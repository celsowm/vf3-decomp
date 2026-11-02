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
int vf3_away_batch6_adapter_23(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0541ecu: goto P_0c0541ec;
case 0x0c0541eeu: goto P_0c0541ee;
case 0x0c0541f0u: goto P_0c0541f0;
case 0x0c0541f2u: goto P_0c0541f2;
case 0x0c0541f4u: goto P_0c0541f4;
case 0x0c0541f6u: goto P_0c0541f6;
case 0x0c0541f8u: goto P_0c0541f8;
case 0x0c0541fau: goto P_0c0541fa;
case 0x0c0541fcu: goto P_0c0541fc;
case 0x0c0541feu: goto P_0c0541fe;
case 0x0c054200u: goto P_0c054200;
case 0x0c054202u: goto P_0c054202;
case 0x0c054204u: goto P_0c054204;
case 0x0c054206u: goto P_0c054206;
case 0x0c054208u: goto P_0c054208;
case 0x0c05420au: goto P_0c05420a;
case 0x0c05420cu: goto P_0c05420c;
case 0x0c05420eu: goto P_0c05420e;
case 0x0c054210u: goto P_0c054210;
case 0x0c054212u: goto P_0c054212;
case 0x0c054214u: goto P_0c054214;
case 0x0c054216u: goto P_0c054216;
case 0x0c054218u: goto P_0c054218;
case 0x0c05421au: goto P_0c05421a;
case 0x0c05421cu: goto P_0c05421c;
case 0x0c05421eu: goto P_0c05421e;
case 0x0c054220u: goto P_0c054220;
case 0x0c054222u: goto P_0c054222;
case 0x0c054224u: goto P_0c054224;
case 0x0c054226u: goto P_0c054226;
case 0x0c054228u: goto P_0c054228;
case 0x0c05422au: goto P_0c05422a;
case 0x0c05422cu: goto P_0c05422c;
case 0x0c05422eu: goto P_0c05422e;
case 0x0c054230u: goto P_0c054230;
case 0x0c054232u: goto P_0c054232;
case 0x0c054234u: goto P_0c054234;
case 0x0c054236u: goto P_0c054236;
case 0x0c054238u: goto P_0c054238;
case 0x0c05423au: goto P_0c05423a;
case 0x0c05423cu: goto P_0c05423c;
case 0x0c05423eu: goto P_0c05423e;
case 0x0c054240u: goto P_0c054240;
case 0x0c054244u: goto P_0c054244;
case 0x0c054246u: goto P_0c054246;
case 0x0c054248u: goto P_0c054248;
case 0x0c05424au: goto P_0c05424a;
case 0x0c05424cu: goto P_0c05424c;
case 0x0c05424eu: goto P_0c05424e;
case 0x0c054250u: goto P_0c054250;
case 0x0c054252u: goto P_0c054252;
case 0x0c054254u: goto P_0c054254;
case 0x0c054256u: goto P_0c054256;
case 0x0c054258u: goto P_0c054258;
case 0x0c05425au: goto P_0c05425a;
case 0x0c05425cu: goto P_0c05425c;
case 0x0c054268u: goto P_0c054268;
case 0x0c05426au: goto P_0c05426a;
case 0x0c05426cu: goto P_0c05426c;
case 0x0c05426eu: goto P_0c05426e;
case 0x0c054270u: goto P_0c054270;
case 0x0c054272u: goto P_0c054272;
case 0x0c054274u: goto P_0c054274;
case 0x0c054276u: goto P_0c054276;
case 0x0c054278u: goto P_0c054278;
case 0x0c05427au: goto P_0c05427a;
case 0x0c05427cu: goto P_0c05427c;
case 0x0c05427eu: goto P_0c05427e;
case 0x0c054280u: goto P_0c054280;
case 0x0c054282u: goto P_0c054282;
case 0x0c054284u: goto P_0c054284;
case 0x0c054286u: goto P_0c054286;
case 0x0c054288u: goto P_0c054288;
case 0x0c05428au: goto P_0c05428a;
case 0x0c05428cu: goto P_0c05428c;
case 0x0c05428eu: goto P_0c05428e;
case 0x0c054290u: goto P_0c054290;
case 0x0c054292u: goto P_0c054292;
case 0x0c054294u: goto P_0c054294;
case 0x0c054296u: goto P_0c054296;
case 0x0c054298u: goto P_0c054298;
case 0x0c05429au: goto P_0c05429a;
case 0x0c05429cu: goto P_0c05429c;
case 0x0c05429eu: goto P_0c05429e;
case 0x0c0542a0u: goto P_0c0542a0;
case 0x0c0542a2u: goto P_0c0542a2;
case 0x0c0542a4u: goto P_0c0542a4;
case 0x0c0542a6u: goto P_0c0542a6;
case 0x0c0542a8u: goto P_0c0542a8;
case 0x0c0542aau: goto P_0c0542aa;
case 0x0c0542acu: goto P_0c0542ac;
case 0x0c0542aeu: goto P_0c0542ae;
case 0x0c0542b0u: goto P_0c0542b0;
case 0x0c0542b2u: goto P_0c0542b2;
case 0x0c0542b4u: goto P_0c0542b4;
case 0x0c0542b6u: goto P_0c0542b6;
case 0x0c0542b8u: goto P_0c0542b8;
case 0x0c0542bau: goto P_0c0542ba;
case 0x0c0542bcu: goto P_0c0542bc;
case 0x0c0542beu: goto P_0c0542be;
case 0x0c0542c0u: goto P_0c0542c0;
case 0x0c0542c2u: goto P_0c0542c2;
case 0x0c0542c4u: goto P_0c0542c4;
case 0x0c0542c8u: goto P_0c0542c8;
case 0x0c0542cau: goto P_0c0542ca;
case 0x0c0542ccu: goto P_0c0542cc;
case 0x0c0542ceu: goto P_0c0542ce;
case 0x0c0542d0u: goto P_0c0542d0;
case 0x0c0542d2u: goto P_0c0542d2;
case 0x0c0542d4u: goto P_0c0542d4;
case 0x0c0542d6u: goto P_0c0542d6;
case 0x0c0542d8u: goto P_0c0542d8;
case 0x0c0542dau: goto P_0c0542da;
case 0x0c0542dcu: goto P_0c0542dc;
case 0x0c0542deu: goto P_0c0542de;
case 0x0c0542e0u: goto P_0c0542e0;
case 0x0c0542e2u: goto P_0c0542e2;
case 0x0c0542e4u: goto P_0c0542e4;
case 0x0c0542e6u: goto P_0c0542e6;
case 0x0c0542e8u: goto P_0c0542e8;
case 0x0c0542eau: goto P_0c0542ea;
case 0x0c0542ecu: goto P_0c0542ec;
case 0x0c0542eeu: goto P_0c0542ee;
case 0x0c0542f0u: goto P_0c0542f0;
case 0x0c0542f2u: goto P_0c0542f2;
case 0x0c0542f4u: goto P_0c0542f4;
case 0x0c0542f6u: goto P_0c0542f6;
case 0x0c0542f8u: goto P_0c0542f8;
case 0x0c0542fau: goto P_0c0542fa;
case 0x0c0542fcu: goto P_0c0542fc;
case 0x0c0542feu: goto P_0c0542fe;
case 0x0c054300u: goto P_0c054300;
case 0x0c054302u: goto P_0c054302;
case 0x0c054304u: goto P_0c054304;
case 0x0c054306u: goto P_0c054306;
case 0x0c054308u: goto P_0c054308;
case 0x0c05430au: goto P_0c05430a;
case 0x0c05430cu: goto P_0c05430c;
case 0x0c05430eu: goto P_0c05430e;
case 0x0c054310u: goto P_0c054310;
case 0x0c054312u: goto P_0c054312;
case 0x0c054314u: goto P_0c054314;
case 0x0c054316u: goto P_0c054316;
case 0x0c054318u: goto P_0c054318;
case 0x0c05431au: goto P_0c05431a;
case 0x0c05431cu: goto P_0c05431c;
case 0x0c05431eu: goto P_0c05431e;
case 0x0c054320u: goto P_0c054320;
case 0x0c054322u: goto P_0c054322;
case 0x0c054324u: goto P_0c054324;
case 0x0c054326u: goto P_0c054326;
case 0x0c054328u: goto P_0c054328;
case 0x0c05432au: goto P_0c05432a;
case 0x0c05432cu: goto P_0c05432c;
case 0x0c05432eu: goto P_0c05432e;
case 0x0c054330u: goto P_0c054330;
case 0x0c054332u: goto P_0c054332;
case 0x0c054334u: goto P_0c054334;
case 0x0c054336u: goto P_0c054336;
case 0x0c054338u: goto P_0c054338;
case 0x0c05433au: goto P_0c05433a;
case 0x0c05433cu: goto P_0c05433c;
case 0x0c05433eu: goto P_0c05433e;
case 0x0c054340u: goto P_0c054340;
case 0x0c054342u: goto P_0c054342;
case 0x0c054344u: goto P_0c054344;
case 0x0c054384u: goto P_0c054384;
case 0x0c054386u: goto P_0c054386;
case 0x0c054388u: goto P_0c054388;
case 0x0c05438au: goto P_0c05438a;
case 0x0c05438cu: goto P_0c05438c;
case 0x0c05438eu: goto P_0c05438e;
case 0x0c054390u: goto P_0c054390;
case 0x0c054392u: goto P_0c054392;
case 0x0c054394u: goto P_0c054394;
case 0x0c054396u: goto P_0c054396;
case 0x0c054398u: goto P_0c054398;
case 0x0c05439au: goto P_0c05439a;
case 0x0c05439cu: goto P_0c05439c;
case 0x0c05439eu: goto P_0c05439e;
case 0x0c0543a0u: goto P_0c0543a0;
case 0x0c0543a2u: goto P_0c0543a2;
case 0x0c0543a4u: goto P_0c0543a4;
case 0x0c0543a6u: goto P_0c0543a6;
case 0x0c0543a8u: goto P_0c0543a8;
case 0x0c0543aau: goto P_0c0543aa;
case 0x0c0543acu: goto P_0c0543ac;
case 0x0c0543aeu: goto P_0c0543ae;
case 0x0c0543b0u: goto P_0c0543b0;
case 0x0c0543b2u: goto P_0c0543b2;
case 0x0c0543b4u: goto P_0c0543b4;
case 0x0c0543b6u: goto P_0c0543b6;
case 0x0c0543b8u: goto P_0c0543b8;
case 0x0c0543bau: goto P_0c0543ba;
case 0x0c0543bcu: goto P_0c0543bc;
case 0x0c0543beu: goto P_0c0543be;
case 0x0c0543c0u: goto P_0c0543c0;
case 0x0c0543c2u: goto P_0c0543c2;
case 0x0c0543c4u: goto P_0c0543c4;
case 0x0c0543c6u: goto P_0c0543c6;
case 0x0c0543c8u: goto P_0c0543c8;
case 0x0c0543cau: goto P_0c0543ca;
case 0x0c0543ccu: goto P_0c0543cc;
case 0x0c0543ceu: goto P_0c0543ce;
case 0x0c0543d0u: goto P_0c0543d0;
case 0x0c0543d2u: goto P_0c0543d2;
case 0x0c0543d4u: goto P_0c0543d4;
case 0x0c0543d6u: goto P_0c0543d6;
case 0x0c0543d8u: goto P_0c0543d8;
case 0x0c0543dau: goto P_0c0543da;
case 0x0c0543dcu: goto P_0c0543dc;
case 0x0c0543deu: goto P_0c0543de;
case 0x0c0543e0u: goto P_0c0543e0;
case 0x0c0543e2u: goto P_0c0543e2;
case 0x0c0543e4u: goto P_0c0543e4;
case 0x0c0543e6u: goto P_0c0543e6;
case 0x0c0543e8u: goto P_0c0543e8;
case 0x0c0543eau: goto P_0c0543ea;
case 0x0c0543ecu: goto P_0c0543ec;
case 0x0c0543eeu: goto P_0c0543ee;
case 0x0c0543f0u: goto P_0c0543f0;
case 0x0c0543f2u: goto P_0c0543f2;
case 0x0c0543f4u: goto P_0c0543f4;
case 0x0c0543f6u: goto P_0c0543f6;
case 0x0c0543f8u: goto P_0c0543f8;
case 0x0c0543fau: goto P_0c0543fa;
case 0x0c0543fcu: goto P_0c0543fc;
case 0x0c0543feu: goto P_0c0543fe;
case 0x0c054400u: goto P_0c054400;
case 0x0c054402u: goto P_0c054402;
case 0x0c054404u: goto P_0c054404;
case 0x0c054406u: goto P_0c054406;
case 0x0c054408u: goto P_0c054408;
case 0x0c05440au: goto P_0c05440a;
case 0x0c05440cu: goto P_0c05440c;
case 0x0c05440eu: goto P_0c05440e;
case 0x0c054410u: goto P_0c054410;
case 0x0c054412u: goto P_0c054412;
case 0x0c054414u: goto P_0c054414;
case 0x0c054416u: goto P_0c054416;
case 0x0c054418u: goto P_0c054418;
case 0x0c05441au: goto P_0c05441a;
case 0x0c05441cu: goto P_0c05441c;
case 0x0c05441eu: goto P_0c05441e;
case 0x0c054420u: goto P_0c054420;
case 0x0c054422u: goto P_0c054422;
case 0x0c054424u: goto P_0c054424;
case 0x0c054426u: goto P_0c054426;
case 0x0c054428u: goto P_0c054428;
case 0x0c05442au: goto P_0c05442a;
case 0x0c05442cu: goto P_0c05442c;
case 0x0c05442eu: goto P_0c05442e;
case 0x0c054430u: goto P_0c054430;
case 0x0c054432u: goto P_0c054432;
case 0x0c054434u: goto P_0c054434;
case 0x0c054436u: goto P_0c054436;
case 0x0c054438u: goto P_0c054438;
case 0x0c05443au: goto P_0c05443a;
case 0x0c05443cu: goto P_0c05443c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0541ec: /* original 2fe6, guest PC 0x0c0541ec */
if(!s->budget--) { s->failed_pc=0x0c0541ecu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0541ee;
P_0c0541ee: /* original e708, guest PC 0x0c0541ee */
if(!s->budget--) { s->failed_pc=0x0c0541eeu; return 0; }
r[7]=0x00000008u;
goto P_0c0541f0;
P_0c0541f0: /* original 3768, guest PC 0x0c0541f0 */
if(!s->budget--) { s->failed_pc=0x0c0541f0u; return 0; }
r[7]-=r[6];
goto P_0c0541f2;
P_0c0541f2: /* original 6e7f, guest PC 0x0c0541f2 */
if(!s->budget--) { s->failed_pc=0x0c0541f2u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c0541f4;
P_0c0541f4: /* original 2ee8, guest PC 0x0c0541f4 */
if(!s->budget--) { s->failed_pc=0x0c0541f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0541f6;
P_0c0541f6: /* original 8d22, guest PC 0x0c0541f6 */
if(!s->budget--) { s->failed_pc=0x0c0541f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05423e; }
goto P_0c0541fa;
P_0c0541f8: /* original 0009, guest PC 0x0c0541f8 */
if(!s->budget--) { s->failed_pc=0x0c0541f8u; return 0; }
goto P_0c0541fa;
P_0c0541fa: /* original 9122, guest PC 0x0c0541fa */
if(!s->budget--) { s->failed_pc=0x0c0541fau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c054242u,2);
goto P_0c0541fc;
P_0c0541fc: /* original 0009, guest PC 0x0c0541fc */
if(!s->budget--) { s->failed_pc=0x0c0541fcu; return 0; }
goto P_0c0541fe;
P_0c0541fe: /* original 41ec, guest PC 0x0c0541fe */
if(!s->budget--) { s->failed_pc=0x0c0541feu; return 0; }
r[1]=(r[14]&0x80000000u)?((r[14]&31u)?(uint32_t)((int32_t)r[1]>>((-r[14])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[14]&31u);
goto P_0c054200;
P_0c054200: /* original e700, guest PC 0x0c054200 */
if(!s->budget--) { s->failed_pc=0x0c054200u; return 0; }
r[7]=0x00000000u;
goto P_0c054202;
P_0c054202: /* original 75ff, guest PC 0x0c054202 */
if(!s->budget--) { s->failed_pc=0x0c054202u; return 0; }
r[5]+=0xffffffffu;
goto P_0c054204;
P_0c054204: /* original 4511, guest PC 0x0c054204 */
if(!s->budget--) { s->failed_pc=0x0c054204u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c054206;
P_0c054206: /* original 8f12, guest PC 0x0c054206 */
if(!s->budget--) { s->failed_pc=0x0c054206u; return 0; }
cond=r[17]&1u;
r[4]+=r[5];
if(!cond) { goto P_0c05422e; }
goto P_0c05420a;
P_0c054208: /* original 345c, guest PC 0x0c054208 */
if(!s->budget--) { s->failed_pc=0x0c054208u; return 0; }
r[4]+=r[5];
goto P_0c05420a;
P_0c05420a: /* original 636f, guest PC 0x0c05420a */
if(!s->budget--) { s->failed_pc=0x0c05420au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c05420c;
P_0c05420c: /* original 6240, guest PC 0x0c05420c */
if(!s->budget--) { s->failed_pc=0x0c05420cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c05420e;
P_0c05420e: /* original 6040, guest PC 0x0c05420e */
if(!s->budget--) { s->failed_pc=0x0c05420eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
goto P_0c054210;
P_0c054210: /* original 2019, guest PC 0x0c054210 */
if(!s->budget--) { s->failed_pc=0x0c054210u; return 0; }
r[0]&=r[1];
goto P_0c054212;
P_0c054212: /* original 0009, guest PC 0x0c054212 */
if(!s->budget--) { s->failed_pc=0x0c054212u; return 0; }
goto P_0c054214;
P_0c054214: /* original 423d, guest PC 0x0c054214 */
if(!s->budget--) { s->failed_pc=0x0c054214u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c054216;
P_0c054216: /* original 2420, guest PC 0x0c054216 */
if(!s->budget--) { s->failed_pc=0x0c054216u; return 0; }
write(ram,r[4],r[2],1);
goto P_0c054218;
P_0c054218: /* original 6340, guest PC 0x0c054218 */
if(!s->budget--) { s->failed_pc=0x0c054218u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c05421a;
P_0c05421a: /* original 237b, guest PC 0x0c05421a */
if(!s->budget--) { s->failed_pc=0x0c05421au; return 0; }
r[3]|=r[7];
goto P_0c05421c;
P_0c05421c: /* original 2430, guest PC 0x0c05421c */
if(!s->budget--) { s->failed_pc=0x0c05421cu; return 0; }
write(ram,r[4],r[3],1);
goto P_0c05421e;
P_0c05421e: /* original 670c, guest PC 0x0c05421e */
if(!s->budget--) { s->failed_pc=0x0c05421eu; return 0; }
r[7]=r[0]&255u;
goto P_0c054220;
P_0c054220: /* original 63eb, guest PC 0x0c054220 */
if(!s->budget--) { s->failed_pc=0x0c054220u; return 0; }
r[3]=0u-r[14];
goto P_0c054222;
P_0c054222: /* original 0009, guest PC 0x0c054222 */
if(!s->budget--) { s->failed_pc=0x0c054222u; return 0; }
goto P_0c054224;
P_0c054224: /* original 473d, guest PC 0x0c054224 */
if(!s->budget--) { s->failed_pc=0x0c054224u; return 0; }
r[7]=(r[3]&0x80000000u)?((r[3]&31u)?r[7]>>((-r[3])&31u):0):r[7]<<(r[3]&31u);
goto P_0c054226;
P_0c054226: /* original 75ff, guest PC 0x0c054226 */
if(!s->budget--) { s->failed_pc=0x0c054226u; return 0; }
r[5]+=0xffffffffu;
goto P_0c054228;
P_0c054228: /* original 4511, guest PC 0x0c054228 */
if(!s->budget--) { s->failed_pc=0x0c054228u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c05422a;
P_0c05422a: /* original 8dee, guest PC 0x0c05422a */
if(!s->budget--) { s->failed_pc=0x0c05422au; return 0; }
cond=r[17]&1u;
r[4]+=0xffffffffu;
if(cond) { goto P_0c05420a; }
goto P_0c05422e;
P_0c05422c: /* original 74ff, guest PC 0x0c05422c */
if(!s->budget--) { s->failed_pc=0x0c05422cu; return 0; }
r[4]+=0xffffffffu;
goto P_0c05422e;
P_0c05422e: /* original 677c, guest PC 0x0c05422e */
if(!s->budget--) { s->failed_pc=0x0c05422eu; return 0; }
r[7]=r[7]&255u;
goto P_0c054230;
P_0c054230: /* original 2778, guest PC 0x0c054230 */
if(!s->budget--) { s->failed_pc=0x0c054230u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c054232;
P_0c054232: /* original 8d03, guest PC 0x0c054232 */
if(!s->budget--) { s->failed_pc=0x0c054232u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05423c; }
goto P_0c054236;
P_0c054234: /* original 0009, guest PC 0x0c054234 */
if(!s->budget--) { s->failed_pc=0x0c054234u; return 0; }
goto P_0c054236;
P_0c054236: /* original e001, guest PC 0x0c054236 */
if(!s->budget--) { s->failed_pc=0x0c054236u; return 0; }
r[0]=0x00000001u;
goto P_0c054238;
P_0c054238: /* original 000b, guest PC 0x0c054238 */
if(!s->budget--) { s->failed_pc=0x0c054238u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05423a: /* original 6ef6, guest PC 0x0c05423a */
if(!s->budget--) { s->failed_pc=0x0c05423au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c05423c;
P_0c05423c: /* original e000, guest PC 0x0c05423c */
if(!s->budget--) { s->failed_pc=0x0c05423cu; return 0; }
r[0]=0x00000000u;
goto P_0c05423e;
P_0c05423e: /* original 000b, guest PC 0x0c05423e */
if(!s->budget--) { s->failed_pc=0x0c05423eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c054240: /* original 6ef6, guest PC 0x0c054240 */
if(!s->budget--) { s->failed_pc=0x0c054240u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c054242u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c054242u; return 0; } return 1;
P_0c054244: /* original d306, guest PC 0x0c054244 */
if(!s->budget--) { s->failed_pc=0x0c054244u; return 0; }
r[3]=read(ram,0x0c054260u,4);
goto P_0c054246;
P_0c054246: /* original 7ff8, guest PC 0x0c054246 */
if(!s->budget--) { s->failed_pc=0x0c054246u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c054248;
P_0c054248: /* original d206, guest PC 0x0c054248 */
if(!s->budget--) { s->failed_pc=0x0c054248u; return 0; }
r[2]=read(ram,0x0c054264u,4);
goto P_0c05424a;
P_0c05424a: /* original e608, guest PC 0x0c05424a */
if(!s->budget--) { s->failed_pc=0x0c05424au; return 0; }
r[6]=0x00000008u;
goto P_0c05424c;
P_0c05424c: /* original 1f41, guest PC 0x0c05424c */
if(!s->budget--) { s->failed_pc=0x0c05424cu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c05424e;
P_0c05424e: /* original 2f52, guest PC 0x0c05424e */
if(!s->budget--) { s->failed_pc=0x0c05424eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c054250;
P_0c054250: /* original 55f1, guest PC 0x0c054250 */
if(!s->budget--) { s->failed_pc=0x0c054250u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c054252;
P_0c054252: /* original 4508, guest PC 0x0c054252 */
if(!s->budget--) { s->failed_pc=0x0c054252u; return 0; }
r[5]<<=2;
goto P_0c054254;
P_0c054254: /* original 64f2, guest PC 0x0c054254 */
if(!s->budget--) { s->failed_pc=0x0c054254u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c054256;
P_0c054256: /* original 4500, guest PC 0x0c054256 */
if(!s->budget--) { s->failed_pc=0x0c054256u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c054258;
P_0c054258: /* original 353c, guest PC 0x0c054258 */
if(!s->budget--) { s->failed_pc=0x0c054258u; return 0; }
r[5]+=r[3];
goto P_0c05425a;
P_0c05425a: /* original 422b, guest PC 0x0c05425a */
if(!s->budget--) { s->failed_pc=0x0c05425au; return 0; }
target=r[2];
r[15]+=0x00000008u;
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
P_0c05425c: /* original 7f08, guest PC 0x0c05425c */
if(!s->budget--) { s->failed_pc=0x0c05425cu; return 0; }
r[15]+=0x00000008u;
if(!vf3_matrix_family(0x0c05425eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05425eu; return 0; } return 1;
P_0c054268: /* original 2fe6, guest PC 0x0c054268 */
if(!s->budget--) { s->failed_pc=0x0c054268u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05426a;
P_0c05426a: /* original e708, guest PC 0x0c05426a */
if(!s->budget--) { s->failed_pc=0x0c05426au; return 0; }
r[7]=0x00000008u;
goto P_0c05426c;
P_0c05426c: /* original 2fd6, guest PC 0x0c05426c */
if(!s->budget--) { s->failed_pc=0x0c05426cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05426e;
P_0c05426e: /* original 3768, guest PC 0x0c05426e */
if(!s->budget--) { s->failed_pc=0x0c05426eu; return 0; }
r[7]-=r[6];
goto P_0c054270;
P_0c054270: /* original 2fc6, guest PC 0x0c054270 */
if(!s->budget--) { s->failed_pc=0x0c054270u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054272;
P_0c054272: /* original 6d7f, guest PC 0x0c054272 */
if(!s->budget--) { s->failed_pc=0x0c054272u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c054274;
P_0c054274: /* original 2dd8, guest PC 0x0c054274 */
if(!s->budget--) { s->failed_pc=0x0c054274u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c054276;
P_0c054276: /* original 8d22, guest PC 0x0c054276 */
if(!s->budget--) { s->failed_pc=0x0c054276u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0542be; }
goto P_0c05427a;
P_0c054278: /* original 0009, guest PC 0x0c054278 */
if(!s->budget--) { s->failed_pc=0x0c054278u; return 0; }
goto P_0c05427a;
P_0c05427a: /* original 63db, guest PC 0x0c05427a */
if(!s->budget--) { s->failed_pc=0x0c05427au; return 0; }
r[3]=0u-r[13];
goto P_0c05427c;
P_0c05427c: /* original 9c23, guest PC 0x0c05427c */
if(!s->budget--) { s->failed_pc=0x0c05427cu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0542c6u,2);
goto P_0c05427e;
P_0c05427e: /* original 0009, guest PC 0x0c05427e */
if(!s->budget--) { s->failed_pc=0x0c05427eu; return 0; }
goto P_0c054280;
P_0c054280: /* original 4c3c, guest PC 0x0c054280 */
if(!s->budget--) { s->failed_pc=0x0c054280u; return 0; }
r[12]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[12]>>((-r[3])&31u)):((int32_t)r[12]<0?0xffffffffu:0)):r[12]<<(r[3]&31u);
goto P_0c054282;
P_0c054282: /* original e700, guest PC 0x0c054282 */
if(!s->budget--) { s->failed_pc=0x0c054282u; return 0; }
r[7]=0x00000000u;
goto P_0c054284;
P_0c054284: /* original 4515, guest PC 0x0c054284 */
if(!s->budget--) { s->failed_pc=0x0c054284u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c054286;
P_0c054286: /* original 8f13, guest PC 0x0c054286 */
if(!s->budget--) { s->failed_pc=0x0c054286u; return 0; }
cond=r[17]&1u;
r[14]=r[7];
if(!cond) { goto P_0c0542b0; }
goto P_0c05428a;
P_0c054288: /* original 6e73, guest PC 0x0c054288 */
if(!s->budget--) { s->failed_pc=0x0c054288u; return 0; }
r[14]=r[7];
goto P_0c05428a;
P_0c05428a: /* original 636f, guest PC 0x0c05428a */
if(!s->budget--) { s->failed_pc=0x0c05428au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c05428c;
P_0c05428c: /* original 6240, guest PC 0x0c05428c */
if(!s->budget--) { s->failed_pc=0x0c05428cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c05428e;
P_0c05428e: /* original 633b, guest PC 0x0c05428e */
if(!s->budget--) { s->failed_pc=0x0c05428eu; return 0; }
r[3]=0u-r[3];
goto P_0c054290;
P_0c054290: /* original 6040, guest PC 0x0c054290 */
if(!s->budget--) { s->failed_pc=0x0c054290u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
goto P_0c054292;
P_0c054292: /* original 622c, guest PC 0x0c054292 */
if(!s->budget--) { s->failed_pc=0x0c054292u; return 0; }
r[2]=r[2]&255u;
goto P_0c054294;
P_0c054294: /* original 20c9, guest PC 0x0c054294 */
if(!s->budget--) { s->failed_pc=0x0c054294u; return 0; }
r[0]&=r[12];
goto P_0c054296;
P_0c054296: /* original 0009, guest PC 0x0c054296 */
if(!s->budget--) { s->failed_pc=0x0c054296u; return 0; }
goto P_0c054298;
P_0c054298: /* original 423d, guest PC 0x0c054298 */
if(!s->budget--) { s->failed_pc=0x0c054298u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c05429a;
P_0c05429a: /* original 2420, guest PC 0x0c05429a */
if(!s->budget--) { s->failed_pc=0x0c05429au; return 0; }
write(ram,r[4],r[2],1);
goto P_0c05429c;
P_0c05429c: /* original 6140, guest PC 0x0c05429c */
if(!s->budget--) { s->failed_pc=0x0c05429cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[1]=tmp;
goto P_0c05429e;
P_0c05429e: /* original 217b, guest PC 0x0c05429e */
if(!s->budget--) { s->failed_pc=0x0c05429eu; return 0; }
r[1]|=r[7];
goto P_0c0542a0;
P_0c0542a0: /* original 2410, guest PC 0x0c0542a0 */
if(!s->budget--) { s->failed_pc=0x0c0542a0u; return 0; }
write(ram,r[4],r[1],1);
goto P_0c0542a2;
P_0c0542a2: /* original 670c, guest PC 0x0c0542a2 */
if(!s->budget--) { s->failed_pc=0x0c0542a2u; return 0; }
r[7]=r[0]&255u;
goto P_0c0542a4;
P_0c0542a4: /* original 0009, guest PC 0x0c0542a4 */
if(!s->budget--) { s->failed_pc=0x0c0542a4u; return 0; }
goto P_0c0542a6;
P_0c0542a6: /* original 47dd, guest PC 0x0c0542a6 */
if(!s->budget--) { s->failed_pc=0x0c0542a6u; return 0; }
r[7]=(r[13]&0x80000000u)?((r[13]&31u)?r[7]>>((-r[13])&31u):0):r[7]<<(r[13]&31u);
goto P_0c0542a8;
P_0c0542a8: /* original 7e01, guest PC 0x0c0542a8 */
if(!s->budget--) { s->failed_pc=0x0c0542a8u; return 0; }
r[14]+=0x00000001u;
goto P_0c0542aa;
P_0c0542aa: /* original 3e53, guest PC 0x0c0542aa */
if(!s->budget--) { s->failed_pc=0x0c0542aau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[5])!=0);
goto P_0c0542ac;
P_0c0542ac: /* original 8fed, guest PC 0x0c0542ac */
if(!s->budget--) { s->failed_pc=0x0c0542acu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c05428a; }
goto P_0c0542b0;
P_0c0542ae: /* original 7401, guest PC 0x0c0542ae */
if(!s->budget--) { s->failed_pc=0x0c0542aeu; return 0; }
r[4]+=0x00000001u;
goto P_0c0542b0;
P_0c0542b0: /* original 677c, guest PC 0x0c0542b0 */
if(!s->budget--) { s->failed_pc=0x0c0542b0u; return 0; }
r[7]=r[7]&255u;
goto P_0c0542b2;
P_0c0542b2: /* original 2778, guest PC 0x0c0542b2 */
if(!s->budget--) { s->failed_pc=0x0c0542b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0542b4;
P_0c0542b4: /* original 8d02, guest PC 0x0c0542b4 */
if(!s->budget--) { s->failed_pc=0x0c0542b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0542bc; }
goto P_0c0542b8;
P_0c0542b6: /* original 0009, guest PC 0x0c0542b6 */
if(!s->budget--) { s->failed_pc=0x0c0542b6u; return 0; }
goto P_0c0542b8;
P_0c0542b8: /* original a001, guest PC 0x0c0542b8 */
if(!s->budget--) { s->failed_pc=0x0c0542b8u; return 0; }
r[0]=0x00000001u;
goto P_0c0542be;
P_0c0542ba: /* original e001, guest PC 0x0c0542ba */
if(!s->budget--) { s->failed_pc=0x0c0542bau; return 0; }
r[0]=0x00000001u;
goto P_0c0542bc;
P_0c0542bc: /* original e000, guest PC 0x0c0542bc */
if(!s->budget--) { s->failed_pc=0x0c0542bcu; return 0; }
r[0]=0x00000000u;
goto P_0c0542be;
P_0c0542be: /* original 6cf6, guest PC 0x0c0542be */
if(!s->budget--) { s->failed_pc=0x0c0542beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0542c0;
P_0c0542c0: /* original 6df6, guest PC 0x0c0542c0 */
if(!s->budget--) { s->failed_pc=0x0c0542c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0542c2;
P_0c0542c2: /* original 000b, guest PC 0x0c0542c2 */
if(!s->budget--) { s->failed_pc=0x0c0542c2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0542c4: /* original 6ef6, guest PC 0x0c0542c4 */
if(!s->budget--) { s->failed_pc=0x0c0542c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0542c6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0542c6u; return 0; } return 1;
P_0c0542c8: /* original 2fe6, guest PC 0x0c0542c8 */
if(!s->budget--) { s->failed_pc=0x0c0542c8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0542ca;
P_0c0542ca: /* original 77ff, guest PC 0x0c0542ca */
if(!s->budget--) { s->failed_pc=0x0c0542cau; return 0; }
r[7]+=0xffffffffu;
goto P_0c0542cc;
P_0c0542cc: /* original 2fd6, guest PC 0x0c0542cc */
if(!s->budget--) { s->failed_pc=0x0c0542ccu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0542ce;
P_0c0542ce: /* original ee00, guest PC 0x0c0542ce */
if(!s->budget--) { s->failed_pc=0x0c0542ceu; return 0; }
r[14]=0x00000000u;
goto P_0c0542d0;
P_0c0542d0: /* original 7ff8, guest PC 0x0c0542d0 */
if(!s->budget--) { s->failed_pc=0x0c0542d0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0542d2;
P_0c0542d2: /* original ed01, guest PC 0x0c0542d2 */
if(!s->budget--) { s->failed_pc=0x0c0542d2u; return 0; }
r[13]=0x00000001u;
goto P_0c0542d4;
P_0c0542d4: /* original 6173, guest PC 0x0c0542d4 */
if(!s->budget--) { s->failed_pc=0x0c0542d4u; return 0; }
r[1]=r[7];
goto P_0c0542d6;
P_0c0542d6: /* original 315c, guest PC 0x0c0542d6 */
if(!s->budget--) { s->failed_pc=0x0c0542d6u; return 0; }
r[1]+=r[5];
goto P_0c0542d8;
P_0c0542d8: /* original 1f11, guest PC 0x0c0542d8 */
if(!s->budget--) { s->failed_pc=0x0c0542d8u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0542da;
P_0c0542da: /* original 367c, guest PC 0x0c0542da */
if(!s->budget--) { s->failed_pc=0x0c0542dau; return 0; }
r[6]+=r[7];
goto P_0c0542dc;
P_0c0542dc: /* original 7101, guest PC 0x0c0542dc */
if(!s->budget--) { s->failed_pc=0x0c0542dcu; return 0; }
r[1]+=0x00000001u;
goto P_0c0542de;
P_0c0542de: /* original 4711, guest PC 0x0c0542de */
if(!s->budget--) { s->failed_pc=0x0c0542deu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=0)!=0);
goto P_0c0542e0;
P_0c0542e0: /* original 8f1b, guest PC 0x0c0542e0 */
if(!s->budget--) { s->failed_pc=0x0c0542e0u; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[15]+4,4);
if(!cond) { goto P_0c05431a; }
goto P_0c0542e4;
P_0c0542e2: /* original 55f1, guest PC 0x0c0542e2 */
if(!s->budget--) { s->failed_pc=0x0c0542e2u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0542e4;
P_0c0542e4: /* original 6250, guest PC 0x0c0542e4 */
if(!s->budget--) { s->failed_pc=0x0c0542e4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[2]=tmp;
goto P_0c0542e6;
P_0c0542e6: /* original 622c, guest PC 0x0c0542e6 */
if(!s->budget--) { s->failed_pc=0x0c0542e6u; return 0; }
r[2]=r[2]&255u;
goto P_0c0542e8;
P_0c0542e8: /* original 6360, guest PC 0x0c0542e8 */
if(!s->budget--) { s->failed_pc=0x0c0542e8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[3]=tmp;
goto P_0c0542ea;
P_0c0542ea: /* original 633c, guest PC 0x0c0542ea */
if(!s->budget--) { s->failed_pc=0x0c0542eau; return 0; }
r[3]=r[3]&255u;
goto P_0c0542ec;
P_0c0542ec: /* original 3238, guest PC 0x0c0542ec */
if(!s->budget--) { s->failed_pc=0x0c0542ecu; return 0; }
r[2]-=r[3];
goto P_0c0542ee;
P_0c0542ee: /* original 32e8, guest PC 0x0c0542ee */
if(!s->budget--) { s->failed_pc=0x0c0542eeu; return 0; }
r[2]-=r[14];
goto P_0c0542f0;
P_0c0542f0: /* original 4211, guest PC 0x0c0542f0 */
if(!s->budget--) { s->failed_pc=0x0c0542f0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c0542f2;
P_0c0542f2: /* original 8d05, guest PC 0x0c0542f2 */
if(!s->budget--) { s->failed_pc=0x0c0542f2u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[2],4);
if(cond) { goto P_0c054300; }
goto P_0c0542f6;
P_0c0542f4: /* original 2f22, guest PC 0x0c0542f4 */
if(!s->budget--) { s->failed_pc=0x0c0542f4u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0542f6;
P_0c0542f6: /* original 9e26, guest PC 0x0c0542f6 */
if(!s->budget--) { s->failed_pc=0x0c0542f6u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c054346u,2);
goto P_0c0542f8;
P_0c0542f8: /* original 3e2c, guest PC 0x0c0542f8 */
if(!s->budget--) { s->failed_pc=0x0c0542f8u; return 0; }
r[14]+=r[2];
goto P_0c0542fa;
P_0c0542fa: /* original 2fe2, guest PC 0x0c0542fa */
if(!s->budget--) { s->failed_pc=0x0c0542fau; return 0; }
write(ram,r[15],r[14],4);
goto P_0c0542fc;
P_0c0542fc: /* original a001, guest PC 0x0c0542fc */
if(!s->budget--) { s->failed_pc=0x0c0542fcu; return 0; }
r[14]=0x00000001u;
goto P_0c054302;
P_0c0542fe: /* original ee01, guest PC 0x0c0542fe */
if(!s->budget--) { s->failed_pc=0x0c0542feu; return 0; }
r[14]=0x00000001u;
goto P_0c054300;
P_0c054300: /* original ee00, guest PC 0x0c054300 */
if(!s->budget--) { s->failed_pc=0x0c054300u; return 0; }
r[14]=0x00000000u;
goto P_0c054302;
P_0c054302: /* original 62f2, guest PC 0x0c054302 */
if(!s->budget--) { s->failed_pc=0x0c054302u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c054304;
P_0c054304: /* original 2228, guest PC 0x0c054304 */
if(!s->budget--) { s->failed_pc=0x0c054304u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c054306;
P_0c054306: /* original 8d01, guest PC 0x0c054306 */
if(!s->budget--) { s->failed_pc=0x0c054306u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05430c; }
goto P_0c05430a;
P_0c054308: /* original 0009, guest PC 0x0c054308 */
if(!s->budget--) { s->failed_pc=0x0c054308u; return 0; }
goto P_0c05430a;
P_0c05430a: /* original ed00, guest PC 0x0c05430a */
if(!s->budget--) { s->failed_pc=0x0c05430au; return 0; }
r[13]=0x00000000u;
goto P_0c05430c;
P_0c05430c: /* original 63f2, guest PC 0x0c05430c */
if(!s->budget--) { s->failed_pc=0x0c05430cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c05430e;
P_0c05430e: /* original 77ff, guest PC 0x0c05430e */
if(!s->budget--) { s->failed_pc=0x0c05430eu; return 0; }
r[7]+=0xffffffffu;
goto P_0c054310;
P_0c054310: /* original 2134, guest PC 0x0c054310 */
if(!s->budget--) { s->failed_pc=0x0c054310u; return 0; }
tmp=r[3]; r[1]-=1; write(ram,r[1],tmp,1);
goto P_0c054312;
P_0c054312: /* original 76ff, guest PC 0x0c054312 */
if(!s->budget--) { s->failed_pc=0x0c054312u; return 0; }
r[6]+=0xffffffffu;
goto P_0c054314;
P_0c054314: /* original 4711, guest PC 0x0c054314 */
if(!s->budget--) { s->failed_pc=0x0c054314u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=0)!=0);
goto P_0c054316;
P_0c054316: /* original 8de5, guest PC 0x0c054316 */
if(!s->budget--) { s->failed_pc=0x0c054316u; return 0; }
cond=r[17]&1u;
r[5]+=0xffffffffu;
if(cond) { goto P_0c0542e4; }
goto P_0c05431a;
P_0c054318: /* original 75ff, guest PC 0x0c054318 */
if(!s->budget--) { s->failed_pc=0x0c054318u; return 0; }
r[5]+=0xffffffffu;
goto P_0c05431a;
P_0c05431a: /* original 60e3, guest PC 0x0c05431a */
if(!s->budget--) { s->failed_pc=0x0c05431au; return 0; }
r[0]=r[14];
goto P_0c05431c;
P_0c05431c: /* original 0009, guest PC 0x0c05431c */
if(!s->budget--) { s->failed_pc=0x0c05431cu; return 0; }
goto P_0c05431e;
P_0c05431e: /* original 8801, guest PC 0x0c05431e */
if(!s->budget--) { s->failed_pc=0x0c05431eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c054320;
P_0c054320: /* original 8f05, guest PC 0x0c054320 */
if(!s->budget--) { s->failed_pc=0x0c054320u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05432e; }
goto P_0c054324;
P_0c054322: /* original 0009, guest PC 0x0c054322 */
if(!s->budget--) { s->failed_pc=0x0c054322u; return 0; }
goto P_0c054324;
P_0c054324: /* original 2448, guest PC 0x0c054324 */
if(!s->budget--) { s->failed_pc=0x0c054324u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c054326;
P_0c054326: /* original 8f02, guest PC 0x0c054326 */
if(!s->budget--) { s->failed_pc=0x0c054326u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05432e; }
goto P_0c05432a;
P_0c054328: /* original 0009, guest PC 0x0c054328 */
if(!s->budget--) { s->failed_pc=0x0c054328u; return 0; }
goto P_0c05432a;
P_0c05432a: /* original a008, guest PC 0x0c05432a */
if(!s->budget--) { s->failed_pc=0x0c05432au; return 0; }
r[0]=0xffffffffu;
goto P_0c05433e;
P_0c05432c: /* original e0ff, guest PC 0x0c05432c */
if(!s->budget--) { s->failed_pc=0x0c05432cu; return 0; }
r[0]=0xffffffffu;
goto P_0c05432e;
P_0c05432e: /* original 60d3, guest PC 0x0c05432e */
if(!s->budget--) { s->failed_pc=0x0c05432eu; return 0; }
r[0]=r[13];
goto P_0c054330;
P_0c054330: /* original 0009, guest PC 0x0c054330 */
if(!s->budget--) { s->failed_pc=0x0c054330u; return 0; }
goto P_0c054332;
P_0c054332: /* original 8801, guest PC 0x0c054332 */
if(!s->budget--) { s->failed_pc=0x0c054332u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c054334;
P_0c054334: /* original 8f02, guest PC 0x0c054334 */
if(!s->budget--) { s->failed_pc=0x0c054334u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05433c; }
goto P_0c054338;
P_0c054336: /* original 0009, guest PC 0x0c054336 */
if(!s->budget--) { s->failed_pc=0x0c054336u; return 0; }
goto P_0c054338;
P_0c054338: /* original a001, guest PC 0x0c054338 */
if(!s->budget--) { s->failed_pc=0x0c054338u; return 0; }
r[0]=0x00000000u;
goto P_0c05433e;
P_0c05433a: /* original e000, guest PC 0x0c05433a */
if(!s->budget--) { s->failed_pc=0x0c05433au; return 0; }
r[0]=0x00000000u;
goto P_0c05433c;
P_0c05433c: /* original e001, guest PC 0x0c05433c */
if(!s->budget--) { s->failed_pc=0x0c05433cu; return 0; }
r[0]=0x00000001u;
goto P_0c05433e;
P_0c05433e: /* original 7f08, guest PC 0x0c05433e */
if(!s->budget--) { s->failed_pc=0x0c05433eu; return 0; }
r[15]+=0x00000008u;
goto P_0c054340;
P_0c054340: /* original 6df6, guest PC 0x0c054340 */
if(!s->budget--) { s->failed_pc=0x0c054340u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c054342;
P_0c054342: /* original 000b, guest PC 0x0c054342 */
if(!s->budget--) { s->failed_pc=0x0c054342u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c054344: /* original 6ef6, guest PC 0x0c054344 */
if(!s->budget--) { s->failed_pc=0x0c054344u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c054346u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c054346u; return 0; } return 1;
P_0c054384: /* original 2fe6, guest PC 0x0c054384 */
if(!s->budget--) { s->failed_pc=0x0c054384u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054386;
P_0c054386: /* original 2fd6, guest PC 0x0c054386 */
if(!s->budget--) { s->failed_pc=0x0c054386u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054388;
P_0c054388: /* original 2fc6, guest PC 0x0c054388 */
if(!s->budget--) { s->failed_pc=0x0c054388u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05438a;
P_0c05438a: /* original 6d53, guest PC 0x0c05438a */
if(!s->budget--) { s->failed_pc=0x0c05438au; return 0; }
r[13]=r[5];
goto P_0c05438c;
P_0c05438c: /* original 2fb6, guest PC 0x0c05438c */
if(!s->budget--) { s->failed_pc=0x0c05438cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05438e;
P_0c05438e: /* original 4f22, guest PC 0x0c05438e */
if(!s->budget--) { s->failed_pc=0x0c05438eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c054390;
P_0c054390: /* original d52c, guest PC 0x0c054390 */
if(!s->budget--) { s->failed_pc=0x0c054390u; return 0; }
r[5]=read(ram,0x0c054444u,4);
goto P_0c054392;
P_0c054392: /* original 7ffc, guest PC 0x0c054392 */
if(!s->budget--) { s->failed_pc=0x0c054392u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c054394;
P_0c054394: /* original 6cf3, guest PC 0x0c054394 */
if(!s->budget--) { s->failed_pc=0x0c054394u; return 0; }
r[12]=r[15];
goto P_0c054396;
P_0c054396: /* original 7c18, guest PC 0x0c054396 */
if(!s->budget--) { s->failed_pc=0x0c054396u; return 0; }
r[12]+=0x00000018u;
goto P_0c054398;
P_0c054398: /* original 7c06, guest PC 0x0c054398 */
if(!s->budget--) { s->failed_pc=0x0c054398u; return 0; }
r[12]+=0x00000006u;
goto P_0c05439a;
P_0c05439a: /* original 62c1, guest PC 0x0c05439a */
if(!s->budget--) { s->failed_pc=0x0c05439au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[2]=tmp;
goto P_0c05439c;
P_0c05439c: /* original 622d, guest PC 0x0c05439c */
if(!s->budget--) { s->failed_pc=0x0c05439cu; return 0; }
r[2]=r[2]&65535u;
goto P_0c05439e;
P_0c05439e: /* original 2259, guest PC 0x0c05439e */
if(!s->budget--) { s->failed_pc=0x0c05439eu; return 0; }
r[2]&=r[5];
goto P_0c0543a0;
P_0c0543a0: /* original 3250, guest PC 0x0c0543a0 */
if(!s->budget--) { s->failed_pc=0x0c0543a0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[5])!=0);
goto P_0c0543a2;
P_0c0543a2: /* original 8f02, guest PC 0x0c0543a2 */
if(!s->budget--) { s->failed_pc=0x0c0543a2u; return 0; }
cond=r[17]&1u;
r[14]=r[6];
if(!cond) { goto P_0c0543aa; }
goto P_0c0543a6;
P_0c0543a4: /* original 6e63, guest PC 0x0c0543a4 */
if(!s->budget--) { s->failed_pc=0x0c0543a4u; return 0; }
r[14]=r[6];
goto P_0c0543a6;
P_0c0543a6: /* original a001, guest PC 0x0c0543a6 */
if(!s->budget--) { s->failed_pc=0x0c0543a6u; return 0; }
r[3]=0xffffffffu;
goto P_0c0543ac;
P_0c0543a8: /* original e3ff, guest PC 0x0c0543a8 */
if(!s->budget--) { s->failed_pc=0x0c0543a8u; return 0; }
r[3]=0xffffffffu;
goto P_0c0543aa;
P_0c0543aa: /* original e301, guest PC 0x0c0543aa */
if(!s->budget--) { s->failed_pc=0x0c0543aau; return 0; }
r[3]=0x00000001u;
goto P_0c0543ac;
P_0c0543ac: /* original 2430, guest PC 0x0c0543ac */
if(!s->budget--) { s->failed_pc=0x0c0543acu; return 0; }
write(ram,r[4],r[3],1);
goto P_0c0543ae;
P_0c0543ae: /* original 61c1, guest PC 0x0c0543ae */
if(!s->budget--) { s->failed_pc=0x0c0543aeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[1]=tmp;
goto P_0c0543b0;
P_0c0543b0: /* original 9245, guest PC 0x0c0543b0 */
if(!s->budget--) { s->failed_pc=0x0c0543b0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05443eu,2);
goto P_0c0543b2;
P_0c0543b2: /* original 2d11, guest PC 0x0c0543b2 */
if(!s->budget--) { s->failed_pc=0x0c0543b2u; return 0; }
write(ram,r[13],r[1],2);
goto P_0c0543b4;
P_0c0543b4: /* original 63d1, guest PC 0x0c0543b4 */
if(!s->budget--) { s->failed_pc=0x0c0543b4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[3]=tmp;
goto P_0c0543b6;
P_0c0543b6: /* original e1fc, guest PC 0x0c0543b6 */
if(!s->budget--) { s->failed_pc=0x0c0543b6u; return 0; }
r[1]=0xfffffffcu;
goto P_0c0543b8;
P_0c0543b8: /* original 2329, guest PC 0x0c0543b8 */
if(!s->budget--) { s->failed_pc=0x0c0543b8u; return 0; }
r[3]&=r[2];
goto P_0c0543ba;
P_0c0543ba: /* original 0009, guest PC 0x0c0543ba */
if(!s->budget--) { s->failed_pc=0x0c0543bau; return 0; }
goto P_0c0543bc;
P_0c0543bc: /* original 431c, guest PC 0x0c0543bc */
if(!s->budget--) { s->failed_pc=0x0c0543bcu; return 0; }
r[3]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[3]>>((-r[1])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[1]&31u);
goto P_0c0543be;
P_0c0543be: /* original 6bf3, guest PC 0x0c0543be */
if(!s->budget--) { s->failed_pc=0x0c0543beu; return 0; }
r[11]=r[15];
goto P_0c0543c0;
P_0c0543c0: /* original 2d31, guest PC 0x0c0543c0 */
if(!s->budget--) { s->failed_pc=0x0c0543c0u; return 0; }
write(ram,r[13],r[3],2);
goto P_0c0543c2;
P_0c0543c2: /* original 65c3, guest PC 0x0c0543c2 */
if(!s->budget--) { s->failed_pc=0x0c0543c2u; return 0; }
r[5]=r[12];
goto P_0c0543c4;
P_0c0543c4: /* original d320, guest PC 0x0c0543c4 */
if(!s->budget--) { s->failed_pc=0x0c0543c4u; return 0; }
r[3]=read(ram,0x0c054448u,4);
goto P_0c0543c6;
P_0c0543c6: /* original 75fe, guest PC 0x0c0543c6 */
if(!s->budget--) { s->failed_pc=0x0c0543c6u; return 0; }
r[5]+=0xfffffffeu;
goto P_0c0543c8;
P_0c0543c8: /* original 430b, guest PC 0x0c0543c8 */
if(!s->budget--) { s->failed_pc=0x0c0543c8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0543ccu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0543ccu) { target=s->pc; goto dispatch; }
goto P_0c0543cc;
P_0c0543ca: /* original 64b3, guest PC 0x0c0543ca */
if(!s->budget--) { s->failed_pc=0x0c0543cau; return 0; }
r[4]=r[11];
goto P_0c0543cc;
P_0c0543cc: /* original d21f, guest PC 0x0c0543cc */
if(!s->budget--) { s->failed_pc=0x0c0543ccu; return 0; }
r[2]=read(ram,0x0c05444cu,4);
goto P_0c0543ce;
P_0c0543ce: /* original e603, guest PC 0x0c0543ce */
if(!s->budget--) { s->failed_pc=0x0c0543ceu; return 0; }
r[6]=0x00000003u;
goto P_0c0543d0;
P_0c0543d0: /* original 65b3, guest PC 0x0c0543d0 */
if(!s->budget--) { s->failed_pc=0x0c0543d0u; return 0; }
r[5]=r[11];
goto P_0c0543d2;
P_0c0543d2: /* original 7501, guest PC 0x0c0543d2 */
if(!s->budget--) { s->failed_pc=0x0c0543d2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0543d4;
P_0c0543d4: /* original 420b, guest PC 0x0c0543d4 */
if(!s->budget--) { s->failed_pc=0x0c0543d4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0543d8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0543d8u) { target=s->pc; goto dispatch; }
goto P_0c0543d8;
P_0c0543d6: /* original 64e3, guest PC 0x0c0543d6 */
if(!s->budget--) { s->failed_pc=0x0c0543d6u; return 0; }
r[4]=r[14];
goto P_0c0543d8;
P_0c0543d8: /* original d31b, guest PC 0x0c0543d8 */
if(!s->budget--) { s->failed_pc=0x0c0543d8u; return 0; }
r[3]=read(ram,0x0c054448u,4);
goto P_0c0543da;
P_0c0543da: /* original 65c3, guest PC 0x0c0543da */
if(!s->budget--) { s->failed_pc=0x0c0543dau; return 0; }
r[5]=r[12];
goto P_0c0543dc;
P_0c0543dc: /* original 75fa, guest PC 0x0c0543dc */
if(!s->budget--) { s->failed_pc=0x0c0543dcu; return 0; }
r[5]+=0xfffffffau;
goto P_0c0543de;
P_0c0543de: /* original 430b, guest PC 0x0c0543de */
if(!s->budget--) { s->failed_pc=0x0c0543deu; return 0; }
target=r[3];
r[16]=code_base|0x0c0543e2u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0543e2u) { target=s->pc; goto dispatch; }
goto P_0c0543e2;
P_0c0543e0: /* original 64b3, guest PC 0x0c0543e0 */
if(!s->budget--) { s->failed_pc=0x0c0543e0u; return 0; }
r[4]=r[11];
goto P_0c0543e2;
P_0c0543e2: /* original e604, guest PC 0x0c0543e2 */
if(!s->budget--) { s->failed_pc=0x0c0543e2u; return 0; }
r[6]=0x00000004u;
goto P_0c0543e4;
P_0c0543e4: /* original d219, guest PC 0x0c0543e4 */
if(!s->budget--) { s->failed_pc=0x0c0543e4u; return 0; }
r[2]=read(ram,0x0c05444cu,4);
goto P_0c0543e6;
P_0c0543e6: /* original 65b3, guest PC 0x0c0543e6 */
if(!s->budget--) { s->failed_pc=0x0c0543e6u; return 0; }
r[5]=r[11];
goto P_0c0543e8;
P_0c0543e8: /* original 64e3, guest PC 0x0c0543e8 */
if(!s->budget--) { s->failed_pc=0x0c0543e8u; return 0; }
r[4]=r[14];
goto P_0c0543ea;
P_0c0543ea: /* original 420b, guest PC 0x0c0543ea */
if(!s->budget--) { s->failed_pc=0x0c0543eau; return 0; }
target=r[2];
r[16]=code_base|0x0c0543eeu;
r[4]+=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0543eeu) { target=s->pc; goto dispatch; }
goto P_0c0543ee;
P_0c0543ec: /* original 7403, guest PC 0x0c0543ec */
if(!s->budget--) { s->failed_pc=0x0c0543ecu; return 0; }
r[4]+=0x00000003u;
goto P_0c0543ee;
P_0c0543ee: /* original e603, guest PC 0x0c0543ee */
if(!s->budget--) { s->failed_pc=0x0c0543eeu; return 0; }
r[6]=0x00000003u;
goto P_0c0543f0;
P_0c0543f0: /* original dc17, guest PC 0x0c0543f0 */
if(!s->budget--) { s->failed_pc=0x0c0543f0u; return 0; }
r[12]=read(ram,0x0c054450u,4);
goto P_0c0543f2;
P_0c0543f2: /* original e507, guest PC 0x0c0543f2 */
if(!s->budget--) { s->failed_pc=0x0c0543f2u; return 0; }
r[5]=0x00000007u;
goto P_0c0543f4;
P_0c0543f4: /* original 4c0b, guest PC 0x0c0543f4 */
if(!s->budget--) { s->failed_pc=0x0c0543f4u; return 0; }
target=r[12];
r[16]=code_base|0x0c0543f8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0543f8u) { target=s->pc; goto dispatch; }
goto P_0c0543f8;
P_0c0543f6: /* original 64e3, guest PC 0x0c0543f6 */
if(!s->budget--) { s->failed_pc=0x0c0543f6u; return 0; }
r[4]=r[14];
goto P_0c0543f8;
P_0c0543f8: /* original 63d1, guest PC 0x0c0543f8 */
if(!s->budget--) { s->failed_pc=0x0c0543f8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[3]=tmp;
goto P_0c0543fa;
P_0c0543fa: /* original 4315, guest PC 0x0c0543fa */
if(!s->budget--) { s->failed_pc=0x0c0543fau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c0543fc;
P_0c0543fc: /* original 8f04, guest PC 0x0c0543fc */
if(!s->budget--) { s->failed_pc=0x0c0543fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054408; }
goto P_0c054400;
P_0c0543fe: /* original 0009, guest PC 0x0c0543fe */
if(!s->budget--) { s->failed_pc=0x0c0543feu; return 0; }
goto P_0c054400;
P_0c054400: /* original 60e0, guest PC 0x0c054400 */
if(!s->budget--) { s->failed_pc=0x0c054400u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[0]=tmp;
goto P_0c054402;
P_0c054402: /* original cb80, guest PC 0x0c054402 */
if(!s->budget--) { s->failed_pc=0x0c054402u; return 0; }
r[0]|=128u;
goto P_0c054404;
P_0c054404: /* original a014, guest PC 0x0c054404 */
if(!s->budget--) { s->failed_pc=0x0c054404u; return 0; }
write(ram,r[14],r[0],1);
goto P_0c054430;
P_0c054406: /* original 2e00, guest PC 0x0c054406 */
if(!s->budget--) { s->failed_pc=0x0c054406u; return 0; }
write(ram,r[14],r[0],1);
goto P_0c054408;
P_0c054408: /* original 62d1, guest PC 0x0c054408 */
if(!s->budget--) { s->failed_pc=0x0c054408u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[2]=tmp;
goto P_0c05440a;
P_0c05440a: /* original 7201, guest PC 0x0c05440a */
if(!s->budget--) { s->failed_pc=0x0c05440au; return 0; }
r[2]+=0x00000001u;
goto P_0c05440c;
P_0c05440c: /* original 2d21, guest PC 0x0c05440c */
if(!s->budget--) { s->failed_pc=0x0c05440cu; return 0; }
write(ram,r[13],r[2],2);
goto P_0c05440e;
P_0c05440e: /* original 60e0, guest PC 0x0c05440e */
if(!s->budget--) { s->failed_pc=0x0c05440eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[0]=tmp;
goto P_0c054410;
P_0c054410: /* original 9b16, guest PC 0x0c054410 */
if(!s->budget--) { s->failed_pc=0x0c054410u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c054440u,2);
goto P_0c054412;
P_0c054412: /* original c97f, guest PC 0x0c054412 */
if(!s->budget--) { s->failed_pc=0x0c054412u; return 0; }
r[0]&=127u;
goto P_0c054414;
P_0c054414: /* original a007, guest PC 0x0c054414 */
if(!s->budget--) { s->failed_pc=0x0c054414u; return 0; }
write(ram,r[14],r[0],1);
goto P_0c054426;
P_0c054416: /* original 2e00, guest PC 0x0c054416 */
if(!s->budget--) { s->failed_pc=0x0c054416u; return 0; }
write(ram,r[14],r[0],1);
goto P_0c054418;
P_0c054418: /* original e601, guest PC 0x0c054418 */
if(!s->budget--) { s->failed_pc=0x0c054418u; return 0; }
r[6]=0x00000001u;
goto P_0c05441a;
P_0c05441a: /* original e507, guest PC 0x0c05441a */
if(!s->budget--) { s->failed_pc=0x0c05441au; return 0; }
r[5]=0x00000007u;
goto P_0c05441c;
P_0c05441c: /* original 4c0b, guest PC 0x0c05441c */
if(!s->budget--) { s->failed_pc=0x0c05441cu; return 0; }
target=r[12];
r[16]=code_base|0x0c054420u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054420u) { target=s->pc; goto dispatch; }
goto P_0c054420;
P_0c05441e: /* original 64e3, guest PC 0x0c05441e */
if(!s->budget--) { s->failed_pc=0x0c05441eu; return 0; }
r[4]=r[14];
goto P_0c054420;
P_0c054420: /* original 62d1, guest PC 0x0c054420 */
if(!s->budget--) { s->failed_pc=0x0c054420u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[2]=tmp;
goto P_0c054422;
P_0c054422: /* original 72ff, guest PC 0x0c054422 */
if(!s->budget--) { s->failed_pc=0x0c054422u; return 0; }
r[2]+=0xffffffffu;
goto P_0c054424;
P_0c054424: /* original 2d21, guest PC 0x0c054424 */
if(!s->budget--) { s->failed_pc=0x0c054424u; return 0; }
write(ram,r[13],r[2],2);
goto P_0c054426;
P_0c054426: /* original 63e0, guest PC 0x0c054426 */
if(!s->budget--) { s->failed_pc=0x0c054426u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[3]=tmp;
goto P_0c054428;
P_0c054428: /* original 633c, guest PC 0x0c054428 */
if(!s->budget--) { s->failed_pc=0x0c054428u; return 0; }
r[3]=r[3]&255u;
goto P_0c05442a;
P_0c05442a: /* original 23b8, guest PC 0x0c05442a */
if(!s->budget--) { s->failed_pc=0x0c05442au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c05442c;
P_0c05442c: /* original 8df4, guest PC 0x0c05442c */
if(!s->budget--) { s->failed_pc=0x0c05442cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054418; }
goto P_0c054430;
P_0c05442e: /* original 0009, guest PC 0x0c05442e */
if(!s->budget--) { s->failed_pc=0x0c05442eu; return 0; }
goto P_0c054430;
P_0c054430: /* original 7f04, guest PC 0x0c054430 */
if(!s->budget--) { s->failed_pc=0x0c054430u; return 0; }
r[15]+=0x00000004u;
goto P_0c054432;
P_0c054432: /* original 4f26, guest PC 0x0c054432 */
if(!s->budget--) { s->failed_pc=0x0c054432u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c054434;
P_0c054434: /* original 6bf6, guest PC 0x0c054434 */
if(!s->budget--) { s->failed_pc=0x0c054434u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c054436;
P_0c054436: /* original 6cf6, guest PC 0x0c054436 */
if(!s->budget--) { s->failed_pc=0x0c054436u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c054438;
P_0c054438: /* original 6df6, guest PC 0x0c054438 */
if(!s->budget--) { s->failed_pc=0x0c054438u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05443a;
P_0c05443a: /* original 000b, guest PC 0x0c05443a */
if(!s->budget--) { s->failed_pc=0x0c05443au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05443c: /* original 6ef6, guest PC 0x0c05443c */
if(!s->budget--) { s->failed_pc=0x0c05443cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05443eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05443eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
