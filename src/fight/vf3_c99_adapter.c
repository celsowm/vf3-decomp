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
int vf3_c99_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* The code base is the mirror the code runs under: 0x0c, 0x8c or 0xac.  A call hands the callee the mirror it jumped to (the router masks the entry PC to 29 bits, which loses it); a direct entry falls back to the alias the caller left in the link register. */
uint32_t code_base=(vf3_matrix_call_alias_pc==(entry&0x1fffffffu))?vf3_matrix_call_alias:(((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u));
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c010684u: goto P_0c010684;
case 0x0c010686u: goto P_0c010686;
case 0x0c010688u: goto P_0c010688;
case 0x0c01068au: goto P_0c01068a;
case 0x0c01068cu: goto P_0c01068c;
case 0x0c01068eu: goto P_0c01068e;
case 0x0c010690u: goto P_0c010690;
case 0x0c010692u: goto P_0c010692;
case 0x0c010694u: goto P_0c010694;
case 0x0c010696u: goto P_0c010696;
case 0x0c010698u: goto P_0c010698;
case 0x0c01069au: goto P_0c01069a;
case 0x0c01069cu: goto P_0c01069c;
case 0x0c01069eu: goto P_0c01069e;
case 0x0c0106a0u: goto P_0c0106a0;
case 0x0c0106a2u: goto P_0c0106a2;
case 0x0c0106a4u: goto P_0c0106a4;
case 0x0c0106a6u: goto P_0c0106a6;
case 0x0c0106a8u: goto P_0c0106a8;
case 0x0c0106aau: goto P_0c0106aa;
case 0x0c0106acu: goto P_0c0106ac;
case 0x0c0106aeu: goto P_0c0106ae;
case 0x0c0106b0u: goto P_0c0106b0;
case 0x0c0106b2u: goto P_0c0106b2;
case 0x0c0106b4u: goto P_0c0106b4;
case 0x0c0106b6u: goto P_0c0106b6;
case 0x0c0106b8u: goto P_0c0106b8;
case 0x0c0106bau: goto P_0c0106ba;
case 0x0c0106bcu: goto P_0c0106bc;
case 0x0c0106beu: goto P_0c0106be;
case 0x0c0106f4u: goto P_0c0106f4;
case 0x0c0106f6u: goto P_0c0106f6;
case 0x0c0106f8u: goto P_0c0106f8;
case 0x0c0106fau: goto P_0c0106fa;
case 0x0c0106fcu: goto P_0c0106fc;
case 0x0c0106feu: goto P_0c0106fe;
case 0x0c010700u: goto P_0c010700;
case 0x0c010702u: goto P_0c010702;
case 0x0c010704u: goto P_0c010704;
case 0x0c010706u: goto P_0c010706;
case 0x0c010708u: goto P_0c010708;
case 0x0c01070au: goto P_0c01070a;
case 0x0c01070cu: goto P_0c01070c;
case 0x0c01070eu: goto P_0c01070e;
case 0x0c010710u: goto P_0c010710;
case 0x0c010712u: goto P_0c010712;
case 0x0c010714u: goto P_0c010714;
case 0x0c010716u: goto P_0c010716;
case 0x0c010718u: goto P_0c010718;
case 0x0c01071au: goto P_0c01071a;
case 0x0c01071cu: goto P_0c01071c;
case 0x0c01071eu: goto P_0c01071e;
case 0x0c010720u: goto P_0c010720;
case 0x0c010722u: goto P_0c010722;
case 0x0c010724u: goto P_0c010724;
case 0x0c010726u: goto P_0c010726;
case 0x0c010728u: goto P_0c010728;
case 0x0c01072au: goto P_0c01072a;
case 0x0c01072cu: goto P_0c01072c;
case 0x0c01072eu: goto P_0c01072e;
case 0x0c010730u: goto P_0c010730;
case 0x0c010732u: goto P_0c010732;
case 0x0c010734u: goto P_0c010734;
case 0x0c010736u: goto P_0c010736;
case 0x0c010738u: goto P_0c010738;
case 0x0c01073au: goto P_0c01073a;
case 0x0c01073cu: goto P_0c01073c;
case 0x0c01073eu: goto P_0c01073e;
case 0x0c010740u: goto P_0c010740;
case 0x0c010742u: goto P_0c010742;
case 0x0c010744u: goto P_0c010744;
case 0x0c010746u: goto P_0c010746;
case 0x0c010748u: goto P_0c010748;
case 0x0c01074au: goto P_0c01074a;
case 0x0c01074cu: goto P_0c01074c;
case 0x0c01074eu: goto P_0c01074e;
case 0x0c010750u: goto P_0c010750;
case 0x0c010752u: goto P_0c010752;
case 0x0c010758u: goto P_0c010758;
case 0x0c01075au: goto P_0c01075a;
case 0x0c01075cu: goto P_0c01075c;
case 0x0c01075eu: goto P_0c01075e;
case 0x0c010760u: goto P_0c010760;
case 0x0c010762u: goto P_0c010762;
case 0x0c010764u: goto P_0c010764;
case 0x0c010766u: goto P_0c010766;
case 0x0c010768u: goto P_0c010768;
case 0x0c01076au: goto P_0c01076a;
case 0x0c01076cu: goto P_0c01076c;
case 0x0c01076eu: goto P_0c01076e;
case 0x0c010770u: goto P_0c010770;
case 0x0c010772u: goto P_0c010772;
case 0x0c010774u: goto P_0c010774;
case 0x0c010776u: goto P_0c010776;
case 0x0c010778u: goto P_0c010778;
case 0x0c01077au: goto P_0c01077a;
case 0x0c01077cu: goto P_0c01077c;
case 0x0c01077eu: goto P_0c01077e;
case 0x0c010780u: goto P_0c010780;
case 0x0c010782u: goto P_0c010782;
case 0x0c010784u: goto P_0c010784;
case 0x0c010786u: goto P_0c010786;
case 0x0c010788u: goto P_0c010788;
case 0x0c01078au: goto P_0c01078a;
case 0x0c01078cu: goto P_0c01078c;
case 0x0c01078eu: goto P_0c01078e;
case 0x0c010790u: goto P_0c010790;
case 0x0c010792u: goto P_0c010792;
case 0x0c010794u: goto P_0c010794;
case 0x0c010796u: goto P_0c010796;
case 0x0c010798u: goto P_0c010798;
case 0x0c01079au: goto P_0c01079a;
case 0x0c01079cu: goto P_0c01079c;
case 0x0c01079eu: goto P_0c01079e;
case 0x0c0107a0u: goto P_0c0107a0;
case 0x0c0107a2u: goto P_0c0107a2;
case 0x0c0107a4u: goto P_0c0107a4;
case 0x0c0107a6u: goto P_0c0107a6;
case 0x0c0107a8u: goto P_0c0107a8;
case 0x0c0107aau: goto P_0c0107aa;
case 0x0c0107acu: goto P_0c0107ac;
case 0x0c0107aeu: goto P_0c0107ae;
case 0x0c0107b0u: goto P_0c0107b0;
case 0x0c0107b2u: goto P_0c0107b2;
case 0x0c0107b4u: goto P_0c0107b4;
case 0x0c0107b6u: goto P_0c0107b6;
case 0x0c0107b8u: goto P_0c0107b8;
case 0x0c0107bau: goto P_0c0107ba;
case 0x0c0107bcu: goto P_0c0107bc;
case 0x0c0107beu: goto P_0c0107be;
case 0x0c0107c0u: goto P_0c0107c0;
case 0x0c0107c2u: goto P_0c0107c2;
case 0x0c0107c4u: goto P_0c0107c4;
case 0x0c0107c6u: goto P_0c0107c6;
case 0x0c0107c8u: goto P_0c0107c8;
case 0x0c0107cau: goto P_0c0107ca;
case 0x0c0107ccu: goto P_0c0107cc;
case 0x0c0107ceu: goto P_0c0107ce;
case 0x0c0107d0u: goto P_0c0107d0;
case 0x0c0107d2u: goto P_0c0107d2;
case 0x0c0107d4u: goto P_0c0107d4;
case 0x0c0107d6u: goto P_0c0107d6;
case 0x0c0107d8u: goto P_0c0107d8;
case 0x0c0107dau: goto P_0c0107da;
case 0x0c0107dcu: goto P_0c0107dc;
case 0x0c0107deu: goto P_0c0107de;
case 0x0c0107e0u: goto P_0c0107e0;
case 0x0c0107e2u: goto P_0c0107e2;
case 0x0c0107e4u: goto P_0c0107e4;
case 0x0c0107e6u: goto P_0c0107e6;
case 0x0c0107e8u: goto P_0c0107e8;
case 0x0c0107eau: goto P_0c0107ea;
case 0x0c0107ecu: goto P_0c0107ec;
case 0x0c0107eeu: goto P_0c0107ee;
case 0x0c0107f0u: goto P_0c0107f0;
case 0x0c0107f2u: goto P_0c0107f2;
case 0x0c0107f4u: goto P_0c0107f4;
case 0x0c0107f6u: goto P_0c0107f6;
case 0x0c0107f8u: goto P_0c0107f8;
case 0x0c0107fau: goto P_0c0107fa;
case 0x0c0107fcu: goto P_0c0107fc;
case 0x0c01089au: goto P_0c01089a;
case 0x0c01089cu: goto P_0c01089c;
case 0x0c01089eu: goto P_0c01089e;
case 0x0c0108a0u: goto P_0c0108a0;
case 0x0c0108a2u: goto P_0c0108a2;
case 0x0c0108a4u: goto P_0c0108a4;
case 0x0c0108a6u: goto P_0c0108a6;
case 0x0c0108a8u: goto P_0c0108a8;
case 0x0c0108aau: goto P_0c0108aa;
case 0x0c0108acu: goto P_0c0108ac;
case 0x0c0108aeu: goto P_0c0108ae;
case 0x0c0108b0u: goto P_0c0108b0;
case 0x0c0108b2u: goto P_0c0108b2;
case 0x0c0108b4u: goto P_0c0108b4;
case 0x0c0108b6u: goto P_0c0108b6;
case 0x0c0108b8u: goto P_0c0108b8;
case 0x0c0108bau: goto P_0c0108ba;
case 0x0c0108bcu: goto P_0c0108bc;
case 0x0c0108beu: goto P_0c0108be;
case 0x0c0108c0u: goto P_0c0108c0;
case 0x0c0108c2u: goto P_0c0108c2;
case 0x0c0108c4u: goto P_0c0108c4;
case 0x0c0108c6u: goto P_0c0108c6;
case 0x0c0108c8u: goto P_0c0108c8;
case 0x0c0108cau: goto P_0c0108ca;
case 0x0c0108ccu: goto P_0c0108cc;
case 0x0c0108ceu: goto P_0c0108ce;
case 0x0c0108d0u: goto P_0c0108d0;
case 0x0c0108d2u: goto P_0c0108d2;
case 0x0c0108d4u: goto P_0c0108d4;
case 0x0c0108d6u: goto P_0c0108d6;
case 0x0c0108d8u: goto P_0c0108d8;
case 0x0c0108dau: goto P_0c0108da;
case 0x0c0108dcu: goto P_0c0108dc;
case 0x0c0108deu: goto P_0c0108de;
case 0x0c0108e0u: goto P_0c0108e0;
case 0x0c0108e2u: goto P_0c0108e2;
case 0x0c0108e4u: goto P_0c0108e4;
case 0x0c0108e6u: goto P_0c0108e6;
case 0x0c0108e8u: goto P_0c0108e8;
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
case 0x0c01098cu: goto P_0c01098c;
case 0x0c01098eu: goto P_0c01098e;
case 0x0c010990u: goto P_0c010990;
case 0x0c010992u: goto P_0c010992;
case 0x0c010994u: goto P_0c010994;
case 0x0c010996u: goto P_0c010996;
case 0x0c010998u: goto P_0c010998;
case 0x0c01099au: goto P_0c01099a;
case 0x0c01099cu: goto P_0c01099c;
case 0x0c01099eu: goto P_0c01099e;
case 0x0c0109a0u: goto P_0c0109a0;
case 0x0c0109a2u: goto P_0c0109a2;
case 0x0c0109a4u: goto P_0c0109a4;
case 0x0c0109a6u: goto P_0c0109a6;
case 0x0c0109a8u: goto P_0c0109a8;
case 0x0c0109aau: goto P_0c0109aa;
case 0x0c0109acu: goto P_0c0109ac;
case 0x0c0109aeu: goto P_0c0109ae;
case 0x0c0109b0u: goto P_0c0109b0;
case 0x0c0109b2u: goto P_0c0109b2;
case 0x0c0109b4u: goto P_0c0109b4;
case 0x0c0109b6u: goto P_0c0109b6;
case 0x0c0109b8u: goto P_0c0109b8;
case 0x0c0109bau: goto P_0c0109ba;
case 0x0c0109bcu: goto P_0c0109bc;
case 0x0c0109beu: goto P_0c0109be;
case 0x0c0109c0u: goto P_0c0109c0;
case 0x0c0109c2u: goto P_0c0109c2;
case 0x0c0109c4u: goto P_0c0109c4;
case 0x0c0109c6u: goto P_0c0109c6;
case 0x0c0109c8u: goto P_0c0109c8;
case 0x0c0109cau: goto P_0c0109ca;
case 0x0c0109ccu: goto P_0c0109cc;
case 0x0c0109ceu: goto P_0c0109ce;
case 0x0c0109d0u: goto P_0c0109d0;
case 0x0c0109d2u: goto P_0c0109d2;
case 0x0c0109d4u: goto P_0c0109d4;
case 0x0c0109d6u: goto P_0c0109d6;
case 0x0c0109d8u: goto P_0c0109d8;
case 0x0c0109dau: goto P_0c0109da;
case 0x0c0109dcu: goto P_0c0109dc;
case 0x0c0109deu: goto P_0c0109de;
case 0x0c0109e0u: goto P_0c0109e0;
case 0x0c0109e2u: goto P_0c0109e2;
case 0x0c0109e4u: goto P_0c0109e4;
case 0x0c0109e6u: goto P_0c0109e6;
case 0x0c0109e8u: goto P_0c0109e8;
case 0x0c0109eau: goto P_0c0109ea;
case 0x0c0109ecu: goto P_0c0109ec;
case 0x0c0109eeu: goto P_0c0109ee;
case 0x0c0109f0u: goto P_0c0109f0;
case 0x0c0109f2u: goto P_0c0109f2;
case 0x0c0109f4u: goto P_0c0109f4;
case 0x0c0110eeu: goto P_0c0110ee;
case 0x0c0110f0u: goto P_0c0110f0;
case 0x0c0110f2u: goto P_0c0110f2;
case 0x0c0110f4u: goto P_0c0110f4;
case 0x0c0110f6u: goto P_0c0110f6;
case 0x0c0110f8u: goto P_0c0110f8;
case 0x0c0110fau: goto P_0c0110fa;
case 0x0c0110fcu: goto P_0c0110fc;
case 0x0c0110feu: goto P_0c0110fe;
case 0x0c011100u: goto P_0c011100;
case 0x0c011102u: goto P_0c011102;
case 0x0c011104u: goto P_0c011104;
case 0x0c011106u: goto P_0c011106;
case 0x0c011108u: goto P_0c011108;
case 0x0c01110au: goto P_0c01110a;
case 0x0c01110cu: goto P_0c01110c;
case 0x0c01110eu: goto P_0c01110e;
case 0x0c011110u: goto P_0c011110;
case 0x0c011112u: goto P_0c011112;
case 0x0c011114u: goto P_0c011114;
case 0x0c011116u: goto P_0c011116;
case 0x0c011118u: goto P_0c011118;
case 0x0c01111au: goto P_0c01111a;
case 0x0c01111cu: goto P_0c01111c;
case 0x0c01111eu: goto P_0c01111e;
case 0x0c011120u: goto P_0c011120;
case 0x0c011122u: goto P_0c011122;
case 0x0c011124u: goto P_0c011124;
case 0x0c011126u: goto P_0c011126;
case 0x0c011128u: goto P_0c011128;
case 0x0c01112au: goto P_0c01112a;
case 0x0c01112cu: goto P_0c01112c;
case 0x0c01112eu: goto P_0c01112e;
case 0x0c011130u: goto P_0c011130;
case 0x0c011132u: goto P_0c011132;
case 0x0c011134u: goto P_0c011134;
case 0x0c011136u: goto P_0c011136;
case 0x0c011138u: goto P_0c011138;
case 0x0c01113au: goto P_0c01113a;
case 0x0c01113cu: goto P_0c01113c;
case 0x0c01113eu: goto P_0c01113e;
case 0x0c011140u: goto P_0c011140;
case 0x0c011142u: goto P_0c011142;
case 0x0c011144u: goto P_0c011144;
case 0x0c011146u: goto P_0c011146;
case 0x0c011148u: goto P_0c011148;
case 0x0c01114au: goto P_0c01114a;
case 0x0c01114cu: goto P_0c01114c;
case 0x0c01114eu: goto P_0c01114e;
case 0x0c011150u: goto P_0c011150;
case 0x0c011152u: goto P_0c011152;
case 0x0c011154u: goto P_0c011154;
case 0x0c011156u: goto P_0c011156;
case 0x0c011158u: goto P_0c011158;
case 0x0c01115au: goto P_0c01115a;
case 0x0c01115cu: goto P_0c01115c;
case 0x0c01115eu: goto P_0c01115e;
case 0x0c011160u: goto P_0c011160;
case 0x0c011162u: goto P_0c011162;
case 0x0c011164u: goto P_0c011164;
case 0x0c011166u: goto P_0c011166;
case 0x0c011168u: goto P_0c011168;
case 0x0c01116au: goto P_0c01116a;
case 0x0c01116cu: goto P_0c01116c;
case 0x0c01116eu: goto P_0c01116e;
case 0x0c011170u: goto P_0c011170;
case 0x0c011172u: goto P_0c011172;
case 0x0c011174u: goto P_0c011174;
case 0x0c011176u: goto P_0c011176;
case 0x0c011178u: goto P_0c011178;
case 0x0c01117au: goto P_0c01117a;
case 0x0c01117cu: goto P_0c01117c;
case 0x0c01117eu: goto P_0c01117e;
case 0x0c011180u: goto P_0c011180;
case 0x0c011182u: goto P_0c011182;
case 0x0c011184u: goto P_0c011184;
case 0x0c011186u: goto P_0c011186;
case 0x0c011188u: goto P_0c011188;
case 0x0c01118au: goto P_0c01118a;
case 0x0c01118cu: goto P_0c01118c;
case 0x0c01118eu: goto P_0c01118e;
case 0x0c011190u: goto P_0c011190;
case 0x0c011192u: goto P_0c011192;
case 0x0c011194u: goto P_0c011194;
case 0x0c011196u: goto P_0c011196;
case 0x0c011198u: goto P_0c011198;
case 0x0c01119au: goto P_0c01119a;
case 0x0c01119cu: goto P_0c01119c;
case 0x0c01119eu: goto P_0c01119e;
case 0x0c0111a0u: goto P_0c0111a0;
case 0x0c0111a2u: goto P_0c0111a2;
case 0x0c0111a4u: goto P_0c0111a4;
case 0x0c0111a6u: goto P_0c0111a6;
case 0x0c0111a8u: goto P_0c0111a8;
case 0x0c0111aau: goto P_0c0111aa;
case 0x0c0111acu: goto P_0c0111ac;
case 0x0c0111aeu: goto P_0c0111ae;
case 0x0c0111b0u: goto P_0c0111b0;
case 0x0c0111b2u: goto P_0c0111b2;
case 0x0c0111b4u: goto P_0c0111b4;
case 0x0c0111b6u: goto P_0c0111b6;
case 0x0c0111b8u: goto P_0c0111b8;
case 0x0c0111bau: goto P_0c0111ba;
case 0x0c0111bcu: goto P_0c0111bc;
case 0x0c0111beu: goto P_0c0111be;
case 0x0c0111c0u: goto P_0c0111c0;
case 0x0c0119a4u: goto P_0c0119a4;
case 0x0c0119a6u: goto P_0c0119a6;
case 0x0c0119e0u: goto P_0c0119e0;
case 0x0c0119e2u: goto P_0c0119e2;
case 0x0c0119e4u: goto P_0c0119e4;
case 0x0c0119e6u: goto P_0c0119e6;
case 0x0c0119e8u: goto P_0c0119e8;
case 0x0c0119eau: goto P_0c0119ea;
case 0x0c0119ecu: goto P_0c0119ec;
case 0x0c0119eeu: goto P_0c0119ee;
case 0x0c0119f0u: goto P_0c0119f0;
case 0x0c0119f2u: goto P_0c0119f2;
case 0x0c0119f4u: goto P_0c0119f4;
case 0x0c0119f6u: goto P_0c0119f6;
case 0x0c0119f8u: goto P_0c0119f8;
case 0x0c0119fau: goto P_0c0119fa;
case 0x0c0119fcu: goto P_0c0119fc;
case 0x0c0119feu: goto P_0c0119fe;
case 0x0c011a00u: goto P_0c011a00;
case 0x0c011a02u: goto P_0c011a02;
case 0x0c011a04u: goto P_0c011a04;
case 0x0c011a06u: goto P_0c011a06;
case 0x0c011a08u: goto P_0c011a08;
case 0x0c011a0au: goto P_0c011a0a;
case 0x0c011a0cu: goto P_0c011a0c;
case 0x0c011a0eu: goto P_0c011a0e;
case 0x0c011a10u: goto P_0c011a10;
case 0x0c011a12u: goto P_0c011a12;
case 0x0c011a14u: goto P_0c011a14;
case 0x0c011a16u: goto P_0c011a16;
case 0x0c011a18u: goto P_0c011a18;
case 0x0c011a1au: goto P_0c011a1a;
case 0x0c011a1cu: goto P_0c011a1c;
case 0x0c011a1eu: goto P_0c011a1e;
case 0x0c011a20u: goto P_0c011a20;
case 0x0c011a22u: goto P_0c011a22;
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
case 0x0c011afeu: goto P_0c011afe;
case 0x0c011b00u: goto P_0c011b00;
case 0x0c011b02u: goto P_0c011b02;
case 0x0c011b04u: goto P_0c011b04;
case 0x0c011b06u: goto P_0c011b06;
case 0x0c011b08u: goto P_0c011b08;
case 0x0c011b0au: goto P_0c011b0a;
case 0x0c011b0cu: goto P_0c011b0c;
case 0x0c011b0eu: goto P_0c011b0e;
case 0x0c011b10u: goto P_0c011b10;
case 0x0c011b12u: goto P_0c011b12;
case 0x0c011b14u: goto P_0c011b14;
case 0x0c011b16u: goto P_0c011b16;
case 0x0c011b18u: goto P_0c011b18;
case 0x0c011b1au: goto P_0c011b1a;
case 0x0c011b1cu: goto P_0c011b1c;
case 0x0c011b1eu: goto P_0c011b1e;
case 0x0c011b20u: goto P_0c011b20;
case 0x0c011b22u: goto P_0c011b22;
case 0x0c011b24u: goto P_0c011b24;
case 0x0c011b26u: goto P_0c011b26;
case 0x0c011b28u: goto P_0c011b28;
case 0x0c011b2au: goto P_0c011b2a;
default: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
}
P_0c010684: /* original 4f22, guest PC 0x0c010684 */
if(!s->budget--) { s->failed_pc=0x0c010684u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c010686;
P_0c010686: /* original 4f12, guest PC 0x0c010686 */
if(!s->budget--) { s->failed_pc=0x0c010686u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c010688;
P_0c010688: /* original 7ff8, guest PC 0x0c010688 */
if(!s->budget--) { s->failed_pc=0x0c010688u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c01068a;
P_0c01068a: /* original 2f42, guest PC 0x0c01068a */
if(!s->budget--) { s->failed_pc=0x0c01068au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c01068c;
P_0c01068c: /* original 6e73, guest PC 0x0c01068c */
if(!s->budget--) { s->failed_pc=0x0c01068cu; return 0; }
r[14]=r[7];
goto P_0c01068e;
P_0c01068e: /* original d418, guest PC 0x0c01068e */
if(!s->budget--) { s->failed_pc=0x0c01068eu; return 0; }
r[4]=read(ram,0x0c0106f0u,4);
goto P_0c010690;
P_0c010690: /* original 1f51, guest PC 0x0c010690 */
if(!s->budget--) { s->failed_pc=0x0c010690u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c010692;
P_0c010692: /* original 50f1, guest PC 0x0c010692 */
if(!s->budget--) { s->failed_pc=0x0c010692u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c010694;
P_0c010694: /* original 8801, guest PC 0x0c010694 */
if(!s->budget--) { s->failed_pc=0x0c010694u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c010696;
P_0c010696: /* original 8d06, guest PC 0x0c010696 */
if(!s->budget--) { s->failed_pc=0x0c010696u; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(cond) { goto P_0c0106a6; }
goto P_0c01069a;
P_0c010698: /* original e500, guest PC 0x0c010698 */
if(!s->budget--) { s->failed_pc=0x0c010698u; return 0; }
r[5]=0x00000000u;
goto P_0c01069a;
P_0c01069a: /* original 8802, guest PC 0x0c01069a */
if(!s->budget--) { s->failed_pc=0x0c01069au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c01069c;
P_0c01069c: /* original 892a, guest PC 0x0c01069c */
if(!s->budget--) { s->failed_pc=0x0c01069cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0106f4; }
goto P_0c01069e;
P_0c01069e: /* original 8804, guest PC 0x0c01069e */
if(!s->budget--) { s->failed_pc=0x0c01069eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0106a0;
P_0c0106a0: /* original 8935, guest PC 0x0c0106a0 */
if(!s->budget--) { s->failed_pc=0x0c0106a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c01070e; }
goto P_0c0106a2;
P_0c0106a2: /* original a03f, guest PC 0x0c0106a2 */
if(!s->budget--) { s->failed_pc=0x0c0106a2u; return 0; }
goto P_0c010724;
P_0c0106a4: /* original 0009, guest PC 0x0c0106a4 */
if(!s->budget--) { s->failed_pc=0x0c0106a4u; return 0; }
goto P_0c0106a6;
P_0c0106a6: /* original 4e15, guest PC 0x0c0106a6 */
if(!s->budget--) { s->failed_pc=0x0c0106a6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0106a8;
P_0c0106a8: /* original 6763, guest PC 0x0c0106a8 */
if(!s->budget--) { s->failed_pc=0x0c0106a8u; return 0; }
r[7]=r[6];
goto P_0c0106aa;
P_0c0106aa: /* original 6043, guest PC 0x0c0106aa */
if(!s->budget--) { s->failed_pc=0x0c0106aau; return 0; }
r[0]=r[4];
goto P_0c0106ac;
P_0c0106ac: /* original 8f3a, guest PC 0x0c0106ac */
if(!s->budget--) { s->failed_pc=0x0c0106acu; return 0; }
cond=r[17]&1u;
r[4]=r[5];
if(!cond) { goto P_0c010724; }
goto P_0c0106b0;
P_0c0106ae: /* original 6453, guest PC 0x0c0106ae */
if(!s->budget--) { s->failed_pc=0x0c0106aeu; return 0; }
r[4]=r[5];
goto P_0c0106b0;
P_0c0106b0: /* original 6374, guest PC 0x0c0106b0 */
if(!s->budget--) { s->failed_pc=0x0c0106b0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[3]=tmp;
goto P_0c0106b2;
P_0c0106b2: /* original 7401, guest PC 0x0c0106b2 */
if(!s->budget--) { s->failed_pc=0x0c0106b2u; return 0; }
r[4]+=0x00000001u;
goto P_0c0106b4;
P_0c0106b4: /* original 34e3, guest PC 0x0c0106b4 */
if(!s->budget--) { s->failed_pc=0x0c0106b4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[14])!=0);
goto P_0c0106b6;
P_0c0106b6: /* original 2030, guest PC 0x0c0106b6 */
if(!s->budget--) { s->failed_pc=0x0c0106b6u; return 0; }
write(ram,r[0],r[3],1);
goto P_0c0106b8;
P_0c0106b8: /* original 8ffa, guest PC 0x0c0106b8 */
if(!s->budget--) { s->failed_pc=0x0c0106b8u; return 0; }
cond=r[17]&1u;
r[0]+=0x00000001u;
if(!cond) { goto P_0c0106b0; }
goto P_0c0106bc;
P_0c0106ba: /* original 7001, guest PC 0x0c0106ba */
if(!s->budget--) { s->failed_pc=0x0c0106bau; return 0; }
r[0]+=0x00000001u;
goto P_0c0106bc;
P_0c0106bc: /* original a032, guest PC 0x0c0106bc */
if(!s->budget--) { s->failed_pc=0x0c0106bcu; return 0; }
goto P_0c010724;
P_0c0106be: /* original 0009, guest PC 0x0c0106be */
if(!s->budget--) { s->failed_pc=0x0c0106beu; return 0; }
return vf3_matrix_family(0x0c0106c0u,s,ram);
P_0c0106f4: /* original 4e15, guest PC 0x0c0106f4 */
if(!s->budget--) { s->failed_pc=0x0c0106f4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0106f6;
P_0c0106f6: /* original 6063, guest PC 0x0c0106f6 */
if(!s->budget--) { s->failed_pc=0x0c0106f6u; return 0; }
r[0]=r[6];
goto P_0c0106f8;
P_0c0106f8: /* original 6743, guest PC 0x0c0106f8 */
if(!s->budget--) { s->failed_pc=0x0c0106f8u; return 0; }
r[7]=r[4];
goto P_0c0106fa;
P_0c0106fa: /* original 8f13, guest PC 0x0c0106fa */
if(!s->budget--) { s->failed_pc=0x0c0106fau; return 0; }
cond=r[17]&1u;
r[4]=r[5];
if(!cond) { goto P_0c010724; }
goto P_0c0106fe;
P_0c0106fc: /* original 6453, guest PC 0x0c0106fc */
if(!s->budget--) { s->failed_pc=0x0c0106fcu; return 0; }
r[4]=r[5];
goto P_0c0106fe;
P_0c0106fe: /* original 6205, guest PC 0x0c0106fe */
if(!s->budget--) { s->failed_pc=0x0c0106feu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[0],2);
r[0]+=2;
r[2]=tmp;
goto P_0c010700;
P_0c010700: /* original 7401, guest PC 0x0c010700 */
if(!s->budget--) { s->failed_pc=0x0c010700u; return 0; }
r[4]+=0x00000001u;
goto P_0c010702;
P_0c010702: /* original 34e3, guest PC 0x0c010702 */
if(!s->budget--) { s->failed_pc=0x0c010702u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[14])!=0);
goto P_0c010704;
P_0c010704: /* original 2721, guest PC 0x0c010704 */
if(!s->budget--) { s->failed_pc=0x0c010704u; return 0; }
write(ram,r[7],r[2],2);
goto P_0c010706;
P_0c010706: /* original 8ffa, guest PC 0x0c010706 */
if(!s->budget--) { s->failed_pc=0x0c010706u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000002u;
if(!cond) { goto P_0c0106fe; }
goto P_0c01070a;
P_0c010708: /* original 7702, guest PC 0x0c010708 */
if(!s->budget--) { s->failed_pc=0x0c010708u; return 0; }
r[7]+=0x00000002u;
goto P_0c01070a;
P_0c01070a: /* original a00b, guest PC 0x0c01070a */
if(!s->budget--) { s->failed_pc=0x0c01070au; return 0; }
goto P_0c010724;
P_0c01070c: /* original 0009, guest PC 0x0c01070c */
if(!s->budget--) { s->failed_pc=0x0c01070cu; return 0; }
goto P_0c01070e;
P_0c01070e: /* original 4e15, guest PC 0x0c01070e */
if(!s->budget--) { s->failed_pc=0x0c01070eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c010710;
P_0c010710: /* original 6063, guest PC 0x0c010710 */
if(!s->budget--) { s->failed_pc=0x0c010710u; return 0; }
r[0]=r[6];
goto P_0c010712;
P_0c010712: /* original 6743, guest PC 0x0c010712 */
if(!s->budget--) { s->failed_pc=0x0c010712u; return 0; }
r[7]=r[4];
goto P_0c010714;
P_0c010714: /* original 8f06, guest PC 0x0c010714 */
if(!s->budget--) { s->failed_pc=0x0c010714u; return 0; }
cond=r[17]&1u;
r[4]=r[5];
if(!cond) { goto P_0c010724; }
goto P_0c010718;
P_0c010716: /* original 6453, guest PC 0x0c010716 */
if(!s->budget--) { s->failed_pc=0x0c010716u; return 0; }
r[4]=r[5];
goto P_0c010718;
P_0c010718: /* original 6306, guest PC 0x0c010718 */
if(!s->budget--) { s->failed_pc=0x0c010718u; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[3]=tmp;
goto P_0c01071a;
P_0c01071a: /* original 7401, guest PC 0x0c01071a */
if(!s->budget--) { s->failed_pc=0x0c01071au; return 0; }
r[4]+=0x00000001u;
goto P_0c01071c;
P_0c01071c: /* original 34e3, guest PC 0x0c01071c */
if(!s->budget--) { s->failed_pc=0x0c01071cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[14])!=0);
goto P_0c01071e;
P_0c01071e: /* original 2732, guest PC 0x0c01071e */
if(!s->budget--) { s->failed_pc=0x0c01071eu; return 0; }
write(ram,r[7],r[3],4);
goto P_0c010720;
P_0c010720: /* original 8ffa, guest PC 0x0c010720 */
if(!s->budget--) { s->failed_pc=0x0c010720u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000004u;
if(!cond) { goto P_0c010718; }
goto P_0c010724;
P_0c010722: /* original 7704, guest PC 0x0c010722 */
if(!s->budget--) { s->failed_pc=0x0c010722u; return 0; }
r[7]+=0x00000004u;
goto P_0c010724;
P_0c010724: /* original d278, guest PC 0x0c010724 */
if(!s->budget--) { s->failed_pc=0x0c010724u; return 0; }
r[2]=read(ram,0x0c010908u,4);
goto P_0c010726;
P_0c010726: /* original c700, guest PC 0x0c010726 */
if(!s->budget--) { s->failed_pc=0x0c010726u; return 0; }
r[0]=code_base|0x00010728u;
goto P_0c010728;
P_0c010728: /* original 56f1, guest PC 0x0c010728 */
if(!s->budget--) { s->failed_pc=0x0c010728u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c01072a;
P_0c01072a: /* original 320c, guest PC 0x0c01072a */
if(!s->budget--) { s->failed_pc=0x0c01072au; return 0; }
r[2]+=r[0];
goto P_0c01072c;
P_0c01072c: /* original d377, guest PC 0x0c01072c */
if(!s->budget--) { s->failed_pc=0x0c01072cu; return 0; }
r[3]=read(ram,0x0c01090cu,4);
goto P_0c01072e;
P_0c01072e: /* original 6123, guest PC 0x0c01072e */
if(!s->budget--) { s->failed_pc=0x0c01072eu; return 0; }
r[1]=r[2];
goto P_0c010730;
P_0c010730: /* original 06e7, guest PC 0x0c010730 */
if(!s->budget--) { s->failed_pc=0x0c010730u; return 0; }
r[19]=r[6]*r[14];
goto P_0c010732;
P_0c010732: /* original d577, guest PC 0x0c010732 */
if(!s->budget--) { s->failed_pc=0x0c010732u; return 0; }
r[5]=read(ram,0x0c010910u,4);
goto P_0c010734;
P_0c010734: /* original 213b, guest PC 0x0c010734 */
if(!s->budget--) { s->failed_pc=0x0c010734u; return 0; }
r[1]|=r[3];
goto P_0c010736;
P_0c010736: /* original 061a, guest PC 0x0c010736 */
if(!s->budget--) { s->failed_pc=0x0c010736u; return 0; }
r[6]=r[19];
goto P_0c010738;
P_0c010738: /* original 410b, guest PC 0x0c010738 */
if(!s->budget--) { s->failed_pc=0x0c010738u; return 0; }
target=r[1];
r[16]=code_base|0x0c01073cu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c01073cu) { target=s->pc; goto dispatch; }
goto P_0c01073c;
P_0c01073a: /* original 64f2, guest PC 0x0c01073a */
if(!s->budget--) { s->failed_pc=0x0c01073au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c01073c;
P_0c01073c: /* original d375, guest PC 0x0c01073c */
if(!s->budget--) { s->failed_pc=0x0c01073cu; return 0; }
r[3]=read(ram,0x0c010914u,4);
goto P_0c01073e;
P_0c01073e: /* original c700, guest PC 0x0c01073e */
if(!s->budget--) { s->failed_pc=0x0c01073eu; return 0; }
r[0]=code_base|0x00010740u;
goto P_0c010740;
P_0c010740: /* original d272, guest PC 0x0c010740 */
if(!s->budget--) { s->failed_pc=0x0c010740u; return 0; }
r[2]=read(ram,0x0c01090cu,4);
goto P_0c010742;
P_0c010742: /* original 330c, guest PC 0x0c010742 */
if(!s->budget--) { s->failed_pc=0x0c010742u; return 0; }
r[3]+=r[0];
goto P_0c010744;
P_0c010744: /* original 64f2, guest PC 0x0c010744 */
if(!s->budget--) { s->failed_pc=0x0c010744u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c010746;
P_0c010746: /* original 6133, guest PC 0x0c010746 */
if(!s->budget--) { s->failed_pc=0x0c010746u; return 0; }
r[1]=r[3];
goto P_0c010748;
P_0c010748: /* original 212b, guest PC 0x0c010748 */
if(!s->budget--) { s->failed_pc=0x0c010748u; return 0; }
r[1]|=r[2];
goto P_0c01074a;
P_0c01074a: /* original 7f08, guest PC 0x0c01074a */
if(!s->budget--) { s->failed_pc=0x0c01074au; return 0; }
r[15]+=0x00000008u;
goto P_0c01074c;
P_0c01074c: /* original 4f16, guest PC 0x0c01074c */
if(!s->budget--) { s->failed_pc=0x0c01074cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c01074e;
P_0c01074e: /* original 4f26, guest PC 0x0c01074e */
if(!s->budget--) { s->failed_pc=0x0c01074eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c010750;
P_0c010750: /* original 412b, guest PC 0x0c010750 */
if(!s->budget--) { s->failed_pc=0x0c010750u; return 0; }
target=r[1];
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
P_0c010752: /* original 6ef6, guest PC 0x0c010752 */
if(!s->budget--) { s->failed_pc=0x0c010752u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c010754u,s,ram);
P_0c010758: /* original 4f22, guest PC 0x0c010758 */
if(!s->budget--) { s->failed_pc=0x0c010758u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c01075a;
P_0c01075a: /* original 4f12, guest PC 0x0c01075a */
if(!s->budget--) { s->failed_pc=0x0c01075au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c01075c;
P_0c01075c: /* original 7ff8, guest PC 0x0c01075c */
if(!s->budget--) { s->failed_pc=0x0c01075cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c01075e;
P_0c01075e: /* original d36e, guest PC 0x0c01075e */
if(!s->budget--) { s->failed_pc=0x0c01075eu; return 0; }
r[3]=read(ram,0x0c010918u,4);
goto P_0c010760;
P_0c010760: /* original c702, guest PC 0x0c010760 */
if(!s->budget--) { s->failed_pc=0x0c010760u; return 0; }
r[0]=code_base|0x0001076cu;
goto P_0c010762;
P_0c010762: /* original 6e73, guest PC 0x0c010762 */
if(!s->budget--) { s->failed_pc=0x0c010762u; return 0; }
r[14]=r[7];
goto P_0c010764;
P_0c010764: /* original 2f42, guest PC 0x0c010764 */
if(!s->budget--) { s->failed_pc=0x0c010764u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c010766;
P_0c010766: /* original 330c, guest PC 0x0c010766 */
if(!s->budget--) { s->failed_pc=0x0c010766u; return 0; }
r[3]+=r[0];
goto P_0c010768;
P_0c010768: /* original 1f51, guest PC 0x0c010768 */
if(!s->budget--) { s->failed_pc=0x0c010768u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c01076a;
P_0c01076a: /* original 6d63, guest PC 0x0c01076a */
if(!s->budget--) { s->failed_pc=0x0c01076au; return 0; }
r[13]=r[6];
goto P_0c01076c;
P_0c01076c: /* original 6653, guest PC 0x0c01076c */
if(!s->budget--) { s->failed_pc=0x0c01076cu; return 0; }
r[6]=r[5];
goto P_0c01076e;
P_0c01076e: /* original d267, guest PC 0x0c01076e */
if(!s->budget--) { s->failed_pc=0x0c01076eu; return 0; }
r[2]=read(ram,0x0c01090cu,4);
goto P_0c010770;
P_0c010770: /* original 06e7, guest PC 0x0c010770 */
if(!s->budget--) { s->failed_pc=0x0c010770u; return 0; }
r[19]=r[6]*r[14];
goto P_0c010772;
P_0c010772: /* original d567, guest PC 0x0c010772 */
if(!s->budget--) { s->failed_pc=0x0c010772u; return 0; }
r[5]=read(ram,0x0c010910u,4);
goto P_0c010774;
P_0c010774: /* original 6133, guest PC 0x0c010774 */
if(!s->budget--) { s->failed_pc=0x0c010774u; return 0; }
r[1]=r[3];
goto P_0c010776;
P_0c010776: /* original 212b, guest PC 0x0c010776 */
if(!s->budget--) { s->failed_pc=0x0c010776u; return 0; }
r[1]|=r[2];
goto P_0c010778;
P_0c010778: /* original 061a, guest PC 0x0c010778 */
if(!s->budget--) { s->failed_pc=0x0c010778u; return 0; }
r[6]=r[19];
goto P_0c01077a;
P_0c01077a: /* original 410b, guest PC 0x0c01077a */
if(!s->budget--) { s->failed_pc=0x0c01077au; return 0; }
target=r[1];
r[16]=code_base|0x0c01077eu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c01077eu) { target=s->pc; goto dispatch; }
goto P_0c01077e;
P_0c01077c: /* original 64f2, guest PC 0x0c01077c */
if(!s->budget--) { s->failed_pc=0x0c01077cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c01077e;
P_0c01077e: /* original d367, guest PC 0x0c01077e */
if(!s->budget--) { s->failed_pc=0x0c01077eu; return 0; }
r[3]=read(ram,0x0c01091cu,4);
goto P_0c010780;
P_0c010780: /* original c700, guest PC 0x0c010780 */
if(!s->budget--) { s->failed_pc=0x0c010780u; return 0; }
r[0]=code_base|0x00010784u;
goto P_0c010782;
P_0c010782: /* original 330c, guest PC 0x0c010782 */
if(!s->budget--) { s->failed_pc=0x0c010782u; return 0; }
r[3]+=r[0];
goto P_0c010784;
P_0c010784: /* original d261, guest PC 0x0c010784 */
if(!s->budget--) { s->failed_pc=0x0c010784u; return 0; }
r[2]=read(ram,0x0c01090cu,4);
goto P_0c010786;
P_0c010786: /* original 6133, guest PC 0x0c010786 */
if(!s->budget--) { s->failed_pc=0x0c010786u; return 0; }
r[1]=r[3];
goto P_0c010788;
P_0c010788: /* original 212b, guest PC 0x0c010788 */
if(!s->budget--) { s->failed_pc=0x0c010788u; return 0; }
r[1]|=r[2];
goto P_0c01078a;
P_0c01078a: /* original 410b, guest PC 0x0c01078a */
if(!s->budget--) { s->failed_pc=0x0c01078au; return 0; }
target=r[1];
r[16]=code_base|0x0c01078eu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c01078eu) { target=s->pc; goto dispatch; }
goto P_0c01078e;
P_0c01078c: /* original 64f2, guest PC 0x0c01078c */
if(!s->budget--) { s->failed_pc=0x0c01078cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c01078e;
P_0c01078e: /* original 2ee8, guest PC 0x0c01078e */
if(!s->budget--) { s->failed_pc=0x0c01078eu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c010790;
P_0c010790: /* original 892f, guest PC 0x0c010790 */
if(!s->budget--) { s->failed_pc=0x0c010790u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0107f2; }
goto P_0c010792;
P_0c010792: /* original 50f1, guest PC 0x0c010792 */
if(!s->budget--) { s->failed_pc=0x0c010792u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c010794;
P_0c010794: /* original d45e, guest PC 0x0c010794 */
if(!s->budget--) { s->failed_pc=0x0c010794u; return 0; }
r[4]=read(ram,0x0c010910u,4);
goto P_0c010796;
P_0c010796: /* original 8801, guest PC 0x0c010796 */
if(!s->budget--) { s->failed_pc=0x0c010796u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c010798;
P_0c010798: /* original 8d06, guest PC 0x0c010798 */
if(!s->budget--) { s->failed_pc=0x0c010798u; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(cond) { goto P_0c0107a8; }
goto P_0c01079c;
P_0c01079a: /* original e500, guest PC 0x0c01079a */
if(!s->budget--) { s->failed_pc=0x0c01079au; return 0; }
r[5]=0x00000000u;
goto P_0c01079c;
P_0c01079c: /* original 8802, guest PC 0x0c01079c */
if(!s->budget--) { s->failed_pc=0x0c01079cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c01079e;
P_0c01079e: /* original 8910, guest PC 0x0c01079e */
if(!s->budget--) { s->failed_pc=0x0c01079eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0107c2; }
goto P_0c0107a0;
P_0c0107a0: /* original 8804, guest PC 0x0c0107a0 */
if(!s->budget--) { s->failed_pc=0x0c0107a0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0107a2;
P_0c0107a2: /* original 891b, guest PC 0x0c0107a2 */
if(!s->budget--) { s->failed_pc=0x0c0107a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0107dc; }
goto P_0c0107a4;
P_0c0107a4: /* original a025, guest PC 0x0c0107a4 */
if(!s->budget--) { s->failed_pc=0x0c0107a4u; return 0; }
goto P_0c0107f2;
P_0c0107a6: /* original 0009, guest PC 0x0c0107a6 */
if(!s->budget--) { s->failed_pc=0x0c0107a6u; return 0; }
goto P_0c0107a8;
P_0c0107a8: /* original 4e15, guest PC 0x0c0107a8 */
if(!s->budget--) { s->failed_pc=0x0c0107a8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0107aa;
P_0c0107aa: /* original 67d3, guest PC 0x0c0107aa */
if(!s->budget--) { s->failed_pc=0x0c0107aau; return 0; }
r[7]=r[13];
goto P_0c0107ac;
P_0c0107ac: /* original 6643, guest PC 0x0c0107ac */
if(!s->budget--) { s->failed_pc=0x0c0107acu; return 0; }
r[6]=r[4];
goto P_0c0107ae;
P_0c0107ae: /* original 8f20, guest PC 0x0c0107ae */
if(!s->budget--) { s->failed_pc=0x0c0107aeu; return 0; }
cond=r[17]&1u;
r[4]=r[5];
if(!cond) { goto P_0c0107f2; }
goto P_0c0107b2;
P_0c0107b0: /* original 6453, guest PC 0x0c0107b0 */
if(!s->budget--) { s->failed_pc=0x0c0107b0u; return 0; }
r[4]=r[5];
goto P_0c0107b2;
P_0c0107b2: /* original 6364, guest PC 0x0c0107b2 */
if(!s->budget--) { s->failed_pc=0x0c0107b2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]+=1;
r[3]=tmp;
goto P_0c0107b4;
P_0c0107b4: /* original 7401, guest PC 0x0c0107b4 */
if(!s->budget--) { s->failed_pc=0x0c0107b4u; return 0; }
r[4]+=0x00000001u;
goto P_0c0107b6;
P_0c0107b6: /* original 34e3, guest PC 0x0c0107b6 */
if(!s->budget--) { s->failed_pc=0x0c0107b6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[14])!=0);
goto P_0c0107b8;
P_0c0107b8: /* original 2730, guest PC 0x0c0107b8 */
if(!s->budget--) { s->failed_pc=0x0c0107b8u; return 0; }
write(ram,r[7],r[3],1);
goto P_0c0107ba;
P_0c0107ba: /* original 8ffa, guest PC 0x0c0107ba */
if(!s->budget--) { s->failed_pc=0x0c0107bau; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(!cond) { goto P_0c0107b2; }
goto P_0c0107be;
P_0c0107bc: /* original 7701, guest PC 0x0c0107bc */
if(!s->budget--) { s->failed_pc=0x0c0107bcu; return 0; }
r[7]+=0x00000001u;
goto P_0c0107be;
P_0c0107be: /* original a018, guest PC 0x0c0107be */
if(!s->budget--) { s->failed_pc=0x0c0107beu; return 0; }
goto P_0c0107f2;
P_0c0107c0: /* original 0009, guest PC 0x0c0107c0 */
if(!s->budget--) { s->failed_pc=0x0c0107c0u; return 0; }
goto P_0c0107c2;
P_0c0107c2: /* original 4e15, guest PC 0x0c0107c2 */
if(!s->budget--) { s->failed_pc=0x0c0107c2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0107c4;
P_0c0107c4: /* original 66d3, guest PC 0x0c0107c4 */
if(!s->budget--) { s->failed_pc=0x0c0107c4u; return 0; }
r[6]=r[13];
goto P_0c0107c6;
P_0c0107c6: /* original 6743, guest PC 0x0c0107c6 */
if(!s->budget--) { s->failed_pc=0x0c0107c6u; return 0; }
r[7]=r[4];
goto P_0c0107c8;
P_0c0107c8: /* original 8f13, guest PC 0x0c0107c8 */
if(!s->budget--) { s->failed_pc=0x0c0107c8u; return 0; }
cond=r[17]&1u;
r[4]=r[5];
if(!cond) { goto P_0c0107f2; }
goto P_0c0107cc;
P_0c0107ca: /* original 6453, guest PC 0x0c0107ca */
if(!s->budget--) { s->failed_pc=0x0c0107cau; return 0; }
r[4]=r[5];
goto P_0c0107cc;
P_0c0107cc: /* original 6275, guest PC 0x0c0107cc */
if(!s->budget--) { s->failed_pc=0x0c0107ccu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[7]+=2;
r[2]=tmp;
goto P_0c0107ce;
P_0c0107ce: /* original 7401, guest PC 0x0c0107ce */
if(!s->budget--) { s->failed_pc=0x0c0107ceu; return 0; }
r[4]+=0x00000001u;
goto P_0c0107d0;
P_0c0107d0: /* original 34e3, guest PC 0x0c0107d0 */
if(!s->budget--) { s->failed_pc=0x0c0107d0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[14])!=0);
goto P_0c0107d2;
P_0c0107d2: /* original 2621, guest PC 0x0c0107d2 */
if(!s->budget--) { s->failed_pc=0x0c0107d2u; return 0; }
write(ram,r[6],r[2],2);
goto P_0c0107d4;
P_0c0107d4: /* original 8ffa, guest PC 0x0c0107d4 */
if(!s->budget--) { s->failed_pc=0x0c0107d4u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000002u;
if(!cond) { goto P_0c0107cc; }
goto P_0c0107d8;
P_0c0107d6: /* original 7602, guest PC 0x0c0107d6 */
if(!s->budget--) { s->failed_pc=0x0c0107d6u; return 0; }
r[6]+=0x00000002u;
goto P_0c0107d8;
P_0c0107d8: /* original a00b, guest PC 0x0c0107d8 */
if(!s->budget--) { s->failed_pc=0x0c0107d8u; return 0; }
goto P_0c0107f2;
P_0c0107da: /* original 0009, guest PC 0x0c0107da */
if(!s->budget--) { s->failed_pc=0x0c0107dau; return 0; }
goto P_0c0107dc;
P_0c0107dc: /* original 4e15, guest PC 0x0c0107dc */
if(!s->budget--) { s->failed_pc=0x0c0107dcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0107de;
P_0c0107de: /* original 66d3, guest PC 0x0c0107de */
if(!s->budget--) { s->failed_pc=0x0c0107deu; return 0; }
r[6]=r[13];
goto P_0c0107e0;
P_0c0107e0: /* original 6743, guest PC 0x0c0107e0 */
if(!s->budget--) { s->failed_pc=0x0c0107e0u; return 0; }
r[7]=r[4];
goto P_0c0107e2;
P_0c0107e2: /* original 8f06, guest PC 0x0c0107e2 */
if(!s->budget--) { s->failed_pc=0x0c0107e2u; return 0; }
cond=r[17]&1u;
r[4]=r[5];
if(!cond) { goto P_0c0107f2; }
goto P_0c0107e6;
P_0c0107e4: /* original 6453, guest PC 0x0c0107e4 */
if(!s->budget--) { s->failed_pc=0x0c0107e4u; return 0; }
r[4]=r[5];
goto P_0c0107e6;
P_0c0107e6: /* original 6376, guest PC 0x0c0107e6 */
if(!s->budget--) { s->failed_pc=0x0c0107e6u; return 0; }
tmp=read(ram,r[7],4);
r[7]+=4;
r[3]=tmp;
goto P_0c0107e8;
P_0c0107e8: /* original 7401, guest PC 0x0c0107e8 */
if(!s->budget--) { s->failed_pc=0x0c0107e8u; return 0; }
r[4]+=0x00000001u;
goto P_0c0107ea;
P_0c0107ea: /* original 34e3, guest PC 0x0c0107ea */
if(!s->budget--) { s->failed_pc=0x0c0107eau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[14])!=0);
goto P_0c0107ec;
P_0c0107ec: /* original 2632, guest PC 0x0c0107ec */
if(!s->budget--) { s->failed_pc=0x0c0107ecu; return 0; }
write(ram,r[6],r[3],4);
goto P_0c0107ee;
P_0c0107ee: /* original 8ffa, guest PC 0x0c0107ee */
if(!s->budget--) { s->failed_pc=0x0c0107eeu; return 0; }
cond=r[17]&1u;
r[6]+=0x00000004u;
if(!cond) { goto P_0c0107e6; }
goto P_0c0107f2;
P_0c0107f0: /* original 7604, guest PC 0x0c0107f0 */
if(!s->budget--) { s->failed_pc=0x0c0107f0u; return 0; }
r[6]+=0x00000004u;
goto P_0c0107f2;
P_0c0107f2: /* original 7f08, guest PC 0x0c0107f2 */
if(!s->budget--) { s->failed_pc=0x0c0107f2u; return 0; }
r[15]+=0x00000008u;
goto P_0c0107f4;
P_0c0107f4: /* original 4f16, guest PC 0x0c0107f4 */
if(!s->budget--) { s->failed_pc=0x0c0107f4u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0107f6;
P_0c0107f6: /* original 4f26, guest PC 0x0c0107f6 */
if(!s->budget--) { s->failed_pc=0x0c0107f6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0107f8;
P_0c0107f8: /* original 6df6, guest PC 0x0c0107f8 */
if(!s->budget--) { s->failed_pc=0x0c0107f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0107fa;
P_0c0107fa: /* original 000b, guest PC 0x0c0107fa */
if(!s->budget--) { s->failed_pc=0x0c0107fau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0107fc: /* original 6ef6, guest PC 0x0c0107fc */
if(!s->budget--) { s->failed_pc=0x0c0107fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0107feu,s,ram);
P_0c01089a: /* original 4f22, guest PC 0x0c01089a */
if(!s->budget--) { s->failed_pc=0x0c01089au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c01089c;
P_0c01089c: /* original 7ffc, guest PC 0x0c01089c */
if(!s->budget--) { s->failed_pc=0x0c01089cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c01089e;
P_0c01089e: /* original d222, guest PC 0x0c01089e */
if(!s->budget--) { s->failed_pc=0x0c01089eu; return 0; }
r[2]=read(ram,0x0c010928u,4);
goto P_0c0108a0;
P_0c0108a0: /* original 2f42, guest PC 0x0c0108a0 */
if(!s->budget--) { s->failed_pc=0x0c0108a0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0108a2;
P_0c0108a2: /* original 6322, guest PC 0x0c0108a2 */
if(!s->budget--) { s->failed_pc=0x0c0108a2u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0108a4;
P_0c0108a4: /* original 2338, guest PC 0x0c0108a4 */
if(!s->budget--) { s->failed_pc=0x0c0108a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0108a6;
P_0c0108a6: /* original 8d0c, guest PC 0x0c0108a6 */
if(!s->budget--) { s->failed_pc=0x0c0108a6u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(cond) { goto P_0c0108c2; }
goto P_0c0108aa;
P_0c0108a8: /* original e400, guest PC 0x0c0108a8 */
if(!s->budget--) { s->failed_pc=0x0c0108a8u; return 0; }
r[4]=0x00000000u;
goto P_0c0108aa;
P_0c0108aa: /* original 63f2, guest PC 0x0c0108aa */
if(!s->budget--) { s->failed_pc=0x0c0108aau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0108ac;
P_0c0108ac: /* original 2338, guest PC 0x0c0108ac */
if(!s->budget--) { s->failed_pc=0x0c0108acu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0108ae;
P_0c0108ae: /* original 8b08, guest PC 0x0c0108ae */
if(!s->budget--) { s->failed_pc=0x0c0108aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0108c2; }
goto P_0c0108b0;
P_0c0108b0: /* original d31e, guest PC 0x0c0108b0 */
if(!s->budget--) { s->failed_pc=0x0c0108b0u; return 0; }
r[3]=read(ram,0x0c01092cu,4);
goto P_0c0108b2;
P_0c0108b2: /* original c700, guest PC 0x0c0108b2 */
if(!s->budget--) { s->failed_pc=0x0c0108b2u; return 0; }
r[0]=code_base|0x000108b4u;
goto P_0c0108b4;
P_0c0108b4: /* original d215, guest PC 0x0c0108b4 */
if(!s->budget--) { s->failed_pc=0x0c0108b4u; return 0; }
r[2]=read(ram,0x0c01090cu,4);
goto P_0c0108b6;
P_0c0108b6: /* original 330c, guest PC 0x0c0108b6 */
if(!s->budget--) { s->failed_pc=0x0c0108b6u; return 0; }
r[3]+=r[0];
goto P_0c0108b8;
P_0c0108b8: /* original 6133, guest PC 0x0c0108b8 */
if(!s->budget--) { s->failed_pc=0x0c0108b8u; return 0; }
r[1]=r[3];
goto P_0c0108ba;
P_0c0108ba: /* original 212b, guest PC 0x0c0108ba */
if(!s->budget--) { s->failed_pc=0x0c0108bau; return 0; }
r[1]|=r[2];
goto P_0c0108bc;
P_0c0108bc: /* original 410b, guest PC 0x0c0108bc */
if(!s->budget--) { s->failed_pc=0x0c0108bcu; return 0; }
target=r[1];
r[16]=code_base|0x0c0108c0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0108c0u) { target=s->pc; goto dispatch; }
goto P_0c0108c0;
P_0c0108be: /* original 0009, guest PC 0x0c0108be */
if(!s->budget--) { s->failed_pc=0x0c0108beu; return 0; }
goto P_0c0108c0;
P_0c0108c0: /* original 6403, guest PC 0x0c0108c0 */
if(!s->budget--) { s->failed_pc=0x0c0108c0u; return 0; }
r[4]=r[0];
goto P_0c0108c2;
P_0c0108c2: /* original d21b, guest PC 0x0c0108c2 */
if(!s->budget--) { s->failed_pc=0x0c0108c2u; return 0; }
r[2]=read(ram,0x0c010930u,4);
goto P_0c0108c4;
P_0c0108c4: /* original 6322, guest PC 0x0c0108c4 */
if(!s->budget--) { s->failed_pc=0x0c0108c4u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0108c6;
P_0c0108c6: /* original 2338, guest PC 0x0c0108c6 */
if(!s->budget--) { s->failed_pc=0x0c0108c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0108c8;
P_0c0108c8: /* original 890b, guest PC 0x0c0108c8 */
if(!s->budget--) { s->failed_pc=0x0c0108c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0108e2; }
goto P_0c0108ca;
P_0c0108ca: /* original 60f2, guest PC 0x0c0108ca */
if(!s->budget--) { s->failed_pc=0x0c0108cau; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0108cc;
P_0c0108cc: /* original 8801, guest PC 0x0c0108cc */
if(!s->budget--) { s->failed_pc=0x0c0108ccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0108ce;
P_0c0108ce: /* original 8b08, guest PC 0x0c0108ce */
if(!s->budget--) { s->failed_pc=0x0c0108ceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0108e2; }
goto P_0c0108d0;
P_0c0108d0: /* original d218, guest PC 0x0c0108d0 */
if(!s->budget--) { s->failed_pc=0x0c0108d0u; return 0; }
r[2]=read(ram,0x0c010934u,4);
goto P_0c0108d2;
P_0c0108d2: /* original c700, guest PC 0x0c0108d2 */
if(!s->budget--) { s->failed_pc=0x0c0108d2u; return 0; }
r[0]=code_base|0x000108d4u;
goto P_0c0108d4;
P_0c0108d4: /* original d30d, guest PC 0x0c0108d4 */
if(!s->budget--) { s->failed_pc=0x0c0108d4u; return 0; }
r[3]=read(ram,0x0c01090cu,4);
goto P_0c0108d6;
P_0c0108d6: /* original 320c, guest PC 0x0c0108d6 */
if(!s->budget--) { s->failed_pc=0x0c0108d6u; return 0; }
r[2]+=r[0];
goto P_0c0108d8;
P_0c0108d8: /* original 6123, guest PC 0x0c0108d8 */
if(!s->budget--) { s->failed_pc=0x0c0108d8u; return 0; }
r[1]=r[2];
goto P_0c0108da;
P_0c0108da: /* original 213b, guest PC 0x0c0108da */
if(!s->budget--) { s->failed_pc=0x0c0108dau; return 0; }
r[1]|=r[3];
goto P_0c0108dc;
P_0c0108dc: /* original 410b, guest PC 0x0c0108dc */
if(!s->budget--) { s->failed_pc=0x0c0108dcu; return 0; }
target=r[1];
r[16]=code_base|0x0c0108e0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0108e0u) { target=s->pc; goto dispatch; }
goto P_0c0108e0;
P_0c0108de: /* original 0009, guest PC 0x0c0108de */
if(!s->budget--) { s->failed_pc=0x0c0108deu; return 0; }
goto P_0c0108e0;
P_0c0108e0: /* original 6403, guest PC 0x0c0108e0 */
if(!s->budget--) { s->failed_pc=0x0c0108e0u; return 0; }
r[4]=r[0];
goto P_0c0108e2;
P_0c0108e2: /* original 7f04, guest PC 0x0c0108e2 */
if(!s->budget--) { s->failed_pc=0x0c0108e2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0108e4;
P_0c0108e4: /* original 4f26, guest PC 0x0c0108e4 */
if(!s->budget--) { s->failed_pc=0x0c0108e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0108e6;
P_0c0108e6: /* original 000b, guest PC 0x0c0108e6 */
if(!s->budget--) { s->failed_pc=0x0c0108e6u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c0108e8: /* original 6043, guest PC 0x0c0108e8 */
if(!s->budget--) { s->failed_pc=0x0c0108e8u; return 0; }
r[0]=r[4];
return vf3_matrix_family(0x0c0108eau,s,ram);
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
goto P_0c01098c;
P_0c01098c: /* original 4f22, guest PC 0x0c01098c */
if(!s->budget--) { s->failed_pc=0x0c01098cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c01098e;
P_0c01098e: /* original 7ff4, guest PC 0x0c01098e */
if(!s->budget--) { s->failed_pc=0x0c01098eu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c010990;
P_0c010990: /* original 1f42, guest PC 0x0c010990 */
if(!s->budget--) { s->failed_pc=0x0c010990u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c010992;
P_0c010992: /* original 1f51, guest PC 0x0c010992 */
if(!s->budget--) { s->failed_pc=0x0c010992u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c010994;
P_0c010994: /* original 2f62, guest PC 0x0c010994 */
if(!s->budget--) { s->failed_pc=0x0c010994u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c010996;
P_0c010996: /* original 53f2, guest PC 0x0c010996 */
if(!s->budget--) { s->failed_pc=0x0c010996u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c010998;
P_0c010998: /* original 2338, guest PC 0x0c010998 */
if(!s->budget--) { s->failed_pc=0x0c010998u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c01099a;
P_0c01099a: /* original 8906, guest PC 0x0c01099a */
if(!s->budget--) { s->failed_pc=0x0c01099au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0109aa; }
goto P_0c01099c;
P_0c01099c: /* original d331, guest PC 0x0c01099c */
if(!s->budget--) { s->failed_pc=0x0c01099cu; return 0; }
r[3]=read(ram,0x0c010a64u,4);
goto P_0c01099e;
P_0c01099e: /* original c700, guest PC 0x0c01099e */
if(!s->budget--) { s->failed_pc=0x0c01099eu; return 0; }
r[0]=code_base|0x000109a0u;
goto P_0c0109a0;
P_0c0109a0: /* original d22d, guest PC 0x0c0109a0 */
if(!s->budget--) { s->failed_pc=0x0c0109a0u; return 0; }
r[2]=read(ram,0x0c010a58u,4);
goto P_0c0109a2;
P_0c0109a2: /* original 330c, guest PC 0x0c0109a2 */
if(!s->budget--) { s->failed_pc=0x0c0109a2u; return 0; }
r[3]+=r[0];
goto P_0c0109a4;
P_0c0109a4: /* original 6133, guest PC 0x0c0109a4 */
if(!s->budget--) { s->failed_pc=0x0c0109a4u; return 0; }
r[1]=r[3];
goto P_0c0109a6;
P_0c0109a6: /* original a005, guest PC 0x0c0109a6 */
if(!s->budget--) { s->failed_pc=0x0c0109a6u; return 0; }
goto P_0c0109b4;
P_0c0109a8: /* original 0009, guest PC 0x0c0109a8 */
if(!s->budget--) { s->failed_pc=0x0c0109a8u; return 0; }
goto P_0c0109aa;
P_0c0109aa: /* original d32f, guest PC 0x0c0109aa */
if(!s->budget--) { s->failed_pc=0x0c0109aau; return 0; }
r[3]=read(ram,0x0c010a68u,4);
goto P_0c0109ac;
P_0c0109ac: /* original c700, guest PC 0x0c0109ac */
if(!s->budget--) { s->failed_pc=0x0c0109acu; return 0; }
r[0]=code_base|0x000109b0u;
goto P_0c0109ae;
P_0c0109ae: /* original 330c, guest PC 0x0c0109ae */
if(!s->budget--) { s->failed_pc=0x0c0109aeu; return 0; }
r[3]+=r[0];
goto P_0c0109b0;
P_0c0109b0: /* original d229, guest PC 0x0c0109b0 */
if(!s->budget--) { s->failed_pc=0x0c0109b0u; return 0; }
r[2]=read(ram,0x0c010a58u,4);
goto P_0c0109b2;
P_0c0109b2: /* original 6133, guest PC 0x0c0109b2 */
if(!s->budget--) { s->failed_pc=0x0c0109b2u; return 0; }
r[1]=r[3];
goto P_0c0109b4;
P_0c0109b4: /* original 65f2, guest PC 0x0c0109b4 */
if(!s->budget--) { s->failed_pc=0x0c0109b4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0109b6;
P_0c0109b6: /* original 212b, guest PC 0x0c0109b6 */
if(!s->budget--) { s->failed_pc=0x0c0109b6u; return 0; }
r[1]|=r[2];
goto P_0c0109b8;
P_0c0109b8: /* original 410b, guest PC 0x0c0109b8 */
if(!s->budget--) { s->failed_pc=0x0c0109b8u; return 0; }
target=r[1];
r[16]=code_base|0x0c0109bcu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0109bcu) { target=s->pc; goto dispatch; }
goto P_0c0109bc;
P_0c0109ba: /* original 54f1, guest PC 0x0c0109ba */
if(!s->budget--) { s->failed_pc=0x0c0109bau; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0109bc;
P_0c0109bc: /* original 7f0c, guest PC 0x0c0109bc */
if(!s->budget--) { s->failed_pc=0x0c0109bcu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0109be;
P_0c0109be: /* original 4f26, guest PC 0x0c0109be */
if(!s->budget--) { s->failed_pc=0x0c0109beu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0109c0;
P_0c0109c0: /* original 000b, guest PC 0x0c0109c0 */
if(!s->budget--) { s->failed_pc=0x0c0109c0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0109c2: /* original 0009, guest PC 0x0c0109c2 */
if(!s->budget--) { s->failed_pc=0x0c0109c2u; return 0; }
goto P_0c0109c4;
P_0c0109c4: /* original 4f22, guest PC 0x0c0109c4 */
if(!s->budget--) { s->failed_pc=0x0c0109c4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0109c6;
P_0c0109c6: /* original 7ffc, guest PC 0x0c0109c6 */
if(!s->budget--) { s->failed_pc=0x0c0109c6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0109c8;
P_0c0109c8: /* original 6343, guest PC 0x0c0109c8 */
if(!s->budget--) { s->failed_pc=0x0c0109c8u; return 0; }
r[3]=r[4];
goto P_0c0109ca;
P_0c0109ca: /* original 2338, guest PC 0x0c0109ca */
if(!s->budget--) { s->failed_pc=0x0c0109cau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0109cc;
P_0c0109cc: /* original 8d07, guest PC 0x0c0109cc */
if(!s->budget--) { s->failed_pc=0x0c0109ccu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[4],4);
if(cond) { goto P_0c0109de; }
goto P_0c0109d0;
P_0c0109ce: /* original 2f42, guest PC 0x0c0109ce */
if(!s->budget--) { s->failed_pc=0x0c0109ceu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0109d0;
P_0c0109d0: /* original d326, guest PC 0x0c0109d0 */
if(!s->budget--) { s->failed_pc=0x0c0109d0u; return 0; }
r[3]=read(ram,0x0c010a6cu,4);
goto P_0c0109d2;
P_0c0109d2: /* original c700, guest PC 0x0c0109d2 */
if(!s->budget--) { s->failed_pc=0x0c0109d2u; return 0; }
r[0]=code_base|0x000109d4u;
goto P_0c0109d4;
P_0c0109d4: /* original d220, guest PC 0x0c0109d4 */
if(!s->budget--) { s->failed_pc=0x0c0109d4u; return 0; }
r[2]=read(ram,0x0c010a58u,4);
goto P_0c0109d6;
P_0c0109d6: /* original 330c, guest PC 0x0c0109d6 */
if(!s->budget--) { s->failed_pc=0x0c0109d6u; return 0; }
r[3]+=r[0];
goto P_0c0109d8;
P_0c0109d8: /* original 6133, guest PC 0x0c0109d8 */
if(!s->budget--) { s->failed_pc=0x0c0109d8u; return 0; }
r[1]=r[3];
goto P_0c0109da;
P_0c0109da: /* original a005, guest PC 0x0c0109da */
if(!s->budget--) { s->failed_pc=0x0c0109dau; return 0; }
goto P_0c0109e8;
P_0c0109dc: /* original 0009, guest PC 0x0c0109dc */
if(!s->budget--) { s->failed_pc=0x0c0109dcu; return 0; }
goto P_0c0109de;
P_0c0109de: /* original d324, guest PC 0x0c0109de */
if(!s->budget--) { s->failed_pc=0x0c0109deu; return 0; }
r[3]=read(ram,0x0c010a70u,4);
goto P_0c0109e0;
P_0c0109e0: /* original c700, guest PC 0x0c0109e0 */
if(!s->budget--) { s->failed_pc=0x0c0109e0u; return 0; }
r[0]=code_base|0x000109e4u;
goto P_0c0109e2;
P_0c0109e2: /* original 330c, guest PC 0x0c0109e2 */
if(!s->budget--) { s->failed_pc=0x0c0109e2u; return 0; }
r[3]+=r[0];
goto P_0c0109e4;
P_0c0109e4: /* original d21c, guest PC 0x0c0109e4 */
if(!s->budget--) { s->failed_pc=0x0c0109e4u; return 0; }
r[2]=read(ram,0x0c010a58u,4);
goto P_0c0109e6;
P_0c0109e6: /* original 6133, guest PC 0x0c0109e6 */
if(!s->budget--) { s->failed_pc=0x0c0109e6u; return 0; }
r[1]=r[3];
goto P_0c0109e8;
P_0c0109e8: /* original 212b, guest PC 0x0c0109e8 */
if(!s->budget--) { s->failed_pc=0x0c0109e8u; return 0; }
r[1]|=r[2];
goto P_0c0109ea;
P_0c0109ea: /* original 410b, guest PC 0x0c0109ea */
if(!s->budget--) { s->failed_pc=0x0c0109eau; return 0; }
target=r[1];
r[16]=code_base|0x0c0109eeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0109eeu) { target=s->pc; goto dispatch; }
goto P_0c0109ee;
P_0c0109ec: /* original 0009, guest PC 0x0c0109ec */
if(!s->budget--) { s->failed_pc=0x0c0109ecu; return 0; }
goto P_0c0109ee;
P_0c0109ee: /* original 7f04, guest PC 0x0c0109ee */
if(!s->budget--) { s->failed_pc=0x0c0109eeu; return 0; }
r[15]+=0x00000004u;
goto P_0c0109f0;
P_0c0109f0: /* original 4f26, guest PC 0x0c0109f0 */
if(!s->budget--) { s->failed_pc=0x0c0109f0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0109f2;
P_0c0109f2: /* original 000b, guest PC 0x0c0109f2 */
if(!s->budget--) { s->failed_pc=0x0c0109f2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0109f4: /* original 0009, guest PC 0x0c0109f4 */
if(!s->budget--) { s->failed_pc=0x0c0109f4u; return 0; }
return vf3_matrix_family(0x0c0109f6u,s,ram);
P_0c0110ee: /* original 4f22, guest PC 0x0c0110ee */
if(!s->budget--) { s->failed_pc=0x0c0110eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0110f0;
P_0c0110f0: /* original 63e2, guest PC 0x0c0110f0 */
if(!s->budget--) { s->failed_pc=0x0c0110f0u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0110f2;
P_0c0110f2: /* original 0324, guest PC 0x0c0110f2 */
if(!s->budget--) { s->failed_pc=0x0c0110f2u; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c0110f4;
P_0c0110f4: /* original d535, guest PC 0x0c0110f4 */
if(!s->budget--) { s->failed_pc=0x0c0110f4u; return 0; }
r[5]=read(ram,0x0c0111ccu,4);
goto P_0c0110f6;
P_0c0110f6: /* original e480, guest PC 0x0c0110f6 */
if(!s->budget--) { s->failed_pc=0x0c0110f6u; return 0; }
r[4]=0xffffff80u;
goto P_0c0110f8;
P_0c0110f8: /* original 6043, guest PC 0x0c0110f8 */
if(!s->budget--) { s->failed_pc=0x0c0110f8u; return 0; }
r[0]=r[4];
goto P_0c0110fa;
P_0c0110fa: /* original 6352, guest PC 0x0c0110fa */
if(!s->budget--) { s->failed_pc=0x0c0110fau; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c0110fc;
P_0c0110fc: /* original 803c, guest PC 0x0c0110fc */
if(!s->budget--) { s->failed_pc=0x0c0110fcu; return 0; }
write(ram,r[3]+12,r[0],1);
goto P_0c0110fe;
P_0c0110fe: /* original 6352, guest PC 0x0c0110fe */
if(!s->budget--) { s->failed_pc=0x0c0110feu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c011100;
P_0c011100: /* original e024, guest PC 0x0c011100 */
if(!s->budget--) { s->failed_pc=0x0c011100u; return 0; }
r[0]=0x00000024u;
goto P_0c011102;
P_0c011102: /* original 0344, guest PC 0x0c011102 */
if(!s->budget--) { s->failed_pc=0x0c011102u; return 0; }
write(ram,r[3]+r[0],r[4],1);
goto P_0c011104;
P_0c011104: /* original 63e2, guest PC 0x0c011104 */
if(!s->budget--) { s->failed_pc=0x0c011104u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c011106;
P_0c011106: /* original e014, guest PC 0x0c011106 */
if(!s->budget--) { s->failed_pc=0x0c011106u; return 0; }
r[0]=0x00000014u;
goto P_0c011108;
P_0c011108: /* original e243, guest PC 0x0c011108 */
if(!s->budget--) { s->failed_pc=0x0c011108u; return 0; }
r[2]=0x00000043u;
goto P_0c01110a;
P_0c01110a: /* original 0324, guest PC 0x0c01110a */
if(!s->budget--) { s->failed_pc=0x0c01110au; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c01110c;
P_0c01110c: /* original d332, guest PC 0x0c01110c */
if(!s->budget--) { s->failed_pc=0x0c01110cu; return 0; }
r[3]=read(ram,0x0c0111d8u,4);
goto P_0c01110e;
P_0c01110e: /* original c700, guest PC 0x0c01110e */
if(!s->budget--) { s->failed_pc=0x0c01110eu; return 0; }
r[0]=code_base|0x00011110u;
goto P_0c011110;
P_0c011110: /* original d230, guest PC 0x0c011110 */
if(!s->budget--) { s->failed_pc=0x0c011110u; return 0; }
r[2]=read(ram,0x0c0111d4u,4);
goto P_0c011112;
P_0c011112: /* original 330c, guest PC 0x0c011112 */
if(!s->budget--) { s->failed_pc=0x0c011112u; return 0; }
r[3]+=r[0];
goto P_0c011114;
P_0c011114: /* original 6133, guest PC 0x0c011114 */
if(!s->budget--) { s->failed_pc=0x0c011114u; return 0; }
r[1]=r[3];
goto P_0c011116;
P_0c011116: /* original 212b, guest PC 0x0c011116 */
if(!s->budget--) { s->failed_pc=0x0c011116u; return 0; }
r[1]|=r[2];
goto P_0c011118;
P_0c011118: /* original 410b, guest PC 0x0c011118 */
if(!s->budget--) { s->failed_pc=0x0c011118u; return 0; }
target=r[1];
r[16]=code_base|0x0c01111cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c01111cu) { target=s->pc; goto dispatch; }
goto P_0c01111c;
P_0c01111a: /* original 0009, guest PC 0x0c01111a */
if(!s->budget--) { s->failed_pc=0x0c01111au; return 0; }
goto P_0c01111c;
P_0c01111c: /* original 63e2, guest PC 0x0c01111c */
if(!s->budget--) { s->failed_pc=0x0c01111cu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c01111e;
P_0c01111e: /* original e03c, guest PC 0x0c01111e */
if(!s->budget--) { s->failed_pc=0x0c01111eu; return 0; }
r[0]=0x0000003cu;
goto P_0c011120;
P_0c011120: /* original e200, guest PC 0x0c011120 */
if(!s->budget--) { s->failed_pc=0x0c011120u; return 0; }
r[2]=0x00000000u;
goto P_0c011122;
P_0c011122: /* original 0324, guest PC 0x0c011122 */
if(!s->budget--) { s->failed_pc=0x0c011122u; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c011124;
P_0c011124: /* original 4f26, guest PC 0x0c011124 */
if(!s->budget--) { s->failed_pc=0x0c011124u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c011126;
P_0c011126: /* original 000b, guest PC 0x0c011126 */
if(!s->budget--) { s->failed_pc=0x0c011126u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c011128: /* original 6ef6, guest PC 0x0c011128 */
if(!s->budget--) { s->failed_pc=0x0c011128u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c01112a;
P_0c01112a: /* original d327, guest PC 0x0c01112a */
if(!s->budget--) { s->failed_pc=0x0c01112au; return 0; }
r[3]=read(ram,0x0c0111c8u,4);
goto P_0c01112c;
P_0c01112c: /* original 4f22, guest PC 0x0c01112c */
if(!s->budget--) { s->failed_pc=0x0c01112cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c01112e;
P_0c01112e: /* original 6432, guest PC 0x0c01112e */
if(!s->budget--) { s->failed_pc=0x0c01112eu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c011130;
P_0c011130: /* original 9647, guest PC 0x0c011130 */
if(!s->budget--) { s->failed_pc=0x0c011130u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0111c2u,2);
goto P_0c011132;
P_0c011132: /* original 8448, guest PC 0x0c011132 */
if(!s->budget--) { s->failed_pc=0x0c011132u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c011134;
P_0c011134: /* original 2068, guest PC 0x0c011134 */
if(!s->budget--) { s->failed_pc=0x0c011134u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[6])==0)!=0);
goto P_0c011136;
P_0c011136: /* original 890a, guest PC 0x0c011136 */
if(!s->budget--) { s->failed_pc=0x0c011136u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c01114e; }
goto P_0c011138;
P_0c011138: /* original e010, guest PC 0x0c011138 */
if(!s->budget--) { s->failed_pc=0x0c011138u; return 0; }
r[0]=0x00000010u;
goto P_0c01113a;
P_0c01113a: /* original 054c, guest PC 0x0c01113a */
if(!s->budget--) { s->failed_pc=0x0c01113au; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c01113c;
P_0c01113c: /* original 605c, guest PC 0x0c01113c */
if(!s->budget--) { s->failed_pc=0x0c01113cu; return 0; }
r[0]=r[5]&255u;
goto P_0c01113e;
P_0c01113e: /* original e314, guest PC 0x0c01113e */
if(!s->budget--) { s->failed_pc=0x0c01113eu; return 0; }
r[3]=0x00000014u;
goto P_0c011140;
P_0c011140: /* original 3060, guest PC 0x0c011140 */
if(!s->budget--) { s->failed_pc=0x0c011140u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[6])!=0);
goto P_0c011142;
P_0c011142: /* original 334c, guest PC 0x0c011142 */
if(!s->budget--) { s->failed_pc=0x0c011142u; return 0; }
r[3]+=r[4];
goto P_0c011144;
P_0c011144: /* original 8d06, guest PC 0x0c011144 */
if(!s->budget--) { s->failed_pc=0x0c011144u; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
if(cond) { goto P_0c011154; }
goto P_0c011148;
P_0c011146: /* original 6330, guest PC 0x0c011146 */
if(!s->budget--) { s->failed_pc=0x0c011146u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
goto P_0c011148;
P_0c011148: /* original 933c, guest PC 0x0c011148 */
if(!s->budget--) { s->failed_pc=0x0c011148u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0111c4u,2);
goto P_0c01114a;
P_0c01114a: /* original 3030, guest PC 0x0c01114a */
if(!s->budget--) { s->failed_pc=0x0c01114au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c01114c;
P_0c01114c: /* original 8902, guest PC 0x0c01114c */
if(!s->budget--) { s->failed_pc=0x0c01114cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c011154; }
goto P_0c01114e;
P_0c01114e: /* original 4f26, guest PC 0x0c01114e */
if(!s->budget--) { s->failed_pc=0x0c01114eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c011150;
P_0c011150: /* original 000b, guest PC 0x0c011150 */
if(!s->budget--) { s->failed_pc=0x0c011150u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c011152: /* original e000, guest PC 0x0c011152 */
if(!s->budget--) { s->failed_pc=0x0c011152u; return 0; }
r[0]=0x00000000u;
goto P_0c011154;
P_0c011154: /* original 9336, guest PC 0x0c011154 */
if(!s->budget--) { s->failed_pc=0x0c011154u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0111c4u,2);
goto P_0c011156;
P_0c011156: /* original 3030, guest PC 0x0c011156 */
if(!s->budget--) { s->failed_pc=0x0c011156u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c011158;
P_0c011158: /* original 8b0d, guest PC 0x0c011158 */
if(!s->budget--) { s->failed_pc=0x0c011158u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c011176; }
goto P_0c01115a;
P_0c01115a: /* original e014, guest PC 0x0c01115a */
if(!s->budget--) { s->failed_pc=0x0c01115au; return 0; }
r[0]=0x00000014u;
goto P_0c01115c;
P_0c01115c: /* original e139, guest PC 0x0c01115c */
if(!s->budget--) { s->failed_pc=0x0c01115cu; return 0; }
r[1]=0x00000039u;
goto P_0c01115e;
P_0c01115e: /* original 0414, guest PC 0x0c01115e */
if(!s->budget--) { s->failed_pc=0x0c01115eu; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c011160;
P_0c011160: /* original d21e, guest PC 0x0c011160 */
if(!s->budget--) { s->failed_pc=0x0c011160u; return 0; }
r[2]=read(ram,0x0c0111dcu,4);
goto P_0c011162;
P_0c011162: /* original c700, guest PC 0x0c011162 */
if(!s->budget--) { s->failed_pc=0x0c011162u; return 0; }
r[0]=code_base|0x00011164u;
goto P_0c011164;
P_0c011164: /* original d11b, guest PC 0x0c011164 */
if(!s->budget--) { s->failed_pc=0x0c011164u; return 0; }
r[1]=read(ram,0x0c0111d4u,4);
goto P_0c011166;
P_0c011166: /* original 320c, guest PC 0x0c011166 */
if(!s->budget--) { s->failed_pc=0x0c011166u; return 0; }
r[2]+=r[0];
goto P_0c011168;
P_0c011168: /* original 6023, guest PC 0x0c011168 */
if(!s->budget--) { s->failed_pc=0x0c011168u; return 0; }
r[0]=r[2];
goto P_0c01116a;
P_0c01116a: /* original 201b, guest PC 0x0c01116a */
if(!s->budget--) { s->failed_pc=0x0c01116au; return 0; }
r[0]|=r[1];
goto P_0c01116c;
P_0c01116c: /* original 400b, guest PC 0x0c01116c */
if(!s->budget--) { s->failed_pc=0x0c01116cu; return 0; }
target=r[0];
r[16]=code_base|0x0c011170u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c011170u) { target=s->pc; goto dispatch; }
goto P_0c011170;
P_0c01116e: /* original 0009, guest PC 0x0c01116e */
if(!s->budget--) { s->failed_pc=0x0c01116eu; return 0; }
goto P_0c011170;
P_0c011170: /* original d21b, guest PC 0x0c011170 */
if(!s->budget--) { s->failed_pc=0x0c011170u; return 0; }
r[2]=read(ram,0x0c0111e0u,4);
goto P_0c011172;
P_0c011172: /* original 6322, guest PC 0x0c011172 */
if(!s->budget--) { s->failed_pc=0x0c011172u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c011174;
P_0c011174: /* original 6130, guest PC 0x0c011174 */
if(!s->budget--) { s->failed_pc=0x0c011174u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[1]=tmp;
goto P_0c011176;
P_0c011176: /* original e001, guest PC 0x0c011176 */
if(!s->budget--) { s->failed_pc=0x0c011176u; return 0; }
r[0]=0x00000001u;
goto P_0c011178;
P_0c011178: /* original 4f26, guest PC 0x0c011178 */
if(!s->budget--) { s->failed_pc=0x0c011178u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c01117a;
P_0c01117a: /* original 000b, guest PC 0x0c01117a */
if(!s->budget--) { s->failed_pc=0x0c01117au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c01117c: /* original 0009, guest PC 0x0c01117c */
if(!s->budget--) { s->failed_pc=0x0c01117cu; return 0; }
goto P_0c01117e;
P_0c01117e: /* original 4f22, guest PC 0x0c01117e */
if(!s->budget--) { s->failed_pc=0x0c01117eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c011180;
P_0c011180: /* original 7ffc, guest PC 0x0c011180 */
if(!s->budget--) { s->failed_pc=0x0c011180u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c011182;
P_0c011182: /* original d211, guest PC 0x0c011182 */
if(!s->budget--) { s->failed_pc=0x0c011182u; return 0; }
r[2]=read(ram,0x0c0111c8u,4);
goto P_0c011184;
P_0c011184: /* original e014, guest PC 0x0c011184 */
if(!s->budget--) { s->failed_pc=0x0c011184u; return 0; }
r[0]=0x00000014u;
goto P_0c011186;
P_0c011186: /* original e13b, guest PC 0x0c011186 */
if(!s->budget--) { s->failed_pc=0x0c011186u; return 0; }
r[1]=0x0000003bu;
goto P_0c011188;
P_0c011188: /* original 2f42, guest PC 0x0c011188 */
if(!s->budget--) { s->failed_pc=0x0c011188u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c01118a;
P_0c01118a: /* original 6322, guest PC 0x0c01118a */
if(!s->budget--) { s->failed_pc=0x0c01118au; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c01118c;
P_0c01118c: /* original 0314, guest PC 0x0c01118c */
if(!s->budget--) { s->failed_pc=0x0c01118cu; return 0; }
write(ram,r[3]+r[0],r[1],1);
goto P_0c01118e;
P_0c01118e: /* original d315, guest PC 0x0c01118e */
if(!s->budget--) { s->failed_pc=0x0c01118eu; return 0; }
r[3]=read(ram,0x0c0111e4u,4);
goto P_0c011190;
P_0c011190: /* original c700, guest PC 0x0c011190 */
if(!s->budget--) { s->failed_pc=0x0c011190u; return 0; }
r[0]=code_base|0x00011194u;
goto P_0c011192;
P_0c011192: /* original 330c, guest PC 0x0c011192 */
if(!s->budget--) { s->failed_pc=0x0c011192u; return 0; }
r[3]+=r[0];
goto P_0c011194;
P_0c011194: /* original d10f, guest PC 0x0c011194 */
if(!s->budget--) { s->failed_pc=0x0c011194u; return 0; }
r[1]=read(ram,0x0c0111d4u,4);
goto P_0c011196;
P_0c011196: /* original 6033, guest PC 0x0c011196 */
if(!s->budget--) { s->failed_pc=0x0c011196u; return 0; }
r[0]=r[3];
goto P_0c011198;
P_0c011198: /* original 201b, guest PC 0x0c011198 */
if(!s->budget--) { s->failed_pc=0x0c011198u; return 0; }
r[0]|=r[1];
goto P_0c01119a;
P_0c01119a: /* original 400b, guest PC 0x0c01119a */
if(!s->budget--) { s->failed_pc=0x0c01119au; return 0; }
target=r[0];
r[16]=code_base|0x0c01119eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c01119eu) { target=s->pc; goto dispatch; }
goto P_0c01119e;
P_0c01119c: /* original 0009, guest PC 0x0c01119c */
if(!s->budget--) { s->failed_pc=0x0c01119cu; return 0; }
goto P_0c01119e;
P_0c01119e: /* original d110, guest PC 0x0c01119e */
if(!s->budget--) { s->failed_pc=0x0c01119eu; return 0; }
r[1]=read(ram,0x0c0111e0u,4);
goto P_0c0111a0;
P_0c0111a0: /* original e600, guest PC 0x0c0111a0 */
if(!s->budget--) { s->failed_pc=0x0c0111a0u; return 0; }
r[6]=0x00000000u;
goto P_0c0111a2;
P_0c0111a2: /* original 65f2, guest PC 0x0c0111a2 */
if(!s->budget--) { s->failed_pc=0x0c0111a2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0111a4;
P_0c0111a4: /* original e710, guest PC 0x0c0111a4 */
if(!s->budget--) { s->failed_pc=0x0c0111a4u; return 0; }
r[7]=0x00000010u;
goto P_0c0111a6;
P_0c0111a6: /* original 6463, guest PC 0x0c0111a6 */
if(!s->budget--) { s->failed_pc=0x0c0111a6u; return 0; }
r[4]=r[6];
goto P_0c0111a8;
P_0c0111a8: /* original 6212, guest PC 0x0c0111a8 */
if(!s->budget--) { s->failed_pc=0x0c0111a8u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0111aa;
P_0c0111aa: /* original 324c, guest PC 0x0c0111aa */
if(!s->budget--) { s->failed_pc=0x0c0111aau; return 0; }
r[2]+=r[4];
goto P_0c0111ac;
P_0c0111ac: /* original 6320, guest PC 0x0c0111ac */
if(!s->budget--) { s->failed_pc=0x0c0111acu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c0111ae;
P_0c0111ae: /* original 7601, guest PC 0x0c0111ae */
if(!s->budget--) { s->failed_pc=0x0c0111aeu; return 0; }
r[6]+=0x00000001u;
goto P_0c0111b0;
P_0c0111b0: /* original 2530, guest PC 0x0c0111b0 */
if(!s->budget--) { s->failed_pc=0x0c0111b0u; return 0; }
write(ram,r[5],r[3],1);
goto P_0c0111b2;
P_0c0111b2: /* original 3673, guest PC 0x0c0111b2 */
if(!s->budget--) { s->failed_pc=0x0c0111b2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c0111b4;
P_0c0111b4: /* original 7404, guest PC 0x0c0111b4 */
if(!s->budget--) { s->failed_pc=0x0c0111b4u; return 0; }
r[4]+=0x00000004u;
goto P_0c0111b6;
P_0c0111b6: /* original 8ff7, guest PC 0x0c0111b6 */
if(!s->budget--) { s->failed_pc=0x0c0111b6u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(!cond) { goto P_0c0111a8; }
goto P_0c0111ba;
P_0c0111b8: /* original 7501, guest PC 0x0c0111b8 */
if(!s->budget--) { s->failed_pc=0x0c0111b8u; return 0; }
r[5]+=0x00000001u;
goto P_0c0111ba;
P_0c0111ba: /* original 7f04, guest PC 0x0c0111ba */
if(!s->budget--) { s->failed_pc=0x0c0111bau; return 0; }
r[15]+=0x00000004u;
goto P_0c0111bc;
P_0c0111bc: /* original 4f26, guest PC 0x0c0111bc */
if(!s->budget--) { s->failed_pc=0x0c0111bcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0111be;
P_0c0111be: /* original 000b, guest PC 0x0c0111be */
if(!s->budget--) { s->failed_pc=0x0c0111beu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0111c0: /* original 0009, guest PC 0x0c0111c0 */
if(!s->budget--) { s->failed_pc=0x0c0111c0u; return 0; }
return vf3_matrix_family(0x0c0111c2u,s,ram);
P_0c0119a4: /* original 000b, guest PC 0x0c0119a4 */
if(!s->budget--) { s->failed_pc=0x0c0119a4u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0119a6: /* original 0009, guest PC 0x0c0119a6 */
if(!s->budget--) { s->failed_pc=0x0c0119a6u; return 0; }
return vf3_matrix_family(0x0c0119a8u,s,ram);
P_0c0119e0: /* original 2fe6, guest PC 0x0c0119e0 */
if(!s->budget--) { s->failed_pc=0x0c0119e0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0119e2;
P_0c0119e2: /* original ee00, guest PC 0x0c0119e2 */
if(!s->budget--) { s->failed_pc=0x0c0119e2u; return 0; }
r[14]=0x00000000u;
goto P_0c0119e4;
P_0c0119e4: /* original 2fd6, guest PC 0x0c0119e4 */
if(!s->budget--) { s->failed_pc=0x0c0119e4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0119e6;
P_0c0119e6: /* original ed00, guest PC 0x0c0119e6 */
if(!s->budget--) { s->failed_pc=0x0c0119e6u; return 0; }
r[13]=0x00000000u;
goto P_0c0119e8;
P_0c0119e8: /* original 2fc6, guest PC 0x0c0119e8 */
if(!s->budget--) { s->failed_pc=0x0c0119e8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0119ea;
P_0c0119ea: /* original 2fb6, guest PC 0x0c0119ea */
if(!s->budget--) { s->failed_pc=0x0c0119eau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0119ec;
P_0c0119ec: /* original 6b53, guest PC 0x0c0119ec */
if(!s->budget--) { s->failed_pc=0x0c0119ecu; return 0; }
r[11]=r[5];
goto P_0c0119ee;
P_0c0119ee: /* original 4f22, guest PC 0x0c0119ee */
if(!s->budget--) { s->failed_pc=0x0c0119eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0119f0;
P_0c0119f0: /* original dc21, guest PC 0x0c0119f0 */
if(!s->budget--) { s->failed_pc=0x0c0119f0u; return 0; }
r[12]=read(ram,0x0c011a78u,4);
goto P_0c0119f2;
P_0c0119f2: /* original 4b15, guest PC 0x0c0119f2 */
if(!s->budget--) { s->failed_pc=0x0c0119f2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>0)!=0);
goto P_0c0119f4;
P_0c0119f4: /* original 8f0c, guest PC 0x0c0119f4 */
if(!s->budget--) { s->failed_pc=0x0c0119f4u; return 0; }
cond=r[17]&1u;
r[14]+=r[4];
if(!cond) { goto P_0c011a10; }
goto P_0c0119f8;
P_0c0119f6: /* original 3e4c, guest PC 0x0c0119f6 */
if(!s->budget--) { s->failed_pc=0x0c0119f6u; return 0; }
r[14]+=r[4];
goto P_0c0119f8;
P_0c0119f8: /* original d221, guest PC 0x0c0119f8 */
if(!s->budget--) { s->failed_pc=0x0c0119f8u; return 0; }
r[2]=read(ram,0x0c011a80u,4);
goto P_0c0119fa;
P_0c0119fa: /* original c700, guest PC 0x0c0119fa */
if(!s->budget--) { s->failed_pc=0x0c0119fau; return 0; }
r[0]=code_base|0x000119fcu;
goto P_0c0119fc;
P_0c0119fc: /* original 320c, guest PC 0x0c0119fc */
if(!s->budget--) { s->failed_pc=0x0c0119fcu; return 0; }
r[2]+=r[0];
goto P_0c0119fe;
P_0c0119fe: /* original 6323, guest PC 0x0c0119fe */
if(!s->budget--) { s->failed_pc=0x0c0119feu; return 0; }
r[3]=r[2];
goto P_0c011a00;
P_0c011a00: /* original 23cb, guest PC 0x0c011a00 */
if(!s->budget--) { s->failed_pc=0x0c011a00u; return 0; }
r[3]|=r[12];
goto P_0c011a02;
P_0c011a02: /* original 430b, guest PC 0x0c011a02 */
if(!s->budget--) { s->failed_pc=0x0c011a02u; return 0; }
target=r[3];
r[16]=code_base|0x0c011a06u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c011a06u) { target=s->pc; goto dispatch; }
goto P_0c011a06;
P_0c011a04: /* original 0009, guest PC 0x0c011a04 */
if(!s->budget--) { s->failed_pc=0x0c011a04u; return 0; }
goto P_0c011a06;
P_0c011a06: /* original 7d01, guest PC 0x0c011a06 */
if(!s->budget--) { s->failed_pc=0x0c011a06u; return 0; }
r[13]+=0x00000001u;
goto P_0c011a08;
P_0c011a08: /* original 2e00, guest PC 0x0c011a08 */
if(!s->budget--) { s->failed_pc=0x0c011a08u; return 0; }
write(ram,r[14],r[0],1);
goto P_0c011a0a;
P_0c011a0a: /* original 3db3, guest PC 0x0c011a0a */
if(!s->budget--) { s->failed_pc=0x0c011a0au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[11])!=0);
goto P_0c011a0c;
P_0c011a0c: /* original 8ff4, guest PC 0x0c011a0c */
if(!s->budget--) { s->failed_pc=0x0c011a0cu; return 0; }
cond=r[17]&1u;
r[14]+=0x00000001u;
if(!cond) { goto P_0c0119f8; }
goto P_0c011a10;
P_0c011a0e: /* original 7e01, guest PC 0x0c011a0e */
if(!s->budget--) { s->failed_pc=0x0c011a0eu; return 0; }
r[14]+=0x00000001u;
goto P_0c011a10;
P_0c011a10: /* original 4f26, guest PC 0x0c011a10 */
if(!s->budget--) { s->failed_pc=0x0c011a10u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c011a12;
P_0c011a12: /* original 6bf6, guest PC 0x0c011a12 */
if(!s->budget--) { s->failed_pc=0x0c011a12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c011a14;
P_0c011a14: /* original 6cf6, guest PC 0x0c011a14 */
if(!s->budget--) { s->failed_pc=0x0c011a14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c011a16;
P_0c011a16: /* original 6df6, guest PC 0x0c011a16 */
if(!s->budget--) { s->failed_pc=0x0c011a16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c011a18;
P_0c011a18: /* original 000b, guest PC 0x0c011a18 */
if(!s->budget--) { s->failed_pc=0x0c011a18u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c011a1a: /* original 6ef6, guest PC 0x0c011a1a */
if(!s->budget--) { s->failed_pc=0x0c011a1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c011a1c;
P_0c011a1c: /* original 2fe6, guest PC 0x0c011a1c */
if(!s->budget--) { s->failed_pc=0x0c011a1cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c011a1e;
P_0c011a1e: /* original 2fd6, guest PC 0x0c011a1e */
if(!s->budget--) { s->failed_pc=0x0c011a1eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c011a20;
P_0c011a20: /* original 2fc6, guest PC 0x0c011a20 */
if(!s->budget--) { s->failed_pc=0x0c011a20u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c011a22;
P_0c011a22: /* original 2fb6, guest PC 0x0c011a22 */
if(!s->budget--) { s->failed_pc=0x0c011a22u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c011a24;
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
return vf3_matrix_family(0x0c011a6cu,s,ram);
P_0c011afe: /* original 2fe6, guest PC 0x0c011afe */
if(!s->budget--) { s->failed_pc=0x0c011afeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c011b00;
P_0c011b00: /* original 4f22, guest PC 0x0c011b00 */
if(!s->budget--) { s->failed_pc=0x0c011b00u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c011b02;
P_0c011b02: /* original de19, guest PC 0x0c011b02 */
if(!s->budget--) { s->failed_pc=0x0c011b02u; return 0; }
r[14]=read(ram,0x0c011b68u,4);
goto P_0c011b04;
P_0c011b04: /* original d219, guest PC 0x0c011b04 */
if(!s->budget--) { s->failed_pc=0x0c011b04u; return 0; }
r[2]=read(ram,0x0c011b6cu,4);
goto P_0c011b06;
P_0c011b06: /* original c700, guest PC 0x0c011b06 */
if(!s->budget--) { s->failed_pc=0x0c011b06u; return 0; }
r[0]=code_base|0x00011b08u;
goto P_0c011b08;
P_0c011b08: /* original 320c, guest PC 0x0c011b08 */
if(!s->budget--) { s->failed_pc=0x0c011b08u; return 0; }
r[2]+=r[0];
goto P_0c011b0a;
P_0c011b0a: /* original 6323, guest PC 0x0c011b0a */
if(!s->budget--) { s->failed_pc=0x0c011b0au; return 0; }
r[3]=r[2];
goto P_0c011b0c;
P_0c011b0c: /* original 23eb, guest PC 0x0c011b0c */
if(!s->budget--) { s->failed_pc=0x0c011b0cu; return 0; }
r[3]|=r[14];
goto P_0c011b0e;
P_0c011b0e: /* original 430b, guest PC 0x0c011b0e */
if(!s->budget--) { s->failed_pc=0x0c011b0eu; return 0; }
target=r[3];
r[16]=code_base|0x0c011b12u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c011b12u) { target=s->pc; goto dispatch; }
goto P_0c011b12;
P_0c011b10: /* original 0009, guest PC 0x0c011b10 */
if(!s->budget--) { s->failed_pc=0x0c011b10u; return 0; }
goto P_0c011b12;
P_0c011b12: /* original 2008, guest PC 0x0c011b12 */
if(!s->budget--) { s->failed_pc=0x0c011b12u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c011b14;
P_0c011b14: /* original 89f6, guest PC 0x0c011b14 */
if(!s->budget--) { s->failed_pc=0x0c011b14u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c011b04; }
goto P_0c011b16;
P_0c011b16: /* original d313, guest PC 0x0c011b16 */
if(!s->budget--) { s->failed_pc=0x0c011b16u; return 0; }
r[3]=read(ram,0x0c011b64u,4);
goto P_0c011b18;
P_0c011b18: /* original d216, guest PC 0x0c011b18 */
if(!s->budget--) { s->failed_pc=0x0c011b18u; return 0; }
r[2]=read(ram,0x0c011b74u,4);
goto P_0c011b1a;
P_0c011b1a: /* original 6031, guest PC 0x0c011b1a */
if(!s->budget--) { s->failed_pc=0x0c011b1au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[0]=tmp;
goto P_0c011b1c;
P_0c011b1c: /* original d114, guest PC 0x0c011b1c */
if(!s->budget--) { s->failed_pc=0x0c011b1cu; return 0; }
r[1]=read(ram,0x0c011b70u,4);
goto P_0c011b1e;
P_0c011b1e: /* original 4f26, guest PC 0x0c011b1e */
if(!s->budget--) { s->failed_pc=0x0c011b1eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c011b20;
P_0c011b20: /* original 2029, guest PC 0x0c011b20 */
if(!s->budget--) { s->failed_pc=0x0c011b20u; return 0; }
r[0]&=r[2];
goto P_0c011b22;
P_0c011b22: /* original 6410, guest PC 0x0c011b22 */
if(!s->budget--) { s->failed_pc=0x0c011b22u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[4]=tmp;
goto P_0c011b24;
P_0c011b24: /* original 2301, guest PC 0x0c011b24 */
if(!s->budget--) { s->failed_pc=0x0c011b24u; return 0; }
write(ram,r[3],r[0],2);
goto P_0c011b26;
P_0c011b26: /* original 6043, guest PC 0x0c011b26 */
if(!s->budget--) { s->failed_pc=0x0c011b26u; return 0; }
r[0]=r[4];
goto P_0c011b28;
P_0c011b28: /* original 000b, guest PC 0x0c011b28 */
if(!s->budget--) { s->failed_pc=0x0c011b28u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c011b2a: /* original 6ef6, guest PC 0x0c011b2a */
if(!s->budget--) { s->failed_pc=0x0c011b2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c011b2cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c010684u,0x0c010686u,0x0c010688u,0x0c01068au,0x0c01068cu,0x0c01068eu,0x0c010690u,0x0c010692u,0x0c010694u,0x0c010696u,0x0c010698u,0x0c01069au,0x0c01069cu,0x0c01069eu,0x0c0106a0u,0x0c0106a2u,
0x0c0106a4u,0x0c0106a6u,0x0c0106a8u,0x0c0106aau,0x0c0106acu,0x0c0106aeu,0x0c0106b0u,0x0c0106b2u,0x0c0106b4u,0x0c0106b6u,0x0c0106b8u,0x0c0106bau,0x0c0106bcu,0x0c0106beu,0x0c0106f4u,0x0c0106f6u,
0x0c0106f8u,0x0c0106fau,0x0c0106fcu,0x0c0106feu,0x0c010700u,0x0c010702u,0x0c010704u,0x0c010706u,0x0c010708u,0x0c01070au,0x0c01070cu,0x0c01070eu,0x0c010710u,0x0c010712u,0x0c010714u,0x0c010716u,
0x0c010718u,0x0c01071au,0x0c01071cu,0x0c01071eu,0x0c010720u,0x0c010722u,0x0c010724u,0x0c010726u,0x0c010728u,0x0c01072au,0x0c01072cu,0x0c01072eu,0x0c010730u,0x0c010732u,0x0c010734u,0x0c010736u,
0x0c010738u,0x0c01073au,0x0c01073cu,0x0c01073eu,0x0c010740u,0x0c010742u,0x0c010744u,0x0c010746u,0x0c010748u,0x0c01074au,0x0c01074cu,0x0c01074eu,0x0c010750u,0x0c010752u,0x0c010758u,0x0c01075au,
0x0c01075cu,0x0c01075eu,0x0c010760u,0x0c010762u,0x0c010764u,0x0c010766u,0x0c010768u,0x0c01076au,0x0c01076cu,0x0c01076eu,0x0c010770u,0x0c010772u,0x0c010774u,0x0c010776u,0x0c010778u,0x0c01077au,
0x0c01077cu,0x0c01077eu,0x0c010780u,0x0c010782u,0x0c010784u,0x0c010786u,0x0c010788u,0x0c01078au,0x0c01078cu,0x0c01078eu,0x0c010790u,0x0c010792u,0x0c010794u,0x0c010796u,0x0c010798u,0x0c01079au,
0x0c01079cu,0x0c01079eu,0x0c0107a0u,0x0c0107a2u,0x0c0107a4u,0x0c0107a6u,0x0c0107a8u,0x0c0107aau,0x0c0107acu,0x0c0107aeu,0x0c0107b0u,0x0c0107b2u,0x0c0107b4u,0x0c0107b6u,0x0c0107b8u,0x0c0107bau,
0x0c0107bcu,0x0c0107beu,0x0c0107c0u,0x0c0107c2u,0x0c0107c4u,0x0c0107c6u,0x0c0107c8u,0x0c0107cau,0x0c0107ccu,0x0c0107ceu,0x0c0107d0u,0x0c0107d2u,0x0c0107d4u,0x0c0107d6u,0x0c0107d8u,0x0c0107dau,
0x0c0107dcu,0x0c0107deu,0x0c0107e0u,0x0c0107e2u,0x0c0107e4u,0x0c0107e6u,0x0c0107e8u,0x0c0107eau,0x0c0107ecu,0x0c0107eeu,0x0c0107f0u,0x0c0107f2u,0x0c0107f4u,0x0c0107f6u,0x0c0107f8u,0x0c0107fau,
0x0c0107fcu,0x0c01089au,0x0c01089cu,0x0c01089eu,0x0c0108a0u,0x0c0108a2u,0x0c0108a4u,0x0c0108a6u,0x0c0108a8u,0x0c0108aau,0x0c0108acu,0x0c0108aeu,0x0c0108b0u,0x0c0108b2u,0x0c0108b4u,0x0c0108b6u,
0x0c0108b8u,0x0c0108bau,0x0c0108bcu,0x0c0108beu,0x0c0108c0u,0x0c0108c2u,0x0c0108c4u,0x0c0108c6u,0x0c0108c8u,0x0c0108cau,0x0c0108ccu,0x0c0108ceu,0x0c0108d0u,0x0c0108d2u,0x0c0108d4u,0x0c0108d6u,
0x0c0108d8u,0x0c0108dau,0x0c0108dcu,0x0c0108deu,0x0c0108e0u,0x0c0108e2u,0x0c0108e4u,0x0c0108e6u,0x0c0108e8u,0x0c010954u,0x0c010956u,0x0c010958u,0x0c01095au,0x0c01095cu,0x0c01095eu,0x0c010960u,
0x0c010962u,0x0c010964u,0x0c010966u,0x0c010968u,0x0c01096au,0x0c01096cu,0x0c01096eu,0x0c010970u,0x0c010972u,0x0c010974u,0x0c010976u,0x0c010978u,0x0c01097au,0x0c01097cu,0x0c01097eu,0x0c010980u,
0x0c010982u,0x0c010984u,0x0c010986u,0x0c010988u,0x0c01098au,0x0c01098cu,0x0c01098eu,0x0c010990u,0x0c010992u,0x0c010994u,0x0c010996u,0x0c010998u,0x0c01099au,0x0c01099cu,0x0c01099eu,0x0c0109a0u,
0x0c0109a2u,0x0c0109a4u,0x0c0109a6u,0x0c0109a8u,0x0c0109aau,0x0c0109acu,0x0c0109aeu,0x0c0109b0u,0x0c0109b2u,0x0c0109b4u,0x0c0109b6u,0x0c0109b8u,0x0c0109bau,0x0c0109bcu,0x0c0109beu,0x0c0109c0u,
0x0c0109c2u,0x0c0109c4u,0x0c0109c6u,0x0c0109c8u,0x0c0109cau,0x0c0109ccu,0x0c0109ceu,0x0c0109d0u,0x0c0109d2u,0x0c0109d4u,0x0c0109d6u,0x0c0109d8u,0x0c0109dau,0x0c0109dcu,0x0c0109deu,0x0c0109e0u,
0x0c0109e2u,0x0c0109e4u,0x0c0109e6u,0x0c0109e8u,0x0c0109eau,0x0c0109ecu,0x0c0109eeu,0x0c0109f0u,0x0c0109f2u,0x0c0109f4u,0x0c0110eeu,0x0c0110f0u,0x0c0110f2u,0x0c0110f4u,0x0c0110f6u,0x0c0110f8u,
0x0c0110fau,0x0c0110fcu,0x0c0110feu,0x0c011100u,0x0c011102u,0x0c011104u,0x0c011106u,0x0c011108u,0x0c01110au,0x0c01110cu,0x0c01110eu,0x0c011110u,0x0c011112u,0x0c011114u,0x0c011116u,0x0c011118u,
0x0c01111au,0x0c01111cu,0x0c01111eu,0x0c011120u,0x0c011122u,0x0c011124u,0x0c011126u,0x0c011128u,0x0c01112au,0x0c01112cu,0x0c01112eu,0x0c011130u,0x0c011132u,0x0c011134u,0x0c011136u,0x0c011138u,
0x0c01113au,0x0c01113cu,0x0c01113eu,0x0c011140u,0x0c011142u,0x0c011144u,0x0c011146u,0x0c011148u,0x0c01114au,0x0c01114cu,0x0c01114eu,0x0c011150u,0x0c011152u,0x0c011154u,0x0c011156u,0x0c011158u,
0x0c01115au,0x0c01115cu,0x0c01115eu,0x0c011160u,0x0c011162u,0x0c011164u,0x0c011166u,0x0c011168u,0x0c01116au,0x0c01116cu,0x0c01116eu,0x0c011170u,0x0c011172u,0x0c011174u,0x0c011176u,0x0c011178u,
0x0c01117au,0x0c01117cu,0x0c01117eu,0x0c011180u,0x0c011182u,0x0c011184u,0x0c011186u,0x0c011188u,0x0c01118au,0x0c01118cu,0x0c01118eu,0x0c011190u,0x0c011192u,0x0c011194u,0x0c011196u,0x0c011198u,
0x0c01119au,0x0c01119cu,0x0c01119eu,0x0c0111a0u,0x0c0111a2u,0x0c0111a4u,0x0c0111a6u,0x0c0111a8u,0x0c0111aau,0x0c0111acu,0x0c0111aeu,0x0c0111b0u,0x0c0111b2u,0x0c0111b4u,0x0c0111b6u,0x0c0111b8u,
0x0c0111bau,0x0c0111bcu,0x0c0111beu,0x0c0111c0u,0x0c0119a4u,0x0c0119a6u,0x0c0119e0u,0x0c0119e2u,0x0c0119e4u,0x0c0119e6u,0x0c0119e8u,0x0c0119eau,0x0c0119ecu,0x0c0119eeu,0x0c0119f0u,0x0c0119f2u,
0x0c0119f4u,0x0c0119f6u,0x0c0119f8u,0x0c0119fau,0x0c0119fcu,0x0c0119feu,0x0c011a00u,0x0c011a02u,0x0c011a04u,0x0c011a06u,0x0c011a08u,0x0c011a0au,0x0c011a0cu,0x0c011a0eu,0x0c011a10u,0x0c011a12u,
0x0c011a14u,0x0c011a16u,0x0c011a18u,0x0c011a1au,0x0c011a1cu,0x0c011a1eu,0x0c011a20u,0x0c011a22u,0x0c011a24u,0x0c011a26u,0x0c011a28u,0x0c011a2au,0x0c011a2cu,0x0c011a2eu,0x0c011a30u,0x0c011a32u,
0x0c011a34u,0x0c011a36u,0x0c011a38u,0x0c011a3au,0x0c011a3cu,0x0c011a3eu,0x0c011a40u,0x0c011a42u,0x0c011a44u,0x0c011a46u,0x0c011a48u,0x0c011a4au,0x0c011a4cu,0x0c011a4eu,0x0c011a50u,0x0c011a52u,
0x0c011a54u,0x0c011a56u,0x0c011a58u,0x0c011a5au,0x0c011a5cu,0x0c011a5eu,0x0c011a60u,0x0c011a62u,0x0c011a64u,0x0c011a66u,0x0c011a68u,0x0c011a6au,0x0c011afeu,0x0c011b00u,0x0c011b02u,0x0c011b04u,
0x0c011b06u,0x0c011b08u,0x0c011b0au,0x0c011b0cu,0x0c011b0eu,0x0c011b10u,0x0c011b12u,0x0c011b14u,0x0c011b16u,0x0c011b18u,0x0c011b1au,0x0c011b1cu,0x0c011b1eu,0x0c011b20u,0x0c011b22u,0x0c011b24u,
0x0c011b26u,0x0c011b28u,0x0c011b2au,
};
static const uint32_t claim_pcs[]={
0x0c010684u,0x0c010686u,0x0c010688u,0x0c01068au,0x0c01068cu,0x0c01068eu,0x0c010690u,0x0c010692u,0x0c010694u,0x0c010696u,0x0c010698u,0x0c01069au,0x0c01069cu,0x0c01069eu,0x0c0106a0u,0x0c0106a2u,
0x0c0106a4u,0x0c0106a6u,0x0c0106a8u,0x0c0106aau,0x0c0106acu,0x0c0106aeu,0x0c0106b0u,0x0c0106b2u,0x0c0106b4u,0x0c0106b6u,0x0c0106b8u,0x0c0106bau,0x0c0106bcu,0x0c0106beu,0x0c0106f4u,0x0c0106f6u,
0x0c0106f8u,0x0c0106fau,0x0c0106fcu,0x0c0106feu,0x0c010700u,0x0c010702u,0x0c010704u,0x0c010706u,0x0c010708u,0x0c01070au,0x0c01070cu,0x0c01070eu,0x0c010710u,0x0c010712u,0x0c010714u,0x0c010716u,
0x0c010718u,0x0c01071au,0x0c01071cu,0x0c01071eu,0x0c010720u,0x0c010722u,0x0c010724u,0x0c010726u,0x0c010728u,0x0c01072au,0x0c01072cu,0x0c01072eu,0x0c010730u,0x0c010732u,0x0c010734u,0x0c010736u,
0x0c010738u,0x0c01073au,0x0c01073cu,0x0c01073eu,0x0c010740u,0x0c010742u,0x0c010744u,0x0c010746u,0x0c010748u,0x0c01074au,0x0c01074cu,0x0c01074eu,0x0c010750u,0x0c010752u,0x0c010758u,0x0c01075au,
0x0c01075cu,0x0c01075eu,0x0c010760u,0x0c010762u,0x0c010764u,0x0c010766u,0x0c010768u,0x0c01076au,0x0c01076cu,0x0c01076eu,0x0c010770u,0x0c010772u,0x0c010774u,0x0c010776u,0x0c010778u,0x0c01077au,
0x0c01077cu,0x0c01077eu,0x0c010780u,0x0c010782u,0x0c010784u,0x0c010786u,0x0c010788u,0x0c01078au,0x0c01078cu,0x0c01078eu,0x0c010790u,0x0c010792u,0x0c010794u,0x0c010796u,0x0c010798u,0x0c01079au,
0x0c01079cu,0x0c01079eu,0x0c0107a0u,0x0c0107a2u,0x0c0107a4u,0x0c0107a6u,0x0c0107a8u,0x0c0107aau,0x0c0107acu,0x0c0107aeu,0x0c0107b0u,0x0c0107b2u,0x0c0107b4u,0x0c0107b6u,0x0c0107b8u,0x0c0107bau,
0x0c0107bcu,0x0c0107beu,0x0c0107c0u,0x0c0107c2u,0x0c0107c4u,0x0c0107c6u,0x0c0107c8u,0x0c0107cau,0x0c0107ccu,0x0c0107ceu,0x0c0107d0u,0x0c0107d2u,0x0c0107d4u,0x0c0107d6u,0x0c0107d8u,0x0c0107dau,
0x0c0107dcu,0x0c0107deu,0x0c0107e0u,0x0c0107e2u,0x0c0107e4u,0x0c0107e6u,0x0c0107e8u,0x0c0107eau,0x0c0107ecu,0x0c0107eeu,0x0c0107f0u,0x0c0107f2u,0x0c0107f4u,0x0c0107f6u,0x0c0107f8u,0x0c0107fau,
0x0c0107fcu,0x0c01089au,0x0c01089cu,0x0c01089eu,0x0c0108a0u,0x0c0108a2u,0x0c0108a4u,0x0c0108a6u,0x0c0108a8u,0x0c0108aau,0x0c0108acu,0x0c0108aeu,0x0c0108b0u,0x0c0108b2u,0x0c0108b4u,0x0c0108b6u,
0x0c0108b8u,0x0c0108bau,0x0c0108bcu,0x0c0108beu,0x0c0108c0u,0x0c0108c2u,0x0c0108c4u,0x0c0108c6u,0x0c0108c8u,0x0c0108cau,0x0c0108ccu,0x0c0108ceu,0x0c0108d0u,0x0c0108d2u,0x0c0108d4u,0x0c0108d6u,
0x0c0108d8u,0x0c0108dau,0x0c0108dcu,0x0c0108deu,0x0c0108e0u,0x0c0108e2u,0x0c0108e4u,0x0c0108e6u,0x0c0108e8u,0x0c010954u,0x0c010956u,0x0c010958u,0x0c01095au,0x0c01095cu,0x0c01095eu,0x0c010960u,
0x0c010962u,0x0c010964u,0x0c010966u,0x0c010968u,0x0c01096au,0x0c01096cu,0x0c01096eu,0x0c010970u,0x0c010972u,0x0c010974u,0x0c010976u,0x0c010978u,0x0c01097au,0x0c01097cu,0x0c01097eu,0x0c010980u,
0x0c010982u,0x0c010984u,0x0c010986u,0x0c010988u,0x0c01098au,0x0c01098cu,0x0c01098eu,0x0c010990u,0x0c010992u,0x0c010994u,0x0c010996u,0x0c010998u,0x0c01099au,0x0c01099cu,0x0c01099eu,0x0c0109a0u,
0x0c0109a2u,0x0c0109a4u,0x0c0109a6u,0x0c0109a8u,0x0c0109aau,0x0c0109acu,0x0c0109aeu,0x0c0109b0u,0x0c0109b2u,0x0c0109b4u,0x0c0109b6u,0x0c0109b8u,0x0c0109bau,0x0c0109bcu,0x0c0109beu,0x0c0109c0u,
0x0c0109c2u,0x0c0109c4u,0x0c0109c6u,0x0c0109c8u,0x0c0109cau,0x0c0109ccu,0x0c0109ceu,0x0c0109d0u,0x0c0109d2u,0x0c0109d4u,0x0c0109d6u,0x0c0109d8u,0x0c0109dau,0x0c0109dcu,0x0c0109deu,0x0c0109e0u,
0x0c0109e2u,0x0c0109e4u,0x0c0109e6u,0x0c0109e8u,0x0c0109eau,0x0c0109ecu,0x0c0109eeu,0x0c0109f0u,0x0c0109f2u,0x0c0109f4u,0x0c0110eeu,0x0c0110f0u,0x0c0110f2u,0x0c0110f4u,0x0c0110f6u,0x0c0110f8u,
0x0c0110fau,0x0c0110fcu,0x0c0110feu,0x0c011100u,0x0c011102u,0x0c011104u,0x0c011106u,0x0c011108u,0x0c01110au,0x0c01110cu,0x0c01110eu,0x0c011110u,0x0c011112u,0x0c011114u,0x0c011116u,0x0c011118u,
0x0c01111au,0x0c01111cu,0x0c01111eu,0x0c011120u,0x0c011122u,0x0c011124u,0x0c011126u,0x0c011128u,0x0c01112au,0x0c01112cu,0x0c01112eu,0x0c011130u,0x0c011132u,0x0c011134u,0x0c011136u,0x0c011138u,
0x0c01113au,0x0c01113cu,0x0c01113eu,0x0c011140u,0x0c011142u,0x0c011144u,0x0c011146u,0x0c011148u,0x0c01114au,0x0c01114cu,0x0c01114eu,0x0c011150u,0x0c011152u,0x0c011154u,0x0c011156u,0x0c011158u,
0x0c01115au,0x0c01115cu,0x0c01115eu,0x0c011160u,0x0c011162u,0x0c011164u,0x0c011166u,0x0c011168u,0x0c01116au,0x0c01116cu,0x0c01116eu,0x0c011170u,0x0c011172u,0x0c011174u,0x0c011176u,0x0c011178u,
0x0c01117au,0x0c01117cu,0x0c01117eu,0x0c011180u,0x0c011182u,0x0c011184u,0x0c011186u,0x0c011188u,0x0c01118au,0x0c01118cu,0x0c01118eu,0x0c011190u,0x0c011192u,0x0c011194u,0x0c011196u,0x0c011198u,
0x0c01119au,0x0c01119cu,0x0c01119eu,0x0c0111a0u,0x0c0111a2u,0x0c0111a4u,0x0c0111a6u,0x0c0111a8u,0x0c0111aau,0x0c0111acu,0x0c0111aeu,0x0c0111b0u,0x0c0111b2u,0x0c0111b4u,0x0c0111b6u,0x0c0111b8u,
0x0c0111bau,0x0c0111bcu,0x0c0111beu,0x0c0111c0u,0x0c0119a4u,0x0c0119a6u,0x0c0119e0u,0x0c0119e2u,0x0c0119e4u,0x0c0119e6u,0x0c0119e8u,0x0c0119eau,0x0c0119ecu,0x0c0119eeu,0x0c0119f0u,0x0c0119f2u,
0x0c0119f4u,0x0c0119f6u,0x0c0119f8u,0x0c0119fau,0x0c0119fcu,0x0c0119feu,0x0c011a00u,0x0c011a02u,0x0c011a04u,0x0c011a06u,0x0c011a08u,0x0c011a0au,0x0c011a0cu,0x0c011a0eu,0x0c011a10u,0x0c011a12u,
0x0c011a14u,0x0c011a16u,0x0c011a18u,0x0c011a1au,0x0c011a1cu,0x0c011a1eu,0x0c011a20u,0x0c011a22u,0x0c011a24u,0x0c011a26u,0x0c011a28u,0x0c011a2au,0x0c011a2cu,0x0c011a2eu,0x0c011a30u,0x0c011a32u,
0x0c011a34u,0x0c011a36u,0x0c011a38u,0x0c011a3au,0x0c011a3cu,0x0c011a3eu,0x0c011a40u,0x0c011a42u,0x0c011a44u,0x0c011a46u,0x0c011a48u,0x0c011a4au,0x0c011a4cu,0x0c011a4eu,0x0c011a50u,0x0c011a52u,
0x0c011a54u,0x0c011a56u,0x0c011a58u,0x0c011a5au,0x0c011a5cu,0x0c011a5eu,0x0c011a60u,0x0c011a62u,0x0c011a64u,0x0c011a66u,0x0c011a68u,0x0c011a6au,0x0c011afeu,0x0c011b00u,0x0c011b02u,0x0c011b04u,
0x0c011b06u,0x0c011b08u,0x0c011b0au,0x0c011b0cu,0x0c011b0eu,0x0c011b10u,0x0c011b12u,0x0c011b14u,0x0c011b16u,0x0c011b18u,0x0c011b1au,0x0c011b1cu,0x0c011b1eu,0x0c011b20u,0x0c011b22u,0x0c011b24u,
0x0c011b26u,0x0c011b28u,0x0c011b2au,
};
int vf3_c99_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(claim_pcs)/sizeof(claim_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(claim_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(claim_pcs)/sizeof(claim_pcs[0]) && claim_pcs[lo]==pc;
}
