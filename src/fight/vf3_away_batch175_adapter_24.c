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
int vf3_away_batch175_adapter_24(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07b204u: goto P_0c07b204;
case 0x0c07b206u: goto P_0c07b206;
case 0x0c07b208u: goto P_0c07b208;
case 0x0c07b20au: goto P_0c07b20a;
case 0x0c07b20cu: goto P_0c07b20c;
case 0x0c07b20eu: goto P_0c07b20e;
case 0x0c07b210u: goto P_0c07b210;
case 0x0c07b212u: goto P_0c07b212;
case 0x0c07b214u: goto P_0c07b214;
case 0x0c07b216u: goto P_0c07b216;
case 0x0c07b218u: goto P_0c07b218;
case 0x0c07b21au: goto P_0c07b21a;
case 0x0c07b21cu: goto P_0c07b21c;
case 0x0c07b21eu: goto P_0c07b21e;
case 0x0c07b220u: goto P_0c07b220;
case 0x0c07b222u: goto P_0c07b222;
case 0x0c07b224u: goto P_0c07b224;
case 0x0c07b226u: goto P_0c07b226;
case 0x0c07b228u: goto P_0c07b228;
case 0x0c07b22au: goto P_0c07b22a;
case 0x0c07b22cu: goto P_0c07b22c;
case 0x0c07b22eu: goto P_0c07b22e;
case 0x0c07b230u: goto P_0c07b230;
case 0x0c07b232u: goto P_0c07b232;
case 0x0c07b234u: goto P_0c07b234;
case 0x0c07b236u: goto P_0c07b236;
case 0x0c07b238u: goto P_0c07b238;
case 0x0c07b23au: goto P_0c07b23a;
case 0x0c07b23cu: goto P_0c07b23c;
case 0x0c07b23eu: goto P_0c07b23e;
case 0x0c07b240u: goto P_0c07b240;
case 0x0c07b242u: goto P_0c07b242;
case 0x0c07b244u: goto P_0c07b244;
case 0x0c07b246u: goto P_0c07b246;
case 0x0c07b248u: goto P_0c07b248;
case 0x0c07b24au: goto P_0c07b24a;
case 0x0c07b24cu: goto P_0c07b24c;
case 0x0c07b24eu: goto P_0c07b24e;
case 0x0c07b250u: goto P_0c07b250;
case 0x0c07b252u: goto P_0c07b252;
case 0x0c07b254u: goto P_0c07b254;
case 0x0c07b256u: goto P_0c07b256;
case 0x0c07b258u: goto P_0c07b258;
case 0x0c07b25au: goto P_0c07b25a;
case 0x0c07b25cu: goto P_0c07b25c;
case 0x0c07b25eu: goto P_0c07b25e;
case 0x0c07b260u: goto P_0c07b260;
case 0x0c07b262u: goto P_0c07b262;
case 0x0c07b264u: goto P_0c07b264;
case 0x0c07b266u: goto P_0c07b266;
case 0x0c07b268u: goto P_0c07b268;
case 0x0c07b26au: goto P_0c07b26a;
case 0x0c07b26cu: goto P_0c07b26c;
case 0x0c07b26eu: goto P_0c07b26e;
case 0x0c07b270u: goto P_0c07b270;
case 0x0c07b272u: goto P_0c07b272;
case 0x0c07b274u: goto P_0c07b274;
case 0x0c07b276u: goto P_0c07b276;
case 0x0c07b278u: goto P_0c07b278;
case 0x0c07b27au: goto P_0c07b27a;
case 0x0c07b27cu: goto P_0c07b27c;
case 0x0c07b27eu: goto P_0c07b27e;
case 0x0c07b280u: goto P_0c07b280;
case 0x0c07b282u: goto P_0c07b282;
case 0x0c07b284u: goto P_0c07b284;
case 0x0c07b286u: goto P_0c07b286;
case 0x0c07b288u: goto P_0c07b288;
case 0x0c07b28au: goto P_0c07b28a;
case 0x0c07b28cu: goto P_0c07b28c;
case 0x0c07b28eu: goto P_0c07b28e;
case 0x0c07b290u: goto P_0c07b290;
case 0x0c07b292u: goto P_0c07b292;
case 0x0c07b294u: goto P_0c07b294;
case 0x0c07b296u: goto P_0c07b296;
case 0x0c07b298u: goto P_0c07b298;
case 0x0c07b29au: goto P_0c07b29a;
case 0x0c07b29cu: goto P_0c07b29c;
case 0x0c07b29eu: goto P_0c07b29e;
case 0x0c07b2a0u: goto P_0c07b2a0;
case 0x0c07b2a2u: goto P_0c07b2a2;
case 0x0c07b2a4u: goto P_0c07b2a4;
case 0x0c07b2a6u: goto P_0c07b2a6;
case 0x0c07b2a8u: goto P_0c07b2a8;
case 0x0c07b2aau: goto P_0c07b2aa;
case 0x0c07b2acu: goto P_0c07b2ac;
case 0x0c07b2aeu: goto P_0c07b2ae;
case 0x0c07b2b0u: goto P_0c07b2b0;
case 0x0c07b2b2u: goto P_0c07b2b2;
case 0x0c07b2b4u: goto P_0c07b2b4;
case 0x0c07b2b6u: goto P_0c07b2b6;
case 0x0c07b2b8u: goto P_0c07b2b8;
case 0x0c07b2bau: goto P_0c07b2ba;
case 0x0c07b2bcu: goto P_0c07b2bc;
case 0x0c07b5b0u: goto P_0c07b5b0;
case 0x0c07b5b2u: goto P_0c07b5b2;
case 0x0c07b5b4u: goto P_0c07b5b4;
case 0x0c07b5b6u: goto P_0c07b5b6;
case 0x0c07b5b8u: goto P_0c07b5b8;
case 0x0c07b5bau: goto P_0c07b5ba;
case 0x0c07b5bcu: goto P_0c07b5bc;
case 0x0c07b5beu: goto P_0c07b5be;
case 0x0c07b5c0u: goto P_0c07b5c0;
case 0x0c07b5c2u: goto P_0c07b5c2;
case 0x0c07b5c4u: goto P_0c07b5c4;
case 0x0c07b5c6u: goto P_0c07b5c6;
case 0x0c07b5c8u: goto P_0c07b5c8;
case 0x0c07b5cau: goto P_0c07b5ca;
case 0x0c07b5ccu: goto P_0c07b5cc;
case 0x0c07b5f0u: goto P_0c07b5f0;
case 0x0c07b5f2u: goto P_0c07b5f2;
case 0x0c07b5f4u: goto P_0c07b5f4;
case 0x0c07b5f6u: goto P_0c07b5f6;
case 0x0c07b5f8u: goto P_0c07b5f8;
case 0x0c07b5fau: goto P_0c07b5fa;
case 0x0c07b5fcu: goto P_0c07b5fc;
case 0x0c07b5feu: goto P_0c07b5fe;
case 0x0c07b600u: goto P_0c07b600;
case 0x0c07b602u: goto P_0c07b602;
case 0x0c07b604u: goto P_0c07b604;
case 0x0c07b606u: goto P_0c07b606;
case 0x0c07b608u: goto P_0c07b608;
case 0x0c07b60au: goto P_0c07b60a;
case 0x0c07b60cu: goto P_0c07b60c;
case 0x0c07b60eu: goto P_0c07b60e;
case 0x0c07b610u: goto P_0c07b610;
case 0x0c07b612u: goto P_0c07b612;
case 0x0c07b614u: goto P_0c07b614;
case 0x0c07b616u: goto P_0c07b616;
case 0x0c07b618u: goto P_0c07b618;
case 0x0c07b61au: goto P_0c07b61a;
case 0x0c07b61cu: goto P_0c07b61c;
case 0x0c07b61eu: goto P_0c07b61e;
case 0x0c07b620u: goto P_0c07b620;
case 0x0c07b622u: goto P_0c07b622;
case 0x0c07b624u: goto P_0c07b624;
case 0x0c07b626u: goto P_0c07b626;
case 0x0c07b628u: goto P_0c07b628;
case 0x0c07b62au: goto P_0c07b62a;
case 0x0c07b62cu: goto P_0c07b62c;
case 0x0c07b62eu: goto P_0c07b62e;
case 0x0c07b630u: goto P_0c07b630;
case 0x0c07b632u: goto P_0c07b632;
case 0x0c07b634u: goto P_0c07b634;
case 0x0c07b636u: goto P_0c07b636;
case 0x0c07b638u: goto P_0c07b638;
case 0x0c07b63au: goto P_0c07b63a;
case 0x0c07b63cu: goto P_0c07b63c;
case 0x0c07b63eu: goto P_0c07b63e;
case 0x0c07b640u: goto P_0c07b640;
case 0x0c07b642u: goto P_0c07b642;
case 0x0c07b644u: goto P_0c07b644;
case 0x0c07b646u: goto P_0c07b646;
case 0x0c07b648u: goto P_0c07b648;
case 0x0c07b64au: goto P_0c07b64a;
case 0x0c07b64cu: goto P_0c07b64c;
case 0x0c07b64eu: goto P_0c07b64e;
case 0x0c07b650u: goto P_0c07b650;
case 0x0c07b652u: goto P_0c07b652;
case 0x0c07b654u: goto P_0c07b654;
case 0x0c07b656u: goto P_0c07b656;
case 0x0c07b658u: goto P_0c07b658;
case 0x0c07b65au: goto P_0c07b65a;
case 0x0c07b65cu: goto P_0c07b65c;
case 0x0c07b65eu: goto P_0c07b65e;
case 0x0c07b660u: goto P_0c07b660;
case 0x0c07b662u: goto P_0c07b662;
case 0x0c07b664u: goto P_0c07b664;
case 0x0c07b666u: goto P_0c07b666;
case 0x0c07b668u: goto P_0c07b668;
case 0x0c07b66au: goto P_0c07b66a;
case 0x0c07b66cu: goto P_0c07b66c;
case 0x0c08b430u: goto P_0c08b430;
case 0x0c08b432u: goto P_0c08b432;
case 0x0c08b434u: goto P_0c08b434;
case 0x0c08b436u: goto P_0c08b436;
case 0x0c08b438u: goto P_0c08b438;
case 0x0c08b43au: goto P_0c08b43a;
case 0x0c08b43cu: goto P_0c08b43c;
case 0x0c08b43eu: goto P_0c08b43e;
case 0x0c08b440u: goto P_0c08b440;
case 0x0c08b442u: goto P_0c08b442;
case 0x0c08b444u: goto P_0c08b444;
case 0x0c08b446u: goto P_0c08b446;
case 0x0c08b448u: goto P_0c08b448;
case 0x0c08b44au: goto P_0c08b44a;
case 0x0c08b44cu: goto P_0c08b44c;
case 0x0c08b44eu: goto P_0c08b44e;
case 0x0c08b450u: goto P_0c08b450;
case 0x0c08b452u: goto P_0c08b452;
case 0x0c08b454u: goto P_0c08b454;
case 0x0c08b456u: goto P_0c08b456;
case 0x0c08b458u: goto P_0c08b458;
case 0x0c08b45au: goto P_0c08b45a;
case 0x0c08b45cu: goto P_0c08b45c;
case 0x0c08b45eu: goto P_0c08b45e;
case 0x0c08b460u: goto P_0c08b460;
case 0x0c08b462u: goto P_0c08b462;
case 0x0c08b464u: goto P_0c08b464;
case 0x0c08b466u: goto P_0c08b466;
case 0x0c08b468u: goto P_0c08b468;
case 0x0c08b46au: goto P_0c08b46a;
case 0x0c08b46cu: goto P_0c08b46c;
case 0x0c08b46eu: goto P_0c08b46e;
case 0x0c08b470u: goto P_0c08b470;
case 0x0c08b472u: goto P_0c08b472;
case 0x0c08b474u: goto P_0c08b474;
case 0x0c08b476u: goto P_0c08b476;
case 0x0c08b478u: goto P_0c08b478;
case 0x0c08b47au: goto P_0c08b47a;
case 0x0c08b47cu: goto P_0c08b47c;
case 0x0c08b47eu: goto P_0c08b47e;
case 0x0c08b480u: goto P_0c08b480;
case 0x0c08b482u: goto P_0c08b482;
case 0x0c08b484u: goto P_0c08b484;
case 0x0c08b486u: goto P_0c08b486;
case 0x0c08b488u: goto P_0c08b488;
case 0x0c08b48au: goto P_0c08b48a;
case 0x0c08b48cu: goto P_0c08b48c;
case 0x0c08b48eu: goto P_0c08b48e;
case 0x0c08b490u: goto P_0c08b490;
case 0x0c08b492u: goto P_0c08b492;
case 0x0c08b494u: goto P_0c08b494;
case 0x0c08b496u: goto P_0c08b496;
case 0x0c08b498u: goto P_0c08b498;
case 0x0c08b49au: goto P_0c08b49a;
case 0x0c08b49cu: goto P_0c08b49c;
case 0x0c08b49eu: goto P_0c08b49e;
case 0x0c08b4a0u: goto P_0c08b4a0;
case 0x0c08b4a2u: goto P_0c08b4a2;
case 0x0c08b4a4u: goto P_0c08b4a4;
case 0x0c08b4a6u: goto P_0c08b4a6;
case 0x0c08b4a8u: goto P_0c08b4a8;
case 0x0c08b4aau: goto P_0c08b4aa;
case 0x0c08b4acu: goto P_0c08b4ac;
case 0x0c08b4aeu: goto P_0c08b4ae;
case 0x0c08b4b0u: goto P_0c08b4b0;
case 0x0c08b4b2u: goto P_0c08b4b2;
case 0x0c08b4b4u: goto P_0c08b4b4;
case 0x0c08b4b6u: goto P_0c08b4b6;
case 0x0c08b4b8u: goto P_0c08b4b8;
case 0x0c08b4bau: goto P_0c08b4ba;
case 0x0c08b4bcu: goto P_0c08b4bc;
case 0x0c08b4beu: goto P_0c08b4be;
case 0x0c08b4c0u: goto P_0c08b4c0;
case 0x0c08b4c2u: goto P_0c08b4c2;
case 0x0c08b4c4u: goto P_0c08b4c4;
case 0x0c08b4c6u: goto P_0c08b4c6;
case 0x0c08b4c8u: goto P_0c08b4c8;
case 0x0c08b4cau: goto P_0c08b4ca;
case 0x0c08b4ccu: goto P_0c08b4cc;
case 0x0c08b4ceu: goto P_0c08b4ce;
case 0x0c08b4d0u: goto P_0c08b4d0;
case 0x0c08b4d2u: goto P_0c08b4d2;
case 0x0c08b4d4u: goto P_0c08b4d4;
case 0x0c08b4d6u: goto P_0c08b4d6;
case 0x0c08b4d8u: goto P_0c08b4d8;
case 0x0c08b4dau: goto P_0c08b4da;
case 0x0c08b4dcu: goto P_0c08b4dc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07b204: /* original 2fe6, guest PC 0x0c07b204 */
if(!s->budget--) { s->failed_pc=0x0c07b204u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b206;
P_0c07b206: /* original e400, guest PC 0x0c07b206 */
if(!s->budget--) { s->failed_pc=0x0c07b206u; return 0; }
r[4]=0x00000000u;
goto P_0c07b208;
P_0c07b208: /* original 2fd6, guest PC 0x0c07b208 */
if(!s->budget--) { s->failed_pc=0x0c07b208u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b20a;
P_0c07b20a: /* original e654, guest PC 0x0c07b20a */
if(!s->budget--) { s->failed_pc=0x0c07b20au; return 0; }
r[6]=0x00000054u;
goto P_0c07b20c;
P_0c07b20c: /* original 2fc6, guest PC 0x0c07b20c */
if(!s->budget--) { s->failed_pc=0x0c07b20cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b20e;
P_0c07b20e: /* original 2fb6, guest PC 0x0c07b20e */
if(!s->budget--) { s->failed_pc=0x0c07b20eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b210;
P_0c07b210: /* original eb00, guest PC 0x0c07b210 */
if(!s->budget--) { s->failed_pc=0x0c07b210u; return 0; }
r[11]=0x00000000u;
goto P_0c07b212;
P_0c07b212: /* original 2fa6, guest PC 0x0c07b212 */
if(!s->budget--) { s->failed_pc=0x0c07b212u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b214;
P_0c07b214: /* original 65b3, guest PC 0x0c07b214 */
if(!s->budget--) { s->failed_pc=0x0c07b214u; return 0; }
r[5]=r[11];
goto P_0c07b216;
P_0c07b216: /* original 4f22, guest PC 0x0c07b216 */
if(!s->budget--) { s->failed_pc=0x0c07b216u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b218;
P_0c07b218: /* original d348, guest PC 0x0c07b218 */
if(!s->budget--) { s->failed_pc=0x0c07b218u; return 0; }
r[3]=read(ram,0x0c07b33cu,4);
goto P_0c07b21a;
P_0c07b21a: /* original d249, guest PC 0x0c07b21a */
if(!s->budget--) { s->failed_pc=0x0c07b21au; return 0; }
r[2]=read(ram,0x0c07b340u,4);
goto P_0c07b21c;
P_0c07b21c: /* original 6e32, guest PC 0x0c07b21c */
if(!s->budget--) { s->failed_pc=0x0c07b21cu; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c07b21e;
P_0c07b21e: /* original 7ffc, guest PC 0x0c07b21e */
if(!s->budget--) { s->failed_pc=0x0c07b21eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07b220;
P_0c07b220: /* original 2f22, guest PC 0x0c07b220 */
if(!s->budget--) { s->failed_pc=0x0c07b220u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c07b222;
P_0c07b222: /* original dd48, guest PC 0x0c07b222 */
if(!s->budget--) { s->failed_pc=0x0c07b222u; return 0; }
r[13]=read(ram,0x0c07b344u,4);
goto P_0c07b224;
P_0c07b224: /* original 34dc, guest PC 0x0c07b224 */
if(!s->budget--) { s->failed_pc=0x0c07b224u; return 0; }
r[4]+=r[13];
goto P_0c07b226;
P_0c07b226: /* original 7501, guest PC 0x0c07b226 */
if(!s->budget--) { s->failed_pc=0x0c07b226u; return 0; }
r[5]+=0x00000001u;
goto P_0c07b228;
P_0c07b228: /* original 24b1, guest PC 0x0c07b228 */
if(!s->budget--) { s->failed_pc=0x0c07b228u; return 0; }
write(ram,r[4],r[11],2);
goto P_0c07b22a;
P_0c07b22a: /* original 3563, guest PC 0x0c07b22a */
if(!s->budget--) { s->failed_pc=0x0c07b22au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c07b22c;
P_0c07b22c: /* original 8ffb, guest PC 0x0c07b22c */
if(!s->budget--) { s->failed_pc=0x0c07b22cu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000002u;
if(!cond) { goto P_0c07b226; }
goto P_0c07b230;
P_0c07b22e: /* original 7402, guest PC 0x0c07b22e */
if(!s->budget--) { s->failed_pc=0x0c07b22eu; return 0; }
r[4]+=0x00000002u;
goto P_0c07b230;
P_0c07b230: /* original d245, guest PC 0x0c07b230 */
if(!s->budget--) { s->failed_pc=0x0c07b230u; return 0; }
r[2]=read(ram,0x0c07b348u,4);
goto P_0c07b232;
P_0c07b232: /* original 65e3, guest PC 0x0c07b232 */
if(!s->budget--) { s->failed_pc=0x0c07b232u; return 0; }
r[5]=r[14];
goto P_0c07b234;
P_0c07b234: /* original 420b, guest PC 0x0c07b234 */
if(!s->budget--) { s->failed_pc=0x0c07b234u; return 0; }
target=r[2];
r[16]=code_base|0x0c07b238u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b238u) { target=s->pc; goto dispatch; }
goto P_0c07b238;
P_0c07b236: /* original e401, guest PC 0x0c07b236 */
if(!s->budget--) { s->failed_pc=0x0c07b236u; return 0; }
r[4]=0x00000001u;
goto P_0c07b238;
P_0c07b238: /* original dc44, guest PC 0x0c07b238 */
if(!s->budget--) { s->failed_pc=0x0c07b238u; return 0; }
r[12]=read(ram,0x0c07b34cu,4);
goto P_0c07b23a;
P_0c07b23a: /* original 4c0b, guest PC 0x0c07b23a */
if(!s->budget--) { s->failed_pc=0x0c07b23au; return 0; }
target=r[12];
r[16]=code_base|0x0c07b23eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b23eu) { target=s->pc; goto dispatch; }
goto P_0c07b23e;
P_0c07b23c: /* original e400, guest PC 0x0c07b23c */
if(!s->budget--) { s->failed_pc=0x0c07b23cu; return 0; }
r[4]=0x00000000u;
goto P_0c07b23e;
P_0c07b23e: /* original da44, guest PC 0x0c07b23e */
if(!s->budget--) { s->failed_pc=0x0c07b23eu; return 0; }
r[10]=read(ram,0x0c07b350u,4);
goto P_0c07b240;
P_0c07b240: /* original 65e3, guest PC 0x0c07b240 */
if(!s->budget--) { s->failed_pc=0x0c07b240u; return 0; }
r[5]=r[14];
goto P_0c07b242;
P_0c07b242: /* original bad1, guest PC 0x0c07b242 */
if(!s->budget--) { s->failed_pc=0x0c07b242u; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b246u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b246u) { target=s->pc; goto dispatch; }
goto P_0c07b246;
P_0c07b244: /* original 64a3, guest PC 0x0c07b244 */
if(!s->budget--) { s->failed_pc=0x0c07b244u; return 0; }
r[4]=r[10];
goto P_0c07b246;
P_0c07b246: /* original 4c0b, guest PC 0x0c07b246 */
if(!s->budget--) { s->failed_pc=0x0c07b246u; return 0; }
target=r[12];
r[16]=code_base|0x0c07b24au;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b24au) { target=s->pc; goto dispatch; }
goto P_0c07b24a;
P_0c07b248: /* original e401, guest PC 0x0c07b248 */
if(!s->budget--) { s->failed_pc=0x0c07b248u; return 0; }
r[4]=0x00000001u;
goto P_0c07b24a;
P_0c07b24a: /* original 64a3, guest PC 0x0c07b24a */
if(!s->budget--) { s->failed_pc=0x0c07b24au; return 0; }
r[4]=r[10];
goto P_0c07b24c;
P_0c07b24c: /* original 65e3, guest PC 0x0c07b24c */
if(!s->budget--) { s->failed_pc=0x0c07b24cu; return 0; }
r[5]=r[14];
goto P_0c07b24e;
P_0c07b24e: /* original bacb, guest PC 0x0c07b24e */
if(!s->budget--) { s->failed_pc=0x0c07b24eu; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b252u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b252u) { target=s->pc; goto dispatch; }
goto P_0c07b252;
P_0c07b250: /* original 7410, guest PC 0x0c07b250 */
if(!s->budget--) { s->failed_pc=0x0c07b250u; return 0; }
r[4]+=0x00000010u;
goto P_0c07b252;
P_0c07b252: /* original 4c0b, guest PC 0x0c07b252 */
if(!s->budget--) { s->failed_pc=0x0c07b252u; return 0; }
target=r[12];
r[16]=code_base|0x0c07b256u;
r[4]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b256u) { target=s->pc; goto dispatch; }
goto P_0c07b256;
P_0c07b254: /* original e402, guest PC 0x0c07b254 */
if(!s->budget--) { s->failed_pc=0x0c07b254u; return 0; }
r[4]=0x00000002u;
goto P_0c07b256;
P_0c07b256: /* original 64a3, guest PC 0x0c07b256 */
if(!s->budget--) { s->failed_pc=0x0c07b256u; return 0; }
r[4]=r[10];
goto P_0c07b258;
P_0c07b258: /* original 65e3, guest PC 0x0c07b258 */
if(!s->budget--) { s->failed_pc=0x0c07b258u; return 0; }
r[5]=r[14];
goto P_0c07b25a;
P_0c07b25a: /* original bac5, guest PC 0x0c07b25a */
if(!s->budget--) { s->failed_pc=0x0c07b25au; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b25eu;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b25eu) { target=s->pc; goto dispatch; }
goto P_0c07b25e;
P_0c07b25c: /* original 7420, guest PC 0x0c07b25c */
if(!s->budget--) { s->failed_pc=0x0c07b25cu; return 0; }
r[4]+=0x00000020u;
goto P_0c07b25e;
P_0c07b25e: /* original 4c0b, guest PC 0x0c07b25e */
if(!s->budget--) { s->failed_pc=0x0c07b25eu; return 0; }
target=r[12];
r[16]=code_base|0x0c07b262u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b262u) { target=s->pc; goto dispatch; }
goto P_0c07b262;
P_0c07b260: /* original e403, guest PC 0x0c07b260 */
if(!s->budget--) { s->failed_pc=0x0c07b260u; return 0; }
r[4]=0x00000003u;
goto P_0c07b262;
P_0c07b262: /* original 64a3, guest PC 0x0c07b262 */
if(!s->budget--) { s->failed_pc=0x0c07b262u; return 0; }
r[4]=r[10];
goto P_0c07b264;
P_0c07b264: /* original 65e3, guest PC 0x0c07b264 */
if(!s->budget--) { s->failed_pc=0x0c07b264u; return 0; }
r[5]=r[14];
goto P_0c07b266;
P_0c07b266: /* original babf, guest PC 0x0c07b266 */
if(!s->budget--) { s->failed_pc=0x0c07b266u; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b26au;
r[4]+=0x00000030u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b26au) { target=s->pc; goto dispatch; }
goto P_0c07b26a;
P_0c07b268: /* original 7430, guest PC 0x0c07b268 */
if(!s->budget--) { s->failed_pc=0x0c07b268u; return 0; }
r[4]+=0x00000030u;
goto P_0c07b26a;
P_0c07b26a: /* original 4c0b, guest PC 0x0c07b26a */
if(!s->budget--) { s->failed_pc=0x0c07b26au; return 0; }
target=r[12];
r[16]=code_base|0x0c07b26eu;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b26eu) { target=s->pc; goto dispatch; }
goto P_0c07b26e;
P_0c07b26c: /* original e404, guest PC 0x0c07b26c */
if(!s->budget--) { s->failed_pc=0x0c07b26cu; return 0; }
r[4]=0x00000004u;
goto P_0c07b26e;
P_0c07b26e: /* original 64a3, guest PC 0x0c07b26e */
if(!s->budget--) { s->failed_pc=0x0c07b26eu; return 0; }
r[4]=r[10];
goto P_0c07b270;
P_0c07b270: /* original 65e3, guest PC 0x0c07b270 */
if(!s->budget--) { s->failed_pc=0x0c07b270u; return 0; }
r[5]=r[14];
goto P_0c07b272;
P_0c07b272: /* original bab9, guest PC 0x0c07b272 */
if(!s->budget--) { s->failed_pc=0x0c07b272u; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b276u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b276u) { target=s->pc; goto dispatch; }
goto P_0c07b276;
P_0c07b274: /* original 7440, guest PC 0x0c07b274 */
if(!s->budget--) { s->failed_pc=0x0c07b274u; return 0; }
r[4]+=0x00000040u;
goto P_0c07b276;
P_0c07b276: /* original 4c0b, guest PC 0x0c07b276 */
if(!s->budget--) { s->failed_pc=0x0c07b276u; return 0; }
target=r[12];
r[16]=code_base|0x0c07b27au;
r[4]=0x00000053u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b27au) { target=s->pc; goto dispatch; }
goto P_0c07b27a;
P_0c07b278: /* original e453, guest PC 0x0c07b278 */
if(!s->budget--) { s->failed_pc=0x0c07b278u; return 0; }
r[4]=0x00000053u;
goto P_0c07b27a;
P_0c07b27a: /* original 64a3, guest PC 0x0c07b27a */
if(!s->budget--) { s->failed_pc=0x0c07b27au; return 0; }
r[4]=r[10];
goto P_0c07b27c;
P_0c07b27c: /* original 65e3, guest PC 0x0c07b27c */
if(!s->budget--) { s->failed_pc=0x0c07b27cu; return 0; }
r[5]=r[14];
goto P_0c07b27e;
P_0c07b27e: /* original bab3, guest PC 0x0c07b27e */
if(!s->budget--) { s->failed_pc=0x0c07b27eu; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b282u;
r[4]+=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b282u) { target=s->pc; goto dispatch; }
goto P_0c07b282;
P_0c07b280: /* original 7450, guest PC 0x0c07b280 */
if(!s->budget--) { s->failed_pc=0x0c07b280u; return 0; }
r[4]+=0x00000050u;
goto P_0c07b282;
P_0c07b282: /* original e001, guest PC 0x0c07b282 */
if(!s->budget--) { s->failed_pc=0x0c07b282u; return 0; }
r[0]=0x00000001u;
goto P_0c07b284;
P_0c07b284: /* original 2db1, guest PC 0x0c07b284 */
if(!s->budget--) { s->failed_pc=0x0c07b284u; return 0; }
write(ram,r[13],r[11],2);
goto P_0c07b286;
P_0c07b286: /* original 81d1, guest PC 0x0c07b286 */
if(!s->budget--) { s->failed_pc=0x0c07b286u; return 0; }
write(ram,r[13]+2,r[0],2);
goto P_0c07b288;
P_0c07b288: /* original e002, guest PC 0x0c07b288 */
if(!s->budget--) { s->failed_pc=0x0c07b288u; return 0; }
r[0]=0x00000002u;
goto P_0c07b28a;
P_0c07b28a: /* original 81d2, guest PC 0x0c07b28a */
if(!s->budget--) { s->failed_pc=0x0c07b28au; return 0; }
write(ram,r[13]+4,r[0],2);
goto P_0c07b28c;
P_0c07b28c: /* original e003, guest PC 0x0c07b28c */
if(!s->budget--) { s->failed_pc=0x0c07b28cu; return 0; }
r[0]=0x00000003u;
goto P_0c07b28e;
P_0c07b28e: /* original 81d3, guest PC 0x0c07b28e */
if(!s->budget--) { s->failed_pc=0x0c07b28eu; return 0; }
write(ram,r[13]+6,r[0],2);
goto P_0c07b290;
P_0c07b290: /* original e004, guest PC 0x0c07b290 */
if(!s->budget--) { s->failed_pc=0x0c07b290u; return 0; }
r[0]=0x00000004u;
goto P_0c07b292;
P_0c07b292: /* original 81d4, guest PC 0x0c07b292 */
if(!s->budget--) { s->failed_pc=0x0c07b292u; return 0; }
write(ram,r[13]+8,r[0],2);
goto P_0c07b294;
P_0c07b294: /* original e353, guest PC 0x0c07b294 */
if(!s->budget--) { s->failed_pc=0x0c07b294u; return 0; }
r[3]=0x00000053u;
goto P_0c07b296;
P_0c07b296: /* original 904e, guest PC 0x0c07b296 */
if(!s->budget--) { s->failed_pc=0x0c07b296u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b336u,2);
goto P_0c07b298;
P_0c07b298: /* original 0d35, guest PC 0x0c07b298 */
if(!s->budget--) { s->failed_pc=0x0c07b298u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07b29a;
P_0c07b29a: /* original d32e, guest PC 0x0c07b29a */
if(!s->budget--) { s->failed_pc=0x0c07b29au; return 0; }
r[3]=read(ram,0x0c07b354u,4);
goto P_0c07b29c;
P_0c07b29c: /* original 64f2, guest PC 0x0c07b29c */
if(!s->budget--) { s->failed_pc=0x0c07b29cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07b29e;
P_0c07b29e: /* original 430b, guest PC 0x0c07b29e */
if(!s->budget--) { s->failed_pc=0x0c07b29eu; return 0; }
target=r[3];
r[16]=code_base|0x0c07b2a2u;
r[4]+=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b2a2u) { target=s->pc; goto dispatch; }
goto P_0c07b2a2;
P_0c07b2a0: /* original 7412, guest PC 0x0c07b2a0 */
if(!s->budget--) { s->failed_pc=0x0c07b2a0u; return 0; }
r[4]+=0x00000012u;
goto P_0c07b2a2;
P_0c07b2a2: /* original 600c, guest PC 0x0c07b2a2 */
if(!s->budget--) { s->failed_pc=0x0c07b2a2u; return 0; }
r[0]=r[0]&255u;
goto P_0c07b2a4;
P_0c07b2a4: /* original 2008, guest PC 0x0c07b2a4 */
if(!s->budget--) { s->failed_pc=0x0c07b2a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c07b2a6;
P_0c07b2a6: /* original 8d02, guest PC 0x0c07b2a6 */
if(!s->budget--) { s->failed_pc=0x0c07b2a6u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c07b2ae; }
goto P_0c07b2aa;
P_0c07b2a8: /* original 7f04, guest PC 0x0c07b2a8 */
if(!s->budget--) { s->failed_pc=0x0c07b2a8u; return 0; }
r[15]+=0x00000004u;
goto P_0c07b2aa;
P_0c07b2aa: /* original a001, guest PC 0x0c07b2aa */
if(!s->budget--) { s->failed_pc=0x0c07b2aau; return 0; }
r[4]=0x00000008u;
goto P_0c07b2b0;
P_0c07b2ac: /* original e408, guest PC 0x0c07b2ac */
if(!s->budget--) { s->failed_pc=0x0c07b2acu; return 0; }
r[4]=0x00000008u;
goto P_0c07b2ae;
P_0c07b2ae: /* original e409, guest PC 0x0c07b2ae */
if(!s->budget--) { s->failed_pc=0x0c07b2aeu; return 0; }
r[4]=0x00000009u;
goto P_0c07b2b0;
P_0c07b2b0: /* original 4f26, guest PC 0x0c07b2b0 */
if(!s->budget--) { s->failed_pc=0x0c07b2b0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b2b2;
P_0c07b2b2: /* original 6af6, guest PC 0x0c07b2b2 */
if(!s->budget--) { s->failed_pc=0x0c07b2b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07b2b4;
P_0c07b2b4: /* original 6bf6, guest PC 0x0c07b2b4 */
if(!s->budget--) { s->failed_pc=0x0c07b2b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07b2b6;
P_0c07b2b6: /* original 6cf6, guest PC 0x0c07b2b6 */
if(!s->budget--) { s->failed_pc=0x0c07b2b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07b2b8;
P_0c07b2b8: /* original 6df6, guest PC 0x0c07b2b8 */
if(!s->budget--) { s->failed_pc=0x0c07b2b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b2ba;
P_0c07b2ba: /* original abf7, guest PC 0x0c07b2ba */
if(!s->budget--) { s->failed_pc=0x0c07b2bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07aaacu,s,ram);
P_0c07b2bc: /* original 6ef6, guest PC 0x0c07b2bc */
if(!s->budget--) { s->failed_pc=0x0c07b2bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07b2beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b2beu; return 0; } return 1;
P_0c07b5b0: /* original 920d, guest PC 0x0c07b5b0 */
if(!s->budget--) { s->failed_pc=0x0c07b5b0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5ceu,2);
goto P_0c07b5b2;
P_0c07b5b2: /* original 634d, guest PC 0x0c07b5b2 */
if(!s->budget--) { s->failed_pc=0x0c07b5b2u; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b5b4;
P_0c07b5b4: /* original 2328, guest PC 0x0c07b5b4 */
if(!s->budget--) { s->failed_pc=0x0c07b5b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c07b5b6;
P_0c07b5b6: /* original 8908, guest PC 0x0c07b5b6 */
if(!s->budget--) { s->failed_pc=0x0c07b5b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b5ca; }
goto P_0c07b5b8;
P_0c07b5b8: /* original 900a, guest PC 0x0c07b5b8 */
if(!s->budget--) { s->failed_pc=0x0c07b5b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5d0u,2);
goto P_0c07b5ba;
P_0c07b5ba: /* original 2409, guest PC 0x0c07b5ba */
if(!s->budget--) { s->failed_pc=0x0c07b5bau; return 0; }
r[4]&=r[0];
goto P_0c07b5bc;
P_0c07b5bc: /* original d005, guest PC 0x0c07b5bc */
if(!s->budget--) { s->failed_pc=0x0c07b5bcu; return 0; }
r[0]=read(ram,0x0c07b5d4u,4);
goto P_0c07b5be;
P_0c07b5be: /* original 634d, guest PC 0x0c07b5be */
if(!s->budget--) { s->failed_pc=0x0c07b5beu; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b5c0;
P_0c07b5c0: /* original 6133, guest PC 0x0c07b5c0 */
if(!s->budget--) { s->failed_pc=0x0c07b5c0u; return 0; }
r[1]=r[3];
goto P_0c07b5c2;
P_0c07b5c2: /* original 4108, guest PC 0x0c07b5c2 */
if(!s->budget--) { s->failed_pc=0x0c07b5c2u; return 0; }
r[1]<<=2;
goto P_0c07b5c4;
P_0c07b5c4: /* original 4300, guest PC 0x0c07b5c4 */
if(!s->budget--) { s->failed_pc=0x0c07b5c4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07b5c6;
P_0c07b5c6: /* original 331c, guest PC 0x0c07b5c6 */
if(!s->budget--) { s->failed_pc=0x0c07b5c6u; return 0; }
r[3]+=r[1];
goto P_0c07b5c8;
P_0c07b5c8: /* original 043d, guest PC 0x0c07b5c8 */
if(!s->budget--) { s->failed_pc=0x0c07b5c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07b5ca;
P_0c07b5ca: /* original 000b, guest PC 0x0c07b5ca */
if(!s->budget--) { s->failed_pc=0x0c07b5cau; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c07b5cc: /* original 6043, guest PC 0x0c07b5cc */
if(!s->budget--) { s->failed_pc=0x0c07b5ccu; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c07b5ceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b5ceu; return 0; } return 1;
P_0c07b5f0: /* original 2fe6, guest PC 0x0c07b5f0 */
if(!s->budget--) { s->failed_pc=0x0c07b5f0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b5f2;
P_0c07b5f2: /* original 2fd6, guest PC 0x0c07b5f2 */
if(!s->budget--) { s->failed_pc=0x0c07b5f2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b5f4;
P_0c07b5f4: /* original 6d43, guest PC 0x0c07b5f4 */
if(!s->budget--) { s->failed_pc=0x0c07b5f4u; return 0; }
r[13]=r[4];
goto P_0c07b5f6;
P_0c07b5f6: /* original 2fc6, guest PC 0x0c07b5f6 */
if(!s->budget--) { s->failed_pc=0x0c07b5f6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b5f8;
P_0c07b5f8: /* original 4f22, guest PC 0x0c07b5f8 */
if(!s->budget--) { s->failed_pc=0x0c07b5f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b5fa;
P_0c07b5fa: /* original d22a, guest PC 0x0c07b5fa */
if(!s->budget--) { s->failed_pc=0x0c07b5fau; return 0; }
r[2]=read(ram,0x0c07b6a4u,4);
goto P_0c07b5fc;
P_0c07b5fc: /* original d32a, guest PC 0x0c07b5fc */
if(!s->budget--) { s->failed_pc=0x0c07b5fcu; return 0; }
r[3]=read(ram,0x0c07b6a8u,4);
goto P_0c07b5fe;
P_0c07b5fe: /* original 7fe0, guest PC 0x0c07b5fe */
if(!s->budget--) { s->failed_pc=0x0c07b5feu; return 0; }
r[15]+=0xffffffe0u;
goto P_0c07b600;
P_0c07b600: /* original 61f3, guest PC 0x0c07b600 */
if(!s->budget--) { s->failed_pc=0x0c07b600u; return 0; }
r[1]=r[15];
goto P_0c07b602;
P_0c07b602: /* original 430b, guest PC 0x0c07b602 */
if(!s->budget--) { s->failed_pc=0x0c07b602u; return 0; }
target=r[3];
r[16]=code_base|0x0c07b606u;
r[0]=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b606u) { target=s->pc; goto dispatch; }
goto P_0c07b606;
P_0c07b604: /* original e020, guest PC 0x0c07b604 */
if(!s->budget--) { s->failed_pc=0x0c07b604u; return 0; }
r[0]=0x00000020u;
goto P_0c07b606;
P_0c07b606: /* original 9149, guest PC 0x0c07b606 */
if(!s->budget--) { s->failed_pc=0x0c07b606u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69cu,2);
goto P_0c07b608;
P_0c07b608: /* original 6edd, guest PC 0x0c07b608 */
if(!s->budget--) { s->failed_pc=0x0c07b608u; return 0; }
r[14]=r[13]&65535u;
goto P_0c07b60a;
P_0c07b60a: /* original 21e8, guest PC 0x0c07b60a */
if(!s->budget--) { s->failed_pc=0x0c07b60au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[14])==0)!=0);
goto P_0c07b60c;
P_0c07b60c: /* original 8b29, guest PC 0x0c07b60c */
if(!s->budget--) { s->failed_pc=0x0c07b60cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b662; }
goto P_0c07b60e;
P_0c07b60e: /* original d227, guest PC 0x0c07b60e */
if(!s->budget--) { s->failed_pc=0x0c07b60eu; return 0; }
r[2]=read(ram,0x0c07b6acu,4);
goto P_0c07b610;
P_0c07b610: /* original 22e8, guest PC 0x0c07b610 */
if(!s->budget--) { s->failed_pc=0x0c07b610u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c07b612;
P_0c07b612: /* original 8b26, guest PC 0x0c07b612 */
if(!s->budget--) { s->failed_pc=0x0c07b612u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b662; }
goto P_0c07b614;
P_0c07b614: /* original 60e3, guest PC 0x0c07b614 */
if(!s->budget--) { s->failed_pc=0x0c07b614u; return 0; }
r[0]=r[14];
goto P_0c07b616;
P_0c07b616: /* original dc26, guest PC 0x0c07b616 */
if(!s->budget--) { s->failed_pc=0x0c07b616u; return 0; }
r[12]=read(ram,0x0c07b6b0u,4);
goto P_0c07b618;
P_0c07b618: /* original 8807, guest PC 0x0c07b618 */
if(!s->budget--) { s->failed_pc=0x0c07b618u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c07b61a;
P_0c07b61a: /* original 8b02, guest PC 0x0c07b61a */
if(!s->budget--) { s->failed_pc=0x0c07b61au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b622; }
goto P_0c07b61c;
P_0c07b61c: /* original 953f, guest PC 0x0c07b61c */
if(!s->budget--) { s->failed_pc=0x0c07b61cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69eu,2);
goto P_0c07b61e;
P_0c07b61e: /* original 4c0b, guest PC 0x0c07b61e */
if(!s->budget--) { s->failed_pc=0x0c07b61eu; return 0; }
target=r[12];
r[16]=code_base|0x0c07b622u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b622u) { target=s->pc; goto dispatch; }
goto P_0c07b622;
P_0c07b620: /* original e401, guest PC 0x0c07b620 */
if(!s->budget--) { s->failed_pc=0x0c07b620u; return 0; }
r[4]=0x00000001u;
goto P_0c07b622;
P_0c07b622: /* original 60e3, guest PC 0x0c07b622 */
if(!s->budget--) { s->failed_pc=0x0c07b622u; return 0; }
r[0]=r[14];
goto P_0c07b624;
P_0c07b624: /* original 8805, guest PC 0x0c07b624 */
if(!s->budget--) { s->failed_pc=0x0c07b624u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c07b626;
P_0c07b626: /* original 8b02, guest PC 0x0c07b626 */
if(!s->budget--) { s->failed_pc=0x0c07b626u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b62e; }
goto P_0c07b628;
P_0c07b628: /* original 953a, guest PC 0x0c07b628 */
if(!s->budget--) { s->failed_pc=0x0c07b628u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b6a0u,2);
goto P_0c07b62a;
P_0c07b62a: /* original 4c0b, guest PC 0x0c07b62a */
if(!s->budget--) { s->failed_pc=0x0c07b62au; return 0; }
target=r[12];
r[16]=code_base|0x0c07b62eu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b62eu) { target=s->pc; goto dispatch; }
goto P_0c07b62e;
P_0c07b62c: /* original e401, guest PC 0x0c07b62c */
if(!s->budget--) { s->failed_pc=0x0c07b62cu; return 0; }
r[4]=0x00000001u;
goto P_0c07b62e;
P_0c07b62e: /* original d021, guest PC 0x0c07b62e */
if(!s->budget--) { s->failed_pc=0x0c07b62eu; return 0; }
r[0]=read(ram,0x0c07b6b4u,4);
goto P_0c07b630;
P_0c07b630: /* original 64dd, guest PC 0x0c07b630 */
if(!s->budget--) { s->failed_pc=0x0c07b630u; return 0; }
r[4]=r[13]&65535u;
goto P_0c07b632;
P_0c07b632: /* original 4400, guest PC 0x0c07b632 */
if(!s->budget--) { s->failed_pc=0x0c07b632u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07b634;
P_0c07b634: /* original 044d, guest PC 0x0c07b634 */
if(!s->budget--) { s->failed_pc=0x0c07b634u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07b636;
P_0c07b636: /* original 644d, guest PC 0x0c07b636 */
if(!s->budget--) { s->failed_pc=0x0c07b636u; return 0; }
r[4]=r[4]&65535u;
goto P_0c07b638;
P_0c07b638: /* original 2448, guest PC 0x0c07b638 */
if(!s->budget--) { s->failed_pc=0x0c07b638u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07b63a;
P_0c07b63a: /* original 8912, guest PC 0x0c07b63a */
if(!s->budget--) { s->failed_pc=0x0c07b63au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b662; }
goto P_0c07b63c;
P_0c07b63c: /* original d21e, guest PC 0x0c07b63c */
if(!s->budget--) { s->failed_pc=0x0c07b63cu; return 0; }
r[2]=read(ram,0x0c07b6b8u,4);
goto P_0c07b63e;
P_0c07b63e: /* original 3420, guest PC 0x0c07b63e */
if(!s->budget--) { s->failed_pc=0x0c07b63eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c07b640;
P_0c07b640: /* original 890f, guest PC 0x0c07b640 */
if(!s->budget--) { s->failed_pc=0x0c07b640u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b662; }
goto P_0c07b642;
P_0c07b642: /* original d21e, guest PC 0x0c07b642 */
if(!s->budget--) { s->failed_pc=0x0c07b642u; return 0; }
r[2]=read(ram,0x0c07b6bcu,4);
goto P_0c07b644;
P_0c07b644: /* original 420b, guest PC 0x0c07b644 */
if(!s->budget--) { s->failed_pc=0x0c07b644u; return 0; }
target=r[2];
r[16]=code_base|0x0c07b648u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b648u) { target=s->pc; goto dispatch; }
goto P_0c07b648;
P_0c07b646: /* original 0009, guest PC 0x0c07b646 */
if(!s->budget--) { s->failed_pc=0x0c07b646u; return 0; }
goto P_0c07b648;
P_0c07b648: /* original d31d, guest PC 0x0c07b648 */
if(!s->budget--) { s->failed_pc=0x0c07b648u; return 0; }
r[3]=read(ram,0x0c07b6c0u,4);
goto P_0c07b64a;
P_0c07b64a: /* original 430b, guest PC 0x0c07b64a */
if(!s->budget--) { s->failed_pc=0x0c07b64au; return 0; }
target=r[3];
r[16]=code_base|0x0c07b64eu;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b64eu) { target=s->pc; goto dispatch; }
goto P_0c07b64e;
P_0c07b64c: /* original 64f3, guest PC 0x0c07b64c */
if(!s->budget--) { s->failed_pc=0x0c07b64cu; return 0; }
r[4]=r[15];
goto P_0c07b64e;
P_0c07b64e: /* original 2008, guest PC 0x0c07b64e */
if(!s->budget--) { s->failed_pc=0x0c07b64eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c07b650;
P_0c07b650: /* original 8902, guest PC 0x0c07b650 */
if(!s->budget--) { s->failed_pc=0x0c07b650u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b658; }
goto P_0c07b652;
P_0c07b652: /* original 9524, guest PC 0x0c07b652 */
if(!s->budget--) { s->failed_pc=0x0c07b652u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69eu,2);
goto P_0c07b654;
P_0c07b654: /* original 4c0b, guest PC 0x0c07b654 */
if(!s->budget--) { s->failed_pc=0x0c07b654u; return 0; }
target=r[12];
r[16]=code_base|0x0c07b658u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b658u) { target=s->pc; goto dispatch; }
goto P_0c07b658;
P_0c07b656: /* original e401, guest PC 0x0c07b656 */
if(!s->budget--) { s->failed_pc=0x0c07b656u; return 0; }
r[4]=0x00000001u;
goto P_0c07b658;
P_0c07b658: /* original d016, guest PC 0x0c07b658 */
if(!s->budget--) { s->failed_pc=0x0c07b658u; return 0; }
r[0]=read(ram,0x0c07b6b4u,4);
goto P_0c07b65a;
P_0c07b65a: /* original 6ddd, guest PC 0x0c07b65a */
if(!s->budget--) { s->failed_pc=0x0c07b65au; return 0; }
r[13]=r[13]&65535u;
goto P_0c07b65c;
P_0c07b65c: /* original e300, guest PC 0x0c07b65c */
if(!s->budget--) { s->failed_pc=0x0c07b65cu; return 0; }
r[3]=0x00000000u;
goto P_0c07b65e;
P_0c07b65e: /* original 4d00, guest PC 0x0c07b65e */
if(!s->budget--) { s->failed_pc=0x0c07b65eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07b660;
P_0c07b660: /* original 0d35, guest PC 0x0c07b660 */
if(!s->budget--) { s->failed_pc=0x0c07b660u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07b662;
P_0c07b662: /* original 7f20, guest PC 0x0c07b662 */
if(!s->budget--) { s->failed_pc=0x0c07b662u; return 0; }
r[15]+=0x00000020u;
goto P_0c07b664;
P_0c07b664: /* original 4f26, guest PC 0x0c07b664 */
if(!s->budget--) { s->failed_pc=0x0c07b664u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b666;
P_0c07b666: /* original 6cf6, guest PC 0x0c07b666 */
if(!s->budget--) { s->failed_pc=0x0c07b666u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07b668;
P_0c07b668: /* original 6df6, guest PC 0x0c07b668 */
if(!s->budget--) { s->failed_pc=0x0c07b668u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b66a;
P_0c07b66a: /* original 000b, guest PC 0x0c07b66a */
if(!s->budget--) { s->failed_pc=0x0c07b66au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b66c: /* original 6ef6, guest PC 0x0c07b66c */
if(!s->budget--) { s->failed_pc=0x0c07b66cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07b66eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b66eu; return 0; } return 1;
P_0c08b430: /* original 2fe6, guest PC 0x0c08b430 */
if(!s->budget--) { s->failed_pc=0x0c08b430u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b432;
P_0c08b432: /* original 6e73, guest PC 0x0c08b432 */
if(!s->budget--) { s->failed_pc=0x0c08b432u; return 0; }
r[14]=r[7];
goto P_0c08b434;
P_0c08b434: /* original 2fd6, guest PC 0x0c08b434 */
if(!s->budget--) { s->failed_pc=0x0c08b434u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b436;
P_0c08b436: /* original 2fc6, guest PC 0x0c08b436 */
if(!s->budget--) { s->failed_pc=0x0c08b436u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b438;
P_0c08b438: /* original 6c53, guest PC 0x0c08b438 */
if(!s->budget--) { s->failed_pc=0x0c08b438u; return 0; }
r[12]=r[5];
goto P_0c08b43a;
P_0c08b43a: /* original 2fb6, guest PC 0x0c08b43a */
if(!s->budget--) { s->failed_pc=0x0c08b43au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b43c;
P_0c08b43c: /* original 2fa6, guest PC 0x0c08b43c */
if(!s->budget--) { s->failed_pc=0x0c08b43cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b43e;
P_0c08b43e: /* original 2f96, guest PC 0x0c08b43e */
if(!s->budget--) { s->failed_pc=0x0c08b43eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b440;
P_0c08b440: /* original 6943, guest PC 0x0c08b440 */
if(!s->budget--) { s->failed_pc=0x0c08b440u; return 0; }
r[9]=r[4];
goto P_0c08b442;
P_0c08b442: /* original 2f86, guest PC 0x0c08b442 */
if(!s->budget--) { s->failed_pc=0x0c08b442u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08b444;
P_0c08b444: /* original 7964, guest PC 0x0c08b444 */
if(!s->budget--) { s->failed_pc=0x0c08b444u; return 0; }
r[9]+=0x00000064u;
goto P_0c08b446;
P_0c08b446: /* original fffb, guest PC 0x0c08b446 */
if(!s->budget--) { s->failed_pc=0x0c08b446u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08b448;
P_0c08b448: /* original 4f22, guest PC 0x0c08b448 */
if(!s->budget--) { s->failed_pc=0x0c08b448u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b44a;
P_0c08b44a: /* original 4f12, guest PC 0x0c08b44a */
if(!s->budget--) { s->failed_pc=0x0c08b44au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c08b44c;
P_0c08b44c: /* original 7ff8, guest PC 0x0c08b44c */
if(!s->budget--) { s->failed_pc=0x0c08b44cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c08b44e;
P_0c08b44e: /* original 1f61, guest PC 0x0c08b44e */
if(!s->budget--) { s->failed_pc=0x0c08b44eu; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c08b450;
P_0c08b450: /* original 2f72, guest PC 0x0c08b450 */
if(!s->budget--) { s->failed_pc=0x0c08b450u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c08b452;
P_0c08b452: /* original d22d, guest PC 0x0c08b452 */
if(!s->budget--) { s->failed_pc=0x0c08b452u; return 0; }
r[2]=read(ram,0x0c08b508u,4);
goto P_0c08b454;
P_0c08b454: /* original 9353, guest PC 0x0c08b454 */
if(!s->budget--) { s->failed_pc=0x0c08b454u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b4feu,2);
goto P_0c08b456;
P_0c08b456: /* original 6822, guest PC 0x0c08b456 */
if(!s->budget--) { s->failed_pc=0x0c08b456u; return 0; }
tmp=read(ram,r[2],4);
r[8]=tmp;
goto P_0c08b458;
P_0c08b458: /* original 9d50, guest PC 0x0c08b458 */
if(!s->budget--) { s->failed_pc=0x0c08b458u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b4fcu,2);
goto P_0c08b45a;
P_0c08b45a: /* original 2838, guest PC 0x0c08b45a */
if(!s->budget--) { s->failed_pc=0x0c08b45au; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c08b45c;
P_0c08b45c: /* original 3d4c, guest PC 0x0c08b45c */
if(!s->budget--) { s->failed_pc=0x0c08b45cu; return 0; }
r[13]+=r[4];
goto P_0c08b45e;
P_0c08b45e: /* original 8d05, guest PC 0x0c08b45e */
if(!s->budget--) { s->failed_pc=0x0c08b45eu; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]=tmp;
if(cond) { goto P_0c08b46c; }
goto P_0c08b462;
P_0c08b460: /* original 6ee0, guest PC 0x0c08b460 */
if(!s->budget--) { s->failed_pc=0x0c08b460u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]=tmp;
goto P_0c08b462;
P_0c08b462: /* original 60c3, guest PC 0x0c08b462 */
if(!s->budget--) { s->failed_pc=0x0c08b462u; return 0; }
r[0]=r[12];
goto P_0c08b464;
P_0c08b464: /* original 8810, guest PC 0x0c08b464 */
if(!s->budget--) { s->failed_pc=0x0c08b464u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c08b466;
P_0c08b466: /* original 8b01, guest PC 0x0c08b466 */
if(!s->budget--) { s->failed_pc=0x0c08b466u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b46c; }
goto P_0c08b468;
P_0c08b468: /* original a001, guest PC 0x0c08b468 */
if(!s->budget--) { s->failed_pc=0x0c08b468u; return 0; }
r[8]=0x00000001u;
goto P_0c08b46e;
P_0c08b46a: /* original e801, guest PC 0x0c08b46a */
if(!s->budget--) { s->failed_pc=0x0c08b46au; return 0; }
r[8]=0x00000001u;
goto P_0c08b46c;
P_0c08b46c: /* original e800, guest PC 0x0c08b46c */
if(!s->budget--) { s->failed_pc=0x0c08b46cu; return 0; }
r[8]=0x00000000u;
goto P_0c08b46e;
P_0c08b46e: /* original da27, guest PC 0x0c08b46e */
if(!s->budget--) { s->failed_pc=0x0c08b46eu; return 0; }
r[10]=read(ram,0x0c08b50cu,4);
goto P_0c08b470;
P_0c08b470: /* original c727, guest PC 0x0c08b470 */
if(!s->budget--) { s->failed_pc=0x0c08b470u; return 0; }
r[0]=code_base|0x0008b510u;
goto P_0c08b472;
P_0c08b472: /* original a024, guest PC 0x0c08b472 */
if(!s->budget--) { s->failed_pc=0x0c08b472u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08b4be;
P_0c08b474: /* original ff08, guest PC 0x0c08b474 */
if(!s->budget--) { s->failed_pc=0x0c08b474u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08b476;
P_0c08b476: /* original 2888, guest PC 0x0c08b476 */
if(!s->budget--) { s->failed_pc=0x0c08b476u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c08b478;
P_0c08b478: /* original 8905, guest PC 0x0c08b478 */
if(!s->budget--) { s->failed_pc=0x0c08b478u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b486; }
goto P_0c08b47a;
P_0c08b47a: /* original d326, guest PC 0x0c08b47a */
if(!s->budget--) { s->failed_pc=0x0c08b47au; return 0; }
r[3]=read(ram,0x0c08b514u,4);
goto P_0c08b47c;
P_0c08b47c: /* original 430b, guest PC 0x0c08b47c */
if(!s->budget--) { s->failed_pc=0x0c08b47cu; return 0; }
target=r[3];
r[16]=code_base|0x0c08b480u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b480u) { target=s->pc; goto dispatch; }
goto P_0c08b480;
P_0c08b47e: /* original 0009, guest PC 0x0c08b47e */
if(!s->budget--) { s->failed_pc=0x0c08b47eu; return 0; }
goto P_0c08b480;
P_0c08b480: /* original f40c, guest PC 0x0c08b480 */
if(!s->budget--) { s->failed_pc=0x0c08b480u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c08b482;
P_0c08b482: /* original f4f5, guest PC 0x0c08b482 */
if(!s->budget--) { s->failed_pc=0x0c08b482u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[15]))!=0);
goto P_0c08b484;
P_0c08b484: /* original 891e, guest PC 0x0c08b484 */
if(!s->budget--) { s->failed_pc=0x0c08b484u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b4c4; }
goto P_0c08b486;
P_0c08b486: /* original 60ee, guest PC 0x0c08b486 */
if(!s->budget--) { s->failed_pc=0x0c08b486u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c08b488;
P_0c08b488: /* original 7eff, guest PC 0x0c08b488 */
if(!s->budget--) { s->failed_pc=0x0c08b488u; return 0; }
r[14]+=0xffffffffu;
goto P_0c08b48a;
P_0c08b48a: /* original 6eee, guest PC 0x0c08b48a */
if(!s->budget--) { s->failed_pc=0x0c08b48au; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c08b48c;
P_0c08b48c: /* original e31c, guest PC 0x0c08b48c */
if(!s->budget--) { s->failed_pc=0x0c08b48cu; return 0; }
r[3]=0x0000001cu;
goto P_0c08b48e;
P_0c08b48e: /* original 2e3f, guest PC 0x0c08b48e */
if(!s->budget--) { s->failed_pc=0x0c08b48eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c08b490;
P_0c08b490: /* original 4008, guest PC 0x0c08b490 */
if(!s->budget--) { s->failed_pc=0x0c08b490u; return 0; }
r[0]<<=2;
goto P_0c08b492;
P_0c08b492: /* original 09d6, guest PC 0x0c08b492 */
if(!s->budget--) { s->failed_pc=0x0c08b492u; return 0; }
write(ram,r[9]+r[0],r[13],4);
goto P_0c08b494;
P_0c08b494: /* original 52f1, guest PC 0x0c08b494 */
if(!s->budget--) { s->failed_pc=0x0c08b494u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c08b496;
P_0c08b496: /* original 0e1a, guest PC 0x0c08b496 */
if(!s->budget--) { s->failed_pc=0x0c08b496u; return 0; }
r[14]=r[19];
goto P_0c08b498;
P_0c08b498: /* original 6eef, guest PC 0x0c08b498 */
if(!s->budget--) { s->failed_pc=0x0c08b498u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c08b49a;
P_0c08b49a: /* original 3eac, guest PC 0x0c08b49a */
if(!s->budget--) { s->failed_pc=0x0c08b49au; return 0; }
r[14]+=r[10];
goto P_0c08b49c;
P_0c08b49c: /* original 85ec, guest PC 0x0c08b49c */
if(!s->budget--) { s->failed_pc=0x0c08b49cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+24,2);
goto P_0c08b49e;
P_0c08b49e: /* original 6403, guest PC 0x0c08b49e */
if(!s->budget--) { s->failed_pc=0x0c08b49eu; return 0; }
r[4]=r[0];
goto P_0c08b4a0;
P_0c08b4a0: /* original 2428, guest PC 0x0c08b4a0 */
if(!s->budget--) { s->failed_pc=0x0c08b4a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c08b4a2;
P_0c08b4a2: /* original 8b02, guest PC 0x0c08b4a2 */
if(!s->budget--) { s->failed_pc=0x0c08b4a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b4aa; }
goto P_0c08b4a4;
P_0c08b4a4: /* original 60c3, guest PC 0x0c08b4a4 */
if(!s->budget--) { s->failed_pc=0x0c08b4a4u; return 0; }
r[0]=r[12];
goto P_0c08b4a6;
P_0c08b4a6: /* original 8810, guest PC 0x0c08b4a6 */
if(!s->budget--) { s->failed_pc=0x0c08b4a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c08b4a8;
P_0c08b4a8: /* original 8903, guest PC 0x0c08b4a8 */
if(!s->budget--) { s->failed_pc=0x0c08b4a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b4b2; }
goto P_0c08b4aa;
P_0c08b4aa: /* original 60c3, guest PC 0x0c08b4aa */
if(!s->budget--) { s->failed_pc=0x0c08b4aau; return 0; }
r[0]=r[12];
goto P_0c08b4ac;
P_0c08b4ac: /* original 0bee, guest PC 0x0c08b4ac */
if(!s->budget--) { s->failed_pc=0x0c08b4acu; return 0; }
r[11]=read(ram,r[14]+r[0],4);
goto P_0c08b4ae;
P_0c08b4ae: /* original 4b0b, guest PC 0x0c08b4ae */
if(!s->budget--) { s->failed_pc=0x0c08b4aeu; return 0; }
target=r[11];
r[16]=code_base|0x0c08b4b2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08b4b2u) { target=s->pc; goto dispatch; }
goto P_0c08b4b2;
P_0c08b4b0: /* original 64d3, guest PC 0x0c08b4b0 */
if(!s->budget--) { s->failed_pc=0x0c08b4b0u; return 0; }
r[4]=r[13];
goto P_0c08b4b2;
P_0c08b4b2: /* original 52e5, guest PC 0x0c08b4b2 */
if(!s->budget--) { s->failed_pc=0x0c08b4b2u; return 0; }
r[2]=read(ram,r[14]+20,4);
goto P_0c08b4b4;
P_0c08b4b4: /* original 6ef2, guest PC 0x0c08b4b4 */
if(!s->budget--) { s->failed_pc=0x0c08b4b4u; return 0; }
tmp=read(ram,r[15],4);
r[14]=tmp;
goto P_0c08b4b6;
P_0c08b4b6: /* original 3d2c, guest PC 0x0c08b4b6 */
if(!s->budget--) { s->failed_pc=0x0c08b4b6u; return 0; }
r[13]+=r[2];
goto P_0c08b4b8;
P_0c08b4b8: /* original 7e01, guest PC 0x0c08b4b8 */
if(!s->budget--) { s->failed_pc=0x0c08b4b8u; return 0; }
r[14]+=0x00000001u;
goto P_0c08b4ba;
P_0c08b4ba: /* original 2fe2, guest PC 0x0c08b4ba */
if(!s->budget--) { s->failed_pc=0x0c08b4bau; return 0; }
write(ram,r[15],r[14],4);
goto P_0c08b4bc;
P_0c08b4bc: /* original 6ee0, guest PC 0x0c08b4bc */
if(!s->budget--) { s->failed_pc=0x0c08b4bcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]=tmp;
goto P_0c08b4be;
P_0c08b4be: /* original 63ee, guest PC 0x0c08b4be */
if(!s->budget--) { s->failed_pc=0x0c08b4beu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c08b4c0;
P_0c08b4c0: /* original 2338, guest PC 0x0c08b4c0 */
if(!s->budget--) { s->failed_pc=0x0c08b4c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c08b4c2;
P_0c08b4c2: /* original 8bd8, guest PC 0x0c08b4c2 */
if(!s->budget--) { s->failed_pc=0x0c08b4c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b476; }
goto P_0c08b4c4;
P_0c08b4c4: /* original 7f08, guest PC 0x0c08b4c4 */
if(!s->budget--) { s->failed_pc=0x0c08b4c4u; return 0; }
r[15]+=0x00000008u;
goto P_0c08b4c6;
P_0c08b4c6: /* original 60d3, guest PC 0x0c08b4c6 */
if(!s->budget--) { s->failed_pc=0x0c08b4c6u; return 0; }
r[0]=r[13];
goto P_0c08b4c8;
P_0c08b4c8: /* original 4f16, guest PC 0x0c08b4c8 */
if(!s->budget--) { s->failed_pc=0x0c08b4c8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b4ca;
P_0c08b4ca: /* original 4f26, guest PC 0x0c08b4ca */
if(!s->budget--) { s->failed_pc=0x0c08b4cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b4cc;
P_0c08b4cc: /* original fff9, guest PC 0x0c08b4cc */
if(!s->budget--) { s->failed_pc=0x0c08b4ccu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b4ce;
P_0c08b4ce: /* original 68f6, guest PC 0x0c08b4ce */
if(!s->budget--) { s->failed_pc=0x0c08b4ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08b4d0;
P_0c08b4d0: /* original 69f6, guest PC 0x0c08b4d0 */
if(!s->budget--) { s->failed_pc=0x0c08b4d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08b4d2;
P_0c08b4d2: /* original 6af6, guest PC 0x0c08b4d2 */
if(!s->budget--) { s->failed_pc=0x0c08b4d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08b4d4;
P_0c08b4d4: /* original 6bf6, guest PC 0x0c08b4d4 */
if(!s->budget--) { s->failed_pc=0x0c08b4d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08b4d6;
P_0c08b4d6: /* original 6cf6, guest PC 0x0c08b4d6 */
if(!s->budget--) { s->failed_pc=0x0c08b4d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08b4d8;
P_0c08b4d8: /* original 6df6, guest PC 0x0c08b4d8 */
if(!s->budget--) { s->failed_pc=0x0c08b4d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08b4da;
P_0c08b4da: /* original 000b, guest PC 0x0c08b4da */
if(!s->budget--) { s->failed_pc=0x0c08b4dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b4dc: /* original 6ef6, guest PC 0x0c08b4dc */
if(!s->budget--) { s->failed_pc=0x0c08b4dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08b4deu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
