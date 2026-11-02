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
int vf3_away_batch16_adapter_10(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08d9f4u: goto P_0c08d9f4;
case 0x0c08d9f6u: goto P_0c08d9f6;
case 0x0c08d9f8u: goto P_0c08d9f8;
case 0x0c08d9fau: goto P_0c08d9fa;
case 0x0c08d9fcu: goto P_0c08d9fc;
case 0x0c08d9feu: goto P_0c08d9fe;
case 0x0c08da00u: goto P_0c08da00;
case 0x0c08da02u: goto P_0c08da02;
case 0x0c08da04u: goto P_0c08da04;
case 0x0c08da06u: goto P_0c08da06;
case 0x0c08da08u: goto P_0c08da08;
case 0x0c08da0au: goto P_0c08da0a;
case 0x0c08da0cu: goto P_0c08da0c;
case 0x0c08da0eu: goto P_0c08da0e;
case 0x0c08da10u: goto P_0c08da10;
case 0x0c08da12u: goto P_0c08da12;
case 0x0c08da14u: goto P_0c08da14;
case 0x0c08da16u: goto P_0c08da16;
case 0x0c08da18u: goto P_0c08da18;
case 0x0c08da1au: goto P_0c08da1a;
case 0x0c08da1cu: goto P_0c08da1c;
case 0x0c08da1eu: goto P_0c08da1e;
case 0x0c08da20u: goto P_0c08da20;
case 0x0c08da22u: goto P_0c08da22;
case 0x0c08da24u: goto P_0c08da24;
case 0x0c08da26u: goto P_0c08da26;
case 0x0c08da28u: goto P_0c08da28;
case 0x0c08da2au: goto P_0c08da2a;
case 0x0c08da2cu: goto P_0c08da2c;
case 0x0c08da2eu: goto P_0c08da2e;
case 0x0c08da30u: goto P_0c08da30;
case 0x0c08da32u: goto P_0c08da32;
case 0x0c08da34u: goto P_0c08da34;
case 0x0c08da36u: goto P_0c08da36;
case 0x0c08da38u: goto P_0c08da38;
case 0x0c08da3au: goto P_0c08da3a;
case 0x0c08da3cu: goto P_0c08da3c;
case 0x0c08da3eu: goto P_0c08da3e;
case 0x0c08da40u: goto P_0c08da40;
case 0x0c08da42u: goto P_0c08da42;
case 0x0c08da44u: goto P_0c08da44;
case 0x0c08da46u: goto P_0c08da46;
case 0x0c08da48u: goto P_0c08da48;
case 0x0c08da4au: goto P_0c08da4a;
case 0x0c08da4cu: goto P_0c08da4c;
case 0x0c08da4eu: goto P_0c08da4e;
case 0x0c08da50u: goto P_0c08da50;
case 0x0c08da52u: goto P_0c08da52;
case 0x0c08da54u: goto P_0c08da54;
case 0x0c08da56u: goto P_0c08da56;
case 0x0c08da58u: goto P_0c08da58;
case 0x0c08da5au: goto P_0c08da5a;
case 0x0c08da5cu: goto P_0c08da5c;
case 0x0c08da5eu: goto P_0c08da5e;
case 0x0c08da60u: goto P_0c08da60;
case 0x0c08da62u: goto P_0c08da62;
case 0x0c08da64u: goto P_0c08da64;
case 0x0c08da66u: goto P_0c08da66;
case 0x0c08da68u: goto P_0c08da68;
case 0x0c08da6au: goto P_0c08da6a;
case 0x0c08da6cu: goto P_0c08da6c;
case 0x0c08da6eu: goto P_0c08da6e;
case 0x0c08da70u: goto P_0c08da70;
case 0x0c08da72u: goto P_0c08da72;
case 0x0c08da74u: goto P_0c08da74;
case 0x0c08da76u: goto P_0c08da76;
case 0x0c08da78u: goto P_0c08da78;
case 0x0c08da7au: goto P_0c08da7a;
case 0x0c08da7cu: goto P_0c08da7c;
case 0x0c08da7eu: goto P_0c08da7e;
case 0x0c08da80u: goto P_0c08da80;
case 0x0c08da82u: goto P_0c08da82;
case 0x0c08da84u: goto P_0c08da84;
case 0x0c08da86u: goto P_0c08da86;
case 0x0c08da88u: goto P_0c08da88;
case 0x0c08da8au: goto P_0c08da8a;
case 0x0c08da8cu: goto P_0c08da8c;
case 0x0c08da8eu: goto P_0c08da8e;
case 0x0c08da90u: goto P_0c08da90;
case 0x0c08da92u: goto P_0c08da92;
case 0x0c08da94u: goto P_0c08da94;
case 0x0c08da96u: goto P_0c08da96;
case 0x0c08da98u: goto P_0c08da98;
case 0x0c08da9au: goto P_0c08da9a;
case 0x0c08da9cu: goto P_0c08da9c;
case 0x0c08da9eu: goto P_0c08da9e;
case 0x0c08daa0u: goto P_0c08daa0;
case 0x0c08daa2u: goto P_0c08daa2;
case 0x0c08daa4u: goto P_0c08daa4;
case 0x0c08daa6u: goto P_0c08daa6;
case 0x0c08daa8u: goto P_0c08daa8;
case 0x0c08daaau: goto P_0c08daaa;
case 0x0c08daacu: goto P_0c08daac;
case 0x0c08daaeu: goto P_0c08daae;
case 0x0c08dab0u: goto P_0c08dab0;
case 0x0c08dab2u: goto P_0c08dab2;
case 0x0c08dab4u: goto P_0c08dab4;
case 0x0c08dab6u: goto P_0c08dab6;
case 0x0c08dab8u: goto P_0c08dab8;
case 0x0c08dabau: goto P_0c08daba;
case 0x0c08dabcu: goto P_0c08dabc;
case 0x0c08dabeu: goto P_0c08dabe;
case 0x0c08dac0u: goto P_0c08dac0;
case 0x0c08dac2u: goto P_0c08dac2;
case 0x0c08dac4u: goto P_0c08dac4;
case 0x0c08dac6u: goto P_0c08dac6;
case 0x0c08dac8u: goto P_0c08dac8;
case 0x0c08dacau: goto P_0c08daca;
case 0x0c08daccu: goto P_0c08dacc;
case 0x0c08daceu: goto P_0c08dace;
case 0x0c08dad0u: goto P_0c08dad0;
case 0x0c08dad2u: goto P_0c08dad2;
case 0x0c08dad4u: goto P_0c08dad4;
case 0x0c08dad6u: goto P_0c08dad6;
case 0x0c08dad8u: goto P_0c08dad8;
case 0x0c08daf4u: goto P_0c08daf4;
case 0x0c08daf6u: goto P_0c08daf6;
case 0x0c08daf8u: goto P_0c08daf8;
case 0x0c08dafau: goto P_0c08dafa;
case 0x0c08dafcu: goto P_0c08dafc;
case 0x0c08dafeu: goto P_0c08dafe;
case 0x0c08db00u: goto P_0c08db00;
case 0x0c08db02u: goto P_0c08db02;
case 0x0c08db04u: goto P_0c08db04;
case 0x0c08db06u: goto P_0c08db06;
case 0x0c08db08u: goto P_0c08db08;
case 0x0c08db0au: goto P_0c08db0a;
case 0x0c08db0cu: goto P_0c08db0c;
case 0x0c08db0eu: goto P_0c08db0e;
case 0x0c08db10u: goto P_0c08db10;
case 0x0c08db12u: goto P_0c08db12;
case 0x0c08db14u: goto P_0c08db14;
case 0x0c08db16u: goto P_0c08db16;
case 0x0c08db18u: goto P_0c08db18;
case 0x0c08db1au: goto P_0c08db1a;
case 0x0c08db1cu: goto P_0c08db1c;
case 0x0c08db1eu: goto P_0c08db1e;
case 0x0c08db20u: goto P_0c08db20;
case 0x0c08db22u: goto P_0c08db22;
case 0x0c08db24u: goto P_0c08db24;
case 0x0c08db26u: goto P_0c08db26;
case 0x0c08db28u: goto P_0c08db28;
case 0x0c08db2au: goto P_0c08db2a;
case 0x0c08db2cu: goto P_0c08db2c;
case 0x0c08db2eu: goto P_0c08db2e;
case 0x0c08db30u: goto P_0c08db30;
case 0x0c08db32u: goto P_0c08db32;
case 0x0c08db34u: goto P_0c08db34;
case 0x0c08db36u: goto P_0c08db36;
case 0x0c08db38u: goto P_0c08db38;
case 0x0c08db3au: goto P_0c08db3a;
case 0x0c08db3cu: goto P_0c08db3c;
case 0x0c08db3eu: goto P_0c08db3e;
case 0x0c08db40u: goto P_0c08db40;
case 0x0c08db42u: goto P_0c08db42;
case 0x0c08db44u: goto P_0c08db44;
case 0x0c08db46u: goto P_0c08db46;
case 0x0c08db48u: goto P_0c08db48;
case 0x0c08db4au: goto P_0c08db4a;
case 0x0c08db4cu: goto P_0c08db4c;
case 0x0c08db4eu: goto P_0c08db4e;
case 0x0c08db50u: goto P_0c08db50;
case 0x0c08db52u: goto P_0c08db52;
case 0x0c08db54u: goto P_0c08db54;
case 0x0c08db56u: goto P_0c08db56;
case 0x0c08db58u: goto P_0c08db58;
case 0x0c08db5au: goto P_0c08db5a;
case 0x0c08db5cu: goto P_0c08db5c;
case 0x0c08db5eu: goto P_0c08db5e;
case 0x0c08db60u: goto P_0c08db60;
case 0x0c08db62u: goto P_0c08db62;
case 0x0c08db64u: goto P_0c08db64;
case 0x0c08db66u: goto P_0c08db66;
case 0x0c08db68u: goto P_0c08db68;
case 0x0c08db6au: goto P_0c08db6a;
case 0x0c08db6cu: goto P_0c08db6c;
case 0x0c08db6eu: goto P_0c08db6e;
case 0x0c08dbe4u: goto P_0c08dbe4;
case 0x0c08dbe6u: goto P_0c08dbe6;
case 0x0c08dbe8u: goto P_0c08dbe8;
case 0x0c08dbeau: goto P_0c08dbea;
case 0x0c08dbecu: goto P_0c08dbec;
case 0x0c08dbeeu: goto P_0c08dbee;
case 0x0c08dbf0u: goto P_0c08dbf0;
case 0x0c08dbf2u: goto P_0c08dbf2;
case 0x0c08dbf4u: goto P_0c08dbf4;
case 0x0c08dbf6u: goto P_0c08dbf6;
case 0x0c08dbf8u: goto P_0c08dbf8;
case 0x0c08dbfau: goto P_0c08dbfa;
case 0x0c08dbfcu: goto P_0c08dbfc;
case 0x0c08dbfeu: goto P_0c08dbfe;
case 0x0c08dc00u: goto P_0c08dc00;
case 0x0c08dc02u: goto P_0c08dc02;
case 0x0c08dc04u: goto P_0c08dc04;
case 0x0c08dc06u: goto P_0c08dc06;
case 0x0c08dc08u: goto P_0c08dc08;
case 0x0c08dc0au: goto P_0c08dc0a;
case 0x0c08dc0cu: goto P_0c08dc0c;
case 0x0c08dc0eu: goto P_0c08dc0e;
case 0x0c08dc10u: goto P_0c08dc10;
case 0x0c08dc12u: goto P_0c08dc12;
case 0x0c08dc14u: goto P_0c08dc14;
case 0x0c08dc16u: goto P_0c08dc16;
case 0x0c08dc18u: goto P_0c08dc18;
case 0x0c08dc1au: goto P_0c08dc1a;
case 0x0c08dc1cu: goto P_0c08dc1c;
case 0x0c08dc1eu: goto P_0c08dc1e;
case 0x0c08dc20u: goto P_0c08dc20;
case 0x0c08dc22u: goto P_0c08dc22;
case 0x0c08dc24u: goto P_0c08dc24;
case 0x0c08dc26u: goto P_0c08dc26;
case 0x0c08dc28u: goto P_0c08dc28;
case 0x0c08dc2au: goto P_0c08dc2a;
case 0x0c08dc2cu: goto P_0c08dc2c;
case 0x0c08dc2eu: goto P_0c08dc2e;
case 0x0c08dc30u: goto P_0c08dc30;
case 0x0c08dc32u: goto P_0c08dc32;
case 0x0c08dc34u: goto P_0c08dc34;
case 0x0c08dc36u: goto P_0c08dc36;
case 0x0c08dc38u: goto P_0c08dc38;
case 0x0c08dc3au: goto P_0c08dc3a;
case 0x0c08dc3cu: goto P_0c08dc3c;
case 0x0c08dc4cu: goto P_0c08dc4c;
case 0x0c08dc4eu: goto P_0c08dc4e;
case 0x0c08dc50u: goto P_0c08dc50;
case 0x0c08dc52u: goto P_0c08dc52;
case 0x0c08dc54u: goto P_0c08dc54;
case 0x0c08dc56u: goto P_0c08dc56;
case 0x0c08dc58u: goto P_0c08dc58;
case 0x0c08dc5au: goto P_0c08dc5a;
case 0x0c08dc5cu: goto P_0c08dc5c;
case 0x0c08dc5eu: goto P_0c08dc5e;
case 0x0c08dc60u: goto P_0c08dc60;
case 0x0c08dc62u: goto P_0c08dc62;
case 0x0c08dc64u: goto P_0c08dc64;
case 0x0c08dc66u: goto P_0c08dc66;
case 0x0c08dc68u: goto P_0c08dc68;
case 0x0c08dc6au: goto P_0c08dc6a;
case 0x0c08dc6cu: goto P_0c08dc6c;
case 0x0c08dc6eu: goto P_0c08dc6e;
case 0x0c08dc70u: goto P_0c08dc70;
case 0x0c08dc72u: goto P_0c08dc72;
case 0x0c08dc74u: goto P_0c08dc74;
case 0x0c08dc76u: goto P_0c08dc76;
case 0x0c08dc78u: goto P_0c08dc78;
case 0x0c08dc7au: goto P_0c08dc7a;
case 0x0c08dc7cu: goto P_0c08dc7c;
case 0x0c08dc7eu: goto P_0c08dc7e;
case 0x0c08dc80u: goto P_0c08dc80;
case 0x0c08dc82u: goto P_0c08dc82;
case 0x0c08dc84u: goto P_0c08dc84;
case 0x0c08dc86u: goto P_0c08dc86;
case 0x0c08dc88u: goto P_0c08dc88;
case 0x0c08dc8au: goto P_0c08dc8a;
case 0x0c08dc8cu: goto P_0c08dc8c;
case 0x0c08dc8eu: goto P_0c08dc8e;
case 0x0c08dc90u: goto P_0c08dc90;
case 0x0c08dc92u: goto P_0c08dc92;
case 0x0c08dc94u: goto P_0c08dc94;
case 0x0c08dc96u: goto P_0c08dc96;
case 0x0c08dc98u: goto P_0c08dc98;
case 0x0c08dc9au: goto P_0c08dc9a;
case 0x0c08dc9cu: goto P_0c08dc9c;
case 0x0c08dc9eu: goto P_0c08dc9e;
case 0x0c08dca0u: goto P_0c08dca0;
case 0x0c08dca2u: goto P_0c08dca2;
case 0x0c08dca4u: goto P_0c08dca4;
case 0x0c08dca6u: goto P_0c08dca6;
case 0x0c08dca8u: goto P_0c08dca8;
case 0x0c08dcaau: goto P_0c08dcaa;
case 0x0c08dcacu: goto P_0c08dcac;
case 0x0c08dcaeu: goto P_0c08dcae;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08d9f4: /* original 2fe6, guest PC 0x0c08d9f4 */
if(!s->budget--) { s->failed_pc=0x0c08d9f4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d9f6;
P_0c08d9f6: /* original ee00, guest PC 0x0c08d9f6 */
if(!s->budget--) { s->failed_pc=0x0c08d9f6u; return 0; }
r[14]=0x00000000u;
goto P_0c08d9f8;
P_0c08d9f8: /* original 4f22, guest PC 0x0c08d9f8 */
if(!s->budget--) { s->failed_pc=0x0c08d9f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08d9fa;
P_0c08d9fa: /* original 65e3, guest PC 0x0c08d9fa */
if(!s->budget--) { s->failed_pc=0x0c08d9fau; return 0; }
r[5]=r[14];
goto P_0c08d9fc;
P_0c08d9fc: /* original 7fec, guest PC 0x0c08d9fc */
if(!s->budget--) { s->failed_pc=0x0c08d9fcu; return 0; }
r[15]+=0xffffffecu;
goto P_0c08d9fe;
P_0c08d9fe: /* original 63f3, guest PC 0x0c08d9fe */
if(!s->budget--) { s->failed_pc=0x0c08d9feu; return 0; }
r[3]=r[15];
goto P_0c08da00;
P_0c08da00: /* original 730c, guest PC 0x0c08da00 */
if(!s->budget--) { s->failed_pc=0x0c08da00u; return 0; }
r[3]+=0x0000000cu;
goto P_0c08da02;
P_0c08da02: /* original 1f44, guest PC 0x0c08da02 */
if(!s->budget--) { s->failed_pc=0x0c08da02u; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c08da04;
P_0c08da04: /* original 2f36, guest PC 0x0c08da04 */
if(!s->budget--) { s->failed_pc=0x0c08da04u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da06;
P_0c08da06: /* original 62f3, guest PC 0x0c08da06 */
if(!s->budget--) { s->failed_pc=0x0c08da06u; return 0; }
r[2]=r[15];
goto P_0c08da08;
P_0c08da08: /* original 720c, guest PC 0x0c08da08 */
if(!s->budget--) { s->failed_pc=0x0c08da08u; return 0; }
r[2]+=0x0000000cu;
goto P_0c08da0a;
P_0c08da0a: /* original 2f26, guest PC 0x0c08da0a */
if(!s->budget--) { s->failed_pc=0x0c08da0au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da0c;
P_0c08da0c: /* original 66f3, guest PC 0x0c08da0c */
if(!s->budget--) { s->failed_pc=0x0c08da0cu; return 0; }
r[6]=r[15];
goto P_0c08da0e;
P_0c08da0e: /* original 67f3, guest PC 0x0c08da0e */
if(!s->budget--) { s->failed_pc=0x0c08da0eu; return 0; }
r[7]=r[15];
goto P_0c08da10;
P_0c08da10: /* original 7608, guest PC 0x0c08da10 */
if(!s->budget--) { s->failed_pc=0x0c08da10u; return 0; }
r[6]+=0x00000008u;
goto P_0c08da12;
P_0c08da12: /* original 770c, guest PC 0x0c08da12 */
if(!s->budget--) { s->failed_pc=0x0c08da12u; return 0; }
r[7]+=0x0000000cu;
goto P_0c08da14;
P_0c08da14: /* original b14c, guest PC 0x0c08da14 */
if(!s->budget--) { s->failed_pc=0x0c08da14u; return 0; }
target=code_base|0x0c08dcb0u; r[16]=code_base|0x0c08da18u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08da18u) { target=s->pc; goto dispatch; }
goto P_0c08da18;
P_0c08da16: /* original 64e3, guest PC 0x0c08da16 */
if(!s->budget--) { s->failed_pc=0x0c08da16u; return 0; }
r[4]=r[14];
goto P_0c08da18;
P_0c08da18: /* original 62f3, guest PC 0x0c08da18 */
if(!s->budget--) { s->failed_pc=0x0c08da18u; return 0; }
r[2]=r[15];
goto P_0c08da1a;
P_0c08da1a: /* original 7214, guest PC 0x0c08da1a */
if(!s->budget--) { s->failed_pc=0x0c08da1au; return 0; }
r[2]+=0x00000014u;
goto P_0c08da1c;
P_0c08da1c: /* original 2f26, guest PC 0x0c08da1c */
if(!s->budget--) { s->failed_pc=0x0c08da1cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da1e;
P_0c08da1e: /* original 66f3, guest PC 0x0c08da1e */
if(!s->budget--) { s->failed_pc=0x0c08da1eu; return 0; }
r[6]=r[15];
goto P_0c08da20;
P_0c08da20: /* original 65f3, guest PC 0x0c08da20 */
if(!s->budget--) { s->failed_pc=0x0c08da20u; return 0; }
r[5]=r[15];
goto P_0c08da22;
P_0c08da22: /* original 67f3, guest PC 0x0c08da22 */
if(!s->budget--) { s->failed_pc=0x0c08da22u; return 0; }
r[7]=r[15];
goto P_0c08da24;
P_0c08da24: /* original 750c, guest PC 0x0c08da24 */
if(!s->budget--) { s->failed_pc=0x0c08da24u; return 0; }
r[5]+=0x0000000cu;
goto P_0c08da26;
P_0c08da26: /* original 7714, guest PC 0x0c08da26 */
if(!s->budget--) { s->failed_pc=0x0c08da26u; return 0; }
r[7]+=0x00000014u;
goto P_0c08da28;
P_0c08da28: /* original 7610, guest PC 0x0c08da28 */
if(!s->budget--) { s->failed_pc=0x0c08da28u; return 0; }
r[6]+=0x00000010u;
goto P_0c08da2a;
P_0c08da2a: /* original b174, guest PC 0x0c08da2a */
if(!s->budget--) { s->failed_pc=0x0c08da2au; return 0; }
target=code_base|0x0c08dd16u; r[16]=code_base|0x0c08da2eu;
r[4]=read(ram,r[15]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08da2eu) { target=s->pc; goto dispatch; }
goto P_0c08da2e;
P_0c08da2c: /* original 54f7, guest PC 0x0c08da2c */
if(!s->budget--) { s->failed_pc=0x0c08da2cu; return 0; }
r[4]=read(ram,r[15]+28,4);
goto P_0c08da2e;
P_0c08da2e: /* original 52f6, guest PC 0x0c08da2e */
if(!s->budget--) { s->failed_pc=0x0c08da2eu; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c08da30;
P_0c08da30: /* original 65e3, guest PC 0x0c08da30 */
if(!s->budget--) { s->failed_pc=0x0c08da30u; return 0; }
r[5]=r[14];
goto P_0c08da32;
P_0c08da32: /* original 66e3, guest PC 0x0c08da32 */
if(!s->budget--) { s->failed_pc=0x0c08da32u; return 0; }
r[6]=r[14];
goto P_0c08da34;
P_0c08da34: /* original 2f26, guest PC 0x0c08da34 */
if(!s->budget--) { s->failed_pc=0x0c08da34u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da36;
P_0c08da36: /* original 53f6, guest PC 0x0c08da36 */
if(!s->budget--) { s->failed_pc=0x0c08da36u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c08da38;
P_0c08da38: /* original 2f36, guest PC 0x0c08da38 */
if(!s->budget--) { s->failed_pc=0x0c08da38u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da3a;
P_0c08da3a: /* original 52f6, guest PC 0x0c08da3a */
if(!s->budget--) { s->failed_pc=0x0c08da3au; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c08da3c;
P_0c08da3c: /* original 2f26, guest PC 0x0c08da3c */
if(!s->budget--) { s->failed_pc=0x0c08da3cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da3e;
P_0c08da3e: /* original 57f6, guest PC 0x0c08da3e */
if(!s->budget--) { s->failed_pc=0x0c08da3eu; return 0; }
r[7]=read(ram,r[15]+24,4);
goto P_0c08da40;
P_0c08da40: /* original b251, guest PC 0x0c08da40 */
if(!s->budget--) { s->failed_pc=0x0c08da40u; return 0; }
target=code_base|0x0c08dee6u; r[16]=code_base|0x0c08da44u;
r[4]=read(ram,r[15]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08da44u) { target=s->pc; goto dispatch; }
goto P_0c08da44;
P_0c08da42: /* original 54fa, guest PC 0x0c08da42 */
if(!s->budget--) { s->failed_pc=0x0c08da42u; return 0; }
r[4]=read(ram,r[15]+40,4);
goto P_0c08da44;
P_0c08da44: /* original 7f2c, guest PC 0x0c08da44 */
if(!s->budget--) { s->failed_pc=0x0c08da44u; return 0; }
r[15]+=0x0000002cu;
goto P_0c08da46;
P_0c08da46: /* original 4f26, guest PC 0x0c08da46 */
if(!s->budget--) { s->failed_pc=0x0c08da46u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08da48;
P_0c08da48: /* original 000b, guest PC 0x0c08da48 */
if(!s->budget--) { s->failed_pc=0x0c08da48u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08da4a: /* original 6ef6, guest PC 0x0c08da4a */
if(!s->budget--) { s->failed_pc=0x0c08da4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08da4c;
P_0c08da4c: /* original 2fe6, guest PC 0x0c08da4c */
if(!s->budget--) { s->failed_pc=0x0c08da4cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da4e;
P_0c08da4e: /* original 6e43, guest PC 0x0c08da4e */
if(!s->budget--) { s->failed_pc=0x0c08da4eu; return 0; }
r[14]=r[4];
goto P_0c08da50;
P_0c08da50: /* original 2fd6, guest PC 0x0c08da50 */
if(!s->budget--) { s->failed_pc=0x0c08da50u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da52;
P_0c08da52: /* original e301, guest PC 0x0c08da52 */
if(!s->budget--) { s->failed_pc=0x0c08da52u; return 0; }
r[3]=0x00000001u;
goto P_0c08da54;
P_0c08da54: /* original 2fc6, guest PC 0x0c08da54 */
if(!s->budget--) { s->failed_pc=0x0c08da54u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da56;
P_0c08da56: /* original 9042, guest PC 0x0c08da56 */
if(!s->budget--) { s->failed_pc=0x0c08da56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dadeu,2);
goto P_0c08da58;
P_0c08da58: /* original 4f22, guest PC 0x0c08da58 */
if(!s->budget--) { s->failed_pc=0x0c08da58u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08da5a;
P_0c08da5a: /* original 0ced, guest PC 0x0c08da5a */
if(!s->budget--) { s->failed_pc=0x0c08da5au; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08da5c;
P_0c08da5c: /* original 7002, guest PC 0x0c08da5c */
if(!s->budget--) { s->failed_pc=0x0c08da5cu; return 0; }
r[0]+=0x00000002u;
goto P_0c08da5e;
P_0c08da5e: /* original 0ded, guest PC 0x0c08da5e */
if(!s->budget--) { s->failed_pc=0x0c08da5eu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08da60;
P_0c08da60: /* original 70f6, guest PC 0x0c08da60 */
if(!s->budget--) { s->failed_pc=0x0c08da60u; return 0; }
r[0]+=0xfffffff6u;
goto P_0c08da62;
P_0c08da62: /* original 7ff0, guest PC 0x0c08da62 */
if(!s->budget--) { s->failed_pc=0x0c08da62u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c08da64;
P_0c08da64: /* original 0e34, guest PC 0x0c08da64 */
if(!s->budget--) { s->failed_pc=0x0c08da64u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08da66;
P_0c08da66: /* original 62f3, guest PC 0x0c08da66 */
if(!s->budget--) { s->failed_pc=0x0c08da66u; return 0; }
r[2]=r[15];
goto P_0c08da68;
P_0c08da68: /* original 720c, guest PC 0x0c08da68 */
if(!s->budget--) { s->failed_pc=0x0c08da68u; return 0; }
r[2]+=0x0000000cu;
goto P_0c08da6a;
P_0c08da6a: /* original 2f26, guest PC 0x0c08da6a */
if(!s->budget--) { s->failed_pc=0x0c08da6au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da6c;
P_0c08da6c: /* original 65d3, guest PC 0x0c08da6c */
if(!s->budget--) { s->failed_pc=0x0c08da6cu; return 0; }
r[5]=r[13];
goto P_0c08da6e;
P_0c08da6e: /* original 63f3, guest PC 0x0c08da6e */
if(!s->budget--) { s->failed_pc=0x0c08da6eu; return 0; }
r[3]=r[15];
goto P_0c08da70;
P_0c08da70: /* original 730c, guest PC 0x0c08da70 */
if(!s->budget--) { s->failed_pc=0x0c08da70u; return 0; }
r[3]+=0x0000000cu;
goto P_0c08da72;
P_0c08da72: /* original 2f36, guest PC 0x0c08da72 */
if(!s->budget--) { s->failed_pc=0x0c08da72u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da74;
P_0c08da74: /* original 66f3, guest PC 0x0c08da74 */
if(!s->budget--) { s->failed_pc=0x0c08da74u; return 0; }
r[6]=r[15];
goto P_0c08da76;
P_0c08da76: /* original 67f3, guest PC 0x0c08da76 */
if(!s->budget--) { s->failed_pc=0x0c08da76u; return 0; }
r[7]=r[15];
goto P_0c08da78;
P_0c08da78: /* original 7608, guest PC 0x0c08da78 */
if(!s->budget--) { s->failed_pc=0x0c08da78u; return 0; }
r[6]+=0x00000008u;
goto P_0c08da7a;
P_0c08da7a: /* original 770c, guest PC 0x0c08da7a */
if(!s->budget--) { s->failed_pc=0x0c08da7au; return 0; }
r[7]+=0x0000000cu;
goto P_0c08da7c;
P_0c08da7c: /* original b118, guest PC 0x0c08da7c */
if(!s->budget--) { s->failed_pc=0x0c08da7cu; return 0; }
target=code_base|0x0c08dcb0u; r[16]=code_base|0x0c08da80u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08da80u) { target=s->pc; goto dispatch; }
goto P_0c08da80;
P_0c08da7e: /* original 64c3, guest PC 0x0c08da7e */
if(!s->budget--) { s->failed_pc=0x0c08da7eu; return 0; }
r[4]=r[12];
goto P_0c08da80;
P_0c08da80: /* original 53f5, guest PC 0x0c08da80 */
if(!s->budget--) { s->failed_pc=0x0c08da80u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c08da82;
P_0c08da82: /* original 65c3, guest PC 0x0c08da82 */
if(!s->budget--) { s->failed_pc=0x0c08da82u; return 0; }
r[5]=r[12];
goto P_0c08da84;
P_0c08da84: /* original 66d3, guest PC 0x0c08da84 */
if(!s->budget--) { s->failed_pc=0x0c08da84u; return 0; }
r[6]=r[13];
goto P_0c08da86;
P_0c08da86: /* original 2f36, guest PC 0x0c08da86 */
if(!s->budget--) { s->failed_pc=0x0c08da86u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da88;
P_0c08da88: /* original 52f5, guest PC 0x0c08da88 */
if(!s->budget--) { s->failed_pc=0x0c08da88u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c08da8a;
P_0c08da8a: /* original 2f26, guest PC 0x0c08da8a */
if(!s->budget--) { s->failed_pc=0x0c08da8au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da8c;
P_0c08da8c: /* original 53f5, guest PC 0x0c08da8c */
if(!s->budget--) { s->failed_pc=0x0c08da8cu; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c08da8e;
P_0c08da8e: /* original 2f36, guest PC 0x0c08da8e */
if(!s->budget--) { s->failed_pc=0x0c08da8eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da90;
P_0c08da90: /* original 57f5, guest PC 0x0c08da90 */
if(!s->budget--) { s->failed_pc=0x0c08da90u; return 0; }
r[7]=read(ram,r[15]+20,4);
goto P_0c08da92;
P_0c08da92: /* original b228, guest PC 0x0c08da92 */
if(!s->budget--) { s->failed_pc=0x0c08da92u; return 0; }
target=code_base|0x0c08dee6u; r[16]=code_base|0x0c08da96u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08da96u) { target=s->pc; goto dispatch; }
goto P_0c08da96;
P_0c08da94: /* original 64e3, guest PC 0x0c08da94 */
if(!s->budget--) { s->failed_pc=0x0c08da94u; return 0; }
r[4]=r[14];
goto P_0c08da96;
P_0c08da96: /* original 7f24, guest PC 0x0c08da96 */
if(!s->budget--) { s->failed_pc=0x0c08da96u; return 0; }
r[15]+=0x00000024u;
goto P_0c08da98;
P_0c08da98: /* original 4f26, guest PC 0x0c08da98 */
if(!s->budget--) { s->failed_pc=0x0c08da98u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08da9a;
P_0c08da9a: /* original 6cf6, guest PC 0x0c08da9a */
if(!s->budget--) { s->failed_pc=0x0c08da9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08da9c;
P_0c08da9c: /* original 6df6, guest PC 0x0c08da9c */
if(!s->budget--) { s->failed_pc=0x0c08da9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08da9e;
P_0c08da9e: /* original 000b, guest PC 0x0c08da9e */
if(!s->budget--) { s->failed_pc=0x0c08da9eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08daa0: /* original 6ef6, guest PC 0x0c08daa0 */
if(!s->budget--) { s->failed_pc=0x0c08daa0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08daa2;
P_0c08daa2: /* original 901c, guest PC 0x0c08daa2 */
if(!s->budget--) { s->failed_pc=0x0c08daa2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dadeu,2);
goto P_0c08daa4;
P_0c08daa4: /* original 4f22, guest PC 0x0c08daa4 */
if(!s->budget--) { s->failed_pc=0x0c08daa4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08daa6;
P_0c08daa6: /* original 034d, guest PC 0x0c08daa6 */
if(!s->budget--) { s->failed_pc=0x0c08daa6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08daa8;
P_0c08daa8: /* original 7ff4, guest PC 0x0c08daa8 */
if(!s->budget--) { s->failed_pc=0x0c08daa8u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c08daaa;
P_0c08daaa: /* original 2f32, guest PC 0x0c08daaa */
if(!s->budget--) { s->failed_pc=0x0c08daaau; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08daac;
P_0c08daac: /* original 9018, guest PC 0x0c08daac */
if(!s->budget--) { s->failed_pc=0x0c08daacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dae0u,2);
goto P_0c08daae;
P_0c08daae: /* original 024d, guest PC 0x0c08daae */
if(!s->budget--) { s->failed_pc=0x0c08daaeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08dab0;
P_0c08dab0: /* original 1f21, guest PC 0x0c08dab0 */
if(!s->budget--) { s->failed_pc=0x0c08dab0u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c08dab2;
P_0c08dab2: /* original 9016, guest PC 0x0c08dab2 */
if(!s->budget--) { s->failed_pc=0x0c08dab2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dae2u,2);
goto P_0c08dab4;
P_0c08dab4: /* original 034d, guest PC 0x0c08dab4 */
if(!s->budget--) { s->failed_pc=0x0c08dab4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08dab6;
P_0c08dab6: /* original 1f32, guest PC 0x0c08dab6 */
if(!s->budget--) { s->failed_pc=0x0c08dab6u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c08dab8;
P_0c08dab8: /* original 9014, guest PC 0x0c08dab8 */
if(!s->budget--) { s->failed_pc=0x0c08dab8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dae4u,2);
goto P_0c08daba;
P_0c08daba: /* original 074d, guest PC 0x0c08daba */
if(!s->budget--) { s->failed_pc=0x0c08dabau; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08dabc;
P_0c08dabc: /* original 7002, guest PC 0x0c08dabc */
if(!s->budget--) { s->failed_pc=0x0c08dabcu; return 0; }
r[0]+=0x00000002u;
goto P_0c08dabe;
P_0c08dabe: /* original 064d, guest PC 0x0c08dabe */
if(!s->budget--) { s->failed_pc=0x0c08dabeu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08dac0;
P_0c08dac0: /* original 7002, guest PC 0x0c08dac0 */
if(!s->budget--) { s->failed_pc=0x0c08dac0u; return 0; }
r[0]+=0x00000002u;
goto P_0c08dac2;
P_0c08dac2: /* original 054d, guest PC 0x0c08dac2 */
if(!s->budget--) { s->failed_pc=0x0c08dac2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08dac4;
P_0c08dac4: /* original 2f56, guest PC 0x0c08dac4 */
if(!s->budget--) { s->failed_pc=0x0c08dac4u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dac6;
P_0c08dac6: /* original 2f66, guest PC 0x0c08dac6 */
if(!s->budget--) { s->failed_pc=0x0c08dac6u; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dac8;
P_0c08dac8: /* original 2f76, guest PC 0x0c08dac8 */
if(!s->budget--) { s->failed_pc=0x0c08dac8u; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08daca;
P_0c08daca: /* original 56f4, guest PC 0x0c08daca */
if(!s->budget--) { s->failed_pc=0x0c08dacau; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c08dacc;
P_0c08dacc: /* original 57f5, guest PC 0x0c08dacc */
if(!s->budget--) { s->failed_pc=0x0c08daccu; return 0; }
r[7]=read(ram,r[15]+20,4);
goto P_0c08dace;
P_0c08dace: /* original b20a, guest PC 0x0c08dace */
if(!s->budget--) { s->failed_pc=0x0c08daceu; return 0; }
target=code_base|0x0c08dee6u; r[16]=code_base|0x0c08dad2u;
r[5]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08dad2u) { target=s->pc; goto dispatch; }
goto P_0c08dad2;
P_0c08dad0: /* original 55f3, guest PC 0x0c08dad0 */
if(!s->budget--) { s->failed_pc=0x0c08dad0u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c08dad2;
P_0c08dad2: /* original 7f18, guest PC 0x0c08dad2 */
if(!s->budget--) { s->failed_pc=0x0c08dad2u; return 0; }
r[15]+=0x00000018u;
goto P_0c08dad4;
P_0c08dad4: /* original 4f26, guest PC 0x0c08dad4 */
if(!s->budget--) { s->failed_pc=0x0c08dad4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08dad6;
P_0c08dad6: /* original 000b, guest PC 0x0c08dad6 */
if(!s->budget--) { s->failed_pc=0x0c08dad6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c08dad8: /* original 0009, guest PC 0x0c08dad8 */
if(!s->budget--) { s->failed_pc=0x0c08dad8u; return 0; }
if(!vf3_matrix_family(0x0c08dadau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08dadau; return 0; } return 1;
P_0c08daf4: /* original 2fe6, guest PC 0x0c08daf4 */
if(!s->budget--) { s->failed_pc=0x0c08daf4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08daf6;
P_0c08daf6: /* original 6e43, guest PC 0x0c08daf6 */
if(!s->budget--) { s->failed_pc=0x0c08daf6u; return 0; }
r[14]=r[4];
goto P_0c08daf8;
P_0c08daf8: /* original 90a1, guest PC 0x0c08daf8 */
if(!s->budget--) { s->failed_pc=0x0c08daf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dc3eu,2);
goto P_0c08dafa;
P_0c08dafa: /* original 4f22, guest PC 0x0c08dafa */
if(!s->budget--) { s->failed_pc=0x0c08dafau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08dafc;
P_0c08dafc: /* original f356, guest PC 0x0c08dafc */
if(!s->budget--) { s->failed_pc=0x0c08dafcu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c08dafe;
P_0c08dafe: /* original e01c, guest PC 0x0c08dafe */
if(!s->budget--) { s->failed_pc=0x0c08dafeu; return 0; }
r[0]=0x0000001cu;
goto P_0c08db00;
P_0c08db00: /* original 7fe0, guest PC 0x0c08db00 */
if(!s->budget--) { s->failed_pc=0x0c08db00u; return 0; }
r[15]+=0xffffffe0u;
goto P_0c08db02;
P_0c08db02: /* original ff37, guest PC 0x0c08db02 */
if(!s->budget--) { s->failed_pc=0x0c08db02u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08db04;
P_0c08db04: /* original 66f3, guest PC 0x0c08db04 */
if(!s->budget--) { s->failed_pc=0x0c08db04u; return 0; }
r[6]=r[15];
goto P_0c08db06;
P_0c08db06: /* original 909b, guest PC 0x0c08db06 */
if(!s->budget--) { s->failed_pc=0x0c08db06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dc40u,2);
goto P_0c08db08;
P_0c08db08: /* original 7614, guest PC 0x0c08db08 */
if(!s->budget--) { s->failed_pc=0x0c08db08u; return 0; }
r[6]+=0x00000014u;
goto P_0c08db0a;
P_0c08db0a: /* original f356, guest PC 0x0c08db0a */
if(!s->budget--) { s->failed_pc=0x0c08db0au; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c08db0c;
P_0c08db0c: /* original e018, guest PC 0x0c08db0c */
if(!s->budget--) { s->failed_pc=0x0c08db0cu; return 0; }
r[0]=0x00000018u;
goto P_0c08db0e;
P_0c08db0e: /* original ff37, guest PC 0x0c08db0e */
if(!s->budget--) { s->failed_pc=0x0c08db0eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08db10;
P_0c08db10: /* original 9097, guest PC 0x0c08db10 */
if(!s->budget--) { s->failed_pc=0x0c08db10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dc42u,2);
goto P_0c08db12;
P_0c08db12: /* original f53c, guest PC 0x0c08db12 */
if(!s->budget--) { s->failed_pc=0x0c08db12u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c08db14;
P_0c08db14: /* original f656, guest PC 0x0c08db14 */
if(!s->budget--) { s->failed_pc=0x0c08db14u; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c08db16;
P_0c08db16: /* original e01c, guest PC 0x0c08db16 */
if(!s->budget--) { s->failed_pc=0x0c08db16u; return 0; }
r[0]=0x0000001cu;
goto P_0c08db18;
P_0c08db18: /* original 65f3, guest PC 0x0c08db18 */
if(!s->budget--) { s->failed_pc=0x0c08db18u; return 0; }
r[5]=r[15];
goto P_0c08db1a;
P_0c08db1a: /* original f4f6, guest PC 0x0c08db1a */
if(!s->budget--) { s->failed_pc=0x0c08db1au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08db1c;
P_0c08db1c: /* original 7510, guest PC 0x0c08db1c */
if(!s->budget--) { s->failed_pc=0x0c08db1cu; return 0; }
r[5]+=0x00000010u;
goto P_0c08db1e;
P_0c08db1e: /* original b157, guest PC 0x0c08db1e */
if(!s->budget--) { s->failed_pc=0x0c08db1eu; return 0; }
target=code_base|0x0c08ddd0u; r[16]=code_base|0x0c08db22u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08db22u) { target=s->pc; goto dispatch; }
goto P_0c08db22;
P_0c08db20: /* original 64e3, guest PC 0x0c08db20 */
if(!s->budget--) { s->failed_pc=0x0c08db20u; return 0; }
r[4]=r[14];
goto P_0c08db22;
P_0c08db22: /* original 62f3, guest PC 0x0c08db22 */
if(!s->budget--) { s->failed_pc=0x0c08db22u; return 0; }
r[2]=r[15];
goto P_0c08db24;
P_0c08db24: /* original 720c, guest PC 0x0c08db24 */
if(!s->budget--) { s->failed_pc=0x0c08db24u; return 0; }
r[2]+=0x0000000cu;
goto P_0c08db26;
P_0c08db26: /* original 2f26, guest PC 0x0c08db26 */
if(!s->budget--) { s->failed_pc=0x0c08db26u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08db28;
P_0c08db28: /* original 63f3, guest PC 0x0c08db28 */
if(!s->budget--) { s->failed_pc=0x0c08db28u; return 0; }
r[3]=r[15];
goto P_0c08db2a;
P_0c08db2a: /* original 730c, guest PC 0x0c08db2a */
if(!s->budget--) { s->failed_pc=0x0c08db2au; return 0; }
r[3]+=0x0000000cu;
goto P_0c08db2c;
P_0c08db2c: /* original 2f36, guest PC 0x0c08db2c */
if(!s->budget--) { s->failed_pc=0x0c08db2cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08db2e;
P_0c08db2e: /* original 66f3, guest PC 0x0c08db2e */
if(!s->budget--) { s->failed_pc=0x0c08db2eu; return 0; }
r[6]=r[15];
goto P_0c08db30;
P_0c08db30: /* original 55f7, guest PC 0x0c08db30 */
if(!s->budget--) { s->failed_pc=0x0c08db30u; return 0; }
r[5]=read(ram,r[15]+28,4);
goto P_0c08db32;
P_0c08db32: /* original 67f3, guest PC 0x0c08db32 */
if(!s->budget--) { s->failed_pc=0x0c08db32u; return 0; }
r[7]=r[15];
goto P_0c08db34;
P_0c08db34: /* original 7608, guest PC 0x0c08db34 */
if(!s->budget--) { s->failed_pc=0x0c08db34u; return 0; }
r[6]+=0x00000008u;
goto P_0c08db36;
P_0c08db36: /* original 770c, guest PC 0x0c08db36 */
if(!s->budget--) { s->failed_pc=0x0c08db36u; return 0; }
r[7]+=0x0000000cu;
goto P_0c08db38;
P_0c08db38: /* original b0ba, guest PC 0x0c08db38 */
if(!s->budget--) { s->failed_pc=0x0c08db38u; return 0; }
target=code_base|0x0c08dcb0u; r[16]=code_base|0x0c08db3cu;
r[4]=read(ram,r[15]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08db3cu) { target=s->pc; goto dispatch; }
goto P_0c08db3c;
P_0c08db3a: /* original 54f6, guest PC 0x0c08db3a */
if(!s->budget--) { s->failed_pc=0x0c08db3au; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c08db3c;
P_0c08db3c: /* original 62f3, guest PC 0x0c08db3c */
if(!s->budget--) { s->failed_pc=0x0c08db3cu; return 0; }
r[2]=r[15];
goto P_0c08db3e;
P_0c08db3e: /* original 7214, guest PC 0x0c08db3e */
if(!s->budget--) { s->failed_pc=0x0c08db3eu; return 0; }
r[2]+=0x00000014u;
goto P_0c08db40;
P_0c08db40: /* original 2f26, guest PC 0x0c08db40 */
if(!s->budget--) { s->failed_pc=0x0c08db40u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08db42;
P_0c08db42: /* original 66f3, guest PC 0x0c08db42 */
if(!s->budget--) { s->failed_pc=0x0c08db42u; return 0; }
r[6]=r[15];
goto P_0c08db44;
P_0c08db44: /* original 65f3, guest PC 0x0c08db44 */
if(!s->budget--) { s->failed_pc=0x0c08db44u; return 0; }
r[5]=r[15];
goto P_0c08db46;
P_0c08db46: /* original 67f3, guest PC 0x0c08db46 */
if(!s->budget--) { s->failed_pc=0x0c08db46u; return 0; }
r[7]=r[15];
goto P_0c08db48;
P_0c08db48: /* original 750c, guest PC 0x0c08db48 */
if(!s->budget--) { s->failed_pc=0x0c08db48u; return 0; }
r[5]+=0x0000000cu;
goto P_0c08db4a;
P_0c08db4a: /* original 7714, guest PC 0x0c08db4a */
if(!s->budget--) { s->failed_pc=0x0c08db4au; return 0; }
r[7]+=0x00000014u;
goto P_0c08db4c;
P_0c08db4c: /* original 7610, guest PC 0x0c08db4c */
if(!s->budget--) { s->failed_pc=0x0c08db4cu; return 0; }
r[6]+=0x00000010u;
goto P_0c08db4e;
P_0c08db4e: /* original b0e2, guest PC 0x0c08db4e */
if(!s->budget--) { s->failed_pc=0x0c08db4eu; return 0; }
target=code_base|0x0c08dd16u; r[16]=code_base|0x0c08db52u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08db52u) { target=s->pc; goto dispatch; }
goto P_0c08db52;
P_0c08db50: /* original 64e3, guest PC 0x0c08db50 */
if(!s->budget--) { s->failed_pc=0x0c08db50u; return 0; }
r[4]=r[14];
goto P_0c08db52;
P_0c08db52: /* original 52f6, guest PC 0x0c08db52 */
if(!s->budget--) { s->failed_pc=0x0c08db52u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c08db54;
P_0c08db54: /* original 2f26, guest PC 0x0c08db54 */
if(!s->budget--) { s->failed_pc=0x0c08db54u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08db56;
P_0c08db56: /* original 53f6, guest PC 0x0c08db56 */
if(!s->budget--) { s->failed_pc=0x0c08db56u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c08db58;
P_0c08db58: /* original 2f36, guest PC 0x0c08db58 */
if(!s->budget--) { s->failed_pc=0x0c08db58u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08db5a;
P_0c08db5a: /* original 52f6, guest PC 0x0c08db5a */
if(!s->budget--) { s->failed_pc=0x0c08db5au; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c08db5c;
P_0c08db5c: /* original 2f26, guest PC 0x0c08db5c */
if(!s->budget--) { s->failed_pc=0x0c08db5cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08db5e;
P_0c08db5e: /* original 55fa, guest PC 0x0c08db5e */
if(!s->budget--) { s->failed_pc=0x0c08db5eu; return 0; }
r[5]=read(ram,r[15]+40,4);
goto P_0c08db60;
P_0c08db60: /* original 56fb, guest PC 0x0c08db60 */
if(!s->budget--) { s->failed_pc=0x0c08db60u; return 0; }
r[6]=read(ram,r[15]+44,4);
goto P_0c08db62;
P_0c08db62: /* original 57f6, guest PC 0x0c08db62 */
if(!s->budget--) { s->failed_pc=0x0c08db62u; return 0; }
r[7]=read(ram,r[15]+24,4);
goto P_0c08db64;
P_0c08db64: /* original b1bf, guest PC 0x0c08db64 */
if(!s->budget--) { s->failed_pc=0x0c08db64u; return 0; }
target=code_base|0x0c08dee6u; r[16]=code_base|0x0c08db68u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08db68u) { target=s->pc; goto dispatch; }
goto P_0c08db68;
P_0c08db66: /* original 64e3, guest PC 0x0c08db66 */
if(!s->budget--) { s->failed_pc=0x0c08db66u; return 0; }
r[4]=r[14];
goto P_0c08db68;
P_0c08db68: /* original 7f38, guest PC 0x0c08db68 */
if(!s->budget--) { s->failed_pc=0x0c08db68u; return 0; }
r[15]+=0x00000038u;
goto P_0c08db6a;
P_0c08db6a: /* original 4f26, guest PC 0x0c08db6a */
if(!s->budget--) { s->failed_pc=0x0c08db6au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08db6c;
P_0c08db6c: /* original 000b, guest PC 0x0c08db6c */
if(!s->budget--) { s->failed_pc=0x0c08db6cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08db6e: /* original 6ef6, guest PC 0x0c08db6e */
if(!s->budget--) { s->failed_pc=0x0c08db6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08db70u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08db70u; return 0; } return 1;
P_0c08dbe4: /* original 2fe6, guest PC 0x0c08dbe4 */
if(!s->budget--) { s->failed_pc=0x0c08dbe4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dbe6;
P_0c08dbe6: /* original 6e43, guest PC 0x0c08dbe6 */
if(!s->budget--) { s->failed_pc=0x0c08dbe6u; return 0; }
r[14]=r[4];
goto P_0c08dbe8;
P_0c08dbe8: /* original 2fd6, guest PC 0x0c08dbe8 */
if(!s->budget--) { s->failed_pc=0x0c08dbe8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dbea;
P_0c08dbea: /* original 2fc6, guest PC 0x0c08dbea */
if(!s->budget--) { s->failed_pc=0x0c08dbeau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dbec;
P_0c08dbec: /* original 902a, guest PC 0x0c08dbec */
if(!s->budget--) { s->failed_pc=0x0c08dbecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dc44u,2);
goto P_0c08dbee;
P_0c08dbee: /* original 4f22, guest PC 0x0c08dbee */
if(!s->budget--) { s->failed_pc=0x0c08dbeeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08dbf0;
P_0c08dbf0: /* original 06ed, guest PC 0x0c08dbf0 */
if(!s->budget--) { s->failed_pc=0x0c08dbf0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08dbf2;
P_0c08dbf2: /* original 7002, guest PC 0x0c08dbf2 */
if(!s->budget--) { s->failed_pc=0x0c08dbf2u; return 0; }
r[0]+=0x00000002u;
goto P_0c08dbf4;
P_0c08dbf4: /* original 05ed, guest PC 0x0c08dbf4 */
if(!s->budget--) { s->failed_pc=0x0c08dbf4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08dbf6;
P_0c08dbf6: /* original 70fc, guest PC 0x0c08dbf6 */
if(!s->budget--) { s->failed_pc=0x0c08dbf6u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08dbf8;
P_0c08dbf8: /* original 04ed, guest PC 0x0c08dbf8 */
if(!s->budget--) { s->failed_pc=0x0c08dbf8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08dbfa;
P_0c08dbfa: /* original 7006, guest PC 0x0c08dbfa */
if(!s->budget--) { s->failed_pc=0x0c08dbfau; return 0; }
r[0]+=0x00000006u;
goto P_0c08dbfc;
P_0c08dbfc: /* original 0ded, guest PC 0x0c08dbfc */
if(!s->budget--) { s->failed_pc=0x0c08dbfcu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08dbfe;
P_0c08dbfe: /* original 7002, guest PC 0x0c08dbfe */
if(!s->budget--) { s->failed_pc=0x0c08dbfeu; return 0; }
r[0]+=0x00000002u;
goto P_0c08dc00;
P_0c08dc00: /* original 4410, guest PC 0x0c08dc00 */
if(!s->budget--) { s->failed_pc=0x0c08dc00u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c08dc02;
P_0c08dc02: /* original 7ff0, guest PC 0x0c08dc02 */
if(!s->budget--) { s->failed_pc=0x0c08dc02u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c08dc04;
P_0c08dc04: /* original 8f22, guest PC 0x0c08dc04 */
if(!s->budget--) { s->failed_pc=0x0c08dc04u; return 0; }
cond=r[17]&1u;
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(!cond) { goto P_0c08dc4c; }
goto P_0c08dc08;
P_0c08dc06: /* original 0ced, guest PC 0x0c08dc06 */
if(!s->budget--) { s->failed_pc=0x0c08dc06u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08dc08;
P_0c08dc08: /* original 901c, guest PC 0x0c08dc08 */
if(!s->budget--) { s->failed_pc=0x0c08dc08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dc44u,2);
goto P_0c08dc0a;
P_0c08dc0a: /* original e400, guest PC 0x0c08dc0a */
if(!s->budget--) { s->failed_pc=0x0c08dc0au; return 0; }
r[4]=0x00000000u;
goto P_0c08dc0c;
P_0c08dc0c: /* original 62f3, guest PC 0x0c08dc0c */
if(!s->budget--) { s->failed_pc=0x0c08dc0cu; return 0; }
r[2]=r[15];
goto P_0c08dc0e;
P_0c08dc0e: /* original e301, guest PC 0x0c08dc0e */
if(!s->budget--) { s->failed_pc=0x0c08dc0eu; return 0; }
r[3]=0x00000001u;
goto P_0c08dc10;
P_0c08dc10: /* original 0e45, guest PC 0x0c08dc10 */
if(!s->budget--) { s->failed_pc=0x0c08dc10u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08dc12;
P_0c08dc12: /* original 7002, guest PC 0x0c08dc12 */
if(!s->budget--) { s->failed_pc=0x0c08dc12u; return 0; }
r[0]+=0x00000002u;
goto P_0c08dc14;
P_0c08dc14: /* original 0e45, guest PC 0x0c08dc14 */
if(!s->budget--) { s->failed_pc=0x0c08dc14u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08dc16;
P_0c08dc16: /* original 70fc, guest PC 0x0c08dc16 */
if(!s->budget--) { s->failed_pc=0x0c08dc16u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08dc18;
P_0c08dc18: /* original 0e45, guest PC 0x0c08dc18 */
if(!s->budget--) { s->failed_pc=0x0c08dc18u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08dc1a;
P_0c08dc1a: /* original 70fe, guest PC 0x0c08dc1a */
if(!s->budget--) { s->failed_pc=0x0c08dc1au; return 0; }
r[0]+=0xfffffffeu;
goto P_0c08dc1c;
P_0c08dc1c: /* original 720c, guest PC 0x0c08dc1c */
if(!s->budget--) { s->failed_pc=0x0c08dc1cu; return 0; }
r[2]+=0x0000000cu;
goto P_0c08dc1e;
P_0c08dc1e: /* original 0e34, guest PC 0x0c08dc1e */
if(!s->budget--) { s->failed_pc=0x0c08dc1eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08dc20;
P_0c08dc20: /* original 2f26, guest PC 0x0c08dc20 */
if(!s->budget--) { s->failed_pc=0x0c08dc20u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc22;
P_0c08dc22: /* original 3d6c, guest PC 0x0c08dc22 */
if(!s->budget--) { s->failed_pc=0x0c08dc22u; return 0; }
r[13]+=r[6];
goto P_0c08dc24;
P_0c08dc24: /* original 63f3, guest PC 0x0c08dc24 */
if(!s->budget--) { s->failed_pc=0x0c08dc24u; return 0; }
r[3]=r[15];
goto P_0c08dc26;
P_0c08dc26: /* original 730c, guest PC 0x0c08dc26 */
if(!s->budget--) { s->failed_pc=0x0c08dc26u; return 0; }
r[3]+=0x0000000cu;
goto P_0c08dc28;
P_0c08dc28: /* original 2f36, guest PC 0x0c08dc28 */
if(!s->budget--) { s->failed_pc=0x0c08dc28u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc2a;
P_0c08dc2a: /* original 3c5c, guest PC 0x0c08dc2a */
if(!s->budget--) { s->failed_pc=0x0c08dc2au; return 0; }
r[12]+=r[5];
goto P_0c08dc2c;
P_0c08dc2c: /* original 66f3, guest PC 0x0c08dc2c */
if(!s->budget--) { s->failed_pc=0x0c08dc2cu; return 0; }
r[6]=r[15];
goto P_0c08dc2e;
P_0c08dc2e: /* original 67f3, guest PC 0x0c08dc2e */
if(!s->budget--) { s->failed_pc=0x0c08dc2eu; return 0; }
r[7]=r[15];
goto P_0c08dc30;
P_0c08dc30: /* original 65c3, guest PC 0x0c08dc30 */
if(!s->budget--) { s->failed_pc=0x0c08dc30u; return 0; }
r[5]=r[12];
goto P_0c08dc32;
P_0c08dc32: /* original 7608, guest PC 0x0c08dc32 */
if(!s->budget--) { s->failed_pc=0x0c08dc32u; return 0; }
r[6]+=0x00000008u;
goto P_0c08dc34;
P_0c08dc34: /* original 770c, guest PC 0x0c08dc34 */
if(!s->budget--) { s->failed_pc=0x0c08dc34u; return 0; }
r[7]+=0x0000000cu;
goto P_0c08dc36;
P_0c08dc36: /* original b03b, guest PC 0x0c08dc36 */
if(!s->budget--) { s->failed_pc=0x0c08dc36u; return 0; }
target=code_base|0x0c08dcb0u; r[16]=code_base|0x0c08dc3au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08dc3au) { target=s->pc; goto dispatch; }
goto P_0c08dc3a;
P_0c08dc38: /* original 64d3, guest PC 0x0c08dc38 */
if(!s->budget--) { s->failed_pc=0x0c08dc38u; return 0; }
r[4]=r[13];
goto P_0c08dc3a;
P_0c08dc3a: /* original a028, guest PC 0x0c08dc3a */
if(!s->budget--) { s->failed_pc=0x0c08dc3au; return 0; }
goto P_0c08dc8e;
P_0c08dc3c: /* original 0009, guest PC 0x0c08dc3c */
if(!s->budget--) { s->failed_pc=0x0c08dc3cu; return 0; }
if(!vf3_matrix_family(0x0c08dc3eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08dc3eu; return 0; } return 1;
P_0c08dc4c: /* original d242, guest PC 0x0c08dc4c */
if(!s->budget--) { s->failed_pc=0x0c08dc4cu; return 0; }
r[2]=read(ram,0x0c08dd58u,4);
goto P_0c08dc4e;
P_0c08dc4e: /* original 6163, guest PC 0x0c08dc4e */
if(!s->budget--) { s->failed_pc=0x0c08dc4eu; return 0; }
r[1]=r[6];
goto P_0c08dc50;
P_0c08dc50: /* original 420b, guest PC 0x0c08dc50 */
if(!s->budget--) { s->failed_pc=0x0c08dc50u; return 0; }
target=r[2];
r[16]=code_base|0x0c08dc54u;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08dc54u) { target=s->pc; goto dispatch; }
goto P_0c08dc54;
P_0c08dc52: /* original 6043, guest PC 0x0c08dc52 */
if(!s->budget--) { s->failed_pc=0x0c08dc52u; return 0; }
r[0]=r[4];
goto P_0c08dc54;
P_0c08dc54: /* original d340, guest PC 0x0c08dc54 */
if(!s->budget--) { s->failed_pc=0x0c08dc54u; return 0; }
r[3]=read(ram,0x0c08dd58u,4);
goto P_0c08dc56;
P_0c08dc56: /* original 6153, guest PC 0x0c08dc56 */
if(!s->budget--) { s->failed_pc=0x0c08dc56u; return 0; }
r[1]=r[5];
goto P_0c08dc58;
P_0c08dc58: /* original 6703, guest PC 0x0c08dc58 */
if(!s->budget--) { s->failed_pc=0x0c08dc58u; return 0; }
r[7]=r[0];
goto P_0c08dc5a;
P_0c08dc5a: /* original 430b, guest PC 0x0c08dc5a */
if(!s->budget--) { s->failed_pc=0x0c08dc5au; return 0; }
target=r[3];
r[16]=code_base|0x0c08dc5eu;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08dc5eu) { target=s->pc; goto dispatch; }
goto P_0c08dc5e;
P_0c08dc5c: /* original 6043, guest PC 0x0c08dc5c */
if(!s->budget--) { s->failed_pc=0x0c08dc5cu; return 0; }
r[0]=r[4];
goto P_0c08dc5e;
P_0c08dc5e: /* original 6203, guest PC 0x0c08dc5e */
if(!s->budget--) { s->failed_pc=0x0c08dc5eu; return 0; }
r[2]=r[0];
goto P_0c08dc60;
P_0c08dc60: /* original 9071, guest PC 0x0c08dc60 */
if(!s->budget--) { s->failed_pc=0x0c08dc60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dd46u,2);
goto P_0c08dc62;
P_0c08dc62: /* original 63f3, guest PC 0x0c08dc62 */
if(!s->budget--) { s->failed_pc=0x0c08dc62u; return 0; }
r[3]=r[15];
goto P_0c08dc64;
P_0c08dc64: /* original 730c, guest PC 0x0c08dc64 */
if(!s->budget--) { s->failed_pc=0x0c08dc64u; return 0; }
r[3]+=0x0000000cu;
goto P_0c08dc66;
P_0c08dc66: /* original 0e45, guest PC 0x0c08dc66 */
if(!s->budget--) { s->failed_pc=0x0c08dc66u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08dc68;
P_0c08dc68: /* original 3528, guest PC 0x0c08dc68 */
if(!s->budget--) { s->failed_pc=0x0c08dc68u; return 0; }
r[5]-=r[2];
goto P_0c08dc6a;
P_0c08dc6a: /* original 3c2c, guest PC 0x0c08dc6a */
if(!s->budget--) { s->failed_pc=0x0c08dc6au; return 0; }
r[12]+=r[2];
goto P_0c08dc6c;
P_0c08dc6c: /* original 3678, guest PC 0x0c08dc6c */
if(!s->budget--) { s->failed_pc=0x0c08dc6cu; return 0; }
r[6]-=r[7];
goto P_0c08dc6e;
P_0c08dc6e: /* original 7002, guest PC 0x0c08dc6e */
if(!s->budget--) { s->failed_pc=0x0c08dc6eu; return 0; }
r[0]+=0x00000002u;
goto P_0c08dc70;
P_0c08dc70: /* original 0e65, guest PC 0x0c08dc70 */
if(!s->budget--) { s->failed_pc=0x0c08dc70u; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c08dc72;
P_0c08dc72: /* original 3d7c, guest PC 0x0c08dc72 */
if(!s->budget--) { s->failed_pc=0x0c08dc72u; return 0; }
r[13]+=r[7];
goto P_0c08dc74;
P_0c08dc74: /* original 7002, guest PC 0x0c08dc74 */
if(!s->budget--) { s->failed_pc=0x0c08dc74u; return 0; }
r[0]+=0x00000002u;
goto P_0c08dc76;
P_0c08dc76: /* original 0e55, guest PC 0x0c08dc76 */
if(!s->budget--) { s->failed_pc=0x0c08dc76u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c08dc78;
P_0c08dc78: /* original 65c3, guest PC 0x0c08dc78 */
if(!s->budget--) { s->failed_pc=0x0c08dc78u; return 0; }
r[5]=r[12];
goto P_0c08dc7a;
P_0c08dc7a: /* original 2f36, guest PC 0x0c08dc7a */
if(!s->budget--) { s->failed_pc=0x0c08dc7au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc7c;
P_0c08dc7c: /* original 62f3, guest PC 0x0c08dc7c */
if(!s->budget--) { s->failed_pc=0x0c08dc7cu; return 0; }
r[2]=r[15];
goto P_0c08dc7e;
P_0c08dc7e: /* original 720c, guest PC 0x0c08dc7e */
if(!s->budget--) { s->failed_pc=0x0c08dc7eu; return 0; }
r[2]+=0x0000000cu;
goto P_0c08dc80;
P_0c08dc80: /* original 2f26, guest PC 0x0c08dc80 */
if(!s->budget--) { s->failed_pc=0x0c08dc80u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc82;
P_0c08dc82: /* original 66f3, guest PC 0x0c08dc82 */
if(!s->budget--) { s->failed_pc=0x0c08dc82u; return 0; }
r[6]=r[15];
goto P_0c08dc84;
P_0c08dc84: /* original 67f3, guest PC 0x0c08dc84 */
if(!s->budget--) { s->failed_pc=0x0c08dc84u; return 0; }
r[7]=r[15];
goto P_0c08dc86;
P_0c08dc86: /* original 7608, guest PC 0x0c08dc86 */
if(!s->budget--) { s->failed_pc=0x0c08dc86u; return 0; }
r[6]+=0x00000008u;
goto P_0c08dc88;
P_0c08dc88: /* original 770c, guest PC 0x0c08dc88 */
if(!s->budget--) { s->failed_pc=0x0c08dc88u; return 0; }
r[7]+=0x0000000cu;
goto P_0c08dc8a;
P_0c08dc8a: /* original b011, guest PC 0x0c08dc8a */
if(!s->budget--) { s->failed_pc=0x0c08dc8au; return 0; }
target=code_base|0x0c08dcb0u; r[16]=code_base|0x0c08dc8eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08dc8eu) { target=s->pc; goto dispatch; }
goto P_0c08dc8e;
P_0c08dc8c: /* original 64d3, guest PC 0x0c08dc8c */
if(!s->budget--) { s->failed_pc=0x0c08dc8cu; return 0; }
r[4]=r[13];
goto P_0c08dc8e;
P_0c08dc8e: /* original 52f5, guest PC 0x0c08dc8e */
if(!s->budget--) { s->failed_pc=0x0c08dc8eu; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c08dc90;
P_0c08dc90: /* original 65d3, guest PC 0x0c08dc90 */
if(!s->budget--) { s->failed_pc=0x0c08dc90u; return 0; }
r[5]=r[13];
goto P_0c08dc92;
P_0c08dc92: /* original 66c3, guest PC 0x0c08dc92 */
if(!s->budget--) { s->failed_pc=0x0c08dc92u; return 0; }
r[6]=r[12];
goto P_0c08dc94;
P_0c08dc94: /* original 2f26, guest PC 0x0c08dc94 */
if(!s->budget--) { s->failed_pc=0x0c08dc94u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc96;
P_0c08dc96: /* original 53f5, guest PC 0x0c08dc96 */
if(!s->budget--) { s->failed_pc=0x0c08dc96u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c08dc98;
P_0c08dc98: /* original 2f36, guest PC 0x0c08dc98 */
if(!s->budget--) { s->failed_pc=0x0c08dc98u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc9a;
P_0c08dc9a: /* original 52f5, guest PC 0x0c08dc9a */
if(!s->budget--) { s->failed_pc=0x0c08dc9au; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c08dc9c;
P_0c08dc9c: /* original 2f26, guest PC 0x0c08dc9c */
if(!s->budget--) { s->failed_pc=0x0c08dc9cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc9e;
P_0c08dc9e: /* original 57f5, guest PC 0x0c08dc9e */
if(!s->budget--) { s->failed_pc=0x0c08dc9eu; return 0; }
r[7]=read(ram,r[15]+20,4);
goto P_0c08dca0;
P_0c08dca0: /* original b121, guest PC 0x0c08dca0 */
if(!s->budget--) { s->failed_pc=0x0c08dca0u; return 0; }
target=code_base|0x0c08dee6u; r[16]=code_base|0x0c08dca4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08dca4u) { target=s->pc; goto dispatch; }
goto P_0c08dca4;
P_0c08dca2: /* original 64e3, guest PC 0x0c08dca2 */
if(!s->budget--) { s->failed_pc=0x0c08dca2u; return 0; }
r[4]=r[14];
goto P_0c08dca4;
P_0c08dca4: /* original 7f24, guest PC 0x0c08dca4 */
if(!s->budget--) { s->failed_pc=0x0c08dca4u; return 0; }
r[15]+=0x00000024u;
goto P_0c08dca6;
P_0c08dca6: /* original 4f26, guest PC 0x0c08dca6 */
if(!s->budget--) { s->failed_pc=0x0c08dca6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08dca8;
P_0c08dca8: /* original 6cf6, guest PC 0x0c08dca8 */
if(!s->budget--) { s->failed_pc=0x0c08dca8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08dcaa;
P_0c08dcaa: /* original 6df6, guest PC 0x0c08dcaa */
if(!s->budget--) { s->failed_pc=0x0c08dcaau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08dcac;
P_0c08dcac: /* original 000b, guest PC 0x0c08dcac */
if(!s->budget--) { s->failed_pc=0x0c08dcacu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08dcae: /* original 6ef6, guest PC 0x0c08dcae */
if(!s->budget--) { s->failed_pc=0x0c08dcaeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08dcb0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
