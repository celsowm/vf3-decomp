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
int vf3_away_batch24_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06e8c4u: goto P_0c06e8c4;
case 0x0c06e8c6u: goto P_0c06e8c6;
case 0x0c06e8c8u: goto P_0c06e8c8;
case 0x0c06e8cau: goto P_0c06e8ca;
case 0x0c06e8ccu: goto P_0c06e8cc;
case 0x0c06e8ceu: goto P_0c06e8ce;
case 0x0c06e8d0u: goto P_0c06e8d0;
case 0x0c06e8d2u: goto P_0c06e8d2;
case 0x0c06e8d4u: goto P_0c06e8d4;
case 0x0c06e8d6u: goto P_0c06e8d6;
case 0x0c06e8d8u: goto P_0c06e8d8;
case 0x0c06e8dau: goto P_0c06e8da;
case 0x0c06e8dcu: goto P_0c06e8dc;
case 0x0c06e8deu: goto P_0c06e8de;
case 0x0c06e8e0u: goto P_0c06e8e0;
case 0x0c06e8e2u: goto P_0c06e8e2;
case 0x0c06e8e4u: goto P_0c06e8e4;
case 0x0c06e8e6u: goto P_0c06e8e6;
case 0x0c06e8e8u: goto P_0c06e8e8;
case 0x0c06e8eau: goto P_0c06e8ea;
case 0x0c06e8ecu: goto P_0c06e8ec;
case 0x0c06e8eeu: goto P_0c06e8ee;
case 0x0c06e8f0u: goto P_0c06e8f0;
case 0x0c06e8f2u: goto P_0c06e8f2;
case 0x0c06e8f4u: goto P_0c06e8f4;
case 0x0c06e8f6u: goto P_0c06e8f6;
case 0x0c06e8f8u: goto P_0c06e8f8;
case 0x0c06e8fau: goto P_0c06e8fa;
case 0x0c06e8fcu: goto P_0c06e8fc;
case 0x0c06e8feu: goto P_0c06e8fe;
case 0x0c06e900u: goto P_0c06e900;
case 0x0c06e902u: goto P_0c06e902;
case 0x0c06e904u: goto P_0c06e904;
case 0x0c06e906u: goto P_0c06e906;
case 0x0c06e908u: goto P_0c06e908;
case 0x0c06e90au: goto P_0c06e90a;
case 0x0c06e90cu: goto P_0c06e90c;
case 0x0c06e90eu: goto P_0c06e90e;
case 0x0c06e910u: goto P_0c06e910;
case 0x0c06e912u: goto P_0c06e912;
case 0x0c06e914u: goto P_0c06e914;
case 0x0c06e916u: goto P_0c06e916;
case 0x0c06e918u: goto P_0c06e918;
case 0x0c06e91au: goto P_0c06e91a;
case 0x0c06e91cu: goto P_0c06e91c;
case 0x0c06e91eu: goto P_0c06e91e;
case 0x0c06e920u: goto P_0c06e920;
case 0x0c06e922u: goto P_0c06e922;
case 0x0c06e924u: goto P_0c06e924;
case 0x0c06e926u: goto P_0c06e926;
case 0x0c06e928u: goto P_0c06e928;
case 0x0c06e92au: goto P_0c06e92a;
case 0x0c06e92cu: goto P_0c06e92c;
case 0x0c06e92eu: goto P_0c06e92e;
case 0x0c06e930u: goto P_0c06e930;
case 0x0c06e932u: goto P_0c06e932;
case 0x0c06e934u: goto P_0c06e934;
case 0x0c06e936u: goto P_0c06e936;
case 0x0c06e938u: goto P_0c06e938;
case 0x0c06e93au: goto P_0c06e93a;
case 0x0c06e93cu: goto P_0c06e93c;
case 0x0c06e93eu: goto P_0c06e93e;
case 0x0c06e940u: goto P_0c06e940;
case 0x0c06e964u: goto P_0c06e964;
case 0x0c06e966u: goto P_0c06e966;
case 0x0c06e968u: goto P_0c06e968;
case 0x0c06e96au: goto P_0c06e96a;
case 0x0c06e96cu: goto P_0c06e96c;
case 0x0c06e96eu: goto P_0c06e96e;
case 0x0c06e970u: goto P_0c06e970;
case 0x0c06e972u: goto P_0c06e972;
case 0x0c06e974u: goto P_0c06e974;
case 0x0c06e976u: goto P_0c06e976;
case 0x0c06e978u: goto P_0c06e978;
case 0x0c06e97au: goto P_0c06e97a;
case 0x0c06e97cu: goto P_0c06e97c;
case 0x0c06e97eu: goto P_0c06e97e;
case 0x0c06e980u: goto P_0c06e980;
case 0x0c06e982u: goto P_0c06e982;
case 0x0c06e984u: goto P_0c06e984;
case 0x0c06e986u: goto P_0c06e986;
case 0x0c06e988u: goto P_0c06e988;
case 0x0c06e98au: goto P_0c06e98a;
case 0x0c06e98cu: goto P_0c06e98c;
case 0x0c06e98eu: goto P_0c06e98e;
case 0x0c06e990u: goto P_0c06e990;
case 0x0c06e992u: goto P_0c06e992;
case 0x0c06e994u: goto P_0c06e994;
case 0x0c06e996u: goto P_0c06e996;
case 0x0c06e998u: goto P_0c06e998;
case 0x0c06e99au: goto P_0c06e99a;
case 0x0c06e99cu: goto P_0c06e99c;
case 0x0c06e99eu: goto P_0c06e99e;
case 0x0c06e9a0u: goto P_0c06e9a0;
case 0x0c06e9a2u: goto P_0c06e9a2;
case 0x0c06e9a4u: goto P_0c06e9a4;
case 0x0c06e9a6u: goto P_0c06e9a6;
case 0x0c06e9a8u: goto P_0c06e9a8;
case 0x0c06e9aau: goto P_0c06e9aa;
case 0x0c06e9acu: goto P_0c06e9ac;
case 0x0c06e9aeu: goto P_0c06e9ae;
case 0x0c06e9b0u: goto P_0c06e9b0;
case 0x0c06e9b2u: goto P_0c06e9b2;
case 0x0c06e9b4u: goto P_0c06e9b4;
case 0x0c06e9b6u: goto P_0c06e9b6;
case 0x0c06e9b8u: goto P_0c06e9b8;
case 0x0c06e9bau: goto P_0c06e9ba;
case 0x0c06e9bcu: goto P_0c06e9bc;
case 0x0c06e9beu: goto P_0c06e9be;
case 0x0c06e9c0u: goto P_0c06e9c0;
case 0x0c06e9c2u: goto P_0c06e9c2;
case 0x0c06e9c4u: goto P_0c06e9c4;
case 0x0c06e9c6u: goto P_0c06e9c6;
case 0x0c06e9c8u: goto P_0c06e9c8;
case 0x0c06e9cau: goto P_0c06e9ca;
case 0x0c06e9ccu: goto P_0c06e9cc;
case 0x0c06e9ceu: goto P_0c06e9ce;
case 0x0c06e9d0u: goto P_0c06e9d0;
case 0x0c06e9d2u: goto P_0c06e9d2;
case 0x0c06e9d4u: goto P_0c06e9d4;
case 0x0c06e9d6u: goto P_0c06e9d6;
case 0x0c06e9d8u: goto P_0c06e9d8;
case 0x0c06e9dau: goto P_0c06e9da;
case 0x0c06e9dcu: goto P_0c06e9dc;
case 0x0c06e9deu: goto P_0c06e9de;
case 0x0c06e9e0u: goto P_0c06e9e0;
case 0x0c06e9e2u: goto P_0c06e9e2;
case 0x0c06e9e4u: goto P_0c06e9e4;
case 0x0c06e9e6u: goto P_0c06e9e6;
case 0x0c06e9e8u: goto P_0c06e9e8;
case 0x0c06e9eau: goto P_0c06e9ea;
case 0x0c06e9ecu: goto P_0c06e9ec;
case 0x0c06e9eeu: goto P_0c06e9ee;
case 0x0c06e9f0u: goto P_0c06e9f0;
case 0x0c06e9f2u: goto P_0c06e9f2;
case 0x0c06e9f4u: goto P_0c06e9f4;
case 0x0c06e9f6u: goto P_0c06e9f6;
case 0x0c06e9f8u: goto P_0c06e9f8;
case 0x0c06e9fau: goto P_0c06e9fa;
case 0x0c06e9fcu: goto P_0c06e9fc;
case 0x0c06e9feu: goto P_0c06e9fe;
case 0x0c06ea00u: goto P_0c06ea00;
case 0x0c06ea02u: goto P_0c06ea02;
case 0x0c06ea04u: goto P_0c06ea04;
case 0x0c06ea06u: goto P_0c06ea06;
case 0x0c06ea08u: goto P_0c06ea08;
case 0x0c06ea0au: goto P_0c06ea0a;
case 0x0c06ea0cu: goto P_0c06ea0c;
case 0x0c06ea0eu: goto P_0c06ea0e;
case 0x0c06ea10u: goto P_0c06ea10;
case 0x0c06ea12u: goto P_0c06ea12;
case 0x0c06ea14u: goto P_0c06ea14;
case 0x0c06ea16u: goto P_0c06ea16;
case 0x0c06ea18u: goto P_0c06ea18;
case 0x0c06ea1au: goto P_0c06ea1a;
case 0x0c06ea1cu: goto P_0c06ea1c;
case 0x0c06ea1eu: goto P_0c06ea1e;
case 0x0c06ea20u: goto P_0c06ea20;
case 0x0c06ea22u: goto P_0c06ea22;
case 0x0c06ea24u: goto P_0c06ea24;
case 0x0c06ea26u: goto P_0c06ea26;
case 0x0c06ea28u: goto P_0c06ea28;
case 0x0c06ea2au: goto P_0c06ea2a;
case 0x0c06ea2cu: goto P_0c06ea2c;
case 0x0c06ea2eu: goto P_0c06ea2e;
case 0x0c06ea30u: goto P_0c06ea30;
case 0x0c06ea32u: goto P_0c06ea32;
case 0x0c06ea34u: goto P_0c06ea34;
case 0x0c06ea36u: goto P_0c06ea36;
case 0x0c06ea38u: goto P_0c06ea38;
case 0x0c06ea3au: goto P_0c06ea3a;
case 0x0c06ea3cu: goto P_0c06ea3c;
case 0x0c06ea3eu: goto P_0c06ea3e;
case 0x0c06ea40u: goto P_0c06ea40;
case 0x0c06ea42u: goto P_0c06ea42;
case 0x0c06ea44u: goto P_0c06ea44;
case 0x0c06ea46u: goto P_0c06ea46;
case 0x0c06ea48u: goto P_0c06ea48;
case 0x0c06ea4au: goto P_0c06ea4a;
case 0x0c06ea4cu: goto P_0c06ea4c;
case 0x0c06ea4eu: goto P_0c06ea4e;
case 0x0c06ea50u: goto P_0c06ea50;
case 0x0c06ea52u: goto P_0c06ea52;
case 0x0c06ea54u: goto P_0c06ea54;
case 0x0c06ea56u: goto P_0c06ea56;
case 0x0c06ea58u: goto P_0c06ea58;
case 0x0c06ea5au: goto P_0c06ea5a;
case 0x0c06ea5cu: goto P_0c06ea5c;
case 0x0c06ea5eu: goto P_0c06ea5e;
case 0x0c06ea60u: goto P_0c06ea60;
case 0x0c06ea62u: goto P_0c06ea62;
case 0x0c06ea64u: goto P_0c06ea64;
case 0x0c06ea66u: goto P_0c06ea66;
case 0x0c06ea68u: goto P_0c06ea68;
case 0x0c06ea6au: goto P_0c06ea6a;
case 0x0c06ea6cu: goto P_0c06ea6c;
case 0x0c06ea6eu: goto P_0c06ea6e;
case 0x0c06ea70u: goto P_0c06ea70;
case 0x0c06ea72u: goto P_0c06ea72;
case 0x0c06ea74u: goto P_0c06ea74;
case 0x0c06ea76u: goto P_0c06ea76;
case 0x0c06ea78u: goto P_0c06ea78;
case 0x0c06ea7au: goto P_0c06ea7a;
case 0x0c06ea7cu: goto P_0c06ea7c;
case 0x0c06ea7eu: goto P_0c06ea7e;
case 0x0c06ea80u: goto P_0c06ea80;
case 0x0c06ea82u: goto P_0c06ea82;
case 0x0c06ea84u: goto P_0c06ea84;
case 0x0c06ea86u: goto P_0c06ea86;
case 0x0c06ea88u: goto P_0c06ea88;
case 0x0c06ea8au: goto P_0c06ea8a;
case 0x0c06ea8cu: goto P_0c06ea8c;
case 0x0c06ea8eu: goto P_0c06ea8e;
case 0x0c06ea90u: goto P_0c06ea90;
case 0x0c06ea92u: goto P_0c06ea92;
case 0x0c06ea94u: goto P_0c06ea94;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06e8c4: /* original fffb, guest PC 0x0c06e8c4 */
if(!s->budget--) { s->failed_pc=0x0c06e8c4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06e8c6;
P_0c06e8c6: /* original ffeb, guest PC 0x0c06e8c6 */
if(!s->budget--) { s->failed_pc=0x0c06e8c6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06e8c8;
P_0c06e8c8: /* original ffdb, guest PC 0x0c06e8c8 */
if(!s->budget--) { s->failed_pc=0x0c06e8c8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c06e8ca;
P_0c06e8ca: /* original ffcb, guest PC 0x0c06e8ca */
if(!s->budget--) { s->failed_pc=0x0c06e8cau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c06e8cc;
P_0c06e8cc: /* original 4f22, guest PC 0x0c06e8cc */
if(!s->budget--) { s->failed_pc=0x0c06e8ccu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06e8ce;
P_0c06e8ce: /* original fe5c, guest PC 0x0c06e8ce */
if(!s->budget--) { s->failed_pc=0x0c06e8ceu; return 0; }
vf3_matrix_move(s,14,5);
goto P_0c06e8d0;
P_0c06e8d0: /* original ff4c, guest PC 0x0c06e8d0 */
if(!s->budget--) { s->failed_pc=0x0c06e8d0u; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c06e8d2;
P_0c06e8d2: /* original 7fd0, guest PC 0x0c06e8d2 */
if(!s->budget--) { s->failed_pc=0x0c06e8d2u; return 0; }
r[15]+=0xffffffd0u;
goto P_0c06e8d4;
P_0c06e8d4: /* original 1f44, guest PC 0x0c06e8d4 */
if(!s->budget--) { s->failed_pc=0x0c06e8d4u; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c06e8d6;
P_0c06e8d6: /* original e40f, guest PC 0x0c06e8d6 */
if(!s->budget--) { s->failed_pc=0x0c06e8d6u; return 0; }
r[4]=0x0000000fu;
goto P_0c06e8d8;
P_0c06e8d8: /* original 1f57, guest PC 0x0c06e8d8 */
if(!s->budget--) { s->failed_pc=0x0c06e8d8u; return 0; }
write(ram,r[15]+28,r[5],4);
goto P_0c06e8da;
P_0c06e8da: /* original 1f65, guest PC 0x0c06e8da */
if(!s->budget--) { s->failed_pc=0x0c06e8dau; return 0; }
write(ram,r[15]+20,r[6],4);
goto P_0c06e8dc;
P_0c06e8dc: /* original 1f76, guest PC 0x0c06e8dc */
if(!s->budget--) { s->failed_pc=0x0c06e8dcu; return 0; }
write(ram,r[15]+24,r[7],4);
goto P_0c06e8de;
P_0c06e8de: /* original d21d, guest PC 0x0c06e8de */
if(!s->budget--) { s->failed_pc=0x0c06e8deu; return 0; }
r[2]=read(ram,0x0c06e954u,4);
goto P_0c06e8e0;
P_0c06e8e0: /* original d31b, guest PC 0x0c06e8e0 */
if(!s->budget--) { s->failed_pc=0x0c06e8e0u; return 0; }
r[3]=read(ram,0x0c06e950u,4);
goto P_0c06e8e2;
P_0c06e8e2: /* original 6020, guest PC 0x0c06e8e2 */
if(!s->budget--) { s->failed_pc=0x0c06e8e2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c06e8e4;
P_0c06e8e4: /* original 600c, guest PC 0x0c06e8e4 */
if(!s->budget--) { s->failed_pc=0x0c06e8e4u; return 0; }
r[0]=r[0]&255u;
goto P_0c06e8e6;
P_0c06e8e6: /* original 2409, guest PC 0x0c06e8e6 */
if(!s->budget--) { s->failed_pc=0x0c06e8e6u; return 0; }
r[4]&=r[0];
goto P_0c06e8e8;
P_0c06e8e8: /* original 6043, guest PC 0x0c06e8e8 */
if(!s->budget--) { s->failed_pc=0x0c06e8e8u; return 0; }
r[0]=r[4];
goto P_0c06e8ea;
P_0c06e8ea: /* original 880f, guest PC 0x0c06e8ea */
if(!s->budget--) { s->failed_pc=0x0c06e8eau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c06e8ec;
P_0c06e8ec: /* original 8f15, guest PC 0x0c06e8ec */
if(!s->budget--) { s->failed_pc=0x0c06e8ecu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[3],4);
r[5]=tmp;
if(!cond) { goto P_0c06e91a; }
goto P_0c06e8f0;
P_0c06e8ee: /* original 6532, guest PC 0x0c06e8ee */
if(!s->budget--) { s->failed_pc=0x0c06e8eeu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06e8f0;
P_0c06e8f0: /* original f3fc, guest PC 0x0c06e8f0 */
if(!s->budget--) { s->failed_pc=0x0c06e8f0u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c06e8f2;
P_0c06e8f2: /* original f3f2, guest PC 0x0c06e8f2 */
if(!s->budget--) { s->failed_pc=0x0c06e8f2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06e8f4;
P_0c06e8f4: /* original f0ec, guest PC 0x0c06e8f4 */
if(!s->budget--) { s->failed_pc=0x0c06e8f4u; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c06e8f6;
P_0c06e8f6: /* original c718, guest PC 0x0c06e8f6 */
if(!s->budget--) { s->failed_pc=0x0c06e8f6u; return 0; }
r[0]=code_base|0x0006e958u;
goto P_0c06e8f8;
P_0c06e8f8: /* original f508, guest PC 0x0c06e8f8 */
if(!s->budget--) { s->failed_pc=0x0c06e8f8u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c06e8fa;
P_0c06e8fa: /* original c718, guest PC 0x0c06e8fa */
if(!s->budget--) { s->failed_pc=0x0c06e8fau; return 0; }
r[0]=code_base|0x0006e95cu;
goto P_0c06e8fc;
P_0c06e8fc: /* original f208, guest PC 0x0c06e8fc */
if(!s->budget--) { s->failed_pc=0x0c06e8fcu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c06e8fe;
P_0c06e8fe: /* original f3ee, guest PC 0x0c06e8fe */
if(!s->budget--) { s->failed_pc=0x0c06e8feu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[14],fr[3],r[18]);
goto P_0c06e900;
P_0c06e900: /* original f43c, guest PC 0x0c06e900 */
if(!s->budget--) { s->failed_pc=0x0c06e900u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c06e902;
P_0c06e902: /* original f245, guest PC 0x0c06e902 */
if(!s->budget--) { s->failed_pc=0x0c06e902u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c06e904;
P_0c06e904: /* original 8f02, guest PC 0x0c06e904 */
if(!s->budget--) { s->failed_pc=0x0c06e904u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,13,15);
if(!cond) { goto P_0c06e90c; }
goto P_0c06e908;
P_0c06e906: /* original fdfc, guest PC 0x0c06e906 */
if(!s->budget--) { s->failed_pc=0x0c06e906u; return 0; }
vf3_matrix_move(s,13,15);
goto P_0c06e908;
P_0c06e908: /* original a001, guest PC 0x0c06e908 */
if(!s->budget--) { s->failed_pc=0x0c06e908u; return 0; }
fr[4]=0;
goto P_0c06e90e;
P_0c06e90a: /* original f48d, guest PC 0x0c06e90a */
if(!s->budget--) { s->failed_pc=0x0c06e90au; return 0; }
fr[4]=0;
goto P_0c06e90c;
P_0c06e90c: /* original f47d, guest PC 0x0c06e90c */
if(!s->budget--) { s->failed_pc=0x0c06e90cu; return 0; }
if(!vf3_fpu_fsrra(fr[4],r[18],&fr[4])) goto unsupported;
goto P_0c06e90e;
P_0c06e90e: /* original fd42, guest PC 0x0c06e90e */
if(!s->budget--) { s->failed_pc=0x0c06e90eu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'*');
goto P_0c06e910;
P_0c06e910: /* original fcec, guest PC 0x0c06e910 */
if(!s->budget--) { s->failed_pc=0x0c06e910u; return 0; }
vf3_matrix_move(s,12,14);
goto P_0c06e912;
P_0c06e912: /* original fc42, guest PC 0x0c06e912 */
if(!s->budget--) { s->failed_pc=0x0c06e912u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'*');
goto P_0c06e914;
P_0c06e914: /* original fd52, guest PC 0x0c06e914 */
if(!s->budget--) { s->failed_pc=0x0c06e914u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[5],r[18],'*');
goto P_0c06e916;
P_0c06e916: /* original a083, guest PC 0x0c06e916 */
if(!s->budget--) { s->failed_pc=0x0c06e916u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[5],r[18],'*');
goto P_0c06ea20;
P_0c06e918: /* original fc52, guest PC 0x0c06e918 */
if(!s->budget--) { s->failed_pc=0x0c06e918u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[5],r[18],'*');
goto P_0c06e91a;
P_0c06e91a: /* original 9016, guest PC 0x0c06e91a */
if(!s->budget--) { s->failed_pc=0x0c06e91au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06e94au,2);
goto P_0c06e91c;
P_0c06e91c: /* original f39d, guest PC 0x0c06e91c */
if(!s->budget--) { s->failed_pc=0x0c06e91cu; return 0; }
fr[3]=0x3f800000u;
goto P_0c06e91e;
P_0c06e91e: /* original 045e, guest PC 0x0c06e91e */
if(!s->budget--) { s->failed_pc=0x0c06e91eu; return 0; }
r[4]=read(ram,r[5]+r[0],4);
goto P_0c06e920;
P_0c06e920: /* original c70f, guest PC 0x0c06e920 */
if(!s->budget--) { s->failed_pc=0x0c06e920u; return 0; }
r[0]=code_base|0x0006e960u;
goto P_0c06e922;
P_0c06e922: /* original f908, guest PC 0x0c06e922 */
if(!s->budget--) { s->failed_pc=0x0c06e922u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c06e924;
P_0c06e924: /* original e020, guest PC 0x0c06e924 */
if(!s->budget--) { s->failed_pc=0x0c06e924u; return 0; }
r[0]=0x00000020u;
goto P_0c06e926;
P_0c06e926: /* original f48d, guest PC 0x0c06e926 */
if(!s->budget--) { s->failed_pc=0x0c06e926u; return 0; }
fr[4]=0;
goto P_0c06e928;
P_0c06e928: /* original fc4c, guest PC 0x0c06e928 */
if(!s->budget--) { s->failed_pc=0x0c06e928u; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c06e92a;
P_0c06e92a: /* original fd4c, guest PC 0x0c06e92a */
if(!s->budget--) { s->failed_pc=0x0c06e92au; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c06e92c;
P_0c06e92c: /* original ff37, guest PC 0x0c06e92c */
if(!s->budget--) { s->failed_pc=0x0c06e92cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e92e;
P_0c06e92e: /* original e02c, guest PC 0x0c06e92e */
if(!s->budget--) { s->failed_pc=0x0c06e92eu; return 0; }
r[0]=0x0000002cu;
goto P_0c06e930;
P_0c06e930: /* original 6546, guest PC 0x0c06e930 */
if(!s->budget--) { s->failed_pc=0x0c06e930u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[5]=tmp;
goto P_0c06e932;
P_0c06e932: /* original f649, guest PC 0x0c06e932 */
if(!s->budget--) { s->failed_pc=0x0c06e932u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e934;
P_0c06e934: /* original f549, guest PC 0x0c06e934 */
if(!s->budget--) { s->failed_pc=0x0c06e934u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e936;
P_0c06e936: /* original f349, guest PC 0x0c06e936 */
if(!s->budget--) { s->failed_pc=0x0c06e936u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e938;
P_0c06e938: /* original ff37, guest PC 0x0c06e938 */
if(!s->budget--) { s->failed_pc=0x0c06e938u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e93a;
P_0c06e93a: /* original e028, guest PC 0x0c06e93a */
if(!s->budget--) { s->failed_pc=0x0c06e93au; return 0; }
r[0]=0x00000028u;
goto P_0c06e93c;
P_0c06e93c: /* original f349, guest PC 0x0c06e93c */
if(!s->budget--) { s->failed_pc=0x0c06e93cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e93e;
P_0c06e93e: /* original a06d, guest PC 0x0c06e93e */
if(!s->budget--) { s->failed_pc=0x0c06e93eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06ea1c;
P_0c06e940: /* original ff37, guest PC 0x0c06e940 */
if(!s->budget--) { s->failed_pc=0x0c06e940u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(!vf3_matrix_family(0x0c06e942u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06e942u; return 0; } return 1;
P_0c06e964: /* original e02c, guest PC 0x0c06e964 */
if(!s->budget--) { s->failed_pc=0x0c06e964u; return 0; }
r[0]=0x0000002cu;
goto P_0c06e966;
P_0c06e966: /* original fb6c, guest PC 0x0c06e966 */
if(!s->budget--) { s->failed_pc=0x0c06e966u; return 0; }
vf3_matrix_move(s,11,6);
goto P_0c06e968;
P_0c06e968: /* original f6f6, guest PC 0x0c06e968 */
if(!s->budget--) { s->failed_pc=0x0c06e968u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c06e96a;
P_0c06e96a: /* original e028, guest PC 0x0c06e96a */
if(!s->budget--) { s->failed_pc=0x0c06e96au; return 0; }
r[0]=0x00000028u;
goto P_0c06e96c;
P_0c06e96c: /* original f4fc, guest PC 0x0c06e96c */
if(!s->budget--) { s->failed_pc=0x0c06e96cu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c06e96e;
P_0c06e96e: /* original f4b1, guest PC 0x0c06e96e */
if(!s->budget--) { s->failed_pc=0x0c06e96eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[11],r[18],'-');
goto P_0c06e970;
P_0c06e970: /* original f86c, guest PC 0x0c06e970 */
if(!s->budget--) { s->failed_pc=0x0c06e970u; return 0; }
vf3_matrix_move(s,8,6);
goto P_0c06e972;
P_0c06e972: /* original f8b1, guest PC 0x0c06e972 */
if(!s->budget--) { s->failed_pc=0x0c06e972u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[11],r[18],'-');
goto P_0c06e974;
P_0c06e974: /* original fa5c, guest PC 0x0c06e974 */
if(!s->budget--) { s->failed_pc=0x0c06e974u; return 0; }
vf3_matrix_move(s,10,5);
goto P_0c06e976;
P_0c06e976: /* original f5f6, guest PC 0x0c06e976 */
if(!s->budget--) { s->failed_pc=0x0c06e976u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c06e978;
P_0c06e978: /* original e024, guest PC 0x0c06e978 */
if(!s->budget--) { s->failed_pc=0x0c06e978u; return 0; }
r[0]=0x00000024u;
goto P_0c06e97a;
P_0c06e97a: /* original f3ec, guest PC 0x0c06e97a */
if(!s->budget--) { s->failed_pc=0x0c06e97au; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c06e97c;
P_0c06e97c: /* original f3a1, guest PC 0x0c06e97c */
if(!s->budget--) { s->failed_pc=0x0c06e97cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[10],r[18],'-');
goto P_0c06e97e;
P_0c06e97e: /* original f75c, guest PC 0x0c06e97e */
if(!s->budget--) { s->failed_pc=0x0c06e97eu; return 0; }
vf3_matrix_move(s,7,5);
goto P_0c06e980;
P_0c06e980: /* original f7a1, guest PC 0x0c06e980 */
if(!s->budget--) { s->failed_pc=0x0c06e980u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[10],r[18],'-');
goto P_0c06e982;
P_0c06e982: /* original ff37, guest PC 0x0c06e982 */
if(!s->budget--) { s->failed_pc=0x0c06e982u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e984;
P_0c06e984: /* original e00c, guest PC 0x0c06e984 */
if(!s->budget--) { s->failed_pc=0x0c06e984u; return 0; }
r[0]=0x0000000cu;
goto P_0c06e986;
P_0c06e986: /* original f24c, guest PC 0x0c06e986 */
if(!s->budget--) { s->failed_pc=0x0c06e986u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c06e988;
P_0c06e988: /* original f48c, guest PC 0x0c06e988 */
if(!s->budget--) { s->failed_pc=0x0c06e988u; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c06e98a;
P_0c06e98a: /* original f422, guest PC 0x0c06e98a */
if(!s->budget--) { s->failed_pc=0x0c06e98au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'*');
goto P_0c06e98c;
P_0c06e98c: /* original f07c, guest PC 0x0c06e98c */
if(!s->budget--) { s->failed_pc=0x0c06e98cu; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c06e98e;
P_0c06e98e: /* original f14c, guest PC 0x0c06e98e */
if(!s->budget--) { s->failed_pc=0x0c06e98eu; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c06e990;
P_0c06e990: /* original f13e, guest PC 0x0c06e990 */
if(!s->budget--) { s->failed_pc=0x0c06e990u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[3],fr[1],r[18]);
goto P_0c06e992;
P_0c06e992: /* original f38c, guest PC 0x0c06e992 */
if(!s->budget--) { s->failed_pc=0x0c06e992u; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c06e994;
P_0c06e994: /* original f382, guest PC 0x0c06e994 */
if(!s->budget--) { s->failed_pc=0x0c06e994u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c06e996;
P_0c06e996: /* original f41c, guest PC 0x0c06e996 */
if(!s->budget--) { s->failed_pc=0x0c06e996u; return 0; }
vf3_matrix_move(s,4,1);
goto P_0c06e998;
P_0c06e998: /* original f37e, guest PC 0x0c06e998 */
if(!s->budget--) { s->failed_pc=0x0c06e998u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[7],fr[3],r[18]);
goto P_0c06e99a;
P_0c06e99a: /* original f433, guest PC 0x0c06e99a */
if(!s->budget--) { s->failed_pc=0x0c06e99au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c06e99c;
P_0c06e99c: /* original ff37, guest PC 0x0c06e99c */
if(!s->budget--) { s->failed_pc=0x0c06e99cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06e99e;
P_0c06e99e: /* original f249, guest PC 0x0c06e99e */
if(!s->budget--) { s->failed_pc=0x0c06e99eu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e9a0;
P_0c06e9a0: /* original e02c, guest PC 0x0c06e9a0 */
if(!s->budget--) { s->failed_pc=0x0c06e9a0u; return 0; }
r[0]=0x0000002cu;
goto P_0c06e9a2;
P_0c06e9a2: /* original ff27, guest PC 0x0c06e9a2 */
if(!s->budget--) { s->failed_pc=0x0c06e9a2u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c06e9a4;
P_0c06e9a4: /* original f249, guest PC 0x0c06e9a4 */
if(!s->budget--) { s->failed_pc=0x0c06e9a4u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e9a6;
P_0c06e9a6: /* original e028, guest PC 0x0c06e9a6 */
if(!s->budget--) { s->failed_pc=0x0c06e9a6u; return 0; }
r[0]=0x00000028u;
goto P_0c06e9a8;
P_0c06e9a8: /* original ff27, guest PC 0x0c06e9a8 */
if(!s->budget--) { s->failed_pc=0x0c06e9a8u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c06e9aa;
P_0c06e9aa: /* original f28d, guest PC 0x0c06e9aa */
if(!s->budget--) { s->failed_pc=0x0c06e9aau; return 0; }
fr[2]=0;
goto P_0c06e9ac;
P_0c06e9ac: /* original f245, guest PC 0x0c06e9ac */
if(!s->budget--) { s->failed_pc=0x0c06e9acu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c06e9ae;
P_0c06e9ae: /* original 891f, guest PC 0x0c06e9ae */
if(!s->budget--) { s->failed_pc=0x0c06e9aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06e9f0; }
goto P_0c06e9b0;
P_0c06e9b0: /* original e020, guest PC 0x0c06e9b0 */
if(!s->budget--) { s->failed_pc=0x0c06e9b0u; return 0; }
r[0]=0x00000020u;
goto P_0c06e9b2;
P_0c06e9b2: /* original f2f6, guest PC 0x0c06e9b2 */
if(!s->budget--) { s->failed_pc=0x0c06e9b2u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c06e9b4;
P_0c06e9b4: /* original f425, guest PC 0x0c06e9b4 */
if(!s->budget--) { s->failed_pc=0x0c06e9b4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c06e9b6;
P_0c06e9b6: /* original 891b, guest PC 0x0c06e9b6 */
if(!s->budget--) { s->failed_pc=0x0c06e9b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06e9f0; }
goto P_0c06e9b8;
P_0c06e9b8: /* original f742, guest PC 0x0c06e9b8 */
if(!s->budget--) { s->failed_pc=0x0c06e9b8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c06e9ba;
P_0c06e9ba: /* original c737, guest PC 0x0c06e9ba */
if(!s->budget--) { s->failed_pc=0x0c06e9bau; return 0; }
r[0]=code_base|0x0006ea98u;
goto P_0c06e9bc;
P_0c06e9bc: /* original f842, guest PC 0x0c06e9bc */
if(!s->budget--) { s->failed_pc=0x0c06e9bcu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'*');
goto P_0c06e9be;
P_0c06e9be: /* original f37c, guest PC 0x0c06e9be */
if(!s->budget--) { s->failed_pc=0x0c06e9beu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c06e9c0;
P_0c06e9c0: /* original f3a0, guest PC 0x0c06e9c0 */
if(!s->budget--) { s->failed_pc=0x0c06e9c0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[10],r[18],'+');
goto P_0c06e9c2;
P_0c06e9c2: /* original f8b0, guest PC 0x0c06e9c2 */
if(!s->budget--) { s->failed_pc=0x0c06e9c2u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[11],r[18],'+');
goto P_0c06e9c4;
P_0c06e9c4: /* original ff3a, guest PC 0x0c06e9c4 */
if(!s->budget--) { s->failed_pc=0x0c06e9c4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c06e9c6;
P_0c06e9c6: /* original f7fc, guest PC 0x0c06e9c6 */
if(!s->budget--) { s->failed_pc=0x0c06e9c6u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c06e9c8;
P_0c06e9c8: /* original f781, guest PC 0x0c06e9c8 */
if(!s->budget--) { s->failed_pc=0x0c06e9c8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[8],r[18],'-');
goto P_0c06e9ca;
P_0c06e9ca: /* original f4ec, guest PC 0x0c06e9ca */
if(!s->budget--) { s->failed_pc=0x0c06e9cau; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06e9cc;
P_0c06e9cc: /* original f431, guest PC 0x0c06e9cc */
if(!s->budget--) { s->failed_pc=0x0c06e9ccu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c06e9ce;
P_0c06e9ce: /* original f308, guest PC 0x0c06e9ce */
if(!s->budget--) { s->failed_pc=0x0c06e9ceu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06e9d0;
P_0c06e9d0: /* original f772, guest PC 0x0c06e9d0 */
if(!s->budget--) { s->failed_pc=0x0c06e9d0u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[7],r[18],'*');
goto P_0c06e9d2;
P_0c06e9d2: /* original f442, guest PC 0x0c06e9d2 */
if(!s->budget--) { s->failed_pc=0x0c06e9d2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[4],r[18],'*');
goto P_0c06e9d4;
P_0c06e9d4: /* original f470, guest PC 0x0c06e9d4 */
if(!s->budget--) { s->failed_pc=0x0c06e9d4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'+');
goto P_0c06e9d6;
P_0c06e9d6: /* original f345, guest PC 0x0c06e9d6 */
if(!s->budget--) { s->failed_pc=0x0c06e9d6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c06e9d8;
P_0c06e9d8: /* original 8b01, guest PC 0x0c06e9d8 */
if(!s->budget--) { s->failed_pc=0x0c06e9d8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06e9de; }
goto P_0c06e9da;
P_0c06e9da: /* original a002, guest PC 0x0c06e9da */
if(!s->budget--) { s->failed_pc=0x0c06e9dau; return 0; }
fr[7]=0;
goto P_0c06e9e2;
P_0c06e9dc: /* original f78d, guest PC 0x0c06e9dc */
if(!s->budget--) { s->failed_pc=0x0c06e9dcu; return 0; }
fr[7]=0;
goto P_0c06e9de;
P_0c06e9de: /* original f74c, guest PC 0x0c06e9de */
if(!s->budget--) { s->failed_pc=0x0c06e9deu; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c06e9e0;
P_0c06e9e0: /* original f77d, guest PC 0x0c06e9e0 */
if(!s->budget--) { s->failed_pc=0x0c06e9e0u; return 0; }
if(!vf3_fpu_fsrra(fr[7],r[18],&fr[7])) goto unsupported;
goto P_0c06e9e2;
P_0c06e9e2: /* original f472, guest PC 0x0c06e9e2 */
if(!s->budget--) { s->failed_pc=0x0c06e9e2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c06e9e4;
P_0c06e9e4: /* original f945, guest PC 0x0c06e9e4 */
if(!s->budget--) { s->failed_pc=0x0c06e9e4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[4]))!=0);
goto P_0c06e9e6;
P_0c06e9e6: /* original 8b18, guest PC 0x0c06e9e6 */
if(!s->budget--) { s->failed_pc=0x0c06e9e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ea1a; }
goto P_0c06e9e8;
P_0c06e9e8: /* original fd8c, guest PC 0x0c06e9e8 */
if(!s->budget--) { s->failed_pc=0x0c06e9e8u; return 0; }
vf3_matrix_move(s,13,8);
goto P_0c06e9ea;
P_0c06e9ea: /* original f94c, guest PC 0x0c06e9ea */
if(!s->budget--) { s->failed_pc=0x0c06e9eau; return 0; }
vf3_matrix_move(s,9,4);
goto P_0c06e9ec;
P_0c06e9ec: /* original a015, guest PC 0x0c06e9ec */
if(!s->budget--) { s->failed_pc=0x0c06e9ecu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
goto P_0c06ea1a;
P_0c06e9ee: /* original fcf8, guest PC 0x0c06e9ee */
if(!s->budget--) { s->failed_pc=0x0c06e9eeu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
goto P_0c06e9f0;
P_0c06e9f0: /* original f4ec, guest PC 0x0c06e9f0 */
if(!s->budget--) { s->failed_pc=0x0c06e9f0u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06e9f2;
P_0c06e9f2: /* original f451, guest PC 0x0c06e9f2 */
if(!s->budget--) { s->failed_pc=0x0c06e9f2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c06e9f4;
P_0c06e9f4: /* original f7fc, guest PC 0x0c06e9f4 */
if(!s->budget--) { s->failed_pc=0x0c06e9f4u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c06e9f6;
P_0c06e9f6: /* original f761, guest PC 0x0c06e9f6 */
if(!s->budget--) { s->failed_pc=0x0c06e9f6u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'-');
goto P_0c06e9f8;
P_0c06e9f8: /* original c727, guest PC 0x0c06e9f8 */
if(!s->budget--) { s->failed_pc=0x0c06e9f8u; return 0; }
r[0]=code_base|0x0006ea98u;
goto P_0c06e9fa;
P_0c06e9fa: /* original f308, guest PC 0x0c06e9fa */
if(!s->budget--) { s->failed_pc=0x0c06e9fau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06e9fc;
P_0c06e9fc: /* original f442, guest PC 0x0c06e9fc */
if(!s->budget--) { s->failed_pc=0x0c06e9fcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[4],r[18],'*');
goto P_0c06e9fe;
P_0c06e9fe: /* original f772, guest PC 0x0c06e9fe */
if(!s->budget--) { s->failed_pc=0x0c06e9feu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[7],r[18],'*');
goto P_0c06ea00;
P_0c06ea00: /* original f470, guest PC 0x0c06ea00 */
if(!s->budget--) { s->failed_pc=0x0c06ea00u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'+');
goto P_0c06ea02;
P_0c06ea02: /* original f345, guest PC 0x0c06ea02 */
if(!s->budget--) { s->failed_pc=0x0c06ea02u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c06ea04;
P_0c06ea04: /* original 8b01, guest PC 0x0c06ea04 */
if(!s->budget--) { s->failed_pc=0x0c06ea04u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ea0a; }
goto P_0c06ea06;
P_0c06ea06: /* original a002, guest PC 0x0c06ea06 */
if(!s->budget--) { s->failed_pc=0x0c06ea06u; return 0; }
fr[7]=0;
goto P_0c06ea0e;
P_0c06ea08: /* original f78d, guest PC 0x0c06ea08 */
if(!s->budget--) { s->failed_pc=0x0c06ea08u; return 0; }
fr[7]=0;
goto P_0c06ea0a;
P_0c06ea0a: /* original f74c, guest PC 0x0c06ea0a */
if(!s->budget--) { s->failed_pc=0x0c06ea0au; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c06ea0c;
P_0c06ea0c: /* original f77d, guest PC 0x0c06ea0c */
if(!s->budget--) { s->failed_pc=0x0c06ea0cu; return 0; }
if(!vf3_fpu_fsrra(fr[7],r[18],&fr[7])) goto unsupported;
goto P_0c06ea0e;
P_0c06ea0e: /* original f472, guest PC 0x0c06ea0e */
if(!s->budget--) { s->failed_pc=0x0c06ea0eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c06ea10;
P_0c06ea10: /* original f945, guest PC 0x0c06ea10 */
if(!s->budget--) { s->failed_pc=0x0c06ea10u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[4]))!=0);
goto P_0c06ea12;
P_0c06ea12: /* original 8b02, guest PC 0x0c06ea12 */
if(!s->budget--) { s->failed_pc=0x0c06ea12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ea1a; }
goto P_0c06ea14;
P_0c06ea14: /* original fc5c, guest PC 0x0c06ea14 */
if(!s->budget--) { s->failed_pc=0x0c06ea14u; return 0; }
vf3_matrix_move(s,12,5);
goto P_0c06ea16;
P_0c06ea16: /* original fd6c, guest PC 0x0c06ea16 */
if(!s->budget--) { s->failed_pc=0x0c06ea16u; return 0; }
vf3_matrix_move(s,13,6);
goto P_0c06ea18;
P_0c06ea18: /* original f94c, guest PC 0x0c06ea18 */
if(!s->budget--) { s->failed_pc=0x0c06ea18u; return 0; }
vf3_matrix_move(s,9,4);
goto P_0c06ea1a;
P_0c06ea1a: /* original 75ff, guest PC 0x0c06ea1a */
if(!s->budget--) { s->failed_pc=0x0c06ea1au; return 0; }
r[5]+=0xffffffffu;
goto P_0c06ea1c;
P_0c06ea1c: /* original 2558, guest PC 0x0c06ea1c */
if(!s->budget--) { s->failed_pc=0x0c06ea1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06ea1e;
P_0c06ea1e: /* original 8ba1, guest PC 0x0c06ea1e */
if(!s->budget--) { s->failed_pc=0x0c06ea1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06e964; }
goto P_0c06ea20;
P_0c06ea20: /* original f3ec, guest PC 0x0c06ea20 */
if(!s->budget--) { s->failed_pc=0x0c06ea20u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c06ea22;
P_0c06ea22: /* original f3c1, guest PC 0x0c06ea22 */
if(!s->budget--) { s->failed_pc=0x0c06ea22u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'-');
goto P_0c06ea24;
P_0c06ea24: /* original e008, guest PC 0x0c06ea24 */
if(!s->budget--) { s->failed_pc=0x0c06ea24u; return 0; }
r[0]=0x00000008u;
goto P_0c06ea26;
P_0c06ea26: /* original ff37, guest PC 0x0c06ea26 */
if(!s->budget--) { s->failed_pc=0x0c06ea26u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06ea28;
P_0c06ea28: /* original e004, guest PC 0x0c06ea28 */
if(!s->budget--) { s->failed_pc=0x0c06ea28u; return 0; }
r[0]=0x00000004u;
goto P_0c06ea2a;
P_0c06ea2a: /* original f2fc, guest PC 0x0c06ea2a */
if(!s->budget--) { s->failed_pc=0x0c06ea2au; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c06ea2c;
P_0c06ea2c: /* original f2d1, guest PC 0x0c06ea2c */
if(!s->budget--) { s->failed_pc=0x0c06ea2cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[13],r[18],'-');
goto P_0c06ea2e;
P_0c06ea2e: /* original f53c, guest PC 0x0c06ea2e */
if(!s->budget--) { s->failed_pc=0x0c06ea2eu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c06ea30;
P_0c06ea30: /* original ff27, guest PC 0x0c06ea30 */
if(!s->budget--) { s->failed_pc=0x0c06ea30u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c06ea32;
P_0c06ea32: /* original d31a, guest PC 0x0c06ea32 */
if(!s->budget--) { s->failed_pc=0x0c06ea32u; return 0; }
r[3]=read(ram,0x0c06ea9cu,4);
goto P_0c06ea34;
P_0c06ea34: /* original 430b, guest PC 0x0c06ea34 */
if(!s->budget--) { s->failed_pc=0x0c06ea34u; return 0; }
target=r[3];
r[16]=code_base|0x0c06ea38u;
vf3_matrix_move(s,4,2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ea38u) { target=s->pc; goto dispatch; }
goto P_0c06ea38;
P_0c06ea36: /* original f42c, guest PC 0x0c06ea36 */
if(!s->budget--) { s->failed_pc=0x0c06ea36u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c06ea38;
P_0c06ea38: /* original 640f, guest PC 0x0c06ea38 */
if(!s->budget--) { s->failed_pc=0x0c06ea38u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c06ea3a;
P_0c06ea3a: /* original f4fc, guest PC 0x0c06ea3a */
if(!s->budget--) { s->failed_pc=0x0c06ea3au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c06ea3c;
P_0c06ea3c: /* original e004, guest PC 0x0c06ea3c */
if(!s->budget--) { s->failed_pc=0x0c06ea3cu; return 0; }
r[0]=0x00000004u;
goto P_0c06ea3e;
P_0c06ea3e: /* original f3f6, guest PC 0x0c06ea3e */
if(!s->budget--) { s->failed_pc=0x0c06ea3eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06ea40;
P_0c06ea40: /* original e008, guest PC 0x0c06ea40 */
if(!s->budget--) { s->failed_pc=0x0c06ea40u; return 0; }
r[0]=0x00000008u;
goto P_0c06ea42;
P_0c06ea42: /* original f0f6, guest PC 0x0c06ea42 */
if(!s->budget--) { s->failed_pc=0x0c06ea42u; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c06ea44;
P_0c06ea44: /* original f432, guest PC 0x0c06ea44 */
if(!s->budget--) { s->failed_pc=0x0c06ea44u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c06ea46;
P_0c06ea46: /* original f24c, guest PC 0x0c06ea46 */
if(!s->budget--) { s->failed_pc=0x0c06ea46u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c06ea48;
P_0c06ea48: /* original f2ee, guest PC 0x0c06ea48 */
if(!s->budget--) { s->failed_pc=0x0c06ea48u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[14],fr[2],r[18]);
goto P_0c06ea4a;
P_0c06ea4a: /* original f42c, guest PC 0x0c06ea4a */
if(!s->budget--) { s->failed_pc=0x0c06ea4au; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c06ea4c;
P_0c06ea4c: /* original f28d, guest PC 0x0c06ea4c */
if(!s->budget--) { s->failed_pc=0x0c06ea4cu; return 0; }
fr[2]=0;
goto P_0c06ea4e;
P_0c06ea4e: /* original f245, guest PC 0x0c06ea4e */
if(!s->budget--) { s->failed_pc=0x0c06ea4eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c06ea50;
P_0c06ea50: /* original 8d03, guest PC 0x0c06ea50 */
if(!s->budget--) { s->failed_pc=0x0c06ea50u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,13);
if(cond) { goto P_0c06ea5a; }
goto P_0c06ea54;
P_0c06ea52: /* original f5dc, guest PC 0x0c06ea52 */
if(!s->budget--) { s->failed_pc=0x0c06ea52u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c06ea54;
P_0c06ea54: /* original d212, guest PC 0x0c06ea54 */
if(!s->budget--) { s->failed_pc=0x0c06ea54u; return 0; }
r[2]=read(ram,0x0c06eaa0u,4);
goto P_0c06ea56;
P_0c06ea56: /* original 224a, guest PC 0x0c06ea56 */
if(!s->budget--) { s->failed_pc=0x0c06ea56u; return 0; }
r[2]^=r[4];
goto P_0c06ea58;
P_0c06ea58: /* original 642f, guest PC 0x0c06ea58 */
if(!s->budget--) { s->failed_pc=0x0c06ea58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c06ea5a;
P_0c06ea5a: /* original f4cc, guest PC 0x0c06ea5a */
if(!s->budget--) { s->failed_pc=0x0c06ea5au; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c06ea5c;
P_0c06ea5c: /* original f4e1, guest PC 0x0c06ea5c */
if(!s->budget--) { s->failed_pc=0x0c06ea5cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'-');
goto P_0c06ea5e;
P_0c06ea5e: /* original f5f1, guest PC 0x0c06ea5e */
if(!s->budget--) { s->failed_pc=0x0c06ea5eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'-');
goto P_0c06ea60;
P_0c06ea60: /* original c70d, guest PC 0x0c06ea60 */
if(!s->budget--) { s->failed_pc=0x0c06ea60u; return 0; }
r[0]=code_base|0x0006ea98u;
goto P_0c06ea62;
P_0c06ea62: /* original f308, guest PC 0x0c06ea62 */
if(!s->budget--) { s->failed_pc=0x0c06ea62u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06ea64;
P_0c06ea64: /* original f442, guest PC 0x0c06ea64 */
if(!s->budget--) { s->failed_pc=0x0c06ea64u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[4],r[18],'*');
goto P_0c06ea66;
P_0c06ea66: /* original f552, guest PC 0x0c06ea66 */
if(!s->budget--) { s->failed_pc=0x0c06ea66u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[5],r[18],'*');
goto P_0c06ea68;
P_0c06ea68: /* original f450, guest PC 0x0c06ea68 */
if(!s->budget--) { s->failed_pc=0x0c06ea68u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c06ea6a;
P_0c06ea6a: /* original f345, guest PC 0x0c06ea6a */
if(!s->budget--) { s->failed_pc=0x0c06ea6au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c06ea6c;
P_0c06ea6c: /* original 8b01, guest PC 0x0c06ea6c */
if(!s->budget--) { s->failed_pc=0x0c06ea6cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ea72; }
goto P_0c06ea6e;
P_0c06ea6e: /* original a002, guest PC 0x0c06ea6e */
if(!s->budget--) { s->failed_pc=0x0c06ea6eu; return 0; }
fr[5]=0;
goto P_0c06ea76;
P_0c06ea70: /* original f58d, guest PC 0x0c06ea70 */
if(!s->budget--) { s->failed_pc=0x0c06ea70u; return 0; }
fr[5]=0;
goto P_0c06ea72;
P_0c06ea72: /* original f54c, guest PC 0x0c06ea72 */
if(!s->budget--) { s->failed_pc=0x0c06ea72u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c06ea74;
P_0c06ea74: /* original f57d, guest PC 0x0c06ea74 */
if(!s->budget--) { s->failed_pc=0x0c06ea74u; return 0; }
if(!vf3_fpu_fsrra(fr[5],r[18],&fr[5])) goto unsupported;
goto P_0c06ea76;
P_0c06ea76: /* original 53f4, guest PC 0x0c06ea76 */
if(!s->budget--) { s->failed_pc=0x0c06ea76u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c06ea78;
P_0c06ea78: /* original f452, guest PC 0x0c06ea78 */
if(!s->budget--) { s->failed_pc=0x0c06ea78u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c06ea7a;
P_0c06ea7a: /* original f3da, guest PC 0x0c06ea7a */
if(!s->budget--) { s->failed_pc=0x0c06ea7au; return 0; }
vf3_matrix_store(s,ram,13,r[3]);
goto P_0c06ea7c;
P_0c06ea7c: /* original 53f7, guest PC 0x0c06ea7c */
if(!s->budget--) { s->failed_pc=0x0c06ea7cu; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c06ea7e;
P_0c06ea7e: /* original f3ca, guest PC 0x0c06ea7e */
if(!s->budget--) { s->failed_pc=0x0c06ea7eu; return 0; }
vf3_matrix_store(s,ram,12,r[3]);
goto P_0c06ea80;
P_0c06ea80: /* original 53f5, guest PC 0x0c06ea80 */
if(!s->budget--) { s->failed_pc=0x0c06ea80u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c06ea82;
P_0c06ea82: /* original f34a, guest PC 0x0c06ea82 */
if(!s->budget--) { s->failed_pc=0x0c06ea82u; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c06ea84;
P_0c06ea84: /* original 53f6, guest PC 0x0c06ea84 */
if(!s->budget--) { s->failed_pc=0x0c06ea84u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c06ea86;
P_0c06ea86: /* original 7f30, guest PC 0x0c06ea86 */
if(!s->budget--) { s->failed_pc=0x0c06ea86u; return 0; }
r[15]+=0x00000030u;
goto P_0c06ea88;
P_0c06ea88: /* original 4f26, guest PC 0x0c06ea88 */
if(!s->budget--) { s->failed_pc=0x0c06ea88u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06ea8a;
P_0c06ea8a: /* original 2342, guest PC 0x0c06ea8a */
if(!s->budget--) { s->failed_pc=0x0c06ea8au; return 0; }
write(ram,r[3],r[4],4);
goto P_0c06ea8c;
P_0c06ea8c: /* original fcf9, guest PC 0x0c06ea8c */
if(!s->budget--) { s->failed_pc=0x0c06ea8cu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06ea8e;
P_0c06ea8e: /* original fdf9, guest PC 0x0c06ea8e */
if(!s->budget--) { s->failed_pc=0x0c06ea8eu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06ea90;
P_0c06ea90: /* original fef9, guest PC 0x0c06ea90 */
if(!s->budget--) { s->failed_pc=0x0c06ea90u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06ea92;
P_0c06ea92: /* original 000b, guest PC 0x0c06ea92 */
if(!s->budget--) { s->failed_pc=0x0c06ea92u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c06ea94: /* original fff9, guest PC 0x0c06ea94 */
if(!s->budget--) { s->failed_pc=0x0c06ea94u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c06ea96u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06ea96u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
