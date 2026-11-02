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
int vf3_away_batch44_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c03fc90u: goto P_0c03fc90;
case 0x0c03fc92u: goto P_0c03fc92;
case 0x0c03fc94u: goto P_0c03fc94;
case 0x0c03fc96u: goto P_0c03fc96;
case 0x0c03fc98u: goto P_0c03fc98;
case 0x0c03fc9au: goto P_0c03fc9a;
case 0x0c03fc9cu: goto P_0c03fc9c;
case 0x0c03fc9eu: goto P_0c03fc9e;
case 0x0c03fca0u: goto P_0c03fca0;
case 0x0c03fca2u: goto P_0c03fca2;
case 0x0c03fca4u: goto P_0c03fca4;
case 0x0c03fca6u: goto P_0c03fca6;
case 0x0c03fca8u: goto P_0c03fca8;
case 0x0c03fcaau: goto P_0c03fcaa;
case 0x0c03fcacu: goto P_0c03fcac;
case 0x0c03fcaeu: goto P_0c03fcae;
case 0x0c03fcb0u: goto P_0c03fcb0;
case 0x0c03fcb2u: goto P_0c03fcb2;
case 0x0c03fcb4u: goto P_0c03fcb4;
case 0x0c03fcb6u: goto P_0c03fcb6;
case 0x0c03fcb8u: goto P_0c03fcb8;
case 0x0c03fcbau: goto P_0c03fcba;
case 0x0c03fcbcu: goto P_0c03fcbc;
case 0x0c03fcbeu: goto P_0c03fcbe;
case 0x0c03fcc0u: goto P_0c03fcc0;
case 0x0c03fcc2u: goto P_0c03fcc2;
case 0x0c03fcc4u: goto P_0c03fcc4;
case 0x0c03fcc6u: goto P_0c03fcc6;
case 0x0c03fcc8u: goto P_0c03fcc8;
case 0x0c03fccau: goto P_0c03fcca;
case 0x0c03fcccu: goto P_0c03fccc;
case 0x0c03fcceu: goto P_0c03fcce;
case 0x0c03fcd0u: goto P_0c03fcd0;
case 0x0c03fcd2u: goto P_0c03fcd2;
case 0x0c03fcd4u: goto P_0c03fcd4;
case 0x0c03fcd6u: goto P_0c03fcd6;
case 0x0c03fcd8u: goto P_0c03fcd8;
case 0x0c03fcdau: goto P_0c03fcda;
case 0x0c03fcdcu: goto P_0c03fcdc;
case 0x0c03fcdeu: goto P_0c03fcde;
case 0x0c03fce0u: goto P_0c03fce0;
case 0x0c03fce2u: goto P_0c03fce2;
case 0x0c03fce4u: goto P_0c03fce4;
case 0x0c03fce6u: goto P_0c03fce6;
case 0x0c03fce8u: goto P_0c03fce8;
case 0x0c03fceau: goto P_0c03fcea;
case 0x0c03fcecu: goto P_0c03fcec;
case 0x0c03fcf0u: goto P_0c03fcf0;
case 0x0c03fcf2u: goto P_0c03fcf2;
case 0x0c03fcf4u: goto P_0c03fcf4;
case 0x0c03fcf6u: goto P_0c03fcf6;
case 0x0c03fcf8u: goto P_0c03fcf8;
case 0x0c03fcfau: goto P_0c03fcfa;
case 0x0c03fcfcu: goto P_0c03fcfc;
case 0x0c03fcfeu: goto P_0c03fcfe;
case 0x0c03fd00u: goto P_0c03fd00;
case 0x0c03fd02u: goto P_0c03fd02;
case 0x0c03fd04u: goto P_0c03fd04;
case 0x0c03fd06u: goto P_0c03fd06;
case 0x0c03fd08u: goto P_0c03fd08;
case 0x0c03fd0au: goto P_0c03fd0a;
case 0x0c03fd10u: goto P_0c03fd10;
case 0x0c03fd12u: goto P_0c03fd12;
case 0x0c03fd14u: goto P_0c03fd14;
case 0x0c03fd16u: goto P_0c03fd16;
case 0x0c03fd18u: goto P_0c03fd18;
case 0x0c03fd1au: goto P_0c03fd1a;
case 0x0c03fd1cu: goto P_0c03fd1c;
case 0x0c03fd1eu: goto P_0c03fd1e;
case 0x0c03fd20u: goto P_0c03fd20;
case 0x0c03fd22u: goto P_0c03fd22;
case 0x0c03fd24u: goto P_0c03fd24;
case 0x0c03fd26u: goto P_0c03fd26;
case 0x0c03fd28u: goto P_0c03fd28;
case 0x0c03fd2au: goto P_0c03fd2a;
case 0x0c03fd2cu: goto P_0c03fd2c;
case 0x0c03fd2eu: goto P_0c03fd2e;
case 0x0c03fd30u: goto P_0c03fd30;
case 0x0c03fd32u: goto P_0c03fd32;
case 0x0c03fd34u: goto P_0c03fd34;
case 0x0c03fd36u: goto P_0c03fd36;
case 0x0c03fd38u: goto P_0c03fd38;
case 0x0c03fd3au: goto P_0c03fd3a;
case 0x0c03fd3cu: goto P_0c03fd3c;
case 0x0c03fd3eu: goto P_0c03fd3e;
case 0x0c03fd40u: goto P_0c03fd40;
case 0x0c03fd42u: goto P_0c03fd42;
case 0x0c03fd44u: goto P_0c03fd44;
case 0x0c03fd70u: goto P_0c03fd70;
case 0x0c03fd72u: goto P_0c03fd72;
case 0x0c03fd74u: goto P_0c03fd74;
case 0x0c03fd76u: goto P_0c03fd76;
case 0x0c03fd78u: goto P_0c03fd78;
case 0x0c03fd7au: goto P_0c03fd7a;
case 0x0c03fd7cu: goto P_0c03fd7c;
case 0x0c03fd7eu: goto P_0c03fd7e;
case 0x0c03fd80u: goto P_0c03fd80;
case 0x0c03fd82u: goto P_0c03fd82;
case 0x0c03fd84u: goto P_0c03fd84;
case 0x0c03fd86u: goto P_0c03fd86;
case 0x0c03fd88u: goto P_0c03fd88;
case 0x0c03fd8au: goto P_0c03fd8a;
case 0x0c03fd8cu: goto P_0c03fd8c;
case 0x0c03fd8eu: goto P_0c03fd8e;
case 0x0c03fd90u: goto P_0c03fd90;
case 0x0c03fd92u: goto P_0c03fd92;
case 0x0c03fd94u: goto P_0c03fd94;
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
P_0c03fc90: /* original 2fe6, guest PC 0x0c03fc90 */
if(!s->budget--) { s->failed_pc=0x0c03fc90u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fc92;
P_0c03fc92: /* original 6e43, guest PC 0x0c03fc92 */
if(!s->budget--) { s->failed_pc=0x0c03fc92u; return 0; }
r[14]=r[4];
goto P_0c03fc94;
P_0c03fc94: /* original d32d, guest PC 0x0c03fc94 */
if(!s->budget--) { s->failed_pc=0x0c03fc94u; return 0; }
r[3]=read(ram,0x0c03fd4cu,4);
goto P_0c03fc96;
P_0c03fc96: /* original 4f22, guest PC 0x0c03fc96 */
if(!s->budget--) { s->failed_pc=0x0c03fc96u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03fc98;
P_0c03fc98: /* original 2e32, guest PC 0x0c03fc98 */
if(!s->budget--) { s->failed_pc=0x0c03fc98u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c03fc9a;
P_0c03fc9a: /* original d22d, guest PC 0x0c03fc9a */
if(!s->budget--) { s->failed_pc=0x0c03fc9au; return 0; }
r[2]=read(ram,0x0c03fd50u,4);
goto P_0c03fc9c;
P_0c03fc9c: /* original 1e21, guest PC 0x0c03fc9c */
if(!s->budget--) { s->failed_pc=0x0c03fc9cu; return 0; }
write(ram,r[14]+4,r[2],4);
goto P_0c03fc9e;
P_0c03fc9e: /* original e200, guest PC 0x0c03fc9e */
if(!s->budget--) { s->failed_pc=0x0c03fc9eu; return 0; }
r[2]=0x00000000u;
goto P_0c03fca0;
P_0c03fca0: /* original 9352, guest PC 0x0c03fca0 */
if(!s->budget--) { s->failed_pc=0x0c03fca0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03fd48u,2);
goto P_0c03fca2;
P_0c03fca2: /* original 1e32, guest PC 0x0c03fca2 */
if(!s->budget--) { s->failed_pc=0x0c03fca2u; return 0; }
write(ram,r[14]+8,r[3],4);
goto P_0c03fca4;
P_0c03fca4: /* original 1e23, guest PC 0x0c03fca4 */
if(!s->budget--) { s->failed_pc=0x0c03fca4u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c03fca6;
P_0c03fca6: /* original d32b, guest PC 0x0c03fca6 */
if(!s->budget--) { s->failed_pc=0x0c03fca6u; return 0; }
r[3]=read(ram,0x0c03fd54u,4);
goto P_0c03fca8;
P_0c03fca8: /* original 430b, guest PC 0x0c03fca8 */
if(!s->budget--) { s->failed_pc=0x0c03fca8u; return 0; }
target=r[3];
r[16]=code_base|0x0c03fcacu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03fcacu) { target=s->pc; goto dispatch; }
goto P_0c03fcac;
P_0c03fcaa: /* original 64e3, guest PC 0x0c03fcaa */
if(!s->budget--) { s->failed_pc=0x0c03fcaau; return 0; }
r[4]=r[14];
goto P_0c03fcac;
P_0c03fcac: /* original 55e3, guest PC 0x0c03fcac */
if(!s->budget--) { s->failed_pc=0x0c03fcacu; return 0; }
r[5]=read(ram,r[14]+12,4);
goto P_0c03fcae;
P_0c03fcae: /* original e3e5, guest PC 0x0c03fcae */
if(!s->budget--) { s->failed_pc=0x0c03fcaeu; return 0; }
r[3]=0xffffffe5u;
goto P_0c03fcb0;
P_0c03fcb0: /* original e407, guest PC 0x0c03fcb0 */
if(!s->budget--) { s->failed_pc=0x0c03fcb0u; return 0; }
r[4]=0x00000007u;
goto P_0c03fcb2;
P_0c03fcb2: /* original 453d, guest PC 0x0c03fcb2 */
if(!s->budget--) { s->failed_pc=0x0c03fcb2u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c03fcb4;
P_0c03fcb4: /* original 2549, guest PC 0x0c03fcb4 */
if(!s->budget--) { s->failed_pc=0x0c03fcb4u; return 0; }
r[5]&=r[4];
goto P_0c03fcb6;
P_0c03fcb6: /* original 2558, guest PC 0x0c03fcb6 */
if(!s->budget--) { s->failed_pc=0x0c03fcb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c03fcb8;
P_0c03fcb8: /* original e200, guest PC 0x0c03fcb8 */
if(!s->budget--) { s->failed_pc=0x0c03fcb8u; return 0; }
r[2]=0x00000000u;
goto P_0c03fcba;
P_0c03fcba: /* original 8d04, guest PC 0x0c03fcba */
if(!s->budget--) { s->failed_pc=0x0c03fcbau; return 0; }
cond=r[17]&1u;
write(ram,r[14]+20,r[2],4);
if(cond) { goto P_0c03fcc6; }
goto P_0c03fcbe;
P_0c03fcbc: /* original 1e25, guest PC 0x0c03fcbc */
if(!s->budget--) { s->failed_pc=0x0c03fcbcu; return 0; }
write(ram,r[14]+20,r[2],4);
goto P_0c03fcbe;
P_0c03fcbe: /* original 6053, guest PC 0x0c03fcbe */
if(!s->budget--) { s->failed_pc=0x0c03fcbeu; return 0; }
r[0]=r[5];
goto P_0c03fcc0;
P_0c03fcc0: /* original 0009, guest PC 0x0c03fcc0 */
if(!s->budget--) { s->failed_pc=0x0c03fcc0u; return 0; }
goto P_0c03fcc2;
P_0c03fcc2: /* original 8802, guest PC 0x0c03fcc2 */
if(!s->budget--) { s->failed_pc=0x0c03fcc2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c03fcc4;
P_0c03fcc4: /* original 8b01, guest PC 0x0c03fcc4 */
if(!s->budget--) { s->failed_pc=0x0c03fcc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fcca; }
goto P_0c03fcc6;
P_0c03fcc6: /* original e301, guest PC 0x0c03fcc6 */
if(!s->budget--) { s->failed_pc=0x0c03fcc6u; return 0; }
r[3]=0x00000001u;
goto P_0c03fcc8;
P_0c03fcc8: /* original 1e35, guest PC 0x0c03fcc8 */
if(!s->budget--) { s->failed_pc=0x0c03fcc8u; return 0; }
write(ram,r[14]+20,r[3],4);
goto P_0c03fcca;
P_0c03fcca: /* original 50e2, guest PC 0x0c03fcca */
if(!s->budget--) { s->failed_pc=0x0c03fccau; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c03fccc;
P_0c03fccc: /* original d522, guest PC 0x0c03fccc */
if(!s->budget--) { s->failed_pc=0x0c03fcccu; return 0; }
r[5]=read(ram,0x0c03fd58u,4);
goto P_0c03fcce;
P_0c03fcce: /* original 4009, guest PC 0x0c03fcce */
if(!s->budget--) { s->failed_pc=0x0c03fcceu; return 0; }
r[0]>>=2;
goto P_0c03fcd0;
P_0c03fcd0: /* original 4001, guest PC 0x0c03fcd0 */
if(!s->budget--) { s->failed_pc=0x0c03fcd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c03fcd2;
P_0c03fcd2: /* original 2049, guest PC 0x0c03fcd2 */
if(!s->budget--) { s->failed_pc=0x0c03fcd2u; return 0; }
r[0]&=r[4];
goto P_0c03fcd4;
P_0c03fcd4: /* original 4008, guest PC 0x0c03fcd4 */
if(!s->budget--) { s->failed_pc=0x0c03fcd4u; return 0; }
r[0]<<=2;
goto P_0c03fcd6;
P_0c03fcd6: /* original f356, guest PC 0x0c03fcd6 */
if(!s->budget--) { s->failed_pc=0x0c03fcd6u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c03fcd8;
P_0c03fcd8: /* original e018, guest PC 0x0c03fcd8 */
if(!s->budget--) { s->failed_pc=0x0c03fcd8u; return 0; }
r[0]=0x00000018u;
goto P_0c03fcda;
P_0c03fcda: /* original 4f26, guest PC 0x0c03fcda */
if(!s->budget--) { s->failed_pc=0x0c03fcdau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03fcdc;
P_0c03fcdc: /* original fe37, guest PC 0x0c03fcdc */
if(!s->budget--) { s->failed_pc=0x0c03fcdcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c03fcde;
P_0c03fcde: /* original 50e2, guest PC 0x0c03fcde */
if(!s->budget--) { s->failed_pc=0x0c03fcdeu; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c03fce0;
P_0c03fce0: /* original 2049, guest PC 0x0c03fce0 */
if(!s->budget--) { s->failed_pc=0x0c03fce0u; return 0; }
r[0]&=r[4];
goto P_0c03fce2;
P_0c03fce2: /* original 4008, guest PC 0x0c03fce2 */
if(!s->budget--) { s->failed_pc=0x0c03fce2u; return 0; }
r[0]<<=2;
goto P_0c03fce4;
P_0c03fce4: /* original f356, guest PC 0x0c03fce4 */
if(!s->budget--) { s->failed_pc=0x0c03fce4u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c03fce6;
P_0c03fce6: /* original e01c, guest PC 0x0c03fce6 */
if(!s->budget--) { s->failed_pc=0x0c03fce6u; return 0; }
r[0]=0x0000001cu;
goto P_0c03fce8;
P_0c03fce8: /* original fe37, guest PC 0x0c03fce8 */
if(!s->budget--) { s->failed_pc=0x0c03fce8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c03fcea;
P_0c03fcea: /* original 000b, guest PC 0x0c03fcea */
if(!s->budget--) { s->failed_pc=0x0c03fceau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03fcec: /* original 6ef6, guest PC 0x0c03fcec */
if(!s->budget--) { s->failed_pc=0x0c03fcecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03fceeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fceeu; return 0; } return 1;
P_0c03fcf0: /* original 2fe6, guest PC 0x0c03fcf0 */
if(!s->budget--) { s->failed_pc=0x0c03fcf0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcf2;
P_0c03fcf2: /* original 2fd6, guest PC 0x0c03fcf2 */
if(!s->budget--) { s->failed_pc=0x0c03fcf2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcf4;
P_0c03fcf4: /* original 2fb6, guest PC 0x0c03fcf4 */
if(!s->budget--) { s->failed_pc=0x0c03fcf4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcf6;
P_0c03fcf6: /* original eb00, guest PC 0x0c03fcf6 */
if(!s->budget--) { s->failed_pc=0x0c03fcf6u; return 0; }
r[11]=0x00000000u;
goto P_0c03fcf8;
P_0c03fcf8: /* original 2fa6, guest PC 0x0c03fcf8 */
if(!s->budget--) { s->failed_pc=0x0c03fcf8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcfa;
P_0c03fcfa: /* original ea01, guest PC 0x0c03fcfa */
if(!s->budget--) { s->failed_pc=0x0c03fcfau; return 0; }
r[10]=0x00000001u;
goto P_0c03fcfc;
P_0c03fcfc: /* original 2f96, guest PC 0x0c03fcfc */
if(!s->budget--) { s->failed_pc=0x0c03fcfcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcfe;
P_0c03fcfe: /* original e920, guest PC 0x0c03fcfe */
if(!s->budget--) { s->failed_pc=0x0c03fcfeu; return 0; }
r[9]=0x00000020u;
goto P_0c03fd00;
P_0c03fd00: /* original 2f86, guest PC 0x0c03fd00 */
if(!s->budget--) { s->failed_pc=0x0c03fd00u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fd02;
P_0c03fd02: /* original 4f22, guest PC 0x0c03fd02 */
if(!s->budget--) { s->failed_pc=0x0c03fd02u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03fd04;
P_0c03fd04: /* original d716, guest PC 0x0c03fd04 */
if(!s->budget--) { s->failed_pc=0x0c03fd04u; return 0; }
r[7]=read(ram,0x0c03fd60u,4);
goto P_0c03fd06;
P_0c03fd06: /* original d815, guest PC 0x0c03fd06 */
if(!s->budget--) { s->failed_pc=0x0c03fd06u; return 0; }
r[8]=read(ram,0x0c03fd5cu,4);
goto P_0c03fd08;
P_0c03fd08: /* original a033, guest PC 0x0c03fd08 */
if(!s->budget--) { s->failed_pc=0x0c03fd08u; return 0; }
r[5]=r[11];
goto P_0c03fd72;
P_0c03fd0a: /* original 65b3, guest PC 0x0c03fd0a */
if(!s->budget--) { s->failed_pc=0x0c03fd0au; return 0; }
r[5]=r[11];
if(!vf3_matrix_family(0x0c03fd0cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fd0cu; return 0; } return 1;
P_0c03fd10: /* original 6072, guest PC 0x0c03fd10 */
if(!s->budget--) { s->failed_pc=0x0c03fd10u; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c03fd12;
P_0c03fd12: /* original 6e53, guest PC 0x0c03fd12 */
if(!s->budget--) { s->failed_pc=0x0c03fd12u; return 0; }
r[14]=r[5];
goto P_0c03fd14;
P_0c03fd14: /* original 4e08, guest PC 0x0c03fd14 */
if(!s->budget--) { s->failed_pc=0x0c03fd14u; return 0; }
r[14]<<=2;
goto P_0c03fd16;
P_0c03fd16: /* original 00ee, guest PC 0x0c03fd16 */
if(!s->budget--) { s->failed_pc=0x0c03fd16u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c03fd18;
P_0c03fd18: /* original 88ff, guest PC 0x0c03fd18 */
if(!s->budget--) { s->failed_pc=0x0c03fd18u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03fd1a;
P_0c03fd1a: /* original 8d29, guest PC 0x0c03fd1a */
if(!s->budget--) { s->failed_pc=0x0c03fd1au; return 0; }
cond=r[17]&1u;
r[13]=r[0];
if(cond) { goto P_0c03fd70; }
goto P_0c03fd1e;
P_0c03fd1c: /* original 6d03, guest PC 0x0c03fd1c */
if(!s->budget--) { s->failed_pc=0x0c03fd1cu; return 0; }
r[13]=r[0];
goto P_0c03fd1e;
P_0c03fd1e: /* original 6153, guest PC 0x0c03fd1e */
if(!s->budget--) { s->failed_pc=0x0c03fd1eu; return 0; }
r[1]=r[5];
goto P_0c03fd20;
P_0c03fd20: /* original 4108, guest PC 0x0c03fd20 */
if(!s->budget--) { s->failed_pc=0x0c03fd20u; return 0; }
r[1]<<=2;
goto P_0c03fd22;
P_0c03fd22: /* original 4108, guest PC 0x0c03fd22 */
if(!s->budget--) { s->failed_pc=0x0c03fd22u; return 0; }
r[1]<<=2;
goto P_0c03fd24;
P_0c03fd24: /* original 66b3, guest PC 0x0c03fd24 */
if(!s->budget--) { s->failed_pc=0x0c03fd24u; return 0; }
r[6]=r[11];
goto P_0c03fd26;
P_0c03fd26: /* original 4100, guest PC 0x0c03fd26 */
if(!s->budget--) { s->failed_pc=0x0c03fd26u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c03fd28;
P_0c03fd28: /* original 64a3, guest PC 0x0c03fd28 */
if(!s->budget--) { s->failed_pc=0x0c03fd28u; return 0; }
r[4]=r[10];
goto P_0c03fd2a;
P_0c03fd2a: /* original 62d3, guest PC 0x0c03fd2a */
if(!s->budget--) { s->failed_pc=0x0c03fd2au; return 0; }
r[2]=r[13];
goto P_0c03fd2c;
P_0c03fd2c: /* original 2248, guest PC 0x0c03fd2c */
if(!s->budget--) { s->failed_pc=0x0c03fd2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c03fd2e;
P_0c03fd2e: /* original 8b07, guest PC 0x0c03fd2e */
if(!s->budget--) { s->failed_pc=0x0c03fd2eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fd40; }
goto P_0c03fd30;
P_0c03fd30: /* original 6072, guest PC 0x0c03fd30 */
if(!s->budget--) { s->failed_pc=0x0c03fd30u; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c03fd32;
P_0c03fd32: /* original 02ee, guest PC 0x0c03fd32 */
if(!s->budget--) { s->failed_pc=0x0c03fd32u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c03fd34;
P_0c03fd34: /* original 224b, guest PC 0x0c03fd34 */
if(!s->budget--) { s->failed_pc=0x0c03fd34u; return 0; }
r[2]|=r[4];
goto P_0c03fd36;
P_0c03fd36: /* original 0e26, guest PC 0x0c03fd36 */
if(!s->budget--) { s->failed_pc=0x0c03fd36u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c03fd38;
P_0c03fd38: /* original 6013, guest PC 0x0c03fd38 */
if(!s->budget--) { s->failed_pc=0x0c03fd38u; return 0; }
r[0]=r[1];
goto P_0c03fd3a;
P_0c03fd3a: /* original 0009, guest PC 0x0c03fd3a */
if(!s->budget--) { s->failed_pc=0x0c03fd3au; return 0; }
goto P_0c03fd3c;
P_0c03fd3c: /* original a023, guest PC 0x0c03fd3c */
if(!s->budget--) { s->failed_pc=0x0c03fd3cu; return 0; }
r[0]+=r[6];
goto P_0c03fd86;
P_0c03fd3e: /* original 306c, guest PC 0x0c03fd3e */
if(!s->budget--) { s->failed_pc=0x0c03fd3eu; return 0; }
r[0]+=r[6];
goto P_0c03fd40;
P_0c03fd40: /* original 4400, guest PC 0x0c03fd40 */
if(!s->budget--) { s->failed_pc=0x0c03fd40u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c03fd42;
P_0c03fd42: /* original aff2, guest PC 0x0c03fd42 */
if(!s->budget--) { s->failed_pc=0x0c03fd42u; return 0; }
r[6]+=0x00000001u;
goto P_0c03fd2a;
P_0c03fd44: /* original 7601, guest PC 0x0c03fd44 */
if(!s->budget--) { s->failed_pc=0x0c03fd44u; return 0; }
r[6]+=0x00000001u;
if(!vf3_matrix_family(0x0c03fd46u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fd46u; return 0; } return 1;
P_0c03fd70: /* original 7501, guest PC 0x0c03fd70 */
if(!s->budget--) { s->failed_pc=0x0c03fd70u; return 0; }
r[5]+=0x00000001u;
goto P_0c03fd72;
P_0c03fd72: /* original 6182, guest PC 0x0c03fd72 */
if(!s->budget--) { s->failed_pc=0x0c03fd72u; return 0; }
tmp=read(ram,r[8],4);
r[1]=tmp;
goto P_0c03fd74;
P_0c03fd74: /* original 711f, guest PC 0x0c03fd74 */
if(!s->budget--) { s->failed_pc=0x0c03fd74u; return 0; }
r[1]+=0x0000001fu;
goto P_0c03fd76;
P_0c03fd76: /* original 6093, guest PC 0x0c03fd76 */
if(!s->budget--) { s->failed_pc=0x0c03fd76u; return 0; }
r[0]=r[9];
goto P_0c03fd78;
P_0c03fd78: /* original 0009, guest PC 0x0c03fd78 */
if(!s->budget--) { s->failed_pc=0x0c03fd78u; return 0; }
goto P_0c03fd7a;
P_0c03fd7a: /* original d311, guest PC 0x0c03fd7a */
if(!s->budget--) { s->failed_pc=0x0c03fd7au; return 0; }
r[3]=read(ram,0x0c03fdc0u,4);
goto P_0c03fd7c;
P_0c03fd7c: /* original 430b, guest PC 0x0c03fd7c */
if(!s->budget--) { s->failed_pc=0x0c03fd7cu; return 0; }
target=r[3];
r[16]=code_base|0x0c03fd80u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03fd80u) { target=s->pc; goto dispatch; }
goto P_0c03fd80;
P_0c03fd7e: /* original 0009, guest PC 0x0c03fd7e */
if(!s->budget--) { s->failed_pc=0x0c03fd7eu; return 0; }
goto P_0c03fd80;
P_0c03fd80: /* original 3503, guest PC 0x0c03fd80 */
if(!s->budget--) { s->failed_pc=0x0c03fd80u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[0])!=0);
goto P_0c03fd82;
P_0c03fd82: /* original 8bc5, guest PC 0x0c03fd82 */
if(!s->budget--) { s->failed_pc=0x0c03fd82u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fd10; }
goto P_0c03fd84;
P_0c03fd84: /* original e0ff, guest PC 0x0c03fd84 */
if(!s->budget--) { s->failed_pc=0x0c03fd84u; return 0; }
r[0]=0xffffffffu;
goto P_0c03fd86;
P_0c03fd86: /* original 4f26, guest PC 0x0c03fd86 */
if(!s->budget--) { s->failed_pc=0x0c03fd86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03fd88;
P_0c03fd88: /* original 68f6, guest PC 0x0c03fd88 */
if(!s->budget--) { s->failed_pc=0x0c03fd88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03fd8a;
P_0c03fd8a: /* original 69f6, guest PC 0x0c03fd8a */
if(!s->budget--) { s->failed_pc=0x0c03fd8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03fd8c;
P_0c03fd8c: /* original 6af6, guest PC 0x0c03fd8c */
if(!s->budget--) { s->failed_pc=0x0c03fd8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03fd8e;
P_0c03fd8e: /* original 6bf6, guest PC 0x0c03fd8e */
if(!s->budget--) { s->failed_pc=0x0c03fd8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03fd90;
P_0c03fd90: /* original 6df6, guest PC 0x0c03fd90 */
if(!s->budget--) { s->failed_pc=0x0c03fd90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03fd92;
P_0c03fd92: /* original 000b, guest PC 0x0c03fd92 */
if(!s->budget--) { s->failed_pc=0x0c03fd92u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03fd94: /* original 6ef6, guest PC 0x0c03fd94 */
if(!s->budget--) { s->failed_pc=0x0c03fd94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03fd96u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fd96u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
