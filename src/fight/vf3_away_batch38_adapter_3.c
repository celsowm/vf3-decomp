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
int vf3_away_batch38_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06c95eu: goto P_0c06c95e;
case 0x0c06c960u: goto P_0c06c960;
case 0x0c06c962u: goto P_0c06c962;
case 0x0c06c964u: goto P_0c06c964;
case 0x0c06c966u: goto P_0c06c966;
case 0x0c06c968u: goto P_0c06c968;
case 0x0c06c96au: goto P_0c06c96a;
case 0x0c06c96cu: goto P_0c06c96c;
case 0x0c06c96eu: goto P_0c06c96e;
case 0x0c06c970u: goto P_0c06c970;
case 0x0c06c972u: goto P_0c06c972;
case 0x0c06c974u: goto P_0c06c974;
case 0x0c06c976u: goto P_0c06c976;
case 0x0c06c978u: goto P_0c06c978;
case 0x0c06c97au: goto P_0c06c97a;
case 0x0c06c97cu: goto P_0c06c97c;
case 0x0c06c97eu: goto P_0c06c97e;
case 0x0c06c980u: goto P_0c06c980;
case 0x0c06c982u: goto P_0c06c982;
case 0x0c06c984u: goto P_0c06c984;
case 0x0c06c986u: goto P_0c06c986;
case 0x0c06c988u: goto P_0c06c988;
case 0x0c06c98au: goto P_0c06c98a;
case 0x0c06c98cu: goto P_0c06c98c;
case 0x0c06c98eu: goto P_0c06c98e;
case 0x0c06c990u: goto P_0c06c990;
case 0x0c06c992u: goto P_0c06c992;
case 0x0c06c994u: goto P_0c06c994;
case 0x0c06c996u: goto P_0c06c996;
case 0x0c06c998u: goto P_0c06c998;
case 0x0c06c99au: goto P_0c06c99a;
case 0x0c06c99cu: goto P_0c06c99c;
case 0x0c06c99eu: goto P_0c06c99e;
case 0x0c06c9a0u: goto P_0c06c9a0;
case 0x0c06c9a2u: goto P_0c06c9a2;
case 0x0c06c9a4u: goto P_0c06c9a4;
case 0x0c06c9a6u: goto P_0c06c9a6;
case 0x0c06c9a8u: goto P_0c06c9a8;
case 0x0c06c9aau: goto P_0c06c9aa;
case 0x0c06c9acu: goto P_0c06c9ac;
case 0x0c06c9aeu: goto P_0c06c9ae;
case 0x0c06c9b0u: goto P_0c06c9b0;
case 0x0c06c9b2u: goto P_0c06c9b2;
case 0x0c06c9b4u: goto P_0c06c9b4;
case 0x0c06c9b6u: goto P_0c06c9b6;
case 0x0c06c9b8u: goto P_0c06c9b8;
case 0x0c06c9bau: goto P_0c06c9ba;
case 0x0c06c9bcu: goto P_0c06c9bc;
case 0x0c06c9beu: goto P_0c06c9be;
case 0x0c06c9c0u: goto P_0c06c9c0;
case 0x0c06c9c2u: goto P_0c06c9c2;
case 0x0c06c9c4u: goto P_0c06c9c4;
case 0x0c06c9c6u: goto P_0c06c9c6;
case 0x0c06c9c8u: goto P_0c06c9c8;
case 0x0c06c9cau: goto P_0c06c9ca;
case 0x0c06c9ccu: goto P_0c06c9cc;
case 0x0c06c9ceu: goto P_0c06c9ce;
case 0x0c06c9d0u: goto P_0c06c9d0;
case 0x0c06c9d2u: goto P_0c06c9d2;
case 0x0c06c9d4u: goto P_0c06c9d4;
case 0x0c06c9d6u: goto P_0c06c9d6;
case 0x0c06c9d8u: goto P_0c06c9d8;
case 0x0c06c9dau: goto P_0c06c9da;
case 0x0c06c9dcu: goto P_0c06c9dc;
case 0x0c06c9deu: goto P_0c06c9de;
case 0x0c06c9e0u: goto P_0c06c9e0;
case 0x0c06c9e2u: goto P_0c06c9e2;
case 0x0c06c9e4u: goto P_0c06c9e4;
case 0x0c06c9e6u: goto P_0c06c9e6;
case 0x0c06c9e8u: goto P_0c06c9e8;
case 0x0c06c9eau: goto P_0c06c9ea;
case 0x0c06c9ecu: goto P_0c06c9ec;
case 0x0c06c9eeu: goto P_0c06c9ee;
case 0x0c06c9f0u: goto P_0c06c9f0;
case 0x0c06c9f2u: goto P_0c06c9f2;
case 0x0c06c9f4u: goto P_0c06c9f4;
case 0x0c06c9f6u: goto P_0c06c9f6;
case 0x0c06ca30u: goto P_0c06ca30;
case 0x0c06ca32u: goto P_0c06ca32;
case 0x0c06ca34u: goto P_0c06ca34;
case 0x0c06ca36u: goto P_0c06ca36;
case 0x0c06ca38u: goto P_0c06ca38;
case 0x0c06ca3au: goto P_0c06ca3a;
case 0x0c06ca3cu: goto P_0c06ca3c;
case 0x0c06ca3eu: goto P_0c06ca3e;
case 0x0c06ca40u: goto P_0c06ca40;
case 0x0c06ca42u: goto P_0c06ca42;
case 0x0c06ca44u: goto P_0c06ca44;
case 0x0c06ca46u: goto P_0c06ca46;
case 0x0c06ca48u: goto P_0c06ca48;
case 0x0c06ca4au: goto P_0c06ca4a;
case 0x0c06ca4cu: goto P_0c06ca4c;
case 0x0c06ca4eu: goto P_0c06ca4e;
case 0x0c06ca50u: goto P_0c06ca50;
case 0x0c06ca52u: goto P_0c06ca52;
case 0x0c06ca54u: goto P_0c06ca54;
case 0x0c06ca56u: goto P_0c06ca56;
case 0x0c06ca58u: goto P_0c06ca58;
case 0x0c06ca5au: goto P_0c06ca5a;
case 0x0c06ca5cu: goto P_0c06ca5c;
case 0x0c06ca5eu: goto P_0c06ca5e;
case 0x0c06ca60u: goto P_0c06ca60;
case 0x0c06ca62u: goto P_0c06ca62;
case 0x0c06ca64u: goto P_0c06ca64;
case 0x0c06ca66u: goto P_0c06ca66;
case 0x0c06ca68u: goto P_0c06ca68;
case 0x0c06ca6au: goto P_0c06ca6a;
case 0x0c06ca6cu: goto P_0c06ca6c;
case 0x0c06ca6eu: goto P_0c06ca6e;
case 0x0c06ca70u: goto P_0c06ca70;
case 0x0c06ca72u: goto P_0c06ca72;
case 0x0c06ca74u: goto P_0c06ca74;
case 0x0c06ca76u: goto P_0c06ca76;
case 0x0c06ca78u: goto P_0c06ca78;
case 0x0c06ca7au: goto P_0c06ca7a;
case 0x0c06ca7cu: goto P_0c06ca7c;
case 0x0c06ca7eu: goto P_0c06ca7e;
case 0x0c06ca80u: goto P_0c06ca80;
case 0x0c06ca82u: goto P_0c06ca82;
case 0x0c06ca84u: goto P_0c06ca84;
case 0x0c06ca86u: goto P_0c06ca86;
case 0x0c06ca88u: goto P_0c06ca88;
case 0x0c06ca8au: goto P_0c06ca8a;
case 0x0c06ca8cu: goto P_0c06ca8c;
case 0x0c06ca8eu: goto P_0c06ca8e;
case 0x0c06ca90u: goto P_0c06ca90;
case 0x0c06ca92u: goto P_0c06ca92;
case 0x0c06ca94u: goto P_0c06ca94;
case 0x0c06ca96u: goto P_0c06ca96;
case 0x0c06ca98u: goto P_0c06ca98;
case 0x0c06ca9au: goto P_0c06ca9a;
case 0x0c06ca9cu: goto P_0c06ca9c;
case 0x0c06ca9eu: goto P_0c06ca9e;
case 0x0c06caa0u: goto P_0c06caa0;
case 0x0c06caa2u: goto P_0c06caa2;
case 0x0c06caa4u: goto P_0c06caa4;
case 0x0c06caa6u: goto P_0c06caa6;
case 0x0c06caa8u: goto P_0c06caa8;
case 0x0c06caaau: goto P_0c06caaa;
case 0x0c06caacu: goto P_0c06caac;
case 0x0c06caaeu: goto P_0c06caae;
case 0x0c06cab0u: goto P_0c06cab0;
case 0x0c06cab2u: goto P_0c06cab2;
case 0x0c06cab4u: goto P_0c06cab4;
case 0x0c06cab6u: goto P_0c06cab6;
case 0x0c06cab8u: goto P_0c06cab8;
case 0x0c06cabau: goto P_0c06caba;
case 0x0c06cabcu: goto P_0c06cabc;
case 0x0c06cabeu: goto P_0c06cabe;
case 0x0c06cac0u: goto P_0c06cac0;
case 0x0c06cac2u: goto P_0c06cac2;
case 0x0c06cac4u: goto P_0c06cac4;
case 0x0c06cac6u: goto P_0c06cac6;
case 0x0c06cac8u: goto P_0c06cac8;
case 0x0c06cacau: goto P_0c06caca;
case 0x0c06caccu: goto P_0c06cacc;
case 0x0c06caceu: goto P_0c06cace;
case 0x0c06cad0u: goto P_0c06cad0;
case 0x0c06cad2u: goto P_0c06cad2;
case 0x0c06cad4u: goto P_0c06cad4;
case 0x0c06cad6u: goto P_0c06cad6;
case 0x0c06cad8u: goto P_0c06cad8;
case 0x0c06cadau: goto P_0c06cada;
case 0x0c06cadcu: goto P_0c06cadc;
case 0x0c06cadeu: goto P_0c06cade;
case 0x0c06cae0u: goto P_0c06cae0;
case 0x0c06cae2u: goto P_0c06cae2;
case 0x0c06cae4u: goto P_0c06cae4;
case 0x0c06cae6u: goto P_0c06cae6;
case 0x0c06cae8u: goto P_0c06cae8;
case 0x0c06caeau: goto P_0c06caea;
case 0x0c06caecu: goto P_0c06caec;
case 0x0c06caeeu: goto P_0c06caee;
case 0x0c06caf0u: goto P_0c06caf0;
case 0x0c06caf2u: goto P_0c06caf2;
case 0x0c06caf4u: goto P_0c06caf4;
case 0x0c06caf6u: goto P_0c06caf6;
case 0x0c06caf8u: goto P_0c06caf8;
case 0x0c06cafau: goto P_0c06cafa;
case 0x0c06cafcu: goto P_0c06cafc;
case 0x0c06cafeu: goto P_0c06cafe;
case 0x0c06cb00u: goto P_0c06cb00;
case 0x0c06cb02u: goto P_0c06cb02;
case 0x0c06cb04u: goto P_0c06cb04;
case 0x0c06cb06u: goto P_0c06cb06;
case 0x0c06cb08u: goto P_0c06cb08;
case 0x0c06cb0au: goto P_0c06cb0a;
case 0x0c06cb0cu: goto P_0c06cb0c;
case 0x0c06cb0eu: goto P_0c06cb0e;
case 0x0c06cb10u: goto P_0c06cb10;
case 0x0c06cb12u: goto P_0c06cb12;
case 0x0c06cb14u: goto P_0c06cb14;
case 0x0c06cb16u: goto P_0c06cb16;
case 0x0c06cb18u: goto P_0c06cb18;
case 0x0c06cb1au: goto P_0c06cb1a;
case 0x0c06cb1cu: goto P_0c06cb1c;
case 0x0c06cb1eu: goto P_0c06cb1e;
case 0x0c06cb20u: goto P_0c06cb20;
case 0x0c06cb22u: goto P_0c06cb22;
case 0x0c06cb24u: goto P_0c06cb24;
case 0x0c06cb26u: goto P_0c06cb26;
case 0x0c06cb28u: goto P_0c06cb28;
case 0x0c06cb2au: goto P_0c06cb2a;
case 0x0c06cb2cu: goto P_0c06cb2c;
case 0x0c06cb2eu: goto P_0c06cb2e;
case 0x0c06cb30u: goto P_0c06cb30;
case 0x0c06cb32u: goto P_0c06cb32;
case 0x0c06cb34u: goto P_0c06cb34;
case 0x0c06cb36u: goto P_0c06cb36;
case 0x0c06cb38u: goto P_0c06cb38;
case 0x0c06cb60u: goto P_0c06cb60;
case 0x0c06cb62u: goto P_0c06cb62;
case 0x0c06cb64u: goto P_0c06cb64;
case 0x0c06cb66u: goto P_0c06cb66;
case 0x0c06cb68u: goto P_0c06cb68;
case 0x0c06cb6au: goto P_0c06cb6a;
case 0x0c06cb6cu: goto P_0c06cb6c;
case 0x0c06cb6eu: goto P_0c06cb6e;
case 0x0c06cb70u: goto P_0c06cb70;
case 0x0c06cb72u: goto P_0c06cb72;
case 0x0c06cb74u: goto P_0c06cb74;
case 0x0c06cb76u: goto P_0c06cb76;
case 0x0c06cb78u: goto P_0c06cb78;
case 0x0c06cb7au: goto P_0c06cb7a;
case 0x0c06cb7cu: goto P_0c06cb7c;
case 0x0c06cb7eu: goto P_0c06cb7e;
case 0x0c06cb80u: goto P_0c06cb80;
case 0x0c06cb82u: goto P_0c06cb82;
case 0x0c06cb84u: goto P_0c06cb84;
case 0x0c06cb86u: goto P_0c06cb86;
case 0x0c06cb88u: goto P_0c06cb88;
case 0x0c06cb8au: goto P_0c06cb8a;
case 0x0c06cb8cu: goto P_0c06cb8c;
case 0x0c06cb8eu: goto P_0c06cb8e;
case 0x0c06cb90u: goto P_0c06cb90;
case 0x0c06cb92u: goto P_0c06cb92;
case 0x0c06cb94u: goto P_0c06cb94;
case 0x0c06cb96u: goto P_0c06cb96;
case 0x0c06cb98u: goto P_0c06cb98;
case 0x0c06cb9au: goto P_0c06cb9a;
case 0x0c06cb9cu: goto P_0c06cb9c;
case 0x0c06cb9eu: goto P_0c06cb9e;
case 0x0c06cba0u: goto P_0c06cba0;
case 0x0c06cba2u: goto P_0c06cba2;
case 0x0c06cba4u: goto P_0c06cba4;
case 0x0c06cba6u: goto P_0c06cba6;
case 0x0c06cba8u: goto P_0c06cba8;
case 0x0c06cbaau: goto P_0c06cbaa;
case 0x0c06cbacu: goto P_0c06cbac;
case 0x0c06cbaeu: goto P_0c06cbae;
case 0x0c06cbb0u: goto P_0c06cbb0;
case 0x0c06cbb2u: goto P_0c06cbb2;
case 0x0c06cbb4u: goto P_0c06cbb4;
case 0x0c06cbb6u: goto P_0c06cbb6;
case 0x0c06cbb8u: goto P_0c06cbb8;
case 0x0c06cbbau: goto P_0c06cbba;
case 0x0c06cbbcu: goto P_0c06cbbc;
case 0x0c06cbbeu: goto P_0c06cbbe;
case 0x0c06cbc0u: goto P_0c06cbc0;
case 0x0c06cbc2u: goto P_0c06cbc2;
case 0x0c06cbc4u: goto P_0c06cbc4;
case 0x0c06cbc6u: goto P_0c06cbc6;
case 0x0c06cbc8u: goto P_0c06cbc8;
case 0x0c06cbcau: goto P_0c06cbca;
case 0x0c06cbccu: goto P_0c06cbcc;
case 0x0c06cbceu: goto P_0c06cbce;
case 0x0c06cbd0u: goto P_0c06cbd0;
case 0x0c06cbd2u: goto P_0c06cbd2;
case 0x0c06cbd4u: goto P_0c06cbd4;
case 0x0c06cbd6u: goto P_0c06cbd6;
case 0x0c06cbd8u: goto P_0c06cbd8;
case 0x0c06cbdau: goto P_0c06cbda;
case 0x0c06cbdcu: goto P_0c06cbdc;
case 0x0c06cbdeu: goto P_0c06cbde;
case 0x0c06cbe0u: goto P_0c06cbe0;
case 0x0c06cbe2u: goto P_0c06cbe2;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06c95e: /* original 2fe6, guest PC 0x0c06c95e */
if(!s->budget--) { s->failed_pc=0x0c06c95eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c960;
P_0c06c960: /* original ee27, guest PC 0x0c06c960 */
if(!s->budget--) { s->failed_pc=0x0c06c960u; return 0; }
r[14]=0x00000027u;
goto P_0c06c962;
P_0c06c962: /* original 2fd6, guest PC 0x0c06c962 */
if(!s->budget--) { s->failed_pc=0x0c06c962u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c964;
P_0c06c964: /* original 60e3, guest PC 0x0c06c964 */
if(!s->budget--) { s->failed_pc=0x0c06c964u; return 0; }
r[0]=r[14];
goto P_0c06c966;
P_0c06c966: /* original 2fc6, guest PC 0x0c06c966 */
if(!s->budget--) { s->failed_pc=0x0c06c966u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c968;
P_0c06c968: /* original 706b, guest PC 0x0c06c968 */
if(!s->budget--) { s->failed_pc=0x0c06c968u; return 0; }
r[0]+=0x0000006bu;
goto P_0c06c96a;
P_0c06c96a: /* original 2fb6, guest PC 0x0c06c96a */
if(!s->budget--) { s->failed_pc=0x0c06c96au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c96c;
P_0c06c96c: /* original 2fa6, guest PC 0x0c06c96c */
if(!s->budget--) { s->failed_pc=0x0c06c96cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c96e;
P_0c06c96e: /* original 2f96, guest PC 0x0c06c96e */
if(!s->budget--) { s->failed_pc=0x0c06c96eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c970;
P_0c06c970: /* original 4f22, guest PC 0x0c06c970 */
if(!s->budget--) { s->failed_pc=0x0c06c970u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c972;
P_0c06c972: /* original d327, guest PC 0x0c06c972 */
if(!s->budget--) { s->failed_pc=0x0c06c972u; return 0; }
r[3]=read(ram,0x0c06ca10u,4);
goto P_0c06c974;
P_0c06c974: /* original 7ffc, guest PC 0x0c06c974 */
if(!s->budget--) { s->failed_pc=0x0c06c974u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c976;
P_0c06c976: /* original 2f32, guest PC 0x0c06c976 */
if(!s->budget--) { s->failed_pc=0x0c06c976u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c978;
P_0c06c978: /* original dd28, guest PC 0x0c06c978 */
if(!s->budget--) { s->failed_pc=0x0c06c978u; return 0; }
r[13]=read(ram,0x0c06ca1cu,4);
goto P_0c06c97a;
P_0c06c97a: /* original d327, guest PC 0x0c06c97a */
if(!s->budget--) { s->failed_pc=0x0c06c97au; return 0; }
r[3]=read(ram,0x0c06ca18u,4);
goto P_0c06c97c;
P_0c06c97c: /* original 04dc, guest PC 0x0c06c97c */
if(!s->budget--) { s->failed_pc=0x0c06c97cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c06c97e;
P_0c06c97e: /* original 6632, guest PC 0x0c06c97e */
if(!s->budget--) { s->failed_pc=0x0c06c97eu; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c06c980;
P_0c06c980: /* original 6043, guest PC 0x0c06c980 */
if(!s->budget--) { s->failed_pc=0x0c06c980u; return 0; }
r[0]=r[4];
goto P_0c06c982;
P_0c06c982: /* original dc24, guest PC 0x0c06c982 */
if(!s->budget--) { s->failed_pc=0x0c06c982u; return 0; }
r[12]=read(ram,0x0c06ca14u,4);
goto P_0c06c984;
P_0c06c984: /* original 8801, guest PC 0x0c06c984 */
if(!s->budget--) { s->failed_pc=0x0c06c984u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c986;
P_0c06c986: /* original 7601, guest PC 0x0c06c986 */
if(!s->budget--) { s->failed_pc=0x0c06c986u; return 0; }
r[6]+=0x00000001u;
goto P_0c06c988;
P_0c06c988: /* original 8d01, guest PC 0x0c06c988 */
if(!s->budget--) { s->failed_pc=0x0c06c988u; return 0; }
cond=r[17]&1u;
r[5]=0x00000004u;
if(cond) { goto P_0c06c98e; }
goto P_0c06c98c;
P_0c06c98a: /* original e504, guest PC 0x0c06c98a */
if(!s->budget--) { s->failed_pc=0x0c06c98au; return 0; }
r[5]=0x00000004u;
goto P_0c06c98c;
P_0c06c98c: /* original 6e53, guest PC 0x0c06c98c */
if(!s->budget--) { s->failed_pc=0x0c06c98cu; return 0; }
r[14]=r[5];
goto P_0c06c98e;
P_0c06c98e: /* original 54d2, guest PC 0x0c06c98e */
if(!s->budget--) { s->failed_pc=0x0c06c98eu; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c06c990;
P_0c06c990: /* original 6b63, guest PC 0x0c06c990 */
if(!s->budget--) { s->failed_pc=0x0c06c990u; return 0; }
r[11]=r[6];
goto P_0c06c992;
P_0c06c992: /* original e307, guest PC 0x0c06c992 */
if(!s->budget--) { s->failed_pc=0x0c06c992u; return 0; }
r[3]=0x00000007u;
goto P_0c06c994;
P_0c06c994: /* original 6ae3, guest PC 0x0c06c994 */
if(!s->budget--) { s->failed_pc=0x0c06c994u; return 0; }
r[10]=r[14];
goto P_0c06c996;
P_0c06c996: /* original 4a00, guest PC 0x0c06c996 */
if(!s->budget--) { s->failed_pc=0x0c06c996u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c06c998;
P_0c06c998: /* original 2458, guest PC 0x0c06c998 */
if(!s->budget--) { s->failed_pc=0x0c06c998u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[5])==0)!=0);
goto P_0c06c99a;
P_0c06c99a: /* original 4b3d, guest PC 0x0c06c99a */
if(!s->budget--) { s->failed_pc=0x0c06c99au; return 0; }
r[11]=(r[3]&0x80000000u)?((r[3]&31u)?r[11]>>((-r[3])&31u):0):r[11]<<(r[3]&31u);
goto P_0c06c99c;
P_0c06c99c: /* original 8d13, guest PC 0x0c06c99c */
if(!s->budget--) { s->failed_pc=0x0c06c99cu; return 0; }
cond=r[17]&1u;
r[10]|=r[11];
if(cond) { goto P_0c06c9c6; }
goto P_0c06c9a0;
P_0c06c99e: /* original 2abb, guest PC 0x0c06c99e */
if(!s->budget--) { s->failed_pc=0x0c06c99eu; return 0; }
r[10]|=r[11];
goto P_0c06c9a0;
P_0c06c9a0: /* original bcfa, guest PC 0x0c06c9a0 */
if(!s->budget--) { s->failed_pc=0x0c06c9a0u; return 0; }
target=code_base|0x0c06c398u; r[16]=code_base|0x0c06c9a4u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c9a4u) { target=s->pc; goto dispatch; }
goto P_0c06c9a4;
P_0c06c9a2: /* original 64a3, guest PC 0x0c06c9a2 */
if(!s->budget--) { s->failed_pc=0x0c06c9a2u; return 0; }
r[4]=r[10];
goto P_0c06c9a4;
P_0c06c9a4: /* original 2008, guest PC 0x0c06c9a4 */
if(!s->budget--) { s->failed_pc=0x0c06c9a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06c9a6;
P_0c06c9a6: /* original 8b01, guest PC 0x0c06c9a6 */
if(!s->budget--) { s->failed_pc=0x0c06c9a6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c9ac; }
goto P_0c06c9a8;
P_0c06c9a8: /* original a094, guest PC 0x0c06c9a8 */
if(!s->budget--) { s->failed_pc=0x0c06c9a8u; return 0; }
goto P_0c06cad4;
P_0c06c9aa: /* original 0009, guest PC 0x0c06c9aa */
if(!s->budget--) { s->failed_pc=0x0c06c9aau; return 0; }
goto P_0c06c9ac;
P_0c06c9ac: /* original 7f04, guest PC 0x0c06c9ac */
if(!s->budget--) { s->failed_pc=0x0c06c9acu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c9ae;
P_0c06c9ae: /* original 64a3, guest PC 0x0c06c9ae */
if(!s->budget--) { s->failed_pc=0x0c06c9aeu; return 0; }
r[4]=r[10];
goto P_0c06c9b0;
P_0c06c9b0: /* original 4f26, guest PC 0x0c06c9b0 */
if(!s->budget--) { s->failed_pc=0x0c06c9b0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c9b2;
P_0c06c9b2: /* original d216, guest PC 0x0c06c9b2 */
if(!s->budget--) { s->failed_pc=0x0c06c9b2u; return 0; }
r[2]=read(ram,0x0c06ca0cu,4);
goto P_0c06c9b4;
P_0c06c9b4: /* original e601, guest PC 0x0c06c9b4 */
if(!s->budget--) { s->failed_pc=0x0c06c9b4u; return 0; }
r[6]=0x00000001u;
goto P_0c06c9b6;
P_0c06c9b6: /* original d51a, guest PC 0x0c06c9b6 */
if(!s->budget--) { s->failed_pc=0x0c06c9b6u; return 0; }
r[5]=read(ram,0x0c06ca20u,4);
goto P_0c06c9b8;
P_0c06c9b8: /* original 69f6, guest PC 0x0c06c9b8 */
if(!s->budget--) { s->failed_pc=0x0c06c9b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06c9ba;
P_0c06c9ba: /* original 6af6, guest PC 0x0c06c9ba */
if(!s->budget--) { s->failed_pc=0x0c06c9bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06c9bc;
P_0c06c9bc: /* original 6bf6, guest PC 0x0c06c9bc */
if(!s->budget--) { s->failed_pc=0x0c06c9bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06c9be;
P_0c06c9be: /* original 6cf6, guest PC 0x0c06c9be */
if(!s->budget--) { s->failed_pc=0x0c06c9beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06c9c0;
P_0c06c9c0: /* original 6df6, guest PC 0x0c06c9c0 */
if(!s->budget--) { s->failed_pc=0x0c06c9c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06c9c2;
P_0c06c9c2: /* original 422b, guest PC 0x0c06c9c2 */
if(!s->budget--) { s->failed_pc=0x0c06c9c2u; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c06c9c4: /* original 6ef6, guest PC 0x0c06c9c4 */
if(!s->budget--) { s->failed_pc=0x0c06c9c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c9c6;
P_0c06c9c6: /* original d317, guest PC 0x0c06c9c6 */
if(!s->budget--) { s->failed_pc=0x0c06c9c6u; return 0; }
r[3]=read(ram,0x0c06ca24u,4);
goto P_0c06c9c8;
P_0c06c9c8: /* original 64f2, guest PC 0x0c06c9c8 */
if(!s->budget--) { s->failed_pc=0x0c06c9c8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06c9ca;
P_0c06c9ca: /* original 430b, guest PC 0x0c06c9ca */
if(!s->budget--) { s->failed_pc=0x0c06c9cau; return 0; }
target=r[3];
r[16]=code_base|0x0c06c9ceu;
r[4]+=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c9ceu) { target=s->pc; goto dispatch; }
goto P_0c06c9ce;
P_0c06c9cc: /* original 7412, guest PC 0x0c06c9cc */
if(!s->budget--) { s->failed_pc=0x0c06c9ccu; return 0; }
r[4]+=0x00000012u;
goto P_0c06c9ce;
P_0c06c9ce: /* original 9015, guest PC 0x0c06c9ce */
if(!s->budget--) { s->failed_pc=0x0c06c9ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c9fcu,2);
goto P_0c06c9d0;
P_0c06c9d0: /* original e706, guest PC 0x0c06c9d0 */
if(!s->budget--) { s->failed_pc=0x0c06c9d0u; return 0; }
r[7]=0x00000006u;
goto P_0c06c9d2;
P_0c06c9d2: /* original 0dde, guest PC 0x0c06c9d2 */
if(!s->budget--) { s->failed_pc=0x0c06c9d2u; return 0; }
r[13]=read(ram,r[13]+r[0],4);
goto P_0c06c9d4;
P_0c06c9d4: /* original 60d3, guest PC 0x0c06c9d4 */
if(!s->budget--) { s->failed_pc=0x0c06c9d4u; return 0; }
r[0]=r[13];
goto P_0c06c9d6;
P_0c06c9d6: /* original 4001, guest PC 0x0c06c9d6 */
if(!s->budget--) { s->failed_pc=0x0c06c9d6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c06c9d8;
P_0c06c9d8: /* original 66d3, guest PC 0x0c06c9d8 */
if(!s->budget--) { s->failed_pc=0x0c06c9d8u; return 0; }
r[6]=r[13];
goto P_0c06c9da;
P_0c06c9da: /* original 2709, guest PC 0x0c06c9da */
if(!s->budget--) { s->failed_pc=0x0c06c9dau; return 0; }
r[7]&=r[0];
goto P_0c06c9dc;
P_0c06c9dc: /* original d012, guest PC 0x0c06c9dc */
if(!s->budget--) { s->failed_pc=0x0c06c9dcu; return 0; }
r[0]=read(ram,0x0c06ca28u,4);
goto P_0c06c9de;
P_0c06c9de: /* original 4609, guest PC 0x0c06c9de */
if(!s->budget--) { s->failed_pc=0x0c06c9deu; return 0; }
r[6]>>=2;
goto P_0c06c9e0;
P_0c06c9e0: /* original 4600, guest PC 0x0c06c9e0 */
if(!s->budget--) { s->failed_pc=0x0c06c9e0u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c06c9e2;
P_0c06c9e2: /* original 046d, guest PC 0x0c06c9e2 */
if(!s->budget--) { s->failed_pc=0x0c06c9e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c06c9e4;
P_0c06c9e4: /* original 2778, guest PC 0x0c06c9e4 */
if(!s->budget--) { s->failed_pc=0x0c06c9e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c06c9e6;
P_0c06c9e6: /* original 8d23, guest PC 0x0c06c9e6 */
if(!s->budget--) { s->failed_pc=0x0c06c9e6u; return 0; }
cond=r[17]&1u;
r[5]=0x00000020u;
if(cond) { goto P_0c06ca30; }
goto P_0c06c9ea;
P_0c06c9e8: /* original e520, guest PC 0x0c06c9e8 */
if(!s->budget--) { s->failed_pc=0x0c06c9e8u; return 0; }
r[5]=0x00000020u;
goto P_0c06c9ea;
P_0c06c9ea: /* original d010, guest PC 0x0c06c9ea */
if(!s->budget--) { s->failed_pc=0x0c06c9eau; return 0; }
r[0]=read(ram,0x0c06ca2cu,4);
goto P_0c06c9ec;
P_0c06c9ec: /* original 3d52, guest PC 0x0c06c9ec */
if(!s->budget--) { s->failed_pc=0x0c06c9ecu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[5])!=0);
goto P_0c06c9ee;
P_0c06c9ee: /* original 8f61, guest PC 0x0c06c9ee */
if(!s->budget--) { s->failed_pc=0x0c06c9eeu; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
if(!cond) { goto P_0c06cab4; }
goto P_0c06c9f2;
P_0c06c9f0: /* original 046d, guest PC 0x0c06c9f0 */
if(!s->budget--) { s->failed_pc=0x0c06c9f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c06c9f2;
P_0c06c9f2: /* original 9904, guest PC 0x0c06c9f2 */
if(!s->budget--) { s->failed_pc=0x0c06c9f2u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c9feu,2);
goto P_0c06c9f4;
P_0c06c9f4: /* original a05f, guest PC 0x0c06c9f4 */
if(!s->budget--) { s->failed_pc=0x0c06c9f4u; return 0; }
goto P_0c06cab6;
P_0c06c9f6: /* original 0009, guest PC 0x0c06c9f6 */
if(!s->budget--) { s->failed_pc=0x0c06c9f6u; return 0; }
if(!vf3_matrix_family(0x0c06c9f8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06c9f8u; return 0; } return 1;
P_0c06ca30: /* original 3d52, guest PC 0x0c06ca30 */
if(!s->budget--) { s->failed_pc=0x0c06ca30u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[5])!=0);
goto P_0c06ca32;
P_0c06ca32: /* original 8b3f, guest PC 0x0c06ca32 */
if(!s->budget--) { s->failed_pc=0x0c06ca32u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06cab4; }
goto P_0c06ca34;
P_0c06ca34: /* original e228, guest PC 0x0c06ca34 */
if(!s->budget--) { s->failed_pc=0x0c06ca34u; return 0; }
r[2]=0x00000028u;
goto P_0c06ca36;
P_0c06ca36: /* original 9980, guest PC 0x0c06ca36 */
if(!s->budget--) { s->failed_pc=0x0c06ca36u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cb3au,2);
goto P_0c06ca38;
P_0c06ca38: /* original 3d26, guest PC 0x0c06ca38 */
if(!s->budget--) { s->failed_pc=0x0c06ca38u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>r[2])!=0);
goto P_0c06ca3a;
P_0c06ca3a: /* original 8b3c, guest PC 0x0c06ca3a */
if(!s->budget--) { s->failed_pc=0x0c06ca3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06cab6; }
goto P_0c06ca3c;
P_0c06ca3c: /* original e35a, guest PC 0x0c06ca3c */
if(!s->budget--) { s->failed_pc=0x0c06ca3cu; return 0; }
r[3]=0x0000005au;
goto P_0c06ca3e;
P_0c06ca3e: /* original 3d36, guest PC 0x0c06ca3e */
if(!s->budget--) { s->failed_pc=0x0c06ca3eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>r[3])!=0);
goto P_0c06ca40;
P_0c06ca40: /* original 8b39, guest PC 0x0c06ca40 */
if(!s->budget--) { s->failed_pc=0x0c06ca40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06cab6; }
goto P_0c06ca42;
P_0c06ca42: /* original e464, guest PC 0x0c06ca42 */
if(!s->budget--) { s->failed_pc=0x0c06ca42u; return 0; }
r[4]=0x00000064u;
goto P_0c06ca44;
P_0c06ca44: /* original 997a, guest PC 0x0c06ca44 */
if(!s->budget--) { s->failed_pc=0x0c06ca44u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cb3cu,2);
goto P_0c06ca46;
P_0c06ca46: /* original 3d42, guest PC 0x0c06ca46 */
if(!s->budget--) { s->failed_pc=0x0c06ca46u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[4])!=0);
goto P_0c06ca48;
P_0c06ca48: /* original 8935, guest PC 0x0c06ca48 */
if(!s->budget--) { s->failed_pc=0x0c06ca48u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cab6; }
goto P_0c06ca4a;
P_0c06ca4a: /* original 2f42, guest PC 0x0c06ca4a */
if(!s->budget--) { s->failed_pc=0x0c06ca4au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06ca4c;
P_0c06ca4c: /* original bca4, guest PC 0x0c06ca4c */
if(!s->budget--) { s->failed_pc=0x0c06ca4cu; return 0; }
target=code_base|0x0c06c398u; r[16]=code_base|0x0c06ca50u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ca50u) { target=s->pc; goto dispatch; }
goto P_0c06ca50;
P_0c06ca4e: /* original 64a3, guest PC 0x0c06ca4e */
if(!s->budget--) { s->failed_pc=0x0c06ca4eu; return 0; }
r[4]=r[10];
goto P_0c06ca50;
P_0c06ca50: /* original 2008, guest PC 0x0c06ca50 */
if(!s->budget--) { s->failed_pc=0x0c06ca50u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06ca52;
P_0c06ca52: /* original 893f, guest PC 0x0c06ca52 */
if(!s->budget--) { s->failed_pc=0x0c06ca52u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cad4; }
goto P_0c06ca54;
P_0c06ca54: /* original 64e3, guest PC 0x0c06ca54 */
if(!s->budget--) { s->failed_pc=0x0c06ca54u; return 0; }
r[4]=r[14];
goto P_0c06ca56;
P_0c06ca56: /* original e300, guest PC 0x0c06ca56 */
if(!s->budget--) { s->failed_pc=0x0c06ca56u; return 0; }
r[3]=0x00000000u;
goto P_0c06ca58;
P_0c06ca58: /* original 4400, guest PC 0x0c06ca58 */
if(!s->budget--) { s->failed_pc=0x0c06ca58u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06ca5a;
P_0c06ca5a: /* original 2f36, guest PC 0x0c06ca5a */
if(!s->budget--) { s->failed_pc=0x0c06ca5au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ca5c;
P_0c06ca5c: /* original 956f, guest PC 0x0c06ca5c */
if(!s->budget--) { s->failed_pc=0x0c06ca5cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cb3eu,2);
goto P_0c06ca5e;
P_0c06ca5e: /* original 24bb, guest PC 0x0c06ca5e */
if(!s->budget--) { s->failed_pc=0x0c06ca5eu; return 0; }
r[4]|=r[11];
goto P_0c06ca60;
P_0c06ca60: /* original d239, guest PC 0x0c06ca60 */
if(!s->budget--) { s->failed_pc=0x0c06ca60u; return 0; }
r[2]=read(ram,0x0c06cb48u,4);
goto P_0c06ca62;
P_0c06ca62: /* original 6733, guest PC 0x0c06ca62 */
if(!s->budget--) { s->failed_pc=0x0c06ca62u; return 0; }
r[7]=r[3];
goto P_0c06ca64;
P_0c06ca64: /* original 420b, guest PC 0x0c06ca64 */
if(!s->budget--) { s->failed_pc=0x0c06ca64u; return 0; }
target=r[2];
r[16]=code_base|0x0c06ca68u;
r[6]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ca68u) { target=s->pc; goto dispatch; }
goto P_0c06ca68;
P_0c06ca66: /* original 66c3, guest PC 0x0c06ca66 */
if(!s->budget--) { s->failed_pc=0x0c06ca66u; return 0; }
r[6]=r[12];
goto P_0c06ca68;
P_0c06ca68: /* original 7efd, guest PC 0x0c06ca68 */
if(!s->budget--) { s->failed_pc=0x0c06ca68u; return 0; }
r[14]+=0xfffffffdu;
goto P_0c06ca6a;
P_0c06ca6a: /* original 9969, guest PC 0x0c06ca6a */
if(!s->budget--) { s->failed_pc=0x0c06ca6au; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cb40u,2);
goto P_0c06ca6c;
P_0c06ca6c: /* original 65e3, guest PC 0x0c06ca6c */
if(!s->budget--) { s->failed_pc=0x0c06ca6cu; return 0; }
r[5]=r[14];
goto P_0c06ca6e;
P_0c06ca6e: /* original 4500, guest PC 0x0c06ca6e */
if(!s->budget--) { s->failed_pc=0x0c06ca6eu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06ca70;
P_0c06ca70: /* original da36, guest PC 0x0c06ca70 */
if(!s->budget--) { s->failed_pc=0x0c06ca70u; return 0; }
r[10]=read(ram,0x0c06cb4cu,4);
goto P_0c06ca72;
P_0c06ca72: /* original 6793, guest PC 0x0c06ca72 */
if(!s->budget--) { s->failed_pc=0x0c06ca72u; return 0; }
r[7]=r[9];
goto P_0c06ca74;
P_0c06ca74: /* original e601, guest PC 0x0c06ca74 */
if(!s->budget--) { s->failed_pc=0x0c06ca74u; return 0; }
r[6]=0x00000001u;
goto P_0c06ca76;
P_0c06ca76: /* original 7f04, guest PC 0x0c06ca76 */
if(!s->budget--) { s->failed_pc=0x0c06ca76u; return 0; }
r[15]+=0x00000004u;
goto P_0c06ca78;
P_0c06ca78: /* original 25bb, guest PC 0x0c06ca78 */
if(!s->budget--) { s->failed_pc=0x0c06ca78u; return 0; }
r[5]|=r[11];
goto P_0c06ca7a;
P_0c06ca7a: /* original 4a0b, guest PC 0x0c06ca7a */
if(!s->budget--) { s->failed_pc=0x0c06ca7au; return 0; }
target=r[10];
r[16]=code_base|0x0c06ca7eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ca7eu) { target=s->pc; goto dispatch; }
goto P_0c06ca7e;
P_0c06ca7c: /* original 64c3, guest PC 0x0c06ca7c */
if(!s->budget--) { s->failed_pc=0x0c06ca7cu; return 0; }
r[4]=r[12];
goto P_0c06ca7e;
P_0c06ca7e: /* original 65e3, guest PC 0x0c06ca7e */
if(!s->budget--) { s->failed_pc=0x0c06ca7eu; return 0; }
r[5]=r[14];
goto P_0c06ca80;
P_0c06ca80: /* original 7502, guest PC 0x0c06ca80 */
if(!s->budget--) { s->failed_pc=0x0c06ca80u; return 0; }
r[5]+=0x00000002u;
goto P_0c06ca82;
P_0c06ca82: /* original 4500, guest PC 0x0c06ca82 */
if(!s->budget--) { s->failed_pc=0x0c06ca82u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06ca84;
P_0c06ca84: /* original 6793, guest PC 0x0c06ca84 */
if(!s->budget--) { s->failed_pc=0x0c06ca84u; return 0; }
r[7]=r[9];
goto P_0c06ca86;
P_0c06ca86: /* original e600, guest PC 0x0c06ca86 */
if(!s->budget--) { s->failed_pc=0x0c06ca86u; return 0; }
r[6]=0x00000000u;
goto P_0c06ca88;
P_0c06ca88: /* original 25bb, guest PC 0x0c06ca88 */
if(!s->budget--) { s->failed_pc=0x0c06ca88u; return 0; }
r[5]|=r[11];
goto P_0c06ca8a;
P_0c06ca8a: /* original 4a0b, guest PC 0x0c06ca8a */
if(!s->budget--) { s->failed_pc=0x0c06ca8au; return 0; }
target=r[10];
r[16]=code_base|0x0c06ca8eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ca8eu) { target=s->pc; goto dispatch; }
goto P_0c06ca8e;
P_0c06ca8c: /* original 64c3, guest PC 0x0c06ca8c */
if(!s->budget--) { s->failed_pc=0x0c06ca8cu; return 0; }
r[4]=r[12];
goto P_0c06ca8e;
P_0c06ca8e: /* original 65e3, guest PC 0x0c06ca8e */
if(!s->budget--) { s->failed_pc=0x0c06ca8eu; return 0; }
r[5]=r[14];
goto P_0c06ca90;
P_0c06ca90: /* original 7504, guest PC 0x0c06ca90 */
if(!s->budget--) { s->failed_pc=0x0c06ca90u; return 0; }
r[5]+=0x00000004u;
goto P_0c06ca92;
P_0c06ca92: /* original 4500, guest PC 0x0c06ca92 */
if(!s->budget--) { s->failed_pc=0x0c06ca92u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06ca94;
P_0c06ca94: /* original 6793, guest PC 0x0c06ca94 */
if(!s->budget--) { s->failed_pc=0x0c06ca94u; return 0; }
r[7]=r[9];
goto P_0c06ca96;
P_0c06ca96: /* original e600, guest PC 0x0c06ca96 */
if(!s->budget--) { s->failed_pc=0x0c06ca96u; return 0; }
r[6]=0x00000000u;
goto P_0c06ca98;
P_0c06ca98: /* original 25bb, guest PC 0x0c06ca98 */
if(!s->budget--) { s->failed_pc=0x0c06ca98u; return 0; }
r[5]|=r[11];
goto P_0c06ca9a;
P_0c06ca9a: /* original 4a0b, guest PC 0x0c06ca9a */
if(!s->budget--) { s->failed_pc=0x0c06ca9au; return 0; }
target=r[10];
r[16]=code_base|0x0c06ca9eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ca9eu) { target=s->pc; goto dispatch; }
goto P_0c06ca9e;
P_0c06ca9c: /* original 64c3, guest PC 0x0c06ca9c */
if(!s->budget--) { s->failed_pc=0x0c06ca9cu; return 0; }
r[4]=r[12];
goto P_0c06ca9e;
P_0c06ca9e: /* original 65e3, guest PC 0x0c06ca9e */
if(!s->budget--) { s->failed_pc=0x0c06ca9eu; return 0; }
r[5]=r[14];
goto P_0c06caa0;
P_0c06caa0: /* original 7513, guest PC 0x0c06caa0 */
if(!s->budget--) { s->failed_pc=0x0c06caa0u; return 0; }
r[5]+=0x00000013u;
goto P_0c06caa2;
P_0c06caa2: /* original 66f2, guest PC 0x0c06caa2 */
if(!s->budget--) { s->failed_pc=0x0c06caa2u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c06caa4;
P_0c06caa4: /* original 4500, guest PC 0x0c06caa4 */
if(!s->budget--) { s->failed_pc=0x0c06caa4u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06caa6;
P_0c06caa6: /* original 6793, guest PC 0x0c06caa6 */
if(!s->budget--) { s->failed_pc=0x0c06caa6u; return 0; }
r[7]=r[9];
goto P_0c06caa8;
P_0c06caa8: /* original 25bb, guest PC 0x0c06caa8 */
if(!s->budget--) { s->failed_pc=0x0c06caa8u; return 0; }
r[5]|=r[11];
goto P_0c06caaa;
P_0c06caaa: /* original 36d8, guest PC 0x0c06caaa */
if(!s->budget--) { s->failed_pc=0x0c06caaau; return 0; }
r[6]-=r[13];
goto P_0c06caac;
P_0c06caac: /* original 4a0b, guest PC 0x0c06caac */
if(!s->budget--) { s->failed_pc=0x0c06caacu; return 0; }
target=r[10];
r[16]=code_base|0x0c06cab0u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cab0u) { target=s->pc; goto dispatch; }
goto P_0c06cab0;
P_0c06caae: /* original 64c3, guest PC 0x0c06caae */
if(!s->budget--) { s->failed_pc=0x0c06caaeu; return 0; }
r[4]=r[12];
goto P_0c06cab0;
P_0c06cab0: /* original a010, guest PC 0x0c06cab0 */
if(!s->budget--) { s->failed_pc=0x0c06cab0u; return 0; }
goto P_0c06cad4;
P_0c06cab2: /* original 0009, guest PC 0x0c06cab2 */
if(!s->budget--) { s->failed_pc=0x0c06cab2u; return 0; }
goto P_0c06cab4;
P_0c06cab4: /* original 694d, guest PC 0x0c06cab4 */
if(!s->budget--) { s->failed_pc=0x0c06cab4u; return 0; }
r[9]=r[4]&65535u;
goto P_0c06cab6;
P_0c06cab6: /* original 4e00, guest PC 0x0c06cab6 */
if(!s->budget--) { s->failed_pc=0x0c06cab6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c06cab8;
P_0c06cab8: /* original 2ebb, guest PC 0x0c06cab8 */
if(!s->budget--) { s->failed_pc=0x0c06cab8u; return 0; }
r[14]|=r[11];
goto P_0c06caba;
P_0c06caba: /* original bc6d, guest PC 0x0c06caba */
if(!s->budget--) { s->failed_pc=0x0c06cabau; return 0; }
target=code_base|0x0c06c398u; r[16]=code_base|0x0c06cabeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cabeu) { target=s->pc; goto dispatch; }
goto P_0c06cabe;
P_0c06cabc: /* original 64e3, guest PC 0x0c06cabc */
if(!s->budget--) { s->failed_pc=0x0c06cabcu; return 0; }
r[4]=r[14];
goto P_0c06cabe;
P_0c06cabe: /* original 2008, guest PC 0x0c06cabe */
if(!s->budget--) { s->failed_pc=0x0c06cabeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06cac0;
P_0c06cac0: /* original 8908, guest PC 0x0c06cac0 */
if(!s->budget--) { s->failed_pc=0x0c06cac0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cad4; }
goto P_0c06cac2;
P_0c06cac2: /* original e300, guest PC 0x0c06cac2 */
if(!s->budget--) { s->failed_pc=0x0c06cac2u; return 0; }
r[3]=0x00000000u;
goto P_0c06cac4;
P_0c06cac4: /* original 6593, guest PC 0x0c06cac4 */
if(!s->budget--) { s->failed_pc=0x0c06cac4u; return 0; }
r[5]=r[9];
goto P_0c06cac6;
P_0c06cac6: /* original 66c3, guest PC 0x0c06cac6 */
if(!s->budget--) { s->failed_pc=0x0c06cac6u; return 0; }
r[6]=r[12];
goto P_0c06cac8;
P_0c06cac8: /* original 2f36, guest PC 0x0c06cac8 */
if(!s->budget--) { s->failed_pc=0x0c06cac8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06caca;
P_0c06caca: /* original d21f, guest PC 0x0c06caca */
if(!s->budget--) { s->failed_pc=0x0c06cacau; return 0; }
r[2]=read(ram,0x0c06cb48u,4);
goto P_0c06cacc;
P_0c06cacc: /* original 6733, guest PC 0x0c06cacc */
if(!s->budget--) { s->failed_pc=0x0c06caccu; return 0; }
r[7]=r[3];
goto P_0c06cace;
P_0c06cace: /* original 420b, guest PC 0x0c06cace */
if(!s->budget--) { s->failed_pc=0x0c06caceu; return 0; }
target=r[2];
r[16]=code_base|0x0c06cad2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cad2u) { target=s->pc; goto dispatch; }
goto P_0c06cad2;
P_0c06cad0: /* original 64e3, guest PC 0x0c06cad0 */
if(!s->budget--) { s->failed_pc=0x0c06cad0u; return 0; }
r[4]=r[14];
goto P_0c06cad2;
P_0c06cad2: /* original 7f04, guest PC 0x0c06cad2 */
if(!s->budget--) { s->failed_pc=0x0c06cad2u; return 0; }
r[15]+=0x00000004u;
goto P_0c06cad4;
P_0c06cad4: /* original 7f04, guest PC 0x0c06cad4 */
if(!s->budget--) { s->failed_pc=0x0c06cad4u; return 0; }
r[15]+=0x00000004u;
goto P_0c06cad6;
P_0c06cad6: /* original 4f26, guest PC 0x0c06cad6 */
if(!s->budget--) { s->failed_pc=0x0c06cad6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06cad8;
P_0c06cad8: /* original 69f6, guest PC 0x0c06cad8 */
if(!s->budget--) { s->failed_pc=0x0c06cad8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06cada;
P_0c06cada: /* original 6af6, guest PC 0x0c06cada */
if(!s->budget--) { s->failed_pc=0x0c06cadau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06cadc;
P_0c06cadc: /* original 6bf6, guest PC 0x0c06cadc */
if(!s->budget--) { s->failed_pc=0x0c06cadcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06cade;
P_0c06cade: /* original 6cf6, guest PC 0x0c06cade */
if(!s->budget--) { s->failed_pc=0x0c06cadeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06cae0;
P_0c06cae0: /* original 6df6, guest PC 0x0c06cae0 */
if(!s->budget--) { s->failed_pc=0x0c06cae0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06cae2;
P_0c06cae2: /* original 000b, guest PC 0x0c06cae2 */
if(!s->budget--) { s->failed_pc=0x0c06cae2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06cae4: /* original 6ef6, guest PC 0x0c06cae4 */
if(!s->budget--) { s->failed_pc=0x0c06cae4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06cae6;
P_0c06cae6: /* original 2fe6, guest PC 0x0c06cae6 */
if(!s->budget--) { s->failed_pc=0x0c06cae6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cae8;
P_0c06cae8: /* original 4400, guest PC 0x0c06cae8 */
if(!s->budget--) { s->failed_pc=0x0c06cae8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06caea;
P_0c06caea: /* original 2fd6, guest PC 0x0c06caea */
if(!s->budget--) { s->failed_pc=0x0c06caeau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06caec;
P_0c06caec: /* original e307, guest PC 0x0c06caec */
if(!s->budget--) { s->failed_pc=0x0c06caecu; return 0; }
r[3]=0x00000007u;
goto P_0c06caee;
P_0c06caee: /* original 2fc6, guest PC 0x0c06caee */
if(!s->budget--) { s->failed_pc=0x0c06caeeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06caf0;
P_0c06caf0: /* original 6d43, guest PC 0x0c06caf0 */
if(!s->budget--) { s->failed_pc=0x0c06caf0u; return 0; }
r[13]=r[4];
goto P_0c06caf2;
P_0c06caf2: /* original 2fb6, guest PC 0x0c06caf2 */
if(!s->budget--) { s->failed_pc=0x0c06caf2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06caf4;
P_0c06caf4: /* original 453d, guest PC 0x0c06caf4 */
if(!s->budget--) { s->failed_pc=0x0c06caf4u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c06caf6;
P_0c06caf6: /* original 2fa6, guest PC 0x0c06caf6 */
if(!s->budget--) { s->failed_pc=0x0c06caf6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06caf8;
P_0c06caf8: /* original 2d5b, guest PC 0x0c06caf8 */
if(!s->budget--) { s->failed_pc=0x0c06caf8u; return 0; }
r[13]|=r[5];
goto P_0c06cafa;
P_0c06cafa: /* original 2f96, guest PC 0x0c06cafa */
if(!s->budget--) { s->failed_pc=0x0c06cafau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cafc;
P_0c06cafc: /* original 6e63, guest PC 0x0c06cafc */
if(!s->budget--) { s->failed_pc=0x0c06cafcu; return 0; }
r[14]=r[6];
goto P_0c06cafe;
P_0c06cafe: /* original d514, guest PC 0x0c06cafe */
if(!s->budget--) { s->failed_pc=0x0c06cafeu; return 0; }
r[5]=read(ram,0x0c06cb50u,4);
goto P_0c06cb00;
P_0c06cb00: /* original 901f, guest PC 0x0c06cb00 */
if(!s->budget--) { s->failed_pc=0x0c06cb00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cb42u,2);
goto P_0c06cb02;
P_0c06cb02: /* original 4f22, guest PC 0x0c06cb02 */
if(!s->budget--) { s->failed_pc=0x0c06cb02u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06cb04;
P_0c06cb04: /* original 045c, guest PC 0x0c06cb04 */
if(!s->budget--) { s->failed_pc=0x0c06cb04u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c06cb06;
P_0c06cb06: /* original da13, guest PC 0x0c06cb06 */
if(!s->budget--) { s->failed_pc=0x0c06cb06u; return 0; }
r[10]=read(ram,0x0c06cb54u,4);
goto P_0c06cb08;
P_0c06cb08: /* original 6043, guest PC 0x0c06cb08 */
if(!s->budget--) { s->failed_pc=0x0c06cb08u; return 0; }
r[0]=r[4];
goto P_0c06cb0a;
P_0c06cb0a: /* original 5bf7, guest PC 0x0c06cb0a */
if(!s->budget--) { s->failed_pc=0x0c06cb0au; return 0; }
r[11]=read(ram,r[15]+28,4);
goto P_0c06cb0c;
P_0c06cb0c: /* original 8801, guest PC 0x0c06cb0c */
if(!s->budget--) { s->failed_pc=0x0c06cb0cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cb0e;
P_0c06cb0e: /* original 8d2e, guest PC 0x0c06cb0e */
if(!s->budget--) { s->failed_pc=0x0c06cb0eu; return 0; }
cond=r[17]&1u;
r[9]=r[7];
if(cond) { goto P_0c06cb6e; }
goto P_0c06cb12;
P_0c06cb10: /* original 6973, guest PC 0x0c06cb10 */
if(!s->budget--) { s->failed_pc=0x0c06cb10u; return 0; }
r[9]=r[7];
goto P_0c06cb12;
P_0c06cb12: /* original 9017, guest PC 0x0c06cb12 */
if(!s->budget--) { s->failed_pc=0x0c06cb12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cb44u,2);
goto P_0c06cb14;
P_0c06cb14: /* original d411, guest PC 0x0c06cb14 */
if(!s->budget--) { s->failed_pc=0x0c06cb14u; return 0; }
r[4]=read(ram,0x0c06cb5cu,4);
goto P_0c06cb16;
P_0c06cb16: /* original 0c5c, guest PC 0x0c06cb16 */
if(!s->budget--) { s->failed_pc=0x0c06cb16u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c06cb18;
P_0c06cb18: /* original d50f, guest PC 0x0c06cb18 */
if(!s->budget--) { s->failed_pc=0x0c06cb18u; return 0; }
r[5]=read(ram,0x0c06cb58u,4);
goto P_0c06cb1a;
P_0c06cb1a: /* original 60c3, guest PC 0x0c06cb1a */
if(!s->budget--) { s->failed_pc=0x0c06cb1au; return 0; }
r[0]=r[12];
goto P_0c06cb1c;
P_0c06cb1c: /* original 8801, guest PC 0x0c06cb1c */
if(!s->budget--) { s->failed_pc=0x0c06cb1cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cb1e;
P_0c06cb1e: /* original 8d04, guest PC 0x0c06cb1e */
if(!s->budget--) { s->failed_pc=0x0c06cb1eu; return 0; }
cond=r[17]&1u;
r[6]=0x00000001u;
if(cond) { goto P_0c06cb2a; }
goto P_0c06cb22;
P_0c06cb20: /* original e601, guest PC 0x0c06cb20 */
if(!s->budget--) { s->failed_pc=0x0c06cb20u; return 0; }
r[6]=0x00000001u;
goto P_0c06cb22;
P_0c06cb22: /* original 3c90, guest PC 0x0c06cb22 */
if(!s->budget--) { s->failed_pc=0x0c06cb22u; return 0; }
r[17]=(r[17]&~1u)|((r[12]==r[9])!=0);
goto P_0c06cb24;
P_0c06cb24: /* original 8901, guest PC 0x0c06cb24 */
if(!s->budget--) { s->failed_pc=0x0c06cb24u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cb2a; }
goto P_0c06cb26;
P_0c06cb26: /* original 2998, guest PC 0x0c06cb26 */
if(!s->budget--) { s->failed_pc=0x0c06cb26u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c06cb28;
P_0c06cb28: /* original 8b37, guest PC 0x0c06cb28 */
if(!s->budget--) { s->failed_pc=0x0c06cb28u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06cb9a; }
goto P_0c06cb2a;
P_0c06cb2a: /* original 60b3, guest PC 0x0c06cb2a */
if(!s->budget--) { s->failed_pc=0x0c06cb2au; return 0; }
r[0]=r[11];
goto P_0c06cb2c;
P_0c06cb2c: /* original 8801, guest PC 0x0c06cb2c */
if(!s->budget--) { s->failed_pc=0x0c06cb2cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cb2e;
P_0c06cb2e: /* original 8925, guest PC 0x0c06cb2e */
if(!s->budget--) { s->failed_pc=0x0c06cb2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cb7c; }
goto P_0c06cb30;
P_0c06cb30: /* original 3e66, guest PC 0x0c06cb30 */
if(!s->budget--) { s->failed_pc=0x0c06cb30u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[6])!=0);
goto P_0c06cb32;
P_0c06cb32: /* original 8d15, guest PC 0x0c06cb32 */
if(!s->budget--) { s->failed_pc=0x0c06cb32u; return 0; }
cond=r[17]&1u;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
if(cond) { goto P_0c06cb60; }
goto P_0c06cb36;
P_0c06cb34: /* original 2fb6, guest PC 0x0c06cb34 */
if(!s->budget--) { s->failed_pc=0x0c06cb34u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cb36;
P_0c06cb36: /* original a014, guest PC 0x0c06cb36 */
if(!s->budget--) { s->failed_pc=0x0c06cb36u; return 0; }
r[6]=r[5];
goto P_0c06cb62;
P_0c06cb38: /* original 6653, guest PC 0x0c06cb38 */
if(!s->budget--) { s->failed_pc=0x0c06cb38u; return 0; }
r[6]=r[5];
if(!vf3_matrix_family(0x0c06cb3au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06cb3au; return 0; } return 1;
P_0c06cb60: /* original 6643, guest PC 0x0c06cb60 */
if(!s->budget--) { s->failed_pc=0x0c06cb60u; return 0; }
r[6]=r[4];
goto P_0c06cb62;
P_0c06cb62: /* original 65a3, guest PC 0x0c06cb62 */
if(!s->budget--) { s->failed_pc=0x0c06cb62u; return 0; }
r[5]=r[10];
goto P_0c06cb64;
P_0c06cb64: /* original 67e3, guest PC 0x0c06cb64 */
if(!s->budget--) { s->failed_pc=0x0c06cb64u; return 0; }
r[7]=r[14];
goto P_0c06cb66;
P_0c06cb66: /* original bc4e, guest PC 0x0c06cb66 */
if(!s->budget--) { s->failed_pc=0x0c06cb66u; return 0; }
target=code_base|0x0c06c406u; r[16]=code_base|0x0c06cb6au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cb6au) { target=s->pc; goto dispatch; }
goto P_0c06cb6a;
P_0c06cb68: /* original 64d3, guest PC 0x0c06cb68 */
if(!s->budget--) { s->failed_pc=0x0c06cb68u; return 0; }
r[4]=r[13];
goto P_0c06cb6a;
P_0c06cb6a: /* original a033, guest PC 0x0c06cb6a */
if(!s->budget--) { s->failed_pc=0x0c06cb6au; return 0; }
r[15]+=0x00000004u;
goto P_0c06cbd4;
P_0c06cb6c: /* original 7f04, guest PC 0x0c06cb6c */
if(!s->budget--) { s->failed_pc=0x0c06cb6cu; return 0; }
r[15]+=0x00000004u;
goto P_0c06cb6e;
P_0c06cb6e: /* original d23c, guest PC 0x0c06cb6e */
if(!s->budget--) { s->failed_pc=0x0c06cb6eu; return 0; }
r[2]=read(ram,0x0c06cc60u,4);
goto P_0c06cb70;
P_0c06cb70: /* original e601, guest PC 0x0c06cb70 */
if(!s->budget--) { s->failed_pc=0x0c06cb70u; return 0; }
r[6]=0x00000001u;
goto P_0c06cb72;
P_0c06cb72: /* original d53a, guest PC 0x0c06cb72 */
if(!s->budget--) { s->failed_pc=0x0c06cb72u; return 0; }
r[5]=read(ram,0x0c06cc5cu,4);
goto P_0c06cb74;
P_0c06cb74: /* original 420b, guest PC 0x0c06cb74 */
if(!s->budget--) { s->failed_pc=0x0c06cb74u; return 0; }
target=r[2];
r[16]=code_base|0x0c06cb78u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cb78u) { target=s->pc; goto dispatch; }
goto P_0c06cb78;
P_0c06cb76: /* original 64d3, guest PC 0x0c06cb76 */
if(!s->budget--) { s->failed_pc=0x0c06cb76u; return 0; }
r[4]=r[13];
goto P_0c06cb78;
P_0c06cb78: /* original a02c, guest PC 0x0c06cb78 */
if(!s->budget--) { s->failed_pc=0x0c06cb78u; return 0; }
goto P_0c06cbd4;
P_0c06cb7a: /* original 0009, guest PC 0x0c06cb7a */
if(!s->budget--) { s->failed_pc=0x0c06cb7au; return 0; }
goto P_0c06cb7c;
P_0c06cb7c: /* original 3e66, guest PC 0x0c06cb7c */
if(!s->budget--) { s->failed_pc=0x0c06cb7cu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[6])!=0);
goto P_0c06cb7e;
P_0c06cb7e: /* original 8f02, guest PC 0x0c06cb7e */
if(!s->budget--) { s->failed_pc=0x0c06cb7eu; return 0; }
cond=r[17]&1u;
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
if(!cond) { goto P_0c06cb86; }
goto P_0c06cb82;
P_0c06cb80: /* original 2fe6, guest PC 0x0c06cb80 */
if(!s->budget--) { s->failed_pc=0x0c06cb80u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cb82;
P_0c06cb82: /* original a001, guest PC 0x0c06cb82 */
if(!s->budget--) { s->failed_pc=0x0c06cb82u; return 0; }
r[6]=r[4];
goto P_0c06cb88;
P_0c06cb84: /* original 6643, guest PC 0x0c06cb84 */
if(!s->budget--) { s->failed_pc=0x0c06cb84u; return 0; }
r[6]=r[4];
goto P_0c06cb86;
P_0c06cb86: /* original 6653, guest PC 0x0c06cb86 */
if(!s->budget--) { s->failed_pc=0x0c06cb86u; return 0; }
r[6]=r[5];
goto P_0c06cb88;
P_0c06cb88: /* original 2f66, guest PC 0x0c06cb88 */
if(!s->budget--) { s->failed_pc=0x0c06cb88u; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cb8a;
P_0c06cb8a: /* original 2fa6, guest PC 0x0c06cb8a */
if(!s->budget--) { s->failed_pc=0x0c06cb8au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cb8c;
P_0c06cb8c: /* original d335, guest PC 0x0c06cb8c */
if(!s->budget--) { s->failed_pc=0x0c06cb8cu; return 0; }
r[3]=read(ram,0x0c06cc64u,4);
goto P_0c06cb8e;
P_0c06cb8e: /* original 2f36, guest PC 0x0c06cb8e */
if(!s->budget--) { s->failed_pc=0x0c06cb8eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cb90;
P_0c06cb90: /* original d235, guest PC 0x0c06cb90 */
if(!s->budget--) { s->failed_pc=0x0c06cb90u; return 0; }
r[2]=read(ram,0x0c06cc68u,4);
goto P_0c06cb92;
P_0c06cb92: /* original 420b, guest PC 0x0c06cb92 */
if(!s->budget--) { s->failed_pc=0x0c06cb92u; return 0; }
target=r[2];
r[16]=code_base|0x0c06cb96u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cb96u) { target=s->pc; goto dispatch; }
goto P_0c06cb96;
P_0c06cb94: /* original 64d3, guest PC 0x0c06cb94 */
if(!s->budget--) { s->failed_pc=0x0c06cb94u; return 0; }
r[4]=r[13];
goto P_0c06cb96;
P_0c06cb96: /* original a010, guest PC 0x0c06cb96 */
if(!s->budget--) { s->failed_pc=0x0c06cb96u; return 0; }
goto P_0c06cbba;
P_0c06cb98: /* original 0009, guest PC 0x0c06cb98 */
if(!s->budget--) { s->failed_pc=0x0c06cb98u; return 0; }
goto P_0c06cb9a;
P_0c06cb9a: /* original 60b3, guest PC 0x0c06cb9a */
if(!s->budget--) { s->failed_pc=0x0c06cb9au; return 0; }
r[0]=r[11];
goto P_0c06cb9c;
P_0c06cb9c: /* original d733, guest PC 0x0c06cb9c */
if(!s->budget--) { s->failed_pc=0x0c06cb9cu; return 0; }
r[7]=read(ram,0x0c06cc6cu,4);
goto P_0c06cb9e;
P_0c06cb9e: /* original 8801, guest PC 0x0c06cb9e */
if(!s->budget--) { s->failed_pc=0x0c06cb9eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cba0;
P_0c06cba0: /* original 890d, guest PC 0x0c06cba0 */
if(!s->budget--) { s->failed_pc=0x0c06cba0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cbbe; }
goto P_0c06cba2;
P_0c06cba2: /* original 3e66, guest PC 0x0c06cba2 */
if(!s->budget--) { s->failed_pc=0x0c06cba2u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[6])!=0);
goto P_0c06cba4;
P_0c06cba4: /* original 8d02, guest PC 0x0c06cba4 */
if(!s->budget--) { s->failed_pc=0x0c06cba4u; return 0; }
cond=r[17]&1u;
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
if(cond) { goto P_0c06cbac; }
goto P_0c06cba8;
P_0c06cba6: /* original 2fc6, guest PC 0x0c06cba6 */
if(!s->budget--) { s->failed_pc=0x0c06cba6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cba8;
P_0c06cba8: /* original a001, guest PC 0x0c06cba8 */
if(!s->budget--) { s->failed_pc=0x0c06cba8u; return 0; }
r[6]=r[5];
goto P_0c06cbae;
P_0c06cbaa: /* original 6653, guest PC 0x0c06cbaa */
if(!s->budget--) { s->failed_pc=0x0c06cbaau; return 0; }
r[6]=r[5];
goto P_0c06cbac;
P_0c06cbac: /* original 6643, guest PC 0x0c06cbac */
if(!s->budget--) { s->failed_pc=0x0c06cbacu; return 0; }
r[6]=r[4];
goto P_0c06cbae;
P_0c06cbae: /* original 2f96, guest PC 0x0c06cbae */
if(!s->budget--) { s->failed_pc=0x0c06cbaeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbb0;
P_0c06cbb0: /* original 65a3, guest PC 0x0c06cbb0 */
if(!s->budget--) { s->failed_pc=0x0c06cbb0u; return 0; }
r[5]=r[10];
goto P_0c06cbb2;
P_0c06cbb2: /* original 2fb6, guest PC 0x0c06cbb2 */
if(!s->budget--) { s->failed_pc=0x0c06cbb2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbb4;
P_0c06cbb4: /* original 2fe6, guest PC 0x0c06cbb4 */
if(!s->budget--) { s->failed_pc=0x0c06cbb4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbb6;
P_0c06cbb6: /* original b015, guest PC 0x0c06cbb6 */
if(!s->budget--) { s->failed_pc=0x0c06cbb6u; return 0; }
target=code_base|0x0c06cbe4u; r[16]=code_base|0x0c06cbbau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cbbau) { target=s->pc; goto dispatch; }
goto P_0c06cbba;
P_0c06cbb8: /* original 64d3, guest PC 0x0c06cbb8 */
if(!s->budget--) { s->failed_pc=0x0c06cbb8u; return 0; }
r[4]=r[13];
goto P_0c06cbba;
P_0c06cbba: /* original a00b, guest PC 0x0c06cbba */
if(!s->budget--) { s->failed_pc=0x0c06cbbau; return 0; }
r[15]+=0x00000010u;
goto P_0c06cbd4;
P_0c06cbbc: /* original 7f10, guest PC 0x0c06cbbc */
if(!s->budget--) { s->failed_pc=0x0c06cbbcu; return 0; }
r[15]+=0x00000010u;
goto P_0c06cbbe;
P_0c06cbbe: /* original 2fc6, guest PC 0x0c06cbbe */
if(!s->budget--) { s->failed_pc=0x0c06cbbeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbc0;
P_0c06cbc0: /* original 2f96, guest PC 0x0c06cbc0 */
if(!s->budget--) { s->failed_pc=0x0c06cbc0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbc2;
P_0c06cbc2: /* original 2f76, guest PC 0x0c06cbc2 */
if(!s->budget--) { s->failed_pc=0x0c06cbc2u; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbc4;
P_0c06cbc4: /* original 2fe6, guest PC 0x0c06cbc4 */
if(!s->budget--) { s->failed_pc=0x0c06cbc4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbc6;
P_0c06cbc6: /* original 2fa6, guest PC 0x0c06cbc6 */
if(!s->budget--) { s->failed_pc=0x0c06cbc6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbc8;
P_0c06cbc8: /* original d229, guest PC 0x0c06cbc8 */
if(!s->budget--) { s->failed_pc=0x0c06cbc8u; return 0; }
r[2]=read(ram,0x0c06cc70u,4);
goto P_0c06cbca;
P_0c06cbca: /* original 2f26, guest PC 0x0c06cbca */
if(!s->budget--) { s->failed_pc=0x0c06cbcau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbcc;
P_0c06cbcc: /* original d326, guest PC 0x0c06cbcc */
if(!s->budget--) { s->failed_pc=0x0c06cbccu; return 0; }
r[3]=read(ram,0x0c06cc68u,4);
goto P_0c06cbce;
P_0c06cbce: /* original 430b, guest PC 0x0c06cbce */
if(!s->budget--) { s->failed_pc=0x0c06cbceu; return 0; }
target=r[3];
r[16]=code_base|0x0c06cbd2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cbd2u) { target=s->pc; goto dispatch; }
goto P_0c06cbd2;
P_0c06cbd0: /* original 64d3, guest PC 0x0c06cbd0 */
if(!s->budget--) { s->failed_pc=0x0c06cbd0u; return 0; }
r[4]=r[13];
goto P_0c06cbd2;
P_0c06cbd2: /* original 7f18, guest PC 0x0c06cbd2 */
if(!s->budget--) { s->failed_pc=0x0c06cbd2u; return 0; }
r[15]+=0x00000018u;
goto P_0c06cbd4;
P_0c06cbd4: /* original 4f26, guest PC 0x0c06cbd4 */
if(!s->budget--) { s->failed_pc=0x0c06cbd4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06cbd6;
P_0c06cbd6: /* original 69f6, guest PC 0x0c06cbd6 */
if(!s->budget--) { s->failed_pc=0x0c06cbd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06cbd8;
P_0c06cbd8: /* original 6af6, guest PC 0x0c06cbd8 */
if(!s->budget--) { s->failed_pc=0x0c06cbd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06cbda;
P_0c06cbda: /* original 6bf6, guest PC 0x0c06cbda */
if(!s->budget--) { s->failed_pc=0x0c06cbdau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06cbdc;
P_0c06cbdc: /* original 6cf6, guest PC 0x0c06cbdc */
if(!s->budget--) { s->failed_pc=0x0c06cbdcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06cbde;
P_0c06cbde: /* original 6df6, guest PC 0x0c06cbde */
if(!s->budget--) { s->failed_pc=0x0c06cbdeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06cbe0;
P_0c06cbe0: /* original 000b, guest PC 0x0c06cbe0 */
if(!s->budget--) { s->failed_pc=0x0c06cbe0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06cbe2: /* original 6ef6, guest PC 0x0c06cbe2 */
if(!s->budget--) { s->failed_pc=0x0c06cbe2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06cbe4u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
