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
int vf3_advance_controller_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06c360u: goto P_0c06c360;
case 0x0c06c362u: goto P_0c06c362;
case 0x0c06c364u: goto P_0c06c364;
case 0x0c06c366u: goto P_0c06c366;
case 0x0c06c368u: goto P_0c06c368;
case 0x0c06c36au: goto P_0c06c36a;
case 0x0c06c36cu: goto P_0c06c36c;
case 0x0c06c36eu: goto P_0c06c36e;
case 0x0c06c370u: goto P_0c06c370;
case 0x0c06c372u: goto P_0c06c372;
case 0x0c06c374u: goto P_0c06c374;
case 0x0c06c376u: goto P_0c06c376;
case 0x0c06c378u: goto P_0c06c378;
case 0x0c06c37au: goto P_0c06c37a;
case 0x0c06c37cu: goto P_0c06c37c;
case 0x0c06c37eu: goto P_0c06c37e;
case 0x0c06c380u: goto P_0c06c380;
case 0x0c06c382u: goto P_0c06c382;
case 0x0c06c384u: goto P_0c06c384;
case 0x0c06c386u: goto P_0c06c386;
case 0x0c06c388u: goto P_0c06c388;
case 0x0c06c38au: goto P_0c06c38a;
case 0x0c06c38cu: goto P_0c06c38c;
case 0x0c06c38eu: goto P_0c06c38e;
case 0x0c06c390u: goto P_0c06c390;
case 0x0c06c392u: goto P_0c06c392;
case 0x0c06c394u: goto P_0c06c394;
case 0x0c06c396u: goto P_0c06c396;
case 0x0c06c51eu: goto P_0c06c51e;
case 0x0c06c520u: goto P_0c06c520;
case 0x0c06c522u: goto P_0c06c522;
case 0x0c06c524u: goto P_0c06c524;
case 0x0c06c526u: goto P_0c06c526;
case 0x0c06c528u: goto P_0c06c528;
case 0x0c06c52au: goto P_0c06c52a;
case 0x0c06c52cu: goto P_0c06c52c;
case 0x0c06c52eu: goto P_0c06c52e;
case 0x0c06c530u: goto P_0c06c530;
case 0x0c06c532u: goto P_0c06c532;
case 0x0c06c534u: goto P_0c06c534;
case 0x0c06c536u: goto P_0c06c536;
case 0x0c06c538u: goto P_0c06c538;
case 0x0c06c53au: goto P_0c06c53a;
case 0x0c06c53cu: goto P_0c06c53c;
case 0x0c06c53eu: goto P_0c06c53e;
case 0x0c06c540u: goto P_0c06c540;
case 0x0c06c542u: goto P_0c06c542;
case 0x0c06c544u: goto P_0c06c544;
case 0x0c06c546u: goto P_0c06c546;
case 0x0c06c548u: goto P_0c06c548;
case 0x0c06c54au: goto P_0c06c54a;
case 0x0c06c54cu: goto P_0c06c54c;
case 0x0c06c54eu: goto P_0c06c54e;
case 0x0c06c550u: goto P_0c06c550;
case 0x0c06c552u: goto P_0c06c552;
case 0x0c06c554u: goto P_0c06c554;
case 0x0c06c556u: goto P_0c06c556;
case 0x0c06c558u: goto P_0c06c558;
case 0x0c06c55au: goto P_0c06c55a;
case 0x0c06c55cu: goto P_0c06c55c;
case 0x0c06c55eu: goto P_0c06c55e;
case 0x0c06c560u: goto P_0c06c560;
case 0x0c06c562u: goto P_0c06c562;
case 0x0c06c564u: goto P_0c06c564;
case 0x0c06c566u: goto P_0c06c566;
case 0x0c06c568u: goto P_0c06c568;
case 0x0c06c56au: goto P_0c06c56a;
case 0x0c06c56cu: goto P_0c06c56c;
case 0x0c06c56eu: goto P_0c06c56e;
case 0x0c06c570u: goto P_0c06c570;
case 0x0c06c572u: goto P_0c06c572;
case 0x0c06c574u: goto P_0c06c574;
case 0x0c06c576u: goto P_0c06c576;
case 0x0c06c578u: goto P_0c06c578;
case 0x0c06c57au: goto P_0c06c57a;
case 0x0c06c57cu: goto P_0c06c57c;
case 0x0c06c57eu: goto P_0c06c57e;
case 0x0c06c580u: goto P_0c06c580;
case 0x0c06c582u: goto P_0c06c582;
case 0x0c06c584u: goto P_0c06c584;
case 0x0c06c586u: goto P_0c06c586;
case 0x0c06c588u: goto P_0c06c588;
case 0x0c06c58au: goto P_0c06c58a;
case 0x0c06c58cu: goto P_0c06c58c;
case 0x0c06c58eu: goto P_0c06c58e;
case 0x0c06c590u: goto P_0c06c590;
case 0x0c06c592u: goto P_0c06c592;
case 0x0c06c594u: goto P_0c06c594;
case 0x0c06c596u: goto P_0c06c596;
case 0x0c06c598u: goto P_0c06c598;
case 0x0c06ccc0u: goto P_0c06ccc0;
case 0x0c06ccc2u: goto P_0c06ccc2;
case 0x0c06ccc4u: goto P_0c06ccc4;
case 0x0c06ccc6u: goto P_0c06ccc6;
case 0x0c06ccc8u: goto P_0c06ccc8;
case 0x0c06cccau: goto P_0c06ccca;
case 0x0c06ccccu: goto P_0c06cccc;
case 0x0c06ccceu: goto P_0c06ccce;
case 0x0c06ccd0u: goto P_0c06ccd0;
case 0x0c06ccd2u: goto P_0c06ccd2;
case 0x0c06ccd4u: goto P_0c06ccd4;
case 0x0c06ccd6u: goto P_0c06ccd6;
case 0x0c06ccd8u: goto P_0c06ccd8;
case 0x0c06ccdau: goto P_0c06ccda;
case 0x0c06ccdcu: goto P_0c06ccdc;
case 0x0c06ccdeu: goto P_0c06ccde;
case 0x0c06cce0u: goto P_0c06cce0;
case 0x0c06cce2u: goto P_0c06cce2;
case 0x0c06cce4u: goto P_0c06cce4;
case 0x0c06cce6u: goto P_0c06cce6;
case 0x0c06cce8u: goto P_0c06cce8;
case 0x0c06cceau: goto P_0c06ccea;
case 0x0c06ccecu: goto P_0c06ccec;
case 0x0c06cceeu: goto P_0c06ccee;
case 0x0c06ccf0u: goto P_0c06ccf0;
case 0x0c06ccf2u: goto P_0c06ccf2;
case 0x0c06ccf4u: goto P_0c06ccf4;
case 0x0c06ccf6u: goto P_0c06ccf6;
case 0x0c06ccf8u: goto P_0c06ccf8;
case 0x0c06ccfau: goto P_0c06ccfa;
case 0x0c06ccfcu: goto P_0c06ccfc;
case 0x0c06ccfeu: goto P_0c06ccfe;
case 0x0c06cd00u: goto P_0c06cd00;
case 0x0c06cd02u: goto P_0c06cd02;
case 0x0c06cd04u: goto P_0c06cd04;
case 0x0c06cd06u: goto P_0c06cd06;
case 0x0c06cd08u: goto P_0c06cd08;
case 0x0c06cd0au: goto P_0c06cd0a;
case 0x0c06cd0cu: goto P_0c06cd0c;
case 0x0c06cd0eu: goto P_0c06cd0e;
case 0x0c06cd10u: goto P_0c06cd10;
case 0x0c06cd12u: goto P_0c06cd12;
case 0x0c06cd14u: goto P_0c06cd14;
case 0x0c06cd16u: goto P_0c06cd16;
case 0x0c06cd18u: goto P_0c06cd18;
case 0x0c06cd1au: goto P_0c06cd1a;
case 0x0c06cd1cu: goto P_0c06cd1c;
case 0x0c06cd1eu: goto P_0c06cd1e;
case 0x0c06cd20u: goto P_0c06cd20;
case 0x0c06cd22u: goto P_0c06cd22;
case 0x0c06cd24u: goto P_0c06cd24;
case 0x0c06cd26u: goto P_0c06cd26;
case 0x0c06cd28u: goto P_0c06cd28;
case 0x0c06cd2au: goto P_0c06cd2a;
case 0x0c06cd2cu: goto P_0c06cd2c;
case 0x0c06cd2eu: goto P_0c06cd2e;
case 0x0c06cd30u: goto P_0c06cd30;
case 0x0c06cd32u: goto P_0c06cd32;
case 0x0c06cd34u: goto P_0c06cd34;
case 0x0c06cd36u: goto P_0c06cd36;
case 0x0c06cd38u: goto P_0c06cd38;
case 0x0c06cd3au: goto P_0c06cd3a;
case 0x0c06cd3cu: goto P_0c06cd3c;
case 0x0c06cd3eu: goto P_0c06cd3e;
case 0x0c06cd40u: goto P_0c06cd40;
case 0x0c06cd42u: goto P_0c06cd42;
case 0x0c06cd44u: goto P_0c06cd44;
case 0x0c06cd46u: goto P_0c06cd46;
case 0x0c06cd48u: goto P_0c06cd48;
case 0x0c06cd4au: goto P_0c06cd4a;
case 0x0c06cd4cu: goto P_0c06cd4c;
case 0x0c06cd4eu: goto P_0c06cd4e;
case 0x0c06cd74u: goto P_0c06cd74;
case 0x0c06cd76u: goto P_0c06cd76;
case 0x0c06cd78u: goto P_0c06cd78;
case 0x0c06cd7au: goto P_0c06cd7a;
case 0x0c06cd7cu: goto P_0c06cd7c;
case 0x0c06cd7eu: goto P_0c06cd7e;
case 0x0c06cd80u: goto P_0c06cd80;
case 0x0c06cd82u: goto P_0c06cd82;
case 0x0c06cd84u: goto P_0c06cd84;
case 0x0c06cd86u: goto P_0c06cd86;
case 0x0c06cd88u: goto P_0c06cd88;
case 0x0c06cd8au: goto P_0c06cd8a;
case 0x0c06cd8cu: goto P_0c06cd8c;
case 0x0c06cd8eu: goto P_0c06cd8e;
case 0x0c06cd90u: goto P_0c06cd90;
case 0x0c06cd92u: goto P_0c06cd92;
case 0x0c06cd94u: goto P_0c06cd94;
case 0x0c06cd96u: goto P_0c06cd96;
case 0x0c06cd98u: goto P_0c06cd98;
case 0x0c06cd9au: goto P_0c06cd9a;
case 0x0c06cd9cu: goto P_0c06cd9c;
case 0x0c06cd9eu: goto P_0c06cd9e;
case 0x0c06cda0u: goto P_0c06cda0;
case 0x0c06cda2u: goto P_0c06cda2;
case 0x0c06cda4u: goto P_0c06cda4;
case 0x0c06cda6u: goto P_0c06cda6;
case 0x0c06cda8u: goto P_0c06cda8;
case 0x0c06cdaau: goto P_0c06cdaa;
case 0x0c06cdacu: goto P_0c06cdac;
case 0x0c06cdaeu: goto P_0c06cdae;
case 0x0c06cdb0u: goto P_0c06cdb0;
case 0x0c06cdb2u: goto P_0c06cdb2;
case 0x0c06cdb4u: goto P_0c06cdb4;
case 0x0c06cdb6u: goto P_0c06cdb6;
case 0x0c06cdb8u: goto P_0c06cdb8;
case 0x0c06cdbau: goto P_0c06cdba;
case 0x0c06cdbcu: goto P_0c06cdbc;
case 0x0c06cdbeu: goto P_0c06cdbe;
case 0x0c06cdc0u: goto P_0c06cdc0;
case 0x0c06cdc2u: goto P_0c06cdc2;
case 0x0c06cdc4u: goto P_0c06cdc4;
case 0x0c06cdc6u: goto P_0c06cdc6;
case 0x0c06cdc8u: goto P_0c06cdc8;
case 0x0c06cdcau: goto P_0c06cdca;
case 0x0c06cdccu: goto P_0c06cdcc;
case 0x0c06cdceu: goto P_0c06cdce;
case 0x0c06cdd0u: goto P_0c06cdd0;
case 0x0c06cdd2u: goto P_0c06cdd2;
case 0x0c06cdd4u: goto P_0c06cdd4;
case 0x0c06cdd6u: goto P_0c06cdd6;
case 0x0c06cdd8u: goto P_0c06cdd8;
case 0x0c06cddau: goto P_0c06cdda;
case 0x0c06cddcu: goto P_0c06cddc;
case 0x0c06cddeu: goto P_0c06cdde;
case 0x0c06cde0u: goto P_0c06cde0;
case 0x0c06cde2u: goto P_0c06cde2;
case 0x0c06cde4u: goto P_0c06cde4;
case 0x0c06cde6u: goto P_0c06cde6;
case 0x0c06cde8u: goto P_0c06cde8;
case 0x0c06cdeau: goto P_0c06cdea;
case 0x0c06cdecu: goto P_0c06cdec;
case 0x0c06cdeeu: goto P_0c06cdee;
case 0x0c06cdf0u: goto P_0c06cdf0;
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
case 0x0c0a0718u: goto P_0c0a0718;
case 0x0c0a071au: goto P_0c0a071a;
case 0x0c0a071cu: goto P_0c0a071c;
case 0x0c0a071eu: goto P_0c0a071e;
case 0x0c0a0720u: goto P_0c0a0720;
case 0x0c0a0722u: goto P_0c0a0722;
case 0x0c0a0724u: goto P_0c0a0724;
case 0x0c0a0726u: goto P_0c0a0726;
case 0x0c0a0728u: goto P_0c0a0728;
case 0x0c0a072au: goto P_0c0a072a;
case 0x0c0a072cu: goto P_0c0a072c;
case 0x0c0a072eu: goto P_0c0a072e;
case 0x0c0a0730u: goto P_0c0a0730;
case 0x0c0a0732u: goto P_0c0a0732;
case 0x0c0a0734u: goto P_0c0a0734;
case 0x0c0a0736u: goto P_0c0a0736;
case 0x0c0a0738u: goto P_0c0a0738;
case 0x0c0a073au: goto P_0c0a073a;
case 0x0c0a073cu: goto P_0c0a073c;
case 0x0c0a073eu: goto P_0c0a073e;
case 0x0c0a0740u: goto P_0c0a0740;
case 0x0c0a0742u: goto P_0c0a0742;
case 0x0c0a0744u: goto P_0c0a0744;
case 0x0c0a0746u: goto P_0c0a0746;
case 0x0c0a0748u: goto P_0c0a0748;
case 0x0c0a074au: goto P_0c0a074a;
case 0x0c0a074cu: goto P_0c0a074c;
case 0x0c0a074eu: goto P_0c0a074e;
case 0x0c0a0750u: goto P_0c0a0750;
case 0x0c0a0752u: goto P_0c0a0752;
case 0x0c0a0754u: goto P_0c0a0754;
case 0x0c0a0756u: goto P_0c0a0756;
case 0x0c0a0758u: goto P_0c0a0758;
case 0x0c0a075au: goto P_0c0a075a;
case 0x0c0a075cu: goto P_0c0a075c;
case 0x0c0a075eu: goto P_0c0a075e;
case 0x0c0a0760u: goto P_0c0a0760;
case 0x0c0a0762u: goto P_0c0a0762;
case 0x0c0a0764u: goto P_0c0a0764;
case 0x0c0a0766u: goto P_0c0a0766;
case 0x0c0a0768u: goto P_0c0a0768;
case 0x0c0a076au: goto P_0c0a076a;
case 0x0c0a076cu: goto P_0c0a076c;
case 0x0c0a076eu: goto P_0c0a076e;
case 0x0c0a0770u: goto P_0c0a0770;
case 0x0c0a0772u: goto P_0c0a0772;
case 0x0c0a0774u: goto P_0c0a0774;
case 0x0c0a0776u: goto P_0c0a0776;
case 0x0c0a0778u: goto P_0c0a0778;
case 0x0c0a077au: goto P_0c0a077a;
case 0x0c0a077cu: goto P_0c0a077c;
case 0x0c0a077eu: goto P_0c0a077e;
case 0x0c0a0780u: goto P_0c0a0780;
case 0x0c0a0782u: goto P_0c0a0782;
case 0x0c0a0784u: goto P_0c0a0784;
case 0x0c0a0786u: goto P_0c0a0786;
case 0x0c0a0788u: goto P_0c0a0788;
case 0x0c0a078au: goto P_0c0a078a;
case 0x0c0a078cu: goto P_0c0a078c;
case 0x0c0a078eu: goto P_0c0a078e;
case 0x0c0a0790u: goto P_0c0a0790;
case 0x0c0a0792u: goto P_0c0a0792;
case 0x0c0a0794u: goto P_0c0a0794;
case 0x0c0a0796u: goto P_0c0a0796;
case 0x0c0a0798u: goto P_0c0a0798;
case 0x0c0a079au: goto P_0c0a079a;
case 0x0c0a079cu: goto P_0c0a079c;
case 0x0c0a079eu: goto P_0c0a079e;
case 0x0c0a07a0u: goto P_0c0a07a0;
case 0x0c0a07a2u: goto P_0c0a07a2;
case 0x0c0a07a4u: goto P_0c0a07a4;
case 0x0c0a07a6u: goto P_0c0a07a6;
case 0x0c0a07a8u: goto P_0c0a07a8;
case 0x0c0a07aau: goto P_0c0a07aa;
case 0x0c0a07acu: goto P_0c0a07ac;
case 0x0c0a07aeu: goto P_0c0a07ae;
case 0x0c0a07b0u: goto P_0c0a07b0;
case 0x0c0a07b2u: goto P_0c0a07b2;
case 0x0c0a07b4u: goto P_0c0a07b4;
case 0x0c0a07b6u: goto P_0c0a07b6;
case 0x0c0a07b8u: goto P_0c0a07b8;
case 0x0c0a07bau: goto P_0c0a07ba;
case 0x0c0a07bcu: goto P_0c0a07bc;
case 0x0c0a07beu: goto P_0c0a07be;
case 0x0c0a07c0u: goto P_0c0a07c0;
case 0x0c0a07c2u: goto P_0c0a07c2;
case 0x0c0a07c4u: goto P_0c0a07c4;
case 0x0c0a07c6u: goto P_0c0a07c6;
case 0x0c0a07c8u: goto P_0c0a07c8;
case 0x0c0a07cau: goto P_0c0a07ca;
case 0x0c0a07ccu: goto P_0c0a07cc;
case 0x0c0a07ceu: goto P_0c0a07ce;
case 0x0c0a07d0u: goto P_0c0a07d0;
case 0x0c0a07d2u: goto P_0c0a07d2;
case 0x0c0a07d4u: goto P_0c0a07d4;
case 0x0c0a07d6u: goto P_0c0a07d6;
case 0x0c0a07d8u: goto P_0c0a07d8;
case 0x0c0a07dau: goto P_0c0a07da;
case 0x0c0a07dcu: goto P_0c0a07dc;
case 0x0c0a07deu: goto P_0c0a07de;
case 0x0c0a07e0u: goto P_0c0a07e0;
case 0x0c0a07e2u: goto P_0c0a07e2;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06c360: /* original 4f22, guest PC 0x0c06c360 */
if(!s->budget--) { s->failed_pc=0x0c06c360u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c362;
P_0c06c362: /* original e21f, guest PC 0x0c06c362 */
if(!s->budget--) { s->failed_pc=0x0c06c362u; return 0; }
r[2]=0x0000001fu;
goto P_0c06c364;
P_0c06c364: /* original e108, guest PC 0x0c06c364 */
if(!s->budget--) { s->failed_pc=0x0c06c364u; return 0; }
r[1]=0x00000008u;
goto P_0c06c366;
P_0c06c366: /* original 7ffc, guest PC 0x0c06c366 */
if(!s->budget--) { s->failed_pc=0x0c06c366u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c368;
P_0c06c368: /* original 2f42, guest PC 0x0c06c368 */
if(!s->budget--) { s->failed_pc=0x0c06c368u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06c36a;
P_0c06c36a: /* original d345, guest PC 0x0c06c36a */
if(!s->budget--) { s->failed_pc=0x0c06c36au; return 0; }
r[3]=read(ram,0x0c06c480u,4);
goto P_0c06c36c;
P_0c06c36c: /* original d443, guest PC 0x0c06c36c */
if(!s->budget--) { s->failed_pc=0x0c06c36cu; return 0; }
r[4]=read(ram,0x0c06c47cu,4);
goto P_0c06c36e;
P_0c06c36e: /* original 6532, guest PC 0x0c06c36e */
if(!s->budget--) { s->failed_pc=0x0c06c36eu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06c370;
P_0c06c370: /* original 2529, guest PC 0x0c06c370 */
if(!s->budget--) { s->failed_pc=0x0c06c370u; return 0; }
r[5]&=r[2];
goto P_0c06c372;
P_0c06c372: /* original 3513, guest PC 0x0c06c372 */
if(!s->budget--) { s->failed_pc=0x0c06c372u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[1])!=0);
goto P_0c06c374;
P_0c06c374: /* original 8b03, guest PC 0x0c06c374 */
if(!s->budget--) { s->failed_pc=0x0c06c374u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c37e; }
goto P_0c06c376;
P_0c06c376: /* original 7f04, guest PC 0x0c06c376 */
if(!s->budget--) { s->failed_pc=0x0c06c376u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c378;
P_0c06c378: /* original 4f26, guest PC 0x0c06c378 */
if(!s->budget--) { s->failed_pc=0x0c06c378u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c37a;
P_0c06c37a: /* original 000b, guest PC 0x0c06c37a */
if(!s->budget--) { s->failed_pc=0x0c06c37au; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c06c37c: /* original 6053, guest PC 0x0c06c37c */
if(!s->budget--) { s->failed_pc=0x0c06c37cu; return 0; }
r[0]=r[5];
goto P_0c06c37e;
P_0c06c37e: /* original e220, guest PC 0x0c06c37e */
if(!s->budget--) { s->failed_pc=0x0c06c37eu; return 0; }
r[2]=0x00000020u;
goto P_0c06c380;
P_0c06c380: /* original e615, guest PC 0x0c06c380 */
if(!s->budget--) { s->failed_pc=0x0c06c380u; return 0; }
r[6]=0x00000015u;
goto P_0c06c382;
P_0c06c382: /* original 2f26, guest PC 0x0c06c382 */
if(!s->budget--) { s->failed_pc=0x0c06c382u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c384;
P_0c06c384: /* original d33f, guest PC 0x0c06c384 */
if(!s->budget--) { s->failed_pc=0x0c06c384u; return 0; }
r[3]=read(ram,0x0c06c484u,4);
goto P_0c06c386;
P_0c06c386: /* original e701, guest PC 0x0c06c386 */
if(!s->budget--) { s->failed_pc=0x0c06c386u; return 0; }
r[7]=0x00000001u;
goto P_0c06c388;
P_0c06c388: /* original 430b, guest PC 0x0c06c388 */
if(!s->budget--) { s->failed_pc=0x0c06c388u; return 0; }
target=r[3];
r[16]=0x0c06c38cu;
r[5]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06c38cu) { target=s->pc; goto dispatch; }
goto P_0c06c38c;
P_0c06c38a: /* original 55f1, guest PC 0x0c06c38a */
if(!s->budget--) { s->failed_pc=0x0c06c38au; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c06c38c;
P_0c06c38c: /* original e000, guest PC 0x0c06c38c */
if(!s->budget--) { s->failed_pc=0x0c06c38cu; return 0; }
r[0]=0x00000000u;
goto P_0c06c38e;
P_0c06c38e: /* original 7f04, guest PC 0x0c06c38e */
if(!s->budget--) { s->failed_pc=0x0c06c38eu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c390;
P_0c06c390: /* original 7f04, guest PC 0x0c06c390 */
if(!s->budget--) { s->failed_pc=0x0c06c390u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c392;
P_0c06c392: /* original 4f26, guest PC 0x0c06c392 */
if(!s->budget--) { s->failed_pc=0x0c06c392u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c394;
P_0c06c394: /* original 000b, guest PC 0x0c06c394 */
if(!s->budget--) { s->failed_pc=0x0c06c394u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06c396: /* original 0009, guest PC 0x0c06c396 */
if(!s->budget--) { s->failed_pc=0x0c06c396u; return 0; }
return vf3_matrix_family(0x0c06c398u,s,ram);
P_0c06c51e: /* original 2fe6, guest PC 0x0c06c51e */
if(!s->budget--) { s->failed_pc=0x0c06c51eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c520;
P_0c06c520: /* original 2fd6, guest PC 0x0c06c520 */
if(!s->budget--) { s->failed_pc=0x0c06c520u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c522;
P_0c06c522: /* original 2fc6, guest PC 0x0c06c522 */
if(!s->budget--) { s->failed_pc=0x0c06c522u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c524;
P_0c06c524: /* original 2fb6, guest PC 0x0c06c524 */
if(!s->budget--) { s->failed_pc=0x0c06c524u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c526;
P_0c06c526: /* original 903c, guest PC 0x0c06c526 */
if(!s->budget--) { s->failed_pc=0x0c06c526u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c5a2u,2);
goto P_0c06c528;
P_0c06c528: /* original d423, guest PC 0x0c06c528 */
if(!s->budget--) { s->failed_pc=0x0c06c528u; return 0; }
r[4]=read(ram,0x0c06c5b8u,4);
goto P_0c06c52a;
P_0c06c52a: /* original 4f22, guest PC 0x0c06c52a */
if(!s->budget--) { s->failed_pc=0x0c06c52au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c52c;
P_0c06c52c: /* original 034c, guest PC 0x0c06c52c */
if(!s->budget--) { s->failed_pc=0x0c06c52cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c52e;
P_0c06c52e: /* original 7ffc, guest PC 0x0c06c52e */
if(!s->budget--) { s->failed_pc=0x0c06c52eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c530;
P_0c06c530: /* original 2f32, guest PC 0x0c06c530 */
if(!s->budget--) { s->failed_pc=0x0c06c530u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c532;
P_0c06c532: /* original 9037, guest PC 0x0c06c532 */
if(!s->budget--) { s->failed_pc=0x0c06c532u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c5a4u,2);
goto P_0c06c534;
P_0c06c534: /* original 0b4c, guest PC 0x0c06c534 */
if(!s->budget--) { s->failed_pc=0x0c06c534u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c536;
P_0c06c536: /* original 9036, guest PC 0x0c06c536 */
if(!s->budget--) { s->failed_pc=0x0c06c536u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c5a6u,2);
goto P_0c06c538;
P_0c06c538: /* original 064c, guest PC 0x0c06c538 */
if(!s->budget--) { s->failed_pc=0x0c06c538u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c53a;
P_0c06c53a: /* original 7001, guest PC 0x0c06c53a */
if(!s->budget--) { s->failed_pc=0x0c06c53au; return 0; }
r[0]+=0x00000001u;
goto P_0c06c53c;
P_0c06c53c: /* original 074c, guest PC 0x0c06c53c */
if(!s->budget--) { s->failed_pc=0x0c06c53cu; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c53e;
P_0c06c53e: /* original 700d, guest PC 0x0c06c53e */
if(!s->budget--) { s->failed_pc=0x0c06c53eu; return 0; }
r[0]+=0x0000000du;
goto P_0c06c540;
P_0c06c540: /* original 054c, guest PC 0x0c06c540 */
if(!s->budget--) { s->failed_pc=0x0c06c540u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c542;
P_0c06c542: /* original 6033, guest PC 0x0c06c542 */
if(!s->budget--) { s->failed_pc=0x0c06c542u; return 0; }
r[0]=r[3];
goto P_0c06c544;
P_0c06c544: /* original 8801, guest PC 0x0c06c544 */
if(!s->budget--) { s->failed_pc=0x0c06c544u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c546;
P_0c06c546: /* original 8907, guest PC 0x0c06c546 */
if(!s->budget--) { s->failed_pc=0x0c06c546u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c558; }
goto P_0c06c548;
P_0c06c548: /* original 60b3, guest PC 0x0c06c548 */
if(!s->budget--) { s->failed_pc=0x0c06c548u; return 0; }
r[0]=r[11];
goto P_0c06c54a;
P_0c06c54a: /* original 8801, guest PC 0x0c06c54a */
if(!s->budget--) { s->failed_pc=0x0c06c54au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c54c;
P_0c06c54c: /* original 8f01, guest PC 0x0c06c54c */
if(!s->budget--) { s->failed_pc=0x0c06c54cu; return 0; }
cond=r[17]&1u;
r[14]=0x00000005u;
if(!cond) { goto P_0c06c552; }
goto P_0c06c550;
P_0c06c54e: /* original ee05, guest PC 0x0c06c54e */
if(!s->budget--) { s->failed_pc=0x0c06c54eu; return 0; }
r[14]=0x00000005u;
goto P_0c06c550;
P_0c06c550: /* original ee27, guest PC 0x0c06c550 */
if(!s->budget--) { s->failed_pc=0x0c06c550u; return 0; }
r[14]=0x00000027u;
goto P_0c06c552;
P_0c06c552: /* original 6d63, guest PC 0x0c06c552 */
if(!s->budget--) { s->failed_pc=0x0c06c552u; return 0; }
r[13]=r[6];
goto P_0c06c554;
P_0c06c554: /* original a00b, guest PC 0x0c06c554 */
if(!s->budget--) { s->failed_pc=0x0c06c554u; return 0; }
r[12]=r[7];
goto P_0c06c56e;
P_0c06c556: /* original 6c73, guest PC 0x0c06c556 */
if(!s->budget--) { s->failed_pc=0x0c06c556u; return 0; }
r[12]=r[7];
goto P_0c06c558;
P_0c06c558: /* original 60b3, guest PC 0x0c06c558 */
if(!s->budget--) { s->failed_pc=0x0c06c558u; return 0; }
r[0]=r[11];
goto P_0c06c55a;
P_0c06c55a: /* original 8801, guest PC 0x0c06c55a */
if(!s->budget--) { s->failed_pc=0x0c06c55au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c55c;
P_0c06c55c: /* original ee05, guest PC 0x0c06c55c */
if(!s->budget--) { s->failed_pc=0x0c06c55cu; return 0; }
r[14]=0x00000005u;
goto P_0c06c55e;
P_0c06c55e: /* original 6d63, guest PC 0x0c06c55e */
if(!s->budget--) { s->failed_pc=0x0c06c55eu; return 0; }
r[13]=r[6];
goto P_0c06c560;
P_0c06c560: /* original 8f05, guest PC 0x0c06c560 */
if(!s->budget--) { s->failed_pc=0x0c06c560u; return 0; }
cond=r[17]&1u;
r[12]=r[7];
if(!cond) { goto P_0c06c56e; }
goto P_0c06c564;
P_0c06c562: /* original 6c73, guest PC 0x0c06c562 */
if(!s->budget--) { s->failed_pc=0x0c06c562u; return 0; }
r[12]=r[7];
goto P_0c06c564;
P_0c06c564: /* original 9020, guest PC 0x0c06c564 */
if(!s->budget--) { s->failed_pc=0x0c06c564u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c5a8u,2);
goto P_0c06c566;
P_0c06c566: /* original ee27, guest PC 0x0c06c566 */
if(!s->budget--) { s->failed_pc=0x0c06c566u; return 0; }
r[14]=0x00000027u;
goto P_0c06c568;
P_0c06c568: /* original 0d4c, guest PC 0x0c06c568 */
if(!s->budget--) { s->failed_pc=0x0c06c568u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c56a;
P_0c06c56a: /* original 7001, guest PC 0x0c06c56a */
if(!s->budget--) { s->failed_pc=0x0c06c56au; return 0; }
r[0]+=0x00000001u;
goto P_0c06c56c;
P_0c06c56c: /* original 0c4c, guest PC 0x0c06c56c */
if(!s->budget--) { s->failed_pc=0x0c06c56cu; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c56e;
P_0c06c56e: /* original 9316, guest PC 0x0c06c56e */
if(!s->budget--) { s->failed_pc=0x0c06c56eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c59eu,2);
goto P_0c06c570;
P_0c06c570: /* original 64e3, guest PC 0x0c06c570 */
if(!s->budget--) { s->failed_pc=0x0c06c570u; return 0; }
r[4]=r[14];
goto P_0c06c572;
P_0c06c572: /* original 6b53, guest PC 0x0c06c572 */
if(!s->budget--) { s->failed_pc=0x0c06c572u; return 0; }
r[11]=r[5];
goto P_0c06c574;
P_0c06c574: /* original 4400, guest PC 0x0c06c574 */
if(!s->budget--) { s->failed_pc=0x0c06c574u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c576;
P_0c06c576: /* original bef3, guest PC 0x0c06c576 */
if(!s->budget--) { s->failed_pc=0x0c06c576u; return 0; }
target=0x0c06c360u; r[16]=0x0c06c57au;
r[4]|=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06c57au) { target=s->pc; goto dispatch; }
goto P_0c06c57a;
P_0c06c578: /* original 243b, guest PC 0x0c06c578 */
if(!s->budget--) { s->failed_pc=0x0c06c578u; return 0; }
r[4]|=r[3];
goto P_0c06c57a;
P_0c06c57a: /* original 2008, guest PC 0x0c06c57a */
if(!s->budget--) { s->failed_pc=0x0c06c57au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06c57c;
P_0c06c57c: /* original 8906, guest PC 0x0c06c57c */
if(!s->budget--) { s->failed_pc=0x0c06c57cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c58c; }
goto P_0c06c57e;
P_0c06c57e: /* original 66d3, guest PC 0x0c06c57e */
if(!s->budget--) { s->failed_pc=0x0c06c57eu; return 0; }
r[6]=r[13];
goto P_0c06c580;
P_0c06c580: /* original e52e, guest PC 0x0c06c580 */
if(!s->budget--) { s->failed_pc=0x0c06c580u; return 0; }
r[5]=0x0000002eu;
goto P_0c06c582;
P_0c06c582: /* original 2fb6, guest PC 0x0c06c582 */
if(!s->budget--) { s->failed_pc=0x0c06c582u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c584;
P_0c06c584: /* original 67c3, guest PC 0x0c06c584 */
if(!s->budget--) { s->failed_pc=0x0c06c584u; return 0; }
r[7]=r[12];
goto P_0c06c586;
P_0c06c586: /* original b2ae, guest PC 0x0c06c586 */
if(!s->budget--) { s->failed_pc=0x0c06c586u; return 0; }
target=0x0c06cae6u; r[16]=0x0c06c58au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06c58au) { target=s->pc; goto dispatch; }
goto P_0c06c58a;
P_0c06c588: /* original 64e3, guest PC 0x0c06c588 */
if(!s->budget--) { s->failed_pc=0x0c06c588u; return 0; }
r[4]=r[14];
goto P_0c06c58a;
P_0c06c58a: /* original 7f04, guest PC 0x0c06c58a */
if(!s->budget--) { s->failed_pc=0x0c06c58au; return 0; }
r[15]+=0x00000004u;
goto P_0c06c58c;
P_0c06c58c: /* original 7f04, guest PC 0x0c06c58c */
if(!s->budget--) { s->failed_pc=0x0c06c58cu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c58e;
P_0c06c58e: /* original 4f26, guest PC 0x0c06c58e */
if(!s->budget--) { s->failed_pc=0x0c06c58eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c590;
P_0c06c590: /* original 6bf6, guest PC 0x0c06c590 */
if(!s->budget--) { s->failed_pc=0x0c06c590u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06c592;
P_0c06c592: /* original 6cf6, guest PC 0x0c06c592 */
if(!s->budget--) { s->failed_pc=0x0c06c592u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06c594;
P_0c06c594: /* original 6df6, guest PC 0x0c06c594 */
if(!s->budget--) { s->failed_pc=0x0c06c594u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06c596;
P_0c06c596: /* original 000b, guest PC 0x0c06c596 */
if(!s->budget--) { s->failed_pc=0x0c06c596u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c598: /* original 6ef6, guest PC 0x0c06c598 */
if(!s->budget--) { s->failed_pc=0x0c06c598u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06c59au,s,ram);
P_0c06ccc0: /* original 2fe6, guest PC 0x0c06ccc0 */
if(!s->budget--) { s->failed_pc=0x0c06ccc0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ccc2;
P_0c06ccc2: /* original 2fd6, guest PC 0x0c06ccc2 */
if(!s->budget--) { s->failed_pc=0x0c06ccc2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ccc4;
P_0c06ccc4: /* original 2fc6, guest PC 0x0c06ccc4 */
if(!s->budget--) { s->failed_pc=0x0c06ccc4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ccc6;
P_0c06ccc6: /* original de27, guest PC 0x0c06ccc6 */
if(!s->budget--) { s->failed_pc=0x0c06ccc6u; return 0; }
r[14]=read(ram,0x0c06cd64u,4);
goto P_0c06ccc8;
P_0c06ccc8: /* original 4f22, guest PC 0x0c06ccc8 */
if(!s->budget--) { s->failed_pc=0x0c06ccc8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06ccca;
P_0c06ccca: /* original d329, guest PC 0x0c06ccca */
if(!s->budget--) { s->failed_pc=0x0c06cccau; return 0; }
r[3]=read(ram,0x0c06cd70u,4);
goto P_0c06cccc;
P_0c06cccc: /* original 7ff8, guest PC 0x0c06cccc */
if(!s->budget--) { s->failed_pc=0x0c06ccccu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06ccce;
P_0c06ccce: /* original 1f31, guest PC 0x0c06ccce */
if(!s->budget--) { s->failed_pc=0x0c06ccceu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c06ccd0;
P_0c06ccd0: /* original 9040, guest PC 0x0c06ccd0 */
if(!s->budget--) { s->failed_pc=0x0c06ccd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cd54u,2);
goto P_0c06ccd2;
P_0c06ccd2: /* original 02ec, guest PC 0x0c06ccd2 */
if(!s->budget--) { s->failed_pc=0x0c06ccd2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06ccd4;
P_0c06ccd4: /* original 6023, guest PC 0x0c06ccd4 */
if(!s->budget--) { s->failed_pc=0x0c06ccd4u; return 0; }
r[0]=r[2];
goto P_0c06ccd6;
P_0c06ccd6: /* original 8801, guest PC 0x0c06ccd6 */
if(!s->budget--) { s->failed_pc=0x0c06ccd6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06ccd8;
P_0c06ccd8: /* original 2f22, guest PC 0x0c06ccd8 */
if(!s->budget--) { s->failed_pc=0x0c06ccd8u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c06ccda;
P_0c06ccda: /* original 8b01, guest PC 0x0c06ccda */
if(!s->budget--) { s->failed_pc=0x0c06ccdau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06cce0; }
goto P_0c06ccdc;
P_0c06ccdc: /* original a04b, guest PC 0x0c06ccdc */
if(!s->budget--) { s->failed_pc=0x0c06ccdcu; return 0; }
r[2]=0x00000003u;
goto P_0c06cd76;
P_0c06ccde: /* original e203, guest PC 0x0c06ccde */
if(!s->budget--) { s->failed_pc=0x0c06ccdeu; return 0; }
r[2]=0x00000003u;
goto P_0c06cce0;
P_0c06cce0: /* original 9039, guest PC 0x0c06cce0 */
if(!s->budget--) { s->failed_pc=0x0c06cce0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cd56u,2);
goto P_0c06cce2;
P_0c06cce2: /* original 01ec, guest PC 0x0c06cce2 */
if(!s->budget--) { s->failed_pc=0x0c06cce2u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06cce4;
P_0c06cce4: /* original 6013, guest PC 0x0c06cce4 */
if(!s->budget--) { s->failed_pc=0x0c06cce4u; return 0; }
r[0]=r[1];
goto P_0c06cce6;
P_0c06cce6: /* original 8801, guest PC 0x0c06cce6 */
if(!s->budget--) { s->failed_pc=0x0c06cce6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cce8;
P_0c06cce8: /* original 2f12, guest PC 0x0c06cce8 */
if(!s->budget--) { s->failed_pc=0x0c06cce8u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c06ccea;
P_0c06ccea: /* original 8b0d, guest PC 0x0c06ccea */
if(!s->budget--) { s->failed_pc=0x0c06cceau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06cd08; }
goto P_0c06ccec;
P_0c06ccec: /* original 2778, guest PC 0x0c06ccec */
if(!s->budget--) { s->failed_pc=0x0c06ccecu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c06ccee;
P_0c06ccee: /* original 8b06, guest PC 0x0c06ccee */
if(!s->budget--) { s->failed_pc=0x0c06cceeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ccfe; }
goto P_0c06ccf0;
P_0c06ccf0: /* original 9032, guest PC 0x0c06ccf0 */
if(!s->budget--) { s->failed_pc=0x0c06ccf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cd58u,2);
goto P_0c06ccf2;
P_0c06ccf2: /* original 00ec, guest PC 0x0c06ccf2 */
if(!s->budget--) { s->failed_pc=0x0c06ccf2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06ccf4;
P_0c06ccf4: /* original 8801, guest PC 0x0c06ccf4 */
if(!s->budget--) { s->failed_pc=0x0c06ccf4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06ccf6;
P_0c06ccf6: /* original 8f12, guest PC 0x0c06ccf6 */
if(!s->budget--) { s->failed_pc=0x0c06ccf6u; return 0; }
cond=r[17]&1u;
r[7]=r[0];
if(!cond) { goto P_0c06cd1e; }
goto P_0c06ccfa;
P_0c06ccf8: /* original 6703, guest PC 0x0c06ccf8 */
if(!s->budget--) { s->failed_pc=0x0c06ccf8u; return 0; }
r[7]=r[0];
goto P_0c06ccfa;
P_0c06ccfa: /* original a005, guest PC 0x0c06ccfa */
if(!s->budget--) { s->failed_pc=0x0c06ccfau; return 0; }
goto P_0c06cd08;
P_0c06ccfc: /* original 0009, guest PC 0x0c06ccfc */
if(!s->budget--) { s->failed_pc=0x0c06ccfcu; return 0; }
goto P_0c06ccfe;
P_0c06ccfe: /* original 902b, guest PC 0x0c06ccfe */
if(!s->budget--) { s->failed_pc=0x0c06ccfeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cd58u,2);
goto P_0c06cd00;
P_0c06cd00: /* original 00ec, guest PC 0x0c06cd00 */
if(!s->budget--) { s->failed_pc=0x0c06cd00u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06cd02;
P_0c06cd02: /* original 8801, guest PC 0x0c06cd02 */
if(!s->budget--) { s->failed_pc=0x0c06cd02u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cd04;
P_0c06cd04: /* original 8d0b, guest PC 0x0c06cd04 */
if(!s->budget--) { s->failed_pc=0x0c06cd04u; return 0; }
cond=r[17]&1u;
r[7]=r[0];
if(cond) { goto P_0c06cd1e; }
goto P_0c06cd08;
P_0c06cd06: /* original 6703, guest PC 0x0c06cd06 */
if(!s->budget--) { s->failed_pc=0x0c06cd06u; return 0; }
r[7]=r[0];
goto P_0c06cd08;
P_0c06cd08: /* original 9027, guest PC 0x0c06cd08 */
if(!s->budget--) { s->failed_pc=0x0c06cd08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cd5au,2);
goto P_0c06cd0a;
P_0c06cd0a: /* original 07ec, guest PC 0x0c06cd0a */
if(!s->budget--) { s->failed_pc=0x0c06cd0au; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06cd0c;
P_0c06cd0c: /* original 70ff, guest PC 0x0c06cd0c */
if(!s->budget--) { s->failed_pc=0x0c06cd0cu; return 0; }
r[0]+=0xffffffffu;
goto P_0c06cd0e;
P_0c06cd0e: /* original 03ec, guest PC 0x0c06cd0e */
if(!s->budget--) { s->failed_pc=0x0c06cd0eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06cd10;
P_0c06cd10: /* original 2338, guest PC 0x0c06cd10 */
if(!s->budget--) { s->failed_pc=0x0c06cd10u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06cd12;
P_0c06cd12: /* original 8f12, guest PC 0x0c06cd12 */
if(!s->budget--) { s->failed_pc=0x0c06cd12u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c06cd3a; }
goto P_0c06cd16;
P_0c06cd14: /* original 2f32, guest PC 0x0c06cd14 */
if(!s->budget--) { s->failed_pc=0x0c06cd14u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06cd16;
P_0c06cd16: /* original 2778, guest PC 0x0c06cd16 */
if(!s->budget--) { s->failed_pc=0x0c06cd16u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c06cd18;
P_0c06cd18: /* original 8b0f, guest PC 0x0c06cd18 */
if(!s->budget--) { s->failed_pc=0x0c06cd18u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06cd3a; }
goto P_0c06cd1a;
P_0c06cd1a: /* original a02b, guest PC 0x0c06cd1a */
if(!s->budget--) { s->failed_pc=0x0c06cd1au; return 0; }
goto P_0c06cd74;
P_0c06cd1c: /* original 0009, guest PC 0x0c06cd1c */
if(!s->budget--) { s->failed_pc=0x0c06cd1cu; return 0; }
goto P_0c06cd1e;
P_0c06cd1e: /* original 901d, guest PC 0x0c06cd1e */
if(!s->budget--) { s->failed_pc=0x0c06cd1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cd5cu,2);
goto P_0c06cd20;
P_0c06cd20: /* original 07ec, guest PC 0x0c06cd20 */
if(!s->budget--) { s->failed_pc=0x0c06cd20u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06cd22;
P_0c06cd22: /* original 70ff, guest PC 0x0c06cd22 */
if(!s->budget--) { s->failed_pc=0x0c06cd22u; return 0; }
r[0]+=0xffffffffu;
goto P_0c06cd24;
P_0c06cd24: /* original 03ec, guest PC 0x0c06cd24 */
if(!s->budget--) { s->failed_pc=0x0c06cd24u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06cd26;
P_0c06cd26: /* original 2338, guest PC 0x0c06cd26 */
if(!s->budget--) { s->failed_pc=0x0c06cd26u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06cd28;
P_0c06cd28: /* original 8f02, guest PC 0x0c06cd28 */
if(!s->budget--) { s->failed_pc=0x0c06cd28u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c06cd30; }
goto P_0c06cd2c;
P_0c06cd2a: /* original 2f32, guest PC 0x0c06cd2a */
if(!s->budget--) { s->failed_pc=0x0c06cd2au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06cd2c;
P_0c06cd2c: /* original 2778, guest PC 0x0c06cd2c */
if(!s->budget--) { s->failed_pc=0x0c06cd2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c06cd2e;
P_0c06cd2e: /* original 8921, guest PC 0x0c06cd2e */
if(!s->budget--) { s->failed_pc=0x0c06cd2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cd74; }
goto P_0c06cd30;
P_0c06cd30: /* original 61f2, guest PC 0x0c06cd30 */
if(!s->budget--) { s->failed_pc=0x0c06cd30u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c06cd32;
P_0c06cd32: /* original 3142, guest PC 0x0c06cd32 */
if(!s->budget--) { s->failed_pc=0x0c06cd32u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[4])!=0);
goto P_0c06cd34;
P_0c06cd34: /* original 8b08, guest PC 0x0c06cd34 */
if(!s->budget--) { s->failed_pc=0x0c06cd34u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06cd48; }
goto P_0c06cd36;
P_0c06cd36: /* original a003, guest PC 0x0c06cd36 */
if(!s->budget--) { s->failed_pc=0x0c06cd36u; return 0; }
goto P_0c06cd40;
P_0c06cd38: /* original 0009, guest PC 0x0c06cd38 */
if(!s->budget--) { s->failed_pc=0x0c06cd38u; return 0; }
goto P_0c06cd3a;
P_0c06cd3a: /* original 63f2, guest PC 0x0c06cd3a */
if(!s->budget--) { s->failed_pc=0x0c06cd3au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06cd3c;
P_0c06cd3c: /* original 3342, guest PC 0x0c06cd3c */
if(!s->budget--) { s->failed_pc=0x0c06cd3cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[4])!=0);
goto P_0c06cd3e;
P_0c06cd3e: /* original 8b03, guest PC 0x0c06cd3e */
if(!s->budget--) { s->failed_pc=0x0c06cd3eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06cd48; }
goto P_0c06cd40;
P_0c06cd40: /* original 900d, guest PC 0x0c06cd40 */
if(!s->budget--) { s->failed_pc=0x0c06cd40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cd5eu,2);
goto P_0c06cd42;
P_0c06cd42: /* original e202, guest PC 0x0c06cd42 */
if(!s->budget--) { s->failed_pc=0x0c06cd42u; return 0; }
r[2]=0x00000002u;
goto P_0c06cd44;
P_0c06cd44: /* original a019, guest PC 0x0c06cd44 */
if(!s->budget--) { s->failed_pc=0x0c06cd44u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c06cd7a;
P_0c06cd46: /* original 0e24, guest PC 0x0c06cd46 */
if(!s->budget--) { s->failed_pc=0x0c06cd46u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c06cd48;
P_0c06cd48: /* original 9009, guest PC 0x0c06cd48 */
if(!s->budget--) { s->failed_pc=0x0c06cd48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cd5eu,2);
goto P_0c06cd4a;
P_0c06cd4a: /* original e103, guest PC 0x0c06cd4a */
if(!s->budget--) { s->failed_pc=0x0c06cd4au; return 0; }
r[1]=0x00000003u;
goto P_0c06cd4c;
P_0c06cd4c: /* original a015, guest PC 0x0c06cd4c */
if(!s->budget--) { s->failed_pc=0x0c06cd4cu; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c06cd7a;
P_0c06cd4e: /* original 0e14, guest PC 0x0c06cd4e */
if(!s->budget--) { s->failed_pc=0x0c06cd4eu; return 0; }
write(ram,r[14]+r[0],r[1],1);
return vf3_matrix_family(0x0c06cd50u,s,ram);
P_0c06cd74: /* original e201, guest PC 0x0c06cd74 */
if(!s->budget--) { s->failed_pc=0x0c06cd74u; return 0; }
r[2]=0x00000001u;
goto P_0c06cd76;
P_0c06cd76: /* original 9059, guest PC 0x0c06cd76 */
if(!s->budget--) { s->failed_pc=0x0c06cd76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ce2cu,2);
goto P_0c06cd78;
P_0c06cd78: /* original 0e24, guest PC 0x0c06cd78 */
if(!s->budget--) { s->failed_pc=0x0c06cd78u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c06cd7a;
P_0c06cd7a: /* original 9058, guest PC 0x0c06cd7a */
if(!s->budget--) { s->failed_pc=0x0c06cd7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ce2eu,2);
goto P_0c06cd7c;
P_0c06cd7c: /* original 6453, guest PC 0x0c06cd7c */
if(!s->budget--) { s->failed_pc=0x0c06cd7cu; return 0; }
r[4]=r[5];
goto P_0c06cd7e;
P_0c06cd7e: /* original 00ec, guest PC 0x0c06cd7e */
if(!s->budget--) { s->failed_pc=0x0c06cd7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06cd80;
P_0c06cd80: /* original 8801, guest PC 0x0c06cd80 */
if(!s->budget--) { s->failed_pc=0x0c06cd80u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cd82;
P_0c06cd82: /* original 8d01, guest PC 0x0c06cd82 */
if(!s->budget--) { s->failed_pc=0x0c06cd82u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c06cd88; }
goto P_0c06cd86;
P_0c06cd84: /* original 6503, guest PC 0x0c06cd84 */
if(!s->budget--) { s->failed_pc=0x0c06cd84u; return 0; }
r[5]=r[0];
goto P_0c06cd86;
P_0c06cd86: /* original 6463, guest PC 0x0c06cd86 */
if(!s->budget--) { s->failed_pc=0x0c06cd86u; return 0; }
r[4]=r[6];
goto P_0c06cd88;
P_0c06cd88: /* original 9050, guest PC 0x0c06cd88 */
if(!s->budget--) { s->failed_pc=0x0c06cd88u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ce2cu,2);
goto P_0c06cd8a;
P_0c06cd8a: /* original 4400, guest PC 0x0c06cd8a */
if(!s->budget--) { s->failed_pc=0x0c06cd8au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06cd8c;
P_0c06cd8c: /* original 03ec, guest PC 0x0c06cd8c */
if(!s->budget--) { s->failed_pc=0x0c06cd8cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06cd8e;
P_0c06cd8e: /* original 2f32, guest PC 0x0c06cd8e */
if(!s->budget--) { s->failed_pc=0x0c06cd8eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06cd90;
P_0c06cd90: /* original 9d4e, guest PC 0x0c06cd90 */
if(!s->budget--) { s->failed_pc=0x0c06cd90u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ce30u,2);
goto P_0c06cd92;
P_0c06cd92: /* original 2d4b, guest PC 0x0c06cd92 */
if(!s->budget--) { s->failed_pc=0x0c06cd92u; return 0; }
r[13]|=r[4];
goto P_0c06cd94;
P_0c06cd94: /* original bae4, guest PC 0x0c06cd94 */
if(!s->budget--) { s->failed_pc=0x0c06cd94u; return 0; }
target=0x0c06c360u; r[16]=0x0c06cd98u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06cd98u) { target=s->pc; goto dispatch; }
goto P_0c06cd98;
P_0c06cd96: /* original 64d3, guest PC 0x0c06cd96 */
if(!s->budget--) { s->failed_pc=0x0c06cd96u; return 0; }
r[4]=r[13];
goto P_0c06cd98;
P_0c06cd98: /* original 2008, guest PC 0x0c06cd98 */
if(!s->budget--) { s->failed_pc=0x0c06cd98u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06cd9a;
P_0c06cd9a: /* original 8924, guest PC 0x0c06cd9a */
if(!s->budget--) { s->failed_pc=0x0c06cd9au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cde6; }
goto P_0c06cd9c;
P_0c06cd9c: /* original 60f2, guest PC 0x0c06cd9c */
if(!s->budget--) { s->failed_pc=0x0c06cd9cu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c06cd9e;
P_0c06cd9e: /* original dc26, guest PC 0x0c06cd9e */
if(!s->budget--) { s->failed_pc=0x0c06cd9eu; return 0; }
r[12]=read(ram,0x0c06ce38u,4);
goto P_0c06cda0;
P_0c06cda0: /* original 8800, guest PC 0x0c06cda0 */
if(!s->budget--) { s->failed_pc=0x0c06cda0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c06cda2;
P_0c06cda2: /* original 8909, guest PC 0x0c06cda2 */
if(!s->budget--) { s->failed_pc=0x0c06cda2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cdb8; }
goto P_0c06cda4;
P_0c06cda4: /* original 8801, guest PC 0x0c06cda4 */
if(!s->budget--) { s->failed_pc=0x0c06cda4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cda6;
P_0c06cda6: /* original 8911, guest PC 0x0c06cda6 */
if(!s->budget--) { s->failed_pc=0x0c06cda6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cdcc; }
goto P_0c06cda8;
P_0c06cda8: /* original 8802, guest PC 0x0c06cda8 */
if(!s->budget--) { s->failed_pc=0x0c06cda8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c06cdaa;
P_0c06cdaa: /* original 8912, guest PC 0x0c06cdaa */
if(!s->budget--) { s->failed_pc=0x0c06cdaau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cdd2; }
goto P_0c06cdac;
P_0c06cdac: /* original 8803, guest PC 0x0c06cdac */
if(!s->budget--) { s->failed_pc=0x0c06cdacu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c06cdae;
P_0c06cdae: /* original 8913, guest PC 0x0c06cdae */
if(!s->budget--) { s->failed_pc=0x0c06cdaeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cdd8; }
goto P_0c06cdb0;
P_0c06cdb0: /* original 8804, guest PC 0x0c06cdb0 */
if(!s->budget--) { s->failed_pc=0x0c06cdb0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c06cdb2;
P_0c06cdb2: /* original 8914, guest PC 0x0c06cdb2 */
if(!s->budget--) { s->failed_pc=0x0c06cdb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cdde; }
goto P_0c06cdb4;
P_0c06cdb4: /* original a017, guest PC 0x0c06cdb4 */
if(!s->budget--) { s->failed_pc=0x0c06cdb4u; return 0; }
goto P_0c06cde6;
P_0c06cdb6: /* original 0009, guest PC 0x0c06cdb6 */
if(!s->budget--) { s->failed_pc=0x0c06cdb6u; return 0; }
goto P_0c06cdb8;
P_0c06cdb8: /* original e320, guest PC 0x0c06cdb8 */
if(!s->budget--) { s->failed_pc=0x0c06cdb8u; return 0; }
r[3]=0x00000020u;
goto P_0c06cdba;
P_0c06cdba: /* original 65d3, guest PC 0x0c06cdba */
if(!s->budget--) { s->failed_pc=0x0c06cdbau; return 0; }
r[5]=r[13];
goto P_0c06cdbc;
P_0c06cdbc: /* original e615, guest PC 0x0c06cdbc */
if(!s->budget--) { s->failed_pc=0x0c06cdbcu; return 0; }
r[6]=0x00000015u;
goto P_0c06cdbe;
P_0c06cdbe: /* original 2f36, guest PC 0x0c06cdbe */
if(!s->budget--) { s->failed_pc=0x0c06cdbeu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cdc0;
P_0c06cdc0: /* original d21e, guest PC 0x0c06cdc0 */
if(!s->budget--) { s->failed_pc=0x0c06cdc0u; return 0; }
r[2]=read(ram,0x0c06ce3cu,4);
goto P_0c06cdc2;
P_0c06cdc2: /* original e701, guest PC 0x0c06cdc2 */
if(!s->budget--) { s->failed_pc=0x0c06cdc2u; return 0; }
r[7]=0x00000001u;
goto P_0c06cdc4;
P_0c06cdc4: /* original 420b, guest PC 0x0c06cdc4 */
if(!s->budget--) { s->failed_pc=0x0c06cdc4u; return 0; }
target=r[2];
r[16]=0x0c06cdc8u;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06cdc8u) { target=s->pc; goto dispatch; }
goto P_0c06cdc8;
P_0c06cdc6: /* original 54f2, guest PC 0x0c06cdc6 */
if(!s->budget--) { s->failed_pc=0x0c06cdc6u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c06cdc8;
P_0c06cdc8: /* original a00d, guest PC 0x0c06cdc8 */
if(!s->budget--) { s->failed_pc=0x0c06cdc8u; return 0; }
r[15]+=0x00000004u;
goto P_0c06cde6;
P_0c06cdca: /* original 7f04, guest PC 0x0c06cdca */
if(!s->budget--) { s->failed_pc=0x0c06cdcau; return 0; }
r[15]+=0x00000004u;
goto P_0c06cdcc;
P_0c06cdcc: /* original d51c, guest PC 0x0c06cdcc */
if(!s->budget--) { s->failed_pc=0x0c06cdccu; return 0; }
r[5]=read(ram,0x0c06ce40u,4);
goto P_0c06cdce;
P_0c06cdce: /* original a008, guest PC 0x0c06cdce */
if(!s->budget--) { s->failed_pc=0x0c06cdceu; return 0; }
r[6]=0x00000001u;
goto P_0c06cde2;
P_0c06cdd0: /* original e601, guest PC 0x0c06cdd0 */
if(!s->budget--) { s->failed_pc=0x0c06cdd0u; return 0; }
r[6]=0x00000001u;
goto P_0c06cdd2;
P_0c06cdd2: /* original d51c, guest PC 0x0c06cdd2 */
if(!s->budget--) { s->failed_pc=0x0c06cdd2u; return 0; }
r[5]=read(ram,0x0c06ce44u,4);
goto P_0c06cdd4;
P_0c06cdd4: /* original a005, guest PC 0x0c06cdd4 */
if(!s->budget--) { s->failed_pc=0x0c06cdd4u; return 0; }
r[6]=0x00000001u;
goto P_0c06cde2;
P_0c06cdd6: /* original e601, guest PC 0x0c06cdd6 */
if(!s->budget--) { s->failed_pc=0x0c06cdd6u; return 0; }
r[6]=0x00000001u;
goto P_0c06cdd8;
P_0c06cdd8: /* original d51b, guest PC 0x0c06cdd8 */
if(!s->budget--) { s->failed_pc=0x0c06cdd8u; return 0; }
r[5]=read(ram,0x0c06ce48u,4);
goto P_0c06cdda;
P_0c06cdda: /* original a002, guest PC 0x0c06cdda */
if(!s->budget--) { s->failed_pc=0x0c06cddau; return 0; }
r[6]=0x00000001u;
goto P_0c06cde2;
P_0c06cddc: /* original e601, guest PC 0x0c06cddc */
if(!s->budget--) { s->failed_pc=0x0c06cddcu; return 0; }
r[6]=0x00000001u;
goto P_0c06cdde;
P_0c06cdde: /* original d51b, guest PC 0x0c06cdde */
if(!s->budget--) { s->failed_pc=0x0c06cddeu; return 0; }
r[5]=read(ram,0x0c06ce4cu,4);
goto P_0c06cde0;
P_0c06cde0: /* original e601, guest PC 0x0c06cde0 */
if(!s->budget--) { s->failed_pc=0x0c06cde0u; return 0; }
r[6]=0x00000001u;
goto P_0c06cde2;
P_0c06cde2: /* original 4c0b, guest PC 0x0c06cde2 */
if(!s->budget--) { s->failed_pc=0x0c06cde2u; return 0; }
target=r[12];
r[16]=0x0c06cde6u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06cde6u) { target=s->pc; goto dispatch; }
goto P_0c06cde6;
P_0c06cde4: /* original 64d3, guest PC 0x0c06cde4 */
if(!s->budget--) { s->failed_pc=0x0c06cde4u; return 0; }
r[4]=r[13];
goto P_0c06cde6;
P_0c06cde6: /* original 7f08, guest PC 0x0c06cde6 */
if(!s->budget--) { s->failed_pc=0x0c06cde6u; return 0; }
r[15]+=0x00000008u;
goto P_0c06cde8;
P_0c06cde8: /* original 4f26, guest PC 0x0c06cde8 */
if(!s->budget--) { s->failed_pc=0x0c06cde8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06cdea;
P_0c06cdea: /* original 6cf6, guest PC 0x0c06cdea */
if(!s->budget--) { s->failed_pc=0x0c06cdeau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06cdec;
P_0c06cdec: /* original 6df6, guest PC 0x0c06cdec */
if(!s->budget--) { s->failed_pc=0x0c06cdecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06cdee;
P_0c06cdee: /* original 000b, guest PC 0x0c06cdee */
if(!s->budget--) { s->failed_pc=0x0c06cdeeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06cdf0: /* original 6ef6, guest PC 0x0c06cdf0 */
if(!s->budget--) { s->failed_pc=0x0c06cdf0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06cdf2u,s,ram);
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
return vf3_matrix_family(0x0c0a00f4u,s,ram);
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
return vf3_matrix_family(0x0c0a01eau,s,ram);
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
target=0x0c0a0718u; r[16]=0x0c0a0238u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a0238u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c0a0266u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a0266u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c0a0280u,s,ram);
P_0c0a0718: /* original 2fe6, guest PC 0x0c0a0718 */
if(!s->budget--) { s->failed_pc=0x0c0a0718u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a071a;
P_0c0a071a: /* original ee00, guest PC 0x0c0a071a */
if(!s->budget--) { s->failed_pc=0x0c0a071au; return 0; }
r[14]=0x00000000u;
goto P_0c0a071c;
P_0c0a071c: /* original d54a, guest PC 0x0c0a071c */
if(!s->budget--) { s->failed_pc=0x0c0a071cu; return 0; }
r[5]=read(ram,0x0c0a0848u,4);
goto P_0c0a071e;
P_0c0a071e: /* original 7fd4, guest PC 0x0c0a071e */
if(!s->budget--) { s->failed_pc=0x0c0a071eu; return 0; }
r[15]+=0xffffffd4u;
goto P_0c0a0720;
P_0c0a0720: /* original 64f3, guest PC 0x0c0a0720 */
if(!s->budget--) { s->failed_pc=0x0c0a0720u; return 0; }
r[4]=r[15];
goto P_0c0a0722;
P_0c0a0722: /* original 7420, guest PC 0x0c0a0722 */
if(!s->budget--) { s->failed_pc=0x0c0a0722u; return 0; }
r[4]+=0x00000020u;
goto P_0c0a0724;
P_0c0a0724: /* original 6343, guest PC 0x0c0a0724 */
if(!s->budget--) { s->failed_pc=0x0c0a0724u; return 0; }
r[3]=r[4];
goto P_0c0a0726;
P_0c0a0726: /* original 1f31, guest PC 0x0c0a0726 */
if(!s->budget--) { s->failed_pc=0x0c0a0726u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0a0728;
P_0c0a0728: /* original 9086, guest PC 0x0c0a0728 */
if(!s->budget--) { s->failed_pc=0x0c0a0728u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0838u,2);
goto P_0c0a072a;
P_0c0a072a: /* original 7402, guest PC 0x0c0a072a */
if(!s->budget--) { s->failed_pc=0x0c0a072au; return 0; }
r[4]+=0x00000002u;
goto P_0c0a072c;
P_0c0a072c: /* original 025c, guest PC 0x0c0a072c */
if(!s->budget--) { s->failed_pc=0x0c0a072cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0a072e;
P_0c0a072e: /* original 2320, guest PC 0x0c0a072e */
if(!s->budget--) { s->failed_pc=0x0c0a072eu; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0a0730;
P_0c0a0730: /* original 7301, guest PC 0x0c0a0730 */
if(!s->budget--) { s->failed_pc=0x0c0a0730u; return 0; }
r[3]+=0x00000001u;
goto P_0c0a0732;
P_0c0a0732: /* original 1f36, guest PC 0x0c0a0732 */
if(!s->budget--) { s->failed_pc=0x0c0a0732u; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0a0734;
P_0c0a0734: /* original 9081, guest PC 0x0c0a0734 */
if(!s->budget--) { s->failed_pc=0x0c0a0734u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a083au,2);
goto P_0c0a0736;
P_0c0a0736: /* original 025c, guest PC 0x0c0a0736 */
if(!s->budget--) { s->failed_pc=0x0c0a0736u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0a0738;
P_0c0a0738: /* original 2320, guest PC 0x0c0a0738 */
if(!s->budget--) { s->failed_pc=0x0c0a0738u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0a073a;
P_0c0a073a: /* original 1f44, guest PC 0x0c0a073a */
if(!s->budget--) { s->failed_pc=0x0c0a073au; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c0a073c;
P_0c0a073c: /* original 907e, guest PC 0x0c0a073c */
if(!s->budget--) { s->failed_pc=0x0c0a073cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a083cu,2);
goto P_0c0a073e;
P_0c0a073e: /* original 035c, guest PC 0x0c0a073e */
if(!s->budget--) { s->failed_pc=0x0c0a073eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0a0740;
P_0c0a0740: /* original 2430, guest PC 0x0c0a0740 */
if(!s->budget--) { s->failed_pc=0x0c0a0740u; return 0; }
write(ram,r[4],r[3],1);
goto P_0c0a0742;
P_0c0a0742: /* original d242, guest PC 0x0c0a0742 */
if(!s->budget--) { s->failed_pc=0x0c0a0742u; return 0; }
r[2]=read(ram,0x0c0a084cu,4);
goto P_0c0a0744;
P_0c0a0744: /* original 1f27, guest PC 0x0c0a0744 */
if(!s->budget--) { s->failed_pc=0x0c0a0744u; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c0a0746;
P_0c0a0746: /* original d342, guest PC 0x0c0a0746 */
if(!s->budget--) { s->failed_pc=0x0c0a0746u; return 0; }
r[3]=read(ram,0x0c0a0850u,4);
goto P_0c0a0748;
P_0c0a0748: /* original 2f32, guest PC 0x0c0a0748 */
if(!s->budget--) { s->failed_pc=0x0c0a0748u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a074a;
P_0c0a074a: /* original e30b, guest PC 0x0c0a074a */
if(!s->budget--) { s->failed_pc=0x0c0a074au; return 0; }
r[3]=0x0000000bu;
goto P_0c0a074c;
P_0c0a074c: /* original 3e33, guest PC 0x0c0a074c */
if(!s->budget--) { s->failed_pc=0x0c0a074cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c0a074e;
P_0c0a074e: /* original 8946, guest PC 0x0c0a074e */
if(!s->budget--) { s->failed_pc=0x0c0a074eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a07de; }
goto P_0c0a0750;
P_0c0a0750: /* original 54f7, guest PC 0x0c0a0750 */
if(!s->budget--) { s->failed_pc=0x0c0a0750u; return 0; }
r[4]=read(ram,r[15]+28,4);
goto P_0c0a0752;
P_0c0a0752: /* original 67f3, guest PC 0x0c0a0752 */
if(!s->budget--) { s->failed_pc=0x0c0a0752u; return 0; }
r[7]=r[15];
goto P_0c0a0754;
P_0c0a0754: /* original 7728, guest PC 0x0c0a0754 */
if(!s->budget--) { s->failed_pc=0x0c0a0754u; return 0; }
r[7]+=0x00000028u;
goto P_0c0a0756;
P_0c0a0756: /* original 7404, guest PC 0x0c0a0756 */
if(!s->budget--) { s->failed_pc=0x0c0a0756u; return 0; }
r[4]+=0x00000004u;
goto P_0c0a0758;
P_0c0a0758: /* original 6373, guest PC 0x0c0a0758 */
if(!s->budget--) { s->failed_pc=0x0c0a0758u; return 0; }
r[3]=r[7];
goto P_0c0a075a;
P_0c0a075a: /* original 1f47, guest PC 0x0c0a075a */
if(!s->budget--) { s->failed_pc=0x0c0a075au; return 0; }
write(ram,r[15]+28,r[4],4);
goto P_0c0a075c;
P_0c0a075c: /* original 74fc, guest PC 0x0c0a075c */
if(!s->budget--) { s->failed_pc=0x0c0a075cu; return 0; }
r[4]+=0xfffffffcu;
goto P_0c0a075e;
P_0c0a075e: /* original 6442, guest PC 0x0c0a075e */
if(!s->budget--) { s->failed_pc=0x0c0a075eu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0a0760;
P_0c0a0760: /* original 66f2, guest PC 0x0c0a0760 */
if(!s->budget--) { s->failed_pc=0x0c0a0760u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c0a0762;
P_0c0a0762: /* original 7604, guest PC 0x0c0a0762 */
if(!s->budget--) { s->failed_pc=0x0c0a0762u; return 0; }
r[6]+=0x00000004u;
goto P_0c0a0764;
P_0c0a0764: /* original 2f62, guest PC 0x0c0a0764 */
if(!s->budget--) { s->failed_pc=0x0c0a0764u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0a0766;
P_0c0a0766: /* original 76fc, guest PC 0x0c0a0766 */
if(!s->budget--) { s->failed_pc=0x0c0a0766u; return 0; }
r[6]+=0xfffffffcu;
goto P_0c0a0768;
P_0c0a0768: /* original 6662, guest PC 0x0c0a0768 */
if(!s->budget--) { s->failed_pc=0x0c0a0768u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c0a076a;
P_0c0a076a: /* original 1f32, guest PC 0x0c0a076a */
if(!s->budget--) { s->failed_pc=0x0c0a076au; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0a076c;
P_0c0a076c: /* original 6244, guest PC 0x0c0a076c */
if(!s->budget--) { s->failed_pc=0x0c0a076cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[2]=tmp;
goto P_0c0a076e;
P_0c0a076e: /* original 2320, guest PC 0x0c0a076e */
if(!s->budget--) { s->failed_pc=0x0c0a076eu; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0a0770;
P_0c0a0770: /* original 7301, guest PC 0x0c0a0770 */
if(!s->budget--) { s->failed_pc=0x0c0a0770u; return 0; }
r[3]+=0x00000001u;
goto P_0c0a0772;
P_0c0a0772: /* original 1f35, guest PC 0x0c0a0772 */
if(!s->budget--) { s->failed_pc=0x0c0a0772u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c0a0774;
P_0c0a0774: /* original 6244, guest PC 0x0c0a0774 */
if(!s->budget--) { s->failed_pc=0x0c0a0774u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[2]=tmp;
goto P_0c0a0776;
P_0c0a0776: /* original 2320, guest PC 0x0c0a0776 */
if(!s->budget--) { s->failed_pc=0x0c0a0776u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0a0778;
P_0c0a0778: /* original 6373, guest PC 0x0c0a0778 */
if(!s->budget--) { s->failed_pc=0x0c0a0778u; return 0; }
r[3]=r[7];
goto P_0c0a077a;
P_0c0a077a: /* original 7302, guest PC 0x0c0a077a */
if(!s->budget--) { s->failed_pc=0x0c0a077au; return 0; }
r[3]+=0x00000002u;
goto P_0c0a077c;
P_0c0a077c: /* original 1f33, guest PC 0x0c0a077c */
if(!s->budget--) { s->failed_pc=0x0c0a077cu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0a077e;
P_0c0a077e: /* original 6244, guest PC 0x0c0a077e */
if(!s->budget--) { s->failed_pc=0x0c0a077eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[2]=tmp;
goto P_0c0a0780;
P_0c0a0780: /* original 2320, guest PC 0x0c0a0780 */
if(!s->budget--) { s->failed_pc=0x0c0a0780u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c0a0782;
P_0c0a0782: /* original 6040, guest PC 0x0c0a0782 */
if(!s->budget--) { s->failed_pc=0x0c0a0782u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
goto P_0c0a0784;
P_0c0a0784: /* original 64f3, guest PC 0x0c0a0784 */
if(!s->budget--) { s->failed_pc=0x0c0a0784u; return 0; }
r[4]=r[15];
goto P_0c0a0786;
P_0c0a0786: /* original 7424, guest PC 0x0c0a0786 */
if(!s->budget--) { s->failed_pc=0x0c0a0786u; return 0; }
r[4]+=0x00000024u;
goto P_0c0a0788;
P_0c0a0788: /* original 8073, guest PC 0x0c0a0788 */
if(!s->budget--) { s->failed_pc=0x0c0a0788u; return 0; }
write(ram,r[7]+3,r[0],1);
goto P_0c0a078a;
P_0c0a078a: /* original 6364, guest PC 0x0c0a078a */
if(!s->budget--) { s->failed_pc=0x0c0a078au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]+=1;
r[3]=tmp;
goto P_0c0a078c;
P_0c0a078c: /* original 2430, guest PC 0x0c0a078c */
if(!s->budget--) { s->failed_pc=0x0c0a078cu; return 0; }
write(ram,r[4],r[3],1);
goto P_0c0a078e;
P_0c0a078e: /* original 6064, guest PC 0x0c0a078e */
if(!s->budget--) { s->failed_pc=0x0c0a078eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]+=1;
r[0]=tmp;
goto P_0c0a0790;
P_0c0a0790: /* original 8041, guest PC 0x0c0a0790 */
if(!s->budget--) { s->failed_pc=0x0c0a0790u; return 0; }
write(ram,r[4]+1,r[0],1);
goto P_0c0a0792;
P_0c0a0792: /* original 6064, guest PC 0x0c0a0792 */
if(!s->budget--) { s->failed_pc=0x0c0a0792u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]+=1;
r[0]=tmp;
goto P_0c0a0794;
P_0c0a0794: /* original 8042, guest PC 0x0c0a0794 */
if(!s->budget--) { s->failed_pc=0x0c0a0794u; return 0; }
write(ram,r[4]+2,r[0],1);
goto P_0c0a0796;
P_0c0a0796: /* original 6060, guest PC 0x0c0a0796 */
if(!s->budget--) { s->failed_pc=0x0c0a0796u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[0]=tmp;
goto P_0c0a0798;
P_0c0a0798: /* original 8043, guest PC 0x0c0a0798 */
if(!s->budget--) { s->failed_pc=0x0c0a0798u; return 0; }
write(ram,r[4]+3,r[0],1);
goto P_0c0a079a;
P_0c0a079a: /* original 53f1, guest PC 0x0c0a079a */
if(!s->budget--) { s->failed_pc=0x0c0a079au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a079c;
P_0c0a079c: /* original 6230, guest PC 0x0c0a079c */
if(!s->budget--) { s->failed_pc=0x0c0a079cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0a079e;
P_0c0a079e: /* original 53f2, guest PC 0x0c0a079e */
if(!s->budget--) { s->failed_pc=0x0c0a079eu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0a07a0;
P_0c0a07a0: /* original 6130, guest PC 0x0c0a07a0 */
if(!s->budget--) { s->failed_pc=0x0c0a07a0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[1]=tmp;
goto P_0c0a07a2;
P_0c0a07a2: /* original 3210, guest PC 0x0c0a07a2 */
if(!s->budget--) { s->failed_pc=0x0c0a07a2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c0a07a4;
P_0c0a07a4: /* original 8fd1, guest PC 0x0c0a07a4 */
if(!s->budget--) { s->failed_pc=0x0c0a07a4u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000001u;
if(!cond) { goto P_0c0a074a; }
goto P_0c0a07a8;
P_0c0a07a6: /* original 7e01, guest PC 0x0c0a07a6 */
if(!s->budget--) { s->failed_pc=0x0c0a07a6u; return 0; }
r[14]+=0x00000001u;
goto P_0c0a07a8;
P_0c0a07a8: /* original 52f6, guest PC 0x0c0a07a8 */
if(!s->budget--) { s->failed_pc=0x0c0a07a8u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c0a07aa;
P_0c0a07aa: /* original 6320, guest PC 0x0c0a07aa */
if(!s->budget--) { s->failed_pc=0x0c0a07aau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c0a07ac;
P_0c0a07ac: /* original 52f5, guest PC 0x0c0a07ac */
if(!s->budget--) { s->failed_pc=0x0c0a07acu; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0a07ae;
P_0c0a07ae: /* original 6120, guest PC 0x0c0a07ae */
if(!s->budget--) { s->failed_pc=0x0c0a07aeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c0a07b0;
P_0c0a07b0: /* original 3310, guest PC 0x0c0a07b0 */
if(!s->budget--) { s->failed_pc=0x0c0a07b0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c0a07b2;
P_0c0a07b2: /* original 8bca, guest PC 0x0c0a07b2 */
if(!s->budget--) { s->failed_pc=0x0c0a07b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a074a; }
goto P_0c0a07b4;
P_0c0a07b4: /* original 52f4, guest PC 0x0c0a07b4 */
if(!s->budget--) { s->failed_pc=0x0c0a07b4u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0a07b6;
P_0c0a07b6: /* original 6320, guest PC 0x0c0a07b6 */
if(!s->budget--) { s->failed_pc=0x0c0a07b6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c0a07b8;
P_0c0a07b8: /* original 52f3, guest PC 0x0c0a07b8 */
if(!s->budget--) { s->failed_pc=0x0c0a07b8u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0a07ba;
P_0c0a07ba: /* original 6120, guest PC 0x0c0a07ba */
if(!s->budget--) { s->failed_pc=0x0c0a07bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c0a07bc;
P_0c0a07bc: /* original 3310, guest PC 0x0c0a07bc */
if(!s->budget--) { s->failed_pc=0x0c0a07bcu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c0a07be;
P_0c0a07be: /* original 8bc4, guest PC 0x0c0a07be */
if(!s->budget--) { s->failed_pc=0x0c0a07beu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a074a; }
goto P_0c0a07c0;
P_0c0a07c0: /* original 903a, guest PC 0x0c0a07c0 */
if(!s->budget--) { s->failed_pc=0x0c0a07c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0838u,2);
goto P_0c0a07c2;
P_0c0a07c2: /* original 6340, guest PC 0x0c0a07c2 */
if(!s->budget--) { s->failed_pc=0x0c0a07c2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c0a07c4;
P_0c0a07c4: /* original 0534, guest PC 0x0c0a07c4 */
if(!s->budget--) { s->failed_pc=0x0c0a07c4u; return 0; }
write(ram,r[5]+r[0],r[3],1);
goto P_0c0a07c6;
P_0c0a07c6: /* original 9138, guest PC 0x0c0a07c6 */
if(!s->budget--) { s->failed_pc=0x0c0a07c6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a083au,2);
goto P_0c0a07c8;
P_0c0a07c8: /* original 8441, guest PC 0x0c0a07c8 */
if(!s->budget--) { s->failed_pc=0x0c0a07c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0a07ca;
P_0c0a07ca: /* original 315c, guest PC 0x0c0a07ca */
if(!s->budget--) { s->failed_pc=0x0c0a07cau; return 0; }
r[1]+=r[5];
goto P_0c0a07cc;
P_0c0a07cc: /* original 2100, guest PC 0x0c0a07cc */
if(!s->budget--) { s->failed_pc=0x0c0a07ccu; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0a07ce;
P_0c0a07ce: /* original 9235, guest PC 0x0c0a07ce */
if(!s->budget--) { s->failed_pc=0x0c0a07ceu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a083cu,2);
goto P_0c0a07d0;
P_0c0a07d0: /* original 8442, guest PC 0x0c0a07d0 */
if(!s->budget--) { s->failed_pc=0x0c0a07d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c0a07d2;
P_0c0a07d2: /* original 325c, guest PC 0x0c0a07d2 */
if(!s->budget--) { s->failed_pc=0x0c0a07d2u; return 0; }
r[2]+=r[5];
goto P_0c0a07d4;
P_0c0a07d4: /* original 2200, guest PC 0x0c0a07d4 */
if(!s->budget--) { s->failed_pc=0x0c0a07d4u; return 0; }
write(ram,r[2],r[0],1);
goto P_0c0a07d6;
P_0c0a07d6: /* original 9132, guest PC 0x0c0a07d6 */
if(!s->budget--) { s->failed_pc=0x0c0a07d6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a083eu,2);
goto P_0c0a07d8;
P_0c0a07d8: /* original 8443, guest PC 0x0c0a07d8 */
if(!s->budget--) { s->failed_pc=0x0c0a07d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c0a07da;
P_0c0a07da: /* original 315c, guest PC 0x0c0a07da */
if(!s->budget--) { s->failed_pc=0x0c0a07dau; return 0; }
r[1]+=r[5];
goto P_0c0a07dc;
P_0c0a07dc: /* original 2100, guest PC 0x0c0a07dc */
if(!s->budget--) { s->failed_pc=0x0c0a07dcu; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0a07de;
P_0c0a07de: /* original 7f2c, guest PC 0x0c0a07de */
if(!s->budget--) { s->failed_pc=0x0c0a07deu; return 0; }
r[15]+=0x0000002cu;
goto P_0c0a07e0;
P_0c0a07e0: /* original 000b, guest PC 0x0c0a07e0 */
if(!s->budget--) { s->failed_pc=0x0c0a07e0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a07e2: /* original 6ef6, guest PC 0x0c0a07e2 */
if(!s->budget--) { s->failed_pc=0x0c0a07e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a07e4u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c06c360u,0x0c06c362u,0x0c06c364u,0x0c06c366u,0x0c06c368u,0x0c06c36au,0x0c06c36cu,0x0c06c36eu,0x0c06c370u,0x0c06c372u,0x0c06c374u,0x0c06c376u,0x0c06c378u,0x0c06c37au,0x0c06c37cu,0x0c06c37eu,
0x0c06c380u,0x0c06c382u,0x0c06c384u,0x0c06c386u,0x0c06c388u,0x0c06c38au,0x0c06c38cu,0x0c06c38eu,0x0c06c390u,0x0c06c392u,0x0c06c394u,0x0c06c396u,0x0c06c51eu,0x0c06c520u,0x0c06c522u,0x0c06c524u,
0x0c06c526u,0x0c06c528u,0x0c06c52au,0x0c06c52cu,0x0c06c52eu,0x0c06c530u,0x0c06c532u,0x0c06c534u,0x0c06c536u,0x0c06c538u,0x0c06c53au,0x0c06c53cu,0x0c06c53eu,0x0c06c540u,0x0c06c542u,0x0c06c544u,
0x0c06c546u,0x0c06c548u,0x0c06c54au,0x0c06c54cu,0x0c06c54eu,0x0c06c550u,0x0c06c552u,0x0c06c554u,0x0c06c556u,0x0c06c558u,0x0c06c55au,0x0c06c55cu,0x0c06c55eu,0x0c06c560u,0x0c06c562u,0x0c06c564u,
0x0c06c566u,0x0c06c568u,0x0c06c56au,0x0c06c56cu,0x0c06c56eu,0x0c06c570u,0x0c06c572u,0x0c06c574u,0x0c06c576u,0x0c06c578u,0x0c06c57au,0x0c06c57cu,0x0c06c57eu,0x0c06c580u,0x0c06c582u,0x0c06c584u,
0x0c06c586u,0x0c06c588u,0x0c06c58au,0x0c06c58cu,0x0c06c58eu,0x0c06c590u,0x0c06c592u,0x0c06c594u,0x0c06c596u,0x0c06c598u,0x0c06ccc0u,0x0c06ccc2u,0x0c06ccc4u,0x0c06ccc6u,0x0c06ccc8u,0x0c06cccau,
0x0c06ccccu,0x0c06ccceu,0x0c06ccd0u,0x0c06ccd2u,0x0c06ccd4u,0x0c06ccd6u,0x0c06ccd8u,0x0c06ccdau,0x0c06ccdcu,0x0c06ccdeu,0x0c06cce0u,0x0c06cce2u,0x0c06cce4u,0x0c06cce6u,0x0c06cce8u,0x0c06cceau,
0x0c06ccecu,0x0c06cceeu,0x0c06ccf0u,0x0c06ccf2u,0x0c06ccf4u,0x0c06ccf6u,0x0c06ccf8u,0x0c06ccfau,0x0c06ccfcu,0x0c06ccfeu,0x0c06cd00u,0x0c06cd02u,0x0c06cd04u,0x0c06cd06u,0x0c06cd08u,0x0c06cd0au,
0x0c06cd0cu,0x0c06cd0eu,0x0c06cd10u,0x0c06cd12u,0x0c06cd14u,0x0c06cd16u,0x0c06cd18u,0x0c06cd1au,0x0c06cd1cu,0x0c06cd1eu,0x0c06cd20u,0x0c06cd22u,0x0c06cd24u,0x0c06cd26u,0x0c06cd28u,0x0c06cd2au,
0x0c06cd2cu,0x0c06cd2eu,0x0c06cd30u,0x0c06cd32u,0x0c06cd34u,0x0c06cd36u,0x0c06cd38u,0x0c06cd3au,0x0c06cd3cu,0x0c06cd3eu,0x0c06cd40u,0x0c06cd42u,0x0c06cd44u,0x0c06cd46u,0x0c06cd48u,0x0c06cd4au,
0x0c06cd4cu,0x0c06cd4eu,0x0c06cd74u,0x0c06cd76u,0x0c06cd78u,0x0c06cd7au,0x0c06cd7cu,0x0c06cd7eu,0x0c06cd80u,0x0c06cd82u,0x0c06cd84u,0x0c06cd86u,0x0c06cd88u,0x0c06cd8au,0x0c06cd8cu,0x0c06cd8eu,
0x0c06cd90u,0x0c06cd92u,0x0c06cd94u,0x0c06cd96u,0x0c06cd98u,0x0c06cd9au,0x0c06cd9cu,0x0c06cd9eu,0x0c06cda0u,0x0c06cda2u,0x0c06cda4u,0x0c06cda6u,0x0c06cda8u,0x0c06cdaau,0x0c06cdacu,0x0c06cdaeu,
0x0c06cdb0u,0x0c06cdb2u,0x0c06cdb4u,0x0c06cdb6u,0x0c06cdb8u,0x0c06cdbau,0x0c06cdbcu,0x0c06cdbeu,0x0c06cdc0u,0x0c06cdc2u,0x0c06cdc4u,0x0c06cdc6u,0x0c06cdc8u,0x0c06cdcau,0x0c06cdccu,0x0c06cdceu,
0x0c06cdd0u,0x0c06cdd2u,0x0c06cdd4u,0x0c06cdd6u,0x0c06cdd8u,0x0c06cddau,0x0c06cddcu,0x0c06cddeu,0x0c06cde0u,0x0c06cde2u,0x0c06cde4u,0x0c06cde6u,0x0c06cde8u,0x0c06cdeau,0x0c06cdecu,0x0c06cdeeu,
0x0c06cdf0u,0x0c0a00b6u,0x0c0a00b8u,0x0c0a00bau,0x0c0a00bcu,0x0c0a00beu,0x0c0a00c0u,0x0c0a00c2u,0x0c0a00c4u,0x0c0a00c6u,0x0c0a00c8u,0x0c0a00cau,0x0c0a00ccu,0x0c0a00ceu,0x0c0a00d0u,0x0c0a00d2u,
0x0c0a00d4u,0x0c0a00d6u,0x0c0a00d8u,0x0c0a00dau,0x0c0a00dcu,0x0c0a00deu,0x0c0a00e0u,0x0c0a00e2u,0x0c0a00e4u,0x0c0a00e6u,0x0c0a00e8u,0x0c0a00eau,0x0c0a00ecu,0x0c0a00eeu,0x0c0a00f0u,0x0c0a00f2u,
0x0c0a0120u,0x0c0a0122u,0x0c0a0124u,0x0c0a0126u,0x0c0a0128u,0x0c0a012au,0x0c0a012cu,0x0c0a012eu,0x0c0a0130u,0x0c0a0132u,0x0c0a0134u,0x0c0a0136u,0x0c0a0138u,0x0c0a013au,0x0c0a013cu,0x0c0a013eu,
0x0c0a0140u,0x0c0a0142u,0x0c0a0144u,0x0c0a0146u,0x0c0a0148u,0x0c0a014au,0x0c0a014cu,0x0c0a014eu,0x0c0a0150u,0x0c0a0152u,0x0c0a0154u,0x0c0a0156u,0x0c0a0158u,0x0c0a015au,0x0c0a015cu,0x0c0a015eu,
0x0c0a0160u,0x0c0a0162u,0x0c0a0164u,0x0c0a0166u,0x0c0a0168u,0x0c0a016au,0x0c0a016cu,0x0c0a016eu,0x0c0a0170u,0x0c0a0172u,0x0c0a0174u,0x0c0a0176u,0x0c0a0178u,0x0c0a017au,0x0c0a017cu,0x0c0a017eu,
0x0c0a0180u,0x0c0a0182u,0x0c0a0184u,0x0c0a0186u,0x0c0a0188u,0x0c0a018au,0x0c0a018cu,0x0c0a018eu,0x0c0a0190u,0x0c0a0192u,0x0c0a0194u,0x0c0a0196u,0x0c0a0198u,0x0c0a019au,0x0c0a019cu,0x0c0a019eu,
0x0c0a01a0u,0x0c0a01a2u,0x0c0a01a4u,0x0c0a01a6u,0x0c0a01a8u,0x0c0a01aau,0x0c0a01acu,0x0c0a01aeu,0x0c0a01b0u,0x0c0a01b2u,0x0c0a01b4u,0x0c0a01b6u,0x0c0a01b8u,0x0c0a01bau,0x0c0a01bcu,0x0c0a01beu,
0x0c0a01c0u,0x0c0a01c2u,0x0c0a01c4u,0x0c0a01c6u,0x0c0a01c8u,0x0c0a01cau,0x0c0a01ccu,0x0c0a01ceu,0x0c0a01d0u,0x0c0a01d2u,0x0c0a01d4u,0x0c0a01d6u,0x0c0a01d8u,0x0c0a01dau,0x0c0a01dcu,0x0c0a01deu,
0x0c0a01e0u,0x0c0a01e2u,0x0c0a01e4u,0x0c0a01e6u,0x0c0a01e8u,0x0c0a020cu,0x0c0a020eu,0x0c0a0210u,0x0c0a0212u,0x0c0a0214u,0x0c0a0216u,0x0c0a0218u,0x0c0a021au,0x0c0a021cu,0x0c0a021eu,0x0c0a0220u,
0x0c0a0222u,0x0c0a0224u,0x0c0a0226u,0x0c0a0228u,0x0c0a022au,0x0c0a022cu,0x0c0a022eu,0x0c0a0230u,0x0c0a0232u,0x0c0a0234u,0x0c0a0236u,0x0c0a0238u,0x0c0a023au,0x0c0a023cu,0x0c0a023eu,0x0c0a0240u,
0x0c0a0242u,0x0c0a0244u,0x0c0a0246u,0x0c0a0248u,0x0c0a024au,0x0c0a024cu,0x0c0a024eu,0x0c0a0250u,0x0c0a0252u,0x0c0a0254u,0x0c0a0256u,0x0c0a0258u,0x0c0a025au,0x0c0a025cu,0x0c0a025eu,0x0c0a0260u,
0x0c0a0262u,0x0c0a0264u,0x0c0a0266u,0x0c0a0268u,0x0c0a026au,0x0c0a026cu,0x0c0a026eu,0x0c0a0270u,0x0c0a0272u,0x0c0a0274u,0x0c0a0276u,0x0c0a0278u,0x0c0a027au,0x0c0a027cu,0x0c0a027eu,0x0c0a0718u,
0x0c0a071au,0x0c0a071cu,0x0c0a071eu,0x0c0a0720u,0x0c0a0722u,0x0c0a0724u,0x0c0a0726u,0x0c0a0728u,0x0c0a072au,0x0c0a072cu,0x0c0a072eu,0x0c0a0730u,0x0c0a0732u,0x0c0a0734u,0x0c0a0736u,0x0c0a0738u,
0x0c0a073au,0x0c0a073cu,0x0c0a073eu,0x0c0a0740u,0x0c0a0742u,0x0c0a0744u,0x0c0a0746u,0x0c0a0748u,0x0c0a074au,0x0c0a074cu,0x0c0a074eu,0x0c0a0750u,0x0c0a0752u,0x0c0a0754u,0x0c0a0756u,0x0c0a0758u,
0x0c0a075au,0x0c0a075cu,0x0c0a075eu,0x0c0a0760u,0x0c0a0762u,0x0c0a0764u,0x0c0a0766u,0x0c0a0768u,0x0c0a076au,0x0c0a076cu,0x0c0a076eu,0x0c0a0770u,0x0c0a0772u,0x0c0a0774u,0x0c0a0776u,0x0c0a0778u,
0x0c0a077au,0x0c0a077cu,0x0c0a077eu,0x0c0a0780u,0x0c0a0782u,0x0c0a0784u,0x0c0a0786u,0x0c0a0788u,0x0c0a078au,0x0c0a078cu,0x0c0a078eu,0x0c0a0790u,0x0c0a0792u,0x0c0a0794u,0x0c0a0796u,0x0c0a0798u,
0x0c0a079au,0x0c0a079cu,0x0c0a079eu,0x0c0a07a0u,0x0c0a07a2u,0x0c0a07a4u,0x0c0a07a6u,0x0c0a07a8u,0x0c0a07aau,0x0c0a07acu,0x0c0a07aeu,0x0c0a07b0u,0x0c0a07b2u,0x0c0a07b4u,0x0c0a07b6u,0x0c0a07b8u,
0x0c0a07bau,0x0c0a07bcu,0x0c0a07beu,0x0c0a07c0u,0x0c0a07c2u,0x0c0a07c4u,0x0c0a07c6u,0x0c0a07c8u,0x0c0a07cau,0x0c0a07ccu,0x0c0a07ceu,0x0c0a07d0u,0x0c0a07d2u,0x0c0a07d4u,0x0c0a07d6u,0x0c0a07d8u,
0x0c0a07dau,0x0c0a07dcu,0x0c0a07deu,0x0c0a07e0u,0x0c0a07e2u,
};
int vf3_advance_controller_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
