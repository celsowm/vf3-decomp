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
int vf3_away_batch15_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08cad4u: goto P_0c08cad4;
case 0x0c08cad6u: goto P_0c08cad6;
case 0x0c08cad8u: goto P_0c08cad8;
case 0x0c08cadau: goto P_0c08cada;
case 0x0c08cadcu: goto P_0c08cadc;
case 0x0c08cadeu: goto P_0c08cade;
case 0x0c08cae0u: goto P_0c08cae0;
case 0x0c08cae2u: goto P_0c08cae2;
case 0x0c08cae4u: goto P_0c08cae4;
case 0x0c08cae6u: goto P_0c08cae6;
case 0x0c08cae8u: goto P_0c08cae8;
case 0x0c08caeau: goto P_0c08caea;
case 0x0c08caecu: goto P_0c08caec;
case 0x0c08caeeu: goto P_0c08caee;
case 0x0c08caf0u: goto P_0c08caf0;
case 0x0c08caf2u: goto P_0c08caf2;
case 0x0c08caf4u: goto P_0c08caf4;
case 0x0c08caf6u: goto P_0c08caf6;
case 0x0c08caf8u: goto P_0c08caf8;
case 0x0c08cafau: goto P_0c08cafa;
case 0x0c08cafcu: goto P_0c08cafc;
case 0x0c08cafeu: goto P_0c08cafe;
case 0x0c08cb00u: goto P_0c08cb00;
case 0x0c08cb02u: goto P_0c08cb02;
case 0x0c08cb04u: goto P_0c08cb04;
case 0x0c08cb06u: goto P_0c08cb06;
case 0x0c08cb08u: goto P_0c08cb08;
case 0x0c08cb0au: goto P_0c08cb0a;
case 0x0c08cb0cu: goto P_0c08cb0c;
case 0x0c08cb0eu: goto P_0c08cb0e;
case 0x0c08cb10u: goto P_0c08cb10;
case 0x0c08cb12u: goto P_0c08cb12;
case 0x0c08cb14u: goto P_0c08cb14;
case 0x0c08cb16u: goto P_0c08cb16;
case 0x0c08cb18u: goto P_0c08cb18;
case 0x0c08cb1au: goto P_0c08cb1a;
case 0x0c08cb1cu: goto P_0c08cb1c;
case 0x0c08cb1eu: goto P_0c08cb1e;
case 0x0c08cb20u: goto P_0c08cb20;
case 0x0c08cb22u: goto P_0c08cb22;
case 0x0c08cb24u: goto P_0c08cb24;
case 0x0c08cb26u: goto P_0c08cb26;
case 0x0c08cb28u: goto P_0c08cb28;
case 0x0c08cb2au: goto P_0c08cb2a;
case 0x0c08cb2cu: goto P_0c08cb2c;
case 0x0c08cb2eu: goto P_0c08cb2e;
case 0x0c08cb30u: goto P_0c08cb30;
case 0x0c08cb32u: goto P_0c08cb32;
case 0x0c08cb34u: goto P_0c08cb34;
case 0x0c08cb36u: goto P_0c08cb36;
case 0x0c08cb38u: goto P_0c08cb38;
case 0x0c08cb3au: goto P_0c08cb3a;
case 0x0c08cb3cu: goto P_0c08cb3c;
case 0x0c08cb3eu: goto P_0c08cb3e;
case 0x0c08cb40u: goto P_0c08cb40;
case 0x0c08cb42u: goto P_0c08cb42;
case 0x0c08cb44u: goto P_0c08cb44;
case 0x0c08cb46u: goto P_0c08cb46;
case 0x0c08cb48u: goto P_0c08cb48;
case 0x0c08cb4au: goto P_0c08cb4a;
case 0x0c08cb4cu: goto P_0c08cb4c;
case 0x0c08cb4eu: goto P_0c08cb4e;
case 0x0c08cb50u: goto P_0c08cb50;
case 0x0c08cb52u: goto P_0c08cb52;
case 0x0c08cb54u: goto P_0c08cb54;
case 0x0c08cb56u: goto P_0c08cb56;
case 0x0c08cb58u: goto P_0c08cb58;
case 0x0c08cb5au: goto P_0c08cb5a;
case 0x0c08cb5cu: goto P_0c08cb5c;
case 0x0c08cb5eu: goto P_0c08cb5e;
case 0x0c08cb60u: goto P_0c08cb60;
case 0x0c08cb62u: goto P_0c08cb62;
case 0x0c08cb64u: goto P_0c08cb64;
case 0x0c08cb66u: goto P_0c08cb66;
case 0x0c08cb68u: goto P_0c08cb68;
case 0x0c08cb6au: goto P_0c08cb6a;
case 0x0c08cb6cu: goto P_0c08cb6c;
case 0x0c08cbacu: goto P_0c08cbac;
case 0x0c08cbaeu: goto P_0c08cbae;
case 0x0c08cbb0u: goto P_0c08cbb0;
case 0x0c08cbb2u: goto P_0c08cbb2;
case 0x0c08cbb4u: goto P_0c08cbb4;
case 0x0c08cbb6u: goto P_0c08cbb6;
case 0x0c08cbb8u: goto P_0c08cbb8;
case 0x0c08cbbau: goto P_0c08cbba;
case 0x0c08cbbcu: goto P_0c08cbbc;
case 0x0c08cbbeu: goto P_0c08cbbe;
case 0x0c08cbc0u: goto P_0c08cbc0;
case 0x0c08cbc2u: goto P_0c08cbc2;
case 0x0c08cbc4u: goto P_0c08cbc4;
case 0x0c08cbc6u: goto P_0c08cbc6;
case 0x0c08cbc8u: goto P_0c08cbc8;
case 0x0c08cbcau: goto P_0c08cbca;
case 0x0c08cbccu: goto P_0c08cbcc;
case 0x0c08cbceu: goto P_0c08cbce;
case 0x0c08cbd0u: goto P_0c08cbd0;
case 0x0c08cbd2u: goto P_0c08cbd2;
case 0x0c08cbd4u: goto P_0c08cbd4;
case 0x0c08cbd6u: goto P_0c08cbd6;
case 0x0c08cbd8u: goto P_0c08cbd8;
case 0x0c08cbdau: goto P_0c08cbda;
case 0x0c08cbdcu: goto P_0c08cbdc;
case 0x0c08cbdeu: goto P_0c08cbde;
case 0x0c08cbe0u: goto P_0c08cbe0;
case 0x0c08cbe2u: goto P_0c08cbe2;
case 0x0c08cbe4u: goto P_0c08cbe4;
case 0x0c08cbe6u: goto P_0c08cbe6;
case 0x0c08cbe8u: goto P_0c08cbe8;
case 0x0c08cbeau: goto P_0c08cbea;
case 0x0c08cbecu: goto P_0c08cbec;
case 0x0c08cbeeu: goto P_0c08cbee;
case 0x0c08cbf0u: goto P_0c08cbf0;
case 0x0c08cbf2u: goto P_0c08cbf2;
case 0x0c08cbf4u: goto P_0c08cbf4;
case 0x0c08cbf6u: goto P_0c08cbf6;
case 0x0c08cbf8u: goto P_0c08cbf8;
case 0x0c08cbfau: goto P_0c08cbfa;
case 0x0c08cbfcu: goto P_0c08cbfc;
case 0x0c08cbfeu: goto P_0c08cbfe;
case 0x0c08cc00u: goto P_0c08cc00;
case 0x0c08cc02u: goto P_0c08cc02;
case 0x0c08cc04u: goto P_0c08cc04;
case 0x0c08cc06u: goto P_0c08cc06;
case 0x0c08cc08u: goto P_0c08cc08;
case 0x0c08cc0au: goto P_0c08cc0a;
case 0x0c08cc0cu: goto P_0c08cc0c;
case 0x0c08cc0eu: goto P_0c08cc0e;
case 0x0c08cc10u: goto P_0c08cc10;
case 0x0c08cc12u: goto P_0c08cc12;
case 0x0c08cc14u: goto P_0c08cc14;
case 0x0c08cc16u: goto P_0c08cc16;
case 0x0c08cc18u: goto P_0c08cc18;
case 0x0c08cc1au: goto P_0c08cc1a;
case 0x0c08cc1cu: goto P_0c08cc1c;
case 0x0c08cc1eu: goto P_0c08cc1e;
case 0x0c08cc20u: goto P_0c08cc20;
case 0x0c08cc22u: goto P_0c08cc22;
case 0x0c08cc24u: goto P_0c08cc24;
case 0x0c08cc26u: goto P_0c08cc26;
case 0x0c08cc28u: goto P_0c08cc28;
case 0x0c08cc2au: goto P_0c08cc2a;
case 0x0c08cc2cu: goto P_0c08cc2c;
case 0x0c08cc2eu: goto P_0c08cc2e;
case 0x0c08cc30u: goto P_0c08cc30;
case 0x0c08cc32u: goto P_0c08cc32;
case 0x0c08cc34u: goto P_0c08cc34;
case 0x0c08cc36u: goto P_0c08cc36;
case 0x0c08cc38u: goto P_0c08cc38;
case 0x0c08cc3au: goto P_0c08cc3a;
case 0x0c08cc3cu: goto P_0c08cc3c;
case 0x0c08cc3eu: goto P_0c08cc3e;
case 0x0c08cc40u: goto P_0c08cc40;
case 0x0c08cc42u: goto P_0c08cc42;
case 0x0c08cc44u: goto P_0c08cc44;
case 0x0c08cc46u: goto P_0c08cc46;
case 0x0c08cc48u: goto P_0c08cc48;
case 0x0c08cc4au: goto P_0c08cc4a;
case 0x0c08cc4cu: goto P_0c08cc4c;
case 0x0c08cc4eu: goto P_0c08cc4e;
case 0x0c08cc50u: goto P_0c08cc50;
case 0x0c08cc52u: goto P_0c08cc52;
case 0x0c08cc54u: goto P_0c08cc54;
case 0x0c08cc56u: goto P_0c08cc56;
case 0x0c08cc58u: goto P_0c08cc58;
case 0x0c08cc5au: goto P_0c08cc5a;
case 0x0c08cc5cu: goto P_0c08cc5c;
case 0x0c08cc5eu: goto P_0c08cc5e;
case 0x0c08cc60u: goto P_0c08cc60;
case 0x0c08cc62u: goto P_0c08cc62;
case 0x0c08cc64u: goto P_0c08cc64;
case 0x0c08cc66u: goto P_0c08cc66;
case 0x0c08cc68u: goto P_0c08cc68;
case 0x0c08cc6au: goto P_0c08cc6a;
case 0x0c08cc6cu: goto P_0c08cc6c;
case 0x0c08cc6eu: goto P_0c08cc6e;
case 0x0c08cc70u: goto P_0c08cc70;
case 0x0c08cc72u: goto P_0c08cc72;
case 0x0c08cc74u: goto P_0c08cc74;
case 0x0c08cc76u: goto P_0c08cc76;
case 0x0c08cc78u: goto P_0c08cc78;
case 0x0c08cc7au: goto P_0c08cc7a;
case 0x0c08cc7cu: goto P_0c08cc7c;
case 0x0c08cc7eu: goto P_0c08cc7e;
case 0x0c08cc80u: goto P_0c08cc80;
case 0x0c08cc82u: goto P_0c08cc82;
case 0x0c08cc84u: goto P_0c08cc84;
case 0x0c08cc86u: goto P_0c08cc86;
case 0x0c08cc88u: goto P_0c08cc88;
case 0x0c08cc8au: goto P_0c08cc8a;
case 0x0c08cc8cu: goto P_0c08cc8c;
case 0x0c08cc8eu: goto P_0c08cc8e;
case 0x0c08cc90u: goto P_0c08cc90;
case 0x0c08cc92u: goto P_0c08cc92;
case 0x0c08cc94u: goto P_0c08cc94;
case 0x0c08cc96u: goto P_0c08cc96;
case 0x0c08cc98u: goto P_0c08cc98;
case 0x0c08cc9au: goto P_0c08cc9a;
case 0x0c08cc9cu: goto P_0c08cc9c;
case 0x0c08cc9eu: goto P_0c08cc9e;
case 0x0c08cca0u: goto P_0c08cca0;
case 0x0c08cca2u: goto P_0c08cca2;
case 0x0c08cca4u: goto P_0c08cca4;
case 0x0c08cca6u: goto P_0c08cca6;
case 0x0c08cca8u: goto P_0c08cca8;
case 0x0c08ccaau: goto P_0c08ccaa;
case 0x0c08ccacu: goto P_0c08ccac;
case 0x0c08ccaeu: goto P_0c08ccae;
case 0x0c08ccb0u: goto P_0c08ccb0;
case 0x0c08ccb2u: goto P_0c08ccb2;
case 0x0c08ccb4u: goto P_0c08ccb4;
case 0x0c08ccb6u: goto P_0c08ccb6;
case 0x0c08ccb8u: goto P_0c08ccb8;
case 0x0c08ccbau: goto P_0c08ccba;
case 0x0c08ccbcu: goto P_0c08ccbc;
case 0x0c08ccbeu: goto P_0c08ccbe;
case 0x0c08ccc0u: goto P_0c08ccc0;
case 0x0c08ccc2u: goto P_0c08ccc2;
case 0x0c08ccc4u: goto P_0c08ccc4;
case 0x0c08ccc6u: goto P_0c08ccc6;
case 0x0c08ccc8u: goto P_0c08ccc8;
case 0x0c08cccau: goto P_0c08ccca;
case 0x0c08ccccu: goto P_0c08cccc;
case 0x0c08ccceu: goto P_0c08ccce;
case 0x0c08ccd0u: goto P_0c08ccd0;
case 0x0c08ccd2u: goto P_0c08ccd2;
case 0x0c08ccd4u: goto P_0c08ccd4;
case 0x0c08ccd6u: goto P_0c08ccd6;
case 0x0c08ccd8u: goto P_0c08ccd8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08cad4: /* original 2fe6, guest PC 0x0c08cad4 */
if(!s->budget--) { s->failed_pc=0x0c08cad4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cad6;
P_0c08cad6: /* original e048, guest PC 0x0c08cad6 */
if(!s->budget--) { s->failed_pc=0x0c08cad6u; return 0; }
r[0]=0x00000048u;
goto P_0c08cad8;
P_0c08cad8: /* original 2fd6, guest PC 0x0c08cad8 */
if(!s->budget--) { s->failed_pc=0x0c08cad8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cada;
P_0c08cada: /* original 2fc6, guest PC 0x0c08cada */
if(!s->budget--) { s->failed_pc=0x0c08cadau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cadc;
P_0c08cadc: /* original 6c43, guest PC 0x0c08cadc */
if(!s->budget--) { s->failed_pc=0x0c08cadcu; return 0; }
r[12]=r[4];
goto P_0c08cade;
P_0c08cade: /* original 2fb6, guest PC 0x0c08cade */
if(!s->budget--) { s->failed_pc=0x0c08cadeu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cae0;
P_0c08cae0: /* original 2fa6, guest PC 0x0c08cae0 */
if(!s->budget--) { s->failed_pc=0x0c08cae0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cae2;
P_0c08cae2: /* original 4f22, guest PC 0x0c08cae2 */
if(!s->budget--) { s->failed_pc=0x0c08cae2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08cae4;
P_0c08cae4: /* original 00cc, guest PC 0x0c08cae4 */
if(!s->budget--) { s->failed_pc=0x0c08cae4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c08cae6;
P_0c08cae6: /* original da26, guest PC 0x0c08cae6 */
if(!s->budget--) { s->failed_pc=0x0c08cae6u; return 0; }
r[10]=read(ram,0x0c08cb80u,4);
goto P_0c08cae8;
P_0c08cae8: /* original 8801, guest PC 0x0c08cae8 */
if(!s->budget--) { s->failed_pc=0x0c08cae8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08caea;
P_0c08caea: /* original 7ff8, guest PC 0x0c08caea */
if(!s->budget--) { s->failed_pc=0x0c08caeau; return 0; }
r[15]+=0xfffffff8u;
goto P_0c08caec;
P_0c08caec: /* original 8f02, guest PC 0x0c08caec */
if(!s->budget--) { s->failed_pc=0x0c08caecu; return 0; }
cond=r[17]&1u;
r[14]=r[5];
if(!cond) { goto P_0c08caf4; }
goto P_0c08caf0;
P_0c08caee: /* original 6e53, guest PC 0x0c08caee */
if(!s->budget--) { s->failed_pc=0x0c08caeeu; return 0; }
r[14]=r[5];
goto P_0c08caf0;
P_0c08caf0: /* original a09d, guest PC 0x0c08caf0 */
if(!s->budget--) { s->failed_pc=0x0c08caf0u; return 0; }
goto P_0c08cc2e;
P_0c08caf2: /* original 0009, guest PC 0x0c08caf2 */
if(!s->budget--) { s->failed_pc=0x0c08caf2u; return 0; }
goto P_0c08caf4;
P_0c08caf4: /* original 60e2, guest PC 0x0c08caf4 */
if(!s->budget--) { s->failed_pc=0x0c08caf4u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c08caf6;
P_0c08caf6: /* original cb01, guest PC 0x0c08caf6 */
if(!s->budget--) { s->failed_pc=0x0c08caf6u; return 0; }
r[0]|=1u;
goto P_0c08caf8;
P_0c08caf8: /* original 2e02, guest PC 0x0c08caf8 */
if(!s->budget--) { s->failed_pc=0x0c08caf8u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c08cafa;
P_0c08cafa: /* original e048, guest PC 0x0c08cafa */
if(!s->budget--) { s->failed_pc=0x0c08cafau; return 0; }
r[0]=0x00000048u;
goto P_0c08cafc;
P_0c08cafc: /* original 05ee, guest PC 0x0c08cafc */
if(!s->budget--) { s->failed_pc=0x0c08cafcu; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c08cafe;
P_0c08cafe: /* original 9036, guest PC 0x0c08cafe */
if(!s->budget--) { s->failed_pc=0x0c08cafeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08cb6eu,2);
goto P_0c08cb00;
P_0c08cb00: /* original d21c, guest PC 0x0c08cb00 */
if(!s->budget--) { s->failed_pc=0x0c08cb00u; return 0; }
r[2]=read(ram,0x0c08cb74u,4);
goto P_0c08cb02;
P_0c08cb02: /* original f356, guest PC 0x0c08cb02 */
if(!s->budget--) { s->failed_pc=0x0c08cb02u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c08cb04;
P_0c08cb04: /* original e004, guest PC 0x0c08cb04 */
if(!s->budget--) { s->failed_pc=0x0c08cb04u; return 0; }
r[0]=0x00000004u;
goto P_0c08cb06;
P_0c08cb06: /* original 6420, guest PC 0x0c08cb06 */
if(!s->budget--) { s->failed_pc=0x0c08cb06u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[4]=tmp;
goto P_0c08cb08;
P_0c08cb08: /* original ff37, guest PC 0x0c08cb08 */
if(!s->budget--) { s->failed_pc=0x0c08cb08u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08cb0a;
P_0c08cb0a: /* original 9031, guest PC 0x0c08cb0a */
if(!s->budget--) { s->failed_pc=0x0c08cb0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08cb70u,2);
goto P_0c08cb0c;
P_0c08cb0c: /* original f356, guest PC 0x0c08cb0c */
if(!s->budget--) { s->failed_pc=0x0c08cb0cu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c08cb0e;
P_0c08cb0e: /* original e04c, guest PC 0x0c08cb0e */
if(!s->budget--) { s->failed_pc=0x0c08cb0eu; return 0; }
r[0]=0x0000004cu;
goto P_0c08cb10;
P_0c08cb10: /* original ff3a, guest PC 0x0c08cb10 */
if(!s->budget--) { s->failed_pc=0x0c08cb10u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08cb12;
P_0c08cb12: /* original 03ee, guest PC 0x0c08cb12 */
if(!s->budget--) { s->failed_pc=0x0c08cb12u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c08cb14;
P_0c08cb14: /* original e048, guest PC 0x0c08cb14 */
if(!s->budget--) { s->failed_pc=0x0c08cb14u; return 0; }
r[0]=0x00000048u;
goto P_0c08cb16;
P_0c08cb16: /* original d11d, guest PC 0x0c08cb16 */
if(!s->budget--) { s->failed_pc=0x0c08cb16u; return 0; }
r[1]=read(ram,0x0c08cb8cu,4);
goto P_0c08cb18;
P_0c08cb18: /* original 033e, guest PC 0x0c08cb18 */
if(!s->budget--) { s->failed_pc=0x0c08cb18u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c08cb1a;
P_0c08cb1a: /* original 2318, guest PC 0x0c08cb1a */
if(!s->budget--) { s->failed_pc=0x0c08cb1au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[1])==0)!=0);
goto P_0c08cb1c;
P_0c08cb1c: /* original 8908, guest PC 0x0c08cb1c */
if(!s->budget--) { s->failed_pc=0x0c08cb1cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08cb30; }
goto P_0c08cb1e;
P_0c08cb1e: /* original 84e8, guest PC 0x0c08cb1e */
if(!s->budget--) { s->failed_pc=0x0c08cb1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08cb20;
P_0c08cb20: /* original 640c, guest PC 0x0c08cb20 */
if(!s->budget--) { s->failed_pc=0x0c08cb20u; return 0; }
r[4]=r[0]&255u;
goto P_0c08cb22;
P_0c08cb22: /* original d01b, guest PC 0x0c08cb22 */
if(!s->budget--) { s->failed_pc=0x0c08cb22u; return 0; }
r[0]=read(ram,0x0c08cb90u,4);
goto P_0c08cb24;
P_0c08cb24: /* original 6b43, guest PC 0x0c08cb24 */
if(!s->budget--) { s->failed_pc=0x0c08cb24u; return 0; }
r[11]=r[4];
goto P_0c08cb26;
P_0c08cb26: /* original 0d4c, guest PC 0x0c08cb26 */
if(!s->budget--) { s->failed_pc=0x0c08cb26u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c08cb28;
P_0c08cb28: /* original d01a, guest PC 0x0c08cb28 */
if(!s->budget--) { s->failed_pc=0x0c08cb28u; return 0; }
r[0]=read(ram,0x0c08cb94u,4);
goto P_0c08cb2a;
P_0c08cb2a: /* original 6ddc, guest PC 0x0c08cb2a */
if(!s->budget--) { s->failed_pc=0x0c08cb2au; return 0; }
r[13]=r[13]&255u;
goto P_0c08cb2c;
P_0c08cb2c: /* original a049, guest PC 0x0c08cb2c */
if(!s->budget--) { s->failed_pc=0x0c08cb2cu; return 0; }
r[11]<<=2;
goto P_0c08cbc2;
P_0c08cb2e: /* original 4b08, guest PC 0x0c08cb2e */
if(!s->budget--) { s->failed_pc=0x0c08cb2eu; return 0; }
r[11]<<=2;
goto P_0c08cb30;
P_0c08cb30: /* original 84e8, guest PC 0x0c08cb30 */
if(!s->budget--) { s->failed_pc=0x0c08cb30u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08cb32;
P_0c08cb32: /* original e304, guest PC 0x0c08cb32 */
if(!s->budget--) { s->failed_pc=0x0c08cb32u; return 0; }
r[3]=0x00000004u;
goto P_0c08cb34;
P_0c08cb34: /* original 3432, guest PC 0x0c08cb34 */
if(!s->budget--) { s->failed_pc=0x0c08cb34u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[3])!=0);
goto P_0c08cb36;
P_0c08cb36: /* original 650c, guest PC 0x0c08cb36 */
if(!s->budget--) { s->failed_pc=0x0c08cb36u; return 0; }
r[5]=r[0]&255u;
goto P_0c08cb38;
P_0c08cb38: /* original d017, guest PC 0x0c08cb38 */
if(!s->budget--) { s->failed_pc=0x0c08cb38u; return 0; }
r[0]=read(ram,0x0c08cb98u,4);
goto P_0c08cb3a;
P_0c08cb3a: /* original 6b53, guest PC 0x0c08cb3a */
if(!s->budget--) { s->failed_pc=0x0c08cb3au; return 0; }
r[11]=r[5];
goto P_0c08cb3c;
P_0c08cb3c: /* original 4b08, guest PC 0x0c08cb3c */
if(!s->budget--) { s->failed_pc=0x0c08cb3cu; return 0; }
r[11]<<=2;
goto P_0c08cb3e;
P_0c08cb3e: /* original 0d5c, guest PC 0x0c08cb3e */
if(!s->budget--) { s->failed_pc=0x0c08cb3eu; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c08cb40;
P_0c08cb40: /* original d016, guest PC 0x0c08cb40 */
if(!s->budget--) { s->failed_pc=0x0c08cb40u; return 0; }
r[0]=read(ram,0x0c08cb9cu,4);
goto P_0c08cb42;
P_0c08cb42: /* original 6ddc, guest PC 0x0c08cb42 */
if(!s->budget--) { s->failed_pc=0x0c08cb42u; return 0; }
r[13]=r[13]&255u;
goto P_0c08cb44;
P_0c08cb44: /* original 8f3f, guest PC 0x0c08cb44 */
if(!s->budget--) { s->failed_pc=0x0c08cb44u; return 0; }
cond=r[17]&1u;
r[11]=read(ram,r[11]+r[0],4);
if(!cond) { goto P_0c08cbc6; }
goto P_0c08cb48;
P_0c08cb46: /* original 0bbe, guest PC 0x0c08cb46 */
if(!s->budget--) { s->failed_pc=0x0c08cb46u; return 0; }
r[11]=read(ram,r[11]+r[0],4);
goto P_0c08cb48;
P_0c08cb48: /* original 4a0b, guest PC 0x0c08cb48 */
if(!s->budget--) { s->failed_pc=0x0c08cb48u; return 0; }
target=r[10];
r[16]=code_base|0x0c08cb4cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cb4cu) { target=s->pc; goto dispatch; }
goto P_0c08cb4c;
P_0c08cb4a: /* original 0009, guest PC 0x0c08cb4a */
if(!s->budget--) { s->failed_pc=0x0c08cb4au; return 0; }
goto P_0c08cb4c;
P_0c08cb4c: /* original c803, guest PC 0x0c08cb4c */
if(!s->budget--) { s->failed_pc=0x0c08cb4cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&3u)==0)!=0);
goto P_0c08cb4e;
P_0c08cb4e: /* original 893f, guest PC 0x0c08cb4e */
if(!s->budget--) { s->failed_pc=0x0c08cb4eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08cbd0; }
goto P_0c08cb50;
P_0c08cb50: /* original c713, guest PC 0x0c08cb50 */
if(!s->budget--) { s->failed_pc=0x0c08cb50u; return 0; }
r[0]=code_base|0x0008cba0u;
goto P_0c08cb52;
P_0c08cb52: /* original f408, guest PC 0x0c08cb52 */
if(!s->budget--) { s->failed_pc=0x0c08cb52u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c08cb54;
P_0c08cb54: /* original e004, guest PC 0x0c08cb54 */
if(!s->budget--) { s->failed_pc=0x0c08cb54u; return 0; }
r[0]=0x00000004u;
goto P_0c08cb56;
P_0c08cb56: /* original f3f6, guest PC 0x0c08cb56 */
if(!s->budget--) { s->failed_pc=0x0c08cb56u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08cb58;
P_0c08cb58: /* original f435, guest PC 0x0c08cb58 */
if(!s->budget--) { s->failed_pc=0x0c08cb58u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c08cb5a;
P_0c08cb5a: /* original 8b27, guest PC 0x0c08cb5a */
if(!s->budget--) { s->failed_pc=0x0c08cb5au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08cbac; }
goto P_0c08cb5c;
P_0c08cb5c: /* original 84e8, guest PC 0x0c08cb5c */
if(!s->budget--) { s->failed_pc=0x0c08cb5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08cb5e;
P_0c08cb5e: /* original 640c, guest PC 0x0c08cb5e */
if(!s->budget--) { s->failed_pc=0x0c08cb5eu; return 0; }
r[4]=r[0]&255u;
goto P_0c08cb60;
P_0c08cb60: /* original d010, guest PC 0x0c08cb60 */
if(!s->budget--) { s->failed_pc=0x0c08cb60u; return 0; }
r[0]=read(ram,0x0c08cba4u,4);
goto P_0c08cb62;
P_0c08cb62: /* original 6b43, guest PC 0x0c08cb62 */
if(!s->budget--) { s->failed_pc=0x0c08cb62u; return 0; }
r[11]=r[4];
goto P_0c08cb64;
P_0c08cb64: /* original 0d4c, guest PC 0x0c08cb64 */
if(!s->budget--) { s->failed_pc=0x0c08cb64u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c08cb66;
P_0c08cb66: /* original d010, guest PC 0x0c08cb66 */
if(!s->budget--) { s->failed_pc=0x0c08cb66u; return 0; }
r[0]=read(ram,0x0c08cba8u,4);
goto P_0c08cb68;
P_0c08cb68: /* original 6ddc, guest PC 0x0c08cb68 */
if(!s->budget--) { s->failed_pc=0x0c08cb68u; return 0; }
r[13]=r[13]&255u;
goto P_0c08cb6a;
P_0c08cb6a: /* original a02a, guest PC 0x0c08cb6a */
if(!s->budget--) { s->failed_pc=0x0c08cb6au; return 0; }
r[11]<<=2;
goto P_0c08cbc2;
P_0c08cb6c: /* original 4b08, guest PC 0x0c08cb6c */
if(!s->budget--) { s->failed_pc=0x0c08cb6cu; return 0; }
r[11]<<=2;
if(!vf3_matrix_family(0x0c08cb6eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08cb6eu; return 0; } return 1;
P_0c08cbac: /* original f2f8, guest PC 0x0c08cbac */
if(!s->budget--) { s->failed_pc=0x0c08cbacu; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c08cbae;
P_0c08cbae: /* original f425, guest PC 0x0c08cbae */
if(!s->budget--) { s->failed_pc=0x0c08cbaeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c08cbb0;
P_0c08cbb0: /* original 8b09, guest PC 0x0c08cbb0 */
if(!s->budget--) { s->failed_pc=0x0c08cbb0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08cbc6; }
goto P_0c08cbb2;
P_0c08cbb2: /* original 84e8, guest PC 0x0c08cbb2 */
if(!s->budget--) { s->failed_pc=0x0c08cbb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08cbb4;
P_0c08cbb4: /* original 640c, guest PC 0x0c08cbb4 */
if(!s->budget--) { s->failed_pc=0x0c08cbb4u; return 0; }
r[4]=r[0]&255u;
goto P_0c08cbb6;
P_0c08cbb6: /* original d04a, guest PC 0x0c08cbb6 */
if(!s->budget--) { s->failed_pc=0x0c08cbb6u; return 0; }
r[0]=read(ram,0x0c08cce0u,4);
goto P_0c08cbb8;
P_0c08cbb8: /* original 6b43, guest PC 0x0c08cbb8 */
if(!s->budget--) { s->failed_pc=0x0c08cbb8u; return 0; }
r[11]=r[4];
goto P_0c08cbba;
P_0c08cbba: /* original 4b08, guest PC 0x0c08cbba */
if(!s->budget--) { s->failed_pc=0x0c08cbbau; return 0; }
r[11]<<=2;
goto P_0c08cbbc;
P_0c08cbbc: /* original 0d4c, guest PC 0x0c08cbbc */
if(!s->budget--) { s->failed_pc=0x0c08cbbcu; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c08cbbe;
P_0c08cbbe: /* original d049, guest PC 0x0c08cbbe */
if(!s->budget--) { s->failed_pc=0x0c08cbbeu; return 0; }
r[0]=read(ram,0x0c08cce4u,4);
goto P_0c08cbc0;
P_0c08cbc0: /* original 6ddc, guest PC 0x0c08cbc0 */
if(!s->budget--) { s->failed_pc=0x0c08cbc0u; return 0; }
r[13]=r[13]&255u;
goto P_0c08cbc2;
P_0c08cbc2: /* original a005, guest PC 0x0c08cbc2 */
if(!s->budget--) { s->failed_pc=0x0c08cbc2u; return 0; }
r[11]=read(ram,r[11]+r[0],4);
goto P_0c08cbd0;
P_0c08cbc4: /* original 0bbe, guest PC 0x0c08cbc4 */
if(!s->budget--) { s->failed_pc=0x0c08cbc4u; return 0; }
r[11]=read(ram,r[11]+r[0],4);
goto P_0c08cbc6;
P_0c08cbc6: /* original 84e8, guest PC 0x0c08cbc6 */
if(!s->budget--) { s->failed_pc=0x0c08cbc6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08cbc8;
P_0c08cbc8: /* original d147, guest PC 0x0c08cbc8 */
if(!s->budget--) { s->failed_pc=0x0c08cbc8u; return 0; }
r[1]=read(ram,0x0c08cce8u,4);
goto P_0c08cbca;
P_0c08cbca: /* original 600c, guest PC 0x0c08cbca */
if(!s->budget--) { s->failed_pc=0x0c08cbcau; return 0; }
r[0]=r[0]&255u;
goto P_0c08cbcc;
P_0c08cbcc: /* original 0d1c, guest PC 0x0c08cbcc */
if(!s->budget--) { s->failed_pc=0x0c08cbccu; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c08cbce;
P_0c08cbce: /* original 6ddc, guest PC 0x0c08cbce */
if(!s->budget--) { s->failed_pc=0x0c08cbceu; return 0; }
r[13]=r[13]&255u;
goto P_0c08cbd0;
P_0c08cbd0: /* original 4a0b, guest PC 0x0c08cbd0 */
if(!s->budget--) { s->failed_pc=0x0c08cbd0u; return 0; }
target=r[10];
r[16]=code_base|0x0c08cbd4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cbd4u) { target=s->pc; goto dispatch; }
goto P_0c08cbd4;
P_0c08cbd2: /* original 0009, guest PC 0x0c08cbd2 */
if(!s->budget--) { s->failed_pc=0x0c08cbd2u; return 0; }
goto P_0c08cbd4;
P_0c08cbd4: /* original d345, guest PC 0x0c08cbd4 */
if(!s->budget--) { s->failed_pc=0x0c08cbd4u; return 0; }
r[3]=read(ram,0x0c08ccecu,4);
goto P_0c08cbd6;
P_0c08cbd6: /* original 6103, guest PC 0x0c08cbd6 */
if(!s->budget--) { s->failed_pc=0x0c08cbd6u; return 0; }
r[1]=r[0];
goto P_0c08cbd8;
P_0c08cbd8: /* original 430b, guest PC 0x0c08cbd8 */
if(!s->budget--) { s->failed_pc=0x0c08cbd8u; return 0; }
target=r[3];
r[16]=code_base|0x0c08cbdcu;
r[0]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cbdcu) { target=s->pc; goto dispatch; }
goto P_0c08cbdc;
P_0c08cbda: /* original 60d3, guest PC 0x0c08cbda */
if(!s->budget--) { s->failed_pc=0x0c08cbdau; return 0; }
r[0]=r[13];
goto P_0c08cbdc;
P_0c08cbdc: /* original 4000, guest PC 0x0c08cbdc */
if(!s->budget--) { s->failed_pc=0x0c08cbdcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c08cbde;
P_0c08cbde: /* original 04bd, guest PC 0x0c08cbde */
if(!s->budget--) { s->failed_pc=0x0c08cbdeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c08cbe0;
P_0c08cbe0: /* original e028, guest PC 0x0c08cbe0 */
if(!s->budget--) { s->failed_pc=0x0c08cbe0u; return 0; }
r[0]=0x00000028u;
goto P_0c08cbe2;
P_0c08cbe2: /* original e500, guest PC 0x0c08cbe2 */
if(!s->budget--) { s->failed_pc=0x0c08cbe2u; return 0; }
r[5]=0x00000000u;
goto P_0c08cbe4;
P_0c08cbe4: /* original 644d, guest PC 0x0c08cbe4 */
if(!s->budget--) { s->failed_pc=0x0c08cbe4u; return 0; }
r[4]=r[4]&65535u;
goto P_0c08cbe6;
P_0c08cbe6: /* original 0c45, guest PC 0x0c08cbe6 */
if(!s->budget--) { s->failed_pc=0x0c08cbe6u; return 0; }
write(ram,r[12]+r[0],r[4],2);
goto P_0c08cbe8;
P_0c08cbe8: /* original e040, guest PC 0x0c08cbe8 */
if(!s->budget--) { s->failed_pc=0x0c08cbe8u; return 0; }
r[0]=0x00000040u;
goto P_0c08cbea;
P_0c08cbea: /* original 1e4d, guest PC 0x0c08cbea */
if(!s->budget--) { s->failed_pc=0x0c08cbeau; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c08cbec;
P_0c08cbec: /* original 0e56, guest PC 0x0c08cbec */
if(!s->budget--) { s->failed_pc=0x0c08cbecu; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c08cbee;
P_0c08cbee: /* original b2b3, guest PC 0x0c08cbee */
if(!s->budget--) { s->failed_pc=0x0c08cbeeu; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08cbf2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cbf2u) { target=s->pc; goto dispatch; }
goto P_0c08cbf2;
P_0c08cbf0: /* original 64e3, guest PC 0x0c08cbf0 */
if(!s->budget--) { s->failed_pc=0x0c08cbf0u; return 0; }
r[4]=r[14];
goto P_0c08cbf2;
P_0c08cbf2: /* original e200, guest PC 0x0c08cbf2 */
if(!s->budget--) { s->failed_pc=0x0c08cbf2u; return 0; }
r[2]=0x00000000u;
goto P_0c08cbf4;
P_0c08cbf4: /* original 54ee, guest PC 0x0c08cbf4 */
if(!s->budget--) { s->failed_pc=0x0c08cbf4u; return 0; }
r[4]=read(ram,r[14]+56,4);
goto P_0c08cbf6;
P_0c08cbf6: /* original e02c, guest PC 0x0c08cbf6 */
if(!s->budget--) { s->failed_pc=0x0c08cbf6u; return 0; }
r[0]=0x0000002cu;
goto P_0c08cbf8;
P_0c08cbf8: /* original 55ef, guest PC 0x0c08cbf8 */
if(!s->budget--) { s->failed_pc=0x0c08cbf8u; return 0; }
r[5]=read(ram,r[14]+60,4);
goto P_0c08cbfa;
P_0c08cbfa: /* original 0c24, guest PC 0x0c08cbfa */
if(!s->budget--) { s->failed_pc=0x0c08cbfau; return 0; }
write(ram,r[12]+r[0],r[2],1);
goto P_0c08cbfc;
P_0c08cbfc: /* original e02d, guest PC 0x0c08cbfc */
if(!s->budget--) { s->failed_pc=0x0c08cbfcu; return 0; }
r[0]=0x0000002du;
goto P_0c08cbfe;
P_0c08cbfe: /* original 0c44, guest PC 0x0c08cbfe */
if(!s->budget--) { s->failed_pc=0x0c08cbfeu; return 0; }
write(ram,r[12]+r[0],r[4],1);
goto P_0c08cc00;
P_0c08cc00: /* original 6053, guest PC 0x0c08cc00 */
if(!s->budget--) { s->failed_pc=0x0c08cc00u; return 0; }
r[0]=r[5];
goto P_0c08cc02;
P_0c08cc02: /* original 81ca, guest PC 0x0c08cc02 */
if(!s->budget--) { s->failed_pc=0x0c08cc02u; return 0; }
write(ram,r[12]+20,r[0],2);
goto P_0c08cc04;
P_0c08cc04: /* original e04c, guest PC 0x0c08cc04 */
if(!s->budget--) { s->failed_pc=0x0c08cc04u; return 0; }
r[0]=0x0000004cu;
goto P_0c08cc06;
P_0c08cc06: /* original 04ee, guest PC 0x0c08cc06 */
if(!s->budget--) { s->failed_pc=0x0c08cc06u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c08cc08;
P_0c08cc08: /* original e60a, guest PC 0x0c08cc08 */
if(!s->budget--) { s->failed_pc=0x0c08cc08u; return 0; }
r[6]=0x0000000au;
goto P_0c08cc0a;
P_0c08cc0a: /* original 9066, guest PC 0x0c08cc0a */
if(!s->budget--) { s->failed_pc=0x0c08cc0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ccdau,2);
goto P_0c08cc0c;
P_0c08cc0c: /* original 6d63, guest PC 0x0c08cc0c */
if(!s->budget--) { s->failed_pc=0x0c08cc0cu; return 0; }
r[13]=r[6];
goto P_0c08cc0e;
P_0c08cc0e: /* original 044d, guest PC 0x0c08cc0e */
if(!s->budget--) { s->failed_pc=0x0c08cc0eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08cc10;
P_0c08cc10: /* original 3467, guest PC 0x0c08cc10 */
if(!s->budget--) { s->failed_pc=0x0c08cc10u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[6])!=0);
goto P_0c08cc12;
P_0c08cc12: /* original 8f01, guest PC 0x0c08cc12 */
if(!s->budget--) { s->failed_pc=0x0c08cc12u; return 0; }
cond=r[17]&1u;
r[5]=r[4];
if(!cond) { goto P_0c08cc18; }
goto P_0c08cc16;
P_0c08cc14: /* original 6543, guest PC 0x0c08cc14 */
if(!s->budget--) { s->failed_pc=0x0c08cc14u; return 0; }
r[5]=r[4];
goto P_0c08cc16;
P_0c08cc16: /* original 6d53, guest PC 0x0c08cc16 */
if(!s->budget--) { s->failed_pc=0x0c08cc16u; return 0; }
r[13]=r[5];
goto P_0c08cc18;
P_0c08cc18: /* original 4a0b, guest PC 0x0c08cc18 */
if(!s->budget--) { s->failed_pc=0x0c08cc18u; return 0; }
target=r[10];
r[16]=code_base|0x0c08cc1cu;
r[17]=(r[17]&~1u)|((r[13]&1)!=0);
r[13]>>=1;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cc1cu) { target=s->pc; goto dispatch; }
goto P_0c08cc1c;
P_0c08cc1a: /* original 4d01, guest PC 0x0c08cc1a */
if(!s->budget--) { s->failed_pc=0x0c08cc1au; return 0; }
r[17]=(r[17]&~1u)|((r[13]&1)!=0);
r[13]>>=1;
goto P_0c08cc1c;
P_0c08cc1c: /* original d233, guest PC 0x0c08cc1c */
if(!s->budget--) { s->failed_pc=0x0c08cc1cu; return 0; }
r[2]=read(ram,0x0c08ccecu,4);
goto P_0c08cc1e;
P_0c08cc1e: /* original 6103, guest PC 0x0c08cc1e */
if(!s->budget--) { s->failed_pc=0x0c08cc1eu; return 0; }
r[1]=r[0];
goto P_0c08cc20;
P_0c08cc20: /* original 420b, guest PC 0x0c08cc20 */
if(!s->budget--) { s->failed_pc=0x0c08cc20u; return 0; }
target=r[2];
r[16]=code_base|0x0c08cc24u;
r[0]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cc24u) { target=s->pc; goto dispatch; }
goto P_0c08cc24;
P_0c08cc22: /* original 60d3, guest PC 0x0c08cc22 */
if(!s->budget--) { s->failed_pc=0x0c08cc22u; return 0; }
r[0]=r[13];
goto P_0c08cc24;
P_0c08cc24: /* original 81cc, guest PC 0x0c08cc24 */
if(!s->budget--) { s->failed_pc=0x0c08cc24u; return 0; }
write(ram,r[12]+24,r[0],2);
goto P_0c08cc26;
P_0c08cc26: /* original e048, guest PC 0x0c08cc26 */
if(!s->budget--) { s->failed_pc=0x0c08cc26u; return 0; }
r[0]=0x00000048u;
goto P_0c08cc28;
P_0c08cc28: /* original 03cc, guest PC 0x0c08cc28 */
if(!s->budget--) { s->failed_pc=0x0c08cc28u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c08cc2a;
P_0c08cc2a: /* original 7301, guest PC 0x0c08cc2a */
if(!s->budget--) { s->failed_pc=0x0c08cc2au; return 0; }
r[3]+=0x00000001u;
goto P_0c08cc2c;
P_0c08cc2c: /* original 0c34, guest PC 0x0c08cc2c */
if(!s->budget--) { s->failed_pc=0x0c08cc2cu; return 0; }
write(ram,r[12]+r[0],r[3],1);
goto P_0c08cc2e;
P_0c08cc2e: /* original 7f08, guest PC 0x0c08cc2e */
if(!s->budget--) { s->failed_pc=0x0c08cc2eu; return 0; }
r[15]+=0x00000008u;
goto P_0c08cc30;
P_0c08cc30: /* original 4f26, guest PC 0x0c08cc30 */
if(!s->budget--) { s->failed_pc=0x0c08cc30u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08cc32;
P_0c08cc32: /* original 6af6, guest PC 0x0c08cc32 */
if(!s->budget--) { s->failed_pc=0x0c08cc32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08cc34;
P_0c08cc34: /* original 6bf6, guest PC 0x0c08cc34 */
if(!s->budget--) { s->failed_pc=0x0c08cc34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08cc36;
P_0c08cc36: /* original 6cf6, guest PC 0x0c08cc36 */
if(!s->budget--) { s->failed_pc=0x0c08cc36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08cc38;
P_0c08cc38: /* original 6df6, guest PC 0x0c08cc38 */
if(!s->budget--) { s->failed_pc=0x0c08cc38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08cc3a;
P_0c08cc3a: /* original 000b, guest PC 0x0c08cc3a */
if(!s->budget--) { s->failed_pc=0x0c08cc3au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08cc3c: /* original 6ef6, guest PC 0x0c08cc3c */
if(!s->budget--) { s->failed_pc=0x0c08cc3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08cc3e;
P_0c08cc3e: /* original 2fe6, guest PC 0x0c08cc3e */
if(!s->budget--) { s->failed_pc=0x0c08cc3eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cc40;
P_0c08cc40: /* original 6e43, guest PC 0x0c08cc40 */
if(!s->budget--) { s->failed_pc=0x0c08cc40u; return 0; }
r[14]=r[4];
goto P_0c08cc42;
P_0c08cc42: /* original e048, guest PC 0x0c08cc42 */
if(!s->budget--) { s->failed_pc=0x0c08cc42u; return 0; }
r[0]=0x00000048u;
goto P_0c08cc44;
P_0c08cc44: /* original 2fd6, guest PC 0x0c08cc44 */
if(!s->budget--) { s->failed_pc=0x0c08cc44u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cc46;
P_0c08cc46: /* original 00ec, guest PC 0x0c08cc46 */
if(!s->budget--) { s->failed_pc=0x0c08cc46u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08cc48;
P_0c08cc48: /* original 4f22, guest PC 0x0c08cc48 */
if(!s->budget--) { s->failed_pc=0x0c08cc48u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08cc4a;
P_0c08cc4a: /* original 8801, guest PC 0x0c08cc4a */
if(!s->budget--) { s->failed_pc=0x0c08cc4au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08cc4c;
P_0c08cc4c: /* original 8d1b, guest PC 0x0c08cc4c */
if(!s->budget--) { s->failed_pc=0x0c08cc4cu; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c08cc86; }
goto P_0c08cc50;
P_0c08cc4e: /* original 6d53, guest PC 0x0c08cc4e */
if(!s->budget--) { s->failed_pc=0x0c08cc4eu; return 0; }
r[13]=r[5];
goto P_0c08cc50;
P_0c08cc50: /* original 60d2, guest PC 0x0c08cc50 */
if(!s->budget--) { s->failed_pc=0x0c08cc50u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c08cc52;
P_0c08cc52: /* original e500, guest PC 0x0c08cc52 */
if(!s->budget--) { s->failed_pc=0x0c08cc52u; return 0; }
r[5]=0x00000000u;
goto P_0c08cc54;
P_0c08cc54: /* original cb01, guest PC 0x0c08cc54 */
if(!s->budget--) { s->failed_pc=0x0c08cc54u; return 0; }
r[0]|=1u;
goto P_0c08cc56;
P_0c08cc56: /* original 2d02, guest PC 0x0c08cc56 */
if(!s->budget--) { s->failed_pc=0x0c08cc56u; return 0; }
write(ram,r[13],r[0],4);
goto P_0c08cc58;
P_0c08cc58: /* original e028, guest PC 0x0c08cc58 */
if(!s->budget--) { s->failed_pc=0x0c08cc58u; return 0; }
r[0]=0x00000028u;
goto P_0c08cc5a;
P_0c08cc5a: /* original 943f, guest PC 0x0c08cc5a */
if(!s->budget--) { s->failed_pc=0x0c08cc5au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ccdcu,2);
goto P_0c08cc5c;
P_0c08cc5c: /* original 0e45, guest PC 0x0c08cc5c */
if(!s->budget--) { s->failed_pc=0x0c08cc5cu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08cc5e;
P_0c08cc5e: /* original e040, guest PC 0x0c08cc5e */
if(!s->budget--) { s->failed_pc=0x0c08cc5eu; return 0; }
r[0]=0x00000040u;
goto P_0c08cc60;
P_0c08cc60: /* original 1d4d, guest PC 0x0c08cc60 */
if(!s->budget--) { s->failed_pc=0x0c08cc60u; return 0; }
write(ram,r[13]+52,r[4],4);
goto P_0c08cc62;
P_0c08cc62: /* original 0d56, guest PC 0x0c08cc62 */
if(!s->budget--) { s->failed_pc=0x0c08cc62u; return 0; }
write(ram,r[13]+r[0],r[5],4);
goto P_0c08cc64;
P_0c08cc64: /* original b278, guest PC 0x0c08cc64 */
if(!s->budget--) { s->failed_pc=0x0c08cc64u; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08cc68u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cc68u) { target=s->pc; goto dispatch; }
goto P_0c08cc68;
P_0c08cc66: /* original 64d3, guest PC 0x0c08cc66 */
if(!s->budget--) { s->failed_pc=0x0c08cc66u; return 0; }
r[4]=r[13];
goto P_0c08cc68;
P_0c08cc68: /* original e200, guest PC 0x0c08cc68 */
if(!s->budget--) { s->failed_pc=0x0c08cc68u; return 0; }
r[2]=0x00000000u;
goto P_0c08cc6a;
P_0c08cc6a: /* original 54de, guest PC 0x0c08cc6a */
if(!s->budget--) { s->failed_pc=0x0c08cc6au; return 0; }
r[4]=read(ram,r[13]+56,4);
goto P_0c08cc6c;
P_0c08cc6c: /* original e02c, guest PC 0x0c08cc6c */
if(!s->budget--) { s->failed_pc=0x0c08cc6cu; return 0; }
r[0]=0x0000002cu;
goto P_0c08cc6e;
P_0c08cc6e: /* original 55df, guest PC 0x0c08cc6e */
if(!s->budget--) { s->failed_pc=0x0c08cc6eu; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c08cc70;
P_0c08cc70: /* original 0e24, guest PC 0x0c08cc70 */
if(!s->budget--) { s->failed_pc=0x0c08cc70u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c08cc72;
P_0c08cc72: /* original e02d, guest PC 0x0c08cc72 */
if(!s->budget--) { s->failed_pc=0x0c08cc72u; return 0; }
r[0]=0x0000002du;
goto P_0c08cc74;
P_0c08cc74: /* original 0e44, guest PC 0x0c08cc74 */
if(!s->budget--) { s->failed_pc=0x0c08cc74u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c08cc76;
P_0c08cc76: /* original 6053, guest PC 0x0c08cc76 */
if(!s->budget--) { s->failed_pc=0x0c08cc76u; return 0; }
r[0]=r[5];
goto P_0c08cc78;
P_0c08cc78: /* original 81ea, guest PC 0x0c08cc78 */
if(!s->budget--) { s->failed_pc=0x0c08cc78u; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c08cc7a;
P_0c08cc7a: /* original e010, guest PC 0x0c08cc7a */
if(!s->budget--) { s->failed_pc=0x0c08cc7au; return 0; }
r[0]=0x00000010u;
goto P_0c08cc7c;
P_0c08cc7c: /* original 81ef, guest PC 0x0c08cc7c */
if(!s->budget--) { s->failed_pc=0x0c08cc7cu; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c08cc7e;
P_0c08cc7e: /* original e048, guest PC 0x0c08cc7e */
if(!s->budget--) { s->failed_pc=0x0c08cc7eu; return 0; }
r[0]=0x00000048u;
goto P_0c08cc80;
P_0c08cc80: /* original 03ec, guest PC 0x0c08cc80 */
if(!s->budget--) { s->failed_pc=0x0c08cc80u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08cc82;
P_0c08cc82: /* original 7301, guest PC 0x0c08cc82 */
if(!s->budget--) { s->failed_pc=0x0c08cc82u; return 0; }
r[3]+=0x00000001u;
goto P_0c08cc84;
P_0c08cc84: /* original 0e34, guest PC 0x0c08cc84 */
if(!s->budget--) { s->failed_pc=0x0c08cc84u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08cc86;
P_0c08cc86: /* original 4f26, guest PC 0x0c08cc86 */
if(!s->budget--) { s->failed_pc=0x0c08cc86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08cc88;
P_0c08cc88: /* original 6df6, guest PC 0x0c08cc88 */
if(!s->budget--) { s->failed_pc=0x0c08cc88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08cc8a;
P_0c08cc8a: /* original 000b, guest PC 0x0c08cc8a */
if(!s->budget--) { s->failed_pc=0x0c08cc8au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08cc8c: /* original 6ef6, guest PC 0x0c08cc8c */
if(!s->budget--) { s->failed_pc=0x0c08cc8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08cc8e;
P_0c08cc8e: /* original 2fe6, guest PC 0x0c08cc8e */
if(!s->budget--) { s->failed_pc=0x0c08cc8eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cc90;
P_0c08cc90: /* original 6e43, guest PC 0x0c08cc90 */
if(!s->budget--) { s->failed_pc=0x0c08cc90u; return 0; }
r[14]=r[4];
goto P_0c08cc92;
P_0c08cc92: /* original e048, guest PC 0x0c08cc92 */
if(!s->budget--) { s->failed_pc=0x0c08cc92u; return 0; }
r[0]=0x00000048u;
goto P_0c08cc94;
P_0c08cc94: /* original 2fd6, guest PC 0x0c08cc94 */
if(!s->budget--) { s->failed_pc=0x0c08cc94u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cc96;
P_0c08cc96: /* original 00ec, guest PC 0x0c08cc96 */
if(!s->budget--) { s->failed_pc=0x0c08cc96u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08cc98;
P_0c08cc98: /* original 4f22, guest PC 0x0c08cc98 */
if(!s->budget--) { s->failed_pc=0x0c08cc98u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08cc9a;
P_0c08cc9a: /* original 8801, guest PC 0x0c08cc9a */
if(!s->budget--) { s->failed_pc=0x0c08cc9au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08cc9c;
P_0c08cc9c: /* original 8d19, guest PC 0x0c08cc9c */
if(!s->budget--) { s->failed_pc=0x0c08cc9cu; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c08ccd2; }
goto P_0c08cca0;
P_0c08cc9e: /* original 6d53, guest PC 0x0c08cc9e */
if(!s->budget--) { s->failed_pc=0x0c08cc9eu; return 0; }
r[13]=r[5];
goto P_0c08cca0;
P_0c08cca0: /* original 60d2, guest PC 0x0c08cca0 */
if(!s->budget--) { s->failed_pc=0x0c08cca0u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c08cca2;
P_0c08cca2: /* original e500, guest PC 0x0c08cca2 */
if(!s->budget--) { s->failed_pc=0x0c08cca2u; return 0; }
r[5]=0x00000000u;
goto P_0c08cca4;
P_0c08cca4: /* original cb01, guest PC 0x0c08cca4 */
if(!s->budget--) { s->failed_pc=0x0c08cca4u; return 0; }
r[0]|=1u;
goto P_0c08cca6;
P_0c08cca6: /* original 2d02, guest PC 0x0c08cca6 */
if(!s->budget--) { s->failed_pc=0x0c08cca6u; return 0; }
write(ram,r[13],r[0],4);
goto P_0c08cca8;
P_0c08cca8: /* original e028, guest PC 0x0c08cca8 */
if(!s->budget--) { s->failed_pc=0x0c08cca8u; return 0; }
r[0]=0x00000028u;
goto P_0c08ccaa;
P_0c08ccaa: /* original 9418, guest PC 0x0c08ccaa */
if(!s->budget--) { s->failed_pc=0x0c08ccaau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ccdeu,2);
goto P_0c08ccac;
P_0c08ccac: /* original 0e45, guest PC 0x0c08ccac */
if(!s->budget--) { s->failed_pc=0x0c08ccacu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08ccae;
P_0c08ccae: /* original e040, guest PC 0x0c08ccae */
if(!s->budget--) { s->failed_pc=0x0c08ccaeu; return 0; }
r[0]=0x00000040u;
goto P_0c08ccb0;
P_0c08ccb0: /* original 1d4d, guest PC 0x0c08ccb0 */
if(!s->budget--) { s->failed_pc=0x0c08ccb0u; return 0; }
write(ram,r[13]+52,r[4],4);
goto P_0c08ccb2;
P_0c08ccb2: /* original 0d56, guest PC 0x0c08ccb2 */
if(!s->budget--) { s->failed_pc=0x0c08ccb2u; return 0; }
write(ram,r[13]+r[0],r[5],4);
goto P_0c08ccb4;
P_0c08ccb4: /* original b250, guest PC 0x0c08ccb4 */
if(!s->budget--) { s->failed_pc=0x0c08ccb4u; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08ccb8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ccb8u) { target=s->pc; goto dispatch; }
goto P_0c08ccb8;
P_0c08ccb6: /* original 64d3, guest PC 0x0c08ccb6 */
if(!s->budget--) { s->failed_pc=0x0c08ccb6u; return 0; }
r[4]=r[13];
goto P_0c08ccb8;
P_0c08ccb8: /* original e200, guest PC 0x0c08ccb8 */
if(!s->budget--) { s->failed_pc=0x0c08ccb8u; return 0; }
r[2]=0x00000000u;
goto P_0c08ccba;
P_0c08ccba: /* original 55de, guest PC 0x0c08ccba */
if(!s->budget--) { s->failed_pc=0x0c08ccbau; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c08ccbc;
P_0c08ccbc: /* original e02c, guest PC 0x0c08ccbc */
if(!s->budget--) { s->failed_pc=0x0c08ccbcu; return 0; }
r[0]=0x0000002cu;
goto P_0c08ccbe;
P_0c08ccbe: /* original 54df, guest PC 0x0c08ccbe */
if(!s->budget--) { s->failed_pc=0x0c08ccbeu; return 0; }
r[4]=read(ram,r[13]+60,4);
goto P_0c08ccc0;
P_0c08ccc0: /* original 0e24, guest PC 0x0c08ccc0 */
if(!s->budget--) { s->failed_pc=0x0c08ccc0u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c08ccc2;
P_0c08ccc2: /* original e02d, guest PC 0x0c08ccc2 */
if(!s->budget--) { s->failed_pc=0x0c08ccc2u; return 0; }
r[0]=0x0000002du;
goto P_0c08ccc4;
P_0c08ccc4: /* original 0e54, guest PC 0x0c08ccc4 */
if(!s->budget--) { s->failed_pc=0x0c08ccc4u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c08ccc6;
P_0c08ccc6: /* original 6043, guest PC 0x0c08ccc6 */
if(!s->budget--) { s->failed_pc=0x0c08ccc6u; return 0; }
r[0]=r[4];
goto P_0c08ccc8;
P_0c08ccc8: /* original 81ea, guest PC 0x0c08ccc8 */
if(!s->budget--) { s->failed_pc=0x0c08ccc8u; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c08ccca;
P_0c08ccca: /* original e048, guest PC 0x0c08ccca */
if(!s->budget--) { s->failed_pc=0x0c08cccau; return 0; }
r[0]=0x00000048u;
goto P_0c08cccc;
P_0c08cccc: /* original 03ec, guest PC 0x0c08cccc */
if(!s->budget--) { s->failed_pc=0x0c08ccccu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08ccce;
P_0c08ccce: /* original 7301, guest PC 0x0c08ccce */
if(!s->budget--) { s->failed_pc=0x0c08ccceu; return 0; }
r[3]+=0x00000001u;
goto P_0c08ccd0;
P_0c08ccd0: /* original 0e34, guest PC 0x0c08ccd0 */
if(!s->budget--) { s->failed_pc=0x0c08ccd0u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08ccd2;
P_0c08ccd2: /* original 4f26, guest PC 0x0c08ccd2 */
if(!s->budget--) { s->failed_pc=0x0c08ccd2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08ccd4;
P_0c08ccd4: /* original 6df6, guest PC 0x0c08ccd4 */
if(!s->budget--) { s->failed_pc=0x0c08ccd4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08ccd6;
P_0c08ccd6: /* original 000b, guest PC 0x0c08ccd6 */
if(!s->budget--) { s->failed_pc=0x0c08ccd6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08ccd8: /* original 6ef6, guest PC 0x0c08ccd8 */
if(!s->budget--) { s->failed_pc=0x0c08ccd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08ccdau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08ccdau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
