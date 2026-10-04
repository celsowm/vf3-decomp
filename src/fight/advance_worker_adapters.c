/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_advance_worker_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03da50u: goto P_0c03da50;
case 0x0c03da52u: goto P_0c03da52;
case 0x0c03da54u: goto P_0c03da54;
case 0x0c03da56u: goto P_0c03da56;
case 0x0c03da58u: goto P_0c03da58;
case 0x0c03da5au: goto P_0c03da5a;
case 0x0c03da5cu: goto P_0c03da5c;
case 0x0c03da5eu: goto P_0c03da5e;
case 0x0c03da60u: goto P_0c03da60;
case 0x0c03da62u: goto P_0c03da62;
case 0x0c03da64u: goto P_0c03da64;
case 0x0c03da66u: goto P_0c03da66;
case 0x0c03da68u: goto P_0c03da68;
case 0x0c03da6au: goto P_0c03da6a;
case 0x0c03da6cu: goto P_0c03da6c;
case 0x0c03da6eu: goto P_0c03da6e;
case 0x0c03da70u: goto P_0c03da70;
case 0x0c03da72u: goto P_0c03da72;
case 0x0c03da74u: goto P_0c03da74;
case 0x0c03da76u: goto P_0c03da76;
case 0x0c03da78u: goto P_0c03da78;
case 0x0c03da7au: goto P_0c03da7a;
case 0x0c03da7cu: goto P_0c03da7c;
case 0x0c03da7eu: goto P_0c03da7e;
case 0x0c03da80u: goto P_0c03da80;
case 0x0c03da82u: goto P_0c03da82;
case 0x0c03da84u: goto P_0c03da84;
case 0x0c03da86u: goto P_0c03da86;
case 0x0c03da88u: goto P_0c03da88;
case 0x0c03da8au: goto P_0c03da8a;
case 0x0c03da8cu: goto P_0c03da8c;
case 0x0c03da8eu: goto P_0c03da8e;
case 0x0c03da90u: goto P_0c03da90;
case 0x0c03da92u: goto P_0c03da92;
case 0x0c03da94u: goto P_0c03da94;
case 0x0c03da96u: goto P_0c03da96;
case 0x0c03da98u: goto P_0c03da98;
case 0x0c03da9au: goto P_0c03da9a;
case 0x0c03da9cu: goto P_0c03da9c;
case 0x0c03da9eu: goto P_0c03da9e;
case 0x0c03daa0u: goto P_0c03daa0;
case 0x0c03daa2u: goto P_0c03daa2;
case 0x0c03daa4u: goto P_0c03daa4;
case 0x0c03daa6u: goto P_0c03daa6;
case 0x0c03daa8u: goto P_0c03daa8;
case 0x0c03daaau: goto P_0c03daaa;
case 0x0c03daacu: goto P_0c03daac;
case 0x0c03daaeu: goto P_0c03daae;
case 0x0c03dab0u: goto P_0c03dab0;
case 0x0c03dab2u: goto P_0c03dab2;
case 0x0c03dab4u: goto P_0c03dab4;
case 0x0c03dab6u: goto P_0c03dab6;
case 0x0c03dab8u: goto P_0c03dab8;
case 0x0c03dabau: goto P_0c03daba;
case 0x0c03dad0u: goto P_0c03dad0;
case 0x0c03dad2u: goto P_0c03dad2;
case 0x0c03dad4u: goto P_0c03dad4;
case 0x0c03dad6u: goto P_0c03dad6;
case 0x0c03dad8u: goto P_0c03dad8;
case 0x0c03dadau: goto P_0c03dada;
case 0x0c03dadcu: goto P_0c03dadc;
case 0x0c03dadeu: goto P_0c03dade;
case 0x0c03dae0u: goto P_0c03dae0;
case 0x0c03dae2u: goto P_0c03dae2;
case 0x0c03dae4u: goto P_0c03dae4;
case 0x0c03dae6u: goto P_0c03dae6;
case 0x0c03dae8u: goto P_0c03dae8;
case 0x0c03daeau: goto P_0c03daea;
case 0x0c03daecu: goto P_0c03daec;
case 0x0c03daeeu: goto P_0c03daee;
case 0x0c03daf0u: goto P_0c03daf0;
case 0x0c03daf2u: goto P_0c03daf2;
case 0x0c03daf4u: goto P_0c03daf4;
case 0x0c03daf6u: goto P_0c03daf6;
case 0x0c03daf8u: goto P_0c03daf8;
case 0x0c03dafau: goto P_0c03dafa;
case 0x0c03dafcu: goto P_0c03dafc;
case 0x0c03dafeu: goto P_0c03dafe;
case 0x0c03db00u: goto P_0c03db00;
case 0x0c03db02u: goto P_0c03db02;
case 0x0c03db04u: goto P_0c03db04;
case 0x0c03db06u: goto P_0c03db06;
case 0x0c03db08u: goto P_0c03db08;
case 0x0c03db10u: goto P_0c03db10;
case 0x0c03db12u: goto P_0c03db12;
case 0x0c03db14u: goto P_0c03db14;
case 0x0c03db16u: goto P_0c03db16;
case 0x0c03db18u: goto P_0c03db18;
case 0x0c03db1au: goto P_0c03db1a;
case 0x0c03db1cu: goto P_0c03db1c;
case 0x0c03db1eu: goto P_0c03db1e;
case 0x0c03db20u: goto P_0c03db20;
case 0x0c03db22u: goto P_0c03db22;
case 0x0c03db24u: goto P_0c03db24;
case 0x0c03db26u: goto P_0c03db26;
case 0x0c03db28u: goto P_0c03db28;
case 0x0c03db2au: goto P_0c03db2a;
case 0x0c03db2cu: goto P_0c03db2c;
case 0x0c03db2eu: goto P_0c03db2e;
case 0x0c03db30u: goto P_0c03db30;
case 0x0c03db32u: goto P_0c03db32;
case 0x0c03db34u: goto P_0c03db34;
case 0x0c03db36u: goto P_0c03db36;
case 0x0c03db38u: goto P_0c03db38;
case 0x0c03db40u: goto P_0c03db40;
case 0x0c03db42u: goto P_0c03db42;
case 0x0c03db44u: goto P_0c03db44;
case 0x0c03db46u: goto P_0c03db46;
case 0x0c03db48u: goto P_0c03db48;
case 0x0c03db4au: goto P_0c03db4a;
case 0x0c03db4cu: goto P_0c03db4c;
case 0x0c03db4eu: goto P_0c03db4e;
case 0x0c03db50u: goto P_0c03db50;
case 0x0c03db52u: goto P_0c03db52;
case 0x0c03db54u: goto P_0c03db54;
case 0x0c03db56u: goto P_0c03db56;
case 0x0c03db58u: goto P_0c03db58;
case 0x0c03db5au: goto P_0c03db5a;
case 0x0c03db5cu: goto P_0c03db5c;
case 0x0c03db5eu: goto P_0c03db5e;
case 0x0c03db60u: goto P_0c03db60;
case 0x0c03db62u: goto P_0c03db62;
case 0x0c03db64u: goto P_0c03db64;
case 0x0c03db66u: goto P_0c03db66;
case 0x0c03db68u: goto P_0c03db68;
case 0x0c03db6au: goto P_0c03db6a;
case 0x0c03db6cu: goto P_0c03db6c;
case 0x0c03db6eu: goto P_0c03db6e;
case 0x0c03db70u: goto P_0c03db70;
case 0x0c03db72u: goto P_0c03db72;
case 0x0c03db74u: goto P_0c03db74;
case 0x0c03db76u: goto P_0c03db76;
case 0x0c03db78u: goto P_0c03db78;
case 0x0c03db7au: goto P_0c03db7a;
case 0x0c03db7cu: goto P_0c03db7c;
case 0x0c03db80u: goto P_0c03db80;
case 0x0c03db82u: goto P_0c03db82;
case 0x0c03db84u: goto P_0c03db84;
case 0x0c03db86u: goto P_0c03db86;
case 0x0c03db88u: goto P_0c03db88;
case 0x0c03db8au: goto P_0c03db8a;
case 0x0c03db8cu: goto P_0c03db8c;
case 0x0c03db8eu: goto P_0c03db8e;
case 0x0c03db90u: goto P_0c03db90;
case 0x0c03db92u: goto P_0c03db92;
case 0x0c03db94u: goto P_0c03db94;
case 0x0c03db96u: goto P_0c03db96;
case 0x0c03db98u: goto P_0c03db98;
case 0x0c03db9au: goto P_0c03db9a;
case 0x0c03db9cu: goto P_0c03db9c;
case 0x0c03db9eu: goto P_0c03db9e;
case 0x0c03dba0u: goto P_0c03dba0;
case 0x0c03dba2u: goto P_0c03dba2;
case 0x0c03ea22u: goto P_0c03ea22;
case 0x0c03ea24u: goto P_0c03ea24;
case 0x0c03ea26u: goto P_0c03ea26;
case 0x0c03ea28u: goto P_0c03ea28;
case 0x0c03ea2au: goto P_0c03ea2a;
case 0x0c03ea2cu: goto P_0c03ea2c;
case 0x0c03ea2eu: goto P_0c03ea2e;
case 0x0c03ea30u: goto P_0c03ea30;
case 0x0c03ea32u: goto P_0c03ea32;
case 0x0c03ea34u: goto P_0c03ea34;
case 0x0c03ea36u: goto P_0c03ea36;
case 0x0c03ea38u: goto P_0c03ea38;
case 0x0c03ea3au: goto P_0c03ea3a;
case 0x0c03ea3cu: goto P_0c03ea3c;
case 0x0c03ea3eu: goto P_0c03ea3e;
case 0x0c03ea40u: goto P_0c03ea40;
case 0x0c03ea42u: goto P_0c03ea42;
case 0x0c03ea44u: goto P_0c03ea44;
case 0x0c03ea46u: goto P_0c03ea46;
case 0x0c03ea48u: goto P_0c03ea48;
case 0x0c03ea4au: goto P_0c03ea4a;
case 0x0c03ea4cu: goto P_0c03ea4c;
case 0x0c03ea4eu: goto P_0c03ea4e;
case 0x0c03ea50u: goto P_0c03ea50;
case 0x0c03ea52u: goto P_0c03ea52;
case 0x0c03ea54u: goto P_0c03ea54;
case 0x0c03ea56u: goto P_0c03ea56;
case 0x0c03ea58u: goto P_0c03ea58;
case 0x0c03ea5au: goto P_0c03ea5a;
case 0x0c03ea5cu: goto P_0c03ea5c;
case 0x0c03ea5eu: goto P_0c03ea5e;
case 0x0c03ea60u: goto P_0c03ea60;
case 0x0c03ea62u: goto P_0c03ea62;
case 0x0c03ea64u: goto P_0c03ea64;
case 0x0c03ea66u: goto P_0c03ea66;
case 0x0c03ea68u: goto P_0c03ea68;
case 0x0c03ea6au: goto P_0c03ea6a;
case 0x0c03ea6cu: goto P_0c03ea6c;
case 0x0c03ea6eu: goto P_0c03ea6e;
case 0x0c03ea70u: goto P_0c03ea70;
case 0x0c03ea72u: goto P_0c03ea72;
case 0x0c03ea74u: goto P_0c03ea74;
case 0x0c03ea76u: goto P_0c03ea76;
case 0x0c03ea78u: goto P_0c03ea78;
case 0x0c03ea7au: goto P_0c03ea7a;
case 0x0c03ea7cu: goto P_0c03ea7c;
case 0x0c03ea7eu: goto P_0c03ea7e;
case 0x0c03ea80u: goto P_0c03ea80;
case 0x0c03ea82u: goto P_0c03ea82;
case 0x0c03ea84u: goto P_0c03ea84;
case 0x0c03ea86u: goto P_0c03ea86;
case 0x0c03ea88u: goto P_0c03ea88;
case 0x0c03ea8au: goto P_0c03ea8a;
case 0x0c03ea8cu: goto P_0c03ea8c;
case 0x0c03ea8eu: goto P_0c03ea8e;
case 0x0c03ea90u: goto P_0c03ea90;
case 0x0c03ea92u: goto P_0c03ea92;
case 0x0c03ea94u: goto P_0c03ea94;
case 0x0c03ea96u: goto P_0c03ea96;
case 0x0c03ea98u: goto P_0c03ea98;
case 0x0c03ea9au: goto P_0c03ea9a;
case 0x0c03ea9cu: goto P_0c03ea9c;
case 0x0c03ea9eu: goto P_0c03ea9e;
case 0x0c03eaa0u: goto P_0c03eaa0;
case 0x0c03eaa2u: goto P_0c03eaa2;
case 0x0c03eaa4u: goto P_0c03eaa4;
case 0x0c03eaa6u: goto P_0c03eaa6;
case 0x0c03eaa8u: goto P_0c03eaa8;
case 0x0c03eaaau: goto P_0c03eaaa;
case 0x0c03eaacu: goto P_0c03eaac;
case 0x0c03eaaeu: goto P_0c03eaae;
case 0x0c03eab0u: goto P_0c03eab0;
case 0x0c03eab2u: goto P_0c03eab2;
case 0x0c03eab4u: goto P_0c03eab4;
case 0x0c03eab6u: goto P_0c03eab6;
case 0x0c03eab8u: goto P_0c03eab8;
case 0x0c03eabau: goto P_0c03eaba;
case 0x0c03eabcu: goto P_0c03eabc;
case 0x0c03eabeu: goto P_0c03eabe;
case 0x0c03eac0u: goto P_0c03eac0;
case 0x0c03eac2u: goto P_0c03eac2;
case 0x0c03eac4u: goto P_0c03eac4;
case 0x0c03eac6u: goto P_0c03eac6;
case 0x0c03eac8u: goto P_0c03eac8;
case 0x0c03eacau: goto P_0c03eaca;
case 0x0c03eaccu: goto P_0c03eacc;
case 0x0c03eaceu: goto P_0c03eace;
case 0x0c04baf6u: goto P_0c04baf6;
case 0x0c04baf8u: goto P_0c04baf8;
case 0x0c04bafau: goto P_0c04bafa;
case 0x0c04bafcu: goto P_0c04bafc;
case 0x0c04bafeu: goto P_0c04bafe;
case 0x0c04bb00u: goto P_0c04bb00;
case 0x0c04bb02u: goto P_0c04bb02;
case 0x0c04bb04u: goto P_0c04bb04;
case 0x0c04bb06u: goto P_0c04bb06;
case 0x0c04bb08u: goto P_0c04bb08;
case 0x0c04bb0au: goto P_0c04bb0a;
case 0x0c04bb0cu: goto P_0c04bb0c;
case 0x0c04bb0eu: goto P_0c04bb0e;
case 0x0c04bb10u: goto P_0c04bb10;
case 0x0c04bb12u: goto P_0c04bb12;
case 0x0c04bb14u: goto P_0c04bb14;
case 0x0c04bb16u: goto P_0c04bb16;
case 0x0c04bb18u: goto P_0c04bb18;
case 0x0c04bb1au: goto P_0c04bb1a;
case 0x0c04bb1cu: goto P_0c04bb1c;
case 0x0c04bb1eu: goto P_0c04bb1e;
case 0x0c04bb20u: goto P_0c04bb20;
case 0x0c04bb22u: goto P_0c04bb22;
case 0x0c04bb24u: goto P_0c04bb24;
case 0x0c04bb26u: goto P_0c04bb26;
case 0x0c04bb28u: goto P_0c04bb28;
case 0x0c04bb58u: goto P_0c04bb58;
case 0x0c04bb5au: goto P_0c04bb5a;
case 0x0c04bb5cu: goto P_0c04bb5c;
case 0x0c04bb5eu: goto P_0c04bb5e;
case 0x0c04bb60u: goto P_0c04bb60;
case 0x0c04bb62u: goto P_0c04bb62;
case 0x0c04bb64u: goto P_0c04bb64;
case 0x0c04bb66u: goto P_0c04bb66;
case 0x0c04bb68u: goto P_0c04bb68;
case 0x0c04bb6au: goto P_0c04bb6a;
case 0x0c04bb6cu: goto P_0c04bb6c;
case 0x0c04bb6eu: goto P_0c04bb6e;
case 0x0c04bb70u: goto P_0c04bb70;
case 0x0c04bb72u: goto P_0c04bb72;
case 0x0c04bb74u: goto P_0c04bb74;
case 0x0c04bb76u: goto P_0c04bb76;
case 0x0c04bb78u: goto P_0c04bb78;
case 0x0c04bb7au: goto P_0c04bb7a;
case 0x0c04bb7cu: goto P_0c04bb7c;
case 0x0c04bb7eu: goto P_0c04bb7e;
case 0x0c04bb80u: goto P_0c04bb80;
case 0x0c04bb82u: goto P_0c04bb82;
case 0x0c04bb84u: goto P_0c04bb84;
case 0x0c04bb86u: goto P_0c04bb86;
case 0x0c04bb88u: goto P_0c04bb88;
case 0x0c04bb8au: goto P_0c04bb8a;
case 0x0c04bb8cu: goto P_0c04bb8c;
case 0x0c04bb8eu: goto P_0c04bb8e;
case 0x0c04bb90u: goto P_0c04bb90;
case 0x0c04bb92u: goto P_0c04bb92;
case 0x0c04bb94u: goto P_0c04bb94;
case 0x0c04bb96u: goto P_0c04bb96;
case 0x0c04bb98u: goto P_0c04bb98;
case 0x0c04bb9au: goto P_0c04bb9a;
case 0x0c04bb9cu: goto P_0c04bb9c;
case 0x0c04bb9eu: goto P_0c04bb9e;
case 0x0c04bba0u: goto P_0c04bba0;
case 0x0c04bba2u: goto P_0c04bba2;
case 0x0c04bba4u: goto P_0c04bba4;
case 0x0c04bba6u: goto P_0c04bba6;
case 0x0c04bba8u: goto P_0c04bba8;
case 0x0c04bbaau: goto P_0c04bbaa;
case 0x0c04bbacu: goto P_0c04bbac;
case 0x0c04bbaeu: goto P_0c04bbae;
case 0x0c04bbb0u: goto P_0c04bbb0;
case 0x0c04bbb2u: goto P_0c04bbb2;
case 0x0c04bbb4u: goto P_0c04bbb4;
case 0x0c04bbb6u: goto P_0c04bbb6;
case 0x0c04bbb8u: goto P_0c04bbb8;
case 0x0c04bbbau: goto P_0c04bbba;
case 0x0c04bbbcu: goto P_0c04bbbc;
case 0x0c04bbbeu: goto P_0c04bbbe;
case 0x0c04bbc0u: goto P_0c04bbc0;
case 0x0c04bbc2u: goto P_0c04bbc2;
case 0x0c04bbc4u: goto P_0c04bbc4;
case 0x0c05e46cu: goto P_0c05e46c;
case 0x0c05e46eu: goto P_0c05e46e;
case 0x0c05e470u: goto P_0c05e470;
case 0x0c05e472u: goto P_0c05e472;
case 0x0c05e474u: goto P_0c05e474;
case 0x0c05e476u: goto P_0c05e476;
case 0x0c05e478u: goto P_0c05e478;
case 0x0c05e47au: goto P_0c05e47a;
case 0x0c05e47cu: goto P_0c05e47c;
case 0x0c05e47eu: goto P_0c05e47e;
case 0x0c05e480u: goto P_0c05e480;
case 0x0c05e482u: goto P_0c05e482;
case 0x0c05e484u: goto P_0c05e484;
case 0x0c05e486u: goto P_0c05e486;
case 0x0c05e488u: goto P_0c05e488;
case 0x0c05e48au: goto P_0c05e48a;
case 0x0c05e48cu: goto P_0c05e48c;
case 0x0c05e48eu: goto P_0c05e48e;
case 0x0c05e490u: goto P_0c05e490;
case 0x0c05e492u: goto P_0c05e492;
case 0x0c05e494u: goto P_0c05e494;
case 0x0c05e496u: goto P_0c05e496;
case 0x0c05e498u: goto P_0c05e498;
case 0x0c05e49au: goto P_0c05e49a;
case 0x0c05e49cu: goto P_0c05e49c;
case 0x0c05e49eu: goto P_0c05e49e;
case 0x0c05e4a0u: goto P_0c05e4a0;
case 0x0c05e4a2u: goto P_0c05e4a2;
case 0x0c05e4a4u: goto P_0c05e4a4;
case 0x0c05e4a6u: goto P_0c05e4a6;
case 0x0c05e4a8u: goto P_0c05e4a8;
case 0x0c05e4aau: goto P_0c05e4aa;
case 0x0c05e4acu: goto P_0c05e4ac;
case 0x0c05e4aeu: goto P_0c05e4ae;
case 0x0c05e4b0u: goto P_0c05e4b0;
case 0x0c05e4b2u: goto P_0c05e4b2;
case 0x0c05e4b4u: goto P_0c05e4b4;
case 0x0c05e4b6u: goto P_0c05e4b6;
case 0x0c05e4b8u: goto P_0c05e4b8;
case 0x0c05e4bau: goto P_0c05e4ba;
case 0x0c05e4bcu: goto P_0c05e4bc;
case 0x0c05e4beu: goto P_0c05e4be;
case 0x0c05e4c0u: goto P_0c05e4c0;
case 0x0c05e4c2u: goto P_0c05e4c2;
case 0x0c05e4c4u: goto P_0c05e4c4;
case 0x0c05e4c6u: goto P_0c05e4c6;
case 0x0c06c406u: goto P_0c06c406;
case 0x0c06c408u: goto P_0c06c408;
case 0x0c06c40au: goto P_0c06c40a;
case 0x0c06c40cu: goto P_0c06c40c;
case 0x0c06c40eu: goto P_0c06c40e;
case 0x0c06c410u: goto P_0c06c410;
case 0x0c06c412u: goto P_0c06c412;
case 0x0c06c414u: goto P_0c06c414;
case 0x0c06c416u: goto P_0c06c416;
case 0x0c06c418u: goto P_0c06c418;
case 0x0c06c41au: goto P_0c06c41a;
case 0x0c06c41cu: goto P_0c06c41c;
case 0x0c06c41eu: goto P_0c06c41e;
case 0x0c06c420u: goto P_0c06c420;
case 0x0c06c6d6u: goto P_0c06c6d6;
case 0x0c06c6d8u: goto P_0c06c6d8;
case 0x0c06c6dau: goto P_0c06c6da;
case 0x0c06c6dcu: goto P_0c06c6dc;
case 0x0c06c6deu: goto P_0c06c6de;
case 0x0c06c720u: goto P_0c06c720;
case 0x0c06c722u: goto P_0c06c722;
case 0x0c06c724u: goto P_0c06c724;
case 0x0c06c726u: goto P_0c06c726;
case 0x0c06c728u: goto P_0c06c728;
case 0x0c06c72au: goto P_0c06c72a;
case 0x0c06c72cu: goto P_0c06c72c;
case 0x0c06c72eu: goto P_0c06c72e;
case 0x0c06c730u: goto P_0c06c730;
case 0x0c06c732u: goto P_0c06c732;
case 0x0c06c734u: goto P_0c06c734;
case 0x0c06c736u: goto P_0c06c736;
case 0x0c06c738u: goto P_0c06c738;
case 0x0c06c73au: goto P_0c06c73a;
case 0x0c06c73cu: goto P_0c06c73c;
case 0x0c06c73eu: goto P_0c06c73e;
case 0x0c06c740u: goto P_0c06c740;
case 0x0c06c742u: goto P_0c06c742;
case 0x0c06c744u: goto P_0c06c744;
case 0x0c06c746u: goto P_0c06c746;
case 0x0c06c748u: goto P_0c06c748;
case 0x0c06c74au: goto P_0c06c74a;
case 0x0c06c74cu: goto P_0c06c74c;
case 0x0c06c74eu: goto P_0c06c74e;
case 0x0c06c750u: goto P_0c06c750;
case 0x0c06c752u: goto P_0c06c752;
case 0x0c06c754u: goto P_0c06c754;
case 0x0c06c756u: goto P_0c06c756;
case 0x0c06c758u: goto P_0c06c758;
case 0x0c06c75au: goto P_0c06c75a;
case 0x0c06c75cu: goto P_0c06c75c;
case 0x0c06c75eu: goto P_0c06c75e;
case 0x0c06c760u: goto P_0c06c760;
case 0x0c06c762u: goto P_0c06c762;
case 0x0c06c764u: goto P_0c06c764;
case 0x0c06c766u: goto P_0c06c766;
case 0x0c06c768u: goto P_0c06c768;
case 0x0c06c76au: goto P_0c06c76a;
case 0x0c06c76cu: goto P_0c06c76c;
case 0x0c06c76eu: goto P_0c06c76e;
case 0x0c06c770u: goto P_0c06c770;
case 0x0c06c772u: goto P_0c06c772;
case 0x0c06c774u: goto P_0c06c774;
case 0x0c06c776u: goto P_0c06c776;
case 0x0c06c778u: goto P_0c06c778;
case 0x0c06c77au: goto P_0c06c77a;
case 0x0c06c77cu: goto P_0c06c77c;
case 0x0c06c77eu: goto P_0c06c77e;
case 0x0c06c780u: goto P_0c06c780;
case 0x0c06c782u: goto P_0c06c782;
case 0x0c06c784u: goto P_0c06c784;
case 0x0c06c786u: goto P_0c06c786;
case 0x0c06c788u: goto P_0c06c788;
case 0x0c06c78au: goto P_0c06c78a;
case 0x0c06c78cu: goto P_0c06c78c;
case 0x0c06c78eu: goto P_0c06c78e;
case 0x0c06c790u: goto P_0c06c790;
case 0x0c06c792u: goto P_0c06c792;
case 0x0c06c794u: goto P_0c06c794;
case 0x0c06c796u: goto P_0c06c796;
case 0x0c06c798u: goto P_0c06c798;
case 0x0c06c79au: goto P_0c06c79a;
case 0x0c06c79cu: goto P_0c06c79c;
case 0x0c06c79eu: goto P_0c06c79e;
case 0x0c06c7a0u: goto P_0c06c7a0;
case 0x0c06c7a2u: goto P_0c06c7a2;
case 0x0c06c7a4u: goto P_0c06c7a4;
case 0x0c06c7a6u: goto P_0c06c7a6;
case 0x0c06c7a8u: goto P_0c06c7a8;
case 0x0c06c7aau: goto P_0c06c7aa;
case 0x0c06c7acu: goto P_0c06c7ac;
case 0x0c06c7aeu: goto P_0c06c7ae;
case 0x0c06c7b0u: goto P_0c06c7b0;
case 0x0c06c7b2u: goto P_0c06c7b2;
case 0x0c06c7b4u: goto P_0c06c7b4;
case 0x0c06c7b6u: goto P_0c06c7b6;
case 0x0c06c7b8u: goto P_0c06c7b8;
case 0x0c06c7bau: goto P_0c06c7ba;
case 0x0c06c7bcu: goto P_0c06c7bc;
case 0x0c06c7beu: goto P_0c06c7be;
case 0x0c06c7c0u: goto P_0c06c7c0;
case 0x0c06c7c2u: goto P_0c06c7c2;
case 0x0c06c7c4u: goto P_0c06c7c4;
case 0x0c06c7c6u: goto P_0c06c7c6;
case 0x0c06c7c8u: goto P_0c06c7c8;
case 0x0c06c7cau: goto P_0c06c7ca;
case 0x0c06c7e4u: goto P_0c06c7e4;
case 0x0c06c7e6u: goto P_0c06c7e6;
case 0x0c06c7e8u: goto P_0c06c7e8;
case 0x0c06c7eau: goto P_0c06c7ea;
case 0x0c06c7ecu: goto P_0c06c7ec;
case 0x0c06c7eeu: goto P_0c06c7ee;
case 0x0c06c7f0u: goto P_0c06c7f0;
case 0x0c06c7f2u: goto P_0c06c7f2;
case 0x0c06c7f4u: goto P_0c06c7f4;
case 0x0c06c7f6u: goto P_0c06c7f6;
case 0x0c06c7f8u: goto P_0c06c7f8;
case 0x0c06c7fau: goto P_0c06c7fa;
case 0x0c06c7fcu: goto P_0c06c7fc;
case 0x0c06c7feu: goto P_0c06c7fe;
case 0x0c06c800u: goto P_0c06c800;
case 0x0c06c802u: goto P_0c06c802;
case 0x0c06c804u: goto P_0c06c804;
case 0x0c06c806u: goto P_0c06c806;
case 0x0c06c808u: goto P_0c06c808;
case 0x0c06c80au: goto P_0c06c80a;
case 0x0c06c80cu: goto P_0c06c80c;
case 0x0c06c80eu: goto P_0c06c80e;
case 0x0c06c810u: goto P_0c06c810;
case 0x0c06c812u: goto P_0c06c812;
case 0x0c06c814u: goto P_0c06c814;
case 0x0c06c816u: goto P_0c06c816;
case 0x0c06c818u: goto P_0c06c818;
case 0x0c06c81au: goto P_0c06c81a;
case 0x0c06c81cu: goto P_0c06c81c;
case 0x0c06c81eu: goto P_0c06c81e;
case 0x0c06c820u: goto P_0c06c820;
case 0x0c06c822u: goto P_0c06c822;
case 0x0c06c824u: goto P_0c06c824;
case 0x0c06c826u: goto P_0c06c826;
case 0x0c06c828u: goto P_0c06c828;
case 0x0c06c82au: goto P_0c06c82a;
case 0x0c06c82cu: goto P_0c06c82c;
case 0x0c06c82eu: goto P_0c06c82e;
case 0x0c06c830u: goto P_0c06c830;
case 0x0c06c832u: goto P_0c06c832;
case 0x0c06c834u: goto P_0c06c834;
case 0x0c06c836u: goto P_0c06c836;
case 0x0c06c838u: goto P_0c06c838;
case 0x0c06c83au: goto P_0c06c83a;
case 0x0c06c83cu: goto P_0c06c83c;
case 0x0c06c83eu: goto P_0c06c83e;
case 0x0c06c840u: goto P_0c06c840;
case 0x0c06c842u: goto P_0c06c842;
case 0x0c06c844u: goto P_0c06c844;
case 0x0c06c846u: goto P_0c06c846;
case 0x0c06c848u: goto P_0c06c848;
case 0x0c06c84au: goto P_0c06c84a;
case 0x0c06c84cu: goto P_0c06c84c;
case 0x0c06c84eu: goto P_0c06c84e;
case 0x0c06c850u: goto P_0c06c850;
case 0x0c06c852u: goto P_0c06c852;
case 0x0c06c854u: goto P_0c06c854;
case 0x0c06c856u: goto P_0c06c856;
case 0x0c06c858u: goto P_0c06c858;
case 0x0c06c85au: goto P_0c06c85a;
case 0x0c06c85cu: goto P_0c06c85c;
case 0x0c06c85eu: goto P_0c06c85e;
case 0x0c06c860u: goto P_0c06c860;
case 0x0c06c862u: goto P_0c06c862;
case 0x0c06c864u: goto P_0c06c864;
case 0x0c06c866u: goto P_0c06c866;
case 0x0c06c868u: goto P_0c06c868;
case 0x0c06c86au: goto P_0c06c86a;
case 0x0c06c86cu: goto P_0c06c86c;
case 0x0c06c86eu: goto P_0c06c86e;
case 0x0c06c870u: goto P_0c06c870;
case 0x0c06c872u: goto P_0c06c872;
case 0x0c06c874u: goto P_0c06c874;
case 0x0c06c876u: goto P_0c06c876;
case 0x0c06c878u: goto P_0c06c878;
case 0x0c06c87au: goto P_0c06c87a;
case 0x0c06c87cu: goto P_0c06c87c;
case 0x0c06c87eu: goto P_0c06c87e;
case 0x0c06c880u: goto P_0c06c880;
case 0x0c06c882u: goto P_0c06c882;
case 0x0c06c884u: goto P_0c06c884;
case 0x0c06c886u: goto P_0c06c886;
case 0x0c06c888u: goto P_0c06c888;
case 0x0c06c88au: goto P_0c06c88a;
case 0x0c06c88cu: goto P_0c06c88c;
case 0x0c06c88eu: goto P_0c06c88e;
case 0x0c06c890u: goto P_0c06c890;
case 0x0c06c892u: goto P_0c06c892;
case 0x0c06c894u: goto P_0c06c894;
case 0x0c06c896u: goto P_0c06c896;
case 0x0c06c898u: goto P_0c06c898;
case 0x0c06c89au: goto P_0c06c89a;
case 0x0c06c89cu: goto P_0c06c89c;
case 0x0c06c89eu: goto P_0c06c89e;
case 0x0c06c8a0u: goto P_0c06c8a0;
case 0x0c06c8a2u: goto P_0c06c8a2;
case 0x0c06c95eu: goto P_0c06c95e;
case 0x0c06c960u: goto P_0c06c960;
case 0x0c06c962u: goto P_0c06c962;
case 0x0c06c964u: goto P_0c06c964;
case 0x0c06c966u: goto P_0c06c966;
case 0x0c06c968u: goto P_0c06c968;
case 0x0c06c96au: goto P_0c06c96a;
case 0x0c06c96cu: goto P_0c06c96c;
case 0x0c06c96eu: goto P_0c06c96e;
case 0x0c06c970u: goto P_0c06c970;
case 0x0c06c972u: goto P_0c06c972;
case 0x0c06c974u: goto P_0c06c974;
case 0x0c06c976u: goto P_0c06c976;
case 0x0c06c978u: goto P_0c06c978;
case 0x0c06c97au: goto P_0c06c97a;
case 0x0c06c97cu: goto P_0c06c97c;
case 0x0c06c97eu: goto P_0c06c97e;
case 0x0c06c980u: goto P_0c06c980;
case 0x0c06c982u: goto P_0c06c982;
case 0x0c06c984u: goto P_0c06c984;
case 0x0c06c986u: goto P_0c06c986;
case 0x0c06c988u: goto P_0c06c988;
case 0x0c06c98au: goto P_0c06c98a;
case 0x0c06c98cu: goto P_0c06c98c;
case 0x0c06c98eu: goto P_0c06c98e;
case 0x0c06c990u: goto P_0c06c990;
case 0x0c06c992u: goto P_0c06c992;
case 0x0c06c994u: goto P_0c06c994;
case 0x0c06c996u: goto P_0c06c996;
case 0x0c06c998u: goto P_0c06c998;
case 0x0c06c99au: goto P_0c06c99a;
case 0x0c06c99cu: goto P_0c06c99c;
case 0x0c06c99eu: goto P_0c06c99e;
case 0x0c06c9a0u: goto P_0c06c9a0;
case 0x0c06c9a2u: goto P_0c06c9a2;
case 0x0c06c9a4u: goto P_0c06c9a4;
case 0x0c06c9a6u: goto P_0c06c9a6;
case 0x0c06c9a8u: goto P_0c06c9a8;
case 0x0c06c9aau: goto P_0c06c9aa;
case 0x0c06c9acu: goto P_0c06c9ac;
case 0x0c06c9aeu: goto P_0c06c9ae;
case 0x0c06c9b0u: goto P_0c06c9b0;
case 0x0c06c9b2u: goto P_0c06c9b2;
case 0x0c06c9b4u: goto P_0c06c9b4;
case 0x0c06c9b6u: goto P_0c06c9b6;
case 0x0c06c9b8u: goto P_0c06c9b8;
case 0x0c06c9bau: goto P_0c06c9ba;
case 0x0c06c9bcu: goto P_0c06c9bc;
case 0x0c06c9beu: goto P_0c06c9be;
case 0x0c06c9c0u: goto P_0c06c9c0;
case 0x0c06c9c2u: goto P_0c06c9c2;
case 0x0c06c9c4u: goto P_0c06c9c4;
case 0x0c06c9c6u: goto P_0c06c9c6;
case 0x0c06c9c8u: goto P_0c06c9c8;
case 0x0c06c9cau: goto P_0c06c9ca;
case 0x0c06c9ccu: goto P_0c06c9cc;
case 0x0c06c9ceu: goto P_0c06c9ce;
case 0x0c06c9d0u: goto P_0c06c9d0;
case 0x0c06c9d2u: goto P_0c06c9d2;
case 0x0c06c9d4u: goto P_0c06c9d4;
case 0x0c06c9d6u: goto P_0c06c9d6;
case 0x0c06c9d8u: goto P_0c06c9d8;
case 0x0c06c9dau: goto P_0c06c9da;
case 0x0c06c9dcu: goto P_0c06c9dc;
case 0x0c06c9deu: goto P_0c06c9de;
case 0x0c06c9e0u: goto P_0c06c9e0;
case 0x0c06c9e2u: goto P_0c06c9e2;
case 0x0c06c9e4u: goto P_0c06c9e4;
case 0x0c06c9e6u: goto P_0c06c9e6;
case 0x0c06c9e8u: goto P_0c06c9e8;
case 0x0c06c9eau: goto P_0c06c9ea;
case 0x0c06c9ecu: goto P_0c06c9ec;
case 0x0c06c9eeu: goto P_0c06c9ee;
case 0x0c06c9f0u: goto P_0c06c9f0;
case 0x0c06c9f2u: goto P_0c06c9f2;
case 0x0c06c9f4u: goto P_0c06c9f4;
case 0x0c06c9f6u: goto P_0c06c9f6;
case 0x0c06ca30u: goto P_0c06ca30;
case 0x0c06ca32u: goto P_0c06ca32;
case 0x0c06ca34u: goto P_0c06ca34;
case 0x0c06ca36u: goto P_0c06ca36;
case 0x0c06ca38u: goto P_0c06ca38;
case 0x0c06ca3au: goto P_0c06ca3a;
case 0x0c06ca3cu: goto P_0c06ca3c;
case 0x0c06ca3eu: goto P_0c06ca3e;
case 0x0c06ca40u: goto P_0c06ca40;
case 0x0c06ca42u: goto P_0c06ca42;
case 0x0c06ca44u: goto P_0c06ca44;
case 0x0c06ca46u: goto P_0c06ca46;
case 0x0c06ca48u: goto P_0c06ca48;
case 0x0c06ca4au: goto P_0c06ca4a;
case 0x0c06ca4cu: goto P_0c06ca4c;
case 0x0c06ca4eu: goto P_0c06ca4e;
case 0x0c06ca50u: goto P_0c06ca50;
case 0x0c06ca52u: goto P_0c06ca52;
case 0x0c06ca54u: goto P_0c06ca54;
case 0x0c06ca56u: goto P_0c06ca56;
case 0x0c06ca58u: goto P_0c06ca58;
case 0x0c06ca5au: goto P_0c06ca5a;
case 0x0c06ca5cu: goto P_0c06ca5c;
case 0x0c06ca5eu: goto P_0c06ca5e;
case 0x0c06ca60u: goto P_0c06ca60;
case 0x0c06ca62u: goto P_0c06ca62;
case 0x0c06ca64u: goto P_0c06ca64;
case 0x0c06ca66u: goto P_0c06ca66;
case 0x0c06ca68u: goto P_0c06ca68;
case 0x0c06ca6au: goto P_0c06ca6a;
case 0x0c06ca6cu: goto P_0c06ca6c;
case 0x0c06ca6eu: goto P_0c06ca6e;
case 0x0c06ca70u: goto P_0c06ca70;
case 0x0c06ca72u: goto P_0c06ca72;
case 0x0c06ca74u: goto P_0c06ca74;
case 0x0c06ca76u: goto P_0c06ca76;
case 0x0c06ca78u: goto P_0c06ca78;
case 0x0c06ca7au: goto P_0c06ca7a;
case 0x0c06ca7cu: goto P_0c06ca7c;
case 0x0c06ca7eu: goto P_0c06ca7e;
case 0x0c06ca80u: goto P_0c06ca80;
case 0x0c06ca82u: goto P_0c06ca82;
case 0x0c06ca84u: goto P_0c06ca84;
case 0x0c06ca86u: goto P_0c06ca86;
case 0x0c06ca88u: goto P_0c06ca88;
case 0x0c06ca8au: goto P_0c06ca8a;
case 0x0c06ca8cu: goto P_0c06ca8c;
case 0x0c06ca8eu: goto P_0c06ca8e;
case 0x0c06ca90u: goto P_0c06ca90;
case 0x0c06ca92u: goto P_0c06ca92;
case 0x0c06ca94u: goto P_0c06ca94;
case 0x0c06ca96u: goto P_0c06ca96;
case 0x0c06ca98u: goto P_0c06ca98;
case 0x0c06ca9au: goto P_0c06ca9a;
case 0x0c06ca9cu: goto P_0c06ca9c;
case 0x0c06ca9eu: goto P_0c06ca9e;
case 0x0c06caa0u: goto P_0c06caa0;
case 0x0c06caa2u: goto P_0c06caa2;
case 0x0c06caa4u: goto P_0c06caa4;
case 0x0c06caa6u: goto P_0c06caa6;
case 0x0c06caa8u: goto P_0c06caa8;
case 0x0c06caaau: goto P_0c06caaa;
case 0x0c06caacu: goto P_0c06caac;
case 0x0c06caaeu: goto P_0c06caae;
case 0x0c06cab0u: goto P_0c06cab0;
case 0x0c06cab2u: goto P_0c06cab2;
case 0x0c06cab4u: goto P_0c06cab4;
case 0x0c06cab6u: goto P_0c06cab6;
case 0x0c06cab8u: goto P_0c06cab8;
case 0x0c06cabau: goto P_0c06caba;
case 0x0c06cabcu: goto P_0c06cabc;
case 0x0c06cabeu: goto P_0c06cabe;
case 0x0c06cac0u: goto P_0c06cac0;
case 0x0c06cac2u: goto P_0c06cac2;
case 0x0c06cac4u: goto P_0c06cac4;
case 0x0c06cac6u: goto P_0c06cac6;
case 0x0c06cac8u: goto P_0c06cac8;
case 0x0c06cacau: goto P_0c06caca;
case 0x0c06caccu: goto P_0c06cacc;
case 0x0c06caceu: goto P_0c06cace;
case 0x0c06cad0u: goto P_0c06cad0;
case 0x0c06cad2u: goto P_0c06cad2;
case 0x0c06cad4u: goto P_0c06cad4;
case 0x0c06cad6u: goto P_0c06cad6;
case 0x0c06cad8u: goto P_0c06cad8;
case 0x0c06cadau: goto P_0c06cada;
case 0x0c06cadcu: goto P_0c06cadc;
case 0x0c06cadeu: goto P_0c06cade;
case 0x0c06cae0u: goto P_0c06cae0;
case 0x0c06cae2u: goto P_0c06cae2;
case 0x0c06cae4u: goto P_0c06cae4;
case 0x0c06cae6u: goto P_0c06cae6;
case 0x0c06cae8u: goto P_0c06cae8;
case 0x0c06caeau: goto P_0c06caea;
case 0x0c06caecu: goto P_0c06caec;
case 0x0c06caeeu: goto P_0c06caee;
case 0x0c06caf0u: goto P_0c06caf0;
case 0x0c06caf2u: goto P_0c06caf2;
case 0x0c06caf4u: goto P_0c06caf4;
case 0x0c06caf6u: goto P_0c06caf6;
case 0x0c06caf8u: goto P_0c06caf8;
case 0x0c06cafau: goto P_0c06cafa;
case 0x0c06cafcu: goto P_0c06cafc;
case 0x0c06cafeu: goto P_0c06cafe;
case 0x0c06cb00u: goto P_0c06cb00;
case 0x0c06cb02u: goto P_0c06cb02;
case 0x0c06cb04u: goto P_0c06cb04;
case 0x0c06cb06u: goto P_0c06cb06;
case 0x0c06cb08u: goto P_0c06cb08;
case 0x0c06cb0au: goto P_0c06cb0a;
case 0x0c06cb0cu: goto P_0c06cb0c;
case 0x0c06cb0eu: goto P_0c06cb0e;
case 0x0c06cb10u: goto P_0c06cb10;
case 0x0c06cb12u: goto P_0c06cb12;
case 0x0c06cb14u: goto P_0c06cb14;
case 0x0c06cb16u: goto P_0c06cb16;
case 0x0c06cb18u: goto P_0c06cb18;
case 0x0c06cb1au: goto P_0c06cb1a;
case 0x0c06cb1cu: goto P_0c06cb1c;
case 0x0c06cb1eu: goto P_0c06cb1e;
case 0x0c06cb20u: goto P_0c06cb20;
case 0x0c06cb22u: goto P_0c06cb22;
case 0x0c06cb24u: goto P_0c06cb24;
case 0x0c06cb26u: goto P_0c06cb26;
case 0x0c06cb28u: goto P_0c06cb28;
case 0x0c06cb2au: goto P_0c06cb2a;
case 0x0c06cb2cu: goto P_0c06cb2c;
case 0x0c06cb2eu: goto P_0c06cb2e;
case 0x0c06cb30u: goto P_0c06cb30;
case 0x0c06cb32u: goto P_0c06cb32;
case 0x0c06cb34u: goto P_0c06cb34;
case 0x0c06cb36u: goto P_0c06cb36;
case 0x0c06cb38u: goto P_0c06cb38;
case 0x0c06cb60u: goto P_0c06cb60;
case 0x0c06cb62u: goto P_0c06cb62;
case 0x0c06cb64u: goto P_0c06cb64;
case 0x0c06cb66u: goto P_0c06cb66;
case 0x0c06cb68u: goto P_0c06cb68;
case 0x0c06cb6au: goto P_0c06cb6a;
case 0x0c06cb6cu: goto P_0c06cb6c;
case 0x0c06cb6eu: goto P_0c06cb6e;
case 0x0c06cb70u: goto P_0c06cb70;
case 0x0c06cb72u: goto P_0c06cb72;
case 0x0c06cb74u: goto P_0c06cb74;
case 0x0c06cb76u: goto P_0c06cb76;
case 0x0c06cb78u: goto P_0c06cb78;
case 0x0c06cb7au: goto P_0c06cb7a;
case 0x0c06cb7cu: goto P_0c06cb7c;
case 0x0c06cb7eu: goto P_0c06cb7e;
case 0x0c06cb80u: goto P_0c06cb80;
case 0x0c06cb82u: goto P_0c06cb82;
case 0x0c06cb84u: goto P_0c06cb84;
case 0x0c06cb86u: goto P_0c06cb86;
case 0x0c06cb88u: goto P_0c06cb88;
case 0x0c06cb8au: goto P_0c06cb8a;
case 0x0c06cb8cu: goto P_0c06cb8c;
case 0x0c06cb8eu: goto P_0c06cb8e;
case 0x0c06cb90u: goto P_0c06cb90;
case 0x0c06cb92u: goto P_0c06cb92;
case 0x0c06cb94u: goto P_0c06cb94;
case 0x0c06cb96u: goto P_0c06cb96;
case 0x0c06cb98u: goto P_0c06cb98;
case 0x0c06cb9au: goto P_0c06cb9a;
case 0x0c06cb9cu: goto P_0c06cb9c;
case 0x0c06cb9eu: goto P_0c06cb9e;
case 0x0c06cba0u: goto P_0c06cba0;
case 0x0c06cba2u: goto P_0c06cba2;
case 0x0c06cba4u: goto P_0c06cba4;
case 0x0c06cba6u: goto P_0c06cba6;
case 0x0c06cba8u: goto P_0c06cba8;
case 0x0c06cbaau: goto P_0c06cbaa;
case 0x0c06cbacu: goto P_0c06cbac;
case 0x0c06cbaeu: goto P_0c06cbae;
case 0x0c06cbb0u: goto P_0c06cbb0;
case 0x0c06cbb2u: goto P_0c06cbb2;
case 0x0c06cbb4u: goto P_0c06cbb4;
case 0x0c06cbb6u: goto P_0c06cbb6;
case 0x0c06cbb8u: goto P_0c06cbb8;
case 0x0c06cbbau: goto P_0c06cbba;
case 0x0c06cbbcu: goto P_0c06cbbc;
case 0x0c06cbbeu: goto P_0c06cbbe;
case 0x0c06cbc0u: goto P_0c06cbc0;
case 0x0c06cbc2u: goto P_0c06cbc2;
case 0x0c06cbc4u: goto P_0c06cbc4;
case 0x0c06cbc6u: goto P_0c06cbc6;
case 0x0c06cbc8u: goto P_0c06cbc8;
case 0x0c06cbcau: goto P_0c06cbca;
case 0x0c06cbccu: goto P_0c06cbcc;
case 0x0c06cbceu: goto P_0c06cbce;
case 0x0c06cbd0u: goto P_0c06cbd0;
case 0x0c06cbd2u: goto P_0c06cbd2;
case 0x0c06cbd4u: goto P_0c06cbd4;
case 0x0c06cbd6u: goto P_0c06cbd6;
case 0x0c06cbd8u: goto P_0c06cbd8;
case 0x0c06cbdau: goto P_0c06cbda;
case 0x0c06cbdcu: goto P_0c06cbdc;
case 0x0c06cbdeu: goto P_0c06cbde;
case 0x0c06cbe0u: goto P_0c06cbe0;
case 0x0c06cbe2u: goto P_0c06cbe2;
case 0x0c06cbe4u: goto P_0c06cbe4;
case 0x0c06cbe6u: goto P_0c06cbe6;
case 0x0c06cbe8u: goto P_0c06cbe8;
case 0x0c06cbeau: goto P_0c06cbea;
case 0x0c06cbecu: goto P_0c06cbec;
case 0x0c06cbeeu: goto P_0c06cbee;
case 0x0c06cbf0u: goto P_0c06cbf0;
case 0x0c06cbf2u: goto P_0c06cbf2;
case 0x0c06cbf4u: goto P_0c06cbf4;
case 0x0c06cbf6u: goto P_0c06cbf6;
case 0x0c06cbf8u: goto P_0c06cbf8;
case 0x0c06cbfau: goto P_0c06cbfa;
case 0x0c06cbfcu: goto P_0c06cbfc;
case 0x0c06cbfeu: goto P_0c06cbfe;
case 0x0c06cc00u: goto P_0c06cc00;
case 0x0c06cc02u: goto P_0c06cc02;
case 0x0c06cc04u: goto P_0c06cc04;
case 0x0c06cc06u: goto P_0c06cc06;
case 0x0c06cc08u: goto P_0c06cc08;
case 0x0c06cc0au: goto P_0c06cc0a;
case 0x0c06cc0cu: goto P_0c06cc0c;
case 0x0c06cc0eu: goto P_0c06cc0e;
case 0x0c06cc10u: goto P_0c06cc10;
case 0x0c06cc12u: goto P_0c06cc12;
case 0x0c06cc14u: goto P_0c06cc14;
case 0x0c06cc16u: goto P_0c06cc16;
case 0x0c06cc18u: goto P_0c06cc18;
case 0x0c06cc1au: goto P_0c06cc1a;
case 0x0c06cc1cu: goto P_0c06cc1c;
case 0x0c085666u: goto P_0c085666;
case 0x0c085668u: goto P_0c085668;
case 0x0c08566au: goto P_0c08566a;
case 0x0c08566cu: goto P_0c08566c;
case 0x0c08566eu: goto P_0c08566e;
case 0x0c085670u: goto P_0c085670;
case 0x0c085672u: goto P_0c085672;
case 0x0c085674u: goto P_0c085674;
case 0x0c085676u: goto P_0c085676;
case 0x0c085678u: goto P_0c085678;
case 0x0c08567au: goto P_0c08567a;
case 0x0c08567cu: goto P_0c08567c;
case 0x0c08567eu: goto P_0c08567e;
case 0x0c085680u: goto P_0c085680;
case 0x0c085682u: goto P_0c085682;
case 0x0c085684u: goto P_0c085684;
case 0x0c085686u: goto P_0c085686;
case 0x0c085688u: goto P_0c085688;
case 0x0c08568au: goto P_0c08568a;
case 0x0c08568cu: goto P_0c08568c;
case 0x0c08568eu: goto P_0c08568e;
case 0x0c085690u: goto P_0c085690;
case 0x0c085692u: goto P_0c085692;
case 0x0c085694u: goto P_0c085694;
case 0x0c085696u: goto P_0c085696;
case 0x0c085698u: goto P_0c085698;
case 0x0c08569au: goto P_0c08569a;
case 0x0c08569cu: goto P_0c08569c;
case 0x0c08569eu: goto P_0c08569e;
case 0x0c0856a0u: goto P_0c0856a0;
case 0x0c0856a2u: goto P_0c0856a2;
case 0x0c0856a4u: goto P_0c0856a4;
case 0x0c0856a6u: goto P_0c0856a6;
case 0x0c0856a8u: goto P_0c0856a8;
case 0x0c0856aau: goto P_0c0856aa;
case 0x0c0856acu: goto P_0c0856ac;
case 0x0c0856aeu: goto P_0c0856ae;
case 0x0c0856b0u: goto P_0c0856b0;
case 0x0c0856b2u: goto P_0c0856b2;
case 0x0c0856b4u: goto P_0c0856b4;
case 0x0c0856b6u: goto P_0c0856b6;
case 0x0c0856b8u: goto P_0c0856b8;
case 0x0c0856bau: goto P_0c0856ba;
case 0x0c0856bcu: goto P_0c0856bc;
case 0x0c0856beu: goto P_0c0856be;
case 0x0c0856c0u: goto P_0c0856c0;
case 0x0c0856c2u: goto P_0c0856c2;
case 0x0c0856c4u: goto P_0c0856c4;
case 0x0c0856c6u: goto P_0c0856c6;
case 0x0c0856c8u: goto P_0c0856c8;
case 0x0c0856cau: goto P_0c0856ca;
case 0x0c0856ccu: goto P_0c0856cc;
case 0x0c0856ceu: goto P_0c0856ce;
case 0x0c0856d0u: goto P_0c0856d0;
case 0x0c0856d2u: goto P_0c0856d2;
case 0x0c0856d4u: goto P_0c0856d4;
case 0x0c0856d6u: goto P_0c0856d6;
case 0x0c0856d8u: goto P_0c0856d8;
case 0x0c0856dau: goto P_0c0856da;
case 0x0c0856dcu: goto P_0c0856dc;
case 0x0c0856deu: goto P_0c0856de;
case 0x0c0856e0u: goto P_0c0856e0;
case 0x0c0856e2u: goto P_0c0856e2;
case 0x0c0856e4u: goto P_0c0856e4;
case 0x0c0856e6u: goto P_0c0856e6;
case 0x0c0856e8u: goto P_0c0856e8;
case 0x0c0856eau: goto P_0c0856ea;
case 0x0c0856ecu: goto P_0c0856ec;
case 0x0c0856eeu: goto P_0c0856ee;
case 0x0c0856f0u: goto P_0c0856f0;
case 0x0c0856f2u: goto P_0c0856f2;
case 0x0c0856f4u: goto P_0c0856f4;
case 0x0c0856f6u: goto P_0c0856f6;
case 0x0c0856f8u: goto P_0c0856f8;
case 0x0c0856fau: goto P_0c0856fa;
case 0x0c0856fcu: goto P_0c0856fc;
case 0x0c0856feu: goto P_0c0856fe;
case 0x0c085700u: goto P_0c085700;
case 0x0c085702u: goto P_0c085702;
case 0x0c085704u: goto P_0c085704;
case 0x0c085706u: goto P_0c085706;
case 0x0c085708u: goto P_0c085708;
case 0x0c08570au: goto P_0c08570a;
case 0x0c08570cu: goto P_0c08570c;
case 0x0c08570eu: goto P_0c08570e;
case 0x0c085710u: goto P_0c085710;
case 0x0c085712u: goto P_0c085712;
case 0x0c085714u: goto P_0c085714;
case 0x0c085716u: goto P_0c085716;
case 0x0c085718u: goto P_0c085718;
case 0x0c08571au: goto P_0c08571a;
case 0x0c08571cu: goto P_0c08571c;
case 0x0c08571eu: goto P_0c08571e;
case 0x0c085720u: goto P_0c085720;
case 0x0c085722u: goto P_0c085722;
case 0x0c085724u: goto P_0c085724;
case 0x0c085726u: goto P_0c085726;
case 0x0c085728u: goto P_0c085728;
case 0x0c08572au: goto P_0c08572a;
case 0x0c08572cu: goto P_0c08572c;
case 0x0c08572eu: goto P_0c08572e;
case 0x0c085730u: goto P_0c085730;
case 0x0c085732u: goto P_0c085732;
case 0x0c085734u: goto P_0c085734;
case 0x0c085736u: goto P_0c085736;
case 0x0c085738u: goto P_0c085738;
case 0x0c08573au: goto P_0c08573a;
case 0x0c08573cu: goto P_0c08573c;
case 0x0c08573eu: goto P_0c08573e;
case 0x0c085740u: goto P_0c085740;
case 0x0c085742u: goto P_0c085742;
case 0x0c085744u: goto P_0c085744;
case 0x0c085746u: goto P_0c085746;
case 0x0c085748u: goto P_0c085748;
case 0x0c08574au: goto P_0c08574a;
case 0x0c08574cu: goto P_0c08574c;
case 0x0c08574eu: goto P_0c08574e;
case 0x0c085750u: goto P_0c085750;
case 0x0c085752u: goto P_0c085752;
case 0x0c085754u: goto P_0c085754;
case 0x0c085756u: goto P_0c085756;
case 0x0c085758u: goto P_0c085758;
case 0x0c08575au: goto P_0c08575a;
case 0x0c08575cu: goto P_0c08575c;
case 0x0c08575eu: goto P_0c08575e;
case 0x0c085760u: goto P_0c085760;
case 0x0c085762u: goto P_0c085762;
case 0x0c085764u: goto P_0c085764;
case 0x0c085766u: goto P_0c085766;
case 0x0c085768u: goto P_0c085768;
case 0x0c08576au: goto P_0c08576a;
case 0x0c08576cu: goto P_0c08576c;
case 0x0c08576eu: goto P_0c08576e;
case 0x0c085770u: goto P_0c085770;
case 0x0c085772u: goto P_0c085772;
case 0x0c085774u: goto P_0c085774;
case 0x0c085776u: goto P_0c085776;
case 0x0c085778u: goto P_0c085778;
case 0x0c08577au: goto P_0c08577a;
case 0x0c08577cu: goto P_0c08577c;
case 0x0c08577eu: goto P_0c08577e;
case 0x0c085780u: goto P_0c085780;
case 0x0c085782u: goto P_0c085782;
case 0x0c085784u: goto P_0c085784;
case 0x0c085786u: goto P_0c085786;
case 0x0c085788u: goto P_0c085788;
case 0x0c08578au: goto P_0c08578a;
case 0x0c08578cu: goto P_0c08578c;
case 0x0c08578eu: goto P_0c08578e;
case 0x0c085790u: goto P_0c085790;
case 0x0c085792u: goto P_0c085792;
case 0x0c085794u: goto P_0c085794;
case 0x0c085796u: goto P_0c085796;
case 0x0c085798u: goto P_0c085798;
case 0x0c08579au: goto P_0c08579a;
case 0x0c08579cu: goto P_0c08579c;
case 0x0c08579eu: goto P_0c08579e;
case 0x0c0857a0u: goto P_0c0857a0;
case 0x0c0857a2u: goto P_0c0857a2;
case 0x0c0857dcu: goto P_0c0857dc;
case 0x0c0857deu: goto P_0c0857de;
case 0x0c0857e0u: goto P_0c0857e0;
case 0x0c0857e2u: goto P_0c0857e2;
case 0x0c0857e4u: goto P_0c0857e4;
case 0x0c0857e6u: goto P_0c0857e6;
case 0x0c0857e8u: goto P_0c0857e8;
case 0x0c0857eau: goto P_0c0857ea;
case 0x0c0857ecu: goto P_0c0857ec;
case 0x0c0857eeu: goto P_0c0857ee;
case 0x0c0857f0u: goto P_0c0857f0;
case 0x0c0857f2u: goto P_0c0857f2;
case 0x0c0857f4u: goto P_0c0857f4;
case 0x0c0857f6u: goto P_0c0857f6;
case 0x0c0857f8u: goto P_0c0857f8;
case 0x0c0857fau: goto P_0c0857fa;
case 0x0c0857fcu: goto P_0c0857fc;
case 0x0c0857feu: goto P_0c0857fe;
case 0x0c085800u: goto P_0c085800;
case 0x0c085802u: goto P_0c085802;
case 0x0c085804u: goto P_0c085804;
case 0x0c085806u: goto P_0c085806;
case 0x0c085808u: goto P_0c085808;
case 0x0c08580au: goto P_0c08580a;
case 0x0c08580cu: goto P_0c08580c;
case 0x0c08580eu: goto P_0c08580e;
case 0x0c085810u: goto P_0c085810;
case 0x0c085812u: goto P_0c085812;
case 0x0c085814u: goto P_0c085814;
case 0x0c085816u: goto P_0c085816;
case 0x0c085818u: goto P_0c085818;
case 0x0c08581au: goto P_0c08581a;
case 0x0c08581cu: goto P_0c08581c;
case 0x0c08581eu: goto P_0c08581e;
case 0x0c085820u: goto P_0c085820;
case 0x0c085822u: goto P_0c085822;
case 0x0c085824u: goto P_0c085824;
case 0x0c085826u: goto P_0c085826;
case 0x0c085828u: goto P_0c085828;
case 0x0c08582au: goto P_0c08582a;
case 0x0c08582cu: goto P_0c08582c;
case 0x0c08582eu: goto P_0c08582e;
case 0x0c085830u: goto P_0c085830;
case 0x0c085832u: goto P_0c085832;
case 0x0c085834u: goto P_0c085834;
case 0x0c085836u: goto P_0c085836;
case 0x0c085838u: goto P_0c085838;
case 0x0c08583au: goto P_0c08583a;
case 0x0c0858e8u: goto P_0c0858e8;
case 0x0c0858eau: goto P_0c0858ea;
case 0x0c0858ecu: goto P_0c0858ec;
case 0x0c0858eeu: goto P_0c0858ee;
case 0x0c0858f0u: goto P_0c0858f0;
case 0x0c0858f2u: goto P_0c0858f2;
case 0x0c0858f4u: goto P_0c0858f4;
case 0x0c0858f6u: goto P_0c0858f6;
case 0x0c0858f8u: goto P_0c0858f8;
case 0x0c0858fau: goto P_0c0858fa;
case 0x0c0858fcu: goto P_0c0858fc;
case 0x0c0858feu: goto P_0c0858fe;
case 0x0c085900u: goto P_0c085900;
case 0x0c085902u: goto P_0c085902;
case 0x0c085904u: goto P_0c085904;
case 0x0c085906u: goto P_0c085906;
case 0x0c085908u: goto P_0c085908;
case 0x0c08590au: goto P_0c08590a;
case 0x0c08590cu: goto P_0c08590c;
case 0x0c08590eu: goto P_0c08590e;
case 0x0c085910u: goto P_0c085910;
case 0x0c085912u: goto P_0c085912;
case 0x0c085914u: goto P_0c085914;
case 0x0c085916u: goto P_0c085916;
case 0x0c085918u: goto P_0c085918;
case 0x0c08591au: goto P_0c08591a;
case 0x0c08591cu: goto P_0c08591c;
case 0x0c08591eu: goto P_0c08591e;
case 0x0c085920u: goto P_0c085920;
case 0x0c085922u: goto P_0c085922;
case 0x0c085924u: goto P_0c085924;
case 0x0c085926u: goto P_0c085926;
case 0x0c085928u: goto P_0c085928;
case 0x0c08592au: goto P_0c08592a;
case 0x0c08592cu: goto P_0c08592c;
case 0x0c08592eu: goto P_0c08592e;
case 0x0c085930u: goto P_0c085930;
case 0x0c085932u: goto P_0c085932;
case 0x0c085934u: goto P_0c085934;
case 0x0c085936u: goto P_0c085936;
case 0x0c085938u: goto P_0c085938;
case 0x0c08593au: goto P_0c08593a;
case 0x0c08593cu: goto P_0c08593c;
case 0x0c08593eu: goto P_0c08593e;
case 0x0c085940u: goto P_0c085940;
case 0x0c085942u: goto P_0c085942;
case 0x0c085944u: goto P_0c085944;
case 0x0c085946u: goto P_0c085946;
case 0x0c085948u: goto P_0c085948;
case 0x0c08594au: goto P_0c08594a;
case 0x0c08594cu: goto P_0c08594c;
case 0x0c08594eu: goto P_0c08594e;
case 0x0c085950u: goto P_0c085950;
case 0x0c085952u: goto P_0c085952;
case 0x0c085954u: goto P_0c085954;
case 0x0c085956u: goto P_0c085956;
case 0x0c085958u: goto P_0c085958;
case 0x0c08595au: goto P_0c08595a;
case 0x0c08595cu: goto P_0c08595c;
case 0x0c08595eu: goto P_0c08595e;
case 0x0c085960u: goto P_0c085960;
case 0x0c085962u: goto P_0c085962;
case 0x0c085964u: goto P_0c085964;
case 0x0c085966u: goto P_0c085966;
case 0x0c085968u: goto P_0c085968;
case 0x0c08596au: goto P_0c08596a;
case 0x0c08596cu: goto P_0c08596c;
case 0x0c08596eu: goto P_0c08596e;
case 0x0c085970u: goto P_0c085970;
case 0x0c085972u: goto P_0c085972;
case 0x0c085974u: goto P_0c085974;
case 0x0c085976u: goto P_0c085976;
case 0x0c085978u: goto P_0c085978;
case 0x0c08597au: goto P_0c08597a;
case 0x0c08597cu: goto P_0c08597c;
case 0x0c08597eu: goto P_0c08597e;
case 0x0c085980u: goto P_0c085980;
case 0x0c085982u: goto P_0c085982;
case 0x0c085984u: goto P_0c085984;
case 0x0c085986u: goto P_0c085986;
case 0x0c085988u: goto P_0c085988;
case 0x0c08598au: goto P_0c08598a;
case 0x0c08598cu: goto P_0c08598c;
case 0x0c08598eu: goto P_0c08598e;
case 0x0c085990u: goto P_0c085990;
case 0x0c085992u: goto P_0c085992;
case 0x0c085994u: goto P_0c085994;
case 0x0c085996u: goto P_0c085996;
case 0x0c085998u: goto P_0c085998;
case 0x0c08599au: goto P_0c08599a;
case 0x0c08599cu: goto P_0c08599c;
case 0x0c08599eu: goto P_0c08599e;
case 0x0c0859a0u: goto P_0c0859a0;
case 0x0c0859a2u: goto P_0c0859a2;
case 0x0c0859a4u: goto P_0c0859a4;
case 0x0c0859a6u: goto P_0c0859a6;
case 0x0c0859a8u: goto P_0c0859a8;
case 0x0c0859aau: goto P_0c0859aa;
case 0x0c0859acu: goto P_0c0859ac;
case 0x0c0859aeu: goto P_0c0859ae;
case 0x0c0859b0u: goto P_0c0859b0;
case 0x0c0859b2u: goto P_0c0859b2;
case 0x0c0859b4u: goto P_0c0859b4;
case 0x0c0859b6u: goto P_0c0859b6;
case 0x0c0859b8u: goto P_0c0859b8;
case 0x0c0859bau: goto P_0c0859ba;
case 0x0c0859bcu: goto P_0c0859bc;
case 0x0c0859beu: goto P_0c0859be;
case 0x0c0859c0u: goto P_0c0859c0;
case 0x0c0859c2u: goto P_0c0859c2;
case 0x0c0859c4u: goto P_0c0859c4;
case 0x0c0859c6u: goto P_0c0859c6;
case 0x0c0859c8u: goto P_0c0859c8;
case 0x0c0859cau: goto P_0c0859ca;
case 0x0c0859ccu: goto P_0c0859cc;
case 0x0c0859ceu: goto P_0c0859ce;
case 0x0c0859d0u: goto P_0c0859d0;
case 0x0c0859d2u: goto P_0c0859d2;
case 0x0c085a0cu: goto P_0c085a0c;
case 0x0c085a0eu: goto P_0c085a0e;
case 0x0c085a10u: goto P_0c085a10;
case 0x0c085a12u: goto P_0c085a12;
case 0x0c085a14u: goto P_0c085a14;
case 0x0c085a16u: goto P_0c085a16;
case 0x0c085a18u: goto P_0c085a18;
case 0x0c085a1au: goto P_0c085a1a;
case 0x0c085a1cu: goto P_0c085a1c;
case 0x0c085a1eu: goto P_0c085a1e;
case 0x0c085a20u: goto P_0c085a20;
case 0x0c085a22u: goto P_0c085a22;
case 0x0c085a24u: goto P_0c085a24;
case 0x0c085a26u: goto P_0c085a26;
case 0x0c085a28u: goto P_0c085a28;
case 0x0c085a2au: goto P_0c085a2a;
case 0x0c085a2cu: goto P_0c085a2c;
case 0x0c085a2eu: goto P_0c085a2e;
case 0x0c085a30u: goto P_0c085a30;
case 0x0c085a32u: goto P_0c085a32;
case 0x0c085a34u: goto P_0c085a34;
case 0x0c085a36u: goto P_0c085a36;
case 0x0c085a38u: goto P_0c085a38;
case 0x0c085a3au: goto P_0c085a3a;
case 0x0c085a3cu: goto P_0c085a3c;
case 0x0c085a3eu: goto P_0c085a3e;
case 0x0c085a40u: goto P_0c085a40;
case 0x0c085a42u: goto P_0c085a42;
case 0x0c085a44u: goto P_0c085a44;
case 0x0c085a46u: goto P_0c085a46;
case 0x0c085a48u: goto P_0c085a48;
case 0x0c085a4au: goto P_0c085a4a;
case 0x0c085a4cu: goto P_0c085a4c;
case 0x0c085a4eu: goto P_0c085a4e;
case 0x0c085a50u: goto P_0c085a50;
case 0x0c085a52u: goto P_0c085a52;
case 0x0c085a54u: goto P_0c085a54;
case 0x0c085a56u: goto P_0c085a56;
case 0x0c085a58u: goto P_0c085a58;
case 0x0c085a5au: goto P_0c085a5a;
case 0x0c085a5cu: goto P_0c085a5c;
case 0x0c085a5eu: goto P_0c085a5e;
case 0x0c085a60u: goto P_0c085a60;
case 0x0c085a62u: goto P_0c085a62;
case 0x0c085a64u: goto P_0c085a64;
case 0x0c085a66u: goto P_0c085a66;
case 0x0c085a68u: goto P_0c085a68;
case 0x0c085a6au: goto P_0c085a6a;
case 0x0c085a6cu: goto P_0c085a6c;
case 0x0c085a6eu: goto P_0c085a6e;
case 0x0c085a70u: goto P_0c085a70;
case 0x0c085a72u: goto P_0c085a72;
case 0x0c085a74u: goto P_0c085a74;
case 0x0c085a76u: goto P_0c085a76;
case 0x0c085a78u: goto P_0c085a78;
case 0x0c085a7au: goto P_0c085a7a;
case 0x0c085a7cu: goto P_0c085a7c;
case 0x0c085a7eu: goto P_0c085a7e;
case 0x0c085a80u: goto P_0c085a80;
case 0x0c085a82u: goto P_0c085a82;
case 0x0c085a84u: goto P_0c085a84;
case 0x0c085a86u: goto P_0c085a86;
case 0x0c085a88u: goto P_0c085a88;
case 0x0c085a8au: goto P_0c085a8a;
case 0x0c085a8cu: goto P_0c085a8c;
case 0x0c085a8eu: goto P_0c085a8e;
case 0x0c085a90u: goto P_0c085a90;
case 0x0c085a92u: goto P_0c085a92;
case 0x0c085a94u: goto P_0c085a94;
case 0x0c085a96u: goto P_0c085a96;
case 0x0c085a98u: goto P_0c085a98;
case 0x0c085a9au: goto P_0c085a9a;
case 0x0c085a9cu: goto P_0c085a9c;
case 0x0c085a9eu: goto P_0c085a9e;
case 0x0c085aa0u: goto P_0c085aa0;
case 0x0c085aa2u: goto P_0c085aa2;
case 0x0c085aa4u: goto P_0c085aa4;
case 0x0c085aa6u: goto P_0c085aa6;
case 0x0c085aa8u: goto P_0c085aa8;
case 0x0c085aaau: goto P_0c085aaa;
case 0x0c085aacu: goto P_0c085aac;
case 0x0c085aaeu: goto P_0c085aae;
case 0x0c085ab0u: goto P_0c085ab0;
case 0x0c085ab2u: goto P_0c085ab2;
case 0x0c085ab4u: goto P_0c085ab4;
case 0x0c085ab6u: goto P_0c085ab6;
case 0x0c085ab8u: goto P_0c085ab8;
case 0x0c085abau: goto P_0c085aba;
case 0x0c085abcu: goto P_0c085abc;
case 0x0c085abeu: goto P_0c085abe;
case 0x0c085ac0u: goto P_0c085ac0;
case 0x0c085ac2u: goto P_0c085ac2;
case 0x0c085ac4u: goto P_0c085ac4;
case 0x0c085ac6u: goto P_0c085ac6;
case 0x0c085ac8u: goto P_0c085ac8;
case 0x0c085acau: goto P_0c085aca;
case 0x0c085accu: goto P_0c085acc;
case 0x0c085aceu: goto P_0c085ace;
case 0x0c085ad0u: goto P_0c085ad0;
case 0x0c085ad2u: goto P_0c085ad2;
case 0x0c085ad4u: goto P_0c085ad4;
case 0x0c085ad6u: goto P_0c085ad6;
case 0x0c085ad8u: goto P_0c085ad8;
case 0x0c085adau: goto P_0c085ada;
case 0x0c085adcu: goto P_0c085adc;
case 0x0c085adeu: goto P_0c085ade;
case 0x0c085ae0u: goto P_0c085ae0;
case 0x0c085ae2u: goto P_0c085ae2;
case 0x0c085ae4u: goto P_0c085ae4;
case 0x0c085ae6u: goto P_0c085ae6;
case 0x0c085ae8u: goto P_0c085ae8;
case 0x0c085aeau: goto P_0c085aea;
case 0x0c085aecu: goto P_0c085aec;
case 0x0c085aeeu: goto P_0c085aee;
case 0x0c085af0u: goto P_0c085af0;
case 0x0c085af2u: goto P_0c085af2;
case 0x0c085af4u: goto P_0c085af4;
case 0x0c085af6u: goto P_0c085af6;
case 0x0c085af8u: goto P_0c085af8;
case 0x0c085afau: goto P_0c085afa;
case 0x0c085afcu: goto P_0c085afc;
case 0x0c085afeu: goto P_0c085afe;
case 0x0c085b00u: goto P_0c085b00;
case 0x0c085b02u: goto P_0c085b02;
case 0x0c085b04u: goto P_0c085b04;
case 0x0c085b06u: goto P_0c085b06;
case 0x0c085b08u: goto P_0c085b08;
case 0x0c085b0au: goto P_0c085b0a;
case 0x0c085b0cu: goto P_0c085b0c;
case 0x0c085b0eu: goto P_0c085b0e;
case 0x0c085b10u: goto P_0c085b10;
case 0x0c085b12u: goto P_0c085b12;
case 0x0c085b14u: goto P_0c085b14;
case 0x0c085b16u: goto P_0c085b16;
case 0x0c085b18u: goto P_0c085b18;
case 0x0c085b1au: goto P_0c085b1a;
case 0x0c085b1cu: goto P_0c085b1c;
case 0x0c085b1eu: goto P_0c085b1e;
case 0x0c085b20u: goto P_0c085b20;
case 0x0c085b22u: goto P_0c085b22;
case 0x0c085b24u: goto P_0c085b24;
case 0x0c085b26u: goto P_0c085b26;
case 0x0c085b28u: goto P_0c085b28;
case 0x0c085b2au: goto P_0c085b2a;
case 0x0c085b2cu: goto P_0c085b2c;
case 0x0c085b2eu: goto P_0c085b2e;
case 0x0c085b30u: goto P_0c085b30;
case 0x0c085b32u: goto P_0c085b32;
case 0x0c085b34u: goto P_0c085b34;
case 0x0c085b36u: goto P_0c085b36;
case 0x0c085b38u: goto P_0c085b38;
case 0x0c085b3au: goto P_0c085b3a;
case 0x0c085b3cu: goto P_0c085b3c;
case 0x0c085b3eu: goto P_0c085b3e;
case 0x0c085b40u: goto P_0c085b40;
case 0x0c085b42u: goto P_0c085b42;
case 0x0c085b44u: goto P_0c085b44;
case 0x0c085b46u: goto P_0c085b46;
case 0x0c085b48u: goto P_0c085b48;
case 0x0c085b4au: goto P_0c085b4a;
case 0x0c085b88u: goto P_0c085b88;
case 0x0c085b8au: goto P_0c085b8a;
case 0x0c085b8cu: goto P_0c085b8c;
case 0x0c085b8eu: goto P_0c085b8e;
case 0x0c085b90u: goto P_0c085b90;
case 0x0c085b92u: goto P_0c085b92;
case 0x0c085b94u: goto P_0c085b94;
case 0x0c085b96u: goto P_0c085b96;
case 0x0c085b98u: goto P_0c085b98;
case 0x0c085b9au: goto P_0c085b9a;
case 0x0c085b9cu: goto P_0c085b9c;
case 0x0c085b9eu: goto P_0c085b9e;
case 0x0c085ba0u: goto P_0c085ba0;
case 0x0c085ba2u: goto P_0c085ba2;
case 0x0c085ba4u: goto P_0c085ba4;
case 0x0c085ba6u: goto P_0c085ba6;
case 0x0c085ba8u: goto P_0c085ba8;
case 0x0c085baau: goto P_0c085baa;
case 0x0c085bacu: goto P_0c085bac;
case 0x0c085baeu: goto P_0c085bae;
case 0x0c085bb0u: goto P_0c085bb0;
case 0x0c085bb2u: goto P_0c085bb2;
case 0x0c085bb4u: goto P_0c085bb4;
case 0x0c085bb6u: goto P_0c085bb6;
case 0x0c085bb8u: goto P_0c085bb8;
case 0x0c085bbau: goto P_0c085bba;
case 0x0c085bbcu: goto P_0c085bbc;
case 0x0c085bbeu: goto P_0c085bbe;
case 0x0c085bc0u: goto P_0c085bc0;
case 0x0c085bc2u: goto P_0c085bc2;
case 0x0c085bc4u: goto P_0c085bc4;
case 0x0c0a7442u: goto P_0c0a7442;
case 0x0c0a7444u: goto P_0c0a7444;
case 0x0c0a7446u: goto P_0c0a7446;
case 0x0c0a7448u: goto P_0c0a7448;
case 0x0c0a744au: goto P_0c0a744a;
case 0x0c0a744cu: goto P_0c0a744c;
case 0x0c0a744eu: goto P_0c0a744e;
case 0x0c0abcdcu: goto P_0c0abcdc;
case 0x0c0abcdeu: goto P_0c0abcde;
case 0x0c0abce0u: goto P_0c0abce0;
case 0x0c0abce2u: goto P_0c0abce2;
case 0x0c0abce4u: goto P_0c0abce4;
case 0x0c0abce6u: goto P_0c0abce6;
case 0x0c0abce8u: goto P_0c0abce8;
case 0x0c0abceau: goto P_0c0abcea;
case 0x0c0abd2cu: goto P_0c0abd2c;
case 0x0c0abd2eu: goto P_0c0abd2e;
case 0x0c0abd30u: goto P_0c0abd30;
case 0x0c0abd32u: goto P_0c0abd32;
case 0x0c0abd34u: goto P_0c0abd34;
case 0x0c0abd36u: goto P_0c0abd36;
case 0x0c0abd38u: goto P_0c0abd38;
case 0x0c0abd3au: goto P_0c0abd3a;
case 0x0c0abd3cu: goto P_0c0abd3c;
case 0x0c0abd3eu: goto P_0c0abd3e;
case 0x0c0abd40u: goto P_0c0abd40;
case 0x0c0abd42u: goto P_0c0abd42;
case 0x0c0abd44u: goto P_0c0abd44;
case 0x0c0abd46u: goto P_0c0abd46;
case 0x0c0abd48u: goto P_0c0abd48;
case 0x0c0abd4au: goto P_0c0abd4a;
case 0x0c0abd4cu: goto P_0c0abd4c;
case 0x0c0abd4eu: goto P_0c0abd4e;
case 0x0c0abd50u: goto P_0c0abd50;
case 0x0c0abd52u: goto P_0c0abd52;
case 0x0c0abd54u: goto P_0c0abd54;
case 0x0c0abd56u: goto P_0c0abd56;
case 0x0c0abd58u: goto P_0c0abd58;
case 0x0c0abd5au: goto P_0c0abd5a;
case 0x0c0abd5cu: goto P_0c0abd5c;
case 0x0c0abd5eu: goto P_0c0abd5e;
case 0x0c0abd60u: goto P_0c0abd60;
case 0x0c0abd62u: goto P_0c0abd62;
case 0x0c0abd64u: goto P_0c0abd64;
case 0x0c0abd66u: goto P_0c0abd66;
case 0x0c0abd68u: goto P_0c0abd68;
case 0x0c0abd6au: goto P_0c0abd6a;
case 0x0c0abd6cu: goto P_0c0abd6c;
case 0x0c0abd6eu: goto P_0c0abd6e;
case 0x0c0abd70u: goto P_0c0abd70;
case 0x0c0abd72u: goto P_0c0abd72;
case 0x0c0abd74u: goto P_0c0abd74;
case 0x0c0abd76u: goto P_0c0abd76;
case 0x0c0abd78u: goto P_0c0abd78;
case 0x0c0abd7au: goto P_0c0abd7a;
case 0x0c0abd7cu: goto P_0c0abd7c;
case 0x0c0abd7eu: goto P_0c0abd7e;
case 0x0c0abd80u: goto P_0c0abd80;
case 0x0c0abd82u: goto P_0c0abd82;
case 0x0c0abd84u: goto P_0c0abd84;
case 0x0c0abd86u: goto P_0c0abd86;
case 0x0c0abd88u: goto P_0c0abd88;
case 0x0c0abd8au: goto P_0c0abd8a;
case 0x0c0abd8cu: goto P_0c0abd8c;
case 0x0c0abd8eu: goto P_0c0abd8e;
case 0x0c0abd90u: goto P_0c0abd90;
case 0x0c0abd92u: goto P_0c0abd92;
case 0x0c0abd94u: goto P_0c0abd94;
case 0x0c0abd96u: goto P_0c0abd96;
case 0x0c0abd98u: goto P_0c0abd98;
case 0x0c0abd9au: goto P_0c0abd9a;
case 0x0c0abd9cu: goto P_0c0abd9c;
case 0x0c0abd9eu: goto P_0c0abd9e;
case 0x0c0abda0u: goto P_0c0abda0;
case 0x0c0abda2u: goto P_0c0abda2;
case 0x0c0abda4u: goto P_0c0abda4;
case 0x0c0abda6u: goto P_0c0abda6;
case 0x0c0abda8u: goto P_0c0abda8;
case 0x0c0abdaau: goto P_0c0abdaa;
case 0x0c0abdacu: goto P_0c0abdac;
case 0x0c0abdaeu: goto P_0c0abdae;
case 0x0c0abdb0u: goto P_0c0abdb0;
case 0x0c0abdb2u: goto P_0c0abdb2;
case 0x0c0abdb4u: goto P_0c0abdb4;
case 0x0c0abdb6u: goto P_0c0abdb6;
case 0x0c0abdb8u: goto P_0c0abdb8;
case 0x0c0abdbau: goto P_0c0abdba;
case 0x0c0abdbcu: goto P_0c0abdbc;
case 0x0c0abdbeu: goto P_0c0abdbe;
case 0x0c0abdc0u: goto P_0c0abdc0;
case 0x0c0abdc2u: goto P_0c0abdc2;
case 0x0c0ca0c6u: goto P_0c0ca0c6;
case 0x0c0ca0c8u: goto P_0c0ca0c8;
case 0x0c0ca0cau: goto P_0c0ca0ca;
case 0x0c0ca0ccu: goto P_0c0ca0cc;
case 0x0c0ca0ceu: goto P_0c0ca0ce;
case 0x0c0ca0d0u: goto P_0c0ca0d0;
case 0x0c0ca0d2u: goto P_0c0ca0d2;
case 0x0c0ca0d4u: goto P_0c0ca0d4;
case 0x0c0ca0d6u: goto P_0c0ca0d6;
case 0x0c0ca0d8u: goto P_0c0ca0d8;
case 0x0c0ca0dau: goto P_0c0ca0da;
case 0x0c0ca0dcu: goto P_0c0ca0dc;
case 0x0c0ca0deu: goto P_0c0ca0de;
case 0x0c0ca0e0u: goto P_0c0ca0e0;
case 0x0c0ca0e2u: goto P_0c0ca0e2;
case 0x0c0ca0e4u: goto P_0c0ca0e4;
case 0x0c0ca0e6u: goto P_0c0ca0e6;
case 0x0c0ca0e8u: goto P_0c0ca0e8;
case 0x0c0ca0eau: goto P_0c0ca0ea;
case 0x0c0ca0ecu: goto P_0c0ca0ec;
case 0x0c0ca0eeu: goto P_0c0ca0ee;
case 0x0c0ca0f0u: goto P_0c0ca0f0;
case 0x0c0ca0f2u: goto P_0c0ca0f2;
case 0x0c0ca0f4u: goto P_0c0ca0f4;
case 0x0c0ca0f6u: goto P_0c0ca0f6;
case 0x0c0ca0f8u: goto P_0c0ca0f8;
case 0x0c0ca0fau: goto P_0c0ca0fa;
case 0x0c0ca0fcu: goto P_0c0ca0fc;
case 0x0c0ca0feu: goto P_0c0ca0fe;
case 0x0c0ca100u: goto P_0c0ca100;
case 0x0c0ca102u: goto P_0c0ca102;
case 0x0c0ca104u: goto P_0c0ca104;
case 0x0c0ca106u: goto P_0c0ca106;
case 0x0c0ca108u: goto P_0c0ca108;
case 0x0c0ca10au: goto P_0c0ca10a;
case 0x0c0ca10cu: goto P_0c0ca10c;
case 0x0c0ca10eu: goto P_0c0ca10e;
case 0x0c0ca110u: goto P_0c0ca110;
case 0x0c0ca112u: goto P_0c0ca112;
case 0x0c0ca114u: goto P_0c0ca114;
case 0x0c0ca116u: goto P_0c0ca116;
case 0x0c0ca118u: goto P_0c0ca118;
case 0x0c0ca11au: goto P_0c0ca11a;
case 0x0c0ca11cu: goto P_0c0ca11c;
case 0x0c0ca11eu: goto P_0c0ca11e;
case 0x0c0ca120u: goto P_0c0ca120;
case 0x0c0ca122u: goto P_0c0ca122;
case 0x0c0ca124u: goto P_0c0ca124;
case 0x0c0ca126u: goto P_0c0ca126;
case 0x0c0ca128u: goto P_0c0ca128;
case 0x0c0ca12au: goto P_0c0ca12a;
case 0x0c0ca12cu: goto P_0c0ca12c;
case 0x0c0ca12eu: goto P_0c0ca12e;
case 0x0c0ca130u: goto P_0c0ca130;
case 0x0c0ca132u: goto P_0c0ca132;
case 0x0c0ca134u: goto P_0c0ca134;
case 0x0c0ca136u: goto P_0c0ca136;
case 0x0c0ca138u: goto P_0c0ca138;
case 0x0c0ca13au: goto P_0c0ca13a;
case 0x0c0ca13cu: goto P_0c0ca13c;
case 0x0c0ca13eu: goto P_0c0ca13e;
case 0x0c0ca140u: goto P_0c0ca140;
case 0x0c0ca142u: goto P_0c0ca142;
case 0x0c0ca144u: goto P_0c0ca144;
case 0x0c0ca146u: goto P_0c0ca146;
case 0x0c0ca148u: goto P_0c0ca148;
case 0x0c0ca14au: goto P_0c0ca14a;
case 0x0c0ca14cu: goto P_0c0ca14c;
case 0x0c0ca14eu: goto P_0c0ca14e;
case 0x0c0ca150u: goto P_0c0ca150;
case 0x0c0ca152u: goto P_0c0ca152;
case 0x0c0ca154u: goto P_0c0ca154;
case 0x0c0ca156u: goto P_0c0ca156;
case 0x0c0ca158u: goto P_0c0ca158;
case 0x0c0ca15au: goto P_0c0ca15a;
case 0x0c0ca15cu: goto P_0c0ca15c;
case 0x0c0ca15eu: goto P_0c0ca15e;
case 0x0c0ca326u: goto P_0c0ca326;
case 0x0c0ca328u: goto P_0c0ca328;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03da50: /* original d579, guest PC 0x0c03da50 */
if(!s->budget--) { s->failed_pc=0x0c03da50u; return 0; }
r[5]=read(ram,0x0c03dc38u,4);
goto P_0c03da52;
P_0c03da52: /* original c778, guest PC 0x0c03da52 */
if(!s->budget--) { s->failed_pc=0x0c03da52u; return 0; }
r[0]=0x0c03dc34u;
goto P_0c03da54;
P_0c03da54: /* original f508, guest PC 0x0c03da54 */
if(!s->budget--) { s->failed_pc=0x0c03da54u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03da56;
P_0c03da56: /* original e004, guest PC 0x0c03da56 */
if(!s->budget--) { s->failed_pc=0x0c03da56u; return 0; }
r[0]=0x00000004u;
goto P_0c03da58;
P_0c03da58: /* original f358, guest PC 0x0c03da58 */
if(!s->budget--) { s->failed_pc=0x0c03da58u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c03da5a;
P_0c03da5a: /* original f352, guest PC 0x0c03da5a */
if(!s->budget--) { s->failed_pc=0x0c03da5au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03da5c;
P_0c03da5c: /* original f43a, guest PC 0x0c03da5c */
if(!s->budget--) { s->failed_pc=0x0c03da5cu; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c03da5e;
P_0c03da5e: /* original f48d, guest PC 0x0c03da5e */
if(!s->budget--) { s->failed_pc=0x0c03da5eu; return 0; }
fr[4]=0;
goto P_0c03da60;
P_0c03da60: /* original f447, guest PC 0x0c03da60 */
if(!s->budget--) { s->failed_pc=0x0c03da60u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c03da62;
P_0c03da62: /* original e008, guest PC 0x0c03da62 */
if(!s->budget--) { s->failed_pc=0x0c03da62u; return 0; }
r[0]=0x00000008u;
goto P_0c03da64;
P_0c03da64: /* original f447, guest PC 0x0c03da64 */
if(!s->budget--) { s->failed_pc=0x0c03da64u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c03da66;
P_0c03da66: /* original e00c, guest PC 0x0c03da66 */
if(!s->budget--) { s->failed_pc=0x0c03da66u; return 0; }
r[0]=0x0000000cu;
goto P_0c03da68;
P_0c03da68: /* original f447, guest PC 0x0c03da68 */
if(!s->budget--) { s->failed_pc=0x0c03da68u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c03da6a;
P_0c03da6a: /* original e010, guest PC 0x0c03da6a */
if(!s->budget--) { s->failed_pc=0x0c03da6au; return 0; }
r[0]=0x00000010u;
goto P_0c03da6c;
P_0c03da6c: /* original f447, guest PC 0x0c03da6c */
if(!s->budget--) { s->failed_pc=0x0c03da6cu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c03da6e;
P_0c03da6e: /* original e014, guest PC 0x0c03da6e */
if(!s->budget--) { s->failed_pc=0x0c03da6eu; return 0; }
r[0]=0x00000014u;
goto P_0c03da70;
P_0c03da70: /* original d673, guest PC 0x0c03da70 */
if(!s->budget--) { s->failed_pc=0x0c03da70u; return 0; }
r[6]=read(ram,0x0c03dc40u,4);
goto P_0c03da72;
P_0c03da72: /* original f368, guest PC 0x0c03da72 */
if(!s->budget--) { s->failed_pc=0x0c03da72u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
goto P_0c03da74;
P_0c03da74: /* original f352, guest PC 0x0c03da74 */
if(!s->budget--) { s->failed_pc=0x0c03da74u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03da76;
P_0c03da76: /* original f34d, guest PC 0x0c03da76 */
if(!s->budget--) { s->failed_pc=0x0c03da76u; return 0; }
fr[3]^=0x80000000u;
goto P_0c03da78;
P_0c03da78: /* original f437, guest PC 0x0c03da78 */
if(!s->budget--) { s->failed_pc=0x0c03da78u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03da7a;
P_0c03da7a: /* original e018, guest PC 0x0c03da7a */
if(!s->budget--) { s->failed_pc=0x0c03da7au; return 0; }
r[0]=0x00000018u;
goto P_0c03da7c;
P_0c03da7c: /* original f447, guest PC 0x0c03da7c */
if(!s->budget--) { s->failed_pc=0x0c03da7cu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c03da7e;
P_0c03da7e: /* original e01c, guest PC 0x0c03da7e */
if(!s->budget--) { s->failed_pc=0x0c03da7eu; return 0; }
r[0]=0x0000001cu;
goto P_0c03da80;
P_0c03da80: /* original f447, guest PC 0x0c03da80 */
if(!s->budget--) { s->failed_pc=0x0c03da80u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c03da82;
P_0c03da82: /* original e020, guest PC 0x0c03da82 */
if(!s->budget--) { s->failed_pc=0x0c03da82u; return 0; }
r[0]=0x00000020u;
goto P_0c03da84;
P_0c03da84: /* original f447, guest PC 0x0c03da84 */
if(!s->budget--) { s->failed_pc=0x0c03da84u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c03da86;
P_0c03da86: /* original e024, guest PC 0x0c03da86 */
if(!s->budget--) { s->failed_pc=0x0c03da86u; return 0; }
r[0]=0x00000024u;
goto P_0c03da88;
P_0c03da88: /* original f447, guest PC 0x0c03da88 */
if(!s->budget--) { s->failed_pc=0x0c03da88u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c03da8a;
P_0c03da8a: /* original c772, guest PC 0x0c03da8a */
if(!s->budget--) { s->failed_pc=0x0c03da8au; return 0; }
r[0]=0x0c03dc54u;
goto P_0c03da8c;
P_0c03da8c: /* original f308, guest PC 0x0c03da8c */
if(!s->budget--) { s->failed_pc=0x0c03da8cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03da8e;
P_0c03da8e: /* original e028, guest PC 0x0c03da8e */
if(!s->budget--) { s->failed_pc=0x0c03da8eu; return 0; }
r[0]=0x00000028u;
goto P_0c03da90;
P_0c03da90: /* original f437, guest PC 0x0c03da90 */
if(!s->budget--) { s->failed_pc=0x0c03da90u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03da92;
P_0c03da92: /* original e02c, guest PC 0x0c03da92 */
if(!s->budget--) { s->failed_pc=0x0c03da92u; return 0; }
r[0]=0x0000002cu;
goto P_0c03da94;
P_0c03da94: /* original f447, guest PC 0x0c03da94 */
if(!s->budget--) { s->failed_pc=0x0c03da94u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c03da96;
P_0c03da96: /* original e030, guest PC 0x0c03da96 */
if(!s->budget--) { s->failed_pc=0x0c03da96u; return 0; }
r[0]=0x00000030u;
goto P_0c03da98;
P_0c03da98: /* original d36a, guest PC 0x0c03da98 */
if(!s->budget--) { s->failed_pc=0x0c03da98u; return 0; }
r[3]=read(ram,0x0c03dc44u,4);
goto P_0c03da9a;
P_0c03da9a: /* original f258, guest PC 0x0c03da9a */
if(!s->budget--) { s->failed_pc=0x0c03da9au; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c03da9c;
P_0c03da9c: /* original f338, guest PC 0x0c03da9c */
if(!s->budget--) { s->failed_pc=0x0c03da9cu; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c03da9e;
P_0c03da9e: /* original f05c, guest PC 0x0c03da9e */
if(!s->budget--) { s->failed_pc=0x0c03da9eu; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c03daa0;
P_0c03daa0: /* original f32e, guest PC 0x0c03daa0 */
if(!s->budget--) { s->failed_pc=0x0c03daa0u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c03daa2;
P_0c03daa2: /* original f437, guest PC 0x0c03daa2 */
if(!s->budget--) { s->failed_pc=0x0c03daa2u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03daa4;
P_0c03daa4: /* original e034, guest PC 0x0c03daa4 */
if(!s->budget--) { s->failed_pc=0x0c03daa4u; return 0; }
r[0]=0x00000034u;
goto P_0c03daa6;
P_0c03daa6: /* original d265, guest PC 0x0c03daa6 */
if(!s->budget--) { s->failed_pc=0x0c03daa6u; return 0; }
r[2]=read(ram,0x0c03dc3cu,4);
goto P_0c03daa8;
P_0c03daa8: /* original f268, guest PC 0x0c03daa8 */
if(!s->budget--) { s->failed_pc=0x0c03daa8u; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c03daaa;
P_0c03daaa: /* original f328, guest PC 0x0c03daaa */
if(!s->budget--) { s->failed_pc=0x0c03daaau; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
goto P_0c03daac;
P_0c03daac: /* original f32e, guest PC 0x0c03daac */
if(!s->budget--) { s->failed_pc=0x0c03daacu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c03daae;
P_0c03daae: /* original f437, guest PC 0x0c03daae */
if(!s->budget--) { s->failed_pc=0x0c03daaeu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03dab0;
P_0c03dab0: /* original e038, guest PC 0x0c03dab0 */
if(!s->budget--) { s->failed_pc=0x0c03dab0u; return 0; }
r[0]=0x00000038u;
goto P_0c03dab2;
P_0c03dab2: /* original f407, guest PC 0x0c03dab2 */
if(!s->budget--) { s->failed_pc=0x0c03dab2u; return 0; }
vf3_matrix_store(s,ram,0,r[4]+r[0]);
goto P_0c03dab4;
P_0c03dab4: /* original e03c, guest PC 0x0c03dab4 */
if(!s->budget--) { s->failed_pc=0x0c03dab4u; return 0; }
r[0]=0x0000003cu;
goto P_0c03dab6;
P_0c03dab6: /* original f39d, guest PC 0x0c03dab6 */
if(!s->budget--) { s->failed_pc=0x0c03dab6u; return 0; }
fr[3]=0x3f800000u;
goto P_0c03dab8;
P_0c03dab8: /* original 000b, guest PC 0x0c03dab8 */
if(!s->budget--) { s->failed_pc=0x0c03dab8u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,3,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c03daba: /* original f437, guest PC 0x0c03daba */
if(!s->budget--) { s->failed_pc=0x0c03dabau; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
return vf3_matrix_family(0x0c03dabcu,s,ram);
P_0c03dad0: /* original 4f22, guest PC 0x0c03dad0 */
if(!s->budget--) { s->failed_pc=0x0c03dad0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03dad2;
P_0c03dad2: /* original fc7c, guest PC 0x0c03dad2 */
if(!s->budget--) { s->failed_pc=0x0c03dad2u; return 0; }
vf3_matrix_move(s,12,7);
goto P_0c03dad4;
P_0c03dad4: /* original f3fa, guest PC 0x0c03dad4 */
if(!s->budget--) { s->failed_pc=0x0c03dad4u; return 0; }
vf3_matrix_store(s,ram,15,r[3]);
goto P_0c03dad6;
P_0c03dad6: /* original d261, guest PC 0x0c03dad6 */
if(!s->budget--) { s->failed_pc=0x0c03dad6u; return 0; }
r[2]=read(ram,0x0c03dc5cu,4);
goto P_0c03dad8;
P_0c03dad8: /* original 7ff8, guest PC 0x0c03dad8 */
if(!s->budget--) { s->failed_pc=0x0c03dad8u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c03dada;
P_0c03dada: /* original f2ea, guest PC 0x0c03dada */
if(!s->budget--) { s->failed_pc=0x0c03dadau; return 0; }
vf3_matrix_store(s,ram,14,r[2]);
goto P_0c03dadc;
P_0c03dadc: /* original d160, guest PC 0x0c03dadc */
if(!s->budget--) { s->failed_pc=0x0c03dadcu; return 0; }
r[1]=read(ram,0x0c03dc60u,4);
goto P_0c03dade;
P_0c03dade: /* original f1da, guest PC 0x0c03dade */
if(!s->budget--) { s->failed_pc=0x0c03dadeu; return 0; }
vf3_matrix_store(s,ram,13,r[1]);
goto P_0c03dae0;
P_0c03dae0: /* original d360, guest PC 0x0c03dae0 */
if(!s->budget--) { s->failed_pc=0x0c03dae0u; return 0; }
r[3]=read(ram,0x0c03dc64u,4);
goto P_0c03dae2;
P_0c03dae2: /* original f3ca, guest PC 0x0c03dae2 */
if(!s->budget--) { s->failed_pc=0x0c03dae2u; return 0; }
vf3_matrix_store(s,ram,12,r[3]);
goto P_0c03dae4;
P_0c03dae4: /* original d255, guest PC 0x0c03dae4 */
if(!s->budget--) { s->failed_pc=0x0c03dae4u; return 0; }
r[2]=read(ram,0x0c03dc3cu,4);
goto P_0c03dae6;
P_0c03dae6: /* original f2ea, guest PC 0x0c03dae6 */
if(!s->budget--) { s->failed_pc=0x0c03dae6u; return 0; }
vf3_matrix_store(s,ram,14,r[2]);
goto P_0c03dae8;
P_0c03dae8: /* original d655, guest PC 0x0c03dae8 */
if(!s->budget--) { s->failed_pc=0x0c03dae8u; return 0; }
r[6]=read(ram,0x0c03dc40u,4);
goto P_0c03daea;
P_0c03daea: /* original f6ca, guest PC 0x0c03daea */
if(!s->budget--) { s->failed_pc=0x0c03daeau; return 0; }
vf3_matrix_store(s,ram,12,r[6]);
goto P_0c03daec;
P_0c03daec: /* original d05e, guest PC 0x0c03daec */
if(!s->budget--) { s->failed_pc=0x0c03daecu; return 0; }
r[0]=read(ram,0x0c03dc68u,4);
goto P_0c03daee;
P_0c03daee: /* original d452, guest PC 0x0c03daee */
if(!s->budget--) { s->failed_pc=0x0c03daeeu; return 0; }
r[4]=read(ram,0x0c03dc38u,4);
goto P_0c03daf0;
P_0c03daf0: /* original 6101, guest PC 0x0c03daf0 */
if(!s->budget--) { s->failed_pc=0x0c03daf0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[0],2);
r[1]=tmp;
goto P_0c03daf2;
P_0c03daf2: /* original d554, guest PC 0x0c03daf2 */
if(!s->budget--) { s->failed_pc=0x0c03daf2u; return 0; }
r[5]=read(ram,0x0c03dc44u,4);
goto P_0c03daf4;
P_0c03daf4: /* original 2118, guest PC 0x0c03daf4 */
if(!s->budget--) { s->failed_pc=0x0c03daf4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c03daf6;
P_0c03daf6: /* original 890b, guest PC 0x0c03daf6 */
if(!s->budget--) { s->failed_pc=0x0c03daf6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03db10; }
goto P_0c03daf8;
P_0c03daf8: /* original c75c, guest PC 0x0c03daf8 */
if(!s->budget--) { s->failed_pc=0x0c03daf8u; return 0; }
r[0]=0x0c03dc6cu;
goto P_0c03dafa;
P_0c03dafa: /* original f3fc, guest PC 0x0c03dafa */
if(!s->budget--) { s->failed_pc=0x0c03dafau; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c03dafc;
P_0c03dafc: /* original f408, guest PC 0x0c03dafc */
if(!s->budget--) { s->failed_pc=0x0c03dafcu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c03dafe;
P_0c03dafe: /* original f342, guest PC 0x0c03dafe */
if(!s->budget--) { s->failed_pc=0x0c03dafeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c03db00;
P_0c03db00: /* original f53a, guest PC 0x0c03db00 */
if(!s->budget--) { s->failed_pc=0x0c03db00u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c03db02;
P_0c03db02: /* original f2dc, guest PC 0x0c03db02 */
if(!s->budget--) { s->failed_pc=0x0c03db02u; return 0; }
vf3_matrix_move(s,2,13);
goto P_0c03db04;
P_0c03db04: /* original f242, guest PC 0x0c03db04 */
if(!s->budget--) { s->failed_pc=0x0c03db04u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c03db06;
P_0c03db06: /* original a005, guest PC 0x0c03db06 */
if(!s->budget--) { s->failed_pc=0x0c03db06u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c03db14;
P_0c03db08: /* original f42a, guest PC 0x0c03db08 */
if(!s->budget--) { s->failed_pc=0x0c03db08u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
return vf3_matrix_family(0x0c03db0au,s,ram);
P_0c03db10: /* original f5fa, guest PC 0x0c03db10 */
if(!s->budget--) { s->failed_pc=0x0c03db10u; return 0; }
vf3_matrix_store(s,ram,15,r[5]);
goto P_0c03db12;
P_0c03db12: /* original f4da, guest PC 0x0c03db12 */
if(!s->budget--) { s->failed_pc=0x0c03db12u; return 0; }
vf3_matrix_store(s,ram,13,r[4]);
goto P_0c03db14;
P_0c03db14: /* original d357, guest PC 0x0c03db14 */
if(!s->budget--) { s->failed_pc=0x0c03db14u; return 0; }
r[3]=read(ram,0x0c03dc74u,4);
goto P_0c03db16;
P_0c03db16: /* original f248, guest PC 0x0c03db16 */
if(!s->budget--) { s->failed_pc=0x0c03db16u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
goto P_0c03db18;
P_0c03db18: /* original f338, guest PC 0x0c03db18 */
if(!s->budget--) { s->failed_pc=0x0c03db18u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c03db1a;
P_0c03db1a: /* original d555, guest PC 0x0c03db1a */
if(!s->budget--) { s->failed_pc=0x0c03db1au; return 0; }
r[5]=read(ram,0x0c03dc70u,4);
goto P_0c03db1c;
P_0c03db1c: /* original f232, guest PC 0x0c03db1c */
if(!s->budget--) { s->failed_pc=0x0c03db1cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03db1e;
P_0c03db1e: /* original f52a, guest PC 0x0c03db1e */
if(!s->budget--) { s->failed_pc=0x0c03db1eu; return 0; }
vf3_matrix_store(s,ram,2,r[5]);
goto P_0c03db20;
P_0c03db20: /* original d256, guest PC 0x0c03db20 */
if(!s->budget--) { s->failed_pc=0x0c03db20u; return 0; }
r[2]=read(ram,0x0c03dc7cu,4);
goto P_0c03db22;
P_0c03db22: /* original f268, guest PC 0x0c03db22 */
if(!s->budget--) { s->failed_pc=0x0c03db22u; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c03db24;
P_0c03db24: /* original f328, guest PC 0x0c03db24 */
if(!s->budget--) { s->failed_pc=0x0c03db24u; return 0; }
vf3_matrix_load(s,ram,3,r[2]);
goto P_0c03db26;
P_0c03db26: /* original d454, guest PC 0x0c03db26 */
if(!s->budget--) { s->failed_pc=0x0c03db26u; return 0; }
r[4]=read(ram,0x0c03dc78u,4);
goto P_0c03db28;
P_0c03db28: /* original f232, guest PC 0x0c03db28 */
if(!s->budget--) { s->failed_pc=0x0c03db28u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03db2a;
P_0c03db2a: /* original f42a, guest PC 0x0c03db2a */
if(!s->budget--) { s->failed_pc=0x0c03db2au; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c03db2c;
P_0c03db2c: /* original f458, guest PC 0x0c03db2c */
if(!s->budget--) { s->failed_pc=0x0c03db2cu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
goto P_0c03db2e;
P_0c03db2e: /* original f52c, guest PC 0x0c03db2e */
if(!s->budget--) { s->failed_pc=0x0c03db2eu; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c03db30;
P_0c03db30: /* original f455, guest PC 0x0c03db30 */
if(!s->budget--) { s->failed_pc=0x0c03db30u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c03db32;
P_0c03db32: /* original d653, guest PC 0x0c03db32 */
if(!s->budget--) { s->failed_pc=0x0c03db32u; return 0; }
r[6]=read(ram,0x0c03dc80u,4);
goto P_0c03db34;
P_0c03db34: /* original 8b04, guest PC 0x0c03db34 */
if(!s->budget--) { s->failed_pc=0x0c03db34u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03db40; }
goto P_0c03db36;
P_0c03db36: /* original a004, guest PC 0x0c03db36 */
if(!s->budget--) { s->failed_pc=0x0c03db36u; return 0; }
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c03db42;
P_0c03db38: /* original f64a, guest PC 0x0c03db38 */
if(!s->budget--) { s->failed_pc=0x0c03db38u; return 0; }
vf3_matrix_store(s,ram,4,r[6]);
return vf3_matrix_family(0x0c03db3au,s,ram);
P_0c03db40: /* original f65a, guest PC 0x0c03db40 */
if(!s->budget--) { s->failed_pc=0x0c03db40u; return 0; }
vf3_matrix_store(s,ram,5,r[6]);
goto P_0c03db42;
P_0c03db42: /* original d450, guest PC 0x0c03db42 */
if(!s->budget--) { s->failed_pc=0x0c03db42u; return 0; }
r[4]=read(ram,0x0c03dc84u,4);
goto P_0c03db44;
P_0c03db44: /* original bf84, guest PC 0x0c03db44 */
if(!s->budget--) { s->failed_pc=0x0c03db44u; return 0; }
target=0x0c03da50u; r[16]=0x0c03db48u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03db48u) { target=s->pc; goto dispatch; }
goto P_0c03db48;
P_0c03db46: /* original 0009, guest PC 0x0c03db46 */
if(!s->budget--) { s->failed_pc=0x0c03db46u; return 0; }
goto P_0c03db48;
P_0c03db48: /* original fe3d, guest PC 0x0c03db48 */
if(!s->budget--) { s->failed_pc=0x0c03db48u; return 0; }
r[53]=truncate_float(fr[14]);
goto P_0c03db4a;
P_0c03db4a: /* original f3ec, guest PC 0x0c03db4a */
if(!s->budget--) { s->failed_pc=0x0c03db4au; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c03db4c;
P_0c03db4c: /* original f3c0, guest PC 0x0c03db4c */
if(!s->budget--) { s->failed_pc=0x0c03db4cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'+');
goto P_0c03db4e;
P_0c03db4e: /* original e004, guest PC 0x0c03db4e */
if(!s->budget--) { s->failed_pc=0x0c03db4eu; return 0; }
r[0]=0x00000004u;
goto P_0c03db50;
P_0c03db50: /* original ff37, guest PC 0x0c03db50 */
if(!s->budget--) { s->failed_pc=0x0c03db50u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03db52;
P_0c03db52: /* original f2fc, guest PC 0x0c03db52 */
if(!s->budget--) { s->failed_pc=0x0c03db52u; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c03db54;
P_0c03db54: /* original f2d0, guest PC 0x0c03db54 */
if(!s->budget--) { s->failed_pc=0x0c03db54u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[13],r[18],'+');
goto P_0c03db56;
P_0c03db56: /* original ff2a, guest PC 0x0c03db56 */
if(!s->budget--) { s->failed_pc=0x0c03db56u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c03db58;
P_0c03db58: /* original d34b, guest PC 0x0c03db58 */
if(!s->budget--) { s->failed_pc=0x0c03db58u; return 0; }
r[3]=read(ram,0x0c03dc88u,4);
goto P_0c03db5a;
P_0c03db5a: /* original 055a, guest PC 0x0c03db5a */
if(!s->budget--) { s->failed_pc=0x0c03db5au; return 0; }
r[5]=r[53];
goto P_0c03db5c;
P_0c03db5c: /* original ff3d, guest PC 0x0c03db5c */
if(!s->budget--) { s->failed_pc=0x0c03db5cu; return 0; }
r[53]=truncate_float(fr[15]);
goto P_0c03db5e;
P_0c03db5e: /* original 6032, guest PC 0x0c03db5e */
if(!s->budget--) { s->failed_pc=0x0c03db5eu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c03db60;
P_0c03db60: /* original 8804, guest PC 0x0c03db60 */
if(!s->budget--) { s->failed_pc=0x0c03db60u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c03db62;
P_0c03db62: /* original 8f0d, guest PC 0x0c03db62 */
if(!s->budget--) { s->failed_pc=0x0c03db62u; return 0; }
cond=r[17]&1u;
r[4]=r[53];
if(!cond) { goto P_0c03db80; }
goto P_0c03db66;
P_0c03db64: /* original 045a, guest PC 0x0c03db64 */
if(!s->budget--) { s->failed_pc=0x0c03db64u; return 0; }
r[4]=r[53];
goto P_0c03db66;
P_0c03db66: /* original f33d, guest PC 0x0c03db66 */
if(!s->budget--) { s->failed_pc=0x0c03db66u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03db68;
P_0c03db68: /* original 7f08, guest PC 0x0c03db68 */
if(!s->budget--) { s->failed_pc=0x0c03db68u; return 0; }
r[15]+=0x00000008u;
goto P_0c03db6a;
P_0c03db6a: /* original 4f26, guest PC 0x0c03db6a */
if(!s->budget--) { s->failed_pc=0x0c03db6au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03db6c;
P_0c03db6c: /* original d147, guest PC 0x0c03db6c */
if(!s->budget--) { s->failed_pc=0x0c03db6cu; return 0; }
r[1]=read(ram,0x0c03dc8cu,4);
goto P_0c03db6e;
P_0c03db6e: /* original 075a, guest PC 0x0c03db6e */
if(!s->budget--) { s->failed_pc=0x0c03db6eu; return 0; }
r[7]=r[53];
goto P_0c03db70;
P_0c03db70: /* original f23d, guest PC 0x0c03db70 */
if(!s->budget--) { s->failed_pc=0x0c03db70u; return 0; }
r[53]=truncate_float(fr[2]);
goto P_0c03db72;
P_0c03db72: /* original fcf9, guest PC 0x0c03db72 */
if(!s->budget--) { s->failed_pc=0x0c03db72u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03db74;
P_0c03db74: /* original fdf9, guest PC 0x0c03db74 */
if(!s->budget--) { s->failed_pc=0x0c03db74u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03db76;
P_0c03db76: /* original 065a, guest PC 0x0c03db76 */
if(!s->budget--) { s->failed_pc=0x0c03db76u; return 0; }
r[6]=r[53];
goto P_0c03db78;
P_0c03db78: /* original fef9, guest PC 0x0c03db78 */
if(!s->budget--) { s->failed_pc=0x0c03db78u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03db7a;
P_0c03db7a: /* original 412b, guest PC 0x0c03db7a */
if(!s->budget--) { s->failed_pc=0x0c03db7au; return 0; }
target=r[1];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c03db7c: /* original fff9, guest PC 0x0c03db7c */
if(!s->budget--) { s->failed_pc=0x0c03db7cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c03db7eu,s,ram);
P_0c03db80: /* original c743, guest PC 0x0c03db80 */
if(!s->budget--) { s->failed_pc=0x0c03db80u; return 0; }
r[0]=0x0c03dc90u;
goto P_0c03db82;
P_0c03db82: /* original f03c, guest PC 0x0c03db82 */
if(!s->budget--) { s->failed_pc=0x0c03db82u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c03db84;
P_0c03db84: /* original f108, guest PC 0x0c03db84 */
if(!s->budget--) { s->failed_pc=0x0c03db84u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c03db86;
P_0c03db86: /* original 7f08, guest PC 0x0c03db86 */
if(!s->budget--) { s->failed_pc=0x0c03db86u; return 0; }
r[15]+=0x00000008u;
goto P_0c03db88;
P_0c03db88: /* original 4f26, guest PC 0x0c03db88 */
if(!s->budget--) { s->failed_pc=0x0c03db88u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03db8a;
P_0c03db8a: /* original f010, guest PC 0x0c03db8a */
if(!s->budget--) { s->failed_pc=0x0c03db8au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'+');
goto P_0c03db8c;
P_0c03db8c: /* original d23f, guest PC 0x0c03db8c */
if(!s->budget--) { s->failed_pc=0x0c03db8cu; return 0; }
r[2]=read(ram,0x0c03dc8cu,4);
goto P_0c03db8e;
P_0c03db8e: /* original fcf9, guest PC 0x0c03db8e */
if(!s->budget--) { s->failed_pc=0x0c03db8eu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03db90;
P_0c03db90: /* original f03d, guest PC 0x0c03db90 */
if(!s->budget--) { s->failed_pc=0x0c03db90u; return 0; }
r[53]=truncate_float(fr[0]);
goto P_0c03db92;
P_0c03db92: /* original f02c, guest PC 0x0c03db92 */
if(!s->budget--) { s->failed_pc=0x0c03db92u; return 0; }
vf3_matrix_move(s,0,2);
goto P_0c03db94;
P_0c03db94: /* original f010, guest PC 0x0c03db94 */
if(!s->budget--) { s->failed_pc=0x0c03db94u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'+');
goto P_0c03db96;
P_0c03db96: /* original fdf9, guest PC 0x0c03db96 */
if(!s->budget--) { s->failed_pc=0x0c03db96u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03db98;
P_0c03db98: /* original fef9, guest PC 0x0c03db98 */
if(!s->budget--) { s->failed_pc=0x0c03db98u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03db9a;
P_0c03db9a: /* original 075a, guest PC 0x0c03db9a */
if(!s->budget--) { s->failed_pc=0x0c03db9au; return 0; }
r[7]=r[53];
goto P_0c03db9c;
P_0c03db9c: /* original f03d, guest PC 0x0c03db9c */
if(!s->budget--) { s->failed_pc=0x0c03db9cu; return 0; }
r[53]=truncate_float(fr[0]);
goto P_0c03db9e;
P_0c03db9e: /* original 065a, guest PC 0x0c03db9e */
if(!s->budget--) { s->failed_pc=0x0c03db9eu; return 0; }
r[6]=r[53];
goto P_0c03dba0;
P_0c03dba0: /* original 422b, guest PC 0x0c03dba0 */
if(!s->budget--) { s->failed_pc=0x0c03dba0u; return 0; }
target=r[2];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c03dba2: /* original fff9, guest PC 0x0c03dba2 */
if(!s->budget--) { s->failed_pc=0x0c03dba2u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c03dba4u,s,ram);
P_0c03ea22: /* original 4f22, guest PC 0x0c03ea22 */
if(!s->budget--) { s->failed_pc=0x0c03ea22u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03ea24;
P_0c03ea24: /* original d92c, guest PC 0x0c03ea24 */
if(!s->budget--) { s->failed_pc=0x0c03ea24u; return 0; }
r[9]=read(ram,0x0c03ead8u,4);
goto P_0c03ea26;
P_0c03ea26: /* original da2d, guest PC 0x0c03ea26 */
if(!s->budget--) { s->failed_pc=0x0c03ea26u; return 0; }
r[10]=read(ram,0x0c03eadcu,4);
goto P_0c03ea28;
P_0c03ea28: /* original 4f12, guest PC 0x0c03ea28 */
if(!s->budget--) { s->failed_pc=0x0c03ea28u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03ea2a;
P_0c03ea2a: /* original db2d, guest PC 0x0c03ea2a */
if(!s->budget--) { s->failed_pc=0x0c03ea2au; return 0; }
r[11]=read(ram,0x0c03eae0u,4);
goto P_0c03ea2c;
P_0c03ea2c: /* original d829, guest PC 0x0c03ea2c */
if(!s->budget--) { s->failed_pc=0x0c03ea2cu; return 0; }
r[8]=read(ram,0x0c03ead4u,4);
goto P_0c03ea2e;
P_0c03ea2e: /* original 9d4f, guest PC 0x0c03ea2e */
if(!s->budget--) { s->failed_pc=0x0c03ea2eu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03ead0u,2);
goto P_0c03ea30;
P_0c03ea30: /* original 60e3, guest PC 0x0c03ea30 */
if(!s->budget--) { s->failed_pc=0x0c03ea30u; return 0; }
r[0]=r[14];
goto P_0c03ea32;
P_0c03ea32: /* original 4008, guest PC 0x0c03ea32 */
if(!s->budget--) { s->failed_pc=0x0c03ea32u; return 0; }
r[0]<<=2;
goto P_0c03ea34;
P_0c03ea34: /* original 64e3, guest PC 0x0c03ea34 */
if(!s->budget--) { s->failed_pc=0x0c03ea34u; return 0; }
r[4]=r[14];
goto P_0c03ea36;
P_0c03ea36: /* original 2edf, guest PC 0x0c03ea36 */
if(!s->budget--) { s->failed_pc=0x0c03ea36u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[13]);
goto P_0c03ea38;
P_0c03ea38: /* original 4408, guest PC 0x0c03ea38 */
if(!s->budget--) { s->failed_pc=0x0c03ea38u; return 0; }
r[4]<<=2;
goto P_0c03ea3a;
P_0c03ea3a: /* original 6583, guest PC 0x0c03ea3a */
if(!s->budget--) { s->failed_pc=0x0c03ea3au; return 0; }
r[5]=r[8];
goto P_0c03ea3c;
P_0c03ea3c: /* original 4408, guest PC 0x0c03ea3c */
if(!s->budget--) { s->failed_pc=0x0c03ea3cu; return 0; }
r[4]<<=2;
goto P_0c03ea3e;
P_0c03ea3e: /* original 349c, guest PC 0x0c03ea3e */
if(!s->budget--) { s->failed_pc=0x0c03ea3eu; return 0; }
r[4]+=r[9];
goto P_0c03ea40;
P_0c03ea40: /* original 0d1a, guest PC 0x0c03ea40 */
if(!s->budget--) { s->failed_pc=0x0c03ea40u; return 0; }
r[13]=r[19];
goto P_0c03ea42;
P_0c03ea42: /* original 6ddf, guest PC 0x0c03ea42 */
if(!s->budget--) { s->failed_pc=0x0c03ea42u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c03ea44;
P_0c03ea44: /* original 3dac, guest PC 0x0c03ea44 */
if(!s->budget--) { s->failed_pc=0x0c03ea44u; return 0; }
r[13]+=r[10];
goto P_0c03ea46;
P_0c03ea46: /* original 63d1, guest PC 0x0c03ea46 */
if(!s->budget--) { s->failed_pc=0x0c03ea46u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[3]=tmp;
goto P_0c03ea48;
P_0c03ea48: /* original 0b36, guest PC 0x0c03ea48 */
if(!s->budget--) { s->failed_pc=0x0c03ea48u; return 0; }
write(ram,r[11]+r[0],r[3],4);
goto P_0c03ea4a;
P_0c03ea4a: /* original e014, guest PC 0x0c03ea4a */
if(!s->budget--) { s->failed_pc=0x0c03ea4au; return 0; }
r[0]=0x00000014u;
goto P_0c03ea4c;
P_0c03ea4c: /* original f3d6, guest PC 0x0c03ea4c */
if(!s->budget--) { s->failed_pc=0x0c03ea4cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03ea4e;
P_0c03ea4e: /* original e018, guest PC 0x0c03ea4e */
if(!s->budget--) { s->failed_pc=0x0c03ea4eu; return 0; }
r[0]=0x00000018u;
goto P_0c03ea50;
P_0c03ea50: /* original f43a, guest PC 0x0c03ea50 */
if(!s->budget--) { s->failed_pc=0x0c03ea50u; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c03ea52;
P_0c03ea52: /* original f3d6, guest PC 0x0c03ea52 */
if(!s->budget--) { s->failed_pc=0x0c03ea52u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03ea54;
P_0c03ea54: /* original e004, guest PC 0x0c03ea54 */
if(!s->budget--) { s->failed_pc=0x0c03ea54u; return 0; }
r[0]=0x00000004u;
goto P_0c03ea56;
P_0c03ea56: /* original f437, guest PC 0x0c03ea56 */
if(!s->budget--) { s->failed_pc=0x0c03ea56u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03ea58;
P_0c03ea58: /* original e01c, guest PC 0x0c03ea58 */
if(!s->budget--) { s->failed_pc=0x0c03ea58u; return 0; }
r[0]=0x0000001cu;
goto P_0c03ea5a;
P_0c03ea5a: /* original f3d6, guest PC 0x0c03ea5a */
if(!s->budget--) { s->failed_pc=0x0c03ea5au; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03ea5c;
P_0c03ea5c: /* original e008, guest PC 0x0c03ea5c */
if(!s->budget--) { s->failed_pc=0x0c03ea5cu; return 0; }
r[0]=0x00000008u;
goto P_0c03ea5e;
P_0c03ea5e: /* original f437, guest PC 0x0c03ea5e */
if(!s->budget--) { s->failed_pc=0x0c03ea5eu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03ea60;
P_0c03ea60: /* original e020, guest PC 0x0c03ea60 */
if(!s->budget--) { s->failed_pc=0x0c03ea60u; return 0; }
r[0]=0x00000020u;
goto P_0c03ea62;
P_0c03ea62: /* original f3d6, guest PC 0x0c03ea62 */
if(!s->budget--) { s->failed_pc=0x0c03ea62u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03ea64;
P_0c03ea64: /* original e00c, guest PC 0x0c03ea64 */
if(!s->budget--) { s->failed_pc=0x0c03ea64u; return 0; }
r[0]=0x0000000cu;
goto P_0c03ea66;
P_0c03ea66: /* original f437, guest PC 0x0c03ea66 */
if(!s->budget--) { s->failed_pc=0x0c03ea66u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03ea68;
P_0c03ea68: /* original befa, guest PC 0x0c03ea68 */
if(!s->budget--) { s->failed_pc=0x0c03ea68u; return 0; }
target=0x0c03e860u; r[16]=0x0c03ea6cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ea6cu) { target=s->pc; goto dispatch; }
goto P_0c03ea6c;
P_0c03ea6a: /* original 64e3, guest PC 0x0c03ea6a */
if(!s->budget--) { s->failed_pc=0x0c03ea6au; return 0; }
r[4]=r[14];
goto P_0c03ea6c;
P_0c03ea6c: /* original 2dc1, guest PC 0x0c03ea6c */
if(!s->budget--) { s->failed_pc=0x0c03ea6cu; return 0; }
write(ram,r[13],r[12],2);
goto P_0c03ea6e;
P_0c03ea6e: /* original 7e01, guest PC 0x0c03ea6e */
if(!s->budget--) { s->failed_pc=0x0c03ea6eu; return 0; }
r[14]+=0x00000001u;
goto P_0c03ea70;
P_0c03ea70: /* original 9d2e, guest PC 0x0c03ea70 */
if(!s->budget--) { s->failed_pc=0x0c03ea70u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03ead0u,2);
goto P_0c03ea72;
P_0c03ea72: /* original 60e3, guest PC 0x0c03ea72 */
if(!s->budget--) { s->failed_pc=0x0c03ea72u; return 0; }
r[0]=r[14];
goto P_0c03ea74;
P_0c03ea74: /* original 4008, guest PC 0x0c03ea74 */
if(!s->budget--) { s->failed_pc=0x0c03ea74u; return 0; }
r[0]<<=2;
goto P_0c03ea76;
P_0c03ea76: /* original 64e3, guest PC 0x0c03ea76 */
if(!s->budget--) { s->failed_pc=0x0c03ea76u; return 0; }
r[4]=r[14];
goto P_0c03ea78;
P_0c03ea78: /* original 2edf, guest PC 0x0c03ea78 */
if(!s->budget--) { s->failed_pc=0x0c03ea78u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[13]);
goto P_0c03ea7a;
P_0c03ea7a: /* original 4408, guest PC 0x0c03ea7a */
if(!s->budget--) { s->failed_pc=0x0c03ea7au; return 0; }
r[4]<<=2;
goto P_0c03ea7c;
P_0c03ea7c: /* original 6583, guest PC 0x0c03ea7c */
if(!s->budget--) { s->failed_pc=0x0c03ea7cu; return 0; }
r[5]=r[8];
goto P_0c03ea7e;
P_0c03ea7e: /* original 4408, guest PC 0x0c03ea7e */
if(!s->budget--) { s->failed_pc=0x0c03ea7eu; return 0; }
r[4]<<=2;
goto P_0c03ea80;
P_0c03ea80: /* original 349c, guest PC 0x0c03ea80 */
if(!s->budget--) { s->failed_pc=0x0c03ea80u; return 0; }
r[4]+=r[9];
goto P_0c03ea82;
P_0c03ea82: /* original 0d1a, guest PC 0x0c03ea82 */
if(!s->budget--) { s->failed_pc=0x0c03ea82u; return 0; }
r[13]=r[19];
goto P_0c03ea84;
P_0c03ea84: /* original 6ddf, guest PC 0x0c03ea84 */
if(!s->budget--) { s->failed_pc=0x0c03ea84u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c03ea86;
P_0c03ea86: /* original 3dac, guest PC 0x0c03ea86 */
if(!s->budget--) { s->failed_pc=0x0c03ea86u; return 0; }
r[13]+=r[10];
goto P_0c03ea88;
P_0c03ea88: /* original 63d1, guest PC 0x0c03ea88 */
if(!s->budget--) { s->failed_pc=0x0c03ea88u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[3]=tmp;
goto P_0c03ea8a;
P_0c03ea8a: /* original 0b36, guest PC 0x0c03ea8a */
if(!s->budget--) { s->failed_pc=0x0c03ea8au; return 0; }
write(ram,r[11]+r[0],r[3],4);
goto P_0c03ea8c;
P_0c03ea8c: /* original e014, guest PC 0x0c03ea8c */
if(!s->budget--) { s->failed_pc=0x0c03ea8cu; return 0; }
r[0]=0x00000014u;
goto P_0c03ea8e;
P_0c03ea8e: /* original f3d6, guest PC 0x0c03ea8e */
if(!s->budget--) { s->failed_pc=0x0c03ea8eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03ea90;
P_0c03ea90: /* original e018, guest PC 0x0c03ea90 */
if(!s->budget--) { s->failed_pc=0x0c03ea90u; return 0; }
r[0]=0x00000018u;
goto P_0c03ea92;
P_0c03ea92: /* original f43a, guest PC 0x0c03ea92 */
if(!s->budget--) { s->failed_pc=0x0c03ea92u; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c03ea94;
P_0c03ea94: /* original f3d6, guest PC 0x0c03ea94 */
if(!s->budget--) { s->failed_pc=0x0c03ea94u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03ea96;
P_0c03ea96: /* original e004, guest PC 0x0c03ea96 */
if(!s->budget--) { s->failed_pc=0x0c03ea96u; return 0; }
r[0]=0x00000004u;
goto P_0c03ea98;
P_0c03ea98: /* original f437, guest PC 0x0c03ea98 */
if(!s->budget--) { s->failed_pc=0x0c03ea98u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03ea9a;
P_0c03ea9a: /* original e01c, guest PC 0x0c03ea9a */
if(!s->budget--) { s->failed_pc=0x0c03ea9au; return 0; }
r[0]=0x0000001cu;
goto P_0c03ea9c;
P_0c03ea9c: /* original f3d6, guest PC 0x0c03ea9c */
if(!s->budget--) { s->failed_pc=0x0c03ea9cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03ea9e;
P_0c03ea9e: /* original e008, guest PC 0x0c03ea9e */
if(!s->budget--) { s->failed_pc=0x0c03ea9eu; return 0; }
r[0]=0x00000008u;
goto P_0c03eaa0;
P_0c03eaa0: /* original f437, guest PC 0x0c03eaa0 */
if(!s->budget--) { s->failed_pc=0x0c03eaa0u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03eaa2;
P_0c03eaa2: /* original e020, guest PC 0x0c03eaa2 */
if(!s->budget--) { s->failed_pc=0x0c03eaa2u; return 0; }
r[0]=0x00000020u;
goto P_0c03eaa4;
P_0c03eaa4: /* original f3d6, guest PC 0x0c03eaa4 */
if(!s->budget--) { s->failed_pc=0x0c03eaa4u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c03eaa6;
P_0c03eaa6: /* original e00c, guest PC 0x0c03eaa6 */
if(!s->budget--) { s->failed_pc=0x0c03eaa6u; return 0; }
r[0]=0x0000000cu;
goto P_0c03eaa8;
P_0c03eaa8: /* original f437, guest PC 0x0c03eaa8 */
if(!s->budget--) { s->failed_pc=0x0c03eaa8u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03eaaa;
P_0c03eaaa: /* original bed9, guest PC 0x0c03eaaa */
if(!s->budget--) { s->failed_pc=0x0c03eaaau; return 0; }
target=0x0c03e860u; r[16]=0x0c03eaaeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03eaaeu) { target=s->pc; goto dispatch; }
goto P_0c03eaae;
P_0c03eaac: /* original 64e3, guest PC 0x0c03eaac */
if(!s->budget--) { s->failed_pc=0x0c03eaacu; return 0; }
r[4]=r[14];
goto P_0c03eaae;
P_0c03eaae: /* original e210, guest PC 0x0c03eaae */
if(!s->budget--) { s->failed_pc=0x0c03eaaeu; return 0; }
r[2]=0x00000010u;
goto P_0c03eab0;
P_0c03eab0: /* original 7e01, guest PC 0x0c03eab0 */
if(!s->budget--) { s->failed_pc=0x0c03eab0u; return 0; }
r[14]+=0x00000001u;
goto P_0c03eab2;
P_0c03eab2: /* original 3e23, guest PC 0x0c03eab2 */
if(!s->budget--) { s->failed_pc=0x0c03eab2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c03eab4;
P_0c03eab4: /* original 8fbb, guest PC 0x0c03eab4 */
if(!s->budget--) { s->failed_pc=0x0c03eab4u; return 0; }
cond=r[17]&1u;
write(ram,r[13],r[12],2);
if(!cond) { goto P_0c03ea2e; }
goto P_0c03eab8;
P_0c03eab6: /* original 2dc1, guest PC 0x0c03eab6 */
if(!s->budget--) { s->failed_pc=0x0c03eab6u; return 0; }
write(ram,r[13],r[12],2);
goto P_0c03eab8;
P_0c03eab8: /* original 4f16, guest PC 0x0c03eab8 */
if(!s->budget--) { s->failed_pc=0x0c03eab8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03eaba;
P_0c03eaba: /* original d10a, guest PC 0x0c03eaba */
if(!s->budget--) { s->failed_pc=0x0c03eabau; return 0; }
r[1]=read(ram,0x0c03eae4u,4);
goto P_0c03eabc;
P_0c03eabc: /* original 4f26, guest PC 0x0c03eabc */
if(!s->budget--) { s->failed_pc=0x0c03eabcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03eabe;
P_0c03eabe: /* original 21c2, guest PC 0x0c03eabe */
if(!s->budget--) { s->failed_pc=0x0c03eabeu; return 0; }
write(ram,r[1],r[12],4);
goto P_0c03eac0;
P_0c03eac0: /* original 68f6, guest PC 0x0c03eac0 */
if(!s->budget--) { s->failed_pc=0x0c03eac0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03eac2;
P_0c03eac2: /* original 69f6, guest PC 0x0c03eac2 */
if(!s->budget--) { s->failed_pc=0x0c03eac2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03eac4;
P_0c03eac4: /* original 6af6, guest PC 0x0c03eac4 */
if(!s->budget--) { s->failed_pc=0x0c03eac4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03eac6;
P_0c03eac6: /* original 6bf6, guest PC 0x0c03eac6 */
if(!s->budget--) { s->failed_pc=0x0c03eac6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03eac8;
P_0c03eac8: /* original 6cf6, guest PC 0x0c03eac8 */
if(!s->budget--) { s->failed_pc=0x0c03eac8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03eaca;
P_0c03eaca: /* original 6df6, guest PC 0x0c03eaca */
if(!s->budget--) { s->failed_pc=0x0c03eacau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03eacc;
P_0c03eacc: /* original 000b, guest PC 0x0c03eacc */
if(!s->budget--) { s->failed_pc=0x0c03eaccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03eace: /* original 6ef6, guest PC 0x0c03eace */
if(!s->budget--) { s->failed_pc=0x0c03eaceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03ead0u,s,ram);
P_0c04baf6: /* original 4f22, guest PC 0x0c04baf6 */
if(!s->budget--) { s->failed_pc=0x0c04baf6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04baf8;
P_0c04baf8: /* original 901e, guest PC 0x0c04baf8 */
if(!s->budget--) { s->failed_pc=0x0c04baf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bb38u,2);
goto P_0c04bafa;
P_0c04bafa: /* original 3f0c, guest PC 0x0c04bafa */
if(!s->budget--) { s->failed_pc=0x0c04bafau; return 0; }
r[15]+=r[0];
goto P_0c04bafc;
P_0c04bafc: /* original 6bf3, guest PC 0x0c04bafc */
if(!s->budget--) { s->failed_pc=0x0c04bafcu; return 0; }
r[11]=r[15];
goto P_0c04bafe;
P_0c04bafe: /* original 1f51, guest PC 0x0c04bafe */
if(!s->budget--) { s->failed_pc=0x0c04bafeu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c04bb00;
P_0c04bb00: /* original 2f62, guest PC 0x0c04bb00 */
if(!s->budget--) { s->failed_pc=0x0c04bb00u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c04bb02;
P_0c04bb02: /* original e500, guest PC 0x0c04bb02 */
if(!s->budget--) { s->failed_pc=0x0c04bb02u; return 0; }
r[5]=0x00000000u;
goto P_0c04bb04;
P_0c04bb04: /* original 9a16, guest PC 0x0c04bb04 */
if(!s->budget--) { s->failed_pc=0x0c04bb04u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bb34u,2);
goto P_0c04bb06;
P_0c04bb06: /* original 7b08, guest PC 0x0c04bb06 */
if(!s->budget--) { s->failed_pc=0x0c04bb06u; return 0; }
r[11]+=0x00000008u;
goto P_0c04bb08;
P_0c04bb08: /* original d30e, guest PC 0x0c04bb08 */
if(!s->budget--) { s->failed_pc=0x0c04bb08u; return 0; }
r[3]=read(ram,0x0c04bb44u,4);
goto P_0c04bb0a;
P_0c04bb0a: /* original 66a3, guest PC 0x0c04bb0a */
if(!s->budget--) { s->failed_pc=0x0c04bb0au; return 0; }
r[6]=r[10];
goto P_0c04bb0c;
P_0c04bb0c: /* original 430b, guest PC 0x0c04bb0c */
if(!s->budget--) { s->failed_pc=0x0c04bb0cu; return 0; }
target=r[3];
r[16]=0x0c04bb10u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04bb10u) { target=s->pc; goto dispatch; }
goto P_0c04bb10;
P_0c04bb0e: /* original 64b3, guest PC 0x0c04bb0e */
if(!s->budget--) { s->failed_pc=0x0c04bb0eu; return 0; }
r[4]=r[11];
goto P_0c04bb10;
P_0c04bb10: /* original 900d, guest PC 0x0c04bb10 */
if(!s->budget--) { s->failed_pc=0x0c04bb10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bb2eu,2);
goto P_0c04bb12;
P_0c04bb12: /* original 02de, guest PC 0x0c04bb12 */
if(!s->budget--) { s->failed_pc=0x0c04bb12u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c04bb14;
P_0c04bb14: /* original 7004, guest PC 0x0c04bb14 */
if(!s->budget--) { s->failed_pc=0x0c04bb14u; return 0; }
r[0]+=0x00000004u;
goto P_0c04bb16;
P_0c04bb16: /* original 03de, guest PC 0x0c04bb16 */
if(!s->budget--) { s->failed_pc=0x0c04bb16u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c04bb18;
P_0c04bb18: /* original 3320, guest PC 0x0c04bb18 */
if(!s->budget--) { s->failed_pc=0x0c04bb18u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c04bb1a;
P_0c04bb1a: /* original 8b01, guest PC 0x0c04bb1a */
if(!s->budget--) { s->failed_pc=0x0c04bb1au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04bb20; }
goto P_0c04bb1c;
P_0c04bb1c: /* original a049, guest PC 0x0c04bb1c */
if(!s->budget--) { s->failed_pc=0x0c04bb1cu; return 0; }
r[0]=0xffffffffu;
goto P_0c04bbb2;
P_0c04bb1e: /* original e0ff, guest PC 0x0c04bb1e */
if(!s->budget--) { s->failed_pc=0x0c04bb1eu; return 0; }
r[0]=0xffffffffu;
goto P_0c04bb20;
P_0c04bb20: /* original 9e07, guest PC 0x0c04bb20 */
if(!s->budget--) { s->failed_pc=0x0c04bb20u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bb32u,2);
goto P_0c04bb22;
P_0c04bb22: /* original e400, guest PC 0x0c04bb22 */
if(!s->budget--) { s->failed_pc=0x0c04bb22u; return 0; }
r[4]=0x00000000u;
goto P_0c04bb24;
P_0c04bb24: /* original 6c43, guest PC 0x0c04bb24 */
if(!s->budget--) { s->failed_pc=0x0c04bb24u; return 0; }
r[12]=r[4];
goto P_0c04bb26;
P_0c04bb26: /* original a01a, guest PC 0x0c04bb26 */
if(!s->budget--) { s->failed_pc=0x0c04bb26u; return 0; }
r[14]+=r[13];
goto P_0c04bb5e;
P_0c04bb28: /* original 3edc, guest PC 0x0c04bb28 */
if(!s->budget--) { s->failed_pc=0x0c04bb28u; return 0; }
r[14]+=r[13];
return vf3_matrix_family(0x0c04bb2au,s,ram);
P_0c04bb58: /* original 9283, guest PC 0x0c04bb58 */
if(!s->budget--) { s->failed_pc=0x0c04bb58u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc62u,2);
goto P_0c04bb5a;
P_0c04bb5a: /* original 7c01, guest PC 0x0c04bb5a */
if(!s->budget--) { s->failed_pc=0x0c04bb5au; return 0; }
r[12]+=0x00000001u;
goto P_0c04bb5c;
P_0c04bb5c: /* original 3e2c, guest PC 0x0c04bb5c */
if(!s->budget--) { s->failed_pc=0x0c04bb5cu; return 0; }
r[14]+=r[2];
goto P_0c04bb5e;
P_0c04bb5e: /* original 53e3, guest PC 0x0c04bb5e */
if(!s->budget--) { s->failed_pc=0x0c04bb5eu; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c04bb60;
P_0c04bb60: /* original 2338, guest PC 0x0c04bb60 */
if(!s->budget--) { s->failed_pc=0x0c04bb60u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04bb62;
P_0c04bb62: /* original 8bf9, guest PC 0x0c04bb62 */
if(!s->budget--) { s->failed_pc=0x0c04bb62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04bb58; }
goto P_0c04bb64;
P_0c04bb64: /* original e301, guest PC 0x0c04bb64 */
if(!s->budget--) { s->failed_pc=0x0c04bb64u; return 0; }
r[3]=0x00000001u;
goto P_0c04bb66;
P_0c04bb66: /* original 1e42, guest PC 0x0c04bb66 */
if(!s->budget--) { s->failed_pc=0x0c04bb66u; return 0; }
write(ram,r[14]+8,r[4],4);
goto P_0c04bb68;
P_0c04bb68: /* original 1e33, guest PC 0x0c04bb68 */
if(!s->budget--) { s->failed_pc=0x0c04bb68u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c04bb6a;
P_0c04bb6a: /* original 4909, guest PC 0x0c04bb6a */
if(!s->budget--) { s->failed_pc=0x0c04bb6au; return 0; }
r[9]>>=2;
goto P_0c04bb6c;
P_0c04bb6c: /* original 907a, guest PC 0x0c04bb6c */
if(!s->budget--) { s->failed_pc=0x0c04bb6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc64u,2);
goto P_0c04bb6e;
P_0c04bb6e: /* original 66a3, guest PC 0x0c04bb6e */
if(!s->budget--) { s->failed_pc=0x0c04bb6eu; return 0; }
r[6]=r[10];
goto P_0c04bb70;
P_0c04bb70: /* original 02de, guest PC 0x0c04bb70 */
if(!s->budget--) { s->failed_pc=0x0c04bb70u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c04bb72;
P_0c04bb72: /* original 1e25, guest PC 0x0c04bb72 */
if(!s->budget--) { s->failed_pc=0x0c04bb72u; return 0; }
write(ram,r[14]+20,r[2],4);
goto P_0c04bb74;
P_0c04bb74: /* original 63f2, guest PC 0x0c04bb74 */
if(!s->budget--) { s->failed_pc=0x0c04bb74u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c04bb76;
P_0c04bb76: /* original 2e32, guest PC 0x0c04bb76 */
if(!s->budget--) { s->failed_pc=0x0c04bb76u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c04bb78;
P_0c04bb78: /* original 1e91, guest PC 0x0c04bb78 */
if(!s->budget--) { s->failed_pc=0x0c04bb78u; return 0; }
write(ram,r[14]+4,r[9],4);
goto P_0c04bb7a;
P_0c04bb7a: /* original 9074, guest PC 0x0c04bb7a */
if(!s->budget--) { s->failed_pc=0x0c04bb7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc66u,2);
goto P_0c04bb7c;
P_0c04bb7c: /* original 0e46, guest PC 0x0c04bb7c */
if(!s->budget--) { s->failed_pc=0x0c04bb7cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c04bb7e;
P_0c04bb7e: /* original 7004, guest PC 0x0c04bb7e */
if(!s->budget--) { s->failed_pc=0x0c04bb7eu; return 0; }
r[0]+=0x00000004u;
goto P_0c04bb80;
P_0c04bb80: /* original 1e44, guest PC 0x0c04bb80 */
if(!s->budget--) { s->failed_pc=0x0c04bb80u; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c04bb82;
P_0c04bb82: /* original 0e46, guest PC 0x0c04bb82 */
if(!s->budget--) { s->failed_pc=0x0c04bb82u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c04bb84;
P_0c04bb84: /* original 64e3, guest PC 0x0c04bb84 */
if(!s->budget--) { s->failed_pc=0x0c04bb84u; return 0; }
r[4]=r[14];
goto P_0c04bb86;
P_0c04bb86: /* original 956f, guest PC 0x0c04bb86 */
if(!s->budget--) { s->failed_pc=0x0c04bb86u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc68u,2);
goto P_0c04bb88;
P_0c04bb88: /* original d33b, guest PC 0x0c04bb88 */
if(!s->budget--) { s->failed_pc=0x0c04bb88u; return 0; }
r[3]=read(ram,0x0c04bc78u,4);
goto P_0c04bb8a;
P_0c04bb8a: /* original 35dc, guest PC 0x0c04bb8a */
if(!s->budget--) { s->failed_pc=0x0c04bb8au; return 0; }
r[5]+=r[13];
goto P_0c04bb8c;
P_0c04bb8c: /* original 430b, guest PC 0x0c04bb8c */
if(!s->budget--) { s->failed_pc=0x0c04bb8cu; return 0; }
target=r[3];
r[16]=0x0c04bb90u;
r[4]+=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04bb90u) { target=s->pc; goto dispatch; }
goto P_0c04bb90;
P_0c04bb8e: /* original 7418, guest PC 0x0c04bb8e */
if(!s->budget--) { s->failed_pc=0x0c04bb8eu; return 0; }
r[4]+=0x00000018u;
goto P_0c04bb90;
P_0c04bb90: /* original d23a, guest PC 0x0c04bb90 */
if(!s->budget--) { s->failed_pc=0x0c04bb90u; return 0; }
r[2]=read(ram,0x0c04bc7cu,4);
goto P_0c04bb92;
P_0c04bb92: /* original 420b, guest PC 0x0c04bb92 */
if(!s->budget--) { s->failed_pc=0x0c04bb92u; return 0; }
target=r[2];
r[16]=0x0c04bb96u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04bb96u) { target=s->pc; goto dispatch; }
goto P_0c04bb96;
P_0c04bb94: /* original 64b3, guest PC 0x0c04bb94 */
if(!s->budget--) { s->failed_pc=0x0c04bb94u; return 0; }
r[4]=r[11];
goto P_0c04bb96;
P_0c04bb96: /* original d338, guest PC 0x0c04bb96 */
if(!s->budget--) { s->failed_pc=0x0c04bb96u; return 0; }
r[3]=read(ram,0x0c04bc78u,4);
goto P_0c04bb98;
P_0c04bb98: /* original 64e3, guest PC 0x0c04bb98 */
if(!s->budget--) { s->failed_pc=0x0c04bb98u; return 0; }
r[4]=r[14];
goto P_0c04bb9a;
P_0c04bb9a: /* original 66a3, guest PC 0x0c04bb9a */
if(!s->budget--) { s->failed_pc=0x0c04bb9au; return 0; }
r[6]=r[10];
goto P_0c04bb9c;
P_0c04bb9c: /* original 65b3, guest PC 0x0c04bb9c */
if(!s->budget--) { s->failed_pc=0x0c04bb9cu; return 0; }
r[5]=r[11];
goto P_0c04bb9e;
P_0c04bb9e: /* original 430b, guest PC 0x0c04bb9e */
if(!s->budget--) { s->failed_pc=0x0c04bb9eu; return 0; }
target=r[3];
r[16]=0x0c04bba2u;
r[4]+=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04bba2u) { target=s->pc; goto dispatch; }
goto P_0c04bba2;
P_0c04bba0: /* original 7418, guest PC 0x0c04bba0 */
if(!s->budget--) { s->failed_pc=0x0c04bba0u; return 0; }
r[4]+=0x00000018u;
goto P_0c04bba2;
P_0c04bba2: /* original 62f2, guest PC 0x0c04bba2 */
if(!s->budget--) { s->failed_pc=0x0c04bba2u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04bba4;
P_0c04bba4: /* original 79ff, guest PC 0x0c04bba4 */
if(!s->budget--) { s->failed_pc=0x0c04bba4u; return 0; }
r[9]+=0xffffffffu;
goto P_0c04bba6;
P_0c04bba6: /* original 4908, guest PC 0x0c04bba6 */
if(!s->budget--) { s->failed_pc=0x0c04bba6u; return 0; }
r[9]<<=2;
goto P_0c04bba8;
P_0c04bba8: /* original 60c3, guest PC 0x0c04bba8 */
if(!s->budget--) { s->failed_pc=0x0c04bba8u; return 0; }
r[0]=r[12];
goto P_0c04bbaa;
P_0c04bbaa: /* original 392c, guest PC 0x0c04bbaa */
if(!s->budget--) { s->failed_pc=0x0c04bbaau; return 0; }
r[9]+=r[2];
goto P_0c04bbac;
P_0c04bbac: /* original 1e96, guest PC 0x0c04bbac */
if(!s->budget--) { s->failed_pc=0x0c04bbacu; return 0; }
write(ram,r[14]+24,r[9],4);
goto P_0c04bbae;
P_0c04bbae: /* original 53f1, guest PC 0x0c04bbae */
if(!s->budget--) { s->failed_pc=0x0c04bbaeu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c04bbb0;
P_0c04bbb0: /* original 1e38, guest PC 0x0c04bbb0 */
if(!s->budget--) { s->failed_pc=0x0c04bbb0u; return 0; }
write(ram,r[14]+32,r[3],4);
goto P_0c04bbb2;
P_0c04bbb2: /* original 915a, guest PC 0x0c04bbb2 */
if(!s->budget--) { s->failed_pc=0x0c04bbb2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc6au,2);
goto P_0c04bbb4;
P_0c04bbb4: /* original 3f1c, guest PC 0x0c04bbb4 */
if(!s->budget--) { s->failed_pc=0x0c04bbb4u; return 0; }
r[15]+=r[1];
goto P_0c04bbb6;
P_0c04bbb6: /* original 4f26, guest PC 0x0c04bbb6 */
if(!s->budget--) { s->failed_pc=0x0c04bbb6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04bbb8;
P_0c04bbb8: /* original 69f6, guest PC 0x0c04bbb8 */
if(!s->budget--) { s->failed_pc=0x0c04bbb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04bbba;
P_0c04bbba: /* original 6af6, guest PC 0x0c04bbba */
if(!s->budget--) { s->failed_pc=0x0c04bbbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04bbbc;
P_0c04bbbc: /* original 6bf6, guest PC 0x0c04bbbc */
if(!s->budget--) { s->failed_pc=0x0c04bbbcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04bbbe;
P_0c04bbbe: /* original 6cf6, guest PC 0x0c04bbbe */
if(!s->budget--) { s->failed_pc=0x0c04bbbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04bbc0;
P_0c04bbc0: /* original 6df6, guest PC 0x0c04bbc0 */
if(!s->budget--) { s->failed_pc=0x0c04bbc0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04bbc2;
P_0c04bbc2: /* original 000b, guest PC 0x0c04bbc2 */
if(!s->budget--) { s->failed_pc=0x0c04bbc2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04bbc4: /* original 6ef6, guest PC 0x0c04bbc4 */
if(!s->budget--) { s->failed_pc=0x0c04bbc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04bbc6u,s,ram);
P_0c05e46c: /* original 2fe6, guest PC 0x0c05e46c */
if(!s->budget--) { s->failed_pc=0x0c05e46cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05e46e;
P_0c05e46e: /* original 3467, guest PC 0x0c05e46e */
if(!s->budget--) { s->failed_pc=0x0c05e46eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[6])!=0);
goto P_0c05e470;
P_0c05e470: /* original 8901, guest PC 0x0c05e470 */
if(!s->budget--) { s->failed_pc=0x0c05e470u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05e476; }
goto P_0c05e472;
P_0c05e472: /* original 3577, guest PC 0x0c05e472 */
if(!s->budget--) { s->failed_pc=0x0c05e472u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[7])!=0);
goto P_0c05e474;
P_0c05e474: /* original 8b02, guest PC 0x0c05e474 */
if(!s->budget--) { s->failed_pc=0x0c05e474u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e47c; }
goto P_0c05e476;
P_0c05e476: /* original d02d, guest PC 0x0c05e476 */
if(!s->budget--) { s->failed_pc=0x0c05e476u; return 0; }
r[0]=read(ram,0x0c05e52cu,4);
goto P_0c05e478;
P_0c05e478: /* original 000b, guest PC 0x0c05e478 */
if(!s->budget--) { s->failed_pc=0x0c05e478u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05e47a: /* original 6ef6, guest PC 0x0c05e47a */
if(!s->budget--) { s->failed_pc=0x0c05e47au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c05e47c;
P_0c05e47c: /* original 9e4b, guest PC 0x0c05e47c */
if(!s->budget--) { s->failed_pc=0x0c05e47cu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e516u,2);
goto P_0c05e47e;
P_0c05e47e: /* original 36e7, guest PC 0x0c05e47e */
if(!s->budget--) { s->failed_pc=0x0c05e47eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[14])!=0);
goto P_0c05e480;
P_0c05e480: /* original 8b00, guest PC 0x0c05e480 */
if(!s->budget--) { s->failed_pc=0x0c05e480u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e484; }
goto P_0c05e482;
P_0c05e482: /* original 66e3, guest PC 0x0c05e482 */
if(!s->budget--) { s->failed_pc=0x0c05e482u; return 0; }
r[6]=r[14];
goto P_0c05e484;
P_0c05e484: /* original 37e7, guest PC 0x0c05e484 */
if(!s->budget--) { s->failed_pc=0x0c05e484u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>(int32_t)r[14])!=0);
goto P_0c05e486;
P_0c05e486: /* original 8b00, guest PC 0x0c05e486 */
if(!s->budget--) { s->failed_pc=0x0c05e486u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e48a; }
goto P_0c05e488;
P_0c05e488: /* original 67e3, guest PC 0x0c05e488 */
if(!s->budget--) { s->failed_pc=0x0c05e488u; return 0; }
r[7]=r[14];
goto P_0c05e48a;
P_0c05e48a: /* original d229, guest PC 0x0c05e48a */
if(!s->budget--) { s->failed_pc=0x0c05e48au; return 0; }
r[2]=read(ram,0x0c05e530u,4);
goto P_0c05e48c;
P_0c05e48c: /* original 6022, guest PC 0x0c05e48c */
if(!s->budget--) { s->failed_pc=0x0c05e48cu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05e48e;
P_0c05e48e: /* original 8804, guest PC 0x0c05e48e */
if(!s->budget--) { s->failed_pc=0x0c05e48eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c05e490;
P_0c05e490: /* original 8b0a, guest PC 0x0c05e490 */
if(!s->budget--) { s->failed_pc=0x0c05e490u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e4a8; }
goto P_0c05e492;
P_0c05e492: /* original e0fe, guest PC 0x0c05e492 */
if(!s->budget--) { s->failed_pc=0x0c05e492u; return 0; }
r[0]=0xfffffffeu;
goto P_0c05e494;
P_0c05e494: /* original 6143, guest PC 0x0c05e494 */
if(!s->budget--) { s->failed_pc=0x0c05e494u; return 0; }
r[1]=r[4];
goto P_0c05e496;
P_0c05e496: /* original 7101, guest PC 0x0c05e496 */
if(!s->budget--) { s->failed_pc=0x0c05e496u; return 0; }
r[1]+=0x00000001u;
goto P_0c05e498;
P_0c05e498: /* original 6413, guest PC 0x0c05e498 */
if(!s->budget--) { s->failed_pc=0x0c05e498u; return 0; }
r[4]=r[1];
goto P_0c05e49a;
P_0c05e49a: /* original 2409, guest PC 0x0c05e49a */
if(!s->budget--) { s->failed_pc=0x0c05e49au; return 0; }
r[4]&=r[0];
goto P_0c05e49c;
P_0c05e49c: /* original 6353, guest PC 0x0c05e49c */
if(!s->budget--) { s->failed_pc=0x0c05e49cu; return 0; }
r[3]=r[5];
goto P_0c05e49e;
P_0c05e49e: /* original 7301, guest PC 0x0c05e49e */
if(!s->budget--) { s->failed_pc=0x0c05e49eu; return 0; }
r[3]+=0x00000001u;
goto P_0c05e4a0;
P_0c05e4a0: /* original 6533, guest PC 0x0c05e4a0 */
if(!s->budget--) { s->failed_pc=0x0c05e4a0u; return 0; }
r[5]=r[3];
goto P_0c05e4a2;
P_0c05e4a2: /* original 2509, guest PC 0x0c05e4a2 */
if(!s->budget--) { s->failed_pc=0x0c05e4a2u; return 0; }
r[5]&=r[0];
goto P_0c05e4a4;
P_0c05e4a4: /* original 2609, guest PC 0x0c05e4a4 */
if(!s->budget--) { s->failed_pc=0x0c05e4a4u; return 0; }
r[6]&=r[0];
goto P_0c05e4a6;
P_0c05e4a6: /* original 2709, guest PC 0x0c05e4a6 */
if(!s->budget--) { s->failed_pc=0x0c05e4a6u; return 0; }
r[7]&=r[0];
goto P_0c05e4a8;
P_0c05e4a8: /* original d222, guest PC 0x0c05e4a8 */
if(!s->budget--) { s->failed_pc=0x0c05e4a8u; return 0; }
r[2]=read(ram,0x0c05e534u,4);
goto P_0c05e4aa;
P_0c05e4aa: /* original 26e9, guest PC 0x0c05e4aa */
if(!s->budget--) { s->failed_pc=0x0c05e4aau; return 0; }
r[6]&=r[14];
goto P_0c05e4ac;
P_0c05e4ac: /* original 4628, guest PC 0x0c05e4ac */
if(!s->budget--) { s->failed_pc=0x0c05e4acu; return 0; }
r[6]<<=16;
goto P_0c05e4ae;
P_0c05e4ae: /* original 24e9, guest PC 0x0c05e4ae */
if(!s->budget--) { s->failed_pc=0x0c05e4aeu; return 0; }
r[4]&=r[14];
goto P_0c05e4b0;
P_0c05e4b0: /* original 246b, guest PC 0x0c05e4b0 */
if(!s->budget--) { s->failed_pc=0x0c05e4b0u; return 0; }
r[4]|=r[6];
goto P_0c05e4b2;
P_0c05e4b2: /* original 2242, guest PC 0x0c05e4b2 */
if(!s->budget--) { s->failed_pc=0x0c05e4b2u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c05e4b4;
P_0c05e4b4: /* original d320, guest PC 0x0c05e4b4 */
if(!s->budget--) { s->failed_pc=0x0c05e4b4u; return 0; }
r[3]=read(ram,0x0c05e538u,4);
goto P_0c05e4b6;
P_0c05e4b6: /* original 6473, guest PC 0x0c05e4b6 */
if(!s->budget--) { s->failed_pc=0x0c05e4b6u; return 0; }
r[4]=r[7];
goto P_0c05e4b8;
P_0c05e4b8: /* original 24e9, guest PC 0x0c05e4b8 */
if(!s->budget--) { s->failed_pc=0x0c05e4b8u; return 0; }
r[4]&=r[14];
goto P_0c05e4ba;
P_0c05e4ba: /* original 4428, guest PC 0x0c05e4ba */
if(!s->budget--) { s->failed_pc=0x0c05e4bau; return 0; }
r[4]<<=16;
goto P_0c05e4bc;
P_0c05e4bc: /* original 25e9, guest PC 0x0c05e4bc */
if(!s->budget--) { s->failed_pc=0x0c05e4bcu; return 0; }
r[5]&=r[14];
goto P_0c05e4be;
P_0c05e4be: /* original 245b, guest PC 0x0c05e4be */
if(!s->budget--) { s->failed_pc=0x0c05e4beu; return 0; }
r[4]|=r[5];
goto P_0c05e4c0;
P_0c05e4c0: /* original 2342, guest PC 0x0c05e4c0 */
if(!s->budget--) { s->failed_pc=0x0c05e4c0u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c05e4c2;
P_0c05e4c2: /* original e000, guest PC 0x0c05e4c2 */
if(!s->budget--) { s->failed_pc=0x0c05e4c2u; return 0; }
r[0]=0x00000000u;
goto P_0c05e4c4;
P_0c05e4c4: /* original 000b, guest PC 0x0c05e4c4 */
if(!s->budget--) { s->failed_pc=0x0c05e4c4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05e4c6: /* original 6ef6, guest PC 0x0c05e4c6 */
if(!s->budget--) { s->failed_pc=0x0c05e4c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c05e4c8u,s,ram);
P_0c06c406: /* original 4f22, guest PC 0x0c06c406 */
if(!s->budget--) { s->failed_pc=0x0c06c406u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c408;
P_0c06c408: /* original 53f1, guest PC 0x0c06c408 */
if(!s->budget--) { s->failed_pc=0x0c06c408u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06c40a;
P_0c06c40a: /* original 2f36, guest PC 0x0c06c40a */
if(!s->budget--) { s->failed_pc=0x0c06c40au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c40c;
P_0c06c40c: /* original 2f76, guest PC 0x0c06c40c */
if(!s->budget--) { s->failed_pc=0x0c06c40cu; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c40e;
P_0c06c40e: /* original 2f66, guest PC 0x0c06c40e */
if(!s->budget--) { s->failed_pc=0x0c06c40eu; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c410;
P_0c06c410: /* original 2f56, guest PC 0x0c06c410 */
if(!s->budget--) { s->failed_pc=0x0c06c410u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c412;
P_0c06c412: /* original d31e, guest PC 0x0c06c412 */
if(!s->budget--) { s->failed_pc=0x0c06c412u; return 0; }
r[3]=read(ram,0x0c06c48cu,4);
goto P_0c06c414;
P_0c06c414: /* original d21e, guest PC 0x0c06c414 */
if(!s->budget--) { s->failed_pc=0x0c06c414u; return 0; }
r[2]=read(ram,0x0c06c490u,4);
goto P_0c06c416;
P_0c06c416: /* original 420b, guest PC 0x0c06c416 */
if(!s->budget--) { s->failed_pc=0x0c06c416u; return 0; }
target=r[2];
r[16]=0x0c06c41au;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06c41au) { target=s->pc; goto dispatch; }
goto P_0c06c41a;
P_0c06c418: /* original 2f36, guest PC 0x0c06c418 */
if(!s->budget--) { s->failed_pc=0x0c06c418u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c41a;
P_0c06c41a: /* original 7f14, guest PC 0x0c06c41a */
if(!s->budget--) { s->failed_pc=0x0c06c41au; return 0; }
r[15]+=0x00000014u;
goto P_0c06c41c;
P_0c06c41c: /* original 4f26, guest PC 0x0c06c41c */
if(!s->budget--) { s->failed_pc=0x0c06c41cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c41e;
P_0c06c41e: /* original 000b, guest PC 0x0c06c41e */
if(!s->budget--) { s->failed_pc=0x0c06c41eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06c420: /* original 0009, guest PC 0x0c06c420 */
if(!s->budget--) { s->failed_pc=0x0c06c420u; return 0; }
return vf3_matrix_family(0x0c06c422u,s,ram);
P_0c06c6d6: /* original 4f22, guest PC 0x0c06c6d6 */
if(!s->budget--) { s->failed_pc=0x0c06c6d6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c6d8;
P_0c06c6d8: /* original bf76, guest PC 0x0c06c6d8 */
if(!s->budget--) { s->failed_pc=0x0c06c6d8u; return 0; }
target=0x0c06c5c8u; r[16]=0x0c06c6dcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06c6dcu) { target=s->pc; goto dispatch; }
goto P_0c06c6dc;
P_0c06c6da: /* original 0009, guest PC 0x0c06c6da */
if(!s->budget--) { s->failed_pc=0x0c06c6dau; return 0; }
goto P_0c06c6dc;
P_0c06c6dc: /* original a020, guest PC 0x0c06c6dc */
if(!s->budget--) { s->failed_pc=0x0c06c6dcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c720;
P_0c06c6de: /* original 4f26, guest PC 0x0c06c6de */
if(!s->budget--) { s->failed_pc=0x0c06c6deu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c06c6e0u,s,ram);
P_0c06c720: /* original 2fe6, guest PC 0x0c06c720 */
if(!s->budget--) { s->failed_pc=0x0c06c720u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c722;
P_0c06c722: /* original 9053, guest PC 0x0c06c722 */
if(!s->budget--) { s->failed_pc=0x0c06c722u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7ccu,2);
goto P_0c06c724;
P_0c06c724: /* original 7ffc, guest PC 0x0c06c724 */
if(!s->budget--) { s->failed_pc=0x0c06c724u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c726;
P_0c06c726: /* original de2c, guest PC 0x0c06c726 */
if(!s->budget--) { s->failed_pc=0x0c06c726u; return 0; }
r[14]=read(ram,0x0c06c7d8u,4);
goto P_0c06c728;
P_0c06c728: /* original 00ec, guest PC 0x0c06c728 */
if(!s->budget--) { s->failed_pc=0x0c06c728u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c72a;
P_0c06c72a: /* original 8801, guest PC 0x0c06c72a */
if(!s->budget--) { s->failed_pc=0x0c06c72au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c72c;
P_0c06c72c: /* original 8d12, guest PC 0x0c06c72c */
if(!s->budget--) { s->failed_pc=0x0c06c72cu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c06c754; }
goto P_0c06c730;
P_0c06c72e: /* original 6403, guest PC 0x0c06c72e */
if(!s->budget--) { s->failed_pc=0x0c06c72eu; return 0; }
r[4]=r[0];
goto P_0c06c730;
P_0c06c730: /* original 904d, guest PC 0x0c06c730 */
if(!s->budget--) { s->failed_pc=0x0c06c730u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7ceu,2);
goto P_0c06c732;
P_0c06c732: /* original 04ec, guest PC 0x0c06c732 */
if(!s->budget--) { s->failed_pc=0x0c06c732u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c734;
P_0c06c734: /* original 70ff, guest PC 0x0c06c734 */
if(!s->budget--) { s->failed_pc=0x0c06c734u; return 0; }
r[0]+=0xffffffffu;
goto P_0c06c736;
P_0c06c736: /* original 03ec, guest PC 0x0c06c736 */
if(!s->budget--) { s->failed_pc=0x0c06c736u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c738;
P_0c06c738: /* original 2338, guest PC 0x0c06c738 */
if(!s->budget--) { s->failed_pc=0x0c06c738u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06c73a;
P_0c06c73a: /* original 8f02, guest PC 0x0c06c73a */
if(!s->budget--) { s->failed_pc=0x0c06c73au; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c06c742; }
goto P_0c06c73e;
P_0c06c73c: /* original 2f32, guest PC 0x0c06c73c */
if(!s->budget--) { s->failed_pc=0x0c06c73cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c73e;
P_0c06c73e: /* original 2448, guest PC 0x0c06c73e */
if(!s->budget--) { s->failed_pc=0x0c06c73eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06c740;
P_0c06c740: /* original 890c, guest PC 0x0c06c740 */
if(!s->budget--) { s->failed_pc=0x0c06c740u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c75c; }
goto P_0c06c742;
P_0c06c742: /* original 9045, guest PC 0x0c06c742 */
if(!s->budget--) { s->failed_pc=0x0c06c742u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d0u,2);
goto P_0c06c744;
P_0c06c744: /* original 63f2, guest PC 0x0c06c744 */
if(!s->budget--) { s->failed_pc=0x0c06c744u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06c746;
P_0c06c746: /* original 04ec, guest PC 0x0c06c746 */
if(!s->budget--) { s->failed_pc=0x0c06c746u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c748;
P_0c06c748: /* original 3342, guest PC 0x0c06c748 */
if(!s->budget--) { s->failed_pc=0x0c06c748u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[4])!=0);
goto P_0c06c74a;
P_0c06c74a: /* original 8903, guest PC 0x0c06c74a */
if(!s->budget--) { s->failed_pc=0x0c06c74au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c754; }
goto P_0c06c74c;
P_0c06c74c: /* original 9041, guest PC 0x0c06c74c */
if(!s->budget--) { s->failed_pc=0x0c06c74cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d2u,2);
goto P_0c06c74e;
P_0c06c74e: /* original e102, guest PC 0x0c06c74e */
if(!s->budget--) { s->failed_pc=0x0c06c74eu; return 0; }
r[1]=0x00000002u;
goto P_0c06c750;
P_0c06c750: /* original a007, guest PC 0x0c06c750 */
if(!s->budget--) { s->failed_pc=0x0c06c750u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c06c762;
P_0c06c752: /* original 0e14, guest PC 0x0c06c752 */
if(!s->budget--) { s->failed_pc=0x0c06c752u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c06c754;
P_0c06c754: /* original 903d, guest PC 0x0c06c754 */
if(!s->budget--) { s->failed_pc=0x0c06c754u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d2u,2);
goto P_0c06c756;
P_0c06c756: /* original e303, guest PC 0x0c06c756 */
if(!s->budget--) { s->failed_pc=0x0c06c756u; return 0; }
r[3]=0x00000003u;
goto P_0c06c758;
P_0c06c758: /* original a003, guest PC 0x0c06c758 */
if(!s->budget--) { s->failed_pc=0x0c06c758u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06c762;
P_0c06c75a: /* original 0e34, guest PC 0x0c06c75a */
if(!s->budget--) { s->failed_pc=0x0c06c75au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06c75c;
P_0c06c75c: /* original 9039, guest PC 0x0c06c75c */
if(!s->budget--) { s->failed_pc=0x0c06c75cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d2u,2);
goto P_0c06c75e;
P_0c06c75e: /* original e101, guest PC 0x0c06c75e */
if(!s->budget--) { s->failed_pc=0x0c06c75eu; return 0; }
r[1]=0x00000001u;
goto P_0c06c760;
P_0c06c760: /* original 0e14, guest PC 0x0c06c760 */
if(!s->budget--) { s->failed_pc=0x0c06c760u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c06c762;
P_0c06c762: /* original 9036, guest PC 0x0c06c762 */
if(!s->budget--) { s->failed_pc=0x0c06c762u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d2u,2);
goto P_0c06c764;
P_0c06c764: /* original 00ec, guest PC 0x0c06c764 */
if(!s->budget--) { s->failed_pc=0x0c06c764u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c766;
P_0c06c766: /* original 8803, guest PC 0x0c06c766 */
if(!s->budget--) { s->failed_pc=0x0c06c766u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c06c768;
P_0c06c768: /* original 8f03, guest PC 0x0c06c768 */
if(!s->budget--) { s->failed_pc=0x0c06c768u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c06c772; }
goto P_0c06c76c;
P_0c06c76a: /* original 6403, guest PC 0x0c06c76a */
if(!s->budget--) { s->failed_pc=0x0c06c76au; return 0; }
r[4]=r[0];
goto P_0c06c76c;
P_0c06c76c: /* original 7f04, guest PC 0x0c06c76c */
if(!s->budget--) { s->failed_pc=0x0c06c76cu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c76e;
P_0c06c76e: /* original a018, guest PC 0x0c06c76e */
if(!s->budget--) { s->failed_pc=0x0c06c76eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c7a2;
P_0c06c770: /* original 6ef6, guest PC 0x0c06c770 */
if(!s->budget--) { s->failed_pc=0x0c06c770u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c772;
P_0c06c772: /* original d31a, guest PC 0x0c06c772 */
if(!s->budget--) { s->failed_pc=0x0c06c772u; return 0; }
r[3]=read(ram,0x0c06c7dcu,4);
goto P_0c06c774;
P_0c06c774: /* original e23f, guest PC 0x0c06c774 */
if(!s->budget--) { s->failed_pc=0x0c06c774u; return 0; }
r[2]=0x0000003fu;
goto P_0c06c776;
P_0c06c776: /* original 902d, guest PC 0x0c06c776 */
if(!s->budget--) { s->failed_pc=0x0c06c776u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d4u,2);
goto P_0c06c778;
P_0c06c778: /* original 6532, guest PC 0x0c06c778 */
if(!s->budget--) { s->failed_pc=0x0c06c778u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06c77a;
P_0c06c77a: /* original e303, guest PC 0x0c06c77a */
if(!s->budget--) { s->failed_pc=0x0c06c77au; return 0; }
r[3]=0x00000003u;
goto P_0c06c77c;
P_0c06c77c: /* original 04ec, guest PC 0x0c06c77c */
if(!s->budget--) { s->failed_pc=0x0c06c77cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c77e;
P_0c06c77e: /* original 2529, guest PC 0x0c06c77e */
if(!s->budget--) { s->failed_pc=0x0c06c77eu; return 0; }
r[5]&=r[2];
goto P_0c06c780;
P_0c06c780: /* original 2558, guest PC 0x0c06c780 */
if(!s->budget--) { s->failed_pc=0x0c06c780u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06c782;
P_0c06c782: /* original 8f01, guest PC 0x0c06c782 */
if(!s->budget--) { s->failed_pc=0x0c06c782u; return 0; }
cond=r[17]&1u;
r[4]&=r[3];
if(!cond) { goto P_0c06c788; }
goto P_0c06c786;
P_0c06c784: /* original 2439, guest PC 0x0c06c784 */
if(!s->budget--) { s->failed_pc=0x0c06c784u; return 0; }
r[4]&=r[3];
goto P_0c06c786;
P_0c06c786: /* original 7401, guest PC 0x0c06c786 */
if(!s->budget--) { s->failed_pc=0x0c06c786u; return 0; }
r[4]+=0x00000001u;
goto P_0c06c788;
P_0c06c788: /* original e302, guest PC 0x0c06c788 */
if(!s->budget--) { s->failed_pc=0x0c06c788u; return 0; }
r[3]=0x00000002u;
goto P_0c06c78a;
P_0c06c78a: /* original 3436, guest PC 0x0c06c78a */
if(!s->budget--) { s->failed_pc=0x0c06c78au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[3])!=0);
goto P_0c06c78c;
P_0c06c78c: /* original 8b00, guest PC 0x0c06c78c */
if(!s->budget--) { s->failed_pc=0x0c06c78cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c790; }
goto P_0c06c78e;
P_0c06c78e: /* original e400, guest PC 0x0c06c78e */
if(!s->budget--) { s->failed_pc=0x0c06c78eu; return 0; }
r[4]=0x00000000u;
goto P_0c06c790;
P_0c06c790: /* original 0e44, guest PC 0x0c06c790 */
if(!s->budget--) { s->failed_pc=0x0c06c790u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06c792;
P_0c06c792: /* original 4408, guest PC 0x0c06c792 */
if(!s->budget--) { s->failed_pc=0x0c06c792u; return 0; }
r[4]<<=2;
goto P_0c06c794;
P_0c06c794: /* original d012, guest PC 0x0c06c794 */
if(!s->budget--) { s->failed_pc=0x0c06c794u; return 0; }
r[0]=read(ram,0x0c06c7e0u,4);
goto P_0c06c796;
P_0c06c796: /* original 034e, guest PC 0x0c06c796 */
if(!s->budget--) { s->failed_pc=0x0c06c796u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c06c798;
P_0c06c798: /* original 2f32, guest PC 0x0c06c798 */
if(!s->budget--) { s->failed_pc=0x0c06c798u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c79a;
P_0c06c79a: /* original 7f04, guest PC 0x0c06c79a */
if(!s->budget--) { s->failed_pc=0x0c06c79au; return 0; }
r[15]+=0x00000004u;
goto P_0c06c79c;
P_0c06c79c: /* original 6233, guest PC 0x0c06c79c */
if(!s->budget--) { s->failed_pc=0x0c06c79cu; return 0; }
r[2]=r[3];
goto P_0c06c79e;
P_0c06c79e: /* original 422b, guest PC 0x0c06c79e */
if(!s->budget--) { s->failed_pc=0x0c06c79eu; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c06c7a0: /* original 6ef6, guest PC 0x0c06c7a0 */
if(!s->budget--) { s->failed_pc=0x0c06c7a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c7a2;
P_0c06c7a2: /* original d30e, guest PC 0x0c06c7a2 */
if(!s->budget--) { s->failed_pc=0x0c06c7a2u; return 0; }
r[3]=read(ram,0x0c06c7dcu,4);
goto P_0c06c7a4;
P_0c06c7a4: /* original e23f, guest PC 0x0c06c7a4 */
if(!s->budget--) { s->failed_pc=0x0c06c7a4u; return 0; }
r[2]=0x0000003fu;
goto P_0c06c7a6;
P_0c06c7a6: /* original 9015, guest PC 0x0c06c7a6 */
if(!s->budget--) { s->failed_pc=0x0c06c7a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c7d4u,2);
goto P_0c06c7a8;
P_0c06c7a8: /* original e601, guest PC 0x0c06c7a8 */
if(!s->budget--) { s->failed_pc=0x0c06c7a8u; return 0; }
r[6]=0x00000001u;
goto P_0c06c7aa;
P_0c06c7aa: /* original d70b, guest PC 0x0c06c7aa */
if(!s->budget--) { s->failed_pc=0x0c06c7aau; return 0; }
r[7]=read(ram,0x0c06c7d8u,4);
goto P_0c06c7ac;
P_0c06c7ac: /* original 7ffc, guest PC 0x0c06c7ac */
if(!s->budget--) { s->failed_pc=0x0c06c7acu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c7ae;
P_0c06c7ae: /* original 6532, guest PC 0x0c06c7ae */
if(!s->budget--) { s->failed_pc=0x0c06c7aeu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06c7b0;
P_0c06c7b0: /* original 047c, guest PC 0x0c06c7b0 */
if(!s->budget--) { s->failed_pc=0x0c06c7b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c06c7b2;
P_0c06c7b2: /* original 2529, guest PC 0x0c06c7b2 */
if(!s->budget--) { s->failed_pc=0x0c06c7b2u; return 0; }
r[5]&=r[2];
goto P_0c06c7b4;
P_0c06c7b4: /* original 2558, guest PC 0x0c06c7b4 */
if(!s->budget--) { s->failed_pc=0x0c06c7b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06c7b6;
P_0c06c7b6: /* original 8f02, guest PC 0x0c06c7b6 */
if(!s->budget--) { s->failed_pc=0x0c06c7b6u; return 0; }
cond=r[17]&1u;
r[4]&=r[6];
if(!cond) { goto P_0c06c7be; }
goto P_0c06c7ba;
P_0c06c7b8: /* original 2469, guest PC 0x0c06c7b8 */
if(!s->budget--) { s->failed_pc=0x0c06c7b8u; return 0; }
r[4]&=r[6];
goto P_0c06c7ba;
P_0c06c7ba: /* original 246a, guest PC 0x0c06c7ba */
if(!s->budget--) { s->failed_pc=0x0c06c7bau; return 0; }
r[4]^=r[6];
goto P_0c06c7bc;
P_0c06c7bc: /* original 0744, guest PC 0x0c06c7bc */
if(!s->budget--) { s->failed_pc=0x0c06c7bcu; return 0; }
write(ram,r[7]+r[0],r[4],1);
goto P_0c06c7be;
P_0c06c7be: /* original d008, guest PC 0x0c06c7be */
if(!s->budget--) { s->failed_pc=0x0c06c7beu; return 0; }
r[0]=read(ram,0x0c06c7e0u,4);
goto P_0c06c7c0;
P_0c06c7c0: /* original 4408, guest PC 0x0c06c7c0 */
if(!s->budget--) { s->failed_pc=0x0c06c7c0u; return 0; }
r[4]<<=2;
goto P_0c06c7c2;
P_0c06c7c2: /* original 034e, guest PC 0x0c06c7c2 */
if(!s->budget--) { s->failed_pc=0x0c06c7c2u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c06c7c4;
P_0c06c7c4: /* original 6233, guest PC 0x0c06c7c4 */
if(!s->budget--) { s->failed_pc=0x0c06c7c4u; return 0; }
r[2]=r[3];
goto P_0c06c7c6;
P_0c06c7c6: /* original 2f32, guest PC 0x0c06c7c6 */
if(!s->budget--) { s->failed_pc=0x0c06c7c6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c7c8;
P_0c06c7c8: /* original 422b, guest PC 0x0c06c7c8 */
if(!s->budget--) { s->failed_pc=0x0c06c7c8u; return 0; }
target=r[2];
r[15]+=0x00000004u;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c06c7ca: /* original 7f04, guest PC 0x0c06c7ca */
if(!s->budget--) { s->failed_pc=0x0c06c7cau; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c06c7ccu,s,ram);
P_0c06c7e4: /* original 2fe6, guest PC 0x0c06c7e4 */
if(!s->budget--) { s->failed_pc=0x0c06c7e4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c7e6;
P_0c06c7e6: /* original 2fd6, guest PC 0x0c06c7e6 */
if(!s->budget--) { s->failed_pc=0x0c06c7e6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c7e8;
P_0c06c7e8: /* original 2fc6, guest PC 0x0c06c7e8 */
if(!s->budget--) { s->failed_pc=0x0c06c7e8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c7ea;
P_0c06c7ea: /* original 2fb6, guest PC 0x0c06c7ea */
if(!s->budget--) { s->failed_pc=0x0c06c7eau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c7ec;
P_0c06c7ec: /* original 2f96, guest PC 0x0c06c7ec */
if(!s->budget--) { s->failed_pc=0x0c06c7ecu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c7ee;
P_0c06c7ee: /* original de46, guest PC 0x0c06c7ee */
if(!s->budget--) { s->failed_pc=0x0c06c7eeu; return 0; }
r[14]=read(ram,0x0c06c908u,4);
goto P_0c06c7f0;
P_0c06c7f0: /* original 9081, guest PC 0x0c06c7f0 */
if(!s->budget--) { s->failed_pc=0x0c06c7f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8f6u,2);
goto P_0c06c7f2;
P_0c06c7f2: /* original 4f22, guest PC 0x0c06c7f2 */
if(!s->budget--) { s->failed_pc=0x0c06c7f2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c7f4;
P_0c06c7f4: /* original 06ec, guest PC 0x0c06c7f4 */
if(!s->budget--) { s->failed_pc=0x0c06c7f4u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c7f6;
P_0c06c7f6: /* original 7005, guest PC 0x0c06c7f6 */
if(!s->budget--) { s->failed_pc=0x0c06c7f6u; return 0; }
r[0]+=0x00000005u;
goto P_0c06c7f8;
P_0c06c7f8: /* original 05ec, guest PC 0x0c06c7f8 */
if(!s->budget--) { s->failed_pc=0x0c06c7f8u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c7fa;
P_0c06c7fa: /* original 907d, guest PC 0x0c06c7fa */
if(!s->budget--) { s->failed_pc=0x0c06c7fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8f8u,2);
goto P_0c06c7fc;
P_0c06c7fc: /* original 7ff8, guest PC 0x0c06c7fc */
if(!s->budget--) { s->failed_pc=0x0c06c7fcu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06c7fe;
P_0c06c7fe: /* original d441, guest PC 0x0c06c7fe */
if(!s->budget--) { s->failed_pc=0x0c06c7feu; return 0; }
r[4]=read(ram,0x0c06c904u,4);
goto P_0c06c800;
P_0c06c800: /* original 01ec, guest PC 0x0c06c800 */
if(!s->budget--) { s->failed_pc=0x0c06c800u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c802;
P_0c06c802: /* original 6063, guest PC 0x0c06c802 */
if(!s->budget--) { s->failed_pc=0x0c06c802u; return 0; }
r[0]=r[6];
goto P_0c06c804;
P_0c06c804: /* original 8801, guest PC 0x0c06c804 */
if(!s->budget--) { s->failed_pc=0x0c06c804u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c806;
P_0c06c806: /* original 8d22, guest PC 0x0c06c806 */
if(!s->budget--) { s->failed_pc=0x0c06c806u; return 0; }
cond=r[17]&1u;
r[7]=0x00000004u;
if(cond) { goto P_0c06c84e; }
goto P_0c06c80a;
P_0c06c808: /* original e704, guest PC 0x0c06c808 */
if(!s->budget--) { s->failed_pc=0x0c06c808u; return 0; }
r[7]=0x00000004u;
goto P_0c06c80a;
P_0c06c80a: /* original d340, guest PC 0x0c06c80a */
if(!s->budget--) { s->failed_pc=0x0c06c80au; return 0; }
r[3]=read(ram,0x0c06c90cu,4);
goto P_0c06c80c;
P_0c06c80c: /* original 6013, guest PC 0x0c06c80c */
if(!s->budget--) { s->failed_pc=0x0c06c80cu; return 0; }
r[0]=r[1];
goto P_0c06c80e;
P_0c06c80e: /* original 8801, guest PC 0x0c06c80e */
if(!s->budget--) { s->failed_pc=0x0c06c80eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c810;
P_0c06c810: /* original 6b53, guest PC 0x0c06c810 */
if(!s->budget--) { s->failed_pc=0x0c06c810u; return 0; }
r[11]=r[5];
goto P_0c06c812;
P_0c06c812: /* original 6c32, guest PC 0x0c06c812 */
if(!s->budget--) { s->failed_pc=0x0c06c812u; return 0; }
tmp=read(ram,r[3],4);
r[12]=tmp;
goto P_0c06c814;
P_0c06c814: /* original 6d73, guest PC 0x0c06c814 */
if(!s->budget--) { s->failed_pc=0x0c06c814u; return 0; }
r[13]=r[7];
goto P_0c06c816;
P_0c06c816: /* original 8f01, guest PC 0x0c06c816 */
if(!s->budget--) { s->failed_pc=0x0c06c816u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c06c81c; }
goto P_0c06c81a;
P_0c06c818: /* original 7c01, guest PC 0x0c06c818 */
if(!s->budget--) { s->failed_pc=0x0c06c818u; return 0; }
r[12]+=0x00000001u;
goto P_0c06c81a;
P_0c06c81a: /* original ed27, guest PC 0x0c06c81a */
if(!s->budget--) { s->failed_pc=0x0c06c81au; return 0; }
r[13]=0x00000027u;
goto P_0c06c81c;
P_0c06c81c: /* original 63d3, guest PC 0x0c06c81c */
if(!s->budget--) { s->failed_pc=0x0c06c81cu; return 0; }
r[3]=r[13];
goto P_0c06c81e;
P_0c06c81e: /* original 65c3, guest PC 0x0c06c81e */
if(!s->budget--) { s->failed_pc=0x0c06c81eu; return 0; }
r[5]=r[12];
goto P_0c06c820;
P_0c06c820: /* original e207, guest PC 0x0c06c820 */
if(!s->budget--) { s->failed_pc=0x0c06c820u; return 0; }
r[2]=0x00000007u;
goto P_0c06c822;
P_0c06c822: /* original 73fd, guest PC 0x0c06c822 */
if(!s->budget--) { s->failed_pc=0x0c06c822u; return 0; }
r[3]+=0xfffffffdu;
goto P_0c06c824;
P_0c06c824: /* original 452d, guest PC 0x0c06c824 */
if(!s->budget--) { s->failed_pc=0x0c06c824u; return 0; }
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?r[5]>>((-r[2])&31u):0):r[5]<<(r[2]&31u);
goto P_0c06c826;
P_0c06c826: /* original 2f32, guest PC 0x0c06c826 */
if(!s->budget--) { s->failed_pc=0x0c06c826u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c828;
P_0c06c828: /* original 1f51, guest PC 0x0c06c828 */
if(!s->budget--) { s->failed_pc=0x0c06c828u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c06c82a;
P_0c06c82a: /* original 4300, guest PC 0x0c06c82a */
if(!s->budget--) { s->failed_pc=0x0c06c82au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c06c82c;
P_0c06c82c: /* original 253b, guest PC 0x0c06c82c */
if(!s->budget--) { s->failed_pc=0x0c06c82cu; return 0; }
r[5]|=r[3];
goto P_0c06c82e;
P_0c06c82e: /* original e320, guest PC 0x0c06c82e */
if(!s->budget--) { s->failed_pc=0x0c06c82eu; return 0; }
r[3]=0x00000020u;
goto P_0c06c830;
P_0c06c830: /* original e701, guest PC 0x0c06c830 */
if(!s->budget--) { s->failed_pc=0x0c06c830u; return 0; }
r[7]=0x00000001u;
goto P_0c06c832;
P_0c06c832: /* original 2f36, guest PC 0x0c06c832 */
if(!s->budget--) { s->failed_pc=0x0c06c832u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c834;
P_0c06c834: /* original d236, guest PC 0x0c06c834 */
if(!s->budget--) { s->failed_pc=0x0c06c834u; return 0; }
r[2]=read(ram,0x0c06c910u,4);
goto P_0c06c836;
P_0c06c836: /* original 420b, guest PC 0x0c06c836 */
if(!s->budget--) { s->failed_pc=0x0c06c836u; return 0; }
target=r[2];
r[16]=0x0c06c83au;
r[6]=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06c83au) { target=s->pc; goto dispatch; }
goto P_0c06c83a;
P_0c06c838: /* original e618, guest PC 0x0c06c838 */
if(!s->budget--) { s->failed_pc=0x0c06c838u; return 0; }
r[6]=0x00000018u;
goto P_0c06c83a;
P_0c06c83a: /* original 905e, guest PC 0x0c06c83a */
if(!s->budget--) { s->failed_pc=0x0c06c83au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8fau,2);
goto P_0c06c83c;
P_0c06c83c: /* original 7f04, guest PC 0x0c06c83c */
if(!s->budget--) { s->failed_pc=0x0c06c83cu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c83e;
P_0c06c83e: /* original 64f2, guest PC 0x0c06c83e */
if(!s->budget--) { s->failed_pc=0x0c06c83eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06c840;
P_0c06c840: /* original 09ec, guest PC 0x0c06c840 */
if(!s->budget--) { s->failed_pc=0x0c06c840u; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c842;
P_0c06c842: /* original 700d, guest PC 0x0c06c842 */
if(!s->budget--) { s->failed_pc=0x0c06c842u; return 0; }
r[0]+=0x0000000du;
goto P_0c06c844;
P_0c06c844: /* original 53f1, guest PC 0x0c06c844 */
if(!s->budget--) { s->failed_pc=0x0c06c844u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06c846;
P_0c06c846: /* original 4400, guest PC 0x0c06c846 */
if(!s->budget--) { s->failed_pc=0x0c06c846u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c848;
P_0c06c848: /* original 0eec, guest PC 0x0c06c848 */
if(!s->budget--) { s->failed_pc=0x0c06c848u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c84a;
P_0c06c84a: /* original a018, guest PC 0x0c06c84a */
if(!s->budget--) { s->failed_pc=0x0c06c84au; return 0; }
r[4]|=r[3];
goto P_0c06c87e;
P_0c06c84c: /* original 243b, guest PC 0x0c06c84c */
if(!s->budget--) { s->failed_pc=0x0c06c84cu; return 0; }
r[4]|=r[3];
goto P_0c06c84e;
P_0c06c84e: /* original 9054, guest PC 0x0c06c84e */
if(!s->budget--) { s->failed_pc=0x0c06c84eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8fau,2);
goto P_0c06c850;
P_0c06c850: /* original 6d73, guest PC 0x0c06c850 */
if(!s->budget--) { s->failed_pc=0x0c06c850u; return 0; }
r[13]=r[7];
goto P_0c06c852;
P_0c06c852: /* original d32e, guest PC 0x0c06c852 */
if(!s->budget--) { s->failed_pc=0x0c06c852u; return 0; }
r[3]=read(ram,0x0c06c90cu,4);
goto P_0c06c854;
P_0c06c854: /* original 09ec, guest PC 0x0c06c854 */
if(!s->budget--) { s->failed_pc=0x0c06c854u; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c856;
P_0c06c856: /* original 6013, guest PC 0x0c06c856 */
if(!s->budget--) { s->failed_pc=0x0c06c856u; return 0; }
r[0]=r[1];
goto P_0c06c858;
P_0c06c858: /* original 6c32, guest PC 0x0c06c858 */
if(!s->budget--) { s->failed_pc=0x0c06c858u; return 0; }
tmp=read(ram,r[3],4);
r[12]=tmp;
goto P_0c06c85a;
P_0c06c85a: /* original 8801, guest PC 0x0c06c85a */
if(!s->budget--) { s->failed_pc=0x0c06c85au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c85c;
P_0c06c85c: /* original 7c01, guest PC 0x0c06c85c */
if(!s->budget--) { s->failed_pc=0x0c06c85cu; return 0; }
r[12]+=0x00000001u;
goto P_0c06c85e;
P_0c06c85e: /* original 8f05, guest PC 0x0c06c85e */
if(!s->budget--) { s->failed_pc=0x0c06c85eu; return 0; }
cond=r[17]&1u;
r[11]=r[5];
if(!cond) { goto P_0c06c86c; }
goto P_0c06c862;
P_0c06c860: /* original 6b53, guest PC 0x0c06c860 */
if(!s->budget--) { s->failed_pc=0x0c06c860u; return 0; }
r[11]=r[5];
goto P_0c06c862;
P_0c06c862: /* original 904b, guest PC 0x0c06c862 */
if(!s->budget--) { s->failed_pc=0x0c06c862u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8fcu,2);
goto P_0c06c864;
P_0c06c864: /* original ed27, guest PC 0x0c06c864 */
if(!s->budget--) { s->failed_pc=0x0c06c864u; return 0; }
r[13]=0x00000027u;
goto P_0c06c866;
P_0c06c866: /* original 0bec, guest PC 0x0c06c866 */
if(!s->budget--) { s->failed_pc=0x0c06c866u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c868;
P_0c06c868: /* original 7001, guest PC 0x0c06c868 */
if(!s->budget--) { s->failed_pc=0x0c06c868u; return 0; }
r[0]+=0x00000001u;
goto P_0c06c86a;
P_0c06c86a: /* original 09ec, guest PC 0x0c06c86a */
if(!s->budget--) { s->failed_pc=0x0c06c86au; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c86c;
P_0c06c86c: /* original 64d3, guest PC 0x0c06c86c */
if(!s->budget--) { s->failed_pc=0x0c06c86cu; return 0; }
r[4]=r[13];
goto P_0c06c86e;
P_0c06c86e: /* original 9046, guest PC 0x0c06c86e */
if(!s->budget--) { s->failed_pc=0x0c06c86eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8feu,2);
goto P_0c06c870;
P_0c06c870: /* original 62c3, guest PC 0x0c06c870 */
if(!s->budget--) { s->failed_pc=0x0c06c870u; return 0; }
r[2]=r[12];
goto P_0c06c872;
P_0c06c872: /* original e307, guest PC 0x0c06c872 */
if(!s->budget--) { s->failed_pc=0x0c06c872u; return 0; }
r[3]=0x00000007u;
goto P_0c06c874;
P_0c06c874: /* original 74fd, guest PC 0x0c06c874 */
if(!s->budget--) { s->failed_pc=0x0c06c874u; return 0; }
r[4]+=0xfffffffdu;
goto P_0c06c876;
P_0c06c876: /* original 0eec, guest PC 0x0c06c876 */
if(!s->budget--) { s->failed_pc=0x0c06c876u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06c878;
P_0c06c878: /* original 423d, guest PC 0x0c06c878 */
if(!s->budget--) { s->failed_pc=0x0c06c878u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c06c87a;
P_0c06c87a: /* original 4400, guest PC 0x0c06c87a */
if(!s->budget--) { s->failed_pc=0x0c06c87au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c87c;
P_0c06c87c: /* original 242b, guest PC 0x0c06c87c */
if(!s->budget--) { s->failed_pc=0x0c06c87cu; return 0; }
r[4]|=r[2];
goto P_0c06c87e;
P_0c06c87e: /* original bd8b, guest PC 0x0c06c87e */
if(!s->budget--) { s->failed_pc=0x0c06c87eu; return 0; }
target=0x0c06c398u; r[16]=0x0c06c882u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06c882u) { target=s->pc; goto dispatch; }
goto P_0c06c882;
P_0c06c880: /* original 0009, guest PC 0x0c06c880 */
if(!s->budget--) { s->failed_pc=0x0c06c880u; return 0; }
goto P_0c06c882;
P_0c06c882: /* original 2008, guest PC 0x0c06c882 */
if(!s->budget--) { s->failed_pc=0x0c06c882u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06c884;
P_0c06c884: /* original 8906, guest PC 0x0c06c884 */
if(!s->budget--) { s->failed_pc=0x0c06c884u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c894; }
goto P_0c06c886;
P_0c06c886: /* original 66b3, guest PC 0x0c06c886 */
if(!s->budget--) { s->failed_pc=0x0c06c886u; return 0; }
r[6]=r[11];
goto P_0c06c888;
P_0c06c888: /* original 65c3, guest PC 0x0c06c888 */
if(!s->budget--) { s->failed_pc=0x0c06c888u; return 0; }
r[5]=r[12];
goto P_0c06c88a;
P_0c06c88a: /* original 2fe6, guest PC 0x0c06c88a */
if(!s->budget--) { s->failed_pc=0x0c06c88au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c88c;
P_0c06c88c: /* original 6793, guest PC 0x0c06c88c */
if(!s->budget--) { s->failed_pc=0x0c06c88cu; return 0; }
r[7]=r[9];
goto P_0c06c88e;
P_0c06c88e: /* original b12a, guest PC 0x0c06c88e */
if(!s->budget--) { s->failed_pc=0x0c06c88eu; return 0; }
target=0x0c06cae6u; r[16]=0x0c06c892u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06c892u) { target=s->pc; goto dispatch; }
goto P_0c06c892;
P_0c06c890: /* original 64d3, guest PC 0x0c06c890 */
if(!s->budget--) { s->failed_pc=0x0c06c890u; return 0; }
r[4]=r[13];
goto P_0c06c892;
P_0c06c892: /* original 7f04, guest PC 0x0c06c892 */
if(!s->budget--) { s->failed_pc=0x0c06c892u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c894;
P_0c06c894: /* original 7f08, guest PC 0x0c06c894 */
if(!s->budget--) { s->failed_pc=0x0c06c894u; return 0; }
r[15]+=0x00000008u;
goto P_0c06c896;
P_0c06c896: /* original 4f26, guest PC 0x0c06c896 */
if(!s->budget--) { s->failed_pc=0x0c06c896u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c898;
P_0c06c898: /* original 69f6, guest PC 0x0c06c898 */
if(!s->budget--) { s->failed_pc=0x0c06c898u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06c89a;
P_0c06c89a: /* original 6bf6, guest PC 0x0c06c89a */
if(!s->budget--) { s->failed_pc=0x0c06c89au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06c89c;
P_0c06c89c: /* original 6cf6, guest PC 0x0c06c89c */
if(!s->budget--) { s->failed_pc=0x0c06c89cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06c89e;
P_0c06c89e: /* original 6df6, guest PC 0x0c06c89e */
if(!s->budget--) { s->failed_pc=0x0c06c89eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06c8a0;
P_0c06c8a0: /* original 000b, guest PC 0x0c06c8a0 */
if(!s->budget--) { s->failed_pc=0x0c06c8a0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c8a2: /* original 6ef6, guest PC 0x0c06c8a2 */
if(!s->budget--) { s->failed_pc=0x0c06c8a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06c8a4u,s,ram);
P_0c06c95e: /* original 2fe6, guest PC 0x0c06c95e */
if(!s->budget--) { s->failed_pc=0x0c06c95eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c960;
P_0c06c960: /* original ee27, guest PC 0x0c06c960 */
if(!s->budget--) { s->failed_pc=0x0c06c960u; return 0; }
r[14]=0x00000027u;
goto P_0c06c962;
P_0c06c962: /* original 2fd6, guest PC 0x0c06c962 */
if(!s->budget--) { s->failed_pc=0x0c06c962u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c964;
P_0c06c964: /* original 60e3, guest PC 0x0c06c964 */
if(!s->budget--) { s->failed_pc=0x0c06c964u; return 0; }
r[0]=r[14];
goto P_0c06c966;
P_0c06c966: /* original 2fc6, guest PC 0x0c06c966 */
if(!s->budget--) { s->failed_pc=0x0c06c966u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c968;
P_0c06c968: /* original 706b, guest PC 0x0c06c968 */
if(!s->budget--) { s->failed_pc=0x0c06c968u; return 0; }
r[0]+=0x0000006bu;
goto P_0c06c96a;
P_0c06c96a: /* original 2fb6, guest PC 0x0c06c96a */
if(!s->budget--) { s->failed_pc=0x0c06c96au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c96c;
P_0c06c96c: /* original 2fa6, guest PC 0x0c06c96c */
if(!s->budget--) { s->failed_pc=0x0c06c96cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c96e;
P_0c06c96e: /* original 2f96, guest PC 0x0c06c96e */
if(!s->budget--) { s->failed_pc=0x0c06c96eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c970;
P_0c06c970: /* original 4f22, guest PC 0x0c06c970 */
if(!s->budget--) { s->failed_pc=0x0c06c970u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c972;
P_0c06c972: /* original d327, guest PC 0x0c06c972 */
if(!s->budget--) { s->failed_pc=0x0c06c972u; return 0; }
r[3]=read(ram,0x0c06ca10u,4);
goto P_0c06c974;
P_0c06c974: /* original 7ffc, guest PC 0x0c06c974 */
if(!s->budget--) { s->failed_pc=0x0c06c974u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c976;
P_0c06c976: /* original 2f32, guest PC 0x0c06c976 */
if(!s->budget--) { s->failed_pc=0x0c06c976u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c978;
P_0c06c978: /* original dd28, guest PC 0x0c06c978 */
if(!s->budget--) { s->failed_pc=0x0c06c978u; return 0; }
r[13]=read(ram,0x0c06ca1cu,4);
goto P_0c06c97a;
P_0c06c97a: /* original d327, guest PC 0x0c06c97a */
if(!s->budget--) { s->failed_pc=0x0c06c97au; return 0; }
r[3]=read(ram,0x0c06ca18u,4);
goto P_0c06c97c;
P_0c06c97c: /* original 04dc, guest PC 0x0c06c97c */
if(!s->budget--) { s->failed_pc=0x0c06c97cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c06c97e;
P_0c06c97e: /* original 6632, guest PC 0x0c06c97e */
if(!s->budget--) { s->failed_pc=0x0c06c97eu; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c06c980;
P_0c06c980: /* original 6043, guest PC 0x0c06c980 */
if(!s->budget--) { s->failed_pc=0x0c06c980u; return 0; }
r[0]=r[4];
goto P_0c06c982;
P_0c06c982: /* original dc24, guest PC 0x0c06c982 */
if(!s->budget--) { s->failed_pc=0x0c06c982u; return 0; }
r[12]=read(ram,0x0c06ca14u,4);
goto P_0c06c984;
P_0c06c984: /* original 8801, guest PC 0x0c06c984 */
if(!s->budget--) { s->failed_pc=0x0c06c984u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c986;
P_0c06c986: /* original 7601, guest PC 0x0c06c986 */
if(!s->budget--) { s->failed_pc=0x0c06c986u; return 0; }
r[6]+=0x00000001u;
goto P_0c06c988;
P_0c06c988: /* original 8d01, guest PC 0x0c06c988 */
if(!s->budget--) { s->failed_pc=0x0c06c988u; return 0; }
cond=r[17]&1u;
r[5]=0x00000004u;
if(cond) { goto P_0c06c98e; }
goto P_0c06c98c;
P_0c06c98a: /* original e504, guest PC 0x0c06c98a */
if(!s->budget--) { s->failed_pc=0x0c06c98au; return 0; }
r[5]=0x00000004u;
goto P_0c06c98c;
P_0c06c98c: /* original 6e53, guest PC 0x0c06c98c */
if(!s->budget--) { s->failed_pc=0x0c06c98cu; return 0; }
r[14]=r[5];
goto P_0c06c98e;
P_0c06c98e: /* original 54d2, guest PC 0x0c06c98e */
if(!s->budget--) { s->failed_pc=0x0c06c98eu; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c06c990;
P_0c06c990: /* original 6b63, guest PC 0x0c06c990 */
if(!s->budget--) { s->failed_pc=0x0c06c990u; return 0; }
r[11]=r[6];
goto P_0c06c992;
P_0c06c992: /* original e307, guest PC 0x0c06c992 */
if(!s->budget--) { s->failed_pc=0x0c06c992u; return 0; }
r[3]=0x00000007u;
goto P_0c06c994;
P_0c06c994: /* original 6ae3, guest PC 0x0c06c994 */
if(!s->budget--) { s->failed_pc=0x0c06c994u; return 0; }
r[10]=r[14];
goto P_0c06c996;
P_0c06c996: /* original 4a00, guest PC 0x0c06c996 */
if(!s->budget--) { s->failed_pc=0x0c06c996u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c06c998;
P_0c06c998: /* original 2458, guest PC 0x0c06c998 */
if(!s->budget--) { s->failed_pc=0x0c06c998u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[5])==0)!=0);
goto P_0c06c99a;
P_0c06c99a: /* original 4b3d, guest PC 0x0c06c99a */
if(!s->budget--) { s->failed_pc=0x0c06c99au; return 0; }
r[11]=(r[3]&0x80000000u)?((r[3]&31u)?r[11]>>((-r[3])&31u):0):r[11]<<(r[3]&31u);
goto P_0c06c99c;
P_0c06c99c: /* original 8d13, guest PC 0x0c06c99c */
if(!s->budget--) { s->failed_pc=0x0c06c99cu; return 0; }
cond=r[17]&1u;
r[10]|=r[11];
if(cond) { goto P_0c06c9c6; }
goto P_0c06c9a0;
P_0c06c99e: /* original 2abb, guest PC 0x0c06c99e */
if(!s->budget--) { s->failed_pc=0x0c06c99eu; return 0; }
r[10]|=r[11];
goto P_0c06c9a0;
P_0c06c9a0: /* original bcfa, guest PC 0x0c06c9a0 */
if(!s->budget--) { s->failed_pc=0x0c06c9a0u; return 0; }
target=0x0c06c398u; r[16]=0x0c06c9a4u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06c9a4u) { target=s->pc; goto dispatch; }
goto P_0c06c9a4;
P_0c06c9a2: /* original 64a3, guest PC 0x0c06c9a2 */
if(!s->budget--) { s->failed_pc=0x0c06c9a2u; return 0; }
r[4]=r[10];
goto P_0c06c9a4;
P_0c06c9a4: /* original 2008, guest PC 0x0c06c9a4 */
if(!s->budget--) { s->failed_pc=0x0c06c9a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06c9a6;
P_0c06c9a6: /* original 8b01, guest PC 0x0c06c9a6 */
if(!s->budget--) { s->failed_pc=0x0c06c9a6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c9ac; }
goto P_0c06c9a8;
P_0c06c9a8: /* original a094, guest PC 0x0c06c9a8 */
if(!s->budget--) { s->failed_pc=0x0c06c9a8u; return 0; }
goto P_0c06cad4;
P_0c06c9aa: /* original 0009, guest PC 0x0c06c9aa */
if(!s->budget--) { s->failed_pc=0x0c06c9aau; return 0; }
goto P_0c06c9ac;
P_0c06c9ac: /* original 7f04, guest PC 0x0c06c9ac */
if(!s->budget--) { s->failed_pc=0x0c06c9acu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c9ae;
P_0c06c9ae: /* original 64a3, guest PC 0x0c06c9ae */
if(!s->budget--) { s->failed_pc=0x0c06c9aeu; return 0; }
r[4]=r[10];
goto P_0c06c9b0;
P_0c06c9b0: /* original 4f26, guest PC 0x0c06c9b0 */
if(!s->budget--) { s->failed_pc=0x0c06c9b0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c9b2;
P_0c06c9b2: /* original d216, guest PC 0x0c06c9b2 */
if(!s->budget--) { s->failed_pc=0x0c06c9b2u; return 0; }
r[2]=read(ram,0x0c06ca0cu,4);
goto P_0c06c9b4;
P_0c06c9b4: /* original e601, guest PC 0x0c06c9b4 */
if(!s->budget--) { s->failed_pc=0x0c06c9b4u; return 0; }
r[6]=0x00000001u;
goto P_0c06c9b6;
P_0c06c9b6: /* original d51a, guest PC 0x0c06c9b6 */
if(!s->budget--) { s->failed_pc=0x0c06c9b6u; return 0; }
r[5]=read(ram,0x0c06ca20u,4);
goto P_0c06c9b8;
P_0c06c9b8: /* original 69f6, guest PC 0x0c06c9b8 */
if(!s->budget--) { s->failed_pc=0x0c06c9b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06c9ba;
P_0c06c9ba: /* original 6af6, guest PC 0x0c06c9ba */
if(!s->budget--) { s->failed_pc=0x0c06c9bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06c9bc;
P_0c06c9bc: /* original 6bf6, guest PC 0x0c06c9bc */
if(!s->budget--) { s->failed_pc=0x0c06c9bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06c9be;
P_0c06c9be: /* original 6cf6, guest PC 0x0c06c9be */
if(!s->budget--) { s->failed_pc=0x0c06c9beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06c9c0;
P_0c06c9c0: /* original 6df6, guest PC 0x0c06c9c0 */
if(!s->budget--) { s->failed_pc=0x0c06c9c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06c9c2;
P_0c06c9c2: /* original 422b, guest PC 0x0c06c9c2 */
if(!s->budget--) { s->failed_pc=0x0c06c9c2u; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c06c9c4: /* original 6ef6, guest PC 0x0c06c9c4 */
if(!s->budget--) { s->failed_pc=0x0c06c9c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c9c6;
P_0c06c9c6: /* original d317, guest PC 0x0c06c9c6 */
if(!s->budget--) { s->failed_pc=0x0c06c9c6u; return 0; }
r[3]=read(ram,0x0c06ca24u,4);
goto P_0c06c9c8;
P_0c06c9c8: /* original 64f2, guest PC 0x0c06c9c8 */
if(!s->budget--) { s->failed_pc=0x0c06c9c8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06c9ca;
P_0c06c9ca: /* original 430b, guest PC 0x0c06c9ca */
if(!s->budget--) { s->failed_pc=0x0c06c9cau; return 0; }
target=r[3];
r[16]=0x0c06c9ceu;
r[4]+=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06c9ceu) { target=s->pc; goto dispatch; }
goto P_0c06c9ce;
P_0c06c9cc: /* original 7412, guest PC 0x0c06c9cc */
if(!s->budget--) { s->failed_pc=0x0c06c9ccu; return 0; }
r[4]+=0x00000012u;
goto P_0c06c9ce;
P_0c06c9ce: /* original 9015, guest PC 0x0c06c9ce */
if(!s->budget--) { s->failed_pc=0x0c06c9ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c9fcu,2);
goto P_0c06c9d0;
P_0c06c9d0: /* original e706, guest PC 0x0c06c9d0 */
if(!s->budget--) { s->failed_pc=0x0c06c9d0u; return 0; }
r[7]=0x00000006u;
goto P_0c06c9d2;
P_0c06c9d2: /* original 0dde, guest PC 0x0c06c9d2 */
if(!s->budget--) { s->failed_pc=0x0c06c9d2u; return 0; }
r[13]=read(ram,r[13]+r[0],4);
goto P_0c06c9d4;
P_0c06c9d4: /* original 60d3, guest PC 0x0c06c9d4 */
if(!s->budget--) { s->failed_pc=0x0c06c9d4u; return 0; }
r[0]=r[13];
goto P_0c06c9d6;
P_0c06c9d6: /* original 4001, guest PC 0x0c06c9d6 */
if(!s->budget--) { s->failed_pc=0x0c06c9d6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c06c9d8;
P_0c06c9d8: /* original 66d3, guest PC 0x0c06c9d8 */
if(!s->budget--) { s->failed_pc=0x0c06c9d8u; return 0; }
r[6]=r[13];
goto P_0c06c9da;
P_0c06c9da: /* original 2709, guest PC 0x0c06c9da */
if(!s->budget--) { s->failed_pc=0x0c06c9dau; return 0; }
r[7]&=r[0];
goto P_0c06c9dc;
P_0c06c9dc: /* original d012, guest PC 0x0c06c9dc */
if(!s->budget--) { s->failed_pc=0x0c06c9dcu; return 0; }
r[0]=read(ram,0x0c06ca28u,4);
goto P_0c06c9de;
P_0c06c9de: /* original 4609, guest PC 0x0c06c9de */
if(!s->budget--) { s->failed_pc=0x0c06c9deu; return 0; }
r[6]>>=2;
goto P_0c06c9e0;
P_0c06c9e0: /* original 4600, guest PC 0x0c06c9e0 */
if(!s->budget--) { s->failed_pc=0x0c06c9e0u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c06c9e2;
P_0c06c9e2: /* original 046d, guest PC 0x0c06c9e2 */
if(!s->budget--) { s->failed_pc=0x0c06c9e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c06c9e4;
P_0c06c9e4: /* original 2778, guest PC 0x0c06c9e4 */
if(!s->budget--) { s->failed_pc=0x0c06c9e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c06c9e6;
P_0c06c9e6: /* original 8d23, guest PC 0x0c06c9e6 */
if(!s->budget--) { s->failed_pc=0x0c06c9e6u; return 0; }
cond=r[17]&1u;
r[5]=0x00000020u;
if(cond) { goto P_0c06ca30; }
goto P_0c06c9ea;
P_0c06c9e8: /* original e520, guest PC 0x0c06c9e8 */
if(!s->budget--) { s->failed_pc=0x0c06c9e8u; return 0; }
r[5]=0x00000020u;
goto P_0c06c9ea;
P_0c06c9ea: /* original d010, guest PC 0x0c06c9ea */
if(!s->budget--) { s->failed_pc=0x0c06c9eau; return 0; }
r[0]=read(ram,0x0c06ca2cu,4);
goto P_0c06c9ec;
P_0c06c9ec: /* original 3d52, guest PC 0x0c06c9ec */
if(!s->budget--) { s->failed_pc=0x0c06c9ecu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[5])!=0);
goto P_0c06c9ee;
P_0c06c9ee: /* original 8f61, guest PC 0x0c06c9ee */
if(!s->budget--) { s->failed_pc=0x0c06c9eeu; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
if(!cond) { goto P_0c06cab4; }
goto P_0c06c9f2;
P_0c06c9f0: /* original 046d, guest PC 0x0c06c9f0 */
if(!s->budget--) { s->failed_pc=0x0c06c9f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c06c9f2;
P_0c06c9f2: /* original 9904, guest PC 0x0c06c9f2 */
if(!s->budget--) { s->failed_pc=0x0c06c9f2u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c9feu,2);
goto P_0c06c9f4;
P_0c06c9f4: /* original a05f, guest PC 0x0c06c9f4 */
if(!s->budget--) { s->failed_pc=0x0c06c9f4u; return 0; }
goto P_0c06cab6;
P_0c06c9f6: /* original 0009, guest PC 0x0c06c9f6 */
if(!s->budget--) { s->failed_pc=0x0c06c9f6u; return 0; }
return vf3_matrix_family(0x0c06c9f8u,s,ram);
P_0c06ca30: /* original 3d52, guest PC 0x0c06ca30 */
if(!s->budget--) { s->failed_pc=0x0c06ca30u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[5])!=0);
goto P_0c06ca32;
P_0c06ca32: /* original 8b3f, guest PC 0x0c06ca32 */
if(!s->budget--) { s->failed_pc=0x0c06ca32u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06cab4; }
goto P_0c06ca34;
P_0c06ca34: /* original e228, guest PC 0x0c06ca34 */
if(!s->budget--) { s->failed_pc=0x0c06ca34u; return 0; }
r[2]=0x00000028u;
goto P_0c06ca36;
P_0c06ca36: /* original 9980, guest PC 0x0c06ca36 */
if(!s->budget--) { s->failed_pc=0x0c06ca36u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cb3au,2);
goto P_0c06ca38;
P_0c06ca38: /* original 3d26, guest PC 0x0c06ca38 */
if(!s->budget--) { s->failed_pc=0x0c06ca38u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>r[2])!=0);
goto P_0c06ca3a;
P_0c06ca3a: /* original 8b3c, guest PC 0x0c06ca3a */
if(!s->budget--) { s->failed_pc=0x0c06ca3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06cab6; }
goto P_0c06ca3c;
P_0c06ca3c: /* original e35a, guest PC 0x0c06ca3c */
if(!s->budget--) { s->failed_pc=0x0c06ca3cu; return 0; }
r[3]=0x0000005au;
goto P_0c06ca3e;
P_0c06ca3e: /* original 3d36, guest PC 0x0c06ca3e */
if(!s->budget--) { s->failed_pc=0x0c06ca3eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>r[3])!=0);
goto P_0c06ca40;
P_0c06ca40: /* original 8b39, guest PC 0x0c06ca40 */
if(!s->budget--) { s->failed_pc=0x0c06ca40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06cab6; }
goto P_0c06ca42;
P_0c06ca42: /* original e464, guest PC 0x0c06ca42 */
if(!s->budget--) { s->failed_pc=0x0c06ca42u; return 0; }
r[4]=0x00000064u;
goto P_0c06ca44;
P_0c06ca44: /* original 997a, guest PC 0x0c06ca44 */
if(!s->budget--) { s->failed_pc=0x0c06ca44u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cb3cu,2);
goto P_0c06ca46;
P_0c06ca46: /* original 3d42, guest PC 0x0c06ca46 */
if(!s->budget--) { s->failed_pc=0x0c06ca46u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[4])!=0);
goto P_0c06ca48;
P_0c06ca48: /* original 8935, guest PC 0x0c06ca48 */
if(!s->budget--) { s->failed_pc=0x0c06ca48u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cab6; }
goto P_0c06ca4a;
P_0c06ca4a: /* original 2f42, guest PC 0x0c06ca4a */
if(!s->budget--) { s->failed_pc=0x0c06ca4au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06ca4c;
P_0c06ca4c: /* original bca4, guest PC 0x0c06ca4c */
if(!s->budget--) { s->failed_pc=0x0c06ca4cu; return 0; }
target=0x0c06c398u; r[16]=0x0c06ca50u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06ca50u) { target=s->pc; goto dispatch; }
goto P_0c06ca50;
P_0c06ca4e: /* original 64a3, guest PC 0x0c06ca4e */
if(!s->budget--) { s->failed_pc=0x0c06ca4eu; return 0; }
r[4]=r[10];
goto P_0c06ca50;
P_0c06ca50: /* original 2008, guest PC 0x0c06ca50 */
if(!s->budget--) { s->failed_pc=0x0c06ca50u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06ca52;
P_0c06ca52: /* original 893f, guest PC 0x0c06ca52 */
if(!s->budget--) { s->failed_pc=0x0c06ca52u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cad4; }
goto P_0c06ca54;
P_0c06ca54: /* original 64e3, guest PC 0x0c06ca54 */
if(!s->budget--) { s->failed_pc=0x0c06ca54u; return 0; }
r[4]=r[14];
goto P_0c06ca56;
P_0c06ca56: /* original e300, guest PC 0x0c06ca56 */
if(!s->budget--) { s->failed_pc=0x0c06ca56u; return 0; }
r[3]=0x00000000u;
goto P_0c06ca58;
P_0c06ca58: /* original 4400, guest PC 0x0c06ca58 */
if(!s->budget--) { s->failed_pc=0x0c06ca58u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06ca5a;
P_0c06ca5a: /* original 2f36, guest PC 0x0c06ca5a */
if(!s->budget--) { s->failed_pc=0x0c06ca5au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ca5c;
P_0c06ca5c: /* original 956f, guest PC 0x0c06ca5c */
if(!s->budget--) { s->failed_pc=0x0c06ca5cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cb3eu,2);
goto P_0c06ca5e;
P_0c06ca5e: /* original 24bb, guest PC 0x0c06ca5e */
if(!s->budget--) { s->failed_pc=0x0c06ca5eu; return 0; }
r[4]|=r[11];
goto P_0c06ca60;
P_0c06ca60: /* original d239, guest PC 0x0c06ca60 */
if(!s->budget--) { s->failed_pc=0x0c06ca60u; return 0; }
r[2]=read(ram,0x0c06cb48u,4);
goto P_0c06ca62;
P_0c06ca62: /* original 6733, guest PC 0x0c06ca62 */
if(!s->budget--) { s->failed_pc=0x0c06ca62u; return 0; }
r[7]=r[3];
goto P_0c06ca64;
P_0c06ca64: /* original 420b, guest PC 0x0c06ca64 */
if(!s->budget--) { s->failed_pc=0x0c06ca64u; return 0; }
target=r[2];
r[16]=0x0c06ca68u;
r[6]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06ca68u) { target=s->pc; goto dispatch; }
goto P_0c06ca68;
P_0c06ca66: /* original 66c3, guest PC 0x0c06ca66 */
if(!s->budget--) { s->failed_pc=0x0c06ca66u; return 0; }
r[6]=r[12];
goto P_0c06ca68;
P_0c06ca68: /* original 7efd, guest PC 0x0c06ca68 */
if(!s->budget--) { s->failed_pc=0x0c06ca68u; return 0; }
r[14]+=0xfffffffdu;
goto P_0c06ca6a;
P_0c06ca6a: /* original 9969, guest PC 0x0c06ca6a */
if(!s->budget--) { s->failed_pc=0x0c06ca6au; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cb40u,2);
goto P_0c06ca6c;
P_0c06ca6c: /* original 65e3, guest PC 0x0c06ca6c */
if(!s->budget--) { s->failed_pc=0x0c06ca6cu; return 0; }
r[5]=r[14];
goto P_0c06ca6e;
P_0c06ca6e: /* original 4500, guest PC 0x0c06ca6e */
if(!s->budget--) { s->failed_pc=0x0c06ca6eu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06ca70;
P_0c06ca70: /* original da36, guest PC 0x0c06ca70 */
if(!s->budget--) { s->failed_pc=0x0c06ca70u; return 0; }
r[10]=read(ram,0x0c06cb4cu,4);
goto P_0c06ca72;
P_0c06ca72: /* original 6793, guest PC 0x0c06ca72 */
if(!s->budget--) { s->failed_pc=0x0c06ca72u; return 0; }
r[7]=r[9];
goto P_0c06ca74;
P_0c06ca74: /* original e601, guest PC 0x0c06ca74 */
if(!s->budget--) { s->failed_pc=0x0c06ca74u; return 0; }
r[6]=0x00000001u;
goto P_0c06ca76;
P_0c06ca76: /* original 7f04, guest PC 0x0c06ca76 */
if(!s->budget--) { s->failed_pc=0x0c06ca76u; return 0; }
r[15]+=0x00000004u;
goto P_0c06ca78;
P_0c06ca78: /* original 25bb, guest PC 0x0c06ca78 */
if(!s->budget--) { s->failed_pc=0x0c06ca78u; return 0; }
r[5]|=r[11];
goto P_0c06ca7a;
P_0c06ca7a: /* original 4a0b, guest PC 0x0c06ca7a */
if(!s->budget--) { s->failed_pc=0x0c06ca7au; return 0; }
target=r[10];
r[16]=0x0c06ca7eu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06ca7eu) { target=s->pc; goto dispatch; }
goto P_0c06ca7e;
P_0c06ca7c: /* original 64c3, guest PC 0x0c06ca7c */
if(!s->budget--) { s->failed_pc=0x0c06ca7cu; return 0; }
r[4]=r[12];
goto P_0c06ca7e;
P_0c06ca7e: /* original 65e3, guest PC 0x0c06ca7e */
if(!s->budget--) { s->failed_pc=0x0c06ca7eu; return 0; }
r[5]=r[14];
goto P_0c06ca80;
P_0c06ca80: /* original 7502, guest PC 0x0c06ca80 */
if(!s->budget--) { s->failed_pc=0x0c06ca80u; return 0; }
r[5]+=0x00000002u;
goto P_0c06ca82;
P_0c06ca82: /* original 4500, guest PC 0x0c06ca82 */
if(!s->budget--) { s->failed_pc=0x0c06ca82u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06ca84;
P_0c06ca84: /* original 6793, guest PC 0x0c06ca84 */
if(!s->budget--) { s->failed_pc=0x0c06ca84u; return 0; }
r[7]=r[9];
goto P_0c06ca86;
P_0c06ca86: /* original e600, guest PC 0x0c06ca86 */
if(!s->budget--) { s->failed_pc=0x0c06ca86u; return 0; }
r[6]=0x00000000u;
goto P_0c06ca88;
P_0c06ca88: /* original 25bb, guest PC 0x0c06ca88 */
if(!s->budget--) { s->failed_pc=0x0c06ca88u; return 0; }
r[5]|=r[11];
goto P_0c06ca8a;
P_0c06ca8a: /* original 4a0b, guest PC 0x0c06ca8a */
if(!s->budget--) { s->failed_pc=0x0c06ca8au; return 0; }
target=r[10];
r[16]=0x0c06ca8eu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06ca8eu) { target=s->pc; goto dispatch; }
goto P_0c06ca8e;
P_0c06ca8c: /* original 64c3, guest PC 0x0c06ca8c */
if(!s->budget--) { s->failed_pc=0x0c06ca8cu; return 0; }
r[4]=r[12];
goto P_0c06ca8e;
P_0c06ca8e: /* original 65e3, guest PC 0x0c06ca8e */
if(!s->budget--) { s->failed_pc=0x0c06ca8eu; return 0; }
r[5]=r[14];
goto P_0c06ca90;
P_0c06ca90: /* original 7504, guest PC 0x0c06ca90 */
if(!s->budget--) { s->failed_pc=0x0c06ca90u; return 0; }
r[5]+=0x00000004u;
goto P_0c06ca92;
P_0c06ca92: /* original 4500, guest PC 0x0c06ca92 */
if(!s->budget--) { s->failed_pc=0x0c06ca92u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06ca94;
P_0c06ca94: /* original 6793, guest PC 0x0c06ca94 */
if(!s->budget--) { s->failed_pc=0x0c06ca94u; return 0; }
r[7]=r[9];
goto P_0c06ca96;
P_0c06ca96: /* original e600, guest PC 0x0c06ca96 */
if(!s->budget--) { s->failed_pc=0x0c06ca96u; return 0; }
r[6]=0x00000000u;
goto P_0c06ca98;
P_0c06ca98: /* original 25bb, guest PC 0x0c06ca98 */
if(!s->budget--) { s->failed_pc=0x0c06ca98u; return 0; }
r[5]|=r[11];
goto P_0c06ca9a;
P_0c06ca9a: /* original 4a0b, guest PC 0x0c06ca9a */
if(!s->budget--) { s->failed_pc=0x0c06ca9au; return 0; }
target=r[10];
r[16]=0x0c06ca9eu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06ca9eu) { target=s->pc; goto dispatch; }
goto P_0c06ca9e;
P_0c06ca9c: /* original 64c3, guest PC 0x0c06ca9c */
if(!s->budget--) { s->failed_pc=0x0c06ca9cu; return 0; }
r[4]=r[12];
goto P_0c06ca9e;
P_0c06ca9e: /* original 65e3, guest PC 0x0c06ca9e */
if(!s->budget--) { s->failed_pc=0x0c06ca9eu; return 0; }
r[5]=r[14];
goto P_0c06caa0;
P_0c06caa0: /* original 7513, guest PC 0x0c06caa0 */
if(!s->budget--) { s->failed_pc=0x0c06caa0u; return 0; }
r[5]+=0x00000013u;
goto P_0c06caa2;
P_0c06caa2: /* original 66f2, guest PC 0x0c06caa2 */
if(!s->budget--) { s->failed_pc=0x0c06caa2u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c06caa4;
P_0c06caa4: /* original 4500, guest PC 0x0c06caa4 */
if(!s->budget--) { s->failed_pc=0x0c06caa4u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06caa6;
P_0c06caa6: /* original 6793, guest PC 0x0c06caa6 */
if(!s->budget--) { s->failed_pc=0x0c06caa6u; return 0; }
r[7]=r[9];
goto P_0c06caa8;
P_0c06caa8: /* original 25bb, guest PC 0x0c06caa8 */
if(!s->budget--) { s->failed_pc=0x0c06caa8u; return 0; }
r[5]|=r[11];
goto P_0c06caaa;
P_0c06caaa: /* original 36d8, guest PC 0x0c06caaa */
if(!s->budget--) { s->failed_pc=0x0c06caaau; return 0; }
r[6]-=r[13];
goto P_0c06caac;
P_0c06caac: /* original 4a0b, guest PC 0x0c06caac */
if(!s->budget--) { s->failed_pc=0x0c06caacu; return 0; }
target=r[10];
r[16]=0x0c06cab0u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06cab0u) { target=s->pc; goto dispatch; }
goto P_0c06cab0;
P_0c06caae: /* original 64c3, guest PC 0x0c06caae */
if(!s->budget--) { s->failed_pc=0x0c06caaeu; return 0; }
r[4]=r[12];
goto P_0c06cab0;
P_0c06cab0: /* original a010, guest PC 0x0c06cab0 */
if(!s->budget--) { s->failed_pc=0x0c06cab0u; return 0; }
goto P_0c06cad4;
P_0c06cab2: /* original 0009, guest PC 0x0c06cab2 */
if(!s->budget--) { s->failed_pc=0x0c06cab2u; return 0; }
goto P_0c06cab4;
P_0c06cab4: /* original 694d, guest PC 0x0c06cab4 */
if(!s->budget--) { s->failed_pc=0x0c06cab4u; return 0; }
r[9]=r[4]&65535u;
goto P_0c06cab6;
P_0c06cab6: /* original 4e00, guest PC 0x0c06cab6 */
if(!s->budget--) { s->failed_pc=0x0c06cab6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c06cab8;
P_0c06cab8: /* original 2ebb, guest PC 0x0c06cab8 */
if(!s->budget--) { s->failed_pc=0x0c06cab8u; return 0; }
r[14]|=r[11];
goto P_0c06caba;
P_0c06caba: /* original bc6d, guest PC 0x0c06caba */
if(!s->budget--) { s->failed_pc=0x0c06cabau; return 0; }
target=0x0c06c398u; r[16]=0x0c06cabeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06cabeu) { target=s->pc; goto dispatch; }
goto P_0c06cabe;
P_0c06cabc: /* original 64e3, guest PC 0x0c06cabc */
if(!s->budget--) { s->failed_pc=0x0c06cabcu; return 0; }
r[4]=r[14];
goto P_0c06cabe;
P_0c06cabe: /* original 2008, guest PC 0x0c06cabe */
if(!s->budget--) { s->failed_pc=0x0c06cabeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06cac0;
P_0c06cac0: /* original 8908, guest PC 0x0c06cac0 */
if(!s->budget--) { s->failed_pc=0x0c06cac0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cad4; }
goto P_0c06cac2;
P_0c06cac2: /* original e300, guest PC 0x0c06cac2 */
if(!s->budget--) { s->failed_pc=0x0c06cac2u; return 0; }
r[3]=0x00000000u;
goto P_0c06cac4;
P_0c06cac4: /* original 6593, guest PC 0x0c06cac4 */
if(!s->budget--) { s->failed_pc=0x0c06cac4u; return 0; }
r[5]=r[9];
goto P_0c06cac6;
P_0c06cac6: /* original 66c3, guest PC 0x0c06cac6 */
if(!s->budget--) { s->failed_pc=0x0c06cac6u; return 0; }
r[6]=r[12];
goto P_0c06cac8;
P_0c06cac8: /* original 2f36, guest PC 0x0c06cac8 */
if(!s->budget--) { s->failed_pc=0x0c06cac8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06caca;
P_0c06caca: /* original d21f, guest PC 0x0c06caca */
if(!s->budget--) { s->failed_pc=0x0c06cacau; return 0; }
r[2]=read(ram,0x0c06cb48u,4);
goto P_0c06cacc;
P_0c06cacc: /* original 6733, guest PC 0x0c06cacc */
if(!s->budget--) { s->failed_pc=0x0c06caccu; return 0; }
r[7]=r[3];
goto P_0c06cace;
P_0c06cace: /* original 420b, guest PC 0x0c06cace */
if(!s->budget--) { s->failed_pc=0x0c06caceu; return 0; }
target=r[2];
r[16]=0x0c06cad2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06cad2u) { target=s->pc; goto dispatch; }
goto P_0c06cad2;
P_0c06cad0: /* original 64e3, guest PC 0x0c06cad0 */
if(!s->budget--) { s->failed_pc=0x0c06cad0u; return 0; }
r[4]=r[14];
goto P_0c06cad2;
P_0c06cad2: /* original 7f04, guest PC 0x0c06cad2 */
if(!s->budget--) { s->failed_pc=0x0c06cad2u; return 0; }
r[15]+=0x00000004u;
goto P_0c06cad4;
P_0c06cad4: /* original 7f04, guest PC 0x0c06cad4 */
if(!s->budget--) { s->failed_pc=0x0c06cad4u; return 0; }
r[15]+=0x00000004u;
goto P_0c06cad6;
P_0c06cad6: /* original 4f26, guest PC 0x0c06cad6 */
if(!s->budget--) { s->failed_pc=0x0c06cad6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06cad8;
P_0c06cad8: /* original 69f6, guest PC 0x0c06cad8 */
if(!s->budget--) { s->failed_pc=0x0c06cad8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06cada;
P_0c06cada: /* original 6af6, guest PC 0x0c06cada */
if(!s->budget--) { s->failed_pc=0x0c06cadau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06cadc;
P_0c06cadc: /* original 6bf6, guest PC 0x0c06cadc */
if(!s->budget--) { s->failed_pc=0x0c06cadcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06cade;
P_0c06cade: /* original 6cf6, guest PC 0x0c06cade */
if(!s->budget--) { s->failed_pc=0x0c06cadeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06cae0;
P_0c06cae0: /* original 6df6, guest PC 0x0c06cae0 */
if(!s->budget--) { s->failed_pc=0x0c06cae0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06cae2;
P_0c06cae2: /* original 000b, guest PC 0x0c06cae2 */
if(!s->budget--) { s->failed_pc=0x0c06cae2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06cae4: /* original 6ef6, guest PC 0x0c06cae4 */
if(!s->budget--) { s->failed_pc=0x0c06cae4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06cae6;
P_0c06cae6: /* original 2fe6, guest PC 0x0c06cae6 */
if(!s->budget--) { s->failed_pc=0x0c06cae6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cae8;
P_0c06cae8: /* original 4400, guest PC 0x0c06cae8 */
if(!s->budget--) { s->failed_pc=0x0c06cae8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06caea;
P_0c06caea: /* original 2fd6, guest PC 0x0c06caea */
if(!s->budget--) { s->failed_pc=0x0c06caeau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06caec;
P_0c06caec: /* original e307, guest PC 0x0c06caec */
if(!s->budget--) { s->failed_pc=0x0c06caecu; return 0; }
r[3]=0x00000007u;
goto P_0c06caee;
P_0c06caee: /* original 2fc6, guest PC 0x0c06caee */
if(!s->budget--) { s->failed_pc=0x0c06caeeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06caf0;
P_0c06caf0: /* original 6d43, guest PC 0x0c06caf0 */
if(!s->budget--) { s->failed_pc=0x0c06caf0u; return 0; }
r[13]=r[4];
goto P_0c06caf2;
P_0c06caf2: /* original 2fb6, guest PC 0x0c06caf2 */
if(!s->budget--) { s->failed_pc=0x0c06caf2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06caf4;
P_0c06caf4: /* original 453d, guest PC 0x0c06caf4 */
if(!s->budget--) { s->failed_pc=0x0c06caf4u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c06caf6;
P_0c06caf6: /* original 2fa6, guest PC 0x0c06caf6 */
if(!s->budget--) { s->failed_pc=0x0c06caf6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06caf8;
P_0c06caf8: /* original 2d5b, guest PC 0x0c06caf8 */
if(!s->budget--) { s->failed_pc=0x0c06caf8u; return 0; }
r[13]|=r[5];
goto P_0c06cafa;
P_0c06cafa: /* original 2f96, guest PC 0x0c06cafa */
if(!s->budget--) { s->failed_pc=0x0c06cafau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cafc;
P_0c06cafc: /* original 6e63, guest PC 0x0c06cafc */
if(!s->budget--) { s->failed_pc=0x0c06cafcu; return 0; }
r[14]=r[6];
goto P_0c06cafe;
P_0c06cafe: /* original d514, guest PC 0x0c06cafe */
if(!s->budget--) { s->failed_pc=0x0c06cafeu; return 0; }
r[5]=read(ram,0x0c06cb50u,4);
goto P_0c06cb00;
P_0c06cb00: /* original 901f, guest PC 0x0c06cb00 */
if(!s->budget--) { s->failed_pc=0x0c06cb00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cb42u,2);
goto P_0c06cb02;
P_0c06cb02: /* original 4f22, guest PC 0x0c06cb02 */
if(!s->budget--) { s->failed_pc=0x0c06cb02u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06cb04;
P_0c06cb04: /* original 045c, guest PC 0x0c06cb04 */
if(!s->budget--) { s->failed_pc=0x0c06cb04u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c06cb06;
P_0c06cb06: /* original da13, guest PC 0x0c06cb06 */
if(!s->budget--) { s->failed_pc=0x0c06cb06u; return 0; }
r[10]=read(ram,0x0c06cb54u,4);
goto P_0c06cb08;
P_0c06cb08: /* original 6043, guest PC 0x0c06cb08 */
if(!s->budget--) { s->failed_pc=0x0c06cb08u; return 0; }
r[0]=r[4];
goto P_0c06cb0a;
P_0c06cb0a: /* original 5bf7, guest PC 0x0c06cb0a */
if(!s->budget--) { s->failed_pc=0x0c06cb0au; return 0; }
r[11]=read(ram,r[15]+28,4);
goto P_0c06cb0c;
P_0c06cb0c: /* original 8801, guest PC 0x0c06cb0c */
if(!s->budget--) { s->failed_pc=0x0c06cb0cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cb0e;
P_0c06cb0e: /* original 8d2e, guest PC 0x0c06cb0e */
if(!s->budget--) { s->failed_pc=0x0c06cb0eu; return 0; }
cond=r[17]&1u;
r[9]=r[7];
if(cond) { goto P_0c06cb6e; }
goto P_0c06cb12;
P_0c06cb10: /* original 6973, guest PC 0x0c06cb10 */
if(!s->budget--) { s->failed_pc=0x0c06cb10u; return 0; }
r[9]=r[7];
goto P_0c06cb12;
P_0c06cb12: /* original 9017, guest PC 0x0c06cb12 */
if(!s->budget--) { s->failed_pc=0x0c06cb12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cb44u,2);
goto P_0c06cb14;
P_0c06cb14: /* original d411, guest PC 0x0c06cb14 */
if(!s->budget--) { s->failed_pc=0x0c06cb14u; return 0; }
r[4]=read(ram,0x0c06cb5cu,4);
goto P_0c06cb16;
P_0c06cb16: /* original 0c5c, guest PC 0x0c06cb16 */
if(!s->budget--) { s->failed_pc=0x0c06cb16u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c06cb18;
P_0c06cb18: /* original d50f, guest PC 0x0c06cb18 */
if(!s->budget--) { s->failed_pc=0x0c06cb18u; return 0; }
r[5]=read(ram,0x0c06cb58u,4);
goto P_0c06cb1a;
P_0c06cb1a: /* original 60c3, guest PC 0x0c06cb1a */
if(!s->budget--) { s->failed_pc=0x0c06cb1au; return 0; }
r[0]=r[12];
goto P_0c06cb1c;
P_0c06cb1c: /* original 8801, guest PC 0x0c06cb1c */
if(!s->budget--) { s->failed_pc=0x0c06cb1cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cb1e;
P_0c06cb1e: /* original 8d04, guest PC 0x0c06cb1e */
if(!s->budget--) { s->failed_pc=0x0c06cb1eu; return 0; }
cond=r[17]&1u;
r[6]=0x00000001u;
if(cond) { goto P_0c06cb2a; }
goto P_0c06cb22;
P_0c06cb20: /* original e601, guest PC 0x0c06cb20 */
if(!s->budget--) { s->failed_pc=0x0c06cb20u; return 0; }
r[6]=0x00000001u;
goto P_0c06cb22;
P_0c06cb22: /* original 3c90, guest PC 0x0c06cb22 */
if(!s->budget--) { s->failed_pc=0x0c06cb22u; return 0; }
r[17]=(r[17]&~1u)|((r[12]==r[9])!=0);
goto P_0c06cb24;
P_0c06cb24: /* original 8901, guest PC 0x0c06cb24 */
if(!s->budget--) { s->failed_pc=0x0c06cb24u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cb2a; }
goto P_0c06cb26;
P_0c06cb26: /* original 2998, guest PC 0x0c06cb26 */
if(!s->budget--) { s->failed_pc=0x0c06cb26u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c06cb28;
P_0c06cb28: /* original 8b37, guest PC 0x0c06cb28 */
if(!s->budget--) { s->failed_pc=0x0c06cb28u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06cb9a; }
goto P_0c06cb2a;
P_0c06cb2a: /* original 60b3, guest PC 0x0c06cb2a */
if(!s->budget--) { s->failed_pc=0x0c06cb2au; return 0; }
r[0]=r[11];
goto P_0c06cb2c;
P_0c06cb2c: /* original 8801, guest PC 0x0c06cb2c */
if(!s->budget--) { s->failed_pc=0x0c06cb2cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cb2e;
P_0c06cb2e: /* original 8925, guest PC 0x0c06cb2e */
if(!s->budget--) { s->failed_pc=0x0c06cb2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cb7c; }
goto P_0c06cb30;
P_0c06cb30: /* original 3e66, guest PC 0x0c06cb30 */
if(!s->budget--) { s->failed_pc=0x0c06cb30u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[6])!=0);
goto P_0c06cb32;
P_0c06cb32: /* original 8d15, guest PC 0x0c06cb32 */
if(!s->budget--) { s->failed_pc=0x0c06cb32u; return 0; }
cond=r[17]&1u;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
if(cond) { goto P_0c06cb60; }
goto P_0c06cb36;
P_0c06cb34: /* original 2fb6, guest PC 0x0c06cb34 */
if(!s->budget--) { s->failed_pc=0x0c06cb34u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cb36;
P_0c06cb36: /* original a014, guest PC 0x0c06cb36 */
if(!s->budget--) { s->failed_pc=0x0c06cb36u; return 0; }
r[6]=r[5];
goto P_0c06cb62;
P_0c06cb38: /* original 6653, guest PC 0x0c06cb38 */
if(!s->budget--) { s->failed_pc=0x0c06cb38u; return 0; }
r[6]=r[5];
return vf3_matrix_family(0x0c06cb3au,s,ram);
P_0c06cb60: /* original 6643, guest PC 0x0c06cb60 */
if(!s->budget--) { s->failed_pc=0x0c06cb60u; return 0; }
r[6]=r[4];
goto P_0c06cb62;
P_0c06cb62: /* original 65a3, guest PC 0x0c06cb62 */
if(!s->budget--) { s->failed_pc=0x0c06cb62u; return 0; }
r[5]=r[10];
goto P_0c06cb64;
P_0c06cb64: /* original 67e3, guest PC 0x0c06cb64 */
if(!s->budget--) { s->failed_pc=0x0c06cb64u; return 0; }
r[7]=r[14];
goto P_0c06cb66;
P_0c06cb66: /* original bc4e, guest PC 0x0c06cb66 */
if(!s->budget--) { s->failed_pc=0x0c06cb66u; return 0; }
target=0x0c06c406u; r[16]=0x0c06cb6au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06cb6au) { target=s->pc; goto dispatch; }
goto P_0c06cb6a;
P_0c06cb68: /* original 64d3, guest PC 0x0c06cb68 */
if(!s->budget--) { s->failed_pc=0x0c06cb68u; return 0; }
r[4]=r[13];
goto P_0c06cb6a;
P_0c06cb6a: /* original a033, guest PC 0x0c06cb6a */
if(!s->budget--) { s->failed_pc=0x0c06cb6au; return 0; }
r[15]+=0x00000004u;
goto P_0c06cbd4;
P_0c06cb6c: /* original 7f04, guest PC 0x0c06cb6c */
if(!s->budget--) { s->failed_pc=0x0c06cb6cu; return 0; }
r[15]+=0x00000004u;
goto P_0c06cb6e;
P_0c06cb6e: /* original d23c, guest PC 0x0c06cb6e */
if(!s->budget--) { s->failed_pc=0x0c06cb6eu; return 0; }
r[2]=read(ram,0x0c06cc60u,4);
goto P_0c06cb70;
P_0c06cb70: /* original e601, guest PC 0x0c06cb70 */
if(!s->budget--) { s->failed_pc=0x0c06cb70u; return 0; }
r[6]=0x00000001u;
goto P_0c06cb72;
P_0c06cb72: /* original d53a, guest PC 0x0c06cb72 */
if(!s->budget--) { s->failed_pc=0x0c06cb72u; return 0; }
r[5]=read(ram,0x0c06cc5cu,4);
goto P_0c06cb74;
P_0c06cb74: /* original 420b, guest PC 0x0c06cb74 */
if(!s->budget--) { s->failed_pc=0x0c06cb74u; return 0; }
target=r[2];
r[16]=0x0c06cb78u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06cb78u) { target=s->pc; goto dispatch; }
goto P_0c06cb78;
P_0c06cb76: /* original 64d3, guest PC 0x0c06cb76 */
if(!s->budget--) { s->failed_pc=0x0c06cb76u; return 0; }
r[4]=r[13];
goto P_0c06cb78;
P_0c06cb78: /* original a02c, guest PC 0x0c06cb78 */
if(!s->budget--) { s->failed_pc=0x0c06cb78u; return 0; }
goto P_0c06cbd4;
P_0c06cb7a: /* original 0009, guest PC 0x0c06cb7a */
if(!s->budget--) { s->failed_pc=0x0c06cb7au; return 0; }
goto P_0c06cb7c;
P_0c06cb7c: /* original 3e66, guest PC 0x0c06cb7c */
if(!s->budget--) { s->failed_pc=0x0c06cb7cu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[6])!=0);
goto P_0c06cb7e;
P_0c06cb7e: /* original 8f02, guest PC 0x0c06cb7e */
if(!s->budget--) { s->failed_pc=0x0c06cb7eu; return 0; }
cond=r[17]&1u;
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
if(!cond) { goto P_0c06cb86; }
goto P_0c06cb82;
P_0c06cb80: /* original 2fe6, guest PC 0x0c06cb80 */
if(!s->budget--) { s->failed_pc=0x0c06cb80u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cb82;
P_0c06cb82: /* original a001, guest PC 0x0c06cb82 */
if(!s->budget--) { s->failed_pc=0x0c06cb82u; return 0; }
r[6]=r[4];
goto P_0c06cb88;
P_0c06cb84: /* original 6643, guest PC 0x0c06cb84 */
if(!s->budget--) { s->failed_pc=0x0c06cb84u; return 0; }
r[6]=r[4];
goto P_0c06cb86;
P_0c06cb86: /* original 6653, guest PC 0x0c06cb86 */
if(!s->budget--) { s->failed_pc=0x0c06cb86u; return 0; }
r[6]=r[5];
goto P_0c06cb88;
P_0c06cb88: /* original 2f66, guest PC 0x0c06cb88 */
if(!s->budget--) { s->failed_pc=0x0c06cb88u; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cb8a;
P_0c06cb8a: /* original 2fa6, guest PC 0x0c06cb8a */
if(!s->budget--) { s->failed_pc=0x0c06cb8au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cb8c;
P_0c06cb8c: /* original d335, guest PC 0x0c06cb8c */
if(!s->budget--) { s->failed_pc=0x0c06cb8cu; return 0; }
r[3]=read(ram,0x0c06cc64u,4);
goto P_0c06cb8e;
P_0c06cb8e: /* original 2f36, guest PC 0x0c06cb8e */
if(!s->budget--) { s->failed_pc=0x0c06cb8eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cb90;
P_0c06cb90: /* original d235, guest PC 0x0c06cb90 */
if(!s->budget--) { s->failed_pc=0x0c06cb90u; return 0; }
r[2]=read(ram,0x0c06cc68u,4);
goto P_0c06cb92;
P_0c06cb92: /* original 420b, guest PC 0x0c06cb92 */
if(!s->budget--) { s->failed_pc=0x0c06cb92u; return 0; }
target=r[2];
r[16]=0x0c06cb96u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06cb96u) { target=s->pc; goto dispatch; }
goto P_0c06cb96;
P_0c06cb94: /* original 64d3, guest PC 0x0c06cb94 */
if(!s->budget--) { s->failed_pc=0x0c06cb94u; return 0; }
r[4]=r[13];
goto P_0c06cb96;
P_0c06cb96: /* original a010, guest PC 0x0c06cb96 */
if(!s->budget--) { s->failed_pc=0x0c06cb96u; return 0; }
goto P_0c06cbba;
P_0c06cb98: /* original 0009, guest PC 0x0c06cb98 */
if(!s->budget--) { s->failed_pc=0x0c06cb98u; return 0; }
goto P_0c06cb9a;
P_0c06cb9a: /* original 60b3, guest PC 0x0c06cb9a */
if(!s->budget--) { s->failed_pc=0x0c06cb9au; return 0; }
r[0]=r[11];
goto P_0c06cb9c;
P_0c06cb9c: /* original d733, guest PC 0x0c06cb9c */
if(!s->budget--) { s->failed_pc=0x0c06cb9cu; return 0; }
r[7]=read(ram,0x0c06cc6cu,4);
goto P_0c06cb9e;
P_0c06cb9e: /* original 8801, guest PC 0x0c06cb9e */
if(!s->budget--) { s->failed_pc=0x0c06cb9eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cba0;
P_0c06cba0: /* original 890d, guest PC 0x0c06cba0 */
if(!s->budget--) { s->failed_pc=0x0c06cba0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cbbe; }
goto P_0c06cba2;
P_0c06cba2: /* original 3e66, guest PC 0x0c06cba2 */
if(!s->budget--) { s->failed_pc=0x0c06cba2u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[6])!=0);
goto P_0c06cba4;
P_0c06cba4: /* original 8d02, guest PC 0x0c06cba4 */
if(!s->budget--) { s->failed_pc=0x0c06cba4u; return 0; }
cond=r[17]&1u;
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
if(cond) { goto P_0c06cbac; }
goto P_0c06cba8;
P_0c06cba6: /* original 2fc6, guest PC 0x0c06cba6 */
if(!s->budget--) { s->failed_pc=0x0c06cba6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cba8;
P_0c06cba8: /* original a001, guest PC 0x0c06cba8 */
if(!s->budget--) { s->failed_pc=0x0c06cba8u; return 0; }
r[6]=r[5];
goto P_0c06cbae;
P_0c06cbaa: /* original 6653, guest PC 0x0c06cbaa */
if(!s->budget--) { s->failed_pc=0x0c06cbaau; return 0; }
r[6]=r[5];
goto P_0c06cbac;
P_0c06cbac: /* original 6643, guest PC 0x0c06cbac */
if(!s->budget--) { s->failed_pc=0x0c06cbacu; return 0; }
r[6]=r[4];
goto P_0c06cbae;
P_0c06cbae: /* original 2f96, guest PC 0x0c06cbae */
if(!s->budget--) { s->failed_pc=0x0c06cbaeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbb0;
P_0c06cbb0: /* original 65a3, guest PC 0x0c06cbb0 */
if(!s->budget--) { s->failed_pc=0x0c06cbb0u; return 0; }
r[5]=r[10];
goto P_0c06cbb2;
P_0c06cbb2: /* original 2fb6, guest PC 0x0c06cbb2 */
if(!s->budget--) { s->failed_pc=0x0c06cbb2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbb4;
P_0c06cbb4: /* original 2fe6, guest PC 0x0c06cbb4 */
if(!s->budget--) { s->failed_pc=0x0c06cbb4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbb6;
P_0c06cbb6: /* original b015, guest PC 0x0c06cbb6 */
if(!s->budget--) { s->failed_pc=0x0c06cbb6u; return 0; }
target=0x0c06cbe4u; r[16]=0x0c06cbbau;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06cbbau) { target=s->pc; goto dispatch; }
goto P_0c06cbba;
P_0c06cbb8: /* original 64d3, guest PC 0x0c06cbb8 */
if(!s->budget--) { s->failed_pc=0x0c06cbb8u; return 0; }
r[4]=r[13];
goto P_0c06cbba;
P_0c06cbba: /* original a00b, guest PC 0x0c06cbba */
if(!s->budget--) { s->failed_pc=0x0c06cbbau; return 0; }
r[15]+=0x00000010u;
goto P_0c06cbd4;
P_0c06cbbc: /* original 7f10, guest PC 0x0c06cbbc */
if(!s->budget--) { s->failed_pc=0x0c06cbbcu; return 0; }
r[15]+=0x00000010u;
goto P_0c06cbbe;
P_0c06cbbe: /* original 2fc6, guest PC 0x0c06cbbe */
if(!s->budget--) { s->failed_pc=0x0c06cbbeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbc0;
P_0c06cbc0: /* original 2f96, guest PC 0x0c06cbc0 */
if(!s->budget--) { s->failed_pc=0x0c06cbc0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbc2;
P_0c06cbc2: /* original 2f76, guest PC 0x0c06cbc2 */
if(!s->budget--) { s->failed_pc=0x0c06cbc2u; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbc4;
P_0c06cbc4: /* original 2fe6, guest PC 0x0c06cbc4 */
if(!s->budget--) { s->failed_pc=0x0c06cbc4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbc6;
P_0c06cbc6: /* original 2fa6, guest PC 0x0c06cbc6 */
if(!s->budget--) { s->failed_pc=0x0c06cbc6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbc8;
P_0c06cbc8: /* original d229, guest PC 0x0c06cbc8 */
if(!s->budget--) { s->failed_pc=0x0c06cbc8u; return 0; }
r[2]=read(ram,0x0c06cc70u,4);
goto P_0c06cbca;
P_0c06cbca: /* original 2f26, guest PC 0x0c06cbca */
if(!s->budget--) { s->failed_pc=0x0c06cbcau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbcc;
P_0c06cbcc: /* original d326, guest PC 0x0c06cbcc */
if(!s->budget--) { s->failed_pc=0x0c06cbccu; return 0; }
r[3]=read(ram,0x0c06cc68u,4);
goto P_0c06cbce;
P_0c06cbce: /* original 430b, guest PC 0x0c06cbce */
if(!s->budget--) { s->failed_pc=0x0c06cbceu; return 0; }
target=r[3];
r[16]=0x0c06cbd2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06cbd2u) { target=s->pc; goto dispatch; }
goto P_0c06cbd2;
P_0c06cbd0: /* original 64d3, guest PC 0x0c06cbd0 */
if(!s->budget--) { s->failed_pc=0x0c06cbd0u; return 0; }
r[4]=r[13];
goto P_0c06cbd2;
P_0c06cbd2: /* original 7f18, guest PC 0x0c06cbd2 */
if(!s->budget--) { s->failed_pc=0x0c06cbd2u; return 0; }
r[15]+=0x00000018u;
goto P_0c06cbd4;
P_0c06cbd4: /* original 4f26, guest PC 0x0c06cbd4 */
if(!s->budget--) { s->failed_pc=0x0c06cbd4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06cbd6;
P_0c06cbd6: /* original 69f6, guest PC 0x0c06cbd6 */
if(!s->budget--) { s->failed_pc=0x0c06cbd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06cbd8;
P_0c06cbd8: /* original 6af6, guest PC 0x0c06cbd8 */
if(!s->budget--) { s->failed_pc=0x0c06cbd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06cbda;
P_0c06cbda: /* original 6bf6, guest PC 0x0c06cbda */
if(!s->budget--) { s->failed_pc=0x0c06cbdau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06cbdc;
P_0c06cbdc: /* original 6cf6, guest PC 0x0c06cbdc */
if(!s->budget--) { s->failed_pc=0x0c06cbdcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06cbde;
P_0c06cbde: /* original 6df6, guest PC 0x0c06cbde */
if(!s->budget--) { s->failed_pc=0x0c06cbdeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06cbe0;
P_0c06cbe0: /* original 000b, guest PC 0x0c06cbe0 */
if(!s->budget--) { s->failed_pc=0x0c06cbe0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06cbe2: /* original 6ef6, guest PC 0x0c06cbe2 */
if(!s->budget--) { s->failed_pc=0x0c06cbe2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06cbe4;
P_0c06cbe4: /* original 4f22, guest PC 0x0c06cbe4 */
if(!s->budget--) { s->failed_pc=0x0c06cbe4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06cbe6;
P_0c06cbe6: /* original e018, guest PC 0x0c06cbe6 */
if(!s->budget--) { s->failed_pc=0x0c06cbe6u; return 0; }
r[0]=0x00000018u;
goto P_0c06cbe8;
P_0c06cbe8: /* original 7ff8, guest PC 0x0c06cbe8 */
if(!s->budget--) { s->failed_pc=0x0c06cbe8u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06cbea;
P_0c06cbea: /* original 2f42, guest PC 0x0c06cbea */
if(!s->budget--) { s->failed_pc=0x0c06cbeau; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06cbec;
P_0c06cbec: /* original 1f71, guest PC 0x0c06cbec */
if(!s->budget--) { s->failed_pc=0x0c06cbecu; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c06cbee;
P_0c06cbee: /* original 03fc, guest PC 0x0c06cbee */
if(!s->budget--) { s->failed_pc=0x0c06cbeeu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c06cbf0;
P_0c06cbf0: /* original e018, guest PC 0x0c06cbf0 */
if(!s->budget--) { s->failed_pc=0x0c06cbf0u; return 0; }
r[0]=0x00000018u;
goto P_0c06cbf2;
P_0c06cbf2: /* original 2f36, guest PC 0x0c06cbf2 */
if(!s->budget--) { s->failed_pc=0x0c06cbf2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbf4;
P_0c06cbf4: /* original 02fc, guest PC 0x0c06cbf4 */
if(!s->budget--) { s->failed_pc=0x0c06cbf4u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c06cbf6;
P_0c06cbf6: /* original e01c, guest PC 0x0c06cbf6 */
if(!s->budget--) { s->failed_pc=0x0c06cbf6u; return 0; }
r[0]=0x0000001cu;
goto P_0c06cbf8;
P_0c06cbf8: /* original 2f26, guest PC 0x0c06cbf8 */
if(!s->budget--) { s->failed_pc=0x0c06cbf8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbfa;
P_0c06cbfa: /* original 53f3, guest PC 0x0c06cbfa */
if(!s->budget--) { s->failed_pc=0x0c06cbfau; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c06cbfc;
P_0c06cbfc: /* original 2f36, guest PC 0x0c06cbfc */
if(!s->budget--) { s->failed_pc=0x0c06cbfcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbfe;
P_0c06cbfe: /* original 02fc, guest PC 0x0c06cbfe */
if(!s->budget--) { s->failed_pc=0x0c06cbfeu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c06cc00;
P_0c06cc00: /* original e01c, guest PC 0x0c06cc00 */
if(!s->budget--) { s->failed_pc=0x0c06cc00u; return 0; }
r[0]=0x0000001cu;
goto P_0c06cc02;
P_0c06cc02: /* original 2f26, guest PC 0x0c06cc02 */
if(!s->budget--) { s->failed_pc=0x0c06cc02u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cc04;
P_0c06cc04: /* original 00fc, guest PC 0x0c06cc04 */
if(!s->budget--) { s->failed_pc=0x0c06cc04u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c06cc06;
P_0c06cc06: /* original 2f06, guest PC 0x0c06cc06 */
if(!s->budget--) { s->failed_pc=0x0c06cc06u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cc08;
P_0c06cc08: /* original 2f66, guest PC 0x0c06cc08 */
if(!s->budget--) { s->failed_pc=0x0c06cc08u; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cc0a;
P_0c06cc0a: /* original 2f56, guest PC 0x0c06cc0a */
if(!s->budget--) { s->failed_pc=0x0c06cc0au; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cc0c;
P_0c06cc0c: /* original d319, guest PC 0x0c06cc0c */
if(!s->budget--) { s->failed_pc=0x0c06cc0cu; return 0; }
r[3]=read(ram,0x0c06cc74u,4);
goto P_0c06cc0e;
P_0c06cc0e: /* original 2f36, guest PC 0x0c06cc0e */
if(!s->budget--) { s->failed_pc=0x0c06cc0eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cc10;
P_0c06cc10: /* original d215, guest PC 0x0c06cc10 */
if(!s->budget--) { s->failed_pc=0x0c06cc10u; return 0; }
r[2]=read(ram,0x0c06cc68u,4);
goto P_0c06cc12;
P_0c06cc12: /* original 420b, guest PC 0x0c06cc12 */
if(!s->budget--) { s->failed_pc=0x0c06cc12u; return 0; }
target=r[2];
r[16]=0x0c06cc16u;
r[4]=read(ram,r[15]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06cc16u) { target=s->pc; goto dispatch; }
goto P_0c06cc16;
P_0c06cc14: /* original 54f8, guest PC 0x0c06cc14 */
if(!s->budget--) { s->failed_pc=0x0c06cc14u; return 0; }
r[4]=read(ram,r[15]+32,4);
goto P_0c06cc16;
P_0c06cc16: /* original 7f28, guest PC 0x0c06cc16 */
if(!s->budget--) { s->failed_pc=0x0c06cc16u; return 0; }
r[15]+=0x00000028u;
goto P_0c06cc18;
P_0c06cc18: /* original 4f26, guest PC 0x0c06cc18 */
if(!s->budget--) { s->failed_pc=0x0c06cc18u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06cc1a;
P_0c06cc1a: /* original 000b, guest PC 0x0c06cc1a */
if(!s->budget--) { s->failed_pc=0x0c06cc1au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06cc1c: /* original 0009, guest PC 0x0c06cc1c */
if(!s->budget--) { s->failed_pc=0x0c06cc1cu; return 0; }
return vf3_matrix_family(0x0c06cc1eu,s,ram);
P_0c085666: /* original 4f22, guest PC 0x0c085666 */
if(!s->budget--) { s->failed_pc=0x0c085666u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c085668;
P_0c085668: /* original d352, guest PC 0x0c085668 */
if(!s->budget--) { s->failed_pc=0x0c085668u; return 0; }
r[3]=read(ram,0x0c0857b4u,4);
goto P_0c08566a;
P_0c08566a: /* original 7ff4, guest PC 0x0c08566a */
if(!s->budget--) { s->failed_pc=0x0c08566au; return 0; }
r[15]+=0xfffffff4u;
goto P_0c08566c;
P_0c08566c: /* original 1f32, guest PC 0x0c08566c */
if(!s->budget--) { s->failed_pc=0x0c08566cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c08566e;
P_0c08566e: /* original d154, guest PC 0x0c08566e */
if(!s->budget--) { s->failed_pc=0x0c08566eu; return 0; }
r[1]=read(ram,0x0c0857c0u,4);
goto P_0c085670;
P_0c085670: /* original d352, guest PC 0x0c085670 */
if(!s->budget--) { s->failed_pc=0x0c085670u; return 0; }
r[3]=read(ram,0x0c0857bcu,4);
goto P_0c085672;
P_0c085672: /* original 6212, guest PC 0x0c085672 */
if(!s->budget--) { s->failed_pc=0x0c085672u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c085674;
P_0c085674: /* original ff08, guest PC 0x0c085674 */
if(!s->budget--) { s->failed_pc=0x0c085674u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c085676;
P_0c085676: /* original 2238, guest PC 0x0c085676 */
if(!s->budget--) { s->failed_pc=0x0c085676u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c085678;
P_0c085678: /* original 8d02, guest PC 0x0c085678 */
if(!s->budget--) { s->failed_pc=0x0c085678u; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(cond) { goto P_0c085680; }
goto P_0c08567c;
P_0c08567a: /* original 6e43, guest PC 0x0c08567a */
if(!s->budget--) { s->failed_pc=0x0c08567au; return 0; }
r[14]=r[4];
goto P_0c08567c;
P_0c08567c: /* original a0cd, guest PC 0x0c08567c */
if(!s->budget--) { s->failed_pc=0x0c08567cu; return 0; }
goto P_0c08581a;
P_0c08567e: /* original 0009, guest PC 0x0c08567e */
if(!s->budget--) { s->failed_pc=0x0c08567eu; return 0; }
goto P_0c085680;
P_0c085680: /* original 9090, guest PC 0x0c085680 */
if(!s->budget--) { s->failed_pc=0x0c085680u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857a4u,2);
goto P_0c085682;
P_0c085682: /* original 9390, guest PC 0x0c085682 */
if(!s->budget--) { s->failed_pc=0x0c085682u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857a6u,2);
goto P_0c085684;
P_0c085684: /* original 0bed, guest PC 0x0c085684 */
if(!s->budget--) { s->failed_pc=0x0c085684u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085686;
P_0c085686: /* original 70fe, guest PC 0x0c085686 */
if(!s->budget--) { s->failed_pc=0x0c085686u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c085688;
P_0c085688: /* original 928e, guest PC 0x0c085688 */
if(!s->budget--) { s->failed_pc=0x0c085688u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857a8u,2);
goto P_0c08568a;
P_0c08568a: /* original 0ced, guest PC 0x0c08568a */
if(!s->budget--) { s->failed_pc=0x0c08568au; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08568c;
P_0c08568c: /* original 7004, guest PC 0x0c08568c */
if(!s->budget--) { s->failed_pc=0x0c08568cu; return 0; }
r[0]+=0x00000004u;
goto P_0c08568e;
P_0c08568e: /* original 0aed, guest PC 0x0c08568e */
if(!s->budget--) { s->failed_pc=0x0c08568eu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085690;
P_0c085690: /* original 3b3c, guest PC 0x0c085690 */
if(!s->budget--) { s->failed_pc=0x0c085690u; return 0; }
r[11]+=r[3];
goto P_0c085692;
P_0c085692: /* original 3c2c, guest PC 0x0c085692 */
if(!s->budget--) { s->failed_pc=0x0c085692u; return 0; }
r[12]+=r[2];
goto P_0c085694;
P_0c085694: /* original 9189, guest PC 0x0c085694 */
if(!s->budget--) { s->failed_pc=0x0c085694u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857aau,2);
goto P_0c085696;
P_0c085696: /* original e0ff, guest PC 0x0c085696 */
if(!s->budget--) { s->failed_pc=0x0c085696u; return 0; }
r[0]=0xffffffffu;
goto P_0c085698;
P_0c085698: /* original 63cf, guest PC 0x0c085698 */
if(!s->budget--) { s->failed_pc=0x0c085698u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c08569a;
P_0c08569a: /* original 3303, guest PC 0x0c08569a */
if(!s->budget--) { s->failed_pc=0x0c08569au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[0])!=0);
goto P_0c08569c;
P_0c08569c: /* original 8f0f, guest PC 0x0c08569c */
if(!s->budget--) { s->failed_pc=0x0c08569cu; return 0; }
cond=r[17]&1u;
r[10]+=r[1];
if(!cond) { goto P_0c0856be; }
goto P_0c0856a0;
P_0c08569e: /* original 3a1c, guest PC 0x0c08569e */
if(!s->budget--) { s->failed_pc=0x0c08569eu; return 0; }
r[10]+=r[1];
goto P_0c0856a0;
P_0c0856a0: /* original d348, guest PC 0x0c0856a0 */
if(!s->budget--) { s->failed_pc=0x0c0856a0u; return 0; }
r[3]=read(ram,0x0c0857c4u,4);
goto P_0c0856a2;
P_0c0856a2: /* original 430b, guest PC 0x0c0856a2 */
if(!s->budget--) { s->failed_pc=0x0c0856a2u; return 0; }
target=r[3];
r[16]=0x0c0856a6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0856a6u) { target=s->pc; goto dispatch; }
goto P_0c0856a6;
P_0c0856a4: /* original 0009, guest PC 0x0c0856a4 */
if(!s->budget--) { s->failed_pc=0x0c0856a4u; return 0; }
goto P_0c0856a6;
P_0c0856a6: /* original e2e2, guest PC 0x0c0856a6 */
if(!s->budget--) { s->failed_pc=0x0c0856a6u; return 0; }
r[2]=0xffffffe2u;
goto P_0c0856a8;
P_0c0856a8: /* original 6303, guest PC 0x0c0856a8 */
if(!s->budget--) { s->failed_pc=0x0c0856a8u; return 0; }
r[3]=r[0];
goto P_0c0856aa;
P_0c0856aa: /* original 432c, guest PC 0x0c0856aa */
if(!s->budget--) { s->failed_pc=0x0c0856aau; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c0856ac;
P_0c0856ac: /* original d446, guest PC 0x0c0856ac */
if(!s->budget--) { s->failed_pc=0x0c0856acu; return 0; }
r[4]=read(ram,0x0c0857c8u,4);
goto P_0c0856ae;
P_0c0856ae: /* original 4008, guest PC 0x0c0856ae */
if(!s->budget--) { s->failed_pc=0x0c0856aeu; return 0; }
r[0]<<=2;
goto P_0c0856b0;
P_0c0856b0: /* original e50c, guest PC 0x0c0856b0 */
if(!s->budget--) { s->failed_pc=0x0c0856b0u; return 0; }
r[5]=0x0000000cu;
goto P_0c0856b2;
P_0c0856b2: /* original 203b, guest PC 0x0c0856b2 */
if(!s->budget--) { s->failed_pc=0x0c0856b2u; return 0; }
r[0]|=r[3];
goto P_0c0856b4;
P_0c0856b4: /* original 2509, guest PC 0x0c0856b4 */
if(!s->budget--) { s->failed_pc=0x0c0856b4u; return 0; }
r[5]&=r[0];
goto P_0c0856b6;
P_0c0856b6: /* original 6053, guest PC 0x0c0856b6 */
if(!s->budget--) { s->failed_pc=0x0c0856b6u; return 0; }
r[0]=r[5];
goto P_0c0856b8;
P_0c0856b8: /* original f446, guest PC 0x0c0856b8 */
if(!s->budget--) { s->failed_pc=0x0c0856b8u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0856ba;
P_0c0856ba: /* original 9077, guest PC 0x0c0856ba */
if(!s->budget--) { s->failed_pc=0x0c0856bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857acu,2);
goto P_0c0856bc;
P_0c0856bc: /* original fe47, guest PC 0x0c0856bc */
if(!s->budget--) { s->failed_pc=0x0c0856bcu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0856be;
P_0c0856be: /* original 9071, guest PC 0x0c0856be */
if(!s->budget--) { s->failed_pc=0x0c0856beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857a4u,2);
goto P_0c0856c0;
P_0c0856c0: /* original 0eb5, guest PC 0x0c0856c0 */
if(!s->budget--) { s->failed_pc=0x0c0856c0u; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c0856c2;
P_0c0856c2: /* original 70fe, guest PC 0x0c0856c2 */
if(!s->budget--) { s->failed_pc=0x0c0856c2u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0856c4;
P_0c0856c4: /* original 0ec5, guest PC 0x0c0856c4 */
if(!s->budget--) { s->failed_pc=0x0c0856c4u; return 0; }
write(ram,r[14]+r[0],r[12],2);
goto P_0c0856c6;
P_0c0856c6: /* original 7004, guest PC 0x0c0856c6 */
if(!s->budget--) { s->failed_pc=0x0c0856c6u; return 0; }
r[0]+=0x00000004u;
goto P_0c0856c8;
P_0c0856c8: /* original 0ea5, guest PC 0x0c0856c8 */
if(!s->budget--) { s->failed_pc=0x0c0856c8u; return 0; }
write(ram,r[14]+r[0],r[10],2);
goto P_0c0856ca;
P_0c0856ca: /* original e004, guest PC 0x0c0856ca */
if(!s->budget--) { s->failed_pc=0x0c0856cau; return 0; }
r[0]=0x00000004u;
goto P_0c0856cc;
P_0c0856cc: /* original d83f, guest PC 0x0c0856cc */
if(!s->budget--) { s->failed_pc=0x0c0856ccu; return 0; }
r[8]=read(ram,0x0c0857ccu,4);
goto P_0c0856ce;
P_0c0856ce: /* original d341, guest PC 0x0c0856ce */
if(!s->budget--) { s->failed_pc=0x0c0856ceu; return 0; }
r[3]=read(ram,0x0c0857d4u,4);
goto P_0c0856d0;
P_0c0856d0: /* original 6483, guest PC 0x0c0856d0 */
if(!s->budget--) { s->failed_pc=0x0c0856d0u; return 0; }
r[4]=r[8];
goto P_0c0856d2;
P_0c0856d2: /* original f546, guest PC 0x0c0856d2 */
if(!s->budget--) { s->failed_pc=0x0c0856d2u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0856d4;
P_0c0856d4: /* original 6432, guest PC 0x0c0856d4 */
if(!s->budget--) { s->failed_pc=0x0c0856d4u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0856d6;
P_0c0856d6: /* original e061, guest PC 0x0c0856d6 */
if(!s->budget--) { s->failed_pc=0x0c0856d6u; return 0; }
r[0]=0x00000061u;
goto P_0c0856d8;
P_0c0856d8: /* original f488, guest PC 0x0c0856d8 */
if(!s->budget--) { s->failed_pc=0x0c0856d8u; return 0; }
vf3_matrix_load(s,ram,4,r[8]);
goto P_0c0856da;
P_0c0856da: /* original 054c, guest PC 0x0c0856da */
if(!s->budget--) { s->failed_pc=0x0c0856dau; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0856dc;
P_0c0856dc: /* original dd3c, guest PC 0x0c0856dc */
if(!s->budget--) { s->failed_pc=0x0c0856dcu; return 0; }
r[13]=read(ram,0x0c0857d0u,4);
goto P_0c0856de;
P_0c0856de: /* original 605c, guest PC 0x0c0856de */
if(!s->budget--) { s->failed_pc=0x0c0856deu; return 0; }
r[0]=r[5]&255u;
goto P_0c0856e0;
P_0c0856e0: /* original 8809, guest PC 0x0c0856e0 */
if(!s->budget--) { s->failed_pc=0x0c0856e0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0856e2;
P_0c0856e2: /* original 8d1c, guest PC 0x0c0856e2 */
if(!s->budget--) { s->failed_pc=0x0c0856e2u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c08571e; }
goto P_0c0856e6;
P_0c0856e4: /* original 6503, guest PC 0x0c0856e4 */
if(!s->budget--) { s->failed_pc=0x0c0856e4u; return 0; }
r[5]=r[0];
goto P_0c0856e6;
P_0c0856e6: /* original 6053, guest PC 0x0c0856e6 */
if(!s->budget--) { s->failed_pc=0x0c0856e6u; return 0; }
r[0]=r[5];
goto P_0c0856e8;
P_0c0856e8: /* original 8804, guest PC 0x0c0856e8 */
if(!s->budget--) { s->failed_pc=0x0c0856e8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0856ea;
P_0c0856ea: /* original 8918, guest PC 0x0c0856ea */
if(!s->budget--) { s->failed_pc=0x0c0856eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08571e; }
goto P_0c0856ec;
P_0c0856ec: /* original 6053, guest PC 0x0c0856ec */
if(!s->budget--) { s->failed_pc=0x0c0856ecu; return 0; }
r[0]=r[5];
goto P_0c0856ee;
P_0c0856ee: /* original 880b, guest PC 0x0c0856ee */
if(!s->budget--) { s->failed_pc=0x0c0856eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0856f0;
P_0c0856f0: /* original 8915, guest PC 0x0c0856f0 */
if(!s->budget--) { s->failed_pc=0x0c0856f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08571e; }
goto P_0c0856f2;
P_0c0856f2: /* original 905c, guest PC 0x0c0856f2 */
if(!s->budget--) { s->failed_pc=0x0c0856f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857aeu,2);
goto P_0c0856f4;
P_0c0856f4: /* original 66a3, guest PC 0x0c0856f4 */
if(!s->budget--) { s->failed_pc=0x0c0856f4u; return 0; }
r[6]=r[10];
goto P_0c0856f6;
P_0c0856f6: /* original 65c3, guest PC 0x0c0856f6 */
if(!s->budget--) { s->failed_pc=0x0c0856f6u; return 0; }
r[5]=r[12];
goto P_0c0856f8;
P_0c0856f8: /* original f346, guest PC 0x0c0856f8 */
if(!s->budget--) { s->failed_pc=0x0c0856f8u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0856fa;
P_0c0856fa: /* original e004, guest PC 0x0c0856fa */
if(!s->budget--) { s->failed_pc=0x0c0856fau; return 0; }
r[0]=0x00000004u;
goto P_0c0856fc;
P_0c0856fc: /* original ff37, guest PC 0x0c0856fc */
if(!s->budget--) { s->failed_pc=0x0c0856fcu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0856fe;
P_0c0856fe: /* original 9057, guest PC 0x0c0856fe */
if(!s->budget--) { s->failed_pc=0x0c0856feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857b0u,2);
goto P_0c085700;
P_0c085700: /* original f346, guest PC 0x0c085700 */
if(!s->budget--) { s->failed_pc=0x0c085700u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c085702;
P_0c085702: /* original f34d, guest PC 0x0c085702 */
if(!s->budget--) { s->failed_pc=0x0c085702u; return 0; }
fr[3]^=0x80000000u;
goto P_0c085704;
P_0c085704: /* original ff3a, guest PC 0x0c085704 */
if(!s->budget--) { s->failed_pc=0x0c085704u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c085706;
P_0c085706: /* original 2fe6, guest PC 0x0c085706 */
if(!s->budget--) { s->failed_pc=0x0c085706u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085708;
P_0c085708: /* original 2fd6, guest PC 0x0c085708 */
if(!s->budget--) { s->failed_pc=0x0c085708u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08570a;
P_0c08570a: /* original 63f3, guest PC 0x0c08570a */
if(!s->budget--) { s->failed_pc=0x0c08570au; return 0; }
r[3]=r[15];
goto P_0c08570c;
P_0c08570c: /* original 7308, guest PC 0x0c08570c */
if(!s->budget--) { s->failed_pc=0x0c08570cu; return 0; }
r[3]+=0x00000008u;
goto P_0c08570e;
P_0c08570e: /* original 2f36, guest PC 0x0c08570e */
if(!s->budget--) { s->failed_pc=0x0c08570eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085710;
P_0c085710: /* original 67f3, guest PC 0x0c085710 */
if(!s->budget--) { s->failed_pc=0x0c085710u; return 0; }
r[7]=r[15];
goto P_0c085712;
P_0c085712: /* original f6fc, guest PC 0x0c085712 */
if(!s->budget--) { s->failed_pc=0x0c085712u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c085714;
P_0c085714: /* original 7710, guest PC 0x0c085714 */
if(!s->budget--) { s->failed_pc=0x0c085714u; return 0; }
r[7]+=0x00000010u;
goto P_0c085716;
P_0c085716: /* original b08b, guest PC 0x0c085716 */
if(!s->budget--) { s->failed_pc=0x0c085716u; return 0; }
target=0x0c085830u; r[16]=0x0c08571au;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08571au) { target=s->pc; goto dispatch; }
goto P_0c08571a;
P_0c085718: /* original 64b3, guest PC 0x0c085718 */
if(!s->budget--) { s->failed_pc=0x0c085718u; return 0; }
r[4]=r[11];
goto P_0c08571a;
P_0c08571a: /* original 7d10, guest PC 0x0c08571a */
if(!s->budget--) { s->failed_pc=0x0c08571au; return 0; }
r[13]+=0x00000010u;
goto P_0c08571c;
P_0c08571c: /* original 7f0c, guest PC 0x0c08571c */
if(!s->budget--) { s->failed_pc=0x0c08571cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c08571e;
P_0c08571e: /* original d32e, guest PC 0x0c08571e */
if(!s->budget--) { s->failed_pc=0x0c08571eu; return 0; }
r[3]=read(ram,0x0c0857d8u,4);
goto P_0c085720;
P_0c085720: /* original 6483, guest PC 0x0c085720 */
if(!s->budget--) { s->failed_pc=0x0c085720u; return 0; }
r[4]=r[8];
goto P_0c085722;
P_0c085722: /* original 7408, guest PC 0x0c085722 */
if(!s->budget--) { s->failed_pc=0x0c085722u; return 0; }
r[4]+=0x00000008u;
goto P_0c085724;
P_0c085724: /* original e004, guest PC 0x0c085724 */
if(!s->budget--) { s->failed_pc=0x0c085724u; return 0; }
r[0]=0x00000004u;
goto P_0c085726;
P_0c085726: /* original 6932, guest PC 0x0c085726 */
if(!s->budget--) { s->failed_pc=0x0c085726u; return 0; }
tmp=read(ram,r[3],4);
r[9]=tmp;
goto P_0c085728;
P_0c085728: /* original f546, guest PC 0x0c085728 */
if(!s->budget--) { s->failed_pc=0x0c085728u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c08572a;
P_0c08572a: /* original e061, guest PC 0x0c08572a */
if(!s->budget--) { s->failed_pc=0x0c08572au; return 0; }
r[0]=0x00000061u;
goto P_0c08572c;
P_0c08572c: /* original f448, guest PC 0x0c08572c */
if(!s->budget--) { s->failed_pc=0x0c08572cu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c08572e;
P_0c08572e: /* original 049c, guest PC 0x0c08572e */
if(!s->budget--) { s->failed_pc=0x0c08572eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+r[0],1);
goto P_0c085730;
P_0c085730: /* original 604c, guest PC 0x0c085730 */
if(!s->budget--) { s->failed_pc=0x0c085730u; return 0; }
r[0]=r[4]&255u;
goto P_0c085732;
P_0c085732: /* original 8809, guest PC 0x0c085732 */
if(!s->budget--) { s->failed_pc=0x0c085732u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c085734;
P_0c085734: /* original 8d1c, guest PC 0x0c085734 */
if(!s->budget--) { s->failed_pc=0x0c085734u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c085770; }
goto P_0c085738;
P_0c085736: /* original 6403, guest PC 0x0c085736 */
if(!s->budget--) { s->failed_pc=0x0c085736u; return 0; }
r[4]=r[0];
goto P_0c085738;
P_0c085738: /* original 6043, guest PC 0x0c085738 */
if(!s->budget--) { s->failed_pc=0x0c085738u; return 0; }
r[0]=r[4];
goto P_0c08573a;
P_0c08573a: /* original 8804, guest PC 0x0c08573a */
if(!s->budget--) { s->failed_pc=0x0c08573au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c08573c;
P_0c08573c: /* original 8918, guest PC 0x0c08573c */
if(!s->budget--) { s->failed_pc=0x0c08573cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c085770; }
goto P_0c08573e;
P_0c08573e: /* original 6043, guest PC 0x0c08573e */
if(!s->budget--) { s->failed_pc=0x0c08573eu; return 0; }
r[0]=r[4];
goto P_0c085740;
P_0c085740: /* original 880b, guest PC 0x0c085740 */
if(!s->budget--) { s->failed_pc=0x0c085740u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c085742;
P_0c085742: /* original 8915, guest PC 0x0c085742 */
if(!s->budget--) { s->failed_pc=0x0c085742u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c085770; }
goto P_0c085744;
P_0c085744: /* original 9033, guest PC 0x0c085744 */
if(!s->budget--) { s->failed_pc=0x0c085744u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857aeu,2);
goto P_0c085746;
P_0c085746: /* original 66a3, guest PC 0x0c085746 */
if(!s->budget--) { s->failed_pc=0x0c085746u; return 0; }
r[6]=r[10];
goto P_0c085748;
P_0c085748: /* original 65c3, guest PC 0x0c085748 */
if(!s->budget--) { s->failed_pc=0x0c085748u; return 0; }
r[5]=r[12];
goto P_0c08574a;
P_0c08574a: /* original f396, guest PC 0x0c08574a */
if(!s->budget--) { s->failed_pc=0x0c08574au; return 0; }
vf3_matrix_load(s,ram,3,r[9]+r[0]);
goto P_0c08574c;
P_0c08574c: /* original e004, guest PC 0x0c08574c */
if(!s->budget--) { s->failed_pc=0x0c08574cu; return 0; }
r[0]=0x00000004u;
goto P_0c08574e;
P_0c08574e: /* original ff37, guest PC 0x0c08574e */
if(!s->budget--) { s->failed_pc=0x0c08574eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c085750;
P_0c085750: /* original 902e, guest PC 0x0c085750 */
if(!s->budget--) { s->failed_pc=0x0c085750u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857b0u,2);
goto P_0c085752;
P_0c085752: /* original f396, guest PC 0x0c085752 */
if(!s->budget--) { s->failed_pc=0x0c085752u; return 0; }
vf3_matrix_load(s,ram,3,r[9]+r[0]);
goto P_0c085754;
P_0c085754: /* original f34d, guest PC 0x0c085754 */
if(!s->budget--) { s->failed_pc=0x0c085754u; return 0; }
fr[3]^=0x80000000u;
goto P_0c085756;
P_0c085756: /* original ff3a, guest PC 0x0c085756 */
if(!s->budget--) { s->failed_pc=0x0c085756u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c085758;
P_0c085758: /* original 2fe6, guest PC 0x0c085758 */
if(!s->budget--) { s->failed_pc=0x0c085758u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08575a;
P_0c08575a: /* original 2fd6, guest PC 0x0c08575a */
if(!s->budget--) { s->failed_pc=0x0c08575au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08575c;
P_0c08575c: /* original 63f3, guest PC 0x0c08575c */
if(!s->budget--) { s->failed_pc=0x0c08575cu; return 0; }
r[3]=r[15];
goto P_0c08575e;
P_0c08575e: /* original 7308, guest PC 0x0c08575e */
if(!s->budget--) { s->failed_pc=0x0c08575eu; return 0; }
r[3]+=0x00000008u;
goto P_0c085760;
P_0c085760: /* original 2f36, guest PC 0x0c085760 */
if(!s->budget--) { s->failed_pc=0x0c085760u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085762;
P_0c085762: /* original 67f3, guest PC 0x0c085762 */
if(!s->budget--) { s->failed_pc=0x0c085762u; return 0; }
r[7]=r[15];
goto P_0c085764;
P_0c085764: /* original f6fc, guest PC 0x0c085764 */
if(!s->budget--) { s->failed_pc=0x0c085764u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c085766;
P_0c085766: /* original 7710, guest PC 0x0c085766 */
if(!s->budget--) { s->failed_pc=0x0c085766u; return 0; }
r[7]+=0x00000010u;
goto P_0c085768;
P_0c085768: /* original b062, guest PC 0x0c085768 */
if(!s->budget--) { s->failed_pc=0x0c085768u; return 0; }
target=0x0c085830u; r[16]=0x0c08576cu;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08576cu) { target=s->pc; goto dispatch; }
goto P_0c08576c;
P_0c08576a: /* original 64b3, guest PC 0x0c08576a */
if(!s->budget--) { s->failed_pc=0x0c08576au; return 0; }
r[4]=r[11];
goto P_0c08576c;
P_0c08576c: /* original 7d10, guest PC 0x0c08576c */
if(!s->budget--) { s->failed_pc=0x0c08576cu; return 0; }
r[13]+=0x00000010u;
goto P_0c08576e;
P_0c08576e: /* original 7f0c, guest PC 0x0c08576e */
if(!s->budget--) { s->failed_pc=0x0c08576eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c085770;
P_0c085770: /* original 901d, guest PC 0x0c085770 */
if(!s->budget--) { s->failed_pc=0x0c085770u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857aeu,2);
goto P_0c085772;
P_0c085772: /* original 66ab, guest PC 0x0c085772 */
if(!s->budget--) { s->failed_pc=0x0c085772u; return 0; }
r[6]=0u-r[10];
goto P_0c085774;
P_0c085774: /* original 64bb, guest PC 0x0c085774 */
if(!s->budget--) { s->failed_pc=0x0c085774u; return 0; }
r[4]=0u-r[11];
goto P_0c085776;
P_0c085776: /* original f396, guest PC 0x0c085776 */
if(!s->budget--) { s->failed_pc=0x0c085776u; return 0; }
vf3_matrix_load(s,ram,3,r[9]+r[0]);
goto P_0c085778;
P_0c085778: /* original e004, guest PC 0x0c085778 */
if(!s->budget--) { s->failed_pc=0x0c085778u; return 0; }
r[0]=0x00000004u;
goto P_0c08577a;
P_0c08577a: /* original 65cb, guest PC 0x0c08577a */
if(!s->budget--) { s->failed_pc=0x0c08577au; return 0; }
r[5]=0u-r[12];
goto P_0c08577c;
P_0c08577c: /* original ff37, guest PC 0x0c08577c */
if(!s->budget--) { s->failed_pc=0x0c08577cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08577e;
P_0c08577e: /* original 9017, guest PC 0x0c08577e */
if(!s->budget--) { s->failed_pc=0x0c08577eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857b0u,2);
goto P_0c085780;
P_0c085780: /* original f396, guest PC 0x0c085780 */
if(!s->budget--) { s->failed_pc=0x0c085780u; return 0; }
vf3_matrix_load(s,ram,3,r[9]+r[0]);
goto P_0c085782;
P_0c085782: /* original f34d, guest PC 0x0c085782 */
if(!s->budget--) { s->failed_pc=0x0c085782u; return 0; }
fr[3]^=0x80000000u;
goto P_0c085784;
P_0c085784: /* original ff3a, guest PC 0x0c085784 */
if(!s->budget--) { s->failed_pc=0x0c085784u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c085786;
P_0c085786: /* original d313, guest PC 0x0c085786 */
if(!s->budget--) { s->failed_pc=0x0c085786u; return 0; }
r[3]=read(ram,0x0c0857d4u,4);
goto P_0c085788;
P_0c085788: /* original 9011, guest PC 0x0c085788 */
if(!s->budget--) { s->failed_pc=0x0c085788u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857aeu,2);
goto P_0c08578a;
P_0c08578a: /* original 6732, guest PC 0x0c08578a */
if(!s->budget--) { s->failed_pc=0x0c08578au; return 0; }
tmp=read(ram,r[3],4);
r[7]=tmp;
goto P_0c08578c;
P_0c08578c: /* original f576, guest PC 0x0c08578c */
if(!s->budget--) { s->failed_pc=0x0c08578cu; return 0; }
vf3_matrix_load(s,ram,5,r[7]+r[0]);
goto P_0c08578e;
P_0c08578e: /* original 7008, guest PC 0x0c08578e */
if(!s->budget--) { s->failed_pc=0x0c08578eu; return 0; }
r[0]+=0x00000008u;
goto P_0c085790;
P_0c085790: /* original f476, guest PC 0x0c085790 */
if(!s->budget--) { s->failed_pc=0x0c085790u; return 0; }
vf3_matrix_load(s,ram,4,r[7]+r[0]);
goto P_0c085792;
P_0c085792: /* original e004, guest PC 0x0c085792 */
if(!s->budget--) { s->failed_pc=0x0c085792u; return 0; }
r[0]=0x00000004u;
goto P_0c085794;
P_0c085794: /* original f3f6, guest PC 0x0c085794 */
if(!s->budget--) { s->failed_pc=0x0c085794u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c085796;
P_0c085796: /* original e004, guest PC 0x0c085796 */
if(!s->budget--) { s->failed_pc=0x0c085796u; return 0; }
r[0]=0x00000004u;
goto P_0c085798;
P_0c085798: /* original f44d, guest PC 0x0c085798 */
if(!s->budget--) { s->failed_pc=0x0c085798u; return 0; }
fr[4]^=0x80000000u;
goto P_0c08579a;
P_0c08579a: /* original f350, guest PC 0x0c08579a */
if(!s->budget--) { s->failed_pc=0x0c08579au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'+');
goto P_0c08579c;
P_0c08579c: /* original ff37, guest PC 0x0c08579c */
if(!s->budget--) { s->failed_pc=0x0c08579cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08579e;
P_0c08579e: /* original f2f8, guest PC 0x0c08579e */
if(!s->budget--) { s->failed_pc=0x0c08579eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0857a0;
P_0c0857a0: /* original a01c, guest PC 0x0c0857a0 */
if(!s->budget--) { s->failed_pc=0x0c0857a0u; return 0; }
goto P_0c0857dc;
P_0c0857a2: /* original 0009, guest PC 0x0c0857a2 */
if(!s->budget--) { s->failed_pc=0x0c0857a2u; return 0; }
return vf3_matrix_family(0x0c0857a4u,s,ram);
P_0c0857dc: /* original f240, guest PC 0x0c0857dc */
if(!s->budget--) { s->failed_pc=0x0c0857dcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'+');
goto P_0c0857de;
P_0c0857de: /* original c73f, guest PC 0x0c0857de */
if(!s->budget--) { s->failed_pc=0x0c0857deu; return 0; }
r[0]=0x0c0858dcu;
goto P_0c0857e0;
P_0c0857e0: /* original 6783, guest PC 0x0c0857e0 */
if(!s->budget--) { s->failed_pc=0x0c0857e0u; return 0; }
r[7]=r[8];
goto P_0c0857e2;
P_0c0857e2: /* original 7710, guest PC 0x0c0857e2 */
if(!s->budget--) { s->failed_pc=0x0c0857e2u; return 0; }
r[7]+=0x00000010u;
goto P_0c0857e4;
P_0c0857e4: /* original ff2a, guest PC 0x0c0857e4 */
if(!s->budget--) { s->failed_pc=0x0c0857e4u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0857e6;
P_0c0857e6: /* original f408, guest PC 0x0c0857e6 */
if(!s->budget--) { s->failed_pc=0x0c0857e6u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0857e8;
P_0c0857e8: /* original e004, guest PC 0x0c0857e8 */
if(!s->budget--) { s->failed_pc=0x0c0857e8u; return 0; }
r[0]=0x00000004u;
goto P_0c0857ea;
P_0c0857ea: /* original f242, guest PC 0x0c0857ea */
if(!s->budget--) { s->failed_pc=0x0c0857eau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c0857ec;
P_0c0857ec: /* original f342, guest PC 0x0c0857ec */
if(!s->budget--) { s->failed_pc=0x0c0857ecu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0857ee;
P_0c0857ee: /* original ff37, guest PC 0x0c0857ee */
if(!s->budget--) { s->failed_pc=0x0c0857eeu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0857f0;
P_0c0857f0: /* original e004, guest PC 0x0c0857f0 */
if(!s->budget--) { s->failed_pc=0x0c0857f0u; return 0; }
r[0]=0x00000004u;
goto P_0c0857f2;
P_0c0857f2: /* original ff2a, guest PC 0x0c0857f2 */
if(!s->budget--) { s->failed_pc=0x0c0857f2u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0857f4;
P_0c0857f4: /* original f576, guest PC 0x0c0857f4 */
if(!s->budget--) { s->failed_pc=0x0c0857f4u; return 0; }
vf3_matrix_load(s,ram,5,r[7]+r[0]);
goto P_0c0857f6;
P_0c0857f6: /* original f478, guest PC 0x0c0857f6 */
if(!s->budget--) { s->failed_pc=0x0c0857f6u; return 0; }
vf3_matrix_load(s,ram,4,r[7]);
goto P_0c0857f8;
P_0c0857f8: /* original 2fe6, guest PC 0x0c0857f8 */
if(!s->budget--) { s->failed_pc=0x0c0857f8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0857fa;
P_0c0857fa: /* original 2fd6, guest PC 0x0c0857fa */
if(!s->budget--) { s->failed_pc=0x0c0857fau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0857fc;
P_0c0857fc: /* original 62f3, guest PC 0x0c0857fc */
if(!s->budget--) { s->failed_pc=0x0c0857fcu; return 0; }
r[2]=r[15];
goto P_0c0857fe;
P_0c0857fe: /* original 7208, guest PC 0x0c0857fe */
if(!s->budget--) { s->failed_pc=0x0c0857feu; return 0; }
r[2]+=0x00000008u;
goto P_0c085800;
P_0c085800: /* original 2f26, guest PC 0x0c085800 */
if(!s->budget--) { s->failed_pc=0x0c085800u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085802;
P_0c085802: /* original 67f3, guest PC 0x0c085802 */
if(!s->budget--) { s->failed_pc=0x0c085802u; return 0; }
r[7]=r[15];
goto P_0c085804;
P_0c085804: /* original f6fc, guest PC 0x0c085804 */
if(!s->budget--) { s->failed_pc=0x0c085804u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c085806;
P_0c085806: /* original b013, guest PC 0x0c085806 */
if(!s->budget--) { s->failed_pc=0x0c085806u; return 0; }
target=0x0c085830u; r[16]=0x0c08580au;
r[7]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08580au) { target=s->pc; goto dispatch; }
goto P_0c08580a;
P_0c085808: /* original 7710, guest PC 0x0c085808 */
if(!s->budget--) { s->failed_pc=0x0c085808u; return 0; }
r[7]+=0x00000010u;
goto P_0c08580a;
P_0c08580a: /* original e3ff, guest PC 0x0c08580a */
if(!s->budget--) { s->failed_pc=0x0c08580au; return 0; }
r[3]=0xffffffffu;
goto P_0c08580c;
P_0c08580c: /* original 7d10, guest PC 0x0c08580c */
if(!s->budget--) { s->failed_pc=0x0c08580cu; return 0; }
r[13]+=0x00000010u;
goto P_0c08580e;
P_0c08580e: /* original 2d32, guest PC 0x0c08580e */
if(!s->budget--) { s->failed_pc=0x0c08580eu; return 0; }
write(ram,r[13],r[3],4);
goto P_0c085810;
P_0c085810: /* original 7f0c, guest PC 0x0c085810 */
if(!s->budget--) { s->failed_pc=0x0c085810u; return 0; }
r[15]+=0x0000000cu;
goto P_0c085812;
P_0c085812: /* original b069, guest PC 0x0c085812 */
if(!s->budget--) { s->failed_pc=0x0c085812u; return 0; }
target=0x0c0858e8u; r[16]=0x0c085816u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085816u) { target=s->pc; goto dispatch; }
goto P_0c085816;
P_0c085814: /* original 64e3, guest PC 0x0c085814 */
if(!s->budget--) { s->failed_pc=0x0c085814u; return 0; }
r[4]=r[14];
goto P_0c085816;
P_0c085816: /* original b0f9, guest PC 0x0c085816 */
if(!s->budget--) { s->failed_pc=0x0c085816u; return 0; }
target=0x0c085a0cu; r[16]=0x0c08581au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08581au) { target=s->pc; goto dispatch; }
goto P_0c08581a;
P_0c085818: /* original 0009, guest PC 0x0c085818 */
if(!s->budget--) { s->failed_pc=0x0c085818u; return 0; }
goto P_0c08581a;
P_0c08581a: /* original 7f0c, guest PC 0x0c08581a */
if(!s->budget--) { s->failed_pc=0x0c08581au; return 0; }
r[15]+=0x0000000cu;
goto P_0c08581c;
P_0c08581c: /* original 4f26, guest PC 0x0c08581c */
if(!s->budget--) { s->failed_pc=0x0c08581cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08581e;
P_0c08581e: /* original fff9, guest PC 0x0c08581e */
if(!s->budget--) { s->failed_pc=0x0c08581eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085820;
P_0c085820: /* original 68f6, guest PC 0x0c085820 */
if(!s->budget--) { s->failed_pc=0x0c085820u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c085822;
P_0c085822: /* original 69f6, guest PC 0x0c085822 */
if(!s->budget--) { s->failed_pc=0x0c085822u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c085824;
P_0c085824: /* original 6af6, guest PC 0x0c085824 */
if(!s->budget--) { s->failed_pc=0x0c085824u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c085826;
P_0c085826: /* original 6bf6, guest PC 0x0c085826 */
if(!s->budget--) { s->failed_pc=0x0c085826u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c085828;
P_0c085828: /* original 6cf6, guest PC 0x0c085828 */
if(!s->budget--) { s->failed_pc=0x0c085828u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08582a;
P_0c08582a: /* original 6df6, guest PC 0x0c08582a */
if(!s->budget--) { s->failed_pc=0x0c08582au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08582c;
P_0c08582c: /* original 000b, guest PC 0x0c08582c */
if(!s->budget--) { s->failed_pc=0x0c08582cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08582e: /* original 6ef6, guest PC 0x0c08582e */
if(!s->budget--) { s->failed_pc=0x0c08582eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c085830;
P_0c085830: /* original 2fe6, guest PC 0x0c085830 */
if(!s->budget--) { s->failed_pc=0x0c085830u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085832;
P_0c085832: /* original 6043, guest PC 0x0c085832 */
if(!s->budget--) { s->failed_pc=0x0c085832u; return 0; }
r[0]=r[4];
goto P_0c085834;
P_0c085834: /* original 2fd6, guest PC 0x0c085834 */
if(!s->budget--) { s->failed_pc=0x0c085834u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085836;
P_0c085836: /* original 2fc6, guest PC 0x0c085836 */
if(!s->budget--) { s->failed_pc=0x0c085836u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085838;
P_0c085838: /* original 6c73, guest PC 0x0c085838 */
if(!s->budget--) { s->failed_pc=0x0c085838u; return 0; }
r[12]=r[7];
goto P_0c08583a;
P_0c08583a: /* original fffb, guest PC 0x0c08583a */
if(!s->budget--) { s->failed_pc=0x0c08583au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
return vf3_matrix_family(0x0c08583cu,s,ram);
P_0c0858e8: /* original 2fe6, guest PC 0x0c0858e8 */
if(!s->budget--) { s->failed_pc=0x0c0858e8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0858ea;
P_0c0858ea: /* original 6e43, guest PC 0x0c0858ea */
if(!s->budget--) { s->failed_pc=0x0c0858eau; return 0; }
r[14]=r[4];
goto P_0c0858ec;
P_0c0858ec: /* original 2fd6, guest PC 0x0c0858ec */
if(!s->budget--) { s->failed_pc=0x0c0858ecu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0858ee;
P_0c0858ee: /* original fffb, guest PC 0x0c0858ee */
if(!s->budget--) { s->failed_pc=0x0c0858eeu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0858f0;
P_0c0858f0: /* original 9070, guest PC 0x0c0858f0 */
if(!s->budget--) { s->failed_pc=0x0c0858f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859d4u,2);
goto P_0c0858f2;
P_0c0858f2: /* original 4f22, guest PC 0x0c0858f2 */
if(!s->budget--) { s->failed_pc=0x0c0858f2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0858f4;
P_0c0858f4: /* original 00ed, guest PC 0x0c0858f4 */
if(!s->budget--) { s->failed_pc=0x0c0858f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0858f6;
P_0c0858f6: /* original 7fec, guest PC 0x0c0858f6 */
if(!s->budget--) { s->failed_pc=0x0c0858f6u; return 0; }
r[15]+=0xffffffecu;
goto P_0c0858f8;
P_0c0858f8: /* original 81f2, guest PC 0x0c0858f8 */
if(!s->budget--) { s->failed_pc=0x0c0858f8u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c0858fa;
P_0c0858fa: /* original c73b, guest PC 0x0c0858fa */
if(!s->budget--) { s->failed_pc=0x0c0858fau; return 0; }
r[0]=0x0c0859e8u;
goto P_0c0858fc;
P_0c0858fc: /* original f308, guest PC 0x0c0858fc */
if(!s->budget--) { s->failed_pc=0x0c0858fcu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0858fe;
P_0c0858fe: /* original e008, guest PC 0x0c0858fe */
if(!s->budget--) { s->failed_pc=0x0c0858feu; return 0; }
r[0]=0x00000008u;
goto P_0c085900;
P_0c085900: /* original ff37, guest PC 0x0c085900 */
if(!s->budget--) { s->failed_pc=0x0c085900u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c085902;
P_0c085902: /* original 85f2, guest PC 0x0c085902 */
if(!s->budget--) { s->failed_pc=0x0c085902u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c085904;
P_0c085904: /* original dd39, guest PC 0x0c085904 */
if(!s->budget--) { s->failed_pc=0x0c085904u; return 0; }
r[13]=read(ram,0x0c0859ecu,4);
goto P_0c085906;
P_0c085906: /* original 4d0b, guest PC 0x0c085906 */
if(!s->budget--) { s->failed_pc=0x0c085906u; return 0; }
target=r[13];
r[16]=0x0c08590au;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08590au) { target=s->pc; goto dispatch; }
goto P_0c08590a;
P_0c085908: /* original 6403, guest PC 0x0c085908 */
if(!s->budget--) { s->failed_pc=0x0c085908u; return 0; }
r[4]=r[0];
goto P_0c08590a;
P_0c08590a: /* original e008, guest PC 0x0c08590a */
if(!s->budget--) { s->failed_pc=0x0c08590au; return 0; }
r[0]=0x00000008u;
goto P_0c08590c;
P_0c08590c: /* original f4f6, guest PC 0x0c08590c */
if(!s->budget--) { s->failed_pc=0x0c08590cu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08590e;
P_0c08590e: /* original 9062, guest PC 0x0c08590e */
if(!s->budget--) { s->failed_pc=0x0c08590eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859d6u,2);
goto P_0c085910;
P_0c085910: /* original f402, guest PC 0x0c085910 */
if(!s->budget--) { s->failed_pc=0x0c085910u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[0],r[18],'*');
goto P_0c085912;
P_0c085912: /* original f43d, guest PC 0x0c085912 */
if(!s->budget--) { s->failed_pc=0x0c085912u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c085914;
P_0c085914: /* original 035a, guest PC 0x0c085914 */
if(!s->budget--) { s->failed_pc=0x0c085914u; return 0; }
r[3]=r[53];
goto P_0c085916;
P_0c085916: /* original 0e35, guest PC 0x0c085916 */
if(!s->budget--) { s->failed_pc=0x0c085916u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c085918;
P_0c085918: /* original 70f8, guest PC 0x0c085918 */
if(!s->budget--) { s->failed_pc=0x0c085918u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c08591a;
P_0c08591a: /* original 00ed, guest PC 0x0c08591a */
if(!s->budget--) { s->failed_pc=0x0c08591au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08591c;
P_0c08591c: /* original 81f6, guest PC 0x0c08591c */
if(!s->budget--) { s->failed_pc=0x0c08591cu; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c08591e;
P_0c08591e: /* original 905b, guest PC 0x0c08591e */
if(!s->budget--) { s->failed_pc=0x0c08591eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859d8u,2);
goto P_0c085920;
P_0c085920: /* original 00ed, guest PC 0x0c085920 */
if(!s->budget--) { s->failed_pc=0x0c085920u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085922;
P_0c085922: /* original 81f2, guest PC 0x0c085922 */
if(!s->budget--) { s->failed_pc=0x0c085922u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c085924;
P_0c085924: /* original c732, guest PC 0x0c085924 */
if(!s->budget--) { s->failed_pc=0x0c085924u; return 0; }
r[0]=0x0c0859f0u;
goto P_0c085926;
P_0c085926: /* original ff08, guest PC 0x0c085926 */
if(!s->budget--) { s->failed_pc=0x0c085926u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c085928;
P_0c085928: /* original 85f6, guest PC 0x0c085928 */
if(!s->budget--) { s->failed_pc=0x0c085928u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c08592a;
P_0c08592a: /* original 4d0b, guest PC 0x0c08592a */
if(!s->budget--) { s->failed_pc=0x0c08592au; return 0; }
target=r[13];
r[16]=0x0c08592eu;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08592eu) { target=s->pc; goto dispatch; }
goto P_0c08592e;
P_0c08592c: /* original 6403, guest PC 0x0c08592c */
if(!s->budget--) { s->failed_pc=0x0c08592cu; return 0; }
r[4]=r[0];
goto P_0c08592e;
P_0c08592e: /* original f3fc, guest PC 0x0c08592e */
if(!s->budget--) { s->failed_pc=0x0c08592eu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c085930;
P_0c085930: /* original f302, guest PC 0x0c085930 */
if(!s->budget--) { s->failed_pc=0x0c085930u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'*');
goto P_0c085932;
P_0c085932: /* original e010, guest PC 0x0c085932 */
if(!s->budget--) { s->failed_pc=0x0c085932u; return 0; }
r[0]=0x00000010u;
goto P_0c085934;
P_0c085934: /* original ff37, guest PC 0x0c085934 */
if(!s->budget--) { s->failed_pc=0x0c085934u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c085936;
P_0c085936: /* original d32f, guest PC 0x0c085936 */
if(!s->budget--) { s->failed_pc=0x0c085936u; return 0; }
r[3]=read(ram,0x0c0859f4u,4);
goto P_0c085938;
P_0c085938: /* original 85f2, guest PC 0x0c085938 */
if(!s->budget--) { s->failed_pc=0x0c085938u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c08593a;
P_0c08593a: /* original 430b, guest PC 0x0c08593a */
if(!s->budget--) { s->failed_pc=0x0c08593au; return 0; }
target=r[3];
r[16]=0x0c08593eu;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08593eu) { target=s->pc; goto dispatch; }
goto P_0c08593e;
P_0c08593c: /* original 6403, guest PC 0x0c08593c */
if(!s->budget--) { s->failed_pc=0x0c08593cu; return 0; }
r[4]=r[0];
goto P_0c08593e;
P_0c08593e: /* original f4fc, guest PC 0x0c08593e */
if(!s->budget--) { s->failed_pc=0x0c08593eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c085940;
P_0c085940: /* original f402, guest PC 0x0c085940 */
if(!s->budget--) { s->failed_pc=0x0c085940u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[0],r[18],'*');
goto P_0c085942;
P_0c085942: /* original e010, guest PC 0x0c085942 */
if(!s->budget--) { s->failed_pc=0x0c085942u; return 0; }
r[0]=0x00000010u;
goto P_0c085944;
P_0c085944: /* original f34c, guest PC 0x0c085944 */
if(!s->budget--) { s->failed_pc=0x0c085944u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c085946;
P_0c085946: /* original f4f6, guest PC 0x0c085946 */
if(!s->budget--) { s->failed_pc=0x0c085946u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c085948;
P_0c085948: /* original f430, guest PC 0x0c085948 */
if(!s->budget--) { s->failed_pc=0x0c085948u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c08594a;
P_0c08594a: /* original f43d, guest PC 0x0c08594a */
if(!s->budget--) { s->failed_pc=0x0c08594au; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c08594c;
P_0c08594c: /* original 035a, guest PC 0x0c08594c */
if(!s->budget--) { s->failed_pc=0x0c08594cu; return 0; }
r[3]=r[53];
goto P_0c08594e;
P_0c08594e: /* original 633f, guest PC 0x0c08594e */
if(!s->budget--) { s->failed_pc=0x0c08594eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c085950;
P_0c085950: /* original 6233, guest PC 0x0c085950 */
if(!s->budget--) { s->failed_pc=0x0c085950u; return 0; }
r[2]=r[3];
goto P_0c085952;
P_0c085952: /* original 2f32, guest PC 0x0c085952 */
if(!s->budget--) { s->failed_pc=0x0c085952u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c085954;
P_0c085954: /* original 9041, guest PC 0x0c085954 */
if(!s->budget--) { s->failed_pc=0x0c085954u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859dau,2);
goto P_0c085956;
P_0c085956: /* original 0e25, guest PC 0x0c085956 */
if(!s->budget--) { s->failed_pc=0x0c085956u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c085958;
P_0c085958: /* original c727, guest PC 0x0c085958 */
if(!s->budget--) { s->failed_pc=0x0c085958u; return 0; }
r[0]=0x0c0859f8u;
goto P_0c08595a;
P_0c08595a: /* original f308, guest PC 0x0c08595a */
if(!s->budget--) { s->failed_pc=0x0c08595au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08595c;
P_0c08595c: /* original 903e, guest PC 0x0c08595c */
if(!s->budget--) { s->failed_pc=0x0c08595cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859dcu,2);
goto P_0c08595e;
P_0c08595e: /* original fe37, guest PC 0x0c08595e */
if(!s->budget--) { s->failed_pc=0x0c08595eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c085960;
P_0c085960: /* original 903d, guest PC 0x0c085960 */
if(!s->budget--) { s->failed_pc=0x0c085960u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859deu,2);
goto P_0c085962;
P_0c085962: /* original 03ed, guest PC 0x0c085962 */
if(!s->budget--) { s->failed_pc=0x0c085962u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085964;
P_0c085964: /* original 2f32, guest PC 0x0c085964 */
if(!s->budget--) { s->failed_pc=0x0c085964u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c085966;
P_0c085966: /* original d126, guest PC 0x0c085966 */
if(!s->budget--) { s->failed_pc=0x0c085966u; return 0; }
r[1]=read(ram,0x0c085a00u,4);
goto P_0c085968;
P_0c085968: /* original 903a, guest PC 0x0c085968 */
if(!s->budget--) { s->failed_pc=0x0c085968u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859e0u,2);
goto P_0c08596a;
P_0c08596a: /* original 6212, guest PC 0x0c08596a */
if(!s->budget--) { s->failed_pc=0x0c08596au; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c08596c;
P_0c08596c: /* original d323, guest PC 0x0c08596c */
if(!s->budget--) { s->failed_pc=0x0c08596cu; return 0; }
r[3]=read(ram,0x0c0859fcu,4);
goto P_0c08596e;
P_0c08596e: /* original 04ed, guest PC 0x0c08596e */
if(!s->budget--) { s->failed_pc=0x0c08596eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085970;
P_0c085970: /* original 2238, guest PC 0x0c085970 */
if(!s->budget--) { s->failed_pc=0x0c085970u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c085972;
P_0c085972: /* original 8b0f, guest PC 0x0c085972 */
if(!s->budget--) { s->failed_pc=0x0c085972u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085994; }
goto P_0c085974;
P_0c085974: /* original 9035, guest PC 0x0c085974 */
if(!s->budget--) { s->failed_pc=0x0c085974u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859e2u,2);
goto P_0c085976;
P_0c085976: /* original 05ed, guest PC 0x0c085976 */
if(!s->budget--) { s->failed_pc=0x0c085976u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085978;
P_0c085978: /* original 2558, guest PC 0x0c085978 */
if(!s->budget--) { s->failed_pc=0x0c085978u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c08597a;
P_0c08597a: /* original 8904, guest PC 0x0c08597a */
if(!s->budget--) { s->failed_pc=0x0c08597au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c085986; }
goto P_0c08597c;
P_0c08597c: /* original 65f3, guest PC 0x0c08597c */
if(!s->budget--) { s->failed_pc=0x0c08597cu; return 0; }
r[5]=r[15];
goto P_0c08597e;
P_0c08597e: /* original b103, guest PC 0x0c08597e */
if(!s->budget--) { s->failed_pc=0x0c08597eu; return 0; }
target=0x0c085b88u; r[16]=0x0c085982u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085982u) { target=s->pc; goto dispatch; }
goto P_0c085982;
P_0c085980: /* original 64e3, guest PC 0x0c085980 */
if(!s->budget--) { s->failed_pc=0x0c085980u; return 0; }
r[4]=r[14];
goto P_0c085982;
P_0c085982: /* original a007, guest PC 0x0c085982 */
if(!s->budget--) { s->failed_pc=0x0c085982u; return 0; }
goto P_0c085994;
P_0c085984: /* original 0009, guest PC 0x0c085984 */
if(!s->budget--) { s->failed_pc=0x0c085984u; return 0; }
goto P_0c085986;
P_0c085986: /* original 63f2, guest PC 0x0c085986 */
if(!s->budget--) { s->failed_pc=0x0c085986u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c085988;
P_0c085988: /* original 644f, guest PC 0x0c085988 */
if(!s->budget--) { s->failed_pc=0x0c085988u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c08598a;
P_0c08598a: /* original 334c, guest PC 0x0c08598a */
if(!s->budget--) { s->failed_pc=0x0c08598au; return 0; }
r[3]+=r[4];
goto P_0c08598c;
P_0c08598c: /* original 6233, guest PC 0x0c08598c */
if(!s->budget--) { s->failed_pc=0x0c08598cu; return 0; }
r[2]=r[3];
goto P_0c08598e;
P_0c08598e: /* original 2f32, guest PC 0x0c08598e */
if(!s->budget--) { s->failed_pc=0x0c08598eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c085990;
P_0c085990: /* original 9025, guest PC 0x0c085990 */
if(!s->budget--) { s->failed_pc=0x0c085990u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859deu,2);
goto P_0c085992;
P_0c085992: /* original 0e25, guest PC 0x0c085992 */
if(!s->budget--) { s->failed_pc=0x0c085992u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c085994;
P_0c085994: /* original 63f2, guest PC 0x0c085994 */
if(!s->budget--) { s->failed_pc=0x0c085994u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c085996;
P_0c085996: /* original 4311, guest PC 0x0c085996 */
if(!s->budget--) { s->failed_pc=0x0c085996u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c085998;
P_0c085998: /* original 8b02, guest PC 0x0c085998 */
if(!s->budget--) { s->failed_pc=0x0c085998u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0859a0; }
goto P_0c08599a;
P_0c08599a: /* original 65f3, guest PC 0x0c08599a */
if(!s->budget--) { s->failed_pc=0x0c08599au; return 0; }
r[5]=r[15];
goto P_0c08599c;
P_0c08599c: /* original b0f4, guest PC 0x0c08599c */
if(!s->budget--) { s->failed_pc=0x0c08599cu; return 0; }
target=0x0c085b88u; r[16]=0x0c0859a0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0859a0u) { target=s->pc; goto dispatch; }
goto P_0c0859a0;
P_0c08599e: /* original 64e3, guest PC 0x0c08599e */
if(!s->budget--) { s->failed_pc=0x0c08599eu; return 0; }
r[4]=r[14];
goto P_0c0859a0;
P_0c0859a0: /* original 64f2, guest PC 0x0c0859a0 */
if(!s->budget--) { s->failed_pc=0x0c0859a0u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0859a2;
P_0c0859a2: /* original 4d0b, guest PC 0x0c0859a2 */
if(!s->budget--) { s->failed_pc=0x0c0859a2u; return 0; }
target=r[13];
r[16]=0x0c0859a6u;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0859a6u) { target=s->pc; goto dispatch; }
goto P_0c0859a6;
P_0c0859a4: /* original 644f, guest PC 0x0c0859a4 */
if(!s->budget--) { s->failed_pc=0x0c0859a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0859a6;
P_0c0859a6: /* original c717, guest PC 0x0c0859a6 */
if(!s->budget--) { s->failed_pc=0x0c0859a6u; return 0; }
r[0]=0x0c085a04u;
goto P_0c0859a8;
P_0c0859a8: /* original f40c, guest PC 0x0c0859a8 */
if(!s->budget--) { s->failed_pc=0x0c0859a8u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0859aa;
P_0c0859aa: /* original f308, guest PC 0x0c0859aa */
if(!s->budget--) { s->failed_pc=0x0c0859aau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0859ac;
P_0c0859ac: /* original f28d, guest PC 0x0c0859ac */
if(!s->budget--) { s->failed_pc=0x0c0859acu; return 0; }
fr[2]=0;
goto P_0c0859ae;
P_0c0859ae: /* original f432, guest PC 0x0c0859ae */
if(!s->budget--) { s->failed_pc=0x0c0859aeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0859b0;
P_0c0859b0: /* original f245, guest PC 0x0c0859b0 */
if(!s->budget--) { s->failed_pc=0x0c0859b0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c0859b2;
P_0c0859b2: /* original 8b04, guest PC 0x0c0859b2 */
if(!s->budget--) { s->failed_pc=0x0c0859b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0859be; }
goto P_0c0859b4;
P_0c0859b4: /* original f14c, guest PC 0x0c0859b4 */
if(!s->budget--) { s->failed_pc=0x0c0859b4u; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c0859b6;
P_0c0859b6: /* original f29d, guest PC 0x0c0859b6 */
if(!s->budget--) { s->failed_pc=0x0c0859b6u; return 0; }
fr[2]=0x3f800000u;
goto P_0c0859b8;
P_0c0859b8: /* original f122, guest PC 0x0c0859b8 */
if(!s->budget--) { s->failed_pc=0x0c0859b8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0859ba;
P_0c0859ba: /* original f41c, guest PC 0x0c0859ba */
if(!s->budget--) { s->failed_pc=0x0c0859bau; return 0; }
vf3_matrix_move(s,4,1);
goto P_0c0859bc;
P_0c0859bc: /* original f44d, guest PC 0x0c0859bc */
if(!s->budget--) { s->failed_pc=0x0c0859bcu; return 0; }
fr[4]^=0x80000000u;
goto P_0c0859be;
P_0c0859be: /* original 7f14, guest PC 0x0c0859be */
if(!s->budget--) { s->failed_pc=0x0c0859beu; return 0; }
r[15]+=0x00000014u;
goto P_0c0859c0;
P_0c0859c0: /* original c711, guest PC 0x0c0859c0 */
if(!s->budget--) { s->failed_pc=0x0c0859c0u; return 0; }
r[0]=0x0c085a08u;
goto P_0c0859c2;
P_0c0859c2: /* original 4f26, guest PC 0x0c0859c2 */
if(!s->budget--) { s->failed_pc=0x0c0859c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0859c4;
P_0c0859c4: /* original f308, guest PC 0x0c0859c4 */
if(!s->budget--) { s->failed_pc=0x0c0859c4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0859c6;
P_0c0859c6: /* original 900d, guest PC 0x0c0859c6 */
if(!s->budget--) { s->failed_pc=0x0c0859c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0859e4u,2);
goto P_0c0859c8;
P_0c0859c8: /* original f430, guest PC 0x0c0859c8 */
if(!s->budget--) { s->failed_pc=0x0c0859c8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0859ca;
P_0c0859ca: /* original fe47, guest PC 0x0c0859ca */
if(!s->budget--) { s->failed_pc=0x0c0859cau; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0859cc;
P_0c0859cc: /* original fff9, guest PC 0x0c0859cc */
if(!s->budget--) { s->failed_pc=0x0c0859ccu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0859ce;
P_0c0859ce: /* original 6df6, guest PC 0x0c0859ce */
if(!s->budget--) { s->failed_pc=0x0c0859ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0859d0;
P_0c0859d0: /* original 000b, guest PC 0x0c0859d0 */
if(!s->budget--) { s->failed_pc=0x0c0859d0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0859d2: /* original 6ef6, guest PC 0x0c0859d2 */
if(!s->budget--) { s->failed_pc=0x0c0859d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0859d4u,s,ram);
P_0c085a0c: /* original 2fe6, guest PC 0x0c085a0c */
if(!s->budget--) { s->failed_pc=0x0c085a0cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085a0e;
P_0c085a0e: /* original 2fd6, guest PC 0x0c085a0e */
if(!s->budget--) { s->failed_pc=0x0c085a0eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085a10;
P_0c085a10: /* original 2fc6, guest PC 0x0c085a10 */
if(!s->budget--) { s->failed_pc=0x0c085a10u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085a12;
P_0c085a12: /* original 2fb6, guest PC 0x0c085a12 */
if(!s->budget--) { s->failed_pc=0x0c085a12u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085a14;
P_0c085a14: /* original 2fa6, guest PC 0x0c085a14 */
if(!s->budget--) { s->failed_pc=0x0c085a14u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085a16;
P_0c085a16: /* original 4f22, guest PC 0x0c085a16 */
if(!s->budget--) { s->failed_pc=0x0c085a16u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c085a18;
P_0c085a18: /* original 9098, guest PC 0x0c085a18 */
if(!s->budget--) { s->failed_pc=0x0c085a18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b4cu,2);
goto P_0c085a1a;
P_0c085a1a: /* original d351, guest PC 0x0c085a1a */
if(!s->budget--) { s->failed_pc=0x0c085a1au; return 0; }
r[3]=read(ram,0x0c085b60u,4);
goto P_0c085a1c;
P_0c085a1c: /* original 3f0c, guest PC 0x0c085a1c */
if(!s->budget--) { s->failed_pc=0x0c085a1cu; return 0; }
r[15]+=r[0];
goto P_0c085a1e;
P_0c085a1e: /* original d052, guest PC 0x0c085a1e */
if(!s->budget--) { s->failed_pc=0x0c085a1eu; return 0; }
r[0]=read(ram,0x0c085b68u,4);
goto P_0c085a20;
P_0c085a20: /* original d250, guest PC 0x0c085a20 */
if(!s->budget--) { s->failed_pc=0x0c085a20u; return 0; }
r[2]=read(ram,0x0c085b64u,4);
goto P_0c085a22;
P_0c085a22: /* original 6102, guest PC 0x0c085a22 */
if(!s->budget--) { s->failed_pc=0x0c085a22u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c085a24;
P_0c085a24: /* original 6e32, guest PC 0x0c085a24 */
if(!s->budget--) { s->failed_pc=0x0c085a24u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c085a26;
P_0c085a26: /* original 2128, guest PC 0x0c085a26 */
if(!s->budget--) { s->failed_pc=0x0c085a26u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c085a28;
P_0c085a28: /* original 8b06, guest PC 0x0c085a28 */
if(!s->budget--) { s->failed_pc=0x0c085a28u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085a38; }
goto P_0c085a2a;
P_0c085a2a: /* original 85e3, guest PC 0x0c085a2a */
if(!s->budget--) { s->failed_pc=0x0c085a2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+6,2);
goto P_0c085a2c;
P_0c085a2c: /* original e37f, guest PC 0x0c085a2c */
if(!s->budget--) { s->failed_pc=0x0c085a2cu; return 0; }
r[3]=0x0000007fu;
goto P_0c085a2e;
P_0c085a2e: /* original 640d, guest PC 0x0c085a2e */
if(!s->budget--) { s->failed_pc=0x0c085a2eu; return 0; }
r[4]=r[0]&65535u;
goto P_0c085a30;
P_0c085a30: /* original 7401, guest PC 0x0c085a30 */
if(!s->budget--) { s->failed_pc=0x0c085a30u; return 0; }
r[4]+=0x00000001u;
goto P_0c085a32;
P_0c085a32: /* original 2439, guest PC 0x0c085a32 */
if(!s->budget--) { s->failed_pc=0x0c085a32u; return 0; }
r[4]&=r[3];
goto P_0c085a34;
P_0c085a34: /* original 6043, guest PC 0x0c085a34 */
if(!s->budget--) { s->failed_pc=0x0c085a34u; return 0; }
r[0]=r[4];
goto P_0c085a36;
P_0c085a36: /* original 81e3, guest PC 0x0c085a36 */
if(!s->budget--) { s->failed_pc=0x0c085a36u; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c085a38;
P_0c085a38: /* original d34c, guest PC 0x0c085a38 */
if(!s->budget--) { s->failed_pc=0x0c085a38u; return 0; }
r[3]=read(ram,0x0c085b6cu,4);
goto P_0c085a3a;
P_0c085a3a: /* original 64f3, guest PC 0x0c085a3a */
if(!s->budget--) { s->failed_pc=0x0c085a3au; return 0; }
r[4]=r[15];
goto P_0c085a3c;
P_0c085a3c: /* original 430b, guest PC 0x0c085a3c */
if(!s->budget--) { s->failed_pc=0x0c085a3cu; return 0; }
target=r[3];
r[16]=0x0c085a40u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085a40u) { target=s->pc; goto dispatch; }
goto P_0c085a40;
P_0c085a3e: /* original 7410, guest PC 0x0c085a3e */
if(!s->budget--) { s->failed_pc=0x0c085a3eu; return 0; }
r[4]+=0x00000010u;
goto P_0c085a40;
P_0c085a40: /* original d24c, guest PC 0x0c085a40 */
if(!s->budget--) { s->failed_pc=0x0c085a40u; return 0; }
r[2]=read(ram,0x0c085b74u,4);
goto P_0c085a42;
P_0c085a42: /* original d44b, guest PC 0x0c085a42 */
if(!s->budget--) { s->failed_pc=0x0c085a42u; return 0; }
r[4]=read(ram,0x0c085b70u,4);
goto P_0c085a44;
P_0c085a44: /* original 420b, guest PC 0x0c085a44 */
if(!s->budget--) { s->failed_pc=0x0c085a44u; return 0; }
target=r[2];
r[16]=0x0c085a48u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085a48u) { target=s->pc; goto dispatch; }
goto P_0c085a48;
P_0c085a46: /* original 0009, guest PC 0x0c085a46 */
if(!s->budget--) { s->failed_pc=0x0c085a46u; return 0; }
goto P_0c085a48;
P_0c085a48: /* original ed00, guest PC 0x0c085a48 */
if(!s->budget--) { s->failed_pc=0x0c085a48u; return 0; }
r[13]=0x00000000u;
goto P_0c085a4a;
P_0c085a4a: /* original 9480, guest PC 0x0c085a4a */
if(!s->budget--) { s->failed_pc=0x0c085a4au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b4eu,2);
goto P_0c085a4c;
P_0c085a4c: /* original 60d3, guest PC 0x0c085a4c */
if(!s->budget--) { s->failed_pc=0x0c085a4cu; return 0; }
r[0]=r[13];
goto P_0c085a4e;
P_0c085a4e: /* original 81f6, guest PC 0x0c085a4e */
if(!s->budget--) { s->failed_pc=0x0c085a4eu; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c085a50;
P_0c085a50: /* original f68d, guest PC 0x0c085a50 */
if(!s->budget--) { s->failed_pc=0x0c085a50u; return 0; }
fr[6]=0;
goto P_0c085a52;
P_0c085a52: /* original 67d3, guest PC 0x0c085a52 */
if(!s->budget--) { s->failed_pc=0x0c085a52u; return 0; }
r[7]=r[13];
goto P_0c085a54;
P_0c085a54: /* original f46c, guest PC 0x0c085a54 */
if(!s->budget--) { s->failed_pc=0x0c085a54u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c085a56;
P_0c085a56: /* original f56c, guest PC 0x0c085a56 */
if(!s->budget--) { s->failed_pc=0x0c085a56u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c085a58;
P_0c085a58: /* original ff6a, guest PC 0x0c085a58 */
if(!s->budget--) { s->failed_pc=0x0c085a58u; return 0; }
vf3_matrix_store(s,ram,6,r[15]);
goto P_0c085a5a;
P_0c085a5a: /* original 85f6, guest PC 0x0c085a5a */
if(!s->budget--) { s->failed_pc=0x0c085a5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c085a5c;
P_0c085a5c: /* original 6603, guest PC 0x0c085a5c */
if(!s->budget--) { s->failed_pc=0x0c085a5cu; return 0; }
r[6]=r[0];
goto P_0c085a5e;
P_0c085a5e: /* original b054, guest PC 0x0c085a5e */
if(!s->budget--) { s->failed_pc=0x0c085a5eu; return 0; }
target=0x0c085b0au; r[16]=0x0c085a62u;
r[5]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085a62u) { target=s->pc; goto dispatch; }
goto P_0c085a62;
P_0c085a60: /* original 65d3, guest PC 0x0c085a60 */
if(!s->budget--) { s->failed_pc=0x0c085a60u; return 0; }
r[5]=r[13];
goto P_0c085a62;
P_0c085a62: /* original 9077, guest PC 0x0c085a62 */
if(!s->budget--) { s->failed_pc=0x0c085a62u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b54u,2);
goto P_0c085a64;
P_0c085a64: /* original 9c75, guest PC 0x0c085a64 */
if(!s->budget--) { s->failed_pc=0x0c085a64u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b52u,2);
goto P_0c085a66;
P_0c085a66: /* original 05ed, guest PC 0x0c085a66 */
if(!s->budget--) { s->failed_pc=0x0c085a66u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085a68;
P_0c085a68: /* original 7002, guest PC 0x0c085a68 */
if(!s->budget--) { s->failed_pc=0x0c085a68u; return 0; }
r[0]+=0x00000002u;
goto P_0c085a6a;
P_0c085a6a: /* original 04ed, guest PC 0x0c085a6a */
if(!s->budget--) { s->failed_pc=0x0c085a6au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085a6c;
P_0c085a6c: /* original 3c5c, guest PC 0x0c085a6c */
if(!s->budget--) { s->failed_pc=0x0c085a6cu; return 0; }
r[12]+=r[5];
goto P_0c085a6e;
P_0c085a6e: /* original 9b6f, guest PC 0x0c085a6e */
if(!s->budget--) { s->failed_pc=0x0c085a6eu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b50u,2);
goto P_0c085a70;
P_0c085a70: /* original 6ccf, guest PC 0x0c085a70 */
if(!s->budget--) { s->failed_pc=0x0c085a70u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c085a72;
P_0c085a72: /* original da41, guest PC 0x0c085a72 */
if(!s->budget--) { s->failed_pc=0x0c085a72u; return 0; }
r[10]=read(ram,0x0c085b78u,4);
goto P_0c085a74;
P_0c085a74: /* original 2fd6, guest PC 0x0c085a74 */
if(!s->budget--) { s->failed_pc=0x0c085a74u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085a76;
P_0c085a76: /* original 3b4c, guest PC 0x0c085a76 */
if(!s->budget--) { s->failed_pc=0x0c085a76u; return 0; }
r[11]+=r[4];
goto P_0c085a78;
P_0c085a78: /* original 2fc6, guest PC 0x0c085a78 */
if(!s->budget--) { s->failed_pc=0x0c085a78u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085a7a;
P_0c085a7a: /* original 67bf, guest PC 0x0c085a7a */
if(!s->budget--) { s->failed_pc=0x0c085a7au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c085a7c;
P_0c085a7c: /* original 65f3, guest PC 0x0c085a7c */
if(!s->budget--) { s->failed_pc=0x0c085a7cu; return 0; }
r[5]=r[15];
goto P_0c085a7e;
P_0c085a7e: /* original 66f3, guest PC 0x0c085a7e */
if(!s->budget--) { s->failed_pc=0x0c085a7eu; return 0; }
r[6]=r[15];
goto P_0c085a80;
P_0c085a80: /* original 64f3, guest PC 0x0c085a80 */
if(!s->budget--) { s->failed_pc=0x0c085a80u; return 0; }
r[4]=r[15];
goto P_0c085a82;
P_0c085a82: /* original 750c, guest PC 0x0c085a82 */
if(!s->budget--) { s->failed_pc=0x0c085a82u; return 0; }
r[5]+=0x0000000cu;
goto P_0c085a84;
P_0c085a84: /* original 7610, guest PC 0x0c085a84 */
if(!s->budget--) { s->failed_pc=0x0c085a84u; return 0; }
r[6]+=0x00000010u;
goto P_0c085a86;
P_0c085a86: /* original 4a0b, guest PC 0x0c085a86 */
if(!s->budget--) { s->failed_pc=0x0c085a86u; return 0; }
target=r[10];
r[16]=0x0c085a8au;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085a8au) { target=s->pc; goto dispatch; }
goto P_0c085a8a;
P_0c085a88: /* original 7408, guest PC 0x0c085a88 */
if(!s->budget--) { s->failed_pc=0x0c085a88u; return 0; }
r[4]+=0x00000008u;
goto P_0c085a8a;
P_0c085a8a: /* original 9063, guest PC 0x0c085a8a */
if(!s->budget--) { s->failed_pc=0x0c085a8au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b54u,2);
goto P_0c085a8c;
P_0c085a8c: /* original 9c63, guest PC 0x0c085a8c */
if(!s->budget--) { s->failed_pc=0x0c085a8cu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b56u,2);
goto P_0c085a8e;
P_0c085a8e: /* original 04ed, guest PC 0x0c085a8e */
if(!s->budget--) { s->failed_pc=0x0c085a8eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085a90;
P_0c085a90: /* original 7002, guest PC 0x0c085a90 */
if(!s->budget--) { s->failed_pc=0x0c085a90u; return 0; }
r[0]+=0x00000002u;
goto P_0c085a92;
P_0c085a92: /* original 9b5c, guest PC 0x0c085a92 */
if(!s->budget--) { s->failed_pc=0x0c085a92u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b4eu,2);
goto P_0c085a94;
P_0c085a94: /* original 654b, guest PC 0x0c085a94 */
if(!s->budget--) { s->failed_pc=0x0c085a94u; return 0; }
r[5]=0u-r[4];
goto P_0c085a96;
P_0c085a96: /* original 04ed, guest PC 0x0c085a96 */
if(!s->budget--) { s->failed_pc=0x0c085a96u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085a98;
P_0c085a98: /* original 3c5c, guest PC 0x0c085a98 */
if(!s->budget--) { s->failed_pc=0x0c085a98u; return 0; }
r[12]+=r[5];
goto P_0c085a9a;
P_0c085a9a: /* original 2fd6, guest PC 0x0c085a9a */
if(!s->budget--) { s->failed_pc=0x0c085a9au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085a9c;
P_0c085a9c: /* original 6ccf, guest PC 0x0c085a9c */
if(!s->budget--) { s->failed_pc=0x0c085a9cu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c085a9e;
P_0c085a9e: /* original 2fc6, guest PC 0x0c085a9e */
if(!s->budget--) { s->failed_pc=0x0c085a9eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085aa0;
P_0c085aa0: /* original 3b4c, guest PC 0x0c085aa0 */
if(!s->budget--) { s->failed_pc=0x0c085aa0u; return 0; }
r[11]+=r[4];
goto P_0c085aa2;
P_0c085aa2: /* original 66f3, guest PC 0x0c085aa2 */
if(!s->budget--) { s->failed_pc=0x0c085aa2u; return 0; }
r[6]=r[15];
goto P_0c085aa4;
P_0c085aa4: /* original 65f3, guest PC 0x0c085aa4 */
if(!s->budget--) { s->failed_pc=0x0c085aa4u; return 0; }
r[5]=r[15];
goto P_0c085aa6;
P_0c085aa6: /* original 7514, guest PC 0x0c085aa6 */
if(!s->budget--) { s->failed_pc=0x0c085aa6u; return 0; }
r[5]+=0x00000014u;
goto P_0c085aa8;
P_0c085aa8: /* original 64f3, guest PC 0x0c085aa8 */
if(!s->budget--) { s->failed_pc=0x0c085aa8u; return 0; }
r[4]=r[15];
goto P_0c085aaa;
P_0c085aaa: /* original 7618, guest PC 0x0c085aaa */
if(!s->budget--) { s->failed_pc=0x0c085aaau; return 0; }
r[6]+=0x00000018u;
goto P_0c085aac;
P_0c085aac: /* original 67bf, guest PC 0x0c085aac */
if(!s->budget--) { s->failed_pc=0x0c085aacu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c085aae;
P_0c085aae: /* original 4a0b, guest PC 0x0c085aae */
if(!s->budget--) { s->failed_pc=0x0c085aaeu; return 0; }
target=r[10];
r[16]=0x0c085ab2u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085ab2u) { target=s->pc; goto dispatch; }
goto P_0c085ab2;
P_0c085ab0: /* original 7410, guest PC 0x0c085ab0 */
if(!s->budget--) { s->failed_pc=0x0c085ab0u; return 0; }
r[4]+=0x00000010u;
goto P_0c085ab2;
P_0c085ab2: /* original 904f, guest PC 0x0c085ab2 */
if(!s->budget--) { s->failed_pc=0x0c085ab2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b54u,2);
goto P_0c085ab4;
P_0c085ab4: /* original 9c51, guest PC 0x0c085ab4 */
if(!s->budget--) { s->failed_pc=0x0c085ab4u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b5au,2);
goto P_0c085ab6;
P_0c085ab6: /* original 05ed, guest PC 0x0c085ab6 */
if(!s->budget--) { s->failed_pc=0x0c085ab6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085ab8;
P_0c085ab8: /* original 7002, guest PC 0x0c085ab8 */
if(!s->budget--) { s->failed_pc=0x0c085ab8u; return 0; }
r[0]+=0x00000002u;
goto P_0c085aba;
P_0c085aba: /* original 9b4d, guest PC 0x0c085aba */
if(!s->budget--) { s->failed_pc=0x0c085abau; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b58u,2);
goto P_0c085abc;
P_0c085abc: /* original 3c5c, guest PC 0x0c085abc */
if(!s->budget--) { s->failed_pc=0x0c085abcu; return 0; }
r[12]+=r[5];
goto P_0c085abe;
P_0c085abe: /* original 04ed, guest PC 0x0c085abe */
if(!s->budget--) { s->failed_pc=0x0c085abeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085ac0;
P_0c085ac0: /* original 6ccf, guest PC 0x0c085ac0 */
if(!s->budget--) { s->failed_pc=0x0c085ac0u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c085ac2;
P_0c085ac2: /* original 2fd6, guest PC 0x0c085ac2 */
if(!s->budget--) { s->failed_pc=0x0c085ac2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085ac4;
P_0c085ac4: /* original 2fc6, guest PC 0x0c085ac4 */
if(!s->budget--) { s->failed_pc=0x0c085ac4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085ac6;
P_0c085ac6: /* original 3b4c, guest PC 0x0c085ac6 */
if(!s->budget--) { s->failed_pc=0x0c085ac6u; return 0; }
r[11]+=r[4];
goto P_0c085ac8;
P_0c085ac8: /* original 66f3, guest PC 0x0c085ac8 */
if(!s->budget--) { s->failed_pc=0x0c085ac8u; return 0; }
r[6]=r[15];
goto P_0c085aca;
P_0c085aca: /* original 65f3, guest PC 0x0c085aca */
if(!s->budget--) { s->failed_pc=0x0c085acau; return 0; }
r[5]=r[15];
goto P_0c085acc;
P_0c085acc: /* original 751c, guest PC 0x0c085acc */
if(!s->budget--) { s->failed_pc=0x0c085accu; return 0; }
r[5]+=0x0000001cu;
goto P_0c085ace;
P_0c085ace: /* original 64f3, guest PC 0x0c085ace */
if(!s->budget--) { s->failed_pc=0x0c085aceu; return 0; }
r[4]=r[15];
goto P_0c085ad0;
P_0c085ad0: /* original 67bf, guest PC 0x0c085ad0 */
if(!s->budget--) { s->failed_pc=0x0c085ad0u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c085ad2;
P_0c085ad2: /* original 7620, guest PC 0x0c085ad2 */
if(!s->budget--) { s->failed_pc=0x0c085ad2u; return 0; }
r[6]+=0x00000020u;
goto P_0c085ad4;
P_0c085ad4: /* original 4a0b, guest PC 0x0c085ad4 */
if(!s->budget--) { s->failed_pc=0x0c085ad4u; return 0; }
target=r[10];
r[16]=0x0c085ad8u;
r[4]+=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085ad8u) { target=s->pc; goto dispatch; }
goto P_0c085ad8;
P_0c085ad6: /* original 7418, guest PC 0x0c085ad6 */
if(!s->budget--) { s->failed_pc=0x0c085ad6u; return 0; }
r[4]+=0x00000018u;
goto P_0c085ad8;
P_0c085ad8: /* original d328, guest PC 0x0c085ad8 */
if(!s->budget--) { s->failed_pc=0x0c085ad8u; return 0; }
r[3]=read(ram,0x0c085b7cu,4);
goto P_0c085ada;
P_0c085ada: /* original 7f18, guest PC 0x0c085ada */
if(!s->budget--) { s->failed_pc=0x0c085adau; return 0; }
r[15]+=0x00000018u;
goto P_0c085adc;
P_0c085adc: /* original 1f33, guest PC 0x0c085adc */
if(!s->budget--) { s->failed_pc=0x0c085adcu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c085ade;
P_0c085ade: /* original de28, guest PC 0x0c085ade */
if(!s->budget--) { s->failed_pc=0x0c085adeu; return 0; }
r[14]=read(ram,0x0c085b80u,4);
goto P_0c085ae0;
P_0c085ae0: /* original 60e1, guest PC 0x0c085ae0 */
if(!s->budget--) { s->failed_pc=0x0c085ae0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c085ae2;
P_0c085ae2: /* original 88ff, guest PC 0x0c085ae2 */
if(!s->budget--) { s->failed_pc=0x0c085ae2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c085ae4;
P_0c085ae4: /* original 8d04, guest PC 0x0c085ae4 */
if(!s->budget--) { s->failed_pc=0x0c085ae4u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c085af0; }
goto P_0c085ae8;
P_0c085ae6: /* original 6403, guest PC 0x0c085ae6 */
if(!s->budget--) { s->failed_pc=0x0c085ae6u; return 0; }
r[4]=r[0];
goto P_0c085ae8;
P_0c085ae8: /* original 85e1, guest PC 0x0c085ae8 */
if(!s->budget--) { s->failed_pc=0x0c085ae8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c085aea;
P_0c085aea: /* original 6503, guest PC 0x0c085aea */
if(!s->budget--) { s->failed_pc=0x0c085aeau; return 0; }
r[5]=r[0];
goto P_0c085aec;
P_0c085aec: /* original b02c, guest PC 0x0c085aec */
if(!s->budget--) { s->failed_pc=0x0c085aecu; return 0; }
target=0x0c085b48u; r[16]=0x0c085af0u;
r[4]=read(ram,r[15]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085af0u) { target=s->pc; goto dispatch; }
goto P_0c085af0;
P_0c085aee: /* original 54f3, guest PC 0x0c085aee */
if(!s->budget--) { s->failed_pc=0x0c085aeeu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c085af0;
P_0c085af0: /* original d324, guest PC 0x0c085af0 */
if(!s->budget--) { s->failed_pc=0x0c085af0u; return 0; }
r[3]=read(ram,0x0c085b84u,4);
goto P_0c085af2;
P_0c085af2: /* original 64f3, guest PC 0x0c085af2 */
if(!s->budget--) { s->failed_pc=0x0c085af2u; return 0; }
r[4]=r[15];
goto P_0c085af4;
P_0c085af4: /* original 430b, guest PC 0x0c085af4 */
if(!s->budget--) { s->failed_pc=0x0c085af4u; return 0; }
target=r[3];
r[16]=0x0c085af8u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085af8u) { target=s->pc; goto dispatch; }
goto P_0c085af8;
P_0c085af6: /* original 7410, guest PC 0x0c085af6 */
if(!s->budget--) { s->failed_pc=0x0c085af6u; return 0; }
r[4]+=0x00000010u;
goto P_0c085af8;
P_0c085af8: /* original 9130, guest PC 0x0c085af8 */
if(!s->budget--) { s->failed_pc=0x0c085af8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b5cu,2);
goto P_0c085afa;
P_0c085afa: /* original 3f1c, guest PC 0x0c085afa */
if(!s->budget--) { s->failed_pc=0x0c085afau; return 0; }
r[15]+=r[1];
goto P_0c085afc;
P_0c085afc: /* original 4f26, guest PC 0x0c085afc */
if(!s->budget--) { s->failed_pc=0x0c085afcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c085afe;
P_0c085afe: /* original 6af6, guest PC 0x0c085afe */
if(!s->budget--) { s->failed_pc=0x0c085afeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c085b00;
P_0c085b00: /* original 6bf6, guest PC 0x0c085b00 */
if(!s->budget--) { s->failed_pc=0x0c085b00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c085b02;
P_0c085b02: /* original 6cf6, guest PC 0x0c085b02 */
if(!s->budget--) { s->failed_pc=0x0c085b02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c085b04;
P_0c085b04: /* original 6df6, guest PC 0x0c085b04 */
if(!s->budget--) { s->failed_pc=0x0c085b04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c085b06;
P_0c085b06: /* original 000b, guest PC 0x0c085b06 */
if(!s->budget--) { s->failed_pc=0x0c085b06u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c085b08: /* original 6ef6, guest PC 0x0c085b08 */
if(!s->budget--) { s->failed_pc=0x0c085b08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c085b0a;
P_0c085b0a: /* original 2fe6, guest PC 0x0c085b0a */
if(!s->budget--) { s->failed_pc=0x0c085b0au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085b0c;
P_0c085b0c: /* original 6053, guest PC 0x0c085b0c */
if(!s->budget--) { s->failed_pc=0x0c085b0cu; return 0; }
r[0]=r[5];
goto P_0c085b0e;
P_0c085b0e: /* original 4f22, guest PC 0x0c085b0e */
if(!s->budget--) { s->failed_pc=0x0c085b0eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c085b10;
P_0c085b10: /* original 6e4f, guest PC 0x0c085b10 */
if(!s->budget--) { s->failed_pc=0x0c085b10u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c085b12;
P_0c085b12: /* original 2ee8, guest PC 0x0c085b12 */
if(!s->budget--) { s->failed_pc=0x0c085b12u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c085b14;
P_0c085b14: /* original 7fec, guest PC 0x0c085b14 */
if(!s->budget--) { s->failed_pc=0x0c085b14u; return 0; }
r[15]+=0xffffffecu;
goto P_0c085b16;
P_0c085b16: /* original 63f3, guest PC 0x0c085b16 */
if(!s->budget--) { s->failed_pc=0x0c085b16u; return 0; }
r[3]=r[15];
goto P_0c085b18;
P_0c085b18: /* original 7310, guest PC 0x0c085b18 */
if(!s->budget--) { s->failed_pc=0x0c085b18u; return 0; }
r[3]+=0x00000010u;
goto P_0c085b1a;
P_0c085b1a: /* original f36a, guest PC 0x0c085b1a */
if(!s->budget--) { s->failed_pc=0x0c085b1au; return 0; }
vf3_matrix_store(s,ram,6,r[3]);
goto P_0c085b1c;
P_0c085b1c: /* original 81f4, guest PC 0x0c085b1c */
if(!s->budget--) { s->failed_pc=0x0c085b1cu; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c085b1e;
P_0c085b1e: /* original 6063, guest PC 0x0c085b1e */
if(!s->budget--) { s->failed_pc=0x0c085b1eu; return 0; }
r[0]=r[6];
goto P_0c085b20;
P_0c085b20: /* original 8d0e, guest PC 0x0c085b20 */
if(!s->budget--) { s->failed_pc=0x0c085b20u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+12,r[0],2);
if(cond) { goto P_0c085b40; }
goto P_0c085b24;
P_0c085b22: /* original 81f6, guest PC 0x0c085b22 */
if(!s->budget--) { s->failed_pc=0x0c085b22u; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c085b24;
P_0c085b24: /* original 85f6, guest PC 0x0c085b24 */
if(!s->budget--) { s->failed_pc=0x0c085b24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c085b26;
P_0c085b26: /* original 67e3, guest PC 0x0c085b26 */
if(!s->budget--) { s->failed_pc=0x0c085b26u; return 0; }
r[7]=r[14];
goto P_0c085b28;
P_0c085b28: /* original 2f06, guest PC 0x0c085b28 */
if(!s->budget--) { s->failed_pc=0x0c085b28u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085b2a;
P_0c085b2a: /* original 85f6, guest PC 0x0c085b2a */
if(!s->budget--) { s->failed_pc=0x0c085b2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c085b2c;
P_0c085b2c: /* original 2f06, guest PC 0x0c085b2c */
if(!s->budget--) { s->failed_pc=0x0c085b2cu; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085b2e;
P_0c085b2e: /* original 65f3, guest PC 0x0c085b2e */
if(!s->budget--) { s->failed_pc=0x0c085b2eu; return 0; }
r[5]=r[15];
goto P_0c085b30;
P_0c085b30: /* original d311, guest PC 0x0c085b30 */
if(!s->budget--) { s->failed_pc=0x0c085b30u; return 0; }
r[3]=read(ram,0x0c085b78u,4);
goto P_0c085b32;
P_0c085b32: /* original 66f3, guest PC 0x0c085b32 */
if(!s->budget--) { s->failed_pc=0x0c085b32u; return 0; }
r[6]=r[15];
goto P_0c085b34;
P_0c085b34: /* original 64f3, guest PC 0x0c085b34 */
if(!s->budget--) { s->failed_pc=0x0c085b34u; return 0; }
r[4]=r[15];
goto P_0c085b36;
P_0c085b36: /* original 760c, guest PC 0x0c085b36 */
if(!s->budget--) { s->failed_pc=0x0c085b36u; return 0; }
r[6]+=0x0000000cu;
goto P_0c085b38;
P_0c085b38: /* original 7508, guest PC 0x0c085b38 */
if(!s->budget--) { s->failed_pc=0x0c085b38u; return 0; }
r[5]+=0x00000008u;
goto P_0c085b3a;
P_0c085b3a: /* original 430b, guest PC 0x0c085b3a */
if(!s->budget--) { s->failed_pc=0x0c085b3au; return 0; }
target=r[3];
r[16]=0x0c085b3eu;
r[4]+=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085b3eu) { target=s->pc; goto dispatch; }
goto P_0c085b3e;
P_0c085b3c: /* original 7418, guest PC 0x0c085b3c */
if(!s->budget--) { s->failed_pc=0x0c085b3cu; return 0; }
r[4]+=0x00000018u;
goto P_0c085b3e;
P_0c085b3e: /* original 7f08, guest PC 0x0c085b3e */
if(!s->budget--) { s->failed_pc=0x0c085b3eu; return 0; }
r[15]+=0x00000008u;
goto P_0c085b40;
P_0c085b40: /* original 7f14, guest PC 0x0c085b40 */
if(!s->budget--) { s->failed_pc=0x0c085b40u; return 0; }
r[15]+=0x00000014u;
goto P_0c085b42;
P_0c085b42: /* original 4f26, guest PC 0x0c085b42 */
if(!s->budget--) { s->failed_pc=0x0c085b42u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c085b44;
P_0c085b44: /* original 000b, guest PC 0x0c085b44 */
if(!s->budget--) { s->failed_pc=0x0c085b44u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c085b46: /* original 6ef6, guest PC 0x0c085b46 */
if(!s->budget--) { s->failed_pc=0x0c085b46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c085b48;
P_0c085b48: /* original 000b, guest PC 0x0c085b48 */
if(!s->budget--) { s->failed_pc=0x0c085b48u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c085b4a: /* original 0009, guest PC 0x0c085b4a */
if(!s->budget--) { s->failed_pc=0x0c085b4au; return 0; }
return vf3_matrix_family(0x0c085b4cu,s,ram);
P_0c085b88: /* original 2fe6, guest PC 0x0c085b88 */
if(!s->budget--) { s->failed_pc=0x0c085b88u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085b8a;
P_0c085b8a: /* original 6e43, guest PC 0x0c085b8a */
if(!s->budget--) { s->failed_pc=0x0c085b8au; return 0; }
r[14]=r[4];
goto P_0c085b8c;
P_0c085b8c: /* original 4f22, guest PC 0x0c085b8c */
if(!s->budget--) { s->failed_pc=0x0c085b8cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c085b8e;
P_0c085b8e: /* original e340, guest PC 0x0c085b8e */
if(!s->budget--) { s->failed_pc=0x0c085b8eu; return 0; }
r[3]=0x00000040u;
goto P_0c085b90;
P_0c085b90: /* original 7ffc, guest PC 0x0c085b90 */
if(!s->budget--) { s->failed_pc=0x0c085b90u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c085b92;
P_0c085b92: /* original 2f52, guest PC 0x0c085b92 */
if(!s->budget--) { s->failed_pc=0x0c085b92u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c085b94;
P_0c085b94: /* original 9017, guest PC 0x0c085b94 */
if(!s->budget--) { s->failed_pc=0x0c085b94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085bc6u,2);
goto P_0c085b96;
P_0c085b96: /* original 04ed, guest PC 0x0c085b96 */
if(!s->budget--) { s->failed_pc=0x0c085b96u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085b98;
P_0c085b98: /* original 7401, guest PC 0x0c085b98 */
if(!s->budget--) { s->failed_pc=0x0c085b98u; return 0; }
r[4]+=0x00000001u;
goto P_0c085b9a;
P_0c085b9a: /* original 2438, guest PC 0x0c085b9a */
if(!s->budget--) { s->failed_pc=0x0c085b9au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c085b9c;
P_0c085b9c: /* original 8d0f, guest PC 0x0c085b9c */
if(!s->budget--) { s->failed_pc=0x0c085b9cu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],2);
if(cond) { goto P_0c085bbe; }
goto P_0c085ba0;
P_0c085b9e: /* original 0e45, guest PC 0x0c085b9e */
if(!s->budget--) { s->failed_pc=0x0c085b9eu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c085ba0;
P_0c085ba0: /* original d30a, guest PC 0x0c085ba0 */
if(!s->budget--) { s->failed_pc=0x0c085ba0u; return 0; }
r[3]=read(ram,0x0c085bccu,4);
goto P_0c085ba2;
P_0c085ba2: /* original e200, guest PC 0x0c085ba2 */
if(!s->budget--) { s->failed_pc=0x0c085ba2u; return 0; }
r[2]=0x00000000u;
goto P_0c085ba4;
P_0c085ba4: /* original 430b, guest PC 0x0c085ba4 */
if(!s->budget--) { s->failed_pc=0x0c085ba4u; return 0; }
target=r[3];
r[16]=0x0c085ba8u;
write(ram,r[14]+r[0],r[2],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085ba8u) { target=s->pc; goto dispatch; }
goto P_0c085ba8;
P_0c085ba6: /* original 0e25, guest PC 0x0c085ba6 */
if(!s->budget--) { s->failed_pc=0x0c085ba6u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c085ba8;
P_0c085ba8: /* original 6403, guest PC 0x0c085ba8 */
if(!s->budget--) { s->failed_pc=0x0c085ba8u; return 0; }
r[4]=r[0];
goto P_0c085baa;
P_0c085baa: /* original e00e, guest PC 0x0c085baa */
if(!s->budget--) { s->failed_pc=0x0c085baau; return 0; }
r[0]=0x0000000eu;
goto P_0c085bac;
P_0c085bac: /* original 4400, guest PC 0x0c085bac */
if(!s->budget--) { s->failed_pc=0x0c085bacu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c085bae;
P_0c085bae: /* original 2049, guest PC 0x0c085bae */
if(!s->budget--) { s->failed_pc=0x0c085baeu; return 0; }
r[0]&=r[4];
goto P_0c085bb0;
P_0c085bb0: /* original d407, guest PC 0x0c085bb0 */
if(!s->budget--) { s->failed_pc=0x0c085bb0u; return 0; }
r[4]=read(ram,0x0c085bd0u,4);
goto P_0c085bb2;
P_0c085bb2: /* original 034d, guest PC 0x0c085bb2 */
if(!s->budget--) { s->failed_pc=0x0c085bb2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c085bb4;
P_0c085bb4: /* original 9008, guest PC 0x0c085bb4 */
if(!s->budget--) { s->failed_pc=0x0c085bb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085bc8u,2);
goto P_0c085bb6;
P_0c085bb6: /* original 6433, guest PC 0x0c085bb6 */
if(!s->budget--) { s->failed_pc=0x0c085bb6u; return 0; }
r[4]=r[3];
goto P_0c085bb8;
P_0c085bb8: /* original 0e45, guest PC 0x0c085bb8 */
if(!s->budget--) { s->failed_pc=0x0c085bb8u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c085bba;
P_0c085bba: /* original 63f2, guest PC 0x0c085bba */
if(!s->budget--) { s->failed_pc=0x0c085bbau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c085bbc;
P_0c085bbc: /* original 2342, guest PC 0x0c085bbc */
if(!s->budget--) { s->failed_pc=0x0c085bbcu; return 0; }
write(ram,r[3],r[4],4);
goto P_0c085bbe;
P_0c085bbe: /* original 7f04, guest PC 0x0c085bbe */
if(!s->budget--) { s->failed_pc=0x0c085bbeu; return 0; }
r[15]+=0x00000004u;
goto P_0c085bc0;
P_0c085bc0: /* original 4f26, guest PC 0x0c085bc0 */
if(!s->budget--) { s->failed_pc=0x0c085bc0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c085bc2;
P_0c085bc2: /* original 000b, guest PC 0x0c085bc2 */
if(!s->budget--) { s->failed_pc=0x0c085bc2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c085bc4: /* original 6ef6, guest PC 0x0c085bc4 */
if(!s->budget--) { s->failed_pc=0x0c085bc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c085bc6u,s,ram);
P_0c0a7442: /* original d024, guest PC 0x0c0a7442 */
if(!s->budget--) { s->failed_pc=0x0c0a7442u; return 0; }
r[0]=read(ram,0x0c0a74d4u,4);
goto P_0c0a7444;
P_0c0a7444: /* original 7ffc, guest PC 0x0c0a7444 */
if(!s->budget--) { s->failed_pc=0x0c0a7444u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a7446;
P_0c0a7446: /* original e635, guest PC 0x0c0a7446 */
if(!s->budget--) { s->failed_pc=0x0c0a7446u; return 0; }
r[6]=0x00000035u;
goto P_0c0a7448;
P_0c0a7448: /* original 6503, guest PC 0x0c0a7448 */
if(!s->budget--) { s->failed_pc=0x0c0a7448u; return 0; }
r[5]=r[0];
goto P_0c0a744a;
P_0c0a744a: /* original 2f02, guest PC 0x0c0a744a */
if(!s->budget--) { s->failed_pc=0x0c0a744au; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0a744c;
P_0c0a744c: /* original af00, guest PC 0x0c0a744c */
if(!s->budget--) { s->failed_pc=0x0c0a744cu; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c0a7250u,s,ram);
P_0c0a744e: /* original 7f04, guest PC 0x0c0a744e */
if(!s->budget--) { s->failed_pc=0x0c0a744eu; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c0a7450u,s,ram);
P_0c0abcdc: /* original 4f22, guest PC 0x0c0abcdc */
if(!s->budget--) { s->failed_pc=0x0c0abcdcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abcde;
P_0c0abcde: /* original 7ffc, guest PC 0x0c0abcde */
if(!s->budget--) { s->failed_pc=0x0c0abcdeu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0abce0;
P_0c0abce0: /* original b004, guest PC 0x0c0abce0 */
if(!s->budget--) { s->failed_pc=0x0c0abce0u; return 0; }
target=0x0c0abcecu; r[16]=0x0c0abce4u;
write(ram,r[15],r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0abce4u) { target=s->pc; goto dispatch; }
goto P_0c0abce4;
P_0c0abce2: /* original 2f42, guest PC 0x0c0abce2 */
if(!s->budget--) { s->failed_pc=0x0c0abce2u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0abce4;
P_0c0abce4: /* original 64f2, guest PC 0x0c0abce4 */
if(!s->budget--) { s->failed_pc=0x0c0abce4u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0abce6;
P_0c0abce6: /* original 7f04, guest PC 0x0c0abce6 */
if(!s->budget--) { s->failed_pc=0x0c0abce6u; return 0; }
r[15]+=0x00000004u;
goto P_0c0abce8;
P_0c0abce8: /* original a020, guest PC 0x0c0abce8 */
if(!s->budget--) { s->failed_pc=0x0c0abce8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abd2c;
P_0c0abcea: /* original 4f26, guest PC 0x0c0abcea */
if(!s->budget--) { s->failed_pc=0x0c0abceau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0abcecu,s,ram);
P_0c0abd2c: /* original c737, guest PC 0x0c0abd2c */
if(!s->budget--) { s->failed_pc=0x0c0abd2cu; return 0; }
r[0]=0x0c0abe0cu;
goto P_0c0abd2e;
P_0c0abd2e: /* original d636, guest PC 0x0c0abd2e */
if(!s->budget--) { s->failed_pc=0x0c0abd2eu; return 0; }
r[6]=read(ram,0x0c0abe08u,4);
goto P_0c0abd30;
P_0c0abd30: /* original f708, guest PC 0x0c0abd30 */
if(!s->budget--) { s->failed_pc=0x0c0abd30u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0abd32;
P_0c0abd32: /* original e01c, guest PC 0x0c0abd32 */
if(!s->budget--) { s->failed_pc=0x0c0abd32u; return 0; }
r[0]=0x0000001cu;
goto P_0c0abd34;
P_0c0abd34: /* original 006c, guest PC 0x0c0abd34 */
if(!s->budget--) { s->failed_pc=0x0c0abd34u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0abd36;
P_0c0abd36: /* original e71b, guest PC 0x0c0abd36 */
if(!s->budget--) { s->failed_pc=0x0c0abd36u; return 0; }
r[7]=0x0000001bu;
goto P_0c0abd38;
P_0c0abd38: /* original 9560, guest PC 0x0c0abd38 */
if(!s->budget--) { s->failed_pc=0x0c0abd38u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abdfcu,2);
goto P_0c0abd3a;
P_0c0abd3a: /* original 600c, guest PC 0x0c0abd3a */
if(!s->budget--) { s->failed_pc=0x0c0abd3au; return 0; }
r[0]=r[0]&255u;
goto P_0c0abd3c;
P_0c0abd3c: /* original 354c, guest PC 0x0c0abd3c */
if(!s->budget--) { s->failed_pc=0x0c0abd3cu; return 0; }
r[5]+=r[4];
goto P_0c0abd3e;
P_0c0abd3e: /* original c90f, guest PC 0x0c0abd3e */
if(!s->budget--) { s->failed_pc=0x0c0abd3eu; return 0; }
r[0]&=15u;
goto P_0c0abd40;
P_0c0abd40: /* original f459, guest PC 0x0c0abd40 */
if(!s->budget--) { s->failed_pc=0x0c0abd40u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0abd42;
P_0c0abd42: /* original 880c, guest PC 0x0c0abd42 */
if(!s->budget--) { s->failed_pc=0x0c0abd42u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0abd44;
P_0c0abd44: /* original 8f06, guest PC 0x0c0abd44 */
if(!s->budget--) { s->failed_pc=0x0c0abd44u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,6,4);
if(!cond) { goto P_0c0abd54; }
goto P_0c0abd48;
P_0c0abd46: /* original f64c, guest PC 0x0c0abd46 */
if(!s->budget--) { s->failed_pc=0x0c0abd46u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c0abd48;
P_0c0abd48: /* original c731, guest PC 0x0c0abd48 */
if(!s->budget--) { s->failed_pc=0x0c0abd48u; return 0; }
r[0]=0x0c0abe10u;
goto P_0c0abd4a;
P_0c0abd4a: /* original f308, guest PC 0x0c0abd4a */
if(!s->budget--) { s->failed_pc=0x0c0abd4au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0abd4c;
P_0c0abd4c: /* original 9057, guest PC 0x0c0abd4c */
if(!s->budget--) { s->failed_pc=0x0c0abd4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abdfeu,2);
goto P_0c0abd4e;
P_0c0abd4e: /* original f246, guest PC 0x0c0abd4e */
if(!s->budget--) { s->failed_pc=0x0c0abd4eu; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c0abd50;
P_0c0abd50: /* original f325, guest PC 0x0c0abd50 */
if(!s->budget--) { s->failed_pc=0x0c0abd50u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0abd52;
P_0c0abd52: /* original 892b, guest PC 0x0c0abd52 */
if(!s->budget--) { s->failed_pc=0x0c0abd52u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abdac; }
goto P_0c0abd54;
P_0c0abd54: /* original f559, guest PC 0x0c0abd54 */
if(!s->budget--) { s->failed_pc=0x0c0abd54u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0abd56;
P_0c0abd56: /* original f545, guest PC 0x0c0abd56 */
if(!s->budget--) { s->failed_pc=0x0c0abd56u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c0abd58;
P_0c0abd58: /* original 8b00, guest PC 0x0c0abd58 */
if(!s->budget--) { s->failed_pc=0x0c0abd58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abd5c; }
goto P_0c0abd5a;
P_0c0abd5a: /* original f45c, guest PC 0x0c0abd5a */
if(!s->budget--) { s->failed_pc=0x0c0abd5au; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0abd5c;
P_0c0abd5c: /* original f655, guest PC 0x0c0abd5c */
if(!s->budget--) { s->failed_pc=0x0c0abd5cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[5]))!=0);
goto P_0c0abd5e;
P_0c0abd5e: /* original 8b00, guest PC 0x0c0abd5e */
if(!s->budget--) { s->failed_pc=0x0c0abd5eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abd62; }
goto P_0c0abd60;
P_0c0abd60: /* original f65c, guest PC 0x0c0abd60 */
if(!s->budget--) { s->failed_pc=0x0c0abd60u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c0abd62;
P_0c0abd62: /* original 4710, guest PC 0x0c0abd62 */
if(!s->budget--) { s->failed_pc=0x0c0abd62u; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c0abd64;
P_0c0abd64: /* original 8bf6, guest PC 0x0c0abd64 */
if(!s->budget--) { s->failed_pc=0x0c0abd64u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abd54; }
goto P_0c0abd66;
P_0c0abd66: /* original f461, guest PC 0x0c0abd66 */
if(!s->budget--) { s->failed_pc=0x0c0abd66u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c0abd68;
P_0c0abd68: /* original f475, guest PC 0x0c0abd68 */
if(!s->budget--) { s->failed_pc=0x0c0abd68u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[7]))!=0);
goto P_0c0abd6a;
P_0c0abd6a: /* original 8915, guest PC 0x0c0abd6a */
if(!s->budget--) { s->failed_pc=0x0c0abd6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abd98; }
goto P_0c0abd6c;
P_0c0abd6c: /* original e01c, guest PC 0x0c0abd6c */
if(!s->budget--) { s->failed_pc=0x0c0abd6cu; return 0; }
r[0]=0x0000001cu;
goto P_0c0abd6e;
P_0c0abd6e: /* original 006c, guest PC 0x0c0abd6e */
if(!s->budget--) { s->failed_pc=0x0c0abd6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0abd70;
P_0c0abd70: /* original e50f, guest PC 0x0c0abd70 */
if(!s->budget--) { s->failed_pc=0x0c0abd70u; return 0; }
r[5]=0x0000000fu;
goto P_0c0abd72;
P_0c0abd72: /* original 600c, guest PC 0x0c0abd72 */
if(!s->budget--) { s->failed_pc=0x0c0abd72u; return 0; }
r[0]=r[0]&255u;
goto P_0c0abd74;
P_0c0abd74: /* original 2509, guest PC 0x0c0abd74 */
if(!s->budget--) { s->failed_pc=0x0c0abd74u; return 0; }
r[5]&=r[0];
goto P_0c0abd76;
P_0c0abd76: /* original 6053, guest PC 0x0c0abd76 */
if(!s->budget--) { s->failed_pc=0x0c0abd76u; return 0; }
r[0]=r[5];
goto P_0c0abd78;
P_0c0abd78: /* original 8801, guest PC 0x0c0abd78 */
if(!s->budget--) { s->failed_pc=0x0c0abd78u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0abd7a;
P_0c0abd7a: /* original 8917, guest PC 0x0c0abd7a */
if(!s->budget--) { s->failed_pc=0x0c0abd7au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abdac; }
goto P_0c0abd7c;
P_0c0abd7c: /* original 6053, guest PC 0x0c0abd7c */
if(!s->budget--) { s->failed_pc=0x0c0abd7cu; return 0; }
r[0]=r[5];
goto P_0c0abd7e;
P_0c0abd7e: /* original 8804, guest PC 0x0c0abd7e */
if(!s->budget--) { s->failed_pc=0x0c0abd7eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0abd80;
P_0c0abd80: /* original 8914, guest PC 0x0c0abd80 */
if(!s->budget--) { s->failed_pc=0x0c0abd80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abdac; }
goto P_0c0abd82;
P_0c0abd82: /* original 6053, guest PC 0x0c0abd82 */
if(!s->budget--) { s->failed_pc=0x0c0abd82u; return 0; }
r[0]=r[5];
goto P_0c0abd84;
P_0c0abd84: /* original 8806, guest PC 0x0c0abd84 */
if(!s->budget--) { s->failed_pc=0x0c0abd84u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0abd86;
P_0c0abd86: /* original 8911, guest PC 0x0c0abd86 */
if(!s->budget--) { s->failed_pc=0x0c0abd86u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abdac; }
goto P_0c0abd88;
P_0c0abd88: /* original 6053, guest PC 0x0c0abd88 */
if(!s->budget--) { s->failed_pc=0x0c0abd88u; return 0; }
r[0]=r[5];
goto P_0c0abd8a;
P_0c0abd8a: /* original 880c, guest PC 0x0c0abd8a */
if(!s->budget--) { s->failed_pc=0x0c0abd8au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0abd8c;
P_0c0abd8c: /* original 890e, guest PC 0x0c0abd8c */
if(!s->budget--) { s->failed_pc=0x0c0abd8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abdac; }
goto P_0c0abd8e;
P_0c0abd8e: /* original 9037, guest PC 0x0c0abd8e */
if(!s->budget--) { s->failed_pc=0x0c0abd8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abe00u,2);
goto P_0c0abd90;
P_0c0abd90: /* original 004c, guest PC 0x0c0abd90 */
if(!s->budget--) { s->failed_pc=0x0c0abd90u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0abd92;
P_0c0abd92: /* original 600c, guest PC 0x0c0abd92 */
if(!s->budget--) { s->failed_pc=0x0c0abd92u; return 0; }
r[0]=r[0]&255u;
goto P_0c0abd94;
P_0c0abd94: /* original c810, guest PC 0x0c0abd94 */
if(!s->budget--) { s->failed_pc=0x0c0abd94u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0abd96;
P_0c0abd96: /* original 8909, guest PC 0x0c0abd96 */
if(!s->budget--) { s->failed_pc=0x0c0abd96u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0abdac; }
goto P_0c0abd98;
P_0c0abd98: /* original 9033, guest PC 0x0c0abd98 */
if(!s->budget--) { s->failed_pc=0x0c0abd98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abe02u,2);
goto P_0c0abd9a;
P_0c0abd9a: /* original f446, guest PC 0x0c0abd9a */
if(!s->budget--) { s->failed_pc=0x0c0abd9au; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0abd9c;
P_0c0abd9c: /* original 7004, guest PC 0x0c0abd9c */
if(!s->budget--) { s->failed_pc=0x0c0abd9cu; return 0; }
r[0]+=0x00000004u;
goto P_0c0abd9e;
P_0c0abd9e: /* original f546, guest PC 0x0c0abd9e */
if(!s->budget--) { s->failed_pc=0x0c0abd9eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0abda0;
P_0c0abda0: /* original e024, guest PC 0x0c0abda0 */
if(!s->budget--) { s->failed_pc=0x0c0abda0u; return 0; }
r[0]=0x00000024u;
goto P_0c0abda2;
P_0c0abda2: /* original f447, guest PC 0x0c0abda2 */
if(!s->budget--) { s->failed_pc=0x0c0abda2u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0abda4;
P_0c0abda4: /* original e02c, guest PC 0x0c0abda4 */
if(!s->budget--) { s->failed_pc=0x0c0abda4u; return 0; }
r[0]=0x0000002cu;
goto P_0c0abda6;
P_0c0abda6: /* original f457, guest PC 0x0c0abda6 */
if(!s->budget--) { s->failed_pc=0x0c0abda6u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0abda8;
P_0c0abda8: /* original a00a, guest PC 0x0c0abda8 */
if(!s->budget--) { s->failed_pc=0x0c0abda8u; return 0; }
r[5]=0x00000001u;
goto P_0c0abdc0;
P_0c0abdaa: /* original e501, guest PC 0x0c0abdaa */
if(!s->budget--) { s->failed_pc=0x0c0abdaau; return 0; }
r[5]=0x00000001u;
goto P_0c0abdac;
P_0c0abdac: /* original e024, guest PC 0x0c0abdac */
if(!s->budget--) { s->failed_pc=0x0c0abdacu; return 0; }
r[0]=0x00000024u;
goto P_0c0abdae;
P_0c0abdae: /* original f48d, guest PC 0x0c0abdae */
if(!s->budget--) { s->failed_pc=0x0c0abdaeu; return 0; }
fr[4]=0;
goto P_0c0abdb0;
P_0c0abdb0: /* original f447, guest PC 0x0c0abdb0 */
if(!s->budget--) { s->failed_pc=0x0c0abdb0u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0abdb2;
P_0c0abdb2: /* original e02c, guest PC 0x0c0abdb2 */
if(!s->budget--) { s->failed_pc=0x0c0abdb2u; return 0; }
r[0]=0x0000002cu;
goto P_0c0abdb4;
P_0c0abdb4: /* original f447, guest PC 0x0c0abdb4 */
if(!s->budget--) { s->failed_pc=0x0c0abdb4u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0abdb6;
P_0c0abdb6: /* original e500, guest PC 0x0c0abdb6 */
if(!s->budget--) { s->failed_pc=0x0c0abdb6u; return 0; }
r[5]=0x00000000u;
goto P_0c0abdb8;
P_0c0abdb8: /* original 9024, guest PC 0x0c0abdb8 */
if(!s->budget--) { s->failed_pc=0x0c0abdb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abe04u,2);
goto P_0c0abdba;
P_0c0abdba: /* original f447, guest PC 0x0c0abdba */
if(!s->budget--) { s->failed_pc=0x0c0abdbau; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0abdbc;
P_0c0abdbc: /* original 7008, guest PC 0x0c0abdbc */
if(!s->budget--) { s->failed_pc=0x0c0abdbcu; return 0; }
r[0]+=0x00000008u;
goto P_0c0abdbe;
P_0c0abdbe: /* original f447, guest PC 0x0c0abdbe */
if(!s->budget--) { s->failed_pc=0x0c0abdbeu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0abdc0;
P_0c0abdc0: /* original 000b, guest PC 0x0c0abdc0 */
if(!s->budget--) { s->failed_pc=0x0c0abdc0u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c0abdc2: /* original 6053, guest PC 0x0c0abdc2 */
if(!s->budget--) { s->failed_pc=0x0c0abdc2u; return 0; }
r[0]=r[5];
return vf3_matrix_family(0x0c0abdc4u,s,ram);
P_0c0ca0c6: /* original 4f22, guest PC 0x0c0ca0c6 */
if(!s->budget--) { s->failed_pc=0x0c0ca0c6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ca0c8;
P_0c0ca0c8: /* original 005d, guest PC 0x0c0ca0c8 */
if(!s->budget--) { s->failed_pc=0x0c0ca0c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0ca0ca;
P_0c0ca0ca: /* original d32e, guest PC 0x0c0ca0ca */
if(!s->budget--) { s->failed_pc=0x0c0ca0cau; return 0; }
r[3]=read(ram,0x0c0ca184u,4);
goto P_0c0ca0cc;
P_0c0ca0cc: /* original 7fec, guest PC 0x0c0ca0cc */
if(!s->budget--) { s->failed_pc=0x0c0ca0ccu; return 0; }
r[15]+=0xffffffecu;
goto P_0c0ca0ce;
P_0c0ca0ce: /* original d42a, guest PC 0x0c0ca0ce */
if(!s->budget--) { s->failed_pc=0x0c0ca0ceu; return 0; }
r[4]=read(ram,0x0c0ca178u,4);
goto P_0c0ca0d0;
P_0c0ca0d0: /* original 6d32, guest PC 0x0c0ca0d0 */
if(!s->budget--) { s->failed_pc=0x0c0ca0d0u; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c0ca0d2;
P_0c0ca0d2: /* original 81f8, guest PC 0x0c0ca0d2 */
if(!s->budget--) { s->failed_pc=0x0c0ca0d2u; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c0ca0d4;
P_0c0ca0d4: /* original e022, guest PC 0x0c0ca0d4 */
if(!s->budget--) { s->failed_pc=0x0c0ca0d4u; return 0; }
r[0]=0x00000022u;
goto P_0c0ca0d6;
P_0c0ca0d6: /* original 005d, guest PC 0x0c0ca0d6 */
if(!s->budget--) { s->failed_pc=0x0c0ca0d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0ca0d8;
P_0c0ca0d8: /* original 6e43, guest PC 0x0c0ca0d8 */
if(!s->budget--) { s->failed_pc=0x0c0ca0d8u; return 0; }
r[14]=r[4];
goto P_0c0ca0da;
P_0c0ca0da: /* original 81f6, guest PC 0x0c0ca0da */
if(!s->budget--) { s->failed_pc=0x0c0ca0dau; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c0ca0dc;
P_0c0ca0dc: /* original 2f16, guest PC 0x0c0ca0dc */
if(!s->budget--) { s->failed_pc=0x0c0ca0dcu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca0de;
P_0c0ca0de: /* original 85f8, guest PC 0x0c0ca0de */
if(!s->budget--) { s->failed_pc=0x0c0ca0deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c0ca0e0;
P_0c0ca0e0: /* original 2f06, guest PC 0x0c0ca0e0 */
if(!s->budget--) { s->failed_pc=0x0c0ca0e0u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca0e2;
P_0c0ca0e2: /* original 85fc, guest PC 0x0c0ca0e2 */
if(!s->budget--) { s->failed_pc=0x0c0ca0e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+24,2);
goto P_0c0ca0e4;
P_0c0ca0e4: /* original 66f3, guest PC 0x0c0ca0e4 */
if(!s->budget--) { s->failed_pc=0x0c0ca0e4u; return 0; }
r[6]=r[15];
goto P_0c0ca0e6;
P_0c0ca0e6: /* original 65f3, guest PC 0x0c0ca0e6 */
if(!s->budget--) { s->failed_pc=0x0c0ca0e6u; return 0; }
r[5]=r[15];
goto P_0c0ca0e8;
P_0c0ca0e8: /* original d227, guest PC 0x0c0ca0e8 */
if(!s->budget--) { s->failed_pc=0x0c0ca0e8u; return 0; }
r[2]=read(ram,0x0c0ca188u,4);
goto P_0c0ca0ea;
P_0c0ca0ea: /* original 64f3, guest PC 0x0c0ca0ea */
if(!s->budget--) { s->failed_pc=0x0c0ca0eau; return 0; }
r[4]=r[15];
goto P_0c0ca0ec;
P_0c0ca0ec: /* original 750c, guest PC 0x0c0ca0ec */
if(!s->budget--) { s->failed_pc=0x0c0ca0ecu; return 0; }
r[5]+=0x0000000cu;
goto P_0c0ca0ee;
P_0c0ca0ee: /* original 6703, guest PC 0x0c0ca0ee */
if(!s->budget--) { s->failed_pc=0x0c0ca0eeu; return 0; }
r[7]=r[0];
goto P_0c0ca0f0;
P_0c0ca0f0: /* original 7610, guest PC 0x0c0ca0f0 */
if(!s->budget--) { s->failed_pc=0x0c0ca0f0u; return 0; }
r[6]+=0x00000010u;
goto P_0c0ca0f2;
P_0c0ca0f2: /* original 420b, guest PC 0x0c0ca0f2 */
if(!s->budget--) { s->failed_pc=0x0c0ca0f2u; return 0; }
target=r[2];
r[16]=0x0c0ca0f6u;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ca0f6u) { target=s->pc; goto dispatch; }
goto P_0c0ca0f6;
P_0c0ca0f4: /* original 7408, guest PC 0x0c0ca0f4 */
if(!s->budget--) { s->failed_pc=0x0c0ca0f4u; return 0; }
r[4]+=0x00000008u;
goto P_0c0ca0f6;
P_0c0ca0f6: /* original e008, guest PC 0x0c0ca0f6 */
if(!s->budget--) { s->failed_pc=0x0c0ca0f6u; return 0; }
r[0]=0x00000008u;
goto P_0c0ca0f8;
P_0c0ca0f8: /* original f3f6, guest PC 0x0c0ca0f8 */
if(!s->budget--) { s->failed_pc=0x0c0ca0f8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca0fa;
P_0c0ca0fa: /* original e008, guest PC 0x0c0ca0fa */
if(!s->budget--) { s->failed_pc=0x0c0ca0fau; return 0; }
r[0]=0x00000008u;
goto P_0c0ca0fc;
P_0c0ca0fc: /* original fe37, guest PC 0x0c0ca0fc */
if(!s->budget--) { s->failed_pc=0x0c0ca0fcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca0fe;
P_0c0ca0fe: /* original e00c, guest PC 0x0c0ca0fe */
if(!s->budget--) { s->failed_pc=0x0c0ca0feu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ca100;
P_0c0ca100: /* original f3f6, guest PC 0x0c0ca100 */
if(!s->budget--) { s->failed_pc=0x0c0ca100u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca102;
P_0c0ca102: /* original e00c, guest PC 0x0c0ca102 */
if(!s->budget--) { s->failed_pc=0x0c0ca102u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ca104;
P_0c0ca104: /* original fe37, guest PC 0x0c0ca104 */
if(!s->budget--) { s->failed_pc=0x0c0ca104u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca106;
P_0c0ca106: /* original e010, guest PC 0x0c0ca106 */
if(!s->budget--) { s->failed_pc=0x0c0ca106u; return 0; }
r[0]=0x00000010u;
goto P_0c0ca108;
P_0c0ca108: /* original f3f6, guest PC 0x0c0ca108 */
if(!s->budget--) { s->failed_pc=0x0c0ca108u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca10a;
P_0c0ca10a: /* original e010, guest PC 0x0c0ca10a */
if(!s->budget--) { s->failed_pc=0x0c0ca10au; return 0; }
r[0]=0x00000010u;
goto P_0c0ca10c;
P_0c0ca10c: /* original fe37, guest PC 0x0c0ca10c */
if(!s->budget--) { s->failed_pc=0x0c0ca10cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca10e;
P_0c0ca10e: /* original 9027, guest PC 0x0c0ca10e */
if(!s->budget--) { s->failed_pc=0x0c0ca10eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca160u,2);
goto P_0c0ca110;
P_0c0ca110: /* original f3d6, guest PC 0x0c0ca110 */
if(!s->budget--) { s->failed_pc=0x0c0ca110u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca112;
P_0c0ca112: /* original e004, guest PC 0x0c0ca112 */
if(!s->budget--) { s->failed_pc=0x0c0ca112u; return 0; }
r[0]=0x00000004u;
goto P_0c0ca114;
P_0c0ca114: /* original fe37, guest PC 0x0c0ca114 */
if(!s->budget--) { s->failed_pc=0x0c0ca114u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca116;
P_0c0ca116: /* original 9024, guest PC 0x0c0ca116 */
if(!s->budget--) { s->failed_pc=0x0c0ca116u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca162u,2);
goto P_0c0ca118;
P_0c0ca118: /* original f3d6, guest PC 0x0c0ca118 */
if(!s->budget--) { s->failed_pc=0x0c0ca118u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca11a;
P_0c0ca11a: /* original e014, guest PC 0x0c0ca11a */
if(!s->budget--) { s->failed_pc=0x0c0ca11au; return 0; }
r[0]=0x00000014u;
goto P_0c0ca11c;
P_0c0ca11c: /* original fe37, guest PC 0x0c0ca11c */
if(!s->budget--) { s->failed_pc=0x0c0ca11cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca11e;
P_0c0ca11e: /* original 9021, guest PC 0x0c0ca11e */
if(!s->budget--) { s->failed_pc=0x0c0ca11eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca164u,2);
goto P_0c0ca120;
P_0c0ca120: /* original f3d6, guest PC 0x0c0ca120 */
if(!s->budget--) { s->failed_pc=0x0c0ca120u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca122;
P_0c0ca122: /* original e028, guest PC 0x0c0ca122 */
if(!s->budget--) { s->failed_pc=0x0c0ca122u; return 0; }
r[0]=0x00000028u;
goto P_0c0ca124;
P_0c0ca124: /* original fe37, guest PC 0x0c0ca124 */
if(!s->budget--) { s->failed_pc=0x0c0ca124u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca126;
P_0c0ca126: /* original 901e, guest PC 0x0c0ca126 */
if(!s->budget--) { s->failed_pc=0x0c0ca126u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca166u,2);
goto P_0c0ca128;
P_0c0ca128: /* original 03dc, guest PC 0x0c0ca128 */
if(!s->budget--) { s->failed_pc=0x0c0ca128u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0ca12a;
P_0c0ca12a: /* original e018, guest PC 0x0c0ca12a */
if(!s->budget--) { s->failed_pc=0x0c0ca12au; return 0; }
r[0]=0x00000018u;
goto P_0c0ca12c;
P_0c0ca12c: /* original 0e34, guest PC 0x0c0ca12c */
if(!s->budget--) { s->failed_pc=0x0c0ca12cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ca12e;
P_0c0ca12e: /* original 901b, guest PC 0x0c0ca12e */
if(!s->budget--) { s->failed_pc=0x0c0ca12eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca168u,2);
goto P_0c0ca130;
P_0c0ca130: /* original 02dc, guest PC 0x0c0ca130 */
if(!s->budget--) { s->failed_pc=0x0c0ca130u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0ca132;
P_0c0ca132: /* original e019, guest PC 0x0c0ca132 */
if(!s->budget--) { s->failed_pc=0x0c0ca132u; return 0; }
r[0]=0x00000019u;
goto P_0c0ca134;
P_0c0ca134: /* original 0e24, guest PC 0x0c0ca134 */
if(!s->budget--) { s->failed_pc=0x0c0ca134u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0ca136;
P_0c0ca136: /* original 9018, guest PC 0x0c0ca136 */
if(!s->budget--) { s->failed_pc=0x0c0ca136u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca16au,2);
goto P_0c0ca138;
P_0c0ca138: /* original 7f1c, guest PC 0x0c0ca138 */
if(!s->budget--) { s->failed_pc=0x0c0ca138u; return 0; }
r[15]+=0x0000001cu;
goto P_0c0ca13a;
P_0c0ca13a: /* original 4f26, guest PC 0x0c0ca13a */
if(!s->budget--) { s->failed_pc=0x0c0ca13au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ca13c;
P_0c0ca13c: /* original 03dc, guest PC 0x0c0ca13c */
if(!s->budget--) { s->failed_pc=0x0c0ca13cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0ca13e;
P_0c0ca13e: /* original e01a, guest PC 0x0c0ca13e */
if(!s->budget--) { s->failed_pc=0x0c0ca13eu; return 0; }
r[0]=0x0000001au;
goto P_0c0ca140;
P_0c0ca140: /* original 0e34, guest PC 0x0c0ca140 */
if(!s->budget--) { s->failed_pc=0x0c0ca140u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ca142;
P_0c0ca142: /* original 9013, guest PC 0x0c0ca142 */
if(!s->budget--) { s->failed_pc=0x0c0ca142u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca16cu,2);
goto P_0c0ca144;
P_0c0ca144: /* original f3d6, guest PC 0x0c0ca144 */
if(!s->budget--) { s->failed_pc=0x0c0ca144u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca146;
P_0c0ca146: /* original e01c, guest PC 0x0c0ca146 */
if(!s->budget--) { s->failed_pc=0x0c0ca146u; return 0; }
r[0]=0x0000001cu;
goto P_0c0ca148;
P_0c0ca148: /* original fe37, guest PC 0x0c0ca148 */
if(!s->budget--) { s->failed_pc=0x0c0ca148u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca14a;
P_0c0ca14a: /* original 9010, guest PC 0x0c0ca14a */
if(!s->budget--) { s->failed_pc=0x0c0ca14au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca16eu,2);
goto P_0c0ca14c;
P_0c0ca14c: /* original f3d6, guest PC 0x0c0ca14c */
if(!s->budget--) { s->failed_pc=0x0c0ca14cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca14e;
P_0c0ca14e: /* original e020, guest PC 0x0c0ca14e */
if(!s->budget--) { s->failed_pc=0x0c0ca14eu; return 0; }
r[0]=0x00000020u;
goto P_0c0ca150;
P_0c0ca150: /* original fe37, guest PC 0x0c0ca150 */
if(!s->budget--) { s->failed_pc=0x0c0ca150u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca152;
P_0c0ca152: /* original 900d, guest PC 0x0c0ca152 */
if(!s->budget--) { s->failed_pc=0x0c0ca152u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca170u,2);
goto P_0c0ca154;
P_0c0ca154: /* original f3d6, guest PC 0x0c0ca154 */
if(!s->budget--) { s->failed_pc=0x0c0ca154u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ca156;
P_0c0ca156: /* original e024, guest PC 0x0c0ca156 */
if(!s->budget--) { s->failed_pc=0x0c0ca156u; return 0; }
r[0]=0x00000024u;
goto P_0c0ca158;
P_0c0ca158: /* original fe37, guest PC 0x0c0ca158 */
if(!s->budget--) { s->failed_pc=0x0c0ca158u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ca15a;
P_0c0ca15a: /* original 6df6, guest PC 0x0c0ca15a */
if(!s->budget--) { s->failed_pc=0x0c0ca15au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ca15c;
P_0c0ca15c: /* original 000b, guest PC 0x0c0ca15c */
if(!s->budget--) { s->failed_pc=0x0c0ca15cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ca15e: /* original 6ef6, guest PC 0x0c0ca15e */
if(!s->budget--) { s->failed_pc=0x0c0ca15eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ca160u,s,ram);
P_0c0ca326: /* original 000b, guest PC 0x0c0ca326 */
if(!s->budget--) { s->failed_pc=0x0c0ca326u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0ca328: /* original 0009, guest PC 0x0c0ca328 */
if(!s->budget--) { s->failed_pc=0x0c0ca328u; return 0; }
return vf3_matrix_family(0x0c0ca32au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c03da50u,0x0c03da52u,0x0c03da54u,0x0c03da56u,0x0c03da58u,0x0c03da5au,0x0c03da5cu,0x0c03da5eu,0x0c03da60u,0x0c03da62u,0x0c03da64u,0x0c03da66u,0x0c03da68u,0x0c03da6au,0x0c03da6cu,0x0c03da6eu,
0x0c03da70u,0x0c03da72u,0x0c03da74u,0x0c03da76u,0x0c03da78u,0x0c03da7au,0x0c03da7cu,0x0c03da7eu,0x0c03da80u,0x0c03da82u,0x0c03da84u,0x0c03da86u,0x0c03da88u,0x0c03da8au,0x0c03da8cu,0x0c03da8eu,
0x0c03da90u,0x0c03da92u,0x0c03da94u,0x0c03da96u,0x0c03da98u,0x0c03da9au,0x0c03da9cu,0x0c03da9eu,0x0c03daa0u,0x0c03daa2u,0x0c03daa4u,0x0c03daa6u,0x0c03daa8u,0x0c03daaau,0x0c03daacu,0x0c03daaeu,
0x0c03dab0u,0x0c03dab2u,0x0c03dab4u,0x0c03dab6u,0x0c03dab8u,0x0c03dabau,0x0c03dad0u,0x0c03dad2u,0x0c03dad4u,0x0c03dad6u,0x0c03dad8u,0x0c03dadau,0x0c03dadcu,0x0c03dadeu,0x0c03dae0u,0x0c03dae2u,
0x0c03dae4u,0x0c03dae6u,0x0c03dae8u,0x0c03daeau,0x0c03daecu,0x0c03daeeu,0x0c03daf0u,0x0c03daf2u,0x0c03daf4u,0x0c03daf6u,0x0c03daf8u,0x0c03dafau,0x0c03dafcu,0x0c03dafeu,0x0c03db00u,0x0c03db02u,
0x0c03db04u,0x0c03db06u,0x0c03db08u,0x0c03db10u,0x0c03db12u,0x0c03db14u,0x0c03db16u,0x0c03db18u,0x0c03db1au,0x0c03db1cu,0x0c03db1eu,0x0c03db20u,0x0c03db22u,0x0c03db24u,0x0c03db26u,0x0c03db28u,
0x0c03db2au,0x0c03db2cu,0x0c03db2eu,0x0c03db30u,0x0c03db32u,0x0c03db34u,0x0c03db36u,0x0c03db38u,0x0c03db40u,0x0c03db42u,0x0c03db44u,0x0c03db46u,0x0c03db48u,0x0c03db4au,0x0c03db4cu,0x0c03db4eu,
0x0c03db50u,0x0c03db52u,0x0c03db54u,0x0c03db56u,0x0c03db58u,0x0c03db5au,0x0c03db5cu,0x0c03db5eu,0x0c03db60u,0x0c03db62u,0x0c03db64u,0x0c03db66u,0x0c03db68u,0x0c03db6au,0x0c03db6cu,0x0c03db6eu,
0x0c03db70u,0x0c03db72u,0x0c03db74u,0x0c03db76u,0x0c03db78u,0x0c03db7au,0x0c03db7cu,0x0c03db80u,0x0c03db82u,0x0c03db84u,0x0c03db86u,0x0c03db88u,0x0c03db8au,0x0c03db8cu,0x0c03db8eu,0x0c03db90u,
0x0c03db92u,0x0c03db94u,0x0c03db96u,0x0c03db98u,0x0c03db9au,0x0c03db9cu,0x0c03db9eu,0x0c03dba0u,0x0c03dba2u,0x0c03ea22u,0x0c03ea24u,0x0c03ea26u,0x0c03ea28u,0x0c03ea2au,0x0c03ea2cu,0x0c03ea2eu,
0x0c03ea30u,0x0c03ea32u,0x0c03ea34u,0x0c03ea36u,0x0c03ea38u,0x0c03ea3au,0x0c03ea3cu,0x0c03ea3eu,0x0c03ea40u,0x0c03ea42u,0x0c03ea44u,0x0c03ea46u,0x0c03ea48u,0x0c03ea4au,0x0c03ea4cu,0x0c03ea4eu,
0x0c03ea50u,0x0c03ea52u,0x0c03ea54u,0x0c03ea56u,0x0c03ea58u,0x0c03ea5au,0x0c03ea5cu,0x0c03ea5eu,0x0c03ea60u,0x0c03ea62u,0x0c03ea64u,0x0c03ea66u,0x0c03ea68u,0x0c03ea6au,0x0c03ea6cu,0x0c03ea6eu,
0x0c03ea70u,0x0c03ea72u,0x0c03ea74u,0x0c03ea76u,0x0c03ea78u,0x0c03ea7au,0x0c03ea7cu,0x0c03ea7eu,0x0c03ea80u,0x0c03ea82u,0x0c03ea84u,0x0c03ea86u,0x0c03ea88u,0x0c03ea8au,0x0c03ea8cu,0x0c03ea8eu,
0x0c03ea90u,0x0c03ea92u,0x0c03ea94u,0x0c03ea96u,0x0c03ea98u,0x0c03ea9au,0x0c03ea9cu,0x0c03ea9eu,0x0c03eaa0u,0x0c03eaa2u,0x0c03eaa4u,0x0c03eaa6u,0x0c03eaa8u,0x0c03eaaau,0x0c03eaacu,0x0c03eaaeu,
0x0c03eab0u,0x0c03eab2u,0x0c03eab4u,0x0c03eab6u,0x0c03eab8u,0x0c03eabau,0x0c03eabcu,0x0c03eabeu,0x0c03eac0u,0x0c03eac2u,0x0c03eac4u,0x0c03eac6u,0x0c03eac8u,0x0c03eacau,0x0c03eaccu,0x0c03eaceu,
0x0c04baf6u,0x0c04baf8u,0x0c04bafau,0x0c04bafcu,0x0c04bafeu,0x0c04bb00u,0x0c04bb02u,0x0c04bb04u,0x0c04bb06u,0x0c04bb08u,0x0c04bb0au,0x0c04bb0cu,0x0c04bb0eu,0x0c04bb10u,0x0c04bb12u,0x0c04bb14u,
0x0c04bb16u,0x0c04bb18u,0x0c04bb1au,0x0c04bb1cu,0x0c04bb1eu,0x0c04bb20u,0x0c04bb22u,0x0c04bb24u,0x0c04bb26u,0x0c04bb28u,0x0c04bb58u,0x0c04bb5au,0x0c04bb5cu,0x0c04bb5eu,0x0c04bb60u,0x0c04bb62u,
0x0c04bb64u,0x0c04bb66u,0x0c04bb68u,0x0c04bb6au,0x0c04bb6cu,0x0c04bb6eu,0x0c04bb70u,0x0c04bb72u,0x0c04bb74u,0x0c04bb76u,0x0c04bb78u,0x0c04bb7au,0x0c04bb7cu,0x0c04bb7eu,0x0c04bb80u,0x0c04bb82u,
0x0c04bb84u,0x0c04bb86u,0x0c04bb88u,0x0c04bb8au,0x0c04bb8cu,0x0c04bb8eu,0x0c04bb90u,0x0c04bb92u,0x0c04bb94u,0x0c04bb96u,0x0c04bb98u,0x0c04bb9au,0x0c04bb9cu,0x0c04bb9eu,0x0c04bba0u,0x0c04bba2u,
0x0c04bba4u,0x0c04bba6u,0x0c04bba8u,0x0c04bbaau,0x0c04bbacu,0x0c04bbaeu,0x0c04bbb0u,0x0c04bbb2u,0x0c04bbb4u,0x0c04bbb6u,0x0c04bbb8u,0x0c04bbbau,0x0c04bbbcu,0x0c04bbbeu,0x0c04bbc0u,0x0c04bbc2u,
0x0c04bbc4u,0x0c05e46cu,0x0c05e46eu,0x0c05e470u,0x0c05e472u,0x0c05e474u,0x0c05e476u,0x0c05e478u,0x0c05e47au,0x0c05e47cu,0x0c05e47eu,0x0c05e480u,0x0c05e482u,0x0c05e484u,0x0c05e486u,0x0c05e488u,
0x0c05e48au,0x0c05e48cu,0x0c05e48eu,0x0c05e490u,0x0c05e492u,0x0c05e494u,0x0c05e496u,0x0c05e498u,0x0c05e49au,0x0c05e49cu,0x0c05e49eu,0x0c05e4a0u,0x0c05e4a2u,0x0c05e4a4u,0x0c05e4a6u,0x0c05e4a8u,
0x0c05e4aau,0x0c05e4acu,0x0c05e4aeu,0x0c05e4b0u,0x0c05e4b2u,0x0c05e4b4u,0x0c05e4b6u,0x0c05e4b8u,0x0c05e4bau,0x0c05e4bcu,0x0c05e4beu,0x0c05e4c0u,0x0c05e4c2u,0x0c05e4c4u,0x0c05e4c6u,0x0c06c406u,
0x0c06c408u,0x0c06c40au,0x0c06c40cu,0x0c06c40eu,0x0c06c410u,0x0c06c412u,0x0c06c414u,0x0c06c416u,0x0c06c418u,0x0c06c41au,0x0c06c41cu,0x0c06c41eu,0x0c06c420u,0x0c06c6d6u,0x0c06c6d8u,0x0c06c6dau,
0x0c06c6dcu,0x0c06c6deu,0x0c06c720u,0x0c06c722u,0x0c06c724u,0x0c06c726u,0x0c06c728u,0x0c06c72au,0x0c06c72cu,0x0c06c72eu,0x0c06c730u,0x0c06c732u,0x0c06c734u,0x0c06c736u,0x0c06c738u,0x0c06c73au,
0x0c06c73cu,0x0c06c73eu,0x0c06c740u,0x0c06c742u,0x0c06c744u,0x0c06c746u,0x0c06c748u,0x0c06c74au,0x0c06c74cu,0x0c06c74eu,0x0c06c750u,0x0c06c752u,0x0c06c754u,0x0c06c756u,0x0c06c758u,0x0c06c75au,
0x0c06c75cu,0x0c06c75eu,0x0c06c760u,0x0c06c762u,0x0c06c764u,0x0c06c766u,0x0c06c768u,0x0c06c76au,0x0c06c76cu,0x0c06c76eu,0x0c06c770u,0x0c06c772u,0x0c06c774u,0x0c06c776u,0x0c06c778u,0x0c06c77au,
0x0c06c77cu,0x0c06c77eu,0x0c06c780u,0x0c06c782u,0x0c06c784u,0x0c06c786u,0x0c06c788u,0x0c06c78au,0x0c06c78cu,0x0c06c78eu,0x0c06c790u,0x0c06c792u,0x0c06c794u,0x0c06c796u,0x0c06c798u,0x0c06c79au,
0x0c06c79cu,0x0c06c79eu,0x0c06c7a0u,0x0c06c7a2u,0x0c06c7a4u,0x0c06c7a6u,0x0c06c7a8u,0x0c06c7aau,0x0c06c7acu,0x0c06c7aeu,0x0c06c7b0u,0x0c06c7b2u,0x0c06c7b4u,0x0c06c7b6u,0x0c06c7b8u,0x0c06c7bau,
0x0c06c7bcu,0x0c06c7beu,0x0c06c7c0u,0x0c06c7c2u,0x0c06c7c4u,0x0c06c7c6u,0x0c06c7c8u,0x0c06c7cau,0x0c06c7e4u,0x0c06c7e6u,0x0c06c7e8u,0x0c06c7eau,0x0c06c7ecu,0x0c06c7eeu,0x0c06c7f0u,0x0c06c7f2u,
0x0c06c7f4u,0x0c06c7f6u,0x0c06c7f8u,0x0c06c7fau,0x0c06c7fcu,0x0c06c7feu,0x0c06c800u,0x0c06c802u,0x0c06c804u,0x0c06c806u,0x0c06c808u,0x0c06c80au,0x0c06c80cu,0x0c06c80eu,0x0c06c810u,0x0c06c812u,
0x0c06c814u,0x0c06c816u,0x0c06c818u,0x0c06c81au,0x0c06c81cu,0x0c06c81eu,0x0c06c820u,0x0c06c822u,0x0c06c824u,0x0c06c826u,0x0c06c828u,0x0c06c82au,0x0c06c82cu,0x0c06c82eu,0x0c06c830u,0x0c06c832u,
0x0c06c834u,0x0c06c836u,0x0c06c838u,0x0c06c83au,0x0c06c83cu,0x0c06c83eu,0x0c06c840u,0x0c06c842u,0x0c06c844u,0x0c06c846u,0x0c06c848u,0x0c06c84au,0x0c06c84cu,0x0c06c84eu,0x0c06c850u,0x0c06c852u,
0x0c06c854u,0x0c06c856u,0x0c06c858u,0x0c06c85au,0x0c06c85cu,0x0c06c85eu,0x0c06c860u,0x0c06c862u,0x0c06c864u,0x0c06c866u,0x0c06c868u,0x0c06c86au,0x0c06c86cu,0x0c06c86eu,0x0c06c870u,0x0c06c872u,
0x0c06c874u,0x0c06c876u,0x0c06c878u,0x0c06c87au,0x0c06c87cu,0x0c06c87eu,0x0c06c880u,0x0c06c882u,0x0c06c884u,0x0c06c886u,0x0c06c888u,0x0c06c88au,0x0c06c88cu,0x0c06c88eu,0x0c06c890u,0x0c06c892u,
0x0c06c894u,0x0c06c896u,0x0c06c898u,0x0c06c89au,0x0c06c89cu,0x0c06c89eu,0x0c06c8a0u,0x0c06c8a2u,0x0c06c95eu,0x0c06c960u,0x0c06c962u,0x0c06c964u,0x0c06c966u,0x0c06c968u,0x0c06c96au,0x0c06c96cu,
0x0c06c96eu,0x0c06c970u,0x0c06c972u,0x0c06c974u,0x0c06c976u,0x0c06c978u,0x0c06c97au,0x0c06c97cu,0x0c06c97eu,0x0c06c980u,0x0c06c982u,0x0c06c984u,0x0c06c986u,0x0c06c988u,0x0c06c98au,0x0c06c98cu,
0x0c06c98eu,0x0c06c990u,0x0c06c992u,0x0c06c994u,0x0c06c996u,0x0c06c998u,0x0c06c99au,0x0c06c99cu,0x0c06c99eu,0x0c06c9a0u,0x0c06c9a2u,0x0c06c9a4u,0x0c06c9a6u,0x0c06c9a8u,0x0c06c9aau,0x0c06c9acu,
0x0c06c9aeu,0x0c06c9b0u,0x0c06c9b2u,0x0c06c9b4u,0x0c06c9b6u,0x0c06c9b8u,0x0c06c9bau,0x0c06c9bcu,0x0c06c9beu,0x0c06c9c0u,0x0c06c9c2u,0x0c06c9c4u,0x0c06c9c6u,0x0c06c9c8u,0x0c06c9cau,0x0c06c9ccu,
0x0c06c9ceu,0x0c06c9d0u,0x0c06c9d2u,0x0c06c9d4u,0x0c06c9d6u,0x0c06c9d8u,0x0c06c9dau,0x0c06c9dcu,0x0c06c9deu,0x0c06c9e0u,0x0c06c9e2u,0x0c06c9e4u,0x0c06c9e6u,0x0c06c9e8u,0x0c06c9eau,0x0c06c9ecu,
0x0c06c9eeu,0x0c06c9f0u,0x0c06c9f2u,0x0c06c9f4u,0x0c06c9f6u,0x0c06ca30u,0x0c06ca32u,0x0c06ca34u,0x0c06ca36u,0x0c06ca38u,0x0c06ca3au,0x0c06ca3cu,0x0c06ca3eu,0x0c06ca40u,0x0c06ca42u,0x0c06ca44u,
0x0c06ca46u,0x0c06ca48u,0x0c06ca4au,0x0c06ca4cu,0x0c06ca4eu,0x0c06ca50u,0x0c06ca52u,0x0c06ca54u,0x0c06ca56u,0x0c06ca58u,0x0c06ca5au,0x0c06ca5cu,0x0c06ca5eu,0x0c06ca60u,0x0c06ca62u,0x0c06ca64u,
0x0c06ca66u,0x0c06ca68u,0x0c06ca6au,0x0c06ca6cu,0x0c06ca6eu,0x0c06ca70u,0x0c06ca72u,0x0c06ca74u,0x0c06ca76u,0x0c06ca78u,0x0c06ca7au,0x0c06ca7cu,0x0c06ca7eu,0x0c06ca80u,0x0c06ca82u,0x0c06ca84u,
0x0c06ca86u,0x0c06ca88u,0x0c06ca8au,0x0c06ca8cu,0x0c06ca8eu,0x0c06ca90u,0x0c06ca92u,0x0c06ca94u,0x0c06ca96u,0x0c06ca98u,0x0c06ca9au,0x0c06ca9cu,0x0c06ca9eu,0x0c06caa0u,0x0c06caa2u,0x0c06caa4u,
0x0c06caa6u,0x0c06caa8u,0x0c06caaau,0x0c06caacu,0x0c06caaeu,0x0c06cab0u,0x0c06cab2u,0x0c06cab4u,0x0c06cab6u,0x0c06cab8u,0x0c06cabau,0x0c06cabcu,0x0c06cabeu,0x0c06cac0u,0x0c06cac2u,0x0c06cac4u,
0x0c06cac6u,0x0c06cac8u,0x0c06cacau,0x0c06caccu,0x0c06caceu,0x0c06cad0u,0x0c06cad2u,0x0c06cad4u,0x0c06cad6u,0x0c06cad8u,0x0c06cadau,0x0c06cadcu,0x0c06cadeu,0x0c06cae0u,0x0c06cae2u,0x0c06cae4u,
0x0c06cae6u,0x0c06cae8u,0x0c06caeau,0x0c06caecu,0x0c06caeeu,0x0c06caf0u,0x0c06caf2u,0x0c06caf4u,0x0c06caf6u,0x0c06caf8u,0x0c06cafau,0x0c06cafcu,0x0c06cafeu,0x0c06cb00u,0x0c06cb02u,0x0c06cb04u,
0x0c06cb06u,0x0c06cb08u,0x0c06cb0au,0x0c06cb0cu,0x0c06cb0eu,0x0c06cb10u,0x0c06cb12u,0x0c06cb14u,0x0c06cb16u,0x0c06cb18u,0x0c06cb1au,0x0c06cb1cu,0x0c06cb1eu,0x0c06cb20u,0x0c06cb22u,0x0c06cb24u,
0x0c06cb26u,0x0c06cb28u,0x0c06cb2au,0x0c06cb2cu,0x0c06cb2eu,0x0c06cb30u,0x0c06cb32u,0x0c06cb34u,0x0c06cb36u,0x0c06cb38u,0x0c06cb60u,0x0c06cb62u,0x0c06cb64u,0x0c06cb66u,0x0c06cb68u,0x0c06cb6au,
0x0c06cb6cu,0x0c06cb6eu,0x0c06cb70u,0x0c06cb72u,0x0c06cb74u,0x0c06cb76u,0x0c06cb78u,0x0c06cb7au,0x0c06cb7cu,0x0c06cb7eu,0x0c06cb80u,0x0c06cb82u,0x0c06cb84u,0x0c06cb86u,0x0c06cb88u,0x0c06cb8au,
0x0c06cb8cu,0x0c06cb8eu,0x0c06cb90u,0x0c06cb92u,0x0c06cb94u,0x0c06cb96u,0x0c06cb98u,0x0c06cb9au,0x0c06cb9cu,0x0c06cb9eu,0x0c06cba0u,0x0c06cba2u,0x0c06cba4u,0x0c06cba6u,0x0c06cba8u,0x0c06cbaau,
0x0c06cbacu,0x0c06cbaeu,0x0c06cbb0u,0x0c06cbb2u,0x0c06cbb4u,0x0c06cbb6u,0x0c06cbb8u,0x0c06cbbau,0x0c06cbbcu,0x0c06cbbeu,0x0c06cbc0u,0x0c06cbc2u,0x0c06cbc4u,0x0c06cbc6u,0x0c06cbc8u,0x0c06cbcau,
0x0c06cbccu,0x0c06cbceu,0x0c06cbd0u,0x0c06cbd2u,0x0c06cbd4u,0x0c06cbd6u,0x0c06cbd8u,0x0c06cbdau,0x0c06cbdcu,0x0c06cbdeu,0x0c06cbe0u,0x0c06cbe2u,0x0c06cbe4u,0x0c06cbe6u,0x0c06cbe8u,0x0c06cbeau,
0x0c06cbecu,0x0c06cbeeu,0x0c06cbf0u,0x0c06cbf2u,0x0c06cbf4u,0x0c06cbf6u,0x0c06cbf8u,0x0c06cbfau,0x0c06cbfcu,0x0c06cbfeu,0x0c06cc00u,0x0c06cc02u,0x0c06cc04u,0x0c06cc06u,0x0c06cc08u,0x0c06cc0au,
0x0c06cc0cu,0x0c06cc0eu,0x0c06cc10u,0x0c06cc12u,0x0c06cc14u,0x0c06cc16u,0x0c06cc18u,0x0c06cc1au,0x0c06cc1cu,0x0c085666u,0x0c085668u,0x0c08566au,0x0c08566cu,0x0c08566eu,0x0c085670u,0x0c085672u,
0x0c085674u,0x0c085676u,0x0c085678u,0x0c08567au,0x0c08567cu,0x0c08567eu,0x0c085680u,0x0c085682u,0x0c085684u,0x0c085686u,0x0c085688u,0x0c08568au,0x0c08568cu,0x0c08568eu,0x0c085690u,0x0c085692u,
0x0c085694u,0x0c085696u,0x0c085698u,0x0c08569au,0x0c08569cu,0x0c08569eu,0x0c0856a0u,0x0c0856a2u,0x0c0856a4u,0x0c0856a6u,0x0c0856a8u,0x0c0856aau,0x0c0856acu,0x0c0856aeu,0x0c0856b0u,0x0c0856b2u,
0x0c0856b4u,0x0c0856b6u,0x0c0856b8u,0x0c0856bau,0x0c0856bcu,0x0c0856beu,0x0c0856c0u,0x0c0856c2u,0x0c0856c4u,0x0c0856c6u,0x0c0856c8u,0x0c0856cau,0x0c0856ccu,0x0c0856ceu,0x0c0856d0u,0x0c0856d2u,
0x0c0856d4u,0x0c0856d6u,0x0c0856d8u,0x0c0856dau,0x0c0856dcu,0x0c0856deu,0x0c0856e0u,0x0c0856e2u,0x0c0856e4u,0x0c0856e6u,0x0c0856e8u,0x0c0856eau,0x0c0856ecu,0x0c0856eeu,0x0c0856f0u,0x0c0856f2u,
0x0c0856f4u,0x0c0856f6u,0x0c0856f8u,0x0c0856fau,0x0c0856fcu,0x0c0856feu,0x0c085700u,0x0c085702u,0x0c085704u,0x0c085706u,0x0c085708u,0x0c08570au,0x0c08570cu,0x0c08570eu,0x0c085710u,0x0c085712u,
0x0c085714u,0x0c085716u,0x0c085718u,0x0c08571au,0x0c08571cu,0x0c08571eu,0x0c085720u,0x0c085722u,0x0c085724u,0x0c085726u,0x0c085728u,0x0c08572au,0x0c08572cu,0x0c08572eu,0x0c085730u,0x0c085732u,
0x0c085734u,0x0c085736u,0x0c085738u,0x0c08573au,0x0c08573cu,0x0c08573eu,0x0c085740u,0x0c085742u,0x0c085744u,0x0c085746u,0x0c085748u,0x0c08574au,0x0c08574cu,0x0c08574eu,0x0c085750u,0x0c085752u,
0x0c085754u,0x0c085756u,0x0c085758u,0x0c08575au,0x0c08575cu,0x0c08575eu,0x0c085760u,0x0c085762u,0x0c085764u,0x0c085766u,0x0c085768u,0x0c08576au,0x0c08576cu,0x0c08576eu,0x0c085770u,0x0c085772u,
0x0c085774u,0x0c085776u,0x0c085778u,0x0c08577au,0x0c08577cu,0x0c08577eu,0x0c085780u,0x0c085782u,0x0c085784u,0x0c085786u,0x0c085788u,0x0c08578au,0x0c08578cu,0x0c08578eu,0x0c085790u,0x0c085792u,
0x0c085794u,0x0c085796u,0x0c085798u,0x0c08579au,0x0c08579cu,0x0c08579eu,0x0c0857a0u,0x0c0857a2u,0x0c0857dcu,0x0c0857deu,0x0c0857e0u,0x0c0857e2u,0x0c0857e4u,0x0c0857e6u,0x0c0857e8u,0x0c0857eau,
0x0c0857ecu,0x0c0857eeu,0x0c0857f0u,0x0c0857f2u,0x0c0857f4u,0x0c0857f6u,0x0c0857f8u,0x0c0857fau,0x0c0857fcu,0x0c0857feu,0x0c085800u,0x0c085802u,0x0c085804u,0x0c085806u,0x0c085808u,0x0c08580au,
0x0c08580cu,0x0c08580eu,0x0c085810u,0x0c085812u,0x0c085814u,0x0c085816u,0x0c085818u,0x0c08581au,0x0c08581cu,0x0c08581eu,0x0c085820u,0x0c085822u,0x0c085824u,0x0c085826u,0x0c085828u,0x0c08582au,
0x0c08582cu,0x0c08582eu,0x0c085830u,0x0c085832u,0x0c085834u,0x0c085836u,0x0c085838u,0x0c08583au,0x0c0858e8u,0x0c0858eau,0x0c0858ecu,0x0c0858eeu,0x0c0858f0u,0x0c0858f2u,0x0c0858f4u,0x0c0858f6u,
0x0c0858f8u,0x0c0858fau,0x0c0858fcu,0x0c0858feu,0x0c085900u,0x0c085902u,0x0c085904u,0x0c085906u,0x0c085908u,0x0c08590au,0x0c08590cu,0x0c08590eu,0x0c085910u,0x0c085912u,0x0c085914u,0x0c085916u,
0x0c085918u,0x0c08591au,0x0c08591cu,0x0c08591eu,0x0c085920u,0x0c085922u,0x0c085924u,0x0c085926u,0x0c085928u,0x0c08592au,0x0c08592cu,0x0c08592eu,0x0c085930u,0x0c085932u,0x0c085934u,0x0c085936u,
0x0c085938u,0x0c08593au,0x0c08593cu,0x0c08593eu,0x0c085940u,0x0c085942u,0x0c085944u,0x0c085946u,0x0c085948u,0x0c08594au,0x0c08594cu,0x0c08594eu,0x0c085950u,0x0c085952u,0x0c085954u,0x0c085956u,
0x0c085958u,0x0c08595au,0x0c08595cu,0x0c08595eu,0x0c085960u,0x0c085962u,0x0c085964u,0x0c085966u,0x0c085968u,0x0c08596au,0x0c08596cu,0x0c08596eu,0x0c085970u,0x0c085972u,0x0c085974u,0x0c085976u,
0x0c085978u,0x0c08597au,0x0c08597cu,0x0c08597eu,0x0c085980u,0x0c085982u,0x0c085984u,0x0c085986u,0x0c085988u,0x0c08598au,0x0c08598cu,0x0c08598eu,0x0c085990u,0x0c085992u,0x0c085994u,0x0c085996u,
0x0c085998u,0x0c08599au,0x0c08599cu,0x0c08599eu,0x0c0859a0u,0x0c0859a2u,0x0c0859a4u,0x0c0859a6u,0x0c0859a8u,0x0c0859aau,0x0c0859acu,0x0c0859aeu,0x0c0859b0u,0x0c0859b2u,0x0c0859b4u,0x0c0859b6u,
0x0c0859b8u,0x0c0859bau,0x0c0859bcu,0x0c0859beu,0x0c0859c0u,0x0c0859c2u,0x0c0859c4u,0x0c0859c6u,0x0c0859c8u,0x0c0859cau,0x0c0859ccu,0x0c0859ceu,0x0c0859d0u,0x0c0859d2u,0x0c085a0cu,0x0c085a0eu,
0x0c085a10u,0x0c085a12u,0x0c085a14u,0x0c085a16u,0x0c085a18u,0x0c085a1au,0x0c085a1cu,0x0c085a1eu,0x0c085a20u,0x0c085a22u,0x0c085a24u,0x0c085a26u,0x0c085a28u,0x0c085a2au,0x0c085a2cu,0x0c085a2eu,
0x0c085a30u,0x0c085a32u,0x0c085a34u,0x0c085a36u,0x0c085a38u,0x0c085a3au,0x0c085a3cu,0x0c085a3eu,0x0c085a40u,0x0c085a42u,0x0c085a44u,0x0c085a46u,0x0c085a48u,0x0c085a4au,0x0c085a4cu,0x0c085a4eu,
0x0c085a50u,0x0c085a52u,0x0c085a54u,0x0c085a56u,0x0c085a58u,0x0c085a5au,0x0c085a5cu,0x0c085a5eu,0x0c085a60u,0x0c085a62u,0x0c085a64u,0x0c085a66u,0x0c085a68u,0x0c085a6au,0x0c085a6cu,0x0c085a6eu,
0x0c085a70u,0x0c085a72u,0x0c085a74u,0x0c085a76u,0x0c085a78u,0x0c085a7au,0x0c085a7cu,0x0c085a7eu,0x0c085a80u,0x0c085a82u,0x0c085a84u,0x0c085a86u,0x0c085a88u,0x0c085a8au,0x0c085a8cu,0x0c085a8eu,
0x0c085a90u,0x0c085a92u,0x0c085a94u,0x0c085a96u,0x0c085a98u,0x0c085a9au,0x0c085a9cu,0x0c085a9eu,0x0c085aa0u,0x0c085aa2u,0x0c085aa4u,0x0c085aa6u,0x0c085aa8u,0x0c085aaau,0x0c085aacu,0x0c085aaeu,
0x0c085ab0u,0x0c085ab2u,0x0c085ab4u,0x0c085ab6u,0x0c085ab8u,0x0c085abau,0x0c085abcu,0x0c085abeu,0x0c085ac0u,0x0c085ac2u,0x0c085ac4u,0x0c085ac6u,0x0c085ac8u,0x0c085acau,0x0c085accu,0x0c085aceu,
0x0c085ad0u,0x0c085ad2u,0x0c085ad4u,0x0c085ad6u,0x0c085ad8u,0x0c085adau,0x0c085adcu,0x0c085adeu,0x0c085ae0u,0x0c085ae2u,0x0c085ae4u,0x0c085ae6u,0x0c085ae8u,0x0c085aeau,0x0c085aecu,0x0c085aeeu,
0x0c085af0u,0x0c085af2u,0x0c085af4u,0x0c085af6u,0x0c085af8u,0x0c085afau,0x0c085afcu,0x0c085afeu,0x0c085b00u,0x0c085b02u,0x0c085b04u,0x0c085b06u,0x0c085b08u,0x0c085b0au,0x0c085b0cu,0x0c085b0eu,
0x0c085b10u,0x0c085b12u,0x0c085b14u,0x0c085b16u,0x0c085b18u,0x0c085b1au,0x0c085b1cu,0x0c085b1eu,0x0c085b20u,0x0c085b22u,0x0c085b24u,0x0c085b26u,0x0c085b28u,0x0c085b2au,0x0c085b2cu,0x0c085b2eu,
0x0c085b30u,0x0c085b32u,0x0c085b34u,0x0c085b36u,0x0c085b38u,0x0c085b3au,0x0c085b3cu,0x0c085b3eu,0x0c085b40u,0x0c085b42u,0x0c085b44u,0x0c085b46u,0x0c085b48u,0x0c085b4au,0x0c085b88u,0x0c085b8au,
0x0c085b8cu,0x0c085b8eu,0x0c085b90u,0x0c085b92u,0x0c085b94u,0x0c085b96u,0x0c085b98u,0x0c085b9au,0x0c085b9cu,0x0c085b9eu,0x0c085ba0u,0x0c085ba2u,0x0c085ba4u,0x0c085ba6u,0x0c085ba8u,0x0c085baau,
0x0c085bacu,0x0c085baeu,0x0c085bb0u,0x0c085bb2u,0x0c085bb4u,0x0c085bb6u,0x0c085bb8u,0x0c085bbau,0x0c085bbcu,0x0c085bbeu,0x0c085bc0u,0x0c085bc2u,0x0c085bc4u,0x0c0a7442u,0x0c0a7444u,0x0c0a7446u,
0x0c0a7448u,0x0c0a744au,0x0c0a744cu,0x0c0a744eu,0x0c0abcdcu,0x0c0abcdeu,0x0c0abce0u,0x0c0abce2u,0x0c0abce4u,0x0c0abce6u,0x0c0abce8u,0x0c0abceau,0x0c0abd2cu,0x0c0abd2eu,0x0c0abd30u,0x0c0abd32u,
0x0c0abd34u,0x0c0abd36u,0x0c0abd38u,0x0c0abd3au,0x0c0abd3cu,0x0c0abd3eu,0x0c0abd40u,0x0c0abd42u,0x0c0abd44u,0x0c0abd46u,0x0c0abd48u,0x0c0abd4au,0x0c0abd4cu,0x0c0abd4eu,0x0c0abd50u,0x0c0abd52u,
0x0c0abd54u,0x0c0abd56u,0x0c0abd58u,0x0c0abd5au,0x0c0abd5cu,0x0c0abd5eu,0x0c0abd60u,0x0c0abd62u,0x0c0abd64u,0x0c0abd66u,0x0c0abd68u,0x0c0abd6au,0x0c0abd6cu,0x0c0abd6eu,0x0c0abd70u,0x0c0abd72u,
0x0c0abd74u,0x0c0abd76u,0x0c0abd78u,0x0c0abd7au,0x0c0abd7cu,0x0c0abd7eu,0x0c0abd80u,0x0c0abd82u,0x0c0abd84u,0x0c0abd86u,0x0c0abd88u,0x0c0abd8au,0x0c0abd8cu,0x0c0abd8eu,0x0c0abd90u,0x0c0abd92u,
0x0c0abd94u,0x0c0abd96u,0x0c0abd98u,0x0c0abd9au,0x0c0abd9cu,0x0c0abd9eu,0x0c0abda0u,0x0c0abda2u,0x0c0abda4u,0x0c0abda6u,0x0c0abda8u,0x0c0abdaau,0x0c0abdacu,0x0c0abdaeu,0x0c0abdb0u,0x0c0abdb2u,
0x0c0abdb4u,0x0c0abdb6u,0x0c0abdb8u,0x0c0abdbau,0x0c0abdbcu,0x0c0abdbeu,0x0c0abdc0u,0x0c0abdc2u,0x0c0ca0c6u,0x0c0ca0c8u,0x0c0ca0cau,0x0c0ca0ccu,0x0c0ca0ceu,0x0c0ca0d0u,0x0c0ca0d2u,0x0c0ca0d4u,
0x0c0ca0d6u,0x0c0ca0d8u,0x0c0ca0dau,0x0c0ca0dcu,0x0c0ca0deu,0x0c0ca0e0u,0x0c0ca0e2u,0x0c0ca0e4u,0x0c0ca0e6u,0x0c0ca0e8u,0x0c0ca0eau,0x0c0ca0ecu,0x0c0ca0eeu,0x0c0ca0f0u,0x0c0ca0f2u,0x0c0ca0f4u,
0x0c0ca0f6u,0x0c0ca0f8u,0x0c0ca0fau,0x0c0ca0fcu,0x0c0ca0feu,0x0c0ca100u,0x0c0ca102u,0x0c0ca104u,0x0c0ca106u,0x0c0ca108u,0x0c0ca10au,0x0c0ca10cu,0x0c0ca10eu,0x0c0ca110u,0x0c0ca112u,0x0c0ca114u,
0x0c0ca116u,0x0c0ca118u,0x0c0ca11au,0x0c0ca11cu,0x0c0ca11eu,0x0c0ca120u,0x0c0ca122u,0x0c0ca124u,0x0c0ca126u,0x0c0ca128u,0x0c0ca12au,0x0c0ca12cu,0x0c0ca12eu,0x0c0ca130u,0x0c0ca132u,0x0c0ca134u,
0x0c0ca136u,0x0c0ca138u,0x0c0ca13au,0x0c0ca13cu,0x0c0ca13eu,0x0c0ca140u,0x0c0ca142u,0x0c0ca144u,0x0c0ca146u,0x0c0ca148u,0x0c0ca14au,0x0c0ca14cu,0x0c0ca14eu,0x0c0ca150u,0x0c0ca152u,0x0c0ca154u,
0x0c0ca156u,0x0c0ca158u,0x0c0ca15au,0x0c0ca15cu,0x0c0ca15eu,0x0c0ca326u,0x0c0ca328u,
};
int vf3_advance_worker_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
