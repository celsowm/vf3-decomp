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
int vf3_away_batch80_adapter_12(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09ee18u: goto P_0c09ee18;
case 0x0c09ee1au: goto P_0c09ee1a;
case 0x0c09ee1cu: goto P_0c09ee1c;
case 0x0c09ee1eu: goto P_0c09ee1e;
case 0x0c09ee20u: goto P_0c09ee20;
case 0x0c09ee22u: goto P_0c09ee22;
case 0x0c09ee24u: goto P_0c09ee24;
case 0x0c09ee26u: goto P_0c09ee26;
case 0x0c09ee28u: goto P_0c09ee28;
case 0x0c09ee2au: goto P_0c09ee2a;
case 0x0c09ee2cu: goto P_0c09ee2c;
case 0x0c09ee2eu: goto P_0c09ee2e;
case 0x0c09ee30u: goto P_0c09ee30;
case 0x0c09ee32u: goto P_0c09ee32;
case 0x0c09ee34u: goto P_0c09ee34;
case 0x0c09ee36u: goto P_0c09ee36;
case 0x0c09ee38u: goto P_0c09ee38;
case 0x0c09ee3au: goto P_0c09ee3a;
case 0x0c09ee3cu: goto P_0c09ee3c;
case 0x0c09ee3eu: goto P_0c09ee3e;
case 0x0c09ee40u: goto P_0c09ee40;
case 0x0c09ee42u: goto P_0c09ee42;
case 0x0c09ee44u: goto P_0c09ee44;
case 0x0c09ee46u: goto P_0c09ee46;
case 0x0c09ee48u: goto P_0c09ee48;
case 0x0c09ee4au: goto P_0c09ee4a;
case 0x0c09ee4cu: goto P_0c09ee4c;
case 0x0c09ee4eu: goto P_0c09ee4e;
case 0x0c09ee50u: goto P_0c09ee50;
case 0x0c09ee52u: goto P_0c09ee52;
case 0x0c09ee54u: goto P_0c09ee54;
case 0x0c09ee56u: goto P_0c09ee56;
case 0x0c09ee58u: goto P_0c09ee58;
case 0x0c09ee5au: goto P_0c09ee5a;
case 0x0c09ee5cu: goto P_0c09ee5c;
case 0x0c09ee5eu: goto P_0c09ee5e;
case 0x0c09ee60u: goto P_0c09ee60;
case 0x0c09ee62u: goto P_0c09ee62;
case 0x0c09ee64u: goto P_0c09ee64;
case 0x0c09ee66u: goto P_0c09ee66;
case 0x0c09ee68u: goto P_0c09ee68;
case 0x0c09ee6au: goto P_0c09ee6a;
case 0x0c09ee6cu: goto P_0c09ee6c;
case 0x0c09ee6eu: goto P_0c09ee6e;
case 0x0c09ee70u: goto P_0c09ee70;
case 0x0c09ee72u: goto P_0c09ee72;
case 0x0c09ee74u: goto P_0c09ee74;
case 0x0c09ee76u: goto P_0c09ee76;
case 0x0c09ee78u: goto P_0c09ee78;
case 0x0c09ee7au: goto P_0c09ee7a;
case 0x0c09ee7cu: goto P_0c09ee7c;
case 0x0c09ee7eu: goto P_0c09ee7e;
case 0x0c09ee80u: goto P_0c09ee80;
case 0x0c09ee82u: goto P_0c09ee82;
case 0x0c09ee84u: goto P_0c09ee84;
case 0x0c09ee86u: goto P_0c09ee86;
case 0x0c09ee88u: goto P_0c09ee88;
case 0x0c09ee8au: goto P_0c09ee8a;
case 0x0c09ee8cu: goto P_0c09ee8c;
case 0x0c09ee8eu: goto P_0c09ee8e;
case 0x0c09ee90u: goto P_0c09ee90;
case 0x0c09ee92u: goto P_0c09ee92;
case 0x0c09ee94u: goto P_0c09ee94;
case 0x0c09ee96u: goto P_0c09ee96;
case 0x0c09ee98u: goto P_0c09ee98;
case 0x0c09ee9au: goto P_0c09ee9a;
case 0x0c09ee9cu: goto P_0c09ee9c;
case 0x0c09ee9eu: goto P_0c09ee9e;
case 0x0c09eea0u: goto P_0c09eea0;
case 0x0c09eea2u: goto P_0c09eea2;
case 0x0c09eea4u: goto P_0c09eea4;
case 0x0c09eea6u: goto P_0c09eea6;
case 0x0c09eea8u: goto P_0c09eea8;
case 0x0c09eeaau: goto P_0c09eeaa;
case 0x0c09eeacu: goto P_0c09eeac;
case 0x0c09eeaeu: goto P_0c09eeae;
case 0x0c09eeb0u: goto P_0c09eeb0;
case 0x0c09eeb2u: goto P_0c09eeb2;
case 0x0c09eeb4u: goto P_0c09eeb4;
case 0x0c09eeb6u: goto P_0c09eeb6;
case 0x0c09eeb8u: goto P_0c09eeb8;
case 0x0c09eebau: goto P_0c09eeba;
case 0x0c09eebcu: goto P_0c09eebc;
case 0x0c09eebeu: goto P_0c09eebe;
case 0x0c09eec0u: goto P_0c09eec0;
case 0x0c09eec2u: goto P_0c09eec2;
case 0x0c09eec4u: goto P_0c09eec4;
case 0x0c09eec6u: goto P_0c09eec6;
case 0x0c09eec8u: goto P_0c09eec8;
case 0x0c09eecau: goto P_0c09eeca;
case 0x0c09eeccu: goto P_0c09eecc;
case 0x0c09eeceu: goto P_0c09eece;
case 0x0c09eed0u: goto P_0c09eed0;
case 0x0c09eed2u: goto P_0c09eed2;
case 0x0c09eed4u: goto P_0c09eed4;
case 0x0c09eed6u: goto P_0c09eed6;
case 0x0c09eed8u: goto P_0c09eed8;
case 0x0c09eedau: goto P_0c09eeda;
case 0x0c09eedcu: goto P_0c09eedc;
case 0x0c09eedeu: goto P_0c09eede;
case 0x0c09eee0u: goto P_0c09eee0;
case 0x0c09eee2u: goto P_0c09eee2;
case 0x0c09eee4u: goto P_0c09eee4;
case 0x0c09eee6u: goto P_0c09eee6;
case 0x0c09eee8u: goto P_0c09eee8;
case 0x0c09eeeau: goto P_0c09eeea;
case 0x0c09eeecu: goto P_0c09eeec;
case 0x0c09eeeeu: goto P_0c09eeee;
case 0x0c09eef0u: goto P_0c09eef0;
case 0x0c09eef2u: goto P_0c09eef2;
case 0x0c09eef4u: goto P_0c09eef4;
case 0x0c09eef6u: goto P_0c09eef6;
case 0x0c09eef8u: goto P_0c09eef8;
case 0x0c09eefau: goto P_0c09eefa;
case 0x0c09eefcu: goto P_0c09eefc;
case 0x0c09eefeu: goto P_0c09eefe;
case 0x0c09ef00u: goto P_0c09ef00;
case 0x0c09ef02u: goto P_0c09ef02;
case 0x0c09ef04u: goto P_0c09ef04;
case 0x0c09ef06u: goto P_0c09ef06;
case 0x0c09ef08u: goto P_0c09ef08;
case 0x0c09ef0au: goto P_0c09ef0a;
case 0x0c09ef0cu: goto P_0c09ef0c;
case 0x0c09ef0eu: goto P_0c09ef0e;
case 0x0c09ef10u: goto P_0c09ef10;
case 0x0c09ef12u: goto P_0c09ef12;
case 0x0c09ef14u: goto P_0c09ef14;
case 0x0c09ef16u: goto P_0c09ef16;
case 0x0c09ef18u: goto P_0c09ef18;
case 0x0c09ef1au: goto P_0c09ef1a;
case 0x0c09ef1cu: goto P_0c09ef1c;
case 0x0c09ef1eu: goto P_0c09ef1e;
case 0x0c09ef20u: goto P_0c09ef20;
case 0x0c09ef22u: goto P_0c09ef22;
case 0x0c09ef24u: goto P_0c09ef24;
case 0x0c09ef26u: goto P_0c09ef26;
case 0x0c09ef28u: goto P_0c09ef28;
case 0x0c09ef78u: goto P_0c09ef78;
case 0x0c09ef7au: goto P_0c09ef7a;
case 0x0c09ef7cu: goto P_0c09ef7c;
case 0x0c09ef7eu: goto P_0c09ef7e;
case 0x0c09ef80u: goto P_0c09ef80;
case 0x0c09ef82u: goto P_0c09ef82;
case 0x0c09ef84u: goto P_0c09ef84;
case 0x0c09ef86u: goto P_0c09ef86;
case 0x0c09ef88u: goto P_0c09ef88;
case 0x0c09ef8au: goto P_0c09ef8a;
case 0x0c09ef8cu: goto P_0c09ef8c;
case 0x0c09ef8eu: goto P_0c09ef8e;
case 0x0c09ef90u: goto P_0c09ef90;
case 0x0c09ef92u: goto P_0c09ef92;
case 0x0c09ef94u: goto P_0c09ef94;
case 0x0c09ef96u: goto P_0c09ef96;
case 0x0c09ef98u: goto P_0c09ef98;
case 0x0c09ef9au: goto P_0c09ef9a;
case 0x0c09ef9cu: goto P_0c09ef9c;
case 0x0c09ef9eu: goto P_0c09ef9e;
case 0x0c09efa0u: goto P_0c09efa0;
case 0x0c09efa2u: goto P_0c09efa2;
case 0x0c09efa4u: goto P_0c09efa4;
case 0x0c09efa6u: goto P_0c09efa6;
case 0x0c09efa8u: goto P_0c09efa8;
case 0x0c09efaau: goto P_0c09efaa;
case 0x0c09efacu: goto P_0c09efac;
case 0x0c09efaeu: goto P_0c09efae;
case 0x0c09efb0u: goto P_0c09efb0;
case 0x0c09efb2u: goto P_0c09efb2;
case 0x0c09efb4u: goto P_0c09efb4;
case 0x0c09efb6u: goto P_0c09efb6;
case 0x0c09efb8u: goto P_0c09efb8;
case 0x0c09efbau: goto P_0c09efba;
case 0x0c09efbcu: goto P_0c09efbc;
case 0x0c09efbeu: goto P_0c09efbe;
case 0x0c09efc0u: goto P_0c09efc0;
case 0x0c09efc2u: goto P_0c09efc2;
case 0x0c09efc4u: goto P_0c09efc4;
case 0x0c09efc6u: goto P_0c09efc6;
case 0x0c09efc8u: goto P_0c09efc8;
case 0x0c09efcau: goto P_0c09efca;
case 0x0c09efccu: goto P_0c09efcc;
case 0x0c09efd8u: goto P_0c09efd8;
case 0x0c09efdau: goto P_0c09efda;
case 0x0c09efdcu: goto P_0c09efdc;
case 0x0c09efdeu: goto P_0c09efde;
case 0x0c09efe0u: goto P_0c09efe0;
case 0x0c09efe2u: goto P_0c09efe2;
case 0x0c09efe4u: goto P_0c09efe4;
case 0x0c09efe6u: goto P_0c09efe6;
case 0x0c09efe8u: goto P_0c09efe8;
case 0x0c09efeau: goto P_0c09efea;
case 0x0c09efecu: goto P_0c09efec;
case 0x0c09efeeu: goto P_0c09efee;
case 0x0c09eff0u: goto P_0c09eff0;
case 0x0c09eff2u: goto P_0c09eff2;
case 0x0c09eff4u: goto P_0c09eff4;
case 0x0c09eff6u: goto P_0c09eff6;
case 0x0c09eff8u: goto P_0c09eff8;
case 0x0c09effau: goto P_0c09effa;
case 0x0c09effcu: goto P_0c09effc;
case 0x0c09effeu: goto P_0c09effe;
case 0x0c09f000u: goto P_0c09f000;
case 0x0c09f002u: goto P_0c09f002;
case 0x0c09f004u: goto P_0c09f004;
case 0x0c09f006u: goto P_0c09f006;
case 0x0c09f008u: goto P_0c09f008;
case 0x0c09f00au: goto P_0c09f00a;
case 0x0c09f00cu: goto P_0c09f00c;
case 0x0c09f00eu: goto P_0c09f00e;
case 0x0c09f010u: goto P_0c09f010;
case 0x0c09f012u: goto P_0c09f012;
case 0x0c09f014u: goto P_0c09f014;
case 0x0c09f016u: goto P_0c09f016;
case 0x0c09f018u: goto P_0c09f018;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09ee18: /* original 2fe6, guest PC 0x0c09ee18 */
if(!s->budget--) { s->failed_pc=0x0c09ee18u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ee1a;
P_0c09ee1a: /* original 6e43, guest PC 0x0c09ee1a */
if(!s->budget--) { s->failed_pc=0x0c09ee1au; return 0; }
r[14]=r[4];
goto P_0c09ee1c;
P_0c09ee1c: /* original 2fd6, guest PC 0x0c09ee1c */
if(!s->budget--) { s->failed_pc=0x0c09ee1cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ee1e;
P_0c09ee1e: /* original e210, guest PC 0x0c09ee1e */
if(!s->budget--) { s->failed_pc=0x0c09ee1eu; return 0; }
r[2]=0x00000010u;
goto P_0c09ee20;
P_0c09ee20: /* original 2fc6, guest PC 0x0c09ee20 */
if(!s->budget--) { s->failed_pc=0x0c09ee20u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ee22;
P_0c09ee22: /* original 6c53, guest PC 0x0c09ee22 */
if(!s->budget--) { s->failed_pc=0x0c09ee22u; return 0; }
r[12]=r[5];
goto P_0c09ee24;
P_0c09ee24: /* original 2fb6, guest PC 0x0c09ee24 */
if(!s->budget--) { s->failed_pc=0x0c09ee24u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ee26;
P_0c09ee26: /* original 4f22, guest PC 0x0c09ee26 */
if(!s->budget--) { s->failed_pc=0x0c09ee26u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09ee28;
P_0c09ee28: /* original 9380, guest PC 0x0c09ee28 */
if(!s->budget--) { s->failed_pc=0x0c09ee28u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2cu,2);
goto P_0c09ee2a;
P_0c09ee2a: /* original 33ec, guest PC 0x0c09ee2a */
if(!s->budget--) { s->failed_pc=0x0c09ee2au; return 0; }
r[3]+=r[14];
goto P_0c09ee2c;
P_0c09ee2c: /* original 7ff0, guest PC 0x0c09ee2c */
if(!s->budget--) { s->failed_pc=0x0c09ee2cu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09ee2e;
P_0c09ee2e: /* original 2f32, guest PC 0x0c09ee2e */
if(!s->budget--) { s->failed_pc=0x0c09ee2eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09ee30;
P_0c09ee30: /* original 907d, guest PC 0x0c09ee30 */
if(!s->budget--) { s->failed_pc=0x0c09ee30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2eu,2);
goto P_0c09ee32;
P_0c09ee32: /* original 937b, guest PC 0x0c09ee32 */
if(!s->budget--) { s->failed_pc=0x0c09ee32u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2cu,2);
goto P_0c09ee34;
P_0c09ee34: /* original 0bec, guest PC 0x0c09ee34 */
if(!s->budget--) { s->failed_pc=0x0c09ee34u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09ee36;
P_0c09ee36: /* original 33ec, guest PC 0x0c09ee36 */
if(!s->budget--) { s->failed_pc=0x0c09ee36u; return 0; }
r[3]+=r[14];
goto P_0c09ee38;
P_0c09ee38: /* original 6bbc, guest PC 0x0c09ee38 */
if(!s->budget--) { s->failed_pc=0x0c09ee38u; return 0; }
r[11]=r[11]&255u;
goto P_0c09ee3a;
P_0c09ee3a: /* original 6db3, guest PC 0x0c09ee3a */
if(!s->budget--) { s->failed_pc=0x0c09ee3au; return 0; }
r[13]=r[11];
goto P_0c09ee3c;
P_0c09ee3c: /* original 22d8, guest PC 0x0c09ee3c */
if(!s->budget--) { s->failed_pc=0x0c09ee3cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c09ee3e;
P_0c09ee3e: /* original 8f02, guest PC 0x0c09ee3e */
if(!s->budget--) { s->failed_pc=0x0c09ee3eu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c09ee46; }
goto P_0c09ee42;
P_0c09ee40: /* original 2f32, guest PC 0x0c09ee40 */
if(!s->budget--) { s->failed_pc=0x0c09ee40u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09ee42;
P_0c09ee42: /* original a099, guest PC 0x0c09ee42 */
if(!s->budget--) { s->failed_pc=0x0c09ee42u; return 0; }
goto P_0c09ef78;
P_0c09ee44: /* original 0009, guest PC 0x0c09ee44 */
if(!s->budget--) { s->failed_pc=0x0c09ee44u; return 0; }
goto P_0c09ee46;
P_0c09ee46: /* original 9373, guest PC 0x0c09ee46 */
if(!s->budget--) { s->failed_pc=0x0c09ee46u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef30u,2);
goto P_0c09ee48;
P_0c09ee48: /* original 9071, guest PC 0x0c09ee48 */
if(!s->budget--) { s->failed_pc=0x0c09ee48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2eu,2);
goto P_0c09ee4a;
P_0c09ee4a: /* original 2b39, guest PC 0x0c09ee4a */
if(!s->budget--) { s->failed_pc=0x0c09ee4au; return 0; }
r[11]&=r[3];
goto P_0c09ee4c;
P_0c09ee4c: /* original 0eb4, guest PC 0x0c09ee4c */
if(!s->budget--) { s->failed_pc=0x0c09ee4cu; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c09ee4e;
P_0c09ee4e: /* original 956d, guest PC 0x0c09ee4e */
if(!s->budget--) { s->failed_pc=0x0c09ee4eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2cu,2);
goto P_0c09ee50;
P_0c09ee50: /* original d23b, guest PC 0x0c09ee50 */
if(!s->budget--) { s->failed_pc=0x0c09ee50u; return 0; }
r[2]=read(ram,0x0c09ef40u,4);
goto P_0c09ee52;
P_0c09ee52: /* original 35ec, guest PC 0x0c09ee52 */
if(!s->budget--) { s->failed_pc=0x0c09ee52u; return 0; }
r[5]+=r[14];
goto P_0c09ee54;
P_0c09ee54: /* original 420b, guest PC 0x0c09ee54 */
if(!s->budget--) { s->failed_pc=0x0c09ee54u; return 0; }
target=r[2];
r[16]=code_base|0x0c09ee58u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ee58u) { target=s->pc; goto dispatch; }
goto P_0c09ee58;
P_0c09ee56: /* original 64e3, guest PC 0x0c09ee56 */
if(!s->budget--) { s->failed_pc=0x0c09ee56u; return 0; }
r[4]=r[14];
goto P_0c09ee58;
P_0c09ee58: /* original d33a, guest PC 0x0c09ee58 */
if(!s->budget--) { s->failed_pc=0x0c09ee58u; return 0; }
r[3]=read(ram,0x0c09ef44u,4);
goto P_0c09ee5a;
P_0c09ee5a: /* original 65f3, guest PC 0x0c09ee5a */
if(!s->budget--) { s->failed_pc=0x0c09ee5au; return 0; }
r[5]=r[15];
goto P_0c09ee5c;
P_0c09ee5c: /* original 66c3, guest PC 0x0c09ee5c */
if(!s->budget--) { s->failed_pc=0x0c09ee5cu; return 0; }
r[6]=r[12];
goto P_0c09ee5e;
P_0c09ee5e: /* original 430b, guest PC 0x0c09ee5e */
if(!s->budget--) { s->failed_pc=0x0c09ee5eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09ee62u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ee62u) { target=s->pc; goto dispatch; }
goto P_0c09ee62;
P_0c09ee60: /* original 64e3, guest PC 0x0c09ee60 */
if(!s->budget--) { s->failed_pc=0x0c09ee60u; return 0; }
r[4]=r[14];
goto P_0c09ee62;
P_0c09ee62: /* original d239, guest PC 0x0c09ee62 */
if(!s->budget--) { s->failed_pc=0x0c09ee62u; return 0; }
r[2]=read(ram,0x0c09ef48u,4);
goto P_0c09ee64;
P_0c09ee64: /* original 420b, guest PC 0x0c09ee64 */
if(!s->budget--) { s->failed_pc=0x0c09ee64u; return 0; }
target=r[2];
r[16]=code_base|0x0c09ee68u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ee68u) { target=s->pc; goto dispatch; }
goto P_0c09ee68;
P_0c09ee66: /* original 64e3, guest PC 0x0c09ee66 */
if(!s->budget--) { s->failed_pc=0x0c09ee66u; return 0; }
r[4]=r[14];
goto P_0c09ee68;
P_0c09ee68: /* original 62e2, guest PC 0x0c09ee68 */
if(!s->budget--) { s->failed_pc=0x0c09ee68u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c09ee6a;
P_0c09ee6a: /* original d338, guest PC 0x0c09ee6a */
if(!s->budget--) { s->failed_pc=0x0c09ee6au; return 0; }
r[3]=read(ram,0x0c09ef4cu,4);
goto P_0c09ee6c;
P_0c09ee6c: /* original 2238, guest PC 0x0c09ee6c */
if(!s->budget--) { s->failed_pc=0x0c09ee6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09ee6e;
P_0c09ee6e: /* original 8909, guest PC 0x0c09ee6e */
if(!s->budget--) { s->failed_pc=0x0c09ee6eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ee84; }
goto P_0c09ee70;
P_0c09ee70: /* original 905d, guest PC 0x0c09ee70 */
if(!s->budget--) { s->failed_pc=0x0c09ee70u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2eu,2);
goto P_0c09ee72;
P_0c09ee72: /* original 6db3, guest PC 0x0c09ee72 */
if(!s->budget--) { s->failed_pc=0x0c09ee72u; return 0; }
r[13]=r[11];
goto P_0c09ee74;
P_0c09ee74: /* original 935d, guest PC 0x0c09ee74 */
if(!s->budget--) { s->failed_pc=0x0c09ee74u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef32u,2);
goto P_0c09ee76;
P_0c09ee76: /* original 02ec, guest PC 0x0c09ee76 */
if(!s->budget--) { s->failed_pc=0x0c09ee76u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09ee78;
P_0c09ee78: /* original 223b, guest PC 0x0c09ee78 */
if(!s->budget--) { s->failed_pc=0x0c09ee78u; return 0; }
r[2]|=r[3];
goto P_0c09ee7a;
P_0c09ee7a: /* original 0e24, guest PC 0x0c09ee7a */
if(!s->budget--) { s->failed_pc=0x0c09ee7au; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c09ee7c;
P_0c09ee7c: /* original 9456, guest PC 0x0c09ee7c */
if(!s->budget--) { s->failed_pc=0x0c09ee7cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2cu,2);
goto P_0c09ee7e;
P_0c09ee7e: /* original d134, guest PC 0x0c09ee7e */
if(!s->budget--) { s->failed_pc=0x0c09ee7eu; return 0; }
r[1]=read(ram,0x0c09ef50u,4);
goto P_0c09ee80;
P_0c09ee80: /* original 410b, guest PC 0x0c09ee80 */
if(!s->budget--) { s->failed_pc=0x0c09ee80u; return 0; }
target=r[1];
r[16]=code_base|0x0c09ee84u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ee84u) { target=s->pc; goto dispatch; }
goto P_0c09ee84;
P_0c09ee82: /* original 34ec, guest PC 0x0c09ee82 */
if(!s->budget--) { s->failed_pc=0x0c09ee82u; return 0; }
r[4]+=r[14];
goto P_0c09ee84;
P_0c09ee84: /* original 9053, guest PC 0x0c09ee84 */
if(!s->budget--) { s->failed_pc=0x0c09ee84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2eu,2);
goto P_0c09ee86;
P_0c09ee86: /* original 00ec, guest PC 0x0c09ee86 */
if(!s->budget--) { s->failed_pc=0x0c09ee86u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09ee88;
P_0c09ee88: /* original 600c, guest PC 0x0c09ee88 */
if(!s->budget--) { s->failed_pc=0x0c09ee88u; return 0; }
r[0]=r[0]&255u;
goto P_0c09ee8a;
P_0c09ee8a: /* original c820, guest PC 0x0c09ee8a */
if(!s->budget--) { s->failed_pc=0x0c09ee8au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c09ee8c;
P_0c09ee8c: /* original 891f, guest PC 0x0c09ee8c */
if(!s->budget--) { s->failed_pc=0x0c09ee8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09eece; }
goto P_0c09ee8e;
P_0c09ee8e: /* original 9051, guest PC 0x0c09ee8e */
if(!s->budget--) { s->failed_pc=0x0c09ee8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef34u,2);
goto P_0c09ee90;
P_0c09ee90: /* original 04ed, guest PC 0x0c09ee90 */
if(!s->budget--) { s->failed_pc=0x0c09ee90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09ee92;
P_0c09ee92: /* original e008, guest PC 0x0c09ee92 */
if(!s->budget--) { s->failed_pc=0x0c09ee92u; return 0; }
r[0]=0x00000008u;
goto P_0c09ee94;
P_0c09ee94: /* original 6b4b, guest PC 0x0c09ee94 */
if(!s->budget--) { s->failed_pc=0x0c09ee94u; return 0; }
r[11]=0u-r[4];
goto P_0c09ee96;
P_0c09ee96: /* original 4b5a, guest PC 0x0c09ee96 */
if(!s->budget--) { s->failed_pc=0x0c09ee96u; return 0; }
r[53]=r[11];
goto P_0c09ee98;
P_0c09ee98: /* original 64bf, guest PC 0x0c09ee98 */
if(!s->budget--) { s->failed_pc=0x0c09ee98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c09ee9a;
P_0c09ee9a: /* original f32d, guest PC 0x0c09ee9a */
if(!s->budget--) { s->failed_pc=0x0c09ee9au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c09ee9c;
P_0c09ee9c: /* original ff37, guest PC 0x0c09ee9c */
if(!s->budget--) { s->failed_pc=0x0c09ee9cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09ee9e;
P_0c09ee9e: /* original d32d, guest PC 0x0c09ee9e */
if(!s->budget--) { s->failed_pc=0x0c09ee9eu; return 0; }
r[3]=read(ram,0x0c09ef54u,4);
goto P_0c09eea0;
P_0c09eea0: /* original 430b, guest PC 0x0c09eea0 */
if(!s->budget--) { s->failed_pc=0x0c09eea0u; return 0; }
target=r[3];
r[16]=code_base|0x0c09eea4u;
write(ram,r[15]+4,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eea4u) { target=s->pc; goto dispatch; }
goto P_0c09eea4;
P_0c09eea2: /* original 1f41, guest PC 0x0c09eea2 */
if(!s->budget--) { s->failed_pc=0x0c09eea2u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c09eea4;
P_0c09eea4: /* original e00c, guest PC 0x0c09eea4 */
if(!s->budget--) { s->failed_pc=0x0c09eea4u; return 0; }
r[0]=0x0000000cu;
goto P_0c09eea6;
P_0c09eea6: /* original ff07, guest PC 0x0c09eea6 */
if(!s->budget--) { s->failed_pc=0x0c09eea6u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c09eea8;
P_0c09eea8: /* original d32b, guest PC 0x0c09eea8 */
if(!s->budget--) { s->failed_pc=0x0c09eea8u; return 0; }
r[3]=read(ram,0x0c09ef58u,4);
goto P_0c09eeaa;
P_0c09eeaa: /* original 430b, guest PC 0x0c09eeaa */
if(!s->budget--) { s->failed_pc=0x0c09eeaau; return 0; }
target=r[3];
r[16]=code_base|0x0c09eeaeu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eeaeu) { target=s->pc; goto dispatch; }
goto P_0c09eeae;
P_0c09eeac: /* original 54f1, guest PC 0x0c09eeac */
if(!s->budget--) { s->failed_pc=0x0c09eeacu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c09eeae;
P_0c09eeae: /* original e00c, guest PC 0x0c09eeae */
if(!s->budget--) { s->failed_pc=0x0c09eeaeu; return 0; }
r[0]=0x0000000cu;
goto P_0c09eeb0;
P_0c09eeb0: /* original f39d, guest PC 0x0c09eeb0 */
if(!s->budget--) { s->failed_pc=0x0c09eeb0u; return 0; }
fr[3]=0x3f800000u;
goto P_0c09eeb2;
P_0c09eeb2: /* original f2f6, guest PC 0x0c09eeb2 */
if(!s->budget--) { s->failed_pc=0x0c09eeb2u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09eeb4;
P_0c09eeb4: /* original e008, guest PC 0x0c09eeb4 */
if(!s->budget--) { s->failed_pc=0x0c09eeb4u; return 0; }
r[0]=0x00000008u;
goto P_0c09eeb6;
P_0c09eeb6: /* original f6f6, guest PC 0x0c09eeb6 */
if(!s->budget--) { s->failed_pc=0x0c09eeb6u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09eeb8;
P_0c09eeb8: /* original f232, guest PC 0x0c09eeb8 */
if(!s->budget--) { s->failed_pc=0x0c09eeb8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c09eeba;
P_0c09eeba: /* original d328, guest PC 0x0c09eeba */
if(!s->budget--) { s->failed_pc=0x0c09eebau; return 0; }
r[3]=read(ram,0x0c09ef5cu,4);
goto P_0c09eebc;
P_0c09eebc: /* original 943b, guest PC 0x0c09eebc */
if(!s->budget--) { s->failed_pc=0x0c09eebcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef36u,2);
goto P_0c09eebe;
P_0c09eebe: /* original f50c, guest PC 0x0c09eebe */
if(!s->budget--) { s->failed_pc=0x0c09eebeu; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c09eec0;
P_0c09eec0: /* original f42c, guest PC 0x0c09eec0 */
if(!s->budget--) { s->failed_pc=0x0c09eec0u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c09eec2;
P_0c09eec2: /* original f44d, guest PC 0x0c09eec2 */
if(!s->budget--) { s->failed_pc=0x0c09eec2u; return 0; }
fr[4]^=0x80000000u;
goto P_0c09eec4;
P_0c09eec4: /* original 430b, guest PC 0x0c09eec4 */
if(!s->budget--) { s->failed_pc=0x0c09eec4u; return 0; }
target=r[3];
r[16]=code_base|0x0c09eec8u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eec8u) { target=s->pc; goto dispatch; }
goto P_0c09eec8;
P_0c09eec6: /* original 34ec, guest PC 0x0c09eec6 */
if(!s->budget--) { s->failed_pc=0x0c09eec6u; return 0; }
r[4]+=r[14];
goto P_0c09eec8;
P_0c09eec8: /* original d225, guest PC 0x0c09eec8 */
if(!s->budget--) { s->failed_pc=0x0c09eec8u; return 0; }
r[2]=read(ram,0x0c09ef60u,4);
goto P_0c09eeca;
P_0c09eeca: /* original 420b, guest PC 0x0c09eeca */
if(!s->budget--) { s->failed_pc=0x0c09eecau; return 0; }
target=r[2];
r[16]=code_base|0x0c09eeceu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eeceu) { target=s->pc; goto dispatch; }
goto P_0c09eece;
P_0c09eecc: /* original 64e3, guest PC 0x0c09eecc */
if(!s->budget--) { s->failed_pc=0x0c09eeccu; return 0; }
r[4]=r[14];
goto P_0c09eece;
P_0c09eece: /* original e048, guest PC 0x0c09eece */
if(!s->budget--) { s->failed_pc=0x0c09eeceu; return 0; }
r[0]=0x00000048u;
goto P_0c09eed0;
P_0c09eed0: /* original 9332, guest PC 0x0c09eed0 */
if(!s->budget--) { s->failed_pc=0x0c09eed0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef38u,2);
goto P_0c09eed2;
P_0c09eed2: /* original 02ee, guest PC 0x0c09eed2 */
if(!s->budget--) { s->failed_pc=0x0c09eed2u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09eed4;
P_0c09eed4: /* original 2238, guest PC 0x0c09eed4 */
if(!s->budget--) { s->failed_pc=0x0c09eed4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09eed6;
P_0c09eed6: /* original 8908, guest PC 0x0c09eed6 */
if(!s->budget--) { s->failed_pc=0x0c09eed6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09eeea; }
goto P_0c09eed8;
P_0c09eed8: /* original c722, guest PC 0x0c09eed8 */
if(!s->budget--) { s->failed_pc=0x0c09eed8u; return 0; }
r[0]=code_base|0x0009ef64u;
goto P_0c09eeda;
P_0c09eeda: /* original 942c, guest PC 0x0c09eeda */
if(!s->budget--) { s->failed_pc=0x0c09eedau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef36u,2);
goto P_0c09eedc;
P_0c09eedc: /* original f508, guest PC 0x0c09eedc */
if(!s->budget--) { s->failed_pc=0x0c09eedcu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c09eede;
P_0c09eede: /* original c722, guest PC 0x0c09eede */
if(!s->budget--) { s->failed_pc=0x0c09eedeu; return 0; }
r[0]=code_base|0x0009ef68u;
goto P_0c09eee0;
P_0c09eee0: /* original d31e, guest PC 0x0c09eee0 */
if(!s->budget--) { s->failed_pc=0x0c09eee0u; return 0; }
r[3]=read(ram,0x0c09ef5cu,4);
goto P_0c09eee2;
P_0c09eee2: /* original f608, guest PC 0x0c09eee2 */
if(!s->budget--) { s->failed_pc=0x0c09eee2u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c09eee4;
P_0c09eee4: /* original f48d, guest PC 0x0c09eee4 */
if(!s->budget--) { s->failed_pc=0x0c09eee4u; return 0; }
fr[4]=0;
goto P_0c09eee6;
P_0c09eee6: /* original 430b, guest PC 0x0c09eee6 */
if(!s->budget--) { s->failed_pc=0x0c09eee6u; return 0; }
target=r[3];
r[16]=code_base|0x0c09eeeau;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09eeeau) { target=s->pc; goto dispatch; }
goto P_0c09eeea;
P_0c09eee8: /* original 34ec, guest PC 0x0c09eee8 */
if(!s->budget--) { s->failed_pc=0x0c09eee8u; return 0; }
r[4]+=r[14];
goto P_0c09eeea;
P_0c09eeea: /* original 9026, guest PC 0x0c09eeea */
if(!s->budget--) { s->failed_pc=0x0c09eeeau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef3au,2);
goto P_0c09eeec;
P_0c09eeec: /* original d317, guest PC 0x0c09eeec */
if(!s->budget--) { s->failed_pc=0x0c09eeecu; return 0; }
r[3]=read(ram,0x0c09ef4cu,4);
goto P_0c09eeee;
P_0c09eeee: /* original 02ee, guest PC 0x0c09eeee */
if(!s->budget--) { s->failed_pc=0x0c09eeeeu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09eef0;
P_0c09eef0: /* original 2238, guest PC 0x0c09eef0 */
if(!s->budget--) { s->failed_pc=0x0c09eef0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09eef2;
P_0c09eef2: /* original 8908, guest PC 0x0c09eef2 */
if(!s->budget--) { s->failed_pc=0x0c09eef2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ef06; }
goto P_0c09eef4;
P_0c09eef4: /* original 9022, guest PC 0x0c09eef4 */
if(!s->budget--) { s->failed_pc=0x0c09eef4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef3cu,2);
goto P_0c09eef6;
P_0c09eef6: /* original e340, guest PC 0x0c09eef6 */
if(!s->budget--) { s->failed_pc=0x0c09eef6u; return 0; }
r[3]=0x00000040u;
goto P_0c09eef8;
P_0c09eef8: /* original 01ed, guest PC 0x0c09eef8 */
if(!s->budget--) { s->failed_pc=0x0c09eef8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09eefa;
P_0c09eefa: /* original 901b, guest PC 0x0c09eefa */
if(!s->budget--) { s->failed_pc=0x0c09eefau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef34u,2);
goto P_0c09eefc;
P_0c09eefc: /* original 0e15, guest PC 0x0c09eefc */
if(!s->budget--) { s->failed_pc=0x0c09eefcu; return 0; }
write(ram,r[14]+r[0],r[1],2);
goto P_0c09eefe;
P_0c09eefe: /* original 70df, guest PC 0x0c09eefe */
if(!s->budget--) { s->failed_pc=0x0c09eefeu; return 0; }
r[0]+=0xffffffdfu;
goto P_0c09ef00;
P_0c09ef00: /* original 02ec, guest PC 0x0c09ef00 */
if(!s->budget--) { s->failed_pc=0x0c09ef00u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09ef02;
P_0c09ef02: /* original 223b, guest PC 0x0c09ef02 */
if(!s->budget--) { s->failed_pc=0x0c09ef02u; return 0; }
r[2]|=r[3];
goto P_0c09ef04;
P_0c09ef04: /* original 0e24, guest PC 0x0c09ef04 */
if(!s->budget--) { s->failed_pc=0x0c09ef04u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c09ef06;
P_0c09ef06: /* original 9516, guest PC 0x0c09ef06 */
if(!s->budget--) { s->failed_pc=0x0c09ef06u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef36u,2);
goto P_0c09ef08;
P_0c09ef08: /* original 9410, guest PC 0x0c09ef08 */
if(!s->budget--) { s->failed_pc=0x0c09ef08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2cu,2);
goto P_0c09ef0a;
P_0c09ef0a: /* original d318, guest PC 0x0c09ef0a */
if(!s->budget--) { s->failed_pc=0x0c09ef0au; return 0; }
r[3]=read(ram,0x0c09ef6cu,4);
goto P_0c09ef0c;
P_0c09ef0c: /* original 35ec, guest PC 0x0c09ef0c */
if(!s->budget--) { s->failed_pc=0x0c09ef0cu; return 0; }
r[5]+=r[14];
goto P_0c09ef0e;
P_0c09ef0e: /* original 430b, guest PC 0x0c09ef0e */
if(!s->budget--) { s->failed_pc=0x0c09ef0eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09ef12u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ef12u) { target=s->pc; goto dispatch; }
goto P_0c09ef12;
P_0c09ef10: /* original 34ec, guest PC 0x0c09ef10 */
if(!s->budget--) { s->failed_pc=0x0c09ef10u; return 0; }
r[4]+=r[14];
goto P_0c09ef12;
P_0c09ef12: /* original 950b, guest PC 0x0c09ef12 */
if(!s->budget--) { s->failed_pc=0x0c09ef12u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef2cu,2);
goto P_0c09ef14;
P_0c09ef14: /* original 960f, guest PC 0x0c09ef14 */
if(!s->budget--) { s->failed_pc=0x0c09ef14u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ef36u,2);
goto P_0c09ef16;
P_0c09ef16: /* original d216, guest PC 0x0c09ef16 */
if(!s->budget--) { s->failed_pc=0x0c09ef16u; return 0; }
r[2]=read(ram,0x0c09ef70u,4);
goto P_0c09ef18;
P_0c09ef18: /* original 35ec, guest PC 0x0c09ef18 */
if(!s->budget--) { s->failed_pc=0x0c09ef18u; return 0; }
r[5]+=r[14];
goto P_0c09ef1a;
P_0c09ef1a: /* original 36ec, guest PC 0x0c09ef1a */
if(!s->budget--) { s->failed_pc=0x0c09ef1au; return 0; }
r[6]+=r[14];
goto P_0c09ef1c;
P_0c09ef1c: /* original 420b, guest PC 0x0c09ef1c */
if(!s->budget--) { s->failed_pc=0x0c09ef1cu; return 0; }
target=r[2];
r[16]=code_base|0x0c09ef20u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ef20u) { target=s->pc; goto dispatch; }
goto P_0c09ef20;
P_0c09ef1e: /* original 64e3, guest PC 0x0c09ef1e */
if(!s->budget--) { s->failed_pc=0x0c09ef1eu; return 0; }
r[4]=r[14];
goto P_0c09ef20;
P_0c09ef20: /* original d314, guest PC 0x0c09ef20 */
if(!s->budget--) { s->failed_pc=0x0c09ef20u; return 0; }
r[3]=read(ram,0x0c09ef74u,4);
goto P_0c09ef22;
P_0c09ef22: /* original 430b, guest PC 0x0c09ef22 */
if(!s->budget--) { s->failed_pc=0x0c09ef22u; return 0; }
target=r[3];
r[16]=code_base|0x0c09ef26u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ef26u) { target=s->pc; goto dispatch; }
goto P_0c09ef26;
P_0c09ef24: /* original 64e3, guest PC 0x0c09ef24 */
if(!s->budget--) { s->failed_pc=0x0c09ef24u; return 0; }
r[4]=r[14];
goto P_0c09ef26;
P_0c09ef26: /* original a03a, guest PC 0x0c09ef26 */
if(!s->budget--) { s->failed_pc=0x0c09ef26u; return 0; }
goto P_0c09ef9e;
P_0c09ef28: /* original 0009, guest PC 0x0c09ef28 */
if(!s->budget--) { s->failed_pc=0x0c09ef28u; return 0; }
if(!vf3_matrix_family(0x0c09ef2au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09ef2au; return 0; } return 1;
P_0c09ef78: /* original 9066, guest PC 0x0c09ef78 */
if(!s->budget--) { s->failed_pc=0x0c09ef78u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f048u,2);
goto P_0c09ef7a;
P_0c09ef7a: /* original 65f3, guest PC 0x0c09ef7a */
if(!s->budget--) { s->failed_pc=0x0c09ef7au; return 0; }
r[5]=r[15];
goto P_0c09ef7c;
P_0c09ef7c: /* original 66c3, guest PC 0x0c09ef7c */
if(!s->budget--) { s->failed_pc=0x0c09ef7cu; return 0; }
r[6]=r[12];
goto P_0c09ef7e;
P_0c09ef7e: /* original 03ed, guest PC 0x0c09ef7e */
if(!s->budget--) { s->failed_pc=0x0c09ef7eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09ef80;
P_0c09ef80: /* original 9063, guest PC 0x0c09ef80 */
if(!s->budget--) { s->failed_pc=0x0c09ef80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f04au,2);
goto P_0c09ef82;
P_0c09ef82: /* original 0e35, guest PC 0x0c09ef82 */
if(!s->budget--) { s->failed_pc=0x0c09ef82u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c09ef84;
P_0c09ef84: /* original d334, guest PC 0x0c09ef84 */
if(!s->budget--) { s->failed_pc=0x0c09ef84u; return 0; }
r[3]=read(ram,0x0c09f058u,4);
goto P_0c09ef86;
P_0c09ef86: /* original 430b, guest PC 0x0c09ef86 */
if(!s->budget--) { s->failed_pc=0x0c09ef86u; return 0; }
target=r[3];
r[16]=code_base|0x0c09ef8au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ef8au) { target=s->pc; goto dispatch; }
goto P_0c09ef8a;
P_0c09ef88: /* original 64e3, guest PC 0x0c09ef88 */
if(!s->budget--) { s->failed_pc=0x0c09ef88u; return 0; }
r[4]=r[14];
goto P_0c09ef8a;
P_0c09ef8a: /* original d234, guest PC 0x0c09ef8a */
if(!s->budget--) { s->failed_pc=0x0c09ef8au; return 0; }
r[2]=read(ram,0x0c09f05cu,4);
goto P_0c09ef8c;
P_0c09ef8c: /* original 420b, guest PC 0x0c09ef8c */
if(!s->budget--) { s->failed_pc=0x0c09ef8cu; return 0; }
target=r[2];
r[16]=code_base|0x0c09ef90u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ef90u) { target=s->pc; goto dispatch; }
goto P_0c09ef90;
P_0c09ef8e: /* original 64e3, guest PC 0x0c09ef8e */
if(!s->budget--) { s->failed_pc=0x0c09ef8eu; return 0; }
r[4]=r[14];
goto P_0c09ef90;
P_0c09ef90: /* original 935c, guest PC 0x0c09ef90 */
if(!s->budget--) { s->failed_pc=0x0c09ef90u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f04cu,2);
goto P_0c09ef92;
P_0c09ef92: /* original 23d8, guest PC 0x0c09ef92 */
if(!s->budget--) { s->failed_pc=0x0c09ef92u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09ef94;
P_0c09ef94: /* original 8903, guest PC 0x0c09ef94 */
if(!s->budget--) { s->failed_pc=0x0c09ef94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ef9e; }
goto P_0c09ef96;
P_0c09ef96: /* original d332, guest PC 0x0c09ef96 */
if(!s->budget--) { s->failed_pc=0x0c09ef96u; return 0; }
r[3]=read(ram,0x0c09f060u,4);
goto P_0c09ef98;
P_0c09ef98: /* original 9459, guest PC 0x0c09ef98 */
if(!s->budget--) { s->failed_pc=0x0c09ef98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f04eu,2);
goto P_0c09ef9a;
P_0c09ef9a: /* original 430b, guest PC 0x0c09ef9a */
if(!s->budget--) { s->failed_pc=0x0c09ef9au; return 0; }
target=r[3];
r[16]=code_base|0x0c09ef9eu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ef9eu) { target=s->pc; goto dispatch; }
goto P_0c09ef9e;
P_0c09ef9c: /* original 34ec, guest PC 0x0c09ef9c */
if(!s->budget--) { s->failed_pc=0x0c09ef9cu; return 0; }
r[4]+=r[14];
goto P_0c09ef9e;
P_0c09ef9e: /* original e201, guest PC 0x0c09ef9e */
if(!s->budget--) { s->failed_pc=0x0c09ef9eu; return 0; }
r[2]=0x00000001u;
goto P_0c09efa0;
P_0c09efa0: /* original 22d8, guest PC 0x0c09efa0 */
if(!s->budget--) { s->failed_pc=0x0c09efa0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c09efa2;
P_0c09efa2: /* original 8902, guest PC 0x0c09efa2 */
if(!s->budget--) { s->failed_pc=0x0c09efa2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09efaa; }
goto P_0c09efa4;
P_0c09efa4: /* original d22f, guest PC 0x0c09efa4 */
if(!s->budget--) { s->failed_pc=0x0c09efa4u; return 0; }
r[2]=read(ram,0x0c09f064u,4);
goto P_0c09efa6;
P_0c09efa6: /* original 420b, guest PC 0x0c09efa6 */
if(!s->budget--) { s->failed_pc=0x0c09efa6u; return 0; }
target=r[2];
r[16]=code_base|0x0c09efaau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09efaau) { target=s->pc; goto dispatch; }
goto P_0c09efaa;
P_0c09efa8: /* original 64e3, guest PC 0x0c09efa8 */
if(!s->budget--) { s->failed_pc=0x0c09efa8u; return 0; }
r[4]=r[14];
goto P_0c09efaa;
P_0c09efaa: /* original e302, guest PC 0x0c09efaa */
if(!s->budget--) { s->failed_pc=0x0c09efaau; return 0; }
r[3]=0x00000002u;
goto P_0c09efac;
P_0c09efac: /* original 23d8, guest PC 0x0c09efac */
if(!s->budget--) { s->failed_pc=0x0c09efacu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09efae;
P_0c09efae: /* original 8904, guest PC 0x0c09efae */
if(!s->budget--) { s->failed_pc=0x0c09efaeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09efba; }
goto P_0c09efb0;
P_0c09efb0: /* original d32d, guest PC 0x0c09efb0 */
if(!s->budget--) { s->failed_pc=0x0c09efb0u; return 0; }
r[3]=read(ram,0x0c09f068u,4);
goto P_0c09efb2;
P_0c09efb2: /* original 65c3, guest PC 0x0c09efb2 */
if(!s->budget--) { s->failed_pc=0x0c09efb2u; return 0; }
r[5]=r[12];
goto P_0c09efb4;
P_0c09efb4: /* original 66d3, guest PC 0x0c09efb4 */
if(!s->budget--) { s->failed_pc=0x0c09efb4u; return 0; }
r[6]=r[13];
goto P_0c09efb6;
P_0c09efb6: /* original 430b, guest PC 0x0c09efb6 */
if(!s->budget--) { s->failed_pc=0x0c09efb6u; return 0; }
target=r[3];
r[16]=code_base|0x0c09efbau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09efbau) { target=s->pc; goto dispatch; }
goto P_0c09efba;
P_0c09efb8: /* original 64e3, guest PC 0x0c09efb8 */
if(!s->budget--) { s->failed_pc=0x0c09efb8u; return 0; }
r[4]=r[14];
goto P_0c09efba;
P_0c09efba: /* original d22c, guest PC 0x0c09efba */
if(!s->budget--) { s->failed_pc=0x0c09efbau; return 0; }
r[2]=read(ram,0x0c09f06cu,4);
goto P_0c09efbc;
P_0c09efbc: /* original 420b, guest PC 0x0c09efbc */
if(!s->budget--) { s->failed_pc=0x0c09efbcu; return 0; }
target=r[2];
r[16]=code_base|0x0c09efc0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09efc0u) { target=s->pc; goto dispatch; }
goto P_0c09efc0;
P_0c09efbe: /* original 64e3, guest PC 0x0c09efbe */
if(!s->budget--) { s->failed_pc=0x0c09efbeu; return 0; }
r[4]=r[14];
goto P_0c09efc0;
P_0c09efc0: /* original 7f10, guest PC 0x0c09efc0 */
if(!s->budget--) { s->failed_pc=0x0c09efc0u; return 0; }
r[15]+=0x00000010u;
goto P_0c09efc2;
P_0c09efc2: /* original 4f26, guest PC 0x0c09efc2 */
if(!s->budget--) { s->failed_pc=0x0c09efc2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09efc4;
P_0c09efc4: /* original 6bf6, guest PC 0x0c09efc4 */
if(!s->budget--) { s->failed_pc=0x0c09efc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09efc6;
P_0c09efc6: /* original 6cf6, guest PC 0x0c09efc6 */
if(!s->budget--) { s->failed_pc=0x0c09efc6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09efc8;
P_0c09efc8: /* original 6df6, guest PC 0x0c09efc8 */
if(!s->budget--) { s->failed_pc=0x0c09efc8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09efca;
P_0c09efca: /* original 000b, guest PC 0x0c09efca */
if(!s->budget--) { s->failed_pc=0x0c09efcau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09efcc: /* original 6ef6, guest PC 0x0c09efcc */
if(!s->budget--) { s->failed_pc=0x0c09efccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09efceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09efceu; return 0; } return 1;
P_0c09efd8: /* original e03e, guest PC 0x0c09efd8 */
if(!s->budget--) { s->failed_pc=0x0c09efd8u; return 0; }
r[0]=0x0000003eu;
goto P_0c09efda;
P_0c09efda: /* original e301, guest PC 0x0c09efda */
if(!s->budget--) { s->failed_pc=0x0c09efdau; return 0; }
r[3]=0x00000001u;
goto P_0c09efdc;
P_0c09efdc: /* original 0435, guest PC 0x0c09efdc */
if(!s->budget--) { s->failed_pc=0x0c09efdcu; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c09efde;
P_0c09efde: /* original e040, guest PC 0x0c09efde */
if(!s->budget--) { s->failed_pc=0x0c09efdeu; return 0; }
r[0]=0x00000040u;
goto P_0c09efe0;
P_0c09efe0: /* original e200, guest PC 0x0c09efe0 */
if(!s->budget--) { s->failed_pc=0x0c09efe0u; return 0; }
r[2]=0x00000000u;
goto P_0c09efe2;
P_0c09efe2: /* original 000b, guest PC 0x0c09efe2 */
if(!s->budget--) { s->failed_pc=0x0c09efe2u; return 0; }
target=r[16];
write(ram,r[4]+r[0],r[2],2);
s->pc=target; return ram->oob==0;
P_0c09efe4: /* original 0425, guest PC 0x0c09efe4 */
if(!s->budget--) { s->failed_pc=0x0c09efe4u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c09efe6;
P_0c09efe6: /* original e03e, guest PC 0x0c09efe6 */
if(!s->budget--) { s->failed_pc=0x0c09efe6u; return 0; }
r[0]=0x0000003eu;
goto P_0c09efe8;
P_0c09efe8: /* original 054d, guest PC 0x0c09efe8 */
if(!s->budget--) { s->failed_pc=0x0c09efe8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09efea;
P_0c09efea: /* original e040, guest PC 0x0c09efea */
if(!s->budget--) { s->failed_pc=0x0c09efeau; return 0; }
r[0]=0x00000040u;
goto P_0c09efec;
P_0c09efec: /* original 064d, guest PC 0x0c09efec */
if(!s->budget--) { s->failed_pc=0x0c09efecu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09efee;
P_0c09efee: /* original e3f8, guest PC 0x0c09efee */
if(!s->budget--) { s->failed_pc=0x0c09efeeu; return 0; }
r[3]=0xfffffff8u;
goto P_0c09eff0;
P_0c09eff0: /* original 655d, guest PC 0x0c09eff0 */
if(!s->budget--) { s->failed_pc=0x0c09eff0u; return 0; }
r[5]=r[5]&65535u;
goto P_0c09eff2;
P_0c09eff2: /* original 902f, guest PC 0x0c09eff2 */
if(!s->budget--) { s->failed_pc=0x0c09eff2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f054u,2);
goto P_0c09eff4;
P_0c09eff4: /* original 4528, guest PC 0x0c09eff4 */
if(!s->budget--) { s->failed_pc=0x0c09eff4u; return 0; }
r[5]<<=16;
goto P_0c09eff6;
P_0c09eff6: /* original 666d, guest PC 0x0c09eff6 */
if(!s->budget--) { s->failed_pc=0x0c09eff6u; return 0; }
r[6]=r[6]&65535u;
goto P_0c09eff8;
P_0c09eff8: /* original 044d, guest PC 0x0c09eff8 */
if(!s->budget--) { s->failed_pc=0x0c09eff8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09effa;
P_0c09effa: /* original 256b, guest PC 0x0c09effa */
if(!s->budget--) { s->failed_pc=0x0c09effau; return 0; }
r[5]|=r[6];
goto P_0c09effc;
P_0c09effc: /* original 9629, guest PC 0x0c09effc */
if(!s->budget--) { s->failed_pc=0x0c09effcu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f052u,2);
goto P_0c09effe;
P_0c09effe: /* original 453c, guest PC 0x0c09effe */
if(!s->budget--) { s->failed_pc=0x0c09effeu; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c09f000;
P_0c09f000: /* original 644d, guest PC 0x0c09f000 */
if(!s->budget--) { s->failed_pc=0x0c09f000u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09f002;
P_0c09f002: /* original 6753, guest PC 0x0c09f002 */
if(!s->budget--) { s->failed_pc=0x0c09f002u; return 0; }
r[7]=r[5];
goto P_0c09f004;
P_0c09f004: /* original 365c, guest PC 0x0c09f004 */
if(!s->budget--) { s->failed_pc=0x0c09f004u; return 0; }
r[6]+=r[5];
goto P_0c09f006;
P_0c09f006: /* original 4611, guest PC 0x0c09f006 */
if(!s->budget--) { s->failed_pc=0x0c09f006u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=0)!=0);
goto P_0c09f008;
P_0c09f008: /* original 4418, guest PC 0x0c09f008 */
if(!s->budget--) { s->failed_pc=0x0c09f008u; return 0; }
r[4]<<=8;
goto P_0c09f00a;
P_0c09f00a: /* original 8d01, guest PC 0x0c09f00a */
if(!s->budget--) { s->failed_pc=0x0c09f00au; return 0; }
cond=r[17]&1u;
r[7]-=r[4];
if(cond) { goto P_0c09f010; }
goto P_0c09f00e;
P_0c09f00c: /* original 3748, guest PC 0x0c09f00c */
if(!s->budget--) { s->failed_pc=0x0c09f00cu; return 0; }
r[7]-=r[4];
goto P_0c09f00e;
P_0c09f00e: /* original 951f, guest PC 0x0c09f00e */
if(!s->budget--) { s->failed_pc=0x0c09f00eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f050u,2);
goto P_0c09f010;
P_0c09f010: /* original 4715, guest PC 0x0c09f010 */
if(!s->budget--) { s->failed_pc=0x0c09f010u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c09f012;
P_0c09f012: /* original 8b00, guest PC 0x0c09f012 */
if(!s->budget--) { s->failed_pc=0x0c09f012u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f016; }
goto P_0c09f014;
P_0c09f014: /* original 6543, guest PC 0x0c09f014 */
if(!s->budget--) { s->failed_pc=0x0c09f014u; return 0; }
r[5]=r[4];
goto P_0c09f016;
P_0c09f016: /* original 000b, guest PC 0x0c09f016 */
if(!s->budget--) { s->failed_pc=0x0c09f016u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c09f018: /* original 6053, guest PC 0x0c09f018 */
if(!s->budget--) { s->failed_pc=0x0c09f018u; return 0; }
r[0]=r[5];
return vf3_matrix_family(0x0c09f01au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
