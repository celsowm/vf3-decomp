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
int vf3_away_batch6_adapter_13(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04fa7cu: goto P_0c04fa7c;
case 0x0c04fa7eu: goto P_0c04fa7e;
case 0x0c04fa80u: goto P_0c04fa80;
case 0x0c04fa82u: goto P_0c04fa82;
case 0x0c04fa84u: goto P_0c04fa84;
case 0x0c04fa86u: goto P_0c04fa86;
case 0x0c04fa88u: goto P_0c04fa88;
case 0x0c04fa8au: goto P_0c04fa8a;
case 0x0c04fa8cu: goto P_0c04fa8c;
case 0x0c04fa8eu: goto P_0c04fa8e;
case 0x0c04fa90u: goto P_0c04fa90;
case 0x0c04fa92u: goto P_0c04fa92;
case 0x0c04fa94u: goto P_0c04fa94;
case 0x0c04fa96u: goto P_0c04fa96;
case 0x0c04fa98u: goto P_0c04fa98;
case 0x0c04fa9au: goto P_0c04fa9a;
case 0x0c04fa9cu: goto P_0c04fa9c;
case 0x0c04fa9eu: goto P_0c04fa9e;
case 0x0c04faa0u: goto P_0c04faa0;
case 0x0c04faa2u: goto P_0c04faa2;
case 0x0c04faa4u: goto P_0c04faa4;
case 0x0c04faa6u: goto P_0c04faa6;
case 0x0c04faa8u: goto P_0c04faa8;
case 0x0c04faaau: goto P_0c04faaa;
case 0x0c04faacu: goto P_0c04faac;
case 0x0c04faaeu: goto P_0c04faae;
case 0x0c04fe40u: goto P_0c04fe40;
case 0x0c04fe42u: goto P_0c04fe42;
case 0x0c04fe44u: goto P_0c04fe44;
case 0x0c04fe46u: goto P_0c04fe46;
case 0x0c04fe48u: goto P_0c04fe48;
case 0x0c04fe4au: goto P_0c04fe4a;
case 0x0c04fe4cu: goto P_0c04fe4c;
case 0x0c04fe4eu: goto P_0c04fe4e;
case 0x0c04fe50u: goto P_0c04fe50;
case 0x0c04fe52u: goto P_0c04fe52;
case 0x0c04fe54u: goto P_0c04fe54;
case 0x0c04fe56u: goto P_0c04fe56;
case 0x0c04fe58u: goto P_0c04fe58;
case 0x0c04fe5au: goto P_0c04fe5a;
case 0x0c04fe5cu: goto P_0c04fe5c;
case 0x0c04fe5eu: goto P_0c04fe5e;
case 0x0c04fe60u: goto P_0c04fe60;
case 0x0c04fe62u: goto P_0c04fe62;
case 0x0c04fe64u: goto P_0c04fe64;
case 0x0c04fe66u: goto P_0c04fe66;
case 0x0c04fe68u: goto P_0c04fe68;
case 0x0c04fe6au: goto P_0c04fe6a;
case 0x0c04fe6cu: goto P_0c04fe6c;
case 0x0c04fe6eu: goto P_0c04fe6e;
case 0x0c04fe70u: goto P_0c04fe70;
case 0x0c04fe72u: goto P_0c04fe72;
case 0x0c04fe74u: goto P_0c04fe74;
case 0x0c04fe76u: goto P_0c04fe76;
case 0x0c04fe78u: goto P_0c04fe78;
case 0x0c04fe7au: goto P_0c04fe7a;
case 0x0c04fe7cu: goto P_0c04fe7c;
case 0x0c04fe7eu: goto P_0c04fe7e;
case 0x0c04fe80u: goto P_0c04fe80;
case 0x0c04fe82u: goto P_0c04fe82;
case 0x0c04fe84u: goto P_0c04fe84;
case 0x0c04fe86u: goto P_0c04fe86;
case 0x0c04fe88u: goto P_0c04fe88;
case 0x0c04fe8au: goto P_0c04fe8a;
case 0x0c04fe8cu: goto P_0c04fe8c;
case 0x0c04fe8eu: goto P_0c04fe8e;
case 0x0c04fe90u: goto P_0c04fe90;
case 0x0c04fe92u: goto P_0c04fe92;
case 0x0c04fe94u: goto P_0c04fe94;
case 0x0c04fe96u: goto P_0c04fe96;
case 0x0c04fe98u: goto P_0c04fe98;
case 0x0c04fe9au: goto P_0c04fe9a;
case 0x0c04fe9cu: goto P_0c04fe9c;
case 0x0c04fe9eu: goto P_0c04fe9e;
case 0x0c04fea0u: goto P_0c04fea0;
case 0x0c04fea2u: goto P_0c04fea2;
case 0x0c04fea4u: goto P_0c04fea4;
case 0x0c04fea6u: goto P_0c04fea6;
case 0x0c04fea8u: goto P_0c04fea8;
case 0x0c04feaau: goto P_0c04feaa;
case 0x0c04feacu: goto P_0c04feac;
case 0x0c04feaeu: goto P_0c04feae;
case 0x0c04feb0u: goto P_0c04feb0;
case 0x0c04feb2u: goto P_0c04feb2;
case 0x0c04feb4u: goto P_0c04feb4;
case 0x0c04feb6u: goto P_0c04feb6;
case 0x0c04feb8u: goto P_0c04feb8;
case 0x0c04febau: goto P_0c04feba;
case 0x0c04febcu: goto P_0c04febc;
case 0x0c04febeu: goto P_0c04febe;
case 0x0c04fec0u: goto P_0c04fec0;
case 0x0c04fec2u: goto P_0c04fec2;
case 0x0c04ff62u: goto P_0c04ff62;
case 0x0c04ff64u: goto P_0c04ff64;
case 0x0c04ff66u: goto P_0c04ff66;
case 0x0c04ff68u: goto P_0c04ff68;
case 0x0c04ff6au: goto P_0c04ff6a;
case 0x0c04ff6cu: goto P_0c04ff6c;
case 0x0c04ff6eu: goto P_0c04ff6e;
case 0x0c04ff70u: goto P_0c04ff70;
case 0x0c04ff72u: goto P_0c04ff72;
case 0x0c04ff74u: goto P_0c04ff74;
case 0x0c04ff76u: goto P_0c04ff76;
case 0x0c04ff78u: goto P_0c04ff78;
case 0x0c04ff7au: goto P_0c04ff7a;
case 0x0c04ff7cu: goto P_0c04ff7c;
case 0x0c04ff7eu: goto P_0c04ff7e;
case 0x0c04ff80u: goto P_0c04ff80;
case 0x0c04ff82u: goto P_0c04ff82;
case 0x0c04ff84u: goto P_0c04ff84;
case 0x0c04ff86u: goto P_0c04ff86;
case 0x0c04ff88u: goto P_0c04ff88;
case 0x0c04ff8au: goto P_0c04ff8a;
case 0x0c04ff8cu: goto P_0c04ff8c;
case 0x0c04ff8eu: goto P_0c04ff8e;
case 0x0c04ff90u: goto P_0c04ff90;
case 0x0c04ff92u: goto P_0c04ff92;
case 0x0c04ff94u: goto P_0c04ff94;
case 0x0c04ff96u: goto P_0c04ff96;
case 0x0c04ff98u: goto P_0c04ff98;
case 0x0c04ff9au: goto P_0c04ff9a;
case 0x0c04ff9cu: goto P_0c04ff9c;
case 0x0c04ff9eu: goto P_0c04ff9e;
case 0x0c04ffa0u: goto P_0c04ffa0;
case 0x0c04ffa2u: goto P_0c04ffa2;
case 0x0c04ffa4u: goto P_0c04ffa4;
case 0x0c04ffa6u: goto P_0c04ffa6;
case 0x0c04ffa8u: goto P_0c04ffa8;
case 0x0c04ffaau: goto P_0c04ffaa;
case 0x0c04ffacu: goto P_0c04ffac;
case 0x0c04ffaeu: goto P_0c04ffae;
case 0x0c04ffb0u: goto P_0c04ffb0;
case 0x0c04ffb2u: goto P_0c04ffb2;
case 0x0c04ffb4u: goto P_0c04ffb4;
case 0x0c04ffb6u: goto P_0c04ffb6;
case 0x0c04ffb8u: goto P_0c04ffb8;
case 0x0c04ffbau: goto P_0c04ffba;
case 0x0c04ffbcu: goto P_0c04ffbc;
case 0x0c04ffbeu: goto P_0c04ffbe;
case 0x0c04ffc0u: goto P_0c04ffc0;
case 0x0c04ffc2u: goto P_0c04ffc2;
case 0x0c04ffc4u: goto P_0c04ffc4;
case 0x0c04ffc6u: goto P_0c04ffc6;
case 0x0c04ffc8u: goto P_0c04ffc8;
case 0x0c04ffcau: goto P_0c04ffca;
case 0x0c04ffccu: goto P_0c04ffcc;
case 0x0c04ffceu: goto P_0c04ffce;
case 0x0c04ffd0u: goto P_0c04ffd0;
case 0x0c04ffd2u: goto P_0c04ffd2;
case 0x0c04ffd4u: goto P_0c04ffd4;
case 0x0c04ffd6u: goto P_0c04ffd6;
case 0x0c04ffd8u: goto P_0c04ffd8;
case 0x0c04fffcu: goto P_0c04fffc;
case 0x0c04fffeu: goto P_0c04fffe;
case 0x0c050000u: goto P_0c050000;
case 0x0c050002u: goto P_0c050002;
case 0x0c050004u: goto P_0c050004;
case 0x0c050006u: goto P_0c050006;
case 0x0c050008u: goto P_0c050008;
case 0x0c05000au: goto P_0c05000a;
case 0x0c05000cu: goto P_0c05000c;
case 0x0c05000eu: goto P_0c05000e;
case 0x0c050010u: goto P_0c050010;
case 0x0c050012u: goto P_0c050012;
case 0x0c050014u: goto P_0c050014;
case 0x0c050016u: goto P_0c050016;
case 0x0c050018u: goto P_0c050018;
case 0x0c05001au: goto P_0c05001a;
case 0x0c05001cu: goto P_0c05001c;
case 0x0c05001eu: goto P_0c05001e;
case 0x0c050020u: goto P_0c050020;
case 0x0c050022u: goto P_0c050022;
case 0x0c050024u: goto P_0c050024;
case 0x0c050026u: goto P_0c050026;
case 0x0c050028u: goto P_0c050028;
case 0x0c05002au: goto P_0c05002a;
case 0x0c05002cu: goto P_0c05002c;
case 0x0c05002eu: goto P_0c05002e;
case 0x0c050030u: goto P_0c050030;
case 0x0c050032u: goto P_0c050032;
case 0x0c050034u: goto P_0c050034;
case 0x0c050036u: goto P_0c050036;
case 0x0c050038u: goto P_0c050038;
case 0x0c05003au: goto P_0c05003a;
case 0x0c05003cu: goto P_0c05003c;
case 0x0c05003eu: goto P_0c05003e;
case 0x0c050040u: goto P_0c050040;
case 0x0c050042u: goto P_0c050042;
case 0x0c050044u: goto P_0c050044;
case 0x0c050046u: goto P_0c050046;
case 0x0c050048u: goto P_0c050048;
case 0x0c05004au: goto P_0c05004a;
case 0x0c05004cu: goto P_0c05004c;
case 0x0c05004eu: goto P_0c05004e;
case 0x0c050050u: goto P_0c050050;
case 0x0c050052u: goto P_0c050052;
case 0x0c050054u: goto P_0c050054;
case 0x0c050056u: goto P_0c050056;
case 0x0c050058u: goto P_0c050058;
case 0x0c05005au: goto P_0c05005a;
case 0x0c05005cu: goto P_0c05005c;
case 0x0c05005eu: goto P_0c05005e;
case 0x0c050060u: goto P_0c050060;
case 0x0c050062u: goto P_0c050062;
case 0x0c050064u: goto P_0c050064;
case 0x0c050066u: goto P_0c050066;
case 0x0c050068u: goto P_0c050068;
case 0x0c05006au: goto P_0c05006a;
case 0x0c05006cu: goto P_0c05006c;
case 0x0c05006eu: goto P_0c05006e;
case 0x0c050070u: goto P_0c050070;
case 0x0c050072u: goto P_0c050072;
case 0x0c050074u: goto P_0c050074;
case 0x0c050076u: goto P_0c050076;
case 0x0c050078u: goto P_0c050078;
case 0x0c05007au: goto P_0c05007a;
case 0x0c05007cu: goto P_0c05007c;
case 0x0c05007eu: goto P_0c05007e;
case 0x0c050080u: goto P_0c050080;
case 0x0c050082u: goto P_0c050082;
case 0x0c050084u: goto P_0c050084;
case 0x0c050086u: goto P_0c050086;
case 0x0c050088u: goto P_0c050088;
case 0x0c05008au: goto P_0c05008a;
case 0x0c05008cu: goto P_0c05008c;
case 0x0c05008eu: goto P_0c05008e;
case 0x0c050090u: goto P_0c050090;
case 0x0c050092u: goto P_0c050092;
case 0x0c050094u: goto P_0c050094;
case 0x0c050096u: goto P_0c050096;
case 0x0c050098u: goto P_0c050098;
case 0x0c05009au: goto P_0c05009a;
case 0x0c05009cu: goto P_0c05009c;
case 0x0c05009eu: goto P_0c05009e;
case 0x0c0500a0u: goto P_0c0500a0;
case 0x0c0500a2u: goto P_0c0500a2;
case 0x0c0500a4u: goto P_0c0500a4;
case 0x0c0500a6u: goto P_0c0500a6;
case 0x0c0500a8u: goto P_0c0500a8;
case 0x0c0500aau: goto P_0c0500aa;
case 0x0c0500acu: goto P_0c0500ac;
case 0x0c0500aeu: goto P_0c0500ae;
case 0x0c0500b0u: goto P_0c0500b0;
case 0x0c0500b2u: goto P_0c0500b2;
case 0x0c0500b4u: goto P_0c0500b4;
case 0x0c0500b6u: goto P_0c0500b6;
case 0x0c0500b8u: goto P_0c0500b8;
case 0x0c0500bau: goto P_0c0500ba;
case 0x0c0500bcu: goto P_0c0500bc;
case 0x0c0500beu: goto P_0c0500be;
case 0x0c0500f0u: goto P_0c0500f0;
case 0x0c0500f2u: goto P_0c0500f2;
case 0x0c0500f4u: goto P_0c0500f4;
case 0x0c0500f6u: goto P_0c0500f6;
case 0x0c0500f8u: goto P_0c0500f8;
case 0x0c0500fau: goto P_0c0500fa;
case 0x0c0500fcu: goto P_0c0500fc;
case 0x0c0500feu: goto P_0c0500fe;
case 0x0c050100u: goto P_0c050100;
case 0x0c050102u: goto P_0c050102;
case 0x0c050104u: goto P_0c050104;
case 0x0c050106u: goto P_0c050106;
case 0x0c050108u: goto P_0c050108;
case 0x0c05010au: goto P_0c05010a;
case 0x0c05010cu: goto P_0c05010c;
case 0x0c05010eu: goto P_0c05010e;
case 0x0c050110u: goto P_0c050110;
case 0x0c050112u: goto P_0c050112;
case 0x0c050114u: goto P_0c050114;
case 0x0c050116u: goto P_0c050116;
case 0x0c050118u: goto P_0c050118;
case 0x0c05011au: goto P_0c05011a;
case 0x0c05011cu: goto P_0c05011c;
case 0x0c05011eu: goto P_0c05011e;
case 0x0c050120u: goto P_0c050120;
case 0x0c050122u: goto P_0c050122;
case 0x0c050124u: goto P_0c050124;
case 0x0c050126u: goto P_0c050126;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04fa7c: /* original 9632, guest PC 0x0c04fa7c */
if(!s->budget--) { s->failed_pc=0x0c04fa7cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fae4u,2);
goto P_0c04fa7e;
P_0c04fa7e: /* original 4f12, guest PC 0x0c04fa7e */
if(!s->budget--) { s->failed_pc=0x0c04fa7eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fa80;
P_0c04fa80: /* original 246f, guest PC 0x0c04fa80 */
if(!s->budget--) { s->failed_pc=0x0c04fa80u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[6]);
goto P_0c04fa82;
P_0c04fa82: /* original d31b, guest PC 0x0c04fa82 */
if(!s->budget--) { s->failed_pc=0x0c04fa82u; return 0; }
r[3]=read(ram,0x0c04faf0u,4);
goto P_0c04fa84;
P_0c04fa84: /* original 061a, guest PC 0x0c04fa84 */
if(!s->budget--) { s->failed_pc=0x0c04fa84u; return 0; }
r[6]=r[19];
goto P_0c04fa86;
P_0c04fa86: /* original 666f, guest PC 0x0c04fa86 */
if(!s->budget--) { s->failed_pc=0x0c04fa86u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c04fa88;
P_0c04fa88: /* original 363c, guest PC 0x0c04fa88 */
if(!s->budget--) { s->failed_pc=0x0c04fa88u; return 0; }
r[6]+=r[3];
goto P_0c04fa8a;
P_0c04fa8a: /* original 556a, guest PC 0x0c04fa8a */
if(!s->budget--) { s->failed_pc=0x0c04fa8au; return 0; }
r[5]=read(ram,r[6]+40,4);
goto P_0c04fa8c;
P_0c04fa8c: /* original a009, guest PC 0x0c04fa8c */
if(!s->budget--) { s->failed_pc=0x0c04fa8cu; return 0; }
r[4]=0x00000000u;
goto P_0c04faa2;
P_0c04fa8e: /* original e400, guest PC 0x0c04fa8e */
if(!s->budget--) { s->failed_pc=0x0c04fa8eu; return 0; }
r[4]=0x00000000u;
goto P_0c04fa90;
P_0c04fa90: /* original 6750, guest PC 0x0c04fa90 */
if(!s->budget--) { s->failed_pc=0x0c04fa90u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[7]=tmp;
goto P_0c04fa92;
P_0c04fa92: /* original 677c, guest PC 0x0c04fa92 */
if(!s->budget--) { s->failed_pc=0x0c04fa92u; return 0; }
r[7]=r[7]&255u;
goto P_0c04fa94;
P_0c04fa94: /* original 2778, guest PC 0x0c04fa94 */
if(!s->budget--) { s->failed_pc=0x0c04fa94u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c04fa96;
P_0c04fa96: /* original 8b02, guest PC 0x0c04fa96 */
if(!s->budget--) { s->failed_pc=0x0c04fa96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fa9e; }
goto P_0c04fa98;
P_0c04fa98: /* original 6043, guest PC 0x0c04fa98 */
if(!s->budget--) { s->failed_pc=0x0c04fa98u; return 0; }
r[0]=r[4];
goto P_0c04fa9a;
P_0c04fa9a: /* original 000b, guest PC 0x0c04fa9a */
if(!s->budget--) { s->failed_pc=0x0c04fa9au; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c04fa9c: /* original 4f16, guest PC 0x0c04fa9c */
if(!s->budget--) { s->failed_pc=0x0c04fa9cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fa9e;
P_0c04fa9e: /* original 7520, guest PC 0x0c04fa9e */
if(!s->budget--) { s->failed_pc=0x0c04fa9eu; return 0; }
r[5]+=0x00000020u;
goto P_0c04faa0;
P_0c04faa0: /* original 7401, guest PC 0x0c04faa0 */
if(!s->budget--) { s->failed_pc=0x0c04faa0u; return 0; }
r[4]+=0x00000001u;
goto P_0c04faa2;
P_0c04faa2: /* original 5267, guest PC 0x0c04faa2 */
if(!s->budget--) { s->failed_pc=0x0c04faa2u; return 0; }
r[2]=read(ram,r[6]+28,4);
goto P_0c04faa4;
P_0c04faa4: /* original 532c, guest PC 0x0c04faa4 */
if(!s->budget--) { s->failed_pc=0x0c04faa4u; return 0; }
r[3]=read(ram,r[2]+48,4);
goto P_0c04faa6;
P_0c04faa6: /* original 3433, guest PC 0x0c04faa6 */
if(!s->budget--) { s->failed_pc=0x0c04faa6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c04faa8;
P_0c04faa8: /* original 8bf2, guest PC 0x0c04faa8 */
if(!s->budget--) { s->failed_pc=0x0c04faa8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fa90; }
goto P_0c04faaa;
P_0c04faaa: /* original e0ff, guest PC 0x0c04faaa */
if(!s->budget--) { s->failed_pc=0x0c04faaau; return 0; }
r[0]=0xffffffffu;
goto P_0c04faac;
P_0c04faac: /* original 000b, guest PC 0x0c04faac */
if(!s->budget--) { s->failed_pc=0x0c04faacu; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c04faae: /* original 4f16, guest PC 0x0c04faae */
if(!s->budget--) { s->failed_pc=0x0c04faaeu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c04fab0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04fab0u; return 0; } return 1;
P_0c04fe40: /* original 2fe6, guest PC 0x0c04fe40 */
if(!s->budget--) { s->failed_pc=0x0c04fe40u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe42;
P_0c04fe42: /* original 2fd6, guest PC 0x0c04fe42 */
if(!s->budget--) { s->failed_pc=0x0c04fe42u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe44;
P_0c04fe44: /* original 6d53, guest PC 0x0c04fe44 */
if(!s->budget--) { s->failed_pc=0x0c04fe44u; return 0; }
r[13]=r[5];
goto P_0c04fe46;
P_0c04fe46: /* original 4f22, guest PC 0x0c04fe46 */
if(!s->budget--) { s->failed_pc=0x0c04fe46u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04fe48;
P_0c04fe48: /* original 4f12, guest PC 0x0c04fe48 */
if(!s->budget--) { s->failed_pc=0x0c04fe48u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fe4a;
P_0c04fe4a: /* original 7ffc, guest PC 0x0c04fe4a */
if(!s->budget--) { s->failed_pc=0x0c04fe4au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04fe4c;
P_0c04fe4c: /* original 2f61, guest PC 0x0c04fe4c */
if(!s->budget--) { s->failed_pc=0x0c04fe4cu; return 0; }
write(ram,r[15],r[6],2);
goto P_0c04fe4e;
P_0c04fe4e: /* original 9e39, guest PC 0x0c04fe4e */
if(!s->budget--) { s->failed_pc=0x0c04fe4eu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fec4u,2);
goto P_0c04fe50;
P_0c04fe50: /* original d31d, guest PC 0x0c04fe50 */
if(!s->budget--) { s->failed_pc=0x0c04fe50u; return 0; }
r[3]=read(ram,0x0c04fec8u,4);
goto P_0c04fe52;
P_0c04fe52: /* original 24ef, guest PC 0x0c04fe52 */
if(!s->budget--) { s->failed_pc=0x0c04fe52u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[14]);
goto P_0c04fe54;
P_0c04fe54: /* original 0e1a, guest PC 0x0c04fe54 */
if(!s->budget--) { s->failed_pc=0x0c04fe54u; return 0; }
r[14]=r[19];
goto P_0c04fe56;
P_0c04fe56: /* original 6eef, guest PC 0x0c04fe56 */
if(!s->budget--) { s->failed_pc=0x0c04fe56u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04fe58;
P_0c04fe58: /* original 3e3c, guest PC 0x0c04fe58 */
if(!s->budget--) { s->failed_pc=0x0c04fe58u; return 0; }
r[14]+=r[3];
goto P_0c04fe5a;
P_0c04fe5a: /* original 52e7, guest PC 0x0c04fe5a */
if(!s->budget--) { s->failed_pc=0x0c04fe5au; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04fe5c;
P_0c04fe5c: /* original 6122, guest PC 0x0c04fe5c */
if(!s->budget--) { s->failed_pc=0x0c04fe5cu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c04fe5e;
P_0c04fe5e: /* original 3d17, guest PC 0x0c04fe5e */
if(!s->budget--) { s->failed_pc=0x0c04fe5eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>(int32_t)r[1])!=0);
goto P_0c04fe60;
P_0c04fe60: /* original 8b0a, guest PC 0x0c04fe60 */
if(!s->budget--) { s->failed_pc=0x0c04fe60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fe78; }
goto P_0c04fe62;
P_0c04fe62: /* original 60f1, guest PC 0x0c04fe62 */
if(!s->budget--) { s->failed_pc=0x0c04fe62u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[0]=tmp;
goto P_0c04fe64;
P_0c04fe64: /* original 600d, guest PC 0x0c04fe64 */
if(!s->budget--) { s->failed_pc=0x0c04fe64u; return 0; }
r[0]=r[0]&65535u;
goto P_0c04fe66;
P_0c04fe66: /* original 2f06, guest PC 0x0c04fe66 */
if(!s->budget--) { s->failed_pc=0x0c04fe66u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe68;
P_0c04fe68: /* original 2fd6, guest PC 0x0c04fe68 */
if(!s->budget--) { s->failed_pc=0x0c04fe68u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe6a;
P_0c04fe6a: /* original 2f46, guest PC 0x0c04fe6a */
if(!s->budget--) { s->failed_pc=0x0c04fe6au; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe6c;
P_0c04fe6c: /* original d218, guest PC 0x0c04fe6c */
if(!s->budget--) { s->failed_pc=0x0c04fe6cu; return 0; }
r[2]=read(ram,0x0c04fed0u,4);
goto P_0c04fe6e;
P_0c04fe6e: /* original d119, guest PC 0x0c04fe6e */
if(!s->budget--) { s->failed_pc=0x0c04fe6eu; return 0; }
r[1]=read(ram,0x0c04fed4u,4);
goto P_0c04fe70;
P_0c04fe70: /* original 410b, guest PC 0x0c04fe70 */
if(!s->budget--) { s->failed_pc=0x0c04fe70u; return 0; }
target=r[1];
r[16]=code_base|0x0c04fe74u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fe74u) { target=s->pc; goto dispatch; }
goto P_0c04fe74;
P_0c04fe72: /* original 2f26, guest PC 0x0c04fe72 */
if(!s->budget--) { s->failed_pc=0x0c04fe72u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe74;
P_0c04fe74: /* original a00d, guest PC 0x0c04fe74 */
if(!s->budget--) { s->failed_pc=0x0c04fe74u; return 0; }
r[15]+=0x00000010u;
goto P_0c04fe92;
P_0c04fe76: /* original 7f10, guest PC 0x0c04fe76 */
if(!s->budget--) { s->failed_pc=0x0c04fe76u; return 0; }
r[15]+=0x00000010u;
goto P_0c04fe78;
P_0c04fe78: /* original 66f1, guest PC 0x0c04fe78 */
if(!s->budget--) { s->failed_pc=0x0c04fe78u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[6]=tmp;
goto P_0c04fe7a;
P_0c04fe7a: /* original 7f04, guest PC 0x0c04fe7a */
if(!s->budget--) { s->failed_pc=0x0c04fe7au; return 0; }
r[15]+=0x00000004u;
goto P_0c04fe7c;
P_0c04fe7c: /* original 4f16, guest PC 0x0c04fe7c */
if(!s->budget--) { s->failed_pc=0x0c04fe7cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fe7e;
P_0c04fe7e: /* original d113, guest PC 0x0c04fe7e */
if(!s->budget--) { s->failed_pc=0x0c04fe7eu; return 0; }
r[1]=read(ram,0x0c04feccu,4);
goto P_0c04fe80;
P_0c04fe80: /* original 65d3, guest PC 0x0c04fe80 */
if(!s->budget--) { s->failed_pc=0x0c04fe80u; return 0; }
r[5]=r[13];
goto P_0c04fe82;
P_0c04fe82: /* original 54e9, guest PC 0x0c04fe82 */
if(!s->budget--) { s->failed_pc=0x0c04fe82u; return 0; }
r[4]=read(ram,r[14]+36,4);
goto P_0c04fe84;
P_0c04fe84: /* original 4500, guest PC 0x0c04fe84 */
if(!s->budget--) { s->failed_pc=0x0c04fe84u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c04fe86;
P_0c04fe86: /* original 4f26, guest PC 0x0c04fe86 */
if(!s->budget--) { s->failed_pc=0x0c04fe86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fe88;
P_0c04fe88: /* original 6312, guest PC 0x0c04fe88 */
if(!s->budget--) { s->failed_pc=0x0c04fe88u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c04fe8a;
P_0c04fe8a: /* original 5234, guest PC 0x0c04fe8a */
if(!s->budget--) { s->failed_pc=0x0c04fe8au; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04fe8c;
P_0c04fe8c: /* original 6df6, guest PC 0x0c04fe8c */
if(!s->budget--) { s->failed_pc=0x0c04fe8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fe8e;
P_0c04fe8e: /* original 422b, guest PC 0x0c04fe8e */
if(!s->budget--) { s->failed_pc=0x0c04fe8eu; return 0; }
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
P_0c04fe90: /* original 6ef6, guest PC 0x0c04fe90 */
if(!s->budget--) { s->failed_pc=0x0c04fe90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04fe92;
P_0c04fe92: /* original 7f04, guest PC 0x0c04fe92 */
if(!s->budget--) { s->failed_pc=0x0c04fe92u; return 0; }
r[15]+=0x00000004u;
goto P_0c04fe94;
P_0c04fe94: /* original 4f16, guest PC 0x0c04fe94 */
if(!s->budget--) { s->failed_pc=0x0c04fe94u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fe96;
P_0c04fe96: /* original 4f26, guest PC 0x0c04fe96 */
if(!s->budget--) { s->failed_pc=0x0c04fe96u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fe98;
P_0c04fe98: /* original 6df6, guest PC 0x0c04fe98 */
if(!s->budget--) { s->failed_pc=0x0c04fe98u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fe9a;
P_0c04fe9a: /* original 000b, guest PC 0x0c04fe9a */
if(!s->budget--) { s->failed_pc=0x0c04fe9au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04fe9c: /* original 6ef6, guest PC 0x0c04fe9c */
if(!s->budget--) { s->failed_pc=0x0c04fe9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04fe9e;
P_0c04fe9e: /* original 4f12, guest PC 0x0c04fe9e */
if(!s->budget--) { s->failed_pc=0x0c04fe9eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fea0;
P_0c04fea0: /* original 7ff8, guest PC 0x0c04fea0 */
if(!s->budget--) { s->failed_pc=0x0c04fea0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c04fea2;
P_0c04fea2: /* original 2f52, guest PC 0x0c04fea2 */
if(!s->budget--) { s->failed_pc=0x0c04fea2u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c04fea4;
P_0c04fea4: /* original 930e, guest PC 0x0c04fea4 */
if(!s->budget--) { s->failed_pc=0x0c04fea4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fec4u,2);
goto P_0c04fea6;
P_0c04fea6: /* original d208, guest PC 0x0c04fea6 */
if(!s->budget--) { s->failed_pc=0x0c04fea6u; return 0; }
r[2]=read(ram,0x0c04fec8u,4);
goto P_0c04fea8;
P_0c04fea8: /* original 243f, guest PC 0x0c04fea8 */
if(!s->budget--) { s->failed_pc=0x0c04fea8u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c04feaa;
P_0c04feaa: /* original 041a, guest PC 0x0c04feaa */
if(!s->budget--) { s->failed_pc=0x0c04feaau; return 0; }
r[4]=r[19];
goto P_0c04feac;
P_0c04feac: /* original 644f, guest PC 0x0c04feac */
if(!s->budget--) { s->failed_pc=0x0c04feacu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c04feae;
P_0c04feae: /* original 342c, guest PC 0x0c04feae */
if(!s->budget--) { s->failed_pc=0x0c04feaeu; return 0; }
r[4]+=r[2];
goto P_0c04feb0;
P_0c04feb0: /* original 1f41, guest PC 0x0c04feb0 */
if(!s->budget--) { s->failed_pc=0x0c04feb0u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c04feb2;
P_0c04feb2: /* original d106, guest PC 0x0c04feb2 */
if(!s->budget--) { s->failed_pc=0x0c04feb2u; return 0; }
r[1]=read(ram,0x0c04feccu,4);
goto P_0c04feb4;
P_0c04feb4: /* original 65f2, guest PC 0x0c04feb4 */
if(!s->budget--) { s->failed_pc=0x0c04feb4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04feb6;
P_0c04feb6: /* original 7f08, guest PC 0x0c04feb6 */
if(!s->budget--) { s->failed_pc=0x0c04feb6u; return 0; }
r[15]+=0x00000008u;
goto P_0c04feb8;
P_0c04feb8: /* original 6012, guest PC 0x0c04feb8 */
if(!s->budget--) { s->failed_pc=0x0c04feb8u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c04feba;
P_0c04feba: /* original 5449, guest PC 0x0c04feba */
if(!s->budget--) { s->failed_pc=0x0c04febau; return 0; }
r[4]=read(ram,r[4]+36,4);
goto P_0c04febc;
P_0c04febc: /* original 4500, guest PC 0x0c04febc */
if(!s->budget--) { s->failed_pc=0x0c04febcu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c04febe;
P_0c04febe: /* original 5003, guest PC 0x0c04febe */
if(!s->budget--) { s->failed_pc=0x0c04febeu; return 0; }
r[0]=read(ram,r[0]+12,4);
goto P_0c04fec0;
P_0c04fec0: /* original 402b, guest PC 0x0c04fec0 */
if(!s->budget--) { s->failed_pc=0x0c04fec0u; return 0; }
target=r[0];
r[19]=read(ram,r[15],4); r[15]+=4;
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
P_0c04fec2: /* original 4f16, guest PC 0x0c04fec2 */
if(!s->budget--) { s->failed_pc=0x0c04fec2u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c04fec4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04fec4u; return 0; } return 1;
P_0c04ff62: /* original 933a, guest PC 0x0c04ff62 */
if(!s->budget--) { s->failed_pc=0x0c04ff62u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ffdau,2);
goto P_0c04ff64;
P_0c04ff64: /* original 6053, guest PC 0x0c04ff64 */
if(!s->budget--) { s->failed_pc=0x0c04ff64u; return 0; }
r[0]=r[5];
goto P_0c04ff66;
P_0c04ff66: /* original 4f12, guest PC 0x0c04ff66 */
if(!s->budget--) { s->failed_pc=0x0c04ff66u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04ff68;
P_0c04ff68: /* original 243f, guest PC 0x0c04ff68 */
if(!s->budget--) { s->failed_pc=0x0c04ff68u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c04ff6a;
P_0c04ff6a: /* original d21d, guest PC 0x0c04ff6a */
if(!s->budget--) { s->failed_pc=0x0c04ff6au; return 0; }
r[2]=read(ram,0x0c04ffe0u,4);
goto P_0c04ff6c;
P_0c04ff6c: /* original 4008, guest PC 0x0c04ff6c */
if(!s->budget--) { s->failed_pc=0x0c04ff6cu; return 0; }
r[0]<<=2;
goto P_0c04ff6e;
P_0c04ff6e: /* original 4008, guest PC 0x0c04ff6e */
if(!s->budget--) { s->failed_pc=0x0c04ff6eu; return 0; }
r[0]<<=2;
goto P_0c04ff70;
P_0c04ff70: /* original 4000, guest PC 0x0c04ff70 */
if(!s->budget--) { s->failed_pc=0x0c04ff70u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c04ff72;
P_0c04ff72: /* original 041a, guest PC 0x0c04ff72 */
if(!s->budget--) { s->failed_pc=0x0c04ff72u; return 0; }
r[4]=r[19];
goto P_0c04ff74;
P_0c04ff74: /* original 644f, guest PC 0x0c04ff74 */
if(!s->budget--) { s->failed_pc=0x0c04ff74u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c04ff76;
P_0c04ff76: /* original 342c, guest PC 0x0c04ff76 */
if(!s->budget--) { s->failed_pc=0x0c04ff76u; return 0; }
r[4]+=r[2];
goto P_0c04ff78;
P_0c04ff78: /* original 514a, guest PC 0x0c04ff78 */
if(!s->budget--) { s->failed_pc=0x0c04ff78u; return 0; }
r[1]=read(ram,r[4]+40,4);
goto P_0c04ff7a;
P_0c04ff7a: /* original 301c, guest PC 0x0c04ff7a */
if(!s->budget--) { s->failed_pc=0x0c04ff7au; return 0; }
r[0]+=r[1];
goto P_0c04ff7c;
P_0c04ff7c: /* original 000b, guest PC 0x0c04ff7c */
if(!s->budget--) { s->failed_pc=0x0c04ff7cu; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c04ff7e: /* original 4f16, guest PC 0x0c04ff7e */
if(!s->budget--) { s->failed_pc=0x0c04ff7eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ff80;
P_0c04ff80: /* original 932b, guest PC 0x0c04ff80 */
if(!s->budget--) { s->failed_pc=0x0c04ff80u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ffdau,2);
goto P_0c04ff82;
P_0c04ff82: /* original e1fc, guest PC 0x0c04ff82 */
if(!s->budget--) { s->failed_pc=0x0c04ff82u; return 0; }
r[1]=0xfffffffcu;
goto P_0c04ff84;
P_0c04ff84: /* original 4f12, guest PC 0x0c04ff84 */
if(!s->budget--) { s->failed_pc=0x0c04ff84u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04ff86;
P_0c04ff86: /* original 243f, guest PC 0x0c04ff86 */
if(!s->budget--) { s->failed_pc=0x0c04ff86u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c04ff88;
P_0c04ff88: /* original d215, guest PC 0x0c04ff88 */
if(!s->budget--) { s->failed_pc=0x0c04ff88u; return 0; }
r[2]=read(ram,0x0c04ffe0u,4);
goto P_0c04ff8a;
P_0c04ff8a: /* original 451c, guest PC 0x0c04ff8a */
if(!s->budget--) { s->failed_pc=0x0c04ff8au; return 0; }
r[5]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[5]>>((-r[1])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[1]&31u);
goto P_0c04ff8c;
P_0c04ff8c: /* original e101, guest PC 0x0c04ff8c */
if(!s->budget--) { s->failed_pc=0x0c04ff8cu; return 0; }
r[1]=0x00000001u;
goto P_0c04ff8e;
P_0c04ff8e: /* original 041a, guest PC 0x0c04ff8e */
if(!s->budget--) { s->failed_pc=0x0c04ff8eu; return 0; }
r[4]=r[19];
goto P_0c04ff90;
P_0c04ff90: /* original 644f, guest PC 0x0c04ff90 */
if(!s->budget--) { s->failed_pc=0x0c04ff90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c04ff92;
P_0c04ff92: /* original 342c, guest PC 0x0c04ff92 */
if(!s->budget--) { s->failed_pc=0x0c04ff92u; return 0; }
r[4]+=r[2];
goto P_0c04ff94;
P_0c04ff94: /* original 6043, guest PC 0x0c04ff94 */
if(!s->budget--) { s->failed_pc=0x0c04ff94u; return 0; }
r[0]=r[4];
goto P_0c04ff96;
P_0c04ff96: /* original 7048, guest PC 0x0c04ff96 */
if(!s->budget--) { s->failed_pc=0x0c04ff96u; return 0; }
r[0]+=0x00000048u;
goto P_0c04ff98;
P_0c04ff98: /* original 350c, guest PC 0x0c04ff98 */
if(!s->budget--) { s->failed_pc=0x0c04ff98u; return 0; }
r[5]+=r[0];
goto P_0c04ff9a;
P_0c04ff9a: /* original 2510, guest PC 0x0c04ff9a */
if(!s->budget--) { s->failed_pc=0x0c04ff9au; return 0; }
write(ram,r[5],r[1],1);
goto P_0c04ff9c;
P_0c04ff9c: /* original 000b, guest PC 0x0c04ff9c */
if(!s->budget--) { s->failed_pc=0x0c04ff9cu; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c04ff9e: /* original 4f16, guest PC 0x0c04ff9e */
if(!s->budget--) { s->failed_pc=0x0c04ff9eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ffa0;
P_0c04ffa0: /* original d713, guest PC 0x0c04ffa0 */
if(!s->budget--) { s->failed_pc=0x0c04ffa0u; return 0; }
r[7]=read(ram,0x0c04fff0u,4);
goto P_0c04ffa2;
P_0c04ffa2: /* original e601, guest PC 0x0c04ffa2 */
if(!s->budget--) { s->failed_pc=0x0c04ffa2u; return 0; }
r[6]=0x00000001u;
goto P_0c04ffa4;
P_0c04ffa4: /* original d411, guest PC 0x0c04ffa4 */
if(!s->budget--) { s->failed_pc=0x0c04ffa4u; return 0; }
r[4]=read(ram,0x0c04ffecu,4);
goto P_0c04ffa6;
P_0c04ffa6: /* original a009, guest PC 0x0c04ffa6 */
if(!s->budget--) { s->failed_pc=0x0c04ffa6u; return 0; }
r[5]=0x00000000u;
goto P_0c04ffbc;
P_0c04ffa8: /* original e500, guest PC 0x0c04ffa8 */
if(!s->budget--) { s->failed_pc=0x0c04ffa8u; return 0; }
r[5]=0x00000000u;
goto P_0c04ffaa;
P_0c04ffaa: /* original 6240, guest PC 0x0c04ffaa */
if(!s->budget--) { s->failed_pc=0x0c04ffaau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c04ffac;
P_0c04ffac: /* original 2228, guest PC 0x0c04ffac */
if(!s->budget--) { s->failed_pc=0x0c04ffacu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04ffae;
P_0c04ffae: /* original 8b03, guest PC 0x0c04ffae */
if(!s->budget--) { s->failed_pc=0x0c04ffaeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ffb8; }
goto P_0c04ffb0;
P_0c04ffb0: /* original 2460, guest PC 0x0c04ffb0 */
if(!s->budget--) { s->failed_pc=0x0c04ffb0u; return 0; }
write(ram,r[4],r[6],1);
goto P_0c04ffb2;
P_0c04ffb2: /* original 1453, guest PC 0x0c04ffb2 */
if(!s->budget--) { s->failed_pc=0x0c04ffb2u; return 0; }
write(ram,r[4]+12,r[5],4);
goto P_0c04ffb4;
P_0c04ffb4: /* original 000b, guest PC 0x0c04ffb4 */
if(!s->budget--) { s->failed_pc=0x0c04ffb4u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c04ffb6: /* original 6043, guest PC 0x0c04ffb6 */
if(!s->budget--) { s->failed_pc=0x0c04ffb6u; return 0; }
r[0]=r[4];
goto P_0c04ffb8;
P_0c04ffb8: /* original 7448, guest PC 0x0c04ffb8 */
if(!s->budget--) { s->failed_pc=0x0c04ffb8u; return 0; }
r[4]+=0x00000048u;
goto P_0c04ffba;
P_0c04ffba: /* original 7501, guest PC 0x0c04ffba */
if(!s->budget--) { s->failed_pc=0x0c04ffbau; return 0; }
r[5]+=0x00000001u;
goto P_0c04ffbc;
P_0c04ffbc: /* original 6372, guest PC 0x0c04ffbc */
if(!s->budget--) { s->failed_pc=0x0c04ffbcu; return 0; }
tmp=read(ram,r[7],4);
r[3]=tmp;
goto P_0c04ffbe;
P_0c04ffbe: /* original 3533, guest PC 0x0c04ffbe */
if(!s->budget--) { s->failed_pc=0x0c04ffbeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[3])!=0);
goto P_0c04ffc0;
P_0c04ffc0: /* original 8bf3, guest PC 0x0c04ffc0 */
if(!s->budget--) { s->failed_pc=0x0c04ffc0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ffaa; }
goto P_0c04ffc2;
P_0c04ffc2: /* original d20c, guest PC 0x0c04ffc2 */
if(!s->budget--) { s->failed_pc=0x0c04ffc2u; return 0; }
r[2]=read(ram,0x0c04fff4u,4);
goto P_0c04ffc4;
P_0c04ffc4: /* original e000, guest PC 0x0c04ffc4 */
if(!s->budget--) { s->failed_pc=0x0c04ffc4u; return 0; }
r[0]=0x00000000u;
goto P_0c04ffc6;
P_0c04ffc6: /* original 9109, guest PC 0x0c04ffc6 */
if(!s->budget--) { s->failed_pc=0x0c04ffc6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ffdcu,2);
goto P_0c04ffc8;
P_0c04ffc8: /* original 2212, guest PC 0x0c04ffc8 */
if(!s->budget--) { s->failed_pc=0x0c04ffc8u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c04ffca;
P_0c04ffca: /* original 000b, guest PC 0x0c04ffca */
if(!s->budget--) { s->failed_pc=0x0c04ffcau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c04ffcc: /* original 0009, guest PC 0x0c04ffcc */
if(!s->budget--) { s->failed_pc=0x0c04ffccu; return 0; }
goto P_0c04ffce;
P_0c04ffce: /* original d30a, guest PC 0x0c04ffce */
if(!s->budget--) { s->failed_pc=0x0c04ffceu; return 0; }
r[3]=read(ram,0x0c04fff8u,4);
goto P_0c04ffd0;
P_0c04ffd0: /* original e648, guest PC 0x0c04ffd0 */
if(!s->budget--) { s->failed_pc=0x0c04ffd0u; return 0; }
r[6]=0x00000048u;
goto P_0c04ffd2;
P_0c04ffd2: /* original 432b, guest PC 0x0c04ffd2 */
if(!s->budget--) { s->failed_pc=0x0c04ffd2u; return 0; }
target=r[3];
r[5]=0x00000000u;
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
P_0c04ffd4: /* original e500, guest PC 0x0c04ffd4 */
if(!s->budget--) { s->failed_pc=0x0c04ffd4u; return 0; }
r[5]=0x00000000u;
goto P_0c04ffd6;
P_0c04ffd6: /* original 000b, guest PC 0x0c04ffd6 */
if(!s->budget--) { s->failed_pc=0x0c04ffd6u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c04ffd8: /* original e000, guest PC 0x0c04ffd8 */
if(!s->budget--) { s->failed_pc=0x0c04ffd8u; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c04ffdau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04ffdau; return 0; } return 1;
P_0c04fffc: /* original 2fe6, guest PC 0x0c04fffc */
if(!s->budget--) { s->failed_pc=0x0c04fffcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fffe;
P_0c04fffe: /* original 6253, guest PC 0x0c04fffe */
if(!s->budget--) { s->failed_pc=0x0c04fffeu; return 0; }
r[2]=r[5];
goto P_0c050000;
P_0c050000: /* original 2fd6, guest PC 0x0c050000 */
if(!s->budget--) { s->failed_pc=0x0c050000u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050002;
P_0c050002: /* original 6d43, guest PC 0x0c050002 */
if(!s->budget--) { s->failed_pc=0x0c050002u; return 0; }
r[13]=r[4];
goto P_0c050004;
P_0c050004: /* original 2fc6, guest PC 0x0c050004 */
if(!s->budget--) { s->failed_pc=0x0c050004u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050006;
P_0c050006: /* original 2fb6, guest PC 0x0c050006 */
if(!s->budget--) { s->failed_pc=0x0c050006u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050008;
P_0c050008: /* original 4f22, guest PC 0x0c050008 */
if(!s->budget--) { s->failed_pc=0x0c050008u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05000a;
P_0c05000a: /* original 4f12, guest PC 0x0c05000a */
if(!s->budget--) { s->failed_pc=0x0c05000au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c05000c;
P_0c05000c: /* original 7fd0, guest PC 0x0c05000c */
if(!s->budget--) { s->failed_pc=0x0c05000cu; return 0; }
r[15]+=0xffffffd0u;
goto P_0c05000e;
P_0c05000e: /* original 2f52, guest PC 0x0c05000e */
if(!s->budget--) { s->failed_pc=0x0c05000eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c050010;
P_0c050010: /* original 9b56, guest PC 0x0c050010 */
if(!s->budget--) { s->failed_pc=0x0c050010u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0500c0u,2);
goto P_0c050012;
P_0c050012: /* original d32c, guest PC 0x0c050012 */
if(!s->budget--) { s->failed_pc=0x0c050012u; return 0; }
r[3]=read(ram,0x0c0500c4u,4);
goto P_0c050014;
P_0c050014: /* original 2dbf, guest PC 0x0c050014 */
if(!s->budget--) { s->failed_pc=0x0c050014u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[11]);
goto P_0c050016;
P_0c050016: /* original 2f56, guest PC 0x0c050016 */
if(!s->budget--) { s->failed_pc=0x0c050016u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050018;
P_0c050018: /* original 2fd6, guest PC 0x0c050018 */
if(!s->budget--) { s->failed_pc=0x0c050018u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05001a;
P_0c05001a: /* original d22b, guest PC 0x0c05001a */
if(!s->budget--) { s->failed_pc=0x0c05001au; return 0; }
r[2]=read(ram,0x0c0500c8u,4);
goto P_0c05001c;
P_0c05001c: /* original 0b1a, guest PC 0x0c05001c */
if(!s->budget--) { s->failed_pc=0x0c05001cu; return 0; }
r[11]=r[19];
goto P_0c05001e;
P_0c05001e: /* original d12b, guest PC 0x0c05001e */
if(!s->budget--) { s->failed_pc=0x0c05001eu; return 0; }
r[1]=read(ram,0x0c0500ccu,4);
goto P_0c050020;
P_0c050020: /* original 6bbf, guest PC 0x0c050020 */
if(!s->budget--) { s->failed_pc=0x0c050020u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c050022;
P_0c050022: /* original 3b3c, guest PC 0x0c050022 */
if(!s->budget--) { s->failed_pc=0x0c050022u; return 0; }
r[11]+=r[3];
goto P_0c050024;
P_0c050024: /* original 410b, guest PC 0x0c050024 */
if(!s->budget--) { s->failed_pc=0x0c050024u; return 0; }
target=r[1];
r[16]=code_base|0x0c050028u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050028u) { target=s->pc; goto dispatch; }
goto P_0c050028;
P_0c050026: /* original 2f26, guest PC 0x0c050026 */
if(!s->budget--) { s->failed_pc=0x0c050026u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050028;
P_0c050028: /* original 7f0c, guest PC 0x0c050028 */
if(!s->budget--) { s->failed_pc=0x0c050028u; return 0; }
r[15]+=0x0000000cu;
goto P_0c05002a;
P_0c05002a: /* original 65f2, guest PC 0x0c05002a */
if(!s->budget--) { s->failed_pc=0x0c05002au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c05002c;
P_0c05002c: /* original 66f3, guest PC 0x0c05002c */
if(!s->budget--) { s->failed_pc=0x0c05002cu; return 0; }
r[6]=r[15];
goto P_0c05002e;
P_0c05002e: /* original 7604, guest PC 0x0c05002e */
if(!s->budget--) { s->failed_pc=0x0c05002eu; return 0; }
r[6]+=0x00000004u;
goto P_0c050030;
P_0c050030: /* original bcad, guest PC 0x0c050030 */
if(!s->budget--) { s->failed_pc=0x0c050030u; return 0; }
target=code_base|0x0c04f98eu; r[16]=code_base|0x0c050034u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050034u) { target=s->pc; goto dispatch; }
goto P_0c050034;
P_0c050032: /* original 64d3, guest PC 0x0c050032 */
if(!s->budget--) { s->failed_pc=0x0c050032u; return 0; }
r[4]=r[13];
goto P_0c050034;
P_0c050034: /* original 6503, guest PC 0x0c050034 */
if(!s->budget--) { s->failed_pc=0x0c050034u; return 0; }
r[5]=r[0];
goto P_0c050036;
P_0c050036: /* original 4511, guest PC 0x0c050036 */
if(!s->budget--) { s->failed_pc=0x0c050036u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c050038;
P_0c050038: /* original 8902, guest PC 0x0c050038 */
if(!s->budget--) { s->failed_pc=0x0c050038u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c050040; }
goto P_0c05003a;
P_0c05003a: /* original 9042, guest PC 0x0c05003a */
if(!s->budget--) { s->failed_pc=0x0c05003au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0500c2u,2);
goto P_0c05003c;
P_0c05003c: /* original a06c, guest PC 0x0c05003c */
if(!s->budget--) { s->failed_pc=0x0c05003cu; return 0; }
goto P_0c050118;
P_0c05003e: /* original 0009, guest PC 0x0c05003e */
if(!s->budget--) { s->failed_pc=0x0c05003eu; return 0; }
goto P_0c050040;
P_0c050040: /* original bf8f, guest PC 0x0c050040 */
if(!s->budget--) { s->failed_pc=0x0c050040u; return 0; }
target=code_base|0x0c04ff62u; r[16]=code_base|0x0c050044u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050044u) { target=s->pc; goto dispatch; }
goto P_0c050044;
P_0c050042: /* original 64d3, guest PC 0x0c050042 */
if(!s->budget--) { s->failed_pc=0x0c050042u; return 0; }
r[4]=r[13];
goto P_0c050044;
P_0c050044: /* original 53b7, guest PC 0x0c050044 */
if(!s->budget--) { s->failed_pc=0x0c050044u; return 0; }
r[3]=read(ram,r[11]+28,4);
goto P_0c050046;
P_0c050046: /* original 5ef4, guest PC 0x0c050046 */
if(!s->budget--) { s->failed_pc=0x0c050046u; return 0; }
r[14]=read(ram,r[15]+16,4);
goto P_0c050048;
P_0c050048: /* original 523c, guest PC 0x0c050048 */
if(!s->budget--) { s->failed_pc=0x0c050048u; return 0; }
r[2]=read(ram,r[3]+48,4);
goto P_0c05004a;
P_0c05004a: /* original 3e23, guest PC 0x0c05004a */
if(!s->budget--) { s->failed_pc=0x0c05004au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c05004c;
P_0c05004c: /* original 890c, guest PC 0x0c05004c */
if(!s->budget--) { s->failed_pc=0x0c05004cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c050068; }
goto P_0c05004e;
P_0c05004e: /* original a05f, guest PC 0x0c05004e */
if(!s->budget--) { s->failed_pc=0x0c05004eu; return 0; }
r[12]=0x00000000u;
goto P_0c050110;
P_0c050050: /* original ec00, guest PC 0x0c050050 */
if(!s->budget--) { s->failed_pc=0x0c050050u; return 0; }
r[12]=0x00000000u;
goto P_0c050052;
P_0c050052: /* original 65e3, guest PC 0x0c050052 */
if(!s->budget--) { s->failed_pc=0x0c050052u; return 0; }
r[5]=r[14];
goto P_0c050054;
P_0c050054: /* original bf23, guest PC 0x0c050054 */
if(!s->budget--) { s->failed_pc=0x0c050054u; return 0; }
target=code_base|0x0c04fe9eu; r[16]=code_base|0x0c050058u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050058u) { target=s->pc; goto dispatch; }
goto P_0c050058;
P_0c050056: /* original 64d3, guest PC 0x0c050056 */
if(!s->budget--) { s->failed_pc=0x0c050056u; return 0; }
r[4]=r[13];
goto P_0c050058;
P_0c050058: /* original 52fb, guest PC 0x0c050058 */
if(!s->budget--) { s->failed_pc=0x0c050058u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c05005a;
P_0c05005a: /* original 640d, guest PC 0x0c05005a */
if(!s->budget--) { s->failed_pc=0x0c05005au; return 0; }
r[4]=r[0]&65535u;
goto P_0c05005c;
P_0c05005c: /* original d51c, guest PC 0x0c05005c */
if(!s->budget--) { s->failed_pc=0x0c05005cu; return 0; }
r[5]=read(ram,0x0c0500d0u,4);
goto P_0c05005e;
P_0c05005e: /* original 72ff, guest PC 0x0c05005e */
if(!s->budget--) { s->failed_pc=0x0c05005eu; return 0; }
r[2]+=0xffffffffu;
goto P_0c050060;
P_0c050060: /* original 3c20, guest PC 0x0c050060 */
if(!s->budget--) { s->failed_pc=0x0c050060u; return 0; }
r[17]=(r[17]&~1u)|((r[12]==r[2])!=0);
goto P_0c050062;
P_0c050062: /* original 8b08, guest PC 0x0c050062 */
if(!s->budget--) { s->failed_pc=0x0c050062u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050076; }
goto P_0c050064;
P_0c050064: /* original 3450, guest PC 0x0c050064 */
if(!s->budget--) { s->failed_pc=0x0c050064u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c050066;
P_0c050066: /* original 8951, guest PC 0x0c050066 */
if(!s->budget--) { s->failed_pc=0x0c050066u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05010c; }
goto P_0c050068;
P_0c050068: /* original dd1a, guest PC 0x0c050068 */
if(!s->budget--) { s->failed_pc=0x0c050068u; return 0; }
r[13]=read(ram,0x0c0500d4u,4);
goto P_0c05006a;
P_0c05006a: /* original 2fe6, guest PC 0x0c05006a */
if(!s->budget--) { s->failed_pc=0x0c05006au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05006c;
P_0c05006c: /* original d317, guest PC 0x0c05006c */
if(!s->budget--) { s->failed_pc=0x0c05006cu; return 0; }
r[3]=read(ram,0x0c0500ccu,4);
goto P_0c05006e;
P_0c05006e: /* original 430b, guest PC 0x0c05006e */
if(!s->budget--) { s->failed_pc=0x0c05006eu; return 0; }
target=r[3];
r[16]=code_base|0x0c050072u;
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050072u) { target=s->pc; goto dispatch; }
goto P_0c050072;
P_0c050070: /* original 2fd6, guest PC 0x0c050070 */
if(!s->budget--) { s->failed_pc=0x0c050070u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050072;
P_0c050072: /* original a048, guest PC 0x0c050072 */
if(!s->budget--) { s->failed_pc=0x0c050072u; return 0; }
r[15]+=0x00000008u;
goto P_0c050106;
P_0c050074: /* original 7f08, guest PC 0x0c050074 */
if(!s->budget--) { s->failed_pc=0x0c050074u; return 0; }
r[15]+=0x00000008u;
goto P_0c050076;
P_0c050076: /* original 34e0, guest PC 0x0c050076 */
if(!s->budget--) { s->failed_pc=0x0c050076u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[14])!=0);
goto P_0c050078;
P_0c050078: /* original 8b07, guest PC 0x0c050078 */
if(!s->budget--) { s->failed_pc=0x0c050078u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05008a; }
goto P_0c05007a;
P_0c05007a: /* original dd17, guest PC 0x0c05007a */
if(!s->budget--) { s->failed_pc=0x0c05007au; return 0; }
r[13]=read(ram,0x0c0500d8u,4);
goto P_0c05007c;
P_0c05007c: /* original 2fe6, guest PC 0x0c05007c */
if(!s->budget--) { s->failed_pc=0x0c05007cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05007e;
P_0c05007e: /* original 2f46, guest PC 0x0c05007e */
if(!s->budget--) { s->failed_pc=0x0c05007eu; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050080;
P_0c050080: /* original d312, guest PC 0x0c050080 */
if(!s->budget--) { s->failed_pc=0x0c050080u; return 0; }
r[3]=read(ram,0x0c0500ccu,4);
goto P_0c050082;
P_0c050082: /* original 430b, guest PC 0x0c050082 */
if(!s->budget--) { s->failed_pc=0x0c050082u; return 0; }
target=r[3];
r[16]=code_base|0x0c050086u;
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050086u) { target=s->pc; goto dispatch; }
goto P_0c050086;
P_0c050084: /* original 2fd6, guest PC 0x0c050084 */
if(!s->budget--) { s->failed_pc=0x0c050084u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050086;
P_0c050086: /* original a03e, guest PC 0x0c050086 */
if(!s->budget--) { s->failed_pc=0x0c050086u; return 0; }
r[15]+=0x0000000cu;
goto P_0c050106;
P_0c050088: /* original 7f0c, guest PC 0x0c050088 */
if(!s->budget--) { s->failed_pc=0x0c050088u; return 0; }
r[15]+=0x0000000cu;
goto P_0c05008a;
P_0c05008a: /* original 3450, guest PC 0x0c05008a */
if(!s->budget--) { s->failed_pc=0x0c05008au; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c05008c;
P_0c05008c: /* original 8b02, guest PC 0x0c05008c */
if(!s->budget--) { s->failed_pc=0x0c05008cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050094; }
goto P_0c05008e;
P_0c05008e: /* original dd13, guest PC 0x0c05008e */
if(!s->budget--) { s->failed_pc=0x0c05008eu; return 0; }
r[13]=read(ram,0x0c0500dcu,4);
goto P_0c050090;
P_0c050090: /* original aff4, guest PC 0x0c050090 */
if(!s->budget--) { s->failed_pc=0x0c050090u; return 0; }
goto P_0c05007c;
P_0c050092: /* original 0009, guest PC 0x0c050092 */
if(!s->budget--) { s->failed_pc=0x0c050092u; return 0; }
goto P_0c050094;
P_0c050094: /* original d512, guest PC 0x0c050094 */
if(!s->budget--) { s->failed_pc=0x0c050094u; return 0; }
r[5]=read(ram,0x0c0500e0u,4);
goto P_0c050096;
P_0c050096: /* original 3450, guest PC 0x0c050096 */
if(!s->budget--) { s->failed_pc=0x0c050096u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c050098;
P_0c050098: /* original 8b07, guest PC 0x0c050098 */
if(!s->budget--) { s->failed_pc=0x0c050098u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0500aa; }
goto P_0c05009a;
P_0c05009a: /* original dd12, guest PC 0x0c05009a */
if(!s->budget--) { s->failed_pc=0x0c05009au; return 0; }
r[13]=read(ram,0x0c0500e4u,4);
goto P_0c05009c;
P_0c05009c: /* original 2fe6, guest PC 0x0c05009c */
if(!s->budget--) { s->failed_pc=0x0c05009cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05009e;
P_0c05009e: /* original 2f46, guest PC 0x0c05009e */
if(!s->budget--) { s->failed_pc=0x0c05009eu; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500a0;
P_0c0500a0: /* original d20a, guest PC 0x0c0500a0 */
if(!s->budget--) { s->failed_pc=0x0c0500a0u; return 0; }
r[2]=read(ram,0x0c0500ccu,4);
goto P_0c0500a2;
P_0c0500a2: /* original 420b, guest PC 0x0c0500a2 */
if(!s->budget--) { s->failed_pc=0x0c0500a2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0500a6u;
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0500a6u) { target=s->pc; goto dispatch; }
goto P_0c0500a6;
P_0c0500a4: /* original 2fd6, guest PC 0x0c0500a4 */
if(!s->budget--) { s->failed_pc=0x0c0500a4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500a6;
P_0c0500a6: /* original a02e, guest PC 0x0c0500a6 */
if(!s->budget--) { s->failed_pc=0x0c0500a6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c050106;
P_0c0500a8: /* original 7f0c, guest PC 0x0c0500a8 */
if(!s->budget--) { s->failed_pc=0x0c0500a8u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0500aa;
P_0c0500aa: /* original d50f, guest PC 0x0c0500aa */
if(!s->budget--) { s->failed_pc=0x0c0500aau; return 0; }
r[5]=read(ram,0x0c0500e8u,4);
goto P_0c0500ac;
P_0c0500ac: /* original 3450, guest PC 0x0c0500ac */
if(!s->budget--) { s->failed_pc=0x0c0500acu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c0500ae;
P_0c0500ae: /* original 8b1f, guest PC 0x0c0500ae */
if(!s->budget--) { s->failed_pc=0x0c0500aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0500f0; }
goto P_0c0500b0;
P_0c0500b0: /* original dd0e, guest PC 0x0c0500b0 */
if(!s->budget--) { s->failed_pc=0x0c0500b0u; return 0; }
r[13]=read(ram,0x0c0500ecu,4);
goto P_0c0500b2;
P_0c0500b2: /* original 2fe6, guest PC 0x0c0500b2 */
if(!s->budget--) { s->failed_pc=0x0c0500b2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500b4;
P_0c0500b4: /* original 2f46, guest PC 0x0c0500b4 */
if(!s->budget--) { s->failed_pc=0x0c0500b4u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500b6;
P_0c0500b6: /* original d205, guest PC 0x0c0500b6 */
if(!s->budget--) { s->failed_pc=0x0c0500b6u; return 0; }
r[2]=read(ram,0x0c0500ccu,4);
goto P_0c0500b8;
P_0c0500b8: /* original 420b, guest PC 0x0c0500b8 */
if(!s->budget--) { s->failed_pc=0x0c0500b8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0500bcu;
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0500bcu) { target=s->pc; goto dispatch; }
goto P_0c0500bc;
P_0c0500ba: /* original 2fd6, guest PC 0x0c0500ba */
if(!s->budget--) { s->failed_pc=0x0c0500bau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500bc;
P_0c0500bc: /* original a023, guest PC 0x0c0500bc */
if(!s->budget--) { s->failed_pc=0x0c0500bcu; return 0; }
r[15]+=0x0000000cu;
goto P_0c050106;
P_0c0500be: /* original 7f0c, guest PC 0x0c0500be */
if(!s->budget--) { s->failed_pc=0x0c0500beu; return 0; }
r[15]+=0x0000000cu;
if(!vf3_matrix_family(0x0c0500c0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0500c0u; return 0; } return 1;
P_0c0500f0: /* original 52b7, guest PC 0x0c0500f0 */
if(!s->budget--) { s->failed_pc=0x0c0500f0u; return 0; }
r[2]=read(ram,r[11]+28,4);
goto P_0c0500f2;
P_0c0500f2: /* original 532c, guest PC 0x0c0500f2 */
if(!s->budget--) { s->failed_pc=0x0c0500f2u; return 0; }
r[3]=read(ram,r[2]+48,4);
goto P_0c0500f4;
P_0c0500f4: /* original 3433, guest PC 0x0c0500f4 */
if(!s->budget--) { s->failed_pc=0x0c0500f4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0500f6;
P_0c0500f6: /* original 8b09, guest PC 0x0c0500f6 */
if(!s->budget--) { s->failed_pc=0x0c0500f6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05010c; }
goto P_0c0500f8;
P_0c0500f8: /* original dd56, guest PC 0x0c0500f8 */
if(!s->budget--) { s->failed_pc=0x0c0500f8u; return 0; }
r[13]=read(ram,0x0c050254u,4);
goto P_0c0500fa;
P_0c0500fa: /* original 2fe6, guest PC 0x0c0500fa */
if(!s->budget--) { s->failed_pc=0x0c0500fau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500fc;
P_0c0500fc: /* original 2f46, guest PC 0x0c0500fc */
if(!s->budget--) { s->failed_pc=0x0c0500fcu; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500fe;
P_0c0500fe: /* original d356, guest PC 0x0c0500fe */
if(!s->budget--) { s->failed_pc=0x0c0500feu; return 0; }
r[3]=read(ram,0x0c050258u,4);
goto P_0c050100;
P_0c050100: /* original 430b, guest PC 0x0c050100 */
if(!s->budget--) { s->failed_pc=0x0c050100u; return 0; }
target=r[3];
r[16]=code_base|0x0c050104u;
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050104u) { target=s->pc; goto dispatch; }
goto P_0c050104;
P_0c050102: /* original 2fd6, guest PC 0x0c050102 */
if(!s->budget--) { s->failed_pc=0x0c050102u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050104;
P_0c050104: /* original 7f0c, guest PC 0x0c050104 */
if(!s->budget--) { s->failed_pc=0x0c050104u; return 0; }
r[15]+=0x0000000cu;
goto P_0c050106;
P_0c050106: /* original 90a3, guest PC 0x0c050106 */
if(!s->budget--) { s->failed_pc=0x0c050106u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c050250u,2);
goto P_0c050108;
P_0c050108: /* original a006, guest PC 0x0c050108 */
if(!s->budget--) { s->failed_pc=0x0c050108u; return 0; }
goto P_0c050118;
P_0c05010a: /* original 0009, guest PC 0x0c05010a */
if(!s->budget--) { s->failed_pc=0x0c05010au; return 0; }
goto P_0c05010c;
P_0c05010c: /* original 7c01, guest PC 0x0c05010c */
if(!s->budget--) { s->failed_pc=0x0c05010cu; return 0; }
r[12]+=0x00000001u;
goto P_0c05010e;
P_0c05010e: /* original 6e43, guest PC 0x0c05010e */
if(!s->budget--) { s->failed_pc=0x0c05010eu; return 0; }
r[14]=r[4];
goto P_0c050110;
P_0c050110: /* original 52fb, guest PC 0x0c050110 */
if(!s->budget--) { s->failed_pc=0x0c050110u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c050112;
P_0c050112: /* original 3c23, guest PC 0x0c050112 */
if(!s->budget--) { s->failed_pc=0x0c050112u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[2])!=0);
goto P_0c050114;
P_0c050114: /* original 8b9d, guest PC 0x0c050114 */
if(!s->budget--) { s->failed_pc=0x0c050114u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050052; }
goto P_0c050116;
P_0c050116: /* original e000, guest PC 0x0c050116 */
if(!s->budget--) { s->failed_pc=0x0c050116u; return 0; }
r[0]=0x00000000u;
goto P_0c050118;
P_0c050118: /* original 7f30, guest PC 0x0c050118 */
if(!s->budget--) { s->failed_pc=0x0c050118u; return 0; }
r[15]+=0x00000030u;
goto P_0c05011a;
P_0c05011a: /* original 4f16, guest PC 0x0c05011a */
if(!s->budget--) { s->failed_pc=0x0c05011au; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c05011c;
P_0c05011c: /* original 4f26, guest PC 0x0c05011c */
if(!s->budget--) { s->failed_pc=0x0c05011cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05011e;
P_0c05011e: /* original 6bf6, guest PC 0x0c05011e */
if(!s->budget--) { s->failed_pc=0x0c05011eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c050120;
P_0c050120: /* original 6cf6, guest PC 0x0c050120 */
if(!s->budget--) { s->failed_pc=0x0c050120u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c050122;
P_0c050122: /* original 6df6, guest PC 0x0c050122 */
if(!s->budget--) { s->failed_pc=0x0c050122u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c050124;
P_0c050124: /* original 000b, guest PC 0x0c050124 */
if(!s->budget--) { s->failed_pc=0x0c050124u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c050126: /* original 6ef6, guest PC 0x0c050126 */
if(!s->budget--) { s->failed_pc=0x0c050126u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c050128u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c050128u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
