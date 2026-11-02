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
int vf3_away_batch14_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03a140u: goto P_0c03a140;
case 0x0c03a142u: goto P_0c03a142;
case 0x0c03a144u: goto P_0c03a144;
case 0x0c03a146u: goto P_0c03a146;
case 0x0c03a148u: goto P_0c03a148;
case 0x0c03a14au: goto P_0c03a14a;
case 0x0c03a14cu: goto P_0c03a14c;
case 0x0c03a14eu: goto P_0c03a14e;
case 0x0c03a150u: goto P_0c03a150;
case 0x0c03a152u: goto P_0c03a152;
case 0x0c03a154u: goto P_0c03a154;
case 0x0c03a156u: goto P_0c03a156;
case 0x0c03a250u: goto P_0c03a250;
case 0x0c03a252u: goto P_0c03a252;
case 0x0c03a254u: goto P_0c03a254;
case 0x0c03a256u: goto P_0c03a256;
case 0x0c03a258u: goto P_0c03a258;
case 0x0c03a25au: goto P_0c03a25a;
case 0x0c03a25cu: goto P_0c03a25c;
case 0x0c03a25eu: goto P_0c03a25e;
case 0x0c03a260u: goto P_0c03a260;
case 0x0c03a262u: goto P_0c03a262;
case 0x0c03a264u: goto P_0c03a264;
case 0x0c03a270u: goto P_0c03a270;
case 0x0c03a272u: goto P_0c03a272;
case 0x0c03a274u: goto P_0c03a274;
case 0x0c03a276u: goto P_0c03a276;
case 0x0c03a278u: goto P_0c03a278;
case 0x0c03a27au: goto P_0c03a27a;
case 0x0c03a27cu: goto P_0c03a27c;
case 0x0c03a27eu: goto P_0c03a27e;
case 0x0c03a280u: goto P_0c03a280;
case 0x0c03a282u: goto P_0c03a282;
case 0x0c03a284u: goto P_0c03a284;
case 0x0c03a286u: goto P_0c03a286;
case 0x0c03a288u: goto P_0c03a288;
case 0x0c03a28au: goto P_0c03a28a;
case 0x0c03a28cu: goto P_0c03a28c;
case 0x0c03a28eu: goto P_0c03a28e;
case 0x0c03a290u: goto P_0c03a290;
case 0x0c03a292u: goto P_0c03a292;
case 0x0c03a294u: goto P_0c03a294;
case 0x0c03a296u: goto P_0c03a296;
case 0x0c03a298u: goto P_0c03a298;
case 0x0c03a29au: goto P_0c03a29a;
case 0x0c03a29cu: goto P_0c03a29c;
case 0x0c03a29eu: goto P_0c03a29e;
case 0x0c03a2a0u: goto P_0c03a2a0;
case 0x0c03a2a2u: goto P_0c03a2a2;
case 0x0c03a2a4u: goto P_0c03a2a4;
case 0x0c03a2a6u: goto P_0c03a2a6;
case 0x0c03a2a8u: goto P_0c03a2a8;
case 0x0c03a2aau: goto P_0c03a2aa;
case 0x0c03a2acu: goto P_0c03a2ac;
case 0x0c03a2aeu: goto P_0c03a2ae;
case 0x0c03a2b0u: goto P_0c03a2b0;
case 0x0c03a2b2u: goto P_0c03a2b2;
case 0x0c03a2b4u: goto P_0c03a2b4;
case 0x0c03a2b6u: goto P_0c03a2b6;
case 0x0c03a2b8u: goto P_0c03a2b8;
case 0x0c03a2bau: goto P_0c03a2ba;
case 0x0c03a2bcu: goto P_0c03a2bc;
case 0x0c03a2beu: goto P_0c03a2be;
case 0x0c03a390u: goto P_0c03a390;
case 0x0c03a392u: goto P_0c03a392;
case 0x0c03a394u: goto P_0c03a394;
case 0x0c03a396u: goto P_0c03a396;
case 0x0c03a398u: goto P_0c03a398;
case 0x0c03a39au: goto P_0c03a39a;
case 0x0c03a39cu: goto P_0c03a39c;
case 0x0c03a3a0u: goto P_0c03a3a0;
case 0x0c03a3a2u: goto P_0c03a3a2;
case 0x0c03a3a4u: goto P_0c03a3a4;
case 0x0c03a3a6u: goto P_0c03a3a6;
case 0x0c03a3a8u: goto P_0c03a3a8;
case 0x0c03a3aau: goto P_0c03a3aa;
case 0x0c03a3acu: goto P_0c03a3ac;
case 0x0c03a3aeu: goto P_0c03a3ae;
case 0x0c03a3b0u: goto P_0c03a3b0;
case 0x0c03a3b2u: goto P_0c03a3b2;
case 0x0c03a3b4u: goto P_0c03a3b4;
case 0x0c03a3b6u: goto P_0c03a3b6;
case 0x0c03a3b8u: goto P_0c03a3b8;
case 0x0c03a3bau: goto P_0c03a3ba;
case 0x0c03a3bcu: goto P_0c03a3bc;
case 0x0c03a3beu: goto P_0c03a3be;
case 0x0c03a3c0u: goto P_0c03a3c0;
case 0x0c03a3c2u: goto P_0c03a3c2;
case 0x0c03a3c4u: goto P_0c03a3c4;
case 0x0c03a3c6u: goto P_0c03a3c6;
case 0x0c03a3c8u: goto P_0c03a3c8;
case 0x0c03a3cau: goto P_0c03a3ca;
case 0x0c03a3ccu: goto P_0c03a3cc;
case 0x0c03a3ceu: goto P_0c03a3ce;
case 0x0c03a3d0u: goto P_0c03a3d0;
case 0x0c03a3d2u: goto P_0c03a3d2;
case 0x0c03a400u: goto P_0c03a400;
case 0x0c03a402u: goto P_0c03a402;
case 0x0c03a404u: goto P_0c03a404;
case 0x0c03a406u: goto P_0c03a406;
case 0x0c03a408u: goto P_0c03a408;
case 0x0c03a40au: goto P_0c03a40a;
case 0x0c03a40cu: goto P_0c03a40c;
case 0x0c03a40eu: goto P_0c03a40e;
case 0x0c03a410u: goto P_0c03a410;
case 0x0c03a412u: goto P_0c03a412;
case 0x0c03a420u: goto P_0c03a420;
case 0x0c03a422u: goto P_0c03a422;
case 0x0c03a424u: goto P_0c03a424;
case 0x0c03a426u: goto P_0c03a426;
case 0x0c03a428u: goto P_0c03a428;
case 0x0c03a42au: goto P_0c03a42a;
case 0x0c03a42cu: goto P_0c03a42c;
case 0x0c03a42eu: goto P_0c03a42e;
case 0x0c03a430u: goto P_0c03a430;
case 0x0c03a432u: goto P_0c03a432;
case 0x0c03a434u: goto P_0c03a434;
case 0x0c03a436u: goto P_0c03a436;
case 0x0c03a440u: goto P_0c03a440;
case 0x0c03a442u: goto P_0c03a442;
case 0x0c03a444u: goto P_0c03a444;
case 0x0c03a446u: goto P_0c03a446;
case 0x0c03a448u: goto P_0c03a448;
case 0x0c03a44au: goto P_0c03a44a;
case 0x0c03a44cu: goto P_0c03a44c;
case 0x0c03a44eu: goto P_0c03a44e;
case 0x0c03a450u: goto P_0c03a450;
case 0x0c03a452u: goto P_0c03a452;
case 0x0c03a460u: goto P_0c03a460;
case 0x0c03a462u: goto P_0c03a462;
case 0x0c03a464u: goto P_0c03a464;
case 0x0c03a466u: goto P_0c03a466;
case 0x0c03a468u: goto P_0c03a468;
case 0x0c03a46au: goto P_0c03a46a;
case 0x0c03a46cu: goto P_0c03a46c;
case 0x0c03a46eu: goto P_0c03a46e;
case 0x0c03a470u: goto P_0c03a470;
case 0x0c03a472u: goto P_0c03a472;
case 0x0c03a474u: goto P_0c03a474;
case 0x0c03a476u: goto P_0c03a476;
case 0x0c03a478u: goto P_0c03a478;
case 0x0c03a47au: goto P_0c03a47a;
case 0x0c03a47cu: goto P_0c03a47c;
case 0x0c03a47eu: goto P_0c03a47e;
case 0x0c03a480u: goto P_0c03a480;
case 0x0c03a482u: goto P_0c03a482;
case 0x0c03a484u: goto P_0c03a484;
case 0x0c03a486u: goto P_0c03a486;
case 0x0c03a488u: goto P_0c03a488;
case 0x0c03a48au: goto P_0c03a48a;
case 0x0c03a48cu: goto P_0c03a48c;
case 0x0c03a48eu: goto P_0c03a48e;
case 0x0c03a490u: goto P_0c03a490;
case 0x0c03a492u: goto P_0c03a492;
case 0x0c03a494u: goto P_0c03a494;
case 0x0c03a496u: goto P_0c03a496;
case 0x0c03a498u: goto P_0c03a498;
case 0x0c03a49au: goto P_0c03a49a;
case 0x0c03a49cu: goto P_0c03a49c;
case 0x0c03a49eu: goto P_0c03a49e;
case 0x0c03a4a0u: goto P_0c03a4a0;
case 0x0c03a4a2u: goto P_0c03a4a2;
case 0x0c03a4a4u: goto P_0c03a4a4;
case 0x0c03a4a6u: goto P_0c03a4a6;
case 0x0c03a4a8u: goto P_0c03a4a8;
case 0x0c03a4aau: goto P_0c03a4aa;
case 0x0c03a4acu: goto P_0c03a4ac;
case 0x0c03a4aeu: goto P_0c03a4ae;
case 0x0c03a4b0u: goto P_0c03a4b0;
case 0x0c03a4b2u: goto P_0c03a4b2;
case 0x0c03a4b4u: goto P_0c03a4b4;
case 0x0c03a50eu: goto P_0c03a50e;
case 0x0c03a510u: goto P_0c03a510;
case 0x0c03a512u: goto P_0c03a512;
case 0x0c03a514u: goto P_0c03a514;
case 0x0c03a516u: goto P_0c03a516;
case 0x0c03a518u: goto P_0c03a518;
case 0x0c03a51au: goto P_0c03a51a;
case 0x0c03a520u: goto P_0c03a520;
case 0x0c03a522u: goto P_0c03a522;
case 0x0c03a524u: goto P_0c03a524;
case 0x0c03a526u: goto P_0c03a526;
case 0x0c03a528u: goto P_0c03a528;
case 0x0c03a52au: goto P_0c03a52a;
case 0x0c03a52cu: goto P_0c03a52c;
case 0x0c03a52eu: goto P_0c03a52e;
case 0x0c03a530u: goto P_0c03a530;
case 0x0c03a532u: goto P_0c03a532;
case 0x0c03a534u: goto P_0c03a534;
case 0x0c03a536u: goto P_0c03a536;
case 0x0c03a538u: goto P_0c03a538;
case 0x0c03a53au: goto P_0c03a53a;
case 0x0c03a53cu: goto P_0c03a53c;
case 0x0c03a53eu: goto P_0c03a53e;
case 0x0c03a540u: goto P_0c03a540;
case 0x0c03a542u: goto P_0c03a542;
case 0x0c03a544u: goto P_0c03a544;
case 0x0c03a546u: goto P_0c03a546;
case 0x0c03a548u: goto P_0c03a548;
case 0x0c03a54au: goto P_0c03a54a;
case 0x0c03a54cu: goto P_0c03a54c;
case 0x0c03a54eu: goto P_0c03a54e;
case 0x0c03a550u: goto P_0c03a550;
case 0x0c03a560u: goto P_0c03a560;
case 0x0c03a562u: goto P_0c03a562;
case 0x0c03a570u: goto P_0c03a570;
case 0x0c03a572u: goto P_0c03a572;
case 0x0c03a574u: goto P_0c03a574;
case 0x0c03a576u: goto P_0c03a576;
case 0x0c03a578u: goto P_0c03a578;
case 0x0c03a580u: goto P_0c03a580;
case 0x0c03a582u: goto P_0c03a582;
case 0x0c03a584u: goto P_0c03a584;
case 0x0c03a586u: goto P_0c03a586;
case 0x0c03a588u: goto P_0c03a588;
case 0x0c03a58au: goto P_0c03a58a;
case 0x0c03a58cu: goto P_0c03a58c;
case 0x0c03a58eu: goto P_0c03a58e;
case 0x0c03a590u: goto P_0c03a590;
case 0x0c03a592u: goto P_0c03a592;
case 0x0c03a594u: goto P_0c03a594;
case 0x0c03a596u: goto P_0c03a596;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03a140: /* original 2fe6, guest PC 0x0c03a140 */
if(!s->budget--) { s->failed_pc=0x0c03a140u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03a142;
P_0c03a142: /* original 6e4d, guest PC 0x0c03a142 */
if(!s->budget--) { s->failed_pc=0x0c03a142u; return 0; }
r[14]=r[4]&65535u;
goto P_0c03a144;
P_0c03a144: /* original d337, guest PC 0x0c03a144 */
if(!s->budget--) { s->failed_pc=0x0c03a144u; return 0; }
r[3]=read(ram,0x0c03a224u,4);
goto P_0c03a146;
P_0c03a146: /* original 3e37, guest PC 0x0c03a146 */
if(!s->budget--) { s->failed_pc=0x0c03a146u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[3])!=0);
goto P_0c03a148;
P_0c03a148: /* original 8b02, guest PC 0x0c03a148 */
if(!s->budget--) { s->failed_pc=0x0c03a148u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a150; }
goto P_0c03a14a;
P_0c03a14a: /* original d137, guest PC 0x0c03a14a */
if(!s->budget--) { s->failed_pc=0x0c03a14au; return 0; }
r[1]=read(ram,0x0c03a228u,4);
goto P_0c03a14c;
P_0c03a14c: /* original 31e8, guest PC 0x0c03a14c */
if(!s->budget--) { s->failed_pc=0x0c03a14cu; return 0; }
r[1]-=r[14];
goto P_0c03a14e;
P_0c03a14e: /* original 6e13, guest PC 0x0c03a14e */
if(!s->budget--) { s->failed_pc=0x0c03a14eu; return 0; }
r[14]=r[1];
goto P_0c03a150;
P_0c03a150: /* original 9466, guest PC 0x0c03a150 */
if(!s->budget--) { s->failed_pc=0x0c03a150u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a220u,2);
goto P_0c03a152;
P_0c03a152: /* original 34e8, guest PC 0x0c03a152 */
if(!s->budget--) { s->failed_pc=0x0c03a152u; return 0; }
r[4]-=r[14];
goto P_0c03a154;
P_0c03a154: /* original a2c4, guest PC 0x0c03a154 */
if(!s->budget--) { s->failed_pc=0x0c03a154u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03a6e0u,s,ram);
P_0c03a156: /* original 6ef6, guest PC 0x0c03a156 */
if(!s->budget--) { s->failed_pc=0x0c03a156u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03a158u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a158u; return 0; } return 1;
P_0c03a250: /* original fffb, guest PC 0x0c03a250 */
if(!s->budget--) { s->failed_pc=0x0c03a250u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c03a252;
P_0c03a252: /* original c760, guest PC 0x0c03a252 */
if(!s->budget--) { s->failed_pc=0x0c03a252u; return 0; }
r[0]=code_base|0x0003a3d4u;
goto P_0c03a254;
P_0c03a254: /* original ffeb, guest PC 0x0c03a254 */
if(!s->budget--) { s->failed_pc=0x0c03a254u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c03a256;
P_0c03a256: /* original f28d, guest PC 0x0c03a256 */
if(!s->budget--) { s->failed_pc=0x0c03a256u; return 0; }
fr[2]=0;
goto P_0c03a258;
P_0c03a258: /* original ff4c, guest PC 0x0c03a258 */
if(!s->budget--) { s->failed_pc=0x0c03a258u; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c03a25a;
P_0c03a25a: /* original f2f5, guest PC 0x0c03a25a */
if(!s->budget--) { s->failed_pc=0x0c03a25au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[15]))!=0);
goto P_0c03a25c;
P_0c03a25c: /* original 8d08, guest PC 0x0c03a25c */
if(!s->budget--) { s->failed_pc=0x0c03a25cu; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[0]);
if(cond) { goto P_0c03a270; }
goto P_0c03a260;
P_0c03a25e: /* original f408, guest PC 0x0c03a25e */
if(!s->budget--) { s->failed_pc=0x0c03a25eu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c03a260;
P_0c03a260: /* original c75d, guest PC 0x0c03a260 */
if(!s->budget--) { s->failed_pc=0x0c03a260u; return 0; }
r[0]=code_base|0x0003a3d8u;
goto P_0c03a262;
P_0c03a262: /* original a007, guest PC 0x0c03a262 */
if(!s->budget--) { s->failed_pc=0x0c03a262u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03a274;
P_0c03a264: /* original f308, guest PC 0x0c03a264 */
if(!s->budget--) { s->failed_pc=0x0c03a264u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
if(!vf3_matrix_family(0x0c03a266u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a266u; return 0; } return 1;
P_0c03a270: /* original c75a, guest PC 0x0c03a270 */
if(!s->budget--) { s->failed_pc=0x0c03a270u; return 0; }
r[0]=code_base|0x0003a3dcu;
goto P_0c03a272;
P_0c03a272: /* original f308, guest PC 0x0c03a272 */
if(!s->budget--) { s->failed_pc=0x0c03a272u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03a274;
P_0c03a274: /* original f2fc, guest PC 0x0c03a274 */
if(!s->budget--) { s->failed_pc=0x0c03a274u; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c03a276;
P_0c03a276: /* original f243, guest PC 0x0c03a276 */
if(!s->budget--) { s->failed_pc=0x0c03a276u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'/');
goto P_0c03a278;
P_0c03a278: /* original c759, guest PC 0x0c03a278 */
if(!s->budget--) { s->failed_pc=0x0c03a278u; return 0; }
r[0]=code_base|0x0003a3e0u;
goto P_0c03a27a;
P_0c03a27a: /* original e50a, guest PC 0x0c03a27a */
if(!s->budget--) { s->failed_pc=0x0c03a27au; return 0; }
r[5]=0x0000000au;
goto P_0c03a27c;
P_0c03a27c: /* original e606, guest PC 0x0c03a27c */
if(!s->budget--) { s->failed_pc=0x0c03a27cu; return 0; }
r[6]=0x00000006u;
goto P_0c03a27e;
P_0c03a27e: /* original f320, guest PC 0x0c03a27e */
if(!s->budget--) { s->failed_pc=0x0c03a27eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c03a280;
P_0c03a280: /* original f33d, guest PC 0x0c03a280 */
if(!s->budget--) { s->failed_pc=0x0c03a280u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03a282;
P_0c03a282: /* original f308, guest PC 0x0c03a282 */
if(!s->budget--) { s->failed_pc=0x0c03a282u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03a284;
P_0c03a284: /* original 045a, guest PC 0x0c03a284 */
if(!s->budget--) { s->failed_pc=0x0c03a284u; return 0; }
r[4]=r[53];
goto P_0c03a286;
P_0c03a286: /* original 445a, guest PC 0x0c03a286 */
if(!s->budget--) { s->failed_pc=0x0c03a286u; return 0; }
r[53]=r[4];
goto P_0c03a288;
P_0c03a288: /* original f22d, guest PC 0x0c03a288 */
if(!s->budget--) { s->failed_pc=0x0c03a288u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a28a;
P_0c03a28a: /* original f242, guest PC 0x0c03a28a */
if(!s->budget--) { s->failed_pc=0x0c03a28au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c03a28c;
P_0c03a28c: /* original ff21, guest PC 0x0c03a28c */
if(!s->budget--) { s->failed_pc=0x0c03a28cu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[2],r[18],'-');
goto P_0c03a28e;
P_0c03a28e: /* original f4fc, guest PC 0x0c03a28e */
if(!s->budget--) { s->failed_pc=0x0c03a28eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c03a290;
P_0c03a290: /* original f4f2, guest PC 0x0c03a290 */
if(!s->budget--) { s->failed_pc=0x0c03a290u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c03a292;
P_0c03a292: /* original fe4c, guest PC 0x0c03a292 */
if(!s->budget--) { s->failed_pc=0x0c03a292u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c03a294;
P_0c03a294: /* original fe33, guest PC 0x0c03a294 */
if(!s->budget--) { s->failed_pc=0x0c03a294u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'/');
goto P_0c03a296;
P_0c03a296: /* original 455a, guest PC 0x0c03a296 */
if(!s->budget--) { s->failed_pc=0x0c03a296u; return 0; }
r[53]=r[5];
goto P_0c03a298;
P_0c03a298: /* original 75fc, guest PC 0x0c03a298 */
if(!s->budget--) { s->failed_pc=0x0c03a298u; return 0; }
r[5]+=0xfffffffcu;
goto P_0c03a29a;
P_0c03a29a: /* original 3563, guest PC 0x0c03a29a */
if(!s->budget--) { s->failed_pc=0x0c03a29au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c03a29c;
P_0c03a29c: /* original f32d, guest PC 0x0c03a29c */
if(!s->budget--) { s->failed_pc=0x0c03a29cu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a29e;
P_0c03a29e: /* original f3e0, guest PC 0x0c03a29e */
if(!s->budget--) { s->failed_pc=0x0c03a29eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'+');
goto P_0c03a2a0;
P_0c03a2a0: /* original fe4c, guest PC 0x0c03a2a0 */
if(!s->budget--) { s->failed_pc=0x0c03a2a0u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c03a2a2;
P_0c03a2a2: /* original 8df8, guest PC 0x0c03a2a2 */
if(!s->budget--) { s->failed_pc=0x0c03a2a2u; return 0; }
cond=r[17]&1u;
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'/');
if(cond) { goto P_0c03a296; }
goto P_0c03a2a6;
P_0c03a2a4: /* original fe33, guest PC 0x0c03a2a4 */
if(!s->budget--) { s->failed_pc=0x0c03a2a4u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'/');
goto P_0c03a2a6;
P_0c03a2a6: /* original f3fc, guest PC 0x0c03a2a6 */
if(!s->budget--) { s->failed_pc=0x0c03a2a6u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c03a2a8;
P_0c03a2a8: /* original f3e0, guest PC 0x0c03a2a8 */
if(!s->budget--) { s->failed_pc=0x0c03a2a8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'+');
goto P_0c03a2aa;
P_0c03a2aa: /* original f1ec, guest PC 0x0c03a2aa */
if(!s->budget--) { s->failed_pc=0x0c03a2aau; return 0; }
vf3_matrix_move(s,1,14);
goto P_0c03a2ac;
P_0c03a2ac: /* original f1f1, guest PC 0x0c03a2ac */
if(!s->budget--) { s->failed_pc=0x0c03a2acu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[15],r[18],'-');
goto P_0c03a2ae;
P_0c03a2ae: /* original c74d, guest PC 0x0c03a2ae */
if(!s->budget--) { s->failed_pc=0x0c03a2aeu; return 0; }
r[0]=code_base|0x0003a3e4u;
goto P_0c03a2b0;
P_0c03a2b0: /* original fef9, guest PC 0x0c03a2b0 */
if(!s->budget--) { s->failed_pc=0x0c03a2b0u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03a2b2;
P_0c03a2b2: /* original f208, guest PC 0x0c03a2b2 */
if(!s->budget--) { s->failed_pc=0x0c03a2b2u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a2b4;
P_0c03a2b4: /* original f320, guest PC 0x0c03a2b4 */
if(!s->budget--) { s->failed_pc=0x0c03a2b4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c03a2b6;
P_0c03a2b6: /* original f120, guest PC 0x0c03a2b6 */
if(!s->budget--) { s->failed_pc=0x0c03a2b6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c03a2b8;
P_0c03a2b8: /* original f43c, guest PC 0x0c03a2b8 */
if(!s->budget--) { s->failed_pc=0x0c03a2b8u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03a2ba;
P_0c03a2ba: /* original f413, guest PC 0x0c03a2ba */
if(!s->budget--) { s->failed_pc=0x0c03a2bau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'/');
goto P_0c03a2bc;
P_0c03a2bc: /* original a068, guest PC 0x0c03a2bc */
if(!s->budget--) { s->failed_pc=0x0c03a2bcu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03a390;
P_0c03a2be: /* original fff9, guest PC 0x0c03a2be */
if(!s->budget--) { s->failed_pc=0x0c03a2beu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c03a2c0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a2c0u; return 0; } return 1;
P_0c03a390: /* original f38d, guest PC 0x0c03a390 */
if(!s->budget--) { s->failed_pc=0x0c03a390u; return 0; }
fr[3]=0;
goto P_0c03a392;
P_0c03a392: /* original f434, guest PC 0x0c03a392 */
if(!s->budget--) { s->failed_pc=0x0c03a392u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c03a394;
P_0c03a394: /* original 7ffc, guest PC 0x0c03a394 */
if(!s->budget--) { s->failed_pc=0x0c03a394u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03a396;
P_0c03a396: /* original 8b03, guest PC 0x0c03a396 */
if(!s->budget--) { s->failed_pc=0x0c03a396u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a3a0; }
goto P_0c03a398;
P_0c03a398: /* original f08d, guest PC 0x0c03a398 */
if(!s->budget--) { s->failed_pc=0x0c03a398u; return 0; }
fr[0]=0;
goto P_0c03a39a;
P_0c03a39a: /* original 000b, guest PC 0x0c03a39a */
if(!s->budget--) { s->failed_pc=0x0c03a39au; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c03a39c: /* original 7f04, guest PC 0x0c03a39c */
if(!s->budget--) { s->failed_pc=0x0c03a39cu; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c03a39eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a39eu; return 0; } return 1;
P_0c03a3a0: /* original 65f3, guest PC 0x0c03a3a0 */
if(!s->budget--) { s->failed_pc=0x0c03a3a0u; return 0; }
r[5]=r[15];
goto P_0c03a3a2;
P_0c03a3a2: /* original e2e9, guest PC 0x0c03a3a2 */
if(!s->budget--) { s->failed_pc=0x0c03a3a2u; return 0; }
r[2]=0xffffffe9u;
goto P_0c03a3a4;
P_0c03a3a4: /* original e701, guest PC 0x0c03a3a4 */
if(!s->budget--) { s->failed_pc=0x0c03a3a4u; return 0; }
r[7]=0x00000001u;
goto P_0c03a3a6;
P_0c03a3a6: /* original ff4a, guest PC 0x0c03a3a6 */
if(!s->budget--) { s->failed_pc=0x0c03a3a6u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c03a3a8;
P_0c03a3a8: /* original 6352, guest PC 0x0c03a3a8 */
if(!s->budget--) { s->failed_pc=0x0c03a3a8u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c03a3aa;
P_0c03a3aa: /* original d611, guest PC 0x0c03a3aa */
if(!s->budget--) { s->failed_pc=0x0c03a3aau; return 0; }
r[6]=read(ram,0x0c03a3f0u,4);
goto P_0c03a3ac;
P_0c03a3ac: /* original 432c, guest PC 0x0c03a3ac */
if(!s->budget--) { s->failed_pc=0x0c03a3acu; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c03a3ae;
P_0c03a3ae: /* original 633c, guest PC 0x0c03a3ae */
if(!s->budget--) { s->failed_pc=0x0c03a3aeu; return 0; }
r[3]=r[3]&255u;
goto P_0c03a3b0;
P_0c03a3b0: /* original 343c, guest PC 0x0c03a3b0 */
if(!s->budget--) { s->failed_pc=0x0c03a3b0u; return 0; }
r[4]+=r[3];
goto P_0c03a3b2;
P_0c03a3b2: /* original 3473, guest PC 0x0c03a3b2 */
if(!s->budget--) { s->failed_pc=0x0c03a3b2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[7])!=0);
goto P_0c03a3b4;
P_0c03a3b4: /* original 8924, guest PC 0x0c03a3b4 */
if(!s->budget--) { s->failed_pc=0x0c03a3b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03a400; }
goto P_0c03a3b6;
P_0c03a3b6: /* original 6252, guest PC 0x0c03a3b6 */
if(!s->budget--) { s->failed_pc=0x0c03a3b6u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c03a3b8;
P_0c03a3b8: /* original 3748, guest PC 0x0c03a3b8 */
if(!s->budget--) { s->failed_pc=0x0c03a3b8u; return 0; }
r[7]-=r[4];
goto P_0c03a3ba;
P_0c03a3ba: /* original d30e, guest PC 0x0c03a3ba */
if(!s->budget--) { s->failed_pc=0x0c03a3bau; return 0; }
r[3]=read(ram,0x0c03a3f4u,4);
goto P_0c03a3bc;
P_0c03a3bc: /* original 677b, guest PC 0x0c03a3bc */
if(!s->budget--) { s->failed_pc=0x0c03a3bcu; return 0; }
r[7]=0u-r[7];
goto P_0c03a3be;
P_0c03a3be: /* original d10e, guest PC 0x0c03a3be */
if(!s->budget--) { s->failed_pc=0x0c03a3beu; return 0; }
r[1]=read(ram,0x0c03a3f8u,4);
goto P_0c03a3c0;
P_0c03a3c0: /* original 2239, guest PC 0x0c03a3c0 */
if(!s->budget--) { s->failed_pc=0x0c03a3c0u; return 0; }
r[2]&=r[3];
goto P_0c03a3c2;
P_0c03a3c2: /* original 6052, guest PC 0x0c03a3c2 */
if(!s->budget--) { s->failed_pc=0x0c03a3c2u; return 0; }
tmp=read(ram,r[5],4);
r[0]=tmp;
goto P_0c03a3c4;
P_0c03a3c4: /* original 221b, guest PC 0x0c03a3c4 */
if(!s->budget--) { s->failed_pc=0x0c03a3c4u; return 0; }
r[2]|=r[1];
goto P_0c03a3c6;
P_0c03a3c6: /* original 427c, guest PC 0x0c03a3c6 */
if(!s->budget--) { s->failed_pc=0x0c03a3c6u; return 0; }
r[2]=(r[7]&0x80000000u)?((r[7]&31u)?(uint32_t)((int32_t)r[2]>>((-r[7])&31u)):((int32_t)r[2]<0?0xffffffffu:0)):r[2]<<(r[7]&31u);
goto P_0c03a3c8;
P_0c03a3c8: /* original 2069, guest PC 0x0c03a3c8 */
if(!s->budget--) { s->failed_pc=0x0c03a3c8u; return 0; }
r[0]&=r[6];
goto P_0c03a3ca;
P_0c03a3ca: /* original 6423, guest PC 0x0c03a3ca */
if(!s->budget--) { s->failed_pc=0x0c03a3cau; return 0; }
r[4]=r[2];
goto P_0c03a3cc;
P_0c03a3cc: /* original 6203, guest PC 0x0c03a3cc */
if(!s->budget--) { s->failed_pc=0x0c03a3ccu; return 0; }
r[2]=r[0];
goto P_0c03a3ce;
P_0c03a3ce: /* original 224b, guest PC 0x0c03a3ce */
if(!s->budget--) { s->failed_pc=0x0c03a3ceu; return 0; }
r[2]|=r[4];
goto P_0c03a3d0;
P_0c03a3d0: /* original a02f, guest PC 0x0c03a3d0 */
if(!s->budget--) { s->failed_pc=0x0c03a3d0u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c03a432;
P_0c03a3d2: /* original 2522, guest PC 0x0c03a3d2 */
if(!s->budget--) { s->failed_pc=0x0c03a3d2u; return 0; }
write(ram,r[5],r[2],4);
if(!vf3_matrix_family(0x0c03a3d4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a3d4u; return 0; } return 1;
P_0c03a400: /* original 936e, guest PC 0x0c03a400 */
if(!s->budget--) { s->failed_pc=0x0c03a400u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a4e0u,2);
goto P_0c03a402;
P_0c03a402: /* original 3437, guest PC 0x0c03a402 */
if(!s->budget--) { s->failed_pc=0x0c03a402u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c03a404;
P_0c03a404: /* original 8b0c, guest PC 0x0c03a404 */
if(!s->budget--) { s->failed_pc=0x0c03a404u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a420; }
goto P_0c03a406;
P_0c03a406: /* original 6152, guest PC 0x0c03a406 */
if(!s->budget--) { s->failed_pc=0x0c03a406u; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c03a408;
P_0c03a408: /* original d236, guest PC 0x0c03a408 */
if(!s->budget--) { s->failed_pc=0x0c03a408u; return 0; }
r[2]=read(ram,0x0c03a4e4u,4);
goto P_0c03a40a;
P_0c03a40a: /* original 2169, guest PC 0x0c03a40a */
if(!s->budget--) { s->failed_pc=0x0c03a40au; return 0; }
r[1]&=r[6];
goto P_0c03a40c;
P_0c03a40c: /* original 6013, guest PC 0x0c03a40c */
if(!s->budget--) { s->failed_pc=0x0c03a40cu; return 0; }
r[0]=r[1];
goto P_0c03a40e;
P_0c03a40e: /* original 202b, guest PC 0x0c03a40e */
if(!s->budget--) { s->failed_pc=0x0c03a40eu; return 0; }
r[0]|=r[2];
goto P_0c03a410;
P_0c03a410: /* original a00f, guest PC 0x0c03a410 */
if(!s->budget--) { s->failed_pc=0x0c03a410u; return 0; }
write(ram,r[5],r[0],4);
goto P_0c03a432;
P_0c03a412: /* original 2502, guest PC 0x0c03a412 */
if(!s->budget--) { s->failed_pc=0x0c03a412u; return 0; }
write(ram,r[5],r[0],4);
if(!vf3_matrix_family(0x0c03a414u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a414u; return 0; } return 1;
P_0c03a420: /* original 6252, guest PC 0x0c03a420 */
if(!s->budget--) { s->failed_pc=0x0c03a420u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c03a422;
P_0c03a422: /* original d331, guest PC 0x0c03a422 */
if(!s->budget--) { s->failed_pc=0x0c03a422u; return 0; }
r[3]=read(ram,0x0c03a4e8u,4);
goto P_0c03a424;
P_0c03a424: /* original 2239, guest PC 0x0c03a424 */
if(!s->budget--) { s->failed_pc=0x0c03a424u; return 0; }
r[2]&=r[3];
goto P_0c03a426;
P_0c03a426: /* original 2522, guest PC 0x0c03a426 */
if(!s->budget--) { s->failed_pc=0x0c03a426u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c03a428;
P_0c03a428: /* original e217, guest PC 0x0c03a428 */
if(!s->budget--) { s->failed_pc=0x0c03a428u; return 0; }
r[2]=0x00000017u;
goto P_0c03a42a;
P_0c03a42a: /* original 6152, guest PC 0x0c03a42a */
if(!s->budget--) { s->failed_pc=0x0c03a42au; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c03a42c;
P_0c03a42c: /* original 442c, guest PC 0x0c03a42c */
if(!s->budget--) { s->failed_pc=0x0c03a42cu; return 0; }
r[4]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[4]>>((-r[2])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[2]&31u);
goto P_0c03a42e;
P_0c03a42e: /* original 214b, guest PC 0x0c03a42e */
if(!s->budget--) { s->failed_pc=0x0c03a42eu; return 0; }
r[1]|=r[4];
goto P_0c03a430;
P_0c03a430: /* original 2512, guest PC 0x0c03a430 */
if(!s->budget--) { s->failed_pc=0x0c03a430u; return 0; }
write(ram,r[5],r[1],4);
goto P_0c03a432;
P_0c03a432: /* original f0f8, guest PC 0x0c03a432 */
if(!s->budget--) { s->failed_pc=0x0c03a432u; return 0; }
vf3_matrix_load(s,ram,0,r[15]);
goto P_0c03a434;
P_0c03a434: /* original 000b, guest PC 0x0c03a434 */
if(!s->budget--) { s->failed_pc=0x0c03a434u; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c03a436: /* original 7f04, guest PC 0x0c03a436 */
if(!s->budget--) { s->failed_pc=0x0c03a436u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c03a438u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a438u; return 0; } return 1;
P_0c03a440: /* original f38d, guest PC 0x0c03a440 */
if(!s->budget--) { s->failed_pc=0x0c03a440u; return 0; }
fr[3]=0;
goto P_0c03a442;
P_0c03a442: /* original f345, guest PC 0x0c03a442 */
if(!s->budget--) { s->failed_pc=0x0c03a442u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c03a444;
P_0c03a444: /* original e401, guest PC 0x0c03a444 */
if(!s->budget--) { s->failed_pc=0x0c03a444u; return 0; }
r[4]=0x00000001u;
goto P_0c03a446;
P_0c03a446: /* original 8d03, guest PC 0x0c03a446 */
if(!s->budget--) { s->failed_pc=0x0c03a446u; return 0; }
cond=r[17]&1u;
fr[6]=0;
if(cond) { goto P_0c03a450; }
goto P_0c03a44a;
P_0c03a448: /* original f68d, guest PC 0x0c03a448 */
if(!s->budget--) { s->failed_pc=0x0c03a448u; return 0; }
fr[6]=0;
goto P_0c03a44a;
P_0c03a44a: /* original f38d, guest PC 0x0c03a44a */
if(!s->budget--) { s->failed_pc=0x0c03a44au; return 0; }
fr[3]=0;
goto P_0c03a44c;
P_0c03a44c: /* original f434, guest PC 0x0c03a44c */
if(!s->budget--) { s->failed_pc=0x0c03a44cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c03a44e;
P_0c03a44e: /* original 8b07, guest PC 0x0c03a44e */
if(!s->budget--) { s->failed_pc=0x0c03a44eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a460; }
goto P_0c03a450;
P_0c03a450: /* original 000b, guest PC 0x0c03a450 */
if(!s->budget--) { s->failed_pc=0x0c03a450u; return 0; }
target=r[16];
fr[0]=0;
s->pc=target; return ram->oob==0;
P_0c03a452: /* original f08d, guest PC 0x0c03a452 */
if(!s->budget--) { s->failed_pc=0x0c03a452u; return 0; }
fr[0]=0;
if(!vf3_matrix_family(0x0c03a454u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a454u; return 0; } return 1;
P_0c03a460: /* original c722, guest PC 0x0c03a460 */
if(!s->budget--) { s->failed_pc=0x0c03a460u; return 0; }
r[0]=code_base|0x0003a4ecu;
goto P_0c03a462;
P_0c03a462: /* original f708, guest PC 0x0c03a462 */
if(!s->budget--) { s->failed_pc=0x0c03a462u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c03a464;
P_0c03a464: /* original c722, guest PC 0x0c03a464 */
if(!s->budget--) { s->failed_pc=0x0c03a464u; return 0; }
r[0]=code_base|0x0003a4f0u;
goto P_0c03a466;
P_0c03a466: /* original f508, guest PC 0x0c03a466 */
if(!s->budget--) { s->failed_pc=0x0c03a466u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03a468;
P_0c03a468: /* original f545, guest PC 0x0c03a468 */
if(!s->budget--) { s->failed_pc=0x0c03a468u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c03a46a;
P_0c03a46a: /* original 8903, guest PC 0x0c03a46a */
if(!s->budget--) { s->failed_pc=0x0c03a46au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03a474; }
goto P_0c03a46c;
P_0c03a46c: /* original f453, guest PC 0x0c03a46c */
if(!s->budget--) { s->failed_pc=0x0c03a46cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'/');
goto P_0c03a46e;
P_0c03a46e: /* original f545, guest PC 0x0c03a46e */
if(!s->budget--) { s->failed_pc=0x0c03a46eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c03a470;
P_0c03a470: /* original 8ffc, guest PC 0x0c03a470 */
if(!s->budget--) { s->failed_pc=0x0c03a470u; return 0; }
cond=r[17]&1u;
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'+');
if(!cond) { goto P_0c03a46c; }
goto P_0c03a474;
P_0c03a472: /* original f670, guest PC 0x0c03a472 */
if(!s->budget--) { s->failed_pc=0x0c03a472u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'+');
goto P_0c03a474;
P_0c03a474: /* original f89d, guest PC 0x0c03a474 */
if(!s->budget--) { s->failed_pc=0x0c03a474u; return 0; }
fr[8]=0x3f800000u;
goto P_0c03a476;
P_0c03a476: /* original f845, guest PC 0x0c03a476 */
if(!s->budget--) { s->failed_pc=0x0c03a476u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[4]))!=0);
goto P_0c03a478;
P_0c03a478: /* original 8b03, guest PC 0x0c03a478 */
if(!s->budget--) { s->failed_pc=0x0c03a478u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a482; }
goto P_0c03a47a;
P_0c03a47a: /* original f452, guest PC 0x0c03a47a */
if(!s->budget--) { s->failed_pc=0x0c03a47au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c03a47c;
P_0c03a47c: /* original f845, guest PC 0x0c03a47c */
if(!s->budget--) { s->failed_pc=0x0c03a47cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[4]))!=0);
goto P_0c03a47e;
P_0c03a47e: /* original 8dfc, guest PC 0x0c03a47e */
if(!s->budget--) { s->failed_pc=0x0c03a47eu; return 0; }
cond=r[17]&1u;
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'-');
if(cond) { goto P_0c03a47a; }
goto P_0c03a482;
P_0c03a480: /* original f671, guest PC 0x0c03a480 */
if(!s->budget--) { s->failed_pc=0x0c03a480u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'-');
goto P_0c03a482;
P_0c03a482: /* original c71c, guest PC 0x0c03a482 */
if(!s->budget--) { s->failed_pc=0x0c03a482u; return 0; }
r[0]=code_base|0x0003a4f4u;
goto P_0c03a484;
P_0c03a484: /* original f24c, guest PC 0x0c03a484 */
if(!s->budget--) { s->failed_pc=0x0c03a484u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03a486;
P_0c03a486: /* original f308, guest PC 0x0c03a486 */
if(!s->budget--) { s->failed_pc=0x0c03a486u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03a488;
P_0c03a488: /* original f14c, guest PC 0x0c03a488 */
if(!s->budget--) { s->failed_pc=0x0c03a488u; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c03a48a;
P_0c03a48a: /* original f180, guest PC 0x0c03a48a */
if(!s->budget--) { s->failed_pc=0x0c03a48au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[8],r[18],'+');
goto P_0c03a48c;
P_0c03a48c: /* original f230, guest PC 0x0c03a48c */
if(!s->budget--) { s->failed_pc=0x0c03a48cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c03a48e;
P_0c03a48e: /* original f42c, guest PC 0x0c03a48e */
if(!s->budget--) { s->failed_pc=0x0c03a48eu; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c03a490;
P_0c03a490: /* original f413, guest PC 0x0c03a490 */
if(!s->budget--) { s->failed_pc=0x0c03a490u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'/');
goto P_0c03a492;
P_0c03a492: /* original f25c, guest PC 0x0c03a492 */
if(!s->budget--) { s->failed_pc=0x0c03a492u; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c03a494;
P_0c03a494: /* original f54c, guest PC 0x0c03a494 */
if(!s->budget--) { s->failed_pc=0x0c03a494u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c03a496;
P_0c03a496: /* original f522, guest PC 0x0c03a496 */
if(!s->budget--) { s->failed_pc=0x0c03a496u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'*');
goto P_0c03a498;
P_0c03a498: /* original f24c, guest PC 0x0c03a498 */
if(!s->budget--) { s->failed_pc=0x0c03a498u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03a49a;
P_0c03a49a: /* original f422, guest PC 0x0c03a49a */
if(!s->budget--) { s->failed_pc=0x0c03a49au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'*');
goto P_0c03a49c;
P_0c03a49c: /* original 445a, guest PC 0x0c03a49c */
if(!s->budget--) { s->failed_pc=0x0c03a49cu; return 0; }
r[53]=r[4];
goto P_0c03a49e;
P_0c03a49e: /* original f25c, guest PC 0x0c03a49e */
if(!s->budget--) { s->failed_pc=0x0c03a49eu; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c03a4a0;
P_0c03a4a0: /* original f542, guest PC 0x0c03a4a0 */
if(!s->budget--) { s->failed_pc=0x0c03a4a0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c03a4a2;
P_0c03a4a2: /* original f76c, guest PC 0x0c03a4a2 */
if(!s->budget--) { s->failed_pc=0x0c03a4a2u; return 0; }
vf3_matrix_move(s,7,6);
goto P_0c03a4a4;
P_0c03a4a4: /* original f32d, guest PC 0x0c03a4a4 */
if(!s->budget--) { s->failed_pc=0x0c03a4a4u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a4a6;
P_0c03a4a6: /* original f233, guest PC 0x0c03a4a6 */
if(!s->budget--) { s->failed_pc=0x0c03a4a6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'/');
goto P_0c03a4a8;
P_0c03a4a8: /* original f620, guest PC 0x0c03a4a8 */
if(!s->budget--) { s->failed_pc=0x0c03a4a8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'+');
goto P_0c03a4aa;
P_0c03a4aa: /* original f674, guest PC 0x0c03a4aa */
if(!s->budget--) { s->failed_pc=0x0c03a4aau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])==as_float(fr[7]))!=0);
goto P_0c03a4ac;
P_0c03a4ac: /* original 8ff6, guest PC 0x0c03a4ac */
if(!s->budget--) { s->failed_pc=0x0c03a4acu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000002u;
if(!cond) { goto P_0c03a49c; }
goto P_0c03a4b0;
P_0c03a4ae: /* original 7402, guest PC 0x0c03a4ae */
if(!s->budget--) { s->failed_pc=0x0c03a4aeu; return 0; }
r[4]+=0x00000002u;
goto P_0c03a4b0;
P_0c03a4b0: /* original f06c, guest PC 0x0c03a4b0 */
if(!s->budget--) { s->failed_pc=0x0c03a4b0u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c03a4b2;
P_0c03a4b2: /* original 000b, guest PC 0x0c03a4b2 */
if(!s->budget--) { s->failed_pc=0x0c03a4b2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03a4b4: /* original 0009, guest PC 0x0c03a4b4 */
if(!s->budget--) { s->failed_pc=0x0c03a4b4u; return 0; }
if(!vf3_matrix_family(0x0c03a4b6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a4b6u; return 0; } return 1;
P_0c03a50e: /* original 4f22, guest PC 0x0c03a50e */
if(!s->budget--) { s->failed_pc=0x0c03a50eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03a510;
P_0c03a510: /* original 8f06, guest PC 0x0c03a510 */
if(!s->budget--) { s->failed_pc=0x0c03a510u; return 0; }
cond=r[17]&1u;
r[4]=r[53];
if(!cond) { goto P_0c03a520; }
goto P_0c03a514;
P_0c03a512: /* original 045a, guest PC 0x0c03a512 */
if(!s->budget--) { s->failed_pc=0x0c03a512u; return 0; }
r[4]=r[53];
goto P_0c03a514;
P_0c03a514: /* original fe35, guest PC 0x0c03a514 */
if(!s->budget--) { s->failed_pc=0x0c03a514u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[3]))!=0);
goto P_0c03a516;
P_0c03a516: /* original 892e, guest PC 0x0c03a516 */
if(!s->budget--) { s->failed_pc=0x0c03a516u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03a576; }
goto P_0c03a518;
P_0c03a518: /* original a03a, guest PC 0x0c03a518 */
if(!s->budget--) { s->failed_pc=0x0c03a518u; return 0; }
fr[0]=0x3f800000u;
goto P_0c03a590;
P_0c03a51a: /* original f09d, guest PC 0x0c03a51a */
if(!s->budget--) { s->failed_pc=0x0c03a51au; return 0; }
fr[0]=0x3f800000u;
if(!vf3_matrix_family(0x0c03a51cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a51cu; return 0; } return 1;
P_0c03a520: /* original 445a, guest PC 0x0c03a520 */
if(!s->budget--) { s->failed_pc=0x0c03a520u; return 0; }
r[53]=r[4];
goto P_0c03a522;
P_0c03a522: /* original f32d, guest PC 0x0c03a522 */
if(!s->budget--) { s->failed_pc=0x0c03a522u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a524;
P_0c03a524: /* original fe34, guest PC 0x0c03a524 */
if(!s->budget--) { s->failed_pc=0x0c03a524u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])==as_float(fr[3]))!=0);
goto P_0c03a526;
P_0c03a526: /* original 8b23, guest PC 0x0c03a526 */
if(!s->budget--) { s->failed_pc=0x0c03a526u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a570; }
goto P_0c03a528;
P_0c03a528: /* original 4411, guest PC 0x0c03a528 */
if(!s->budget--) { s->failed_pc=0x0c03a528u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c03a52a;
P_0c03a52a: /* original 8d04, guest PC 0x0c03a52a */
if(!s->budget--) { s->failed_pc=0x0c03a52au; return 0; }
cond=r[17]&1u;
fr[5]=0x3f800000u;
if(cond) { goto P_0c03a536; }
goto P_0c03a52e;
P_0c03a52c: /* original f59d, guest PC 0x0c03a52c */
if(!s->budget--) { s->failed_pc=0x0c03a52cu; return 0; }
fr[5]=0x3f800000u;
goto P_0c03a52e;
P_0c03a52e: /* original f3fc, guest PC 0x0c03a52e */
if(!s->budget--) { s->failed_pc=0x0c03a52eu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c03a530;
P_0c03a530: /* original 644b, guest PC 0x0c03a530 */
if(!s->budget--) { s->failed_pc=0x0c03a530u; return 0; }
r[4]=0u-r[4];
goto P_0c03a532;
P_0c03a532: /* original ff5c, guest PC 0x0c03a532 */
if(!s->budget--) { s->failed_pc=0x0c03a532u; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c03a534;
P_0c03a534: /* original ff33, guest PC 0x0c03a534 */
if(!s->budget--) { s->failed_pc=0x0c03a534u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'/');
goto P_0c03a536;
P_0c03a536: /* original e501, guest PC 0x0c03a536 */
if(!s->budget--) { s->failed_pc=0x0c03a536u; return 0; }
r[5]=0x00000001u;
goto P_0c03a538;
P_0c03a538: /* original f45c, guest PC 0x0c03a538 */
if(!s->budget--) { s->failed_pc=0x0c03a538u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c03a53a;
P_0c03a53a: /* original 6243, guest PC 0x0c03a53a */
if(!s->budget--) { s->failed_pc=0x0c03a53au; return 0; }
r[2]=r[4];
goto P_0c03a53c;
P_0c03a53c: /* original 2258, guest PC 0x0c03a53c */
if(!s->budget--) { s->failed_pc=0x0c03a53cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c03a53e;
P_0c03a53e: /* original 8900, guest PC 0x0c03a53e */
if(!s->budget--) { s->failed_pc=0x0c03a53eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03a542; }
goto P_0c03a540;
P_0c03a540: /* original f4f2, guest PC 0x0c03a540 */
if(!s->budget--) { s->failed_pc=0x0c03a540u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c03a542;
P_0c03a542: /* original e300, guest PC 0x0c03a542 */
if(!s->budget--) { s->failed_pc=0x0c03a542u; return 0; }
r[3]=0x00000000u;
goto P_0c03a544;
P_0c03a544: /* original 3347, guest PC 0x0c03a544 */
if(!s->budget--) { s->failed_pc=0x0c03a544u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[4])!=0);
goto P_0c03a546;
P_0c03a546: /* original 343e, guest PC 0x0c03a546 */
if(!s->budget--) { s->failed_pc=0x0c03a546u; return 0; }
wide=(uint64_t)r[4]+r[3]+(r[17]&1u); r[4]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c03a548;
P_0c03a548: /* original 4421, guest PC 0x0c03a548 */
if(!s->budget--) { s->failed_pc=0x0c03a548u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]=(uint32_t)((int32_t)r[4]>>1);
goto P_0c03a54a;
P_0c03a54a: /* original 2448, guest PC 0x0c03a54a */
if(!s->budget--) { s->failed_pc=0x0c03a54au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03a54c;
P_0c03a54c: /* original 8908, guest PC 0x0c03a54c */
if(!s->budget--) { s->failed_pc=0x0c03a54cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03a560; }
goto P_0c03a54e;
P_0c03a54e: /* original aff4, guest PC 0x0c03a54e */
if(!s->budget--) { s->failed_pc=0x0c03a54eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[15],r[18],'*');
goto P_0c03a53a;
P_0c03a550: /* original fff2, guest PC 0x0c03a550 */
if(!s->budget--) { s->failed_pc=0x0c03a550u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[15],r[18],'*');
if(!vf3_matrix_family(0x0c03a552u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a552u; return 0; } return 1;
P_0c03a560: /* original a016, guest PC 0x0c03a560 */
if(!s->budget--) { s->failed_pc=0x0c03a560u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a590;
P_0c03a562: /* original f04c, guest PC 0x0c03a562 */
if(!s->budget--) { s->failed_pc=0x0c03a562u; return 0; }
vf3_matrix_move(s,0,4);
if(!vf3_matrix_family(0x0c03a564u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a564u; return 0; } return 1;
P_0c03a570: /* original f38d, guest PC 0x0c03a570 */
if(!s->budget--) { s->failed_pc=0x0c03a570u; return 0; }
fr[3]=0;
goto P_0c03a572;
P_0c03a572: /* original f3f5, guest PC 0x0c03a572 */
if(!s->budget--) { s->failed_pc=0x0c03a572u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c03a574;
P_0c03a574: /* original 8b04, guest PC 0x0c03a574 */
if(!s->budget--) { s->failed_pc=0x0c03a574u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a580; }
goto P_0c03a576;
P_0c03a576: /* original a00b, guest PC 0x0c03a576 */
if(!s->budget--) { s->failed_pc=0x0c03a576u; return 0; }
fr[0]=0;
goto P_0c03a590;
P_0c03a578: /* original f08d, guest PC 0x0c03a578 */
if(!s->budget--) { s->failed_pc=0x0c03a578u; return 0; }
fr[0]=0;
if(!vf3_matrix_family(0x0c03a57au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a57au; return 0; } return 1;
P_0c03a580: /* original bf5e, guest PC 0x0c03a580 */
if(!s->budget--) { s->failed_pc=0x0c03a580u; return 0; }
target=code_base|0x0c03a440u; r[16]=code_base|0x0c03a584u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03a584u) { target=s->pc; goto dispatch; }
goto P_0c03a584;
P_0c03a582: /* original f4fc, guest PC 0x0c03a582 */
if(!s->budget--) { s->failed_pc=0x0c03a582u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c03a584;
P_0c03a584: /* original 4f26, guest PC 0x0c03a584 */
if(!s->budget--) { s->failed_pc=0x0c03a584u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03a586;
P_0c03a586: /* original f4ec, guest PC 0x0c03a586 */
if(!s->budget--) { s->failed_pc=0x0c03a586u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c03a588;
P_0c03a588: /* original f402, guest PC 0x0c03a588 */
if(!s->budget--) { s->failed_pc=0x0c03a588u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[0],r[18],'*');
goto P_0c03a58a;
P_0c03a58a: /* original fef9, guest PC 0x0c03a58a */
if(!s->budget--) { s->failed_pc=0x0c03a58au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03a58c;
P_0c03a58c: /* original ae60, guest PC 0x0c03a58c */
if(!s->budget--) { s->failed_pc=0x0c03a58cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03a250;
P_0c03a58e: /* original fff9, guest PC 0x0c03a58e */
if(!s->budget--) { s->failed_pc=0x0c03a58eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03a590;
P_0c03a590: /* original 4f26, guest PC 0x0c03a590 */
if(!s->budget--) { s->failed_pc=0x0c03a590u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03a592;
P_0c03a592: /* original fef9, guest PC 0x0c03a592 */
if(!s->budget--) { s->failed_pc=0x0c03a592u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03a594;
P_0c03a594: /* original 000b, guest PC 0x0c03a594 */
if(!s->budget--) { s->failed_pc=0x0c03a594u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c03a596: /* original fff9, guest PC 0x0c03a596 */
if(!s->budget--) { s->failed_pc=0x0c03a596u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c03a598u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a598u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
