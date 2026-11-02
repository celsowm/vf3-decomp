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
int vf3_away_batch167_adapter_29(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c0c7a00u: goto P_0c0c7a00;
case 0x0c0c7a02u: goto P_0c0c7a02;
case 0x0c0c7a04u: goto P_0c0c7a04;
case 0x0c0c7a06u: goto P_0c0c7a06;
case 0x0c0c7a08u: goto P_0c0c7a08;
case 0x0c0c7a0au: goto P_0c0c7a0a;
case 0x0c0c7a0cu: goto P_0c0c7a0c;
case 0x0c0c7a0eu: goto P_0c0c7a0e;
case 0x0c0c7a10u: goto P_0c0c7a10;
case 0x0c0c7a12u: goto P_0c0c7a12;
case 0x0c0c7a14u: goto P_0c0c7a14;
case 0x0c0c7a16u: goto P_0c0c7a16;
case 0x0c0c7a18u: goto P_0c0c7a18;
case 0x0c0c7a1au: goto P_0c0c7a1a;
case 0x0c0c7a1cu: goto P_0c0c7a1c;
case 0x0c0c7a1eu: goto P_0c0c7a1e;
case 0x0c0c7a20u: goto P_0c0c7a20;
case 0x0c0c7a22u: goto P_0c0c7a22;
case 0x0c0c7a24u: goto P_0c0c7a24;
case 0x0c0c7a26u: goto P_0c0c7a26;
case 0x0c0c7a28u: goto P_0c0c7a28;
case 0x0c0c7a2au: goto P_0c0c7a2a;
case 0x0c0c7a2cu: goto P_0c0c7a2c;
case 0x0c0c7a2eu: goto P_0c0c7a2e;
case 0x0c0c7a30u: goto P_0c0c7a30;
case 0x0c0c7a32u: goto P_0c0c7a32;
case 0x0c0c7a34u: goto P_0c0c7a34;
case 0x0c0c7a36u: goto P_0c0c7a36;
case 0x0c0c7a38u: goto P_0c0c7a38;
case 0x0c0c7a3au: goto P_0c0c7a3a;
case 0x0c0c7a3cu: goto P_0c0c7a3c;
case 0x0c0c7a3eu: goto P_0c0c7a3e;
case 0x0c0c7a40u: goto P_0c0c7a40;
case 0x0c0c7a42u: goto P_0c0c7a42;
case 0x0c0c7a44u: goto P_0c0c7a44;
case 0x0c0c7a46u: goto P_0c0c7a46;
case 0x0c0c7a48u: goto P_0c0c7a48;
case 0x0c0c7a4au: goto P_0c0c7a4a;
case 0x0c0c7a4cu: goto P_0c0c7a4c;
case 0x0c0c7a4eu: goto P_0c0c7a4e;
case 0x0c0c7a50u: goto P_0c0c7a50;
case 0x0c0c7a52u: goto P_0c0c7a52;
case 0x0c0c7a54u: goto P_0c0c7a54;
case 0x0c0c7a56u: goto P_0c0c7a56;
case 0x0c0c7a58u: goto P_0c0c7a58;
case 0x0c0c7a5au: goto P_0c0c7a5a;
case 0x0c0c7a5cu: goto P_0c0c7a5c;
case 0x0c0c7a5eu: goto P_0c0c7a5e;
case 0x0c0c7a60u: goto P_0c0c7a60;
case 0x0c0c7a62u: goto P_0c0c7a62;
case 0x0c0c7a64u: goto P_0c0c7a64;
case 0x0c0c7a66u: goto P_0c0c7a66;
case 0x0c0c7a68u: goto P_0c0c7a68;
case 0x0c0c7a6au: goto P_0c0c7a6a;
case 0x0c0c7a6cu: goto P_0c0c7a6c;
case 0x0c0c7a6eu: goto P_0c0c7a6e;
case 0x0c0c7a70u: goto P_0c0c7a70;
case 0x0c0c7a72u: goto P_0c0c7a72;
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
P_0c0c7a00: /* original 2fe6, guest PC 0x0c0c7a00 */
if(!s->budget--) { s->failed_pc=0x0c0c7a00u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7a02;
P_0c0c7a02: /* original 4511, guest PC 0x0c0c7a02 */
if(!s->budget--) { s->failed_pc=0x0c0c7a02u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c0c7a04;
P_0c0c7a04: /* original 2fd6, guest PC 0x0c0c7a04 */
if(!s->budget--) { s->failed_pc=0x0c0c7a04u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7a06;
P_0c0c7a06: /* original 2fc6, guest PC 0x0c0c7a06 */
if(!s->budget--) { s->failed_pc=0x0c0c7a06u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7a08;
P_0c0c7a08: /* original 2fb6, guest PC 0x0c0c7a08 */
if(!s->budget--) { s->failed_pc=0x0c0c7a08u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7a0a;
P_0c0c7a0a: /* original 2fa6, guest PC 0x0c0c7a0a */
if(!s->budget--) { s->failed_pc=0x0c0c7a0au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7a0c;
P_0c0c7a0c: /* original 2f96, guest PC 0x0c0c7a0c */
if(!s->budget--) { s->failed_pc=0x0c0c7a0cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7a0e;
P_0c0c7a0e: /* original 4f22, guest PC 0x0c0c7a0e */
if(!s->budget--) { s->failed_pc=0x0c0c7a0eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7a10;
P_0c0c7a10: /* original dc4a, guest PC 0x0c0c7a10 */
if(!s->budget--) { s->failed_pc=0x0c0c7a10u; return 0; }
r[12]=read(ram,0x0c0c7b3cu,4);
goto P_0c0c7a12;
P_0c0c7a12: /* original 8b27, guest PC 0x0c0c7a12 */
if(!s->budget--) { s->failed_pc=0x0c0c7a12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7a64; }
goto P_0c0c7a14;
P_0c0c7a14: /* original d34a, guest PC 0x0c0c7a14 */
if(!s->budget--) { s->failed_pc=0x0c0c7a14u; return 0; }
r[3]=read(ram,0x0c0c7b40u,4);
goto P_0c0c7a16;
P_0c0c7a16: /* original d24b, guest PC 0x0c0c7a16 */
if(!s->budget--) { s->failed_pc=0x0c0c7a16u; return 0; }
r[2]=read(ram,0x0c0c7b44u,4);
goto P_0c0c7a18;
P_0c0c7a18: /* original 9086, guest PC 0x0c0c7a18 */
if(!s->budget--) { s->failed_pc=0x0c0c7a18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7b28u,2);
goto P_0c0c7a1a;
P_0c0c7a1a: /* original 6522, guest PC 0x0c0c7a1a */
if(!s->budget--) { s->failed_pc=0x0c0c7a1au; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c0c7a1c;
P_0c0c7a1c: /* original d14a, guest PC 0x0c0c7a1c */
if(!s->budget--) { s->failed_pc=0x0c0c7a1cu; return 0; }
r[1]=read(ram,0x0c0c7b48u,4);
goto P_0c0c7a1e;
P_0c0c7a1e: /* original 0dce, guest PC 0x0c0c7a1e */
if(!s->budget--) { s->failed_pc=0x0c0c7a1eu; return 0; }
r[13]=read(ram,r[12]+r[0],4);
goto P_0c0c7a20;
P_0c0c7a20: /* original 6631, guest PC 0x0c0c7a20 */
if(!s->budget--) { s->failed_pc=0x0c0c7a20u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[6]=tmp;
goto P_0c0c7a22;
P_0c0c7a22: /* original 410b, guest PC 0x0c0c7a22 */
if(!s->budget--) { s->failed_pc=0x0c0c7a22u; return 0; }
target=r[1];
r[16]=code_base|0x0c0c7a26u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7a26u) { target=s->pc; goto dispatch; }
goto P_0c0c7a26;
P_0c0c7a24: /* original 64d3, guest PC 0x0c0c7a24 */
if(!s->budget--) { s->failed_pc=0x0c0c7a24u; return 0; }
r[4]=r[13];
goto P_0c0c7a26;
P_0c0c7a26: /* original da49, guest PC 0x0c0c7a26 */
if(!s->budget--) { s->failed_pc=0x0c0c7a26u; return 0; }
r[10]=read(ram,0x0c0c7b4cu,4);
goto P_0c0c7a28;
P_0c0c7a28: /* original 9b7f, guest PC 0x0c0c7a28 */
if(!s->budget--) { s->failed_pc=0x0c0c7a28u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7b2au,2);
goto P_0c0c7a2a;
P_0c0c7a2a: /* original 59d4, guest PC 0x0c0c7a2a */
if(!s->budget--) { s->failed_pc=0x0c0c7a2au; return 0; }
r[9]=read(ram,r[13]+16,4);
goto P_0c0c7a2c;
P_0c0c7a2c: /* original a007, guest PC 0x0c0c7a2c */
if(!s->budget--) { s->failed_pc=0x0c0c7a2cu; return 0; }
r[14]=0x00000000u;
goto P_0c0c7a3e;
P_0c0c7a2e: /* original ee00, guest PC 0x0c0c7a2e */
if(!s->budget--) { s->failed_pc=0x0c0c7a2eu; return 0; }
r[14]=0x00000000u;
goto P_0c0c7a30;
P_0c0c7a30: /* original 60e3, guest PC 0x0c0c7a30 */
if(!s->budget--) { s->failed_pc=0x0c0c7a30u; return 0; }
r[0]=r[14];
goto P_0c0c7a32;
P_0c0c7a32: /* original 4008, guest PC 0x0c0c7a32 */
if(!s->budget--) { s->failed_pc=0x0c0c7a32u; return 0; }
r[0]<<=2;
goto P_0c0c7a34;
P_0c0c7a34: /* original 059e, guest PC 0x0c0c7a34 */
if(!s->budget--) { s->failed_pc=0x0c0c7a34u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c0c7a36;
P_0c0c7a36: /* original 64b3, guest PC 0x0c0c7a36 */
if(!s->budget--) { s->failed_pc=0x0c0c7a36u; return 0; }
r[4]=r[11];
goto P_0c0c7a38;
P_0c0c7a38: /* original 4a0b, guest PC 0x0c0c7a38 */
if(!s->budget--) { s->failed_pc=0x0c0c7a38u; return 0; }
target=r[10];
r[16]=code_base|0x0c0c7a3cu;
r[11]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7a3cu) { target=s->pc; goto dispatch; }
goto P_0c0c7a3c;
P_0c0c7a3a: /* original 7b01, guest PC 0x0c0c7a3a */
if(!s->budget--) { s->failed_pc=0x0c0c7a3au; return 0; }
r[11]+=0x00000001u;
goto P_0c0c7a3c;
P_0c0c7a3c: /* original 7e01, guest PC 0x0c0c7a3c */
if(!s->budget--) { s->failed_pc=0x0c0c7a3cu; return 0; }
r[14]+=0x00000001u;
goto P_0c0c7a3e;
P_0c0c7a3e: /* original 85d6, guest PC 0x0c0c7a3e */
if(!s->budget--) { s->failed_pc=0x0c0c7a3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+12,2);
goto P_0c0c7a40;
P_0c0c7a40: /* original 600d, guest PC 0x0c0c7a40 */
if(!s->budget--) { s->failed_pc=0x0c0c7a40u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c7a42;
P_0c0c7a42: /* original 3e03, guest PC 0x0c0c7a42 */
if(!s->budget--) { s->failed_pc=0x0c0c7a42u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[0])!=0);
goto P_0c0c7a44;
P_0c0c7a44: /* original 8bf4, guest PC 0x0c0c7a44 */
if(!s->budget--) { s->failed_pc=0x0c0c7a44u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7a30; }
goto P_0c0c7a46;
P_0c0c7a46: /* original 906f, guest PC 0x0c0c7a46 */
if(!s->budget--) { s->failed_pc=0x0c0c7a46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7b28u,2);
goto P_0c0c7a48;
P_0c0c7a48: /* original 53d6, guest PC 0x0c0c7a48 */
if(!s->budget--) { s->failed_pc=0x0c0c7a48u; return 0; }
r[3]=read(ram,r[13]+24,4);
goto P_0c0c7a4a;
P_0c0c7a4a: /* original 02ce, guest PC 0x0c0c7a4a */
if(!s->budget--) { s->failed_pc=0x0c0c7a4au; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0c7a4c;
P_0c0c7a4c: /* original 7008, guest PC 0x0c0c7a4c */
if(!s->budget--) { s->failed_pc=0x0c0c7a4cu; return 0; }
r[0]+=0x00000008u;
goto P_0c0c7a4e;
P_0c0c7a4e: /* original 916d, guest PC 0x0c0c7a4e */
if(!s->budget--) { s->failed_pc=0x0c0c7a4eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7b2cu,2);
goto P_0c0c7a50;
P_0c0c7a50: /* original 323c, guest PC 0x0c0c7a50 */
if(!s->budget--) { s->failed_pc=0x0c0c7a50u; return 0; }
r[2]+=r[3];
goto P_0c0c7a52;
P_0c0c7a52: /* original 936c, guest PC 0x0c0c7a52 */
if(!s->budget--) { s->failed_pc=0x0c0c7a52u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7b2eu,2);
goto P_0c0c7a54;
P_0c0c7a54: /* original 321c, guest PC 0x0c0c7a54 */
if(!s->budget--) { s->failed_pc=0x0c0c7a54u; return 0; }
r[2]+=r[1];
goto P_0c0c7a56;
P_0c0c7a56: /* original 2239, guest PC 0x0c0c7a56 */
if(!s->budget--) { s->failed_pc=0x0c0c7a56u; return 0; }
r[2]&=r[3];
goto P_0c0c7a58;
P_0c0c7a58: /* original 0c26, guest PC 0x0c0c7a58 */
if(!s->budget--) { s->failed_pc=0x0c0c7a58u; return 0; }
write(ram,r[12]+r[0],r[2],4);
goto P_0c0c7a5a;
P_0c0c7a5a: /* original 7040, guest PC 0x0c0c7a5a */
if(!s->budget--) { s->failed_pc=0x0c0c7a5au; return 0; }
r[0]+=0x00000040u;
goto P_0c0c7a5c;
P_0c0c7a5c: /* original e1ff, guest PC 0x0c0c7a5c */
if(!s->budget--) { s->failed_pc=0x0c0c7a5cu; return 0; }
r[1]=0xffffffffu;
goto P_0c0c7a5e;
P_0c0c7a5e: /* original bed0, guest PC 0x0c0c7a5e */
if(!s->budget--) { s->failed_pc=0x0c0c7a5eu; return 0; }
target=code_base|0x0c0c7802u; r[16]=code_base|0x0c0c7a62u;
write(ram,r[12]+r[0],r[1],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7a62u) { target=s->pc; goto dispatch; }
goto P_0c0c7a62;
P_0c0c7a60: /* original 0c16, guest PC 0x0c0c7a60 */
if(!s->budget--) { s->failed_pc=0x0c0c7a60u; return 0; }
write(ram,r[12]+r[0],r[1],4);
goto P_0c0c7a62;
P_0c0c7a62: /* original e000, guest PC 0x0c0c7a62 */
if(!s->budget--) { s->failed_pc=0x0c0c7a62u; return 0; }
r[0]=0x00000000u;
goto P_0c0c7a64;
P_0c0c7a64: /* original 4f26, guest PC 0x0c0c7a64 */
if(!s->budget--) { s->failed_pc=0x0c0c7a64u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7a66;
P_0c0c7a66: /* original 69f6, guest PC 0x0c0c7a66 */
if(!s->budget--) { s->failed_pc=0x0c0c7a66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c7a68;
P_0c0c7a68: /* original 6af6, guest PC 0x0c0c7a68 */
if(!s->budget--) { s->failed_pc=0x0c0c7a68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c7a6a;
P_0c0c7a6a: /* original 6bf6, guest PC 0x0c0c7a6a */
if(!s->budget--) { s->failed_pc=0x0c0c7a6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7a6c;
P_0c0c7a6c: /* original 6cf6, guest PC 0x0c0c7a6c */
if(!s->budget--) { s->failed_pc=0x0c0c7a6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7a6e;
P_0c0c7a6e: /* original 6df6, guest PC 0x0c0c7a6e */
if(!s->budget--) { s->failed_pc=0x0c0c7a6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c7a70;
P_0c0c7a70: /* original 000b, guest PC 0x0c0c7a70 */
if(!s->budget--) { s->failed_pc=0x0c0c7a70u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c7a72: /* original 6ef6, guest PC 0x0c0c7a72 */
if(!s->budget--) { s->failed_pc=0x0c0c7a72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c7a74u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7a74u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
