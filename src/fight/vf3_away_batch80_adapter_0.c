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
int vf3_away_batch80_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03a140u: goto P_0c03a140;
case 0x0c03a142u: goto P_0c03a142;
case 0x0c03a144u: goto P_0c03a144;
case 0x0c03a146u: goto P_0c03a146;
case 0x0c03a148u: goto P_0c03a148;
case 0x0c03a14au: goto P_0c03a14a;
case 0x0c03a14cu: goto P_0c03a14c;
case 0x0c03a14eu: goto P_0c03a14e;
case 0x0c03a150u: goto P_0c03a150;
case 0x0c03a152u: goto P_0c03a152;
case 0x0c03a154u: goto P_0c03a154;
case 0x0c03a156u: goto P_0c03a156;
case 0x0c03a6e0u: goto P_0c03a6e0;
case 0x0c03a6e2u: goto P_0c03a6e2;
case 0x0c03a6e4u: goto P_0c03a6e4;
case 0x0c03a6e6u: goto P_0c03a6e6;
case 0x0c03a6e8u: goto P_0c03a6e8;
case 0x0c03a6eau: goto P_0c03a6ea;
case 0x0c03a6ecu: goto P_0c03a6ec;
case 0x0c03a6eeu: goto P_0c03a6ee;
case 0x0c03a6f0u: goto P_0c03a6f0;
case 0x0c03a6f2u: goto P_0c03a6f2;
case 0x0c03a6f4u: goto P_0c03a6f4;
case 0x0c03a6f6u: goto P_0c03a6f6;
case 0x0c03a6f8u: goto P_0c03a6f8;
case 0x0c03a6fau: goto P_0c03a6fa;
case 0x0c03a6fcu: goto P_0c03a6fc;
case 0x0c03a6feu: goto P_0c03a6fe;
case 0x0c03a700u: goto P_0c03a700;
case 0x0c03a702u: goto P_0c03a702;
case 0x0c03a704u: goto P_0c03a704;
case 0x0c03a706u: goto P_0c03a706;
case 0x0c03a708u: goto P_0c03a708;
case 0x0c03a70au: goto P_0c03a70a;
case 0x0c03a70cu: goto P_0c03a70c;
case 0x0c03a70eu: goto P_0c03a70e;
case 0x0c03a710u: goto P_0c03a710;
case 0x0c03a712u: goto P_0c03a712;
case 0x0c03a714u: goto P_0c03a714;
case 0x0c03a716u: goto P_0c03a716;
case 0x0c03a718u: goto P_0c03a718;
case 0x0c03a71au: goto P_0c03a71a;
case 0x0c03a71cu: goto P_0c03a71c;
case 0x0c03a71eu: goto P_0c03a71e;
case 0x0c03a720u: goto P_0c03a720;
case 0x0c03a722u: goto P_0c03a722;
case 0x0c03a724u: goto P_0c03a724;
case 0x0c03a726u: goto P_0c03a726;
case 0x0c03a728u: goto P_0c03a728;
case 0x0c03a72au: goto P_0c03a72a;
case 0x0c03a72cu: goto P_0c03a72c;
case 0x0c03a72eu: goto P_0c03a72e;
case 0x0c03a730u: goto P_0c03a730;
case 0x0c03a732u: goto P_0c03a732;
case 0x0c03a734u: goto P_0c03a734;
case 0x0c03a736u: goto P_0c03a736;
case 0x0c03a738u: goto P_0c03a738;
case 0x0c03a73au: goto P_0c03a73a;
case 0x0c03a73cu: goto P_0c03a73c;
case 0x0c03a73eu: goto P_0c03a73e;
case 0x0c03a740u: goto P_0c03a740;
case 0x0c03a742u: goto P_0c03a742;
case 0x0c03a744u: goto P_0c03a744;
case 0x0c03a746u: goto P_0c03a746;
case 0x0c03a748u: goto P_0c03a748;
case 0x0c03a74au: goto P_0c03a74a;
case 0x0c03a750u: goto P_0c03a750;
case 0x0c03a752u: goto P_0c03a752;
case 0x0c03a754u: goto P_0c03a754;
case 0x0c03a756u: goto P_0c03a756;
case 0x0c03c5b0u: goto P_0c03c5b0;
case 0x0c03c5b2u: goto P_0c03c5b2;
case 0x0c03c5b4u: goto P_0c03c5b4;
case 0x0c03c5b6u: goto P_0c03c5b6;
case 0x0c03c5b8u: goto P_0c03c5b8;
case 0x0c03c5bau: goto P_0c03c5ba;
case 0x0c03c5bcu: goto P_0c03c5bc;
case 0x0c03c5beu: goto P_0c03c5be;
case 0x0c03c5c0u: goto P_0c03c5c0;
case 0x0c03c5c2u: goto P_0c03c5c2;
case 0x0c03c5c4u: goto P_0c03c5c4;
case 0x0c03c5c6u: goto P_0c03c5c6;
case 0x0c03c5c8u: goto P_0c03c5c8;
case 0x0c03c5cau: goto P_0c03c5ca;
case 0x0c03c5ccu: goto P_0c03c5cc;
case 0x0c03c5ceu: goto P_0c03c5ce;
case 0x0c03c5d0u: goto P_0c03c5d0;
case 0x0c03c5d2u: goto P_0c03c5d2;
case 0x0c03c5d4u: goto P_0c03c5d4;
case 0x0c03c5d6u: goto P_0c03c5d6;
case 0x0c03c5d8u: goto P_0c03c5d8;
case 0x0c03c5dau: goto P_0c03c5da;
case 0x0c03c5dcu: goto P_0c03c5dc;
case 0x0c03c5deu: goto P_0c03c5de;
case 0x0c03c5e0u: goto P_0c03c5e0;
case 0x0c03c5e2u: goto P_0c03c5e2;
case 0x0c03c5e4u: goto P_0c03c5e4;
case 0x0c03c5e6u: goto P_0c03c5e6;
case 0x0c03c5e8u: goto P_0c03c5e8;
case 0x0c03c5eau: goto P_0c03c5ea;
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
case 0x0c068c58u: goto P_0c068c58;
case 0x0c068c5au: goto P_0c068c5a;
case 0x0c068c5cu: goto P_0c068c5c;
case 0x0c068c5eu: goto P_0c068c5e;
case 0x0c068c60u: goto P_0c068c60;
case 0x0c068c62u: goto P_0c068c62;
case 0x0c068c64u: goto P_0c068c64;
case 0x0c068c66u: goto P_0c068c66;
case 0x0c068c68u: goto P_0c068c68;
case 0x0c068c6au: goto P_0c068c6a;
case 0x0c068c6cu: goto P_0c068c6c;
case 0x0c068c6eu: goto P_0c068c6e;
case 0x0c068c70u: goto P_0c068c70;
case 0x0c068c72u: goto P_0c068c72;
case 0x0c068c74u: goto P_0c068c74;
case 0x0c068c76u: goto P_0c068c76;
case 0x0c068c78u: goto P_0c068c78;
case 0x0c068c7au: goto P_0c068c7a;
case 0x0c068c7cu: goto P_0c068c7c;
case 0x0c068c7eu: goto P_0c068c7e;
case 0x0c068c80u: goto P_0c068c80;
case 0x0c068c82u: goto P_0c068c82;
case 0x0c068c84u: goto P_0c068c84;
case 0x0c068c86u: goto P_0c068c86;
case 0x0c068c88u: goto P_0c068c88;
case 0x0c068c8au: goto P_0c068c8a;
case 0x0c068c8cu: goto P_0c068c8c;
case 0x0c068c8eu: goto P_0c068c8e;
case 0x0c068c90u: goto P_0c068c90;
case 0x0c068c92u: goto P_0c068c92;
case 0x0c068c94u: goto P_0c068c94;
case 0x0c068c96u: goto P_0c068c96;
case 0x0c068c98u: goto P_0c068c98;
case 0x0c068c9au: goto P_0c068c9a;
case 0x0c068c9cu: goto P_0c068c9c;
case 0x0c068c9eu: goto P_0c068c9e;
case 0x0c068ca0u: goto P_0c068ca0;
case 0x0c068ca2u: goto P_0c068ca2;
case 0x0c068ca4u: goto P_0c068ca4;
case 0x0c068ca6u: goto P_0c068ca6;
case 0x0c068ca8u: goto P_0c068ca8;
case 0x0c068caau: goto P_0c068caa;
case 0x0c068cacu: goto P_0c068cac;
case 0x0c068caeu: goto P_0c068cae;
case 0x0c068cb0u: goto P_0c068cb0;
case 0x0c068cb2u: goto P_0c068cb2;
case 0x0c068cb4u: goto P_0c068cb4;
case 0x0c068cb6u: goto P_0c068cb6;
case 0x0c068cb8u: goto P_0c068cb8;
case 0x0c068cbau: goto P_0c068cba;
case 0x0c068cbcu: goto P_0c068cbc;
case 0x0c068cbeu: goto P_0c068cbe;
case 0x0c068cc0u: goto P_0c068cc0;
case 0x0c068cc2u: goto P_0c068cc2;
case 0x0c068cc4u: goto P_0c068cc4;
case 0x0c068cc6u: goto P_0c068cc6;
case 0x0c068cc8u: goto P_0c068cc8;
case 0x0c068ccau: goto P_0c068cca;
case 0x0c068cccu: goto P_0c068ccc;
case 0x0c068cceu: goto P_0c068cce;
case 0x0c068cd0u: goto P_0c068cd0;
case 0x0c068cd2u: goto P_0c068cd2;
case 0x0c068cd4u: goto P_0c068cd4;
case 0x0c068cd6u: goto P_0c068cd6;
case 0x0c068cd8u: goto P_0c068cd8;
case 0x0c068cdau: goto P_0c068cda;
case 0x0c068cdcu: goto P_0c068cdc;
case 0x0c068cdeu: goto P_0c068cde;
case 0x0c068ce0u: goto P_0c068ce0;
case 0x0c068ce2u: goto P_0c068ce2;
case 0x0c068ce4u: goto P_0c068ce4;
case 0x0c068ce6u: goto P_0c068ce6;
case 0x0c068ce8u: goto P_0c068ce8;
case 0x0c068ceau: goto P_0c068cea;
case 0x0c068cecu: goto P_0c068cec;
case 0x0c068ceeu: goto P_0c068cee;
case 0x0c068cf0u: goto P_0c068cf0;
case 0x0c068cf2u: goto P_0c068cf2;
case 0x0c068cf4u: goto P_0c068cf4;
case 0x0c068cf6u: goto P_0c068cf6;
case 0x0c068cf8u: goto P_0c068cf8;
case 0x0c068cfau: goto P_0c068cfa;
case 0x0c068cfcu: goto P_0c068cfc;
case 0x0c068cfeu: goto P_0c068cfe;
case 0x0c068d00u: goto P_0c068d00;
case 0x0c068d02u: goto P_0c068d02;
case 0x0c068d04u: goto P_0c068d04;
case 0x0c068d06u: goto P_0c068d06;
case 0x0c068d08u: goto P_0c068d08;
case 0x0c068d0au: goto P_0c068d0a;
case 0x0c068d0cu: goto P_0c068d0c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03a140: /* original 2fe6, guest PC 0x0c03a140 */
if(!s->budget--) { s->failed_pc=0x0c03a140u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03a142;
P_0c03a142: /* original 6e4d, guest PC 0x0c03a142 */
if(!s->budget--) { s->failed_pc=0x0c03a142u; return 0; }
r[14]=r[4]&65535u;
goto P_0c03a144;
P_0c03a144: /* original d337, guest PC 0x0c03a144 */
if(!s->budget--) { s->failed_pc=0x0c03a144u; return 0; }
r[3]=read(ram,0x0c03a224u,4);
goto P_0c03a146;
P_0c03a146: /* original 3e37, guest PC 0x0c03a146 */
if(!s->budget--) { s->failed_pc=0x0c03a146u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[3])!=0);
goto P_0c03a148;
P_0c03a148: /* original 8b02, guest PC 0x0c03a148 */
if(!s->budget--) { s->failed_pc=0x0c03a148u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a150; }
goto P_0c03a14a;
P_0c03a14a: /* original d137, guest PC 0x0c03a14a */
if(!s->budget--) { s->failed_pc=0x0c03a14au; return 0; }
r[1]=read(ram,0x0c03a228u,4);
goto P_0c03a14c;
P_0c03a14c: /* original 31e8, guest PC 0x0c03a14c */
if(!s->budget--) { s->failed_pc=0x0c03a14cu; return 0; }
r[1]-=r[14];
goto P_0c03a14e;
P_0c03a14e: /* original 6e13, guest PC 0x0c03a14e */
if(!s->budget--) { s->failed_pc=0x0c03a14eu; return 0; }
r[14]=r[1];
goto P_0c03a150;
P_0c03a150: /* original 9466, guest PC 0x0c03a150 */
if(!s->budget--) { s->failed_pc=0x0c03a150u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a220u,2);
goto P_0c03a152;
P_0c03a152: /* original 34e8, guest PC 0x0c03a152 */
if(!s->budget--) { s->failed_pc=0x0c03a152u; return 0; }
r[4]-=r[14];
goto P_0c03a154;
P_0c03a154: /* original a2c4, guest PC 0x0c03a154 */
if(!s->budget--) { s->failed_pc=0x0c03a154u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c03a6e0;
P_0c03a156: /* original 6ef6, guest PC 0x0c03a156 */
if(!s->budget--) { s->failed_pc=0x0c03a156u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03a158u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a158u; return 0; } return 1;
P_0c03a6e0: /* original 644d, guest PC 0x0c03a6e0 */
if(!s->budget--) { s->failed_pc=0x0c03a6e0u; return 0; }
r[4]=r[4]&65535u;
goto P_0c03a6e2;
P_0c03a6e2: /* original 445a, guest PC 0x0c03a6e2 */
if(!s->budget--) { s->failed_pc=0x0c03a6e2u; return 0; }
r[53]=r[4];
goto P_0c03a6e4;
P_0c03a6e4: /* original c78d, guest PC 0x0c03a6e4 */
if(!s->budget--) { s->failed_pc=0x0c03a6e4u; return 0; }
r[0]=code_base|0x0003a91cu;
goto P_0c03a6e6;
P_0c03a6e6: /* original f708, guest PC 0x0c03a6e6 */
if(!s->budget--) { s->failed_pc=0x0c03a6e6u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c03a6e8;
P_0c03a6e8: /* original c78d, guest PC 0x0c03a6e8 */
if(!s->budget--) { s->failed_pc=0x0c03a6e8u; return 0; }
r[0]=code_base|0x0003a920u;
goto P_0c03a6ea;
P_0c03a6ea: /* original f208, guest PC 0x0c03a6ea */
if(!s->budget--) { s->failed_pc=0x0c03a6eau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a6ec;
P_0c03a6ec: /* original c78d, guest PC 0x0c03a6ec */
if(!s->budget--) { s->failed_pc=0x0c03a6ecu; return 0; }
r[0]=code_base|0x0003a924u;
goto P_0c03a6ee;
P_0c03a6ee: /* original f32d, guest PC 0x0c03a6ee */
if(!s->budget--) { s->failed_pc=0x0c03a6eeu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a6f0;
P_0c03a6f0: /* original f108, guest PC 0x0c03a6f0 */
if(!s->budget--) { s->failed_pc=0x0c03a6f0u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c03a6f2;
P_0c03a6f2: /* original c78d, guest PC 0x0c03a6f2 */
if(!s->budget--) { s->failed_pc=0x0c03a6f2u; return 0; }
r[0]=code_base|0x0003a928u;
goto P_0c03a6f4;
P_0c03a6f4: /* original f508, guest PC 0x0c03a6f4 */
if(!s->budget--) { s->failed_pc=0x0c03a6f4u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03a6f6;
P_0c03a6f6: /* original c78d, guest PC 0x0c03a6f6 */
if(!s->budget--) { s->failed_pc=0x0c03a6f6u; return 0; }
r[0]=code_base|0x0003a92cu;
goto P_0c03a6f8;
P_0c03a6f8: /* original f008, guest PC 0x0c03a6f8 */
if(!s->budget--) { s->failed_pc=0x0c03a6f8u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c03a6fa;
P_0c03a6fa: /* original e40b, guest PC 0x0c03a6fa */
if(!s->budget--) { s->failed_pc=0x0c03a6fau; return 0; }
r[4]=0x0000000bu;
goto P_0c03a6fc;
P_0c03a6fc: /* original e503, guest PC 0x0c03a6fc */
if(!s->budget--) { s->failed_pc=0x0c03a6fcu; return 0; }
r[5]=0x00000003u;
goto P_0c03a6fe;
P_0c03a6fe: /* original f322, guest PC 0x0c03a6fe */
if(!s->budget--) { s->failed_pc=0x0c03a6feu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c03a700;
P_0c03a700: /* original f313, guest PC 0x0c03a700 */
if(!s->budget--) { s->failed_pc=0x0c03a700u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'/');
goto P_0c03a702;
P_0c03a702: /* original f43c, guest PC 0x0c03a702 */
if(!s->budget--) { s->failed_pc=0x0c03a702u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03a704;
P_0c03a704: /* original f473, guest PC 0x0c03a704 */
if(!s->budget--) { s->failed_pc=0x0c03a704u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'/');
goto P_0c03a706;
P_0c03a706: /* original f34c, guest PC 0x0c03a706 */
if(!s->budget--) { s->failed_pc=0x0c03a706u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03a708;
P_0c03a708: /* original f353, guest PC 0x0c03a708 */
if(!s->budget--) { s->failed_pc=0x0c03a708u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'/');
goto P_0c03a70a;
P_0c03a70a: /* original f300, guest PC 0x0c03a70a */
if(!s->budget--) { s->failed_pc=0x0c03a70au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'+');
goto P_0c03a70c;
P_0c03a70c: /* original f33d, guest PC 0x0c03a70c */
if(!s->budget--) { s->failed_pc=0x0c03a70cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03a70e;
P_0c03a70e: /* original 065a, guest PC 0x0c03a70e */
if(!s->budget--) { s->failed_pc=0x0c03a70eu; return 0; }
r[6]=r[53];
goto P_0c03a710;
P_0c03a710: /* original 465a, guest PC 0x0c03a710 */
if(!s->budget--) { s->failed_pc=0x0c03a710u; return 0; }
r[53]=r[6];
goto P_0c03a712;
P_0c03a712: /* original f32d, guest PC 0x0c03a712 */
if(!s->budget--) { s->failed_pc=0x0c03a712u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a714;
P_0c03a714: /* original f352, guest PC 0x0c03a714 */
if(!s->budget--) { s->failed_pc=0x0c03a714u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a716;
P_0c03a716: /* original f58d, guest PC 0x0c03a716 */
if(!s->budget--) { s->failed_pc=0x0c03a716u; return 0; }
fr[5]=0;
goto P_0c03a718;
P_0c03a718: /* original f431, guest PC 0x0c03a718 */
if(!s->budget--) { s->failed_pc=0x0c03a718u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c03a71a;
P_0c03a71a: /* original f64c, guest PC 0x0c03a71a */
if(!s->budget--) { s->failed_pc=0x0c03a71au; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c03a71c;
P_0c03a71c: /* original f642, guest PC 0x0c03a71c */
if(!s->budget--) { s->failed_pc=0x0c03a71cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c03a71e;
P_0c03a71e: /* original 445a, guest PC 0x0c03a71e */
if(!s->budget--) { s->failed_pc=0x0c03a71eu; return 0; }
r[53]=r[4];
goto P_0c03a720;
P_0c03a720: /* original 74fe, guest PC 0x0c03a720 */
if(!s->budget--) { s->failed_pc=0x0c03a720u; return 0; }
r[4]+=0xfffffffeu;
goto P_0c03a722;
P_0c03a722: /* original 3453, guest PC 0x0c03a722 */
if(!s->budget--) { s->failed_pc=0x0c03a722u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c03a724;
P_0c03a724: /* original f22d, guest PC 0x0c03a724 */
if(!s->budget--) { s->failed_pc=0x0c03a724u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a726;
P_0c03a726: /* original f251, guest PC 0x0c03a726 */
if(!s->budget--) { s->failed_pc=0x0c03a726u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c03a728;
P_0c03a728: /* original f56c, guest PC 0x0c03a728 */
if(!s->budget--) { s->failed_pc=0x0c03a728u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c03a72a;
P_0c03a72a: /* original 8df8, guest PC 0x0c03a72a */
if(!s->budget--) { s->failed_pc=0x0c03a72au; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
if(cond) { goto P_0c03a71e; }
goto P_0c03a72e;
P_0c03a72c: /* original f523, guest PC 0x0c03a72c */
if(!s->budget--) { s->failed_pc=0x0c03a72cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
goto P_0c03a72e;
P_0c03a72e: /* original f69d, guest PC 0x0c03a72e */
if(!s->budget--) { s->failed_pc=0x0c03a72eu; return 0; }
fr[6]=0x3f800000u;
goto P_0c03a730;
P_0c03a730: /* original e301, guest PC 0x0c03a730 */
if(!s->budget--) { s->failed_pc=0x0c03a730u; return 0; }
r[3]=0x00000001u;
goto P_0c03a732;
P_0c03a732: /* original f36c, guest PC 0x0c03a732 */
if(!s->budget--) { s->failed_pc=0x0c03a732u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c03a734;
P_0c03a734: /* original f351, guest PC 0x0c03a734 */
if(!s->budget--) { s->failed_pc=0x0c03a734u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c03a736;
P_0c03a736: /* original 2638, guest PC 0x0c03a736 */
if(!s->budget--) { s->failed_pc=0x0c03a736u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c03a738;
P_0c03a738: /* original f433, guest PC 0x0c03a738 */
if(!s->budget--) { s->failed_pc=0x0c03a738u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c03a73a;
P_0c03a73a: /* original f24c, guest PC 0x0c03a73a */
if(!s->budget--) { s->failed_pc=0x0c03a73au; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03a73c;
P_0c03a73c: /* original f272, guest PC 0x0c03a73c */
if(!s->budget--) { s->failed_pc=0x0c03a73cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c03a73e;
P_0c03a73e: /* original f04c, guest PC 0x0c03a73e */
if(!s->budget--) { s->failed_pc=0x0c03a73eu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a740;
P_0c03a740: /* original f64e, guest PC 0x0c03a740 */
if(!s->budget--) { s->failed_pc=0x0c03a740u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[4],fr[6],r[18]);
goto P_0c03a742;
P_0c03a742: /* original f42c, guest PC 0x0c03a742 */
if(!s->budget--) { s->failed_pc=0x0c03a742u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c03a744;
P_0c03a744: /* original 8f04, guest PC 0x0c03a744 */
if(!s->budget--) { s->failed_pc=0x0c03a744u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
if(!cond) { goto P_0c03a750; }
goto P_0c03a748;
P_0c03a746: /* original f463, guest PC 0x0c03a746 */
if(!s->budget--) { s->failed_pc=0x0c03a746u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
goto P_0c03a748;
P_0c03a748: /* original 000b, guest PC 0x0c03a748 */
if(!s->budget--) { s->failed_pc=0x0c03a748u; return 0; }
target=r[16];
vf3_matrix_move(s,0,4);
s->pc=target; return ram->oob==0;
P_0c03a74a: /* original f04c, guest PC 0x0c03a74a */
if(!s->budget--) { s->failed_pc=0x0c03a74au; return 0; }
vf3_matrix_move(s,0,4);
if(!vf3_matrix_family(0x0c03a74cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a74cu; return 0; } return 1;
P_0c03a750: /* original f04c, guest PC 0x0c03a750 */
if(!s->budget--) { s->failed_pc=0x0c03a750u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a752;
P_0c03a752: /* original f04d, guest PC 0x0c03a752 */
if(!s->budget--) { s->failed_pc=0x0c03a752u; return 0; }
fr[0]^=0x80000000u;
goto P_0c03a754;
P_0c03a754: /* original 000b, guest PC 0x0c03a754 */
if(!s->budget--) { s->failed_pc=0x0c03a754u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03a756: /* original 0009, guest PC 0x0c03a756 */
if(!s->budget--) { s->failed_pc=0x0c03a756u; return 0; }
if(!vf3_matrix_family(0x0c03a758u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a758u; return 0; } return 1;
P_0c03c5b0: /* original fbfd, guest PC 0x0c03c5b0 */
if(!s->budget--) { s->failed_pc=0x0c03c5b0u; return 0; }
vf3_matrix_swap(s);
goto P_0c03c5b2;
P_0c03c5b2: /* original f38d, guest PC 0x0c03c5b2 */
if(!s->budget--) { s->failed_pc=0x0c03c5b2u; return 0; }
fr[3]=0;
goto P_0c03c5b4;
P_0c03c5b4: /* original fbb1, guest PC 0x0c03c5b4 */
if(!s->budget--) { s->failed_pc=0x0c03c5b4u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'-');
goto P_0c03c5b6;
P_0c03c5b6: /* original f78d, guest PC 0x0c03c5b6 */
if(!s->budget--) { s->failed_pc=0x0c03c5b6u; return 0; }
fr[7]=0;
goto P_0c03c5b8;
P_0c03c5b8: /* original ff9d, guest PC 0x0c03c5b8 */
if(!s->budget--) { s->failed_pc=0x0c03c5b8u; return 0; }
fr[15]=0x3f800000u;
goto P_0c03c5ba;
P_0c03c5ba: /* original f11d, guest PC 0x0c03c5ba */
if(!s->budget--) { s->failed_pc=0x0c03c5bau; return 0; }
r[53]=fr[1];
goto P_0c03c5bc;
P_0c03c5bc: /* original f3ed, guest PC 0x0c03c5bc */
if(!s->budget--) { s->failed_pc=0x0c03c5bcu; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c03c5be;
P_0c03c5be: /* original f14c, guest PC 0x0c03c5be */
if(!s->budget--) { s->failed_pc=0x0c03c5beu; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c03c5c0;
P_0c03c5c0: /* original f7ed, guest PC 0x0c03c5c0 */
if(!s->budget--) { s->failed_pc=0x0c03c5c0u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03c5c2;
P_0c03c5c2: /* original f40d, guest PC 0x0c03c5c2 */
if(!s->budget--) { s->failed_pc=0x0c03c5c2u; return 0; }
fr[4]=r[53];
goto P_0c03c5c4;
P_0c03c5c4: /* original fbed, guest PC 0x0c03c5c4 */
if(!s->budget--) { s->failed_pc=0x0c03c5c4u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c03c5c6;
P_0c03c5c6: /* original fc8d, guest PC 0x0c03c5c6 */
if(!s->budget--) { s->failed_pc=0x0c03c5c6u; return 0; }
fr[12]=0;
goto P_0c03c5c8;
P_0c03c5c8: /* original fee1, guest PC 0x0c03c5c8 */
if(!s->budget--) { s->failed_pc=0x0c03c5c8u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[14],r[18],'-');
goto P_0c03c5ca;
P_0c03c5ca: /* original fc31, guest PC 0x0c03c5ca */
if(!s->budget--) { s->failed_pc=0x0c03c5cau; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'-');
goto P_0c03c5cc;
P_0c03c5cc: /* original fd8d, guest PC 0x0c03c5cc */
if(!s->budget--) { s->failed_pc=0x0c03c5ccu; return 0; }
fr[13]=0;
goto P_0c03c5ce;
P_0c03c5ce: /* original fd71, guest PC 0x0c03c5ce */
if(!s->budget--) { s->failed_pc=0x0c03c5ceu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[7],r[18],'-');
goto P_0c03c5d0;
P_0c03c5d0: /* original f21d, guest PC 0x0c03c5d0 */
if(!s->budget--) { s->failed_pc=0x0c03c5d0u; return 0; }
r[53]=fr[2];
goto P_0c03c5d2;
P_0c03c5d2: /* original feb1, guest PC 0x0c03c5d2 */
if(!s->budget--) { s->failed_pc=0x0c03c5d2u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[11],r[18],'-');
goto P_0c03c5d4;
P_0c03c5d4: /* original f28c, guest PC 0x0c03c5d4 */
if(!s->budget--) { s->failed_pc=0x0c03c5d4u; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c03c5d6;
P_0c03c5d6: /* original f331, guest PC 0x0c03c5d6 */
if(!s->budget--) { s->failed_pc=0x0c03c5d6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[3],r[18],'-');
goto P_0c03c5d8;
P_0c03c5d8: /* original f80d, guest PC 0x0c03c5d8 */
if(!s->budget--) { s->failed_pc=0x0c03c5d8u; return 0; }
fr[8]=r[53];
goto P_0c03c5da;
P_0c03c5da: /* original f771, guest PC 0x0c03c5da */
if(!s->budget--) { s->failed_pc=0x0c03c5dau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[7],r[18],'-');
goto P_0c03c5dc;
P_0c03c5dc: /* original f61d, guest PC 0x0c03c5dc */
if(!s->budget--) { s->failed_pc=0x0c03c5dcu; return 0; }
r[53]=fr[6];
goto P_0c03c5de;
P_0c03c5de: /* original fbb1, guest PC 0x0c03c5de */
if(!s->budget--) { s->failed_pc=0x0c03c5deu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'-');
goto P_0c03c5e0;
P_0c03c5e0: /* original f69c, guest PC 0x0c03c5e0 */
if(!s->budget--) { s->failed_pc=0x0c03c5e0u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c03c5e2;
P_0c03c5e2: /* original f90d, guest PC 0x0c03c5e2 */
if(!s->budget--) { s->failed_pc=0x0c03c5e2u; return 0; }
fr[9]=r[53];
goto P_0c03c5e4;
P_0c03c5e4: /* original fbfd, guest PC 0x0c03c5e4 */
if(!s->budget--) { s->failed_pc=0x0c03c5e4u; return 0; }
vf3_matrix_swap(s);
goto P_0c03c5e6;
P_0c03c5e6: /* original 0009, guest PC 0x0c03c5e6 */
if(!s->budget--) { s->failed_pc=0x0c03c5e6u; return 0; }
goto P_0c03c5e8;
P_0c03c5e8: /* original 000b, guest PC 0x0c03c5e8 */
if(!s->budget--) { s->failed_pc=0x0c03c5e8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03c5ea: /* original 0009, guest PC 0x0c03c5ea */
if(!s->budget--) { s->failed_pc=0x0c03c5eau; return 0; }
if(!vf3_matrix_family(0x0c03c5ecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03c5ecu; return 0; } return 1;
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
P_0c068c58: /* original 2fe6, guest PC 0x0c068c58 */
if(!s->budget--) { s->failed_pc=0x0c068c58u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c5a;
P_0c068c5a: /* original 2fd6, guest PC 0x0c068c5a */
if(!s->budget--) { s->failed_pc=0x0c068c5au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c5c;
P_0c068c5c: /* original 2fc6, guest PC 0x0c068c5c */
if(!s->budget--) { s->failed_pc=0x0c068c5cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c5e;
P_0c068c5e: /* original ec0f, guest PC 0x0c068c5e */
if(!s->budget--) { s->failed_pc=0x0c068c5eu; return 0; }
r[12]=0x0000000fu;
goto P_0c068c60;
P_0c068c60: /* original 2fb6, guest PC 0x0c068c60 */
if(!s->budget--) { s->failed_pc=0x0c068c60u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c62;
P_0c068c62: /* original 2fa6, guest PC 0x0c068c62 */
if(!s->budget--) { s->failed_pc=0x0c068c62u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c64;
P_0c068c64: /* original 2f96, guest PC 0x0c068c64 */
if(!s->budget--) { s->failed_pc=0x0c068c64u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c66;
P_0c068c66: /* original 2f86, guest PC 0x0c068c66 */
if(!s->budget--) { s->failed_pc=0x0c068c66u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c68;
P_0c068c68: /* original d92b, guest PC 0x0c068c68 */
if(!s->budget--) { s->failed_pc=0x0c068c68u; return 0; }
r[9]=read(ram,0x0c068d18u,4);
goto P_0c068c6a;
P_0c068c6a: /* original d833, guest PC 0x0c068c6a */
if(!s->budget--) { s->failed_pc=0x0c068c6au; return 0; }
r[8]=read(ram,0x0c068d38u,4);
goto P_0c068c6c;
P_0c068c6c: /* original 6393, guest PC 0x0c068c6c */
if(!s->budget--) { s->failed_pc=0x0c068c6cu; return 0; }
r[3]=r[9];
goto P_0c068c6e;
P_0c068c6e: /* original 731c, guest PC 0x0c068c6e */
if(!s->budget--) { s->failed_pc=0x0c068c6eu; return 0; }
r[3]+=0x0000001cu;
goto P_0c068c70;
P_0c068c70: /* original 6030, guest PC 0x0c068c70 */
if(!s->budget--) { s->failed_pc=0x0c068c70u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c068c72;
P_0c068c72: /* original 4f22, guest PC 0x0c068c72 */
if(!s->budget--) { s->failed_pc=0x0c068c72u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c068c74;
P_0c068c74: /* original 600c, guest PC 0x0c068c74 */
if(!s->budget--) { s->failed_pc=0x0c068c74u; return 0; }
r[0]=r[0]&255u;
goto P_0c068c76;
P_0c068c76: /* original da31, guest PC 0x0c068c76 */
if(!s->budget--) { s->failed_pc=0x0c068c76u; return 0; }
r[10]=read(ram,0x0c068d3cu,4);
goto P_0c068c78;
P_0c068c78: /* original 2c09, guest PC 0x0c068c78 */
if(!s->budget--) { s->failed_pc=0x0c068c78u; return 0; }
r[12]&=r[0];
goto P_0c068c7a;
P_0c068c7a: /* original de2a, guest PC 0x0c068c7a */
if(!s->budget--) { s->failed_pc=0x0c068c7au; return 0; }
r[14]=read(ram,0x0c068d24u,4);
goto P_0c068c7c;
P_0c068c7c: /* original 6bc3, guest PC 0x0c068c7c */
if(!s->budget--) { s->failed_pc=0x0c068c7cu; return 0; }
r[11]=r[12];
goto P_0c068c7e;
P_0c068c7e: /* original 4b08, guest PC 0x0c068c7e */
if(!s->budget--) { s->failed_pc=0x0c068c7eu; return 0; }
r[11]<<=2;
goto P_0c068c80;
P_0c068c80: /* original 60b3, guest PC 0x0c068c80 */
if(!s->budget--) { s->failed_pc=0x0c068c80u; return 0; }
r[0]=r[11];
goto P_0c068c82;
P_0c068c82: /* original 008e, guest PC 0x0c068c82 */
if(!s->budget--) { s->failed_pc=0x0c068c82u; return 0; }
r[0]=read(ram,r[8]+r[0],4);
goto P_0c068c84;
P_0c068c84: /* original 88ff, guest PC 0x0c068c84 */
if(!s->budget--) { s->failed_pc=0x0c068c84u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c068c86;
P_0c068c86: /* original 8d36, guest PC 0x0c068c86 */
if(!s->budget--) { s->failed_pc=0x0c068c86u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(cond) { goto P_0c068cf6; }
goto P_0c068c8a;
P_0c068c88: /* original e400, guest PC 0x0c068c88 */
if(!s->budget--) { s->failed_pc=0x0c068c88u; return 0; }
r[4]=0x00000000u;
goto P_0c068c8a;
P_0c068c8a: /* original 6192, guest PC 0x0c068c8a */
if(!s->budget--) { s->failed_pc=0x0c068c8au; return 0; }
tmp=read(ram,r[9],4);
r[1]=tmp;
goto P_0c068c8c;
P_0c068c8c: /* original d22c, guest PC 0x0c068c8c */
if(!s->budget--) { s->failed_pc=0x0c068c8cu; return 0; }
r[2]=read(ram,0x0c068d40u,4);
goto P_0c068c8e;
P_0c068c8e: /* original dd23, guest PC 0x0c068c8e */
if(!s->budget--) { s->failed_pc=0x0c068c8eu; return 0; }
r[13]=read(ram,0x0c068d1cu,4);
goto P_0c068c90;
P_0c068c90: /* original 2128, guest PC 0x0c068c90 */
if(!s->budget--) { s->failed_pc=0x0c068c90u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c068c92;
P_0c068c92: /* original 8912, guest PC 0x0c068c92 */
if(!s->budget--) { s->failed_pc=0x0c068c92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068cba; }
goto P_0c068c94;
P_0c068c94: /* original 903d, guest PC 0x0c068c94 */
if(!s->budget--) { s->failed_pc=0x0c068c94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d12u,2);
goto P_0c068c96;
P_0c068c96: /* original 0a46, guest PC 0x0c068c96 */
if(!s->budget--) { s->failed_pc=0x0c068c96u; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c068c98;
P_0c068c98: /* original 60b3, guest PC 0x0c068c98 */
if(!s->budget--) { s->failed_pc=0x0c068c98u; return 0; }
r[0]=r[11];
goto P_0c068c9a;
P_0c068c9a: /* original 2e42, guest PC 0x0c068c9a */
if(!s->budget--) { s->failed_pc=0x0c068c9au; return 0; }
write(ram,r[14],r[4],4);
goto P_0c068c9c;
P_0c068c9c: /* original 933a, guest PC 0x0c068c9c */
if(!s->budget--) { s->failed_pc=0x0c068c9cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d14u,2);
goto P_0c068c9e;
P_0c068c9e: /* original 2f36, guest PC 0x0c068c9e */
if(!s->budget--) { s->failed_pc=0x0c068c9eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068ca0;
P_0c068ca0: /* original d228, guest PC 0x0c068ca0 */
if(!s->budget--) { s->failed_pc=0x0c068ca0u; return 0; }
r[2]=read(ram,0x0c068d44u,4);
goto P_0c068ca2;
P_0c068ca2: /* original 2f26, guest PC 0x0c068ca2 */
if(!s->budget--) { s->failed_pc=0x0c068ca2u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068ca4;
P_0c068ca4: /* original 2fc6, guest PC 0x0c068ca4 */
if(!s->budget--) { s->failed_pc=0x0c068ca4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068ca6;
P_0c068ca6: /* original 9636, guest PC 0x0c068ca6 */
if(!s->budget--) { s->failed_pc=0x0c068ca6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d16u,2);
goto P_0c068ca8;
P_0c068ca8: /* original d727, guest PC 0x0c068ca8 */
if(!s->budget--) { s->failed_pc=0x0c068ca8u; return 0; }
r[7]=read(ram,0x0c068d48u,4);
goto P_0c068caa;
P_0c068caa: /* original 369c, guest PC 0x0c068caa */
if(!s->budget--) { s->failed_pc=0x0c068caau; return 0; }
r[6]+=r[9];
goto P_0c068cac;
P_0c068cac: /* original 65d2, guest PC 0x0c068cac */
if(!s->budget--) { s->failed_pc=0x0c068cacu; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c068cae;
P_0c068cae: /* original d327, guest PC 0x0c068cae */
if(!s->budget--) { s->failed_pc=0x0c068caeu; return 0; }
r[3]=read(ram,0x0c068d4cu,4);
goto P_0c068cb0;
P_0c068cb0: /* original 7608, guest PC 0x0c068cb0 */
if(!s->budget--) { s->failed_pc=0x0c068cb0u; return 0; }
r[6]+=0x00000008u;
goto P_0c068cb2;
P_0c068cb2: /* original 430b, guest PC 0x0c068cb2 */
if(!s->budget--) { s->failed_pc=0x0c068cb2u; return 0; }
target=r[3];
r[16]=code_base|0x0c068cb6u;
r[4]=read(ram,r[8]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c068cb6u) { target=s->pc; goto dispatch; }
goto P_0c068cb6;
P_0c068cb4: /* original 048e, guest PC 0x0c068cb4 */
if(!s->budget--) { s->failed_pc=0x0c068cb4u; return 0; }
r[4]=read(ram,r[8]+r[0],4);
goto P_0c068cb6;
P_0c068cb6: /* original a021, guest PC 0x0c068cb6 */
if(!s->budget--) { s->failed_pc=0x0c068cb6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c068cfc;
P_0c068cb8: /* original 7f0c, guest PC 0x0c068cb8 */
if(!s->budget--) { s->failed_pc=0x0c068cb8u; return 0; }
r[15]+=0x0000000cu;
goto P_0c068cba;
P_0c068cba: /* original d325, guest PC 0x0c068cba */
if(!s->budget--) { s->failed_pc=0x0c068cbau; return 0; }
r[3]=read(ram,0x0c068d50u,4);
goto P_0c068cbc;
P_0c068cbc: /* original 60b3, guest PC 0x0c068cbc */
if(!s->budget--) { s->failed_pc=0x0c068cbcu; return 0; }
r[0]=r[11];
goto P_0c068cbe;
P_0c068cbe: /* original 65d2, guest PC 0x0c068cbe */
if(!s->budget--) { s->failed_pc=0x0c068cbeu; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c068cc0;
P_0c068cc0: /* original 430b, guest PC 0x0c068cc0 */
if(!s->budget--) { s->failed_pc=0x0c068cc0u; return 0; }
target=r[3];
r[16]=code_base|0x0c068cc4u;
r[4]=read(ram,r[8]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c068cc4u) { target=s->pc; goto dispatch; }
goto P_0c068cc4;
P_0c068cc2: /* original 048e, guest PC 0x0c068cc2 */
if(!s->budget--) { s->failed_pc=0x0c068cc2u; return 0; }
r[4]=read(ram,r[8]+r[0],4);
goto P_0c068cc4;
P_0c068cc4: /* original 64d2, guest PC 0x0c068cc4 */
if(!s->budget--) { s->failed_pc=0x0c068cc4u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c068cc6;
P_0c068cc6: /* original 9024, guest PC 0x0c068cc6 */
if(!s->budget--) { s->failed_pc=0x0c068cc6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d12u,2);
goto P_0c068cc8;
P_0c068cc8: /* original 6542, guest PC 0x0c068cc8 */
if(!s->budget--) { s->failed_pc=0x0c068cc8u; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c068cca;
P_0c068cca: /* original 6343, guest PC 0x0c068cca */
if(!s->budget--) { s->failed_pc=0x0c068ccau; return 0; }
r[3]=r[4];
goto P_0c068ccc;
P_0c068ccc: /* original 353c, guest PC 0x0c068ccc */
if(!s->budget--) { s->failed_pc=0x0c068cccu; return 0; }
r[5]+=r[3];
goto P_0c068cce;
P_0c068cce: /* original 0a56, guest PC 0x0c068cce */
if(!s->budget--) { s->failed_pc=0x0c068cceu; return 0; }
write(ram,r[10]+r[0],r[5],4);
goto P_0c068cd0;
P_0c068cd0: /* original 60c3, guest PC 0x0c068cd0 */
if(!s->budget--) { s->failed_pc=0x0c068cd0u; return 0; }
r[0]=r[12];
goto P_0c068cd2;
P_0c068cd2: /* original 5441, guest PC 0x0c068cd2 */
if(!s->budget--) { s->failed_pc=0x0c068cd2u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c068cd4;
P_0c068cd4: /* original 880c, guest PC 0x0c068cd4 */
if(!s->budget--) { s->failed_pc=0x0c068cd4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c068cd6;
P_0c068cd6: /* original 63d2, guest PC 0x0c068cd6 */
if(!s->budget--) { s->failed_pc=0x0c068cd6u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c068cd8;
P_0c068cd8: /* original 343c, guest PC 0x0c068cd8 */
if(!s->budget--) { s->failed_pc=0x0c068cd8u; return 0; }
r[4]+=r[3];
goto P_0c068cda;
P_0c068cda: /* original 8f0f, guest PC 0x0c068cda */
if(!s->budget--) { s->failed_pc=0x0c068cdau; return 0; }
cond=r[17]&1u;
write(ram,r[14],r[4],4);
if(!cond) { goto P_0c068cfc; }
goto P_0c068cde;
P_0c068cdc: /* original 2e42, guest PC 0x0c068cdc */
if(!s->budget--) { s->failed_pc=0x0c068cdcu; return 0; }
write(ram,r[14],r[4],4);
goto P_0c068cde;
P_0c068cde: /* original c713, guest PC 0x0c068cde */
if(!s->budget--) { s->failed_pc=0x0c068cdeu; return 0; }
r[0]=code_base|0x00068d2cu;
goto P_0c068ce0;
P_0c068ce0: /* original 63e2, guest PC 0x0c068ce0 */
if(!s->budget--) { s->failed_pc=0x0c068ce0u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c068ce2;
P_0c068ce2: /* original f308, guest PC 0x0c068ce2 */
if(!s->budget--) { s->failed_pc=0x0c068ce2u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c068ce4;
P_0c068ce4: /* original d012, guest PC 0x0c068ce4 */
if(!s->budget--) { s->failed_pc=0x0c068ce4u; return 0; }
r[0]=read(ram,0x0c068d30u,4);
goto P_0c068ce6;
P_0c068ce6: /* original f337, guest PC 0x0c068ce6 */
if(!s->budget--) { s->failed_pc=0x0c068ce6u; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c068ce8;
P_0c068ce8: /* original c712, guest PC 0x0c068ce8 */
if(!s->budget--) { s->failed_pc=0x0c068ce8u; return 0; }
r[0]=code_base|0x00068d34u;
goto P_0c068cea;
P_0c068cea: /* original f308, guest PC 0x0c068cea */
if(!s->budget--) { s->failed_pc=0x0c068ceau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c068cec;
P_0c068cec: /* original 900f, guest PC 0x0c068cec */
if(!s->budget--) { s->failed_pc=0x0c068cecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d0eu,2);
goto P_0c068cee;
P_0c068cee: /* original 63e2, guest PC 0x0c068cee */
if(!s->budget--) { s->failed_pc=0x0c068ceeu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c068cf0;
P_0c068cf0: /* original f337, guest PC 0x0c068cf0 */
if(!s->budget--) { s->failed_pc=0x0c068cf0u; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c068cf2;
P_0c068cf2: /* original a003, guest PC 0x0c068cf2 */
if(!s->budget--) { s->failed_pc=0x0c068cf2u; return 0; }
goto P_0c068cfc;
P_0c068cf4: /* original 0009, guest PC 0x0c068cf4 */
if(!s->budget--) { s->failed_pc=0x0c068cf4u; return 0; }
goto P_0c068cf6;
P_0c068cf6: /* original 900c, guest PC 0x0c068cf6 */
if(!s->budget--) { s->failed_pc=0x0c068cf6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d12u,2);
goto P_0c068cf8;
P_0c068cf8: /* original 0a46, guest PC 0x0c068cf8 */
if(!s->budget--) { s->failed_pc=0x0c068cf8u; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c068cfa;
P_0c068cfa: /* original 2e42, guest PC 0x0c068cfa */
if(!s->budget--) { s->failed_pc=0x0c068cfau; return 0; }
write(ram,r[14],r[4],4);
goto P_0c068cfc;
P_0c068cfc: /* original 4f26, guest PC 0x0c068cfc */
if(!s->budget--) { s->failed_pc=0x0c068cfcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c068cfe;
P_0c068cfe: /* original 68f6, guest PC 0x0c068cfe */
if(!s->budget--) { s->failed_pc=0x0c068cfeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c068d00;
P_0c068d00: /* original 69f6, guest PC 0x0c068d00 */
if(!s->budget--) { s->failed_pc=0x0c068d00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c068d02;
P_0c068d02: /* original 6af6, guest PC 0x0c068d02 */
if(!s->budget--) { s->failed_pc=0x0c068d02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c068d04;
P_0c068d04: /* original 6bf6, guest PC 0x0c068d04 */
if(!s->budget--) { s->failed_pc=0x0c068d04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c068d06;
P_0c068d06: /* original 6cf6, guest PC 0x0c068d06 */
if(!s->budget--) { s->failed_pc=0x0c068d06u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c068d08;
P_0c068d08: /* original 6df6, guest PC 0x0c068d08 */
if(!s->budget--) { s->failed_pc=0x0c068d08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c068d0a;
P_0c068d0a: /* original 000b, guest PC 0x0c068d0a */
if(!s->budget--) { s->failed_pc=0x0c068d0au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c068d0c: /* original 6ef6, guest PC 0x0c068d0c */
if(!s->budget--) { s->failed_pc=0x0c068d0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c068d0eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c068d0eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
