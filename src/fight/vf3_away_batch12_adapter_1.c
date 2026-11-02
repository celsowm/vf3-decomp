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
int vf3_away_batch12_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03fb10u: goto P_0c03fb10;
case 0x0c03fb12u: goto P_0c03fb12;
case 0x0c03fb14u: goto P_0c03fb14;
case 0x0c03fb16u: goto P_0c03fb16;
case 0x0c03fb18u: goto P_0c03fb18;
case 0x0c03fb1au: goto P_0c03fb1a;
case 0x0c03fb1cu: goto P_0c03fb1c;
case 0x0c03fb1eu: goto P_0c03fb1e;
case 0x0c03fb20u: goto P_0c03fb20;
case 0x0c03fb22u: goto P_0c03fb22;
case 0x0c03fb24u: goto P_0c03fb24;
case 0x0c03fb26u: goto P_0c03fb26;
case 0x0c03fb28u: goto P_0c03fb28;
case 0x0c03fb2au: goto P_0c03fb2a;
case 0x0c03fb2cu: goto P_0c03fb2c;
case 0x0c03fb2eu: goto P_0c03fb2e;
case 0x0c03fb30u: goto P_0c03fb30;
case 0x0c03fb32u: goto P_0c03fb32;
case 0x0c03fb34u: goto P_0c03fb34;
case 0x0c03fb36u: goto P_0c03fb36;
case 0x0c03fb38u: goto P_0c03fb38;
case 0x0c03fb3au: goto P_0c03fb3a;
case 0x0c03fb3cu: goto P_0c03fb3c;
case 0x0c03fb3eu: goto P_0c03fb3e;
case 0x0c03fb40u: goto P_0c03fb40;
case 0x0c03fb42u: goto P_0c03fb42;
case 0x0c03fb44u: goto P_0c03fb44;
case 0x0c03fb46u: goto P_0c03fb46;
case 0x0c03fb48u: goto P_0c03fb48;
case 0x0c03fb4au: goto P_0c03fb4a;
case 0x0c03fb4cu: goto P_0c03fb4c;
case 0x0c03fb4eu: goto P_0c03fb4e;
case 0x0c03fb50u: goto P_0c03fb50;
case 0x0c03fb52u: goto P_0c03fb52;
case 0x0c03fb54u: goto P_0c03fb54;
case 0x0c03fb56u: goto P_0c03fb56;
case 0x0c03fb58u: goto P_0c03fb58;
case 0x0c03fb5au: goto P_0c03fb5a;
case 0x0c03fb5cu: goto P_0c03fb5c;
case 0x0c03fb5eu: goto P_0c03fb5e;
case 0x0c03fb60u: goto P_0c03fb60;
case 0x0c03fb62u: goto P_0c03fb62;
case 0x0c03fb64u: goto P_0c03fb64;
case 0x0c03fb66u: goto P_0c03fb66;
case 0x0c03fb68u: goto P_0c03fb68;
case 0x0c03fb6au: goto P_0c03fb6a;
case 0x0c03fb6cu: goto P_0c03fb6c;
case 0x0c03fb6eu: goto P_0c03fb6e;
case 0x0c03fb70u: goto P_0c03fb70;
case 0x0c03fb72u: goto P_0c03fb72;
case 0x0c03fb74u: goto P_0c03fb74;
case 0x0c03fb76u: goto P_0c03fb76;
case 0x0c03fb78u: goto P_0c03fb78;
case 0x0c03fb7au: goto P_0c03fb7a;
case 0x0c03fb80u: goto P_0c03fb80;
case 0x0c03fb82u: goto P_0c03fb82;
case 0x0c03fb84u: goto P_0c03fb84;
case 0x0c03fb86u: goto P_0c03fb86;
case 0x0c03fb88u: goto P_0c03fb88;
case 0x0c03fb8au: goto P_0c03fb8a;
case 0x0c03fb8cu: goto P_0c03fb8c;
case 0x0c03fb8eu: goto P_0c03fb8e;
case 0x0c03fb90u: goto P_0c03fb90;
case 0x0c03fb92u: goto P_0c03fb92;
case 0x0c03fb94u: goto P_0c03fb94;
case 0x0c03fb96u: goto P_0c03fb96;
case 0x0c03fb98u: goto P_0c03fb98;
case 0x0c03fb9au: goto P_0c03fb9a;
case 0x0c03fb9cu: goto P_0c03fb9c;
case 0x0c03fb9eu: goto P_0c03fb9e;
case 0x0c03fba0u: goto P_0c03fba0;
case 0x0c03fbb0u: goto P_0c03fbb0;
case 0x0c03fbb2u: goto P_0c03fbb2;
case 0x0c03fbb4u: goto P_0c03fbb4;
case 0x0c03fbb6u: goto P_0c03fbb6;
case 0x0c03fbb8u: goto P_0c03fbb8;
case 0x0c03fbbau: goto P_0c03fbba;
case 0x0c03fbbcu: goto P_0c03fbbc;
case 0x0c03fbbeu: goto P_0c03fbbe;
case 0x0c03fbc0u: goto P_0c03fbc0;
case 0x0c03fbc2u: goto P_0c03fbc2;
case 0x0c03fbc4u: goto P_0c03fbc4;
case 0x0c03fbc6u: goto P_0c03fbc6;
case 0x0c03fbd0u: goto P_0c03fbd0;
case 0x0c03fbd2u: goto P_0c03fbd2;
case 0x0c03fbd4u: goto P_0c03fbd4;
case 0x0c03fbd6u: goto P_0c03fbd6;
case 0x0c03fbd8u: goto P_0c03fbd8;
case 0x0c03fbdau: goto P_0c03fbda;
case 0x0c03fbdcu: goto P_0c03fbdc;
case 0x0c03fbdeu: goto P_0c03fbde;
case 0x0c03fbe0u: goto P_0c03fbe0;
case 0x0c03fbe2u: goto P_0c03fbe2;
case 0x0c03fbe4u: goto P_0c03fbe4;
case 0x0c03fbe6u: goto P_0c03fbe6;
case 0x0c03fbf0u: goto P_0c03fbf0;
case 0x0c03fbf2u: goto P_0c03fbf2;
case 0x0c03fbf4u: goto P_0c03fbf4;
case 0x0c03fbf6u: goto P_0c03fbf6;
case 0x0c03fbf8u: goto P_0c03fbf8;
case 0x0c03fbfau: goto P_0c03fbfa;
case 0x0c03fbfcu: goto P_0c03fbfc;
case 0x0c03fbfeu: goto P_0c03fbfe;
case 0x0c03fc00u: goto P_0c03fc00;
case 0x0c03fc02u: goto P_0c03fc02;
case 0x0c03fc04u: goto P_0c03fc04;
case 0x0c03fc06u: goto P_0c03fc06;
case 0x0c03fc50u: goto P_0c03fc50;
case 0x0c03fc52u: goto P_0c03fc52;
case 0x0c03fc54u: goto P_0c03fc54;
case 0x0c03fc56u: goto P_0c03fc56;
case 0x0c03fc58u: goto P_0c03fc58;
case 0x0c03fc5au: goto P_0c03fc5a;
case 0x0c03fc5cu: goto P_0c03fc5c;
case 0x0c03fc5eu: goto P_0c03fc5e;
case 0x0c03fc60u: goto P_0c03fc60;
case 0x0c03fc62u: goto P_0c03fc62;
case 0x0c03fc64u: goto P_0c03fc64;
case 0x0c03fc66u: goto P_0c03fc66;
case 0x0c03fc68u: goto P_0c03fc68;
case 0x0c03fc6au: goto P_0c03fc6a;
case 0x0c03fc6cu: goto P_0c03fc6c;
case 0x0c03fc6eu: goto P_0c03fc6e;
case 0x0c03fc70u: goto P_0c03fc70;
case 0x0c03fc72u: goto P_0c03fc72;
case 0x0c03fc74u: goto P_0c03fc74;
case 0x0c03fc76u: goto P_0c03fc76;
case 0x0c03fc78u: goto P_0c03fc78;
case 0x0c03fc7au: goto P_0c03fc7a;
case 0x0c03fc7cu: goto P_0c03fc7c;
case 0x0c03fc7eu: goto P_0c03fc7e;
case 0x0c03fc80u: goto P_0c03fc80;
case 0x0c040f1eu: goto P_0c040f1e;
case 0x0c040f20u: goto P_0c040f20;
case 0x0c040f22u: goto P_0c040f22;
case 0x0c040f24u: goto P_0c040f24;
case 0x0c040f26u: goto P_0c040f26;
case 0x0c040f28u: goto P_0c040f28;
case 0x0c040f2au: goto P_0c040f2a;
case 0x0c040f2cu: goto P_0c040f2c;
case 0x0c040f2eu: goto P_0c040f2e;
case 0x0c040f30u: goto P_0c040f30;
case 0x0c040f32u: goto P_0c040f32;
case 0x0c040f34u: goto P_0c040f34;
case 0x0c040f36u: goto P_0c040f36;
case 0x0c040f38u: goto P_0c040f38;
case 0x0c040f3au: goto P_0c040f3a;
case 0x0c040f3cu: goto P_0c040f3c;
case 0x0c040f3eu: goto P_0c040f3e;
case 0x0c040f40u: goto P_0c040f40;
case 0x0c040f42u: goto P_0c040f42;
case 0x0c040f44u: goto P_0c040f44;
case 0x0c040f46u: goto P_0c040f46;
case 0x0c040f48u: goto P_0c040f48;
case 0x0c040f4au: goto P_0c040f4a;
case 0x0c040f4cu: goto P_0c040f4c;
case 0x0c040f4eu: goto P_0c040f4e;
case 0x0c040f50u: goto P_0c040f50;
case 0x0c040f52u: goto P_0c040f52;
case 0x0c040f54u: goto P_0c040f54;
case 0x0c040f56u: goto P_0c040f56;
case 0x0c040f58u: goto P_0c040f58;
case 0x0c040f5au: goto P_0c040f5a;
case 0x0c040f5cu: goto P_0c040f5c;
case 0x0c040f5eu: goto P_0c040f5e;
case 0x0c040f60u: goto P_0c040f60;
case 0x0c040f62u: goto P_0c040f62;
case 0x0c040f64u: goto P_0c040f64;
case 0x0c040f66u: goto P_0c040f66;
case 0x0c0423b0u: goto P_0c0423b0;
case 0x0c0423b2u: goto P_0c0423b2;
case 0x0c0423b4u: goto P_0c0423b4;
case 0x0c0423b6u: goto P_0c0423b6;
case 0x0c0423b8u: goto P_0c0423b8;
case 0x0c0423bau: goto P_0c0423ba;
case 0x0c0423bcu: goto P_0c0423bc;
case 0x0c0423beu: goto P_0c0423be;
case 0x0c0423c0u: goto P_0c0423c0;
case 0x0c0423c2u: goto P_0c0423c2;
case 0x0c0423c4u: goto P_0c0423c4;
case 0x0c0423c6u: goto P_0c0423c6;
case 0x0c0423c8u: goto P_0c0423c8;
case 0x0c0423cau: goto P_0c0423ca;
case 0x0c0423ccu: goto P_0c0423cc;
case 0x0c0423ceu: goto P_0c0423ce;
case 0x0c0423d0u: goto P_0c0423d0;
case 0x0c0423d2u: goto P_0c0423d2;
case 0x0c0423d4u: goto P_0c0423d4;
case 0x0c0423d6u: goto P_0c0423d6;
case 0x0c0423d8u: goto P_0c0423d8;
case 0x0c0423dau: goto P_0c0423da;
case 0x0c0423dcu: goto P_0c0423dc;
case 0x0c0423deu: goto P_0c0423de;
case 0x0c0423e0u: goto P_0c0423e0;
case 0x0c0423e2u: goto P_0c0423e2;
case 0x0c0423e4u: goto P_0c0423e4;
case 0x0c0423e6u: goto P_0c0423e6;
case 0x0c0423e8u: goto P_0c0423e8;
case 0x0c0423eau: goto P_0c0423ea;
case 0x0c0423ecu: goto P_0c0423ec;
case 0x0c0423eeu: goto P_0c0423ee;
case 0x0c0423f0u: goto P_0c0423f0;
case 0x0c0423f2u: goto P_0c0423f2;
case 0x0c0423f4u: goto P_0c0423f4;
case 0x0c0423f6u: goto P_0c0423f6;
case 0x0c0423f8u: goto P_0c0423f8;
case 0x0c0423fau: goto P_0c0423fa;
case 0x0c0423fcu: goto P_0c0423fc;
case 0x0c0423feu: goto P_0c0423fe;
case 0x0c042400u: goto P_0c042400;
case 0x0c042402u: goto P_0c042402;
case 0x0c042404u: goto P_0c042404;
case 0x0c042406u: goto P_0c042406;
case 0x0c042408u: goto P_0c042408;
case 0x0c04240au: goto P_0c04240a;
case 0x0c04240cu: goto P_0c04240c;
case 0x0c04240eu: goto P_0c04240e;
case 0x0c042410u: goto P_0c042410;
case 0x0c042412u: goto P_0c042412;
case 0x0c042414u: goto P_0c042414;
case 0x0c042416u: goto P_0c042416;
case 0x0c042418u: goto P_0c042418;
case 0x0c04241au: goto P_0c04241a;
case 0x0c04241cu: goto P_0c04241c;
case 0x0c04241eu: goto P_0c04241e;
case 0x0c042420u: goto P_0c042420;
case 0x0c042422u: goto P_0c042422;
case 0x0c042424u: goto P_0c042424;
case 0x0c042426u: goto P_0c042426;
case 0x0c042428u: goto P_0c042428;
case 0x0c04242au: goto P_0c04242a;
case 0x0c04242cu: goto P_0c04242c;
case 0x0c04242eu: goto P_0c04242e;
case 0x0c042430u: goto P_0c042430;
case 0x0c042432u: goto P_0c042432;
case 0x0c042434u: goto P_0c042434;
case 0x0c042436u: goto P_0c042436;
case 0x0c042438u: goto P_0c042438;
case 0x0c04243au: goto P_0c04243a;
case 0x0c04243cu: goto P_0c04243c;
case 0x0c04243eu: goto P_0c04243e;
case 0x0c042440u: goto P_0c042440;
case 0x0c042442u: goto P_0c042442;
case 0x0c042444u: goto P_0c042444;
case 0x0c042446u: goto P_0c042446;
case 0x0c042448u: goto P_0c042448;
case 0x0c04244au: goto P_0c04244a;
case 0x0c04244cu: goto P_0c04244c;
case 0x0c04244eu: goto P_0c04244e;
case 0x0c042450u: goto P_0c042450;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03fb10: /* original e303, guest PC 0x0c03fb10 */
if(!s->budget--) { s->failed_pc=0x0c03fb10u; return 0; }
r[3]=0x00000003u;
goto P_0c03fb12;
P_0c03fb12: /* original ffeb, guest PC 0x0c03fb12 */
if(!s->budget--) { s->failed_pc=0x0c03fb12u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c03fb14;
P_0c03fb14: /* original 574b, guest PC 0x0c03fb14 */
if(!s->budget--) { s->failed_pc=0x0c03fb14u; return 0; }
r[7]=read(ram,r[4]+44,4);
goto P_0c03fb16;
P_0c03fb16: /* original e104, guest PC 0x0c03fb16 */
if(!s->budget--) { s->failed_pc=0x0c03fb16u; return 0; }
r[1]=0x00000004u;
goto P_0c03fb18;
P_0c03fb18: /* original f95c, guest PC 0x0c03fb18 */
if(!s->budget--) { s->failed_pc=0x0c03fb18u; return 0; }
vf3_matrix_move(s,9,5);
goto P_0c03fb1a;
P_0c03fb1a: /* original f962, guest PC 0x0c03fb1a */
if(!s->budget--) { s->failed_pc=0x0c03fb1au; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[6],r[18],'*');
goto P_0c03fb1c;
P_0c03fb1c: /* original 2379, guest PC 0x0c03fb1c */
if(!s->budget--) { s->failed_pc=0x0c03fb1cu; return 0; }
r[3]&=r[7];
goto P_0c03fb1e;
P_0c03fb1e: /* original f84c, guest PC 0x0c03fb1e */
if(!s->budget--) { s->failed_pc=0x0c03fb1eu; return 0; }
vf3_matrix_move(s,8,4);
goto P_0c03fb20;
P_0c03fb20: /* original 435a, guest PC 0x0c03fb20 */
if(!s->budget--) { s->failed_pc=0x0c03fb20u; return 0; }
r[53]=r[3];
goto P_0c03fb22;
P_0c03fb22: /* original 4721, guest PC 0x0c03fb22 */
if(!s->budget--) { s->failed_pc=0x0c03fb22u; return 0; }
r[17]=(r[17]&~1u)|((r[7]&1)!=0);
r[7]=(uint32_t)((int32_t)r[7]>>1);
goto P_0c03fb24;
P_0c03fb24: /* original e303, guest PC 0x0c03fb24 */
if(!s->budget--) { s->failed_pc=0x0c03fb24u; return 0; }
r[3]=0x00000003u;
goto P_0c03fb26;
P_0c03fb26: /* original f462, guest PC 0x0c03fb26 */
if(!s->budget--) { s->failed_pc=0x0c03fb26u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c03fb28;
P_0c03fb28: /* original 4721, guest PC 0x0c03fb28 */
if(!s->budget--) { s->failed_pc=0x0c03fb28u; return 0; }
r[17]=(r[17]&~1u)|((r[7]&1)!=0);
r[7]=(uint32_t)((int32_t)r[7]>>1);
goto P_0c03fb2a;
P_0c03fb2a: /* original f572, guest PC 0x0c03fb2a */
if(!s->budget--) { s->failed_pc=0x0c03fb2au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c03fb2c;
P_0c03fb2c: /* original f32d, guest PC 0x0c03fb2c */
if(!s->budget--) { s->failed_pc=0x0c03fb2cu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03fb2e;
P_0c03fb2e: /* original 2739, guest PC 0x0c03fb2e */
if(!s->budget--) { s->failed_pc=0x0c03fb2eu; return 0; }
r[7]&=r[3];
goto P_0c03fb30;
P_0c03fb30: /* original 475a, guest PC 0x0c03fb30 */
if(!s->budget--) { s->failed_pc=0x0c03fb30u; return 0; }
r[53]=r[7];
goto P_0c03fb32;
P_0c03fb32: /* original f872, guest PC 0x0c03fb32 */
if(!s->budget--) { s->failed_pc=0x0c03fb32u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[7],r[18],'*');
goto P_0c03fb34;
P_0c03fb34: /* original d73f, guest PC 0x0c03fb34 */
if(!s->budget--) { s->failed_pc=0x0c03fb34u; return 0; }
r[7]=read(ram,0x0c03fc34u,4);
goto P_0c03fb36;
P_0c03fb36: /* original f63c, guest PC 0x0c03fb36 */
if(!s->budget--) { s->failed_pc=0x0c03fb36u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c03fb38;
P_0c03fb38: /* original f32d, guest PC 0x0c03fb38 */
if(!s->budget--) { s->failed_pc=0x0c03fb38u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03fb3a;
P_0c03fb3a: /* original fe3c, guest PC 0x0c03fb3a */
if(!s->budget--) { s->failed_pc=0x0c03fb3au; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c03fb3c;
P_0c03fb3c: /* original f779, guest PC 0x0c03fb3c */
if(!s->budget--) { s->failed_pc=0x0c03fb3cu; return 0; }
vf3_matrix_load(s,ram,7,r[7]);
r[7]+=(r[18]&0x100000u)?8:4;
goto P_0c03fb3e;
P_0c03fb3e: /* original e004, guest PC 0x0c03fb3e */
if(!s->budget--) { s->failed_pc=0x0c03fb3eu; return 0; }
r[0]=0x00000004u;
goto P_0c03fb40;
P_0c03fb40: /* original f38d, guest PC 0x0c03fb40 */
if(!s->budget--) { s->failed_pc=0x0c03fb40u; return 0; }
fr[3]=0;
goto P_0c03fb42;
P_0c03fb42: /* original f761, guest PC 0x0c03fb42 */
if(!s->budget--) { s->failed_pc=0x0c03fb42u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'-');
goto P_0c03fb44;
P_0c03fb44: /* original fa79, guest PC 0x0c03fb44 */
if(!s->budget--) { s->failed_pc=0x0c03fb44u; return 0; }
vf3_matrix_load(s,ram,10,r[7]);
r[7]+=(r[18]&0x100000u)?8:4;
goto P_0c03fb46;
P_0c03fb46: /* original fb46, guest PC 0x0c03fb46 */
if(!s->budget--) { s->failed_pc=0x0c03fb46u; return 0; }
vf3_matrix_load(s,ram,11,r[4]+r[0]);
goto P_0c03fb48;
P_0c03fb48: /* original e008, guest PC 0x0c03fb48 */
if(!s->budget--) { s->failed_pc=0x0c03fb48u; return 0; }
r[0]=0x00000008u;
goto P_0c03fb4a;
P_0c03fb4a: /* original fae1, guest PC 0x0c03fb4a */
if(!s->budget--) { s->failed_pc=0x0c03fb4au; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[14],r[18],'-');
goto P_0c03fb4c;
P_0c03fb4c: /* original f734, guest PC 0x0c03fb4c */
if(!s->budget--) { s->failed_pc=0x0c03fb4cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])==as_float(fr[3]))!=0);
goto P_0c03fb4e;
P_0c03fb4e: /* original 8d06, guest PC 0x0c03fb4e */
if(!s->budget--) { s->failed_pc=0x0c03fb4eu; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,1,r[4]+r[0]);
if(cond) { goto P_0c03fb5e; }
goto P_0c03fb52;
P_0c03fb50: /* original f146, guest PC 0x0c03fb50 */
if(!s->budget--) { s->failed_pc=0x0c03fb50u; return 0; }
vf3_matrix_load(s,ram,1,r[4]+r[0]);
goto P_0c03fb52;
P_0c03fb52: /* original f24c, guest PC 0x0c03fb52 */
if(!s->budget--) { s->failed_pc=0x0c03fb52u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03fb54;
P_0c03fb54: /* original f272, guest PC 0x0c03fb54 */
if(!s->budget--) { s->failed_pc=0x0c03fb54u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c03fb56;
P_0c03fb56: /* original f07c, guest PC 0x0c03fb56 */
if(!s->budget--) { s->failed_pc=0x0c03fb56u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c03fb58;
P_0c03fb58: /* original fb8e, guest PC 0x0c03fb58 */
if(!s->budget--) { s->failed_pc=0x0c03fb58u; return 0; }
fr[11]=vf3_fpu_mac(fr[0],fr[8],fr[11],r[18]);
goto P_0c03fb5a;
P_0c03fb5a: /* original f24d, guest PC 0x0c03fb5a */
if(!s->budget--) { s->failed_pc=0x0c03fb5au; return 0; }
fr[2]^=0x80000000u;
goto P_0c03fb5c;
P_0c03fb5c: /* original f120, guest PC 0x0c03fb5c */
if(!s->budget--) { s->failed_pc=0x0c03fb5cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c03fb5e;
P_0c03fb5e: /* original f38d, guest PC 0x0c03fb5e */
if(!s->budget--) { s->failed_pc=0x0c03fb5eu; return 0; }
fr[3]=0;
goto P_0c03fb60;
P_0c03fb60: /* original fa34, guest PC 0x0c03fb60 */
if(!s->budget--) { s->failed_pc=0x0c03fb60u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])==as_float(fr[3]))!=0);
goto P_0c03fb62;
P_0c03fb62: /* original 8902, guest PC 0x0c03fb62 */
if(!s->budget--) { s->failed_pc=0x0c03fb62u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03fb6a; }
goto P_0c03fb64;
P_0c03fb64: /* original f0ac, guest PC 0x0c03fb64 */
if(!s->budget--) { s->failed_pc=0x0c03fb64u; return 0; }
vf3_matrix_move(s,0,10);
goto P_0c03fb66;
P_0c03fb66: /* original f15e, guest PC 0x0c03fb66 */
if(!s->budget--) { s->failed_pc=0x0c03fb66u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[5],fr[1],r[18]);
goto P_0c03fb68;
P_0c03fb68: /* original fb9e, guest PC 0x0c03fb68 */
if(!s->budget--) { s->failed_pc=0x0c03fb68u; return 0; }
fr[11]=vf3_fpu_mac(fr[0],fr[9],fr[11],r[18]);
goto P_0c03fb6a;
P_0c03fb6a: /* original 71ff, guest PC 0x0c03fb6a */
if(!s->budget--) { s->failed_pc=0x0c03fb6au; return 0; }
r[1]+=0xffffffffu;
goto P_0c03fb6c;
P_0c03fb6c: /* original f5ba, guest PC 0x0c03fb6c */
if(!s->budget--) { s->failed_pc=0x0c03fb6cu; return 0; }
vf3_matrix_store(s,ram,11,r[5]);
goto P_0c03fb6e;
P_0c03fb6e: /* original f61a, guest PC 0x0c03fb6e */
if(!s->budget--) { s->failed_pc=0x0c03fb6eu; return 0; }
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c03fb70;
P_0c03fb70: /* original 2118, guest PC 0x0c03fb70 */
if(!s->budget--) { s->failed_pc=0x0c03fb70u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c03fb72;
P_0c03fb72: /* original 7604, guest PC 0x0c03fb72 */
if(!s->budget--) { s->failed_pc=0x0c03fb72u; return 0; }
r[6]+=0x00000004u;
goto P_0c03fb74;
P_0c03fb74: /* original 8fe2, guest PC 0x0c03fb74 */
if(!s->budget--) { s->failed_pc=0x0c03fb74u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(!cond) { goto P_0c03fb3c; }
goto P_0c03fb78;
P_0c03fb76: /* original 7504, guest PC 0x0c03fb76 */
if(!s->budget--) { s->failed_pc=0x0c03fb76u; return 0; }
r[5]+=0x00000004u;
goto P_0c03fb78;
P_0c03fb78: /* original 000b, guest PC 0x0c03fb78 */
if(!s->budget--) { s->failed_pc=0x0c03fb78u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c03fb7a: /* original fef9, guest PC 0x0c03fb7a */
if(!s->budget--) { s->failed_pc=0x0c03fb7au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c03fb7cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fb7cu; return 0; } return 1;
P_0c03fb80: /* original c72d, guest PC 0x0c03fb80 */
if(!s->budget--) { s->failed_pc=0x0c03fb80u; return 0; }
r[0]=code_base|0x0003fc38u;
goto P_0c03fb82;
P_0c03fb82: /* original f808, guest PC 0x0c03fb82 */
if(!s->budget--) { s->failed_pc=0x0c03fb82u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c03fb84;
P_0c03fb84: /* original c72d, guest PC 0x0c03fb84 */
if(!s->budget--) { s->failed_pc=0x0c03fb84u; return 0; }
r[0]=code_base|0x0003fc3cu;
goto P_0c03fb86;
P_0c03fb86: /* original f908, guest PC 0x0c03fb86 */
if(!s->budget--) { s->failed_pc=0x0c03fb86u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c03fb88;
P_0c03fb88: /* original f482, guest PC 0x0c03fb88 */
if(!s->budget--) { s->failed_pc=0x0c03fb88u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'*');
goto P_0c03fb8a;
P_0c03fb8a: /* original f582, guest PC 0x0c03fb8a */
if(!s->budget--) { s->failed_pc=0x0c03fb8au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'*');
goto P_0c03fb8c;
P_0c03fb8c: /* original f682, guest PC 0x0c03fb8c */
if(!s->budget--) { s->failed_pc=0x0c03fb8cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'*');
goto P_0c03fb8e;
P_0c03fb8e: /* original f782, guest PC 0x0c03fb8e */
if(!s->budget--) { s->failed_pc=0x0c03fb8eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[8],r[18],'*');
goto P_0c03fb90;
P_0c03fb90: /* original f495, guest PC 0x0c03fb90 */
if(!s->budget--) { s->failed_pc=0x0c03fb90u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[9]))!=0);
goto P_0c03fb92;
P_0c03fb92: /* original 8f0d, guest PC 0x0c03fb92 */
if(!s->budget--) { s->failed_pc=0x0c03fb92u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,8,4);
if(!cond) { goto P_0c03fbb0; }
goto P_0c03fb96;
P_0c03fb94: /* original f84c, guest PC 0x0c03fb94 */
if(!s->budget--) { s->failed_pc=0x0c03fb94u; return 0; }
vf3_matrix_move(s,8,4);
goto P_0c03fb96;
P_0c03fb96: /* original c72a, guest PC 0x0c03fb96 */
if(!s->budget--) { s->failed_pc=0x0c03fb96u; return 0; }
r[0]=code_base|0x0003fc40u;
goto P_0c03fb98;
P_0c03fb98: /* original f28c, guest PC 0x0c03fb98 */
if(!s->budget--) { s->failed_pc=0x0c03fb98u; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c03fb9a;
P_0c03fb9a: /* original f308, guest PC 0x0c03fb9a */
if(!s->budget--) { s->failed_pc=0x0c03fb9au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03fb9c;
P_0c03fb9c: /* original f230, guest PC 0x0c03fb9c */
if(!s->budget--) { s->failed_pc=0x0c03fb9cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c03fb9e;
P_0c03fb9e: /* original a008, guest PC 0x0c03fb9e */
if(!s->budget--) { s->failed_pc=0x0c03fb9eu; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c03fbb2;
P_0c03fba0: /* original f32c, guest PC 0x0c03fba0 */
if(!s->budget--) { s->failed_pc=0x0c03fba0u; return 0; }
vf3_matrix_move(s,3,2);
if(!vf3_matrix_family(0x0c03fba2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fba2u; return 0; } return 1;
P_0c03fbb0: /* original f38c, guest PC 0x0c03fbb0 */
if(!s->budget--) { s->failed_pc=0x0c03fbb0u; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c03fbb2;
P_0c03fbb2: /* original f33d, guest PC 0x0c03fbb2 */
if(!s->budget--) { s->failed_pc=0x0c03fbb2u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03fbb4;
P_0c03fbb4: /* original f595, guest PC 0x0c03fbb4 */
if(!s->budget--) { s->failed_pc=0x0c03fbb4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[9]))!=0);
goto P_0c03fbb6;
P_0c03fbb6: /* original 045a, guest PC 0x0c03fbb6 */
if(!s->budget--) { s->failed_pc=0x0c03fbb6u; return 0; }
r[4]=r[53];
goto P_0c03fbb8;
P_0c03fbb8: /* original 8f0a, guest PC 0x0c03fbb8 */
if(!s->budget--) { s->failed_pc=0x0c03fbb8u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,5);
if(!cond) { goto P_0c03fbd0; }
goto P_0c03fbbc;
P_0c03fbba: /* original f45c, guest PC 0x0c03fbba */
if(!s->budget--) { s->failed_pc=0x0c03fbbau; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c03fbbc;
P_0c03fbbc: /* original c720, guest PC 0x0c03fbbc */
if(!s->budget--) { s->failed_pc=0x0c03fbbcu; return 0; }
r[0]=code_base|0x0003fc40u;
goto P_0c03fbbe;
P_0c03fbbe: /* original f24c, guest PC 0x0c03fbbe */
if(!s->budget--) { s->failed_pc=0x0c03fbbeu; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03fbc0;
P_0c03fbc0: /* original f308, guest PC 0x0c03fbc0 */
if(!s->budget--) { s->failed_pc=0x0c03fbc0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03fbc2;
P_0c03fbc2: /* original f230, guest PC 0x0c03fbc2 */
if(!s->budget--) { s->failed_pc=0x0c03fbc2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c03fbc4;
P_0c03fbc4: /* original a005, guest PC 0x0c03fbc4 */
if(!s->budget--) { s->failed_pc=0x0c03fbc4u; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c03fbd2;
P_0c03fbc6: /* original f32c, guest PC 0x0c03fbc6 */
if(!s->budget--) { s->failed_pc=0x0c03fbc6u; return 0; }
vf3_matrix_move(s,3,2);
if(!vf3_matrix_family(0x0c03fbc8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fbc8u; return 0; } return 1;
P_0c03fbd0: /* original f34c, guest PC 0x0c03fbd0 */
if(!s->budget--) { s->failed_pc=0x0c03fbd0u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03fbd2;
P_0c03fbd2: /* original f33d, guest PC 0x0c03fbd2 */
if(!s->budget--) { s->failed_pc=0x0c03fbd2u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03fbd4;
P_0c03fbd4: /* original f695, guest PC 0x0c03fbd4 */
if(!s->budget--) { s->failed_pc=0x0c03fbd4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[9]))!=0);
goto P_0c03fbd6;
P_0c03fbd6: /* original 055a, guest PC 0x0c03fbd6 */
if(!s->budget--) { s->failed_pc=0x0c03fbd6u; return 0; }
r[5]=r[53];
goto P_0c03fbd8;
P_0c03fbd8: /* original 8f0a, guest PC 0x0c03fbd8 */
if(!s->budget--) { s->failed_pc=0x0c03fbd8u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,6);
if(!cond) { goto P_0c03fbf0; }
goto P_0c03fbdc;
P_0c03fbda: /* original f46c, guest PC 0x0c03fbda */
if(!s->budget--) { s->failed_pc=0x0c03fbdau; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c03fbdc;
P_0c03fbdc: /* original c718, guest PC 0x0c03fbdc */
if(!s->budget--) { s->failed_pc=0x0c03fbdcu; return 0; }
r[0]=code_base|0x0003fc40u;
goto P_0c03fbde;
P_0c03fbde: /* original f24c, guest PC 0x0c03fbde */
if(!s->budget--) { s->failed_pc=0x0c03fbdeu; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03fbe0;
P_0c03fbe0: /* original f308, guest PC 0x0c03fbe0 */
if(!s->budget--) { s->failed_pc=0x0c03fbe0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03fbe2;
P_0c03fbe2: /* original f230, guest PC 0x0c03fbe2 */
if(!s->budget--) { s->failed_pc=0x0c03fbe2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c03fbe4;
P_0c03fbe4: /* original a005, guest PC 0x0c03fbe4 */
if(!s->budget--) { s->failed_pc=0x0c03fbe4u; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c03fbf2;
P_0c03fbe6: /* original f32c, guest PC 0x0c03fbe6 */
if(!s->budget--) { s->failed_pc=0x0c03fbe6u; return 0; }
vf3_matrix_move(s,3,2);
if(!vf3_matrix_family(0x0c03fbe8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fbe8u; return 0; } return 1;
P_0c03fbf0: /* original f34c, guest PC 0x0c03fbf0 */
if(!s->budget--) { s->failed_pc=0x0c03fbf0u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03fbf2;
P_0c03fbf2: /* original f33d, guest PC 0x0c03fbf2 */
if(!s->budget--) { s->failed_pc=0x0c03fbf2u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03fbf4;
P_0c03fbf4: /* original f795, guest PC 0x0c03fbf4 */
if(!s->budget--) { s->failed_pc=0x0c03fbf4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[9]))!=0);
goto P_0c03fbf6;
P_0c03fbf6: /* original 065a, guest PC 0x0c03fbf6 */
if(!s->budget--) { s->failed_pc=0x0c03fbf6u; return 0; }
r[6]=r[53];
goto P_0c03fbf8;
P_0c03fbf8: /* original 8f2a, guest PC 0x0c03fbf8 */
if(!s->budget--) { s->failed_pc=0x0c03fbf8u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,7);
if(!cond) { goto P_0c03fc50; }
goto P_0c03fbfc;
P_0c03fbfa: /* original f47c, guest PC 0x0c03fbfa */
if(!s->budget--) { s->failed_pc=0x0c03fbfau; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c03fbfc;
P_0c03fbfc: /* original c710, guest PC 0x0c03fbfc */
if(!s->budget--) { s->failed_pc=0x0c03fbfcu; return 0; }
r[0]=code_base|0x0003fc40u;
goto P_0c03fbfe;
P_0c03fbfe: /* original f24c, guest PC 0x0c03fbfe */
if(!s->budget--) { s->failed_pc=0x0c03fbfeu; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03fc00;
P_0c03fc00: /* original f308, guest PC 0x0c03fc00 */
if(!s->budget--) { s->failed_pc=0x0c03fc00u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03fc02;
P_0c03fc02: /* original f230, guest PC 0x0c03fc02 */
if(!s->budget--) { s->failed_pc=0x0c03fc02u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c03fc04;
P_0c03fc04: /* original a025, guest PC 0x0c03fc04 */
if(!s->budget--) { s->failed_pc=0x0c03fc04u; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c03fc52;
P_0c03fc06: /* original f32c, guest PC 0x0c03fc06 */
if(!s->budget--) { s->failed_pc=0x0c03fc06u; return 0; }
vf3_matrix_move(s,3,2);
if(!vf3_matrix_family(0x0c03fc08u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fc08u; return 0; } return 1;
P_0c03fc50: /* original f34c, guest PC 0x0c03fc50 */
if(!s->budget--) { s->failed_pc=0x0c03fc50u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03fc52;
P_0c03fc52: /* original f33d, guest PC 0x0c03fc52 */
if(!s->budget--) { s->failed_pc=0x0c03fc52u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03fc54;
P_0c03fc54: /* original 9077, guest PC 0x0c03fc54 */
if(!s->budget--) { s->failed_pc=0x0c03fc54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03fd46u,2);
goto P_0c03fc56;
P_0c03fc56: /* original 3406, guest PC 0x0c03fc56 */
if(!s->budget--) { s->failed_pc=0x0c03fc56u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[0])!=0);
goto P_0c03fc58;
P_0c03fc58: /* original 075a, guest PC 0x0c03fc58 */
if(!s->budget--) { s->failed_pc=0x0c03fc58u; return 0; }
r[7]=r[53];
goto P_0c03fc5a;
P_0c03fc5a: /* original 8f01, guest PC 0x0c03fc5a */
if(!s->budget--) { s->failed_pc=0x0c03fc5au; return 0; }
cond=r[17]&1u;
r[1]=0x00000000u;
if(!cond) { goto P_0c03fc60; }
goto P_0c03fc5e;
P_0c03fc5c: /* original e100, guest PC 0x0c03fc5c */
if(!s->budget--) { s->failed_pc=0x0c03fc5cu; return 0; }
r[1]=0x00000000u;
goto P_0c03fc5e;
P_0c03fc5e: /* original 6403, guest PC 0x0c03fc5e */
if(!s->budget--) { s->failed_pc=0x0c03fc5eu; return 0; }
r[4]=r[0];
goto P_0c03fc60;
P_0c03fc60: /* original 3506, guest PC 0x0c03fc60 */
if(!s->budget--) { s->failed_pc=0x0c03fc60u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[0])!=0);
goto P_0c03fc62;
P_0c03fc62: /* original 8b00, guest PC 0x0c03fc62 */
if(!s->budget--) { s->failed_pc=0x0c03fc62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fc66; }
goto P_0c03fc64;
P_0c03fc64: /* original 6503, guest PC 0x0c03fc64 */
if(!s->budget--) { s->failed_pc=0x0c03fc64u; return 0; }
r[5]=r[0];
goto P_0c03fc66;
P_0c03fc66: /* original 3606, guest PC 0x0c03fc66 */
if(!s->budget--) { s->failed_pc=0x0c03fc66u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>r[0])!=0);
goto P_0c03fc68;
P_0c03fc68: /* original 8b00, guest PC 0x0c03fc68 */
if(!s->budget--) { s->failed_pc=0x0c03fc68u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fc6c; }
goto P_0c03fc6a;
P_0c03fc6a: /* original 6603, guest PC 0x0c03fc6a */
if(!s->budget--) { s->failed_pc=0x0c03fc6au; return 0; }
r[6]=r[0];
goto P_0c03fc6c;
P_0c03fc6c: /* original 3706, guest PC 0x0c03fc6c */
if(!s->budget--) { s->failed_pc=0x0c03fc6cu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>r[0])!=0);
goto P_0c03fc6e;
P_0c03fc6e: /* original 8f01, guest PC 0x0c03fc6e */
if(!s->budget--) { s->failed_pc=0x0c03fc6eu; return 0; }
cond=r[17]&1u;
r[4]<<=8;
if(!cond) { goto P_0c03fc74; }
goto P_0c03fc72;
P_0c03fc70: /* original 4418, guest PC 0x0c03fc70 */
if(!s->budget--) { s->failed_pc=0x0c03fc70u; return 0; }
r[4]<<=8;
goto P_0c03fc72;
P_0c03fc72: /* original 6703, guest PC 0x0c03fc72 */
if(!s->budget--) { s->failed_pc=0x0c03fc72u; return 0; }
r[7]=r[0];
goto P_0c03fc74;
P_0c03fc74: /* original 245b, guest PC 0x0c03fc74 */
if(!s->budget--) { s->failed_pc=0x0c03fc74u; return 0; }
r[4]|=r[5];
goto P_0c03fc76;
P_0c03fc76: /* original 4418, guest PC 0x0c03fc76 */
if(!s->budget--) { s->failed_pc=0x0c03fc76u; return 0; }
r[4]<<=8;
goto P_0c03fc78;
P_0c03fc78: /* original 246b, guest PC 0x0c03fc78 */
if(!s->budget--) { s->failed_pc=0x0c03fc78u; return 0; }
r[4]|=r[6];
goto P_0c03fc7a;
P_0c03fc7a: /* original 4418, guest PC 0x0c03fc7a */
if(!s->budget--) { s->failed_pc=0x0c03fc7au; return 0; }
r[4]<<=8;
goto P_0c03fc7c;
P_0c03fc7c: /* original 247b, guest PC 0x0c03fc7c */
if(!s->budget--) { s->failed_pc=0x0c03fc7cu; return 0; }
r[4]|=r[7];
goto P_0c03fc7e;
P_0c03fc7e: /* original 000b, guest PC 0x0c03fc7e */
if(!s->budget--) { s->failed_pc=0x0c03fc7eu; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c03fc80: /* original 6043, guest PC 0x0c03fc80 */
if(!s->budget--) { s->failed_pc=0x0c03fc80u; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c03fc82u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fc82u; return 0; } return 1;
P_0c040f1e: /* original 7ffc, guest PC 0x0c040f1e */
if(!s->budget--) { s->failed_pc=0x0c040f1eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c040f20;
P_0c040f20: /* original 2f42, guest PC 0x0c040f20 */
if(!s->budget--) { s->failed_pc=0x0c040f20u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c040f22;
P_0c040f22: /* original 60f2, guest PC 0x0c040f22 */
if(!s->budget--) { s->failed_pc=0x0c040f22u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c040f24;
P_0c040f24: /* original c880, guest PC 0x0c040f24 */
if(!s->budget--) { s->failed_pc=0x0c040f24u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c040f26;
P_0c040f26: /* original 8b03, guest PC 0x0c040f26 */
if(!s->budget--) { s->failed_pc=0x0c040f26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040f30; }
goto P_0c040f28;
P_0c040f28: /* original e0fe, guest PC 0x0c040f28 */
if(!s->budget--) { s->failed_pc=0x0c040f28u; return 0; }
r[0]=0xfffffffeu;
goto P_0c040f2a;
P_0c040f2a: /* original 7f04, guest PC 0x0c040f2a */
if(!s->budget--) { s->failed_pc=0x0c040f2au; return 0; }
r[15]+=0x00000004u;
goto P_0c040f2c;
P_0c040f2c: /* original 000b, guest PC 0x0c040f2c */
if(!s->budget--) { s->failed_pc=0x0c040f2cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f2e: /* original 0009, guest PC 0x0c040f2e */
if(!s->budget--) { s->failed_pc=0x0c040f2eu; return 0; }
goto P_0c040f30;
P_0c040f30: /* original d30d, guest PC 0x0c040f30 */
if(!s->budget--) { s->failed_pc=0x0c040f30u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f32;
P_0c040f32: /* original 6232, guest PC 0x0c040f32 */
if(!s->budget--) { s->failed_pc=0x0c040f32u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040f34;
P_0c040f34: /* original 6122, guest PC 0x0c040f34 */
if(!s->budget--) { s->failed_pc=0x0c040f34u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c040f36;
P_0c040f36: /* original 2118, guest PC 0x0c040f36 */
if(!s->budget--) { s->failed_pc=0x0c040f36u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c040f38;
P_0c040f38: /* original 8903, guest PC 0x0c040f38 */
if(!s->budget--) { s->failed_pc=0x0c040f38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040f42; }
goto P_0c040f3a;
P_0c040f3a: /* original e0ff, guest PC 0x0c040f3a */
if(!s->budget--) { s->failed_pc=0x0c040f3au; return 0; }
r[0]=0xffffffffu;
goto P_0c040f3c;
P_0c040f3c: /* original 7f04, guest PC 0x0c040f3c */
if(!s->budget--) { s->failed_pc=0x0c040f3cu; return 0; }
r[15]+=0x00000004u;
goto P_0c040f3e;
P_0c040f3e: /* original 000b, guest PC 0x0c040f3e */
if(!s->budget--) { s->failed_pc=0x0c040f3eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f40: /* original 0009, guest PC 0x0c040f40 */
if(!s->budget--) { s->failed_pc=0x0c040f40u; return 0; }
goto P_0c040f42;
P_0c040f42: /* original d309, guest PC 0x0c040f42 */
if(!s->budget--) { s->failed_pc=0x0c040f42u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f44;
P_0c040f44: /* original 6232, guest PC 0x0c040f44 */
if(!s->budget--) { s->failed_pc=0x0c040f44u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040f46;
P_0c040f46: /* original 7204, guest PC 0x0c040f46 */
if(!s->budget--) { s->failed_pc=0x0c040f46u; return 0; }
r[2]+=0x00000004u;
goto P_0c040f48;
P_0c040f48: /* original 2322, guest PC 0x0c040f48 */
if(!s->budget--) { s->failed_pc=0x0c040f48u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c040f4a;
P_0c040f4a: /* original 72fc, guest PC 0x0c040f4a */
if(!s->budget--) { s->failed_pc=0x0c040f4au; return 0; }
r[2]+=0xfffffffcu;
goto P_0c040f4c;
P_0c040f4c: /* original 63f2, guest PC 0x0c040f4c */
if(!s->budget--) { s->failed_pc=0x0c040f4cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c040f4e;
P_0c040f4e: /* original 2232, guest PC 0x0c040f4e */
if(!s->budget--) { s->failed_pc=0x0c040f4eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c040f50;
P_0c040f50: /* original d206, guest PC 0x0c040f50 */
if(!s->budget--) { s->failed_pc=0x0c040f50u; return 0; }
r[2]=read(ram,0x0c040f6cu,4);
goto P_0c040f52;
P_0c040f52: /* original d305, guest PC 0x0c040f52 */
if(!s->budget--) { s->failed_pc=0x0c040f52u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f54;
P_0c040f54: /* original 6132, guest PC 0x0c040f54 */
if(!s->budget--) { s->failed_pc=0x0c040f54u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c040f56;
P_0c040f56: /* original 3120, guest PC 0x0c040f56 */
if(!s->budget--) { s->failed_pc=0x0c040f56u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c040f58;
P_0c040f58: /* original 8b02, guest PC 0x0c040f58 */
if(!s->budget--) { s->failed_pc=0x0c040f58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040f60; }
goto P_0c040f5a;
P_0c040f5a: /* original d305, guest PC 0x0c040f5a */
if(!s->budget--) { s->failed_pc=0x0c040f5au; return 0; }
r[3]=read(ram,0x0c040f70u,4);
goto P_0c040f5c;
P_0c040f5c: /* original d002, guest PC 0x0c040f5c */
if(!s->budget--) { s->failed_pc=0x0c040f5cu; return 0; }
r[0]=read(ram,0x0c040f68u,4);
goto P_0c040f5e;
P_0c040f5e: /* original 2032, guest PC 0x0c040f5e */
if(!s->budget--) { s->failed_pc=0x0c040f5eu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c040f60;
P_0c040f60: /* original e000, guest PC 0x0c040f60 */
if(!s->budget--) { s->failed_pc=0x0c040f60u; return 0; }
r[0]=0x00000000u;
goto P_0c040f62;
P_0c040f62: /* original 7f04, guest PC 0x0c040f62 */
if(!s->budget--) { s->failed_pc=0x0c040f62u; return 0; }
r[15]+=0x00000004u;
goto P_0c040f64;
P_0c040f64: /* original 000b, guest PC 0x0c040f64 */
if(!s->budget--) { s->failed_pc=0x0c040f64u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f66: /* original 0009, guest PC 0x0c040f66 */
if(!s->budget--) { s->failed_pc=0x0c040f66u; return 0; }
if(!vf3_matrix_family(0x0c040f68u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040f68u; return 0; } return 1;
P_0c0423b0: /* original 2fe6, guest PC 0x0c0423b0 */
if(!s->budget--) { s->failed_pc=0x0c0423b0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423b2;
P_0c0423b2: /* original 2fd6, guest PC 0x0c0423b2 */
if(!s->budget--) { s->failed_pc=0x0c0423b2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423b4;
P_0c0423b4: /* original 2fc6, guest PC 0x0c0423b4 */
if(!s->budget--) { s->failed_pc=0x0c0423b4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423b6;
P_0c0423b6: /* original 2fb6, guest PC 0x0c0423b6 */
if(!s->budget--) { s->failed_pc=0x0c0423b6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423b8;
P_0c0423b8: /* original 2fa6, guest PC 0x0c0423b8 */
if(!s->budget--) { s->failed_pc=0x0c0423b8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423ba;
P_0c0423ba: /* original 2f96, guest PC 0x0c0423ba */
if(!s->budget--) { s->failed_pc=0x0c0423bau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423bc;
P_0c0423bc: /* original 2f86, guest PC 0x0c0423bc */
if(!s->budget--) { s->failed_pc=0x0c0423bcu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0423be;
P_0c0423be: /* original d12c, guest PC 0x0c0423be */
if(!s->budget--) { s->failed_pc=0x0c0423beu; return 0; }
r[1]=read(ram,0x0c042470u,4);
goto P_0c0423c0;
P_0c0423c0: /* original 7ff4, guest PC 0x0c0423c0 */
if(!s->budget--) { s->failed_pc=0x0c0423c0u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0423c2;
P_0c0423c2: /* original 6e12, guest PC 0x0c0423c2 */
if(!s->budget--) { s->failed_pc=0x0c0423c2u; return 0; }
tmp=read(ram,r[1],4);
r[14]=tmp;
goto P_0c0423c4;
P_0c0423c4: /* original 2ee8, guest PC 0x0c0423c4 */
if(!s->budget--) { s->failed_pc=0x0c0423c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0423c6;
P_0c0423c6: /* original 893b, guest PC 0x0c0423c6 */
if(!s->budget--) { s->failed_pc=0x0c0423c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042440; }
goto P_0c0423c8;
P_0c0423c8: /* original 6df3, guest PC 0x0c0423c8 */
if(!s->budget--) { s->failed_pc=0x0c0423c8u; return 0; }
r[13]=r[15];
goto P_0c0423ca;
P_0c0423ca: /* original dc2c, guest PC 0x0c0423ca */
if(!s->budget--) { s->failed_pc=0x0c0423cau; return 0; }
r[12]=read(ram,0x0c04247cu,4);
goto P_0c0423cc;
P_0c0423cc: /* original 7d04, guest PC 0x0c0423cc */
if(!s->budget--) { s->failed_pc=0x0c0423ccu; return 0; }
r[13]+=0x00000004u;
goto P_0c0423ce;
P_0c0423ce: /* original 2d41, guest PC 0x0c0423ce */
if(!s->budget--) { s->failed_pc=0x0c0423ceu; return 0; }
write(ram,r[13],r[4],2);
goto P_0c0423d0;
P_0c0423d0: /* original 2c41, guest PC 0x0c0423d0 */
if(!s->budget--) { s->failed_pc=0x0c0423d0u; return 0; }
write(ram,r[12],r[4],2);
goto P_0c0423d2;
P_0c0423d2: /* original 6053, guest PC 0x0c0423d2 */
if(!s->budget--) { s->failed_pc=0x0c0423d2u; return 0; }
r[0]=r[5];
goto P_0c0423d4;
P_0c0423d4: /* original 0009, guest PC 0x0c0423d4 */
if(!s->budget--) { s->failed_pc=0x0c0423d4u; return 0; }
goto P_0c0423d6;
P_0c0423d6: /* original 81d1, guest PC 0x0c0423d6 */
if(!s->budget--) { s->failed_pc=0x0c0423d6u; return 0; }
write(ram,r[13]+2,r[0],2);
goto P_0c0423d8;
P_0c0423d8: /* original 81c1, guest PC 0x0c0423d8 */
if(!s->budget--) { s->failed_pc=0x0c0423d8u; return 0; }
write(ram,r[12]+2,r[0],2);
goto P_0c0423da;
P_0c0423da: /* original 6063, guest PC 0x0c0423da */
if(!s->budget--) { s->failed_pc=0x0c0423dau; return 0; }
r[0]=r[6];
goto P_0c0423dc;
P_0c0423dc: /* original 0009, guest PC 0x0c0423dc */
if(!s->budget--) { s->failed_pc=0x0c0423dcu; return 0; }
goto P_0c0423de;
P_0c0423de: /* original 81d2, guest PC 0x0c0423de */
if(!s->budget--) { s->failed_pc=0x0c0423deu; return 0; }
write(ram,r[13]+4,r[0],2);
goto P_0c0423e0;
P_0c0423e0: /* original 81c2, guest PC 0x0c0423e0 */
if(!s->budget--) { s->failed_pc=0x0c0423e0u; return 0; }
write(ram,r[12]+4,r[0],2);
goto P_0c0423e2;
P_0c0423e2: /* original 6073, guest PC 0x0c0423e2 */
if(!s->budget--) { s->failed_pc=0x0c0423e2u; return 0; }
r[0]=r[7];
goto P_0c0423e4;
P_0c0423e4: /* original 0009, guest PC 0x0c0423e4 */
if(!s->budget--) { s->failed_pc=0x0c0423e4u; return 0; }
goto P_0c0423e6;
P_0c0423e6: /* original e500, guest PC 0x0c0423e6 */
if(!s->budget--) { s->failed_pc=0x0c0423e6u; return 0; }
r[5]=0x00000000u;
goto P_0c0423e8;
P_0c0423e8: /* original 81d3, guest PC 0x0c0423e8 */
if(!s->budget--) { s->failed_pc=0x0c0423e8u; return 0; }
write(ram,r[13]+6,r[0],2);
goto P_0c0423ea;
P_0c0423ea: /* original e404, guest PC 0x0c0423ea */
if(!s->budget--) { s->failed_pc=0x0c0423eau; return 0; }
r[4]=0x00000004u;
goto P_0c0423ec;
P_0c0423ec: /* original 6853, guest PC 0x0c0423ec */
if(!s->budget--) { s->failed_pc=0x0c0423ecu; return 0; }
r[8]=r[5];
goto P_0c0423ee;
P_0c0423ee: /* original 81c3, guest PC 0x0c0423ee */
if(!s->budget--) { s->failed_pc=0x0c0423eeu; return 0; }
write(ram,r[12]+6,r[0],2);
goto P_0c0423f0;
P_0c0423f0: /* original 6383, guest PC 0x0c0423f0 */
if(!s->budget--) { s->failed_pc=0x0c0423f0u; return 0; }
r[3]=r[8];
goto P_0c0423f2;
P_0c0423f2: /* original 4300, guest PC 0x0c0423f2 */
if(!s->budget--) { s->failed_pc=0x0c0423f2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0423f4;
P_0c0423f4: /* original 33dc, guest PC 0x0c0423f4 */
if(!s->budget--) { s->failed_pc=0x0c0423f4u; return 0; }
r[3]+=r[13];
goto P_0c0423f6;
P_0c0423f6: /* original 6c53, guest PC 0x0c0423f6 */
if(!s->budget--) { s->failed_pc=0x0c0423f6u; return 0; }
r[12]=r[5];
goto P_0c0423f8;
P_0c0423f8: /* original 2f32, guest PC 0x0c0423f8 */
if(!s->budget--) { s->failed_pc=0x0c0423f8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0423fa;
P_0c0423fa: /* original 69c3, guest PC 0x0c0423fa */
if(!s->budget--) { s->failed_pc=0x0c0423fau; return 0; }
r[9]=r[12];
goto P_0c0423fc;
P_0c0423fc: /* original 4900, guest PC 0x0c0423fc */
if(!s->budget--) { s->failed_pc=0x0c0423fcu; return 0; }
r[17]=(r[17]&~1u)|((r[9]>>31)!=0);
r[9]<<=1;
goto P_0c0423fe;
P_0c0423fe: /* original 39dc, guest PC 0x0c0423fe */
if(!s->budget--) { s->failed_pc=0x0c0423feu; return 0; }
r[9]+=r[13];
goto P_0c042400;
P_0c042400: /* original 6653, guest PC 0x0c042400 */
if(!s->budget--) { s->failed_pc=0x0c042400u; return 0; }
r[6]=r[5];
goto P_0c042402;
P_0c042402: /* original 6b63, guest PC 0x0c042402 */
if(!s->budget--) { s->failed_pc=0x0c042402u; return 0; }
r[11]=r[6];
goto P_0c042404;
P_0c042404: /* original 4b00, guest PC 0x0c042404 */
if(!s->budget--) { s->failed_pc=0x0c042404u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c042406;
P_0c042406: /* original ea00, guest PC 0x0c042406 */
if(!s->budget--) { s->failed_pc=0x0c042406u; return 0; }
r[10]=0x00000000u;
goto P_0c042408;
P_0c042408: /* original 6753, guest PC 0x0c042408 */
if(!s->budget--) { s->failed_pc=0x0c042408u; return 0; }
r[7]=r[5];
goto P_0c04240a;
P_0c04240a: /* original 3bdc, guest PC 0x0c04240a */
if(!s->budget--) { s->failed_pc=0x0c04240au; return 0; }
r[11]+=r[13];
goto P_0c04240c;
P_0c04240c: /* original 3adc, guest PC 0x0c04240c */
if(!s->budget--) { s->failed_pc=0x0c04240cu; return 0; }
r[10]+=r[13];
goto P_0c04240e;
P_0c04240e: /* original 62a5, guest PC 0x0c04240e */
if(!s->budget--) { s->failed_pc=0x0c04240eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[10],2);
r[10]+=2;
r[2]=tmp;
goto P_0c042410;
P_0c042410: /* original 7701, guest PC 0x0c042410 */
if(!s->budget--) { s->failed_pc=0x0c042410u; return 0; }
r[7]+=0x00000001u;
goto P_0c042412;
P_0c042412: /* original 3743, guest PC 0x0c042412 */
if(!s->budget--) { s->failed_pc=0x0c042412u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[4])!=0);
goto P_0c042414;
P_0c042414: /* original 2e21, guest PC 0x0c042414 */
if(!s->budget--) { s->failed_pc=0x0c042414u; return 0; }
write(ram,r[14],r[2],2);
goto P_0c042416;
P_0c042416: /* original 7e02, guest PC 0x0c042416 */
if(!s->budget--) { s->failed_pc=0x0c042416u; return 0; }
r[14]+=0x00000002u;
goto P_0c042418;
P_0c042418: /* original 62b1, guest PC 0x0c042418 */
if(!s->budget--) { s->failed_pc=0x0c042418u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[11],2);
r[2]=tmp;
goto P_0c04241a;
P_0c04241a: /* original 2e21, guest PC 0x0c04241a */
if(!s->budget--) { s->failed_pc=0x0c04241au; return 0; }
write(ram,r[14],r[2],2);
goto P_0c04241c;
P_0c04241c: /* original 7e02, guest PC 0x0c04241c */
if(!s->budget--) { s->failed_pc=0x0c04241cu; return 0; }
r[14]+=0x00000002u;
goto P_0c04241e;
P_0c04241e: /* original 6291, guest PC 0x0c04241e */
if(!s->budget--) { s->failed_pc=0x0c04241eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[9],2);
r[2]=tmp;
goto P_0c042420;
P_0c042420: /* original 2e21, guest PC 0x0c042420 */
if(!s->budget--) { s->failed_pc=0x0c042420u; return 0; }
write(ram,r[14],r[2],2);
goto P_0c042422;
P_0c042422: /* original 7e02, guest PC 0x0c042422 */
if(!s->budget--) { s->failed_pc=0x0c042422u; return 0; }
r[14]+=0x00000002u;
goto P_0c042424;
P_0c042424: /* original 62f2, guest PC 0x0c042424 */
if(!s->budget--) { s->failed_pc=0x0c042424u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c042426;
P_0c042426: /* original 6121, guest PC 0x0c042426 */
if(!s->budget--) { s->failed_pc=0x0c042426u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[1]=tmp;
goto P_0c042428;
P_0c042428: /* original 2e11, guest PC 0x0c042428 */
if(!s->budget--) { s->failed_pc=0x0c042428u; return 0; }
write(ram,r[14],r[1],2);
goto P_0c04242a;
P_0c04242a: /* original 8ff0, guest PC 0x0c04242a */
if(!s->budget--) { s->failed_pc=0x0c04242au; return 0; }
cond=r[17]&1u;
r[14]+=0x00000002u;
if(!cond) { goto P_0c04240e; }
goto P_0c04242e;
P_0c04242c: /* original 7e02, guest PC 0x0c04242c */
if(!s->budget--) { s->failed_pc=0x0c04242cu; return 0; }
r[14]+=0x00000002u;
goto P_0c04242e;
P_0c04242e: /* original 7601, guest PC 0x0c04242e */
if(!s->budget--) { s->failed_pc=0x0c04242eu; return 0; }
r[6]+=0x00000001u;
goto P_0c042430;
P_0c042430: /* original 3643, guest PC 0x0c042430 */
if(!s->budget--) { s->failed_pc=0x0c042430u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[4])!=0);
goto P_0c042432;
P_0c042432: /* original 8be6, guest PC 0x0c042432 */
if(!s->budget--) { s->failed_pc=0x0c042432u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042402; }
goto P_0c042434;
P_0c042434: /* original 7c01, guest PC 0x0c042434 */
if(!s->budget--) { s->failed_pc=0x0c042434u; return 0; }
r[12]+=0x00000001u;
goto P_0c042436;
P_0c042436: /* original 3c43, guest PC 0x0c042436 */
if(!s->budget--) { s->failed_pc=0x0c042436u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[4])!=0);
goto P_0c042438;
P_0c042438: /* original 8bdf, guest PC 0x0c042438 */
if(!s->budget--) { s->failed_pc=0x0c042438u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0423fa; }
goto P_0c04243a;
P_0c04243a: /* original 7801, guest PC 0x0c04243a */
if(!s->budget--) { s->failed_pc=0x0c04243au; return 0; }
r[8]+=0x00000001u;
goto P_0c04243c;
P_0c04243c: /* original 3843, guest PC 0x0c04243c */
if(!s->budget--) { s->failed_pc=0x0c04243cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[4])!=0);
goto P_0c04243e;
P_0c04243e: /* original 8bd7, guest PC 0x0c04243e */
if(!s->budget--) { s->failed_pc=0x0c04243eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0423f0; }
goto P_0c042440;
P_0c042440: /* original 7f0c, guest PC 0x0c042440 */
if(!s->budget--) { s->failed_pc=0x0c042440u; return 0; }
r[15]+=0x0000000cu;
goto P_0c042442;
P_0c042442: /* original 68f6, guest PC 0x0c042442 */
if(!s->budget--) { s->failed_pc=0x0c042442u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c042444;
P_0c042444: /* original 69f6, guest PC 0x0c042444 */
if(!s->budget--) { s->failed_pc=0x0c042444u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c042446;
P_0c042446: /* original 6af6, guest PC 0x0c042446 */
if(!s->budget--) { s->failed_pc=0x0c042446u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c042448;
P_0c042448: /* original 6bf6, guest PC 0x0c042448 */
if(!s->budget--) { s->failed_pc=0x0c042448u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04244a;
P_0c04244a: /* original 6cf6, guest PC 0x0c04244a */
if(!s->budget--) { s->failed_pc=0x0c04244au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04244c;
P_0c04244c: /* original 6df6, guest PC 0x0c04244c */
if(!s->budget--) { s->failed_pc=0x0c04244cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04244e;
P_0c04244e: /* original 000b, guest PC 0x0c04244e */
if(!s->budget--) { s->failed_pc=0x0c04244eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c042450: /* original 6ef6, guest PC 0x0c042450 */
if(!s->budget--) { s->failed_pc=0x0c042450u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c042452u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042452u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
