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
int vf3_away_batch8_adapter_18(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0644e8u: goto P_0c0644e8;
case 0x0c0644eau: goto P_0c0644ea;
case 0x0c0644ecu: goto P_0c0644ec;
case 0x0c0644eeu: goto P_0c0644ee;
case 0x0c0644f0u: goto P_0c0644f0;
case 0x0c0644f2u: goto P_0c0644f2;
case 0x0c0644f4u: goto P_0c0644f4;
case 0x0c0644f6u: goto P_0c0644f6;
case 0x0c0644f8u: goto P_0c0644f8;
case 0x0c0644fau: goto P_0c0644fa;
case 0x0c0644fcu: goto P_0c0644fc;
case 0x0c0644feu: goto P_0c0644fe;
case 0x0c064500u: goto P_0c064500;
case 0x0c064502u: goto P_0c064502;
case 0x0c064504u: goto P_0c064504;
case 0x0c064506u: goto P_0c064506;
case 0x0c064508u: goto P_0c064508;
case 0x0c06450au: goto P_0c06450a;
case 0x0c06450cu: goto P_0c06450c;
case 0x0c06450eu: goto P_0c06450e;
case 0x0c064510u: goto P_0c064510;
case 0x0c064512u: goto P_0c064512;
case 0x0c064514u: goto P_0c064514;
case 0x0c064516u: goto P_0c064516;
case 0x0c064518u: goto P_0c064518;
case 0x0c06451au: goto P_0c06451a;
case 0x0c06451cu: goto P_0c06451c;
case 0x0c06451eu: goto P_0c06451e;
case 0x0c064520u: goto P_0c064520;
case 0x0c064522u: goto P_0c064522;
case 0x0c064524u: goto P_0c064524;
case 0x0c064526u: goto P_0c064526;
case 0x0c064528u: goto P_0c064528;
case 0x0c06452au: goto P_0c06452a;
case 0x0c06452cu: goto P_0c06452c;
case 0x0c06452eu: goto P_0c06452e;
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
case 0x0c064594u: goto P_0c064594;
case 0x0c064596u: goto P_0c064596;
case 0x0c064598u: goto P_0c064598;
case 0x0c06459au: goto P_0c06459a;
case 0x0c06459cu: goto P_0c06459c;
case 0x0c06459eu: goto P_0c06459e;
case 0x0c0645a0u: goto P_0c0645a0;
case 0x0c0645a2u: goto P_0c0645a2;
case 0x0c0645a4u: goto P_0c0645a4;
case 0x0c0645a6u: goto P_0c0645a6;
case 0x0c0645a8u: goto P_0c0645a8;
case 0x0c0645aau: goto P_0c0645aa;
case 0x0c0645acu: goto P_0c0645ac;
case 0x0c0645aeu: goto P_0c0645ae;
case 0x0c0645b0u: goto P_0c0645b0;
case 0x0c0645b2u: goto P_0c0645b2;
case 0x0c0645b4u: goto P_0c0645b4;
case 0x0c0645b6u: goto P_0c0645b6;
case 0x0c0645b8u: goto P_0c0645b8;
case 0x0c0645bau: goto P_0c0645ba;
case 0x0c0645bcu: goto P_0c0645bc;
case 0x0c0645beu: goto P_0c0645be;
case 0x0c0645c0u: goto P_0c0645c0;
case 0x0c0645c2u: goto P_0c0645c2;
case 0x0c0645c4u: goto P_0c0645c4;
case 0x0c0645c6u: goto P_0c0645c6;
case 0x0c0645c8u: goto P_0c0645c8;
case 0x0c0645cau: goto P_0c0645ca;
case 0x0c0645ccu: goto P_0c0645cc;
case 0x0c0645ceu: goto P_0c0645ce;
case 0x0c0645d0u: goto P_0c0645d0;
case 0x0c0645d2u: goto P_0c0645d2;
case 0x0c0645d4u: goto P_0c0645d4;
case 0x0c0645d6u: goto P_0c0645d6;
case 0x0c0645d8u: goto P_0c0645d8;
case 0x0c0645dau: goto P_0c0645da;
case 0x0c0645dcu: goto P_0c0645dc;
case 0x0c0645deu: goto P_0c0645de;
case 0x0c0645e0u: goto P_0c0645e0;
case 0x0c0645e2u: goto P_0c0645e2;
case 0x0c0645e4u: goto P_0c0645e4;
case 0x0c0645e6u: goto P_0c0645e6;
case 0x0c0645e8u: goto P_0c0645e8;
case 0x0c0645eau: goto P_0c0645ea;
case 0x0c0645ecu: goto P_0c0645ec;
case 0x0c0645eeu: goto P_0c0645ee;
case 0x0c0645f0u: goto P_0c0645f0;
case 0x0c0645f2u: goto P_0c0645f2;
case 0x0c064aacu: goto P_0c064aac;
case 0x0c064aaeu: goto P_0c064aae;
case 0x0c064ab0u: goto P_0c064ab0;
case 0x0c064ab2u: goto P_0c064ab2;
case 0x0c064ab4u: goto P_0c064ab4;
case 0x0c064ab6u: goto P_0c064ab6;
case 0x0c064ab8u: goto P_0c064ab8;
case 0x0c064abau: goto P_0c064aba;
case 0x0c064abcu: goto P_0c064abc;
case 0x0c064abeu: goto P_0c064abe;
case 0x0c064ac0u: goto P_0c064ac0;
case 0x0c064ac2u: goto P_0c064ac2;
case 0x0c064ac4u: goto P_0c064ac4;
case 0x0c064ac6u: goto P_0c064ac6;
case 0x0c064ac8u: goto P_0c064ac8;
case 0x0c064acau: goto P_0c064aca;
case 0x0c064accu: goto P_0c064acc;
case 0x0c064aceu: goto P_0c064ace;
case 0x0c064ad0u: goto P_0c064ad0;
case 0x0c064ad2u: goto P_0c064ad2;
case 0x0c064ad4u: goto P_0c064ad4;
case 0x0c064ad6u: goto P_0c064ad6;
case 0x0c064ad8u: goto P_0c064ad8;
case 0x0c064adau: goto P_0c064ada;
case 0x0c064adcu: goto P_0c064adc;
case 0x0c064adeu: goto P_0c064ade;
case 0x0c064ae0u: goto P_0c064ae0;
case 0x0c064ae2u: goto P_0c064ae2;
case 0x0c064ae4u: goto P_0c064ae4;
case 0x0c064ae6u: goto P_0c064ae6;
case 0x0c064ae8u: goto P_0c064ae8;
case 0x0c064aeau: goto P_0c064aea;
case 0x0c064aecu: goto P_0c064aec;
case 0x0c064aeeu: goto P_0c064aee;
case 0x0c064af0u: goto P_0c064af0;
case 0x0c064af2u: goto P_0c064af2;
case 0x0c064af4u: goto P_0c064af4;
case 0x0c064af6u: goto P_0c064af6;
case 0x0c064af8u: goto P_0c064af8;
case 0x0c064afau: goto P_0c064afa;
case 0x0c064afcu: goto P_0c064afc;
case 0x0c064afeu: goto P_0c064afe;
case 0x0c064b00u: goto P_0c064b00;
case 0x0c064b02u: goto P_0c064b02;
case 0x0c064b04u: goto P_0c064b04;
case 0x0c064b06u: goto P_0c064b06;
case 0x0c064b08u: goto P_0c064b08;
case 0x0c064b0au: goto P_0c064b0a;
case 0x0c064b0cu: goto P_0c064b0c;
case 0x0c064b0eu: goto P_0c064b0e;
case 0x0c064b10u: goto P_0c064b10;
case 0x0c064b12u: goto P_0c064b12;
case 0x0c064b14u: goto P_0c064b14;
case 0x0c064b16u: goto P_0c064b16;
case 0x0c064b18u: goto P_0c064b18;
case 0x0c064b1au: goto P_0c064b1a;
case 0x0c064b1cu: goto P_0c064b1c;
case 0x0c064b1eu: goto P_0c064b1e;
case 0x0c064b20u: goto P_0c064b20;
case 0x0c064b22u: goto P_0c064b22;
case 0x0c064b24u: goto P_0c064b24;
case 0x0c064b26u: goto P_0c064b26;
case 0x0c064b28u: goto P_0c064b28;
case 0x0c064b2au: goto P_0c064b2a;
case 0x0c064b2cu: goto P_0c064b2c;
case 0x0c064b2eu: goto P_0c064b2e;
case 0x0c064b30u: goto P_0c064b30;
case 0x0c064b32u: goto P_0c064b32;
case 0x0c064b34u: goto P_0c064b34;
case 0x0c064b36u: goto P_0c064b36;
case 0x0c064b38u: goto P_0c064b38;
case 0x0c064b3au: goto P_0c064b3a;
case 0x0c064b3cu: goto P_0c064b3c;
case 0x0c064b3eu: goto P_0c064b3e;
case 0x0c064b40u: goto P_0c064b40;
case 0x0c064b42u: goto P_0c064b42;
case 0x0c064b44u: goto P_0c064b44;
case 0x0c064b46u: goto P_0c064b46;
case 0x0c064b48u: goto P_0c064b48;
case 0x0c064b4au: goto P_0c064b4a;
case 0x0c064b4cu: goto P_0c064b4c;
case 0x0c064b4eu: goto P_0c064b4e;
case 0x0c064b50u: goto P_0c064b50;
case 0x0c064b52u: goto P_0c064b52;
case 0x0c064b54u: goto P_0c064b54;
case 0x0c064b56u: goto P_0c064b56;
case 0x0c064b58u: goto P_0c064b58;
case 0x0c064b5au: goto P_0c064b5a;
case 0x0c064b5cu: goto P_0c064b5c;
case 0x0c064b5eu: goto P_0c064b5e;
case 0x0c064b60u: goto P_0c064b60;
case 0x0c064b62u: goto P_0c064b62;
case 0x0c064b64u: goto P_0c064b64;
case 0x0c064b66u: goto P_0c064b66;
case 0x0c064b68u: goto P_0c064b68;
case 0x0c064b6au: goto P_0c064b6a;
case 0x0c064b6cu: goto P_0c064b6c;
case 0x0c064b6eu: goto P_0c064b6e;
case 0x0c064b70u: goto P_0c064b70;
case 0x0c064b72u: goto P_0c064b72;
case 0x0c064b74u: goto P_0c064b74;
case 0x0c064b76u: goto P_0c064b76;
case 0x0c064b78u: goto P_0c064b78;
case 0x0c064b7au: goto P_0c064b7a;
case 0x0c064b7cu: goto P_0c064b7c;
case 0x0c064b7eu: goto P_0c064b7e;
case 0x0c064b80u: goto P_0c064b80;
case 0x0c064b82u: goto P_0c064b82;
case 0x0c064b84u: goto P_0c064b84;
case 0x0c064b86u: goto P_0c064b86;
case 0x0c064b88u: goto P_0c064b88;
case 0x0c064b8au: goto P_0c064b8a;
case 0x0c064b8cu: goto P_0c064b8c;
case 0x0c064b8eu: goto P_0c064b8e;
case 0x0c064b90u: goto P_0c064b90;
case 0x0c064b92u: goto P_0c064b92;
case 0x0c064b94u: goto P_0c064b94;
case 0x0c064b96u: goto P_0c064b96;
case 0x0c064b98u: goto P_0c064b98;
case 0x0c064b9au: goto P_0c064b9a;
case 0x0c064b9cu: goto P_0c064b9c;
case 0x0c064b9eu: goto P_0c064b9e;
case 0x0c064ba0u: goto P_0c064ba0;
case 0x0c064ba2u: goto P_0c064ba2;
case 0x0c064ba4u: goto P_0c064ba4;
case 0x0c064ba6u: goto P_0c064ba6;
case 0x0c064ba8u: goto P_0c064ba8;
case 0x0c064baau: goto P_0c064baa;
case 0x0c064bacu: goto P_0c064bac;
case 0x0c064baeu: goto P_0c064bae;
case 0x0c064bb0u: goto P_0c064bb0;
case 0x0c064bb2u: goto P_0c064bb2;
case 0x0c064bb4u: goto P_0c064bb4;
case 0x0c064bb6u: goto P_0c064bb6;
case 0x0c064bb8u: goto P_0c064bb8;
case 0x0c064bbau: goto P_0c064bba;
case 0x0c064bbcu: goto P_0c064bbc;
case 0x0c064bbeu: goto P_0c064bbe;
case 0x0c064bc0u: goto P_0c064bc0;
case 0x0c064bc2u: goto P_0c064bc2;
case 0x0c064bc4u: goto P_0c064bc4;
case 0x0c064bc6u: goto P_0c064bc6;
case 0x0c064bc8u: goto P_0c064bc8;
case 0x0c064bcau: goto P_0c064bca;
case 0x0c064bccu: goto P_0c064bcc;
case 0x0c064bceu: goto P_0c064bce;
case 0x0c064bd0u: goto P_0c064bd0;
case 0x0c064bd2u: goto P_0c064bd2;
case 0x0c064bd4u: goto P_0c064bd4;
case 0x0c064bd6u: goto P_0c064bd6;
case 0x0c064bd8u: goto P_0c064bd8;
case 0x0c064bdau: goto P_0c064bda;
case 0x0c064bdcu: goto P_0c064bdc;
case 0x0c064bdeu: goto P_0c064bde;
case 0x0c064be0u: goto P_0c064be0;
case 0x0c064be2u: goto P_0c064be2;
case 0x0c064be4u: goto P_0c064be4;
case 0x0c064be6u: goto P_0c064be6;
case 0x0c064be8u: goto P_0c064be8;
case 0x0c064beau: goto P_0c064bea;
case 0x0c064becu: goto P_0c064bec;
case 0x0c064beeu: goto P_0c064bee;
case 0x0c064bf0u: goto P_0c064bf0;
case 0x0c064bf2u: goto P_0c064bf2;
case 0x0c064bf4u: goto P_0c064bf4;
case 0x0c064bf6u: goto P_0c064bf6;
case 0x0c064bf8u: goto P_0c064bf8;
case 0x0c064bfau: goto P_0c064bfa;
case 0x0c064bfcu: goto P_0c064bfc;
case 0x0c064bfeu: goto P_0c064bfe;
case 0x0c064c00u: goto P_0c064c00;
case 0x0c064c02u: goto P_0c064c02;
case 0x0c064c04u: goto P_0c064c04;
case 0x0c064c06u: goto P_0c064c06;
case 0x0c064c08u: goto P_0c064c08;
case 0x0c064c0au: goto P_0c064c0a;
case 0x0c064c0cu: goto P_0c064c0c;
case 0x0c064c0eu: goto P_0c064c0e;
case 0x0c064c10u: goto P_0c064c10;
case 0x0c064c12u: goto P_0c064c12;
case 0x0c064c14u: goto P_0c064c14;
case 0x0c064c16u: goto P_0c064c16;
case 0x0c064c18u: goto P_0c064c18;
case 0x0c064c1au: goto P_0c064c1a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0644e8: /* original d283, guest PC 0x0c0644e8 */
if(!s->budget--) { s->failed_pc=0x0c0644e8u; return 0; }
r[2]=read(ram,0x0c0646f8u,4);
goto P_0c0644ea;
P_0c0644ea: /* original 2668, guest PC 0x0c0644ea */
if(!s->budget--) { s->failed_pc=0x0c0644eau; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0644ec;
P_0c0644ec: /* original e307, guest PC 0x0c0644ec */
if(!s->budget--) { s->failed_pc=0x0c0644ecu; return 0; }
r[3]=0x00000007u;
goto P_0c0644ee;
P_0c0644ee: /* original 2439, guest PC 0x0c0644ee */
if(!s->budget--) { s->failed_pc=0x0c0644eeu; return 0; }
r[4]&=r[3];
goto P_0c0644f0;
P_0c0644f0: /* original 4428, guest PC 0x0c0644f0 */
if(!s->budget--) { s->failed_pc=0x0c0644f0u; return 0; }
r[4]<<=16;
goto P_0c0644f2;
P_0c0644f2: /* original 4418, guest PC 0x0c0644f2 */
if(!s->budget--) { s->failed_pc=0x0c0644f2u; return 0; }
r[4]<<=8;
goto P_0c0644f4;
P_0c0644f4: /* original 8d04, guest PC 0x0c0644f4 */
if(!s->budget--) { s->failed_pc=0x0c0644f4u; return 0; }
cond=r[17]&1u;
write(ram,r[2],r[4],4);
if(cond) { goto P_0c064500; }
goto P_0c0644f8;
P_0c0644f6: /* original 2242, guest PC 0x0c0644f6 */
if(!s->budget--) { s->failed_pc=0x0c0644f6u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c0644f8;
P_0c0644f8: /* original d180, guest PC 0x0c0644f8 */
if(!s->budget--) { s->failed_pc=0x0c0644f8u; return 0; }
r[1]=read(ram,0x0c0646fcu,4);
goto P_0c0644fa;
P_0c0644fa: /* original 6022, guest PC 0x0c0644fa */
if(!s->budget--) { s->failed_pc=0x0c0644fau; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0644fc;
P_0c0644fc: /* original 201b, guest PC 0x0c0644fc */
if(!s->budget--) { s->failed_pc=0x0c0644fcu; return 0; }
r[0]|=r[1];
goto P_0c0644fe;
P_0c0644fe: /* original 2202, guest PC 0x0c0644fe */
if(!s->budget--) { s->failed_pc=0x0c0644feu; return 0; }
write(ram,r[2],r[0],4);
goto P_0c064500;
P_0c064500: /* original 2558, guest PC 0x0c064500 */
if(!s->budget--) { s->failed_pc=0x0c064500u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c064502;
P_0c064502: /* original 8904, guest PC 0x0c064502 */
if(!s->budget--) { s->failed_pc=0x0c064502u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06450e; }
goto P_0c064504;
P_0c064504: /* original d37c, guest PC 0x0c064504 */
if(!s->budget--) { s->failed_pc=0x0c064504u; return 0; }
r[3]=read(ram,0x0c0646f8u,4);
goto P_0c064506;
P_0c064506: /* original d27e, guest PC 0x0c064506 */
if(!s->budget--) { s->failed_pc=0x0c064506u; return 0; }
r[2]=read(ram,0x0c064700u,4);
goto P_0c064508;
P_0c064508: /* original 6132, guest PC 0x0c064508 */
if(!s->budget--) { s->failed_pc=0x0c064508u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c06450a;
P_0c06450a: /* original 212b, guest PC 0x0c06450a */
if(!s->budget--) { s->failed_pc=0x0c06450au; return 0; }
r[1]|=r[2];
goto P_0c06450c;
P_0c06450c: /* original 2312, guest PC 0x0c06450c */
if(!s->budget--) { s->failed_pc=0x0c06450cu; return 0; }
write(ram,r[3],r[1],4);
goto P_0c06450e;
P_0c06450e: /* original 000b, guest PC 0x0c06450e */
if(!s->budget--) { s->failed_pc=0x0c06450eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c064510: /* original 0009, guest PC 0x0c064510 */
if(!s->budget--) { s->failed_pc=0x0c064510u; return 0; }
goto P_0c064512;
P_0c064512: /* original d37c, guest PC 0x0c064512 */
if(!s->budget--) { s->failed_pc=0x0c064512u; return 0; }
r[3]=read(ram,0x0c064704u,4);
goto P_0c064514;
P_0c064514: /* original 2348, guest PC 0x0c064514 */
if(!s->budget--) { s->failed_pc=0x0c064514u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c064516;
P_0c064516: /* original 8d09, guest PC 0x0c064516 */
if(!s->budget--) { s->failed_pc=0x0c064516u; return 0; }
cond=r[17]&1u;
r[5]=0x00000001u;
if(cond) { goto P_0c06452c; }
goto P_0c06451a;
P_0c064518: /* original e501, guest PC 0x0c064518 */
if(!s->budget--) { s->failed_pc=0x0c064518u; return 0; }
r[5]=0x00000001u;
goto P_0c06451a;
P_0c06451a: /* original d37b, guest PC 0x0c06451a */
if(!s->budget--) { s->failed_pc=0x0c06451au; return 0; }
r[3]=read(ram,0x0c064708u,4);
goto P_0c06451c;
P_0c06451c: /* original 2348, guest PC 0x0c06451c */
if(!s->budget--) { s->failed_pc=0x0c06451cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c06451e;
P_0c06451e: /* original 8d01, guest PC 0x0c06451e */
if(!s->budget--) { s->failed_pc=0x0c06451eu; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(cond) { goto P_0c064524; }
goto P_0c064522;
P_0c064520: /* original 7501, guest PC 0x0c064520 */
if(!s->budget--) { s->failed_pc=0x0c064520u; return 0; }
r[5]+=0x00000001u;
goto P_0c064522;
P_0c064522: /* original 7501, guest PC 0x0c064522 */
if(!s->budget--) { s->failed_pc=0x0c064522u; return 0; }
r[5]+=0x00000001u;
goto P_0c064524;
P_0c064524: /* original d379, guest PC 0x0c064524 */
if(!s->budget--) { s->failed_pc=0x0c064524u; return 0; }
r[3]=read(ram,0x0c06470cu,4);
goto P_0c064526;
P_0c064526: /* original 2438, guest PC 0x0c064526 */
if(!s->budget--) { s->failed_pc=0x0c064526u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c064528;
P_0c064528: /* original 8b00, guest PC 0x0c064528 */
if(!s->budget--) { s->failed_pc=0x0c064528u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06452c; }
goto P_0c06452a;
P_0c06452a: /* original 7501, guest PC 0x0c06452a */
if(!s->budget--) { s->failed_pc=0x0c06452au; return 0; }
r[5]+=0x00000001u;
goto P_0c06452c;
P_0c06452c: /* original 000b, guest PC 0x0c06452c */
if(!s->budget--) { s->failed_pc=0x0c06452cu; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c06452e: /* original 6053, guest PC 0x0c06452e */
if(!s->budget--) { s->failed_pc=0x0c06452eu; return 0; }
r[0]=r[5];
goto P_0c064530;
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
goto P_0c064594;
P_0c064594: /* original d35e, guest PC 0x0c064594 */
if(!s->budget--) { s->failed_pc=0x0c064594u; return 0; }
r[3]=read(ram,0x0c064710u,4);
goto P_0c064596;
P_0c064596: /* original d260, guest PC 0x0c064596 */
if(!s->budget--) { s->failed_pc=0x0c064596u; return 0; }
r[2]=read(ram,0x0c064718u,4);
goto P_0c064598;
P_0c064598: /* original 2322, guest PC 0x0c064598 */
if(!s->budget--) { s->failed_pc=0x0c064598u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c06459a;
P_0c06459a: /* original d160, guest PC 0x0c06459a */
if(!s->budget--) { s->failed_pc=0x0c06459au; return 0; }
r[1]=read(ram,0x0c06471cu,4);
goto P_0c06459c;
P_0c06459c: /* original d260, guest PC 0x0c06459c */
if(!s->budget--) { s->failed_pc=0x0c06459cu; return 0; }
r[2]=read(ram,0x0c064720u,4);
goto P_0c06459e;
P_0c06459e: /* original 2122, guest PC 0x0c06459e */
if(!s->budget--) { s->failed_pc=0x0c06459eu; return 0; }
write(ram,r[1],r[2],4);
goto P_0c0645a0;
P_0c0645a0: /* original d060, guest PC 0x0c0645a0 */
if(!s->budget--) { s->failed_pc=0x0c0645a0u; return 0; }
r[0]=read(ram,0x0c064724u,4);
goto P_0c0645a2;
P_0c0645a2: /* original e300, guest PC 0x0c0645a2 */
if(!s->budget--) { s->failed_pc=0x0c0645a2u; return 0; }
r[3]=0x00000000u;
goto P_0c0645a4;
P_0c0645a4: /* original 2032, guest PC 0x0c0645a4 */
if(!s->budget--) { s->failed_pc=0x0c0645a4u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c0645a6;
P_0c0645a6: /* original d760, guest PC 0x0c0645a6 */
if(!s->budget--) { s->failed_pc=0x0c0645a6u; return 0; }
r[7]=read(ram,0x0c064728u,4);
goto P_0c0645a8;
P_0c0645a8: /* original d260, guest PC 0x0c0645a8 */
if(!s->budget--) { s->failed_pc=0x0c0645a8u; return 0; }
r[2]=read(ram,0x0c06472cu,4);
goto P_0c0645aa;
P_0c0645aa: /* original 2272, guest PC 0x0c0645aa */
if(!s->budget--) { s->failed_pc=0x0c0645aau; return 0; }
write(ram,r[2],r[7],4);
goto P_0c0645ac;
P_0c0645ac: /* original d660, guest PC 0x0c0645ac */
if(!s->budget--) { s->failed_pc=0x0c0645acu; return 0; }
r[6]=read(ram,0x0c064730u,4);
goto P_0c0645ae;
P_0c0645ae: /* original d361, guest PC 0x0c0645ae */
if(!s->budget--) { s->failed_pc=0x0c0645aeu; return 0; }
r[3]=read(ram,0x0c064734u,4);
goto P_0c0645b0;
P_0c0645b0: /* original 2362, guest PC 0x0c0645b0 */
if(!s->budget--) { s->failed_pc=0x0c0645b0u; return 0; }
write(ram,r[3],r[6],4);
goto P_0c0645b2;
P_0c0645b2: /* original 7110, guest PC 0x0c0645b2 */
if(!s->budget--) { s->failed_pc=0x0c0645b2u; return 0; }
r[1]+=0x00000010u;
goto P_0c0645b4;
P_0c0645b4: /* original d560, guest PC 0x0c0645b4 */
if(!s->budget--) { s->failed_pc=0x0c0645b4u; return 0; }
r[5]=read(ram,0x0c064738u,4);
goto P_0c0645b6;
P_0c0645b6: /* original 2152, guest PC 0x0c0645b6 */
if(!s->budget--) { s->failed_pc=0x0c0645b6u; return 0; }
write(ram,r[1],r[5],4);
goto P_0c0645b8;
P_0c0645b8: /* original d460, guest PC 0x0c0645b8 */
if(!s->budget--) { s->failed_pc=0x0c0645b8u; return 0; }
r[4]=read(ram,0x0c06473cu,4);
goto P_0c0645ba;
P_0c0645ba: /* original 720c, guest PC 0x0c0645ba */
if(!s->budget--) { s->failed_pc=0x0c0645bau; return 0; }
r[2]+=0x0000000cu;
goto P_0c0645bc;
P_0c0645bc: /* original 2242, guest PC 0x0c0645bc */
if(!s->budget--) { s->failed_pc=0x0c0645bcu; return 0; }
write(ram,r[2],r[4],4);
goto P_0c0645be;
P_0c0645be: /* original 730c, guest PC 0x0c0645be */
if(!s->budget--) { s->failed_pc=0x0c0645beu; return 0; }
r[3]+=0x0000000cu;
goto P_0c0645c0;
P_0c0645c0: /* original d15f, guest PC 0x0c0645c0 */
if(!s->budget--) { s->failed_pc=0x0c0645c0u; return 0; }
r[1]=read(ram,0x0c064740u,4);
goto P_0c0645c2;
P_0c0645c2: /* original 2312, guest PC 0x0c0645c2 */
if(!s->budget--) { s->failed_pc=0x0c0645c2u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0645c4;
P_0c0645c4: /* original d05f, guest PC 0x0c0645c4 */
if(!s->budget--) { s->failed_pc=0x0c0645c4u; return 0; }
r[0]=read(ram,0x0c064744u,4);
goto P_0c0645c6;
P_0c0645c6: /* original 2072, guest PC 0x0c0645c6 */
if(!s->budget--) { s->failed_pc=0x0c0645c6u; return 0; }
write(ram,r[0],r[7],4);
goto P_0c0645c8;
P_0c0645c8: /* original 720c, guest PC 0x0c0645c8 */
if(!s->budget--) { s->failed_pc=0x0c0645c8u; return 0; }
r[2]+=0x0000000cu;
goto P_0c0645ca;
P_0c0645ca: /* original 2252, guest PC 0x0c0645ca */
if(!s->budget--) { s->failed_pc=0x0c0645cau; return 0; }
write(ram,r[2],r[5],4);
goto P_0c0645cc;
P_0c0645cc: /* original 730c, guest PC 0x0c0645cc */
if(!s->budget--) { s->failed_pc=0x0c0645ccu; return 0; }
r[3]+=0x0000000cu;
goto P_0c0645ce;
P_0c0645ce: /* original 2342, guest PC 0x0c0645ce */
if(!s->budget--) { s->failed_pc=0x0c0645ceu; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0645d0;
P_0c0645d0: /* original d15d, guest PC 0x0c0645d0 */
if(!s->budget--) { s->failed_pc=0x0c0645d0u; return 0; }
r[1]=read(ram,0x0c064748u,4);
goto P_0c0645d2;
P_0c0645d2: /* original d25e, guest PC 0x0c0645d2 */
if(!s->budget--) { s->failed_pc=0x0c0645d2u; return 0; }
r[2]=read(ram,0x0c06474cu,4);
goto P_0c0645d4;
P_0c0645d4: /* original 2122, guest PC 0x0c0645d4 */
if(!s->budget--) { s->failed_pc=0x0c0645d4u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c0645d6;
P_0c0645d6: /* original d05e, guest PC 0x0c0645d6 */
if(!s->budget--) { s->failed_pc=0x0c0645d6u; return 0; }
r[0]=read(ram,0x0c064750u,4);
goto P_0c0645d8;
P_0c0645d8: /* original 2062, guest PC 0x0c0645d8 */
if(!s->budget--) { s->failed_pc=0x0c0645d8u; return 0; }
write(ram,r[0],r[6],4);
goto P_0c0645da;
P_0c0645da: /* original 730c, guest PC 0x0c0645da */
if(!s->budget--) { s->failed_pc=0x0c0645dau; return 0; }
r[3]+=0x0000000cu;
goto P_0c0645dc;
P_0c0645dc: /* original 2352, guest PC 0x0c0645dc */
if(!s->budget--) { s->failed_pc=0x0c0645dcu; return 0; }
write(ram,r[3],r[5],4);
goto P_0c0645de;
P_0c0645de: /* original d25d, guest PC 0x0c0645de */
if(!s->budget--) { s->failed_pc=0x0c0645deu; return 0; }
r[2]=read(ram,0x0c064754u,4);
goto P_0c0645e0;
P_0c0645e0: /* original 2242, guest PC 0x0c0645e0 */
if(!s->budget--) { s->failed_pc=0x0c0645e0u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c0645e2;
P_0c0645e2: /* original 71e8, guest PC 0x0c0645e2 */
if(!s->budget--) { s->failed_pc=0x0c0645e2u; return 0; }
r[1]+=0xffffffe8u;
goto P_0c0645e4;
P_0c0645e4: /* original 6312, guest PC 0x0c0645e4 */
if(!s->budget--) { s->failed_pc=0x0c0645e4u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c0645e6;
P_0c0645e6: /* original d05c, guest PC 0x0c0645e6 */
if(!s->budget--) { s->failed_pc=0x0c0645e6u; return 0; }
r[0]=read(ram,0x0c064758u,4);
goto P_0c0645e8;
P_0c0645e8: /* original 2032, guest PC 0x0c0645e8 */
if(!s->budget--) { s->failed_pc=0x0c0645e8u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c0645ea;
P_0c0645ea: /* original d247, guest PC 0x0c0645ea */
if(!s->budget--) { s->failed_pc=0x0c0645eau; return 0; }
r[2]=read(ram,0x0c064708u,4);
goto P_0c0645ec;
P_0c0645ec: /* original d342, guest PC 0x0c0645ec */
if(!s->budget--) { s->failed_pc=0x0c0645ecu; return 0; }
r[3]=read(ram,0x0c0646f8u,4);
goto P_0c0645ee;
P_0c0645ee: /* original 2322, guest PC 0x0c0645ee */
if(!s->budget--) { s->failed_pc=0x0c0645eeu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0645f0;
P_0c0645f0: /* original 000b, guest PC 0x0c0645f0 */
if(!s->budget--) { s->failed_pc=0x0c0645f0u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c0645f2: /* original e000, guest PC 0x0c0645f2 */
if(!s->budget--) { s->failed_pc=0x0c0645f2u; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c0645f4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0645f4u; return 0; } return 1;
P_0c064aac: /* original 2fe6, guest PC 0x0c064aac */
if(!s->budget--) { s->failed_pc=0x0c064aacu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c064aae;
P_0c064aae: /* original 2fd6, guest PC 0x0c064aae */
if(!s->budget--) { s->failed_pc=0x0c064aaeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c064ab0;
P_0c064ab0: /* original 2fc6, guest PC 0x0c064ab0 */
if(!s->budget--) { s->failed_pc=0x0c064ab0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c064ab2;
P_0c064ab2: /* original ec00, guest PC 0x0c064ab2 */
if(!s->budget--) { s->failed_pc=0x0c064ab2u; return 0; }
r[12]=0x00000000u;
goto P_0c064ab4;
P_0c064ab4: /* original 2fb6, guest PC 0x0c064ab4 */
if(!s->budget--) { s->failed_pc=0x0c064ab4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c064ab6;
P_0c064ab6: /* original 2fa6, guest PC 0x0c064ab6 */
if(!s->budget--) { s->failed_pc=0x0c064ab6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c064ab8;
P_0c064ab8: /* original 4f22, guest PC 0x0c064ab8 */
if(!s->budget--) { s->failed_pc=0x0c064ab8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c064aba;
P_0c064aba: /* original 7ff0, guest PC 0x0c064aba */
if(!s->budget--) { s->failed_pc=0x0c064abau; return 0; }
r[15]+=0xfffffff0u;
goto P_0c064abc;
P_0c064abc: /* original 6342, guest PC 0x0c064abc */
if(!s->budget--) { s->failed_pc=0x0c064abcu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c064abe;
P_0c064abe: /* original 65f3, guest PC 0x0c064abe */
if(!s->budget--) { s->failed_pc=0x0c064abeu; return 0; }
r[5]=r[15];
goto P_0c064ac0;
P_0c064ac0: /* original 7504, guest PC 0x0c064ac0 */
if(!s->budget--) { s->failed_pc=0x0c064ac0u; return 0; }
r[5]+=0x00000004u;
goto P_0c064ac2;
P_0c064ac2: /* original 6d53, guest PC 0x0c064ac2 */
if(!s->budget--) { s->failed_pc=0x0c064ac2u; return 0; }
r[13]=r[5];
goto P_0c064ac4;
P_0c064ac4: /* original 2d32, guest PC 0x0c064ac4 */
if(!s->budget--) { s->failed_pc=0x0c064ac4u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c064ac6;
P_0c064ac6: /* original 6ad3, guest PC 0x0c064ac6 */
if(!s->budget--) { s->failed_pc=0x0c064ac6u; return 0; }
r[10]=r[13];
goto P_0c064ac8;
P_0c064ac8: /* original 5241, guest PC 0x0c064ac8 */
if(!s->budget--) { s->failed_pc=0x0c064ac8u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c064aca;
P_0c064aca: /* original 6bd3, guest PC 0x0c064aca */
if(!s->budget--) { s->failed_pc=0x0c064acau; return 0; }
r[11]=r[13];
goto P_0c064acc;
P_0c064acc: /* original 7a04, guest PC 0x0c064acc */
if(!s->budget--) { s->failed_pc=0x0c064accu; return 0; }
r[10]+=0x00000004u;
goto P_0c064ace;
P_0c064ace: /* original 7b08, guest PC 0x0c064ace */
if(!s->budget--) { s->failed_pc=0x0c064aceu; return 0; }
r[11]+=0x00000008u;
goto P_0c064ad0;
P_0c064ad0: /* original 2a22, guest PC 0x0c064ad0 */
if(!s->budget--) { s->failed_pc=0x0c064ad0u; return 0; }
write(ram,r[10],r[2],4);
goto P_0c064ad2;
P_0c064ad2: /* original 5342, guest PC 0x0c064ad2 */
if(!s->budget--) { s->failed_pc=0x0c064ad2u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c064ad4;
P_0c064ad4: /* original d2a8, guest PC 0x0c064ad4 */
if(!s->budget--) { s->failed_pc=0x0c064ad4u; return 0; }
r[2]=read(ram,0x0c064d78u,4);
goto P_0c064ad6;
P_0c064ad6: /* original 2b32, guest PC 0x0c064ad6 */
if(!s->budget--) { s->failed_pc=0x0c064ad6u; return 0; }
write(ram,r[11],r[3],4);
goto P_0c064ad8;
P_0c064ad8: /* original 6e22, guest PC 0x0c064ad8 */
if(!s->budget--) { s->failed_pc=0x0c064ad8u; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c064ada;
P_0c064ada: /* original d3a8, guest PC 0x0c064ada */
if(!s->budget--) { s->failed_pc=0x0c064adau; return 0; }
r[3]=read(ram,0x0c064d7cu,4);
goto P_0c064adc;
P_0c064adc: /* original 6432, guest PC 0x0c064adc */
if(!s->budget--) { s->failed_pc=0x0c064adcu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c064ade;
P_0c064ade: /* original d1a8, guest PC 0x0c064ade */
if(!s->budget--) { s->failed_pc=0x0c064adeu; return 0; }
r[1]=read(ram,0x0c064d80u,4);
goto P_0c064ae0;
P_0c064ae0: /* original 6512, guest PC 0x0c064ae0 */
if(!s->budget--) { s->failed_pc=0x0c064ae0u; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c064ae2;
P_0c064ae2: /* original d0a8, guest PC 0x0c064ae2 */
if(!s->budget--) { s->failed_pc=0x0c064ae2u; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064ae4;
P_0c064ae4: /* original 62c3, guest PC 0x0c064ae4 */
if(!s->budget--) { s->failed_pc=0x0c064ae4u; return 0; }
r[2]=r[12];
goto P_0c064ae6;
P_0c064ae6: /* original 7c01, guest PC 0x0c064ae6 */
if(!s->budget--) { s->failed_pc=0x0c064ae6u; return 0; }
r[12]+=0x00000001u;
goto P_0c064ae8;
P_0c064ae8: /* original 4208, guest PC 0x0c064ae8 */
if(!s->budget--) { s->failed_pc=0x0c064ae8u; return 0; }
r[2]<<=2;
goto P_0c064aea;
P_0c064aea: /* original 02e6, guest PC 0x0c064aea */
if(!s->budget--) { s->failed_pc=0x0c064aeau; return 0; }
write(ram,r[2]+r[0],r[14],4);
goto P_0c064aec;
P_0c064aec: /* original 63c3, guest PC 0x0c064aec */
if(!s->budget--) { s->failed_pc=0x0c064aecu; return 0; }
r[3]=r[12];
goto P_0c064aee;
P_0c064aee: /* original 7c01, guest PC 0x0c064aee */
if(!s->budget--) { s->failed_pc=0x0c064aeeu; return 0; }
r[12]+=0x00000001u;
goto P_0c064af0;
P_0c064af0: /* original 4308, guest PC 0x0c064af0 */
if(!s->budget--) { s->failed_pc=0x0c064af0u; return 0; }
r[3]<<=2;
goto P_0c064af2;
P_0c064af2: /* original 0346, guest PC 0x0c064af2 */
if(!s->budget--) { s->failed_pc=0x0c064af2u; return 0; }
write(ram,r[3]+r[0],r[4],4);
goto P_0c064af4;
P_0c064af4: /* original 62c3, guest PC 0x0c064af4 */
if(!s->budget--) { s->failed_pc=0x0c064af4u; return 0; }
r[2]=r[12];
goto P_0c064af6;
P_0c064af6: /* original 7c01, guest PC 0x0c064af6 */
if(!s->budget--) { s->failed_pc=0x0c064af6u; return 0; }
r[12]+=0x00000001u;
goto P_0c064af8;
P_0c064af8: /* original 4208, guest PC 0x0c064af8 */
if(!s->budget--) { s->failed_pc=0x0c064af8u; return 0; }
r[2]<<=2;
goto P_0c064afa;
P_0c064afa: /* original 0256, guest PC 0x0c064afa */
if(!s->budget--) { s->failed_pc=0x0c064afau; return 0; }
write(ram,r[2]+r[0],r[5],4);
goto P_0c064afc;
P_0c064afc: /* original 62d2, guest PC 0x0c064afc */
if(!s->budget--) { s->failed_pc=0x0c064afcu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c064afe;
P_0c064afe: /* original 63c3, guest PC 0x0c064afe */
if(!s->budget--) { s->failed_pc=0x0c064afeu; return 0; }
r[3]=r[12];
goto P_0c064b00;
P_0c064b00: /* original 5221, guest PC 0x0c064b00 */
if(!s->budget--) { s->failed_pc=0x0c064b00u; return 0; }
r[2]=read(ram,r[2]+4,4);
goto P_0c064b02;
P_0c064b02: /* original 7c01, guest PC 0x0c064b02 */
if(!s->budget--) { s->failed_pc=0x0c064b02u; return 0; }
r[12]+=0x00000001u;
goto P_0c064b04;
P_0c064b04: /* original 4308, guest PC 0x0c064b04 */
if(!s->budget--) { s->failed_pc=0x0c064b04u; return 0; }
r[3]<<=2;
goto P_0c064b06;
P_0c064b06: /* original 0326, guest PC 0x0c064b06 */
if(!s->budget--) { s->failed_pc=0x0c064b06u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064b08;
P_0c064b08: /* original 62d2, guest PC 0x0c064b08 */
if(!s->budget--) { s->failed_pc=0x0c064b08u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c064b0a;
P_0c064b0a: /* original 63c3, guest PC 0x0c064b0a */
if(!s->budget--) { s->failed_pc=0x0c064b0au; return 0; }
r[3]=r[12];
goto P_0c064b0c;
P_0c064b0c: /* original 5222, guest PC 0x0c064b0c */
if(!s->budget--) { s->failed_pc=0x0c064b0cu; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c064b0e;
P_0c064b0e: /* original 7c01, guest PC 0x0c064b0e */
if(!s->budget--) { s->failed_pc=0x0c064b0eu; return 0; }
r[12]+=0x00000001u;
goto P_0c064b10;
P_0c064b10: /* original 4308, guest PC 0x0c064b10 */
if(!s->budget--) { s->failed_pc=0x0c064b10u; return 0; }
r[3]<<=2;
goto P_0c064b12;
P_0c064b12: /* original 0326, guest PC 0x0c064b12 */
if(!s->budget--) { s->failed_pc=0x0c064b12u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064b14;
P_0c064b14: /* original 62d2, guest PC 0x0c064b14 */
if(!s->budget--) { s->failed_pc=0x0c064b14u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c064b16;
P_0c064b16: /* original 63c3, guest PC 0x0c064b16 */
if(!s->budget--) { s->failed_pc=0x0c064b16u; return 0; }
r[3]=r[12];
goto P_0c064b18;
P_0c064b18: /* original 5223, guest PC 0x0c064b18 */
if(!s->budget--) { s->failed_pc=0x0c064b18u; return 0; }
r[2]=read(ram,r[2]+12,4);
goto P_0c064b1a;
P_0c064b1a: /* original 7c01, guest PC 0x0c064b1a */
if(!s->budget--) { s->failed_pc=0x0c064b1au; return 0; }
r[12]+=0x00000001u;
goto P_0c064b1c;
P_0c064b1c: /* original 4308, guest PC 0x0c064b1c */
if(!s->budget--) { s->failed_pc=0x0c064b1cu; return 0; }
r[3]<<=2;
goto P_0c064b1e;
P_0c064b1e: /* original 0326, guest PC 0x0c064b1e */
if(!s->budget--) { s->failed_pc=0x0c064b1eu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064b20;
P_0c064b20: /* original 67d2, guest PC 0x0c064b20 */
if(!s->budget--) { s->failed_pc=0x0c064b20u; return 0; }
tmp=read(ram,r[13],4);
r[7]=tmp;
goto P_0c064b22;
P_0c064b22: /* original 2f72, guest PC 0x0c064b22 */
if(!s->budget--) { s->failed_pc=0x0c064b22u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c064b24;
P_0c064b24: /* original 5775, guest PC 0x0c064b24 */
if(!s->budget--) { s->failed_pc=0x0c064b24u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c064b26;
P_0c064b26: /* original 66f2, guest PC 0x0c064b26 */
if(!s->budget--) { s->failed_pc=0x0c064b26u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c064b28;
P_0c064b28: /* original 5664, guest PC 0x0c064b28 */
if(!s->budget--) { s->failed_pc=0x0c064b28u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c064b2a;
P_0c064b2a: /* original 65c3, guest PC 0x0c064b2a */
if(!s->budget--) { s->failed_pc=0x0c064b2au; return 0; }
r[5]=r[12];
goto P_0c064b2c;
P_0c064b2c: /* original bd24, guest PC 0x0c064b2c */
if(!s->budget--) { s->failed_pc=0x0c064b2cu; return 0; }
target=code_base|0x0c064578u; r[16]=code_base|0x0c064b30u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064b30u) { target=s->pc; goto dispatch; }
goto P_0c064b30;
P_0c064b2e: /* original 64e3, guest PC 0x0c064b2e */
if(!s->budget--) { s->failed_pc=0x0c064b2eu; return 0; }
r[4]=r[14];
goto P_0c064b30;
P_0c064b30: /* original 63d2, guest PC 0x0c064b30 */
if(!s->budget--) { s->failed_pc=0x0c064b30u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c064b32;
P_0c064b32: /* original 6c03, guest PC 0x0c064b32 */
if(!s->budget--) { s->failed_pc=0x0c064b32u; return 0; }
r[12]=r[0];
goto P_0c064b34;
P_0c064b34: /* original 5136, guest PC 0x0c064b34 */
if(!s->budget--) { s->failed_pc=0x0c064b34u; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c064b36;
P_0c064b36: /* original 62c3, guest PC 0x0c064b36 */
if(!s->budget--) { s->failed_pc=0x0c064b36u; return 0; }
r[2]=r[12];
goto P_0c064b38;
P_0c064b38: /* original d092, guest PC 0x0c064b38 */
if(!s->budget--) { s->failed_pc=0x0c064b38u; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064b3a;
P_0c064b3a: /* original 7c01, guest PC 0x0c064b3a */
if(!s->budget--) { s->failed_pc=0x0c064b3au; return 0; }
r[12]+=0x00000001u;
goto P_0c064b3c;
P_0c064b3c: /* original 4208, guest PC 0x0c064b3c */
if(!s->budget--) { s->failed_pc=0x0c064b3cu; return 0; }
r[2]<<=2;
goto P_0c064b3e;
P_0c064b3e: /* original 0216, guest PC 0x0c064b3e */
if(!s->budget--) { s->failed_pc=0x0c064b3eu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064b40;
P_0c064b40: /* original 66d2, guest PC 0x0c064b40 */
if(!s->budget--) { s->failed_pc=0x0c064b40u; return 0; }
tmp=read(ram,r[13],4);
r[6]=tmp;
goto P_0c064b42;
P_0c064b42: /* original 65c3, guest PC 0x0c064b42 */
if(!s->budget--) { s->failed_pc=0x0c064b42u; return 0; }
r[5]=r[12];
goto P_0c064b44;
P_0c064b44: /* original 5667, guest PC 0x0c064b44 */
if(!s->budget--) { s->failed_pc=0x0c064b44u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c064b46;
P_0c064b46: /* original bcf3, guest PC 0x0c064b46 */
if(!s->budget--) { s->failed_pc=0x0c064b46u; return 0; }
target=code_base|0x0c064530u; r[16]=code_base|0x0c064b4au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064b4au) { target=s->pc; goto dispatch; }
goto P_0c064b4a;
P_0c064b48: /* original 64e3, guest PC 0x0c064b48 */
if(!s->budget--) { s->failed_pc=0x0c064b48u; return 0; }
r[4]=r[14];
goto P_0c064b4a;
P_0c064b4a: /* original 6c03, guest PC 0x0c064b4a */
if(!s->budget--) { s->failed_pc=0x0c064b4au; return 0; }
r[12]=r[0];
goto P_0c064b4c;
P_0c064b4c: /* original 61a2, guest PC 0x0c064b4c */
if(!s->budget--) { s->failed_pc=0x0c064b4cu; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c064b4e;
P_0c064b4e: /* original 62c3, guest PC 0x0c064b4e */
if(!s->budget--) { s->failed_pc=0x0c064b4eu; return 0; }
r[2]=r[12];
goto P_0c064b50;
P_0c064b50: /* original d08c, guest PC 0x0c064b50 */
if(!s->budget--) { s->failed_pc=0x0c064b50u; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064b52;
P_0c064b52: /* original 7c01, guest PC 0x0c064b52 */
if(!s->budget--) { s->failed_pc=0x0c064b52u; return 0; }
r[12]+=0x00000001u;
goto P_0c064b54;
P_0c064b54: /* original 5311, guest PC 0x0c064b54 */
if(!s->budget--) { s->failed_pc=0x0c064b54u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c064b56;
P_0c064b56: /* original 4208, guest PC 0x0c064b56 */
if(!s->budget--) { s->failed_pc=0x0c064b56u; return 0; }
r[2]<<=2;
goto P_0c064b58;
P_0c064b58: /* original 0236, guest PC 0x0c064b58 */
if(!s->budget--) { s->failed_pc=0x0c064b58u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064b5a;
P_0c064b5a: /* original 62c3, guest PC 0x0c064b5a */
if(!s->budget--) { s->failed_pc=0x0c064b5au; return 0; }
r[2]=r[12];
goto P_0c064b5c;
P_0c064b5c: /* original 61a2, guest PC 0x0c064b5c */
if(!s->budget--) { s->failed_pc=0x0c064b5cu; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c064b5e;
P_0c064b5e: /* original 7c01, guest PC 0x0c064b5e */
if(!s->budget--) { s->failed_pc=0x0c064b5eu; return 0; }
r[12]+=0x00000001u;
goto P_0c064b60;
P_0c064b60: /* original 5312, guest PC 0x0c064b60 */
if(!s->budget--) { s->failed_pc=0x0c064b60u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c064b62;
P_0c064b62: /* original 4208, guest PC 0x0c064b62 */
if(!s->budget--) { s->failed_pc=0x0c064b62u; return 0; }
r[2]<<=2;
goto P_0c064b64;
P_0c064b64: /* original 0236, guest PC 0x0c064b64 */
if(!s->budget--) { s->failed_pc=0x0c064b64u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064b66;
P_0c064b66: /* original 62c3, guest PC 0x0c064b66 */
if(!s->budget--) { s->failed_pc=0x0c064b66u; return 0; }
r[2]=r[12];
goto P_0c064b68;
P_0c064b68: /* original 61a2, guest PC 0x0c064b68 */
if(!s->budget--) { s->failed_pc=0x0c064b68u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c064b6a;
P_0c064b6a: /* original 7c01, guest PC 0x0c064b6a */
if(!s->budget--) { s->failed_pc=0x0c064b6au; return 0; }
r[12]+=0x00000001u;
goto P_0c064b6c;
P_0c064b6c: /* original 5313, guest PC 0x0c064b6c */
if(!s->budget--) { s->failed_pc=0x0c064b6cu; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c064b6e;
P_0c064b6e: /* original 4208, guest PC 0x0c064b6e */
if(!s->budget--) { s->failed_pc=0x0c064b6eu; return 0; }
r[2]<<=2;
goto P_0c064b70;
P_0c064b70: /* original 0236, guest PC 0x0c064b70 */
if(!s->budget--) { s->failed_pc=0x0c064b70u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064b72;
P_0c064b72: /* original 65c3, guest PC 0x0c064b72 */
if(!s->budget--) { s->failed_pc=0x0c064b72u; return 0; }
r[5]=r[12];
goto P_0c064b74;
P_0c064b74: /* original 67a2, guest PC 0x0c064b74 */
if(!s->budget--) { s->failed_pc=0x0c064b74u; return 0; }
tmp=read(ram,r[10],4);
r[7]=tmp;
goto P_0c064b76;
P_0c064b76: /* original 2f72, guest PC 0x0c064b76 */
if(!s->budget--) { s->failed_pc=0x0c064b76u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c064b78;
P_0c064b78: /* original 5775, guest PC 0x0c064b78 */
if(!s->budget--) { s->failed_pc=0x0c064b78u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c064b7a;
P_0c064b7a: /* original 66f2, guest PC 0x0c064b7a */
if(!s->budget--) { s->failed_pc=0x0c064b7au; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c064b7c;
P_0c064b7c: /* original 5664, guest PC 0x0c064b7c */
if(!s->budget--) { s->failed_pc=0x0c064b7cu; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c064b7e;
P_0c064b7e: /* original bcfb, guest PC 0x0c064b7e */
if(!s->budget--) { s->failed_pc=0x0c064b7eu; return 0; }
target=code_base|0x0c064578u; r[16]=code_base|0x0c064b82u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064b82u) { target=s->pc; goto dispatch; }
goto P_0c064b82;
P_0c064b80: /* original 64e3, guest PC 0x0c064b80 */
if(!s->budget--) { s->failed_pc=0x0c064b80u; return 0; }
r[4]=r[14];
goto P_0c064b82;
P_0c064b82: /* original 6c03, guest PC 0x0c064b82 */
if(!s->budget--) { s->failed_pc=0x0c064b82u; return 0; }
r[12]=r[0];
goto P_0c064b84;
P_0c064b84: /* original 63a2, guest PC 0x0c064b84 */
if(!s->budget--) { s->failed_pc=0x0c064b84u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c064b86;
P_0c064b86: /* original 62c3, guest PC 0x0c064b86 */
if(!s->budget--) { s->failed_pc=0x0c064b86u; return 0; }
r[2]=r[12];
goto P_0c064b88;
P_0c064b88: /* original d07e, guest PC 0x0c064b88 */
if(!s->budget--) { s->failed_pc=0x0c064b88u; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064b8a;
P_0c064b8a: /* original 7c01, guest PC 0x0c064b8a */
if(!s->budget--) { s->failed_pc=0x0c064b8au; return 0; }
r[12]+=0x00000001u;
goto P_0c064b8c;
P_0c064b8c: /* original 5136, guest PC 0x0c064b8c */
if(!s->budget--) { s->failed_pc=0x0c064b8cu; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c064b8e;
P_0c064b8e: /* original 4208, guest PC 0x0c064b8e */
if(!s->budget--) { s->failed_pc=0x0c064b8eu; return 0; }
r[2]<<=2;
goto P_0c064b90;
P_0c064b90: /* original 0216, guest PC 0x0c064b90 */
if(!s->budget--) { s->failed_pc=0x0c064b90u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064b92;
P_0c064b92: /* original 65c3, guest PC 0x0c064b92 */
if(!s->budget--) { s->failed_pc=0x0c064b92u; return 0; }
r[5]=r[12];
goto P_0c064b94;
P_0c064b94: /* original 66a2, guest PC 0x0c064b94 */
if(!s->budget--) { s->failed_pc=0x0c064b94u; return 0; }
tmp=read(ram,r[10],4);
r[6]=tmp;
goto P_0c064b96;
P_0c064b96: /* original 5667, guest PC 0x0c064b96 */
if(!s->budget--) { s->failed_pc=0x0c064b96u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c064b98;
P_0c064b98: /* original bcca, guest PC 0x0c064b98 */
if(!s->budget--) { s->failed_pc=0x0c064b98u; return 0; }
target=code_base|0x0c064530u; r[16]=code_base|0x0c064b9cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064b9cu) { target=s->pc; goto dispatch; }
goto P_0c064b9c;
P_0c064b9a: /* original 64e3, guest PC 0x0c064b9a */
if(!s->budget--) { s->failed_pc=0x0c064b9au; return 0; }
r[4]=r[14];
goto P_0c064b9c;
P_0c064b9c: /* original 61b2, guest PC 0x0c064b9c */
if(!s->budget--) { s->failed_pc=0x0c064b9cu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c064b9e;
P_0c064b9e: /* original 6c03, guest PC 0x0c064b9e */
if(!s->budget--) { s->failed_pc=0x0c064b9eu; return 0; }
r[12]=r[0];
goto P_0c064ba0;
P_0c064ba0: /* original 5311, guest PC 0x0c064ba0 */
if(!s->budget--) { s->failed_pc=0x0c064ba0u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c064ba2;
P_0c064ba2: /* original 62c3, guest PC 0x0c064ba2 */
if(!s->budget--) { s->failed_pc=0x0c064ba2u; return 0; }
r[2]=r[12];
goto P_0c064ba4;
P_0c064ba4: /* original d077, guest PC 0x0c064ba4 */
if(!s->budget--) { s->failed_pc=0x0c064ba4u; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064ba6;
P_0c064ba6: /* original 7c01, guest PC 0x0c064ba6 */
if(!s->budget--) { s->failed_pc=0x0c064ba6u; return 0; }
r[12]+=0x00000001u;
goto P_0c064ba8;
P_0c064ba8: /* original 4208, guest PC 0x0c064ba8 */
if(!s->budget--) { s->failed_pc=0x0c064ba8u; return 0; }
r[2]<<=2;
goto P_0c064baa;
P_0c064baa: /* original 0236, guest PC 0x0c064baa */
if(!s->budget--) { s->failed_pc=0x0c064baau; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064bac;
P_0c064bac: /* original 61b2, guest PC 0x0c064bac */
if(!s->budget--) { s->failed_pc=0x0c064bacu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c064bae;
P_0c064bae: /* original 62c3, guest PC 0x0c064bae */
if(!s->budget--) { s->failed_pc=0x0c064baeu; return 0; }
r[2]=r[12];
goto P_0c064bb0;
P_0c064bb0: /* original 5312, guest PC 0x0c064bb0 */
if(!s->budget--) { s->failed_pc=0x0c064bb0u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c064bb2;
P_0c064bb2: /* original 7c01, guest PC 0x0c064bb2 */
if(!s->budget--) { s->failed_pc=0x0c064bb2u; return 0; }
r[12]+=0x00000001u;
goto P_0c064bb4;
P_0c064bb4: /* original 4208, guest PC 0x0c064bb4 */
if(!s->budget--) { s->failed_pc=0x0c064bb4u; return 0; }
r[2]<<=2;
goto P_0c064bb6;
P_0c064bb6: /* original 0236, guest PC 0x0c064bb6 */
if(!s->budget--) { s->failed_pc=0x0c064bb6u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064bb8;
P_0c064bb8: /* original 61b2, guest PC 0x0c064bb8 */
if(!s->budget--) { s->failed_pc=0x0c064bb8u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c064bba;
P_0c064bba: /* original 62c3, guest PC 0x0c064bba */
if(!s->budget--) { s->failed_pc=0x0c064bbau; return 0; }
r[2]=r[12];
goto P_0c064bbc;
P_0c064bbc: /* original 5313, guest PC 0x0c064bbc */
if(!s->budget--) { s->failed_pc=0x0c064bbcu; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c064bbe;
P_0c064bbe: /* original 7c01, guest PC 0x0c064bbe */
if(!s->budget--) { s->failed_pc=0x0c064bbeu; return 0; }
r[12]+=0x00000001u;
goto P_0c064bc0;
P_0c064bc0: /* original 4208, guest PC 0x0c064bc0 */
if(!s->budget--) { s->failed_pc=0x0c064bc0u; return 0; }
r[2]<<=2;
goto P_0c064bc2;
P_0c064bc2: /* original 0236, guest PC 0x0c064bc2 */
if(!s->budget--) { s->failed_pc=0x0c064bc2u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064bc4;
P_0c064bc4: /* original 67b2, guest PC 0x0c064bc4 */
if(!s->budget--) { s->failed_pc=0x0c064bc4u; return 0; }
tmp=read(ram,r[11],4);
r[7]=tmp;
goto P_0c064bc6;
P_0c064bc6: /* original 65c3, guest PC 0x0c064bc6 */
if(!s->budget--) { s->failed_pc=0x0c064bc6u; return 0; }
r[5]=r[12];
goto P_0c064bc8;
P_0c064bc8: /* original 2f72, guest PC 0x0c064bc8 */
if(!s->budget--) { s->failed_pc=0x0c064bc8u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c064bca;
P_0c064bca: /* original 5775, guest PC 0x0c064bca */
if(!s->budget--) { s->failed_pc=0x0c064bcau; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c064bcc;
P_0c064bcc: /* original 66f2, guest PC 0x0c064bcc */
if(!s->budget--) { s->failed_pc=0x0c064bccu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c064bce;
P_0c064bce: /* original 5664, guest PC 0x0c064bce */
if(!s->budget--) { s->failed_pc=0x0c064bceu; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c064bd0;
P_0c064bd0: /* original bcd2, guest PC 0x0c064bd0 */
if(!s->budget--) { s->failed_pc=0x0c064bd0u; return 0; }
target=code_base|0x0c064578u; r[16]=code_base|0x0c064bd4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064bd4u) { target=s->pc; goto dispatch; }
goto P_0c064bd4;
P_0c064bd2: /* original 64e3, guest PC 0x0c064bd2 */
if(!s->budget--) { s->failed_pc=0x0c064bd2u; return 0; }
r[4]=r[14];
goto P_0c064bd4;
P_0c064bd4: /* original 63b2, guest PC 0x0c064bd4 */
if(!s->budget--) { s->failed_pc=0x0c064bd4u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c064bd6;
P_0c064bd6: /* original 6c03, guest PC 0x0c064bd6 */
if(!s->budget--) { s->failed_pc=0x0c064bd6u; return 0; }
r[12]=r[0];
goto P_0c064bd8;
P_0c064bd8: /* original 5136, guest PC 0x0c064bd8 */
if(!s->budget--) { s->failed_pc=0x0c064bd8u; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c064bda;
P_0c064bda: /* original 62c3, guest PC 0x0c064bda */
if(!s->budget--) { s->failed_pc=0x0c064bdau; return 0; }
r[2]=r[12];
goto P_0c064bdc;
P_0c064bdc: /* original d069, guest PC 0x0c064bdc */
if(!s->budget--) { s->failed_pc=0x0c064bdcu; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064bde;
P_0c064bde: /* original 7c01, guest PC 0x0c064bde */
if(!s->budget--) { s->failed_pc=0x0c064bdeu; return 0; }
r[12]+=0x00000001u;
goto P_0c064be0;
P_0c064be0: /* original 4208, guest PC 0x0c064be0 */
if(!s->budget--) { s->failed_pc=0x0c064be0u; return 0; }
r[2]<<=2;
goto P_0c064be2;
P_0c064be2: /* original 0216, guest PC 0x0c064be2 */
if(!s->budget--) { s->failed_pc=0x0c064be2u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064be4;
P_0c064be4: /* original 66b2, guest PC 0x0c064be4 */
if(!s->budget--) { s->failed_pc=0x0c064be4u; return 0; }
tmp=read(ram,r[11],4);
r[6]=tmp;
goto P_0c064be6;
P_0c064be6: /* original 65c3, guest PC 0x0c064be6 */
if(!s->budget--) { s->failed_pc=0x0c064be6u; return 0; }
r[5]=r[12];
goto P_0c064be8;
P_0c064be8: /* original 5667, guest PC 0x0c064be8 */
if(!s->budget--) { s->failed_pc=0x0c064be8u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c064bea;
P_0c064bea: /* original bca1, guest PC 0x0c064bea */
if(!s->budget--) { s->failed_pc=0x0c064beau; return 0; }
target=code_base|0x0c064530u; r[16]=code_base|0x0c064beeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064beeu) { target=s->pc; goto dispatch; }
goto P_0c064bee;
P_0c064bec: /* original 64e3, guest PC 0x0c064bec */
if(!s->budget--) { s->failed_pc=0x0c064becu; return 0; }
r[4]=r[14];
goto P_0c064bee;
P_0c064bee: /* original 6403, guest PC 0x0c064bee */
if(!s->budget--) { s->failed_pc=0x0c064beeu; return 0; }
r[4]=r[0];
goto P_0c064bf0;
P_0c064bf0: /* original d265, guest PC 0x0c064bf0 */
if(!s->budget--) { s->failed_pc=0x0c064bf0u; return 0; }
r[2]=read(ram,0x0c064d88u,4);
goto P_0c064bf2;
P_0c064bf2: /* original 4408, guest PC 0x0c064bf2 */
if(!s->budget--) { s->failed_pc=0x0c064bf2u; return 0; }
r[4]<<=2;
goto P_0c064bf4;
P_0c064bf4: /* original 2242, guest PC 0x0c064bf4 */
if(!s->budget--) { s->failed_pc=0x0c064bf4u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c064bf6;
P_0c064bf6: /* original bc8c, guest PC 0x0c064bf6 */
if(!s->budget--) { s->failed_pc=0x0c064bf6u; return 0; }
target=code_base|0x0c064512u; r[16]=code_base|0x0c064bfau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064bfau) { target=s->pc; goto dispatch; }
goto P_0c064bfa;
P_0c064bf8: /* original 64e3, guest PC 0x0c064bf8 */
if(!s->budget--) { s->failed_pc=0x0c064bf8u; return 0; }
r[4]=r[14];
goto P_0c064bfa;
P_0c064bfa: /* original 6403, guest PC 0x0c064bfa */
if(!s->budget--) { s->failed_pc=0x0c064bfau; return 0; }
r[4]=r[0];
goto P_0c064bfc;
P_0c064bfc: /* original e500, guest PC 0x0c064bfc */
if(!s->budget--) { s->failed_pc=0x0c064bfcu; return 0; }
r[5]=0x00000000u;
goto P_0c064bfe;
P_0c064bfe: /* original bc73, guest PC 0x0c064bfe */
if(!s->budget--) { s->failed_pc=0x0c064bfeu; return 0; }
target=code_base|0x0c0644e8u; r[16]=code_base|0x0c064c02u;
r[6]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064c02u) { target=s->pc; goto dispatch; }
goto P_0c064c02;
P_0c064c00: /* original 6653, guest PC 0x0c064c00 */
if(!s->budget--) { s->failed_pc=0x0c064c00u; return 0; }
r[6]=r[5];
goto P_0c064c02;
P_0c064c02: /* original 62d2, guest PC 0x0c064c02 */
if(!s->budget--) { s->failed_pc=0x0c064c02u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c064c04;
P_0c064c04: /* original d161, guest PC 0x0c064c04 */
if(!s->budget--) { s->failed_pc=0x0c064c04u; return 0; }
r[1]=read(ram,0x0c064d8cu,4);
goto P_0c064c06;
P_0c064c06: /* original 5323, guest PC 0x0c064c06 */
if(!s->budget--) { s->failed_pc=0x0c064c06u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c064c08;
P_0c064c08: /* original 2132, guest PC 0x0c064c08 */
if(!s->budget--) { s->failed_pc=0x0c064c08u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c064c0a;
P_0c064c0a: /* original e000, guest PC 0x0c064c0a */
if(!s->budget--) { s->failed_pc=0x0c064c0au; return 0; }
r[0]=0x00000000u;
goto P_0c064c0c;
P_0c064c0c: /* original 7f10, guest PC 0x0c064c0c */
if(!s->budget--) { s->failed_pc=0x0c064c0cu; return 0; }
r[15]+=0x00000010u;
goto P_0c064c0e;
P_0c064c0e: /* original 4f26, guest PC 0x0c064c0e */
if(!s->budget--) { s->failed_pc=0x0c064c0eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c064c10;
P_0c064c10: /* original 6af6, guest PC 0x0c064c10 */
if(!s->budget--) { s->failed_pc=0x0c064c10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c064c12;
P_0c064c12: /* original 6bf6, guest PC 0x0c064c12 */
if(!s->budget--) { s->failed_pc=0x0c064c12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c064c14;
P_0c064c14: /* original 6cf6, guest PC 0x0c064c14 */
if(!s->budget--) { s->failed_pc=0x0c064c14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c064c16;
P_0c064c16: /* original 6df6, guest PC 0x0c064c16 */
if(!s->budget--) { s->failed_pc=0x0c064c16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c064c18;
P_0c064c18: /* original 000b, guest PC 0x0c064c18 */
if(!s->budget--) { s->failed_pc=0x0c064c18u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c064c1a: /* original 6ef6, guest PC 0x0c064c1a */
if(!s->budget--) { s->failed_pc=0x0c064c1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c064c1cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
