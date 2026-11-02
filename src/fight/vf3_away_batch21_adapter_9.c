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
int vf3_away_batch21_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09fc8eu: goto P_0c09fc8e;
case 0x0c09fc90u: goto P_0c09fc90;
case 0x0c09fc92u: goto P_0c09fc92;
case 0x0c09fc94u: goto P_0c09fc94;
case 0x0c09fc96u: goto P_0c09fc96;
case 0x0c09fc98u: goto P_0c09fc98;
case 0x0c09fc9au: goto P_0c09fc9a;
case 0x0c09fc9cu: goto P_0c09fc9c;
case 0x0c09fc9eu: goto P_0c09fc9e;
case 0x0c09fca0u: goto P_0c09fca0;
case 0x0c09fca2u: goto P_0c09fca2;
case 0x0c09fca4u: goto P_0c09fca4;
case 0x0c09fca6u: goto P_0c09fca6;
case 0x0c09fca8u: goto P_0c09fca8;
case 0x0c09fcaau: goto P_0c09fcaa;
case 0x0c09fcacu: goto P_0c09fcac;
case 0x0c09fcaeu: goto P_0c09fcae;
case 0x0c09fcb0u: goto P_0c09fcb0;
case 0x0c09fcb2u: goto P_0c09fcb2;
case 0x0c09fcb4u: goto P_0c09fcb4;
case 0x0c09fcb6u: goto P_0c09fcb6;
case 0x0c09fcb8u: goto P_0c09fcb8;
case 0x0c09fcbau: goto P_0c09fcba;
case 0x0c09fcbcu: goto P_0c09fcbc;
case 0x0c09fcbeu: goto P_0c09fcbe;
case 0x0c09fcc0u: goto P_0c09fcc0;
case 0x0c09fcc2u: goto P_0c09fcc2;
case 0x0c09fcc4u: goto P_0c09fcc4;
case 0x0c09fcc6u: goto P_0c09fcc6;
case 0x0c09fcc8u: goto P_0c09fcc8;
case 0x0c09fccau: goto P_0c09fcca;
case 0x0c09fcccu: goto P_0c09fccc;
case 0x0c09fcceu: goto P_0c09fcce;
case 0x0c09fcd0u: goto P_0c09fcd0;
case 0x0c09fcf4u: goto P_0c09fcf4;
case 0x0c09fcf6u: goto P_0c09fcf6;
case 0x0c09fcf8u: goto P_0c09fcf8;
case 0x0c09fcfau: goto P_0c09fcfa;
case 0x0c09fcfcu: goto P_0c09fcfc;
case 0x0c09fcfeu: goto P_0c09fcfe;
case 0x0c09fd00u: goto P_0c09fd00;
case 0x0c09fd02u: goto P_0c09fd02;
case 0x0c09fd04u: goto P_0c09fd04;
case 0x0c09fd06u: goto P_0c09fd06;
case 0x0c09fd08u: goto P_0c09fd08;
case 0x0c09fd0au: goto P_0c09fd0a;
case 0x0c09fd0cu: goto P_0c09fd0c;
case 0x0c09fd0eu: goto P_0c09fd0e;
case 0x0c09fd10u: goto P_0c09fd10;
case 0x0c09fd12u: goto P_0c09fd12;
case 0x0c09fd14u: goto P_0c09fd14;
case 0x0c09fd16u: goto P_0c09fd16;
case 0x0c09fd18u: goto P_0c09fd18;
case 0x0c09fd1au: goto P_0c09fd1a;
case 0x0c09fd1cu: goto P_0c09fd1c;
case 0x0c09fd1eu: goto P_0c09fd1e;
case 0x0c09fd20u: goto P_0c09fd20;
case 0x0c09fd22u: goto P_0c09fd22;
case 0x0c09fd24u: goto P_0c09fd24;
case 0x0c09fd26u: goto P_0c09fd26;
case 0x0c09fd28u: goto P_0c09fd28;
case 0x0c09fd2au: goto P_0c09fd2a;
case 0x0c09fd2cu: goto P_0c09fd2c;
case 0x0c09fd2eu: goto P_0c09fd2e;
case 0x0c09fd30u: goto P_0c09fd30;
case 0x0c09fd32u: goto P_0c09fd32;
case 0x0c09fd34u: goto P_0c09fd34;
case 0x0c09fd36u: goto P_0c09fd36;
case 0x0c09fd38u: goto P_0c09fd38;
case 0x0c09fd3au: goto P_0c09fd3a;
case 0x0c09fd3cu: goto P_0c09fd3c;
case 0x0c09fd3eu: goto P_0c09fd3e;
case 0x0c09fd40u: goto P_0c09fd40;
case 0x0c09fd42u: goto P_0c09fd42;
case 0x0c09fd44u: goto P_0c09fd44;
case 0x0c09fd46u: goto P_0c09fd46;
case 0x0c09fd48u: goto P_0c09fd48;
case 0x0c09fd4au: goto P_0c09fd4a;
case 0x0c09fd4cu: goto P_0c09fd4c;
case 0x0c09fd4eu: goto P_0c09fd4e;
case 0x0c09fd50u: goto P_0c09fd50;
case 0x0c09fd52u: goto P_0c09fd52;
case 0x0c09fd54u: goto P_0c09fd54;
case 0x0c09fd56u: goto P_0c09fd56;
case 0x0c09fd58u: goto P_0c09fd58;
case 0x0c09fd5au: goto P_0c09fd5a;
case 0x0c09fd5cu: goto P_0c09fd5c;
case 0x0c09fd5eu: goto P_0c09fd5e;
case 0x0c09fd60u: goto P_0c09fd60;
case 0x0c09fd62u: goto P_0c09fd62;
case 0x0c09fd64u: goto P_0c09fd64;
case 0x0c09fd66u: goto P_0c09fd66;
case 0x0c09fd68u: goto P_0c09fd68;
case 0x0c09fd6au: goto P_0c09fd6a;
case 0x0c09fd6cu: goto P_0c09fd6c;
case 0x0c09fd6eu: goto P_0c09fd6e;
case 0x0c09fd70u: goto P_0c09fd70;
case 0x0c09fd72u: goto P_0c09fd72;
case 0x0c09fd74u: goto P_0c09fd74;
case 0x0c09fd76u: goto P_0c09fd76;
case 0x0c09fd78u: goto P_0c09fd78;
case 0x0c09fd7au: goto P_0c09fd7a;
case 0x0c09fd7cu: goto P_0c09fd7c;
case 0x0c09fd7eu: goto P_0c09fd7e;
case 0x0c09fd80u: goto P_0c09fd80;
case 0x0c09fd82u: goto P_0c09fd82;
case 0x0c09fd84u: goto P_0c09fd84;
case 0x0c09fd86u: goto P_0c09fd86;
case 0x0c09fd88u: goto P_0c09fd88;
case 0x0c09fd8au: goto P_0c09fd8a;
case 0x0c09fd8cu: goto P_0c09fd8c;
case 0x0c09fd8eu: goto P_0c09fd8e;
case 0x0c09fd90u: goto P_0c09fd90;
case 0x0c09fd92u: goto P_0c09fd92;
case 0x0c09fd94u: goto P_0c09fd94;
case 0x0c09fd96u: goto P_0c09fd96;
case 0x0c09fd98u: goto P_0c09fd98;
case 0x0c09fd9au: goto P_0c09fd9a;
case 0x0c09fd9cu: goto P_0c09fd9c;
case 0x0c09fd9eu: goto P_0c09fd9e;
case 0x0c09fda0u: goto P_0c09fda0;
case 0x0c09fda2u: goto P_0c09fda2;
case 0x0c09fda4u: goto P_0c09fda4;
case 0x0c09fda6u: goto P_0c09fda6;
case 0x0c09fda8u: goto P_0c09fda8;
case 0x0c09fdaau: goto P_0c09fdaa;
case 0x0c09fdacu: goto P_0c09fdac;
case 0x0c09fdaeu: goto P_0c09fdae;
case 0x0c09fdb0u: goto P_0c09fdb0;
case 0x0c09fdb2u: goto P_0c09fdb2;
case 0x0c09fdb4u: goto P_0c09fdb4;
case 0x0c09fdb6u: goto P_0c09fdb6;
case 0x0c09fdb8u: goto P_0c09fdb8;
case 0x0c09fdbau: goto P_0c09fdba;
case 0x0c09fdbcu: goto P_0c09fdbc;
case 0x0c09fdbeu: goto P_0c09fdbe;
case 0x0c09fdc0u: goto P_0c09fdc0;
case 0x0c09fdc2u: goto P_0c09fdc2;
case 0x0c09fdc4u: goto P_0c09fdc4;
case 0x0c09fdc6u: goto P_0c09fdc6;
case 0x0c09fdc8u: goto P_0c09fdc8;
case 0x0c09fdcau: goto P_0c09fdca;
case 0x0c09fdccu: goto P_0c09fdcc;
case 0x0c09fdceu: goto P_0c09fdce;
case 0x0c09fdd0u: goto P_0c09fdd0;
case 0x0c09fdd2u: goto P_0c09fdd2;
case 0x0c09fdd4u: goto P_0c09fdd4;
case 0x0c09fdd6u: goto P_0c09fdd6;
case 0x0c09fdd8u: goto P_0c09fdd8;
case 0x0c09fddau: goto P_0c09fdda;
case 0x0c09fddcu: goto P_0c09fddc;
case 0x0c09fddeu: goto P_0c09fdde;
case 0x0c09fde0u: goto P_0c09fde0;
case 0x0c09fde2u: goto P_0c09fde2;
case 0x0c09fde4u: goto P_0c09fde4;
case 0x0c09fde6u: goto P_0c09fde6;
case 0x0c09fde8u: goto P_0c09fde8;
case 0x0c09fdeau: goto P_0c09fdea;
case 0x0c09fdecu: goto P_0c09fdec;
case 0x0c09fdeeu: goto P_0c09fdee;
case 0x0c09fdf0u: goto P_0c09fdf0;
case 0x0c09fdf2u: goto P_0c09fdf2;
case 0x0c09fdf4u: goto P_0c09fdf4;
case 0x0c09fdf6u: goto P_0c09fdf6;
case 0x0c09fdf8u: goto P_0c09fdf8;
case 0x0c09fdfau: goto P_0c09fdfa;
case 0x0c09fdfcu: goto P_0c09fdfc;
case 0x0c09fdfeu: goto P_0c09fdfe;
case 0x0c09fe00u: goto P_0c09fe00;
case 0x0c09fe02u: goto P_0c09fe02;
case 0x0c09fe04u: goto P_0c09fe04;
case 0x0c09fe06u: goto P_0c09fe06;
case 0x0c09fe08u: goto P_0c09fe08;
case 0x0c09fe0au: goto P_0c09fe0a;
case 0x0c09fe0cu: goto P_0c09fe0c;
case 0x0c09fe0eu: goto P_0c09fe0e;
case 0x0c09fe10u: goto P_0c09fe10;
case 0x0c09fe12u: goto P_0c09fe12;
case 0x0c09fe14u: goto P_0c09fe14;
case 0x0c09fe16u: goto P_0c09fe16;
case 0x0c09fe18u: goto P_0c09fe18;
case 0x0c09fe1au: goto P_0c09fe1a;
case 0x0c09fe1cu: goto P_0c09fe1c;
case 0x0c09fe1eu: goto P_0c09fe1e;
case 0x0c09fe20u: goto P_0c09fe20;
case 0x0c09fe22u: goto P_0c09fe22;
case 0x0c09fe24u: goto P_0c09fe24;
case 0x0c09fe26u: goto P_0c09fe26;
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
case 0x0c0a92c8u: goto P_0c0a92c8;
case 0x0c0a92cau: goto P_0c0a92ca;
case 0x0c0a92ccu: goto P_0c0a92cc;
case 0x0c0a92ceu: goto P_0c0a92ce;
case 0x0c0a92d0u: goto P_0c0a92d0;
case 0x0c0a92d2u: goto P_0c0a92d2;
case 0x0c0a92d4u: goto P_0c0a92d4;
case 0x0c0a92d6u: goto P_0c0a92d6;
case 0x0c0a92d8u: goto P_0c0a92d8;
case 0x0c0a92dau: goto P_0c0a92da;
case 0x0c0a92dcu: goto P_0c0a92dc;
case 0x0c0a92deu: goto P_0c0a92de;
case 0x0c0a92e0u: goto P_0c0a92e0;
case 0x0c0a92e2u: goto P_0c0a92e2;
case 0x0c0a92e4u: goto P_0c0a92e4;
case 0x0c0a92e6u: goto P_0c0a92e6;
case 0x0c0a92e8u: goto P_0c0a92e8;
case 0x0c0a92eau: goto P_0c0a92ea;
case 0x0c0a92ecu: goto P_0c0a92ec;
case 0x0c0a92eeu: goto P_0c0a92ee;
case 0x0c0a92f0u: goto P_0c0a92f0;
case 0x0c0a92f2u: goto P_0c0a92f2;
case 0x0c0a92f4u: goto P_0c0a92f4;
case 0x0c0a92f6u: goto P_0c0a92f6;
case 0x0c0a92f8u: goto P_0c0a92f8;
case 0x0c0a92fau: goto P_0c0a92fa;
case 0x0c0a92fcu: goto P_0c0a92fc;
case 0x0c0a92feu: goto P_0c0a92fe;
case 0x0c0a9300u: goto P_0c0a9300;
case 0x0c0a9302u: goto P_0c0a9302;
case 0x0c0a9304u: goto P_0c0a9304;
case 0x0c0a9306u: goto P_0c0a9306;
case 0x0c0a9308u: goto P_0c0a9308;
case 0x0c0a930au: goto P_0c0a930a;
case 0x0c0a930cu: goto P_0c0a930c;
case 0x0c0a930eu: goto P_0c0a930e;
case 0x0c0a9310u: goto P_0c0a9310;
case 0x0c0a9312u: goto P_0c0a9312;
case 0x0c0a9314u: goto P_0c0a9314;
case 0x0c0a9316u: goto P_0c0a9316;
case 0x0c0a9318u: goto P_0c0a9318;
case 0x0c0a931au: goto P_0c0a931a;
case 0x0c0a931cu: goto P_0c0a931c;
case 0x0c0a931eu: goto P_0c0a931e;
case 0x0c0a9320u: goto P_0c0a9320;
case 0x0c0a9322u: goto P_0c0a9322;
case 0x0c0a9324u: goto P_0c0a9324;
case 0x0c0a9326u: goto P_0c0a9326;
case 0x0c0a9328u: goto P_0c0a9328;
case 0x0c0a932au: goto P_0c0a932a;
case 0x0c0a932cu: goto P_0c0a932c;
case 0x0c0a932eu: goto P_0c0a932e;
case 0x0c0a9330u: goto P_0c0a9330;
case 0x0c0a9332u: goto P_0c0a9332;
case 0x0c0a9334u: goto P_0c0a9334;
case 0x0c0a9336u: goto P_0c0a9336;
case 0x0c0a9338u: goto P_0c0a9338;
case 0x0c0a933au: goto P_0c0a933a;
case 0x0c0a933cu: goto P_0c0a933c;
case 0x0c0a933eu: goto P_0c0a933e;
case 0x0c0a9340u: goto P_0c0a9340;
case 0x0c0a9342u: goto P_0c0a9342;
case 0x0c0a9344u: goto P_0c0a9344;
case 0x0c0a9346u: goto P_0c0a9346;
case 0x0c0a9348u: goto P_0c0a9348;
case 0x0c0a934au: goto P_0c0a934a;
case 0x0c0a934cu: goto P_0c0a934c;
case 0x0c0a934eu: goto P_0c0a934e;
case 0x0c0a9350u: goto P_0c0a9350;
case 0x0c0a9352u: goto P_0c0a9352;
case 0x0c0a9354u: goto P_0c0a9354;
case 0x0c0a9356u: goto P_0c0a9356;
case 0x0c0a9358u: goto P_0c0a9358;
case 0x0c0a935au: goto P_0c0a935a;
case 0x0c0a935cu: goto P_0c0a935c;
case 0x0c0a935eu: goto P_0c0a935e;
case 0x0c0a9360u: goto P_0c0a9360;
case 0x0c0a9362u: goto P_0c0a9362;
case 0x0c0a9364u: goto P_0c0a9364;
case 0x0c0a9366u: goto P_0c0a9366;
case 0x0c0a9368u: goto P_0c0a9368;
case 0x0c0a936au: goto P_0c0a936a;
case 0x0c0a936cu: goto P_0c0a936c;
case 0x0c0a936eu: goto P_0c0a936e;
case 0x0c0a9370u: goto P_0c0a9370;
case 0x0c0a9372u: goto P_0c0a9372;
case 0x0c0a9374u: goto P_0c0a9374;
case 0x0c0a9376u: goto P_0c0a9376;
case 0x0c0a9378u: goto P_0c0a9378;
case 0x0c0a937au: goto P_0c0a937a;
case 0x0c0a937cu: goto P_0c0a937c;
case 0x0c0a937eu: goto P_0c0a937e;
case 0x0c0a9380u: goto P_0c0a9380;
case 0x0c0a9382u: goto P_0c0a9382;
case 0x0c0a9384u: goto P_0c0a9384;
case 0x0c0a9386u: goto P_0c0a9386;
case 0x0c0a9388u: goto P_0c0a9388;
case 0x0c0a938au: goto P_0c0a938a;
case 0x0c0a938cu: goto P_0c0a938c;
case 0x0c0a938eu: goto P_0c0a938e;
case 0x0c0a9390u: goto P_0c0a9390;
case 0x0c0a9392u: goto P_0c0a9392;
case 0x0c0a9394u: goto P_0c0a9394;
case 0x0c0a9396u: goto P_0c0a9396;
case 0x0c0a9398u: goto P_0c0a9398;
case 0x0c0a939au: goto P_0c0a939a;
case 0x0c0a939cu: goto P_0c0a939c;
case 0x0c0a93c8u: goto P_0c0a93c8;
case 0x0c0a93cau: goto P_0c0a93ca;
case 0x0c0a93ccu: goto P_0c0a93cc;
case 0x0c0a93ceu: goto P_0c0a93ce;
case 0x0c0a93d0u: goto P_0c0a93d0;
case 0x0c0a93d2u: goto P_0c0a93d2;
case 0x0c0a93d4u: goto P_0c0a93d4;
case 0x0c0a93d6u: goto P_0c0a93d6;
case 0x0c0a93d8u: goto P_0c0a93d8;
case 0x0c0a93dau: goto P_0c0a93da;
case 0x0c0a93dcu: goto P_0c0a93dc;
case 0x0c0a93deu: goto P_0c0a93de;
case 0x0c0a93e0u: goto P_0c0a93e0;
case 0x0c0a93e2u: goto P_0c0a93e2;
case 0x0c0a93e4u: goto P_0c0a93e4;
case 0x0c0a93e6u: goto P_0c0a93e6;
case 0x0c0a93e8u: goto P_0c0a93e8;
case 0x0c0a93eau: goto P_0c0a93ea;
case 0x0c0a93ecu: goto P_0c0a93ec;
case 0x0c0a93eeu: goto P_0c0a93ee;
case 0x0c0a93f0u: goto P_0c0a93f0;
case 0x0c0a93f2u: goto P_0c0a93f2;
case 0x0c0a93f4u: goto P_0c0a93f4;
case 0x0c0a93f6u: goto P_0c0a93f6;
case 0x0c0a93f8u: goto P_0c0a93f8;
case 0x0c0a93fau: goto P_0c0a93fa;
case 0x0c0a93fcu: goto P_0c0a93fc;
case 0x0c0a93feu: goto P_0c0a93fe;
case 0x0c0a9400u: goto P_0c0a9400;
case 0x0c0a9402u: goto P_0c0a9402;
case 0x0c0a9404u: goto P_0c0a9404;
case 0x0c0a9406u: goto P_0c0a9406;
case 0x0c0a9408u: goto P_0c0a9408;
case 0x0c0a940au: goto P_0c0a940a;
case 0x0c0a940cu: goto P_0c0a940c;
case 0x0c0a940eu: goto P_0c0a940e;
case 0x0c0a9410u: goto P_0c0a9410;
case 0x0c0a9412u: goto P_0c0a9412;
case 0x0c0a9414u: goto P_0c0a9414;
case 0x0c0a9416u: goto P_0c0a9416;
case 0x0c0a9418u: goto P_0c0a9418;
case 0x0c0a941au: goto P_0c0a941a;
case 0x0c0a941cu: goto P_0c0a941c;
case 0x0c0a941eu: goto P_0c0a941e;
case 0x0c0a9420u: goto P_0c0a9420;
case 0x0c0a9422u: goto P_0c0a9422;
case 0x0c0a9424u: goto P_0c0a9424;
case 0x0c0a9426u: goto P_0c0a9426;
case 0x0c0a9428u: goto P_0c0a9428;
case 0x0c0a942au: goto P_0c0a942a;
case 0x0c0a942cu: goto P_0c0a942c;
case 0x0c0a942eu: goto P_0c0a942e;
case 0x0c0a9430u: goto P_0c0a9430;
case 0x0c0a9432u: goto P_0c0a9432;
case 0x0c0a9434u: goto P_0c0a9434;
case 0x0c0a9436u: goto P_0c0a9436;
case 0x0c0a9438u: goto P_0c0a9438;
case 0x0c0a943au: goto P_0c0a943a;
case 0x0c0a943cu: goto P_0c0a943c;
case 0x0c0a943eu: goto P_0c0a943e;
case 0x0c0a9440u: goto P_0c0a9440;
case 0x0c0a9442u: goto P_0c0a9442;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09fc8e: /* original 9024, guest PC 0x0c09fc8e */
if(!s->budget--) { s->failed_pc=0x0c09fc8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fcdau,2);
goto P_0c09fc90;
P_0c09fc90: /* original 9224, guest PC 0x0c09fc90 */
if(!s->budget--) { s->failed_pc=0x0c09fc90u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fcdcu,2);
goto P_0c09fc92;
P_0c09fc92: /* original 034d, guest PC 0x0c09fc92 */
if(!s->budget--) { s->failed_pc=0x0c09fc92u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09fc94;
P_0c09fc94: /* original 633d, guest PC 0x0c09fc94 */
if(!s->budget--) { s->failed_pc=0x0c09fc94u; return 0; }
r[3]=r[3]&65535u;
goto P_0c09fc96;
P_0c09fc96: /* original 3320, guest PC 0x0c09fc96 */
if(!s->budget--) { s->failed_pc=0x0c09fc96u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c09fc98;
P_0c09fc98: /* original 8b05, guest PC 0x0c09fc98 */
if(!s->budget--) { s->failed_pc=0x0c09fc98u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09fca6; }
goto P_0c09fc9a;
P_0c09fc9a: /* original 9120, guest PC 0x0c09fc9a */
if(!s->budget--) { s->failed_pc=0x0c09fc9au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fcdeu,2);
goto P_0c09fc9c;
P_0c09fc9c: /* original e008, guest PC 0x0c09fc9c */
if(!s->budget--) { s->failed_pc=0x0c09fc9cu; return 0; }
r[0]=0x00000008u;
goto P_0c09fc9e;
P_0c09fc9e: /* original f48d, guest PC 0x0c09fc9e */
if(!s->budget--) { s->failed_pc=0x0c09fc9eu; return 0; }
fr[4]=0;
goto P_0c09fca0;
P_0c09fca0: /* original 341c, guest PC 0x0c09fca0 */
if(!s->budget--) { s->failed_pc=0x0c09fca0u; return 0; }
r[4]+=r[1];
goto P_0c09fca2;
P_0c09fca2: /* original f44a, guest PC 0x0c09fca2 */
if(!s->budget--) { s->failed_pc=0x0c09fca2u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c09fca4;
P_0c09fca4: /* original f447, guest PC 0x0c09fca4 */
if(!s->budget--) { s->failed_pc=0x0c09fca4u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09fca6;
P_0c09fca6: /* original 000b, guest PC 0x0c09fca6 */
if(!s->budget--) { s->failed_pc=0x0c09fca6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09fca8: /* original 0009, guest PC 0x0c09fca8 */
if(!s->budget--) { s->failed_pc=0x0c09fca8u; return 0; }
goto P_0c09fcaa;
P_0c09fcaa: /* original c711, guest PC 0x0c09fcaa */
if(!s->budget--) { s->failed_pc=0x0c09fcaau; return 0; }
r[0]=code_base|0x0009fcf0u;
goto P_0c09fcac;
P_0c09fcac: /* original f448, guest PC 0x0c09fcac */
if(!s->budget--) { s->failed_pc=0x0c09fcacu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c09fcae;
P_0c09fcae: /* original f508, guest PC 0x0c09fcae */
if(!s->budget--) { s->failed_pc=0x0c09fcaeu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c09fcb0;
P_0c09fcb0: /* original f451, guest PC 0x0c09fcb0 */
if(!s->budget--) { s->failed_pc=0x0c09fcb0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c09fcb2;
P_0c09fcb2: /* original f44d, guest PC 0x0c09fcb2 */
if(!s->budget--) { s->failed_pc=0x0c09fcb2u; return 0; }
fr[4]^=0x80000000u;
goto P_0c09fcb4;
P_0c09fcb4: /* original f450, guest PC 0x0c09fcb4 */
if(!s->budget--) { s->failed_pc=0x0c09fcb4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c09fcb6;
P_0c09fcb6: /* original 000b, guest PC 0x0c09fcb6 */
if(!s->budget--) { s->failed_pc=0x0c09fcb6u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,4,r[4]);
s->pc=target; return ram->oob==0;
P_0c09fcb8: /* original f44a, guest PC 0x0c09fcb8 */
if(!s->budget--) { s->failed_pc=0x0c09fcb8u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c09fcba;
P_0c09fcba: /* original f358, guest PC 0x0c09fcba */
if(!s->budget--) { s->failed_pc=0x0c09fcbau; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c09fcbc;
P_0c09fcbc: /* original f448, guest PC 0x0c09fcbc */
if(!s->budget--) { s->failed_pc=0x0c09fcbcu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c09fcbe;
P_0c09fcbe: /* original f43a, guest PC 0x0c09fcbe */
if(!s->budget--) { s->failed_pc=0x0c09fcbeu; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c09fcc0;
P_0c09fcc0: /* original 000b, guest PC 0x0c09fcc0 */
if(!s->budget--) { s->failed_pc=0x0c09fcc0u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,4,r[5]);
s->pc=target; return ram->oob==0;
P_0c09fcc2: /* original f54a, guest PC 0x0c09fcc2 */
if(!s->budget--) { s->failed_pc=0x0c09fcc2u; return 0; }
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c09fcc4;
P_0c09fcc4: /* original f448, guest PC 0x0c09fcc4 */
if(!s->budget--) { s->failed_pc=0x0c09fcc4u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c09fcc6;
P_0c09fcc6: /* original f558, guest PC 0x0c09fcc6 */
if(!s->budget--) { s->failed_pc=0x0c09fcc6u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
goto P_0c09fcc8;
P_0c09fcc8: /* original f44d, guest PC 0x0c09fcc8 */
if(!s->budget--) { s->failed_pc=0x0c09fcc8u; return 0; }
fr[4]^=0x80000000u;
goto P_0c09fcca;
P_0c09fcca: /* original f54d, guest PC 0x0c09fcca */
if(!s->budget--) { s->failed_pc=0x0c09fccau; return 0; }
fr[5]^=0x80000000u;
goto P_0c09fccc;
P_0c09fccc: /* original f54a, guest PC 0x0c09fccc */
if(!s->budget--) { s->failed_pc=0x0c09fcccu; return 0; }
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c09fcce;
P_0c09fcce: /* original 000b, guest PC 0x0c09fcce */
if(!s->budget--) { s->failed_pc=0x0c09fcceu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,5,r[4]);
s->pc=target; return ram->oob==0;
P_0c09fcd0: /* original f45a, guest PC 0x0c09fcd0 */
if(!s->budget--) { s->failed_pc=0x0c09fcd0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]);
if(!vf3_matrix_family(0x0c09fcd2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09fcd2u; return 0; } return 1;
P_0c09fcf4: /* original 2fe6, guest PC 0x0c09fcf4 */
if(!s->budget--) { s->failed_pc=0x0c09fcf4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09fcf6;
P_0c09fcf6: /* original e00c, guest PC 0x0c09fcf6 */
if(!s->budget--) { s->failed_pc=0x0c09fcf6u; return 0; }
r[0]=0x0000000cu;
goto P_0c09fcf8;
P_0c09fcf8: /* original 6e43, guest PC 0x0c09fcf8 */
if(!s->budget--) { s->failed_pc=0x0c09fcf8u; return 0; }
r[14]=r[4];
goto P_0c09fcfa;
P_0c09fcfa: /* original f3e8, guest PC 0x0c09fcfa */
if(!s->budget--) { s->failed_pc=0x0c09fcfau; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c09fcfc;
P_0c09fcfc: /* original 4f22, guest PC 0x0c09fcfc */
if(!s->budget--) { s->failed_pc=0x0c09fcfcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09fcfe;
P_0c09fcfe: /* original f34d, guest PC 0x0c09fcfe */
if(!s->budget--) { s->failed_pc=0x0c09fcfeu; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fd00;
P_0c09fd00: /* original 65e3, guest PC 0x0c09fd00 */
if(!s->budget--) { s->failed_pc=0x0c09fd00u; return 0; }
r[5]=r[14];
goto P_0c09fd02;
P_0c09fd02: /* original fe3a, guest PC 0x0c09fd02 */
if(!s->budget--) { s->failed_pc=0x0c09fd02u; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c09fd04;
P_0c09fd04: /* original 64e3, guest PC 0x0c09fd04 */
if(!s->budget--) { s->failed_pc=0x0c09fd04u; return 0; }
r[4]=r[14];
goto P_0c09fd06;
P_0c09fd06: /* original f2e6, guest PC 0x0c09fd06 */
if(!s->budget--) { s->failed_pc=0x0c09fd06u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c09fd08;
P_0c09fd08: /* original 7524, guest PC 0x0c09fd08 */
if(!s->budget--) { s->failed_pc=0x0c09fd08u; return 0; }
r[5]+=0x00000024u;
goto P_0c09fd0a;
P_0c09fd0a: /* original f24d, guest PC 0x0c09fd0a */
if(!s->budget--) { s->failed_pc=0x0c09fd0au; return 0; }
fr[2]^=0x80000000u;
goto P_0c09fd0c;
P_0c09fd0c: /* original fe27, guest PC 0x0c09fd0c */
if(!s->budget--) { s->failed_pc=0x0c09fd0cu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c09fd0e;
P_0c09fd0e: /* original e018, guest PC 0x0c09fd0e */
if(!s->budget--) { s->failed_pc=0x0c09fd0eu; return 0; }
r[0]=0x00000018u;
goto P_0c09fd10;
P_0c09fd10: /* original f3e6, guest PC 0x0c09fd10 */
if(!s->budget--) { s->failed_pc=0x0c09fd10u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fd12;
P_0c09fd12: /* original f34d, guest PC 0x0c09fd12 */
if(!s->budget--) { s->failed_pc=0x0c09fd12u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fd14;
P_0c09fd14: /* original fe37, guest PC 0x0c09fd14 */
if(!s->budget--) { s->failed_pc=0x0c09fd14u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fd16;
P_0c09fd16: /* original bfd5, guest PC 0x0c09fd16 */
if(!s->budget--) { s->failed_pc=0x0c09fd16u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fd1au;
r[4]+=0x00000030u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd1au) { target=s->pc; goto dispatch; }
goto P_0c09fd1a;
P_0c09fd18: /* original 7430, guest PC 0x0c09fd18 */
if(!s->budget--) { s->failed_pc=0x0c09fd18u; return 0; }
r[4]+=0x00000030u;
goto P_0c09fd1a;
P_0c09fd1a: /* original 65e3, guest PC 0x0c09fd1a */
if(!s->budget--) { s->failed_pc=0x0c09fd1au; return 0; }
r[5]=r[14];
goto P_0c09fd1c;
P_0c09fd1c: /* original 64e3, guest PC 0x0c09fd1c */
if(!s->budget--) { s->failed_pc=0x0c09fd1cu; return 0; }
r[4]=r[14];
goto P_0c09fd1e;
P_0c09fd1e: /* original 7528, guest PC 0x0c09fd1e */
if(!s->budget--) { s->failed_pc=0x0c09fd1eu; return 0; }
r[5]+=0x00000028u;
goto P_0c09fd20;
P_0c09fd20: /* original bfcb, guest PC 0x0c09fd20 */
if(!s->budget--) { s->failed_pc=0x0c09fd20u; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fd24u;
r[4]+=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd24u) { target=s->pc; goto dispatch; }
goto P_0c09fd24;
P_0c09fd22: /* original 7434, guest PC 0x0c09fd22 */
if(!s->budget--) { s->failed_pc=0x0c09fd22u; return 0; }
r[4]+=0x00000034u;
goto P_0c09fd24;
P_0c09fd24: /* original 65e3, guest PC 0x0c09fd24 */
if(!s->budget--) { s->failed_pc=0x0c09fd24u; return 0; }
r[5]=r[14];
goto P_0c09fd26;
P_0c09fd26: /* original 64e3, guest PC 0x0c09fd26 */
if(!s->budget--) { s->failed_pc=0x0c09fd26u; return 0; }
r[4]=r[14];
goto P_0c09fd28;
P_0c09fd28: /* original 752c, guest PC 0x0c09fd28 */
if(!s->budget--) { s->failed_pc=0x0c09fd28u; return 0; }
r[5]+=0x0000002cu;
goto P_0c09fd2a;
P_0c09fd2a: /* original bfc6, guest PC 0x0c09fd2a */
if(!s->budget--) { s->failed_pc=0x0c09fd2au; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fd2eu;
r[4]+=0x00000038u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd2eu) { target=s->pc; goto dispatch; }
goto P_0c09fd2e;
P_0c09fd2c: /* original 7438, guest PC 0x0c09fd2c */
if(!s->budget--) { s->failed_pc=0x0c09fd2cu; return 0; }
r[4]+=0x00000038u;
goto P_0c09fd2e;
P_0c09fd2e: /* original 65e3, guest PC 0x0c09fd2e */
if(!s->budget--) { s->failed_pc=0x0c09fd2eu; return 0; }
r[5]=r[14];
goto P_0c09fd30;
P_0c09fd30: /* original 64e3, guest PC 0x0c09fd30 */
if(!s->budget--) { s->failed_pc=0x0c09fd30u; return 0; }
r[4]=r[14];
goto P_0c09fd32;
P_0c09fd32: /* original 753c, guest PC 0x0c09fd32 */
if(!s->budget--) { s->failed_pc=0x0c09fd32u; return 0; }
r[5]+=0x0000003cu;
goto P_0c09fd34;
P_0c09fd34: /* original bfc6, guest PC 0x0c09fd34 */
if(!s->budget--) { s->failed_pc=0x0c09fd34u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fd38u;
r[4]+=0x00000048u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd38u) { target=s->pc; goto dispatch; }
goto P_0c09fd38;
P_0c09fd36: /* original 7448, guest PC 0x0c09fd36 */
if(!s->budget--) { s->failed_pc=0x0c09fd36u; return 0; }
r[4]+=0x00000048u;
goto P_0c09fd38;
P_0c09fd38: /* original 65e3, guest PC 0x0c09fd38 */
if(!s->budget--) { s->failed_pc=0x0c09fd38u; return 0; }
r[5]=r[14];
goto P_0c09fd3a;
P_0c09fd3a: /* original 64e3, guest PC 0x0c09fd3a */
if(!s->budget--) { s->failed_pc=0x0c09fd3au; return 0; }
r[4]=r[14];
goto P_0c09fd3c;
P_0c09fd3c: /* original 7540, guest PC 0x0c09fd3c */
if(!s->budget--) { s->failed_pc=0x0c09fd3cu; return 0; }
r[5]+=0x00000040u;
goto P_0c09fd3e;
P_0c09fd3e: /* original bfbc, guest PC 0x0c09fd3e */
if(!s->budget--) { s->failed_pc=0x0c09fd3eu; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fd42u;
r[4]+=0x0000004cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd42u) { target=s->pc; goto dispatch; }
goto P_0c09fd42;
P_0c09fd40: /* original 744c, guest PC 0x0c09fd40 */
if(!s->budget--) { s->failed_pc=0x0c09fd40u; return 0; }
r[4]+=0x0000004cu;
goto P_0c09fd42;
P_0c09fd42: /* original 65e3, guest PC 0x0c09fd42 */
if(!s->budget--) { s->failed_pc=0x0c09fd42u; return 0; }
r[5]=r[14];
goto P_0c09fd44;
P_0c09fd44: /* original 64e3, guest PC 0x0c09fd44 */
if(!s->budget--) { s->failed_pc=0x0c09fd44u; return 0; }
r[4]=r[14];
goto P_0c09fd46;
P_0c09fd46: /* original 7544, guest PC 0x0c09fd46 */
if(!s->budget--) { s->failed_pc=0x0c09fd46u; return 0; }
r[5]+=0x00000044u;
goto P_0c09fd48;
P_0c09fd48: /* original bfb7, guest PC 0x0c09fd48 */
if(!s->budget--) { s->failed_pc=0x0c09fd48u; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fd4cu;
r[4]+=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd4cu) { target=s->pc; goto dispatch; }
goto P_0c09fd4c;
P_0c09fd4a: /* original 7450, guest PC 0x0c09fd4a */
if(!s->budget--) { s->failed_pc=0x0c09fd4au; return 0; }
r[4]+=0x00000050u;
goto P_0c09fd4c;
P_0c09fd4c: /* original e054, guest PC 0x0c09fd4c */
if(!s->budget--) { s->failed_pc=0x0c09fd4cu; return 0; }
r[0]=0x00000054u;
goto P_0c09fd4e;
P_0c09fd4e: /* original 64e3, guest PC 0x0c09fd4e */
if(!s->budget--) { s->failed_pc=0x0c09fd4eu; return 0; }
r[4]=r[14];
goto P_0c09fd50;
P_0c09fd50: /* original f3e6, guest PC 0x0c09fd50 */
if(!s->budget--) { s->failed_pc=0x0c09fd50u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fd52;
P_0c09fd52: /* original f34d, guest PC 0x0c09fd52 */
if(!s->budget--) { s->failed_pc=0x0c09fd52u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fd54;
P_0c09fd54: /* original fe37, guest PC 0x0c09fd54 */
if(!s->budget--) { s->failed_pc=0x0c09fd54u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fd56;
P_0c09fd56: /* original e058, guest PC 0x0c09fd56 */
if(!s->budget--) { s->failed_pc=0x0c09fd56u; return 0; }
r[0]=0x00000058u;
goto P_0c09fd58;
P_0c09fd58: /* original f3e6, guest PC 0x0c09fd58 */
if(!s->budget--) { s->failed_pc=0x0c09fd58u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fd5a;
P_0c09fd5a: /* original f34d, guest PC 0x0c09fd5a */
if(!s->budget--) { s->failed_pc=0x0c09fd5au; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fd5c;
P_0c09fd5c: /* original fe37, guest PC 0x0c09fd5c */
if(!s->budget--) { s->failed_pc=0x0c09fd5cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fd5e;
P_0c09fd5e: /* original e060, guest PC 0x0c09fd5e */
if(!s->budget--) { s->failed_pc=0x0c09fd5eu; return 0; }
r[0]=0x00000060u;
goto P_0c09fd60;
P_0c09fd60: /* original f3e6, guest PC 0x0c09fd60 */
if(!s->budget--) { s->failed_pc=0x0c09fd60u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fd62;
P_0c09fd62: /* original f34d, guest PC 0x0c09fd62 */
if(!s->budget--) { s->failed_pc=0x0c09fd62u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fd64;
P_0c09fd64: /* original fe37, guest PC 0x0c09fd64 */
if(!s->budget--) { s->failed_pc=0x0c09fd64u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fd66;
P_0c09fd66: /* original bfa0, guest PC 0x0c09fd66 */
if(!s->budget--) { s->failed_pc=0x0c09fd66u; return 0; }
target=code_base|0x0c09fcaau; r[16]=code_base|0x0c09fd6au;
r[4]+=0x00000064u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd6au) { target=s->pc; goto dispatch; }
goto P_0c09fd6a;
P_0c09fd68: /* original 7464, guest PC 0x0c09fd68 */
if(!s->budget--) { s->failed_pc=0x0c09fd68u; return 0; }
r[4]+=0x00000064u;
goto P_0c09fd6a;
P_0c09fd6a: /* original e068, guest PC 0x0c09fd6a */
if(!s->budget--) { s->failed_pc=0x0c09fd6au; return 0; }
r[0]=0x00000068u;
goto P_0c09fd6c;
P_0c09fd6c: /* original 64e3, guest PC 0x0c09fd6c */
if(!s->budget--) { s->failed_pc=0x0c09fd6cu; return 0; }
r[4]=r[14];
goto P_0c09fd6e;
P_0c09fd6e: /* original f3e6, guest PC 0x0c09fd6e */
if(!s->budget--) { s->failed_pc=0x0c09fd6eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fd70;
P_0c09fd70: /* original f34d, guest PC 0x0c09fd70 */
if(!s->budget--) { s->failed_pc=0x0c09fd70u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fd72;
P_0c09fd72: /* original fe37, guest PC 0x0c09fd72 */
if(!s->budget--) { s->failed_pc=0x0c09fd72u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fd74;
P_0c09fd74: /* original bf99, guest PC 0x0c09fd74 */
if(!s->budget--) { s->failed_pc=0x0c09fd74u; return 0; }
target=code_base|0x0c09fcaau; r[16]=code_base|0x0c09fd78u;
r[4]+=0x00000070u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd78u) { target=s->pc; goto dispatch; }
goto P_0c09fd78;
P_0c09fd76: /* original 7470, guest PC 0x0c09fd76 */
if(!s->budget--) { s->failed_pc=0x0c09fd76u; return 0; }
r[4]+=0x00000070u;
goto P_0c09fd78;
P_0c09fd78: /* original 9556, guest PC 0x0c09fd78 */
if(!s->budget--) { s->failed_pc=0x0c09fd78u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe28u,2);
goto P_0c09fd7a;
P_0c09fd7a: /* original 9456, guest PC 0x0c09fd7a */
if(!s->budget--) { s->failed_pc=0x0c09fd7au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe2au,2);
goto P_0c09fd7c;
P_0c09fd7c: /* original 35ec, guest PC 0x0c09fd7c */
if(!s->budget--) { s->failed_pc=0x0c09fd7cu; return 0; }
r[5]+=r[14];
goto P_0c09fd7e;
P_0c09fd7e: /* original bfa1, guest PC 0x0c09fd7e */
if(!s->budget--) { s->failed_pc=0x0c09fd7eu; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fd82u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd82u) { target=s->pc; goto dispatch; }
goto P_0c09fd82;
P_0c09fd80: /* original 34ec, guest PC 0x0c09fd80 */
if(!s->budget--) { s->failed_pc=0x0c09fd80u; return 0; }
r[4]+=r[14];
goto P_0c09fd82;
P_0c09fd82: /* original 9453, guest PC 0x0c09fd82 */
if(!s->budget--) { s->failed_pc=0x0c09fd82u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe2cu,2);
goto P_0c09fd84;
P_0c09fd84: /* original 65e3, guest PC 0x0c09fd84 */
if(!s->budget--) { s->failed_pc=0x0c09fd84u; return 0; }
r[5]=r[14];
goto P_0c09fd86;
P_0c09fd86: /* original 757c, guest PC 0x0c09fd86 */
if(!s->budget--) { s->failed_pc=0x0c09fd86u; return 0; }
r[5]+=0x0000007cu;
goto P_0c09fd88;
P_0c09fd88: /* original bf9c, guest PC 0x0c09fd88 */
if(!s->budget--) { s->failed_pc=0x0c09fd88u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fd8cu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd8cu) { target=s->pc; goto dispatch; }
goto P_0c09fd8c;
P_0c09fd8a: /* original 34ec, guest PC 0x0c09fd8a */
if(!s->budget--) { s->failed_pc=0x0c09fd8au; return 0; }
r[4]+=r[14];
goto P_0c09fd8c;
P_0c09fd8c: /* original 944f, guest PC 0x0c09fd8c */
if(!s->budget--) { s->failed_pc=0x0c09fd8cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe2eu,2);
goto P_0c09fd8e;
P_0c09fd8e: /* original 65e3, guest PC 0x0c09fd8e */
if(!s->budget--) { s->failed_pc=0x0c09fd8eu; return 0; }
r[5]=r[14];
goto P_0c09fd90;
P_0c09fd90: /* original 7578, guest PC 0x0c09fd90 */
if(!s->budget--) { s->failed_pc=0x0c09fd90u; return 0; }
r[5]+=0x00000078u;
goto P_0c09fd92;
P_0c09fd92: /* original bf92, guest PC 0x0c09fd92 */
if(!s->budget--) { s->failed_pc=0x0c09fd92u; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fd96u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fd96u) { target=s->pc; goto dispatch; }
goto P_0c09fd96;
P_0c09fd94: /* original 34ec, guest PC 0x0c09fd94 */
if(!s->budget--) { s->failed_pc=0x0c09fd94u; return 0; }
r[4]+=r[14];
goto P_0c09fd96;
P_0c09fd96: /* original 954b, guest PC 0x0c09fd96 */
if(!s->budget--) { s->failed_pc=0x0c09fd96u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe30u,2);
goto P_0c09fd98;
P_0c09fd98: /* original 944b, guest PC 0x0c09fd98 */
if(!s->budget--) { s->failed_pc=0x0c09fd98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe32u,2);
goto P_0c09fd9a;
P_0c09fd9a: /* original 35ec, guest PC 0x0c09fd9a */
if(!s->budget--) { s->failed_pc=0x0c09fd9au; return 0; }
r[5]+=r[14];
goto P_0c09fd9c;
P_0c09fd9c: /* original bf92, guest PC 0x0c09fd9c */
if(!s->budget--) { s->failed_pc=0x0c09fd9cu; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fda0u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fda0u) { target=s->pc; goto dispatch; }
goto P_0c09fda0;
P_0c09fd9e: /* original 34ec, guest PC 0x0c09fd9e */
if(!s->budget--) { s->failed_pc=0x0c09fd9eu; return 0; }
r[4]+=r[14];
goto P_0c09fda0;
P_0c09fda0: /* original 9548, guest PC 0x0c09fda0 */
if(!s->budget--) { s->failed_pc=0x0c09fda0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe34u,2);
goto P_0c09fda2;
P_0c09fda2: /* original 9448, guest PC 0x0c09fda2 */
if(!s->budget--) { s->failed_pc=0x0c09fda2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe36u,2);
goto P_0c09fda4;
P_0c09fda4: /* original 35ec, guest PC 0x0c09fda4 */
if(!s->budget--) { s->failed_pc=0x0c09fda4u; return 0; }
r[5]+=r[14];
goto P_0c09fda6;
P_0c09fda6: /* original bf8d, guest PC 0x0c09fda6 */
if(!s->budget--) { s->failed_pc=0x0c09fda6u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fdaau;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdaau) { target=s->pc; goto dispatch; }
goto P_0c09fdaa;
P_0c09fda8: /* original 34ec, guest PC 0x0c09fda8 */
if(!s->budget--) { s->failed_pc=0x0c09fda8u; return 0; }
r[4]+=r[14];
goto P_0c09fdaa;
P_0c09fdaa: /* original 9545, guest PC 0x0c09fdaa */
if(!s->budget--) { s->failed_pc=0x0c09fdaau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe38u,2);
goto P_0c09fdac;
P_0c09fdac: /* original 9445, guest PC 0x0c09fdac */
if(!s->budget--) { s->failed_pc=0x0c09fdacu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe3au,2);
goto P_0c09fdae;
P_0c09fdae: /* original 35ec, guest PC 0x0c09fdae */
if(!s->budget--) { s->failed_pc=0x0c09fdaeu; return 0; }
r[5]+=r[14];
goto P_0c09fdb0;
P_0c09fdb0: /* original bf83, guest PC 0x0c09fdb0 */
if(!s->budget--) { s->failed_pc=0x0c09fdb0u; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fdb4u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdb4u) { target=s->pc; goto dispatch; }
goto P_0c09fdb4;
P_0c09fdb2: /* original 34ec, guest PC 0x0c09fdb2 */
if(!s->budget--) { s->failed_pc=0x0c09fdb2u; return 0; }
r[4]+=r[14];
goto P_0c09fdb4;
P_0c09fdb4: /* original 9542, guest PC 0x0c09fdb4 */
if(!s->budget--) { s->failed_pc=0x0c09fdb4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe3cu,2);
goto P_0c09fdb6;
P_0c09fdb6: /* original 9442, guest PC 0x0c09fdb6 */
if(!s->budget--) { s->failed_pc=0x0c09fdb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe3eu,2);
goto P_0c09fdb8;
P_0c09fdb8: /* original 35ec, guest PC 0x0c09fdb8 */
if(!s->budget--) { s->failed_pc=0x0c09fdb8u; return 0; }
r[5]+=r[14];
goto P_0c09fdba;
P_0c09fdba: /* original bf83, guest PC 0x0c09fdba */
if(!s->budget--) { s->failed_pc=0x0c09fdbau; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fdbeu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdbeu) { target=s->pc; goto dispatch; }
goto P_0c09fdbe;
P_0c09fdbc: /* original 34ec, guest PC 0x0c09fdbc */
if(!s->budget--) { s->failed_pc=0x0c09fdbcu; return 0; }
r[4]+=r[14];
goto P_0c09fdbe;
P_0c09fdbe: /* original 953f, guest PC 0x0c09fdbe */
if(!s->budget--) { s->failed_pc=0x0c09fdbeu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe40u,2);
goto P_0c09fdc0;
P_0c09fdc0: /* original 943f, guest PC 0x0c09fdc0 */
if(!s->budget--) { s->failed_pc=0x0c09fdc0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe42u,2);
goto P_0c09fdc2;
P_0c09fdc2: /* original 35ec, guest PC 0x0c09fdc2 */
if(!s->budget--) { s->failed_pc=0x0c09fdc2u; return 0; }
r[5]+=r[14];
goto P_0c09fdc4;
P_0c09fdc4: /* original bf7e, guest PC 0x0c09fdc4 */
if(!s->budget--) { s->failed_pc=0x0c09fdc4u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fdc8u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdc8u) { target=s->pc; goto dispatch; }
goto P_0c09fdc8;
P_0c09fdc6: /* original 34ec, guest PC 0x0c09fdc6 */
if(!s->budget--) { s->failed_pc=0x0c09fdc6u; return 0; }
r[4]+=r[14];
goto P_0c09fdc8;
P_0c09fdc8: /* original 953c, guest PC 0x0c09fdc8 */
if(!s->budget--) { s->failed_pc=0x0c09fdc8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe44u,2);
goto P_0c09fdca;
P_0c09fdca: /* original 943c, guest PC 0x0c09fdca */
if(!s->budget--) { s->failed_pc=0x0c09fdcau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe46u,2);
goto P_0c09fdcc;
P_0c09fdcc: /* original 35ec, guest PC 0x0c09fdcc */
if(!s->budget--) { s->failed_pc=0x0c09fdccu; return 0; }
r[5]+=r[14];
goto P_0c09fdce;
P_0c09fdce: /* original bf74, guest PC 0x0c09fdce */
if(!s->budget--) { s->failed_pc=0x0c09fdceu; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fdd2u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdd2u) { target=s->pc; goto dispatch; }
goto P_0c09fdd2;
P_0c09fdd0: /* original 34ec, guest PC 0x0c09fdd0 */
if(!s->budget--) { s->failed_pc=0x0c09fdd0u; return 0; }
r[4]+=r[14];
goto P_0c09fdd2;
P_0c09fdd2: /* original 9039, guest PC 0x0c09fdd2 */
if(!s->budget--) { s->failed_pc=0x0c09fdd2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe48u,2);
goto P_0c09fdd4;
P_0c09fdd4: /* original f3e6, guest PC 0x0c09fdd4 */
if(!s->budget--) { s->failed_pc=0x0c09fdd4u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fdd6;
P_0c09fdd6: /* original f34d, guest PC 0x0c09fdd6 */
if(!s->budget--) { s->failed_pc=0x0c09fdd6u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fdd8;
P_0c09fdd8: /* original fe37, guest PC 0x0c09fdd8 */
if(!s->budget--) { s->failed_pc=0x0c09fdd8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fdda;
P_0c09fdda: /* original 9436, guest PC 0x0c09fdda */
if(!s->budget--) { s->failed_pc=0x0c09fddau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe4au,2);
goto P_0c09fddc;
P_0c09fddc: /* original bf65, guest PC 0x0c09fddc */
if(!s->budget--) { s->failed_pc=0x0c09fddcu; return 0; }
target=code_base|0x0c09fcaau; r[16]=code_base|0x0c09fde0u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fde0u) { target=s->pc; goto dispatch; }
goto P_0c09fde0;
P_0c09fdde: /* original 34ec, guest PC 0x0c09fdde */
if(!s->budget--) { s->failed_pc=0x0c09fddeu; return 0; }
r[4]+=r[14];
goto P_0c09fde0;
P_0c09fde0: /* original 9034, guest PC 0x0c09fde0 */
if(!s->budget--) { s->failed_pc=0x0c09fde0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe4cu,2);
goto P_0c09fde2;
P_0c09fde2: /* original f3e6, guest PC 0x0c09fde2 */
if(!s->budget--) { s->failed_pc=0x0c09fde2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09fde4;
P_0c09fde4: /* original f34d, guest PC 0x0c09fde4 */
if(!s->budget--) { s->failed_pc=0x0c09fde4u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09fde6;
P_0c09fde6: /* original fe37, guest PC 0x0c09fde6 */
if(!s->budget--) { s->failed_pc=0x0c09fde6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09fde8;
P_0c09fde8: /* original 9531, guest PC 0x0c09fde8 */
if(!s->budget--) { s->failed_pc=0x0c09fde8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe4eu,2);
goto P_0c09fdea;
P_0c09fdea: /* original 9431, guest PC 0x0c09fdea */
if(!s->budget--) { s->failed_pc=0x0c09fdeau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe50u,2);
goto P_0c09fdec;
P_0c09fdec: /* original 35ec, guest PC 0x0c09fdec */
if(!s->budget--) { s->failed_pc=0x0c09fdecu; return 0; }
r[5]+=r[14];
goto P_0c09fdee;
P_0c09fdee: /* original bf69, guest PC 0x0c09fdee */
if(!s->budget--) { s->failed_pc=0x0c09fdeeu; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fdf2u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdf2u) { target=s->pc; goto dispatch; }
goto P_0c09fdf2;
P_0c09fdf0: /* original 34ec, guest PC 0x0c09fdf0 */
if(!s->budget--) { s->failed_pc=0x0c09fdf0u; return 0; }
r[4]+=r[14];
goto P_0c09fdf2;
P_0c09fdf2: /* original 952e, guest PC 0x0c09fdf2 */
if(!s->budget--) { s->failed_pc=0x0c09fdf2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe52u,2);
goto P_0c09fdf4;
P_0c09fdf4: /* original 942e, guest PC 0x0c09fdf4 */
if(!s->budget--) { s->failed_pc=0x0c09fdf4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe54u,2);
goto P_0c09fdf6;
P_0c09fdf6: /* original 35ec, guest PC 0x0c09fdf6 */
if(!s->budget--) { s->failed_pc=0x0c09fdf6u; return 0; }
r[5]+=r[14];
goto P_0c09fdf8;
P_0c09fdf8: /* original bf64, guest PC 0x0c09fdf8 */
if(!s->budget--) { s->failed_pc=0x0c09fdf8u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fdfcu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fdfcu) { target=s->pc; goto dispatch; }
goto P_0c09fdfc;
P_0c09fdfa: /* original 34ec, guest PC 0x0c09fdfa */
if(!s->budget--) { s->failed_pc=0x0c09fdfau; return 0; }
r[4]+=r[14];
goto P_0c09fdfc;
P_0c09fdfc: /* original 952b, guest PC 0x0c09fdfc */
if(!s->budget--) { s->failed_pc=0x0c09fdfcu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe56u,2);
goto P_0c09fdfe;
P_0c09fdfe: /* original 942b, guest PC 0x0c09fdfe */
if(!s->budget--) { s->failed_pc=0x0c09fdfeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe58u,2);
goto P_0c09fe00;
P_0c09fe00: /* original 35ec, guest PC 0x0c09fe00 */
if(!s->budget--) { s->failed_pc=0x0c09fe00u; return 0; }
r[5]+=r[14];
goto P_0c09fe02;
P_0c09fe02: /* original bf5a, guest PC 0x0c09fe02 */
if(!s->budget--) { s->failed_pc=0x0c09fe02u; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fe06u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fe06u) { target=s->pc; goto dispatch; }
goto P_0c09fe06;
P_0c09fe04: /* original 34ec, guest PC 0x0c09fe04 */
if(!s->budget--) { s->failed_pc=0x0c09fe04u; return 0; }
r[4]+=r[14];
goto P_0c09fe06;
P_0c09fe06: /* original 9528, guest PC 0x0c09fe06 */
if(!s->budget--) { s->failed_pc=0x0c09fe06u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe5au,2);
goto P_0c09fe08;
P_0c09fe08: /* original 9428, guest PC 0x0c09fe08 */
if(!s->budget--) { s->failed_pc=0x0c09fe08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe5cu,2);
goto P_0c09fe0a;
P_0c09fe0a: /* original 35ec, guest PC 0x0c09fe0a */
if(!s->budget--) { s->failed_pc=0x0c09fe0au; return 0; }
r[5]+=r[14];
goto P_0c09fe0c;
P_0c09fe0c: /* original bf55, guest PC 0x0c09fe0c */
if(!s->budget--) { s->failed_pc=0x0c09fe0cu; return 0; }
target=code_base|0x0c09fcbau; r[16]=code_base|0x0c09fe10u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fe10u) { target=s->pc; goto dispatch; }
goto P_0c09fe10;
P_0c09fe0e: /* original 34ec, guest PC 0x0c09fe0e */
if(!s->budget--) { s->failed_pc=0x0c09fe0eu; return 0; }
r[4]+=r[14];
goto P_0c09fe10;
P_0c09fe10: /* original 9525, guest PC 0x0c09fe10 */
if(!s->budget--) { s->failed_pc=0x0c09fe10u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe5eu,2);
goto P_0c09fe12;
P_0c09fe12: /* original 9425, guest PC 0x0c09fe12 */
if(!s->budget--) { s->failed_pc=0x0c09fe12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe60u,2);
goto P_0c09fe14;
P_0c09fe14: /* original 35ec, guest PC 0x0c09fe14 */
if(!s->budget--) { s->failed_pc=0x0c09fe14u; return 0; }
r[5]+=r[14];
goto P_0c09fe16;
P_0c09fe16: /* original bf55, guest PC 0x0c09fe16 */
if(!s->budget--) { s->failed_pc=0x0c09fe16u; return 0; }
target=code_base|0x0c09fcc4u; r[16]=code_base|0x0c09fe1au;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09fe1au) { target=s->pc; goto dispatch; }
goto P_0c09fe1a;
P_0c09fe18: /* original 34ec, guest PC 0x0c09fe18 */
if(!s->budget--) { s->failed_pc=0x0c09fe18u; return 0; }
r[4]+=r[14];
goto P_0c09fe1a;
P_0c09fe1a: /* original 9423, guest PC 0x0c09fe1a */
if(!s->budget--) { s->failed_pc=0x0c09fe1au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe64u,2);
goto P_0c09fe1c;
P_0c09fe1c: /* original 4f26, guest PC 0x0c09fe1c */
if(!s->budget--) { s->failed_pc=0x0c09fe1cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09fe1e;
P_0c09fe1e: /* original 9520, guest PC 0x0c09fe1e */
if(!s->budget--) { s->failed_pc=0x0c09fe1eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09fe62u,2);
goto P_0c09fe20;
P_0c09fe20: /* original 34ec, guest PC 0x0c09fe20 */
if(!s->budget--) { s->failed_pc=0x0c09fe20u; return 0; }
r[4]+=r[14];
goto P_0c09fe22;
P_0c09fe22: /* original 35ec, guest PC 0x0c09fe22 */
if(!s->budget--) { s->failed_pc=0x0c09fe22u; return 0; }
r[5]+=r[14];
goto P_0c09fe24;
P_0c09fe24: /* original af4e, guest PC 0x0c09fe24 */
if(!s->budget--) { s->failed_pc=0x0c09fe24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09fcc4;
P_0c09fe26: /* original 6ef6, guest PC 0x0c09fe26 */
if(!s->budget--) { s->failed_pc=0x0c09fe26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09fe28u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09fe28u; return 0; } return 1;
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
P_0c0a92c8: /* original 2fe6, guest PC 0x0c0a92c8 */
if(!s->budget--) { s->failed_pc=0x0c0a92c8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a92ca;
P_0c0a92ca: /* original 6e43, guest PC 0x0c0a92ca */
if(!s->budget--) { s->failed_pc=0x0c0a92cau; return 0; }
r[14]=r[4];
goto P_0c0a92cc;
P_0c0a92cc: /* original 2fd6, guest PC 0x0c0a92cc */
if(!s->budget--) { s->failed_pc=0x0c0a92ccu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a92ce;
P_0c0a92ce: /* original ed01, guest PC 0x0c0a92ce */
if(!s->budget--) { s->failed_pc=0x0c0a92ceu; return 0; }
r[13]=0x00000001u;
goto P_0c0a92d0;
P_0c0a92d0: /* original 2fc6, guest PC 0x0c0a92d0 */
if(!s->budget--) { s->failed_pc=0x0c0a92d0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a92d2;
P_0c0a92d2: /* original dc39, guest PC 0x0c0a92d2 */
if(!s->budget--) { s->failed_pc=0x0c0a92d2u; return 0; }
r[12]=read(ram,0x0c0a93b8u,4);
goto P_0c0a92d4;
P_0c0a92d4: /* original 9063, guest PC 0x0c0a92d4 */
if(!s->budget--) { s->failed_pc=0x0c0a92d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a939eu,2);
goto P_0c0a92d6;
P_0c0a92d6: /* original 56c5, guest PC 0x0c0a92d6 */
if(!s->budget--) { s->failed_pc=0x0c0a92d6u; return 0; }
r[6]=read(ram,r[12]+20,4);
goto P_0c0a92d8;
P_0c0a92d8: /* original 54c4, guest PC 0x0c0a92d8 */
if(!s->budget--) { s->failed_pc=0x0c0a92d8u; return 0; }
r[4]=read(ram,r[12]+16,4);
goto P_0c0a92da;
P_0c0a92da: /* original 4f22, guest PC 0x0c0a92da */
if(!s->budget--) { s->failed_pc=0x0c0a92dau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a92dc;
P_0c0a92dc: /* original 04d4, guest PC 0x0c0a92dc */
if(!s->budget--) { s->failed_pc=0x0c0a92dcu; return 0; }
write(ram,r[4]+r[0],r[13],1);
goto P_0c0a92de;
P_0c0a92de: /* original 06d4, guest PC 0x0c0a92de */
if(!s->budget--) { s->failed_pc=0x0c0a92deu; return 0; }
write(ram,r[6]+r[0],r[13],1);
goto P_0c0a92e0;
P_0c0a92e0: /* original 84e4, guest PC 0x0c0a92e0 */
if(!s->budget--) { s->failed_pc=0x0c0a92e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0a92e2;
P_0c0a92e2: /* original 7ffc, guest PC 0x0c0a92e2 */
if(!s->budget--) { s->failed_pc=0x0c0a92e2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a92e4;
P_0c0a92e4: /* original d335, guest PC 0x0c0a92e4 */
if(!s->budget--) { s->failed_pc=0x0c0a92e4u; return 0; }
r[3]=read(ram,0x0c0a93bcu,4);
goto P_0c0a92e6;
P_0c0a92e6: /* original 660e, guest PC 0x0c0a92e6 */
if(!s->budget--) { s->failed_pc=0x0c0a92e6u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c0a92e8;
P_0c0a92e8: /* original 2668, guest PC 0x0c0a92e8 */
if(!s->budget--) { s->failed_pc=0x0c0a92e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0a92ea;
P_0c0a92ea: /* original 8d01, guest PC 0x0c0a92ea */
if(!s->budget--) { s->failed_pc=0x0c0a92eau; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(cond) { goto P_0c0a92f0; }
goto P_0c0a92ee;
P_0c0a92ec: /* original 6432, guest PC 0x0c0a92ec */
if(!s->budget--) { s->failed_pc=0x0c0a92ecu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0a92ee;
P_0c0a92ee: /* original 4419, guest PC 0x0c0a92ee */
if(!s->budget--) { s->failed_pc=0x0c0a92eeu; return 0; }
r[4]>>=8;
goto P_0c0a92f0;
P_0c0a92f0: /* original e061, guest PC 0x0c0a92f0 */
if(!s->budget--) { s->failed_pc=0x0c0a92f0u; return 0; }
r[0]=0x00000061u;
goto P_0c0a92f2;
P_0c0a92f2: /* original 03ec, guest PC 0x0c0a92f2 */
if(!s->budget--) { s->failed_pc=0x0c0a92f2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a92f4;
P_0c0a92f4: /* original 2f30, guest PC 0x0c0a92f4 */
if(!s->budget--) { s->failed_pc=0x0c0a92f4u; return 0; }
write(ram,r[15],r[3],1);
goto P_0c0a92f6;
P_0c0a92f6: /* original 67f0, guest PC 0x0c0a92f6 */
if(!s->budget--) { s->failed_pc=0x0c0a92f6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[7]=tmp;
goto P_0c0a92f8;
P_0c0a92f8: /* original 6073, guest PC 0x0c0a92f8 */
if(!s->budget--) { s->failed_pc=0x0c0a92f8u; return 0; }
r[0]=r[7];
goto P_0c0a92fa;
P_0c0a92fa: /* original 8803, guest PC 0x0c0a92fa */
if(!s->budget--) { s->failed_pc=0x0c0a92fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0a92fc;
P_0c0a92fc: /* original 8d03, guest PC 0x0c0a92fc */
if(!s->budget--) { s->failed_pc=0x0c0a92fcu; return 0; }
cond=r[17]&1u;
r[6]=r[4];
if(cond) { goto P_0c0a9306; }
goto P_0c0a9300;
P_0c0a92fe: /* original 6643, guest PC 0x0c0a92fe */
if(!s->budget--) { s->failed_pc=0x0c0a92feu; return 0; }
r[6]=r[4];
goto P_0c0a9300;
P_0c0a9300: /* original 6073, guest PC 0x0c0a9300 */
if(!s->budget--) { s->failed_pc=0x0c0a9300u; return 0; }
r[0]=r[7];
goto P_0c0a9302;
P_0c0a9302: /* original 8801, guest PC 0x0c0a9302 */
if(!s->budget--) { s->failed_pc=0x0c0a9302u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a9304;
P_0c0a9304: /* original 8b11, guest PC 0x0c0a9304 */
if(!s->budget--) { s->failed_pc=0x0c0a9304u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a932a; }
goto P_0c0a9306;
P_0c0a9306: /* original d32e, guest PC 0x0c0a9306 */
if(!s->budget--) { s->failed_pc=0x0c0a9306u; return 0; }
r[3]=read(ram,0x0c0a93c0u,4);
goto P_0c0a9308;
P_0c0a9308: /* original 924a, guest PC 0x0c0a9308 */
if(!s->budget--) { s->failed_pc=0x0c0a9308u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93a0u,2);
goto P_0c0a930a;
P_0c0a930a: /* original 2439, guest PC 0x0c0a930a */
if(!s->budget--) { s->failed_pc=0x0c0a930au; return 0; }
r[4]&=r[3];
goto P_0c0a930c;
P_0c0a930c: /* original 3420, guest PC 0x0c0a930c */
if(!s->budget--) { s->failed_pc=0x0c0a930cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0a930e;
P_0c0a930e: /* original 8b0c, guest PC 0x0c0a930e */
if(!s->budget--) { s->failed_pc=0x0c0a930eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a932a; }
goto P_0c0a9310;
P_0c0a9310: /* original 9047, guest PC 0x0c0a9310 */
if(!s->budget--) { s->failed_pc=0x0c0a9310u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93a2u,2);
goto P_0c0a9312;
P_0c0a9312: /* original e31c, guest PC 0x0c0a9312 */
if(!s->budget--) { s->failed_pc=0x0c0a9312u; return 0; }
r[3]=0x0000001cu;
goto P_0c0a9314;
P_0c0a9314: /* original 54c8, guest PC 0x0c0a9314 */
if(!s->budget--) { s->failed_pc=0x0c0a9314u; return 0; }
r[4]=read(ram,r[12]+32,4);
goto P_0c0a9316;
P_0c0a9316: /* original 0436, guest PC 0x0c0a9316 */
if(!s->budget--) { s->failed_pc=0x0c0a9316u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c0a9318;
P_0c0a9318: /* original 9041, guest PC 0x0c0a9318 */
if(!s->budget--) { s->failed_pc=0x0c0a9318u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a939eu,2);
goto P_0c0a931a;
P_0c0a931a: /* original 0ed4, guest PC 0x0c0a931a */
if(!s->budget--) { s->failed_pc=0x0c0a931au; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0a931c;
P_0c0a931c: /* original 6073, guest PC 0x0c0a931c */
if(!s->budget--) { s->failed_pc=0x0c0a931cu; return 0; }
r[0]=r[7];
goto P_0c0a931e;
P_0c0a931e: /* original 9441, guest PC 0x0c0a931e */
if(!s->budget--) { s->failed_pc=0x0c0a931eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93a4u,2);
goto P_0c0a9320;
P_0c0a9320: /* original 8803, guest PC 0x0c0a9320 */
if(!s->budget--) { s->failed_pc=0x0c0a9320u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0a9322;
P_0c0a9322: /* original 8971, guest PC 0x0c0a9322 */
if(!s->budget--) { s->failed_pc=0x0c0a9322u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9408; }
goto P_0c0a9324;
P_0c0a9324: /* original 943f, guest PC 0x0c0a9324 */
if(!s->budget--) { s->failed_pc=0x0c0a9324u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93a6u,2);
goto P_0c0a9326;
P_0c0a9326: /* original a06f, guest PC 0x0c0a9326 */
if(!s->budget--) { s->failed_pc=0x0c0a9326u; return 0; }
goto P_0c0a9408;
P_0c0a9328: /* original 0009, guest PC 0x0c0a9328 */
if(!s->budget--) { s->failed_pc=0x0c0a9328u; return 0; }
goto P_0c0a932a;
P_0c0a932a: /* original d726, guest PC 0x0c0a932a */
if(!s->budget--) { s->failed_pc=0x0c0a932au; return 0; }
r[7]=read(ram,0x0c0a93c4u,4);
goto P_0c0a932c;
P_0c0a932c: /* original e018, guest PC 0x0c0a932c */
if(!s->budget--) { s->failed_pc=0x0c0a932cu; return 0; }
r[0]=0x00000018u;
goto P_0c0a932e;
P_0c0a932e: /* original 047c, guest PC 0x0c0a932e */
if(!s->budget--) { s->failed_pc=0x0c0a932eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c0a9330;
P_0c0a9330: /* original 2448, guest PC 0x0c0a9330 */
if(!s->budget--) { s->failed_pc=0x0c0a9330u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a9332;
P_0c0a9332: /* original 8b17, guest PC 0x0c0a9332 */
if(!s->budget--) { s->failed_pc=0x0c0a9332u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9364; }
goto P_0c0a9334;
P_0c0a9334: /* original 6403, guest PC 0x0c0a9334 */
if(!s->budget--) { s->failed_pc=0x0c0a9334u; return 0; }
r[4]=r[0];
goto P_0c0a9336;
P_0c0a9336: /* original 9037, guest PC 0x0c0a9336 */
if(!s->budget--) { s->failed_pc=0x0c0a9336u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93a8u,2);
goto P_0c0a9338;
P_0c0a9338: /* original 02ed, guest PC 0x0c0a9338 */
if(!s->budget--) { s->failed_pc=0x0c0a9338u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a933a;
P_0c0a933a: /* original e046, guest PC 0x0c0a933a */
if(!s->budget--) { s->failed_pc=0x0c0a933au; return 0; }
r[0]=0x00000046u;
goto P_0c0a933c;
P_0c0a933c: /* original 03ed, guest PC 0x0c0a933c */
if(!s->budget--) { s->failed_pc=0x0c0a933cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a933e;
P_0c0a933e: /* original 633d, guest PC 0x0c0a933e */
if(!s->budget--) { s->failed_pc=0x0c0a933eu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a9340;
P_0c0a9340: /* original 3230, guest PC 0x0c0a9340 */
if(!s->budget--) { s->failed_pc=0x0c0a9340u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0a9342;
P_0c0a9342: /* original 8b0f, guest PC 0x0c0a9342 */
if(!s->budget--) { s->failed_pc=0x0c0a9342u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9364; }
goto P_0c0a9344;
P_0c0a9344: /* original e061, guest PC 0x0c0a9344 */
if(!s->budget--) { s->failed_pc=0x0c0a9344u; return 0; }
r[0]=0x00000061u;
goto P_0c0a9346;
P_0c0a9346: /* original 025c, guest PC 0x0c0a9346 */
if(!s->budget--) { s->failed_pc=0x0c0a9346u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0a9348;
P_0c0a9348: /* original 2228, guest PC 0x0c0a9348 */
if(!s->budget--) { s->failed_pc=0x0c0a9348u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a934a;
P_0c0a934a: /* original 8b4d, guest PC 0x0c0a934a */
if(!s->budget--) { s->failed_pc=0x0c0a934au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a93e8; }
goto P_0c0a934c;
P_0c0a934c: /* original 00ec, guest PC 0x0c0a934c */
if(!s->budget--) { s->failed_pc=0x0c0a934cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a934e;
P_0c0a934e: /* original 600c, guest PC 0x0c0a934e */
if(!s->budget--) { s->failed_pc=0x0c0a934eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0a9350;
P_0c0a9350: /* original 8806, guest PC 0x0c0a9350 */
if(!s->budget--) { s->failed_pc=0x0c0a9350u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0a9352;
P_0c0a9352: /* original 8b49, guest PC 0x0c0a9352 */
if(!s->budget--) { s->failed_pc=0x0c0a9352u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a93e8; }
goto P_0c0a9354;
P_0c0a9354: /* original 9025, guest PC 0x0c0a9354 */
if(!s->budget--) { s->failed_pc=0x0c0a9354u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93a2u,2);
goto P_0c0a9356;
P_0c0a9356: /* original e31c, guest PC 0x0c0a9356 */
if(!s->budget--) { s->failed_pc=0x0c0a9356u; return 0; }
r[3]=0x0000001cu;
goto P_0c0a9358;
P_0c0a9358: /* original 54c8, guest PC 0x0c0a9358 */
if(!s->budget--) { s->failed_pc=0x0c0a9358u; return 0; }
r[4]=read(ram,r[12]+32,4);
goto P_0c0a935a;
P_0c0a935a: /* original 0436, guest PC 0x0c0a935a */
if(!s->budget--) { s->failed_pc=0x0c0a935au; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c0a935c;
P_0c0a935c: /* original 9425, guest PC 0x0c0a935c */
if(!s->budget--) { s->failed_pc=0x0c0a935cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93aau,2);
goto P_0c0a935e;
P_0c0a935e: /* original 901e, guest PC 0x0c0a935e */
if(!s->budget--) { s->failed_pc=0x0c0a935eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a939eu,2);
goto P_0c0a9360;
P_0c0a9360: /* original a052, guest PC 0x0c0a9360 */
if(!s->budget--) { s->failed_pc=0x0c0a9360u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0a9408;
P_0c0a9362: /* original 0ed4, guest PC 0x0c0a9362 */
if(!s->budget--) { s->failed_pc=0x0c0a9362u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0a9364;
P_0c0a9364: /* original 9422, guest PC 0x0c0a9364 */
if(!s->budget--) { s->failed_pc=0x0c0a9364u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93acu,2);
goto P_0c0a9366;
P_0c0a9366: /* original 6263, guest PC 0x0c0a9366 */
if(!s->budget--) { s->failed_pc=0x0c0a9366u; return 0; }
r[2]=r[6];
goto P_0c0a9368;
P_0c0a9368: /* original 2249, guest PC 0x0c0a9368 */
if(!s->budget--) { s->failed_pc=0x0c0a9368u; return 0; }
r[2]&=r[4];
goto P_0c0a936a;
P_0c0a936a: /* original 3240, guest PC 0x0c0a936a */
if(!s->budget--) { s->failed_pc=0x0c0a936au; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[4])!=0);
goto P_0c0a936c;
P_0c0a936c: /* original 8b01, guest PC 0x0c0a936c */
if(!s->budget--) { s->failed_pc=0x0c0a936cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9372; }
goto P_0c0a936e;
P_0c0a936e: /* original a03b, guest PC 0x0c0a936e */
if(!s->budget--) { s->failed_pc=0x0c0a936eu; return 0; }
r[4]=0x00000010u;
goto P_0c0a93e8;
P_0c0a9370: /* original e410, guest PC 0x0c0a9370 */
if(!s->budget--) { s->failed_pc=0x0c0a9370u; return 0; }
r[4]=0x00000010u;
goto P_0c0a9372;
P_0c0a9372: /* original 941c, guest PC 0x0c0a9372 */
if(!s->budget--) { s->failed_pc=0x0c0a9372u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93aeu,2);
goto P_0c0a9374;
P_0c0a9374: /* original 6263, guest PC 0x0c0a9374 */
if(!s->budget--) { s->failed_pc=0x0c0a9374u; return 0; }
r[2]=r[6];
goto P_0c0a9376;
P_0c0a9376: /* original 2249, guest PC 0x0c0a9376 */
if(!s->budget--) { s->failed_pc=0x0c0a9376u; return 0; }
r[2]&=r[4];
goto P_0c0a9378;
P_0c0a9378: /* original 3240, guest PC 0x0c0a9378 */
if(!s->budget--) { s->failed_pc=0x0c0a9378u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[4])!=0);
goto P_0c0a937a;
P_0c0a937a: /* original 8b01, guest PC 0x0c0a937a */
if(!s->budget--) { s->failed_pc=0x0c0a937au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9380; }
goto P_0c0a937c;
P_0c0a937c: /* original a034, guest PC 0x0c0a937c */
if(!s->budget--) { s->failed_pc=0x0c0a937cu; return 0; }
r[4]=0x00000014u;
goto P_0c0a93e8;
P_0c0a937e: /* original e414, guest PC 0x0c0a937e */
if(!s->budget--) { s->failed_pc=0x0c0a937eu; return 0; }
r[4]=0x00000014u;
goto P_0c0a9380;
P_0c0a9380: /* original 9316, guest PC 0x0c0a9380 */
if(!s->budget--) { s->failed_pc=0x0c0a9380u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93b0u,2);
goto P_0c0a9382;
P_0c0a9382: /* original 2368, guest PC 0x0c0a9382 */
if(!s->budget--) { s->failed_pc=0x0c0a9382u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0a9384;
P_0c0a9384: /* original 8901, guest PC 0x0c0a9384 */
if(!s->budget--) { s->failed_pc=0x0c0a9384u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a938a; }
goto P_0c0a9386;
P_0c0a9386: /* original a02f, guest PC 0x0c0a9386 */
if(!s->budget--) { s->failed_pc=0x0c0a9386u; return 0; }
r[4]=0x00000000u;
goto P_0c0a93e8;
P_0c0a9388: /* original e400, guest PC 0x0c0a9388 */
if(!s->budget--) { s->failed_pc=0x0c0a9388u; return 0; }
r[4]=0x00000000u;
goto P_0c0a938a;
P_0c0a938a: /* original 9312, guest PC 0x0c0a938a */
if(!s->budget--) { s->failed_pc=0x0c0a938au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93b2u,2);
goto P_0c0a938c;
P_0c0a938c: /* original 2368, guest PC 0x0c0a938c */
if(!s->budget--) { s->failed_pc=0x0c0a938cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0a938e;
P_0c0a938e: /* original 8901, guest PC 0x0c0a938e */
if(!s->budget--) { s->failed_pc=0x0c0a938eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9394; }
goto P_0c0a9390;
P_0c0a9390: /* original a02a, guest PC 0x0c0a9390 */
if(!s->budget--) { s->failed_pc=0x0c0a9390u; return 0; }
r[4]=0x00000004u;
goto P_0c0a93e8;
P_0c0a9392: /* original e404, guest PC 0x0c0a9392 */
if(!s->budget--) { s->failed_pc=0x0c0a9392u; return 0; }
r[4]=0x00000004u;
goto P_0c0a9394;
P_0c0a9394: /* original 920e, guest PC 0x0c0a9394 */
if(!s->budget--) { s->failed_pc=0x0c0a9394u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a93b4u,2);
goto P_0c0a9396;
P_0c0a9396: /* original 2268, guest PC 0x0c0a9396 */
if(!s->budget--) { s->failed_pc=0x0c0a9396u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c0a9398;
P_0c0a9398: /* original 8916, guest PC 0x0c0a9398 */
if(!s->budget--) { s->failed_pc=0x0c0a9398u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a93c8; }
goto P_0c0a939a;
P_0c0a939a: /* original a025, guest PC 0x0c0a939a */
if(!s->budget--) { s->failed_pc=0x0c0a939au; return 0; }
r[4]=0x00000008u;
goto P_0c0a93e8;
P_0c0a939c: /* original e408, guest PC 0x0c0a939c */
if(!s->budget--) { s->failed_pc=0x0c0a939cu; return 0; }
r[4]=0x00000008u;
if(!vf3_matrix_family(0x0c0a939eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a939eu; return 0; } return 1;
P_0c0a93c8: /* original 926d, guest PC 0x0c0a93c8 */
if(!s->budget--) { s->failed_pc=0x0c0a93c8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a94a6u,2);
goto P_0c0a93ca;
P_0c0a93ca: /* original 2628, guest PC 0x0c0a93ca */
if(!s->budget--) { s->failed_pc=0x0c0a93cau; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c0a93cc;
P_0c0a93cc: /* original 8901, guest PC 0x0c0a93cc */
if(!s->budget--) { s->failed_pc=0x0c0a93ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a93d2; }
goto P_0c0a93ce;
P_0c0a93ce: /* original a00b, guest PC 0x0c0a93ce */
if(!s->budget--) { s->failed_pc=0x0c0a93ceu; return 0; }
r[4]=0x0000000cu;
goto P_0c0a93e8;
P_0c0a93d0: /* original e40c, guest PC 0x0c0a93d0 */
if(!s->budget--) { s->failed_pc=0x0c0a93d0u; return 0; }
r[4]=0x0000000cu;
goto P_0c0a93d2;
P_0c0a93d2: /* original d138, guest PC 0x0c0a93d2 */
if(!s->budget--) { s->failed_pc=0x0c0a93d2u; return 0; }
r[1]=read(ram,0x0c0a94b4u,4);
goto P_0c0a93d4;
P_0c0a93d4: /* original d336, guest PC 0x0c0a93d4 */
if(!s->budget--) { s->failed_pc=0x0c0a93d4u; return 0; }
r[3]=read(ram,0x0c0a94b0u,4);
goto P_0c0a93d6;
P_0c0a93d6: /* original 5472, guest PC 0x0c0a93d6 */
if(!s->budget--) { s->failed_pc=0x0c0a93d6u; return 0; }
r[4]=read(ram,r[7]+8,4);
goto P_0c0a93d8;
P_0c0a93d8: /* original 410b, guest PC 0x0c0a93d8 */
if(!s->budget--) { s->failed_pc=0x0c0a93d8u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a93dcu;
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a93dcu) { target=s->pc; goto dispatch; }
goto P_0c0a93dc;
P_0c0a93da: /* original 2438, guest PC 0x0c0a93da */
if(!s->budget--) { s->failed_pc=0x0c0a93dau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0a93dc;
P_0c0a93dc: /* original d236, guest PC 0x0c0a93dc */
if(!s->budget--) { s->failed_pc=0x0c0a93dcu; return 0; }
r[2]=read(ram,0x0c0a94b8u,4);
goto P_0c0a93de;
P_0c0a93de: /* original 6103, guest PC 0x0c0a93de */
if(!s->budget--) { s->failed_pc=0x0c0a93deu; return 0; }
r[1]=r[0];
goto P_0c0a93e0;
P_0c0a93e0: /* original 420b, guest PC 0x0c0a93e0 */
if(!s->budget--) { s->failed_pc=0x0c0a93e0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a93e4u;
r[0]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a93e4u) { target=s->pc; goto dispatch; }
goto P_0c0a93e4;
P_0c0a93e2: /* original e006, guest PC 0x0c0a93e2 */
if(!s->budget--) { s->failed_pc=0x0c0a93e2u; return 0; }
r[0]=0x00000006u;
goto P_0c0a93e4;
P_0c0a93e4: /* original 6403, guest PC 0x0c0a93e4 */
if(!s->budget--) { s->failed_pc=0x0c0a93e4u; return 0; }
r[4]=r[0];
goto P_0c0a93e6;
P_0c0a93e6: /* original 4408, guest PC 0x0c0a93e6 */
if(!s->budget--) { s->failed_pc=0x0c0a93e6u; return 0; }
r[4]<<=2;
goto P_0c0a93e8;
P_0c0a93e8: /* original 905e, guest PC 0x0c0a93e8 */
if(!s->budget--) { s->failed_pc=0x0c0a93e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a94a8u,2);
goto P_0c0a93ea;
P_0c0a93ea: /* original 55c8, guest PC 0x0c0a93ea */
if(!s->budget--) { s->failed_pc=0x0c0a93eau; return 0; }
r[5]=read(ram,r[12]+32,4);
goto P_0c0a93ec;
P_0c0a93ec: /* original 0546, guest PC 0x0c0a93ec */
if(!s->budget--) { s->failed_pc=0x0c0a93ecu; return 0; }
write(ram,r[5]+r[0],r[4],4);
goto P_0c0a93ee;
P_0c0a93ee: /* original 4409, guest PC 0x0c0a93ee */
if(!s->budget--) { s->failed_pc=0x0c0a93eeu; return 0; }
r[4]>>=2;
goto P_0c0a93f0;
P_0c0a93f0: /* original 905b, guest PC 0x0c0a93f0 */
if(!s->budget--) { s->failed_pc=0x0c0a93f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a94aau,2);
goto P_0c0a93f2;
P_0c0a93f2: /* original 6543, guest PC 0x0c0a93f2 */
if(!s->budget--) { s->failed_pc=0x0c0a93f2u; return 0; }
r[5]=r[4];
goto P_0c0a93f4;
P_0c0a93f4: /* original 4508, guest PC 0x0c0a93f4 */
if(!s->budget--) { s->failed_pc=0x0c0a93f4u; return 0; }
r[5]<<=2;
goto P_0c0a93f6;
P_0c0a93f6: /* original 0ed4, guest PC 0x0c0a93f6 */
if(!s->budget--) { s->failed_pc=0x0c0a93f6u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0a93f8;
P_0c0a93f8: /* original d030, guest PC 0x0c0a93f8 */
if(!s->budget--) { s->failed_pc=0x0c0a93f8u; return 0; }
r[0]=read(ram,0x0c0a94bcu,4);
goto P_0c0a93fa;
P_0c0a93fa: /* original 055e, guest PC 0x0c0a93fa */
if(!s->budget--) { s->failed_pc=0x0c0a93fau; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c0a93fc;
P_0c0a93fc: /* original e061, guest PC 0x0c0a93fc */
if(!s->budget--) { s->failed_pc=0x0c0a93fcu; return 0; }
r[0]=0x00000061u;
goto P_0c0a93fe;
P_0c0a93fe: /* original 00ec, guest PC 0x0c0a93fe */
if(!s->budget--) { s->failed_pc=0x0c0a93feu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a9400;
P_0c0a9400: /* original 600c, guest PC 0x0c0a9400 */
if(!s->budget--) { s->failed_pc=0x0c0a9400u; return 0; }
r[0]=r[0]&255u;
goto P_0c0a9402;
P_0c0a9402: /* original 4000, guest PC 0x0c0a9402 */
if(!s->budget--) { s->failed_pc=0x0c0a9402u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0a9404;
P_0c0a9404: /* original 045d, guest PC 0x0c0a9404 */
if(!s->budget--) { s->failed_pc=0x0c0a9404u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0a9406;
P_0c0a9406: /* original 644d, guest PC 0x0c0a9406 */
if(!s->budget--) { s->failed_pc=0x0c0a9406u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a9408;
P_0c0a9408: /* original e03c, guest PC 0x0c0a9408 */
if(!s->budget--) { s->failed_pc=0x0c0a9408u; return 0; }
r[0]=0x0000003cu;
goto P_0c0a940a;
P_0c0a940a: /* original 0e45, guest PC 0x0c0a940a */
if(!s->budget--) { s->failed_pc=0x0c0a940au; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a940c;
P_0c0a940c: /* original e03e, guest PC 0x0c0a940c */
if(!s->budget--) { s->failed_pc=0x0c0a940cu; return 0; }
r[0]=0x0000003eu;
goto P_0c0a940e;
P_0c0a940e: /* original 1e4d, guest PC 0x0c0a940e */
if(!s->budget--) { s->failed_pc=0x0c0a940eu; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c0a9410;
P_0c0a9410: /* original 0ed5, guest PC 0x0c0a9410 */
if(!s->budget--) { s->failed_pc=0x0c0a9410u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c0a9412;
P_0c0a9412: /* original e010, guest PC 0x0c0a9412 */
if(!s->budget--) { s->failed_pc=0x0c0a9412u; return 0; }
r[0]=0x00000010u;
goto P_0c0a9414;
P_0c0a9414: /* original f4e6, guest PC 0x0c0a9414 */
if(!s->budget--) { s->failed_pc=0x0c0a9414u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a9416;
P_0c0a9416: /* original e018, guest PC 0x0c0a9416 */
if(!s->budget--) { s->failed_pc=0x0c0a9416u; return 0; }
r[0]=0x00000018u;
goto P_0c0a9418;
P_0c0a9418: /* original d329, guest PC 0x0c0a9418 */
if(!s->budget--) { s->failed_pc=0x0c0a9418u; return 0; }
r[3]=read(ram,0x0c0a94c0u,4);
goto P_0c0a941a;
P_0c0a941a: /* original f5e6, guest PC 0x0c0a941a */
if(!s->budget--) { s->failed_pc=0x0c0a941au; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a941c;
P_0c0a941c: /* original 430b, guest PC 0x0c0a941c */
if(!s->budget--) { s->failed_pc=0x0c0a941cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9420u;
fr[5]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9420u) { target=s->pc; goto dispatch; }
goto P_0c0a9420;
P_0c0a941e: /* original f54d, guest PC 0x0c0a941e */
if(!s->budget--) { s->failed_pc=0x0c0a941eu; return 0; }
fr[5]^=0x80000000u;
goto P_0c0a9420;
P_0c0a9420: /* original e024, guest PC 0x0c0a9420 */
if(!s->budget--) { s->failed_pc=0x0c0a9420u; return 0; }
r[0]=0x00000024u;
goto P_0c0a9422;
P_0c0a9422: /* original f58d, guest PC 0x0c0a9422 */
if(!s->budget--) { s->failed_pc=0x0c0a9422u; return 0; }
fr[5]=0;
goto P_0c0a9424;
P_0c0a9424: /* original 7f04, guest PC 0x0c0a9424 */
if(!s->budget--) { s->failed_pc=0x0c0a9424u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a9426;
P_0c0a9426: /* original f40c, guest PC 0x0c0a9426 */
if(!s->budget--) { s->failed_pc=0x0c0a9426u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0a9428;
P_0c0a9428: /* original fe57, guest PC 0x0c0a9428 */
if(!s->budget--) { s->failed_pc=0x0c0a9428u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a942a;
P_0c0a942a: /* original e028, guest PC 0x0c0a942a */
if(!s->budget--) { s->failed_pc=0x0c0a942au; return 0; }
r[0]=0x00000028u;
goto P_0c0a942c;
P_0c0a942c: /* original fe57, guest PC 0x0c0a942c */
if(!s->budget--) { s->failed_pc=0x0c0a942cu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a942e;
P_0c0a942e: /* original e02c, guest PC 0x0c0a942e */
if(!s->budget--) { s->failed_pc=0x0c0a942eu; return 0; }
r[0]=0x0000002cu;
goto P_0c0a9430;
P_0c0a9430: /* original 4f26, guest PC 0x0c0a9430 */
if(!s->budget--) { s->failed_pc=0x0c0a9430u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9432;
P_0c0a9432: /* original fe57, guest PC 0x0c0a9432 */
if(!s->budget--) { s->failed_pc=0x0c0a9432u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0a9434;
P_0c0a9434: /* original e014, guest PC 0x0c0a9434 */
if(!s->budget--) { s->failed_pc=0x0c0a9434u; return 0; }
r[0]=0x00000014u;
goto P_0c0a9436;
P_0c0a9436: /* original fe47, guest PC 0x0c0a9436 */
if(!s->budget--) { s->failed_pc=0x0c0a9436u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a9438;
P_0c0a9438: /* original 9038, guest PC 0x0c0a9438 */
if(!s->budget--) { s->failed_pc=0x0c0a9438u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a94acu,2);
goto P_0c0a943a;
P_0c0a943a: /* original fe47, guest PC 0x0c0a943a */
if(!s->budget--) { s->failed_pc=0x0c0a943au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0a943c;
P_0c0a943c: /* original 6cf6, guest PC 0x0c0a943c */
if(!s->budget--) { s->failed_pc=0x0c0a943cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a943e;
P_0c0a943e: /* original 6df6, guest PC 0x0c0a943e */
if(!s->budget--) { s->failed_pc=0x0c0a943eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a9440;
P_0c0a9440: /* original 000b, guest PC 0x0c0a9440 */
if(!s->budget--) { s->failed_pc=0x0c0a9440u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a9442: /* original 6ef6, guest PC 0x0c0a9442 */
if(!s->budget--) { s->failed_pc=0x0c0a9442u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a9444u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
