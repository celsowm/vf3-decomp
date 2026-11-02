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
int vf3_away_batch55_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c087542u: goto P_0c087542;
case 0x0c087544u: goto P_0c087544;
case 0x0c087546u: goto P_0c087546;
case 0x0c087548u: goto P_0c087548;
case 0x0c08754au: goto P_0c08754a;
case 0x0c08754cu: goto P_0c08754c;
case 0x0c08754eu: goto P_0c08754e;
case 0x0c087550u: goto P_0c087550;
case 0x0c087552u: goto P_0c087552;
case 0x0c087554u: goto P_0c087554;
case 0x0c087556u: goto P_0c087556;
case 0x0c087558u: goto P_0c087558;
case 0x0c08755au: goto P_0c08755a;
case 0x0c08755cu: goto P_0c08755c;
case 0x0c08755eu: goto P_0c08755e;
case 0x0c087560u: goto P_0c087560;
case 0x0c087562u: goto P_0c087562;
case 0x0c087564u: goto P_0c087564;
case 0x0c087566u: goto P_0c087566;
case 0x0c087568u: goto P_0c087568;
case 0x0c08756au: goto P_0c08756a;
case 0x0c08756cu: goto P_0c08756c;
case 0x0c08756eu: goto P_0c08756e;
case 0x0c087570u: goto P_0c087570;
case 0x0c087572u: goto P_0c087572;
case 0x0c087574u: goto P_0c087574;
case 0x0c087576u: goto P_0c087576;
case 0x0c087578u: goto P_0c087578;
case 0x0c08757au: goto P_0c08757a;
case 0x0c08757cu: goto P_0c08757c;
case 0x0c08757eu: goto P_0c08757e;
case 0x0c087580u: goto P_0c087580;
case 0x0c087582u: goto P_0c087582;
case 0x0c087584u: goto P_0c087584;
case 0x0c087586u: goto P_0c087586;
case 0x0c087588u: goto P_0c087588;
case 0x0c08758au: goto P_0c08758a;
case 0x0c08758cu: goto P_0c08758c;
case 0x0c08758eu: goto P_0c08758e;
case 0x0c087590u: goto P_0c087590;
case 0x0c087592u: goto P_0c087592;
case 0x0c087594u: goto P_0c087594;
case 0x0c087596u: goto P_0c087596;
case 0x0c087598u: goto P_0c087598;
case 0x0c08759au: goto P_0c08759a;
case 0x0c08759cu: goto P_0c08759c;
case 0x0c08759eu: goto P_0c08759e;
case 0x0c0875a0u: goto P_0c0875a0;
case 0x0c0875a2u: goto P_0c0875a2;
case 0x0c0875a4u: goto P_0c0875a4;
case 0x0c0875a6u: goto P_0c0875a6;
case 0x0c0875a8u: goto P_0c0875a8;
case 0x0c0875aau: goto P_0c0875aa;
case 0x0c0875acu: goto P_0c0875ac;
case 0x0c0875aeu: goto P_0c0875ae;
case 0x0c0875b0u: goto P_0c0875b0;
case 0x0c0875b2u: goto P_0c0875b2;
case 0x0c0875b4u: goto P_0c0875b4;
case 0x0c0875b6u: goto P_0c0875b6;
case 0x0c0875b8u: goto P_0c0875b8;
case 0x0c0875bau: goto P_0c0875ba;
case 0x0c0875bcu: goto P_0c0875bc;
case 0x0c0875beu: goto P_0c0875be;
case 0x0c0875c0u: goto P_0c0875c0;
case 0x0c0875c2u: goto P_0c0875c2;
case 0x0c0875c4u: goto P_0c0875c4;
case 0x0c0875c6u: goto P_0c0875c6;
case 0x0c0875c8u: goto P_0c0875c8;
case 0x0c0875cau: goto P_0c0875ca;
case 0x0c0875ccu: goto P_0c0875cc;
case 0x0c0875ceu: goto P_0c0875ce;
case 0x0c0875d0u: goto P_0c0875d0;
case 0x0c0875d2u: goto P_0c0875d2;
case 0x0c0875d4u: goto P_0c0875d4;
case 0x0c0875d6u: goto P_0c0875d6;
case 0x0c0875d8u: goto P_0c0875d8;
case 0x0c0875dau: goto P_0c0875da;
case 0x0c0875dcu: goto P_0c0875dc;
case 0x0c0875deu: goto P_0c0875de;
case 0x0c0875e0u: goto P_0c0875e0;
case 0x0c0875e2u: goto P_0c0875e2;
case 0x0c0875e4u: goto P_0c0875e4;
case 0x0c0875e6u: goto P_0c0875e6;
case 0x0c0875e8u: goto P_0c0875e8;
case 0x0c0875eau: goto P_0c0875ea;
case 0x0c0875ecu: goto P_0c0875ec;
case 0x0c0875eeu: goto P_0c0875ee;
case 0x0c088c34u: goto P_0c088c34;
case 0x0c088c36u: goto P_0c088c36;
case 0x0c088c38u: goto P_0c088c38;
case 0x0c088c3au: goto P_0c088c3a;
case 0x0c088c3cu: goto P_0c088c3c;
case 0x0c088c3eu: goto P_0c088c3e;
case 0x0c088c40u: goto P_0c088c40;
case 0x0c088c42u: goto P_0c088c42;
case 0x0c088c44u: goto P_0c088c44;
case 0x0c088c46u: goto P_0c088c46;
case 0x0c088c48u: goto P_0c088c48;
case 0x0c088c4au: goto P_0c088c4a;
case 0x0c088c4cu: goto P_0c088c4c;
case 0x0c088c4eu: goto P_0c088c4e;
case 0x0c088c50u: goto P_0c088c50;
case 0x0c088c52u: goto P_0c088c52;
case 0x0c088c54u: goto P_0c088c54;
case 0x0c088c56u: goto P_0c088c56;
case 0x0c088c58u: goto P_0c088c58;
case 0x0c088c5au: goto P_0c088c5a;
case 0x0c088c5cu: goto P_0c088c5c;
case 0x0c088c5eu: goto P_0c088c5e;
case 0x0c088c60u: goto P_0c088c60;
case 0x0c088c62u: goto P_0c088c62;
case 0x0c088c64u: goto P_0c088c64;
case 0x0c088c66u: goto P_0c088c66;
case 0x0c088c68u: goto P_0c088c68;
case 0x0c088c6au: goto P_0c088c6a;
case 0x0c088c6cu: goto P_0c088c6c;
case 0x0c088c6eu: goto P_0c088c6e;
case 0x0c088c70u: goto P_0c088c70;
case 0x0c088c72u: goto P_0c088c72;
case 0x0c088c74u: goto P_0c088c74;
case 0x0c088c76u: goto P_0c088c76;
case 0x0c088c78u: goto P_0c088c78;
case 0x0c088c7au: goto P_0c088c7a;
case 0x0c088c7cu: goto P_0c088c7c;
case 0x0c088c7eu: goto P_0c088c7e;
case 0x0c088c80u: goto P_0c088c80;
case 0x0c088c82u: goto P_0c088c82;
case 0x0c088c84u: goto P_0c088c84;
case 0x0c088c86u: goto P_0c088c86;
case 0x0c088c88u: goto P_0c088c88;
case 0x0c088c8au: goto P_0c088c8a;
case 0x0c088c8cu: goto P_0c088c8c;
case 0x0c088c8eu: goto P_0c088c8e;
case 0x0c088c90u: goto P_0c088c90;
case 0x0c088c92u: goto P_0c088c92;
case 0x0c088c94u: goto P_0c088c94;
case 0x0c088c96u: goto P_0c088c96;
case 0x0c088c98u: goto P_0c088c98;
case 0x0c088c9au: goto P_0c088c9a;
case 0x0c088c9cu: goto P_0c088c9c;
case 0x0c088c9eu: goto P_0c088c9e;
case 0x0c088ca0u: goto P_0c088ca0;
case 0x0c088ca2u: goto P_0c088ca2;
case 0x0c088ca4u: goto P_0c088ca4;
case 0x0c088ca6u: goto P_0c088ca6;
case 0x0c088ca8u: goto P_0c088ca8;
case 0x0c088caau: goto P_0c088caa;
case 0x0c088cacu: goto P_0c088cac;
case 0x0c088caeu: goto P_0c088cae;
case 0x0c088cb0u: goto P_0c088cb0;
case 0x0c088cb2u: goto P_0c088cb2;
case 0x0c088cb4u: goto P_0c088cb4;
case 0x0c088cb6u: goto P_0c088cb6;
case 0x0c088cb8u: goto P_0c088cb8;
case 0x0c088cbau: goto P_0c088cba;
case 0x0c088cbcu: goto P_0c088cbc;
case 0x0c088cbeu: goto P_0c088cbe;
case 0x0c088cc0u: goto P_0c088cc0;
case 0x0c088cc2u: goto P_0c088cc2;
case 0x0c088cc4u: goto P_0c088cc4;
case 0x0c088cc6u: goto P_0c088cc6;
case 0x0c088cc8u: goto P_0c088cc8;
case 0x0c088ccau: goto P_0c088cca;
case 0x0c088cccu: goto P_0c088ccc;
case 0x0c088cceu: goto P_0c088cce;
case 0x0c088cd0u: goto P_0c088cd0;
case 0x0c088cd2u: goto P_0c088cd2;
case 0x0c088cd4u: goto P_0c088cd4;
case 0x0c088cd6u: goto P_0c088cd6;
case 0x0c088cd8u: goto P_0c088cd8;
case 0x0c088cdau: goto P_0c088cda;
case 0x0c088cdcu: goto P_0c088cdc;
case 0x0c088cdeu: goto P_0c088cde;
case 0x0c088ce0u: goto P_0c088ce0;
case 0x0c088ce2u: goto P_0c088ce2;
case 0x0c088ce4u: goto P_0c088ce4;
case 0x0c088ce6u: goto P_0c088ce6;
case 0x0c088ce8u: goto P_0c088ce8;
case 0x0c088ceau: goto P_0c088cea;
case 0x0c088cecu: goto P_0c088cec;
case 0x0c088ceeu: goto P_0c088cee;
case 0x0c088cf0u: goto P_0c088cf0;
case 0x0c088cf2u: goto P_0c088cf2;
case 0x0c088cf4u: goto P_0c088cf4;
case 0x0c088cf6u: goto P_0c088cf6;
case 0x0c088cf8u: goto P_0c088cf8;
case 0x0c088cfau: goto P_0c088cfa;
case 0x0c088cfcu: goto P_0c088cfc;
case 0x0c088cfeu: goto P_0c088cfe;
case 0x0c088d00u: goto P_0c088d00;
case 0x0c088d02u: goto P_0c088d02;
case 0x0c088d04u: goto P_0c088d04;
case 0x0c088d06u: goto P_0c088d06;
case 0x0c088d08u: goto P_0c088d08;
case 0x0c088d0au: goto P_0c088d0a;
case 0x0c088d0cu: goto P_0c088d0c;
case 0x0c088d0eu: goto P_0c088d0e;
case 0x0c088d10u: goto P_0c088d10;
case 0x0c088d12u: goto P_0c088d12;
case 0x0c088d14u: goto P_0c088d14;
case 0x0c088d16u: goto P_0c088d16;
case 0x0c088d18u: goto P_0c088d18;
case 0x0c088d1au: goto P_0c088d1a;
case 0x0c088d1cu: goto P_0c088d1c;
case 0x0c088d1eu: goto P_0c088d1e;
case 0x0c088d20u: goto P_0c088d20;
case 0x0c088d22u: goto P_0c088d22;
case 0x0c088d24u: goto P_0c088d24;
case 0x0c088d26u: goto P_0c088d26;
case 0x0c088d28u: goto P_0c088d28;
case 0x0c088d2au: goto P_0c088d2a;
case 0x0c088d2cu: goto P_0c088d2c;
case 0x0c088d2eu: goto P_0c088d2e;
case 0x0c088d30u: goto P_0c088d30;
case 0x0c088d32u: goto P_0c088d32;
case 0x0c088d34u: goto P_0c088d34;
case 0x0c088d36u: goto P_0c088d36;
case 0x0c088d38u: goto P_0c088d38;
case 0x0c088d3au: goto P_0c088d3a;
case 0x0c088d3cu: goto P_0c088d3c;
case 0x0c088d3eu: goto P_0c088d3e;
case 0x0c088d40u: goto P_0c088d40;
case 0x0c088d42u: goto P_0c088d42;
case 0x0c088d44u: goto P_0c088d44;
case 0x0c088d46u: goto P_0c088d46;
case 0x0c088d48u: goto P_0c088d48;
case 0x0c088d4au: goto P_0c088d4a;
case 0x0c088d4cu: goto P_0c088d4c;
case 0x0c088d4eu: goto P_0c088d4e;
case 0x0c088d50u: goto P_0c088d50;
case 0x0c088d52u: goto P_0c088d52;
case 0x0c088d54u: goto P_0c088d54;
case 0x0c088d56u: goto P_0c088d56;
case 0x0c088d58u: goto P_0c088d58;
case 0x0c088d5au: goto P_0c088d5a;
case 0x0c088d5cu: goto P_0c088d5c;
case 0x0c088d5eu: goto P_0c088d5e;
case 0x0c088d60u: goto P_0c088d60;
case 0x0c088d62u: goto P_0c088d62;
case 0x0c088d64u: goto P_0c088d64;
case 0x0c088d66u: goto P_0c088d66;
case 0x0c088d68u: goto P_0c088d68;
case 0x0c088d6au: goto P_0c088d6a;
case 0x0c088d6cu: goto P_0c088d6c;
case 0x0c088d6eu: goto P_0c088d6e;
case 0x0c088d70u: goto P_0c088d70;
case 0x0c088d72u: goto P_0c088d72;
case 0x0c088d74u: goto P_0c088d74;
case 0x0c088d76u: goto P_0c088d76;
case 0x0c088d78u: goto P_0c088d78;
case 0x0c088d7au: goto P_0c088d7a;
case 0x0c088d7cu: goto P_0c088d7c;
case 0x0c088d7eu: goto P_0c088d7e;
case 0x0c088d80u: goto P_0c088d80;
case 0x0c088d82u: goto P_0c088d82;
case 0x0c088d84u: goto P_0c088d84;
case 0x0c088d86u: goto P_0c088d86;
case 0x0c088d88u: goto P_0c088d88;
case 0x0c088d8au: goto P_0c088d8a;
case 0x0c088d8cu: goto P_0c088d8c;
case 0x0c088d8eu: goto P_0c088d8e;
case 0x0c088d90u: goto P_0c088d90;
case 0x0c088d92u: goto P_0c088d92;
case 0x0c088d94u: goto P_0c088d94;
case 0x0c088d96u: goto P_0c088d96;
default: return vf3_matrix_family(target,s,ram);
}
P_0c087542: /* original 5041, guest PC 0x0c087542 */
if(!s->budget--) { s->failed_pc=0x0c087542u; return 0; }
r[0]=read(ram,r[4]+4,4);
goto P_0c087544;
P_0c087544: /* original 88ff, guest PC 0x0c087544 */
if(!s->budget--) { s->failed_pc=0x0c087544u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c087546;
P_0c087546: /* original 8d0a, guest PC 0x0c087546 */
if(!s->budget--) { s->failed_pc=0x0c087546u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c08755e; }
goto P_0c08754a;
P_0c087548: /* original 6503, guest PC 0x0c087548 */
if(!s->budget--) { s->failed_pc=0x0c087548u; return 0; }
r[5]=r[0];
goto P_0c08754a;
P_0c08754a: /* original 6252, guest PC 0x0c08754a */
if(!s->budget--) { s->failed_pc=0x0c08754au; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c08754c;
P_0c08754c: /* original 1421, guest PC 0x0c08754c */
if(!s->budget--) { s->failed_pc=0x0c08754cu; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c08754e;
P_0c08754e: /* original 6642, guest PC 0x0c08754e */
if(!s->budget--) { s->failed_pc=0x0c08754eu; return 0; }
tmp=read(ram,r[4],4);
r[6]=tmp;
goto P_0c087550;
P_0c087550: /* original 6063, guest PC 0x0c087550 */
if(!s->budget--) { s->failed_pc=0x0c087550u; return 0; }
r[0]=r[6];
goto P_0c087552;
P_0c087552: /* original 88ff, guest PC 0x0c087552 */
if(!s->budget--) { s->failed_pc=0x0c087552u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c087554;
P_0c087554: /* original 2562, guest PC 0x0c087554 */
if(!s->budget--) { s->failed_pc=0x0c087554u; return 0; }
write(ram,r[5],r[6],4);
goto P_0c087556;
P_0c087556: /* original 2452, guest PC 0x0c087556 */
if(!s->budget--) { s->failed_pc=0x0c087556u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c087558;
P_0c087558: /* original 8d01, guest PC 0x0c087558 */
if(!s->budget--) { s->failed_pc=0x0c087558u; return 0; }
cond=r[17]&1u;
write(ram,r[5]+4,r[4],4);
if(cond) { goto P_0c08755e; }
goto P_0c08755c;
P_0c08755a: /* original 1541, guest PC 0x0c08755a */
if(!s->budget--) { s->failed_pc=0x0c08755au; return 0; }
write(ram,r[5]+4,r[4],4);
goto P_0c08755c;
P_0c08755c: /* original 1651, guest PC 0x0c08755c */
if(!s->budget--) { s->failed_pc=0x0c08755cu; return 0; }
write(ram,r[6]+4,r[5],4);
goto P_0c08755e;
P_0c08755e: /* original 000b, guest PC 0x0c08755e */
if(!s->budget--) { s->failed_pc=0x0c08755eu; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c087560: /* original 6053, guest PC 0x0c087560 */
if(!s->budget--) { s->failed_pc=0x0c087560u; return 0; }
r[0]=r[5];
goto P_0c087562;
P_0c087562: /* original 8448, guest PC 0x0c087562 */
if(!s->budget--) { s->failed_pc=0x0c087562u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c087564;
P_0c087564: /* original 6603, guest PC 0x0c087564 */
if(!s->budget--) { s->failed_pc=0x0c087564u; return 0; }
r[6]=r[0];
goto P_0c087566;
P_0c087566: /* original 606e, guest PC 0x0c087566 */
if(!s->budget--) { s->failed_pc=0x0c087566u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[6];
goto P_0c087568;
P_0c087568: /* original 88ff, guest PC 0x0c087568 */
if(!s->budget--) { s->failed_pc=0x0c087568u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c08756a;
P_0c08756a: /* original 891f, guest PC 0x0c08756a */
if(!s->budget--) { s->failed_pc=0x0c08756au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0875ac; }
goto P_0c08756c;
P_0c08756c: /* original 76ff, guest PC 0x0c08756c */
if(!s->budget--) { s->failed_pc=0x0c08756cu; return 0; }
r[6]+=0xffffffffu;
goto P_0c08756e;
P_0c08756e: /* original 6063, guest PC 0x0c08756e */
if(!s->budget--) { s->failed_pc=0x0c08756eu; return 0; }
r[0]=r[6];
goto P_0c087570;
P_0c087570: /* original 666e, guest PC 0x0c087570 */
if(!s->budget--) { s->failed_pc=0x0c087570u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[6];
goto P_0c087572;
P_0c087572: /* original 2668, guest PC 0x0c087572 */
if(!s->budget--) { s->failed_pc=0x0c087572u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c087574;
P_0c087574: /* original 8f1a, guest PC 0x0c087574 */
if(!s->budget--) { s->failed_pc=0x0c087574u; return 0; }
cond=r[17]&1u;
write(ram,r[4]+8,r[0],1);
if(!cond) { goto P_0c0875ac; }
goto P_0c087578;
P_0c087576: /* original 8048, guest PC 0x0c087576 */
if(!s->budget--) { s->failed_pc=0x0c087576u; return 0; }
write(ram,r[4]+8,r[0],1);
goto P_0c087578;
P_0c087578: /* original 8449, guest PC 0x0c087578 */
if(!s->budget--) { s->failed_pc=0x0c087578u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+9,1);
goto P_0c08757a;
P_0c08757a: /* original 6703, guest PC 0x0c08757a */
if(!s->budget--) { s->failed_pc=0x0c08757au; return 0; }
r[7]=r[0];
goto P_0c08757c;
P_0c08757c: /* original 4708, guest PC 0x0c08757c */
if(!s->budget--) { s->failed_pc=0x0c08757cu; return 0; }
r[7]<<=2;
goto P_0c08757e;
P_0c08757e: /* original 375c, guest PC 0x0c08757e */
if(!s->budget--) { s->failed_pc=0x0c08757eu; return 0; }
r[7]+=r[5];
goto P_0c087580;
P_0c087580: /* original 6603, guest PC 0x0c087580 */
if(!s->budget--) { s->failed_pc=0x0c087580u; return 0; }
r[6]=r[0];
goto P_0c087582;
P_0c087582: /* original 8471, guest PC 0x0c087582 */
if(!s->budget--) { s->failed_pc=0x0c087582u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+1,1);
goto P_0c087584;
P_0c087584: /* original 6703, guest PC 0x0c087584 */
if(!s->budget--) { s->failed_pc=0x0c087584u; return 0; }
r[7]=r[0];
goto P_0c087586;
P_0c087586: /* original 617e, guest PC 0x0c087586 */
if(!s->budget--) { s->failed_pc=0x0c087586u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c087588;
P_0c087588: /* original 6013, guest PC 0x0c087588 */
if(!s->budget--) { s->failed_pc=0x0c087588u; return 0; }
r[0]=r[1];
goto P_0c08758a;
P_0c08758a: /* original 88ff, guest PC 0x0c08758a */
if(!s->budget--) { s->failed_pc=0x0c08758au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c08758c;
P_0c08758c: /* original 8f03, guest PC 0x0c08758c */
if(!s->budget--) { s->failed_pc=0x0c08758cu; return 0; }
cond=r[17]&1u;
r[6]+=0x00000001u;
if(!cond) { goto P_0c087596; }
goto P_0c087590;
P_0c08758e: /* original 7601, guest PC 0x0c08758e */
if(!s->budget--) { s->failed_pc=0x0c08758eu; return 0; }
r[6]+=0x00000001u;
goto P_0c087590;
P_0c087590: /* original 6073, guest PC 0x0c087590 */
if(!s->budget--) { s->failed_pc=0x0c087590u; return 0; }
r[0]=r[7];
goto P_0c087592;
P_0c087592: /* original 000b, guest PC 0x0c087592 */
if(!s->budget--) { s->failed_pc=0x0c087592u; return 0; }
target=r[16];
write(ram,r[4]+8,r[0],1);
s->pc=target; return ram->oob==0;
P_0c087594: /* original 8048, guest PC 0x0c087594 */
if(!s->budget--) { s->failed_pc=0x0c087594u; return 0; }
write(ram,r[4]+8,r[0],1);
goto P_0c087596;
P_0c087596: /* original 2118, guest PC 0x0c087596 */
if(!s->budget--) { s->failed_pc=0x0c087596u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c087598;
P_0c087598: /* original 8900, guest PC 0x0c087598 */
if(!s->budget--) { s->failed_pc=0x0c087598u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08759c; }
goto P_0c08759a;
P_0c08759a: /* original e600, guest PC 0x0c08759a */
if(!s->budget--) { s->failed_pc=0x0c08759au; return 0; }
r[6]=0x00000000u;
goto P_0c08759c;
P_0c08759c: /* original 6063, guest PC 0x0c08759c */
if(!s->budget--) { s->failed_pc=0x0c08759cu; return 0; }
r[0]=r[6];
goto P_0c08759e;
P_0c08759e: /* original 4608, guest PC 0x0c08759e */
if(!s->budget--) { s->failed_pc=0x0c08759eu; return 0; }
r[6]<<=2;
goto P_0c0875a0;
P_0c0875a0: /* original 356c, guest PC 0x0c0875a0 */
if(!s->budget--) { s->failed_pc=0x0c0875a0u; return 0; }
r[5]+=r[6];
goto P_0c0875a2;
P_0c0875a2: /* original 8049, guest PC 0x0c0875a2 */
if(!s->budget--) { s->failed_pc=0x0c0875a2u; return 0; }
write(ram,r[4]+9,r[0],1);
goto P_0c0875a4;
P_0c0875a4: /* original 6050, guest PC 0x0c0875a4 */
if(!s->budget--) { s->failed_pc=0x0c0875a4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[0]=tmp;
goto P_0c0875a6;
P_0c0875a6: /* original 8048, guest PC 0x0c0875a6 */
if(!s->budget--) { s->failed_pc=0x0c0875a6u; return 0; }
write(ram,r[4]+8,r[0],1);
goto P_0c0875a8;
P_0c0875a8: /* original 8551, guest PC 0x0c0875a8 */
if(!s->budget--) { s->failed_pc=0x0c0875a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c0875aa;
P_0c0875aa: /* original 8145, guest PC 0x0c0875aa */
if(!s->budget--) { s->failed_pc=0x0c0875aau; return 0; }
write(ram,r[4]+10,r[0],2);
goto P_0c0875ac;
P_0c0875ac: /* original 000b, guest PC 0x0c0875ac */
if(!s->budget--) { s->failed_pc=0x0c0875acu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0875ae: /* original 0009, guest PC 0x0c0875ae */
if(!s->budget--) { s->failed_pc=0x0c0875aeu; return 0; }
goto P_0c0875b0;
P_0c0875b0: /* original 364c, guest PC 0x0c0875b0 */
if(!s->budget--) { s->failed_pc=0x0c0875b0u; return 0; }
r[6]+=r[4];
goto P_0c0875b2;
P_0c0875b2: /* original e0ff, guest PC 0x0c0875b2 */
if(!s->budget--) { s->failed_pc=0x0c0875b2u; return 0; }
r[0]=0xffffffffu;
goto P_0c0875b4;
P_0c0875b4: /* original 2402, guest PC 0x0c0875b4 */
if(!s->budget--) { s->failed_pc=0x0c0875b4u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c0875b6;
P_0c0875b6: /* original 1461, guest PC 0x0c0875b6 */
if(!s->budget--) { s->failed_pc=0x0c0875b6u; return 0; }
write(ram,r[4]+4,r[6],4);
goto P_0c0875b8;
P_0c0875b8: /* original 6463, guest PC 0x0c0875b8 */
if(!s->budget--) { s->failed_pc=0x0c0875b8u; return 0; }
r[4]=r[6];
goto P_0c0875ba;
P_0c0875ba: /* original 345c, guest PC 0x0c0875ba */
if(!s->budget--) { s->failed_pc=0x0c0875bau; return 0; }
r[4]+=r[5];
goto P_0c0875bc;
P_0c0875bc: /* original 2778, guest PC 0x0c0875bc */
if(!s->budget--) { s->failed_pc=0x0c0875bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0875be;
P_0c0875be: /* original 2642, guest PC 0x0c0875be */
if(!s->budget--) { s->failed_pc=0x0c0875beu; return 0; }
write(ram,r[6],r[4],4);
goto P_0c0875c0;
P_0c0875c0: /* original 8d02, guest PC 0x0c0875c0 */
if(!s->budget--) { s->failed_pc=0x0c0875c0u; return 0; }
cond=r[17]&1u;
r[6]+=r[5];
if(cond) { goto P_0c0875c8; }
goto P_0c0875c4;
P_0c0875c2: /* original 365c, guest PC 0x0c0875c2 */
if(!s->budget--) { s->failed_pc=0x0c0875c2u; return 0; }
r[6]+=r[5];
goto P_0c0875c4;
P_0c0875c4: /* original aff9, guest PC 0x0c0875c4 */
if(!s->budget--) { s->failed_pc=0x0c0875c4u; return 0; }
r[7]+=0xffffffffu;
goto P_0c0875ba;
P_0c0875c6: /* original 77ff, guest PC 0x0c0875c6 */
if(!s->budget--) { s->failed_pc=0x0c0875c6u; return 0; }
r[7]+=0xffffffffu;
goto P_0c0875c8;
P_0c0875c8: /* original 2602, guest PC 0x0c0875c8 */
if(!s->budget--) { s->failed_pc=0x0c0875c8u; return 0; }
write(ram,r[6],r[0],4);
goto P_0c0875ca;
P_0c0875ca: /* original 000b, guest PC 0x0c0875ca */
if(!s->budget--) { s->failed_pc=0x0c0875cau; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c0875cc: /* original 6063, guest PC 0x0c0875cc */
if(!s->budget--) { s->failed_pc=0x0c0875ccu; return 0; }
r[0]=r[6];
goto P_0c0875ce;
P_0c0875ce: /* original 5341, guest PC 0x0c0875ce */
if(!s->budget--) { s->failed_pc=0x0c0875ceu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0875d0;
P_0c0875d0: /* original 7ff8, guest PC 0x0c0875d0 */
if(!s->budget--) { s->failed_pc=0x0c0875d0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0875d2;
P_0c0875d2: /* original 2f32, guest PC 0x0c0875d2 */
if(!s->budget--) { s->failed_pc=0x0c0875d2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0875d4;
P_0c0875d4: /* original 6752, guest PC 0x0c0875d4 */
if(!s->budget--) { s->failed_pc=0x0c0875d4u; return 0; }
tmp=read(ram,r[5],4);
r[7]=tmp;
goto P_0c0875d6;
P_0c0875d6: /* original 5651, guest PC 0x0c0875d6 */
if(!s->budget--) { s->failed_pc=0x0c0875d6u; return 0; }
r[6]=read(ram,r[5]+4,4);
goto P_0c0875d8;
P_0c0875d8: /* original 6073, guest PC 0x0c0875d8 */
if(!s->budget--) { s->failed_pc=0x0c0875d8u; return 0; }
r[0]=r[7];
goto P_0c0875da;
P_0c0875da: /* original 88ff, guest PC 0x0c0875da */
if(!s->budget--) { s->failed_pc=0x0c0875dau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0875dc;
P_0c0875dc: /* original 1f71, guest PC 0x0c0875dc */
if(!s->budget--) { s->failed_pc=0x0c0875dcu; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c0875de;
P_0c0875de: /* original 8900, guest PC 0x0c0875de */
if(!s->budget--) { s->failed_pc=0x0c0875deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0875e2; }
goto P_0c0875e0;
P_0c0875e0: /* original 1761, guest PC 0x0c0875e0 */
if(!s->budget--) { s->failed_pc=0x0c0875e0u; return 0; }
write(ram,r[7]+4,r[6],4);
goto P_0c0875e2;
P_0c0875e2: /* original 6063, guest PC 0x0c0875e2 */
if(!s->budget--) { s->failed_pc=0x0c0875e2u; return 0; }
r[0]=r[6];
goto P_0c0875e4;
P_0c0875e4: /* original 2672, guest PC 0x0c0875e4 */
if(!s->budget--) { s->failed_pc=0x0c0875e4u; return 0; }
write(ram,r[6],r[7],4);
goto P_0c0875e6;
P_0c0875e6: /* original 62f2, guest PC 0x0c0875e6 */
if(!s->budget--) { s->failed_pc=0x0c0875e6u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0875e8;
P_0c0875e8: /* original 2522, guest PC 0x0c0875e8 */
if(!s->budget--) { s->failed_pc=0x0c0875e8u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c0875ea;
P_0c0875ea: /* original 1451, guest PC 0x0c0875ea */
if(!s->budget--) { s->failed_pc=0x0c0875eau; return 0; }
write(ram,r[4]+4,r[5],4);
goto P_0c0875ec;
P_0c0875ec: /* original 000b, guest PC 0x0c0875ec */
if(!s->budget--) { s->failed_pc=0x0c0875ecu; return 0; }
target=r[16];
r[15]+=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c0875ee: /* original 7f08, guest PC 0x0c0875ee */
if(!s->budget--) { s->failed_pc=0x0c0875eeu; return 0; }
r[15]+=0x00000008u;
if(!vf3_matrix_family(0x0c0875f0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0875f0u; return 0; } return 1;
P_0c088c34: /* original 2fe6, guest PC 0x0c088c34 */
if(!s->budget--) { s->failed_pc=0x0c088c34u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088c36;
P_0c088c36: /* original e000, guest PC 0x0c088c36 */
if(!s->budget--) { s->failed_pc=0x0c088c36u; return 0; }
r[0]=0x00000000u;
goto P_0c088c38;
P_0c088c38: /* original 2fd6, guest PC 0x0c088c38 */
if(!s->budget--) { s->failed_pc=0x0c088c38u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088c3a;
P_0c088c3a: /* original ee02, guest PC 0x0c088c3a */
if(!s->budget--) { s->failed_pc=0x0c088c3au; return 0; }
r[14]=0x00000002u;
goto P_0c088c3c;
P_0c088c3c: /* original 2fc6, guest PC 0x0c088c3c */
if(!s->budget--) { s->failed_pc=0x0c088c3cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088c3e;
P_0c088c3e: /* original 2fb6, guest PC 0x0c088c3e */
if(!s->budget--) { s->failed_pc=0x0c088c3eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088c40;
P_0c088c40: /* original 6b43, guest PC 0x0c088c40 */
if(!s->budget--) { s->failed_pc=0x0c088c40u; return 0; }
r[11]=r[4];
goto P_0c088c42;
P_0c088c42: /* original 2f86, guest PC 0x0c088c42 */
if(!s->budget--) { s->failed_pc=0x0c088c42u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088c44;
P_0c088c44: /* original 7410, guest PC 0x0c088c44 */
if(!s->budget--) { s->failed_pc=0x0c088c44u; return 0; }
r[4]+=0x00000010u;
goto P_0c088c46;
P_0c088c46: /* original 80b2, guest PC 0x0c088c46 */
if(!s->budget--) { s->failed_pc=0x0c088c46u; return 0; }
write(ram,r[11]+2,r[0],1);
goto P_0c088c48;
P_0c088c48: /* original 80b3, guest PC 0x0c088c48 */
if(!s->budget--) { s->failed_pc=0x0c088c48u; return 0; }
write(ram,r[11]+3,r[0],1);
goto P_0c088c4a;
P_0c088c4a: /* original c755, guest PC 0x0c088c4a */
if(!s->budget--) { s->failed_pc=0x0c088c4au; return 0; }
r[0]=code_base|0x00088da0u;
goto P_0c088c4c;
P_0c088c4c: /* original 4f22, guest PC 0x0c088c4c */
if(!s->budget--) { s->failed_pc=0x0c088c4cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c088c4e;
P_0c088c4e: /* original f408, guest PC 0x0c088c4e */
if(!s->budget--) { s->failed_pc=0x0c088c4eu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c088c50;
P_0c088c50: /* original d054, guest PC 0x0c088c50 */
if(!s->budget--) { s->failed_pc=0x0c088c50u; return 0; }
r[0]=read(ram,0x0c088da4u,4);
goto P_0c088c52;
P_0c088c52: /* original 68e3, guest PC 0x0c088c52 */
if(!s->budget--) { s->failed_pc=0x0c088c52u; return 0; }
r[8]=r[14];
goto P_0c088c54;
P_0c088c54: /* original 4808, guest PC 0x0c088c54 */
if(!s->budget--) { s->failed_pc=0x0c088c54u; return 0; }
r[8]<<=2;
goto P_0c088c56;
P_0c088c56: /* original 62e3, guest PC 0x0c088c56 */
if(!s->budget--) { s->failed_pc=0x0c088c56u; return 0; }
r[2]=r[14];
goto P_0c088c58;
P_0c088c58: /* original 07ec, guest PC 0x0c088c58 */
if(!s->budget--) { s->failed_pc=0x0c088c58u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c088c5a;
P_0c088c5a: /* original 6c73, guest PC 0x0c088c5a */
if(!s->budget--) { s->failed_pc=0x0c088c5au; return 0; }
r[12]=r[7];
goto P_0c088c5c;
P_0c088c5c: /* original 6d73, guest PC 0x0c088c5c */
if(!s->budget--) { s->failed_pc=0x0c088c5cu; return 0; }
r[13]=r[7];
goto P_0c088c5e;
P_0c088c5e: /* original 4c08, guest PC 0x0c088c5e */
if(!s->budget--) { s->failed_pc=0x0c088c5eu; return 0; }
r[12]<<=2;
goto P_0c088c60;
P_0c088c60: /* original 4d00, guest PC 0x0c088c60 */
if(!s->budget--) { s->failed_pc=0x0c088c60u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c088c62;
P_0c088c62: /* original 4c00, guest PC 0x0c088c62 */
if(!s->budget--) { s->failed_pc=0x0c088c62u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c088c64;
P_0c088c64: /* original 4800, guest PC 0x0c088c64 */
if(!s->budget--) { s->failed_pc=0x0c088c64u; return 0; }
r[17]=(r[17]&~1u)|((r[8]>>31)!=0);
r[8]<<=1;
goto P_0c088c66;
P_0c088c66: /* original 4200, guest PC 0x0c088c66 */
if(!s->budget--) { s->failed_pc=0x0c088c66u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c088c68;
P_0c088c68: /* original 4711, guest PC 0x0c088c68 */
if(!s->budget--) { s->failed_pc=0x0c088c68u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=0)!=0);
goto P_0c088c6a;
P_0c088c6a: /* original 8b37, guest PC 0x0c088c6a */
if(!s->budget--) { s->failed_pc=0x0c088c6au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c088cdc; }
goto P_0c088c6c;
P_0c088c6c: /* original 66c3, guest PC 0x0c088c6c */
if(!s->budget--) { s->failed_pc=0x0c088c6cu; return 0; }
r[6]=r[12];
goto P_0c088c6e;
P_0c088c6e: /* original 36dc, guest PC 0x0c088c6e */
if(!s->budget--) { s->failed_pc=0x0c088c6eu; return 0; }
r[6]+=r[13];
goto P_0c088c70;
P_0c088c70: /* original 4600, guest PC 0x0c088c70 */
if(!s->budget--) { s->failed_pc=0x0c088c70u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c088c72;
P_0c088c72: /* original 6583, guest PC 0x0c088c72 */
if(!s->budget--) { s->failed_pc=0x0c088c72u; return 0; }
r[5]=r[8];
goto P_0c088c74;
P_0c088c74: /* original 6163, guest PC 0x0c088c74 */
if(!s->budget--) { s->failed_pc=0x0c088c74u; return 0; }
r[1]=r[6];
goto P_0c088c76;
P_0c088c76: /* original 760a, guest PC 0x0c088c76 */
if(!s->budget--) { s->failed_pc=0x0c088c76u; return 0; }
r[6]+=0x0000000au;
goto P_0c088c78;
P_0c088c78: /* original 465a, guest PC 0x0c088c78 */
if(!s->budget--) { s->failed_pc=0x0c088c78u; return 0; }
r[53]=r[6];
goto P_0c088c7a;
P_0c088c7a: /* original 352c, guest PC 0x0c088c7a */
if(!s->budget--) { s->failed_pc=0x0c088c7au; return 0; }
r[5]+=r[2];
goto P_0c088c7c;
P_0c088c7c: /* original 4500, guest PC 0x0c088c7c */
if(!s->budget--) { s->failed_pc=0x0c088c7cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c088c7e;
P_0c088c7e: /* original 215b, guest PC 0x0c088c7e */
if(!s->budget--) { s->failed_pc=0x0c088c7eu; return 0; }
r[1]|=r[5];
goto P_0c088c80;
P_0c088c80: /* original f32d, guest PC 0x0c088c80 */
if(!s->budget--) { s->failed_pc=0x0c088c80u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c088c82;
P_0c088c82: /* original 750a, guest PC 0x0c088c82 */
if(!s->budget--) { s->failed_pc=0x0c088c82u; return 0; }
r[5]+=0x0000000au;
goto P_0c088c84;
P_0c088c84: /* original 455a, guest PC 0x0c088c84 */
if(!s->budget--) { s->failed_pc=0x0c088c84u; return 0; }
r[53]=r[5];
goto P_0c088c86;
P_0c088c86: /* original e004, guest PC 0x0c088c86 */
if(!s->budget--) { s->failed_pc=0x0c088c86u; return 0; }
r[0]=0x00000004u;
goto P_0c088c88;
P_0c088c88: /* original 9586, guest PC 0x0c088c88 */
if(!s->budget--) { s->failed_pc=0x0c088c88u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088d98u,2);
goto P_0c088c8a;
P_0c088c8a: /* original f22d, guest PC 0x0c088c8a */
if(!s->budget--) { s->failed_pc=0x0c088c8au; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c088c8c;
P_0c088c8c: /* original f53c, guest PC 0x0c088c8c */
if(!s->budget--) { s->failed_pc=0x0c088c8cu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c088c8e;
P_0c088c8e: /* original f341, guest PC 0x0c088c8e */
if(!s->budget--) { s->failed_pc=0x0c088c8eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c088c90;
P_0c088c90: /* original f72c, guest PC 0x0c088c90 */
if(!s->budget--) { s->failed_pc=0x0c088c90u; return 0; }
vf3_matrix_move(s,7,2);
goto P_0c088c92;
P_0c088c92: /* original f43a, guest PC 0x0c088c92 */
if(!s->budget--) { s->failed_pc=0x0c088c92u; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c088c94;
P_0c088c94: /* original f97c, guest PC 0x0c088c94 */
if(!s->budget--) { s->failed_pc=0x0c088c94u; return 0; }
vf3_matrix_move(s,9,7);
goto P_0c088c96;
P_0c088c96: /* original f940, guest PC 0x0c088c96 */
if(!s->budget--) { s->failed_pc=0x0c088c96u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[4],r[18],'+');
goto P_0c088c98;
P_0c088c98: /* original f497, guest PC 0x0c088c98 */
if(!s->budget--) { s->failed_pc=0x0c088c98u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c088c9a;
P_0c088c9a: /* original 1452, guest PC 0x0c088c9a */
if(!s->budget--) { s->failed_pc=0x0c088c9au; return 0; }
write(ram,r[4]+8,r[5],4);
goto P_0c088c9c;
P_0c088c9c: /* original 740c, guest PC 0x0c088c9c */
if(!s->budget--) { s->failed_pc=0x0c088c9cu; return 0; }
r[4]+=0x0000000cu;
goto P_0c088c9e;
P_0c088c9e: /* original f65c, guest PC 0x0c088c9e */
if(!s->budget--) { s->failed_pc=0x0c088c9eu; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c088ca0;
P_0c088ca0: /* original f64d, guest PC 0x0c088ca0 */
if(!s->budget--) { s->failed_pc=0x0c088ca0u; return 0; }
fr[6]^=0x80000000u;
goto P_0c088ca2;
P_0c088ca2: /* original f36c, guest PC 0x0c088ca2 */
if(!s->budget--) { s->failed_pc=0x0c088ca2u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c088ca4;
P_0c088ca4: /* original f341, guest PC 0x0c088ca4 */
if(!s->budget--) { s->failed_pc=0x0c088ca4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c088ca6;
P_0c088ca6: /* original f43a, guest PC 0x0c088ca6 */
if(!s->budget--) { s->failed_pc=0x0c088ca6u; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c088ca8;
P_0c088ca8: /* original f497, guest PC 0x0c088ca8 */
if(!s->budget--) { s->failed_pc=0x0c088ca8u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c088caa;
P_0c088caa: /* original 1452, guest PC 0x0c088caa */
if(!s->budget--) { s->failed_pc=0x0c088caau; return 0; }
write(ram,r[4]+8,r[5],4);
goto P_0c088cac;
P_0c088cac: /* original 2118, guest PC 0x0c088cac */
if(!s->budget--) { s->failed_pc=0x0c088cacu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c088cae;
P_0c088cae: /* original 8d09, guest PC 0x0c088cae */
if(!s->budget--) { s->failed_pc=0x0c088caeu; return 0; }
cond=r[17]&1u;
r[4]+=0x0000000cu;
if(cond) { goto P_0c088cc4; }
goto P_0c088cb2;
P_0c088cb0: /* original 740c, guest PC 0x0c088cb0 */
if(!s->budget--) { s->failed_pc=0x0c088cb0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c088cb2;
P_0c088cb2: /* original f87c, guest PC 0x0c088cb2 */
if(!s->budget--) { s->failed_pc=0x0c088cb2u; return 0; }
vf3_matrix_move(s,8,7);
goto P_0c088cb4;
P_0c088cb4: /* original f541, guest PC 0x0c088cb4 */
if(!s->budget--) { s->failed_pc=0x0c088cb4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'-');
goto P_0c088cb6;
P_0c088cb6: /* original f84d, guest PC 0x0c088cb6 */
if(!s->budget--) { s->failed_pc=0x0c088cb6u; return 0; }
fr[8]^=0x80000000u;
goto P_0c088cb8;
P_0c088cb8: /* original f45a, guest PC 0x0c088cb8 */
if(!s->budget--) { s->failed_pc=0x0c088cb8u; return 0; }
vf3_matrix_store(s,ram,5,r[4]);
goto P_0c088cba;
P_0c088cba: /* original f38c, guest PC 0x0c088cba */
if(!s->budget--) { s->failed_pc=0x0c088cbau; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c088cbc;
P_0c088cbc: /* original f340, guest PC 0x0c088cbc */
if(!s->budget--) { s->failed_pc=0x0c088cbcu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c088cbe;
P_0c088cbe: /* original f437, guest PC 0x0c088cbe */
if(!s->budget--) { s->failed_pc=0x0c088cbeu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c088cc0;
P_0c088cc0: /* original 1452, guest PC 0x0c088cc0 */
if(!s->budget--) { s->failed_pc=0x0c088cc0u; return 0; }
write(ram,r[4]+8,r[5],4);
goto P_0c088cc2;
P_0c088cc2: /* original 740c, guest PC 0x0c088cc2 */
if(!s->budget--) { s->failed_pc=0x0c088cc2u; return 0; }
r[4]+=0x0000000cu;
goto P_0c088cc4;
P_0c088cc4: /* original f641, guest PC 0x0c088cc4 */
if(!s->budget--) { s->failed_pc=0x0c088cc4u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'-');
goto P_0c088cc6;
P_0c088cc6: /* original 77ff, guest PC 0x0c088cc6 */
if(!s->budget--) { s->failed_pc=0x0c088cc6u; return 0; }
r[7]+=0xffffffffu;
goto P_0c088cc8;
P_0c088cc8: /* original 4711, guest PC 0x0c088cc8 */
if(!s->budget--) { s->failed_pc=0x0c088cc8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=0)!=0);
goto P_0c088cca;
P_0c088cca: /* original 7dfe, guest PC 0x0c088cca */
if(!s->budget--) { s->failed_pc=0x0c088ccau; return 0; }
r[13]+=0xfffffffeu;
goto P_0c088ccc;
P_0c088ccc: /* original f46a, guest PC 0x0c088ccc */
if(!s->budget--) { s->failed_pc=0x0c088cccu; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c088cce;
P_0c088cce: /* original f38c, guest PC 0x0c088cce */
if(!s->budget--) { s->failed_pc=0x0c088cceu; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c088cd0;
P_0c088cd0: /* original f340, guest PC 0x0c088cd0 */
if(!s->budget--) { s->failed_pc=0x0c088cd0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c088cd2;
P_0c088cd2: /* original f437, guest PC 0x0c088cd2 */
if(!s->budget--) { s->failed_pc=0x0c088cd2u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c088cd4;
P_0c088cd4: /* original 1452, guest PC 0x0c088cd4 */
if(!s->budget--) { s->failed_pc=0x0c088cd4u; return 0; }
write(ram,r[4]+8,r[5],4);
goto P_0c088cd6;
P_0c088cd6: /* original 740c, guest PC 0x0c088cd6 */
if(!s->budget--) { s->failed_pc=0x0c088cd6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c088cd8;
P_0c088cd8: /* original 8dc8, guest PC 0x0c088cd8 */
if(!s->budget--) { s->failed_pc=0x0c088cd8u; return 0; }
cond=r[17]&1u;
r[12]+=0xfffffff8u;
if(cond) { goto P_0c088c6c; }
goto P_0c088cdc;
P_0c088cda: /* original 7cf8, guest PC 0x0c088cda */
if(!s->budget--) { s->failed_pc=0x0c088cdau; return 0; }
r[12]+=0xfffffff8u;
goto P_0c088cdc;
P_0c088cdc: /* original 7eff, guest PC 0x0c088cdc */
if(!s->budget--) { s->failed_pc=0x0c088cdcu; return 0; }
r[14]+=0xffffffffu;
goto P_0c088cde;
P_0c088cde: /* original 4e11, guest PC 0x0c088cde */
if(!s->budget--) { s->failed_pc=0x0c088cdeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c088ce0;
P_0c088ce0: /* original 89b6, guest PC 0x0c088ce0 */
if(!s->budget--) { s->failed_pc=0x0c088ce0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088c50; }
goto P_0c088ce2;
P_0c088ce2: /* original d331, guest PC 0x0c088ce2 */
if(!s->budget--) { s->failed_pc=0x0c088ce2u; return 0; }
r[3]=read(ram,0x0c088da8u,4);
goto P_0c088ce4;
P_0c088ce4: /* original 430b, guest PC 0x0c088ce4 */
if(!s->budget--) { s->failed_pc=0x0c088ce4u; return 0; }
target=r[3];
r[16]=code_base|0x0c088ce8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088ce8u) { target=s->pc; goto dispatch; }
goto P_0c088ce8;
P_0c088ce6: /* original 0009, guest PC 0x0c088ce6 */
if(!s->budget--) { s->failed_pc=0x0c088ce6u; return 0; }
goto P_0c088ce8;
P_0c088ce8: /* original 640d, guest PC 0x0c088ce8 */
if(!s->budget--) { s->failed_pc=0x0c088ce8u; return 0; }
r[4]=r[0]&65535u;
goto P_0c088cea;
P_0c088cea: /* original e000, guest PC 0x0c088cea */
if(!s->budget--) { s->failed_pc=0x0c088ceau; return 0; }
r[0]=0x00000000u;
goto P_0c088cec;
P_0c088cec: /* original 4f26, guest PC 0x0c088cec */
if(!s->budget--) { s->failed_pc=0x0c088cecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c088cee;
P_0c088cee: /* original 81b2, guest PC 0x0c088cee */
if(!s->budget--) { s->failed_pc=0x0c088ceeu; return 0; }
write(ram,r[11]+4,r[0],2);
goto P_0c088cf0;
P_0c088cf0: /* original 6043, guest PC 0x0c088cf0 */
if(!s->budget--) { s->failed_pc=0x0c088cf0u; return 0; }
r[0]=r[4];
goto P_0c088cf2;
P_0c088cf2: /* original 654c, guest PC 0x0c088cf2 */
if(!s->budget--) { s->failed_pc=0x0c088cf2u; return 0; }
r[5]=r[4]&255u;
goto P_0c088cf4;
P_0c088cf4: /* original 81b3, guest PC 0x0c088cf4 */
if(!s->budget--) { s->failed_pc=0x0c088cf4u; return 0; }
write(ram,r[11]+6,r[0],2);
goto P_0c088cf6;
P_0c088cf6: /* original 6053, guest PC 0x0c088cf6 */
if(!s->budget--) { s->failed_pc=0x0c088cf6u; return 0; }
r[0]=r[5];
goto P_0c088cf8;
P_0c088cf8: /* original 81b4, guest PC 0x0c088cf8 */
if(!s->budget--) { s->failed_pc=0x0c088cf8u; return 0; }
write(ram,r[11]+8,r[0],2);
goto P_0c088cfa;
P_0c088cfa: /* original 68f6, guest PC 0x0c088cfa */
if(!s->budget--) { s->failed_pc=0x0c088cfau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c088cfc;
P_0c088cfc: /* original 6bf6, guest PC 0x0c088cfc */
if(!s->budget--) { s->failed_pc=0x0c088cfcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c088cfe;
P_0c088cfe: /* original 6cf6, guest PC 0x0c088cfe */
if(!s->budget--) { s->failed_pc=0x0c088cfeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c088d00;
P_0c088d00: /* original 6df6, guest PC 0x0c088d00 */
if(!s->budget--) { s->failed_pc=0x0c088d00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c088d02;
P_0c088d02: /* original 000b, guest PC 0x0c088d02 */
if(!s->budget--) { s->failed_pc=0x0c088d02u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c088d04: /* original 6ef6, guest PC 0x0c088d04 */
if(!s->budget--) { s->failed_pc=0x0c088d04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c088d06;
P_0c088d06: /* original 2fe6, guest PC 0x0c088d06 */
if(!s->budget--) { s->failed_pc=0x0c088d06u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088d08;
P_0c088d08: /* original 2fd6, guest PC 0x0c088d08 */
if(!s->budget--) { s->failed_pc=0x0c088d08u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088d0a;
P_0c088d0a: /* original 2fc6, guest PC 0x0c088d0a */
if(!s->budget--) { s->failed_pc=0x0c088d0au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088d0c;
P_0c088d0c: /* original fffb, guest PC 0x0c088d0c */
if(!s->budget--) { s->failed_pc=0x0c088d0cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c088d0e;
P_0c088d0e: /* original d128, guest PC 0x0c088d0e */
if(!s->budget--) { s->failed_pc=0x0c088d0eu; return 0; }
r[1]=read(ram,0x0c088db0u,4);
goto P_0c088d10;
P_0c088d10: /* original 4f22, guest PC 0x0c088d10 */
if(!s->budget--) { s->failed_pc=0x0c088d10u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c088d12;
P_0c088d12: /* original 6212, guest PC 0x0c088d12 */
if(!s->budget--) { s->failed_pc=0x0c088d12u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c088d14;
P_0c088d14: /* original d325, guest PC 0x0c088d14 */
if(!s->budget--) { s->failed_pc=0x0c088d14u; return 0; }
r[3]=read(ram,0x0c088dacu,4);
goto P_0c088d16;
P_0c088d16: /* original 7ffc, guest PC 0x0c088d16 */
if(!s->budget--) { s->failed_pc=0x0c088d16u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c088d18;
P_0c088d18: /* original 2238, guest PC 0x0c088d18 */
if(!s->budget--) { s->failed_pc=0x0c088d18u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c088d1a;
P_0c088d1a: /* original 8b36, guest PC 0x0c088d1a */
if(!s->budget--) { s->failed_pc=0x0c088d1au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c088d8a; }
goto P_0c088d1c;
P_0c088d1c: /* original 6e43, guest PC 0x0c088d1c */
if(!s->budget--) { s->failed_pc=0x0c088d1cu; return 0; }
r[14]=r[4];
goto P_0c088d1e;
P_0c088d1e: /* original 84e3, guest PC 0x0c088d1e */
if(!s->budget--) { s->failed_pc=0x0c088d1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+3,1);
goto P_0c088d20;
P_0c088d20: /* original 6403, guest PC 0x0c088d20 */
if(!s->budget--) { s->failed_pc=0x0c088d20u; return 0; }
r[4]=r[0];
goto P_0c088d22;
P_0c088d22: /* original 74ff, guest PC 0x0c088d22 */
if(!s->budget--) { s->failed_pc=0x0c088d22u; return 0; }
r[4]+=0xffffffffu;
goto P_0c088d24;
P_0c088d24: /* original 634e, guest PC 0x0c088d24 */
if(!s->budget--) { s->failed_pc=0x0c088d24u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c088d26;
P_0c088d26: /* original 4311, guest PC 0x0c088d26 */
if(!s->budget--) { s->failed_pc=0x0c088d26u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c088d28;
P_0c088d28: /* original 8907, guest PC 0x0c088d28 */
if(!s->budget--) { s->failed_pc=0x0c088d28u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088d3a; }
goto P_0c088d2a;
P_0c088d2a: /* original 84e2, guest PC 0x0c088d2a */
if(!s->budget--) { s->failed_pc=0x0c088d2au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c088d2c;
P_0c088d2c: /* original e31f, guest PC 0x0c088d2c */
if(!s->budget--) { s->failed_pc=0x0c088d2cu; return 0; }
r[3]=0x0000001fu;
goto P_0c088d2e;
P_0c088d2e: /* original e402, guest PC 0x0c088d2e */
if(!s->budget--) { s->failed_pc=0x0c088d2eu; return 0; }
r[4]=0x00000002u;
goto P_0c088d30;
P_0c088d30: /* original 6503, guest PC 0x0c088d30 */
if(!s->budget--) { s->failed_pc=0x0c088d30u; return 0; }
r[5]=r[0];
goto P_0c088d32;
P_0c088d32: /* original 7501, guest PC 0x0c088d32 */
if(!s->budget--) { s->failed_pc=0x0c088d32u; return 0; }
r[5]+=0x00000001u;
goto P_0c088d34;
P_0c088d34: /* original 2539, guest PC 0x0c088d34 */
if(!s->budget--) { s->failed_pc=0x0c088d34u; return 0; }
r[5]&=r[3];
goto P_0c088d36;
P_0c088d36: /* original 6053, guest PC 0x0c088d36 */
if(!s->budget--) { s->failed_pc=0x0c088d36u; return 0; }
r[0]=r[5];
goto P_0c088d38;
P_0c088d38: /* original 80e2, guest PC 0x0c088d38 */
if(!s->budget--) { s->failed_pc=0x0c088d38u; return 0; }
write(ram,r[14]+2,r[0],1);
goto P_0c088d3a;
P_0c088d3a: /* original 6043, guest PC 0x0c088d3a */
if(!s->budget--) { s->failed_pc=0x0c088d3au; return 0; }
r[0]=r[4];
goto P_0c088d3c;
P_0c088d3c: /* original 80e3, guest PC 0x0c088d3c */
if(!s->budget--) { s->failed_pc=0x0c088d3cu; return 0; }
write(ram,r[14]+3,r[0],1);
goto P_0c088d3e;
P_0c088d3e: /* original 64e0, guest PC 0x0c088d3e */
if(!s->budget--) { s->failed_pc=0x0c088d3eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[4]=tmp;
goto P_0c088d40;
P_0c088d40: /* original e30f, guest PC 0x0c088d40 */
if(!s->budget--) { s->failed_pc=0x0c088d40u; return 0; }
r[3]=0x0000000fu;
goto P_0c088d42;
P_0c088d42: /* original 7401, guest PC 0x0c088d42 */
if(!s->budget--) { s->failed_pc=0x0c088d42u; return 0; }
r[4]+=0x00000001u;
goto P_0c088d44;
P_0c088d44: /* original 2439, guest PC 0x0c088d44 */
if(!s->budget--) { s->failed_pc=0x0c088d44u; return 0; }
r[4]&=r[3];
goto P_0c088d46;
P_0c088d46: /* original 2e40, guest PC 0x0c088d46 */
if(!s->budget--) { s->failed_pc=0x0c088d46u; return 0; }
write(ram,r[14],r[4],1);
goto P_0c088d48;
P_0c088d48: /* original 85e6, guest PC 0x0c088d48 */
if(!s->budget--) { s->failed_pc=0x0c088d48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c088d4a;
P_0c088d4a: /* original 9127, guest PC 0x0c088d4a */
if(!s->budget--) { s->failed_pc=0x0c088d4au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088d9cu,2);
goto P_0c088d4c;
P_0c088d4c: /* original 6d03, guest PC 0x0c088d4c */
if(!s->budget--) { s->failed_pc=0x0c088d4cu; return 0; }
r[13]=r[0];
goto P_0c088d4e;
P_0c088d4e: /* original 85e7, guest PC 0x0c088d4e */
if(!s->budget--) { s->failed_pc=0x0c088d4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c088d50;
P_0c088d50: /* original 9223, guest PC 0x0c088d50 */
if(!s->budget--) { s->failed_pc=0x0c088d50u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088d9au,2);
goto P_0c088d52;
P_0c088d52: /* original 6c03, guest PC 0x0c088d52 */
if(!s->budget--) { s->failed_pc=0x0c088d52u; return 0; }
r[12]=r[0];
goto P_0c088d54;
P_0c088d54: /* original c717, guest PC 0x0c088d54 */
if(!s->budget--) { s->failed_pc=0x0c088d54u; return 0; }
r[0]=code_base|0x00088db4u;
goto P_0c088d56;
P_0c088d56: /* original d318, guest PC 0x0c088d56 */
if(!s->budget--) { s->failed_pc=0x0c088d56u; return 0; }
r[3]=read(ram,0x0c088db8u,4);
goto P_0c088d58;
P_0c088d58: /* original 3c1c, guest PC 0x0c088d58 */
if(!s->budget--) { s->failed_pc=0x0c088d58u; return 0; }
r[12]+=r[1];
goto P_0c088d5a;
P_0c088d5a: /* original ff08, guest PC 0x0c088d5a */
if(!s->budget--) { s->failed_pc=0x0c088d5au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c088d5c;
P_0c088d5c: /* original 3d2c, guest PC 0x0c088d5c */
if(!s->budget--) { s->failed_pc=0x0c088d5cu; return 0; }
r[13]+=r[2];
goto P_0c088d5e;
P_0c088d5e: /* original 430b, guest PC 0x0c088d5e */
if(!s->budget--) { s->failed_pc=0x0c088d5eu; return 0; }
target=r[3];
r[16]=code_base|0x0c088d62u;
r[4]=(uint32_t)(int32_t)(int16_t)r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088d62u) { target=s->pc; goto dispatch; }
goto P_0c088d62;
P_0c088d60: /* original 64df, guest PC 0x0c088d60 */
if(!s->budget--) { s->failed_pc=0x0c088d60u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c088d62;
P_0c088d62: /* original f40c, guest PC 0x0c088d62 */
if(!s->budget--) { s->failed_pc=0x0c088d62u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c088d64;
P_0c088d64: /* original f4f2, guest PC 0x0c088d64 */
if(!s->budget--) { s->failed_pc=0x0c088d64u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c088d66;
P_0c088d66: /* original f43d, guest PC 0x0c088d66 */
if(!s->budget--) { s->failed_pc=0x0c088d66u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c088d68;
P_0c088d68: /* original 025a, guest PC 0x0c088d68 */
if(!s->budget--) { s->failed_pc=0x0c088d68u; return 0; }
r[2]=r[53];
goto P_0c088d6a;
P_0c088d6a: /* original 2f21, guest PC 0x0c088d6a */
if(!s->budget--) { s->failed_pc=0x0c088d6au; return 0; }
write(ram,r[15],r[2],2);
goto P_0c088d6c;
P_0c088d6c: /* original d312, guest PC 0x0c088d6c */
if(!s->budget--) { s->failed_pc=0x0c088d6cu; return 0; }
r[3]=read(ram,0x0c088db8u,4);
goto P_0c088d6e;
P_0c088d6e: /* original 430b, guest PC 0x0c088d6e */
if(!s->budget--) { s->failed_pc=0x0c088d6eu; return 0; }
target=r[3];
r[16]=code_base|0x0c088d72u;
r[4]=(uint32_t)(int32_t)(int16_t)r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088d72u) { target=s->pc; goto dispatch; }
goto P_0c088d72;
P_0c088d70: /* original 64cf, guest PC 0x0c088d70 */
if(!s->budget--) { s->failed_pc=0x0c088d70u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c088d72;
P_0c088d72: /* original f40c, guest PC 0x0c088d72 */
if(!s->budget--) { s->failed_pc=0x0c088d72u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c088d74;
P_0c088d74: /* original f4f2, guest PC 0x0c088d74 */
if(!s->budget--) { s->failed_pc=0x0c088d74u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c088d76;
P_0c088d76: /* original 60d3, guest PC 0x0c088d76 */
if(!s->budget--) { s->failed_pc=0x0c088d76u; return 0; }
r[0]=r[13];
goto P_0c088d78;
P_0c088d78: /* original f43d, guest PC 0x0c088d78 */
if(!s->budget--) { s->failed_pc=0x0c088d78u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c088d7a;
P_0c088d7a: /* original 045a, guest PC 0x0c088d7a */
if(!s->budget--) { s->failed_pc=0x0c088d7au; return 0; }
r[4]=r[53];
goto P_0c088d7c;
P_0c088d7c: /* original 81e6, guest PC 0x0c088d7c */
if(!s->budget--) { s->failed_pc=0x0c088d7cu; return 0; }
write(ram,r[14]+12,r[0],2);
goto P_0c088d7e;
P_0c088d7e: /* original 60c3, guest PC 0x0c088d7e */
if(!s->budget--) { s->failed_pc=0x0c088d7eu; return 0; }
r[0]=r[12];
goto P_0c088d80;
P_0c088d80: /* original 81e7, guest PC 0x0c088d80 */
if(!s->budget--) { s->failed_pc=0x0c088d80u; return 0; }
write(ram,r[14]+14,r[0],2);
goto P_0c088d82;
P_0c088d82: /* original 60f1, guest PC 0x0c088d82 */
if(!s->budget--) { s->failed_pc=0x0c088d82u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[0]=tmp;
goto P_0c088d84;
P_0c088d84: /* original 81e3, guest PC 0x0c088d84 */
if(!s->budget--) { s->failed_pc=0x0c088d84u; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c088d86;
P_0c088d86: /* original 6043, guest PC 0x0c088d86 */
if(!s->budget--) { s->failed_pc=0x0c088d86u; return 0; }
r[0]=r[4];
goto P_0c088d88;
P_0c088d88: /* original 81e4, guest PC 0x0c088d88 */
if(!s->budget--) { s->failed_pc=0x0c088d88u; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c088d8a;
P_0c088d8a: /* original 7f04, guest PC 0x0c088d8a */
if(!s->budget--) { s->failed_pc=0x0c088d8au; return 0; }
r[15]+=0x00000004u;
goto P_0c088d8c;
P_0c088d8c: /* original 4f26, guest PC 0x0c088d8c */
if(!s->budget--) { s->failed_pc=0x0c088d8cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c088d8e;
P_0c088d8e: /* original fff9, guest PC 0x0c088d8e */
if(!s->budget--) { s->failed_pc=0x0c088d8eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088d90;
P_0c088d90: /* original 6cf6, guest PC 0x0c088d90 */
if(!s->budget--) { s->failed_pc=0x0c088d90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c088d92;
P_0c088d92: /* original 6df6, guest PC 0x0c088d92 */
if(!s->budget--) { s->failed_pc=0x0c088d92u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c088d94;
P_0c088d94: /* original 000b, guest PC 0x0c088d94 */
if(!s->budget--) { s->failed_pc=0x0c088d94u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c088d96: /* original 6ef6, guest PC 0x0c088d96 */
if(!s->budget--) { s->failed_pc=0x0c088d96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c088d98u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c088d98u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
