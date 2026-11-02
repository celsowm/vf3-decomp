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
int vf3_away_batch21_adapter_18(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0abad0u: goto P_0c0abad0;
case 0x0c0abad2u: goto P_0c0abad2;
case 0x0c0abad4u: goto P_0c0abad4;
case 0x0c0abad6u: goto P_0c0abad6;
case 0x0c0abad8u: goto P_0c0abad8;
case 0x0c0abadau: goto P_0c0abada;
case 0x0c0abadcu: goto P_0c0abadc;
case 0x0c0abadeu: goto P_0c0abade;
case 0x0c0abae0u: goto P_0c0abae0;
case 0x0c0abae2u: goto P_0c0abae2;
case 0x0c0abae4u: goto P_0c0abae4;
case 0x0c0abae6u: goto P_0c0abae6;
case 0x0c0abae8u: goto P_0c0abae8;
case 0x0c0abaeau: goto P_0c0abaea;
case 0x0c0abaecu: goto P_0c0abaec;
case 0x0c0abaeeu: goto P_0c0abaee;
case 0x0c0abaf0u: goto P_0c0abaf0;
case 0x0c0abaf2u: goto P_0c0abaf2;
case 0x0c0abaf4u: goto P_0c0abaf4;
case 0x0c0abaf6u: goto P_0c0abaf6;
case 0x0c0abaf8u: goto P_0c0abaf8;
case 0x0c0abafau: goto P_0c0abafa;
case 0x0c0abafcu: goto P_0c0abafc;
case 0x0c0abafeu: goto P_0c0abafe;
case 0x0c0abb00u: goto P_0c0abb00;
case 0x0c0abb02u: goto P_0c0abb02;
case 0x0c0abb04u: goto P_0c0abb04;
case 0x0c0abb06u: goto P_0c0abb06;
case 0x0c0abb08u: goto P_0c0abb08;
case 0x0c0abb0au: goto P_0c0abb0a;
case 0x0c0abb0cu: goto P_0c0abb0c;
case 0x0c0abb0eu: goto P_0c0abb0e;
case 0x0c0abb10u: goto P_0c0abb10;
case 0x0c0abb12u: goto P_0c0abb12;
case 0x0c0abb14u: goto P_0c0abb14;
case 0x0c0abb16u: goto P_0c0abb16;
case 0x0c0abb18u: goto P_0c0abb18;
case 0x0c0abb1au: goto P_0c0abb1a;
case 0x0c0abb1cu: goto P_0c0abb1c;
case 0x0c0abb1eu: goto P_0c0abb1e;
case 0x0c0abb20u: goto P_0c0abb20;
case 0x0c0abb22u: goto P_0c0abb22;
case 0x0c0abb24u: goto P_0c0abb24;
case 0x0c0abb26u: goto P_0c0abb26;
case 0x0c0abb28u: goto P_0c0abb28;
case 0x0c0abb2au: goto P_0c0abb2a;
case 0x0c0abb2cu: goto P_0c0abb2c;
case 0x0c0abb2eu: goto P_0c0abb2e;
case 0x0c0abb30u: goto P_0c0abb30;
case 0x0c0abb32u: goto P_0c0abb32;
case 0x0c0abb34u: goto P_0c0abb34;
case 0x0c0abb36u: goto P_0c0abb36;
case 0x0c0abb38u: goto P_0c0abb38;
case 0x0c0abb3au: goto P_0c0abb3a;
case 0x0c0abb3cu: goto P_0c0abb3c;
case 0x0c0abb3eu: goto P_0c0abb3e;
case 0x0c0abb40u: goto P_0c0abb40;
case 0x0c0abb42u: goto P_0c0abb42;
case 0x0c0abb44u: goto P_0c0abb44;
case 0x0c0abb46u: goto P_0c0abb46;
case 0x0c0abb48u: goto P_0c0abb48;
case 0x0c0abb4au: goto P_0c0abb4a;
case 0x0c0abb4cu: goto P_0c0abb4c;
case 0x0c0abb4eu: goto P_0c0abb4e;
case 0x0c0abb50u: goto P_0c0abb50;
case 0x0c0abb52u: goto P_0c0abb52;
case 0x0c0abb54u: goto P_0c0abb54;
case 0x0c0abb56u: goto P_0c0abb56;
case 0x0c0abb58u: goto P_0c0abb58;
case 0x0c0abb5au: goto P_0c0abb5a;
case 0x0c0abb5cu: goto P_0c0abb5c;
case 0x0c0abb5eu: goto P_0c0abb5e;
case 0x0c0abb60u: goto P_0c0abb60;
case 0x0c0abb62u: goto P_0c0abb62;
case 0x0c0abb64u: goto P_0c0abb64;
case 0x0c0abb66u: goto P_0c0abb66;
case 0x0c0abb68u: goto P_0c0abb68;
case 0x0c0abb6au: goto P_0c0abb6a;
case 0x0c0abb6cu: goto P_0c0abb6c;
case 0x0c0abb6eu: goto P_0c0abb6e;
case 0x0c0abb70u: goto P_0c0abb70;
case 0x0c0abb72u: goto P_0c0abb72;
case 0x0c0abb74u: goto P_0c0abb74;
case 0x0c0abb76u: goto P_0c0abb76;
case 0x0c0abb78u: goto P_0c0abb78;
case 0x0c0abb7au: goto P_0c0abb7a;
case 0x0c0abb7cu: goto P_0c0abb7c;
case 0x0c0abb7eu: goto P_0c0abb7e;
case 0x0c0abb80u: goto P_0c0abb80;
case 0x0c0abb82u: goto P_0c0abb82;
case 0x0c0abb84u: goto P_0c0abb84;
case 0x0c0abb86u: goto P_0c0abb86;
case 0x0c0abb88u: goto P_0c0abb88;
case 0x0c0abb8au: goto P_0c0abb8a;
case 0x0c0abb8cu: goto P_0c0abb8c;
case 0x0c0abb8eu: goto P_0c0abb8e;
case 0x0c0abb90u: goto P_0c0abb90;
case 0x0c0abb92u: goto P_0c0abb92;
case 0x0c0abb94u: goto P_0c0abb94;
case 0x0c0abb96u: goto P_0c0abb96;
case 0x0c0abb98u: goto P_0c0abb98;
case 0x0c0abb9au: goto P_0c0abb9a;
case 0x0c0abb9cu: goto P_0c0abb9c;
case 0x0c0abb9eu: goto P_0c0abb9e;
case 0x0c0abba0u: goto P_0c0abba0;
case 0x0c0abba2u: goto P_0c0abba2;
case 0x0c0abba4u: goto P_0c0abba4;
case 0x0c0abba6u: goto P_0c0abba6;
case 0x0c0abba8u: goto P_0c0abba8;
case 0x0c0abbaau: goto P_0c0abbaa;
case 0x0c0abbacu: goto P_0c0abbac;
case 0x0c0abbaeu: goto P_0c0abbae;
case 0x0c0abbb0u: goto P_0c0abbb0;
case 0x0c0abbb2u: goto P_0c0abbb2;
case 0x0c0abbb4u: goto P_0c0abbb4;
case 0x0c0abbb6u: goto P_0c0abbb6;
case 0x0c0abbb8u: goto P_0c0abbb8;
case 0x0c0abbbau: goto P_0c0abbba;
case 0x0c0abbbcu: goto P_0c0abbbc;
case 0x0c0abbbeu: goto P_0c0abbbe;
case 0x0c0abbc0u: goto P_0c0abbc0;
case 0x0c0abbc2u: goto P_0c0abbc2;
case 0x0c0abbc4u: goto P_0c0abbc4;
case 0x0c0abbc6u: goto P_0c0abbc6;
case 0x0c0abbc8u: goto P_0c0abbc8;
case 0x0c0abbcau: goto P_0c0abbca;
case 0x0c0abbccu: goto P_0c0abbcc;
case 0x0c0abbceu: goto P_0c0abbce;
case 0x0c0abbd0u: goto P_0c0abbd0;
case 0x0c0abbd2u: goto P_0c0abbd2;
case 0x0c0abbd4u: goto P_0c0abbd4;
case 0x0c0abbd6u: goto P_0c0abbd6;
case 0x0c0abbd8u: goto P_0c0abbd8;
case 0x0c0abbdau: goto P_0c0abbda;
case 0x0c0abbdcu: goto P_0c0abbdc;
case 0x0c0abbdeu: goto P_0c0abbde;
case 0x0c0abbfcu: goto P_0c0abbfc;
case 0x0c0abbfeu: goto P_0c0abbfe;
case 0x0c0abc00u: goto P_0c0abc00;
case 0x0c0abc02u: goto P_0c0abc02;
case 0x0c0abc04u: goto P_0c0abc04;
case 0x0c0abc06u: goto P_0c0abc06;
case 0x0c0abc08u: goto P_0c0abc08;
case 0x0c0abc0au: goto P_0c0abc0a;
case 0x0c0abc0cu: goto P_0c0abc0c;
case 0x0c0abc0eu: goto P_0c0abc0e;
case 0x0c0abc10u: goto P_0c0abc10;
case 0x0c0abc12u: goto P_0c0abc12;
case 0x0c0abc14u: goto P_0c0abc14;
case 0x0c0abc16u: goto P_0c0abc16;
case 0x0c0abc18u: goto P_0c0abc18;
case 0x0c0abc1au: goto P_0c0abc1a;
case 0x0c0abc1cu: goto P_0c0abc1c;
case 0x0c0abc1eu: goto P_0c0abc1e;
case 0x0c0abc20u: goto P_0c0abc20;
case 0x0c0abc22u: goto P_0c0abc22;
case 0x0c0abc24u: goto P_0c0abc24;
case 0x0c0abc26u: goto P_0c0abc26;
case 0x0c0abc28u: goto P_0c0abc28;
case 0x0c0abc2au: goto P_0c0abc2a;
case 0x0c0abc2cu: goto P_0c0abc2c;
case 0x0c0abc2eu: goto P_0c0abc2e;
case 0x0c0abc30u: goto P_0c0abc30;
case 0x0c0abc32u: goto P_0c0abc32;
case 0x0c0abc34u: goto P_0c0abc34;
case 0x0c0abc36u: goto P_0c0abc36;
case 0x0c0abc38u: goto P_0c0abc38;
case 0x0c0abc3au: goto P_0c0abc3a;
case 0x0c0abc3cu: goto P_0c0abc3c;
case 0x0c0abc3eu: goto P_0c0abc3e;
case 0x0c0abc40u: goto P_0c0abc40;
case 0x0c0abc42u: goto P_0c0abc42;
case 0x0c0abc44u: goto P_0c0abc44;
case 0x0c0abc46u: goto P_0c0abc46;
case 0x0c0abc48u: goto P_0c0abc48;
case 0x0c0abc4au: goto P_0c0abc4a;
case 0x0c0abc4cu: goto P_0c0abc4c;
case 0x0c0abc4eu: goto P_0c0abc4e;
case 0x0c0abc50u: goto P_0c0abc50;
case 0x0c0abc52u: goto P_0c0abc52;
case 0x0c0abc54u: goto P_0c0abc54;
case 0x0c0abc56u: goto P_0c0abc56;
case 0x0c0abc58u: goto P_0c0abc58;
case 0x0c0abc5au: goto P_0c0abc5a;
case 0x0c0abc5cu: goto P_0c0abc5c;
case 0x0c0abc5eu: goto P_0c0abc5e;
case 0x0c0abc60u: goto P_0c0abc60;
case 0x0c0abc62u: goto P_0c0abc62;
case 0x0c0abc64u: goto P_0c0abc64;
case 0x0c0abc66u: goto P_0c0abc66;
case 0x0c0abc68u: goto P_0c0abc68;
case 0x0c0abc6au: goto P_0c0abc6a;
case 0x0c0abc6cu: goto P_0c0abc6c;
case 0x0c0abc6eu: goto P_0c0abc6e;
case 0x0c0abc70u: goto P_0c0abc70;
case 0x0c0abc72u: goto P_0c0abc72;
case 0x0c0abc74u: goto P_0c0abc74;
case 0x0c0abc76u: goto P_0c0abc76;
case 0x0c0abc78u: goto P_0c0abc78;
case 0x0c0abc7au: goto P_0c0abc7a;
case 0x0c0abc7cu: goto P_0c0abc7c;
case 0x0c0abc7eu: goto P_0c0abc7e;
case 0x0c0abc80u: goto P_0c0abc80;
case 0x0c0abc82u: goto P_0c0abc82;
case 0x0c0abc84u: goto P_0c0abc84;
case 0x0c0abc86u: goto P_0c0abc86;
case 0x0c0abc88u: goto P_0c0abc88;
case 0x0c0abc8au: goto P_0c0abc8a;
case 0x0c0abc8cu: goto P_0c0abc8c;
case 0x0c0abc8eu: goto P_0c0abc8e;
case 0x0c0abc90u: goto P_0c0abc90;
case 0x0c0abc92u: goto P_0c0abc92;
case 0x0c0abc94u: goto P_0c0abc94;
case 0x0c0abc96u: goto P_0c0abc96;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0abad0: /* original 2fe6, guest PC 0x0c0abad0 */
if(!s->budget--) { s->failed_pc=0x0c0abad0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abad2;
P_0c0abad2: /* original 6e43, guest PC 0x0c0abad2 */
if(!s->budget--) { s->failed_pc=0x0c0abad2u; return 0; }
r[14]=r[4];
goto P_0c0abad4;
P_0c0abad4: /* original 2fd6, guest PC 0x0c0abad4 */
if(!s->budget--) { s->failed_pc=0x0c0abad4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abad6;
P_0c0abad6: /* original 6d53, guest PC 0x0c0abad6 */
if(!s->budget--) { s->failed_pc=0x0c0abad6u; return 0; }
r[13]=r[5];
goto P_0c0abad8;
P_0c0abad8: /* original 4f22, guest PC 0x0c0abad8 */
if(!s->budget--) { s->failed_pc=0x0c0abad8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abada;
P_0c0abada: /* original d344, guest PC 0x0c0abada */
if(!s->budget--) { s->failed_pc=0x0c0abadau; return 0; }
r[3]=read(ram,0x0c0abbecu,4);
goto P_0c0abadc;
P_0c0abadc: /* original 7ff8, guest PC 0x0c0abadc */
if(!s->budget--) { s->failed_pc=0x0c0abadcu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0abade;
P_0c0abade: /* original 2f32, guest PC 0x0c0abade */
if(!s->budget--) { s->failed_pc=0x0c0abadeu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0abae0;
P_0c0abae0: /* original b104, guest PC 0x0c0abae0 */
if(!s->budget--) { s->failed_pc=0x0c0abae0u; return 0; }
target=code_base|0x0c0abcecu; r[16]=code_base|0x0c0abae4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0abae4u) { target=s->pc; goto dispatch; }
goto P_0c0abae4;
P_0c0abae2: /* original 64e3, guest PC 0x0c0abae2 */
if(!s->budget--) { s->failed_pc=0x0c0abae2u; return 0; }
r[4]=r[14];
goto P_0c0abae4;
P_0c0abae4: /* original b122, guest PC 0x0c0abae4 */
if(!s->budget--) { s->failed_pc=0x0c0abae4u; return 0; }
target=code_base|0x0c0abd2cu; r[16]=code_base|0x0c0abae8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0abae8u) { target=s->pc; goto dispatch; }
goto P_0c0abae8;
P_0c0abae6: /* original 64e3, guest PC 0x0c0abae6 */
if(!s->budget--) { s->failed_pc=0x0c0abae6u; return 0; }
r[4]=r[14];
goto P_0c0abae8;
P_0c0abae8: /* original 1f01, guest PC 0x0c0abae8 */
if(!s->budget--) { s->failed_pc=0x0c0abae8u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0abaea;
P_0c0abaea: /* original b16b, guest PC 0x0c0abaea */
if(!s->budget--) { s->failed_pc=0x0c0abaeau; return 0; }
target=code_base|0x0c0abdc4u; r[16]=code_base|0x0c0abaeeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0abaeeu) { target=s->pc; goto dispatch; }
goto P_0c0abaee;
P_0c0abaec: /* original 64e3, guest PC 0x0c0abaec */
if(!s->budget--) { s->failed_pc=0x0c0abaecu; return 0; }
r[4]=r[14];
goto P_0c0abaee;
P_0c0abaee: /* original 50f1, guest PC 0x0c0abaee */
if(!s->budget--) { s->failed_pc=0x0c0abaeeu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0abaf0;
P_0c0abaf0: /* original 8801, guest PC 0x0c0abaf0 */
if(!s->budget--) { s->failed_pc=0x0c0abaf0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0abaf2;
P_0c0abaf2: /* original 8b06, guest PC 0x0c0abaf2 */
if(!s->budget--) { s->failed_pc=0x0c0abaf2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abb02; }
goto P_0c0abaf4;
P_0c0abaf4: /* original 60f2, guest PC 0x0c0abaf4 */
if(!s->budget--) { s->failed_pc=0x0c0abaf4u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0abaf6;
P_0c0abaf6: /* original e11c, guest PC 0x0c0abaf6 */
if(!s->budget--) { s->failed_pc=0x0c0abaf6u; return 0; }
r[1]=0x0000001cu;
goto P_0c0abaf8;
P_0c0abaf8: /* original 001c, guest PC 0x0c0abaf8 */
if(!s->budget--) { s->failed_pc=0x0c0abaf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0abafa;
P_0c0abafa: /* original 600c, guest PC 0x0c0abafa */
if(!s->budget--) { s->failed_pc=0x0c0abafau; return 0; }
r[0]=r[0]&255u;
goto P_0c0abafc;
P_0c0abafc: /* original c90f, guest PC 0x0c0abafc */
if(!s->budget--) { s->failed_pc=0x0c0abafcu; return 0; }
r[0]&=15u;
goto P_0c0abafe;
P_0c0abafe: /* original 8806, guest PC 0x0c0abafe */
if(!s->budget--) { s->failed_pc=0x0c0abafeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0abb00;
P_0c0abb00: /* original 8b0b, guest PC 0x0c0abb00 */
if(!s->budget--) { s->failed_pc=0x0c0abb00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abb1a; }
goto P_0c0abb02;
P_0c0abb02: /* original 7f08, guest PC 0x0c0abb02 */
if(!s->budget--) { s->failed_pc=0x0c0abb02u; return 0; }
r[15]+=0x00000008u;
goto P_0c0abb04;
P_0c0abb04: /* original 65d3, guest PC 0x0c0abb04 */
if(!s->budget--) { s->failed_pc=0x0c0abb04u; return 0; }
r[5]=r[13];
goto P_0c0abb06;
P_0c0abb06: /* original 4f26, guest PC 0x0c0abb06 */
if(!s->budget--) { s->failed_pc=0x0c0abb06u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abb08;
P_0c0abb08: /* original e203, guest PC 0x0c0abb08 */
if(!s->budget--) { s->failed_pc=0x0c0abb08u; return 0; }
r[2]=0x00000003u;
goto P_0c0abb0a;
P_0c0abb0a: /* original 64e3, guest PC 0x0c0abb0a */
if(!s->budget--) { s->failed_pc=0x0c0abb0au; return 0; }
r[4]=r[14];
goto P_0c0abb0c;
P_0c0abb0c: /* original 1d22, guest PC 0x0c0abb0c */
if(!s->budget--) { s->failed_pc=0x0c0abb0cu; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c0abb0e;
P_0c0abb0e: /* original 6323, guest PC 0x0c0abb0e */
if(!s->budget--) { s->failed_pc=0x0c0abb0eu; return 0; }
r[3]=r[2];
goto P_0c0abb10;
P_0c0abb10: /* original e062, guest PC 0x0c0abb10 */
if(!s->budget--) { s->failed_pc=0x0c0abb10u; return 0; }
r[0]=0x00000062u;
goto P_0c0abb12;
P_0c0abb12: /* original 0e34, guest PC 0x0c0abb12 */
if(!s->budget--) { s->failed_pc=0x0c0abb12u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0abb14;
P_0c0abb14: /* original 6df6, guest PC 0x0c0abb14 */
if(!s->budget--) { s->failed_pc=0x0c0abb14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abb16;
P_0c0abb16: /* original a005, guest PC 0x0c0abb16 */
if(!s->budget--) { s->failed_pc=0x0c0abb16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abb24;
P_0c0abb18: /* original 6ef6, guest PC 0x0c0abb18 */
if(!s->budget--) { s->failed_pc=0x0c0abb18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abb1a;
P_0c0abb1a: /* original 7f08, guest PC 0x0c0abb1a */
if(!s->budget--) { s->failed_pc=0x0c0abb1au; return 0; }
r[15]+=0x00000008u;
goto P_0c0abb1c;
P_0c0abb1c: /* original 4f26, guest PC 0x0c0abb1c */
if(!s->budget--) { s->failed_pc=0x0c0abb1cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abb1e;
P_0c0abb1e: /* original 6df6, guest PC 0x0c0abb1e */
if(!s->budget--) { s->failed_pc=0x0c0abb1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abb20;
P_0c0abb20: /* original 000b, guest PC 0x0c0abb20 */
if(!s->budget--) { s->failed_pc=0x0c0abb20u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0abb22: /* original 6ef6, guest PC 0x0c0abb22 */
if(!s->budget--) { s->failed_pc=0x0c0abb22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abb24;
P_0c0abb24: /* original 2fe6, guest PC 0x0c0abb24 */
if(!s->budget--) { s->failed_pc=0x0c0abb24u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abb26;
P_0c0abb26: /* original 6e43, guest PC 0x0c0abb26 */
if(!s->budget--) { s->failed_pc=0x0c0abb26u; return 0; }
r[14]=r[4];
goto P_0c0abb28;
P_0c0abb28: /* original 2fd6, guest PC 0x0c0abb28 */
if(!s->budget--) { s->failed_pc=0x0c0abb28u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abb2a;
P_0c0abb2a: /* original 4f22, guest PC 0x0c0abb2a */
if(!s->budget--) { s->failed_pc=0x0c0abb2au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abb2c;
P_0c0abb2c: /* original b0de, guest PC 0x0c0abb2c */
if(!s->budget--) { s->failed_pc=0x0c0abb2cu; return 0; }
target=code_base|0x0c0abcecu; r[16]=code_base|0x0c0abb30u;
r[13]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0abb30u) { target=s->pc; goto dispatch; }
goto P_0c0abb30;
P_0c0abb2e: /* original 6d53, guest PC 0x0c0abb2e */
if(!s->budget--) { s->failed_pc=0x0c0abb2eu; return 0; }
r[13]=r[5];
goto P_0c0abb30;
P_0c0abb30: /* original e03e, guest PC 0x0c0abb30 */
if(!s->budget--) { s->failed_pc=0x0c0abb30u; return 0; }
r[0]=0x0000003eu;
goto P_0c0abb32;
P_0c0abb32: /* original 04ed, guest PC 0x0c0abb32 */
if(!s->budget--) { s->failed_pc=0x0c0abb32u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abb34;
P_0c0abb34: /* original 9054, guest PC 0x0c0abb34 */
if(!s->budget--) { s->failed_pc=0x0c0abb34u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abbe0u,2);
goto P_0c0abb36;
P_0c0abb36: /* original 644d, guest PC 0x0c0abb36 */
if(!s->budget--) { s->failed_pc=0x0c0abb36u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0abb38;
P_0c0abb38: /* original 05ed, guest PC 0x0c0abb38 */
if(!s->budget--) { s->failed_pc=0x0c0abb38u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abb3a;
P_0c0abb3a: /* original 9052, guest PC 0x0c0abb3a */
if(!s->budget--) { s->failed_pc=0x0c0abb3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abbe2u,2);
goto P_0c0abb3c;
P_0c0abb3c: /* original 3450, guest PC 0x0c0abb3c */
if(!s->budget--) { s->failed_pc=0x0c0abb3cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c0abb3e;
P_0c0abb3e: /* original 06ed, guest PC 0x0c0abb3e */
if(!s->budget--) { s->failed_pc=0x0c0abb3eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abb40;
P_0c0abb40: /* original 8f03, guest PC 0x0c0abb40 */
if(!s->budget--) { s->failed_pc=0x0c0abb40u; return 0; }
cond=r[17]&1u;
r[6]=r[6]&65535u;
if(!cond) { goto P_0c0abb4a; }
goto P_0c0abb44;
P_0c0abb42: /* original 666d, guest PC 0x0c0abb42 */
if(!s->budget--) { s->failed_pc=0x0c0abb42u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0abb44;
P_0c0abb44: /* original e03e, guest PC 0x0c0abb44 */
if(!s->budget--) { s->failed_pc=0x0c0abb44u; return 0; }
r[0]=0x0000003eu;
goto P_0c0abb46;
P_0c0abb46: /* original 7401, guest PC 0x0c0abb46 */
if(!s->budget--) { s->failed_pc=0x0c0abb46u; return 0; }
r[4]+=0x00000001u;
goto P_0c0abb48;
P_0c0abb48: /* original 0e45, guest PC 0x0c0abb48 */
if(!s->budget--) { s->failed_pc=0x0c0abb48u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0abb4a;
P_0c0abb4a: /* original 3462, guest PC 0x0c0abb4a */
if(!s->budget--) { s->failed_pc=0x0c0abb4au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[6])!=0);
goto P_0c0abb4c;
P_0c0abb4c: /* original 8b15, guest PC 0x0c0abb4c */
if(!s->budget--) { s->failed_pc=0x0c0abb4cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abb7a; }
goto P_0c0abb4e;
P_0c0abb4e: /* original e204, guest PC 0x0c0abb4e */
if(!s->budget--) { s->failed_pc=0x0c0abb4eu; return 0; }
r[2]=0x00000004u;
goto P_0c0abb50;
P_0c0abb50: /* original 65d3, guest PC 0x0c0abb50 */
if(!s->budget--) { s->failed_pc=0x0c0abb50u; return 0; }
r[5]=r[13];
goto P_0c0abb52;
P_0c0abb52: /* original 6323, guest PC 0x0c0abb52 */
if(!s->budget--) { s->failed_pc=0x0c0abb52u; return 0; }
r[3]=r[2];
goto P_0c0abb54;
P_0c0abb54: /* original e062, guest PC 0x0c0abb54 */
if(!s->budget--) { s->failed_pc=0x0c0abb54u; return 0; }
r[0]=0x00000062u;
goto P_0c0abb56;
P_0c0abb56: /* original 1d22, guest PC 0x0c0abb56 */
if(!s->budget--) { s->failed_pc=0x0c0abb56u; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c0abb58;
P_0c0abb58: /* original 64e3, guest PC 0x0c0abb58 */
if(!s->budget--) { s->failed_pc=0x0c0abb58u; return 0; }
r[4]=r[14];
goto P_0c0abb5a;
P_0c0abb5a: /* original 0e34, guest PC 0x0c0abb5a */
if(!s->budget--) { s->failed_pc=0x0c0abb5au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0abb5c;
P_0c0abb5c: /* original e048, guest PC 0x0c0abb5c */
if(!s->budget--) { s->failed_pc=0x0c0abb5cu; return 0; }
r[0]=0x00000048u;
goto P_0c0abb5e;
P_0c0abb5e: /* original 62d2, guest PC 0x0c0abb5e */
if(!s->budget--) { s->failed_pc=0x0c0abb5eu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0abb60;
P_0c0abb60: /* original d323, guest PC 0x0c0abb60 */
if(!s->budget--) { s->failed_pc=0x0c0abb60u; return 0; }
r[3]=read(ram,0x0c0abbf0u,4);
goto P_0c0abb62;
P_0c0abb62: /* original 4f26, guest PC 0x0c0abb62 */
if(!s->budget--) { s->failed_pc=0x0c0abb62u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abb64;
P_0c0abb64: /* original 223b, guest PC 0x0c0abb64 */
if(!s->budget--) { s->failed_pc=0x0c0abb64u; return 0; }
r[2]|=r[3];
goto P_0c0abb66;
P_0c0abb66: /* original 2d22, guest PC 0x0c0abb66 */
if(!s->budget--) { s->failed_pc=0x0c0abb66u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0abb68;
P_0c0abb68: /* original 01ee, guest PC 0x0c0abb68 */
if(!s->budget--) { s->failed_pc=0x0c0abb68u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0abb6a;
P_0c0abb6a: /* original d222, guest PC 0x0c0abb6a */
if(!s->budget--) { s->failed_pc=0x0c0abb6au; return 0; }
r[2]=read(ram,0x0c0abbf4u,4);
goto P_0c0abb6c;
P_0c0abb6c: /* original 212b, guest PC 0x0c0abb6c */
if(!s->budget--) { s->failed_pc=0x0c0abb6cu; return 0; }
r[1]|=r[2];
goto P_0c0abb6e;
P_0c0abb6e: /* original 0e16, guest PC 0x0c0abb6e */
if(!s->budget--) { s->failed_pc=0x0c0abb6eu; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c0abb70;
P_0c0abb70: /* original 60d2, guest PC 0x0c0abb70 */
if(!s->budget--) { s->failed_pc=0x0c0abb70u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0abb72;
P_0c0abb72: /* original 2e02, guest PC 0x0c0abb72 */
if(!s->budget--) { s->failed_pc=0x0c0abb72u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c0abb74;
P_0c0abb74: /* original 6df6, guest PC 0x0c0abb74 */
if(!s->budget--) { s->failed_pc=0x0c0abb74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abb76;
P_0c0abb76: /* original a004, guest PC 0x0c0abb76 */
if(!s->budget--) { s->failed_pc=0x0c0abb76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abb82;
P_0c0abb78: /* original 6ef6, guest PC 0x0c0abb78 */
if(!s->budget--) { s->failed_pc=0x0c0abb78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abb7a;
P_0c0abb7a: /* original 4f26, guest PC 0x0c0abb7a */
if(!s->budget--) { s->failed_pc=0x0c0abb7au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abb7c;
P_0c0abb7c: /* original 6df6, guest PC 0x0c0abb7c */
if(!s->budget--) { s->failed_pc=0x0c0abb7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abb7e;
P_0c0abb7e: /* original 000b, guest PC 0x0c0abb7e */
if(!s->budget--) { s->failed_pc=0x0c0abb7eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0abb80: /* original 6ef6, guest PC 0x0c0abb80 */
if(!s->budget--) { s->failed_pc=0x0c0abb80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abb82;
P_0c0abb82: /* original 2fe6, guest PC 0x0c0abb82 */
if(!s->budget--) { s->failed_pc=0x0c0abb82u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abb84;
P_0c0abb84: /* original e048, guest PC 0x0c0abb84 */
if(!s->budget--) { s->failed_pc=0x0c0abb84u; return 0; }
r[0]=0x00000048u;
goto P_0c0abb86;
P_0c0abb86: /* original 6e43, guest PC 0x0c0abb86 */
if(!s->budget--) { s->failed_pc=0x0c0abb86u; return 0; }
r[14]=r[4];
goto P_0c0abb88;
P_0c0abb88: /* original 02ee, guest PC 0x0c0abb88 */
if(!s->budget--) { s->failed_pc=0x0c0abb88u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0abb8a;
P_0c0abb8a: /* original d31b, guest PC 0x0c0abb8a */
if(!s->budget--) { s->failed_pc=0x0c0abb8au; return 0; }
r[3]=read(ram,0x0c0abbf8u,4);
goto P_0c0abb8c;
P_0c0abb8c: /* original 4f22, guest PC 0x0c0abb8c */
if(!s->budget--) { s->failed_pc=0x0c0abb8cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abb8e;
P_0c0abb8e: /* original 2239, guest PC 0x0c0abb8e */
if(!s->budget--) { s->failed_pc=0x0c0abb8eu; return 0; }
r[2]&=r[3];
goto P_0c0abb90;
P_0c0abb90: /* original 0e26, guest PC 0x0c0abb90 */
if(!s->budget--) { s->failed_pc=0x0c0abb90u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0abb92;
P_0c0abb92: /* original b0ab, guest PC 0x0c0abb92 */
if(!s->budget--) { s->failed_pc=0x0c0abb92u; return 0; }
target=code_base|0x0c0abcecu; r[16]=code_base|0x0c0abb96u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0abb96u) { target=s->pc; goto dispatch; }
goto P_0c0abb96;
P_0c0abb94: /* original 64e3, guest PC 0x0c0abb94 */
if(!s->budget--) { s->failed_pc=0x0c0abb94u; return 0; }
r[4]=r[14];
goto P_0c0abb96;
P_0c0abb96: /* original e024, guest PC 0x0c0abb96 */
if(!s->budget--) { s->failed_pc=0x0c0abb96u; return 0; }
r[0]=0x00000024u;
goto P_0c0abb98;
P_0c0abb98: /* original f48d, guest PC 0x0c0abb98 */
if(!s->budget--) { s->failed_pc=0x0c0abb98u; return 0; }
fr[4]=0;
goto P_0c0abb9a;
P_0c0abb9a: /* original fe47, guest PC 0x0c0abb9a */
if(!s->budget--) { s->failed_pc=0x0c0abb9au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0abb9c;
P_0c0abb9c: /* original e02c, guest PC 0x0c0abb9c */
if(!s->budget--) { s->failed_pc=0x0c0abb9cu; return 0; }
r[0]=0x0000002cu;
goto P_0c0abb9e;
P_0c0abb9e: /* original fe47, guest PC 0x0c0abb9e */
if(!s->budget--) { s->failed_pc=0x0c0abb9eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0abba0;
P_0c0abba0: /* original 9020, guest PC 0x0c0abba0 */
if(!s->budget--) { s->failed_pc=0x0c0abba0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abbe4u,2);
goto P_0c0abba2;
P_0c0abba2: /* original 4f26, guest PC 0x0c0abba2 */
if(!s->budget--) { s->failed_pc=0x0c0abba2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abba4;
P_0c0abba4: /* original fe47, guest PC 0x0c0abba4 */
if(!s->budget--) { s->failed_pc=0x0c0abba4u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0abba6;
P_0c0abba6: /* original 7004, guest PC 0x0c0abba6 */
if(!s->budget--) { s->failed_pc=0x0c0abba6u; return 0; }
r[0]+=0x00000004u;
goto P_0c0abba8;
P_0c0abba8: /* original fe47, guest PC 0x0c0abba8 */
if(!s->budget--) { s->failed_pc=0x0c0abba8u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0abbaa;
P_0c0abbaa: /* original 7004, guest PC 0x0c0abbaa */
if(!s->budget--) { s->failed_pc=0x0c0abbaau; return 0; }
r[0]+=0x00000004u;
goto P_0c0abbac;
P_0c0abbac: /* original fe47, guest PC 0x0c0abbac */
if(!s->budget--) { s->failed_pc=0x0c0abbacu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0abbae;
P_0c0abbae: /* original 9018, guest PC 0x0c0abbae */
if(!s->budget--) { s->failed_pc=0x0c0abbaeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abbe2u,2);
goto P_0c0abbb0;
P_0c0abbb0: /* original 03ed, guest PC 0x0c0abbb0 */
if(!s->budget--) { s->failed_pc=0x0c0abbb0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abbb2;
P_0c0abbb2: /* original e03e, guest PC 0x0c0abbb2 */
if(!s->budget--) { s->failed_pc=0x0c0abbb2u; return 0; }
r[0]=0x0000003eu;
goto P_0c0abbb4;
P_0c0abbb4: /* original 0e35, guest PC 0x0c0abbb4 */
if(!s->budget--) { s->failed_pc=0x0c0abbb4u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0abbb6;
P_0c0abbb6: /* original 000b, guest PC 0x0c0abbb6 */
if(!s->budget--) { s->failed_pc=0x0c0abbb6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0abbb8: /* original 6ef6, guest PC 0x0c0abbb8 */
if(!s->budget--) { s->failed_pc=0x0c0abbb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abbba;
P_0c0abbba: /* original e205, guest PC 0x0c0abbba */
if(!s->budget--) { s->failed_pc=0x0c0abbbau; return 0; }
r[2]=0x00000005u;
goto P_0c0abbbc;
P_0c0abbbc: /* original e062, guest PC 0x0c0abbbc */
if(!s->budget--) { s->failed_pc=0x0c0abbbcu; return 0; }
r[0]=0x00000062u;
goto P_0c0abbbe;
P_0c0abbbe: /* original 6323, guest PC 0x0c0abbbe */
if(!s->budget--) { s->failed_pc=0x0c0abbbeu; return 0; }
r[3]=r[2];
goto P_0c0abbc0;
P_0c0abbc0: /* original 1522, guest PC 0x0c0abbc0 */
if(!s->budget--) { s->failed_pc=0x0c0abbc0u; return 0; }
write(ram,r[5]+8,r[2],4);
goto P_0c0abbc2;
P_0c0abbc2: /* original 0434, guest PC 0x0c0abbc2 */
if(!s->budget--) { s->failed_pc=0x0c0abbc2u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c0abbc4;
P_0c0abbc4: /* original 900f, guest PC 0x0c0abbc4 */
if(!s->budget--) { s->failed_pc=0x0c0abbc4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abbe6u,2);
goto P_0c0abbc6;
P_0c0abbc6: /* original f346, guest PC 0x0c0abbc6 */
if(!s->budget--) { s->failed_pc=0x0c0abbc6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0abbc8;
P_0c0abbc8: /* original e024, guest PC 0x0c0abbc8 */
if(!s->budget--) { s->failed_pc=0x0c0abbc8u; return 0; }
r[0]=0x00000024u;
goto P_0c0abbca;
P_0c0abbca: /* original f437, guest PC 0x0c0abbca */
if(!s->budget--) { s->failed_pc=0x0c0abbcau; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0abbcc;
P_0c0abbcc: /* original 900c, guest PC 0x0c0abbcc */
if(!s->budget--) { s->failed_pc=0x0c0abbccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abbe8u,2);
goto P_0c0abbce;
P_0c0abbce: /* original f346, guest PC 0x0c0abbce */
if(!s->budget--) { s->failed_pc=0x0c0abbceu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0abbd0;
P_0c0abbd0: /* original e02c, guest PC 0x0c0abbd0 */
if(!s->budget--) { s->failed_pc=0x0c0abbd0u; return 0; }
r[0]=0x0000002cu;
goto P_0c0abbd2;
P_0c0abbd2: /* original f437, guest PC 0x0c0abbd2 */
if(!s->budget--) { s->failed_pc=0x0c0abbd2u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0abbd4;
P_0c0abbd4: /* original 9006, guest PC 0x0c0abbd4 */
if(!s->budget--) { s->failed_pc=0x0c0abbd4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abbe4u,2);
goto P_0c0abbd6;
P_0c0abbd6: /* original f48d, guest PC 0x0c0abbd6 */
if(!s->budget--) { s->failed_pc=0x0c0abbd6u; return 0; }
fr[4]=0;
goto P_0c0abbd8;
P_0c0abbd8: /* original f447, guest PC 0x0c0abbd8 */
if(!s->budget--) { s->failed_pc=0x0c0abbd8u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0abbda;
P_0c0abbda: /* original 7008, guest PC 0x0c0abbda */
if(!s->budget--) { s->failed_pc=0x0c0abbdau; return 0; }
r[0]+=0x00000008u;
goto P_0c0abbdc;
P_0c0abbdc: /* original a00e, guest PC 0x0c0abbdc */
if(!s->budget--) { s->failed_pc=0x0c0abbdcu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0abbfc;
P_0c0abbde: /* original f447, guest PC 0x0c0abbde */
if(!s->budget--) { s->failed_pc=0x0c0abbdeu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
if(!vf3_matrix_family(0x0c0abbe0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0abbe0u; return 0; } return 1;
P_0c0abbfc: /* original 2fe6, guest PC 0x0c0abbfc */
if(!s->budget--) { s->failed_pc=0x0c0abbfcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abbfe;
P_0c0abbfe: /* original 6643, guest PC 0x0c0abbfe */
if(!s->budget--) { s->failed_pc=0x0c0abbfeu; return 0; }
r[6]=r[4];
goto P_0c0abc00;
P_0c0abc00: /* original 2fd6, guest PC 0x0c0abc00 */
if(!s->budget--) { s->failed_pc=0x0c0abc00u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abc02;
P_0c0abc02: /* original 6e43, guest PC 0x0c0abc02 */
if(!s->budget--) { s->failed_pc=0x0c0abc02u; return 0; }
r[14]=r[4];
goto P_0c0abc04;
P_0c0abc04: /* original 2fc6, guest PC 0x0c0abc04 */
if(!s->budget--) { s->failed_pc=0x0c0abc04u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abc06;
P_0c0abc06: /* original 6d53, guest PC 0x0c0abc06 */
if(!s->budget--) { s->failed_pc=0x0c0abc06u; return 0; }
r[13]=r[5];
goto P_0c0abc08;
P_0c0abc08: /* original 4f22, guest PC 0x0c0abc08 */
if(!s->budget--) { s->failed_pc=0x0c0abc08u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abc0a;
P_0c0abc0a: /* original d344, guest PC 0x0c0abc0a */
if(!s->budget--) { s->failed_pc=0x0c0abc0au; return 0; }
r[3]=read(ram,0x0c0abd1cu,4);
goto P_0c0abc0c;
P_0c0abc0c: /* original 430b, guest PC 0x0c0abc0c */
if(!s->budget--) { s->failed_pc=0x0c0abc0cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0abc10u;
r[6]+=0x00000048u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0abc10u) { target=s->pc; goto dispatch; }
goto P_0c0abc10;
P_0c0abc0e: /* original 7648, guest PC 0x0c0abc0e */
if(!s->budget--) { s->failed_pc=0x0c0abc0eu; return 0; }
r[6]+=0x00000048u;
goto P_0c0abc10;
P_0c0abc10: /* original 62d2, guest PC 0x0c0abc10 */
if(!s->budget--) { s->failed_pc=0x0c0abc10u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0abc12;
P_0c0abc12: /* original 6323, guest PC 0x0c0abc12 */
if(!s->budget--) { s->failed_pc=0x0c0abc12u; return 0; }
r[3]=r[2];
goto P_0c0abc14;
P_0c0abc14: /* original 2e22, guest PC 0x0c0abc14 */
if(!s->budget--) { s->failed_pc=0x0c0abc14u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0abc16;
P_0c0abc16: /* original d442, guest PC 0x0c0abc16 */
if(!s->budget--) { s->failed_pc=0x0c0abc16u; return 0; }
r[4]=read(ram,0x0c0abd20u,4);
goto P_0c0abc18;
P_0c0abc18: /* original 2348, guest PC 0x0c0abc18 */
if(!s->budget--) { s->failed_pc=0x0c0abc18u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0abc1a;
P_0c0abc1a: /* original 8b07, guest PC 0x0c0abc1a */
if(!s->budget--) { s->failed_pc=0x0c0abc1au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abc2c; }
goto P_0c0abc1c;
P_0c0abc1c: /* original 9075, guest PC 0x0c0abc1c */
if(!s->budget--) { s->failed_pc=0x0c0abc1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abd0au,2);
goto P_0c0abc1e;
P_0c0abc1e: /* original f3e6, guest PC 0x0c0abc1e */
if(!s->budget--) { s->failed_pc=0x0c0abc1eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0abc20;
P_0c0abc20: /* original e024, guest PC 0x0c0abc20 */
if(!s->budget--) { s->failed_pc=0x0c0abc20u; return 0; }
r[0]=0x00000024u;
goto P_0c0abc22;
P_0c0abc22: /* original fe37, guest PC 0x0c0abc22 */
if(!s->budget--) { s->failed_pc=0x0c0abc22u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0abc24;
P_0c0abc24: /* original 9072, guest PC 0x0c0abc24 */
if(!s->budget--) { s->failed_pc=0x0c0abc24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abd0cu,2);
goto P_0c0abc26;
P_0c0abc26: /* original f3e6, guest PC 0x0c0abc26 */
if(!s->budget--) { s->failed_pc=0x0c0abc26u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0abc28;
P_0c0abc28: /* original e02c, guest PC 0x0c0abc28 */
if(!s->budget--) { s->failed_pc=0x0c0abc28u; return 0; }
r[0]=0x0000002cu;
goto P_0c0abc2a;
P_0c0abc2a: /* original fe37, guest PC 0x0c0abc2a */
if(!s->budget--) { s->failed_pc=0x0c0abc2au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0abc2c;
P_0c0abc2c: /* original 63d2, guest PC 0x0c0abc2c */
if(!s->budget--) { s->failed_pc=0x0c0abc2cu; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0abc2e;
P_0c0abc2e: /* original 2438, guest PC 0x0c0abc2e */
if(!s->budget--) { s->failed_pc=0x0c0abc2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0abc30;
P_0c0abc30: /* original 892d, guest PC 0x0c0abc30 */
if(!s->budget--) { s->failed_pc=0x0c0abc30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abc8e; }
goto P_0c0abc32;
P_0c0abc32: /* original e03e, guest PC 0x0c0abc32 */
if(!s->budget--) { s->failed_pc=0x0c0abc32u; return 0; }
r[0]=0x0000003eu;
goto P_0c0abc34;
P_0c0abc34: /* original 01ed, guest PC 0x0c0abc34 */
if(!s->budget--) { s->failed_pc=0x0c0abc34u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abc36;
P_0c0abc36: /* original 906a, guest PC 0x0c0abc36 */
if(!s->budget--) { s->failed_pc=0x0c0abc36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abd0eu,2);
goto P_0c0abc38;
P_0c0abc38: /* original 03ed, guest PC 0x0c0abc38 */
if(!s->budget--) { s->failed_pc=0x0c0abc38u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abc3a;
P_0c0abc3a: /* original 3136, guest PC 0x0c0abc3a */
if(!s->budget--) { s->failed_pc=0x0c0abc3au; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[3])!=0);
goto P_0c0abc3c;
P_0c0abc3c: /* original 8906, guest PC 0x0c0abc3c */
if(!s->budget--) { s->failed_pc=0x0c0abc3cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abc4c; }
goto P_0c0abc3e;
P_0c0abc3e: /* original e03e, guest PC 0x0c0abc3e */
if(!s->budget--) { s->failed_pc=0x0c0abc3eu; return 0; }
r[0]=0x0000003eu;
goto P_0c0abc40;
P_0c0abc40: /* original 03ed, guest PC 0x0c0abc40 */
if(!s->budget--) { s->failed_pc=0x0c0abc40u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abc42;
P_0c0abc42: /* original 9065, guest PC 0x0c0abc42 */
if(!s->budget--) { s->failed_pc=0x0c0abc42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abd10u,2);
goto P_0c0abc44;
P_0c0abc44: /* original 633d, guest PC 0x0c0abc44 */
if(!s->budget--) { s->failed_pc=0x0c0abc44u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0abc46;
P_0c0abc46: /* original 02ed, guest PC 0x0c0abc46 */
if(!s->budget--) { s->failed_pc=0x0c0abc46u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abc48;
P_0c0abc48: /* original 3320, guest PC 0x0c0abc48 */
if(!s->budget--) { s->failed_pc=0x0c0abc48u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0abc4a;
P_0c0abc4a: /* original 8b20, guest PC 0x0c0abc4a */
if(!s->budget--) { s->failed_pc=0x0c0abc4au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abc8e; }
goto P_0c0abc4c;
P_0c0abc4c: /* original e206, guest PC 0x0c0abc4c */
if(!s->budget--) { s->failed_pc=0x0c0abc4cu; return 0; }
r[2]=0x00000006u;
goto P_0c0abc4e;
P_0c0abc4e: /* original 6323, guest PC 0x0c0abc4e */
if(!s->budget--) { s->failed_pc=0x0c0abc4eu; return 0; }
r[3]=r[2];
goto P_0c0abc50;
P_0c0abc50: /* original e062, guest PC 0x0c0abc50 */
if(!s->budget--) { s->failed_pc=0x0c0abc50u; return 0; }
r[0]=0x00000062u;
goto P_0c0abc52;
P_0c0abc52: /* original 1d22, guest PC 0x0c0abc52 */
if(!s->budget--) { s->failed_pc=0x0c0abc52u; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c0abc54;
P_0c0abc54: /* original 0e34, guest PC 0x0c0abc54 */
if(!s->budget--) { s->failed_pc=0x0c0abc54u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0abc56;
P_0c0abc56: /* original 905c, guest PC 0x0c0abc56 */
if(!s->budget--) { s->failed_pc=0x0c0abc56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abd12u,2);
goto P_0c0abc58;
P_0c0abc58: /* original 00ec, guest PC 0x0c0abc58 */
if(!s->budget--) { s->failed_pc=0x0c0abc58u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0abc5a;
P_0c0abc5a: /* original 600c, guest PC 0x0c0abc5a */
if(!s->budget--) { s->failed_pc=0x0c0abc5au; return 0; }
r[0]=r[0]&255u;
goto P_0c0abc5c;
P_0c0abc5c: /* original c801, guest PC 0x0c0abc5c */
if(!s->budget--) { s->failed_pc=0x0c0abc5cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0abc5e;
P_0c0abc5e: /* original 8b02, guest PC 0x0c0abc5e */
if(!s->budget--) { s->failed_pc=0x0c0abc5eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abc66; }
goto P_0c0abc60;
P_0c0abc60: /* original 9c58, guest PC 0x0c0abc60 */
if(!s->budget--) { s->failed_pc=0x0c0abc60u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abd14u,2);
goto P_0c0abc62;
P_0c0abc62: /* original a001, guest PC 0x0c0abc62 */
if(!s->budget--) { s->failed_pc=0x0c0abc62u; return 0; }
goto P_0c0abc68;
P_0c0abc64: /* original 0009, guest PC 0x0c0abc64 */
if(!s->budget--) { s->failed_pc=0x0c0abc64u; return 0; }
goto P_0c0abc66;
P_0c0abc66: /* original 9c56, guest PC 0x0c0abc66 */
if(!s->budget--) { s->failed_pc=0x0c0abc66u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abd16u,2);
goto P_0c0abc68;
P_0c0abc68: /* original d22e, guest PC 0x0c0abc68 */
if(!s->budget--) { s->failed_pc=0x0c0abc68u; return 0; }
r[2]=read(ram,0x0c0abd24u,4);
goto P_0c0abc6a;
P_0c0abc6a: /* original 65c3, guest PC 0x0c0abc6a */
if(!s->budget--) { s->failed_pc=0x0c0abc6au; return 0; }
r[5]=r[12];
goto P_0c0abc6c;
P_0c0abc6c: /* original 420b, guest PC 0x0c0abc6c */
if(!s->budget--) { s->failed_pc=0x0c0abc6cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0abc70u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0abc70u) { target=s->pc; goto dispatch; }
goto P_0c0abc70;
P_0c0abc6e: /* original 64e3, guest PC 0x0c0abc6e */
if(!s->budget--) { s->failed_pc=0x0c0abc6eu; return 0; }
r[4]=r[14];
goto P_0c0abc70;
P_0c0abc70: /* original d32a, guest PC 0x0c0abc70 */
if(!s->budget--) { s->failed_pc=0x0c0abc70u; return 0; }
r[3]=read(ram,0x0c0abd1cu,4);
goto P_0c0abc72;
P_0c0abc72: /* original 66e3, guest PC 0x0c0abc72 */
if(!s->budget--) { s->failed_pc=0x0c0abc72u; return 0; }
r[6]=r[14];
goto P_0c0abc74;
P_0c0abc74: /* original 65d3, guest PC 0x0c0abc74 */
if(!s->budget--) { s->failed_pc=0x0c0abc74u; return 0; }
r[5]=r[13];
goto P_0c0abc76;
P_0c0abc76: /* original 7648, guest PC 0x0c0abc76 */
if(!s->budget--) { s->failed_pc=0x0c0abc76u; return 0; }
r[6]+=0x00000048u;
goto P_0c0abc78;
P_0c0abc78: /* original 430b, guest PC 0x0c0abc78 */
if(!s->budget--) { s->failed_pc=0x0c0abc78u; return 0; }
target=r[3];
r[16]=code_base|0x0c0abc7cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0abc7cu) { target=s->pc; goto dispatch; }
goto P_0c0abc7c;
P_0c0abc7a: /* original 64e3, guest PC 0x0c0abc7a */
if(!s->budget--) { s->failed_pc=0x0c0abc7au; return 0; }
r[4]=r[14];
goto P_0c0abc7c;
P_0c0abc7c: /* original 4f26, guest PC 0x0c0abc7c */
if(!s->budget--) { s->failed_pc=0x0c0abc7cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abc7e;
P_0c0abc7e: /* original 65d3, guest PC 0x0c0abc7e */
if(!s->budget--) { s->failed_pc=0x0c0abc7eu; return 0; }
r[5]=r[13];
goto P_0c0abc80;
P_0c0abc80: /* original 62d2, guest PC 0x0c0abc80 */
if(!s->budget--) { s->failed_pc=0x0c0abc80u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0abc82;
P_0c0abc82: /* original 64e3, guest PC 0x0c0abc82 */
if(!s->budget--) { s->failed_pc=0x0c0abc82u; return 0; }
r[4]=r[14];
goto P_0c0abc84;
P_0c0abc84: /* original 2e22, guest PC 0x0c0abc84 */
if(!s->budget--) { s->failed_pc=0x0c0abc84u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0abc86;
P_0c0abc86: /* original 6cf6, guest PC 0x0c0abc86 */
if(!s->budget--) { s->failed_pc=0x0c0abc86u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0abc88;
P_0c0abc88: /* original 6df6, guest PC 0x0c0abc88 */
if(!s->budget--) { s->failed_pc=0x0c0abc88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abc8a;
P_0c0abc8a: /* original a005, guest PC 0x0c0abc8a */
if(!s->budget--) { s->failed_pc=0x0c0abc8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0abc98u,s,ram);
P_0c0abc8c: /* original 6ef6, guest PC 0x0c0abc8c */
if(!s->budget--) { s->failed_pc=0x0c0abc8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abc8e;
P_0c0abc8e: /* original 4f26, guest PC 0x0c0abc8e */
if(!s->budget--) { s->failed_pc=0x0c0abc8eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abc90;
P_0c0abc90: /* original 6cf6, guest PC 0x0c0abc90 */
if(!s->budget--) { s->failed_pc=0x0c0abc90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0abc92;
P_0c0abc92: /* original 6df6, guest PC 0x0c0abc92 */
if(!s->budget--) { s->failed_pc=0x0c0abc92u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abc94;
P_0c0abc94: /* original 000b, guest PC 0x0c0abc94 */
if(!s->budget--) { s->failed_pc=0x0c0abc94u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0abc96: /* original 6ef6, guest PC 0x0c0abc96 */
if(!s->budget--) { s->failed_pc=0x0c0abc96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0abc98u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
