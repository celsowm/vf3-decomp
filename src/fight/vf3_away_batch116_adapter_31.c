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
int vf3_away_batch116_adapter_31(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c66b8u: goto P_0c0c66b8;
case 0x0c0c66bau: goto P_0c0c66ba;
case 0x0c0c7648u: goto P_0c0c7648;
case 0x0c0c764au: goto P_0c0c764a;
case 0x0c0c764cu: goto P_0c0c764c;
case 0x0c0c764eu: goto P_0c0c764e;
case 0x0c0c7650u: goto P_0c0c7650;
case 0x0c0c7652u: goto P_0c0c7652;
case 0x0c0c7654u: goto P_0c0c7654;
case 0x0c0c7656u: goto P_0c0c7656;
case 0x0c0c7658u: goto P_0c0c7658;
case 0x0c0c765au: goto P_0c0c765a;
case 0x0c0c765cu: goto P_0c0c765c;
case 0x0c0c765eu: goto P_0c0c765e;
case 0x0c0c7660u: goto P_0c0c7660;
case 0x0c0c7662u: goto P_0c0c7662;
case 0x0c0c7664u: goto P_0c0c7664;
case 0x0c0c7666u: goto P_0c0c7666;
case 0x0c0c7668u: goto P_0c0c7668;
case 0x0c0c766au: goto P_0c0c766a;
case 0x0c0c766cu: goto P_0c0c766c;
case 0x0c0c766eu: goto P_0c0c766e;
case 0x0c0c7670u: goto P_0c0c7670;
case 0x0c0c7672u: goto P_0c0c7672;
case 0x0c0c7674u: goto P_0c0c7674;
case 0x0c0c7676u: goto P_0c0c7676;
case 0x0c0c7678u: goto P_0c0c7678;
case 0x0c0c767au: goto P_0c0c767a;
case 0x0c0c767cu: goto P_0c0c767c;
case 0x0c0c767eu: goto P_0c0c767e;
case 0x0c0c7680u: goto P_0c0c7680;
case 0x0c0c7682u: goto P_0c0c7682;
case 0x0c0c7684u: goto P_0c0c7684;
case 0x0c0c7686u: goto P_0c0c7686;
case 0x0c0c7688u: goto P_0c0c7688;
case 0x0c0c768au: goto P_0c0c768a;
case 0x0c0c768cu: goto P_0c0c768c;
case 0x0c0c768eu: goto P_0c0c768e;
case 0x0c0c7690u: goto P_0c0c7690;
case 0x0c0c7692u: goto P_0c0c7692;
case 0x0c0c7694u: goto P_0c0c7694;
case 0x0c0c7696u: goto P_0c0c7696;
case 0x0c0c7698u: goto P_0c0c7698;
case 0x0c0c769au: goto P_0c0c769a;
case 0x0c0c769cu: goto P_0c0c769c;
case 0x0c0c769eu: goto P_0c0c769e;
case 0x0c0c76a0u: goto P_0c0c76a0;
case 0x0c0c76a2u: goto P_0c0c76a2;
case 0x0c0c76a4u: goto P_0c0c76a4;
case 0x0c0c76a6u: goto P_0c0c76a6;
case 0x0c0c76a8u: goto P_0c0c76a8;
case 0x0c0c76aau: goto P_0c0c76aa;
case 0x0c0c76acu: goto P_0c0c76ac;
case 0x0c0c76aeu: goto P_0c0c76ae;
case 0x0c0c76b0u: goto P_0c0c76b0;
case 0x0c0c76b2u: goto P_0c0c76b2;
case 0x0c0c76b4u: goto P_0c0c76b4;
case 0x0c0c76b6u: goto P_0c0c76b6;
case 0x0c0c76b8u: goto P_0c0c76b8;
case 0x0c0c76bau: goto P_0c0c76ba;
case 0x0c0c76bcu: goto P_0c0c76bc;
case 0x0c0c76beu: goto P_0c0c76be;
case 0x0c0c7de8u: goto P_0c0c7de8;
case 0x0c0c7deau: goto P_0c0c7dea;
case 0x0c0c7decu: goto P_0c0c7dec;
case 0x0c0c7deeu: goto P_0c0c7dee;
case 0x0c0c7df0u: goto P_0c0c7df0;
case 0x0c0c7df2u: goto P_0c0c7df2;
case 0x0c0c7df4u: goto P_0c0c7df4;
case 0x0c0c7df6u: goto P_0c0c7df6;
case 0x0c0c7df8u: goto P_0c0c7df8;
case 0x0c0c7dfau: goto P_0c0c7dfa;
case 0x0c0c7dfcu: goto P_0c0c7dfc;
case 0x0c0c7dfeu: goto P_0c0c7dfe;
case 0x0c0c7e00u: goto P_0c0c7e00;
case 0x0c0c7e02u: goto P_0c0c7e02;
case 0x0c0c7e04u: goto P_0c0c7e04;
case 0x0c0c7e06u: goto P_0c0c7e06;
case 0x0c0c7e08u: goto P_0c0c7e08;
case 0x0c0c7e0au: goto P_0c0c7e0a;
case 0x0c0c7e0cu: goto P_0c0c7e0c;
case 0x0c0c7e0eu: goto P_0c0c7e0e;
case 0x0c0c7e10u: goto P_0c0c7e10;
case 0x0c0c7e12u: goto P_0c0c7e12;
case 0x0c0c7e14u: goto P_0c0c7e14;
case 0x0c0c7e16u: goto P_0c0c7e16;
case 0x0c0c7e18u: goto P_0c0c7e18;
case 0x0c0c7e1au: goto P_0c0c7e1a;
case 0x0c0c7e1cu: goto P_0c0c7e1c;
case 0x0c0c7e1eu: goto P_0c0c7e1e;
case 0x0c0c7e20u: goto P_0c0c7e20;
case 0x0c0c7e22u: goto P_0c0c7e22;
case 0x0c0c7e24u: goto P_0c0c7e24;
case 0x0c0c7e26u: goto P_0c0c7e26;
case 0x0c0c7e28u: goto P_0c0c7e28;
case 0x0c0c7e2au: goto P_0c0c7e2a;
case 0x0c0c7e2cu: goto P_0c0c7e2c;
case 0x0c0c7e2eu: goto P_0c0c7e2e;
case 0x0c0c7e30u: goto P_0c0c7e30;
case 0x0c0c7e32u: goto P_0c0c7e32;
case 0x0c0c7e34u: goto P_0c0c7e34;
case 0x0c0c7e36u: goto P_0c0c7e36;
case 0x0c0c7e38u: goto P_0c0c7e38;
case 0x0c0c7e3au: goto P_0c0c7e3a;
case 0x0c0c7e3cu: goto P_0c0c7e3c;
case 0x0c0c7e3eu: goto P_0c0c7e3e;
case 0x0c0c7e40u: goto P_0c0c7e40;
case 0x0c0c7e42u: goto P_0c0c7e42;
case 0x0c0c7e44u: goto P_0c0c7e44;
case 0x0c0c7e46u: goto P_0c0c7e46;
case 0x0c0c7e48u: goto P_0c0c7e48;
case 0x0c0c7e4au: goto P_0c0c7e4a;
case 0x0c0c7e4cu: goto P_0c0c7e4c;
case 0x0c0c7e4eu: goto P_0c0c7e4e;
case 0x0c0c7e50u: goto P_0c0c7e50;
case 0x0c0c7e52u: goto P_0c0c7e52;
case 0x0c0c7e54u: goto P_0c0c7e54;
case 0x0c0c7e56u: goto P_0c0c7e56;
case 0x0c0c7e58u: goto P_0c0c7e58;
case 0x0c0c7e5au: goto P_0c0c7e5a;
case 0x0c0c7e5cu: goto P_0c0c7e5c;
case 0x0c0c7e5eu: goto P_0c0c7e5e;
case 0x0c0c7e60u: goto P_0c0c7e60;
case 0x0c0c7e62u: goto P_0c0c7e62;
case 0x0c0c7e64u: goto P_0c0c7e64;
case 0x0c0c7e66u: goto P_0c0c7e66;
case 0x0c0c7e68u: goto P_0c0c7e68;
case 0x0c0c7e6au: goto P_0c0c7e6a;
case 0x0c0c7e6cu: goto P_0c0c7e6c;
case 0x0c0c7e6eu: goto P_0c0c7e6e;
case 0x0c0c7e70u: goto P_0c0c7e70;
case 0x0c0c7e72u: goto P_0c0c7e72;
case 0x0c0c7e74u: goto P_0c0c7e74;
case 0x0c0c7e76u: goto P_0c0c7e76;
case 0x0c0c7e78u: goto P_0c0c7e78;
case 0x0c0c7e7au: goto P_0c0c7e7a;
case 0x0c0c7e7cu: goto P_0c0c7e7c;
case 0x0c0c7e7eu: goto P_0c0c7e7e;
case 0x0c0c7e80u: goto P_0c0c7e80;
case 0x0c0c7e82u: goto P_0c0c7e82;
case 0x0c0c7e84u: goto P_0c0c7e84;
case 0x0c0c7e86u: goto P_0c0c7e86;
case 0x0c0c7e88u: goto P_0c0c7e88;
case 0x0c0c7e8au: goto P_0c0c7e8a;
case 0x0c0c7e8cu: goto P_0c0c7e8c;
case 0x0c0c7e8eu: goto P_0c0c7e8e;
case 0x0c0c7e90u: goto P_0c0c7e90;
case 0x0c0c7e92u: goto P_0c0c7e92;
case 0x0c0c7e94u: goto P_0c0c7e94;
case 0x0c0c7e96u: goto P_0c0c7e96;
case 0x0c0c7e98u: goto P_0c0c7e98;
case 0x0c0c7e9au: goto P_0c0c7e9a;
case 0x0c0c7e9cu: goto P_0c0c7e9c;
case 0x0c0c7e9eu: goto P_0c0c7e9e;
case 0x0c0c7ea0u: goto P_0c0c7ea0;
case 0x0c0c7ea2u: goto P_0c0c7ea2;
case 0x0c0c7ea4u: goto P_0c0c7ea4;
case 0x0c0c7ea6u: goto P_0c0c7ea6;
case 0x0c0c7ea8u: goto P_0c0c7ea8;
case 0x0c0c7eaau: goto P_0c0c7eaa;
case 0x0c0c7eacu: goto P_0c0c7eac;
case 0x0c0c7eaeu: goto P_0c0c7eae;
case 0x0c0c7eb0u: goto P_0c0c7eb0;
case 0x0c0c7eb2u: goto P_0c0c7eb2;
case 0x0c0c7eb4u: goto P_0c0c7eb4;
case 0x0c0c7eb6u: goto P_0c0c7eb6;
case 0x0c0c7eb8u: goto P_0c0c7eb8;
case 0x0c0c7ebau: goto P_0c0c7eba;
case 0x0c0c7ebcu: goto P_0c0c7ebc;
case 0x0c0c7ebeu: goto P_0c0c7ebe;
case 0x0c0c7ec0u: goto P_0c0c7ec0;
case 0x0c0c7ec2u: goto P_0c0c7ec2;
case 0x0c0c7ec4u: goto P_0c0c7ec4;
case 0x0c0c7ec6u: goto P_0c0c7ec6;
case 0x0c0c7ec8u: goto P_0c0c7ec8;
case 0x0c0c7ecau: goto P_0c0c7eca;
case 0x0c0c7eccu: goto P_0c0c7ecc;
case 0x0c0c7eceu: goto P_0c0c7ece;
case 0x0c0c7ed0u: goto P_0c0c7ed0;
case 0x0c0c7ed2u: goto P_0c0c7ed2;
case 0x0c0c7ed4u: goto P_0c0c7ed4;
case 0x0c0c7ed6u: goto P_0c0c7ed6;
case 0x0c0c7ed8u: goto P_0c0c7ed8;
case 0x0c0c7edau: goto P_0c0c7eda;
case 0x0c0c7edcu: goto P_0c0c7edc;
case 0x0c0c7edeu: goto P_0c0c7ede;
case 0x0c0c7ee0u: goto P_0c0c7ee0;
case 0x0c0c7ee2u: goto P_0c0c7ee2;
case 0x0c0c7ee4u: goto P_0c0c7ee4;
case 0x0c0c7ee6u: goto P_0c0c7ee6;
case 0x0c0c7ee8u: goto P_0c0c7ee8;
case 0x0c0c7eeau: goto P_0c0c7eea;
case 0x0c0c7eecu: goto P_0c0c7eec;
case 0x0c0c7eeeu: goto P_0c0c7eee;
case 0x0c0c7ef0u: goto P_0c0c7ef0;
case 0x0c0c7ef2u: goto P_0c0c7ef2;
case 0x0c0c7ef4u: goto P_0c0c7ef4;
case 0x0c0c7ef6u: goto P_0c0c7ef6;
case 0x0c0c7ef8u: goto P_0c0c7ef8;
case 0x0c0c7efau: goto P_0c0c7efa;
case 0x0c0c7efcu: goto P_0c0c7efc;
case 0x0c0c7efeu: goto P_0c0c7efe;
case 0x0c0c7f00u: goto P_0c0c7f00;
case 0x0c0c7f02u: goto P_0c0c7f02;
case 0x0c0c7f44u: goto P_0c0c7f44;
case 0x0c0c7f46u: goto P_0c0c7f46;
case 0x0c0c7f48u: goto P_0c0c7f48;
case 0x0c0c7f4au: goto P_0c0c7f4a;
case 0x0c0c7f4cu: goto P_0c0c7f4c;
case 0x0c0c7f4eu: goto P_0c0c7f4e;
case 0x0c0c7f50u: goto P_0c0c7f50;
case 0x0c0c7f52u: goto P_0c0c7f52;
case 0x0c0c7f54u: goto P_0c0c7f54;
case 0x0c0c7f56u: goto P_0c0c7f56;
case 0x0c0c7f58u: goto P_0c0c7f58;
case 0x0c0c7f5au: goto P_0c0c7f5a;
case 0x0c0c7f5cu: goto P_0c0c7f5c;
case 0x0c0c7f5eu: goto P_0c0c7f5e;
case 0x0c0c7f60u: goto P_0c0c7f60;
case 0x0c0c7f62u: goto P_0c0c7f62;
case 0x0c0c7f64u: goto P_0c0c7f64;
case 0x0c0c7f66u: goto P_0c0c7f66;
case 0x0c0c7f68u: goto P_0c0c7f68;
case 0x0c0c7f6au: goto P_0c0c7f6a;
case 0x0c0c7f6cu: goto P_0c0c7f6c;
case 0x0c0c7f6eu: goto P_0c0c7f6e;
case 0x0c0c7f70u: goto P_0c0c7f70;
case 0x0c0c7f72u: goto P_0c0c7f72;
case 0x0c0c7f74u: goto P_0c0c7f74;
case 0x0c0c7f76u: goto P_0c0c7f76;
case 0x0c0c7f78u: goto P_0c0c7f78;
case 0x0c0c7f7au: goto P_0c0c7f7a;
case 0x0c0c7f7cu: goto P_0c0c7f7c;
case 0x0c0c7f7eu: goto P_0c0c7f7e;
case 0x0c0c7f80u: goto P_0c0c7f80;
case 0x0c0c7f82u: goto P_0c0c7f82;
case 0x0c0c7f84u: goto P_0c0c7f84;
case 0x0c0c7f86u: goto P_0c0c7f86;
case 0x0c0c7f88u: goto P_0c0c7f88;
case 0x0c0c7f8au: goto P_0c0c7f8a;
case 0x0c0c7f8cu: goto P_0c0c7f8c;
case 0x0c0c7f8eu: goto P_0c0c7f8e;
case 0x0c0c7f90u: goto P_0c0c7f90;
case 0x0c0c7f92u: goto P_0c0c7f92;
case 0x0c0c7f94u: goto P_0c0c7f94;
case 0x0c0c7f96u: goto P_0c0c7f96;
case 0x0c0c7f98u: goto P_0c0c7f98;
case 0x0c0c7f9au: goto P_0c0c7f9a;
case 0x0c0c7f9cu: goto P_0c0c7f9c;
case 0x0c0c7f9eu: goto P_0c0c7f9e;
case 0x0c0c7fa0u: goto P_0c0c7fa0;
case 0x0c0c7fa2u: goto P_0c0c7fa2;
case 0x0c0c7fa4u: goto P_0c0c7fa4;
case 0x0c0c7fa6u: goto P_0c0c7fa6;
case 0x0c0c7fa8u: goto P_0c0c7fa8;
case 0x0c0c7faau: goto P_0c0c7faa;
case 0x0c0c7facu: goto P_0c0c7fac;
case 0x0c0c7faeu: goto P_0c0c7fae;
case 0x0c0c7fb0u: goto P_0c0c7fb0;
case 0x0c0c7fb2u: goto P_0c0c7fb2;
case 0x0c0c7fb4u: goto P_0c0c7fb4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c66b8: /* original 000b, guest PC 0x0c0c66b8 */
if(!s->budget--) { s->failed_pc=0x0c0c66b8u; return 0; }
target=r[16];
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c66ba: /* original 6040, guest PC 0x0c0c66ba */
if(!s->budget--) { s->failed_pc=0x0c0c66bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
if(!vf3_matrix_family(0x0c0c66bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66bcu; return 0; } return 1;
P_0c0c7648: /* original 2fe6, guest PC 0x0c0c7648 */
if(!s->budget--) { s->failed_pc=0x0c0c7648u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c764a;
P_0c0c764a: /* original 2fd6, guest PC 0x0c0c764a */
if(!s->budget--) { s->failed_pc=0x0c0c764au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c764c;
P_0c0c764c: /* original 2fc6, guest PC 0x0c0c764c */
if(!s->budget--) { s->failed_pc=0x0c0c764cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c764e;
P_0c0c764e: /* original 2fb6, guest PC 0x0c0c764e */
if(!s->budget--) { s->failed_pc=0x0c0c764eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7650;
P_0c0c7650: /* original 2fa6, guest PC 0x0c0c7650 */
if(!s->budget--) { s->failed_pc=0x0c0c7650u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7652;
P_0c0c7652: /* original 2f96, guest PC 0x0c0c7652 */
if(!s->budget--) { s->failed_pc=0x0c0c7652u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7654;
P_0c0c7654: /* original da40, guest PC 0x0c0c7654 */
if(!s->budget--) { s->failed_pc=0x0c0c7654u; return 0; }
r[10]=read(ram,0x0c0c7758u,4);
goto P_0c0c7656;
P_0c0c7656: /* original 9077, guest PC 0x0c0c7656 */
if(!s->budget--) { s->failed_pc=0x0c0c7656u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7748u,2);
goto P_0c0c7658;
P_0c0c7658: /* original 4f22, guest PC 0x0c0c7658 */
if(!s->budget--) { s->failed_pc=0x0c0c7658u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c765a;
P_0c0c765a: /* original 0cae, guest PC 0x0c0c765a */
if(!s->budget--) { s->failed_pc=0x0c0c765au; return 0; }
r[12]=read(ram,r[10]+r[0],4);
goto P_0c0c765c;
P_0c0c765c: /* original 7004, guest PC 0x0c0c765c */
if(!s->budget--) { s->failed_pc=0x0c0c765cu; return 0; }
r[0]+=0x00000004u;
goto P_0c0c765e;
P_0c0c765e: /* original dd3f, guest PC 0x0c0c765e */
if(!s->budget--) { s->failed_pc=0x0c0c765eu; return 0; }
r[13]=read(ram,0x0c0c775cu,4);
goto P_0c0c7660;
P_0c0c7660: /* original 2cc8, guest PC 0x0c0c7660 */
if(!s->budget--) { s->failed_pc=0x0c0c7660u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0c7662;
P_0c0c7662: /* original 8d0e, guest PC 0x0c0c7662 */
if(!s->budget--) { s->failed_pc=0x0c0c7662u; return 0; }
cond=r[17]&1u;
r[11]=read(ram,r[10]+r[0],4);
if(cond) { goto P_0c0c7682; }
goto P_0c0c7666;
P_0c0c7664: /* original 0bae, guest PC 0x0c0c7664 */
if(!s->budget--) { s->failed_pc=0x0c0c7664u; return 0; }
r[11]=read(ram,r[10]+r[0],4);
goto P_0c0c7666;
P_0c0c7666: /* original 85c6, guest PC 0x0c0c7666 */
if(!s->budget--) { s->failed_pc=0x0c0c7666u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+12,2);
goto P_0c0c7668;
P_0c0c7668: /* original 996f, guest PC 0x0c0c7668 */
if(!s->budget--) { s->failed_pc=0x0c0c7668u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774au,2);
goto P_0c0c766a;
P_0c0c766a: /* original 6e0d, guest PC 0x0c0c766a */
if(!s->budget--) { s->failed_pc=0x0c0c766au; return 0; }
r[14]=r[0]&65535u;
goto P_0c0c766c;
P_0c0c766c: /* original 4e15, guest PC 0x0c0c766c */
if(!s->budget--) { s->failed_pc=0x0c0c766cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c766e;
P_0c0c766e: /* original 8b05, guest PC 0x0c0c766e */
if(!s->budget--) { s->failed_pc=0x0c0c766eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c767c; }
goto P_0c0c7670;
P_0c0c7670: /* original 6493, guest PC 0x0c0c7670 */
if(!s->budget--) { s->failed_pc=0x0c0c7670u; return 0; }
r[4]=r[9];
goto P_0c0c7672;
P_0c0c7672: /* original 4d0b, guest PC 0x0c0c7672 */
if(!s->budget--) { s->failed_pc=0x0c0c7672u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c7676u;
r[9]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7676u) { target=s->pc; goto dispatch; }
goto P_0c0c7676;
P_0c0c7674: /* original 7901, guest PC 0x0c0c7674 */
if(!s->budget--) { s->failed_pc=0x0c0c7674u; return 0; }
r[9]+=0x00000001u;
goto P_0c0c7676;
P_0c0c7676: /* original 7eff, guest PC 0x0c0c7676 */
if(!s->budget--) { s->failed_pc=0x0c0c7676u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0c7678;
P_0c0c7678: /* original 4e15, guest PC 0x0c0c7678 */
if(!s->budget--) { s->failed_pc=0x0c0c7678u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c767a;
P_0c0c767a: /* original 89f9, guest PC 0x0c0c767a */
if(!s->budget--) { s->failed_pc=0x0c0c767au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7670; }
goto P_0c0c767c;
P_0c0c767c: /* original d338, guest PC 0x0c0c767c */
if(!s->budget--) { s->failed_pc=0x0c0c767cu; return 0; }
r[3]=read(ram,0x0c0c7760u,4);
goto P_0c0c767e;
P_0c0c767e: /* original 430b, guest PC 0x0c0c767e */
if(!s->budget--) { s->failed_pc=0x0c0c767eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7682u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7682u) { target=s->pc; goto dispatch; }
goto P_0c0c7682;
P_0c0c7680: /* original 64c3, guest PC 0x0c0c7680 */
if(!s->budget--) { s->failed_pc=0x0c0c7680u; return 0; }
r[4]=r[12];
goto P_0c0c7682;
P_0c0c7682: /* original 2bb8, guest PC 0x0c0c7682 */
if(!s->budget--) { s->failed_pc=0x0c0c7682u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0c7684;
P_0c0c7684: /* original 890d, guest PC 0x0c0c7684 */
if(!s->budget--) { s->failed_pc=0x0c0c7684u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c76a2; }
goto P_0c0c7686;
P_0c0c7686: /* original 85b6, guest PC 0x0c0c7686 */
if(!s->budget--) { s->failed_pc=0x0c0c7686u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+12,2);
goto P_0c0c7688;
P_0c0c7688: /* original 9c60, guest PC 0x0c0c7688 */
if(!s->budget--) { s->failed_pc=0x0c0c7688u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774cu,2);
goto P_0c0c768a;
P_0c0c768a: /* original 6e0d, guest PC 0x0c0c768a */
if(!s->budget--) { s->failed_pc=0x0c0c768au; return 0; }
r[14]=r[0]&65535u;
goto P_0c0c768c;
P_0c0c768c: /* original 4e15, guest PC 0x0c0c768c */
if(!s->budget--) { s->failed_pc=0x0c0c768cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c768e;
P_0c0c768e: /* original 8b05, guest PC 0x0c0c768e */
if(!s->budget--) { s->failed_pc=0x0c0c768eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c769c; }
goto P_0c0c7690;
P_0c0c7690: /* original 64c3, guest PC 0x0c0c7690 */
if(!s->budget--) { s->failed_pc=0x0c0c7690u; return 0; }
r[4]=r[12];
goto P_0c0c7692;
P_0c0c7692: /* original 4d0b, guest PC 0x0c0c7692 */
if(!s->budget--) { s->failed_pc=0x0c0c7692u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c7696u;
r[12]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7696u) { target=s->pc; goto dispatch; }
goto P_0c0c7696;
P_0c0c7694: /* original 7c01, guest PC 0x0c0c7694 */
if(!s->budget--) { s->failed_pc=0x0c0c7694u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c7696;
P_0c0c7696: /* original 7eff, guest PC 0x0c0c7696 */
if(!s->budget--) { s->failed_pc=0x0c0c7696u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0c7698;
P_0c0c7698: /* original 4e15, guest PC 0x0c0c7698 */
if(!s->budget--) { s->failed_pc=0x0c0c7698u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c769a;
P_0c0c769a: /* original 89f9, guest PC 0x0c0c769a */
if(!s->budget--) { s->failed_pc=0x0c0c769au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7690; }
goto P_0c0c769c;
P_0c0c769c: /* original d330, guest PC 0x0c0c769c */
if(!s->budget--) { s->failed_pc=0x0c0c769cu; return 0; }
r[3]=read(ram,0x0c0c7760u,4);
goto P_0c0c769e;
P_0c0c769e: /* original 430b, guest PC 0x0c0c769e */
if(!s->budget--) { s->failed_pc=0x0c0c769eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c76a2u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c76a2u) { target=s->pc; goto dispatch; }
goto P_0c0c76a2;
P_0c0c76a0: /* original 64b3, guest PC 0x0c0c76a0 */
if(!s->budget--) { s->failed_pc=0x0c0c76a0u; return 0; }
r[4]=r[11];
goto P_0c0c76a2;
P_0c0c76a2: /* original 9054, guest PC 0x0c0c76a2 */
if(!s->budget--) { s->failed_pc=0x0c0c76a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774eu,2);
goto P_0c0c76a4;
P_0c0c76a4: /* original e400, guest PC 0x0c0c76a4 */
if(!s->budget--) { s->failed_pc=0x0c0c76a4u; return 0; }
r[4]=0x00000000u;
goto P_0c0c76a6;
P_0c0c76a6: /* original 4f26, guest PC 0x0c0c76a6 */
if(!s->budget--) { s->failed_pc=0x0c0c76a6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c76a8;
P_0c0c76a8: /* original 0a46, guest PC 0x0c0c76a8 */
if(!s->budget--) { s->failed_pc=0x0c0c76a8u; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c0c76aa;
P_0c0c76aa: /* original 70f8, guest PC 0x0c0c76aa */
if(!s->budget--) { s->failed_pc=0x0c0c76aau; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c76ac;
P_0c0c76ac: /* original 0a46, guest PC 0x0c0c76ac */
if(!s->budget--) { s->failed_pc=0x0c0c76acu; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c0c76ae;
P_0c0c76ae: /* original 7004, guest PC 0x0c0c76ae */
if(!s->budget--) { s->failed_pc=0x0c0c76aeu; return 0; }
r[0]+=0x00000004u;
goto P_0c0c76b0;
P_0c0c76b0: /* original 0a46, guest PC 0x0c0c76b0 */
if(!s->budget--) { s->failed_pc=0x0c0c76b0u; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c0c76b2;
P_0c0c76b2: /* original 69f6, guest PC 0x0c0c76b2 */
if(!s->budget--) { s->failed_pc=0x0c0c76b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c76b4;
P_0c0c76b4: /* original 6af6, guest PC 0x0c0c76b4 */
if(!s->budget--) { s->failed_pc=0x0c0c76b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c76b6;
P_0c0c76b6: /* original 6bf6, guest PC 0x0c0c76b6 */
if(!s->budget--) { s->failed_pc=0x0c0c76b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c76b8;
P_0c0c76b8: /* original 6cf6, guest PC 0x0c0c76b8 */
if(!s->budget--) { s->failed_pc=0x0c0c76b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c76ba;
P_0c0c76ba: /* original 6df6, guest PC 0x0c0c76ba */
if(!s->budget--) { s->failed_pc=0x0c0c76bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c76bc;
P_0c0c76bc: /* original 000b, guest PC 0x0c0c76bc */
if(!s->budget--) { s->failed_pc=0x0c0c76bcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c76be: /* original 6ef6, guest PC 0x0c0c76be */
if(!s->budget--) { s->failed_pc=0x0c0c76beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c76c0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c76c0u; return 0; } return 1;
P_0c0c7de8: /* original d54a, guest PC 0x0c0c7de8 */
if(!s->budget--) { s->failed_pc=0x0c0c7de8u; return 0; }
r[5]=read(ram,0x0c0c7f14u,4);
goto P_0c0c7dea;
P_0c0c7dea: /* original e01c, guest PC 0x0c0c7dea */
if(!s->budget--) { s->failed_pc=0x0c0c7deau; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7dec;
P_0c0c7dec: /* original e30f, guest PC 0x0c0c7dec */
if(!s->budget--) { s->failed_pc=0x0c0c7decu; return 0; }
r[3]=0x0000000fu;
goto P_0c0c7dee;
P_0c0c7dee: /* original 9189, guest PC 0x0c0c7dee */
if(!s->budget--) { s->failed_pc=0x0c0c7deeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f04u,2);
goto P_0c0c7df0;
P_0c0c7df0: /* original 045c, guest PC 0x0c0c7df0 */
if(!s->budget--) { s->failed_pc=0x0c0c7df0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c7df2;
P_0c0c7df2: /* original d049, guest PC 0x0c0c7df2 */
if(!s->budget--) { s->failed_pc=0x0c0c7df2u; return 0; }
r[0]=read(ram,0x0c0c7f18u,4);
goto P_0c0c7df4;
P_0c0c7df4: /* original 315c, guest PC 0x0c0c7df4 */
if(!s->budget--) { s->failed_pc=0x0c0c7df4u; return 0; }
r[1]+=r[5];
goto P_0c0c7df6;
P_0c0c7df6: /* original 644c, guest PC 0x0c0c7df6 */
if(!s->budget--) { s->failed_pc=0x0c0c7df6u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c7df8;
P_0c0c7df8: /* original 2439, guest PC 0x0c0c7df8 */
if(!s->budget--) { s->failed_pc=0x0c0c7df8u; return 0; }
r[4]&=r[3];
goto P_0c0c7dfa;
P_0c0c7dfa: /* original 024c, guest PC 0x0c0c7dfa */
if(!s->budget--) { s->failed_pc=0x0c0c7dfau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7dfc;
P_0c0c7dfc: /* original 000b, guest PC 0x0c0c7dfc */
if(!s->budget--) { s->failed_pc=0x0c0c7dfcu; return 0; }
target=r[16];
write(ram,r[1],r[2],1);
s->pc=target; return ram->oob==0;
P_0c0c7dfe: /* original 2120, guest PC 0x0c0c7dfe */
if(!s->budget--) { s->failed_pc=0x0c0c7dfeu; return 0; }
write(ram,r[1],r[2],1);
goto P_0c0c7e00;
P_0c0c7e00: /* original 7ff8, guest PC 0x0c0c7e00 */
if(!s->budget--) { s->failed_pc=0x0c0c7e00u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c7e02;
P_0c0c7e02: /* original 2f42, guest PC 0x0c0c7e02 */
if(!s->budget--) { s->failed_pc=0x0c0c7e02u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c7e04;
P_0c0c7e04: /* original 1f51, guest PC 0x0c0c7e04 */
if(!s->budget--) { s->failed_pc=0x0c0c7e04u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0c7e06;
P_0c0c7e06: /* original 63f2, guest PC 0x0c0c7e06 */
if(!s->budget--) { s->failed_pc=0x0c0c7e06u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c7e08;
P_0c0c7e08: /* original d544, guest PC 0x0c0c7e08 */
if(!s->budget--) { s->failed_pc=0x0c0c7e08u; return 0; }
r[5]=read(ram,0x0c0c7f1cu,4);
goto P_0c0c7e0a;
P_0c0c7e0a: /* original 2338, guest PC 0x0c0c7e0a */
if(!s->budget--) { s->failed_pc=0x0c0c7e0au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c7e0c;
P_0c0c7e0c: /* original 8b01, guest PC 0x0c0c7e0c */
if(!s->budget--) { s->failed_pc=0x0c0c7e0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7e12; }
goto P_0c0c7e0e;
P_0c0c7e0e: /* original a001, guest PC 0x0c0c7e0e */
if(!s->budget--) { s->failed_pc=0x0c0c7e0eu; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c0c7e14;
P_0c0c7e10: /* original 5454, guest PC 0x0c0c7e10 */
if(!s->budget--) { s->failed_pc=0x0c0c7e10u; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c0c7e12;
P_0c0c7e12: /* original 5455, guest PC 0x0c0c7e12 */
if(!s->budget--) { s->failed_pc=0x0c0c7e12u; return 0; }
r[4]=read(ram,r[5]+20,4);
goto P_0c0c7e14;
P_0c0c7e14: /* original 65f2, guest PC 0x0c0c7e14 */
if(!s->budget--) { s->failed_pc=0x0c0c7e14u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0c7e16;
P_0c0c7e16: /* original 56f1, guest PC 0x0c0c7e16 */
if(!s->budget--) { s->failed_pc=0x0c0c7e16u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c0c7e18;
P_0c0c7e18: /* original a000, guest PC 0x0c0c7e18 */
if(!s->budget--) { s->failed_pc=0x0c0c7e18u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c7e1c;
P_0c0c7e1a: /* original 7f08, guest PC 0x0c0c7e1a */
if(!s->budget--) { s->failed_pc=0x0c0c7e1au; return 0; }
r[15]+=0x00000008u;
goto P_0c0c7e1c;
P_0c0c7e1c: /* original 2fe6, guest PC 0x0c0c7e1c */
if(!s->budget--) { s->failed_pc=0x0c0c7e1cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7e1e;
P_0c0c7e1e: /* original e00c, guest PC 0x0c0c7e1e */
if(!s->budget--) { s->failed_pc=0x0c0c7e1eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c7e20;
P_0c0c7e20: /* original 2fd6, guest PC 0x0c0c7e20 */
if(!s->budget--) { s->failed_pc=0x0c0c7e20u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7e22;
P_0c0c7e22: /* original 6d53, guest PC 0x0c0c7e22 */
if(!s->budget--) { s->failed_pc=0x0c0c7e22u; return 0; }
r[13]=r[5];
goto P_0c0c7e24;
P_0c0c7e24: /* original 2fc6, guest PC 0x0c0c7e24 */
if(!s->budget--) { s->failed_pc=0x0c0c7e24u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7e26;
P_0c0c7e26: /* original 2fb6, guest PC 0x0c0c7e26 */
if(!s->budget--) { s->failed_pc=0x0c0c7e26u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7e28;
P_0c0c7e28: /* original fffb, guest PC 0x0c0c7e28 */
if(!s->budget--) { s->failed_pc=0x0c0c7e28u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c7e2a;
P_0c0c7e2a: /* original 4f22, guest PC 0x0c0c7e2a */
if(!s->budget--) { s->failed_pc=0x0c0c7e2au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7e2c;
P_0c0c7e2c: /* original 7fec, guest PC 0x0c0c7e2c */
if(!s->budget--) { s->failed_pc=0x0c0c7e2cu; return 0; }
r[15]+=0xffffffecu;
goto P_0c0c7e2e;
P_0c0c7e2e: /* original ff47, guest PC 0x0c0c7e2e */
if(!s->budget--) { s->failed_pc=0x0c0c7e2eu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0c7e30;
P_0c0c7e30: /* original e010, guest PC 0x0c0c7e30 */
if(!s->budget--) { s->failed_pc=0x0c0c7e30u; return 0; }
r[0]=0x00000010u;
goto P_0c0c7e32;
P_0c0c7e32: /* original ff67, guest PC 0x0c0c7e32 */
if(!s->budget--) { s->failed_pc=0x0c0c7e32u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c0c7e34;
P_0c0c7e34: /* original 1f62, guest PC 0x0c0c7e34 */
if(!s->budget--) { s->failed_pc=0x0c0c7e34u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c0c7e36;
P_0c0c7e36: /* original dc37, guest PC 0x0c0c7e36 */
if(!s->budget--) { s->failed_pc=0x0c0c7e36u; return 0; }
r[12]=read(ram,0x0c0c7f14u,4);
goto P_0c0c7e38;
P_0c0c7e38: /* original bfd6, guest PC 0x0c0c7e38 */
if(!s->budget--) { s->failed_pc=0x0c0c7e38u; return 0; }
target=code_base|0x0c0c7de8u; r[16]=code_base|0x0c0c7e3cu;
r[14]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7e3cu) { target=s->pc; goto dispatch; }
goto P_0c0c7e3c;
P_0c0c7e3a: /* original 6e43, guest PC 0x0c0c7e3a */
if(!s->budget--) { s->failed_pc=0x0c0c7e3au; return 0; }
r[14]=r[4];
goto P_0c0c7e3c;
P_0c0c7e3c: /* original 60d3, guest PC 0x0c0c7e3c */
if(!s->budget--) { s->failed_pc=0x0c0c7e3cu; return 0; }
r[0]=r[13];
goto P_0c0c7e3e;
P_0c0c7e3e: /* original 80e4, guest PC 0x0c0c7e3e */
if(!s->budget--) { s->failed_pc=0x0c0c7e3eu; return 0; }
write(ram,r[14]+4,r[0],1);
goto P_0c0c7e40;
P_0c0c7e40: /* original e01c, guest PC 0x0c0c7e40 */
if(!s->budget--) { s->failed_pc=0x0c0c7e40u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7e42;
P_0c0c7e42: /* original d337, guest PC 0x0c0c7e42 */
if(!s->budget--) { s->failed_pc=0x0c0c7e42u; return 0; }
r[3]=read(ram,0x0c0c7f20u,4);
goto P_0c0c7e44;
P_0c0c7e44: /* original 04cc, guest PC 0x0c0c7e44 */
if(!s->budget--) { s->failed_pc=0x0c0c7e44u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c7e46;
P_0c0c7e46: /* original e032, guest PC 0x0c0c7e46 */
if(!s->budget--) { s->failed_pc=0x0c0c7e46u; return 0; }
r[0]=0x00000032u;
goto P_0c0c7e48;
P_0c0c7e48: /* original 65f3, guest PC 0x0c0c7e48 */
if(!s->budget--) { s->failed_pc=0x0c0c7e48u; return 0; }
r[5]=r[15];
goto P_0c0c7e4a;
P_0c0c7e4a: /* original 7504, guest PC 0x0c0c7e4a */
if(!s->budget--) { s->failed_pc=0x0c0c7e4au; return 0; }
r[5]+=0x00000004u;
goto P_0c0c7e4c;
P_0c0c7e4c: /* original 644c, guest PC 0x0c0c7e4c */
if(!s->budget--) { s->failed_pc=0x0c0c7e4cu; return 0; }
r[4]=r[4]&255u;
goto P_0c0c7e4e;
P_0c0c7e4e: /* original 66f3, guest PC 0x0c0c7e4e */
if(!s->budget--) { s->failed_pc=0x0c0c7e4eu; return 0; }
r[6]=r[15];
goto P_0c0c7e50;
P_0c0c7e50: /* original 4408, guest PC 0x0c0c7e50 */
if(!s->budget--) { s->failed_pc=0x0c0c7e50u; return 0; }
r[4]<<=2;
goto P_0c0c7e52;
P_0c0c7e52: /* original 4408, guest PC 0x0c0c7e52 */
if(!s->budget--) { s->failed_pc=0x0c0c7e52u; return 0; }
r[4]<<=2;
goto P_0c0c7e54;
P_0c0c7e54: /* original 4408, guest PC 0x0c0c7e54 */
if(!s->budget--) { s->failed_pc=0x0c0c7e54u; return 0; }
r[4]<<=2;
goto P_0c0c7e56;
P_0c0c7e56: /* original 343c, guest PC 0x0c0c7e56 */
if(!s->budget--) { s->failed_pc=0x0c0c7e56u; return 0; }
r[4]+=r[3];
goto P_0c0c7e58;
P_0c0c7e58: /* original 0b4d, guest PC 0x0c0c7e58 */
if(!s->budget--) { s->failed_pc=0x0c0c7e58u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c7e5a;
P_0c0c7e5a: /* original e028, guest PC 0x0c0c7e5a */
if(!s->budget--) { s->failed_pc=0x0c0c7e5au; return 0; }
r[0]=0x00000028u;
goto P_0c0c7e5c;
P_0c0c7e5c: /* original f446, guest PC 0x0c0c7e5c */
if(!s->budget--) { s->failed_pc=0x0c0c7e5cu; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0c7e5e;
P_0c0c7e5e: /* original e00c, guest PC 0x0c0c7e5e */
if(!s->budget--) { s->failed_pc=0x0c0c7e5eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c7e60;
P_0c0c7e60: /* original f34c, guest PC 0x0c0c7e60 */
if(!s->budget--) { s->failed_pc=0x0c0c7e60u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0c7e62;
P_0c0c7e62: /* original f4f6, guest PC 0x0c0c7e62 */
if(!s->budget--) { s->failed_pc=0x0c0c7e62u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c7e64;
P_0c0c7e64: /* original e010, guest PC 0x0c0c7e64 */
if(!s->budget--) { s->failed_pc=0x0c0c7e64u; return 0; }
r[0]=0x00000010u;
goto P_0c0c7e66;
P_0c0c7e66: /* original f5f6, guest PC 0x0c0c7e66 */
if(!s->budget--) { s->failed_pc=0x0c0c7e66u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c7e68;
P_0c0c7e68: /* original e004, guest PC 0x0c0c7e68 */
if(!s->budget--) { s->failed_pc=0x0c0c7e68u; return 0; }
r[0]=0x00000004u;
goto P_0c0c7e6a;
P_0c0c7e6a: /* original f430, guest PC 0x0c0c7e6a */
if(!s->budget--) { s->failed_pc=0x0c0c7e6au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0c7e6c;
P_0c0c7e6c: /* original ff47, guest PC 0x0c0c7e6c */
if(!s->budget--) { s->failed_pc=0x0c0c7e6cu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0c7e6e;
P_0c0c7e6e: /* original ff5a, guest PC 0x0c0c7e6e */
if(!s->budget--) { s->failed_pc=0x0c0c7e6eu; return 0; }
vf3_matrix_store(s,ram,5,r[15]);
goto P_0c0c7e70;
P_0c0c7e70: /* original d22c, guest PC 0x0c0c7e70 */
if(!s->budget--) { s->failed_pc=0x0c0c7e70u; return 0; }
r[2]=read(ram,0x0c0c7f24u,4);
goto P_0c0c7e72;
P_0c0c7e72: /* original 420b, guest PC 0x0c0c7e72 */
if(!s->budget--) { s->failed_pc=0x0c0c7e72u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7e76u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7e76u) { target=s->pc; goto dispatch; }
goto P_0c0c7e76;
P_0c0c7e74: /* original 64b3, guest PC 0x0c0c7e74 */
if(!s->budget--) { s->failed_pc=0x0c0c7e74u; return 0; }
r[4]=r[11];
goto P_0c0c7e76;
P_0c0c7e76: /* original e004, guest PC 0x0c0c7e76 */
if(!s->budget--) { s->failed_pc=0x0c0c7e76u; return 0; }
r[0]=0x00000004u;
goto P_0c0c7e78;
P_0c0c7e78: /* original fff8, guest PC 0x0c0c7e78 */
if(!s->budget--) { s->failed_pc=0x0c0c7e78u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
goto P_0c0c7e7a;
P_0c0c7e7a: /* original f4f6, guest PC 0x0c0c7e7a */
if(!s->budget--) { s->failed_pc=0x0c0c7e7au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c7e7c;
P_0c0c7e7c: /* original e010, guest PC 0x0c0c7e7c */
if(!s->budget--) { s->failed_pc=0x0c0c7e7cu; return 0; }
r[0]=0x00000010u;
goto P_0c0c7e7e;
P_0c0c7e7e: /* original 54f2, guest PC 0x0c0c7e7e */
if(!s->budget--) { s->failed_pc=0x0c0c7e7eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0c7e80;
P_0c0c7e80: /* original fe47, guest PC 0x0c0c7e80 */
if(!s->budget--) { s->failed_pc=0x0c0c7e80u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c7e82;
P_0c0c7e82: /* original e018, guest PC 0x0c0c7e82 */
if(!s->budget--) { s->failed_pc=0x0c0c7e82u; return 0; }
r[0]=0x00000018u;
goto P_0c0c7e84;
P_0c0c7e84: /* original fef7, guest PC 0x0c0c7e84 */
if(!s->budget--) { s->failed_pc=0x0c0c7e84u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c7e86;
P_0c0c7e86: /* original 34bc, guest PC 0x0c0c7e86 */
if(!s->budget--) { s->failed_pc=0x0c0c7e86u; return 0; }
r[4]+=r[11];
goto P_0c0c7e88;
P_0c0c7e88: /* original 903d, guest PC 0x0c0c7e88 */
if(!s->budget--) { s->failed_pc=0x0c0c7e88u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f06u,2);
goto P_0c0c7e8a;
P_0c0c7e8a: /* original fe47, guest PC 0x0c0c7e8a */
if(!s->budget--) { s->failed_pc=0x0c0c7e8au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c7e8c;
P_0c0c7e8c: /* original 7008, guest PC 0x0c0c7e8c */
if(!s->budget--) { s->failed_pc=0x0c0c7e8cu; return 0; }
r[0]+=0x00000008u;
goto P_0c0c7e8e;
P_0c0c7e8e: /* original fef7, guest PC 0x0c0c7e8e */
if(!s->budget--) { s->failed_pc=0x0c0c7e8eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c7e90;
P_0c0c7e90: /* original 6043, guest PC 0x0c0c7e90 */
if(!s->budget--) { s->failed_pc=0x0c0c7e90u; return 0; }
r[0]=r[4];
goto P_0c0c7e92;
P_0c0c7e92: /* original 81ef, guest PC 0x0c0c7e92 */
if(!s->budget--) { s->failed_pc=0x0c0c7e92u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0c7e94;
P_0c0c7e94: /* original d324, guest PC 0x0c0c7e94 */
if(!s->budget--) { s->failed_pc=0x0c0c7e94u; return 0; }
r[3]=read(ram,0x0c0c7f28u,4);
goto P_0c0c7e96;
P_0c0c7e96: /* original f5fc, guest PC 0x0c0c7e96 */
if(!s->budget--) { s->failed_pc=0x0c0c7e96u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c7e98;
P_0c0c7e98: /* original 430b, guest PC 0x0c0c7e98 */
if(!s->budget--) { s->failed_pc=0x0c0c7e98u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7e9cu;
fr[5]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7e9cu) { target=s->pc; goto dispatch; }
goto P_0c0c7e9c;
P_0c0c7e9a: /* original f54d, guest PC 0x0c0c7e9a */
if(!s->budget--) { s->failed_pc=0x0c0c7e9au; return 0; }
fr[5]^=0x80000000u;
goto P_0c0c7e9c;
P_0c0c7e9c: /* original e014, guest PC 0x0c0c7e9c */
if(!s->budget--) { s->failed_pc=0x0c0c7e9cu; return 0; }
r[0]=0x00000014u;
goto P_0c0c7e9e;
P_0c0c7e9e: /* original f40c, guest PC 0x0c0c7e9e */
if(!s->budget--) { s->failed_pc=0x0c0c7e9eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0c7ea0;
P_0c0c7ea0: /* original fe47, guest PC 0x0c0c7ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea0u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c7ea2;
P_0c0c7ea2: /* original e30d, guest PC 0x0c0c7ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea2u; return 0; }
r[3]=0x0000000du;
goto P_0c0c7ea4;
P_0c0c7ea4: /* original 9030, guest PC 0x0c0c7ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f08u,2);
goto P_0c0c7ea6;
P_0c0c7ea6: /* original fe47, guest PC 0x0c0c7ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c7ea8;
P_0c0c7ea8: /* original e060, guest PC 0x0c0c7ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea8u; return 0; }
r[0]=0x00000060u;
goto P_0c0c7eaa;
P_0c0c7eaa: /* original 04ec, guest PC 0x0c0c7eaa */
if(!s->budget--) { s->failed_pc=0x0c0c7eaau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c7eac;
P_0c0c7eac: /* original 644c, guest PC 0x0c0c7eac */
if(!s->budget--) { s->failed_pc=0x0c0c7eacu; return 0; }
r[4]=r[4]&255u;
goto P_0c0c7eae;
P_0c0c7eae: /* original 3433, guest PC 0x0c0c7eae */
if(!s->budget--) { s->failed_pc=0x0c0c7eaeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0c7eb0;
P_0c0c7eb0: /* original 8f01, guest PC 0x0c0c7eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb0u; return 0; }
cond=r[17]&1u;
r[0]=0x00000061u;
if(!cond) { goto P_0c0c7eb6; }
goto P_0c0c7eb4;
P_0c0c7eb2: /* original e061, guest PC 0x0c0c7eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb2u; return 0; }
r[0]=0x00000061u;
goto P_0c0c7eb4;
P_0c0c7eb4: /* original 74f3, guest PC 0x0c0c7eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb4u; return 0; }
r[4]+=0xfffffff3u;
goto P_0c0c7eb6;
P_0c0c7eb6: /* original 634b, guest PC 0x0c0c7eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb6u; return 0; }
r[3]=0u-r[4];
goto P_0c0c7eb8;
P_0c0c7eb8: /* original 0e44, guest PC 0x0c0c7eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb8u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c7eba;
P_0c0c7eba: /* original d41c, guest PC 0x0c0c7eba */
if(!s->budget--) { s->failed_pc=0x0c0c7ebau; return 0; }
r[4]=read(ram,0x0c0c7f2cu,4);
goto P_0c0c7ebc;
P_0c0c7ebc: /* original 9025, guest PC 0x0c0c7ebc */
if(!s->budget--) { s->failed_pc=0x0c0c7ebcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f0au,2);
goto P_0c0c7ebe;
P_0c0c7ebe: /* original 443d, guest PC 0x0c0c7ebe */
if(!s->budget--) { s->failed_pc=0x0c0c7ebeu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c0c7ec0;
P_0c0c7ec0: /* original 0e46, guest PC 0x0c0c7ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec0u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7ec2;
P_0c0c7ec2: /* original e400, guest PC 0x0c0c7ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec2u; return 0; }
r[4]=0x00000000u;
goto P_0c0c7ec4;
P_0c0c7ec4: /* original e022, guest PC 0x0c0c7ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec4u; return 0; }
r[0]=0x00000022u;
goto P_0c0c7ec6;
P_0c0c7ec6: /* original d31a, guest PC 0x0c0c7ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec6u; return 0; }
r[3]=read(ram,0x0c0c7f30u,4);
goto P_0c0c7ec8;
P_0c0c7ec8: /* original 1e33, guest PC 0x0c0c7ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec8u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c0c7eca;
P_0c0c7eca: /* original 0e44, guest PC 0x0c0c7eca */
if(!s->budget--) { s->failed_pc=0x0c0c7ecau; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c7ecc;
P_0c0c7ecc: /* original 901e, guest PC 0x0c0c7ecc */
if(!s->budget--) { s->failed_pc=0x0c0c7eccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f0cu,2);
goto P_0c0c7ece;
P_0c0c7ece: /* original 0e46, guest PC 0x0c0c7ece */
if(!s->budget--) { s->failed_pc=0x0c0c7eceu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7ed0;
P_0c0c7ed0: /* original 700c, guest PC 0x0c0c7ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed0u; return 0; }
r[0]+=0x0000000cu;
goto P_0c0c7ed2;
P_0c0c7ed2: /* original 0e46, guest PC 0x0c0c7ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed2u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7ed4;
P_0c0c7ed4: /* original 901b, guest PC 0x0c0c7ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f0eu,2);
goto P_0c0c7ed6;
P_0c0c7ed6: /* original 0e46, guest PC 0x0c0c7ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed6u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7ed8;
P_0c0c7ed8: /* original 700c, guest PC 0x0c0c7ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed8u; return 0; }
r[0]+=0x0000000cu;
goto P_0c0c7eda;
P_0c0c7eda: /* original 0e46, guest PC 0x0c0c7eda */
if(!s->budget--) { s->failed_pc=0x0c0c7edau; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7edc;
P_0c0c7edc: /* original 9018, guest PC 0x0c0c7edc */
if(!s->budget--) { s->failed_pc=0x0c0c7edcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f10u,2);
goto P_0c0c7ede;
P_0c0c7ede: /* original 0e44, guest PC 0x0c0c7ede */
if(!s->budget--) { s->failed_pc=0x0c0c7edeu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c7ee0;
P_0c0c7ee0: /* original e401, guest PC 0x0c0c7ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee0u; return 0; }
r[4]=0x00000001u;
goto P_0c0c7ee2;
P_0c0c7ee2: /* original 60e2, guest PC 0x0c0c7ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee2u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0c7ee4;
P_0c0c7ee4: /* original d313, guest PC 0x0c0c7ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee4u; return 0; }
r[3]=read(ram,0x0c0c7f34u,4);
goto P_0c0c7ee6;
P_0c0c7ee6: /* original 2039, guest PC 0x0c0c7ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee6u; return 0; }
r[0]&=r[3];
goto P_0c0c7ee8;
P_0c0c7ee8: /* original 240b, guest PC 0x0c0c7ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee8u; return 0; }
r[4]|=r[0];
goto P_0c0c7eea;
P_0c0c7eea: /* original 2e42, guest PC 0x0c0c7eea */
if(!s->budget--) { s->failed_pc=0x0c0c7eeau; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0c7eec;
P_0c0c7eec: /* original d212, guest PC 0x0c0c7eec */
if(!s->budget--) { s->failed_pc=0x0c0c7eecu; return 0; }
r[2]=read(ram,0x0c0c7f38u,4);
goto P_0c0c7eee;
P_0c0c7eee: /* original 420b, guest PC 0x0c0c7eee */
if(!s->budget--) { s->failed_pc=0x0c0c7eeeu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7ef2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7ef2u) { target=s->pc; goto dispatch; }
goto P_0c0c7ef2;
P_0c0c7ef0: /* original 64e3, guest PC 0x0c0c7ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef0u; return 0; }
r[4]=r[14];
goto P_0c0c7ef2;
P_0c0c7ef2: /* original 62c2, guest PC 0x0c0c7ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef2u; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c0c7ef4;
P_0c0c7ef4: /* original d311, guest PC 0x0c0c7ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef4u; return 0; }
r[3]=read(ram,0x0c0c7f3cu,4);
goto P_0c0c7ef6;
P_0c0c7ef6: /* original 2238, guest PC 0x0c0c7ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c7ef8;
P_0c0c7ef8: /* original 8924, guest PC 0x0c0c7ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7f44; }
goto P_0c0c7efa;
P_0c0c7efa: /* original d211, guest PC 0x0c0c7efa */
if(!s->budget--) { s->failed_pc=0x0c0c7efau; return 0; }
r[2]=read(ram,0x0c0c7f40u,4);
goto P_0c0c7efc;
P_0c0c7efc: /* original 420b, guest PC 0x0c0c7efc */
if(!s->budget--) { s->failed_pc=0x0c0c7efcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7f00u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f00u) { target=s->pc; goto dispatch; }
goto P_0c0c7f00;
P_0c0c7efe: /* original 64e3, guest PC 0x0c0c7efe */
if(!s->budget--) { s->failed_pc=0x0c0c7efeu; return 0; }
r[4]=r[14];
goto P_0c0c7f00;
P_0c0c7f00: /* original a02a, guest PC 0x0c0c7f00 */
if(!s->budget--) { s->failed_pc=0x0c0c7f00u; return 0; }
goto P_0c0c7f58;
P_0c0c7f02: /* original 0009, guest PC 0x0c0c7f02 */
if(!s->budget--) { s->failed_pc=0x0c0c7f02u; return 0; }
if(!vf3_matrix_family(0x0c0c7f04u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7f04u; return 0; } return 1;
P_0c0c7f44: /* original e060, guest PC 0x0c0c7f44 */
if(!s->budget--) { s->failed_pc=0x0c0c7f44u; return 0; }
r[0]=0x00000060u;
goto P_0c0c7f46;
P_0c0c7f46: /* original d247, guest PC 0x0c0c7f46 */
if(!s->budget--) { s->failed_pc=0x0c0c7f46u; return 0; }
r[2]=read(ram,0x0c0c8064u,4);
goto P_0c0c7f48;
P_0c0c7f48: /* original 05ec, guest PC 0x0c0c7f48 */
if(!s->budget--) { s->failed_pc=0x0c0c7f48u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c7f4a;
P_0c0c7f4a: /* original 84e4, guest PC 0x0c0c7f4a */
if(!s->budget--) { s->failed_pc=0x0c0c7f4au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c7f4c;
P_0c0c7f4c: /* original 655c, guest PC 0x0c0c7f4c */
if(!s->budget--) { s->failed_pc=0x0c0c7f4cu; return 0; }
r[5]=r[5]&255u;
goto P_0c0c7f4e;
P_0c0c7f4e: /* original 420b, guest PC 0x0c0c7f4e */
if(!s->budget--) { s->failed_pc=0x0c0c7f4eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7f52u;
r[4]=r[0]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f52u) { target=s->pc; goto dispatch; }
goto P_0c0c7f52;
P_0c0c7f50: /* original 640c, guest PC 0x0c0c7f50 */
if(!s->budget--) { s->failed_pc=0x0c0c7f50u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c7f52;
P_0c0c7f52: /* original d345, guest PC 0x0c0c7f52 */
if(!s->budget--) { s->failed_pc=0x0c0c7f52u; return 0; }
r[3]=read(ram,0x0c0c8068u,4);
goto P_0c0c7f54;
P_0c0c7f54: /* original 430b, guest PC 0x0c0c7f54 */
if(!s->budget--) { s->failed_pc=0x0c0c7f54u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7f58u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f58u) { target=s->pc; goto dispatch; }
goto P_0c0c7f58;
P_0c0c7f56: /* original 64e3, guest PC 0x0c0c7f56 */
if(!s->budget--) { s->failed_pc=0x0c0c7f56u; return 0; }
r[4]=r[14];
goto P_0c0c7f58;
P_0c0c7f58: /* original e060, guest PC 0x0c0c7f58 */
if(!s->budget--) { s->failed_pc=0x0c0c7f58u; return 0; }
r[0]=0x00000060u;
goto P_0c0c7f5a;
P_0c0c7f5a: /* original 02ec, guest PC 0x0c0c7f5a */
if(!s->budget--) { s->failed_pc=0x0c0c7f5au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c7f5c;
P_0c0c7f5c: /* original 907e, guest PC 0x0c0c7f5c */
if(!s->budget--) { s->failed_pc=0x0c0c7f5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c805cu,2);
goto P_0c0c7f5e;
P_0c0c7f5e: /* original 0e24, guest PC 0x0c0c7f5e */
if(!s->budget--) { s->failed_pc=0x0c0c7f5eu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0c7f60;
P_0c0c7f60: /* original d342, guest PC 0x0c0c7f60 */
if(!s->budget--) { s->failed_pc=0x0c0c7f60u; return 0; }
r[3]=read(ram,0x0c0c806cu,4);
goto P_0c0c7f62;
P_0c0c7f62: /* original 61c2, guest PC 0x0c0c7f62 */
if(!s->budget--) { s->failed_pc=0x0c0c7f62u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c0c7f64;
P_0c0c7f64: /* original 2138, guest PC 0x0c0c7f64 */
if(!s->budget--) { s->failed_pc=0x0c0c7f64u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0c7f66;
P_0c0c7f66: /* original 8904, guest PC 0x0c0c7f66 */
if(!s->budget--) { s->failed_pc=0x0c0c7f66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7f72; }
goto P_0c0c7f68;
P_0c0c7f68: /* original d241, guest PC 0x0c0c7f68 */
if(!s->budget--) { s->failed_pc=0x0c0c7f68u; return 0; }
r[2]=read(ram,0x0c0c8070u,4);
goto P_0c0c7f6a;
P_0c0c7f6a: /* original 420b, guest PC 0x0c0c7f6a */
if(!s->budget--) { s->failed_pc=0x0c0c7f6au; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7f6eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f6eu) { target=s->pc; goto dispatch; }
goto P_0c0c7f6e;
P_0c0c7f6c: /* original 0009, guest PC 0x0c0c7f6c */
if(!s->budget--) { s->failed_pc=0x0c0c7f6cu; return 0; }
goto P_0c0c7f6e;
P_0c0c7f6e: /* original a006, guest PC 0x0c0c7f6e */
if(!s->budget--) { s->failed_pc=0x0c0c7f6eu; return 0; }
goto P_0c0c7f7e;
P_0c0c7f70: /* original 0009, guest PC 0x0c0c7f70 */
if(!s->budget--) { s->failed_pc=0x0c0c7f70u; return 0; }
goto P_0c0c7f72;
P_0c0c7f72: /* original 60d3, guest PC 0x0c0c7f72 */
if(!s->budget--) { s->failed_pc=0x0c0c7f72u; return 0; }
r[0]=r[13];
goto P_0c0c7f74;
P_0c0c7f74: /* original 8801, guest PC 0x0c0c7f74 */
if(!s->budget--) { s->failed_pc=0x0c0c7f74u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c7f76;
P_0c0c7f76: /* original 8b02, guest PC 0x0c0c7f76 */
if(!s->budget--) { s->failed_pc=0x0c0c7f76u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7f7e; }
goto P_0c0c7f78;
P_0c0c7f78: /* original d13e, guest PC 0x0c0c7f78 */
if(!s->budget--) { s->failed_pc=0x0c0c7f78u; return 0; }
r[1]=read(ram,0x0c0c8074u,4);
goto P_0c0c7f7a;
P_0c0c7f7a: /* original 410b, guest PC 0x0c0c7f7a */
if(!s->budget--) { s->failed_pc=0x0c0c7f7au; return 0; }
target=r[1];
r[16]=code_base|0x0c0c7f7eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f7eu) { target=s->pc; goto dispatch; }
goto P_0c0c7f7e;
P_0c0c7f7c: /* original 0009, guest PC 0x0c0c7f7c */
if(!s->budget--) { s->failed_pc=0x0c0c7f7cu; return 0; }
goto P_0c0c7f7e;
P_0c0c7f7e: /* original d33e, guest PC 0x0c0c7f7e */
if(!s->budget--) { s->failed_pc=0x0c0c7f7eu; return 0; }
r[3]=read(ram,0x0c0c8078u,4);
goto P_0c0c7f80;
P_0c0c7f80: /* original 430b, guest PC 0x0c0c7f80 */
if(!s->budget--) { s->failed_pc=0x0c0c7f80u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7f84u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f84u) { target=s->pc; goto dispatch; }
goto P_0c0c7f84;
P_0c0c7f82: /* original 64e3, guest PC 0x0c0c7f82 */
if(!s->budget--) { s->failed_pc=0x0c0c7f82u; return 0; }
r[4]=r[14];
goto P_0c0c7f84;
P_0c0c7f84: /* original d23d, guest PC 0x0c0c7f84 */
if(!s->budget--) { s->failed_pc=0x0c0c7f84u; return 0; }
r[2]=read(ram,0x0c0c807cu,4);
goto P_0c0c7f86;
P_0c0c7f86: /* original 420b, guest PC 0x0c0c7f86 */
if(!s->budget--) { s->failed_pc=0x0c0c7f86u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7f8au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f8au) { target=s->pc; goto dispatch; }
goto P_0c0c7f8a;
P_0c0c7f88: /* original 0009, guest PC 0x0c0c7f88 */
if(!s->budget--) { s->failed_pc=0x0c0c7f88u; return 0; }
goto P_0c0c7f8a;
P_0c0c7f8a: /* original 2dd8, guest PC 0x0c0c7f8a */
if(!s->budget--) { s->failed_pc=0x0c0c7f8au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0c7f8c;
P_0c0c7f8c: /* original 8b06, guest PC 0x0c0c7f8c */
if(!s->budget--) { s->failed_pc=0x0c0c7f8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7f9c; }
goto P_0c0c7f8e;
P_0c0c7f8e: /* original d33e, guest PC 0x0c0c7f8e */
if(!s->budget--) { s->failed_pc=0x0c0c7f8eu; return 0; }
r[3]=read(ram,0x0c0c8088u,4);
goto P_0c0c7f90;
P_0c0c7f90: /* original d23c, guest PC 0x0c0c7f90 */
if(!s->budget--) { s->failed_pc=0x0c0c7f90u; return 0; }
r[2]=read(ram,0x0c0c8084u,4);
goto P_0c0c7f92;
P_0c0c7f92: /* original d53b, guest PC 0x0c0c7f92 */
if(!s->budget--) { s->failed_pc=0x0c0c7f92u; return 0; }
r[5]=read(ram,0x0c0c8080u,4);
goto P_0c0c7f94;
P_0c0c7f94: /* original 430b, guest PC 0x0c0c7f94 */
if(!s->budget--) { s->failed_pc=0x0c0c7f94u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7f98u;
tmp=read(ram,r[2],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f98u) { target=s->pc; goto dispatch; }
goto P_0c0c7f98;
P_0c0c7f96: /* original 6422, guest PC 0x0c0c7f96 */
if(!s->budget--) { s->failed_pc=0x0c0c7f96u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0c7f98;
P_0c0c7f98: /* original a005, guest PC 0x0c0c7f98 */
if(!s->budget--) { s->failed_pc=0x0c0c7f98u; return 0; }
goto P_0c0c7fa6;
P_0c0c7f9a: /* original 0009, guest PC 0x0c0c7f9a */
if(!s->budget--) { s->failed_pc=0x0c0c7f9au; return 0; }
goto P_0c0c7f9c;
P_0c0c7f9c: /* original d23a, guest PC 0x0c0c7f9c */
if(!s->budget--) { s->failed_pc=0x0c0c7f9cu; return 0; }
r[2]=read(ram,0x0c0c8088u,4);
goto P_0c0c7f9e;
P_0c0c7f9e: /* original d33b, guest PC 0x0c0c7f9e */
if(!s->budget--) { s->failed_pc=0x0c0c7f9eu; return 0; }
r[3]=read(ram,0x0c0c808cu,4);
goto P_0c0c7fa0;
P_0c0c7fa0: /* original d537, guest PC 0x0c0c7fa0 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa0u; return 0; }
r[5]=read(ram,0x0c0c8080u,4);
goto P_0c0c7fa2;
P_0c0c7fa2: /* original 420b, guest PC 0x0c0c7fa2 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7fa6u;
tmp=read(ram,r[3],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7fa6u) { target=s->pc; goto dispatch; }
goto P_0c0c7fa6;
P_0c0c7fa4: /* original 6432, guest PC 0x0c0c7fa4 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa4u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0c7fa6;
P_0c0c7fa6: /* original 7f14, guest PC 0x0c0c7fa6 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa6u; return 0; }
r[15]+=0x00000014u;
goto P_0c0c7fa8;
P_0c0c7fa8: /* original 4f26, guest PC 0x0c0c7fa8 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7faa;
P_0c0c7faa: /* original fff9, guest PC 0x0c0c7faa */
if(!s->budget--) { s->failed_pc=0x0c0c7faau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c7fac;
P_0c0c7fac: /* original 6bf6, guest PC 0x0c0c7fac */
if(!s->budget--) { s->failed_pc=0x0c0c7facu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7fae;
P_0c0c7fae: /* original 6cf6, guest PC 0x0c0c7fae */
if(!s->budget--) { s->failed_pc=0x0c0c7faeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7fb0;
P_0c0c7fb0: /* original 6df6, guest PC 0x0c0c7fb0 */
if(!s->budget--) { s->failed_pc=0x0c0c7fb0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c7fb2;
P_0c0c7fb2: /* original 000b, guest PC 0x0c0c7fb2 */
if(!s->budget--) { s->failed_pc=0x0c0c7fb2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c7fb4: /* original 6ef6, guest PC 0x0c0c7fb4 */
if(!s->budget--) { s->failed_pc=0x0c0c7fb4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c7fb6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7fb6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
