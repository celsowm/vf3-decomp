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
int vf3_away_batch71_adapter_49(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c76c0u: goto P_0c0c76c0;
case 0x0c0c76c2u: goto P_0c0c76c2;
case 0x0c0c76c4u: goto P_0c0c76c4;
case 0x0c0c76c6u: goto P_0c0c76c6;
case 0x0c0c76c8u: goto P_0c0c76c8;
case 0x0c0c76cau: goto P_0c0c76ca;
case 0x0c0c76ccu: goto P_0c0c76cc;
case 0x0c0c76ceu: goto P_0c0c76ce;
case 0x0c0c76d0u: goto P_0c0c76d0;
case 0x0c0c76d2u: goto P_0c0c76d2;
case 0x0c0c76d4u: goto P_0c0c76d4;
case 0x0c0c76d6u: goto P_0c0c76d6;
case 0x0c0c76d8u: goto P_0c0c76d8;
case 0x0c0c76dau: goto P_0c0c76da;
case 0x0c0c76dcu: goto P_0c0c76dc;
case 0x0c0c76deu: goto P_0c0c76de;
case 0x0c0c76e0u: goto P_0c0c76e0;
case 0x0c0c76e2u: goto P_0c0c76e2;
case 0x0c0c76e4u: goto P_0c0c76e4;
case 0x0c0c76e6u: goto P_0c0c76e6;
case 0x0c0c76e8u: goto P_0c0c76e8;
case 0x0c0c76eau: goto P_0c0c76ea;
case 0x0c0c76ecu: goto P_0c0c76ec;
case 0x0c0c76eeu: goto P_0c0c76ee;
case 0x0c0c76f0u: goto P_0c0c76f0;
case 0x0c0c76f2u: goto P_0c0c76f2;
case 0x0c0c76f4u: goto P_0c0c76f4;
case 0x0c0c76f6u: goto P_0c0c76f6;
case 0x0c0c76f8u: goto P_0c0c76f8;
case 0x0c0c76fau: goto P_0c0c76fa;
case 0x0c0c76fcu: goto P_0c0c76fc;
case 0x0c0c76feu: goto P_0c0c76fe;
case 0x0c0c7700u: goto P_0c0c7700;
case 0x0c0c7702u: goto P_0c0c7702;
case 0x0c0c7704u: goto P_0c0c7704;
case 0x0c0c7706u: goto P_0c0c7706;
case 0x0c0c7708u: goto P_0c0c7708;
case 0x0c0c770au: goto P_0c0c770a;
case 0x0c0c770cu: goto P_0c0c770c;
case 0x0c0c770eu: goto P_0c0c770e;
case 0x0c0c7710u: goto P_0c0c7710;
case 0x0c0c7712u: goto P_0c0c7712;
case 0x0c0c7714u: goto P_0c0c7714;
case 0x0c0c7716u: goto P_0c0c7716;
case 0x0c0c7718u: goto P_0c0c7718;
case 0x0c0c771au: goto P_0c0c771a;
case 0x0c0c771cu: goto P_0c0c771c;
case 0x0c0c771eu: goto P_0c0c771e;
case 0x0c0c7720u: goto P_0c0c7720;
case 0x0c0c7722u: goto P_0c0c7722;
case 0x0c0c7724u: goto P_0c0c7724;
case 0x0c0c7726u: goto P_0c0c7726;
case 0x0c0c7728u: goto P_0c0c7728;
case 0x0c0c772au: goto P_0c0c772a;
case 0x0c0c772cu: goto P_0c0c772c;
case 0x0c0c772eu: goto P_0c0c772e;
case 0x0c0c7730u: goto P_0c0c7730;
case 0x0c0c7732u: goto P_0c0c7732;
case 0x0c0c7734u: goto P_0c0c7734;
case 0x0c0c7736u: goto P_0c0c7736;
case 0x0c0c7738u: goto P_0c0c7738;
case 0x0c0c773au: goto P_0c0c773a;
case 0x0c0c773cu: goto P_0c0c773c;
case 0x0c0c773eu: goto P_0c0c773e;
case 0x0c0c7740u: goto P_0c0c7740;
case 0x0c0c7742u: goto P_0c0c7742;
case 0x0c0c7744u: goto P_0c0c7744;
case 0x0c0c7746u: goto P_0c0c7746;
case 0x0c0c7778u: goto P_0c0c7778;
case 0x0c0c777au: goto P_0c0c777a;
case 0x0c0c777cu: goto P_0c0c777c;
case 0x0c0c777eu: goto P_0c0c777e;
case 0x0c0c7780u: goto P_0c0c7780;
case 0x0c0c7782u: goto P_0c0c7782;
case 0x0c0c7784u: goto P_0c0c7784;
case 0x0c0c7786u: goto P_0c0c7786;
case 0x0c0c7788u: goto P_0c0c7788;
case 0x0c0c778au: goto P_0c0c778a;
case 0x0c0c778cu: goto P_0c0c778c;
case 0x0c0c778eu: goto P_0c0c778e;
case 0x0c0c7790u: goto P_0c0c7790;
case 0x0c0c7792u: goto P_0c0c7792;
case 0x0c0c7794u: goto P_0c0c7794;
case 0x0c0c7796u: goto P_0c0c7796;
case 0x0c0c7798u: goto P_0c0c7798;
case 0x0c0c779au: goto P_0c0c779a;
case 0x0c0c779cu: goto P_0c0c779c;
case 0x0c0c779eu: goto P_0c0c779e;
case 0x0c0c77a0u: goto P_0c0c77a0;
case 0x0c0c77a2u: goto P_0c0c77a2;
case 0x0c0c77a4u: goto P_0c0c77a4;
case 0x0c0c77a6u: goto P_0c0c77a6;
case 0x0c0c77a8u: goto P_0c0c77a8;
case 0x0c0c77aau: goto P_0c0c77aa;
case 0x0c0c77acu: goto P_0c0c77ac;
case 0x0c0c77aeu: goto P_0c0c77ae;
case 0x0c0c77b0u: goto P_0c0c77b0;
case 0x0c0c77b2u: goto P_0c0c77b2;
case 0x0c0c77b4u: goto P_0c0c77b4;
case 0x0c0c77b6u: goto P_0c0c77b6;
case 0x0c0c77b8u: goto P_0c0c77b8;
case 0x0c0c77bau: goto P_0c0c77ba;
case 0x0c0c77bcu: goto P_0c0c77bc;
case 0x0c0c77beu: goto P_0c0c77be;
case 0x0c0c77c0u: goto P_0c0c77c0;
case 0x0c0c77c2u: goto P_0c0c77c2;
case 0x0c0c77c4u: goto P_0c0c77c4;
case 0x0c0c77c6u: goto P_0c0c77c6;
case 0x0c0c77c8u: goto P_0c0c77c8;
case 0x0c0c77cau: goto P_0c0c77ca;
case 0x0c0c77ccu: goto P_0c0c77cc;
case 0x0c0c77ceu: goto P_0c0c77ce;
case 0x0c0c77d0u: goto P_0c0c77d0;
case 0x0c0c77d2u: goto P_0c0c77d2;
case 0x0c0c77d4u: goto P_0c0c77d4;
case 0x0c0c77d6u: goto P_0c0c77d6;
case 0x0c0c77d8u: goto P_0c0c77d8;
case 0x0c0c77dau: goto P_0c0c77da;
case 0x0c0c77dcu: goto P_0c0c77dc;
case 0x0c0c77deu: goto P_0c0c77de;
case 0x0c0c77e0u: goto P_0c0c77e0;
case 0x0c0c77e2u: goto P_0c0c77e2;
case 0x0c0c77e4u: goto P_0c0c77e4;
case 0x0c0c77e6u: goto P_0c0c77e6;
case 0x0c0c77e8u: goto P_0c0c77e8;
case 0x0c0c77eau: goto P_0c0c77ea;
case 0x0c0c77ecu: goto P_0c0c77ec;
case 0x0c0c77eeu: goto P_0c0c77ee;
case 0x0c0c77f0u: goto P_0c0c77f0;
case 0x0c0c77f2u: goto P_0c0c77f2;
case 0x0c0c77f4u: goto P_0c0c77f4;
case 0x0c0c77f6u: goto P_0c0c77f6;
case 0x0c0c77f8u: goto P_0c0c77f8;
case 0x0c0c77fau: goto P_0c0c77fa;
case 0x0c0c77fcu: goto P_0c0c77fc;
case 0x0c0c77feu: goto P_0c0c77fe;
case 0x0c0c7800u: goto P_0c0c7800;
case 0x0c0c7802u: goto P_0c0c7802;
case 0x0c0c7804u: goto P_0c0c7804;
case 0x0c0c7806u: goto P_0c0c7806;
case 0x0c0c7808u: goto P_0c0c7808;
case 0x0c0c780au: goto P_0c0c780a;
case 0x0c0c780cu: goto P_0c0c780c;
case 0x0c0c780eu: goto P_0c0c780e;
case 0x0c0c7810u: goto P_0c0c7810;
case 0x0c0c7812u: goto P_0c0c7812;
case 0x0c0c7814u: goto P_0c0c7814;
case 0x0c0c7816u: goto P_0c0c7816;
case 0x0c0c7818u: goto P_0c0c7818;
case 0x0c0c781au: goto P_0c0c781a;
case 0x0c0c781cu: goto P_0c0c781c;
case 0x0c0c781eu: goto P_0c0c781e;
case 0x0c0c7820u: goto P_0c0c7820;
case 0x0c0c7822u: goto P_0c0c7822;
case 0x0c0c7824u: goto P_0c0c7824;
case 0x0c0c7826u: goto P_0c0c7826;
case 0x0c0c7828u: goto P_0c0c7828;
case 0x0c0c782au: goto P_0c0c782a;
case 0x0c0c782cu: goto P_0c0c782c;
case 0x0c0c782eu: goto P_0c0c782e;
case 0x0c0c7830u: goto P_0c0c7830;
case 0x0c0c7832u: goto P_0c0c7832;
case 0x0c0c7834u: goto P_0c0c7834;
case 0x0c0c7836u: goto P_0c0c7836;
case 0x0c0c7838u: goto P_0c0c7838;
case 0x0c0c783au: goto P_0c0c783a;
case 0x0c0c783cu: goto P_0c0c783c;
case 0x0c0c783eu: goto P_0c0c783e;
case 0x0c0c7840u: goto P_0c0c7840;
case 0x0c0c7842u: goto P_0c0c7842;
case 0x0c0c7844u: goto P_0c0c7844;
case 0x0c0c7846u: goto P_0c0c7846;
case 0x0c0c7848u: goto P_0c0c7848;
case 0x0c0c784au: goto P_0c0c784a;
case 0x0c0c784cu: goto P_0c0c784c;
case 0x0c0c784eu: goto P_0c0c784e;
case 0x0c0c7850u: goto P_0c0c7850;
case 0x0c0c7852u: goto P_0c0c7852;
case 0x0c0c7854u: goto P_0c0c7854;
case 0x0c0c7856u: goto P_0c0c7856;
case 0x0c0c7858u: goto P_0c0c7858;
case 0x0c0c785au: goto P_0c0c785a;
case 0x0c0c785cu: goto P_0c0c785c;
case 0x0c0c7c50u: goto P_0c0c7c50;
case 0x0c0c7c52u: goto P_0c0c7c52;
case 0x0c0c7c54u: goto P_0c0c7c54;
case 0x0c0c7c56u: goto P_0c0c7c56;
case 0x0c0c7c58u: goto P_0c0c7c58;
case 0x0c0c7c5au: goto P_0c0c7c5a;
case 0x0c0c7c5cu: goto P_0c0c7c5c;
case 0x0c0c7c5eu: goto P_0c0c7c5e;
case 0x0c0c7c60u: goto P_0c0c7c60;
case 0x0c0c7c62u: goto P_0c0c7c62;
case 0x0c0c7c64u: goto P_0c0c7c64;
case 0x0c0c7c66u: goto P_0c0c7c66;
case 0x0c0c7c68u: goto P_0c0c7c68;
case 0x0c0c7c6au: goto P_0c0c7c6a;
case 0x0c0c7c6cu: goto P_0c0c7c6c;
case 0x0c0c7c6eu: goto P_0c0c7c6e;
case 0x0c0c7c70u: goto P_0c0c7c70;
case 0x0c0c7c72u: goto P_0c0c7c72;
case 0x0c0c7c74u: goto P_0c0c7c74;
case 0x0c0c7c76u: goto P_0c0c7c76;
case 0x0c0c7c78u: goto P_0c0c7c78;
case 0x0c0c7c7au: goto P_0c0c7c7a;
case 0x0c0c7c7cu: goto P_0c0c7c7c;
case 0x0c0c7c7eu: goto P_0c0c7c7e;
case 0x0c0c7c80u: goto P_0c0c7c80;
case 0x0c0c7c82u: goto P_0c0c7c82;
case 0x0c0c7c84u: goto P_0c0c7c84;
case 0x0c0c7c86u: goto P_0c0c7c86;
case 0x0c0c7c88u: goto P_0c0c7c88;
case 0x0c0c7c8au: goto P_0c0c7c8a;
case 0x0c0c7c8cu: goto P_0c0c7c8c;
case 0x0c0c7c8eu: goto P_0c0c7c8e;
case 0x0c0c7c90u: goto P_0c0c7c90;
case 0x0c0c7c92u: goto P_0c0c7c92;
case 0x0c0c7c94u: goto P_0c0c7c94;
case 0x0c0c7c96u: goto P_0c0c7c96;
case 0x0c0c7c98u: goto P_0c0c7c98;
case 0x0c0c7c9au: goto P_0c0c7c9a;
case 0x0c0c7c9cu: goto P_0c0c7c9c;
case 0x0c0c7c9eu: goto P_0c0c7c9e;
case 0x0c0c7ca0u: goto P_0c0c7ca0;
case 0x0c0c7ca2u: goto P_0c0c7ca2;
case 0x0c0c7ca4u: goto P_0c0c7ca4;
case 0x0c0c7ca6u: goto P_0c0c7ca6;
case 0x0c0c7ca8u: goto P_0c0c7ca8;
case 0x0c0c7caau: goto P_0c0c7caa;
case 0x0c0c7cacu: goto P_0c0c7cac;
case 0x0c0c7caeu: goto P_0c0c7cae;
case 0x0c0c7cb0u: goto P_0c0c7cb0;
case 0x0c0c7cb2u: goto P_0c0c7cb2;
case 0x0c0c7cb4u: goto P_0c0c7cb4;
case 0x0c0c7cb6u: goto P_0c0c7cb6;
case 0x0c0c7cb8u: goto P_0c0c7cb8;
case 0x0c0c7cbau: goto P_0c0c7cba;
case 0x0c0c7cbcu: goto P_0c0c7cbc;
case 0x0c0c7cbeu: goto P_0c0c7cbe;
case 0x0c0c7cc0u: goto P_0c0c7cc0;
case 0x0c0c7cc2u: goto P_0c0c7cc2;
case 0x0c0c7cc4u: goto P_0c0c7cc4;
case 0x0c0c7cc6u: goto P_0c0c7cc6;
case 0x0c0c7cc8u: goto P_0c0c7cc8;
case 0x0c0c7ccau: goto P_0c0c7cca;
case 0x0c0c7cccu: goto P_0c0c7ccc;
case 0x0c0c7cceu: goto P_0c0c7cce;
case 0x0c0c7cd0u: goto P_0c0c7cd0;
case 0x0c0c7cd2u: goto P_0c0c7cd2;
case 0x0c0c7cd4u: goto P_0c0c7cd4;
case 0x0c0c7cd6u: goto P_0c0c7cd6;
case 0x0c0c7cd8u: goto P_0c0c7cd8;
case 0x0c0c7cdau: goto P_0c0c7cda;
case 0x0c0c7cdcu: goto P_0c0c7cdc;
case 0x0c0c7cdeu: goto P_0c0c7cde;
case 0x0c0c7ce0u: goto P_0c0c7ce0;
case 0x0c0c7ce2u: goto P_0c0c7ce2;
case 0x0c0c7ce4u: goto P_0c0c7ce4;
case 0x0c0c7ce6u: goto P_0c0c7ce6;
case 0x0c0c7ce8u: goto P_0c0c7ce8;
case 0x0c0c7ceau: goto P_0c0c7cea;
case 0x0c0c7cecu: goto P_0c0c7cec;
case 0x0c0c7ceeu: goto P_0c0c7cee;
case 0x0c0c7cf0u: goto P_0c0c7cf0;
case 0x0c0c7cf2u: goto P_0c0c7cf2;
case 0x0c0c7cf4u: goto P_0c0c7cf4;
case 0x0c0c7cf6u: goto P_0c0c7cf6;
case 0x0c0c7cf8u: goto P_0c0c7cf8;
case 0x0c0c7cfau: goto P_0c0c7cfa;
case 0x0c0c7cfcu: goto P_0c0c7cfc;
case 0x0c0c7cfeu: goto P_0c0c7cfe;
case 0x0c0c7d00u: goto P_0c0c7d00;
case 0x0c0c7d02u: goto P_0c0c7d02;
case 0x0c0c7d04u: goto P_0c0c7d04;
case 0x0c0c7d06u: goto P_0c0c7d06;
case 0x0c0c7d08u: goto P_0c0c7d08;
case 0x0c0c7d0au: goto P_0c0c7d0a;
case 0x0c0c7d0cu: goto P_0c0c7d0c;
case 0x0c0c7d0eu: goto P_0c0c7d0e;
case 0x0c0c7d10u: goto P_0c0c7d10;
case 0x0c0c7d12u: goto P_0c0c7d12;
case 0x0c0c7d14u: goto P_0c0c7d14;
case 0x0c0c7d16u: goto P_0c0c7d16;
case 0x0c0c7d18u: goto P_0c0c7d18;
case 0x0c0c7d1au: goto P_0c0c7d1a;
case 0x0c0c7d1cu: goto P_0c0c7d1c;
case 0x0c0c7d1eu: goto P_0c0c7d1e;
case 0x0c0c7d20u: goto P_0c0c7d20;
case 0x0c0c7d22u: goto P_0c0c7d22;
case 0x0c0c7d24u: goto P_0c0c7d24;
case 0x0c0c7d26u: goto P_0c0c7d26;
case 0x0c0c7d28u: goto P_0c0c7d28;
case 0x0c0c7d2au: goto P_0c0c7d2a;
case 0x0c0c7d2cu: goto P_0c0c7d2c;
case 0x0c0c7d2eu: goto P_0c0c7d2e;
case 0x0c0c7d30u: goto P_0c0c7d30;
case 0x0c0c7d32u: goto P_0c0c7d32;
case 0x0c0c7d34u: goto P_0c0c7d34;
case 0x0c0c7d36u: goto P_0c0c7d36;
case 0x0c0c7d38u: goto P_0c0c7d38;
case 0x0c0c7d3au: goto P_0c0c7d3a;
case 0x0c0c7d3cu: goto P_0c0c7d3c;
case 0x0c0c7d3eu: goto P_0c0c7d3e;
case 0x0c0c7d40u: goto P_0c0c7d40;
case 0x0c0c7d42u: goto P_0c0c7d42;
case 0x0c0c7d44u: goto P_0c0c7d44;
case 0x0c0c7d46u: goto P_0c0c7d46;
case 0x0c0c7d48u: goto P_0c0c7d48;
case 0x0c0c7d4au: goto P_0c0c7d4a;
case 0x0c0c7d4cu: goto P_0c0c7d4c;
case 0x0c0c7d4eu: goto P_0c0c7d4e;
case 0x0c0c7d50u: goto P_0c0c7d50;
case 0x0c0c7d52u: goto P_0c0c7d52;
case 0x0c0c7d54u: goto P_0c0c7d54;
case 0x0c0c7d56u: goto P_0c0c7d56;
case 0x0c0c7d58u: goto P_0c0c7d58;
case 0x0c0c7d5au: goto P_0c0c7d5a;
case 0x0c0c7d5cu: goto P_0c0c7d5c;
case 0x0c0c7d5eu: goto P_0c0c7d5e;
case 0x0c0c7d60u: goto P_0c0c7d60;
case 0x0c0c7d62u: goto P_0c0c7d62;
case 0x0c0c7d64u: goto P_0c0c7d64;
case 0x0c0c7d66u: goto P_0c0c7d66;
case 0x0c0c7d68u: goto P_0c0c7d68;
case 0x0c0c7d6au: goto P_0c0c7d6a;
case 0x0c0c7d6cu: goto P_0c0c7d6c;
case 0x0c0c7d6eu: goto P_0c0c7d6e;
case 0x0c0c7d70u: goto P_0c0c7d70;
case 0x0c0c7d72u: goto P_0c0c7d72;
case 0x0c0c7d74u: goto P_0c0c7d74;
case 0x0c0c7d76u: goto P_0c0c7d76;
case 0x0c0c7d78u: goto P_0c0c7d78;
case 0x0c0c7de0u: goto P_0c0c7de0;
case 0x0c0c7de2u: goto P_0c0c7de2;
case 0x0c0c7de4u: goto P_0c0c7de4;
case 0x0c0c7de6u: goto P_0c0c7de6;
case 0x0c0c7de8u: goto P_0c0c7de8;
case 0x0c0c7deau: goto P_0c0c7dea;
case 0x0c0c7decu: goto P_0c0c7dec;
case 0x0c0c7deeu: goto P_0c0c7dee;
case 0x0c0c7df0u: goto P_0c0c7df0;
case 0x0c0c7df2u: goto P_0c0c7df2;
case 0x0c0c7df4u: goto P_0c0c7df4;
case 0x0c0c7df6u: goto P_0c0c7df6;
case 0x0c0c7df8u: goto P_0c0c7df8;
case 0x0c0c7dfau: goto P_0c0c7dfa;
case 0x0c0c7dfcu: goto P_0c0c7dfc;
case 0x0c0c7dfeu: goto P_0c0c7dfe;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c76c0: /* original 2fe6, guest PC 0x0c0c76c0 */
if(!s->budget--) { s->failed_pc=0x0c0c76c0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c76c2;
P_0c0c76c2: /* original e01c, guest PC 0x0c0c76c2 */
if(!s->budget--) { s->failed_pc=0x0c0c76c2u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c76c4;
P_0c0c76c4: /* original 2fd6, guest PC 0x0c0c76c4 */
if(!s->budget--) { s->failed_pc=0x0c0c76c4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c76c6;
P_0c0c76c6: /* original 2fc6, guest PC 0x0c0c76c6 */
if(!s->budget--) { s->failed_pc=0x0c0c76c6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c76c8;
P_0c0c76c8: /* original ec0f, guest PC 0x0c0c76c8 */
if(!s->budget--) { s->failed_pc=0x0c0c76c8u; return 0; }
r[12]=0x0000000fu;
goto P_0c0c76ca;
P_0c0c76ca: /* original 2fb6, guest PC 0x0c0c76ca */
if(!s->budget--) { s->failed_pc=0x0c0c76cau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c76cc;
P_0c0c76cc: /* original 2fa6, guest PC 0x0c0c76cc */
if(!s->budget--) { s->failed_pc=0x0c0c76ccu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c76ce;
P_0c0c76ce: /* original 2f96, guest PC 0x0c0c76ce */
if(!s->budget--) { s->failed_pc=0x0c0c76ceu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c76d0;
P_0c0c76d0: /* original 2f86, guest PC 0x0c0c76d0 */
if(!s->budget--) { s->failed_pc=0x0c0c76d0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c76d2;
P_0c0c76d2: /* original de21, guest PC 0x0c0c76d2 */
if(!s->budget--) { s->failed_pc=0x0c0c76d2u; return 0; }
r[14]=read(ram,0x0c0c7758u,4);
goto P_0c0c76d4;
P_0c0c76d4: /* original 4f22, guest PC 0x0c0c76d4 */
if(!s->budget--) { s->failed_pc=0x0c0c76d4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c76d6;
P_0c0c76d6: /* original 09ec, guest PC 0x0c0c76d6 */
if(!s->budget--) { s->failed_pc=0x0c0c76d6u; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c76d8;
P_0c0c76d8: /* original d024, guest PC 0x0c0c76d8 */
if(!s->budget--) { s->failed_pc=0x0c0c76d8u; return 0; }
r[0]=read(ram,0x0c0c776cu,4);
goto P_0c0c76da;
P_0c0c76da: /* original 699c, guest PC 0x0c0c76da */
if(!s->budget--) { s->failed_pc=0x0c0c76dau; return 0; }
r[9]=r[9]&255u;
goto P_0c0c76dc;
P_0c0c76dc: /* original d322, guest PC 0x0c0c76dc */
if(!s->budget--) { s->failed_pc=0x0c0c76dcu; return 0; }
r[3]=read(ram,0x0c0c7768u,4);
goto P_0c0c76de;
P_0c0c76de: /* original 2c99, guest PC 0x0c0c76de */
if(!s->budget--) { s->failed_pc=0x0c0c76deu; return 0; }
r[12]&=r[9];
goto P_0c0c76e0;
P_0c0c76e0: /* original db20, guest PC 0x0c0c76e0 */
if(!s->budget--) { s->failed_pc=0x0c0c76e0u; return 0; }
r[11]=read(ram,0x0c0c7764u,4);
goto P_0c0c76e2;
P_0c0c76e2: /* original 4c08, guest PC 0x0c0c76e2 */
if(!s->budget--) { s->failed_pc=0x0c0c76e2u; return 0; }
r[12]<<=2;
goto P_0c0c76e4;
P_0c0c76e4: /* original 4c00, guest PC 0x0c0c76e4 */
if(!s->budget--) { s->failed_pc=0x0c0c76e4u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c0c76e6;
P_0c0c76e6: /* original 00ce, guest PC 0x0c0c76e6 */
if(!s->budget--) { s->failed_pc=0x0c0c76e6u; return 0; }
r[0]=read(ram,r[12]+r[0],4);
goto P_0c0c76e8;
P_0c0c76e8: /* original 7ffc, guest PC 0x0c0c76e8 */
if(!s->budget--) { s->failed_pc=0x0c0c76e8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c76ea;
P_0c0c76ea: /* original 88ff, guest PC 0x0c0c76ea */
if(!s->budget--) { s->failed_pc=0x0c0c76eau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c76ec;
P_0c0c76ec: /* original 8d44, guest PC 0x0c0c76ec */
if(!s->budget--) { s->failed_pc=0x0c0c76ecu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(cond) { goto P_0c0c7778; }
goto P_0c0c76f0;
P_0c0c76ee: /* original 6432, guest PC 0x0c0c76ee */
if(!s->budget--) { s->failed_pc=0x0c0c76eeu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0c76f0;
P_0c0c76f0: /* original 902e, guest PC 0x0c0c76f0 */
if(!s->budget--) { s->failed_pc=0x0c0c76f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7750u,2);
goto P_0c0c76f2;
P_0c0c76f2: /* original 0e46, guest PC 0x0c0c76f2 */
if(!s->budget--) { s->failed_pc=0x0c0c76f2u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c76f4;
P_0c0c76f4: /* original d51d, guest PC 0x0c0c76f4 */
if(!s->budget--) { s->failed_pc=0x0c0c76f4u; return 0; }
r[5]=read(ram,0x0c0c776cu,4);
goto P_0c0c76f6;
P_0c0c76f6: /* original d21e, guest PC 0x0c0c76f6 */
if(!s->budget--) { s->failed_pc=0x0c0c76f6u; return 0; }
r[2]=read(ram,0x0c0c7770u,4);
goto P_0c0c76f8;
P_0c0c76f8: /* original 35cc, guest PC 0x0c0c76f8 */
if(!s->budget--) { s->failed_pc=0x0c0c76f8u; return 0; }
r[5]+=r[12];
goto P_0c0c76fa;
P_0c0c76fa: /* original 0aee, guest PC 0x0c0c76fa */
if(!s->budget--) { s->failed_pc=0x0c0c76fau; return 0; }
r[10]=read(ram,r[14]+r[0],4);
goto P_0c0c76fc;
P_0c0c76fc: /* original 6721, guest PC 0x0c0c76fc */
if(!s->budget--) { s->failed_pc=0x0c0c76fcu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[7]=tmp;
goto P_0c0c76fe;
P_0c0c76fe: /* original 2f52, guest PC 0x0c0c76fe */
if(!s->budget--) { s->failed_pc=0x0c0c76feu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c7700;
P_0c0c7700: /* original 66a3, guest PC 0x0c0c7700 */
if(!s->budget--) { s->failed_pc=0x0c0c7700u; return 0; }
r[6]=r[10];
goto P_0c0c7702;
P_0c0c7702: /* original 64f2, guest PC 0x0c0c7702 */
if(!s->budget--) { s->failed_pc=0x0c0c7702u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c7704;
P_0c0c7704: /* original 5551, guest PC 0x0c0c7704 */
if(!s->budget--) { s->failed_pc=0x0c0c7704u; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c0c7706;
P_0c0c7706: /* original d31b, guest PC 0x0c0c7706 */
if(!s->budget--) { s->failed_pc=0x0c0c7706u; return 0; }
r[3]=read(ram,0x0c0c7774u,4);
goto P_0c0c7708;
P_0c0c7708: /* original 430b, guest PC 0x0c0c7708 */
if(!s->budget--) { s->failed_pc=0x0c0c7708u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c770cu;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c770cu) { target=s->pc; goto dispatch; }
goto P_0c0c770c;
P_0c0c770a: /* original 6442, guest PC 0x0c0c770a */
if(!s->budget--) { s->failed_pc=0x0c0c770au; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c770c;
P_0c0c770c: /* original 52a4, guest PC 0x0c0c770c */
if(!s->budget--) { s->failed_pc=0x0c0c770cu; return 0; }
r[2]=read(ram,r[10]+16,4);
goto P_0c0c770e;
P_0c0c770e: /* original 2f22, guest PC 0x0c0c770e */
if(!s->budget--) { s->failed_pc=0x0c0c770eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c7710;
P_0c0c7710: /* original 981c, guest PC 0x0c0c7710 */
if(!s->budget--) { s->failed_pc=0x0c0c7710u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774cu,2);
goto P_0c0c7712;
P_0c0c7712: /* original a008, guest PC 0x0c0c7712 */
if(!s->budget--) { s->failed_pc=0x0c0c7712u; return 0; }
r[13]=0x00000000u;
goto P_0c0c7726;
P_0c0c7714: /* original ed00, guest PC 0x0c0c7714 */
if(!s->budget--) { s->failed_pc=0x0c0c7714u; return 0; }
r[13]=0x00000000u;
goto P_0c0c7716;
P_0c0c7716: /* original 60f2, guest PC 0x0c0c7716 */
if(!s->budget--) { s->failed_pc=0x0c0c7716u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0c7718;
P_0c0c7718: /* original 65d3, guest PC 0x0c0c7718 */
if(!s->budget--) { s->failed_pc=0x0c0c7718u; return 0; }
r[5]=r[13];
goto P_0c0c771a;
P_0c0c771a: /* original 4508, guest PC 0x0c0c771a */
if(!s->budget--) { s->failed_pc=0x0c0c771au; return 0; }
r[5]<<=2;
goto P_0c0c771c;
P_0c0c771c: /* original 6483, guest PC 0x0c0c771c */
if(!s->budget--) { s->failed_pc=0x0c0c771cu; return 0; }
r[4]=r[8];
goto P_0c0c771e;
P_0c0c771e: /* original 055e, guest PC 0x0c0c771e */
if(!s->budget--) { s->failed_pc=0x0c0c771eu; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c0c7720;
P_0c0c7720: /* original 4b0b, guest PC 0x0c0c7720 */
if(!s->budget--) { s->failed_pc=0x0c0c7720u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c7724u;
r[8]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7724u) { target=s->pc; goto dispatch; }
goto P_0c0c7724;
P_0c0c7722: /* original 7801, guest PC 0x0c0c7722 */
if(!s->budget--) { s->failed_pc=0x0c0c7722u; return 0; }
r[8]+=0x00000001u;
goto P_0c0c7724;
P_0c0c7724: /* original 7d01, guest PC 0x0c0c7724 */
if(!s->budget--) { s->failed_pc=0x0c0c7724u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c7726;
P_0c0c7726: /* original 85a6, guest PC 0x0c0c7726 */
if(!s->budget--) { s->failed_pc=0x0c0c7726u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+12,2);
goto P_0c0c7728;
P_0c0c7728: /* original 600d, guest PC 0x0c0c7728 */
if(!s->budget--) { s->failed_pc=0x0c0c7728u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c772a;
P_0c0c772a: /* original 3d03, guest PC 0x0c0c772a */
if(!s->budget--) { s->failed_pc=0x0c0c772au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[0])!=0);
goto P_0c0c772c;
P_0c0c772c: /* original 8bf3, guest PC 0x0c0c772c */
if(!s->budget--) { s->failed_pc=0x0c0c772cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7716; }
goto P_0c0c772e;
P_0c0c772e: /* original 900f, guest PC 0x0c0c772e */
if(!s->budget--) { s->failed_pc=0x0c0c772eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7750u,2);
goto P_0c0c7730;
P_0c0c7730: /* original 53a6, guest PC 0x0c0c7730 */
if(!s->budget--) { s->failed_pc=0x0c0c7730u; return 0; }
r[3]=read(ram,r[10]+24,4);
goto P_0c0c7732;
P_0c0c7732: /* original 02ee, guest PC 0x0c0c7732 */
if(!s->budget--) { s->failed_pc=0x0c0c7732u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0c7734;
P_0c0c7734: /* original 7004, guest PC 0x0c0c7734 */
if(!s->budget--) { s->failed_pc=0x0c0c7734u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c7736;
P_0c0c7736: /* original 910c, guest PC 0x0c0c7736 */
if(!s->budget--) { s->failed_pc=0x0c0c7736u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7752u,2);
goto P_0c0c7738;
P_0c0c7738: /* original 323c, guest PC 0x0c0c7738 */
if(!s->budget--) { s->failed_pc=0x0c0c7738u; return 0; }
r[2]+=r[3];
goto P_0c0c773a;
P_0c0c773a: /* original 930b, guest PC 0x0c0c773a */
if(!s->budget--) { s->failed_pc=0x0c0c773au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7754u,2);
goto P_0c0c773c;
P_0c0c773c: /* original 321c, guest PC 0x0c0c773c */
if(!s->budget--) { s->failed_pc=0x0c0c773cu; return 0; }
r[2]+=r[1];
goto P_0c0c773e;
P_0c0c773e: /* original 2239, guest PC 0x0c0c773e */
if(!s->budget--) { s->failed_pc=0x0c0c773eu; return 0; }
r[2]&=r[3];
goto P_0c0c7740;
P_0c0c7740: /* original 0e26, guest PC 0x0c0c7740 */
if(!s->budget--) { s->failed_pc=0x0c0c7740u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c7742;
P_0c0c7742: /* original 70f8, guest PC 0x0c0c7742 */
if(!s->budget--) { s->failed_pc=0x0c0c7742u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c7744;
P_0c0c7744: /* original a01a, guest PC 0x0c0c7744 */
if(!s->budget--) { s->failed_pc=0x0c0c7744u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c777c;
P_0c0c7746: /* original 0e26, guest PC 0x0c0c7746 */
if(!s->budget--) { s->failed_pc=0x0c0c7746u; return 0; }
write(ram,r[14]+r[0],r[2],4);
if(!vf3_matrix_family(0x0c0c7748u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7748u; return 0; } return 1;
P_0c0c7778: /* original 9071, guest PC 0x0c0c7778 */
if(!s->budget--) { s->failed_pc=0x0c0c7778u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c785eu,2);
goto P_0c0c777a;
P_0c0c777a: /* original 0e46, guest PC 0x0c0c777a */
if(!s->budget--) { s->failed_pc=0x0c0c777au; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c777c;
P_0c0c777c: /* original d03a, guest PC 0x0c0c777c */
if(!s->budget--) { s->failed_pc=0x0c0c777cu; return 0; }
r[0]=read(ram,0x0c0c7868u,4);
goto P_0c0c777e;
P_0c0c777e: /* original 00ce, guest PC 0x0c0c777e */
if(!s->budget--) { s->failed_pc=0x0c0c777eu; return 0; }
r[0]=read(ram,r[12]+r[0],4);
goto P_0c0c7780;
P_0c0c7780: /* original 88ff, guest PC 0x0c0c7780 */
if(!s->budget--) { s->failed_pc=0x0c0c7780u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c7782;
P_0c0c7782: /* original 8931, guest PC 0x0c0c7782 */
if(!s->budget--) { s->failed_pc=0x0c0c7782u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c77e8; }
goto P_0c0c7784;
P_0c0c7784: /* original 906b, guest PC 0x0c0c7784 */
if(!s->budget--) { s->failed_pc=0x0c0c7784u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c785eu,2);
goto P_0c0c7786;
P_0c0c7786: /* original d339, guest PC 0x0c0c7786 */
if(!s->budget--) { s->failed_pc=0x0c0c7786u; return 0; }
r[3]=read(ram,0x0c0c786cu,4);
goto P_0c0c7788;
P_0c0c7788: /* original 0dee, guest PC 0x0c0c7788 */
if(!s->budget--) { s->failed_pc=0x0c0c7788u; return 0; }
r[13]=read(ram,r[14]+r[0],4);
goto P_0c0c778a;
P_0c0c778a: /* original 6093, guest PC 0x0c0c778a */
if(!s->budget--) { s->failed_pc=0x0c0c778au; return 0; }
r[0]=r[9];
goto P_0c0c778c;
P_0c0c778c: /* original 8812, guest PC 0x0c0c778c */
if(!s->budget--) { s->failed_pc=0x0c0c778cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c0c778e;
P_0c0c778e: /* original 8f08, guest PC 0x0c0c778e */
if(!s->budget--) { s->failed_pc=0x0c0c778eu; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[7]=tmp;
if(!cond) { goto P_0c0c77a2; }
goto P_0c0c7792;
P_0c0c7790: /* original 6731, guest PC 0x0c0c7790 */
if(!s->budget--) { s->failed_pc=0x0c0c7790u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[7]=tmp;
goto P_0c0c7792;
P_0c0c7792: /* original 9565, guest PC 0x0c0c7792 */
if(!s->budget--) { s->failed_pc=0x0c0c7792u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7860u,2);
goto P_0c0c7794;
P_0c0c7794: /* original 66d3, guest PC 0x0c0c7794 */
if(!s->budget--) { s->failed_pc=0x0c0c7794u; return 0; }
r[6]=r[13];
goto P_0c0c7796;
P_0c0c7796: /* original d136, guest PC 0x0c0c7796 */
if(!s->budget--) { s->failed_pc=0x0c0c7796u; return 0; }
r[1]=read(ram,0x0c0c7870u,4);
goto P_0c0c7798;
P_0c0c7798: /* original 6453, guest PC 0x0c0c7798 */
if(!s->budget--) { s->failed_pc=0x0c0c7798u; return 0; }
r[4]=r[5];
goto P_0c0c779a;
P_0c0c779a: /* original 410b, guest PC 0x0c0c779a */
if(!s->budget--) { s->failed_pc=0x0c0c779au; return 0; }
target=r[1];
r[16]=code_base|0x0c0c779eu;
r[4]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c779eu) { target=s->pc; goto dispatch; }
goto P_0c0c779e;
P_0c0c779c: /* original 7401, guest PC 0x0c0c779c */
if(!s->budget--) { s->failed_pc=0x0c0c779cu; return 0; }
r[4]+=0x00000001u;
goto P_0c0c779e;
P_0c0c779e: /* original a009, guest PC 0x0c0c779e */
if(!s->budget--) { s->failed_pc=0x0c0c779eu; return 0; }
goto P_0c0c77b4;
P_0c0c77a0: /* original 0009, guest PC 0x0c0c77a0 */
if(!s->budget--) { s->failed_pc=0x0c0c77a0u; return 0; }
goto P_0c0c77a2;
P_0c0c77a2: /* original d531, guest PC 0x0c0c77a2 */
if(!s->budget--) { s->failed_pc=0x0c0c77a2u; return 0; }
r[5]=read(ram,0x0c0c7868u,4);
goto P_0c0c77a4;
P_0c0c77a4: /* original 66d3, guest PC 0x0c0c77a4 */
if(!s->budget--) { s->failed_pc=0x0c0c77a4u; return 0; }
r[6]=r[13];
goto P_0c0c77a6;
P_0c0c77a6: /* original 35cc, guest PC 0x0c0c77a6 */
if(!s->budget--) { s->failed_pc=0x0c0c77a6u; return 0; }
r[5]+=r[12];
goto P_0c0c77a8;
P_0c0c77a8: /* original 2f52, guest PC 0x0c0c77a8 */
if(!s->budget--) { s->failed_pc=0x0c0c77a8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c77aa;
P_0c0c77aa: /* original 64f2, guest PC 0x0c0c77aa */
if(!s->budget--) { s->failed_pc=0x0c0c77aau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c77ac;
P_0c0c77ac: /* original d230, guest PC 0x0c0c77ac */
if(!s->budget--) { s->failed_pc=0x0c0c77acu; return 0; }
r[2]=read(ram,0x0c0c7870u,4);
goto P_0c0c77ae;
P_0c0c77ae: /* original 5551, guest PC 0x0c0c77ae */
if(!s->budget--) { s->failed_pc=0x0c0c77aeu; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c0c77b0;
P_0c0c77b0: /* original 420b, guest PC 0x0c0c77b0 */
if(!s->budget--) { s->failed_pc=0x0c0c77b0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c77b4u;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c77b4u) { target=s->pc; goto dispatch; }
goto P_0c0c77b4;
P_0c0c77b2: /* original 6442, guest PC 0x0c0c77b2 */
if(!s->budget--) { s->failed_pc=0x0c0c77b2u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c77b4;
P_0c0c77b4: /* original 9a55, guest PC 0x0c0c77b4 */
if(!s->budget--) { s->failed_pc=0x0c0c77b4u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7862u,2);
goto P_0c0c77b6;
P_0c0c77b6: /* original 59d4, guest PC 0x0c0c77b6 */
if(!s->budget--) { s->failed_pc=0x0c0c77b6u; return 0; }
r[9]=read(ram,r[13]+16,4);
goto P_0c0c77b8;
P_0c0c77b8: /* original a007, guest PC 0x0c0c77b8 */
if(!s->budget--) { s->failed_pc=0x0c0c77b8u; return 0; }
r[12]=0x00000000u;
goto P_0c0c77ca;
P_0c0c77ba: /* original ec00, guest PC 0x0c0c77ba */
if(!s->budget--) { s->failed_pc=0x0c0c77bau; return 0; }
r[12]=0x00000000u;
goto P_0c0c77bc;
P_0c0c77bc: /* original 60c3, guest PC 0x0c0c77bc */
if(!s->budget--) { s->failed_pc=0x0c0c77bcu; return 0; }
r[0]=r[12];
goto P_0c0c77be;
P_0c0c77be: /* original 4008, guest PC 0x0c0c77be */
if(!s->budget--) { s->failed_pc=0x0c0c77beu; return 0; }
r[0]<<=2;
goto P_0c0c77c0;
P_0c0c77c0: /* original 059e, guest PC 0x0c0c77c0 */
if(!s->budget--) { s->failed_pc=0x0c0c77c0u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c0c77c2;
P_0c0c77c2: /* original 64a3, guest PC 0x0c0c77c2 */
if(!s->budget--) { s->failed_pc=0x0c0c77c2u; return 0; }
r[4]=r[10];
goto P_0c0c77c4;
P_0c0c77c4: /* original 4b0b, guest PC 0x0c0c77c4 */
if(!s->budget--) { s->failed_pc=0x0c0c77c4u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c77c8u;
r[10]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c77c8u) { target=s->pc; goto dispatch; }
goto P_0c0c77c8;
P_0c0c77c6: /* original 7a01, guest PC 0x0c0c77c6 */
if(!s->budget--) { s->failed_pc=0x0c0c77c6u; return 0; }
r[10]+=0x00000001u;
goto P_0c0c77c8;
P_0c0c77c8: /* original 7c01, guest PC 0x0c0c77c8 */
if(!s->budget--) { s->failed_pc=0x0c0c77c8u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c77ca;
P_0c0c77ca: /* original 85d6, guest PC 0x0c0c77ca */
if(!s->budget--) { s->failed_pc=0x0c0c77cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+12,2);
goto P_0c0c77cc;
P_0c0c77cc: /* original 600d, guest PC 0x0c0c77cc */
if(!s->budget--) { s->failed_pc=0x0c0c77ccu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c77ce;
P_0c0c77ce: /* original 3c03, guest PC 0x0c0c77ce */
if(!s->budget--) { s->failed_pc=0x0c0c77ceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[0])!=0);
goto P_0c0c77d0;
P_0c0c77d0: /* original 8bf4, guest PC 0x0c0c77d0 */
if(!s->budget--) { s->failed_pc=0x0c0c77d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c77bc; }
goto P_0c0c77d2;
P_0c0c77d2: /* original 9044, guest PC 0x0c0c77d2 */
if(!s->budget--) { s->failed_pc=0x0c0c77d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c785eu,2);
goto P_0c0c77d4;
P_0c0c77d4: /* original 53d6, guest PC 0x0c0c77d4 */
if(!s->budget--) { s->failed_pc=0x0c0c77d4u; return 0; }
r[3]=read(ram,r[13]+24,4);
goto P_0c0c77d6;
P_0c0c77d6: /* original 02ee, guest PC 0x0c0c77d6 */
if(!s->budget--) { s->failed_pc=0x0c0c77d6u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0c77d8;
P_0c0c77d8: /* original 7008, guest PC 0x0c0c77d8 */
if(!s->budget--) { s->failed_pc=0x0c0c77d8u; return 0; }
r[0]+=0x00000008u;
goto P_0c0c77da;
P_0c0c77da: /* original 9143, guest PC 0x0c0c77da */
if(!s->budget--) { s->failed_pc=0x0c0c77dau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7864u,2);
goto P_0c0c77dc;
P_0c0c77dc: /* original 323c, guest PC 0x0c0c77dc */
if(!s->budget--) { s->failed_pc=0x0c0c77dcu; return 0; }
r[2]+=r[3];
goto P_0c0c77de;
P_0c0c77de: /* original 9342, guest PC 0x0c0c77de */
if(!s->budget--) { s->failed_pc=0x0c0c77deu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7866u,2);
goto P_0c0c77e0;
P_0c0c77e0: /* original 321c, guest PC 0x0c0c77e0 */
if(!s->budget--) { s->failed_pc=0x0c0c77e0u; return 0; }
r[2]+=r[1];
goto P_0c0c77e2;
P_0c0c77e2: /* original 2239, guest PC 0x0c0c77e2 */
if(!s->budget--) { s->failed_pc=0x0c0c77e2u; return 0; }
r[2]&=r[3];
goto P_0c0c77e4;
P_0c0c77e4: /* original a003, guest PC 0x0c0c77e4 */
if(!s->budget--) { s->failed_pc=0x0c0c77e4u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c77ee;
P_0c0c77e6: /* original 0e26, guest PC 0x0c0c77e6 */
if(!s->budget--) { s->failed_pc=0x0c0c77e6u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c77e8;
P_0c0c77e8: /* original 9039, guest PC 0x0c0c77e8 */
if(!s->budget--) { s->failed_pc=0x0c0c77e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c785eu,2);
goto P_0c0c77ea;
P_0c0c77ea: /* original e300, guest PC 0x0c0c77ea */
if(!s->budget--) { s->failed_pc=0x0c0c77eau; return 0; }
r[3]=0x00000000u;
goto P_0c0c77ec;
P_0c0c77ec: /* original 0e36, guest PC 0x0c0c77ec */
if(!s->budget--) { s->failed_pc=0x0c0c77ecu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0c77ee;
P_0c0c77ee: /* original 7f04, guest PC 0x0c0c77ee */
if(!s->budget--) { s->failed_pc=0x0c0c77eeu; return 0; }
r[15]+=0x00000004u;
goto P_0c0c77f0;
P_0c0c77f0: /* original 4f26, guest PC 0x0c0c77f0 */
if(!s->budget--) { s->failed_pc=0x0c0c77f0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c77f2;
P_0c0c77f2: /* original 68f6, guest PC 0x0c0c77f2 */
if(!s->budget--) { s->failed_pc=0x0c0c77f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c77f4;
P_0c0c77f4: /* original 69f6, guest PC 0x0c0c77f4 */
if(!s->budget--) { s->failed_pc=0x0c0c77f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c77f6;
P_0c0c77f6: /* original 6af6, guest PC 0x0c0c77f6 */
if(!s->budget--) { s->failed_pc=0x0c0c77f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c77f8;
P_0c0c77f8: /* original 6bf6, guest PC 0x0c0c77f8 */
if(!s->budget--) { s->failed_pc=0x0c0c77f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c77fa;
P_0c0c77fa: /* original 6cf6, guest PC 0x0c0c77fa */
if(!s->budget--) { s->failed_pc=0x0c0c77fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c77fc;
P_0c0c77fc: /* original 6df6, guest PC 0x0c0c77fc */
if(!s->budget--) { s->failed_pc=0x0c0c77fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c77fe;
P_0c0c77fe: /* original a000, guest PC 0x0c0c77fe */
if(!s->budget--) { s->failed_pc=0x0c0c77feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c7802;
P_0c0c7800: /* original 6ef6, guest PC 0x0c0c7800 */
if(!s->budget--) { s->failed_pc=0x0c0c7800u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c7802;
P_0c0c7802: /* original e01c, guest PC 0x0c0c7802 */
if(!s->budget--) { s->failed_pc=0x0c0c7802u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7804;
P_0c0c7804: /* original 2fe6, guest PC 0x0c0c7804 */
if(!s->budget--) { s->failed_pc=0x0c0c7804u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7806;
P_0c0c7806: /* original 2fd6, guest PC 0x0c0c7806 */
if(!s->budget--) { s->failed_pc=0x0c0c7806u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7808;
P_0c0c7808: /* original 2fc6, guest PC 0x0c0c7808 */
if(!s->budget--) { s->failed_pc=0x0c0c7808u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c780a;
P_0c0c780a: /* original 2fb6, guest PC 0x0c0c780a */
if(!s->budget--) { s->failed_pc=0x0c0c780au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c780c;
P_0c0c780c: /* original 2fa6, guest PC 0x0c0c780c */
if(!s->budget--) { s->failed_pc=0x0c0c780cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c780e;
P_0c0c780e: /* original d419, guest PC 0x0c0c780e */
if(!s->budget--) { s->failed_pc=0x0c0c780eu; return 0; }
r[4]=read(ram,0x0c0c7874u,4);
goto P_0c0c7810;
P_0c0c7810: /* original 4f22, guest PC 0x0c0c7810 */
if(!s->budget--) { s->failed_pc=0x0c0c7810u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7812;
P_0c0c7812: /* original 004c, guest PC 0x0c0c7812 */
if(!s->budget--) { s->failed_pc=0x0c0c7812u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7814;
P_0c0c7814: /* original e40f, guest PC 0x0c0c7814 */
if(!s->budget--) { s->failed_pc=0x0c0c7814u; return 0; }
r[4]=0x0000000fu;
goto P_0c0c7816;
P_0c0c7816: /* original 600c, guest PC 0x0c0c7816 */
if(!s->budget--) { s->failed_pc=0x0c0c7816u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c7818;
P_0c0c7818: /* original 2409, guest PC 0x0c0c7818 */
if(!s->budget--) { s->failed_pc=0x0c0c7818u; return 0; }
r[4]&=r[0];
goto P_0c0c781a;
P_0c0c781a: /* original d017, guest PC 0x0c0c781a */
if(!s->budget--) { s->failed_pc=0x0c0c781au; return 0; }
r[0]=read(ram,0x0c0c7878u,4);
goto P_0c0c781c;
P_0c0c781c: /* original 6e43, guest PC 0x0c0c781c */
if(!s->budget--) { s->failed_pc=0x0c0c781cu; return 0; }
r[14]=r[4];
goto P_0c0c781e;
P_0c0c781e: /* original 4e08, guest PC 0x0c0c781e */
if(!s->budget--) { s->failed_pc=0x0c0c781eu; return 0; }
r[14]<<=2;
goto P_0c0c7820;
P_0c0c7820: /* original 0eee, guest PC 0x0c0c7820 */
if(!s->budget--) { s->failed_pc=0x0c0c7820u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c0c7822;
P_0c0c7822: /* original 2ee8, guest PC 0x0c0c7822 */
if(!s->budget--) { s->failed_pc=0x0c0c7822u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c7824;
P_0c0c7824: /* original 8914, guest PC 0x0c0c7824 */
if(!s->budget--) { s->failed_pc=0x0c0c7824u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7850; }
goto P_0c0c7826;
P_0c0c7826: /* original dc17, guest PC 0x0c0c7826 */
if(!s->budget--) { s->failed_pc=0x0c0c7826u; return 0; }
r[12]=read(ram,0x0c0c7884u,4);
goto P_0c0c7828;
P_0c0c7828: /* original db15, guest PC 0x0c0c7828 */
if(!s->budget--) { s->failed_pc=0x0c0c7828u; return 0; }
r[11]=read(ram,0x0c0c7880u,4);
goto P_0c0c782a;
P_0c0c782a: /* original da14, guest PC 0x0c0c782a */
if(!s->budget--) { s->failed_pc=0x0c0c782au; return 0; }
r[10]=read(ram,0x0c0c787cu,4);
goto P_0c0c782c;
P_0c0c782c: /* original a00d, guest PC 0x0c0c782c */
if(!s->budget--) { s->failed_pc=0x0c0c782cu; return 0; }
r[13]=0x00000001u;
goto P_0c0c784a;
P_0c0c782e: /* original ed01, guest PC 0x0c0c782e */
if(!s->budget--) { s->failed_pc=0x0c0c782eu; return 0; }
r[13]=0x00000001u;
goto P_0c0c7830;
P_0c0c7830: /* original 60e5, guest PC 0x0c0c7830 */
if(!s->budget--) { s->failed_pc=0x0c0c7830u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[0]=tmp;
goto P_0c0c7832;
P_0c0c7832: /* original 600d, guest PC 0x0c0c7832 */
if(!s->budget--) { s->failed_pc=0x0c0c7832u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c7834;
P_0c0c7834: /* original 4008, guest PC 0x0c0c7834 */
if(!s->budget--) { s->failed_pc=0x0c0c7834u; return 0; }
r[0]<<=2;
goto P_0c0c7836;
P_0c0c7836: /* original 04ce, guest PC 0x0c0c7836 */
if(!s->budget--) { s->failed_pc=0x0c0c7836u; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c0c7838;
P_0c0c7838: /* original 5341, guest PC 0x0c0c7838 */
if(!s->budget--) { s->failed_pc=0x0c0c7838u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0c783a;
P_0c0c783a: /* original 23d8, guest PC 0x0c0c783a */
if(!s->budget--) { s->failed_pc=0x0c0c783au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c783c;
P_0c0c783c: /* original 8903, guest PC 0x0c0c783c */
if(!s->budget--) { s->failed_pc=0x0c0c783cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7846; }
goto P_0c0c783e;
P_0c0c783e: /* original 4b0b, guest PC 0x0c0c783e */
if(!s->budget--) { s->failed_pc=0x0c0c783eu; return 0; }
target=r[11];
r[16]=code_base|0x0c0c7842u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7842u) { target=s->pc; goto dispatch; }
goto P_0c0c7842;
P_0c0c7840: /* original 0009, guest PC 0x0c0c7840 */
if(!s->budget--) { s->failed_pc=0x0c0c7840u; return 0; }
goto P_0c0c7842;
P_0c0c7842: /* original a002, guest PC 0x0c0c7842 */
if(!s->budget--) { s->failed_pc=0x0c0c7842u; return 0; }
goto P_0c0c784a;
P_0c0c7844: /* original 0009, guest PC 0x0c0c7844 */
if(!s->budget--) { s->failed_pc=0x0c0c7844u; return 0; }
goto P_0c0c7846;
P_0c0c7846: /* original 4a0b, guest PC 0x0c0c7846 */
if(!s->budget--) { s->failed_pc=0x0c0c7846u; return 0; }
target=r[10];
r[16]=code_base|0x0c0c784au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c784au) { target=s->pc; goto dispatch; }
goto P_0c0c784a;
P_0c0c7848: /* original 0009, guest PC 0x0c0c7848 */
if(!s->budget--) { s->failed_pc=0x0c0c7848u; return 0; }
goto P_0c0c784a;
P_0c0c784a: /* original 62e1, guest PC 0x0c0c784a */
if(!s->budget--) { s->failed_pc=0x0c0c784au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c0c784c;
P_0c0c784c: /* original 2228, guest PC 0x0c0c784c */
if(!s->budget--) { s->failed_pc=0x0c0c784cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c784e;
P_0c0c784e: /* original 8bef, guest PC 0x0c0c784e */
if(!s->budget--) { s->failed_pc=0x0c0c784eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7830; }
goto P_0c0c7850;
P_0c0c7850: /* original 4f26, guest PC 0x0c0c7850 */
if(!s->budget--) { s->failed_pc=0x0c0c7850u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7852;
P_0c0c7852: /* original 6af6, guest PC 0x0c0c7852 */
if(!s->budget--) { s->failed_pc=0x0c0c7852u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c7854;
P_0c0c7854: /* original 6bf6, guest PC 0x0c0c7854 */
if(!s->budget--) { s->failed_pc=0x0c0c7854u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7856;
P_0c0c7856: /* original 6cf6, guest PC 0x0c0c7856 */
if(!s->budget--) { s->failed_pc=0x0c0c7856u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7858;
P_0c0c7858: /* original 6df6, guest PC 0x0c0c7858 */
if(!s->budget--) { s->failed_pc=0x0c0c7858u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c785a;
P_0c0c785a: /* original 000b, guest PC 0x0c0c785a */
if(!s->budget--) { s->failed_pc=0x0c0c785au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c785c: /* original 6ef6, guest PC 0x0c0c785c */
if(!s->budget--) { s->failed_pc=0x0c0c785cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c785eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c785eu; return 0; } return 1;
P_0c0c7c50: /* original 2fe6, guest PC 0x0c0c7c50 */
if(!s->budget--) { s->failed_pc=0x0c0c7c50u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7c52;
P_0c0c7c52: /* original e201, guest PC 0x0c0c7c52 */
if(!s->budget--) { s->failed_pc=0x0c0c7c52u; return 0; }
r[2]=0x00000001u;
goto P_0c0c7c54;
P_0c0c7c54: /* original 2fd6, guest PC 0x0c0c7c54 */
if(!s->budget--) { s->failed_pc=0x0c0c7c54u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7c56;
P_0c0c7c56: /* original e07f, guest PC 0x0c0c7c56 */
if(!s->budget--) { s->failed_pc=0x0c0c7c56u; return 0; }
r[0]=0x0000007fu;
goto P_0c0c7c58;
P_0c0c7c58: /* original 2fc6, guest PC 0x0c0c7c58 */
if(!s->budget--) { s->failed_pc=0x0c0c7c58u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7c5a;
P_0c0c7c5a: /* original ec34, guest PC 0x0c0c7c5a */
if(!s->budget--) { s->failed_pc=0x0c0c7c5au; return 0; }
r[12]=0x00000034u;
goto P_0c0c7c5c;
P_0c0c7c5c: /* original 2fb6, guest PC 0x0c0c7c5c */
if(!s->budget--) { s->failed_pc=0x0c0c7c5cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7c5e;
P_0c0c7c5e: /* original 2fa6, guest PC 0x0c0c7c5e */
if(!s->budget--) { s->failed_pc=0x0c0c7c5eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7c60;
P_0c0c7c60: /* original 2f96, guest PC 0x0c0c7c60 */
if(!s->budget--) { s->failed_pc=0x0c0c7c60u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7c62;
P_0c0c7c62: /* original d94b, guest PC 0x0c0c7c62 */
if(!s->budget--) { s->failed_pc=0x0c0c7c62u; return 0; }
r[9]=read(ram,0x0c0c7d90u,4);
goto P_0c0c7c64;
P_0c0c7c64: /* original 4f22, guest PC 0x0c0c7c64 */
if(!s->budget--) { s->failed_pc=0x0c0c7c64u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7c66;
P_0c0c7c66: /* original d34c, guest PC 0x0c0c7c66 */
if(!s->budget--) { s->failed_pc=0x0c0c7c66u; return 0; }
r[3]=read(ram,0x0c0c7d98u,4);
goto P_0c0c7c68;
P_0c0c7c68: /* original db4a, guest PC 0x0c0c7c68 */
if(!s->budget--) { s->failed_pc=0x0c0c7c68u; return 0; }
r[11]=read(ram,0x0c0c7d94u,4);
goto P_0c0c7c6a;
P_0c0c7c6a: /* original 4f12, guest PC 0x0c0c7c6a */
if(!s->budget--) { s->failed_pc=0x0c0c7c6au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c7c6c;
P_0c0c7c6c: /* original 7ffc, guest PC 0x0c0c7c6c */
if(!s->budget--) { s->failed_pc=0x0c0c7c6cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c7c6e;
P_0c0c7c6e: /* original 2f32, guest PC 0x0c0c7c6e */
if(!s->budget--) { s->failed_pc=0x0c0c7c6eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c7c70;
P_0c0c7c70: /* original 0924, guest PC 0x0c0c7c70 */
if(!s->budget--) { s->failed_pc=0x0c0c7c70u; return 0; }
write(ram,r[9]+r[0],r[2],1);
goto P_0c0c7c72;
P_0c0c7c72: /* original e01c, guest PC 0x0c0c7c72 */
if(!s->budget--) { s->failed_pc=0x0c0c7c72u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7c74;
P_0c0c7c74: /* original 0a9c, guest PC 0x0c0c7c74 */
if(!s->budget--) { s->failed_pc=0x0c0c7c74u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+r[0],1);
goto P_0c0c7c76;
P_0c0c7c76: /* original d24a, guest PC 0x0c0c7c76 */
if(!s->budget--) { s->failed_pc=0x0c0c7c76u; return 0; }
r[2]=read(ram,0x0c0c7da0u,4);
goto P_0c0c7c78;
P_0c0c7c78: /* original 6aac, guest PC 0x0c0c7c78 */
if(!s->budget--) { s->failed_pc=0x0c0c7c78u; return 0; }
r[10]=r[10]&255u;
goto P_0c0c7c7a;
P_0c0c7c7a: /* original d348, guest PC 0x0c0c7c7a */
if(!s->budget--) { s->failed_pc=0x0c0c7c7au; return 0; }
r[3]=read(ram,0x0c0c7d9cu,4);
goto P_0c0c7c7c;
P_0c0c7c7c: /* original 2acf, guest PC 0x0c0c7c7c */
if(!s->budget--) { s->failed_pc=0x0c0c7c7cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[10]*(int32_t)(int16_t)r[12]);
goto P_0c0c7c7e;
P_0c0c7c7e: /* original 6ea3, guest PC 0x0c0c7c7e */
if(!s->budget--) { s->failed_pc=0x0c0c7c7eu; return 0; }
r[14]=r[10];
goto P_0c0c7c80;
P_0c0c7c80: /* original 4e08, guest PC 0x0c0c7c80 */
if(!s->budget--) { s->failed_pc=0x0c0c7c80u; return 0; }
r[14]<<=2;
goto P_0c0c7c82;
P_0c0c7c82: /* original 4e08, guest PC 0x0c0c7c82 */
if(!s->budget--) { s->failed_pc=0x0c0c7c82u; return 0; }
r[14]<<=2;
goto P_0c0c7c84;
P_0c0c7c84: /* original 9079, guest PC 0x0c0c7c84 */
if(!s->budget--) { s->failed_pc=0x0c0c7c84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d7au,2);
goto P_0c0c7c86;
P_0c0c7c86: /* original 4e08, guest PC 0x0c0c7c86 */
if(!s->budget--) { s->failed_pc=0x0c0c7c86u; return 0; }
r[14]<<=2;
goto P_0c0c7c88;
P_0c0c7c88: /* original 0c1a, guest PC 0x0c0c7c88 */
if(!s->budget--) { s->failed_pc=0x0c0c7c88u; return 0; }
r[12]=r[19];
goto P_0c0c7c8a;
P_0c0c7c8a: /* original 3e3c, guest PC 0x0c0c7c8a */
if(!s->budget--) { s->failed_pc=0x0c0c7c8au; return 0; }
r[14]+=r[3];
goto P_0c0c7c8c;
P_0c0c7c8c: /* original 6ccf, guest PC 0x0c0c7c8c */
if(!s->budget--) { s->failed_pc=0x0c0c7c8cu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c0c7c8e;
P_0c0c7c8e: /* original 3c2c, guest PC 0x0c0c7c8e */
if(!s->budget--) { s->failed_pc=0x0c0c7c8eu; return 0; }
r[12]+=r[2];
goto P_0c0c7c90;
P_0c0c7c90: /* original 0be6, guest PC 0x0c0c7c90 */
if(!s->budget--) { s->failed_pc=0x0c0c7c90u; return 0; }
write(ram,r[11]+r[0],r[14],4);
goto P_0c0c7c92;
P_0c0c7c92: /* original 7004, guest PC 0x0c0c7c92 */
if(!s->budget--) { s->failed_pc=0x0c0c7c92u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c7c94;
P_0c0c7c94: /* original 65c3, guest PC 0x0c0c7c94 */
if(!s->budget--) { s->failed_pc=0x0c0c7c94u; return 0; }
r[5]=r[12];
goto P_0c0c7c96;
P_0c0c7c96: /* original 0bc6, guest PC 0x0c0c7c96 */
if(!s->budget--) { s->failed_pc=0x0c0c7c96u; return 0; }
write(ram,r[11]+r[0],r[12],4);
goto P_0c0c7c98;
P_0c0c7c98: /* original d342, guest PC 0x0c0c7c98 */
if(!s->budget--) { s->failed_pc=0x0c0c7c98u; return 0; }
r[3]=read(ram,0x0c0c7da4u,4);
goto P_0c0c7c9a;
P_0c0c7c9a: /* original 430b, guest PC 0x0c0c7c9a */
if(!s->budget--) { s->failed_pc=0x0c0c7c9au; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7c9eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7c9eu) { target=s->pc; goto dispatch; }
goto P_0c0c7c9e;
P_0c0c7c9c: /* original 64e3, guest PC 0x0c0c7c9c */
if(!s->budget--) { s->failed_pc=0x0c0c7c9cu; return 0; }
r[4]=r[14];
goto P_0c0c7c9e;
P_0c0c7c9e: /* original 63e2, guest PC 0x0c0c7c9e */
if(!s->budget--) { s->failed_pc=0x0c0c7c9eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0c7ca0;
P_0c0c7ca0: /* original 906c, guest PC 0x0c0c7ca0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ca0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d7cu,2);
goto P_0c0c7ca2;
P_0c0c7ca2: /* original d241, guest PC 0x0c0c7ca2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ca2u; return 0; }
r[2]=read(ram,0x0c0c7da8u,4);
goto P_0c0c7ca4;
P_0c0c7ca4: /* original 6d22, guest PC 0x0c0c7ca4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ca4u; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c0c7ca6;
P_0c0c7ca6: /* original 0b36, guest PC 0x0c0c7ca6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ca6u; return 0; }
write(ram,r[11]+r[0],r[3],4);
goto P_0c0c7ca8;
P_0c0c7ca8: /* original 6192, guest PC 0x0c0c7ca8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ca8u; return 0; }
tmp=read(ram,r[9],4);
r[1]=tmp;
goto P_0c0c7caa;
P_0c0c7caa: /* original d340, guest PC 0x0c0c7caa */
if(!s->budget--) { s->failed_pc=0x0c0c7caau; return 0; }
r[3]=read(ram,0x0c0c7dacu,4);
goto P_0c0c7cac;
P_0c0c7cac: /* original 2138, guest PC 0x0c0c7cac */
if(!s->budget--) { s->failed_pc=0x0c0c7cacu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0c7cae;
P_0c0c7cae: /* original 8b03, guest PC 0x0c0c7cae */
if(!s->budget--) { s->failed_pc=0x0c0c7caeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7cb8; }
goto P_0c0c7cb0;
P_0c0c7cb0: /* original d23f, guest PC 0x0c0c7cb0 */
if(!s->budget--) { s->failed_pc=0x0c0c7cb0u; return 0; }
r[2]=read(ram,0x0c0c7db0u,4);
goto P_0c0c7cb2;
P_0c0c7cb2: /* original e034, guest PC 0x0c0c7cb2 */
if(!s->budget--) { s->failed_pc=0x0c0c7cb2u; return 0; }
r[0]=0x00000034u;
goto P_0c0c7cb4;
P_0c0c7cb4: /* original 420b, guest PC 0x0c0c7cb4 */
if(!s->budget--) { s->failed_pc=0x0c0c7cb4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7cb8u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7cb8u) { target=s->pc; goto dispatch; }
goto P_0c0c7cb8;
P_0c0c7cb6: /* original 04ed, guest PC 0x0c0c7cb6 */
if(!s->budget--) { s->failed_pc=0x0c0c7cb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c7cb8;
P_0c0c7cb8: /* original e036, guest PC 0x0c0c7cb8 */
if(!s->budget--) { s->failed_pc=0x0c0c7cb8u; return 0; }
r[0]=0x00000036u;
goto P_0c0c7cba;
P_0c0c7cba: /* original 03ed, guest PC 0x0c0c7cba */
if(!s->budget--) { s->failed_pc=0x0c0c7cbau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c7cbc;
P_0c0c7cbc: /* original e731, guest PC 0x0c0c7cbc */
if(!s->budget--) { s->failed_pc=0x0c0c7cbcu; return 0; }
r[7]=0x00000031u;
goto P_0c0c7cbe;
P_0c0c7cbe: /* original 905e, guest PC 0x0c0c7cbe */
if(!s->budget--) { s->failed_pc=0x0c0c7cbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d7eu,2);
goto P_0c0c7cc0;
P_0c0c7cc0: /* original 6273, guest PC 0x0c0c7cc0 */
if(!s->budget--) { s->failed_pc=0x0c0c7cc0u; return 0; }
r[2]=r[7];
goto P_0c0c7cc2;
P_0c0c7cc2: /* original 7253, guest PC 0x0c0c7cc2 */
if(!s->budget--) { s->failed_pc=0x0c0c7cc2u; return 0; }
r[2]+=0x00000053u;
goto P_0c0c7cc4;
P_0c0c7cc4: /* original 0b35, guest PC 0x0c0c7cc4 */
if(!s->budget--) { s->failed_pc=0x0c0c7cc4u; return 0; }
write(ram,r[11]+r[0],r[3],2);
goto P_0c0c7cc6;
P_0c0c7cc6: /* original e300, guest PC 0x0c0c7cc6 */
if(!s->budget--) { s->failed_pc=0x0c0c7cc6u; return 0; }
r[3]=0x00000000u;
goto P_0c0c7cc8;
P_0c0c7cc8: /* original 915a, guest PC 0x0c0c7cc8 */
if(!s->budget--) { s->failed_pc=0x0c0c7cc8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d80u,2);
goto P_0c0c7cca;
P_0c0c7cca: /* original e640, guest PC 0x0c0c7cca */
if(!s->budget--) { s->failed_pc=0x0c0c7ccau; return 0; }
r[6]=0x00000040u;
goto P_0c0c7ccc;
P_0c0c7ccc: /* original 85c6, guest PC 0x0c0c7ccc */
if(!s->budget--) { s->failed_pc=0x0c0c7cccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+12,2);
goto P_0c0c7cce;
P_0c0c7cce: /* original 6533, guest PC 0x0c0c7cce */
if(!s->budget--) { s->failed_pc=0x0c0c7cceu; return 0; }
r[5]=r[3];
goto P_0c0c7cd0;
P_0c0c7cd0: /* original 31bc, guest PC 0x0c0c7cd0 */
if(!s->budget--) { s->failed_pc=0x0c0c7cd0u; return 0; }
r[1]+=r[11];
goto P_0c0c7cd2;
P_0c0c7cd2: /* original 2101, guest PC 0x0c0c7cd2 */
if(!s->budget--) { s->failed_pc=0x0c0c7cd2u; return 0; }
write(ram,r[1],r[0],2);
goto P_0c0c7cd4;
P_0c0c7cd4: /* original 2f36, guest PC 0x0c0c7cd4 */
if(!s->budget--) { s->failed_pc=0x0c0c7cd4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7cd6;
P_0c0c7cd6: /* original 54f1, guest PC 0x0c0c7cd6 */
if(!s->budget--) { s->failed_pc=0x0c0c7cd6u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c7cd8;
P_0c0c7cd8: /* original d136, guest PC 0x0c0c7cd8 */
if(!s->budget--) { s->failed_pc=0x0c0c7cd8u; return 0; }
r[1]=read(ram,0x0c0c7db4u,4);
goto P_0c0c7cda;
P_0c0c7cda: /* original 410b, guest PC 0x0c0c7cda */
if(!s->budget--) { s->failed_pc=0x0c0c7cdau; return 0; }
target=r[1];
r[16]=code_base|0x0c0c7cdeu;
r[4]+=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7cdeu) { target=s->pc; goto dispatch; }
goto P_0c0c7cde;
P_0c0c7cdc: /* original 342c, guest PC 0x0c0c7cdc */
if(!s->budget--) { s->failed_pc=0x0c0c7cdcu; return 0; }
r[4]+=r[2];
goto P_0c0c7cde;
P_0c0c7cde: /* original d336, guest PC 0x0c0c7cde */
if(!s->budget--) { s->failed_pc=0x0c0c7cdeu; return 0; }
r[3]=read(ram,0x0c0c7db8u,4);
goto P_0c0c7ce0;
P_0c0c7ce0: /* original 7f04, guest PC 0x0c0c7ce0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ce0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c7ce2;
P_0c0c7ce2: /* original 430b, guest PC 0x0c0c7ce2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ce2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7ce6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7ce6u) { target=s->pc; goto dispatch; }
goto P_0c0c7ce6;
P_0c0c7ce4: /* original 64d3, guest PC 0x0c0c7ce4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ce4u; return 0; }
r[4]=r[13];
goto P_0c0c7ce6;
P_0c0c7ce6: /* original e024, guest PC 0x0c0c7ce6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ce6u; return 0; }
r[0]=0x00000024u;
goto P_0c0c7ce8;
P_0c0c7ce8: /* original f3c6, guest PC 0x0c0c7ce8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ce8u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c0c7cea;
P_0c0c7cea: /* original e300, guest PC 0x0c0c7cea */
if(!s->budget--) { s->failed_pc=0x0c0c7ceau; return 0; }
r[3]=0x00000000u;
goto P_0c0c7cec;
P_0c0c7cec: /* original 9049, guest PC 0x0c0c7cec */
if(!s->budget--) { s->failed_pc=0x0c0c7cecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d82u,2);
goto P_0c0c7cee;
P_0c0c7cee: /* original fd37, guest PC 0x0c0c7cee */
if(!s->budget--) { s->failed_pc=0x0c0c7ceeu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0c7cf0;
P_0c0c7cf0: /* original e028, guest PC 0x0c0c7cf0 */
if(!s->budget--) { s->failed_pc=0x0c0c7cf0u; return 0; }
r[0]=0x00000028u;
goto P_0c0c7cf2;
P_0c0c7cf2: /* original f3c6, guest PC 0x0c0c7cf2 */
if(!s->budget--) { s->failed_pc=0x0c0c7cf2u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c0c7cf4;
P_0c0c7cf4: /* original 9046, guest PC 0x0c0c7cf4 */
if(!s->budget--) { s->failed_pc=0x0c0c7cf4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d84u,2);
goto P_0c0c7cf6;
P_0c0c7cf6: /* original fd37, guest PC 0x0c0c7cf6 */
if(!s->budget--) { s->failed_pc=0x0c0c7cf6u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0c7cf8;
P_0c0c7cf8: /* original 9045, guest PC 0x0c0c7cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c7cf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d86u,2);
goto P_0c0c7cfa;
P_0c0c7cfa: /* original 0b36, guest PC 0x0c0c7cfa */
if(!s->budget--) { s->failed_pc=0x0c0c7cfau; return 0; }
write(ram,r[11]+r[0],r[3],4);
goto P_0c0c7cfc;
P_0c0c7cfc: /* original e02c, guest PC 0x0c0c7cfc */
if(!s->budget--) { s->failed_pc=0x0c0c7cfcu; return 0; }
r[0]=0x0000002cu;
goto P_0c0c7cfe;
P_0c0c7cfe: /* original f3c6, guest PC 0x0c0c7cfe */
if(!s->budget--) { s->failed_pc=0x0c0c7cfeu; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c0c7d00;
P_0c0c7d00: /* original 9042, guest PC 0x0c0c7d00 */
if(!s->budget--) { s->failed_pc=0x0c0c7d00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d88u,2);
goto P_0c0c7d02;
P_0c0c7d02: /* original fd37, guest PC 0x0c0c7d02 */
if(!s->budget--) { s->failed_pc=0x0c0c7d02u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0c7d04;
P_0c0c7d04: /* original e030, guest PC 0x0c0c7d04 */
if(!s->budget--) { s->failed_pc=0x0c0c7d04u; return 0; }
r[0]=0x00000030u;
goto P_0c0c7d06;
P_0c0c7d06: /* original f3c6, guest PC 0x0c0c7d06 */
if(!s->budget--) { s->failed_pc=0x0c0c7d06u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c0c7d08;
P_0c0c7d08: /* original 903f, guest PC 0x0c0c7d08 */
if(!s->budget--) { s->failed_pc=0x0c0c7d08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d8au,2);
goto P_0c0c7d0a;
P_0c0c7d0a: /* original fd37, guest PC 0x0c0c7d0a */
if(!s->budget--) { s->failed_pc=0x0c0c7d0au; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0c7d0c;
P_0c0c7d0c: /* original d22b, guest PC 0x0c0c7d0c */
if(!s->budget--) { s->failed_pc=0x0c0c7d0cu; return 0; }
r[2]=read(ram,0x0c0c7dbcu,4);
goto P_0c0c7d0e;
P_0c0c7d0e: /* original 6322, guest PC 0x0c0c7d0e */
if(!s->budget--) { s->failed_pc=0x0c0c7d0eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0c7d10;
P_0c0c7d10: /* original 3a30, guest PC 0x0c0c7d10 */
if(!s->budget--) { s->failed_pc=0x0c0c7d10u; return 0; }
r[17]=(r[17]&~1u)|((r[10]==r[3])!=0);
goto P_0c0c7d12;
P_0c0c7d12: /* original 890d, guest PC 0x0c0c7d12 */
if(!s->budget--) { s->failed_pc=0x0c0c7d12u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7d30; }
goto P_0c0c7d14;
P_0c0c7d14: /* original bc98, guest PC 0x0c0c7d14 */
if(!s->budget--) { s->failed_pc=0x0c0c7d14u; return 0; }
target=code_base|0x0c0c7648u; r[16]=code_base|0x0c0c7d18u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d18u) { target=s->pc; goto dispatch; }
goto P_0c0c7d18;
P_0c0c7d16: /* original 0009, guest PC 0x0c0c7d16 */
if(!s->budget--) { s->failed_pc=0x0c0c7d16u; return 0; }
goto P_0c0c7d18;
P_0c0c7d18: /* original 6192, guest PC 0x0c0c7d18 */
if(!s->budget--) { s->failed_pc=0x0c0c7d18u; return 0; }
tmp=read(ram,r[9],4);
r[1]=tmp;
goto P_0c0c7d1a;
P_0c0c7d1a: /* original d324, guest PC 0x0c0c7d1a */
if(!s->budget--) { s->failed_pc=0x0c0c7d1au; return 0; }
r[3]=read(ram,0x0c0c7dacu,4);
goto P_0c0c7d1c;
P_0c0c7d1c: /* original 2138, guest PC 0x0c0c7d1c */
if(!s->budget--) { s->failed_pc=0x0c0c7d1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0c7d1e;
P_0c0c7d1e: /* original 8b07, guest PC 0x0c0c7d1e */
if(!s->budget--) { s->failed_pc=0x0c0c7d1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7d30; }
goto P_0c0c7d20;
P_0c0c7d20: /* original d227, guest PC 0x0c0c7d20 */
if(!s->budget--) { s->failed_pc=0x0c0c7d20u; return 0; }
r[2]=read(ram,0x0c0c7dc0u,4);
goto P_0c0c7d22;
P_0c0c7d22: /* original 420b, guest PC 0x0c0c7d22 */
if(!s->budget--) { s->failed_pc=0x0c0c7d22u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7d26u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d26u) { target=s->pc; goto dispatch; }
goto P_0c0c7d26;
P_0c0c7d24: /* original 0009, guest PC 0x0c0c7d24 */
if(!s->budget--) { s->failed_pc=0x0c0c7d24u; return 0; }
goto P_0c0c7d26;
P_0c0c7d26: /* original bccb, guest PC 0x0c0c7d26 */
if(!s->budget--) { s->failed_pc=0x0c0c7d26u; return 0; }
target=code_base|0x0c0c76c0u; r[16]=code_base|0x0c0c7d2au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d2au) { target=s->pc; goto dispatch; }
goto P_0c0c7d2a;
P_0c0c7d28: /* original 0009, guest PC 0x0c0c7d28 */
if(!s->budget--) { s->failed_pc=0x0c0c7d28u; return 0; }
goto P_0c0c7d2a;
P_0c0c7d2a: /* original d226, guest PC 0x0c0c7d2a */
if(!s->budget--) { s->failed_pc=0x0c0c7d2au; return 0; }
r[2]=read(ram,0x0c0c7dc4u,4);
goto P_0c0c7d2c;
P_0c0c7d2c: /* original 420b, guest PC 0x0c0c7d2c */
if(!s->budget--) { s->failed_pc=0x0c0c7d2cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7d30u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d30u) { target=s->pc; goto dispatch; }
goto P_0c0c7d30;
P_0c0c7d2e: /* original 64a3, guest PC 0x0c0c7d2e */
if(!s->budget--) { s->failed_pc=0x0c0c7d2eu; return 0; }
r[4]=r[10];
goto P_0c0c7d30;
P_0c0c7d30: /* original 902c, guest PC 0x0c0c7d30 */
if(!s->budget--) { s->failed_pc=0x0c0c7d30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d8cu,2);
goto P_0c0c7d32;
P_0c0c7d32: /* original 0da4, guest PC 0x0c0c7d32 */
if(!s->budget--) { s->failed_pc=0x0c0c7d32u; return 0; }
write(ram,r[13]+r[0],r[10],1);
goto P_0c0c7d34;
P_0c0c7d34: /* original e031, guest PC 0x0c0c7d34 */
if(!s->budget--) { s->failed_pc=0x0c0c7d34u; return 0; }
r[0]=0x00000031u;
goto P_0c0c7d36;
P_0c0c7d36: /* original 03ec, guest PC 0x0c0c7d36 */
if(!s->budget--) { s->failed_pc=0x0c0c7d36u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c7d38;
P_0c0c7d38: /* original 2338, guest PC 0x0c0c7d38 */
if(!s->budget--) { s->failed_pc=0x0c0c7d38u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c7d3a;
P_0c0c7d3a: /* original 8904, guest PC 0x0c0c7d3a */
if(!s->budget--) { s->failed_pc=0x0c0c7d3au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7d46; }
goto P_0c0c7d3c;
P_0c0c7d3c: /* original d322, guest PC 0x0c0c7d3c */
if(!s->budget--) { s->failed_pc=0x0c0c7d3cu; return 0; }
r[3]=read(ram,0x0c0c7dc8u,4);
goto P_0c0c7d3e;
P_0c0c7d3e: /* original 65a3, guest PC 0x0c0c7d3e */
if(!s->budget--) { s->failed_pc=0x0c0c7d3eu; return 0; }
r[5]=r[10];
goto P_0c0c7d40;
P_0c0c7d40: /* original 84e4, guest PC 0x0c0c7d40 */
if(!s->budget--) { s->failed_pc=0x0c0c7d40u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c7d42;
P_0c0c7d42: /* original 430b, guest PC 0x0c0c7d42 */
if(!s->budget--) { s->failed_pc=0x0c0c7d42u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7d46u;
r[4]=r[0]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d46u) { target=s->pc; goto dispatch; }
goto P_0c0c7d46;
P_0c0c7d44: /* original 640c, guest PC 0x0c0c7d44 */
if(!s->budget--) { s->failed_pc=0x0c0c7d44u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c7d46;
P_0c0c7d46: /* original d321, guest PC 0x0c0c7d46 */
if(!s->budget--) { s->failed_pc=0x0c0c7d46u; return 0; }
r[3]=read(ram,0x0c0c7dccu,4);
goto P_0c0c7d48;
P_0c0c7d48: /* original 430b, guest PC 0x0c0c7d48 */
if(!s->budget--) { s->failed_pc=0x0c0c7d48u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7d4cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d4cu) { target=s->pc; goto dispatch; }
goto P_0c0c7d4c;
P_0c0c7d4a: /* original 0009, guest PC 0x0c0c7d4a */
if(!s->budget--) { s->failed_pc=0x0c0c7d4au; return 0; }
goto P_0c0c7d4c;
P_0c0c7d4c: /* original d220, guest PC 0x0c0c7d4c */
if(!s->budget--) { s->failed_pc=0x0c0c7d4cu; return 0; }
r[2]=read(ram,0x0c0c7dd0u,4);
goto P_0c0c7d4e;
P_0c0c7d4e: /* original 420b, guest PC 0x0c0c7d4e */
if(!s->budget--) { s->failed_pc=0x0c0c7d4eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7d52u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d52u) { target=s->pc; goto dispatch; }
goto P_0c0c7d52;
P_0c0c7d50: /* original 0009, guest PC 0x0c0c7d50 */
if(!s->budget--) { s->failed_pc=0x0c0c7d50u; return 0; }
goto P_0c0c7d52;
P_0c0c7d52: /* original 60d2, guest PC 0x0c0c7d52 */
if(!s->budget--) { s->failed_pc=0x0c0c7d52u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0c7d54;
P_0c0c7d54: /* original c810, guest PC 0x0c0c7d54 */
if(!s->budget--) { s->failed_pc=0x0c0c7d54u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0c7d56;
P_0c0c7d56: /* original 8b02, guest PC 0x0c0c7d56 */
if(!s->budget--) { s->failed_pc=0x0c0c7d56u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7d5e; }
goto P_0c0c7d58;
P_0c0c7d58: /* original d21e, guest PC 0x0c0c7d58 */
if(!s->budget--) { s->failed_pc=0x0c0c7d58u; return 0; }
r[2]=read(ram,0x0c0c7dd4u,4);
goto P_0c0c7d5a;
P_0c0c7d5a: /* original 420b, guest PC 0x0c0c7d5a */
if(!s->budget--) { s->failed_pc=0x0c0c7d5au; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7d5eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d5eu) { target=s->pc; goto dispatch; }
goto P_0c0c7d5e;
P_0c0c7d5c: /* original 0009, guest PC 0x0c0c7d5c */
if(!s->budget--) { s->failed_pc=0x0c0c7d5cu; return 0; }
goto P_0c0c7d5e;
P_0c0c7d5e: /* original d31e, guest PC 0x0c0c7d5e */
if(!s->budget--) { s->failed_pc=0x0c0c7d5eu; return 0; }
r[3]=read(ram,0x0c0c7dd8u,4);
goto P_0c0c7d60;
P_0c0c7d60: /* original 430b, guest PC 0x0c0c7d60 */
if(!s->budget--) { s->failed_pc=0x0c0c7d60u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7d64u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d64u) { target=s->pc; goto dispatch; }
goto P_0c0c7d64;
P_0c0c7d62: /* original 0009, guest PC 0x0c0c7d62 */
if(!s->budget--) { s->failed_pc=0x0c0c7d62u; return 0; }
goto P_0c0c7d64;
P_0c0c7d64: /* original d21d, guest PC 0x0c0c7d64 */
if(!s->budget--) { s->failed_pc=0x0c0c7d64u; return 0; }
r[2]=read(ram,0x0c0c7ddcu,4);
goto P_0c0c7d66;
P_0c0c7d66: /* original 420b, guest PC 0x0c0c7d66 */
if(!s->budget--) { s->failed_pc=0x0c0c7d66u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7d6au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d6au) { target=s->pc; goto dispatch; }
goto P_0c0c7d6a;
P_0c0c7d68: /* original 0009, guest PC 0x0c0c7d68 */
if(!s->budget--) { s->failed_pc=0x0c0c7d68u; return 0; }
goto P_0c0c7d6a;
P_0c0c7d6a: /* original 7f04, guest PC 0x0c0c7d6a */
if(!s->budget--) { s->failed_pc=0x0c0c7d6au; return 0; }
r[15]+=0x00000004u;
goto P_0c0c7d6c;
P_0c0c7d6c: /* original 4f16, guest PC 0x0c0c7d6c */
if(!s->budget--) { s->failed_pc=0x0c0c7d6cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7d6e;
P_0c0c7d6e: /* original 4f26, guest PC 0x0c0c7d6e */
if(!s->budget--) { s->failed_pc=0x0c0c7d6eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7d70;
P_0c0c7d70: /* original 69f6, guest PC 0x0c0c7d70 */
if(!s->budget--) { s->failed_pc=0x0c0c7d70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c7d72;
P_0c0c7d72: /* original 6af6, guest PC 0x0c0c7d72 */
if(!s->budget--) { s->failed_pc=0x0c0c7d72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c7d74;
P_0c0c7d74: /* original 6bf6, guest PC 0x0c0c7d74 */
if(!s->budget--) { s->failed_pc=0x0c0c7d74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7d76;
P_0c0c7d76: /* original a033, guest PC 0x0c0c7d76 */
if(!s->budget--) { s->failed_pc=0x0c0c7d76u; return 0; }
goto P_0c0c7de0;
P_0c0c7d78: /* original 0009, guest PC 0x0c0c7d78 */
if(!s->budget--) { s->failed_pc=0x0c0c7d78u; return 0; }
if(!vf3_matrix_family(0x0c0c7d7au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7d7au; return 0; } return 1;
P_0c0c7de0: /* original 6cf6, guest PC 0x0c0c7de0 */
if(!s->budget--) { s->failed_pc=0x0c0c7de0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7de2;
P_0c0c7de2: /* original 6df6, guest PC 0x0c0c7de2 */
if(!s->budget--) { s->failed_pc=0x0c0c7de2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c7de4;
P_0c0c7de4: /* original a95e, guest PC 0x0c0c7de4 */
if(!s->budget--) { s->failed_pc=0x0c0c7de4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c70a4u,s,ram);
P_0c0c7de6: /* original 6ef6, guest PC 0x0c0c7de6 */
if(!s->budget--) { s->failed_pc=0x0c0c7de6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c7de8;
P_0c0c7de8: /* original d54a, guest PC 0x0c0c7de8 */
if(!s->budget--) { s->failed_pc=0x0c0c7de8u; return 0; }
r[5]=read(ram,0x0c0c7f14u,4);
goto P_0c0c7dea;
P_0c0c7dea: /* original e01c, guest PC 0x0c0c7dea */
if(!s->budget--) { s->failed_pc=0x0c0c7deau; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7dec;
P_0c0c7dec: /* original e30f, guest PC 0x0c0c7dec */
if(!s->budget--) { s->failed_pc=0x0c0c7decu; return 0; }
r[3]=0x0000000fu;
goto P_0c0c7dee;
P_0c0c7dee: /* original 9189, guest PC 0x0c0c7dee */
if(!s->budget--) { s->failed_pc=0x0c0c7deeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f04u,2);
goto P_0c0c7df0;
P_0c0c7df0: /* original 045c, guest PC 0x0c0c7df0 */
if(!s->budget--) { s->failed_pc=0x0c0c7df0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c7df2;
P_0c0c7df2: /* original d049, guest PC 0x0c0c7df2 */
if(!s->budget--) { s->failed_pc=0x0c0c7df2u; return 0; }
r[0]=read(ram,0x0c0c7f18u,4);
goto P_0c0c7df4;
P_0c0c7df4: /* original 315c, guest PC 0x0c0c7df4 */
if(!s->budget--) { s->failed_pc=0x0c0c7df4u; return 0; }
r[1]+=r[5];
goto P_0c0c7df6;
P_0c0c7df6: /* original 644c, guest PC 0x0c0c7df6 */
if(!s->budget--) { s->failed_pc=0x0c0c7df6u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c7df8;
P_0c0c7df8: /* original 2439, guest PC 0x0c0c7df8 */
if(!s->budget--) { s->failed_pc=0x0c0c7df8u; return 0; }
r[4]&=r[3];
goto P_0c0c7dfa;
P_0c0c7dfa: /* original 024c, guest PC 0x0c0c7dfa */
if(!s->budget--) { s->failed_pc=0x0c0c7dfau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7dfc;
P_0c0c7dfc: /* original 000b, guest PC 0x0c0c7dfc */
if(!s->budget--) { s->failed_pc=0x0c0c7dfcu; return 0; }
target=r[16];
write(ram,r[1],r[2],1);
s->pc=target; return ram->oob==0;
P_0c0c7dfe: /* original 2120, guest PC 0x0c0c7dfe */
if(!s->budget--) { s->failed_pc=0x0c0c7dfeu; return 0; }
write(ram,r[1],r[2],1);
return vf3_matrix_family(0x0c0c7e00u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
