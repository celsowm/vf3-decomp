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
int vf3_away_batch80_adapter_17(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c0a8574u: goto P_0c0a8574;
case 0x0c0a8576u: goto P_0c0a8576;
case 0x0c0a8578u: goto P_0c0a8578;
case 0x0c0a857au: goto P_0c0a857a;
case 0x0c0a857cu: goto P_0c0a857c;
case 0x0c0a857eu: goto P_0c0a857e;
case 0x0c0a8580u: goto P_0c0a8580;
case 0x0c0a8582u: goto P_0c0a8582;
case 0x0c0a8584u: goto P_0c0a8584;
case 0x0c0a8586u: goto P_0c0a8586;
case 0x0c0a8588u: goto P_0c0a8588;
case 0x0c0a858au: goto P_0c0a858a;
case 0x0c0a858cu: goto P_0c0a858c;
case 0x0c0a858eu: goto P_0c0a858e;
case 0x0c0a8590u: goto P_0c0a8590;
case 0x0c0a8592u: goto P_0c0a8592;
case 0x0c0a8594u: goto P_0c0a8594;
case 0x0c0a8596u: goto P_0c0a8596;
case 0x0c0a8598u: goto P_0c0a8598;
case 0x0c0a859au: goto P_0c0a859a;
case 0x0c0a859cu: goto P_0c0a859c;
case 0x0c0a859eu: goto P_0c0a859e;
case 0x0c0a85a0u: goto P_0c0a85a0;
case 0x0c0a85a2u: goto P_0c0a85a2;
case 0x0c0a85a4u: goto P_0c0a85a4;
case 0x0c0a85a6u: goto P_0c0a85a6;
case 0x0c0a85a8u: goto P_0c0a85a8;
case 0x0c0a85aau: goto P_0c0a85aa;
case 0x0c0a85acu: goto P_0c0a85ac;
case 0x0c0a85aeu: goto P_0c0a85ae;
case 0x0c0a85b0u: goto P_0c0a85b0;
case 0x0c0a85b2u: goto P_0c0a85b2;
case 0x0c0a85b4u: goto P_0c0a85b4;
case 0x0c0a85b6u: goto P_0c0a85b6;
case 0x0c0a85b8u: goto P_0c0a85b8;
case 0x0c0a85bau: goto P_0c0a85ba;
case 0x0c0a85bcu: goto P_0c0a85bc;
case 0x0c0a85beu: goto P_0c0a85be;
case 0x0c0a85c0u: goto P_0c0a85c0;
case 0x0c0a85c2u: goto P_0c0a85c2;
case 0x0c0a85c4u: goto P_0c0a85c4;
case 0x0c0a85c6u: goto P_0c0a85c6;
case 0x0c0a85c8u: goto P_0c0a85c8;
case 0x0c0a85cau: goto P_0c0a85ca;
case 0x0c0a85ccu: goto P_0c0a85cc;
case 0x0c0a85ceu: goto P_0c0a85ce;
case 0x0c0a85d0u: goto P_0c0a85d0;
case 0x0c0a85d2u: goto P_0c0a85d2;
case 0x0c0a85d4u: goto P_0c0a85d4;
case 0x0c0a85d6u: goto P_0c0a85d6;
case 0x0c0a85d8u: goto P_0c0a85d8;
case 0x0c0a85dau: goto P_0c0a85da;
case 0x0c0a85dcu: goto P_0c0a85dc;
case 0x0c0a85deu: goto P_0c0a85de;
case 0x0c0a85e0u: goto P_0c0a85e0;
case 0x0c0a85e2u: goto P_0c0a85e2;
case 0x0c0a85e4u: goto P_0c0a85e4;
case 0x0c0a85e6u: goto P_0c0a85e6;
case 0x0c0a85e8u: goto P_0c0a85e8;
case 0x0c0a85eau: goto P_0c0a85ea;
case 0x0c0a85ecu: goto P_0c0a85ec;
case 0x0c0a85eeu: goto P_0c0a85ee;
case 0x0c0a85f0u: goto P_0c0a85f0;
case 0x0c0a85f2u: goto P_0c0a85f2;
case 0x0c0a85f4u: goto P_0c0a85f4;
case 0x0c0a85f6u: goto P_0c0a85f6;
case 0x0c0a85f8u: goto P_0c0a85f8;
case 0x0c0a85fau: goto P_0c0a85fa;
case 0x0c0a85fcu: goto P_0c0a85fc;
case 0x0c0a85feu: goto P_0c0a85fe;
case 0x0c0a8600u: goto P_0c0a8600;
case 0x0c0a8602u: goto P_0c0a8602;
case 0x0c0a8604u: goto P_0c0a8604;
case 0x0c0a8606u: goto P_0c0a8606;
case 0x0c0a8608u: goto P_0c0a8608;
case 0x0c0a860au: goto P_0c0a860a;
case 0x0c0a860cu: goto P_0c0a860c;
case 0x0c0a860eu: goto P_0c0a860e;
case 0x0c0a8610u: goto P_0c0a8610;
case 0x0c0a8612u: goto P_0c0a8612;
case 0x0c0a8614u: goto P_0c0a8614;
case 0x0c0a8616u: goto P_0c0a8616;
case 0x0c0a8618u: goto P_0c0a8618;
case 0x0c0a861au: goto P_0c0a861a;
case 0x0c0a861cu: goto P_0c0a861c;
case 0x0c0a861eu: goto P_0c0a861e;
case 0x0c0a8620u: goto P_0c0a8620;
case 0x0c0a8622u: goto P_0c0a8622;
case 0x0c0a8624u: goto P_0c0a8624;
case 0x0c0a8626u: goto P_0c0a8626;
case 0x0c0a8628u: goto P_0c0a8628;
case 0x0c0a862au: goto P_0c0a862a;
case 0x0c0a862cu: goto P_0c0a862c;
case 0x0c0a862eu: goto P_0c0a862e;
case 0x0c0a8630u: goto P_0c0a8630;
case 0x0c0a8632u: goto P_0c0a8632;
case 0x0c0a8634u: goto P_0c0a8634;
case 0x0c0a8636u: goto P_0c0a8636;
case 0x0c0a8638u: goto P_0c0a8638;
case 0x0c0a863au: goto P_0c0a863a;
case 0x0c0a863cu: goto P_0c0a863c;
case 0x0c0a863eu: goto P_0c0a863e;
case 0x0c0a8640u: goto P_0c0a8640;
case 0x0c0a8642u: goto P_0c0a8642;
case 0x0c0a8644u: goto P_0c0a8644;
case 0x0c0a8646u: goto P_0c0a8646;
case 0x0c0a8648u: goto P_0c0a8648;
case 0x0c0a864au: goto P_0c0a864a;
case 0x0c0a864cu: goto P_0c0a864c;
case 0x0c0a864eu: goto P_0c0a864e;
case 0x0c0a8650u: goto P_0c0a8650;
case 0x0c0a8652u: goto P_0c0a8652;
case 0x0c0a8654u: goto P_0c0a8654;
case 0x0c0a8656u: goto P_0c0a8656;
case 0x0c0a8658u: goto P_0c0a8658;
case 0x0c0a865au: goto P_0c0a865a;
case 0x0c0a865cu: goto P_0c0a865c;
case 0x0c0a865eu: goto P_0c0a865e;
case 0x0c0a8660u: goto P_0c0a8660;
case 0x0c0a8662u: goto P_0c0a8662;
case 0x0c0a8664u: goto P_0c0a8664;
case 0x0c0a8666u: goto P_0c0a8666;
case 0x0c0a8668u: goto P_0c0a8668;
case 0x0c0a866au: goto P_0c0a866a;
case 0x0c0a866cu: goto P_0c0a866c;
case 0x0c0a866eu: goto P_0c0a866e;
case 0x0c0a8670u: goto P_0c0a8670;
case 0x0c0a8672u: goto P_0c0a8672;
case 0x0c0a8674u: goto P_0c0a8674;
case 0x0c0a8676u: goto P_0c0a8676;
case 0x0c0a8678u: goto P_0c0a8678;
case 0x0c0a867au: goto P_0c0a867a;
case 0x0c0a867cu: goto P_0c0a867c;
case 0x0c0a867eu: goto P_0c0a867e;
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
P_0c0a8574: /* original 2fe6, guest PC 0x0c0a8574 */
if(!s->budget--) { s->failed_pc=0x0c0a8574u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8576;
P_0c0a8576: /* original 2fd6, guest PC 0x0c0a8576 */
if(!s->budget--) { s->failed_pc=0x0c0a8576u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8578;
P_0c0a8578: /* original 2fc6, guest PC 0x0c0a8578 */
if(!s->budget--) { s->failed_pc=0x0c0a8578u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a857a;
P_0c0a857a: /* original 2fb6, guest PC 0x0c0a857a */
if(!s->budget--) { s->failed_pc=0x0c0a857au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a857c;
P_0c0a857c: /* original 2fa6, guest PC 0x0c0a857c */
if(!s->budget--) { s->failed_pc=0x0c0a857cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a857e;
P_0c0a857e: /* original 2f96, guest PC 0x0c0a857e */
if(!s->budget--) { s->failed_pc=0x0c0a857eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8580;
P_0c0a8580: /* original 2f86, guest PC 0x0c0a8580 */
if(!s->budget--) { s->failed_pc=0x0c0a8580u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a8582;
P_0c0a8582: /* original 4f22, guest PC 0x0c0a8582 */
if(!s->budget--) { s->failed_pc=0x0c0a8582u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a8584;
P_0c0a8584: /* original 7ff4, guest PC 0x0c0a8584 */
if(!s->budget--) { s->failed_pc=0x0c0a8584u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a8586;
P_0c0a8586: /* original 2f42, guest PC 0x0c0a8586 */
if(!s->budget--) { s->failed_pc=0x0c0a8586u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a8588;
P_0c0a8588: /* original d340, guest PC 0x0c0a8588 */
if(!s->budget--) { s->failed_pc=0x0c0a8588u; return 0; }
r[3]=read(ram,0x0c0a868cu,4);
goto P_0c0a858a;
P_0c0a858a: /* original d241, guest PC 0x0c0a858a */
if(!s->budget--) { s->failed_pc=0x0c0a858au; return 0; }
r[2]=read(ram,0x0c0a8690u,4);
goto P_0c0a858c;
P_0c0a858c: /* original 420b, guest PC 0x0c0a858c */
if(!s->budget--) { s->failed_pc=0x0c0a858cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a8590u;
write(ram,r[15]+8,r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8590u) { target=s->pc; goto dispatch; }
goto P_0c0a8590;
P_0c0a858e: /* original 1f32, guest PC 0x0c0a858e */
if(!s->budget--) { s->failed_pc=0x0c0a858eu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0a8590;
P_0c0a8590: /* original 2008, guest PC 0x0c0a8590 */
if(!s->budget--) { s->failed_pc=0x0c0a8590u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a8592;
P_0c0a8592: /* original 896b, guest PC 0x0c0a8592 */
if(!s->budget--) { s->failed_pc=0x0c0a8592u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a866c; }
goto P_0c0a8594;
P_0c0a8594: /* original dc3f, guest PC 0x0c0a8594 */
if(!s->budget--) { s->failed_pc=0x0c0a8594u; return 0; }
r[12]=read(ram,0x0c0a8694u,4);
goto P_0c0a8596;
P_0c0a8596: /* original eb01, guest PC 0x0c0a8596 */
if(!s->budget--) { s->failed_pc=0x0c0a8596u; return 0; }
r[11]=0x00000001u;
goto P_0c0a8598;
P_0c0a8598: /* original 9072, guest PC 0x0c0a8598 */
if(!s->budget--) { s->failed_pc=0x0c0a8598u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8680u,2);
goto P_0c0a859a;
P_0c0a859a: /* original 6df2, guest PC 0x0c0a859a */
if(!s->budget--) { s->failed_pc=0x0c0a859au; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c0a859c;
P_0c0a859c: /* original 0cb4, guest PC 0x0c0a859c */
if(!s->budget--) { s->failed_pc=0x0c0a859cu; return 0; }
write(ram,r[12]+r[0],r[11],1);
goto P_0c0a859e;
P_0c0a859e: /* original e029, guest PC 0x0c0a859e */
if(!s->budget--) { s->failed_pc=0x0c0a859eu; return 0; }
r[0]=0x00000029u;
goto P_0c0a85a0;
P_0c0a85a0: /* original 00cc, guest PC 0x0c0a85a0 */
if(!s->budget--) { s->failed_pc=0x0c0a85a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0a85a2;
P_0c0a85a2: /* original 80f4, guest PC 0x0c0a85a2 */
if(!s->budget--) { s->failed_pc=0x0c0a85a2u; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c0a85a4;
P_0c0a85a4: /* original 53c2, guest PC 0x0c0a85a4 */
if(!s->budget--) { s->failed_pc=0x0c0a85a4u; return 0; }
r[3]=read(ram,r[12]+8,4);
goto P_0c0a85a6;
P_0c0a85a6: /* original 2f32, guest PC 0x0c0a85a6 */
if(!s->budget--) { s->failed_pc=0x0c0a85a6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a85a8;
P_0c0a85a8: /* original 54f2, guest PC 0x0c0a85a8 */
if(!s->budget--) { s->failed_pc=0x0c0a85a8u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0a85aa;
P_0c0a85aa: /* original d33b, guest PC 0x0c0a85aa */
if(!s->budget--) { s->failed_pc=0x0c0a85aau; return 0; }
r[3]=read(ram,0x0c0a8698u,4);
goto P_0c0a85ac;
P_0c0a85ac: /* original 430b, guest PC 0x0c0a85ac */
if(!s->budget--) { s->failed_pc=0x0c0a85acu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a85b0u;
r[4]+=0x00000013u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a85b0u) { target=s->pc; goto dispatch; }
goto P_0c0a85b0;
P_0c0a85ae: /* original 7413, guest PC 0x0c0a85ae */
if(!s->budget--) { s->failed_pc=0x0c0a85aeu; return 0; }
r[4]+=0x00000013u;
goto P_0c0a85b0;
P_0c0a85b0: /* original 6e0c, guest PC 0x0c0a85b0 */
if(!s->budget--) { s->failed_pc=0x0c0a85b0u; return 0; }
r[14]=r[0]&255u;
goto P_0c0a85b2;
P_0c0a85b2: /* original 84f4, guest PC 0x0c0a85b2 */
if(!s->budget--) { s->failed_pc=0x0c0a85b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c0a85b4;
P_0c0a85b4: /* original 8803, guest PC 0x0c0a85b4 */
if(!s->budget--) { s->failed_pc=0x0c0a85b4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0a85b6;
P_0c0a85b6: /* original 8b09, guest PC 0x0c0a85b6 */
if(!s->budget--) { s->failed_pc=0x0c0a85b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a85cc; }
goto P_0c0a85b8;
P_0c0a85b8: /* original 2ee8, guest PC 0x0c0a85b8 */
if(!s->budget--) { s->failed_pc=0x0c0a85b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a85ba;
P_0c0a85ba: /* original 8907, guest PC 0x0c0a85ba */
if(!s->budget--) { s->failed_pc=0x0c0a85bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a85cc; }
goto P_0c0a85bc;
P_0c0a85bc: /* original 64f2, guest PC 0x0c0a85bc */
if(!s->budget--) { s->failed_pc=0x0c0a85bcu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a85be;
P_0c0a85be: /* original 644c, guest PC 0x0c0a85be */
if(!s->budget--) { s->failed_pc=0x0c0a85beu; return 0; }
r[4]=r[4]&255u;
goto P_0c0a85c0;
P_0c0a85c0: /* original 6043, guest PC 0x0c0a85c0 */
if(!s->budget--) { s->failed_pc=0x0c0a85c0u; return 0; }
r[0]=r[4];
goto P_0c0a85c2;
P_0c0a85c2: /* original 8801, guest PC 0x0c0a85c2 */
if(!s->budget--) { s->failed_pc=0x0c0a85c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a85c4;
P_0c0a85c4: /* original 8b02, guest PC 0x0c0a85c4 */
if(!s->budget--) { s->failed_pc=0x0c0a85c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a85cc; }
goto P_0c0a85c6;
P_0c0a85c6: /* original 6043, guest PC 0x0c0a85c6 */
if(!s->budget--) { s->failed_pc=0x0c0a85c6u; return 0; }
r[0]=r[4];
goto P_0c0a85c8;
P_0c0a85c8: /* original 881d, guest PC 0x0c0a85c8 */
if(!s->budget--) { s->failed_pc=0x0c0a85c8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001du)!=0);
goto P_0c0a85ca;
P_0c0a85ca: /* original 8904, guest PC 0x0c0a85ca */
if(!s->budget--) { s->failed_pc=0x0c0a85cau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a85d6; }
goto P_0c0a85cc;
P_0c0a85cc: /* original e019, guest PC 0x0c0a85cc */
if(!s->budget--) { s->failed_pc=0x0c0a85ccu; return 0; }
r[0]=0x00000019u;
goto P_0c0a85ce;
P_0c0a85ce: /* original 04cc, guest PC 0x0c0a85ce */
if(!s->budget--) { s->failed_pc=0x0c0a85ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0a85d0;
P_0c0a85d0: /* original 604e, guest PC 0x0c0a85d0 */
if(!s->budget--) { s->failed_pc=0x0c0a85d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0a85d2;
P_0c0a85d2: /* original 8802, guest PC 0x0c0a85d2 */
if(!s->budget--) { s->failed_pc=0x0c0a85d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a85d4;
P_0c0a85d4: /* original 894a, guest PC 0x0c0a85d4 */
if(!s->budget--) { s->failed_pc=0x0c0a85d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a866c; }
goto P_0c0a85d6;
P_0c0a85d6: /* original d231, guest PC 0x0c0a85d6 */
if(!s->budget--) { s->failed_pc=0x0c0a85d6u; return 0; }
r[2]=read(ram,0x0c0a869cu,4);
goto P_0c0a85d8;
P_0c0a85d8: /* original 420b, guest PC 0x0c0a85d8 */
if(!s->budget--) { s->failed_pc=0x0c0a85d8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a85dcu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a85dcu) { target=s->pc; goto dispatch; }
goto P_0c0a85dc;
P_0c0a85da: /* original 0009, guest PC 0x0c0a85da */
if(!s->budget--) { s->failed_pc=0x0c0a85dau; return 0; }
goto P_0c0a85dc;
P_0c0a85dc: /* original d430, guest PC 0x0c0a85dc */
if(!s->budget--) { s->failed_pc=0x0c0a85dcu; return 0; }
r[4]=read(ram,0x0c0a86a0u,4);
goto P_0c0a85de;
P_0c0a85de: /* original 9050, guest PC 0x0c0a85de */
if(!s->budget--) { s->failed_pc=0x0c0a85deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8682u,2);
goto P_0c0a85e0;
P_0c0a85e0: /* original 5a45, guest PC 0x0c0a85e0 */
if(!s->budget--) { s->failed_pc=0x0c0a85e0u; return 0; }
r[10]=read(ram,r[4]+20,4);
goto P_0c0a85e2;
P_0c0a85e2: /* original 5944, guest PC 0x0c0a85e2 */
if(!s->budget--) { s->failed_pc=0x0c0a85e2u; return 0; }
r[9]=read(ram,r[4]+16,4);
goto P_0c0a85e4;
P_0c0a85e4: /* original 09b4, guest PC 0x0c0a85e4 */
if(!s->budget--) { s->failed_pc=0x0c0a85e4u; return 0; }
write(ram,r[9]+r[0],r[11],1);
goto P_0c0a85e6;
P_0c0a85e6: /* original 0ae4, guest PC 0x0c0a85e6 */
if(!s->budget--) { s->failed_pc=0x0c0a85e6u; return 0; }
write(ram,r[10]+r[0],r[14],1);
goto P_0c0a85e8;
P_0c0a85e8: /* original e050, guest PC 0x0c0a85e8 */
if(!s->budget--) { s->failed_pc=0x0c0a85e8u; return 0; }
r[0]=0x00000050u;
goto P_0c0a85ea;
P_0c0a85ea: /* original 054e, guest PC 0x0c0a85ea */
if(!s->budget--) { s->failed_pc=0x0c0a85eau; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0a85ec;
P_0c0a85ec: /* original 5e54, guest PC 0x0c0a85ec */
if(!s->budget--) { s->failed_pc=0x0c0a85ecu; return 0; }
r[14]=read(ram,r[5]+16,4);
goto P_0c0a85ee;
P_0c0a85ee: /* original 1de4, guest PC 0x0c0a85ee */
if(!s->budget--) { s->failed_pc=0x0c0a85eeu; return 0; }
write(ram,r[13]+16,r[14],4);
goto P_0c0a85f0;
P_0c0a85f0: /* original 7eff, guest PC 0x0c0a85f0 */
if(!s->budget--) { s->failed_pc=0x0c0a85f0u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0a85f2;
P_0c0a85f2: /* original 9847, guest PC 0x0c0a85f2 */
if(!s->budget--) { s->failed_pc=0x0c0a85f2u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8684u,2);
goto P_0c0a85f4;
P_0c0a85f4: /* original 4e11, guest PC 0x0c0a85f4 */
if(!s->budget--) { s->failed_pc=0x0c0a85f4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0a85f6;
P_0c0a85f6: /* original 8900, guest PC 0x0c0a85f6 */
if(!s->budget--) { s->failed_pc=0x0c0a85f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a85fa; }
goto P_0c0a85f8;
P_0c0a85f8: /* original 6e83, guest PC 0x0c0a85f8 */
if(!s->budget--) { s->failed_pc=0x0c0a85f8u; return 0; }
r[14]=r[8];
goto P_0c0a85fa;
P_0c0a85fa: /* original 1de5, guest PC 0x0c0a85fa */
if(!s->budget--) { s->failed_pc=0x0c0a85fau; return 0; }
write(ram,r[13]+20,r[14],4);
goto P_0c0a85fc;
P_0c0a85fc: /* original 9043, guest PC 0x0c0a85fc */
if(!s->budget--) { s->failed_pc=0x0c0a85fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8686u,2);
goto P_0c0a85fe;
P_0c0a85fe: /* original 5444, guest PC 0x0c0a85fe */
if(!s->budget--) { s->failed_pc=0x0c0a85feu; return 0; }
r[4]=read(ram,r[4]+16,4);
goto P_0c0a8600;
P_0c0a8600: /* original 05ce, guest PC 0x0c0a8600 */
if(!s->budget--) { s->failed_pc=0x0c0a8600u; return 0; }
r[5]=read(ram,r[12]+r[0],4);
goto P_0c0a8602;
P_0c0a8602: /* original ec00, guest PC 0x0c0a8602 */
if(!s->budget--) { s->failed_pc=0x0c0a8602u; return 0; }
r[12]=0x00000000u;
goto P_0c0a8604;
P_0c0a8604: /* original 3540, guest PC 0x0c0a8604 */
if(!s->budget--) { s->failed_pc=0x0c0a8604u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[4])!=0);
goto P_0c0a8606;
P_0c0a8606: /* original 8d01, guest PC 0x0c0a8606 */
if(!s->budget--) { s->failed_pc=0x0c0a8606u; return 0; }
cond=r[17]&1u;
r[6]=r[12];
if(cond) { goto P_0c0a860c; }
goto P_0c0a860a;
P_0c0a8608: /* original 66c3, guest PC 0x0c0a8608 */
if(!s->budget--) { s->failed_pc=0x0c0a8608u; return 0; }
r[6]=r[12];
goto P_0c0a860a;
P_0c0a860a: /* original 66b3, guest PC 0x0c0a860a */
if(!s->budget--) { s->failed_pc=0x0c0a860au; return 0; }
r[6]=r[11];
goto P_0c0a860c;
P_0c0a860c: /* original e700, guest PC 0x0c0a860c */
if(!s->budget--) { s->failed_pc=0x0c0a860cu; return 0; }
r[7]=0x00000000u;
goto P_0c0a860e;
P_0c0a860e: /* original 65e3, guest PC 0x0c0a860e */
if(!s->budget--) { s->failed_pc=0x0c0a860eu; return 0; }
r[5]=r[14];
goto P_0c0a8610;
P_0c0a8610: /* original b04c, guest PC 0x0c0a8610 */
if(!s->budget--) { s->failed_pc=0x0c0a8610u; return 0; }
target=code_base|0x0c0a86acu; r[16]=code_base|0x0c0a8614u;
r[4]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8614u) { target=s->pc; goto dispatch; }
goto P_0c0a8614;
P_0c0a8612: /* original 6473, guest PC 0x0c0a8612 */
if(!s->budget--) { s->failed_pc=0x0c0a8612u; return 0; }
r[4]=r[7];
goto P_0c0a8614;
P_0c0a8614: /* original 6403, guest PC 0x0c0a8614 */
if(!s->budget--) { s->failed_pc=0x0c0a8614u; return 0; }
r[4]=r[0];
goto P_0c0a8616;
P_0c0a8616: /* original 7eff, guest PC 0x0c0a8616 */
if(!s->budget--) { s->failed_pc=0x0c0a8616u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0a8618;
P_0c0a8618: /* original 4e11, guest PC 0x0c0a8618 */
if(!s->budget--) { s->failed_pc=0x0c0a8618u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0a861a;
P_0c0a861a: /* original 8900, guest PC 0x0c0a861a */
if(!s->budget--) { s->failed_pc=0x0c0a861au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a861e; }
goto P_0c0a861c;
P_0c0a861c: /* original 6e83, guest PC 0x0c0a861c */
if(!s->budget--) { s->failed_pc=0x0c0a861cu; return 0; }
r[14]=r[8];
goto P_0c0a861e;
P_0c0a861e: /* original 4410, guest PC 0x0c0a861e */
if(!s->budget--) { s->failed_pc=0x0c0a861eu; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c0a8620;
P_0c0a8620: /* original 8bf9, guest PC 0x0c0a8620 */
if(!s->budget--) { s->failed_pc=0x0c0a8620u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8616; }
goto P_0c0a8622;
P_0c0a8622: /* original 64e3, guest PC 0x0c0a8622 */
if(!s->budget--) { s->failed_pc=0x0c0a8622u; return 0; }
r[4]=r[14];
goto P_0c0a8624;
P_0c0a8624: /* original 7401, guest PC 0x0c0a8624 */
if(!s->budget--) { s->failed_pc=0x0c0a8624u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a8626;
P_0c0a8626: /* original 3486, guest PC 0x0c0a8626 */
if(!s->budget--) { s->failed_pc=0x0c0a8626u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[8])!=0);
goto P_0c0a8628;
P_0c0a8628: /* original 8f01, guest PC 0x0c0a8628 */
if(!s->budget--) { s->failed_pc=0x0c0a8628u; return 0; }
cond=r[17]&1u;
write(ram,r[13]+24,r[14],4);
if(!cond) { goto P_0c0a862e; }
goto P_0c0a862c;
P_0c0a862a: /* original 1de6, guest PC 0x0c0a862a */
if(!s->budget--) { s->failed_pc=0x0c0a862au; return 0; }
write(ram,r[13]+24,r[14],4);
goto P_0c0a862c;
P_0c0a862c: /* original 64c3, guest PC 0x0c0a862c */
if(!s->budget--) { s->failed_pc=0x0c0a862cu; return 0; }
r[4]=r[12];
goto P_0c0a862e;
P_0c0a862e: /* original 6543, guest PC 0x0c0a862e */
if(!s->budget--) { s->failed_pc=0x0c0a862eu; return 0; }
r[5]=r[4];
goto P_0c0a8630;
P_0c0a8630: /* original 7501, guest PC 0x0c0a8630 */
if(!s->budget--) { s->failed_pc=0x0c0a8630u; return 0; }
r[5]+=0x00000001u;
goto P_0c0a8632;
P_0c0a8632: /* original 3586, guest PC 0x0c0a8632 */
if(!s->budget--) { s->failed_pc=0x0c0a8632u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[8])!=0);
goto P_0c0a8634;
P_0c0a8634: /* original 8b00, guest PC 0x0c0a8634 */
if(!s->budget--) { s->failed_pc=0x0c0a8634u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8638; }
goto P_0c0a8636;
P_0c0a8636: /* original 65c3, guest PC 0x0c0a8636 */
if(!s->budget--) { s->failed_pc=0x0c0a8636u; return 0; }
r[5]=r[12];
goto P_0c0a8638;
P_0c0a8638: /* original 4408, guest PC 0x0c0a8638 */
if(!s->budget--) { s->failed_pc=0x0c0a8638u; return 0; }
r[4]<<=2;
goto P_0c0a863a;
P_0c0a863a: /* original 1d54, guest PC 0x0c0a863a */
if(!s->budget--) { s->failed_pc=0x0c0a863au; return 0; }
write(ram,r[13]+16,r[5],4);
goto P_0c0a863c;
P_0c0a863c: /* original 4408, guest PC 0x0c0a863c */
if(!s->budget--) { s->failed_pc=0x0c0a863cu; return 0; }
r[4]<<=2;
goto P_0c0a863e;
P_0c0a863e: /* original de19, guest PC 0x0c0a863e */
if(!s->budget--) { s->failed_pc=0x0c0a863eu; return 0; }
r[14]=read(ram,0x0c0a86a4u,4);
goto P_0c0a8640;
P_0c0a8640: /* original 4408, guest PC 0x0c0a8640 */
if(!s->budget--) { s->failed_pc=0x0c0a8640u; return 0; }
r[4]<<=2;
goto P_0c0a8642;
P_0c0a8642: /* original 9221, guest PC 0x0c0a8642 */
if(!s->budget--) { s->failed_pc=0x0c0a8642u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8688u,2);
goto P_0c0a8644;
P_0c0a8644: /* original 4400, guest PC 0x0c0a8644 */
if(!s->budget--) { s->failed_pc=0x0c0a8644u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a8646;
P_0c0a8646: /* original 6593, guest PC 0x0c0a8646 */
if(!s->budget--) { s->failed_pc=0x0c0a8646u; return 0; }
r[5]=r[9];
goto P_0c0a8648;
P_0c0a8648: /* original 3e4c, guest PC 0x0c0a8648 */
if(!s->budget--) { s->failed_pc=0x0c0a8648u; return 0; }
r[14]+=r[4];
goto P_0c0a864a;
P_0c0a864a: /* original 66a3, guest PC 0x0c0a864a */
if(!s->budget--) { s->failed_pc=0x0c0a864au; return 0; }
r[6]=r[10];
goto P_0c0a864c;
P_0c0a864c: /* original 64e2, guest PC 0x0c0a864c */
if(!s->budget--) { s->failed_pc=0x0c0a864cu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0a864e;
P_0c0a864e: /* original 242b, guest PC 0x0c0a864e */
if(!s->budget--) { s->failed_pc=0x0c0a864eu; return 0; }
r[4]|=r[2];
goto P_0c0a8650;
P_0c0a8650: /* original 2e42, guest PC 0x0c0a8650 */
if(!s->budget--) { s->failed_pc=0x0c0a8650u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0a8652;
P_0c0a8652: /* original b4f0, guest PC 0x0c0a8652 */
if(!s->budget--) { s->failed_pc=0x0c0a8652u; return 0; }
target=code_base|0x0c0a9036u; r[16]=code_base|0x0c0a8656u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8656u) { target=s->pc; goto dispatch; }
goto P_0c0a8656;
P_0c0a8654: /* original 64e3, guest PC 0x0c0a8654 */
if(!s->budget--) { s->failed_pc=0x0c0a8654u; return 0; }
r[4]=r[14];
goto P_0c0a8656;
P_0c0a8656: /* original 7e40, guest PC 0x0c0a8656 */
if(!s->budget--) { s->failed_pc=0x0c0a8656u; return 0; }
r[14]+=0x00000040u;
goto P_0c0a8658;
P_0c0a8658: /* original 9316, guest PC 0x0c0a8658 */
if(!s->budget--) { s->failed_pc=0x0c0a8658u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8688u,2);
goto P_0c0a865a;
P_0c0a865a: /* original 62e2, guest PC 0x0c0a865a */
if(!s->budget--) { s->failed_pc=0x0c0a865au; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0a865c;
P_0c0a865c: /* original 65a3, guest PC 0x0c0a865c */
if(!s->budget--) { s->failed_pc=0x0c0a865cu; return 0; }
r[5]=r[10];
goto P_0c0a865e;
P_0c0a865e: /* original 6693, guest PC 0x0c0a865e */
if(!s->budget--) { s->failed_pc=0x0c0a865eu; return 0; }
r[6]=r[9];
goto P_0c0a8660;
P_0c0a8660: /* original 223b, guest PC 0x0c0a8660 */
if(!s->budget--) { s->failed_pc=0x0c0a8660u; return 0; }
r[2]|=r[3];
goto P_0c0a8662;
P_0c0a8662: /* original 2e22, guest PC 0x0c0a8662 */
if(!s->budget--) { s->failed_pc=0x0c0a8662u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a8664;
P_0c0a8664: /* original b4e7, guest PC 0x0c0a8664 */
if(!s->budget--) { s->failed_pc=0x0c0a8664u; return 0; }
target=code_base|0x0c0a9036u; r[16]=code_base|0x0c0a8668u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8668u) { target=s->pc; goto dispatch; }
goto P_0c0a8668;
P_0c0a8666: /* original 64e3, guest PC 0x0c0a8666 */
if(!s->budget--) { s->failed_pc=0x0c0a8666u; return 0; }
r[4]=r[14];
goto P_0c0a8668;
P_0c0a8668: /* original d30f, guest PC 0x0c0a8668 */
if(!s->budget--) { s->failed_pc=0x0c0a8668u; return 0; }
r[3]=read(ram,0x0c0a86a8u,4);
goto P_0c0a866a;
P_0c0a866a: /* original 1d33, guest PC 0x0c0a866a */
if(!s->budget--) { s->failed_pc=0x0c0a866au; return 0; }
write(ram,r[13]+12,r[3],4);
goto P_0c0a866c;
P_0c0a866c: /* original 7f0c, guest PC 0x0c0a866c */
if(!s->budget--) { s->failed_pc=0x0c0a866cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a866e;
P_0c0a866e: /* original 4f26, guest PC 0x0c0a866e */
if(!s->budget--) { s->failed_pc=0x0c0a866eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8670;
P_0c0a8670: /* original 68f6, guest PC 0x0c0a8670 */
if(!s->budget--) { s->failed_pc=0x0c0a8670u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a8672;
P_0c0a8672: /* original 69f6, guest PC 0x0c0a8672 */
if(!s->budget--) { s->failed_pc=0x0c0a8672u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a8674;
P_0c0a8674: /* original 6af6, guest PC 0x0c0a8674 */
if(!s->budget--) { s->failed_pc=0x0c0a8674u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8676;
P_0c0a8676: /* original 6bf6, guest PC 0x0c0a8676 */
if(!s->budget--) { s->failed_pc=0x0c0a8676u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8678;
P_0c0a8678: /* original 6cf6, guest PC 0x0c0a8678 */
if(!s->budget--) { s->failed_pc=0x0c0a8678u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a867a;
P_0c0a867a: /* original 6df6, guest PC 0x0c0a867a */
if(!s->budget--) { s->failed_pc=0x0c0a867au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a867c;
P_0c0a867c: /* original 000b, guest PC 0x0c0a867c */
if(!s->budget--) { s->failed_pc=0x0c0a867cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a867e: /* original 6ef6, guest PC 0x0c0a867e */
if(!s->budget--) { s->failed_pc=0x0c0a867eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a8680u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a8680u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
