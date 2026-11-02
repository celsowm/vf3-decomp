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
int vf3_away_batch6_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0451f8u: goto P_0c0451f8;
case 0x0c0451fau: goto P_0c0451fa;
case 0x0c0451fcu: goto P_0c0451fc;
case 0x0c0451feu: goto P_0c0451fe;
case 0x0c045200u: goto P_0c045200;
case 0x0c045202u: goto P_0c045202;
case 0x0c045204u: goto P_0c045204;
case 0x0c045206u: goto P_0c045206;
case 0x0c045208u: goto P_0c045208;
case 0x0c04520au: goto P_0c04520a;
case 0x0c04520cu: goto P_0c04520c;
case 0x0c04520eu: goto P_0c04520e;
case 0x0c045210u: goto P_0c045210;
case 0x0c045212u: goto P_0c045212;
case 0x0c045214u: goto P_0c045214;
case 0x0c045216u: goto P_0c045216;
case 0x0c045218u: goto P_0c045218;
case 0x0c04521au: goto P_0c04521a;
case 0x0c04521cu: goto P_0c04521c;
case 0x0c04521eu: goto P_0c04521e;
case 0x0c045220u: goto P_0c045220;
case 0x0c045222u: goto P_0c045222;
case 0x0c045224u: goto P_0c045224;
case 0x0c045226u: goto P_0c045226;
case 0x0c045228u: goto P_0c045228;
case 0x0c04522au: goto P_0c04522a;
case 0x0c04522cu: goto P_0c04522c;
case 0x0c04522eu: goto P_0c04522e;
case 0x0c045230u: goto P_0c045230;
case 0x0c045232u: goto P_0c045232;
case 0x0c045234u: goto P_0c045234;
case 0x0c045236u: goto P_0c045236;
case 0x0c045238u: goto P_0c045238;
case 0x0c04523au: goto P_0c04523a;
case 0x0c04523cu: goto P_0c04523c;
case 0x0c04523eu: goto P_0c04523e;
case 0x0c045240u: goto P_0c045240;
case 0x0c045242u: goto P_0c045242;
case 0x0c045244u: goto P_0c045244;
case 0x0c045246u: goto P_0c045246;
case 0x0c045248u: goto P_0c045248;
case 0x0c04524au: goto P_0c04524a;
case 0x0c04524cu: goto P_0c04524c;
case 0x0c04524eu: goto P_0c04524e;
case 0x0c045250u: goto P_0c045250;
case 0x0c045252u: goto P_0c045252;
case 0x0c045254u: goto P_0c045254;
case 0x0c045256u: goto P_0c045256;
case 0x0c045258u: goto P_0c045258;
case 0x0c04525au: goto P_0c04525a;
case 0x0c04525cu: goto P_0c04525c;
case 0x0c04525eu: goto P_0c04525e;
case 0x0c045260u: goto P_0c045260;
case 0x0c045262u: goto P_0c045262;
case 0x0c045264u: goto P_0c045264;
case 0x0c045266u: goto P_0c045266;
case 0x0c045268u: goto P_0c045268;
case 0x0c04526au: goto P_0c04526a;
case 0x0c04526cu: goto P_0c04526c;
case 0x0c04526eu: goto P_0c04526e;
case 0x0c045270u: goto P_0c045270;
case 0x0c045272u: goto P_0c045272;
case 0x0c045274u: goto P_0c045274;
case 0x0c045276u: goto P_0c045276;
case 0x0c045278u: goto P_0c045278;
case 0x0c04527au: goto P_0c04527a;
case 0x0c04527cu: goto P_0c04527c;
case 0x0c04527eu: goto P_0c04527e;
case 0x0c045280u: goto P_0c045280;
case 0x0c045282u: goto P_0c045282;
case 0x0c045284u: goto P_0c045284;
case 0x0c045286u: goto P_0c045286;
case 0x0c045288u: goto P_0c045288;
case 0x0c04528au: goto P_0c04528a;
case 0x0c04528cu: goto P_0c04528c;
case 0x0c04528eu: goto P_0c04528e;
case 0x0c045290u: goto P_0c045290;
case 0x0c045292u: goto P_0c045292;
case 0x0c045294u: goto P_0c045294;
case 0x0c045296u: goto P_0c045296;
case 0x0c045298u: goto P_0c045298;
case 0x0c04529au: goto P_0c04529a;
case 0x0c04529cu: goto P_0c04529c;
case 0x0c04529eu: goto P_0c04529e;
case 0x0c0452a0u: goto P_0c0452a0;
case 0x0c0452a2u: goto P_0c0452a2;
case 0x0c0452a4u: goto P_0c0452a4;
case 0x0c0452a6u: goto P_0c0452a6;
case 0x0c0452a8u: goto P_0c0452a8;
case 0x0c0452aau: goto P_0c0452aa;
case 0x0c0452acu: goto P_0c0452ac;
case 0x0c0452aeu: goto P_0c0452ae;
case 0x0c0452b0u: goto P_0c0452b0;
case 0x0c0452b2u: goto P_0c0452b2;
case 0x0c0452b4u: goto P_0c0452b4;
case 0x0c0452b6u: goto P_0c0452b6;
case 0x0c0452b8u: goto P_0c0452b8;
case 0x0c0452bau: goto P_0c0452ba;
case 0x0c0452bcu: goto P_0c0452bc;
case 0x0c0452beu: goto P_0c0452be;
case 0x0c0452c0u: goto P_0c0452c0;
case 0x0c0452c2u: goto P_0c0452c2;
case 0x0c0452c4u: goto P_0c0452c4;
case 0x0c0452c6u: goto P_0c0452c6;
case 0x0c0452c8u: goto P_0c0452c8;
case 0x0c0452cau: goto P_0c0452ca;
case 0x0c0452ccu: goto P_0c0452cc;
case 0x0c0452ceu: goto P_0c0452ce;
case 0x0c0452d0u: goto P_0c0452d0;
case 0x0c0452d2u: goto P_0c0452d2;
case 0x0c0452d4u: goto P_0c0452d4;
case 0x0c0452d6u: goto P_0c0452d6;
case 0x0c0452d8u: goto P_0c0452d8;
case 0x0c0452dau: goto P_0c0452da;
case 0x0c0452dcu: goto P_0c0452dc;
case 0x0c0452deu: goto P_0c0452de;
case 0x0c0452e0u: goto P_0c0452e0;
case 0x0c0452e2u: goto P_0c0452e2;
case 0x0c0452e4u: goto P_0c0452e4;
case 0x0c0452e6u: goto P_0c0452e6;
case 0x0c0452e8u: goto P_0c0452e8;
case 0x0c0452eau: goto P_0c0452ea;
case 0x0c0452ecu: goto P_0c0452ec;
case 0x0c0452eeu: goto P_0c0452ee;
case 0x0c0452f0u: goto P_0c0452f0;
case 0x0c0452f2u: goto P_0c0452f2;
case 0x0c0452f4u: goto P_0c0452f4;
case 0x0c0452f6u: goto P_0c0452f6;
case 0x0c0452f8u: goto P_0c0452f8;
case 0x0c0452fau: goto P_0c0452fa;
case 0x0c0452fcu: goto P_0c0452fc;
case 0x0c0452feu: goto P_0c0452fe;
case 0x0c045300u: goto P_0c045300;
case 0x0c045302u: goto P_0c045302;
case 0x0c045304u: goto P_0c045304;
case 0x0c045306u: goto P_0c045306;
case 0x0c045308u: goto P_0c045308;
case 0x0c04530au: goto P_0c04530a;
case 0x0c04530cu: goto P_0c04530c;
case 0x0c04530eu: goto P_0c04530e;
case 0x0c045310u: goto P_0c045310;
case 0x0c045312u: goto P_0c045312;
case 0x0c045314u: goto P_0c045314;
case 0x0c045316u: goto P_0c045316;
case 0x0c045318u: goto P_0c045318;
case 0x0c04531au: goto P_0c04531a;
case 0x0c04531cu: goto P_0c04531c;
case 0x0c04531eu: goto P_0c04531e;
case 0x0c045320u: goto P_0c045320;
case 0x0c045322u: goto P_0c045322;
case 0x0c045324u: goto P_0c045324;
case 0x0c045326u: goto P_0c045326;
case 0x0c045328u: goto P_0c045328;
case 0x0c04532au: goto P_0c04532a;
case 0x0c04532cu: goto P_0c04532c;
case 0x0c04532eu: goto P_0c04532e;
case 0x0c045330u: goto P_0c045330;
case 0x0c045332u: goto P_0c045332;
case 0x0c045344u: goto P_0c045344;
case 0x0c045346u: goto P_0c045346;
case 0x0c045348u: goto P_0c045348;
case 0x0c04534au: goto P_0c04534a;
case 0x0c04534cu: goto P_0c04534c;
case 0x0c04534eu: goto P_0c04534e;
case 0x0c045350u: goto P_0c045350;
case 0x0c045352u: goto P_0c045352;
case 0x0c045354u: goto P_0c045354;
case 0x0c045356u: goto P_0c045356;
case 0x0c045358u: goto P_0c045358;
case 0x0c04535au: goto P_0c04535a;
case 0x0c04535cu: goto P_0c04535c;
case 0x0c04535eu: goto P_0c04535e;
case 0x0c045360u: goto P_0c045360;
case 0x0c045362u: goto P_0c045362;
case 0x0c045364u: goto P_0c045364;
case 0x0c045366u: goto P_0c045366;
case 0x0c045368u: goto P_0c045368;
case 0x0c04536au: goto P_0c04536a;
case 0x0c04536cu: goto P_0c04536c;
case 0x0c04536eu: goto P_0c04536e;
case 0x0c045370u: goto P_0c045370;
case 0x0c045372u: goto P_0c045372;
case 0x0c045374u: goto P_0c045374;
case 0x0c045376u: goto P_0c045376;
case 0x0c045378u: goto P_0c045378;
case 0x0c04537au: goto P_0c04537a;
case 0x0c04537cu: goto P_0c04537c;
case 0x0c04537eu: goto P_0c04537e;
case 0x0c045380u: goto P_0c045380;
case 0x0c045382u: goto P_0c045382;
case 0x0c045384u: goto P_0c045384;
case 0x0c045386u: goto P_0c045386;
case 0x0c045388u: goto P_0c045388;
case 0x0c04538au: goto P_0c04538a;
case 0x0c04538cu: goto P_0c04538c;
case 0x0c04538eu: goto P_0c04538e;
case 0x0c045390u: goto P_0c045390;
case 0x0c045392u: goto P_0c045392;
case 0x0c045394u: goto P_0c045394;
case 0x0c045396u: goto P_0c045396;
case 0x0c045398u: goto P_0c045398;
case 0x0c04539au: goto P_0c04539a;
case 0x0c04539cu: goto P_0c04539c;
case 0x0c04539eu: goto P_0c04539e;
case 0x0c0453a0u: goto P_0c0453a0;
case 0x0c0453a2u: goto P_0c0453a2;
case 0x0c0453a4u: goto P_0c0453a4;
case 0x0c0453a6u: goto P_0c0453a6;
case 0x0c0453a8u: goto P_0c0453a8;
case 0x0c0453aau: goto P_0c0453aa;
case 0x0c0453acu: goto P_0c0453ac;
case 0x0c0453aeu: goto P_0c0453ae;
case 0x0c0453b0u: goto P_0c0453b0;
case 0x0c0453b2u: goto P_0c0453b2;
case 0x0c0453b4u: goto P_0c0453b4;
case 0x0c0453b6u: goto P_0c0453b6;
case 0x0c0453b8u: goto P_0c0453b8;
case 0x0c0453bau: goto P_0c0453ba;
case 0x0c0453bcu: goto P_0c0453bc;
case 0x0c0453beu: goto P_0c0453be;
case 0x0c0453c0u: goto P_0c0453c0;
case 0x0c0453c2u: goto P_0c0453c2;
case 0x0c0453c4u: goto P_0c0453c4;
case 0x0c0453c6u: goto P_0c0453c6;
case 0x0c0453c8u: goto P_0c0453c8;
case 0x0c0453cau: goto P_0c0453ca;
case 0x0c0453ccu: goto P_0c0453cc;
case 0x0c0453ceu: goto P_0c0453ce;
case 0x0c0453d0u: goto P_0c0453d0;
case 0x0c0453d2u: goto P_0c0453d2;
case 0x0c0453d4u: goto P_0c0453d4;
case 0x0c0453d6u: goto P_0c0453d6;
case 0x0c0453d8u: goto P_0c0453d8;
case 0x0c0453dau: goto P_0c0453da;
case 0x0c0453dcu: goto P_0c0453dc;
case 0x0c0453deu: goto P_0c0453de;
case 0x0c0453e0u: goto P_0c0453e0;
case 0x0c0453e2u: goto P_0c0453e2;
case 0x0c0453e4u: goto P_0c0453e4;
case 0x0c0453e6u: goto P_0c0453e6;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0451f8: /* original 2fe6, guest PC 0x0c0451f8 */
if(!s->budget--) { s->failed_pc=0x0c0451f8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0451fa;
P_0c0451fa: /* original 6353, guest PC 0x0c0451fa */
if(!s->budget--) { s->failed_pc=0x0c0451fau; return 0; }
r[3]=r[5];
goto P_0c0451fc;
P_0c0451fc: /* original 2fd6, guest PC 0x0c0451fc */
if(!s->budget--) { s->failed_pc=0x0c0451fcu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0451fe;
P_0c0451fe: /* original 4308, guest PC 0x0c0451fe */
if(!s->budget--) { s->failed_pc=0x0c0451feu; return 0; }
r[3]<<=2;
goto P_0c045200;
P_0c045200: /* original 2fc6, guest PC 0x0c045200 */
if(!s->budget--) { s->failed_pc=0x0c045200u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045202;
P_0c045202: /* original 4300, guest PC 0x0c045202 */
if(!s->budget--) { s->failed_pc=0x0c045202u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c045204;
P_0c045204: /* original 2fb6, guest PC 0x0c045204 */
if(!s->budget--) { s->failed_pc=0x0c045204u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045206;
P_0c045206: /* original 2fa6, guest PC 0x0c045206 */
if(!s->budget--) { s->failed_pc=0x0c045206u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045208;
P_0c045208: /* original 6a53, guest PC 0x0c045208 */
if(!s->budget--) { s->failed_pc=0x0c045208u; return 0; }
r[10]=r[5];
goto P_0c04520a;
P_0c04520a: /* original 2f96, guest PC 0x0c04520a */
if(!s->budget--) { s->failed_pc=0x0c04520au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04520c;
P_0c04520c: /* original 2f86, guest PC 0x0c04520c */
if(!s->budget--) { s->failed_pc=0x0c04520cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04520e;
P_0c04520e: /* original dd4b, guest PC 0x0c04520e */
if(!s->budget--) { s->failed_pc=0x0c04520eu; return 0; }
r[13]=read(ram,0x0c04533cu,4);
goto P_0c045210;
P_0c045210: /* original 4f22, guest PC 0x0c045210 */
if(!s->budget--) { s->failed_pc=0x0c045210u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045212;
P_0c045212: /* original 69d2, guest PC 0x0c045212 */
if(!s->budget--) { s->failed_pc=0x0c045212u; return 0; }
tmp=read(ram,r[13],4);
r[9]=tmp;
goto P_0c045214;
P_0c045214: /* original 6ed2, guest PC 0x0c045214 */
if(!s->budget--) { s->failed_pc=0x0c045214u; return 0; }
tmp=read(ram,r[13],4);
r[14]=tmp;
goto P_0c045216;
P_0c045216: /* original 7904, guest PC 0x0c045216 */
if(!s->budget--) { s->failed_pc=0x0c045216u; return 0; }
r[9]+=0x00000004u;
goto P_0c045218;
P_0c045218: /* original 6bd2, guest PC 0x0c045218 */
if(!s->budget--) { s->failed_pc=0x0c045218u; return 0; }
tmp=read(ram,r[13],4);
r[11]=tmp;
goto P_0c04521a;
P_0c04521a: /* original 393c, guest PC 0x0c04521a */
if(!s->budget--) { s->failed_pc=0x0c04521au; return 0; }
r[9]+=r[3];
goto P_0c04521c;
P_0c04521c: /* original 928a, guest PC 0x0c04521c */
if(!s->budget--) { s->failed_pc=0x0c04521cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c045334u,2);
goto P_0c04521e;
P_0c04521e: /* original e32c, guest PC 0x0c04521e */
if(!s->budget--) { s->failed_pc=0x0c04521eu; return 0; }
r[3]=0x0000002cu;
goto P_0c045220;
P_0c045220: /* original 4f12, guest PC 0x0c045220 */
if(!s->budget--) { s->failed_pc=0x0c045220u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c045222;
P_0c045222: /* original 243f, guest PC 0x0c045222 */
if(!s->budget--) { s->failed_pc=0x0c045222u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c045224;
P_0c045224: /* original 7e28, guest PC 0x0c045224 */
if(!s->budget--) { s->failed_pc=0x0c045224u; return 0; }
r[14]+=0x00000028u;
goto P_0c045226;
P_0c045226: /* original 7ffc, guest PC 0x0c045226 */
if(!s->budget--) { s->failed_pc=0x0c045226u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c045228;
P_0c045228: /* original 3b2c, guest PC 0x0c045228 */
if(!s->budget--) { s->failed_pc=0x0c045228u; return 0; }
r[11]+=r[2];
goto P_0c04522a;
P_0c04522a: /* original 031a, guest PC 0x0c04522a */
if(!s->budget--) { s->failed_pc=0x0c04522au; return 0; }
r[3]=r[19];
goto P_0c04522c;
P_0c04522c: /* original 633f, guest PC 0x0c04522c */
if(!s->budget--) { s->failed_pc=0x0c04522cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04522e;
P_0c04522e: /* original 3e3c, guest PC 0x0c04522e */
if(!s->budget--) { s->failed_pc=0x0c04522eu; return 0; }
r[14]+=r[3];
goto P_0c045230;
P_0c045230: /* original e378, guest PC 0x0c045230 */
if(!s->budget--) { s->failed_pc=0x0c045230u; return 0; }
r[3]=0x00000078u;
goto P_0c045232;
P_0c045232: /* original 243f, guest PC 0x0c045232 */
if(!s->budget--) { s->failed_pc=0x0c045232u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c045234;
P_0c045234: /* original 031a, guest PC 0x0c045234 */
if(!s->budget--) { s->failed_pc=0x0c045234u; return 0; }
r[3]=r[19];
goto P_0c045236;
P_0c045236: /* original 633f, guest PC 0x0c045236 */
if(!s->budget--) { s->failed_pc=0x0c045236u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c045238;
P_0c045238: /* original 60d2, guest PC 0x0c045238 */
if(!s->budget--) { s->failed_pc=0x0c045238u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c04523a;
P_0c04523a: /* original 3b3c, guest PC 0x0c04523a */
if(!s->budget--) { s->failed_pc=0x0c04523au; return 0; }
r[11]+=r[3];
goto P_0c04523c;
P_0c04523c: /* original 917b, guest PC 0x0c04523c */
if(!s->budget--) { s->failed_pc=0x0c04523cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c045336u,2);
goto P_0c04523e;
P_0c04523e: /* original 6c43, guest PC 0x0c04523e */
if(!s->budget--) { s->failed_pc=0x0c04523eu; return 0; }
r[12]=r[4];
goto P_0c045240;
P_0c045240: /* original 6303, guest PC 0x0c045240 */
if(!s->budget--) { s->failed_pc=0x0c045240u; return 0; }
r[3]=r[0];
goto P_0c045242;
P_0c045242: /* original 4c08, guest PC 0x0c045242 */
if(!s->budget--) { s->failed_pc=0x0c045242u; return 0; }
r[12]<<=2;
goto P_0c045244;
P_0c045244: /* original 313c, guest PC 0x0c045244 */
if(!s->budget--) { s->failed_pc=0x0c045244u; return 0; }
r[1]+=r[3];
goto P_0c045246;
P_0c045246: /* original 6110, guest PC 0x0c045246 */
if(!s->budget--) { s->failed_pc=0x0c045246u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[1]=tmp;
goto P_0c045248;
P_0c045248: /* original 611b, guest PC 0x0c045248 */
if(!s->budget--) { s->failed_pc=0x0c045248u; return 0; }
r[1]=0u-r[1];
goto P_0c04524a;
P_0c04524a: /* original 7101, guest PC 0x0c04524a */
if(!s->budget--) { s->failed_pc=0x0c04524au; return 0; }
r[1]+=0x00000001u;
goto P_0c04524c;
P_0c04524c: /* original 6313, guest PC 0x0c04524c */
if(!s->budget--) { s->failed_pc=0x0c04524cu; return 0; }
r[3]=r[1];
goto P_0c04524e;
P_0c04524e: /* original 4100, guest PC 0x0c04524e */
if(!s->budget--) { s->failed_pc=0x0c04524eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c045250;
P_0c045250: /* original 313c, guest PC 0x0c045250 */
if(!s->budget--) { s->failed_pc=0x0c045250u; return 0; }
r[1]+=r[3];
goto P_0c045252;
P_0c045252: /* original 9371, guest PC 0x0c045252 */
if(!s->budget--) { s->failed_pc=0x0c045252u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c045338u,2);
goto P_0c045254;
P_0c045254: /* original 4108, guest PC 0x0c045254 */
if(!s->budget--) { s->failed_pc=0x0c045254u; return 0; }
r[1]<<=2;
goto P_0c045256;
P_0c045256: /* original 2fc2, guest PC 0x0c045256 */
if(!s->budget--) { s->failed_pc=0x0c045256u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c045258;
P_0c045258: /* original 4108, guest PC 0x0c045258 */
if(!s->budget--) { s->failed_pc=0x0c045258u; return 0; }
r[1]<<=2;
goto P_0c04525a;
P_0c04525a: /* original 4100, guest PC 0x0c04525a */
if(!s->budget--) { s->failed_pc=0x0c04525au; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c04525c;
P_0c04525c: /* original 611c, guest PC 0x0c04525c */
if(!s->budget--) { s->failed_pc=0x0c04525cu; return 0; }
r[1]=r[1]&255u;
goto P_0c04525e;
P_0c04525e: /* original 303c, guest PC 0x0c04525e */
if(!s->budget--) { s->failed_pc=0x0c04525eu; return 0; }
r[0]+=r[3];
goto P_0c045260;
P_0c045260: /* original 301c, guest PC 0x0c045260 */
if(!s->budget--) { s->failed_pc=0x0c045260u; return 0; }
r[0]+=r[1];
goto P_0c045262;
P_0c045262: /* original 0cce, guest PC 0x0c045262 */
if(!s->budget--) { s->failed_pc=0x0c045262u; return 0; }
r[12]=read(ram,r[12]+r[0],4);
goto P_0c045264;
P_0c045264: /* original 60e0, guest PC 0x0c045264 */
if(!s->budget--) { s->failed_pc=0x0c045264u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[0]=tmp;
goto P_0c045266;
P_0c045266: /* original 80e1, guest PC 0x0c045266 */
if(!s->budget--) { s->failed_pc=0x0c045266u; return 0; }
write(ram,r[14]+1,r[0],1);
goto P_0c045268;
P_0c045268: /* original 84e4, guest PC 0x0c045268 */
if(!s->budget--) { s->failed_pc=0x0c045268u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c04526a;
P_0c04526a: /* original 80e5, guest PC 0x0c04526a */
if(!s->budget--) { s->failed_pc=0x0c04526au; return 0; }
write(ram,r[14]+5,r[0],1);
goto P_0c04526c;
P_0c04526c: /* original 51e7, guest PC 0x0c04526c */
if(!s->budget--) { s->failed_pc=0x0c04526cu; return 0; }
r[1]=read(ram,r[14]+28,4);
goto P_0c04526e;
P_0c04526e: /* original 2118, guest PC 0x0c04526e */
if(!s->budget--) { s->failed_pc=0x0c04526eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c045270;
P_0c045270: /* original 8d03, guest PC 0x0c045270 */
if(!s->budget--) { s->failed_pc=0x0c045270u; return 0; }
cond=r[17]&1u;
r[8]=0x00000000u;
if(cond) { goto P_0c04527a; }
goto P_0c045274;
P_0c045272: /* original e800, guest PC 0x0c045272 */
if(!s->budget--) { s->failed_pc=0x0c045272u; return 0; }
r[8]=0x00000000u;
goto P_0c045274;
P_0c045274: /* original 51e7, guest PC 0x0c045274 */
if(!s->budget--) { s->failed_pc=0x0c045274u; return 0; }
r[1]=read(ram,r[14]+28,4);
goto P_0c045276;
P_0c045276: /* original 1e18, guest PC 0x0c045276 */
if(!s->budget--) { s->failed_pc=0x0c045276u; return 0; }
write(ram,r[14]+32,r[1],4);
goto P_0c045278;
P_0c045278: /* original 1e87, guest PC 0x0c045278 */
if(!s->budget--) { s->failed_pc=0x0c045278u; return 0; }
write(ram,r[14]+28,r[8],4);
goto P_0c04527a;
P_0c04527a: /* original d031, guest PC 0x0c04527a */
if(!s->budget--) { s->failed_pc=0x0c04527au; return 0; }
r[0]=read(ram,0x0c045340u,4);
goto P_0c04527c;
P_0c04527c: /* original e21f, guest PC 0x0c04527c */
if(!s->budget--) { s->failed_pc=0x0c04527cu; return 0; }
r[2]=0x0000001fu;
goto P_0c04527e;
P_0c04527e: /* original 61d2, guest PC 0x0c04527e */
if(!s->budget--) { s->failed_pc=0x0c04527eu; return 0; }
tmp=read(ram,r[13],4);
r[1]=tmp;
goto P_0c045280;
P_0c045280: /* original 034c, guest PC 0x0c045280 */
if(!s->budget--) { s->failed_pc=0x0c045280u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c045282;
P_0c045282: /* original 905a, guest PC 0x0c045282 */
if(!s->budget--) { s->failed_pc=0x0c045282u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04533au,2);
goto P_0c045284;
P_0c045284: /* original 2329, guest PC 0x0c045284 */
if(!s->budget--) { s->failed_pc=0x0c045284u; return 0; }
r[3]&=r[2];
goto P_0c045286;
P_0c045286: /* original 6433, guest PC 0x0c045286 */
if(!s->budget--) { s->failed_pc=0x0c045286u; return 0; }
r[4]=r[3];
goto P_0c045288;
P_0c045288: /* original 031e, guest PC 0x0c045288 */
if(!s->budget--) { s->failed_pc=0x0c045288u; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c04528a;
P_0c04528a: /* original 2338, guest PC 0x0c04528a */
if(!s->budget--) { s->failed_pc=0x0c04528au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04528c;
P_0c04528c: /* original 8b10, guest PC 0x0c04528c */
if(!s->budget--) { s->failed_pc=0x0c04528cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0452b0; }
goto P_0c04528e;
P_0c04528e: /* original 634c, guest PC 0x0c04528e */
if(!s->budget--) { s->failed_pc=0x0c04528eu; return 0; }
r[3]=r[4]&255u;
goto P_0c045290;
P_0c045290: /* original 2338, guest PC 0x0c045290 */
if(!s->budget--) { s->failed_pc=0x0c045290u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c045292;
P_0c045292: /* original 8906, guest PC 0x0c045292 */
if(!s->budget--) { s->failed_pc=0x0c045292u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0452a2; }
goto P_0c045294;
P_0c045294: /* original 66b3, guest PC 0x0c045294 */
if(!s->budget--) { s->failed_pc=0x0c045294u; return 0; }
r[6]=r[11];
goto P_0c045296;
P_0c045296: /* original 67e3, guest PC 0x0c045296 */
if(!s->budget--) { s->failed_pc=0x0c045296u; return 0; }
r[7]=r[14];
goto P_0c045298;
P_0c045298: /* original 2fc6, guest PC 0x0c045298 */
if(!s->budget--) { s->failed_pc=0x0c045298u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04529a;
P_0c04529a: /* original b1eb, guest PC 0x0c04529a */
if(!s->budget--) { s->failed_pc=0x0c04529au; return 0; }
target=code_base|0x0c045674u; r[16]=code_base|0x0c04529eu;
r[5]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04529eu) { target=s->pc; goto dispatch; }
goto P_0c04529e;
P_0c04529c: /* original 6593, guest PC 0x0c04529c */
if(!s->budget--) { s->failed_pc=0x0c04529cu; return 0; }
r[5]=r[9];
goto P_0c04529e;
P_0c04529e: /* original a005, guest PC 0x0c04529e */
if(!s->budget--) { s->failed_pc=0x0c04529eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0452ac;
P_0c0452a0: /* original 7f04, guest PC 0x0c0452a0 */
if(!s->budget--) { s->failed_pc=0x0c0452a0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0452a2;
P_0c0452a2: /* original 65b3, guest PC 0x0c0452a2 */
if(!s->budget--) { s->failed_pc=0x0c0452a2u; return 0; }
r[5]=r[11];
goto P_0c0452a4;
P_0c0452a4: /* original 66e3, guest PC 0x0c0452a4 */
if(!s->budget--) { s->failed_pc=0x0c0452a4u; return 0; }
r[6]=r[14];
goto P_0c0452a6;
P_0c0452a6: /* original 67c3, guest PC 0x0c0452a6 */
if(!s->budget--) { s->failed_pc=0x0c0452a6u; return 0; }
r[7]=r[12];
goto P_0c0452a8;
P_0c0452a8: /* original b12b, guest PC 0x0c0452a8 */
if(!s->budget--) { s->failed_pc=0x0c0452a8u; return 0; }
target=code_base|0x0c045502u; r[16]=code_base|0x0c0452acu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0452acu) { target=s->pc; goto dispatch; }
goto P_0c0452ac;
P_0c0452aa: /* original 64a3, guest PC 0x0c0452aa */
if(!s->budget--) { s->failed_pc=0x0c0452aau; return 0; }
r[4]=r[10];
goto P_0c0452ac;
P_0c0452ac: /* original a010, guest PC 0x0c0452ac */
if(!s->budget--) { s->failed_pc=0x0c0452acu; return 0; }
r[5]=r[0];
goto P_0c0452d0;
P_0c0452ae: /* original 6503, guest PC 0x0c0452ae */
if(!s->budget--) { s->failed_pc=0x0c0452aeu; return 0; }
r[5]=r[0];
goto P_0c0452b0;
P_0c0452b0: /* original 614c, guest PC 0x0c0452b0 */
if(!s->budget--) { s->failed_pc=0x0c0452b0u; return 0; }
r[1]=r[4]&255u;
goto P_0c0452b2;
P_0c0452b2: /* original 2118, guest PC 0x0c0452b2 */
if(!s->budget--) { s->failed_pc=0x0c0452b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0452b4;
P_0c0452b4: /* original 8906, guest PC 0x0c0452b4 */
if(!s->budget--) { s->failed_pc=0x0c0452b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0452c4; }
goto P_0c0452b6;
P_0c0452b6: /* original 66b3, guest PC 0x0c0452b6 */
if(!s->budget--) { s->failed_pc=0x0c0452b6u; return 0; }
r[6]=r[11];
goto P_0c0452b8;
P_0c0452b8: /* original 67e3, guest PC 0x0c0452b8 */
if(!s->budget--) { s->failed_pc=0x0c0452b8u; return 0; }
r[7]=r[14];
goto P_0c0452ba;
P_0c0452ba: /* original 2fc6, guest PC 0x0c0452ba */
if(!s->budget--) { s->failed_pc=0x0c0452bau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0452bc;
P_0c0452bc: /* original b17e, guest PC 0x0c0452bc */
if(!s->budget--) { s->failed_pc=0x0c0452bcu; return 0; }
target=code_base|0x0c0455bcu; r[16]=code_base|0x0c0452c0u;
r[5]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0452c0u) { target=s->pc; goto dispatch; }
goto P_0c0452c0;
P_0c0452be: /* original 6593, guest PC 0x0c0452be */
if(!s->budget--) { s->failed_pc=0x0c0452beu; return 0; }
r[5]=r[9];
goto P_0c0452c0;
P_0c0452c0: /* original a005, guest PC 0x0c0452c0 */
if(!s->budget--) { s->failed_pc=0x0c0452c0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0452ce;
P_0c0452c2: /* original 7f04, guest PC 0x0c0452c2 */
if(!s->budget--) { s->failed_pc=0x0c0452c2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0452c4;
P_0c0452c4: /* original 65b3, guest PC 0x0c0452c4 */
if(!s->budget--) { s->failed_pc=0x0c0452c4u; return 0; }
r[5]=r[11];
goto P_0c0452c6;
P_0c0452c6: /* original 66e3, guest PC 0x0c0452c6 */
if(!s->budget--) { s->failed_pc=0x0c0452c6u; return 0; }
r[6]=r[14];
goto P_0c0452c8;
P_0c0452c8: /* original 67c3, guest PC 0x0c0452c8 */
if(!s->budget--) { s->failed_pc=0x0c0452c8u; return 0; }
r[7]=r[12];
goto P_0c0452ca;
P_0c0452ca: /* original b08d, guest PC 0x0c0452ca */
if(!s->budget--) { s->failed_pc=0x0c0452cau; return 0; }
target=code_base|0x0c0453e8u; r[16]=code_base|0x0c0452ceu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0452ceu) { target=s->pc; goto dispatch; }
goto P_0c0452ce;
P_0c0452cc: /* original 64a3, guest PC 0x0c0452cc */
if(!s->budget--) { s->failed_pc=0x0c0452ccu; return 0; }
r[4]=r[10];
goto P_0c0452ce;
P_0c0452ce: /* original 6503, guest PC 0x0c0452ce */
if(!s->budget--) { s->failed_pc=0x0c0452ceu; return 0; }
r[5]=r[0];
goto P_0c0452d0;
P_0c0452d0: /* original 84e7, guest PC 0x0c0452d0 */
if(!s->budget--) { s->failed_pc=0x0c0452d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+7,1);
goto P_0c0452d2;
P_0c0452d2: /* original 2008, guest PC 0x0c0452d2 */
if(!s->budget--) { s->failed_pc=0x0c0452d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0452d4;
P_0c0452d4: /* original 8912, guest PC 0x0c0452d4 */
if(!s->budget--) { s->failed_pc=0x0c0452d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0452fc; }
goto P_0c0452d6;
P_0c0452d6: /* original 62d2, guest PC 0x0c0452d6 */
if(!s->budget--) { s->failed_pc=0x0c0452d6u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0452d8;
P_0c0452d8: /* original 902d, guest PC 0x0c0452d8 */
if(!s->budget--) { s->failed_pc=0x0c0452d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c045336u,2);
goto P_0c0452da;
P_0c0452da: /* original 6323, guest PC 0x0c0452da */
if(!s->budget--) { s->failed_pc=0x0c0452dau; return 0; }
r[3]=r[2];
goto P_0c0452dc;
P_0c0452dc: /* original 013c, guest PC 0x0c0452dc */
if(!s->budget--) { s->failed_pc=0x0c0452dcu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c0452de;
P_0c0452de: /* original 60f2, guest PC 0x0c0452de */
if(!s->budget--) { s->failed_pc=0x0c0452deu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0452e0;
P_0c0452e0: /* original 611b, guest PC 0x0c0452e0 */
if(!s->budget--) { s->failed_pc=0x0c0452e0u; return 0; }
r[1]=0u-r[1];
goto P_0c0452e2;
P_0c0452e2: /* original 7101, guest PC 0x0c0452e2 */
if(!s->budget--) { s->failed_pc=0x0c0452e2u; return 0; }
r[1]+=0x00000001u;
goto P_0c0452e4;
P_0c0452e4: /* original 6313, guest PC 0x0c0452e4 */
if(!s->budget--) { s->failed_pc=0x0c0452e4u; return 0; }
r[3]=r[1];
goto P_0c0452e6;
P_0c0452e6: /* original 4100, guest PC 0x0c0452e6 */
if(!s->budget--) { s->failed_pc=0x0c0452e6u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0452e8;
P_0c0452e8: /* original 313c, guest PC 0x0c0452e8 */
if(!s->budget--) { s->failed_pc=0x0c0452e8u; return 0; }
r[1]+=r[3];
goto P_0c0452ea;
P_0c0452ea: /* original 9325, guest PC 0x0c0452ea */
if(!s->budget--) { s->failed_pc=0x0c0452eau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c045338u,2);
goto P_0c0452ec;
P_0c0452ec: /* original 4108, guest PC 0x0c0452ec */
if(!s->budget--) { s->failed_pc=0x0c0452ecu; return 0; }
r[1]<<=2;
goto P_0c0452ee;
P_0c0452ee: /* original 4108, guest PC 0x0c0452ee */
if(!s->budget--) { s->failed_pc=0x0c0452eeu; return 0; }
r[1]<<=2;
goto P_0c0452f0;
P_0c0452f0: /* original 4100, guest PC 0x0c0452f0 */
if(!s->budget--) { s->failed_pc=0x0c0452f0u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0452f2;
P_0c0452f2: /* original 323c, guest PC 0x0c0452f2 */
if(!s->budget--) { s->failed_pc=0x0c0452f2u; return 0; }
r[2]+=r[3];
goto P_0c0452f4;
P_0c0452f4: /* original 611c, guest PC 0x0c0452f4 */
if(!s->budget--) { s->failed_pc=0x0c0452f4u; return 0; }
r[1]=r[1]&255u;
goto P_0c0452f6;
P_0c0452f6: /* original 312c, guest PC 0x0c0452f6 */
if(!s->budget--) { s->failed_pc=0x0c0452f6u; return 0; }
r[1]+=r[2];
goto P_0c0452f8;
P_0c0452f8: /* original 021e, guest PC 0x0c0452f8 */
if(!s->budget--) { s->failed_pc=0x0c0452f8u; return 0; }
r[2]=read(ram,r[1]+r[0],4);
goto P_0c0452fa;
P_0c0452fa: /* original 1e24, guest PC 0x0c0452fa */
if(!s->budget--) { s->failed_pc=0x0c0452fau; return 0; }
write(ram,r[14]+16,r[2],4);
goto P_0c0452fc;
P_0c0452fc: /* original 84ed, guest PC 0x0c0452fc */
if(!s->budget--) { s->failed_pc=0x0c0452fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+13,1);
goto P_0c0452fe;
P_0c0452fe: /* original 2008, guest PC 0x0c0452fe */
if(!s->budget--) { s->failed_pc=0x0c0452feu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c045300;
P_0c045300: /* original 8902, guest PC 0x0c045300 */
if(!s->budget--) { s->failed_pc=0x0c045300u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c045308; }
goto P_0c045302;
P_0c045302: /* original 6083, guest PC 0x0c045302 */
if(!s->budget--) { s->failed_pc=0x0c045302u; return 0; }
r[0]=r[8];
goto P_0c045304;
P_0c045304: /* original 80ec, guest PC 0x0c045304 */
if(!s->budget--) { s->failed_pc=0x0c045304u; return 0; }
write(ram,r[14]+12,r[0],1);
goto P_0c045306;
P_0c045306: /* original 80ed, guest PC 0x0c045306 */
if(!s->budget--) { s->failed_pc=0x0c045306u; return 0; }
write(ram,r[14]+13,r[0],1);
goto P_0c045308;
P_0c045308: /* original 7f04, guest PC 0x0c045308 */
if(!s->budget--) { s->failed_pc=0x0c045308u; return 0; }
r[15]+=0x00000004u;
goto P_0c04530a;
P_0c04530a: /* original 84e2, guest PC 0x0c04530a */
if(!s->budget--) { s->failed_pc=0x0c04530au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c04530c;
P_0c04530c: /* original 4f16, guest PC 0x0c04530c */
if(!s->budget--) { s->failed_pc=0x0c04530cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04530e;
P_0c04530e: /* original 6303, guest PC 0x0c04530e */
if(!s->budget--) { s->failed_pc=0x0c04530eu; return 0; }
r[3]=r[0];
goto P_0c045310;
P_0c045310: /* original 84ec, guest PC 0x0c045310 */
if(!s->budget--) { s->failed_pc=0x0c045310u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+12,1);
goto P_0c045312;
P_0c045312: /* original 4f26, guest PC 0x0c045312 */
if(!s->budget--) { s->failed_pc=0x0c045312u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045314;
P_0c045314: /* original 203b, guest PC 0x0c045314 */
if(!s->budget--) { s->failed_pc=0x0c045314u; return 0; }
r[0]|=r[3];
goto P_0c045316;
P_0c045316: /* original 80ec, guest PC 0x0c045316 */
if(!s->budget--) { s->failed_pc=0x0c045316u; return 0; }
write(ram,r[14]+12,r[0],1);
goto P_0c045318;
P_0c045318: /* original 84e3, guest PC 0x0c045318 */
if(!s->budget--) { s->failed_pc=0x0c045318u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+3,1);
goto P_0c04531a;
P_0c04531a: /* original 6303, guest PC 0x0c04531a */
if(!s->budget--) { s->failed_pc=0x0c04531au; return 0; }
r[3]=r[0];
goto P_0c04531c;
P_0c04531c: /* original 84ec, guest PC 0x0c04531c */
if(!s->budget--) { s->failed_pc=0x0c04531cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+12,1);
goto P_0c04531e;
P_0c04531e: /* original 203b, guest PC 0x0c04531e */
if(!s->budget--) { s->failed_pc=0x0c04531eu; return 0; }
r[0]|=r[3];
goto P_0c045320;
P_0c045320: /* original 80ec, guest PC 0x0c045320 */
if(!s->budget--) { s->failed_pc=0x0c045320u; return 0; }
write(ram,r[14]+12,r[0],1);
goto P_0c045322;
P_0c045322: /* original 6053, guest PC 0x0c045322 */
if(!s->budget--) { s->failed_pc=0x0c045322u; return 0; }
r[0]=r[5];
goto P_0c045324;
P_0c045324: /* original 68f6, guest PC 0x0c045324 */
if(!s->budget--) { s->failed_pc=0x0c045324u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c045326;
P_0c045326: /* original 69f6, guest PC 0x0c045326 */
if(!s->budget--) { s->failed_pc=0x0c045326u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c045328;
P_0c045328: /* original 6af6, guest PC 0x0c045328 */
if(!s->budget--) { s->failed_pc=0x0c045328u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04532a;
P_0c04532a: /* original 6bf6, guest PC 0x0c04532a */
if(!s->budget--) { s->failed_pc=0x0c04532au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04532c;
P_0c04532c: /* original 6cf6, guest PC 0x0c04532c */
if(!s->budget--) { s->failed_pc=0x0c04532cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04532e;
P_0c04532e: /* original 6df6, guest PC 0x0c04532e */
if(!s->budget--) { s->failed_pc=0x0c04532eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c045330;
P_0c045330: /* original 000b, guest PC 0x0c045330 */
if(!s->budget--) { s->failed_pc=0x0c045330u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c045332: /* original 6ef6, guest PC 0x0c045332 */
if(!s->budget--) { s->failed_pc=0x0c045332u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c045334u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c045334u; return 0; } return 1;
P_0c045344: /* original 8447, guest PC 0x0c045344 */
if(!s->budget--) { s->failed_pc=0x0c045344u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+7,1);
goto P_0c045346;
P_0c045346: /* original e601, guest PC 0x0c045346 */
if(!s->budget--) { s->failed_pc=0x0c045346u; return 0; }
r[6]=0x00000001u;
goto P_0c045348;
P_0c045348: /* original 600c, guest PC 0x0c045348 */
if(!s->budget--) { s->failed_pc=0x0c045348u; return 0; }
r[0]=r[0]&255u;
goto P_0c04534a;
P_0c04534a: /* original 8801, guest PC 0x0c04534a */
if(!s->budget--) { s->failed_pc=0x0c04534au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c04534c;
P_0c04534c: /* original 8f08, guest PC 0x0c04534c */
if(!s->budget--) { s->failed_pc=0x0c04534cu; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(!cond) { goto P_0c045360; }
goto P_0c045350;
P_0c04534e: /* original e500, guest PC 0x0c04534e */
if(!s->budget--) { s->failed_pc=0x0c04534eu; return 0; }
r[5]=0x00000000u;
goto P_0c045350;
P_0c045350: /* original 8448, guest PC 0x0c045350 */
if(!s->budget--) { s->failed_pc=0x0c045350u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c045352;
P_0c045352: /* original 600c, guest PC 0x0c045352 */
if(!s->budget--) { s->failed_pc=0x0c045352u; return 0; }
r[0]=r[0]&255u;
goto P_0c045354;
P_0c045354: /* original 8805, guest PC 0x0c045354 */
if(!s->budget--) { s->failed_pc=0x0c045354u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c045356;
P_0c045356: /* original 8b01, guest PC 0x0c045356 */
if(!s->budget--) { s->failed_pc=0x0c045356u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04535c; }
goto P_0c045358;
P_0c045358: /* original a00c, guest PC 0x0c045358 */
if(!s->budget--) { s->failed_pc=0x0c045358u; return 0; }
write(ram,r[4],r[6],1);
goto P_0c045374;
P_0c04535a: /* original 2460, guest PC 0x0c04535a */
if(!s->budget--) { s->failed_pc=0x0c04535au; return 0; }
write(ram,r[4],r[6],1);
goto P_0c04535c;
P_0c04535c: /* original a00a, guest PC 0x0c04535c */
if(!s->budget--) { s->failed_pc=0x0c04535cu; return 0; }
write(ram,r[4],r[5],1);
goto P_0c045374;
P_0c04535e: /* original 2450, guest PC 0x0c04535e */
if(!s->budget--) { s->failed_pc=0x0c04535eu; return 0; }
write(ram,r[4],r[5],1);
goto P_0c045360;
P_0c045360: /* original 8448, guest PC 0x0c045360 */
if(!s->budget--) { s->failed_pc=0x0c045360u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c045362;
P_0c045362: /* original 600c, guest PC 0x0c045362 */
if(!s->budget--) { s->failed_pc=0x0c045362u; return 0; }
r[0]=r[0]&255u;
goto P_0c045364;
P_0c045364: /* original 8800, guest PC 0x0c045364 */
if(!s->budget--) { s->failed_pc=0x0c045364u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c045366;
P_0c045366: /* original 8902, guest PC 0x0c045366 */
if(!s->budget--) { s->failed_pc=0x0c045366u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04536e; }
goto P_0c045368;
P_0c045368: /* original 916e, guest PC 0x0c045368 */
if(!s->budget--) { s->failed_pc=0x0c045368u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c045448u,2);
goto P_0c04536a;
P_0c04536a: /* original 3010, guest PC 0x0c04536a */
if(!s->budget--) { s->failed_pc=0x0c04536au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04536c;
P_0c04536c: /* original 8b01, guest PC 0x0c04536c */
if(!s->budget--) { s->failed_pc=0x0c04536cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c045372; }
goto P_0c04536e;
P_0c04536e: /* original a001, guest PC 0x0c04536e */
if(!s->budget--) { s->failed_pc=0x0c04536eu; return 0; }
write(ram,r[4],r[5],1);
goto P_0c045374;
P_0c045370: /* original 2450, guest PC 0x0c045370 */
if(!s->budget--) { s->failed_pc=0x0c045370u; return 0; }
write(ram,r[4],r[5],1);
goto P_0c045372;
P_0c045372: /* original 2460, guest PC 0x0c045372 */
if(!s->budget--) { s->failed_pc=0x0c045372u; return 0; }
write(ram,r[4],r[6],1);
goto P_0c045374;
P_0c045374: /* original 000b, guest PC 0x0c045374 */
if(!s->budget--) { s->failed_pc=0x0c045374u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c045376: /* original e000, guest PC 0x0c045376 */
if(!s->budget--) { s->failed_pc=0x0c045376u; return 0; }
r[0]=0x00000000u;
goto P_0c045378;
P_0c045378: /* original 9066, guest PC 0x0c045378 */
if(!s->budget--) { s->failed_pc=0x0c045378u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c045448u,2);
goto P_0c04537a;
P_0c04537a: /* original e3ff, guest PC 0x0c04537a */
if(!s->budget--) { s->failed_pc=0x0c04537au; return 0; }
r[3]=0xffffffffu;
goto P_0c04537c;
P_0c04537c: /* original 804b, guest PC 0x0c04537c */
if(!s->budget--) { s->failed_pc=0x0c04537cu; return 0; }
write(ram,r[4]+11,r[0],1);
goto P_0c04537e;
P_0c04537e: /* original 804a, guest PC 0x0c04537e */
if(!s->budget--) { s->failed_pc=0x0c04537eu; return 0; }
write(ram,r[4]+10,r[0],1);
goto P_0c045380;
P_0c045380: /* original 8049, guest PC 0x0c045380 */
if(!s->budget--) { s->failed_pc=0x0c045380u; return 0; }
write(ram,r[4]+9,r[0],1);
goto P_0c045382;
P_0c045382: /* original 8048, guest PC 0x0c045382 */
if(!s->budget--) { s->failed_pc=0x0c045382u; return 0; }
write(ram,r[4]+8,r[0],1);
goto P_0c045384;
P_0c045384: /* original 1435, guest PC 0x0c045384 */
if(!s->budget--) { s->failed_pc=0x0c045384u; return 0; }
write(ram,r[4]+20,r[3],4);
goto P_0c045386;
P_0c045386: /* original 000b, guest PC 0x0c045386 */
if(!s->budget--) { s->failed_pc=0x0c045386u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c045388: /* original e000, guest PC 0x0c045388 */
if(!s->budget--) { s->failed_pc=0x0c045388u; return 0; }
r[0]=0x00000000u;
goto P_0c04538a;
P_0c04538a: /* original 6356, guest PC 0x0c04538a */
if(!s->budget--) { s->failed_pc=0x0c04538au; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[3]=tmp;
goto P_0c04538c;
P_0c04538c: /* original 7ffc, guest PC 0x0c04538c */
if(!s->budget--) { s->failed_pc=0x0c04538cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04538e;
P_0c04538e: /* original 2f32, guest PC 0x0c04538e */
if(!s->budget--) { s->failed_pc=0x0c04538eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c045390;
P_0c045390: /* original d230, guest PC 0x0c045390 */
if(!s->budget--) { s->failed_pc=0x0c045390u; return 0; }
r[2]=read(ram,0x0c045454u,4);
goto P_0c045392;
P_0c045392: /* original 915a, guest PC 0x0c045392 */
if(!s->budget--) { s->failed_pc=0x0c045392u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04544au,2);
goto P_0c045394;
P_0c045394: /* original 6022, guest PC 0x0c045394 */
if(!s->budget--) { s->failed_pc=0x0c045394u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c045396;
P_0c045396: /* original 001e, guest PC 0x0c045396 */
if(!s->budget--) { s->failed_pc=0x0c045396u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c045398;
P_0c045398: /* original 8801, guest PC 0x0c045398 */
if(!s->budget--) { s->failed_pc=0x0c045398u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c04539a;
P_0c04539a: /* original 8b09, guest PC 0x0c04539a */
if(!s->budget--) { s->failed_pc=0x0c04539au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0453b0; }
goto P_0c04539c;
P_0c04539c: /* original 66f3, guest PC 0x0c04539c */
if(!s->budget--) { s->failed_pc=0x0c04539cu; return 0; }
r[6]=r[15];
goto P_0c04539e;
P_0c04539e: /* original 6064, guest PC 0x0c04539e */
if(!s->budget--) { s->failed_pc=0x0c04539eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]+=1;
r[0]=tmp;
goto P_0c0453a0;
P_0c0453a0: /* original 804b, guest PC 0x0c0453a0 */
if(!s->budget--) { s->failed_pc=0x0c0453a0u; return 0; }
write(ram,r[4]+11,r[0],1);
goto P_0c0453a2;
P_0c0453a2: /* original 6064, guest PC 0x0c0453a2 */
if(!s->budget--) { s->failed_pc=0x0c0453a2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]+=1;
r[0]=tmp;
goto P_0c0453a4;
P_0c0453a4: /* original 804a, guest PC 0x0c0453a4 */
if(!s->budget--) { s->failed_pc=0x0c0453a4u; return 0; }
write(ram,r[4]+10,r[0],1);
goto P_0c0453a6;
P_0c0453a6: /* original 6064, guest PC 0x0c0453a6 */
if(!s->budget--) { s->failed_pc=0x0c0453a6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]+=1;
r[0]=tmp;
goto P_0c0453a8;
P_0c0453a8: /* original 8049, guest PC 0x0c0453a8 */
if(!s->budget--) { s->failed_pc=0x0c0453a8u; return 0; }
write(ram,r[4]+9,r[0],1);
goto P_0c0453aa;
P_0c0453aa: /* original 6060, guest PC 0x0c0453aa */
if(!s->budget--) { s->failed_pc=0x0c0453aau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[0]=tmp;
goto P_0c0453ac;
P_0c0453ac: /* original a009, guest PC 0x0c0453ac */
if(!s->budget--) { s->failed_pc=0x0c0453acu; return 0; }
write(ram,r[4]+8,r[0],1);
goto P_0c0453c2;
P_0c0453ae: /* original 8048, guest PC 0x0c0453ae */
if(!s->budget--) { s->failed_pc=0x0c0453aeu; return 0; }
write(ram,r[4]+8,r[0],1);
goto P_0c0453b0;
P_0c0453b0: /* original 66f3, guest PC 0x0c0453b0 */
if(!s->budget--) { s->failed_pc=0x0c0453b0u; return 0; }
r[6]=r[15];
goto P_0c0453b2;
P_0c0453b2: /* original 6064, guest PC 0x0c0453b2 */
if(!s->budget--) { s->failed_pc=0x0c0453b2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]+=1;
r[0]=tmp;
goto P_0c0453b4;
P_0c0453b4: /* original 8048, guest PC 0x0c0453b4 */
if(!s->budget--) { s->failed_pc=0x0c0453b4u; return 0; }
write(ram,r[4]+8,r[0],1);
goto P_0c0453b6;
P_0c0453b6: /* original 6064, guest PC 0x0c0453b6 */
if(!s->budget--) { s->failed_pc=0x0c0453b6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]+=1;
r[0]=tmp;
goto P_0c0453b8;
P_0c0453b8: /* original 8049, guest PC 0x0c0453b8 */
if(!s->budget--) { s->failed_pc=0x0c0453b8u; return 0; }
write(ram,r[4]+9,r[0],1);
goto P_0c0453ba;
P_0c0453ba: /* original 6064, guest PC 0x0c0453ba */
if(!s->budget--) { s->failed_pc=0x0c0453bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]+=1;
r[0]=tmp;
goto P_0c0453bc;
P_0c0453bc: /* original 804a, guest PC 0x0c0453bc */
if(!s->budget--) { s->failed_pc=0x0c0453bcu; return 0; }
write(ram,r[4]+10,r[0],1);
goto P_0c0453be;
P_0c0453be: /* original 6060, guest PC 0x0c0453be */
if(!s->budget--) { s->failed_pc=0x0c0453beu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[0]=tmp;
goto P_0c0453c0;
P_0c0453c0: /* original 804b, guest PC 0x0c0453c0 */
if(!s->budget--) { s->failed_pc=0x0c0453c0u; return 0; }
write(ram,r[4]+11,r[0],1);
goto P_0c0453c2;
P_0c0453c2: /* original 8448, guest PC 0x0c0453c2 */
if(!s->budget--) { s->failed_pc=0x0c0453c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c0453c4;
P_0c0453c4: /* original 9340, guest PC 0x0c0453c4 */
if(!s->budget--) { s->failed_pc=0x0c0453c4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c045448u,2);
goto P_0c0453c6;
P_0c0453c6: /* original 600c, guest PC 0x0c0453c6 */
if(!s->budget--) { s->failed_pc=0x0c0453c6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0453c8;
P_0c0453c8: /* original 3030, guest PC 0x0c0453c8 */
if(!s->budget--) { s->failed_pc=0x0c0453c8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c0453ca;
P_0c0453ca: /* original 8b02, guest PC 0x0c0453ca */
if(!s->budget--) { s->failed_pc=0x0c0453cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0453d2; }
goto P_0c0453cc;
P_0c0453cc: /* original e1ff, guest PC 0x0c0453cc */
if(!s->budget--) { s->failed_pc=0x0c0453ccu; return 0; }
r[1]=0xffffffffu;
goto P_0c0453ce;
P_0c0453ce: /* original a008, guest PC 0x0c0453ce */
if(!s->budget--) { s->failed_pc=0x0c0453ceu; return 0; }
write(ram,r[4]+20,r[1],4);
goto P_0c0453e2;
P_0c0453d0: /* original 1415, guest PC 0x0c0453d0 */
if(!s->budget--) { s->failed_pc=0x0c0453d0u; return 0; }
write(ram,r[4]+20,r[1],4);
goto P_0c0453d2;
P_0c0453d2: /* original 923b, guest PC 0x0c0453d2 */
if(!s->budget--) { s->failed_pc=0x0c0453d2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04544cu,2);
goto P_0c0453d4;
P_0c0453d4: /* original 3023, guest PC 0x0c0453d4 */
if(!s->budget--) { s->failed_pc=0x0c0453d4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[2])!=0);
goto P_0c0453d6;
P_0c0453d6: /* original 8902, guest PC 0x0c0453d6 */
if(!s->budget--) { s->failed_pc=0x0c0453d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0453de; }
goto P_0c0453d8;
P_0c0453d8: /* original e000, guest PC 0x0c0453d8 */
if(!s->budget--) { s->failed_pc=0x0c0453d8u; return 0; }
r[0]=0x00000000u;
goto P_0c0453da;
P_0c0453da: /* original a002, guest PC 0x0c0453da */
if(!s->budget--) { s->failed_pc=0x0c0453dau; return 0; }
write(ram,r[4]+20,r[0],4);
goto P_0c0453e2;
P_0c0453dc: /* original 1405, guest PC 0x0c0453dc */
if(!s->budget--) { s->failed_pc=0x0c0453dcu; return 0; }
write(ram,r[4]+20,r[0],4);
goto P_0c0453de;
P_0c0453de: /* original 6152, guest PC 0x0c0453de */
if(!s->budget--) { s->failed_pc=0x0c0453deu; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c0453e0;
P_0c0453e0: /* original 1415, guest PC 0x0c0453e0 */
if(!s->budget--) { s->failed_pc=0x0c0453e0u; return 0; }
write(ram,r[4]+20,r[1],4);
goto P_0c0453e2;
P_0c0453e2: /* original e000, guest PC 0x0c0453e2 */
if(!s->budget--) { s->failed_pc=0x0c0453e2u; return 0; }
r[0]=0x00000000u;
goto P_0c0453e4;
P_0c0453e4: /* original 000b, guest PC 0x0c0453e4 */
if(!s->budget--) { s->failed_pc=0x0c0453e4u; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c0453e6: /* original 7f04, guest PC 0x0c0453e6 */
if(!s->budget--) { s->failed_pc=0x0c0453e6u; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c0453e8u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
