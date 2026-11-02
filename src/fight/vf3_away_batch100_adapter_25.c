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
int vf3_away_batch100_adapter_25(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c0c109cu: goto P_0c0c109c;
case 0x0c0c109eu: goto P_0c0c109e;
case 0x0c0c10a0u: goto P_0c0c10a0;
case 0x0c0c1184u: goto P_0c0c1184;
case 0x0c0c1186u: goto P_0c0c1186;
case 0x0c0c1188u: goto P_0c0c1188;
case 0x0c0c118au: goto P_0c0c118a;
case 0x0c0c118cu: goto P_0c0c118c;
case 0x0c0c118eu: goto P_0c0c118e;
case 0x0c0c1190u: goto P_0c0c1190;
case 0x0c0c1836u: goto P_0c0c1836;
case 0x0c0c1838u: goto P_0c0c1838;
case 0x0c0c183au: goto P_0c0c183a;
case 0x0c0c183cu: goto P_0c0c183c;
case 0x0c0c183eu: goto P_0c0c183e;
case 0x0c0c1840u: goto P_0c0c1840;
case 0x0c0c1842u: goto P_0c0c1842;
case 0x0c0c1844u: goto P_0c0c1844;
case 0x0c0c1846u: goto P_0c0c1846;
case 0x0c0c1848u: goto P_0c0c1848;
case 0x0c0c184au: goto P_0c0c184a;
case 0x0c0c184cu: goto P_0c0c184c;
case 0x0c0c184eu: goto P_0c0c184e;
case 0x0c0c1850u: goto P_0c0c1850;
case 0x0c0c1852u: goto P_0c0c1852;
case 0x0c0c1854u: goto P_0c0c1854;
case 0x0c0c1856u: goto P_0c0c1856;
case 0x0c0c1858u: goto P_0c0c1858;
case 0x0c0c185au: goto P_0c0c185a;
case 0x0c0c185cu: goto P_0c0c185c;
case 0x0c0c185eu: goto P_0c0c185e;
case 0x0c0c1860u: goto P_0c0c1860;
case 0x0c0c1862u: goto P_0c0c1862;
case 0x0c0c1864u: goto P_0c0c1864;
case 0x0c0c1866u: goto P_0c0c1866;
case 0x0c0c1868u: goto P_0c0c1868;
case 0x0c0c186au: goto P_0c0c186a;
case 0x0c0c186cu: goto P_0c0c186c;
case 0x0c0c186eu: goto P_0c0c186e;
case 0x0c0c1870u: goto P_0c0c1870;
case 0x0c0c1872u: goto P_0c0c1872;
case 0x0c0c1874u: goto P_0c0c1874;
case 0x0c0c1876u: goto P_0c0c1876;
case 0x0c0c1878u: goto P_0c0c1878;
case 0x0c0c187au: goto P_0c0c187a;
case 0x0c0c187cu: goto P_0c0c187c;
case 0x0c0c187eu: goto P_0c0c187e;
case 0x0c0c1880u: goto P_0c0c1880;
case 0x0c0c1882u: goto P_0c0c1882;
case 0x0c0c1884u: goto P_0c0c1884;
case 0x0c0c1886u: goto P_0c0c1886;
case 0x0c0c1888u: goto P_0c0c1888;
case 0x0c0c188au: goto P_0c0c188a;
case 0x0c0c188cu: goto P_0c0c188c;
case 0x0c0c188eu: goto P_0c0c188e;
case 0x0c0c1890u: goto P_0c0c1890;
case 0x0c0c1892u: goto P_0c0c1892;
case 0x0c0c1894u: goto P_0c0c1894;
case 0x0c0c1896u: goto P_0c0c1896;
case 0x0c0c1898u: goto P_0c0c1898;
case 0x0c0c189au: goto P_0c0c189a;
case 0x0c0c189cu: goto P_0c0c189c;
case 0x0c0c189eu: goto P_0c0c189e;
case 0x0c0c18a0u: goto P_0c0c18a0;
case 0x0c0c18a2u: goto P_0c0c18a2;
case 0x0c0c18a4u: goto P_0c0c18a4;
case 0x0c0c18a6u: goto P_0c0c18a6;
case 0x0c0c18a8u: goto P_0c0c18a8;
case 0x0c0c18aau: goto P_0c0c18aa;
case 0x0c0c18acu: goto P_0c0c18ac;
case 0x0c0c18aeu: goto P_0c0c18ae;
case 0x0c0c18b0u: goto P_0c0c18b0;
case 0x0c0c18b2u: goto P_0c0c18b2;
case 0x0c0c18b4u: goto P_0c0c18b4;
case 0x0c0c18b6u: goto P_0c0c18b6;
case 0x0c0c18b8u: goto P_0c0c18b8;
case 0x0c0c18bau: goto P_0c0c18ba;
case 0x0c0c18bcu: goto P_0c0c18bc;
case 0x0c0c18beu: goto P_0c0c18be;
case 0x0c0c1a62u: goto P_0c0c1a62;
case 0x0c0c1a64u: goto P_0c0c1a64;
case 0x0c0c5eaeu: goto P_0c0c5eae;
case 0x0c0c5eb0u: goto P_0c0c5eb0;
case 0x0c0c5eb2u: goto P_0c0c5eb2;
case 0x0c0c5eb4u: goto P_0c0c5eb4;
case 0x0c0c5eb6u: goto P_0c0c5eb6;
case 0x0c0c5eb8u: goto P_0c0c5eb8;
case 0x0c0c5ebau: goto P_0c0c5eba;
case 0x0c0c5ebcu: goto P_0c0c5ebc;
case 0x0c0c5ebeu: goto P_0c0c5ebe;
case 0x0c0c5ec0u: goto P_0c0c5ec0;
case 0x0c0c5ec2u: goto P_0c0c5ec2;
case 0x0c0c5ec4u: goto P_0c0c5ec4;
case 0x0c0c5ec6u: goto P_0c0c5ec6;
case 0x0c0c5ec8u: goto P_0c0c5ec8;
case 0x0c0c5ecau: goto P_0c0c5eca;
case 0x0c0c5eccu: goto P_0c0c5ecc;
case 0x0c0c5eceu: goto P_0c0c5ece;
case 0x0c0c5ed0u: goto P_0c0c5ed0;
case 0x0c0c5ed2u: goto P_0c0c5ed2;
case 0x0c0c5ed4u: goto P_0c0c5ed4;
case 0x0c0c5ed6u: goto P_0c0c5ed6;
case 0x0c0c5ed8u: goto P_0c0c5ed8;
case 0x0c0c5edau: goto P_0c0c5eda;
case 0x0c0c5edcu: goto P_0c0c5edc;
case 0x0c0c5edeu: goto P_0c0c5ede;
case 0x0c0c5ee0u: goto P_0c0c5ee0;
case 0x0c0c5ee2u: goto P_0c0c5ee2;
case 0x0c0c5ee4u: goto P_0c0c5ee4;
case 0x0c0c5ee6u: goto P_0c0c5ee6;
case 0x0c0c5ee8u: goto P_0c0c5ee8;
case 0x0c0c5eeau: goto P_0c0c5eea;
case 0x0c0c5eecu: goto P_0c0c5eec;
case 0x0c0c5eeeu: goto P_0c0c5eee;
case 0x0c0c5ef0u: goto P_0c0c5ef0;
case 0x0c0c5ef2u: goto P_0c0c5ef2;
case 0x0c0c5ef4u: goto P_0c0c5ef4;
case 0x0c0c5ef6u: goto P_0c0c5ef6;
case 0x0c0c5ef8u: goto P_0c0c5ef8;
case 0x0c0c5efau: goto P_0c0c5efa;
case 0x0c0c5efcu: goto P_0c0c5efc;
case 0x0c0c5efeu: goto P_0c0c5efe;
case 0x0c0c5f00u: goto P_0c0c5f00;
case 0x0c0c5f02u: goto P_0c0c5f02;
case 0x0c0c5f04u: goto P_0c0c5f04;
case 0x0c0c5f06u: goto P_0c0c5f06;
case 0x0c0c5f08u: goto P_0c0c5f08;
case 0x0c0c5f0au: goto P_0c0c5f0a;
case 0x0c0c5f0cu: goto P_0c0c5f0c;
case 0x0c0c5f0eu: goto P_0c0c5f0e;
case 0x0c0c5f10u: goto P_0c0c5f10;
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
P_0c0c109c: /* original d34f, guest PC 0x0c0c109c */
if(!s->budget--) { s->failed_pc=0x0c0c109cu; return 0; }
r[3]=read(ram,0x0c0c11dcu,4);
goto P_0c0c109e;
P_0c0c109e: /* original 432b, guest PC 0x0c0c109e */
if(!s->budget--) { s->failed_pc=0x0c0c109eu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c07b204u: return vf3_matrix_family(0x0c07b204u,s,ram);
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
P_0c0c10a0: /* original 0009, guest PC 0x0c0c10a0 */
if(!s->budget--) { s->failed_pc=0x0c0c10a0u; return 0; }
if(!vf3_matrix_family(0x0c0c10a2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c10a2u; return 0; } return 1;
P_0c0c1184: /* original 4f22, guest PC 0x0c0c1184 */
if(!s->budget--) { s->failed_pc=0x0c0c1184u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c1186;
P_0c0c1186: /* original 0546, guest PC 0x0c0c1186 */
if(!s->budget--) { s->failed_pc=0x0c0c1186u; return 0; }
write(ram,r[5]+r[0],r[4],4);
goto P_0c0c1188;
P_0c0c1188: /* original 7004, guest PC 0x0c0c1188 */
if(!s->budget--) { s->failed_pc=0x0c0c1188u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c118a;
P_0c0c118a: /* original b46a, guest PC 0x0c0c118a */
if(!s->budget--) { s->failed_pc=0x0c0c118au; return 0; }
target=code_base|0x0c0c1a62u; r[16]=code_base|0x0c0c118eu;
write(ram,r[5]+r[0],r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c118eu) { target=s->pc; goto dispatch; }
goto P_0c0c118e;
P_0c0c118c: /* original 0546, guest PC 0x0c0c118c */
if(!s->budget--) { s->failed_pc=0x0c0c118cu; return 0; }
write(ram,r[5]+r[0],r[4],4);
goto P_0c0c118e;
P_0c0c118e: /* original af85, guest PC 0x0c0c118e */
if(!s->budget--) { s->failed_pc=0x0c0c118eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c109c;
P_0c0c1190: /* original 4f26, guest PC 0x0c0c1190 */
if(!s->budget--) { s->failed_pc=0x0c0c1190u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0c1192u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c1192u; return 0; } return 1;
P_0c0c1836: /* original 2fe6, guest PC 0x0c0c1836 */
if(!s->budget--) { s->failed_pc=0x0c0c1836u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1838;
P_0c0c1838: /* original 6053, guest PC 0x0c0c1838 */
if(!s->budget--) { s->failed_pc=0x0c0c1838u; return 0; }
r[0]=r[5];
goto P_0c0c183a;
P_0c0c183a: /* original 2fc6, guest PC 0x0c0c183a */
if(!s->budget--) { s->failed_pc=0x0c0c183au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c183c;
P_0c0c183c: /* original e3f9, guest PC 0x0c0c183c */
if(!s->budget--) { s->failed_pc=0x0c0c183cu; return 0; }
r[3]=0xfffffff9u;
goto P_0c0c183e;
P_0c0c183e: /* original 2fb6, guest PC 0x0c0c183e */
if(!s->budget--) { s->failed_pc=0x0c0c183eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1840;
P_0c0c1840: /* original ec3f, guest PC 0x0c0c1840 */
if(!s->budget--) { s->failed_pc=0x0c0c1840u; return 0; }
r[12]=0x0000003fu;
goto P_0c0c1842;
P_0c0c1842: /* original 2fa6, guest PC 0x0c0c1842 */
if(!s->budget--) { s->failed_pc=0x0c0c1842u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1844;
P_0c0c1844: /* original eb3f, guest PC 0x0c0c1844 */
if(!s->budget--) { s->failed_pc=0x0c0c1844u; return 0; }
r[11]=0x0000003fu;
goto P_0c0c1846;
P_0c0c1846: /* original 453d, guest PC 0x0c0c1846 */
if(!s->budget--) { s->failed_pc=0x0c0c1846u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c0c1848;
P_0c0c1848: /* original 2f96, guest PC 0x0c0c1848 */
if(!s->budget--) { s->failed_pc=0x0c0c1848u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c184a;
P_0c0c184a: /* original 4001, guest PC 0x0c0c184a */
if(!s->budget--) { s->failed_pc=0x0c0c184au; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c0c184c;
P_0c0c184c: /* original 2f86, guest PC 0x0c0c184c */
if(!s->budget--) { s->failed_pc=0x0c0c184cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c184e;
P_0c0c184e: /* original 2b59, guest PC 0x0c0c184e */
if(!s->budget--) { s->failed_pc=0x0c0c184eu; return 0; }
r[11]&=r[5];
goto P_0c0c1850;
P_0c0c1850: /* original 5e43, guest PC 0x0c0c1850 */
if(!s->budget--) { s->failed_pc=0x0c0c1850u; return 0; }
r[14]=read(ram,r[4]+12,4);
goto P_0c0c1852;
P_0c0c1852: /* original 2c09, guest PC 0x0c0c1852 */
if(!s->budget--) { s->failed_pc=0x0c0c1852u; return 0; }
r[12]&=r[0];
goto P_0c0c1854;
P_0c0c1854: /* original e801, guest PC 0x0c0c1854 */
if(!s->budget--) { s->failed_pc=0x0c0c1854u; return 0; }
r[8]=0x00000001u;
goto P_0c0c1856;
P_0c0c1856: /* original ea00, guest PC 0x0c0c1856 */
if(!s->budget--) { s->failed_pc=0x0c0c1856u; return 0; }
r[10]=0x00000000u;
goto P_0c0c1858;
P_0c0c1858: /* original 36cc, guest PC 0x0c0c1858 */
if(!s->budget--) { s->failed_pc=0x0c0c1858u; return 0; }
r[6]+=r[12];
goto P_0c0c185a;
P_0c0c185a: /* original 37bc, guest PC 0x0c0c185a */
if(!s->budget--) { s->failed_pc=0x0c0c185au; return 0; }
r[7]+=r[11];
goto P_0c0c185c;
P_0c0c185c: /* original a021, guest PC 0x0c0c185c */
if(!s->budget--) { s->failed_pc=0x0c0c185cu; return 0; }
r[9]=r[10];
goto P_0c0c18a2;
P_0c0c185e: /* original 69a3, guest PC 0x0c0c185e */
if(!s->budget--) { s->failed_pc=0x0c0c185eu; return 0; }
r[9]=r[10];
goto P_0c0c1860;
P_0c0c1860: /* original 63e1, guest PC 0x0c0c1860 */
if(!s->budget--) { s->failed_pc=0x0c0c1860u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[3]=tmp;
goto P_0c0c1862;
P_0c0c1862: /* original 633d, guest PC 0x0c0c1862 */
if(!s->budget--) { s->failed_pc=0x0c0c1862u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c1864;
P_0c0c1864: /* original 2388, guest PC 0x0c0c1864 */
if(!s->budget--) { s->failed_pc=0x0c0c1864u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0c1866;
P_0c0c1866: /* original 891a, guest PC 0x0c0c1866 */
if(!s->budget--) { s->failed_pc=0x0c0c1866u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c1868;
P_0c0c1868: /* original 85e3, guest PC 0x0c0c1868 */
if(!s->budget--) { s->failed_pc=0x0c0c1868u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+6,2);
goto P_0c0c186a;
P_0c0c186a: /* original 610d, guest PC 0x0c0c186a */
if(!s->budget--) { s->failed_pc=0x0c0c186au; return 0; }
r[1]=r[0]&65535u;
goto P_0c0c186c;
P_0c0c186c: /* original 85e4, guest PC 0x0c0c186c */
if(!s->budget--) { s->failed_pc=0x0c0c186cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+8,2);
goto P_0c0c186e;
P_0c0c186e: /* original 3c17, guest PC 0x0c0c186e */
if(!s->budget--) { s->failed_pc=0x0c0c186eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>(int32_t)r[1])!=0);
goto P_0c0c1870;
P_0c0c1870: /* original 8d15, guest PC 0x0c0c1870 */
if(!s->budget--) { s->failed_pc=0x0c0c1870u; return 0; }
cond=r[17]&1u;
r[5]=r[0]&65535u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c1874;
P_0c0c1872: /* original 650d, guest PC 0x0c0c1872 */
if(!s->budget--) { s->failed_pc=0x0c0c1872u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0c1874;
P_0c0c1874: /* original 3166, guest PC 0x0c0c1874 */
if(!s->budget--) { s->failed_pc=0x0c0c1874u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[6])!=0);
goto P_0c0c1876;
P_0c0c1876: /* original 8912, guest PC 0x0c0c1876 */
if(!s->budget--) { s->failed_pc=0x0c0c1876u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c1878;
P_0c0c1878: /* original 3b57, guest PC 0x0c0c1878 */
if(!s->budget--) { s->failed_pc=0x0c0c1878u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>(int32_t)r[5])!=0);
goto P_0c0c187a;
P_0c0c187a: /* original 8910, guest PC 0x0c0c187a */
if(!s->budget--) { s->failed_pc=0x0c0c187au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c187c;
P_0c0c187c: /* original 3576, guest PC 0x0c0c187c */
if(!s->budget--) { s->failed_pc=0x0c0c187cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[7])!=0);
goto P_0c0c187e;
P_0c0c187e: /* original 890e, guest PC 0x0c0c187e */
if(!s->budget--) { s->failed_pc=0x0c0c187eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c1880;
P_0c0c1880: /* original 85e5, guest PC 0x0c0c1880 */
if(!s->budget--) { s->failed_pc=0x0c0c1880u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+10,2);
goto P_0c0c1882;
P_0c0c1882: /* original 600d, guest PC 0x0c0c1882 */
if(!s->budget--) { s->failed_pc=0x0c0c1882u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c1884;
P_0c0c1884: /* original 310c, guest PC 0x0c0c1884 */
if(!s->budget--) { s->failed_pc=0x0c0c1884u; return 0; }
r[1]+=r[0];
goto P_0c0c1886;
P_0c0c1886: /* original 85e6, guest PC 0x0c0c1886 */
if(!s->budget--) { s->failed_pc=0x0c0c1886u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0c1888;
P_0c0c1888: /* original 3c17, guest PC 0x0c0c1888 */
if(!s->budget--) { s->failed_pc=0x0c0c1888u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>(int32_t)r[1])!=0);
goto P_0c0c188a;
P_0c0c188a: /* original 600d, guest PC 0x0c0c188a */
if(!s->budget--) { s->failed_pc=0x0c0c188au; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c188c;
P_0c0c188c: /* original 8d07, guest PC 0x0c0c188c */
if(!s->budget--) { s->failed_pc=0x0c0c188cu; return 0; }
cond=r[17]&1u;
r[5]+=r[0];
if(cond) { goto P_0c0c189e; }
goto P_0c0c1890;
P_0c0c188e: /* original 350c, guest PC 0x0c0c188e */
if(!s->budget--) { s->failed_pc=0x0c0c188eu; return 0; }
r[5]+=r[0];
goto P_0c0c1890;
P_0c0c1890: /* original 3166, guest PC 0x0c0c1890 */
if(!s->budget--) { s->failed_pc=0x0c0c1890u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[6])!=0);
goto P_0c0c1892;
P_0c0c1892: /* original 8904, guest PC 0x0c0c1892 */
if(!s->budget--) { s->failed_pc=0x0c0c1892u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c1894;
P_0c0c1894: /* original 3b57, guest PC 0x0c0c1894 */
if(!s->budget--) { s->failed_pc=0x0c0c1894u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>(int32_t)r[5])!=0);
goto P_0c0c1896;
P_0c0c1896: /* original 8902, guest PC 0x0c0c1896 */
if(!s->budget--) { s->failed_pc=0x0c0c1896u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c1898;
P_0c0c1898: /* original 3576, guest PC 0x0c0c1898 */
if(!s->budget--) { s->failed_pc=0x0c0c1898u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[7])!=0);
goto P_0c0c189a;
P_0c0c189a: /* original 8900, guest PC 0x0c0c189a */
if(!s->budget--) { s->failed_pc=0x0c0c189au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c189e; }
goto P_0c0c189c;
P_0c0c189c: /* original 2ea1, guest PC 0x0c0c189c */
if(!s->budget--) { s->failed_pc=0x0c0c189cu; return 0; }
write(ram,r[14],r[10],2);
goto P_0c0c189e;
P_0c0c189e: /* original 7e44, guest PC 0x0c0c189e */
if(!s->budget--) { s->failed_pc=0x0c0c189eu; return 0; }
r[14]+=0x00000044u;
goto P_0c0c18a0;
P_0c0c18a0: /* original 7901, guest PC 0x0c0c18a0 */
if(!s->budget--) { s->failed_pc=0x0c0c18a0u; return 0; }
r[9]+=0x00000001u;
goto P_0c0c18a2;
P_0c0c18a2: /* original e278, guest PC 0x0c0c18a2 */
if(!s->budget--) { s->failed_pc=0x0c0c18a2u; return 0; }
r[2]=0x00000078u;
goto P_0c0c18a4;
P_0c0c18a4: /* original 3922, guest PC 0x0c0c18a4 */
if(!s->budget--) { s->failed_pc=0x0c0c18a4u; return 0; }
r[17]=(r[17]&~1u)|((r[9]>=r[2])!=0);
goto P_0c0c18a6;
P_0c0c18a6: /* original 8bdb, guest PC 0x0c0c18a6 */
if(!s->budget--) { s->failed_pc=0x0c0c18a6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1860; }
goto P_0c0c18a8;
P_0c0c18a8: /* original e022, guest PC 0x0c0c18a8 */
if(!s->budget--) { s->failed_pc=0x0c0c18a8u; return 0; }
r[0]=0x00000022u;
goto P_0c0c18aa;
P_0c0c18aa: /* original 024d, guest PC 0x0c0c18aa */
if(!s->budget--) { s->failed_pc=0x0c0c18aau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c18ac;
P_0c0c18ac: /* original e301, guest PC 0x0c0c18ac */
if(!s->budget--) { s->failed_pc=0x0c0c18acu; return 0; }
r[3]=0x00000001u;
goto P_0c0c18ae;
P_0c0c18ae: /* original 223b, guest PC 0x0c0c18ae */
if(!s->budget--) { s->failed_pc=0x0c0c18aeu; return 0; }
r[2]|=r[3];
goto P_0c0c18b0;
P_0c0c18b0: /* original 0425, guest PC 0x0c0c18b0 */
if(!s->budget--) { s->failed_pc=0x0c0c18b0u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0c18b2;
P_0c0c18b2: /* original 68f6, guest PC 0x0c0c18b2 */
if(!s->budget--) { s->failed_pc=0x0c0c18b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c18b4;
P_0c0c18b4: /* original 69f6, guest PC 0x0c0c18b4 */
if(!s->budget--) { s->failed_pc=0x0c0c18b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c18b6;
P_0c0c18b6: /* original 6af6, guest PC 0x0c0c18b6 */
if(!s->budget--) { s->failed_pc=0x0c0c18b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c18b8;
P_0c0c18b8: /* original 6bf6, guest PC 0x0c0c18b8 */
if(!s->budget--) { s->failed_pc=0x0c0c18b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c18ba;
P_0c0c18ba: /* original 6cf6, guest PC 0x0c0c18ba */
if(!s->budget--) { s->failed_pc=0x0c0c18bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c18bc;
P_0c0c18bc: /* original 000b, guest PC 0x0c0c18bc */
if(!s->budget--) { s->failed_pc=0x0c0c18bcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c18be: /* original 6ef6, guest PC 0x0c0c18be */
if(!s->budget--) { s->failed_pc=0x0c0c18beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c18c0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c18c0u; return 0; } return 1;
P_0c0c1a62: /* original 000b, guest PC 0x0c0c1a62 */
if(!s->budget--) { s->failed_pc=0x0c0c1a62u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c1a64: /* original 0009, guest PC 0x0c0c1a64 */
if(!s->budget--) { s->failed_pc=0x0c0c1a64u; return 0; }
if(!vf3_matrix_family(0x0c0c1a66u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c1a66u; return 0; } return 1;
P_0c0c5eae: /* original 2fe6, guest PC 0x0c0c5eae */
if(!s->budget--) { s->failed_pc=0x0c0c5eaeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5eb0;
P_0c0c5eb0: /* original 2fd6, guest PC 0x0c0c5eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5eb2;
P_0c0c5eb2: /* original ed1f, guest PC 0x0c0c5eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb2u; return 0; }
r[13]=0x0000001fu;
goto P_0c0c5eb4;
P_0c0c5eb4: /* original 2d49, guest PC 0x0c0c5eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb4u; return 0; }
r[13]&=r[4];
goto P_0c0c5eb6;
P_0c0c5eb6: /* original d31b, guest PC 0x0c0c5eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb6u; return 0; }
r[3]=read(ram,0x0c0c5f24u,4);
goto P_0c0c5eb8;
P_0c0c5eb8: /* original 4d00, guest PC 0x0c0c5eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c5eb8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c0c5eba;
P_0c0c5eba: /* original 6ed3, guest PC 0x0c0c5eba */
if(!s->budget--) { s->failed_pc=0x0c0c5ebau; return 0; }
r[14]=r[13];
goto P_0c0c5ebc;
P_0c0c5ebc: /* original 4e08, guest PC 0x0c0c5ebc */
if(!s->budget--) { s->failed_pc=0x0c0c5ebcu; return 0; }
r[14]<<=2;
goto P_0c0c5ebe;
P_0c0c5ebe: /* original 3e3c, guest PC 0x0c0c5ebe */
if(!s->budget--) { s->failed_pc=0x0c0c5ebeu; return 0; }
r[14]+=r[3];
goto P_0c0c5ec0;
P_0c0c5ec0: /* original 62e2, guest PC 0x0c0c5ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0c5ec2;
P_0c0c5ec2: /* original 4f22, guest PC 0x0c0c5ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5ec4;
P_0c0c5ec4: /* original 2228, guest PC 0x0c0c5ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c5ec6;
P_0c0c5ec6: /* original 8920, guest PC 0x0c0c5ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5f0a; }
goto P_0c0c5ec8;
P_0c0c5ec8: /* original d217, guest PC 0x0c0c5ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ec8u; return 0; }
r[2]=read(ram,0x0c0c5f28u,4);
goto P_0c0c5eca;
P_0c0c5eca: /* original 61e2, guest PC 0x0c0c5eca */
if(!s->budget--) { s->failed_pc=0x0c0c5ecau; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0c5ecc;
P_0c0c5ecc: /* original 6022, guest PC 0x0c0c5ecc */
if(!s->budget--) { s->failed_pc=0x0c0c5eccu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0c5ece;
P_0c0c5ece: /* original 3010, guest PC 0x0c0c5ece */
if(!s->budget--) { s->failed_pc=0x0c0c5eceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0c5ed0;
P_0c0c5ed0: /* original 891b, guest PC 0x0c0c5ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5f0a; }
goto P_0c0c5ed2;
P_0c0c5ed2: /* original d317, guest PC 0x0c0c5ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed2u; return 0; }
r[3]=read(ram,0x0c0c5f30u,4);
goto P_0c0c5ed4;
P_0c0c5ed4: /* original d115, guest PC 0x0c0c5ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed4u; return 0; }
r[1]=read(ram,0x0c0c5f2cu,4);
goto P_0c0c5ed6;
P_0c0c5ed6: /* original 6532, guest PC 0x0c0c5ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed6u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0c5ed8;
P_0c0c5ed8: /* original d216, guest PC 0x0c0c5ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ed8u; return 0; }
r[2]=read(ram,0x0c0c5f34u,4);
goto P_0c0c5eda;
P_0c0c5eda: /* original 351c, guest PC 0x0c0c5eda */
if(!s->budget--) { s->failed_pc=0x0c0c5edau; return 0; }
r[5]+=r[1];
goto P_0c0c5edc;
P_0c0c5edc: /* original 420b, guest PC 0x0c0c5edc */
if(!s->budget--) { s->failed_pc=0x0c0c5edcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c5ee0u;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5ee0u) { target=s->pc; goto dispatch; }
goto P_0c0c5ee0;
P_0c0c5ede: /* original 64e2, guest PC 0x0c0c5ede */
if(!s->budget--) { s->failed_pc=0x0c0c5edeu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0c5ee0;
P_0c0c5ee0: /* original d30e, guest PC 0x0c0c5ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee0u; return 0; }
r[3]=read(ram,0x0c0c5f1cu,4);
goto P_0c0c5ee2;
P_0c0c5ee2: /* original 430b, guest PC 0x0c0c5ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5ee6u;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5ee6u) { target=s->pc; goto dispatch; }
goto P_0c0c5ee6;
P_0c0c5ee4: /* original e404, guest PC 0x0c0c5ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee4u; return 0; }
r[4]=0x00000004u;
goto P_0c0c5ee6;
P_0c0c5ee6: /* original d212, guest PC 0x0c0c5ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee6u; return 0; }
r[2]=read(ram,0x0c0c5f30u,4);
goto P_0c0c5ee8;
P_0c0c5ee8: /* original e504, guest PC 0x0c0c5ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ee8u; return 0; }
r[5]=0x00000004u;
goto P_0c0c5eea;
P_0c0c5eea: /* original d113, guest PC 0x0c0c5eea */
if(!s->budget--) { s->failed_pc=0x0c0c5eeau; return 0; }
r[1]=read(ram,0x0c0c5f38u,4);
goto P_0c0c5eec;
P_0c0c5eec: /* original 6422, guest PC 0x0c0c5eec */
if(!s->budget--) { s->failed_pc=0x0c0c5eecu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0c5eee;
P_0c0c5eee: /* original d30f, guest PC 0x0c0c5eee */
if(!s->budget--) { s->failed_pc=0x0c0c5eeeu; return 0; }
r[3]=read(ram,0x0c0c5f2cu,4);
goto P_0c0c5ef0;
P_0c0c5ef0: /* original 410b, guest PC 0x0c0c5ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef0u; return 0; }
target=r[1];
r[16]=code_base|0x0c0c5ef4u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5ef4u) { target=s->pc; goto dispatch; }
goto P_0c0c5ef4;
P_0c0c5ef2: /* original 343c, guest PC 0x0c0c5ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef2u; return 0; }
r[4]+=r[3];
goto P_0c0c5ef4;
P_0c0c5ef4: /* original 2008, guest PC 0x0c0c5ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c5ef6;
P_0c0c5ef6: /* original 8903, guest PC 0x0c0c5ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5f00; }
goto P_0c0c5ef8;
P_0c0c5ef8: /* original d210, guest PC 0x0c0c5ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ef8u; return 0; }
r[2]=read(ram,0x0c0c5f3cu,4);
goto P_0c0c5efa;
P_0c0c5efa: /* original 950a, guest PC 0x0c0c5efa */
if(!s->budget--) { s->failed_pc=0x0c0c5efau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5f12u,2);
goto P_0c0c5efc;
P_0c0c5efc: /* original 420b, guest PC 0x0c0c5efc */
if(!s->budget--) { s->failed_pc=0x0c0c5efcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c5f00u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5f00u) { target=s->pc; goto dispatch; }
goto P_0c0c5f00;
P_0c0c5efe: /* original e401, guest PC 0x0c0c5efe */
if(!s->budget--) { s->failed_pc=0x0c0c5efeu; return 0; }
r[4]=0x00000001u;
goto P_0c0c5f00;
P_0c0c5f00: /* original d008, guest PC 0x0c0c5f00 */
if(!s->budget--) { s->failed_pc=0x0c0c5f00u; return 0; }
r[0]=read(ram,0x0c0c5f24u,4);
goto P_0c0c5f02;
P_0c0c5f02: /* original 4d08, guest PC 0x0c0c5f02 */
if(!s->budget--) { s->failed_pc=0x0c0c5f02u; return 0; }
r[13]<<=2;
goto P_0c0c5f04;
P_0c0c5f04: /* original d308, guest PC 0x0c0c5f04 */
if(!s->budget--) { s->failed_pc=0x0c0c5f04u; return 0; }
r[3]=read(ram,0x0c0c5f28u,4);
goto P_0c0c5f06;
P_0c0c5f06: /* original 02de, guest PC 0x0c0c5f06 */
if(!s->budget--) { s->failed_pc=0x0c0c5f06u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c0c5f08;
P_0c0c5f08: /* original 2322, guest PC 0x0c0c5f08 */
if(!s->budget--) { s->failed_pc=0x0c0c5f08u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0c5f0a;
P_0c0c5f0a: /* original 4f26, guest PC 0x0c0c5f0a */
if(!s->budget--) { s->failed_pc=0x0c0c5f0au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5f0c;
P_0c0c5f0c: /* original 6df6, guest PC 0x0c0c5f0c */
if(!s->budget--) { s->failed_pc=0x0c0c5f0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5f0e;
P_0c0c5f0e: /* original 000b, guest PC 0x0c0c5f0e */
if(!s->budget--) { s->failed_pc=0x0c0c5f0eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5f10: /* original 6ef6, guest PC 0x0c0c5f10 */
if(!s->budget--) { s->failed_pc=0x0c0c5f10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c5f12u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5f12u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
