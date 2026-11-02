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
int vf3_away_batch188_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09fe68u: goto P_0c09fe68;
case 0x0c09fe6au: goto P_0c09fe6a;
case 0x0c09fe6cu: goto P_0c09fe6c;
case 0x0c09fe6eu: goto P_0c09fe6e;
case 0x0c09fe70u: goto P_0c09fe70;
case 0x0c09fe72u: goto P_0c09fe72;
case 0x0c09fe74u: goto P_0c09fe74;
case 0x0c09fe76u: goto P_0c09fe76;
case 0x0c09fe78u: goto P_0c09fe78;
case 0x0c09fe7au: goto P_0c09fe7a;
case 0x0c09fe7cu: goto P_0c09fe7c;
case 0x0c09fe7eu: goto P_0c09fe7e;
case 0x0c09fe80u: goto P_0c09fe80;
case 0x0c09fe82u: goto P_0c09fe82;
case 0x0c09fe84u: goto P_0c09fe84;
case 0x0c09fe86u: goto P_0c09fe86;
case 0x0c09fe88u: goto P_0c09fe88;
case 0x0c09fe8au: goto P_0c09fe8a;
case 0x0c09fe8cu: goto P_0c09fe8c;
case 0x0c09fe8eu: goto P_0c09fe8e;
case 0x0c09fe90u: goto P_0c09fe90;
case 0x0c09fe92u: goto P_0c09fe92;
case 0x0c09fe94u: goto P_0c09fe94;
case 0x0c09fe96u: goto P_0c09fe96;
case 0x0c09fe98u: goto P_0c09fe98;
case 0x0c09fe9au: goto P_0c09fe9a;
case 0x0c09fe9cu: goto P_0c09fe9c;
case 0x0c09fe9eu: goto P_0c09fe9e;
case 0x0c09fea0u: goto P_0c09fea0;
case 0x0c09fea2u: goto P_0c09fea2;
case 0x0c09fea4u: goto P_0c09fea4;
case 0x0c09fea6u: goto P_0c09fea6;
case 0x0c09fea8u: goto P_0c09fea8;
case 0x0c09feaau: goto P_0c09feaa;
case 0x0c09feacu: goto P_0c09feac;
case 0x0c09feaeu: goto P_0c09feae;
case 0x0c09feb0u: goto P_0c09feb0;
case 0x0c09feb2u: goto P_0c09feb2;
case 0x0c09feb4u: goto P_0c09feb4;
case 0x0c09feb6u: goto P_0c09feb6;
case 0x0c09feb8u: goto P_0c09feb8;
case 0x0c09febau: goto P_0c09feba;
case 0x0c09febcu: goto P_0c09febc;
case 0x0c09febeu: goto P_0c09febe;
case 0x0c09fec0u: goto P_0c09fec0;
case 0x0c09fec2u: goto P_0c09fec2;
case 0x0c09fec4u: goto P_0c09fec4;
case 0x0c09fec6u: goto P_0c09fec6;
case 0x0c09fec8u: goto P_0c09fec8;
case 0x0c09fecau: goto P_0c09feca;
case 0x0c09feccu: goto P_0c09fecc;
case 0x0c09feceu: goto P_0c09fece;
case 0x0c09fed0u: goto P_0c09fed0;
case 0x0c09fed2u: goto P_0c09fed2;
case 0x0c09fed4u: goto P_0c09fed4;
case 0x0c09fed6u: goto P_0c09fed6;
case 0x0c09fed8u: goto P_0c09fed8;
case 0x0c09fedau: goto P_0c09feda;
case 0x0c09fedcu: goto P_0c09fedc;
case 0x0c09fedeu: goto P_0c09fede;
case 0x0c09fee0u: goto P_0c09fee0;
case 0x0c09fee2u: goto P_0c09fee2;
case 0x0c09fee4u: goto P_0c09fee4;
case 0x0c09fee6u: goto P_0c09fee6;
case 0x0c09fee8u: goto P_0c09fee8;
case 0x0c09feeau: goto P_0c09feea;
case 0x0c09feecu: goto P_0c09feec;
case 0x0c09feeeu: goto P_0c09feee;
case 0x0c09fef0u: goto P_0c09fef0;
case 0x0c09fef2u: goto P_0c09fef2;
case 0x0c09fef4u: goto P_0c09fef4;
case 0x0c09fef6u: goto P_0c09fef6;
case 0x0c09fef8u: goto P_0c09fef8;
case 0x0c09fefau: goto P_0c09fefa;
case 0x0c09fefcu: goto P_0c09fefc;
case 0x0c0a00b6u: goto P_0c0a00b6;
case 0x0c0a00b8u: goto P_0c0a00b8;
case 0x0c0a00bau: goto P_0c0a00ba;
case 0x0c0a00bcu: goto P_0c0a00bc;
case 0x0c0a00beu: goto P_0c0a00be;
case 0x0c0a00c0u: goto P_0c0a00c0;
case 0x0c0a00c2u: goto P_0c0a00c2;
case 0x0c0a00c4u: goto P_0c0a00c4;
case 0x0c0a00c6u: goto P_0c0a00c6;
case 0x0c0a00c8u: goto P_0c0a00c8;
case 0x0c0a00cau: goto P_0c0a00ca;
case 0x0c0a00ccu: goto P_0c0a00cc;
case 0x0c0a00ceu: goto P_0c0a00ce;
case 0x0c0a00d0u: goto P_0c0a00d0;
case 0x0c0a00d2u: goto P_0c0a00d2;
case 0x0c0a00d4u: goto P_0c0a00d4;
case 0x0c0a00d6u: goto P_0c0a00d6;
case 0x0c0a00d8u: goto P_0c0a00d8;
case 0x0c0a00dau: goto P_0c0a00da;
case 0x0c0a00dcu: goto P_0c0a00dc;
case 0x0c0a00deu: goto P_0c0a00de;
case 0x0c0a00e0u: goto P_0c0a00e0;
case 0x0c0a00e2u: goto P_0c0a00e2;
case 0x0c0a00e4u: goto P_0c0a00e4;
case 0x0c0a00e6u: goto P_0c0a00e6;
case 0x0c0a00e8u: goto P_0c0a00e8;
case 0x0c0a00eau: goto P_0c0a00ea;
case 0x0c0a00ecu: goto P_0c0a00ec;
case 0x0c0a00eeu: goto P_0c0a00ee;
case 0x0c0a00f0u: goto P_0c0a00f0;
case 0x0c0a00f2u: goto P_0c0a00f2;
case 0x0c0a0120u: goto P_0c0a0120;
case 0x0c0a0122u: goto P_0c0a0122;
case 0x0c0a0124u: goto P_0c0a0124;
case 0x0c0a0126u: goto P_0c0a0126;
case 0x0c0a0128u: goto P_0c0a0128;
case 0x0c0a012au: goto P_0c0a012a;
case 0x0c0a012cu: goto P_0c0a012c;
case 0x0c0a012eu: goto P_0c0a012e;
case 0x0c0a0130u: goto P_0c0a0130;
case 0x0c0a0132u: goto P_0c0a0132;
case 0x0c0a0134u: goto P_0c0a0134;
case 0x0c0a0136u: goto P_0c0a0136;
case 0x0c0a0138u: goto P_0c0a0138;
case 0x0c0a013au: goto P_0c0a013a;
case 0x0c0a013cu: goto P_0c0a013c;
case 0x0c0a013eu: goto P_0c0a013e;
case 0x0c0a0140u: goto P_0c0a0140;
case 0x0c0a0142u: goto P_0c0a0142;
case 0x0c0a0144u: goto P_0c0a0144;
case 0x0c0a0146u: goto P_0c0a0146;
case 0x0c0a0148u: goto P_0c0a0148;
case 0x0c0a014au: goto P_0c0a014a;
case 0x0c0a014cu: goto P_0c0a014c;
case 0x0c0a014eu: goto P_0c0a014e;
case 0x0c0a0150u: goto P_0c0a0150;
case 0x0c0a0152u: goto P_0c0a0152;
case 0x0c0a0154u: goto P_0c0a0154;
case 0x0c0a0156u: goto P_0c0a0156;
case 0x0c0a0158u: goto P_0c0a0158;
case 0x0c0a015au: goto P_0c0a015a;
case 0x0c0a015cu: goto P_0c0a015c;
case 0x0c0a015eu: goto P_0c0a015e;
case 0x0c0a0160u: goto P_0c0a0160;
case 0x0c0a0162u: goto P_0c0a0162;
case 0x0c0a0164u: goto P_0c0a0164;
case 0x0c0a0166u: goto P_0c0a0166;
case 0x0c0a0168u: goto P_0c0a0168;
case 0x0c0a016au: goto P_0c0a016a;
case 0x0c0a016cu: goto P_0c0a016c;
case 0x0c0a016eu: goto P_0c0a016e;
case 0x0c0a0170u: goto P_0c0a0170;
case 0x0c0a0172u: goto P_0c0a0172;
case 0x0c0a0174u: goto P_0c0a0174;
case 0x0c0a0176u: goto P_0c0a0176;
case 0x0c0a0178u: goto P_0c0a0178;
case 0x0c0a017au: goto P_0c0a017a;
case 0x0c0a017cu: goto P_0c0a017c;
case 0x0c0a017eu: goto P_0c0a017e;
case 0x0c0a0180u: goto P_0c0a0180;
case 0x0c0a0182u: goto P_0c0a0182;
case 0x0c0a0184u: goto P_0c0a0184;
case 0x0c0a0186u: goto P_0c0a0186;
case 0x0c0a0188u: goto P_0c0a0188;
case 0x0c0a018au: goto P_0c0a018a;
case 0x0c0a018cu: goto P_0c0a018c;
case 0x0c0a018eu: goto P_0c0a018e;
case 0x0c0a0190u: goto P_0c0a0190;
case 0x0c0a0192u: goto P_0c0a0192;
case 0x0c0a0194u: goto P_0c0a0194;
case 0x0c0a0196u: goto P_0c0a0196;
case 0x0c0a0198u: goto P_0c0a0198;
case 0x0c0a019au: goto P_0c0a019a;
case 0x0c0a019cu: goto P_0c0a019c;
case 0x0c0a019eu: goto P_0c0a019e;
case 0x0c0a01a0u: goto P_0c0a01a0;
case 0x0c0a01a2u: goto P_0c0a01a2;
case 0x0c0a01a4u: goto P_0c0a01a4;
case 0x0c0a01a6u: goto P_0c0a01a6;
case 0x0c0a01a8u: goto P_0c0a01a8;
case 0x0c0a01aau: goto P_0c0a01aa;
case 0x0c0a01acu: goto P_0c0a01ac;
case 0x0c0a01aeu: goto P_0c0a01ae;
case 0x0c0a01b0u: goto P_0c0a01b0;
case 0x0c0a01b2u: goto P_0c0a01b2;
case 0x0c0a01b4u: goto P_0c0a01b4;
case 0x0c0a01b6u: goto P_0c0a01b6;
case 0x0c0a01b8u: goto P_0c0a01b8;
case 0x0c0a01bau: goto P_0c0a01ba;
case 0x0c0a01bcu: goto P_0c0a01bc;
case 0x0c0a01beu: goto P_0c0a01be;
case 0x0c0a01c0u: goto P_0c0a01c0;
case 0x0c0a01c2u: goto P_0c0a01c2;
case 0x0c0a01c4u: goto P_0c0a01c4;
case 0x0c0a01c6u: goto P_0c0a01c6;
case 0x0c0a01c8u: goto P_0c0a01c8;
case 0x0c0a01cau: goto P_0c0a01ca;
case 0x0c0a01ccu: goto P_0c0a01cc;
case 0x0c0a01ceu: goto P_0c0a01ce;
case 0x0c0a01d0u: goto P_0c0a01d0;
case 0x0c0a01d2u: goto P_0c0a01d2;
case 0x0c0a01d4u: goto P_0c0a01d4;
case 0x0c0a01d6u: goto P_0c0a01d6;
case 0x0c0a01d8u: goto P_0c0a01d8;
case 0x0c0a01dau: goto P_0c0a01da;
case 0x0c0a01dcu: goto P_0c0a01dc;
case 0x0c0a01deu: goto P_0c0a01de;
case 0x0c0a01e0u: goto P_0c0a01e0;
case 0x0c0a01e2u: goto P_0c0a01e2;
case 0x0c0a01e4u: goto P_0c0a01e4;
case 0x0c0a01e6u: goto P_0c0a01e6;
case 0x0c0a01e8u: goto P_0c0a01e8;
case 0x0c0a020cu: goto P_0c0a020c;
case 0x0c0a020eu: goto P_0c0a020e;
case 0x0c0a0210u: goto P_0c0a0210;
case 0x0c0a0212u: goto P_0c0a0212;
case 0x0c0a0214u: goto P_0c0a0214;
case 0x0c0a0216u: goto P_0c0a0216;
case 0x0c0a0218u: goto P_0c0a0218;
case 0x0c0a021au: goto P_0c0a021a;
case 0x0c0a021cu: goto P_0c0a021c;
case 0x0c0a021eu: goto P_0c0a021e;
case 0x0c0a0220u: goto P_0c0a0220;
case 0x0c0a0222u: goto P_0c0a0222;
case 0x0c0a0224u: goto P_0c0a0224;
case 0x0c0a0226u: goto P_0c0a0226;
case 0x0c0a0228u: goto P_0c0a0228;
case 0x0c0a022au: goto P_0c0a022a;
case 0x0c0a022cu: goto P_0c0a022c;
case 0x0c0a022eu: goto P_0c0a022e;
case 0x0c0a0230u: goto P_0c0a0230;
case 0x0c0a0232u: goto P_0c0a0232;
case 0x0c0a0234u: goto P_0c0a0234;
case 0x0c0a0236u: goto P_0c0a0236;
case 0x0c0a0238u: goto P_0c0a0238;
case 0x0c0a023au: goto P_0c0a023a;
case 0x0c0a023cu: goto P_0c0a023c;
case 0x0c0a023eu: goto P_0c0a023e;
case 0x0c0a0240u: goto P_0c0a0240;
case 0x0c0a0242u: goto P_0c0a0242;
case 0x0c0a0244u: goto P_0c0a0244;
case 0x0c0a0246u: goto P_0c0a0246;
case 0x0c0a0248u: goto P_0c0a0248;
case 0x0c0a024au: goto P_0c0a024a;
case 0x0c0a024cu: goto P_0c0a024c;
case 0x0c0a024eu: goto P_0c0a024e;
case 0x0c0a0250u: goto P_0c0a0250;
case 0x0c0a0252u: goto P_0c0a0252;
case 0x0c0a0254u: goto P_0c0a0254;
case 0x0c0a0256u: goto P_0c0a0256;
case 0x0c0a0258u: goto P_0c0a0258;
case 0x0c0a025au: goto P_0c0a025a;
case 0x0c0a025cu: goto P_0c0a025c;
case 0x0c0a025eu: goto P_0c0a025e;
case 0x0c0a0260u: goto P_0c0a0260;
case 0x0c0a0262u: goto P_0c0a0262;
case 0x0c0a0264u: goto P_0c0a0264;
case 0x0c0a0266u: goto P_0c0a0266;
case 0x0c0a0268u: goto P_0c0a0268;
case 0x0c0a026au: goto P_0c0a026a;
case 0x0c0a026cu: goto P_0c0a026c;
case 0x0c0a026eu: goto P_0c0a026e;
case 0x0c0a0270u: goto P_0c0a0270;
case 0x0c0a0272u: goto P_0c0a0272;
case 0x0c0a0274u: goto P_0c0a0274;
case 0x0c0a0276u: goto P_0c0a0276;
case 0x0c0a0278u: goto P_0c0a0278;
case 0x0c0a027au: goto P_0c0a027a;
case 0x0c0a027cu: goto P_0c0a027c;
case 0x0c0a027eu: goto P_0c0a027e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09fe68: /* original 2fe6, guest PC 0x0c09fe68 */
if(!s->budget--) { s->failed_pc=0x0c09fe68u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe6a;
P_0c09fe6a: /* original 2fd6, guest PC 0x0c09fe6a */
if(!s->budget--) { s->failed_pc=0x0c09fe6au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe6c;
P_0c09fe6c: /* original 2fc6, guest PC 0x0c09fe6c */
if(!s->budget--) { s->failed_pc=0x0c09fe6cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe6e;
P_0c09fe6e: /* original 2fb6, guest PC 0x0c09fe6e */
if(!s->budget--) { s->failed_pc=0x0c09fe6eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe70;
P_0c09fe70: /* original 2fa6, guest PC 0x0c09fe70 */
if(!s->budget--) { s->failed_pc=0x0c09fe70u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe72;
P_0c09fe72: /* original 2f96, guest PC 0x0c09fe72 */
if(!s->budget--) { s->failed_pc=0x0c09fe72u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe74;
P_0c09fe74: /* original e900, guest PC 0x0c09fe74 */
if(!s->budget--) { s->failed_pc=0x0c09fe74u; return 0; }
r[9]=0x00000000u;
goto P_0c09fe76;
P_0c09fe76: /* original 2f86, guest PC 0x0c09fe76 */
if(!s->budget--) { s->failed_pc=0x0c09fe76u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fe78;
P_0c09fe78: /* original e812, guest PC 0x0c09fe78 */
if(!s->budget--) { s->failed_pc=0x0c09fe78u; return 0; }
r[8]=0x00000012u;
goto P_0c09fe7a;
P_0c09fe7a: /* original 4f22, guest PC 0x0c09fe7a */
if(!s->budget--) { s->failed_pc=0x0c09fe7au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09fe7c;
P_0c09fe7c: /* original d343, guest PC 0x0c09fe7c */
if(!s->budget--) { s->failed_pc=0x0c09fe7cu; return 0; }
r[3]=read(ram,0x0c09ff8cu,4);
goto P_0c09fe7e;
P_0c09fe7e: /* original 6e93, guest PC 0x0c09fe7e */
if(!s->budget--) { s->failed_pc=0x0c09fe7eu; return 0; }
r[14]=r[9];
goto P_0c09fe80;
P_0c09fe80: /* original dc41, guest PC 0x0c09fe80 */
if(!s->budget--) { s->failed_pc=0x0c09fe80u; return 0; }
r[12]=read(ram,0x0c09ff88u,4);
goto P_0c09fe82;
P_0c09fe82: /* original 7ff0, guest PC 0x0c09fe82 */
if(!s->budget--) { s->failed_pc=0x0c09fe82u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09fe84;
P_0c09fe84: /* original 2f32, guest PC 0x0c09fe84 */
if(!s->budget--) { s->failed_pc=0x0c09fe84u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09fe86;
P_0c09fe86: /* original 6bc3, guest PC 0x0c09fe86 */
if(!s->budget--) { s->failed_pc=0x0c09fe86u; return 0; }
r[11]=r[12];
goto P_0c09fe88;
P_0c09fe88: /* original d241, guest PC 0x0c09fe88 */
if(!s->budget--) { s->failed_pc=0x0c09fe88u; return 0; }
r[2]=read(ram,0x0c09ff90u,4);
goto P_0c09fe8a;
P_0c09fe8a: /* original 1f23, guest PC 0x0c09fe8a */
if(!s->budget--) { s->failed_pc=0x0c09fe8au; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c09fe8c;
P_0c09fe8c: /* original d341, guest PC 0x0c09fe8c */
if(!s->budget--) { s->failed_pc=0x0c09fe8cu; return 0; }
r[3]=read(ram,0x0c09ff94u,4);
goto P_0c09fe8e;
P_0c09fe8e: /* original 1f31, guest PC 0x0c09fe8e */
if(!s->budget--) { s->failed_pc=0x0c09fe8eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09fe90;
P_0c09fe90: /* original d241, guest PC 0x0c09fe90 */
if(!s->budget--) { s->failed_pc=0x0c09fe90u; return 0; }
r[2]=read(ram,0x0c09ff98u,4);
goto P_0c09fe92;
P_0c09fe92: /* original 1f22, guest PC 0x0c09fe92 */
if(!s->budget--) { s->failed_pc=0x0c09fe92u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c09fe94;
P_0c09fe94: /* original 9a73, guest PC 0x0c09fe94 */
if(!s->budget--) { s->failed_pc=0x0c09fe94u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ff7eu,2);
goto P_0c09fe96;
P_0c09fe96: /* original dd41, guest PC 0x0c09fe96 */
if(!s->budget--) { s->failed_pc=0x0c09fe96u; return 0; }
r[13]=read(ram,0x0c09ff9cu,4);
goto P_0c09fe98;
P_0c09fe98: /* original 3acc, guest PC 0x0c09fe98 */
if(!s->budget--) { s->failed_pc=0x0c09fe98u; return 0; }
r[10]+=r[12];
goto P_0c09fe9a;
P_0c09fe9a: /* original 65f2, guest PC 0x0c09fe9a */
if(!s->budget--) { s->failed_pc=0x0c09fe9au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c09fe9c;
P_0c09fe9c: /* original 7504, guest PC 0x0c09fe9c */
if(!s->budget--) { s->failed_pc=0x0c09fe9cu; return 0; }
r[5]+=0x00000004u;
goto P_0c09fe9e;
P_0c09fe9e: /* original 2f52, guest PC 0x0c09fe9e */
if(!s->budget--) { s->failed_pc=0x0c09fe9eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c09fea0;
P_0c09fea0: /* original 75fc, guest PC 0x0c09fea0 */
if(!s->budget--) { s->failed_pc=0x0c09fea0u; return 0; }
r[5]+=0xfffffffcu;
goto P_0c09fea2;
P_0c09fea2: /* original 6552, guest PC 0x0c09fea2 */
if(!s->budget--) { s->failed_pc=0x0c09fea2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c09fea4;
P_0c09fea4: /* original 4d0b, guest PC 0x0c09fea4 */
if(!s->budget--) { s->failed_pc=0x0c09fea4u; return 0; }
target=r[13];
r[16]=code_base|0x0c09fea8u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fea8u) { target=s->pc; goto dispatch; }
goto P_0c09fea8;
P_0c09fea6: /* original 64b3, guest PC 0x0c09fea6 */
if(!s->budget--) { s->failed_pc=0x0c09fea6u; return 0; }
r[4]=r[11];
goto P_0c09fea8;
P_0c09fea8: /* original 55f3, guest PC 0x0c09fea8 */
if(!s->budget--) { s->failed_pc=0x0c09fea8u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c09feaa;
P_0c09feaa: /* original 64c3, guest PC 0x0c09feaa */
if(!s->budget--) { s->failed_pc=0x0c09feaau; return 0; }
r[4]=r[12];
goto P_0c09feac;
P_0c09feac: /* original 7448, guest PC 0x0c09feac */
if(!s->budget--) { s->failed_pc=0x0c09feacu; return 0; }
r[4]+=0x00000048u;
goto P_0c09feae;
P_0c09feae: /* original 7504, guest PC 0x0c09feae */
if(!s->budget--) { s->failed_pc=0x0c09feaeu; return 0; }
r[5]+=0x00000004u;
goto P_0c09feb0;
P_0c09feb0: /* original 1f53, guest PC 0x0c09feb0 */
if(!s->budget--) { s->failed_pc=0x0c09feb0u; return 0; }
write(ram,r[15]+12,r[5],4);
goto P_0c09feb2;
P_0c09feb2: /* original 75fc, guest PC 0x0c09feb2 */
if(!s->budget--) { s->failed_pc=0x0c09feb2u; return 0; }
r[5]+=0xfffffffcu;
goto P_0c09feb4;
P_0c09feb4: /* original 6552, guest PC 0x0c09feb4 */
if(!s->budget--) { s->failed_pc=0x0c09feb4u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c09feb6;
P_0c09feb6: /* original 4d0b, guest PC 0x0c09feb6 */
if(!s->budget--) { s->failed_pc=0x0c09feb6u; return 0; }
target=r[13];
r[16]=code_base|0x0c09febau;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09febau) { target=s->pc; goto dispatch; }
goto P_0c09feba;
P_0c09feb8: /* original 34ec, guest PC 0x0c09feb8 */
if(!s->budget--) { s->failed_pc=0x0c09feb8u; return 0; }
r[4]+=r[14];
goto P_0c09feba;
P_0c09feba: /* original 55f1, guest PC 0x0c09feba */
if(!s->budget--) { s->failed_pc=0x0c09febau; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c09febc;
P_0c09febc: /* original 7502, guest PC 0x0c09febc */
if(!s->budget--) { s->failed_pc=0x0c09febcu; return 0; }
r[5]+=0x00000002u;
goto P_0c09febe;
P_0c09febe: /* original 1f51, guest PC 0x0c09febe */
if(!s->budget--) { s->failed_pc=0x0c09febeu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c09fec0;
P_0c09fec0: /* original 75fe, guest PC 0x0c09fec0 */
if(!s->budget--) { s->failed_pc=0x0c09fec0u; return 0; }
r[5]+=0xfffffffeu;
goto P_0c09fec2;
P_0c09fec2: /* original 945d, guest PC 0x0c09fec2 */
if(!s->budget--) { s->failed_pc=0x0c09fec2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ff80u,2);
goto P_0c09fec4;
P_0c09fec4: /* original 6551, guest PC 0x0c09fec4 */
if(!s->budget--) { s->failed_pc=0x0c09fec4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c09fec6;
P_0c09fec6: /* original 34cc, guest PC 0x0c09fec6 */
if(!s->budget--) { s->failed_pc=0x0c09fec6u; return 0; }
r[4]+=r[12];
goto P_0c09fec8;
P_0c09fec8: /* original 655d, guest PC 0x0c09fec8 */
if(!s->budget--) { s->failed_pc=0x0c09fec8u; return 0; }
r[5]=r[5]&65535u;
goto P_0c09feca;
P_0c09feca: /* original 4d0b, guest PC 0x0c09feca */
if(!s->budget--) { s->failed_pc=0x0c09fecau; return 0; }
target=r[13];
r[16]=code_base|0x0c09feceu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09feceu) { target=s->pc; goto dispatch; }
goto P_0c09fece;
P_0c09fecc: /* original 34ec, guest PC 0x0c09fecc */
if(!s->budget--) { s->failed_pc=0x0c09feccu; return 0; }
r[4]+=r[14];
goto P_0c09fece;
P_0c09fece: /* original 55f2, guest PC 0x0c09fece */
if(!s->budget--) { s->failed_pc=0x0c09feceu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c09fed0;
P_0c09fed0: /* original 7501, guest PC 0x0c09fed0 */
if(!s->budget--) { s->failed_pc=0x0c09fed0u; return 0; }
r[5]+=0x00000001u;
goto P_0c09fed2;
P_0c09fed2: /* original 1f52, guest PC 0x0c09fed2 */
if(!s->budget--) { s->failed_pc=0x0c09fed2u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c09fed4;
P_0c09fed4: /* original 75ff, guest PC 0x0c09fed4 */
if(!s->budget--) { s->failed_pc=0x0c09fed4u; return 0; }
r[5]+=0xffffffffu;
goto P_0c09fed6;
P_0c09fed6: /* original d332, guest PC 0x0c09fed6 */
if(!s->budget--) { s->failed_pc=0x0c09fed6u; return 0; }
r[3]=read(ram,0x0c09ffa0u,4);
goto P_0c09fed8;
P_0c09fed8: /* original 6550, guest PC 0x0c09fed8 */
if(!s->budget--) { s->failed_pc=0x0c09fed8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c09feda;
P_0c09feda: /* original 430b, guest PC 0x0c09feda */
if(!s->budget--) { s->failed_pc=0x0c09fedau; return 0; }
target=r[3];
r[16]=code_base|0x0c09fedeu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fedeu) { target=s->pc; goto dispatch; }
goto P_0c09fede;
P_0c09fedc: /* original 64a3, guest PC 0x0c09fedc */
if(!s->budget--) { s->failed_pc=0x0c09fedcu; return 0; }
r[4]=r[10];
goto P_0c09fede;
P_0c09fede: /* original 7901, guest PC 0x0c09fede */
if(!s->budget--) { s->failed_pc=0x0c09fedeu; return 0; }
r[9]+=0x00000001u;
goto P_0c09fee0;
P_0c09fee0: /* original 3983, guest PC 0x0c09fee0 */
if(!s->budget--) { s->failed_pc=0x0c09fee0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[8])!=0);
goto P_0c09fee2;
P_0c09fee2: /* original 7e04, guest PC 0x0c09fee2 */
if(!s->budget--) { s->failed_pc=0x0c09fee2u; return 0; }
r[14]+=0x00000004u;
goto P_0c09fee4;
P_0c09fee4: /* original 7a01, guest PC 0x0c09fee4 */
if(!s->budget--) { s->failed_pc=0x0c09fee4u; return 0; }
r[10]+=0x00000001u;
goto P_0c09fee6;
P_0c09fee6: /* original 8fd8, guest PC 0x0c09fee6 */
if(!s->budget--) { s->failed_pc=0x0c09fee6u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000004u;
if(!cond) { goto P_0c09fe9a; }
goto P_0c09feea;
P_0c09fee8: /* original 7b04, guest PC 0x0c09fee8 */
if(!s->budget--) { s->failed_pc=0x0c09fee8u; return 0; }
r[11]+=0x00000004u;
goto P_0c09feea;
P_0c09feea: /* original 7f10, guest PC 0x0c09feea */
if(!s->budget--) { s->failed_pc=0x0c09feeau; return 0; }
r[15]+=0x00000010u;
goto P_0c09feec;
P_0c09feec: /* original 4f26, guest PC 0x0c09feec */
if(!s->budget--) { s->failed_pc=0x0c09feecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09feee;
P_0c09feee: /* original 68f6, guest PC 0x0c09feee */
if(!s->budget--) { s->failed_pc=0x0c09feeeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09fef0;
P_0c09fef0: /* original 69f6, guest PC 0x0c09fef0 */
if(!s->budget--) { s->failed_pc=0x0c09fef0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09fef2;
P_0c09fef2: /* original 6af6, guest PC 0x0c09fef2 */
if(!s->budget--) { s->failed_pc=0x0c09fef2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09fef4;
P_0c09fef4: /* original 6bf6, guest PC 0x0c09fef4 */
if(!s->budget--) { s->failed_pc=0x0c09fef4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09fef6;
P_0c09fef6: /* original 6cf6, guest PC 0x0c09fef6 */
if(!s->budget--) { s->failed_pc=0x0c09fef6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09fef8;
P_0c09fef8: /* original 6df6, guest PC 0x0c09fef8 */
if(!s->budget--) { s->failed_pc=0x0c09fef8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09fefa;
P_0c09fefa: /* original 000b, guest PC 0x0c09fefa */
if(!s->budget--) { s->failed_pc=0x0c09fefau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09fefc: /* original 6ef6, guest PC 0x0c09fefc */
if(!s->budget--) { s->failed_pc=0x0c09fefcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09fefeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09fefeu; return 0; } return 1;
P_0c0a00b6: /* original 2fe6, guest PC 0x0c0a00b6 */
if(!s->budget--) { s->failed_pc=0x0c0a00b6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a00b8;
P_0c0a00b8: /* original 2fd6, guest PC 0x0c0a00b8 */
if(!s->budget--) { s->failed_pc=0x0c0a00b8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a00ba;
P_0c0a00ba: /* original 2fc6, guest PC 0x0c0a00ba */
if(!s->budget--) { s->failed_pc=0x0c0a00bau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a00bc;
P_0c0a00bc: /* original 2fb6, guest PC 0x0c0a00bc */
if(!s->budget--) { s->failed_pc=0x0c0a00bcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a00be;
P_0c0a00be: /* original 2fa6, guest PC 0x0c0a00be */
if(!s->budget--) { s->failed_pc=0x0c0a00beu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a00c0;
P_0c0a00c0: /* original 2f96, guest PC 0x0c0a00c0 */
if(!s->budget--) { s->failed_pc=0x0c0a00c0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a00c2;
P_0c0a00c2: /* original 2f86, guest PC 0x0c0a00c2 */
if(!s->budget--) { s->failed_pc=0x0c0a00c2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a00c4;
P_0c0a00c4: /* original de13, guest PC 0x0c0a00c4 */
if(!s->budget--) { s->failed_pc=0x0c0a00c4u; return 0; }
r[14]=read(ram,0x0c0a0114u,4);
goto P_0c0a00c6;
P_0c0a00c6: /* original dd14, guest PC 0x0c0a00c6 */
if(!s->budget--) { s->failed_pc=0x0c0a00c6u; return 0; }
r[13]=read(ram,0x0c0a0118u,4);
goto P_0c0a00c8;
P_0c0a00c8: /* original 4f22, guest PC 0x0c0a00c8 */
if(!s->budget--) { s->failed_pc=0x0c0a00c8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a00ca;
P_0c0a00ca: /* original d314, guest PC 0x0c0a00ca */
if(!s->budget--) { s->failed_pc=0x0c0a00cau; return 0; }
r[3]=read(ram,0x0c0a011cu,4);
goto P_0c0a00cc;
P_0c0a00cc: /* original 7ff8, guest PC 0x0c0a00cc */
if(!s->budget--) { s->failed_pc=0x0c0a00ccu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a00ce;
P_0c0a00ce: /* original 1f31, guest PC 0x0c0a00ce */
if(!s->budget--) { s->failed_pc=0x0c0a00ceu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0a00d0;
P_0c0a00d0: /* original 9016, guest PC 0x0c0a00d0 */
if(!s->budget--) { s->failed_pc=0x0c0a00d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0100u,2);
goto P_0c0a00d2;
P_0c0a00d2: /* original 05ec, guest PC 0x0c0a00d2 */
if(!s->budget--) { s->failed_pc=0x0c0a00d2u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a00d4;
P_0c0a00d4: /* original 7001, guest PC 0x0c0a00d4 */
if(!s->budget--) { s->failed_pc=0x0c0a00d4u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a00d6;
P_0c0a00d6: /* original 04ec, guest PC 0x0c0a00d6 */
if(!s->budget--) { s->failed_pc=0x0c0a00d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a00d8;
P_0c0a00d8: /* original 9013, guest PC 0x0c0a00d8 */
if(!s->budget--) { s->failed_pc=0x0c0a00d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0102u,2);
goto P_0c0a00da;
P_0c0a00da: /* original 06de, guest PC 0x0c0a00da */
if(!s->budget--) { s->failed_pc=0x0c0a00dau; return 0; }
r[6]=read(ram,r[13]+r[0],4);
goto P_0c0a00dc;
P_0c0a00dc: /* original 70fc, guest PC 0x0c0a00dc */
if(!s->budget--) { s->failed_pc=0x0c0a00dcu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0a00de;
P_0c0a00de: /* original 07de, guest PC 0x0c0a00de */
if(!s->budget--) { s->failed_pc=0x0c0a00deu; return 0; }
r[7]=read(ram,r[13]+r[0],4);
goto P_0c0a00e0;
P_0c0a00e0: /* original 7004, guest PC 0x0c0a00e0 */
if(!s->budget--) { s->failed_pc=0x0c0a00e0u; return 0; }
r[0]+=0x00000004u;
goto P_0c0a00e2;
P_0c0a00e2: /* original 0ade, guest PC 0x0c0a00e2 */
if(!s->budget--) { s->failed_pc=0x0c0a00e2u; return 0; }
r[10]=read(ram,r[13]+r[0],4);
goto P_0c0a00e4;
P_0c0a00e4: /* original e029, guest PC 0x0c0a00e4 */
if(!s->budget--) { s->failed_pc=0x0c0a00e4u; return 0; }
r[0]=0x00000029u;
goto P_0c0a00e6;
P_0c0a00e6: /* original 00ec, guest PC 0x0c0a00e6 */
if(!s->budget--) { s->failed_pc=0x0c0a00e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a00e8;
P_0c0a00e8: /* original 600c, guest PC 0x0c0a00e8 */
if(!s->budget--) { s->failed_pc=0x0c0a00e8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0a00ea;
P_0c0a00ea: /* original 8801, guest PC 0x0c0a00ea */
if(!s->budget--) { s->failed_pc=0x0c0a00eau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a00ec;
P_0c0a00ec: /* original 8f18, guest PC 0x0c0a00ec */
if(!s->budget--) { s->failed_pc=0x0c0a00ecu; return 0; }
cond=r[17]&1u;
r[11]=0x00000000u;
if(!cond) { goto P_0c0a0120; }
goto P_0c0a00f0;
P_0c0a00ee: /* original eb00, guest PC 0x0c0a00ee */
if(!s->budget--) { s->failed_pc=0x0c0a00eeu; return 0; }
r[11]=0x00000000u;
goto P_0c0a00f0;
P_0c0a00f0: /* original a018, guest PC 0x0c0a00f0 */
if(!s->budget--) { s->failed_pc=0x0c0a00f0u; return 0; }
r[12]=r[11];
goto P_0c0a0124;
P_0c0a00f2: /* original 6cb3, guest PC 0x0c0a00f2 */
if(!s->budget--) { s->failed_pc=0x0c0a00f2u; return 0; }
r[12]=r[11];
if(!vf3_matrix_family(0x0c0a00f4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a00f4u; return 0; } return 1;
P_0c0a0120: /* original 4a21, guest PC 0x0c0a0120 */
if(!s->budget--) { s->failed_pc=0x0c0a0120u; return 0; }
r[17]=(r[17]&~1u)|((r[10]&1)!=0);
r[10]=(uint32_t)((int32_t)r[10]>>1);
goto P_0c0a0122;
P_0c0a0122: /* original ec08, guest PC 0x0c0a0122 */
if(!s->budget--) { s->failed_pc=0x0c0a0122u; return 0; }
r[12]=0x00000008u;
goto P_0c0a0124;
P_0c0a0124: /* original 63cb, guest PC 0x0c0a0124 */
if(!s->budget--) { s->failed_pc=0x0c0a0124u; return 0; }
r[3]=0u-r[12];
goto P_0c0a0126;
P_0c0a0126: /* original 9860, guest PC 0x0c0a0126 */
if(!s->budget--) { s->failed_pc=0x0c0a0126u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a01eau,2);
goto P_0c0a0128;
P_0c0a0128: /* original e203, guest PC 0x0c0a0128 */
if(!s->budget--) { s->failed_pc=0x0c0a0128u; return 0; }
r[2]=0x00000003u;
goto P_0c0a012a;
P_0c0a012a: /* original 6ccb, guest PC 0x0c0a012a */
if(!s->budget--) { s->failed_pc=0x0c0a012au; return 0; }
r[12]=0u-r[12];
goto P_0c0a012c;
P_0c0a012c: /* original 3523, guest PC 0x0c0a012c */
if(!s->budget--) { s->failed_pc=0x0c0a012cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[2])!=0);
goto P_0c0a012e;
P_0c0a012e: /* original e91f, guest PC 0x0c0a012e */
if(!s->budget--) { s->failed_pc=0x0c0a012eu; return 0; }
r[9]=0x0000001fu;
goto P_0c0a0130;
P_0c0a0130: /* original 463c, guest PC 0x0c0a0130 */
if(!s->budget--) { s->failed_pc=0x0c0a0130u; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[6]>>((-r[3])&31u)):((int32_t)r[6]<0?0xffffffffu:0)):r[6]<<(r[3]&31u);
goto P_0c0a0132;
P_0c0a0132: /* original 47cc, guest PC 0x0c0a0132 */
if(!s->budget--) { s->failed_pc=0x0c0a0132u; return 0; }
r[7]=(r[12]&0x80000000u)?((r[12]&31u)?(uint32_t)((int32_t)r[7]>>((-r[12])&31u)):((int32_t)r[7]<0?0xffffffffu:0)):r[7]<<(r[12]&31u);
goto P_0c0a0134;
P_0c0a0134: /* original 8f0d, guest PC 0x0c0a0134 */
if(!s->budget--) { s->failed_pc=0x0c0a0134u; return 0; }
cond=r[17]&1u;
r[12]=0x00000001u;
if(!cond) { goto P_0c0a0152; }
goto P_0c0a0138;
P_0c0a0136: /* original ec01, guest PC 0x0c0a0136 */
if(!s->budget--) { s->failed_pc=0x0c0a0136u; return 0; }
r[12]=0x00000001u;
goto P_0c0a0138;
P_0c0a0138: /* original e31e, guest PC 0x0c0a0138 */
if(!s->budget--) { s->failed_pc=0x0c0a0138u; return 0; }
r[3]=0x0000001eu;
goto P_0c0a013a;
P_0c0a013a: /* original 3433, guest PC 0x0c0a013a */
if(!s->budget--) { s->failed_pc=0x0c0a013au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0a013c;
P_0c0a013c: /* original 8b01, guest PC 0x0c0a013c */
if(!s->budget--) { s->failed_pc=0x0c0a013cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a0142; }
goto P_0c0a013e;
P_0c0a013e: /* original 3497, guest PC 0x0c0a013e */
if(!s->budget--) { s->failed_pc=0x0c0a013eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[9])!=0);
goto P_0c0a0140;
P_0c0a0140: /* original 8b00, guest PC 0x0c0a0140 */
if(!s->budget--) { s->failed_pc=0x0c0a0140u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a0144; }
goto P_0c0a0142;
P_0c0a0142: /* original 6493, guest PC 0x0c0a0142 */
if(!s->budget--) { s->failed_pc=0x0c0a0142u; return 0; }
r[4]=r[9];
goto P_0c0a0144;
P_0c0a0144: /* original d32b, guest PC 0x0c0a0144 */
if(!s->budget--) { s->failed_pc=0x0c0a0144u; return 0; }
r[3]=read(ram,0x0c0a01f4u,4);
goto P_0c0a0146;
P_0c0a0146: /* original 2638, guest PC 0x0c0a0146 */
if(!s->budget--) { s->failed_pc=0x0c0a0146u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0a0148;
P_0c0a0148: /* original 8912, guest PC 0x0c0a0148 */
if(!s->budget--) { s->failed_pc=0x0c0a0148u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a0170; }
goto P_0c0a014a;
P_0c0a014a: /* original 2788, guest PC 0x0c0a014a */
if(!s->budget--) { s->failed_pc=0x0c0a014au; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[8])==0)!=0);
goto P_0c0a014c;
P_0c0a014c: /* original 8910, guest PC 0x0c0a014c */
if(!s->budget--) { s->failed_pc=0x0c0a014cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a0170; }
goto P_0c0a014e;
P_0c0a014e: /* original a00f, guest PC 0x0c0a014e */
if(!s->budget--) { s->failed_pc=0x0c0a014eu; return 0; }
r[4]^=r[12];
goto P_0c0a0170;
P_0c0a0150: /* original 24ca, guest PC 0x0c0a0150 */
if(!s->budget--) { s->failed_pc=0x0c0a0150u; return 0; }
r[4]^=r[12];
goto P_0c0a0152;
P_0c0a0152: /* original 924b, guest PC 0x0c0a0152 */
if(!s->budget--) { s->failed_pc=0x0c0a0152u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a01ecu,2);
goto P_0c0a0154;
P_0c0a0154: /* original 2268, guest PC 0x0c0a0154 */
if(!s->budget--) { s->failed_pc=0x0c0a0154u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c0a0156;
P_0c0a0156: /* original 8904, guest PC 0x0c0a0156 */
if(!s->budget--) { s->failed_pc=0x0c0a0156u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a0162; }
goto P_0c0a0158;
P_0c0a0158: /* original 6373, guest PC 0x0c0a0158 */
if(!s->budget--) { s->failed_pc=0x0c0a0158u; return 0; }
r[3]=r[7];
goto P_0c0a015a;
P_0c0a015a: /* original 2388, guest PC 0x0c0a015a */
if(!s->budget--) { s->failed_pc=0x0c0a015au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0a015c;
P_0c0a015c: /* original 8901, guest PC 0x0c0a015c */
if(!s->budget--) { s->failed_pc=0x0c0a015cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a0162; }
goto P_0c0a015e;
P_0c0a015e: /* original 7401, guest PC 0x0c0a015e */
if(!s->budget--) { s->failed_pc=0x0c0a015eu; return 0; }
r[4]+=0x00000001u;
goto P_0c0a0160;
P_0c0a0160: /* original 2499, guest PC 0x0c0a0160 */
if(!s->budget--) { s->failed_pc=0x0c0a0160u; return 0; }
r[4]&=r[9];
goto P_0c0a0162;
P_0c0a0162: /* original d325, guest PC 0x0c0a0162 */
if(!s->budget--) { s->failed_pc=0x0c0a0162u; return 0; }
r[3]=read(ram,0x0c0a01f8u,4);
goto P_0c0a0164;
P_0c0a0164: /* original 2638, guest PC 0x0c0a0164 */
if(!s->budget--) { s->failed_pc=0x0c0a0164u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0a0166;
P_0c0a0166: /* original 8903, guest PC 0x0c0a0166 */
if(!s->budget--) { s->failed_pc=0x0c0a0166u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a0170; }
goto P_0c0a0168;
P_0c0a0168: /* original 2788, guest PC 0x0c0a0168 */
if(!s->budget--) { s->failed_pc=0x0c0a0168u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[8])==0)!=0);
goto P_0c0a016a;
P_0c0a016a: /* original 8901, guest PC 0x0c0a016a */
if(!s->budget--) { s->failed_pc=0x0c0a016au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a0170; }
goto P_0c0a016c;
P_0c0a016c: /* original 74ff, guest PC 0x0c0a016c */
if(!s->budget--) { s->failed_pc=0x0c0a016cu; return 0; }
r[4]+=0xffffffffu;
goto P_0c0a016e;
P_0c0a016e: /* original 2499, guest PC 0x0c0a016e */
if(!s->budget--) { s->failed_pc=0x0c0a016eu; return 0; }
r[4]&=r[9];
goto P_0c0a0170;
P_0c0a0170: /* original 903d, guest PC 0x0c0a0170 */
if(!s->budget--) { s->failed_pc=0x0c0a0170u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a01eeu,2);
goto P_0c0a0172;
P_0c0a0172: /* original 0e44, guest PC 0x0c0a0172 */
if(!s->budget--) { s->failed_pc=0x0c0a0172u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a0174;
P_0c0a0174: /* original d021, guest PC 0x0c0a0174 */
if(!s->budget--) { s->failed_pc=0x0c0a0174u; return 0; }
r[0]=read(ram,0x0c0a01fcu,4);
goto P_0c0a0176;
P_0c0a0176: /* original 973b, guest PC 0x0c0a0176 */
if(!s->budget--) { s->failed_pc=0x0c0a0176u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a01f0u,2);
goto P_0c0a0178;
P_0c0a0178: /* original 064c, guest PC 0x0c0a0178 */
if(!s->budget--) { s->failed_pc=0x0c0a0178u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a017a;
P_0c0a017a: /* original 903a, guest PC 0x0c0a017a */
if(!s->budget--) { s->failed_pc=0x0c0a017au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a01f2u,2);
goto P_0c0a017c;
P_0c0a017c: /* original 09ec, guest PC 0x0c0a017c */
if(!s->budget--) { s->failed_pc=0x0c0a017cu; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a017e;
P_0c0a017e: /* original 70fe, guest PC 0x0c0a017e */
if(!s->budget--) { s->failed_pc=0x0c0a017eu; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0a0180;
P_0c0a0180: /* original 03ed, guest PC 0x0c0a0180 */
if(!s->budget--) { s->failed_pc=0x0c0a0180u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a0182;
P_0c0a0182: /* original 699c, guest PC 0x0c0a0182 */
if(!s->budget--) { s->failed_pc=0x0c0a0182u; return 0; }
r[9]=r[9]&255u;
goto P_0c0a0184;
P_0c0a0184: /* original 6093, guest PC 0x0c0a0184 */
if(!s->budget--) { s->failed_pc=0x0c0a0184u; return 0; }
r[0]=r[9];
goto P_0c0a0186;
P_0c0a0186: /* original 8801, guest PC 0x0c0a0186 */
if(!s->budget--) { s->failed_pc=0x0c0a0186u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a0188;
P_0c0a0188: /* original 2f32, guest PC 0x0c0a0188 */
if(!s->budget--) { s->failed_pc=0x0c0a0188u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a018a;
P_0c0a018a: /* original 8f02, guest PC 0x0c0a018a */
if(!s->budget--) { s->failed_pc=0x0c0a018au; return 0; }
cond=r[17]&1u;
r[7]+=r[14];
if(!cond) { goto P_0c0a0192; }
goto P_0c0a018e;
P_0c0a018c: /* original 37ec, guest PC 0x0c0a018c */
if(!s->budget--) { s->failed_pc=0x0c0a018cu; return 0; }
r[7]+=r[14];
goto P_0c0a018e;
P_0c0a018e: /* original a001, guest PC 0x0c0a018e */
if(!s->budget--) { s->failed_pc=0x0c0a018eu; return 0; }
r[4]=r[12];
goto P_0c0a0194;
P_0c0a0190: /* original 64c3, guest PC 0x0c0a0190 */
if(!s->budget--) { s->failed_pc=0x0c0a0190u; return 0; }
r[4]=r[12];
goto P_0c0a0192;
P_0c0a0192: /* original 64b3, guest PC 0x0c0a0192 */
if(!s->budget--) { s->failed_pc=0x0c0a0192u; return 0; }
r[4]=r[11];
goto P_0c0a0194;
P_0c0a0194: /* original 2998, guest PC 0x0c0a0194 */
if(!s->budget--) { s->failed_pc=0x0c0a0194u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0a0196;
P_0c0a0196: /* original 8b01, guest PC 0x0c0a0196 */
if(!s->budget--) { s->failed_pc=0x0c0a0196u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a019c; }
goto P_0c0a0198;
P_0c0a0198: /* original a001, guest PC 0x0c0a0198 */
if(!s->budget--) { s->failed_pc=0x0c0a0198u; return 0; }
r[8]=r[12];
goto P_0c0a019e;
P_0c0a019a: /* original 68c3, guest PC 0x0c0a019a */
if(!s->budget--) { s->failed_pc=0x0c0a019au; return 0; }
r[8]=r[12];
goto P_0c0a019c;
P_0c0a019c: /* original 68b3, guest PC 0x0c0a019c */
if(!s->budget--) { s->failed_pc=0x0c0a019cu; return 0; }
r[8]=r[11];
goto P_0c0a019e;
P_0c0a019e: /* original 63f2, guest PC 0x0c0a019e */
if(!s->budget--) { s->failed_pc=0x0c0a019eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a01a0;
P_0c0a01a0: /* original 2338, guest PC 0x0c0a01a0 */
if(!s->budget--) { s->failed_pc=0x0c0a01a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a01a2;
P_0c0a01a2: /* original 8b01, guest PC 0x0c0a01a2 */
if(!s->budget--) { s->failed_pc=0x0c0a01a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a01a8; }
goto P_0c0a01a4;
P_0c0a01a4: /* original a001, guest PC 0x0c0a01a4 */
if(!s->budget--) { s->failed_pc=0x0c0a01a4u; return 0; }
r[9]=r[12];
goto P_0c0a01aa;
P_0c0a01a6: /* original 69c3, guest PC 0x0c0a01a6 */
if(!s->budget--) { s->failed_pc=0x0c0a01a6u; return 0; }
r[9]=r[12];
goto P_0c0a01a8;
P_0c0a01a8: /* original 69b3, guest PC 0x0c0a01a8 */
if(!s->budget--) { s->failed_pc=0x0c0a01a8u; return 0; }
r[9]=r[11];
goto P_0c0a01aa;
P_0c0a01aa: /* original 2498, guest PC 0x0c0a01aa */
if(!s->budget--) { s->failed_pc=0x0c0a01aau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[9])==0)!=0);
goto P_0c0a01ac;
P_0c0a01ac: /* original 8b2e, guest PC 0x0c0a01ac */
if(!s->budget--) { s->failed_pc=0x0c0a01acu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a020c; }
goto P_0c0a01ae;
P_0c0a01ae: /* original 2888, guest PC 0x0c0a01ae */
if(!s->budget--) { s->failed_pc=0x0c0a01aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c0a01b0;
P_0c0a01b0: /* original 8916, guest PC 0x0c0a01b0 */
if(!s->budget--) { s->failed_pc=0x0c0a01b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a01e0; }
goto P_0c0a01b2;
P_0c0a01b2: /* original e210, guest PC 0x0c0a01b2 */
if(!s->budget--) { s->failed_pc=0x0c0a01b2u; return 0; }
r[2]=0x00000010u;
goto P_0c0a01b4;
P_0c0a01b4: /* original 2a28, guest PC 0x0c0a01b4 */
if(!s->budget--) { s->failed_pc=0x0c0a01b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[2])==0)!=0);
goto P_0c0a01b6;
P_0c0a01b6: /* original 8913, guest PC 0x0c0a01b6 */
if(!s->budget--) { s->failed_pc=0x0c0a01b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a01e0; }
goto P_0c0a01b8;
P_0c0a01b8: /* original e029, guest PC 0x0c0a01b8 */
if(!s->budget--) { s->failed_pc=0x0c0a01b8u; return 0; }
r[0]=0x00000029u;
goto P_0c0a01ba;
P_0c0a01ba: /* original 04ec, guest PC 0x0c0a01ba */
if(!s->budget--) { s->failed_pc=0x0c0a01bau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a01bc;
P_0c0a01bc: /* original 604c, guest PC 0x0c0a01bc */
if(!s->budget--) { s->failed_pc=0x0c0a01bcu; return 0; }
r[0]=r[4]&255u;
goto P_0c0a01be;
P_0c0a01be: /* original 8801, guest PC 0x0c0a01be */
if(!s->budget--) { s->failed_pc=0x0c0a01beu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a01c0;
P_0c0a01c0: /* original 8f03, guest PC 0x0c0a01c0 */
if(!s->budget--) { s->failed_pc=0x0c0a01c0u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c0a01ca; }
goto P_0c0a01c4;
P_0c0a01c2: /* original 6403, guest PC 0x0c0a01c2 */
if(!s->budget--) { s->failed_pc=0x0c0a01c2u; return 0; }
r[4]=r[0];
goto P_0c0a01c4;
P_0c0a01c4: /* original d20e, guest PC 0x0c0a01c4 */
if(!s->budget--) { s->failed_pc=0x0c0a01c4u; return 0; }
r[2]=read(ram,0x0c0a0200u,4);
goto P_0c0a01c6;
P_0c0a01c6: /* original a002, guest PC 0x0c0a01c6 */
if(!s->budget--) { s->failed_pc=0x0c0a01c6u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0a01ce;
P_0c0a01c8: /* original 6422, guest PC 0x0c0a01c8 */
if(!s->budget--) { s->failed_pc=0x0c0a01c8u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0a01ca;
P_0c0a01ca: /* original d10e, guest PC 0x0c0a01ca */
if(!s->budget--) { s->failed_pc=0x0c0a01cau; return 0; }
r[1]=read(ram,0x0c0a0204u,4);
goto P_0c0a01cc;
P_0c0a01cc: /* original 6412, guest PC 0x0c0a01cc */
if(!s->budget--) { s->failed_pc=0x0c0a01ccu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c0a01ce;
P_0c0a01ce: /* original d30e, guest PC 0x0c0a01ce */
if(!s->budget--) { s->failed_pc=0x0c0a01ceu; return 0; }
r[3]=read(ram,0x0c0a0208u,4);
goto P_0c0a01d0;
P_0c0a01d0: /* original 2f32, guest PC 0x0c0a01d0 */
if(!s->budget--) { s->failed_pc=0x0c0a01d0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a01d2;
P_0c0a01d2: /* original 6233, guest PC 0x0c0a01d2 */
if(!s->budget--) { s->failed_pc=0x0c0a01d2u; return 0; }
r[2]=r[3];
goto P_0c0a01d4;
P_0c0a01d4: /* original 143d, guest PC 0x0c0a01d4 */
if(!s->budget--) { s->failed_pc=0x0c0a01d4u; return 0; }
write(ram,r[4]+52,r[3],4);
goto P_0c0a01d6;
P_0c0a01d6: /* original 900c, guest PC 0x0c0a01d6 */
if(!s->budget--) { s->failed_pc=0x0c0a01d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a01f2u,2);
goto P_0c0a01d8;
P_0c0a01d8: /* original 0ec4, guest PC 0x0c0a01d8 */
if(!s->budget--) { s->failed_pc=0x0c0a01d8u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0a01da;
P_0c0a01da: /* original 70fe, guest PC 0x0c0a01da */
if(!s->budget--) { s->failed_pc=0x0c0a01dau; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0a01dc;
P_0c0a01dc: /* original a016, guest PC 0x0c0a01dc */
if(!s->budget--) { s->failed_pc=0x0c0a01dcu; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c0a020c;
P_0c0a01de: /* original 0eb5, guest PC 0x0c0a01de */
if(!s->budget--) { s->failed_pc=0x0c0a01deu; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c0a01e0;
P_0c0a01e0: /* original 52d3, guest PC 0x0c0a01e0 */
if(!s->budget--) { s->failed_pc=0x0c0a01e0u; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0a01e2;
P_0c0a01e2: /* original 4215, guest PC 0x0c0a01e2 */
if(!s->budget--) { s->failed_pc=0x0c0a01e2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0a01e4;
P_0c0a01e4: /* original 8b26, guest PC 0x0c0a01e4 */
if(!s->budget--) { s->failed_pc=0x0c0a01e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a0234; }
goto P_0c0a01e6;
P_0c0a01e6: /* original a041, guest PC 0x0c0a01e6 */
if(!s->budget--) { s->failed_pc=0x0c0a01e6u; return 0; }
goto P_0c0a026c;
P_0c0a01e8: /* original 0009, guest PC 0x0c0a01e8 */
if(!s->budget--) { s->failed_pc=0x0c0a01e8u; return 0; }
if(!vf3_matrix_family(0x0c0a01eau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a01eau; return 0; } return 1;
P_0c0a020c: /* original 646e, guest PC 0x0c0a020c */
if(!s->budget--) { s->failed_pc=0x0c0a020cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[6];
goto P_0c0a020e;
P_0c0a020e: /* original 6043, guest PC 0x0c0a020e */
if(!s->budget--) { s->failed_pc=0x0c0a020eu; return 0; }
r[0]=r[4];
goto P_0c0a0210;
P_0c0a0210: /* original 885f, guest PC 0x0c0a0210 */
if(!s->budget--) { s->failed_pc=0x0c0a0210u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000005fu)!=0);
goto P_0c0a0212;
P_0c0a0212: /* original 8906, guest PC 0x0c0a0212 */
if(!s->budget--) { s->failed_pc=0x0c0a0212u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a0222; }
goto P_0c0a0214;
P_0c0a0214: /* original 6043, guest PC 0x0c0a0214 */
if(!s->budget--) { s->failed_pc=0x0c0a0214u; return 0; }
r[0]=r[4];
goto P_0c0a0216;
P_0c0a0216: /* original 885e, guest PC 0x0c0a0216 */
if(!s->budget--) { s->failed_pc=0x0c0a0216u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000005eu)!=0);
goto P_0c0a0218;
P_0c0a0218: /* original 890c, guest PC 0x0c0a0218 */
if(!s->budget--) { s->failed_pc=0x0c0a0218u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a0234; }
goto P_0c0a021a;
P_0c0a021a: /* original 6053, guest PC 0x0c0a021a */
if(!s->budget--) { s->failed_pc=0x0c0a021au; return 0; }
r[0]=r[5];
goto P_0c0a021c;
P_0c0a021c: /* original 0764, guest PC 0x0c0a021c */
if(!s->budget--) { s->failed_pc=0x0c0a021cu; return 0; }
write(ram,r[7]+r[0],r[6],1);
goto P_0c0a021e;
P_0c0a021e: /* original a006, guest PC 0x0c0a021e */
if(!s->budget--) { s->failed_pc=0x0c0a021eu; return 0; }
r[5]+=0x00000001u;
goto P_0c0a022e;
P_0c0a0220: /* original 7501, guest PC 0x0c0a0220 */
if(!s->budget--) { s->failed_pc=0x0c0a0220u; return 0; }
r[5]+=0x00000001u;
goto P_0c0a0222;
P_0c0a0222: /* original 2558, guest PC 0x0c0a0222 */
if(!s->budget--) { s->failed_pc=0x0c0a0222u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0a0224;
P_0c0a0224: /* original 8d22, guest PC 0x0c0a0224 */
if(!s->budget--) { s->failed_pc=0x0c0a0224u; return 0; }
cond=r[17]&1u;
r[4]=0x00000020u;
if(cond) { goto P_0c0a026c; }
goto P_0c0a0228;
P_0c0a0226: /* original e420, guest PC 0x0c0a0226 */
if(!s->budget--) { s->failed_pc=0x0c0a0226u; return 0; }
r[4]=0x00000020u;
goto P_0c0a0228;
P_0c0a0228: /* original 75ff, guest PC 0x0c0a0228 */
if(!s->budget--) { s->failed_pc=0x0c0a0228u; return 0; }
r[5]+=0xffffffffu;
goto P_0c0a022a;
P_0c0a022a: /* original 6053, guest PC 0x0c0a022a */
if(!s->budget--) { s->failed_pc=0x0c0a022au; return 0; }
r[0]=r[5];
goto P_0c0a022c;
P_0c0a022c: /* original 0744, guest PC 0x0c0a022c */
if(!s->budget--) { s->failed_pc=0x0c0a022cu; return 0; }
write(ram,r[7]+r[0],r[4],1);
goto P_0c0a022e;
P_0c0a022e: /* original 907f, guest PC 0x0c0a022e */
if(!s->budget--) { s->failed_pc=0x0c0a022eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0330u,2);
goto P_0c0a0230;
P_0c0a0230: /* original a01c, guest PC 0x0c0a0230 */
if(!s->budget--) { s->failed_pc=0x0c0a0230u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0a026c;
P_0c0a0232: /* original 0e54, guest PC 0x0c0a0232 */
if(!s->budget--) { s->failed_pc=0x0c0a0232u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0a0234;
P_0c0a0234: /* original b270, guest PC 0x0c0a0234 */
if(!s->budget--) { s->failed_pc=0x0c0a0234u; return 0; }
target=code_base|0x0c0a0718u; r[16]=code_base|0x0c0a0238u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0238u) { target=s->pc; goto dispatch; }
goto P_0c0a0238;
P_0c0a0236: /* original 0009, guest PC 0x0c0a0236 */
if(!s->budget--) { s->failed_pc=0x0c0a0236u; return 0; }
goto P_0c0a0238;
P_0c0a0238: /* original 947b, guest PC 0x0c0a0238 */
if(!s->budget--) { s->failed_pc=0x0c0a0238u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0332u,2);
goto P_0c0a023a;
P_0c0a023a: /* original 34ec, guest PC 0x0c0a023a */
if(!s->budget--) { s->failed_pc=0x0c0a023au; return 0; }
r[4]+=r[14];
goto P_0c0a023c;
P_0c0a023c: /* original 8441, guest PC 0x0c0a023c */
if(!s->budget--) { s->failed_pc=0x0c0a023cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0a023e;
P_0c0a023e: /* original 6540, guest PC 0x0c0a023e */
if(!s->budget--) { s->failed_pc=0x0c0a023eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[5]=tmp;
goto P_0c0a0240;
P_0c0a0240: /* original 4018, guest PC 0x0c0a0240 */
if(!s->budget--) { s->failed_pc=0x0c0a0240u; return 0; }
r[0]<<=8;
goto P_0c0a0242;
P_0c0a0242: /* original 655c, guest PC 0x0c0a0242 */
if(!s->budget--) { s->failed_pc=0x0c0a0242u; return 0; }
r[5]=r[5]&255u;
goto P_0c0a0244;
P_0c0a0244: /* original 350c, guest PC 0x0c0a0244 */
if(!s->budget--) { s->failed_pc=0x0c0a0244u; return 0; }
r[5]+=r[0];
goto P_0c0a0246;
P_0c0a0246: /* original 8442, guest PC 0x0c0a0246 */
if(!s->budget--) { s->failed_pc=0x0c0a0246u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c0a0248;
P_0c0a0248: /* original 4028, guest PC 0x0c0a0248 */
if(!s->budget--) { s->failed_pc=0x0c0a0248u; return 0; }
r[0]<<=16;
goto P_0c0a024a;
P_0c0a024a: /* original 350c, guest PC 0x0c0a024a */
if(!s->budget--) { s->failed_pc=0x0c0a024au; return 0; }
r[5]+=r[0];
goto P_0c0a024c;
P_0c0a024c: /* original 8443, guest PC 0x0c0a024c */
if(!s->budget--) { s->failed_pc=0x0c0a024cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c0a024e;
P_0c0a024e: /* original 4028, guest PC 0x0c0a024e */
if(!s->budget--) { s->failed_pc=0x0c0a024eu; return 0; }
r[0]<<=16;
goto P_0c0a0250;
P_0c0a0250: /* original 4018, guest PC 0x0c0a0250 */
if(!s->budget--) { s->failed_pc=0x0c0a0250u; return 0; }
r[0]<<=8;
goto P_0c0a0252;
P_0c0a0252: /* original 350c, guest PC 0x0c0a0252 */
if(!s->budget--) { s->failed_pc=0x0c0a0252u; return 0; }
r[5]+=r[0];
goto P_0c0a0254;
P_0c0a0254: /* original 906e, guest PC 0x0c0a0254 */
if(!s->budget--) { s->failed_pc=0x0c0a0254u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0334u,2);
goto P_0c0a0256;
P_0c0a0256: /* original 03ec, guest PC 0x0c0a0256 */
if(!s->budget--) { s->failed_pc=0x0c0a0256u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a0258;
P_0c0a0258: /* original 2f32, guest PC 0x0c0a0258 */
if(!s->budget--) { s->failed_pc=0x0c0a0258u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a025a;
P_0c0a025a: /* original 4308, guest PC 0x0c0a025a */
if(!s->budget--) { s->failed_pc=0x0c0a025au; return 0; }
r[3]<<=2;
goto P_0c0a025c;
P_0c0a025c: /* original 54f1, guest PC 0x0c0a025c */
if(!s->budget--) { s->failed_pc=0x0c0a025cu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0a025e;
P_0c0a025e: /* original 343c, guest PC 0x0c0a025e */
if(!s->budget--) { s->failed_pc=0x0c0a025eu; return 0; }
r[4]+=r[3];
goto P_0c0a0260;
P_0c0a0260: /* original d338, guest PC 0x0c0a0260 */
if(!s->budget--) { s->failed_pc=0x0c0a0260u; return 0; }
r[3]=read(ram,0x0c0a0344u,4);
goto P_0c0a0262;
P_0c0a0262: /* original 430b, guest PC 0x0c0a0262 */
if(!s->budget--) { s->failed_pc=0x0c0a0262u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a0266u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0266u) { target=s->pc; goto dispatch; }
goto P_0c0a0266;
P_0c0a0264: /* original 0009, guest PC 0x0c0a0264 */
if(!s->budget--) { s->failed_pc=0x0c0a0264u; return 0; }
goto P_0c0a0266;
P_0c0a0266: /* original 9066, guest PC 0x0c0a0266 */
if(!s->budget--) { s->failed_pc=0x0c0a0266u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0336u,2);
goto P_0c0a0268;
P_0c0a0268: /* original 0ec4, guest PC 0x0c0a0268 */
if(!s->budget--) { s->failed_pc=0x0c0a0268u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0a026a;
P_0c0a026a: /* original 1db3, guest PC 0x0c0a026a */
if(!s->budget--) { s->failed_pc=0x0c0a026au; return 0; }
write(ram,r[13]+12,r[11],4);
goto P_0c0a026c;
P_0c0a026c: /* original 7f08, guest PC 0x0c0a026c */
if(!s->budget--) { s->failed_pc=0x0c0a026cu; return 0; }
r[15]+=0x00000008u;
goto P_0c0a026e;
P_0c0a026e: /* original 4f26, guest PC 0x0c0a026e */
if(!s->budget--) { s->failed_pc=0x0c0a026eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0270;
P_0c0a0270: /* original 68f6, guest PC 0x0c0a0270 */
if(!s->budget--) { s->failed_pc=0x0c0a0270u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a0272;
P_0c0a0272: /* original 69f6, guest PC 0x0c0a0272 */
if(!s->budget--) { s->failed_pc=0x0c0a0272u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a0274;
P_0c0a0274: /* original 6af6, guest PC 0x0c0a0274 */
if(!s->budget--) { s->failed_pc=0x0c0a0274u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a0276;
P_0c0a0276: /* original 6bf6, guest PC 0x0c0a0276 */
if(!s->budget--) { s->failed_pc=0x0c0a0276u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a0278;
P_0c0a0278: /* original 6cf6, guest PC 0x0c0a0278 */
if(!s->budget--) { s->failed_pc=0x0c0a0278u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a027a;
P_0c0a027a: /* original 6df6, guest PC 0x0c0a027a */
if(!s->budget--) { s->failed_pc=0x0c0a027au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a027c;
P_0c0a027c: /* original 000b, guest PC 0x0c0a027c */
if(!s->budget--) { s->failed_pc=0x0c0a027cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a027e: /* original 6ef6, guest PC 0x0c0a027e */
if(!s->budget--) { s->failed_pc=0x0c0a027eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a0280u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a0280u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
