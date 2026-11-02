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
int vf3_offinv_b03_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* The code base is the mirror the code runs under: 0x0c, 0x8c or 0xac.  A call hands the callee the mirror it jumped to (the router masks the entry PC to 29 bits, which loses it); a direct entry falls back to the alias the caller left in the link register. */
uint32_t code_base=(vf3_matrix_call_alias_pc==(entry&0x1fffffffu))?vf3_matrix_call_alias:(((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u));
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0aa7a2u: goto P_0c0aa7a2;
case 0x0c0aa7a4u: goto P_0c0aa7a4;
case 0x0c0aa7a6u: goto P_0c0aa7a6;
case 0x0c0aa7a8u: goto P_0c0aa7a8;
case 0x0c0aa7aau: goto P_0c0aa7aa;
case 0x0c0aa7acu: goto P_0c0aa7ac;
case 0x0c0aa7aeu: goto P_0c0aa7ae;
case 0x0c0aa7b0u: goto P_0c0aa7b0;
case 0x0c0aa7b2u: goto P_0c0aa7b2;
case 0x0c0aa7b4u: goto P_0c0aa7b4;
case 0x0c0aa7b6u: goto P_0c0aa7b6;
case 0x0c0aa7b8u: goto P_0c0aa7b8;
case 0x0c0aa7bau: goto P_0c0aa7ba;
case 0x0c0aa7bcu: goto P_0c0aa7bc;
case 0x0c0aa7beu: goto P_0c0aa7be;
case 0x0c0aa7c0u: goto P_0c0aa7c0;
case 0x0c0aa7c2u: goto P_0c0aa7c2;
case 0x0c0aa7c4u: goto P_0c0aa7c4;
case 0x0c0aa7c6u: goto P_0c0aa7c6;
case 0x0c0aa7c8u: goto P_0c0aa7c8;
case 0x0c0aa7cau: goto P_0c0aa7ca;
case 0x0c0aa7ccu: goto P_0c0aa7cc;
case 0x0c0aa7ceu: goto P_0c0aa7ce;
case 0x0c0aa7d0u: goto P_0c0aa7d0;
case 0x0c0aa7d2u: goto P_0c0aa7d2;
case 0x0c0aa7d4u: goto P_0c0aa7d4;
case 0x0c0aa7d6u: goto P_0c0aa7d6;
case 0x0c0aa7d8u: goto P_0c0aa7d8;
case 0x0c0aa7dau: goto P_0c0aa7da;
case 0x0c0aa7dcu: goto P_0c0aa7dc;
case 0x0c0aa7deu: goto P_0c0aa7de;
case 0x0c0aa7e0u: goto P_0c0aa7e0;
case 0x0c0aa7e2u: goto P_0c0aa7e2;
case 0x0c0aa7e4u: goto P_0c0aa7e4;
case 0x0c0aa7e6u: goto P_0c0aa7e6;
case 0x0c0aa7e8u: goto P_0c0aa7e8;
case 0x0c0aa7eau: goto P_0c0aa7ea;
case 0x0c0aaebau: goto P_0c0aaeba;
case 0x0c0aaebcu: goto P_0c0aaebc;
case 0x0c0aaebeu: goto P_0c0aaebe;
case 0x0c0aaec0u: goto P_0c0aaec0;
case 0x0c0aaec2u: goto P_0c0aaec2;
case 0x0c0aaec4u: goto P_0c0aaec4;
case 0x0c0aaec6u: goto P_0c0aaec6;
case 0x0c0aaec8u: goto P_0c0aaec8;
case 0x0c0aaecau: goto P_0c0aaeca;
case 0x0c0aaeccu: goto P_0c0aaecc;
case 0x0c0aaeceu: goto P_0c0aaece;
case 0x0c0aaed0u: goto P_0c0aaed0;
case 0x0c0aaed2u: goto P_0c0aaed2;
case 0x0c0aaed4u: goto P_0c0aaed4;
case 0x0c0aaed6u: goto P_0c0aaed6;
case 0x0c0aaed8u: goto P_0c0aaed8;
case 0x0c0aaedau: goto P_0c0aaeda;
case 0x0c0aaedcu: goto P_0c0aaedc;
case 0x0c0aaedeu: goto P_0c0aaede;
case 0x0c0aaee0u: goto P_0c0aaee0;
case 0x0c0aaee2u: goto P_0c0aaee2;
case 0x0c0aaee4u: goto P_0c0aaee4;
case 0x0c0aaee6u: goto P_0c0aaee6;
case 0x0c0aaee8u: goto P_0c0aaee8;
case 0x0c0aaeeau: goto P_0c0aaeea;
case 0x0c0aaeecu: goto P_0c0aaeec;
case 0x0c0aaeeeu: goto P_0c0aaeee;
case 0x0c0aaef0u: goto P_0c0aaef0;
case 0x0c0aaef2u: goto P_0c0aaef2;
case 0x0c0aaef4u: goto P_0c0aaef4;
case 0x0c0aaef6u: goto P_0c0aaef6;
case 0x0c0aaef8u: goto P_0c0aaef8;
case 0x0c0aaefau: goto P_0c0aaefa;
case 0x0c0aaefcu: goto P_0c0aaefc;
case 0x0c0aaefeu: goto P_0c0aaefe;
case 0x0c0aaf00u: goto P_0c0aaf00;
case 0x0c0aaf02u: goto P_0c0aaf02;
case 0x0c0aaf04u: goto P_0c0aaf04;
case 0x0c0aaf06u: goto P_0c0aaf06;
case 0x0c0aaf08u: goto P_0c0aaf08;
case 0x0c0aaf0au: goto P_0c0aaf0a;
case 0x0c0aaf0cu: goto P_0c0aaf0c;
case 0x0c0aaf0eu: goto P_0c0aaf0e;
case 0x0c0aaf10u: goto P_0c0aaf10;
case 0x0c0aaf12u: goto P_0c0aaf12;
case 0x0c0aaf14u: goto P_0c0aaf14;
case 0x0c0aaf16u: goto P_0c0aaf16;
case 0x0c0aaf18u: goto P_0c0aaf18;
case 0x0c0aaf1au: goto P_0c0aaf1a;
case 0x0c0aaf1cu: goto P_0c0aaf1c;
case 0x0c0aaf1eu: goto P_0c0aaf1e;
case 0x0c0aaf20u: goto P_0c0aaf20;
case 0x0c0aaf22u: goto P_0c0aaf22;
case 0x0c0aaf24u: goto P_0c0aaf24;
case 0x0c0aaf26u: goto P_0c0aaf26;
case 0x0c0aaf28u: goto P_0c0aaf28;
case 0x0c0aaf2au: goto P_0c0aaf2a;
case 0x0c0aaf2cu: goto P_0c0aaf2c;
case 0x0c0aaf2eu: goto P_0c0aaf2e;
case 0x0c0aaf30u: goto P_0c0aaf30;
case 0x0c0aaf32u: goto P_0c0aaf32;
case 0x0c0aaf34u: goto P_0c0aaf34;
case 0x0c0aaf36u: goto P_0c0aaf36;
case 0x0c0aaf38u: goto P_0c0aaf38;
case 0x0c0aaf3au: goto P_0c0aaf3a;
case 0x0c0aaf3cu: goto P_0c0aaf3c;
case 0x0c0aaf3eu: goto P_0c0aaf3e;
case 0x0c0aaf40u: goto P_0c0aaf40;
case 0x0c0aaf42u: goto P_0c0aaf42;
case 0x0c0aaf44u: goto P_0c0aaf44;
case 0x0c0aaf46u: goto P_0c0aaf46;
case 0x0c0aaf48u: goto P_0c0aaf48;
case 0x0c0aaf4au: goto P_0c0aaf4a;
case 0x0c0aaf4cu: goto P_0c0aaf4c;
case 0x0c0aaf4eu: goto P_0c0aaf4e;
case 0x0c0aaf50u: goto P_0c0aaf50;
case 0x0c0aaf52u: goto P_0c0aaf52;
case 0x0c0aaf54u: goto P_0c0aaf54;
case 0x0c0aaf56u: goto P_0c0aaf56;
case 0x0c0aaf58u: goto P_0c0aaf58;
case 0x0c0aaf5au: goto P_0c0aaf5a;
case 0x0c0aaf5cu: goto P_0c0aaf5c;
case 0x0c0aaf5eu: goto P_0c0aaf5e;
case 0x0c0aaf60u: goto P_0c0aaf60;
case 0x0c0aaf62u: goto P_0c0aaf62;
case 0x0c0aaf64u: goto P_0c0aaf64;
case 0x0c0aaf66u: goto P_0c0aaf66;
case 0x0c0aaf68u: goto P_0c0aaf68;
case 0x0c0aaf6au: goto P_0c0aaf6a;
case 0x0c0aaf6cu: goto P_0c0aaf6c;
case 0x0c0aaf6eu: goto P_0c0aaf6e;
case 0x0c0aaf70u: goto P_0c0aaf70;
default: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!s->lost_pc) s->lost_pc=target; if(!vf3_matrix_family(target,s,ram)) return 0; return 1;
}
P_0c0aa7a2: /* original e048, guest PC 0x0c0aa7a2 */
if(!s->budget--) { s->failed_pc=0x0c0aa7a2u; return 0; }
r[0]=0x00000048u;
goto P_0c0aa7a4;
P_0c0aa7a4: /* original d324, guest PC 0x0c0aa7a4 */
if(!s->budget--) { s->failed_pc=0x0c0aa7a4u; return 0; }
r[3]=read(ram,0x0c0aa838u,4);
goto P_0c0aa7a6;
P_0c0aa7a6: /* original 025e, guest PC 0x0c0aa7a6 */
if(!s->budget--) { s->failed_pc=0x0c0aa7a6u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c0aa7a8;
P_0c0aa7a8: /* original 4f22, guest PC 0x0c0aa7a8 */
if(!s->budget--) { s->failed_pc=0x0c0aa7a8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aa7aa;
P_0c0aa7aa: /* original 2238, guest PC 0x0c0aa7aa */
if(!s->budget--) { s->failed_pc=0x0c0aa7aau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aa7ac;
P_0c0aa7ac: /* original 891b, guest PC 0x0c0aa7ac */
if(!s->budget--) { s->failed_pc=0x0c0aa7acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa7e6; }
goto P_0c0aa7ae;
P_0c0aa7ae: /* original 9034, guest PC 0x0c0aa7ae */
if(!s->budget--) { s->failed_pc=0x0c0aa7aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa81au,2);
goto P_0c0aa7b0;
P_0c0aa7b0: /* original 065d, guest PC 0x0c0aa7b0 */
if(!s->budget--) { s->failed_pc=0x0c0aa7b0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aa7b2;
P_0c0aa7b2: /* original e03e, guest PC 0x0c0aa7b2 */
if(!s->budget--) { s->failed_pc=0x0c0aa7b2u; return 0; }
r[0]=0x0000003eu;
goto P_0c0aa7b4;
P_0c0aa7b4: /* original 035d, guest PC 0x0c0aa7b4 */
if(!s->budget--) { s->failed_pc=0x0c0aa7b4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aa7b6;
P_0c0aa7b6: /* original 8444, guest PC 0x0c0aa7b6 */
if(!s->budget--) { s->failed_pc=0x0c0aa7b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+4,1);
goto P_0c0aa7b8;
P_0c0aa7b8: /* original 666d, guest PC 0x0c0aa7b8 */
if(!s->budget--) { s->failed_pc=0x0c0aa7b8u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0aa7ba;
P_0c0aa7ba: /* original 633d, guest PC 0x0c0aa7ba */
if(!s->budget--) { s->failed_pc=0x0c0aa7bau; return 0; }
r[3]=r[3]&65535u;
goto P_0c0aa7bc;
P_0c0aa7bc: /* original 600c, guest PC 0x0c0aa7bc */
if(!s->budget--) { s->failed_pc=0x0c0aa7bcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0aa7be;
P_0c0aa7be: /* original 3638, guest PC 0x0c0aa7be */
if(!s->budget--) { s->failed_pc=0x0c0aa7beu; return 0; }
r[6]-=r[3];
goto P_0c0aa7c0;
P_0c0aa7c0: /* original 360c, guest PC 0x0c0aa7c0 */
if(!s->budget--) { s->failed_pc=0x0c0aa7c0u; return 0; }
r[6]+=r[0];
goto P_0c0aa7c2;
P_0c0aa7c2: /* original 902b, guest PC 0x0c0aa7c2 */
if(!s->budget--) { s->failed_pc=0x0c0aa7c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa81cu,2);
goto P_0c0aa7c4;
P_0c0aa7c4: /* original e301, guest PC 0x0c0aa7c4 */
if(!s->budget--) { s->failed_pc=0x0c0aa7c4u; return 0; }
r[3]=0x00000001u;
goto P_0c0aa7c6;
P_0c0aa7c6: /* original 054d, guest PC 0x0c0aa7c6 */
if(!s->budget--) { s->failed_pc=0x0c0aa7c6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0aa7c8;
P_0c0aa7c8: /* original 3637, guest PC 0x0c0aa7c8 */
if(!s->budget--) { s->failed_pc=0x0c0aa7c8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[3])!=0);
goto P_0c0aa7ca;
P_0c0aa7ca: /* original 8f0a, guest PC 0x0c0aa7ca */
if(!s->budget--) { s->failed_pc=0x0c0aa7cau; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(!cond) { goto P_0c0aa7e2; }
goto P_0c0aa7ce;
P_0c0aa7cc: /* original 655d, guest PC 0x0c0aa7cc */
if(!s->budget--) { s->failed_pc=0x0c0aa7ccu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0aa7ce;
P_0c0aa7ce: /* original e03e, guest PC 0x0c0aa7ce */
if(!s->budget--) { s->failed_pc=0x0c0aa7ceu; return 0; }
r[0]=0x0000003eu;
goto P_0c0aa7d0;
P_0c0aa7d0: /* original d31a, guest PC 0x0c0aa7d0 */
if(!s->budget--) { s->failed_pc=0x0c0aa7d0u; return 0; }
r[3]=read(ram,0x0c0aa83cu,4);
goto P_0c0aa7d2;
P_0c0aa7d2: /* original 074d, guest PC 0x0c0aa7d2 */
if(!s->budget--) { s->failed_pc=0x0c0aa7d2u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0aa7d4;
P_0c0aa7d4: /* original 677d, guest PC 0x0c0aa7d4 */
if(!s->budget--) { s->failed_pc=0x0c0aa7d4u; return 0; }
r[7]=r[7]&65535u;
goto P_0c0aa7d6;
P_0c0aa7d6: /* original 3578, guest PC 0x0c0aa7d6 */
if(!s->budget--) { s->failed_pc=0x0c0aa7d6u; return 0; }
r[5]-=r[7];
goto P_0c0aa7d8;
P_0c0aa7d8: /* original 6153, guest PC 0x0c0aa7d8 */
if(!s->budget--) { s->failed_pc=0x0c0aa7d8u; return 0; }
r[1]=r[5];
goto P_0c0aa7da;
P_0c0aa7da: /* original 430b, guest PC 0x0c0aa7da */
if(!s->budget--) { s->failed_pc=0x0c0aa7dau; return 0; }
target=r[3];
r[16]=code_base|0x0c0aa7deu;
r[0]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aa7deu) { target=s->pc; goto dispatch; }
goto P_0c0aa7de;
P_0c0aa7dc: /* original 6063, guest PC 0x0c0aa7dc */
if(!s->budget--) { s->failed_pc=0x0c0aa7dcu; return 0; }
r[0]=r[6];
goto P_0c0aa7de;
P_0c0aa7de: /* original 6503, guest PC 0x0c0aa7de */
if(!s->budget--) { s->failed_pc=0x0c0aa7deu; return 0; }
r[5]=r[0];
goto P_0c0aa7e0;
P_0c0aa7e0: /* original 357c, guest PC 0x0c0aa7e0 */
if(!s->budget--) { s->failed_pc=0x0c0aa7e0u; return 0; }
r[5]+=r[7];
goto P_0c0aa7e2;
P_0c0aa7e2: /* original e03e, guest PC 0x0c0aa7e2 */
if(!s->budget--) { s->failed_pc=0x0c0aa7e2u; return 0; }
r[0]=0x0000003eu;
goto P_0c0aa7e4;
P_0c0aa7e4: /* original 0455, guest PC 0x0c0aa7e4 */
if(!s->budget--) { s->failed_pc=0x0c0aa7e4u; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c0aa7e6;
P_0c0aa7e6: /* original 4f26, guest PC 0x0c0aa7e6 */
if(!s->budget--) { s->failed_pc=0x0c0aa7e6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aa7e8;
P_0c0aa7e8: /* original 000b, guest PC 0x0c0aa7e8 */
if(!s->budget--) { s->failed_pc=0x0c0aa7e8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0aa7ea: /* original 0009, guest PC 0x0c0aa7ea */
if(!s->budget--) { s->failed_pc=0x0c0aa7eau; return 0; }
if(!vf3_matrix_family(0x0c0aa7ecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aa7ecu; return 0; } return 1;
P_0c0aaeba: /* original 2fe6, guest PC 0x0c0aaeba */
if(!s->budget--) { s->failed_pc=0x0c0aaebau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aaebc;
P_0c0aaebc: /* original e058, guest PC 0x0c0aaebc */
if(!s->budget--) { s->failed_pc=0x0c0aaebcu; return 0; }
r[0]=0x00000058u;
goto P_0c0aaebe;
P_0c0aaebe: /* original 4f22, guest PC 0x0c0aaebe */
if(!s->budget--) { s->failed_pc=0x0c0aaebeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aaec0;
P_0c0aaec0: /* original 6e43, guest PC 0x0c0aaec0 */
if(!s->budget--) { s->failed_pc=0x0c0aaec0u; return 0; }
r[14]=r[4];
goto P_0c0aaec2;
P_0c0aaec2: /* original 7ffc, guest PC 0x0c0aaec2 */
if(!s->budget--) { s->failed_pc=0x0c0aaec2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0aaec4;
P_0c0aaec4: /* original 2f52, guest PC 0x0c0aaec4 */
if(!s->budget--) { s->failed_pc=0x0c0aaec4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0aaec6;
P_0c0aaec6: /* original 04ee, guest PC 0x0c0aaec6 */
if(!s->budget--) { s->failed_pc=0x0c0aaec6u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0aaec8;
P_0c0aaec8: /* original e048, guest PC 0x0c0aaec8 */
if(!s->budget--) { s->failed_pc=0x0c0aaec8u; return 0; }
r[0]=0x00000048u;
goto P_0c0aaeca;
P_0c0aaeca: /* original d32f, guest PC 0x0c0aaeca */
if(!s->budget--) { s->failed_pc=0x0c0aaecau; return 0; }
r[3]=read(ram,0x0c0aaf88u,4);
goto P_0c0aaecc;
P_0c0aaecc: /* original 05ee, guest PC 0x0c0aaecc */
if(!s->budget--) { s->failed_pc=0x0c0aaeccu; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0aaece;
P_0c0aaece: /* original 9751, guest PC 0x0c0aaece */
if(!s->budget--) { s->failed_pc=0x0c0aaeceu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aaf74u,2);
goto P_0c0aaed0;
P_0c0aaed0: /* original 2538, guest PC 0x0c0aaed0 */
if(!s->budget--) { s->failed_pc=0x0c0aaed0u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0aaed2;
P_0c0aaed2: /* original 8d2a, guest PC 0x0c0aaed2 */
if(!s->budget--) { s->failed_pc=0x0c0aaed2u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[14],4);
r[6]=tmp;
if(cond) { goto P_0c0aaf2a; }
goto P_0c0aaed6;
P_0c0aaed4: /* original 66e2, guest PC 0x0c0aaed4 */
if(!s->budget--) { s->failed_pc=0x0c0aaed4u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c0aaed6;
P_0c0aaed6: /* original 934e, guest PC 0x0c0aaed6 */
if(!s->budget--) { s->failed_pc=0x0c0aaed6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aaf76u,2);
goto P_0c0aaed8;
P_0c0aaed8: /* original 854e, guest PC 0x0c0aaed8 */
if(!s->budget--) { s->failed_pc=0x0c0aaed8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+28,2);
goto P_0c0aaeda;
P_0c0aaeda: /* original 2638, guest PC 0x0c0aaeda */
if(!s->budget--) { s->failed_pc=0x0c0aaedau; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0aaedc;
P_0c0aaedc: /* original 8f3f, guest PC 0x0c0aaedc */
if(!s->budget--) { s->failed_pc=0x0c0aaedcu; return 0; }
cond=r[17]&1u;
r[5]=r[0]&65535u;
if(!cond) { goto P_0c0aaf5e; }
goto P_0c0aaee0;
P_0c0aaede: /* original 650d, guest PC 0x0c0aaede */
if(!s->budget--) { s->failed_pc=0x0c0aaedeu; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aaee0;
P_0c0aaee0: /* original 6643, guest PC 0x0c0aaee0 */
if(!s->budget--) { s->failed_pc=0x0c0aaee0u; return 0; }
r[6]=r[4];
goto P_0c0aaee2;
P_0c0aaee2: /* original e03c, guest PC 0x0c0aaee2 */
if(!s->budget--) { s->failed_pc=0x0c0aaee2u; return 0; }
r[0]=0x0000003cu;
goto P_0c0aaee4;
P_0c0aaee4: /* original 7622, guest PC 0x0c0aaee4 */
if(!s->budget--) { s->failed_pc=0x0c0aaee4u; return 0; }
r[6]+=0x00000022u;
goto P_0c0aaee6;
P_0c0aaee6: /* original 03ed, guest PC 0x0c0aaee6 */
if(!s->budget--) { s->failed_pc=0x0c0aaee6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aaee8;
P_0c0aaee8: /* original 6661, guest PC 0x0c0aaee8 */
if(!s->budget--) { s->failed_pc=0x0c0aaee8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[6]=tmp;
goto P_0c0aaeea;
P_0c0aaeea: /* original 633d, guest PC 0x0c0aaeea */
if(!s->budget--) { s->failed_pc=0x0c0aaeeau; return 0; }
r[3]=r[3]&65535u;
goto P_0c0aaeec;
P_0c0aaeec: /* original 666d, guest PC 0x0c0aaeec */
if(!s->budget--) { s->failed_pc=0x0c0aaeecu; return 0; }
r[6]=r[6]&65535u;
goto P_0c0aaeee;
P_0c0aaeee: /* original 3360, guest PC 0x0c0aaeee */
if(!s->budget--) { s->failed_pc=0x0c0aaeeeu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[6])!=0);
goto P_0c0aaef0;
P_0c0aaef0: /* original 892f, guest PC 0x0c0aaef0 */
if(!s->budget--) { s->failed_pc=0x0c0aaef0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aaf52; }
goto P_0c0aaef2;
P_0c0aaef2: /* original 903e, guest PC 0x0c0aaef2 */
if(!s->budget--) { s->failed_pc=0x0c0aaef2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aaf72u,2);
goto P_0c0aaef4;
P_0c0aaef4: /* original 06ed, guest PC 0x0c0aaef4 */
if(!s->budget--) { s->failed_pc=0x0c0aaef4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aaef6;
P_0c0aaef6: /* original 666d, guest PC 0x0c0aaef6 */
if(!s->budget--) { s->failed_pc=0x0c0aaef6u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0aaef8;
P_0c0aaef8: /* original 2678, guest PC 0x0c0aaef8 */
if(!s->budget--) { s->failed_pc=0x0c0aaef8u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[7])==0)!=0);
goto P_0c0aaefa;
P_0c0aaefa: /* original 8b0f, guest PC 0x0c0aaefa */
if(!s->budget--) { s->failed_pc=0x0c0aaefau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aaf1c; }
goto P_0c0aaefc;
P_0c0aaefc: /* original 903c, guest PC 0x0c0aaefc */
if(!s->budget--) { s->failed_pc=0x0c0aaefcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aaf78u,2);
goto P_0c0aaefe;
P_0c0aaefe: /* original 6543, guest PC 0x0c0aaefe */
if(!s->budget--) { s->failed_pc=0x0c0aaefeu; return 0; }
r[5]=r[4];
goto P_0c0aaf00;
P_0c0aaf00: /* original d322, guest PC 0x0c0aaf00 */
if(!s->budget--) { s->failed_pc=0x0c0aaf00u; return 0; }
r[3]=read(ram,0x0c0aaf8cu,4);
goto P_0c0aaf02;
P_0c0aaf02: /* original 7522, guest PC 0x0c0aaf02 */
if(!s->budget--) { s->failed_pc=0x0c0aaf02u; return 0; }
r[5]+=0x00000022u;
goto P_0c0aaf04;
P_0c0aaf04: /* original 02ee, guest PC 0x0c0aaf04 */
if(!s->budget--) { s->failed_pc=0x0c0aaf04u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0aaf06;
P_0c0aaf06: /* original 6551, guest PC 0x0c0aaf06 */
if(!s->budget--) { s->failed_pc=0x0c0aaf06u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0aaf08;
P_0c0aaf08: /* original 2238, guest PC 0x0c0aaf08 */
if(!s->budget--) { s->failed_pc=0x0c0aaf08u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aaf0a;
P_0c0aaf0a: /* original 8d02, guest PC 0x0c0aaf0a */
if(!s->budget--) { s->failed_pc=0x0c0aaf0au; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(cond) { goto P_0c0aaf12; }
goto P_0c0aaf0e;
P_0c0aaf0c: /* original 655d, guest PC 0x0c0aaf0c */
if(!s->budget--) { s->failed_pc=0x0c0aaf0cu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0aaf0e;
P_0c0aaf0e: /* original 854e, guest PC 0x0c0aaf0e */
if(!s->budget--) { s->failed_pc=0x0c0aaf0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+28,2);
goto P_0c0aaf10;
P_0c0aaf10: /* original 650d, guest PC 0x0c0aaf10 */
if(!s->budget--) { s->failed_pc=0x0c0aaf10u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aaf12;
P_0c0aaf12: /* original d31f, guest PC 0x0c0aaf12 */
if(!s->budget--) { s->failed_pc=0x0c0aaf12u; return 0; }
r[3]=read(ram,0x0c0aaf90u,4);
goto P_0c0aaf14;
P_0c0aaf14: /* original 430b, guest PC 0x0c0aaf14 */
if(!s->budget--) { s->failed_pc=0x0c0aaf14u; return 0; }
target=r[3];
r[16]=code_base|0x0c0aaf18u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aaf18u) { target=s->pc; goto dispatch; }
goto P_0c0aaf18;
P_0c0aaf16: /* original 64e3, guest PC 0x0c0aaf16 */
if(!s->budget--) { s->failed_pc=0x0c0aaf16u; return 0; }
r[4]=r[14];
goto P_0c0aaf18;
P_0c0aaf18: /* original a01b, guest PC 0x0c0aaf18 */
if(!s->budget--) { s->failed_pc=0x0c0aaf18u; return 0; }
goto P_0c0aaf52;
P_0c0aaf1a: /* original 0009, guest PC 0x0c0aaf1a */
if(!s->budget--) { s->failed_pc=0x0c0aaf1au; return 0; }
goto P_0c0aaf1c;
P_0c0aaf1c: /* original 902c, guest PC 0x0c0aaf1c */
if(!s->budget--) { s->failed_pc=0x0c0aaf1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aaf78u,2);
goto P_0c0aaf1e;
P_0c0aaf1e: /* original d31d, guest PC 0x0c0aaf1e */
if(!s->budget--) { s->failed_pc=0x0c0aaf1eu; return 0; }
r[3]=read(ram,0x0c0aaf94u,4);
goto P_0c0aaf20;
P_0c0aaf20: /* original 02ee, guest PC 0x0c0aaf20 */
if(!s->budget--) { s->failed_pc=0x0c0aaf20u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0aaf22;
P_0c0aaf22: /* original 2238, guest PC 0x0c0aaf22 */
if(!s->budget--) { s->failed_pc=0x0c0aaf22u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aaf24;
P_0c0aaf24: /* original 8b21, guest PC 0x0c0aaf24 */
if(!s->budget--) { s->failed_pc=0x0c0aaf24u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aaf6a; }
goto P_0c0aaf26;
P_0c0aaf26: /* original a01a, guest PC 0x0c0aaf26 */
if(!s->budget--) { s->failed_pc=0x0c0aaf26u; return 0; }
goto P_0c0aaf5e;
P_0c0aaf28: /* original 0009, guest PC 0x0c0aaf28 */
if(!s->budget--) { s->failed_pc=0x0c0aaf28u; return 0; }
goto P_0c0aaf2a;
P_0c0aaf2a: /* original 6543, guest PC 0x0c0aaf2a */
if(!s->budget--) { s->failed_pc=0x0c0aaf2au; return 0; }
r[5]=r[4];
goto P_0c0aaf2c;
P_0c0aaf2c: /* original d313, guest PC 0x0c0aaf2c */
if(!s->budget--) { s->failed_pc=0x0c0aaf2cu; return 0; }
r[3]=read(ram,0x0c0aaf7cu,4);
goto P_0c0aaf2e;
P_0c0aaf2e: /* original 7522, guest PC 0x0c0aaf2e */
if(!s->budget--) { s->failed_pc=0x0c0aaf2eu; return 0; }
r[5]+=0x00000022u;
goto P_0c0aaf30;
P_0c0aaf30: /* original 6551, guest PC 0x0c0aaf30 */
if(!s->budget--) { s->failed_pc=0x0c0aaf30u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0aaf32;
P_0c0aaf32: /* original 2638, guest PC 0x0c0aaf32 */
if(!s->budget--) { s->failed_pc=0x0c0aaf32u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0aaf34;
P_0c0aaf34: /* original 8f13, guest PC 0x0c0aaf34 */
if(!s->budget--) { s->failed_pc=0x0c0aaf34u; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(!cond) { goto P_0c0aaf5e; }
goto P_0c0aaf38;
P_0c0aaf36: /* original 655d, guest PC 0x0c0aaf36 */
if(!s->budget--) { s->failed_pc=0x0c0aaf36u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0aaf38;
P_0c0aaf38: /* original 901b, guest PC 0x0c0aaf38 */
if(!s->budget--) { s->failed_pc=0x0c0aaf38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aaf72u,2);
goto P_0c0aaf3a;
P_0c0aaf3a: /* original 04ed, guest PC 0x0c0aaf3a */
if(!s->budget--) { s->failed_pc=0x0c0aaf3au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aaf3c;
P_0c0aaf3c: /* original 644d, guest PC 0x0c0aaf3c */
if(!s->budget--) { s->failed_pc=0x0c0aaf3cu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0aaf3e;
P_0c0aaf3e: /* original 2478, guest PC 0x0c0aaf3e */
if(!s->budget--) { s->failed_pc=0x0c0aaf3eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[7])==0)!=0);
goto P_0c0aaf40;
P_0c0aaf40: /* original 8b04, guest PC 0x0c0aaf40 */
if(!s->budget--) { s->failed_pc=0x0c0aaf40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aaf4c; }
goto P_0c0aaf42;
P_0c0aaf42: /* original d310, guest PC 0x0c0aaf42 */
if(!s->budget--) { s->failed_pc=0x0c0aaf42u; return 0; }
r[3]=read(ram,0x0c0aaf84u,4);
goto P_0c0aaf44;
P_0c0aaf44: /* original 430b, guest PC 0x0c0aaf44 */
if(!s->budget--) { s->failed_pc=0x0c0aaf44u; return 0; }
target=r[3];
r[16]=code_base|0x0c0aaf48u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aaf48u) { target=s->pc; goto dispatch; }
goto P_0c0aaf48;
P_0c0aaf46: /* original 64e3, guest PC 0x0c0aaf46 */
if(!s->budget--) { s->failed_pc=0x0c0aaf46u; return 0; }
r[4]=r[14];
goto P_0c0aaf48;
P_0c0aaf48: /* original a003, guest PC 0x0c0aaf48 */
if(!s->budget--) { s->failed_pc=0x0c0aaf48u; return 0; }
goto P_0c0aaf52;
P_0c0aaf4a: /* original 0009, guest PC 0x0c0aaf4a */
if(!s->budget--) { s->failed_pc=0x0c0aaf4au; return 0; }
goto P_0c0aaf4c;
P_0c0aaf4c: /* original d30c, guest PC 0x0c0aaf4c */
if(!s->budget--) { s->failed_pc=0x0c0aaf4cu; return 0; }
r[3]=read(ram,0x0c0aaf80u,4);
goto P_0c0aaf4e;
P_0c0aaf4e: /* original 430b, guest PC 0x0c0aaf4e */
if(!s->budget--) { s->failed_pc=0x0c0aaf4eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0aaf52u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aaf52u) { target=s->pc; goto dispatch; }
goto P_0c0aaf52;
P_0c0aaf50: /* original 64e3, guest PC 0x0c0aaf50 */
if(!s->budget--) { s->failed_pc=0x0c0aaf50u; return 0; }
r[4]=r[14];
goto P_0c0aaf52;
P_0c0aaf52: /* original 65f2, guest PC 0x0c0aaf52 */
if(!s->budget--) { s->failed_pc=0x0c0aaf52u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0aaf54;
P_0c0aaf54: /* original 7f04, guest PC 0x0c0aaf54 */
if(!s->budget--) { s->failed_pc=0x0c0aaf54u; return 0; }
r[15]+=0x00000004u;
goto P_0c0aaf56;
P_0c0aaf56: /* original 4f26, guest PC 0x0c0aaf56 */
if(!s->budget--) { s->failed_pc=0x0c0aaf56u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aaf58;
P_0c0aaf58: /* original 64e3, guest PC 0x0c0aaf58 */
if(!s->budget--) { s->failed_pc=0x0c0aaf58u; return 0; }
r[4]=r[14];
goto P_0c0aaf5a;
P_0c0aaf5a: /* original ac22, guest PC 0x0c0aaf5a */
if(!s->budget--) { s->failed_pc=0x0c0aaf5au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa7a2;
P_0c0aaf5c: /* original 6ef6, guest PC 0x0c0aaf5c */
if(!s->budget--) { s->failed_pc=0x0c0aaf5cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aaf5e;
P_0c0aaf5e: /* original 7f04, guest PC 0x0c0aaf5e */
if(!s->budget--) { s->failed_pc=0x0c0aaf5eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aaf60;
P_0c0aaf60: /* original d208, guest PC 0x0c0aaf60 */
if(!s->budget--) { s->failed_pc=0x0c0aaf60u; return 0; }
r[2]=read(ram,0x0c0aaf84u,4);
goto P_0c0aaf62;
P_0c0aaf62: /* original 4f26, guest PC 0x0c0aaf62 */
if(!s->budget--) { s->failed_pc=0x0c0aaf62u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aaf64;
P_0c0aaf64: /* original 64e3, guest PC 0x0c0aaf64 */
if(!s->budget--) { s->failed_pc=0x0c0aaf64u; return 0; }
r[4]=r[14];
goto P_0c0aaf66;
P_0c0aaf66: /* original 422b, guest PC 0x0c0aaf66 */
if(!s->budget--) { s->failed_pc=0x0c0aaf66u; return 0; }
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
P_0c0aaf68: /* original 6ef6, guest PC 0x0c0aaf68 */
if(!s->budget--) { s->failed_pc=0x0c0aaf68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aaf6a;
P_0c0aaf6a: /* original 7f04, guest PC 0x0c0aaf6a */
if(!s->budget--) { s->failed_pc=0x0c0aaf6au; return 0; }
r[15]+=0x00000004u;
goto P_0c0aaf6c;
P_0c0aaf6c: /* original 4f26, guest PC 0x0c0aaf6c */
if(!s->budget--) { s->failed_pc=0x0c0aaf6cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aaf6e;
P_0c0aaf6e: /* original 000b, guest PC 0x0c0aaf6e */
if(!s->budget--) { s->failed_pc=0x0c0aaf6eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0aaf70: /* original 6ef6, guest PC 0x0c0aaf70 */
if(!s->budget--) { s->failed_pc=0x0c0aaf70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0aaf72u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aaf72u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c0aa7a2u,0x0c0aa7a4u,0x0c0aa7a6u,0x0c0aa7a8u,0x0c0aa7aau,0x0c0aa7acu,0x0c0aa7aeu,0x0c0aa7b0u,0x0c0aa7b2u,0x0c0aa7b4u,0x0c0aa7b6u,0x0c0aa7b8u,0x0c0aa7bau,0x0c0aa7bcu,0x0c0aa7beu,0x0c0aa7c0u,
0x0c0aa7c2u,0x0c0aa7c4u,0x0c0aa7c6u,0x0c0aa7c8u,0x0c0aa7cau,0x0c0aa7ccu,0x0c0aa7ceu,0x0c0aa7d0u,0x0c0aa7d2u,0x0c0aa7d4u,0x0c0aa7d6u,0x0c0aa7d8u,0x0c0aa7dau,0x0c0aa7dcu,0x0c0aa7deu,0x0c0aa7e0u,
0x0c0aa7e2u,0x0c0aa7e4u,0x0c0aa7e6u,0x0c0aa7e8u,0x0c0aa7eau,0x0c0aaebau,0x0c0aaebcu,0x0c0aaebeu,0x0c0aaec0u,0x0c0aaec2u,0x0c0aaec4u,0x0c0aaec6u,0x0c0aaec8u,0x0c0aaecau,0x0c0aaeccu,0x0c0aaeceu,
0x0c0aaed0u,0x0c0aaed2u,0x0c0aaed4u,0x0c0aaed6u,0x0c0aaed8u,0x0c0aaedau,0x0c0aaedcu,0x0c0aaedeu,0x0c0aaee0u,0x0c0aaee2u,0x0c0aaee4u,0x0c0aaee6u,0x0c0aaee8u,0x0c0aaeeau,0x0c0aaeecu,0x0c0aaeeeu,
0x0c0aaef0u,0x0c0aaef2u,0x0c0aaef4u,0x0c0aaef6u,0x0c0aaef8u,0x0c0aaefau,0x0c0aaefcu,0x0c0aaefeu,0x0c0aaf00u,0x0c0aaf02u,0x0c0aaf04u,0x0c0aaf06u,0x0c0aaf08u,0x0c0aaf0au,0x0c0aaf0cu,0x0c0aaf0eu,
0x0c0aaf10u,0x0c0aaf12u,0x0c0aaf14u,0x0c0aaf16u,0x0c0aaf18u,0x0c0aaf1au,0x0c0aaf1cu,0x0c0aaf1eu,0x0c0aaf20u,0x0c0aaf22u,0x0c0aaf24u,0x0c0aaf26u,0x0c0aaf28u,0x0c0aaf2au,0x0c0aaf2cu,0x0c0aaf2eu,
0x0c0aaf30u,0x0c0aaf32u,0x0c0aaf34u,0x0c0aaf36u,0x0c0aaf38u,0x0c0aaf3au,0x0c0aaf3cu,0x0c0aaf3eu,0x0c0aaf40u,0x0c0aaf42u,0x0c0aaf44u,0x0c0aaf46u,0x0c0aaf48u,0x0c0aaf4au,0x0c0aaf4cu,0x0c0aaf4eu,
0x0c0aaf50u,0x0c0aaf52u,0x0c0aaf54u,0x0c0aaf56u,0x0c0aaf58u,0x0c0aaf5au,0x0c0aaf5cu,0x0c0aaf5eu,0x0c0aaf60u,0x0c0aaf62u,0x0c0aaf64u,0x0c0aaf66u,0x0c0aaf68u,0x0c0aaf6au,0x0c0aaf6cu,0x0c0aaf6eu,
0x0c0aaf70u,
};
static const uint32_t claim_pcs[]={
0x0c0aaebau,
};
int vf3_offinv_b03_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(claim_pcs)/sizeof(claim_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(claim_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(claim_pcs)/sizeof(claim_pcs[0]) && claim_pcs[lo]==pc;
}
