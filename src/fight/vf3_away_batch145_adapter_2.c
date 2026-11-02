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
int vf3_away_batch145_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0af198u: goto P_0c0af198;
case 0x0c0af19au: goto P_0c0af19a;
case 0x0c0af19cu: goto P_0c0af19c;
case 0x0c0af19eu: goto P_0c0af19e;
case 0x0c0af1a0u: goto P_0c0af1a0;
case 0x0c0af1a2u: goto P_0c0af1a2;
case 0x0c0af1a4u: goto P_0c0af1a4;
case 0x0c0af1a6u: goto P_0c0af1a6;
case 0x0c0af1a8u: goto P_0c0af1a8;
case 0x0c0af1aau: goto P_0c0af1aa;
case 0x0c0af1acu: goto P_0c0af1ac;
case 0x0c0af1aeu: goto P_0c0af1ae;
case 0x0c0af1b0u: goto P_0c0af1b0;
case 0x0c0af1b2u: goto P_0c0af1b2;
case 0x0c0af1b4u: goto P_0c0af1b4;
case 0x0c0af1b6u: goto P_0c0af1b6;
case 0x0c0af1b8u: goto P_0c0af1b8;
case 0x0c0af1bau: goto P_0c0af1ba;
case 0x0c0af1bcu: goto P_0c0af1bc;
case 0x0c0af1beu: goto P_0c0af1be;
case 0x0c0af1c0u: goto P_0c0af1c0;
case 0x0c0af1c2u: goto P_0c0af1c2;
case 0x0c0af1c4u: goto P_0c0af1c4;
case 0x0c0af1c6u: goto P_0c0af1c6;
case 0x0c0af1c8u: goto P_0c0af1c8;
case 0x0c0af1cau: goto P_0c0af1ca;
case 0x0c0af1ccu: goto P_0c0af1cc;
case 0x0c0af1ceu: goto P_0c0af1ce;
case 0x0c0af1d0u: goto P_0c0af1d0;
case 0x0c0af1d2u: goto P_0c0af1d2;
case 0x0c0af1d4u: goto P_0c0af1d4;
case 0x0c0af1d6u: goto P_0c0af1d6;
case 0x0c0af1d8u: goto P_0c0af1d8;
case 0x0c0af1dau: goto P_0c0af1da;
case 0x0c0af1dcu: goto P_0c0af1dc;
case 0x0c0af1deu: goto P_0c0af1de;
case 0x0c0af1e0u: goto P_0c0af1e0;
case 0x0c0af1e2u: goto P_0c0af1e2;
case 0x0c0af1e4u: goto P_0c0af1e4;
case 0x0c0af1e6u: goto P_0c0af1e6;
case 0x0c0af1e8u: goto P_0c0af1e8;
case 0x0c0af1eau: goto P_0c0af1ea;
case 0x0c0af1ecu: goto P_0c0af1ec;
case 0x0c0af1eeu: goto P_0c0af1ee;
case 0x0c0af1f0u: goto P_0c0af1f0;
case 0x0c0af1f2u: goto P_0c0af1f2;
case 0x0c0af1f4u: goto P_0c0af1f4;
case 0x0c0af1f6u: goto P_0c0af1f6;
case 0x0c0af1f8u: goto P_0c0af1f8;
case 0x0c0af1fau: goto P_0c0af1fa;
case 0x0c0af1fcu: goto P_0c0af1fc;
case 0x0c0af1feu: goto P_0c0af1fe;
case 0x0c0af200u: goto P_0c0af200;
case 0x0c0af202u: goto P_0c0af202;
case 0x0c0af204u: goto P_0c0af204;
case 0x0c0af206u: goto P_0c0af206;
case 0x0c0af208u: goto P_0c0af208;
case 0x0c0af20au: goto P_0c0af20a;
case 0x0c0af20cu: goto P_0c0af20c;
case 0x0c0af20eu: goto P_0c0af20e;
case 0x0c0af210u: goto P_0c0af210;
case 0x0c0af212u: goto P_0c0af212;
case 0x0c0af214u: goto P_0c0af214;
case 0x0c0af216u: goto P_0c0af216;
case 0x0c0af218u: goto P_0c0af218;
case 0x0c0af21au: goto P_0c0af21a;
case 0x0c0af21cu: goto P_0c0af21c;
case 0x0c0af21eu: goto P_0c0af21e;
case 0x0c0af220u: goto P_0c0af220;
case 0x0c0af222u: goto P_0c0af222;
case 0x0c0af224u: goto P_0c0af224;
case 0x0c0af226u: goto P_0c0af226;
case 0x0c0af228u: goto P_0c0af228;
case 0x0c0af22au: goto P_0c0af22a;
case 0x0c0af22cu: goto P_0c0af22c;
case 0x0c0af22eu: goto P_0c0af22e;
case 0x0c0af230u: goto P_0c0af230;
case 0x0c0af232u: goto P_0c0af232;
case 0x0c0af234u: goto P_0c0af234;
case 0x0c0af236u: goto P_0c0af236;
case 0x0c0af238u: goto P_0c0af238;
case 0x0c0af23au: goto P_0c0af23a;
case 0x0c0af23cu: goto P_0c0af23c;
case 0x0c0af23eu: goto P_0c0af23e;
case 0x0c0af240u: goto P_0c0af240;
case 0x0c0af242u: goto P_0c0af242;
case 0x0c0af244u: goto P_0c0af244;
case 0x0c0af246u: goto P_0c0af246;
case 0x0c0af248u: goto P_0c0af248;
case 0x0c0af24au: goto P_0c0af24a;
case 0x0c0af24cu: goto P_0c0af24c;
case 0x0c0af24eu: goto P_0c0af24e;
case 0x0c0af250u: goto P_0c0af250;
case 0x0c0af252u: goto P_0c0af252;
case 0x0c0af254u: goto P_0c0af254;
case 0x0c0af256u: goto P_0c0af256;
case 0x0c0af258u: goto P_0c0af258;
case 0x0c0af25au: goto P_0c0af25a;
case 0x0c0af25cu: goto P_0c0af25c;
case 0x0c0af25eu: goto P_0c0af25e;
case 0x0c0af260u: goto P_0c0af260;
case 0x0c0af262u: goto P_0c0af262;
case 0x0c0af264u: goto P_0c0af264;
case 0x0c0af266u: goto P_0c0af266;
case 0x0c0af268u: goto P_0c0af268;
case 0x0c0af26au: goto P_0c0af26a;
case 0x0c0af26cu: goto P_0c0af26c;
case 0x0c0af26eu: goto P_0c0af26e;
case 0x0c0af270u: goto P_0c0af270;
case 0x0c0af272u: goto P_0c0af272;
case 0x0c0af274u: goto P_0c0af274;
case 0x0c0af276u: goto P_0c0af276;
case 0x0c0af278u: goto P_0c0af278;
case 0x0c0af27au: goto P_0c0af27a;
case 0x0c0af27cu: goto P_0c0af27c;
case 0x0c0af27eu: goto P_0c0af27e;
case 0x0c0af280u: goto P_0c0af280;
case 0x0c0af282u: goto P_0c0af282;
case 0x0c0af284u: goto P_0c0af284;
case 0x0c0af286u: goto P_0c0af286;
case 0x0c0af288u: goto P_0c0af288;
case 0x0c0af28au: goto P_0c0af28a;
case 0x0c0af28cu: goto P_0c0af28c;
case 0x0c0af28eu: goto P_0c0af28e;
case 0x0c0af290u: goto P_0c0af290;
case 0x0c0af292u: goto P_0c0af292;
case 0x0c0af294u: goto P_0c0af294;
case 0x0c0af296u: goto P_0c0af296;
case 0x0c0af298u: goto P_0c0af298;
case 0x0c0af29au: goto P_0c0af29a;
case 0x0c0af29cu: goto P_0c0af29c;
case 0x0c0af29eu: goto P_0c0af29e;
case 0x0c0af2a0u: goto P_0c0af2a0;
case 0x0c0af2a2u: goto P_0c0af2a2;
case 0x0c0af2a4u: goto P_0c0af2a4;
case 0x0c0af2a6u: goto P_0c0af2a6;
case 0x0c0af2a8u: goto P_0c0af2a8;
case 0x0c0af2aau: goto P_0c0af2aa;
case 0x0c0af2acu: goto P_0c0af2ac;
case 0x0c0af2aeu: goto P_0c0af2ae;
case 0x0c0af2b0u: goto P_0c0af2b0;
case 0x0c0af2dcu: goto P_0c0af2dc;
case 0x0c0af2deu: goto P_0c0af2de;
case 0x0c0af2e0u: goto P_0c0af2e0;
case 0x0c0af2e2u: goto P_0c0af2e2;
case 0x0c0af2e4u: goto P_0c0af2e4;
case 0x0c0af2e6u: goto P_0c0af2e6;
case 0x0c0af2e8u: goto P_0c0af2e8;
case 0x0c0af2eau: goto P_0c0af2ea;
case 0x0c0af2ecu: goto P_0c0af2ec;
case 0x0c0af2eeu: goto P_0c0af2ee;
case 0x0c0af2f0u: goto P_0c0af2f0;
case 0x0c0af2f2u: goto P_0c0af2f2;
case 0x0c0af2f4u: goto P_0c0af2f4;
case 0x0c0af2f6u: goto P_0c0af2f6;
case 0x0c0af2f8u: goto P_0c0af2f8;
case 0x0c0af2fau: goto P_0c0af2fa;
case 0x0c0af2fcu: goto P_0c0af2fc;
case 0x0c0af2feu: goto P_0c0af2fe;
case 0x0c0af300u: goto P_0c0af300;
case 0x0c0af302u: goto P_0c0af302;
case 0x0c0af304u: goto P_0c0af304;
case 0x0c0af306u: goto P_0c0af306;
case 0x0c0af308u: goto P_0c0af308;
case 0x0c0af30au: goto P_0c0af30a;
case 0x0c0af30cu: goto P_0c0af30c;
case 0x0c0af30eu: goto P_0c0af30e;
case 0x0c0af310u: goto P_0c0af310;
case 0x0c0af312u: goto P_0c0af312;
case 0x0c0af314u: goto P_0c0af314;
case 0x0c0af316u: goto P_0c0af316;
case 0x0c0af318u: goto P_0c0af318;
case 0x0c0af31au: goto P_0c0af31a;
case 0x0c0af31cu: goto P_0c0af31c;
case 0x0c0af31eu: goto P_0c0af31e;
case 0x0c0af320u: goto P_0c0af320;
case 0x0c0af322u: goto P_0c0af322;
case 0x0c0af324u: goto P_0c0af324;
case 0x0c0af326u: goto P_0c0af326;
case 0x0c0af328u: goto P_0c0af328;
case 0x0c0af32au: goto P_0c0af32a;
case 0x0c0af32cu: goto P_0c0af32c;
case 0x0c0af32eu: goto P_0c0af32e;
case 0x0c0af330u: goto P_0c0af330;
case 0x0c0af332u: goto P_0c0af332;
case 0x0c0af334u: goto P_0c0af334;
case 0x0c0af336u: goto P_0c0af336;
case 0x0c0af338u: goto P_0c0af338;
case 0x0c0af33au: goto P_0c0af33a;
case 0x0c0af33cu: goto P_0c0af33c;
case 0x0c0af33eu: goto P_0c0af33e;
case 0x0c0af340u: goto P_0c0af340;
case 0x0c0af342u: goto P_0c0af342;
case 0x0c0af344u: goto P_0c0af344;
case 0x0c0af346u: goto P_0c0af346;
case 0x0c0af348u: goto P_0c0af348;
case 0x0c0af34au: goto P_0c0af34a;
case 0x0c0af34cu: goto P_0c0af34c;
case 0x0c0af34eu: goto P_0c0af34e;
case 0x0c0af350u: goto P_0c0af350;
case 0x0c0af352u: goto P_0c0af352;
case 0x0c0af354u: goto P_0c0af354;
case 0x0c0af356u: goto P_0c0af356;
case 0x0c0af358u: goto P_0c0af358;
case 0x0c0af35au: goto P_0c0af35a;
case 0x0c0af35cu: goto P_0c0af35c;
case 0x0c0af35eu: goto P_0c0af35e;
case 0x0c0af360u: goto P_0c0af360;
case 0x0c0af362u: goto P_0c0af362;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0af198: /* original 2fe6, guest PC 0x0c0af198 */
if(!s->budget--) { s->failed_pc=0x0c0af198u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af19a;
P_0c0af19a: /* original 2fd6, guest PC 0x0c0af19a */
if(!s->budget--) { s->failed_pc=0x0c0af19au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af19c;
P_0c0af19c: /* original 2fc6, guest PC 0x0c0af19c */
if(!s->budget--) { s->failed_pc=0x0c0af19cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af19e;
P_0c0af19e: /* original 2fb6, guest PC 0x0c0af19e */
if(!s->budget--) { s->failed_pc=0x0c0af19eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af1a0;
P_0c0af1a0: /* original 2fa6, guest PC 0x0c0af1a0 */
if(!s->budget--) { s->failed_pc=0x0c0af1a0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af1a2;
P_0c0af1a2: /* original 2f96, guest PC 0x0c0af1a2 */
if(!s->budget--) { s->failed_pc=0x0c0af1a2u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af1a4;
P_0c0af1a4: /* original 4f22, guest PC 0x0c0af1a4 */
if(!s->budget--) { s->failed_pc=0x0c0af1a4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0af1a6;
P_0c0af1a6: /* original 7ff0, guest PC 0x0c0af1a6 */
if(!s->budget--) { s->failed_pc=0x0c0af1a6u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0af1a8;
P_0c0af1a8: /* original 67f3, guest PC 0x0c0af1a8 */
if(!s->budget--) { s->failed_pc=0x0c0af1a8u; return 0; }
r[7]=r[15];
goto P_0c0af1aa;
P_0c0af1aa: /* original 7708, guest PC 0x0c0af1aa */
if(!s->budget--) { s->failed_pc=0x0c0af1aau; return 0; }
r[7]+=0x00000008u;
goto P_0c0af1ac;
P_0c0af1ac: /* original 1f71, guest PC 0x0c0af1ac */
if(!s->budget--) { s->failed_pc=0x0c0af1acu; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c0af1ae;
P_0c0af1ae: /* original 2f72, guest PC 0x0c0af1ae */
if(!s->budget--) { s->failed_pc=0x0c0af1aeu; return 0; }
write(ram,r[15],r[7],4);
goto P_0c0af1b0;
P_0c0af1b0: /* original 5762, guest PC 0x0c0af1b0 */
if(!s->budget--) { s->failed_pc=0x0c0af1b0u; return 0; }
r[7]=read(ram,r[6]+8,4);
goto P_0c0af1b2;
P_0c0af1b2: /* original da43, guest PC 0x0c0af1b2 */
if(!s->budget--) { s->failed_pc=0x0c0af1b2u; return 0; }
r[10]=read(ram,0x0c0af2c0u,4);
goto P_0c0af1b4;
P_0c0af1b4: /* original 8473, guest PC 0x0c0af1b4 */
if(!s->budget--) { s->failed_pc=0x0c0af1b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+3,1);
goto P_0c0af1b6;
P_0c0af1b6: /* original d941, guest PC 0x0c0af1b6 */
if(!s->budget--) { s->failed_pc=0x0c0af1b6u; return 0; }
r[9]=read(ram,0x0c0af2bcu,4);
goto P_0c0af1b8;
P_0c0af1b8: /* original 6d0c, guest PC 0x0c0af1b8 */
if(!s->budget--) { s->failed_pc=0x0c0af1b8u; return 0; }
r[13]=r[0]&255u;
goto P_0c0af1ba;
P_0c0af1ba: /* original 8477, guest PC 0x0c0af1ba */
if(!s->budget--) { s->failed_pc=0x0c0af1bau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+7,1);
goto P_0c0af1bc;
P_0c0af1bc: /* original dc41, guest PC 0x0c0af1bc */
if(!s->budget--) { s->failed_pc=0x0c0af1bcu; return 0; }
r[12]=read(ram,0x0c0af2c4u,4);
goto P_0c0af1be;
P_0c0af1be: /* original 600c, guest PC 0x0c0af1be */
if(!s->budget--) { s->failed_pc=0x0c0af1beu; return 0; }
r[0]=r[0]&255u;
goto P_0c0af1c0;
P_0c0af1c0: /* original 4028, guest PC 0x0c0af1c0 */
if(!s->budget--) { s->failed_pc=0x0c0af1c0u; return 0; }
r[0]<<=16;
goto P_0c0af1c2;
P_0c0af1c2: /* original 4018, guest PC 0x0c0af1c2 */
if(!s->budget--) { s->failed_pc=0x0c0af1c2u; return 0; }
r[0]<<=8;
goto P_0c0af1c4;
P_0c0af1c4: /* original 6e03, guest PC 0x0c0af1c4 */
if(!s->budget--) { s->failed_pc=0x0c0af1c4u; return 0; }
r[14]=r[0];
goto P_0c0af1c6;
P_0c0af1c6: /* original 8476, guest PC 0x0c0af1c6 */
if(!s->budget--) { s->failed_pc=0x0c0af1c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+6,1);
goto P_0c0af1c8;
P_0c0af1c8: /* original 2ea9, guest PC 0x0c0af1c8 */
if(!s->budget--) { s->failed_pc=0x0c0af1c8u; return 0; }
r[14]&=r[10];
goto P_0c0af1ca;
P_0c0af1ca: /* original 600c, guest PC 0x0c0af1ca */
if(!s->budget--) { s->failed_pc=0x0c0af1cau; return 0; }
r[0]=r[0]&255u;
goto P_0c0af1cc;
P_0c0af1cc: /* original 4028, guest PC 0x0c0af1cc */
if(!s->budget--) { s->failed_pc=0x0c0af1ccu; return 0; }
r[0]<<=16;
goto P_0c0af1ce;
P_0c0af1ce: /* original 2099, guest PC 0x0c0af1ce */
if(!s->budget--) { s->failed_pc=0x0c0af1ceu; return 0; }
r[0]&=r[9];
goto P_0c0af1d0;
P_0c0af1d0: /* original 2e0b, guest PC 0x0c0af1d0 */
if(!s->budget--) { s->failed_pc=0x0c0af1d0u; return 0; }
r[14]|=r[0];
goto P_0c0af1d2;
P_0c0af1d2: /* original 8475, guest PC 0x0c0af1d2 */
if(!s->budget--) { s->failed_pc=0x0c0af1d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+5,1);
goto P_0c0af1d4;
P_0c0af1d4: /* original 600c, guest PC 0x0c0af1d4 */
if(!s->budget--) { s->failed_pc=0x0c0af1d4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0af1d6;
P_0c0af1d6: /* original 4018, guest PC 0x0c0af1d6 */
if(!s->budget--) { s->failed_pc=0x0c0af1d6u; return 0; }
r[0]<<=8;
goto P_0c0af1d8;
P_0c0af1d8: /* original 20c9, guest PC 0x0c0af1d8 */
if(!s->budget--) { s->failed_pc=0x0c0af1d8u; return 0; }
r[0]&=r[12];
goto P_0c0af1da;
P_0c0af1da: /* original 53f1, guest PC 0x0c0af1da */
if(!s->budget--) { s->failed_pc=0x0c0af1dau; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0af1dc;
P_0c0af1dc: /* original 2e0b, guest PC 0x0c0af1dc */
if(!s->budget--) { s->failed_pc=0x0c0af1dcu; return 0; }
r[14]|=r[0];
goto P_0c0af1de;
P_0c0af1de: /* original 8474, guest PC 0x0c0af1de */
if(!s->budget--) { s->failed_pc=0x0c0af1deu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+4,1);
goto P_0c0af1e0;
P_0c0af1e0: /* original 600c, guest PC 0x0c0af1e0 */
if(!s->budget--) { s->failed_pc=0x0c0af1e0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0af1e2;
P_0c0af1e2: /* original 2e0b, guest PC 0x0c0af1e2 */
if(!s->budget--) { s->failed_pc=0x0c0af1e2u; return 0; }
r[14]|=r[0];
goto P_0c0af1e4;
P_0c0af1e4: /* original 847b, guest PC 0x0c0af1e4 */
if(!s->budget--) { s->failed_pc=0x0c0af1e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+11,1);
goto P_0c0af1e6;
P_0c0af1e6: /* original 600c, guest PC 0x0c0af1e6 */
if(!s->budget--) { s->failed_pc=0x0c0af1e6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0af1e8;
P_0c0af1e8: /* original 4028, guest PC 0x0c0af1e8 */
if(!s->budget--) { s->failed_pc=0x0c0af1e8u; return 0; }
r[0]<<=16;
goto P_0c0af1ea;
P_0c0af1ea: /* original 4018, guest PC 0x0c0af1ea */
if(!s->budget--) { s->failed_pc=0x0c0af1eau; return 0; }
r[0]<<=8;
goto P_0c0af1ec;
P_0c0af1ec: /* original 20a9, guest PC 0x0c0af1ec */
if(!s->budget--) { s->failed_pc=0x0c0af1ecu; return 0; }
r[0]&=r[10];
goto P_0c0af1ee;
P_0c0af1ee: /* original 6203, guest PC 0x0c0af1ee */
if(!s->budget--) { s->failed_pc=0x0c0af1eeu; return 0; }
r[2]=r[0];
goto P_0c0af1f0;
P_0c0af1f0: /* original 847a, guest PC 0x0c0af1f0 */
if(!s->budget--) { s->failed_pc=0x0c0af1f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+10,1);
goto P_0c0af1f2;
P_0c0af1f2: /* original 600c, guest PC 0x0c0af1f2 */
if(!s->budget--) { s->failed_pc=0x0c0af1f2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0af1f4;
P_0c0af1f4: /* original 4028, guest PC 0x0c0af1f4 */
if(!s->budget--) { s->failed_pc=0x0c0af1f4u; return 0; }
r[0]<<=16;
goto P_0c0af1f6;
P_0c0af1f6: /* original 2099, guest PC 0x0c0af1f6 */
if(!s->budget--) { s->failed_pc=0x0c0af1f6u; return 0; }
r[0]&=r[9];
goto P_0c0af1f8;
P_0c0af1f8: /* original 220b, guest PC 0x0c0af1f8 */
if(!s->budget--) { s->failed_pc=0x0c0af1f8u; return 0; }
r[2]|=r[0];
goto P_0c0af1fa;
P_0c0af1fa: /* original 8479, guest PC 0x0c0af1fa */
if(!s->budget--) { s->failed_pc=0x0c0af1fau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+9,1);
goto P_0c0af1fc;
P_0c0af1fc: /* original 600c, guest PC 0x0c0af1fc */
if(!s->budget--) { s->failed_pc=0x0c0af1fcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0af1fe;
P_0c0af1fe: /* original 4018, guest PC 0x0c0af1fe */
if(!s->budget--) { s->failed_pc=0x0c0af1feu; return 0; }
r[0]<<=8;
goto P_0c0af200;
P_0c0af200: /* original 20c9, guest PC 0x0c0af200 */
if(!s->budget--) { s->failed_pc=0x0c0af200u; return 0; }
r[0]&=r[12];
goto P_0c0af202;
P_0c0af202: /* original 220b, guest PC 0x0c0af202 */
if(!s->budget--) { s->failed_pc=0x0c0af202u; return 0; }
r[2]|=r[0];
goto P_0c0af204;
P_0c0af204: /* original 8478, guest PC 0x0c0af204 */
if(!s->budget--) { s->failed_pc=0x0c0af204u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+8,1);
goto P_0c0af206;
P_0c0af206: /* original 600c, guest PC 0x0c0af206 */
if(!s->budget--) { s->failed_pc=0x0c0af206u; return 0; }
r[0]=r[0]&255u;
goto P_0c0af208;
P_0c0af208: /* original 220b, guest PC 0x0c0af208 */
if(!s->budget--) { s->failed_pc=0x0c0af208u; return 0; }
r[2]|=r[0];
goto P_0c0af20a;
P_0c0af20a: /* original 2322, guest PC 0x0c0af20a */
if(!s->budget--) { s->failed_pc=0x0c0af20au; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0af20c;
P_0c0af20c: /* original 63f2, guest PC 0x0c0af20c */
if(!s->budget--) { s->failed_pc=0x0c0af20cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0af20e;
P_0c0af20e: /* original d72e, guest PC 0x0c0af20e */
if(!s->budget--) { s->failed_pc=0x0c0af20eu; return 0; }
r[7]=read(ram,0x0c0af2c8u,4);
goto P_0c0af210;
P_0c0af210: /* original f438, guest PC 0x0c0af210 */
if(!s->budget--) { s->failed_pc=0x0c0af210u; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c0af212;
P_0c0af212: /* original 63d3, guest PC 0x0c0af212 */
if(!s->budget--) { s->failed_pc=0x0c0af212u; return 0; }
r[3]=r[13];
goto P_0c0af214;
P_0c0af214: /* original 4328, guest PC 0x0c0af214 */
if(!s->budget--) { s->failed_pc=0x0c0af214u; return 0; }
r[3]<<=16;
goto P_0c0af216;
P_0c0af216: /* original 4318, guest PC 0x0c0af216 */
if(!s->budget--) { s->failed_pc=0x0c0af216u; return 0; }
r[3]<<=8;
goto P_0c0af218;
P_0c0af218: /* original 2378, guest PC 0x0c0af218 */
if(!s->budget--) { s->failed_pc=0x0c0af218u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c0af21a;
P_0c0af21a: /* original 8f05, guest PC 0x0c0af21a */
if(!s->budget--) { s->failed_pc=0x0c0af21au; return 0; }
cond=r[17]&1u;
r[1]=0x0000007fu;
if(!cond) { goto P_0c0af228; }
goto P_0c0af21e;
P_0c0af21c: /* original e17f, guest PC 0x0c0af21c */
if(!s->budget--) { s->failed_pc=0x0c0af21cu; return 0; }
r[1]=0x0000007fu;
goto P_0c0af21e;
P_0c0af21e: /* original e04c, guest PC 0x0c0af21e */
if(!s->budget--) { s->failed_pc=0x0c0af21eu; return 0; }
r[0]=0x0000004cu;
goto P_0c0af220;
P_0c0af220: /* original d32a, guest PC 0x0c0af220 */
if(!s->budget--) { s->failed_pc=0x0c0af220u; return 0; }
r[3]=read(ram,0x0c0af2ccu,4);
goto P_0c0af222;
P_0c0af222: /* original 024e, guest PC 0x0c0af222 */
if(!s->budget--) { s->failed_pc=0x0c0af222u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c0af224;
P_0c0af224: /* original 2239, guest PC 0x0c0af224 */
if(!s->budget--) { s->failed_pc=0x0c0af224u; return 0; }
r[2]&=r[3];
goto P_0c0af226;
P_0c0af226: /* original 0426, guest PC 0x0c0af226 */
if(!s->budget--) { s->failed_pc=0x0c0af226u; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c0af228;
P_0c0af228: /* original e050, guest PC 0x0c0af228 */
if(!s->budget--) { s->failed_pc=0x0c0af228u; return 0; }
r[0]=0x00000050u;
goto P_0c0af22a;
P_0c0af22a: /* original 034e, guest PC 0x0c0af22a */
if(!s->budget--) { s->failed_pc=0x0c0af22au; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0af22c;
P_0c0af22c: /* original 2d19, guest PC 0x0c0af22c */
if(!s->budget--) { s->failed_pc=0x0c0af22cu; return 0; }
r[13]&=r[1];
goto P_0c0af22e;
P_0c0af22e: /* original 43dd, guest PC 0x0c0af22e */
if(!s->budget--) { s->failed_pc=0x0c0af22eu; return 0; }
r[3]=(r[13]&0x80000000u)?((r[13]&31u)?r[3]>>((-r[13])&31u):0):r[3]<<(r[13]&31u);
goto P_0c0af230;
P_0c0af230: /* original 2378, guest PC 0x0c0af230 */
if(!s->budget--) { s->failed_pc=0x0c0af230u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c0af232;
P_0c0af232: /* original 8b01, guest PC 0x0c0af232 */
if(!s->budget--) { s->failed_pc=0x0c0af232u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0af238; }
goto P_0c0af234;
P_0c0af234: /* original a088, guest PC 0x0c0af234 */
if(!s->budget--) { s->failed_pc=0x0c0af234u; return 0; }
goto P_0c0af348;
P_0c0af236: /* original 0009, guest PC 0x0c0af236 */
if(!s->budget--) { s->failed_pc=0x0c0af236u; return 0; }
goto P_0c0af238;
P_0c0af238: /* original 6252, guest PC 0x0c0af238 */
if(!s->budget--) { s->failed_pc=0x0c0af238u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c0af23a;
P_0c0af23a: /* original db25, guest PC 0x0c0af23a */
if(!s->budget--) { s->failed_pc=0x0c0af23au; return 0; }
r[11]=read(ram,0x0c0af2d0u,4);
goto P_0c0af23c;
P_0c0af23c: /* original 22b8, guest PC 0x0c0af23c */
if(!s->budget--) { s->failed_pc=0x0c0af23cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[11])==0)!=0);
goto P_0c0af23e;
P_0c0af23e: /* original 8901, guest PC 0x0c0af23e */
if(!s->budget--) { s->failed_pc=0x0c0af23eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af244; }
goto P_0c0af240;
P_0c0af240: /* original a082, guest PC 0x0c0af240 */
if(!s->budget--) { s->failed_pc=0x0c0af240u; return 0; }
goto P_0c0af348;
P_0c0af242: /* original 0009, guest PC 0x0c0af242 */
if(!s->budget--) { s->failed_pc=0x0c0af242u; return 0; }
goto P_0c0af244;
P_0c0af244: /* original f38d, guest PC 0x0c0af244 */
if(!s->budget--) { s->failed_pc=0x0c0af244u; return 0; }
fr[3]=0;
goto P_0c0af246;
P_0c0af246: /* original f434, guest PC 0x0c0af246 */
if(!s->budget--) { s->failed_pc=0x0c0af246u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c0af248;
P_0c0af248: /* original 8905, guest PC 0x0c0af248 */
if(!s->budget--) { s->failed_pc=0x0c0af248u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af256; }
goto P_0c0af24a;
P_0c0af24a: /* original e05c, guest PC 0x0c0af24a */
if(!s->budget--) { s->failed_pc=0x0c0af24au; return 0; }
r[0]=0x0000005cu;
goto P_0c0af24c;
P_0c0af24c: /* original f346, guest PC 0x0c0af24c */
if(!s->budget--) { s->failed_pc=0x0c0af24cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0af24e;
P_0c0af24e: /* original f345, guest PC 0x0c0af24e */
if(!s->budget--) { s->failed_pc=0x0c0af24eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0af250;
P_0c0af250: /* original 8b01, guest PC 0x0c0af250 */
if(!s->budget--) { s->failed_pc=0x0c0af250u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0af256; }
goto P_0c0af252;
P_0c0af252: /* original a079, guest PC 0x0c0af252 */
if(!s->budget--) { s->failed_pc=0x0c0af252u; return 0; }
goto P_0c0af348;
P_0c0af254: /* original 0009, guest PC 0x0c0af254 */
if(!s->budget--) { s->failed_pc=0x0c0af254u; return 0; }
goto P_0c0af256;
P_0c0af256: /* original 5762, guest PC 0x0c0af256 */
if(!s->budget--) { s->failed_pc=0x0c0af256u; return 0; }
r[7]=read(ram,r[6]+8,4);
goto P_0c0af258;
P_0c0af258: /* original 8477, guest PC 0x0c0af258 */
if(!s->budget--) { s->failed_pc=0x0c0af258u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+7,1);
goto P_0c0af25a;
P_0c0af25a: /* original 600c, guest PC 0x0c0af25a */
if(!s->budget--) { s->failed_pc=0x0c0af25au; return 0; }
r[0]=r[0]&255u;
goto P_0c0af25c;
P_0c0af25c: /* original 4028, guest PC 0x0c0af25c */
if(!s->budget--) { s->failed_pc=0x0c0af25cu; return 0; }
r[0]<<=16;
goto P_0c0af25e;
P_0c0af25e: /* original 4018, guest PC 0x0c0af25e */
if(!s->budget--) { s->failed_pc=0x0c0af25eu; return 0; }
r[0]<<=8;
goto P_0c0af260;
P_0c0af260: /* original 20a9, guest PC 0x0c0af260 */
if(!s->budget--) { s->failed_pc=0x0c0af260u; return 0; }
r[0]&=r[10];
goto P_0c0af262;
P_0c0af262: /* original 6303, guest PC 0x0c0af262 */
if(!s->budget--) { s->failed_pc=0x0c0af262u; return 0; }
r[3]=r[0];
goto P_0c0af264;
P_0c0af264: /* original 8476, guest PC 0x0c0af264 */
if(!s->budget--) { s->failed_pc=0x0c0af264u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+6,1);
goto P_0c0af266;
P_0c0af266: /* original 600c, guest PC 0x0c0af266 */
if(!s->budget--) { s->failed_pc=0x0c0af266u; return 0; }
r[0]=r[0]&255u;
goto P_0c0af268;
P_0c0af268: /* original 4028, guest PC 0x0c0af268 */
if(!s->budget--) { s->failed_pc=0x0c0af268u; return 0; }
r[0]<<=16;
goto P_0c0af26a;
P_0c0af26a: /* original 2099, guest PC 0x0c0af26a */
if(!s->budget--) { s->failed_pc=0x0c0af26au; return 0; }
r[0]&=r[9];
goto P_0c0af26c;
P_0c0af26c: /* original 230b, guest PC 0x0c0af26c */
if(!s->budget--) { s->failed_pc=0x0c0af26cu; return 0; }
r[3]|=r[0];
goto P_0c0af26e;
P_0c0af26e: /* original 8475, guest PC 0x0c0af26e */
if(!s->budget--) { s->failed_pc=0x0c0af26eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+5,1);
goto P_0c0af270;
P_0c0af270: /* original 600c, guest PC 0x0c0af270 */
if(!s->budget--) { s->failed_pc=0x0c0af270u; return 0; }
r[0]=r[0]&255u;
goto P_0c0af272;
P_0c0af272: /* original 4018, guest PC 0x0c0af272 */
if(!s->budget--) { s->failed_pc=0x0c0af272u; return 0; }
r[0]<<=8;
goto P_0c0af274;
P_0c0af274: /* original 20c9, guest PC 0x0c0af274 */
if(!s->budget--) { s->failed_pc=0x0c0af274u; return 0; }
r[0]&=r[12];
goto P_0c0af276;
P_0c0af276: /* original 230b, guest PC 0x0c0af276 */
if(!s->budget--) { s->failed_pc=0x0c0af276u; return 0; }
r[3]|=r[0];
goto P_0c0af278;
P_0c0af278: /* original 8474, guest PC 0x0c0af278 */
if(!s->budget--) { s->failed_pc=0x0c0af278u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+4,1);
goto P_0c0af27a;
P_0c0af27a: /* original 6733, guest PC 0x0c0af27a */
if(!s->budget--) { s->failed_pc=0x0c0af27au; return 0; }
r[7]=r[3];
goto P_0c0af27c;
P_0c0af27c: /* original 9319, guest PC 0x0c0af27c */
if(!s->budget--) { s->failed_pc=0x0c0af27cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af2b2u,2);
goto P_0c0af27e;
P_0c0af27e: /* original 600c, guest PC 0x0c0af27e */
if(!s->budget--) { s->failed_pc=0x0c0af27eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0af280;
P_0c0af280: /* original 270b, guest PC 0x0c0af280 */
if(!s->budget--) { s->failed_pc=0x0c0af280u; return 0; }
r[7]|=r[0];
goto P_0c0af282;
P_0c0af282: /* original 677d, guest PC 0x0c0af282 */
if(!s->budget--) { s->failed_pc=0x0c0af282u; return 0; }
r[7]=r[7]&65535u;
goto P_0c0af284;
P_0c0af284: /* original 3730, guest PC 0x0c0af284 */
if(!s->budget--) { s->failed_pc=0x0c0af284u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[3])!=0);
goto P_0c0af286;
P_0c0af286: /* original 890a, guest PC 0x0c0af286 */
if(!s->budget--) { s->failed_pc=0x0c0af286u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af29e; }
goto P_0c0af288;
P_0c0af288: /* original 9214, guest PC 0x0c0af288 */
if(!s->budget--) { s->failed_pc=0x0c0af288u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af2b4u,2);
goto P_0c0af28a;
P_0c0af28a: /* original 3720, guest PC 0x0c0af28a */
if(!s->budget--) { s->failed_pc=0x0c0af28au; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[2])!=0);
goto P_0c0af28c;
P_0c0af28c: /* original 8907, guest PC 0x0c0af28c */
if(!s->budget--) { s->failed_pc=0x0c0af28cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af29e; }
goto P_0c0af28e;
P_0c0af28e: /* original 9312, guest PC 0x0c0af28e */
if(!s->budget--) { s->failed_pc=0x0c0af28eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af2b6u,2);
goto P_0c0af290;
P_0c0af290: /* original 3730, guest PC 0x0c0af290 */
if(!s->budget--) { s->failed_pc=0x0c0af290u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[3])!=0);
goto P_0c0af292;
P_0c0af292: /* original 8923, guest PC 0x0c0af292 */
if(!s->budget--) { s->failed_pc=0x0c0af292u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af2dc; }
goto P_0c0af294;
P_0c0af294: /* original 9210, guest PC 0x0c0af294 */
if(!s->budget--) { s->failed_pc=0x0c0af294u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af2b8u,2);
goto P_0c0af296;
P_0c0af296: /* original 3720, guest PC 0x0c0af296 */
if(!s->budget--) { s->failed_pc=0x0c0af296u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[2])!=0);
goto P_0c0af298;
P_0c0af298: /* original 8920, guest PC 0x0c0af298 */
if(!s->budget--) { s->failed_pc=0x0c0af298u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af2dc; }
goto P_0c0af29a;
P_0c0af29a: /* original a027, guest PC 0x0c0af29a */
if(!s->budget--) { s->failed_pc=0x0c0af29au; return 0; }
goto P_0c0af2ec;
P_0c0af29c: /* original 0009, guest PC 0x0c0af29c */
if(!s->budget--) { s->failed_pc=0x0c0af29cu; return 0; }
goto P_0c0af29e;
P_0c0af29e: /* original e050, guest PC 0x0c0af29e */
if(!s->budget--) { s->failed_pc=0x0c0af29eu; return 0; }
r[0]=0x00000050u;
goto P_0c0af2a0;
P_0c0af2a0: /* original 014e, guest PC 0x0c0af2a0 */
if(!s->budget--) { s->failed_pc=0x0c0af2a0u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c0af2a2;
P_0c0af2a2: /* original 21b8, guest PC 0x0c0af2a2 */
if(!s->budget--) { s->failed_pc=0x0c0af2a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[11])==0)!=0);
goto P_0c0af2a4;
P_0c0af2a4: /* original 8b02, guest PC 0x0c0af2a4 */
if(!s->budget--) { s->failed_pc=0x0c0af2a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0af2ac; }
goto P_0c0af2a6;
P_0c0af2a6: /* original de0b, guest PC 0x0c0af2a6 */
if(!s->budget--) { s->failed_pc=0x0c0af2a6u; return 0; }
r[14]=read(ram,0x0c0af2d4u,4);
goto P_0c0af2a8;
P_0c0af2a8: /* original a020, guest PC 0x0c0af2a8 */
if(!s->budget--) { s->failed_pc=0x0c0af2a8u; return 0; }
goto P_0c0af2ec;
P_0c0af2aa: /* original 0009, guest PC 0x0c0af2aa */
if(!s->budget--) { s->failed_pc=0x0c0af2aau; return 0; }
goto P_0c0af2ac;
P_0c0af2ac: /* original de0a, guest PC 0x0c0af2ac */
if(!s->budget--) { s->failed_pc=0x0c0af2acu; return 0; }
r[14]=read(ram,0x0c0af2d8u,4);
goto P_0c0af2ae;
P_0c0af2ae: /* original a01d, guest PC 0x0c0af2ae */
if(!s->budget--) { s->failed_pc=0x0c0af2aeu; return 0; }
goto P_0c0af2ec;
P_0c0af2b0: /* original 0009, guest PC 0x0c0af2b0 */
if(!s->budget--) { s->failed_pc=0x0c0af2b0u; return 0; }
if(!vf3_matrix_family(0x0c0af2b2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0af2b2u; return 0; } return 1;
P_0c0af2dc: /* original e050, guest PC 0x0c0af2dc */
if(!s->budget--) { s->failed_pc=0x0c0af2dcu; return 0; }
r[0]=0x00000050u;
goto P_0c0af2de;
P_0c0af2de: /* original 024e, guest PC 0x0c0af2de */
if(!s->budget--) { s->failed_pc=0x0c0af2deu; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c0af2e0;
P_0c0af2e0: /* original 22b8, guest PC 0x0c0af2e0 */
if(!s->budget--) { s->failed_pc=0x0c0af2e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[11])==0)!=0);
goto P_0c0af2e2;
P_0c0af2e2: /* original 8b02, guest PC 0x0c0af2e2 */
if(!s->budget--) { s->failed_pc=0x0c0af2e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0af2ea; }
goto P_0c0af2e4;
P_0c0af2e4: /* original de21, guest PC 0x0c0af2e4 */
if(!s->budget--) { s->failed_pc=0x0c0af2e4u; return 0; }
r[14]=read(ram,0x0c0af36cu,4);
goto P_0c0af2e6;
P_0c0af2e6: /* original a001, guest PC 0x0c0af2e6 */
if(!s->budget--) { s->failed_pc=0x0c0af2e6u; return 0; }
goto P_0c0af2ec;
P_0c0af2e8: /* original 0009, guest PC 0x0c0af2e8 */
if(!s->budget--) { s->failed_pc=0x0c0af2e8u; return 0; }
goto P_0c0af2ea;
P_0c0af2ea: /* original de21, guest PC 0x0c0af2ea */
if(!s->budget--) { s->failed_pc=0x0c0af2eau; return 0; }
r[14]=read(ram,0x0c0af370u,4);
goto P_0c0af2ec;
P_0c0af2ec: /* original e03c, guest PC 0x0c0af2ec */
if(!s->budget--) { s->failed_pc=0x0c0af2ecu; return 0; }
r[0]=0x0000003cu;
goto P_0c0af2ee;
P_0c0af2ee: /* original 9339, guest PC 0x0c0af2ee */
if(!s->budget--) { s->failed_pc=0x0c0af2eeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af364u,2);
goto P_0c0af2f0;
P_0c0af2f0: /* original 074d, guest PC 0x0c0af2f0 */
if(!s->budget--) { s->failed_pc=0x0c0af2f0u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0af2f2;
P_0c0af2f2: /* original e050, guest PC 0x0c0af2f2 */
if(!s->budget--) { s->failed_pc=0x0c0af2f2u; return 0; }
r[0]=0x00000050u;
goto P_0c0af2f4;
P_0c0af2f4: /* original 0a4e, guest PC 0x0c0af2f4 */
if(!s->budget--) { s->failed_pc=0x0c0af2f4u; return 0; }
r[10]=read(ram,r[4]+r[0],4);
goto P_0c0af2f6;
P_0c0af2f6: /* original dd1f, guest PC 0x0c0af2f6 */
if(!s->budget--) { s->failed_pc=0x0c0af2f6u; return 0; }
r[13]=read(ram,0x0c0af374u,4);
goto P_0c0af2f8;
P_0c0af2f8: /* original 677d, guest PC 0x0c0af2f8 */
if(!s->budget--) { s->failed_pc=0x0c0af2f8u; return 0; }
r[7]=r[7]&65535u;
goto P_0c0af2fa;
P_0c0af2fa: /* original 6ca3, guest PC 0x0c0af2fa */
if(!s->budget--) { s->failed_pc=0x0c0af2fau; return 0; }
r[12]=r[10];
goto P_0c0af2fc;
P_0c0af2fc: /* original 3730, guest PC 0x0c0af2fc */
if(!s->budget--) { s->failed_pc=0x0c0af2fcu; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[3])!=0);
goto P_0c0af2fe;
P_0c0af2fe: /* original 2cb9, guest PC 0x0c0af2fe */
if(!s->budget--) { s->failed_pc=0x0c0af2feu; return 0; }
r[12]&=r[11];
goto P_0c0af300;
P_0c0af300: /* original 8d0b, guest PC 0x0c0af300 */
if(!s->budget--) { s->failed_pc=0x0c0af300u; return 0; }
cond=r[17]&1u;
r[13]&=r[10];
if(cond) { goto P_0c0af31a; }
goto P_0c0af304;
P_0c0af302: /* original 2da9, guest PC 0x0c0af302 */
if(!s->budget--) { s->failed_pc=0x0c0af302u; return 0; }
r[13]&=r[10];
goto P_0c0af304;
P_0c0af304: /* original 922f, guest PC 0x0c0af304 */
if(!s->budget--) { s->failed_pc=0x0c0af304u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af366u,2);
goto P_0c0af306;
P_0c0af306: /* original 3720, guest PC 0x0c0af306 */
if(!s->budget--) { s->failed_pc=0x0c0af306u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[2])!=0);
goto P_0c0af308;
P_0c0af308: /* original 890d, guest PC 0x0c0af308 */
if(!s->budget--) { s->failed_pc=0x0c0af308u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af326; }
goto P_0c0af30a;
P_0c0af30a: /* original 932d, guest PC 0x0c0af30a */
if(!s->budget--) { s->failed_pc=0x0c0af30au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af368u,2);
goto P_0c0af30c;
P_0c0af30c: /* original 3730, guest PC 0x0c0af30c */
if(!s->budget--) { s->failed_pc=0x0c0af30cu; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[3])!=0);
goto P_0c0af30e;
P_0c0af30e: /* original 8910, guest PC 0x0c0af30e */
if(!s->budget--) { s->failed_pc=0x0c0af30eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af332; }
goto P_0c0af310;
P_0c0af310: /* original 922b, guest PC 0x0c0af310 */
if(!s->budget--) { s->failed_pc=0x0c0af310u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af36au,2);
goto P_0c0af312;
P_0c0af312: /* original 3720, guest PC 0x0c0af312 */
if(!s->budget--) { s->failed_pc=0x0c0af312u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[2])!=0);
goto P_0c0af314;
P_0c0af314: /* original 8913, guest PC 0x0c0af314 */
if(!s->budget--) { s->failed_pc=0x0c0af314u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af33e; }
goto P_0c0af316;
P_0c0af316: /* original a016, guest PC 0x0c0af316 */
if(!s->budget--) { s->failed_pc=0x0c0af316u; return 0; }
goto P_0c0af346;
P_0c0af318: /* original 0009, guest PC 0x0c0af318 */
if(!s->budget--) { s->failed_pc=0x0c0af318u; return 0; }
goto P_0c0af31a;
P_0c0af31a: /* original 2cc8, guest PC 0x0c0af31a */
if(!s->budget--) { s->failed_pc=0x0c0af31au; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0af31c;
P_0c0af31c: /* original 8b14, guest PC 0x0c0af31c */
if(!s->budget--) { s->failed_pc=0x0c0af31cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0af348; }
goto P_0c0af31e;
P_0c0af31e: /* original 2dd8, guest PC 0x0c0af31e */
if(!s->budget--) { s->failed_pc=0x0c0af31eu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0af320;
P_0c0af320: /* original 8b12, guest PC 0x0c0af320 */
if(!s->budget--) { s->failed_pc=0x0c0af320u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0af348; }
goto P_0c0af322;
P_0c0af322: /* original a010, guest PC 0x0c0af322 */
if(!s->budget--) { s->failed_pc=0x0c0af322u; return 0; }
goto P_0c0af346;
P_0c0af324: /* original 0009, guest PC 0x0c0af324 */
if(!s->budget--) { s->failed_pc=0x0c0af324u; return 0; }
goto P_0c0af326;
P_0c0af326: /* original 2cc8, guest PC 0x0c0af326 */
if(!s->budget--) { s->failed_pc=0x0c0af326u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0af328;
P_0c0af328: /* original 890e, guest PC 0x0c0af328 */
if(!s->budget--) { s->failed_pc=0x0c0af328u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af348; }
goto P_0c0af32a;
P_0c0af32a: /* original 2dd8, guest PC 0x0c0af32a */
if(!s->budget--) { s->failed_pc=0x0c0af32au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0af32c;
P_0c0af32c: /* original 890c, guest PC 0x0c0af32c */
if(!s->budget--) { s->failed_pc=0x0c0af32cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af348; }
goto P_0c0af32e;
P_0c0af32e: /* original a00a, guest PC 0x0c0af32e */
if(!s->budget--) { s->failed_pc=0x0c0af32eu; return 0; }
goto P_0c0af346;
P_0c0af330: /* original 0009, guest PC 0x0c0af330 */
if(!s->budget--) { s->failed_pc=0x0c0af330u; return 0; }
goto P_0c0af332;
P_0c0af332: /* original 2cc8, guest PC 0x0c0af332 */
if(!s->budget--) { s->failed_pc=0x0c0af332u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0af334;
P_0c0af334: /* original 8b08, guest PC 0x0c0af334 */
if(!s->budget--) { s->failed_pc=0x0c0af334u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0af348; }
goto P_0c0af336;
P_0c0af336: /* original 2dd8, guest PC 0x0c0af336 */
if(!s->budget--) { s->failed_pc=0x0c0af336u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0af338;
P_0c0af338: /* original 8906, guest PC 0x0c0af338 */
if(!s->budget--) { s->failed_pc=0x0c0af338u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af348; }
goto P_0c0af33a;
P_0c0af33a: /* original a004, guest PC 0x0c0af33a */
if(!s->budget--) { s->failed_pc=0x0c0af33au; return 0; }
goto P_0c0af346;
P_0c0af33c: /* original 0009, guest PC 0x0c0af33c */
if(!s->budget--) { s->failed_pc=0x0c0af33cu; return 0; }
goto P_0c0af33e;
P_0c0af33e: /* original 2cc8, guest PC 0x0c0af33e */
if(!s->budget--) { s->failed_pc=0x0c0af33eu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0af340;
P_0c0af340: /* original 8902, guest PC 0x0c0af340 */
if(!s->budget--) { s->failed_pc=0x0c0af340u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af348; }
goto P_0c0af342;
P_0c0af342: /* original 2dd8, guest PC 0x0c0af342 */
if(!s->budget--) { s->failed_pc=0x0c0af342u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0af344;
P_0c0af344: /* original 8900, guest PC 0x0c0af344 */
if(!s->budget--) { s->failed_pc=0x0c0af344u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af348; }
goto P_0c0af346;
P_0c0af346: /* original 14ec, guest PC 0x0c0af346 */
if(!s->budget--) { s->failed_pc=0x0c0af346u; return 0; }
write(ram,r[4]+48,r[14],4);
goto P_0c0af348;
P_0c0af348: /* original 5262, guest PC 0x0c0af348 */
if(!s->budget--) { s->failed_pc=0x0c0af348u; return 0; }
r[2]=read(ram,r[6]+8,4);
goto P_0c0af34a;
P_0c0af34a: /* original d30b, guest PC 0x0c0af34a */
if(!s->budget--) { s->failed_pc=0x0c0af34au; return 0; }
r[3]=read(ram,0x0c0af378u,4);
goto P_0c0af34c;
P_0c0af34c: /* original 720c, guest PC 0x0c0af34c */
if(!s->budget--) { s->failed_pc=0x0c0af34cu; return 0; }
r[2]+=0x0000000cu;
goto P_0c0af34e;
P_0c0af34e: /* original 430b, guest PC 0x0c0af34e */
if(!s->budget--) { s->failed_pc=0x0c0af34eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0af352u;
write(ram,r[6]+8,r[2],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0af352u) { target=s->pc; goto dispatch; }
goto P_0c0af352;
P_0c0af350: /* original 1622, guest PC 0x0c0af350 */
if(!s->budget--) { s->failed_pc=0x0c0af350u; return 0; }
write(ram,r[6]+8,r[2],4);
goto P_0c0af352;
P_0c0af352: /* original 7f10, guest PC 0x0c0af352 */
if(!s->budget--) { s->failed_pc=0x0c0af352u; return 0; }
r[15]+=0x00000010u;
goto P_0c0af354;
P_0c0af354: /* original 4f26, guest PC 0x0c0af354 */
if(!s->budget--) { s->failed_pc=0x0c0af354u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0af356;
P_0c0af356: /* original 69f6, guest PC 0x0c0af356 */
if(!s->budget--) { s->failed_pc=0x0c0af356u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0af358;
P_0c0af358: /* original 6af6, guest PC 0x0c0af358 */
if(!s->budget--) { s->failed_pc=0x0c0af358u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0af35a;
P_0c0af35a: /* original 6bf6, guest PC 0x0c0af35a */
if(!s->budget--) { s->failed_pc=0x0c0af35au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0af35c;
P_0c0af35c: /* original 6cf6, guest PC 0x0c0af35c */
if(!s->budget--) { s->failed_pc=0x0c0af35cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0af35e;
P_0c0af35e: /* original 6df6, guest PC 0x0c0af35e */
if(!s->budget--) { s->failed_pc=0x0c0af35eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0af360;
P_0c0af360: /* original 000b, guest PC 0x0c0af360 */
if(!s->budget--) { s->failed_pc=0x0c0af360u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0af362: /* original 6ef6, guest PC 0x0c0af362 */
if(!s->budget--) { s->failed_pc=0x0c0af362u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0af364u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0af364u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
