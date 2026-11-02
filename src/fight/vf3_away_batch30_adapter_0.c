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
int vf3_away_batch30_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042c1eu: goto P_0c042c1e;
case 0x0c042c20u: goto P_0c042c20;
case 0x0c042c22u: goto P_0c042c22;
case 0x0c042c24u: goto P_0c042c24;
case 0x0c042c26u: goto P_0c042c26;
case 0x0c042c28u: goto P_0c042c28;
case 0x0c042c2au: goto P_0c042c2a;
case 0x0c042c2cu: goto P_0c042c2c;
case 0x0c042c2eu: goto P_0c042c2e;
case 0x0c042c30u: goto P_0c042c30;
case 0x0c042c32u: goto P_0c042c32;
case 0x0c042c34u: goto P_0c042c34;
case 0x0c042c36u: goto P_0c042c36;
case 0x0c042c38u: goto P_0c042c38;
case 0x0c042c3au: goto P_0c042c3a;
case 0x0c042c3cu: goto P_0c042c3c;
case 0x0c042c3eu: goto P_0c042c3e;
case 0x0c042c40u: goto P_0c042c40;
case 0x0c042c42u: goto P_0c042c42;
case 0x0c042c44u: goto P_0c042c44;
case 0x0c042c46u: goto P_0c042c46;
case 0x0c042c48u: goto P_0c042c48;
case 0x0c042c4au: goto P_0c042c4a;
case 0x0c042c4cu: goto P_0c042c4c;
case 0x0c042c4eu: goto P_0c042c4e;
case 0x0c042c50u: goto P_0c042c50;
case 0x0c042c52u: goto P_0c042c52;
case 0x0c042c54u: goto P_0c042c54;
case 0x0c042c56u: goto P_0c042c56;
case 0x0c042c58u: goto P_0c042c58;
case 0x0c042c5au: goto P_0c042c5a;
case 0x0c042c5cu: goto P_0c042c5c;
case 0x0c042c5eu: goto P_0c042c5e;
case 0x0c042c60u: goto P_0c042c60;
case 0x0c042c62u: goto P_0c042c62;
case 0x0c042c64u: goto P_0c042c64;
case 0x0c042c66u: goto P_0c042c66;
case 0x0c042c68u: goto P_0c042c68;
case 0x0c042c6au: goto P_0c042c6a;
case 0x0c042c6cu: goto P_0c042c6c;
case 0x0c042c6eu: goto P_0c042c6e;
case 0x0c042c70u: goto P_0c042c70;
case 0x0c042c72u: goto P_0c042c72;
case 0x0c042c74u: goto P_0c042c74;
case 0x0c042c76u: goto P_0c042c76;
case 0x0c042c78u: goto P_0c042c78;
case 0x0c042c7au: goto P_0c042c7a;
case 0x0c042c7cu: goto P_0c042c7c;
case 0x0c042c7eu: goto P_0c042c7e;
case 0x0c042c80u: goto P_0c042c80;
case 0x0c042c82u: goto P_0c042c82;
case 0x0c042c84u: goto P_0c042c84;
case 0x0c042c86u: goto P_0c042c86;
case 0x0c042c88u: goto P_0c042c88;
case 0x0c042c8au: goto P_0c042c8a;
case 0x0c042c8cu: goto P_0c042c8c;
case 0x0c042c8eu: goto P_0c042c8e;
case 0x0c042c90u: goto P_0c042c90;
case 0x0c042c92u: goto P_0c042c92;
case 0x0c042c94u: goto P_0c042c94;
case 0x0c042c96u: goto P_0c042c96;
case 0x0c042c98u: goto P_0c042c98;
case 0x0c042c9au: goto P_0c042c9a;
case 0x0c042c9cu: goto P_0c042c9c;
case 0x0c042c9eu: goto P_0c042c9e;
case 0x0c042ca0u: goto P_0c042ca0;
case 0x0c042ca2u: goto P_0c042ca2;
case 0x0c042ca4u: goto P_0c042ca4;
case 0x0c042ca6u: goto P_0c042ca6;
case 0x0c042ca8u: goto P_0c042ca8;
case 0x0c042caau: goto P_0c042caa;
case 0x0c042cacu: goto P_0c042cac;
case 0x0c042caeu: goto P_0c042cae;
case 0x0c042cb0u: goto P_0c042cb0;
case 0x0c042cb2u: goto P_0c042cb2;
case 0x0c042cb4u: goto P_0c042cb4;
case 0x0c042cb6u: goto P_0c042cb6;
case 0x0c042cb8u: goto P_0c042cb8;
case 0x0c042cbau: goto P_0c042cba;
case 0x0c042cbcu: goto P_0c042cbc;
case 0x0c042cbeu: goto P_0c042cbe;
case 0x0c042cc0u: goto P_0c042cc0;
case 0x0c042cc2u: goto P_0c042cc2;
case 0x0c042cc4u: goto P_0c042cc4;
case 0x0c042cc6u: goto P_0c042cc6;
case 0x0c042cc8u: goto P_0c042cc8;
case 0x0c042ccau: goto P_0c042cca;
case 0x0c05fc9au: goto P_0c05fc9a;
case 0x0c05fc9cu: goto P_0c05fc9c;
case 0x0c05fc9eu: goto P_0c05fc9e;
case 0x0c060030u: goto P_0c060030;
case 0x0c060032u: goto P_0c060032;
case 0x0c060034u: goto P_0c060034;
case 0x0c060036u: goto P_0c060036;
case 0x0c060038u: goto P_0c060038;
case 0x0c06003au: goto P_0c06003a;
case 0x0c06003cu: goto P_0c06003c;
case 0x0c06003eu: goto P_0c06003e;
case 0x0c060040u: goto P_0c060040;
case 0x0c060042u: goto P_0c060042;
case 0x0c060044u: goto P_0c060044;
case 0x0c060046u: goto P_0c060046;
case 0x0c060048u: goto P_0c060048;
case 0x0c06004au: goto P_0c06004a;
case 0x0c06004cu: goto P_0c06004c;
case 0x0c06004eu: goto P_0c06004e;
case 0x0c060050u: goto P_0c060050;
case 0x0c060052u: goto P_0c060052;
case 0x0c060054u: goto P_0c060054;
case 0x0c060056u: goto P_0c060056;
case 0x0c060058u: goto P_0c060058;
case 0x0c06005au: goto P_0c06005a;
case 0x0c06005cu: goto P_0c06005c;
case 0x0c06005eu: goto P_0c06005e;
case 0x0c060060u: goto P_0c060060;
case 0x0c060062u: goto P_0c060062;
case 0x0c060064u: goto P_0c060064;
case 0x0c060066u: goto P_0c060066;
case 0x0c060068u: goto P_0c060068;
case 0x0c06006au: goto P_0c06006a;
case 0x0c06006cu: goto P_0c06006c;
case 0x0c06006eu: goto P_0c06006e;
case 0x0c060070u: goto P_0c060070;
case 0x0c060072u: goto P_0c060072;
case 0x0c060074u: goto P_0c060074;
case 0x0c060076u: goto P_0c060076;
case 0x0c060078u: goto P_0c060078;
case 0x0c06007au: goto P_0c06007a;
case 0x0c06007cu: goto P_0c06007c;
case 0x0c06007eu: goto P_0c06007e;
case 0x0c060080u: goto P_0c060080;
case 0x0c060082u: goto P_0c060082;
case 0x0c060084u: goto P_0c060084;
case 0x0c060086u: goto P_0c060086;
case 0x0c060088u: goto P_0c060088;
case 0x0c06008au: goto P_0c06008a;
case 0x0c06008cu: goto P_0c06008c;
case 0x0c06008eu: goto P_0c06008e;
case 0x0c060090u: goto P_0c060090;
case 0x0c060092u: goto P_0c060092;
case 0x0c060094u: goto P_0c060094;
case 0x0c060096u: goto P_0c060096;
case 0x0c060098u: goto P_0c060098;
case 0x0c06009au: goto P_0c06009a;
case 0x0c06009cu: goto P_0c06009c;
case 0x0c06009eu: goto P_0c06009e;
case 0x0c0600a0u: goto P_0c0600a0;
case 0x0c0600a2u: goto P_0c0600a2;
case 0x0c0600a4u: goto P_0c0600a4;
case 0x0c0600a6u: goto P_0c0600a6;
case 0x0c0600a8u: goto P_0c0600a8;
case 0x0c0600aau: goto P_0c0600aa;
case 0x0c0600acu: goto P_0c0600ac;
case 0x0c0600aeu: goto P_0c0600ae;
case 0x0c0600b0u: goto P_0c0600b0;
case 0x0c0600b2u: goto P_0c0600b2;
case 0x0c0600b4u: goto P_0c0600b4;
case 0x0c0600b6u: goto P_0c0600b6;
case 0x0c0600b8u: goto P_0c0600b8;
case 0x0c0600bau: goto P_0c0600ba;
case 0x0c0600bcu: goto P_0c0600bc;
case 0x0c0600beu: goto P_0c0600be;
case 0x0c0600c0u: goto P_0c0600c0;
case 0x0c0600c2u: goto P_0c0600c2;
case 0x0c0600c4u: goto P_0c0600c4;
case 0x0c0600c6u: goto P_0c0600c6;
case 0x0c0600c8u: goto P_0c0600c8;
case 0x0c0600cau: goto P_0c0600ca;
case 0x0c0600ccu: goto P_0c0600cc;
case 0x0c0600ceu: goto P_0c0600ce;
case 0x0c0600d0u: goto P_0c0600d0;
case 0x0c0600d2u: goto P_0c0600d2;
case 0x0c0600d4u: goto P_0c0600d4;
case 0x0c0600d6u: goto P_0c0600d6;
case 0x0c0600d8u: goto P_0c0600d8;
case 0x0c0600dau: goto P_0c0600da;
case 0x0c0600dcu: goto P_0c0600dc;
case 0x0c0600deu: goto P_0c0600de;
case 0x0c0600e0u: goto P_0c0600e0;
case 0x0c0600e2u: goto P_0c0600e2;
case 0x0c0600e4u: goto P_0c0600e4;
case 0x0c0600e6u: goto P_0c0600e6;
case 0x0c0600e8u: goto P_0c0600e8;
case 0x0c0600eau: goto P_0c0600ea;
case 0x0c0600ecu: goto P_0c0600ec;
case 0x0c0600eeu: goto P_0c0600ee;
case 0x0c0600f0u: goto P_0c0600f0;
case 0x0c0600f2u: goto P_0c0600f2;
case 0x0c0600f4u: goto P_0c0600f4;
case 0x0c0600f6u: goto P_0c0600f6;
case 0x0c0600f8u: goto P_0c0600f8;
case 0x0c0600fau: goto P_0c0600fa;
case 0x0c0600fcu: goto P_0c0600fc;
case 0x0c0600feu: goto P_0c0600fe;
case 0x0c060100u: goto P_0c060100;
case 0x0c060102u: goto P_0c060102;
case 0x0c060104u: goto P_0c060104;
case 0x0c060106u: goto P_0c060106;
case 0x0c060108u: goto P_0c060108;
case 0x0c06010au: goto P_0c06010a;
case 0x0c06010cu: goto P_0c06010c;
case 0x0c06010eu: goto P_0c06010e;
case 0x0c060110u: goto P_0c060110;
case 0x0c060112u: goto P_0c060112;
case 0x0c060114u: goto P_0c060114;
case 0x0c060116u: goto P_0c060116;
case 0x0c060118u: goto P_0c060118;
case 0x0c06011au: goto P_0c06011a;
case 0x0c06011cu: goto P_0c06011c;
case 0x0c06011eu: goto P_0c06011e;
case 0x0c060120u: goto P_0c060120;
case 0x0c060122u: goto P_0c060122;
case 0x0c060124u: goto P_0c060124;
case 0x0c060126u: goto P_0c060126;
case 0x0c060128u: goto P_0c060128;
case 0x0c06012au: goto P_0c06012a;
case 0x0c06012cu: goto P_0c06012c;
case 0x0c06012eu: goto P_0c06012e;
case 0x0c060130u: goto P_0c060130;
case 0x0c060132u: goto P_0c060132;
case 0x0c060134u: goto P_0c060134;
case 0x0c060136u: goto P_0c060136;
case 0x0c060138u: goto P_0c060138;
case 0x0c06013au: goto P_0c06013a;
case 0x0c06013cu: goto P_0c06013c;
case 0x0c06013eu: goto P_0c06013e;
case 0x0c060140u: goto P_0c060140;
case 0x0c060142u: goto P_0c060142;
case 0x0c060144u: goto P_0c060144;
case 0x0c060146u: goto P_0c060146;
case 0x0c060148u: goto P_0c060148;
case 0x0c06014au: goto P_0c06014a;
case 0x0c06014cu: goto P_0c06014c;
case 0x0c06014eu: goto P_0c06014e;
case 0x0c060150u: goto P_0c060150;
case 0x0c060152u: goto P_0c060152;
case 0x0c060154u: goto P_0c060154;
case 0x0c060156u: goto P_0c060156;
case 0x0c060158u: goto P_0c060158;
case 0x0c06015au: goto P_0c06015a;
case 0x0c06015cu: goto P_0c06015c;
case 0x0c06015eu: goto P_0c06015e;
case 0x0c060160u: goto P_0c060160;
case 0x0c060162u: goto P_0c060162;
case 0x0c060164u: goto P_0c060164;
case 0x0c060166u: goto P_0c060166;
case 0x0c060168u: goto P_0c060168;
case 0x0c06016au: goto P_0c06016a;
case 0x0c06016cu: goto P_0c06016c;
case 0x0c06016eu: goto P_0c06016e;
case 0x0c060170u: goto P_0c060170;
case 0x0c060172u: goto P_0c060172;
case 0x0c060174u: goto P_0c060174;
case 0x0c060176u: goto P_0c060176;
case 0x0c060178u: goto P_0c060178;
case 0x0c06017au: goto P_0c06017a;
case 0x0c06017cu: goto P_0c06017c;
case 0x0c06017eu: goto P_0c06017e;
case 0x0c060180u: goto P_0c060180;
case 0x0c060182u: goto P_0c060182;
default: return vf3_matrix_family(target,s,ram);
}
P_0c042c1e: /* original 4f22, guest PC 0x0c042c1e */
if(!s->budget--) { s->failed_pc=0x0c042c1eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c042c20;
P_0c042c20: /* original 2008, guest PC 0x0c042c20 */
if(!s->budget--) { s->failed_pc=0x0c042c20u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042c22;
P_0c042c22: /* original 2f26, guest PC 0x0c042c22 */
if(!s->budget--) { s->failed_pc=0x0c042c22u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042c24;
P_0c042c24: /* original 8d4c, guest PC 0x0c042c24 */
if(!s->budget--) { s->failed_pc=0x0c042c24u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042cc0; }
goto P_0c042c28;
P_0c042c26: /* original 0009, guest PC 0x0c042c26 */
if(!s->budget--) { s->failed_pc=0x0c042c26u; return 0; }
goto P_0c042c28;
P_0c042c28: /* original 2f36, guest PC 0x0c042c28 */
if(!s->budget--) { s->failed_pc=0x0c042c28u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042c2a;
P_0c042c2a: /* original e200, guest PC 0x0c042c2a */
if(!s->budget--) { s->failed_pc=0x0c042c2au; return 0; }
r[2]=0x00000000u;
goto P_0c042c2c;
P_0c042c2c: /* original 2127, guest PC 0x0c042c2c */
if(!s->budget--) { s->failed_pc=0x0c042c2cu; return 0; }
r[17]=(r[17]&~0x301u)|((r[1]>>31)<<8)|((r[2]>>31)<<9)|(((r[1]^r[2])>>31)&1u);
goto P_0c042c2e;
P_0c042c2e: /* original 333a, guest PC 0x0c042c2e */
if(!s->budget--) { s->failed_pc=0x0c042c2eu; return 0; }
wide=(uint64_t)r[3]-r[3]-(r[17]&1u); r[3]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c30;
P_0c042c30: /* original 312a, guest PC 0x0c042c30 */
if(!s->budget--) { s->failed_pc=0x0c042c30u; return 0; }
wide=(uint64_t)r[1]-r[2]-(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c32;
P_0c042c32: /* original 2307, guest PC 0x0c042c32 */
if(!s->budget--) { s->failed_pc=0x0c042c32u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042c34;
P_0c042c34: /* original 4124, guest PC 0x0c042c34 */
if(!s->budget--) { s->failed_pc=0x0c042c34u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c36;
P_0c042c36: /* original 3304, guest PC 0x0c042c36 */
if(!s->budget--) { s->failed_pc=0x0c042c36u; return 0; }
divide_step(s,3,0);
goto P_0c042c38;
P_0c042c38: /* original 4124, guest PC 0x0c042c38 */
if(!s->budget--) { s->failed_pc=0x0c042c38u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3a;
P_0c042c3a: /* original 3304, guest PC 0x0c042c3a */
if(!s->budget--) { s->failed_pc=0x0c042c3au; return 0; }
divide_step(s,3,0);
goto P_0c042c3c;
P_0c042c3c: /* original 4124, guest PC 0x0c042c3c */
if(!s->budget--) { s->failed_pc=0x0c042c3cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3e;
P_0c042c3e: /* original 3304, guest PC 0x0c042c3e */
if(!s->budget--) { s->failed_pc=0x0c042c3eu; return 0; }
divide_step(s,3,0);
goto P_0c042c40;
P_0c042c40: /* original 4124, guest PC 0x0c042c40 */
if(!s->budget--) { s->failed_pc=0x0c042c40u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c42;
P_0c042c42: /* original 3304, guest PC 0x0c042c42 */
if(!s->budget--) { s->failed_pc=0x0c042c42u; return 0; }
divide_step(s,3,0);
goto P_0c042c44;
P_0c042c44: /* original 4124, guest PC 0x0c042c44 */
if(!s->budget--) { s->failed_pc=0x0c042c44u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c46;
P_0c042c46: /* original 3304, guest PC 0x0c042c46 */
if(!s->budget--) { s->failed_pc=0x0c042c46u; return 0; }
divide_step(s,3,0);
goto P_0c042c48;
P_0c042c48: /* original 4124, guest PC 0x0c042c48 */
if(!s->budget--) { s->failed_pc=0x0c042c48u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4a;
P_0c042c4a: /* original 3304, guest PC 0x0c042c4a */
if(!s->budget--) { s->failed_pc=0x0c042c4au; return 0; }
divide_step(s,3,0);
goto P_0c042c4c;
P_0c042c4c: /* original 4124, guest PC 0x0c042c4c */
if(!s->budget--) { s->failed_pc=0x0c042c4cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4e;
P_0c042c4e: /* original 3304, guest PC 0x0c042c4e */
if(!s->budget--) { s->failed_pc=0x0c042c4eu; return 0; }
divide_step(s,3,0);
goto P_0c042c50;
P_0c042c50: /* original 4124, guest PC 0x0c042c50 */
if(!s->budget--) { s->failed_pc=0x0c042c50u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c52;
P_0c042c52: /* original 3304, guest PC 0x0c042c52 */
if(!s->budget--) { s->failed_pc=0x0c042c52u; return 0; }
divide_step(s,3,0);
goto P_0c042c54;
P_0c042c54: /* original 4124, guest PC 0x0c042c54 */
if(!s->budget--) { s->failed_pc=0x0c042c54u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c56;
P_0c042c56: /* original 3304, guest PC 0x0c042c56 */
if(!s->budget--) { s->failed_pc=0x0c042c56u; return 0; }
divide_step(s,3,0);
goto P_0c042c58;
P_0c042c58: /* original 4124, guest PC 0x0c042c58 */
if(!s->budget--) { s->failed_pc=0x0c042c58u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5a;
P_0c042c5a: /* original 3304, guest PC 0x0c042c5a */
if(!s->budget--) { s->failed_pc=0x0c042c5au; return 0; }
divide_step(s,3,0);
goto P_0c042c5c;
P_0c042c5c: /* original 4124, guest PC 0x0c042c5c */
if(!s->budget--) { s->failed_pc=0x0c042c5cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5e;
P_0c042c5e: /* original 3304, guest PC 0x0c042c5e */
if(!s->budget--) { s->failed_pc=0x0c042c5eu; return 0; }
divide_step(s,3,0);
goto P_0c042c60;
P_0c042c60: /* original 4124, guest PC 0x0c042c60 */
if(!s->budget--) { s->failed_pc=0x0c042c60u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c62;
P_0c042c62: /* original 3304, guest PC 0x0c042c62 */
if(!s->budget--) { s->failed_pc=0x0c042c62u; return 0; }
divide_step(s,3,0);
goto P_0c042c64;
P_0c042c64: /* original 4124, guest PC 0x0c042c64 */
if(!s->budget--) { s->failed_pc=0x0c042c64u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c66;
P_0c042c66: /* original 3304, guest PC 0x0c042c66 */
if(!s->budget--) { s->failed_pc=0x0c042c66u; return 0; }
divide_step(s,3,0);
goto P_0c042c68;
P_0c042c68: /* original 4124, guest PC 0x0c042c68 */
if(!s->budget--) { s->failed_pc=0x0c042c68u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6a;
P_0c042c6a: /* original 3304, guest PC 0x0c042c6a */
if(!s->budget--) { s->failed_pc=0x0c042c6au; return 0; }
divide_step(s,3,0);
goto P_0c042c6c;
P_0c042c6c: /* original 4124, guest PC 0x0c042c6c */
if(!s->budget--) { s->failed_pc=0x0c042c6cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6e;
P_0c042c6e: /* original 3304, guest PC 0x0c042c6e */
if(!s->budget--) { s->failed_pc=0x0c042c6eu; return 0; }
divide_step(s,3,0);
goto P_0c042c70;
P_0c042c70: /* original 4124, guest PC 0x0c042c70 */
if(!s->budget--) { s->failed_pc=0x0c042c70u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c72;
P_0c042c72: /* original 3304, guest PC 0x0c042c72 */
if(!s->budget--) { s->failed_pc=0x0c042c72u; return 0; }
divide_step(s,3,0);
goto P_0c042c74;
P_0c042c74: /* original 4124, guest PC 0x0c042c74 */
if(!s->budget--) { s->failed_pc=0x0c042c74u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c76;
P_0c042c76: /* original 3304, guest PC 0x0c042c76 */
if(!s->budget--) { s->failed_pc=0x0c042c76u; return 0; }
divide_step(s,3,0);
goto P_0c042c78;
P_0c042c78: /* original 4124, guest PC 0x0c042c78 */
if(!s->budget--) { s->failed_pc=0x0c042c78u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7a;
P_0c042c7a: /* original 3304, guest PC 0x0c042c7a */
if(!s->budget--) { s->failed_pc=0x0c042c7au; return 0; }
divide_step(s,3,0);
goto P_0c042c7c;
P_0c042c7c: /* original 4124, guest PC 0x0c042c7c */
if(!s->budget--) { s->failed_pc=0x0c042c7cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7e;
P_0c042c7e: /* original 3304, guest PC 0x0c042c7e */
if(!s->budget--) { s->failed_pc=0x0c042c7eu; return 0; }
divide_step(s,3,0);
goto P_0c042c80;
P_0c042c80: /* original 4124, guest PC 0x0c042c80 */
if(!s->budget--) { s->failed_pc=0x0c042c80u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c82;
P_0c042c82: /* original 3304, guest PC 0x0c042c82 */
if(!s->budget--) { s->failed_pc=0x0c042c82u; return 0; }
divide_step(s,3,0);
goto P_0c042c84;
P_0c042c84: /* original 4124, guest PC 0x0c042c84 */
if(!s->budget--) { s->failed_pc=0x0c042c84u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c86;
P_0c042c86: /* original 3304, guest PC 0x0c042c86 */
if(!s->budget--) { s->failed_pc=0x0c042c86u; return 0; }
divide_step(s,3,0);
goto P_0c042c88;
P_0c042c88: /* original 4124, guest PC 0x0c042c88 */
if(!s->budget--) { s->failed_pc=0x0c042c88u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8a;
P_0c042c8a: /* original 3304, guest PC 0x0c042c8a */
if(!s->budget--) { s->failed_pc=0x0c042c8au; return 0; }
divide_step(s,3,0);
goto P_0c042c8c;
P_0c042c8c: /* original 4124, guest PC 0x0c042c8c */
if(!s->budget--) { s->failed_pc=0x0c042c8cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8e;
P_0c042c8e: /* original 3304, guest PC 0x0c042c8e */
if(!s->budget--) { s->failed_pc=0x0c042c8eu; return 0; }
divide_step(s,3,0);
goto P_0c042c90;
P_0c042c90: /* original 4124, guest PC 0x0c042c90 */
if(!s->budget--) { s->failed_pc=0x0c042c90u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c92;
P_0c042c92: /* original 3304, guest PC 0x0c042c92 */
if(!s->budget--) { s->failed_pc=0x0c042c92u; return 0; }
divide_step(s,3,0);
goto P_0c042c94;
P_0c042c94: /* original 4124, guest PC 0x0c042c94 */
if(!s->budget--) { s->failed_pc=0x0c042c94u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c96;
P_0c042c96: /* original 3304, guest PC 0x0c042c96 */
if(!s->budget--) { s->failed_pc=0x0c042c96u; return 0; }
divide_step(s,3,0);
goto P_0c042c98;
P_0c042c98: /* original 4124, guest PC 0x0c042c98 */
if(!s->budget--) { s->failed_pc=0x0c042c98u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9a;
P_0c042c9a: /* original 3304, guest PC 0x0c042c9a */
if(!s->budget--) { s->failed_pc=0x0c042c9au; return 0; }
divide_step(s,3,0);
goto P_0c042c9c;
P_0c042c9c: /* original 4124, guest PC 0x0c042c9c */
if(!s->budget--) { s->failed_pc=0x0c042c9cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9e;
P_0c042c9e: /* original 3304, guest PC 0x0c042c9e */
if(!s->budget--) { s->failed_pc=0x0c042c9eu; return 0; }
divide_step(s,3,0);
goto P_0c042ca0;
P_0c042ca0: /* original 4124, guest PC 0x0c042ca0 */
if(!s->budget--) { s->failed_pc=0x0c042ca0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca2;
P_0c042ca2: /* original 3304, guest PC 0x0c042ca2 */
if(!s->budget--) { s->failed_pc=0x0c042ca2u; return 0; }
divide_step(s,3,0);
goto P_0c042ca4;
P_0c042ca4: /* original 4124, guest PC 0x0c042ca4 */
if(!s->budget--) { s->failed_pc=0x0c042ca4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca6;
P_0c042ca6: /* original 3304, guest PC 0x0c042ca6 */
if(!s->budget--) { s->failed_pc=0x0c042ca6u; return 0; }
divide_step(s,3,0);
goto P_0c042ca8;
P_0c042ca8: /* original 4124, guest PC 0x0c042ca8 */
if(!s->budget--) { s->failed_pc=0x0c042ca8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042caa;
P_0c042caa: /* original 3304, guest PC 0x0c042caa */
if(!s->budget--) { s->failed_pc=0x0c042caau; return 0; }
divide_step(s,3,0);
goto P_0c042cac;
P_0c042cac: /* original 4124, guest PC 0x0c042cac */
if(!s->budget--) { s->failed_pc=0x0c042cacu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cae;
P_0c042cae: /* original 3304, guest PC 0x0c042cae */
if(!s->budget--) { s->failed_pc=0x0c042caeu; return 0; }
divide_step(s,3,0);
goto P_0c042cb0;
P_0c042cb0: /* original 4124, guest PC 0x0c042cb0 */
if(!s->budget--) { s->failed_pc=0x0c042cb0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb2;
P_0c042cb2: /* original 3304, guest PC 0x0c042cb2 */
if(!s->budget--) { s->failed_pc=0x0c042cb2u; return 0; }
divide_step(s,3,0);
goto P_0c042cb4;
P_0c042cb4: /* original 4124, guest PC 0x0c042cb4 */
if(!s->budget--) { s->failed_pc=0x0c042cb4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb6;
P_0c042cb6: /* original 312e, guest PC 0x0c042cb6 */
if(!s->budget--) { s->failed_pc=0x0c042cb6u; return 0; }
wide=(uint64_t)r[1]+r[2]+(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042cb8;
P_0c042cb8: /* original 6013, guest PC 0x0c042cb8 */
if(!s->budget--) { s->failed_pc=0x0c042cb8u; return 0; }
r[0]=r[1];
goto P_0c042cba;
P_0c042cba: /* original 63f6, guest PC 0x0c042cba */
if(!s->budget--) { s->failed_pc=0x0c042cbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042cbc;
P_0c042cbc: /* original 000b, guest PC 0x0c042cbc */
if(!s->budget--) { s->failed_pc=0x0c042cbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042cbe: /* original 62f6, guest PC 0x0c042cbe */
if(!s->budget--) { s->failed_pc=0x0c042cbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c042cc0;
P_0c042cc0: /* original d102, guest PC 0x0c042cc0 */
if(!s->budget--) { s->failed_pc=0x0c042cc0u; return 0; }
r[1]=read(ram,0x0c042cccu,4);
goto P_0c042cc2;
P_0c042cc2: /* original d203, guest PC 0x0c042cc2 */
if(!s->budget--) { s->failed_pc=0x0c042cc2u; return 0; }
r[2]=read(ram,0x0c042cd0u,4);
goto P_0c042cc4;
P_0c042cc4: /* original e000, guest PC 0x0c042cc4 */
if(!s->budget--) { s->failed_pc=0x0c042cc4u; return 0; }
r[0]=0x00000000u;
goto P_0c042cc6;
P_0c042cc6: /* original 2122, guest PC 0x0c042cc6 */
if(!s->budget--) { s->failed_pc=0x0c042cc6u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042cc8;
P_0c042cc8: /* original 000b, guest PC 0x0c042cc8 */
if(!s->budget--) { s->failed_pc=0x0c042cc8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042cca: /* original 62f6, guest PC 0x0c042cca */
if(!s->budget--) { s->failed_pc=0x0c042ccau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042cccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042cccu; return 0; } return 1;
P_0c05fc9a: /* original d339, guest PC 0x0c05fc9a */
if(!s->budget--) { s->failed_pc=0x0c05fc9au; return 0; }
r[3]=read(ram,0x0c05fd80u,4);
goto P_0c05fc9c;
P_0c05fc9c: /* original 432b, guest PC 0x0c05fc9c */
if(!s->budget--) { s->failed_pc=0x0c05fc9cu; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c060d14u: return vf3_matrix_family(0x0c060d14u,s,ram);
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
P_0c05fc9e: /* original 0009, guest PC 0x0c05fc9e */
if(!s->budget--) { s->failed_pc=0x0c05fc9eu; return 0; }
if(!vf3_matrix_family(0x0c05fca0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05fca0u; return 0; } return 1;
P_0c060030: /* original 2fe6, guest PC 0x0c060030 */
if(!s->budget--) { s->failed_pc=0x0c060030u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060032;
P_0c060032: /* original e058, guest PC 0x0c060032 */
if(!s->budget--) { s->failed_pc=0x0c060032u; return 0; }
r[0]=0x00000058u;
goto P_0c060034;
P_0c060034: /* original 95a6, guest PC 0x0c060034 */
if(!s->budget--) { s->failed_pc=0x0c060034u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060184u,2);
goto P_0c060036;
P_0c060036: /* original 2fd6, guest PC 0x0c060036 */
if(!s->budget--) { s->failed_pc=0x0c060036u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060038;
P_0c060038: /* original 64f3, guest PC 0x0c060038 */
if(!s->budget--) { s->failed_pc=0x0c060038u; return 0; }
r[4]=r[15];
goto P_0c06003a;
P_0c06003a: /* original 7408, guest PC 0x0c06003a */
if(!s->budget--) { s->failed_pc=0x0c06003au; return 0; }
r[4]+=0x00000008u;
goto P_0c06003c;
P_0c06003c: /* original 034e, guest PC 0x0c06003c */
if(!s->budget--) { s->failed_pc=0x0c06003cu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c06003e;
P_0c06003e: /* original e054, guest PC 0x0c06003e */
if(!s->budget--) { s->failed_pc=0x0c06003eu; return 0; }
r[0]=0x00000054u;
goto P_0c060040;
P_0c060040: /* original 024e, guest PC 0x0c060040 */
if(!s->budget--) { s->failed_pc=0x0c060040u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c060042;
P_0c060042: /* original 2359, guest PC 0x0c060042 */
if(!s->budget--) { s->failed_pc=0x0c060042u; return 0; }
r[3]&=r[5];
goto P_0c060044;
P_0c060044: /* original 2259, guest PC 0x0c060044 */
if(!s->budget--) { s->failed_pc=0x0c060044u; return 0; }
r[2]&=r[5];
goto P_0c060046;
P_0c060046: /* original 4228, guest PC 0x0c060046 */
if(!s->budget--) { s->failed_pc=0x0c060046u; return 0; }
r[2]<<=16;
goto P_0c060048;
P_0c060048: /* original 232b, guest PC 0x0c060048 */
if(!s->budget--) { s->failed_pc=0x0c060048u; return 0; }
r[3]|=r[2];
goto P_0c06004a;
P_0c06004a: /* original d250, guest PC 0x0c06004a */
if(!s->budget--) { s->failed_pc=0x0c06004au; return 0; }
r[2]=read(ram,0x0c06018cu,4);
goto P_0c06004c;
P_0c06004c: /* original 2232, guest PC 0x0c06004c */
if(!s->budget--) { s->failed_pc=0x0c06004cu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c06004e;
P_0c06004e: /* original e060, guest PC 0x0c06004e */
if(!s->budget--) { s->failed_pc=0x0c06004eu; return 0; }
r[0]=0x00000060u;
goto P_0c060050;
P_0c060050: /* original 014e, guest PC 0x0c060050 */
if(!s->budget--) { s->failed_pc=0x0c060050u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c060052;
P_0c060052: /* original e05c, guest PC 0x0c060052 */
if(!s->budget--) { s->failed_pc=0x0c060052u; return 0; }
r[0]=0x0000005cu;
goto P_0c060054;
P_0c060054: /* original 034e, guest PC 0x0c060054 */
if(!s->budget--) { s->failed_pc=0x0c060054u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c060056;
P_0c060056: /* original 2159, guest PC 0x0c060056 */
if(!s->budget--) { s->failed_pc=0x0c060056u; return 0; }
r[1]&=r[5];
goto P_0c060058;
P_0c060058: /* original 2359, guest PC 0x0c060058 */
if(!s->budget--) { s->failed_pc=0x0c060058u; return 0; }
r[3]&=r[5];
goto P_0c06005a;
P_0c06005a: /* original 4328, guest PC 0x0c06005a */
if(!s->budget--) { s->failed_pc=0x0c06005au; return 0; }
r[3]<<=16;
goto P_0c06005c;
P_0c06005c: /* original 213b, guest PC 0x0c06005c */
if(!s->budget--) { s->failed_pc=0x0c06005cu; return 0; }
r[1]|=r[3];
goto P_0c06005e;
P_0c06005e: /* original d34c, guest PC 0x0c06005e */
if(!s->budget--) { s->failed_pc=0x0c06005eu; return 0; }
r[3]=read(ram,0x0c060190u,4);
goto P_0c060060;
P_0c060060: /* original 2312, guest PC 0x0c060060 */
if(!s->budget--) { s->failed_pc=0x0c060060u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c060062;
P_0c060062: /* original e50f, guest PC 0x0c060062 */
if(!s->budget--) { s->failed_pc=0x0c060062u; return 0; }
r[5]=0x0000000fu;
goto P_0c060064;
P_0c060064: /* original e61f, guest PC 0x0c060064 */
if(!s->budget--) { s->failed_pc=0x0c060064u; return 0; }
r[6]=0x0000001fu;
goto P_0c060066;
P_0c060066: /* original e048, guest PC 0x0c060066 */
if(!s->budget--) { s->failed_pc=0x0c060066u; return 0; }
r[0]=0x00000048u;
goto P_0c060068;
P_0c060068: /* original 024e, guest PC 0x0c060068 */
if(!s->budget--) { s->failed_pc=0x0c060068u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c06006a;
P_0c06006a: /* original e04c, guest PC 0x0c06006a */
if(!s->budget--) { s->failed_pc=0x0c06006au; return 0; }
r[0]=0x0000004cu;
goto P_0c06006c;
P_0c06006c: /* original 2259, guest PC 0x0c06006c */
if(!s->budget--) { s->failed_pc=0x0c06006cu; return 0; }
r[2]&=r[5];
goto P_0c06006e;
P_0c06006e: /* original 014e, guest PC 0x0c06006e */
if(!s->budget--) { s->failed_pc=0x0c06006eu; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c060070;
P_0c060070: /* original 2169, guest PC 0x0c060070 */
if(!s->budget--) { s->failed_pc=0x0c060070u; return 0; }
r[1]&=r[6];
goto P_0c060072;
P_0c060072: /* original 4108, guest PC 0x0c060072 */
if(!s->budget--) { s->failed_pc=0x0c060072u; return 0; }
r[1]<<=2;
goto P_0c060074;
P_0c060074: /* original 4108, guest PC 0x0c060074 */
if(!s->budget--) { s->failed_pc=0x0c060074u; return 0; }
r[1]<<=2;
goto P_0c060076;
P_0c060076: /* original 221b, guest PC 0x0c060076 */
if(!s->budget--) { s->failed_pc=0x0c060076u; return 0; }
r[2]|=r[1];
goto P_0c060078;
P_0c060078: /* original e050, guest PC 0x0c060078 */
if(!s->budget--) { s->failed_pc=0x0c060078u; return 0; }
r[0]=0x00000050u;
goto P_0c06007a;
P_0c06007a: /* original 014e, guest PC 0x0c06007a */
if(!s->budget--) { s->failed_pc=0x0c06007au; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c06007c;
P_0c06007c: /* original 2159, guest PC 0x0c06007c */
if(!s->budget--) { s->failed_pc=0x0c06007cu; return 0; }
r[1]&=r[5];
goto P_0c06007e;
P_0c06007e: /* original 4118, guest PC 0x0c06007e */
if(!s->budget--) { s->failed_pc=0x0c06007eu; return 0; }
r[1]<<=8;
goto P_0c060080;
P_0c060080: /* original 4100, guest PC 0x0c060080 */
if(!s->budget--) { s->failed_pc=0x0c060080u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c060082;
P_0c060082: /* original 221b, guest PC 0x0c060082 */
if(!s->budget--) { s->failed_pc=0x0c060082u; return 0; }
r[2]|=r[1];
goto P_0c060084;
P_0c060084: /* original d143, guest PC 0x0c060084 */
if(!s->budget--) { s->failed_pc=0x0c060084u; return 0; }
r[1]=read(ram,0x0c060194u,4);
goto P_0c060086;
P_0c060086: /* original 2122, guest PC 0x0c060086 */
if(!s->budget--) { s->failed_pc=0x0c060086u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c060088;
P_0c060088: /* original 6342, guest PC 0x0c060088 */
if(!s->budget--) { s->failed_pc=0x0c060088u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c06008a;
P_0c06008a: /* original d243, guest PC 0x0c06008a */
if(!s->budget--) { s->failed_pc=0x0c06008au; return 0; }
r[2]=read(ram,0x0c060198u,4);
goto P_0c06008c;
P_0c06008c: /* original 2232, guest PC 0x0c06008c */
if(!s->budget--) { s->failed_pc=0x0c06008cu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c06008e;
P_0c06008e: /* original 5141, guest PC 0x0c06008e */
if(!s->budget--) { s->failed_pc=0x0c06008eu; return 0; }
r[1]=read(ram,r[4]+4,4);
goto P_0c060090;
P_0c060090: /* original d342, guest PC 0x0c060090 */
if(!s->budget--) { s->failed_pc=0x0c060090u; return 0; }
r[3]=read(ram,0x0c06019cu,4);
goto P_0c060092;
P_0c060092: /* original 2312, guest PC 0x0c060092 */
if(!s->budget--) { s->failed_pc=0x0c060092u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c060094;
P_0c060094: /* original 9577, guest PC 0x0c060094 */
if(!s->budget--) { s->failed_pc=0x0c060094u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060186u,2);
goto P_0c060096;
P_0c060096: /* original 6742, guest PC 0x0c060096 */
if(!s->budget--) { s->failed_pc=0x0c060096u; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c060098;
P_0c060098: /* original 5d41, guest PC 0x0c060098 */
if(!s->budget--) { s->failed_pc=0x0c060098u; return 0; }
r[13]=read(ram,r[4]+4,4);
goto P_0c06009a;
P_0c06009a: /* original 2759, guest PC 0x0c06009a */
if(!s->budget--) { s->failed_pc=0x0c06009au; return 0; }
r[7]&=r[5];
goto P_0c06009c;
P_0c06009c: /* original 5e42, guest PC 0x0c06009c */
if(!s->budget--) { s->failed_pc=0x0c06009cu; return 0; }
r[14]=read(ram,r[4]+8,4);
goto P_0c06009e;
P_0c06009e: /* original 2e59, guest PC 0x0c06009e */
if(!s->budget--) { s->failed_pc=0x0c06009eu; return 0; }
r[14]&=r[5];
goto P_0c0600a0;
P_0c0600a0: /* original d03f, guest PC 0x0c0600a0 */
if(!s->budget--) { s->failed_pc=0x0c0600a0u; return 0; }
r[0]=read(ram,0x0c0601a0u,4);
goto P_0c0600a2;
P_0c0600a2: /* original 4e28, guest PC 0x0c0600a2 */
if(!s->budget--) { s->failed_pc=0x0c0600a2u; return 0; }
r[14]<<=16;
goto P_0c0600a4;
P_0c0600a4: /* original 4e08, guest PC 0x0c0600a4 */
if(!s->budget--) { s->failed_pc=0x0c0600a4u; return 0; }
r[14]<<=2;
goto P_0c0600a6;
P_0c0600a6: /* original 6102, guest PC 0x0c0600a6 */
if(!s->budget--) { s->failed_pc=0x0c0600a6u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c0600a8;
P_0c0600a8: /* original 4115, guest PC 0x0c0600a8 */
if(!s->budget--) { s->failed_pc=0x0c0600a8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c0600aa;
P_0c0600aa: /* original 8f0b, guest PC 0x0c0600aa */
if(!s->budget--) { s->failed_pc=0x0c0600aau; return 0; }
cond=r[17]&1u;
r[14]<<=2;
if(!cond) { goto P_0c0600c4; }
goto P_0c0600ae;
P_0c0600ac: /* original 4e08, guest PC 0x0c0600ac */
if(!s->budget--) { s->failed_pc=0x0c0600acu; return 0; }
r[14]<<=2;
goto P_0c0600ae;
P_0c0600ae: /* original d13c, guest PC 0x0c0600ae */
if(!s->budget--) { s->failed_pc=0x0c0600aeu; return 0; }
r[1]=read(ram,0x0c0601a0u,4);
goto P_0c0600b0;
P_0c0600b0: /* original 6212, guest PC 0x0c0600b0 */
if(!s->budget--) { s->failed_pc=0x0c0600b0u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0600b2;
P_0c0600b2: /* original 3d28, guest PC 0x0c0600b2 */
if(!s->budget--) { s->failed_pc=0x0c0600b2u; return 0; }
r[13]-=r[2];
goto P_0c0600b4;
P_0c0600b4: /* original d33b, guest PC 0x0c0600b4 */
if(!s->budget--) { s->failed_pc=0x0c0600b4u; return 0; }
r[3]=read(ram,0x0c0601a4u,4);
goto P_0c0600b6;
P_0c0600b6: /* original 2d59, guest PC 0x0c0600b6 */
if(!s->budget--) { s->failed_pc=0x0c0600b6u; return 0; }
r[13]&=r[5];
goto P_0c0600b8;
P_0c0600b8: /* original 4d18, guest PC 0x0c0600b8 */
if(!s->budget--) { s->failed_pc=0x0c0600b8u; return 0; }
r[13]<<=8;
goto P_0c0600ba;
P_0c0600ba: /* original 4d08, guest PC 0x0c0600ba */
if(!s->budget--) { s->failed_pc=0x0c0600bau; return 0; }
r[13]<<=2;
goto P_0c0600bc;
P_0c0600bc: /* original 27db, guest PC 0x0c0600bc */
if(!s->budget--) { s->failed_pc=0x0c0600bcu; return 0; }
r[7]|=r[13];
goto P_0c0600be;
P_0c0600be: /* original 27eb, guest PC 0x0c0600be */
if(!s->budget--) { s->failed_pc=0x0c0600beu; return 0; }
r[7]|=r[14];
goto P_0c0600c0;
P_0c0600c0: /* original a007, guest PC 0x0c0600c0 */
if(!s->budget--) { s->failed_pc=0x0c0600c0u; return 0; }
write(ram,r[3],r[7],4);
goto P_0c0600d2;
P_0c0600c2: /* original 2372, guest PC 0x0c0600c2 */
if(!s->budget--) { s->failed_pc=0x0c0600c2u; return 0; }
write(ram,r[3],r[7],4);
goto P_0c0600c4;
P_0c0600c4: /* original d137, guest PC 0x0c0600c4 */
if(!s->budget--) { s->failed_pc=0x0c0600c4u; return 0; }
r[1]=read(ram,0x0c0601a4u,4);
goto P_0c0600c6;
P_0c0600c6: /* original 2d59, guest PC 0x0c0600c6 */
if(!s->budget--) { s->failed_pc=0x0c0600c6u; return 0; }
r[13]&=r[5];
goto P_0c0600c8;
P_0c0600c8: /* original 4d18, guest PC 0x0c0600c8 */
if(!s->budget--) { s->failed_pc=0x0c0600c8u; return 0; }
r[13]<<=8;
goto P_0c0600ca;
P_0c0600ca: /* original 4d08, guest PC 0x0c0600ca */
if(!s->budget--) { s->failed_pc=0x0c0600cau; return 0; }
r[13]<<=2;
goto P_0c0600cc;
P_0c0600cc: /* original 27db, guest PC 0x0c0600cc */
if(!s->budget--) { s->failed_pc=0x0c0600ccu; return 0; }
r[7]|=r[13];
goto P_0c0600ce;
P_0c0600ce: /* original 27eb, guest PC 0x0c0600ce */
if(!s->budget--) { s->failed_pc=0x0c0600ceu; return 0; }
r[7]|=r[14];
goto P_0c0600d0;
P_0c0600d0: /* original 2172, guest PC 0x0c0600d0 */
if(!s->budget--) { s->failed_pc=0x0c0600d0u; return 0; }
write(ram,r[1],r[7],4);
goto P_0c0600d2;
P_0c0600d2: /* original 5345, guest PC 0x0c0600d2 */
if(!s->budget--) { s->failed_pc=0x0c0600d2u; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c0600d4;
P_0c0600d4: /* original 5246, guest PC 0x0c0600d4 */
if(!s->budget--) { s->failed_pc=0x0c0600d4u; return 0; }
r[2]=read(ram,r[4]+24,4);
goto P_0c0600d6;
P_0c0600d6: /* original 633c, guest PC 0x0c0600d6 */
if(!s->budget--) { s->failed_pc=0x0c0600d6u; return 0; }
r[3]=r[3]&255u;
goto P_0c0600d8;
P_0c0600d8: /* original d133, guest PC 0x0c0600d8 */
if(!s->budget--) { s->failed_pc=0x0c0600d8u; return 0; }
r[1]=read(ram,0x0c0601a8u,4);
goto P_0c0600da;
P_0c0600da: /* original 622c, guest PC 0x0c0600da */
if(!s->budget--) { s->failed_pc=0x0c0600dau; return 0; }
r[2]=r[2]&255u;
goto P_0c0600dc;
P_0c0600dc: /* original 4218, guest PC 0x0c0600dc */
if(!s->budget--) { s->failed_pc=0x0c0600dcu; return 0; }
r[2]<<=8;
goto P_0c0600de;
P_0c0600de: /* original 232b, guest PC 0x0c0600de */
if(!s->budget--) { s->failed_pc=0x0c0600deu; return 0; }
r[3]|=r[2];
goto P_0c0600e0;
P_0c0600e0: /* original 2132, guest PC 0x0c0600e0 */
if(!s->budget--) { s->failed_pc=0x0c0600e0u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c0600e2;
P_0c0600e2: /* original e501, guest PC 0x0c0600e2 */
if(!s->budget--) { s->failed_pc=0x0c0600e2u; return 0; }
r[5]=0x00000001u;
goto P_0c0600e4;
P_0c0600e4: /* original 5344, guest PC 0x0c0600e4 */
if(!s->budget--) { s->failed_pc=0x0c0600e4u; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c0600e6;
P_0c0600e6: /* original 633d, guest PC 0x0c0600e6 */
if(!s->budget--) { s->failed_pc=0x0c0600e6u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0600e8;
P_0c0600e8: /* original 5243, guest PC 0x0c0600e8 */
if(!s->budget--) { s->failed_pc=0x0c0600e8u; return 0; }
r[2]=read(ram,r[4]+12,4);
goto P_0c0600ea;
P_0c0600ea: /* original 2259, guest PC 0x0c0600ea */
if(!s->budget--) { s->failed_pc=0x0c0600eau; return 0; }
r[2]&=r[5];
goto P_0c0600ec;
P_0c0600ec: /* original 5047, guest PC 0x0c0600ec */
if(!s->budget--) { s->failed_pc=0x0c0600ecu; return 0; }
r[0]=read(ram,r[4]+28,4);
goto P_0c0600ee;
P_0c0600ee: /* original 4228, guest PC 0x0c0600ee */
if(!s->budget--) { s->failed_pc=0x0c0600eeu; return 0; }
r[2]<<=16;
goto P_0c0600f0;
P_0c0600f0: /* original 232b, guest PC 0x0c0600f0 */
if(!s->budget--) { s->failed_pc=0x0c0600f0u; return 0; }
r[3]|=r[2];
goto P_0c0600f2;
P_0c0600f2: /* original 2059, guest PC 0x0c0600f2 */
if(!s->budget--) { s->failed_pc=0x0c0600f2u; return 0; }
r[0]&=r[5];
goto P_0c0600f4;
P_0c0600f4: /* original d22d, guest PC 0x0c0600f4 */
if(!s->budget--) { s->failed_pc=0x0c0600f4u; return 0; }
r[2]=read(ram,0x0c0601acu,4);
goto P_0c0600f6;
P_0c0600f6: /* original 4028, guest PC 0x0c0600f6 */
if(!s->budget--) { s->failed_pc=0x0c0600f6u; return 0; }
r[0]<<=16;
goto P_0c0600f8;
P_0c0600f8: /* original 4008, guest PC 0x0c0600f8 */
if(!s->budget--) { s->failed_pc=0x0c0600f8u; return 0; }
r[0]<<=2;
goto P_0c0600fa;
P_0c0600fa: /* original 230b, guest PC 0x0c0600fa */
if(!s->budget--) { s->failed_pc=0x0c0600fau; return 0; }
r[3]|=r[0];
goto P_0c0600fc;
P_0c0600fc: /* original 2232, guest PC 0x0c0600fc */
if(!s->budget--) { s->failed_pc=0x0c0600fcu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0600fe;
P_0c0600fe: /* original e044, guest PC 0x0c0600fe */
if(!s->budget--) { s->failed_pc=0x0c0600feu; return 0; }
r[0]=0x00000044u;
goto P_0c060100;
P_0c060100: /* original 9342, guest PC 0x0c060100 */
if(!s->budget--) { s->failed_pc=0x0c060100u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060188u,2);
goto P_0c060102;
P_0c060102: /* original 72c4, guest PC 0x0c060102 */
if(!s->budget--) { s->failed_pc=0x0c060102u; return 0; }
r[2]+=0xffffffc4u;
goto P_0c060104;
P_0c060104: /* original 004e, guest PC 0x0c060104 */
if(!s->budget--) { s->failed_pc=0x0c060104u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c060106;
P_0c060106: /* original 2039, guest PC 0x0c060106 */
if(!s->budget--) { s->failed_pc=0x0c060106u; return 0; }
r[0]&=r[3];
goto P_0c060108;
P_0c060108: /* original 2202, guest PC 0x0c060108 */
if(!s->budget--) { s->failed_pc=0x0c060108u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c06010a;
P_0c06010a: /* original e707, guest PC 0x0c06010a */
if(!s->budget--) { s->failed_pc=0x0c06010au; return 0; }
r[7]=0x00000007u;
goto P_0c06010c;
P_0c06010c: /* original 514c, guest PC 0x0c06010c */
if(!s->budget--) { s->failed_pc=0x0c06010cu; return 0; }
r[1]=read(ram,r[4]+48,4);
goto P_0c06010e;
P_0c06010e: /* original 2179, guest PC 0x0c06010e */
if(!s->budget--) { s->failed_pc=0x0c06010eu; return 0; }
r[1]&=r[7];
goto P_0c060110;
P_0c060110: /* original 504b, guest PC 0x0c060110 */
if(!s->budget--) { s->failed_pc=0x0c060110u; return 0; }
r[0]=read(ram,r[4]+44,4);
goto P_0c060112;
P_0c060112: /* original 2059, guest PC 0x0c060112 */
if(!s->budget--) { s->failed_pc=0x0c060112u; return 0; }
r[0]&=r[5];
goto P_0c060114;
P_0c060114: /* original 4008, guest PC 0x0c060114 */
if(!s->budget--) { s->failed_pc=0x0c060114u; return 0; }
r[0]<<=2;
goto P_0c060116;
P_0c060116: /* original 4000, guest PC 0x0c060116 */
if(!s->budget--) { s->failed_pc=0x0c060116u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c060118;
P_0c060118: /* original 210b, guest PC 0x0c060118 */
if(!s->budget--) { s->failed_pc=0x0c060118u; return 0; }
r[1]|=r[0];
goto P_0c06011a;
P_0c06011a: /* original 504d, guest PC 0x0c06011a */
if(!s->budget--) { s->failed_pc=0x0c06011au; return 0; }
r[0]=read(ram,r[4]+52,4);
goto P_0c06011c;
P_0c06011c: /* original 600c, guest PC 0x0c06011c */
if(!s->budget--) { s->failed_pc=0x0c06011cu; return 0; }
r[0]=r[0]&255u;
goto P_0c06011e;
P_0c06011e: /* original 4018, guest PC 0x0c06011e */
if(!s->budget--) { s->failed_pc=0x0c06011eu; return 0; }
r[0]<<=8;
goto P_0c060120;
P_0c060120: /* original 210b, guest PC 0x0c060120 */
if(!s->budget--) { s->failed_pc=0x0c060120u; return 0; }
r[1]|=r[0];
goto P_0c060122;
P_0c060122: /* original 504e, guest PC 0x0c060122 */
if(!s->budget--) { s->failed_pc=0x0c060122u; return 0; }
r[0]=read(ram,r[4]+56,4);
goto P_0c060124;
P_0c060124: /* original 600c, guest PC 0x0c060124 */
if(!s->budget--) { s->failed_pc=0x0c060124u; return 0; }
r[0]=r[0]&255u;
goto P_0c060126;
P_0c060126: /* original 4028, guest PC 0x0c060126 */
if(!s->budget--) { s->failed_pc=0x0c060126u; return 0; }
r[0]<<=16;
goto P_0c060128;
P_0c060128: /* original 210b, guest PC 0x0c060128 */
if(!s->budget--) { s->failed_pc=0x0c060128u; return 0; }
r[1]|=r[0];
goto P_0c06012a;
P_0c06012a: /* original d021, guest PC 0x0c06012a */
if(!s->budget--) { s->failed_pc=0x0c06012au; return 0; }
r[0]=read(ram,0x0c0601b0u,4);
goto P_0c06012c;
P_0c06012c: /* original 2012, guest PC 0x0c06012c */
if(!s->budget--) { s->failed_pc=0x0c06012cu; return 0; }
write(ram,r[0],r[1],4);
goto P_0c06012e;
P_0c06012e: /* original 5348, guest PC 0x0c06012e */
if(!s->budget--) { s->failed_pc=0x0c06012eu; return 0; }
r[3]=read(ram,r[4]+32,4);
goto P_0c060130;
P_0c060130: /* original 514a, guest PC 0x0c060130 */
if(!s->budget--) { s->failed_pc=0x0c060130u; return 0; }
r[1]=read(ram,r[4]+40,4);
goto P_0c060132;
P_0c060132: /* original 2359, guest PC 0x0c060132 */
if(!s->budget--) { s->failed_pc=0x0c060132u; return 0; }
r[3]&=r[5];
goto P_0c060134;
P_0c060134: /* original 504f, guest PC 0x0c060134 */
if(!s->budget--) { s->failed_pc=0x0c060134u; return 0; }
r[0]=read(ram,r[4]+60,4);
goto P_0c060136;
P_0c060136: /* original 2159, guest PC 0x0c060136 */
if(!s->budget--) { s->failed_pc=0x0c060136u; return 0; }
r[1]&=r[5];
goto P_0c060138;
P_0c060138: /* original 4100, guest PC 0x0c060138 */
if(!s->budget--) { s->failed_pc=0x0c060138u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c06013a;
P_0c06013a: /* original 231b, guest PC 0x0c06013a */
if(!s->budget--) { s->failed_pc=0x0c06013au; return 0; }
r[3]|=r[1];
goto P_0c06013c;
P_0c06013c: /* original c903, guest PC 0x0c06013c */
if(!s->budget--) { s->failed_pc=0x0c06013cu; return 0; }
r[0]&=3u;
goto P_0c06013e;
P_0c06013e: /* original 4008, guest PC 0x0c06013e */
if(!s->budget--) { s->failed_pc=0x0c06013eu; return 0; }
r[0]<<=2;
goto P_0c060140;
P_0c060140: /* original 230b, guest PC 0x0c060140 */
if(!s->budget--) { s->failed_pc=0x0c060140u; return 0; }
r[3]|=r[0];
goto P_0c060142;
P_0c060142: /* original e040, guest PC 0x0c060142 */
if(!s->budget--) { s->failed_pc=0x0c060142u; return 0; }
r[0]=0x00000040u;
goto P_0c060144;
P_0c060144: /* original 004e, guest PC 0x0c060144 */
if(!s->budget--) { s->failed_pc=0x0c060144u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c060146;
P_0c060146: /* original 2709, guest PC 0x0c060146 */
if(!s->budget--) { s->failed_pc=0x0c060146u; return 0; }
r[7]&=r[0];
goto P_0c060148;
P_0c060148: /* original 4708, guest PC 0x0c060148 */
if(!s->budget--) { s->failed_pc=0x0c060148u; return 0; }
r[7]<<=2;
goto P_0c06014a;
P_0c06014a: /* original 4708, guest PC 0x0c06014a */
if(!s->budget--) { s->failed_pc=0x0c06014au; return 0; }
r[7]<<=2;
goto P_0c06014c;
P_0c06014c: /* original 237b, guest PC 0x0c06014c */
if(!s->budget--) { s->failed_pc=0x0c06014cu; return 0; }
r[3]|=r[7];
goto P_0c06014e;
P_0c06014e: /* original e070, guest PC 0x0c06014e */
if(!s->budget--) { s->failed_pc=0x0c06014eu; return 0; }
r[0]=0x00000070u;
goto P_0c060150;
P_0c060150: /* original 014c, guest PC 0x0c060150 */
if(!s->budget--) { s->failed_pc=0x0c060150u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c060152;
P_0c060152: /* original e216, guest PC 0x0c060152 */
if(!s->budget--) { s->failed_pc=0x0c060152u; return 0; }
r[2]=0x00000016u;
goto P_0c060154;
P_0c060154: /* original 611c, guest PC 0x0c060154 */
if(!s->budget--) { s->failed_pc=0x0c060154u; return 0; }
r[1]=r[1]&255u;
goto P_0c060156;
P_0c060156: /* original 4118, guest PC 0x0c060156 */
if(!s->budget--) { s->failed_pc=0x0c060156u; return 0; }
r[1]<<=8;
goto P_0c060158;
P_0c060158: /* original 231b, guest PC 0x0c060158 */
if(!s->budget--) { s->failed_pc=0x0c060158u; return 0; }
r[3]|=r[1];
goto P_0c06015a;
P_0c06015a: /* original e068, guest PC 0x0c06015a */
if(!s->budget--) { s->failed_pc=0x0c06015au; return 0; }
r[0]=0x00000068u;
goto P_0c06015c;
P_0c06015c: /* original 014e, guest PC 0x0c06015c */
if(!s->budget--) { s->failed_pc=0x0c06015cu; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c06015e;
P_0c06015e: /* original e064, guest PC 0x0c06015e */
if(!s->budget--) { s->failed_pc=0x0c06015eu; return 0; }
r[0]=0x00000064u;
goto P_0c060160;
P_0c060160: /* original 2619, guest PC 0x0c060160 */
if(!s->budget--) { s->failed_pc=0x0c060160u; return 0; }
r[6]&=r[1];
goto P_0c060162;
P_0c060162: /* original 4628, guest PC 0x0c060162 */
if(!s->budget--) { s->failed_pc=0x0c060162u; return 0; }
r[6]<<=16;
goto P_0c060164;
P_0c060164: /* original 014e, guest PC 0x0c060164 */
if(!s->budget--) { s->failed_pc=0x0c060164u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c060166;
P_0c060166: /* original 236b, guest PC 0x0c060166 */
if(!s->budget--) { s->failed_pc=0x0c060166u; return 0; }
r[3]|=r[6];
goto P_0c060168;
P_0c060168: /* original 2159, guest PC 0x0c060168 */
if(!s->budget--) { s->failed_pc=0x0c060168u; return 0; }
r[1]&=r[5];
goto P_0c06016a;
P_0c06016a: /* original 412c, guest PC 0x0c06016a */
if(!s->budget--) { s->failed_pc=0x0c06016au; return 0; }
r[1]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[1]>>((-r[2])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[2]&31u);
goto P_0c06016c;
P_0c06016c: /* original 231b, guest PC 0x0c06016c */
if(!s->budget--) { s->failed_pc=0x0c06016cu; return 0; }
r[3]|=r[1];
goto P_0c06016e;
P_0c06016e: /* original e06c, guest PC 0x0c06016e */
if(!s->budget--) { s->failed_pc=0x0c06016eu; return 0; }
r[0]=0x0000006cu;
goto P_0c060170;
P_0c060170: /* original 014e, guest PC 0x0c060170 */
if(!s->budget--) { s->failed_pc=0x0c060170u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c060172;
P_0c060172: /* original e217, guest PC 0x0c060172 */
if(!s->budget--) { s->failed_pc=0x0c060172u; return 0; }
r[2]=0x00000017u;
goto P_0c060174;
P_0c060174: /* original 2159, guest PC 0x0c060174 */
if(!s->budget--) { s->failed_pc=0x0c060174u; return 0; }
r[1]&=r[5];
goto P_0c060176;
P_0c060176: /* original 412c, guest PC 0x0c060176 */
if(!s->budget--) { s->failed_pc=0x0c060176u; return 0; }
r[1]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[1]>>((-r[2])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[2]&31u);
goto P_0c060178;
P_0c060178: /* original 231b, guest PC 0x0c060178 */
if(!s->budget--) { s->failed_pc=0x0c060178u; return 0; }
r[3]|=r[1];
goto P_0c06017a;
P_0c06017a: /* original d10e, guest PC 0x0c06017a */
if(!s->budget--) { s->failed_pc=0x0c06017au; return 0; }
r[1]=read(ram,0x0c0601b4u,4);
goto P_0c06017c;
P_0c06017c: /* original 2132, guest PC 0x0c06017c */
if(!s->budget--) { s->failed_pc=0x0c06017cu; return 0; }
write(ram,r[1],r[3],4);
goto P_0c06017e;
P_0c06017e: /* original 6df6, guest PC 0x0c06017e */
if(!s->budget--) { s->failed_pc=0x0c06017eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c060180;
P_0c060180: /* original 000b, guest PC 0x0c060180 */
if(!s->budget--) { s->failed_pc=0x0c060180u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c060182: /* original 6ef6, guest PC 0x0c060182 */
if(!s->budget--) { s->failed_pc=0x0c060182u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c060184u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060184u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
