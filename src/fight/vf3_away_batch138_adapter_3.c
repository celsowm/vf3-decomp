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
int vf3_away_batch138_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0ab8a0u: goto P_0c0ab8a0;
case 0x0c0ab8a2u: goto P_0c0ab8a2;
case 0x0c0ab8a4u: goto P_0c0ab8a4;
case 0x0c0ab8a6u: goto P_0c0ab8a6;
case 0x0c0ab8a8u: goto P_0c0ab8a8;
case 0x0c0ab8aau: goto P_0c0ab8aa;
case 0x0c0ab8acu: goto P_0c0ab8ac;
case 0x0c0ab8aeu: goto P_0c0ab8ae;
case 0x0c0ab8b0u: goto P_0c0ab8b0;
case 0x0c0ab8b2u: goto P_0c0ab8b2;
case 0x0c0ab8b4u: goto P_0c0ab8b4;
case 0x0c0ab8b6u: goto P_0c0ab8b6;
case 0x0c0ab8b8u: goto P_0c0ab8b8;
case 0x0c0ab8bau: goto P_0c0ab8ba;
case 0x0c0ab8bcu: goto P_0c0ab8bc;
case 0x0c0ab8beu: goto P_0c0ab8be;
case 0x0c0ab8c0u: goto P_0c0ab8c0;
case 0x0c0ab8c2u: goto P_0c0ab8c2;
case 0x0c0ab8c4u: goto P_0c0ab8c4;
case 0x0c0ab8c6u: goto P_0c0ab8c6;
case 0x0c0ab8c8u: goto P_0c0ab8c8;
case 0x0c0ab8cau: goto P_0c0ab8ca;
case 0x0c0ab8ccu: goto P_0c0ab8cc;
case 0x0c0ab8ceu: goto P_0c0ab8ce;
case 0x0c0ab8d0u: goto P_0c0ab8d0;
case 0x0c0ab8d2u: goto P_0c0ab8d2;
case 0x0c0ab8d4u: goto P_0c0ab8d4;
case 0x0c0ab8d6u: goto P_0c0ab8d6;
case 0x0c0ab8d8u: goto P_0c0ab8d8;
case 0x0c0ab8dau: goto P_0c0ab8da;
case 0x0c0ab8dcu: goto P_0c0ab8dc;
case 0x0c0ab8deu: goto P_0c0ab8de;
case 0x0c0ab8e0u: goto P_0c0ab8e0;
case 0x0c0ab8e2u: goto P_0c0ab8e2;
case 0x0c0ab8e4u: goto P_0c0ab8e4;
case 0x0c0ab8e6u: goto P_0c0ab8e6;
case 0x0c0ab8e8u: goto P_0c0ab8e8;
case 0x0c0ab8eau: goto P_0c0ab8ea;
case 0x0c0ab8ecu: goto P_0c0ab8ec;
case 0x0c0ab8eeu: goto P_0c0ab8ee;
case 0x0c0ab8f0u: goto P_0c0ab8f0;
case 0x0c0ab8f2u: goto P_0c0ab8f2;
case 0x0c0ab8f4u: goto P_0c0ab8f4;
case 0x0c0ab8f6u: goto P_0c0ab8f6;
case 0x0c0ab8f8u: goto P_0c0ab8f8;
case 0x0c0ab8fau: goto P_0c0ab8fa;
case 0x0c0ab8fcu: goto P_0c0ab8fc;
case 0x0c0ab8feu: goto P_0c0ab8fe;
case 0x0c0ab900u: goto P_0c0ab900;
case 0x0c0ab902u: goto P_0c0ab902;
case 0x0c0ab904u: goto P_0c0ab904;
case 0x0c0ab906u: goto P_0c0ab906;
case 0x0c0ab908u: goto P_0c0ab908;
case 0x0c0ab90au: goto P_0c0ab90a;
case 0x0c0ab90cu: goto P_0c0ab90c;
case 0x0c0ab90eu: goto P_0c0ab90e;
case 0x0c0ab910u: goto P_0c0ab910;
case 0x0c0ab912u: goto P_0c0ab912;
case 0x0c0ab914u: goto P_0c0ab914;
case 0x0c0ab916u: goto P_0c0ab916;
case 0x0c0ab918u: goto P_0c0ab918;
case 0x0c0ab91au: goto P_0c0ab91a;
case 0x0c0ab91cu: goto P_0c0ab91c;
case 0x0c0ab91eu: goto P_0c0ab91e;
case 0x0c0ab920u: goto P_0c0ab920;
case 0x0c0ab922u: goto P_0c0ab922;
case 0x0c0ab924u: goto P_0c0ab924;
case 0x0c0ab926u: goto P_0c0ab926;
case 0x0c0ab928u: goto P_0c0ab928;
case 0x0c0ab92au: goto P_0c0ab92a;
case 0x0c0ab92cu: goto P_0c0ab92c;
case 0x0c0ab92eu: goto P_0c0ab92e;
case 0x0c0ab930u: goto P_0c0ab930;
case 0x0c0ab932u: goto P_0c0ab932;
case 0x0c0ab934u: goto P_0c0ab934;
case 0x0c0ab936u: goto P_0c0ab936;
case 0x0c0ab938u: goto P_0c0ab938;
case 0x0c0ab93au: goto P_0c0ab93a;
case 0x0c0ab93cu: goto P_0c0ab93c;
case 0x0c0ab93eu: goto P_0c0ab93e;
case 0x0c0ab940u: goto P_0c0ab940;
case 0x0c0ab942u: goto P_0c0ab942;
case 0x0c0ab944u: goto P_0c0ab944;
case 0x0c0ab946u: goto P_0c0ab946;
case 0x0c0ab948u: goto P_0c0ab948;
case 0x0c0ab94au: goto P_0c0ab94a;
case 0x0c0ab94cu: goto P_0c0ab94c;
case 0x0c0ab94eu: goto P_0c0ab94e;
case 0x0c0ab950u: goto P_0c0ab950;
case 0x0c0ab952u: goto P_0c0ab952;
case 0x0c0ab954u: goto P_0c0ab954;
case 0x0c0ab956u: goto P_0c0ab956;
case 0x0c0ab958u: goto P_0c0ab958;
case 0x0c0ab95au: goto P_0c0ab95a;
case 0x0c0ab95cu: goto P_0c0ab95c;
case 0x0c0ab95eu: goto P_0c0ab95e;
case 0x0c0ab960u: goto P_0c0ab960;
case 0x0c0ab962u: goto P_0c0ab962;
case 0x0c0ab964u: goto P_0c0ab964;
case 0x0c0ab966u: goto P_0c0ab966;
case 0x0c0ab968u: goto P_0c0ab968;
case 0x0c0ab96au: goto P_0c0ab96a;
case 0x0c0ab96cu: goto P_0c0ab96c;
case 0x0c0ab96eu: goto P_0c0ab96e;
case 0x0c0ab970u: goto P_0c0ab970;
case 0x0c0ab972u: goto P_0c0ab972;
case 0x0c0ab974u: goto P_0c0ab974;
case 0x0c0ab976u: goto P_0c0ab976;
case 0x0c0ab978u: goto P_0c0ab978;
case 0x0c0ab97au: goto P_0c0ab97a;
case 0x0c0ab97cu: goto P_0c0ab97c;
case 0x0c0ab97eu: goto P_0c0ab97e;
case 0x0c0ab980u: goto P_0c0ab980;
case 0x0c0ab982u: goto P_0c0ab982;
case 0x0c0ab984u: goto P_0c0ab984;
case 0x0c0ab986u: goto P_0c0ab986;
case 0x0c0ab988u: goto P_0c0ab988;
case 0x0c0ab98au: goto P_0c0ab98a;
case 0x0c0ab98cu: goto P_0c0ab98c;
case 0x0c0ab98eu: goto P_0c0ab98e;
case 0x0c0ab9c0u: goto P_0c0ab9c0;
case 0x0c0ab9c2u: goto P_0c0ab9c2;
case 0x0c0ab9c4u: goto P_0c0ab9c4;
case 0x0c0ab9c6u: goto P_0c0ab9c6;
case 0x0c0ab9c8u: goto P_0c0ab9c8;
case 0x0c0ab9cau: goto P_0c0ab9ca;
case 0x0c0ab9ccu: goto P_0c0ab9cc;
case 0x0c0ab9ceu: goto P_0c0ab9ce;
case 0x0c0ab9d0u: goto P_0c0ab9d0;
case 0x0c0ab9d2u: goto P_0c0ab9d2;
case 0x0c0ab9d4u: goto P_0c0ab9d4;
case 0x0c0ab9d6u: goto P_0c0ab9d6;
case 0x0c0ab9d8u: goto P_0c0ab9d8;
case 0x0c0ab9dau: goto P_0c0ab9da;
case 0x0c0ab9dcu: goto P_0c0ab9dc;
case 0x0c0ab9deu: goto P_0c0ab9de;
case 0x0c0ab9e0u: goto P_0c0ab9e0;
case 0x0c0ab9e2u: goto P_0c0ab9e2;
case 0x0c0ab9e4u: goto P_0c0ab9e4;
case 0x0c0ab9e6u: goto P_0c0ab9e6;
case 0x0c0ab9e8u: goto P_0c0ab9e8;
case 0x0c0ab9eau: goto P_0c0ab9ea;
case 0x0c0ab9ecu: goto P_0c0ab9ec;
case 0x0c0ab9eeu: goto P_0c0ab9ee;
case 0x0c0ab9f0u: goto P_0c0ab9f0;
case 0x0c0ab9f2u: goto P_0c0ab9f2;
case 0x0c0ab9f4u: goto P_0c0ab9f4;
case 0x0c0ab9f6u: goto P_0c0ab9f6;
case 0x0c0ab9f8u: goto P_0c0ab9f8;
case 0x0c0ab9fau: goto P_0c0ab9fa;
case 0x0c0ab9fcu: goto P_0c0ab9fc;
case 0x0c0ab9feu: goto P_0c0ab9fe;
case 0x0c0aba00u: goto P_0c0aba00;
case 0x0c0aba02u: goto P_0c0aba02;
case 0x0c0aba04u: goto P_0c0aba04;
case 0x0c0aba06u: goto P_0c0aba06;
case 0x0c0aba08u: goto P_0c0aba08;
case 0x0c0aba0au: goto P_0c0aba0a;
case 0x0c0aba0cu: goto P_0c0aba0c;
case 0x0c0aba0eu: goto P_0c0aba0e;
case 0x0c0aba10u: goto P_0c0aba10;
case 0x0c0aba12u: goto P_0c0aba12;
case 0x0c0aba14u: goto P_0c0aba14;
case 0x0c0aba16u: goto P_0c0aba16;
case 0x0c0aba18u: goto P_0c0aba18;
case 0x0c0aba1au: goto P_0c0aba1a;
case 0x0c0aba1cu: goto P_0c0aba1c;
case 0x0c0aba1eu: goto P_0c0aba1e;
case 0x0c0aba20u: goto P_0c0aba20;
case 0x0c0aba22u: goto P_0c0aba22;
case 0x0c0aba24u: goto P_0c0aba24;
case 0x0c0aba26u: goto P_0c0aba26;
case 0x0c0aba28u: goto P_0c0aba28;
case 0x0c0aba2au: goto P_0c0aba2a;
case 0x0c0aba2cu: goto P_0c0aba2c;
case 0x0c0aba2eu: goto P_0c0aba2e;
case 0x0c0aba30u: goto P_0c0aba30;
case 0x0c0aba32u: goto P_0c0aba32;
case 0x0c0aba34u: goto P_0c0aba34;
case 0x0c0aba36u: goto P_0c0aba36;
case 0x0c0aba38u: goto P_0c0aba38;
case 0x0c0aba3au: goto P_0c0aba3a;
case 0x0c0aba3cu: goto P_0c0aba3c;
case 0x0c0aba3eu: goto P_0c0aba3e;
case 0x0c0aba40u: goto P_0c0aba40;
case 0x0c0aba42u: goto P_0c0aba42;
case 0x0c0aba44u: goto P_0c0aba44;
case 0x0c0aba46u: goto P_0c0aba46;
case 0x0c0aba48u: goto P_0c0aba48;
case 0x0c0aba4au: goto P_0c0aba4a;
case 0x0c0aba4cu: goto P_0c0aba4c;
case 0x0c0aba4eu: goto P_0c0aba4e;
case 0x0c0aba50u: goto P_0c0aba50;
case 0x0c0aba52u: goto P_0c0aba52;
case 0x0c0aba54u: goto P_0c0aba54;
case 0x0c0aba56u: goto P_0c0aba56;
case 0x0c0aba58u: goto P_0c0aba58;
case 0x0c0aba5au: goto P_0c0aba5a;
case 0x0c0aba5cu: goto P_0c0aba5c;
case 0x0c0aba5eu: goto P_0c0aba5e;
case 0x0c0aba60u: goto P_0c0aba60;
case 0x0c0aba62u: goto P_0c0aba62;
case 0x0c0aba64u: goto P_0c0aba64;
case 0x0c0aba66u: goto P_0c0aba66;
case 0x0c0aba68u: goto P_0c0aba68;
case 0x0c0aba6au: goto P_0c0aba6a;
case 0x0c0aba6cu: goto P_0c0aba6c;
case 0x0c0aba6eu: goto P_0c0aba6e;
case 0x0c0aba70u: goto P_0c0aba70;
case 0x0c0aba72u: goto P_0c0aba72;
case 0x0c0aba74u: goto P_0c0aba74;
case 0x0c0aba76u: goto P_0c0aba76;
case 0x0c0aba78u: goto P_0c0aba78;
case 0x0c0aba7au: goto P_0c0aba7a;
case 0x0c0aba7cu: goto P_0c0aba7c;
case 0x0c0aba7eu: goto P_0c0aba7e;
case 0x0c0aba80u: goto P_0c0aba80;
case 0x0c0aba82u: goto P_0c0aba82;
case 0x0c0aba84u: goto P_0c0aba84;
case 0x0c0aba86u: goto P_0c0aba86;
case 0x0c0aba88u: goto P_0c0aba88;
case 0x0c0aba8au: goto P_0c0aba8a;
case 0x0c0aba8cu: goto P_0c0aba8c;
case 0x0c0aba8eu: goto P_0c0aba8e;
case 0x0c0aba90u: goto P_0c0aba90;
case 0x0c0aba92u: goto P_0c0aba92;
case 0x0c0aba94u: goto P_0c0aba94;
case 0x0c0aba96u: goto P_0c0aba96;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0ab8a0: /* original 2fe6, guest PC 0x0c0ab8a0 */
if(!s->budget--) { s->failed_pc=0x0c0ab8a0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ab8a2;
P_0c0ab8a2: /* original 6e53, guest PC 0x0c0ab8a2 */
if(!s->budget--) { s->failed_pc=0x0c0ab8a2u; return 0; }
r[14]=r[5];
goto P_0c0ab8a4;
P_0c0ab8a4: /* original 2fd6, guest PC 0x0c0ab8a4 */
if(!s->budget--) { s->failed_pc=0x0c0ab8a4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ab8a6;
P_0c0ab8a6: /* original 6d43, guest PC 0x0c0ab8a6 */
if(!s->budget--) { s->failed_pc=0x0c0ab8a6u; return 0; }
r[13]=r[4];
goto P_0c0ab8a8;
P_0c0ab8a8: /* original d33e, guest PC 0x0c0ab8a8 */
if(!s->budget--) { s->failed_pc=0x0c0ab8a8u; return 0; }
r[3]=read(ram,0x0c0ab9a4u,4);
goto P_0c0ab8aa;
P_0c0ab8aa: /* original 62e2, guest PC 0x0c0ab8aa */
if(!s->budget--) { s->failed_pc=0x0c0ab8aau; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0ab8ac;
P_0c0ab8ac: /* original 4f22, guest PC 0x0c0ab8ac */
if(!s->budget--) { s->failed_pc=0x0c0ab8acu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ab8ae;
P_0c0ab8ae: /* original 223b, guest PC 0x0c0ab8ae */
if(!s->budget--) { s->failed_pc=0x0c0ab8aeu; return 0; }
r[2]|=r[3];
goto P_0c0ab8b0;
P_0c0ab8b0: /* original 6123, guest PC 0x0c0ab8b0 */
if(!s->budget--) { s->failed_pc=0x0c0ab8b0u; return 0; }
r[1]=r[2];
goto P_0c0ab8b2;
P_0c0ab8b2: /* original 2e22, guest PC 0x0c0ab8b2 */
if(!s->budget--) { s->failed_pc=0x0c0ab8b2u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0ab8b4;
P_0c0ab8b4: /* original 2d22, guest PC 0x0c0ab8b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab8b4u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0ab8b6;
P_0c0ab8b6: /* original 52e1, guest PC 0x0c0ab8b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab8b6u; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0ab8b8;
P_0c0ab8b8: /* original 622d, guest PC 0x0c0ab8b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab8b8u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0ab8ba;
P_0c0ab8ba: /* original 2228, guest PC 0x0c0ab8ba */
if(!s->budget--) { s->failed_pc=0x0c0ab8bau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0ab8bc;
P_0c0ab8bc: /* original 8b05, guest PC 0x0c0ab8bc */
if(!s->budget--) { s->failed_pc=0x0c0ab8bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab8ca; }
goto P_0c0ab8be;
P_0c0ab8be: /* original 4f26, guest PC 0x0c0ab8be */
if(!s->budget--) { s->failed_pc=0x0c0ab8beu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ab8c0;
P_0c0ab8c0: /* original 64d3, guest PC 0x0c0ab8c0 */
if(!s->budget--) { s->failed_pc=0x0c0ab8c0u; return 0; }
r[4]=r[13];
goto P_0c0ab8c2;
P_0c0ab8c2: /* original 65e3, guest PC 0x0c0ab8c2 */
if(!s->budget--) { s->failed_pc=0x0c0ab8c2u; return 0; }
r[5]=r[14];
goto P_0c0ab8c4;
P_0c0ab8c4: /* original 6df6, guest PC 0x0c0ab8c4 */
if(!s->budget--) { s->failed_pc=0x0c0ab8c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ab8c6;
P_0c0ab8c6: /* original a1ec, guest PC 0x0c0ab8c6 */
if(!s->budget--) { s->failed_pc=0x0c0ab8c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0abca2u,s,ram);
P_0c0ab8c8: /* original 6ef6, guest PC 0x0c0ab8c8 */
if(!s->budget--) { s->failed_pc=0x0c0ab8c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ab8ca;
P_0c0ab8ca: /* original 55e1, guest PC 0x0c0ab8ca */
if(!s->budget--) { s->failed_pc=0x0c0ab8cau; return 0; }
r[5]=read(ram,r[14]+4,4);
goto P_0c0ab8cc;
P_0c0ab8cc: /* original d336, guest PC 0x0c0ab8cc */
if(!s->budget--) { s->failed_pc=0x0c0ab8ccu; return 0; }
r[3]=read(ram,0x0c0ab9a8u,4);
goto P_0c0ab8ce;
P_0c0ab8ce: /* original 655d, guest PC 0x0c0ab8ce */
if(!s->budget--) { s->failed_pc=0x0c0ab8ceu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ab8d0;
P_0c0ab8d0: /* original 430b, guest PC 0x0c0ab8d0 */
if(!s->budget--) { s->failed_pc=0x0c0ab8d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ab8d4u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab8d4u) { target=s->pc; goto dispatch; }
goto P_0c0ab8d4;
P_0c0ab8d2: /* original 64d3, guest PC 0x0c0ab8d2 */
if(!s->budget--) { s->failed_pc=0x0c0ab8d2u; return 0; }
r[4]=r[13];
goto P_0c0ab8d4;
P_0c0ab8d4: /* original 4f26, guest PC 0x0c0ab8d4 */
if(!s->budget--) { s->failed_pc=0x0c0ab8d4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ab8d6;
P_0c0ab8d6: /* original e201, guest PC 0x0c0ab8d6 */
if(!s->budget--) { s->failed_pc=0x0c0ab8d6u; return 0; }
r[2]=0x00000001u;
goto P_0c0ab8d8;
P_0c0ab8d8: /* original 64d3, guest PC 0x0c0ab8d8 */
if(!s->budget--) { s->failed_pc=0x0c0ab8d8u; return 0; }
r[4]=r[13];
goto P_0c0ab8da;
P_0c0ab8da: /* original e062, guest PC 0x0c0ab8da */
if(!s->budget--) { s->failed_pc=0x0c0ab8dau; return 0; }
r[0]=0x00000062u;
goto P_0c0ab8dc;
P_0c0ab8dc: /* original 6323, guest PC 0x0c0ab8dc */
if(!s->budget--) { s->failed_pc=0x0c0ab8dcu; return 0; }
r[3]=r[2];
goto P_0c0ab8de;
P_0c0ab8de: /* original 1e22, guest PC 0x0c0ab8de */
if(!s->budget--) { s->failed_pc=0x0c0ab8deu; return 0; }
write(ram,r[14]+8,r[2],4);
goto P_0c0ab8e0;
P_0c0ab8e0: /* original 65e3, guest PC 0x0c0ab8e0 */
if(!s->budget--) { s->failed_pc=0x0c0ab8e0u; return 0; }
r[5]=r[14];
goto P_0c0ab8e2;
P_0c0ab8e2: /* original 0d34, guest PC 0x0c0ab8e2 */
if(!s->budget--) { s->failed_pc=0x0c0ab8e2u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0ab8e4;
P_0c0ab8e4: /* original 6df6, guest PC 0x0c0ab8e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab8e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ab8e6;
P_0c0ab8e6: /* original a000, guest PC 0x0c0ab8e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab8e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ab8ea;
P_0c0ab8e8: /* original 6ef6, guest PC 0x0c0ab8e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab8e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ab8ea;
P_0c0ab8ea: /* original 2fe6, guest PC 0x0c0ab8ea */
if(!s->budget--) { s->failed_pc=0x0c0ab8eau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ab8ec;
P_0c0ab8ec: /* original 6e43, guest PC 0x0c0ab8ec */
if(!s->budget--) { s->failed_pc=0x0c0ab8ecu; return 0; }
r[14]=r[4];
goto P_0c0ab8ee;
P_0c0ab8ee: /* original 2fd6, guest PC 0x0c0ab8ee */
if(!s->budget--) { s->failed_pc=0x0c0ab8eeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ab8f0;
P_0c0ab8f0: /* original 4f22, guest PC 0x0c0ab8f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab8f0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ab8f2;
P_0c0ab8f2: /* original d32f, guest PC 0x0c0ab8f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab8f2u; return 0; }
r[3]=read(ram,0x0c0ab9b0u,4);
goto P_0c0ab8f4;
P_0c0ab8f4: /* original d42d, guest PC 0x0c0ab8f4 */
if(!s->budget--) { s->failed_pc=0x0c0ab8f4u; return 0; }
r[4]=read(ram,0x0c0ab9acu,4);
goto P_0c0ab8f6;
P_0c0ab8f6: /* original 7ff8, guest PC 0x0c0ab8f6 */
if(!s->budget--) { s->failed_pc=0x0c0ab8f6u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0ab8f8;
P_0c0ab8f8: /* original 1f31, guest PC 0x0c0ab8f8 */
if(!s->budget--) { s->failed_pc=0x0c0ab8f8u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0ab8fa;
P_0c0ab8fa: /* original 904a, guest PC 0x0c0ab8fa */
if(!s->budget--) { s->failed_pc=0x0c0ab8fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab992u,2);
goto P_0c0ab8fc;
P_0c0ab8fc: /* original f3e6, guest PC 0x0c0ab8fc */
if(!s->budget--) { s->failed_pc=0x0c0ab8fcu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab8fe;
P_0c0ab8fe: /* original e024, guest PC 0x0c0ab8fe */
if(!s->budget--) { s->failed_pc=0x0c0ab8feu; return 0; }
r[0]=0x00000024u;
goto P_0c0ab900;
P_0c0ab900: /* original fe37, guest PC 0x0c0ab900 */
if(!s->budget--) { s->failed_pc=0x0c0ab900u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab902;
P_0c0ab902: /* original 9047, guest PC 0x0c0ab902 */
if(!s->budget--) { s->failed_pc=0x0c0ab902u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab994u,2);
goto P_0c0ab904;
P_0c0ab904: /* original f3e6, guest PC 0x0c0ab904 */
if(!s->budget--) { s->failed_pc=0x0c0ab904u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab906;
P_0c0ab906: /* original e02c, guest PC 0x0c0ab906 */
if(!s->budget--) { s->failed_pc=0x0c0ab906u; return 0; }
r[0]=0x0000002cu;
goto P_0c0ab908;
P_0c0ab908: /* original fe37, guest PC 0x0c0ab908 */
if(!s->budget--) { s->failed_pc=0x0c0ab908u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab90a;
P_0c0ab90a: /* original e03e, guest PC 0x0c0ab90a */
if(!s->budget--) { s->failed_pc=0x0c0ab90au; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab90c;
P_0c0ab90c: /* original 03ed, guest PC 0x0c0ab90c */
if(!s->budget--) { s->failed_pc=0x0c0ab90cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab90e;
P_0c0ab90e: /* original 9042, guest PC 0x0c0ab90e */
if(!s->budget--) { s->failed_pc=0x0c0ab90eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab996u,2);
goto P_0c0ab910;
P_0c0ab910: /* original 02ed, guest PC 0x0c0ab910 */
if(!s->budget--) { s->failed_pc=0x0c0ab910u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab912;
P_0c0ab912: /* original 3322, guest PC 0x0c0ab912 */
if(!s->budget--) { s->failed_pc=0x0c0ab912u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0ab914;
P_0c0ab914: /* original 8d06, guest PC 0x0c0ab914 */
if(!s->budget--) { s->failed_pc=0x0c0ab914u; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c0ab924; }
goto P_0c0ab918;
P_0c0ab916: /* original 6d53, guest PC 0x0c0ab916 */
if(!s->budget--) { s->failed_pc=0x0c0ab916u; return 0; }
r[13]=r[5];
goto P_0c0ab918;
P_0c0ab918: /* original e048, guest PC 0x0c0ab918 */
if(!s->budget--) { s->failed_pc=0x0c0ab918u; return 0; }
r[0]=0x00000048u;
goto P_0c0ab91a;
P_0c0ab91a: /* original d326, guest PC 0x0c0ab91a */
if(!s->budget--) { s->failed_pc=0x0c0ab91au; return 0; }
r[3]=read(ram,0x0c0ab9b4u,4);
goto P_0c0ab91c;
P_0c0ab91c: /* original 02ee, guest PC 0x0c0ab91c */
if(!s->budget--) { s->failed_pc=0x0c0ab91cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ab91e;
P_0c0ab91e: /* original 2239, guest PC 0x0c0ab91e */
if(!s->budget--) { s->failed_pc=0x0c0ab91eu; return 0; }
r[2]&=r[3];
goto P_0c0ab920;
P_0c0ab920: /* original a0b5, guest PC 0x0c0ab920 */
if(!s->budget--) { s->failed_pc=0x0c0ab920u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0aba8e;
P_0c0ab922: /* original 0e26, guest PC 0x0c0ab922 */
if(!s->budget--) { s->failed_pc=0x0c0ab922u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0ab924;
P_0c0ab924: /* original e061, guest PC 0x0c0ab924 */
if(!s->budget--) { s->failed_pc=0x0c0ab924u; return 0; }
r[0]=0x00000061u;
goto P_0c0ab926;
P_0c0ab926: /* original 00ec, guest PC 0x0c0ab926 */
if(!s->budget--) { s->failed_pc=0x0c0ab926u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ab928;
P_0c0ab928: /* original 600c, guest PC 0x0c0ab928 */
if(!s->budget--) { s->failed_pc=0x0c0ab928u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ab92a;
P_0c0ab92a: /* original 8809, guest PC 0x0c0ab92a */
if(!s->budget--) { s->failed_pc=0x0c0ab92au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0ab92c;
P_0c0ab92c: /* original 8909, guest PC 0x0c0ab92c */
if(!s->budget--) { s->failed_pc=0x0c0ab92cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab942; }
goto P_0c0ab92e;
P_0c0ab92e: /* original 9034, guest PC 0x0c0ab92e */
if(!s->budget--) { s->failed_pc=0x0c0ab92eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab99au,2);
goto P_0c0ab930;
P_0c0ab930: /* original 9332, guest PC 0x0c0ab930 */
if(!s->budget--) { s->failed_pc=0x0c0ab930u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab998u,2);
goto P_0c0ab932;
P_0c0ab932: /* original 024e, guest PC 0x0c0ab932 */
if(!s->budget--) { s->failed_pc=0x0c0ab932u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c0ab934;
P_0c0ab934: /* original 2238, guest PC 0x0c0ab934 */
if(!s->budget--) { s->failed_pc=0x0c0ab934u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab936;
P_0c0ab936: /* original 8904, guest PC 0x0c0ab936 */
if(!s->budget--) { s->failed_pc=0x0c0ab936u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab942; }
goto P_0c0ab938;
P_0c0ab938: /* original 65d3, guest PC 0x0c0ab938 */
if(!s->budget--) { s->failed_pc=0x0c0ab938u; return 0; }
r[5]=r[13];
goto P_0c0ab93a;
P_0c0ab93a: /* original b13e, guest PC 0x0c0ab93a */
if(!s->budget--) { s->failed_pc=0x0c0ab93au; return 0; }
target=code_base|0x0c0abbbau; r[16]=code_base|0x0c0ab93eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab93eu) { target=s->pc; goto dispatch; }
goto P_0c0ab93e;
P_0c0ab93c: /* original 64e3, guest PC 0x0c0ab93c */
if(!s->budget--) { s->failed_pc=0x0c0ab93cu; return 0; }
r[4]=r[14];
goto P_0c0ab93e;
P_0c0ab93e: /* original a0a6, guest PC 0x0c0ab93e */
if(!s->budget--) { s->failed_pc=0x0c0ab93eu; return 0; }
goto P_0c0aba8e;
P_0c0ab940: /* original 0009, guest PC 0x0c0ab940 */
if(!s->budget--) { s->failed_pc=0x0c0ab940u; return 0; }
goto P_0c0ab942;
P_0c0ab942: /* original d31d, guest PC 0x0c0ab942 */
if(!s->budget--) { s->failed_pc=0x0c0ab942u; return 0; }
r[3]=read(ram,0x0c0ab9b8u,4);
goto P_0c0ab944;
P_0c0ab944: /* original 66e3, guest PC 0x0c0ab944 */
if(!s->budget--) { s->failed_pc=0x0c0ab944u; return 0; }
r[6]=r[14];
goto P_0c0ab946;
P_0c0ab946: /* original 65d3, guest PC 0x0c0ab946 */
if(!s->budget--) { s->failed_pc=0x0c0ab946u; return 0; }
r[5]=r[13];
goto P_0c0ab948;
P_0c0ab948: /* original 7648, guest PC 0x0c0ab948 */
if(!s->budget--) { s->failed_pc=0x0c0ab948u; return 0; }
r[6]+=0x00000048u;
goto P_0c0ab94a;
P_0c0ab94a: /* original 430b, guest PC 0x0c0ab94a */
if(!s->budget--) { s->failed_pc=0x0c0ab94au; return 0; }
target=r[3];
r[16]=code_base|0x0c0ab94eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab94eu) { target=s->pc; goto dispatch; }
goto P_0c0ab94e;
P_0c0ab94c: /* original 64e3, guest PC 0x0c0ab94c */
if(!s->budget--) { s->failed_pc=0x0c0ab94cu; return 0; }
r[4]=r[14];
goto P_0c0ab94e;
P_0c0ab94e: /* original 62d2, guest PC 0x0c0ab94e */
if(!s->budget--) { s->failed_pc=0x0c0ab94eu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ab950;
P_0c0ab950: /* original 2e22, guest PC 0x0c0ab950 */
if(!s->budget--) { s->failed_pc=0x0c0ab950u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0ab952;
P_0c0ab952: /* original 901e, guest PC 0x0c0ab952 */
if(!s->budget--) { s->failed_pc=0x0c0ab952u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab992u,2);
goto P_0c0ab954;
P_0c0ab954: /* original f3e6, guest PC 0x0c0ab954 */
if(!s->budget--) { s->failed_pc=0x0c0ab954u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab956;
P_0c0ab956: /* original e024, guest PC 0x0c0ab956 */
if(!s->budget--) { s->failed_pc=0x0c0ab956u; return 0; }
r[0]=0x00000024u;
goto P_0c0ab958;
P_0c0ab958: /* original fe37, guest PC 0x0c0ab958 */
if(!s->budget--) { s->failed_pc=0x0c0ab958u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab95a;
P_0c0ab95a: /* original 901b, guest PC 0x0c0ab95a */
if(!s->budget--) { s->failed_pc=0x0c0ab95au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab994u,2);
goto P_0c0ab95c;
P_0c0ab95c: /* original f3e6, guest PC 0x0c0ab95c */
if(!s->budget--) { s->failed_pc=0x0c0ab95cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab95e;
P_0c0ab95e: /* original e02c, guest PC 0x0c0ab95e */
if(!s->budget--) { s->failed_pc=0x0c0ab95eu; return 0; }
r[0]=0x0000002cu;
goto P_0c0ab960;
P_0c0ab960: /* original fe37, guest PC 0x0c0ab960 */
if(!s->budget--) { s->failed_pc=0x0c0ab960u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab962;
P_0c0ab962: /* original b275, guest PC 0x0c0ab962 */
if(!s->budget--) { s->failed_pc=0x0c0ab962u; return 0; }
target=code_base|0x0c0abe50u; r[16]=code_base|0x0c0ab966u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ab966u) { target=s->pc; goto dispatch; }
goto P_0c0ab966;
P_0c0ab964: /* original 64e3, guest PC 0x0c0ab964 */
if(!s->budget--) { s->failed_pc=0x0c0ab964u; return 0; }
r[4]=r[14];
goto P_0c0ab966;
P_0c0ab966: /* original 62d2, guest PC 0x0c0ab966 */
if(!s->budget--) { s->failed_pc=0x0c0ab966u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ab968;
P_0c0ab968: /* original 9318, guest PC 0x0c0ab968 */
if(!s->budget--) { s->failed_pc=0x0c0ab968u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab99cu,2);
goto P_0c0ab96a;
P_0c0ab96a: /* original 2238, guest PC 0x0c0ab96a */
if(!s->budget--) { s->failed_pc=0x0c0ab96au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab96c;
P_0c0ab96c: /* original 8b28, guest PC 0x0c0ab96c */
if(!s->budget--) { s->failed_pc=0x0c0ab96cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab9c0; }
goto P_0c0ab96e;
P_0c0ab96e: /* original 50f1, guest PC 0x0c0ab96e */
if(!s->budget--) { s->failed_pc=0x0c0ab96eu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0ab970;
P_0c0ab970: /* original e11c, guest PC 0x0c0ab970 */
if(!s->budget--) { s->failed_pc=0x0c0ab970u; return 0; }
r[1]=0x0000001cu;
goto P_0c0ab972;
P_0c0ab972: /* original d212, guest PC 0x0c0ab972 */
if(!s->budget--) { s->failed_pc=0x0c0ab972u; return 0; }
r[2]=read(ram,0x0c0ab9bcu,4);
goto P_0c0ab974;
P_0c0ab974: /* original 001c, guest PC 0x0c0ab974 */
if(!s->budget--) { s->failed_pc=0x0c0ab974u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0ab976;
P_0c0ab976: /* original 600c, guest PC 0x0c0ab976 */
if(!s->budget--) { s->failed_pc=0x0c0ab976u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ab978;
P_0c0ab978: /* original c90f, guest PC 0x0c0ab978 */
if(!s->budget--) { s->failed_pc=0x0c0ab978u; return 0; }
r[0]&=15u;
goto P_0c0ab97a;
P_0c0ab97a: /* original 4008, guest PC 0x0c0ab97a */
if(!s->budget--) { s->failed_pc=0x0c0ab97au; return 0; }
r[0]<<=2;
goto P_0c0ab97c;
P_0c0ab97c: /* original f326, guest PC 0x0c0ab97c */
if(!s->budget--) { s->failed_pc=0x0c0ab97cu; return 0; }
vf3_matrix_load(s,ram,3,r[2]+r[0]);
goto P_0c0ab97e;
P_0c0ab97e: /* original e00c, guest PC 0x0c0ab97e */
if(!s->budget--) { s->failed_pc=0x0c0ab97eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab980;
P_0c0ab980: /* original ff3a, guest PC 0x0c0ab980 */
if(!s->budget--) { s->failed_pc=0x0c0ab980u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0ab982;
P_0c0ab982: /* original f2d6, guest PC 0x0c0ab982 */
if(!s->budget--) { s->failed_pc=0x0c0ab982u; return 0; }
vf3_matrix_load(s,ram,2,r[13]+r[0]);
goto P_0c0ab984;
P_0c0ab984: /* original f235, guest PC 0x0c0ab984 */
if(!s->budget--) { s->failed_pc=0x0c0ab984u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0ab986;
P_0c0ab986: /* original 8b01, guest PC 0x0c0ab986 */
if(!s->budget--) { s->failed_pc=0x0c0ab986u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab98c; }
goto P_0c0ab988;
P_0c0ab988: /* original a081, guest PC 0x0c0ab988 */
if(!s->budget--) { s->failed_pc=0x0c0ab988u; return 0; }
goto P_0c0aba8e;
P_0c0ab98a: /* original 0009, guest PC 0x0c0ab98a */
if(!s->budget--) { s->failed_pc=0x0c0ab98au; return 0; }
goto P_0c0ab98c;
P_0c0ab98c: /* original a04e, guest PC 0x0c0ab98c */
if(!s->budget--) { s->failed_pc=0x0c0ab98cu; return 0; }
goto P_0c0aba2c;
P_0c0ab98e: /* original 0009, guest PC 0x0c0ab98e */
if(!s->budget--) { s->failed_pc=0x0c0ab98eu; return 0; }
if(!vf3_matrix_family(0x0c0ab990u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ab990u; return 0; } return 1;
P_0c0ab9c0: /* original 906a, guest PC 0x0c0ab9c0 */
if(!s->budget--) { s->failed_pc=0x0c0ab9c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aba98u,2);
goto P_0c0ab9c2;
P_0c0ab9c2: /* original 00ec, guest PC 0x0c0ab9c2 */
if(!s->budget--) { s->failed_pc=0x0c0ab9c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ab9c4;
P_0c0ab9c4: /* original 600c, guest PC 0x0c0ab9c4 */
if(!s->budget--) { s->failed_pc=0x0c0ab9c4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ab9c6;
P_0c0ab9c6: /* original c804, guest PC 0x0c0ab9c6 */
if(!s->budget--) { s->failed_pc=0x0c0ab9c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0ab9c8;
P_0c0ab9c8: /* original 8b05, guest PC 0x0c0ab9c8 */
if(!s->budget--) { s->failed_pc=0x0c0ab9c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab9d6; }
goto P_0c0ab9ca;
P_0c0ab9ca: /* original e03e, guest PC 0x0c0ab9ca */
if(!s->budget--) { s->failed_pc=0x0c0ab9cau; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab9cc;
P_0c0ab9cc: /* original 03ed, guest PC 0x0c0ab9cc */
if(!s->budget--) { s->failed_pc=0x0c0ab9ccu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab9ce;
P_0c0ab9ce: /* original 9064, guest PC 0x0c0ab9ce */
if(!s->budget--) { s->failed_pc=0x0c0ab9ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aba9au,2);
goto P_0c0ab9d0;
P_0c0ab9d0: /* original 02ed, guest PC 0x0c0ab9d0 */
if(!s->budget--) { s->failed_pc=0x0c0ab9d0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab9d2;
P_0c0ab9d2: /* original 3322, guest PC 0x0c0ab9d2 */
if(!s->budget--) { s->failed_pc=0x0c0ab9d2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0ab9d4;
P_0c0ab9d4: /* original 8b5b, guest PC 0x0c0ab9d4 */
if(!s->budget--) { s->failed_pc=0x0c0ab9d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aba8e; }
goto P_0c0ab9d6;
P_0c0ab9d6: /* original 9061, guest PC 0x0c0ab9d6 */
if(!s->budget--) { s->failed_pc=0x0c0ab9d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aba9cu,2);
goto P_0c0ab9d8;
P_0c0ab9d8: /* original f3e6, guest PC 0x0c0ab9d8 */
if(!s->budget--) { s->failed_pc=0x0c0ab9d8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab9da;
P_0c0ab9da: /* original c735, guest PC 0x0c0ab9da */
if(!s->budget--) { s->failed_pc=0x0c0ab9dau; return 0; }
r[0]=code_base|0x000abab0u;
goto P_0c0ab9dc;
P_0c0ab9dc: /* original ff3a, guest PC 0x0c0ab9dc */
if(!s->budget--) { s->failed_pc=0x0c0ab9dcu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0ab9de;
P_0c0ab9de: /* original f408, guest PC 0x0c0ab9de */
if(!s->budget--) { s->failed_pc=0x0c0ab9deu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0ab9e0;
P_0c0ab9e0: /* original c734, guest PC 0x0c0ab9e0 */
if(!s->budget--) { s->failed_pc=0x0c0ab9e0u; return 0; }
r[0]=code_base|0x000abab4u;
goto P_0c0ab9e2;
P_0c0ab9e2: /* original f508, guest PC 0x0c0ab9e2 */
if(!s->budget--) { s->failed_pc=0x0c0ab9e2u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0ab9e4;
P_0c0ab9e4: /* original e00c, guest PC 0x0c0ab9e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab9e4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab9e6;
P_0c0ab9e6: /* original f350, guest PC 0x0c0ab9e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab9e6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'+');
goto P_0c0ab9e8;
P_0c0ab9e8: /* original ff3a, guest PC 0x0c0ab9e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab9e8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0ab9ea;
P_0c0ab9ea: /* original f2d6, guest PC 0x0c0ab9ea */
if(!s->budget--) { s->failed_pc=0x0c0ab9eau; return 0; }
vf3_matrix_load(s,ram,2,r[13]+r[0]);
goto P_0c0ab9ec;
P_0c0ab9ec: /* original f235, guest PC 0x0c0ab9ec */
if(!s->budget--) { s->failed_pc=0x0c0ab9ecu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0ab9ee;
P_0c0ab9ee: /* original 894e, guest PC 0x0c0ab9ee */
if(!s->budget--) { s->failed_pc=0x0c0ab9eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aba8e; }
goto P_0c0ab9f0;
P_0c0ab9f0: /* original 9055, guest PC 0x0c0ab9f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab9f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aba9eu,2);
goto P_0c0ab9f2;
P_0c0ab9f2: /* original e51c, guest PC 0x0c0ab9f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab9f2u; return 0; }
r[5]=0x0000001cu;
goto P_0c0ab9f4;
P_0c0ab9f4: /* original 9456, guest PC 0x0c0ab9f4 */
if(!s->budget--) { s->failed_pc=0x0c0ab9f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abaa4u,2);
goto P_0c0ab9f6;
P_0c0ab9f6: /* original 07ee, guest PC 0x0c0ab9f6 */
if(!s->budget--) { s->failed_pc=0x0c0ab9f6u; return 0; }
r[7]=read(ram,r[14]+r[0],4);
goto P_0c0ab9f8;
P_0c0ab9f8: /* original 9052, guest PC 0x0c0ab9f8 */
if(!s->budget--) { s->failed_pc=0x0c0ab9f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abaa0u,2);
goto P_0c0ab9fa;
P_0c0ab9fa: /* original 34ec, guest PC 0x0c0ab9fa */
if(!s->budget--) { s->failed_pc=0x0c0ab9fau; return 0; }
r[4]+=r[14];
goto P_0c0ab9fc;
P_0c0ab9fc: /* original 9651, guest PC 0x0c0ab9fc */
if(!s->budget--) { s->failed_pc=0x0c0ab9fcu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abaa2u,2);
goto P_0c0ab9fe;
P_0c0ab9fe: /* original f3e6, guest PC 0x0c0ab9fe */
if(!s->budget--) { s->failed_pc=0x0c0ab9feu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0aba00;
P_0c0aba00: /* original c72d, guest PC 0x0c0aba00 */
if(!s->budget--) { s->failed_pc=0x0c0aba00u; return 0; }
r[0]=code_base|0x000abab8u;
goto P_0c0aba02;
P_0c0aba02: /* original 36ec, guest PC 0x0c0aba02 */
if(!s->budget--) { s->failed_pc=0x0c0aba02u; return 0; }
r[6]+=r[14];
goto P_0c0aba04;
P_0c0aba04: /* original f341, guest PC 0x0c0aba04 */
if(!s->budget--) { s->failed_pc=0x0c0aba04u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c0aba06;
P_0c0aba06: /* original ff3a, guest PC 0x0c0aba06 */
if(!s->budget--) { s->failed_pc=0x0c0aba06u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0aba08;
P_0c0aba08: /* original f608, guest PC 0x0c0aba08 */
if(!s->budget--) { s->failed_pc=0x0c0aba08u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0aba0a;
P_0c0aba0a: /* original e004, guest PC 0x0c0aba0a */
if(!s->budget--) { s->failed_pc=0x0c0aba0au; return 0; }
r[0]=0x00000004u;
goto P_0c0aba0c;
P_0c0aba0c: /* original f549, guest PC 0x0c0aba0c */
if(!s->budget--) { s->failed_pc=0x0c0aba0cu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0aba0e;
P_0c0aba0e: /* original f476, guest PC 0x0c0aba0e */
if(!s->budget--) { s->failed_pc=0x0c0aba0eu; return 0; }
vf3_matrix_load(s,ram,4,r[7]+r[0]);
goto P_0c0aba10;
P_0c0aba10: /* original f769, guest PC 0x0c0aba10 */
if(!s->budget--) { s->failed_pc=0x0c0aba10u; return 0; }
vf3_matrix_load(s,ram,7,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0aba12;
P_0c0aba12: /* original f451, guest PC 0x0c0aba12 */
if(!s->budget--) { s->failed_pc=0x0c0aba12u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c0aba14;
P_0c0aba14: /* original f54c, guest PC 0x0c0aba14 */
if(!s->budget--) { s->failed_pc=0x0c0aba14u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0aba16;
P_0c0aba16: /* original f561, guest PC 0x0c0aba16 */
if(!s->budget--) { s->failed_pc=0x0c0aba16u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c0aba18;
P_0c0aba18: /* original f575, guest PC 0x0c0aba18 */
if(!s->budget--) { s->failed_pc=0x0c0aba18u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[7]))!=0);
goto P_0c0aba1a;
P_0c0aba1a: /* original 8d03, guest PC 0x0c0aba1a */
if(!s->budget--) { s->failed_pc=0x0c0aba1au; return 0; }
cond=r[17]&1u;
r[7]+=0x0000000cu;
if(cond) { goto P_0c0aba24; }
goto P_0c0aba1e;
P_0c0aba1c: /* original 770c, guest PC 0x0c0aba1c */
if(!s->budget--) { s->failed_pc=0x0c0aba1cu; return 0; }
r[7]+=0x0000000cu;
goto P_0c0aba1e;
P_0c0aba1e: /* original f3f8, guest PC 0x0c0aba1e */
if(!s->budget--) { s->failed_pc=0x0c0aba1eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0aba20;
P_0c0aba20: /* original f345, guest PC 0x0c0aba20 */
if(!s->budget--) { s->failed_pc=0x0c0aba20u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0aba22;
P_0c0aba22: /* original 8903, guest PC 0x0c0aba22 */
if(!s->budget--) { s->failed_pc=0x0c0aba22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aba2c; }
goto P_0c0aba24;
P_0c0aba24: /* original 4510, guest PC 0x0c0aba24 */
if(!s->budget--) { s->failed_pc=0x0c0aba24u; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c0aba26;
P_0c0aba26: /* original 8bf0, guest PC 0x0c0aba26 */
if(!s->budget--) { s->failed_pc=0x0c0aba26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aba0a; }
goto P_0c0aba28;
P_0c0aba28: /* original a031, guest PC 0x0c0aba28 */
if(!s->budget--) { s->failed_pc=0x0c0aba28u; return 0; }
goto P_0c0aba8e;
P_0c0aba2a: /* original 0009, guest PC 0x0c0aba2a */
if(!s->budget--) { s->failed_pc=0x0c0aba2au; return 0; }
goto P_0c0aba2c;
P_0c0aba2c: /* original d323, guest PC 0x0c0aba2c */
if(!s->budget--) { s->failed_pc=0x0c0aba2cu; return 0; }
r[3]=read(ram,0x0c0ababcu,4);
goto P_0c0aba2e;
P_0c0aba2e: /* original 64f3, guest PC 0x0c0aba2e */
if(!s->budget--) { s->failed_pc=0x0c0aba2eu; return 0; }
r[4]=r[15];
goto P_0c0aba30;
P_0c0aba30: /* original 9039, guest PC 0x0c0aba30 */
if(!s->budget--) { s->failed_pc=0x0c0aba30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abaa6u,2);
goto P_0c0aba32;
P_0c0aba32: /* original 430b, guest PC 0x0c0aba32 */
if(!s->budget--) { s->failed_pc=0x0c0aba32u; return 0; }
target=r[3];
r[16]=code_base|0x0c0aba36u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aba36u) { target=s->pc; goto dispatch; }
goto P_0c0aba36;
P_0c0aba34: /* original f4e6, guest PC 0x0c0aba34 */
if(!s->budget--) { s->failed_pc=0x0c0aba34u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0aba36;
P_0c0aba36: /* original f38d, guest PC 0x0c0aba36 */
if(!s->budget--) { s->failed_pc=0x0c0aba36u; return 0; }
fr[3]=0;
goto P_0c0aba38;
P_0c0aba38: /* original f305, guest PC 0x0c0aba38 */
if(!s->budget--) { s->failed_pc=0x0c0aba38u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[0]))!=0);
goto P_0c0aba3a;
P_0c0aba3a: /* original 8903, guest PC 0x0c0aba3a */
if(!s->budget--) { s->failed_pc=0x0c0aba3au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aba44; }
goto P_0c0aba3c;
P_0c0aba3c: /* original 62d2, guest PC 0x0c0aba3c */
if(!s->budget--) { s->failed_pc=0x0c0aba3cu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0aba3e;
P_0c0aba3e: /* original d320, guest PC 0x0c0aba3e */
if(!s->budget--) { s->failed_pc=0x0c0aba3eu; return 0; }
r[3]=read(ram,0x0c0abac0u,4);
goto P_0c0aba40;
P_0c0aba40: /* original 2238, guest PC 0x0c0aba40 */
if(!s->budget--) { s->failed_pc=0x0c0aba40u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aba42;
P_0c0aba42: /* original 8b07, guest PC 0x0c0aba42 */
if(!s->budget--) { s->failed_pc=0x0c0aba42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aba54; }
goto P_0c0aba44;
P_0c0aba44: /* original 9030, guest PC 0x0c0aba44 */
if(!s->budget--) { s->failed_pc=0x0c0aba44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abaa8u,2);
goto P_0c0aba46;
P_0c0aba46: /* original 01ee, guest PC 0x0c0aba46 */
if(!s->budget--) { s->failed_pc=0x0c0aba46u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0aba48;
P_0c0aba48: /* original 2118, guest PC 0x0c0aba48 */
if(!s->budget--) { s->failed_pc=0x0c0aba48u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0aba4a;
P_0c0aba4a: /* original 8b20, guest PC 0x0c0aba4a */
if(!s->budget--) { s->failed_pc=0x0c0aba4au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aba8e; }
goto P_0c0aba4c;
P_0c0aba4c: /* original 902d, guest PC 0x0c0aba4c */
if(!s->budget--) { s->failed_pc=0x0c0aba4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abaaau,2);
goto P_0c0aba4e;
P_0c0aba4e: /* original 01ee, guest PC 0x0c0aba4e */
if(!s->budget--) { s->failed_pc=0x0c0aba4eu; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0aba50;
P_0c0aba50: /* original 2118, guest PC 0x0c0aba50 */
if(!s->budget--) { s->failed_pc=0x0c0aba50u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0aba52;
P_0c0aba52: /* original 891c, guest PC 0x0c0aba52 */
if(!s->budget--) { s->failed_pc=0x0c0aba52u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aba8e; }
goto P_0c0aba54;
P_0c0aba54: /* original e102, guest PC 0x0c0aba54 */
if(!s->budget--) { s->failed_pc=0x0c0aba54u; return 0; }
r[1]=0x00000002u;
goto P_0c0aba56;
P_0c0aba56: /* original 65e3, guest PC 0x0c0aba56 */
if(!s->budget--) { s->failed_pc=0x0c0aba56u; return 0; }
r[5]=r[14];
goto P_0c0aba58;
P_0c0aba58: /* original 6313, guest PC 0x0c0aba58 */
if(!s->budget--) { s->failed_pc=0x0c0aba58u; return 0; }
r[3]=r[1];
goto P_0c0aba5a;
P_0c0aba5a: /* original e062, guest PC 0x0c0aba5a */
if(!s->budget--) { s->failed_pc=0x0c0aba5au; return 0; }
r[0]=0x00000062u;
goto P_0c0aba5c;
P_0c0aba5c: /* original 1d12, guest PC 0x0c0aba5c */
if(!s->budget--) { s->failed_pc=0x0c0aba5cu; return 0; }
write(ram,r[13]+8,r[1],4);
goto P_0c0aba5e;
P_0c0aba5e: /* original 0e34, guest PC 0x0c0aba5e */
if(!s->budget--) { s->failed_pc=0x0c0aba5eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0aba60;
P_0c0aba60: /* original 9024, guest PC 0x0c0aba60 */
if(!s->budget--) { s->failed_pc=0x0c0aba60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abaacu,2);
goto P_0c0aba62;
P_0c0aba62: /* original 02ed, guest PC 0x0c0aba62 */
if(!s->budget--) { s->failed_pc=0x0c0aba62u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aba64;
P_0c0aba64: /* original e03e, guest PC 0x0c0aba64 */
if(!s->budget--) { s->failed_pc=0x0c0aba64u; return 0; }
r[0]=0x0000003eu;
goto P_0c0aba66;
P_0c0aba66: /* original 0e25, guest PC 0x0c0aba66 */
if(!s->budget--) { s->failed_pc=0x0c0aba66u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0aba68;
P_0c0aba68: /* original e048, guest PC 0x0c0aba68 */
if(!s->budget--) { s->failed_pc=0x0c0aba68u; return 0; }
r[0]=0x00000048u;
goto P_0c0aba6a;
P_0c0aba6a: /* original d316, guest PC 0x0c0aba6a */
if(!s->budget--) { s->failed_pc=0x0c0aba6au; return 0; }
r[3]=read(ram,0x0c0abac4u,4);
goto P_0c0aba6c;
P_0c0aba6c: /* original 62d2, guest PC 0x0c0aba6c */
if(!s->budget--) { s->failed_pc=0x0c0aba6cu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0aba6e;
P_0c0aba6e: /* original 04ee, guest PC 0x0c0aba6e */
if(!s->budget--) { s->failed_pc=0x0c0aba6eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0aba70;
P_0c0aba70: /* original 223b, guest PC 0x0c0aba70 */
if(!s->budget--) { s->failed_pc=0x0c0aba70u; return 0; }
r[2]|=r[3];
goto P_0c0aba72;
P_0c0aba72: /* original 2d22, guest PC 0x0c0aba72 */
if(!s->budget--) { s->failed_pc=0x0c0aba72u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0aba74;
P_0c0aba74: /* original 911b, guest PC 0x0c0aba74 */
if(!s->budget--) { s->failed_pc=0x0c0aba74u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abaaeu,2);
goto P_0c0aba76;
P_0c0aba76: /* original 63d2, guest PC 0x0c0aba76 */
if(!s->budget--) { s->failed_pc=0x0c0aba76u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0aba78;
P_0c0aba78: /* original d213, guest PC 0x0c0aba78 */
if(!s->budget--) { s->failed_pc=0x0c0aba78u; return 0; }
r[2]=read(ram,0x0c0abac8u,4);
goto P_0c0aba7a;
P_0c0aba7a: /* original 2419, guest PC 0x0c0aba7a */
if(!s->budget--) { s->failed_pc=0x0c0aba7au; return 0; }
r[4]&=r[1];
goto P_0c0aba7c;
P_0c0aba7c: /* original 2e32, guest PC 0x0c0aba7c */
if(!s->budget--) { s->failed_pc=0x0c0aba7cu; return 0; }
write(ram,r[14],r[3],4);
goto P_0c0aba7e;
P_0c0aba7e: /* original 242b, guest PC 0x0c0aba7e */
if(!s->budget--) { s->failed_pc=0x0c0aba7eu; return 0; }
r[4]|=r[2];
goto P_0c0aba80;
P_0c0aba80: /* original 0e46, guest PC 0x0c0aba80 */
if(!s->budget--) { s->failed_pc=0x0c0aba80u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0aba82;
P_0c0aba82: /* original d312, guest PC 0x0c0aba82 */
if(!s->budget--) { s->failed_pc=0x0c0aba82u; return 0; }
r[3]=read(ram,0x0c0abaccu,4);
goto P_0c0aba84;
P_0c0aba84: /* original 430b, guest PC 0x0c0aba84 */
if(!s->budget--) { s->failed_pc=0x0c0aba84u; return 0; }
target=r[3];
r[16]=code_base|0x0c0aba88u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aba88u) { target=s->pc; goto dispatch; }
goto P_0c0aba88;
P_0c0aba86: /* original e400, guest PC 0x0c0aba86 */
if(!s->budget--) { s->failed_pc=0x0c0aba86u; return 0; }
r[4]=0x00000000u;
goto P_0c0aba88;
P_0c0aba88: /* original 65d3, guest PC 0x0c0aba88 */
if(!s->budget--) { s->failed_pc=0x0c0aba88u; return 0; }
r[5]=r[13];
goto P_0c0aba8a;
P_0c0aba8a: /* original b021, guest PC 0x0c0aba8a */
if(!s->budget--) { s->failed_pc=0x0c0aba8au; return 0; }
target=code_base|0x0c0abad0u; r[16]=code_base|0x0c0aba8eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aba8eu) { target=s->pc; goto dispatch; }
goto P_0c0aba8e;
P_0c0aba8c: /* original 64e3, guest PC 0x0c0aba8c */
if(!s->budget--) { s->failed_pc=0x0c0aba8cu; return 0; }
r[4]=r[14];
goto P_0c0aba8e;
P_0c0aba8e: /* original 7f08, guest PC 0x0c0aba8e */
if(!s->budget--) { s->failed_pc=0x0c0aba8eu; return 0; }
r[15]+=0x00000008u;
goto P_0c0aba90;
P_0c0aba90: /* original 4f26, guest PC 0x0c0aba90 */
if(!s->budget--) { s->failed_pc=0x0c0aba90u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aba92;
P_0c0aba92: /* original 6df6, guest PC 0x0c0aba92 */
if(!s->budget--) { s->failed_pc=0x0c0aba92u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aba94;
P_0c0aba94: /* original 000b, guest PC 0x0c0aba94 */
if(!s->budget--) { s->failed_pc=0x0c0aba94u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0aba96: /* original 6ef6, guest PC 0x0c0aba96 */
if(!s->budget--) { s->failed_pc=0x0c0aba96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0aba98u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aba98u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
