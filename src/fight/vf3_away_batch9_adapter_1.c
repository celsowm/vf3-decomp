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
int vf3_away_batch9_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c064530u: goto P_0c064530;
case 0x0c064532u: goto P_0c064532;
case 0x0c064534u: goto P_0c064534;
case 0x0c064536u: goto P_0c064536;
case 0x0c064538u: goto P_0c064538;
case 0x0c06453au: goto P_0c06453a;
case 0x0c06453cu: goto P_0c06453c;
case 0x0c06453eu: goto P_0c06453e;
case 0x0c064540u: goto P_0c064540;
case 0x0c064542u: goto P_0c064542;
case 0x0c064544u: goto P_0c064544;
case 0x0c064546u: goto P_0c064546;
case 0x0c064548u: goto P_0c064548;
case 0x0c06454au: goto P_0c06454a;
case 0x0c06454cu: goto P_0c06454c;
case 0x0c06454eu: goto P_0c06454e;
case 0x0c064550u: goto P_0c064550;
case 0x0c064552u: goto P_0c064552;
case 0x0c064554u: goto P_0c064554;
case 0x0c064556u: goto P_0c064556;
case 0x0c064558u: goto P_0c064558;
case 0x0c06455au: goto P_0c06455a;
case 0x0c06455cu: goto P_0c06455c;
case 0x0c06455eu: goto P_0c06455e;
case 0x0c064560u: goto P_0c064560;
case 0x0c064562u: goto P_0c064562;
case 0x0c064564u: goto P_0c064564;
case 0x0c064566u: goto P_0c064566;
case 0x0c064568u: goto P_0c064568;
case 0x0c06456au: goto P_0c06456a;
case 0x0c06456cu: goto P_0c06456c;
case 0x0c06456eu: goto P_0c06456e;
case 0x0c064570u: goto P_0c064570;
case 0x0c064572u: goto P_0c064572;
case 0x0c064574u: goto P_0c064574;
case 0x0c064576u: goto P_0c064576;
case 0x0c064578u: goto P_0c064578;
case 0x0c06457au: goto P_0c06457a;
case 0x0c06457cu: goto P_0c06457c;
case 0x0c06457eu: goto P_0c06457e;
case 0x0c064580u: goto P_0c064580;
case 0x0c064582u: goto P_0c064582;
case 0x0c064584u: goto P_0c064584;
case 0x0c064586u: goto P_0c064586;
case 0x0c064588u: goto P_0c064588;
case 0x0c06458au: goto P_0c06458a;
case 0x0c06458cu: goto P_0c06458c;
case 0x0c06458eu: goto P_0c06458e;
case 0x0c064590u: goto P_0c064590;
case 0x0c064592u: goto P_0c064592;
case 0x0c065c40u: goto P_0c065c40;
case 0x0c065c42u: goto P_0c065c42;
case 0x0c065c44u: goto P_0c065c44;
case 0x0c065c46u: goto P_0c065c46;
case 0x0c065c48u: goto P_0c065c48;
case 0x0c065c4au: goto P_0c065c4a;
case 0x0c065c4cu: goto P_0c065c4c;
case 0x0c065c4eu: goto P_0c065c4e;
case 0x0c065c50u: goto P_0c065c50;
case 0x0c065c52u: goto P_0c065c52;
case 0x0c065c54u: goto P_0c065c54;
case 0x0c065c56u: goto P_0c065c56;
case 0x0c065c58u: goto P_0c065c58;
case 0x0c065c5au: goto P_0c065c5a;
case 0x0c065c5cu: goto P_0c065c5c;
case 0x0c065c5eu: goto P_0c065c5e;
case 0x0c065c60u: goto P_0c065c60;
case 0x0c065c62u: goto P_0c065c62;
case 0x0c065c64u: goto P_0c065c64;
case 0x0c065c66u: goto P_0c065c66;
case 0x0c065c68u: goto P_0c065c68;
case 0x0c065c6au: goto P_0c065c6a;
case 0x0c065c6cu: goto P_0c065c6c;
case 0x0c065c6eu: goto P_0c065c6e;
case 0x0c065c70u: goto P_0c065c70;
case 0x0c065c72u: goto P_0c065c72;
case 0x0c065c74u: goto P_0c065c74;
case 0x0c065c76u: goto P_0c065c76;
case 0x0c065c78u: goto P_0c065c78;
case 0x0c065c7au: goto P_0c065c7a;
case 0x0c065c7cu: goto P_0c065c7c;
case 0x0c065c7eu: goto P_0c065c7e;
case 0x0c065c80u: goto P_0c065c80;
case 0x0c065c82u: goto P_0c065c82;
case 0x0c065c84u: goto P_0c065c84;
case 0x0c065c86u: goto P_0c065c86;
case 0x0c065c88u: goto P_0c065c88;
case 0x0c065c8au: goto P_0c065c8a;
case 0x0c065c8cu: goto P_0c065c8c;
case 0x0c065c8eu: goto P_0c065c8e;
case 0x0c065c90u: goto P_0c065c90;
case 0x0c065c92u: goto P_0c065c92;
case 0x0c065c94u: goto P_0c065c94;
case 0x0c065c96u: goto P_0c065c96;
case 0x0c065c98u: goto P_0c065c98;
case 0x0c065c9au: goto P_0c065c9a;
case 0x0c065c9cu: goto P_0c065c9c;
case 0x0c065c9eu: goto P_0c065c9e;
case 0x0c065ca0u: goto P_0c065ca0;
case 0x0c065ca2u: goto P_0c065ca2;
case 0x0c065ca4u: goto P_0c065ca4;
case 0x0c065ca6u: goto P_0c065ca6;
case 0x0c065ca8u: goto P_0c065ca8;
case 0x0c065caau: goto P_0c065caa;
case 0x0c065cacu: goto P_0c065cac;
case 0x0c065caeu: goto P_0c065cae;
case 0x0c065cb0u: goto P_0c065cb0;
case 0x0c065cb2u: goto P_0c065cb2;
case 0x0c065cb4u: goto P_0c065cb4;
case 0x0c065cb6u: goto P_0c065cb6;
case 0x0c065cb8u: goto P_0c065cb8;
case 0x0c065cbau: goto P_0c065cba;
case 0x0c065cbcu: goto P_0c065cbc;
case 0x0c065cbeu: goto P_0c065cbe;
case 0x0c065cc0u: goto P_0c065cc0;
case 0x0c065cc2u: goto P_0c065cc2;
case 0x0c065cc4u: goto P_0c065cc4;
case 0x0c065cc6u: goto P_0c065cc6;
case 0x0c065cc8u: goto P_0c065cc8;
case 0x0c065ccau: goto P_0c065cca;
case 0x0c065cccu: goto P_0c065ccc;
case 0x0c065cceu: goto P_0c065cce;
case 0x0c065cd0u: goto P_0c065cd0;
case 0x0c065cd2u: goto P_0c065cd2;
case 0x0c065cd4u: goto P_0c065cd4;
case 0x0c065cd6u: goto P_0c065cd6;
case 0x0c065cd8u: goto P_0c065cd8;
case 0x0c065cdau: goto P_0c065cda;
case 0x0c065cdcu: goto P_0c065cdc;
case 0x0c065cdeu: goto P_0c065cde;
case 0x0c065ce0u: goto P_0c065ce0;
case 0x0c065ce2u: goto P_0c065ce2;
case 0x0c065ce4u: goto P_0c065ce4;
case 0x0c065ce6u: goto P_0c065ce6;
case 0x0c065ce8u: goto P_0c065ce8;
case 0x0c065ceau: goto P_0c065cea;
case 0x0c065cecu: goto P_0c065cec;
case 0x0c065ceeu: goto P_0c065cee;
case 0x0c065cf0u: goto P_0c065cf0;
case 0x0c065cf2u: goto P_0c065cf2;
case 0x0c065cf4u: goto P_0c065cf4;
case 0x0c065cf6u: goto P_0c065cf6;
case 0x0c065cf8u: goto P_0c065cf8;
case 0x0c065cfau: goto P_0c065cfa;
case 0x0c065cfcu: goto P_0c065cfc;
case 0x0c065cfeu: goto P_0c065cfe;
case 0x0c065d00u: goto P_0c065d00;
case 0x0c065d02u: goto P_0c065d02;
case 0x0c065d04u: goto P_0c065d04;
case 0x0c065d06u: goto P_0c065d06;
case 0x0c065d08u: goto P_0c065d08;
case 0x0c065d0au: goto P_0c065d0a;
case 0x0c065d0cu: goto P_0c065d0c;
case 0x0c065d0eu: goto P_0c065d0e;
case 0x0c065d10u: goto P_0c065d10;
case 0x0c065d12u: goto P_0c065d12;
case 0x0c065d14u: goto P_0c065d14;
case 0x0c065d16u: goto P_0c065d16;
case 0x0c065d18u: goto P_0c065d18;
case 0x0c065d1au: goto P_0c065d1a;
case 0x0c065d1cu: goto P_0c065d1c;
case 0x0c065d1eu: goto P_0c065d1e;
case 0x0c065d20u: goto P_0c065d20;
case 0x0c065d22u: goto P_0c065d22;
case 0x0c065d24u: goto P_0c065d24;
case 0x0c065d26u: goto P_0c065d26;
case 0x0c065d28u: goto P_0c065d28;
case 0x0c065d2au: goto P_0c065d2a;
case 0x0c065d2cu: goto P_0c065d2c;
case 0x0c065d2eu: goto P_0c065d2e;
case 0x0c065d30u: goto P_0c065d30;
case 0x0c065d32u: goto P_0c065d32;
case 0x0c065d34u: goto P_0c065d34;
case 0x0c065d36u: goto P_0c065d36;
case 0x0c065d38u: goto P_0c065d38;
case 0x0c065d3au: goto P_0c065d3a;
case 0x0c065d3cu: goto P_0c065d3c;
case 0x0c065d3eu: goto P_0c065d3e;
case 0x0c065d40u: goto P_0c065d40;
case 0x0c065d42u: goto P_0c065d42;
case 0x0c065d44u: goto P_0c065d44;
case 0x0c065d46u: goto P_0c065d46;
case 0x0c065d48u: goto P_0c065d48;
case 0x0c065d4au: goto P_0c065d4a;
case 0x0c065d4cu: goto P_0c065d4c;
case 0x0c065d4eu: goto P_0c065d4e;
case 0x0c065d50u: goto P_0c065d50;
case 0x0c065d52u: goto P_0c065d52;
case 0x0c065d54u: goto P_0c065d54;
case 0x0c065d56u: goto P_0c065d56;
case 0x0c065d58u: goto P_0c065d58;
case 0x0c065d5au: goto P_0c065d5a;
case 0x0c065d5cu: goto P_0c065d5c;
case 0x0c065d5eu: goto P_0c065d5e;
case 0x0c065d60u: goto P_0c065d60;
case 0x0c065d62u: goto P_0c065d62;
case 0x0c065d64u: goto P_0c065d64;
case 0x0c065d66u: goto P_0c065d66;
case 0x0c065d68u: goto P_0c065d68;
case 0x0c065d6au: goto P_0c065d6a;
case 0x0c065d6cu: goto P_0c065d6c;
case 0x0c065d6eu: goto P_0c065d6e;
case 0x0c065d70u: goto P_0c065d70;
case 0x0c065d72u: goto P_0c065d72;
case 0x0c065d74u: goto P_0c065d74;
case 0x0c065d76u: goto P_0c065d76;
case 0x0c065d78u: goto P_0c065d78;
case 0x0c065d7au: goto P_0c065d7a;
case 0x0c065d7cu: goto P_0c065d7c;
case 0x0c065d7eu: goto P_0c065d7e;
case 0x0c065d80u: goto P_0c065d80;
case 0x0c065d82u: goto P_0c065d82;
case 0x0c065d84u: goto P_0c065d84;
case 0x0c065d86u: goto P_0c065d86;
case 0x0c065d88u: goto P_0c065d88;
case 0x0c065d8au: goto P_0c065d8a;
case 0x0c065d8cu: goto P_0c065d8c;
case 0x0c065d8eu: goto P_0c065d8e;
case 0x0c065d90u: goto P_0c065d90;
case 0x0c065d92u: goto P_0c065d92;
case 0x0c065d94u: goto P_0c065d94;
case 0x0c065d96u: goto P_0c065d96;
case 0x0c065d98u: goto P_0c065d98;
case 0x0c065d9au: goto P_0c065d9a;
case 0x0c065d9cu: goto P_0c065d9c;
case 0x0c065d9eu: goto P_0c065d9e;
case 0x0c065da0u: goto P_0c065da0;
case 0x0c065da2u: goto P_0c065da2;
case 0x0c065da4u: goto P_0c065da4;
case 0x0c065da6u: goto P_0c065da6;
case 0x0c065da8u: goto P_0c065da8;
case 0x0c065daau: goto P_0c065daa;
default: return vf3_matrix_family(target,s,ram);
}
P_0c064530: /* original d375, guest PC 0x0c064530 */
if(!s->budget--) { s->failed_pc=0x0c064530u; return 0; }
r[3]=read(ram,0x0c064708u,4);
goto P_0c064532;
P_0c064532: /* original 2438, guest PC 0x0c064532 */
if(!s->budget--) { s->failed_pc=0x0c064532u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c064534;
P_0c064534: /* original 8904, guest PC 0x0c064534 */
if(!s->budget--) { s->failed_pc=0x0c064534u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064540; }
goto P_0c064536;
P_0c064536: /* original 6153, guest PC 0x0c064536 */
if(!s->budget--) { s->failed_pc=0x0c064536u; return 0; }
r[1]=r[5];
goto P_0c064538;
P_0c064538: /* original d075, guest PC 0x0c064538 */
if(!s->budget--) { s->failed_pc=0x0c064538u; return 0; }
r[0]=read(ram,0x0c064710u,4);
goto P_0c06453a;
P_0c06453a: /* original 7501, guest PC 0x0c06453a */
if(!s->budget--) { s->failed_pc=0x0c06453au; return 0; }
r[5]+=0x00000001u;
goto P_0c06453c;
P_0c06453c: /* original 4108, guest PC 0x0c06453c */
if(!s->budget--) { s->failed_pc=0x0c06453cu; return 0; }
r[1]<<=2;
goto P_0c06453e;
P_0c06453e: /* original 0166, guest PC 0x0c06453e */
if(!s->budget--) { s->failed_pc=0x0c06453eu; return 0; }
write(ram,r[1]+r[0],r[6],4);
goto P_0c064540;
P_0c064540: /* original 000b, guest PC 0x0c064540 */
if(!s->budget--) { s->failed_pc=0x0c064540u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c064542: /* original 6053, guest PC 0x0c064542 */
if(!s->budget--) { s->failed_pc=0x0c064542u; return 0; }
r[0]=r[5];
goto P_0c064544;
P_0c064544: /* original d36f, guest PC 0x0c064544 */
if(!s->budget--) { s->failed_pc=0x0c064544u; return 0; }
r[3]=read(ram,0x0c064704u,4);
goto P_0c064546;
P_0c064546: /* original 2348, guest PC 0x0c064546 */
if(!s->budget--) { s->failed_pc=0x0c064546u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c064548;
P_0c064548: /* original 8914, guest PC 0x0c064548 */
if(!s->budget--) { s->failed_pc=0x0c064548u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064574; }
goto P_0c06454a;
P_0c06454a: /* original d170, guest PC 0x0c06454a */
if(!s->budget--) { s->failed_pc=0x0c06454au; return 0; }
r[1]=read(ram,0x0c06470cu,4);
goto P_0c06454c;
P_0c06454c: /* original 2418, guest PC 0x0c06454c */
if(!s->budget--) { s->failed_pc=0x0c06454cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[1])==0)!=0);
goto P_0c06454e;
P_0c06454e: /* original 8904, guest PC 0x0c06454e */
if(!s->budget--) { s->failed_pc=0x0c06454eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06455a; }
goto P_0c064550;
P_0c064550: /* original d06f, guest PC 0x0c064550 */
if(!s->budget--) { s->failed_pc=0x0c064550u; return 0; }
r[0]=read(ram,0x0c064710u,4);
goto P_0c064552;
P_0c064552: /* original 6253, guest PC 0x0c064552 */
if(!s->budget--) { s->failed_pc=0x0c064552u; return 0; }
r[2]=r[5];
goto P_0c064554;
P_0c064554: /* original 7501, guest PC 0x0c064554 */
if(!s->budget--) { s->failed_pc=0x0c064554u; return 0; }
r[5]+=0x00000001u;
goto P_0c064556;
P_0c064556: /* original a00c, guest PC 0x0c064556 */
if(!s->budget--) { s->failed_pc=0x0c064556u; return 0; }
r[2]<<=2;
goto P_0c064572;
P_0c064558: /* original 4208, guest PC 0x0c064558 */
if(!s->budget--) { s->failed_pc=0x0c064558u; return 0; }
r[2]<<=2;
goto P_0c06455a;
P_0c06455a: /* original 6253, guest PC 0x0c06455a */
if(!s->budget--) { s->failed_pc=0x0c06455au; return 0; }
r[2]=r[5];
goto P_0c06455c;
P_0c06455c: /* original d36d, guest PC 0x0c06455c */
if(!s->budget--) { s->failed_pc=0x0c06455cu; return 0; }
r[3]=read(ram,0x0c064714u,4);
goto P_0c06455e;
P_0c06455e: /* original 7501, guest PC 0x0c06455e */
if(!s->budget--) { s->failed_pc=0x0c06455eu; return 0; }
r[5]+=0x00000001u;
goto P_0c064560;
P_0c064560: /* original d06b, guest PC 0x0c064560 */
if(!s->budget--) { s->failed_pc=0x0c064560u; return 0; }
r[0]=read(ram,0x0c064710u,4);
goto P_0c064562;
P_0c064562: /* original 4208, guest PC 0x0c064562 */
if(!s->budget--) { s->failed_pc=0x0c064562u; return 0; }
r[2]<<=2;
goto P_0c064564;
P_0c064564: /* original 2369, guest PC 0x0c064564 */
if(!s->budget--) { s->failed_pc=0x0c064564u; return 0; }
r[3]&=r[6];
goto P_0c064566;
P_0c064566: /* original 0236, guest PC 0x0c064566 */
if(!s->budget--) { s->failed_pc=0x0c064566u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064568;
P_0c064568: /* original 6253, guest PC 0x0c064568 */
if(!s->budget--) { s->failed_pc=0x0c064568u; return 0; }
r[2]=r[5];
goto P_0c06456a;
P_0c06456a: /* original 7501, guest PC 0x0c06456a */
if(!s->budget--) { s->failed_pc=0x0c06456au; return 0; }
r[5]+=0x00000001u;
goto P_0c06456c;
P_0c06456c: /* original 4208, guest PC 0x0c06456c */
if(!s->budget--) { s->failed_pc=0x0c06456cu; return 0; }
r[2]<<=2;
goto P_0c06456e;
P_0c06456e: /* original 666d, guest PC 0x0c06456e */
if(!s->budget--) { s->failed_pc=0x0c06456eu; return 0; }
r[6]=r[6]&65535u;
goto P_0c064570;
P_0c064570: /* original 4628, guest PC 0x0c064570 */
if(!s->budget--) { s->failed_pc=0x0c064570u; return 0; }
r[6]<<=16;
goto P_0c064572;
P_0c064572: /* original 0266, guest PC 0x0c064572 */
if(!s->budget--) { s->failed_pc=0x0c064572u; return 0; }
write(ram,r[2]+r[0],r[6],4);
goto P_0c064574;
P_0c064574: /* original 000b, guest PC 0x0c064574 */
if(!s->budget--) { s->failed_pc=0x0c064574u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c064576: /* original 6053, guest PC 0x0c064576 */
if(!s->budget--) { s->failed_pc=0x0c064576u; return 0; }
r[0]=r[5];
goto P_0c064578;
P_0c064578: /* original d362, guest PC 0x0c064578 */
if(!s->budget--) { s->failed_pc=0x0c064578u; return 0; }
r[3]=read(ram,0x0c064704u,4);
goto P_0c06457a;
P_0c06457a: /* original 2438, guest PC 0x0c06457a */
if(!s->budget--) { s->failed_pc=0x0c06457au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c06457c;
P_0c06457c: /* original 8908, guest PC 0x0c06457c */
if(!s->budget--) { s->failed_pc=0x0c06457cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064590; }
goto P_0c06457e;
P_0c06457e: /* original 6153, guest PC 0x0c06457e */
if(!s->budget--) { s->failed_pc=0x0c06457eu; return 0; }
r[1]=r[5];
goto P_0c064580;
P_0c064580: /* original d063, guest PC 0x0c064580 */
if(!s->budget--) { s->failed_pc=0x0c064580u; return 0; }
r[0]=read(ram,0x0c064710u,4);
goto P_0c064582;
P_0c064582: /* original 7501, guest PC 0x0c064582 */
if(!s->budget--) { s->failed_pc=0x0c064582u; return 0; }
r[5]+=0x00000001u;
goto P_0c064584;
P_0c064584: /* original 4108, guest PC 0x0c064584 */
if(!s->budget--) { s->failed_pc=0x0c064584u; return 0; }
r[1]<<=2;
goto P_0c064586;
P_0c064586: /* original 0166, guest PC 0x0c064586 */
if(!s->budget--) { s->failed_pc=0x0c064586u; return 0; }
write(ram,r[1]+r[0],r[6],4);
goto P_0c064588;
P_0c064588: /* original 6253, guest PC 0x0c064588 */
if(!s->budget--) { s->failed_pc=0x0c064588u; return 0; }
r[2]=r[5];
goto P_0c06458a;
P_0c06458a: /* original 7501, guest PC 0x0c06458a */
if(!s->budget--) { s->failed_pc=0x0c06458au; return 0; }
r[5]+=0x00000001u;
goto P_0c06458c;
P_0c06458c: /* original 4208, guest PC 0x0c06458c */
if(!s->budget--) { s->failed_pc=0x0c06458cu; return 0; }
r[2]<<=2;
goto P_0c06458e;
P_0c06458e: /* original 0276, guest PC 0x0c06458e */
if(!s->budget--) { s->failed_pc=0x0c06458eu; return 0; }
write(ram,r[2]+r[0],r[7],4);
goto P_0c064590;
P_0c064590: /* original 000b, guest PC 0x0c064590 */
if(!s->budget--) { s->failed_pc=0x0c064590u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c064592: /* original 6053, guest PC 0x0c064592 */
if(!s->budget--) { s->failed_pc=0x0c064592u; return 0; }
r[0]=r[5];
if(!vf3_matrix_family(0x0c064594u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c064594u; return 0; } return 1;
P_0c065c40: /* original 2fe6, guest PC 0x0c065c40 */
if(!s->budget--) { s->failed_pc=0x0c065c40u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065c42;
P_0c065c42: /* original 2fd6, guest PC 0x0c065c42 */
if(!s->budget--) { s->failed_pc=0x0c065c42u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065c44;
P_0c065c44: /* original 2fc6, guest PC 0x0c065c44 */
if(!s->budget--) { s->failed_pc=0x0c065c44u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065c46;
P_0c065c46: /* original ec00, guest PC 0x0c065c46 */
if(!s->budget--) { s->failed_pc=0x0c065c46u; return 0; }
r[12]=0x00000000u;
goto P_0c065c48;
P_0c065c48: /* original 2fb6, guest PC 0x0c065c48 */
if(!s->budget--) { s->failed_pc=0x0c065c48u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065c4a;
P_0c065c4a: /* original 2fa6, guest PC 0x0c065c4a */
if(!s->budget--) { s->failed_pc=0x0c065c4au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065c4c;
P_0c065c4c: /* original 4f22, guest PC 0x0c065c4c */
if(!s->budget--) { s->failed_pc=0x0c065c4cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c065c4e;
P_0c065c4e: /* original 7ff4, guest PC 0x0c065c4e */
if(!s->budget--) { s->failed_pc=0x0c065c4eu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c065c50;
P_0c065c50: /* original 6342, guest PC 0x0c065c50 */
if(!s->budget--) { s->failed_pc=0x0c065c50u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c065c52;
P_0c065c52: /* original 65f3, guest PC 0x0c065c52 */
if(!s->budget--) { s->failed_pc=0x0c065c52u; return 0; }
r[5]=r[15];
goto P_0c065c54;
P_0c065c54: /* original 6e53, guest PC 0x0c065c54 */
if(!s->budget--) { s->failed_pc=0x0c065c54u; return 0; }
r[14]=r[5];
goto P_0c065c56;
P_0c065c56: /* original 6ae3, guest PC 0x0c065c56 */
if(!s->budget--) { s->failed_pc=0x0c065c56u; return 0; }
r[10]=r[14];
goto P_0c065c58;
P_0c065c58: /* original 2e32, guest PC 0x0c065c58 */
if(!s->budget--) { s->failed_pc=0x0c065c58u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c065c5a;
P_0c065c5a: /* original 6be3, guest PC 0x0c065c5a */
if(!s->budget--) { s->failed_pc=0x0c065c5au; return 0; }
r[11]=r[14];
goto P_0c065c5c;
P_0c065c5c: /* original 5241, guest PC 0x0c065c5c */
if(!s->budget--) { s->failed_pc=0x0c065c5cu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c065c5e;
P_0c065c5e: /* original 7a04, guest PC 0x0c065c5e */
if(!s->budget--) { s->failed_pc=0x0c065c5eu; return 0; }
r[10]+=0x00000004u;
goto P_0c065c60;
P_0c065c60: /* original 2a22, guest PC 0x0c065c60 */
if(!s->budget--) { s->failed_pc=0x0c065c60u; return 0; }
write(ram,r[10],r[2],4);
goto P_0c065c62;
P_0c065c62: /* original 7b08, guest PC 0x0c065c62 */
if(!s->budget--) { s->failed_pc=0x0c065c62u; return 0; }
r[11]+=0x00000008u;
goto P_0c065c64;
P_0c065c64: /* original 5342, guest PC 0x0c065c64 */
if(!s->budget--) { s->failed_pc=0x0c065c64u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c065c66;
P_0c065c66: /* original 2b32, guest PC 0x0c065c66 */
if(!s->budget--) { s->failed_pc=0x0c065c66u; return 0; }
write(ram,r[11],r[3],4);
goto P_0c065c68;
P_0c065c68: /* original d250, guest PC 0x0c065c68 */
if(!s->budget--) { s->failed_pc=0x0c065c68u; return 0; }
r[2]=read(ram,0x0c065dacu,4);
goto P_0c065c6a;
P_0c065c6a: /* original 6d22, guest PC 0x0c065c6a */
if(!s->budget--) { s->failed_pc=0x0c065c6au; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c065c6c;
P_0c065c6c: /* original d350, guest PC 0x0c065c6c */
if(!s->budget--) { s->failed_pc=0x0c065c6cu; return 0; }
r[3]=read(ram,0x0c065db0u,4);
goto P_0c065c6e;
P_0c065c6e: /* original 6432, guest PC 0x0c065c6e */
if(!s->budget--) { s->failed_pc=0x0c065c6eu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c065c70;
P_0c065c70: /* original d150, guest PC 0x0c065c70 */
if(!s->budget--) { s->failed_pc=0x0c065c70u; return 0; }
r[1]=read(ram,0x0c065db4u,4);
goto P_0c065c72;
P_0c065c72: /* original 6512, guest PC 0x0c065c72 */
if(!s->budget--) { s->failed_pc=0x0c065c72u; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c065c74;
P_0c065c74: /* original d050, guest PC 0x0c065c74 */
if(!s->budget--) { s->failed_pc=0x0c065c74u; return 0; }
r[0]=read(ram,0x0c065db8u,4);
goto P_0c065c76;
P_0c065c76: /* original 62c3, guest PC 0x0c065c76 */
if(!s->budget--) { s->failed_pc=0x0c065c76u; return 0; }
r[2]=r[12];
goto P_0c065c78;
P_0c065c78: /* original 7c01, guest PC 0x0c065c78 */
if(!s->budget--) { s->failed_pc=0x0c065c78u; return 0; }
r[12]+=0x00000001u;
goto P_0c065c7a;
P_0c065c7a: /* original 4208, guest PC 0x0c065c7a */
if(!s->budget--) { s->failed_pc=0x0c065c7au; return 0; }
r[2]<<=2;
goto P_0c065c7c;
P_0c065c7c: /* original 02d6, guest PC 0x0c065c7c */
if(!s->budget--) { s->failed_pc=0x0c065c7cu; return 0; }
write(ram,r[2]+r[0],r[13],4);
goto P_0c065c7e;
P_0c065c7e: /* original 63c3, guest PC 0x0c065c7e */
if(!s->budget--) { s->failed_pc=0x0c065c7eu; return 0; }
r[3]=r[12];
goto P_0c065c80;
P_0c065c80: /* original 7c01, guest PC 0x0c065c80 */
if(!s->budget--) { s->failed_pc=0x0c065c80u; return 0; }
r[12]+=0x00000001u;
goto P_0c065c82;
P_0c065c82: /* original 4308, guest PC 0x0c065c82 */
if(!s->budget--) { s->failed_pc=0x0c065c82u; return 0; }
r[3]<<=2;
goto P_0c065c84;
P_0c065c84: /* original 0346, guest PC 0x0c065c84 */
if(!s->budget--) { s->failed_pc=0x0c065c84u; return 0; }
write(ram,r[3]+r[0],r[4],4);
goto P_0c065c86;
P_0c065c86: /* original 62c3, guest PC 0x0c065c86 */
if(!s->budget--) { s->failed_pc=0x0c065c86u; return 0; }
r[2]=r[12];
goto P_0c065c88;
P_0c065c88: /* original 7c01, guest PC 0x0c065c88 */
if(!s->budget--) { s->failed_pc=0x0c065c88u; return 0; }
r[12]+=0x00000001u;
goto P_0c065c8a;
P_0c065c8a: /* original 4208, guest PC 0x0c065c8a */
if(!s->budget--) { s->failed_pc=0x0c065c8au; return 0; }
r[2]<<=2;
goto P_0c065c8c;
P_0c065c8c: /* original 0256, guest PC 0x0c065c8c */
if(!s->budget--) { s->failed_pc=0x0c065c8cu; return 0; }
write(ram,r[2]+r[0],r[5],4);
goto P_0c065c8e;
P_0c065c8e: /* original 63c3, guest PC 0x0c065c8e */
if(!s->budget--) { s->failed_pc=0x0c065c8eu; return 0; }
r[3]=r[12];
goto P_0c065c90;
P_0c065c90: /* original 62e2, guest PC 0x0c065c90 */
if(!s->budget--) { s->failed_pc=0x0c065c90u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c065c92;
P_0c065c92: /* original 7c01, guest PC 0x0c065c92 */
if(!s->budget--) { s->failed_pc=0x0c065c92u; return 0; }
r[12]+=0x00000001u;
goto P_0c065c94;
P_0c065c94: /* original 5221, guest PC 0x0c065c94 */
if(!s->budget--) { s->failed_pc=0x0c065c94u; return 0; }
r[2]=read(ram,r[2]+4,4);
goto P_0c065c96;
P_0c065c96: /* original 4308, guest PC 0x0c065c96 */
if(!s->budget--) { s->failed_pc=0x0c065c96u; return 0; }
r[3]<<=2;
goto P_0c065c98;
P_0c065c98: /* original 0326, guest PC 0x0c065c98 */
if(!s->budget--) { s->failed_pc=0x0c065c98u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065c9a;
P_0c065c9a: /* original 63c3, guest PC 0x0c065c9a */
if(!s->budget--) { s->failed_pc=0x0c065c9au; return 0; }
r[3]=r[12];
goto P_0c065c9c;
P_0c065c9c: /* original 62e2, guest PC 0x0c065c9c */
if(!s->budget--) { s->failed_pc=0x0c065c9cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c065c9e;
P_0c065c9e: /* original 7c01, guest PC 0x0c065c9e */
if(!s->budget--) { s->failed_pc=0x0c065c9eu; return 0; }
r[12]+=0x00000001u;
goto P_0c065ca0;
P_0c065ca0: /* original 5222, guest PC 0x0c065ca0 */
if(!s->budget--) { s->failed_pc=0x0c065ca0u; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c065ca2;
P_0c065ca2: /* original 4308, guest PC 0x0c065ca2 */
if(!s->budget--) { s->failed_pc=0x0c065ca2u; return 0; }
r[3]<<=2;
goto P_0c065ca4;
P_0c065ca4: /* original 0326, guest PC 0x0c065ca4 */
if(!s->budget--) { s->failed_pc=0x0c065ca4u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065ca6;
P_0c065ca6: /* original 63c3, guest PC 0x0c065ca6 */
if(!s->budget--) { s->failed_pc=0x0c065ca6u; return 0; }
r[3]=r[12];
goto P_0c065ca8;
P_0c065ca8: /* original 62e2, guest PC 0x0c065ca8 */
if(!s->budget--) { s->failed_pc=0x0c065ca8u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c065caa;
P_0c065caa: /* original 7c01, guest PC 0x0c065caa */
if(!s->budget--) { s->failed_pc=0x0c065caau; return 0; }
r[12]+=0x00000001u;
goto P_0c065cac;
P_0c065cac: /* original 5223, guest PC 0x0c065cac */
if(!s->budget--) { s->failed_pc=0x0c065cacu; return 0; }
r[2]=read(ram,r[2]+12,4);
goto P_0c065cae;
P_0c065cae: /* original 4308, guest PC 0x0c065cae */
if(!s->budget--) { s->failed_pc=0x0c065caeu; return 0; }
r[3]<<=2;
goto P_0c065cb0;
P_0c065cb0: /* original 0326, guest PC 0x0c065cb0 */
if(!s->budget--) { s->failed_pc=0x0c065cb0u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065cb2;
P_0c065cb2: /* original 65c3, guest PC 0x0c065cb2 */
if(!s->budget--) { s->failed_pc=0x0c065cb2u; return 0; }
r[5]=r[12];
goto P_0c065cb4;
P_0c065cb4: /* original d341, guest PC 0x0c065cb4 */
if(!s->budget--) { s->failed_pc=0x0c065cb4u; return 0; }
r[3]=read(ram,0x0c065dbcu,4);
goto P_0c065cb6;
P_0c065cb6: /* original 66e2, guest PC 0x0c065cb6 */
if(!s->budget--) { s->failed_pc=0x0c065cb6u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c065cb8;
P_0c065cb8: /* original 5664, guest PC 0x0c065cb8 */
if(!s->budget--) { s->failed_pc=0x0c065cb8u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065cba;
P_0c065cba: /* original 430b, guest PC 0x0c065cba */
if(!s->budget--) { s->failed_pc=0x0c065cbau; return 0; }
target=r[3];
r[16]=code_base|0x0c065cbeu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065cbeu) { target=s->pc; goto dispatch; }
goto P_0c065cbe;
P_0c065cbc: /* original 64d3, guest PC 0x0c065cbc */
if(!s->budget--) { s->failed_pc=0x0c065cbcu; return 0; }
r[4]=r[13];
goto P_0c065cbe;
P_0c065cbe: /* original 6c03, guest PC 0x0c065cbe */
if(!s->budget--) { s->failed_pc=0x0c065cbeu; return 0; }
r[12]=r[0];
goto P_0c065cc0;
P_0c065cc0: /* original 63e2, guest PC 0x0c065cc0 */
if(!s->budget--) { s->failed_pc=0x0c065cc0u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c065cc2;
P_0c065cc2: /* original 62c3, guest PC 0x0c065cc2 */
if(!s->budget--) { s->failed_pc=0x0c065cc2u; return 0; }
r[2]=r[12];
goto P_0c065cc4;
P_0c065cc4: /* original d03c, guest PC 0x0c065cc4 */
if(!s->budget--) { s->failed_pc=0x0c065cc4u; return 0; }
r[0]=read(ram,0x0c065db8u,4);
goto P_0c065cc6;
P_0c065cc6: /* original 7c01, guest PC 0x0c065cc6 */
if(!s->budget--) { s->failed_pc=0x0c065cc6u; return 0; }
r[12]+=0x00000001u;
goto P_0c065cc8;
P_0c065cc8: /* original 5136, guest PC 0x0c065cc8 */
if(!s->budget--) { s->failed_pc=0x0c065cc8u; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c065cca;
P_0c065cca: /* original 4208, guest PC 0x0c065cca */
if(!s->budget--) { s->failed_pc=0x0c065ccau; return 0; }
r[2]<<=2;
goto P_0c065ccc;
P_0c065ccc: /* original 0216, guest PC 0x0c065ccc */
if(!s->budget--) { s->failed_pc=0x0c065cccu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065cce;
P_0c065cce: /* original 65c3, guest PC 0x0c065cce */
if(!s->budget--) { s->failed_pc=0x0c065cceu; return 0; }
r[5]=r[12];
goto P_0c065cd0;
P_0c065cd0: /* original d33b, guest PC 0x0c065cd0 */
if(!s->budget--) { s->failed_pc=0x0c065cd0u; return 0; }
r[3]=read(ram,0x0c065dc0u,4);
goto P_0c065cd2;
P_0c065cd2: /* original 66e2, guest PC 0x0c065cd2 */
if(!s->budget--) { s->failed_pc=0x0c065cd2u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c065cd4;
P_0c065cd4: /* original 5667, guest PC 0x0c065cd4 */
if(!s->budget--) { s->failed_pc=0x0c065cd4u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c065cd6;
P_0c065cd6: /* original 430b, guest PC 0x0c065cd6 */
if(!s->budget--) { s->failed_pc=0x0c065cd6u; return 0; }
target=r[3];
r[16]=code_base|0x0c065cdau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065cdau) { target=s->pc; goto dispatch; }
goto P_0c065cda;
P_0c065cd8: /* original 64d3, guest PC 0x0c065cd8 */
if(!s->budget--) { s->failed_pc=0x0c065cd8u; return 0; }
r[4]=r[13];
goto P_0c065cda;
P_0c065cda: /* original 6c03, guest PC 0x0c065cda */
if(!s->budget--) { s->failed_pc=0x0c065cdau; return 0; }
r[12]=r[0];
goto P_0c065cdc;
P_0c065cdc: /* original 61a2, guest PC 0x0c065cdc */
if(!s->budget--) { s->failed_pc=0x0c065cdcu; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065cde;
P_0c065cde: /* original 62c3, guest PC 0x0c065cde */
if(!s->budget--) { s->failed_pc=0x0c065cdeu; return 0; }
r[2]=r[12];
goto P_0c065ce0;
P_0c065ce0: /* original d035, guest PC 0x0c065ce0 */
if(!s->budget--) { s->failed_pc=0x0c065ce0u; return 0; }
r[0]=read(ram,0x0c065db8u,4);
goto P_0c065ce2;
P_0c065ce2: /* original 7c01, guest PC 0x0c065ce2 */
if(!s->budget--) { s->failed_pc=0x0c065ce2u; return 0; }
r[12]+=0x00000001u;
goto P_0c065ce4;
P_0c065ce4: /* original 5311, guest PC 0x0c065ce4 */
if(!s->budget--) { s->failed_pc=0x0c065ce4u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c065ce6;
P_0c065ce6: /* original 4208, guest PC 0x0c065ce6 */
if(!s->budget--) { s->failed_pc=0x0c065ce6u; return 0; }
r[2]<<=2;
goto P_0c065ce8;
P_0c065ce8: /* original 0236, guest PC 0x0c065ce8 */
if(!s->budget--) { s->failed_pc=0x0c065ce8u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065cea;
P_0c065cea: /* original 62c3, guest PC 0x0c065cea */
if(!s->budget--) { s->failed_pc=0x0c065ceau; return 0; }
r[2]=r[12];
goto P_0c065cec;
P_0c065cec: /* original 61a2, guest PC 0x0c065cec */
if(!s->budget--) { s->failed_pc=0x0c065cecu; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065cee;
P_0c065cee: /* original 7c01, guest PC 0x0c065cee */
if(!s->budget--) { s->failed_pc=0x0c065ceeu; return 0; }
r[12]+=0x00000001u;
goto P_0c065cf0;
P_0c065cf0: /* original 5312, guest PC 0x0c065cf0 */
if(!s->budget--) { s->failed_pc=0x0c065cf0u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c065cf2;
P_0c065cf2: /* original 4208, guest PC 0x0c065cf2 */
if(!s->budget--) { s->failed_pc=0x0c065cf2u; return 0; }
r[2]<<=2;
goto P_0c065cf4;
P_0c065cf4: /* original 0236, guest PC 0x0c065cf4 */
if(!s->budget--) { s->failed_pc=0x0c065cf4u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065cf6;
P_0c065cf6: /* original 62c3, guest PC 0x0c065cf6 */
if(!s->budget--) { s->failed_pc=0x0c065cf6u; return 0; }
r[2]=r[12];
goto P_0c065cf8;
P_0c065cf8: /* original 61a2, guest PC 0x0c065cf8 */
if(!s->budget--) { s->failed_pc=0x0c065cf8u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065cfa;
P_0c065cfa: /* original 7c01, guest PC 0x0c065cfa */
if(!s->budget--) { s->failed_pc=0x0c065cfau; return 0; }
r[12]+=0x00000001u;
goto P_0c065cfc;
P_0c065cfc: /* original 5313, guest PC 0x0c065cfc */
if(!s->budget--) { s->failed_pc=0x0c065cfcu; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c065cfe;
P_0c065cfe: /* original 4208, guest PC 0x0c065cfe */
if(!s->budget--) { s->failed_pc=0x0c065cfeu; return 0; }
r[2]<<=2;
goto P_0c065d00;
P_0c065d00: /* original 0236, guest PC 0x0c065d00 */
if(!s->budget--) { s->failed_pc=0x0c065d00u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065d02;
P_0c065d02: /* original 65c3, guest PC 0x0c065d02 */
if(!s->budget--) { s->failed_pc=0x0c065d02u; return 0; }
r[5]=r[12];
goto P_0c065d04;
P_0c065d04: /* original d32d, guest PC 0x0c065d04 */
if(!s->budget--) { s->failed_pc=0x0c065d04u; return 0; }
r[3]=read(ram,0x0c065dbcu,4);
goto P_0c065d06;
P_0c065d06: /* original 66e2, guest PC 0x0c065d06 */
if(!s->budget--) { s->failed_pc=0x0c065d06u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c065d08;
P_0c065d08: /* original 5664, guest PC 0x0c065d08 */
if(!s->budget--) { s->failed_pc=0x0c065d08u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065d0a;
P_0c065d0a: /* original 430b, guest PC 0x0c065d0a */
if(!s->budget--) { s->failed_pc=0x0c065d0au; return 0; }
target=r[3];
r[16]=code_base|0x0c065d0eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065d0eu) { target=s->pc; goto dispatch; }
goto P_0c065d0e;
P_0c065d0c: /* original 64d3, guest PC 0x0c065d0c */
if(!s->budget--) { s->failed_pc=0x0c065d0cu; return 0; }
r[4]=r[13];
goto P_0c065d0e;
P_0c065d0e: /* original 6c03, guest PC 0x0c065d0e */
if(!s->budget--) { s->failed_pc=0x0c065d0eu; return 0; }
r[12]=r[0];
goto P_0c065d10;
P_0c065d10: /* original 63a2, guest PC 0x0c065d10 */
if(!s->budget--) { s->failed_pc=0x0c065d10u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c065d12;
P_0c065d12: /* original 62c3, guest PC 0x0c065d12 */
if(!s->budget--) { s->failed_pc=0x0c065d12u; return 0; }
r[2]=r[12];
goto P_0c065d14;
P_0c065d14: /* original d028, guest PC 0x0c065d14 */
if(!s->budget--) { s->failed_pc=0x0c065d14u; return 0; }
r[0]=read(ram,0x0c065db8u,4);
goto P_0c065d16;
P_0c065d16: /* original 7c01, guest PC 0x0c065d16 */
if(!s->budget--) { s->failed_pc=0x0c065d16u; return 0; }
r[12]+=0x00000001u;
goto P_0c065d18;
P_0c065d18: /* original 5136, guest PC 0x0c065d18 */
if(!s->budget--) { s->failed_pc=0x0c065d18u; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c065d1a;
P_0c065d1a: /* original 4208, guest PC 0x0c065d1a */
if(!s->budget--) { s->failed_pc=0x0c065d1au; return 0; }
r[2]<<=2;
goto P_0c065d1c;
P_0c065d1c: /* original 0216, guest PC 0x0c065d1c */
if(!s->budget--) { s->failed_pc=0x0c065d1cu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065d1e;
P_0c065d1e: /* original 65c3, guest PC 0x0c065d1e */
if(!s->budget--) { s->failed_pc=0x0c065d1eu; return 0; }
r[5]=r[12];
goto P_0c065d20;
P_0c065d20: /* original d327, guest PC 0x0c065d20 */
if(!s->budget--) { s->failed_pc=0x0c065d20u; return 0; }
r[3]=read(ram,0x0c065dc0u,4);
goto P_0c065d22;
P_0c065d22: /* original 66a2, guest PC 0x0c065d22 */
if(!s->budget--) { s->failed_pc=0x0c065d22u; return 0; }
tmp=read(ram,r[10],4);
r[6]=tmp;
goto P_0c065d24;
P_0c065d24: /* original 5667, guest PC 0x0c065d24 */
if(!s->budget--) { s->failed_pc=0x0c065d24u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c065d26;
P_0c065d26: /* original 430b, guest PC 0x0c065d26 */
if(!s->budget--) { s->failed_pc=0x0c065d26u; return 0; }
target=r[3];
r[16]=code_base|0x0c065d2au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065d2au) { target=s->pc; goto dispatch; }
goto P_0c065d2a;
P_0c065d28: /* original 64d3, guest PC 0x0c065d28 */
if(!s->budget--) { s->failed_pc=0x0c065d28u; return 0; }
r[4]=r[13];
goto P_0c065d2a;
P_0c065d2a: /* original 6c03, guest PC 0x0c065d2a */
if(!s->budget--) { s->failed_pc=0x0c065d2au; return 0; }
r[12]=r[0];
goto P_0c065d2c;
P_0c065d2c: /* original 61b2, guest PC 0x0c065d2c */
if(!s->budget--) { s->failed_pc=0x0c065d2cu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c065d2e;
P_0c065d2e: /* original 62c3, guest PC 0x0c065d2e */
if(!s->budget--) { s->failed_pc=0x0c065d2eu; return 0; }
r[2]=r[12];
goto P_0c065d30;
P_0c065d30: /* original d021, guest PC 0x0c065d30 */
if(!s->budget--) { s->failed_pc=0x0c065d30u; return 0; }
r[0]=read(ram,0x0c065db8u,4);
goto P_0c065d32;
P_0c065d32: /* original 7c01, guest PC 0x0c065d32 */
if(!s->budget--) { s->failed_pc=0x0c065d32u; return 0; }
r[12]+=0x00000001u;
goto P_0c065d34;
P_0c065d34: /* original 5311, guest PC 0x0c065d34 */
if(!s->budget--) { s->failed_pc=0x0c065d34u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c065d36;
P_0c065d36: /* original 4208, guest PC 0x0c065d36 */
if(!s->budget--) { s->failed_pc=0x0c065d36u; return 0; }
r[2]<<=2;
goto P_0c065d38;
P_0c065d38: /* original 0236, guest PC 0x0c065d38 */
if(!s->budget--) { s->failed_pc=0x0c065d38u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065d3a;
P_0c065d3a: /* original 62c3, guest PC 0x0c065d3a */
if(!s->budget--) { s->failed_pc=0x0c065d3au; return 0; }
r[2]=r[12];
goto P_0c065d3c;
P_0c065d3c: /* original 61b2, guest PC 0x0c065d3c */
if(!s->budget--) { s->failed_pc=0x0c065d3cu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c065d3e;
P_0c065d3e: /* original 7c01, guest PC 0x0c065d3e */
if(!s->budget--) { s->failed_pc=0x0c065d3eu; return 0; }
r[12]+=0x00000001u;
goto P_0c065d40;
P_0c065d40: /* original 5312, guest PC 0x0c065d40 */
if(!s->budget--) { s->failed_pc=0x0c065d40u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c065d42;
P_0c065d42: /* original 4208, guest PC 0x0c065d42 */
if(!s->budget--) { s->failed_pc=0x0c065d42u; return 0; }
r[2]<<=2;
goto P_0c065d44;
P_0c065d44: /* original 0236, guest PC 0x0c065d44 */
if(!s->budget--) { s->failed_pc=0x0c065d44u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065d46;
P_0c065d46: /* original 62c3, guest PC 0x0c065d46 */
if(!s->budget--) { s->failed_pc=0x0c065d46u; return 0; }
r[2]=r[12];
goto P_0c065d48;
P_0c065d48: /* original 61b2, guest PC 0x0c065d48 */
if(!s->budget--) { s->failed_pc=0x0c065d48u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c065d4a;
P_0c065d4a: /* original 7c01, guest PC 0x0c065d4a */
if(!s->budget--) { s->failed_pc=0x0c065d4au; return 0; }
r[12]+=0x00000001u;
goto P_0c065d4c;
P_0c065d4c: /* original 5313, guest PC 0x0c065d4c */
if(!s->budget--) { s->failed_pc=0x0c065d4cu; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c065d4e;
P_0c065d4e: /* original 4208, guest PC 0x0c065d4e */
if(!s->budget--) { s->failed_pc=0x0c065d4eu; return 0; }
r[2]<<=2;
goto P_0c065d50;
P_0c065d50: /* original 0236, guest PC 0x0c065d50 */
if(!s->budget--) { s->failed_pc=0x0c065d50u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065d52;
P_0c065d52: /* original 65c3, guest PC 0x0c065d52 */
if(!s->budget--) { s->failed_pc=0x0c065d52u; return 0; }
r[5]=r[12];
goto P_0c065d54;
P_0c065d54: /* original d319, guest PC 0x0c065d54 */
if(!s->budget--) { s->failed_pc=0x0c065d54u; return 0; }
r[3]=read(ram,0x0c065dbcu,4);
goto P_0c065d56;
P_0c065d56: /* original 66b2, guest PC 0x0c065d56 */
if(!s->budget--) { s->failed_pc=0x0c065d56u; return 0; }
tmp=read(ram,r[11],4);
r[6]=tmp;
goto P_0c065d58;
P_0c065d58: /* original 5664, guest PC 0x0c065d58 */
if(!s->budget--) { s->failed_pc=0x0c065d58u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065d5a;
P_0c065d5a: /* original 430b, guest PC 0x0c065d5a */
if(!s->budget--) { s->failed_pc=0x0c065d5au; return 0; }
target=r[3];
r[16]=code_base|0x0c065d5eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065d5eu) { target=s->pc; goto dispatch; }
goto P_0c065d5e;
P_0c065d5c: /* original 64d3, guest PC 0x0c065d5c */
if(!s->budget--) { s->failed_pc=0x0c065d5cu; return 0; }
r[4]=r[13];
goto P_0c065d5e;
P_0c065d5e: /* original 6c03, guest PC 0x0c065d5e */
if(!s->budget--) { s->failed_pc=0x0c065d5eu; return 0; }
r[12]=r[0];
goto P_0c065d60;
P_0c065d60: /* original 63b2, guest PC 0x0c065d60 */
if(!s->budget--) { s->failed_pc=0x0c065d60u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c065d62;
P_0c065d62: /* original 62c3, guest PC 0x0c065d62 */
if(!s->budget--) { s->failed_pc=0x0c065d62u; return 0; }
r[2]=r[12];
goto P_0c065d64;
P_0c065d64: /* original d014, guest PC 0x0c065d64 */
if(!s->budget--) { s->failed_pc=0x0c065d64u; return 0; }
r[0]=read(ram,0x0c065db8u,4);
goto P_0c065d66;
P_0c065d66: /* original 7c01, guest PC 0x0c065d66 */
if(!s->budget--) { s->failed_pc=0x0c065d66u; return 0; }
r[12]+=0x00000001u;
goto P_0c065d68;
P_0c065d68: /* original 5136, guest PC 0x0c065d68 */
if(!s->budget--) { s->failed_pc=0x0c065d68u; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c065d6a;
P_0c065d6a: /* original 4208, guest PC 0x0c065d6a */
if(!s->budget--) { s->failed_pc=0x0c065d6au; return 0; }
r[2]<<=2;
goto P_0c065d6c;
P_0c065d6c: /* original 0216, guest PC 0x0c065d6c */
if(!s->budget--) { s->failed_pc=0x0c065d6cu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065d6e;
P_0c065d6e: /* original 65c3, guest PC 0x0c065d6e */
if(!s->budget--) { s->failed_pc=0x0c065d6eu; return 0; }
r[5]=r[12];
goto P_0c065d70;
P_0c065d70: /* original d313, guest PC 0x0c065d70 */
if(!s->budget--) { s->failed_pc=0x0c065d70u; return 0; }
r[3]=read(ram,0x0c065dc0u,4);
goto P_0c065d72;
P_0c065d72: /* original 66b2, guest PC 0x0c065d72 */
if(!s->budget--) { s->failed_pc=0x0c065d72u; return 0; }
tmp=read(ram,r[11],4);
r[6]=tmp;
goto P_0c065d74;
P_0c065d74: /* original 5667, guest PC 0x0c065d74 */
if(!s->budget--) { s->failed_pc=0x0c065d74u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c065d76;
P_0c065d76: /* original 430b, guest PC 0x0c065d76 */
if(!s->budget--) { s->failed_pc=0x0c065d76u; return 0; }
target=r[3];
r[16]=code_base|0x0c065d7au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065d7au) { target=s->pc; goto dispatch; }
goto P_0c065d7a;
P_0c065d78: /* original 64d3, guest PC 0x0c065d78 */
if(!s->budget--) { s->failed_pc=0x0c065d78u; return 0; }
r[4]=r[13];
goto P_0c065d7a;
P_0c065d7a: /* original 6403, guest PC 0x0c065d7a */
if(!s->budget--) { s->failed_pc=0x0c065d7au; return 0; }
r[4]=r[0];
goto P_0c065d7c;
P_0c065d7c: /* original d211, guest PC 0x0c065d7c */
if(!s->budget--) { s->failed_pc=0x0c065d7cu; return 0; }
r[2]=read(ram,0x0c065dc4u,4);
goto P_0c065d7e;
P_0c065d7e: /* original 4408, guest PC 0x0c065d7e */
if(!s->budget--) { s->failed_pc=0x0c065d7eu; return 0; }
r[4]<<=2;
goto P_0c065d80;
P_0c065d80: /* original 2242, guest PC 0x0c065d80 */
if(!s->budget--) { s->failed_pc=0x0c065d80u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c065d82;
P_0c065d82: /* original d311, guest PC 0x0c065d82 */
if(!s->budget--) { s->failed_pc=0x0c065d82u; return 0; }
r[3]=read(ram,0x0c065dc8u,4);
goto P_0c065d84;
P_0c065d84: /* original 430b, guest PC 0x0c065d84 */
if(!s->budget--) { s->failed_pc=0x0c065d84u; return 0; }
target=r[3];
r[16]=code_base|0x0c065d88u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065d88u) { target=s->pc; goto dispatch; }
goto P_0c065d88;
P_0c065d86: /* original 64d3, guest PC 0x0c065d86 */
if(!s->budget--) { s->failed_pc=0x0c065d86u; return 0; }
r[4]=r[13];
goto P_0c065d88;
P_0c065d88: /* original d210, guest PC 0x0c065d88 */
if(!s->budget--) { s->failed_pc=0x0c065d88u; return 0; }
r[2]=read(ram,0x0c065dccu,4);
goto P_0c065d8a;
P_0c065d8a: /* original 6403, guest PC 0x0c065d8a */
if(!s->budget--) { s->failed_pc=0x0c065d8au; return 0; }
r[4]=r[0];
goto P_0c065d8c;
P_0c065d8c: /* original e500, guest PC 0x0c065d8c */
if(!s->budget--) { s->failed_pc=0x0c065d8cu; return 0; }
r[5]=0x00000000u;
goto P_0c065d8e;
P_0c065d8e: /* original 420b, guest PC 0x0c065d8e */
if(!s->budget--) { s->failed_pc=0x0c065d8eu; return 0; }
target=r[2];
r[16]=code_base|0x0c065d92u;
r[6]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065d92u) { target=s->pc; goto dispatch; }
goto P_0c065d92;
P_0c065d90: /* original 6653, guest PC 0x0c065d90 */
if(!s->budget--) { s->failed_pc=0x0c065d90u; return 0; }
r[6]=r[5];
goto P_0c065d92;
P_0c065d92: /* original 62e2, guest PC 0x0c065d92 */
if(!s->budget--) { s->failed_pc=0x0c065d92u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c065d94;
P_0c065d94: /* original d10e, guest PC 0x0c065d94 */
if(!s->budget--) { s->failed_pc=0x0c065d94u; return 0; }
r[1]=read(ram,0x0c065dd0u,4);
goto P_0c065d96;
P_0c065d96: /* original 5323, guest PC 0x0c065d96 */
if(!s->budget--) { s->failed_pc=0x0c065d96u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c065d98;
P_0c065d98: /* original 2132, guest PC 0x0c065d98 */
if(!s->budget--) { s->failed_pc=0x0c065d98u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c065d9a;
P_0c065d9a: /* original e000, guest PC 0x0c065d9a */
if(!s->budget--) { s->failed_pc=0x0c065d9au; return 0; }
r[0]=0x00000000u;
goto P_0c065d9c;
P_0c065d9c: /* original 7f0c, guest PC 0x0c065d9c */
if(!s->budget--) { s->failed_pc=0x0c065d9cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c065d9e;
P_0c065d9e: /* original 4f26, guest PC 0x0c065d9e */
if(!s->budget--) { s->failed_pc=0x0c065d9eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c065da0;
P_0c065da0: /* original 6af6, guest PC 0x0c065da0 */
if(!s->budget--) { s->failed_pc=0x0c065da0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c065da2;
P_0c065da2: /* original 6bf6, guest PC 0x0c065da2 */
if(!s->budget--) { s->failed_pc=0x0c065da2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c065da4;
P_0c065da4: /* original 6cf6, guest PC 0x0c065da4 */
if(!s->budget--) { s->failed_pc=0x0c065da4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c065da6;
P_0c065da6: /* original 6df6, guest PC 0x0c065da6 */
if(!s->budget--) { s->failed_pc=0x0c065da6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c065da8;
P_0c065da8: /* original 000b, guest PC 0x0c065da8 */
if(!s->budget--) { s->failed_pc=0x0c065da8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c065daa: /* original 6ef6, guest PC 0x0c065daa */
if(!s->budget--) { s->failed_pc=0x0c065daau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c065dacu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c065dacu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
