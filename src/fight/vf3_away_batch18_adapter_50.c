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
int vf3_away_batch18_adapter_50(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a81eeu: goto P_0c0a81ee;
case 0x0c0a81f0u: goto P_0c0a81f0;
case 0x0c0a81f2u: goto P_0c0a81f2;
case 0x0c0a81f4u: goto P_0c0a81f4;
case 0x0c0a81f6u: goto P_0c0a81f6;
case 0x0c0a81f8u: goto P_0c0a81f8;
case 0x0c0a81fau: goto P_0c0a81fa;
case 0x0c0a81fcu: goto P_0c0a81fc;
case 0x0c0a81feu: goto P_0c0a81fe;
case 0x0c0a8200u: goto P_0c0a8200;
case 0x0c0a8202u: goto P_0c0a8202;
case 0x0c0a8204u: goto P_0c0a8204;
case 0x0c0a8206u: goto P_0c0a8206;
case 0x0c0a8208u: goto P_0c0a8208;
case 0x0c0a820au: goto P_0c0a820a;
case 0x0c0a820cu: goto P_0c0a820c;
case 0x0c0a820eu: goto P_0c0a820e;
case 0x0c0a8210u: goto P_0c0a8210;
case 0x0c0a8212u: goto P_0c0a8212;
case 0x0c0a8214u: goto P_0c0a8214;
case 0x0c0a8216u: goto P_0c0a8216;
case 0x0c0a8218u: goto P_0c0a8218;
case 0x0c0a821au: goto P_0c0a821a;
case 0x0c0a821cu: goto P_0c0a821c;
case 0x0c0a821eu: goto P_0c0a821e;
case 0x0c0a8220u: goto P_0c0a8220;
case 0x0c0a8222u: goto P_0c0a8222;
case 0x0c0a8224u: goto P_0c0a8224;
case 0x0c0a8226u: goto P_0c0a8226;
case 0x0c0a8228u: goto P_0c0a8228;
case 0x0c0a822au: goto P_0c0a822a;
case 0x0c0a822cu: goto P_0c0a822c;
case 0x0c0a822eu: goto P_0c0a822e;
case 0x0c0a8230u: goto P_0c0a8230;
case 0x0c0a8232u: goto P_0c0a8232;
case 0x0c0a8234u: goto P_0c0a8234;
case 0x0c0a8236u: goto P_0c0a8236;
case 0x0c0a8238u: goto P_0c0a8238;
case 0x0c0a823au: goto P_0c0a823a;
case 0x0c0a823cu: goto P_0c0a823c;
case 0x0c0a823eu: goto P_0c0a823e;
case 0x0c0a8240u: goto P_0c0a8240;
case 0x0c0a8242u: goto P_0c0a8242;
case 0x0c0a8244u: goto P_0c0a8244;
case 0x0c0a8246u: goto P_0c0a8246;
case 0x0c0a8248u: goto P_0c0a8248;
case 0x0c0a824au: goto P_0c0a824a;
case 0x0c0a824cu: goto P_0c0a824c;
case 0x0c0a824eu: goto P_0c0a824e;
case 0x0c0a8250u: goto P_0c0a8250;
case 0x0c0a8252u: goto P_0c0a8252;
case 0x0c0a8254u: goto P_0c0a8254;
case 0x0c0a8256u: goto P_0c0a8256;
case 0x0c0a8258u: goto P_0c0a8258;
case 0x0c0a825au: goto P_0c0a825a;
case 0x0c0a825cu: goto P_0c0a825c;
case 0x0c0a825eu: goto P_0c0a825e;
case 0x0c0a8260u: goto P_0c0a8260;
case 0x0c0a8262u: goto P_0c0a8262;
case 0x0c0a8264u: goto P_0c0a8264;
case 0x0c0a8266u: goto P_0c0a8266;
case 0x0c0a8268u: goto P_0c0a8268;
case 0x0c0a826au: goto P_0c0a826a;
case 0x0c0a826cu: goto P_0c0a826c;
case 0x0c0a826eu: goto P_0c0a826e;
case 0x0c0a8270u: goto P_0c0a8270;
case 0x0c0a8272u: goto P_0c0a8272;
case 0x0c0a8274u: goto P_0c0a8274;
case 0x0c0a8276u: goto P_0c0a8276;
case 0x0c0a8278u: goto P_0c0a8278;
case 0x0c0a827au: goto P_0c0a827a;
case 0x0c0a827cu: goto P_0c0a827c;
case 0x0c0a827eu: goto P_0c0a827e;
case 0x0c0a8280u: goto P_0c0a8280;
case 0x0c0a8282u: goto P_0c0a8282;
case 0x0c0a8284u: goto P_0c0a8284;
case 0x0c0a8286u: goto P_0c0a8286;
case 0x0c0a8288u: goto P_0c0a8288;
case 0x0c0a828au: goto P_0c0a828a;
case 0x0c0a828cu: goto P_0c0a828c;
case 0x0c0a828eu: goto P_0c0a828e;
case 0x0c0a8290u: goto P_0c0a8290;
case 0x0c0a8292u: goto P_0c0a8292;
case 0x0c0a8294u: goto P_0c0a8294;
case 0x0c0a8296u: goto P_0c0a8296;
case 0x0c0a8298u: goto P_0c0a8298;
case 0x0c0a829au: goto P_0c0a829a;
case 0x0c0a82c0u: goto P_0c0a82c0;
case 0x0c0a82c2u: goto P_0c0a82c2;
case 0x0c0a82c4u: goto P_0c0a82c4;
case 0x0c0a82c6u: goto P_0c0a82c6;
case 0x0c0a82c8u: goto P_0c0a82c8;
case 0x0c0a82cau: goto P_0c0a82ca;
case 0x0c0a82ccu: goto P_0c0a82cc;
case 0x0c0a82ceu: goto P_0c0a82ce;
case 0x0c0a82d0u: goto P_0c0a82d0;
case 0x0c0a82d2u: goto P_0c0a82d2;
case 0x0c0a82d4u: goto P_0c0a82d4;
case 0x0c0a82d6u: goto P_0c0a82d6;
case 0x0c0a82d8u: goto P_0c0a82d8;
case 0x0c0a82dau: goto P_0c0a82da;
case 0x0c0a82dcu: goto P_0c0a82dc;
case 0x0c0a82deu: goto P_0c0a82de;
case 0x0c0a82e0u: goto P_0c0a82e0;
case 0x0c0a82e2u: goto P_0c0a82e2;
case 0x0c0a82e4u: goto P_0c0a82e4;
case 0x0c0a82e6u: goto P_0c0a82e6;
case 0x0c0a82e8u: goto P_0c0a82e8;
case 0x0c0a82eau: goto P_0c0a82ea;
case 0x0c0a82ecu: goto P_0c0a82ec;
case 0x0c0a82eeu: goto P_0c0a82ee;
case 0x0c0a82f0u: goto P_0c0a82f0;
case 0x0c0a82f2u: goto P_0c0a82f2;
case 0x0c0a82f4u: goto P_0c0a82f4;
case 0x0c0a82f6u: goto P_0c0a82f6;
case 0x0c0a82f8u: goto P_0c0a82f8;
case 0x0c0a82fau: goto P_0c0a82fa;
case 0x0c0a82fcu: goto P_0c0a82fc;
case 0x0c0a82feu: goto P_0c0a82fe;
case 0x0c0a8300u: goto P_0c0a8300;
case 0x0c0a8302u: goto P_0c0a8302;
case 0x0c0a8304u: goto P_0c0a8304;
case 0x0c0a8306u: goto P_0c0a8306;
case 0x0c0a8308u: goto P_0c0a8308;
case 0x0c0a830au: goto P_0c0a830a;
case 0x0c0a830cu: goto P_0c0a830c;
case 0x0c0a830eu: goto P_0c0a830e;
case 0x0c0a8310u: goto P_0c0a8310;
case 0x0c0a8312u: goto P_0c0a8312;
case 0x0c0a8314u: goto P_0c0a8314;
case 0x0c0a8316u: goto P_0c0a8316;
case 0x0c0a8318u: goto P_0c0a8318;
case 0x0c0a831au: goto P_0c0a831a;
case 0x0c0a831cu: goto P_0c0a831c;
case 0x0c0a831eu: goto P_0c0a831e;
case 0x0c0a8320u: goto P_0c0a8320;
case 0x0c0a8322u: goto P_0c0a8322;
case 0x0c0a8324u: goto P_0c0a8324;
case 0x0c0a8326u: goto P_0c0a8326;
case 0x0c0a8328u: goto P_0c0a8328;
case 0x0c0a832au: goto P_0c0a832a;
case 0x0c0a832cu: goto P_0c0a832c;
case 0x0c0a832eu: goto P_0c0a832e;
case 0x0c0a8330u: goto P_0c0a8330;
case 0x0c0a8332u: goto P_0c0a8332;
case 0x0c0a8334u: goto P_0c0a8334;
case 0x0c0a8336u: goto P_0c0a8336;
case 0x0c0a8338u: goto P_0c0a8338;
case 0x0c0a833au: goto P_0c0a833a;
case 0x0c0a833cu: goto P_0c0a833c;
case 0x0c0a833eu: goto P_0c0a833e;
case 0x0c0a8340u: goto P_0c0a8340;
case 0x0c0a8342u: goto P_0c0a8342;
case 0x0c0a8344u: goto P_0c0a8344;
case 0x0c0a8346u: goto P_0c0a8346;
case 0x0c0a8348u: goto P_0c0a8348;
case 0x0c0a834au: goto P_0c0a834a;
case 0x0c0a834cu: goto P_0c0a834c;
case 0x0c0a834eu: goto P_0c0a834e;
case 0x0c0a8350u: goto P_0c0a8350;
case 0x0c0a8352u: goto P_0c0a8352;
case 0x0c0a8354u: goto P_0c0a8354;
case 0x0c0a86acu: goto P_0c0a86ac;
case 0x0c0a86aeu: goto P_0c0a86ae;
case 0x0c0a86b0u: goto P_0c0a86b0;
case 0x0c0a86b2u: goto P_0c0a86b2;
case 0x0c0a86b4u: goto P_0c0a86b4;
case 0x0c0a86b6u: goto P_0c0a86b6;
case 0x0c0a86b8u: goto P_0c0a86b8;
case 0x0c0a86bau: goto P_0c0a86ba;
case 0x0c0a86bcu: goto P_0c0a86bc;
case 0x0c0a86beu: goto P_0c0a86be;
case 0x0c0a86c0u: goto P_0c0a86c0;
case 0x0c0a86c2u: goto P_0c0a86c2;
case 0x0c0a86c4u: goto P_0c0a86c4;
case 0x0c0a86c6u: goto P_0c0a86c6;
case 0x0c0a86c8u: goto P_0c0a86c8;
case 0x0c0a86cau: goto P_0c0a86ca;
case 0x0c0a86ccu: goto P_0c0a86cc;
case 0x0c0a86ceu: goto P_0c0a86ce;
case 0x0c0a86d0u: goto P_0c0a86d0;
case 0x0c0a86d2u: goto P_0c0a86d2;
case 0x0c0a86d4u: goto P_0c0a86d4;
case 0x0c0a86d6u: goto P_0c0a86d6;
case 0x0c0a86d8u: goto P_0c0a86d8;
case 0x0c0a86dau: goto P_0c0a86da;
case 0x0c0a86dcu: goto P_0c0a86dc;
case 0x0c0a86deu: goto P_0c0a86de;
case 0x0c0a86e0u: goto P_0c0a86e0;
case 0x0c0a86e2u: goto P_0c0a86e2;
case 0x0c0a86e4u: goto P_0c0a86e4;
case 0x0c0a86e6u: goto P_0c0a86e6;
case 0x0c0a86e8u: goto P_0c0a86e8;
case 0x0c0a86eau: goto P_0c0a86ea;
case 0x0c0a86ecu: goto P_0c0a86ec;
case 0x0c0a86eeu: goto P_0c0a86ee;
case 0x0c0a86f0u: goto P_0c0a86f0;
case 0x0c0a86f2u: goto P_0c0a86f2;
case 0x0c0a86f4u: goto P_0c0a86f4;
case 0x0c0a86f6u: goto P_0c0a86f6;
case 0x0c0a86f8u: goto P_0c0a86f8;
case 0x0c0a86fau: goto P_0c0a86fa;
case 0x0c0a86fcu: goto P_0c0a86fc;
case 0x0c0a86feu: goto P_0c0a86fe;
case 0x0c0a8700u: goto P_0c0a8700;
case 0x0c0a8702u: goto P_0c0a8702;
case 0x0c0a8704u: goto P_0c0a8704;
case 0x0c0a8706u: goto P_0c0a8706;
case 0x0c0a8708u: goto P_0c0a8708;
case 0x0c0a870au: goto P_0c0a870a;
case 0x0c0a870cu: goto P_0c0a870c;
case 0x0c0a870eu: goto P_0c0a870e;
case 0x0c0a8710u: goto P_0c0a8710;
case 0x0c0a8712u: goto P_0c0a8712;
case 0x0c0a8714u: goto P_0c0a8714;
case 0x0c0a8716u: goto P_0c0a8716;
case 0x0c0a8718u: goto P_0c0a8718;
case 0x0c0a871au: goto P_0c0a871a;
case 0x0c0a871cu: goto P_0c0a871c;
case 0x0c0a871eu: goto P_0c0a871e;
case 0x0c0a8720u: goto P_0c0a8720;
case 0x0c0a8722u: goto P_0c0a8722;
case 0x0c0a8724u: goto P_0c0a8724;
case 0x0c0a8726u: goto P_0c0a8726;
case 0x0c0a8728u: goto P_0c0a8728;
case 0x0c0a872au: goto P_0c0a872a;
case 0x0c0a872cu: goto P_0c0a872c;
case 0x0c0a872eu: goto P_0c0a872e;
case 0x0c0a8730u: goto P_0c0a8730;
case 0x0c0a8732u: goto P_0c0a8732;
case 0x0c0a8734u: goto P_0c0a8734;
case 0x0c0a8736u: goto P_0c0a8736;
case 0x0c0a8738u: goto P_0c0a8738;
case 0x0c0a873au: goto P_0c0a873a;
case 0x0c0a873cu: goto P_0c0a873c;
case 0x0c0a873eu: goto P_0c0a873e;
case 0x0c0a8740u: goto P_0c0a8740;
case 0x0c0a8742u: goto P_0c0a8742;
case 0x0c0a8744u: goto P_0c0a8744;
case 0x0c0a8746u: goto P_0c0a8746;
case 0x0c0a8748u: goto P_0c0a8748;
case 0x0c0a874au: goto P_0c0a874a;
case 0x0c0a874cu: goto P_0c0a874c;
case 0x0c0a874eu: goto P_0c0a874e;
case 0x0c0a8750u: goto P_0c0a8750;
case 0x0c0a8752u: goto P_0c0a8752;
case 0x0c0a8754u: goto P_0c0a8754;
case 0x0c0a8756u: goto P_0c0a8756;
case 0x0c0a8758u: goto P_0c0a8758;
case 0x0c0a875au: goto P_0c0a875a;
case 0x0c0a875cu: goto P_0c0a875c;
case 0x0c0a875eu: goto P_0c0a875e;
case 0x0c0a8760u: goto P_0c0a8760;
case 0x0c0a8762u: goto P_0c0a8762;
case 0x0c0a8764u: goto P_0c0a8764;
case 0x0c0a8766u: goto P_0c0a8766;
case 0x0c0a8768u: goto P_0c0a8768;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a81ee: /* original 2fe6, guest PC 0x0c0a81ee */
if(!s->budget--) { s->failed_pc=0x0c0a81eeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f0;
P_0c0a81f0: /* original 2fd6, guest PC 0x0c0a81f0 */
if(!s->budget--) { s->failed_pc=0x0c0a81f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f2;
P_0c0a81f2: /* original 2fc6, guest PC 0x0c0a81f2 */
if(!s->budget--) { s->failed_pc=0x0c0a81f2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f4;
P_0c0a81f4: /* original 2fb6, guest PC 0x0c0a81f4 */
if(!s->budget--) { s->failed_pc=0x0c0a81f4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81f6;
P_0c0a81f6: /* original 6b43, guest PC 0x0c0a81f6 */
if(!s->budget--) { s->failed_pc=0x0c0a81f6u; return 0; }
r[11]=r[4];
goto P_0c0a81f8;
P_0c0a81f8: /* original 2fa6, guest PC 0x0c0a81f8 */
if(!s->budget--) { s->failed_pc=0x0c0a81f8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a81fa;
P_0c0a81fa: /* original eaff, guest PC 0x0c0a81fa */
if(!s->budget--) { s->failed_pc=0x0c0a81fau; return 0; }
r[10]=0xffffffffu;
goto P_0c0a81fc;
P_0c0a81fc: /* original 4f22, guest PC 0x0c0a81fc */
if(!s->budget--) { s->failed_pc=0x0c0a81fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a81fe;
P_0c0a81fe: /* original 4f12, guest PC 0x0c0a81fe */
if(!s->budget--) { s->failed_pc=0x0c0a81feu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a8200;
P_0c0a8200: /* original 7ff0, guest PC 0x0c0a8200 */
if(!s->budget--) { s->failed_pc=0x0c0a8200u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a8202;
P_0c0a8202: /* original 1f51, guest PC 0x0c0a8202 */
if(!s->budget--) { s->failed_pc=0x0c0a8202u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0a8204;
P_0c0a8204: /* original 2f62, guest PC 0x0c0a8204 */
if(!s->budget--) { s->failed_pc=0x0c0a8204u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0a8206;
P_0c0a8206: /* original 1f72, guest PC 0x0c0a8206 */
if(!s->budget--) { s->failed_pc=0x0c0a8206u; return 0; }
write(ram,r[15]+8,r[7],4);
goto P_0c0a8208;
P_0c0a8208: /* original d32a, guest PC 0x0c0a8208 */
if(!s->budget--) { s->failed_pc=0x0c0a8208u; return 0; }
r[3]=read(ram,0x0c0a82b4u,4);
goto P_0c0a820a;
P_0c0a820a: /* original 9249, guest PC 0x0c0a820a */
if(!s->budget--) { s->failed_pc=0x0c0a820au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a82a0u,2);
goto P_0c0a820c;
P_0c0a820c: /* original 6e32, guest PC 0x0c0a820c */
if(!s->budget--) { s->failed_pc=0x0c0a820cu; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c0a820e;
P_0c0a820e: /* original 3b23, guest PC 0x0c0a820e */
if(!s->budget--) { s->failed_pc=0x0c0a820eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[2])!=0);
goto P_0c0a8210;
P_0c0a8210: /* original 8f03, guest PC 0x0c0a8210 */
if(!s->budget--) { s->failed_pc=0x0c0a8210u; return 0; }
cond=r[17]&1u;
r[12]=r[10];
if(!cond) { goto P_0c0a821a; }
goto P_0c0a8214;
P_0c0a8212: /* original 6ca3, guest PC 0x0c0a8212 */
if(!s->budget--) { s->failed_pc=0x0c0a8212u; return 0; }
r[12]=r[10];
goto P_0c0a8214;
P_0c0a8214: /* original dc28, guest PC 0x0c0a8214 */
if(!s->budget--) { s->failed_pc=0x0c0a8214u; return 0; }
r[12]=read(ram,0x0c0a82b8u,4);
goto P_0c0a8216;
P_0c0a8216: /* original a037, guest PC 0x0c0a8216 */
if(!s->budget--) { s->failed_pc=0x0c0a8216u; return 0; }
goto P_0c0a8288;
P_0c0a8218: /* original 0009, guest PC 0x0c0a8218 */
if(!s->budget--) { s->failed_pc=0x0c0a8218u; return 0; }
goto P_0c0a821a;
P_0c0a821a: /* original d028, guest PC 0x0c0a821a */
if(!s->budget--) { s->failed_pc=0x0c0a821au; return 0; }
r[0]=read(ram,0x0c0a82bcu,4);
goto P_0c0a821c;
P_0c0a821c: /* original 63b3, guest PC 0x0c0a821c */
if(!s->budget--) { s->failed_pc=0x0c0a821cu; return 0; }
r[3]=r[11];
goto P_0c0a821e;
P_0c0a821e: /* original 4308, guest PC 0x0c0a821e */
if(!s->budget--) { s->failed_pc=0x0c0a821eu; return 0; }
r[3]<<=2;
goto P_0c0a8220;
P_0c0a8220: /* original 023e, guest PC 0x0c0a8220 */
if(!s->budget--) { s->failed_pc=0x0c0a8220u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0a8222;
P_0c0a8222: /* original 1f23, guest PC 0x0c0a8222 */
if(!s->budget--) { s->failed_pc=0x0c0a8222u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0a8224;
P_0c0a8224: /* original 63f2, guest PC 0x0c0a8224 */
if(!s->budget--) { s->failed_pc=0x0c0a8224u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a8226;
P_0c0a8226: /* original 2338, guest PC 0x0c0a8226 */
if(!s->budget--) { s->failed_pc=0x0c0a8226u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a8228;
P_0c0a8228: /* original 892e, guest PC 0x0c0a8228 */
if(!s->budget--) { s->failed_pc=0x0c0a8228u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8288; }
goto P_0c0a822a;
P_0c0a822a: /* original 50f1, guest PC 0x0c0a822a */
if(!s->budget--) { s->failed_pc=0x0c0a822au; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0a822c;
P_0c0a822c: /* original c803, guest PC 0x0c0a822c */
if(!s->budget--) { s->failed_pc=0x0c0a822cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&3u)==0)!=0);
goto P_0c0a822e;
P_0c0a822e: /* original 8b2b, guest PC 0x0c0a822e */
if(!s->budget--) { s->failed_pc=0x0c0a822eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8288; }
goto P_0c0a8230;
P_0c0a8230: /* original 85ed, guest PC 0x0c0a8230 */
if(!s->budget--) { s->failed_pc=0x0c0a8230u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+26,2);
goto P_0c0a8232;
P_0c0a8232: /* original ed1f, guest PC 0x0c0a8232 */
if(!s->budget--) { s->failed_pc=0x0c0a8232u; return 0; }
r[13]=0x0000001fu;
goto P_0c0a8234;
P_0c0a8234: /* original 600d, guest PC 0x0c0a8234 */
if(!s->budget--) { s->failed_pc=0x0c0a8234u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a8236;
P_0c0a8236: /* original 7001, guest PC 0x0c0a8236 */
if(!s->budget--) { s->failed_pc=0x0c0a8236u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a8238;
P_0c0a8238: /* original 2d09, guest PC 0x0c0a8238 */
if(!s->budget--) { s->failed_pc=0x0c0a8238u; return 0; }
r[13]&=r[0];
goto P_0c0a823a;
P_0c0a823a: /* original 85eb, guest PC 0x0c0a823a */
if(!s->budget--) { s->failed_pc=0x0c0a823au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a823c;
P_0c0a823c: /* original 600d, guest PC 0x0c0a823c */
if(!s->budget--) { s->failed_pc=0x0c0a823cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a823e;
P_0c0a823e: /* original 3d00, guest PC 0x0c0a823e */
if(!s->budget--) { s->failed_pc=0x0c0a823eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[0])!=0);
goto P_0c0a8240;
P_0c0a8240: /* original 8922, guest PC 0x0c0a8240 */
if(!s->budget--) { s->failed_pc=0x0c0a8240u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8288; }
goto P_0c0a8242;
P_0c0a8242: /* original be67, guest PC 0x0c0a8242 */
if(!s->budget--) { s->failed_pc=0x0c0a8242u; return 0; }
target=code_base|0x0c0a7f14u; r[16]=code_base|0x0c0a8246u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8246u) { target=s->pc; goto dispatch; }
goto P_0c0a8246;
P_0c0a8244: /* original 64b3, guest PC 0x0c0a8244 */
if(!s->budget--) { s->failed_pc=0x0c0a8244u; return 0; }
r[4]=r[11];
goto P_0c0a8246;
P_0c0a8246: /* original 2008, guest PC 0x0c0a8246 */
if(!s->budget--) { s->failed_pc=0x0c0a8246u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8248;
P_0c0a8248: /* original 8b1e, guest PC 0x0c0a8248 */
if(!s->budget--) { s->failed_pc=0x0c0a8248u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8288; }
goto P_0c0a824a;
P_0c0a824a: /* original e434, guest PC 0x0c0a824a */
if(!s->budget--) { s->failed_pc=0x0c0a824au; return 0; }
r[4]=0x00000034u;
goto P_0c0a824c;
P_0c0a824c: /* original 63e3, guest PC 0x0c0a824c */
if(!s->budget--) { s->failed_pc=0x0c0a824cu; return 0; }
r[3]=r[14];
goto P_0c0a824e;
P_0c0a824e: /* original 2d4f, guest PC 0x0c0a824e */
if(!s->budget--) { s->failed_pc=0x0c0a824eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[4]);
goto P_0c0a8250;
P_0c0a8250: /* original 731c, guest PC 0x0c0a8250 */
if(!s->budget--) { s->failed_pc=0x0c0a8250u; return 0; }
r[3]+=0x0000001cu;
goto P_0c0a8252;
P_0c0a8252: /* original 60d3, guest PC 0x0c0a8252 */
if(!s->budget--) { s->failed_pc=0x0c0a8252u; return 0; }
r[0]=r[13];
goto P_0c0a8254;
P_0c0a8254: /* original 81ed, guest PC 0x0c0a8254 */
if(!s->budget--) { s->failed_pc=0x0c0a8254u; return 0; }
write(ram,r[14]+26,r[0],2);
goto P_0c0a8256;
P_0c0a8256: /* original e030, guest PC 0x0c0a8256 */
if(!s->budget--) { s->failed_pc=0x0c0a8256u; return 0; }
r[0]=0x00000030u;
goto P_0c0a8258;
P_0c0a8258: /* original 62f2, guest PC 0x0c0a8258 */
if(!s->budget--) { s->failed_pc=0x0c0a8258u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a825a;
P_0c0a825a: /* original 6cd3, guest PC 0x0c0a825a */
if(!s->budget--) { s->failed_pc=0x0c0a825au; return 0; }
r[12]=r[13];
goto P_0c0a825c;
P_0c0a825c: /* original 041a, guest PC 0x0c0a825c */
if(!s->budget--) { s->failed_pc=0x0c0a825cu; return 0; }
r[4]=r[19];
goto P_0c0a825e;
P_0c0a825e: /* original 644f, guest PC 0x0c0a825e */
if(!s->budget--) { s->failed_pc=0x0c0a825eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0a8260;
P_0c0a8260: /* original 343c, guest PC 0x0c0a8260 */
if(!s->budget--) { s->failed_pc=0x0c0a8260u; return 0; }
r[4]+=r[3];
goto P_0c0a8262;
P_0c0a8262: /* original 6323, guest PC 0x0c0a8262 */
if(!s->budget--) { s->failed_pc=0x0c0a8262u; return 0; }
r[3]=r[2];
goto P_0c0a8264;
P_0c0a8264: /* original 2422, guest PC 0x0c0a8264 */
if(!s->budget--) { s->failed_pc=0x0c0a8264u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0a8266;
P_0c0a8266: /* original e200, guest PC 0x0c0a8266 */
if(!s->budget--) { s->failed_pc=0x0c0a8266u; return 0; }
r[2]=0x00000000u;
goto P_0c0a8268;
P_0c0a8268: /* original 2322, guest PC 0x0c0a8268 */
if(!s->budget--) { s->failed_pc=0x0c0a8268u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0a826a;
P_0c0a826a: /* original 53f1, guest PC 0x0c0a826a */
if(!s->budget--) { s->failed_pc=0x0c0a826au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a826c;
P_0c0a826c: /* original 1431, guest PC 0x0c0a826c */
if(!s->budget--) { s->failed_pc=0x0c0a826cu; return 0; }
write(ram,r[4]+4,r[3],4);
goto P_0c0a826e;
P_0c0a826e: /* original 14a7, guest PC 0x0c0a826e */
if(!s->budget--) { s->failed_pc=0x0c0a826eu; return 0; }
write(ram,r[4]+28,r[10],4);
goto P_0c0a8270;
P_0c0a8270: /* original 14a2, guest PC 0x0c0a8270 */
if(!s->budget--) { s->failed_pc=0x0c0a8270u; return 0; }
write(ram,r[4]+8,r[10],4);
goto P_0c0a8272;
P_0c0a8272: /* original 53f3, guest PC 0x0c0a8272 */
if(!s->budget--) { s->failed_pc=0x0c0a8272u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0a8274;
P_0c0a8274: /* original 1434, guest PC 0x0c0a8274 */
if(!s->budget--) { s->failed_pc=0x0c0a8274u; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c0a8276;
P_0c0a8276: /* original 52f2, guest PC 0x0c0a8276 */
if(!s->budget--) { s->failed_pc=0x0c0a8276u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0a8278;
P_0c0a8278: /* original 1425, guest PC 0x0c0a8278 */
if(!s->budget--) { s->failed_pc=0x0c0a8278u; return 0; }
write(ram,r[4]+20,r[2],4);
goto P_0c0a827a;
P_0c0a827a: /* original 53fb, guest PC 0x0c0a827a */
if(!s->budget--) { s->failed_pc=0x0c0a827au; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c0a827c;
P_0c0a827c: /* original 1436, guest PC 0x0c0a827c */
if(!s->budget--) { s->failed_pc=0x0c0a827cu; return 0; }
write(ram,r[4]+24,r[3],4);
goto P_0c0a827e;
P_0c0a827e: /* original 52fc, guest PC 0x0c0a827e */
if(!s->budget--) { s->failed_pc=0x0c0a827eu; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c0a8280;
P_0c0a8280: /* original 142a, guest PC 0x0c0a8280 */
if(!s->budget--) { s->failed_pc=0x0c0a8280u; return 0; }
write(ram,r[4]+40,r[2],4);
goto P_0c0a8282;
P_0c0a8282: /* original 53fd, guest PC 0x0c0a8282 */
if(!s->budget--) { s->failed_pc=0x0c0a8282u; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c0a8284;
P_0c0a8284: /* original 143b, guest PC 0x0c0a8284 */
if(!s->budget--) { s->failed_pc=0x0c0a8284u; return 0; }
write(ram,r[4]+44,r[3],4);
goto P_0c0a8286;
P_0c0a8286: /* original 04b5, guest PC 0x0c0a8286 */
if(!s->budget--) { s->failed_pc=0x0c0a8286u; return 0; }
write(ram,r[4]+r[0],r[11],2);
goto P_0c0a8288;
P_0c0a8288: /* original 7f10, guest PC 0x0c0a8288 */
if(!s->budget--) { s->failed_pc=0x0c0a8288u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a828a;
P_0c0a828a: /* original 60c3, guest PC 0x0c0a828a */
if(!s->budget--) { s->failed_pc=0x0c0a828au; return 0; }
r[0]=r[12];
goto P_0c0a828c;
P_0c0a828c: /* original 4f16, guest PC 0x0c0a828c */
if(!s->budget--) { s->failed_pc=0x0c0a828cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a828e;
P_0c0a828e: /* original 4f26, guest PC 0x0c0a828e */
if(!s->budget--) { s->failed_pc=0x0c0a828eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8290;
P_0c0a8290: /* original 6af6, guest PC 0x0c0a8290 */
if(!s->budget--) { s->failed_pc=0x0c0a8290u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8292;
P_0c0a8292: /* original 6bf6, guest PC 0x0c0a8292 */
if(!s->budget--) { s->failed_pc=0x0c0a8292u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8294;
P_0c0a8294: /* original 6cf6, guest PC 0x0c0a8294 */
if(!s->budget--) { s->failed_pc=0x0c0a8294u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8296;
P_0c0a8296: /* original 6df6, guest PC 0x0c0a8296 */
if(!s->budget--) { s->failed_pc=0x0c0a8296u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8298;
P_0c0a8298: /* original 000b, guest PC 0x0c0a8298 */
if(!s->budget--) { s->failed_pc=0x0c0a8298u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a829a: /* original 6ef6, guest PC 0x0c0a829a */
if(!s->budget--) { s->failed_pc=0x0c0a829au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a829cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a829cu; return 0; } return 1;
P_0c0a82c0: /* original 2fe6, guest PC 0x0c0a82c0 */
if(!s->budget--) { s->failed_pc=0x0c0a82c0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a82c2;
P_0c0a82c2: /* original 2fd6, guest PC 0x0c0a82c2 */
if(!s->budget--) { s->failed_pc=0x0c0a82c2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a82c4;
P_0c0a82c4: /* original 2fc6, guest PC 0x0c0a82c4 */
if(!s->budget--) { s->failed_pc=0x0c0a82c4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a82c6;
P_0c0a82c6: /* original d324, guest PC 0x0c0a82c6 */
if(!s->budget--) { s->failed_pc=0x0c0a82c6u; return 0; }
r[3]=read(ram,0x0c0a8358u,4);
goto P_0c0a82c8;
P_0c0a82c8: /* original 4f22, guest PC 0x0c0a82c8 */
if(!s->budget--) { s->failed_pc=0x0c0a82c8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a82ca;
P_0c0a82ca: /* original 6e32, guest PC 0x0c0a82ca */
if(!s->budget--) { s->failed_pc=0x0c0a82cau; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c0a82cc;
P_0c0a82cc: /* original d223, guest PC 0x0c0a82cc */
if(!s->budget--) { s->failed_pc=0x0c0a82ccu; return 0; }
r[2]=read(ram,0x0c0a835cu,4);
goto P_0c0a82ce;
P_0c0a82ce: /* original 61e2, guest PC 0x0c0a82ce */
if(!s->budget--) { s->failed_pc=0x0c0a82ceu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0a82d0;
P_0c0a82d0: /* original 4f12, guest PC 0x0c0a82d0 */
if(!s->budget--) { s->failed_pc=0x0c0a82d0u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a82d2;
P_0c0a82d2: /* original 2128, guest PC 0x0c0a82d2 */
if(!s->budget--) { s->failed_pc=0x0c0a82d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0a82d4;
P_0c0a82d4: /* original 8934, guest PC 0x0c0a82d4 */
if(!s->budget--) { s->failed_pc=0x0c0a82d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8340; }
goto P_0c0a82d6;
P_0c0a82d6: /* original 85eb, guest PC 0x0c0a82d6 */
if(!s->budget--) { s->failed_pc=0x0c0a82d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a82d8;
P_0c0a82d8: /* original ed34, guest PC 0x0c0a82d8 */
if(!s->budget--) { s->failed_pc=0x0c0a82d8u; return 0; }
r[13]=0x00000034u;
goto P_0c0a82da;
P_0c0a82da: /* original 61e3, guest PC 0x0c0a82da */
if(!s->budget--) { s->failed_pc=0x0c0a82dau; return 0; }
r[1]=r[14];
goto P_0c0a82dc;
P_0c0a82dc: /* original 711c, guest PC 0x0c0a82dc */
if(!s->budget--) { s->failed_pc=0x0c0a82dcu; return 0; }
r[1]+=0x0000001cu;
goto P_0c0a82de;
P_0c0a82de: /* original 20df, guest PC 0x0c0a82de */
if(!s->budget--) { s->failed_pc=0x0c0a82deu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[0]*(int32_t)(int16_t)r[13]);
goto P_0c0a82e0;
P_0c0a82e0: /* original 0d1a, guest PC 0x0c0a82e0 */
if(!s->budget--) { s->failed_pc=0x0c0a82e0u; return 0; }
r[13]=r[19];
goto P_0c0a82e2;
P_0c0a82e2: /* original 6ddf, guest PC 0x0c0a82e2 */
if(!s->budget--) { s->failed_pc=0x0c0a82e2u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c0a82e4;
P_0c0a82e4: /* original 3d1c, guest PC 0x0c0a82e4 */
if(!s->budget--) { s->failed_pc=0x0c0a82e4u; return 0; }
r[13]+=r[1];
goto P_0c0a82e6;
P_0c0a82e6: /* original d11e, guest PC 0x0c0a82e6 */
if(!s->budget--) { s->failed_pc=0x0c0a82e6u; return 0; }
r[1]=read(ram,0x0c0a8360u,4);
goto P_0c0a82e8;
P_0c0a82e8: /* original 410b, guest PC 0x0c0a82e8 */
if(!s->budget--) { s->failed_pc=0x0c0a82e8u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a82ecu;
r[4]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a82ecu) { target=s->pc; goto dispatch; }
goto P_0c0a82ec;
P_0c0a82ea: /* original 54d3, guest PC 0x0c0a82ea */
if(!s->budget--) { s->failed_pc=0x0c0a82eau; return 0; }
r[4]=read(ram,r[13]+12,4);
goto P_0c0a82ec;
P_0c0a82ec: /* original dc1d, guest PC 0x0c0a82ec */
if(!s->budget--) { s->failed_pc=0x0c0a82ecu; return 0; }
r[12]=read(ram,0x0c0a8364u,4);
goto P_0c0a82ee;
P_0c0a82ee: /* original 4c0b, guest PC 0x0c0a82ee */
if(!s->budget--) { s->failed_pc=0x0c0a82eeu; return 0; }
target=r[12];
r[16]=code_base|0x0c0a82f2u;
r[4]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a82f2u) { target=s->pc; goto dispatch; }
goto P_0c0a82f2;
P_0c0a82f0: /* original 54d3, guest PC 0x0c0a82f0 */
if(!s->budget--) { s->failed_pc=0x0c0a82f0u; return 0; }
r[4]=read(ram,r[13]+12,4);
goto P_0c0a82f2;
P_0c0a82f2: /* original 8802, guest PC 0x0c0a82f2 */
if(!s->budget--) { s->failed_pc=0x0c0a82f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a82f4;
P_0c0a82f4: /* original 8dfb, guest PC 0x0c0a82f4 */
if(!s->budget--) { s->failed_pc=0x0c0a82f4u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0a82ee; }
goto P_0c0a82f8;
P_0c0a82f6: /* original 6403, guest PC 0x0c0a82f6 */
if(!s->budget--) { s->failed_pc=0x0c0a82f6u; return 0; }
r[4]=r[0];
goto P_0c0a82f8;
P_0c0a82f8: /* original 53d5, guest PC 0x0c0a82f8 */
if(!s->budget--) { s->failed_pc=0x0c0a82f8u; return 0; }
r[3]=read(ram,r[13]+20,4);
goto P_0c0a82fa;
P_0c0a82fa: /* original 2338, guest PC 0x0c0a82fa */
if(!s->budget--) { s->failed_pc=0x0c0a82fau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a82fc;
P_0c0a82fc: /* original 8904, guest PC 0x0c0a82fc */
if(!s->budget--) { s->failed_pc=0x0c0a82fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8308; }
goto P_0c0a82fe;
P_0c0a82fe: /* original 53d5, guest PC 0x0c0a82fe */
if(!s->budget--) { s->failed_pc=0x0c0a82feu; return 0; }
r[3]=read(ram,r[13]+20,4);
goto P_0c0a8300;
P_0c0a8300: /* original e5ff, guest PC 0x0c0a8300 */
if(!s->budget--) { s->failed_pc=0x0c0a8300u; return 0; }
r[5]=0xffffffffu;
goto P_0c0a8302;
P_0c0a8302: /* original 430b, guest PC 0x0c0a8302 */
if(!s->budget--) { s->failed_pc=0x0c0a8302u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8306u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8306u) { target=s->pc; goto dispatch; }
goto P_0c0a8306;
P_0c0a8304: /* original 64d3, guest PC 0x0c0a8304 */
if(!s->budget--) { s->failed_pc=0x0c0a8304u; return 0; }
r[4]=r[13];
goto P_0c0a8306;
P_0c0a8306: /* original 2008, guest PC 0x0c0a8306 */
if(!s->budget--) { s->failed_pc=0x0c0a8306u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8308;
P_0c0a8308: /* original d317, guest PC 0x0c0a8308 */
if(!s->budget--) { s->failed_pc=0x0c0a8308u; return 0; }
r[3]=read(ram,0x0c0a8368u,4);
goto P_0c0a830a;
P_0c0a830a: /* original 430b, guest PC 0x0c0a830a */
if(!s->budget--) { s->failed_pc=0x0c0a830au; return 0; }
target=r[3];
r[16]=code_base|0x0c0a830eu;
r[4]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a830eu) { target=s->pc; goto dispatch; }
goto P_0c0a830e;
P_0c0a830c: /* original 54d3, guest PC 0x0c0a830c */
if(!s->budget--) { s->failed_pc=0x0c0a830cu; return 0; }
r[4]=read(ram,r[13]+12,4);
goto P_0c0a830e;
P_0c0a830e: /* original 62e2, guest PC 0x0c0a830e */
if(!s->budget--) { s->failed_pc=0x0c0a830eu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0a8310;
P_0c0a8310: /* original d316, guest PC 0x0c0a8310 */
if(!s->budget--) { s->failed_pc=0x0c0a8310u; return 0; }
r[3]=read(ram,0x0c0a836cu,4);
goto P_0c0a8312;
P_0c0a8312: /* original 2239, guest PC 0x0c0a8312 */
if(!s->budget--) { s->failed_pc=0x0c0a8312u; return 0; }
r[2]&=r[3];
goto P_0c0a8314;
P_0c0a8314: /* original a014, guest PC 0x0c0a8314 */
if(!s->budget--) { s->failed_pc=0x0c0a8314u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a8340;
P_0c0a8316: /* original 2e22, guest PC 0x0c0a8316 */
if(!s->budget--) { s->failed_pc=0x0c0a8316u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a8318;
P_0c0a8318: /* original 85eb, guest PC 0x0c0a8318 */
if(!s->budget--) { s->failed_pc=0x0c0a8318u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a831a;
P_0c0a831a: /* original ed34, guest PC 0x0c0a831a */
if(!s->budget--) { s->failed_pc=0x0c0a831au; return 0; }
r[13]=0x00000034u;
goto P_0c0a831c;
P_0c0a831c: /* original 63e3, guest PC 0x0c0a831c */
if(!s->budget--) { s->failed_pc=0x0c0a831cu; return 0; }
r[3]=r[14];
goto P_0c0a831e;
P_0c0a831e: /* original 731c, guest PC 0x0c0a831e */
if(!s->budget--) { s->failed_pc=0x0c0a831eu; return 0; }
r[3]+=0x0000001cu;
goto P_0c0a8320;
P_0c0a8320: /* original 7001, guest PC 0x0c0a8320 */
if(!s->budget--) { s->failed_pc=0x0c0a8320u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a8322;
P_0c0a8322: /* original c91f, guest PC 0x0c0a8322 */
if(!s->budget--) { s->failed_pc=0x0c0a8322u; return 0; }
r[0]&=31u;
goto P_0c0a8324;
P_0c0a8324: /* original 81eb, guest PC 0x0c0a8324 */
if(!s->budget--) { s->failed_pc=0x0c0a8324u; return 0; }
write(ram,r[14]+22,r[0],2);
goto P_0c0a8326;
P_0c0a8326: /* original 85eb, guest PC 0x0c0a8326 */
if(!s->budget--) { s->failed_pc=0x0c0a8326u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a8328;
P_0c0a8328: /* original 20df, guest PC 0x0c0a8328 */
if(!s->budget--) { s->failed_pc=0x0c0a8328u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[0]*(int32_t)(int16_t)r[13]);
goto P_0c0a832a;
P_0c0a832a: /* original 0d1a, guest PC 0x0c0a832a */
if(!s->budget--) { s->failed_pc=0x0c0a832au; return 0; }
r[13]=r[19];
goto P_0c0a832c;
P_0c0a832c: /* original 6ddf, guest PC 0x0c0a832c */
if(!s->budget--) { s->failed_pc=0x0c0a832cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c0a832e;
P_0c0a832e: /* original 3d3c, guest PC 0x0c0a832e */
if(!s->budget--) { s->failed_pc=0x0c0a832eu; return 0; }
r[13]+=r[3];
goto P_0c0a8330;
P_0c0a8330: /* original 52d5, guest PC 0x0c0a8330 */
if(!s->budget--) { s->failed_pc=0x0c0a8330u; return 0; }
r[2]=read(ram,r[13]+20,4);
goto P_0c0a8332;
P_0c0a8332: /* original 2228, guest PC 0x0c0a8332 */
if(!s->budget--) { s->failed_pc=0x0c0a8332u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a8334;
P_0c0a8334: /* original 8904, guest PC 0x0c0a8334 */
if(!s->budget--) { s->failed_pc=0x0c0a8334u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8340; }
goto P_0c0a8336;
P_0c0a8336: /* original 52d5, guest PC 0x0c0a8336 */
if(!s->budget--) { s->failed_pc=0x0c0a8336u; return 0; }
r[2]=read(ram,r[13]+20,4);
goto P_0c0a8338;
P_0c0a8338: /* original e5ff, guest PC 0x0c0a8338 */
if(!s->budget--) { s->failed_pc=0x0c0a8338u; return 0; }
r[5]=0xffffffffu;
goto P_0c0a833a;
P_0c0a833a: /* original 420b, guest PC 0x0c0a833a */
if(!s->budget--) { s->failed_pc=0x0c0a833au; return 0; }
target=r[2];
r[16]=code_base|0x0c0a833eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a833eu) { target=s->pc; goto dispatch; }
goto P_0c0a833e;
P_0c0a833c: /* original 64d3, guest PC 0x0c0a833c */
if(!s->budget--) { s->failed_pc=0x0c0a833cu; return 0; }
r[4]=r[13];
goto P_0c0a833e;
P_0c0a833e: /* original 2008, guest PC 0x0c0a833e */
if(!s->budget--) { s->failed_pc=0x0c0a833eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8340;
P_0c0a8340: /* original 85eb, guest PC 0x0c0a8340 */
if(!s->budget--) { s->failed_pc=0x0c0a8340u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0a8342;
P_0c0a8342: /* original 6303, guest PC 0x0c0a8342 */
if(!s->budget--) { s->failed_pc=0x0c0a8342u; return 0; }
r[3]=r[0];
goto P_0c0a8344;
P_0c0a8344: /* original 85ed, guest PC 0x0c0a8344 */
if(!s->budget--) { s->failed_pc=0x0c0a8344u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+26,2);
goto P_0c0a8346;
P_0c0a8346: /* original 3300, guest PC 0x0c0a8346 */
if(!s->budget--) { s->failed_pc=0x0c0a8346u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[0])!=0);
goto P_0c0a8348;
P_0c0a8348: /* original 8be6, guest PC 0x0c0a8348 */
if(!s->budget--) { s->failed_pc=0x0c0a8348u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8318; }
goto P_0c0a834a;
P_0c0a834a: /* original 4f16, guest PC 0x0c0a834a */
if(!s->budget--) { s->failed_pc=0x0c0a834au; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a834c;
P_0c0a834c: /* original 4f26, guest PC 0x0c0a834c */
if(!s->budget--) { s->failed_pc=0x0c0a834cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a834e;
P_0c0a834e: /* original 6cf6, guest PC 0x0c0a834e */
if(!s->budget--) { s->failed_pc=0x0c0a834eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8350;
P_0c0a8350: /* original 6df6, guest PC 0x0c0a8350 */
if(!s->budget--) { s->failed_pc=0x0c0a8350u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8352;
P_0c0a8352: /* original 000b, guest PC 0x0c0a8352 */
if(!s->budget--) { s->failed_pc=0x0c0a8352u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a8354: /* original 6ef6, guest PC 0x0c0a8354 */
if(!s->budget--) { s->failed_pc=0x0c0a8354u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a8356u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a8356u; return 0; } return 1;
P_0c0a86ac: /* original 2fe6, guest PC 0x0c0a86ac */
if(!s->budget--) { s->failed_pc=0x0c0a86acu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a86ae;
P_0c0a86ae: /* original 6e53, guest PC 0x0c0a86ae */
if(!s->budget--) { s->failed_pc=0x0c0a86aeu; return 0; }
r[14]=r[5];
goto P_0c0a86b0;
P_0c0a86b0: /* original 2fd6, guest PC 0x0c0a86b0 */
if(!s->budget--) { s->failed_pc=0x0c0a86b0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a86b2;
P_0c0a86b2: /* original 6d73, guest PC 0x0c0a86b2 */
if(!s->budget--) { s->failed_pc=0x0c0a86b2u; return 0; }
r[13]=r[7];
goto P_0c0a86b4;
P_0c0a86b4: /* original 2fc6, guest PC 0x0c0a86b4 */
if(!s->budget--) { s->failed_pc=0x0c0a86b4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a86b6;
P_0c0a86b6: /* original 2fb6, guest PC 0x0c0a86b6 */
if(!s->budget--) { s->failed_pc=0x0c0a86b6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a86b8;
P_0c0a86b8: /* original 6b43, guest PC 0x0c0a86b8 */
if(!s->budget--) { s->failed_pc=0x0c0a86b8u; return 0; }
r[11]=r[4];
goto P_0c0a86ba;
P_0c0a86ba: /* original 4f22, guest PC 0x0c0a86ba */
if(!s->budget--) { s->failed_pc=0x0c0a86bau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a86bc;
P_0c0a86bc: /* original 7ffc, guest PC 0x0c0a86bc */
if(!s->budget--) { s->failed_pc=0x0c0a86bcu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a86be;
P_0c0a86be: /* original 2f62, guest PC 0x0c0a86be */
if(!s->budget--) { s->failed_pc=0x0c0a86beu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0a86c0;
P_0c0a86c0: /* original 64e3, guest PC 0x0c0a86c0 */
if(!s->budget--) { s->failed_pc=0x0c0a86c0u; return 0; }
r[4]=r[14];
goto P_0c0a86c2;
P_0c0a86c2: /* original 4408, guest PC 0x0c0a86c2 */
if(!s->budget--) { s->failed_pc=0x0c0a86c2u; return 0; }
r[4]<<=2;
goto P_0c0a86c4;
P_0c0a86c4: /* original 4408, guest PC 0x0c0a86c4 */
if(!s->budget--) { s->failed_pc=0x0c0a86c4u; return 0; }
r[4]<<=2;
goto P_0c0a86c6;
P_0c0a86c6: /* original dc31, guest PC 0x0c0a86c6 */
if(!s->budget--) { s->failed_pc=0x0c0a86c6u; return 0; }
r[12]=read(ram,0x0c0a878cu,4);
goto P_0c0a86c8;
P_0c0a86c8: /* original 4408, guest PC 0x0c0a86c8 */
if(!s->budget--) { s->failed_pc=0x0c0a86c8u; return 0; }
r[4]<<=2;
goto P_0c0a86ca;
P_0c0a86ca: /* original 4400, guest PC 0x0c0a86ca */
if(!s->budget--) { s->failed_pc=0x0c0a86cau; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a86cc;
P_0c0a86cc: /* original 6643, guest PC 0x0c0a86cc */
if(!s->budget--) { s->failed_pc=0x0c0a86ccu; return 0; }
r[6]=r[4];
goto P_0c0a86ce;
P_0c0a86ce: /* original e03b, guest PC 0x0c0a86ce */
if(!s->budget--) { s->failed_pc=0x0c0a86ceu; return 0; }
r[0]=0x0000003bu;
goto P_0c0a86d0;
P_0c0a86d0: /* original 36cc, guest PC 0x0c0a86d0 */
if(!s->budget--) { s->failed_pc=0x0c0a86d0u; return 0; }
r[6]+=r[12];
goto P_0c0a86d2;
P_0c0a86d2: /* original 046c, guest PC 0x0c0a86d2 */
if(!s->budget--) { s->failed_pc=0x0c0a86d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0a86d4;
P_0c0a86d4: /* original 2448, guest PC 0x0c0a86d4 */
if(!s->budget--) { s->failed_pc=0x0c0a86d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a86d6;
P_0c0a86d6: /* original 8b01, guest PC 0x0c0a86d6 */
if(!s->budget--) { s->failed_pc=0x0c0a86d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a86dc; }
goto P_0c0a86d8;
P_0c0a86d8: /* original a040, guest PC 0x0c0a86d8 */
if(!s->budget--) { s->failed_pc=0x0c0a86d8u; return 0; }
r[0]=0x00000001u;
goto P_0c0a875c;
P_0c0a86da: /* original e001, guest PC 0x0c0a86da */
if(!s->budget--) { s->failed_pc=0x0c0a86dau; return 0; }
r[0]=0x00000001u;
goto P_0c0a86dc;
P_0c0a86dc: /* original 60b3, guest PC 0x0c0a86dc */
if(!s->budget--) { s->failed_pc=0x0c0a86dcu; return 0; }
r[0]=r[11];
goto P_0c0a86de;
P_0c0a86de: /* original 8802, guest PC 0x0c0a86de */
if(!s->budget--) { s->failed_pc=0x0c0a86deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a86e0;
P_0c0a86e0: /* original 8903, guest PC 0x0c0a86e0 */
if(!s->budget--) { s->failed_pc=0x0c0a86e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a86ea; }
goto P_0c0a86e2;
P_0c0a86e2: /* original 65f2, guest PC 0x0c0a86e2 */
if(!s->budget--) { s->failed_pc=0x0c0a86e2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0a86e4;
P_0c0a86e4: /* original b041, guest PC 0x0c0a86e4 */
if(!s->budget--) { s->failed_pc=0x0c0a86e4u; return 0; }
target=code_base|0x0c0a876au; r[16]=code_base|0x0c0a86e8u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a86e8u) { target=s->pc; goto dispatch; }
goto P_0c0a86e8;
P_0c0a86e6: /* original 64b3, guest PC 0x0c0a86e6 */
if(!s->budget--) { s->failed_pc=0x0c0a86e6u; return 0; }
r[4]=r[11];
goto P_0c0a86e8;
P_0c0a86e8: /* original 6b03, guest PC 0x0c0a86e8 */
if(!s->budget--) { s->failed_pc=0x0c0a86e8u; return 0; }
r[11]=r[0];
goto P_0c0a86ea;
P_0c0a86ea: /* original 60b3, guest PC 0x0c0a86ea */
if(!s->budget--) { s->failed_pc=0x0c0a86eau; return 0; }
r[0]=r[11];
goto P_0c0a86ec;
P_0c0a86ec: /* original 954a, guest PC 0x0c0a86ec */
if(!s->budget--) { s->failed_pc=0x0c0a86ecu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8784u,2);
goto P_0c0a86ee;
P_0c0a86ee: /* original 8802, guest PC 0x0c0a86ee */
if(!s->budget--) { s->failed_pc=0x0c0a86eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a86f0;
P_0c0a86f0: /* original 8b15, guest PC 0x0c0a86f0 */
if(!s->budget--) { s->failed_pc=0x0c0a86f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a871e; }
goto P_0c0a86f2;
P_0c0a86f2: /* original e400, guest PC 0x0c0a86f2 */
if(!s->budget--) { s->failed_pc=0x0c0a86f2u; return 0; }
r[4]=0x00000000u;
goto P_0c0a86f4;
P_0c0a86f4: /* original 66e3, guest PC 0x0c0a86f4 */
if(!s->budget--) { s->failed_pc=0x0c0a86f4u; return 0; }
r[6]=r[14];
goto P_0c0a86f6;
P_0c0a86f6: /* original 4608, guest PC 0x0c0a86f6 */
if(!s->budget--) { s->failed_pc=0x0c0a86f6u; return 0; }
r[6]<<=2;
goto P_0c0a86f8;
P_0c0a86f8: /* original 4608, guest PC 0x0c0a86f8 */
if(!s->budget--) { s->failed_pc=0x0c0a86f8u; return 0; }
r[6]<<=2;
goto P_0c0a86fa;
P_0c0a86fa: /* original 4608, guest PC 0x0c0a86fa */
if(!s->budget--) { s->failed_pc=0x0c0a86fau; return 0; }
r[6]<<=2;
goto P_0c0a86fc;
P_0c0a86fc: /* original 4600, guest PC 0x0c0a86fc */
if(!s->budget--) { s->failed_pc=0x0c0a86fcu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0a86fe;
P_0c0a86fe: /* original e03b, guest PC 0x0c0a86fe */
if(!s->budget--) { s->failed_pc=0x0c0a86feu; return 0; }
r[0]=0x0000003bu;
goto P_0c0a8700;
P_0c0a8700: /* original 36cc, guest PC 0x0c0a8700 */
if(!s->budget--) { s->failed_pc=0x0c0a8700u; return 0; }
r[6]+=r[12];
goto P_0c0a8702;
P_0c0a8702: /* original 066c, guest PC 0x0c0a8702 */
if(!s->budget--) { s->failed_pc=0x0c0a8702u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0a8704;
P_0c0a8704: /* original 2668, guest PC 0x0c0a8704 */
if(!s->budget--) { s->failed_pc=0x0c0a8704u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0a8706;
P_0c0a8706: /* original 8908, guest PC 0x0c0a8706 */
if(!s->budget--) { s->failed_pc=0x0c0a8706u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a871a; }
goto P_0c0a8708;
P_0c0a8708: /* original 7eff, guest PC 0x0c0a8708 */
if(!s->budget--) { s->failed_pc=0x0c0a8708u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0a870a;
P_0c0a870a: /* original 4e11, guest PC 0x0c0a870a */
if(!s->budget--) { s->failed_pc=0x0c0a870au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0a870c;
P_0c0a870c: /* original 8d01, guest PC 0x0c0a870c */
if(!s->budget--) { s->failed_pc=0x0c0a870cu; return 0; }
cond=r[17]&1u;
r[13]+=0x00000001u;
if(cond) { goto P_0c0a8712; }
goto P_0c0a8710;
P_0c0a870e: /* original 7d01, guest PC 0x0c0a870e */
if(!s->budget--) { s->failed_pc=0x0c0a870eu; return 0; }
r[13]+=0x00000001u;
goto P_0c0a8710;
P_0c0a8710: /* original 6e53, guest PC 0x0c0a8710 */
if(!s->budget--) { s->failed_pc=0x0c0a8710u; return 0; }
r[14]=r[5];
goto P_0c0a8712;
P_0c0a8712: /* original e31e, guest PC 0x0c0a8712 */
if(!s->budget--) { s->failed_pc=0x0c0a8712u; return 0; }
r[3]=0x0000001eu;
goto P_0c0a8714;
P_0c0a8714: /* original 7401, guest PC 0x0c0a8714 */
if(!s->budget--) { s->failed_pc=0x0c0a8714u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a8716;
P_0c0a8716: /* original 3433, guest PC 0x0c0a8716 */
if(!s->budget--) { s->failed_pc=0x0c0a8716u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0a8718;
P_0c0a8718: /* original 8bec, guest PC 0x0c0a8718 */
if(!s->budget--) { s->failed_pc=0x0c0a8718u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a86f4; }
goto P_0c0a871a;
P_0c0a871a: /* original a009, guest PC 0x0c0a871a */
if(!s->budget--) { s->failed_pc=0x0c0a871au; return 0; }
r[4]=r[13];
goto P_0c0a8730;
P_0c0a871c: /* original 64d3, guest PC 0x0c0a871c */
if(!s->budget--) { s->failed_pc=0x0c0a871cu; return 0; }
r[4]=r[13];
goto P_0c0a871e;
P_0c0a871e: /* original 7eff, guest PC 0x0c0a871e */
if(!s->budget--) { s->failed_pc=0x0c0a871eu; return 0; }
r[14]+=0xffffffffu;
goto P_0c0a8720;
P_0c0a8720: /* original 4e11, guest PC 0x0c0a8720 */
if(!s->budget--) { s->failed_pc=0x0c0a8720u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0a8722;
P_0c0a8722: /* original 8d01, guest PC 0x0c0a8722 */
if(!s->budget--) { s->failed_pc=0x0c0a8722u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000001u;
if(cond) { goto P_0c0a8728; }
goto P_0c0a8726;
P_0c0a8724: /* original 7d01, guest PC 0x0c0a8724 */
if(!s->budget--) { s->failed_pc=0x0c0a8724u; return 0; }
r[13]+=0x00000001u;
goto P_0c0a8726;
P_0c0a8726: /* original 6e53, guest PC 0x0c0a8726 */
if(!s->budget--) { s->failed_pc=0x0c0a8726u; return 0; }
r[14]=r[5];
goto P_0c0a8728;
P_0c0a8728: /* original 962d, guest PC 0x0c0a8728 */
if(!s->budget--) { s->failed_pc=0x0c0a8728u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8786u,2);
goto P_0c0a872a;
P_0c0a872a: /* original 3d63, guest PC 0x0c0a872a */
if(!s->budget--) { s->failed_pc=0x0c0a872au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[6])!=0);
goto P_0c0a872c;
P_0c0a872c: /* original 8bc8, guest PC 0x0c0a872c */
if(!s->budget--) { s->failed_pc=0x0c0a872cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a86c0; }
goto P_0c0a872e;
P_0c0a872e: /* original 6463, guest PC 0x0c0a872e */
if(!s->budget--) { s->failed_pc=0x0c0a872eu; return 0; }
r[4]=r[6];
goto P_0c0a8730;
P_0c0a8730: /* original 962a, guest PC 0x0c0a8730 */
if(!s->budget--) { s->failed_pc=0x0c0a8730u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8788u,2);
goto P_0c0a8732;
P_0c0a8732: /* original 3463, guest PC 0x0c0a8732 */
if(!s->budget--) { s->failed_pc=0x0c0a8732u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c0a8734;
P_0c0a8734: /* original 8911, guest PC 0x0c0a8734 */
if(!s->budget--) { s->failed_pc=0x0c0a8734u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a875a; }
goto P_0c0a8736;
P_0c0a8736: /* original 67e3, guest PC 0x0c0a8736 */
if(!s->budget--) { s->failed_pc=0x0c0a8736u; return 0; }
r[7]=r[14];
goto P_0c0a8738;
P_0c0a8738: /* original 4708, guest PC 0x0c0a8738 */
if(!s->budget--) { s->failed_pc=0x0c0a8738u; return 0; }
r[7]<<=2;
goto P_0c0a873a;
P_0c0a873a: /* original 4708, guest PC 0x0c0a873a */
if(!s->budget--) { s->failed_pc=0x0c0a873au; return 0; }
r[7]<<=2;
goto P_0c0a873c;
P_0c0a873c: /* original 4708, guest PC 0x0c0a873c */
if(!s->budget--) { s->failed_pc=0x0c0a873cu; return 0; }
r[7]<<=2;
goto P_0c0a873e;
P_0c0a873e: /* original 4700, guest PC 0x0c0a873e */
if(!s->budget--) { s->failed_pc=0x0c0a873eu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c0a8740;
P_0c0a8740: /* original e03b, guest PC 0x0c0a8740 */
if(!s->budget--) { s->failed_pc=0x0c0a8740u; return 0; }
r[0]=0x0000003bu;
goto P_0c0a8742;
P_0c0a8742: /* original 37cc, guest PC 0x0c0a8742 */
if(!s->budget--) { s->failed_pc=0x0c0a8742u; return 0; }
r[7]+=r[12];
goto P_0c0a8744;
P_0c0a8744: /* original 077c, guest PC 0x0c0a8744 */
if(!s->budget--) { s->failed_pc=0x0c0a8744u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c0a8746;
P_0c0a8746: /* original 2778, guest PC 0x0c0a8746 */
if(!s->budget--) { s->failed_pc=0x0c0a8746u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0a8748;
P_0c0a8748: /* original 8907, guest PC 0x0c0a8748 */
if(!s->budget--) { s->failed_pc=0x0c0a8748u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a875a; }
goto P_0c0a874a;
P_0c0a874a: /* original 7eff, guest PC 0x0c0a874a */
if(!s->budget--) { s->failed_pc=0x0c0a874au; return 0; }
r[14]+=0xffffffffu;
goto P_0c0a874c;
P_0c0a874c: /* original 4e11, guest PC 0x0c0a874c */
if(!s->budget--) { s->failed_pc=0x0c0a874cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0a874e;
P_0c0a874e: /* original 7d01, guest PC 0x0c0a874e */
if(!s->budget--) { s->failed_pc=0x0c0a874eu; return 0; }
r[13]+=0x00000001u;
goto P_0c0a8750;
P_0c0a8750: /* original 8d01, guest PC 0x0c0a8750 */
if(!s->budget--) { s->failed_pc=0x0c0a8750u; return 0; }
cond=r[17]&1u;
r[4]=r[13];
if(cond) { goto P_0c0a8756; }
goto P_0c0a8754;
P_0c0a8752: /* original 64d3, guest PC 0x0c0a8752 */
if(!s->budget--) { s->failed_pc=0x0c0a8752u; return 0; }
r[4]=r[13];
goto P_0c0a8754;
P_0c0a8754: /* original 6e53, guest PC 0x0c0a8754 */
if(!s->budget--) { s->failed_pc=0x0c0a8754u; return 0; }
r[14]=r[5];
goto P_0c0a8756;
P_0c0a8756: /* original 3467, guest PC 0x0c0a8756 */
if(!s->budget--) { s->failed_pc=0x0c0a8756u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[6])!=0);
goto P_0c0a8758;
P_0c0a8758: /* original 8bed, guest PC 0x0c0a8758 */
if(!s->budget--) { s->failed_pc=0x0c0a8758u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8736; }
goto P_0c0a875a;
P_0c0a875a: /* original 6043, guest PC 0x0c0a875a */
if(!s->budget--) { s->failed_pc=0x0c0a875au; return 0; }
r[0]=r[4];
goto P_0c0a875c;
P_0c0a875c: /* original 7f04, guest PC 0x0c0a875c */
if(!s->budget--) { s->failed_pc=0x0c0a875cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0a875e;
P_0c0a875e: /* original 4f26, guest PC 0x0c0a875e */
if(!s->budget--) { s->failed_pc=0x0c0a875eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8760;
P_0c0a8760: /* original 6bf6, guest PC 0x0c0a8760 */
if(!s->budget--) { s->failed_pc=0x0c0a8760u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8762;
P_0c0a8762: /* original 6cf6, guest PC 0x0c0a8762 */
if(!s->budget--) { s->failed_pc=0x0c0a8762u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8764;
P_0c0a8764: /* original 6df6, guest PC 0x0c0a8764 */
if(!s->budget--) { s->failed_pc=0x0c0a8764u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8766;
P_0c0a8766: /* original 000b, guest PC 0x0c0a8766 */
if(!s->budget--) { s->failed_pc=0x0c0a8766u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a8768: /* original 6ef6, guest PC 0x0c0a8768 */
if(!s->budget--) { s->failed_pc=0x0c0a8768u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a876au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
