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
int vf3_away_batch2_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c038b10u: goto P_0c038b10;
case 0x0c038b12u: goto P_0c038b12;
case 0x0c038b14u: goto P_0c038b14;
case 0x0c038b16u: goto P_0c038b16;
case 0x0c038b18u: goto P_0c038b18;
case 0x0c038b1au: goto P_0c038b1a;
case 0x0c038b1cu: goto P_0c038b1c;
case 0x0c038b1eu: goto P_0c038b1e;
case 0x0c038b20u: goto P_0c038b20;
case 0x0c038b22u: goto P_0c038b22;
case 0x0c038b24u: goto P_0c038b24;
case 0x0c038b26u: goto P_0c038b26;
case 0x0c038b30u: goto P_0c038b30;
case 0x0c038b32u: goto P_0c038b32;
case 0x0c038b34u: goto P_0c038b34;
case 0x0c038b36u: goto P_0c038b36;
case 0x0c038b38u: goto P_0c038b38;
case 0x0c038b3au: goto P_0c038b3a;
case 0x0c038b3cu: goto P_0c038b3c;
case 0x0c038d30u: goto P_0c038d30;
case 0x0c038d32u: goto P_0c038d32;
case 0x0c038d34u: goto P_0c038d34;
case 0x0c038d36u: goto P_0c038d36;
case 0x0c038d38u: goto P_0c038d38;
case 0x0c038d3au: goto P_0c038d3a;
case 0x0c038d3cu: goto P_0c038d3c;
case 0x0c038d3eu: goto P_0c038d3e;
case 0x0c038d40u: goto P_0c038d40;
case 0x0c038d42u: goto P_0c038d42;
case 0x0c038d44u: goto P_0c038d44;
case 0x0c038d46u: goto P_0c038d46;
case 0x0c038d48u: goto P_0c038d48;
case 0x0c038d4au: goto P_0c038d4a;
case 0x0c038d4cu: goto P_0c038d4c;
case 0x0c038d4eu: goto P_0c038d4e;
case 0x0c038d50u: goto P_0c038d50;
case 0x0c038d52u: goto P_0c038d52;
case 0x0c038d54u: goto P_0c038d54;
case 0x0c038d56u: goto P_0c038d56;
case 0x0c038d58u: goto P_0c038d58;
case 0x0c038d5au: goto P_0c038d5a;
case 0x0c038d5cu: goto P_0c038d5c;
case 0x0c038d5eu: goto P_0c038d5e;
case 0x0c038d60u: goto P_0c038d60;
case 0x0c038d62u: goto P_0c038d62;
case 0x0c038d64u: goto P_0c038d64;
case 0x0c038d66u: goto P_0c038d66;
case 0x0c038d68u: goto P_0c038d68;
case 0x0c038d6au: goto P_0c038d6a;
case 0x0c038d6cu: goto P_0c038d6c;
case 0x0c038d6eu: goto P_0c038d6e;
case 0x0c038d70u: goto P_0c038d70;
case 0x0c038d72u: goto P_0c038d72;
case 0x0c038d74u: goto P_0c038d74;
case 0x0c038d76u: goto P_0c038d76;
case 0x0c038d78u: goto P_0c038d78;
case 0x0c038d7au: goto P_0c038d7a;
case 0x0c038d7cu: goto P_0c038d7c;
case 0x0c038d7eu: goto P_0c038d7e;
case 0x0c038d80u: goto P_0c038d80;
case 0x0c038d82u: goto P_0c038d82;
case 0x0c038d84u: goto P_0c038d84;
case 0x0c038d86u: goto P_0c038d86;
case 0x0c038d88u: goto P_0c038d88;
case 0x0c038d8au: goto P_0c038d8a;
case 0x0c038d8cu: goto P_0c038d8c;
case 0x0c038d8eu: goto P_0c038d8e;
case 0x0c038d90u: goto P_0c038d90;
case 0x0c038d92u: goto P_0c038d92;
case 0x0c038d94u: goto P_0c038d94;
case 0x0c038d96u: goto P_0c038d96;
case 0x0c038d98u: goto P_0c038d98;
case 0x0c038d9au: goto P_0c038d9a;
case 0x0c038d9cu: goto P_0c038d9c;
case 0x0c038d9eu: goto P_0c038d9e;
case 0x0c038da0u: goto P_0c038da0;
case 0x0c038da2u: goto P_0c038da2;
case 0x0c038da4u: goto P_0c038da4;
case 0x0c039540u: goto P_0c039540;
case 0x0c039542u: goto P_0c039542;
case 0x0c039544u: goto P_0c039544;
case 0x0c039546u: goto P_0c039546;
case 0x0c039548u: goto P_0c039548;
case 0x0c03954au: goto P_0c03954a;
case 0x0c03954cu: goto P_0c03954c;
case 0x0c03954eu: goto P_0c03954e;
case 0x0c039550u: goto P_0c039550;
case 0x0c039552u: goto P_0c039552;
case 0x0c039554u: goto P_0c039554;
case 0x0c039556u: goto P_0c039556;
case 0x0c039558u: goto P_0c039558;
case 0x0c03955au: goto P_0c03955a;
case 0x0c03955cu: goto P_0c03955c;
case 0x0c03955eu: goto P_0c03955e;
case 0x0c039560u: goto P_0c039560;
case 0x0c039562u: goto P_0c039562;
case 0x0c039564u: goto P_0c039564;
case 0x0c039566u: goto P_0c039566;
case 0x0c039568u: goto P_0c039568;
case 0x0c03956au: goto P_0c03956a;
case 0x0c03956cu: goto P_0c03956c;
case 0x0c03956eu: goto P_0c03956e;
case 0x0c039570u: goto P_0c039570;
case 0x0c039572u: goto P_0c039572;
case 0x0c039574u: goto P_0c039574;
case 0x0c039576u: goto P_0c039576;
case 0x0c039578u: goto P_0c039578;
case 0x0c03957au: goto P_0c03957a;
case 0x0c03957cu: goto P_0c03957c;
case 0x0c03957eu: goto P_0c03957e;
case 0x0c039580u: goto P_0c039580;
case 0x0c039582u: goto P_0c039582;
case 0x0c039584u: goto P_0c039584;
case 0x0c039586u: goto P_0c039586;
case 0x0c039588u: goto P_0c039588;
case 0x0c03958au: goto P_0c03958a;
case 0x0c03958cu: goto P_0c03958c;
case 0x0c03958eu: goto P_0c03958e;
case 0x0c039590u: goto P_0c039590;
case 0x0c0395e0u: goto P_0c0395e0;
case 0x0c0395e2u: goto P_0c0395e2;
case 0x0c0395e4u: goto P_0c0395e4;
case 0x0c0395e6u: goto P_0c0395e6;
case 0x0c0395e8u: goto P_0c0395e8;
case 0x0c0395eau: goto P_0c0395ea;
case 0x0c0395ecu: goto P_0c0395ec;
case 0x0c0395eeu: goto P_0c0395ee;
case 0x0c0395f0u: goto P_0c0395f0;
case 0x0c0395f2u: goto P_0c0395f2;
case 0x0c0395f4u: goto P_0c0395f4;
case 0x0c0395f6u: goto P_0c0395f6;
case 0x0c0395f8u: goto P_0c0395f8;
case 0x0c0395fau: goto P_0c0395fa;
case 0x0c0395fcu: goto P_0c0395fc;
case 0x0c0395feu: goto P_0c0395fe;
case 0x0c039600u: goto P_0c039600;
case 0x0c039602u: goto P_0c039602;
case 0x0c039604u: goto P_0c039604;
case 0x0c039606u: goto P_0c039606;
case 0x0c039608u: goto P_0c039608;
case 0x0c03960au: goto P_0c03960a;
case 0x0c03960cu: goto P_0c03960c;
case 0x0c03960eu: goto P_0c03960e;
case 0x0c039610u: goto P_0c039610;
case 0x0c039612u: goto P_0c039612;
case 0x0c039614u: goto P_0c039614;
case 0x0c039616u: goto P_0c039616;
case 0x0c039618u: goto P_0c039618;
case 0x0c03961au: goto P_0c03961a;
case 0x0c03961cu: goto P_0c03961c;
case 0x0c03961eu: goto P_0c03961e;
case 0x0c039620u: goto P_0c039620;
case 0x0c039622u: goto P_0c039622;
case 0x0c039624u: goto P_0c039624;
case 0x0c039626u: goto P_0c039626;
case 0x0c039628u: goto P_0c039628;
case 0x0c03962au: goto P_0c03962a;
case 0x0c03962cu: goto P_0c03962c;
case 0x0c03962eu: goto P_0c03962e;
case 0x0c039630u: goto P_0c039630;
case 0x0c039632u: goto P_0c039632;
case 0x0c039634u: goto P_0c039634;
case 0x0c039636u: goto P_0c039636;
case 0x0c039638u: goto P_0c039638;
case 0x0c03963au: goto P_0c03963a;
case 0x0c03963cu: goto P_0c03963c;
case 0x0c03963eu: goto P_0c03963e;
case 0x0c039640u: goto P_0c039640;
case 0x0c039642u: goto P_0c039642;
case 0x0c039644u: goto P_0c039644;
case 0x0c039646u: goto P_0c039646;
case 0x0c039648u: goto P_0c039648;
case 0x0c03964au: goto P_0c03964a;
case 0x0c03964cu: goto P_0c03964c;
case 0x0c03964eu: goto P_0c03964e;
case 0x0c039650u: goto P_0c039650;
case 0x0c039652u: goto P_0c039652;
case 0x0c039654u: goto P_0c039654;
case 0x0c039656u: goto P_0c039656;
case 0x0c039658u: goto P_0c039658;
case 0x0c03965au: goto P_0c03965a;
case 0x0c03965cu: goto P_0c03965c;
case 0x0c03965eu: goto P_0c03965e;
case 0x0c039660u: goto P_0c039660;
case 0x0c039662u: goto P_0c039662;
case 0x0c039664u: goto P_0c039664;
case 0x0c039666u: goto P_0c039666;
case 0x0c039668u: goto P_0c039668;
case 0x0c03966au: goto P_0c03966a;
case 0x0c03966cu: goto P_0c03966c;
case 0x0c03966eu: goto P_0c03966e;
case 0x0c039670u: goto P_0c039670;
case 0x0c039672u: goto P_0c039672;
case 0x0c039674u: goto P_0c039674;
case 0x0c039676u: goto P_0c039676;
case 0x0c039678u: goto P_0c039678;
case 0x0c03967au: goto P_0c03967a;
case 0x0c03967cu: goto P_0c03967c;
case 0x0c03967eu: goto P_0c03967e;
case 0x0c039680u: goto P_0c039680;
case 0x0c039682u: goto P_0c039682;
case 0x0c039684u: goto P_0c039684;
case 0x0c039686u: goto P_0c039686;
case 0x0c039688u: goto P_0c039688;
case 0x0c03968au: goto P_0c03968a;
case 0x0c03968cu: goto P_0c03968c;
case 0x0c03968eu: goto P_0c03968e;
case 0x0c039690u: goto P_0c039690;
case 0x0c039692u: goto P_0c039692;
case 0x0c039694u: goto P_0c039694;
case 0x0c039696u: goto P_0c039696;
case 0x0c039698u: goto P_0c039698;
case 0x0c03969au: goto P_0c03969a;
case 0x0c03969cu: goto P_0c03969c;
case 0x0c03969eu: goto P_0c03969e;
case 0x0c0396a0u: goto P_0c0396a0;
case 0x0c0396a2u: goto P_0c0396a2;
case 0x0c0396b0u: goto P_0c0396b0;
case 0x0c0396b2u: goto P_0c0396b2;
case 0x0c0396b4u: goto P_0c0396b4;
case 0x0c0396b6u: goto P_0c0396b6;
case 0x0c0396b8u: goto P_0c0396b8;
case 0x0c0396bau: goto P_0c0396ba;
case 0x0c0396bcu: goto P_0c0396bc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c038b10: /* original e33c, guest PC 0x0c038b10 */
if(!s->budget--) { s->failed_pc=0x0c038b10u; return 0; }
r[3]=0x0000003cu;
goto P_0c038b12;
P_0c038b12: /* original d13e, guest PC 0x0c038b12 */
if(!s->budget--) { s->failed_pc=0x0c038b12u; return 0; }
r[1]=read(ram,0x0c038c0cu,4);
goto P_0c038b14;
P_0c038b14: /* original 4f12, guest PC 0x0c038b14 */
if(!s->budget--) { s->failed_pc=0x0c038b14u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c038b16;
P_0c038b16: /* original 0437, guest PC 0x0c038b16 */
if(!s->budget--) { s->failed_pc=0x0c038b16u; return 0; }
r[19]=r[4]*r[3];
goto P_0c038b18;
P_0c038b18: /* original 6212, guest PC 0x0c038b18 */
if(!s->budget--) { s->failed_pc=0x0c038b18u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c038b1a;
P_0c038b1a: /* original 041a, guest PC 0x0c038b1a */
if(!s->budget--) { s->failed_pc=0x0c038b1au; return 0; }
r[4]=r[19];
goto P_0c038b1c;
P_0c038b1c: /* original 342c, guest PC 0x0c038b1c */
if(!s->budget--) { s->failed_pc=0x0c038b1cu; return 0; }
r[4]+=r[2];
goto P_0c038b1e;
P_0c038b1e: /* original 534a, guest PC 0x0c038b1e */
if(!s->budget--) { s->failed_pc=0x0c038b1eu; return 0; }
r[3]=read(ram,r[4]+40,4);
goto P_0c038b20;
P_0c038b20: /* original 2338, guest PC 0x0c038b20 */
if(!s->budget--) { s->failed_pc=0x0c038b20u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c038b22;
P_0c038b22: /* original 8b05, guest PC 0x0c038b22 */
if(!s->budget--) { s->failed_pc=0x0c038b22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038b30; }
goto P_0c038b24;
P_0c038b24: /* original afac, guest PC 0x0c038b24 */
if(!s->budget--) { s->failed_pc=0x0c038b24u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c038a80u,s,ram);
P_0c038b26: /* original 4f16, guest PC 0x0c038b26 */
if(!s->budget--) { s->failed_pc=0x0c038b26u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c038b28u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038b28u; return 0; } return 1;
P_0c038b30: /* original d537, guest PC 0x0c038b30 */
if(!s->budget--) { s->failed_pc=0x0c038b30u; return 0; }
r[5]=read(ram,0x0c038c10u,4);
goto P_0c038b32;
P_0c038b32: /* original 535c, guest PC 0x0c038b32 */
if(!s->budget--) { s->failed_pc=0x0c038b32u; return 0; }
r[3]=read(ram,r[5]+48,4);
goto P_0c038b34;
P_0c038b34: /* original 143c, guest PC 0x0c038b34 */
if(!s->budget--) { s->failed_pc=0x0c038b34u; return 0; }
write(ram,r[4]+48,r[3],4);
goto P_0c038b36;
P_0c038b36: /* original 525d, guest PC 0x0c038b36 */
if(!s->budget--) { s->failed_pc=0x0c038b36u; return 0; }
r[2]=read(ram,r[5]+52,4);
goto P_0c038b38;
P_0c038b38: /* original 142d, guest PC 0x0c038b38 */
if(!s->budget--) { s->failed_pc=0x0c038b38u; return 0; }
write(ram,r[4]+52,r[2],4);
goto P_0c038b3a;
P_0c038b3a: /* original 000b, guest PC 0x0c038b3a */
if(!s->budget--) { s->failed_pc=0x0c038b3au; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c038b3c: /* original 4f16, guest PC 0x0c038b3c */
if(!s->budget--) { s->failed_pc=0x0c038b3cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c038b3eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038b3eu; return 0; } return 1;
P_0c038d30: /* original 2fe6, guest PC 0x0c038d30 */
if(!s->budget--) { s->failed_pc=0x0c038d30u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038d32;
P_0c038d32: /* original 2fd6, guest PC 0x0c038d32 */
if(!s->budget--) { s->failed_pc=0x0c038d32u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c038d34;
P_0c038d34: /* original 6d43, guest PC 0x0c038d34 */
if(!s->budget--) { s->failed_pc=0x0c038d34u; return 0; }
r[13]=r[4];
goto P_0c038d36;
P_0c038d36: /* original de4e, guest PC 0x0c038d36 */
if(!s->budget--) { s->failed_pc=0x0c038d36u; return 0; }
r[14]=read(ram,0x0c038e70u,4);
goto P_0c038d38;
P_0c038d38: /* original 4d08, guest PC 0x0c038d38 */
if(!s->budget--) { s->failed_pc=0x0c038d38u; return 0; }
r[13]<<=2;
goto P_0c038d3a;
P_0c038d3a: /* original d24e, guest PC 0x0c038d3a */
if(!s->budget--) { s->failed_pc=0x0c038d3au; return 0; }
r[2]=read(ram,0x0c038e74u,4);
goto P_0c038d3c;
P_0c038d3c: /* original 7ffc, guest PC 0x0c038d3c */
if(!s->budget--) { s->failed_pc=0x0c038d3cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c038d3e;
P_0c038d3e: /* original 63e2, guest PC 0x0c038d3e */
if(!s->budget--) { s->failed_pc=0x0c038d3eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c038d40;
P_0c038d40: /* original 2322, guest PC 0x0c038d40 */
if(!s->budget--) { s->failed_pc=0x0c038d40u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c038d42;
P_0c038d42: /* original 6243, guest PC 0x0c038d42 */
if(!s->budget--) { s->failed_pc=0x0c038d42u; return 0; }
r[2]=r[4];
goto P_0c038d44;
P_0c038d44: /* original 3d2c, guest PC 0x0c038d44 */
if(!s->budget--) { s->failed_pc=0x0c038d44u; return 0; }
r[13]+=r[2];
goto P_0c038d46;
P_0c038d46: /* original d14c, guest PC 0x0c038d46 */
if(!s->budget--) { s->failed_pc=0x0c038d46u; return 0; }
r[1]=read(ram,0x0c038e78u,4);
goto P_0c038d48;
P_0c038d48: /* original 4d08, guest PC 0x0c038d48 */
if(!s->budget--) { s->failed_pc=0x0c038d48u; return 0; }
r[13]<<=2;
goto P_0c038d4a;
P_0c038d4a: /* original 63e2, guest PC 0x0c038d4a */
if(!s->budget--) { s->failed_pc=0x0c038d4au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c038d4c;
P_0c038d4c: /* original 6ddf, guest PC 0x0c038d4c */
if(!s->budget--) { s->failed_pc=0x0c038d4cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c038d4e;
P_0c038d4e: /* original 3d1c, guest PC 0x0c038d4e */
if(!s->budget--) { s->failed_pc=0x0c038d4eu; return 0; }
r[13]+=r[1];
goto P_0c038d50;
P_0c038d50: /* original 62d2, guest PC 0x0c038d50 */
if(!s->budget--) { s->failed_pc=0x0c038d50u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c038d52;
P_0c038d52: /* original 65d3, guest PC 0x0c038d52 */
if(!s->budget--) { s->failed_pc=0x0c038d52u; return 0; }
r[5]=r[13];
goto P_0c038d54;
P_0c038d54: /* original 7504, guest PC 0x0c038d54 */
if(!s->budget--) { s->failed_pc=0x0c038d54u; return 0; }
r[5]+=0x00000004u;
goto P_0c038d56;
P_0c038d56: /* original 66d3, guest PC 0x0c038d56 */
if(!s->budget--) { s->failed_pc=0x0c038d56u; return 0; }
r[6]=r[13];
goto P_0c038d58;
P_0c038d58: /* original 1322, guest PC 0x0c038d58 */
if(!s->budget--) { s->failed_pc=0x0c038d58u; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c038d5a;
P_0c038d5a: /* original 760c, guest PC 0x0c038d5a */
if(!s->budget--) { s->failed_pc=0x0c038d5au; return 0; }
r[6]+=0x0000000cu;
goto P_0c038d5c;
P_0c038d5c: /* original 6252, guest PC 0x0c038d5c */
if(!s->budget--) { s->failed_pc=0x0c038d5cu; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c038d5e;
P_0c038d5e: /* original 63e2, guest PC 0x0c038d5e */
if(!s->budget--) { s->failed_pc=0x0c038d5eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c038d60;
P_0c038d60: /* original 1323, guest PC 0x0c038d60 */
if(!s->budget--) { s->failed_pc=0x0c038d60u; return 0; }
write(ram,r[3]+12,r[2],4);
goto P_0c038d62;
P_0c038d62: /* original 62d3, guest PC 0x0c038d62 */
if(!s->budget--) { s->failed_pc=0x0c038d62u; return 0; }
r[2]=r[13];
goto P_0c038d64;
P_0c038d64: /* original 7208, guest PC 0x0c038d64 */
if(!s->budget--) { s->failed_pc=0x0c038d64u; return 0; }
r[2]+=0x00000008u;
goto P_0c038d66;
P_0c038d66: /* original 63e2, guest PC 0x0c038d66 */
if(!s->budget--) { s->failed_pc=0x0c038d66u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c038d68;
P_0c038d68: /* original 2f22, guest PC 0x0c038d68 */
if(!s->budget--) { s->failed_pc=0x0c038d68u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c038d6a;
P_0c038d6a: /* original 6022, guest PC 0x0c038d6a */
if(!s->budget--) { s->failed_pc=0x0c038d6au; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c038d6c;
P_0c038d6c: /* original 1308, guest PC 0x0c038d6c */
if(!s->budget--) { s->failed_pc=0x0c038d6cu; return 0; }
write(ram,r[3]+32,r[0],4);
goto P_0c038d6e;
P_0c038d6e: /* original 63e2, guest PC 0x0c038d6e */
if(!s->budget--) { s->failed_pc=0x0c038d6eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c038d70;
P_0c038d70: /* original 6262, guest PC 0x0c038d70 */
if(!s->budget--) { s->failed_pc=0x0c038d70u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c038d72;
P_0c038d72: /* original 67d3, guest PC 0x0c038d72 */
if(!s->budget--) { s->failed_pc=0x0c038d72u; return 0; }
r[7]=r[13];
goto P_0c038d74;
P_0c038d74: /* original e044, guest PC 0x0c038d74 */
if(!s->budget--) { s->failed_pc=0x0c038d74u; return 0; }
r[0]=0x00000044u;
goto P_0c038d76;
P_0c038d76: /* original 7710, guest PC 0x0c038d76 */
if(!s->budget--) { s->failed_pc=0x0c038d76u; return 0; }
r[7]+=0x00000010u;
goto P_0c038d78;
P_0c038d78: /* original 0326, guest PC 0x0c038d78 */
if(!s->budget--) { s->failed_pc=0x0c038d78u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c038d7a;
P_0c038d7a: /* original 6272, guest PC 0x0c038d7a */
if(!s->budget--) { s->failed_pc=0x0c038d7au; return 0; }
tmp=read(ram,r[7],4);
r[2]=tmp;
goto P_0c038d7c;
P_0c038d7c: /* original e040, guest PC 0x0c038d7c */
if(!s->budget--) { s->failed_pc=0x0c038d7cu; return 0; }
r[0]=0x00000040u;
goto P_0c038d7e;
P_0c038d7e: /* original 63e2, guest PC 0x0c038d7e */
if(!s->budget--) { s->failed_pc=0x0c038d7eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c038d80;
P_0c038d80: /* original 0326, guest PC 0x0c038d80 */
if(!s->budget--) { s->failed_pc=0x0c038d80u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c038d82;
P_0c038d82: /* original 63d2, guest PC 0x0c038d82 */
if(!s->budget--) { s->failed_pc=0x0c038d82u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c038d84;
P_0c038d84: /* original d43d, guest PC 0x0c038d84 */
if(!s->budget--) { s->failed_pc=0x0c038d84u; return 0; }
r[4]=read(ram,0x0c038e7cu,4);
goto P_0c038d86;
P_0c038d86: /* original 2432, guest PC 0x0c038d86 */
if(!s->budget--) { s->failed_pc=0x0c038d86u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c038d88;
P_0c038d88: /* original 6252, guest PC 0x0c038d88 */
if(!s->budget--) { s->failed_pc=0x0c038d88u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c038d8a;
P_0c038d8a: /* original 1421, guest PC 0x0c038d8a */
if(!s->budget--) { s->failed_pc=0x0c038d8au; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c038d8c;
P_0c038d8c: /* original 63f2, guest PC 0x0c038d8c */
if(!s->budget--) { s->failed_pc=0x0c038d8cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c038d8e;
P_0c038d8e: /* original 7f04, guest PC 0x0c038d8e */
if(!s->budget--) { s->failed_pc=0x0c038d8eu; return 0; }
r[15]+=0x00000004u;
goto P_0c038d90;
P_0c038d90: /* original 6232, guest PC 0x0c038d90 */
if(!s->budget--) { s->failed_pc=0x0c038d90u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c038d92;
P_0c038d92: /* original 1422, guest PC 0x0c038d92 */
if(!s->budget--) { s->failed_pc=0x0c038d92u; return 0; }
write(ram,r[4]+8,r[2],4);
goto P_0c038d94;
P_0c038d94: /* original 6362, guest PC 0x0c038d94 */
if(!s->budget--) { s->failed_pc=0x0c038d94u; return 0; }
tmp=read(ram,r[6],4);
r[3]=tmp;
goto P_0c038d96;
P_0c038d96: /* original 1433, guest PC 0x0c038d96 */
if(!s->budget--) { s->failed_pc=0x0c038d96u; return 0; }
write(ram,r[4]+12,r[3],4);
goto P_0c038d98;
P_0c038d98: /* original 6272, guest PC 0x0c038d98 */
if(!s->budget--) { s->failed_pc=0x0c038d98u; return 0; }
tmp=read(ram,r[7],4);
r[2]=tmp;
goto P_0c038d9a;
P_0c038d9a: /* original 1424, guest PC 0x0c038d9a */
if(!s->budget--) { s->failed_pc=0x0c038d9au; return 0; }
write(ram,r[4]+16,r[2],4);
goto P_0c038d9c;
P_0c038d9c: /* original d338, guest PC 0x0c038d9c */
if(!s->budget--) { s->failed_pc=0x0c038d9cu; return 0; }
r[3]=read(ram,0x0c038e80u,4);
goto P_0c038d9e;
P_0c038d9e: /* original 6df6, guest PC 0x0c038d9e */
if(!s->budget--) { s->failed_pc=0x0c038d9eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c038da0;
P_0c038da0: /* original 64e2, guest PC 0x0c038da0 */
if(!s->budget--) { s->failed_pc=0x0c038da0u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c038da2;
P_0c038da2: /* original 432b, guest PC 0x0c038da2 */
if(!s->budget--) { s->failed_pc=0x0c038da2u; return 0; }
target=r[3];
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
P_0c038da4: /* original 6ef6, guest PC 0x0c038da4 */
if(!s->budget--) { s->failed_pc=0x0c038da4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c038da6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c038da6u; return 0; } return 1;
P_0c039540: /* original 2fe6, guest PC 0x0c039540 */
if(!s->budget--) { s->failed_pc=0x0c039540u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c039542;
P_0c039542: /* original 2fd6, guest PC 0x0c039542 */
if(!s->budget--) { s->failed_pc=0x0c039542u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c039544;
P_0c039544: /* original ed00, guest PC 0x0c039544 */
if(!s->budget--) { s->failed_pc=0x0c039544u; return 0; }
r[13]=0x00000000u;
goto P_0c039546;
P_0c039546: /* original 2fc6, guest PC 0x0c039546 */
if(!s->budget--) { s->failed_pc=0x0c039546u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c039548;
P_0c039548: /* original ec01, guest PC 0x0c039548 */
if(!s->budget--) { s->failed_pc=0x0c039548u; return 0; }
r[12]=0x00000001u;
goto P_0c03954a;
P_0c03954a: /* original 2fb6, guest PC 0x0c03954a */
if(!s->budget--) { s->failed_pc=0x0c03954au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03954c;
P_0c03954c: /* original eb05, guest PC 0x0c03954c */
if(!s->budget--) { s->failed_pc=0x0c03954cu; return 0; }
r[11]=0x00000005u;
goto P_0c03954e;
P_0c03954e: /* original 2fa6, guest PC 0x0c03954e */
if(!s->budget--) { s->failed_pc=0x0c03954eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c039550;
P_0c039550: /* original 4f22, guest PC 0x0c039550 */
if(!s->budget--) { s->failed_pc=0x0c039550u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c039552;
P_0c039552: /* original 7ff0, guest PC 0x0c039552 */
if(!s->budget--) { s->failed_pc=0x0c039552u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c039554;
P_0c039554: /* original 1f42, guest PC 0x0c039554 */
if(!s->budget--) { s->failed_pc=0x0c039554u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c039556;
P_0c039556: /* original 1f51, guest PC 0x0c039556 */
if(!s->budget--) { s->failed_pc=0x0c039556u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c039558;
P_0c039558: /* original 2f62, guest PC 0x0c039558 */
if(!s->budget--) { s->failed_pc=0x0c039558u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c03955a;
P_0c03955a: /* original 1f73, guest PC 0x0c03955a */
if(!s->budget--) { s->failed_pc=0x0c03955au; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c03955c;
P_0c03955c: /* original da1d, guest PC 0x0c03955c */
if(!s->budget--) { s->failed_pc=0x0c03955cu; return 0; }
r[10]=read(ram,0x0c0395d4u,4);
goto P_0c03955e;
P_0c03955e: /* original 5efa, guest PC 0x0c03955e */
if(!s->budget--) { s->failed_pc=0x0c03955eu; return 0; }
r[14]=read(ram,r[15]+40,4);
goto P_0c039560;
P_0c039560: /* original 63e3, guest PC 0x0c039560 */
if(!s->budget--) { s->failed_pc=0x0c039560u; return 0; }
r[3]=r[14];
goto P_0c039562;
P_0c039562: /* original 23c8, guest PC 0x0c039562 */
if(!s->budget--) { s->failed_pc=0x0c039562u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c039564;
P_0c039564: /* original 8909, guest PC 0x0c039564 */
if(!s->budget--) { s->failed_pc=0x0c039564u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03957a; }
goto P_0c039566;
P_0c039566: /* original 51f3, guest PC 0x0c039566 */
if(!s->budget--) { s->failed_pc=0x0c039566u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c039568;
P_0c039568: /* original 2f16, guest PC 0x0c039568 */
if(!s->budget--) { s->failed_pc=0x0c039568u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03956a;
P_0c03956a: /* original 53f1, guest PC 0x0c03956a */
if(!s->budget--) { s->failed_pc=0x0c03956au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c03956c;
P_0c03956c: /* original 2f36, guest PC 0x0c03956c */
if(!s->budget--) { s->failed_pc=0x0c03956cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03956e;
P_0c03956e: /* original d41a, guest PC 0x0c03956e */
if(!s->budget--) { s->failed_pc=0x0c03956eu; return 0; }
r[4]=read(ram,0x0c0395d8u,4);
goto P_0c039570;
P_0c039570: /* original 56f4, guest PC 0x0c039570 */
if(!s->budget--) { s->failed_pc=0x0c039570u; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c039572;
P_0c039572: /* original 57f3, guest PC 0x0c039572 */
if(!s->budget--) { s->failed_pc=0x0c039572u; return 0; }
r[7]=read(ram,r[15]+12,4);
goto P_0c039574;
P_0c039574: /* original 4a0b, guest PC 0x0c039574 */
if(!s->budget--) { s->failed_pc=0x0c039574u; return 0; }
target=r[10];
r[16]=code_base|0x0c039578u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c039578u) { target=s->pc; goto dispatch; }
goto P_0c039578;
P_0c039576: /* original 65d3, guest PC 0x0c039576 */
if(!s->budget--) { s->failed_pc=0x0c039576u; return 0; }
r[5]=r[13];
goto P_0c039578;
P_0c039578: /* original 7f08, guest PC 0x0c039578 */
if(!s->budget--) { s->failed_pc=0x0c039578u; return 0; }
r[15]+=0x00000008u;
goto P_0c03957a;
P_0c03957a: /* original 7d01, guest PC 0x0c03957a */
if(!s->budget--) { s->failed_pc=0x0c03957au; return 0; }
r[13]+=0x00000001u;
goto P_0c03957c;
P_0c03957c: /* original 4e21, guest PC 0x0c03957c */
if(!s->budget--) { s->failed_pc=0x0c03957cu; return 0; }
r[17]=(r[17]&~1u)|((r[14]&1)!=0);
r[14]=(uint32_t)((int32_t)r[14]>>1);
goto P_0c03957e;
P_0c03957e: /* original 3db3, guest PC 0x0c03957e */
if(!s->budget--) { s->failed_pc=0x0c03957eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[11])!=0);
goto P_0c039580;
P_0c039580: /* original 8bee, guest PC 0x0c039580 */
if(!s->budget--) { s->failed_pc=0x0c039580u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c039560; }
goto P_0c039582;
P_0c039582: /* original 7f10, guest PC 0x0c039582 */
if(!s->budget--) { s->failed_pc=0x0c039582u; return 0; }
r[15]+=0x00000010u;
goto P_0c039584;
P_0c039584: /* original 4f26, guest PC 0x0c039584 */
if(!s->budget--) { s->failed_pc=0x0c039584u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c039586;
P_0c039586: /* original 6af6, guest PC 0x0c039586 */
if(!s->budget--) { s->failed_pc=0x0c039586u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c039588;
P_0c039588: /* original 6bf6, guest PC 0x0c039588 */
if(!s->budget--) { s->failed_pc=0x0c039588u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03958a;
P_0c03958a: /* original 6cf6, guest PC 0x0c03958a */
if(!s->budget--) { s->failed_pc=0x0c03958au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03958c;
P_0c03958c: /* original 6df6, guest PC 0x0c03958c */
if(!s->budget--) { s->failed_pc=0x0c03958cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03958e;
P_0c03958e: /* original 000b, guest PC 0x0c03958e */
if(!s->budget--) { s->failed_pc=0x0c03958eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c039590: /* original 6ef6, guest PC 0x0c039590 */
if(!s->budget--) { s->failed_pc=0x0c039590u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c039592u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c039592u; return 0; } return 1;
P_0c0395e0: /* original 2fe6, guest PC 0x0c0395e0 */
if(!s->budget--) { s->failed_pc=0x0c0395e0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0395e2;
P_0c0395e2: /* original e301, guest PC 0x0c0395e2 */
if(!s->budget--) { s->failed_pc=0x0c0395e2u; return 0; }
r[3]=0x00000001u;
goto P_0c0395e4;
P_0c0395e4: /* original 2fd6, guest PC 0x0c0395e4 */
if(!s->budget--) { s->failed_pc=0x0c0395e4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0395e6;
P_0c0395e6: /* original 2fc6, guest PC 0x0c0395e6 */
if(!s->budget--) { s->failed_pc=0x0c0395e6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0395e8;
P_0c0395e8: /* original 2fb6, guest PC 0x0c0395e8 */
if(!s->budget--) { s->failed_pc=0x0c0395e8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0395ea;
P_0c0395ea: /* original 6b53, guest PC 0x0c0395ea */
if(!s->budget--) { s->failed_pc=0x0c0395eau; return 0; }
r[11]=r[5];
goto P_0c0395ec;
P_0c0395ec: /* original 2fa6, guest PC 0x0c0395ec */
if(!s->budget--) { s->failed_pc=0x0c0395ecu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0395ee;
P_0c0395ee: /* original 6a43, guest PC 0x0c0395ee */
if(!s->budget--) { s->failed_pc=0x0c0395eeu; return 0; }
r[10]=r[4];
goto P_0c0395f0;
P_0c0395f0: /* original 4f22, guest PC 0x0c0395f0 */
if(!s->budget--) { s->failed_pc=0x0c0395f0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0395f2;
P_0c0395f2: /* original de8e, guest PC 0x0c0395f2 */
if(!s->budget--) { s->failed_pc=0x0c0395f2u; return 0; }
r[14]=read(ram,0x0c03982cu,4);
goto P_0c0395f4;
P_0c0395f4: /* original 23a8, guest PC 0x0c0395f4 */
if(!s->budget--) { s->failed_pc=0x0c0395f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[10])==0)!=0);
goto P_0c0395f6;
P_0c0395f6: /* original dd8c, guest PC 0x0c0395f6 */
if(!s->budget--) { s->failed_pc=0x0c0395f6u; return 0; }
r[13]=read(ram,0x0c039828u,4);
goto P_0c0395f8;
P_0c0395f8: /* original 8d09, guest PC 0x0c0395f8 */
if(!s->budget--) { s->failed_pc=0x0c0395f8u; return 0; }
cond=r[17]&1u;
r[11]<<=16;
if(cond) { goto P_0c03960e; }
goto P_0c0395fc;
P_0c0395fa: /* original 4b28, guest PC 0x0c0395fa */
if(!s->budget--) { s->failed_pc=0x0c0395fau; return 0; }
r[11]<<=16;
goto P_0c0395fc;
P_0c0395fc: /* original 64d3, guest PC 0x0c0395fc */
if(!s->budget--) { s->failed_pc=0x0c0395fcu; return 0; }
r[4]=r[13];
goto P_0c0395fe;
P_0c0395fe: /* original 6342, guest PC 0x0c0395fe */
if(!s->budget--) { s->failed_pc=0x0c0395feu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c039600;
P_0c039600: /* original 6543, guest PC 0x0c039600 */
if(!s->budget--) { s->failed_pc=0x0c039600u; return 0; }
r[5]=r[4];
goto P_0c039602;
P_0c039602: /* original e604, guest PC 0x0c039602 */
if(!s->budget--) { s->failed_pc=0x0c039602u; return 0; }
r[6]=0x00000004u;
goto P_0c039604;
P_0c039604: /* original 23e9, guest PC 0x0c039604 */
if(!s->budget--) { s->failed_pc=0x0c039604u; return 0; }
r[3]&=r[14];
goto P_0c039606;
P_0c039606: /* original 23bb, guest PC 0x0c039606 */
if(!s->budget--) { s->failed_pc=0x0c039606u; return 0; }
r[3]|=r[11];
goto P_0c039608;
P_0c039608: /* original 2432, guest PC 0x0c039608 */
if(!s->budget--) { s->failed_pc=0x0c039608u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c03960a;
P_0c03960a: /* original b059, guest PC 0x0c03960a */
if(!s->budget--) { s->failed_pc=0x0c03960au; return 0; }
target=code_base|0x0c0396c0u; r[16]=code_base|0x0c03960eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03960eu) { target=s->pc; goto dispatch; }
goto P_0c03960e;
P_0c03960c: /* original e400, guest PC 0x0c03960c */
if(!s->budget--) { s->failed_pc=0x0c03960cu; return 0; }
r[4]=0x00000000u;
goto P_0c03960e;
P_0c03960e: /* original e302, guest PC 0x0c03960e */
if(!s->budget--) { s->failed_pc=0x0c03960eu; return 0; }
r[3]=0x00000002u;
goto P_0c039610;
P_0c039610: /* original dc87, guest PC 0x0c039610 */
if(!s->budget--) { s->failed_pc=0x0c039610u; return 0; }
r[12]=read(ram,0x0c039830u,4);
goto P_0c039612;
P_0c039612: /* original 23a8, guest PC 0x0c039612 */
if(!s->budget--) { s->failed_pc=0x0c039612u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[10])==0)!=0);
goto P_0c039614;
P_0c039614: /* original 8910, guest PC 0x0c039614 */
if(!s->budget--) { s->failed_pc=0x0c039614u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c039638; }
goto P_0c039616;
P_0c039616: /* original 65c3, guest PC 0x0c039616 */
if(!s->budget--) { s->failed_pc=0x0c039616u; return 0; }
r[5]=r[12];
goto P_0c039618;
P_0c039618: /* original 6352, guest PC 0x0c039618 */
if(!s->budget--) { s->failed_pc=0x0c039618u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c03961a;
P_0c03961a: /* original d486, guest PC 0x0c03961a */
if(!s->budget--) { s->failed_pc=0x0c03961au; return 0; }
r[4]=read(ram,0x0c039834u,4);
goto P_0c03961c;
P_0c03961c: /* original e606, guest PC 0x0c03961c */
if(!s->budget--) { s->failed_pc=0x0c03961cu; return 0; }
r[6]=0x00000006u;
goto P_0c03961e;
P_0c03961e: /* original 23e9, guest PC 0x0c03961e */
if(!s->budget--) { s->failed_pc=0x0c03961eu; return 0; }
r[3]&=r[14];
goto P_0c039620;
P_0c039620: /* original 23bb, guest PC 0x0c039620 */
if(!s->budget--) { s->failed_pc=0x0c039620u; return 0; }
r[3]|=r[11];
goto P_0c039622;
P_0c039622: /* original 234b, guest PC 0x0c039622 */
if(!s->budget--) { s->failed_pc=0x0c039622u; return 0; }
r[3]|=r[4];
goto P_0c039624;
P_0c039624: /* original 2532, guest PC 0x0c039624 */
if(!s->budget--) { s->failed_pc=0x0c039624u; return 0; }
write(ram,r[5],r[3],4);
goto P_0c039626;
P_0c039626: /* original 7560, guest PC 0x0c039626 */
if(!s->budget--) { s->failed_pc=0x0c039626u; return 0; }
r[5]+=0x00000060u;
goto P_0c039628;
P_0c039628: /* original 6252, guest PC 0x0c039628 */
if(!s->budget--) { s->failed_pc=0x0c039628u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c03962a;
P_0c03962a: /* original 22e9, guest PC 0x0c03962a */
if(!s->budget--) { s->failed_pc=0x0c03962au; return 0; }
r[2]&=r[14];
goto P_0c03962c;
P_0c03962c: /* original 22bb, guest PC 0x0c03962c */
if(!s->budget--) { s->failed_pc=0x0c03962cu; return 0; }
r[2]|=r[11];
goto P_0c03962e;
P_0c03962e: /* original 224b, guest PC 0x0c03962e */
if(!s->budget--) { s->failed_pc=0x0c03962eu; return 0; }
r[2]|=r[4];
goto P_0c039630;
P_0c039630: /* original 2522, guest PC 0x0c039630 */
if(!s->budget--) { s->failed_pc=0x0c039630u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c039632;
P_0c039632: /* original 65c3, guest PC 0x0c039632 */
if(!s->budget--) { s->failed_pc=0x0c039632u; return 0; }
r[5]=r[12];
goto P_0c039634;
P_0c039634: /* original b044, guest PC 0x0c039634 */
if(!s->budget--) { s->failed_pc=0x0c039634u; return 0; }
target=code_base|0x0c0396c0u; r[16]=code_base|0x0c039638u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c039638u) { target=s->pc; goto dispatch; }
goto P_0c039638;
P_0c039636: /* original e401, guest PC 0x0c039636 */
if(!s->budget--) { s->failed_pc=0x0c039636u; return 0; }
r[4]=0x00000001u;
goto P_0c039638;
P_0c039638: /* original e204, guest PC 0x0c039638 */
if(!s->budget--) { s->failed_pc=0x0c039638u; return 0; }
r[2]=0x00000004u;
goto P_0c03963a;
P_0c03963a: /* original 22a8, guest PC 0x0c03963a */
if(!s->budget--) { s->failed_pc=0x0c03963au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[10])==0)!=0);
goto P_0c03963c;
P_0c03963c: /* original 890a, guest PC 0x0c03963c */
if(!s->budget--) { s->failed_pc=0x0c03963cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c039654; }
goto P_0c03963e;
P_0c03963e: /* original 64d3, guest PC 0x0c03963e */
if(!s->budget--) { s->failed_pc=0x0c03963eu; return 0; }
r[4]=r[13];
goto P_0c039640;
P_0c039640: /* original 6242, guest PC 0x0c039640 */
if(!s->budget--) { s->failed_pc=0x0c039640u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c039642;
P_0c039642: /* original d37d, guest PC 0x0c039642 */
if(!s->budget--) { s->failed_pc=0x0c039642u; return 0; }
r[3]=read(ram,0x0c039838u,4);
goto P_0c039644;
P_0c039644: /* original 6543, guest PC 0x0c039644 */
if(!s->budget--) { s->failed_pc=0x0c039644u; return 0; }
r[5]=r[4];
goto P_0c039646;
P_0c039646: /* original 22e9, guest PC 0x0c039646 */
if(!s->budget--) { s->failed_pc=0x0c039646u; return 0; }
r[2]&=r[14];
goto P_0c039648;
P_0c039648: /* original 22bb, guest PC 0x0c039648 */
if(!s->budget--) { s->failed_pc=0x0c039648u; return 0; }
r[2]|=r[11];
goto P_0c03964a;
P_0c03964a: /* original 223b, guest PC 0x0c03964a */
if(!s->budget--) { s->failed_pc=0x0c03964au; return 0; }
r[2]|=r[3];
goto P_0c03964c;
P_0c03964c: /* original e604, guest PC 0x0c03964c */
if(!s->budget--) { s->failed_pc=0x0c03964cu; return 0; }
r[6]=0x00000004u;
goto P_0c03964e;
P_0c03964e: /* original 2422, guest PC 0x0c03964e */
if(!s->budget--) { s->failed_pc=0x0c03964eu; return 0; }
write(ram,r[4],r[2],4);
goto P_0c039650;
P_0c039650: /* original b036, guest PC 0x0c039650 */
if(!s->budget--) { s->failed_pc=0x0c039650u; return 0; }
target=code_base|0x0c0396c0u; r[16]=code_base|0x0c039654u;
r[4]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c039654u) { target=s->pc; goto dispatch; }
goto P_0c039654;
P_0c039652: /* original e402, guest PC 0x0c039652 */
if(!s->budget--) { s->failed_pc=0x0c039652u; return 0; }
r[4]=0x00000002u;
goto P_0c039654;
P_0c039654: /* original e308, guest PC 0x0c039654 */
if(!s->budget--) { s->failed_pc=0x0c039654u; return 0; }
r[3]=0x00000008u;
goto P_0c039656;
P_0c039656: /* original 23a8, guest PC 0x0c039656 */
if(!s->budget--) { s->failed_pc=0x0c039656u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[10])==0)!=0);
goto P_0c039658;
P_0c039658: /* original 8910, guest PC 0x0c039658 */
if(!s->budget--) { s->failed_pc=0x0c039658u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03967c; }
goto P_0c03965a;
P_0c03965a: /* original 65c3, guest PC 0x0c03965a */
if(!s->budget--) { s->failed_pc=0x0c03965au; return 0; }
r[5]=r[12];
goto P_0c03965c;
P_0c03965c: /* original 6352, guest PC 0x0c03965c */
if(!s->budget--) { s->failed_pc=0x0c03965cu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c03965e;
P_0c03965e: /* original d477, guest PC 0x0c03965e */
if(!s->budget--) { s->failed_pc=0x0c03965eu; return 0; }
r[4]=read(ram,0x0c03983cu,4);
goto P_0c039660;
P_0c039660: /* original e606, guest PC 0x0c039660 */
if(!s->budget--) { s->failed_pc=0x0c039660u; return 0; }
r[6]=0x00000006u;
goto P_0c039662;
P_0c039662: /* original 23e9, guest PC 0x0c039662 */
if(!s->budget--) { s->failed_pc=0x0c039662u; return 0; }
r[3]&=r[14];
goto P_0c039664;
P_0c039664: /* original 23bb, guest PC 0x0c039664 */
if(!s->budget--) { s->failed_pc=0x0c039664u; return 0; }
r[3]|=r[11];
goto P_0c039666;
P_0c039666: /* original 234b, guest PC 0x0c039666 */
if(!s->budget--) { s->failed_pc=0x0c039666u; return 0; }
r[3]|=r[4];
goto P_0c039668;
P_0c039668: /* original 2532, guest PC 0x0c039668 */
if(!s->budget--) { s->failed_pc=0x0c039668u; return 0; }
write(ram,r[5],r[3],4);
goto P_0c03966a;
P_0c03966a: /* original 7560, guest PC 0x0c03966a */
if(!s->budget--) { s->failed_pc=0x0c03966au; return 0; }
r[5]+=0x00000060u;
goto P_0c03966c;
P_0c03966c: /* original 6252, guest PC 0x0c03966c */
if(!s->budget--) { s->failed_pc=0x0c03966cu; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c03966e;
P_0c03966e: /* original 22e9, guest PC 0x0c03966e */
if(!s->budget--) { s->failed_pc=0x0c03966eu; return 0; }
r[2]&=r[14];
goto P_0c039670;
P_0c039670: /* original 22bb, guest PC 0x0c039670 */
if(!s->budget--) { s->failed_pc=0x0c039670u; return 0; }
r[2]|=r[11];
goto P_0c039672;
P_0c039672: /* original 224b, guest PC 0x0c039672 */
if(!s->budget--) { s->failed_pc=0x0c039672u; return 0; }
r[2]|=r[4];
goto P_0c039674;
P_0c039674: /* original 2522, guest PC 0x0c039674 */
if(!s->budget--) { s->failed_pc=0x0c039674u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c039676;
P_0c039676: /* original 65c3, guest PC 0x0c039676 */
if(!s->budget--) { s->failed_pc=0x0c039676u; return 0; }
r[5]=r[12];
goto P_0c039678;
P_0c039678: /* original b022, guest PC 0x0c039678 */
if(!s->budget--) { s->failed_pc=0x0c039678u; return 0; }
target=code_base|0x0c0396c0u; r[16]=code_base|0x0c03967cu;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03967cu) { target=s->pc; goto dispatch; }
goto P_0c03967c;
P_0c03967a: /* original e403, guest PC 0x0c03967a */
if(!s->budget--) { s->failed_pc=0x0c03967au; return 0; }
r[4]=0x00000003u;
goto P_0c03967c;
P_0c03967c: /* original e210, guest PC 0x0c03967c */
if(!s->budget--) { s->failed_pc=0x0c03967cu; return 0; }
r[2]=0x00000010u;
goto P_0c03967e;
P_0c03967e: /* original 2a28, guest PC 0x0c03967e */
if(!s->budget--) { s->failed_pc=0x0c03967eu; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[2])==0)!=0);
goto P_0c039680;
P_0c039680: /* original 8916, guest PC 0x0c039680 */
if(!s->budget--) { s->failed_pc=0x0c039680u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0396b0; }
goto P_0c039682;
P_0c039682: /* original 4f26, guest PC 0x0c039682 */
if(!s->budget--) { s->failed_pc=0x0c039682u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c039684;
P_0c039684: /* original 64d3, guest PC 0x0c039684 */
if(!s->budget--) { s->failed_pc=0x0c039684u; return 0; }
r[4]=r[13];
goto P_0c039686;
P_0c039686: /* original 6142, guest PC 0x0c039686 */
if(!s->budget--) { s->failed_pc=0x0c039686u; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c039688;
P_0c039688: /* original d36d, guest PC 0x0c039688 */
if(!s->budget--) { s->failed_pc=0x0c039688u; return 0; }
r[3]=read(ram,0x0c039840u,4);
goto P_0c03968a;
P_0c03968a: /* original e604, guest PC 0x0c03968a */
if(!s->budget--) { s->failed_pc=0x0c03968au; return 0; }
r[6]=0x00000004u;
goto P_0c03968c;
P_0c03968c: /* original 2e19, guest PC 0x0c03968c */
if(!s->budget--) { s->failed_pc=0x0c03968cu; return 0; }
r[14]&=r[1];
goto P_0c03968e;
P_0c03968e: /* original 6543, guest PC 0x0c03968e */
if(!s->budget--) { s->failed_pc=0x0c03968eu; return 0; }
r[5]=r[4];
goto P_0c039690;
P_0c039690: /* original 2ebb, guest PC 0x0c039690 */
if(!s->budget--) { s->failed_pc=0x0c039690u; return 0; }
r[14]|=r[11];
goto P_0c039692;
P_0c039692: /* original 2e3b, guest PC 0x0c039692 */
if(!s->budget--) { s->failed_pc=0x0c039692u; return 0; }
r[14]|=r[3];
goto P_0c039694;
P_0c039694: /* original 24e2, guest PC 0x0c039694 */
if(!s->budget--) { s->failed_pc=0x0c039694u; return 0; }
write(ram,r[4],r[14],4);
goto P_0c039696;
P_0c039696: /* original 6463, guest PC 0x0c039696 */
if(!s->budget--) { s->failed_pc=0x0c039696u; return 0; }
r[4]=r[6];
goto P_0c039698;
P_0c039698: /* original 6af6, guest PC 0x0c039698 */
if(!s->budget--) { s->failed_pc=0x0c039698u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03969a;
P_0c03969a: /* original 6bf6, guest PC 0x0c03969a */
if(!s->budget--) { s->failed_pc=0x0c03969au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03969c;
P_0c03969c: /* original 6cf6, guest PC 0x0c03969c */
if(!s->budget--) { s->failed_pc=0x0c03969cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03969e;
P_0c03969e: /* original 6df6, guest PC 0x0c03969e */
if(!s->budget--) { s->failed_pc=0x0c03969eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0396a0;
P_0c0396a0: /* original a00e, guest PC 0x0c0396a0 */
if(!s->budget--) { s->failed_pc=0x0c0396a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0396c0u,s,ram);
P_0c0396a2: /* original 6ef6, guest PC 0x0c0396a2 */
if(!s->budget--) { s->failed_pc=0x0c0396a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0396a4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0396a4u; return 0; } return 1;
P_0c0396b0: /* original 4f26, guest PC 0x0c0396b0 */
if(!s->budget--) { s->failed_pc=0x0c0396b0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0396b2;
P_0c0396b2: /* original 6af6, guest PC 0x0c0396b2 */
if(!s->budget--) { s->failed_pc=0x0c0396b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0396b4;
P_0c0396b4: /* original 6bf6, guest PC 0x0c0396b4 */
if(!s->budget--) { s->failed_pc=0x0c0396b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0396b6;
P_0c0396b6: /* original 6cf6, guest PC 0x0c0396b6 */
if(!s->budget--) { s->failed_pc=0x0c0396b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0396b8;
P_0c0396b8: /* original 6df6, guest PC 0x0c0396b8 */
if(!s->budget--) { s->failed_pc=0x0c0396b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0396ba;
P_0c0396ba: /* original 000b, guest PC 0x0c0396ba */
if(!s->budget--) { s->failed_pc=0x0c0396bau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0396bc: /* original 6ef6, guest PC 0x0c0396bc */
if(!s->budget--) { s->failed_pc=0x0c0396bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0396beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0396beu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
