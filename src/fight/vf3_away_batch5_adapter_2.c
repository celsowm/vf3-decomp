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
int vf3_away_batch5_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042edeu: goto P_0c042ede;
case 0x0c042ee0u: goto P_0c042ee0;
case 0x0c042ee2u: goto P_0c042ee2;
case 0x0c042ee4u: goto P_0c042ee4;
case 0x0c042ee6u: goto P_0c042ee6;
case 0x0c042ee8u: goto P_0c042ee8;
case 0x0c042eeau: goto P_0c042eea;
case 0x0c042eecu: goto P_0c042eec;
case 0x0c042eeeu: goto P_0c042eee;
case 0x0c042ef0u: goto P_0c042ef0;
case 0x0c042ef2u: goto P_0c042ef2;
case 0x0c043a7cu: goto P_0c043a7c;
case 0x0c043a7eu: goto P_0c043a7e;
case 0x0c043a80u: goto P_0c043a80;
case 0x0c043a82u: goto P_0c043a82;
case 0x0c043a84u: goto P_0c043a84;
case 0x0c043a86u: goto P_0c043a86;
case 0x0c043a88u: goto P_0c043a88;
case 0x0c043a8au: goto P_0c043a8a;
case 0x0c043a8cu: goto P_0c043a8c;
case 0x0c043a8eu: goto P_0c043a8e;
case 0x0c043a90u: goto P_0c043a90;
case 0x0c043a92u: goto P_0c043a92;
case 0x0c043a94u: goto P_0c043a94;
case 0x0c043a96u: goto P_0c043a96;
case 0x0c043a98u: goto P_0c043a98;
case 0x0c043a9au: goto P_0c043a9a;
case 0x0c043a9cu: goto P_0c043a9c;
case 0x0c043a9eu: goto P_0c043a9e;
case 0x0c043aa0u: goto P_0c043aa0;
case 0x0c043aa2u: goto P_0c043aa2;
case 0x0c043aa4u: goto P_0c043aa4;
case 0x0c043aa6u: goto P_0c043aa6;
case 0x0c043aa8u: goto P_0c043aa8;
case 0x0c043aaau: goto P_0c043aaa;
case 0x0c043aacu: goto P_0c043aac;
case 0x0c043aaeu: goto P_0c043aae;
case 0x0c043ab0u: goto P_0c043ab0;
case 0x0c043ab2u: goto P_0c043ab2;
case 0x0c043ab4u: goto P_0c043ab4;
case 0x0c043ab6u: goto P_0c043ab6;
case 0x0c043ab8u: goto P_0c043ab8;
case 0x0c043abau: goto P_0c043aba;
case 0x0c043abcu: goto P_0c043abc;
case 0x0c043d04u: goto P_0c043d04;
case 0x0c043d06u: goto P_0c043d06;
case 0x0c043d08u: goto P_0c043d08;
case 0x0c043d0au: goto P_0c043d0a;
case 0x0c043d0cu: goto P_0c043d0c;
case 0x0c043d0eu: goto P_0c043d0e;
case 0x0c043d10u: goto P_0c043d10;
case 0x0c043d12u: goto P_0c043d12;
case 0x0c043d14u: goto P_0c043d14;
case 0x0c043d16u: goto P_0c043d16;
case 0x0c043d18u: goto P_0c043d18;
case 0x0c043d1au: goto P_0c043d1a;
case 0x0c043d1cu: goto P_0c043d1c;
case 0x0c043d1eu: goto P_0c043d1e;
case 0x0c043d20u: goto P_0c043d20;
case 0x0c043d22u: goto P_0c043d22;
case 0x0c043d24u: goto P_0c043d24;
case 0x0c043d26u: goto P_0c043d26;
case 0x0c043d28u: goto P_0c043d28;
case 0x0c043d2au: goto P_0c043d2a;
case 0x0c043d2cu: goto P_0c043d2c;
case 0x0c043d2eu: goto P_0c043d2e;
case 0x0c043d30u: goto P_0c043d30;
case 0x0c043d32u: goto P_0c043d32;
case 0x0c043d34u: goto P_0c043d34;
case 0x0c043d36u: goto P_0c043d36;
case 0x0c043d38u: goto P_0c043d38;
case 0x0c043d3au: goto P_0c043d3a;
case 0x0c043d3cu: goto P_0c043d3c;
case 0x0c043d3eu: goto P_0c043d3e;
case 0x0c043d40u: goto P_0c043d40;
case 0x0c043d42u: goto P_0c043d42;
case 0x0c043d44u: goto P_0c043d44;
case 0x0c043d46u: goto P_0c043d46;
case 0x0c043d48u: goto P_0c043d48;
case 0x0c043d4au: goto P_0c043d4a;
case 0x0c043d4cu: goto P_0c043d4c;
case 0x0c043d4eu: goto P_0c043d4e;
case 0x0c043d50u: goto P_0c043d50;
case 0x0c043d52u: goto P_0c043d52;
case 0x0c043d54u: goto P_0c043d54;
case 0x0c043d56u: goto P_0c043d56;
case 0x0c043d58u: goto P_0c043d58;
case 0x0c043d5au: goto P_0c043d5a;
case 0x0c043d5cu: goto P_0c043d5c;
case 0x0c043d5eu: goto P_0c043d5e;
case 0x0c043d60u: goto P_0c043d60;
case 0x0c043d62u: goto P_0c043d62;
case 0x0c043d64u: goto P_0c043d64;
case 0x0c043d66u: goto P_0c043d66;
case 0x0c043d68u: goto P_0c043d68;
case 0x0c043d6au: goto P_0c043d6a;
case 0x0c043d6cu: goto P_0c043d6c;
case 0x0c043d6eu: goto P_0c043d6e;
case 0x0c043d70u: goto P_0c043d70;
case 0x0c043d72u: goto P_0c043d72;
case 0x0c043d74u: goto P_0c043d74;
case 0x0c043d76u: goto P_0c043d76;
case 0x0c043d78u: goto P_0c043d78;
case 0x0c043d7au: goto P_0c043d7a;
case 0x0c043d7cu: goto P_0c043d7c;
case 0x0c043d7eu: goto P_0c043d7e;
case 0x0c043db4u: goto P_0c043db4;
case 0x0c043db6u: goto P_0c043db6;
case 0x0c043db8u: goto P_0c043db8;
case 0x0c043dbau: goto P_0c043dba;
case 0x0c043dbcu: goto P_0c043dbc;
case 0x0c043dbeu: goto P_0c043dbe;
case 0x0c043dc0u: goto P_0c043dc0;
case 0x0c043dc2u: goto P_0c043dc2;
case 0x0c043dc4u: goto P_0c043dc4;
case 0x0c043dc6u: goto P_0c043dc6;
case 0x0c043dc8u: goto P_0c043dc8;
case 0x0c043dcau: goto P_0c043dca;
case 0x0c043dccu: goto P_0c043dcc;
case 0x0c043dceu: goto P_0c043dce;
case 0x0c043dd0u: goto P_0c043dd0;
case 0x0c043dd2u: goto P_0c043dd2;
case 0x0c043dd4u: goto P_0c043dd4;
case 0x0c043dd6u: goto P_0c043dd6;
case 0x0c043dd8u: goto P_0c043dd8;
case 0x0c043ddau: goto P_0c043dda;
case 0x0c043ddcu: goto P_0c043ddc;
case 0x0c043ddeu: goto P_0c043dde;
case 0x0c043de0u: goto P_0c043de0;
case 0x0c043de2u: goto P_0c043de2;
case 0x0c043de4u: goto P_0c043de4;
case 0x0c043de6u: goto P_0c043de6;
case 0x0c043de8u: goto P_0c043de8;
case 0x0c043deau: goto P_0c043dea;
case 0x0c043decu: goto P_0c043dec;
case 0x0c043deeu: goto P_0c043dee;
case 0x0c043df0u: goto P_0c043df0;
case 0x0c043df2u: goto P_0c043df2;
case 0x0c043df4u: goto P_0c043df4;
case 0x0c043df6u: goto P_0c043df6;
case 0x0c043df8u: goto P_0c043df8;
case 0x0c043dfau: goto P_0c043dfa;
case 0x0c043dfcu: goto P_0c043dfc;
case 0x0c043dfeu: goto P_0c043dfe;
case 0x0c043e00u: goto P_0c043e00;
case 0x0c043e02u: goto P_0c043e02;
case 0x0c043e04u: goto P_0c043e04;
case 0x0c043e06u: goto P_0c043e06;
case 0x0c043e08u: goto P_0c043e08;
case 0x0c043e0au: goto P_0c043e0a;
case 0x0c043e0cu: goto P_0c043e0c;
case 0x0c043e0eu: goto P_0c043e0e;
case 0x0c043e10u: goto P_0c043e10;
case 0x0c043e12u: goto P_0c043e12;
case 0x0c043e14u: goto P_0c043e14;
case 0x0c043e16u: goto P_0c043e16;
case 0x0c043e18u: goto P_0c043e18;
case 0x0c043e1au: goto P_0c043e1a;
case 0x0c043e1cu: goto P_0c043e1c;
case 0x0c043e1eu: goto P_0c043e1e;
case 0x0c043e20u: goto P_0c043e20;
case 0x0c043e22u: goto P_0c043e22;
case 0x0c043e24u: goto P_0c043e24;
case 0x0c043e26u: goto P_0c043e26;
case 0x0c043e28u: goto P_0c043e28;
case 0x0c043e2au: goto P_0c043e2a;
case 0x0c043e2cu: goto P_0c043e2c;
case 0x0c043e2eu: goto P_0c043e2e;
case 0x0c043e30u: goto P_0c043e30;
case 0x0c043e32u: goto P_0c043e32;
case 0x0c043e34u: goto P_0c043e34;
case 0x0c043e36u: goto P_0c043e36;
case 0x0c043e38u: goto P_0c043e38;
case 0x0c043e3au: goto P_0c043e3a;
case 0x0c043e3cu: goto P_0c043e3c;
case 0x0c043e3eu: goto P_0c043e3e;
case 0x0c043e40u: goto P_0c043e40;
case 0x0c043e42u: goto P_0c043e42;
case 0x0c043e44u: goto P_0c043e44;
case 0x0c043e46u: goto P_0c043e46;
case 0x0c043e48u: goto P_0c043e48;
case 0x0c043e4au: goto P_0c043e4a;
case 0x0c043e4cu: goto P_0c043e4c;
case 0x0c043e4eu: goto P_0c043e4e;
case 0x0c043e50u: goto P_0c043e50;
case 0x0c043eb8u: goto P_0c043eb8;
case 0x0c043ebau: goto P_0c043eba;
case 0x0c043ebcu: goto P_0c043ebc;
case 0x0c043ebeu: goto P_0c043ebe;
case 0x0c043ec0u: goto P_0c043ec0;
case 0x0c043ec2u: goto P_0c043ec2;
case 0x0c043ec4u: goto P_0c043ec4;
case 0x0c043ec6u: goto P_0c043ec6;
case 0x0c043ec8u: goto P_0c043ec8;
case 0x0c043ecau: goto P_0c043eca;
case 0x0c043eccu: goto P_0c043ecc;
case 0x0c043eceu: goto P_0c043ece;
case 0x0c043ed0u: goto P_0c043ed0;
case 0x0c043ed2u: goto P_0c043ed2;
case 0x0c043ed4u: goto P_0c043ed4;
case 0x0c043ed6u: goto P_0c043ed6;
case 0x0c043ed8u: goto P_0c043ed8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c042ede: /* original 303c, guest PC 0x0c042ede */
if(!s->budget--) { s->failed_pc=0x0c042edeu; return 0; }
r[0]+=r[3];
goto P_0c042ee0;
P_0c042ee0: /* original 64f6, guest PC 0x0c042ee0 */
if(!s->budget--) { s->failed_pc=0x0c042ee0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c042ee2;
P_0c042ee2: /* original 000b, guest PC 0x0c042ee2 */
if(!s->budget--) { s->failed_pc=0x0c042ee2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
s->pc=target; return ram->oob==0;
P_0c042ee4: /* original 63f6, guest PC 0x0c042ee4 */
if(!s->budget--) { s->failed_pc=0x0c042ee4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042ee6;
P_0c042ee6: /* original 2f26, guest PC 0x0c042ee6 */
if(!s->budget--) { s->failed_pc=0x0c042ee6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042ee8;
P_0c042ee8: /* original d102, guest PC 0x0c042ee8 */
if(!s->budget--) { s->failed_pc=0x0c042ee8u; return 0; }
r[1]=read(ram,0x0c042ef4u,4);
goto P_0c042eea;
P_0c042eea: /* original d203, guest PC 0x0c042eea */
if(!s->budget--) { s->failed_pc=0x0c042eeau; return 0; }
r[2]=read(ram,0x0c042ef8u,4);
goto P_0c042eec;
P_0c042eec: /* original e000, guest PC 0x0c042eec */
if(!s->budget--) { s->failed_pc=0x0c042eecu; return 0; }
r[0]=0x00000000u;
goto P_0c042eee;
P_0c042eee: /* original 2122, guest PC 0x0c042eee */
if(!s->budget--) { s->failed_pc=0x0c042eeeu; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042ef0;
P_0c042ef0: /* original 000b, guest PC 0x0c042ef0 */
if(!s->budget--) { s->failed_pc=0x0c042ef0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042ef2: /* original 62f6, guest PC 0x0c042ef2 */
if(!s->budget--) { s->failed_pc=0x0c042ef2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042ef4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042ef4u; return 0; } return 1;
P_0c043a7c: /* original d33e, guest PC 0x0c043a7c */
if(!s->budget--) { s->failed_pc=0x0c043a7cu; return 0; }
r[3]=read(ram,0x0c043b78u,4);
goto P_0c043a7e;
P_0c043a7e: /* original e600, guest PC 0x0c043a7e */
if(!s->budget--) { s->failed_pc=0x0c043a7eu; return 0; }
r[6]=0x00000000u;
goto P_0c043a80;
P_0c043a80: /* original d53c, guest PC 0x0c043a80 */
if(!s->budget--) { s->failed_pc=0x0c043a80u; return 0; }
r[5]=read(ram,0x0c043b74u,4);
goto P_0c043a82;
P_0c043a82: /* original e718, guest PC 0x0c043a82 */
if(!s->budget--) { s->failed_pc=0x0c043a82u; return 0; }
r[7]=0x00000018u;
goto P_0c043a84;
P_0c043a84: /* original 6432, guest PC 0x0c043a84 */
if(!s->budget--) { s->failed_pc=0x0c043a84u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c043a86;
P_0c043a86: /* original 7428, guest PC 0x0c043a86 */
if(!s->budget--) { s->failed_pc=0x0c043a86u; return 0; }
r[4]+=0x00000028u;
goto P_0c043a88;
P_0c043a88: /* original 6240, guest PC 0x0c043a88 */
if(!s->budget--) { s->failed_pc=0x0c043a88u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c043a8a;
P_0c043a8a: /* original 7601, guest PC 0x0c043a8a */
if(!s->budget--) { s->failed_pc=0x0c043a8au; return 0; }
r[6]+=0x00000001u;
goto P_0c043a8c;
P_0c043a8c: /* original 3673, guest PC 0x0c043a8c */
if(!s->budget--) { s->failed_pc=0x0c043a8cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c043a8e;
P_0c043a8e: /* original 2520, guest PC 0x0c043a8e */
if(!s->budget--) { s->failed_pc=0x0c043a8eu; return 0; }
write(ram,r[5],r[2],1);
goto P_0c043a90;
P_0c043a90: /* original 8441, guest PC 0x0c043a90 */
if(!s->budget--) { s->failed_pc=0x0c043a90u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c043a92;
P_0c043a92: /* original 8051, guest PC 0x0c043a92 */
if(!s->budget--) { s->failed_pc=0x0c043a92u; return 0; }
write(ram,r[5]+1,r[0],1);
goto P_0c043a94;
P_0c043a94: /* original 8442, guest PC 0x0c043a94 */
if(!s->budget--) { s->failed_pc=0x0c043a94u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c043a96;
P_0c043a96: /* original 8052, guest PC 0x0c043a96 */
if(!s->budget--) { s->failed_pc=0x0c043a96u; return 0; }
write(ram,r[5]+2,r[0],1);
goto P_0c043a98;
P_0c043a98: /* original 8443, guest PC 0x0c043a98 */
if(!s->budget--) { s->failed_pc=0x0c043a98u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c043a9a;
P_0c043a9a: /* original 8053, guest PC 0x0c043a9a */
if(!s->budget--) { s->failed_pc=0x0c043a9au; return 0; }
write(ram,r[5]+3,r[0],1);
goto P_0c043a9c;
P_0c043a9c: /* original 5344, guest PC 0x0c043a9c */
if(!s->budget--) { s->failed_pc=0x0c043a9cu; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c043a9e;
P_0c043a9e: /* original 1532, guest PC 0x0c043a9e */
if(!s->budget--) { s->failed_pc=0x0c043a9eu; return 0; }
write(ram,r[5]+8,r[3],4);
goto P_0c043aa0;
P_0c043aa0: /* original 8448, guest PC 0x0c043aa0 */
if(!s->budget--) { s->failed_pc=0x0c043aa0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c043aa2;
P_0c043aa2: /* original 8054, guest PC 0x0c043aa2 */
if(!s->budget--) { s->failed_pc=0x0c043aa2u; return 0; }
write(ram,r[5]+4,r[0],1);
goto P_0c043aa4;
P_0c043aa4: /* original 8449, guest PC 0x0c043aa4 */
if(!s->budget--) { s->failed_pc=0x0c043aa4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+9,1);
goto P_0c043aa6;
P_0c043aa6: /* original 8055, guest PC 0x0c043aa6 */
if(!s->budget--) { s->failed_pc=0x0c043aa6u; return 0; }
write(ram,r[5]+5,r[0],1);
goto P_0c043aa8;
P_0c043aa8: /* original 844a, guest PC 0x0c043aa8 */
if(!s->budget--) { s->failed_pc=0x0c043aa8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+10,1);
goto P_0c043aaa;
P_0c043aaa: /* original 8056, guest PC 0x0c043aaa */
if(!s->budget--) { s->failed_pc=0x0c043aaau; return 0; }
write(ram,r[5]+6,r[0],1);
goto P_0c043aac;
P_0c043aac: /* original 844b, guest PC 0x0c043aac */
if(!s->budget--) { s->failed_pc=0x0c043aacu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+11,1);
goto P_0c043aae;
P_0c043aae: /* original 8057, guest PC 0x0c043aae */
if(!s->budget--) { s->failed_pc=0x0c043aaeu; return 0; }
write(ram,r[5]+7,r[0],1);
goto P_0c043ab0;
P_0c043ab0: /* original 5345, guest PC 0x0c043ab0 */
if(!s->budget--) { s->failed_pc=0x0c043ab0u; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c043ab2;
P_0c043ab2: /* original 1533, guest PC 0x0c043ab2 */
if(!s->budget--) { s->failed_pc=0x0c043ab2u; return 0; }
write(ram,r[5]+12,r[3],4);
goto P_0c043ab4;
P_0c043ab4: /* original 7518, guest PC 0x0c043ab4 */
if(!s->budget--) { s->failed_pc=0x0c043ab4u; return 0; }
r[5]+=0x00000018u;
goto P_0c043ab6;
P_0c043ab6: /* original 8fe7, guest PC 0x0c043ab6 */
if(!s->budget--) { s->failed_pc=0x0c043ab6u; return 0; }
cond=r[17]&1u;
r[4]+=0x0000002cu;
if(!cond) { goto P_0c043a88; }
goto P_0c043aba;
P_0c043ab8: /* original 742c, guest PC 0x0c043ab8 */
if(!s->budget--) { s->failed_pc=0x0c043ab8u; return 0; }
r[4]+=0x0000002cu;
goto P_0c043aba;
P_0c043aba: /* original 000b, guest PC 0x0c043aba */
if(!s->budget--) { s->failed_pc=0x0c043abau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c043abc: /* original 0009, guest PC 0x0c043abc */
if(!s->budget--) { s->failed_pc=0x0c043abcu; return 0; }
if(!vf3_matrix_family(0x0c043abeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c043abeu; return 0; } return 1;
P_0c043d04: /* original 2fe6, guest PC 0x0c043d04 */
if(!s->budget--) { s->failed_pc=0x0c043d04u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043d06;
P_0c043d06: /* original e301, guest PC 0x0c043d06 */
if(!s->budget--) { s->failed_pc=0x0c043d06u; return 0; }
r[3]=0x00000001u;
goto P_0c043d08;
P_0c043d08: /* original 2fd6, guest PC 0x0c043d08 */
if(!s->budget--) { s->failed_pc=0x0c043d08u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043d0a;
P_0c043d0a: /* original 2fc6, guest PC 0x0c043d0a */
if(!s->budget--) { s->failed_pc=0x0c043d0au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043d0c;
P_0c043d0c: /* original 2fb6, guest PC 0x0c043d0c */
if(!s->budget--) { s->failed_pc=0x0c043d0cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043d0e;
P_0c043d0e: /* original 2fa6, guest PC 0x0c043d0e */
if(!s->budget--) { s->failed_pc=0x0c043d0eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043d10;
P_0c043d10: /* original 2f96, guest PC 0x0c043d10 */
if(!s->budget--) { s->failed_pc=0x0c043d10u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043d12;
P_0c043d12: /* original 2f86, guest PC 0x0c043d12 */
if(!s->budget--) { s->failed_pc=0x0c043d12u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043d14;
P_0c043d14: /* original 4f22, guest PC 0x0c043d14 */
if(!s->budget--) { s->failed_pc=0x0c043d14u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043d16;
P_0c043d16: /* original d11f, guest PC 0x0c043d16 */
if(!s->budget--) { s->failed_pc=0x0c043d16u; return 0; }
r[1]=read(ram,0x0c043d94u,4);
goto P_0c043d18;
P_0c043d18: /* original d21d, guest PC 0x0c043d18 */
if(!s->budget--) { s->failed_pc=0x0c043d18u; return 0; }
r[2]=read(ram,0x0c043d90u,4);
goto P_0c043d1a;
P_0c043d1a: /* original 4f12, guest PC 0x0c043d1a */
if(!s->budget--) { s->failed_pc=0x0c043d1au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c043d1c;
P_0c043d1c: /* original 410b, guest PC 0x0c043d1c */
if(!s->budget--) { s->failed_pc=0x0c043d1cu; return 0; }
target=r[1];
r[16]=code_base|0x0c043d20u;
write(ram,r[2],r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043d20u) { target=s->pc; goto dispatch; }
goto P_0c043d20;
P_0c043d1e: /* original 2232, guest PC 0x0c043d1e */
if(!s->budget--) { s->failed_pc=0x0c043d1eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c043d20;
P_0c043d20: /* original 88fe, guest PC 0x0c043d20 */
if(!s->budget--) { s->failed_pc=0x0c043d20u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c043d22;
P_0c043d22: /* original 8f07, guest PC 0x0c043d22 */
if(!s->budget--) { s->failed_pc=0x0c043d22u; return 0; }
cond=r[17]&1u;
r[10]=r[0];
if(!cond) { goto P_0c043d34; }
goto P_0c043d26;
P_0c043d24: /* original 6a03, guest PC 0x0c043d24 */
if(!s->budget--) { s->failed_pc=0x0c043d24u; return 0; }
r[10]=r[0];
goto P_0c043d26;
P_0c043d26: /* original d31c, guest PC 0x0c043d26 */
if(!s->budget--) { s->failed_pc=0x0c043d26u; return 0; }
r[3]=read(ram,0x0c043d98u,4);
goto P_0c043d28;
P_0c043d28: /* original e101, guest PC 0x0c043d28 */
if(!s->budget--) { s->failed_pc=0x0c043d28u; return 0; }
r[1]=0x00000001u;
goto P_0c043d2a;
P_0c043d2a: /* original 902a, guest PC 0x0c043d2a */
if(!s->budget--) { s->failed_pc=0x0c043d2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043d82u,2);
goto P_0c043d2c;
P_0c043d2c: /* original 6232, guest PC 0x0c043d2c */
if(!s->budget--) { s->failed_pc=0x0c043d2cu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c043d2e;
P_0c043d2e: /* original 0216, guest PC 0x0c043d2e */
if(!s->budget--) { s->failed_pc=0x0c043d2eu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c043d30;
P_0c043d30: /* original a084, guest PC 0x0c043d30 */
if(!s->budget--) { s->failed_pc=0x0c043d30u; return 0; }
goto P_0c043e3c;
P_0c043d32: /* original 0009, guest PC 0x0c043d32 */
if(!s->budget--) { s->failed_pc=0x0c043d32u; return 0; }
goto P_0c043d34;
P_0c043d34: /* original d819, guest PC 0x0c043d34 */
if(!s->budget--) { s->failed_pc=0x0c043d34u; return 0; }
r[8]=read(ram,0x0c043d9cu,4);
goto P_0c043d36;
P_0c043d36: /* original 4a11, guest PC 0x0c043d36 */
if(!s->budget--) { s->failed_pc=0x0c043d36u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=0)!=0);
goto P_0c043d38;
P_0c043d38: /* original 8f75, guest PC 0x0c043d38 */
if(!s->budget--) { s->failed_pc=0x0c043d38u; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(!cond) { goto P_0c043e26; }
goto P_0c043d3c;
P_0c043d3a: /* original ec00, guest PC 0x0c043d3a */
if(!s->budget--) { s->failed_pc=0x0c043d3au; return 0; }
r[12]=0x00000000u;
goto P_0c043d3c;
P_0c043d3c: /* original d218, guest PC 0x0c043d3c */
if(!s->budget--) { s->failed_pc=0x0c043d3cu; return 0; }
r[2]=read(ram,0x0c043da0u,4);
goto P_0c043d3e;
P_0c043d3e: /* original 420b, guest PC 0x0c043d3e */
if(!s->budget--) { s->failed_pc=0x0c043d3eu; return 0; }
target=r[2];
r[16]=code_base|0x0c043d42u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043d42u) { target=s->pc; goto dispatch; }
goto P_0c043d42;
P_0c043d40: /* original 0009, guest PC 0x0c043d40 */
if(!s->budget--) { s->failed_pc=0x0c043d40u; return 0; }
goto P_0c043d42;
P_0c043d42: /* original d311, guest PC 0x0c043d42 */
if(!s->budget--) { s->failed_pc=0x0c043d42u; return 0; }
r[3]=read(ram,0x0c043d88u,4);
goto P_0c043d44;
P_0c043d44: /* original 6283, guest PC 0x0c043d44 */
if(!s->budget--) { s->failed_pc=0x0c043d44u; return 0; }
r[2]=r[8];
goto P_0c043d46;
P_0c043d46: /* original 7230, guest PC 0x0c043d46 */
if(!s->budget--) { s->failed_pc=0x0c043d46u; return 0; }
r[2]+=0x00000030u;
goto P_0c043d48;
P_0c043d48: /* original 951a, guest PC 0x0c043d48 */
if(!s->budget--) { s->failed_pc=0x0c043d48u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043d80u,2);
goto P_0c043d4a;
P_0c043d4a: /* original 6432, guest PC 0x0c043d4a */
if(!s->budget--) { s->failed_pc=0x0c043d4au; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c043d4c;
P_0c043d4c: /* original 4400, guest PC 0x0c043d4c */
if(!s->budget--) { s->failed_pc=0x0c043d4cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c043d4e;
P_0c043d4e: /* original 324c, guest PC 0x0c043d4e */
if(!s->budget--) { s->failed_pc=0x0c043d4eu; return 0; }
r[2]+=r[4];
goto P_0c043d50;
P_0c043d50: /* original 2f26, guest PC 0x0c043d50 */
if(!s->budget--) { s->failed_pc=0x0c043d50u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043d52;
P_0c043d52: /* original d00e, guest PC 0x0c043d52 */
if(!s->budget--) { s->failed_pc=0x0c043d52u; return 0; }
r[0]=read(ram,0x0c043d8cu,4);
goto P_0c043d54;
P_0c043d54: /* original 6102, guest PC 0x0c043d54 */
if(!s->budget--) { s->failed_pc=0x0c043d54u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c043d56;
P_0c043d56: /* original 6383, guest PC 0x0c043d56 */
if(!s->budget--) { s->failed_pc=0x0c043d56u; return 0; }
r[3]=r[8];
goto P_0c043d58;
P_0c043d58: /* original d212, guest PC 0x0c043d58 */
if(!s->budget--) { s->failed_pc=0x0c043d58u; return 0; }
r[2]=read(ram,0x0c043da4u,4);
goto P_0c043d5a;
P_0c043d5a: /* original 7334, guest PC 0x0c043d5a */
if(!s->budget--) { s->failed_pc=0x0c043d5au; return 0; }
r[3]+=0x00000034u;
goto P_0c043d5c;
P_0c043d5c: /* original 2159, guest PC 0x0c043d5c */
if(!s->budget--) { s->failed_pc=0x0c043d5cu; return 0; }
r[1]&=r[5];
goto P_0c043d5e;
P_0c043d5e: /* original 334c, guest PC 0x0c043d5e */
if(!s->budget--) { s->failed_pc=0x0c043d5eu; return 0; }
r[3]+=r[4];
goto P_0c043d60;
P_0c043d60: /* original 6022, guest PC 0x0c043d60 */
if(!s->budget--) { s->failed_pc=0x0c043d60u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c043d62;
P_0c043d62: /* original 6331, guest PC 0x0c043d62 */
if(!s->budget--) { s->failed_pc=0x0c043d62u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c043d64;
P_0c043d64: /* original 2059, guest PC 0x0c043d64 */
if(!s->budget--) { s->failed_pc=0x0c043d64u; return 0; }
r[0]&=r[5];
goto P_0c043d66;
P_0c043d66: /* original 230e, guest PC 0x0c043d66 */
if(!s->budget--) { s->failed_pc=0x0c043d66u; return 0; }
r[19]=(r[3]&65535u)*(r[0]&65535u);
goto P_0c043d68;
P_0c043d68: /* original 001a, guest PC 0x0c043d68 */
if(!s->budget--) { s->failed_pc=0x0c043d68u; return 0; }
r[0]=r[19];
goto P_0c043d6a;
P_0c043d6a: /* original 310c, guest PC 0x0c043d6a */
if(!s->budget--) { s->failed_pc=0x0c043d6au; return 0; }
r[1]+=r[0];
goto P_0c043d6c;
P_0c043d6c: /* original 60f6, guest PC 0x0c043d6c */
if(!s->budget--) { s->failed_pc=0x0c043d6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[0]=tmp;
goto P_0c043d6e;
P_0c043d6e: /* original be85, guest PC 0x0c043d6e */
if(!s->budget--) { s->failed_pc=0x0c043d6eu; return 0; }
target=code_base|0x0c043a7cu; r[16]=code_base|0x0c043d72u;
write(ram,r[0],r[1],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043d72u) { target=s->pc; goto dispatch; }
goto P_0c043d72;
P_0c043d70: /* original 2011, guest PC 0x0c043d70 */
if(!s->budget--) { s->failed_pc=0x0c043d70u; return 0; }
write(ram,r[0],r[1],2);
goto P_0c043d72;
P_0c043d72: /* original d20d, guest PC 0x0c043d72 */
if(!s->budget--) { s->failed_pc=0x0c043d72u; return 0; }
r[2]=read(ram,0x0c043da8u,4);
goto P_0c043d74;
P_0c043d74: /* original 420b, guest PC 0x0c043d74 */
if(!s->budget--) { s->failed_pc=0x0c043d74u; return 0; }
target=r[2];
r[16]=code_base|0x0c043d78u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043d78u) { target=s->pc; goto dispatch; }
goto P_0c043d78;
P_0c043d76: /* original 0009, guest PC 0x0c043d76 */
if(!s->budget--) { s->failed_pc=0x0c043d76u; return 0; }
goto P_0c043d78;
P_0c043d78: /* original dd0d, guest PC 0x0c043d78 */
if(!s->budget--) { s->failed_pc=0x0c043d78u; return 0; }
r[13]=read(ram,0x0c043db0u,4);
goto P_0c043d7a;
P_0c043d7a: /* original de0c, guest PC 0x0c043d7a */
if(!s->budget--) { s->failed_pc=0x0c043d7au; return 0; }
r[14]=read(ram,0x0c043dacu,4);
goto P_0c043d7c;
P_0c043d7c: /* original a044, guest PC 0x0c043d7c */
if(!s->budget--) { s->failed_pc=0x0c043d7cu; return 0; }
r[11]=r[12];
goto P_0c043e08;
P_0c043d7e: /* original 6bc3, guest PC 0x0c043d7e */
if(!s->budget--) { s->failed_pc=0x0c043d7eu; return 0; }
r[11]=r[12];
if(!vf3_matrix_family(0x0c043d80u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c043d80u; return 0; } return 1;
P_0c043db4: /* original 52e2, guest PC 0x0c043db4 */
if(!s->budget--) { s->failed_pc=0x0c043db4u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c043db6;
P_0c043db6: /* original 2228, guest PC 0x0c043db6 */
if(!s->budget--) { s->failed_pc=0x0c043db6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c043db8;
P_0c043db8: /* original 8924, guest PC 0x0c043db8 */
if(!s->budget--) { s->failed_pc=0x0c043db8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043e04; }
goto P_0c043dba;
P_0c043dba: /* original d44f, guest PC 0x0c043dba */
if(!s->budget--) { s->failed_pc=0x0c043dbau; return 0; }
r[4]=read(ram,0x0c043ef8u,4);
goto P_0c043dbc;
P_0c043dbc: /* original 56e2, guest PC 0x0c043dbc */
if(!s->budget--) { s->failed_pc=0x0c043dbcu; return 0; }
r[6]=read(ram,r[14]+8,4);
goto P_0c043dbe;
P_0c043dbe: /* original 4d0b, guest PC 0x0c043dbe */
if(!s->budget--) { s->failed_pc=0x0c043dbeu; return 0; }
target=r[13];
r[16]=code_base|0x0c043dc2u;
r[5]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043dc2u) { target=s->pc; goto dispatch; }
goto P_0c043dc2;
P_0c043dc0: /* original 65b3, guest PC 0x0c043dc0 */
if(!s->budget--) { s->failed_pc=0x0c043dc0u; return 0; }
r[5]=r[11];
goto P_0c043dc2;
P_0c043dc2: /* original d44e, guest PC 0x0c043dc2 */
if(!s->budget--) { s->failed_pc=0x0c043dc2u; return 0; }
r[4]=read(ram,0x0c043efcu,4);
goto P_0c043dc4;
P_0c043dc4: /* original 56e1, guest PC 0x0c043dc4 */
if(!s->budget--) { s->failed_pc=0x0c043dc4u; return 0; }
r[6]=read(ram,r[14]+4,4);
goto P_0c043dc6;
P_0c043dc6: /* original 4d0b, guest PC 0x0c043dc6 */
if(!s->budget--) { s->failed_pc=0x0c043dc6u; return 0; }
target=r[13];
r[16]=code_base|0x0c043dcau;
tmp=read(ram,r[14],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043dcau) { target=s->pc; goto dispatch; }
goto P_0c043dca;
P_0c043dc8: /* original 65e2, guest PC 0x0c043dc8 */
if(!s->budget--) { s->failed_pc=0x0c043dc8u; return 0; }
tmp=read(ram,r[14],4);
r[5]=tmp;
goto P_0c043dca;
P_0c043dca: /* original 55e1, guest PC 0x0c043dca */
if(!s->budget--) { s->failed_pc=0x0c043dcau; return 0; }
r[5]=read(ram,r[14]+4,4);
goto P_0c043dcc;
P_0c043dcc: /* original b08c, guest PC 0x0c043dcc */
if(!s->budget--) { s->failed_pc=0x0c043dccu; return 0; }
target=code_base|0x0c043ee8u; r[16]=code_base|0x0c043dd0u;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043dd0u) { target=s->pc; goto dispatch; }
goto P_0c043dd0;
P_0c043dce: /* original 64e2, guest PC 0x0c043dce */
if(!s->budget--) { s->failed_pc=0x0c043dceu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c043dd0;
P_0c043dd0: /* original 2008, guest PC 0x0c043dd0 */
if(!s->budget--) { s->failed_pc=0x0c043dd0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c043dd2;
P_0c043dd2: /* original 8917, guest PC 0x0c043dd2 */
if(!s->budget--) { s->failed_pc=0x0c043dd2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043e04; }
goto P_0c043dd4;
P_0c043dd4: /* original 59e2, guest PC 0x0c043dd4 */
if(!s->budget--) { s->failed_pc=0x0c043dd4u; return 0; }
r[9]=read(ram,r[14]+8,4);
goto P_0c043dd6;
P_0c043dd6: /* original 1ec2, guest PC 0x0c043dd6 */
if(!s->budget--) { s->failed_pc=0x0c043dd6u; return 0; }
write(ram,r[14]+8,r[12],4);
goto P_0c043dd8;
P_0c043dd8: /* original b078, guest PC 0x0c043dd8 */
if(!s->budget--) { s->failed_pc=0x0c043dd8u; return 0; }
target=code_base|0x0c043eccu; r[16]=code_base|0x0c043ddcu;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043ddcu) { target=s->pc; goto dispatch; }
goto P_0c043ddc;
P_0c043dda: /* original 64e2, guest PC 0x0c043dda */
if(!s->budget--) { s->failed_pc=0x0c043ddau; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c043ddc;
P_0c043ddc: /* original 2f06, guest PC 0x0c043ddc */
if(!s->budget--) { s->failed_pc=0x0c043ddcu; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043dde;
P_0c043dde: /* original b06b, guest PC 0x0c043dde */
if(!s->budget--) { s->failed_pc=0x0c043ddeu; return 0; }
target=code_base|0x0c043eb8u; r[16]=code_base|0x0c043de2u;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043de2u) { target=s->pc; goto dispatch; }
goto P_0c043de2;
P_0c043de0: /* original 64e2, guest PC 0x0c043de0 */
if(!s->budget--) { s->failed_pc=0x0c043de0u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c043de2;
P_0c043de2: /* original 2f06, guest PC 0x0c043de2 */
if(!s->budget--) { s->failed_pc=0x0c043de2u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043de4;
P_0c043de4: /* original 66e2, guest PC 0x0c043de4 */
if(!s->budget--) { s->failed_pc=0x0c043de4u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c043de6;
P_0c043de6: /* original d446, guest PC 0x0c043de6 */
if(!s->budget--) { s->failed_pc=0x0c043de6u; return 0; }
r[4]=read(ram,0x0c043f00u,4);
goto P_0c043de8;
P_0c043de8: /* original 57e1, guest PC 0x0c043de8 */
if(!s->budget--) { s->failed_pc=0x0c043de8u; return 0; }
r[7]=read(ram,r[14]+4,4);
goto P_0c043dea;
P_0c043dea: /* original 4d0b, guest PC 0x0c043dea */
if(!s->budget--) { s->failed_pc=0x0c043deau; return 0; }
target=r[13];
r[16]=code_base|0x0c043deeu;
r[5]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043deeu) { target=s->pc; goto dispatch; }
goto P_0c043dee;
P_0c043dec: /* original 6593, guest PC 0x0c043dec */
if(!s->budget--) { s->failed_pc=0x0c043decu; return 0; }
r[5]=r[9];
goto P_0c043dee;
P_0c043dee: /* original 7f08, guest PC 0x0c043dee */
if(!s->budget--) { s->failed_pc=0x0c043deeu; return 0; }
r[15]+=0x00000008u;
goto P_0c043df0;
P_0c043df0: /* original b06c, guest PC 0x0c043df0 */
if(!s->budget--) { s->failed_pc=0x0c043df0u; return 0; }
target=code_base|0x0c043eccu; r[16]=code_base|0x0c043df4u;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043df4u) { target=s->pc; goto dispatch; }
goto P_0c043df4;
P_0c043df2: /* original 64e2, guest PC 0x0c043df2 */
if(!s->budget--) { s->failed_pc=0x0c043df2u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c043df4;
P_0c043df4: /* original 2f06, guest PC 0x0c043df4 */
if(!s->budget--) { s->failed_pc=0x0c043df4u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043df6;
P_0c043df6: /* original b05f, guest PC 0x0c043df6 */
if(!s->budget--) { s->failed_pc=0x0c043df6u; return 0; }
target=code_base|0x0c043eb8u; r[16]=code_base|0x0c043dfau;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043dfau) { target=s->pc; goto dispatch; }
goto P_0c043dfa;
P_0c043df8: /* original 64e2, guest PC 0x0c043df8 */
if(!s->budget--) { s->failed_pc=0x0c043df8u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c043dfa;
P_0c043dfa: /* original 64e2, guest PC 0x0c043dfa */
if(!s->budget--) { s->failed_pc=0x0c043dfau; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c043dfc;
P_0c043dfc: /* original 6603, guest PC 0x0c043dfc */
if(!s->budget--) { s->failed_pc=0x0c043dfcu; return 0; }
r[6]=r[0];
goto P_0c043dfe;
P_0c043dfe: /* original 55e1, guest PC 0x0c043dfe */
if(!s->budget--) { s->failed_pc=0x0c043dfeu; return 0; }
r[5]=read(ram,r[14]+4,4);
goto P_0c043e00;
P_0c043e00: /* original 490b, guest PC 0x0c043e00 */
if(!s->budget--) { s->failed_pc=0x0c043e00u; return 0; }
target=r[9];
r[16]=code_base|0x0c043e04u;
tmp=read(ram,r[15],4);
r[15]+=4;
r[7]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043e04u) { target=s->pc; goto dispatch; }
goto P_0c043e04;
P_0c043e02: /* original 67f6, guest PC 0x0c043e02 */
if(!s->budget--) { s->failed_pc=0x0c043e02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[7]=tmp;
goto P_0c043e04;
P_0c043e04: /* original 7e0c, guest PC 0x0c043e04 */
if(!s->budget--) { s->failed_pc=0x0c043e04u; return 0; }
r[14]+=0x0000000cu;
goto P_0c043e06;
P_0c043e06: /* original 7b01, guest PC 0x0c043e06 */
if(!s->budget--) { s->failed_pc=0x0c043e06u; return 0; }
r[11]+=0x00000001u;
goto P_0c043e08;
P_0c043e08: /* original e330, guest PC 0x0c043e08 */
if(!s->budget--) { s->failed_pc=0x0c043e08u; return 0; }
r[3]=0x00000030u;
goto P_0c043e0a;
P_0c043e0a: /* original 3b33, guest PC 0x0c043e0a */
if(!s->budget--) { s->failed_pc=0x0c043e0au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[3])!=0);
goto P_0c043e0c;
P_0c043e0c: /* original 8bd2, guest PC 0x0c043e0c */
if(!s->budget--) { s->failed_pc=0x0c043e0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043db4; }
goto P_0c043e0e;
P_0c043e0e: /* original d23d, guest PC 0x0c043e0e */
if(!s->budget--) { s->failed_pc=0x0c043e0eu; return 0; }
r[2]=read(ram,0x0c043f04u,4);
goto P_0c043e10;
P_0c043e10: /* original 906d, guest PC 0x0c043e10 */
if(!s->budget--) { s->failed_pc=0x0c043e10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043eeeu,2);
goto P_0c043e12;
P_0c043e12: /* original 6122, guest PC 0x0c043e12 */
if(!s->budget--) { s->failed_pc=0x0c043e12u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c043e14;
P_0c043e14: /* original 01c6, guest PC 0x0c043e14 */
if(!s->budget--) { s->failed_pc=0x0c043e14u; return 0; }
write(ram,r[1]+r[0],r[12],4);
goto P_0c043e16;
P_0c043e16: /* original d33c, guest PC 0x0c043e16 */
if(!s->budget--) { s->failed_pc=0x0c043e16u; return 0; }
r[3]=read(ram,0x0c043f08u,4);
goto P_0c043e18;
P_0c043e18: /* original 6032, guest PC 0x0c043e18 */
if(!s->budget--) { s->failed_pc=0x0c043e18u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c043e1a;
P_0c043e1a: /* original ca01, guest PC 0x0c043e1a */
if(!s->budget--) { s->failed_pc=0x0c043e1au; return 0; }
r[0]^=1u;
goto P_0c043e1c;
P_0c043e1c: /* original 2302, guest PC 0x0c043e1c */
if(!s->budget--) { s->failed_pc=0x0c043e1cu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c043e1e;
P_0c043e1e: /* original 5181, guest PC 0x0c043e1e */
if(!s->budget--) { s->failed_pc=0x0c043e1eu; return 0; }
r[1]=read(ram,r[8]+4,4);
goto P_0c043e20;
P_0c043e20: /* original 7101, guest PC 0x0c043e20 */
if(!s->budget--) { s->failed_pc=0x0c043e20u; return 0; }
r[1]+=0x00000001u;
goto P_0c043e22;
P_0c043e22: /* original a009, guest PC 0x0c043e22 */
if(!s->budget--) { s->failed_pc=0x0c043e22u; return 0; }
write(ram,r[8]+4,r[1],4);
goto P_0c043e38;
P_0c043e24: /* original 1811, guest PC 0x0c043e24 */
if(!s->budget--) { s->failed_pc=0x0c043e24u; return 0; }
write(ram,r[8]+4,r[1],4);
goto P_0c043e26;
P_0c043e26: /* original d239, guest PC 0x0c043e26 */
if(!s->budget--) { s->failed_pc=0x0c043e26u; return 0; }
r[2]=read(ram,0x0c043f0cu,4);
goto P_0c043e28;
P_0c043e28: /* original 6e22, guest PC 0x0c043e28 */
if(!s->budget--) { s->failed_pc=0x0c043e28u; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c043e2a;
P_0c043e2a: /* original 2ee8, guest PC 0x0c043e2a */
if(!s->budget--) { s->failed_pc=0x0c043e2au; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c043e2c;
P_0c043e2c: /* original 8904, guest PC 0x0c043e2c */
if(!s->budget--) { s->failed_pc=0x0c043e2cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043e38; }
goto P_0c043e2e;
P_0c043e2e: /* original 5682, guest PC 0x0c043e2e */
if(!s->budget--) { s->failed_pc=0x0c043e2eu; return 0; }
r[6]=read(ram,r[8]+8,4);
goto P_0c043e30;
P_0c043e30: /* original e5f8, guest PC 0x0c043e30 */
if(!s->budget--) { s->failed_pc=0x0c043e30u; return 0; }
r[5]=0xfffffff8u;
goto P_0c043e32;
P_0c043e32: /* original 67a3, guest PC 0x0c043e32 */
if(!s->budget--) { s->failed_pc=0x0c043e32u; return 0; }
r[7]=r[10];
goto P_0c043e34;
P_0c043e34: /* original 4e0b, guest PC 0x0c043e34 */
if(!s->budget--) { s->failed_pc=0x0c043e34u; return 0; }
target=r[14];
r[16]=code_base|0x0c043e38u;
r[4]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043e38u) { target=s->pc; goto dispatch; }
goto P_0c043e38;
P_0c043e36: /* original e402, guest PC 0x0c043e36 */
if(!s->budget--) { s->failed_pc=0x0c043e36u; return 0; }
r[4]=0x00000002u;
goto P_0c043e38;
P_0c043e38: /* original d235, guest PC 0x0c043e38 */
if(!s->budget--) { s->failed_pc=0x0c043e38u; return 0; }
r[2]=read(ram,0x0c043f10u,4);
goto P_0c043e3a;
P_0c043e3a: /* original 22c2, guest PC 0x0c043e3a */
if(!s->budget--) { s->failed_pc=0x0c043e3au; return 0; }
write(ram,r[2],r[12],4);
goto P_0c043e3c;
P_0c043e3c: /* original 4f16, guest PC 0x0c043e3c */
if(!s->budget--) { s->failed_pc=0x0c043e3cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c043e3e;
P_0c043e3e: /* original 60a3, guest PC 0x0c043e3e */
if(!s->budget--) { s->failed_pc=0x0c043e3eu; return 0; }
r[0]=r[10];
goto P_0c043e40;
P_0c043e40: /* original 4f26, guest PC 0x0c043e40 */
if(!s->budget--) { s->failed_pc=0x0c043e40u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043e42;
P_0c043e42: /* original 68f6, guest PC 0x0c043e42 */
if(!s->budget--) { s->failed_pc=0x0c043e42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c043e44;
P_0c043e44: /* original 69f6, guest PC 0x0c043e44 */
if(!s->budget--) { s->failed_pc=0x0c043e44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c043e46;
P_0c043e46: /* original 6af6, guest PC 0x0c043e46 */
if(!s->budget--) { s->failed_pc=0x0c043e46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c043e48;
P_0c043e48: /* original 6bf6, guest PC 0x0c043e48 */
if(!s->budget--) { s->failed_pc=0x0c043e48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c043e4a;
P_0c043e4a: /* original 6cf6, guest PC 0x0c043e4a */
if(!s->budget--) { s->failed_pc=0x0c043e4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c043e4c;
P_0c043e4c: /* original 6df6, guest PC 0x0c043e4c */
if(!s->budget--) { s->failed_pc=0x0c043e4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c043e4e;
P_0c043e4e: /* original 000b, guest PC 0x0c043e4e */
if(!s->budget--) { s->failed_pc=0x0c043e4eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c043e50: /* original 6ef6, guest PC 0x0c043e50 */
if(!s->budget--) { s->failed_pc=0x0c043e50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c043e52u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c043e52u; return 0; } return 1;
P_0c043eb8: /* original 6043, guest PC 0x0c043eb8 */
if(!s->budget--) { s->failed_pc=0x0c043eb8u; return 0; }
r[0]=r[4];
goto P_0c043eba;
P_0c043eba: /* original 4000, guest PC 0x0c043eba */
if(!s->budget--) { s->failed_pc=0x0c043ebau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c043ebc;
P_0c043ebc: /* original 6343, guest PC 0x0c043ebc */
if(!s->budget--) { s->failed_pc=0x0c043ebcu; return 0; }
r[3]=r[4];
goto P_0c043ebe;
P_0c043ebe: /* original 303c, guest PC 0x0c043ebe */
if(!s->budget--) { s->failed_pc=0x0c043ebeu; return 0; }
r[0]+=r[3];
goto P_0c043ec0;
P_0c043ec0: /* original 4008, guest PC 0x0c043ec0 */
if(!s->budget--) { s->failed_pc=0x0c043ec0u; return 0; }
r[0]<<=2;
goto P_0c043ec2;
P_0c043ec2: /* original d218, guest PC 0x0c043ec2 */
if(!s->budget--) { s->failed_pc=0x0c043ec2u; return 0; }
r[2]=read(ram,0x0c043f24u,4);
goto P_0c043ec4;
P_0c043ec4: /* original 4000, guest PC 0x0c043ec4 */
if(!s->budget--) { s->failed_pc=0x0c043ec4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c043ec6;
P_0c043ec6: /* original 600f, guest PC 0x0c043ec6 */
if(!s->budget--) { s->failed_pc=0x0c043ec6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c043ec8;
P_0c043ec8: /* original 000b, guest PC 0x0c043ec8 */
if(!s->budget--) { s->failed_pc=0x0c043ec8u; return 0; }
target=r[16];
r[0]+=r[2];
s->pc=target; return ram->oob==0;
P_0c043eca: /* original 302c, guest PC 0x0c043eca */
if(!s->budget--) { s->failed_pc=0x0c043ecau; return 0; }
r[0]+=r[2];
goto P_0c043ecc;
P_0c043ecc: /* original 4f22, guest PC 0x0c043ecc */
if(!s->budget--) { s->failed_pc=0x0c043eccu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043ece;
P_0c043ece: /* original d317, guest PC 0x0c043ece */
if(!s->budget--) { s->failed_pc=0x0c043eceu; return 0; }
r[3]=read(ram,0x0c043f2cu,4);
goto P_0c043ed0;
P_0c043ed0: /* original 430b, guest PC 0x0c043ed0 */
if(!s->budget--) { s->failed_pc=0x0c043ed0u; return 0; }
target=r[3];
r[16]=code_base|0x0c043ed4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043ed4u) { target=s->pc; goto dispatch; }
goto P_0c043ed4;
P_0c043ed2: /* original 0009, guest PC 0x0c043ed2 */
if(!s->budget--) { s->failed_pc=0x0c043ed2u; return 0; }
goto P_0c043ed4;
P_0c043ed4: /* original 4f26, guest PC 0x0c043ed4 */
if(!s->budget--) { s->failed_pc=0x0c043ed4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043ed6;
P_0c043ed6: /* original 000b, guest PC 0x0c043ed6 */
if(!s->budget--) { s->failed_pc=0x0c043ed6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c043ed8: /* original 0009, guest PC 0x0c043ed8 */
if(!s->budget--) { s->failed_pc=0x0c043ed8u; return 0; }
if(!vf3_matrix_family(0x0c043edau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c043edau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
