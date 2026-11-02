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
int vf3_away_batch29_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05ae58u: goto P_0c05ae58;
case 0x0c05ae5au: goto P_0c05ae5a;
case 0x0c05ae5cu: goto P_0c05ae5c;
case 0x0c05ae5eu: goto P_0c05ae5e;
case 0x0c05ae60u: goto P_0c05ae60;
case 0x0c05ae62u: goto P_0c05ae62;
case 0x0c05ae64u: goto P_0c05ae64;
case 0x0c05ae66u: goto P_0c05ae66;
case 0x0c05ae68u: goto P_0c05ae68;
case 0x0c05ae6au: goto P_0c05ae6a;
case 0x0c05ae6cu: goto P_0c05ae6c;
case 0x0c05ae6eu: goto P_0c05ae6e;
case 0x0c05ae70u: goto P_0c05ae70;
case 0x0c05ae72u: goto P_0c05ae72;
case 0x0c05ae74u: goto P_0c05ae74;
case 0x0c05ae76u: goto P_0c05ae76;
case 0x0c05ae78u: goto P_0c05ae78;
case 0x0c05ae7au: goto P_0c05ae7a;
case 0x0c05ae7cu: goto P_0c05ae7c;
case 0x0c05ae7eu: goto P_0c05ae7e;
case 0x0c05ae80u: goto P_0c05ae80;
case 0x0c05ae82u: goto P_0c05ae82;
case 0x0c05ae84u: goto P_0c05ae84;
case 0x0c05ae86u: goto P_0c05ae86;
case 0x0c05ae88u: goto P_0c05ae88;
case 0x0c05ae8au: goto P_0c05ae8a;
case 0x0c05ae8cu: goto P_0c05ae8c;
case 0x0c05ae8eu: goto P_0c05ae8e;
case 0x0c05ae90u: goto P_0c05ae90;
case 0x0c05ae92u: goto P_0c05ae92;
case 0x0c05ae94u: goto P_0c05ae94;
case 0x0c05ae96u: goto P_0c05ae96;
case 0x0c05ae98u: goto P_0c05ae98;
case 0x0c05ae9au: goto P_0c05ae9a;
case 0x0c05ae9cu: goto P_0c05ae9c;
case 0x0c05ae9eu: goto P_0c05ae9e;
case 0x0c05aea0u: goto P_0c05aea0;
case 0x0c05aea2u: goto P_0c05aea2;
case 0x0c05aea4u: goto P_0c05aea4;
case 0x0c05aea6u: goto P_0c05aea6;
case 0x0c05aea8u: goto P_0c05aea8;
case 0x0c05aeaau: goto P_0c05aeaa;
case 0x0c05aeacu: goto P_0c05aeac;
case 0x0c05aeaeu: goto P_0c05aeae;
case 0x0c05aeb0u: goto P_0c05aeb0;
case 0x0c05aeb2u: goto P_0c05aeb2;
case 0x0c05aeb4u: goto P_0c05aeb4;
case 0x0c05aeb6u: goto P_0c05aeb6;
case 0x0c05aeb8u: goto P_0c05aeb8;
case 0x0c05aebau: goto P_0c05aeba;
case 0x0c05aebcu: goto P_0c05aebc;
case 0x0c05aebeu: goto P_0c05aebe;
case 0x0c05aec0u: goto P_0c05aec0;
case 0x0c05aec2u: goto P_0c05aec2;
case 0x0c05aec4u: goto P_0c05aec4;
case 0x0c05aec6u: goto P_0c05aec6;
case 0x0c05aec8u: goto P_0c05aec8;
case 0x0c05aecau: goto P_0c05aeca;
case 0x0c05aeccu: goto P_0c05aecc;
case 0x0c05aeceu: goto P_0c05aece;
case 0x0c05aed0u: goto P_0c05aed0;
case 0x0c05aed2u: goto P_0c05aed2;
case 0x0c05aed4u: goto P_0c05aed4;
case 0x0c05aed6u: goto P_0c05aed6;
case 0x0c05aed8u: goto P_0c05aed8;
case 0x0c05aedau: goto P_0c05aeda;
case 0x0c05aedcu: goto P_0c05aedc;
case 0x0c05aedeu: goto P_0c05aede;
case 0x0c05aee0u: goto P_0c05aee0;
case 0x0c05aee2u: goto P_0c05aee2;
case 0x0c05aee4u: goto P_0c05aee4;
case 0x0c05aee6u: goto P_0c05aee6;
case 0x0c05aee8u: goto P_0c05aee8;
case 0x0c05aeeau: goto P_0c05aeea;
case 0x0c05aeecu: goto P_0c05aeec;
case 0x0c05aeeeu: goto P_0c05aeee;
case 0x0c05aef0u: goto P_0c05aef0;
case 0x0c05aef2u: goto P_0c05aef2;
case 0x0c05aef4u: goto P_0c05aef4;
case 0x0c05aef6u: goto P_0c05aef6;
case 0x0c05aef8u: goto P_0c05aef8;
case 0x0c05aefau: goto P_0c05aefa;
case 0x0c05aefcu: goto P_0c05aefc;
case 0x0c05aefeu: goto P_0c05aefe;
case 0x0c05af00u: goto P_0c05af00;
case 0x0c05af02u: goto P_0c05af02;
case 0x0c05af04u: goto P_0c05af04;
case 0x0c05af06u: goto P_0c05af06;
case 0x0c05af08u: goto P_0c05af08;
case 0x0c05af0au: goto P_0c05af0a;
case 0x0c05af0cu: goto P_0c05af0c;
case 0x0c05af0eu: goto P_0c05af0e;
case 0x0c05af10u: goto P_0c05af10;
case 0x0c05af12u: goto P_0c05af12;
case 0x0c05af14u: goto P_0c05af14;
case 0x0c05af16u: goto P_0c05af16;
case 0x0c05af18u: goto P_0c05af18;
case 0x0c05af1au: goto P_0c05af1a;
case 0x0c05af1cu: goto P_0c05af1c;
case 0x0c05af1eu: goto P_0c05af1e;
case 0x0c05af20u: goto P_0c05af20;
case 0x0c05af22u: goto P_0c05af22;
case 0x0c05af24u: goto P_0c05af24;
case 0x0c05af26u: goto P_0c05af26;
case 0x0c05af28u: goto P_0c05af28;
case 0x0c05c950u: goto P_0c05c950;
case 0x0c05c952u: goto P_0c05c952;
case 0x0c05c954u: goto P_0c05c954;
case 0x0c05c956u: goto P_0c05c956;
case 0x0c05c958u: goto P_0c05c958;
case 0x0c05c95au: goto P_0c05c95a;
case 0x0c05c95cu: goto P_0c05c95c;
case 0x0c05c95eu: goto P_0c05c95e;
case 0x0c05c960u: goto P_0c05c960;
case 0x0c05c962u: goto P_0c05c962;
case 0x0c05c964u: goto P_0c05c964;
case 0x0c05c966u: goto P_0c05c966;
case 0x0c05c968u: goto P_0c05c968;
case 0x0c05c96au: goto P_0c05c96a;
case 0x0c05c96cu: goto P_0c05c96c;
case 0x0c05c96eu: goto P_0c05c96e;
case 0x0c05c970u: goto P_0c05c970;
case 0x0c05c972u: goto P_0c05c972;
case 0x0c05c974u: goto P_0c05c974;
case 0x0c05c976u: goto P_0c05c976;
case 0x0c05c978u: goto P_0c05c978;
case 0x0c05c97au: goto P_0c05c97a;
case 0x0c05c97cu: goto P_0c05c97c;
case 0x0c05c97eu: goto P_0c05c97e;
case 0x0c05c980u: goto P_0c05c980;
case 0x0c05c982u: goto P_0c05c982;
case 0x0c05c984u: goto P_0c05c984;
case 0x0c05c986u: goto P_0c05c986;
case 0x0c05c988u: goto P_0c05c988;
case 0x0c05c98au: goto P_0c05c98a;
case 0x0c05c98cu: goto P_0c05c98c;
case 0x0c05c98eu: goto P_0c05c98e;
case 0x0c05c990u: goto P_0c05c990;
case 0x0c05c992u: goto P_0c05c992;
case 0x0c05c994u: goto P_0c05c994;
case 0x0c05c996u: goto P_0c05c996;
case 0x0c05c998u: goto P_0c05c998;
case 0x0c05c99au: goto P_0c05c99a;
case 0x0c05c99cu: goto P_0c05c99c;
case 0x0c05c99eu: goto P_0c05c99e;
case 0x0c05c9a0u: goto P_0c05c9a0;
case 0x0c05c9a2u: goto P_0c05c9a2;
case 0x0c05c9a4u: goto P_0c05c9a4;
case 0x0c05c9a6u: goto P_0c05c9a6;
case 0x0c05c9a8u: goto P_0c05c9a8;
case 0x0c05c9aau: goto P_0c05c9aa;
case 0x0c05c9acu: goto P_0c05c9ac;
case 0x0c05c9aeu: goto P_0c05c9ae;
case 0x0c05c9b0u: goto P_0c05c9b0;
case 0x0c05c9b2u: goto P_0c05c9b2;
case 0x0c05c9b4u: goto P_0c05c9b4;
case 0x0c05c9b6u: goto P_0c05c9b6;
case 0x0c05c9b8u: goto P_0c05c9b8;
case 0x0c05c9bau: goto P_0c05c9ba;
case 0x0c05c9bcu: goto P_0c05c9bc;
case 0x0c05c9beu: goto P_0c05c9be;
case 0x0c05c9c0u: goto P_0c05c9c0;
case 0x0c05c9c2u: goto P_0c05c9c2;
case 0x0c05c9c4u: goto P_0c05c9c4;
case 0x0c05c9c6u: goto P_0c05c9c6;
case 0x0c05c9c8u: goto P_0c05c9c8;
case 0x0c05c9cau: goto P_0c05c9ca;
case 0x0c05c9ccu: goto P_0c05c9cc;
case 0x0c05c9ceu: goto P_0c05c9ce;
case 0x0c05c9d0u: goto P_0c05c9d0;
case 0x0c05c9d2u: goto P_0c05c9d2;
case 0x0c05c9d4u: goto P_0c05c9d4;
case 0x0c05c9d6u: goto P_0c05c9d6;
case 0x0c05c9d8u: goto P_0c05c9d8;
case 0x0c05c9dau: goto P_0c05c9da;
case 0x0c05c9dcu: goto P_0c05c9dc;
case 0x0c05c9deu: goto P_0c05c9de;
case 0x0c05c9e0u: goto P_0c05c9e0;
case 0x0c05c9e2u: goto P_0c05c9e2;
case 0x0c05c9e4u: goto P_0c05c9e4;
case 0x0c05c9e6u: goto P_0c05c9e6;
case 0x0c05c9e8u: goto P_0c05c9e8;
case 0x0c05c9eau: goto P_0c05c9ea;
case 0x0c05c9ecu: goto P_0c05c9ec;
case 0x0c05c9eeu: goto P_0c05c9ee;
case 0x0c05c9f0u: goto P_0c05c9f0;
case 0x0c05c9f2u: goto P_0c05c9f2;
case 0x0c05c9f4u: goto P_0c05c9f4;
case 0x0c05c9f6u: goto P_0c05c9f6;
case 0x0c05c9f8u: goto P_0c05c9f8;
case 0x0c05c9fau: goto P_0c05c9fa;
case 0x0c05c9fcu: goto P_0c05c9fc;
case 0x0c05c9feu: goto P_0c05c9fe;
case 0x0c05ca00u: goto P_0c05ca00;
case 0x0c05ca02u: goto P_0c05ca02;
case 0x0c05ca04u: goto P_0c05ca04;
case 0x0c05ca06u: goto P_0c05ca06;
case 0x0c05ca08u: goto P_0c05ca08;
case 0x0c05ca0au: goto P_0c05ca0a;
case 0x0c05ca0cu: goto P_0c05ca0c;
case 0x0c05ca0eu: goto P_0c05ca0e;
case 0x0c05ca10u: goto P_0c05ca10;
case 0x0c05ca12u: goto P_0c05ca12;
case 0x0c05ca14u: goto P_0c05ca14;
case 0x0c05ca16u: goto P_0c05ca16;
case 0x0c05ca18u: goto P_0c05ca18;
case 0x0c05ca1au: goto P_0c05ca1a;
case 0x0c05ca1cu: goto P_0c05ca1c;
case 0x0c05ca1eu: goto P_0c05ca1e;
case 0x0c05ca20u: goto P_0c05ca20;
case 0x0c05ca22u: goto P_0c05ca22;
case 0x0c05ca24u: goto P_0c05ca24;
case 0x0c05ca26u: goto P_0c05ca26;
case 0x0c05ca28u: goto P_0c05ca28;
case 0x0c05ca2au: goto P_0c05ca2a;
case 0x0c05ca2cu: goto P_0c05ca2c;
case 0x0c05ca2eu: goto P_0c05ca2e;
case 0x0c05ca30u: goto P_0c05ca30;
case 0x0c05ca32u: goto P_0c05ca32;
case 0x0c05ca34u: goto P_0c05ca34;
case 0x0c05ca36u: goto P_0c05ca36;
case 0x0c05ca38u: goto P_0c05ca38;
case 0x0c05ca3au: goto P_0c05ca3a;
case 0x0c05ca3cu: goto P_0c05ca3c;
case 0x0c05ca3eu: goto P_0c05ca3e;
case 0x0c05ca40u: goto P_0c05ca40;
case 0x0c05ca42u: goto P_0c05ca42;
case 0x0c05ca44u: goto P_0c05ca44;
case 0x0c05ca46u: goto P_0c05ca46;
case 0x0c05ca48u: goto P_0c05ca48;
case 0x0c05ca4au: goto P_0c05ca4a;
case 0x0c05ca4cu: goto P_0c05ca4c;
case 0x0c05ca4eu: goto P_0c05ca4e;
case 0x0c05ca50u: goto P_0c05ca50;
case 0x0c05ca52u: goto P_0c05ca52;
case 0x0c05ca54u: goto P_0c05ca54;
case 0x0c05ca56u: goto P_0c05ca56;
case 0x0c05ca58u: goto P_0c05ca58;
case 0x0c05ca5au: goto P_0c05ca5a;
case 0x0c05ca5cu: goto P_0c05ca5c;
case 0x0c05ca5eu: goto P_0c05ca5e;
case 0x0c05ca60u: goto P_0c05ca60;
case 0x0c05ca9cu: goto P_0c05ca9c;
case 0x0c05ca9eu: goto P_0c05ca9e;
case 0x0c05caa0u: goto P_0c05caa0;
case 0x0c05caa2u: goto P_0c05caa2;
case 0x0c05caa4u: goto P_0c05caa4;
case 0x0c05caa6u: goto P_0c05caa6;
case 0x0c05caa8u: goto P_0c05caa8;
case 0x0c05caaau: goto P_0c05caaa;
case 0x0c05caacu: goto P_0c05caac;
case 0x0c05caaeu: goto P_0c05caae;
case 0x0c05cab0u: goto P_0c05cab0;
case 0x0c05cab2u: goto P_0c05cab2;
case 0x0c05cab4u: goto P_0c05cab4;
case 0x0c05cab6u: goto P_0c05cab6;
case 0x0c05cab8u: goto P_0c05cab8;
case 0x0c05cabau: goto P_0c05caba;
case 0x0c05cabcu: goto P_0c05cabc;
case 0x0c05cabeu: goto P_0c05cabe;
case 0x0c05cac0u: goto P_0c05cac0;
case 0x0c05cac2u: goto P_0c05cac2;
case 0x0c05cac4u: goto P_0c05cac4;
case 0x0c05cac6u: goto P_0c05cac6;
case 0x0c05cac8u: goto P_0c05cac8;
case 0x0c05cacau: goto P_0c05caca;
case 0x0c05caccu: goto P_0c05cacc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05ae58: /* original 2fe6, guest PC 0x0c05ae58 */
if(!s->budget--) { s->failed_pc=0x0c05ae58u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ae5a;
P_0c05ae5a: /* original 4f22, guest PC 0x0c05ae5a */
if(!s->budget--) { s->failed_pc=0x0c05ae5au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05ae5c;
P_0c05ae5c: /* original d237, guest PC 0x0c05ae5c */
if(!s->budget--) { s->failed_pc=0x0c05ae5cu; return 0; }
r[2]=read(ram,0x0c05af3cu,4);
goto P_0c05ae5e;
P_0c05ae5e: /* original 7fe8, guest PC 0x0c05ae5e */
if(!s->budget--) { s->failed_pc=0x0c05ae5eu; return 0; }
r[15]+=0xffffffe8u;
goto P_0c05ae60;
P_0c05ae60: /* original d337, guest PC 0x0c05ae60 */
if(!s->budget--) { s->failed_pc=0x0c05ae60u; return 0; }
r[3]=read(ram,0x0c05af40u,4);
goto P_0c05ae62;
P_0c05ae62: /* original 67f3, guest PC 0x0c05ae62 */
if(!s->budget--) { s->failed_pc=0x0c05ae62u; return 0; }
r[7]=r[15];
goto P_0c05ae64;
P_0c05ae64: /* original 61f3, guest PC 0x0c05ae64 */
if(!s->budget--) { s->failed_pc=0x0c05ae64u; return 0; }
r[1]=r[15];
goto P_0c05ae66;
P_0c05ae66: /* original 430b, guest PC 0x0c05ae66 */
if(!s->budget--) { s->failed_pc=0x0c05ae66u; return 0; }
target=r[3];
r[16]=code_base|0x0c05ae6au;
r[0]=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05ae6au) { target=s->pc; goto dispatch; }
goto P_0c05ae6a;
P_0c05ae68: /* original e018, guest PC 0x0c05ae68 */
if(!s->budget--) { s->failed_pc=0x0c05ae68u; return 0; }
r[0]=0x00000018u;
goto P_0c05ae6a;
P_0c05ae6a: /* original d136, guest PC 0x0c05ae6a */
if(!s->budget--) { s->failed_pc=0x0c05ae6au; return 0; }
r[1]=read(ram,0x0c05af44u,4);
goto P_0c05ae6c;
P_0c05ae6c: /* original 6012, guest PC 0x0c05ae6c */
if(!s->budget--) { s->failed_pc=0x0c05ae6cu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05ae6e;
P_0c05ae6e: /* original 8801, guest PC 0x0c05ae6e */
if(!s->budget--) { s->failed_pc=0x0c05ae6eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05ae70;
P_0c05ae70: /* original 8903, guest PC 0x0c05ae70 */
if(!s->budget--) { s->failed_pc=0x0c05ae70u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ae7a; }
goto P_0c05ae72;
P_0c05ae72: /* original d335, guest PC 0x0c05ae72 */
if(!s->budget--) { s->failed_pc=0x0c05ae72u; return 0; }
r[3]=read(ram,0x0c05af48u,4);
goto P_0c05ae74;
P_0c05ae74: /* original 6032, guest PC 0x0c05ae74 */
if(!s->budget--) { s->failed_pc=0x0c05ae74u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05ae76;
P_0c05ae76: /* original c810, guest PC 0x0c05ae76 */
if(!s->budget--) { s->failed_pc=0x0c05ae76u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c05ae78;
P_0c05ae78: /* original 8902, guest PC 0x0c05ae78 */
if(!s->budget--) { s->failed_pc=0x0c05ae78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ae80; }
goto P_0c05ae7a;
P_0c05ae7a: /* original 9e58, guest PC 0x0c05ae7a */
if(!s->budget--) { s->failed_pc=0x0c05ae7au; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05af2eu,2);
goto P_0c05ae7c;
P_0c05ae7c: /* original a001, guest PC 0x0c05ae7c */
if(!s->budget--) { s->failed_pc=0x0c05ae7cu; return 0; }
goto P_0c05ae82;
P_0c05ae7e: /* original 0009, guest PC 0x0c05ae7e */
if(!s->budget--) { s->failed_pc=0x0c05ae7eu; return 0; }
goto P_0c05ae80;
P_0c05ae80: /* original 9e56, guest PC 0x0c05ae80 */
if(!s->budget--) { s->failed_pc=0x0c05ae80u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05af30u,2);
goto P_0c05ae82;
P_0c05ae82: /* original 6053, guest PC 0x0c05ae82 */
if(!s->budget--) { s->failed_pc=0x0c05ae82u; return 0; }
r[0]=r[5];
goto P_0c05ae84;
P_0c05ae84: /* original 0009, guest PC 0x0c05ae84 */
if(!s->budget--) { s->failed_pc=0x0c05ae84u; return 0; }
goto P_0c05ae86;
P_0c05ae86: /* original 8801, guest PC 0x0c05ae86 */
if(!s->budget--) { s->failed_pc=0x0c05ae86u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05ae88;
P_0c05ae88: /* original 8b14, guest PC 0x0c05ae88 */
if(!s->budget--) { s->failed_pc=0x0c05ae88u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05aeb4; }
goto P_0c05ae8a;
P_0c05ae8a: /* original 761f, guest PC 0x0c05ae8a */
if(!s->budget--) { s->failed_pc=0x0c05ae8au; return 0; }
r[6]+=0x0000001fu;
goto P_0c05ae8c;
P_0c05ae8c: /* original d22f, guest PC 0x0c05ae8c */
if(!s->budget--) { s->failed_pc=0x0c05ae8cu; return 0; }
r[2]=read(ram,0x0c05af4cu,4);
goto P_0c05ae8e;
P_0c05ae8e: /* original e3e0, guest PC 0x0c05ae8e */
if(!s->budget--) { s->failed_pc=0x0c05ae8eu; return 0; }
r[3]=0xffffffe0u;
goto P_0c05ae90;
P_0c05ae90: /* original d02f, guest PC 0x0c05ae90 */
if(!s->budget--) { s->failed_pc=0x0c05ae90u; return 0; }
r[0]=read(ram,0x0c05af50u,4);
goto P_0c05ae92;
P_0c05ae92: /* original 2639, guest PC 0x0c05ae92 */
if(!s->budget--) { s->failed_pc=0x0c05ae92u; return 0; }
r[6]&=r[3];
goto P_0c05ae94;
P_0c05ae94: /* original 6102, guest PC 0x0c05ae94 */
if(!s->budget--) { s->failed_pc=0x0c05ae94u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c05ae96;
P_0c05ae96: /* original 2129, guest PC 0x0c05ae96 */
if(!s->budget--) { s->failed_pc=0x0c05ae96u; return 0; }
r[1]&=r[2];
goto P_0c05ae98;
P_0c05ae98: /* original e316, guest PC 0x0c05ae98 */
if(!s->budget--) { s->failed_pc=0x0c05ae98u; return 0; }
r[3]=0x00000016u;
goto P_0c05ae9a;
P_0c05ae9a: /* original 453d, guest PC 0x0c05ae9a */
if(!s->budget--) { s->failed_pc=0x0c05ae9au; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c05ae9c;
P_0c05ae9c: /* original 215b, guest PC 0x0c05ae9c */
if(!s->budget--) { s->failed_pc=0x0c05ae9cu; return 0; }
r[1]|=r[5];
goto P_0c05ae9e;
P_0c05ae9e: /* original 6063, guest PC 0x0c05ae9e */
if(!s->budget--) { s->failed_pc=0x0c05ae9eu; return 0; }
r[0]=r[6];
goto P_0c05aea0;
P_0c05aea0: /* original 0009, guest PC 0x0c05aea0 */
if(!s->budget--) { s->failed_pc=0x0c05aea0u; return 0; }
goto P_0c05aea2;
P_0c05aea2: /* original 4009, guest PC 0x0c05aea2 */
if(!s->budget--) { s->failed_pc=0x0c05aea2u; return 0; }
r[0]>>=2;
goto P_0c05aea4;
P_0c05aea4: /* original 4009, guest PC 0x0c05aea4 */
if(!s->budget--) { s->failed_pc=0x0c05aea4u; return 0; }
r[0]>>=2;
goto P_0c05aea6;
P_0c05aea6: /* original 4001, guest PC 0x0c05aea6 */
if(!s->budget--) { s->failed_pc=0x0c05aea6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c05aea8;
P_0c05aea8: /* original c91f, guest PC 0x0c05aea8 */
if(!s->budget--) { s->failed_pc=0x0c05aea8u; return 0; }
r[0]&=31u;
goto P_0c05aeaa;
P_0c05aeaa: /* original 4028, guest PC 0x0c05aeaa */
if(!s->budget--) { s->failed_pc=0x0c05aeaau; return 0; }
r[0]<<=16;
goto P_0c05aeac;
P_0c05aeac: /* original 210b, guest PC 0x0c05aeac */
if(!s->budget--) { s->failed_pc=0x0c05aeacu; return 0; }
r[1]|=r[0];
goto P_0c05aeae;
P_0c05aeae: /* original d028, guest PC 0x0c05aeae */
if(!s->budget--) { s->failed_pc=0x0c05aeaeu; return 0; }
r[0]=read(ram,0x0c05af50u,4);
goto P_0c05aeb0;
P_0c05aeb0: /* original a019, guest PC 0x0c05aeb0 */
if(!s->budget--) { s->failed_pc=0x0c05aeb0u; return 0; }
write(ram,r[0],r[1],4);
goto P_0c05aee6;
P_0c05aeb2: /* original 2012, guest PC 0x0c05aeb2 */
if(!s->budget--) { s->failed_pc=0x0c05aeb2u; return 0; }
write(ram,r[0],r[1],4);
goto P_0c05aeb4;
P_0c05aeb4: /* original d223, guest PC 0x0c05aeb4 */
if(!s->budget--) { s->failed_pc=0x0c05aeb4u; return 0; }
r[2]=read(ram,0x0c05af44u,4);
goto P_0c05aeb6;
P_0c05aeb6: /* original 6022, guest PC 0x0c05aeb6 */
if(!s->budget--) { s->failed_pc=0x0c05aeb6u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05aeb8;
P_0c05aeb8: /* original 8801, guest PC 0x0c05aeb8 */
if(!s->budget--) { s->failed_pc=0x0c05aeb8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05aeba;
P_0c05aeba: /* original 8910, guest PC 0x0c05aeba */
if(!s->budget--) { s->failed_pc=0x0c05aebau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05aede; }
goto P_0c05aebc;
P_0c05aebc: /* original d322, guest PC 0x0c05aebc */
if(!s->budget--) { s->failed_pc=0x0c05aebcu; return 0; }
r[3]=read(ram,0x0c05af48u,4);
goto P_0c05aebe;
P_0c05aebe: /* original e501, guest PC 0x0c05aebe */
if(!s->budget--) { s->failed_pc=0x0c05aebeu; return 0; }
r[5]=0x00000001u;
goto P_0c05aec0;
P_0c05aec0: /* original 6032, guest PC 0x0c05aec0 */
if(!s->budget--) { s->failed_pc=0x0c05aec0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05aec2;
P_0c05aec2: /* original 2059, guest PC 0x0c05aec2 */
if(!s->budget--) { s->failed_pc=0x0c05aec2u; return 0; }
r[0]&=r[5];
goto P_0c05aec4;
P_0c05aec4: /* original 8801, guest PC 0x0c05aec4 */
if(!s->budget--) { s->failed_pc=0x0c05aec4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05aec6;
P_0c05aec6: /* original 8906, guest PC 0x0c05aec6 */
if(!s->budget--) { s->failed_pc=0x0c05aec6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05aed6; }
goto P_0c05aec8;
P_0c05aec8: /* original d11f, guest PC 0x0c05aec8 */
if(!s->budget--) { s->failed_pc=0x0c05aec8u; return 0; }
r[1]=read(ram,0x0c05af48u,4);
goto P_0c05aeca;
P_0c05aeca: /* original 6012, guest PC 0x0c05aeca */
if(!s->budget--) { s->failed_pc=0x0c05aecau; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05aecc;
P_0c05aecc: /* original c92c, guest PC 0x0c05aecc */
if(!s->budget--) { s->failed_pc=0x0c05aeccu; return 0; }
r[0]&=44u;
goto P_0c05aece;
P_0c05aece: /* original 8820, guest PC 0x0c05aece */
if(!s->budget--) { s->failed_pc=0x0c05aeceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c05aed0;
P_0c05aed0: /* original 8b01, guest PC 0x0c05aed0 */
if(!s->budget--) { s->failed_pc=0x0c05aed0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05aed6; }
goto P_0c05aed2;
P_0c05aed2: /* original 2558, guest PC 0x0c05aed2 */
if(!s->budget--) { s->failed_pc=0x0c05aed2u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c05aed4;
P_0c05aed4: /* original 8b06, guest PC 0x0c05aed4 */
if(!s->budget--) { s->failed_pc=0x0c05aed4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05aee4; }
goto P_0c05aed6;
P_0c05aed6: /* original d31c, guest PC 0x0c05aed6 */
if(!s->budget--) { s->failed_pc=0x0c05aed6u; return 0; }
r[3]=read(ram,0x0c05af48u,4);
goto P_0c05aed8;
P_0c05aed8: /* original 6032, guest PC 0x0c05aed8 */
if(!s->budget--) { s->failed_pc=0x0c05aed8u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05aeda;
P_0c05aeda: /* original c820, guest PC 0x0c05aeda */
if(!s->budget--) { s->failed_pc=0x0c05aedau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c05aedc;
P_0c05aedc: /* original 8902, guest PC 0x0c05aedc */
if(!s->budget--) { s->failed_pc=0x0c05aedcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05aee4; }
goto P_0c05aede;
P_0c05aede: /* original 9628, guest PC 0x0c05aede */
if(!s->budget--) { s->failed_pc=0x0c05aedeu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05af32u,2);
goto P_0c05aee0;
P_0c05aee0: /* original a001, guest PC 0x0c05aee0 */
if(!s->budget--) { s->failed_pc=0x0c05aee0u; return 0; }
goto P_0c05aee6;
P_0c05aee2: /* original 0009, guest PC 0x0c05aee2 */
if(!s->budget--) { s->failed_pc=0x0c05aee2u; return 0; }
goto P_0c05aee4;
P_0c05aee4: /* original 9626, guest PC 0x0c05aee4 */
if(!s->budget--) { s->failed_pc=0x0c05aee4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05af34u,2);
goto P_0c05aee6;
P_0c05aee6: /* original e048, guest PC 0x0c05aee6 */
if(!s->budget--) { s->failed_pc=0x0c05aee6u; return 0; }
r[0]=0x00000048u;
goto P_0c05aee8;
P_0c05aee8: /* original 9325, guest PC 0x0c05aee8 */
if(!s->budget--) { s->failed_pc=0x0c05aee8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05af36u,2);
goto P_0c05aeea;
P_0c05aeea: /* original d51a, guest PC 0x0c05aeea */
if(!s->budget--) { s->failed_pc=0x0c05aeeau; return 0; }
r[5]=read(ram,0x0c05af54u,4);
goto P_0c05aeec;
P_0c05aeec: /* original 05e6, guest PC 0x0c05aeec */
if(!s->budget--) { s->failed_pc=0x0c05aeecu; return 0; }
write(ram,r[5]+r[0],r[14],4);
goto P_0c05aeee;
P_0c05aeee: /* original e04c, guest PC 0x0c05aeee */
if(!s->budget--) { s->failed_pc=0x0c05aeeeu; return 0; }
r[0]=0x0000004cu;
goto P_0c05aef0;
P_0c05aef0: /* original 3430, guest PC 0x0c05aef0 */
if(!s->budget--) { s->failed_pc=0x0c05aef0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c05aef2;
P_0c05aef2: /* original 8d02, guest PC 0x0c05aef2 */
if(!s->budget--) { s->failed_pc=0x0c05aef2u; return 0; }
cond=r[17]&1u;
write(ram,r[5]+r[0],r[6],4);
if(cond) { goto P_0c05aefa; }
goto P_0c05aef6;
P_0c05aef4: /* original 0566, guest PC 0x0c05aef4 */
if(!s->budget--) { s->failed_pc=0x0c05aef4u; return 0; }
write(ram,r[5]+r[0],r[6],4);
goto P_0c05aef6;
P_0c05aef6: /* original a002, guest PC 0x0c05aef6 */
if(!s->budget--) { s->failed_pc=0x0c05aef6u; return 0; }
r[0]=r[4];
goto P_0c05aefe;
P_0c05aef8: /* original 6043, guest PC 0x0c05aef8 */
if(!s->budget--) { s->failed_pc=0x0c05aef8u; return 0; }
r[0]=r[4];
goto P_0c05aefa;
P_0c05aefa: /* original d117, guest PC 0x0c05aefa */
if(!s->budget--) { s->failed_pc=0x0c05aefau; return 0; }
r[1]=read(ram,0x0c05af58u,4);
goto P_0c05aefc;
P_0c05aefc: /* original 6012, guest PC 0x0c05aefc */
if(!s->budget--) { s->failed_pc=0x0c05aefcu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05aefe;
P_0c05aefe: /* original 4008, guest PC 0x0c05aefe */
if(!s->budget--) { s->failed_pc=0x0c05aefeu; return 0; }
r[0]<<=2;
goto P_0c05af00;
P_0c05af00: /* original 027e, guest PC 0x0c05af00 */
if(!s->budget--) { s->failed_pc=0x0c05af00u; return 0; }
r[2]=read(ram,r[7]+r[0],4);
goto P_0c05af02;
P_0c05af02: /* original e050, guest PC 0x0c05af02 */
if(!s->budget--) { s->failed_pc=0x0c05af02u; return 0; }
r[0]=0x00000050u;
goto P_0c05af04;
P_0c05af04: /* original 4209, guest PC 0x0c05af04 */
if(!s->budget--) { s->failed_pc=0x0c05af04u; return 0; }
r[2]>>=2;
goto P_0c05af06;
P_0c05af06: /* original 4201, guest PC 0x0c05af06 */
if(!s->budget--) { s->failed_pc=0x0c05af06u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]>>=1;
goto P_0c05af08;
P_0c05af08: /* original 0526, guest PC 0x0c05af08 */
if(!s->budget--) { s->failed_pc=0x0c05af08u; return 0; }
write(ram,r[5]+r[0],r[2],4);
goto P_0c05af0a;
P_0c05af0a: /* original e04c, guest PC 0x0c05af0a */
if(!s->budget--) { s->failed_pc=0x0c05af0au; return 0; }
r[0]=0x0000004cu;
goto P_0c05af0c;
P_0c05af0c: /* original 035e, guest PC 0x0c05af0c */
if(!s->budget--) { s->failed_pc=0x0c05af0cu; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c05af0e;
P_0c05af0e: /* original e048, guest PC 0x0c05af0e */
if(!s->budget--) { s->failed_pc=0x0c05af0eu; return 0; }
r[0]=0x00000048u;
goto P_0c05af10;
P_0c05af10: /* original 025e, guest PC 0x0c05af10 */
if(!s->budget--) { s->failed_pc=0x0c05af10u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c05af12;
P_0c05af12: /* original e050, guest PC 0x0c05af12 */
if(!s->budget--) { s->failed_pc=0x0c05af12u; return 0; }
r[0]=0x00000050u;
goto P_0c05af14;
P_0c05af14: /* original 0237, guest PC 0x0c05af14 */
if(!s->budget--) { s->failed_pc=0x0c05af14u; return 0; }
r[19]=r[2]*r[3];
goto P_0c05af16;
P_0c05af16: /* original 031a, guest PC 0x0c05af16 */
if(!s->budget--) { s->failed_pc=0x0c05af16u; return 0; }
r[3]=r[19];
goto P_0c05af18;
P_0c05af18: /* original 015e, guest PC 0x0c05af18 */
if(!s->budget--) { s->failed_pc=0x0c05af18u; return 0; }
r[1]=read(ram,r[5]+r[0],4);
goto P_0c05af1a;
P_0c05af1a: /* original e060, guest PC 0x0c05af1a */
if(!s->budget--) { s->failed_pc=0x0c05af1au; return 0; }
r[0]=0x00000060u;
goto P_0c05af1c;
P_0c05af1c: /* original 0317, guest PC 0x0c05af1c */
if(!s->budget--) { s->failed_pc=0x0c05af1cu; return 0; }
r[19]=r[3]*r[1];
goto P_0c05af1e;
P_0c05af1e: /* original 031a, guest PC 0x0c05af1e */
if(!s->budget--) { s->failed_pc=0x0c05af1eu; return 0; }
r[3]=r[19];
goto P_0c05af20;
P_0c05af20: /* original 0536, guest PC 0x0c05af20 */
if(!s->budget--) { s->failed_pc=0x0c05af20u; return 0; }
write(ram,r[5]+r[0],r[3],4);
goto P_0c05af22;
P_0c05af22: /* original 7f18, guest PC 0x0c05af22 */
if(!s->budget--) { s->failed_pc=0x0c05af22u; return 0; }
r[15]+=0x00000018u;
goto P_0c05af24;
P_0c05af24: /* original 4f26, guest PC 0x0c05af24 */
if(!s->budget--) { s->failed_pc=0x0c05af24u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05af26;
P_0c05af26: /* original 000b, guest PC 0x0c05af26 */
if(!s->budget--) { s->failed_pc=0x0c05af26u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05af28: /* original 6ef6, guest PC 0x0c05af28 */
if(!s->budget--) { s->failed_pc=0x0c05af28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05af2au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05af2au; return 0; } return 1;
P_0c05c950: /* original 2fe6, guest PC 0x0c05c950 */
if(!s->budget--) { s->failed_pc=0x0c05c950u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c952;
P_0c05c952: /* original e054, guest PC 0x0c05c952 */
if(!s->budget--) { s->failed_pc=0x0c05c952u; return 0; }
r[0]=0x00000054u;
goto P_0c05c954;
P_0c05c954: /* original d344, guest PC 0x0c05c954 */
if(!s->budget--) { s->failed_pc=0x0c05c954u; return 0; }
r[3]=read(ram,0x0c05ca68u,4);
goto P_0c05c956;
P_0c05c956: /* original 2fd6, guest PC 0x0c05c956 */
if(!s->budget--) { s->failed_pc=0x0c05c956u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c958;
P_0c05c958: /* original 2fc6, guest PC 0x0c05c958 */
if(!s->budget--) { s->failed_pc=0x0c05c958u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c95a;
P_0c05c95a: /* original 6d43, guest PC 0x0c05c95a */
if(!s->budget--) { s->failed_pc=0x0c05c95au; return 0; }
r[13]=r[4];
goto P_0c05c95c;
P_0c05c95c: /* original de41, guest PC 0x0c05c95c */
if(!s->budget--) { s->failed_pc=0x0c05c95cu; return 0; }
r[14]=read(ram,0x0c05ca64u,4);
goto P_0c05c95e;
P_0c05c95e: /* original 2fb6, guest PC 0x0c05c95e */
if(!s->budget--) { s->failed_pc=0x0c05c95eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c960;
P_0c05c960: /* original 2fa6, guest PC 0x0c05c960 */
if(!s->budget--) { s->failed_pc=0x0c05c960u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c962;
P_0c05c962: /* original eb02, guest PC 0x0c05c962 */
if(!s->budget--) { s->failed_pc=0x0c05c962u; return 0; }
r[11]=0x00000002u;
goto P_0c05c964;
P_0c05c964: /* original 2f96, guest PC 0x0c05c964 */
if(!s->budget--) { s->failed_pc=0x0c05c964u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c966;
P_0c05c966: /* original 2f86, guest PC 0x0c05c966 */
if(!s->budget--) { s->failed_pc=0x0c05c966u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c968;
P_0c05c968: /* original 4f22, guest PC 0x0c05c968 */
if(!s->budget--) { s->failed_pc=0x0c05c968u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05c96a;
P_0c05c96a: /* original 7ff0, guest PC 0x0c05c96a */
if(!s->budget--) { s->failed_pc=0x0c05c96au; return 0; }
r[15]+=0xfffffff0u;
goto P_0c05c96c;
P_0c05c96c: /* original 0eb6, guest PC 0x0c05c96c */
if(!s->budget--) { s->failed_pc=0x0c05c96cu; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c05c96e;
P_0c05c96e: /* original e058, guest PC 0x0c05c96e */
if(!s->budget--) { s->failed_pc=0x0c05c96eu; return 0; }
r[0]=0x00000058u;
goto P_0c05c970;
P_0c05c970: /* original 2ed2, guest PC 0x0c05c970 */
if(!s->budget--) { s->failed_pc=0x0c05c970u; return 0; }
write(ram,r[14],r[13],4);
goto P_0c05c972;
P_0c05c972: /* original 430b, guest PC 0x0c05c972 */
if(!s->budget--) { s->failed_pc=0x0c05c972u; return 0; }
target=r[3];
r[16]=code_base|0x0c05c976u;
write(ram,r[14]+r[0],r[5],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05c976u) { target=s->pc; goto dispatch; }
goto P_0c05c976;
P_0c05c974: /* original 0e56, guest PC 0x0c05c974 */
if(!s->budget--) { s->failed_pc=0x0c05c974u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c05c976;
P_0c05c976: /* original d23d, guest PC 0x0c05c976 */
if(!s->budget--) { s->failed_pc=0x0c05c976u; return 0; }
r[2]=read(ram,0x0c05ca6cu,4);
goto P_0c05c978;
P_0c05c978: /* original 3020, guest PC 0x0c05c978 */
if(!s->budget--) { s->failed_pc=0x0c05c978u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[2])!=0);
goto P_0c05c97a;
P_0c05c97a: /* original 8901, guest PC 0x0c05c97a */
if(!s->budget--) { s->failed_pc=0x0c05c97au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05c980; }
goto P_0c05c97c;
P_0c05c97c: /* original a08e, guest PC 0x0c05c97c */
if(!s->budget--) { s->failed_pc=0x0c05c97cu; return 0; }
goto P_0c05ca9c;
P_0c05c97e: /* original 0009, guest PC 0x0c05c97e */
if(!s->budget--) { s->failed_pc=0x0c05c97eu; return 0; }
goto P_0c05c980;
P_0c05c980: /* original d13b, guest PC 0x0c05c980 */
if(!s->budget--) { s->failed_pc=0x0c05c980u; return 0; }
r[1]=read(ram,0x0c05ca70u,4);
goto P_0c05c982;
P_0c05c982: /* original ec01, guest PC 0x0c05c982 */
if(!s->budget--) { s->failed_pc=0x0c05c982u; return 0; }
r[12]=0x00000001u;
goto P_0c05c984;
P_0c05c984: /* original d03b, guest PC 0x0c05c984 */
if(!s->budget--) { s->failed_pc=0x0c05c984u; return 0; }
r[0]=read(ram,0x0c05ca74u,4);
goto P_0c05c986;
P_0c05c986: /* original 21c2, guest PC 0x0c05c986 */
if(!s->budget--) { s->failed_pc=0x0c05c986u; return 0; }
write(ram,r[1],r[12],4);
goto P_0c05c988;
P_0c05c988: /* original 6302, guest PC 0x0c05c988 */
if(!s->budget--) { s->failed_pc=0x0c05c988u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c05c98a;
P_0c05c98a: /* original d23b, guest PC 0x0c05c98a */
if(!s->budget--) { s->failed_pc=0x0c05c98au; return 0; }
r[2]=read(ram,0x0c05ca78u,4);
goto P_0c05c98c;
P_0c05c98c: /* original 2232, guest PC 0x0c05c98c */
if(!s->budget--) { s->failed_pc=0x0c05c98cu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c05c98e;
P_0c05c98e: /* original 70f0, guest PC 0x0c05c98e */
if(!s->budget--) { s->failed_pc=0x0c05c98eu; return 0; }
r[0]+=0xfffffff0u;
goto P_0c05c990;
P_0c05c990: /* original d338, guest PC 0x0c05c990 */
if(!s->budget--) { s->failed_pc=0x0c05c990u; return 0; }
r[3]=read(ram,0x0c05ca74u,4);
goto P_0c05c992;
P_0c05c992: /* original 6132, guest PC 0x0c05c992 */
if(!s->budget--) { s->failed_pc=0x0c05c992u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c05c994;
P_0c05c994: /* original 4108, guest PC 0x0c05c994 */
if(!s->budget--) { s->failed_pc=0x0c05c994u; return 0; }
r[1]<<=2;
goto P_0c05c996;
P_0c05c996: /* original 01b6, guest PC 0x0c05c996 */
if(!s->budget--) { s->failed_pc=0x0c05c996u; return 0; }
write(ram,r[1]+r[0],r[11],4);
goto P_0c05c998;
P_0c05c998: /* original d138, guest PC 0x0c05c998 */
if(!s->budget--) { s->failed_pc=0x0c05c998u; return 0; }
r[1]=read(ram,0x0c05ca7cu,4);
goto P_0c05c99a;
P_0c05c99a: /* original e200, guest PC 0x0c05c99a */
if(!s->budget--) { s->failed_pc=0x0c05c99au; return 0; }
r[2]=0x00000000u;
goto P_0c05c99c;
P_0c05c99c: /* original 2122, guest PC 0x0c05c99c */
if(!s->budget--) { s->failed_pc=0x0c05c99cu; return 0; }
write(ram,r[1],r[2],4);
goto P_0c05c99e;
P_0c05c99e: /* original 7318, guest PC 0x0c05c99e */
if(!s->budget--) { s->failed_pc=0x0c05c99eu; return 0; }
r[3]+=0x00000018u;
goto P_0c05c9a0;
P_0c05c9a0: /* original 23c2, guest PC 0x0c05c9a0 */
if(!s->budget--) { s->failed_pc=0x0c05c9a0u; return 0; }
write(ram,r[3],r[12],4);
goto P_0c05c9a2;
P_0c05c9a2: /* original 64f3, guest PC 0x0c05c9a2 */
if(!s->budget--) { s->failed_pc=0x0c05c9a2u; return 0; }
r[4]=r[15];
goto P_0c05c9a4;
P_0c05c9a4: /* original 52d4, guest PC 0x0c05c9a4 */
if(!s->budget--) { s->failed_pc=0x0c05c9a4u; return 0; }
r[2]=read(ram,r[13]+16,4);
goto P_0c05c9a6;
P_0c05c9a6: /* original 6a43, guest PC 0x0c05c9a6 */
if(!s->budget--) { s->failed_pc=0x0c05c9a6u; return 0; }
r[10]=r[4];
goto P_0c05c9a8;
P_0c05c9a8: /* original 22c9, guest PC 0x0c05c9a8 */
if(!s->budget--) { s->failed_pc=0x0c05c9a8u; return 0; }
r[2]&=r[12];
goto P_0c05c9aa;
P_0c05c9aa: /* original 69a3, guest PC 0x0c05c9aa */
if(!s->budget--) { s->failed_pc=0x0c05c9aau; return 0; }
r[9]=r[10];
goto P_0c05c9ac;
P_0c05c9ac: /* original 2a22, guest PC 0x0c05c9ac */
if(!s->budget--) { s->failed_pc=0x0c05c9acu; return 0; }
write(ram,r[10],r[2],4);
goto P_0c05c9ae;
P_0c05c9ae: /* original 68a3, guest PC 0x0c05c9ae */
if(!s->budget--) { s->failed_pc=0x0c05c9aeu; return 0; }
r[8]=r[10];
goto P_0c05c9b0;
P_0c05c9b0: /* original 50d4, guest PC 0x0c05c9b0 */
if(!s->budget--) { s->failed_pc=0x0c05c9b0u; return 0; }
r[0]=read(ram,r[13]+16,4);
goto P_0c05c9b2;
P_0c05c9b2: /* original 7904, guest PC 0x0c05c9b2 */
if(!s->budget--) { s->failed_pc=0x0c05c9b2u; return 0; }
r[9]+=0x00000004u;
goto P_0c05c9b4;
P_0c05c9b4: /* original 2b09, guest PC 0x0c05c9b4 */
if(!s->budget--) { s->failed_pc=0x0c05c9b4u; return 0; }
r[11]&=r[0];
goto P_0c05c9b6;
P_0c05c9b6: /* original 7808, guest PC 0x0c05c9b6 */
if(!s->budget--) { s->failed_pc=0x0c05c9b6u; return 0; }
r[8]+=0x00000008u;
goto P_0c05c9b8;
P_0c05c9b8: /* original 29b2, guest PC 0x0c05c9b8 */
if(!s->budget--) { s->failed_pc=0x0c05c9b8u; return 0; }
write(ram,r[9],r[11],4);
goto P_0c05c9ba;
P_0c05c9ba: /* original 50d4, guest PC 0x0c05c9ba */
if(!s->budget--) { s->failed_pc=0x0c05c9bau; return 0; }
r[0]=read(ram,r[13]+16,4);
goto P_0c05c9bc;
P_0c05c9bc: /* original c904, guest PC 0x0c05c9bc */
if(!s->budget--) { s->failed_pc=0x0c05c9bcu; return 0; }
r[0]&=4u;
goto P_0c05c9be;
P_0c05c9be: /* original 6ba3, guest PC 0x0c05c9be */
if(!s->budget--) { s->failed_pc=0x0c05c9beu; return 0; }
r[11]=r[10];
goto P_0c05c9c0;
P_0c05c9c0: /* original 2802, guest PC 0x0c05c9c0 */
if(!s->budget--) { s->failed_pc=0x0c05c9c0u; return 0; }
write(ram,r[8],r[0],4);
goto P_0c05c9c2;
P_0c05c9c2: /* original e200, guest PC 0x0c05c9c2 */
if(!s->budget--) { s->failed_pc=0x0c05c9c2u; return 0; }
r[2]=0x00000000u;
goto P_0c05c9c4;
P_0c05c9c4: /* original 50d4, guest PC 0x0c05c9c4 */
if(!s->budget--) { s->failed_pc=0x0c05c9c4u; return 0; }
r[0]=read(ram,r[13]+16,4);
goto P_0c05c9c6;
P_0c05c9c6: /* original 7b0c, guest PC 0x0c05c9c6 */
if(!s->budget--) { s->failed_pc=0x0c05c9c6u; return 0; }
r[11]+=0x0000000cu;
goto P_0c05c9c8;
P_0c05c9c8: /* original c908, guest PC 0x0c05c9c8 */
if(!s->budget--) { s->failed_pc=0x0c05c9c8u; return 0; }
r[0]&=8u;
goto P_0c05c9ca;
P_0c05c9ca: /* original 2b02, guest PC 0x0c05c9ca */
if(!s->budget--) { s->failed_pc=0x0c05c9cau; return 0; }
write(ram,r[11],r[0],4);
goto P_0c05c9cc;
P_0c05c9cc: /* original 2f26, guest PC 0x0c05c9cc */
if(!s->budget--) { s->failed_pc=0x0c05c9ccu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c9ce;
P_0c05c9ce: /* original 67b2, guest PC 0x0c05c9ce */
if(!s->budget--) { s->failed_pc=0x0c05c9ceu; return 0; }
tmp=read(ram,r[11],4);
r[7]=tmp;
goto P_0c05c9d0;
P_0c05c9d0: /* original 6682, guest PC 0x0c05c9d0 */
if(!s->budget--) { s->failed_pc=0x0c05c9d0u; return 0; }
tmp=read(ram,r[8],4);
r[6]=tmp;
goto P_0c05c9d2;
P_0c05c9d2: /* original 6592, guest PC 0x0c05c9d2 */
if(!s->budget--) { s->failed_pc=0x0c05c9d2u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c05c9d4;
P_0c05c9d4: /* original b412, guest PC 0x0c05c9d4 */
if(!s->budget--) { s->failed_pc=0x0c05c9d4u; return 0; }
target=code_base|0x0c05d1fcu; r[16]=code_base|0x0c05c9d8u;
tmp=read(ram,r[10],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05c9d8u) { target=s->pc; goto dispatch; }
goto P_0c05c9d8;
P_0c05c9d6: /* original 64a2, guest PC 0x0c05c9d6 */
if(!s->budget--) { s->failed_pc=0x0c05c9d6u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c05c9d8;
P_0c05c9d8: /* original 2fc6, guest PC 0x0c05c9d8 */
if(!s->budget--) { s->failed_pc=0x0c05c9d8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c9da;
P_0c05c9da: /* original e300, guest PC 0x0c05c9da */
if(!s->budget--) { s->failed_pc=0x0c05c9dau; return 0; }
r[3]=0x00000000u;
goto P_0c05c9dc;
P_0c05c9dc: /* original 2f36, guest PC 0x0c05c9dc */
if(!s->budget--) { s->failed_pc=0x0c05c9dcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c9de;
P_0c05c9de: /* original 67b2, guest PC 0x0c05c9de */
if(!s->budget--) { s->failed_pc=0x0c05c9deu; return 0; }
tmp=read(ram,r[11],4);
r[7]=tmp;
goto P_0c05c9e0;
P_0c05c9e0: /* original 6682, guest PC 0x0c05c9e0 */
if(!s->budget--) { s->failed_pc=0x0c05c9e0u; return 0; }
tmp=read(ram,r[8],4);
r[6]=tmp;
goto P_0c05c9e2;
P_0c05c9e2: /* original 6592, guest PC 0x0c05c9e2 */
if(!s->budget--) { s->failed_pc=0x0c05c9e2u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c05c9e4;
P_0c05c9e4: /* original b474, guest PC 0x0c05c9e4 */
if(!s->budget--) { s->failed_pc=0x0c05c9e4u; return 0; }
target=code_base|0x0c05d2d0u; r[16]=code_base|0x0c05c9e8u;
tmp=read(ram,r[10],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05c9e8u) { target=s->pc; goto dispatch; }
goto P_0c05c9e8;
P_0c05c9e6: /* original 64a2, guest PC 0x0c05c9e6 */
if(!s->budget--) { s->failed_pc=0x0c05c9e6u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c05c9e8;
P_0c05c9e8: /* original 7f0c, guest PC 0x0c05c9e8 */
if(!s->budget--) { s->failed_pc=0x0c05c9e8u; return 0; }
r[15]+=0x0000000cu;
goto P_0c05c9ea;
P_0c05c9ea: /* original 6d03, guest PC 0x0c05c9ea */
if(!s->budget--) { s->failed_pc=0x0c05c9eau; return 0; }
r[13]=r[0];
goto P_0c05c9ec;
P_0c05c9ec: /* original b5dc, guest PC 0x0c05c9ec */
if(!s->budget--) { s->failed_pc=0x0c05c9ecu; return 0; }
target=code_base|0x0c05d5a8u; r[16]=code_base|0x0c05c9f0u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05c9f0u) { target=s->pc; goto dispatch; }
goto P_0c05c9f0;
P_0c05c9ee: /* original 6403, guest PC 0x0c05c9ee */
if(!s->budget--) { s->failed_pc=0x0c05c9eeu; return 0; }
r[4]=r[0];
goto P_0c05c9f0;
P_0c05c9f0: /* original 9437, guest PC 0x0c05c9f0 */
if(!s->budget--) { s->failed_pc=0x0c05c9f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05ca62u,2);
goto P_0c05c9f2;
P_0c05c9f2: /* original e058, guest PC 0x0c05c9f2 */
if(!s->budget--) { s->failed_pc=0x0c05c9f2u; return 0; }
r[0]=0x00000058u;
goto P_0c05c9f4;
P_0c05c9f4: /* original d322, guest PC 0x0c05c9f4 */
if(!s->budget--) { s->failed_pc=0x0c05c9f4u; return 0; }
r[3]=read(ram,0x0c05ca80u,4);
goto P_0c05c9f6;
P_0c05c9f6: /* original 02ee, guest PC 0x0c05c9f6 */
if(!s->budget--) { s->failed_pc=0x0c05c9f6u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c05c9f8;
P_0c05c9f8: /* original 4201, guest PC 0x0c05c9f8 */
if(!s->budget--) { s->failed_pc=0x0c05c9f8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]>>=1;
goto P_0c05c9fa;
P_0c05c9fa: /* original 0e26, guest PC 0x0c05c9fa */
if(!s->budget--) { s->failed_pc=0x0c05c9fau; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c05c9fc;
P_0c05c9fc: /* original 56e9, guest PC 0x0c05c9fc */
if(!s->budget--) { s->failed_pc=0x0c05c9fcu; return 0; }
r[6]=read(ram,r[14]+36,4);
goto P_0c05c9fe;
P_0c05c9fe: /* original 430b, guest PC 0x0c05c9fe */
if(!s->budget--) { s->failed_pc=0x0c05c9feu; return 0; }
target=r[3];
r[16]=code_base|0x0c05ca02u;
r[5]=read(ram,r[14]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05ca02u) { target=s->pc; goto dispatch; }
goto P_0c05ca02;
P_0c05ca00: /* original 55e6, guest PC 0x0c05ca00 */
if(!s->budget--) { s->failed_pc=0x0c05ca00u; return 0; }
r[5]=read(ram,r[14]+24,4);
goto P_0c05ca02;
P_0c05ca02: /* original e060, guest PC 0x0c05ca02 */
if(!s->budget--) { s->failed_pc=0x0c05ca02u; return 0; }
r[0]=0x00000060u;
goto P_0c05ca04;
P_0c05ca04: /* original d31f, guest PC 0x0c05ca04 */
if(!s->budget--) { s->failed_pc=0x0c05ca04u; return 0; }
r[3]=read(ram,0x0c05ca84u,4);
goto P_0c05ca06;
P_0c05ca06: /* original 04ee, guest PC 0x0c05ca06 */
if(!s->budget--) { s->failed_pc=0x0c05ca06u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c05ca08;
P_0c05ca08: /* original 644b, guest PC 0x0c05ca08 */
if(!s->budget--) { s->failed_pc=0x0c05ca08u; return 0; }
r[4]=0u-r[4];
goto P_0c05ca0a;
P_0c05ca0a: /* original 343c, guest PC 0x0c05ca0a */
if(!s->budget--) { s->failed_pc=0x0c05ca0au; return 0; }
r[4]+=r[3];
goto P_0c05ca0c;
P_0c05ca0c: /* original e058, guest PC 0x0c05ca0c */
if(!s->budget--) { s->failed_pc=0x0c05ca0cu; return 0; }
r[0]=0x00000058u;
goto P_0c05ca0e;
P_0c05ca0e: /* original 02ee, guest PC 0x0c05ca0e */
if(!s->budget--) { s->failed_pc=0x0c05ca0eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c05ca10;
P_0c05ca10: /* original 3246, guest PC 0x0c05ca10 */
if(!s->budget--) { s->failed_pc=0x0c05ca10u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[4])!=0);
goto P_0c05ca12;
P_0c05ca12: /* original 8b00, guest PC 0x0c05ca12 */
if(!s->budget--) { s->failed_pc=0x0c05ca12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05ca16; }
goto P_0c05ca14;
P_0c05ca14: /* original 0e46, guest PC 0x0c05ca14 */
if(!s->budget--) { s->failed_pc=0x0c05ca14u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c05ca16;
P_0c05ca16: /* original d61c, guest PC 0x0c05ca16 */
if(!s->budget--) { s->failed_pc=0x0c05ca16u; return 0; }
r[6]=read(ram,0x0c05ca88u,4);
goto P_0c05ca18;
P_0c05ca18: /* original d31c, guest PC 0x0c05ca18 */
if(!s->budget--) { s->failed_pc=0x0c05ca18u; return 0; }
r[3]=read(ram,0x0c05ca8cu,4);
goto P_0c05ca1a;
P_0c05ca1a: /* original 6563, guest PC 0x0c05ca1a */
if(!s->budget--) { s->failed_pc=0x0c05ca1au; return 0; }
r[5]=r[6];
goto P_0c05ca1c;
P_0c05ca1c: /* original 75fc, guest PC 0x0c05ca1c */
if(!s->budget--) { s->failed_pc=0x0c05ca1cu; return 0; }
r[5]+=0xfffffffcu;
goto P_0c05ca1e;
P_0c05ca1e: /* original 430b, guest PC 0x0c05ca1e */
if(!s->budget--) { s->failed_pc=0x0c05ca1eu; return 0; }
target=r[3];
r[16]=code_base|0x0c05ca22u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05ca22u) { target=s->pc; goto dispatch; }
goto P_0c05ca22;
P_0c05ca20: /* original 04ee, guest PC 0x0c05ca20 */
if(!s->budget--) { s->failed_pc=0x0c05ca20u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c05ca22;
P_0c05ca22: /* original 6b03, guest PC 0x0c05ca22 */
if(!s->budget--) { s->failed_pc=0x0c05ca22u; return 0; }
r[11]=r[0];
goto P_0c05ca24;
P_0c05ca24: /* original 2bb8, guest PC 0x0c05ca24 */
if(!s->budget--) { s->failed_pc=0x0c05ca24u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c05ca26;
P_0c05ca26: /* original 8b46, guest PC 0x0c05ca26 */
if(!s->budget--) { s->failed_pc=0x0c05ca26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05cab6; }
goto P_0c05ca28;
P_0c05ca28: /* original d319, guest PC 0x0c05ca28 */
if(!s->budget--) { s->failed_pc=0x0c05ca28u; return 0; }
r[3]=read(ram,0x0c05ca90u,4);
goto P_0c05ca2a;
P_0c05ca2a: /* original e058, guest PC 0x0c05ca2a */
if(!s->budget--) { s->failed_pc=0x0c05ca2au; return 0; }
r[0]=0x00000058u;
goto P_0c05ca2c;
P_0c05ca2c: /* original 02ee, guest PC 0x0c05ca2c */
if(!s->budget--) { s->failed_pc=0x0c05ca2cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c05ca2e;
P_0c05ca2e: /* original 2322, guest PC 0x0c05ca2e */
if(!s->budget--) { s->failed_pc=0x0c05ca2eu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c05ca30;
P_0c05ca30: /* original d718, guest PC 0x0c05ca30 */
if(!s->budget--) { s->failed_pc=0x0c05ca30u; return 0; }
r[7]=read(ram,0x0c05ca94u,4);
goto P_0c05ca32;
P_0c05ca32: /* original e100, guest PC 0x0c05ca32 */
if(!s->budget--) { s->failed_pc=0x0c05ca32u; return 0; }
r[1]=0x00000000u;
goto P_0c05ca34;
P_0c05ca34: /* original 2f16, guest PC 0x0c05ca34 */
if(!s->budget--) { s->failed_pc=0x0c05ca34u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ca36;
P_0c05ca36: /* original 53e6, guest PC 0x0c05ca36 */
if(!s->budget--) { s->failed_pc=0x0c05ca36u; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c05ca38;
P_0c05ca38: /* original 6337, guest PC 0x0c05ca38 */
if(!s->budget--) { s->failed_pc=0x0c05ca38u; return 0; }
r[3]=~r[3];
goto P_0c05ca3a;
P_0c05ca3a: /* original 2d39, guest PC 0x0c05ca3a */
if(!s->budget--) { s->failed_pc=0x0c05ca3au; return 0; }
r[13]&=r[3];
goto P_0c05ca3c;
P_0c05ca3c: /* original 2fd6, guest PC 0x0c05ca3c */
if(!s->budget--) { s->failed_pc=0x0c05ca3cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ca3e;
P_0c05ca3e: /* original 5773, guest PC 0x0c05ca3e */
if(!s->budget--) { s->failed_pc=0x0c05ca3eu; return 0; }
r[7]=read(ram,r[7]+12,4);
goto P_0c05ca40;
P_0c05ca40: /* original e3f9, guest PC 0x0c05ca40 */
if(!s->budget--) { s->failed_pc=0x0c05ca40u; return 0; }
r[3]=0xfffffff9u;
goto P_0c05ca42;
P_0c05ca42: /* original 473d, guest PC 0x0c05ca42 */
if(!s->budget--) { s->failed_pc=0x0c05ca42u; return 0; }
r[7]=(r[3]&0x80000000u)?((r[3]&31u)?r[7]>>((-r[3])&31u):0):r[7]<<(r[3]&31u);
goto P_0c05ca44;
P_0c05ca44: /* original d613, guest PC 0x0c05ca44 */
if(!s->budget--) { s->failed_pc=0x0c05ca44u; return 0; }
r[6]=read(ram,0x0c05ca94u,4);
goto P_0c05ca46;
P_0c05ca46: /* original 5662, guest PC 0x0c05ca46 */
if(!s->budget--) { s->failed_pc=0x0c05ca46u; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c05ca48;
P_0c05ca48: /* original 463d, guest PC 0x0c05ca48 */
if(!s->budget--) { s->failed_pc=0x0c05ca48u; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?r[6]>>((-r[3])&31u):0):r[6]<<(r[3]&31u);
goto P_0c05ca4a;
P_0c05ca4a: /* original d512, guest PC 0x0c05ca4a */
if(!s->budget--) { s->failed_pc=0x0c05ca4au; return 0; }
r[5]=read(ram,0x0c05ca94u,4);
goto P_0c05ca4c;
P_0c05ca4c: /* original 5551, guest PC 0x0c05ca4c */
if(!s->budget--) { s->failed_pc=0x0c05ca4cu; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c05ca4e;
P_0c05ca4e: /* original 453d, guest PC 0x0c05ca4e */
if(!s->budget--) { s->failed_pc=0x0c05ca4eu; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c05ca50;
P_0c05ca50: /* original d410, guest PC 0x0c05ca50 */
if(!s->budget--) { s->failed_pc=0x0c05ca50u; return 0; }
r[4]=read(ram,0x0c05ca94u,4);
goto P_0c05ca52;
P_0c05ca52: /* original 6442, guest PC 0x0c05ca52 */
if(!s->budget--) { s->failed_pc=0x0c05ca52u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05ca54;
P_0c05ca54: /* original d210, guest PC 0x0c05ca54 */
if(!s->budget--) { s->failed_pc=0x0c05ca54u; return 0; }
r[2]=read(ram,0x0c05ca98u,4);
goto P_0c05ca56;
P_0c05ca56: /* original 420b, guest PC 0x0c05ca56 */
if(!s->budget--) { s->failed_pc=0x0c05ca56u; return 0; }
target=r[2];
r[16]=code_base|0x0c05ca5au;
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05ca5au) { target=s->pc; goto dispatch; }
goto P_0c05ca5a;
P_0c05ca58: /* original 443d, guest PC 0x0c05ca58 */
if(!s->budget--) { s->failed_pc=0x0c05ca58u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c05ca5a;
P_0c05ca5a: /* original 7f08, guest PC 0x0c05ca5a */
if(!s->budget--) { s->failed_pc=0x0c05ca5au; return 0; }
r[15]+=0x00000008u;
goto P_0c05ca5c;
P_0c05ca5c: /* original d307, guest PC 0x0c05ca5c */
if(!s->budget--) { s->failed_pc=0x0c05ca5cu; return 0; }
r[3]=read(ram,0x0c05ca7cu,4);
goto P_0c05ca5e;
P_0c05ca5e: /* original a02a, guest PC 0x0c05ca5e */
if(!s->budget--) { s->failed_pc=0x0c05ca5eu; return 0; }
write(ram,r[3],r[12],4);
goto P_0c05cab6;
P_0c05ca60: /* original 23c2, guest PC 0x0c05ca60 */
if(!s->budget--) { s->failed_pc=0x0c05ca60u; return 0; }
write(ram,r[3],r[12],4);
if(!vf3_matrix_family(0x0c05ca62u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05ca62u; return 0; } return 1;
P_0c05ca9c: /* original 9482, guest PC 0x0c05ca9c */
if(!s->budget--) { s->failed_pc=0x0c05ca9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05cba4u,2);
goto P_0c05ca9e;
P_0c05ca9e: /* original b7c6, guest PC 0x0c05ca9e */
if(!s->budget--) { s->failed_pc=0x0c05ca9eu; return 0; }
target=code_base|0x0c05da2eu; r[16]=code_base|0x0c05caa2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05caa2u) { target=s->pc; goto dispatch; }
goto P_0c05caa2;
P_0c05caa0: /* original 0009, guest PC 0x0c05caa0 */
if(!s->budget--) { s->failed_pc=0x0c05caa0u; return 0; }
goto P_0c05caa2;
P_0c05caa2: /* original 9280, guest PC 0x0c05caa2 */
if(!s->budget--) { s->failed_pc=0x0c05caa2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05cba6u,2);
goto P_0c05caa4;
P_0c05caa4: /* original 3020, guest PC 0x0c05caa4 */
if(!s->budget--) { s->failed_pc=0x0c05caa4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[2])!=0);
goto P_0c05caa6;
P_0c05caa6: /* original 8b06, guest PC 0x0c05caa6 */
if(!s->budget--) { s->failed_pc=0x0c05caa6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05cab6; }
goto P_0c05caa8;
P_0c05caa8: /* original d43f, guest PC 0x0c05caa8 */
if(!s->budget--) { s->failed_pc=0x0c05caa8u; return 0; }
r[4]=read(ram,0x0c05cba8u,4);
goto P_0c05caaa;
P_0c05caaa: /* original b7c6, guest PC 0x0c05caaa */
if(!s->budget--) { s->failed_pc=0x0c05caaau; return 0; }
target=code_base|0x0c05da3au; r[16]=code_base|0x0c05caaeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05caaeu) { target=s->pc; goto dispatch; }
goto P_0c05caae;
P_0c05caac: /* original 0009, guest PC 0x0c05caac */
if(!s->budget--) { s->failed_pc=0x0c05caacu; return 0; }
goto P_0c05caae;
P_0c05caae: /* original e054, guest PC 0x0c05caae */
if(!s->budget--) { s->failed_pc=0x0c05caaeu; return 0; }
r[0]=0x00000054u;
goto P_0c05cab0;
P_0c05cab0: /* original b716, guest PC 0x0c05cab0 */
if(!s->budget--) { s->failed_pc=0x0c05cab0u; return 0; }
target=code_base|0x0c05d8e0u; r[16]=code_base|0x0c05cab4u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05cab4u) { target=s->pc; goto dispatch; }
goto P_0c05cab4;
P_0c05cab2: /* original 04ee, guest PC 0x0c05cab2 */
if(!s->budget--) { s->failed_pc=0x0c05cab2u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c05cab4;
P_0c05cab4: /* original 6b03, guest PC 0x0c05cab4 */
if(!s->budget--) { s->failed_pc=0x0c05cab4u; return 0; }
r[11]=r[0];
goto P_0c05cab6;
P_0c05cab6: /* original 60b3, guest PC 0x0c05cab6 */
if(!s->budget--) { s->failed_pc=0x0c05cab6u; return 0; }
r[0]=r[11];
goto P_0c05cab8;
P_0c05cab8: /* original 0009, guest PC 0x0c05cab8 */
if(!s->budget--) { s->failed_pc=0x0c05cab8u; return 0; }
goto P_0c05caba;
P_0c05caba: /* original 7f10, guest PC 0x0c05caba */
if(!s->budget--) { s->failed_pc=0x0c05cabau; return 0; }
r[15]+=0x00000010u;
goto P_0c05cabc;
P_0c05cabc: /* original 4f26, guest PC 0x0c05cabc */
if(!s->budget--) { s->failed_pc=0x0c05cabcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05cabe;
P_0c05cabe: /* original 68f6, guest PC 0x0c05cabe */
if(!s->budget--) { s->failed_pc=0x0c05cabeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05cac0;
P_0c05cac0: /* original 69f6, guest PC 0x0c05cac0 */
if(!s->budget--) { s->failed_pc=0x0c05cac0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05cac2;
P_0c05cac2: /* original 6af6, guest PC 0x0c05cac2 */
if(!s->budget--) { s->failed_pc=0x0c05cac2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05cac4;
P_0c05cac4: /* original 6bf6, guest PC 0x0c05cac4 */
if(!s->budget--) { s->failed_pc=0x0c05cac4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05cac6;
P_0c05cac6: /* original 6cf6, guest PC 0x0c05cac6 */
if(!s->budget--) { s->failed_pc=0x0c05cac6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05cac8;
P_0c05cac8: /* original 6df6, guest PC 0x0c05cac8 */
if(!s->budget--) { s->failed_pc=0x0c05cac8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05caca;
P_0c05caca: /* original 000b, guest PC 0x0c05caca */
if(!s->budget--) { s->failed_pc=0x0c05cacau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05cacc: /* original 6ef6, guest PC 0x0c05cacc */
if(!s->budget--) { s->failed_pc=0x0c05caccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05caceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05caceu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
