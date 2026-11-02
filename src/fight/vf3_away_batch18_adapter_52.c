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
int vf3_away_batch18_adapter_52(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a89b4u: goto P_0c0a89b4;
case 0x0c0a89b6u: goto P_0c0a89b6;
case 0x0c0a89b8u: goto P_0c0a89b8;
case 0x0c0a89bau: goto P_0c0a89ba;
case 0x0c0a89bcu: goto P_0c0a89bc;
case 0x0c0a89beu: goto P_0c0a89be;
case 0x0c0a89c0u: goto P_0c0a89c0;
case 0x0c0a89c2u: goto P_0c0a89c2;
case 0x0c0a89c4u: goto P_0c0a89c4;
case 0x0c0a89c6u: goto P_0c0a89c6;
case 0x0c0a89c8u: goto P_0c0a89c8;
case 0x0c0a89cau: goto P_0c0a89ca;
case 0x0c0a89ccu: goto P_0c0a89cc;
case 0x0c0a89ceu: goto P_0c0a89ce;
case 0x0c0a89d0u: goto P_0c0a89d0;
case 0x0c0a89d2u: goto P_0c0a89d2;
case 0x0c0a89d4u: goto P_0c0a89d4;
case 0x0c0a89d6u: goto P_0c0a89d6;
case 0x0c0a89d8u: goto P_0c0a89d8;
case 0x0c0a89dau: goto P_0c0a89da;
case 0x0c0a89dcu: goto P_0c0a89dc;
case 0x0c0a89deu: goto P_0c0a89de;
case 0x0c0a89e0u: goto P_0c0a89e0;
case 0x0c0a89e2u: goto P_0c0a89e2;
case 0x0c0a89e4u: goto P_0c0a89e4;
case 0x0c0a89e6u: goto P_0c0a89e6;
case 0x0c0a89e8u: goto P_0c0a89e8;
case 0x0c0a89eau: goto P_0c0a89ea;
case 0x0c0a89ecu: goto P_0c0a89ec;
case 0x0c0a89eeu: goto P_0c0a89ee;
case 0x0c0a89f0u: goto P_0c0a89f0;
case 0x0c0a89f2u: goto P_0c0a89f2;
case 0x0c0a89f4u: goto P_0c0a89f4;
case 0x0c0a89f6u: goto P_0c0a89f6;
case 0x0c0a89f8u: goto P_0c0a89f8;
case 0x0c0a89fau: goto P_0c0a89fa;
case 0x0c0a89fcu: goto P_0c0a89fc;
case 0x0c0a89feu: goto P_0c0a89fe;
case 0x0c0a8a00u: goto P_0c0a8a00;
case 0x0c0a8a02u: goto P_0c0a8a02;
case 0x0c0a8a04u: goto P_0c0a8a04;
case 0x0c0a8a06u: goto P_0c0a8a06;
case 0x0c0a8a08u: goto P_0c0a8a08;
case 0x0c0a8a0au: goto P_0c0a8a0a;
case 0x0c0a8a0cu: goto P_0c0a8a0c;
case 0x0c0a8a0eu: goto P_0c0a8a0e;
case 0x0c0a8a10u: goto P_0c0a8a10;
case 0x0c0a8a12u: goto P_0c0a8a12;
case 0x0c0a8a14u: goto P_0c0a8a14;
case 0x0c0a8a16u: goto P_0c0a8a16;
case 0x0c0a8a18u: goto P_0c0a8a18;
case 0x0c0a8a1au: goto P_0c0a8a1a;
case 0x0c0a8a1cu: goto P_0c0a8a1c;
case 0x0c0a8a1eu: goto P_0c0a8a1e;
case 0x0c0a8a20u: goto P_0c0a8a20;
case 0x0c0a8a22u: goto P_0c0a8a22;
case 0x0c0a8a24u: goto P_0c0a8a24;
case 0x0c0a8a26u: goto P_0c0a8a26;
case 0x0c0a8a28u: goto P_0c0a8a28;
case 0x0c0a8a2au: goto P_0c0a8a2a;
case 0x0c0a8a2cu: goto P_0c0a8a2c;
case 0x0c0a8a2eu: goto P_0c0a8a2e;
case 0x0c0a8a30u: goto P_0c0a8a30;
case 0x0c0a8a32u: goto P_0c0a8a32;
case 0x0c0a8a34u: goto P_0c0a8a34;
case 0x0c0a8a36u: goto P_0c0a8a36;
case 0x0c0a8a38u: goto P_0c0a8a38;
case 0x0c0a8a3au: goto P_0c0a8a3a;
case 0x0c0a8a3cu: goto P_0c0a8a3c;
case 0x0c0a8a3eu: goto P_0c0a8a3e;
case 0x0c0a8a40u: goto P_0c0a8a40;
case 0x0c0a8a42u: goto P_0c0a8a42;
case 0x0c0a8a44u: goto P_0c0a8a44;
case 0x0c0a8a46u: goto P_0c0a8a46;
case 0x0c0a8a48u: goto P_0c0a8a48;
case 0x0c0a8a4au: goto P_0c0a8a4a;
case 0x0c0a8a4cu: goto P_0c0a8a4c;
case 0x0c0a8a4eu: goto P_0c0a8a4e;
case 0x0c0a8a50u: goto P_0c0a8a50;
case 0x0c0a8a52u: goto P_0c0a8a52;
case 0x0c0a8a54u: goto P_0c0a8a54;
case 0x0c0a8a56u: goto P_0c0a8a56;
case 0x0c0a8a58u: goto P_0c0a8a58;
case 0x0c0a8a5au: goto P_0c0a8a5a;
case 0x0c0a8a5cu: goto P_0c0a8a5c;
case 0x0c0a8a5eu: goto P_0c0a8a5e;
case 0x0c0a8a60u: goto P_0c0a8a60;
case 0x0c0a8a62u: goto P_0c0a8a62;
case 0x0c0a8a64u: goto P_0c0a8a64;
case 0x0c0a8a66u: goto P_0c0a8a66;
case 0x0c0a8a68u: goto P_0c0a8a68;
case 0x0c0a8a6au: goto P_0c0a8a6a;
case 0x0c0a8a6cu: goto P_0c0a8a6c;
case 0x0c0a8a6eu: goto P_0c0a8a6e;
case 0x0c0a8a70u: goto P_0c0a8a70;
case 0x0c0a8a72u: goto P_0c0a8a72;
case 0x0c0a8a74u: goto P_0c0a8a74;
case 0x0c0a8a76u: goto P_0c0a8a76;
case 0x0c0a8a78u: goto P_0c0a8a78;
case 0x0c0a8a7au: goto P_0c0a8a7a;
case 0x0c0a8a7cu: goto P_0c0a8a7c;
case 0x0c0a8a7eu: goto P_0c0a8a7e;
case 0x0c0a8a80u: goto P_0c0a8a80;
case 0x0c0a8a82u: goto P_0c0a8a82;
case 0x0c0a8a84u: goto P_0c0a8a84;
case 0x0c0a8a86u: goto P_0c0a8a86;
case 0x0c0a8a88u: goto P_0c0a8a88;
case 0x0c0a8a8au: goto P_0c0a8a8a;
case 0x0c0a8a8cu: goto P_0c0a8a8c;
case 0x0c0a8a8eu: goto P_0c0a8a8e;
case 0x0c0a91dau: goto P_0c0a91da;
case 0x0c0a91dcu: goto P_0c0a91dc;
case 0x0c0a91deu: goto P_0c0a91de;
case 0x0c0a91e0u: goto P_0c0a91e0;
case 0x0c0a91e2u: goto P_0c0a91e2;
case 0x0c0a91e4u: goto P_0c0a91e4;
case 0x0c0a91e6u: goto P_0c0a91e6;
case 0x0c0a91e8u: goto P_0c0a91e8;
case 0x0c0a91eau: goto P_0c0a91ea;
case 0x0c0a91ecu: goto P_0c0a91ec;
case 0x0c0a91eeu: goto P_0c0a91ee;
case 0x0c0a91f0u: goto P_0c0a91f0;
case 0x0c0a91f2u: goto P_0c0a91f2;
case 0x0c0a91f4u: goto P_0c0a91f4;
case 0x0c0a91f6u: goto P_0c0a91f6;
case 0x0c0a91f8u: goto P_0c0a91f8;
case 0x0c0a91fau: goto P_0c0a91fa;
case 0x0c0a91fcu: goto P_0c0a91fc;
case 0x0c0a91feu: goto P_0c0a91fe;
case 0x0c0a9200u: goto P_0c0a9200;
case 0x0c0a9202u: goto P_0c0a9202;
case 0x0c0a9204u: goto P_0c0a9204;
case 0x0c0a9206u: goto P_0c0a9206;
case 0x0c0a9208u: goto P_0c0a9208;
case 0x0c0a920au: goto P_0c0a920a;
case 0x0c0a920cu: goto P_0c0a920c;
case 0x0c0a920eu: goto P_0c0a920e;
case 0x0c0a9210u: goto P_0c0a9210;
case 0x0c0a9212u: goto P_0c0a9212;
case 0x0c0a9214u: goto P_0c0a9214;
case 0x0c0a9216u: goto P_0c0a9216;
case 0x0c0a9218u: goto P_0c0a9218;
case 0x0c0a921au: goto P_0c0a921a;
case 0x0c0a921cu: goto P_0c0a921c;
case 0x0c0a921eu: goto P_0c0a921e;
case 0x0c0a9220u: goto P_0c0a9220;
case 0x0c0a9222u: goto P_0c0a9222;
case 0x0c0a9224u: goto P_0c0a9224;
case 0x0c0a9226u: goto P_0c0a9226;
case 0x0c0a9228u: goto P_0c0a9228;
case 0x0c0a922au: goto P_0c0a922a;
case 0x0c0a922cu: goto P_0c0a922c;
case 0x0c0a922eu: goto P_0c0a922e;
case 0x0c0a9230u: goto P_0c0a9230;
case 0x0c0a9232u: goto P_0c0a9232;
case 0x0c0a9234u: goto P_0c0a9234;
case 0x0c0a9236u: goto P_0c0a9236;
case 0x0c0a9238u: goto P_0c0a9238;
case 0x0c0a923au: goto P_0c0a923a;
case 0x0c0a923cu: goto P_0c0a923c;
case 0x0c0a923eu: goto P_0c0a923e;
case 0x0c0a9240u: goto P_0c0a9240;
case 0x0c0a9242u: goto P_0c0a9242;
case 0x0c0a926au: goto P_0c0a926a;
case 0x0c0a926cu: goto P_0c0a926c;
case 0x0c0a926eu: goto P_0c0a926e;
case 0x0c0a9270u: goto P_0c0a9270;
case 0x0c0a9272u: goto P_0c0a9272;
case 0x0c0a9274u: goto P_0c0a9274;
case 0x0c0a9276u: goto P_0c0a9276;
case 0x0c0a9278u: goto P_0c0a9278;
case 0x0c0a927au: goto P_0c0a927a;
case 0x0c0a927cu: goto P_0c0a927c;
case 0x0c0a927eu: goto P_0c0a927e;
case 0x0c0a9280u: goto P_0c0a9280;
case 0x0c0a9282u: goto P_0c0a9282;
case 0x0c0a9284u: goto P_0c0a9284;
case 0x0c0a9286u: goto P_0c0a9286;
case 0x0c0a9288u: goto P_0c0a9288;
case 0x0c0a928au: goto P_0c0a928a;
case 0x0c0a928cu: goto P_0c0a928c;
case 0x0c0a928eu: goto P_0c0a928e;
case 0x0c0a9290u: goto P_0c0a9290;
case 0x0c0a9444u: goto P_0c0a9444;
case 0x0c0a9446u: goto P_0c0a9446;
case 0x0c0a9448u: goto P_0c0a9448;
case 0x0c0a944au: goto P_0c0a944a;
case 0x0c0a944cu: goto P_0c0a944c;
case 0x0c0a944eu: goto P_0c0a944e;
case 0x0c0a9450u: goto P_0c0a9450;
case 0x0c0a9452u: goto P_0c0a9452;
case 0x0c0a9454u: goto P_0c0a9454;
case 0x0c0a9456u: goto P_0c0a9456;
case 0x0c0a9458u: goto P_0c0a9458;
case 0x0c0a945au: goto P_0c0a945a;
case 0x0c0a945cu: goto P_0c0a945c;
case 0x0c0a945eu: goto P_0c0a945e;
case 0x0c0a9460u: goto P_0c0a9460;
case 0x0c0a9462u: goto P_0c0a9462;
case 0x0c0a9464u: goto P_0c0a9464;
case 0x0c0a9466u: goto P_0c0a9466;
case 0x0c0a9468u: goto P_0c0a9468;
case 0x0c0a946au: goto P_0c0a946a;
case 0x0c0a946cu: goto P_0c0a946c;
case 0x0c0a946eu: goto P_0c0a946e;
case 0x0c0a9470u: goto P_0c0a9470;
case 0x0c0a9472u: goto P_0c0a9472;
case 0x0c0a9474u: goto P_0c0a9474;
case 0x0c0a9476u: goto P_0c0a9476;
case 0x0c0a9478u: goto P_0c0a9478;
case 0x0c0a947au: goto P_0c0a947a;
case 0x0c0a947cu: goto P_0c0a947c;
case 0x0c0a947eu: goto P_0c0a947e;
case 0x0c0a9480u: goto P_0c0a9480;
case 0x0c0a9482u: goto P_0c0a9482;
case 0x0c0a9484u: goto P_0c0a9484;
case 0x0c0a9486u: goto P_0c0a9486;
case 0x0c0a9488u: goto P_0c0a9488;
case 0x0c0a948au: goto P_0c0a948a;
case 0x0c0a948cu: goto P_0c0a948c;
case 0x0c0a948eu: goto P_0c0a948e;
case 0x0c0a9490u: goto P_0c0a9490;
case 0x0c0a9492u: goto P_0c0a9492;
case 0x0c0a9494u: goto P_0c0a9494;
case 0x0c0a9496u: goto P_0c0a9496;
case 0x0c0a9498u: goto P_0c0a9498;
case 0x0c0a949au: goto P_0c0a949a;
case 0x0c0a949cu: goto P_0c0a949c;
case 0x0c0a949eu: goto P_0c0a949e;
case 0x0c0a94a0u: goto P_0c0a94a0;
case 0x0c0a94a2u: goto P_0c0a94a2;
case 0x0c0a94a4u: goto P_0c0a94a4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a89b4: /* original 2fe6, guest PC 0x0c0a89b4 */
if(!s->budget--) { s->failed_pc=0x0c0a89b4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a89b6;
P_0c0a89b6: /* original e400, guest PC 0x0c0a89b6 */
if(!s->budget--) { s->failed_pc=0x0c0a89b6u; return 0; }
r[4]=0x00000000u;
goto P_0c0a89b8;
P_0c0a89b8: /* original 2fd6, guest PC 0x0c0a89b8 */
if(!s->budget--) { s->failed_pc=0x0c0a89b8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a89ba;
P_0c0a89ba: /* original e70d, guest PC 0x0c0a89ba */
if(!s->budget--) { s->failed_pc=0x0c0a89bau; return 0; }
r[7]=0x0000000du;
goto P_0c0a89bc;
P_0c0a89bc: /* original 2fc6, guest PC 0x0c0a89bc */
if(!s->budget--) { s->failed_pc=0x0c0a89bcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a89be;
P_0c0a89be: /* original de37, guest PC 0x0c0a89be */
if(!s->budget--) { s->failed_pc=0x0c0a89beu; return 0; }
r[14]=read(ram,0x0c0a8a9cu,4);
goto P_0c0a89c0;
P_0c0a89c0: /* original 9066, guest PC 0x0c0a89c0 */
if(!s->budget--) { s->failed_pc=0x0c0a89c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8a90u,2);
goto P_0c0a89c2;
P_0c0a89c2: /* original 4f22, guest PC 0x0c0a89c2 */
if(!s->budget--) { s->failed_pc=0x0c0a89c2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a89c4;
P_0c0a89c4: /* original 0e44, guest PC 0x0c0a89c4 */
if(!s->budget--) { s->failed_pc=0x0c0a89c4u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a89c6;
P_0c0a89c6: /* original 7001, guest PC 0x0c0a89c6 */
if(!s->budget--) { s->failed_pc=0x0c0a89c6u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a89c8;
P_0c0a89c8: /* original 0e44, guest PC 0x0c0a89c8 */
if(!s->budget--) { s->failed_pc=0x0c0a89c8u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a89ca;
P_0c0a89ca: /* original 7001, guest PC 0x0c0a89ca */
if(!s->budget--) { s->failed_pc=0x0c0a89cau; return 0; }
r[0]+=0x00000001u;
goto P_0c0a89cc;
P_0c0a89cc: /* original 0e44, guest PC 0x0c0a89cc */
if(!s->budget--) { s->failed_pc=0x0c0a89ccu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a89ce;
P_0c0a89ce: /* original d434, guest PC 0x0c0a89ce */
if(!s->budget--) { s->failed_pc=0x0c0a89ceu; return 0; }
r[4]=read(ram,0x0c0a8aa0u,4);
goto P_0c0a89d0;
P_0c0a89d0: /* original 4f12, guest PC 0x0c0a89d0 */
if(!s->budget--) { s->failed_pc=0x0c0a89d0u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a89d2;
P_0c0a89d2: /* original 5c44, guest PC 0x0c0a89d2 */
if(!s->budget--) { s->failed_pc=0x0c0a89d2u; return 0; }
r[12]=read(ram,r[4]+16,4);
goto P_0c0a89d4;
P_0c0a89d4: /* original 5d45, guest PC 0x0c0a89d4 */
if(!s->budget--) { s->failed_pc=0x0c0a89d4u; return 0; }
r[13]=read(ram,r[4]+20,4);
goto P_0c0a89d6;
P_0c0a89d6: /* original 945c, guest PC 0x0c0a89d6 */
if(!s->budget--) { s->failed_pc=0x0c0a89d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8a92u,2);
goto P_0c0a89d8;
P_0c0a89d8: /* original 7ffc, guest PC 0x0c0a89d8 */
if(!s->budget--) { s->failed_pc=0x0c0a89d8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a89da;
P_0c0a89da: /* original 34ec, guest PC 0x0c0a89da */
if(!s->budget--) { s->failed_pc=0x0c0a89dau; return 0; }
r[4]+=r[14];
goto P_0c0a89dc;
P_0c0a89dc: /* original 8441, guest PC 0x0c0a89dc */
if(!s->budget--) { s->failed_pc=0x0c0a89dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0a89de;
P_0c0a89de: /* original 6640, guest PC 0x0c0a89de */
if(!s->budget--) { s->failed_pc=0x0c0a89deu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[6]=tmp;
goto P_0c0a89e0;
P_0c0a89e0: /* original 6503, guest PC 0x0c0a89e0 */
if(!s->budget--) { s->failed_pc=0x0c0a89e0u; return 0; }
r[5]=r[0];
goto P_0c0a89e2;
P_0c0a89e2: /* original 8442, guest PC 0x0c0a89e2 */
if(!s->budget--) { s->failed_pc=0x0c0a89e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c0a89e4;
P_0c0a89e4: /* original 635e, guest PC 0x0c0a89e4 */
if(!s->budget--) { s->failed_pc=0x0c0a89e4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c0a89e6;
P_0c0a89e6: /* original 6403, guest PC 0x0c0a89e6 */
if(!s->budget--) { s->failed_pc=0x0c0a89e6u; return 0; }
r[4]=r[0];
goto P_0c0a89e8;
P_0c0a89e8: /* original 3373, guest PC 0x0c0a89e8 */
if(!s->budget--) { s->failed_pc=0x0c0a89e8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[7])!=0);
goto P_0c0a89ea;
P_0c0a89ea: /* original e060, guest PC 0x0c0a89ea */
if(!s->budget--) { s->failed_pc=0x0c0a89eau; return 0; }
r[0]=0x00000060u;
goto P_0c0a89ec;
P_0c0a89ec: /* original 8f01, guest PC 0x0c0a89ec */
if(!s->budget--) { s->failed_pc=0x0c0a89ecu; return 0; }
cond=r[17]&1u;
write(ram,r[12]+r[0],r[5],1);
if(!cond) { goto P_0c0a89f2; }
goto P_0c0a89f0;
P_0c0a89ee: /* original 0c54, guest PC 0x0c0a89ee */
if(!s->budget--) { s->failed_pc=0x0c0a89eeu; return 0; }
write(ram,r[12]+r[0],r[5],1);
goto P_0c0a89f0;
P_0c0a89f0: /* original 75f3, guest PC 0x0c0a89f0 */
if(!s->budget--) { s->failed_pc=0x0c0a89f0u; return 0; }
r[5]+=0xfffffff3u;
goto P_0c0a89f2;
P_0c0a89f2: /* original e061, guest PC 0x0c0a89f2 */
if(!s->budget--) { s->failed_pc=0x0c0a89f2u; return 0; }
r[0]=0x00000061u;
goto P_0c0a89f4;
P_0c0a89f4: /* original 634e, guest PC 0x0c0a89f4 */
if(!s->budget--) { s->failed_pc=0x0c0a89f4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a89f6;
P_0c0a89f6: /* original 0c54, guest PC 0x0c0a89f6 */
if(!s->budget--) { s->failed_pc=0x0c0a89f6u; return 0; }
write(ram,r[12]+r[0],r[5],1);
goto P_0c0a89f8;
P_0c0a89f8: /* original 3373, guest PC 0x0c0a89f8 */
if(!s->budget--) { s->failed_pc=0x0c0a89f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[7])!=0);
goto P_0c0a89fa;
P_0c0a89fa: /* original e060, guest PC 0x0c0a89fa */
if(!s->budget--) { s->failed_pc=0x0c0a89fau; return 0; }
r[0]=0x00000060u;
goto P_0c0a89fc;
P_0c0a89fc: /* original 8f01, guest PC 0x0c0a89fc */
if(!s->budget--) { s->failed_pc=0x0c0a89fcu; return 0; }
cond=r[17]&1u;
write(ram,r[13]+r[0],r[4],1);
if(!cond) { goto P_0c0a8a02; }
goto P_0c0a8a00;
P_0c0a89fe: /* original 0d44, guest PC 0x0c0a89fe */
if(!s->budget--) { s->failed_pc=0x0c0a89feu; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c0a8a00;
P_0c0a8a00: /* original 74f3, guest PC 0x0c0a8a00 */
if(!s->budget--) { s->failed_pc=0x0c0a8a00u; return 0; }
r[4]+=0xfffffff3u;
goto P_0c0a8a02;
P_0c0a8a02: /* original e061, guest PC 0x0c0a8a02 */
if(!s->budget--) { s->failed_pc=0x0c0a8a02u; return 0; }
r[0]=0x00000061u;
goto P_0c0a8a04;
P_0c0a8a04: /* original 0d44, guest PC 0x0c0a8a04 */
if(!s->budget--) { s->failed_pc=0x0c0a8a04u; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c0a8a06;
P_0c0a8a06: /* original d327, guest PC 0x0c0a8a06 */
if(!s->budget--) { s->failed_pc=0x0c0a8a06u; return 0; }
r[3]=read(ram,0x0c0a8aa4u,4);
goto P_0c0a8a08;
P_0c0a8a08: /* original d227, guest PC 0x0c0a8a08 */
if(!s->budget--) { s->failed_pc=0x0c0a8a08u; return 0; }
r[2]=read(ram,0x0c0a8aa8u,4);
goto P_0c0a8a0a;
P_0c0a8a0a: /* original 420b, guest PC 0x0c0a8a0a */
if(!s->budget--) { s->failed_pc=0x0c0a8a0au; return 0; }
target=r[2];
r[16]=code_base|0x0c0a8a0eu;
write(ram,r[3],r[6],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8a0eu) { target=s->pc; goto dispatch; }
goto P_0c0a8a0e;
P_0c0a8a0c: /* original 2360, guest PC 0x0c0a8a0c */
if(!s->budget--) { s->failed_pc=0x0c0a8a0cu; return 0; }
write(ram,r[3],r[6],1);
goto P_0c0a8a0e;
P_0c0a8a0e: /* original d127, guest PC 0x0c0a8a0e */
if(!s->budget--) { s->failed_pc=0x0c0a8a0eu; return 0; }
r[1]=read(ram,0x0c0a8aacu,4);
goto P_0c0a8a10;
P_0c0a8a10: /* original 410b, guest PC 0x0c0a8a10 */
if(!s->budget--) { s->failed_pc=0x0c0a8a10u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a8a14u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8a14u) { target=s->pc; goto dispatch; }
goto P_0c0a8a14;
P_0c0a8a12: /* original 0009, guest PC 0x0c0a8a12 */
if(!s->budget--) { s->failed_pc=0x0c0a8a12u; return 0; }
goto P_0c0a8a14;
P_0c0a8a14: /* original d526, guest PC 0x0c0a8a14 */
if(!s->budget--) { s->failed_pc=0x0c0a8a14u; return 0; }
r[5]=read(ram,0x0c0a8ab0u,4);
goto P_0c0a8a16;
P_0c0a8a16: /* original e301, guest PC 0x0c0a8a16 */
if(!s->budget--) { s->failed_pc=0x0c0a8a16u; return 0; }
r[3]=0x00000001u;
goto P_0c0a8a18;
P_0c0a8a18: /* original 5451, guest PC 0x0c0a8a18 */
if(!s->budget--) { s->failed_pc=0x0c0a8a18u; return 0; }
r[4]=read(ram,r[5]+4,4);
goto P_0c0a8a1a;
P_0c0a8a1a: /* original 243b, guest PC 0x0c0a8a1a */
if(!s->budget--) { s->failed_pc=0x0c0a8a1au; return 0; }
r[4]|=r[3];
goto P_0c0a8a1c;
P_0c0a8a1c: /* original 1541, guest PC 0x0c0a8a1c */
if(!s->budget--) { s->failed_pc=0x0c0a8a1cu; return 0; }
write(ram,r[5]+4,r[4],4);
goto P_0c0a8a1e;
P_0c0a8a1e: /* original 9039, guest PC 0x0c0a8a1e */
if(!s->budget--) { s->failed_pc=0x0c0a8a1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8a94u,2);
goto P_0c0a8a20;
P_0c0a8a20: /* original 9239, guest PC 0x0c0a8a20 */
if(!s->budget--) { s->failed_pc=0x0c0a8a20u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8a96u,2);
goto P_0c0a8a22;
P_0c0a8a22: /* original 04ec, guest PC 0x0c0a8a22 */
if(!s->budget--) { s->failed_pc=0x0c0a8a22u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a8a24;
P_0c0a8a24: /* original 70ff, guest PC 0x0c0a8a24 */
if(!s->budget--) { s->failed_pc=0x0c0a8a24u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0a8a26;
P_0c0a8a26: /* original 32ec, guest PC 0x0c0a8a26 */
if(!s->budget--) { s->failed_pc=0x0c0a8a26u; return 0; }
r[2]+=r[14];
goto P_0c0a8a28;
P_0c0a8a28: /* original d122, guest PC 0x0c0a8a28 */
if(!s->budget--) { s->failed_pc=0x0c0a8a28u; return 0; }
r[1]=read(ram,0x0c0a8ab4u,4);
goto P_0c0a8a2a;
P_0c0a8a2a: /* original 4408, guest PC 0x0c0a8a2a */
if(!s->budget--) { s->failed_pc=0x0c0a8a2au; return 0; }
r[4]<<=2;
goto P_0c0a8a2c;
P_0c0a8a2c: /* original 342c, guest PC 0x0c0a8a2c */
if(!s->budget--) { s->failed_pc=0x0c0a8a2cu; return 0; }
r[4]+=r[2];
goto P_0c0a8a2e;
P_0c0a8a2e: /* original 6442, guest PC 0x0c0a8a2e */
if(!s->budget--) { s->failed_pc=0x0c0a8a2eu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0a8a30;
P_0c0a8a30: /* original 2142, guest PC 0x0c0a8a30 */
if(!s->budget--) { s->failed_pc=0x0c0a8a30u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c0a8a32;
P_0c0a8a32: /* original 05ec, guest PC 0x0c0a8a32 */
if(!s->budget--) { s->failed_pc=0x0c0a8a32u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a8a34;
P_0c0a8a34: /* original 7001, guest PC 0x0c0a8a34 */
if(!s->budget--) { s->failed_pc=0x0c0a8a34u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a8a36;
P_0c0a8a36: /* original 932f, guest PC 0x0c0a8a36 */
if(!s->budget--) { s->failed_pc=0x0c0a8a36u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8a98u,2);
goto P_0c0a8a38;
P_0c0a8a38: /* original 04ec, guest PC 0x0c0a8a38 */
if(!s->budget--) { s->failed_pc=0x0c0a8a38u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a8a3a;
P_0c0a8a3a: /* original 655c, guest PC 0x0c0a8a3a */
if(!s->budget--) { s->failed_pc=0x0c0a8a3au; return 0; }
r[5]=r[5]&255u;
goto P_0c0a8a3c;
P_0c0a8a3c: /* original 4508, guest PC 0x0c0a8a3c */
if(!s->budget--) { s->failed_pc=0x0c0a8a3cu; return 0; }
r[5]<<=2;
goto P_0c0a8a3e;
P_0c0a8a3e: /* original d21e, guest PC 0x0c0a8a3e */
if(!s->budget--) { s->failed_pc=0x0c0a8a3eu; return 0; }
r[2]=read(ram,0x0c0a8ab8u,4);
goto P_0c0a8a40;
P_0c0a8a40: /* original 243f, guest PC 0x0c0a8a40 */
if(!s->budget--) { s->failed_pc=0x0c0a8a40u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c0a8a42;
P_0c0a8a42: /* original 4508, guest PC 0x0c0a8a42 */
if(!s->budget--) { s->failed_pc=0x0c0a8a42u; return 0; }
r[5]<<=2;
goto P_0c0a8a44;
P_0c0a8a44: /* original 4508, guest PC 0x0c0a8a44 */
if(!s->budget--) { s->failed_pc=0x0c0a8a44u; return 0; }
r[5]<<=2;
goto P_0c0a8a46;
P_0c0a8a46: /* original e004, guest PC 0x0c0a8a46 */
if(!s->budget--) { s->failed_pc=0x0c0a8a46u; return 0; }
r[0]=0x00000004u;
goto P_0c0a8a48;
P_0c0a8a48: /* original 041a, guest PC 0x0c0a8a48 */
if(!s->budget--) { s->failed_pc=0x0c0a8a48u; return 0; }
r[4]=r[19];
goto P_0c0a8a4a;
P_0c0a8a4a: /* original 6e43, guest PC 0x0c0a8a4a */
if(!s->budget--) { s->failed_pc=0x0c0a8a4au; return 0; }
r[14]=r[4];
goto P_0c0a8a4c;
P_0c0a8a4c: /* original 3e5c, guest PC 0x0c0a8a4c */
if(!s->budget--) { s->failed_pc=0x0c0a8a4cu; return 0; }
r[14]+=r[5];
goto P_0c0a8a4e;
P_0c0a8a4e: /* original 3e2c, guest PC 0x0c0a8a4e */
if(!s->budget--) { s->failed_pc=0x0c0a8a4eu; return 0; }
r[14]+=r[2];
goto P_0c0a8a50;
P_0c0a8a50: /* original f4e6, guest PC 0x0c0a8a50 */
if(!s->budget--) { s->failed_pc=0x0c0a8a50u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a8a52;
P_0c0a8a52: /* original e008, guest PC 0x0c0a8a52 */
if(!s->budget--) { s->failed_pc=0x0c0a8a52u; return 0; }
r[0]=0x00000008u;
goto P_0c0a8a54;
P_0c0a8a54: /* original f5e6, guest PC 0x0c0a8a54 */
if(!s->budget--) { s->failed_pc=0x0c0a8a54u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a8a56;
P_0c0a8a56: /* original e00c, guest PC 0x0c0a8a56 */
if(!s->budget--) { s->failed_pc=0x0c0a8a56u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a8a58;
P_0c0a8a58: /* original f6e6, guest PC 0x0c0a8a58 */
if(!s->budget--) { s->failed_pc=0x0c0a8a58u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0a8a5a;
P_0c0a8a5a: /* original e500, guest PC 0x0c0a8a5a */
if(!s->budget--) { s->failed_pc=0x0c0a8a5au; return 0; }
r[5]=0x00000000u;
goto P_0c0a8a5c;
P_0c0a8a5c: /* original 85ea, guest PC 0x0c0a8a5c */
if(!s->budget--) { s->failed_pc=0x0c0a8a5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+20,2);
goto P_0c0a8a5e;
P_0c0a8a5e: /* original 2f01, guest PC 0x0c0a8a5e */
if(!s->budget--) { s->failed_pc=0x0c0a8a5eu; return 0; }
write(ram,r[15],r[0],2);
goto P_0c0a8a60;
P_0c0a8a60: /* original d116, guest PC 0x0c0a8a60 */
if(!s->budget--) { s->failed_pc=0x0c0a8a60u; return 0; }
r[1]=read(ram,0x0c0a8abcu,4);
goto P_0c0a8a62;
P_0c0a8a62: /* original 66f1, guest PC 0x0c0a8a62 */
if(!s->budget--) { s->failed_pc=0x0c0a8a62u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[6]=tmp;
goto P_0c0a8a64;
P_0c0a8a64: /* original 410b, guest PC 0x0c0a8a64 */
if(!s->budget--) { s->failed_pc=0x0c0a8a64u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a8a68u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8a68u) { target=s->pc; goto dispatch; }
goto P_0c0a8a68;
P_0c0a8a66: /* original 64c3, guest PC 0x0c0a8a66 */
if(!s->budget--) { s->failed_pc=0x0c0a8a66u; return 0; }
r[4]=r[12];
goto P_0c0a8a68;
P_0c0a8a68: /* original e004, guest PC 0x0c0a8a68 */
if(!s->budget--) { s->failed_pc=0x0c0a8a68u; return 0; }
r[0]=0x00000004u;
goto P_0c0a8a6a;
P_0c0a8a6a: /* original 64d3, guest PC 0x0c0a8a6a */
if(!s->budget--) { s->failed_pc=0x0c0a8a6au; return 0; }
r[4]=r[13];
goto P_0c0a8a6c;
P_0c0a8a6c: /* original 7e20, guest PC 0x0c0a8a6c */
if(!s->budget--) { s->failed_pc=0x0c0a8a6cu; return 0; }
r[14]+=0x00000020u;
goto P_0c0a8a6e;
P_0c0a8a6e: /* original f4e6, guest PC 0x0c0a8a6e */
if(!s->budget--) { s->failed_pc=0x0c0a8a6eu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a8a70;
P_0c0a8a70: /* original e008, guest PC 0x0c0a8a70 */
if(!s->budget--) { s->failed_pc=0x0c0a8a70u; return 0; }
r[0]=0x00000008u;
goto P_0c0a8a72;
P_0c0a8a72: /* original f5e6, guest PC 0x0c0a8a72 */
if(!s->budget--) { s->failed_pc=0x0c0a8a72u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a8a74;
P_0c0a8a74: /* original e00c, guest PC 0x0c0a8a74 */
if(!s->budget--) { s->failed_pc=0x0c0a8a74u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a8a76;
P_0c0a8a76: /* original f6e6, guest PC 0x0c0a8a76 */
if(!s->budget--) { s->failed_pc=0x0c0a8a76u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0a8a78;
P_0c0a8a78: /* original e501, guest PC 0x0c0a8a78 */
if(!s->budget--) { s->failed_pc=0x0c0a8a78u; return 0; }
r[5]=0x00000001u;
goto P_0c0a8a7a;
P_0c0a8a7a: /* original 85ea, guest PC 0x0c0a8a7a */
if(!s->budget--) { s->failed_pc=0x0c0a8a7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+20,2);
goto P_0c0a8a7c;
P_0c0a8a7c: /* original 2f01, guest PC 0x0c0a8a7c */
if(!s->budget--) { s->failed_pc=0x0c0a8a7cu; return 0; }
write(ram,r[15],r[0],2);
goto P_0c0a8a7e;
P_0c0a8a7e: /* original 66f1, guest PC 0x0c0a8a7e */
if(!s->budget--) { s->failed_pc=0x0c0a8a7eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[6]=tmp;
goto P_0c0a8a80;
P_0c0a8a80: /* original 7f04, guest PC 0x0c0a8a80 */
if(!s->budget--) { s->failed_pc=0x0c0a8a80u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a8a82;
P_0c0a8a82: /* original 4f16, guest PC 0x0c0a8a82 */
if(!s->budget--) { s->failed_pc=0x0c0a8a82u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8a84;
P_0c0a8a84: /* original d30d, guest PC 0x0c0a8a84 */
if(!s->budget--) { s->failed_pc=0x0c0a8a84u; return 0; }
r[3]=read(ram,0x0c0a8abcu,4);
goto P_0c0a8a86;
P_0c0a8a86: /* original 4f26, guest PC 0x0c0a8a86 */
if(!s->budget--) { s->failed_pc=0x0c0a8a86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8a88;
P_0c0a8a88: /* original 6cf6, guest PC 0x0c0a8a88 */
if(!s->budget--) { s->failed_pc=0x0c0a8a88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8a8a;
P_0c0a8a8a: /* original 6df6, guest PC 0x0c0a8a8a */
if(!s->budget--) { s->failed_pc=0x0c0a8a8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8a8c;
P_0c0a8a8c: /* original 432b, guest PC 0x0c0a8a8c */
if(!s->budget--) { s->failed_pc=0x0c0a8a8cu; return 0; }
target=r[3];
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
P_0c0a8a8e: /* original 6ef6, guest PC 0x0c0a8a8e */
if(!s->budget--) { s->failed_pc=0x0c0a8a8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a8a90u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a8a90u; return 0; } return 1;
P_0c0a91da: /* original 2fe6, guest PC 0x0c0a91da */
if(!s->budget--) { s->failed_pc=0x0c0a91dau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a91dc;
P_0c0a91dc: /* original e054, guest PC 0x0c0a91dc */
if(!s->budget--) { s->failed_pc=0x0c0a91dcu; return 0; }
r[0]=0x00000054u;
goto P_0c0a91de;
P_0c0a91de: /* original 2fd6, guest PC 0x0c0a91de */
if(!s->budget--) { s->failed_pc=0x0c0a91deu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a91e0;
P_0c0a91e0: /* original 2fc6, guest PC 0x0c0a91e0 */
if(!s->budget--) { s->failed_pc=0x0c0a91e0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a91e2;
P_0c0a91e2: /* original 2fb6, guest PC 0x0c0a91e2 */
if(!s->budget--) { s->failed_pc=0x0c0a91e2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a91e4;
P_0c0a91e4: /* original de2e, guest PC 0x0c0a91e4 */
if(!s->budget--) { s->failed_pc=0x0c0a91e4u; return 0; }
r[14]=read(ram,0x0c0a92a0u,4);
goto P_0c0a91e6;
P_0c0a91e6: /* original 4f22, guest PC 0x0c0a91e6 */
if(!s->budget--) { s->failed_pc=0x0c0a91e6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a91e8;
P_0c0a91e8: /* original 04ee, guest PC 0x0c0a91e8 */
if(!s->budget--) { s->failed_pc=0x0c0a91e8u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0a91ea;
P_0c0a91ea: /* original 5de4, guest PC 0x0c0a91ea */
if(!s->budget--) { s->failed_pc=0x0c0a91eau; return 0; }
r[13]=read(ram,r[14]+16,4);
goto P_0c0a91ec;
P_0c0a91ec: /* original 5445, guest PC 0x0c0a91ec */
if(!s->budget--) { s->failed_pc=0x0c0a91ecu; return 0; }
r[4]=read(ram,r[4]+20,4);
goto P_0c0a91ee;
P_0c0a91ee: /* original 74ff, guest PC 0x0c0a91ee */
if(!s->budget--) { s->failed_pc=0x0c0a91eeu; return 0; }
r[4]+=0xffffffffu;
goto P_0c0a91f0;
P_0c0a91f0: /* original 4411, guest PC 0x0c0a91f0 */
if(!s->budget--) { s->failed_pc=0x0c0a91f0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0a91f2;
P_0c0a91f2: /* original 8d01, guest PC 0x0c0a91f2 */
if(!s->budget--) { s->failed_pc=0x0c0a91f2u; return 0; }
cond=r[17]&1u;
r[11]=read(ram,r[14]+20,4);
if(cond) { goto P_0c0a91f8; }
goto P_0c0a91f6;
P_0c0a91f4: /* original 5be5, guest PC 0x0c0a91f4 */
if(!s->budget--) { s->failed_pc=0x0c0a91f4u; return 0; }
r[11]=read(ram,r[14]+20,4);
goto P_0c0a91f6;
P_0c0a91f6: /* original 944c, guest PC 0x0c0a91f6 */
if(!s->budget--) { s->failed_pc=0x0c0a91f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9292u,2);
goto P_0c0a91f8;
P_0c0a91f8: /* original 4408, guest PC 0x0c0a91f8 */
if(!s->budget--) { s->failed_pc=0x0c0a91f8u; return 0; }
r[4]<<=2;
goto P_0c0a91fa;
P_0c0a91fa: /* original dc2a, guest PC 0x0c0a91fa */
if(!s->budget--) { s->failed_pc=0x0c0a91fau; return 0; }
r[12]=read(ram,0x0c0a92a4u,4);
goto P_0c0a91fc;
P_0c0a91fc: /* original 4408, guest PC 0x0c0a91fc */
if(!s->budget--) { s->failed_pc=0x0c0a91fcu; return 0; }
r[4]<<=2;
goto P_0c0a91fe;
P_0c0a91fe: /* original 65d3, guest PC 0x0c0a91fe */
if(!s->budget--) { s->failed_pc=0x0c0a91feu; return 0; }
r[5]=r[13];
goto P_0c0a9200;
P_0c0a9200: /* original 4408, guest PC 0x0c0a9200 */
if(!s->budget--) { s->failed_pc=0x0c0a9200u; return 0; }
r[4]<<=2;
goto P_0c0a9202;
P_0c0a9202: /* original 66b3, guest PC 0x0c0a9202 */
if(!s->budget--) { s->failed_pc=0x0c0a9202u; return 0; }
r[6]=r[11];
goto P_0c0a9204;
P_0c0a9204: /* original 4400, guest PC 0x0c0a9204 */
if(!s->budget--) { s->failed_pc=0x0c0a9204u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a9206;
P_0c0a9206: /* original 3c4c, guest PC 0x0c0a9206 */
if(!s->budget--) { s->failed_pc=0x0c0a9206u; return 0; }
r[12]+=r[4];
goto P_0c0a9208;
P_0c0a9208: /* original b162, guest PC 0x0c0a9208 */
if(!s->budget--) { s->failed_pc=0x0c0a9208u; return 0; }
target=code_base|0x0c0a94d0u; r[16]=code_base|0x0c0a920cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a920cu) { target=s->pc; goto dispatch; }
goto P_0c0a920c;
P_0c0a920a: /* original 64c3, guest PC 0x0c0a920a */
if(!s->budget--) { s->failed_pc=0x0c0a920au; return 0; }
r[4]=r[12];
goto P_0c0a920c;
P_0c0a920c: /* original d326, guest PC 0x0c0a920c */
if(!s->budget--) { s->failed_pc=0x0c0a920cu; return 0; }
r[3]=read(ram,0x0c0a92a8u,4);
goto P_0c0a920e;
P_0c0a920e: /* original e028, guest PC 0x0c0a920e */
if(!s->budget--) { s->failed_pc=0x0c0a920eu; return 0; }
r[0]=0x00000028u;
goto P_0c0a9210;
P_0c0a9210: /* original 66d3, guest PC 0x0c0a9210 */
if(!s->budget--) { s->failed_pc=0x0c0a9210u; return 0; }
r[6]=r[13];
goto P_0c0a9212;
P_0c0a9212: /* original 65b3, guest PC 0x0c0a9212 */
if(!s->budget--) { s->failed_pc=0x0c0a9212u; return 0; }
r[5]=r[11];
goto P_0c0a9214;
P_0c0a9214: /* original f438, guest PC 0x0c0a9214 */
if(!s->budget--) { s->failed_pc=0x0c0a9214u; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c0a9216;
P_0c0a9216: /* original 7c40, guest PC 0x0c0a9216 */
if(!s->budget--) { s->failed_pc=0x0c0a9216u; return 0; }
r[12]+=0x00000040u;
goto P_0c0a9218;
P_0c0a9218: /* original fd47, guest PC 0x0c0a9218 */
if(!s->budget--) { s->failed_pc=0x0c0a9218u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0a921a;
P_0c0a921a: /* original b159, guest PC 0x0c0a921a */
if(!s->budget--) { s->failed_pc=0x0c0a921au; return 0; }
target=code_base|0x0c0a94d0u; r[16]=code_base|0x0c0a921eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a921eu) { target=s->pc; goto dispatch; }
goto P_0c0a921e;
P_0c0a921c: /* original 64c3, guest PC 0x0c0a921c */
if(!s->budget--) { s->failed_pc=0x0c0a921cu; return 0; }
r[4]=r[12];
goto P_0c0a921e;
P_0c0a921e: /* original d323, guest PC 0x0c0a921e */
if(!s->budget--) { s->failed_pc=0x0c0a921eu; return 0; }
r[3]=read(ram,0x0c0a92acu,4);
goto P_0c0a9220;
P_0c0a9220: /* original e028, guest PC 0x0c0a9220 */
if(!s->budget--) { s->failed_pc=0x0c0a9220u; return 0; }
r[0]=0x00000028u;
goto P_0c0a9222;
P_0c0a9222: /* original f438, guest PC 0x0c0a9222 */
if(!s->budget--) { s->failed_pc=0x0c0a9222u; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c0a9224;
P_0c0a9224: /* original fd47, guest PC 0x0c0a9224 */
if(!s->budget--) { s->failed_pc=0x0c0a9224u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0a9226;
P_0c0a9226: /* original 5de4, guest PC 0x0c0a9226 */
if(!s->budget--) { s->failed_pc=0x0c0a9226u; return 0; }
r[13]=read(ram,r[14]+16,4);
goto P_0c0a9228;
P_0c0a9228: /* original 5ee5, guest PC 0x0c0a9228 */
if(!s->budget--) { s->failed_pc=0x0c0a9228u; return 0; }
r[14]=read(ram,r[14]+20,4);
goto P_0c0a922a;
P_0c0a922a: /* original d221, guest PC 0x0c0a922a */
if(!s->budget--) { s->failed_pc=0x0c0a922au; return 0; }
r[2]=read(ram,0x0c0a92b0u,4);
goto P_0c0a922c;
P_0c0a922c: /* original 65e3, guest PC 0x0c0a922c */
if(!s->budget--) { s->failed_pc=0x0c0a922cu; return 0; }
r[5]=r[14];
goto P_0c0a922e;
P_0c0a922e: /* original 420b, guest PC 0x0c0a922e */
if(!s->budget--) { s->failed_pc=0x0c0a922eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a9232u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9232u) { target=s->pc; goto dispatch; }
goto P_0c0a9232;
P_0c0a9230: /* original 64d3, guest PC 0x0c0a9230 */
if(!s->budget--) { s->failed_pc=0x0c0a9230u; return 0; }
r[4]=r[13];
goto P_0c0a9232;
P_0c0a9232: /* original 4f26, guest PC 0x0c0a9232 */
if(!s->budget--) { s->failed_pc=0x0c0a9232u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9234;
P_0c0a9234: /* original 65d3, guest PC 0x0c0a9234 */
if(!s->budget--) { s->failed_pc=0x0c0a9234u; return 0; }
r[5]=r[13];
goto P_0c0a9236;
P_0c0a9236: /* original d31e, guest PC 0x0c0a9236 */
if(!s->budget--) { s->failed_pc=0x0c0a9236u; return 0; }
r[3]=read(ram,0x0c0a92b0u,4);
goto P_0c0a9238;
P_0c0a9238: /* original 64e3, guest PC 0x0c0a9238 */
if(!s->budget--) { s->failed_pc=0x0c0a9238u; return 0; }
r[4]=r[14];
goto P_0c0a923a;
P_0c0a923a: /* original 6bf6, guest PC 0x0c0a923a */
if(!s->budget--) { s->failed_pc=0x0c0a923au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a923c;
P_0c0a923c: /* original 6cf6, guest PC 0x0c0a923c */
if(!s->budget--) { s->failed_pc=0x0c0a923cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a923e;
P_0c0a923e: /* original 6df6, guest PC 0x0c0a923e */
if(!s->budget--) { s->failed_pc=0x0c0a923eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a9240;
P_0c0a9240: /* original 432b, guest PC 0x0c0a9240 */
if(!s->budget--) { s->failed_pc=0x0c0a9240u; return 0; }
target=r[3];
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
P_0c0a9242: /* original 6ef6, guest PC 0x0c0a9242 */
if(!s->budget--) { s->failed_pc=0x0c0a9242u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a9244u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a9244u; return 0; } return 1;
P_0c0a926a: /* original 9013, guest PC 0x0c0a926a */
if(!s->budget--) { s->failed_pc=0x0c0a926au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9294u,2);
goto P_0c0a926c;
P_0c0a926c: /* original e601, guest PC 0x0c0a926c */
if(!s->budget--) { s->failed_pc=0x0c0a926cu; return 0; }
r[6]=0x00000001u;
goto P_0c0a926e;
P_0c0a926e: /* original d715, guest PC 0x0c0a926e */
if(!s->budget--) { s->failed_pc=0x0c0a926eu; return 0; }
r[7]=read(ram,0x0c0a92c4u,4);
goto P_0c0a9270;
P_0c0a9270: /* original 0764, guest PC 0x0c0a9270 */
if(!s->budget--) { s->failed_pc=0x0c0a9270u; return 0; }
write(ram,r[7]+r[0],r[6],1);
goto P_0c0a9272;
P_0c0a9272: /* original 6542, guest PC 0x0c0a9272 */
if(!s->budget--) { s->failed_pc=0x0c0a9272u; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c0a9274;
P_0c0a9274: /* original d310, guest PC 0x0c0a9274 */
if(!s->budget--) { s->failed_pc=0x0c0a9274u; return 0; }
r[3]=read(ram,0x0c0a92b8u,4);
goto P_0c0a9276;
P_0c0a9276: /* original 2538, guest PC 0x0c0a9276 */
if(!s->budget--) { s->failed_pc=0x0c0a9276u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0a9278;
P_0c0a9278: /* original 8b07, guest PC 0x0c0a9278 */
if(!s->budget--) { s->failed_pc=0x0c0a9278u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a928a; }
goto P_0c0a927a;
P_0c0a927a: /* original e048, guest PC 0x0c0a927a */
if(!s->budget--) { s->failed_pc=0x0c0a927au; return 0; }
r[0]=0x00000048u;
goto P_0c0a927c;
P_0c0a927c: /* original d30f, guest PC 0x0c0a927c */
if(!s->budget--) { s->failed_pc=0x0c0a927cu; return 0; }
r[3]=read(ram,0x0c0a92bcu,4);
goto P_0c0a927e;
P_0c0a927e: /* original 044e, guest PC 0x0c0a927e */
if(!s->budget--) { s->failed_pc=0x0c0a927eu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c0a9280;
P_0c0a9280: /* original 2348, guest PC 0x0c0a9280 */
if(!s->budget--) { s->failed_pc=0x0c0a9280u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0a9282;
P_0c0a9282: /* original 8b02, guest PC 0x0c0a9282 */
if(!s->budget--) { s->failed_pc=0x0c0a9282u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a928a; }
goto P_0c0a9284;
P_0c0a9284: /* original d50e, guest PC 0x0c0a9284 */
if(!s->budget--) { s->failed_pc=0x0c0a9284u; return 0; }
r[5]=read(ram,0x0c0a92c0u,4);
goto P_0c0a9286;
P_0c0a9286: /* original 2548, guest PC 0x0c0a9286 */
if(!s->budget--) { s->failed_pc=0x0c0a9286u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[4])==0)!=0);
goto P_0c0a9288;
P_0c0a9288: /* original 8b01, guest PC 0x0c0a9288 */
if(!s->budget--) { s->failed_pc=0x0c0a9288u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a928e; }
goto P_0c0a928a;
P_0c0a928a: /* original 9003, guest PC 0x0c0a928a */
if(!s->budget--) { s->failed_pc=0x0c0a928au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9294u,2);
goto P_0c0a928c;
P_0c0a928c: /* original 0764, guest PC 0x0c0a928c */
if(!s->budget--) { s->failed_pc=0x0c0a928cu; return 0; }
write(ram,r[7]+r[0],r[6],1);
goto P_0c0a928e;
P_0c0a928e: /* original 000b, guest PC 0x0c0a928e */
if(!s->budget--) { s->failed_pc=0x0c0a928eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a9290: /* original 0009, guest PC 0x0c0a9290 */
if(!s->budget--) { s->failed_pc=0x0c0a9290u; return 0; }
if(!vf3_matrix_family(0x0c0a9292u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a9292u; return 0; } return 1;
P_0c0a9444: /* original 2fe6, guest PC 0x0c0a9444 */
if(!s->budget--) { s->failed_pc=0x0c0a9444u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9446;
P_0c0a9446: /* original 6e43, guest PC 0x0c0a9446 */
if(!s->budget--) { s->failed_pc=0x0c0a9446u; return 0; }
r[14]=r[4];
goto P_0c0a9448;
P_0c0a9448: /* original d41e, guest PC 0x0c0a9448 */
if(!s->budget--) { s->failed_pc=0x0c0a9448u; return 0; }
r[4]=read(ram,0x0c0a94c4u,4);
goto P_0c0a944a;
P_0c0a944a: /* original 902e, guest PC 0x0c0a944a */
if(!s->budget--) { s->failed_pc=0x0c0a944au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a94aau,2);
goto P_0c0a944c;
P_0c0a944c: /* original 5645, guest PC 0x0c0a944c */
if(!s->budget--) { s->failed_pc=0x0c0a944cu; return 0; }
r[6]=read(ram,r[4]+20,4);
goto P_0c0a944e;
P_0c0a944e: /* original 5544, guest PC 0x0c0a944e */
if(!s->budget--) { s->failed_pc=0x0c0a944eu; return 0; }
r[5]=read(ram,r[4]+16,4);
goto P_0c0a9450;
P_0c0a9450: /* original e401, guest PC 0x0c0a9450 */
if(!s->budget--) { s->failed_pc=0x0c0a9450u; return 0; }
r[4]=0x00000001u;
goto P_0c0a9452;
P_0c0a9452: /* original 4f22, guest PC 0x0c0a9452 */
if(!s->budget--) { s->failed_pc=0x0c0a9452u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a9454;
P_0c0a9454: /* original 0544, guest PC 0x0c0a9454 */
if(!s->budget--) { s->failed_pc=0x0c0a9454u; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c0a9456;
P_0c0a9456: /* original 0644, guest PC 0x0c0a9456 */
if(!s->budget--) { s->failed_pc=0x0c0a9456u; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c0a9458;
P_0c0a9458: /* original d31b, guest PC 0x0c0a9458 */
if(!s->budget--) { s->failed_pc=0x0c0a9458u; return 0; }
r[3]=read(ram,0x0c0a94c8u,4);
goto P_0c0a945a;
P_0c0a945a: /* original 6530, guest PC 0x0c0a945a */
if(!s->budget--) { s->failed_pc=0x0c0a945au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[5]=tmp;
goto P_0c0a945c;
P_0c0a945c: /* original 605e, guest PC 0x0c0a945c */
if(!s->budget--) { s->failed_pc=0x0c0a945cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c0a945e;
P_0c0a945e: /* original 8802, guest PC 0x0c0a945e */
if(!s->budget--) { s->failed_pc=0x0c0a945eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a9460;
P_0c0a9460: /* original 8b1e, guest PC 0x0c0a9460 */
if(!s->budget--) { s->failed_pc=0x0c0a9460u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a94a0; }
goto P_0c0a9462;
P_0c0a9462: /* original e061, guest PC 0x0c0a9462 */
if(!s->budget--) { s->failed_pc=0x0c0a9462u; return 0; }
r[0]=0x00000061u;
goto P_0c0a9464;
P_0c0a9464: /* original 05ec, guest PC 0x0c0a9464 */
if(!s->budget--) { s->failed_pc=0x0c0a9464u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a9466;
P_0c0a9466: /* original d019, guest PC 0x0c0a9466 */
if(!s->budget--) { s->failed_pc=0x0c0a9466u; return 0; }
r[0]=read(ram,0x0c0a94ccu,4);
goto P_0c0a9468;
P_0c0a9468: /* original 4508, guest PC 0x0c0a9468 */
if(!s->budget--) { s->failed_pc=0x0c0a9468u; return 0; }
r[5]<<=2;
goto P_0c0a946a;
P_0c0a946a: /* original 4509, guest PC 0x0c0a946a */
if(!s->budget--) { s->failed_pc=0x0c0a946au; return 0; }
r[5]>>=2;
goto P_0c0a946c;
P_0c0a946c: /* original 4508, guest PC 0x0c0a946c */
if(!s->budget--) { s->failed_pc=0x0c0a946cu; return 0; }
r[5]<<=2;
goto P_0c0a946e;
P_0c0a946e: /* original 055e, guest PC 0x0c0a946e */
if(!s->budget--) { s->failed_pc=0x0c0a946eu; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c0a9470;
P_0c0a9470: /* original e03c, guest PC 0x0c0a9470 */
if(!s->budget--) { s->failed_pc=0x0c0a9470u; return 0; }
r[0]=0x0000003cu;
goto P_0c0a9472;
P_0c0a9472: /* original 0e55, guest PC 0x0c0a9472 */
if(!s->budget--) { s->failed_pc=0x0c0a9472u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0a9474;
P_0c0a9474: /* original e03e, guest PC 0x0c0a9474 */
if(!s->budget--) { s->failed_pc=0x0c0a9474u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a9476;
P_0c0a9476: /* original 1e5d, guest PC 0x0c0a9476 */
if(!s->budget--) { s->failed_pc=0x0c0a9476u; return 0; }
write(ram,r[14]+52,r[5],4);
goto P_0c0a9478;
P_0c0a9478: /* original 0e45, guest PC 0x0c0a9478 */
if(!s->budget--) { s->failed_pc=0x0c0a9478u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a947a;
P_0c0a947a: /* original e010, guest PC 0x0c0a947a */
if(!s->budget--) { s->failed_pc=0x0c0a947au; return 0; }
r[0]=0x00000010u;
goto P_0c0a947c;
P_0c0a947c: /* original f4e6, guest PC 0x0c0a947c */
if(!s->budget--) { s->failed_pc=0x0c0a947cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a947e;
P_0c0a947e: /* original e018, guest PC 0x0c0a947e */
if(!s->budget--) { s->failed_pc=0x0c0a947eu; return 0; }
r[0]=0x00000018u;
goto P_0c0a9480;
P_0c0a9480: /* original d30f, guest PC 0x0c0a9480 */
if(!s->budget--) { s->failed_pc=0x0c0a9480u; return 0; }
r[3]=read(ram,0x0c0a94c0u,4);
goto P_0c0a9482;
P_0c0a9482: /* original f5e6, guest PC 0x0c0a9482 */
if(!s->budget--) { s->failed_pc=0x0c0a9482u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a9484;
P_0c0a9484: /* original 430b, guest PC 0x0c0a9484 */
if(!s->budget--) { s->failed_pc=0x0c0a9484u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9488u;
fr[5]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9488u) { target=s->pc; goto dispatch; }
goto P_0c0a9488;
P_0c0a9486: /* original f54d, guest PC 0x0c0a9486 */
if(!s->budget--) { s->failed_pc=0x0c0a9486u; return 0; }
fr[5]^=0x80000000u;
goto P_0c0a9488;
P_0c0a9488: /* original e024, guest PC 0x0c0a9488 */
if(!s->budget--) { s->failed_pc=0x0c0a9488u; return 0; }
r[0]=0x00000024u;
goto P_0c0a948a;
P_0c0a948a: /* original f48d, guest PC 0x0c0a948a */
if(!s->budget--) { s->failed_pc=0x0c0a948au; return 0; }
fr[4]=0;
goto P_0c0a948c;
P_0c0a948c: /* original f50c, guest PC 0x0c0a948c */
if(!s->budget--) { s->failed_pc=0x0c0a948cu; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c0a948e;
P_0c0a948e: /* original fe47, guest PC 0x0c0a948e */
if(!s->budget--) { s->failed_pc=0x0c0a948eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9490;
P_0c0a9490: /* original e028, guest PC 0x0c0a9490 */
if(!s->budget--) { s->failed_pc=0x0c0a9490u; return 0; }
r[0]=0x00000028u;
goto P_0c0a9492;
P_0c0a9492: /* original fe47, guest PC 0x0c0a9492 */
if(!s->budget--) { s->failed_pc=0x0c0a9492u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9494;
P_0c0a9494: /* original e02c, guest PC 0x0c0a9494 */
if(!s->budget--) { s->failed_pc=0x0c0a9494u; return 0; }
r[0]=0x0000002cu;
goto P_0c0a9496;
P_0c0a9496: /* original fe47, guest PC 0x0c0a9496 */
if(!s->budget--) { s->failed_pc=0x0c0a9496u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9498;
P_0c0a9498: /* original e014, guest PC 0x0c0a9498 */
if(!s->budget--) { s->failed_pc=0x0c0a9498u; return 0; }
r[0]=0x00000014u;
goto P_0c0a949a;
P_0c0a949a: /* original fe57, guest PC 0x0c0a949a */
if(!s->budget--) { s->failed_pc=0x0c0a949au; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a949c;
P_0c0a949c: /* original 9006, guest PC 0x0c0a949c */
if(!s->budget--) { s->failed_pc=0x0c0a949cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a94acu,2);
goto P_0c0a949e;
P_0c0a949e: /* original fe57, guest PC 0x0c0a949e */
if(!s->budget--) { s->failed_pc=0x0c0a949eu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a94a0;
P_0c0a94a0: /* original 4f26, guest PC 0x0c0a94a0 */
if(!s->budget--) { s->failed_pc=0x0c0a94a0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a94a2;
P_0c0a94a2: /* original 000b, guest PC 0x0c0a94a2 */
if(!s->budget--) { s->failed_pc=0x0c0a94a2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a94a4: /* original 6ef6, guest PC 0x0c0a94a4 */
if(!s->budget--) { s->failed_pc=0x0c0a94a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a94a6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a94a6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
