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
int vf3_device_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08db70u: goto P_0c08db70;
case 0x0c08db72u: goto P_0c08db72;
case 0x0c08db74u: goto P_0c08db74;
case 0x0c08db76u: goto P_0c08db76;
case 0x0c08db78u: goto P_0c08db78;
case 0x0c08db7au: goto P_0c08db7a;
case 0x0c08db7cu: goto P_0c08db7c;
case 0x0c08db7eu: goto P_0c08db7e;
case 0x0c08db80u: goto P_0c08db80;
case 0x0c08db82u: goto P_0c08db82;
case 0x0c08db84u: goto P_0c08db84;
case 0x0c08db86u: goto P_0c08db86;
case 0x0c08db88u: goto P_0c08db88;
case 0x0c08db8au: goto P_0c08db8a;
case 0x0c08db8cu: goto P_0c08db8c;
case 0x0c08db8eu: goto P_0c08db8e;
case 0x0c08db90u: goto P_0c08db90;
case 0x0c08db92u: goto P_0c08db92;
case 0x0c08db94u: goto P_0c08db94;
case 0x0c08db96u: goto P_0c08db96;
case 0x0c08db98u: goto P_0c08db98;
case 0x0c08db9au: goto P_0c08db9a;
case 0x0c08db9cu: goto P_0c08db9c;
case 0x0c08db9eu: goto P_0c08db9e;
case 0x0c08dba0u: goto P_0c08dba0;
case 0x0c08dba2u: goto P_0c08dba2;
case 0x0c08dba4u: goto P_0c08dba4;
case 0x0c08dba6u: goto P_0c08dba6;
case 0x0c08dba8u: goto P_0c08dba8;
case 0x0c08dbaau: goto P_0c08dbaa;
case 0x0c08dbacu: goto P_0c08dbac;
case 0x0c08dbaeu: goto P_0c08dbae;
case 0x0c08dbb0u: goto P_0c08dbb0;
case 0x0c08dbb2u: goto P_0c08dbb2;
case 0x0c08dbb4u: goto P_0c08dbb4;
case 0x0c08dbb6u: goto P_0c08dbb6;
case 0x0c08dbb8u: goto P_0c08dbb8;
case 0x0c08dbbau: goto P_0c08dbba;
case 0x0c08dbbcu: goto P_0c08dbbc;
case 0x0c08dbbeu: goto P_0c08dbbe;
case 0x0c08dbc0u: goto P_0c08dbc0;
case 0x0c08dbc2u: goto P_0c08dbc2;
case 0x0c08dbc4u: goto P_0c08dbc4;
case 0x0c08dbc6u: goto P_0c08dbc6;
case 0x0c08dbc8u: goto P_0c08dbc8;
case 0x0c08dbcau: goto P_0c08dbca;
case 0x0c08dbccu: goto P_0c08dbcc;
case 0x0c08dbceu: goto P_0c08dbce;
case 0x0c08dbd0u: goto P_0c08dbd0;
case 0x0c08dbd2u: goto P_0c08dbd2;
case 0x0c08dbd4u: goto P_0c08dbd4;
case 0x0c08dbd6u: goto P_0c08dbd6;
case 0x0c08dbd8u: goto P_0c08dbd8;
case 0x0c08dbdau: goto P_0c08dbda;
case 0x0c08dbdcu: goto P_0c08dbdc;
case 0x0c08dbdeu: goto P_0c08dbde;
case 0x0c08dbe0u: goto P_0c08dbe0;
case 0x0c08dbe2u: goto P_0c08dbe2;
case 0x0c08dee6u: goto P_0c08dee6;
case 0x0c08dee8u: goto P_0c08dee8;
case 0x0c08deeau: goto P_0c08deea;
case 0x0c08deecu: goto P_0c08deec;
case 0x0c08deeeu: goto P_0c08deee;
case 0x0c08def0u: goto P_0c08def0;
case 0x0c08def2u: goto P_0c08def2;
case 0x0c08def4u: goto P_0c08def4;
case 0x0c08def6u: goto P_0c08def6;
case 0x0c08def8u: goto P_0c08def8;
case 0x0c08defau: goto P_0c08defa;
case 0x0c08defcu: goto P_0c08defc;
case 0x0c08defeu: goto P_0c08defe;
case 0x0c08df00u: goto P_0c08df00;
case 0x0c08df02u: goto P_0c08df02;
case 0x0c08df04u: goto P_0c08df04;
case 0x0c08df06u: goto P_0c08df06;
case 0x0c08df08u: goto P_0c08df08;
case 0x0c08df0au: goto P_0c08df0a;
case 0x0c08df0cu: goto P_0c08df0c;
case 0x0c08df0eu: goto P_0c08df0e;
case 0x0c08df10u: goto P_0c08df10;
case 0x0c08df12u: goto P_0c08df12;
case 0x0c08df14u: goto P_0c08df14;
case 0x0c08df16u: goto P_0c08df16;
case 0x0c08df18u: goto P_0c08df18;
case 0x0c08df1au: goto P_0c08df1a;
case 0x0c08df1cu: goto P_0c08df1c;
case 0x0c08df1eu: goto P_0c08df1e;
case 0x0c08df20u: goto P_0c08df20;
case 0x0c08df22u: goto P_0c08df22;
case 0x0c08df24u: goto P_0c08df24;
case 0x0c08df26u: goto P_0c08df26;
case 0x0c08df28u: goto P_0c08df28;
case 0x0c08df2au: goto P_0c08df2a;
case 0x0c08df2cu: goto P_0c08df2c;
case 0x0c08df2eu: goto P_0c08df2e;
case 0x0c08df30u: goto P_0c08df30;
case 0x0c08df32u: goto P_0c08df32;
case 0x0c08df34u: goto P_0c08df34;
case 0x0c08df36u: goto P_0c08df36;
case 0x0c08df6cu: goto P_0c08df6c;
case 0x0c08df6eu: goto P_0c08df6e;
case 0x0c08df70u: goto P_0c08df70;
case 0x0c08df72u: goto P_0c08df72;
case 0x0c08df74u: goto P_0c08df74;
case 0x0c08df76u: goto P_0c08df76;
case 0x0c08df78u: goto P_0c08df78;
case 0x0c08df7au: goto P_0c08df7a;
case 0x0c08df7cu: goto P_0c08df7c;
case 0x0c08df7eu: goto P_0c08df7e;
case 0x0c08df80u: goto P_0c08df80;
case 0x0c08df82u: goto P_0c08df82;
case 0x0c08df84u: goto P_0c08df84;
case 0x0c08df86u: goto P_0c08df86;
case 0x0c08df88u: goto P_0c08df88;
case 0x0c08df8au: goto P_0c08df8a;
case 0x0c08df8cu: goto P_0c08df8c;
case 0x0c08df8eu: goto P_0c08df8e;
case 0x0c08df90u: goto P_0c08df90;
case 0x0c08df92u: goto P_0c08df92;
case 0x0c08df94u: goto P_0c08df94;
case 0x0c08df96u: goto P_0c08df96;
case 0x0c08df98u: goto P_0c08df98;
case 0x0c08df9au: goto P_0c08df9a;
case 0x0c08df9cu: goto P_0c08df9c;
case 0x0c08df9eu: goto P_0c08df9e;
case 0x0c08dfa0u: goto P_0c08dfa0;
case 0x0c08dfa2u: goto P_0c08dfa2;
case 0x0c08dfa4u: goto P_0c08dfa4;
case 0x0c08dfa6u: goto P_0c08dfa6;
case 0x0c08dfa8u: goto P_0c08dfa8;
case 0x0c08dfaau: goto P_0c08dfaa;
case 0x0c08dfacu: goto P_0c08dfac;
case 0x0c08dfaeu: goto P_0c08dfae;
case 0x0c08dfb0u: goto P_0c08dfb0;
case 0x0c08dfb2u: goto P_0c08dfb2;
case 0x0c08dfb4u: goto P_0c08dfb4;
case 0x0c08dfb6u: goto P_0c08dfb6;
case 0x0c08dfb8u: goto P_0c08dfb8;
case 0x0c08dfbau: goto P_0c08dfba;
case 0x0c08dfbcu: goto P_0c08dfbc;
case 0x0c08dfbeu: goto P_0c08dfbe;
case 0x0c08dfc0u: goto P_0c08dfc0;
case 0x0c08dfc2u: goto P_0c08dfc2;
case 0x0c08dfc4u: goto P_0c08dfc4;
case 0x0c08dfc6u: goto P_0c08dfc6;
case 0x0c08dfc8u: goto P_0c08dfc8;
case 0x0c08dfcau: goto P_0c08dfca;
case 0x0c08dfccu: goto P_0c08dfcc;
case 0x0c08dfceu: goto P_0c08dfce;
case 0x0c08dfd0u: goto P_0c08dfd0;
case 0x0c08dfd2u: goto P_0c08dfd2;
case 0x0c08dfd4u: goto P_0c08dfd4;
case 0x0c08dfd6u: goto P_0c08dfd6;
case 0x0c08dfd8u: goto P_0c08dfd8;
case 0x0c08dfdau: goto P_0c08dfda;
case 0x0c08dfdcu: goto P_0c08dfdc;
case 0x0c08dfdeu: goto P_0c08dfde;
case 0x0c08dfe0u: goto P_0c08dfe0;
case 0x0c08dfe2u: goto P_0c08dfe2;
case 0x0c08dfe4u: goto P_0c08dfe4;
case 0x0c08dfe6u: goto P_0c08dfe6;
case 0x0c08dfe8u: goto P_0c08dfe8;
case 0x0c08dfeau: goto P_0c08dfea;
case 0x0c08dfecu: goto P_0c08dfec;
case 0x0c08dfeeu: goto P_0c08dfee;
case 0x0c08dff0u: goto P_0c08dff0;
case 0x0c08dff2u: goto P_0c08dff2;
case 0x0c091c3au: goto P_0c091c3a;
case 0x0c091c3cu: goto P_0c091c3c;
case 0x0c091c3eu: goto P_0c091c3e;
case 0x0c091c40u: goto P_0c091c40;
case 0x0c091c42u: goto P_0c091c42;
case 0x0c091c44u: goto P_0c091c44;
case 0x0c091c46u: goto P_0c091c46;
case 0x0c091c48u: goto P_0c091c48;
case 0x0c091c4au: goto P_0c091c4a;
case 0x0c091c4cu: goto P_0c091c4c;
case 0x0c091c4eu: goto P_0c091c4e;
case 0x0c091c50u: goto P_0c091c50;
case 0x0c091c52u: goto P_0c091c52;
case 0x0c091c54u: goto P_0c091c54;
case 0x0c091c56u: goto P_0c091c56;
case 0x0c091c58u: goto P_0c091c58;
case 0x0c091c5au: goto P_0c091c5a;
case 0x0c091c5cu: goto P_0c091c5c;
case 0x0c091c5eu: goto P_0c091c5e;
case 0x0c091c60u: goto P_0c091c60;
case 0x0c091c62u: goto P_0c091c62;
case 0x0c091c64u: goto P_0c091c64;
case 0x0c091c66u: goto P_0c091c66;
case 0x0c091c68u: goto P_0c091c68;
case 0x0c091c6au: goto P_0c091c6a;
case 0x0c091c6cu: goto P_0c091c6c;
case 0x0c091c6eu: goto P_0c091c6e;
case 0x0c091c70u: goto P_0c091c70;
case 0x0c091c72u: goto P_0c091c72;
case 0x0c091c74u: goto P_0c091c74;
case 0x0c091c76u: goto P_0c091c76;
case 0x0c091c78u: goto P_0c091c78;
case 0x0c091c7au: goto P_0c091c7a;
case 0x0c091c7cu: goto P_0c091c7c;
case 0x0c091c7eu: goto P_0c091c7e;
case 0x0c091c80u: goto P_0c091c80;
case 0x0c091c82u: goto P_0c091c82;
case 0x0c091c84u: goto P_0c091c84;
case 0x0c091c86u: goto P_0c091c86;
case 0x0c091c88u: goto P_0c091c88;
case 0x0c091c8au: goto P_0c091c8a;
case 0x0c091c8cu: goto P_0c091c8c;
case 0x0c091c8eu: goto P_0c091c8e;
case 0x0c091c90u: goto P_0c091c90;
case 0x0c091c92u: goto P_0c091c92;
case 0x0c091c94u: goto P_0c091c94;
case 0x0c091c96u: goto P_0c091c96;
case 0x0c091c98u: goto P_0c091c98;
case 0x0c091c9au: goto P_0c091c9a;
case 0x0c091c9cu: goto P_0c091c9c;
case 0x0c091c9eu: goto P_0c091c9e;
case 0x0c091ca0u: goto P_0c091ca0;
case 0x0c091ca2u: goto P_0c091ca2;
case 0x0c091ca4u: goto P_0c091ca4;
case 0x0c091ca6u: goto P_0c091ca6;
case 0x0c091ca8u: goto P_0c091ca8;
case 0x0c091caau: goto P_0c091caa;
case 0x0c091cacu: goto P_0c091cac;
case 0x0c091caeu: goto P_0c091cae;
case 0x0c091cb0u: goto P_0c091cb0;
case 0x0c091cb2u: goto P_0c091cb2;
case 0x0c091cb4u: goto P_0c091cb4;
case 0x0c091cb6u: goto P_0c091cb6;
case 0x0c091cb8u: goto P_0c091cb8;
case 0x0c091cbau: goto P_0c091cba;
case 0x0c091cbcu: goto P_0c091cbc;
case 0x0c091cbeu: goto P_0c091cbe;
case 0x0c091cc0u: goto P_0c091cc0;
case 0x0c091cc2u: goto P_0c091cc2;
case 0x0c091cc4u: goto P_0c091cc4;
case 0x0c091cc6u: goto P_0c091cc6;
case 0x0c091cc8u: goto P_0c091cc8;
case 0x0c091ccau: goto P_0c091cca;
case 0x0c091cccu: goto P_0c091ccc;
case 0x0c091cceu: goto P_0c091cce;
case 0x0c091cd0u: goto P_0c091cd0;
case 0x0c091cd2u: goto P_0c091cd2;
case 0x0c091cd4u: goto P_0c091cd4;
case 0x0c091cd6u: goto P_0c091cd6;
case 0x0c091cd8u: goto P_0c091cd8;
case 0x0c091cdau: goto P_0c091cda;
case 0x0c091cdcu: goto P_0c091cdc;
case 0x0c091cdeu: goto P_0c091cde;
case 0x0c091ce0u: goto P_0c091ce0;
case 0x0c091ce2u: goto P_0c091ce2;
case 0x0c091ce4u: goto P_0c091ce4;
case 0x0c091ce6u: goto P_0c091ce6;
case 0x0c091ce8u: goto P_0c091ce8;
case 0x0c091ceau: goto P_0c091cea;
case 0x0c091cecu: goto P_0c091cec;
case 0x0c091ceeu: goto P_0c091cee;
case 0x0c091cf0u: goto P_0c091cf0;
case 0x0c091cf2u: goto P_0c091cf2;
case 0x0c091cf4u: goto P_0c091cf4;
case 0x0c091cf6u: goto P_0c091cf6;
case 0x0c091cf8u: goto P_0c091cf8;
case 0x0c091cfau: goto P_0c091cfa;
case 0x0c091cfcu: goto P_0c091cfc;
case 0x0c091cfeu: goto P_0c091cfe;
case 0x0c091d00u: goto P_0c091d00;
case 0x0c091d02u: goto P_0c091d02;
case 0x0c091d04u: goto P_0c091d04;
case 0x0c091d06u: goto P_0c091d06;
case 0x0c091d08u: goto P_0c091d08;
case 0x0c091d0au: goto P_0c091d0a;
case 0x0c091d0cu: goto P_0c091d0c;
case 0x0c091d0eu: goto P_0c091d0e;
case 0x0c091d10u: goto P_0c091d10;
case 0x0c091d12u: goto P_0c091d12;
case 0x0c091d14u: goto P_0c091d14;
case 0x0c091d16u: goto P_0c091d16;
case 0x0c091d18u: goto P_0c091d18;
case 0x0c091d1au: goto P_0c091d1a;
case 0x0c091d1cu: goto P_0c091d1c;
case 0x0c091d1eu: goto P_0c091d1e;
case 0x0c091d20u: goto P_0c091d20;
case 0x0c091d22u: goto P_0c091d22;
case 0x0c091d24u: goto P_0c091d24;
case 0x0c091d26u: goto P_0c091d26;
case 0x0c091d28u: goto P_0c091d28;
case 0x0c091d2au: goto P_0c091d2a;
case 0x0c091d2cu: goto P_0c091d2c;
case 0x0c091d2eu: goto P_0c091d2e;
case 0x0c091d30u: goto P_0c091d30;
case 0x0c091d32u: goto P_0c091d32;
case 0x0c091d34u: goto P_0c091d34;
case 0x0c091d36u: goto P_0c091d36;
case 0x0c091d38u: goto P_0c091d38;
case 0x0c091d3au: goto P_0c091d3a;
case 0x0c091d3cu: goto P_0c091d3c;
case 0x0c091d3eu: goto P_0c091d3e;
case 0x0c091d40u: goto P_0c091d40;
case 0x0c091d42u: goto P_0c091d42;
case 0x0c091d44u: goto P_0c091d44;
case 0x0c091d46u: goto P_0c091d46;
case 0x0c091d48u: goto P_0c091d48;
case 0x0c091d4au: goto P_0c091d4a;
case 0x0c091d4cu: goto P_0c091d4c;
case 0x0c091d4eu: goto P_0c091d4e;
case 0x0c091d50u: goto P_0c091d50;
case 0x0c091d52u: goto P_0c091d52;
case 0x0c091d54u: goto P_0c091d54;
case 0x0c091d56u: goto P_0c091d56;
case 0x0c091d58u: goto P_0c091d58;
case 0x0c091d5au: goto P_0c091d5a;
case 0x0c091d5cu: goto P_0c091d5c;
case 0x0c091d5eu: goto P_0c091d5e;
case 0x0c091d60u: goto P_0c091d60;
case 0x0c091d62u: goto P_0c091d62;
case 0x0c091d64u: goto P_0c091d64;
case 0x0c091d66u: goto P_0c091d66;
case 0x0c091d68u: goto P_0c091d68;
case 0x0c091d6au: goto P_0c091d6a;
case 0x0c091d98u: goto P_0c091d98;
case 0x0c091d9au: goto P_0c091d9a;
case 0x0c091d9cu: goto P_0c091d9c;
case 0x0c091d9eu: goto P_0c091d9e;
case 0x0c091da0u: goto P_0c091da0;
case 0x0c091da2u: goto P_0c091da2;
case 0x0c091da4u: goto P_0c091da4;
case 0x0c091da6u: goto P_0c091da6;
case 0x0c091da8u: goto P_0c091da8;
case 0x0c091daau: goto P_0c091daa;
case 0x0c091dacu: goto P_0c091dac;
case 0x0c091daeu: goto P_0c091dae;
case 0x0c091db0u: goto P_0c091db0;
case 0x0c091db2u: goto P_0c091db2;
case 0x0c091db4u: goto P_0c091db4;
case 0x0c091db6u: goto P_0c091db6;
case 0x0c091db8u: goto P_0c091db8;
case 0x0c091dbau: goto P_0c091dba;
case 0x0c091dbcu: goto P_0c091dbc;
case 0x0c0940c8u: goto P_0c0940c8;
case 0x0c0940cau: goto P_0c0940ca;
case 0x0c0940ccu: goto P_0c0940cc;
case 0x0c0940ceu: goto P_0c0940ce;
case 0x0c0940d0u: goto P_0c0940d0;
case 0x0c0940d2u: goto P_0c0940d2;
case 0x0c0940d4u: goto P_0c0940d4;
case 0x0c0940d6u: goto P_0c0940d6;
case 0x0c0940d8u: goto P_0c0940d8;
case 0x0c0940dau: goto P_0c0940da;
case 0x0c0940dcu: goto P_0c0940dc;
case 0x0c0940deu: goto P_0c0940de;
case 0x0c0940e0u: goto P_0c0940e0;
case 0x0c0940e2u: goto P_0c0940e2;
case 0x0c0940e4u: goto P_0c0940e4;
case 0x0c0940e6u: goto P_0c0940e6;
case 0x0c0940e8u: goto P_0c0940e8;
case 0x0c0940eau: goto P_0c0940ea;
case 0x0c0940ecu: goto P_0c0940ec;
case 0x0c0940eeu: goto P_0c0940ee;
case 0x0c0940f0u: goto P_0c0940f0;
case 0x0c0940f2u: goto P_0c0940f2;
case 0x0c0940f4u: goto P_0c0940f4;
case 0x0c0940f6u: goto P_0c0940f6;
case 0x0c0940f8u: goto P_0c0940f8;
case 0x0c0940fau: goto P_0c0940fa;
case 0x0c0940fcu: goto P_0c0940fc;
case 0x0c0940feu: goto P_0c0940fe;
case 0x0c094100u: goto P_0c094100;
case 0x0c094102u: goto P_0c094102;
case 0x0c094104u: goto P_0c094104;
case 0x0c094106u: goto P_0c094106;
case 0x0c094108u: goto P_0c094108;
case 0x0c09410au: goto P_0c09410a;
case 0x0c09410cu: goto P_0c09410c;
case 0x0c09410eu: goto P_0c09410e;
case 0x0c094110u: goto P_0c094110;
case 0x0c094112u: goto P_0c094112;
case 0x0c094114u: goto P_0c094114;
case 0x0c094116u: goto P_0c094116;
case 0x0c094118u: goto P_0c094118;
case 0x0c09411au: goto P_0c09411a;
case 0x0c09411cu: goto P_0c09411c;
case 0x0c09411eu: goto P_0c09411e;
case 0x0c094120u: goto P_0c094120;
case 0x0c094122u: goto P_0c094122;
case 0x0c094124u: goto P_0c094124;
case 0x0c094126u: goto P_0c094126;
case 0x0c094128u: goto P_0c094128;
case 0x0c09412au: goto P_0c09412a;
case 0x0c09412cu: goto P_0c09412c;
case 0x0c09412eu: goto P_0c09412e;
case 0x0c094130u: goto P_0c094130;
case 0x0c094132u: goto P_0c094132;
case 0x0c094134u: goto P_0c094134;
case 0x0c094136u: goto P_0c094136;
case 0x0c094138u: goto P_0c094138;
case 0x0c09413au: goto P_0c09413a;
case 0x0c09413cu: goto P_0c09413c;
case 0x0c09413eu: goto P_0c09413e;
case 0x0c094140u: goto P_0c094140;
case 0x0c094142u: goto P_0c094142;
case 0x0c094144u: goto P_0c094144;
case 0x0c094146u: goto P_0c094146;
case 0x0c094148u: goto P_0c094148;
case 0x0c09414au: goto P_0c09414a;
case 0x0c09414cu: goto P_0c09414c;
case 0x0c09414eu: goto P_0c09414e;
case 0x0c094150u: goto P_0c094150;
case 0x0c094152u: goto P_0c094152;
case 0x0c094154u: goto P_0c094154;
case 0x0c094156u: goto P_0c094156;
case 0x0c094158u: goto P_0c094158;
case 0x0c09415au: goto P_0c09415a;
case 0x0c09415cu: goto P_0c09415c;
case 0x0c09415eu: goto P_0c09415e;
case 0x0c094160u: goto P_0c094160;
case 0x0c094162u: goto P_0c094162;
case 0x0c094164u: goto P_0c094164;
case 0x0c094166u: goto P_0c094166;
case 0x0c094168u: goto P_0c094168;
case 0x0c09416au: goto P_0c09416a;
case 0x0c09416cu: goto P_0c09416c;
case 0x0c09416eu: goto P_0c09416e;
case 0x0c094170u: goto P_0c094170;
case 0x0c094172u: goto P_0c094172;
case 0x0c094174u: goto P_0c094174;
case 0x0c094176u: goto P_0c094176;
case 0x0c094178u: goto P_0c094178;
case 0x0c09417au: goto P_0c09417a;
case 0x0c09417cu: goto P_0c09417c;
case 0x0c09417eu: goto P_0c09417e;
case 0x0c094180u: goto P_0c094180;
case 0x0c094182u: goto P_0c094182;
case 0x0c094184u: goto P_0c094184;
case 0x0c094186u: goto P_0c094186;
case 0x0c094188u: goto P_0c094188;
case 0x0c09418au: goto P_0c09418a;
case 0x0c09418cu: goto P_0c09418c;
case 0x0c09418eu: goto P_0c09418e;
case 0x0c094190u: goto P_0c094190;
case 0x0c094192u: goto P_0c094192;
case 0x0c094194u: goto P_0c094194;
case 0x0c094196u: goto P_0c094196;
case 0x0c094198u: goto P_0c094198;
case 0x0c09419au: goto P_0c09419a;
case 0x0c09419cu: goto P_0c09419c;
case 0x0c09419eu: goto P_0c09419e;
case 0x0c0941a0u: goto P_0c0941a0;
case 0x0c0941a2u: goto P_0c0941a2;
case 0x0c0941a4u: goto P_0c0941a4;
case 0x0c0941a6u: goto P_0c0941a6;
case 0x0c0941a8u: goto P_0c0941a8;
case 0x0c0941aau: goto P_0c0941aa;
case 0x0c0941acu: goto P_0c0941ac;
case 0x0c0941aeu: goto P_0c0941ae;
case 0x0c0941b0u: goto P_0c0941b0;
case 0x0c0941b2u: goto P_0c0941b2;
case 0x0c0941b4u: goto P_0c0941b4;
case 0x0c0941b6u: goto P_0c0941b6;
case 0x0c0941b8u: goto P_0c0941b8;
case 0x0c0941bau: goto P_0c0941ba;
case 0x0c0941bcu: goto P_0c0941bc;
case 0x0c0941beu: goto P_0c0941be;
case 0x0c0941c0u: goto P_0c0941c0;
case 0x0c0941c2u: goto P_0c0941c2;
case 0x0c0941c4u: goto P_0c0941c4;
case 0x0c0941c6u: goto P_0c0941c6;
case 0x0c0941c8u: goto P_0c0941c8;
case 0x0c0941cau: goto P_0c0941ca;
case 0x0c0941f8u: goto P_0c0941f8;
case 0x0c0941fau: goto P_0c0941fa;
case 0x0c0941fcu: goto P_0c0941fc;
case 0x0c0941feu: goto P_0c0941fe;
case 0x0c094200u: goto P_0c094200;
case 0x0c094202u: goto P_0c094202;
case 0x0c094204u: goto P_0c094204;
case 0x0c094206u: goto P_0c094206;
case 0x0c094208u: goto P_0c094208;
case 0x0c09420au: goto P_0c09420a;
case 0x0c09420cu: goto P_0c09420c;
case 0x0c09420eu: goto P_0c09420e;
case 0x0c094210u: goto P_0c094210;
case 0x0c094212u: goto P_0c094212;
case 0x0c094214u: goto P_0c094214;
case 0x0c094216u: goto P_0c094216;
case 0x0c094218u: goto P_0c094218;
case 0x0c09421au: goto P_0c09421a;
case 0x0c09421cu: goto P_0c09421c;
case 0x0c09421eu: goto P_0c09421e;
case 0x0c094220u: goto P_0c094220;
case 0x0c094222u: goto P_0c094222;
case 0x0c094224u: goto P_0c094224;
case 0x0c094226u: goto P_0c094226;
case 0x0c094228u: goto P_0c094228;
case 0x0c09422au: goto P_0c09422a;
case 0x0c09422cu: goto P_0c09422c;
case 0x0c09422eu: goto P_0c09422e;
case 0x0c094230u: goto P_0c094230;
case 0x0c094232u: goto P_0c094232;
case 0x0c094234u: goto P_0c094234;
case 0x0c094236u: goto P_0c094236;
case 0x0c094238u: goto P_0c094238;
case 0x0c09423au: goto P_0c09423a;
case 0x0c09423cu: goto P_0c09423c;
case 0x0c09423eu: goto P_0c09423e;
case 0x0c094240u: goto P_0c094240;
case 0x0c094242u: goto P_0c094242;
case 0x0c094244u: goto P_0c094244;
case 0x0c094246u: goto P_0c094246;
case 0x0c094248u: goto P_0c094248;
case 0x0c09424au: goto P_0c09424a;
case 0x0c09424cu: goto P_0c09424c;
case 0x0c09424eu: goto P_0c09424e;
case 0x0c094250u: goto P_0c094250;
case 0x0c094252u: goto P_0c094252;
case 0x0c094254u: goto P_0c094254;
case 0x0c094256u: goto P_0c094256;
case 0x0c094258u: goto P_0c094258;
case 0x0c09425au: goto P_0c09425a;
case 0x0c09425cu: goto P_0c09425c;
case 0x0c09425eu: goto P_0c09425e;
case 0x0c094260u: goto P_0c094260;
case 0x0c094262u: goto P_0c094262;
case 0x0c094264u: goto P_0c094264;
case 0x0c094266u: goto P_0c094266;
case 0x0c094268u: goto P_0c094268;
case 0x0c09426au: goto P_0c09426a;
case 0x0c09426cu: goto P_0c09426c;
case 0x0c09426eu: goto P_0c09426e;
case 0x0c094270u: goto P_0c094270;
case 0x0c094272u: goto P_0c094272;
case 0x0c094274u: goto P_0c094274;
case 0x0c094276u: goto P_0c094276;
case 0x0c094278u: goto P_0c094278;
case 0x0c09427au: goto P_0c09427a;
case 0x0c09427cu: goto P_0c09427c;
case 0x0c09427eu: goto P_0c09427e;
case 0x0c094280u: goto P_0c094280;
case 0x0c094282u: goto P_0c094282;
case 0x0c094284u: goto P_0c094284;
case 0x0c094286u: goto P_0c094286;
case 0x0c094288u: goto P_0c094288;
case 0x0c09428au: goto P_0c09428a;
case 0x0c09428cu: goto P_0c09428c;
case 0x0c09428eu: goto P_0c09428e;
case 0x0c094290u: goto P_0c094290;
case 0x0c094292u: goto P_0c094292;
case 0x0c094294u: goto P_0c094294;
case 0x0c094296u: goto P_0c094296;
case 0x0c094298u: goto P_0c094298;
case 0x0c09429au: goto P_0c09429a;
case 0x0c09429cu: goto P_0c09429c;
case 0x0c09429eu: goto P_0c09429e;
case 0x0c0942a0u: goto P_0c0942a0;
case 0x0c0942a2u: goto P_0c0942a2;
case 0x0c0942a4u: goto P_0c0942a4;
case 0x0c0942a6u: goto P_0c0942a6;
case 0x0c0942a8u: goto P_0c0942a8;
case 0x0c0942aau: goto P_0c0942aa;
case 0x0c0942acu: goto P_0c0942ac;
case 0x0c0942aeu: goto P_0c0942ae;
case 0x0c0942b0u: goto P_0c0942b0;
case 0x0c0942b2u: goto P_0c0942b2;
case 0x0c0942b4u: goto P_0c0942b4;
case 0x0c0942b6u: goto P_0c0942b6;
case 0x0c0942b8u: goto P_0c0942b8;
case 0x0c0942bau: goto P_0c0942ba;
case 0x0c0942bcu: goto P_0c0942bc;
case 0x0c0942beu: goto P_0c0942be;
case 0x0c0942c0u: goto P_0c0942c0;
case 0x0c0942c2u: goto P_0c0942c2;
case 0x0c0942c4u: goto P_0c0942c4;
case 0x0c0942c6u: goto P_0c0942c6;
case 0x0c0942c8u: goto P_0c0942c8;
case 0x0c0942cau: goto P_0c0942ca;
case 0x0c0942ccu: goto P_0c0942cc;
case 0x0c0942ceu: goto P_0c0942ce;
case 0x0c0942d0u: goto P_0c0942d0;
case 0x0c0942fcu: goto P_0c0942fc;
case 0x0c0942feu: goto P_0c0942fe;
case 0x0c094300u: goto P_0c094300;
case 0x0c094302u: goto P_0c094302;
case 0x0c094304u: goto P_0c094304;
case 0x0c094306u: goto P_0c094306;
case 0x0c094308u: goto P_0c094308;
case 0x0c09430au: goto P_0c09430a;
case 0x0c09430cu: goto P_0c09430c;
case 0x0c09430eu: goto P_0c09430e;
case 0x0c094310u: goto P_0c094310;
case 0x0c094312u: goto P_0c094312;
case 0x0c094314u: goto P_0c094314;
case 0x0c094316u: goto P_0c094316;
case 0x0c094318u: goto P_0c094318;
case 0x0c09431au: goto P_0c09431a;
case 0x0c09431cu: goto P_0c09431c;
case 0x0c09431eu: goto P_0c09431e;
case 0x0c094320u: goto P_0c094320;
case 0x0c094322u: goto P_0c094322;
case 0x0c094324u: goto P_0c094324;
case 0x0c094326u: goto P_0c094326;
case 0x0c094328u: goto P_0c094328;
case 0x0c09432au: goto P_0c09432a;
case 0x0c09432cu: goto P_0c09432c;
case 0x0c09432eu: goto P_0c09432e;
case 0x0c094330u: goto P_0c094330;
case 0x0c094332u: goto P_0c094332;
case 0x0c094334u: goto P_0c094334;
case 0x0c094336u: goto P_0c094336;
case 0x0c094338u: goto P_0c094338;
case 0x0c09433au: goto P_0c09433a;
case 0x0c09433cu: goto P_0c09433c;
case 0x0c09433eu: goto P_0c09433e;
case 0x0c094340u: goto P_0c094340;
case 0x0c094342u: goto P_0c094342;
case 0x0c094344u: goto P_0c094344;
case 0x0c094346u: goto P_0c094346;
case 0x0c094348u: goto P_0c094348;
case 0x0c09434au: goto P_0c09434a;
case 0x0c09434cu: goto P_0c09434c;
case 0x0c09434eu: goto P_0c09434e;
case 0x0c094350u: goto P_0c094350;
case 0x0c094352u: goto P_0c094352;
case 0x0c094354u: goto P_0c094354;
case 0x0c094356u: goto P_0c094356;
case 0x0c094358u: goto P_0c094358;
case 0x0c09435au: goto P_0c09435a;
case 0x0c09435cu: goto P_0c09435c;
case 0x0c09435eu: goto P_0c09435e;
case 0x0c094360u: goto P_0c094360;
case 0x0c094362u: goto P_0c094362;
case 0x0c094364u: goto P_0c094364;
case 0x0c094366u: goto P_0c094366;
case 0x0c094368u: goto P_0c094368;
case 0x0c09436au: goto P_0c09436a;
case 0x0c09436cu: goto P_0c09436c;
case 0x0c09436eu: goto P_0c09436e;
case 0x0c094370u: goto P_0c094370;
case 0x0c094372u: goto P_0c094372;
case 0x0c094374u: goto P_0c094374;
case 0x0c094376u: goto P_0c094376;
case 0x0c094378u: goto P_0c094378;
case 0x0c09437au: goto P_0c09437a;
case 0x0c09437cu: goto P_0c09437c;
case 0x0c09437eu: goto P_0c09437e;
case 0x0c094380u: goto P_0c094380;
case 0x0c094382u: goto P_0c094382;
case 0x0c094384u: goto P_0c094384;
case 0x0c094386u: goto P_0c094386;
case 0x0c094388u: goto P_0c094388;
case 0x0c09438au: goto P_0c09438a;
case 0x0c09438cu: goto P_0c09438c;
case 0x0c09438eu: goto P_0c09438e;
case 0x0c094390u: goto P_0c094390;
case 0x0c094392u: goto P_0c094392;
case 0x0c094394u: goto P_0c094394;
case 0x0c094396u: goto P_0c094396;
case 0x0c094398u: goto P_0c094398;
case 0x0c09439au: goto P_0c09439a;
case 0x0c09439cu: goto P_0c09439c;
case 0x0c09439eu: goto P_0c09439e;
case 0x0c0943a0u: goto P_0c0943a0;
case 0x0c0943a2u: goto P_0c0943a2;
case 0x0c0943a4u: goto P_0c0943a4;
case 0x0c0943a6u: goto P_0c0943a6;
case 0x0c0943a8u: goto P_0c0943a8;
case 0x0c0943aau: goto P_0c0943aa;
case 0x0c0943acu: goto P_0c0943ac;
case 0x0c0943aeu: goto P_0c0943ae;
case 0x0c0943b0u: goto P_0c0943b0;
case 0x0c0943b2u: goto P_0c0943b2;
case 0x0c0943b4u: goto P_0c0943b4;
case 0x0c0943b6u: goto P_0c0943b6;
case 0x0c0943b8u: goto P_0c0943b8;
case 0x0c0943bau: goto P_0c0943ba;
case 0x0c0943f8u: goto P_0c0943f8;
case 0x0c0943fau: goto P_0c0943fa;
case 0x0c0943fcu: goto P_0c0943fc;
case 0x0c0943feu: goto P_0c0943fe;
case 0x0c094400u: goto P_0c094400;
case 0x0c094402u: goto P_0c094402;
case 0x0c094404u: goto P_0c094404;
case 0x0c094406u: goto P_0c094406;
case 0x0c094408u: goto P_0c094408;
case 0x0c09440au: goto P_0c09440a;
case 0x0c09440cu: goto P_0c09440c;
case 0x0c09440eu: goto P_0c09440e;
case 0x0c094410u: goto P_0c094410;
case 0x0c094412u: goto P_0c094412;
case 0x0c094414u: goto P_0c094414;
case 0x0c094416u: goto P_0c094416;
case 0x0c094418u: goto P_0c094418;
case 0x0c09441au: goto P_0c09441a;
case 0x0c094420u: goto P_0c094420;
case 0x0c094422u: goto P_0c094422;
case 0x0c094424u: goto P_0c094424;
case 0x0c094426u: goto P_0c094426;
case 0x0c094428u: goto P_0c094428;
case 0x0c09442au: goto P_0c09442a;
case 0x0c09442cu: goto P_0c09442c;
case 0x0c09442eu: goto P_0c09442e;
case 0x0c094430u: goto P_0c094430;
case 0x0c094432u: goto P_0c094432;
case 0x0c094434u: goto P_0c094434;
case 0x0c094436u: goto P_0c094436;
case 0x0c094438u: goto P_0c094438;
case 0x0c09443au: goto P_0c09443a;
case 0x0c09443cu: goto P_0c09443c;
case 0x0c09443eu: goto P_0c09443e;
case 0x0c094440u: goto P_0c094440;
case 0x0c094442u: goto P_0c094442;
case 0x0c094444u: goto P_0c094444;
case 0x0c094446u: goto P_0c094446;
case 0x0c094448u: goto P_0c094448;
case 0x0c09444au: goto P_0c09444a;
case 0x0c09444cu: goto P_0c09444c;
case 0x0c09444eu: goto P_0c09444e;
case 0x0c094450u: goto P_0c094450;
case 0x0c094452u: goto P_0c094452;
case 0x0c094454u: goto P_0c094454;
case 0x0c094456u: goto P_0c094456;
case 0x0c094458u: goto P_0c094458;
case 0x0c09445au: goto P_0c09445a;
case 0x0c09445cu: goto P_0c09445c;
case 0x0c09445eu: goto P_0c09445e;
case 0x0c094460u: goto P_0c094460;
case 0x0c094462u: goto P_0c094462;
case 0x0c094464u: goto P_0c094464;
case 0x0c094466u: goto P_0c094466;
case 0x0c094468u: goto P_0c094468;
case 0x0c094470u: goto P_0c094470;
case 0x0c094472u: goto P_0c094472;
case 0x0c094474u: goto P_0c094474;
case 0x0c094476u: goto P_0c094476;
case 0x0c094478u: goto P_0c094478;
case 0x0c09447au: goto P_0c09447a;
case 0x0c09447cu: goto P_0c09447c;
case 0x0c09447eu: goto P_0c09447e;
case 0x0c094480u: goto P_0c094480;
case 0x0c094482u: goto P_0c094482;
case 0x0c094484u: goto P_0c094484;
case 0x0c094486u: goto P_0c094486;
case 0x0c094488u: goto P_0c094488;
case 0x0c09448au: goto P_0c09448a;
case 0x0c09449cu: goto P_0c09449c;
case 0x0c09449eu: goto P_0c09449e;
case 0x0c0944a0u: goto P_0c0944a0;
case 0x0c0944a2u: goto P_0c0944a2;
case 0x0c0944a4u: goto P_0c0944a4;
case 0x0c0944a6u: goto P_0c0944a6;
case 0x0c0944a8u: goto P_0c0944a8;
case 0x0c0944aau: goto P_0c0944aa;
case 0x0c0944acu: goto P_0c0944ac;
case 0x0c0944aeu: goto P_0c0944ae;
case 0x0c0944b0u: goto P_0c0944b0;
case 0x0c0944b2u: goto P_0c0944b2;
case 0x0c0944b4u: goto P_0c0944b4;
case 0x0c0944b6u: goto P_0c0944b6;
case 0x0c0944b8u: goto P_0c0944b8;
case 0x0c0944bau: goto P_0c0944ba;
case 0x0c0944bcu: goto P_0c0944bc;
case 0x0c0944beu: goto P_0c0944be;
case 0x0c0944c0u: goto P_0c0944c0;
case 0x0c0944c2u: goto P_0c0944c2;
case 0x0c0944c4u: goto P_0c0944c4;
case 0x0c0944c6u: goto P_0c0944c6;
case 0x0c0944c8u: goto P_0c0944c8;
case 0x0c0944cau: goto P_0c0944ca;
case 0x0c0944ccu: goto P_0c0944cc;
case 0x0c0944ceu: goto P_0c0944ce;
case 0x0c0944d0u: goto P_0c0944d0;
case 0x0c0944d2u: goto P_0c0944d2;
case 0x0c0944d4u: goto P_0c0944d4;
case 0x0c0944d6u: goto P_0c0944d6;
case 0x0c0944d8u: goto P_0c0944d8;
case 0x0c0944dau: goto P_0c0944da;
case 0x0c0944dcu: goto P_0c0944dc;
case 0x0c0944deu: goto P_0c0944de;
case 0x0c0944e0u: goto P_0c0944e0;
case 0x0c0944e2u: goto P_0c0944e2;
case 0x0c0944e4u: goto P_0c0944e4;
case 0x0c0944e6u: goto P_0c0944e6;
case 0x0c0944e8u: goto P_0c0944e8;
case 0x0c0944eau: goto P_0c0944ea;
case 0x0c0944ecu: goto P_0c0944ec;
case 0x0c0944eeu: goto P_0c0944ee;
case 0x0c0944f0u: goto P_0c0944f0;
case 0x0c0a0464u: goto P_0c0a0464;
case 0x0c0a0466u: goto P_0c0a0466;
case 0x0c0a0468u: goto P_0c0a0468;
case 0x0c0a046au: goto P_0c0a046a;
case 0x0c0a046cu: goto P_0c0a046c;
case 0x0c0a046eu: goto P_0c0a046e;
case 0x0c0a0470u: goto P_0c0a0470;
case 0x0c0a0472u: goto P_0c0a0472;
case 0x0c0a0474u: goto P_0c0a0474;
case 0x0c0a0476u: goto P_0c0a0476;
case 0x0c0a0478u: goto P_0c0a0478;
case 0x0c0a047au: goto P_0c0a047a;
case 0x0c0a047cu: goto P_0c0a047c;
case 0x0c0a047eu: goto P_0c0a047e;
case 0x0c0a0480u: goto P_0c0a0480;
case 0x0c0a0482u: goto P_0c0a0482;
case 0x0c0a0484u: goto P_0c0a0484;
case 0x0c0a0486u: goto P_0c0a0486;
case 0x0c0a0488u: goto P_0c0a0488;
case 0x0c0a048au: goto P_0c0a048a;
case 0x0c0a048cu: goto P_0c0a048c;
case 0x0c0a048eu: goto P_0c0a048e;
case 0x0c0a0490u: goto P_0c0a0490;
case 0x0c0a0492u: goto P_0c0a0492;
case 0x0c0a0494u: goto P_0c0a0494;
case 0x0c0a0496u: goto P_0c0a0496;
case 0x0c0a0498u: goto P_0c0a0498;
case 0x0c0a049au: goto P_0c0a049a;
case 0x0c0a049cu: goto P_0c0a049c;
case 0x0c0a049eu: goto P_0c0a049e;
case 0x0c0a04a0u: goto P_0c0a04a0;
case 0x0c0a04a2u: goto P_0c0a04a2;
case 0x0c0a04a4u: goto P_0c0a04a4;
case 0x0c0a04a6u: goto P_0c0a04a6;
case 0x0c0a04a8u: goto P_0c0a04a8;
case 0x0c0a04aau: goto P_0c0a04aa;
case 0x0c0a04acu: goto P_0c0a04ac;
case 0x0c0a04aeu: goto P_0c0a04ae;
case 0x0c0a04b0u: goto P_0c0a04b0;
case 0x0c0a04b2u: goto P_0c0a04b2;
case 0x0c0a04b4u: goto P_0c0a04b4;
case 0x0c0a04b6u: goto P_0c0a04b6;
case 0x0c0a04b8u: goto P_0c0a04b8;
case 0x0c0a04bau: goto P_0c0a04ba;
case 0x0c0a04bcu: goto P_0c0a04bc;
case 0x0c0a04beu: goto P_0c0a04be;
case 0x0c0a04c0u: goto P_0c0a04c0;
case 0x0c0a04c2u: goto P_0c0a04c2;
case 0x0c0a04c4u: goto P_0c0a04c4;
case 0x0c0a04c6u: goto P_0c0a04c6;
case 0x0c0a04c8u: goto P_0c0a04c8;
case 0x0c0a04cau: goto P_0c0a04ca;
case 0x0c0a04ccu: goto P_0c0a04cc;
case 0x0c0a04ceu: goto P_0c0a04ce;
case 0x0c0a04d0u: goto P_0c0a04d0;
case 0x0c0a04d2u: goto P_0c0a04d2;
case 0x0c0a04d4u: goto P_0c0a04d4;
case 0x0c0a04d6u: goto P_0c0a04d6;
case 0x0c0a04d8u: goto P_0c0a04d8;
case 0x0c0a04dau: goto P_0c0a04da;
case 0x0c0a04e2u: goto P_0c0a04e2;
case 0x0c0a04e4u: goto P_0c0a04e4;
case 0x0c0a04e6u: goto P_0c0a04e6;
case 0x0c0a04e8u: goto P_0c0a04e8;
case 0x0c0a04eau: goto P_0c0a04ea;
case 0x0c0a04ecu: goto P_0c0a04ec;
case 0x0c0a04eeu: goto P_0c0a04ee;
case 0x0c0a04f0u: goto P_0c0a04f0;
case 0x0c0a04f2u: goto P_0c0a04f2;
case 0x0c0a04f4u: goto P_0c0a04f4;
case 0x0c0a04f6u: goto P_0c0a04f6;
case 0x0c0a04f8u: goto P_0c0a04f8;
case 0x0c0a04fau: goto P_0c0a04fa;
case 0x0c0a04fcu: goto P_0c0a04fc;
case 0x0c0a04feu: goto P_0c0a04fe;
case 0x0c0a0500u: goto P_0c0a0500;
case 0x0c0a0502u: goto P_0c0a0502;
case 0x0c0a0504u: goto P_0c0a0504;
case 0x0c0a0506u: goto P_0c0a0506;
case 0x0c0a0508u: goto P_0c0a0508;
case 0x0c0a050au: goto P_0c0a050a;
case 0x0c0a050cu: goto P_0c0a050c;
case 0x0c0a050eu: goto P_0c0a050e;
case 0x0c0a0510u: goto P_0c0a0510;
case 0x0c0a0512u: goto P_0c0a0512;
case 0x0c0a0514u: goto P_0c0a0514;
case 0x0c0a0516u: goto P_0c0a0516;
case 0x0c0a0518u: goto P_0c0a0518;
case 0x0c0a051au: goto P_0c0a051a;
case 0x0c0a051cu: goto P_0c0a051c;
case 0x0c0a051eu: goto P_0c0a051e;
case 0x0c0a0520u: goto P_0c0a0520;
case 0x0c0a0522u: goto P_0c0a0522;
case 0x0c0a0524u: goto P_0c0a0524;
case 0x0c0a0526u: goto P_0c0a0526;
case 0x0c0a0528u: goto P_0c0a0528;
case 0x0c0a052au: goto P_0c0a052a;
case 0x0c0a052cu: goto P_0c0a052c;
case 0x0c0a052eu: goto P_0c0a052e;
case 0x0c0a0530u: goto P_0c0a0530;
case 0x0c0a0532u: goto P_0c0a0532;
case 0x0c0a0534u: goto P_0c0a0534;
case 0x0c0a0536u: goto P_0c0a0536;
case 0x0c0a0538u: goto P_0c0a0538;
case 0x0c0a053au: goto P_0c0a053a;
case 0x0c0a053cu: goto P_0c0a053c;
case 0x0c0a053eu: goto P_0c0a053e;
case 0x0c0a0540u: goto P_0c0a0540;
case 0x0c0a0542u: goto P_0c0a0542;
case 0x0c0a0544u: goto P_0c0a0544;
case 0x0c0a0546u: goto P_0c0a0546;
case 0x0c0a0548u: goto P_0c0a0548;
case 0x0c0a054au: goto P_0c0a054a;
case 0x0c0a054cu: goto P_0c0a054c;
case 0x0c0a054eu: goto P_0c0a054e;
case 0x0c0a0550u: goto P_0c0a0550;
case 0x0c0a0552u: goto P_0c0a0552;
case 0x0c0a0554u: goto P_0c0a0554;
case 0x0c0a0556u: goto P_0c0a0556;
case 0x0c0a0558u: goto P_0c0a0558;
case 0x0c0a055au: goto P_0c0a055a;
case 0x0c0a055cu: goto P_0c0a055c;
case 0x0c0a055eu: goto P_0c0a055e;
case 0x0c0a0560u: goto P_0c0a0560;
case 0x0c0a0562u: goto P_0c0a0562;
case 0x0c0a0564u: goto P_0c0a0564;
case 0x0c0a0566u: goto P_0c0a0566;
case 0x0c0a0568u: goto P_0c0a0568;
case 0x0c0a056au: goto P_0c0a056a;
case 0x0c0a056cu: goto P_0c0a056c;
case 0x0c0a056eu: goto P_0c0a056e;
case 0x0c0a0570u: goto P_0c0a0570;
case 0x0c0a0572u: goto P_0c0a0572;
case 0x0c0a0574u: goto P_0c0a0574;
case 0x0c0a0576u: goto P_0c0a0576;
case 0x0c0a0578u: goto P_0c0a0578;
case 0x0c0a057au: goto P_0c0a057a;
case 0x0c0a057cu: goto P_0c0a057c;
case 0x0c0a057eu: goto P_0c0a057e;
case 0x0c0a0580u: goto P_0c0a0580;
case 0x0c0a0582u: goto P_0c0a0582;
case 0x0c0a0584u: goto P_0c0a0584;
case 0x0c0a0586u: goto P_0c0a0586;
case 0x0c0a0588u: goto P_0c0a0588;
case 0x0c0a058au: goto P_0c0a058a;
case 0x0c0a1212u: goto P_0c0a1212;
case 0x0c0a1214u: goto P_0c0a1214;
case 0x0c0a1216u: goto P_0c0a1216;
case 0x0c0a1218u: goto P_0c0a1218;
case 0x0c0a121au: goto P_0c0a121a;
case 0x0c0a121cu: goto P_0c0a121c;
case 0x0c0a121eu: goto P_0c0a121e;
case 0x0c0a1220u: goto P_0c0a1220;
case 0x0c0a1222u: goto P_0c0a1222;
case 0x0c0a1224u: goto P_0c0a1224;
case 0x0c0a1226u: goto P_0c0a1226;
case 0x0c0a1228u: goto P_0c0a1228;
case 0x0c0a122au: goto P_0c0a122a;
case 0x0c0a122cu: goto P_0c0a122c;
case 0x0c0a122eu: goto P_0c0a122e;
case 0x0c0a1230u: goto P_0c0a1230;
case 0x0c0a1232u: goto P_0c0a1232;
case 0x0c0a1234u: goto P_0c0a1234;
case 0x0c0a1236u: goto P_0c0a1236;
case 0x0c0a1238u: goto P_0c0a1238;
case 0x0c0a123au: goto P_0c0a123a;
case 0x0c0a123cu: goto P_0c0a123c;
case 0x0c0a123eu: goto P_0c0a123e;
case 0x0c0a1240u: goto P_0c0a1240;
case 0x0c0a1242u: goto P_0c0a1242;
case 0x0c0a1244u: goto P_0c0a1244;
case 0x0c0a1246u: goto P_0c0a1246;
case 0x0c0a1248u: goto P_0c0a1248;
case 0x0c0a124au: goto P_0c0a124a;
case 0x0c0a124cu: goto P_0c0a124c;
case 0x0c0a124eu: goto P_0c0a124e;
case 0x0c0a1250u: goto P_0c0a1250;
case 0x0c0a1252u: goto P_0c0a1252;
case 0x0c0a1254u: goto P_0c0a1254;
case 0x0c0a1256u: goto P_0c0a1256;
case 0x0c0a1258u: goto P_0c0a1258;
case 0x0c0a125au: goto P_0c0a125a;
case 0x0c0a125cu: goto P_0c0a125c;
case 0x0c0a125eu: goto P_0c0a125e;
case 0x0c0a1260u: goto P_0c0a1260;
case 0x0c0a1262u: goto P_0c0a1262;
case 0x0c0a1264u: goto P_0c0a1264;
case 0x0c0a1266u: goto P_0c0a1266;
case 0x0c0a1268u: goto P_0c0a1268;
case 0x0c0a126au: goto P_0c0a126a;
case 0x0c0a126cu: goto P_0c0a126c;
case 0x0c0a126eu: goto P_0c0a126e;
case 0x0c0a1270u: goto P_0c0a1270;
case 0x0c0a1272u: goto P_0c0a1272;
case 0x0c0a1274u: goto P_0c0a1274;
case 0x0c0a1276u: goto P_0c0a1276;
case 0x0c0a1278u: goto P_0c0a1278;
case 0x0c0a127au: goto P_0c0a127a;
case 0x0c0a127cu: goto P_0c0a127c;
case 0x0c0a127eu: goto P_0c0a127e;
case 0x0c0a1280u: goto P_0c0a1280;
case 0x0c0a7b56u: goto P_0c0a7b56;
case 0x0c0a7b58u: goto P_0c0a7b58;
case 0x0c0a7b5au: goto P_0c0a7b5a;
case 0x0c0a7b5cu: goto P_0c0a7b5c;
case 0x0c0a7b5eu: goto P_0c0a7b5e;
case 0x0c0a7b60u: goto P_0c0a7b60;
case 0x0c0a7b62u: goto P_0c0a7b62;
case 0x0c0a7b64u: goto P_0c0a7b64;
case 0x0c0a7b66u: goto P_0c0a7b66;
case 0x0c0a7b68u: goto P_0c0a7b68;
case 0x0c0a7b6au: goto P_0c0a7b6a;
case 0x0c0a7b6cu: goto P_0c0a7b6c;
case 0x0c0a7b6eu: goto P_0c0a7b6e;
case 0x0c0a7b70u: goto P_0c0a7b70;
case 0x0c0a7b72u: goto P_0c0a7b72;
case 0x0c0a7b74u: goto P_0c0a7b74;
case 0x0c0a7b76u: goto P_0c0a7b76;
case 0x0c0a7b78u: goto P_0c0a7b78;
case 0x0c0a7b7au: goto P_0c0a7b7a;
case 0x0c0a7b7cu: goto P_0c0a7b7c;
case 0x0c0a7b7eu: goto P_0c0a7b7e;
case 0x0c0a7b80u: goto P_0c0a7b80;
case 0x0c0a7b82u: goto P_0c0a7b82;
case 0x0c0a7b84u: goto P_0c0a7b84;
case 0x0c0ae29cu: goto P_0c0ae29c;
case 0x0c0ae29eu: goto P_0c0ae29e;
case 0x0c0ae2a0u: goto P_0c0ae2a0;
case 0x0c0ae2a2u: goto P_0c0ae2a2;
case 0x0c0ae2a4u: goto P_0c0ae2a4;
case 0x0c0ae2a6u: goto P_0c0ae2a6;
case 0x0c0ae2a8u: goto P_0c0ae2a8;
case 0x0c0ae2aau: goto P_0c0ae2aa;
case 0x0c0ae2acu: goto P_0c0ae2ac;
case 0x0c0ae2aeu: goto P_0c0ae2ae;
case 0x0c0ae2b0u: goto P_0c0ae2b0;
case 0x0c0ae2b2u: goto P_0c0ae2b2;
case 0x0c0ae2b4u: goto P_0c0ae2b4;
case 0x0c0ae2b6u: goto P_0c0ae2b6;
case 0x0c0ae2b8u: goto P_0c0ae2b8;
case 0x0c0ae2bau: goto P_0c0ae2ba;
case 0x0c0ae2bcu: goto P_0c0ae2bc;
case 0x0c0ae2beu: goto P_0c0ae2be;
case 0x0c0ae2c0u: goto P_0c0ae2c0;
case 0x0c0ae2c2u: goto P_0c0ae2c2;
case 0x0c0ae2c4u: goto P_0c0ae2c4;
case 0x0c0ae2c6u: goto P_0c0ae2c6;
case 0x0c0ae2c8u: goto P_0c0ae2c8;
case 0x0c0ae2cau: goto P_0c0ae2ca;
case 0x0c0ae2ccu: goto P_0c0ae2cc;
case 0x0c0ae2ceu: goto P_0c0ae2ce;
case 0x0c0ae2d0u: goto P_0c0ae2d0;
case 0x0c0ae2d2u: goto P_0c0ae2d2;
case 0x0c0ae2d4u: goto P_0c0ae2d4;
case 0x0c0ae2d6u: goto P_0c0ae2d6;
case 0x0c0ae2d8u: goto P_0c0ae2d8;
case 0x0c0ae2dau: goto P_0c0ae2da;
case 0x0c0ae6e8u: goto P_0c0ae6e8;
case 0x0c0ae6eau: goto P_0c0ae6ea;
case 0x0c0ae6ecu: goto P_0c0ae6ec;
case 0x0c0ae6eeu: goto P_0c0ae6ee;
case 0x0c0ae6f0u: goto P_0c0ae6f0;
case 0x0c0ae6f2u: goto P_0c0ae6f2;
case 0x0c0ae6f4u: goto P_0c0ae6f4;
case 0x0c0ae6f6u: goto P_0c0ae6f6;
case 0x0c0ae6f8u: goto P_0c0ae6f8;
case 0x0c0ae6fau: goto P_0c0ae6fa;
case 0x0c0ae6fcu: goto P_0c0ae6fc;
case 0x0c0ae6feu: goto P_0c0ae6fe;
case 0x0c0ae700u: goto P_0c0ae700;
case 0x0c0ae702u: goto P_0c0ae702;
case 0x0c0ae704u: goto P_0c0ae704;
case 0x0c0ae706u: goto P_0c0ae706;
case 0x0c0ae708u: goto P_0c0ae708;
case 0x0c0ae70au: goto P_0c0ae70a;
case 0x0c0ae70cu: goto P_0c0ae70c;
case 0x0c0ae70eu: goto P_0c0ae70e;
case 0x0c0ae710u: goto P_0c0ae710;
case 0x0c0ae712u: goto P_0c0ae712;
case 0x0c0ae714u: goto P_0c0ae714;
case 0x0c0ae716u: goto P_0c0ae716;
case 0x0c0ae718u: goto P_0c0ae718;
case 0x0c0ae71au: goto P_0c0ae71a;
case 0x0c0ae71cu: goto P_0c0ae71c;
case 0x0c0ae71eu: goto P_0c0ae71e;
case 0x0c0ae720u: goto P_0c0ae720;
case 0x0c0ae722u: goto P_0c0ae722;
case 0x0c0ae724u: goto P_0c0ae724;
case 0x0c0ae726u: goto P_0c0ae726;
case 0x0c0ae728u: goto P_0c0ae728;
case 0x0c0ae72au: goto P_0c0ae72a;
case 0x0c0ae72cu: goto P_0c0ae72c;
case 0x0c0ae72eu: goto P_0c0ae72e;
case 0x0c0ae730u: goto P_0c0ae730;
case 0x0c0ae732u: goto P_0c0ae732;
case 0x0c0ae734u: goto P_0c0ae734;
case 0x0c0ae736u: goto P_0c0ae736;
case 0x0c0ae738u: goto P_0c0ae738;
case 0x0c0ae73au: goto P_0c0ae73a;
case 0x0c0ae73cu: goto P_0c0ae73c;
case 0x0c0ae73eu: goto P_0c0ae73e;
case 0x0c0ae740u: goto P_0c0ae740;
case 0x0c0ae742u: goto P_0c0ae742;
case 0x0c0ae744u: goto P_0c0ae744;
case 0x0c0ae746u: goto P_0c0ae746;
case 0x0c0ae748u: goto P_0c0ae748;
case 0x0c0ae74au: goto P_0c0ae74a;
case 0x0c0ae74cu: goto P_0c0ae74c;
case 0x0c0ae74eu: goto P_0c0ae74e;
case 0x0c0ae750u: goto P_0c0ae750;
case 0x0c0ae752u: goto P_0c0ae752;
case 0x0c0ae754u: goto P_0c0ae754;
case 0x0c0ae756u: goto P_0c0ae756;
case 0x0c0ae758u: goto P_0c0ae758;
case 0x0c0ae75au: goto P_0c0ae75a;
case 0x0c0ae75cu: goto P_0c0ae75c;
case 0x0c0ae75eu: goto P_0c0ae75e;
case 0x0c0ae760u: goto P_0c0ae760;
case 0x0c0ae762u: goto P_0c0ae762;
case 0x0c0ae764u: goto P_0c0ae764;
case 0x0c0ae766u: goto P_0c0ae766;
case 0x0c0ae768u: goto P_0c0ae768;
case 0x0c0ae76au: goto P_0c0ae76a;
case 0x0c0ae76cu: goto P_0c0ae76c;
case 0x0c0ae76eu: goto P_0c0ae76e;
case 0x0c0ae770u: goto P_0c0ae770;
case 0x0c0ae772u: goto P_0c0ae772;
case 0x0c0ae774u: goto P_0c0ae774;
case 0x0c0ae776u: goto P_0c0ae776;
case 0x0c0ae778u: goto P_0c0ae778;
case 0x0c0ae77au: goto P_0c0ae77a;
case 0x0c0ae77cu: goto P_0c0ae77c;
case 0x0c0ae77eu: goto P_0c0ae77e;
case 0x0c0ae780u: goto P_0c0ae780;
case 0x0c0ae782u: goto P_0c0ae782;
case 0x0c0ae784u: goto P_0c0ae784;
case 0x0c0ae786u: goto P_0c0ae786;
case 0x0c0ae788u: goto P_0c0ae788;
case 0x0c0ae78au: goto P_0c0ae78a;
case 0x0c0ae78cu: goto P_0c0ae78c;
case 0x0c0ae78eu: goto P_0c0ae78e;
case 0x0c0ae790u: goto P_0c0ae790;
case 0x0c0ae792u: goto P_0c0ae792;
case 0x0c0ae794u: goto P_0c0ae794;
case 0x0c0ae796u: goto P_0c0ae796;
case 0x0c0ae798u: goto P_0c0ae798;
case 0x0c0ae79au: goto P_0c0ae79a;
case 0x0c0ae79cu: goto P_0c0ae79c;
case 0x0c0ae79eu: goto P_0c0ae79e;
case 0x0c0ae7a0u: goto P_0c0ae7a0;
case 0x0c0ae7a2u: goto P_0c0ae7a2;
case 0x0c0ae7a4u: goto P_0c0ae7a4;
case 0x0c0ae7a6u: goto P_0c0ae7a6;
case 0x0c0ae7a8u: goto P_0c0ae7a8;
case 0x0c0ae7aau: goto P_0c0ae7aa;
case 0x0c0b1b7cu: goto P_0c0b1b7c;
case 0x0c0b1b7eu: goto P_0c0b1b7e;
case 0x0c0b1b80u: goto P_0c0b1b80;
case 0x0c0b1b82u: goto P_0c0b1b82;
case 0x0c0b1b84u: goto P_0c0b1b84;
case 0x0c0b1b86u: goto P_0c0b1b86;
case 0x0c0b1b88u: goto P_0c0b1b88;
case 0x0c0b1c92u: goto P_0c0b1c92;
case 0x0c0b1c94u: goto P_0c0b1c94;
case 0x0c0b1c96u: goto P_0c0b1c96;
case 0x0c0b1c98u: goto P_0c0b1c98;
case 0x0c0b1c9au: goto P_0c0b1c9a;
case 0x0c0b1c9cu: goto P_0c0b1c9c;
case 0x0c0b1c9eu: goto P_0c0b1c9e;
case 0x0c0b1ca0u: goto P_0c0b1ca0;
case 0x0c0b1ca2u: goto P_0c0b1ca2;
case 0x0c0b1ca4u: goto P_0c0b1ca4;
case 0x0c0b1ca6u: goto P_0c0b1ca6;
case 0x0c0b1ca8u: goto P_0c0b1ca8;
case 0x0c0b1caau: goto P_0c0b1caa;
case 0x0c0b1cacu: goto P_0c0b1cac;
case 0x0c0b1caeu: goto P_0c0b1cae;
case 0x0c0b1cb0u: goto P_0c0b1cb0;
case 0x0c0b1cb2u: goto P_0c0b1cb2;
case 0x0c0b1cb4u: goto P_0c0b1cb4;
case 0x0c0b1cb6u: goto P_0c0b1cb6;
case 0x0c0b1cb8u: goto P_0c0b1cb8;
case 0x0c0b1cbau: goto P_0c0b1cba;
case 0x0c0b1cbcu: goto P_0c0b1cbc;
case 0x0c0b1cbeu: goto P_0c0b1cbe;
case 0x0c0b1cc0u: goto P_0c0b1cc0;
case 0x0c0b1cc2u: goto P_0c0b1cc2;
case 0x0c0c11f4u: goto P_0c0c11f4;
case 0x0c0c11f6u: goto P_0c0c11f6;
case 0x0c0c11f8u: goto P_0c0c11f8;
case 0x0c0c11fau: goto P_0c0c11fa;
case 0x0c0c11fcu: goto P_0c0c11fc;
case 0x0c0c11feu: goto P_0c0c11fe;
case 0x0c0c1200u: goto P_0c0c1200;
case 0x0c0c1202u: goto P_0c0c1202;
case 0x0c0c1204u: goto P_0c0c1204;
case 0x0c0c1206u: goto P_0c0c1206;
case 0x0c0c13deu: goto P_0c0c13de;
case 0x0c0c13e0u: goto P_0c0c13e0;
case 0x0c0c13e2u: goto P_0c0c13e2;
case 0x0c0c13e4u: goto P_0c0c13e4;
case 0x0c0c13e6u: goto P_0c0c13e6;
case 0x0c0c13e8u: goto P_0c0c13e8;
case 0x0c0c13eau: goto P_0c0c13ea;
case 0x0c0c13ecu: goto P_0c0c13ec;
case 0x0c0c13eeu: goto P_0c0c13ee;
case 0x0c0c13f0u: goto P_0c0c13f0;
case 0x0c0c13f2u: goto P_0c0c13f2;
case 0x0c0c13f4u: goto P_0c0c13f4;
case 0x0c0c13f6u: goto P_0c0c13f6;
case 0x0c0c13f8u: goto P_0c0c13f8;
case 0x0c0c13fau: goto P_0c0c13fa;
case 0x0c0c13fcu: goto P_0c0c13fc;
case 0x0c0c13feu: goto P_0c0c13fe;
case 0x0c0c1400u: goto P_0c0c1400;
case 0x0c0c1402u: goto P_0c0c1402;
case 0x0c0c1404u: goto P_0c0c1404;
case 0x0c0c1406u: goto P_0c0c1406;
case 0x0c0c1408u: goto P_0c0c1408;
case 0x0c0c140au: goto P_0c0c140a;
case 0x0c0c140cu: goto P_0c0c140c;
case 0x0c0c140eu: goto P_0c0c140e;
case 0x0c0c1410u: goto P_0c0c1410;
case 0x0c0c1412u: goto P_0c0c1412;
case 0x0c0c1414u: goto P_0c0c1414;
case 0x0c0c1416u: goto P_0c0c1416;
case 0x0c0c1418u: goto P_0c0c1418;
case 0x0c0c141au: goto P_0c0c141a;
case 0x0c0c141cu: goto P_0c0c141c;
case 0x0c0c141eu: goto P_0c0c141e;
case 0x0c0c1420u: goto P_0c0c1420;
case 0x0c0c1422u: goto P_0c0c1422;
case 0x0c0c1424u: goto P_0c0c1424;
case 0x0c0c1426u: goto P_0c0c1426;
case 0x0c0c1428u: goto P_0c0c1428;
case 0x0c0c142au: goto P_0c0c142a;
case 0x0c0c142cu: goto P_0c0c142c;
case 0x0c0c142eu: goto P_0c0c142e;
case 0x0c0c1430u: goto P_0c0c1430;
case 0x0c0c1432u: goto P_0c0c1432;
case 0x0c0c1434u: goto P_0c0c1434;
case 0x0c0c1436u: goto P_0c0c1436;
case 0x0c0c1438u: goto P_0c0c1438;
case 0x0c0c143au: goto P_0c0c143a;
case 0x0c0c143cu: goto P_0c0c143c;
case 0x0c0c143eu: goto P_0c0c143e;
case 0x0c0c1440u: goto P_0c0c1440;
case 0x0c0c1442u: goto P_0c0c1442;
case 0x0c0c1444u: goto P_0c0c1444;
case 0x0c0c1446u: goto P_0c0c1446;
case 0x0c0c1448u: goto P_0c0c1448;
case 0x0c0c144au: goto P_0c0c144a;
case 0x0c0c144cu: goto P_0c0c144c;
case 0x0c0c144eu: goto P_0c0c144e;
case 0x0c0c1450u: goto P_0c0c1450;
case 0x0c0c1452u: goto P_0c0c1452;
case 0x0c0c1454u: goto P_0c0c1454;
case 0x0c0c1456u: goto P_0c0c1456;
case 0x0c0c1458u: goto P_0c0c1458;
case 0x0c0c145au: goto P_0c0c145a;
case 0x0c0c145cu: goto P_0c0c145c;
case 0x0c0c145eu: goto P_0c0c145e;
case 0x0c0c1460u: goto P_0c0c1460;
case 0x0c0c1462u: goto P_0c0c1462;
case 0x0c0c1464u: goto P_0c0c1464;
case 0x0c0c1466u: goto P_0c0c1466;
case 0x0c0c1468u: goto P_0c0c1468;
case 0x0c0c146au: goto P_0c0c146a;
case 0x0c0c146cu: goto P_0c0c146c;
case 0x0c0c146eu: goto P_0c0c146e;
case 0x0c0c1470u: goto P_0c0c1470;
case 0x0c0c1472u: goto P_0c0c1472;
case 0x0c0c1474u: goto P_0c0c1474;
case 0x0c0c1476u: goto P_0c0c1476;
case 0x0c0c1478u: goto P_0c0c1478;
case 0x0c0c147au: goto P_0c0c147a;
case 0x0c0c147cu: goto P_0c0c147c;
case 0x0c0c147eu: goto P_0c0c147e;
case 0x0c0c1480u: goto P_0c0c1480;
case 0x0c0c1482u: goto P_0c0c1482;
case 0x0c0c1484u: goto P_0c0c1484;
case 0x0c0c1486u: goto P_0c0c1486;
case 0x0c0c1488u: goto P_0c0c1488;
case 0x0c0c14a4u: goto P_0c0c14a4;
case 0x0c0c14a6u: goto P_0c0c14a6;
case 0x0c0c14a8u: goto P_0c0c14a8;
case 0x0c0c14aau: goto P_0c0c14aa;
case 0x0c0c14acu: goto P_0c0c14ac;
case 0x0c0c14aeu: goto P_0c0c14ae;
case 0x0c0c14b0u: goto P_0c0c14b0;
case 0x0c0c14b2u: goto P_0c0c14b2;
case 0x0c0c14b4u: goto P_0c0c14b4;
case 0x0c0c14b6u: goto P_0c0c14b6;
case 0x0c0c14b8u: goto P_0c0c14b8;
case 0x0c0c14bau: goto P_0c0c14ba;
case 0x0c0c14bcu: goto P_0c0c14bc;
case 0x0c0c14beu: goto P_0c0c14be;
case 0x0c0c14c0u: goto P_0c0c14c0;
case 0x0c0c14c2u: goto P_0c0c14c2;
case 0x0c0c14c4u: goto P_0c0c14c4;
case 0x0c0c14c6u: goto P_0c0c14c6;
case 0x0c0c14c8u: goto P_0c0c14c8;
case 0x0c0c14cau: goto P_0c0c14ca;
case 0x0c0c14ccu: goto P_0c0c14cc;
case 0x0c0c14ceu: goto P_0c0c14ce;
case 0x0c0c14d0u: goto P_0c0c14d0;
case 0x0c0c14d2u: goto P_0c0c14d2;
case 0x0c0c14d4u: goto P_0c0c14d4;
case 0x0c0c14d6u: goto P_0c0c14d6;
case 0x0c0c14d8u: goto P_0c0c14d8;
case 0x0c0c14dau: goto P_0c0c14da;
case 0x0c0c14dcu: goto P_0c0c14dc;
case 0x0c0c14deu: goto P_0c0c14de;
case 0x0c0c14e0u: goto P_0c0c14e0;
case 0x0c0c14e2u: goto P_0c0c14e2;
case 0x0c0c14e4u: goto P_0c0c14e4;
case 0x0c0c14e6u: goto P_0c0c14e6;
case 0x0c0c14e8u: goto P_0c0c14e8;
case 0x0c0c14eau: goto P_0c0c14ea;
case 0x0c0c14ecu: goto P_0c0c14ec;
case 0x0c0c14eeu: goto P_0c0c14ee;
case 0x0c0c14f0u: goto P_0c0c14f0;
case 0x0c0c14f2u: goto P_0c0c14f2;
case 0x0c0c14f4u: goto P_0c0c14f4;
case 0x0c0c14f6u: goto P_0c0c14f6;
case 0x0c0c14f8u: goto P_0c0c14f8;
case 0x0c0c14fau: goto P_0c0c14fa;
case 0x0c0c14fcu: goto P_0c0c14fc;
case 0x0c0c14feu: goto P_0c0c14fe;
case 0x0c0c1500u: goto P_0c0c1500;
case 0x0c0c1502u: goto P_0c0c1502;
case 0x0c0c1504u: goto P_0c0c1504;
case 0x0c0c1506u: goto P_0c0c1506;
case 0x0c0c1508u: goto P_0c0c1508;
case 0x0c0c150au: goto P_0c0c150a;
case 0x0c0c150cu: goto P_0c0c150c;
case 0x0c0c150eu: goto P_0c0c150e;
case 0x0c0c1510u: goto P_0c0c1510;
case 0x0c0c1512u: goto P_0c0c1512;
case 0x0c0c1514u: goto P_0c0c1514;
case 0x0c0c1516u: goto P_0c0c1516;
case 0x0c0c1518u: goto P_0c0c1518;
case 0x0c0c151au: goto P_0c0c151a;
case 0x0c0c151cu: goto P_0c0c151c;
case 0x0c0c151eu: goto P_0c0c151e;
case 0x0c0c1520u: goto P_0c0c1520;
case 0x0c0c1522u: goto P_0c0c1522;
case 0x0c0c1524u: goto P_0c0c1524;
case 0x0c0c1526u: goto P_0c0c1526;
case 0x0c0c1528u: goto P_0c0c1528;
case 0x0c0c152au: goto P_0c0c152a;
case 0x0c0c152cu: goto P_0c0c152c;
case 0x0c0c152eu: goto P_0c0c152e;
case 0x0c0c1530u: goto P_0c0c1530;
case 0x0c0c1532u: goto P_0c0c1532;
case 0x0c0c1534u: goto P_0c0c1534;
case 0x0c0c1536u: goto P_0c0c1536;
case 0x0c0c1538u: goto P_0c0c1538;
case 0x0c0c153au: goto P_0c0c153a;
case 0x0c0c153cu: goto P_0c0c153c;
case 0x0c0c153eu: goto P_0c0c153e;
case 0x0c0c1540u: goto P_0c0c1540;
case 0x0c0c1542u: goto P_0c0c1542;
case 0x0c0c1544u: goto P_0c0c1544;
case 0x0c0c1546u: goto P_0c0c1546;
case 0x0c0c1548u: goto P_0c0c1548;
case 0x0c0c154au: goto P_0c0c154a;
case 0x0c0c154cu: goto P_0c0c154c;
case 0x0c0c154eu: goto P_0c0c154e;
case 0x0c0c1550u: goto P_0c0c1550;
case 0x0c0c1552u: goto P_0c0c1552;
case 0x0c0c1554u: goto P_0c0c1554;
case 0x0c0c1556u: goto P_0c0c1556;
case 0x0c0c1558u: goto P_0c0c1558;
case 0x0c0c155au: goto P_0c0c155a;
case 0x0c0c155cu: goto P_0c0c155c;
case 0x0c0c155eu: goto P_0c0c155e;
case 0x0c0c1560u: goto P_0c0c1560;
case 0x0c0c1562u: goto P_0c0c1562;
case 0x0c0c1564u: goto P_0c0c1564;
case 0x0c0c1566u: goto P_0c0c1566;
case 0x0c0c1568u: goto P_0c0c1568;
case 0x0c0c156au: goto P_0c0c156a;
case 0x0c0c156cu: goto P_0c0c156c;
case 0x0c0c156eu: goto P_0c0c156e;
case 0x0c0c1570u: goto P_0c0c1570;
case 0x0c0c1572u: goto P_0c0c1572;
case 0x0c0c1574u: goto P_0c0c1574;
case 0x0c0c1576u: goto P_0c0c1576;
case 0x0c0c1578u: goto P_0c0c1578;
case 0x0c0c157au: goto P_0c0c157a;
case 0x0c0c157cu: goto P_0c0c157c;
case 0x0c0c157eu: goto P_0c0c157e;
case 0x0c0c1580u: goto P_0c0c1580;
case 0x0c0c1582u: goto P_0c0c1582;
case 0x0c0c1584u: goto P_0c0c1584;
case 0x0c0c1586u: goto P_0c0c1586;
case 0x0c0c1588u: goto P_0c0c1588;
case 0x0c0c158au: goto P_0c0c158a;
case 0x0c0c158cu: goto P_0c0c158c;
case 0x0c0c158eu: goto P_0c0c158e;
case 0x0c0c1590u: goto P_0c0c1590;
case 0x0c0c1592u: goto P_0c0c1592;
case 0x0c0c1594u: goto P_0c0c1594;
case 0x0c0c1596u: goto P_0c0c1596;
case 0x0c0c1598u: goto P_0c0c1598;
case 0x0c0c159au: goto P_0c0c159a;
case 0x0c0c159cu: goto P_0c0c159c;
case 0x0c0c159eu: goto P_0c0c159e;
case 0x0c0c15a0u: goto P_0c0c15a0;
case 0x0c0c15a2u: goto P_0c0c15a2;
case 0x0c0c15a4u: goto P_0c0c15a4;
case 0x0c0c15a6u: goto P_0c0c15a6;
case 0x0c0c15a8u: goto P_0c0c15a8;
case 0x0c0c15aau: goto P_0c0c15aa;
case 0x0c0c15acu: goto P_0c0c15ac;
case 0x0c0c15aeu: goto P_0c0c15ae;
case 0x0c0c15b0u: goto P_0c0c15b0;
case 0x0c0c15b2u: goto P_0c0c15b2;
case 0x0c0c15b4u: goto P_0c0c15b4;
case 0x0c0c1770u: goto P_0c0c1770;
case 0x0c0c1772u: goto P_0c0c1772;
case 0x0c0c1774u: goto P_0c0c1774;
case 0x0c0c1776u: goto P_0c0c1776;
case 0x0c0c1778u: goto P_0c0c1778;
case 0x0c0c177au: goto P_0c0c177a;
case 0x0c0c177cu: goto P_0c0c177c;
case 0x0c0c177eu: goto P_0c0c177e;
case 0x0c0c1780u: goto P_0c0c1780;
case 0x0c0c17acu: goto P_0c0c17ac;
case 0x0c0c17aeu: goto P_0c0c17ae;
case 0x0c0c17b0u: goto P_0c0c17b0;
case 0x0c0c17b2u: goto P_0c0c17b2;
case 0x0c0c17b4u: goto P_0c0c17b4;
case 0x0c0c17b6u: goto P_0c0c17b6;
case 0x0c0c17b8u: goto P_0c0c17b8;
case 0x0c0c17bau: goto P_0c0c17ba;
case 0x0c0c17bcu: goto P_0c0c17bc;
case 0x0c0c17beu: goto P_0c0c17be;
case 0x0c0c17c0u: goto P_0c0c17c0;
case 0x0c0c17c2u: goto P_0c0c17c2;
case 0x0c0c17c4u: goto P_0c0c17c4;
case 0x0c0c17c6u: goto P_0c0c17c6;
case 0x0c0c17c8u: goto P_0c0c17c8;
case 0x0c0c17cau: goto P_0c0c17ca;
case 0x0c0c17ccu: goto P_0c0c17cc;
case 0x0c0c17ceu: goto P_0c0c17ce;
case 0x0c0c17d0u: goto P_0c0c17d0;
case 0x0c0c17d2u: goto P_0c0c17d2;
case 0x0c0c17d4u: goto P_0c0c17d4;
case 0x0c0c17d6u: goto P_0c0c17d6;
case 0x0c0c17d8u: goto P_0c0c17d8;
case 0x0c0c17dau: goto P_0c0c17da;
case 0x0c0c17dcu: goto P_0c0c17dc;
case 0x0c0c17deu: goto P_0c0c17de;
case 0x0c0c17e0u: goto P_0c0c17e0;
case 0x0c0c17e2u: goto P_0c0c17e2;
case 0x0c0c17e4u: goto P_0c0c17e4;
case 0x0c0c17e6u: goto P_0c0c17e6;
case 0x0c0c17e8u: goto P_0c0c17e8;
case 0x0c0c17eau: goto P_0c0c17ea;
case 0x0c0c17ecu: goto P_0c0c17ec;
case 0x0c0c17eeu: goto P_0c0c17ee;
case 0x0c0c17f0u: goto P_0c0c17f0;
case 0x0c0c17f2u: goto P_0c0c17f2;
case 0x0c0c17f4u: goto P_0c0c17f4;
case 0x0c0c17f6u: goto P_0c0c17f6;
case 0x0c0c17f8u: goto P_0c0c17f8;
case 0x0c0c17fau: goto P_0c0c17fa;
case 0x0c0c17fcu: goto P_0c0c17fc;
case 0x0c0c17feu: goto P_0c0c17fe;
case 0x0c0c1800u: goto P_0c0c1800;
case 0x0c0c1802u: goto P_0c0c1802;
case 0x0c0c1804u: goto P_0c0c1804;
case 0x0c0c1806u: goto P_0c0c1806;
case 0x0c0c1808u: goto P_0c0c1808;
case 0x0c0c180au: goto P_0c0c180a;
case 0x0c0c180cu: goto P_0c0c180c;
case 0x0c0c180eu: goto P_0c0c180e;
case 0x0c0c1810u: goto P_0c0c1810;
case 0x0c0c1812u: goto P_0c0c1812;
case 0x0c0c1814u: goto P_0c0c1814;
case 0x0c0c1816u: goto P_0c0c1816;
case 0x0c0c1818u: goto P_0c0c1818;
case 0x0c0c181au: goto P_0c0c181a;
case 0x0c0c181cu: goto P_0c0c181c;
case 0x0c0c181eu: goto P_0c0c181e;
case 0x0c0c1820u: goto P_0c0c1820;
case 0x0c0c1822u: goto P_0c0c1822;
case 0x0c0c1824u: goto P_0c0c1824;
case 0x0c0c1826u: goto P_0c0c1826;
case 0x0c0c1828u: goto P_0c0c1828;
case 0x0c0c182au: goto P_0c0c182a;
case 0x0c0c182cu: goto P_0c0c182c;
case 0x0c0c1d86u: goto P_0c0c1d86;
case 0x0c0c1d88u: goto P_0c0c1d88;
case 0x0c0c1d8au: goto P_0c0c1d8a;
case 0x0c0c1d8cu: goto P_0c0c1d8c;
case 0x0c0c1d8eu: goto P_0c0c1d8e;
case 0x0c0c1d90u: goto P_0c0c1d90;
case 0x0c0c1d92u: goto P_0c0c1d92;
case 0x0c0c1d94u: goto P_0c0c1d94;
case 0x0c0c1d96u: goto P_0c0c1d96;
case 0x0c0c1d98u: goto P_0c0c1d98;
case 0x0c0c1d9au: goto P_0c0c1d9a;
case 0x0c0c1d9cu: goto P_0c0c1d9c;
case 0x0c0c1d9eu: goto P_0c0c1d9e;
case 0x0c0c1da0u: goto P_0c0c1da0;
case 0x0c0c1da2u: goto P_0c0c1da2;
case 0x0c0c1da4u: goto P_0c0c1da4;
case 0x0c0c1da6u: goto P_0c0c1da6;
case 0x0c0c1da8u: goto P_0c0c1da8;
case 0x0c0c1daau: goto P_0c0c1daa;
case 0x0c0c1dacu: goto P_0c0c1dac;
case 0x0c0c1daeu: goto P_0c0c1dae;
case 0x0c0c1db0u: goto P_0c0c1db0;
case 0x0c0c1db2u: goto P_0c0c1db2;
case 0x0c0c1db4u: goto P_0c0c1db4;
case 0x0c0c1db6u: goto P_0c0c1db6;
case 0x0c0c1db8u: goto P_0c0c1db8;
case 0x0c0c1dbau: goto P_0c0c1dba;
case 0x0c0c1dbcu: goto P_0c0c1dbc;
case 0x0c0c1dbeu: goto P_0c0c1dbe;
case 0x0c0c1dc0u: goto P_0c0c1dc0;
case 0x0c0c1dc2u: goto P_0c0c1dc2;
case 0x0c0c1dc4u: goto P_0c0c1dc4;
case 0x0c0c1dc6u: goto P_0c0c1dc6;
case 0x0c0c1dc8u: goto P_0c0c1dc8;
case 0x0c0c1dcau: goto P_0c0c1dca;
case 0x0c0c1dccu: goto P_0c0c1dcc;
case 0x0c0c1dceu: goto P_0c0c1dce;
case 0x0c0c1dd0u: goto P_0c0c1dd0;
case 0x0c0c1dd2u: goto P_0c0c1dd2;
case 0x0c0c1dd4u: goto P_0c0c1dd4;
case 0x0c0c1dd6u: goto P_0c0c1dd6;
case 0x0c0c1dd8u: goto P_0c0c1dd8;
case 0x0c0c1ddau: goto P_0c0c1dda;
case 0x0c0c1ddcu: goto P_0c0c1ddc;
case 0x0c0c1ddeu: goto P_0c0c1dde;
case 0x0c0c1de0u: goto P_0c0c1de0;
case 0x0c0c1de2u: goto P_0c0c1de2;
case 0x0c0c1de4u: goto P_0c0c1de4;
case 0x0c0c1de6u: goto P_0c0c1de6;
case 0x0c0c1de8u: goto P_0c0c1de8;
case 0x0c0c1deau: goto P_0c0c1dea;
case 0x0c0c1decu: goto P_0c0c1dec;
case 0x0c0c1deeu: goto P_0c0c1dee;
case 0x0c0c1df0u: goto P_0c0c1df0;
case 0x0c0c1df2u: goto P_0c0c1df2;
case 0x0c0c1e24u: goto P_0c0c1e24;
case 0x0c0c1e26u: goto P_0c0c1e26;
case 0x0c0c1e28u: goto P_0c0c1e28;
case 0x0c0c1e2au: goto P_0c0c1e2a;
case 0x0c0c1e2cu: goto P_0c0c1e2c;
case 0x0c0c1e2eu: goto P_0c0c1e2e;
case 0x0c0c1e30u: goto P_0c0c1e30;
case 0x0c0c1e32u: goto P_0c0c1e32;
case 0x0c0c1e34u: goto P_0c0c1e34;
case 0x0c0c1e36u: goto P_0c0c1e36;
case 0x0c0c1e38u: goto P_0c0c1e38;
case 0x0c0c1e3au: goto P_0c0c1e3a;
case 0x0c0c1e3cu: goto P_0c0c1e3c;
case 0x0c0c1e3eu: goto P_0c0c1e3e;
case 0x0c0c1e40u: goto P_0c0c1e40;
case 0x0c0c1e42u: goto P_0c0c1e42;
case 0x0c0c1e44u: goto P_0c0c1e44;
case 0x0c0c1e46u: goto P_0c0c1e46;
case 0x0c0c1e48u: goto P_0c0c1e48;
case 0x0c0c1e4au: goto P_0c0c1e4a;
case 0x0c0c1e4cu: goto P_0c0c1e4c;
case 0x0c0c1e4eu: goto P_0c0c1e4e;
case 0x0c0c1e50u: goto P_0c0c1e50;
case 0x0c0c1e52u: goto P_0c0c1e52;
case 0x0c0c1e54u: goto P_0c0c1e54;
case 0x0c0c1e56u: goto P_0c0c1e56;
case 0x0c0c1e58u: goto P_0c0c1e58;
case 0x0c0c1e5au: goto P_0c0c1e5a;
case 0x0c0c1e5cu: goto P_0c0c1e5c;
case 0x0c0c1e5eu: goto P_0c0c1e5e;
case 0x0c0c1e60u: goto P_0c0c1e60;
case 0x0c0c1e62u: goto P_0c0c1e62;
case 0x0c0c1e64u: goto P_0c0c1e64;
case 0x0c0c1e66u: goto P_0c0c1e66;
case 0x0c0c1e68u: goto P_0c0c1e68;
case 0x0c0c1e6au: goto P_0c0c1e6a;
case 0x0c0c1e6cu: goto P_0c0c1e6c;
case 0x0c0c1e6eu: goto P_0c0c1e6e;
case 0x0c0c1e70u: goto P_0c0c1e70;
case 0x0c0c1e72u: goto P_0c0c1e72;
case 0x0c0c1e74u: goto P_0c0c1e74;
case 0x0c0c1e76u: goto P_0c0c1e76;
case 0x0c0c1e78u: goto P_0c0c1e78;
case 0x0c0c1e7au: goto P_0c0c1e7a;
case 0x0c0c1e7cu: goto P_0c0c1e7c;
case 0x0c0c1e7eu: goto P_0c0c1e7e;
case 0x0c0c1e80u: goto P_0c0c1e80;
case 0x0c0c1e82u: goto P_0c0c1e82;
case 0x0c0c1e84u: goto P_0c0c1e84;
case 0x0c0c1e86u: goto P_0c0c1e86;
case 0x0c0c1e88u: goto P_0c0c1e88;
case 0x0c0c1e8au: goto P_0c0c1e8a;
case 0x0c0c1e8cu: goto P_0c0c1e8c;
case 0x0c0c1e8eu: goto P_0c0c1e8e;
case 0x0c0c1e90u: goto P_0c0c1e90;
case 0x0c0c1e92u: goto P_0c0c1e92;
case 0x0c0c1e94u: goto P_0c0c1e94;
case 0x0c0c1e96u: goto P_0c0c1e96;
case 0x0c0c1e98u: goto P_0c0c1e98;
case 0x0c0c1e9au: goto P_0c0c1e9a;
case 0x0c0c1e9cu: goto P_0c0c1e9c;
case 0x0c0c1e9eu: goto P_0c0c1e9e;
case 0x0c0c1ea0u: goto P_0c0c1ea0;
case 0x0c0c1ea2u: goto P_0c0c1ea2;
case 0x0c0c1ea4u: goto P_0c0c1ea4;
case 0x0c0c1ea6u: goto P_0c0c1ea6;
case 0x0c0c1ea8u: goto P_0c0c1ea8;
case 0x0c0c1eaau: goto P_0c0c1eaa;
case 0x0c0c1eacu: goto P_0c0c1eac;
case 0x0c0c1eaeu: goto P_0c0c1eae;
case 0x0c0c1eb0u: goto P_0c0c1eb0;
case 0x0c0c1eb2u: goto P_0c0c1eb2;
case 0x0c0c1eb4u: goto P_0c0c1eb4;
case 0x0c0c1eb6u: goto P_0c0c1eb6;
case 0x0c0c1eb8u: goto P_0c0c1eb8;
case 0x0c0c1ebau: goto P_0c0c1eba;
case 0x0c0c1ebcu: goto P_0c0c1ebc;
case 0x0c0c1ebeu: goto P_0c0c1ebe;
case 0x0c0c1ec0u: goto P_0c0c1ec0;
case 0x0c0c1ec2u: goto P_0c0c1ec2;
case 0x0c0c1ec4u: goto P_0c0c1ec4;
case 0x0c0c1ec6u: goto P_0c0c1ec6;
case 0x0c0c1ec8u: goto P_0c0c1ec8;
case 0x0c0c1ecau: goto P_0c0c1eca;
case 0x0c0c1eccu: goto P_0c0c1ecc;
case 0x0c0c1eceu: goto P_0c0c1ece;
case 0x0c0c1ed0u: goto P_0c0c1ed0;
case 0x0c0c1ed2u: goto P_0c0c1ed2;
case 0x0c0c1ed4u: goto P_0c0c1ed4;
case 0x0c0c1ed6u: goto P_0c0c1ed6;
case 0x0c0c1ed8u: goto P_0c0c1ed8;
case 0x0c0c1edau: goto P_0c0c1eda;
case 0x0c0c1edcu: goto P_0c0c1edc;
case 0x0c0c1edeu: goto P_0c0c1ede;
case 0x0c0c1ee0u: goto P_0c0c1ee0;
case 0x0c0c1ee2u: goto P_0c0c1ee2;
case 0x0c0c1ee4u: goto P_0c0c1ee4;
case 0x0c0c1ee6u: goto P_0c0c1ee6;
case 0x0c0c1ee8u: goto P_0c0c1ee8;
case 0x0c0c1eeau: goto P_0c0c1eea;
case 0x0c0c1eecu: goto P_0c0c1eec;
case 0x0c0c1eeeu: goto P_0c0c1eee;
case 0x0c0c1ef0u: goto P_0c0c1ef0;
case 0x0c0c1ef2u: goto P_0c0c1ef2;
case 0x0c0c1ef4u: goto P_0c0c1ef4;
case 0x0c0c1ef6u: goto P_0c0c1ef6;
case 0x0c0c1ef8u: goto P_0c0c1ef8;
case 0x0c0c1efau: goto P_0c0c1efa;
case 0x0c0c1efcu: goto P_0c0c1efc;
case 0x0c0c1efeu: goto P_0c0c1efe;
case 0x0c0c1f00u: goto P_0c0c1f00;
case 0x0c0c1f02u: goto P_0c0c1f02;
case 0x0c0c1f04u: goto P_0c0c1f04;
case 0x0c0c1f06u: goto P_0c0c1f06;
case 0x0c0c1f08u: goto P_0c0c1f08;
case 0x0c0c1f0au: goto P_0c0c1f0a;
case 0x0c0c1f0cu: goto P_0c0c1f0c;
case 0x0c0c1f0eu: goto P_0c0c1f0e;
case 0x0c0c1f10u: goto P_0c0c1f10;
case 0x0c0c1f12u: goto P_0c0c1f12;
case 0x0c0c1f14u: goto P_0c0c1f14;
case 0x0c0c1f16u: goto P_0c0c1f16;
case 0x0c0c1f18u: goto P_0c0c1f18;
case 0x0c0c1f1au: goto P_0c0c1f1a;
case 0x0c0c1f1cu: goto P_0c0c1f1c;
case 0x0c0c1f1eu: goto P_0c0c1f1e;
case 0x0c0c1f20u: goto P_0c0c1f20;
case 0x0c0c1f22u: goto P_0c0c1f22;
case 0x0c0c1f24u: goto P_0c0c1f24;
case 0x0c0c1f26u: goto P_0c0c1f26;
case 0x0c0c1f28u: goto P_0c0c1f28;
case 0x0c0c1f2au: goto P_0c0c1f2a;
case 0x0c0c1f2cu: goto P_0c0c1f2c;
case 0x0c0c1f2eu: goto P_0c0c1f2e;
case 0x0c0c1f30u: goto P_0c0c1f30;
case 0x0c0c2bb4u: goto P_0c0c2bb4;
case 0x0c0c2bb6u: goto P_0c0c2bb6;
case 0x0c0c2bb8u: goto P_0c0c2bb8;
case 0x0c0c2bbau: goto P_0c0c2bba;
case 0x0c0c2bbcu: goto P_0c0c2bbc;
case 0x0c0c2bbeu: goto P_0c0c2bbe;
case 0x0c0c2bc0u: goto P_0c0c2bc0;
case 0x0c0c2bc2u: goto P_0c0c2bc2;
case 0x0c0c2bc4u: goto P_0c0c2bc4;
case 0x0c0c2bc6u: goto P_0c0c2bc6;
case 0x0c0c2bc8u: goto P_0c0c2bc8;
case 0x0c0c2bcau: goto P_0c0c2bca;
case 0x0c0c2bccu: goto P_0c0c2bcc;
case 0x0c0c2bceu: goto P_0c0c2bce;
case 0x0c0c2bd0u: goto P_0c0c2bd0;
case 0x0c0c2bd2u: goto P_0c0c2bd2;
case 0x0c0c2bd4u: goto P_0c0c2bd4;
case 0x0c0c2bd6u: goto P_0c0c2bd6;
case 0x0c0c2bd8u: goto P_0c0c2bd8;
case 0x0c0c2bdau: goto P_0c0c2bda;
case 0x0c0c2bdcu: goto P_0c0c2bdc;
case 0x0c0c2bdeu: goto P_0c0c2bde;
case 0x0c0c2be0u: goto P_0c0c2be0;
case 0x0c0c2be2u: goto P_0c0c2be2;
case 0x0c0c2be4u: goto P_0c0c2be4;
case 0x0c0c2be6u: goto P_0c0c2be6;
case 0x0c0c2be8u: goto P_0c0c2be8;
case 0x0c0c2beau: goto P_0c0c2bea;
case 0x0c0c2becu: goto P_0c0c2bec;
case 0x0c0c2beeu: goto P_0c0c2bee;
case 0x0c0c2bf0u: goto P_0c0c2bf0;
case 0x0c0c2bf2u: goto P_0c0c2bf2;
case 0x0c0c2bf4u: goto P_0c0c2bf4;
case 0x0c0c2bf6u: goto P_0c0c2bf6;
case 0x0c0c2bf8u: goto P_0c0c2bf8;
case 0x0c0c2bfau: goto P_0c0c2bfa;
case 0x0c0c2bfcu: goto P_0c0c2bfc;
case 0x0c0c2bfeu: goto P_0c0c2bfe;
case 0x0c0c2c00u: goto P_0c0c2c00;
case 0x0c0c2c02u: goto P_0c0c2c02;
case 0x0c0c2c04u: goto P_0c0c2c04;
case 0x0c0c2c06u: goto P_0c0c2c06;
case 0x0c0c2c08u: goto P_0c0c2c08;
case 0x0c0c2c0au: goto P_0c0c2c0a;
case 0x0c0c2c0cu: goto P_0c0c2c0c;
case 0x0c0c2c0eu: goto P_0c0c2c0e;
case 0x0c0c2c10u: goto P_0c0c2c10;
case 0x0c0c2c12u: goto P_0c0c2c12;
case 0x0c0c2c14u: goto P_0c0c2c14;
case 0x0c0c2c16u: goto P_0c0c2c16;
case 0x0c0c2c18u: goto P_0c0c2c18;
case 0x0c0c2c1au: goto P_0c0c2c1a;
case 0x0c0c2c1cu: goto P_0c0c2c1c;
case 0x0c0c2c1eu: goto P_0c0c2c1e;
case 0x0c0c2c20u: goto P_0c0c2c20;
case 0x0c0c2c22u: goto P_0c0c2c22;
case 0x0c0c2c24u: goto P_0c0c2c24;
case 0x0c0c2c26u: goto P_0c0c2c26;
case 0x0c0c2c28u: goto P_0c0c2c28;
case 0x0c0c2c2au: goto P_0c0c2c2a;
case 0x0c0c4ebau: goto P_0c0c4eba;
case 0x0c0c4ebcu: goto P_0c0c4ebc;
case 0x0c0c4ebeu: goto P_0c0c4ebe;
case 0x0c0c4ec0u: goto P_0c0c4ec0;
case 0x0c0c4ec2u: goto P_0c0c4ec2;
case 0x0c0c4ec4u: goto P_0c0c4ec4;
case 0x0c0c4ec6u: goto P_0c0c4ec6;
case 0x0c0c4ec8u: goto P_0c0c4ec8;
case 0x0c0c4ecau: goto P_0c0c4eca;
case 0x0c0c4eccu: goto P_0c0c4ecc;
case 0x0c0c4eceu: goto P_0c0c4ece;
case 0x0c0c4ed0u: goto P_0c0c4ed0;
case 0x0c0c4ed2u: goto P_0c0c4ed2;
case 0x0c0c4ed4u: goto P_0c0c4ed4;
case 0x0c0c4ed6u: goto P_0c0c4ed6;
case 0x0c0c4ed8u: goto P_0c0c4ed8;
case 0x0c0c4edau: goto P_0c0c4eda;
case 0x0c0c4edcu: goto P_0c0c4edc;
case 0x0c0c4edeu: goto P_0c0c4ede;
case 0x0c0c4ee0u: goto P_0c0c4ee0;
case 0x0c0c4ee2u: goto P_0c0c4ee2;
case 0x0c0c4ee4u: goto P_0c0c4ee4;
case 0x0c0c4ee6u: goto P_0c0c4ee6;
case 0x0c0c4ee8u: goto P_0c0c4ee8;
case 0x0c0c4eeau: goto P_0c0c4eea;
case 0x0c0c4eecu: goto P_0c0c4eec;
case 0x0c0c4eeeu: goto P_0c0c4eee;
case 0x0c0c4ef0u: goto P_0c0c4ef0;
case 0x0c0c4ef2u: goto P_0c0c4ef2;
case 0x0c0c4ef4u: goto P_0c0c4ef4;
case 0x0c0c4ef6u: goto P_0c0c4ef6;
case 0x0c0c4ef8u: goto P_0c0c4ef8;
case 0x0c0c4efau: goto P_0c0c4efa;
case 0x0c0c4efcu: goto P_0c0c4efc;
case 0x0c0c4efeu: goto P_0c0c4efe;
case 0x0c0c4f00u: goto P_0c0c4f00;
case 0x0c0c4f02u: goto P_0c0c4f02;
case 0x0c0c4f04u: goto P_0c0c4f04;
case 0x0c0c4f06u: goto P_0c0c4f06;
case 0x0c0c4f08u: goto P_0c0c4f08;
case 0x0c0c4f0au: goto P_0c0c4f0a;
case 0x0c0c4f0cu: goto P_0c0c4f0c;
case 0x0c0c4f0eu: goto P_0c0c4f0e;
case 0x0c0c4f10u: goto P_0c0c4f10;
case 0x0c0c4f12u: goto P_0c0c4f12;
case 0x0c0c4f14u: goto P_0c0c4f14;
case 0x0c0c4f16u: goto P_0c0c4f16;
case 0x0c0c4f18u: goto P_0c0c4f18;
case 0x0c0c4f1au: goto P_0c0c4f1a;
case 0x0c0c4f1cu: goto P_0c0c4f1c;
case 0x0c0c4f1eu: goto P_0c0c4f1e;
case 0x0c0c4f20u: goto P_0c0c4f20;
case 0x0c0c4f22u: goto P_0c0c4f22;
case 0x0c0c4f24u: goto P_0c0c4f24;
case 0x0c0c4f26u: goto P_0c0c4f26;
case 0x0c0c4f28u: goto P_0c0c4f28;
case 0x0c0c4f2au: goto P_0c0c4f2a;
case 0x0c0c4f2cu: goto P_0c0c4f2c;
case 0x0c0c4f2eu: goto P_0c0c4f2e;
case 0x0c0c4f30u: goto P_0c0c4f30;
case 0x0c0c4f32u: goto P_0c0c4f32;
case 0x0c0c4f34u: goto P_0c0c4f34;
case 0x0c0c4f36u: goto P_0c0c4f36;
case 0x0c0c4f38u: goto P_0c0c4f38;
case 0x0c0c4f3au: goto P_0c0c4f3a;
case 0x0c0c4f3cu: goto P_0c0c4f3c;
case 0x0c0c4f3eu: goto P_0c0c4f3e;
case 0x0c0c4f40u: goto P_0c0c4f40;
case 0x0c0c4f80u: goto P_0c0c4f80;
case 0x0c0c4f82u: goto P_0c0c4f82;
case 0x0c0c4f84u: goto P_0c0c4f84;
case 0x0c0c4f86u: goto P_0c0c4f86;
case 0x0c0c4f88u: goto P_0c0c4f88;
case 0x0c0c4f8au: goto P_0c0c4f8a;
case 0x0c0c4f8cu: goto P_0c0c4f8c;
case 0x0c0c4f8eu: goto P_0c0c4f8e;
case 0x0c0c4f90u: goto P_0c0c4f90;
case 0x0c0c4f92u: goto P_0c0c4f92;
case 0x0c0c4f94u: goto P_0c0c4f94;
case 0x0c0c4f96u: goto P_0c0c4f96;
case 0x0c0c4f98u: goto P_0c0c4f98;
case 0x0c0c4f9au: goto P_0c0c4f9a;
case 0x0c0c4f9cu: goto P_0c0c4f9c;
case 0x0c0c4f9eu: goto P_0c0c4f9e;
case 0x0c0c4fa0u: goto P_0c0c4fa0;
case 0x0c0c4fa2u: goto P_0c0c4fa2;
case 0x0c0c4fa4u: goto P_0c0c4fa4;
case 0x0c0c4fa6u: goto P_0c0c4fa6;
case 0x0c0c4fa8u: goto P_0c0c4fa8;
case 0x0c0c4faau: goto P_0c0c4faa;
case 0x0c0c4facu: goto P_0c0c4fac;
case 0x0c0c4faeu: goto P_0c0c4fae;
case 0x0c0c4fb0u: goto P_0c0c4fb0;
case 0x0c0c4fb2u: goto P_0c0c4fb2;
case 0x0c0c4fb4u: goto P_0c0c4fb4;
case 0x0c0c4fb6u: goto P_0c0c4fb6;
case 0x0c0c4fb8u: goto P_0c0c4fb8;
case 0x0c0c4fbau: goto P_0c0c4fba;
case 0x0c0c4fbcu: goto P_0c0c4fbc;
case 0x0c0c4fbeu: goto P_0c0c4fbe;
case 0x0c0c4fc0u: goto P_0c0c4fc0;
case 0x0c0c4fc2u: goto P_0c0c4fc2;
case 0x0c0c4fc4u: goto P_0c0c4fc4;
case 0x0c0c4fc6u: goto P_0c0c4fc6;
case 0x0c0c4fc8u: goto P_0c0c4fc8;
case 0x0c0c4fcau: goto P_0c0c4fca;
case 0x0c0c4fccu: goto P_0c0c4fcc;
case 0x0c0c4fceu: goto P_0c0c4fce;
case 0x0c0c4fd0u: goto P_0c0c4fd0;
case 0x0c0c4fd2u: goto P_0c0c4fd2;
case 0x0c0c4fd4u: goto P_0c0c4fd4;
case 0x0c0c4fd6u: goto P_0c0c4fd6;
case 0x0c0c4fd8u: goto P_0c0c4fd8;
case 0x0c0c4fdau: goto P_0c0c4fda;
case 0x0c0c4fdcu: goto P_0c0c4fdc;
case 0x0c0c4fdeu: goto P_0c0c4fde;
case 0x0c0c4fe0u: goto P_0c0c4fe0;
case 0x0c0c4fe2u: goto P_0c0c4fe2;
case 0x0c0c4fe4u: goto P_0c0c4fe4;
case 0x0c0c4fe6u: goto P_0c0c4fe6;
case 0x0c0c4fe8u: goto P_0c0c4fe8;
case 0x0c0c4feau: goto P_0c0c4fea;
case 0x0c0c4fecu: goto P_0c0c4fec;
case 0x0c0c4feeu: goto P_0c0c4fee;
case 0x0c0c4ff0u: goto P_0c0c4ff0;
case 0x0c0c4ff2u: goto P_0c0c4ff2;
case 0x0c0c4ff4u: goto P_0c0c4ff4;
case 0x0c0c4ff6u: goto P_0c0c4ff6;
case 0x0c0c4ff8u: goto P_0c0c4ff8;
case 0x0c0c4ffau: goto P_0c0c4ffa;
case 0x0c0c4ffcu: goto P_0c0c4ffc;
case 0x0c0c4ffeu: goto P_0c0c4ffe;
case 0x0c0c5000u: goto P_0c0c5000;
case 0x0c0c5002u: goto P_0c0c5002;
case 0x0c0c5004u: goto P_0c0c5004;
case 0x0c0c5006u: goto P_0c0c5006;
case 0x0c0c5008u: goto P_0c0c5008;
case 0x0c0c500au: goto P_0c0c500a;
case 0x0c0c500cu: goto P_0c0c500c;
case 0x0c0c500eu: goto P_0c0c500e;
case 0x0c0c5010u: goto P_0c0c5010;
case 0x0c0c5012u: goto P_0c0c5012;
case 0x0c0c5014u: goto P_0c0c5014;
case 0x0c0c5016u: goto P_0c0c5016;
case 0x0c0c5018u: goto P_0c0c5018;
case 0x0c0c501au: goto P_0c0c501a;
case 0x0c0c501cu: goto P_0c0c501c;
case 0x0c0c501eu: goto P_0c0c501e;
case 0x0c0c5020u: goto P_0c0c5020;
case 0x0c0c5022u: goto P_0c0c5022;
case 0x0c0c5024u: goto P_0c0c5024;
case 0x0c0c5062u: goto P_0c0c5062;
case 0x0c0c5064u: goto P_0c0c5064;
case 0x0c0c5066u: goto P_0c0c5066;
case 0x0c0c5068u: goto P_0c0c5068;
case 0x0c0c506au: goto P_0c0c506a;
case 0x0c0c506cu: goto P_0c0c506c;
case 0x0c0c506eu: goto P_0c0c506e;
case 0x0c0c5070u: goto P_0c0c5070;
case 0x0c0c5072u: goto P_0c0c5072;
case 0x0c0c5074u: goto P_0c0c5074;
case 0x0c0c5076u: goto P_0c0c5076;
case 0x0c0c5078u: goto P_0c0c5078;
case 0x0c0c507au: goto P_0c0c507a;
case 0x0c0c507cu: goto P_0c0c507c;
case 0x0c0c507eu: goto P_0c0c507e;
case 0x0c0c5080u: goto P_0c0c5080;
case 0x0c0c5082u: goto P_0c0c5082;
case 0x0c0c5084u: goto P_0c0c5084;
case 0x0c0c5086u: goto P_0c0c5086;
case 0x0c0c5088u: goto P_0c0c5088;
case 0x0c0c508au: goto P_0c0c508a;
case 0x0c0c508cu: goto P_0c0c508c;
case 0x0c0c508eu: goto P_0c0c508e;
case 0x0c0c5090u: goto P_0c0c5090;
case 0x0c0c5092u: goto P_0c0c5092;
case 0x0c0c5094u: goto P_0c0c5094;
case 0x0c0c5096u: goto P_0c0c5096;
case 0x0c0c5098u: goto P_0c0c5098;
case 0x0c0c509au: goto P_0c0c509a;
case 0x0c0c509cu: goto P_0c0c509c;
case 0x0c0c509eu: goto P_0c0c509e;
case 0x0c0c50a0u: goto P_0c0c50a0;
case 0x0c0c50a2u: goto P_0c0c50a2;
case 0x0c0c50a4u: goto P_0c0c50a4;
case 0x0c0c50a6u: goto P_0c0c50a6;
case 0x0c0c50a8u: goto P_0c0c50a8;
case 0x0c0c50aau: goto P_0c0c50aa;
case 0x0c0c50acu: goto P_0c0c50ac;
case 0x0c0c50aeu: goto P_0c0c50ae;
case 0x0c0c50b0u: goto P_0c0c50b0;
case 0x0c0c50b2u: goto P_0c0c50b2;
case 0x0c0c50b4u: goto P_0c0c50b4;
case 0x0c0c50b6u: goto P_0c0c50b6;
case 0x0c0c50b8u: goto P_0c0c50b8;
case 0x0c0c50bau: goto P_0c0c50ba;
case 0x0c0c50bcu: goto P_0c0c50bc;
case 0x0c0c50beu: goto P_0c0c50be;
case 0x0c0c50c0u: goto P_0c0c50c0;
case 0x0c0c50c2u: goto P_0c0c50c2;
case 0x0c0c50c4u: goto P_0c0c50c4;
case 0x0c0c50c6u: goto P_0c0c50c6;
case 0x0c0c50c8u: goto P_0c0c50c8;
case 0x0c0c50cau: goto P_0c0c50ca;
case 0x0c0c50ccu: goto P_0c0c50cc;
case 0x0c0c50ceu: goto P_0c0c50ce;
case 0x0c0c50d0u: goto P_0c0c50d0;
case 0x0c0c50d2u: goto P_0c0c50d2;
case 0x0c0c50d4u: goto P_0c0c50d4;
case 0x0c0c50d6u: goto P_0c0c50d6;
case 0x0c0c50d8u: goto P_0c0c50d8;
case 0x0c0c50dau: goto P_0c0c50da;
case 0x0c0c50dcu: goto P_0c0c50dc;
case 0x0c0c50deu: goto P_0c0c50de;
case 0x0c0c50e0u: goto P_0c0c50e0;
case 0x0c0c50e2u: goto P_0c0c50e2;
case 0x0c0c50e4u: goto P_0c0c50e4;
case 0x0c0c50e6u: goto P_0c0c50e6;
case 0x0c0c50e8u: goto P_0c0c50e8;
case 0x0c0c50eau: goto P_0c0c50ea;
case 0x0c0c50ecu: goto P_0c0c50ec;
case 0x0c0c50eeu: goto P_0c0c50ee;
case 0x0c0c50f0u: goto P_0c0c50f0;
case 0x0c0c50f2u: goto P_0c0c50f2;
case 0x0c0c50f4u: goto P_0c0c50f4;
case 0x0c0c50f6u: goto P_0c0c50f6;
case 0x0c0c50f8u: goto P_0c0c50f8;
case 0x0c0c50fau: goto P_0c0c50fa;
case 0x0c0c50fcu: goto P_0c0c50fc;
case 0x0c0c50feu: goto P_0c0c50fe;
case 0x0c0c5100u: goto P_0c0c5100;
case 0x0c0c5102u: goto P_0c0c5102;
case 0x0c0c5104u: goto P_0c0c5104;
case 0x0c0c5106u: goto P_0c0c5106;
case 0x0c0c5108u: goto P_0c0c5108;
case 0x0c0c510au: goto P_0c0c510a;
case 0x0c0c510cu: goto P_0c0c510c;
case 0x0c0c510eu: goto P_0c0c510e;
case 0x0c0c5110u: goto P_0c0c5110;
case 0x0c0c5112u: goto P_0c0c5112;
case 0x0c0c5114u: goto P_0c0c5114;
case 0x0c0c5116u: goto P_0c0c5116;
case 0x0c0c5118u: goto P_0c0c5118;
case 0x0c0c511au: goto P_0c0c511a;
case 0x0c0c511cu: goto P_0c0c511c;
case 0x0c0c511eu: goto P_0c0c511e;
case 0x0c0c5120u: goto P_0c0c5120;
case 0x0c0c5122u: goto P_0c0c5122;
case 0x0c0c5124u: goto P_0c0c5124;
case 0x0c0c5126u: goto P_0c0c5126;
case 0x0c0c5128u: goto P_0c0c5128;
case 0x0c0c512au: goto P_0c0c512a;
case 0x0c0c512cu: goto P_0c0c512c;
case 0x0c0c512eu: goto P_0c0c512e;
case 0x0c0c5130u: goto P_0c0c5130;
case 0x0c0c5132u: goto P_0c0c5132;
case 0x0c0c5134u: goto P_0c0c5134;
case 0x0c0c5136u: goto P_0c0c5136;
case 0x0c0c5138u: goto P_0c0c5138;
case 0x0c0c513au: goto P_0c0c513a;
case 0x0c0c513cu: goto P_0c0c513c;
case 0x0c0c513eu: goto P_0c0c513e;
case 0x0c0c5140u: goto P_0c0c5140;
case 0x0c0c5142u: goto P_0c0c5142;
case 0x0c0c5144u: goto P_0c0c5144;
case 0x0c0c5146u: goto P_0c0c5146;
case 0x0c0c5148u: goto P_0c0c5148;
case 0x0c0c514au: goto P_0c0c514a;
case 0x0c0c514cu: goto P_0c0c514c;
case 0x0c0c514eu: goto P_0c0c514e;
case 0x0c0c5150u: goto P_0c0c5150;
case 0x0c0c5152u: goto P_0c0c5152;
case 0x0c0c5154u: goto P_0c0c5154;
case 0x0c0c5156u: goto P_0c0c5156;
case 0x0c0c5158u: goto P_0c0c5158;
case 0x0c0c515au: goto P_0c0c515a;
case 0x0c0c515cu: goto P_0c0c515c;
case 0x0c0c515eu: goto P_0c0c515e;
case 0x0c0c5160u: goto P_0c0c5160;
case 0x0c0c5162u: goto P_0c0c5162;
case 0x0c0c5164u: goto P_0c0c5164;
case 0x0c0c5166u: goto P_0c0c5166;
case 0x0c0c5168u: goto P_0c0c5168;
case 0x0c0c516au: goto P_0c0c516a;
case 0x0c0c516cu: goto P_0c0c516c;
case 0x0c0c516eu: goto P_0c0c516e;
case 0x0c0c5170u: goto P_0c0c5170;
case 0x0c0c5172u: goto P_0c0c5172;
case 0x0c0c5174u: goto P_0c0c5174;
case 0x0c0c5176u: goto P_0c0c5176;
case 0x0c0c5178u: goto P_0c0c5178;
case 0x0c0c517au: goto P_0c0c517a;
case 0x0c0c517cu: goto P_0c0c517c;
case 0x0c0c517eu: goto P_0c0c517e;
case 0x0c0c5180u: goto P_0c0c5180;
case 0x0c0c5182u: goto P_0c0c5182;
case 0x0c0c5184u: goto P_0c0c5184;
case 0x0c0c5186u: goto P_0c0c5186;
case 0x0c0c5188u: goto P_0c0c5188;
case 0x0c0c518au: goto P_0c0c518a;
case 0x0c0c518cu: goto P_0c0c518c;
case 0x0c0c518eu: goto P_0c0c518e;
case 0x0c0c5190u: goto P_0c0c5190;
case 0x0c0c5192u: goto P_0c0c5192;
case 0x0c0c5194u: goto P_0c0c5194;
case 0x0c0c5196u: goto P_0c0c5196;
case 0x0c0c5198u: goto P_0c0c5198;
case 0x0c0c519au: goto P_0c0c519a;
case 0x0c0c519cu: goto P_0c0c519c;
case 0x0c0c519eu: goto P_0c0c519e;
case 0x0c0c51a0u: goto P_0c0c51a0;
case 0x0c0c51a2u: goto P_0c0c51a2;
case 0x0c0c51a4u: goto P_0c0c51a4;
case 0x0c0c51a6u: goto P_0c0c51a6;
case 0x0c0c51a8u: goto P_0c0c51a8;
case 0x0c0c51aau: goto P_0c0c51aa;
case 0x0c0c51acu: goto P_0c0c51ac;
case 0x0c0c51aeu: goto P_0c0c51ae;
case 0x0c0c51b0u: goto P_0c0c51b0;
case 0x0c0c51b2u: goto P_0c0c51b2;
case 0x0c0c51b4u: goto P_0c0c51b4;
case 0x0c0c51b6u: goto P_0c0c51b6;
case 0x0c0c51b8u: goto P_0c0c51b8;
case 0x0c0c51bau: goto P_0c0c51ba;
case 0x0c0c51bcu: goto P_0c0c51bc;
case 0x0c0c51beu: goto P_0c0c51be;
case 0x0c0c51c0u: goto P_0c0c51c0;
case 0x0c0c51c2u: goto P_0c0c51c2;
case 0x0c0c51c4u: goto P_0c0c51c4;
case 0x0c0c51c6u: goto P_0c0c51c6;
case 0x0c0c51c8u: goto P_0c0c51c8;
case 0x0c0c51cau: goto P_0c0c51ca;
case 0x0c0c51ccu: goto P_0c0c51cc;
case 0x0c0c51ceu: goto P_0c0c51ce;
case 0x0c0c51d0u: goto P_0c0c51d0;
case 0x0c0c5204u: goto P_0c0c5204;
case 0x0c0c5206u: goto P_0c0c5206;
case 0x0c0c5208u: goto P_0c0c5208;
case 0x0c0c520au: goto P_0c0c520a;
case 0x0c0c520cu: goto P_0c0c520c;
case 0x0c0c520eu: goto P_0c0c520e;
case 0x0c0c5210u: goto P_0c0c5210;
case 0x0c0c5212u: goto P_0c0c5212;
case 0x0c0c5214u: goto P_0c0c5214;
case 0x0c0c5216u: goto P_0c0c5216;
case 0x0c0c5218u: goto P_0c0c5218;
case 0x0c0c521au: goto P_0c0c521a;
case 0x0c0c521cu: goto P_0c0c521c;
case 0x0c0c521eu: goto P_0c0c521e;
case 0x0c0c5220u: goto P_0c0c5220;
case 0x0c0c5222u: goto P_0c0c5222;
case 0x0c0c5224u: goto P_0c0c5224;
case 0x0c0c5226u: goto P_0c0c5226;
case 0x0c0c5228u: goto P_0c0c5228;
case 0x0c0c522au: goto P_0c0c522a;
case 0x0c0c522cu: goto P_0c0c522c;
case 0x0c0c522eu: goto P_0c0c522e;
case 0x0c0c5230u: goto P_0c0c5230;
case 0x0c0c5232u: goto P_0c0c5232;
case 0x0c0c5234u: goto P_0c0c5234;
case 0x0c0c5236u: goto P_0c0c5236;
case 0x0c0c5238u: goto P_0c0c5238;
case 0x0c0c523au: goto P_0c0c523a;
case 0x0c0c523cu: goto P_0c0c523c;
case 0x0c0c523eu: goto P_0c0c523e;
case 0x0c0c5240u: goto P_0c0c5240;
case 0x0c0c5242u: goto P_0c0c5242;
case 0x0c0c5244u: goto P_0c0c5244;
case 0x0c0c5246u: goto P_0c0c5246;
case 0x0c0c5248u: goto P_0c0c5248;
case 0x0c0c524au: goto P_0c0c524a;
case 0x0c0c524cu: goto P_0c0c524c;
case 0x0c0c524eu: goto P_0c0c524e;
case 0x0c0c5250u: goto P_0c0c5250;
case 0x0c0c5252u: goto P_0c0c5252;
case 0x0c0c5254u: goto P_0c0c5254;
case 0x0c0c5256u: goto P_0c0c5256;
case 0x0c0c5258u: goto P_0c0c5258;
case 0x0c0c525au: goto P_0c0c525a;
case 0x0c0c525cu: goto P_0c0c525c;
case 0x0c0c525eu: goto P_0c0c525e;
case 0x0c0c5260u: goto P_0c0c5260;
case 0x0c0c5262u: goto P_0c0c5262;
case 0x0c0c5264u: goto P_0c0c5264;
case 0x0c0c5266u: goto P_0c0c5266;
case 0x0c0c5268u: goto P_0c0c5268;
case 0x0c0c526au: goto P_0c0c526a;
case 0x0c0c526cu: goto P_0c0c526c;
case 0x0c0c526eu: goto P_0c0c526e;
case 0x0c0c5270u: goto P_0c0c5270;
case 0x0c0c5272u: goto P_0c0c5272;
case 0x0c0c5274u: goto P_0c0c5274;
case 0x0c0c5276u: goto P_0c0c5276;
case 0x0c0c5278u: goto P_0c0c5278;
case 0x0c0c527au: goto P_0c0c527a;
case 0x0c0c527cu: goto P_0c0c527c;
case 0x0c0c527eu: goto P_0c0c527e;
case 0x0c0c5280u: goto P_0c0c5280;
case 0x0c0c5282u: goto P_0c0c5282;
case 0x0c0c5284u: goto P_0c0c5284;
case 0x0c0c5286u: goto P_0c0c5286;
case 0x0c0c5288u: goto P_0c0c5288;
case 0x0c0c528au: goto P_0c0c528a;
case 0x0c0c528cu: goto P_0c0c528c;
case 0x0c0c528eu: goto P_0c0c528e;
case 0x0c0c5290u: goto P_0c0c5290;
case 0x0c0c5292u: goto P_0c0c5292;
case 0x0c0c5294u: goto P_0c0c5294;
case 0x0c0c5296u: goto P_0c0c5296;
case 0x0c0c5298u: goto P_0c0c5298;
case 0x0c0c529au: goto P_0c0c529a;
case 0x0c0c529cu: goto P_0c0c529c;
case 0x0c0c529eu: goto P_0c0c529e;
case 0x0c0c52a0u: goto P_0c0c52a0;
case 0x0c0c52a2u: goto P_0c0c52a2;
case 0x0c0c52a4u: goto P_0c0c52a4;
case 0x0c0c52a6u: goto P_0c0c52a6;
case 0x0c0c52a8u: goto P_0c0c52a8;
case 0x0c0c52aau: goto P_0c0c52aa;
case 0x0c0c52acu: goto P_0c0c52ac;
case 0x0c0c52aeu: goto P_0c0c52ae;
case 0x0c0c52b0u: goto P_0c0c52b0;
case 0x0c0c52b2u: goto P_0c0c52b2;
case 0x0c0c52b4u: goto P_0c0c52b4;
case 0x0c0c52b6u: goto P_0c0c52b6;
case 0x0c0c52b8u: goto P_0c0c52b8;
case 0x0c0c52bau: goto P_0c0c52ba;
case 0x0c0c52bcu: goto P_0c0c52bc;
case 0x0c0c52beu: goto P_0c0c52be;
case 0x0c0c52c0u: goto P_0c0c52c0;
case 0x0c0c52c2u: goto P_0c0c52c2;
case 0x0c0c52c4u: goto P_0c0c52c4;
case 0x0c0c52c6u: goto P_0c0c52c6;
case 0x0c0c52c8u: goto P_0c0c52c8;
case 0x0c0c52cau: goto P_0c0c52ca;
case 0x0c0c52ccu: goto P_0c0c52cc;
case 0x0c0c52ceu: goto P_0c0c52ce;
case 0x0c0c52d0u: goto P_0c0c52d0;
case 0x0c0c52d2u: goto P_0c0c52d2;
case 0x0c0c52d4u: goto P_0c0c52d4;
case 0x0c0c52d6u: goto P_0c0c52d6;
case 0x0c0c52d8u: goto P_0c0c52d8;
case 0x0c0c52dau: goto P_0c0c52da;
case 0x0c0c52dcu: goto P_0c0c52dc;
case 0x0c0c52deu: goto P_0c0c52de;
case 0x0c0c52e0u: goto P_0c0c52e0;
case 0x0c0c52e2u: goto P_0c0c52e2;
case 0x0c0c52e4u: goto P_0c0c52e4;
case 0x0c0c52e6u: goto P_0c0c52e6;
case 0x0c0c52e8u: goto P_0c0c52e8;
case 0x0c0c52eau: goto P_0c0c52ea;
case 0x0c0c52ecu: goto P_0c0c52ec;
case 0x0c0c52eeu: goto P_0c0c52ee;
case 0x0c0c52f0u: goto P_0c0c52f0;
case 0x0c0c52f2u: goto P_0c0c52f2;
case 0x0c0c52f4u: goto P_0c0c52f4;
case 0x0c0c52f6u: goto P_0c0c52f6;
case 0x0c0c52f8u: goto P_0c0c52f8;
case 0x0c0c52fau: goto P_0c0c52fa;
case 0x0c0c52fcu: goto P_0c0c52fc;
case 0x0c0c52feu: goto P_0c0c52fe;
case 0x0c0c5300u: goto P_0c0c5300;
case 0x0c0c5302u: goto P_0c0c5302;
case 0x0c0c5304u: goto P_0c0c5304;
case 0x0c0c5306u: goto P_0c0c5306;
case 0x0c0c5308u: goto P_0c0c5308;
case 0x0c0c530au: goto P_0c0c530a;
case 0x0c0c530cu: goto P_0c0c530c;
case 0x0c0c530eu: goto P_0c0c530e;
case 0x0c0c5310u: goto P_0c0c5310;
case 0x0c0c5312u: goto P_0c0c5312;
case 0x0c0c5314u: goto P_0c0c5314;
case 0x0c0c5316u: goto P_0c0c5316;
case 0x0c0c5318u: goto P_0c0c5318;
case 0x0c0c531au: goto P_0c0c531a;
case 0x0c0c531cu: goto P_0c0c531c;
case 0x0c0c531eu: goto P_0c0c531e;
case 0x0c0c5320u: goto P_0c0c5320;
case 0x0c0c5322u: goto P_0c0c5322;
case 0x0c0c5324u: goto P_0c0c5324;
case 0x0c0c5326u: goto P_0c0c5326;
case 0x0c0c5328u: goto P_0c0c5328;
case 0x0c0c532au: goto P_0c0c532a;
case 0x0c0c532cu: goto P_0c0c532c;
case 0x0c0c532eu: goto P_0c0c532e;
case 0x0c0c5330u: goto P_0c0c5330;
case 0x0c0c5332u: goto P_0c0c5332;
case 0x0c0c5334u: goto P_0c0c5334;
case 0x0c0c5336u: goto P_0c0c5336;
case 0x0c0c5338u: goto P_0c0c5338;
case 0x0c0c533au: goto P_0c0c533a;
case 0x0c0c533cu: goto P_0c0c533c;
case 0x0c0c533eu: goto P_0c0c533e;
case 0x0c0c5340u: goto P_0c0c5340;
case 0x0c0c5342u: goto P_0c0c5342;
case 0x0c0c5344u: goto P_0c0c5344;
case 0x0c0c5346u: goto P_0c0c5346;
case 0x0c0c5348u: goto P_0c0c5348;
case 0x0c0c534au: goto P_0c0c534a;
case 0x0c0c534cu: goto P_0c0c534c;
case 0x0c0c534eu: goto P_0c0c534e;
case 0x0c0c5350u: goto P_0c0c5350;
case 0x0c0c5352u: goto P_0c0c5352;
case 0x0c0c5354u: goto P_0c0c5354;
case 0x0c0c5356u: goto P_0c0c5356;
case 0x0c0c5358u: goto P_0c0c5358;
case 0x0c0c535au: goto P_0c0c535a;
case 0x0c0c535cu: goto P_0c0c535c;
case 0x0c0c535eu: goto P_0c0c535e;
case 0x0c0c5360u: goto P_0c0c5360;
case 0x0c0c5362u: goto P_0c0c5362;
case 0x0c0c5364u: goto P_0c0c5364;
case 0x0c0c5366u: goto P_0c0c5366;
case 0x0c0c5368u: goto P_0c0c5368;
case 0x0c0c536au: goto P_0c0c536a;
case 0x0c0c536cu: goto P_0c0c536c;
case 0x0c0c536eu: goto P_0c0c536e;
case 0x0c0c5370u: goto P_0c0c5370;
case 0x0c0c5372u: goto P_0c0c5372;
case 0x0c0c5374u: goto P_0c0c5374;
case 0x0c0c5376u: goto P_0c0c5376;
case 0x0c0c5378u: goto P_0c0c5378;
case 0x0c0c537au: goto P_0c0c537a;
case 0x0c0c537cu: goto P_0c0c537c;
case 0x0c0c53acu: goto P_0c0c53ac;
case 0x0c0c53aeu: goto P_0c0c53ae;
case 0x0c0c53b0u: goto P_0c0c53b0;
case 0x0c0c53b2u: goto P_0c0c53b2;
case 0x0c0c53b4u: goto P_0c0c53b4;
case 0x0c0c53b6u: goto P_0c0c53b6;
case 0x0c0c53b8u: goto P_0c0c53b8;
case 0x0c0c53bau: goto P_0c0c53ba;
case 0x0c0c53bcu: goto P_0c0c53bc;
case 0x0c0c53beu: goto P_0c0c53be;
case 0x0c0c53c0u: goto P_0c0c53c0;
case 0x0c0c53c2u: goto P_0c0c53c2;
case 0x0c0c53c4u: goto P_0c0c53c4;
case 0x0c0c53c6u: goto P_0c0c53c6;
case 0x0c0c53c8u: goto P_0c0c53c8;
case 0x0c0c53cau: goto P_0c0c53ca;
case 0x0c0c53ccu: goto P_0c0c53cc;
case 0x0c0c53ceu: goto P_0c0c53ce;
case 0x0c0c53d0u: goto P_0c0c53d0;
case 0x0c0c53d2u: goto P_0c0c53d2;
case 0x0c0c53d4u: goto P_0c0c53d4;
case 0x0c0c53d6u: goto P_0c0c53d6;
case 0x0c0c53d8u: goto P_0c0c53d8;
case 0x0c0c53dau: goto P_0c0c53da;
case 0x0c0c53dcu: goto P_0c0c53dc;
case 0x0c0c53deu: goto P_0c0c53de;
case 0x0c0c53e0u: goto P_0c0c53e0;
case 0x0c0c53e2u: goto P_0c0c53e2;
case 0x0c0c53e4u: goto P_0c0c53e4;
case 0x0c0c53e6u: goto P_0c0c53e6;
case 0x0c0c53e8u: goto P_0c0c53e8;
case 0x0c0c53eau: goto P_0c0c53ea;
case 0x0c0c53ecu: goto P_0c0c53ec;
case 0x0c0c53eeu: goto P_0c0c53ee;
case 0x0c0c53f0u: goto P_0c0c53f0;
case 0x0c0c53f2u: goto P_0c0c53f2;
case 0x0c0c53f4u: goto P_0c0c53f4;
case 0x0c0c53f6u: goto P_0c0c53f6;
case 0x0c0c53f8u: goto P_0c0c53f8;
case 0x0c0c53fau: goto P_0c0c53fa;
case 0x0c0c53fcu: goto P_0c0c53fc;
case 0x0c0c53feu: goto P_0c0c53fe;
case 0x0c0c5400u: goto P_0c0c5400;
case 0x0c0c5402u: goto P_0c0c5402;
case 0x0c0c5404u: goto P_0c0c5404;
case 0x0c0c5406u: goto P_0c0c5406;
case 0x0c0c5408u: goto P_0c0c5408;
case 0x0c0c540au: goto P_0c0c540a;
case 0x0c0c540cu: goto P_0c0c540c;
case 0x0c0c540eu: goto P_0c0c540e;
case 0x0c0c5410u: goto P_0c0c5410;
case 0x0c0c5412u: goto P_0c0c5412;
case 0x0c0c5414u: goto P_0c0c5414;
case 0x0c0c5416u: goto P_0c0c5416;
case 0x0c0c5418u: goto P_0c0c5418;
case 0x0c0c541au: goto P_0c0c541a;
case 0x0c0c541cu: goto P_0c0c541c;
case 0x0c0c541eu: goto P_0c0c541e;
case 0x0c0c5420u: goto P_0c0c5420;
case 0x0c0c5422u: goto P_0c0c5422;
case 0x0c0c5424u: goto P_0c0c5424;
case 0x0c0c5426u: goto P_0c0c5426;
case 0x0c0c5428u: goto P_0c0c5428;
case 0x0c0c542au: goto P_0c0c542a;
case 0x0c0c542cu: goto P_0c0c542c;
case 0x0c0c542eu: goto P_0c0c542e;
case 0x0c0c5430u: goto P_0c0c5430;
case 0x0c0c5432u: goto P_0c0c5432;
case 0x0c0c5434u: goto P_0c0c5434;
case 0x0c0c5436u: goto P_0c0c5436;
case 0x0c0c5438u: goto P_0c0c5438;
case 0x0c0c543au: goto P_0c0c543a;
case 0x0c0c543cu: goto P_0c0c543c;
case 0x0c0c543eu: goto P_0c0c543e;
case 0x0c0c5440u: goto P_0c0c5440;
case 0x0c0c5442u: goto P_0c0c5442;
case 0x0c0c5444u: goto P_0c0c5444;
case 0x0c0c5446u: goto P_0c0c5446;
case 0x0c0c5448u: goto P_0c0c5448;
case 0x0c0c544au: goto P_0c0c544a;
case 0x0c0c544cu: goto P_0c0c544c;
case 0x0c0c544eu: goto P_0c0c544e;
case 0x0c0c5450u: goto P_0c0c5450;
case 0x0c0c5452u: goto P_0c0c5452;
case 0x0c0c5454u: goto P_0c0c5454;
case 0x0c0c5456u: goto P_0c0c5456;
case 0x0c0c5458u: goto P_0c0c5458;
case 0x0c0c545au: goto P_0c0c545a;
case 0x0c0c545cu: goto P_0c0c545c;
case 0x0c0c545eu: goto P_0c0c545e;
case 0x0c0c5460u: goto P_0c0c5460;
case 0x0c0c5462u: goto P_0c0c5462;
case 0x0c0c5464u: goto P_0c0c5464;
case 0x0c0c5466u: goto P_0c0c5466;
case 0x0c0c5468u: goto P_0c0c5468;
case 0x0c0c546au: goto P_0c0c546a;
case 0x0c0c546cu: goto P_0c0c546c;
case 0x0c0c546eu: goto P_0c0c546e;
case 0x0c0c5470u: goto P_0c0c5470;
case 0x0c0c5472u: goto P_0c0c5472;
case 0x0c0c5474u: goto P_0c0c5474;
case 0x0c0c5476u: goto P_0c0c5476;
case 0x0c0c5478u: goto P_0c0c5478;
case 0x0c0c547au: goto P_0c0c547a;
case 0x0c0c547cu: goto P_0c0c547c;
case 0x0c0c547eu: goto P_0c0c547e;
case 0x0c0c5480u: goto P_0c0c5480;
case 0x0c0c5482u: goto P_0c0c5482;
case 0x0c0c5484u: goto P_0c0c5484;
case 0x0c0c5486u: goto P_0c0c5486;
case 0x0c0c5488u: goto P_0c0c5488;
case 0x0c0c548au: goto P_0c0c548a;
case 0x0c0c548cu: goto P_0c0c548c;
case 0x0c0c548eu: goto P_0c0c548e;
case 0x0c0c5490u: goto P_0c0c5490;
case 0x0c0c5492u: goto P_0c0c5492;
case 0x0c0c5494u: goto P_0c0c5494;
case 0x0c0c5496u: goto P_0c0c5496;
case 0x0c0c5498u: goto P_0c0c5498;
case 0x0c0c549au: goto P_0c0c549a;
case 0x0c0c549cu: goto P_0c0c549c;
case 0x0c0c549eu: goto P_0c0c549e;
case 0x0c0c54a0u: goto P_0c0c54a0;
case 0x0c0c54a2u: goto P_0c0c54a2;
case 0x0c0c54a4u: goto P_0c0c54a4;
case 0x0c0c54a6u: goto P_0c0c54a6;
case 0x0c0c54a8u: goto P_0c0c54a8;
case 0x0c0c54aau: goto P_0c0c54aa;
case 0x0c0c54acu: goto P_0c0c54ac;
case 0x0c0c54aeu: goto P_0c0c54ae;
case 0x0c0c54b0u: goto P_0c0c54b0;
case 0x0c0c54b2u: goto P_0c0c54b2;
case 0x0c0c54b4u: goto P_0c0c54b4;
case 0x0c0c54b6u: goto P_0c0c54b6;
case 0x0c0c54b8u: goto P_0c0c54b8;
case 0x0c0c54bau: goto P_0c0c54ba;
case 0x0c0c54bcu: goto P_0c0c54bc;
case 0x0c0c54beu: goto P_0c0c54be;
case 0x0c0c54c0u: goto P_0c0c54c0;
case 0x0c0c54c2u: goto P_0c0c54c2;
case 0x0c0c54c4u: goto P_0c0c54c4;
case 0x0c0c54c6u: goto P_0c0c54c6;
case 0x0c0c54c8u: goto P_0c0c54c8;
case 0x0c0c54cau: goto P_0c0c54ca;
case 0x0c0c54ccu: goto P_0c0c54cc;
case 0x0c0c54ceu: goto P_0c0c54ce;
case 0x0c0c54d0u: goto P_0c0c54d0;
case 0x0c0c54d2u: goto P_0c0c54d2;
case 0x0c0c54d4u: goto P_0c0c54d4;
case 0x0c0c54d6u: goto P_0c0c54d6;
case 0x0c0c54d8u: goto P_0c0c54d8;
case 0x0c0c54dau: goto P_0c0c54da;
case 0x0c0c54dcu: goto P_0c0c54dc;
case 0x0c0c54deu: goto P_0c0c54de;
case 0x0c0c54e0u: goto P_0c0c54e0;
case 0x0c0c54e2u: goto P_0c0c54e2;
case 0x0c0c54e4u: goto P_0c0c54e4;
case 0x0c0c54e6u: goto P_0c0c54e6;
case 0x0c0c54e8u: goto P_0c0c54e8;
case 0x0c0c54eau: goto P_0c0c54ea;
case 0x0c0c54ecu: goto P_0c0c54ec;
case 0x0c0c54eeu: goto P_0c0c54ee;
case 0x0c0c54f0u: goto P_0c0c54f0;
case 0x0c0c54f2u: goto P_0c0c54f2;
case 0x0c0c54f4u: goto P_0c0c54f4;
case 0x0c0c54f6u: goto P_0c0c54f6;
case 0x0c0c54f8u: goto P_0c0c54f8;
case 0x0c0c54fau: goto P_0c0c54fa;
case 0x0c0c54fcu: goto P_0c0c54fc;
case 0x0c0c54feu: goto P_0c0c54fe;
case 0x0c0c5500u: goto P_0c0c5500;
case 0x0c0c5502u: goto P_0c0c5502;
case 0x0c0c5504u: goto P_0c0c5504;
case 0x0c0c5506u: goto P_0c0c5506;
case 0x0c0c5508u: goto P_0c0c5508;
case 0x0c0c550au: goto P_0c0c550a;
case 0x0c0c550cu: goto P_0c0c550c;
case 0x0c0c550eu: goto P_0c0c550e;
case 0x0c0c5510u: goto P_0c0c5510;
case 0x0c0c5512u: goto P_0c0c5512;
case 0x0c0c5514u: goto P_0c0c5514;
case 0x0c0c5516u: goto P_0c0c5516;
case 0x0c0c5518u: goto P_0c0c5518;
case 0x0c0c551au: goto P_0c0c551a;
case 0x0c0c5558u: goto P_0c0c5558;
case 0x0c0c555au: goto P_0c0c555a;
case 0x0c0c555cu: goto P_0c0c555c;
case 0x0c0c555eu: goto P_0c0c555e;
case 0x0c0c5560u: goto P_0c0c5560;
case 0x0c0c5562u: goto P_0c0c5562;
case 0x0c0c5564u: goto P_0c0c5564;
case 0x0c0c5566u: goto P_0c0c5566;
case 0x0c0c5568u: goto P_0c0c5568;
case 0x0c0c556au: goto P_0c0c556a;
case 0x0c0c556cu: goto P_0c0c556c;
case 0x0c0c556eu: goto P_0c0c556e;
case 0x0c0c5570u: goto P_0c0c5570;
case 0x0c0c5572u: goto P_0c0c5572;
case 0x0c0c5574u: goto P_0c0c5574;
case 0x0c0c5576u: goto P_0c0c5576;
case 0x0c0c5578u: goto P_0c0c5578;
case 0x0c0c557au: goto P_0c0c557a;
case 0x0c0c557cu: goto P_0c0c557c;
case 0x0c0c557eu: goto P_0c0c557e;
case 0x0c0c5580u: goto P_0c0c5580;
case 0x0c0c5582u: goto P_0c0c5582;
case 0x0c0c5584u: goto P_0c0c5584;
case 0x0c0c5586u: goto P_0c0c5586;
case 0x0c0c5588u: goto P_0c0c5588;
case 0x0c0c558au: goto P_0c0c558a;
case 0x0c0c558cu: goto P_0c0c558c;
case 0x0c0c558eu: goto P_0c0c558e;
case 0x0c0c5590u: goto P_0c0c5590;
case 0x0c0c5592u: goto P_0c0c5592;
case 0x0c0c5594u: goto P_0c0c5594;
case 0x0c0c5596u: goto P_0c0c5596;
case 0x0c0c5598u: goto P_0c0c5598;
case 0x0c0c559au: goto P_0c0c559a;
case 0x0c0c559cu: goto P_0c0c559c;
case 0x0c0c559eu: goto P_0c0c559e;
case 0x0c0c55a0u: goto P_0c0c55a0;
case 0x0c0c55a2u: goto P_0c0c55a2;
case 0x0c0c55a4u: goto P_0c0c55a4;
case 0x0c0c55a6u: goto P_0c0c55a6;
case 0x0c0c55a8u: goto P_0c0c55a8;
case 0x0c0c55aau: goto P_0c0c55aa;
case 0x0c0c55acu: goto P_0c0c55ac;
case 0x0c0c55aeu: goto P_0c0c55ae;
case 0x0c0c55b0u: goto P_0c0c55b0;
case 0x0c0c55b2u: goto P_0c0c55b2;
case 0x0c0c55b4u: goto P_0c0c55b4;
case 0x0c0c55b6u: goto P_0c0c55b6;
case 0x0c0c55b8u: goto P_0c0c55b8;
case 0x0c0c55bau: goto P_0c0c55ba;
case 0x0c0c55bcu: goto P_0c0c55bc;
case 0x0c0c55beu: goto P_0c0c55be;
case 0x0c0c55c0u: goto P_0c0c55c0;
case 0x0c0c55c2u: goto P_0c0c55c2;
case 0x0c0c55c4u: goto P_0c0c55c4;
case 0x0c0c55c6u: goto P_0c0c55c6;
case 0x0c0c55c8u: goto P_0c0c55c8;
case 0x0c0c55cau: goto P_0c0c55ca;
case 0x0c0c55ccu: goto P_0c0c55cc;
case 0x0c0c55ceu: goto P_0c0c55ce;
case 0x0c0c55d0u: goto P_0c0c55d0;
case 0x0c0c55d2u: goto P_0c0c55d2;
case 0x0c0c55d4u: goto P_0c0c55d4;
case 0x0c0c55d6u: goto P_0c0c55d6;
case 0x0c0c55d8u: goto P_0c0c55d8;
case 0x0c0c55dau: goto P_0c0c55da;
case 0x0c0c55dcu: goto P_0c0c55dc;
case 0x0c0c55deu: goto P_0c0c55de;
case 0x0c0c55e0u: goto P_0c0c55e0;
case 0x0c0c55e2u: goto P_0c0c55e2;
case 0x0c0c55e4u: goto P_0c0c55e4;
case 0x0c0c55e6u: goto P_0c0c55e6;
case 0x0c0c55e8u: goto P_0c0c55e8;
case 0x0c0c5604u: goto P_0c0c5604;
case 0x0c0c5606u: goto P_0c0c5606;
case 0x0c0c5608u: goto P_0c0c5608;
case 0x0c0c560au: goto P_0c0c560a;
case 0x0c0c560cu: goto P_0c0c560c;
case 0x0c0c560eu: goto P_0c0c560e;
case 0x0c0c5610u: goto P_0c0c5610;
case 0x0c0c5612u: goto P_0c0c5612;
case 0x0c0c5614u: goto P_0c0c5614;
case 0x0c0c5616u: goto P_0c0c5616;
case 0x0c0c5618u: goto P_0c0c5618;
case 0x0c0c561au: goto P_0c0c561a;
case 0x0c0c561cu: goto P_0c0c561c;
case 0x0c0c561eu: goto P_0c0c561e;
case 0x0c0c5620u: goto P_0c0c5620;
case 0x0c0c5622u: goto P_0c0c5622;
case 0x0c0c5624u: goto P_0c0c5624;
case 0x0c0c5626u: goto P_0c0c5626;
case 0x0c0c5628u: goto P_0c0c5628;
case 0x0c0c562au: goto P_0c0c562a;
case 0x0c0c562cu: goto P_0c0c562c;
case 0x0c0c562eu: goto P_0c0c562e;
case 0x0c0c5630u: goto P_0c0c5630;
case 0x0c0c5632u: goto P_0c0c5632;
case 0x0c0c5634u: goto P_0c0c5634;
case 0x0c0c5636u: goto P_0c0c5636;
case 0x0c0c5638u: goto P_0c0c5638;
case 0x0c0c563au: goto P_0c0c563a;
case 0x0c0c563cu: goto P_0c0c563c;
case 0x0c0c563eu: goto P_0c0c563e;
case 0x0c0c5640u: goto P_0c0c5640;
case 0x0c0c5642u: goto P_0c0c5642;
case 0x0c0c5644u: goto P_0c0c5644;
case 0x0c0c5646u: goto P_0c0c5646;
case 0x0c0c5648u: goto P_0c0c5648;
case 0x0c0c564au: goto P_0c0c564a;
case 0x0c0c564cu: goto P_0c0c564c;
case 0x0c0c564eu: goto P_0c0c564e;
case 0x0c0c5650u: goto P_0c0c5650;
case 0x0c0c5652u: goto P_0c0c5652;
case 0x0c0c5654u: goto P_0c0c5654;
case 0x0c0c5656u: goto P_0c0c5656;
case 0x0c0c5658u: goto P_0c0c5658;
case 0x0c0c565au: goto P_0c0c565a;
case 0x0c0c565cu: goto P_0c0c565c;
case 0x0c0c565eu: goto P_0c0c565e;
case 0x0c0c5660u: goto P_0c0c5660;
case 0x0c0c5662u: goto P_0c0c5662;
case 0x0c0c5664u: goto P_0c0c5664;
case 0x0c0c5666u: goto P_0c0c5666;
case 0x0c0c5668u: goto P_0c0c5668;
case 0x0c0c566au: goto P_0c0c566a;
case 0x0c0c566cu: goto P_0c0c566c;
case 0x0c0c566eu: goto P_0c0c566e;
case 0x0c0c5670u: goto P_0c0c5670;
case 0x0c0c5672u: goto P_0c0c5672;
case 0x0c0c5674u: goto P_0c0c5674;
case 0x0c0c5676u: goto P_0c0c5676;
case 0x0c0c5678u: goto P_0c0c5678;
case 0x0c0c567au: goto P_0c0c567a;
case 0x0c0c567cu: goto P_0c0c567c;
case 0x0c0c567eu: goto P_0c0c567e;
case 0x0c0c5680u: goto P_0c0c5680;
case 0x0c0c5682u: goto P_0c0c5682;
case 0x0c0c5684u: goto P_0c0c5684;
case 0x0c0c5686u: goto P_0c0c5686;
case 0x0c0c5688u: goto P_0c0c5688;
case 0x0c0c568au: goto P_0c0c568a;
case 0x0c0c568cu: goto P_0c0c568c;
case 0x0c0c568eu: goto P_0c0c568e;
case 0x0c0c5690u: goto P_0c0c5690;
case 0x0c0c5692u: goto P_0c0c5692;
case 0x0c0c5694u: goto P_0c0c5694;
case 0x0c0c5696u: goto P_0c0c5696;
case 0x0c0c5698u: goto P_0c0c5698;
case 0x0c0c569au: goto P_0c0c569a;
case 0x0c0c569cu: goto P_0c0c569c;
case 0x0c0c569eu: goto P_0c0c569e;
case 0x0c0c56a0u: goto P_0c0c56a0;
case 0x0c0c56a2u: goto P_0c0c56a2;
case 0x0c0c56a4u: goto P_0c0c56a4;
case 0x0c0c56a6u: goto P_0c0c56a6;
case 0x0c0c56a8u: goto P_0c0c56a8;
case 0x0c0c56aau: goto P_0c0c56aa;
case 0x0c0c56acu: goto P_0c0c56ac;
case 0x0c0c56aeu: goto P_0c0c56ae;
case 0x0c0c56b0u: goto P_0c0c56b0;
case 0x0c0c56b2u: goto P_0c0c56b2;
case 0x0c0c56b4u: goto P_0c0c56b4;
case 0x0c0c56b6u: goto P_0c0c56b6;
case 0x0c0c56b8u: goto P_0c0c56b8;
case 0x0c0c56bau: goto P_0c0c56ba;
case 0x0c0c56bcu: goto P_0c0c56bc;
case 0x0c0c56beu: goto P_0c0c56be;
case 0x0c0c56c0u: goto P_0c0c56c0;
case 0x0c0c56c2u: goto P_0c0c56c2;
case 0x0c0c56c4u: goto P_0c0c56c4;
case 0x0c0c56c6u: goto P_0c0c56c6;
case 0x0c0c56c8u: goto P_0c0c56c8;
case 0x0c0c56cau: goto P_0c0c56ca;
case 0x0c0c56ccu: goto P_0c0c56cc;
case 0x0c0c56ceu: goto P_0c0c56ce;
case 0x0c0c56d0u: goto P_0c0c56d0;
case 0x0c0c56d2u: goto P_0c0c56d2;
case 0x0c0c56d4u: goto P_0c0c56d4;
case 0x0c0c56d6u: goto P_0c0c56d6;
case 0x0c0c56d8u: goto P_0c0c56d8;
case 0x0c0c56dau: goto P_0c0c56da;
case 0x0c0c56dcu: goto P_0c0c56dc;
case 0x0c0c56deu: goto P_0c0c56de;
case 0x0c0c56e0u: goto P_0c0c56e0;
case 0x0c0c56e2u: goto P_0c0c56e2;
case 0x0c0c56e4u: goto P_0c0c56e4;
case 0x0c0c56e6u: goto P_0c0c56e6;
case 0x0c0c56e8u: goto P_0c0c56e8;
case 0x0c0c56eau: goto P_0c0c56ea;
case 0x0c0c56ecu: goto P_0c0c56ec;
case 0x0c0c56eeu: goto P_0c0c56ee;
case 0x0c0c56f0u: goto P_0c0c56f0;
case 0x0c0c56f2u: goto P_0c0c56f2;
case 0x0c0c56f4u: goto P_0c0c56f4;
case 0x0c0c56f6u: goto P_0c0c56f6;
case 0x0c0c56f8u: goto P_0c0c56f8;
case 0x0c0c56fau: goto P_0c0c56fa;
case 0x0c0c56fcu: goto P_0c0c56fc;
case 0x0c0c56feu: goto P_0c0c56fe;
case 0x0c0c5700u: goto P_0c0c5700;
case 0x0c0c5702u: goto P_0c0c5702;
case 0x0c0c5704u: goto P_0c0c5704;
case 0x0c0c5706u: goto P_0c0c5706;
case 0x0c0c5708u: goto P_0c0c5708;
case 0x0c0c570au: goto P_0c0c570a;
case 0x0c0c570cu: goto P_0c0c570c;
case 0x0c0c570eu: goto P_0c0c570e;
case 0x0c0c5710u: goto P_0c0c5710;
case 0x0c0c5712u: goto P_0c0c5712;
case 0x0c0c5714u: goto P_0c0c5714;
case 0x0c0c5716u: goto P_0c0c5716;
case 0x0c0c5718u: goto P_0c0c5718;
case 0x0c0c571au: goto P_0c0c571a;
case 0x0c0c571cu: goto P_0c0c571c;
case 0x0c0c571eu: goto P_0c0c571e;
case 0x0c0c5720u: goto P_0c0c5720;
case 0x0c0c5722u: goto P_0c0c5722;
case 0x0c0c5724u: goto P_0c0c5724;
case 0x0c0c5726u: goto P_0c0c5726;
case 0x0c0c5728u: goto P_0c0c5728;
case 0x0c0c572au: goto P_0c0c572a;
case 0x0c0c572cu: goto P_0c0c572c;
case 0x0c0c572eu: goto P_0c0c572e;
case 0x0c0c5730u: goto P_0c0c5730;
case 0x0c0c5732u: goto P_0c0c5732;
case 0x0c0c5734u: goto P_0c0c5734;
case 0x0c0c5736u: goto P_0c0c5736;
case 0x0c0c5738u: goto P_0c0c5738;
case 0x0c0c573au: goto P_0c0c573a;
case 0x0c0c573cu: goto P_0c0c573c;
case 0x0c0c573eu: goto P_0c0c573e;
case 0x0c0c5740u: goto P_0c0c5740;
case 0x0c0c5742u: goto P_0c0c5742;
case 0x0c0c5744u: goto P_0c0c5744;
case 0x0c0c5746u: goto P_0c0c5746;
case 0x0c0c5748u: goto P_0c0c5748;
case 0x0c0c574au: goto P_0c0c574a;
case 0x0c0c574cu: goto P_0c0c574c;
case 0x0c0c574eu: goto P_0c0c574e;
case 0x0c0c5750u: goto P_0c0c5750;
case 0x0c0c5752u: goto P_0c0c5752;
case 0x0c0c5754u: goto P_0c0c5754;
case 0x0c0c5756u: goto P_0c0c5756;
case 0x0c0c5758u: goto P_0c0c5758;
case 0x0c0c575au: goto P_0c0c575a;
case 0x0c0c575cu: goto P_0c0c575c;
case 0x0c0c575eu: goto P_0c0c575e;
case 0x0c0c5760u: goto P_0c0c5760;
case 0x0c0c5762u: goto P_0c0c5762;
case 0x0c0c5764u: goto P_0c0c5764;
case 0x0c0c57b0u: goto P_0c0c57b0;
case 0x0c0c57b2u: goto P_0c0c57b2;
case 0x0c0c57b4u: goto P_0c0c57b4;
case 0x0c0c57b6u: goto P_0c0c57b6;
case 0x0c0c57b8u: goto P_0c0c57b8;
case 0x0c0c57bau: goto P_0c0c57ba;
case 0x0c0c57bcu: goto P_0c0c57bc;
case 0x0c0c57beu: goto P_0c0c57be;
case 0x0c0c57c0u: goto P_0c0c57c0;
case 0x0c0c57c2u: goto P_0c0c57c2;
case 0x0c0c57c4u: goto P_0c0c57c4;
case 0x0c0c57c6u: goto P_0c0c57c6;
case 0x0c0c57c8u: goto P_0c0c57c8;
case 0x0c0c57cau: goto P_0c0c57ca;
case 0x0c0c57ccu: goto P_0c0c57cc;
case 0x0c0c57ceu: goto P_0c0c57ce;
case 0x0c0c57d0u: goto P_0c0c57d0;
case 0x0c0c57d2u: goto P_0c0c57d2;
case 0x0c0c57d4u: goto P_0c0c57d4;
case 0x0c0c57d6u: goto P_0c0c57d6;
case 0x0c0c57d8u: goto P_0c0c57d8;
case 0x0c0c57dau: goto P_0c0c57da;
case 0x0c0c57dcu: goto P_0c0c57dc;
case 0x0c0c57deu: goto P_0c0c57de;
case 0x0c0c57e0u: goto P_0c0c57e0;
case 0x0c0c57e2u: goto P_0c0c57e2;
case 0x0c0c57e4u: goto P_0c0c57e4;
case 0x0c0c57e6u: goto P_0c0c57e6;
case 0x0c0c57e8u: goto P_0c0c57e8;
case 0x0c0c57eau: goto P_0c0c57ea;
case 0x0c0c57ecu: goto P_0c0c57ec;
case 0x0c0c57eeu: goto P_0c0c57ee;
case 0x0c0c57f0u: goto P_0c0c57f0;
case 0x0c0c57f2u: goto P_0c0c57f2;
case 0x0c0c57f4u: goto P_0c0c57f4;
case 0x0c0c57f6u: goto P_0c0c57f6;
case 0x0c0c57f8u: goto P_0c0c57f8;
case 0x0c0c57fau: goto P_0c0c57fa;
case 0x0c0c57fcu: goto P_0c0c57fc;
case 0x0c0c57feu: goto P_0c0c57fe;
case 0x0c0c5800u: goto P_0c0c5800;
case 0x0c0c5802u: goto P_0c0c5802;
case 0x0c0c5804u: goto P_0c0c5804;
case 0x0c0c5806u: goto P_0c0c5806;
case 0x0c0c5808u: goto P_0c0c5808;
case 0x0c0c580au: goto P_0c0c580a;
case 0x0c0c580cu: goto P_0c0c580c;
case 0x0c0c580eu: goto P_0c0c580e;
case 0x0c0c5810u: goto P_0c0c5810;
case 0x0c0c5812u: goto P_0c0c5812;
case 0x0c0c5814u: goto P_0c0c5814;
case 0x0c0c5816u: goto P_0c0c5816;
case 0x0c0c5818u: goto P_0c0c5818;
case 0x0c0c581au: goto P_0c0c581a;
case 0x0c0c581cu: goto P_0c0c581c;
case 0x0c0c581eu: goto P_0c0c581e;
case 0x0c0c5820u: goto P_0c0c5820;
case 0x0c0c5822u: goto P_0c0c5822;
case 0x0c0c5824u: goto P_0c0c5824;
case 0x0c0c5826u: goto P_0c0c5826;
case 0x0c0c5828u: goto P_0c0c5828;
case 0x0c0c582au: goto P_0c0c582a;
case 0x0c0c582cu: goto P_0c0c582c;
case 0x0c0c582eu: goto P_0c0c582e;
case 0x0c0c5830u: goto P_0c0c5830;
case 0x0c0c5832u: goto P_0c0c5832;
case 0x0c0c5834u: goto P_0c0c5834;
case 0x0c0c5836u: goto P_0c0c5836;
case 0x0c0c5838u: goto P_0c0c5838;
case 0x0c0c583au: goto P_0c0c583a;
case 0x0c0c583cu: goto P_0c0c583c;
case 0x0c0c583eu: goto P_0c0c583e;
case 0x0c0c5840u: goto P_0c0c5840;
case 0x0c0c5842u: goto P_0c0c5842;
case 0x0c0c5844u: goto P_0c0c5844;
case 0x0c0c5846u: goto P_0c0c5846;
case 0x0c0c5848u: goto P_0c0c5848;
case 0x0c0c584au: goto P_0c0c584a;
case 0x0c0c584cu: goto P_0c0c584c;
case 0x0c0c584eu: goto P_0c0c584e;
case 0x0c0c5850u: goto P_0c0c5850;
case 0x0c0c5852u: goto P_0c0c5852;
case 0x0c0c5854u: goto P_0c0c5854;
case 0x0c0c5856u: goto P_0c0c5856;
case 0x0c0c5858u: goto P_0c0c5858;
case 0x0c0c585au: goto P_0c0c585a;
case 0x0c0c585cu: goto P_0c0c585c;
case 0x0c0c585eu: goto P_0c0c585e;
case 0x0c0c5860u: goto P_0c0c5860;
case 0x0c0c5862u: goto P_0c0c5862;
case 0x0c0c5864u: goto P_0c0c5864;
case 0x0c0c5866u: goto P_0c0c5866;
case 0x0c0c5868u: goto P_0c0c5868;
case 0x0c0c586au: goto P_0c0c586a;
case 0x0c0c586cu: goto P_0c0c586c;
case 0x0c0c586eu: goto P_0c0c586e;
case 0x0c0c5870u: goto P_0c0c5870;
case 0x0c0c5872u: goto P_0c0c5872;
case 0x0c0c5874u: goto P_0c0c5874;
case 0x0c0c5876u: goto P_0c0c5876;
case 0x0c0c5878u: goto P_0c0c5878;
case 0x0c0c587au: goto P_0c0c587a;
case 0x0c0c587cu: goto P_0c0c587c;
case 0x0c0c587eu: goto P_0c0c587e;
case 0x0c0c5880u: goto P_0c0c5880;
case 0x0c0c5882u: goto P_0c0c5882;
case 0x0c0c5884u: goto P_0c0c5884;
case 0x0c0c5886u: goto P_0c0c5886;
case 0x0c0c5888u: goto P_0c0c5888;
case 0x0c0c588au: goto P_0c0c588a;
case 0x0c0c588cu: goto P_0c0c588c;
case 0x0c0c588eu: goto P_0c0c588e;
case 0x0c0c5890u: goto P_0c0c5890;
case 0x0c0c5892u: goto P_0c0c5892;
case 0x0c0c5894u: goto P_0c0c5894;
case 0x0c0c5896u: goto P_0c0c5896;
case 0x0c0c5898u: goto P_0c0c5898;
case 0x0c0c589au: goto P_0c0c589a;
case 0x0c0c589cu: goto P_0c0c589c;
case 0x0c0c589eu: goto P_0c0c589e;
case 0x0c0c58a0u: goto P_0c0c58a0;
case 0x0c0c58a2u: goto P_0c0c58a2;
case 0x0c0c58a4u: goto P_0c0c58a4;
case 0x0c0c58a6u: goto P_0c0c58a6;
case 0x0c0c58a8u: goto P_0c0c58a8;
case 0x0c0c58aau: goto P_0c0c58aa;
case 0x0c0c58acu: goto P_0c0c58ac;
case 0x0c0c58aeu: goto P_0c0c58ae;
case 0x0c0c58b0u: goto P_0c0c58b0;
case 0x0c0c58b2u: goto P_0c0c58b2;
case 0x0c0c58b4u: goto P_0c0c58b4;
case 0x0c0c58b6u: goto P_0c0c58b6;
case 0x0c0c58b8u: goto P_0c0c58b8;
case 0x0c0c58bau: goto P_0c0c58ba;
case 0x0c0c58bcu: goto P_0c0c58bc;
case 0x0c0c58beu: goto P_0c0c58be;
case 0x0c0c58c0u: goto P_0c0c58c0;
case 0x0c0c58c2u: goto P_0c0c58c2;
case 0x0c0c58c4u: goto P_0c0c58c4;
case 0x0c0c58c6u: goto P_0c0c58c6;
case 0x0c0c58c8u: goto P_0c0c58c8;
case 0x0c0c58cau: goto P_0c0c58ca;
case 0x0c0c58ccu: goto P_0c0c58cc;
case 0x0c0c58ceu: goto P_0c0c58ce;
case 0x0c0c58d0u: goto P_0c0c58d0;
case 0x0c0c58d2u: goto P_0c0c58d2;
case 0x0c0c58d4u: goto P_0c0c58d4;
case 0x0c0c58d6u: goto P_0c0c58d6;
case 0x0c0c58d8u: goto P_0c0c58d8;
case 0x0c0c58dau: goto P_0c0c58da;
case 0x0c0c58dcu: goto P_0c0c58dc;
case 0x0c0c58deu: goto P_0c0c58de;
case 0x0c0c58e0u: goto P_0c0c58e0;
case 0x0c0c58e2u: goto P_0c0c58e2;
case 0x0c0c58e4u: goto P_0c0c58e4;
case 0x0c0c58e6u: goto P_0c0c58e6;
case 0x0c0c58e8u: goto P_0c0c58e8;
case 0x0c0c58eau: goto P_0c0c58ea;
case 0x0c0c58ecu: goto P_0c0c58ec;
case 0x0c0c58eeu: goto P_0c0c58ee;
case 0x0c0c58f0u: goto P_0c0c58f0;
case 0x0c0c58f2u: goto P_0c0c58f2;
case 0x0c0c58f4u: goto P_0c0c58f4;
case 0x0c0c58f6u: goto P_0c0c58f6;
case 0x0c0c58f8u: goto P_0c0c58f8;
case 0x0c0c58fau: goto P_0c0c58fa;
case 0x0c0c58fcu: goto P_0c0c58fc;
case 0x0c0c5938u: goto P_0c0c5938;
case 0x0c0c593au: goto P_0c0c593a;
case 0x0c0c593cu: goto P_0c0c593c;
case 0x0c0c593eu: goto P_0c0c593e;
case 0x0c0c5940u: goto P_0c0c5940;
case 0x0c0c5942u: goto P_0c0c5942;
case 0x0c0c5944u: goto P_0c0c5944;
case 0x0c0c5946u: goto P_0c0c5946;
case 0x0c0c5948u: goto P_0c0c5948;
case 0x0c0c594au: goto P_0c0c594a;
case 0x0c0c594cu: goto P_0c0c594c;
case 0x0c0c594eu: goto P_0c0c594e;
case 0x0c0c5950u: goto P_0c0c5950;
case 0x0c0c5952u: goto P_0c0c5952;
case 0x0c0c5954u: goto P_0c0c5954;
case 0x0c0c5956u: goto P_0c0c5956;
case 0x0c0c5958u: goto P_0c0c5958;
case 0x0c0c595au: goto P_0c0c595a;
case 0x0c0c595cu: goto P_0c0c595c;
case 0x0c0c595eu: goto P_0c0c595e;
case 0x0c0c5960u: goto P_0c0c5960;
case 0x0c0c5962u: goto P_0c0c5962;
case 0x0c0c5964u: goto P_0c0c5964;
case 0x0c0c5966u: goto P_0c0c5966;
case 0x0c0c5968u: goto P_0c0c5968;
case 0x0c0c596au: goto P_0c0c596a;
case 0x0c0c596cu: goto P_0c0c596c;
case 0x0c0c596eu: goto P_0c0c596e;
case 0x0c0c5970u: goto P_0c0c5970;
case 0x0c0c5972u: goto P_0c0c5972;
case 0x0c0c5974u: goto P_0c0c5974;
case 0x0c0c5976u: goto P_0c0c5976;
case 0x0c0c5978u: goto P_0c0c5978;
case 0x0c0c597au: goto P_0c0c597a;
case 0x0c0c597cu: goto P_0c0c597c;
case 0x0c0c597eu: goto P_0c0c597e;
case 0x0c0c5980u: goto P_0c0c5980;
case 0x0c0c5982u: goto P_0c0c5982;
case 0x0c0c5984u: goto P_0c0c5984;
case 0x0c0c5986u: goto P_0c0c5986;
case 0x0c0c5988u: goto P_0c0c5988;
case 0x0c0c598au: goto P_0c0c598a;
case 0x0c0c598cu: goto P_0c0c598c;
case 0x0c0c598eu: goto P_0c0c598e;
case 0x0c0c5990u: goto P_0c0c5990;
case 0x0c0c5992u: goto P_0c0c5992;
case 0x0c0c5994u: goto P_0c0c5994;
case 0x0c0c5996u: goto P_0c0c5996;
case 0x0c0c5998u: goto P_0c0c5998;
case 0x0c0c599au: goto P_0c0c599a;
case 0x0c0c599cu: goto P_0c0c599c;
case 0x0c0c599eu: goto P_0c0c599e;
case 0x0c0c59a0u: goto P_0c0c59a0;
case 0x0c0c59a2u: goto P_0c0c59a2;
case 0x0c0c59a4u: goto P_0c0c59a4;
case 0x0c0c59a6u: goto P_0c0c59a6;
case 0x0c0c59a8u: goto P_0c0c59a8;
case 0x0c0c59aau: goto P_0c0c59aa;
case 0x0c0c59acu: goto P_0c0c59ac;
case 0x0c0c59aeu: goto P_0c0c59ae;
case 0x0c0c59b0u: goto P_0c0c59b0;
case 0x0c0c59b2u: goto P_0c0c59b2;
case 0x0c0c59b4u: goto P_0c0c59b4;
case 0x0c0c59b6u: goto P_0c0c59b6;
case 0x0c0c59b8u: goto P_0c0c59b8;
case 0x0c0c59bau: goto P_0c0c59ba;
case 0x0c0c59bcu: goto P_0c0c59bc;
case 0x0c0c59beu: goto P_0c0c59be;
case 0x0c0c59c0u: goto P_0c0c59c0;
case 0x0c0c59c2u: goto P_0c0c59c2;
case 0x0c0c59c4u: goto P_0c0c59c4;
case 0x0c0c59c6u: goto P_0c0c59c6;
case 0x0c0c59c8u: goto P_0c0c59c8;
case 0x0c0c59cau: goto P_0c0c59ca;
case 0x0c0c59ccu: goto P_0c0c59cc;
case 0x0c0c59ceu: goto P_0c0c59ce;
case 0x0c0c59d0u: goto P_0c0c59d0;
case 0x0c0c59d2u: goto P_0c0c59d2;
case 0x0c0c59d4u: goto P_0c0c59d4;
case 0x0c0c59d6u: goto P_0c0c59d6;
case 0x0c0c59d8u: goto P_0c0c59d8;
case 0x0c0c59dau: goto P_0c0c59da;
case 0x0c0c59dcu: goto P_0c0c59dc;
case 0x0c0c59deu: goto P_0c0c59de;
case 0x0c0c59e0u: goto P_0c0c59e0;
case 0x0c0c59e2u: goto P_0c0c59e2;
case 0x0c0c59e4u: goto P_0c0c59e4;
case 0x0c0c59e6u: goto P_0c0c59e6;
case 0x0c0c59e8u: goto P_0c0c59e8;
case 0x0c0c59eau: goto P_0c0c59ea;
case 0x0c0c59ecu: goto P_0c0c59ec;
case 0x0c0c59eeu: goto P_0c0c59ee;
case 0x0c0c59f0u: goto P_0c0c59f0;
case 0x0c0c59f2u: goto P_0c0c59f2;
case 0x0c0c59f4u: goto P_0c0c59f4;
case 0x0c0c59f6u: goto P_0c0c59f6;
case 0x0c0c59f8u: goto P_0c0c59f8;
case 0x0c0c59fau: goto P_0c0c59fa;
case 0x0c0c59fcu: goto P_0c0c59fc;
case 0x0c0c59feu: goto P_0c0c59fe;
case 0x0c0c5a00u: goto P_0c0c5a00;
case 0x0c0c5a02u: goto P_0c0c5a02;
case 0x0c0c5a04u: goto P_0c0c5a04;
case 0x0c0c5a06u: goto P_0c0c5a06;
case 0x0c0c5a08u: goto P_0c0c5a08;
case 0x0c0c5a0au: goto P_0c0c5a0a;
case 0x0c0c5a0cu: goto P_0c0c5a0c;
case 0x0c0c5a0eu: goto P_0c0c5a0e;
case 0x0c0c5a10u: goto P_0c0c5a10;
case 0x0c0c5a12u: goto P_0c0c5a12;
case 0x0c0c5a14u: goto P_0c0c5a14;
case 0x0c0c5a16u: goto P_0c0c5a16;
case 0x0c0c5a18u: goto P_0c0c5a18;
case 0x0c0c5a1au: goto P_0c0c5a1a;
case 0x0c0c5a1cu: goto P_0c0c5a1c;
case 0x0c0c5a1eu: goto P_0c0c5a1e;
case 0x0c0c5a20u: goto P_0c0c5a20;
case 0x0c0c5a22u: goto P_0c0c5a22;
case 0x0c0c5a24u: goto P_0c0c5a24;
case 0x0c0c5a26u: goto P_0c0c5a26;
case 0x0c0c5a28u: goto P_0c0c5a28;
case 0x0c0c5a2au: goto P_0c0c5a2a;
case 0x0c0c5a2cu: goto P_0c0c5a2c;
case 0x0c0c5a2eu: goto P_0c0c5a2e;
case 0x0c0c5a30u: goto P_0c0c5a30;
case 0x0c0c5a32u: goto P_0c0c5a32;
case 0x0c0c5a34u: goto P_0c0c5a34;
case 0x0c0c5a36u: goto P_0c0c5a36;
case 0x0c0c5a38u: goto P_0c0c5a38;
case 0x0c0c5a3au: goto P_0c0c5a3a;
case 0x0c0c5a3cu: goto P_0c0c5a3c;
case 0x0c0c5a3eu: goto P_0c0c5a3e;
case 0x0c0c5a40u: goto P_0c0c5a40;
case 0x0c0c5a42u: goto P_0c0c5a42;
case 0x0c0c5a44u: goto P_0c0c5a44;
case 0x0c0c5a46u: goto P_0c0c5a46;
case 0x0c0c5a48u: goto P_0c0c5a48;
case 0x0c0c5a4au: goto P_0c0c5a4a;
case 0x0c0c5a4cu: goto P_0c0c5a4c;
case 0x0c0c5a4eu: goto P_0c0c5a4e;
case 0x0c0c5a50u: goto P_0c0c5a50;
case 0x0c0c5a52u: goto P_0c0c5a52;
case 0x0c0c5a54u: goto P_0c0c5a54;
case 0x0c0c5a56u: goto P_0c0c5a56;
case 0x0c0c8b50u: goto P_0c0c8b50;
case 0x0c0c8b52u: goto P_0c0c8b52;
case 0x0c0c8b54u: goto P_0c0c8b54;
case 0x0c0c8b56u: goto P_0c0c8b56;
case 0x0c0c8b58u: goto P_0c0c8b58;
case 0x0c0c8b5au: goto P_0c0c8b5a;
case 0x0c0c8b5cu: goto P_0c0c8b5c;
case 0x0c0c8b5eu: goto P_0c0c8b5e;
case 0x0c0c8b60u: goto P_0c0c8b60;
case 0x0c0c8b62u: goto P_0c0c8b62;
case 0x0c0c8b64u: goto P_0c0c8b64;
case 0x0c0c8b66u: goto P_0c0c8b66;
case 0x0c0c8b68u: goto P_0c0c8b68;
case 0x0c0c8b6au: goto P_0c0c8b6a;
case 0x0c0c8b6cu: goto P_0c0c8b6c;
case 0x0c0c8b6eu: goto P_0c0c8b6e;
case 0x0c0c8b70u: goto P_0c0c8b70;
case 0x0c0c8b72u: goto P_0c0c8b72;
case 0x0c0c8b74u: goto P_0c0c8b74;
case 0x0c0c8b76u: goto P_0c0c8b76;
case 0x0c0c8b78u: goto P_0c0c8b78;
case 0x0c0c8b7au: goto P_0c0c8b7a;
case 0x0c0c8b7cu: goto P_0c0c8b7c;
case 0x0c0c8b7eu: goto P_0c0c8b7e;
case 0x0c0c8b80u: goto P_0c0c8b80;
case 0x0c0c8b82u: goto P_0c0c8b82;
case 0x0c0c8b84u: goto P_0c0c8b84;
case 0x0c0c8b86u: goto P_0c0c8b86;
case 0x0c0c8b88u: goto P_0c0c8b88;
case 0x0c0c8b8au: goto P_0c0c8b8a;
case 0x0c0c8b8cu: goto P_0c0c8b8c;
case 0x0c0c8b8eu: goto P_0c0c8b8e;
case 0x0c0c8b90u: goto P_0c0c8b90;
case 0x0c0c8b92u: goto P_0c0c8b92;
case 0x0c0c8b94u: goto P_0c0c8b94;
case 0x0c0c8b96u: goto P_0c0c8b96;
case 0x0c0c8b98u: goto P_0c0c8b98;
case 0x0c0c8b9au: goto P_0c0c8b9a;
case 0x0c0c8b9cu: goto P_0c0c8b9c;
case 0x0c0c8b9eu: goto P_0c0c8b9e;
case 0x0c0c8ba0u: goto P_0c0c8ba0;
case 0x0c0c8be4u: goto P_0c0c8be4;
case 0x0c0c8be6u: goto P_0c0c8be6;
case 0x0c0c8be8u: goto P_0c0c8be8;
case 0x0c0c8beau: goto P_0c0c8bea;
case 0x0c0c8becu: goto P_0c0c8bec;
case 0x0c0c8beeu: goto P_0c0c8bee;
case 0x0c0c8bf0u: goto P_0c0c8bf0;
case 0x0c0c8bf2u: goto P_0c0c8bf2;
case 0x0c0c8bf4u: goto P_0c0c8bf4;
case 0x0c0c8bf6u: goto P_0c0c8bf6;
case 0x0c0c8bf8u: goto P_0c0c8bf8;
case 0x0c0c8bfau: goto P_0c0c8bfa;
case 0x0c0c8bfcu: goto P_0c0c8bfc;
case 0x0c0c8bfeu: goto P_0c0c8bfe;
case 0x0c0c8c00u: goto P_0c0c8c00;
case 0x0c0c8c02u: goto P_0c0c8c02;
case 0x0c0c8c04u: goto P_0c0c8c04;
case 0x0c0c8c06u: goto P_0c0c8c06;
case 0x0c0c8c08u: goto P_0c0c8c08;
case 0x0c0c8c0au: goto P_0c0c8c0a;
case 0x0c0c8c0cu: goto P_0c0c8c0c;
case 0x0c0c8c0eu: goto P_0c0c8c0e;
case 0x0c0c8c10u: goto P_0c0c8c10;
case 0x0c0c8c12u: goto P_0c0c8c12;
case 0x0c0c8c14u: goto P_0c0c8c14;
case 0x0c0c8c16u: goto P_0c0c8c16;
case 0x0c0c8c18u: goto P_0c0c8c18;
case 0x0c0c8c1au: goto P_0c0c8c1a;
case 0x0c0c8c1cu: goto P_0c0c8c1c;
case 0x0c0c8c1eu: goto P_0c0c8c1e;
case 0x0c0c8c20u: goto P_0c0c8c20;
case 0x0c0c8c22u: goto P_0c0c8c22;
case 0x0c0c8c24u: goto P_0c0c8c24;
case 0x0c0c8c26u: goto P_0c0c8c26;
case 0x0c0c8c28u: goto P_0c0c8c28;
case 0x0c0c8c2au: goto P_0c0c8c2a;
case 0x0c0c8c2cu: goto P_0c0c8c2c;
case 0x0c0c8c2eu: goto P_0c0c8c2e;
case 0x0c0c8c30u: goto P_0c0c8c30;
case 0x0c0c8c32u: goto P_0c0c8c32;
case 0x0c0c8c34u: goto P_0c0c8c34;
case 0x0c0c8c36u: goto P_0c0c8c36;
case 0x0c0c8c38u: goto P_0c0c8c38;
case 0x0c0c8c3au: goto P_0c0c8c3a;
case 0x0c0c8c3cu: goto P_0c0c8c3c;
case 0x0c0c8c3eu: goto P_0c0c8c3e;
case 0x0c0c8c40u: goto P_0c0c8c40;
case 0x0c0c8c42u: goto P_0c0c8c42;
case 0x0c0c8c44u: goto P_0c0c8c44;
case 0x0c0c8c46u: goto P_0c0c8c46;
case 0x0c0c8c48u: goto P_0c0c8c48;
case 0x0c0c8c4au: goto P_0c0c8c4a;
case 0x0c0c8c4cu: goto P_0c0c8c4c;
case 0x0c0c8c4eu: goto P_0c0c8c4e;
case 0x0c0c8c50u: goto P_0c0c8c50;
case 0x0c0c8c52u: goto P_0c0c8c52;
case 0x0c0c8c54u: goto P_0c0c8c54;
case 0x0c0c8c56u: goto P_0c0c8c56;
case 0x0c0c8c58u: goto P_0c0c8c58;
case 0x0c0c8c5au: goto P_0c0c8c5a;
case 0x0c0cc4dcu: goto P_0c0cc4dc;
case 0x0c0cc4deu: goto P_0c0cc4de;
case 0x0c0cc4e0u: goto P_0c0cc4e0;
case 0x0c0cc4e2u: goto P_0c0cc4e2;
case 0x0c0cc4e4u: goto P_0c0cc4e4;
case 0x0c0cc4e6u: goto P_0c0cc4e6;
case 0x0c0cc4e8u: goto P_0c0cc4e8;
case 0x0c0cc4eau: goto P_0c0cc4ea;
case 0x0c0cc4ecu: goto P_0c0cc4ec;
case 0x0c0cc4eeu: goto P_0c0cc4ee;
case 0x0c0cc4f0u: goto P_0c0cc4f0;
case 0x0c0cc4f2u: goto P_0c0cc4f2;
case 0x0c0cc4f4u: goto P_0c0cc4f4;
case 0x0c0cc4f6u: goto P_0c0cc4f6;
case 0x0c0cc4f8u: goto P_0c0cc4f8;
case 0x0c0cc4fau: goto P_0c0cc4fa;
case 0x0c0cc4fcu: goto P_0c0cc4fc;
case 0x0c0cc4feu: goto P_0c0cc4fe;
case 0x0c0cc500u: goto P_0c0cc500;
case 0x0c0cc502u: goto P_0c0cc502;
case 0x0c0cc504u: goto P_0c0cc504;
case 0x0c0cc506u: goto P_0c0cc506;
case 0x0c0cc508u: goto P_0c0cc508;
case 0x0c0cc50au: goto P_0c0cc50a;
case 0x0c0cc50cu: goto P_0c0cc50c;
case 0x0c0cc50eu: goto P_0c0cc50e;
case 0x0c0cc510u: goto P_0c0cc510;
case 0x0c0cc512u: goto P_0c0cc512;
case 0x0c0cc514u: goto P_0c0cc514;
case 0x0c0cc516u: goto P_0c0cc516;
case 0x0c0cc518u: goto P_0c0cc518;
case 0x0c0cc51au: goto P_0c0cc51a;
case 0x0c0cc51cu: goto P_0c0cc51c;
case 0x0c0cc51eu: goto P_0c0cc51e;
case 0x0c0cc520u: goto P_0c0cc520;
case 0x0c0cc522u: goto P_0c0cc522;
case 0x0c0cc524u: goto P_0c0cc524;
case 0x0c0cc526u: goto P_0c0cc526;
case 0x0c0cc528u: goto P_0c0cc528;
case 0x0c0cc52au: goto P_0c0cc52a;
case 0x0c0cc52cu: goto P_0c0cc52c;
case 0x0c0cc52eu: goto P_0c0cc52e;
case 0x0c0cc530u: goto P_0c0cc530;
case 0x0c0cc532u: goto P_0c0cc532;
case 0x0c0cc534u: goto P_0c0cc534;
case 0x0c0cc536u: goto P_0c0cc536;
case 0x0c0cc538u: goto P_0c0cc538;
case 0x0c0cc53au: goto P_0c0cc53a;
case 0x0c0cc53cu: goto P_0c0cc53c;
case 0x0c0cc53eu: goto P_0c0cc53e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08db70: /* original 2fe6, guest PC 0x0c08db70 */
if(!s->budget--) { s->failed_pc=0x0c08db70u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c08db72;
P_0c08db72: /* original 6e43, guest PC 0x0c08db72 */
if(!s->budget--) { s->failed_pc=0x0c08db72u; return 0; }
r[14]=r[4];
goto P_0c08db74;
P_0c08db74: /* original d334, guest PC 0x0c08db74 */
if(!s->budget--) { s->failed_pc=0x0c08db74u; return 0; }
r[3]=read(ram,0x0c08dc48u,4);
goto P_0c08db76;
P_0c08db76: /* original e010, guest PC 0x0c08db76 */
if(!s->budget--) { s->failed_pc=0x0c08db76u; return 0; }
r[0]=0x00000010u;
goto P_0c08db78;
P_0c08db78: /* original 4f22, guest PC 0x0c08db78 */
if(!s->budget--) { s->failed_pc=0x0c08db78u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08db7a;
P_0c08db7a: /* original 6432, guest PC 0x0c08db7a */
if(!s->budget--) { s->failed_pc=0x0c08db7au; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c08db7c;
P_0c08db7c: /* original f446, guest PC 0x0c08db7c */
if(!s->budget--) { s->failed_pc=0x0c08db7cu; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c08db7e;
P_0c08db7e: /* original e014, guest PC 0x0c08db7e */
if(!s->budget--) { s->failed_pc=0x0c08db7eu; return 0; }
r[0]=0x00000014u;
goto P_0c08db80;
P_0c08db80: /* original f546, guest PC 0x0c08db80 */
if(!s->budget--) { s->failed_pc=0x0c08db80u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c08db82;
P_0c08db82: /* original e018, guest PC 0x0c08db82 */
if(!s->budget--) { s->failed_pc=0x0c08db82u; return 0; }
r[0]=0x00000018u;
goto P_0c08db84;
P_0c08db84: /* original f646, guest PC 0x0c08db84 */
if(!s->budget--) { s->failed_pc=0x0c08db84u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c08db86;
P_0c08db86: /* original 7fe8, guest PC 0x0c08db86 */
if(!s->budget--) { s->failed_pc=0x0c08db86u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c08db88;
P_0c08db88: /* original 65f3, guest PC 0x0c08db88 */
if(!s->budget--) { s->failed_pc=0x0c08db88u; return 0; }
r[5]=r[15];
goto P_0c08db8a;
P_0c08db8a: /* original 66f3, guest PC 0x0c08db8a */
if(!s->budget--) { s->failed_pc=0x0c08db8au; return 0; }
r[6]=r[15];
goto P_0c08db8c;
P_0c08db8c: /* original 7510, guest PC 0x0c08db8c */
if(!s->budget--) { s->failed_pc=0x0c08db8cu; return 0; }
r[5]+=0x00000010u;
goto P_0c08db8e;
P_0c08db8e: /* original f64d, guest PC 0x0c08db8e */
if(!s->budget--) { s->failed_pc=0x0c08db8eu; return 0; }
fr[6]^=0x80000000u;
goto P_0c08db90;
P_0c08db90: /* original 7614, guest PC 0x0c08db90 */
if(!s->budget--) { s->failed_pc=0x0c08db90u; return 0; }
r[6]+=0x00000014u;
goto P_0c08db92;
P_0c08db92: /* original b11d, guest PC 0x0c08db92 */
if(!s->budget--) { s->failed_pc=0x0c08db92u; return 0; }
target=0x0c08ddd0u; r[16]=0x0c08db96u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08db96u) { target=s->pc; goto dispatch; }
goto P_0c08db96;
P_0c08db94: /* original 64e3, guest PC 0x0c08db94 */
if(!s->budget--) { s->failed_pc=0x0c08db94u; return 0; }
r[4]=r[14];
goto P_0c08db96;
P_0c08db96: /* original 63f3, guest PC 0x0c08db96 */
if(!s->budget--) { s->failed_pc=0x0c08db96u; return 0; }
r[3]=r[15];
goto P_0c08db98;
P_0c08db98: /* original 730c, guest PC 0x0c08db98 */
if(!s->budget--) { s->failed_pc=0x0c08db98u; return 0; }
r[3]+=0x0000000cu;
goto P_0c08db9a;
P_0c08db9a: /* original 2f36, guest PC 0x0c08db9a */
if(!s->budget--) { s->failed_pc=0x0c08db9au; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c08db9c;
P_0c08db9c: /* original 62f3, guest PC 0x0c08db9c */
if(!s->budget--) { s->failed_pc=0x0c08db9cu; return 0; }
r[2]=r[15];
goto P_0c08db9e;
P_0c08db9e: /* original 720c, guest PC 0x0c08db9e */
if(!s->budget--) { s->failed_pc=0x0c08db9eu; return 0; }
r[2]+=0x0000000cu;
goto P_0c08dba0;
P_0c08dba0: /* original 2f26, guest PC 0x0c08dba0 */
if(!s->budget--) { s->failed_pc=0x0c08dba0u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c08dba2;
P_0c08dba2: /* original 66f3, guest PC 0x0c08dba2 */
if(!s->budget--) { s->failed_pc=0x0c08dba2u; return 0; }
r[6]=r[15];
goto P_0c08dba4;
P_0c08dba4: /* original 55f7, guest PC 0x0c08dba4 */
if(!s->budget--) { s->failed_pc=0x0c08dba4u; return 0; }
r[5]=read(ram,r[15]+28,4);
goto P_0c08dba6;
P_0c08dba6: /* original 67f3, guest PC 0x0c08dba6 */
if(!s->budget--) { s->failed_pc=0x0c08dba6u; return 0; }
r[7]=r[15];
goto P_0c08dba8;
P_0c08dba8: /* original 7608, guest PC 0x0c08dba8 */
if(!s->budget--) { s->failed_pc=0x0c08dba8u; return 0; }
r[6]+=0x00000008u;
goto P_0c08dbaa;
P_0c08dbaa: /* original 770c, guest PC 0x0c08dbaa */
if(!s->budget--) { s->failed_pc=0x0c08dbaau; return 0; }
r[7]+=0x0000000cu;
goto P_0c08dbac;
P_0c08dbac: /* original b080, guest PC 0x0c08dbac */
if(!s->budget--) { s->failed_pc=0x0c08dbacu; return 0; }
target=0x0c08dcb0u; r[16]=0x0c08dbb0u;
r[4]=read(ram,r[15]+24,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08dbb0u) { target=s->pc; goto dispatch; }
goto P_0c08dbb0;
P_0c08dbae: /* original 54f6, guest PC 0x0c08dbae */
if(!s->budget--) { s->failed_pc=0x0c08dbaeu; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c08dbb0;
P_0c08dbb0: /* original 62f3, guest PC 0x0c08dbb0 */
if(!s->budget--) { s->failed_pc=0x0c08dbb0u; return 0; }
r[2]=r[15];
goto P_0c08dbb2;
P_0c08dbb2: /* original 7214, guest PC 0x0c08dbb2 */
if(!s->budget--) { s->failed_pc=0x0c08dbb2u; return 0; }
r[2]+=0x00000014u;
goto P_0c08dbb4;
P_0c08dbb4: /* original 2f26, guest PC 0x0c08dbb4 */
if(!s->budget--) { s->failed_pc=0x0c08dbb4u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c08dbb6;
P_0c08dbb6: /* original 66f3, guest PC 0x0c08dbb6 */
if(!s->budget--) { s->failed_pc=0x0c08dbb6u; return 0; }
r[6]=r[15];
goto P_0c08dbb8;
P_0c08dbb8: /* original 65f3, guest PC 0x0c08dbb8 */
if(!s->budget--) { s->failed_pc=0x0c08dbb8u; return 0; }
r[5]=r[15];
goto P_0c08dbba;
P_0c08dbba: /* original 67f3, guest PC 0x0c08dbba */
if(!s->budget--) { s->failed_pc=0x0c08dbbau; return 0; }
r[7]=r[15];
goto P_0c08dbbc;
P_0c08dbbc: /* original 750c, guest PC 0x0c08dbbc */
if(!s->budget--) { s->failed_pc=0x0c08dbbcu; return 0; }
r[5]+=0x0000000cu;
goto P_0c08dbbe;
P_0c08dbbe: /* original 7714, guest PC 0x0c08dbbe */
if(!s->budget--) { s->failed_pc=0x0c08dbbeu; return 0; }
r[7]+=0x00000014u;
goto P_0c08dbc0;
P_0c08dbc0: /* original 7610, guest PC 0x0c08dbc0 */
if(!s->budget--) { s->failed_pc=0x0c08dbc0u; return 0; }
r[6]+=0x00000010u;
goto P_0c08dbc2;
P_0c08dbc2: /* original b0a8, guest PC 0x0c08dbc2 */
if(!s->budget--) { s->failed_pc=0x0c08dbc2u; return 0; }
target=0x0c08dd16u; r[16]=0x0c08dbc6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08dbc6u) { target=s->pc; goto dispatch; }
goto P_0c08dbc6;
P_0c08dbc4: /* original 64e3, guest PC 0x0c08dbc4 */
if(!s->budget--) { s->failed_pc=0x0c08dbc4u; return 0; }
r[4]=r[14];
goto P_0c08dbc6;
P_0c08dbc6: /* original 52f6, guest PC 0x0c08dbc6 */
if(!s->budget--) { s->failed_pc=0x0c08dbc6u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c08dbc8;
P_0c08dbc8: /* original 2f26, guest PC 0x0c08dbc8 */
if(!s->budget--) { s->failed_pc=0x0c08dbc8u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c08dbca;
P_0c08dbca: /* original 53f6, guest PC 0x0c08dbca */
if(!s->budget--) { s->failed_pc=0x0c08dbcau; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c08dbcc;
P_0c08dbcc: /* original 2f36, guest PC 0x0c08dbcc */
if(!s->budget--) { s->failed_pc=0x0c08dbccu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c08dbce;
P_0c08dbce: /* original 52f6, guest PC 0x0c08dbce */
if(!s->budget--) { s->failed_pc=0x0c08dbceu; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c08dbd0;
P_0c08dbd0: /* original 2f26, guest PC 0x0c08dbd0 */
if(!s->budget--) { s->failed_pc=0x0c08dbd0u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c08dbd2;
P_0c08dbd2: /* original 55fa, guest PC 0x0c08dbd2 */
if(!s->budget--) { s->failed_pc=0x0c08dbd2u; return 0; }
r[5]=read(ram,r[15]+40,4);
goto P_0c08dbd4;
P_0c08dbd4: /* original 56fb, guest PC 0x0c08dbd4 */
if(!s->budget--) { s->failed_pc=0x0c08dbd4u; return 0; }
r[6]=read(ram,r[15]+44,4);
goto P_0c08dbd6;
P_0c08dbd6: /* original 57f6, guest PC 0x0c08dbd6 */
if(!s->budget--) { s->failed_pc=0x0c08dbd6u; return 0; }
r[7]=read(ram,r[15]+24,4);
goto P_0c08dbd8;
P_0c08dbd8: /* original b185, guest PC 0x0c08dbd8 */
if(!s->budget--) { s->failed_pc=0x0c08dbd8u; return 0; }
target=0x0c08dee6u; r[16]=0x0c08dbdcu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08dbdcu) { target=s->pc; goto dispatch; }
goto P_0c08dbdc;
P_0c08dbda: /* original 64e3, guest PC 0x0c08dbda */
if(!s->budget--) { s->failed_pc=0x0c08dbdau; return 0; }
r[4]=r[14];
goto P_0c08dbdc;
P_0c08dbdc: /* original 7f30, guest PC 0x0c08dbdc */
if(!s->budget--) { s->failed_pc=0x0c08dbdcu; return 0; }
r[15]+=0x00000030u;
goto P_0c08dbde;
P_0c08dbde: /* original 4f26, guest PC 0x0c08dbde */
if(!s->budget--) { s->failed_pc=0x0c08dbdeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08dbe0;
P_0c08dbe0: /* original 000b, guest PC 0x0c08dbe0 */
if(!s->budget--) { s->failed_pc=0x0c08dbe0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08dbe2: /* original 6ef6, guest PC 0x0c08dbe2 */
if(!s->budget--) { s->failed_pc=0x0c08dbe2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08dbe4u,s,ram);
P_0c08dee6: /* original 2fe6, guest PC 0x0c08dee6 */
if(!s->budget--) { s->failed_pc=0x0c08dee6u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c08dee8;
P_0c08dee8: /* original 6e43, guest PC 0x0c08dee8 */
if(!s->budget--) { s->failed_pc=0x0c08dee8u; return 0; }
r[14]=r[4];
goto P_0c08deea;
P_0c08deea: /* original e060, guest PC 0x0c08deea */
if(!s->budget--) { s->failed_pc=0x0c08deeau; return 0; }
r[0]=0x00000060u;
goto P_0c08deec;
P_0c08deec: /* original 2fd6, guest PC 0x0c08deec */
if(!s->budget--) { s->failed_pc=0x0c08deecu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c08deee;
P_0c08deee: /* original 2fc6, guest PC 0x0c08deee */
if(!s->budget--) { s->failed_pc=0x0c08deeeu; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c08def0;
P_0c08def0: /* original 4f22, guest PC 0x0c08def0 */
if(!s->budget--) { s->failed_pc=0x0c08def0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08def2;
P_0c08def2: /* original 7fe8, guest PC 0x0c08def2 */
if(!s->budget--) { s->failed_pc=0x0c08def2u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c08def4;
P_0c08def4: /* original 1f52, guest PC 0x0c08def4 */
if(!s->budget--) { s->failed_pc=0x0c08def4u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c08def6;
P_0c08def6: /* original 1f61, guest PC 0x0c08def6 */
if(!s->budget--) { s->failed_pc=0x0c08def6u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c08def8;
P_0c08def8: /* original 2f72, guest PC 0x0c08def8 */
if(!s->budget--) { s->failed_pc=0x0c08def8u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c08defa;
P_0c08defa: /* original 0dec, guest PC 0x0c08defa */
if(!s->budget--) { s->failed_pc=0x0c08defau; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08defc;
P_0c08defc: /* original e00c, guest PC 0x0c08defc */
if(!s->budget--) { s->failed_pc=0x0c08defcu; return 0; }
r[0]=0x0000000cu;
goto P_0c08defe;
P_0c08defe: /* original d211, guest PC 0x0c08defe */
if(!s->budget--) { s->failed_pc=0x0c08defeu; return 0; }
r[2]=read(ram,0x0c08df44u,4);
goto P_0c08df00;
P_0c08df00: /* original 6ddc, guest PC 0x0c08df00 */
if(!s->budget--) { s->failed_pc=0x0c08df00u; return 0; }
r[13]=r[13]&255u;
goto P_0c08df02;
P_0c08df02: /* original 63d3, guest PC 0x0c08df02 */
if(!s->budget--) { s->failed_pc=0x0c08df02u; return 0; }
r[3]=r[13];
goto P_0c08df04;
P_0c08df04: /* original 4d00, guest PC 0x0c08df04 */
if(!s->budget--) { s->failed_pc=0x0c08df04u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c08df06;
P_0c08df06: /* original 3d3c, guest PC 0x0c08df06 */
if(!s->budget--) { s->failed_pc=0x0c08df06u; return 0; }
r[13]+=r[3];
goto P_0c08df08;
P_0c08df08: /* original 4d08, guest PC 0x0c08df08 */
if(!s->budget--) { s->failed_pc=0x0c08df08u; return 0; }
r[13]<<=2;
goto P_0c08df0a;
P_0c08df0a: /* original 6ddf, guest PC 0x0c08df0a */
if(!s->budget--) { s->failed_pc=0x0c08df0au; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c08df0c;
P_0c08df0c: /* original 3d2c, guest PC 0x0c08df0c */
if(!s->budget--) { s->failed_pc=0x0c08df0cu; return 0; }
r[13]+=r[2];
goto P_0c08df0e;
P_0c08df0e: /* original f3d8, guest PC 0x0c08df0e */
if(!s->budget--) { s->failed_pc=0x0c08df0eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c08df10;
P_0c08df10: /* original ff37, guest PC 0x0c08df10 */
if(!s->budget--) { s->failed_pc=0x0c08df10u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08df12;
P_0c08df12: /* original e004, guest PC 0x0c08df12 */
if(!s->budget--) { s->failed_pc=0x0c08df12u; return 0; }
r[0]=0x00000004u;
goto P_0c08df14;
P_0c08df14: /* original f3d6, guest PC 0x0c08df14 */
if(!s->budget--) { s->failed_pc=0x0c08df14u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c08df16;
P_0c08df16: /* original e010, guest PC 0x0c08df16 */
if(!s->budget--) { s->failed_pc=0x0c08df16u; return 0; }
r[0]=0x00000010u;
goto P_0c08df18;
P_0c08df18: /* original ff37, guest PC 0x0c08df18 */
if(!s->budget--) { s->failed_pc=0x0c08df18u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08df1a;
P_0c08df1a: /* original e008, guest PC 0x0c08df1a */
if(!s->budget--) { s->failed_pc=0x0c08df1au; return 0; }
r[0]=0x00000008u;
goto P_0c08df1c;
P_0c08df1c: /* original f3d6, guest PC 0x0c08df1c */
if(!s->budget--) { s->failed_pc=0x0c08df1cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c08df1e;
P_0c08df1e: /* original e014, guest PC 0x0c08df1e */
if(!s->budget--) { s->failed_pc=0x0c08df1eu; return 0; }
r[0]=0x00000014u;
goto P_0c08df20;
P_0c08df20: /* original ff37, guest PC 0x0c08df20 */
if(!s->budget--) { s->failed_pc=0x0c08df20u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08df22;
P_0c08df22: /* original d310, guest PC 0x0c08df22 */
if(!s->budget--) { s->failed_pc=0x0c08df22u; return 0; }
r[3]=read(ram,0x0c08df64u,4);
goto P_0c08df24;
P_0c08df24: /* original d00e, guest PC 0x0c08df24 */
if(!s->budget--) { s->failed_pc=0x0c08df24u; return 0; }
r[0]=read(ram,0x0c08df60u,4);
goto P_0c08df26;
P_0c08df26: /* original 6102, guest PC 0x0c08df26 */
if(!s->budget--) { s->failed_pc=0x0c08df26u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c08df28;
P_0c08df28: /* original 2138, guest PC 0x0c08df28 */
if(!s->budget--) { s->failed_pc=0x0c08df28u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c08df2a;
P_0c08df2a: /* original 891f, guest PC 0x0c08df2a */
if(!s->budget--) { s->failed_pc=0x0c08df2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08df6c; }
goto P_0c08df2c;
P_0c08df2c: /* original e060, guest PC 0x0c08df2c */
if(!s->budget--) { s->failed_pc=0x0c08df2cu; return 0; }
r[0]=0x00000060u;
goto P_0c08df2e;
P_0c08df2e: /* original 0cec, guest PC 0x0c08df2e */
if(!s->budget--) { s->failed_pc=0x0c08df2eu; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08df30;
P_0c08df30: /* original d00d, guest PC 0x0c08df30 */
if(!s->budget--) { s->failed_pc=0x0c08df30u; return 0; }
r[0]=read(ram,0x0c08df68u,4);
goto P_0c08df32;
P_0c08df32: /* original 6ccc, guest PC 0x0c08df32 */
if(!s->budget--) { s->failed_pc=0x0c08df32u; return 0; }
r[12]=r[12]&255u;
goto P_0c08df34;
P_0c08df34: /* original a01f, guest PC 0x0c08df34 */
if(!s->budget--) { s->failed_pc=0x0c08df34u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c08df76;
P_0c08df36: /* original 4c00, guest PC 0x0c08df36 */
if(!s->budget--) { s->failed_pc=0x0c08df36u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
return vf3_matrix_family(0x0c08df38u,s,ram);
P_0c08df6c: /* original e060, guest PC 0x0c08df6c */
if(!s->budget--) { s->failed_pc=0x0c08df6cu; return 0; }
r[0]=0x00000060u;
goto P_0c08df6e;
P_0c08df6e: /* original 0cec, guest PC 0x0c08df6e */
if(!s->budget--) { s->failed_pc=0x0c08df6eu; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08df70;
P_0c08df70: /* original d023, guest PC 0x0c08df70 */
if(!s->budget--) { s->failed_pc=0x0c08df70u; return 0; }
r[0]=read(ram,0x0c08e000u,4);
goto P_0c08df72;
P_0c08df72: /* original 6ccc, guest PC 0x0c08df72 */
if(!s->budget--) { s->failed_pc=0x0c08df72u; return 0; }
r[12]=r[12]&255u;
goto P_0c08df74;
P_0c08df74: /* original 4c00, guest PC 0x0c08df74 */
if(!s->budget--) { s->failed_pc=0x0c08df74u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c08df76;
P_0c08df76: /* original d323, guest PC 0x0c08df76 */
if(!s->budget--) { s->failed_pc=0x0c08df76u; return 0; }
r[3]=read(ram,0x0c08e004u,4);
goto P_0c08df78;
P_0c08df78: /* original 0ccd, guest PC 0x0c08df78 */
if(!s->budget--) { s->failed_pc=0x0c08df78u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c08df7a;
P_0c08df7a: /* original 430b, guest PC 0x0c08df7a */
if(!s->budget--) { s->failed_pc=0x0c08df7au; return 0; }
target=r[3];
r[16]=0x0c08df7eu;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08df7eu) { target=s->pc; goto dispatch; }
goto P_0c08df7e;
P_0c08df7c: /* original e400, guest PC 0x0c08df7c */
if(!s->budget--) { s->failed_pc=0x0c08df7cu; return 0; }
r[4]=0x00000000u;
goto P_0c08df7e;
P_0c08df7e: /* original d222, guest PC 0x0c08df7e */
if(!s->budget--) { s->failed_pc=0x0c08df7eu; return 0; }
r[2]=read(ram,0x0c08e008u,4);
goto P_0c08df80;
P_0c08df80: /* original 420b, guest PC 0x0c08df80 */
if(!s->budget--) { s->failed_pc=0x0c08df80u; return 0; }
target=r[2];
r[16]=0x0c08df84u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08df84u) { target=s->pc; goto dispatch; }
goto P_0c08df84;
P_0c08df82: /* original 64d3, guest PC 0x0c08df82 */
if(!s->budget--) { s->failed_pc=0x0c08df82u; return 0; }
r[4]=r[13];
goto P_0c08df84;
P_0c08df84: /* original d321, guest PC 0x0c08df84 */
if(!s->budget--) { s->failed_pc=0x0c08df84u; return 0; }
r[3]=read(ram,0x0c08e00cu,4);
goto P_0c08df86;
P_0c08df86: /* original 430b, guest PC 0x0c08df86 */
if(!s->budget--) { s->failed_pc=0x0c08df86u; return 0; }
target=r[3];
r[16]=0x0c08df8au;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08df8au) { target=s->pc; goto dispatch; }
goto P_0c08df8a;
P_0c08df88: /* original 64f2, guest PC 0x0c08df88 */
if(!s->budget--) { s->failed_pc=0x0c08df88u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c08df8a;
P_0c08df8a: /* original d321, guest PC 0x0c08df8a */
if(!s->budget--) { s->failed_pc=0x0c08df8au; return 0; }
r[3]=read(ram,0x0c08e010u,4);
goto P_0c08df8c;
P_0c08df8c: /* original 54fa, guest PC 0x0c08df8c */
if(!s->budget--) { s->failed_pc=0x0c08df8cu; return 0; }
r[4]=read(ram,r[15]+40,4);
goto P_0c08df8e;
P_0c08df8e: /* original 430b, guest PC 0x0c08df8e */
if(!s->budget--) { s->failed_pc=0x0c08df8eu; return 0; }
target=r[3];
r[16]=0x0c08df92u;
r[4]=0u-r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08df92u) { target=s->pc; goto dispatch; }
goto P_0c08df92;
P_0c08df90: /* original 644b, guest PC 0x0c08df90 */
if(!s->budget--) { s->failed_pc=0x0c08df90u; return 0; }
r[4]=0u-r[4];
goto P_0c08df92;
P_0c08df92: /* original d220, guest PC 0x0c08df92 */
if(!s->budget--) { s->failed_pc=0x0c08df92u; return 0; }
r[2]=read(ram,0x0c08e014u,4);
goto P_0c08df94;
P_0c08df94: /* original 420b, guest PC 0x0c08df94 */
if(!s->budget--) { s->failed_pc=0x0c08df94u; return 0; }
target=r[2];
r[16]=0x0c08df98u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08df98u) { target=s->pc; goto dispatch; }
goto P_0c08df98;
P_0c08df96: /* original 64c3, guest PC 0x0c08df96 */
if(!s->budget--) { s->failed_pc=0x0c08df96u; return 0; }
r[4]=r[12];
goto P_0c08df98;
P_0c08df98: /* original d31f, guest PC 0x0c08df98 */
if(!s->budget--) { s->failed_pc=0x0c08df98u; return 0; }
r[3]=read(ram,0x0c08e018u,4);
goto P_0c08df9a;
P_0c08df9a: /* original 430b, guest PC 0x0c08df9a */
if(!s->budget--) { s->failed_pc=0x0c08df9au; return 0; }
target=r[3];
r[16]=0x0c08df9eu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08df9eu) { target=s->pc; goto dispatch; }
goto P_0c08df9e;
P_0c08df9c: /* original e401, guest PC 0x0c08df9c */
if(!s->budget--) { s->failed_pc=0x0c08df9cu; return 0; }
r[4]=0x00000001u;
goto P_0c08df9e;
P_0c08df9e: /* original e014, guest PC 0x0c08df9e */
if(!s->budget--) { s->failed_pc=0x0c08df9eu; return 0; }
r[0]=0x00000014u;
goto P_0c08dfa0;
P_0c08dfa0: /* original d31e, guest PC 0x0c08dfa0 */
if(!s->budget--) { s->failed_pc=0x0c08dfa0u; return 0; }
r[3]=read(ram,0x0c08e01cu,4);
goto P_0c08dfa2;
P_0c08dfa2: /* original f6f6, guest PC 0x0c08dfa2 */
if(!s->budget--) { s->failed_pc=0x0c08dfa2u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c08dfa4;
P_0c08dfa4: /* original e010, guest PC 0x0c08dfa4 */
if(!s->budget--) { s->failed_pc=0x0c08dfa4u; return 0; }
r[0]=0x00000010u;
goto P_0c08dfa6;
P_0c08dfa6: /* original f5f6, guest PC 0x0c08dfa6 */
if(!s->budget--) { s->failed_pc=0x0c08dfa6u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c08dfa8;
P_0c08dfa8: /* original e00c, guest PC 0x0c08dfa8 */
if(!s->budget--) { s->failed_pc=0x0c08dfa8u; return 0; }
r[0]=0x0000000cu;
goto P_0c08dfaa;
P_0c08dfaa: /* original f54d, guest PC 0x0c08dfaa */
if(!s->budget--) { s->failed_pc=0x0c08dfaau; return 0; }
fr[5]^=0x80000000u;
goto P_0c08dfac;
P_0c08dfac: /* original 430b, guest PC 0x0c08dfac */
if(!s->budget--) { s->failed_pc=0x0c08dfacu; return 0; }
target=r[3];
r[16]=0x0c08dfb0u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08dfb0u) { target=s->pc; goto dispatch; }
goto P_0c08dfb0;
P_0c08dfae: /* original f4f6, guest PC 0x0c08dfae */
if(!s->budget--) { s->failed_pc=0x0c08dfaeu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08dfb0;
P_0c08dfb0: /* original d316, guest PC 0x0c08dfb0 */
if(!s->budget--) { s->failed_pc=0x0c08dfb0u; return 0; }
r[3]=read(ram,0x0c08e00cu,4);
goto P_0c08dfb2;
P_0c08dfb2: /* original 430b, guest PC 0x0c08dfb2 */
if(!s->budget--) { s->failed_pc=0x0c08dfb2u; return 0; }
target=r[3];
r[16]=0x0c08dfb6u;
r[4]=read(ram,r[15]+44,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08dfb6u) { target=s->pc; goto dispatch; }
goto P_0c08dfb6;
P_0c08dfb4: /* original 54fb, guest PC 0x0c08dfb4 */
if(!s->budget--) { s->failed_pc=0x0c08dfb4u; return 0; }
r[4]=read(ram,r[15]+44,4);
goto P_0c08dfb6;
P_0c08dfb6: /* original d316, guest PC 0x0c08dfb6 */
if(!s->budget--) { s->failed_pc=0x0c08dfb6u; return 0; }
r[3]=read(ram,0x0c08e010u,4);
goto P_0c08dfb8;
P_0c08dfb8: /* original 54fc, guest PC 0x0c08dfb8 */
if(!s->budget--) { s->failed_pc=0x0c08dfb8u; return 0; }
r[4]=read(ram,r[15]+48,4);
goto P_0c08dfba;
P_0c08dfba: /* original 430b, guest PC 0x0c08dfba */
if(!s->budget--) { s->failed_pc=0x0c08dfbau; return 0; }
target=r[3];
r[16]=0x0c08dfbeu;
r[4]=0u-r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08dfbeu) { target=s->pc; goto dispatch; }
goto P_0c08dfbe;
P_0c08dfbc: /* original 644b, guest PC 0x0c08dfbc */
if(!s->budget--) { s->failed_pc=0x0c08dfbcu; return 0; }
r[4]=0u-r[4];
goto P_0c08dfbe;
P_0c08dfbe: /* original d215, guest PC 0x0c08dfbe */
if(!s->budget--) { s->failed_pc=0x0c08dfbeu; return 0; }
r[2]=read(ram,0x0c08e014u,4);
goto P_0c08dfc0;
P_0c08dfc0: /* original 420b, guest PC 0x0c08dfc0 */
if(!s->budget--) { s->failed_pc=0x0c08dfc0u; return 0; }
target=r[2];
r[16]=0x0c08dfc4u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08dfc4u) { target=s->pc; goto dispatch; }
goto P_0c08dfc4;
P_0c08dfc2: /* original 64c3, guest PC 0x0c08dfc2 */
if(!s->budget--) { s->failed_pc=0x0c08dfc2u; return 0; }
r[4]=r[12];
goto P_0c08dfc4;
P_0c08dfc4: /* original 9016, guest PC 0x0c08dfc4 */
if(!s->budget--) { s->failed_pc=0x0c08dfc4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dff4u,2);
goto P_0c08dfc6;
P_0c08dfc6: /* original 53f2, guest PC 0x0c08dfc6 */
if(!s->budget--) { s->failed_pc=0x0c08dfc6u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c08dfc8;
P_0c08dfc8: /* original 0e35, guest PC 0x0c08dfc8 */
if(!s->budget--) { s->failed_pc=0x0c08dfc8u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c08dfca;
P_0c08dfca: /* original 9014, guest PC 0x0c08dfca */
if(!s->budget--) { s->failed_pc=0x0c08dfcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dff6u,2);
goto P_0c08dfcc;
P_0c08dfcc: /* original 52f1, guest PC 0x0c08dfcc */
if(!s->budget--) { s->failed_pc=0x0c08dfccu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c08dfce;
P_0c08dfce: /* original 0e25, guest PC 0x0c08dfce */
if(!s->budget--) { s->failed_pc=0x0c08dfceu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c08dfd0;
P_0c08dfd0: /* original 9012, guest PC 0x0c08dfd0 */
if(!s->budget--) { s->failed_pc=0x0c08dfd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dff8u,2);
goto P_0c08dfd2;
P_0c08dfd2: /* original 63f2, guest PC 0x0c08dfd2 */
if(!s->budget--) { s->failed_pc=0x0c08dfd2u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08dfd4;
P_0c08dfd4: /* original 0e35, guest PC 0x0c08dfd4 */
if(!s->budget--) { s->failed_pc=0x0c08dfd4u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c08dfd6;
P_0c08dfd6: /* original 9010, guest PC 0x0c08dfd6 */
if(!s->budget--) { s->failed_pc=0x0c08dfd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dffau,2);
goto P_0c08dfd8;
P_0c08dfd8: /* original 52fa, guest PC 0x0c08dfd8 */
if(!s->budget--) { s->failed_pc=0x0c08dfd8u; return 0; }
r[2]=read(ram,r[15]+40,4);
goto P_0c08dfda;
P_0c08dfda: /* original 0e25, guest PC 0x0c08dfda */
if(!s->budget--) { s->failed_pc=0x0c08dfdau; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c08dfdc;
P_0c08dfdc: /* original 53fb, guest PC 0x0c08dfdc */
if(!s->budget--) { s->failed_pc=0x0c08dfdcu; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c08dfde;
P_0c08dfde: /* original 900d, guest PC 0x0c08dfde */
if(!s->budget--) { s->failed_pc=0x0c08dfdeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dffcu,2);
goto P_0c08dfe0;
P_0c08dfe0: /* original 0e35, guest PC 0x0c08dfe0 */
if(!s->budget--) { s->failed_pc=0x0c08dfe0u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c08dfe2;
P_0c08dfe2: /* original 52fc, guest PC 0x0c08dfe2 */
if(!s->budget--) { s->failed_pc=0x0c08dfe2u; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c08dfe4;
P_0c08dfe4: /* original 7f18, guest PC 0x0c08dfe4 */
if(!s->budget--) { s->failed_pc=0x0c08dfe4u; return 0; }
r[15]+=0x00000018u;
goto P_0c08dfe6;
P_0c08dfe6: /* original 4f26, guest PC 0x0c08dfe6 */
if(!s->budget--) { s->failed_pc=0x0c08dfe6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08dfe8;
P_0c08dfe8: /* original 9009, guest PC 0x0c08dfe8 */
if(!s->budget--) { s->failed_pc=0x0c08dfe8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dffeu,2);
goto P_0c08dfea;
P_0c08dfea: /* original 0e25, guest PC 0x0c08dfea */
if(!s->budget--) { s->failed_pc=0x0c08dfeau; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c08dfec;
P_0c08dfec: /* original 6cf6, guest PC 0x0c08dfec */
if(!s->budget--) { s->failed_pc=0x0c08dfecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08dfee;
P_0c08dfee: /* original 6df6, guest PC 0x0c08dfee */
if(!s->budget--) { s->failed_pc=0x0c08dfeeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08dff0;
P_0c08dff0: /* original 000b, guest PC 0x0c08dff0 */
if(!s->budget--) { s->failed_pc=0x0c08dff0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08dff2: /* original 6ef6, guest PC 0x0c08dff2 */
if(!s->budget--) { s->failed_pc=0x0c08dff2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08dff4u,s,ram);
P_0c091c3a: /* original 4f22, guest PC 0x0c091c3a */
if(!s->budget--) { s->failed_pc=0x0c091c3au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c091c3c;
P_0c091c3c: /* original 7fe0, guest PC 0x0c091c3c */
if(!s->budget--) { s->failed_pc=0x0c091c3cu; return 0; }
r[15]+=0xffffffe0u;
goto P_0c091c3e;
P_0c091c3e: /* original 1f65, guest PC 0x0c091c3e */
if(!s->budget--) { s->failed_pc=0x0c091c3eu; return 0; }
write(ram,r[15]+20,r[6],4);
goto P_0c091c40;
P_0c091c40: /* original 9094, guest PC 0x0c091c40 */
if(!s->budget--) { s->failed_pc=0x0c091c40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091d6cu,2);
goto P_0c091c42;
P_0c091c42: /* original 0c5e, guest PC 0x0c091c42 */
if(!s->budget--) { s->failed_pc=0x0c091c42u; return 0; }
r[12]=read(ram,r[5]+r[0],4);
goto P_0c091c44;
P_0c091c44: /* original 7004, guest PC 0x0c091c44 */
if(!s->budget--) { s->failed_pc=0x0c091c44u; return 0; }
r[0]+=0x00000004u;
goto P_0c091c46;
P_0c091c46: /* original 045e, guest PC 0x0c091c46 */
if(!s->budget--) { s->failed_pc=0x0c091c46u; return 0; }
r[4]=read(ram,r[5]+r[0],4);
goto P_0c091c48;
P_0c091c48: /* original 63c1, guest PC 0x0c091c48 */
if(!s->budget--) { s->failed_pc=0x0c091c48u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[3]=tmp;
goto P_0c091c4a;
P_0c091c4a: /* original 6943, guest PC 0x0c091c4a */
if(!s->budget--) { s->failed_pc=0x0c091c4au; return 0; }
r[9]=r[4];
goto P_0c091c4c;
P_0c091c4c: /* original 793c, guest PC 0x0c091c4c */
if(!s->budget--) { s->failed_pc=0x0c091c4cu; return 0; }
r[9]+=0x0000003cu;
goto P_0c091c4e;
P_0c091c4e: /* original 2f31, guest PC 0x0c091c4e */
if(!s->budget--) { s->failed_pc=0x0c091c4eu; return 0; }
write(ram,r[15],r[3],2);
goto P_0c091c50;
P_0c091c50: /* original 6a43, guest PC 0x0c091c50 */
if(!s->budget--) { s->failed_pc=0x0c091c50u; return 0; }
r[10]=r[4];
goto P_0c091c52;
P_0c091c52: /* original d347, guest PC 0x0c091c52 */
if(!s->budget--) { s->failed_pc=0x0c091c52u; return 0; }
r[3]=read(ram,0x0c091d70u,4);
goto P_0c091c54;
P_0c091c54: /* original 430b, guest PC 0x0c091c54 */
if(!s->budget--) { s->failed_pc=0x0c091c54u; return 0; }
target=r[3];
r[16]=0x0c091c58u;
r[4]=read(ram,r[15]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091c58u) { target=s->pc; goto dispatch; }
goto P_0c091c58;
P_0c091c56: /* original 54f5, guest PC 0x0c091c56 */
if(!s->budget--) { s->failed_pc=0x0c091c56u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c091c58;
P_0c091c58: /* original d246, guest PC 0x0c091c58 */
if(!s->budget--) { s->failed_pc=0x0c091c58u; return 0; }
r[2]=read(ram,0x0c091d74u,4);
goto P_0c091c5a;
P_0c091c5a: /* original 420b, guest PC 0x0c091c5a */
if(!s->budget--) { s->failed_pc=0x0c091c5au; return 0; }
target=r[2];
r[16]=0x0c091c5eu;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091c5eu) { target=s->pc; goto dispatch; }
goto P_0c091c5e;
P_0c091c5c: /* original e400, guest PC 0x0c091c5c */
if(!s->budget--) { s->failed_pc=0x0c091c5cu; return 0; }
r[4]=0x00000000u;
goto P_0c091c5e;
P_0c091c5e: /* original 2bb8, guest PC 0x0c091c5e */
if(!s->budget--) { s->failed_pc=0x0c091c5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c091c60;
P_0c091c60: /* original 8b02, guest PC 0x0c091c60 */
if(!s->budget--) { s->failed_pc=0x0c091c60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091c68; }
goto P_0c091c62;
P_0c091c62: /* original d245, guest PC 0x0c091c62 */
if(!s->budget--) { s->failed_pc=0x0c091c62u; return 0; }
r[2]=read(ram,0x0c091d78u,4);
goto P_0c091c64;
P_0c091c64: /* original 420b, guest PC 0x0c091c64 */
if(!s->budget--) { s->failed_pc=0x0c091c64u; return 0; }
target=r[2];
r[16]=0x0c091c68u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091c68u) { target=s->pc; goto dispatch; }
goto P_0c091c68;
P_0c091c66: /* original 0009, guest PC 0x0c091c66 */
if(!s->budget--) { s->failed_pc=0x0c091c66u; return 0; }
goto P_0c091c68;
P_0c091c68: /* original d344, guest PC 0x0c091c68 */
if(!s->budget--) { s->failed_pc=0x0c091c68u; return 0; }
r[3]=read(ram,0x0c091d7cu,4);
goto P_0c091c6a;
P_0c091c6a: /* original 430b, guest PC 0x0c091c6a */
if(!s->budget--) { s->failed_pc=0x0c091c6au; return 0; }
target=r[3];
r[16]=0x0c091c6eu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091c6eu) { target=s->pc; goto dispatch; }
goto P_0c091c6e;
P_0c091c6c: /* original e401, guest PC 0x0c091c6c */
if(!s->budget--) { s->failed_pc=0x0c091c6cu; return 0; }
r[4]=0x00000001u;
goto P_0c091c6e;
P_0c091c6e: /* original 64f1, guest PC 0x0c091c6e */
if(!s->budget--) { s->failed_pc=0x0c091c6eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c091c70;
P_0c091c70: /* original d843, guest PC 0x0c091c70 */
if(!s->budget--) { s->failed_pc=0x0c091c70u; return 0; }
r[8]=read(ram,0x0c091d80u,4);
goto P_0c091c72;
P_0c091c72: /* original 480b, guest PC 0x0c091c72 */
if(!s->budget--) { s->failed_pc=0x0c091c72u; return 0; }
target=r[8];
r[16]=0x0c091c76u;
r[4]=r[4]&65535u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091c76u) { target=s->pc; goto dispatch; }
goto P_0c091c76;
P_0c091c74: /* original 644d, guest PC 0x0c091c74 */
if(!s->budget--) { s->failed_pc=0x0c091c74u; return 0; }
r[4]=r[4]&65535u;
goto P_0c091c76;
P_0c091c76: /* original d33f, guest PC 0x0c091c76 */
if(!s->budget--) { s->failed_pc=0x0c091c76u; return 0; }
r[3]=read(ram,0x0c091d74u,4);
goto P_0c091c78;
P_0c091c78: /* original 6ec3, guest PC 0x0c091c78 */
if(!s->budget--) { s->failed_pc=0x0c091c78u; return 0; }
r[14]=r[12];
goto P_0c091c7a;
P_0c091c7a: /* original 7e02, guest PC 0x0c091c7a */
if(!s->budget--) { s->failed_pc=0x0c091c7au; return 0; }
r[14]+=0x00000002u;
goto P_0c091c7c;
P_0c091c7c: /* original 430b, guest PC 0x0c091c7c */
if(!s->budget--) { s->failed_pc=0x0c091c7cu; return 0; }
target=r[3];
r[16]=0x0c091c80u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091c80u) { target=s->pc; goto dispatch; }
goto P_0c091c80;
P_0c091c7e: /* original e400, guest PC 0x0c091c7e */
if(!s->budget--) { s->failed_pc=0x0c091c7eu; return 0; }
r[4]=0x00000000u;
goto P_0c091c80;
P_0c091c80: /* original e200, guest PC 0x0c091c80 */
if(!s->budget--) { s->failed_pc=0x0c091c80u; return 0; }
r[2]=0x00000000u;
goto P_0c091c82;
P_0c091c82: /* original 2f22, guest PC 0x0c091c82 */
if(!s->budget--) { s->failed_pc=0x0c091c82u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c091c84;
P_0c091c84: /* original d33f, guest PC 0x0c091c84 */
if(!s->budget--) { s->failed_pc=0x0c091c84u; return 0; }
r[3]=read(ram,0x0c091d84u,4);
goto P_0c091c86;
P_0c091c86: /* original ff8d, guest PC 0x0c091c86 */
if(!s->budget--) { s->failed_pc=0x0c091c86u; return 0; }
fr[15]=0;
goto P_0c091c88;
P_0c091c88: /* original 1f35, guest PC 0x0c091c88 */
if(!s->budget--) { s->failed_pc=0x0c091c88u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c091c8a;
P_0c091c8a: /* original 60d1, guest PC 0x0c091c8a */
if(!s->budget--) { s->failed_pc=0x0c091c8au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[0]=tmp;
goto P_0c091c8c;
P_0c091c8c: /* original 2bb8, guest PC 0x0c091c8c */
if(!s->budget--) { s->failed_pc=0x0c091c8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c091c8e;
P_0c091c8e: /* original 81f4, guest PC 0x0c091c8e */
if(!s->budget--) { s->failed_pc=0x0c091c8eu; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c091c90;
P_0c091c90: /* original 85d1, guest PC 0x0c091c90 */
if(!s->budget--) { s->failed_pc=0x0c091c90u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+2,2);
goto P_0c091c92;
P_0c091c92: /* original 81fe, guest PC 0x0c091c92 */
if(!s->budget--) { s->failed_pc=0x0c091c92u; return 0; }
write(ram,r[15]+28,r[0],2);
goto P_0c091c94;
P_0c091c94: /* original 85d2, guest PC 0x0c091c94 */
if(!s->budget--) { s->failed_pc=0x0c091c94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+4,2);
goto P_0c091c96;
P_0c091c96: /* original 81f6, guest PC 0x0c091c96 */
if(!s->budget--) { s->failed_pc=0x0c091c96u; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c091c98;
P_0c091c98: /* original 85d3, guest PC 0x0c091c98 */
if(!s->budget--) { s->failed_pc=0x0c091c98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+6,2);
goto P_0c091c9a;
P_0c091c9a: /* original 81f2, guest PC 0x0c091c9a */
if(!s->budget--) { s->failed_pc=0x0c091c9au; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c091c9c;
P_0c091c9c: /* original 85d4, guest PC 0x0c091c9c */
if(!s->budget--) { s->failed_pc=0x0c091c9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+8,2);
goto P_0c091c9e;
P_0c091c9e: /* original 81f8, guest PC 0x0c091c9e */
if(!s->budget--) { s->failed_pc=0x0c091c9eu; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c091ca0;
P_0c091ca0: /* original f4a9, guest PC 0x0c091ca0 */
if(!s->budget--) { s->failed_pc=0x0c091ca0u; return 0; }
vf3_matrix_load(s,ram,4,r[10]);
r[10]+=(r[18]&0x100000u)?8:4;
goto P_0c091ca2;
P_0c091ca2: /* original fd99, guest PC 0x0c091ca2 */
if(!s->budget--) { s->failed_pc=0x0c091ca2u; return 0; }
vf3_matrix_load(s,ram,13,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c091ca4;
P_0c091ca4: /* original f5a9, guest PC 0x0c091ca4 */
if(!s->budget--) { s->failed_pc=0x0c091ca4u; return 0; }
vf3_matrix_load(s,ram,5,r[10]);
r[10]+=(r[18]&0x100000u)?8:4;
goto P_0c091ca6;
P_0c091ca6: /* original f6a9, guest PC 0x0c091ca6 */
if(!s->budget--) { s->failed_pc=0x0c091ca6u; return 0; }
vf3_matrix_load(s,ram,6,r[10]);
r[10]+=(r[18]&0x100000u)?8:4;
goto P_0c091ca8;
P_0c091ca8: /* original 8f0d, guest PC 0x0c091ca8 */
if(!s->budget--) { s->failed_pc=0x0c091ca8u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,14,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
if(!cond) { goto P_0c091cc6; }
goto P_0c091cac;
P_0c091caa: /* original fe99, guest PC 0x0c091caa */
if(!s->budget--) { s->failed_pc=0x0c091caau; return 0; }
vf3_matrix_load(s,ram,14,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c091cac;
P_0c091cac: /* original 85f4, guest PC 0x0c091cac */
if(!s->budget--) { s->failed_pc=0x0c091cacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c091cae;
P_0c091cae: /* original 600b, guest PC 0x0c091cae */
if(!s->budget--) { s->failed_pc=0x0c091caeu; return 0; }
r[0]=0u-r[0];
goto P_0c091cb0;
P_0c091cb0: /* original 81f4, guest PC 0x0c091cb0 */
if(!s->budget--) { s->failed_pc=0x0c091cb0u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c091cb2;
P_0c091cb2: /* original 85f6, guest PC 0x0c091cb2 */
if(!s->budget--) { s->failed_pc=0x0c091cb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c091cb4;
P_0c091cb4: /* original 600b, guest PC 0x0c091cb4 */
if(!s->budget--) { s->failed_pc=0x0c091cb4u; return 0; }
r[0]=0u-r[0];
goto P_0c091cb6;
P_0c091cb6: /* original 81f6, guest PC 0x0c091cb6 */
if(!s->budget--) { s->failed_pc=0x0c091cb6u; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c091cb8;
P_0c091cb8: /* original 85f2, guest PC 0x0c091cb8 */
if(!s->budget--) { s->failed_pc=0x0c091cb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c091cba;
P_0c091cba: /* original 600b, guest PC 0x0c091cba */
if(!s->budget--) { s->failed_pc=0x0c091cbau; return 0; }
r[0]=0u-r[0];
goto P_0c091cbc;
P_0c091cbc: /* original 81f2, guest PC 0x0c091cbc */
if(!s->budget--) { s->failed_pc=0x0c091cbcu; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c091cbe;
P_0c091cbe: /* original 85f8, guest PC 0x0c091cbe */
if(!s->budget--) { s->failed_pc=0x0c091cbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c091cc0;
P_0c091cc0: /* original 600b, guest PC 0x0c091cc0 */
if(!s->budget--) { s->failed_pc=0x0c091cc0u; return 0; }
r[0]=0u-r[0];
goto P_0c091cc2;
P_0c091cc2: /* original 81f8, guest PC 0x0c091cc2 */
if(!s->budget--) { s->failed_pc=0x0c091cc2u; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c091cc4;
P_0c091cc4: /* original f64d, guest PC 0x0c091cc4 */
if(!s->budget--) { s->failed_pc=0x0c091cc4u; return 0; }
fr[6]^=0x80000000u;
goto P_0c091cc6;
P_0c091cc6: /* original 63f2, guest PC 0x0c091cc6 */
if(!s->budget--) { s->failed_pc=0x0c091cc6u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c091cc8;
P_0c091cc8: /* original 2338, guest PC 0x0c091cc8 */
if(!s->budget--) { s->failed_pc=0x0c091cc8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c091cca;
P_0c091cca: /* original 8d03, guest PC 0x0c091cca */
if(!s->budget--) { s->failed_pc=0x0c091ccau; return 0; }
cond=r[17]&1u;
fr[6]^=0x80000000u;
if(cond) { goto P_0c091cd4; }
goto P_0c091cce;
P_0c091ccc: /* original f64d, guest PC 0x0c091ccc */
if(!s->budget--) { s->failed_pc=0x0c091cccu; return 0; }
fr[6]^=0x80000000u;
goto P_0c091cce;
P_0c091cce: /* original d32e, guest PC 0x0c091cce */
if(!s->budget--) { s->failed_pc=0x0c091cceu; return 0; }
r[3]=read(ram,0x0c091d88u,4);
goto P_0c091cd0;
P_0c091cd0: /* original 430b, guest PC 0x0c091cd0 */
if(!s->budget--) { s->failed_pc=0x0c091cd0u; return 0; }
target=r[3];
r[16]=0x0c091cd4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091cd4u) { target=s->pc; goto dispatch; }
goto P_0c091cd4;
P_0c091cd2: /* original 0009, guest PC 0x0c091cd2 */
if(!s->budget--) { s->failed_pc=0x0c091cd2u; return 0; }
goto P_0c091cd4;
P_0c091cd4: /* original 60e5, guest PC 0x0c091cd4 */
if(!s->budget--) { s->failed_pc=0x0c091cd4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[0]=tmp;
goto P_0c091cd6;
P_0c091cd6: /* original 81fc, guest PC 0x0c091cd6 */
if(!s->budget--) { s->failed_pc=0x0c091cd6u; return 0; }
write(ram,r[15]+24,r[0],2);
goto P_0c091cd8;
P_0c091cd8: /* original d32c, guest PC 0x0c091cd8 */
if(!s->budget--) { s->failed_pc=0x0c091cd8u; return 0; }
r[3]=read(ram,0x0c091d8cu,4);
goto P_0c091cda;
P_0c091cda: /* original 85fe, guest PC 0x0c091cda */
if(!s->budget--) { s->failed_pc=0x0c091cdau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+28,2);
goto P_0c091cdc;
P_0c091cdc: /* original 430b, guest PC 0x0c091cdc */
if(!s->budget--) { s->failed_pc=0x0c091cdcu; return 0; }
target=r[3];
r[16]=0x0c091ce0u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091ce0u) { target=s->pc; goto dispatch; }
goto P_0c091ce0;
P_0c091cde: /* original 6403, guest PC 0x0c091cde */
if(!s->budget--) { s->failed_pc=0x0c091cdeu; return 0; }
r[4]=r[0];
goto P_0c091ce0;
P_0c091ce0: /* original d32b, guest PC 0x0c091ce0 */
if(!s->budget--) { s->failed_pc=0x0c091ce0u; return 0; }
r[3]=read(ram,0x0c091d90u,4);
goto P_0c091ce2;
P_0c091ce2: /* original 85f4, guest PC 0x0c091ce2 */
if(!s->budget--) { s->failed_pc=0x0c091ce2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c091ce4;
P_0c091ce4: /* original 430b, guest PC 0x0c091ce4 */
if(!s->budget--) { s->failed_pc=0x0c091ce4u; return 0; }
target=r[3];
r[16]=0x0c091ce8u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091ce8u) { target=s->pc; goto dispatch; }
goto P_0c091ce8;
P_0c091ce6: /* original 6403, guest PC 0x0c091ce6 */
if(!s->budget--) { s->failed_pc=0x0c091ce6u; return 0; }
r[4]=r[0];
goto P_0c091ce8;
P_0c091ce8: /* original d32a, guest PC 0x0c091ce8 */
if(!s->budget--) { s->failed_pc=0x0c091ce8u; return 0; }
r[3]=read(ram,0x0c091d94u,4);
goto P_0c091cea;
P_0c091cea: /* original 85f6, guest PC 0x0c091cea */
if(!s->budget--) { s->failed_pc=0x0c091ceau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c091cec;
P_0c091cec: /* original 430b, guest PC 0x0c091cec */
if(!s->budget--) { s->failed_pc=0x0c091cecu; return 0; }
target=r[3];
r[16]=0x0c091cf0u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091cf0u) { target=s->pc; goto dispatch; }
goto P_0c091cf0;
P_0c091cee: /* original 6403, guest PC 0x0c091cee */
if(!s->budget--) { s->failed_pc=0x0c091ceeu; return 0; }
r[4]=r[0];
goto P_0c091cf0;
P_0c091cf0: /* original 85fc, guest PC 0x0c091cf0 */
if(!s->budget--) { s->failed_pc=0x0c091cf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+24,2);
goto P_0c091cf2;
P_0c091cf2: /* original 6403, guest PC 0x0c091cf2 */
if(!s->budget--) { s->failed_pc=0x0c091cf2u; return 0; }
r[4]=r[0];
goto P_0c091cf4;
P_0c091cf4: /* original 480b, guest PC 0x0c091cf4 */
if(!s->budget--) { s->failed_pc=0x0c091cf4u; return 0; }
target=r[8];
r[16]=0x0c091cf8u;
r[4]=r[4]&65535u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091cf8u) { target=s->pc; goto dispatch; }
goto P_0c091cf8;
P_0c091cf6: /* original 644d, guest PC 0x0c091cf6 */
if(!s->budget--) { s->failed_pc=0x0c091cf6u; return 0; }
r[4]=r[4]&65535u;
goto P_0c091cf8;
P_0c091cf8: /* original 60e5, guest PC 0x0c091cf8 */
if(!s->budget--) { s->failed_pc=0x0c091cf8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[0]=tmp;
goto P_0c091cfa;
P_0c091cfa: /* original 81f4, guest PC 0x0c091cfa */
if(!s->budget--) { s->failed_pc=0x0c091cfau; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c091cfc;
P_0c091cfc: /* original d322, guest PC 0x0c091cfc */
if(!s->budget--) { s->failed_pc=0x0c091cfcu; return 0; }
r[3]=read(ram,0x0c091d88u,4);
goto P_0c091cfe;
P_0c091cfe: /* original f5fc, guest PC 0x0c091cfe */
if(!s->budget--) { s->failed_pc=0x0c091cfeu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c091d00;
P_0c091d00: /* original f6fc, guest PC 0x0c091d00 */
if(!s->budget--) { s->failed_pc=0x0c091d00u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c091d02;
P_0c091d02: /* original 430b, guest PC 0x0c091d02 */
if(!s->budget--) { s->failed_pc=0x0c091d02u; return 0; }
target=r[3];
r[16]=0x0c091d06u;
vf3_matrix_move(s,4,13);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091d06u) { target=s->pc; goto dispatch; }
goto P_0c091d06;
P_0c091d04: /* original f4dc, guest PC 0x0c091d04 */
if(!s->budget--) { s->failed_pc=0x0c091d04u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c091d06;
P_0c091d06: /* original d323, guest PC 0x0c091d06 */
if(!s->budget--) { s->failed_pc=0x0c091d06u; return 0; }
r[3]=read(ram,0x0c091d94u,4);
goto P_0c091d08;
P_0c091d08: /* original 85f2, guest PC 0x0c091d08 */
if(!s->budget--) { s->failed_pc=0x0c091d08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c091d0a;
P_0c091d0a: /* original 430b, guest PC 0x0c091d0a */
if(!s->budget--) { s->failed_pc=0x0c091d0au; return 0; }
target=r[3];
r[16]=0x0c091d0eu;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091d0eu) { target=s->pc; goto dispatch; }
goto P_0c091d0e;
P_0c091d0c: /* original 6403, guest PC 0x0c091d0c */
if(!s->budget--) { s->failed_pc=0x0c091d0cu; return 0; }
r[4]=r[0];
goto P_0c091d0e;
P_0c091d0e: /* original 85f4, guest PC 0x0c091d0e */
if(!s->budget--) { s->failed_pc=0x0c091d0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c091d10;
P_0c091d10: /* original 6403, guest PC 0x0c091d10 */
if(!s->budget--) { s->failed_pc=0x0c091d10u; return 0; }
r[4]=r[0];
goto P_0c091d12;
P_0c091d12: /* original 480b, guest PC 0x0c091d12 */
if(!s->budget--) { s->failed_pc=0x0c091d12u; return 0; }
target=r[8];
r[16]=0x0c091d16u;
r[4]=r[4]&65535u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091d16u) { target=s->pc; goto dispatch; }
goto P_0c091d16;
P_0c091d14: /* original 644d, guest PC 0x0c091d14 */
if(!s->budget--) { s->failed_pc=0x0c091d14u; return 0; }
r[4]=r[4]&65535u;
goto P_0c091d16;
P_0c091d16: /* original 60e5, guest PC 0x0c091d16 */
if(!s->budget--) { s->failed_pc=0x0c091d16u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[0]=tmp;
goto P_0c091d18;
P_0c091d18: /* original 81f2, guest PC 0x0c091d18 */
if(!s->budget--) { s->failed_pc=0x0c091d18u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c091d1a;
P_0c091d1a: /* original d31b, guest PC 0x0c091d1a */
if(!s->budget--) { s->failed_pc=0x0c091d1au; return 0; }
r[3]=read(ram,0x0c091d88u,4);
goto P_0c091d1c;
P_0c091d1c: /* original f5fc, guest PC 0x0c091d1c */
if(!s->budget--) { s->failed_pc=0x0c091d1cu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c091d1e;
P_0c091d1e: /* original f6fc, guest PC 0x0c091d1e */
if(!s->budget--) { s->failed_pc=0x0c091d1eu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c091d20;
P_0c091d20: /* original 430b, guest PC 0x0c091d20 */
if(!s->budget--) { s->failed_pc=0x0c091d20u; return 0; }
target=r[3];
r[16]=0x0c091d24u;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091d24u) { target=s->pc; goto dispatch; }
goto P_0c091d24;
P_0c091d22: /* original f4ec, guest PC 0x0c091d22 */
if(!s->budget--) { s->failed_pc=0x0c091d22u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c091d24;
P_0c091d24: /* original d31b, guest PC 0x0c091d24 */
if(!s->budget--) { s->failed_pc=0x0c091d24u; return 0; }
r[3]=read(ram,0x0c091d94u,4);
goto P_0c091d26;
P_0c091d26: /* original 85f8, guest PC 0x0c091d26 */
if(!s->budget--) { s->failed_pc=0x0c091d26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c091d28;
P_0c091d28: /* original 430b, guest PC 0x0c091d28 */
if(!s->budget--) { s->failed_pc=0x0c091d28u; return 0; }
target=r[3];
r[16]=0x0c091d2cu;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091d2cu) { target=s->pc; goto dispatch; }
goto P_0c091d2c;
P_0c091d2a: /* original 6403, guest PC 0x0c091d2a */
if(!s->budget--) { s->failed_pc=0x0c091d2au; return 0; }
r[4]=r[0];
goto P_0c091d2c;
P_0c091d2c: /* original 85f2, guest PC 0x0c091d2c */
if(!s->budget--) { s->failed_pc=0x0c091d2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c091d2e;
P_0c091d2e: /* original 6403, guest PC 0x0c091d2e */
if(!s->budget--) { s->failed_pc=0x0c091d2eu; return 0; }
r[4]=r[0];
goto P_0c091d30;
P_0c091d30: /* original 480b, guest PC 0x0c091d30 */
if(!s->budget--) { s->failed_pc=0x0c091d30u; return 0; }
target=r[8];
r[16]=0x0c091d34u;
r[4]=r[4]&65535u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091d34u) { target=s->pc; goto dispatch; }
goto P_0c091d34;
P_0c091d32: /* original 644d, guest PC 0x0c091d32 */
if(!s->budget--) { s->failed_pc=0x0c091d32u; return 0; }
r[4]=r[4]&65535u;
goto P_0c091d34;
P_0c091d34: /* original 54f5, guest PC 0x0c091d34 */
if(!s->budget--) { s->failed_pc=0x0c091d34u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c091d36;
P_0c091d36: /* original fbfd, guest PC 0x0c091d36 */
if(!s->budget--) { s->failed_pc=0x0c091d36u; return 0; }
vf3_matrix_swap(s);
goto P_0c091d38;
P_0c091d38: /* original 63f2, guest PC 0x0c091d38 */
if(!s->budget--) { s->failed_pc=0x0c091d38u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c091d3a;
P_0c091d3a: /* original e205, guest PC 0x0c091d3a */
if(!s->budget--) { s->failed_pc=0x0c091d3au; return 0; }
r[2]=0x00000005u;
goto P_0c091d3c;
P_0c091d3c: /* original 5442, guest PC 0x0c091d3c */
if(!s->budget--) { s->failed_pc=0x0c091d3cu; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c091d3e;
P_0c091d3e: /* original 7d0a, guest PC 0x0c091d3e */
if(!s->budget--) { s->failed_pc=0x0c091d3eu; return 0; }
r[13]+=0x0000000au;
goto P_0c091d40;
P_0c091d40: /* original 7301, guest PC 0x0c091d40 */
if(!s->budget--) { s->failed_pc=0x0c091d40u; return 0; }
r[3]+=0x00000001u;
goto P_0c091d42;
P_0c091d42: /* original 74c0, guest PC 0x0c091d42 */
if(!s->budget--) { s->failed_pc=0x0c091d42u; return 0; }
r[4]+=0xffffffc0u;
goto P_0c091d44;
P_0c091d44: /* original 3323, guest PC 0x0c091d44 */
if(!s->budget--) { s->failed_pc=0x0c091d44u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c091d46;
P_0c091d46: /* original f049, guest PC 0x0c091d46 */
if(!s->budget--) { s->failed_pc=0x0c091d46u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d48;
P_0c091d48: /* original f149, guest PC 0x0c091d48 */
if(!s->budget--) { s->failed_pc=0x0c091d48u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d4a;
P_0c091d4a: /* original f249, guest PC 0x0c091d4a */
if(!s->budget--) { s->failed_pc=0x0c091d4au; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d4c;
P_0c091d4c: /* original f349, guest PC 0x0c091d4c */
if(!s->budget--) { s->failed_pc=0x0c091d4cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d4e;
P_0c091d4e: /* original f449, guest PC 0x0c091d4e */
if(!s->budget--) { s->failed_pc=0x0c091d4eu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d50;
P_0c091d50: /* original f549, guest PC 0x0c091d50 */
if(!s->budget--) { s->failed_pc=0x0c091d50u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d52;
P_0c091d52: /* original f649, guest PC 0x0c091d52 */
if(!s->budget--) { s->failed_pc=0x0c091d52u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d54;
P_0c091d54: /* original f749, guest PC 0x0c091d54 */
if(!s->budget--) { s->failed_pc=0x0c091d54u; return 0; }
vf3_matrix_load(s,ram,7,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d56;
P_0c091d56: /* original f849, guest PC 0x0c091d56 */
if(!s->budget--) { s->failed_pc=0x0c091d56u; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d58;
P_0c091d58: /* original f949, guest PC 0x0c091d58 */
if(!s->budget--) { s->failed_pc=0x0c091d58u; return 0; }
vf3_matrix_load(s,ram,9,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d5a;
P_0c091d5a: /* original fa49, guest PC 0x0c091d5a */
if(!s->budget--) { s->failed_pc=0x0c091d5au; return 0; }
vf3_matrix_load(s,ram,10,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d5c;
P_0c091d5c: /* original fb49, guest PC 0x0c091d5c */
if(!s->budget--) { s->failed_pc=0x0c091d5cu; return 0; }
vf3_matrix_load(s,ram,11,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d5e;
P_0c091d5e: /* original fc49, guest PC 0x0c091d5e */
if(!s->budget--) { s->failed_pc=0x0c091d5eu; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d60;
P_0c091d60: /* original fd49, guest PC 0x0c091d60 */
if(!s->budget--) { s->failed_pc=0x0c091d60u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d62;
P_0c091d62: /* original fe49, guest PC 0x0c091d62 */
if(!s->budget--) { s->failed_pc=0x0c091d62u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d64;
P_0c091d64: /* original ff49, guest PC 0x0c091d64 */
if(!s->budget--) { s->failed_pc=0x0c091d64u; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d66;
P_0c091d66: /* original fbfd, guest PC 0x0c091d66 */
if(!s->budget--) { s->failed_pc=0x0c091d66u; return 0; }
vf3_matrix_swap(s);
goto P_0c091d68;
P_0c091d68: /* original a016, guest PC 0x0c091d68 */
if(!s->budget--) { s->failed_pc=0x0c091d68u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c091d98;
P_0c091d6a: /* original 2f32, guest PC 0x0c091d6a */
if(!s->budget--) { s->failed_pc=0x0c091d6au; return 0; }
write(ram,r[15],r[3],4);
return vf3_matrix_family(0x0c091d6cu,s,ram);
P_0c091d98: /* original 8d02, guest PC 0x0c091d98 */
if(!s->budget--) { s->failed_pc=0x0c091d98u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091da0; }
goto P_0c091d9c;
P_0c091d9a: /* original 0009, guest PC 0x0c091d9a */
if(!s->budget--) { s->failed_pc=0x0c091d9au; return 0; }
goto P_0c091d9c;
P_0c091d9c: /* original af75, guest PC 0x0c091d9c */
if(!s->budget--) { s->failed_pc=0x0c091d9cu; return 0; }
goto P_0c091c8a;
P_0c091d9e: /* original 0009, guest PC 0x0c091d9e */
if(!s->budget--) { s->failed_pc=0x0c091d9eu; return 0; }
goto P_0c091da0;
P_0c091da0: /* original 7f20, guest PC 0x0c091da0 */
if(!s->budget--) { s->failed_pc=0x0c091da0u; return 0; }
r[15]+=0x00000020u;
goto P_0c091da2;
P_0c091da2: /* original d332, guest PC 0x0c091da2 */
if(!s->budget--) { s->failed_pc=0x0c091da2u; return 0; }
r[3]=read(ram,0x0c091e6cu,4);
goto P_0c091da4;
P_0c091da4: /* original 4f26, guest PC 0x0c091da4 */
if(!s->budget--) { s->failed_pc=0x0c091da4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c091da6;
P_0c091da6: /* original e401, guest PC 0x0c091da6 */
if(!s->budget--) { s->failed_pc=0x0c091da6u; return 0; }
r[4]=0x00000001u;
goto P_0c091da8;
P_0c091da8: /* original fdf9, guest PC 0x0c091da8 */
if(!s->budget--) { s->failed_pc=0x0c091da8u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c091daa;
P_0c091daa: /* original fef9, guest PC 0x0c091daa */
if(!s->budget--) { s->failed_pc=0x0c091daau; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c091dac;
P_0c091dac: /* original fff9, guest PC 0x0c091dac */
if(!s->budget--) { s->failed_pc=0x0c091dacu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c091dae;
P_0c091dae: /* original 68f6, guest PC 0x0c091dae */
if(!s->budget--) { s->failed_pc=0x0c091daeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c091db0;
P_0c091db0: /* original 69f6, guest PC 0x0c091db0 */
if(!s->budget--) { s->failed_pc=0x0c091db0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c091db2;
P_0c091db2: /* original 6af6, guest PC 0x0c091db2 */
if(!s->budget--) { s->failed_pc=0x0c091db2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c091db4;
P_0c091db4: /* original 6bf6, guest PC 0x0c091db4 */
if(!s->budget--) { s->failed_pc=0x0c091db4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c091db6;
P_0c091db6: /* original 6cf6, guest PC 0x0c091db6 */
if(!s->budget--) { s->failed_pc=0x0c091db6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c091db8;
P_0c091db8: /* original 6df6, guest PC 0x0c091db8 */
if(!s->budget--) { s->failed_pc=0x0c091db8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c091dba;
P_0c091dba: /* original 432b, guest PC 0x0c091dba */
if(!s->budget--) { s->failed_pc=0x0c091dbau; return 0; }
target=r[3];
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
P_0c091dbc: /* original 6ef6, guest PC 0x0c091dbc */
if(!s->budget--) { s->failed_pc=0x0c091dbcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c091dbeu,s,ram);
P_0c0940c8: /* original 2fe6, guest PC 0x0c0940c8 */
if(!s->budget--) { s->failed_pc=0x0c0940c8u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0940ca;
P_0c0940ca: /* original e140, guest PC 0x0c0940ca */
if(!s->budget--) { s->failed_pc=0x0c0940cau; return 0; }
r[1]=0x00000040u;
goto P_0c0940cc;
P_0c0940cc: /* original 2fd6, guest PC 0x0c0940cc */
if(!s->budget--) { s->failed_pc=0x0c0940ccu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0940ce;
P_0c0940ce: /* original 6d43, guest PC 0x0c0940ce */
if(!s->budget--) { s->failed_pc=0x0c0940ceu; return 0; }
r[13]=r[4];
goto P_0c0940d0;
P_0c0940d0: /* original 2fc6, guest PC 0x0c0940d0 */
if(!s->budget--) { s->failed_pc=0x0c0940d0u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0940d2;
P_0c0940d2: /* original d243, guest PC 0x0c0940d2 */
if(!s->budget--) { s->failed_pc=0x0c0940d2u; return 0; }
r[2]=read(ram,0x0c0941e0u,4);
goto P_0c0940d4;
P_0c0940d4: /* original d341, guest PC 0x0c0940d4 */
if(!s->budget--) { s->failed_pc=0x0c0940d4u; return 0; }
r[3]=read(ram,0x0c0941dcu,4);
goto P_0c0940d6;
P_0c0940d6: /* original 6422, guest PC 0x0c0940d6 */
if(!s->budget--) { s->failed_pc=0x0c0940d6u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0940d8;
P_0c0940d8: /* original 4f22, guest PC 0x0c0940d8 */
if(!s->budget--) { s->failed_pc=0x0c0940d8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0940da;
P_0c0940da: /* original 6e32, guest PC 0x0c0940da */
if(!s->budget--) { s->failed_pc=0x0c0940dau; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c0940dc;
P_0c0940dc: /* original 2148, guest PC 0x0c0940dc */
if(!s->budget--) { s->failed_pc=0x0c0940dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c0940de;
P_0c0940de: /* original 8b34, guest PC 0x0c0940de */
if(!s->budget--) { s->failed_pc=0x0c0940deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09414a; }
goto P_0c0940e0;
P_0c0940e0: /* original 65e2, guest PC 0x0c0940e0 */
if(!s->budget--) { s->failed_pc=0x0c0940e0u; return 0; }
tmp=read(ram,r[14],4);
r[5]=tmp;
goto P_0c0940e2;
P_0c0940e2: /* original e201, guest PC 0x0c0940e2 */
if(!s->budget--) { s->failed_pc=0x0c0940e2u; return 0; }
r[2]=0x00000001u;
goto P_0c0940e4;
P_0c0940e4: /* original 2528, guest PC 0x0c0940e4 */
if(!s->budget--) { s->failed_pc=0x0c0940e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0940e6;
P_0c0940e6: /* original 8930, guest PC 0x0c0940e6 */
if(!s->budget--) { s->failed_pc=0x0c0940e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09414a; }
goto P_0c0940e8;
P_0c0940e8: /* original 9370, guest PC 0x0c0940e8 */
if(!s->budget--) { s->failed_pc=0x0c0940e8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0941ccu,2);
goto P_0c0940ea;
P_0c0940ea: /* original 2438, guest PC 0x0c0940ea */
if(!s->budget--) { s->failed_pc=0x0c0940eau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0940ec;
P_0c0940ec: /* original 8b10, guest PC 0x0c0940ec */
if(!s->budget--) { s->failed_pc=0x0c0940ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094110; }
goto P_0c0940ee;
P_0c0940ee: /* original e060, guest PC 0x0c0940ee */
if(!s->budget--) { s->failed_pc=0x0c0940eeu; return 0; }
r[0]=0x00000060u;
goto P_0c0940f0;
P_0c0940f0: /* original 00dc, guest PC 0x0c0940f0 */
if(!s->budget--) { s->failed_pc=0x0c0940f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0940f2;
P_0c0940f2: /* original 600c, guest PC 0x0c0940f2 */
if(!s->budget--) { s->failed_pc=0x0c0940f2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0940f4;
P_0c0940f4: /* original 880f, guest PC 0x0c0940f4 */
if(!s->budget--) { s->failed_pc=0x0c0940f4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c0940f6;
P_0c0940f6: /* original 8b0b, guest PC 0x0c0940f6 */
if(!s->budget--) { s->failed_pc=0x0c0940f6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094110; }
goto P_0c0940f8;
P_0c0940f8: /* original 85e8, guest PC 0x0c0940f8 */
if(!s->budget--) { s->failed_pc=0x0c0940f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+16,2);
goto P_0c0940fa;
P_0c0940fa: /* original 600d, guest PC 0x0c0940fa */
if(!s->budget--) { s->failed_pc=0x0c0940fau; return 0; }
r[0]=r[0]&65535u;
goto P_0c0940fc;
P_0c0940fc: /* original c801, guest PC 0x0c0940fc */
if(!s->budget--) { s->failed_pc=0x0c0940fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0940fe;
P_0c0940fe: /* original 8b07, guest PC 0x0c0940fe */
if(!s->budget--) { s->failed_pc=0x0c0940feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094110; }
goto P_0c094100;
P_0c094100: /* original 9c65, guest PC 0x0c094100 */
if(!s->budget--) { s->failed_pc=0x0c094100u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0941ceu,2);
goto P_0c094102;
P_0c094102: /* original 3cec, guest PC 0x0c094102 */
if(!s->budget--) { s->failed_pc=0x0c094102u; return 0; }
r[12]+=r[14];
goto P_0c094104;
P_0c094104: /* original 0c83, guest PC 0x0c094104 */
if(!s->budget--) { s->failed_pc=0x0c094104u; return 0; }
goto P_0c094106;
P_0c094106: /* original d337, guest PC 0x0c094106 */
if(!s->budget--) { s->failed_pc=0x0c094106u; return 0; }
r[3]=read(ram,0x0c0941e4u,4);
goto P_0c094108;
P_0c094108: /* original 65c3, guest PC 0x0c094108 */
if(!s->budget--) { s->failed_pc=0x0c094108u; return 0; }
r[5]=r[12];
goto P_0c09410a;
P_0c09410a: /* original 9461, guest PC 0x0c09410a */
if(!s->budget--) { s->failed_pc=0x0c09410au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0941d0u,2);
goto P_0c09410c;
P_0c09410c: /* original 430b, guest PC 0x0c09410c */
if(!s->budget--) { s->failed_pc=0x0c09410cu; return 0; }
target=r[3];
r[16]=0x0c094110u;
r[4]+=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094110u) { target=s->pc; goto dispatch; }
goto P_0c094110;
P_0c09410e: /* original 34dc, guest PC 0x0c09410e */
if(!s->budget--) { s->failed_pc=0x0c09410eu; return 0; }
r[4]+=r[13];
goto P_0c094110;
P_0c094110: /* original 84d4, guest PC 0x0c094110 */
if(!s->budget--) { s->failed_pc=0x0c094110u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+4,1);
goto P_0c094112;
P_0c094112: /* original 67c3, guest PC 0x0c094112 */
if(!s->budget--) { s->failed_pc=0x0c094112u; return 0; }
r[7]=r[12];
goto P_0c094114;
P_0c094114: /* original 925d, guest PC 0x0c094114 */
if(!s->budget--) { s->failed_pc=0x0c094114u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0941d2u,2);
goto P_0c094116;
P_0c094116: /* original 65d3, guest PC 0x0c094116 */
if(!s->budget--) { s->failed_pc=0x0c094116u; return 0; }
r[5]=r[13];
goto P_0c094118;
P_0c094118: /* original 6403, guest PC 0x0c094118 */
if(!s->budget--) { s->failed_pc=0x0c094118u; return 0; }
r[4]=r[0];
goto P_0c09411a;
P_0c09411a: /* original 664c, guest PC 0x0c09411a */
if(!s->budget--) { s->failed_pc=0x0c09411au; return 0; }
r[6]=r[4]&255u;
goto P_0c09411c;
P_0c09411c: /* original 6363, guest PC 0x0c09411c */
if(!s->budget--) { s->failed_pc=0x0c09411cu; return 0; }
r[3]=r[6];
goto P_0c09411e;
P_0c09411e: /* original 4600, guest PC 0x0c09411e */
if(!s->budget--) { s->failed_pc=0x0c09411eu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c094120;
P_0c094120: /* original 363c, guest PC 0x0c094120 */
if(!s->budget--) { s->failed_pc=0x0c094120u; return 0; }
r[6]+=r[3];
goto P_0c094122;
P_0c094122: /* original 6303, guest PC 0x0c094122 */
if(!s->budget--) { s->failed_pc=0x0c094122u; return 0; }
r[3]=r[0];
goto P_0c094124;
P_0c094124: /* original 4618, guest PC 0x0c094124 */
if(!s->budget--) { s->failed_pc=0x0c094124u; return 0; }
r[6]<<=8;
goto P_0c094126;
P_0c094126: /* original 4608, guest PC 0x0c094126 */
if(!s->budget--) { s->failed_pc=0x0c094126u; return 0; }
r[6]<<=2;
goto P_0c094128;
P_0c094128: /* original 4608, guest PC 0x0c094128 */
if(!s->budget--) { s->failed_pc=0x0c094128u; return 0; }
r[6]<<=2;
goto P_0c09412a;
P_0c09412a: /* original 32ec, guest PC 0x0c09412a */
if(!s->budget--) { s->failed_pc=0x0c09412au; return 0; }
r[2]+=r[14];
goto P_0c09412c;
P_0c09412c: /* original 666f, guest PC 0x0c09412c */
if(!s->budget--) { s->failed_pc=0x0c09412cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c09412e;
P_0c09412e: /* original 4408, guest PC 0x0c09412e */
if(!s->budget--) { s->failed_pc=0x0c09412eu; return 0; }
r[4]<<=2;
goto P_0c094130;
P_0c094130: /* original 362c, guest PC 0x0c094130 */
if(!s->budget--) { s->failed_pc=0x0c094130u; return 0; }
r[6]+=r[2];
goto P_0c094132;
P_0c094132: /* original 924f, guest PC 0x0c094132 */
if(!s->budget--) { s->failed_pc=0x0c094132u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0941d4u,2);
goto P_0c094134;
P_0c094134: /* original 343c, guest PC 0x0c094134 */
if(!s->budget--) { s->failed_pc=0x0c094134u; return 0; }
r[4]+=r[3];
goto P_0c094136;
P_0c094136: /* original 4408, guest PC 0x0c094136 */
if(!s->budget--) { s->failed_pc=0x0c094136u; return 0; }
r[4]<<=2;
goto P_0c094138;
P_0c094138: /* original 32ec, guest PC 0x0c094138 */
if(!s->budget--) { s->failed_pc=0x0c094138u; return 0; }
r[2]+=r[14];
goto P_0c09413a;
P_0c09413a: /* original 644e, guest PC 0x0c09413a */
if(!s->budget--) { s->failed_pc=0x0c09413au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c09413c;
P_0c09413c: /* original 342c, guest PC 0x0c09413c */
if(!s->budget--) { s->failed_pc=0x0c09413cu; return 0; }
r[4]+=r[2];
goto P_0c09413e;
P_0c09413e: /* original 8541, guest PC 0x0c09413e */
if(!s->budget--) { s->failed_pc=0x0c09413eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c094140;
P_0c094140: /* original 6403, guest PC 0x0c094140 */
if(!s->budget--) { s->failed_pc=0x0c094140u; return 0; }
r[4]=r[0];
goto P_0c094142;
P_0c094142: /* original 2f06, guest PC 0x0c094142 */
if(!s->budget--) { s->failed_pc=0x0c094142u; return 0; }
r[15]-=4; write(ram,r[15],r[0],4);
goto P_0c094144;
P_0c094144: /* original b006, guest PC 0x0c094144 */
if(!s->budget--) { s->failed_pc=0x0c094144u; return 0; }
target=0x0c094154u; r[16]=0x0c094148u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094148u) { target=s->pc; goto dispatch; }
goto P_0c094148;
P_0c094146: /* original 64e3, guest PC 0x0c094146 */
if(!s->budget--) { s->failed_pc=0x0c094146u; return 0; }
r[4]=r[14];
goto P_0c094148;
P_0c094148: /* original 7f04, guest PC 0x0c094148 */
if(!s->budget--) { s->failed_pc=0x0c094148u; return 0; }
r[15]+=0x00000004u;
goto P_0c09414a;
P_0c09414a: /* original 4f26, guest PC 0x0c09414a */
if(!s->budget--) { s->failed_pc=0x0c09414au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09414c;
P_0c09414c: /* original 6cf6, guest PC 0x0c09414c */
if(!s->budget--) { s->failed_pc=0x0c09414cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09414e;
P_0c09414e: /* original 6df6, guest PC 0x0c09414e */
if(!s->budget--) { s->failed_pc=0x0c09414eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c094150;
P_0c094150: /* original 000b, guest PC 0x0c094150 */
if(!s->budget--) { s->failed_pc=0x0c094150u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c094152: /* original 6ef6, guest PC 0x0c094152 */
if(!s->budget--) { s->failed_pc=0x0c094152u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c094154;
P_0c094154: /* original 2fe6, guest PC 0x0c094154 */
if(!s->budget--) { s->failed_pc=0x0c094154u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c094156;
P_0c094156: /* original 6e63, guest PC 0x0c094156 */
if(!s->budget--) { s->failed_pc=0x0c094156u; return 0; }
r[14]=r[6];
goto P_0c094158;
P_0c094158: /* original 2fd6, guest PC 0x0c094158 */
if(!s->budget--) { s->failed_pc=0x0c094158u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c09415a;
P_0c09415a: /* original 2fc6, guest PC 0x0c09415a */
if(!s->budget--) { s->failed_pc=0x0c09415au; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c09415c;
P_0c09415c: /* original 2fb6, guest PC 0x0c09415c */
if(!s->budget--) { s->failed_pc=0x0c09415cu; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c09415e;
P_0c09415e: /* original 2fa6, guest PC 0x0c09415e */
if(!s->budget--) { s->failed_pc=0x0c09415eu; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c094160;
P_0c094160: /* original 6a73, guest PC 0x0c094160 */
if(!s->budget--) { s->failed_pc=0x0c094160u; return 0; }
r[10]=r[7];
goto P_0c094162;
P_0c094162: /* original 4f22, guest PC 0x0c094162 */
if(!s->budget--) { s->failed_pc=0x0c094162u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c094164;
P_0c094164: /* original 7ff0, guest PC 0x0c094164 */
if(!s->budget--) { s->failed_pc=0x0c094164u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c094166;
P_0c094166: /* original 2f52, guest PC 0x0c094166 */
if(!s->budget--) { s->failed_pc=0x0c094166u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c094168;
P_0c094168: /* original e034, guest PC 0x0c094168 */
if(!s->budget--) { s->failed_pc=0x0c094168u; return 0; }
r[0]=0x00000034u;
goto P_0c09416a;
P_0c09416a: /* original 04ed, guest PC 0x0c09416a */
if(!s->budget--) { s->failed_pc=0x0c09416au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09416c;
P_0c09416c: /* original e302, guest PC 0x0c09416c */
if(!s->budget--) { s->failed_pc=0x0c09416cu; return 0; }
r[3]=0x00000002u;
goto P_0c09416e;
P_0c09416e: /* original 6d4d, guest PC 0x0c09416e */
if(!s->budget--) { s->failed_pc=0x0c09416eu; return 0; }
r[13]=r[4]&65535u;
goto P_0c094170;
P_0c094170: /* original 23d8, guest PC 0x0c094170 */
if(!s->budget--) { s->failed_pc=0x0c094170u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c094172;
P_0c094172: /* original 890b, guest PC 0x0c094172 */
if(!s->budget--) { s->failed_pc=0x0c094172u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09418c; }
goto P_0c094174;
P_0c094174: /* original 53fa, guest PC 0x0c094174 */
if(!s->budget--) { s->failed_pc=0x0c094174u; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c094176;
P_0c094176: /* original 6be3, guest PC 0x0c094176 */
if(!s->budget--) { s->failed_pc=0x0c094176u; return 0; }
r[11]=r[14];
goto P_0c094178;
P_0c094178: /* original 4315, guest PC 0x0c094178 */
if(!s->budget--) { s->failed_pc=0x0c094178u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c09417a;
P_0c09417a: /* original 8d03, guest PC 0x0c09417a */
if(!s->budget--) { s->failed_pc=0x0c09417au; return 0; }
cond=r[17]&1u;
r[11]+=0x00000058u;
if(cond) { goto P_0c094184; }
goto P_0c09417e;
P_0c09417c: /* original 7b58, guest PC 0x0c09417c */
if(!s->budget--) { s->failed_pc=0x0c09417cu; return 0; }
r[11]+=0x00000058u;
goto P_0c09417e;
P_0c09417e: /* original d21a, guest PC 0x0c09417e */
if(!s->budget--) { s->failed_pc=0x0c09417eu; return 0; }
r[2]=read(ram,0x0c0941e8u,4);
goto P_0c094180;
P_0c094180: /* original 422b, guest PC 0x0c094180 */
if(!s->budget--) { s->failed_pc=0x0c094180u; return 0; }
target=r[2];
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
P_0c094182: /* original 0009, guest PC 0x0c094182 */
if(!s->budget--) { s->failed_pc=0x0c094182u; return 0; }
goto P_0c094184;
P_0c094184: /* original 52fa, guest PC 0x0c094184 */
if(!s->budget--) { s->failed_pc=0x0c094184u; return 0; }
r[2]=read(ram,r[15]+40,4);
goto P_0c094186;
P_0c094186: /* original 72ff, guest PC 0x0c094186 */
if(!s->budget--) { s->failed_pc=0x0c094186u; return 0; }
r[2]+=0xffffffffu;
goto P_0c094188;
P_0c094188: /* original a002, guest PC 0x0c094188 */
if(!s->budget--) { s->failed_pc=0x0c094188u; return 0; }
write(ram,r[15]+40,r[2],4);
goto P_0c094190;
P_0c09418a: /* original 1f2a, guest PC 0x0c09418a */
if(!s->budget--) { s->failed_pc=0x0c09418au; return 0; }
write(ram,r[15]+40,r[2],4);
goto P_0c09418c;
P_0c09418c: /* original 6be3, guest PC 0x0c09418c */
if(!s->budget--) { s->failed_pc=0x0c09418cu; return 0; }
r[11]=r[14];
goto P_0c09418e;
P_0c09418e: /* original 7b38, guest PC 0x0c09418e */
if(!s->budget--) { s->failed_pc=0x0c09418eu; return 0; }
r[11]+=0x00000038u;
goto P_0c094190;
P_0c094190: /* original e201, guest PC 0x0c094190 */
if(!s->budget--) { s->failed_pc=0x0c094190u; return 0; }
r[2]=0x00000001u;
goto P_0c094192;
P_0c094192: /* original 22d8, guest PC 0x0c094192 */
if(!s->budget--) { s->failed_pc=0x0c094192u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c094194;
P_0c094194: /* original 8b02, guest PC 0x0c094194 */
if(!s->budget--) { s->failed_pc=0x0c094194u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09419c; }
goto P_0c094196;
P_0c094196: /* original d314, guest PC 0x0c094196 */
if(!s->budget--) { s->failed_pc=0x0c094196u; return 0; }
r[3]=read(ram,0x0c0941e8u,4);
goto P_0c094198;
P_0c094198: /* original 432b, guest PC 0x0c094198 */
if(!s->budget--) { s->failed_pc=0x0c094198u; return 0; }
target=r[3];
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
P_0c09419a: /* original 0009, guest PC 0x0c09419a */
if(!s->budget--) { s->failed_pc=0x0c09419au; return 0; }
goto P_0c09419c;
P_0c09419c: /* original e314, guest PC 0x0c09419c */
if(!s->budget--) { s->failed_pc=0x0c09419cu; return 0; }
r[3]=0x00000014u;
goto P_0c09419e;
P_0c09419e: /* original 23d8, guest PC 0x0c09419e */
if(!s->budget--) { s->failed_pc=0x0c09419eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0941a0;
P_0c0941a0: /* original 8906, guest PC 0x0c0941a0 */
if(!s->budget--) { s->failed_pc=0x0c0941a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0941b0; }
goto P_0c0941a2;
P_0c0941a2: /* original d312, guest PC 0x0c0941a2 */
if(!s->budget--) { s->failed_pc=0x0c0941a2u; return 0; }
r[3]=read(ram,0x0c0941ecu,4);
goto P_0c0941a4;
P_0c0941a4: /* original 65e3, guest PC 0x0c0941a4 */
if(!s->budget--) { s->failed_pc=0x0c0941a4u; return 0; }
r[5]=r[14];
goto P_0c0941a6;
P_0c0941a6: /* original 430b, guest PC 0x0c0941a6 */
if(!s->budget--) { s->failed_pc=0x0c0941a6u; return 0; }
target=r[3];
r[16]=0x0c0941aau;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0941aau) { target=s->pc; goto dispatch; }
goto P_0c0941aa;
P_0c0941a8: /* original 64f2, guest PC 0x0c0941a8 */
if(!s->budget--) { s->failed_pc=0x0c0941a8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0941aa;
P_0c0941aa: /* original d211, guest PC 0x0c0941aa */
if(!s->budget--) { s->failed_pc=0x0c0941aau; return 0; }
r[2]=read(ram,0x0c0941f0u,4);
goto P_0c0941ac;
P_0c0941ac: /* original 422b, guest PC 0x0c0941ac */
if(!s->budget--) { s->failed_pc=0x0c0941acu; return 0; }
target=r[2];
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
P_0c0941ae: /* original 0009, guest PC 0x0c0941ae */
if(!s->budget--) { s->failed_pc=0x0c0941aeu; return 0; }
goto P_0c0941b0;
P_0c0941b0: /* original 9311, guest PC 0x0c0941b0 */
if(!s->budget--) { s->failed_pc=0x0c0941b0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0941d6u,2);
goto P_0c0941b2;
P_0c0941b2: /* original 23d8, guest PC 0x0c0941b2 */
if(!s->budget--) { s->failed_pc=0x0c0941b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0941b4;
P_0c0941b4: /* original 8902, guest PC 0x0c0941b4 */
if(!s->budget--) { s->failed_pc=0x0c0941b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0941bc; }
goto P_0c0941b6;
P_0c0941b6: /* original d20e, guest PC 0x0c0941b6 */
if(!s->budget--) { s->failed_pc=0x0c0941b6u; return 0; }
r[2]=read(ram,0x0c0941f0u,4);
goto P_0c0941b8;
P_0c0941b8: /* original 422b, guest PC 0x0c0941b8 */
if(!s->budget--) { s->failed_pc=0x0c0941b8u; return 0; }
target=r[2];
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
P_0c0941ba: /* original 0009, guest PC 0x0c0941ba */
if(!s->budget--) { s->failed_pc=0x0c0941bau; return 0; }
goto P_0c0941bc;
P_0c0941bc: /* original 920c, guest PC 0x0c0941bc */
if(!s->budget--) { s->failed_pc=0x0c0941bcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0941d8u,2);
goto P_0c0941be;
P_0c0941be: /* original 22d8, guest PC 0x0c0941be */
if(!s->budget--) { s->failed_pc=0x0c0941beu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0941c0;
P_0c0941c0: /* original 8902, guest PC 0x0c0941c0 */
if(!s->budget--) { s->failed_pc=0x0c0941c0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0941c8; }
goto P_0c0941c2;
P_0c0941c2: /* original d30c, guest PC 0x0c0941c2 */
if(!s->budget--) { s->failed_pc=0x0c0941c2u; return 0; }
r[3]=read(ram,0x0c0941f4u,4);
goto P_0c0941c4;
P_0c0941c4: /* original 432b, guest PC 0x0c0941c4 */
if(!s->budget--) { s->failed_pc=0x0c0941c4u; return 0; }
target=r[3];
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
P_0c0941c6: /* original 0009, guest PC 0x0c0941c6 */
if(!s->budget--) { s->failed_pc=0x0c0941c6u; return 0; }
goto P_0c0941c8;
P_0c0941c8: /* original a016, guest PC 0x0c0941c8 */
if(!s->budget--) { s->failed_pc=0x0c0941c8u; return 0; }
goto P_0c0941f8;
P_0c0941ca: /* original 0009, guest PC 0x0c0941ca */
if(!s->budget--) { s->failed_pc=0x0c0941cau; return 0; }
return vf3_matrix_family(0x0c0941ccu,s,ram);
P_0c0941f8: /* original fbfd, guest PC 0x0c0941f8 */
if(!s->budget--) { s->failed_pc=0x0c0941f8u; return 0; }
vf3_matrix_swap(s);
goto P_0c0941fa;
P_0c0941fa: /* original f09d, guest PC 0x0c0941fa */
if(!s->budget--) { s->failed_pc=0x0c0941fau; return 0; }
fr[0]=0x3f800000u;
goto P_0c0941fc;
P_0c0941fc: /* original f18d, guest PC 0x0c0941fc */
if(!s->budget--) { s->failed_pc=0x0c0941fcu; return 0; }
fr[1]=0;
goto P_0c0941fe;
P_0c0941fe: /* original f28d, guest PC 0x0c0941fe */
if(!s->budget--) { s->failed_pc=0x0c0941feu; return 0; }
fr[2]=0;
goto P_0c094200;
P_0c094200: /* original f48d, guest PC 0x0c094200 */
if(!s->budget--) { s->failed_pc=0x0c094200u; return 0; }
fr[4]=0;
goto P_0c094202;
P_0c094202: /* original f59d, guest PC 0x0c094202 */
if(!s->budget--) { s->failed_pc=0x0c094202u; return 0; }
fr[5]=0x3f800000u;
goto P_0c094204;
P_0c094204: /* original f68d, guest PC 0x0c094204 */
if(!s->budget--) { s->failed_pc=0x0c094204u; return 0; }
fr[6]=0;
goto P_0c094206;
P_0c094206: /* original f88d, guest PC 0x0c094206 */
if(!s->budget--) { s->failed_pc=0x0c094206u; return 0; }
fr[8]=0;
goto P_0c094208;
P_0c094208: /* original f98d, guest PC 0x0c094208 */
if(!s->budget--) { s->failed_pc=0x0c094208u; return 0; }
fr[9]=0;
goto P_0c09420a;
P_0c09420a: /* original fa9d, guest PC 0x0c09420a */
if(!s->budget--) { s->failed_pc=0x0c09420au; return 0; }
fr[10]=0x3f800000u;
goto P_0c09420c;
P_0c09420c: /* original fbfd, guest PC 0x0c09420c */
if(!s->budget--) { s->failed_pc=0x0c09420cu; return 0; }
vf3_matrix_swap(s);
goto P_0c09420e;
P_0c09420e: /* original 0009, guest PC 0x0c09420e */
if(!s->budget--) { s->failed_pc=0x0c09420eu; return 0; }
goto P_0c094210;
P_0c094210: /* original 64e3, guest PC 0x0c094210 */
if(!s->budget--) { s->failed_pc=0x0c094210u; return 0; }
r[4]=r[14];
goto P_0c094212;
P_0c094212: /* original 740c, guest PC 0x0c094212 */
if(!s->budget--) { s->failed_pc=0x0c094212u; return 0; }
r[4]+=0x0000000cu;
goto P_0c094214;
P_0c094214: /* original fbfd, guest PC 0x0c094214 */
if(!s->budget--) { s->failed_pc=0x0c094214u; return 0; }
vf3_matrix_swap(s);
goto P_0c094216;
P_0c094216: /* original fc49, guest PC 0x0c094216 */
if(!s->budget--) { s->failed_pc=0x0c094216u; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094218;
P_0c094218: /* original fd49, guest PC 0x0c094218 */
if(!s->budget--) { s->failed_pc=0x0c094218u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09421a;
P_0c09421a: /* original fe49, guest PC 0x0c09421a */
if(!s->budget--) { s->failed_pc=0x0c09421au; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09421c;
P_0c09421c: /* original fbfd, guest PC 0x0c09421c */
if(!s->budget--) { s->failed_pc=0x0c09421cu; return 0; }
vf3_matrix_swap(s);
goto P_0c09421e;
P_0c09421e: /* original 0009, guest PC 0x0c09421e */
if(!s->budget--) { s->failed_pc=0x0c09421eu; return 0; }
goto P_0c094220;
P_0c094220: /* original 64f3, guest PC 0x0c094220 */
if(!s->budget--) { s->failed_pc=0x0c094220u; return 0; }
r[4]=r[15];
goto P_0c094222;
P_0c094222: /* original 66e3, guest PC 0x0c094222 */
if(!s->budget--) { s->failed_pc=0x0c094222u; return 0; }
r[6]=r[14];
goto P_0c094224;
P_0c094224: /* original 7404, guest PC 0x0c094224 */
if(!s->budget--) { s->failed_pc=0x0c094224u; return 0; }
r[4]+=0x00000004u;
goto P_0c094226;
P_0c094226: /* original 65e3, guest PC 0x0c094226 */
if(!s->budget--) { s->failed_pc=0x0c094226u; return 0; }
r[5]=r[14];
goto P_0c094228;
P_0c094228: /* original 760c, guest PC 0x0c094228 */
if(!s->budget--) { s->failed_pc=0x0c094228u; return 0; }
r[6]+=0x0000000cu;
goto P_0c09422a;
P_0c09422a: /* original f059, guest PC 0x0c09422a */
if(!s->budget--) { s->failed_pc=0x0c09422au; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c09422c;
P_0c09422c: /* original f369, guest PC 0x0c09422c */
if(!s->budget--) { s->failed_pc=0x0c09422cu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c09422e;
P_0c09422e: /* original f159, guest PC 0x0c09422e */
if(!s->budget--) { s->failed_pc=0x0c09422eu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c094230;
P_0c094230: /* original f469, guest PC 0x0c094230 */
if(!s->budget--) { s->failed_pc=0x0c094230u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c094232;
P_0c094232: /* original f031, guest PC 0x0c094232 */
if(!s->budget--) { s->failed_pc=0x0c094232u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c094234;
P_0c094234: /* original f258, guest PC 0x0c094234 */
if(!s->budget--) { s->failed_pc=0x0c094234u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c094236;
P_0c094236: /* original f568, guest PC 0x0c094236 */
if(!s->budget--) { s->failed_pc=0x0c094236u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c094238;
P_0c094238: /* original f141, guest PC 0x0c094238 */
if(!s->budget--) { s->failed_pc=0x0c094238u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c09423a;
P_0c09423a: /* original f251, guest PC 0x0c09423a */
if(!s->budget--) { s->failed_pc=0x0c09423au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c09423c;
P_0c09423c: /* original 7408, guest PC 0x0c09423c */
if(!s->budget--) { s->failed_pc=0x0c09423cu; return 0; }
r[4]+=0x00000008u;
goto P_0c09423e;
P_0c09423e: /* original f42a, guest PC 0x0c09423e */
if(!s->budget--) { s->failed_pc=0x0c09423eu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c094240;
P_0c094240: /* original f41b, guest PC 0x0c094240 */
if(!s->budget--) { s->failed_pc=0x0c094240u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c094242;
P_0c094242: /* original f40b, guest PC 0x0c094242 */
if(!s->budget--) { s->failed_pc=0x0c094242u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c094244;
P_0c094244: /* original 64f3, guest PC 0x0c094244 */
if(!s->budget--) { s->failed_pc=0x0c094244u; return 0; }
r[4]=r[15];
goto P_0c094246;
P_0c094246: /* original 7404, guest PC 0x0c094246 */
if(!s->budget--) { s->failed_pc=0x0c094246u; return 0; }
r[4]+=0x00000004u;
goto P_0c094248;
P_0c094248: /* original f049, guest PC 0x0c094248 */
if(!s->budget--) { s->failed_pc=0x0c094248u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09424a;
P_0c09424a: /* original f149, guest PC 0x0c09424a */
if(!s->budget--) { s->failed_pc=0x0c09424au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09424c;
P_0c09424c: /* original f249, guest PC 0x0c09424c */
if(!s->budget--) { s->failed_pc=0x0c09424cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09424e;
P_0c09424e: /* original f38d, guest PC 0x0c09424e */
if(!s->budget--) { s->failed_pc=0x0c09424eu; return 0; }
fr[3]=0;
goto P_0c094250;
P_0c094250: /* original f0ed, guest PC 0x0c094250 */
if(!s->budget--) { s->failed_pc=0x0c094250u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c094252;
P_0c094252: /* original f37d, guest PC 0x0c094252 */
if(!s->budget--) { s->failed_pc=0x0c094252u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c094254;
P_0c094254: /* original f232, guest PC 0x0c094254 */
if(!s->budget--) { s->failed_pc=0x0c094254u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c094256;
P_0c094256: /* original f132, guest PC 0x0c094256 */
if(!s->budget--) { s->failed_pc=0x0c094256u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c094258;
P_0c094258: /* original f032, guest PC 0x0c094258 */
if(!s->budget--) { s->failed_pc=0x0c094258u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c09425a;
P_0c09425a: /* original f42b, guest PC 0x0c09425a */
if(!s->budget--) { s->failed_pc=0x0c09425au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c09425c;
P_0c09425c: /* original f41b, guest PC 0x0c09425c */
if(!s->budget--) { s->failed_pc=0x0c09425cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c09425e;
P_0c09425e: /* original f40b, guest PC 0x0c09425e */
if(!s->budget--) { s->failed_pc=0x0c09425eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c094260;
P_0c094260: /* original d31f, guest PC 0x0c094260 */
if(!s->budget--) { s->failed_pc=0x0c094260u; return 0; }
r[3]=read(ram,0x0c0942e0u,4);
goto P_0c094262;
P_0c094262: /* original 65f3, guest PC 0x0c094262 */
if(!s->budget--) { s->failed_pc=0x0c094262u; return 0; }
r[5]=r[15];
goto P_0c094264;
P_0c094264: /* original d41d, guest PC 0x0c094264 */
if(!s->budget--) { s->failed_pc=0x0c094264u; return 0; }
r[4]=read(ram,0x0c0942dcu,4);
goto P_0c094266;
P_0c094266: /* original 430b, guest PC 0x0c094266 */
if(!s->budget--) { s->failed_pc=0x0c094266u; return 0; }
target=r[3];
r[16]=0x0c09426au;
r[5]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09426au) { target=s->pc; goto dispatch; }
goto P_0c09426a;
P_0c094268: /* original 7504, guest PC 0x0c094268 */
if(!s->budget--) { s->failed_pc=0x0c094268u; return 0; }
r[5]+=0x00000004u;
goto P_0c09426a;
P_0c09426a: /* original d21e, guest PC 0x0c09426a */
if(!s->budget--) { s->failed_pc=0x0c09426au; return 0; }
r[2]=read(ram,0x0c0942e4u,4);
goto P_0c09426c;
P_0c09426c: /* original 22d8, guest PC 0x0c09426c */
if(!s->budget--) { s->failed_pc=0x0c09426cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c09426e;
P_0c09426e: /* original 8906, guest PC 0x0c09426e */
if(!s->budget--) { s->failed_pc=0x0c09426eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09427e; }
goto P_0c094270;
P_0c094270: /* original d21e, guest PC 0x0c094270 */
if(!s->budget--) { s->failed_pc=0x0c094270u; return 0; }
r[2]=read(ram,0x0c0942ecu,4);
goto P_0c094272;
P_0c094272: /* original d41d, guest PC 0x0c094272 */
if(!s->budget--) { s->failed_pc=0x0c094272u; return 0; }
r[4]=read(ram,0x0c0942e8u,4);
goto P_0c094274;
P_0c094274: /* original 420b, guest PC 0x0c094274 */
if(!s->budget--) { s->failed_pc=0x0c094274u; return 0; }
target=r[2];
r[16]=0x0c094278u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094278u) { target=s->pc; goto dispatch; }
goto P_0c094278;
P_0c094276: /* original 0009, guest PC 0x0c094276 */
if(!s->budget--) { s->failed_pc=0x0c094276u; return 0; }
goto P_0c094278;
P_0c094278: /* original d31d, guest PC 0x0c094278 */
if(!s->budget--) { s->failed_pc=0x0c094278u; return 0; }
r[3]=read(ram,0x0c0942f0u,4);
goto P_0c09427a;
P_0c09427a: /* original 432b, guest PC 0x0c09427a */
if(!s->budget--) { s->failed_pc=0x0c09427au; return 0; }
target=r[3];
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
P_0c09427c: /* original 0009, guest PC 0x0c09427c */
if(!s->budget--) { s->failed_pc=0x0c09427cu; return 0; }
goto P_0c09427e;
P_0c09427e: /* original 9328, guest PC 0x0c09427e */
if(!s->budget--) { s->failed_pc=0x0c09427eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0942d2u,2);
goto P_0c094280;
P_0c094280: /* original 2d38, guest PC 0x0c094280 */
if(!s->budget--) { s->failed_pc=0x0c094280u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[3])==0)!=0);
goto P_0c094282;
P_0c094282: /* original 8b02, guest PC 0x0c094282 */
if(!s->budget--) { s->failed_pc=0x0c094282u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09428a; }
goto P_0c094284;
P_0c094284: /* original d21a, guest PC 0x0c094284 */
if(!s->budget--) { s->failed_pc=0x0c094284u; return 0; }
r[2]=read(ram,0x0c0942f0u,4);
goto P_0c094286;
P_0c094286: /* original 422b, guest PC 0x0c094286 */
if(!s->budget--) { s->failed_pc=0x0c094286u; return 0; }
target=r[2];
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
P_0c094288: /* original 0009, guest PC 0x0c094288 */
if(!s->budget--) { s->failed_pc=0x0c094288u; return 0; }
goto P_0c09428a;
P_0c09428a: /* original d31a, guest PC 0x0c09428a */
if(!s->budget--) { s->failed_pc=0x0c09428au; return 0; }
r[3]=read(ram,0x0c0942f4u,4);
goto P_0c09428c;
P_0c09428c: /* original 430b, guest PC 0x0c09428c */
if(!s->budget--) { s->failed_pc=0x0c09428cu; return 0; }
target=r[3];
r[16]=0x0c094290u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094290u) { target=s->pc; goto dispatch; }
goto P_0c094290;
P_0c09428e: /* original 64a3, guest PC 0x0c09428e */
if(!s->budget--) { s->failed_pc=0x0c09428eu; return 0; }
r[4]=r[10];
goto P_0c094290;
P_0c094290: /* original 7a24, guest PC 0x0c094290 */
if(!s->budget--) { s->failed_pc=0x0c094290u; return 0; }
r[10]+=0x00000024u;
goto P_0c094292;
P_0c094292: /* original 0a83, guest PC 0x0c094292 */
if(!s->budget--) { s->failed_pc=0x0c094292u; return 0; }
goto P_0c094294;
P_0c094294: /* original d216, guest PC 0x0c094294 */
if(!s->budget--) { s->failed_pc=0x0c094294u; return 0; }
r[2]=read(ram,0x0c0942f0u,4);
goto P_0c094296;
P_0c094296: /* original 422b, guest PC 0x0c094296 */
if(!s->budget--) { s->failed_pc=0x0c094296u; return 0; }
target=r[2];
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
P_0c094298: /* original 0009, guest PC 0x0c094298 */
if(!s->budget--) { s->failed_pc=0x0c094298u; return 0; }
goto P_0c09429a;
P_0c09429a: /* original 931a, guest PC 0x0c09429a */
if(!s->budget--) { s->failed_pc=0x0c09429au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0942d2u,2);
goto P_0c09429c;
P_0c09429c: /* original 23d8, guest PC 0x0c09429c */
if(!s->budget--) { s->failed_pc=0x0c09429cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09429e;
P_0c09429e: /* original 8906, guest PC 0x0c09429e */
if(!s->budget--) { s->failed_pc=0x0c09429eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0942ae; }
goto P_0c0942a0;
P_0c0942a0: /* original 60f2, guest PC 0x0c0942a0 */
if(!s->budget--) { s->failed_pc=0x0c0942a0u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0942a2;
P_0c0942a2: /* original 6002, guest PC 0x0c0942a2 */
if(!s->budget--) { s->failed_pc=0x0c0942a2u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c0942a4;
P_0c0942a4: /* original c810, guest PC 0x0c0942a4 */
if(!s->budget--) { s->failed_pc=0x0c0942a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0942a6;
P_0c0942a6: /* original 8902, guest PC 0x0c0942a6 */
if(!s->budget--) { s->failed_pc=0x0c0942a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0942ae; }
goto P_0c0942a8;
P_0c0942a8: /* original d313, guest PC 0x0c0942a8 */
if(!s->budget--) { s->failed_pc=0x0c0942a8u; return 0; }
r[3]=read(ram,0x0c0942f8u,4);
goto P_0c0942aa;
P_0c0942aa: /* original 432b, guest PC 0x0c0942aa */
if(!s->budget--) { s->failed_pc=0x0c0942aau; return 0; }
target=r[3];
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
P_0c0942ac: /* original 0009, guest PC 0x0c0942ac */
if(!s->budget--) { s->failed_pc=0x0c0942acu; return 0; }
goto P_0c0942ae;
P_0c0942ae: /* original 9311, guest PC 0x0c0942ae */
if(!s->budget--) { s->failed_pc=0x0c0942aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0942d4u,2);
goto P_0c0942b0;
P_0c0942b0: /* original e030, guest PC 0x0c0942b0 */
if(!s->budget--) { s->failed_pc=0x0c0942b0u; return 0; }
r[0]=0x00000030u;
goto P_0c0942b2;
P_0c0942b2: /* original 23d8, guest PC 0x0c0942b2 */
if(!s->budget--) { s->failed_pc=0x0c0942b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0942b4;
P_0c0942b4: /* original 8d03, guest PC 0x0c0942b4 */
if(!s->budget--) { s->failed_pc=0x0c0942b4u; return 0; }
cond=r[17]&1u;
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(cond) { goto P_0c0942be; }
goto P_0c0942b8;
P_0c0942b6: /* original 0ced, guest PC 0x0c0942b6 */
if(!s->budget--) { s->failed_pc=0x0c0942b6u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0942b8;
P_0c0942b8: /* original e02e, guest PC 0x0c0942b8 */
if(!s->budget--) { s->failed_pc=0x0c0942b8u; return 0; }
r[0]=0x0000002eu;
goto P_0c0942ba;
P_0c0942ba: /* original 01ed, guest PC 0x0c0942ba */
if(!s->budget--) { s->failed_pc=0x0c0942bau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0942bc;
P_0c0942bc: /* original 3c1c, guest PC 0x0c0942bc */
if(!s->budget--) { s->failed_pc=0x0c0942bcu; return 0; }
r[12]+=r[1];
goto P_0c0942be;
P_0c0942be: /* original 930a, guest PC 0x0c0942be */
if(!s->budget--) { s->failed_pc=0x0c0942beu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0942d6u,2);
goto P_0c0942c0;
P_0c0942c0: /* original 23d8, guest PC 0x0c0942c0 */
if(!s->budget--) { s->failed_pc=0x0c0942c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0942c2;
P_0c0942c2: /* original 8904, guest PC 0x0c0942c2 */
if(!s->budget--) { s->failed_pc=0x0c0942c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0942ce; }
goto P_0c0942c4;
P_0c0942c4: /* original e02e, guest PC 0x0c0942c4 */
if(!s->budget--) { s->failed_pc=0x0c0942c4u; return 0; }
r[0]=0x0000002eu;
goto P_0c0942c6;
P_0c0942c6: /* original 01ed, guest PC 0x0c0942c6 */
if(!s->budget--) { s->failed_pc=0x0c0942c6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0942c8;
P_0c0942c8: /* original 31cc, guest PC 0x0c0942c8 */
if(!s->budget--) { s->failed_pc=0x0c0942c8u; return 0; }
r[1]+=r[12];
goto P_0c0942ca;
P_0c0942ca: /* original 9c05, guest PC 0x0c0942ca */
if(!s->budget--) { s->failed_pc=0x0c0942cau; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0942d8u,2);
goto P_0c0942cc;
P_0c0942cc: /* original 3c1c, guest PC 0x0c0942cc */
if(!s->budget--) { s->failed_pc=0x0c0942ccu; return 0; }
r[12]+=r[1];
goto P_0c0942ce;
P_0c0942ce: /* original a015, guest PC 0x0c0942ce */
if(!s->budget--) { s->failed_pc=0x0c0942ceu; return 0; }
goto P_0c0942fc;
P_0c0942d0: /* original 0009, guest PC 0x0c0942d0 */
if(!s->budget--) { s->failed_pc=0x0c0942d0u; return 0; }
return vf3_matrix_family(0x0c0942d2u,s,ram);
P_0c0942fc: /* original fbfd, guest PC 0x0c0942fc */
if(!s->budget--) { s->failed_pc=0x0c0942fcu; return 0; }
vf3_matrix_swap(s);
goto P_0c0942fe;
P_0c0942fe: /* original f09d, guest PC 0x0c0942fe */
if(!s->budget--) { s->failed_pc=0x0c0942feu; return 0; }
fr[0]=0x3f800000u;
goto P_0c094300;
P_0c094300: /* original f18d, guest PC 0x0c094300 */
if(!s->budget--) { s->failed_pc=0x0c094300u; return 0; }
fr[1]=0;
goto P_0c094302;
P_0c094302: /* original f28d, guest PC 0x0c094302 */
if(!s->budget--) { s->failed_pc=0x0c094302u; return 0; }
fr[2]=0;
goto P_0c094304;
P_0c094304: /* original f48d, guest PC 0x0c094304 */
if(!s->budget--) { s->failed_pc=0x0c094304u; return 0; }
fr[4]=0;
goto P_0c094306;
P_0c094306: /* original f59d, guest PC 0x0c094306 */
if(!s->budget--) { s->failed_pc=0x0c094306u; return 0; }
fr[5]=0x3f800000u;
goto P_0c094308;
P_0c094308: /* original f68d, guest PC 0x0c094308 */
if(!s->budget--) { s->failed_pc=0x0c094308u; return 0; }
fr[6]=0;
goto P_0c09430a;
P_0c09430a: /* original f88d, guest PC 0x0c09430a */
if(!s->budget--) { s->failed_pc=0x0c09430au; return 0; }
fr[8]=0;
goto P_0c09430c;
P_0c09430c: /* original f98d, guest PC 0x0c09430c */
if(!s->budget--) { s->failed_pc=0x0c09430cu; return 0; }
fr[9]=0;
goto P_0c09430e;
P_0c09430e: /* original fa9d, guest PC 0x0c09430e */
if(!s->budget--) { s->failed_pc=0x0c09430eu; return 0; }
fr[10]=0x3f800000u;
goto P_0c094310;
P_0c094310: /* original fbfd, guest PC 0x0c094310 */
if(!s->budget--) { s->failed_pc=0x0c094310u; return 0; }
vf3_matrix_swap(s);
goto P_0c094312;
P_0c094312: /* original 0009, guest PC 0x0c094312 */
if(!s->budget--) { s->failed_pc=0x0c094312u; return 0; }
goto P_0c094314;
P_0c094314: /* original 64e3, guest PC 0x0c094314 */
if(!s->budget--) { s->failed_pc=0x0c094314u; return 0; }
r[4]=r[14];
goto P_0c094316;
P_0c094316: /* original 740c, guest PC 0x0c094316 */
if(!s->budget--) { s->failed_pc=0x0c094316u; return 0; }
r[4]+=0x0000000cu;
goto P_0c094318;
P_0c094318: /* original fbfd, guest PC 0x0c094318 */
if(!s->budget--) { s->failed_pc=0x0c094318u; return 0; }
vf3_matrix_swap(s);
goto P_0c09431a;
P_0c09431a: /* original fc49, guest PC 0x0c09431a */
if(!s->budget--) { s->failed_pc=0x0c09431au; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09431c;
P_0c09431c: /* original fd49, guest PC 0x0c09431c */
if(!s->budget--) { s->failed_pc=0x0c09431cu; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09431e;
P_0c09431e: /* original fe49, guest PC 0x0c09431e */
if(!s->budget--) { s->failed_pc=0x0c09431eu; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094320;
P_0c094320: /* original fbfd, guest PC 0x0c094320 */
if(!s->budget--) { s->failed_pc=0x0c094320u; return 0; }
vf3_matrix_swap(s);
goto P_0c094322;
P_0c094322: /* original 0009, guest PC 0x0c094322 */
if(!s->budget--) { s->failed_pc=0x0c094322u; return 0; }
goto P_0c094324;
P_0c094324: /* original d326, guest PC 0x0c094324 */
if(!s->budget--) { s->failed_pc=0x0c094324u; return 0; }
r[3]=read(ram,0x0c0943c0u,4);
goto P_0c094326;
P_0c094326: /* original e030, guest PC 0x0c094326 */
if(!s->budget--) { s->failed_pc=0x0c094326u; return 0; }
r[0]=0x00000030u;
goto P_0c094328;
P_0c094328: /* original 430b, guest PC 0x0c094328 */
if(!s->budget--) { s->failed_pc=0x0c094328u; return 0; }
target=r[3];
r[16]=0x0c09432cu;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09432cu) { target=s->pc; goto dispatch; }
goto P_0c09432c;
P_0c09432a: /* original 04ed, guest PC 0x0c09432a */
if(!s->budget--) { s->failed_pc=0x0c09432au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09432c;
P_0c09432c: /* original d325, guest PC 0x0c09432c */
if(!s->budget--) { s->failed_pc=0x0c09432cu; return 0; }
r[3]=read(ram,0x0c0943c4u,4);
goto P_0c09432e;
P_0c09432e: /* original e032, guest PC 0x0c09432e */
if(!s->budget--) { s->failed_pc=0x0c09432eu; return 0; }
r[0]=0x00000032u;
goto P_0c094330;
P_0c094330: /* original 430b, guest PC 0x0c094330 */
if(!s->budget--) { s->failed_pc=0x0c094330u; return 0; }
target=r[3];
r[16]=0x0c094334u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094334u) { target=s->pc; goto dispatch; }
goto P_0c094334;
P_0c094332: /* original 04ed, guest PC 0x0c094332 */
if(!s->budget--) { s->failed_pc=0x0c094332u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c094334;
P_0c094334: /* original d224, guest PC 0x0c094334 */
if(!s->budget--) { s->failed_pc=0x0c094334u; return 0; }
r[2]=read(ram,0x0c0943c8u,4);
goto P_0c094336;
P_0c094336: /* original 2d28, guest PC 0x0c094336 */
if(!s->budget--) { s->failed_pc=0x0c094336u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[2])==0)!=0);
goto P_0c094338;
P_0c094338: /* original 8903, guest PC 0x0c094338 */
if(!s->budget--) { s->failed_pc=0x0c094338u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094342; }
goto P_0c09433a;
P_0c09433a: /* original d125, guest PC 0x0c09433a */
if(!s->budget--) { s->failed_pc=0x0c09433au; return 0; }
r[1]=read(ram,0x0c0943d0u,4);
goto P_0c09433c;
P_0c09433c: /* original d423, guest PC 0x0c09433c */
if(!s->budget--) { s->failed_pc=0x0c09433cu; return 0; }
r[4]=read(ram,0x0c0943ccu,4);
goto P_0c09433e;
P_0c09433e: /* original 410b, guest PC 0x0c09433e */
if(!s->budget--) { s->failed_pc=0x0c09433eu; return 0; }
target=r[1];
r[16]=0x0c094342u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094342u) { target=s->pc; goto dispatch; }
goto P_0c094342;
P_0c094340: /* original 0009, guest PC 0x0c094340 */
if(!s->budget--) { s->failed_pc=0x0c094340u; return 0; }
goto P_0c094342;
P_0c094342: /* original d324, guest PC 0x0c094342 */
if(!s->budget--) { s->failed_pc=0x0c094342u; return 0; }
r[3]=read(ram,0x0c0943d4u,4);
goto P_0c094344;
P_0c094344: /* original 430b, guest PC 0x0c094344 */
if(!s->budget--) { s->failed_pc=0x0c094344u; return 0; }
target=r[3];
r[16]=0x0c094348u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094348u) { target=s->pc; goto dispatch; }
goto P_0c094348;
P_0c094346: /* original 64c3, guest PC 0x0c094346 */
if(!s->budget--) { s->failed_pc=0x0c094346u; return 0; }
r[4]=r[12];
goto P_0c094348;
P_0c094348: /* original e02c, guest PC 0x0c094348 */
if(!s->budget--) { s->failed_pc=0x0c094348u; return 0; }
r[0]=0x0000002cu;
goto P_0c09434a;
P_0c09434a: /* original d323, guest PC 0x0c09434a */
if(!s->budget--) { s->failed_pc=0x0c09434au; return 0; }
r[3]=read(ram,0x0c0943d8u,4);
goto P_0c09434c;
P_0c09434c: /* original 04ed, guest PC 0x0c09434c */
if(!s->budget--) { s->failed_pc=0x0c09434cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09434e;
P_0c09434e: /* original 430b, guest PC 0x0c09434e */
if(!s->budget--) { s->failed_pc=0x0c09434eu; return 0; }
target=r[3];
r[16]=0x0c094352u;
r[4]=r[4]&65535u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094352u) { target=s->pc; goto dispatch; }
goto P_0c094352;
P_0c094350: /* original 644d, guest PC 0x0c094350 */
if(!s->budget--) { s->failed_pc=0x0c094350u; return 0; }
r[4]=r[4]&65535u;
goto P_0c094352;
P_0c094352: /* original d222, guest PC 0x0c094352 */
if(!s->budget--) { s->failed_pc=0x0c094352u; return 0; }
r[2]=read(ram,0x0c0943dcu,4);
goto P_0c094354;
P_0c094354: /* original 422b, guest PC 0x0c094354 */
if(!s->budget--) { s->failed_pc=0x0c094354u; return 0; }
target=r[2];
r[14]=r[11];
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
P_0c094356: /* original 6eb3, guest PC 0x0c094356 */
if(!s->budget--) { s->failed_pc=0x0c094356u; return 0; }
r[14]=r[11];
goto P_0c094358;
P_0c094358: /* original 7f10, guest PC 0x0c094358 */
if(!s->budget--) { s->failed_pc=0x0c094358u; return 0; }
r[15]+=0x00000010u;
goto P_0c09435a;
P_0c09435a: /* original 4f26, guest PC 0x0c09435a */
if(!s->budget--) { s->failed_pc=0x0c09435au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09435c;
P_0c09435c: /* original 6af6, guest PC 0x0c09435c */
if(!s->budget--) { s->failed_pc=0x0c09435cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09435e;
P_0c09435e: /* original 6bf6, guest PC 0x0c09435e */
if(!s->budget--) { s->failed_pc=0x0c09435eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c094360;
P_0c094360: /* original 6cf6, guest PC 0x0c094360 */
if(!s->budget--) { s->failed_pc=0x0c094360u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c094362;
P_0c094362: /* original 6df6, guest PC 0x0c094362 */
if(!s->budget--) { s->failed_pc=0x0c094362u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c094364;
P_0c094364: /* original 000b, guest PC 0x0c094364 */
if(!s->budget--) { s->failed_pc=0x0c094364u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c094366: /* original 6ef6, guest PC 0x0c094366 */
if(!s->budget--) { s->failed_pc=0x0c094366u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c094368;
P_0c094368: /* original 2fe6, guest PC 0x0c094368 */
if(!s->budget--) { s->failed_pc=0x0c094368u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c09436a;
P_0c09436a: /* original 2fd6, guest PC 0x0c09436a */
if(!s->budget--) { s->failed_pc=0x0c09436au; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c09436c;
P_0c09436c: /* original 2fc6, guest PC 0x0c09436c */
if(!s->budget--) { s->failed_pc=0x0c09436cu; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c09436e;
P_0c09436e: /* original 2fb6, guest PC 0x0c09436e */
if(!s->budget--) { s->failed_pc=0x0c09436eu; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c094370;
P_0c094370: /* original fffb, guest PC 0x0c094370 */
if(!s->budget--) { s->failed_pc=0x0c094370u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c094372;
P_0c094372: /* original 4f22, guest PC 0x0c094372 */
if(!s->budget--) { s->failed_pc=0x0c094372u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c094374;
P_0c094374: /* original 7fd8, guest PC 0x0c094374 */
if(!s->budget--) { s->failed_pc=0x0c094374u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c094376;
P_0c094376: /* original 2f42, guest PC 0x0c094376 */
if(!s->budget--) { s->failed_pc=0x0c094376u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c094378;
P_0c094378: /* original 1f51, guest PC 0x0c094378 */
if(!s->budget--) { s->failed_pc=0x0c094378u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c09437a;
P_0c09437a: /* original d41a, guest PC 0x0c09437a */
if(!s->budget--) { s->failed_pc=0x0c09437au; return 0; }
r[4]=read(ram,0x0c0943e4u,4);
goto P_0c09437c;
P_0c09437c: /* original 901e, guest PC 0x0c09437c */
if(!s->budget--) { s->failed_pc=0x0c09437cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0943bcu,2);
goto P_0c09437e;
P_0c09437e: /* original dd18, guest PC 0x0c09437e */
if(!s->budget--) { s->failed_pc=0x0c09437eu; return 0; }
r[13]=read(ram,0x0c0943e0u,4);
goto P_0c094380;
P_0c094380: /* original 034e, guest PC 0x0c094380 */
if(!s->budget--) { s->failed_pc=0x0c094380u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c094382;
P_0c094382: /* original 2338, guest PC 0x0c094382 */
if(!s->budget--) { s->failed_pc=0x0c094382u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c094384;
P_0c094384: /* original 8900, guest PC 0x0c094384 */
if(!s->budget--) { s->failed_pc=0x0c094384u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094388; }
goto P_0c094386;
P_0c094386: /* original dd18, guest PC 0x0c094386 */
if(!s->budget--) { s->failed_pc=0x0c094386u; return 0; }
r[13]=read(ram,0x0c0943e8u,4);
goto P_0c094388;
P_0c094388: /* original c718, guest PC 0x0c094388 */
if(!s->budget--) { s->failed_pc=0x0c094388u; return 0; }
r[0]=0x0c0943ecu;
goto P_0c09438a;
P_0c09438a: /* original ff08, guest PC 0x0c09438a */
if(!s->budget--) { s->failed_pc=0x0c09438au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c09438c;
P_0c09438c: /* original 6cd1, guest PC 0x0c09438c */
if(!s->budget--) { s->failed_pc=0x0c09438cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[12]=tmp;
goto P_0c09438e;
P_0c09438e: /* original 2cc8, guest PC 0x0c09438e */
if(!s->budget--) { s->failed_pc=0x0c09438eu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c094390;
P_0c094390: /* original 8b02, guest PC 0x0c094390 */
if(!s->budget--) { s->failed_pc=0x0c094390u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094398; }
goto P_0c094392;
P_0c094392: /* original d317, guest PC 0x0c094392 */
if(!s->budget--) { s->failed_pc=0x0c094392u; return 0; }
r[3]=read(ram,0x0c0943f0u,4);
goto P_0c094394;
P_0c094394: /* original 432b, guest PC 0x0c094394 */
if(!s->budget--) { s->failed_pc=0x0c094394u; return 0; }
target=r[3];
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
P_0c094396: /* original 0009, guest PC 0x0c094396 */
if(!s->budget--) { s->failed_pc=0x0c094396u; return 0; }
goto P_0c094398;
P_0c094398: /* original 85d1, guest PC 0x0c094398 */
if(!s->budget--) { s->failed_pc=0x0c094398u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+2,2);
goto P_0c09439a;
P_0c09439a: /* original 5ef1, guest PC 0x0c09439a */
if(!s->budget--) { s->failed_pc=0x0c09439au; return 0; }
r[14]=read(ram,r[15]+4,4);
goto P_0c09439c;
P_0c09439c: /* original 6403, guest PC 0x0c09439c */
if(!s->budget--) { s->failed_pc=0x0c09439cu; return 0; }
r[4]=r[0];
goto P_0c09439e;
P_0c09439e: /* original 3e4c, guest PC 0x0c09439e */
if(!s->budget--) { s->failed_pc=0x0c09439eu; return 0; }
r[14]+=r[4];
goto P_0c0943a0;
P_0c0943a0: /* original 0e83, guest PC 0x0c0943a0 */
if(!s->budget--) { s->failed_pc=0x0c0943a0u; return 0; }
goto P_0c0943a2;
P_0c0943a2: /* original 53d1, guest PC 0x0c0943a2 */
if(!s->budget--) { s->failed_pc=0x0c0943a2u; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0943a4;
P_0c0943a4: /* original 1f32, guest PC 0x0c0943a4 */
if(!s->budget--) { s->failed_pc=0x0c0943a4u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0943a6;
P_0c0943a6: /* original 52d2, guest PC 0x0c0943a6 */
if(!s->budget--) { s->failed_pc=0x0c0943a6u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0943a8;
P_0c0943a8: /* original 1f23, guest PC 0x0c0943a8 */
if(!s->budget--) { s->failed_pc=0x0c0943a8u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0943aa;
P_0c0943aa: /* original d312, guest PC 0x0c0943aa */
if(!s->budget--) { s->failed_pc=0x0c0943aau; return 0; }
r[3]=read(ram,0x0c0943f4u,4);
goto P_0c0943ac;
P_0c0943ac: /* original 430b, guest PC 0x0c0943ac */
if(!s->budget--) { s->failed_pc=0x0c0943acu; return 0; }
target=r[3];
r[16]=0x0c0943b0u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0943b0u) { target=s->pc; goto dispatch; }
goto P_0c0943b0;
P_0c0943ae: /* original 64f2, guest PC 0x0c0943ae */
if(!s->budget--) { s->failed_pc=0x0c0943aeu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0943b0;
P_0c0943b0: /* original 64d3, guest PC 0x0c0943b0 */
if(!s->budget--) { s->failed_pc=0x0c0943b0u; return 0; }
r[4]=r[13];
goto P_0c0943b2;
P_0c0943b2: /* original 65f3, guest PC 0x0c0943b2 */
if(!s->budget--) { s->failed_pc=0x0c0943b2u; return 0; }
r[5]=r[15];
goto P_0c0943b4;
P_0c0943b4: /* original 740c, guest PC 0x0c0943b4 */
if(!s->budget--) { s->failed_pc=0x0c0943b4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0943b6;
P_0c0943b6: /* original 751c, guest PC 0x0c0943b6 */
if(!s->budget--) { s->failed_pc=0x0c0943b6u; return 0; }
r[5]+=0x0000001cu;
goto P_0c0943b8;
P_0c0943b8: /* original a01e, guest PC 0x0c0943b8 */
if(!s->budget--) { s->failed_pc=0x0c0943b8u; return 0; }
goto P_0c0943f8;
P_0c0943ba: /* original 0009, guest PC 0x0c0943ba */
if(!s->budget--) { s->failed_pc=0x0c0943bau; return 0; }
return vf3_matrix_family(0x0c0943bcu,s,ram);
P_0c0943f8: /* original f449, guest PC 0x0c0943f8 */
if(!s->budget--) { s->failed_pc=0x0c0943f8u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0943fa;
P_0c0943fa: /* original f549, guest PC 0x0c0943fa */
if(!s->budget--) { s->failed_pc=0x0c0943fau; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0943fc;
P_0c0943fc: /* original f648, guest PC 0x0c0943fc */
if(!s->budget--) { s->failed_pc=0x0c0943fcu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0943fe;
P_0c0943fe: /* original f79d, guest PC 0x0c0943fe */
if(!s->budget--) { s->failed_pc=0x0c0943feu; return 0; }
fr[7]=0x3f800000u;
goto P_0c094400;
P_0c094400: /* original f5fd, guest PC 0x0c094400 */
if(!s->budget--) { s->failed_pc=0x0c094400u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c094402;
P_0c094402: /* original 750c, guest PC 0x0c094402 */
if(!s->budget--) { s->failed_pc=0x0c094402u; return 0; }
r[5]+=0x0000000cu;
goto P_0c094404;
P_0c094404: /* original f56b, guest PC 0x0c094404 */
if(!s->budget--) { s->failed_pc=0x0c094404u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c094406;
P_0c094406: /* original f55b, guest PC 0x0c094406 */
if(!s->budget--) { s->failed_pc=0x0c094406u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c094408;
P_0c094408: /* original f54b, guest PC 0x0c094408 */
if(!s->budget--) { s->failed_pc=0x0c094408u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c09440a;
P_0c09440a: /* original 0009, guest PC 0x0c09440a */
if(!s->budget--) { s->failed_pc=0x0c09440au; return 0; }
goto P_0c09440c;
P_0c09440c: /* original 7d18, guest PC 0x0c09440c */
if(!s->budget--) { s->failed_pc=0x0c09440cu; return 0; }
r[13]+=0x00000018u;
goto P_0c09440e;
P_0c09440e: /* original d303, guest PC 0x0c09440e */
if(!s->budget--) { s->failed_pc=0x0c09440eu; return 0; }
r[3]=read(ram,0x0c09441cu,4);
goto P_0c094410;
P_0c094410: /* original 430b, guest PC 0x0c094410 */
if(!s->budget--) { s->failed_pc=0x0c094410u; return 0; }
target=r[3];
r[16]=0x0c094414u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094414u) { target=s->pc; goto dispatch; }
goto P_0c094414;
P_0c094412: /* original 64e3, guest PC 0x0c094412 */
if(!s->budget--) { s->failed_pc=0x0c094412u; return 0; }
r[4]=r[14];
goto P_0c094414;
P_0c094414: /* original 64f3, guest PC 0x0c094414 */
if(!s->budget--) { s->failed_pc=0x0c094414u; return 0; }
r[4]=r[15];
goto P_0c094416;
P_0c094416: /* original 741c, guest PC 0x0c094416 */
if(!s->budget--) { s->failed_pc=0x0c094416u; return 0; }
r[4]+=0x0000001cu;
goto P_0c094418;
P_0c094418: /* original a002, guest PC 0x0c094418 */
if(!s->budget--) { s->failed_pc=0x0c094418u; return 0; }
goto P_0c094420;
P_0c09441a: /* original 0009, guest PC 0x0c09441a */
if(!s->budget--) { s->failed_pc=0x0c09441au; return 0; }
return vf3_matrix_family(0x0c09441cu,s,ram);
P_0c094420: /* original fbfd, guest PC 0x0c094420 */
if(!s->budget--) { s->failed_pc=0x0c094420u; return 0; }
vf3_matrix_swap(s);
goto P_0c094422;
P_0c094422: /* original fc49, guest PC 0x0c094422 */
if(!s->budget--) { s->failed_pc=0x0c094422u; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094424;
P_0c094424: /* original fd49, guest PC 0x0c094424 */
if(!s->budget--) { s->failed_pc=0x0c094424u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094426;
P_0c094426: /* original fe49, guest PC 0x0c094426 */
if(!s->budget--) { s->failed_pc=0x0c094426u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094428;
P_0c094428: /* original fbfd, guest PC 0x0c094428 */
if(!s->budget--) { s->failed_pc=0x0c094428u; return 0; }
vf3_matrix_swap(s);
goto P_0c09442a;
P_0c09442a: /* original 0009, guest PC 0x0c09442a */
if(!s->budget--) { s->failed_pc=0x0c09442au; return 0; }
goto P_0c09442c;
P_0c09442c: /* original 4c10, guest PC 0x0c09442c */
if(!s->budget--) { s->failed_pc=0x0c09442cu; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c09442e;
P_0c09442e: /* original 8d15, guest PC 0x0c09442e */
if(!s->budget--) { s->failed_pc=0x0c09442eu; return 0; }
cond=r[17]&1u;
r[11]=read(ram,r[15]+12,4);
if(cond) { goto P_0c09445c; }
goto P_0c094432;
P_0c094430: /* original 5bf3, guest PC 0x0c094430 */
if(!s->budget--) { s->failed_pc=0x0c094430u; return 0; }
r[11]=read(ram,r[15]+12,4);
goto P_0c094432;
P_0c094432: /* original e01c, guest PC 0x0c094432 */
if(!s->budget--) { s->failed_pc=0x0c094432u; return 0; }
r[0]=0x0000001cu;
goto P_0c094434;
P_0c094434: /* original f2e9, guest PC 0x0c094434 */
if(!s->budget--) { s->failed_pc=0x0c094434u; return 0; }
vf3_matrix_load(s,ram,2,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c094436;
P_0c094436: /* original f3f6, guest PC 0x0c094436 */
if(!s->budget--) { s->failed_pc=0x0c094436u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c094438;
P_0c094438: /* original e01c, guest PC 0x0c094438 */
if(!s->budget--) { s->failed_pc=0x0c094438u; return 0; }
r[0]=0x0000001cu;
goto P_0c09443a;
P_0c09443a: /* original f0fc, guest PC 0x0c09443a */
if(!s->budget--) { s->failed_pc=0x0c09443au; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c09443c;
P_0c09443c: /* original f32e, guest PC 0x0c09443c */
if(!s->budget--) { s->failed_pc=0x0c09443cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09443e;
P_0c09443e: /* original 5bf2, guest PC 0x0c09443e */
if(!s->budget--) { s->failed_pc=0x0c09443eu; return 0; }
r[11]=read(ram,r[15]+8,4);
goto P_0c094440;
P_0c094440: /* original ff37, guest PC 0x0c094440 */
if(!s->budget--) { s->failed_pc=0x0c094440u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c094442;
P_0c094442: /* original e020, guest PC 0x0c094442 */
if(!s->budget--) { s->failed_pc=0x0c094442u; return 0; }
r[0]=0x00000020u;
goto P_0c094444;
P_0c094444: /* original f2e9, guest PC 0x0c094444 */
if(!s->budget--) { s->failed_pc=0x0c094444u; return 0; }
vf3_matrix_load(s,ram,2,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c094446;
P_0c094446: /* original f3f6, guest PC 0x0c094446 */
if(!s->budget--) { s->failed_pc=0x0c094446u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c094448;
P_0c094448: /* original e020, guest PC 0x0c094448 */
if(!s->budget--) { s->failed_pc=0x0c094448u; return 0; }
r[0]=0x00000020u;
goto P_0c09444a;
P_0c09444a: /* original f32e, guest PC 0x0c09444a */
if(!s->budget--) { s->failed_pc=0x0c09444au; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09444c;
P_0c09444c: /* original ff37, guest PC 0x0c09444c */
if(!s->budget--) { s->failed_pc=0x0c09444cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09444e;
P_0c09444e: /* original e024, guest PC 0x0c09444e */
if(!s->budget--) { s->failed_pc=0x0c09444eu; return 0; }
r[0]=0x00000024u;
goto P_0c094450;
P_0c094450: /* original f2e9, guest PC 0x0c094450 */
if(!s->budget--) { s->failed_pc=0x0c094450u; return 0; }
vf3_matrix_load(s,ram,2,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c094452;
P_0c094452: /* original f3f6, guest PC 0x0c094452 */
if(!s->budget--) { s->failed_pc=0x0c094452u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c094454;
P_0c094454: /* original e024, guest PC 0x0c094454 */
if(!s->budget--) { s->failed_pc=0x0c094454u; return 0; }
r[0]=0x00000024u;
goto P_0c094456;
P_0c094456: /* original 7e18, guest PC 0x0c094456 */
if(!s->budget--) { s->failed_pc=0x0c094456u; return 0; }
r[14]+=0x00000018u;
goto P_0c094458;
P_0c094458: /* original f32e, guest PC 0x0c094458 */
if(!s->budget--) { s->failed_pc=0x0c094458u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09445a;
P_0c09445a: /* original ff37, guest PC 0x0c09445a */
if(!s->budget--) { s->failed_pc=0x0c09445au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09445c;
P_0c09445c: /* original d303, guest PC 0x0c09445c */
if(!s->budget--) { s->failed_pc=0x0c09445cu; return 0; }
r[3]=read(ram,0x0c09446cu,4);
goto P_0c09445e;
P_0c09445e: /* original 430b, guest PC 0x0c09445e */
if(!s->budget--) { s->failed_pc=0x0c09445eu; return 0; }
target=r[3];
r[16]=0x0c094462u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094462u) { target=s->pc; goto dispatch; }
goto P_0c094462;
P_0c094460: /* original 64b3, guest PC 0x0c094460 */
if(!s->budget--) { s->failed_pc=0x0c094460u; return 0; }
r[4]=r[11];
goto P_0c094462;
P_0c094462: /* original 64f3, guest PC 0x0c094462 */
if(!s->budget--) { s->failed_pc=0x0c094462u; return 0; }
r[4]=r[15];
goto P_0c094464;
P_0c094464: /* original 741c, guest PC 0x0c094464 */
if(!s->budget--) { s->failed_pc=0x0c094464u; return 0; }
r[4]+=0x0000001cu;
goto P_0c094466;
P_0c094466: /* original a003, guest PC 0x0c094466 */
if(!s->budget--) { s->failed_pc=0x0c094466u; return 0; }
goto P_0c094470;
P_0c094468: /* original 0009, guest PC 0x0c094468 */
if(!s->budget--) { s->failed_pc=0x0c094468u; return 0; }
return vf3_matrix_family(0x0c09446au,s,ram);
P_0c094470: /* original fbfd, guest PC 0x0c094470 */
if(!s->budget--) { s->failed_pc=0x0c094470u; return 0; }
vf3_matrix_swap(s);
goto P_0c094472;
P_0c094472: /* original fc49, guest PC 0x0c094472 */
if(!s->budget--) { s->failed_pc=0x0c094472u; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094474;
P_0c094474: /* original fd49, guest PC 0x0c094474 */
if(!s->budget--) { s->failed_pc=0x0c094474u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094476;
P_0c094476: /* original fe49, guest PC 0x0c094476 */
if(!s->budget--) { s->failed_pc=0x0c094476u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094478;
P_0c094478: /* original fbfd, guest PC 0x0c094478 */
if(!s->budget--) { s->failed_pc=0x0c094478u; return 0; }
vf3_matrix_swap(s);
goto P_0c09447a;
P_0c09447a: /* original 0009, guest PC 0x0c09447a */
if(!s->budget--) { s->failed_pc=0x0c09447au; return 0; }
goto P_0c09447c;
P_0c09447c: /* original 2cc8, guest PC 0x0c09447c */
if(!s->budget--) { s->failed_pc=0x0c09447cu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c09447e;
P_0c09447e: /* original 8902, guest PC 0x0c09447e */
if(!s->budget--) { s->failed_pc=0x0c09447eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094486; }
goto P_0c094480;
P_0c094480: /* original d32a, guest PC 0x0c094480 */
if(!s->budget--) { s->failed_pc=0x0c094480u; return 0; }
r[3]=read(ram,0x0c09452cu,4);
goto P_0c094482;
P_0c094482: /* original 432b, guest PC 0x0c094482 */
if(!s->budget--) { s->failed_pc=0x0c094482u; return 0; }
target=r[3];
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
P_0c094484: /* original 0009, guest PC 0x0c094484 */
if(!s->budget--) { s->failed_pc=0x0c094484u; return 0; }
goto P_0c094486;
P_0c094486: /* original d32a, guest PC 0x0c094486 */
if(!s->budget--) { s->failed_pc=0x0c094486u; return 0; }
r[3]=read(ram,0x0c094530u,4);
goto P_0c094488;
P_0c094488: /* original 432b, guest PC 0x0c094488 */
if(!s->budget--) { s->failed_pc=0x0c094488u; return 0; }
target=r[3];
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
P_0c09448a: /* original 0009, guest PC 0x0c09448a */
if(!s->budget--) { s->failed_pc=0x0c09448au; return 0; }
return vf3_matrix_family(0x0c09448cu,s,ram);
P_0c09449c: /* original 2fe6, guest PC 0x0c09449c */
if(!s->budget--) { s->failed_pc=0x0c09449cu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c09449e;
P_0c09449e: /* original 6e53, guest PC 0x0c09449e */
if(!s->budget--) { s->failed_pc=0x0c09449eu; return 0; }
r[14]=r[5];
goto P_0c0944a0;
P_0c0944a0: /* original e034, guest PC 0x0c0944a0 */
if(!s->budget--) { s->failed_pc=0x0c0944a0u; return 0; }
r[0]=0x00000034u;
goto P_0c0944a2;
P_0c0944a2: /* original 00ed, guest PC 0x0c0944a2 */
if(!s->budget--) { s->failed_pc=0x0c0944a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0944a4;
P_0c0944a4: /* original 4f22, guest PC 0x0c0944a4 */
if(!s->budget--) { s->failed_pc=0x0c0944a4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0944a6;
P_0c0944a6: /* original 600d, guest PC 0x0c0944a6 */
if(!s->budget--) { s->failed_pc=0x0c0944a6u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0944a8;
P_0c0944a8: /* original c880, guest PC 0x0c0944a8 */
if(!s->budget--) { s->failed_pc=0x0c0944a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0944aa;
P_0c0944aa: /* original 7fc0, guest PC 0x0c0944aa */
if(!s->budget--) { s->failed_pc=0x0c0944aau; return 0; }
r[15]+=0xffffffc0u;
goto P_0c0944ac;
P_0c0944ac: /* original 8b1d, guest PC 0x0c0944ac */
if(!s->budget--) { s->failed_pc=0x0c0944acu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0944ea; }
goto P_0c0944ae;
P_0c0944ae: /* original e054, guest PC 0x0c0944ae */
if(!s->budget--) { s->failed_pc=0x0c0944aeu; return 0; }
r[0]=0x00000054u;
goto P_0c0944b0;
P_0c0944b0: /* original d320, guest PC 0x0c0944b0 */
if(!s->budget--) { s->failed_pc=0x0c0944b0u; return 0; }
r[3]=read(ram,0x0c094534u,4);
goto P_0c0944b2;
P_0c0944b2: /* original 02ed, guest PC 0x0c0944b2 */
if(!s->budget--) { s->failed_pc=0x0c0944b2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0944b4;
P_0c0944b4: /* original 622d, guest PC 0x0c0944b4 */
if(!s->budget--) { s->failed_pc=0x0c0944b4u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0944b6;
P_0c0944b6: /* original 430b, guest PC 0x0c0944b6 */
if(!s->budget--) { s->failed_pc=0x0c0944b6u; return 0; }
target=r[3];
r[16]=0x0c0944bau;
r[4]+=r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0944bau) { target=s->pc; goto dispatch; }
goto P_0c0944ba;
P_0c0944b8: /* original 342c, guest PC 0x0c0944b8 */
if(!s->budget--) { s->failed_pc=0x0c0944b8u; return 0; }
r[4]+=r[2];
goto P_0c0944ba;
P_0c0944ba: /* original d21f, guest PC 0x0c0944ba */
if(!s->budget--) { s->failed_pc=0x0c0944bau; return 0; }
r[2]=read(ram,0x0c094538u,4);
goto P_0c0944bc;
P_0c0944bc: /* original 64e3, guest PC 0x0c0944bc */
if(!s->budget--) { s->failed_pc=0x0c0944bcu; return 0; }
r[4]=r[14];
goto P_0c0944be;
P_0c0944be: /* original 420b, guest PC 0x0c0944be */
if(!s->budget--) { s->failed_pc=0x0c0944beu; return 0; }
target=r[2];
r[16]=0x0c0944c2u;
r[4]+=0x00000038u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0944c2u) { target=s->pc; goto dispatch; }
goto P_0c0944c2;
P_0c0944c0: /* original 7438, guest PC 0x0c0944c0 */
if(!s->budget--) { s->failed_pc=0x0c0944c0u; return 0; }
r[4]+=0x00000038u;
goto P_0c0944c2;
P_0c0944c2: /* original d31e, guest PC 0x0c0944c2 */
if(!s->budget--) { s->failed_pc=0x0c0944c2u; return 0; }
r[3]=read(ram,0x0c09453cu,4);
goto P_0c0944c4;
P_0c0944c4: /* original e032, guest PC 0x0c0944c4 */
if(!s->budget--) { s->failed_pc=0x0c0944c4u; return 0; }
r[0]=0x00000032u;
goto P_0c0944c6;
P_0c0944c6: /* original 430b, guest PC 0x0c0944c6 */
if(!s->budget--) { s->failed_pc=0x0c0944c6u; return 0; }
target=r[3];
r[16]=0x0c0944cau;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0944cau) { target=s->pc; goto dispatch; }
goto P_0c0944ca;
P_0c0944c8: /* original 04ed, guest PC 0x0c0944c8 */
if(!s->budget--) { s->failed_pc=0x0c0944c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0944ca;
P_0c0944ca: /* original d31d, guest PC 0x0c0944ca */
if(!s->budget--) { s->failed_pc=0x0c0944cau; return 0; }
r[3]=read(ram,0x0c094540u,4);
goto P_0c0944cc;
P_0c0944cc: /* original e030, guest PC 0x0c0944cc */
if(!s->budget--) { s->failed_pc=0x0c0944ccu; return 0; }
r[0]=0x00000030u;
goto P_0c0944ce;
P_0c0944ce: /* original 430b, guest PC 0x0c0944ce */
if(!s->budget--) { s->failed_pc=0x0c0944ceu; return 0; }
target=r[3];
r[16]=0x0c0944d2u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0944d2u) { target=s->pc; goto dispatch; }
goto P_0c0944d2;
P_0c0944d0: /* original 04ed, guest PC 0x0c0944d0 */
if(!s->budget--) { s->failed_pc=0x0c0944d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0944d2;
P_0c0944d2: /* original d31c, guest PC 0x0c0944d2 */
if(!s->budget--) { s->failed_pc=0x0c0944d2u; return 0; }
r[3]=read(ram,0x0c094544u,4);
goto P_0c0944d4;
P_0c0944d4: /* original e02e, guest PC 0x0c0944d4 */
if(!s->budget--) { s->failed_pc=0x0c0944d4u; return 0; }
r[0]=0x0000002eu;
goto P_0c0944d6;
P_0c0944d6: /* original 430b, guest PC 0x0c0944d6 */
if(!s->budget--) { s->failed_pc=0x0c0944d6u; return 0; }
target=r[3];
r[16]=0x0c0944dau;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0944dau) { target=s->pc; goto dispatch; }
goto P_0c0944da;
P_0c0944d8: /* original 04ed, guest PC 0x0c0944d8 */
if(!s->budget--) { s->failed_pc=0x0c0944d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0944da;
P_0c0944da: /* original 7f40, guest PC 0x0c0944da */
if(!s->budget--) { s->failed_pc=0x0c0944dau; return 0; }
r[15]+=0x00000040u;
goto P_0c0944dc;
P_0c0944dc: /* original d31a, guest PC 0x0c0944dc */
if(!s->budget--) { s->failed_pc=0x0c0944dcu; return 0; }
r[3]=read(ram,0x0c094548u,4);
goto P_0c0944de;
P_0c0944de: /* original e02c, guest PC 0x0c0944de */
if(!s->budget--) { s->failed_pc=0x0c0944deu; return 0; }
r[0]=0x0000002cu;
goto P_0c0944e0;
P_0c0944e0: /* original 4f26, guest PC 0x0c0944e0 */
if(!s->budget--) { s->failed_pc=0x0c0944e0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0944e2;
P_0c0944e2: /* original 04ed, guest PC 0x0c0944e2 */
if(!s->budget--) { s->failed_pc=0x0c0944e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0944e4;
P_0c0944e4: /* original 644d, guest PC 0x0c0944e4 */
if(!s->budget--) { s->failed_pc=0x0c0944e4u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0944e6;
P_0c0944e6: /* original 432b, guest PC 0x0c0944e6 */
if(!s->budget--) { s->failed_pc=0x0c0944e6u; return 0; }
target=r[3];
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
P_0c0944e8: /* original 6ef6, guest PC 0x0c0944e8 */
if(!s->budget--) { s->failed_pc=0x0c0944e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0944ea;
P_0c0944ea: /* original 7f40, guest PC 0x0c0944ea */
if(!s->budget--) { s->failed_pc=0x0c0944eau; return 0; }
r[15]+=0x00000040u;
goto P_0c0944ec;
P_0c0944ec: /* original 4f26, guest PC 0x0c0944ec */
if(!s->budget--) { s->failed_pc=0x0c0944ecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0944ee;
P_0c0944ee: /* original 000b, guest PC 0x0c0944ee */
if(!s->budget--) { s->failed_pc=0x0c0944eeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0944f0: /* original 6ef6, guest PC 0x0c0944f0 */
if(!s->budget--) { s->failed_pc=0x0c0944f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0944f2u,s,ram);
P_0c0a0464: /* original 4f22, guest PC 0x0c0a0464 */
if(!s->budget--) { s->failed_pc=0x0c0a0464u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a0466;
P_0c0a0466: /* original 7ffc, guest PC 0x0c0a0466 */
if(!s->budget--) { s->failed_pc=0x0c0a0466u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a0468;
P_0c0a0468: /* original 2f42, guest PC 0x0c0a0468 */
if(!s->budget--) { s->failed_pc=0x0c0a0468u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a046a;
P_0c0a046a: /* original de5b, guest PC 0x0c0a046a */
if(!s->budget--) { s->failed_pc=0x0c0a046au; return 0; }
r[14]=read(ram,0x0c0a05d8u,4);
goto P_0c0a046c;
P_0c0a046c: /* original d35b, guest PC 0x0c0a046c */
if(!s->budget--) { s->failed_pc=0x0c0a046cu; return 0; }
r[3]=read(ram,0x0c0a05dcu,4);
goto P_0c0a046e;
P_0c0a046e: /* original 430b, guest PC 0x0c0a046e */
if(!s->budget--) { s->failed_pc=0x0c0a046eu; return 0; }
target=r[3];
r[16]=0x0c0a0472u;
r[4]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a0472u) { target=s->pc; goto dispatch; }
goto P_0c0a0472;
P_0c0a0470: /* original 6453, guest PC 0x0c0a0470 */
if(!s->budget--) { s->failed_pc=0x0c0a0470u; return 0; }
r[4]=r[5];
goto P_0c0a0472;
P_0c0a0472: /* original 6203, guest PC 0x0c0a0472 */
if(!s->budget--) { s->failed_pc=0x0c0a0472u; return 0; }
r[2]=r[0];
goto P_0c0a0474;
P_0c0a0474: /* original 6403, guest PC 0x0c0a0474 */
if(!s->budget--) { s->failed_pc=0x0c0a0474u; return 0; }
r[4]=r[0];
goto P_0c0a0476;
P_0c0a0476: /* original 90aa, guest PC 0x0c0a0476 */
if(!s->budget--) { s->failed_pc=0x0c0a0476u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a05ceu,2);
goto P_0c0a0478;
P_0c0a0478: /* original 4229, guest PC 0x0c0a0478 */
if(!s->budget--) { s->failed_pc=0x0c0a0478u; return 0; }
r[2]>>=16;
goto P_0c0a047a;
P_0c0a047a: /* original 4219, guest PC 0x0c0a047a */
if(!s->budget--) { s->failed_pc=0x0c0a047au; return 0; }
r[2]>>=8;
goto P_0c0a047c;
P_0c0a047c: /* original 6343, guest PC 0x0c0a047c */
if(!s->budget--) { s->failed_pc=0x0c0a047cu; return 0; }
r[3]=r[4];
goto P_0c0a047e;
P_0c0a047e: /* original 0e24, guest PC 0x0c0a047e */
if(!s->budget--) { s->failed_pc=0x0c0a047eu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0a0480;
P_0c0a0480: /* original 7001, guest PC 0x0c0a0480 */
if(!s->budget--) { s->failed_pc=0x0c0a0480u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a0482;
P_0c0a0482: /* original 4329, guest PC 0x0c0a0482 */
if(!s->budget--) { s->failed_pc=0x0c0a0482u; return 0; }
r[3]>>=16;
goto P_0c0a0484;
P_0c0a0484: /* original 6243, guest PC 0x0c0a0484 */
if(!s->budget--) { s->failed_pc=0x0c0a0484u; return 0; }
r[2]=r[4];
goto P_0c0a0486;
P_0c0a0486: /* original 0e34, guest PC 0x0c0a0486 */
if(!s->budget--) { s->failed_pc=0x0c0a0486u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0a0488;
P_0c0a0488: /* original 7001, guest PC 0x0c0a0488 */
if(!s->budget--) { s->failed_pc=0x0c0a0488u; return 0; }
r[0]+=0x00000001u;
goto P_0c0a048a;
P_0c0a048a: /* original 4219, guest PC 0x0c0a048a */
if(!s->budget--) { s->failed_pc=0x0c0a048au; return 0; }
r[2]>>=8;
goto P_0c0a048c;
P_0c0a048c: /* original 0e24, guest PC 0x0c0a048c */
if(!s->budget--) { s->failed_pc=0x0c0a048cu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0a048e;
P_0c0a048e: /* original 7001, guest PC 0x0c0a048e */
if(!s->budget--) { s->failed_pc=0x0c0a048eu; return 0; }
r[0]+=0x00000001u;
goto P_0c0a0490;
P_0c0a0490: /* original 0e44, guest PC 0x0c0a0490 */
if(!s->budget--) { s->failed_pc=0x0c0a0490u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a0492;
P_0c0a0492: /* original dc53, guest PC 0x0c0a0492 */
if(!s->budget--) { s->failed_pc=0x0c0a0492u; return 0; }
r[12]=read(ram,0x0c0a05e0u,4);
goto P_0c0a0494;
P_0c0a0494: /* original 4c0b, guest PC 0x0c0a0494 */
if(!s->budget--) { s->failed_pc=0x0c0a0494u; return 0; }
target=r[12];
r[16]=0x0c0a0498u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a0498u) { target=s->pc; goto dispatch; }
goto P_0c0a0498;
P_0c0a0496: /* original 64d3, guest PC 0x0c0a0496 */
if(!s->budget--) { s->failed_pc=0x0c0a0496u; return 0; }
r[4]=r[13];
goto P_0c0a0498;
P_0c0a0498: /* original 9199, guest PC 0x0c0a0498 */
if(!s->budget--) { s->failed_pc=0x0c0a0498u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a05ceu,2);
goto P_0c0a049a;
P_0c0a049a: /* original 64d3, guest PC 0x0c0a049a */
if(!s->budget--) { s->failed_pc=0x0c0a049au; return 0; }
r[4]=r[13];
goto P_0c0a049c;
P_0c0a049c: /* original 31ec, guest PC 0x0c0a049c */
if(!s->budget--) { s->failed_pc=0x0c0a049cu; return 0; }
r[1]+=r[14];
goto P_0c0a049e;
P_0c0a049e: /* original 2100, guest PC 0x0c0a049e */
if(!s->budget--) { s->failed_pc=0x0c0a049eu; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0a04a0;
P_0c0a04a0: /* original 4c0b, guest PC 0x0c0a04a0 */
if(!s->budget--) { s->failed_pc=0x0c0a04a0u; return 0; }
target=r[12];
r[16]=0x0c0a04a4u;
r[4]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a04a4u) { target=s->pc; goto dispatch; }
goto P_0c0a04a4;
P_0c0a04a2: /* original 7401, guest PC 0x0c0a04a2 */
if(!s->budget--) { s->failed_pc=0x0c0a04a2u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a04a4;
P_0c0a04a4: /* original 9194, guest PC 0x0c0a04a4 */
if(!s->budget--) { s->failed_pc=0x0c0a04a4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a05d0u,2);
goto P_0c0a04a6;
P_0c0a04a6: /* original 64d3, guest PC 0x0c0a04a6 */
if(!s->budget--) { s->failed_pc=0x0c0a04a6u; return 0; }
r[4]=r[13];
goto P_0c0a04a8;
P_0c0a04a8: /* original 31ec, guest PC 0x0c0a04a8 */
if(!s->budget--) { s->failed_pc=0x0c0a04a8u; return 0; }
r[1]+=r[14];
goto P_0c0a04aa;
P_0c0a04aa: /* original 2100, guest PC 0x0c0a04aa */
if(!s->budget--) { s->failed_pc=0x0c0a04aau; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0a04ac;
P_0c0a04ac: /* original 4c0b, guest PC 0x0c0a04ac */
if(!s->budget--) { s->failed_pc=0x0c0a04acu; return 0; }
target=r[12];
r[16]=0x0c0a04b0u;
r[4]+=0x00000002u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a04b0u) { target=s->pc; goto dispatch; }
goto P_0c0a04b0;
P_0c0a04ae: /* original 7402, guest PC 0x0c0a04ae */
if(!s->budget--) { s->failed_pc=0x0c0a04aeu; return 0; }
r[4]+=0x00000002u;
goto P_0c0a04b0;
P_0c0a04b0: /* original 918f, guest PC 0x0c0a04b0 */
if(!s->budget--) { s->failed_pc=0x0c0a04b0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a05d2u,2);
goto P_0c0a04b2;
P_0c0a04b2: /* original e300, guest PC 0x0c0a04b2 */
if(!s->budget--) { s->failed_pc=0x0c0a04b2u; return 0; }
r[3]=0x00000000u;
goto P_0c0a04b4;
P_0c0a04b4: /* original e21c, guest PC 0x0c0a04b4 */
if(!s->budget--) { s->failed_pc=0x0c0a04b4u; return 0; }
r[2]=0x0000001cu;
goto P_0c0a04b6;
P_0c0a04b6: /* original 31ec, guest PC 0x0c0a04b6 */
if(!s->budget--) { s->failed_pc=0x0c0a04b6u; return 0; }
r[1]+=r[14];
goto P_0c0a04b8;
P_0c0a04b8: /* original 2100, guest PC 0x0c0a04b8 */
if(!s->budget--) { s->failed_pc=0x0c0a04b8u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0a04ba;
P_0c0a04ba: /* original e601, guest PC 0x0c0a04ba */
if(!s->budget--) { s->failed_pc=0x0c0a04bau; return 0; }
r[6]=0x00000001u;
goto P_0c0a04bc;
P_0c0a04bc: /* original 908a, guest PC 0x0c0a04bc */
if(!s->budget--) { s->failed_pc=0x0c0a04bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a05d4u,2);
goto P_0c0a04be;
P_0c0a04be: /* original 0e34, guest PC 0x0c0a04be */
if(!s->budget--) { s->failed_pc=0x0c0a04beu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0a04c0;
P_0c0a04c0: /* original e307, guest PC 0x0c0a04c0 */
if(!s->budget--) { s->failed_pc=0x0c0a04c0u; return 0; }
r[3]=0x00000007u;
goto P_0c0a04c2;
P_0c0a04c2: /* original 64f2, guest PC 0x0c0a04c2 */
if(!s->budget--) { s->failed_pc=0x0c0a04c2u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a04c4;
P_0c0a04c4: /* original 7f04, guest PC 0x0c0a04c4 */
if(!s->budget--) { s->failed_pc=0x0c0a04c4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a04c6;
P_0c0a04c6: /* original 4f26, guest PC 0x0c0a04c6 */
if(!s->budget--) { s->failed_pc=0x0c0a04c6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a04c8;
P_0c0a04c8: /* original 9581, guest PC 0x0c0a04c8 */
if(!s->budget--) { s->failed_pc=0x0c0a04c8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a05ceu,2);
goto P_0c0a04ca;
P_0c0a04ca: /* original 740c, guest PC 0x0c0a04ca */
if(!s->budget--) { s->failed_pc=0x0c0a04cau; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a04cc;
P_0c0a04cc: /* original d145, guest PC 0x0c0a04cc */
if(!s->budget--) { s->failed_pc=0x0c0a04ccu; return 0; }
r[1]=read(ram,0x0c0a05e4u,4);
goto P_0c0a04ce;
P_0c0a04ce: /* original 443d, guest PC 0x0c0a04ce */
if(!s->budget--) { s->failed_pc=0x0c0a04ceu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c0a04d0;
P_0c0a04d0: /* original 6cf6, guest PC 0x0c0a04d0 */
if(!s->budget--) { s->failed_pc=0x0c0a04d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a04d2;
P_0c0a04d2: /* original 242b, guest PC 0x0c0a04d2 */
if(!s->budget--) { s->failed_pc=0x0c0a04d2u; return 0; }
r[4]|=r[2];
goto P_0c0a04d4;
P_0c0a04d4: /* original 35ec, guest PC 0x0c0a04d4 */
if(!s->budget--) { s->failed_pc=0x0c0a04d4u; return 0; }
r[5]+=r[14];
goto P_0c0a04d6;
P_0c0a04d6: /* original 6df6, guest PC 0x0c0a04d6 */
if(!s->budget--) { s->failed_pc=0x0c0a04d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a04d8;
P_0c0a04d8: /* original 412b, guest PC 0x0c0a04d8 */
if(!s->budget--) { s->failed_pc=0x0c0a04d8u; return 0; }
target=r[1];
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
P_0c0a04da: /* original 6ef6, guest PC 0x0c0a04da */
if(!s->budget--) { s->failed_pc=0x0c0a04dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a04dcu,s,ram);
P_0c0a04e2: /* original 4f22, guest PC 0x0c0a04e2 */
if(!s->budget--) { s->failed_pc=0x0c0a04e2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a04e4;
P_0c0a04e4: /* original 4f12, guest PC 0x0c0a04e4 */
if(!s->budget--) { s->failed_pc=0x0c0a04e4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a04e6;
P_0c0a04e6: /* original 7ff8, guest PC 0x0c0a04e6 */
if(!s->budget--) { s->failed_pc=0x0c0a04e6u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a04e8;
P_0c0a04e8: /* original 2f42, guest PC 0x0c0a04e8 */
if(!s->budget--) { s->failed_pc=0x0c0a04e8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a04ea;
P_0c0a04ea: /* original 1f51, guest PC 0x0c0a04ea */
if(!s->budget--) { s->failed_pc=0x0c0a04eau; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0a04ec;
P_0c0a04ec: /* original d33b, guest PC 0x0c0a04ec */
if(!s->budget--) { s->failed_pc=0x0c0a04ecu; return 0; }
r[3]=read(ram,0x0c0a05dcu,4);
goto P_0c0a04ee;
P_0c0a04ee: /* original 430b, guest PC 0x0c0a04ee */
if(!s->budget--) { s->failed_pc=0x0c0a04eeu; return 0; }
target=r[3];
r[16]=0x0c0a04f2u;
r[4]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a04f2u) { target=s->pc; goto dispatch; }
goto P_0c0a04f2;
P_0c0a04f0: /* original 6453, guest PC 0x0c0a04f0 */
if(!s->budget--) { s->failed_pc=0x0c0a04f0u; return 0; }
r[4]=r[5];
goto P_0c0a04f2;
P_0c0a04f2: /* original ee3f, guest PC 0x0c0a04f2 */
if(!s->budget--) { s->failed_pc=0x0c0a04f2u; return 0; }
r[14]=0x0000003fu;
goto P_0c0a04f4;
P_0c0a04f4: /* original 6403, guest PC 0x0c0a04f4 */
if(!s->budget--) { s->failed_pc=0x0c0a04f4u; return 0; }
r[4]=r[0];
goto P_0c0a04f6;
P_0c0a04f6: /* original 2e49, guest PC 0x0c0a04f6 */
if(!s->budget--) { s->failed_pc=0x0c0a04f6u; return 0; }
r[14]&=r[4];
goto P_0c0a04f8;
P_0c0a04f8: /* original e264, guest PC 0x0c0a04f8 */
if(!s->budget--) { s->failed_pc=0x0c0a04f8u; return 0; }
r[2]=0x00000064u;
goto P_0c0a04fa;
P_0c0a04fa: /* original 0e27, guest PC 0x0c0a04fa */
if(!s->budget--) { s->failed_pc=0x0c0a04fau; return 0; }
r[19]=r[14]*r[2];
goto P_0c0a04fc;
P_0c0a04fc: /* original e3fa, guest PC 0x0c0a04fc */
if(!s->budget--) { s->failed_pc=0x0c0a04fcu; return 0; }
r[3]=0xfffffffau;
goto P_0c0a04fe;
P_0c0a04fe: /* original e50a, guest PC 0x0c0a04fe */
if(!s->budget--) { s->failed_pc=0x0c0a04feu; return 0; }
r[5]=0x0000000au;
goto P_0c0a0500;
P_0c0a0500: /* original e73c, guest PC 0x0c0a0500 */
if(!s->budget--) { s->failed_pc=0x0c0a0500u; return 0; }
r[7]=0x0000003cu;
goto P_0c0a0502;
P_0c0a0502: /* original 0e1a, guest PC 0x0c0a0502 */
if(!s->budget--) { s->failed_pc=0x0c0a0502u; return 0; }
r[14]=r[19];
goto P_0c0a0504;
P_0c0a0504: /* original 4e3c, guest PC 0x0c0a0504 */
if(!s->budget--) { s->failed_pc=0x0c0a0504u; return 0; }
r[14]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[14]>>((-r[3])&31u)):((int32_t)r[14]<0?0xffffffffu:0)):r[14]<<(r[3]&31u);
goto P_0c0a0506;
P_0c0a0506: /* original d338, guest PC 0x0c0a0506 */
if(!s->budget--) { s->failed_pc=0x0c0a0506u; return 0; }
r[3]=read(ram,0x0c0a05e8u,4);
goto P_0c0a0508;
P_0c0a0508: /* original 61e3, guest PC 0x0c0a0508 */
if(!s->budget--) { s->failed_pc=0x0c0a0508u; return 0; }
r[1]=r[14];
goto P_0c0a050a;
P_0c0a050a: /* original 430b, guest PC 0x0c0a050a */
if(!s->budget--) { s->failed_pc=0x0c0a050au; return 0; }
target=r[3];
r[16]=0x0c0a050eu;
r[0]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a050eu) { target=s->pc; goto dispatch; }
goto P_0c0a050e;
P_0c0a050c: /* original 6053, guest PC 0x0c0a050c */
if(!s->budget--) { s->failed_pc=0x0c0a050cu; return 0; }
r[0]=r[5];
goto P_0c0a050e;
P_0c0a050e: /* original 6103, guest PC 0x0c0a050e */
if(!s->budget--) { s->failed_pc=0x0c0a050eu; return 0; }
r[1]=r[0];
goto P_0c0a0510;
P_0c0a0510: /* original 4108, guest PC 0x0c0a0510 */
if(!s->budget--) { s->failed_pc=0x0c0a0510u; return 0; }
r[1]<<=2;
goto P_0c0a0512;
P_0c0a0512: /* original 6303, guest PC 0x0c0a0512 */
if(!s->budget--) { s->failed_pc=0x0c0a0512u; return 0; }
r[3]=r[0];
goto P_0c0a0514;
P_0c0a0514: /* original 313c, guest PC 0x0c0a0514 */
if(!s->budget--) { s->failed_pc=0x0c0a0514u; return 0; }
r[1]+=r[3];
goto P_0c0a0516;
P_0c0a0516: /* original e3fa, guest PC 0x0c0a0516 */
if(!s->budget--) { s->failed_pc=0x0c0a0516u; return 0; }
r[3]=0xfffffffau;
goto P_0c0a0518;
P_0c0a0518: /* original 6c03, guest PC 0x0c0a0518 */
if(!s->budget--) { s->failed_pc=0x0c0a0518u; return 0; }
r[12]=r[0];
goto P_0c0a051a;
P_0c0a051a: /* original 443c, guest PC 0x0c0a051a */
if(!s->budget--) { s->failed_pc=0x0c0a051au; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c0a051c;
P_0c0a051c: /* original d332, guest PC 0x0c0a051c */
if(!s->budget--) { s->failed_pc=0x0c0a051cu; return 0; }
r[3]=read(ram,0x0c0a05e8u,4);
goto P_0c0a051e;
P_0c0a051e: /* original 4100, guest PC 0x0c0a051e */
if(!s->budget--) { s->failed_pc=0x0c0a051eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0a0520;
P_0c0a0520: /* original 3e18, guest PC 0x0c0a0520 */
if(!s->budget--) { s->failed_pc=0x0c0a0520u; return 0; }
r[14]-=r[1];
goto P_0c0a0522;
P_0c0a0522: /* original 6143, guest PC 0x0c0a0522 */
if(!s->budget--) { s->failed_pc=0x0c0a0522u; return 0; }
r[1]=r[4];
goto P_0c0a0524;
P_0c0a0524: /* original 430b, guest PC 0x0c0a0524 */
if(!s->budget--) { s->failed_pc=0x0c0a0524u; return 0; }
target=r[3];
r[16]=0x0c0a0528u;
r[0]=r[7];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a0528u) { target=s->pc; goto dispatch; }
goto P_0c0a0528;
P_0c0a0526: /* original 6073, guest PC 0x0c0a0526 */
if(!s->budget--) { s->failed_pc=0x0c0a0526u; return 0; }
r[0]=r[7];
goto P_0c0a0528;
P_0c0a0528: /* original 6603, guest PC 0x0c0a0528 */
if(!s->budget--) { s->failed_pc=0x0c0a0528u; return 0; }
r[6]=r[0];
goto P_0c0a052a;
P_0c0a052a: /* original 6d43, guest PC 0x0c0a052a */
if(!s->budget--) { s->failed_pc=0x0c0a052au; return 0; }
r[13]=r[4];
goto P_0c0a052c;
P_0c0a052c: /* original 0677, guest PC 0x0c0a052c */
if(!s->budget--) { s->failed_pc=0x0c0a052cu; return 0; }
r[19]=r[6]*r[7];
goto P_0c0a052e;
P_0c0a052e: /* original d32e, guest PC 0x0c0a052e */
if(!s->budget--) { s->failed_pc=0x0c0a052eu; return 0; }
r[3]=read(ram,0x0c0a05e8u,4);
goto P_0c0a0530;
P_0c0a0530: /* original 071a, guest PC 0x0c0a0530 */
if(!s->budget--) { s->failed_pc=0x0c0a0530u; return 0; }
r[7]=r[19];
goto P_0c0a0532;
P_0c0a0532: /* original 3d78, guest PC 0x0c0a0532 */
if(!s->budget--) { s->failed_pc=0x0c0a0532u; return 0; }
r[13]-=r[7];
goto P_0c0a0534;
P_0c0a0534: /* original 61d3, guest PC 0x0c0a0534 */
if(!s->budget--) { s->failed_pc=0x0c0a0534u; return 0; }
r[1]=r[13];
goto P_0c0a0536;
P_0c0a0536: /* original 430b, guest PC 0x0c0a0536 */
if(!s->budget--) { s->failed_pc=0x0c0a0536u; return 0; }
target=r[3];
r[16]=0x0c0a053au;
r[0]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a053au) { target=s->pc; goto dispatch; }
goto P_0c0a053a;
P_0c0a0538: /* original 6053, guest PC 0x0c0a0538 */
if(!s->budget--) { s->failed_pc=0x0c0a0538u; return 0; }
r[0]=r[5];
goto P_0c0a053a;
P_0c0a053a: /* original 6103, guest PC 0x0c0a053a */
if(!s->budget--) { s->failed_pc=0x0c0a053au; return 0; }
r[1]=r[0];
goto P_0c0a053c;
P_0c0a053c: /* original 4108, guest PC 0x0c0a053c */
if(!s->budget--) { s->failed_pc=0x0c0a053cu; return 0; }
r[1]<<=2;
goto P_0c0a053e;
P_0c0a053e: /* original 6303, guest PC 0x0c0a053e */
if(!s->budget--) { s->failed_pc=0x0c0a053eu; return 0; }
r[3]=r[0];
goto P_0c0a0540;
P_0c0a0540: /* original 313c, guest PC 0x0c0a0540 */
if(!s->budget--) { s->failed_pc=0x0c0a0540u; return 0; }
r[1]+=r[3];
goto P_0c0a0542;
P_0c0a0542: /* original 4100, guest PC 0x0c0a0542 */
if(!s->budget--) { s->failed_pc=0x0c0a0542u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0a0544;
P_0c0a0544: /* original d328, guest PC 0x0c0a0544 */
if(!s->budget--) { s->failed_pc=0x0c0a0544u; return 0; }
r[3]=read(ram,0x0c0a05e8u,4);
goto P_0c0a0546;
P_0c0a0546: /* original 3d18, guest PC 0x0c0a0546 */
if(!s->budget--) { s->failed_pc=0x0c0a0546u; return 0; }
r[13]-=r[1];
goto P_0c0a0548;
P_0c0a0548: /* original 6703, guest PC 0x0c0a0548 */
if(!s->budget--) { s->failed_pc=0x0c0a0548u; return 0; }
r[7]=r[0];
goto P_0c0a054a;
P_0c0a054a: /* original 6163, guest PC 0x0c0a054a */
if(!s->budget--) { s->failed_pc=0x0c0a054au; return 0; }
r[1]=r[6];
goto P_0c0a054c;
P_0c0a054c: /* original 430b, guest PC 0x0c0a054c */
if(!s->budget--) { s->failed_pc=0x0c0a054cu; return 0; }
target=r[3];
r[16]=0x0c0a0550u;
r[0]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a0550u) { target=s->pc; goto dispatch; }
goto P_0c0a0550;
P_0c0a054e: /* original 6053, guest PC 0x0c0a054e */
if(!s->budget--) { s->failed_pc=0x0c0a054eu; return 0; }
r[0]=r[5];
goto P_0c0a0550;
P_0c0a0550: /* original 6103, guest PC 0x0c0a0550 */
if(!s->budget--) { s->failed_pc=0x0c0a0550u; return 0; }
r[1]=r[0];
goto P_0c0a0552;
P_0c0a0552: /* original 64f2, guest PC 0x0c0a0552 */
if(!s->budget--) { s->failed_pc=0x0c0a0552u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a0554;
P_0c0a0554: /* original 4108, guest PC 0x0c0a0554 */
if(!s->budget--) { s->failed_pc=0x0c0a0554u; return 0; }
r[1]<<=2;
goto P_0c0a0556;
P_0c0a0556: /* original 2fe6, guest PC 0x0c0a0556 */
if(!s->budget--) { s->failed_pc=0x0c0a0556u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0a0558;
P_0c0a0558: /* original 6303, guest PC 0x0c0a0558 */
if(!s->budget--) { s->failed_pc=0x0c0a0558u; return 0; }
r[3]=r[0];
goto P_0c0a055a;
P_0c0a055a: /* original 2fc6, guest PC 0x0c0a055a */
if(!s->budget--) { s->failed_pc=0x0c0a055au; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0a055c;
P_0c0a055c: /* original 313c, guest PC 0x0c0a055c */
if(!s->budget--) { s->failed_pc=0x0c0a055cu; return 0; }
r[1]+=r[3];
goto P_0c0a055e;
P_0c0a055e: /* original 2fd6, guest PC 0x0c0a055e */
if(!s->budget--) { s->failed_pc=0x0c0a055eu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0a0560;
P_0c0a0560: /* original e307, guest PC 0x0c0a0560 */
if(!s->budget--) { s->failed_pc=0x0c0a0560u; return 0; }
r[3]=0x00000007u;
goto P_0c0a0562;
P_0c0a0562: /* original 2f76, guest PC 0x0c0a0562 */
if(!s->budget--) { s->failed_pc=0x0c0a0562u; return 0; }
r[15]-=4; write(ram,r[15],r[7],4);
goto P_0c0a0564;
P_0c0a0564: /* original 740c, guest PC 0x0c0a0564 */
if(!s->budget--) { s->failed_pc=0x0c0a0564u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a0566;
P_0c0a0566: /* original 6503, guest PC 0x0c0a0566 */
if(!s->budget--) { s->failed_pc=0x0c0a0566u; return 0; }
r[5]=r[0];
goto P_0c0a0568;
P_0c0a0568: /* original 4100, guest PC 0x0c0a0568 */
if(!s->budget--) { s->failed_pc=0x0c0a0568u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0a056a;
P_0c0a056a: /* original 443c, guest PC 0x0c0a056a */
if(!s->budget--) { s->failed_pc=0x0c0a056au; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c0a056c;
P_0c0a056c: /* original 3618, guest PC 0x0c0a056c */
if(!s->budget--) { s->failed_pc=0x0c0a056cu; return 0; }
r[6]-=r[1];
goto P_0c0a056e;
P_0c0a056e: /* original 2f66, guest PC 0x0c0a056e */
if(!s->budget--) { s->failed_pc=0x0c0a056eu; return 0; }
r[15]-=4; write(ram,r[15],r[6],4);
goto P_0c0a0570;
P_0c0a0570: /* original e12e, guest PC 0x0c0a0570 */
if(!s->budget--) { s->failed_pc=0x0c0a0570u; return 0; }
r[1]=0x0000002eu;
goto P_0c0a0572;
P_0c0a0572: /* original 241b, guest PC 0x0c0a0572 */
if(!s->budget--) { s->failed_pc=0x0c0a0572u; return 0; }
r[4]|=r[1];
goto P_0c0a0574;
P_0c0a0574: /* original 2f56, guest PC 0x0c0a0574 */
if(!s->budget--) { s->failed_pc=0x0c0a0574u; return 0; }
r[15]-=4; write(ram,r[15],r[5],4);
goto P_0c0a0576;
P_0c0a0576: /* original d31e, guest PC 0x0c0a0576 */
if(!s->budget--) { s->failed_pc=0x0c0a0576u; return 0; }
r[3]=read(ram,0x0c0a05f0u,4);
goto P_0c0a0578;
P_0c0a0578: /* original d21c, guest PC 0x0c0a0578 */
if(!s->budget--) { s->failed_pc=0x0c0a0578u; return 0; }
r[2]=read(ram,0x0c0a05ecu,4);
goto P_0c0a057a;
P_0c0a057a: /* original 430b, guest PC 0x0c0a057a */
if(!s->budget--) { s->failed_pc=0x0c0a057au; return 0; }
target=r[3];
r[16]=0x0c0a057eu;
r[15]-=4; write(ram,r[15],r[2],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a057eu) { target=s->pc; goto dispatch; }
goto P_0c0a057e;
P_0c0a057c: /* original 2f26, guest PC 0x0c0a057c */
if(!s->budget--) { s->failed_pc=0x0c0a057cu; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c0a057e;
P_0c0a057e: /* original 7f24, guest PC 0x0c0a057e */
if(!s->budget--) { s->failed_pc=0x0c0a057eu; return 0; }
r[15]+=0x00000024u;
goto P_0c0a0580;
P_0c0a0580: /* original 4f16, guest PC 0x0c0a0580 */
if(!s->budget--) { s->failed_pc=0x0c0a0580u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0582;
P_0c0a0582: /* original 4f26, guest PC 0x0c0a0582 */
if(!s->budget--) { s->failed_pc=0x0c0a0582u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0584;
P_0c0a0584: /* original 6cf6, guest PC 0x0c0a0584 */
if(!s->budget--) { s->failed_pc=0x0c0a0584u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a0586;
P_0c0a0586: /* original 6df6, guest PC 0x0c0a0586 */
if(!s->budget--) { s->failed_pc=0x0c0a0586u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a0588;
P_0c0a0588: /* original 000b, guest PC 0x0c0a0588 */
if(!s->budget--) { s->failed_pc=0x0c0a0588u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a058a: /* original 6ef6, guest PC 0x0c0a058a */
if(!s->budget--) { s->failed_pc=0x0c0a058au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a058cu,s,ram);
P_0c0a1212: /* original 4f22, guest PC 0x0c0a1212 */
if(!s->budget--) { s->failed_pc=0x0c0a1212u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a1214;
P_0c0a1214: /* original d33b, guest PC 0x0c0a1214 */
if(!s->budget--) { s->failed_pc=0x0c0a1214u; return 0; }
r[3]=read(ram,0x0c0a1304u,4);
goto P_0c0a1216;
P_0c0a1216: /* original de3a, guest PC 0x0c0a1216 */
if(!s->budget--) { s->failed_pc=0x0c0a1216u; return 0; }
r[14]=read(ram,0x0c0a1300u,4);
goto P_0c0a1218;
P_0c0a1218: /* original 430b, guest PC 0x0c0a1218 */
if(!s->budget--) { s->failed_pc=0x0c0a1218u; return 0; }
target=r[3];
r[16]=0x0c0a121cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a121cu) { target=s->pc; goto dispatch; }
goto P_0c0a121c;
P_0c0a121a: /* original 0009, guest PC 0x0c0a121a */
if(!s->budget--) { s->failed_pc=0x0c0a121au; return 0; }
goto P_0c0a121c;
P_0c0a121c: /* original dc3a, guest PC 0x0c0a121c */
if(!s->budget--) { s->failed_pc=0x0c0a121cu; return 0; }
r[12]=read(ram,0x0c0a1308u,4);
goto P_0c0a121e;
P_0c0a121e: /* original ed00, guest PC 0x0c0a121e */
if(!s->budget--) { s->failed_pc=0x0c0a121eu; return 0; }
r[13]=0x00000000u;
goto P_0c0a1220;
P_0c0a1220: /* original 9b60, guest PC 0x0c0a1220 */
if(!s->budget--) { s->failed_pc=0x0c0a1220u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a12e4u,2);
goto P_0c0a1222;
P_0c0a1222: /* original 6ad3, guest PC 0x0c0a1222 */
if(!s->budget--) { s->failed_pc=0x0c0a1222u; return 0; }
r[10]=r[13];
goto P_0c0a1224;
P_0c0a1224: /* original e8fe, guest PC 0x0c0a1224 */
if(!s->budget--) { s->failed_pc=0x0c0a1224u; return 0; }
r[8]=0xfffffffeu;
goto P_0c0a1226;
P_0c0a1226: /* original e902, guest PC 0x0c0a1226 */
if(!s->budget--) { s->failed_pc=0x0c0a1226u; return 0; }
r[9]=0x00000002u;
goto P_0c0a1228;
P_0c0a1228: /* original 64a3, guest PC 0x0c0a1228 */
if(!s->budget--) { s->failed_pc=0x0c0a1228u; return 0; }
r[4]=r[10];
goto P_0c0a122a;
P_0c0a122a: /* original 63a3, guest PC 0x0c0a122a */
if(!s->budget--) { s->failed_pc=0x0c0a122au; return 0; }
r[3]=r[10];
goto P_0c0a122c;
P_0c0a122c: /* original 4308, guest PC 0x0c0a122c */
if(!s->budget--) { s->failed_pc=0x0c0a122cu; return 0; }
r[3]<<=2;
goto P_0c0a122e;
P_0c0a122e: /* original 1ed2, guest PC 0x0c0a122e */
if(!s->budget--) { s->failed_pc=0x0c0a122eu; return 0; }
write(ram,r[14]+8,r[13],4);
goto P_0c0a1230;
P_0c0a1230: /* original 4400, guest PC 0x0c0a1230 */
if(!s->budget--) { s->failed_pc=0x0c0a1230u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a1232;
P_0c0a1232: /* original 1ed3, guest PC 0x0c0a1232 */
if(!s->budget--) { s->failed_pc=0x0c0a1232u; return 0; }
write(ram,r[14]+12,r[13],4);
goto P_0c0a1234;
P_0c0a1234: /* original 1ed4, guest PC 0x0c0a1234 */
if(!s->budget--) { s->failed_pc=0x0c0a1234u; return 0; }
write(ram,r[14]+16,r[13],4);
goto P_0c0a1236;
P_0c0a1236: /* original d235, guest PC 0x0c0a1236 */
if(!s->budget--) { s->failed_pc=0x0c0a1236u; return 0; }
r[2]=read(ram,0x0c0a130cu,4);
goto P_0c0a1238;
P_0c0a1238: /* original 420b, guest PC 0x0c0a1238 */
if(!s->budget--) { s->failed_pc=0x0c0a1238u; return 0; }
target=r[2];
r[16]=0x0c0a123cu;
r[4]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a123cu) { target=s->pc; goto dispatch; }
goto P_0c0a123c;
P_0c0a123a: /* original 343c, guest PC 0x0c0a123a */
if(!s->budget--) { s->failed_pc=0x0c0a123au; return 0; }
r[4]+=r[3];
goto P_0c0a123c;
P_0c0a123c: /* original 6403, guest PC 0x0c0a123c */
if(!s->budget--) { s->failed_pc=0x0c0a123cu; return 0; }
r[4]=r[0];
goto P_0c0a123e;
P_0c0a123e: /* original 5341, guest PC 0x0c0a123e */
if(!s->budget--) { s->failed_pc=0x0c0a123eu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0a1240;
P_0c0a1240: /* original 23b9, guest PC 0x0c0a1240 */
if(!s->budget--) { s->failed_pc=0x0c0a1240u; return 0; }
r[3]&=r[11];
goto P_0c0a1242;
P_0c0a1242: /* original 33b0, guest PC 0x0c0a1242 */
if(!s->budget--) { s->failed_pc=0x0c0a1242u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[11])!=0);
goto P_0c0a1244;
P_0c0a1244: /* original 8b01, guest PC 0x0c0a1244 */
if(!s->budget--) { s->failed_pc=0x0c0a1244u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a124a; }
goto P_0c0a1246;
P_0c0a1246: /* original a007, guest PC 0x0c0a1246 */
if(!s->budget--) { s->failed_pc=0x0c0a1246u; return 0; }
write(ram,r[14],r[11],4);
goto P_0c0a1258;
P_0c0a1248: /* original 2eb2, guest PC 0x0c0a1248 */
if(!s->budget--) { s->failed_pc=0x0c0a1248u; return 0; }
write(ram,r[14],r[11],4);
goto P_0c0a124a;
P_0c0a124a: /* original 5241, guest PC 0x0c0a124a */
if(!s->budget--) { s->failed_pc=0x0c0a124au; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c0a124c;
P_0c0a124c: /* original 22c9, guest PC 0x0c0a124c */
if(!s->budget--) { s->failed_pc=0x0c0a124cu; return 0; }
r[2]&=r[12];
goto P_0c0a124e;
P_0c0a124e: /* original 32c0, guest PC 0x0c0a124e */
if(!s->budget--) { s->failed_pc=0x0c0a124eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[12])!=0);
goto P_0c0a1250;
P_0c0a1250: /* original 8b01, guest PC 0x0c0a1250 */
if(!s->budget--) { s->failed_pc=0x0c0a1250u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a1256; }
goto P_0c0a1252;
P_0c0a1252: /* original a001, guest PC 0x0c0a1252 */
if(!s->budget--) { s->failed_pc=0x0c0a1252u; return 0; }
write(ram,r[14],r[12],4);
goto P_0c0a1258;
P_0c0a1254: /* original 2ec2, guest PC 0x0c0a1254 */
if(!s->budget--) { s->failed_pc=0x0c0a1254u; return 0; }
write(ram,r[14],r[12],4);
goto P_0c0a1256;
P_0c0a1256: /* original 2e82, guest PC 0x0c0a1256 */
if(!s->budget--) { s->failed_pc=0x0c0a1256u; return 0; }
write(ram,r[14],r[8],4);
goto P_0c0a1258;
P_0c0a1258: /* original 5341, guest PC 0x0c0a1258 */
if(!s->budget--) { s->failed_pc=0x0c0a1258u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0a125a;
P_0c0a125a: /* original 7a01, guest PC 0x0c0a125a */
if(!s->budget--) { s->failed_pc=0x0c0a125au; return 0; }
r[10]+=0x00000001u;
goto P_0c0a125c;
P_0c0a125c: /* original 3a93, guest PC 0x0c0a125c */
if(!s->budget--) { s->failed_pc=0x0c0a125cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[9])!=0);
goto P_0c0a125e;
P_0c0a125e: /* original 1e31, guest PC 0x0c0a125e */
if(!s->budget--) { s->failed_pc=0x0c0a125eu; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c0a1260;
P_0c0a1260: /* original 5244, guest PC 0x0c0a1260 */
if(!s->budget--) { s->failed_pc=0x0c0a1260u; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c0a1262;
P_0c0a1262: /* original 1e22, guest PC 0x0c0a1262 */
if(!s->budget--) { s->failed_pc=0x0c0a1262u; return 0; }
write(ram,r[14]+8,r[2],4);
goto P_0c0a1264;
P_0c0a1264: /* original 5345, guest PC 0x0c0a1264 */
if(!s->budget--) { s->failed_pc=0x0c0a1264u; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c0a1266;
P_0c0a1266: /* original 1e33, guest PC 0x0c0a1266 */
if(!s->budget--) { s->failed_pc=0x0c0a1266u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c0a1268;
P_0c0a1268: /* original 5242, guest PC 0x0c0a1268 */
if(!s->budget--) { s->failed_pc=0x0c0a1268u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c0a126a;
P_0c0a126a: /* original 1e24, guest PC 0x0c0a126a */
if(!s->budget--) { s->failed_pc=0x0c0a126au; return 0; }
write(ram,r[14]+16,r[2],4);
goto P_0c0a126c;
P_0c0a126c: /* original 8fdc, guest PC 0x0c0a126c */
if(!s->budget--) { s->failed_pc=0x0c0a126cu; return 0; }
cond=r[17]&1u;
r[14]+=0x00000014u;
if(!cond) { goto P_0c0a1228; }
goto P_0c0a1270;
P_0c0a126e: /* original 7e14, guest PC 0x0c0a126e */
if(!s->budget--) { s->failed_pc=0x0c0a126eu; return 0; }
r[14]+=0x00000014u;
goto P_0c0a1270;
P_0c0a1270: /* original 4f26, guest PC 0x0c0a1270 */
if(!s->budget--) { s->failed_pc=0x0c0a1270u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a1272;
P_0c0a1272: /* original 68f6, guest PC 0x0c0a1272 */
if(!s->budget--) { s->failed_pc=0x0c0a1272u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a1274;
P_0c0a1274: /* original 69f6, guest PC 0x0c0a1274 */
if(!s->budget--) { s->failed_pc=0x0c0a1274u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a1276;
P_0c0a1276: /* original 6af6, guest PC 0x0c0a1276 */
if(!s->budget--) { s->failed_pc=0x0c0a1276u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a1278;
P_0c0a1278: /* original 6bf6, guest PC 0x0c0a1278 */
if(!s->budget--) { s->failed_pc=0x0c0a1278u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a127a;
P_0c0a127a: /* original 6cf6, guest PC 0x0c0a127a */
if(!s->budget--) { s->failed_pc=0x0c0a127au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a127c;
P_0c0a127c: /* original 6df6, guest PC 0x0c0a127c */
if(!s->budget--) { s->failed_pc=0x0c0a127cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a127e;
P_0c0a127e: /* original 000b, guest PC 0x0c0a127e */
if(!s->budget--) { s->failed_pc=0x0c0a127eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a1280: /* original 6ef6, guest PC 0x0c0a1280 */
if(!s->budget--) { s->failed_pc=0x0c0a1280u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a1282u,s,ram);
P_0c0a7b56: /* original 2fe6, guest PC 0x0c0a7b56 */
if(!s->budget--) { s->failed_pc=0x0c0a7b56u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0a7b58;
P_0c0a7b58: /* original de0f, guest PC 0x0c0a7b58 */
if(!s->budget--) { s->failed_pc=0x0c0a7b58u; return 0; }
r[14]=read(ram,0x0c0a7b98u,4);
goto P_0c0a7b5a;
P_0c0a7b5a: /* original 4f22, guest PC 0x0c0a7b5a */
if(!s->budget--) { s->failed_pc=0x0c0a7b5au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7b5c;
P_0c0a7b5c: /* original 60e2, guest PC 0x0c0a7b5c */
if(!s->budget--) { s->failed_pc=0x0c0a7b5cu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0a7b5e;
P_0c0a7b5e: /* original c801, guest PC 0x0c0a7b5e */
if(!s->budget--) { s->failed_pc=0x0c0a7b5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a7b60;
P_0c0a7b60: /* original 890e, guest PC 0x0c0a7b60 */
if(!s->budget--) { s->failed_pc=0x0c0a7b60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7b80; }
goto P_0c0a7b62;
P_0c0a7b62: /* original d30e, guest PC 0x0c0a7b62 */
if(!s->budget--) { s->failed_pc=0x0c0a7b62u; return 0; }
r[3]=read(ram,0x0c0a7b9cu,4);
goto P_0c0a7b64;
P_0c0a7b64: /* original 9012, guest PC 0x0c0a7b64 */
if(!s->budget--) { s->failed_pc=0x0c0a7b64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7b8cu,2);
goto P_0c0a7b66;
P_0c0a7b66: /* original 430b, guest PC 0x0c0a7b66 */
if(!s->budget--) { s->failed_pc=0x0c0a7b66u; return 0; }
target=r[3];
r[16]=0x0c0a7b6au;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7b6au) { target=s->pc; goto dispatch; }
goto P_0c0a7b6a;
P_0c0a7b68: /* original f4e6, guest PC 0x0c0a7b68 */
if(!s->budget--) { s->failed_pc=0x0c0a7b68u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a7b6a;
P_0c0a7b6a: /* original d20d, guest PC 0x0c0a7b6a */
if(!s->budget--) { s->failed_pc=0x0c0a7b6au; return 0; }
r[2]=read(ram,0x0c0a7ba0u,4);
goto P_0c0a7b6c;
P_0c0a7b6c: /* original 420b, guest PC 0x0c0a7b6c */
if(!s->budget--) { s->failed_pc=0x0c0a7b6cu; return 0; }
target=r[2];
r[16]=0x0c0a7b70u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7b70u) { target=s->pc; goto dispatch; }
goto P_0c0a7b70;
P_0c0a7b6e: /* original 6403, guest PC 0x0c0a7b6e */
if(!s->budget--) { s->failed_pc=0x0c0a7b6eu; return 0; }
r[4]=r[0];
goto P_0c0a7b70;
P_0c0a7b70: /* original d30c, guest PC 0x0c0a7b70 */
if(!s->budget--) { s->failed_pc=0x0c0a7b70u; return 0; }
r[3]=read(ram,0x0c0a7ba4u,4);
goto P_0c0a7b72;
P_0c0a7b72: /* original 940c, guest PC 0x0c0a7b72 */
if(!s->budget--) { s->failed_pc=0x0c0a7b72u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7b8eu,2);
goto P_0c0a7b74;
P_0c0a7b74: /* original 430b, guest PC 0x0c0a7b74 */
if(!s->budget--) { s->failed_pc=0x0c0a7b74u; return 0; }
target=r[3];
r[16]=0x0c0a7b78u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7b78u) { target=s->pc; goto dispatch; }
goto P_0c0a7b78;
P_0c0a7b76: /* original 34ec, guest PC 0x0c0a7b76 */
if(!s->budget--) { s->failed_pc=0x0c0a7b76u; return 0; }
r[4]+=r[14];
goto P_0c0a7b78;
P_0c0a7b78: /* original 62e2, guest PC 0x0c0a7b78 */
if(!s->budget--) { s->failed_pc=0x0c0a7b78u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0a7b7a;
P_0c0a7b7a: /* original e3fe, guest PC 0x0c0a7b7a */
if(!s->budget--) { s->failed_pc=0x0c0a7b7au; return 0; }
r[3]=0xfffffffeu;
goto P_0c0a7b7c;
P_0c0a7b7c: /* original 2239, guest PC 0x0c0a7b7c */
if(!s->budget--) { s->failed_pc=0x0c0a7b7cu; return 0; }
r[2]&=r[3];
goto P_0c0a7b7e;
P_0c0a7b7e: /* original 2e22, guest PC 0x0c0a7b7e */
if(!s->budget--) { s->failed_pc=0x0c0a7b7eu; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a7b80;
P_0c0a7b80: /* original 4f26, guest PC 0x0c0a7b80 */
if(!s->budget--) { s->failed_pc=0x0c0a7b80u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7b82;
P_0c0a7b82: /* original 000b, guest PC 0x0c0a7b82 */
if(!s->budget--) { s->failed_pc=0x0c0a7b82u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a7b84: /* original 6ef6, guest PC 0x0c0a7b84 */
if(!s->budget--) { s->failed_pc=0x0c0a7b84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a7b86u,s,ram);
P_0c0ae29c: /* original 5762, guest PC 0x0c0ae29c */
if(!s->budget--) { s->failed_pc=0x0c0ae29cu; return 0; }
r[7]=read(ram,r[6]+8,4);
goto P_0c0ae29e;
P_0c0ae29e: /* original 7ffc, guest PC 0x0c0ae29e */
if(!s->budget--) { s->failed_pc=0x0c0ae29eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ae2a0;
P_0c0ae2a0: /* original 6770, guest PC 0x0c0ae2a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]=tmp;
goto P_0c0ae2a2;
P_0c0ae2a2: /* original 677c, guest PC 0x0c0ae2a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a2u; return 0; }
r[7]=r[7]&255u;
goto P_0c0ae2a4;
P_0c0ae2a4: /* original 2778, guest PC 0x0c0ae2a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0ae2a6;
P_0c0ae2a6: /* original 8910, guest PC 0x0c0ae2a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae2ca; }
goto P_0c0ae2a8;
P_0c0ae2a8: /* original 5362, guest PC 0x0c0ae2a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a8u; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c0ae2aa;
P_0c0ae2aa: /* original 2f32, guest PC 0x0c0ae2aa */
if(!s->budget--) { s->failed_pc=0x0c0ae2aau; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ae2ac;
P_0c0ae2ac: /* original 62f2, guest PC 0x0c0ae2ac */
if(!s->budget--) { s->failed_pc=0x0c0ae2acu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0ae2ae;
P_0c0ae2ae: /* original 8432, guest PC 0x0c0ae2ae */
if(!s->budget--) { s->failed_pc=0x0c0ae2aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+2,1);
goto P_0c0ae2b0;
P_0c0ae2b0: /* original 7201, guest PC 0x0c0ae2b0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b0u; return 0; }
r[2]+=0x00000001u;
goto P_0c0ae2b2;
P_0c0ae2b2: /* original d315, guest PC 0x0c0ae2b2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b2u; return 0; }
r[3]=read(ram,0x0c0ae308u,4);
goto P_0c0ae2b4;
P_0c0ae2b4: /* original 600c, guest PC 0x0c0ae2b4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae2b6;
P_0c0ae2b6: /* original 6220, guest PC 0x0c0ae2b6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]=tmp;
goto P_0c0ae2b8;
P_0c0ae2b8: /* original 4018, guest PC 0x0c0ae2b8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b8u; return 0; }
r[0]<<=8;
goto P_0c0ae2ba;
P_0c0ae2ba: /* original 622c, guest PC 0x0c0ae2ba */
if(!s->budget--) { s->failed_pc=0x0c0ae2bau; return 0; }
r[2]=r[2]&255u;
goto P_0c0ae2bc;
P_0c0ae2bc: /* original 2039, guest PC 0x0c0ae2bc */
if(!s->budget--) { s->failed_pc=0x0c0ae2bcu; return 0; }
r[0]&=r[3];
goto P_0c0ae2be;
P_0c0ae2be: /* original 202b, guest PC 0x0c0ae2be */
if(!s->budget--) { s->failed_pc=0x0c0ae2beu; return 0; }
r[0]|=r[2];
goto P_0c0ae2c0;
P_0c0ae2c0: /* original 6103, guest PC 0x0c0ae2c0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c0u; return 0; }
r[1]=r[0];
goto P_0c0ae2c2;
P_0c0ae2c2: /* original 1601, guest PC 0x0c0ae2c2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c2u; return 0; }
write(ram,r[6]+4,r[0],4);
goto P_0c0ae2c4;
P_0c0ae2c4: /* original 6262, guest PC 0x0c0ae2c4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c4u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0ae2c6;
P_0c0ae2c6: /* original 3212, guest PC 0x0c0ae2c6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[1])!=0);
goto P_0c0ae2c8;
P_0c0ae2c8: /* original 8902, guest PC 0x0c0ae2c8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae2d0; }
goto P_0c0ae2ca;
P_0c0ae2ca: /* original d310, guest PC 0x0c0ae2ca */
if(!s->budget--) { s->failed_pc=0x0c0ae2cau; return 0; }
r[3]=read(ram,0x0c0ae30cu,4);
goto P_0c0ae2cc;
P_0c0ae2cc: /* original 432b, guest PC 0x0c0ae2cc */
if(!s->budget--) { s->failed_pc=0x0c0ae2ccu; return 0; }
target=r[3];
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
P_0c0ae2ce: /* original 7f04, guest PC 0x0c0ae2ce */
if(!s->budget--) { s->failed_pc=0x0c0ae2ceu; return 0; }
r[15]+=0x00000004u;
goto P_0c0ae2d0;
P_0c0ae2d0: /* original d00f, guest PC 0x0c0ae2d0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d0u; return 0; }
r[0]=read(ram,0x0c0ae310u,4);
goto P_0c0ae2d2;
P_0c0ae2d2: /* original 4708, guest PC 0x0c0ae2d2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d2u; return 0; }
r[7]<<=2;
goto P_0c0ae2d4;
P_0c0ae2d4: /* original 027e, guest PC 0x0c0ae2d4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d4u; return 0; }
r[2]=read(ram,r[7]+r[0],4);
goto P_0c0ae2d6;
P_0c0ae2d6: /* original 2f22, guest PC 0x0c0ae2d6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d6u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ae2d8;
P_0c0ae2d8: /* original 422b, guest PC 0x0c0ae2d8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d8u; return 0; }
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
P_0c0ae2da: /* original 7f04, guest PC 0x0c0ae2da */
if(!s->budget--) { s->failed_pc=0x0c0ae2dau; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c0ae2dcu,s,ram);
P_0c0ae6e8: /* original 2fe6, guest PC 0x0c0ae6e8 */
if(!s->budget--) { s->failed_pc=0x0c0ae6e8u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0ae6ea;
P_0c0ae6ea: /* original 2fd6, guest PC 0x0c0ae6ea */
if(!s->budget--) { s->failed_pc=0x0c0ae6eau; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0ae6ec;
P_0c0ae6ec: /* original 6d63, guest PC 0x0c0ae6ec */
if(!s->budget--) { s->failed_pc=0x0c0ae6ecu; return 0; }
r[13]=r[6];
goto P_0c0ae6ee;
P_0c0ae6ee: /* original 2fc6, guest PC 0x0c0ae6ee */
if(!s->budget--) { s->failed_pc=0x0c0ae6eeu; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0ae6f0;
P_0c0ae6f0: /* original 2fb6, guest PC 0x0c0ae6f0 */
if(!s->budget--) { s->failed_pc=0x0c0ae6f0u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0ae6f2;
P_0c0ae6f2: /* original 2fa6, guest PC 0x0c0ae6f2 */
if(!s->budget--) { s->failed_pc=0x0c0ae6f2u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0ae6f4;
P_0c0ae6f4: /* original 2f96, guest PC 0x0c0ae6f4 */
if(!s->budget--) { s->failed_pc=0x0c0ae6f4u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0ae6f6;
P_0c0ae6f6: /* original 4f22, guest PC 0x0c0ae6f6 */
if(!s->budget--) { s->failed_pc=0x0c0ae6f6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ae6f8;
P_0c0ae6f8: /* original 7ff4, guest PC 0x0c0ae6f8 */
if(!s->budget--) { s->failed_pc=0x0c0ae6f8u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0ae6fa;
P_0c0ae6fa: /* original 2f52, guest PC 0x0c0ae6fa */
if(!s->budget--) { s->failed_pc=0x0c0ae6fau; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ae6fc;
P_0c0ae6fc: /* original 53d1, guest PC 0x0c0ae6fc */
if(!s->budget--) { s->failed_pc=0x0c0ae6fcu; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0ae6fe;
P_0c0ae6fe: /* original 62d2, guest PC 0x0c0ae6fe */
if(!s->budget--) { s->failed_pc=0x0c0ae6feu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ae700;
P_0c0ae700: /* original de2e, guest PC 0x0c0ae700 */
if(!s->budget--) { s->failed_pc=0x0c0ae700u; return 0; }
r[14]=read(ram,0x0c0ae7bcu,4);
goto P_0c0ae702;
P_0c0ae702: /* original 3230, guest PC 0x0c0ae702 */
if(!s->budget--) { s->failed_pc=0x0c0ae702u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0ae704;
P_0c0ae704: /* original 8f43, guest PC 0x0c0ae704 */
if(!s->budget--) { s->failed_pc=0x0c0ae704u; return 0; }
cond=r[17]&1u;
r[12]=r[4];
if(!cond) { goto P_0c0ae78e; }
goto P_0c0ae708;
P_0c0ae706: /* original 6c43, guest PC 0x0c0ae706 */
if(!s->budget--) { s->failed_pc=0x0c0ae706u; return 0; }
r[12]=r[4];
goto P_0c0ae708;
P_0c0ae708: /* original 61e2, guest PC 0x0c0ae708 */
if(!s->budget--) { s->failed_pc=0x0c0ae708u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0ae70a;
P_0c0ae70a: /* original d32d, guest PC 0x0c0ae70a */
if(!s->budget--) { s->failed_pc=0x0c0ae70au; return 0; }
r[3]=read(ram,0x0c0ae7c0u,4);
goto P_0c0ae70c;
P_0c0ae70c: /* original 2138, guest PC 0x0c0ae70c */
if(!s->budget--) { s->failed_pc=0x0c0ae70cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0ae70e;
P_0c0ae70e: /* original 8b3e, guest PC 0x0c0ae70e */
if(!s->budget--) { s->failed_pc=0x0c0ae70eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae78e; }
goto P_0c0ae710;
P_0c0ae710: /* original 5bd2, guest PC 0x0c0ae710 */
if(!s->budget--) { s->failed_pc=0x0c0ae710u; return 0; }
r[11]=read(ram,r[13]+8,4);
goto P_0c0ae712;
P_0c0ae712: /* original e061, guest PC 0x0c0ae712 */
if(!s->budget--) { s->failed_pc=0x0c0ae712u; return 0; }
r[0]=0x00000061u;
goto P_0c0ae714;
P_0c0ae714: /* original 03cc, guest PC 0x0c0ae714 */
if(!s->budget--) { s->failed_pc=0x0c0ae714u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0ae716;
P_0c0ae716: /* original 7b03, guest PC 0x0c0ae716 */
if(!s->budget--) { s->failed_pc=0x0c0ae716u; return 0; }
r[11]+=0x00000003u;
goto P_0c0ae718;
P_0c0ae718: /* original 6bb0, guest PC 0x0c0ae718 */
if(!s->budget--) { s->failed_pc=0x0c0ae718u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[11]=tmp;
goto P_0c0ae71a;
P_0c0ae71a: /* original 633c, guest PC 0x0c0ae71a */
if(!s->budget--) { s->failed_pc=0x0c0ae71au; return 0; }
r[3]=r[3]&255u;
goto P_0c0ae71c;
P_0c0ae71c: /* original 1f31, guest PC 0x0c0ae71c */
if(!s->budget--) { s->failed_pc=0x0c0ae71cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0ae71e;
P_0c0ae71e: /* original d22a, guest PC 0x0c0ae71e */
if(!s->budget--) { s->failed_pc=0x0c0ae71eu; return 0; }
r[2]=read(ram,0x0c0ae7c8u,4);
goto P_0c0ae720;
P_0c0ae720: /* original 6bbc, guest PC 0x0c0ae720 */
if(!s->budget--) { s->failed_pc=0x0c0ae720u; return 0; }
r[11]=r[11]&255u;
goto P_0c0ae722;
P_0c0ae722: /* original 69b3, guest PC 0x0c0ae722 */
if(!s->budget--) { s->failed_pc=0x0c0ae722u; return 0; }
r[9]=r[11];
goto P_0c0ae724;
P_0c0ae724: /* original da27, guest PC 0x0c0ae724 */
if(!s->budget--) { s->failed_pc=0x0c0ae724u; return 0; }
r[10]=read(ram,0x0c0ae7c4u,4);
goto P_0c0ae726;
P_0c0ae726: /* original 4908, guest PC 0x0c0ae726 */
if(!s->budget--) { s->failed_pc=0x0c0ae726u; return 0; }
r[9]<<=2;
goto P_0c0ae728;
P_0c0ae728: /* original 6423, guest PC 0x0c0ae728 */
if(!s->budget--) { s->failed_pc=0x0c0ae728u; return 0; }
r[4]=r[2];
goto P_0c0ae72a;
P_0c0ae72a: /* original 1f22, guest PC 0x0c0ae72a */
if(!s->budget--) { s->failed_pc=0x0c0ae72au; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0ae72c;
P_0c0ae72c: /* original d327, guest PC 0x0c0ae72c */
if(!s->budget--) { s->failed_pc=0x0c0ae72cu; return 0; }
r[3]=read(ram,0x0c0ae7ccu,4);
goto P_0c0ae72e;
P_0c0ae72e: /* original 430b, guest PC 0x0c0ae72e */
if(!s->budget--) { s->failed_pc=0x0c0ae72eu; return 0; }
target=r[3];
r[16]=0x0c0ae732u;
r[4]+=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae732u) { target=s->pc; goto dispatch; }
goto P_0c0ae732;
P_0c0ae730: /* original 7412, guest PC 0x0c0ae730 */
if(!s->budget--) { s->failed_pc=0x0c0ae730u; return 0; }
r[4]+=0x00000012u;
goto P_0c0ae732;
P_0c0ae732: /* original 640c, guest PC 0x0c0ae732 */
if(!s->budget--) { s->failed_pc=0x0c0ae732u; return 0; }
r[4]=r[0]&255u;
goto P_0c0ae734;
P_0c0ae734: /* original 6043, guest PC 0x0c0ae734 */
if(!s->budget--) { s->failed_pc=0x0c0ae734u; return 0; }
r[0]=r[4];
goto P_0c0ae736;
P_0c0ae736: /* original 8803, guest PC 0x0c0ae736 */
if(!s->budget--) { s->failed_pc=0x0c0ae736u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0ae738;
P_0c0ae738: /* original 8b00, guest PC 0x0c0ae738 */
if(!s->budget--) { s->failed_pc=0x0c0ae738u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae73c; }
goto P_0c0ae73a;
P_0c0ae73a: /* original da25, guest PC 0x0c0ae73a */
if(!s->budget--) { s->failed_pc=0x0c0ae73au; return 0; }
r[10]=read(ram,0x0c0ae7d0u,4);
goto P_0c0ae73c;
P_0c0ae73c: /* original 39ac, guest PC 0x0c0ae73c */
if(!s->budget--) { s->failed_pc=0x0c0ae73cu; return 0; }
r[9]+=r[10];
goto P_0c0ae73e;
P_0c0ae73e: /* original 54f1, guest PC 0x0c0ae73e */
if(!s->budget--) { s->failed_pc=0x0c0ae73eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0ae740;
P_0c0ae740: /* original 6592, guest PC 0x0c0ae740 */
if(!s->budget--) { s->failed_pc=0x0c0ae740u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0ae742;
P_0c0ae742: /* original 4408, guest PC 0x0c0ae742 */
if(!s->budget--) { s->failed_pc=0x0c0ae742u; return 0; }
r[4]<<=2;
goto P_0c0ae744;
P_0c0ae744: /* original 6a53, guest PC 0x0c0ae744 */
if(!s->budget--) { s->failed_pc=0x0c0ae744u; return 0; }
r[10]=r[5];
goto P_0c0ae746;
P_0c0ae746: /* original 3a4c, guest PC 0x0c0ae746 */
if(!s->budget--) { s->failed_pc=0x0c0ae746u; return 0; }
r[10]+=r[4];
goto P_0c0ae748;
P_0c0ae748: /* original 6aa2, guest PC 0x0c0ae748 */
if(!s->budget--) { s->failed_pc=0x0c0ae748u; return 0; }
tmp=read(ram,r[10],4);
r[10]=tmp;
goto P_0c0ae74a;
P_0c0ae74a: /* original 2aa8, guest PC 0x0c0ae74a */
if(!s->budget--) { s->failed_pc=0x0c0ae74au; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0ae74c;
P_0c0ae74c: /* original 891f, guest PC 0x0c0ae74c */
if(!s->budget--) { s->failed_pc=0x0c0ae74cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae78e; }
goto P_0c0ae74e;
P_0c0ae74e: /* original d421, guest PC 0x0c0ae74e */
if(!s->budget--) { s->failed_pc=0x0c0ae74eu; return 0; }
r[4]=read(ram,0x0c0ae7d4u,4);
goto P_0c0ae750;
P_0c0ae750: /* original 34bc, guest PC 0x0c0ae750 */
if(!s->budget--) { s->failed_pc=0x0c0ae750u; return 0; }
r[4]+=r[11];
goto P_0c0ae752;
P_0c0ae752: /* original 6440, guest PC 0x0c0ae752 */
if(!s->budget--) { s->failed_pc=0x0c0ae752u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c0ae754;
P_0c0ae754: /* original 644c, guest PC 0x0c0ae754 */
if(!s->budget--) { s->failed_pc=0x0c0ae754u; return 0; }
r[4]=r[4]&255u;
goto P_0c0ae756;
P_0c0ae756: /* original 2448, guest PC 0x0c0ae756 */
if(!s->budget--) { s->failed_pc=0x0c0ae756u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0ae758;
P_0c0ae758: /* original 8916, guest PC 0x0c0ae758 */
if(!s->budget--) { s->failed_pc=0x0c0ae758u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae788; }
goto P_0c0ae75a;
P_0c0ae75a: /* original 902b, guest PC 0x0c0ae75a */
if(!s->budget--) { s->failed_pc=0x0c0ae75au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae7b4u,2);
goto P_0c0ae75c;
P_0c0ae75c: /* original e301, guest PC 0x0c0ae75c */
if(!s->budget--) { s->failed_pc=0x0c0ae75cu; return 0; }
r[3]=0x00000001u;
goto P_0c0ae75e;
P_0c0ae75e: /* original 0e44, guest PC 0x0c0ae75e */
if(!s->budget--) { s->failed_pc=0x0c0ae75eu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0ae760;
P_0c0ae760: /* original 70d4, guest PC 0x0c0ae760 */
if(!s->budget--) { s->failed_pc=0x0c0ae760u; return 0; }
r[0]+=0xffffffd4u;
goto P_0c0ae762;
P_0c0ae762: /* original 05ee, guest PC 0x0c0ae762 */
if(!s->budget--) { s->failed_pc=0x0c0ae762u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0ae764;
P_0c0ae764: /* original e060, guest PC 0x0c0ae764 */
if(!s->budget--) { s->failed_pc=0x0c0ae764u; return 0; }
r[0]=0x00000060u;
goto P_0c0ae766;
P_0c0ae766: /* original 06cc, guest PC 0x0c0ae766 */
if(!s->budget--) { s->failed_pc=0x0c0ae766u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0ae768;
P_0c0ae768: /* original 7040, guest PC 0x0c0ae768 */
if(!s->budget--) { s->failed_pc=0x0c0ae768u; return 0; }
r[0]+=0x00000040u;
goto P_0c0ae76a;
P_0c0ae76a: /* original d41b, guest PC 0x0c0ae76a */
if(!s->budget--) { s->failed_pc=0x0c0ae76au; return 0; }
r[4]=read(ram,0x0c0ae7d8u,4);
goto P_0c0ae76c;
P_0c0ae76c: /* original 666c, guest PC 0x0c0ae76c */
if(!s->budget--) { s->failed_pc=0x0c0ae76cu; return 0; }
r[6]=r[6]&255u;
goto P_0c0ae76e;
P_0c0ae76e: /* original 666b, guest PC 0x0c0ae76e */
if(!s->budget--) { s->failed_pc=0x0c0ae76eu; return 0; }
r[6]=0u-r[6];
goto P_0c0ae770;
P_0c0ae770: /* original 446d, guest PC 0x0c0ae770 */
if(!s->budget--) { s->failed_pc=0x0c0ae770u; return 0; }
r[4]=(r[6]&0x80000000u)?((r[6]&31u)?r[4]>>((-r[6])&31u):0):r[4]<<(r[6]&31u);
goto P_0c0ae772;
P_0c0ae772: /* original 254b, guest PC 0x0c0ae772 */
if(!s->budget--) { s->failed_pc=0x0c0ae772u; return 0; }
r[5]|=r[4];
goto P_0c0ae774;
P_0c0ae774: /* original 0e56, guest PC 0x0c0ae774 */
if(!s->budget--) { s->failed_pc=0x0c0ae774u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c0ae776;
P_0c0ae776: /* original 901e, guest PC 0x0c0ae776 */
if(!s->budget--) { s->failed_pc=0x0c0ae776u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae7b6u,2);
goto P_0c0ae778;
P_0c0ae778: /* original 0e36, guest PC 0x0c0ae778 */
if(!s->budget--) { s->failed_pc=0x0c0ae778u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0ae77a;
P_0c0ae77a: /* original e054, guest PC 0x0c0ae77a */
if(!s->budget--) { s->failed_pc=0x0c0ae77au; return 0; }
r[0]=0x00000054u;
goto P_0c0ae77c;
P_0c0ae77c: /* original 02ce, guest PC 0x0c0ae77c */
if(!s->budget--) { s->failed_pc=0x0c0ae77cu; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0ae77e;
P_0c0ae77e: /* original e022, guest PC 0x0c0ae77e */
if(!s->budget--) { s->failed_pc=0x0c0ae77eu; return 0; }
r[0]=0x00000022u;
goto P_0c0ae780;
P_0c0ae780: /* original 032d, guest PC 0x0c0ae780 */
if(!s->budget--) { s->failed_pc=0x0c0ae780u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c0ae782;
P_0c0ae782: /* original 9019, guest PC 0x0c0ae782 */
if(!s->budget--) { s->failed_pc=0x0c0ae782u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae7b8u,2);
goto P_0c0ae784;
P_0c0ae784: /* original 7308, guest PC 0x0c0ae784 */
if(!s->budget--) { s->failed_pc=0x0c0ae784u; return 0; }
r[3]+=0x00000008u;
goto P_0c0ae786;
P_0c0ae786: /* original 0c35, guest PC 0x0c0ae786 */
if(!s->budget--) { s->failed_pc=0x0c0ae786u; return 0; }
write(ram,r[12]+r[0],r[3],2);
goto P_0c0ae788;
P_0c0ae788: /* original d314, guest PC 0x0c0ae788 */
if(!s->budget--) { s->failed_pc=0x0c0ae788u; return 0; }
r[3]=read(ram,0x0c0ae7dcu,4);
goto P_0c0ae78a;
P_0c0ae78a: /* original 430b, guest PC 0x0c0ae78a */
if(!s->budget--) { s->failed_pc=0x0c0ae78au; return 0; }
target=r[3];
r[16]=0x0c0ae78eu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae78eu) { target=s->pc; goto dispatch; }
goto P_0c0ae78e;
P_0c0ae78c: /* original 64a3, guest PC 0x0c0ae78c */
if(!s->budget--) { s->failed_pc=0x0c0ae78cu; return 0; }
r[4]=r[10];
goto P_0c0ae78e;
P_0c0ae78e: /* original 52d2, guest PC 0x0c0ae78e */
if(!s->budget--) { s->failed_pc=0x0c0ae78eu; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0ae790;
P_0c0ae790: /* original 64c3, guest PC 0x0c0ae790 */
if(!s->budget--) { s->failed_pc=0x0c0ae790u; return 0; }
r[4]=r[12];
goto P_0c0ae792;
P_0c0ae792: /* original 66d3, guest PC 0x0c0ae792 */
if(!s->budget--) { s->failed_pc=0x0c0ae792u; return 0; }
r[6]=r[13];
goto P_0c0ae794;
P_0c0ae794: /* original 7204, guest PC 0x0c0ae794 */
if(!s->budget--) { s->failed_pc=0x0c0ae794u; return 0; }
r[2]+=0x00000004u;
goto P_0c0ae796;
P_0c0ae796: /* original 1d22, guest PC 0x0c0ae796 */
if(!s->budget--) { s->failed_pc=0x0c0ae796u; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c0ae798;
P_0c0ae798: /* original 65f2, guest PC 0x0c0ae798 */
if(!s->budget--) { s->failed_pc=0x0c0ae798u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ae79a;
P_0c0ae79a: /* original 7f0c, guest PC 0x0c0ae79a */
if(!s->budget--) { s->failed_pc=0x0c0ae79au; return 0; }
r[15]+=0x0000000cu;
goto P_0c0ae79c;
P_0c0ae79c: /* original 4f26, guest PC 0x0c0ae79c */
if(!s->budget--) { s->failed_pc=0x0c0ae79cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ae79e;
P_0c0ae79e: /* original 69f6, guest PC 0x0c0ae79e */
if(!s->budget--) { s->failed_pc=0x0c0ae79eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0ae7a0;
P_0c0ae7a0: /* original 6af6, guest PC 0x0c0ae7a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae7a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ae7a2;
P_0c0ae7a2: /* original 6bf6, guest PC 0x0c0ae7a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae7a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ae7a4;
P_0c0ae7a4: /* original 6cf6, guest PC 0x0c0ae7a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae7a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ae7a6;
P_0c0ae7a6: /* original 6df6, guest PC 0x0c0ae7a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae7a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ae7a8;
P_0c0ae7a8: /* original ad78, guest PC 0x0c0ae7a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae7a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ae29c;
P_0c0ae7aa: /* original 6ef6, guest PC 0x0c0ae7aa */
if(!s->budget--) { s->failed_pc=0x0c0ae7aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ae7acu,s,ram);
P_0c0b1b7c: /* original 2fe6, guest PC 0x0c0b1b7c */
if(!s->budget--) { s->failed_pc=0x0c0b1b7cu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0b1b7e;
P_0c0b1b7e: /* original 6e43, guest PC 0x0c0b1b7e */
if(!s->budget--) { s->failed_pc=0x0c0b1b7eu; return 0; }
r[14]=r[4];
goto P_0c0b1b80;
P_0c0b1b80: /* original 2fd6, guest PC 0x0c0b1b80 */
if(!s->budget--) { s->failed_pc=0x0c0b1b80u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0b1b82;
P_0c0b1b82: /* original e060, guest PC 0x0c0b1b82 */
if(!s->budget--) { s->failed_pc=0x0c0b1b82u; return 0; }
r[0]=0x00000060u;
goto P_0c0b1b84;
P_0c0b1b84: /* original 2fc6, guest PC 0x0c0b1b84 */
if(!s->budget--) { s->failed_pc=0x0c0b1b84u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0b1b86;
P_0c0b1b86: /* original 2fb6, guest PC 0x0c0b1b86 */
if(!s->budget--) { s->failed_pc=0x0c0b1b86u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0b1b88;
P_0c0b1b88: /* original 2fa6, guest PC 0x0c0b1b88 */
if(!s->budget--) { s->failed_pc=0x0c0b1b88u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
return vf3_matrix_family(0x0c0b1b8au,s,ram);
P_0c0b1c92: /* original 2fe6, guest PC 0x0c0b1c92 */
if(!s->budget--) { s->failed_pc=0x0c0b1c92u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0b1c94;
P_0c0b1c94: /* original 4f22, guest PC 0x0c0b1c94 */
if(!s->budget--) { s->failed_pc=0x0c0b1c94u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b1c96;
P_0c0b1c96: /* original 7fbc, guest PC 0x0c0b1c96 */
if(!s->budget--) { s->failed_pc=0x0c0b1c96u; return 0; }
r[15]+=0xffffffbcu;
goto P_0c0b1c98;
P_0c0b1c98: /* original 2f42, guest PC 0x0c0b1c98 */
if(!s->budget--) { s->failed_pc=0x0c0b1c98u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0b1c9a;
P_0c0b1c9a: /* original 9029, guest PC 0x0c0b1c9a */
if(!s->budget--) { s->failed_pc=0x0c0b1c9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1cf0u,2);
goto P_0c0b1c9c;
P_0c0b1c9c: /* original d31d, guest PC 0x0c0b1c9c */
if(!s->budget--) { s->failed_pc=0x0c0b1c9cu; return 0; }
r[3]=read(ram,0x0c0b1d14u,4);
goto P_0c0b1c9e;
P_0c0b1c9e: /* original 044d, guest PC 0x0c0b1c9e */
if(!s->budget--) { s->failed_pc=0x0c0b1c9eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0b1ca0;
P_0c0b1ca0: /* original 6e4d, guest PC 0x0c0b1ca0 */
if(!s->budget--) { s->failed_pc=0x0c0b1ca0u; return 0; }
r[14]=r[4]&65535u;
goto P_0c0b1ca2;
P_0c0b1ca2: /* original 3e30, guest PC 0x0c0b1ca2 */
if(!s->budget--) { s->failed_pc=0x0c0b1ca2u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c0b1ca4;
P_0c0b1ca4: /* original 890a, guest PC 0x0c0b1ca4 */
if(!s->budget--) { s->failed_pc=0x0c0b1ca4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1cbc; }
goto P_0c0b1ca6;
P_0c0b1ca6: /* original d214, guest PC 0x0c0b1ca6 */
if(!s->budget--) { s->failed_pc=0x0c0b1ca6u; return 0; }
r[2]=read(ram,0x0c0b1cf8u,4);
goto P_0c0b1ca8;
P_0c0b1ca8: /* original 9323, guest PC 0x0c0b1ca8 */
if(!s->budget--) { s->failed_pc=0x0c0b1ca8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1cf2u,2);
goto P_0c0b1caa;
P_0c0b1caa: /* original 64f2, guest PC 0x0c0b1caa */
if(!s->budget--) { s->failed_pc=0x0c0b1caau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0b1cac;
P_0c0b1cac: /* original 420b, guest PC 0x0c0b1cac */
if(!s->budget--) { s->failed_pc=0x0c0b1cacu; return 0; }
target=r[2];
r[16]=0x0c0b1cb0u;
r[4]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0b1cb0u) { target=s->pc; goto dispatch; }
goto P_0c0b1cb0;
P_0c0b1cae: /* original 343c, guest PC 0x0c0b1cae */
if(!s->budget--) { s->failed_pc=0x0c0b1caeu; return 0; }
r[4]+=r[3];
goto P_0c0b1cb0;
P_0c0b1cb0: /* original 7f44, guest PC 0x0c0b1cb0 */
if(!s->budget--) { s->failed_pc=0x0c0b1cb0u; return 0; }
r[15]+=0x00000044u;
goto P_0c0b1cb2;
P_0c0b1cb2: /* original d317, guest PC 0x0c0b1cb2 */
if(!s->budget--) { s->failed_pc=0x0c0b1cb2u; return 0; }
r[3]=read(ram,0x0c0b1d10u,4);
goto P_0c0b1cb4;
P_0c0b1cb4: /* original 4f26, guest PC 0x0c0b1cb4 */
if(!s->budget--) { s->failed_pc=0x0c0b1cb4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b1cb6;
P_0c0b1cb6: /* original 64e3, guest PC 0x0c0b1cb6 */
if(!s->budget--) { s->failed_pc=0x0c0b1cb6u; return 0; }
r[4]=r[14];
goto P_0c0b1cb8;
P_0c0b1cb8: /* original 432b, guest PC 0x0c0b1cb8 */
if(!s->budget--) { s->failed_pc=0x0c0b1cb8u; return 0; }
target=r[3];
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
P_0c0b1cba: /* original 6ef6, guest PC 0x0c0b1cba */
if(!s->budget--) { s->failed_pc=0x0c0b1cbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0b1cbc;
P_0c0b1cbc: /* original 7f44, guest PC 0x0c0b1cbc */
if(!s->budget--) { s->failed_pc=0x0c0b1cbcu; return 0; }
r[15]+=0x00000044u;
goto P_0c0b1cbe;
P_0c0b1cbe: /* original 4f26, guest PC 0x0c0b1cbe */
if(!s->budget--) { s->failed_pc=0x0c0b1cbeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b1cc0;
P_0c0b1cc0: /* original 000b, guest PC 0x0c0b1cc0 */
if(!s->budget--) { s->failed_pc=0x0c0b1cc0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b1cc2: /* original 6ef6, guest PC 0x0c0b1cc2 */
if(!s->budget--) { s->failed_pc=0x0c0b1cc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0b1cc4u,s,ram);
P_0c0c11f4: /* original 7ff4, guest PC 0x0c0c11f4 */
if(!s->budget--) { s->failed_pc=0x0c0c11f4u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c11f6;
P_0c0c11f6: /* original 6763, guest PC 0x0c0c11f6 */
if(!s->budget--) { s->failed_pc=0x0c0c11f6u; return 0; }
r[7]=r[6];
goto P_0c0c11f8;
P_0c0c11f8: /* original 1f41, guest PC 0x0c0c11f8 */
if(!s->budget--) { s->failed_pc=0x0c0c11f8u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0c11fa;
P_0c0c11fa: /* original 2f52, guest PC 0x0c0c11fa */
if(!s->budget--) { s->failed_pc=0x0c0c11fau; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c11fc;
P_0c0c11fc: /* original 1f62, guest PC 0x0c0c11fc */
if(!s->budget--) { s->failed_pc=0x0c0c11fcu; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c0c11fe;
P_0c0c11fe: /* original 55f1, guest PC 0x0c0c11fe */
if(!s->budget--) { s->failed_pc=0x0c0c11feu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0c1200;
P_0c0c1200: /* original 66f2, guest PC 0x0c0c1200 */
if(!s->budget--) { s->failed_pc=0x0c0c1200u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c0c1202;
P_0c0c1202: /* original d438, guest PC 0x0c0c1202 */
if(!s->budget--) { s->failed_pc=0x0c0c1202u; return 0; }
r[4]=read(ram,0x0c0c12e4u,4);
goto P_0c0c1204;
P_0c0c1204: /* original a2a6, guest PC 0x0c0c1204 */
if(!s->budget--) { s->failed_pc=0x0c0c1204u; return 0; }
r[15]+=0x0000000cu;
return vf3_matrix_family(0x0c0c1754u,s,ram);
P_0c0c1206: /* original 7f0c, guest PC 0x0c0c1206 */
if(!s->budget--) { s->failed_pc=0x0c0c1206u; return 0; }
r[15]+=0x0000000cu;
return vf3_matrix_family(0x0c0c1208u,s,ram);
P_0c0c13de: /* original 4f22, guest PC 0x0c0c13de */
if(!s->budget--) { s->failed_pc=0x0c0c13deu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c13e0;
P_0c0c13e0: /* original 7fb8, guest PC 0x0c0c13e0 */
if(!s->budget--) { s->failed_pc=0x0c0c13e0u; return 0; }
r[15]+=0xffffffb8u;
goto P_0c0c13e2;
P_0c0c13e2: /* original 2f42, guest PC 0x0c0c13e2 */
if(!s->budget--) { s->failed_pc=0x0c0c13e2u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c13e4;
P_0c0c13e4: /* original e43f, guest PC 0x0c0c13e4 */
if(!s->budget--) { s->failed_pc=0x0c0c13e4u; return 0; }
r[4]=0x0000003fu;
goto P_0c0c13e6;
P_0c0c13e6: /* original 2349, guest PC 0x0c0c13e6 */
if(!s->budget--) { s->failed_pc=0x0c0c13e6u; return 0; }
r[3]&=r[4];
goto P_0c0c13e8;
P_0c0c13e8: /* original fd08, guest PC 0x0c0c13e8 */
if(!s->budget--) { s->failed_pc=0x0c0c13e8u; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c0c13ea;
P_0c0c13ea: /* original 435a, guest PC 0x0c0c13ea */
if(!s->budget--) { s->failed_pc=0x0c0c13eau; return 0; }
r[53]=r[3];
goto P_0c0c13ec;
P_0c0c13ec: /* original 4311, guest PC 0x0c0c13ec */
if(!s->budget--) { s->failed_pc=0x0c0c13ecu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0c13ee;
P_0c0c13ee: /* original 8d04, guest PC 0x0c0c13ee */
if(!s->budget--) { s->failed_pc=0x0c0c13eeu; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c13fa; }
goto P_0c0c13f2;
P_0c0c13f0: /* original f32d, guest PC 0x0c0c13f0 */
if(!s->budget--) { s->failed_pc=0x0c0c13f0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c13f2;
P_0c0c13f2: /* original d228, guest PC 0x0c0c13f2 */
if(!s->budget--) { s->failed_pc=0x0c0c13f2u; return 0; }
r[2]=read(ram,0x0c0c1494u,4);
goto P_0c0c13f4;
P_0c0c13f4: /* original 425a, guest PC 0x0c0c13f4 */
if(!s->budget--) { s->failed_pc=0x0c0c13f4u; return 0; }
r[53]=r[2];
goto P_0c0c13f6;
P_0c0c13f6: /* original f20d, guest PC 0x0c0c13f6 */
if(!s->budget--) { s->failed_pc=0x0c0c13f6u; return 0; }
fr[2]=r[53];
goto P_0c0c13f8;
P_0c0c13f8: /* original f320, guest PC 0x0c0c13f8 */
if(!s->budget--) { s->failed_pc=0x0c0c13f8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c13fa;
P_0c0c13fa: /* original 63c3, guest PC 0x0c0c13fa */
if(!s->budget--) { s->failed_pc=0x0c0c13fau; return 0; }
r[3]=r[12];
goto P_0c0c13fc;
P_0c0c13fc: /* original e2f9, guest PC 0x0c0c13fc */
if(!s->budget--) { s->failed_pc=0x0c0c13fcu; return 0; }
r[2]=0xfffffff9u;
goto P_0c0c13fe;
P_0c0c13fe: /* original f3d2, guest PC 0x0c0c13fe */
if(!s->budget--) { s->failed_pc=0x0c0c13feu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[13],r[18],'*');
goto P_0c0c1400;
P_0c0c1400: /* original 432d, guest PC 0x0c0c1400 */
if(!s->budget--) { s->failed_pc=0x0c0c1400u; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?r[3]>>((-r[2])&31u):0):r[3]<<(r[2]&31u);
goto P_0c0c1402;
P_0c0c1402: /* original 2349, guest PC 0x0c0c1402 */
if(!s->budget--) { s->failed_pc=0x0c0c1402u; return 0; }
r[3]&=r[4];
goto P_0c0c1404;
P_0c0c1404: /* original e010, guest PC 0x0c0c1404 */
if(!s->budget--) { s->failed_pc=0x0c0c1404u; return 0; }
r[0]=0x00000010u;
goto P_0c0c1406;
P_0c0c1406: /* original 4311, guest PC 0x0c0c1406 */
if(!s->budget--) { s->failed_pc=0x0c0c1406u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0c1408;
P_0c0c1408: /* original ff37, guest PC 0x0c0c1408 */
if(!s->budget--) { s->failed_pc=0x0c0c1408u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c140a;
P_0c0c140a: /* original 435a, guest PC 0x0c0c140a */
if(!s->budget--) { s->failed_pc=0x0c0c140au; return 0; }
r[53]=r[3];
goto P_0c0c140c;
P_0c0c140c: /* original 8d04, guest PC 0x0c0c140c */
if(!s->budget--) { s->failed_pc=0x0c0c140cu; return 0; }
cond=r[17]&1u;
fr[2]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c1418; }
goto P_0c0c1410;
P_0c0c140e: /* original f22d, guest PC 0x0c0c140e */
if(!s->budget--) { s->failed_pc=0x0c0c140eu; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c1410;
P_0c0c1410: /* original d120, guest PC 0x0c0c1410 */
if(!s->budget--) { s->failed_pc=0x0c0c1410u; return 0; }
r[1]=read(ram,0x0c0c1494u,4);
goto P_0c0c1412;
P_0c0c1412: /* original 415a, guest PC 0x0c0c1412 */
if(!s->budget--) { s->failed_pc=0x0c0c1412u; return 0; }
r[53]=r[1];
goto P_0c0c1414;
P_0c0c1414: /* original f10d, guest PC 0x0c0c1414 */
if(!s->budget--) { s->failed_pc=0x0c0c1414u; return 0; }
fr[1]=r[53];
goto P_0c0c1416;
P_0c0c1416: /* original f210, guest PC 0x0c0c1416 */
if(!s->budget--) { s->failed_pc=0x0c0c1416u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[1],r[18],'+');
goto P_0c0c1418;
P_0c0c1418: /* original f2d2, guest PC 0x0c0c1418 */
if(!s->budget--) { s->failed_pc=0x0c0c1418u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[13],r[18],'*');
goto P_0c0c141a;
P_0c0c141a: /* original e004, guest PC 0x0c0c141a */
if(!s->budget--) { s->failed_pc=0x0c0c141au; return 0; }
r[0]=0x00000004u;
goto P_0c0c141c;
P_0c0c141c: /* original ff27, guest PC 0x0c0c141c */
if(!s->budget--) { s->failed_pc=0x0c0c141cu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c141e;
P_0c0c141e: /* original d31e, guest PC 0x0c0c141e */
if(!s->budget--) { s->failed_pc=0x0c0c141eu; return 0; }
r[3]=read(ram,0x0c0c1498u,4);
goto P_0c0c1420;
P_0c0c1420: /* original 430b, guest PC 0x0c0c1420 */
if(!s->budget--) { s->failed_pc=0x0c0c1420u; return 0; }
target=r[3];
r[16]=0x0c0c1424u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1424u) { target=s->pc; goto dispatch; }
goto P_0c0c1424;
P_0c0c1422: /* original 64b3, guest PC 0x0c0c1422 */
if(!s->budget--) { s->failed_pc=0x0c0c1422u; return 0; }
r[4]=r[11];
goto P_0c0c1424;
P_0c0c1424: /* original 6d03, guest PC 0x0c0c1424 */
if(!s->budget--) { s->failed_pc=0x0c0c1424u; return 0; }
r[13]=r[0];
goto P_0c0c1426;
P_0c0c1426: /* original c71d, guest PC 0x0c0c1426 */
if(!s->budget--) { s->failed_pc=0x0c0c1426u; return 0; }
r[0]=0x0c0c149cu;
goto P_0c0c1428;
P_0c0c1428: /* original f408, guest PC 0x0c0c1428 */
if(!s->budget--) { s->failed_pc=0x0c0c1428u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c142a;
P_0c0c142a: /* original 60b3, guest PC 0x0c0c142a */
if(!s->budget--) { s->failed_pc=0x0c0c142au; return 0; }
r[0]=r[11];
goto P_0c0c142c;
P_0c0c142c: /* original 8800, guest PC 0x0c0c142c */
if(!s->budget--) { s->failed_pc=0x0c0c142cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0c142e;
P_0c0c142e: /* original 890c, guest PC 0x0c0c142e */
if(!s->budget--) { s->failed_pc=0x0c0c142eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c144a; }
goto P_0c0c1430;
P_0c0c1430: /* original 8853, guest PC 0x0c0c1430 */
if(!s->budget--) { s->failed_pc=0x0c0c1430u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000053u)!=0);
goto P_0c0c1432;
P_0c0c1432: /* original 8918, guest PC 0x0c0c1432 */
if(!s->budget--) { s->failed_pc=0x0c0c1432u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1466; }
goto P_0c0c1434;
P_0c0c1434: /* original 9129, guest PC 0x0c0c1434 */
if(!s->budget--) { s->failed_pc=0x0c0c1434u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c148au,2);
goto P_0c0c1436;
P_0c0c1436: /* original 3010, guest PC 0x0c0c1436 */
if(!s->budget--) { s->failed_pc=0x0c0c1436u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0c1438;
P_0c0c1438: /* original 8904, guest PC 0x0c0c1438 */
if(!s->budget--) { s->failed_pc=0x0c0c1438u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1444; }
goto P_0c0c143a;
P_0c0c143a: /* original 9127, guest PC 0x0c0c143a */
if(!s->budget--) { s->failed_pc=0x0c0c143au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c148cu,2);
goto P_0c0c143c;
P_0c0c143c: /* original 3010, guest PC 0x0c0c143c */
if(!s->budget--) { s->failed_pc=0x0c0c143cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0c143e;
P_0c0c143e: /* original 8908, guest PC 0x0c0c143e */
if(!s->budget--) { s->failed_pc=0x0c0c143eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1452; }
goto P_0c0c1440;
P_0c0c1440: /* original a01b, guest PC 0x0c0c1440 */
if(!s->budget--) { s->failed_pc=0x0c0c1440u; return 0; }
goto P_0c0c147a;
P_0c0c1442: /* original 0009, guest PC 0x0c0c1442 */
if(!s->budget--) { s->failed_pc=0x0c0c1442u; return 0; }
goto P_0c0c1444;
P_0c0c1444: /* original fedc, guest PC 0x0c0c1444 */
if(!s->budget--) { s->failed_pc=0x0c0c1444u; return 0; }
vf3_matrix_move(s,14,13);
goto P_0c0c1446;
P_0c0c1446: /* original a002, guest PC 0x0c0c1446 */
if(!s->budget--) { s->failed_pc=0x0c0c1446u; return 0; }
vf3_matrix_move(s,15,13);
goto P_0c0c144e;
P_0c0c1448: /* original ffdc, guest PC 0x0c0c1448 */
if(!s->budget--) { s->failed_pc=0x0c0c1448u; return 0; }
vf3_matrix_move(s,15,13);
goto P_0c0c144a;
P_0c0c144a: /* original ff4c, guest PC 0x0c0c144a */
if(!s->budget--) { s->failed_pc=0x0c0c144au; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c0c144c;
P_0c0c144c: /* original fedc, guest PC 0x0c0c144c */
if(!s->budget--) { s->failed_pc=0x0c0c144cu; return 0; }
vf3_matrix_move(s,14,13);
goto P_0c0c144e;
P_0c0c144e: /* original a029, guest PC 0x0c0c144e */
if(!s->budget--) { s->failed_pc=0x0c0c144eu; return 0; }
r[12]+=0x00000002u;
goto P_0c0c14a4;
P_0c0c1450: /* original 7c02, guest PC 0x0c0c1450 */
if(!s->budget--) { s->failed_pc=0x0c0c1450u; return 0; }
r[12]+=0x00000002u;
goto P_0c0c1452;
P_0c0c1452: /* original e261, guest PC 0x0c0c1452 */
if(!s->budget--) { s->failed_pc=0x0c0c1452u; return 0; }
r[2]=0x00000061u;
goto P_0c0c1454;
P_0c0c1454: /* original 3e22, guest PC 0x0c0c1454 */
if(!s->budget--) { s->failed_pc=0x0c0c1454u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[2])!=0);
goto P_0c0c1456;
P_0c0c1456: /* original 8b00, guest PC 0x0c0c1456 */
if(!s->budget--) { s->failed_pc=0x0c0c1456u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c145a; }
goto P_0c0c1458;
P_0c0c1458: /* original 7ee0, guest PC 0x0c0c1458 */
if(!s->budget--) { s->failed_pc=0x0c0c1458u; return 0; }
r[14]+=0xffffffe0u;
goto P_0c0c145a;
P_0c0c145a: /* original c711, guest PC 0x0c0c145a */
if(!s->budget--) { s->failed_pc=0x0c0c145au; return 0; }
r[0]=0x0c0c14a0u;
goto P_0c0c145c;
P_0c0c145c: /* original fe4c, guest PC 0x0c0c145c */
if(!s->budget--) { s->failed_pc=0x0c0c145cu; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c0c145e;
P_0c0c145e: /* original ff08, guest PC 0x0c0c145e */
if(!s->budget--) { s->failed_pc=0x0c0c145eu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0c1460;
P_0c0c1460: /* original 7ee0, guest PC 0x0c0c1460 */
if(!s->budget--) { s->failed_pc=0x0c0c1460u; return 0; }
r[14]+=0xffffffe0u;
goto P_0c0c1462;
P_0c0c1462: /* original a01f, guest PC 0x0c0c1462 */
if(!s->budget--) { s->failed_pc=0x0c0c1462u; return 0; }
r[12]+=0x00000004u;
goto P_0c0c14a4;
P_0c0c1464: /* original 7c04, guest PC 0x0c0c1464 */
if(!s->budget--) { s->failed_pc=0x0c0c1464u; return 0; }
r[12]+=0x00000004u;
goto P_0c0c1466;
P_0c0c1466: /* original 60e3, guest PC 0x0c0c1466 */
if(!s->budget--) { s->failed_pc=0x0c0c1466u; return 0; }
r[0]=r[14];
goto P_0c0c1468;
P_0c0c1468: /* original 8820, guest PC 0x0c0c1468 */
if(!s->budget--) { s->failed_pc=0x0c0c1468u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c0c146a;
P_0c0c146a: /* original fe4c, guest PC 0x0c0c146a */
if(!s->budget--) { s->failed_pc=0x0c0c146au; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c0c146c;
P_0c0c146c: /* original ff4c, guest PC 0x0c0c146c */
if(!s->budget--) { s->failed_pc=0x0c0c146cu; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c0c146e;
P_0c0c146e: /* original 8f02, guest PC 0x0c0c146e */
if(!s->budget--) { s->failed_pc=0x0c0c146eu; return 0; }
cond=r[17]&1u;
r[12]+=0x00000004u;
if(!cond) { goto P_0c0c1476; }
goto P_0c0c1472;
P_0c0c1470: /* original 7c04, guest PC 0x0c0c1470 */
if(!s->budget--) { s->failed_pc=0x0c0c1470u; return 0; }
r[12]+=0x00000004u;
goto P_0c0c1472;
P_0c0c1472: /* original a095, guest PC 0x0c0c1472 */
if(!s->budget--) { s->failed_pc=0x0c0c1472u; return 0; }
goto P_0c0c15a0;
P_0c0c1474: /* original 0009, guest PC 0x0c0c1474 */
if(!s->budget--) { s->failed_pc=0x0c0c1474u; return 0; }
goto P_0c0c1476;
P_0c0c1476: /* original a018, guest PC 0x0c0c1476 */
if(!s->budget--) { s->failed_pc=0x0c0c1476u; return 0; }
r[14]+=0xfffffff0u;
goto P_0c0c14aa;
P_0c0c1478: /* original 7ef0, guest PC 0x0c0c1478 */
if(!s->budget--) { s->failed_pc=0x0c0c1478u; return 0; }
r[14]+=0xfffffff0u;
goto P_0c0c147a;
P_0c0c147a: /* original 7ed0, guest PC 0x0c0c147a */
if(!s->budget--) { s->failed_pc=0x0c0c147au; return 0; }
r[14]+=0xffffffd0u;
goto P_0c0c147c;
P_0c0c147c: /* original 65c3, guest PC 0x0c0c147c */
if(!s->budget--) { s->failed_pc=0x0c0c147cu; return 0; }
r[5]=r[12];
goto P_0c0c147e;
P_0c0c147e: /* original 66e3, guest PC 0x0c0c147e */
if(!s->budget--) { s->failed_pc=0x0c0c147eu; return 0; }
r[6]=r[14];
goto P_0c0c1480;
P_0c0c1480: /* original 67b3, guest PC 0x0c0c1480 */
if(!s->budget--) { s->failed_pc=0x0c0c1480u; return 0; }
r[7]=r[11];
goto P_0c0c1482;
P_0c0c1482: /* original b0b1, guest PC 0x0c0c1482 */
if(!s->budget--) { s->failed_pc=0x0c0c1482u; return 0; }
target=0x0c0c15e8u; r[16]=0x0c0c1486u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1486u) { target=s->pc; goto dispatch; }
goto P_0c0c1486;
P_0c0c1484: /* original 64f2, guest PC 0x0c0c1484 */
if(!s->budget--) { s->failed_pc=0x0c0c1484u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c1486;
P_0c0c1486: /* original a08c, guest PC 0x0c0c1486 */
if(!s->budget--) { s->failed_pc=0x0c0c1486u; return 0; }
goto P_0c0c15a2;
P_0c0c1488: /* original 0009, guest PC 0x0c0c1488 */
if(!s->budget--) { s->failed_pc=0x0c0c1488u; return 0; }
return vf3_matrix_family(0x0c0c148au,s,ram);
P_0c0c14a4: /* original 60e3, guest PC 0x0c0c14a4 */
if(!s->budget--) { s->failed_pc=0x0c0c14a4u; return 0; }
r[0]=r[14];
goto P_0c0c14a6;
P_0c0c14a6: /* original 8820, guest PC 0x0c0c14a6 */
if(!s->budget--) { s->failed_pc=0x0c0c14a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c0c14a8;
P_0c0c14a8: /* original 897a, guest PC 0x0c0c14a8 */
if(!s->budget--) { s->failed_pc=0x0c0c14a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c15a0; }
goto P_0c0c14aa;
P_0c0c14aa: /* original e30f, guest PC 0x0c0c14aa */
if(!s->budget--) { s->failed_pc=0x0c0c14aau; return 0; }
r[3]=0x0000000fu;
goto P_0c0c14ac;
P_0c0c14ac: /* original 23e9, guest PC 0x0c0c14ac */
if(!s->budget--) { s->failed_pc=0x0c0c14acu; return 0; }
r[3]&=r[14];
goto P_0c0c14ae;
P_0c0c14ae: /* original 435a, guest PC 0x0c0c14ae */
if(!s->budget--) { s->failed_pc=0x0c0c14aeu; return 0; }
r[53]=r[3];
goto P_0c0c14b0;
P_0c0c14b0: /* original 4311, guest PC 0x0c0c14b0 */
if(!s->budget--) { s->failed_pc=0x0c0c14b0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0c14b2;
P_0c0c14b2: /* original 8d04, guest PC 0x0c0c14b2 */
if(!s->budget--) { s->failed_pc=0x0c0c14b2u; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c14be; }
goto P_0c0c14b6;
P_0c0c14b4: /* original f32d, guest PC 0x0c0c14b4 */
if(!s->budget--) { s->failed_pc=0x0c0c14b4u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c14b6;
P_0c0c14b6: /* original d242, guest PC 0x0c0c14b6 */
if(!s->budget--) { s->failed_pc=0x0c0c14b6u; return 0; }
r[2]=read(ram,0x0c0c15c0u,4);
goto P_0c0c14b8;
P_0c0c14b8: /* original 425a, guest PC 0x0c0c14b8 */
if(!s->budget--) { s->failed_pc=0x0c0c14b8u; return 0; }
r[53]=r[2];
goto P_0c0c14ba;
P_0c0c14ba: /* original f20d, guest PC 0x0c0c14ba */
if(!s->budget--) { s->failed_pc=0x0c0c14bau; return 0; }
fr[2]=r[53];
goto P_0c0c14bc;
P_0c0c14bc: /* original f320, guest PC 0x0c0c14bc */
if(!s->budget--) { s->failed_pc=0x0c0c14bcu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c14be;
P_0c0c14be: /* original f1d8, guest PC 0x0c0c14be */
if(!s->budget--) { s->failed_pc=0x0c0c14beu; return 0; }
vf3_matrix_load(s,ram,1,r[13]);
goto P_0c0c14c0;
P_0c0c14c0: /* original e008, guest PC 0x0c0c14c0 */
if(!s->budget--) { s->failed_pc=0x0c0c14c0u; return 0; }
r[0]=0x00000008u;
goto P_0c0c14c2;
P_0c0c14c2: /* original f0ec, guest PC 0x0c0c14c2 */
if(!s->budget--) { s->failed_pc=0x0c0c14c2u; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c0c14c4;
P_0c0c14c4: /* original f13e, guest PC 0x0c0c14c4 */
if(!s->budget--) { s->failed_pc=0x0c0c14c4u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[3],fr[1],r[18]);
goto P_0c0c14c6;
P_0c0c14c6: /* original ff17, guest PC 0x0c0c14c6 */
if(!s->budget--) { s->failed_pc=0x0c0c14c6u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c14c8;
P_0c0c14c8: /* original 9375, guest PC 0x0c0c14c8 */
if(!s->budget--) { s->failed_pc=0x0c0c14c8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c15b6u,2);
goto P_0c0c14ca;
P_0c0c14ca: /* original 2e39, guest PC 0x0c0c14ca */
if(!s->budget--) { s->failed_pc=0x0c0c14cau; return 0; }
r[14]&=r[3];
goto P_0c0c14cc;
P_0c0c14cc: /* original 4e09, guest PC 0x0c0c14cc */
if(!s->budget--) { s->failed_pc=0x0c0c14ccu; return 0; }
r[14]>>=2;
goto P_0c0c14ce;
P_0c0c14ce: /* original 4e09, guest PC 0x0c0c14ce */
if(!s->budget--) { s->failed_pc=0x0c0c14ceu; return 0; }
r[14]>>=2;
goto P_0c0c14d0;
P_0c0c14d0: /* original 4e5a, guest PC 0x0c0c14d0 */
if(!s->budget--) { s->failed_pc=0x0c0c14d0u; return 0; }
r[53]=r[14];
goto P_0c0c14d2;
P_0c0c14d2: /* original 4e11, guest PC 0x0c0c14d2 */
if(!s->budget--) { s->failed_pc=0x0c0c14d2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0c14d4;
P_0c0c14d4: /* original 8d04, guest PC 0x0c0c14d4 */
if(!s->budget--) { s->failed_pc=0x0c0c14d4u; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c14e0; }
goto P_0c0c14d8;
P_0c0c14d6: /* original f32d, guest PC 0x0c0c14d6 */
if(!s->budget--) { s->failed_pc=0x0c0c14d6u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c14d8;
P_0c0c14d8: /* original d239, guest PC 0x0c0c14d8 */
if(!s->budget--) { s->failed_pc=0x0c0c14d8u; return 0; }
r[2]=read(ram,0x0c0c15c0u,4);
goto P_0c0c14da;
P_0c0c14da: /* original 425a, guest PC 0x0c0c14da */
if(!s->budget--) { s->failed_pc=0x0c0c14dau; return 0; }
r[53]=r[2];
goto P_0c0c14dc;
P_0c0c14dc: /* original f20d, guest PC 0x0c0c14dc */
if(!s->budget--) { s->failed_pc=0x0c0c14dcu; return 0; }
fr[2]=r[53];
goto P_0c0c14de;
P_0c0c14de: /* original f320, guest PC 0x0c0c14de */
if(!s->budget--) { s->failed_pc=0x0c0c14deu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c14e0;
P_0c0c14e0: /* original e004, guest PC 0x0c0c14e0 */
if(!s->budget--) { s->failed_pc=0x0c0c14e0u; return 0; }
r[0]=0x00000004u;
goto P_0c0c14e2;
P_0c0c14e2: /* original f0fc, guest PC 0x0c0c14e2 */
if(!s->budget--) { s->failed_pc=0x0c0c14e2u; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c0c14e4;
P_0c0c14e4: /* original f1d6, guest PC 0x0c0c14e4 */
if(!s->budget--) { s->failed_pc=0x0c0c14e4u; return 0; }
vf3_matrix_load(s,ram,1,r[13]+r[0]);
goto P_0c0c14e6;
P_0c0c14e6: /* original e00c, guest PC 0x0c0c14e6 */
if(!s->budget--) { s->failed_pc=0x0c0c14e6u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c14e8;
P_0c0c14e8: /* original 64f3, guest PC 0x0c0c14e8 */
if(!s->budget--) { s->failed_pc=0x0c0c14e8u; return 0; }
r[4]=r[15];
goto P_0c0c14ea;
P_0c0c14ea: /* original f13e, guest PC 0x0c0c14ea */
if(!s->budget--) { s->failed_pc=0x0c0c14eau; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[3],fr[1],r[18]);
goto P_0c0c14ec;
P_0c0c14ec: /* original ff17, guest PC 0x0c0c14ec */
if(!s->budget--) { s->failed_pc=0x0c0c14ecu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c14ee;
P_0c0c14ee: /* original e010, guest PC 0x0c0c14ee */
if(!s->budget--) { s->failed_pc=0x0c0c14eeu; return 0; }
r[0]=0x00000010u;
goto P_0c0c14f0;
P_0c0c14f0: /* original f3d6, guest PC 0x0c0c14f0 */
if(!s->budget--) { s->failed_pc=0x0c0c14f0u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0c14f2;
P_0c0c14f2: /* original e014, guest PC 0x0c0c14f2 */
if(!s->budget--) { s->failed_pc=0x0c0c14f2u; return 0; }
r[0]=0x00000014u;
goto P_0c0c14f4;
P_0c0c14f4: /* original f6ec, guest PC 0x0c0c14f4 */
if(!s->budget--) { s->failed_pc=0x0c0c14f4u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c0c14f6;
P_0c0c14f6: /* original f632, guest PC 0x0c0c14f6 */
if(!s->budget--) { s->failed_pc=0x0c0c14f6u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0c14f8;
P_0c0c14f8: /* original 62f2, guest PC 0x0c0c14f8 */
if(!s->budget--) { s->failed_pc=0x0c0c14f8u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c14fa;
P_0c0c14fa: /* original f3d6, guest PC 0x0c0c14fa */
if(!s->budget--) { s->failed_pc=0x0c0c14fau; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0c14fc;
P_0c0c14fc: /* original e024, guest PC 0x0c0c14fc */
if(!s->budget--) { s->failed_pc=0x0c0c14fcu; return 0; }
r[0]=0x00000024u;
goto P_0c0c14fe;
P_0c0c14fe: /* original 012d, guest PC 0x0c0c14fe */
if(!s->budget--) { s->failed_pc=0x0c0c14feu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c0c1500;
P_0c0c1500: /* original d030, guest PC 0x0c0c1500 */
if(!s->budget--) { s->failed_pc=0x0c0c1500u; return 0; }
r[0]=read(ram,0x0c0c15c4u,4);
goto P_0c0c1502;
P_0c0c1502: /* original 611d, guest PC 0x0c0c1502 */
if(!s->budget--) { s->failed_pc=0x0c0c1502u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0c1504;
P_0c0c1504: /* original f70c, guest PC 0x0c0c1504 */
if(!s->budget--) { s->failed_pc=0x0c0c1504u; return 0; }
vf3_matrix_move(s,7,0);
goto P_0c0c1506;
P_0c0c1506: /* original 4108, guest PC 0x0c0c1506 */
if(!s->budget--) { s->failed_pc=0x0c0c1506u; return 0; }
r[1]<<=2;
goto P_0c0c1508;
P_0c0c1508: /* original f732, guest PC 0x0c0c1508 */
if(!s->budget--) { s->failed_pc=0x0c0c1508u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c0c150a;
P_0c0c150a: /* original f816, guest PC 0x0c0c150a */
if(!s->budget--) { s->failed_pc=0x0c0c150au; return 0; }
vf3_matrix_load(s,ram,8,r[1]+r[0]);
goto P_0c0c150c;
P_0c0c150c: /* original e004, guest PC 0x0c0c150c */
if(!s->budget--) { s->failed_pc=0x0c0c150cu; return 0; }
r[0]=0x00000004u;
goto P_0c0c150e;
P_0c0c150e: /* original f5f6, guest PC 0x0c0c150e */
if(!s->budget--) { s->failed_pc=0x0c0c150eu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c1510;
P_0c0c1510: /* original e010, guest PC 0x0c0c1510 */
if(!s->budget--) { s->failed_pc=0x0c0c1510u; return 0; }
r[0]=0x00000010u;
goto P_0c0c1512;
P_0c0c1512: /* original d22d, guest PC 0x0c0c1512 */
if(!s->budget--) { s->failed_pc=0x0c0c1512u; return 0; }
r[2]=read(ram,0x0c0c15c8u,4);
goto P_0c0c1514;
P_0c0c1514: /* original f4f6, guest PC 0x0c0c1514 */
if(!s->budget--) { s->failed_pc=0x0c0c1514u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c1516;
P_0c0c1516: /* original 420b, guest PC 0x0c0c1516 */
if(!s->budget--) { s->failed_pc=0x0c0c1516u; return 0; }
target=r[2];
r[16]=0x0c0c151au;
r[4]+=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c151au) { target=s->pc; goto dispatch; }
goto P_0c0c151a;
P_0c0c1518: /* original 7414, guest PC 0x0c0c1518 */
if(!s->budget--) { s->failed_pc=0x0c0c1518u; return 0; }
r[4]+=0x00000014u;
goto P_0c0c151a;
P_0c0c151a: /* original e014, guest PC 0x0c0c151a */
if(!s->budget--) { s->failed_pc=0x0c0c151au; return 0; }
r[0]=0x00000014u;
goto P_0c0c151c;
P_0c0c151c: /* original d32b, guest PC 0x0c0c151c */
if(!s->budget--) { s->failed_pc=0x0c0c151cu; return 0; }
r[3]=read(ram,0x0c0c15ccu,4);
goto P_0c0c151e;
P_0c0c151e: /* original f9d6, guest PC 0x0c0c151e */
if(!s->budget--) { s->failed_pc=0x0c0c151eu; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c0c1520;
P_0c0c1520: /* original e010, guest PC 0x0c0c1520 */
if(!s->budget--) { s->failed_pc=0x0c0c1520u; return 0; }
r[0]=0x00000010u;
goto P_0c0c1522;
P_0c0c1522: /* original f8d6, guest PC 0x0c0c1522 */
if(!s->budget--) { s->failed_pc=0x0c0c1522u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c0c1524;
P_0c0c1524: /* original e00c, guest PC 0x0c0c1524 */
if(!s->budget--) { s->failed_pc=0x0c0c1524u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1526;
P_0c0c1526: /* original f5f6, guest PC 0x0c0c1526 */
if(!s->budget--) { s->failed_pc=0x0c0c1526u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c1528;
P_0c0c1528: /* original e008, guest PC 0x0c0c1528 */
if(!s->budget--) { s->failed_pc=0x0c0c1528u; return 0; }
r[0]=0x00000008u;
goto P_0c0c152a;
P_0c0c152a: /* original f4f6, guest PC 0x0c0c152a */
if(!s->budget--) { s->failed_pc=0x0c0c152au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c152c;
P_0c0c152c: /* original 64f3, guest PC 0x0c0c152c */
if(!s->budget--) { s->failed_pc=0x0c0c152cu; return 0; }
r[4]=r[15];
goto P_0c0c152e;
P_0c0c152e: /* original f7fc, guest PC 0x0c0c152e */
if(!s->budget--) { s->failed_pc=0x0c0c152eu; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0c1530;
P_0c0c1530: /* original f6ec, guest PC 0x0c0c1530 */
if(!s->budget--) { s->failed_pc=0x0c0c1530u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c0c1532;
P_0c0c1532: /* original 430b, guest PC 0x0c0c1532 */
if(!s->budget--) { s->failed_pc=0x0c0c1532u; return 0; }
target=r[3];
r[16]=0x0c0c1536u;
r[4]+=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1536u) { target=s->pc; goto dispatch; }
goto P_0c0c1536;
P_0c0c1534: /* original 7414, guest PC 0x0c0c1534 */
if(!s->budget--) { s->failed_pc=0x0c0c1534u; return 0; }
r[4]+=0x00000014u;
goto P_0c0c1536;
P_0c0c1536: /* original f39d, guest PC 0x0c0c1536 */
if(!s->budget--) { s->failed_pc=0x0c0c1536u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c1538;
P_0c0c1538: /* original e044, guest PC 0x0c0c1538 */
if(!s->budget--) { s->failed_pc=0x0c0c1538u; return 0; }
r[0]=0x00000044u;
goto P_0c0c153a;
P_0c0c153a: /* original 943d, guest PC 0x0c0c153a */
if(!s->budget--) { s->failed_pc=0x0c0c153au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c15b8u,2);
goto P_0c0c153c;
P_0c0c153c: /* original ff37, guest PC 0x0c0c153c */
if(!s->budget--) { s->failed_pc=0x0c0c153cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c153e;
P_0c0c153e: /* original d324, guest PC 0x0c0c153e */
if(!s->budget--) { s->failed_pc=0x0c0c153eu; return 0; }
r[3]=read(ram,0x0c0c15d0u,4);
goto P_0c0c1540;
P_0c0c1540: /* original 923c, guest PC 0x0c0c1540 */
if(!s->budget--) { s->failed_pc=0x0c0c1540u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c15bcu,2);
goto P_0c0c1542;
P_0c0c1542: /* original 6532, guest PC 0x0c0c1542 */
if(!s->budget--) { s->failed_pc=0x0c0c1542u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0c1544;
P_0c0c1544: /* original 9639, guest PC 0x0c0c1544 */
if(!s->budget--) { s->failed_pc=0x0c0c1544u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c15bau,2);
goto P_0c0c1546;
P_0c0c1546: /* original 2258, guest PC 0x0c0c1546 */
if(!s->budget--) { s->failed_pc=0x0c0c1546u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0c1548;
P_0c0c1548: /* original 8901, guest PC 0x0c0c1548 */
if(!s->budget--) { s->failed_pc=0x0c0c1548u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c154e; }
goto P_0c0c154a;
P_0c0c154a: /* original a01b, guest PC 0x0c0c154a */
if(!s->budget--) { s->failed_pc=0x0c0c154au; return 0; }
r[4]=r[6];
goto P_0c0c1584;
P_0c0c154c: /* original 6463, guest PC 0x0c0c154c */
if(!s->budget--) { s->failed_pc=0x0c0c154cu; return 0; }
r[4]=r[6];
goto P_0c0c154e;
P_0c0c154e: /* original 9136, guest PC 0x0c0c154e */
if(!s->budget--) { s->failed_pc=0x0c0c154eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c15beu,2);
goto P_0c0c1550;
P_0c0c1550: /* original 2518, guest PC 0x0c0c1550 */
if(!s->budget--) { s->failed_pc=0x0c0c1550u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[1])==0)!=0);
goto P_0c0c1552;
P_0c0c1552: /* original 8917, guest PC 0x0c0c1552 */
if(!s->budget--) { s->failed_pc=0x0c0c1552u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1584; }
goto P_0c0c1554;
P_0c0c1554: /* original c71f, guest PC 0x0c0c1554 */
if(!s->budget--) { s->failed_pc=0x0c0c1554u; return 0; }
r[0]=0x0c0c15d4u;
goto P_0c0c1556;
P_0c0c1556: /* original 6463, guest PC 0x0c0c1556 */
if(!s->budget--) { s->failed_pc=0x0c0c1556u; return 0; }
r[4]=r[6];
goto P_0c0c1558;
P_0c0c1558: /* original f308, guest PC 0x0c0c1558 */
if(!s->budget--) { s->failed_pc=0x0c0c1558u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c155a;
P_0c0c155a: /* original e044, guest PC 0x0c0c155a */
if(!s->budget--) { s->failed_pc=0x0c0c155au; return 0; }
r[0]=0x00000044u;
goto P_0c0c155c;
P_0c0c155c: /* original ff37, guest PC 0x0c0c155c */
if(!s->budget--) { s->failed_pc=0x0c0c155cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c155e;
P_0c0c155e: /* original c71e, guest PC 0x0c0c155e */
if(!s->budget--) { s->failed_pc=0x0c0c155eu; return 0; }
r[0]=0x0c0c15d8u;
goto P_0c0c1560;
P_0c0c1560: /* original f308, guest PC 0x0c0c1560 */
if(!s->budget--) { s->failed_pc=0x0c0c1560u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c1562;
P_0c0c1562: /* original e024, guest PC 0x0c0c1562 */
if(!s->budget--) { s->failed_pc=0x0c0c1562u; return 0; }
r[0]=0x00000024u;
goto P_0c0c1564;
P_0c0c1564: /* original f2f6, guest PC 0x0c0c1564 */
if(!s->budget--) { s->failed_pc=0x0c0c1564u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c1566;
P_0c0c1566: /* original e024, guest PC 0x0c0c1566 */
if(!s->budget--) { s->failed_pc=0x0c0c1566u; return 0; }
r[0]=0x00000024u;
goto P_0c0c1568;
P_0c0c1568: /* original f231, guest PC 0x0c0c1568 */
if(!s->budget--) { s->failed_pc=0x0c0c1568u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0c156a;
P_0c0c156a: /* original ff27, guest PC 0x0c0c156a */
if(!s->budget--) { s->failed_pc=0x0c0c156au; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c156c;
P_0c0c156c: /* original c71b, guest PC 0x0c0c156c */
if(!s->budget--) { s->failed_pc=0x0c0c156cu; return 0; }
r[0]=0x0c0c15dcu;
goto P_0c0c156e;
P_0c0c156e: /* original f408, guest PC 0x0c0c156e */
if(!s->budget--) { s->failed_pc=0x0c0c156eu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c1570;
P_0c0c1570: /* original e02c, guest PC 0x0c0c1570 */
if(!s->budget--) { s->failed_pc=0x0c0c1570u; return 0; }
r[0]=0x0000002cu;
goto P_0c0c1572;
P_0c0c1572: /* original f2f6, guest PC 0x0c0c1572 */
if(!s->budget--) { s->failed_pc=0x0c0c1572u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c1574;
P_0c0c1574: /* original e02c, guest PC 0x0c0c1574 */
if(!s->budget--) { s->failed_pc=0x0c0c1574u; return 0; }
r[0]=0x0000002cu;
goto P_0c0c1576;
P_0c0c1576: /* original f240, guest PC 0x0c0c1576 */
if(!s->budget--) { s->failed_pc=0x0c0c1576u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'+');
goto P_0c0c1578;
P_0c0c1578: /* original ff27, guest PC 0x0c0c1578 */
if(!s->budget--) { s->failed_pc=0x0c0c1578u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c157a;
P_0c0c157a: /* original e034, guest PC 0x0c0c157a */
if(!s->budget--) { s->failed_pc=0x0c0c157au; return 0; }
r[0]=0x00000034u;
goto P_0c0c157c;
P_0c0c157c: /* original f2f6, guest PC 0x0c0c157c */
if(!s->budget--) { s->failed_pc=0x0c0c157cu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c157e;
P_0c0c157e: /* original e034, guest PC 0x0c0c157e */
if(!s->budget--) { s->failed_pc=0x0c0c157eu; return 0; }
r[0]=0x00000034u;
goto P_0c0c1580;
P_0c0c1580: /* original f241, guest PC 0x0c0c1580 */
if(!s->budget--) { s->failed_pc=0x0c0c1580u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'-');
goto P_0c0c1582;
P_0c0c1582: /* original ff27, guest PC 0x0c0c1582 */
if(!s->budget--) { s->failed_pc=0x0c0c1582u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c1584;
P_0c0c1584: /* original 53d8, guest PC 0x0c0c1584 */
if(!s->budget--) { s->failed_pc=0x0c0c1584u; return 0; }
r[3]=read(ram,r[13]+32,4);
goto P_0c0c1586;
P_0c0c1586: /* original d016, guest PC 0x0c0c1586 */
if(!s->budget--) { s->failed_pc=0x0c0c1586u; return 0; }
r[0]=read(ram,0x0c0c15e0u,4);
goto P_0c0c1588;
P_0c0c1588: /* original 4300, guest PC 0x0c0c1588 */
if(!s->budget--) { s->failed_pc=0x0c0c1588u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c158a;
P_0c0c158a: /* original 023d, guest PC 0x0c0c158a */
if(!s->budget--) { s->failed_pc=0x0c0c158au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c158c;
P_0c0c158c: /* original e300, guest PC 0x0c0c158c */
if(!s->budget--) { s->failed_pc=0x0c0c158cu; return 0; }
r[3]=0x00000000u;
goto P_0c0c158e;
P_0c0c158e: /* original e040, guest PC 0x0c0c158e */
if(!s->budget--) { s->failed_pc=0x0c0c158eu; return 0; }
r[0]=0x00000040u;
goto P_0c0c1590;
P_0c0c1590: /* original 622d, guest PC 0x0c0c1590 */
if(!s->budget--) { s->failed_pc=0x0c0c1590u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c1592;
P_0c0c1592: /* original 1f25, guest PC 0x0c0c1592 */
if(!s->budget--) { s->failed_pc=0x0c0c1592u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c0c1594;
P_0c0c1594: /* original 1f3f, guest PC 0x0c0c1594 */
if(!s->budget--) { s->failed_pc=0x0c0c1594u; return 0; }
write(ram,r[15]+60,r[3],4);
goto P_0c0c1596;
P_0c0c1596: /* original 0f46, guest PC 0x0c0c1596 */
if(!s->budget--) { s->failed_pc=0x0c0c1596u; return 0; }
write(ram,r[15]+r[0],r[4],4);
goto P_0c0c1598;
P_0c0c1598: /* original 64f3, guest PC 0x0c0c1598 */
if(!s->budget--) { s->failed_pc=0x0c0c1598u; return 0; }
r[4]=r[15];
goto P_0c0c159a;
P_0c0c159a: /* original d312, guest PC 0x0c0c159a */
if(!s->budget--) { s->failed_pc=0x0c0c159au; return 0; }
r[3]=read(ram,0x0c0c15e4u,4);
goto P_0c0c159c;
P_0c0c159c: /* original 430b, guest PC 0x0c0c159c */
if(!s->budget--) { s->failed_pc=0x0c0c159cu; return 0; }
target=r[3];
r[16]=0x0c0c15a0u;
r[4]+=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c15a0u) { target=s->pc; goto dispatch; }
goto P_0c0c15a0;
P_0c0c159e: /* original 7414, guest PC 0x0c0c159e */
if(!s->budget--) { s->failed_pc=0x0c0c159eu; return 0; }
r[4]+=0x00000014u;
goto P_0c0c15a0;
P_0c0c15a0: /* original 60c3, guest PC 0x0c0c15a0 */
if(!s->budget--) { s->failed_pc=0x0c0c15a0u; return 0; }
r[0]=r[12];
goto P_0c0c15a2;
P_0c0c15a2: /* original 7f48, guest PC 0x0c0c15a2 */
if(!s->budget--) { s->failed_pc=0x0c0c15a2u; return 0; }
r[15]+=0x00000048u;
goto P_0c0c15a4;
P_0c0c15a4: /* original 4f26, guest PC 0x0c0c15a4 */
if(!s->budget--) { s->failed_pc=0x0c0c15a4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c15a6;
P_0c0c15a6: /* original fdf9, guest PC 0x0c0c15a6 */
if(!s->budget--) { s->failed_pc=0x0c0c15a6u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c15a8;
P_0c0c15a8: /* original fef9, guest PC 0x0c0c15a8 */
if(!s->budget--) { s->failed_pc=0x0c0c15a8u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c15aa;
P_0c0c15aa: /* original fff9, guest PC 0x0c0c15aa */
if(!s->budget--) { s->failed_pc=0x0c0c15aau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c15ac;
P_0c0c15ac: /* original 6bf6, guest PC 0x0c0c15ac */
if(!s->budget--) { s->failed_pc=0x0c0c15acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c15ae;
P_0c0c15ae: /* original 6cf6, guest PC 0x0c0c15ae */
if(!s->budget--) { s->failed_pc=0x0c0c15aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c15b0;
P_0c0c15b0: /* original 6df6, guest PC 0x0c0c15b0 */
if(!s->budget--) { s->failed_pc=0x0c0c15b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c15b2;
P_0c0c15b2: /* original 000b, guest PC 0x0c0c15b2 */
if(!s->budget--) { s->failed_pc=0x0c0c15b2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c15b4: /* original 6ef6, guest PC 0x0c0c15b4 */
if(!s->budget--) { s->failed_pc=0x0c0c15b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c15b6u,s,ram);
P_0c0c1770: /* original 4f22, guest PC 0x0c0c1770 */
if(!s->budget--) { s->failed_pc=0x0c0c1770u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c1772;
P_0c0c1772: /* original e024, guest PC 0x0c0c1772 */
if(!s->budget--) { s->failed_pc=0x0c0c1772u; return 0; }
r[0]=0x00000024u;
goto P_0c0c1774;
P_0c0c1774: /* original 68e3, guest PC 0x0c0c1774 */
if(!s->budget--) { s->failed_pc=0x0c0c1774u; return 0; }
r[8]=r[14];
goto P_0c0c1776;
P_0c0c1776: /* original 2d59, guest PC 0x0c0c1776 */
if(!s->budget--) { s->failed_pc=0x0c0c1776u; return 0; }
r[13]&=r[5];
goto P_0c0c1778;
P_0c0c1778: /* original 6b43, guest PC 0x0c0c1778 */
if(!s->budget--) { s->failed_pc=0x0c0c1778u; return 0; }
r[11]=r[4];
goto P_0c0c177a;
P_0c0c177a: /* original 6c63, guest PC 0x0c0c177a */
if(!s->budget--) { s->failed_pc=0x0c0c177au; return 0; }
r[12]=r[6];
goto P_0c0c177c;
P_0c0c177c: /* original 6973, guest PC 0x0c0c177c */
if(!s->budget--) { s->failed_pc=0x0c0c177cu; return 0; }
r[9]=r[7];
goto P_0c0c177e;
P_0c0c177e: /* original a043, guest PC 0x0c0c177e */
if(!s->budget--) { s->failed_pc=0x0c0c177eu; return 0; }
write(ram,r[11]+r[0],r[9],2);
goto P_0c0c1808;
P_0c0c1780: /* original 0b95, guest PC 0x0c0c1780 */
if(!s->budget--) { s->failed_pc=0x0c0c1780u; return 0; }
write(ram,r[11]+r[0],r[9],2);
return vf3_matrix_family(0x0c0c1782u,s,ram);
P_0c0c17ac: /* original 6ac4, guest PC 0x0c0c17ac */
if(!s->budget--) { s->failed_pc=0x0c0c17acu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[12]+=1;
r[10]=tmp;
goto P_0c0c17ae;
P_0c0c17ae: /* original 2998, guest PC 0x0c0c17ae */
if(!s->budget--) { s->failed_pc=0x0c0c17aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0c17b0;
P_0c0c17b0: /* original 8d16, guest PC 0x0c0c17b0 */
if(!s->budget--) { s->failed_pc=0x0c0c17b0u; return 0; }
cond=r[17]&1u;
r[10]=r[10]&255u;
if(cond) { goto P_0c0c17e0; }
goto P_0c0c17b4;
P_0c0c17b2: /* original 6aac, guest PC 0x0c0c17b2 */
if(!s->budget--) { s->failed_pc=0x0c0c17b2u; return 0; }
r[10]=r[10]&255u;
goto P_0c0c17b4;
P_0c0c17b4: /* original 60a3, guest PC 0x0c0c17b4 */
if(!s->budget--) { s->failed_pc=0x0c0c17b4u; return 0; }
r[0]=r[10];
goto P_0c0c17b6;
P_0c0c17b6: /* original 8808, guest PC 0x0c0c17b6 */
if(!s->budget--) { s->failed_pc=0x0c0c17b6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0c17b8;
P_0c0c17b8: /* original 890a, guest PC 0x0c0c17b8 */
if(!s->budget--) { s->failed_pc=0x0c0c17b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c17d0; }
goto P_0c0c17ba;
P_0c0c17ba: /* original 8809, guest PC 0x0c0c17ba */
if(!s->budget--) { s->failed_pc=0x0c0c17bau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0c17bc;
P_0c0c17bc: /* original 890a, guest PC 0x0c0c17bc */
if(!s->budget--) { s->failed_pc=0x0c0c17bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c17d4; }
goto P_0c0c17be;
P_0c0c17be: /* original 880a, guest PC 0x0c0c17be */
if(!s->budget--) { s->failed_pc=0x0c0c17beu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c0c17c0;
P_0c0c17c0: /* original 8905, guest PC 0x0c0c17c0 */
if(!s->budget--) { s->failed_pc=0x0c0c17c0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c17ce; }
goto P_0c0c17c2;
P_0c0c17c2: /* original 880d, guest PC 0x0c0c17c2 */
if(!s->budget--) { s->failed_pc=0x0c0c17c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0c17c4;
P_0c0c17c4: /* original 8903, guest PC 0x0c0c17c4 */
if(!s->budget--) { s->failed_pc=0x0c0c17c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c17ce; }
goto P_0c0c17c6;
P_0c0c17c6: /* original 885c, guest PC 0x0c0c17c6 */
if(!s->budget--) { s->failed_pc=0x0c0c17c6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000005cu)!=0);
goto P_0c0c17c8;
P_0c0c17c8: /* original 8901, guest PC 0x0c0c17c8 */
if(!s->budget--) { s->failed_pc=0x0c0c17c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c17ce; }
goto P_0c0c17ca;
P_0c0c17ca: /* original a009, guest PC 0x0c0c17ca */
if(!s->budget--) { s->failed_pc=0x0c0c17cau; return 0; }
goto P_0c0c17e0;
P_0c0c17cc: /* original 0009, guest PC 0x0c0c17cc */
if(!s->budget--) { s->failed_pc=0x0c0c17ccu; return 0; }
goto P_0c0c17ce;
P_0c0c17ce: /* original 7d01, guest PC 0x0c0c17ce */
if(!s->budget--) { s->failed_pc=0x0c0c17ceu; return 0; }
r[13]+=0x00000001u;
goto P_0c0c17d0;
P_0c0c17d0: /* original a01a, guest PC 0x0c0c17d0 */
if(!s->budget--) { s->failed_pc=0x0c0c17d0u; return 0; }
r[14]=r[8];
goto P_0c0c1808;
P_0c0c17d2: /* original 6e83, guest PC 0x0c0c17d2 */
if(!s->budget--) { s->failed_pc=0x0c0c17d2u; return 0; }
r[14]=r[8];
goto P_0c0c17d4;
P_0c0c17d4: /* original 62e3, guest PC 0x0c0c17d4 */
if(!s->budget--) { s->failed_pc=0x0c0c17d4u; return 0; }
r[2]=r[14];
goto P_0c0c17d6;
P_0c0c17d6: /* original e4f8, guest PC 0x0c0c17d6 */
if(!s->budget--) { s->failed_pc=0x0c0c17d6u; return 0; }
r[4]=0xfffffff8u;
goto P_0c0c17d8;
P_0c0c17d8: /* original 2249, guest PC 0x0c0c17d8 */
if(!s->budget--) { s->failed_pc=0x0c0c17d8u; return 0; }
r[2]&=r[4];
goto P_0c0c17da;
P_0c0c17da: /* original 6e23, guest PC 0x0c0c17da */
if(!s->budget--) { s->failed_pc=0x0c0c17dau; return 0; }
r[14]=r[2];
goto P_0c0c17dc;
P_0c0c17dc: /* original a014, guest PC 0x0c0c17dc */
if(!s->budget--) { s->failed_pc=0x0c0c17dcu; return 0; }
r[14]+=0x00000008u;
goto P_0c0c1808;
P_0c0c17de: /* original 7e08, guest PC 0x0c0c17de */
if(!s->budget--) { s->failed_pc=0x0c0c17deu; return 0; }
r[14]+=0x00000008u;
goto P_0c0c17e0;
P_0c0c17e0: /* original e020, guest PC 0x0c0c17e0 */
if(!s->budget--) { s->failed_pc=0x0c0c17e0u; return 0; }
r[0]=0x00000020u;
goto P_0c0c17e2;
P_0c0c17e2: /* original 66a3, guest PC 0x0c0c17e2 */
if(!s->budget--) { s->failed_pc=0x0c0c17e2u; return 0; }
r[6]=r[10];
goto P_0c0c17e4;
P_0c0c17e4: /* original e307, guest PC 0x0c0c17e4 */
if(!s->budget--) { s->failed_pc=0x0c0c17e4u; return 0; }
r[3]=0x00000007u;
goto P_0c0c17e6;
P_0c0c17e6: /* original 07bd, guest PC 0x0c0c17e6 */
if(!s->budget--) { s->failed_pc=0x0c0c17e6u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c0c17e8;
P_0c0c17e8: /* original 6ddf, guest PC 0x0c0c17e8 */
if(!s->budget--) { s->failed_pc=0x0c0c17e8u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c0c17ea;
P_0c0c17ea: /* original 65ef, guest PC 0x0c0c17ea */
if(!s->budget--) { s->failed_pc=0x0c0c17eau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c0c17ec;
P_0c0c17ec: /* original 4500, guest PC 0x0c0c17ec */
if(!s->budget--) { s->failed_pc=0x0c0c17ecu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0c17ee;
P_0c0c17ee: /* original 4d3c, guest PC 0x0c0c17ee */
if(!s->budget--) { s->failed_pc=0x0c0c17eeu; return 0; }
r[13]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[13]>>((-r[3])&31u)):((int32_t)r[13]<0?0xffffffffu:0)):r[13]<<(r[3]&31u);
goto P_0c0c17f0;
P_0c0c17f0: /* original 677d, guest PC 0x0c0c17f0 */
if(!s->budget--) { s->failed_pc=0x0c0c17f0u; return 0; }
r[7]=r[7]&65535u;
goto P_0c0c17f2;
P_0c0c17f2: /* original 25db, guest PC 0x0c0c17f2 */
if(!s->budget--) { s->failed_pc=0x0c0c17f2u; return 0; }
r[5]|=r[13];
goto P_0c0c17f4;
P_0c0c17f4: /* original bde6, guest PC 0x0c0c17f4 */
if(!s->budget--) { s->failed_pc=0x0c0c17f4u; return 0; }
target=0x0c0c13c4u; r[16]=0x0c0c17f8u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c17f8u) { target=s->pc; goto dispatch; }
goto P_0c0c17f8;
P_0c0c17f6: /* original 64b3, guest PC 0x0c0c17f6 */
if(!s->budget--) { s->failed_pc=0x0c0c17f6u; return 0; }
r[4]=r[11];
goto P_0c0c17f8;
P_0c0c17f8: /* original e3f9, guest PC 0x0c0c17f8 */
if(!s->budget--) { s->failed_pc=0x0c0c17f8u; return 0; }
r[3]=0xfffffff9u;
goto P_0c0c17fa;
P_0c0c17fa: /* original 6503, guest PC 0x0c0c17fa */
if(!s->budget--) { s->failed_pc=0x0c0c17fau; return 0; }
r[5]=r[0];
goto P_0c0c17fc;
P_0c0c17fc: /* original 453d, guest PC 0x0c0c17fc */
if(!s->budget--) { s->failed_pc=0x0c0c17fcu; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c0c17fe;
P_0c0c17fe: /* original ed3f, guest PC 0x0c0c17fe */
if(!s->budget--) { s->failed_pc=0x0c0c17feu; return 0; }
r[13]=0x0000003fu;
goto P_0c0c1800;
P_0c0c1800: /* original 4001, guest PC 0x0c0c1800 */
if(!s->budget--) { s->failed_pc=0x0c0c1800u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c0c1802;
P_0c0c1802: /* original ee3f, guest PC 0x0c0c1802 */
if(!s->budget--) { s->failed_pc=0x0c0c1802u; return 0; }
r[14]=0x0000003fu;
goto P_0c0c1804;
P_0c0c1804: /* original 2d59, guest PC 0x0c0c1804 */
if(!s->budget--) { s->failed_pc=0x0c0c1804u; return 0; }
r[13]&=r[5];
goto P_0c0c1806;
P_0c0c1806: /* original 2e09, guest PC 0x0c0c1806 */
if(!s->budget--) { s->failed_pc=0x0c0c1806u; return 0; }
r[14]&=r[0];
goto P_0c0c1808;
P_0c0c1808: /* original 62c0, guest PC 0x0c0c1808 */
if(!s->budget--) { s->failed_pc=0x0c0c1808u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[2]=tmp;
goto P_0c0c180a;
P_0c0c180a: /* original 2228, guest PC 0x0c0c180a */
if(!s->budget--) { s->failed_pc=0x0c0c180au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c180c;
P_0c0c180c: /* original 8bce, guest PC 0x0c0c180c */
if(!s->budget--) { s->failed_pc=0x0c0c180cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c17ac; }
goto P_0c0c180e;
P_0c0c180e: /* original 4f26, guest PC 0x0c0c180e */
if(!s->budget--) { s->failed_pc=0x0c0c180eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c1810;
P_0c0c1810: /* original 6ddf, guest PC 0x0c0c1810 */
if(!s->budget--) { s->failed_pc=0x0c0c1810u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c0c1812;
P_0c0c1812: /* original 65ef, guest PC 0x0c0c1812 */
if(!s->budget--) { s->failed_pc=0x0c0c1812u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c0c1814;
P_0c0c1814: /* original 68f6, guest PC 0x0c0c1814 */
if(!s->budget--) { s->failed_pc=0x0c0c1814u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c1816;
P_0c0c1816: /* original e307, guest PC 0x0c0c1816 */
if(!s->budget--) { s->failed_pc=0x0c0c1816u; return 0; }
r[3]=0x00000007u;
goto P_0c0c1818;
P_0c0c1818: /* original 4d3c, guest PC 0x0c0c1818 */
if(!s->budget--) { s->failed_pc=0x0c0c1818u; return 0; }
r[13]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[13]>>((-r[3])&31u)):((int32_t)r[13]<0?0xffffffffu:0)):r[13]<<(r[3]&31u);
goto P_0c0c181a;
P_0c0c181a: /* original 69f6, guest PC 0x0c0c181a */
if(!s->budget--) { s->failed_pc=0x0c0c181au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c181c;
P_0c0c181c: /* original 4500, guest PC 0x0c0c181c */
if(!s->budget--) { s->failed_pc=0x0c0c181cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0c181e;
P_0c0c181e: /* original 25db, guest PC 0x0c0c181e */
if(!s->budget--) { s->failed_pc=0x0c0c181eu; return 0; }
r[5]|=r[13];
goto P_0c0c1820;
P_0c0c1820: /* original 6af6, guest PC 0x0c0c1820 */
if(!s->budget--) { s->failed_pc=0x0c0c1820u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c1822;
P_0c0c1822: /* original 6053, guest PC 0x0c0c1822 */
if(!s->budget--) { s->failed_pc=0x0c0c1822u; return 0; }
r[0]=r[5];
goto P_0c0c1824;
P_0c0c1824: /* original 6bf6, guest PC 0x0c0c1824 */
if(!s->budget--) { s->failed_pc=0x0c0c1824u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c1826;
P_0c0c1826: /* original 6cf6, guest PC 0x0c0c1826 */
if(!s->budget--) { s->failed_pc=0x0c0c1826u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c1828;
P_0c0c1828: /* original 6df6, guest PC 0x0c0c1828 */
if(!s->budget--) { s->failed_pc=0x0c0c1828u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c182a;
P_0c0c182a: /* original 000b, guest PC 0x0c0c182a */
if(!s->budget--) { s->failed_pc=0x0c0c182au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c182c: /* original 6ef6, guest PC 0x0c0c182c */
if(!s->budget--) { s->failed_pc=0x0c0c182cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c182eu,s,ram);
P_0c0c1d86: /* original 2fe6, guest PC 0x0c0c1d86 */
if(!s->budget--) { s->failed_pc=0x0c0c1d86u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c1d88;
P_0c0c1d88: /* original 6e43, guest PC 0x0c0c1d88 */
if(!s->budget--) { s->failed_pc=0x0c0c1d88u; return 0; }
r[14]=r[4];
goto P_0c0c1d8a;
P_0c0c1d8a: /* original 2fd6, guest PC 0x0c0c1d8a */
if(!s->budget--) { s->failed_pc=0x0c0c1d8au; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0c1d8c;
P_0c0c1d8c: /* original e026, guest PC 0x0c0c1d8c */
if(!s->budget--) { s->failed_pc=0x0c0c1d8cu; return 0; }
r[0]=0x00000026u;
goto P_0c0c1d8e;
P_0c0c1d8e: /* original 2fc6, guest PC 0x0c0c1d8e */
if(!s->budget--) { s->failed_pc=0x0c0c1d8eu; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0c1d90;
P_0c0c1d90: /* original e67f, guest PC 0x0c0c1d90 */
if(!s->budget--) { s->failed_pc=0x0c0c1d90u; return 0; }
r[6]=0x0000007fu;
goto P_0c0c1d92;
P_0c0c1d92: /* original 2fb6, guest PC 0x0c0c1d92 */
if(!s->budget--) { s->failed_pc=0x0c0c1d92u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0c1d94;
P_0c0c1d94: /* original 2fa6, guest PC 0x0c0c1d94 */
if(!s->budget--) { s->failed_pc=0x0c0c1d94u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0c1d96;
P_0c0c1d96: /* original 2f96, guest PC 0x0c0c1d96 */
if(!s->budget--) { s->failed_pc=0x0c0c1d96u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0c1d98;
P_0c0c1d98: /* original 2f86, guest PC 0x0c0c1d98 */
if(!s->budget--) { s->failed_pc=0x0c0c1d98u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0c1d9a;
P_0c0c1d9a: /* original fffb, guest PC 0x0c0c1d9a */
if(!s->budget--) { s->failed_pc=0x0c0c1d9au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c1d9c;
P_0c0c1d9c: /* original ffeb, guest PC 0x0c0c1d9c */
if(!s->budget--) { s->failed_pc=0x0c0c1d9cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0c1d9e;
P_0c0c1d9e: /* original ffdb, guest PC 0x0c0c1d9e */
if(!s->budget--) { s->failed_pc=0x0c0c1d9eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0c1da0;
P_0c0c1da0: /* original ffcb, guest PC 0x0c0c1da0 */
if(!s->budget--) { s->failed_pc=0x0c0c1da0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0c1da2;
P_0c0c1da2: /* original 03ed, guest PC 0x0c0c1da2 */
if(!s->budget--) { s->failed_pc=0x0c0c1da2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c1da4;
P_0c0c1da4: /* original d01c, guest PC 0x0c0c1da4 */
if(!s->budget--) { s->failed_pc=0x0c0c1da4u; return 0; }
r[0]=read(ram,0x0c0c1e18u,4);
goto P_0c0c1da6;
P_0c0c1da6: /* original 4f22, guest PC 0x0c0c1da6 */
if(!s->budget--) { s->failed_pc=0x0c0c1da6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c1da8;
P_0c0c1da8: /* original dc1a, guest PC 0x0c0c1da8 */
if(!s->budget--) { s->failed_pc=0x0c0c1da8u; return 0; }
r[12]=read(ram,0x0c0c1e14u,4);
goto P_0c0c1daa;
P_0c0c1daa: /* original 633d, guest PC 0x0c0c1daa */
if(!s->budget--) { s->failed_pc=0x0c0c1daau; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c1dac;
P_0c0c1dac: /* original 4308, guest PC 0x0c0c1dac */
if(!s->budget--) { s->failed_pc=0x0c0c1dacu; return 0; }
r[3]<<=2;
goto P_0c0c1dae;
P_0c0c1dae: /* original 64c3, guest PC 0x0c0c1dae */
if(!s->budget--) { s->failed_pc=0x0c0c1daeu; return 0; }
r[4]=r[12];
goto P_0c0c1db0;
P_0c0c1db0: /* original fe36, guest PC 0x0c0c1db0 */
if(!s->budget--) { s->failed_pc=0x0c0c1db0u; return 0; }
vf3_matrix_load(s,ram,14,r[3]+r[0]);
goto P_0c0c1db2;
P_0c0c1db2: /* original 67c3, guest PC 0x0c0c1db2 */
if(!s->budget--) { s->failed_pc=0x0c0c1db2u; return 0; }
r[7]=r[12];
goto P_0c0c1db4;
P_0c0c1db4: /* original 65c3, guest PC 0x0c0c1db4 */
if(!s->budget--) { s->failed_pc=0x0c0c1db4u; return 0; }
r[5]=r[12];
goto P_0c0c1db6;
P_0c0c1db6: /* original 3e40, guest PC 0x0c0c1db6 */
if(!s->budget--) { s->failed_pc=0x0c0c1db6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[4])!=0);
goto P_0c0c1db8;
P_0c0c1db8: /* original c718, guest PC 0x0c0c1db8 */
if(!s->budget--) { s->failed_pc=0x0c0c1db8u; return 0; }
r[0]=0x0c0c1e1cu;
goto P_0c0c1dba;
P_0c0c1dba: /* original 7fc8, guest PC 0x0c0c1dba */
if(!s->budget--) { s->failed_pc=0x0c0c1dbau; return 0; }
r[15]+=0xffffffc8u;
goto P_0c0c1dbc;
P_0c0c1dbc: /* original 752c, guest PC 0x0c0c1dbc */
if(!s->budget--) { s->failed_pc=0x0c0c1dbcu; return 0; }
r[5]+=0x0000002cu;
goto P_0c0c1dbe;
P_0c0c1dbe: /* original 7758, guest PC 0x0c0c1dbe */
if(!s->budget--) { s->failed_pc=0x0c0c1dbeu; return 0; }
r[7]+=0x00000058u;
goto P_0c0c1dc0;
P_0c0c1dc0: /* original 8d02, guest PC 0x0c0c1dc0 */
if(!s->budget--) { s->failed_pc=0x0c0c1dc0u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[0]);
if(cond) { goto P_0c0c1dc8; }
goto P_0c0c1dc4;
P_0c0c1dc2: /* original f408, guest PC 0x0c0c1dc2 */
if(!s->budget--) { s->failed_pc=0x0c0c1dc2u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c1dc4;
P_0c0c1dc4: /* original 3e50, guest PC 0x0c0c1dc4 */
if(!s->budget--) { s->failed_pc=0x0c0c1dc4u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[5])!=0);
goto P_0c0c1dc6;
P_0c0c1dc6: /* original 8b0f, guest PC 0x0c0c1dc6 */
if(!s->budget--) { s->failed_pc=0x0c0c1dc6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1de8; }
goto P_0c0c1dc8;
P_0c0c1dc8: /* original 9014, guest PC 0x0c0c1dc8 */
if(!s->budget--) { s->failed_pc=0x0c0c1dc8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1df4u,2);
goto P_0c0c1dca;
P_0c0c1dca: /* original 04ce, guest PC 0x0c0c1dca */
if(!s->budget--) { s->failed_pc=0x0c0c1dcau; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c0c1dcc;
P_0c0c1dcc: /* original 2448, guest PC 0x0c0c1dcc */
if(!s->budget--) { s->failed_pc=0x0c0c1dccu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c1dce;
P_0c0c1dce: /* original 890f, guest PC 0x0c0c1dce */
if(!s->budget--) { s->failed_pc=0x0c0c1dceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1df0; }
goto P_0c0c1dd0;
P_0c0c1dd0: /* original 2469, guest PC 0x0c0c1dd0 */
if(!s->budget--) { s->failed_pc=0x0c0c1dd0u; return 0; }
r[4]&=r[6];
goto P_0c0c1dd2;
P_0c0c1dd2: /* original 644b, guest PC 0x0c0c1dd2 */
if(!s->budget--) { s->failed_pc=0x0c0c1dd2u; return 0; }
r[4]=0u-r[4];
goto P_0c0c1dd4;
P_0c0c1dd4: /* original 747f, guest PC 0x0c0c1dd4 */
if(!s->budget--) { s->failed_pc=0x0c0c1dd4u; return 0; }
r[4]+=0x0000007fu;
goto P_0c0c1dd6;
P_0c0c1dd6: /* original 445a, guest PC 0x0c0c1dd6 */
if(!s->budget--) { s->failed_pc=0x0c0c1dd6u; return 0; }
r[53]=r[4];
goto P_0c0c1dd8;
P_0c0c1dd8: /* original 4411, guest PC 0x0c0c1dd8 */
if(!s->budget--) { s->failed_pc=0x0c0c1dd8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c1dda;
P_0c0c1dda: /* original 8d2e, guest PC 0x0c0c1dda */
if(!s->budget--) { s->failed_pc=0x0c0c1ddau; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c1e3a; }
goto P_0c0c1dde;
P_0c0c1ddc: /* original f32d, guest PC 0x0c0c1ddc */
if(!s->budget--) { s->failed_pc=0x0c0c1ddcu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c1dde;
P_0c0c1dde: /* original d210, guest PC 0x0c0c1dde */
if(!s->budget--) { s->failed_pc=0x0c0c1ddeu; return 0; }
r[2]=read(ram,0x0c0c1e20u,4);
goto P_0c0c1de0;
P_0c0c1de0: /* original 425a, guest PC 0x0c0c1de0 */
if(!s->budget--) { s->failed_pc=0x0c0c1de0u; return 0; }
r[53]=r[2];
goto P_0c0c1de2;
P_0c0c1de2: /* original f20d, guest PC 0x0c0c1de2 */
if(!s->budget--) { s->failed_pc=0x0c0c1de2u; return 0; }
fr[2]=r[53];
goto P_0c0c1de4;
P_0c0c1de4: /* original a029, guest PC 0x0c0c1de4 */
if(!s->budget--) { s->failed_pc=0x0c0c1de4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c1e3a;
P_0c0c1de6: /* original f320, guest PC 0x0c0c1de6 */
if(!s->budget--) { s->failed_pc=0x0c0c1de6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c1de8;
P_0c0c1de8: /* original 9005, guest PC 0x0c0c1de8 */
if(!s->budget--) { s->failed_pc=0x0c0c1de8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1df6u,2);
goto P_0c0c1dea;
P_0c0c1dea: /* original 04ce, guest PC 0x0c0c1dea */
if(!s->budget--) { s->failed_pc=0x0c0c1deau; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c0c1dec;
P_0c0c1dec: /* original 2448, guest PC 0x0c0c1dec */
if(!s->budget--) { s->failed_pc=0x0c0c1decu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c1dee;
P_0c0c1dee: /* original 8b19, guest PC 0x0c0c1dee */
if(!s->budget--) { s->failed_pc=0x0c0c1deeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1e24; }
goto P_0c0c1df0;
P_0c0c1df0: /* original a025, guest PC 0x0c0c1df0 */
if(!s->budget--) { s->failed_pc=0x0c0c1df0u; return 0; }
fr[15]=0x3f800000u;
goto P_0c0c1e3e;
P_0c0c1df2: /* original ff9d, guest PC 0x0c0c1df2 */
if(!s->budget--) { s->failed_pc=0x0c0c1df2u; return 0; }
fr[15]=0x3f800000u;
return vf3_matrix_family(0x0c0c1df4u,s,ram);
P_0c0c1e24: /* original 2469, guest PC 0x0c0c1e24 */
if(!s->budget--) { s->failed_pc=0x0c0c1e24u; return 0; }
r[4]&=r[6];
goto P_0c0c1e26;
P_0c0c1e26: /* original 644b, guest PC 0x0c0c1e26 */
if(!s->budget--) { s->failed_pc=0x0c0c1e26u; return 0; }
r[4]=0u-r[4];
goto P_0c0c1e28;
P_0c0c1e28: /* original 747f, guest PC 0x0c0c1e28 */
if(!s->budget--) { s->failed_pc=0x0c0c1e28u; return 0; }
r[4]+=0x0000007fu;
goto P_0c0c1e2a;
P_0c0c1e2a: /* original 445a, guest PC 0x0c0c1e2a */
if(!s->budget--) { s->failed_pc=0x0c0c1e2au; return 0; }
r[53]=r[4];
goto P_0c0c1e2c;
P_0c0c1e2c: /* original 4411, guest PC 0x0c0c1e2c */
if(!s->budget--) { s->failed_pc=0x0c0c1e2cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c1e2e;
P_0c0c1e2e: /* original 8d04, guest PC 0x0c0c1e2e */
if(!s->budget--) { s->failed_pc=0x0c0c1e2eu; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c0c1e3a; }
goto P_0c0c1e32;
P_0c0c1e30: /* original f32d, guest PC 0x0c0c1e30 */
if(!s->budget--) { s->failed_pc=0x0c0c1e30u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c1e32;
P_0c0c1e32: /* original d346, guest PC 0x0c0c1e32 */
if(!s->budget--) { s->failed_pc=0x0c0c1e32u; return 0; }
r[3]=read(ram,0x0c0c1f4cu,4);
goto P_0c0c1e34;
P_0c0c1e34: /* original 435a, guest PC 0x0c0c1e34 */
if(!s->budget--) { s->failed_pc=0x0c0c1e34u; return 0; }
r[53]=r[3];
goto P_0c0c1e36;
P_0c0c1e36: /* original f20d, guest PC 0x0c0c1e36 */
if(!s->budget--) { s->failed_pc=0x0c0c1e36u; return 0; }
fr[2]=r[53];
goto P_0c0c1e38;
P_0c0c1e38: /* original f320, guest PC 0x0c0c1e38 */
if(!s->budget--) { s->failed_pc=0x0c0c1e38u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c1e3a;
P_0c0c1e3a: /* original ff3c, guest PC 0x0c0c1e3a */
if(!s->budget--) { s->failed_pc=0x0c0c1e3au; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c0c1e3c;
P_0c0c1e3c: /* original ff43, guest PC 0x0c0c1e3c */
if(!s->budget--) { s->failed_pc=0x0c0c1e3cu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'/');
goto P_0c0c1e3e;
P_0c0c1e3e: /* original 3e70, guest PC 0x0c0c1e3e */
if(!s->budget--) { s->failed_pc=0x0c0c1e3eu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[7])!=0);
goto P_0c0c1e40;
P_0c0c1e40: /* original 8f14, guest PC 0x0c0c1e40 */
if(!s->budget--) { s->failed_pc=0x0c0c1e40u; return 0; }
cond=r[17]&1u;
r[4]=0x00000002u;
if(!cond) { goto P_0c0c1e6c; }
goto P_0c0c1e44;
P_0c0c1e42: /* original e402, guest PC 0x0c0c1e42 */
if(!s->budget--) { s->failed_pc=0x0c0c1e42u; return 0; }
r[4]=0x00000002u;
goto P_0c0c1e44;
P_0c0c1e44: /* original 907f, guest PC 0x0c0c1e44 */
if(!s->budget--) { s->failed_pc=0x0c0c1e44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1f46u,2);
goto P_0c0c1e46;
P_0c0c1e46: /* original 05ce, guest PC 0x0c0c1e46 */
if(!s->budget--) { s->failed_pc=0x0c0c1e46u; return 0; }
r[5]=read(ram,r[12]+r[0],4);
goto P_0c0c1e48;
P_0c0c1e48: /* original 4511, guest PC 0x0c0c1e48 */
if(!s->budget--) { s->failed_pc=0x0c0c1e48u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c0c1e4a;
P_0c0c1e4a: /* original 8b06, guest PC 0x0c0c1e4a */
if(!s->budget--) { s->failed_pc=0x0c0c1e4au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1e5a; }
goto P_0c0c1e4c;
P_0c0c1e4c: /* original e210, guest PC 0x0c0c1e4c */
if(!s->budget--) { s->failed_pc=0x0c0c1e4cu; return 0; }
r[2]=0x00000010u;
goto P_0c0c1e4e;
P_0c0c1e4e: /* original 3527, guest PC 0x0c0c1e4e */
if(!s->budget--) { s->failed_pc=0x0c0c1e4eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[2])!=0);
goto P_0c0c1e50;
P_0c0c1e50: /* original 8903, guest PC 0x0c0c1e50 */
if(!s->budget--) { s->failed_pc=0x0c0c1e50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1e5a; }
goto P_0c0c1e52;
P_0c0c1e52: /* original bebd, guest PC 0x0c0c1e52 */
if(!s->budget--) { s->failed_pc=0x0c0c1e52u; return 0; }
target=0x0c0c1bd0u; r[16]=0x0c0c1e56u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1e56u) { target=s->pc; goto dispatch; }
goto P_0c0c1e56;
P_0c0c1e54: /* original 64e3, guest PC 0x0c0c1e54 */
if(!s->budget--) { s->failed_pc=0x0c0c1e54u; return 0; }
r[4]=r[14];
goto P_0c0c1e56;
P_0c0c1e56: /* original a05e, guest PC 0x0c0c1e56 */
if(!s->budget--) { s->failed_pc=0x0c0c1e56u; return 0; }
goto P_0c0c1f16;
P_0c0c1e58: /* original 0009, guest PC 0x0c0c1e58 */
if(!s->budget--) { s->failed_pc=0x0c0c1e58u; return 0; }
goto P_0c0c1e5a;
P_0c0c1e5a: /* original 9075, guest PC 0x0c0c1e5a */
if(!s->budget--) { s->failed_pc=0x0c0c1e5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1f48u,2);
goto P_0c0c1e5c;
P_0c0c1e5c: /* original 02ce, guest PC 0x0c0c1e5c */
if(!s->budget--) { s->failed_pc=0x0c0c1e5cu; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0c1e5e;
P_0c0c1e5e: /* original 2228, guest PC 0x0c0c1e5e */
if(!s->budget--) { s->failed_pc=0x0c0c1e5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c1e60;
P_0c0c1e60: /* original 8b09, guest PC 0x0c0c1e60 */
if(!s->budget--) { s->failed_pc=0x0c0c1e60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1e76; }
goto P_0c0c1e62;
P_0c0c1e62: /* original e022, guest PC 0x0c0c1e62 */
if(!s->budget--) { s->failed_pc=0x0c0c1e62u; return 0; }
r[0]=0x00000022u;
goto P_0c0c1e64;
P_0c0c1e64: /* original 02ed, guest PC 0x0c0c1e64 */
if(!s->budget--) { s->failed_pc=0x0c0c1e64u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c1e66;
P_0c0c1e66: /* original 622d, guest PC 0x0c0c1e66 */
if(!s->budget--) { s->failed_pc=0x0c0c1e66u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c1e68;
P_0c0c1e68: /* original 2248, guest PC 0x0c0c1e68 */
if(!s->budget--) { s->failed_pc=0x0c0c1e68u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0c1e6a;
P_0c0c1e6a: /* original 8954, guest PC 0x0c0c1e6a */
if(!s->budget--) { s->failed_pc=0x0c0c1e6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1f16; }
goto P_0c0c1e6c;
P_0c0c1e6c: /* original e022, guest PC 0x0c0c1e6c */
if(!s->budget--) { s->failed_pc=0x0c0c1e6cu; return 0; }
r[0]=0x00000022u;
goto P_0c0c1e6e;
P_0c0c1e6e: /* original 01ed, guest PC 0x0c0c1e6e */
if(!s->budget--) { s->failed_pc=0x0c0c1e6eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c1e70;
P_0c0c1e70: /* original 611d, guest PC 0x0c0c1e70 */
if(!s->budget--) { s->failed_pc=0x0c0c1e70u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0c1e72;
P_0c0c1e72: /* original 2148, guest PC 0x0c0c1e72 */
if(!s->budget--) { s->failed_pc=0x0c0c1e72u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c0c1e74;
P_0c0c1e74: /* original 894f, guest PC 0x0c0c1e74 */
if(!s->budget--) { s->failed_pc=0x0c0c1e74u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1f16; }
goto P_0c0c1e76;
P_0c0c1e76: /* original 85ea, guest PC 0x0c0c1e76 */
if(!s->budget--) { s->failed_pc=0x0c0c1e76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+20,2);
goto P_0c0c1e78;
P_0c0c1e78: /* original e800, guest PC 0x0c0c1e78 */
if(!s->budget--) { s->failed_pc=0x0c0c1e78u; return 0; }
r[8]=0x00000000u;
goto P_0c0c1e7a;
P_0c0c1e7a: /* original d235, guest PC 0x0c0c1e7a */
if(!s->budget--) { s->failed_pc=0x0c0c1e7au; return 0; }
r[2]=read(ram,0x0c0c1f50u,4);
goto P_0c0c1e7c;
P_0c0c1e7c: /* original ea78, guest PC 0x0c0c1e7c */
if(!s->budget--) { s->failed_pc=0x0c0c1e7cu; return 0; }
r[10]=0x00000078u;
goto P_0c0c1e7e;
P_0c0c1e7e: /* original 6303, guest PC 0x0c0c1e7e */
if(!s->budget--) { s->failed_pc=0x0c0c1e7eu; return 0; }
r[3]=r[0];
goto P_0c0c1e80;
P_0c0c1e80: /* original 435a, guest PC 0x0c0c1e80 */
if(!s->budget--) { s->failed_pc=0x0c0c1e80u; return 0; }
r[53]=r[3];
goto P_0c0c1e82;
P_0c0c1e82: /* original f228, guest PC 0x0c0c1e82 */
if(!s->budget--) { s->failed_pc=0x0c0c1e82u; return 0; }
vf3_matrix_load(s,ram,2,r[2]);
goto P_0c0c1e84;
P_0c0c1e84: /* original 6b83, guest PC 0x0c0c1e84 */
if(!s->budget--) { s->failed_pc=0x0c0c1e84u; return 0; }
r[11]=r[8];
goto P_0c0c1e86;
P_0c0c1e86: /* original 54e3, guest PC 0x0c0c1e86 */
if(!s->budget--) { s->failed_pc=0x0c0c1e86u; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c0c1e88;
P_0c0c1e88: /* original 3ba2, guest PC 0x0c0c1e88 */
if(!s->budget--) { s->failed_pc=0x0c0c1e88u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>=r[10])!=0);
goto P_0c0c1e8a;
P_0c0c1e8a: /* original f32d, guest PC 0x0c0c1e8a */
if(!s->budget--) { s->failed_pc=0x0c0c1e8au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c1e8c;
P_0c0c1e8c: /* original 6d43, guest PC 0x0c0c1e8c */
if(!s->budget--) { s->failed_pc=0x0c0c1e8cu; return 0; }
r[13]=r[4];
goto P_0c0c1e8e;
P_0c0c1e8e: /* original f322, guest PC 0x0c0c1e8e */
if(!s->budget--) { s->failed_pc=0x0c0c1e8eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c0c1e90;
P_0c0c1e90: /* original ff3a, guest PC 0x0c0c1e90 */
if(!s->budget--) { s->failed_pc=0x0c0c1e90u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0c1e92;
P_0c0c1e92: /* original 85eb, guest PC 0x0c0c1e92 */
if(!s->budget--) { s->failed_pc=0x0c0c1e92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0c1e94;
P_0c0c1e94: /* original d12f, guest PC 0x0c0c1e94 */
if(!s->budget--) { s->failed_pc=0x0c0c1e94u; return 0; }
r[1]=read(ram,0x0c0c1f54u,4);
goto P_0c0c1e96;
P_0c0c1e96: /* original 6303, guest PC 0x0c0c1e96 */
if(!s->budget--) { s->failed_pc=0x0c0c1e96u; return 0; }
r[3]=r[0];
goto P_0c0c1e98;
P_0c0c1e98: /* original 435a, guest PC 0x0c0c1e98 */
if(!s->budget--) { s->failed_pc=0x0c0c1e98u; return 0; }
r[53]=r[3];
goto P_0c0c1e9a;
P_0c0c1e9a: /* original f218, guest PC 0x0c0c1e9a */
if(!s->budget--) { s->failed_pc=0x0c0c1e9au; return 0; }
vf3_matrix_load(s,ram,2,r[1]);
goto P_0c0c1e9c;
P_0c0c1e9c: /* original c72e, guest PC 0x0c0c1e9c */
if(!s->budget--) { s->failed_pc=0x0c0c1e9cu; return 0; }
r[0]=0x0c0c1f58u;
goto P_0c0c1e9e;
P_0c0c1e9e: /* original fcec, guest PC 0x0c0c1e9e */
if(!s->budget--) { s->failed_pc=0x0c0c1e9eu; return 0; }
vf3_matrix_move(s,12,14);
goto P_0c0c1ea0;
P_0c0c1ea0: /* original f32d, guest PC 0x0c0c1ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ea0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c1ea2;
P_0c0c1ea2: /* original fd3c, guest PC 0x0c0c1ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ea2u; return 0; }
vf3_matrix_move(s,13,3);
goto P_0c0c1ea4;
P_0c0c1ea4: /* original fd22, guest PC 0x0c0c1ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ea4u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[2],r[18],'*');
goto P_0c0c1ea6;
P_0c0c1ea6: /* original f308, guest PC 0x0c0c1ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ea6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c1ea8;
P_0c0c1ea8: /* original 8d2e, guest PC 0x0c0c1ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ea8u; return 0; }
cond=r[17]&1u;
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'+');
if(cond) { goto P_0c0c1f08; }
goto P_0c0c1eac;
P_0c0c1eaa: /* original fc30, guest PC 0x0c0c1eaa */
if(!s->budget--) { s->failed_pc=0x0c0c1eaau; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'+');
goto P_0c0c1eac;
P_0c0c1eac: /* original e910, guest PC 0x0c0c1eac */
if(!s->budget--) { s->failed_pc=0x0c0c1eacu; return 0; }
r[9]=0x00000010u;
goto P_0c0c1eae;
P_0c0c1eae: /* original 60d1, guest PC 0x0c0c1eae */
if(!s->budget--) { s->failed_pc=0x0c0c1eaeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[0]=tmp;
goto P_0c0c1eb0;
P_0c0c1eb0: /* original 600d, guest PC 0x0c0c1eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c1eb0u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c1eb2;
P_0c0c1eb2: /* original c801, guest PC 0x0c0c1eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c1eb2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0c1eb4;
P_0c0c1eb4: /* original 8924, guest PC 0x0c0c1eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c1eb4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1f00; }
goto P_0c0c1eb6;
P_0c0c1eb6: /* original 65d3, guest PC 0x0c0c1eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c1eb6u; return 0; }
r[5]=r[13];
goto P_0c0c1eb8;
P_0c0c1eb8: /* original d228, guest PC 0x0c0c1eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c1eb8u; return 0; }
r[2]=read(ram,0x0c0c1f5cu,4);
goto P_0c0c1eba;
P_0c0c1eba: /* original 64f3, guest PC 0x0c0c1eba */
if(!s->budget--) { s->failed_pc=0x0c0c1ebau; return 0; }
r[4]=r[15];
goto P_0c0c1ebc;
P_0c0c1ebc: /* original e634, guest PC 0x0c0c1ebc */
if(!s->budget--) { s->failed_pc=0x0c0c1ebcu; return 0; }
r[6]=0x00000034u;
goto P_0c0c1ebe;
P_0c0c1ebe: /* original 7510, guest PC 0x0c0c1ebe */
if(!s->budget--) { s->failed_pc=0x0c0c1ebeu; return 0; }
r[5]+=0x00000010u;
goto P_0c0c1ec0;
P_0c0c1ec0: /* original 420b, guest PC 0x0c0c1ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ec0u; return 0; }
target=r[2];
r[16]=0x0c0c1ec4u;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1ec4u) { target=s->pc; goto dispatch; }
goto P_0c0c1ec4;
P_0c0c1ec2: /* original 7404, guest PC 0x0c0c1ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ec2u; return 0; }
r[4]+=0x00000004u;
goto P_0c0c1ec4;
P_0c0c1ec4: /* original e008, guest PC 0x0c0c1ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ec4u; return 0; }
r[0]=0x00000008u;
goto P_0c0c1ec6;
P_0c0c1ec6: /* original f3f8, guest PC 0x0c0c1ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ec6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0c1ec8;
P_0c0c1ec8: /* original f2f6, guest PC 0x0c0c1ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ec8u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c1eca;
P_0c0c1eca: /* original e008, guest PC 0x0c0c1eca */
if(!s->budget--) { s->failed_pc=0x0c0c1ecau; return 0; }
r[0]=0x00000008u;
goto P_0c0c1ecc;
P_0c0c1ecc: /* original f231, guest PC 0x0c0c1ecc */
if(!s->budget--) { s->failed_pc=0x0c0c1eccu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0c1ece;
P_0c0c1ece: /* original ff27, guest PC 0x0c0c1ece */
if(!s->budget--) { s->failed_pc=0x0c0c1eceu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c1ed0;
P_0c0c1ed0: /* original e00c, guest PC 0x0c0c1ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ed0u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1ed2;
P_0c0c1ed2: /* original f2f6, guest PC 0x0c0c1ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ed2u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c1ed4;
P_0c0c1ed4: /* original e00c, guest PC 0x0c0c1ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ed4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1ed6;
P_0c0c1ed6: /* original f2d0, guest PC 0x0c0c1ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ed6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[13],r[18],'+');
goto P_0c0c1ed8;
P_0c0c1ed8: /* original ff27, guest PC 0x0c0c1ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ed8u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c1eda;
P_0c0c1eda: /* original e010, guest PC 0x0c0c1eda */
if(!s->budget--) { s->failed_pc=0x0c0c1edau; return 0; }
r[0]=0x00000010u;
goto P_0c0c1edc;
P_0c0c1edc: /* original ffe7, guest PC 0x0c0c1edc */
if(!s->budget--) { s->failed_pc=0x0c0c1edcu; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c0c1ede;
P_0c0c1ede: /* original 63d1, guest PC 0x0c0c1ede */
if(!s->budget--) { s->failed_pc=0x0c0c1edeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[3]=tmp;
goto P_0c0c1ee0;
P_0c0c1ee0: /* original 633d, guest PC 0x0c0c1ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ee0u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c1ee2;
P_0c0c1ee2: /* original 2398, guest PC 0x0c0c1ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ee2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c0c1ee4;
P_0c0c1ee4: /* original 8901, guest PC 0x0c0c1ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ee4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1eea; }
goto P_0c0c1ee6;
P_0c0c1ee6: /* original e010, guest PC 0x0c0c1ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ee6u; return 0; }
r[0]=0x00000010u;
goto P_0c0c1ee8;
P_0c0c1ee8: /* original ffc7, guest PC 0x0c0c1ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ee8u; return 0; }
vf3_matrix_store(s,ram,12,r[15]+r[0]);
goto P_0c0c1eea;
P_0c0c1eea: /* original 60d1, guest PC 0x0c0c1eea */
if(!s->budget--) { s->failed_pc=0x0c0c1eeau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[0]=tmp;
goto P_0c0c1eec;
P_0c0c1eec: /* original 600d, guest PC 0x0c0c1eec */
if(!s->budget--) { s->failed_pc=0x0c0c1eecu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c1eee;
P_0c0c1eee: /* original c820, guest PC 0x0c0c1eee */
if(!s->budget--) { s->failed_pc=0x0c0c1eeeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0c1ef0;
P_0c0c1ef0: /* original 8b01, guest PC 0x0c0c1ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ef0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1ef6; }
goto P_0c0c1ef2;
P_0c0c1ef2: /* original e034, guest PC 0x0c0c1ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ef2u; return 0; }
r[0]=0x00000034u;
goto P_0c0c1ef4;
P_0c0c1ef4: /* original fff7, guest PC 0x0c0c1ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ef4u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0c1ef6;
P_0c0c1ef6: /* original d31a, guest PC 0x0c0c1ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ef6u; return 0; }
r[3]=read(ram,0x0c0c1f60u,4);
goto P_0c0c1ef8;
P_0c0c1ef8: /* original 64f3, guest PC 0x0c0c1ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ef8u; return 0; }
r[4]=r[15];
goto P_0c0c1efa;
P_0c0c1efa: /* original 430b, guest PC 0x0c0c1efa */
if(!s->budget--) { s->failed_pc=0x0c0c1efau; return 0; }
target=r[3];
r[16]=0x0c0c1efeu;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1efeu) { target=s->pc; goto dispatch; }
goto P_0c0c1efe;
P_0c0c1efc: /* original 7404, guest PC 0x0c0c1efc */
if(!s->budget--) { s->failed_pc=0x0c0c1efcu; return 0; }
r[4]+=0x00000004u;
goto P_0c0c1efe;
P_0c0c1efe: /* original 7801, guest PC 0x0c0c1efe */
if(!s->budget--) { s->failed_pc=0x0c0c1efeu; return 0; }
r[8]+=0x00000001u;
goto P_0c0c1f00;
P_0c0c1f00: /* original 7b01, guest PC 0x0c0c1f00 */
if(!s->budget--) { s->failed_pc=0x0c0c1f00u; return 0; }
r[11]+=0x00000001u;
goto P_0c0c1f02;
P_0c0c1f02: /* original 3ba2, guest PC 0x0c0c1f02 */
if(!s->budget--) { s->failed_pc=0x0c0c1f02u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>=r[10])!=0);
goto P_0c0c1f04;
P_0c0c1f04: /* original 8fd3, guest PC 0x0c0c1f04 */
if(!s->budget--) { s->failed_pc=0x0c0c1f04u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000044u;
if(!cond) { goto P_0c0c1eae; }
goto P_0c0c1f08;
P_0c0c1f06: /* original 7d44, guest PC 0x0c0c1f06 */
if(!s->budget--) { s->failed_pc=0x0c0c1f06u; return 0; }
r[13]+=0x00000044u;
goto P_0c0c1f08;
P_0c0c1f08: /* original e028, guest PC 0x0c0c1f08 */
if(!s->budget--) { s->failed_pc=0x0c0c1f08u; return 0; }
r[0]=0x00000028u;
goto P_0c0c1f0a;
P_0c0c1f0a: /* original 0e85, guest PC 0x0c0c1f0a */
if(!s->budget--) { s->failed_pc=0x0c0c1f0au; return 0; }
write(ram,r[14]+r[0],r[8],2);
goto P_0c0c1f0c;
P_0c0c1f0c: /* original e022, guest PC 0x0c0c1f0c */
if(!s->budget--) { s->failed_pc=0x0c0c1f0cu; return 0; }
r[0]=0x00000022u;
goto P_0c0c1f0e;
P_0c0c1f0e: /* original 02ed, guest PC 0x0c0c1f0e */
if(!s->budget--) { s->failed_pc=0x0c0c1f0eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c1f10;
P_0c0c1f10: /* original d314, guest PC 0x0c0c1f10 */
if(!s->budget--) { s->failed_pc=0x0c0c1f10u; return 0; }
r[3]=read(ram,0x0c0c1f64u,4);
goto P_0c0c1f12;
P_0c0c1f12: /* original 2239, guest PC 0x0c0c1f12 */
if(!s->budget--) { s->failed_pc=0x0c0c1f12u; return 0; }
r[2]&=r[3];
goto P_0c0c1f14;
P_0c0c1f14: /* original 0e25, guest PC 0x0c0c1f14 */
if(!s->budget--) { s->failed_pc=0x0c0c1f14u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0c1f16;
P_0c0c1f16: /* original 7f38, guest PC 0x0c0c1f16 */
if(!s->budget--) { s->failed_pc=0x0c0c1f16u; return 0; }
r[15]+=0x00000038u;
goto P_0c0c1f18;
P_0c0c1f18: /* original 4f26, guest PC 0x0c0c1f18 */
if(!s->budget--) { s->failed_pc=0x0c0c1f18u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c1f1a;
P_0c0c1f1a: /* original fcf9, guest PC 0x0c0c1f1a */
if(!s->budget--) { s->failed_pc=0x0c0c1f1au; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1f1c;
P_0c0c1f1c: /* original fdf9, guest PC 0x0c0c1f1c */
if(!s->budget--) { s->failed_pc=0x0c0c1f1cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1f1e;
P_0c0c1f1e: /* original fef9, guest PC 0x0c0c1f1e */
if(!s->budget--) { s->failed_pc=0x0c0c1f1eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1f20;
P_0c0c1f20: /* original fff9, guest PC 0x0c0c1f20 */
if(!s->budget--) { s->failed_pc=0x0c0c1f20u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1f22;
P_0c0c1f22: /* original 68f6, guest PC 0x0c0c1f22 */
if(!s->budget--) { s->failed_pc=0x0c0c1f22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c1f24;
P_0c0c1f24: /* original 69f6, guest PC 0x0c0c1f24 */
if(!s->budget--) { s->failed_pc=0x0c0c1f24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c1f26;
P_0c0c1f26: /* original 6af6, guest PC 0x0c0c1f26 */
if(!s->budget--) { s->failed_pc=0x0c0c1f26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c1f28;
P_0c0c1f28: /* original 6bf6, guest PC 0x0c0c1f28 */
if(!s->budget--) { s->failed_pc=0x0c0c1f28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c1f2a;
P_0c0c1f2a: /* original 6cf6, guest PC 0x0c0c1f2a */
if(!s->budget--) { s->failed_pc=0x0c0c1f2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c1f2c;
P_0c0c1f2c: /* original 6df6, guest PC 0x0c0c1f2c */
if(!s->budget--) { s->failed_pc=0x0c0c1f2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c1f2e;
P_0c0c1f2e: /* original 000b, guest PC 0x0c0c1f2e */
if(!s->budget--) { s->failed_pc=0x0c0c1f2eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c1f30: /* original 6ef6, guest PC 0x0c0c1f30 */
if(!s->budget--) { s->failed_pc=0x0c0c1f30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c1f32u,s,ram);
P_0c0c2bb4: /* original 4f22, guest PC 0x0c0c2bb4 */
if(!s->budget--) { s->failed_pc=0x0c0c2bb4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c2bb6;
P_0c0c2bb6: /* original de2b, guest PC 0x0c0c2bb6 */
if(!s->budget--) { s->failed_pc=0x0c0c2bb6u; return 0; }
r[14]=read(ram,0x0c0c2c64u,4);
goto P_0c0c2bb8;
P_0c0c2bb8: /* original 9038, guest PC 0x0c0c2bb8 */
if(!s->budget--) { s->failed_pc=0x0c0c2bb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2c2cu,2);
goto P_0c0c2bba;
P_0c0c2bba: /* original 4f12, guest PC 0x0c0c2bba */
if(!s->budget--) { s->failed_pc=0x0c0c2bbau; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c2bbc;
P_0c0c2bbc: /* original 00ee, guest PC 0x0c0c2bbc */
if(!s->budget--) { s->failed_pc=0x0c0c2bbcu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0c2bbe;
P_0c0c2bbe: /* original 88ff, guest PC 0x0c0c2bbe */
if(!s->budget--) { s->failed_pc=0x0c0c2bbeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c2bc0;
P_0c0c2bc0: /* original 7ff4, guest PC 0x0c0c2bc0 */
if(!s->budget--) { s->failed_pc=0x0c0c2bc0u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c2bc2;
P_0c0c2bc2: /* original 8d02, guest PC 0x0c0c2bc2 */
if(!s->budget--) { s->failed_pc=0x0c0c2bc2u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0c2bca; }
goto P_0c0c2bc6;
P_0c0c2bc4: /* original 6403, guest PC 0x0c0c2bc4 */
if(!s->budget--) { s->failed_pc=0x0c0c2bc4u; return 0; }
r[4]=r[0];
goto P_0c0c2bc6;
P_0c0c2bc6: /* original bee1, guest PC 0x0c0c2bc6 */
if(!s->budget--) { s->failed_pc=0x0c0c2bc6u; return 0; }
target=0x0c0c298cu; r[16]=0x0c0c2bcau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2bcau) { target=s->pc; goto dispatch; }
goto P_0c0c2bca;
P_0c0c2bc8: /* original 0009, guest PC 0x0c0c2bc8 */
if(!s->budget--) { s->failed_pc=0x0c0c2bc8u; return 0; }
goto P_0c0c2bca;
P_0c0c2bca: /* original 9030, guest PC 0x0c0c2bca */
if(!s->budget--) { s->failed_pc=0x0c0c2bcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2c2eu,2);
goto P_0c0c2bcc;
P_0c0c2bcc: /* original e320, guest PC 0x0c0c2bcc */
if(!s->budget--) { s->failed_pc=0x0c0c2bccu; return 0; }
r[3]=0x00000020u;
goto P_0c0c2bce;
P_0c0c2bce: /* original 04ee, guest PC 0x0c0c2bce */
if(!s->budget--) { s->failed_pc=0x0c0c2bceu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c2bd0;
P_0c0c2bd0: /* original 3437, guest PC 0x0c0c2bd0 */
if(!s->budget--) { s->failed_pc=0x0c0c2bd0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c0c2bd2;
P_0c0c2bd2: /* original 8905, guest PC 0x0c0c2bd2 */
if(!s->budget--) { s->failed_pc=0x0c0c2bd2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2be0; }
goto P_0c0c2bd4;
P_0c0c2bd4: /* original 6043, guest PC 0x0c0c2bd4 */
if(!s->budget--) { s->failed_pc=0x0c0c2bd4u; return 0; }
r[0]=r[4];
goto P_0c0c2bd6;
P_0c0c2bd6: /* original 88ff, guest PC 0x0c0c2bd6 */
if(!s->budget--) { s->failed_pc=0x0c0c2bd6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c2bd8;
P_0c0c2bd8: /* original 8902, guest PC 0x0c0c2bd8 */
if(!s->budget--) { s->failed_pc=0x0c0c2bd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2be0; }
goto P_0c0c2bda;
P_0c0c2bda: /* original d223, guest PC 0x0c0c2bda */
if(!s->budget--) { s->failed_pc=0x0c0c2bdau; return 0; }
r[2]=read(ram,0x0c0c2c68u,4);
goto P_0c0c2bdc;
P_0c0c2bdc: /* original 420b, guest PC 0x0c0c2bdc */
if(!s->budget--) { s->failed_pc=0x0c0c2bdcu; return 0; }
target=r[2];
r[16]=0x0c0c2be0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2be0u) { target=s->pc; goto dispatch; }
goto P_0c0c2be0;
P_0c0c2bde: /* original 0009, guest PC 0x0c0c2bde */
if(!s->budget--) { s->failed_pc=0x0c0c2bdeu; return 0; }
goto P_0c0c2be0;
P_0c0c2be0: /* original 9026, guest PC 0x0c0c2be0 */
if(!s->budget--) { s->failed_pc=0x0c0c2be0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2c30u,2);
goto P_0c0c2be2;
P_0c0c2be2: /* original 00ee, guest PC 0x0c0c2be2 */
if(!s->budget--) { s->failed_pc=0x0c0c2be2u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0c2be4;
P_0c0c2be4: /* original 88ff, guest PC 0x0c0c2be4 */
if(!s->budget--) { s->failed_pc=0x0c0c2be4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c2be6;
P_0c0c2be6: /* original 8d0d, guest PC 0x0c0c2be6 */
if(!s->budget--) { s->failed_pc=0x0c0c2be6u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0c2c04; }
goto P_0c0c2bea;
P_0c0c2be8: /* original 6403, guest PC 0x0c0c2be8 */
if(!s->budget--) { s->failed_pc=0x0c0c2be8u; return 0; }
r[4]=r[0];
goto P_0c0c2bea;
P_0c0c2bea: /* original 9021, guest PC 0x0c0c2bea */
if(!s->budget--) { s->failed_pc=0x0c0c2beau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2c30u,2);
goto P_0c0c2bec;
P_0c0c2bec: /* original 6243, guest PC 0x0c0c2bec */
if(!s->budget--) { s->failed_pc=0x0c0c2becu; return 0; }
r[2]=r[4];
goto P_0c0c2bee;
P_0c0c2bee: /* original 72ff, guest PC 0x0c0c2bee */
if(!s->budget--) { s->failed_pc=0x0c0c2beeu; return 0; }
r[2]+=0xffffffffu;
goto P_0c0c2bf0;
P_0c0c2bf0: /* original 4421, guest PC 0x0c0c2bf0 */
if(!s->budget--) { s->failed_pc=0x0c0c2bf0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]=(uint32_t)((int32_t)r[4]>>1);
goto P_0c0c2bf2;
P_0c0c2bf2: /* original 0e26, guest PC 0x0c0c2bf2 */
if(!s->budget--) { s->failed_pc=0x0c0c2bf2u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c2bf4;
P_0c0c2bf4: /* original 931d, guest PC 0x0c0c2bf4 */
if(!s->budget--) { s->failed_pc=0x0c0c2bf4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2c32u,2);
goto P_0c0c2bf6;
P_0c0c2bf6: /* original 4408, guest PC 0x0c0c2bf6 */
if(!s->budget--) { s->failed_pc=0x0c0c2bf6u; return 0; }
r[4]<<=2;
goto P_0c0c2bf8;
P_0c0c2bf8: /* original d21c, guest PC 0x0c0c2bf8 */
if(!s->budget--) { s->failed_pc=0x0c0c2bf8u; return 0; }
r[2]=read(ram,0x0c0c2c6cu,4);
goto P_0c0c2bfa;
P_0c0c2bfa: /* original 2439, guest PC 0x0c0c2bfa */
if(!s->budget--) { s->failed_pc=0x0c0c2bfau; return 0; }
r[4]&=r[3];
goto P_0c0c2bfc;
P_0c0c2bfc: /* original 901a, guest PC 0x0c0c2bfc */
if(!s->budget--) { s->failed_pc=0x0c0c2bfcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2c34u,2);
goto P_0c0c2bfe;
P_0c0c2bfe: /* original 0427, guest PC 0x0c0c2bfe */
if(!s->budget--) { s->failed_pc=0x0c0c2bfeu; return 0; }
r[19]=r[4]*r[2];
goto P_0c0c2c00;
P_0c0c2c00: /* original 041a, guest PC 0x0c0c2c00 */
if(!s->budget--) { s->failed_pc=0x0c0c2c00u; return 0; }
r[4]=r[19];
goto P_0c0c2c02;
P_0c0c2c02: /* original 0e46, guest PC 0x0c0c2c02 */
if(!s->budget--) { s->failed_pc=0x0c0c2c02u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c2c04;
P_0c0c2c04: /* original 62e3, guest PC 0x0c0c2c04 */
if(!s->budget--) { s->failed_pc=0x0c0c2c04u; return 0; }
r[2]=r[14];
goto P_0c0c2c06;
P_0c0c2c06: /* original 63e3, guest PC 0x0c0c2c06 */
if(!s->budget--) { s->failed_pc=0x0c0c2c06u; return 0; }
r[3]=r[14];
goto P_0c0c2c08;
P_0c0c2c08: /* original 722c, guest PC 0x0c0c2c08 */
if(!s->budget--) { s->failed_pc=0x0c0c2c08u; return 0; }
r[2]+=0x0000002cu;
goto P_0c0c2c0a;
P_0c0c2c0a: /* original 1fe2, guest PC 0x0c0c2c0a */
if(!s->budget--) { s->failed_pc=0x0c0c2c0au; return 0; }
write(ram,r[15]+8,r[14],4);
goto P_0c0c2c0c;
P_0c0c2c0c: /* original 7358, guest PC 0x0c0c2c0c */
if(!s->budget--) { s->failed_pc=0x0c0c2c0cu; return 0; }
r[3]+=0x00000058u;
goto P_0c0c2c0e;
P_0c0c2c0e: /* original 1f31, guest PC 0x0c0c2c0e */
if(!s->budget--) { s->failed_pc=0x0c0c2c0eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c2c10;
P_0c0c2c10: /* original 2f22, guest PC 0x0c0c2c10 */
if(!s->budget--) { s->failed_pc=0x0c0c2c10u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c2c12;
P_0c0c2c12: /* original 9410, guest PC 0x0c0c2c12 */
if(!s->budget--) { s->failed_pc=0x0c0c2c12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2c36u,2);
goto P_0c0c2c14;
P_0c0c2c14: /* original b8b7, guest PC 0x0c0c2c14 */
if(!s->budget--) { s->failed_pc=0x0c0c2c14u; return 0; }
target=0x0c0c1d86u; r[16]=0x0c0c2c18u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2c18u) { target=s->pc; goto dispatch; }
goto P_0c0c2c18;
P_0c0c2c16: /* original 34ec, guest PC 0x0c0c2c16 */
if(!s->budget--) { s->failed_pc=0x0c0c2c16u; return 0; }
r[4]+=r[14];
goto P_0c0c2c18;
P_0c0c2c18: /* original b8b5, guest PC 0x0c0c2c18 */
if(!s->budget--) { s->failed_pc=0x0c0c2c18u; return 0; }
target=0x0c0c1d86u; r[16]=0x0c0c2c1cu;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2c1cu) { target=s->pc; goto dispatch; }
goto P_0c0c2c1c;
P_0c0c2c1a: /* original 54f1, guest PC 0x0c0c2c1a */
if(!s->budget--) { s->failed_pc=0x0c0c2c1au; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c2c1c;
P_0c0c2c1c: /* original b8b3, guest PC 0x0c0c2c1c */
if(!s->budget--) { s->failed_pc=0x0c0c2c1cu; return 0; }
target=0x0c0c1d86u; r[16]=0x0c0c2c20u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2c20u) { target=s->pc; goto dispatch; }
goto P_0c0c2c20;
P_0c0c2c1e: /* original 64f2, guest PC 0x0c0c2c1e */
if(!s->budget--) { s->failed_pc=0x0c0c2c1eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c2c20;
P_0c0c2c20: /* original 54f2, guest PC 0x0c0c2c20 */
if(!s->budget--) { s->failed_pc=0x0c0c2c20u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0c2c22;
P_0c0c2c22: /* original 7f0c, guest PC 0x0c0c2c22 */
if(!s->budget--) { s->failed_pc=0x0c0c2c22u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c2c24;
P_0c0c2c24: /* original 4f16, guest PC 0x0c0c2c24 */
if(!s->budget--) { s->failed_pc=0x0c0c2c24u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c2c26;
P_0c0c2c26: /* original 4f26, guest PC 0x0c0c2c26 */
if(!s->budget--) { s->failed_pc=0x0c0c2c26u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c2c28;
P_0c0c2c28: /* original a8ad, guest PC 0x0c0c2c28 */
if(!s->budget--) { s->failed_pc=0x0c0c2c28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c1d86;
P_0c0c2c2a: /* original 6ef6, guest PC 0x0c0c2c2a */
if(!s->budget--) { s->failed_pc=0x0c0c2c2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c2c2cu,s,ram);
P_0c0c4eba: /* original 4f22, guest PC 0x0c0c4eba */
if(!s->budget--) { s->failed_pc=0x0c0c4ebau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c4ebc;
P_0c0c4ebc: /* original 4f12, guest PC 0x0c0c4ebc */
if(!s->budget--) { s->failed_pc=0x0c0c4ebcu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c4ebe;
P_0c0c4ebe: /* original 7ff4, guest PC 0x0c0c4ebe */
if(!s->budget--) { s->failed_pc=0x0c0c4ebeu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c4ec0;
P_0c0c4ec0: /* original 1f41, guest PC 0x0c0c4ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ec0u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0c4ec2;
P_0c0c4ec2: /* original db28, guest PC 0x0c0c4ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ec2u; return 0; }
r[11]=read(ram,0x0c0c4f64u,4);
goto P_0c0c4ec4;
P_0c0c4ec4: /* original d728, guest PC 0x0c0c4ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ec4u; return 0; }
r[7]=read(ram,0x0c0c4f68u,4);
goto P_0c0c4ec6;
P_0c0c4ec6: /* original 64b2, guest PC 0x0c0c4ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ec6u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c0c4ec8;
P_0c0c4ec8: /* original 84b9, guest PC 0x0c0c4ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ec8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+9,1);
goto P_0c0c4eca;
P_0c0c4eca: /* original 6343, guest PC 0x0c0c4eca */
if(!s->budget--) { s->failed_pc=0x0c0c4ecau; return 0; }
r[3]=r[4];
goto P_0c0c4ecc;
P_0c0c4ecc: /* original 2379, guest PC 0x0c0c4ecc */
if(!s->budget--) { s->failed_pc=0x0c0c4eccu; return 0; }
r[3]&=r[7];
goto P_0c0c4ece;
P_0c0c4ece: /* original 2338, guest PC 0x0c0c4ece */
if(!s->budget--) { s->failed_pc=0x0c0c4eceu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c4ed0;
P_0c0c4ed0: /* original 2f32, guest PC 0x0c0c4ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ed0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c4ed2;
P_0c0c4ed2: /* original 660c, guest PC 0x0c0c4ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ed2u; return 0; }
r[6]=r[0]&255u;
goto P_0c0c4ed4;
P_0c0c4ed4: /* original 8d05, guest PC 0x0c0c4ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ed4u; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[11]+4,4);
if(cond) { goto P_0c0c4ee2; }
goto P_0c0c4ed8;
P_0c0c4ed6: /* original 55b1, guest PC 0x0c0c4ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ed6u; return 0; }
r[5]=read(ram,r[11]+4,4);
goto P_0c0c4ed8;
P_0c0c4ed8: /* original d324, guest PC 0x0c0c4ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ed8u; return 0; }
r[3]=read(ram,0x0c0c4f6cu,4);
goto P_0c0c4eda;
P_0c0c4eda: /* original 2358, guest PC 0x0c0c4eda */
if(!s->budget--) { s->failed_pc=0x0c0c4edau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0c4edc;
P_0c0c4edc: /* original 8901, guest PC 0x0c0c4edc */
if(!s->budget--) { s->failed_pc=0x0c0c4edcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4ee2; }
goto P_0c0c4ede;
P_0c0c4ede: /* original a099, guest PC 0x0c0c4ede */
if(!s->budget--) { s->failed_pc=0x0c0c4edeu; return 0; }
goto P_0c0c5014;
P_0c0c4ee0: /* original 0009, guest PC 0x0c0c4ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ee0u; return 0; }
goto P_0c0c4ee2;
P_0c0c4ee2: /* original 9232, guest PC 0x0c0c4ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ee2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f4au,2);
goto P_0c0c4ee4;
P_0c0c4ee4: /* original 2249, guest PC 0x0c0c4ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ee4u; return 0; }
r[2]&=r[4];
goto P_0c0c4ee6;
P_0c0c4ee6: /* original 2228, guest PC 0x0c0c4ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ee6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c4ee8;
P_0c0c4ee8: /* original 8d02, guest PC 0x0c0c4ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ee8u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[2],4);
if(cond) { goto P_0c0c4ef0; }
goto P_0c0c4eec;
P_0c0c4eea: /* original 2f22, guest PC 0x0c0c4eea */
if(!s->budget--) { s->failed_pc=0x0c0c4eeau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c4eec;
P_0c0c4eec: /* original a092, guest PC 0x0c0c4eec */
if(!s->budget--) { s->failed_pc=0x0c0c4eecu; return 0; }
goto P_0c0c5014;
P_0c0c4eee: /* original 0009, guest PC 0x0c0c4eee */
if(!s->budget--) { s->failed_pc=0x0c0c4eeeu; return 0; }
goto P_0c0c4ef0;
P_0c0c4ef0: /* original e320, guest PC 0x0c0c4ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ef0u; return 0; }
r[3]=0x00000020u;
goto P_0c0c4ef2;
P_0c0c4ef2: /* original 3637, guest PC 0x0c0c4ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ef2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[3])!=0);
goto P_0c0c4ef4;
P_0c0c4ef4: /* original 8b01, guest PC 0x0c0c4ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ef4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4efa; }
goto P_0c0c4ef6;
P_0c0c4ef6: /* original a08d, guest PC 0x0c0c4ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ef6u; return 0; }
goto P_0c0c5014;
P_0c0c4ef8: /* original 0009, guest PC 0x0c0c4ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ef8u; return 0; }
goto P_0c0c4efa;
P_0c0c4efa: /* original d21d, guest PC 0x0c0c4efa */
if(!s->budget--) { s->failed_pc=0x0c0c4efau; return 0; }
r[2]=read(ram,0x0c0c4f70u,4);
goto P_0c0c4efc;
P_0c0c4efc: /* original 2248, guest PC 0x0c0c4efc */
if(!s->budget--) { s->failed_pc=0x0c0c4efcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0c4efe;
P_0c0c4efe: /* original 8b01, guest PC 0x0c0c4efe */
if(!s->budget--) { s->failed_pc=0x0c0c4efeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4f04; }
goto P_0c0c4f00;
P_0c0c4f00: /* original a088, guest PC 0x0c0c4f00 */
if(!s->budget--) { s->failed_pc=0x0c0c4f00u; return 0; }
goto P_0c0c5014;
P_0c0c4f02: /* original 0009, guest PC 0x0c0c4f02 */
if(!s->budget--) { s->failed_pc=0x0c0c4f02u; return 0; }
goto P_0c0c4f04;
P_0c0c4f04: /* original d31b, guest PC 0x0c0c4f04 */
if(!s->budget--) { s->failed_pc=0x0c0c4f04u; return 0; }
r[3]=read(ram,0x0c0c4f74u,4);
goto P_0c0c4f06;
P_0c0c4f06: /* original 2438, guest PC 0x0c0c4f06 */
if(!s->budget--) { s->failed_pc=0x0c0c4f06u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c4f08;
P_0c0c4f08: /* original 8903, guest PC 0x0c0c4f08 */
if(!s->budget--) { s->failed_pc=0x0c0c4f08u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4f12; }
goto P_0c0c4f0a;
P_0c0c4f0a: /* original 2578, guest PC 0x0c0c4f0a */
if(!s->budget--) { s->failed_pc=0x0c0c4f0au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[7])==0)!=0);
goto P_0c0c4f0c;
P_0c0c4f0c: /* original 8901, guest PC 0x0c0c4f0c */
if(!s->budget--) { s->failed_pc=0x0c0c4f0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4f12; }
goto P_0c0c4f0e;
P_0c0c4f0e: /* original a081, guest PC 0x0c0c4f0e */
if(!s->budget--) { s->failed_pc=0x0c0c4f0eu; return 0; }
goto P_0c0c5014;
P_0c0c4f10: /* original 0009, guest PC 0x0c0c4f10 */
if(!s->budget--) { s->failed_pc=0x0c0c4f10u; return 0; }
goto P_0c0c4f12;
P_0c0c4f12: /* original 901b, guest PC 0x0c0c4f12 */
if(!s->budget--) { s->failed_pc=0x0c0c4f12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f4cu,2);
goto P_0c0c4f14;
P_0c0c4f14: /* original da18, guest PC 0x0c0c4f14 */
if(!s->budget--) { s->failed_pc=0x0c0c4f14u; return 0; }
r[10]=read(ram,0x0c0c4f78u,4);
goto P_0c0c4f16;
P_0c0c4f16: /* original 00ad, guest PC 0x0c0c4f16 */
if(!s->budget--) { s->failed_pc=0x0c0c4f16u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c0c4f18;
P_0c0c4f18: /* original 88ff, guest PC 0x0c0c4f18 */
if(!s->budget--) { s->failed_pc=0x0c0c4f18u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c4f1a;
P_0c0c4f1a: /* original 8d7b, guest PC 0x0c0c4f1a */
if(!s->budget--) { s->failed_pc=0x0c0c4f1au; return 0; }
cond=r[17]&1u;
r[12]=r[0];
if(cond) { goto P_0c0c5014; }
goto P_0c0c4f1e;
P_0c0c4f1c: /* original 6c03, guest PC 0x0c0c4f1c */
if(!s->budget--) { s->failed_pc=0x0c0c4f1cu; return 0; }
r[12]=r[0];
goto P_0c0c4f1e;
P_0c0c4f1e: /* original d317, guest PC 0x0c0c4f1e */
if(!s->budget--) { s->failed_pc=0x0c0c4f1eu; return 0; }
r[3]=read(ram,0x0c0c4f7cu,4);
goto P_0c0c4f20;
P_0c0c4f20: /* original 6432, guest PC 0x0c0c4f20 */
if(!s->budget--) { s->failed_pc=0x0c0c4f20u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0c4f22;
P_0c0c4f22: /* original 854f, guest PC 0x0c0c4f22 */
if(!s->budget--) { s->failed_pc=0x0c0c4f22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c0c4f24;
P_0c0c4f24: /* original 6503, guest PC 0x0c0c4f24 */
if(!s->budget--) { s->failed_pc=0x0c0c4f24u; return 0; }
r[5]=r[0];
goto P_0c0c4f26;
P_0c0c4f26: /* original 854e, guest PC 0x0c0c4f26 */
if(!s->budget--) { s->failed_pc=0x0c0c4f26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+28,2);
goto P_0c0c4f28;
P_0c0c4f28: /* original 81f4, guest PC 0x0c0c4f28 */
if(!s->budget--) { s->failed_pc=0x0c0c4f28u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c0c4f2a;
P_0c0c4f2a: /* original 9010, guest PC 0x0c0c4f2a */
if(!s->budget--) { s->failed_pc=0x0c0c4f2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f4eu,2);
goto P_0c0c4f2c;
P_0c0c4f2c: /* original 9211, guest PC 0x0c0c4f2c */
if(!s->budget--) { s->failed_pc=0x0c0c4f2cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f52u,2);
goto P_0c0c4f2e;
P_0c0c4f2e: /* original 064d, guest PC 0x0c0c4f2e */
if(!s->budget--) { s->failed_pc=0x0c0c4f2eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c4f30;
P_0c0c4f30: /* original 900e, guest PC 0x0c0c4f30 */
if(!s->budget--) { s->failed_pc=0x0c0c4f30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f50u,2);
goto P_0c0c4f32;
P_0c0c4f32: /* original 3c20, guest PC 0x0c0c4f32 */
if(!s->budget--) { s->failed_pc=0x0c0c4f32u; return 0; }
r[17]=(r[17]&~1u)|((r[12]==r[2])!=0);
goto P_0c0c4f34;
P_0c0c4f34: /* original 04ad, guest PC 0x0c0c4f34 */
if(!s->budget--) { s->failed_pc=0x0c0c4f34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c0c4f36;
P_0c0c4f36: /* original 354c, guest PC 0x0c0c4f36 */
if(!s->budget--) { s->failed_pc=0x0c0c4f36u; return 0; }
r[5]+=r[4];
goto P_0c0c4f38;
P_0c0c4f38: /* original 8f22, guest PC 0x0c0c4f38 */
if(!s->budget--) { s->failed_pc=0x0c0c4f38u; return 0; }
cond=r[17]&1u;
r[5]=0u-r[5];
if(!cond) { goto P_0c0c4f80; }
goto P_0c0c4f3c;
P_0c0c4f3a: /* original 655b, guest PC 0x0c0c4f3a */
if(!s->budget--) { s->failed_pc=0x0c0c4f3au; return 0; }
r[5]=0u-r[5];
goto P_0c0c4f3c;
P_0c0c4f3c: /* original 940a, guest PC 0x0c0c4f3c */
if(!s->budget--) { s->failed_pc=0x0c0c4f3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f54u,2);
goto P_0c0c4f3e;
P_0c0c4f3e: /* original a020, guest PC 0x0c0c4f3e */
if(!s->budget--) { s->failed_pc=0x0c0c4f3eu; return 0; }
goto P_0c0c4f82;
P_0c0c4f40: /* original 0009, guest PC 0x0c0c4f40 */
if(!s->budget--) { s->failed_pc=0x0c0c4f40u; return 0; }
return vf3_matrix_family(0x0c0c4f42u,s,ram);
P_0c0c4f80: /* original 9451, guest PC 0x0c0c4f80 */
if(!s->budget--) { s->failed_pc=0x0c0c4f80u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5026u,2);
goto P_0c0c4f82;
P_0c0c4f82: /* original 6d5d, guest PC 0x0c0c4f82 */
if(!s->budget--) { s->failed_pc=0x0c0c4f82u; return 0; }
r[13]=r[5]&65535u;
goto P_0c0c4f84;
P_0c0c4f84: /* original 9351, guest PC 0x0c0c4f84 */
if(!s->budget--) { s->failed_pc=0x0c0c4f84u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c502au,2);
goto P_0c0c4f86;
P_0c0c4f86: /* original 0d47, guest PC 0x0c0c4f86 */
if(!s->budget--) { s->failed_pc=0x0c0c4f86u; return 0; }
r[19]=r[13]*r[4];
goto P_0c0c4f88;
P_0c0c4f88: /* original 944e, guest PC 0x0c0c4f88 */
if(!s->budget--) { s->failed_pc=0x0c0c4f88u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5028u,2);
goto P_0c0c4f8a;
P_0c0c4f8a: /* original 3637, guest PC 0x0c0c4f8a */
if(!s->budget--) { s->failed_pc=0x0c0c4f8au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[3])!=0);
goto P_0c0c4f8c;
P_0c0c4f8c: /* original 8f01, guest PC 0x0c0c4f8c */
if(!s->budget--) { s->failed_pc=0x0c0c4f8cu; return 0; }
cond=r[17]&1u;
r[13]=r[19];
if(!cond) { goto P_0c0c4f92; }
goto P_0c0c4f90;
P_0c0c4f8e: /* original 0d1a, guest PC 0x0c0c4f8e */
if(!s->budget--) { s->failed_pc=0x0c0c4f8eu; return 0; }
r[13]=r[19];
goto P_0c0c4f90;
P_0c0c4f90: /* original 944c, guest PC 0x0c0c4f90 */
if(!s->budget--) { s->failed_pc=0x0c0c4f90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c502cu,2);
goto P_0c0c4f92;
P_0c0c4f92: /* original d328, guest PC 0x0c0c4f92 */
if(!s->budget--) { s->failed_pc=0x0c0c4f92u; return 0; }
r[3]=read(ram,0x0c0c5034u,4);
goto P_0c0c4f94;
P_0c0c4f94: /* original 61d3, guest PC 0x0c0c4f94 */
if(!s->budget--) { s->failed_pc=0x0c0c4f94u; return 0; }
r[1]=r[13];
goto P_0c0c4f96;
P_0c0c4f96: /* original 430b, guest PC 0x0c0c4f96 */
if(!s->budget--) { s->failed_pc=0x0c0c4f96u; return 0; }
target=r[3];
r[16]=0x0c0c4f9au;
r[0]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c4f9au) { target=s->pc; goto dispatch; }
goto P_0c0c4f9a;
P_0c0c4f98: /* original 6043, guest PC 0x0c0c4f98 */
if(!s->budget--) { s->failed_pc=0x0c0c4f98u; return 0; }
r[0]=r[4];
goto P_0c0c4f9a;
P_0c0c4f9a: /* original 4621, guest PC 0x0c0c4f9a */
if(!s->budget--) { s->failed_pc=0x0c0c4f9au; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]=(uint32_t)((int32_t)r[6]>>1);
goto P_0c0c4f9c;
P_0c0c4f9c: /* original 6d03, guest PC 0x0c0c4f9c */
if(!s->budget--) { s->failed_pc=0x0c0c4f9cu; return 0; }
r[13]=r[0];
goto P_0c0c4f9e;
P_0c0c4f9e: /* original 2f62, guest PC 0x0c0c4f9e */
if(!s->budget--) { s->failed_pc=0x0c0c4f9eu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0c4fa0;
P_0c0c4fa0: /* original d325, guest PC 0x0c0c4fa0 */
if(!s->budget--) { s->failed_pc=0x0c0c4fa0u; return 0; }
r[3]=read(ram,0x0c0c5038u,4);
goto P_0c0c4fa2;
P_0c0c4fa2: /* original 430b, guest PC 0x0c0c4fa2 */
if(!s->budget--) { s->failed_pc=0x0c0c4fa2u; return 0; }
target=r[3];
r[16]=0x0c0c4fa6u;
r[4]=(uint32_t)(int32_t)(int16_t)r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c4fa6u) { target=s->pc; goto dispatch; }
goto P_0c0c4fa6;
P_0c0c4fa4: /* original 646f, guest PC 0x0c0c4fa4 */
if(!s->budget--) { s->failed_pc=0x0c0c4fa4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c0c4fa6;
P_0c0c4fa6: /* original c725, guest PC 0x0c0c4fa6 */
if(!s->budget--) { s->failed_pc=0x0c0c4fa6u; return 0; }
r[0]=0x0c0c503cu;
goto P_0c0c4fa8;
P_0c0c4fa8: /* original d325, guest PC 0x0c0c4fa8 */
if(!s->budget--) { s->failed_pc=0x0c0c4fa8u; return 0; }
r[3]=read(ram,0x0c0c5040u,4);
goto P_0c0c4faa;
P_0c0c4faa: /* original f508, guest PC 0x0c0c4faa */
if(!s->budget--) { s->failed_pc=0x0c0c4faau; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c4fac;
P_0c0c4fac: /* original f40c, guest PC 0x0c0c4fac */
if(!s->budget--) { s->failed_pc=0x0c0c4facu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0c4fae;
P_0c0c4fae: /* original 430b, guest PC 0x0c0c4fae */
if(!s->budget--) { s->failed_pc=0x0c0c4faeu; return 0; }
target=r[3];
r[16]=0x0c0c4fb2u;
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c4fb2u) { target=s->pc; goto dispatch; }
goto P_0c0c4fb2;
P_0c0c4fb0: /* original f452, guest PC 0x0c0c4fb0 */
if(!s->budget--) { s->failed_pc=0x0c0c4fb0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0c4fb2;
P_0c0c4fb2: /* original 640f, guest PC 0x0c0c4fb2 */
if(!s->budget--) { s->failed_pc=0x0c0c4fb2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0c4fb4;
P_0c0c4fb4: /* original 85f4, guest PC 0x0c0c4fb4 */
if(!s->budget--) { s->failed_pc=0x0c0c4fb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c0c4fb6;
P_0c0c4fb6: /* original d21f, guest PC 0x0c0c4fb6 */
if(!s->budget--) { s->failed_pc=0x0c0c4fb6u; return 0; }
r[2]=read(ram,0x0c0c5034u,4);
goto P_0c0c4fb8;
P_0c0c4fb8: /* original 6303, guest PC 0x0c0c4fb8 */
if(!s->budget--) { s->failed_pc=0x0c0c4fb8u; return 0; }
r[3]=r[0];
goto P_0c0c4fba;
P_0c0c4fba: /* original 4000, guest PC 0x0c0c4fba */
if(!s->budget--) { s->failed_pc=0x0c0c4fbau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c4fbc;
P_0c0c4fbc: /* original 303c, guest PC 0x0c0c4fbc */
if(!s->budget--) { s->failed_pc=0x0c0c4fbcu; return 0; }
r[0]+=r[3];
goto P_0c0c4fbe;
P_0c0c4fbe: /* original 4008, guest PC 0x0c0c4fbe */
if(!s->budget--) { s->failed_pc=0x0c0c4fbeu; return 0; }
r[0]<<=2;
goto P_0c0c4fc0;
P_0c0c4fc0: /* original 4008, guest PC 0x0c0c4fc0 */
if(!s->budget--) { s->failed_pc=0x0c0c4fc0u; return 0; }
r[0]<<=2;
goto P_0c0c4fc2;
P_0c0c4fc2: /* original 4008, guest PC 0x0c0c4fc2 */
if(!s->budget--) { s->failed_pc=0x0c0c4fc2u; return 0; }
r[0]<<=2;
goto P_0c0c4fc4;
P_0c0c4fc4: /* original 6103, guest PC 0x0c0c4fc4 */
if(!s->budget--) { s->failed_pc=0x0c0c4fc4u; return 0; }
r[1]=r[0];
goto P_0c0c4fc6;
P_0c0c4fc6: /* original 420b, guest PC 0x0c0c4fc6 */
if(!s->budget--) { s->failed_pc=0x0c0c4fc6u; return 0; }
target=r[2];
r[16]=0x0c0c4fcau;
r[0]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c4fcau) { target=s->pc; goto dispatch; }
goto P_0c0c4fca;
P_0c0c4fc8: /* original 6043, guest PC 0x0c0c4fc8 */
if(!s->budget--) { s->failed_pc=0x0c0c4fc8u; return 0; }
r[0]=r[4];
goto P_0c0c4fca;
P_0c0c4fca: /* original 6e03, guest PC 0x0c0c4fca */
if(!s->budget--) { s->failed_pc=0x0c0c4fcau; return 0; }
r[14]=r[0];
goto P_0c0c4fcc;
P_0c0c4fcc: /* original 902f, guest PC 0x0c0c4fcc */
if(!s->budget--) { s->failed_pc=0x0c0c4fccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c502eu,2);
goto P_0c0c4fce;
P_0c0c4fce: /* original 65d3, guest PC 0x0c0c4fce */
if(!s->budget--) { s->failed_pc=0x0c0c4fceu; return 0; }
r[5]=r[13];
goto P_0c0c4fd0;
P_0c0c4fd0: /* original 67c3, guest PC 0x0c0c4fd0 */
if(!s->budget--) { s->failed_pc=0x0c0c4fd0u; return 0; }
r[7]=r[12];
goto P_0c0c4fd2;
P_0c0c4fd2: /* original 04ad, guest PC 0x0c0c4fd2 */
if(!s->budget--) { s->failed_pc=0x0c0c4fd2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c0c4fd4;
P_0c0c4fd4: /* original da1b, guest PC 0x0c0c4fd4 */
if(!s->budget--) { s->failed_pc=0x0c0c4fd4u; return 0; }
r[10]=read(ram,0x0c0c5044u,4);
goto P_0c0c4fd6;
P_0c0c4fd6: /* original 3e48, guest PC 0x0c0c4fd6 */
if(!s->budget--) { s->failed_pc=0x0c0c4fd6u; return 0; }
r[14]-=r[4];
goto P_0c0c4fd8;
P_0c0c4fd8: /* original 66e3, guest PC 0x0c0c4fd8 */
if(!s->budget--) { s->failed_pc=0x0c0c4fd8u; return 0; }
r[6]=r[14];
goto P_0c0c4fda;
P_0c0c4fda: /* original 2fa6, guest PC 0x0c0c4fda */
if(!s->budget--) { s->failed_pc=0x0c0c4fdau; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0c4fdc;
P_0c0c4fdc: /* original b034, guest PC 0x0c0c4fdc */
if(!s->budget--) { s->failed_pc=0x0c0c4fdcu; return 0; }
target=0x0c0c5048u; r[16]=0x0c0c4fe0u;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c4fe0u) { target=s->pc; goto dispatch; }
goto P_0c0c4fe0;
P_0c0c4fde: /* original 54f2, guest PC 0x0c0c4fde */
if(!s->budget--) { s->failed_pc=0x0c0c4fdeu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0c4fe0;
P_0c0c4fe0: /* original e01c, guest PC 0x0c0c4fe0 */
if(!s->budget--) { s->failed_pc=0x0c0c4fe0u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c4fe2;
P_0c0c4fe2: /* original 62e3, guest PC 0x0c0c4fe2 */
if(!s->budget--) { s->failed_pc=0x0c0c4fe2u; return 0; }
r[2]=r[14];
goto P_0c0c4fe4;
P_0c0c4fe4: /* original e40f, guest PC 0x0c0c4fe4 */
if(!s->budget--) { s->failed_pc=0x0c0c4fe4u; return 0; }
r[4]=0x0000000fu;
goto P_0c0c4fe6;
P_0c0c4fe6: /* original e507, guest PC 0x0c0c4fe6 */
if(!s->budget--) { s->failed_pc=0x0c0c4fe6u; return 0; }
r[5]=0x00000007u;
goto P_0c0c4fe8;
P_0c0c4fe8: /* original 2259, guest PC 0x0c0c4fe8 */
if(!s->budget--) { s->failed_pc=0x0c0c4fe8u; return 0; }
r[2]&=r[5];
goto P_0c0c4fea;
P_0c0c4fea: /* original 7f04, guest PC 0x0c0c4fea */
if(!s->budget--) { s->failed_pc=0x0c0c4feau; return 0; }
r[15]+=0x00000004u;
goto P_0c0c4fec;
P_0c0c4fec: /* original 2f22, guest PC 0x0c0c4fec */
if(!s->budget--) { s->failed_pc=0x0c0c4fecu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c4fee;
P_0c0c4fee: /* original 00bc, guest PC 0x0c0c4fee */
if(!s->budget--) { s->failed_pc=0x0c0c4feeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c4ff0;
P_0c0c4ff0: /* original 600c, guest PC 0x0c0c4ff0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ff0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c4ff2;
P_0c0c4ff2: /* original 2409, guest PC 0x0c0c4ff2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ff2u; return 0; }
r[4]&=r[0];
goto P_0c0c4ff4;
P_0c0c4ff4: /* original 6043, guest PC 0x0c0c4ff4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ff4u; return 0; }
r[0]=r[4];
goto P_0c0c4ff6;
P_0c0c4ff6: /* original 880d, guest PC 0x0c0c4ff6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ff6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0c4ff8;
P_0c0c4ff8: /* original 8b06, guest PC 0x0c0c4ff8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ff8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5008; }
goto P_0c0c4ffa;
P_0c0c4ffa: /* original 65d3, guest PC 0x0c0c4ffa */
if(!s->budget--) { s->failed_pc=0x0c0c4ffau; return 0; }
r[5]=r[13];
goto P_0c0c4ffc;
P_0c0c4ffc: /* original 66e3, guest PC 0x0c0c4ffc */
if(!s->budget--) { s->failed_pc=0x0c0c4ffcu; return 0; }
r[6]=r[14];
goto P_0c0c4ffe;
P_0c0c4ffe: /* original b539, guest PC 0x0c0c4ffe */
if(!s->budget--) { s->failed_pc=0x0c0c4ffeu; return 0; }
target=0x0c0c5a74u; r[16]=0x0c0c5002u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5002u) { target=s->pc; goto dispatch; }
goto P_0c0c5002;
P_0c0c5000: /* original 54f1, guest PC 0x0c0c5000 */
if(!s->budget--) { s->failed_pc=0x0c0c5000u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c5002;
P_0c0c5002: /* original 9415, guest PC 0x0c0c5002 */
if(!s->budget--) { s->failed_pc=0x0c0c5002u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5030u,2);
goto P_0c0c5004;
P_0c0c5004: /* original a002, guest PC 0x0c0c5004 */
if(!s->budget--) { s->failed_pc=0x0c0c5004u; return 0; }
goto P_0c0c500c;
P_0c0c5006: /* original 0009, guest PC 0x0c0c5006 */
if(!s->budget--) { s->failed_pc=0x0c0c5006u; return 0; }
goto P_0c0c5008;
P_0c0c5008: /* original 64d3, guest PC 0x0c0c5008 */
if(!s->budget--) { s->failed_pc=0x0c0c5008u; return 0; }
r[4]=r[13];
goto P_0c0c500a;
P_0c0c500a: /* original 2459, guest PC 0x0c0c500a */
if(!s->budget--) { s->failed_pc=0x0c0c500au; return 0; }
r[4]&=r[5];
goto P_0c0c500c;
P_0c0c500c: /* original 6043, guest PC 0x0c0c500c */
if(!s->budget--) { s->failed_pc=0x0c0c500cu; return 0; }
r[0]=r[4];
goto P_0c0c500e;
P_0c0c500e: /* original 81aa, guest PC 0x0c0c500e */
if(!s->budget--) { s->failed_pc=0x0c0c500eu; return 0; }
write(ram,r[10]+20,r[0],2);
goto P_0c0c5010;
P_0c0c5010: /* original 60f2, guest PC 0x0c0c5010 */
if(!s->budget--) { s->failed_pc=0x0c0c5010u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0c5012;
P_0c0c5012: /* original 81ab, guest PC 0x0c0c5012 */
if(!s->budget--) { s->failed_pc=0x0c0c5012u; return 0; }
write(ram,r[10]+22,r[0],2);
goto P_0c0c5014;
P_0c0c5014: /* original 7f0c, guest PC 0x0c0c5014 */
if(!s->budget--) { s->failed_pc=0x0c0c5014u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c5016;
P_0c0c5016: /* original 4f16, guest PC 0x0c0c5016 */
if(!s->budget--) { s->failed_pc=0x0c0c5016u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5018;
P_0c0c5018: /* original 4f26, guest PC 0x0c0c5018 */
if(!s->budget--) { s->failed_pc=0x0c0c5018u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c501a;
P_0c0c501a: /* original 6af6, guest PC 0x0c0c501a */
if(!s->budget--) { s->failed_pc=0x0c0c501au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c501c;
P_0c0c501c: /* original 6bf6, guest PC 0x0c0c501c */
if(!s->budget--) { s->failed_pc=0x0c0c501cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c501e;
P_0c0c501e: /* original 6cf6, guest PC 0x0c0c501e */
if(!s->budget--) { s->failed_pc=0x0c0c501eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c5020;
P_0c0c5020: /* original 6df6, guest PC 0x0c0c5020 */
if(!s->budget--) { s->failed_pc=0x0c0c5020u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5022;
P_0c0c5022: /* original 000b, guest PC 0x0c0c5022 */
if(!s->budget--) { s->failed_pc=0x0c0c5022u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5024: /* original 6ef6, guest PC 0x0c0c5024 */
if(!s->budget--) { s->failed_pc=0x0c0c5024u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c5026u,s,ram);
P_0c0c5062: /* original 4f22, guest PC 0x0c0c5062 */
if(!s->budget--) { s->failed_pc=0x0c0c5062u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5064;
P_0c0c5064: /* original 90b5, guest PC 0x0c0c5064 */
if(!s->budget--) { s->failed_pc=0x0c0c5064u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d2u,2);
goto P_0c0c5066;
P_0c0c5066: /* original dd61, guest PC 0x0c0c5066 */
if(!s->budget--) { s->failed_pc=0x0c0c5066u; return 0; }
r[13]=read(ram,0x0c0c51ecu,4);
goto P_0c0c5068;
P_0c0c5068: /* original 3f0c, guest PC 0x0c0c5068 */
if(!s->budget--) { s->failed_pc=0x0c0c5068u; return 0; }
r[15]+=r[0];
goto P_0c0c506a;
P_0c0c506a: /* original c75f, guest PC 0x0c0c506a */
if(!s->budget--) { s->failed_pc=0x0c0c506au; return 0; }
r[0]=0x0c0c51e8u;
goto P_0c0c506c;
P_0c0c506c: /* original fc08, guest PC 0x0c0c506c */
if(!s->budget--) { s->failed_pc=0x0c0c506cu; return 0; }
vf3_matrix_load(s,ram,12,r[0]);
goto P_0c0c506e;
P_0c0c506e: /* original 1f5f, guest PC 0x0c0c506e */
if(!s->budget--) { s->failed_pc=0x0c0c506eu; return 0; }
write(ram,r[15]+60,r[5],4);
goto P_0c0c5070;
P_0c0c5070: /* original 1f6c, guest PC 0x0c0c5070 */
if(!s->budget--) { s->failed_pc=0x0c0c5070u; return 0; }
write(ram,r[15]+48,r[6],4);
goto P_0c0c5072;
P_0c0c5072: /* original 90af, guest PC 0x0c0c5072 */
if(!s->budget--) { s->failed_pc=0x0c0c5072u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d4u,2);
goto P_0c0c5074;
P_0c0c5074: /* original d35e, guest PC 0x0c0c5074 */
if(!s->budget--) { s->failed_pc=0x0c0c5074u; return 0; }
r[3]=read(ram,0x0c0c51f0u,4);
goto P_0c0c5076;
P_0c0c5076: /* original 0afe, guest PC 0x0c0c5076 */
if(!s->budget--) { s->failed_pc=0x0c0c5076u; return 0; }
r[10]=read(ram,r[15]+r[0],4);
goto P_0c0c5078;
P_0c0c5078: /* original 430b, guest PC 0x0c0c5078 */
if(!s->budget--) { s->failed_pc=0x0c0c5078u; return 0; }
target=r[3];
r[16]=0x0c0c507cu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c507cu) { target=s->pc; goto dispatch; }
goto P_0c0c507c;
P_0c0c507a: /* original 64a3, guest PC 0x0c0c507a */
if(!s->budget--) { s->failed_pc=0x0c0c507au; return 0; }
r[4]=r[10];
goto P_0c0c507c;
P_0c0c507c: /* original e026, guest PC 0x0c0c507c */
if(!s->budget--) { s->failed_pc=0x0c0c507cu; return 0; }
r[0]=0x00000026u;
goto P_0c0c507e;
P_0c0c507e: /* original 02ad, guest PC 0x0c0c507e */
if(!s->budget--) { s->failed_pc=0x0c0c507eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c0c5080;
P_0c0c5080: /* original e044, guest PC 0x0c0c5080 */
if(!s->budget--) { s->failed_pc=0x0c0c5080u; return 0; }
r[0]=0x00000044u;
goto P_0c0c5082;
P_0c0c5082: /* original 622d, guest PC 0x0c0c5082 */
if(!s->budget--) { s->failed_pc=0x0c0c5082u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c5084;
P_0c0c5084: /* original 0f26, guest PC 0x0c0c5084 */
if(!s->budget--) { s->failed_pc=0x0c0c5084u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0c5086;
P_0c0c5086: /* original db5b, guest PC 0x0c0c5086 */
if(!s->budget--) { s->failed_pc=0x0c0c5086u; return 0; }
r[11]=read(ram,0x0c0c51f4u,4);
goto P_0c0c5088;
P_0c0c5088: /* original 4b0b, guest PC 0x0c0c5088 */
if(!s->budget--) { s->failed_pc=0x0c0c5088u; return 0; }
target=r[11];
r[16]=0x0c0c508cu;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c508cu) { target=s->pc; goto dispatch; }
goto P_0c0c508c;
P_0c0c508a: /* original 6493, guest PC 0x0c0c508a */
if(!s->budget--) { s->failed_pc=0x0c0c508au; return 0; }
r[4]=r[9];
goto P_0c0c508c;
P_0c0c508c: /* original 6393, guest PC 0x0c0c508c */
if(!s->budget--) { s->failed_pc=0x0c0c508cu; return 0; }
r[3]=r[9];
goto P_0c0c508e;
P_0c0c508e: /* original 6e03, guest PC 0x0c0c508e */
if(!s->budget--) { s->failed_pc=0x0c0c508eu; return 0; }
r[14]=r[0];
goto P_0c0c5090;
P_0c0c5090: /* original e020, guest PC 0x0c0c5090 */
if(!s->budget--) { s->failed_pc=0x0c0c5090u; return 0; }
r[0]=0x00000020u;
goto P_0c0c5092;
P_0c0c5092: /* original 7305, guest PC 0x0c0c5092 */
if(!s->budget--) { s->failed_pc=0x0c0c5092u; return 0; }
r[3]+=0x00000005u;
goto P_0c0c5094;
P_0c0c5094: /* original 0f35, guest PC 0x0c0c5094 */
if(!s->budget--) { s->failed_pc=0x0c0c5094u; return 0; }
write(ram,r[15]+r[0],r[3],2);
goto P_0c0c5096;
P_0c0c5096: /* original 50e8, guest PC 0x0c0c5096 */
if(!s->budget--) { s->failed_pc=0x0c0c5096u; return 0; }
r[0]=read(ram,r[14]+32,4);
goto P_0c0c5098;
P_0c0c5098: /* original 882c, guest PC 0x0c0c5098 */
if(!s->budget--) { s->failed_pc=0x0c0c5098u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002cu)!=0);
goto P_0c0c509a;
P_0c0c509a: /* original 8d03, guest PC 0x0c0c509a */
if(!s->budget--) { s->failed_pc=0x0c0c509au; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0c50a4; }
goto P_0c0c509e;
P_0c0c509c: /* original 6403, guest PC 0x0c0c509c */
if(!s->budget--) { s->failed_pc=0x0c0c509cu; return 0; }
r[4]=r[0];
goto P_0c0c509e;
P_0c0c509e: /* original 6043, guest PC 0x0c0c509e */
if(!s->budget--) { s->failed_pc=0x0c0c509eu; return 0; }
r[0]=r[4];
goto P_0c0c50a0;
P_0c0c50a0: /* original 8834, guest PC 0x0c0c50a0 */
if(!s->budget--) { s->failed_pc=0x0c0c50a0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000034u)!=0);
goto P_0c0c50a2;
P_0c0c50a2: /* original 8b70, guest PC 0x0c0c50a2 */
if(!s->budget--) { s->failed_pc=0x0c0c50a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5186; }
goto P_0c0c50a4;
P_0c0c50a4: /* original 9497, guest PC 0x0c0c50a4 */
if(!s->budget--) { s->failed_pc=0x0c0c50a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d6u,2);
goto P_0c0c50a6;
P_0c0c50a6: /* original 65e3, guest PC 0x0c0c50a6 */
if(!s->budget--) { s->failed_pc=0x0c0c50a6u; return 0; }
r[5]=r[14];
goto P_0c0c50a8;
P_0c0c50a8: /* original da53, guest PC 0x0c0c50a8 */
if(!s->budget--) { s->failed_pc=0x0c0c50a8u; return 0; }
r[10]=read(ram,0x0c0c51f8u,4);
goto P_0c0c50aa;
P_0c0c50aa: /* original e624, guest PC 0x0c0c50aa */
if(!s->budget--) { s->failed_pc=0x0c0c50aau; return 0; }
r[6]=0x00000024u;
goto P_0c0c50ac;
P_0c0c50ac: /* original 4a0b, guest PC 0x0c0c50ac */
if(!s->budget--) { s->failed_pc=0x0c0c50acu; return 0; }
target=r[10];
r[16]=0x0c0c50b0u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c50b0u) { target=s->pc; goto dispatch; }
goto P_0c0c50b0;
P_0c0c50ae: /* original 34fc, guest PC 0x0c0c50ae */
if(!s->budget--) { s->failed_pc=0x0c0c50aeu; return 0; }
r[4]+=r[15];
goto P_0c0c50b0;
P_0c0c50b0: /* original 6493, guest PC 0x0c0c50b0 */
if(!s->budget--) { s->failed_pc=0x0c0c50b0u; return 0; }
r[4]=r[9];
goto P_0c0c50b2;
P_0c0c50b2: /* original 4b0b, guest PC 0x0c0c50b2 */
if(!s->budget--) { s->failed_pc=0x0c0c50b2u; return 0; }
target=r[11];
r[16]=0x0c0c50b6u;
r[4]+=0x00000003u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c50b6u) { target=s->pc; goto dispatch; }
goto P_0c0c50b6;
P_0c0c50b4: /* original 7403, guest PC 0x0c0c50b4 */
if(!s->budget--) { s->failed_pc=0x0c0c50b4u; return 0; }
r[4]+=0x00000003u;
goto P_0c0c50b6;
P_0c0c50b6: /* original 6503, guest PC 0x0c0c50b6 */
if(!s->budget--) { s->failed_pc=0x0c0c50b6u; return 0; }
r[5]=r[0];
goto P_0c0c50b8;
P_0c0c50b8: /* original 908d, guest PC 0x0c0c50b8 */
if(!s->budget--) { s->failed_pc=0x0c0c50b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d6u,2);
goto P_0c0c50ba;
P_0c0c50ba: /* original f258, guest PC 0x0c0c50ba */
if(!s->budget--) { s->failed_pc=0x0c0c50bau; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0c50bc;
P_0c0c50bc: /* original e624, guest PC 0x0c0c50bc */
if(!s->budget--) { s->failed_pc=0x0c0c50bcu; return 0; }
r[6]=0x00000024u;
goto P_0c0c50be;
P_0c0c50be: /* original f3f6, guest PC 0x0c0c50be */
if(!s->budget--) { s->failed_pc=0x0c0c50beu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c50c0;
P_0c0c50c0: /* original f230, guest PC 0x0c0c50c0 */
if(!s->budget--) { s->failed_pc=0x0c0c50c0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c50c2;
P_0c0c50c2: /* original f52a, guest PC 0x0c0c50c2 */
if(!s->budget--) { s->failed_pc=0x0c0c50c2u; return 0; }
vf3_matrix_store(s,ram,2,r[5]);
goto P_0c0c50c4;
P_0c0c50c4: /* original 9088, guest PC 0x0c0c50c4 */
if(!s->budget--) { s->failed_pc=0x0c0c50c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d8u,2);
goto P_0c0c50c6;
P_0c0c50c6: /* original f3f6, guest PC 0x0c0c50c6 */
if(!s->budget--) { s->failed_pc=0x0c0c50c6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c50c8;
P_0c0c50c8: /* original e004, guest PC 0x0c0c50c8 */
if(!s->budget--) { s->failed_pc=0x0c0c50c8u; return 0; }
r[0]=0x00000004u;
goto P_0c0c50ca;
P_0c0c50ca: /* original f256, guest PC 0x0c0c50ca */
if(!s->budget--) { s->failed_pc=0x0c0c50cau; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c0c50cc;
P_0c0c50cc: /* original f230, guest PC 0x0c0c50cc */
if(!s->budget--) { s->failed_pc=0x0c0c50ccu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c50ce;
P_0c0c50ce: /* original f527, guest PC 0x0c0c50ce */
if(!s->budget--) { s->failed_pc=0x0c0c50ceu; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c0c50d0;
P_0c0c50d0: /* original 9083, guest PC 0x0c0c50d0 */
if(!s->budget--) { s->failed_pc=0x0c0c50d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51dau,2);
goto P_0c0c50d2;
P_0c0c50d2: /* original f3f6, guest PC 0x0c0c50d2 */
if(!s->budget--) { s->failed_pc=0x0c0c50d2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c50d4;
P_0c0c50d4: /* original e018, guest PC 0x0c0c50d4 */
if(!s->budget--) { s->failed_pc=0x0c0c50d4u; return 0; }
r[0]=0x00000018u;
goto P_0c0c50d6;
P_0c0c50d6: /* original f256, guest PC 0x0c0c50d6 */
if(!s->budget--) { s->failed_pc=0x0c0c50d6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c0c50d8;
P_0c0c50d8: /* original f230, guest PC 0x0c0c50d8 */
if(!s->budget--) { s->failed_pc=0x0c0c50d8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c50da;
P_0c0c50da: /* original f527, guest PC 0x0c0c50da */
if(!s->budget--) { s->failed_pc=0x0c0c50dau; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c0c50dc;
P_0c0c50dc: /* original 907e, guest PC 0x0c0c50dc */
if(!s->budget--) { s->failed_pc=0x0c0c50dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51dcu,2);
goto P_0c0c50de;
P_0c0c50de: /* original f3f6, guest PC 0x0c0c50de */
if(!s->budget--) { s->failed_pc=0x0c0c50deu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c50e0;
P_0c0c50e0: /* original e01c, guest PC 0x0c0c50e0 */
if(!s->budget--) { s->failed_pc=0x0c0c50e0u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c50e2;
P_0c0c50e2: /* original f256, guest PC 0x0c0c50e2 */
if(!s->budget--) { s->failed_pc=0x0c0c50e2u; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c0c50e4;
P_0c0c50e4: /* original f230, guest PC 0x0c0c50e4 */
if(!s->budget--) { s->failed_pc=0x0c0c50e4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c50e6;
P_0c0c50e6: /* original f527, guest PC 0x0c0c50e6 */
if(!s->budget--) { s->failed_pc=0x0c0c50e6u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c0c50e8;
P_0c0c50e8: /* original 9079, guest PC 0x0c0c50e8 */
if(!s->budget--) { s->failed_pc=0x0c0c50e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51deu,2);
goto P_0c0c50ea;
P_0c0c50ea: /* original f3f6, guest PC 0x0c0c50ea */
if(!s->budget--) { s->failed_pc=0x0c0c50eau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c50ec;
P_0c0c50ec: /* original e008, guest PC 0x0c0c50ec */
if(!s->budget--) { s->failed_pc=0x0c0c50ecu; return 0; }
r[0]=0x00000008u;
goto P_0c0c50ee;
P_0c0c50ee: /* original f256, guest PC 0x0c0c50ee */
if(!s->budget--) { s->failed_pc=0x0c0c50eeu; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c0c50f0;
P_0c0c50f0: /* original f230, guest PC 0x0c0c50f0 */
if(!s->budget--) { s->failed_pc=0x0c0c50f0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c50f2;
P_0c0c50f2: /* original f527, guest PC 0x0c0c50f2 */
if(!s->budget--) { s->failed_pc=0x0c0c50f2u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c0c50f4;
P_0c0c50f4: /* original 946f, guest PC 0x0c0c50f4 */
if(!s->budget--) { s->failed_pc=0x0c0c50f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d6u,2);
goto P_0c0c50f6;
P_0c0c50f6: /* original 4a0b, guest PC 0x0c0c50f6 */
if(!s->budget--) { s->failed_pc=0x0c0c50f6u; return 0; }
target=r[10];
r[16]=0x0c0c50fau;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c50fau) { target=s->pc; goto dispatch; }
goto P_0c0c50fa;
P_0c0c50f8: /* original 34fc, guest PC 0x0c0c50f8 */
if(!s->budget--) { s->failed_pc=0x0c0c50f8u; return 0; }
r[4]+=r[15];
goto P_0c0c50fa;
P_0c0c50fa: /* original 6493, guest PC 0x0c0c50fa */
if(!s->budget--) { s->failed_pc=0x0c0c50fau; return 0; }
r[4]=r[9];
goto P_0c0c50fc;
P_0c0c50fc: /* original 4b0b, guest PC 0x0c0c50fc */
if(!s->budget--) { s->failed_pc=0x0c0c50fcu; return 0; }
target=r[11];
r[16]=0x0c0c5100u;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5100u) { target=s->pc; goto dispatch; }
goto P_0c0c5100;
P_0c0c50fe: /* original 7404, guest PC 0x0c0c50fe */
if(!s->budget--) { s->failed_pc=0x0c0c50feu; return 0; }
r[4]+=0x00000004u;
goto P_0c0c5100;
P_0c0c5100: /* original 6503, guest PC 0x0c0c5100 */
if(!s->budget--) { s->failed_pc=0x0c0c5100u; return 0; }
r[5]=r[0];
goto P_0c0c5102;
P_0c0c5102: /* original 9068, guest PC 0x0c0c5102 */
if(!s->budget--) { s->failed_pc=0x0c0c5102u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d6u,2);
goto P_0c0c5104;
P_0c0c5104: /* original f258, guest PC 0x0c0c5104 */
if(!s->budget--) { s->failed_pc=0x0c0c5104u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0c5106;
P_0c0c5106: /* original e624, guest PC 0x0c0c5106 */
if(!s->budget--) { s->failed_pc=0x0c0c5106u; return 0; }
r[6]=0x00000024u;
goto P_0c0c5108;
P_0c0c5108: /* original f3f6, guest PC 0x0c0c5108 */
if(!s->budget--) { s->failed_pc=0x0c0c5108u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c510a;
P_0c0c510a: /* original f230, guest PC 0x0c0c510a */
if(!s->budget--) { s->failed_pc=0x0c0c510au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c510c;
P_0c0c510c: /* original f52a, guest PC 0x0c0c510c */
if(!s->budget--) { s->failed_pc=0x0c0c510cu; return 0; }
vf3_matrix_store(s,ram,2,r[5]);
goto P_0c0c510e;
P_0c0c510e: /* original 9063, guest PC 0x0c0c510e */
if(!s->budget--) { s->failed_pc=0x0c0c510eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d8u,2);
goto P_0c0c5110;
P_0c0c5110: /* original f3f6, guest PC 0x0c0c5110 */
if(!s->budget--) { s->failed_pc=0x0c0c5110u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5112;
P_0c0c5112: /* original e004, guest PC 0x0c0c5112 */
if(!s->budget--) { s->failed_pc=0x0c0c5112u; return 0; }
r[0]=0x00000004u;
goto P_0c0c5114;
P_0c0c5114: /* original f256, guest PC 0x0c0c5114 */
if(!s->budget--) { s->failed_pc=0x0c0c5114u; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c0c5116;
P_0c0c5116: /* original f230, guest PC 0x0c0c5116 */
if(!s->budget--) { s->failed_pc=0x0c0c5116u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5118;
P_0c0c5118: /* original f527, guest PC 0x0c0c5118 */
if(!s->budget--) { s->failed_pc=0x0c0c5118u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c0c511a;
P_0c0c511a: /* original 905e, guest PC 0x0c0c511a */
if(!s->budget--) { s->failed_pc=0x0c0c511au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51dau,2);
goto P_0c0c511c;
P_0c0c511c: /* original f3f6, guest PC 0x0c0c511c */
if(!s->budget--) { s->failed_pc=0x0c0c511cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c511e;
P_0c0c511e: /* original e018, guest PC 0x0c0c511e */
if(!s->budget--) { s->failed_pc=0x0c0c511eu; return 0; }
r[0]=0x00000018u;
goto P_0c0c5120;
P_0c0c5120: /* original f256, guest PC 0x0c0c5120 */
if(!s->budget--) { s->failed_pc=0x0c0c5120u; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c0c5122;
P_0c0c5122: /* original f230, guest PC 0x0c0c5122 */
if(!s->budget--) { s->failed_pc=0x0c0c5122u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5124;
P_0c0c5124: /* original f527, guest PC 0x0c0c5124 */
if(!s->budget--) { s->failed_pc=0x0c0c5124u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c0c5126;
P_0c0c5126: /* original 9059, guest PC 0x0c0c5126 */
if(!s->budget--) { s->failed_pc=0x0c0c5126u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51dcu,2);
goto P_0c0c5128;
P_0c0c5128: /* original f3f6, guest PC 0x0c0c5128 */
if(!s->budget--) { s->failed_pc=0x0c0c5128u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c512a;
P_0c0c512a: /* original e01c, guest PC 0x0c0c512a */
if(!s->budget--) { s->failed_pc=0x0c0c512au; return 0; }
r[0]=0x0000001cu;
goto P_0c0c512c;
P_0c0c512c: /* original f256, guest PC 0x0c0c512c */
if(!s->budget--) { s->failed_pc=0x0c0c512cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c0c512e;
P_0c0c512e: /* original f230, guest PC 0x0c0c512e */
if(!s->budget--) { s->failed_pc=0x0c0c512eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5130;
P_0c0c5130: /* original f527, guest PC 0x0c0c5130 */
if(!s->budget--) { s->failed_pc=0x0c0c5130u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c0c5132;
P_0c0c5132: /* original 9054, guest PC 0x0c0c5132 */
if(!s->budget--) { s->failed_pc=0x0c0c5132u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51deu,2);
goto P_0c0c5134;
P_0c0c5134: /* original f3f6, guest PC 0x0c0c5134 */
if(!s->budget--) { s->failed_pc=0x0c0c5134u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5136;
P_0c0c5136: /* original e008, guest PC 0x0c0c5136 */
if(!s->budget--) { s->failed_pc=0x0c0c5136u; return 0; }
r[0]=0x00000008u;
goto P_0c0c5138;
P_0c0c5138: /* original f256, guest PC 0x0c0c5138 */
if(!s->budget--) { s->failed_pc=0x0c0c5138u; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c0c513a;
P_0c0c513a: /* original f230, guest PC 0x0c0c513a */
if(!s->budget--) { s->failed_pc=0x0c0c513au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c513c;
P_0c0c513c: /* original f527, guest PC 0x0c0c513c */
if(!s->budget--) { s->failed_pc=0x0c0c513cu; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c0c513e;
P_0c0c513e: /* original 944a, guest PC 0x0c0c513e */
if(!s->budget--) { s->failed_pc=0x0c0c513eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d6u,2);
goto P_0c0c5140;
P_0c0c5140: /* original 4a0b, guest PC 0x0c0c5140 */
if(!s->budget--) { s->failed_pc=0x0c0c5140u; return 0; }
target=r[10];
r[16]=0x0c0c5144u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5144u) { target=s->pc; goto dispatch; }
goto P_0c0c5144;
P_0c0c5142: /* original 34fc, guest PC 0x0c0c5142 */
if(!s->budget--) { s->failed_pc=0x0c0c5142u; return 0; }
r[4]+=r[15];
goto P_0c0c5144;
P_0c0c5144: /* original e020, guest PC 0x0c0c5144 */
if(!s->budget--) { s->failed_pc=0x0c0c5144u; return 0; }
r[0]=0x00000020u;
goto P_0c0c5146;
P_0c0c5146: /* original 4b0b, guest PC 0x0c0c5146 */
if(!s->budget--) { s->failed_pc=0x0c0c5146u; return 0; }
target=r[11];
r[16]=0x0c0c514au;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c514au) { target=s->pc; goto dispatch; }
goto P_0c0c514a;
P_0c0c5148: /* original 04fd, guest PC 0x0c0c5148 */
if(!s->budget--) { s->failed_pc=0x0c0c5148u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
goto P_0c0c514a;
P_0c0c514a: /* original 6e03, guest PC 0x0c0c514a */
if(!s->budget--) { s->failed_pc=0x0c0c514au; return 0; }
r[14]=r[0];
goto P_0c0c514c;
P_0c0c514c: /* original 9043, guest PC 0x0c0c514c */
if(!s->budget--) { s->failed_pc=0x0c0c514cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d6u,2);
goto P_0c0c514e;
P_0c0c514e: /* original f2e8, guest PC 0x0c0c514e */
if(!s->budget--) { s->failed_pc=0x0c0c514eu; return 0; }
vf3_matrix_load(s,ram,2,r[14]);
goto P_0c0c5150;
P_0c0c5150: /* original f3f6, guest PC 0x0c0c5150 */
if(!s->budget--) { s->failed_pc=0x0c0c5150u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5152;
P_0c0c5152: /* original f230, guest PC 0x0c0c5152 */
if(!s->budget--) { s->failed_pc=0x0c0c5152u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5154;
P_0c0c5154: /* original fe2a, guest PC 0x0c0c5154 */
if(!s->budget--) { s->failed_pc=0x0c0c5154u; return 0; }
vf3_matrix_store(s,ram,2,r[14]);
goto P_0c0c5156;
P_0c0c5156: /* original 903f, guest PC 0x0c0c5156 */
if(!s->budget--) { s->failed_pc=0x0c0c5156u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51d8u,2);
goto P_0c0c5158;
P_0c0c5158: /* original f3f6, guest PC 0x0c0c5158 */
if(!s->budget--) { s->failed_pc=0x0c0c5158u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c515a;
P_0c0c515a: /* original e004, guest PC 0x0c0c515a */
if(!s->budget--) { s->failed_pc=0x0c0c515au; return 0; }
r[0]=0x00000004u;
goto P_0c0c515c;
P_0c0c515c: /* original f2e6, guest PC 0x0c0c515c */
if(!s->budget--) { s->failed_pc=0x0c0c515cu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0c515e;
P_0c0c515e: /* original f230, guest PC 0x0c0c515e */
if(!s->budget--) { s->failed_pc=0x0c0c515eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5160;
P_0c0c5160: /* original fe27, guest PC 0x0c0c5160 */
if(!s->budget--) { s->failed_pc=0x0c0c5160u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0c5162;
P_0c0c5162: /* original 903a, guest PC 0x0c0c5162 */
if(!s->budget--) { s->failed_pc=0x0c0c5162u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51dau,2);
goto P_0c0c5164;
P_0c0c5164: /* original f3f6, guest PC 0x0c0c5164 */
if(!s->budget--) { s->failed_pc=0x0c0c5164u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5166;
P_0c0c5166: /* original e018, guest PC 0x0c0c5166 */
if(!s->budget--) { s->failed_pc=0x0c0c5166u; return 0; }
r[0]=0x00000018u;
goto P_0c0c5168;
P_0c0c5168: /* original f2e6, guest PC 0x0c0c5168 */
if(!s->budget--) { s->failed_pc=0x0c0c5168u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0c516a;
P_0c0c516a: /* original f230, guest PC 0x0c0c516a */
if(!s->budget--) { s->failed_pc=0x0c0c516au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c516c;
P_0c0c516c: /* original fe27, guest PC 0x0c0c516c */
if(!s->budget--) { s->failed_pc=0x0c0c516cu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0c516e;
P_0c0c516e: /* original 9035, guest PC 0x0c0c516e */
if(!s->budget--) { s->failed_pc=0x0c0c516eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51dcu,2);
goto P_0c0c5170;
P_0c0c5170: /* original f3f6, guest PC 0x0c0c5170 */
if(!s->budget--) { s->failed_pc=0x0c0c5170u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5172;
P_0c0c5172: /* original e01c, guest PC 0x0c0c5172 */
if(!s->budget--) { s->failed_pc=0x0c0c5172u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c5174;
P_0c0c5174: /* original f2e6, guest PC 0x0c0c5174 */
if(!s->budget--) { s->failed_pc=0x0c0c5174u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0c5176;
P_0c0c5176: /* original f230, guest PC 0x0c0c5176 */
if(!s->budget--) { s->failed_pc=0x0c0c5176u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5178;
P_0c0c5178: /* original fe27, guest PC 0x0c0c5178 */
if(!s->budget--) { s->failed_pc=0x0c0c5178u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0c517a;
P_0c0c517a: /* original 9030, guest PC 0x0c0c517a */
if(!s->budget--) { s->failed_pc=0x0c0c517au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51deu,2);
goto P_0c0c517c;
P_0c0c517c: /* original f3f6, guest PC 0x0c0c517c */
if(!s->budget--) { s->failed_pc=0x0c0c517cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c517e;
P_0c0c517e: /* original e008, guest PC 0x0c0c517e */
if(!s->budget--) { s->failed_pc=0x0c0c517eu; return 0; }
r[0]=0x00000008u;
goto P_0c0c5180;
P_0c0c5180: /* original f2e6, guest PC 0x0c0c5180 */
if(!s->budget--) { s->failed_pc=0x0c0c5180u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0c5182;
P_0c0c5182: /* original f230, guest PC 0x0c0c5182 */
if(!s->budget--) { s->failed_pc=0x0c0c5182u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5184;
P_0c0c5184: /* original fe27, guest PC 0x0c0c5184 */
if(!s->budget--) { s->failed_pc=0x0c0c5184u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0c5186;
P_0c0c5186: /* original e008, guest PC 0x0c0c5186 */
if(!s->budget--) { s->failed_pc=0x0c0c5186u; return 0; }
r[0]=0x00000008u;
goto P_0c0c5188;
P_0c0c5188: /* original f3e6, guest PC 0x0c0c5188 */
if(!s->budget--) { s->failed_pc=0x0c0c5188u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c518a;
P_0c0c518a: /* original e048, guest PC 0x0c0c518a */
if(!s->budget--) { s->failed_pc=0x0c0c518au; return 0; }
r[0]=0x00000048u;
goto P_0c0c518c;
P_0c0c518c: /* original f33d, guest PC 0x0c0c518c */
if(!s->budget--) { s->failed_pc=0x0c0c518cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0c518e;
P_0c0c518e: /* original 035a, guest PC 0x0c0c518e */
if(!s->budget--) { s->failed_pc=0x0c0c518eu; return 0; }
r[3]=r[53];
goto P_0c0c5190;
P_0c0c5190: /* original 4321, guest PC 0x0c0c5190 */
if(!s->budget--) { s->failed_pc=0x0c0c5190u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c0c5192;
P_0c0c5192: /* original 4321, guest PC 0x0c0c5192 */
if(!s->budget--) { s->failed_pc=0x0c0c5192u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c0c5194;
P_0c0c5194: /* original 4321, guest PC 0x0c0c5194 */
if(!s->budget--) { s->failed_pc=0x0c0c5194u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c0c5196;
P_0c0c5196: /* original 0f36, guest PC 0x0c0c5196 */
if(!s->budget--) { s->failed_pc=0x0c0c5196u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0c5198;
P_0c0c5198: /* original e00c, guest PC 0x0c0c5198 */
if(!s->budget--) { s->failed_pc=0x0c0c5198u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c519a;
P_0c0c519a: /* original f3e6, guest PC 0x0c0c519a */
if(!s->budget--) { s->failed_pc=0x0c0c519au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c519c;
P_0c0c519c: /* original e050, guest PC 0x0c0c519c */
if(!s->budget--) { s->failed_pc=0x0c0c519cu; return 0; }
r[0]=0x00000050u;
goto P_0c0c519e;
P_0c0c519e: /* original f33d, guest PC 0x0c0c519e */
if(!s->budget--) { s->failed_pc=0x0c0c519eu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0c51a0;
P_0c0c51a0: /* original 025a, guest PC 0x0c0c51a0 */
if(!s->budget--) { s->failed_pc=0x0c0c51a0u; return 0; }
r[2]=r[53];
goto P_0c0c51a2;
P_0c0c51a2: /* original 4221, guest PC 0x0c0c51a2 */
if(!s->budget--) { s->failed_pc=0x0c0c51a2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]=(uint32_t)((int32_t)r[2]>>1);
goto P_0c0c51a4;
P_0c0c51a4: /* original 4221, guest PC 0x0c0c51a4 */
if(!s->budget--) { s->failed_pc=0x0c0c51a4u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]=(uint32_t)((int32_t)r[2]>>1);
goto P_0c0c51a6;
P_0c0c51a6: /* original 4221, guest PC 0x0c0c51a6 */
if(!s->budget--) { s->failed_pc=0x0c0c51a6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]=(uint32_t)((int32_t)r[2]>>1);
goto P_0c0c51a8;
P_0c0c51a8: /* original 0f26, guest PC 0x0c0c51a8 */
if(!s->budget--) { s->failed_pc=0x0c0c51a8u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0c51aa;
P_0c0c51aa: /* original 9019, guest PC 0x0c0c51aa */
if(!s->budget--) { s->failed_pc=0x0c0c51aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51e0u,2);
goto P_0c0c51ac;
P_0c0c51ac: /* original 0fc6, guest PC 0x0c0c51ac */
if(!s->budget--) { s->failed_pc=0x0c0c51acu; return 0; }
write(ram,r[15]+r[0],r[12],4);
goto P_0c0c51ae;
P_0c0c51ae: /* original d114, guest PC 0x0c0c51ae */
if(!s->budget--) { s->failed_pc=0x0c0c51aeu; return 0; }
r[1]=read(ram,0x0c0c5200u,4);
goto P_0c0c51b0;
P_0c0c51b0: /* original d012, guest PC 0x0c0c51b0 */
if(!s->budget--) { s->failed_pc=0x0c0c51b0u; return 0; }
r[0]=read(ram,0x0c0c51fcu,4);
goto P_0c0c51b2;
P_0c0c51b2: /* original 6310, guest PC 0x0c0c51b2 */
if(!s->budget--) { s->failed_pc=0x0c0c51b2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[3]=tmp;
goto P_0c0c51b4;
P_0c0c51b4: /* original 9215, guest PC 0x0c0c51b4 */
if(!s->budget--) { s->failed_pc=0x0c0c51b4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51e2u,2);
goto P_0c0c51b6;
P_0c0c51b6: /* original 633c, guest PC 0x0c0c51b6 */
if(!s->budget--) { s->failed_pc=0x0c0c51b6u; return 0; }
r[3]=r[3]&255u;
goto P_0c0c51b8;
P_0c0c51b8: /* original 4308, guest PC 0x0c0c51b8 */
if(!s->budget--) { s->failed_pc=0x0c0c51b8u; return 0; }
r[3]<<=2;
goto P_0c0c51ba;
P_0c0c51ba: /* original 033e, guest PC 0x0c0c51ba */
if(!s->budget--) { s->failed_pc=0x0c0c51bau; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c0c51bc;
P_0c0c51bc: /* original 9012, guest PC 0x0c0c51bc */
if(!s->budget--) { s->failed_pc=0x0c0c51bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51e4u,2);
goto P_0c0c51be;
P_0c0c51be: /* original 232b, guest PC 0x0c0c51be */
if(!s->budget--) { s->failed_pc=0x0c0c51beu; return 0; }
r[3]|=r[2];
goto P_0c0c51c0;
P_0c0c51c0: /* original 0f36, guest PC 0x0c0c51c0 */
if(!s->budget--) { s->failed_pc=0x0c0c51c0u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0c51c2;
P_0c0c51c2: /* original 9010, guest PC 0x0c0c51c2 */
if(!s->budget--) { s->failed_pc=0x0c0c51c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c51e6u,2);
goto P_0c0c51c4;
P_0c0c51c4: /* original f39d, guest PC 0x0c0c51c4 */
if(!s->budget--) { s->failed_pc=0x0c0c51c4u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c51c6;
P_0c0c51c6: /* original ff37, guest PC 0x0c0c51c6 */
if(!s->budget--) { s->failed_pc=0x0c0c51c6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c51c8;
P_0c0c51c8: /* original 53fc, guest PC 0x0c0c51c8 */
if(!s->budget--) { s->failed_pc=0x0c0c51c8u; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c0c51ca;
P_0c0c51ca: /* original 4321, guest PC 0x0c0c51ca */
if(!s->budget--) { s->failed_pc=0x0c0c51cau; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c0c51cc;
P_0c0c51cc: /* original 4321, guest PC 0x0c0c51cc */
if(!s->budget--) { s->failed_pc=0x0c0c51ccu; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c0c51ce;
P_0c0c51ce: /* original a019, guest PC 0x0c0c51ce */
if(!s->budget--) { s->failed_pc=0x0c0c51ceu; return 0; }
goto P_0c0c5204;
P_0c0c51d0: /* original 0009, guest PC 0x0c0c51d0 */
if(!s->budget--) { s->failed_pc=0x0c0c51d0u; return 0; }
return vf3_matrix_family(0x0c0c51d2u,s,ram);
P_0c0c5204: /* original e130, guest PC 0x0c0c5204 */
if(!s->budget--) { s->failed_pc=0x0c0c5204u; return 0; }
r[1]=0x00000030u;
goto P_0c0c5206;
P_0c0c5206: /* original e04c, guest PC 0x0c0c5206 */
if(!s->budget--) { s->failed_pc=0x0c0c5206u; return 0; }
r[0]=0x0000004cu;
goto P_0c0c5208;
P_0c0c5208: /* original 4321, guest PC 0x0c0c5208 */
if(!s->budget--) { s->failed_pc=0x0c0c5208u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c0c520a;
P_0c0c520a: /* original 3313, guest PC 0x0c0c520a */
if(!s->budget--) { s->failed_pc=0x0c0c520au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[1])!=0);
goto P_0c0c520c;
P_0c0c520c: /* original 0f36, guest PC 0x0c0c520c */
if(!s->budget--) { s->failed_pc=0x0c0c520cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0c520e;
P_0c0c520e: /* original 2f32, guest PC 0x0c0c520e */
if(!s->budget--) { s->failed_pc=0x0c0c520eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c5210;
P_0c0c5210: /* original 8f02, guest PC 0x0c0c5210 */
if(!s->budget--) { s->failed_pc=0x0c0c5210u; return 0; }
cond=r[17]&1u;
fr[15]=0;
if(!cond) { goto P_0c0c5218; }
goto P_0c0c5214;
P_0c0c5212: /* original ff8d, guest PC 0x0c0c5212 */
if(!s->budget--) { s->failed_pc=0x0c0c5212u; return 0; }
fr[15]=0;
goto P_0c0c5214;
P_0c0c5214: /* original e130, guest PC 0x0c0c5214 */
if(!s->budget--) { s->failed_pc=0x0c0c5214u; return 0; }
r[1]=0x00000030u;
goto P_0c0c5216;
P_0c0c5216: /* original 2f12, guest PC 0x0c0c5216 */
if(!s->budget--) { s->failed_pc=0x0c0c5216u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0c5218;
P_0c0c5218: /* original e044, guest PC 0x0c0c5218 */
if(!s->budget--) { s->failed_pc=0x0c0c5218u; return 0; }
r[0]=0x00000044u;
goto P_0c0c521a;
P_0c0c521a: /* original d85b, guest PC 0x0c0c521a */
if(!s->budget--) { s->failed_pc=0x0c0c521au; return 0; }
r[8]=read(ram,0x0c0c5388u,4);
goto P_0c0c521c;
P_0c0c521c: /* original 03fe, guest PC 0x0c0c521c */
if(!s->budget--) { s->failed_pc=0x0c0c521cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0c521e;
P_0c0c521e: /* original 4308, guest PC 0x0c0c521e */
if(!s->budget--) { s->failed_pc=0x0c0c521eu; return 0; }
r[3]<<=2;
goto P_0c0c5220;
P_0c0c5220: /* original 1f36, guest PC 0x0c0c5220 */
if(!s->budget--) { s->failed_pc=0x0c0c5220u; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0c5222;
P_0c0c5222: /* original 62f2, guest PC 0x0c0c5222 */
if(!s->budget--) { s->failed_pc=0x0c0c5222u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c5224;
P_0c0c5224: /* original 4211, guest PC 0x0c0c5224 */
if(!s->budget--) { s->failed_pc=0x0c0c5224u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c0c5226;
P_0c0c5226: /* original 8b32, guest PC 0x0c0c5226 */
if(!s->budget--) { s->failed_pc=0x0c0c5226u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c528e; }
goto P_0c0c5228;
P_0c0c5228: /* original 6493, guest PC 0x0c0c5228 */
if(!s->budget--) { s->failed_pc=0x0c0c5228u; return 0; }
r[4]=r[9];
goto P_0c0c522a;
P_0c0c522a: /* original 4b0b, guest PC 0x0c0c522a */
if(!s->budget--) { s->failed_pc=0x0c0c522au; return 0; }
target=r[11];
r[16]=0x0c0c522eu;
r[4]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c522eu) { target=s->pc; goto dispatch; }
goto P_0c0c522e;
P_0c0c522c: /* original 7401, guest PC 0x0c0c522c */
if(!s->budget--) { s->failed_pc=0x0c0c522cu; return 0; }
r[4]+=0x00000001u;
goto P_0c0c522e;
P_0c0c522e: /* original 63f2, guest PC 0x0c0c522e */
if(!s->budget--) { s->failed_pc=0x0c0c522eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c5230;
P_0c0c5230: /* original 6a03, guest PC 0x0c0c5230 */
if(!s->budget--) { s->failed_pc=0x0c0c5230u; return 0; }
r[10]=r[0];
goto P_0c0c5232;
P_0c0c5232: /* original e01c, guest PC 0x0c0c5232 */
if(!s->budget--) { s->failed_pc=0x0c0c5232u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c5234;
P_0c0c5234: /* original 94a3, guest PC 0x0c0c5234 */
if(!s->budget--) { s->failed_pc=0x0c0c5234u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c537eu,2);
goto P_0c0c5236;
P_0c0c5236: /* original 7302, guest PC 0x0c0c5236 */
if(!s->budget--) { s->failed_pc=0x0c0c5236u; return 0; }
r[3]+=0x00000002u;
goto P_0c0c5238;
P_0c0c5238: /* original f7e6, guest PC 0x0c0c5238 */
if(!s->budget--) { s->failed_pc=0x0c0c5238u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c523a;
P_0c0c523a: /* original 435a, guest PC 0x0c0c523a */
if(!s->budget--) { s->failed_pc=0x0c0c523au; return 0; }
r[53]=r[3];
goto P_0c0c523c;
P_0c0c523c: /* original c753, guest PC 0x0c0c523c */
if(!s->budget--) { s->failed_pc=0x0c0c523cu; return 0; }
r[0]=0x0c0c538cu;
goto P_0c0c523e;
P_0c0c523e: /* original 53f6, guest PC 0x0c0c523e */
if(!s->budget--) { s->failed_pc=0x0c0c523eu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0c5240;
P_0c0c5240: /* original f5fc, guest PC 0x0c0c5240 */
if(!s->budget--) { s->failed_pc=0x0c0c5240u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c5242;
P_0c0c5242: /* original f32d, guest PC 0x0c0c5242 */
if(!s->budget--) { s->failed_pc=0x0c0c5242u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c5244;
P_0c0c5244: /* original f4fc, guest PC 0x0c0c5244 */
if(!s->budget--) { s->failed_pc=0x0c0c5244u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0c5246;
P_0c0c5246: /* original f732, guest PC 0x0c0c5246 */
if(!s->budget--) { s->failed_pc=0x0c0c5246u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c0c5248;
P_0c0c5248: /* original f308, guest PC 0x0c0c5248 */
if(!s->budget--) { s->failed_pc=0x0c0c5248u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c524a;
P_0c0c524a: /* original d051, guest PC 0x0c0c524a */
if(!s->budget--) { s->failed_pc=0x0c0c524au; return 0; }
r[0]=read(ram,0x0c0c5390u,4);
goto P_0c0c524c;
P_0c0c524c: /* original f836, guest PC 0x0c0c524c */
if(!s->budget--) { s->failed_pc=0x0c0c524cu; return 0; }
vf3_matrix_load(s,ram,8,r[3]+r[0]);
goto P_0c0c524e;
P_0c0c524e: /* original e018, guest PC 0x0c0c524e */
if(!s->budget--) { s->failed_pc=0x0c0c524eu; return 0; }
r[0]=0x00000018u;
goto P_0c0c5250;
P_0c0c5250: /* original d350, guest PC 0x0c0c5250 */
if(!s->budget--) { s->failed_pc=0x0c0c5250u; return 0; }
r[3]=read(ram,0x0c0c5394u,4);
goto P_0c0c5252;
P_0c0c5252: /* original f830, guest PC 0x0c0c5252 */
if(!s->budget--) { s->failed_pc=0x0c0c5252u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'+');
goto P_0c0c5254;
P_0c0c5254: /* original f6a6, guest PC 0x0c0c5254 */
if(!s->budget--) { s->failed_pc=0x0c0c5254u; return 0; }
vf3_matrix_load(s,ram,6,r[10]+r[0]);
goto P_0c0c5256;
P_0c0c5256: /* original 430b, guest PC 0x0c0c5256 */
if(!s->budget--) { s->failed_pc=0x0c0c5256u; return 0; }
target=r[3];
r[16]=0x0c0c525au;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c525au) { target=s->pc; goto dispatch; }
goto P_0c0c525a;
P_0c0c5258: /* original 34fc, guest PC 0x0c0c5258 */
if(!s->budget--) { s->failed_pc=0x0c0c5258u; return 0; }
r[4]+=r[15];
goto P_0c0c525a;
P_0c0c525a: /* original e014, guest PC 0x0c0c525a */
if(!s->budget--) { s->failed_pc=0x0c0c525au; return 0; }
r[0]=0x00000014u;
goto P_0c0c525c;
P_0c0c525c: /* original 948f, guest PC 0x0c0c525c */
if(!s->budget--) { s->failed_pc=0x0c0c525cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c537eu,2);
goto P_0c0c525e;
P_0c0c525e: /* original f9a6, guest PC 0x0c0c525e */
if(!s->budget--) { s->failed_pc=0x0c0c525eu; return 0; }
vf3_matrix_load(s,ram,9,r[10]+r[0]);
goto P_0c0c5260;
P_0c0c5260: /* original e010, guest PC 0x0c0c5260 */
if(!s->budget--) { s->failed_pc=0x0c0c5260u; return 0; }
r[0]=0x00000010u;
goto P_0c0c5262;
P_0c0c5262: /* original f8a6, guest PC 0x0c0c5262 */
if(!s->budget--) { s->failed_pc=0x0c0c5262u; return 0; }
vf3_matrix_load(s,ram,8,r[10]+r[0]);
goto P_0c0c5264;
P_0c0c5264: /* original e00c, guest PC 0x0c0c5264 */
if(!s->budget--) { s->failed_pc=0x0c0c5264u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c5266;
P_0c0c5266: /* original f7a6, guest PC 0x0c0c5266 */
if(!s->budget--) { s->failed_pc=0x0c0c5266u; return 0; }
vf3_matrix_load(s,ram,7,r[10]+r[0]);
goto P_0c0c5268;
P_0c0c5268: /* original e008, guest PC 0x0c0c5268 */
if(!s->budget--) { s->failed_pc=0x0c0c5268u; return 0; }
r[0]=0x00000008u;
goto P_0c0c526a;
P_0c0c526a: /* original f6a6, guest PC 0x0c0c526a */
if(!s->budget--) { s->failed_pc=0x0c0c526au; return 0; }
vf3_matrix_load(s,ram,6,r[10]+r[0]);
goto P_0c0c526c;
P_0c0c526c: /* original e004, guest PC 0x0c0c526c */
if(!s->budget--) { s->failed_pc=0x0c0c526cu; return 0; }
r[0]=0x00000004u;
goto P_0c0c526e;
P_0c0c526e: /* original f4a8, guest PC 0x0c0c526e */
if(!s->budget--) { s->failed_pc=0x0c0c526eu; return 0; }
vf3_matrix_load(s,ram,4,r[10]);
goto P_0c0c5270;
P_0c0c5270: /* original f5a6, guest PC 0x0c0c5270 */
if(!s->budget--) { s->failed_pc=0x0c0c5270u; return 0; }
vf3_matrix_load(s,ram,5,r[10]+r[0]);
goto P_0c0c5272;
P_0c0c5272: /* original 480b, guest PC 0x0c0c5272 */
if(!s->budget--) { s->failed_pc=0x0c0c5272u; return 0; }
target=r[8];
r[16]=0x0c0c5276u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5276u) { target=s->pc; goto dispatch; }
goto P_0c0c5276;
P_0c0c5274: /* original 34fc, guest PC 0x0c0c5274 */
if(!s->budget--) { s->failed_pc=0x0c0c5274u; return 0; }
r[4]+=r[15];
goto P_0c0c5276;
P_0c0c5276: /* original 53e8, guest PC 0x0c0c5276 */
if(!s->budget--) { s->failed_pc=0x0c0c5276u; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c0c5278;
P_0c0c5278: /* original d047, guest PC 0x0c0c5278 */
if(!s->budget--) { s->failed_pc=0x0c0c5278u; return 0; }
r[0]=read(ram,0x0c0c5398u,4);
goto P_0c0c527a;
P_0c0c527a: /* original 4300, guest PC 0x0c0c527a */
if(!s->budget--) { s->failed_pc=0x0c0c527au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c527c;
P_0c0c527c: /* original 023d, guest PC 0x0c0c527c */
if(!s->budget--) { s->failed_pc=0x0c0c527cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c527e;
P_0c0c527e: /* original 907e, guest PC 0x0c0c527e */
if(!s->budget--) { s->failed_pc=0x0c0c527eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c537eu,2);
goto P_0c0c5280;
P_0c0c5280: /* original 622d, guest PC 0x0c0c5280 */
if(!s->budget--) { s->failed_pc=0x0c0c5280u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c5282;
P_0c0c5282: /* original 0f26, guest PC 0x0c0c5282 */
if(!s->budget--) { s->failed_pc=0x0c0c5282u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0c5284;
P_0c0c5284: /* original 907c, guest PC 0x0c0c5284 */
if(!s->budget--) { s->failed_pc=0x0c0c5284u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5380u,2);
goto P_0c0c5286;
P_0c0c5286: /* original fff7, guest PC 0x0c0c5286 */
if(!s->budget--) { s->failed_pc=0x0c0c5286u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0c5288;
P_0c0c5288: /* original 9479, guest PC 0x0c0c5288 */
if(!s->budget--) { s->failed_pc=0x0c0c5288u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c537eu,2);
goto P_0c0c528a;
P_0c0c528a: /* original 4d0b, guest PC 0x0c0c528a */
if(!s->budget--) { s->failed_pc=0x0c0c528au; return 0; }
target=r[13];
r[16]=0x0c0c528eu;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c528eu) { target=s->pc; goto dispatch; }
goto P_0c0c528e;
P_0c0c528c: /* original 34fc, guest PC 0x0c0c528c */
if(!s->budget--) { s->failed_pc=0x0c0c528cu; return 0; }
r[4]+=r[15];
goto P_0c0c528e;
P_0c0c528e: /* original e050, guest PC 0x0c0c528e */
if(!s->budget--) { s->failed_pc=0x0c0c528eu; return 0; }
r[0]=0x00000050u;
goto P_0c0c5290;
P_0c0c5290: /* original 03fe, guest PC 0x0c0c5290 */
if(!s->budget--) { s->failed_pc=0x0c0c5290u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0c5292;
P_0c0c5292: /* original e04c, guest PC 0x0c0c5292 */
if(!s->budget--) { s->failed_pc=0x0c0c5292u; return 0; }
r[0]=0x0000004cu;
goto P_0c0c5294;
P_0c0c5294: /* original 02fe, guest PC 0x0c0c5294 */
if(!s->budget--) { s->failed_pc=0x0c0c5294u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0c5296;
P_0c0c5296: /* original e130, guest PC 0x0c0c5296 */
if(!s->budget--) { s->failed_pc=0x0c0c5296u; return 0; }
r[1]=0x00000030u;
goto P_0c0c5298;
P_0c0c5298: /* original 323c, guest PC 0x0c0c5298 */
if(!s->budget--) { s->failed_pc=0x0c0c5298u; return 0; }
r[2]+=r[3];
goto P_0c0c529a;
P_0c0c529a: /* original 3213, guest PC 0x0c0c529a */
if(!s->budget--) { s->failed_pc=0x0c0c529au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[1])!=0);
goto P_0c0c529c;
P_0c0c529c: /* original 2f22, guest PC 0x0c0c529c */
if(!s->budget--) { s->failed_pc=0x0c0c529cu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c529e;
P_0c0c529e: /* original 8939, guest PC 0x0c0c529e */
if(!s->budget--) { s->failed_pc=0x0c0c529eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5314; }
goto P_0c0c52a0;
P_0c0c52a0: /* original 4211, guest PC 0x0c0c52a0 */
if(!s->budget--) { s->failed_pc=0x0c0c52a0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c0c52a2;
P_0c0c52a2: /* original 8d01, guest PC 0x0c0c52a2 */
if(!s->budget--) { s->failed_pc=0x0c0c52a2u; return 0; }
cond=r[17]&1u;
r[4]=r[9];
if(cond) { goto P_0c0c52a8; }
goto P_0c0c52a6;
P_0c0c52a4: /* original 6493, guest PC 0x0c0c52a4 */
if(!s->budget--) { s->failed_pc=0x0c0c52a4u; return 0; }
r[4]=r[9];
goto P_0c0c52a6;
P_0c0c52a6: /* original 2fc2, guest PC 0x0c0c52a6 */
if(!s->budget--) { s->failed_pc=0x0c0c52a6u; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0c52a8;
P_0c0c52a8: /* original 4b0b, guest PC 0x0c0c52a8 */
if(!s->budget--) { s->failed_pc=0x0c0c52a8u; return 0; }
target=r[11];
r[16]=0x0c0c52acu;
r[4]+=0x00000002u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c52acu) { target=s->pc; goto dispatch; }
goto P_0c0c52ac;
P_0c0c52aa: /* original 7402, guest PC 0x0c0c52aa */
if(!s->budget--) { s->failed_pc=0x0c0c52aau; return 0; }
r[4]+=0x00000002u;
goto P_0c0c52ac;
P_0c0c52ac: /* original 63f2, guest PC 0x0c0c52ac */
if(!s->budget--) { s->failed_pc=0x0c0c52acu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c52ae;
P_0c0c52ae: /* original e231, guest PC 0x0c0c52ae */
if(!s->budget--) { s->failed_pc=0x0c0c52aeu; return 0; }
r[2]=0x00000031u;
goto P_0c0c52b0;
P_0c0c52b0: /* original 6a03, guest PC 0x0c0c52b0 */
if(!s->budget--) { s->failed_pc=0x0c0c52b0u; return 0; }
r[10]=r[0];
goto P_0c0c52b2;
P_0c0c52b2: /* original e01c, guest PC 0x0c0c52b2 */
if(!s->budget--) { s->failed_pc=0x0c0c52b2u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c52b4;
P_0c0c52b4: /* original 3238, guest PC 0x0c0c52b4 */
if(!s->budget--) { s->failed_pc=0x0c0c52b4u; return 0; }
r[2]-=r[3];
goto P_0c0c52b6;
P_0c0c52b6: /* original f7a6, guest PC 0x0c0c52b6 */
if(!s->budget--) { s->failed_pc=0x0c0c52b6u; return 0; }
vf3_matrix_load(s,ram,7,r[10]+r[0]);
goto P_0c0c52b8;
P_0c0c52b8: /* original 425a, guest PC 0x0c0c52b8 */
if(!s->budget--) { s->failed_pc=0x0c0c52b8u; return 0; }
r[53]=r[2];
goto P_0c0c52ba;
P_0c0c52ba: /* original c734, guest PC 0x0c0c52ba */
if(!s->budget--) { s->failed_pc=0x0c0c52bau; return 0; }
r[0]=0x0c0c538cu;
goto P_0c0c52bc;
P_0c0c52bc: /* original 52f6, guest PC 0x0c0c52bc */
if(!s->budget--) { s->failed_pc=0x0c0c52bcu; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c0c52be;
P_0c0c52be: /* original 945e, guest PC 0x0c0c52be */
if(!s->budget--) { s->failed_pc=0x0c0c52beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c537eu,2);
goto P_0c0c52c0;
P_0c0c52c0: /* original f32d, guest PC 0x0c0c52c0 */
if(!s->budget--) { s->failed_pc=0x0c0c52c0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c52c2;
P_0c0c52c2: /* original 435a, guest PC 0x0c0c52c2 */
if(!s->budget--) { s->failed_pc=0x0c0c52c2u; return 0; }
r[53]=r[3];
goto P_0c0c52c4;
P_0c0c52c4: /* original d333, guest PC 0x0c0c52c4 */
if(!s->budget--) { s->failed_pc=0x0c0c52c4u; return 0; }
r[3]=read(ram,0x0c0c5394u,4);
goto P_0c0c52c6;
P_0c0c52c6: /* original f4fc, guest PC 0x0c0c52c6 */
if(!s->budget--) { s->failed_pc=0x0c0c52c6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0c52c8;
P_0c0c52c8: /* original f22d, guest PC 0x0c0c52c8 */
if(!s->budget--) { s->failed_pc=0x0c0c52c8u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c52ca;
P_0c0c52ca: /* original f732, guest PC 0x0c0c52ca */
if(!s->budget--) { s->failed_pc=0x0c0c52cau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c0c52cc;
P_0c0c52cc: /* original f308, guest PC 0x0c0c52cc */
if(!s->budget--) { s->failed_pc=0x0c0c52ccu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c52ce;
P_0c0c52ce: /* original d030, guest PC 0x0c0c52ce */
if(!s->budget--) { s->failed_pc=0x0c0c52ceu; return 0; }
r[0]=read(ram,0x0c0c5390u,4);
goto P_0c0c52d0;
P_0c0c52d0: /* original f826, guest PC 0x0c0c52d0 */
if(!s->budget--) { s->failed_pc=0x0c0c52d0u; return 0; }
vf3_matrix_load(s,ram,8,r[2]+r[0]);
goto P_0c0c52d2;
P_0c0c52d2: /* original e018, guest PC 0x0c0c52d2 */
if(!s->budget--) { s->failed_pc=0x0c0c52d2u; return 0; }
r[0]=0x00000018u;
goto P_0c0c52d4;
P_0c0c52d4: /* original f6a6, guest PC 0x0c0c52d4 */
if(!s->budget--) { s->failed_pc=0x0c0c52d4u; return 0; }
vf3_matrix_load(s,ram,6,r[10]+r[0]);
goto P_0c0c52d6;
P_0c0c52d6: /* original c731, guest PC 0x0c0c52d6 */
if(!s->budget--) { s->failed_pc=0x0c0c52d6u; return 0; }
r[0]=0x0c0c539cu;
goto P_0c0c52d8;
P_0c0c52d8: /* original f108, guest PC 0x0c0c52d8 */
if(!s->budget--) { s->failed_pc=0x0c0c52d8u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c0c52da;
P_0c0c52da: /* original f830, guest PC 0x0c0c52da */
if(!s->budget--) { s->failed_pc=0x0c0c52dau; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'+');
goto P_0c0c52dc;
P_0c0c52dc: /* original f52c, guest PC 0x0c0c52dc */
if(!s->budget--) { s->failed_pc=0x0c0c52dcu; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c0c52de;
P_0c0c52de: /* original f512, guest PC 0x0c0c52de */
if(!s->budget--) { s->failed_pc=0x0c0c52deu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[1],r[18],'*');
goto P_0c0c52e0;
P_0c0c52e0: /* original 430b, guest PC 0x0c0c52e0 */
if(!s->budget--) { s->failed_pc=0x0c0c52e0u; return 0; }
target=r[3];
r[16]=0x0c0c52e4u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c52e4u) { target=s->pc; goto dispatch; }
goto P_0c0c52e4;
P_0c0c52e2: /* original 34fc, guest PC 0x0c0c52e2 */
if(!s->budget--) { s->failed_pc=0x0c0c52e2u; return 0; }
r[4]+=r[15];
goto P_0c0c52e4;
P_0c0c52e4: /* original e014, guest PC 0x0c0c52e4 */
if(!s->budget--) { s->failed_pc=0x0c0c52e4u; return 0; }
r[0]=0x00000014u;
goto P_0c0c52e6;
P_0c0c52e6: /* original 944a, guest PC 0x0c0c52e6 */
if(!s->budget--) { s->failed_pc=0x0c0c52e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c537eu,2);
goto P_0c0c52e8;
P_0c0c52e8: /* original f9a6, guest PC 0x0c0c52e8 */
if(!s->budget--) { s->failed_pc=0x0c0c52e8u; return 0; }
vf3_matrix_load(s,ram,9,r[10]+r[0]);
goto P_0c0c52ea;
P_0c0c52ea: /* original e010, guest PC 0x0c0c52ea */
if(!s->budget--) { s->failed_pc=0x0c0c52eau; return 0; }
r[0]=0x00000010u;
goto P_0c0c52ec;
P_0c0c52ec: /* original f8a6, guest PC 0x0c0c52ec */
if(!s->budget--) { s->failed_pc=0x0c0c52ecu; return 0; }
vf3_matrix_load(s,ram,8,r[10]+r[0]);
goto P_0c0c52ee;
P_0c0c52ee: /* original e00c, guest PC 0x0c0c52ee */
if(!s->budget--) { s->failed_pc=0x0c0c52eeu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c52f0;
P_0c0c52f0: /* original f7a6, guest PC 0x0c0c52f0 */
if(!s->budget--) { s->failed_pc=0x0c0c52f0u; return 0; }
vf3_matrix_load(s,ram,7,r[10]+r[0]);
goto P_0c0c52f2;
P_0c0c52f2: /* original e008, guest PC 0x0c0c52f2 */
if(!s->budget--) { s->failed_pc=0x0c0c52f2u; return 0; }
r[0]=0x00000008u;
goto P_0c0c52f4;
P_0c0c52f4: /* original f6a6, guest PC 0x0c0c52f4 */
if(!s->budget--) { s->failed_pc=0x0c0c52f4u; return 0; }
vf3_matrix_load(s,ram,6,r[10]+r[0]);
goto P_0c0c52f6;
P_0c0c52f6: /* original e004, guest PC 0x0c0c52f6 */
if(!s->budget--) { s->failed_pc=0x0c0c52f6u; return 0; }
r[0]=0x00000004u;
goto P_0c0c52f8;
P_0c0c52f8: /* original f4a8, guest PC 0x0c0c52f8 */
if(!s->budget--) { s->failed_pc=0x0c0c52f8u; return 0; }
vf3_matrix_load(s,ram,4,r[10]);
goto P_0c0c52fa;
P_0c0c52fa: /* original f5a6, guest PC 0x0c0c52fa */
if(!s->budget--) { s->failed_pc=0x0c0c52fau; return 0; }
vf3_matrix_load(s,ram,5,r[10]+r[0]);
goto P_0c0c52fc;
P_0c0c52fc: /* original 480b, guest PC 0x0c0c52fc */
if(!s->budget--) { s->failed_pc=0x0c0c52fcu; return 0; }
target=r[8];
r[16]=0x0c0c5300u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5300u) { target=s->pc; goto dispatch; }
goto P_0c0c5300;
P_0c0c52fe: /* original 34fc, guest PC 0x0c0c52fe */
if(!s->budget--) { s->failed_pc=0x0c0c52feu; return 0; }
r[4]+=r[15];
goto P_0c0c5300;
P_0c0c5300: /* original 53e8, guest PC 0x0c0c5300 */
if(!s->budget--) { s->failed_pc=0x0c0c5300u; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c0c5302;
P_0c0c5302: /* original d025, guest PC 0x0c0c5302 */
if(!s->budget--) { s->failed_pc=0x0c0c5302u; return 0; }
r[0]=read(ram,0x0c0c5398u,4);
goto P_0c0c5304;
P_0c0c5304: /* original 4300, guest PC 0x0c0c5304 */
if(!s->budget--) { s->failed_pc=0x0c0c5304u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c5306;
P_0c0c5306: /* original 023d, guest PC 0x0c0c5306 */
if(!s->budget--) { s->failed_pc=0x0c0c5306u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c5308;
P_0c0c5308: /* original 9039, guest PC 0x0c0c5308 */
if(!s->budget--) { s->failed_pc=0x0c0c5308u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c537eu,2);
goto P_0c0c530a;
P_0c0c530a: /* original 622d, guest PC 0x0c0c530a */
if(!s->budget--) { s->failed_pc=0x0c0c530au; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c530c;
P_0c0c530c: /* original 0f26, guest PC 0x0c0c530c */
if(!s->budget--) { s->failed_pc=0x0c0c530cu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0c530e;
P_0c0c530e: /* original 9436, guest PC 0x0c0c530e */
if(!s->budget--) { s->failed_pc=0x0c0c530eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c537eu,2);
goto P_0c0c5310;
P_0c0c5310: /* original 4d0b, guest PC 0x0c0c5310 */
if(!s->budget--) { s->failed_pc=0x0c0c5310u; return 0; }
target=r[13];
r[16]=0x0c0c5314u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5314u) { target=s->pc; goto dispatch; }
goto P_0c0c5314;
P_0c0c5312: /* original 34fc, guest PC 0x0c0c5312 */
if(!s->budget--) { s->failed_pc=0x0c0c5312u; return 0; }
r[4]+=r[15];
goto P_0c0c5314;
P_0c0c5314: /* original d223, guest PC 0x0c0c5314 */
if(!s->budget--) { s->failed_pc=0x0c0c5314u; return 0; }
r[2]=read(ram,0x0c0c53a4u,4);
goto P_0c0c5316;
P_0c0c5316: /* original d022, guest PC 0x0c0c5316 */
if(!s->budget--) { s->failed_pc=0x0c0c5316u; return 0; }
r[0]=read(ram,0x0c0c53a0u,4);
goto P_0c0c5318;
P_0c0c5318: /* original 6320, guest PC 0x0c0c5318 */
if(!s->budget--) { s->failed_pc=0x0c0c5318u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c0c531a;
P_0c0c531a: /* original 9132, guest PC 0x0c0c531a */
if(!s->budget--) { s->failed_pc=0x0c0c531au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5382u,2);
goto P_0c0c531c;
P_0c0c531c: /* original 633c, guest PC 0x0c0c531c */
if(!s->budget--) { s->failed_pc=0x0c0c531cu; return 0; }
r[3]=r[3]&255u;
goto P_0c0c531e;
P_0c0c531e: /* original 4308, guest PC 0x0c0c531e */
if(!s->budget--) { s->failed_pc=0x0c0c531eu; return 0; }
r[3]<<=2;
goto P_0c0c5320;
P_0c0c5320: /* original 033e, guest PC 0x0c0c5320 */
if(!s->budget--) { s->failed_pc=0x0c0c5320u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c0c5322;
P_0c0c5322: /* original 902f, guest PC 0x0c0c5322 */
if(!s->budget--) { s->failed_pc=0x0c0c5322u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5384u,2);
goto P_0c0c5324;
P_0c0c5324: /* original 231b, guest PC 0x0c0c5324 */
if(!s->budget--) { s->failed_pc=0x0c0c5324u; return 0; }
r[3]|=r[1];
goto P_0c0c5326;
P_0c0c5326: /* original 0f36, guest PC 0x0c0c5326 */
if(!s->budget--) { s->failed_pc=0x0c0c5326u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0c5328;
P_0c0c5328: /* original 4b0b, guest PC 0x0c0c5328 */
if(!s->budget--) { s->failed_pc=0x0c0c5328u; return 0; }
target=r[11];
r[16]=0x0c0c532cu;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c532cu) { target=s->pc; goto dispatch; }
goto P_0c0c532c;
P_0c0c532a: /* original 6493, guest PC 0x0c0c532a */
if(!s->budget--) { s->failed_pc=0x0c0c532au; return 0; }
r[4]=r[9];
goto P_0c0c532c;
P_0c0c532c: /* original 6e03, guest PC 0x0c0c532c */
if(!s->budget--) { s->failed_pc=0x0c0c532cu; return 0; }
r[14]=r[0];
goto P_0c0c532e;
P_0c0c532e: /* original e048, guest PC 0x0c0c532e */
if(!s->budget--) { s->failed_pc=0x0c0c532eu; return 0; }
r[0]=0x00000048u;
goto P_0c0c5330;
P_0c0c5330: /* original 00fe, guest PC 0x0c0c5330 */
if(!s->budget--) { s->failed_pc=0x0c0c5330u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c0c5332;
P_0c0c5332: /* original d31d, guest PC 0x0c0c5332 */
if(!s->budget--) { s->failed_pc=0x0c0c5332u; return 0; }
r[3]=read(ram,0x0c0c53a8u,4);
goto P_0c0c5334;
P_0c0c5334: /* original 4008, guest PC 0x0c0c5334 */
if(!s->budget--) { s->failed_pc=0x0c0c5334u; return 0; }
r[0]<<=2;
goto P_0c0c5336;
P_0c0c5336: /* original 4000, guest PC 0x0c0c5336 */
if(!s->budget--) { s->failed_pc=0x0c0c5336u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c5338;
P_0c0c5338: /* original 430b, guest PC 0x0c0c5338 */
if(!s->budget--) { s->failed_pc=0x0c0c5338u; return 0; }
target=r[3];
r[16]=0x0c0c533cu;
r[1]=read(ram,r[15]+60,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c533cu) { target=s->pc; goto dispatch; }
goto P_0c0c533c;
P_0c0c533a: /* original 51ff, guest PC 0x0c0c533a */
if(!s->budget--) { s->failed_pc=0x0c0c533au; return 0; }
r[1]=read(ram,r[15]+60,4);
goto P_0c0c533c;
P_0c0c533c: /* original 650b, guest PC 0x0c0c533c */
if(!s->budget--) { s->failed_pc=0x0c0c533cu; return 0; }
r[5]=0u-r[0];
goto P_0c0c533e;
P_0c0c533e: /* original 53fc, guest PC 0x0c0c533e */
if(!s->budget--) { s->failed_pc=0x0c0c533eu; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c0c5340;
P_0c0c5340: /* original 455a, guest PC 0x0c0c5340 */
if(!s->budget--) { s->failed_pc=0x0c0c5340u; return 0; }
r[53]=r[5];
goto P_0c0c5342;
P_0c0c5342: /* original d013, guest PC 0x0c0c5342 */
if(!s->budget--) { s->failed_pc=0x0c0c5342u; return 0; }
r[0]=read(ram,0x0c0c5390u,4);
goto P_0c0c5344;
P_0c0c5344: /* original 941b, guest PC 0x0c0c5344 */
if(!s->budget--) { s->failed_pc=0x0c0c5344u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c537eu,2);
goto P_0c0c5346;
P_0c0c5346: /* original f32d, guest PC 0x0c0c5346 */
if(!s->budget--) { s->failed_pc=0x0c0c5346u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c5348;
P_0c0c5348: /* original 435a, guest PC 0x0c0c5348 */
if(!s->budget--) { s->failed_pc=0x0c0c5348u; return 0; }
r[53]=r[3];
goto P_0c0c534a;
P_0c0c534a: /* original 53f6, guest PC 0x0c0c534a */
if(!s->budget--) { s->failed_pc=0x0c0c534au; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0c534c;
P_0c0c534c: /* original f836, guest PC 0x0c0c534c */
if(!s->budget--) { s->failed_pc=0x0c0c534cu; return 0; }
vf3_matrix_load(s,ram,8,r[3]+r[0]);
goto P_0c0c534e;
P_0c0c534e: /* original e01c, guest PC 0x0c0c534e */
if(!s->budget--) { s->failed_pc=0x0c0c534eu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c5350;
P_0c0c5350: /* original f7e6, guest PC 0x0c0c5350 */
if(!s->budget--) { s->failed_pc=0x0c0c5350u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c5352;
P_0c0c5352: /* original e018, guest PC 0x0c0c5352 */
if(!s->budget--) { s->failed_pc=0x0c0c5352u; return 0; }
r[0]=0x00000018u;
goto P_0c0c5354;
P_0c0c5354: /* original fe3c, guest PC 0x0c0c5354 */
if(!s->budget--) { s->failed_pc=0x0c0c5354u; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c0c5356;
P_0c0c5356: /* original f32d, guest PC 0x0c0c5356 */
if(!s->budget--) { s->failed_pc=0x0c0c5356u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c5358;
P_0c0c5358: /* original f6e6, guest PC 0x0c0c5358 */
if(!s->budget--) { s->failed_pc=0x0c0c5358u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c535a;
P_0c0c535a: /* original d30e, guest PC 0x0c0c535a */
if(!s->budget--) { s->failed_pc=0x0c0c535au; return 0; }
r[3]=read(ram,0x0c0c5394u,4);
goto P_0c0c535c;
P_0c0c535c: /* original f4ec, guest PC 0x0c0c535c */
if(!s->budget--) { s->failed_pc=0x0c0c535cu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0c535e;
P_0c0c535e: /* original fd3c, guest PC 0x0c0c535e */
if(!s->budget--) { s->failed_pc=0x0c0c535eu; return 0; }
vf3_matrix_move(s,13,3);
goto P_0c0c5360;
P_0c0c5360: /* original f53c, guest PC 0x0c0c5360 */
if(!s->budget--) { s->failed_pc=0x0c0c5360u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0c5362;
P_0c0c5362: /* original 430b, guest PC 0x0c0c5362 */
if(!s->budget--) { s->failed_pc=0x0c0c5362u; return 0; }
target=r[3];
r[16]=0x0c0c5366u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5366u) { target=s->pc; goto dispatch; }
goto P_0c0c5366;
P_0c0c5364: /* original 34fc, guest PC 0x0c0c5364 */
if(!s->budget--) { s->failed_pc=0x0c0c5364u; return 0; }
r[4]+=r[15];
goto P_0c0c5366;
P_0c0c5366: /* original e014, guest PC 0x0c0c5366 */
if(!s->budget--) { s->failed_pc=0x0c0c5366u; return 0; }
r[0]=0x00000014u;
goto P_0c0c5368;
P_0c0c5368: /* original f39d, guest PC 0x0c0c5368 */
if(!s->budget--) { s->failed_pc=0x0c0c5368u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c536a;
P_0c0c536a: /* original f9e6, guest PC 0x0c0c536a */
if(!s->budget--) { s->failed_pc=0x0c0c536au; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c0c536c;
P_0c0c536c: /* original e010, guest PC 0x0c0c536c */
if(!s->budget--) { s->failed_pc=0x0c0c536cu; return 0; }
r[0]=0x00000010u;
goto P_0c0c536e;
P_0c0c536e: /* original f8e6, guest PC 0x0c0c536e */
if(!s->budget--) { s->failed_pc=0x0c0c536eu; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0c5370;
P_0c0c5370: /* original e00c, guest PC 0x0c0c5370 */
if(!s->budget--) { s->failed_pc=0x0c0c5370u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c5372;
P_0c0c5372: /* original f7e6, guest PC 0x0c0c5372 */
if(!s->budget--) { s->failed_pc=0x0c0c5372u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c5374;
P_0c0c5374: /* original e008, guest PC 0x0c0c5374 */
if(!s->budget--) { s->failed_pc=0x0c0c5374u; return 0; }
r[0]=0x00000008u;
goto P_0c0c5376;
P_0c0c5376: /* original f6e6, guest PC 0x0c0c5376 */
if(!s->budget--) { s->failed_pc=0x0c0c5376u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c5378;
P_0c0c5378: /* original f630, guest PC 0x0c0c5378 */
if(!s->budget--) { s->failed_pc=0x0c0c5378u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
goto P_0c0c537a;
P_0c0c537a: /* original a017, guest PC 0x0c0c537a */
if(!s->budget--) { s->failed_pc=0x0c0c537au; return 0; }
goto P_0c0c53ac;
P_0c0c537c: /* original 0009, guest PC 0x0c0c537c */
if(!s->budget--) { s->failed_pc=0x0c0c537cu; return 0; }
return vf3_matrix_family(0x0c0c537eu,s,ram);
P_0c0c53ac: /* original e004, guest PC 0x0c0c53ac */
if(!s->budget--) { s->failed_pc=0x0c0c53acu; return 0; }
r[0]=0x00000004u;
goto P_0c0c53ae;
P_0c0c53ae: /* original 94b5, guest PC 0x0c0c53ae */
if(!s->budget--) { s->failed_pc=0x0c0c53aeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c551cu,2);
goto P_0c0c53b0;
P_0c0c53b0: /* original f4e8, guest PC 0x0c0c53b0 */
if(!s->budget--) { s->failed_pc=0x0c0c53b0u; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
goto P_0c0c53b2;
P_0c0c53b2: /* original f5e6, guest PC 0x0c0c53b2 */
if(!s->budget--) { s->failed_pc=0x0c0c53b2u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0c53b4;
P_0c0c53b4: /* original 480b, guest PC 0x0c0c53b4 */
if(!s->budget--) { s->failed_pc=0x0c0c53b4u; return 0; }
target=r[8];
r[16]=0x0c0c53b8u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c53b8u) { target=s->pc; goto dispatch; }
goto P_0c0c53b8;
P_0c0c53b6: /* original 34fc, guest PC 0x0c0c53b6 */
if(!s->budget--) { s->failed_pc=0x0c0c53b6u; return 0; }
r[4]+=r[15];
goto P_0c0c53b8;
P_0c0c53b8: /* original e008, guest PC 0x0c0c53b8 */
if(!s->budget--) { s->failed_pc=0x0c0c53b8u; return 0; }
r[0]=0x00000008u;
goto P_0c0c53ba;
P_0c0c53ba: /* original f39d, guest PC 0x0c0c53ba */
if(!s->budget--) { s->failed_pc=0x0c0c53bau; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c53bc;
P_0c0c53bc: /* original f2e6, guest PC 0x0c0c53bc */
if(!s->budget--) { s->failed_pc=0x0c0c53bcu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0c53be;
P_0c0c53be: /* original f231, guest PC 0x0c0c53be */
if(!s->budget--) { s->failed_pc=0x0c0c53beu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0c53c0;
P_0c0c53c0: /* original fe27, guest PC 0x0c0c53c0 */
if(!s->budget--) { s->failed_pc=0x0c0c53c0u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0c53c2;
P_0c0c53c2: /* original 53e8, guest PC 0x0c0c53c2 */
if(!s->budget--) { s->failed_pc=0x0c0c53c2u; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c0c53c4;
P_0c0c53c4: /* original d05a, guest PC 0x0c0c53c4 */
if(!s->budget--) { s->failed_pc=0x0c0c53c4u; return 0; }
r[0]=read(ram,0x0c0c5530u,4);
goto P_0c0c53c6;
P_0c0c53c6: /* original 4300, guest PC 0x0c0c53c6 */
if(!s->budget--) { s->failed_pc=0x0c0c53c6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c53c8;
P_0c0c53c8: /* original 023d, guest PC 0x0c0c53c8 */
if(!s->budget--) { s->failed_pc=0x0c0c53c8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c53ca;
P_0c0c53ca: /* original 90a7, guest PC 0x0c0c53ca */
if(!s->budget--) { s->failed_pc=0x0c0c53cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c551cu,2);
goto P_0c0c53cc;
P_0c0c53cc: /* original 622d, guest PC 0x0c0c53cc */
if(!s->budget--) { s->failed_pc=0x0c0c53ccu; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c53ce;
P_0c0c53ce: /* original 0f26, guest PC 0x0c0c53ce */
if(!s->budget--) { s->failed_pc=0x0c0c53ceu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0c53d0;
P_0c0c53d0: /* original d359, guest PC 0x0c0c53d0 */
if(!s->budget--) { s->failed_pc=0x0c0c53d0u; return 0; }
r[3]=read(ram,0x0c0c5538u,4);
goto P_0c0c53d2;
P_0c0c53d2: /* original da58, guest PC 0x0c0c53d2 */
if(!s->budget--) { s->failed_pc=0x0c0c53d2u; return 0; }
r[10]=read(ram,0x0c0c5534u,4);
goto P_0c0c53d4;
P_0c0c53d4: /* original 6030, guest PC 0x0c0c53d4 */
if(!s->budget--) { s->failed_pc=0x0c0c53d4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0c53d6;
P_0c0c53d6: /* original 94a2, guest PC 0x0c0c53d6 */
if(!s->budget--) { s->failed_pc=0x0c0c53d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c551eu,2);
goto P_0c0c53d8;
P_0c0c53d8: /* original 600c, guest PC 0x0c0c53d8 */
if(!s->budget--) { s->failed_pc=0x0c0c53d8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c53da;
P_0c0c53da: /* original c90f, guest PC 0x0c0c53da */
if(!s->budget--) { s->failed_pc=0x0c0c53dau; return 0; }
r[0]&=15u;
goto P_0c0c53dc;
P_0c0c53dc: /* original 880d, guest PC 0x0c0c53dc */
if(!s->budget--) { s->failed_pc=0x0c0c53dcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0c53de;
P_0c0c53de: /* original 8b01, guest PC 0x0c0c53de */
if(!s->budget--) { s->failed_pc=0x0c0c53deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c53e4; }
goto P_0c0c53e0;
P_0c0c53e0: /* original a110, guest PC 0x0c0c53e0 */
if(!s->budget--) { s->failed_pc=0x0c0c53e0u; return 0; }
goto P_0c0c5604;
P_0c0c53e2: /* original 0009, guest PC 0x0c0c53e2 */
if(!s->budget--) { s->failed_pc=0x0c0c53e2u; return 0; }
goto P_0c0c53e4;
P_0c0c53e4: /* original 50e8, guest PC 0x0c0c53e4 */
if(!s->budget--) { s->failed_pc=0x0c0c53e4u; return 0; }
r[0]=read(ram,r[14]+32,4);
goto P_0c0c53e6;
P_0c0c53e6: /* original 882c, guest PC 0x0c0c53e6 */
if(!s->budget--) { s->failed_pc=0x0c0c53e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002cu)!=0);
goto P_0c0c53e8;
P_0c0c53e8: /* original 8d05, guest PC 0x0c0c53e8 */
if(!s->budget--) { s->failed_pc=0x0c0c53e8u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c0c53f6; }
goto P_0c0c53ec;
P_0c0c53ea: /* original 6503, guest PC 0x0c0c53ea */
if(!s->budget--) { s->failed_pc=0x0c0c53eau; return 0; }
r[5]=r[0];
goto P_0c0c53ec;
P_0c0c53ec: /* original 6053, guest PC 0x0c0c53ec */
if(!s->budget--) { s->failed_pc=0x0c0c53ecu; return 0; }
r[0]=r[5];
goto P_0c0c53ee;
P_0c0c53ee: /* original 8834, guest PC 0x0c0c53ee */
if(!s->budget--) { s->failed_pc=0x0c0c53eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000034u)!=0);
goto P_0c0c53f0;
P_0c0c53f0: /* original 8901, guest PC 0x0c0c53f0 */
if(!s->budget--) { s->failed_pc=0x0c0c53f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c53f6; }
goto P_0c0c53f2;
P_0c0c53f2: /* original a0d4, guest PC 0x0c0c53f2 */
if(!s->budget--) { s->failed_pc=0x0c0c53f2u; return 0; }
goto P_0c0c559e;
P_0c0c53f4: /* original 0009, guest PC 0x0c0c53f4 */
if(!s->budget--) { s->failed_pc=0x0c0c53f4u; return 0; }
goto P_0c0c53f6;
P_0c0c53f6: /* original 9093, guest PC 0x0c0c53f6 */
if(!s->budget--) { s->failed_pc=0x0c0c53f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5520u,2);
goto P_0c0c53f8;
P_0c0c53f8: /* original 03fe, guest PC 0x0c0c53f8 */
if(!s->budget--) { s->failed_pc=0x0c0c53f8u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0c53fa;
P_0c0c53fa: /* original 9091, guest PC 0x0c0c53fa */
if(!s->budget--) { s->failed_pc=0x0c0c53fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5520u,2);
goto P_0c0c53fc;
P_0c0c53fc: /* original 2349, guest PC 0x0c0c53fc */
if(!s->budget--) { s->failed_pc=0x0c0c53fcu; return 0; }
r[3]&=r[4];
goto P_0c0c53fe;
P_0c0c53fe: /* original 0f36, guest PC 0x0c0c53fe */
if(!s->budget--) { s->failed_pc=0x0c0c53feu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0c5400;
P_0c0c5400: /* original e008, guest PC 0x0c0c5400 */
if(!s->budget--) { s->failed_pc=0x0c0c5400u; return 0; }
r[0]=0x00000008u;
goto P_0c0c5402;
P_0c0c5402: /* original fde6, guest PC 0x0c0c5402 */
if(!s->budget--) { s->failed_pc=0x0c0c5402u; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c0c5404;
P_0c0c5404: /* original e014, guest PC 0x0c0c5404 */
if(!s->budget--) { s->failed_pc=0x0c0c5404u; return 0; }
r[0]=0x00000014u;
goto P_0c0c5406;
P_0c0c5406: /* original 9489, guest PC 0x0c0c5406 */
if(!s->budget--) { s->failed_pc=0x0c0c5406u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c551cu,2);
goto P_0c0c5408;
P_0c0c5408: /* original fee6, guest PC 0x0c0c5408 */
if(!s->budget--) { s->failed_pc=0x0c0c5408u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c0c540a;
P_0c0c540a: /* original 4d0b, guest PC 0x0c0c540a */
if(!s->budget--) { s->failed_pc=0x0c0c540au; return 0; }
target=r[13];
r[16]=0x0c0c540eu;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c540eu) { target=s->pc; goto dispatch; }
goto P_0c0c540e;
P_0c0c540c: /* original 34fc, guest PC 0x0c0c540c */
if(!s->budget--) { s->failed_pc=0x0c0c540cu; return 0; }
r[4]+=r[15];
goto P_0c0c540e;
P_0c0c540e: /* original 9285, guest PC 0x0c0c540e */
if(!s->budget--) { s->failed_pc=0x0c0c540eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c551cu,2);
goto P_0c0c5410;
P_0c0c5410: /* original 9187, guest PC 0x0c0c5410 */
if(!s->budget--) { s->failed_pc=0x0c0c5410u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5522u,2);
goto P_0c0c5412;
P_0c0c5412: /* original d34a, guest PC 0x0c0c5412 */
if(!s->budget--) { s->failed_pc=0x0c0c5412u; return 0; }
r[3]=read(ram,0x0c0c553cu,4);
goto P_0c0c5414;
P_0c0c5414: /* original 32fc, guest PC 0x0c0c5414 */
if(!s->budget--) { s->failed_pc=0x0c0c5414u; return 0; }
r[2]+=r[15];
goto P_0c0c5416;
P_0c0c5416: /* original 31fc, guest PC 0x0c0c5416 */
if(!s->budget--) { s->failed_pc=0x0c0c5416u; return 0; }
r[1]+=r[15];
goto P_0c0c5418;
P_0c0c5418: /* original 430b, guest PC 0x0c0c5418 */
if(!s->budget--) { s->failed_pc=0x0c0c5418u; return 0; }
target=r[3];
r[16]=0x0c0c541cu;
r[0]=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c541cu) { target=s->pc; goto dispatch; }
goto P_0c0c541c;
P_0c0c541a: /* original e034, guest PC 0x0c0c541a */
if(!s->budget--) { s->failed_pc=0x0c0c541au; return 0; }
r[0]=0x00000034u;
goto P_0c0c541c;
P_0c0c541c: /* original 9082, guest PC 0x0c0c541c */
if(!s->budget--) { s->failed_pc=0x0c0c541cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5524u,2);
goto P_0c0c541e;
P_0c0c541e: /* original f2a8, guest PC 0x0c0c541e */
if(!s->budget--) { s->failed_pc=0x0c0c541eu; return 0; }
vf3_matrix_load(s,ram,2,r[10]);
goto P_0c0c5420;
P_0c0c5420: /* original f3f6, guest PC 0x0c0c5420 */
if(!s->budget--) { s->failed_pc=0x0c0c5420u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5422;
P_0c0c5422: /* original f0dc, guest PC 0x0c0c5422 */
if(!s->budget--) { s->failed_pc=0x0c0c5422u; return 0; }
vf3_matrix_move(s,0,13);
goto P_0c0c5424;
P_0c0c5424: /* original f32e, guest PC 0x0c0c5424 */
if(!s->budget--) { s->failed_pc=0x0c0c5424u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0c5426;
P_0c0c5426: /* original 907d, guest PC 0x0c0c5426 */
if(!s->budget--) { s->failed_pc=0x0c0c5426u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5524u,2);
goto P_0c0c5428;
P_0c0c5428: /* original ff37, guest PC 0x0c0c5428 */
if(!s->budget--) { s->failed_pc=0x0c0c5428u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c542a;
P_0c0c542a: /* original c745, guest PC 0x0c0c542a */
if(!s->budget--) { s->failed_pc=0x0c0c542au; return 0; }
r[0]=0x0c0c5540u;
goto P_0c0c542c;
P_0c0c542c: /* original ff08, guest PC 0x0c0c542c */
if(!s->budget--) { s->failed_pc=0x0c0c542cu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0c542e;
P_0c0c542e: /* original f3f5, guest PC 0x0c0c542e */
if(!s->budget--) { s->failed_pc=0x0c0c542eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0c5430;
P_0c0c5430: /* original 8b01, guest PC 0x0c0c5430 */
if(!s->budget--) { s->failed_pc=0x0c0c5430u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5436; }
goto P_0c0c5432;
P_0c0c5432: /* original a302, guest PC 0x0c0c5432 */
if(!s->budget--) { s->failed_pc=0x0c0c5432u; return 0; }
goto P_0c0c5a3a;
P_0c0c5434: /* original 0009, guest PC 0x0c0c5434 */
if(!s->budget--) { s->failed_pc=0x0c0c5434u; return 0; }
goto P_0c0c5436;
P_0c0c5436: /* original c743, guest PC 0x0c0c5436 */
if(!s->budget--) { s->failed_pc=0x0c0c5436u; return 0; }
r[0]=0x0c0c5544u;
goto P_0c0c5438;
P_0c0c5438: /* original f2ec, guest PC 0x0c0c5438 */
if(!s->budget--) { s->failed_pc=0x0c0c5438u; return 0; }
vf3_matrix_move(s,2,14);
goto P_0c0c543a;
P_0c0c543a: /* original f308, guest PC 0x0c0c543a */
if(!s->budget--) { s->failed_pc=0x0c0c543au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c543c;
P_0c0c543c: /* original 9073, guest PC 0x0c0c543c */
if(!s->budget--) { s->failed_pc=0x0c0c543cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5526u,2);
goto P_0c0c543e;
P_0c0c543e: /* original f232, guest PC 0x0c0c543e */
if(!s->budget--) { s->failed_pc=0x0c0c543eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0c5440;
P_0c0c5440: /* original ff27, guest PC 0x0c0c5440 */
if(!s->budget--) { s->failed_pc=0x0c0c5440u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c5442;
P_0c0c5442: /* original c741, guest PC 0x0c0c5442 */
if(!s->budget--) { s->failed_pc=0x0c0c5442u; return 0; }
r[0]=0x0c0c5548u;
goto P_0c0c5444;
P_0c0c5444: /* original f208, guest PC 0x0c0c5444 */
if(!s->budget--) { s->failed_pc=0x0c0c5444u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c5446;
P_0c0c5446: /* original e038, guest PC 0x0c0c5446 */
if(!s->budget--) { s->failed_pc=0x0c0c5446u; return 0; }
r[0]=0x00000038u;
goto P_0c0c5448;
P_0c0c5448: /* original f1ec, guest PC 0x0c0c5448 */
if(!s->budget--) { s->failed_pc=0x0c0c5448u; return 0; }
vf3_matrix_move(s,1,14);
goto P_0c0c544a;
P_0c0c544a: /* original f122, guest PC 0x0c0c544a */
if(!s->budget--) { s->failed_pc=0x0c0c544au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0c544c;
P_0c0c544c: /* original ff17, guest PC 0x0c0c544c */
if(!s->budget--) { s->failed_pc=0x0c0c544cu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c544e;
P_0c0c544e: /* original 906b, guest PC 0x0c0c544e */
if(!s->budget--) { s->failed_pc=0x0c0c544eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5528u,2);
goto P_0c0c5450;
P_0c0c5450: /* original ff17, guest PC 0x0c0c5450 */
if(!s->budget--) { s->failed_pc=0x0c0c5450u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c5452;
P_0c0c5452: /* original c73e, guest PC 0x0c0c5452 */
if(!s->budget--) { s->failed_pc=0x0c0c5452u; return 0; }
r[0]=0x0c0c554cu;
goto P_0c0c5454;
P_0c0c5454: /* original f308, guest PC 0x0c0c5454 */
if(!s->budget--) { s->failed_pc=0x0c0c5454u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c5456;
P_0c0c5456: /* original 9068, guest PC 0x0c0c5456 */
if(!s->budget--) { s->failed_pc=0x0c0c5456u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c552au,2);
goto P_0c0c5458;
P_0c0c5458: /* original f1f6, guest PC 0x0c0c5458 */
if(!s->budget--) { s->failed_pc=0x0c0c5458u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0c545a;
P_0c0c545a: /* original 9066, guest PC 0x0c0c545a */
if(!s->budget--) { s->failed_pc=0x0c0c545au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c552au,2);
goto P_0c0c545c;
P_0c0c545c: /* original f130, guest PC 0x0c0c545c */
if(!s->budget--) { s->failed_pc=0x0c0c545cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'+');
goto P_0c0c545e;
P_0c0c545e: /* original ff17, guest PC 0x0c0c545e */
if(!s->budget--) { s->failed_pc=0x0c0c545eu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c5460;
P_0c0c5460: /* original 945c, guest PC 0x0c0c5460 */
if(!s->budget--) { s->failed_pc=0x0c0c5460u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c551cu,2);
goto P_0c0c5462;
P_0c0c5462: /* original 4d0b, guest PC 0x0c0c5462 */
if(!s->budget--) { s->failed_pc=0x0c0c5462u; return 0; }
target=r[13];
r[16]=0x0c0c5466u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5466u) { target=s->pc; goto dispatch; }
goto P_0c0c5466;
P_0c0c5464: /* original 34fc, guest PC 0x0c0c5464 */
if(!s->budget--) { s->failed_pc=0x0c0c5464u; return 0; }
r[4]+=r[15];
goto P_0c0c5466;
P_0c0c5466: /* original 905d, guest PC 0x0c0c5466 */
if(!s->budget--) { s->failed_pc=0x0c0c5466u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5524u,2);
goto P_0c0c5468;
P_0c0c5468: /* original f2a8, guest PC 0x0c0c5468 */
if(!s->budget--) { s->failed_pc=0x0c0c5468u; return 0; }
vf3_matrix_load(s,ram,2,r[10]);
goto P_0c0c546a;
P_0c0c546a: /* original f3f6, guest PC 0x0c0c546a */
if(!s->budget--) { s->failed_pc=0x0c0c546au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c546c;
P_0c0c546c: /* original f0dc, guest PC 0x0c0c546c */
if(!s->budget--) { s->failed_pc=0x0c0c546cu; return 0; }
vf3_matrix_move(s,0,13);
goto P_0c0c546e;
P_0c0c546e: /* original f32e, guest PC 0x0c0c546e */
if(!s->budget--) { s->failed_pc=0x0c0c546eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0c5470;
P_0c0c5470: /* original 9058, guest PC 0x0c0c5470 */
if(!s->budget--) { s->failed_pc=0x0c0c5470u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5524u,2);
goto P_0c0c5472;
P_0c0c5472: /* original f3f5, guest PC 0x0c0c5472 */
if(!s->budget--) { s->failed_pc=0x0c0c5472u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0c5474;
P_0c0c5474: /* original 8f02, guest PC 0x0c0c5474 */
if(!s->budget--) { s->failed_pc=0x0c0c5474u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(!cond) { goto P_0c0c547c; }
goto P_0c0c5478;
P_0c0c5476: /* original ff37, guest PC 0x0c0c5476 */
if(!s->budget--) { s->failed_pc=0x0c0c5476u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c5478;
P_0c0c5478: /* original a2df, guest PC 0x0c0c5478 */
if(!s->budget--) { s->failed_pc=0x0c0c5478u; return 0; }
goto P_0c0c5a3a;
P_0c0c547a: /* original 0009, guest PC 0x0c0c547a */
if(!s->budget--) { s->failed_pc=0x0c0c547au; return 0; }
goto P_0c0c547c;
P_0c0c547c: /* original e038, guest PC 0x0c0c547c */
if(!s->budget--) { s->failed_pc=0x0c0c547cu; return 0; }
r[0]=0x00000038u;
goto P_0c0c547e;
P_0c0c547e: /* original f3f6, guest PC 0x0c0c547e */
if(!s->budget--) { s->failed_pc=0x0c0c547eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5480;
P_0c0c5480: /* original 9051, guest PC 0x0c0c5480 */
if(!s->budget--) { s->failed_pc=0x0c0c5480u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5526u,2);
goto P_0c0c5482;
P_0c0c5482: /* original ff37, guest PC 0x0c0c5482 */
if(!s->budget--) { s->failed_pc=0x0c0c5482u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c5484;
P_0c0c5484: /* original c732, guest PC 0x0c0c5484 */
if(!s->budget--) { s->failed_pc=0x0c0c5484u; return 0; }
r[0]=0x0c0c5550u;
goto P_0c0c5486;
P_0c0c5486: /* original f308, guest PC 0x0c0c5486 */
if(!s->budget--) { s->failed_pc=0x0c0c5486u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c5488;
P_0c0c5488: /* original 904e, guest PC 0x0c0c5488 */
if(!s->budget--) { s->failed_pc=0x0c0c5488u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5528u,2);
goto P_0c0c548a;
P_0c0c548a: /* original fe32, guest PC 0x0c0c548a */
if(!s->budget--) { s->failed_pc=0x0c0c548au; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'*');
goto P_0c0c548c;
P_0c0c548c: /* original ffe7, guest PC 0x0c0c548c */
if(!s->budget--) { s->failed_pc=0x0c0c548cu; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c0c548e;
P_0c0c548e: /* original c72f, guest PC 0x0c0c548e */
if(!s->budget--) { s->failed_pc=0x0c0c548eu; return 0; }
r[0]=0x0c0c554cu;
goto P_0c0c5490;
P_0c0c5490: /* original f208, guest PC 0x0c0c5490 */
if(!s->budget--) { s->failed_pc=0x0c0c5490u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c5492;
P_0c0c5492: /* original 904a, guest PC 0x0c0c5492 */
if(!s->budget--) { s->failed_pc=0x0c0c5492u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c552au,2);
goto P_0c0c5494;
P_0c0c5494: /* original f1f6, guest PC 0x0c0c5494 */
if(!s->budget--) { s->failed_pc=0x0c0c5494u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0c5496;
P_0c0c5496: /* original 9048, guest PC 0x0c0c5496 */
if(!s->budget--) { s->failed_pc=0x0c0c5496u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c552au,2);
goto P_0c0c5498;
P_0c0c5498: /* original f120, guest PC 0x0c0c5498 */
if(!s->budget--) { s->failed_pc=0x0c0c5498u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c0c549a;
P_0c0c549a: /* original ff17, guest PC 0x0c0c549a */
if(!s->budget--) { s->failed_pc=0x0c0c549au; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c549c;
P_0c0c549c: /* original 943e, guest PC 0x0c0c549c */
if(!s->budget--) { s->failed_pc=0x0c0c549cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c551cu,2);
goto P_0c0c549e;
P_0c0c549e: /* original 4d0b, guest PC 0x0c0c549e */
if(!s->budget--) { s->failed_pc=0x0c0c549eu; return 0; }
target=r[13];
r[16]=0x0c0c54a2u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c54a2u) { target=s->pc; goto dispatch; }
goto P_0c0c54a2;
P_0c0c54a0: /* original 34fc, guest PC 0x0c0c54a0 */
if(!s->budget--) { s->failed_pc=0x0c0c54a0u; return 0; }
r[4]+=r[15];
goto P_0c0c54a2;
P_0c0c54a2: /* original 903f, guest PC 0x0c0c54a2 */
if(!s->budget--) { s->failed_pc=0x0c0c54a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5524u,2);
goto P_0c0c54a4;
P_0c0c54a4: /* original f0a8, guest PC 0x0c0c54a4 */
if(!s->budget--) { s->failed_pc=0x0c0c54a4u; return 0; }
vf3_matrix_load(s,ram,0,r[10]);
goto P_0c0c54a6;
P_0c0c54a6: /* original f3f6, guest PC 0x0c0c54a6 */
if(!s->budget--) { s->failed_pc=0x0c0c54a6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c54a8;
P_0c0c54a8: /* original e008, guest PC 0x0c0c54a8 */
if(!s->budget--) { s->failed_pc=0x0c0c54a8u; return 0; }
r[0]=0x00000008u;
goto P_0c0c54aa;
P_0c0c54aa: /* original f2e6, guest PC 0x0c0c54aa */
if(!s->budget--) { s->failed_pc=0x0c0c54aau; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0c54ac;
P_0c0c54ac: /* original 903a, guest PC 0x0c0c54ac */
if(!s->budget--) { s->failed_pc=0x0c0c54acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5524u,2);
goto P_0c0c54ae;
P_0c0c54ae: /* original f32e, guest PC 0x0c0c54ae */
if(!s->budget--) { s->failed_pc=0x0c0c54aeu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0c54b0;
P_0c0c54b0: /* original f3f5, guest PC 0x0c0c54b0 */
if(!s->budget--) { s->failed_pc=0x0c0c54b0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0c54b2;
P_0c0c54b2: /* original 8f02, guest PC 0x0c0c54b2 */
if(!s->budget--) { s->failed_pc=0x0c0c54b2u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(!cond) { goto P_0c0c54ba; }
goto P_0c0c54b6;
P_0c0c54b4: /* original ff37, guest PC 0x0c0c54b4 */
if(!s->budget--) { s->failed_pc=0x0c0c54b4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c54b6;
P_0c0c54b6: /* original a2c0, guest PC 0x0c0c54b6 */
if(!s->budget--) { s->failed_pc=0x0c0c54b6u; return 0; }
goto P_0c0c5a3a;
P_0c0c54b8: /* original 0009, guest PC 0x0c0c54b8 */
if(!s->budget--) { s->failed_pc=0x0c0c54b8u; return 0; }
goto P_0c0c54ba;
P_0c0c54ba: /* original 9033, guest PC 0x0c0c54ba */
if(!s->budget--) { s->failed_pc=0x0c0c54bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5524u,2);
goto P_0c0c54bc;
P_0c0c54bc: /* original fdf6, guest PC 0x0c0c54bc */
if(!s->budget--) { s->failed_pc=0x0c0c54bcu; return 0; }
vf3_matrix_load(s,ram,13,r[15]+r[0]);
goto P_0c0c54be;
P_0c0c54be: /* original 9035, guest PC 0x0c0c54be */
if(!s->budget--) { s->failed_pc=0x0c0c54beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c552cu,2);
goto P_0c0c54c0;
P_0c0c54c0: /* original fef6, guest PC 0x0c0c54c0 */
if(!s->budget--) { s->failed_pc=0x0c0c54c0u; return 0; }
vf3_matrix_load(s,ram,14,r[15]+r[0]);
goto P_0c0c54c2;
P_0c0c54c2: /* original 9032, guest PC 0x0c0c54c2 */
if(!s->budget--) { s->failed_pc=0x0c0c54c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c552au,2);
goto P_0c0c54c4;
P_0c0c54c4: /* original f3f6, guest PC 0x0c0c54c4 */
if(!s->budget--) { s->failed_pc=0x0c0c54c4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c54c6;
P_0c0c54c6: /* original e040, guest PC 0x0c0c54c6 */
if(!s->budget--) { s->failed_pc=0x0c0c54c6u; return 0; }
r[0]=0x00000040u;
goto P_0c0c54c8;
P_0c0c54c8: /* original ff37, guest PC 0x0c0c54c8 */
if(!s->budget--) { s->failed_pc=0x0c0c54c8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c54ca;
P_0c0c54ca: /* original e020, guest PC 0x0c0c54ca */
if(!s->budget--) { s->failed_pc=0x0c0c54cau; return 0; }
r[0]=0x00000020u;
goto P_0c0c54cc;
P_0c0c54cc: /* original 4b0b, guest PC 0x0c0c54cc */
if(!s->budget--) { s->failed_pc=0x0c0c54ccu; return 0; }
target=r[11];
r[16]=0x0c0c54d0u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c54d0u) { target=s->pc; goto dispatch; }
goto P_0c0c54d0;
P_0c0c54ce: /* original 04fd, guest PC 0x0c0c54ce */
if(!s->budget--) { s->failed_pc=0x0c0c54ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
goto P_0c0c54d0;
P_0c0c54d0: /* original 6e03, guest PC 0x0c0c54d0 */
if(!s->budget--) { s->failed_pc=0x0c0c54d0u; return 0; }
r[14]=r[0];
goto P_0c0c54d2;
P_0c0c54d2: /* original e040, guest PC 0x0c0c54d2 */
if(!s->budget--) { s->failed_pc=0x0c0c54d2u; return 0; }
r[0]=0x00000040u;
goto P_0c0c54d4;
P_0c0c54d4: /* original f8f6, guest PC 0x0c0c54d4 */
if(!s->budget--) { s->failed_pc=0x0c0c54d4u; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c0c54d6;
P_0c0c54d6: /* original e01c, guest PC 0x0c0c54d6 */
if(!s->budget--) { s->failed_pc=0x0c0c54d6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c54d8;
P_0c0c54d8: /* original f7e6, guest PC 0x0c0c54d8 */
if(!s->budget--) { s->failed_pc=0x0c0c54d8u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c54da;
P_0c0c54da: /* original e018, guest PC 0x0c0c54da */
if(!s->budget--) { s->failed_pc=0x0c0c54dau; return 0; }
r[0]=0x00000018u;
goto P_0c0c54dc;
P_0c0c54dc: /* original 941e, guest PC 0x0c0c54dc */
if(!s->budget--) { s->failed_pc=0x0c0c54dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c551cu,2);
goto P_0c0c54de;
P_0c0c54de: /* original d31d, guest PC 0x0c0c54de */
if(!s->budget--) { s->failed_pc=0x0c0c54deu; return 0; }
r[3]=read(ram,0x0c0c5554u,4);
goto P_0c0c54e0;
P_0c0c54e0: /* original f6e6, guest PC 0x0c0c54e0 */
if(!s->budget--) { s->failed_pc=0x0c0c54e0u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c54e2;
P_0c0c54e2: /* original f5ec, guest PC 0x0c0c54e2 */
if(!s->budget--) { s->failed_pc=0x0c0c54e2u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0c54e4;
P_0c0c54e4: /* original f4dc, guest PC 0x0c0c54e4 */
if(!s->budget--) { s->failed_pc=0x0c0c54e4u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0c54e6;
P_0c0c54e6: /* original 430b, guest PC 0x0c0c54e6 */
if(!s->budget--) { s->failed_pc=0x0c0c54e6u; return 0; }
target=r[3];
r[16]=0x0c0c54eau;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c54eau) { target=s->pc; goto dispatch; }
goto P_0c0c54ea;
P_0c0c54e8: /* original 34fc, guest PC 0x0c0c54e8 */
if(!s->budget--) { s->failed_pc=0x0c0c54e8u; return 0; }
r[4]+=r[15];
goto P_0c0c54ea;
P_0c0c54ea: /* original e014, guest PC 0x0c0c54ea */
if(!s->budget--) { s->failed_pc=0x0c0c54eau; return 0; }
r[0]=0x00000014u;
goto P_0c0c54ec;
P_0c0c54ec: /* original 9416, guest PC 0x0c0c54ec */
if(!s->budget--) { s->failed_pc=0x0c0c54ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c551cu,2);
goto P_0c0c54ee;
P_0c0c54ee: /* original f9e6, guest PC 0x0c0c54ee */
if(!s->budget--) { s->failed_pc=0x0c0c54eeu; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c0c54f0;
P_0c0c54f0: /* original e010, guest PC 0x0c0c54f0 */
if(!s->budget--) { s->failed_pc=0x0c0c54f0u; return 0; }
r[0]=0x00000010u;
goto P_0c0c54f2;
P_0c0c54f2: /* original f8e6, guest PC 0x0c0c54f2 */
if(!s->budget--) { s->failed_pc=0x0c0c54f2u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0c54f4;
P_0c0c54f4: /* original e00c, guest PC 0x0c0c54f4 */
if(!s->budget--) { s->failed_pc=0x0c0c54f4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c54f6;
P_0c0c54f6: /* original f7e6, guest PC 0x0c0c54f6 */
if(!s->budget--) { s->failed_pc=0x0c0c54f6u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c54f8;
P_0c0c54f8: /* original e008, guest PC 0x0c0c54f8 */
if(!s->budget--) { s->failed_pc=0x0c0c54f8u; return 0; }
r[0]=0x00000008u;
goto P_0c0c54fa;
P_0c0c54fa: /* original f6e6, guest PC 0x0c0c54fa */
if(!s->budget--) { s->failed_pc=0x0c0c54fau; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c54fc;
P_0c0c54fc: /* original e004, guest PC 0x0c0c54fc */
if(!s->budget--) { s->failed_pc=0x0c0c54fcu; return 0; }
r[0]=0x00000004u;
goto P_0c0c54fe;
P_0c0c54fe: /* original f4e8, guest PC 0x0c0c54fe */
if(!s->budget--) { s->failed_pc=0x0c0c54feu; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
goto P_0c0c5500;
P_0c0c5500: /* original f5e6, guest PC 0x0c0c5500 */
if(!s->budget--) { s->failed_pc=0x0c0c5500u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0c5502;
P_0c0c5502: /* original 480b, guest PC 0x0c0c5502 */
if(!s->budget--) { s->failed_pc=0x0c0c5502u; return 0; }
target=r[8];
r[16]=0x0c0c5506u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5506u) { target=s->pc; goto dispatch; }
goto P_0c0c5506;
P_0c0c5504: /* original 34fc, guest PC 0x0c0c5504 */
if(!s->budget--) { s->failed_pc=0x0c0c5504u; return 0; }
r[4]+=r[15];
goto P_0c0c5506;
P_0c0c5506: /* original 53e8, guest PC 0x0c0c5506 */
if(!s->budget--) { s->failed_pc=0x0c0c5506u; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c0c5508;
P_0c0c5508: /* original d009, guest PC 0x0c0c5508 */
if(!s->budget--) { s->failed_pc=0x0c0c5508u; return 0; }
r[0]=read(ram,0x0c0c5530u,4);
goto P_0c0c550a;
P_0c0c550a: /* original 4300, guest PC 0x0c0c550a */
if(!s->budget--) { s->failed_pc=0x0c0c550au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c550c;
P_0c0c550c: /* original 023d, guest PC 0x0c0c550c */
if(!s->budget--) { s->failed_pc=0x0c0c550cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c550e;
P_0c0c550e: /* original 9005, guest PC 0x0c0c550e */
if(!s->budget--) { s->failed_pc=0x0c0c550eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c551cu,2);
goto P_0c0c5510;
P_0c0c5510: /* original 622d, guest PC 0x0c0c5510 */
if(!s->budget--) { s->failed_pc=0x0c0c5510u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c5512;
P_0c0c5512: /* original 0f26, guest PC 0x0c0c5512 */
if(!s->budget--) { s->failed_pc=0x0c0c5512u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0c5514;
P_0c0c5514: /* original 9006, guest PC 0x0c0c5514 */
if(!s->budget--) { s->failed_pc=0x0c0c5514u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5524u,2);
goto P_0c0c5516;
P_0c0c5516: /* original ffd7, guest PC 0x0c0c5516 */
if(!s->budget--) { s->failed_pc=0x0c0c5516u; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0c5518;
P_0c0c5518: /* original a01e, guest PC 0x0c0c5518 */
if(!s->budget--) { s->failed_pc=0x0c0c5518u; return 0; }
goto P_0c0c5558;
P_0c0c551a: /* original 0009, guest PC 0x0c0c551a */
if(!s->budget--) { s->failed_pc=0x0c0c551au; return 0; }
return vf3_matrix_family(0x0c0c551cu,s,ram);
P_0c0c5558: /* original 9047, guest PC 0x0c0c5558 */
if(!s->budget--) { s->failed_pc=0x0c0c5558u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55eau,2);
goto P_0c0c555a;
P_0c0c555a: /* original ffe7, guest PC 0x0c0c555a */
if(!s->budget--) { s->failed_pc=0x0c0c555au; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c0c555c;
P_0c0c555c: /* original 9046, guest PC 0x0c0c555c */
if(!s->budget--) { s->failed_pc=0x0c0c555cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55ecu,2);
goto P_0c0c555e;
P_0c0c555e: /* original f3f6, guest PC 0x0c0c555e */
if(!s->budget--) { s->failed_pc=0x0c0c555eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5560;
P_0c0c5560: /* original f3f5, guest PC 0x0c0c5560 */
if(!s->budget--) { s->failed_pc=0x0c0c5560u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0c5562;
P_0c0c5562: /* original 8b01, guest PC 0x0c0c5562 */
if(!s->budget--) { s->failed_pc=0x0c0c5562u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5568; }
goto P_0c0c5564;
P_0c0c5564: /* original a269, guest PC 0x0c0c5564 */
if(!s->budget--) { s->failed_pc=0x0c0c5564u; return 0; }
goto P_0c0c5a3a;
P_0c0c5566: /* original 0009, guest PC 0x0c0c5566 */
if(!s->budget--) { s->failed_pc=0x0c0c5566u; return 0; }
goto P_0c0c5568;
P_0c0c5568: /* original c723, guest PC 0x0c0c5568 */
if(!s->budget--) { s->failed_pc=0x0c0c5568u; return 0; }
r[0]=0x0c0c55f8u;
goto P_0c0c556a;
P_0c0c556a: /* original f308, guest PC 0x0c0c556a */
if(!s->budget--) { s->failed_pc=0x0c0c556au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c556c;
P_0c0c556c: /* original 903f, guest PC 0x0c0c556c */
if(!s->budget--) { s->failed_pc=0x0c0c556cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55eeu,2);
goto P_0c0c556e;
P_0c0c556e: /* original f2f6, guest PC 0x0c0c556e */
if(!s->budget--) { s->failed_pc=0x0c0c556eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c5570;
P_0c0c5570: /* original 903d, guest PC 0x0c0c5570 */
if(!s->budget--) { s->failed_pc=0x0c0c5570u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55eeu,2);
goto P_0c0c5572;
P_0c0c5572: /* original f230, guest PC 0x0c0c5572 */
if(!s->budget--) { s->failed_pc=0x0c0c5572u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5574;
P_0c0c5574: /* original ff27, guest PC 0x0c0c5574 */
if(!s->budget--) { s->failed_pc=0x0c0c5574u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c5576;
P_0c0c5576: /* original 943b, guest PC 0x0c0c5576 */
if(!s->budget--) { s->failed_pc=0x0c0c5576u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55f0u,2);
goto P_0c0c5578;
P_0c0c5578: /* original 4d0b, guest PC 0x0c0c5578 */
if(!s->budget--) { s->failed_pc=0x0c0c5578u; return 0; }
target=r[13];
r[16]=0x0c0c557cu;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c557cu) { target=s->pc; goto dispatch; }
goto P_0c0c557c;
P_0c0c557a: /* original 34fc, guest PC 0x0c0c557a */
if(!s->budget--) { s->failed_pc=0x0c0c557au; return 0; }
r[4]+=r[15];
goto P_0c0c557c;
P_0c0c557c: /* original 9036, guest PC 0x0c0c557c */
if(!s->budget--) { s->failed_pc=0x0c0c557cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55ecu,2);
goto P_0c0c557e;
P_0c0c557e: /* original f0a8, guest PC 0x0c0c557e */
if(!s->budget--) { s->failed_pc=0x0c0c557eu; return 0; }
vf3_matrix_load(s,ram,0,r[10]);
goto P_0c0c5580;
P_0c0c5580: /* original f3f6, guest PC 0x0c0c5580 */
if(!s->budget--) { s->failed_pc=0x0c0c5580u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5582;
P_0c0c5582: /* original e008, guest PC 0x0c0c5582 */
if(!s->budget--) { s->failed_pc=0x0c0c5582u; return 0; }
r[0]=0x00000008u;
goto P_0c0c5584;
P_0c0c5584: /* original f2e6, guest PC 0x0c0c5584 */
if(!s->budget--) { s->failed_pc=0x0c0c5584u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0c5586;
P_0c0c5586: /* original 9034, guest PC 0x0c0c5586 */
if(!s->budget--) { s->failed_pc=0x0c0c5586u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55f2u,2);
goto P_0c0c5588;
P_0c0c5588: /* original f32e, guest PC 0x0c0c5588 */
if(!s->budget--) { s->failed_pc=0x0c0c5588u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0c558a;
P_0c0c558a: /* original f3f5, guest PC 0x0c0c558a */
if(!s->budget--) { s->failed_pc=0x0c0c558au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0c558c;
P_0c0c558c: /* original 8f02, guest PC 0x0c0c558c */
if(!s->budget--) { s->failed_pc=0x0c0c558cu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(!cond) { goto P_0c0c5594; }
goto P_0c0c5590;
P_0c0c558e: /* original ff37, guest PC 0x0c0c558e */
if(!s->budget--) { s->failed_pc=0x0c0c558eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c5590;
P_0c0c5590: /* original a253, guest PC 0x0c0c5590 */
if(!s->budget--) { s->failed_pc=0x0c0c5590u; return 0; }
goto P_0c0c5a3a;
P_0c0c5592: /* original 0009, guest PC 0x0c0c5592 */
if(!s->budget--) { s->failed_pc=0x0c0c5592u; return 0; }
goto P_0c0c5594;
P_0c0c5594: /* original 942e, guest PC 0x0c0c5594 */
if(!s->budget--) { s->failed_pc=0x0c0c5594u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55f4u,2);
goto P_0c0c5596;
P_0c0c5596: /* original 4d0b, guest PC 0x0c0c5596 */
if(!s->budget--) { s->failed_pc=0x0c0c5596u; return 0; }
target=r[13];
r[16]=0x0c0c559au;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c559au) { target=s->pc; goto dispatch; }
goto P_0c0c559a;
P_0c0c5598: /* original 34fc, guest PC 0x0c0c5598 */
if(!s->budget--) { s->failed_pc=0x0c0c5598u; return 0; }
r[4]+=r[15];
goto P_0c0c559a;
P_0c0c559a: /* original a24e, guest PC 0x0c0c559a */
if(!s->budget--) { s->failed_pc=0x0c0c559au; return 0; }
goto P_0c0c5a3a;
P_0c0c559c: /* original 0009, guest PC 0x0c0c559c */
if(!s->budget--) { s->failed_pc=0x0c0c559cu; return 0; }
goto P_0c0c559e;
P_0c0c559e: /* original 9427, guest PC 0x0c0c559e */
if(!s->budget--) { s->failed_pc=0x0c0c559eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55f0u,2);
goto P_0c0c55a0;
P_0c0c55a0: /* original 4d0b, guest PC 0x0c0c55a0 */
if(!s->budget--) { s->failed_pc=0x0c0c55a0u; return 0; }
target=r[13];
r[16]=0x0c0c55a4u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c55a4u) { target=s->pc; goto dispatch; }
goto P_0c0c55a4;
P_0c0c55a2: /* original 34fc, guest PC 0x0c0c55a2 */
if(!s->budget--) { s->failed_pc=0x0c0c55a2u; return 0; }
r[4]+=r[15];
goto P_0c0c55a4;
P_0c0c55a4: /* original e008, guest PC 0x0c0c55a4 */
if(!s->budget--) { s->failed_pc=0x0c0c55a4u; return 0; }
r[0]=0x00000008u;
goto P_0c0c55a6;
P_0c0c55a6: /* original 53f6, guest PC 0x0c0c55a6 */
if(!s->budget--) { s->failed_pc=0x0c0c55a6u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0c55a8;
P_0c0c55a8: /* original f3e6, guest PC 0x0c0c55a8 */
if(!s->budget--) { s->failed_pc=0x0c0c55a8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c55aa;
P_0c0c55aa: /* original d014, guest PC 0x0c0c55aa */
if(!s->budget--) { s->failed_pc=0x0c0c55aau; return 0; }
r[0]=read(ram,0x0c0c55fcu,4);
goto P_0c0c55ac;
P_0c0c55ac: /* original fe30, guest PC 0x0c0c55ac */
if(!s->budget--) { s->failed_pc=0x0c0c55acu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'+');
goto P_0c0c55ae;
P_0c0c55ae: /* original 941f, guest PC 0x0c0c55ae */
if(!s->budget--) { s->failed_pc=0x0c0c55aeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55f0u,2);
goto P_0c0c55b0;
P_0c0c55b0: /* original f836, guest PC 0x0c0c55b0 */
if(!s->budget--) { s->failed_pc=0x0c0c55b0u; return 0; }
vf3_matrix_load(s,ram,8,r[3]+r[0]);
goto P_0c0c55b2;
P_0c0c55b2: /* original e01c, guest PC 0x0c0c55b2 */
if(!s->budget--) { s->failed_pc=0x0c0c55b2u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c55b4;
P_0c0c55b4: /* original f7e6, guest PC 0x0c0c55b4 */
if(!s->budget--) { s->failed_pc=0x0c0c55b4u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c55b6;
P_0c0c55b6: /* original e018, guest PC 0x0c0c55b6 */
if(!s->budget--) { s->failed_pc=0x0c0c55b6u; return 0; }
r[0]=0x00000018u;
goto P_0c0c55b8;
P_0c0c55b8: /* original d311, guest PC 0x0c0c55b8 */
if(!s->budget--) { s->failed_pc=0x0c0c55b8u; return 0; }
r[3]=read(ram,0x0c0c5600u,4);
goto P_0c0c55ba;
P_0c0c55ba: /* original f6e6, guest PC 0x0c0c55ba */
if(!s->budget--) { s->failed_pc=0x0c0c55bau; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c55bc;
P_0c0c55bc: /* original f5dc, guest PC 0x0c0c55bc */
if(!s->budget--) { s->failed_pc=0x0c0c55bcu; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c0c55be;
P_0c0c55be: /* original f4ec, guest PC 0x0c0c55be */
if(!s->budget--) { s->failed_pc=0x0c0c55beu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0c55c0;
P_0c0c55c0: /* original 430b, guest PC 0x0c0c55c0 */
if(!s->budget--) { s->failed_pc=0x0c0c55c0u; return 0; }
target=r[3];
r[16]=0x0c0c55c4u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c55c4u) { target=s->pc; goto dispatch; }
goto P_0c0c55c4;
P_0c0c55c2: /* original 34fc, guest PC 0x0c0c55c2 */
if(!s->budget--) { s->failed_pc=0x0c0c55c2u; return 0; }
r[4]+=r[15];
goto P_0c0c55c4;
P_0c0c55c4: /* original e014, guest PC 0x0c0c55c4 */
if(!s->budget--) { s->failed_pc=0x0c0c55c4u; return 0; }
r[0]=0x00000014u;
goto P_0c0c55c6;
P_0c0c55c6: /* original 9413, guest PC 0x0c0c55c6 */
if(!s->budget--) { s->failed_pc=0x0c0c55c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55f0u,2);
goto P_0c0c55c8;
P_0c0c55c8: /* original f9e6, guest PC 0x0c0c55c8 */
if(!s->budget--) { s->failed_pc=0x0c0c55c8u; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c0c55ca;
P_0c0c55ca: /* original e010, guest PC 0x0c0c55ca */
if(!s->budget--) { s->failed_pc=0x0c0c55cau; return 0; }
r[0]=0x00000010u;
goto P_0c0c55cc;
P_0c0c55cc: /* original f8e6, guest PC 0x0c0c55cc */
if(!s->budget--) { s->failed_pc=0x0c0c55ccu; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0c55ce;
P_0c0c55ce: /* original e00c, guest PC 0x0c0c55ce */
if(!s->budget--) { s->failed_pc=0x0c0c55ceu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c55d0;
P_0c0c55d0: /* original f7e6, guest PC 0x0c0c55d0 */
if(!s->budget--) { s->failed_pc=0x0c0c55d0u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c55d2;
P_0c0c55d2: /* original e008, guest PC 0x0c0c55d2 */
if(!s->budget--) { s->failed_pc=0x0c0c55d2u; return 0; }
r[0]=0x00000008u;
goto P_0c0c55d4;
P_0c0c55d4: /* original f6e6, guest PC 0x0c0c55d4 */
if(!s->budget--) { s->failed_pc=0x0c0c55d4u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c55d6;
P_0c0c55d6: /* original e004, guest PC 0x0c0c55d6 */
if(!s->budget--) { s->failed_pc=0x0c0c55d6u; return 0; }
r[0]=0x00000004u;
goto P_0c0c55d8;
P_0c0c55d8: /* original f4e8, guest PC 0x0c0c55d8 */
if(!s->budget--) { s->failed_pc=0x0c0c55d8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
goto P_0c0c55da;
P_0c0c55da: /* original f5e6, guest PC 0x0c0c55da */
if(!s->budget--) { s->failed_pc=0x0c0c55dau; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0c55dc;
P_0c0c55dc: /* original 480b, guest PC 0x0c0c55dc */
if(!s->budget--) { s->failed_pc=0x0c0c55dcu; return 0; }
target=r[8];
r[16]=0x0c0c55e0u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c55e0u) { target=s->pc; goto dispatch; }
goto P_0c0c55e0;
P_0c0c55de: /* original 34fc, guest PC 0x0c0c55de */
if(!s->budget--) { s->failed_pc=0x0c0c55deu; return 0; }
r[4]+=r[15];
goto P_0c0c55e0;
P_0c0c55e0: /* original 9406, guest PC 0x0c0c55e0 */
if(!s->budget--) { s->failed_pc=0x0c0c55e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c55f0u,2);
goto P_0c0c55e2;
P_0c0c55e2: /* original 4d0b, guest PC 0x0c0c55e2 */
if(!s->budget--) { s->failed_pc=0x0c0c55e2u; return 0; }
target=r[13];
r[16]=0x0c0c55e6u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c55e6u) { target=s->pc; goto dispatch; }
goto P_0c0c55e6;
P_0c0c55e4: /* original 34fc, guest PC 0x0c0c55e4 */
if(!s->budget--) { s->failed_pc=0x0c0c55e4u; return 0; }
r[4]+=r[15];
goto P_0c0c55e6;
P_0c0c55e6: /* original a221, guest PC 0x0c0c55e6 */
if(!s->budget--) { s->failed_pc=0x0c0c55e6u; return 0; }
goto P_0c0c5a2c;
P_0c0c55e8: /* original 0009, guest PC 0x0c0c55e8 */
if(!s->budget--) { s->failed_pc=0x0c0c55e8u; return 0; }
return vf3_matrix_family(0x0c0c55eau,s,ram);
P_0c0c5604: /* original c75d, guest PC 0x0c0c5604 */
if(!s->budget--) { s->failed_pc=0x0c0c5604u; return 0; }
r[0]=0x0c0c577cu;
goto P_0c0c5606;
P_0c0c5606: /* original d360, guest PC 0x0c0c5606 */
if(!s->budget--) { s->failed_pc=0x0c0c5606u; return 0; }
r[3]=read(ram,0x0c0c5788u,4);
goto P_0c0c5608;
P_0c0c5608: /* original f708, guest PC 0x0c0c5608 */
if(!s->budget--) { s->failed_pc=0x0c0c5608u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0c560a;
P_0c0c560a: /* original c75d, guest PC 0x0c0c560a */
if(!s->budget--) { s->failed_pc=0x0c0c560au; return 0; }
r[0]=0x0c0c5780u;
goto P_0c0c560c;
P_0c0c560c: /* original f408, guest PC 0x0c0c560c */
if(!s->budget--) { s->failed_pc=0x0c0c560cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c560e;
P_0c0c560e: /* original 90aa, guest PC 0x0c0c560e */
if(!s->budget--) { s->failed_pc=0x0c0c560eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5766u,2);
goto P_0c0c5610;
P_0c0c5610: /* original f538, guest PC 0x0c0c5610 */
if(!s->budget--) { s->failed_pc=0x0c0c5610u; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
goto P_0c0c5612;
P_0c0c5612: /* original fef6, guest PC 0x0c0c5612 */
if(!s->budget--) { s->failed_pc=0x0c0c5612u; return 0; }
vf3_matrix_load(s,ram,14,r[15]+r[0]);
goto P_0c0c5614;
P_0c0c5614: /* original 50e8, guest PC 0x0c0c5614 */
if(!s->budget--) { s->failed_pc=0x0c0c5614u; return 0; }
r[0]=read(ram,r[14]+32,4);
goto P_0c0c5616;
P_0c0c5616: /* original d95b, guest PC 0x0c0c5616 */
if(!s->budget--) { s->failed_pc=0x0c0c5616u; return 0; }
r[9]=read(ram,0x0c0c5784u,4);
goto P_0c0c5618;
P_0c0c5618: /* original f6a8, guest PC 0x0c0c5618 */
if(!s->budget--) { s->failed_pc=0x0c0c5618u; return 0; }
vf3_matrix_load(s,ram,6,r[10]);
goto P_0c0c561a;
P_0c0c561a: /* original 882c, guest PC 0x0c0c561a */
if(!s->budget--) { s->failed_pc=0x0c0c561au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002cu)!=0);
goto P_0c0c561c;
P_0c0c561c: /* original 8d05, guest PC 0x0c0c561c */
if(!s->budget--) { s->failed_pc=0x0c0c561cu; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c0c562a; }
goto P_0c0c5620;
P_0c0c561e: /* original 6503, guest PC 0x0c0c561e */
if(!s->budget--) { s->failed_pc=0x0c0c561eu; return 0; }
r[5]=r[0];
goto P_0c0c5620;
P_0c0c5620: /* original 6053, guest PC 0x0c0c5620 */
if(!s->budget--) { s->failed_pc=0x0c0c5620u; return 0; }
r[0]=r[5];
goto P_0c0c5622;
P_0c0c5622: /* original 8834, guest PC 0x0c0c5622 */
if(!s->budget--) { s->failed_pc=0x0c0c5622u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000034u)!=0);
goto P_0c0c5624;
P_0c0c5624: /* original 8901, guest PC 0x0c0c5624 */
if(!s->budget--) { s->failed_pc=0x0c0c5624u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c562a; }
goto P_0c0c5626;
P_0c0c5626: /* original a187, guest PC 0x0c0c5626 */
if(!s->budget--) { s->failed_pc=0x0c0c5626u; return 0; }
goto P_0c0c5938;
P_0c0c5628: /* original 0009, guest PC 0x0c0c5628 */
if(!s->budget--) { s->failed_pc=0x0c0c5628u; return 0; }
goto P_0c0c562a;
P_0c0c562a: /* original e008, guest PC 0x0c0c562a */
if(!s->budget--) { s->failed_pc=0x0c0c562au; return 0; }
r[0]=0x00000008u;
goto P_0c0c562c;
P_0c0c562c: /* original f3e6, guest PC 0x0c0c562c */
if(!s->budget--) { s->failed_pc=0x0c0c562cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c562e;
P_0c0c562e: /* original e010, guest PC 0x0c0c562e */
if(!s->budget--) { s->failed_pc=0x0c0c562eu; return 0; }
r[0]=0x00000010u;
goto P_0c0c5630;
P_0c0c5630: /* original f362, guest PC 0x0c0c5630 */
if(!s->budget--) { s->failed_pc=0x0c0c5630u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c0c5632;
P_0c0c5632: /* original ff37, guest PC 0x0c0c5632 */
if(!s->budget--) { s->failed_pc=0x0c0c5632u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c5634;
P_0c0c5634: /* original e014, guest PC 0x0c0c5634 */
if(!s->budget--) { s->failed_pc=0x0c0c5634u; return 0; }
r[0]=0x00000014u;
goto P_0c0c5636;
P_0c0c5636: /* original f8e6, guest PC 0x0c0c5636 */
if(!s->budget--) { s->failed_pc=0x0c0c5636u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0c5638;
P_0c0c5638: /* original e00c, guest PC 0x0c0c5638 */
if(!s->budget--) { s->failed_pc=0x0c0c5638u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c563a;
P_0c0c563a: /* original f6e6, guest PC 0x0c0c563a */
if(!s->budget--) { s->failed_pc=0x0c0c563au; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c563c;
P_0c0c563c: /* original f3ec, guest PC 0x0c0c563c */
if(!s->budget--) { s->failed_pc=0x0c0c563cu; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c0c563e;
P_0c0c563e: /* original f06c, guest PC 0x0c0c563e */
if(!s->budget--) { s->failed_pc=0x0c0c563eu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0c5640;
P_0c0c5640: /* original f35e, guest PC 0x0c0c5640 */
if(!s->budget--) { s->failed_pc=0x0c0c5640u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c0c5642;
P_0c0c5642: /* original 9091, guest PC 0x0c0c5642 */
if(!s->budget--) { s->failed_pc=0x0c0c5642u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5768u,2);
goto P_0c0c5644;
P_0c0c5644: /* original 03fe, guest PC 0x0c0c5644 */
if(!s->budget--) { s->failed_pc=0x0c0c5644u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0c5646;
P_0c0c5646: /* original f53c, guest PC 0x0c0c5646 */
if(!s->budget--) { s->failed_pc=0x0c0c5646u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0c5648;
P_0c0c5648: /* original 908e, guest PC 0x0c0c5648 */
if(!s->budget--) { s->failed_pc=0x0c0c5648u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5768u,2);
goto P_0c0c564a;
P_0c0c564a: /* original 2349, guest PC 0x0c0c564a */
if(!s->budget--) { s->failed_pc=0x0c0c564au; return 0; }
r[3]&=r[4];
goto P_0c0c564c;
P_0c0c564c: /* original 0f36, guest PC 0x0c0c564c */
if(!s->budget--) { s->failed_pc=0x0c0c564cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0c564e;
P_0c0c564e: /* original e004, guest PC 0x0c0c564e */
if(!s->budget--) { s->failed_pc=0x0c0c564eu; return 0; }
r[0]=0x00000004u;
goto P_0c0c5650;
P_0c0c5650: /* original f35c, guest PC 0x0c0c5650 */
if(!s->budget--) { s->failed_pc=0x0c0c5650u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0c5652;
P_0c0c5652: /* original f3e1, guest PC 0x0c0c5652 */
if(!s->budget--) { s->failed_pc=0x0c0c5652u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'-');
goto P_0c0c5654;
P_0c0c5654: /* original f20c, guest PC 0x0c0c5654 */
if(!s->budget--) { s->failed_pc=0x0c0c5654u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0c5656;
P_0c0c5656: /* original f370, guest PC 0x0c0c5656 */
if(!s->budget--) { s->failed_pc=0x0c0c5656u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'+');
goto P_0c0c5658;
P_0c0c5658: /* original f233, guest PC 0x0c0c5658 */
if(!s->budget--) { s->failed_pc=0x0c0c5658u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'/');
goto P_0c0c565a;
P_0c0c565a: /* original f282, guest PC 0x0c0c565a */
if(!s->budget--) { s->failed_pc=0x0c0c565au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'*');
goto P_0c0c565c;
P_0c0c565c: /* original ff27, guest PC 0x0c0c565c */
if(!s->budget--) { s->failed_pc=0x0c0c565cu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c565e;
P_0c0c565e: /* original e01c, guest PC 0x0c0c565e */
if(!s->budget--) { s->failed_pc=0x0c0c565eu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c5660;
P_0c0c5660: /* original f3e6, guest PC 0x0c0c5660 */
if(!s->budget--) { s->failed_pc=0x0c0c5660u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c5662;
P_0c0c5662: /* original 9082, guest PC 0x0c0c5662 */
if(!s->budget--) { s->failed_pc=0x0c0c5662u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c576au,2);
goto P_0c0c5664;
P_0c0c5664: /* original f363, guest PC 0x0c0c5664 */
if(!s->budget--) { s->failed_pc=0x0c0c5664u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'/');
goto P_0c0c5666;
P_0c0c5666: /* original ff37, guest PC 0x0c0c5666 */
if(!s->budget--) { s->failed_pc=0x0c0c5666u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c5668;
P_0c0c5668: /* original 9080, guest PC 0x0c0c5668 */
if(!s->budget--) { s->failed_pc=0x0c0c5668u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c576cu,2);
goto P_0c0c566a;
P_0c0c566a: /* original fdf6, guest PC 0x0c0c566a */
if(!s->budget--) { s->failed_pc=0x0c0c566au; return 0; }
vf3_matrix_load(s,ram,13,r[15]+r[0]);
goto P_0c0c566c;
P_0c0c566c: /* original e014, guest PC 0x0c0c566c */
if(!s->budget--) { s->failed_pc=0x0c0c566cu; return 0; }
r[0]=0x00000014u;
goto P_0c0c566e;
P_0c0c566e: /* original f6e6, guest PC 0x0c0c566e */
if(!s->budget--) { s->failed_pc=0x0c0c566eu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c5670;
P_0c0c5670: /* original c746, guest PC 0x0c0c5670 */
if(!s->budget--) { s->failed_pc=0x0c0c5670u; return 0; }
r[0]=0x0c0c578cu;
goto P_0c0c5672;
P_0c0c5672: /* original f308, guest PC 0x0c0c5672 */
if(!s->budget--) { s->failed_pc=0x0c0c5672u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c5674;
P_0c0c5674: /* original e00c, guest PC 0x0c0c5674 */
if(!s->budget--) { s->failed_pc=0x0c0c5674u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c5676;
P_0c0c5676: /* original f26c, guest PC 0x0c0c5676 */
if(!s->budget--) { s->failed_pc=0x0c0c5676u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c0c5678;
P_0c0c5678: /* original fe45, guest PC 0x0c0c5678 */
if(!s->budget--) { s->failed_pc=0x0c0c5678u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c0c567a;
P_0c0c567a: /* original f232, guest PC 0x0c0c567a */
if(!s->budget--) { s->failed_pc=0x0c0c567au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0c567c;
P_0c0c567c: /* original ff27, guest PC 0x0c0c567c */
if(!s->budget--) { s->failed_pc=0x0c0c567cu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c567e;
P_0c0c567e: /* original c744, guest PC 0x0c0c567e */
if(!s->budget--) { s->failed_pc=0x0c0c567eu; return 0; }
r[0]=0x0c0c5790u;
goto P_0c0c5680;
P_0c0c5680: /* original f108, guest PC 0x0c0c5680 */
if(!s->budget--) { s->failed_pc=0x0c0c5680u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c0c5682;
P_0c0c5682: /* original e008, guest PC 0x0c0c5682 */
if(!s->budget--) { s->failed_pc=0x0c0c5682u; return 0; }
r[0]=0x00000008u;
goto P_0c0c5684;
P_0c0c5684: /* original f612, guest PC 0x0c0c5684 */
if(!s->budget--) { s->failed_pc=0x0c0c5684u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[1],r[18],'*');
goto P_0c0c5686;
P_0c0c5686: /* original 8f02, guest PC 0x0c0c5686 */
if(!s->budget--) { s->failed_pc=0x0c0c5686u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,6,r[15]+r[0]);
if(!cond) { goto P_0c0c568e; }
goto P_0c0c568a;
P_0c0c5688: /* original ff67, guest PC 0x0c0c5688 */
if(!s->budget--) { s->failed_pc=0x0c0c5688u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c0c568a;
P_0c0c568a: /* original a1cf, guest PC 0x0c0c568a */
if(!s->budget--) { s->failed_pc=0x0c0c568au; return 0; }
goto P_0c0c5a2c;
P_0c0c568c: /* original 0009, guest PC 0x0c0c568c */
if(!s->budget--) { s->failed_pc=0x0c0c568cu; return 0; }
goto P_0c0c568e;
P_0c0c568e: /* original f39d, guest PC 0x0c0c568e */
if(!s->budget--) { s->failed_pc=0x0c0c568eu; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c5690;
P_0c0c5690: /* original f355, guest PC 0x0c0c5690 */
if(!s->budget--) { s->failed_pc=0x0c0c5690u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c0c5692;
P_0c0c5692: /* original 8b01, guest PC 0x0c0c5692 */
if(!s->budget--) { s->failed_pc=0x0c0c5692u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5698; }
goto P_0c0c5694;
P_0c0c5694: /* original a1ca, guest PC 0x0c0c5694 */
if(!s->budget--) { s->failed_pc=0x0c0c5694u; return 0; }
goto P_0c0c5a2c;
P_0c0c5696: /* original 0009, guest PC 0x0c0c5696 */
if(!s->budget--) { s->failed_pc=0x0c0c5696u; return 0; }
goto P_0c0c5698;
P_0c0c5698: /* original f35c, guest PC 0x0c0c5698 */
if(!s->budget--) { s->failed_pc=0x0c0c5698u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0c569a;
P_0c0c569a: /* original f345, guest PC 0x0c0c569a */
if(!s->budget--) { s->failed_pc=0x0c0c569au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0c569c;
P_0c0c569c: /* original e01c, guest PC 0x0c0c569c */
if(!s->budget--) { s->failed_pc=0x0c0c569cu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c569e;
P_0c0c569e: /* original 8f02, guest PC 0x0c0c569e */
if(!s->budget--) { s->failed_pc=0x0c0c569eu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,5,r[15]+r[0]);
if(!cond) { goto P_0c0c56a6; }
goto P_0c0c56a2;
P_0c0c56a0: /* original ff57, guest PC 0x0c0c56a0 */
if(!s->budget--) { s->failed_pc=0x0c0c56a0u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0c56a2;
P_0c0c56a2: /* original e01c, guest PC 0x0c0c56a2 */
if(!s->budget--) { s->failed_pc=0x0c0c56a2u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c56a4;
P_0c0c56a4: /* original ff47, guest PC 0x0c0c56a4 */
if(!s->budget--) { s->failed_pc=0x0c0c56a4u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0c56a6;
P_0c0c56a6: /* original c73b, guest PC 0x0c0c56a6 */
if(!s->budget--) { s->failed_pc=0x0c0c56a6u; return 0; }
r[0]=0x0c0c5794u;
goto P_0c0c56a8;
P_0c0c56a8: /* original f308, guest PC 0x0c0c56a8 */
if(!s->budget--) { s->failed_pc=0x0c0c56a8u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c56aa;
P_0c0c56aa: /* original e004, guest PC 0x0c0c56aa */
if(!s->budget--) { s->failed_pc=0x0c0c56aau; return 0; }
r[0]=0x00000004u;
goto P_0c0c56ac;
P_0c0c56ac: /* original f2f6, guest PC 0x0c0c56ac */
if(!s->budget--) { s->failed_pc=0x0c0c56acu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c56ae;
P_0c0c56ae: /* original e004, guest PC 0x0c0c56ae */
if(!s->budget--) { s->failed_pc=0x0c0c56aeu; return 0; }
r[0]=0x00000004u;
goto P_0c0c56b0;
P_0c0c56b0: /* original f232, guest PC 0x0c0c56b0 */
if(!s->budget--) { s->failed_pc=0x0c0c56b0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0c56b2;
P_0c0c56b2: /* original ff27, guest PC 0x0c0c56b2 */
if(!s->budget--) { s->failed_pc=0x0c0c56b2u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c56b4;
P_0c0c56b4: /* original 9059, guest PC 0x0c0c56b4 */
if(!s->budget--) { s->failed_pc=0x0c0c56b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c576au,2);
goto P_0c0c56b6;
P_0c0c56b6: /* original f1f6, guest PC 0x0c0c56b6 */
if(!s->budget--) { s->failed_pc=0x0c0c56b6u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0c56b8;
P_0c0c56b8: /* original 9057, guest PC 0x0c0c56b8 */
if(!s->budget--) { s->failed_pc=0x0c0c56b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c576au,2);
goto P_0c0c56ba;
P_0c0c56ba: /* original f132, guest PC 0x0c0c56ba */
if(!s->budget--) { s->failed_pc=0x0c0c56bau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0c56bc;
P_0c0c56bc: /* original ff17, guest PC 0x0c0c56bc */
if(!s->budget--) { s->failed_pc=0x0c0c56bcu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c56be;
P_0c0c56be: /* original 9156, guest PC 0x0c0c56be */
if(!s->budget--) { s->failed_pc=0x0c0c56beu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c576eu,2);
goto P_0c0c56c0;
P_0c0c56c0: /* original 9256, guest PC 0x0c0c56c0 */
if(!s->budget--) { s->failed_pc=0x0c0c56c0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5770u,2);
goto P_0c0c56c2;
P_0c0c56c2: /* original d335, guest PC 0x0c0c56c2 */
if(!s->budget--) { s->failed_pc=0x0c0c56c2u; return 0; }
r[3]=read(ram,0x0c0c5798u,4);
goto P_0c0c56c4;
P_0c0c56c4: /* original 31fc, guest PC 0x0c0c56c4 */
if(!s->budget--) { s->failed_pc=0x0c0c56c4u; return 0; }
r[1]+=r[15];
goto P_0c0c56c6;
P_0c0c56c6: /* original 32fc, guest PC 0x0c0c56c6 */
if(!s->budget--) { s->failed_pc=0x0c0c56c6u; return 0; }
r[2]+=r[15];
goto P_0c0c56c8;
P_0c0c56c8: /* original 430b, guest PC 0x0c0c56c8 */
if(!s->budget--) { s->failed_pc=0x0c0c56c8u; return 0; }
target=r[3];
r[16]=0x0c0c56ccu;
r[0]=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c56ccu) { target=s->pc; goto dispatch; }
goto P_0c0c56cc;
P_0c0c56ca: /* original e034, guest PC 0x0c0c56ca */
if(!s->budget--) { s->failed_pc=0x0c0c56cau; return 0; }
r[0]=0x00000034u;
goto P_0c0c56cc;
P_0c0c56cc: /* original c733, guest PC 0x0c0c56cc */
if(!s->budget--) { s->failed_pc=0x0c0c56ccu; return 0; }
r[0]=0x0c0c579cu;
goto P_0c0c56ce;
P_0c0c56ce: /* original f308, guest PC 0x0c0c56ce */
if(!s->budget--) { s->failed_pc=0x0c0c56ceu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c56d0;
P_0c0c56d0: /* original 904f, guest PC 0x0c0c56d0 */
if(!s->budget--) { s->failed_pc=0x0c0c56d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5772u,2);
goto P_0c0c56d2;
P_0c0c56d2: /* original f1f6, guest PC 0x0c0c56d2 */
if(!s->budget--) { s->failed_pc=0x0c0c56d2u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0c56d4;
P_0c0c56d4: /* original 904d, guest PC 0x0c0c56d4 */
if(!s->budget--) { s->failed_pc=0x0c0c56d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5772u,2);
goto P_0c0c56d6;
P_0c0c56d6: /* original f130, guest PC 0x0c0c56d6 */
if(!s->budget--) { s->failed_pc=0x0c0c56d6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'+');
goto P_0c0c56d8;
P_0c0c56d8: /* original ff17, guest PC 0x0c0c56d8 */
if(!s->budget--) { s->failed_pc=0x0c0c56d8u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c56da;
P_0c0c56da: /* original 914b, guest PC 0x0c0c56da */
if(!s->budget--) { s->failed_pc=0x0c0c56dau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5774u,2);
goto P_0c0c56dc;
P_0c0c56dc: /* original 9248, guest PC 0x0c0c56dc */
if(!s->budget--) { s->failed_pc=0x0c0c56dcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5770u,2);
goto P_0c0c56de;
P_0c0c56de: /* original d32e, guest PC 0x0c0c56de */
if(!s->budget--) { s->failed_pc=0x0c0c56deu; return 0; }
r[3]=read(ram,0x0c0c5798u,4);
goto P_0c0c56e0;
P_0c0c56e0: /* original 31fc, guest PC 0x0c0c56e0 */
if(!s->budget--) { s->failed_pc=0x0c0c56e0u; return 0; }
r[1]+=r[15];
goto P_0c0c56e2;
P_0c0c56e2: /* original 32fc, guest PC 0x0c0c56e2 */
if(!s->budget--) { s->failed_pc=0x0c0c56e2u; return 0; }
r[2]+=r[15];
goto P_0c0c56e4;
P_0c0c56e4: /* original 430b, guest PC 0x0c0c56e4 */
if(!s->budget--) { s->failed_pc=0x0c0c56e4u; return 0; }
target=r[3];
r[16]=0x0c0c56e8u;
r[0]=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c56e8u) { target=s->pc; goto dispatch; }
goto P_0c0c56e8;
P_0c0c56e6: /* original e034, guest PC 0x0c0c56e6 */
if(!s->budget--) { s->failed_pc=0x0c0c56e6u; return 0; }
r[0]=0x00000034u;
goto P_0c0c56e8;
P_0c0c56e8: /* original c72d, guest PC 0x0c0c56e8 */
if(!s->budget--) { s->failed_pc=0x0c0c56e8u; return 0; }
r[0]=0x0c0c57a0u;
goto P_0c0c56ea;
P_0c0c56ea: /* original f108, guest PC 0x0c0c56ea */
if(!s->budget--) { s->failed_pc=0x0c0c56eau; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c0c56ec;
P_0c0c56ec: /* original 9043, guest PC 0x0c0c56ec */
if(!s->budget--) { s->failed_pc=0x0c0c56ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5776u,2);
goto P_0c0c56ee;
P_0c0c56ee: /* original f0f6, guest PC 0x0c0c56ee */
if(!s->budget--) { s->failed_pc=0x0c0c56eeu; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c0c56f0;
P_0c0c56f0: /* original 9041, guest PC 0x0c0c56f0 */
if(!s->budget--) { s->failed_pc=0x0c0c56f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5776u,2);
goto P_0c0c56f2;
P_0c0c56f2: /* original f011, guest PC 0x0c0c56f2 */
if(!s->budget--) { s->failed_pc=0x0c0c56f2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[1],r[18],'-');
goto P_0c0c56f4;
P_0c0c56f4: /* original ff07, guest PC 0x0c0c56f4 */
if(!s->budget--) { s->failed_pc=0x0c0c56f4u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0c56f6;
P_0c0c56f6: /* original 913f, guest PC 0x0c0c56f6 */
if(!s->budget--) { s->failed_pc=0x0c0c56f6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5778u,2);
goto P_0c0c56f8;
P_0c0c56f8: /* original 923a, guest PC 0x0c0c56f8 */
if(!s->budget--) { s->failed_pc=0x0c0c56f8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5770u,2);
goto P_0c0c56fa;
P_0c0c56fa: /* original d327, guest PC 0x0c0c56fa */
if(!s->budget--) { s->failed_pc=0x0c0c56fau; return 0; }
r[3]=read(ram,0x0c0c5798u,4);
goto P_0c0c56fc;
P_0c0c56fc: /* original 31fc, guest PC 0x0c0c56fc */
if(!s->budget--) { s->failed_pc=0x0c0c56fcu; return 0; }
r[1]+=r[15];
goto P_0c0c56fe;
P_0c0c56fe: /* original 32fc, guest PC 0x0c0c56fe */
if(!s->budget--) { s->failed_pc=0x0c0c56feu; return 0; }
r[2]+=r[15];
goto P_0c0c5700;
P_0c0c5700: /* original 430b, guest PC 0x0c0c5700 */
if(!s->budget--) { s->failed_pc=0x0c0c5700u; return 0; }
target=r[3];
r[16]=0x0c0c5704u;
r[0]=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5704u) { target=s->pc; goto dispatch; }
goto P_0c0c5704;
P_0c0c5702: /* original e034, guest PC 0x0c0c5702 */
if(!s->budget--) { s->failed_pc=0x0c0c5702u; return 0; }
r[0]=0x00000034u;
goto P_0c0c5704;
P_0c0c5704: /* original c727, guest PC 0x0c0c5704 */
if(!s->budget--) { s->failed_pc=0x0c0c5704u; return 0; }
r[0]=0x0c0c57a4u;
goto P_0c0c5706;
P_0c0c5706: /* original 61f3, guest PC 0x0c0c5706 */
if(!s->budget--) { s->failed_pc=0x0c0c5706u; return 0; }
r[1]=r[15];
goto P_0c0c5708;
P_0c0c5708: /* original f208, guest PC 0x0c0c5708 */
if(!s->budget--) { s->failed_pc=0x0c0c5708u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c570a;
P_0c0c570a: /* original 7154, guest PC 0x0c0c570a */
if(!s->budget--) { s->failed_pc=0x0c0c570au; return 0; }
r[1]+=0x00000054u;
goto P_0c0c570c;
P_0c0c570c: /* original 9035, guest PC 0x0c0c570c */
if(!s->budget--) { s->failed_pc=0x0c0c570cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c577au,2);
goto P_0c0c570e;
P_0c0c570e: /* original f0f6, guest PC 0x0c0c570e */
if(!s->budget--) { s->failed_pc=0x0c0c570eu; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c0c5710;
P_0c0c5710: /* original 9033, guest PC 0x0c0c5710 */
if(!s->budget--) { s->failed_pc=0x0c0c5710u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c577au,2);
goto P_0c0c5712;
P_0c0c5712: /* original f021, guest PC 0x0c0c5712 */
if(!s->budget--) { s->failed_pc=0x0c0c5712u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[2],r[18],'-');
goto P_0c0c5714;
P_0c0c5714: /* original ff07, guest PC 0x0c0c5714 */
if(!s->budget--) { s->failed_pc=0x0c0c5714u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0c5716;
P_0c0c5716: /* original 922b, guest PC 0x0c0c5716 */
if(!s->budget--) { s->failed_pc=0x0c0c5716u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5770u,2);
goto P_0c0c5718;
P_0c0c5718: /* original d31f, guest PC 0x0c0c5718 */
if(!s->budget--) { s->failed_pc=0x0c0c5718u; return 0; }
r[3]=read(ram,0x0c0c5798u,4);
goto P_0c0c571a;
P_0c0c571a: /* original 32fc, guest PC 0x0c0c571a */
if(!s->budget--) { s->failed_pc=0x0c0c571au; return 0; }
r[2]+=r[15];
goto P_0c0c571c;
P_0c0c571c: /* original 430b, guest PC 0x0c0c571c */
if(!s->budget--) { s->failed_pc=0x0c0c571cu; return 0; }
target=r[3];
r[16]=0x0c0c5720u;
r[0]=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5720u) { target=s->pc; goto dispatch; }
goto P_0c0c5720;
P_0c0c571e: /* original e034, guest PC 0x0c0c571e */
if(!s->budget--) { s->failed_pc=0x0c0c571eu; return 0; }
r[0]=0x00000034u;
goto P_0c0c5720;
P_0c0c5720: /* original c721, guest PC 0x0c0c5720 */
if(!s->budget--) { s->failed_pc=0x0c0c5720u; return 0; }
r[0]=0x0c0c57a8u;
goto P_0c0c5722;
P_0c0c5722: /* original f308, guest PC 0x0c0c5722 */
if(!s->budget--) { s->failed_pc=0x0c0c5722u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c5724;
P_0c0c5724: /* original e060, guest PC 0x0c0c5724 */
if(!s->budget--) { s->failed_pc=0x0c0c5724u; return 0; }
r[0]=0x00000060u;
goto P_0c0c5726;
P_0c0c5726: /* original f0f6, guest PC 0x0c0c5726 */
if(!s->budget--) { s->failed_pc=0x0c0c5726u; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c0c5728;
P_0c0c5728: /* original e060, guest PC 0x0c0c5728 */
if(!s->budget--) { s->failed_pc=0x0c0c5728u; return 0; }
r[0]=0x00000060u;
goto P_0c0c572a;
P_0c0c572a: /* original f031, guest PC 0x0c0c572a */
if(!s->budget--) { s->failed_pc=0x0c0c572au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0c572c;
P_0c0c572c: /* original ff07, guest PC 0x0c0c572c */
if(!s->budget--) { s->failed_pc=0x0c0c572cu; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0c572e;
P_0c0c572e: /* original e020, guest PC 0x0c0c572e */
if(!s->budget--) { s->failed_pc=0x0c0c572eu; return 0; }
r[0]=0x00000020u;
goto P_0c0c5730;
P_0c0c5730: /* original 4b0b, guest PC 0x0c0c5730 */
if(!s->budget--) { s->failed_pc=0x0c0c5730u; return 0; }
target=r[11];
r[16]=0x0c0c5734u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5734u) { target=s->pc; goto dispatch; }
goto P_0c0c5734;
P_0c0c5732: /* original 04fd, guest PC 0x0c0c5732 */
if(!s->budget--) { s->failed_pc=0x0c0c5732u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
goto P_0c0c5734;
P_0c0c5734: /* original 6e03, guest PC 0x0c0c5734 */
if(!s->budget--) { s->failed_pc=0x0c0c5734u; return 0; }
r[14]=r[0];
goto P_0c0c5736;
P_0c0c5736: /* original 9020, guest PC 0x0c0c5736 */
if(!s->budget--) { s->failed_pc=0x0c0c5736u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c577au,2);
goto P_0c0c5738;
P_0c0c5738: /* original 941e, guest PC 0x0c0c5738 */
if(!s->budget--) { s->failed_pc=0x0c0c5738u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5778u,2);
goto P_0c0c573a;
P_0c0c573a: /* original f8f6, guest PC 0x0c0c573a */
if(!s->budget--) { s->failed_pc=0x0c0c573au; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c0c573c;
P_0c0c573c: /* original e01c, guest PC 0x0c0c573c */
if(!s->budget--) { s->failed_pc=0x0c0c573cu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c573e;
P_0c0c573e: /* original f7e6, guest PC 0x0c0c573e */
if(!s->budget--) { s->failed_pc=0x0c0c573eu; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c5740;
P_0c0c5740: /* original e018, guest PC 0x0c0c5740 */
if(!s->budget--) { s->failed_pc=0x0c0c5740u; return 0; }
r[0]=0x00000018u;
goto P_0c0c5742;
P_0c0c5742: /* original d31a, guest PC 0x0c0c5742 */
if(!s->budget--) { s->failed_pc=0x0c0c5742u; return 0; }
r[3]=read(ram,0x0c0c57acu,4);
goto P_0c0c5744;
P_0c0c5744: /* original f6e6, guest PC 0x0c0c5744 */
if(!s->budget--) { s->failed_pc=0x0c0c5744u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c5746;
P_0c0c5746: /* original f5fc, guest PC 0x0c0c5746 */
if(!s->budget--) { s->failed_pc=0x0c0c5746u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c5748;
P_0c0c5748: /* original f4fc, guest PC 0x0c0c5748 */
if(!s->budget--) { s->failed_pc=0x0c0c5748u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0c574a;
P_0c0c574a: /* original 430b, guest PC 0x0c0c574a */
if(!s->budget--) { s->failed_pc=0x0c0c574au; return 0; }
target=r[3];
r[16]=0x0c0c574eu;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c574eu) { target=s->pc; goto dispatch; }
goto P_0c0c574e;
P_0c0c574c: /* original 34fc, guest PC 0x0c0c574c */
if(!s->budget--) { s->failed_pc=0x0c0c574cu; return 0; }
r[4]+=r[15];
goto P_0c0c574e;
P_0c0c574e: /* original e014, guest PC 0x0c0c574e */
if(!s->budget--) { s->failed_pc=0x0c0c574eu; return 0; }
r[0]=0x00000014u;
goto P_0c0c5750;
P_0c0c5750: /* original f9e6, guest PC 0x0c0c5750 */
if(!s->budget--) { s->failed_pc=0x0c0c5750u; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c0c5752;
P_0c0c5752: /* original e010, guest PC 0x0c0c5752 */
if(!s->budget--) { s->failed_pc=0x0c0c5752u; return 0; }
r[0]=0x00000010u;
goto P_0c0c5754;
P_0c0c5754: /* original f8e6, guest PC 0x0c0c5754 */
if(!s->budget--) { s->failed_pc=0x0c0c5754u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0c5756;
P_0c0c5756: /* original e00c, guest PC 0x0c0c5756 */
if(!s->budget--) { s->failed_pc=0x0c0c5756u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c5758;
P_0c0c5758: /* original f7e6, guest PC 0x0c0c5758 */
if(!s->budget--) { s->failed_pc=0x0c0c5758u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c575a;
P_0c0c575a: /* original e008, guest PC 0x0c0c575a */
if(!s->budget--) { s->failed_pc=0x0c0c575au; return 0; }
r[0]=0x00000008u;
goto P_0c0c575c;
P_0c0c575c: /* original f6e6, guest PC 0x0c0c575c */
if(!s->budget--) { s->failed_pc=0x0c0c575cu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c575e;
P_0c0c575e: /* original e004, guest PC 0x0c0c575e */
if(!s->budget--) { s->failed_pc=0x0c0c575eu; return 0; }
r[0]=0x00000004u;
goto P_0c0c5760;
P_0c0c5760: /* original f5e6, guest PC 0x0c0c5760 */
if(!s->budget--) { s->failed_pc=0x0c0c5760u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0c5762;
P_0c0c5762: /* original a025, guest PC 0x0c0c5762 */
if(!s->budget--) { s->failed_pc=0x0c0c5762u; return 0; }
goto P_0c0c57b0;
P_0c0c5764: /* original 0009, guest PC 0x0c0c5764 */
if(!s->budget--) { s->failed_pc=0x0c0c5764u; return 0; }
return vf3_matrix_family(0x0c0c5766u,s,ram);
P_0c0c57b0: /* original 94a5, guest PC 0x0c0c57b0 */
if(!s->budget--) { s->failed_pc=0x0c0c57b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c58feu,2);
goto P_0c0c57b2;
P_0c0c57b2: /* original f4e8, guest PC 0x0c0c57b2 */
if(!s->budget--) { s->failed_pc=0x0c0c57b2u; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
goto P_0c0c57b4;
P_0c0c57b4: /* original 480b, guest PC 0x0c0c57b4 */
if(!s->budget--) { s->failed_pc=0x0c0c57b4u; return 0; }
target=r[8];
r[16]=0x0c0c57b8u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c57b8u) { target=s->pc; goto dispatch; }
goto P_0c0c57b8;
P_0c0c57b6: /* original 34fc, guest PC 0x0c0c57b6 */
if(!s->budget--) { s->failed_pc=0x0c0c57b6u; return 0; }
r[4]+=r[15];
goto P_0c0c57b8;
P_0c0c57b8: /* original e00c, guest PC 0x0c0c57b8 */
if(!s->budget--) { s->failed_pc=0x0c0c57b8u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c57ba;
P_0c0c57ba: /* original f3e6, guest PC 0x0c0c57ba */
if(!s->budget--) { s->failed_pc=0x0c0c57bau; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c57bc;
P_0c0c57bc: /* original e01c, guest PC 0x0c0c57bc */
if(!s->budget--) { s->failed_pc=0x0c0c57bcu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c57be;
P_0c0c57be: /* original f2e6, guest PC 0x0c0c57be */
if(!s->budget--) { s->failed_pc=0x0c0c57beu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0c57c0;
P_0c0c57c0: /* original 909e, guest PC 0x0c0c57c0 */
if(!s->budget--) { s->failed_pc=0x0c0c57c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5900u,2);
goto P_0c0c57c2;
P_0c0c57c2: /* original f233, guest PC 0x0c0c57c2 */
if(!s->budget--) { s->failed_pc=0x0c0c57c2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'/');
goto P_0c0c57c4;
P_0c0c57c4: /* original ff27, guest PC 0x0c0c57c4 */
if(!s->budget--) { s->failed_pc=0x0c0c57c4u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c57c6;
P_0c0c57c6: /* original e008, guest PC 0x0c0c57c6 */
if(!s->budget--) { s->failed_pc=0x0c0c57c6u; return 0; }
r[0]=0x00000008u;
goto P_0c0c57c8;
P_0c0c57c8: /* original f2e6, guest PC 0x0c0c57c8 */
if(!s->budget--) { s->failed_pc=0x0c0c57c8u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0c57ca;
P_0c0c57ca: /* original e028, guest PC 0x0c0c57ca */
if(!s->budget--) { s->failed_pc=0x0c0c57cau; return 0; }
r[0]=0x00000028u;
goto P_0c0c57cc;
P_0c0c57cc: /* original f3a8, guest PC 0x0c0c57cc */
if(!s->budget--) { s->failed_pc=0x0c0c57ccu; return 0; }
vf3_matrix_load(s,ram,3,r[10]);
goto P_0c0c57ce;
P_0c0c57ce: /* original f232, guest PC 0x0c0c57ce */
if(!s->budget--) { s->failed_pc=0x0c0c57ceu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0c57d0;
P_0c0c57d0: /* original ff27, guest PC 0x0c0c57d0 */
if(!s->budget--) { s->failed_pc=0x0c0c57d0u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c57d2;
P_0c0c57d2: /* original c755, guest PC 0x0c0c57d2 */
if(!s->budget--) { s->failed_pc=0x0c0c57d2u; return 0; }
r[0]=0x0c0c5928u;
goto P_0c0c57d4;
P_0c0c57d4: /* original f308, guest PC 0x0c0c57d4 */
if(!s->budget--) { s->failed_pc=0x0c0c57d4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c57d6;
P_0c0c57d6: /* original 9093, guest PC 0x0c0c57d6 */
if(!s->budget--) { s->failed_pc=0x0c0c57d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5900u,2);
goto P_0c0c57d8;
P_0c0c57d8: /* original f1f6, guest PC 0x0c0c57d8 */
if(!s->budget--) { s->failed_pc=0x0c0c57d8u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0c57da;
P_0c0c57da: /* original 9091, guest PC 0x0c0c57da */
if(!s->budget--) { s->failed_pc=0x0c0c57dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5900u,2);
goto P_0c0c57dc;
P_0c0c57dc: /* original f132, guest PC 0x0c0c57dc */
if(!s->budget--) { s->failed_pc=0x0c0c57dcu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0c57de;
P_0c0c57de: /* original ff17, guest PC 0x0c0c57de */
if(!s->budget--) { s->failed_pc=0x0c0c57deu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c57e0;
P_0c0c57e0: /* original 53e8, guest PC 0x0c0c57e0 */
if(!s->budget--) { s->failed_pc=0x0c0c57e0u; return 0; }
r[3]=read(ram,r[14]+32,4);
goto P_0c0c57e2;
P_0c0c57e2: /* original d052, guest PC 0x0c0c57e2 */
if(!s->budget--) { s->failed_pc=0x0c0c57e2u; return 0; }
r[0]=read(ram,0x0c0c592cu,4);
goto P_0c0c57e4;
P_0c0c57e4: /* original 4300, guest PC 0x0c0c57e4 */
if(!s->budget--) { s->failed_pc=0x0c0c57e4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c57e6;
P_0c0c57e6: /* original 023d, guest PC 0x0c0c57e6 */
if(!s->budget--) { s->failed_pc=0x0c0c57e6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c57e8;
P_0c0c57e8: /* original 9089, guest PC 0x0c0c57e8 */
if(!s->budget--) { s->failed_pc=0x0c0c57e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c58feu,2);
goto P_0c0c57ea;
P_0c0c57ea: /* original 622d, guest PC 0x0c0c57ea */
if(!s->budget--) { s->failed_pc=0x0c0c57eau; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c57ec;
P_0c0c57ec: /* original 0f26, guest PC 0x0c0c57ec */
if(!s->budget--) { s->failed_pc=0x0c0c57ecu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0c57ee;
P_0c0c57ee: /* original c750, guest PC 0x0c0c57ee */
if(!s->budget--) { s->failed_pc=0x0c0c57eeu; return 0; }
r[0]=0x0c0c5930u;
goto P_0c0c57f0;
P_0c0c57f0: /* original ffec, guest PC 0x0c0c57f0 */
if(!s->budget--) { s->failed_pc=0x0c0c57f0u; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c0c57f2;
P_0c0c57f2: /* original a07c, guest PC 0x0c0c57f2 */
if(!s->budget--) { s->failed_pc=0x0c0c57f2u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c0c58ee;
P_0c0c57f4: /* original fe08, guest PC 0x0c0c57f4 */
if(!s->budget--) { s->failed_pc=0x0c0c57f4u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c0c57f6;
P_0c0c57f6: /* original 9084, guest PC 0x0c0c57f6 */
if(!s->budget--) { s->failed_pc=0x0c0c57f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5902u,2);
goto P_0c0c57f8;
P_0c0c57f8: /* original ffd7, guest PC 0x0c0c57f8 */
if(!s->budget--) { s->failed_pc=0x0c0c57f8u; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0c57fa;
P_0c0c57fa: /* original e00c, guest PC 0x0c0c57fa */
if(!s->budget--) { s->failed_pc=0x0c0c57fau; return 0; }
r[0]=0x0000000cu;
goto P_0c0c57fc;
P_0c0c57fc: /* original f3f6, guest PC 0x0c0c57fc */
if(!s->budget--) { s->failed_pc=0x0c0c57fcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c57fe;
P_0c0c57fe: /* original 9081, guest PC 0x0c0c57fe */
if(!s->budget--) { s->failed_pc=0x0c0c57feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5904u,2);
goto P_0c0c5800;
P_0c0c5800: /* original ff37, guest PC 0x0c0c5800 */
if(!s->budget--) { s->failed_pc=0x0c0c5800u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c5802;
P_0c0c5802: /* original e008, guest PC 0x0c0c5802 */
if(!s->budget--) { s->failed_pc=0x0c0c5802u; return 0; }
r[0]=0x00000008u;
goto P_0c0c5804;
P_0c0c5804: /* original f3f6, guest PC 0x0c0c5804 */
if(!s->budget--) { s->failed_pc=0x0c0c5804u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5806;
P_0c0c5806: /* original 907e, guest PC 0x0c0c5806 */
if(!s->budget--) { s->failed_pc=0x0c0c5806u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5906u,2);
goto P_0c0c5808;
P_0c0c5808: /* original ff37, guest PC 0x0c0c5808 */
if(!s->budget--) { s->failed_pc=0x0c0c5808u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c580a;
P_0c0c580a: /* original 907d, guest PC 0x0c0c580a */
if(!s->budget--) { s->failed_pc=0x0c0c580au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5908u,2);
goto P_0c0c580c;
P_0c0c580c: /* original ffd7, guest PC 0x0c0c580c */
if(!s->budget--) { s->failed_pc=0x0c0c580cu; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0c580e;
P_0c0c580e: /* original e070, guest PC 0x0c0c580e */
if(!s->budget--) { s->failed_pc=0x0c0c580eu; return 0; }
r[0]=0x00000070u;
goto P_0c0c5810;
P_0c0c5810: /* original ffd7, guest PC 0x0c0c5810 */
if(!s->budget--) { s->failed_pc=0x0c0c5810u; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0c5812;
P_0c0c5812: /* original e004, guest PC 0x0c0c5812 */
if(!s->budget--) { s->failed_pc=0x0c0c5812u; return 0; }
r[0]=0x00000004u;
goto P_0c0c5814;
P_0c0c5814: /* original f4f6, guest PC 0x0c0c5814 */
if(!s->budget--) { s->failed_pc=0x0c0c5814u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c5816;
P_0c0c5816: /* original e00c, guest PC 0x0c0c5816 */
if(!s->budget--) { s->failed_pc=0x0c0c5816u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c5818;
P_0c0c5818: /* original f3f6, guest PC 0x0c0c5818 */
if(!s->budget--) { s->failed_pc=0x0c0c5818u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c581a;
P_0c0c581a: /* original e00c, guest PC 0x0c0c581a */
if(!s->budget--) { s->failed_pc=0x0c0c581au; return 0; }
r[0]=0x0000000cu;
goto P_0c0c581c;
P_0c0c581c: /* original f340, guest PC 0x0c0c581c */
if(!s->budget--) { s->failed_pc=0x0c0c581cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c0c581e;
P_0c0c581e: /* original ff37, guest PC 0x0c0c581e */
if(!s->budget--) { s->failed_pc=0x0c0c581eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c5820;
P_0c0c5820: /* original e008, guest PC 0x0c0c5820 */
if(!s->budget--) { s->failed_pc=0x0c0c5820u; return 0; }
r[0]=0x00000008u;
goto P_0c0c5822;
P_0c0c5822: /* original f2f6, guest PC 0x0c0c5822 */
if(!s->budget--) { s->failed_pc=0x0c0c5822u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c5824;
P_0c0c5824: /* original e008, guest PC 0x0c0c5824 */
if(!s->budget--) { s->failed_pc=0x0c0c5824u; return 0; }
r[0]=0x00000008u;
goto P_0c0c5826;
P_0c0c5826: /* original f240, guest PC 0x0c0c5826 */
if(!s->budget--) { s->failed_pc=0x0c0c5826u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'+');
goto P_0c0c5828;
P_0c0c5828: /* original ff27, guest PC 0x0c0c5828 */
if(!s->budget--) { s->failed_pc=0x0c0c5828u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c582a;
P_0c0c582a: /* original c742, guest PC 0x0c0c582a */
if(!s->budget--) { s->failed_pc=0x0c0c582au; return 0; }
r[0]=0x0c0c5934u;
goto P_0c0c582c;
P_0c0c582c: /* original f108, guest PC 0x0c0c582c */
if(!s->budget--) { s->failed_pc=0x0c0c582cu; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c0c582e;
P_0c0c582e: /* original f1f5, guest PC 0x0c0c582e */
if(!s->budget--) { s->failed_pc=0x0c0c582eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[1])>as_float(fr[15]))!=0);
goto P_0c0c5830;
P_0c0c5830: /* original 8d5a, guest PC 0x0c0c5830 */
if(!s->budget--) { s->failed_pc=0x0c0c5830u; return 0; }
cond=r[17]&1u;
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'+');
if(cond) { goto P_0c0c58e8; }
goto P_0c0c5834;
P_0c0c5832: /* original fd40, guest PC 0x0c0c5832 */
if(!s->budget--) { s->failed_pc=0x0c0c5832u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'+');
goto P_0c0c5834;
P_0c0c5834: /* original f38d, guest PC 0x0c0c5834 */
if(!s->budget--) { s->failed_pc=0x0c0c5834u; return 0; }
fr[3]=0;
goto P_0c0c5836;
P_0c0c5836: /* original f3f5, guest PC 0x0c0c5836 */
if(!s->budget--) { s->failed_pc=0x0c0c5836u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0c5838;
P_0c0c5838: /* original 8b01, guest PC 0x0c0c5838 */
if(!s->budget--) { s->failed_pc=0x0c0c5838u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c583e; }
goto P_0c0c583a;
P_0c0c583a: /* original a004, guest PC 0x0c0c583a */
if(!s->budget--) { s->failed_pc=0x0c0c583au; return 0; }
r[4]=r[12];
goto P_0c0c5846;
P_0c0c583c: /* original 64c3, guest PC 0x0c0c583c */
if(!s->budget--) { s->failed_pc=0x0c0c583cu; return 0; }
r[4]=r[12];
goto P_0c0c583e;
P_0c0c583e: /* original f3fc, guest PC 0x0c0c583e */
if(!s->budget--) { s->failed_pc=0x0c0c583eu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0c5840;
P_0c0c5840: /* original f3c2, guest PC 0x0c0c5840 */
if(!s->budget--) { s->failed_pc=0x0c0c5840u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'*');
goto P_0c0c5842;
P_0c0c5842: /* original f33d, guest PC 0x0c0c5842 */
if(!s->budget--) { s->failed_pc=0x0c0c5842u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0c5844;
P_0c0c5844: /* original 045a, guest PC 0x0c0c5844 */
if(!s->budget--) { s->failed_pc=0x0c0c5844u; return 0; }
r[4]=r[53];
goto P_0c0c5846;
P_0c0c5846: /* original 9060, guest PC 0x0c0c5846 */
if(!s->budget--) { s->failed_pc=0x0c0c5846u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c590au,2);
goto P_0c0c5848;
P_0c0c5848: /* original ffd7, guest PC 0x0c0c5848 */
if(!s->budget--) { s->failed_pc=0x0c0c5848u; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0c584a;
P_0c0c584a: /* original e00c, guest PC 0x0c0c584a */
if(!s->budget--) { s->failed_pc=0x0c0c584au; return 0; }
r[0]=0x0000000cu;
goto P_0c0c584c;
P_0c0c584c: /* original f3f6, guest PC 0x0c0c584c */
if(!s->budget--) { s->failed_pc=0x0c0c584cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c584e;
P_0c0c584e: /* original 905d, guest PC 0x0c0c584e */
if(!s->budget--) { s->failed_pc=0x0c0c584eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c590cu,2);
goto P_0c0c5850;
P_0c0c5850: /* original ff37, guest PC 0x0c0c5850 */
if(!s->budget--) { s->failed_pc=0x0c0c5850u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c5852;
P_0c0c5852: /* original e008, guest PC 0x0c0c5852 */
if(!s->budget--) { s->failed_pc=0x0c0c5852u; return 0; }
r[0]=0x00000008u;
goto P_0c0c5854;
P_0c0c5854: /* original f3f6, guest PC 0x0c0c5854 */
if(!s->budget--) { s->failed_pc=0x0c0c5854u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5856;
P_0c0c5856: /* original 905a, guest PC 0x0c0c5856 */
if(!s->budget--) { s->failed_pc=0x0c0c5856u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c590eu,2);
goto P_0c0c5858;
P_0c0c5858: /* original ff37, guest PC 0x0c0c5858 */
if(!s->budget--) { s->failed_pc=0x0c0c5858u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c585a;
P_0c0c585a: /* original 9059, guest PC 0x0c0c585a */
if(!s->budget--) { s->failed_pc=0x0c0c585au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5910u,2);
goto P_0c0c585c;
P_0c0c585c: /* original ffd7, guest PC 0x0c0c585c */
if(!s->budget--) { s->failed_pc=0x0c0c585cu; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0c585e;
P_0c0c585e: /* original e078, guest PC 0x0c0c585e */
if(!s->budget--) { s->failed_pc=0x0c0c585eu; return 0; }
r[0]=0x00000078u;
goto P_0c0c5860;
P_0c0c5860: /* original ffd7, guest PC 0x0c0c5860 */
if(!s->budget--) { s->failed_pc=0x0c0c5860u; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0c5862;
P_0c0c5862: /* original 9056, guest PC 0x0c0c5862 */
if(!s->budget--) { s->failed_pc=0x0c0c5862u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5912u,2);
goto P_0c0c5864;
P_0c0c5864: /* original f3f6, guest PC 0x0c0c5864 */
if(!s->budget--) { s->failed_pc=0x0c0c5864u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5866;
P_0c0c5866: /* original e02c, guest PC 0x0c0c5866 */
if(!s->budget--) { s->failed_pc=0x0c0c5866u; return 0; }
r[0]=0x0000002cu;
goto P_0c0c5868;
P_0c0c5868: /* original ff37, guest PC 0x0c0c5868 */
if(!s->budget--) { s->failed_pc=0x0c0c5868u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c586a;
P_0c0c586a: /* original 6043, guest PC 0x0c0c586a */
if(!s->budget--) { s->failed_pc=0x0c0c586au; return 0; }
r[0]=r[4];
goto P_0c0c586c;
P_0c0c586c: /* original 4000, guest PC 0x0c0c586c */
if(!s->budget--) { s->failed_pc=0x0c0c586cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c586e;
P_0c0c586e: /* original 039d, guest PC 0x0c0c586e */
if(!s->budget--) { s->failed_pc=0x0c0c586eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[9]+r[0],2);
goto P_0c0c5870;
P_0c0c5870: /* original 904f, guest PC 0x0c0c5870 */
if(!s->budget--) { s->failed_pc=0x0c0c5870u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5912u,2);
goto P_0c0c5872;
P_0c0c5872: /* original 435a, guest PC 0x0c0c5872 */
if(!s->budget--) { s->failed_pc=0x0c0c5872u; return 0; }
r[53]=r[3];
goto P_0c0c5874;
P_0c0c5874: /* original f2f6, guest PC 0x0c0c5874 */
if(!s->budget--) { s->failed_pc=0x0c0c5874u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c5876;
P_0c0c5876: /* original 904c, guest PC 0x0c0c5876 */
if(!s->budget--) { s->failed_pc=0x0c0c5876u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5912u,2);
goto P_0c0c5878;
P_0c0c5878: /* original f32d, guest PC 0x0c0c5878 */
if(!s->budget--) { s->failed_pc=0x0c0c5878u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c587a;
P_0c0c587a: /* original f230, guest PC 0x0c0c587a */
if(!s->budget--) { s->failed_pc=0x0c0c587au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c587c;
P_0c0c587c: /* original ff27, guest PC 0x0c0c587c */
if(!s->budget--) { s->failed_pc=0x0c0c587cu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c587e;
P_0c0c587e: /* original e010, guest PC 0x0c0c587e */
if(!s->budget--) { s->failed_pc=0x0c0c587eu; return 0; }
r[0]=0x00000010u;
goto P_0c0c5880;
P_0c0c5880: /* original f3f6, guest PC 0x0c0c5880 */
if(!s->budget--) { s->failed_pc=0x0c0c5880u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5882;
P_0c0c5882: /* original f230, guest PC 0x0c0c5882 */
if(!s->budget--) { s->failed_pc=0x0c0c5882u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5884;
P_0c0c5884: /* original f2e0, guest PC 0x0c0c5884 */
if(!s->budget--) { s->failed_pc=0x0c0c5884u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[14],r[18],'+');
goto P_0c0c5886;
P_0c0c5886: /* original 9045, guest PC 0x0c0c5886 */
if(!s->budget--) { s->failed_pc=0x0c0c5886u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5914u,2);
goto P_0c0c5888;
P_0c0c5888: /* original ff27, guest PC 0x0c0c5888 */
if(!s->budget--) { s->failed_pc=0x0c0c5888u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c588a;
P_0c0c588a: /* original f230, guest PC 0x0c0c588a */
if(!s->budget--) { s->failed_pc=0x0c0c588au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c588c;
P_0c0c588c: /* original 9043, guest PC 0x0c0c588c */
if(!s->budget--) { s->failed_pc=0x0c0c588cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5916u,2);
goto P_0c0c588e;
P_0c0c588e: /* original f2e0, guest PC 0x0c0c588e */
if(!s->budget--) { s->failed_pc=0x0c0c588eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[14],r[18],'+');
goto P_0c0c5890;
P_0c0c5890: /* original ff27, guest PC 0x0c0c5890 */
if(!s->budget--) { s->failed_pc=0x0c0c5890u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c5892;
P_0c0c5892: /* original e010, guest PC 0x0c0c5892 */
if(!s->budget--) { s->failed_pc=0x0c0c5892u; return 0; }
r[0]=0x00000010u;
goto P_0c0c5894;
P_0c0c5894: /* original f3f6, guest PC 0x0c0c5894 */
if(!s->budget--) { s->failed_pc=0x0c0c5894u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5896;
P_0c0c5896: /* original 903f, guest PC 0x0c0c5896 */
if(!s->budget--) { s->failed_pc=0x0c0c5896u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5918u,2);
goto P_0c0c5898;
P_0c0c5898: /* original f230, guest PC 0x0c0c5898 */
if(!s->budget--) { s->failed_pc=0x0c0c5898u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c589a;
P_0c0c589a: /* original f2e0, guest PC 0x0c0c589a */
if(!s->budget--) { s->failed_pc=0x0c0c589au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[14],r[18],'+');
goto P_0c0c589c;
P_0c0c589c: /* original ff27, guest PC 0x0c0c589c */
if(!s->budget--) { s->failed_pc=0x0c0c589cu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c589e;
P_0c0c589e: /* original e028, guest PC 0x0c0c589e */
if(!s->budget--) { s->failed_pc=0x0c0c589eu; return 0; }
r[0]=0x00000028u;
goto P_0c0c58a0;
P_0c0c58a0: /* original f2f6, guest PC 0x0c0c58a0 */
if(!s->budget--) { s->failed_pc=0x0c0c58a0u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c58a2;
P_0c0c58a2: /* original 9039, guest PC 0x0c0c58a2 */
if(!s->budget--) { s->failed_pc=0x0c0c58a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5918u,2);
goto P_0c0c58a4;
P_0c0c58a4: /* original f1f6, guest PC 0x0c0c58a4 */
if(!s->budget--) { s->failed_pc=0x0c0c58a4u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0c58a6;
P_0c0c58a6: /* original e058, guest PC 0x0c0c58a6 */
if(!s->budget--) { s->failed_pc=0x0c0c58a6u; return 0; }
r[0]=0x00000058u;
goto P_0c0c58a8;
P_0c0c58a8: /* original f120, guest PC 0x0c0c58a8 */
if(!s->budget--) { s->failed_pc=0x0c0c58a8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'+');
goto P_0c0c58aa;
P_0c0c58aa: /* original f1e0, guest PC 0x0c0c58aa */
if(!s->budget--) { s->failed_pc=0x0c0c58aau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[14],r[18],'+');
goto P_0c0c58ac;
P_0c0c58ac: /* original ff17, guest PC 0x0c0c58ac */
if(!s->budget--) { s->failed_pc=0x0c0c58acu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c58ae;
P_0c0c58ae: /* original 9034, guest PC 0x0c0c58ae */
if(!s->budget--) { s->failed_pc=0x0c0c58aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c591au,2);
goto P_0c0c58b0;
P_0c0c58b0: /* original fff7, guest PC 0x0c0c58b0 */
if(!s->budget--) { s->failed_pc=0x0c0c58b0u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0c58b2;
P_0c0c58b2: /* original 9033, guest PC 0x0c0c58b2 */
if(!s->budget--) { s->failed_pc=0x0c0c58b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c591cu,2);
goto P_0c0c58b4;
P_0c0c58b4: /* original fff7, guest PC 0x0c0c58b4 */
if(!s->budget--) { s->failed_pc=0x0c0c58b4u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0c58b6;
P_0c0c58b6: /* original 9032, guest PC 0x0c0c58b6 */
if(!s->budget--) { s->failed_pc=0x0c0c58b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c591eu,2);
goto P_0c0c58b8;
P_0c0c58b8: /* original fff7, guest PC 0x0c0c58b8 */
if(!s->budget--) { s->failed_pc=0x0c0c58b8u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0c58ba;
P_0c0c58ba: /* original 9031, guest PC 0x0c0c58ba */
if(!s->budget--) { s->failed_pc=0x0c0c58bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5920u,2);
goto P_0c0c58bc;
P_0c0c58bc: /* original fff7, guest PC 0x0c0c58bc */
if(!s->budget--) { s->failed_pc=0x0c0c58bcu; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0c58be;
P_0c0c58be: /* original e05c, guest PC 0x0c0c58be */
if(!s->budget--) { s->failed_pc=0x0c0c58beu; return 0; }
r[0]=0x0000005cu;
goto P_0c0c58c0;
P_0c0c58c0: /* original fff7, guest PC 0x0c0c58c0 */
if(!s->budget--) { s->failed_pc=0x0c0c58c0u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0c58c2;
P_0c0c58c2: /* original 942e, guest PC 0x0c0c58c2 */
if(!s->budget--) { s->failed_pc=0x0c0c58c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5922u,2);
goto P_0c0c58c4;
P_0c0c58c4: /* original 4d0b, guest PC 0x0c0c58c4 */
if(!s->budget--) { s->failed_pc=0x0c0c58c4u; return 0; }
target=r[13];
r[16]=0x0c0c58c8u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c58c8u) { target=s->pc; goto dispatch; }
goto P_0c0c58c8;
P_0c0c58c6: /* original 34fc, guest PC 0x0c0c58c6 */
if(!s->budget--) { s->failed_pc=0x0c0c58c6u; return 0; }
r[4]+=r[15];
goto P_0c0c58c8;
P_0c0c58c8: /* original 942c, guest PC 0x0c0c58c8 */
if(!s->budget--) { s->failed_pc=0x0c0c58c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5924u,2);
goto P_0c0c58ca;
P_0c0c58ca: /* original 4d0b, guest PC 0x0c0c58ca */
if(!s->budget--) { s->failed_pc=0x0c0c58cau; return 0; }
target=r[13];
r[16]=0x0c0c58ceu;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c58ceu) { target=s->pc; goto dispatch; }
goto P_0c0c58ce;
P_0c0c58cc: /* original 34fc, guest PC 0x0c0c58cc */
if(!s->budget--) { s->failed_pc=0x0c0c58ccu; return 0; }
r[4]+=r[15];
goto P_0c0c58ce;
P_0c0c58ce: /* original 942a, guest PC 0x0c0c58ce */
if(!s->budget--) { s->failed_pc=0x0c0c58ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5926u,2);
goto P_0c0c58d0;
P_0c0c58d0: /* original 4d0b, guest PC 0x0c0c58d0 */
if(!s->budget--) { s->failed_pc=0x0c0c58d0u; return 0; }
target=r[13];
r[16]=0x0c0c58d4u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c58d4u) { target=s->pc; goto dispatch; }
goto P_0c0c58d4;
P_0c0c58d2: /* original 34fc, guest PC 0x0c0c58d2 */
if(!s->budget--) { s->failed_pc=0x0c0c58d2u; return 0; }
r[4]+=r[15];
goto P_0c0c58d4;
P_0c0c58d4: /* original 9413, guest PC 0x0c0c58d4 */
if(!s->budget--) { s->failed_pc=0x0c0c58d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c58feu,2);
goto P_0c0c58d6;
P_0c0c58d6: /* original 4d0b, guest PC 0x0c0c58d6 */
if(!s->budget--) { s->failed_pc=0x0c0c58d6u; return 0; }
target=r[13];
r[16]=0x0c0c58dau;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c58dau) { target=s->pc; goto dispatch; }
goto P_0c0c58da;
P_0c0c58d8: /* original 34fc, guest PC 0x0c0c58d8 */
if(!s->budget--) { s->failed_pc=0x0c0c58d8u; return 0; }
r[4]+=r[15];
goto P_0c0c58da;
P_0c0c58da: /* original 64f3, guest PC 0x0c0c58da */
if(!s->budget--) { s->failed_pc=0x0c0c58dau; return 0; }
r[4]=r[15];
goto P_0c0c58dc;
P_0c0c58dc: /* original 4d0b, guest PC 0x0c0c58dc */
if(!s->budget--) { s->failed_pc=0x0c0c58dcu; return 0; }
target=r[13];
r[16]=0x0c0c58e0u;
r[4]+=0x00000054u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c58e0u) { target=s->pc; goto dispatch; }
goto P_0c0c58e0;
P_0c0c58de: /* original 7454, guest PC 0x0c0c58de */
if(!s->budget--) { s->failed_pc=0x0c0c58deu; return 0; }
r[4]+=0x00000054u;
goto P_0c0c58e0;
P_0c0c58e0: /* original e02c, guest PC 0x0c0c58e0 */
if(!s->budget--) { s->failed_pc=0x0c0c58e0u; return 0; }
r[0]=0x0000002cu;
goto P_0c0c58e2;
P_0c0c58e2: /* original f3f6, guest PC 0x0c0c58e2 */
if(!s->budget--) { s->failed_pc=0x0c0c58e2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c58e4;
P_0c0c58e4: /* original 9015, guest PC 0x0c0c58e4 */
if(!s->budget--) { s->failed_pc=0x0c0c58e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5912u,2);
goto P_0c0c58e6;
P_0c0c58e6: /* original ff37, guest PC 0x0c0c58e6 */
if(!s->budget--) { s->failed_pc=0x0c0c58e6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c58e8;
P_0c0c58e8: /* original c70f, guest PC 0x0c0c58e8 */
if(!s->budget--) { s->failed_pc=0x0c0c58e8u; return 0; }
r[0]=0x0c0c5928u;
goto P_0c0c58ea;
P_0c0c58ea: /* original f308, guest PC 0x0c0c58ea */
if(!s->budget--) { s->failed_pc=0x0c0c58eau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c58ec;
P_0c0c58ec: /* original ff30, guest PC 0x0c0c58ec */
if(!s->budget--) { s->failed_pc=0x0c0c58ecu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c0c58ee;
P_0c0c58ee: /* original e01c, guest PC 0x0c0c58ee */
if(!s->budget--) { s->failed_pc=0x0c0c58eeu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c58f0;
P_0c0c58f0: /* original f3f6, guest PC 0x0c0c58f0 */
if(!s->budget--) { s->failed_pc=0x0c0c58f0u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c58f2;
P_0c0c58f2: /* original ff35, guest PC 0x0c0c58f2 */
if(!s->budget--) { s->failed_pc=0x0c0c58f2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c0c58f4;
P_0c0c58f4: /* original 8901, guest PC 0x0c0c58f4 */
if(!s->budget--) { s->failed_pc=0x0c0c58f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c58fa; }
goto P_0c0c58f6;
P_0c0c58f6: /* original af7e, guest PC 0x0c0c58f6 */
if(!s->budget--) { s->failed_pc=0x0c0c58f6u; return 0; }
goto P_0c0c57f6;
P_0c0c58f8: /* original 0009, guest PC 0x0c0c58f8 */
if(!s->budget--) { s->failed_pc=0x0c0c58f8u; return 0; }
goto P_0c0c58fa;
P_0c0c58fa: /* original a097, guest PC 0x0c0c58fa */
if(!s->budget--) { s->failed_pc=0x0c0c58fau; return 0; }
goto P_0c0c5a2c;
P_0c0c58fc: /* original 0009, guest PC 0x0c0c58fc */
if(!s->budget--) { s->failed_pc=0x0c0c58fcu; return 0; }
return vf3_matrix_family(0x0c0c58feu,s,ram);
P_0c0c5938: /* original e008, guest PC 0x0c0c5938 */
if(!s->budget--) { s->failed_pc=0x0c0c5938u; return 0; }
r[0]=0x00000008u;
goto P_0c0c593a;
P_0c0c593a: /* original fe45, guest PC 0x0c0c593a */
if(!s->budget--) { s->failed_pc=0x0c0c593au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c0c593c;
P_0c0c593c: /* original f3e6, guest PC 0x0c0c593c */
if(!s->budget--) { s->failed_pc=0x0c0c593cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c593e;
P_0c0c593e: /* original e024, guest PC 0x0c0c593e */
if(!s->budget--) { s->failed_pc=0x0c0c593eu; return 0; }
r[0]=0x00000024u;
goto P_0c0c5940;
P_0c0c5940: /* original f362, guest PC 0x0c0c5940 */
if(!s->budget--) { s->failed_pc=0x0c0c5940u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c0c5942;
P_0c0c5942: /* original ff37, guest PC 0x0c0c5942 */
if(!s->budget--) { s->failed_pc=0x0c0c5942u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c5944;
P_0c0c5944: /* original e014, guest PC 0x0c0c5944 */
if(!s->budget--) { s->failed_pc=0x0c0c5944u; return 0; }
r[0]=0x00000014u;
goto P_0c0c5946;
P_0c0c5946: /* original f8e6, guest PC 0x0c0c5946 */
if(!s->budget--) { s->failed_pc=0x0c0c5946u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0c5948;
P_0c0c5948: /* original e00c, guest PC 0x0c0c5948 */
if(!s->budget--) { s->failed_pc=0x0c0c5948u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c594a;
P_0c0c594a: /* original f6e6, guest PC 0x0c0c594a */
if(!s->budget--) { s->failed_pc=0x0c0c594au; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c594c;
P_0c0c594c: /* original e014, guest PC 0x0c0c594c */
if(!s->budget--) { s->failed_pc=0x0c0c594cu; return 0; }
r[0]=0x00000014u;
goto P_0c0c594e;
P_0c0c594e: /* original f3ec, guest PC 0x0c0c594e */
if(!s->budget--) { s->failed_pc=0x0c0c594eu; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c0c5950;
P_0c0c5950: /* original f06c, guest PC 0x0c0c5950 */
if(!s->budget--) { s->failed_pc=0x0c0c5950u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0c5952;
P_0c0c5952: /* original f35e, guest PC 0x0c0c5952 */
if(!s->budget--) { s->failed_pc=0x0c0c5952u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c0c5954;
P_0c0c5954: /* original ff37, guest PC 0x0c0c5954 */
if(!s->budget--) { s->failed_pc=0x0c0c5954u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c5956;
P_0c0c5956: /* original f3e1, guest PC 0x0c0c5956 */
if(!s->budget--) { s->failed_pc=0x0c0c5956u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'-');
goto P_0c0c5958;
P_0c0c5958: /* original f20c, guest PC 0x0c0c5958 */
if(!s->budget--) { s->failed_pc=0x0c0c5958u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0c595a;
P_0c0c595a: /* original e034, guest PC 0x0c0c595a */
if(!s->budget--) { s->failed_pc=0x0c0c595au; return 0; }
r[0]=0x00000034u;
goto P_0c0c595c;
P_0c0c595c: /* original f370, guest PC 0x0c0c595c */
if(!s->budget--) { s->failed_pc=0x0c0c595cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'+');
goto P_0c0c595e;
P_0c0c595e: /* original f233, guest PC 0x0c0c595e */
if(!s->budget--) { s->failed_pc=0x0c0c595eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'/');
goto P_0c0c5960;
P_0c0c5960: /* original f282, guest PC 0x0c0c5960 */
if(!s->budget--) { s->failed_pc=0x0c0c5960u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'*');
goto P_0c0c5962;
P_0c0c5962: /* original ff27, guest PC 0x0c0c5962 */
if(!s->budget--) { s->failed_pc=0x0c0c5962u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c5964;
P_0c0c5964: /* original e01c, guest PC 0x0c0c5964 */
if(!s->budget--) { s->failed_pc=0x0c0c5964u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c5966;
P_0c0c5966: /* original f3e6, guest PC 0x0c0c5966 */
if(!s->budget--) { s->failed_pc=0x0c0c5966u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0c5968;
P_0c0c5968: /* original 9076, guest PC 0x0c0c5968 */
if(!s->budget--) { s->failed_pc=0x0c0c5968u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a58u,2);
goto P_0c0c596a;
P_0c0c596a: /* original f363, guest PC 0x0c0c596a */
if(!s->budget--) { s->failed_pc=0x0c0c596au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'/');
goto P_0c0c596c;
P_0c0c596c: /* original ff37, guest PC 0x0c0c596c */
if(!s->budget--) { s->failed_pc=0x0c0c596cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c596e;
P_0c0c596e: /* original 9074, guest PC 0x0c0c596e */
if(!s->budget--) { s->failed_pc=0x0c0c596eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5au,2);
goto P_0c0c5970;
P_0c0c5970: /* original 8d5c, guest PC 0x0c0c5970 */
if(!s->budget--) { s->failed_pc=0x0c0c5970u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,13,r[15]+r[0]);
if(cond) { goto P_0c0c5a2c; }
goto P_0c0c5974;
P_0c0c5972: /* original fdf6, guest PC 0x0c0c5972 */
if(!s->budget--) { s->failed_pc=0x0c0c5972u; return 0; }
vf3_matrix_load(s,ram,13,r[15]+r[0]);
goto P_0c0c5974;
P_0c0c5974: /* original e014, guest PC 0x0c0c5974 */
if(!s->budget--) { s->failed_pc=0x0c0c5974u; return 0; }
r[0]=0x00000014u;
goto P_0c0c5976;
P_0c0c5976: /* original f39d, guest PC 0x0c0c5976 */
if(!s->budget--) { s->failed_pc=0x0c0c5976u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c5978;
P_0c0c5978: /* original f2f6, guest PC 0x0c0c5978 */
if(!s->budget--) { s->failed_pc=0x0c0c5978u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c597a;
P_0c0c597a: /* original f325, guest PC 0x0c0c597a */
if(!s->budget--) { s->failed_pc=0x0c0c597au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0c597c;
P_0c0c597c: /* original 8956, guest PC 0x0c0c597c */
if(!s->budget--) { s->failed_pc=0x0c0c597cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5a2c; }
goto P_0c0c597e;
P_0c0c597e: /* original c73a, guest PC 0x0c0c597e */
if(!s->budget--) { s->failed_pc=0x0c0c597eu; return 0; }
r[0]=0x0c0c5a68u;
goto P_0c0c5980;
P_0c0c5980: /* original f308, guest PC 0x0c0c5980 */
if(!s->budget--) { s->failed_pc=0x0c0c5980u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c5982;
P_0c0c5982: /* original e034, guest PC 0x0c0c5982 */
if(!s->budget--) { s->failed_pc=0x0c0c5982u; return 0; }
r[0]=0x00000034u;
goto P_0c0c5984;
P_0c0c5984: /* original f2f6, guest PC 0x0c0c5984 */
if(!s->budget--) { s->failed_pc=0x0c0c5984u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c5986;
P_0c0c5986: /* original e034, guest PC 0x0c0c5986 */
if(!s->budget--) { s->failed_pc=0x0c0c5986u; return 0; }
r[0]=0x00000034u;
goto P_0c0c5988;
P_0c0c5988: /* original f232, guest PC 0x0c0c5988 */
if(!s->budget--) { s->failed_pc=0x0c0c5988u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0c598a;
P_0c0c598a: /* original ff27, guest PC 0x0c0c598a */
if(!s->budget--) { s->failed_pc=0x0c0c598au; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c598c;
P_0c0c598c: /* original 9064, guest PC 0x0c0c598c */
if(!s->budget--) { s->failed_pc=0x0c0c598cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a58u,2);
goto P_0c0c598e;
P_0c0c598e: /* original f1f6, guest PC 0x0c0c598e */
if(!s->budget--) { s->failed_pc=0x0c0c598eu; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0c5990;
P_0c0c5990: /* original 9062, guest PC 0x0c0c5990 */
if(!s->budget--) { s->failed_pc=0x0c0c5990u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a58u,2);
goto P_0c0c5992;
P_0c0c5992: /* original f132, guest PC 0x0c0c5992 */
if(!s->budget--) { s->failed_pc=0x0c0c5992u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0c5994;
P_0c0c5994: /* original ff17, guest PC 0x0c0c5994 */
if(!s->budget--) { s->failed_pc=0x0c0c5994u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0c5996;
P_0c0c5996: /* original a045, guest PC 0x0c0c5996 */
if(!s->budget--) { s->failed_pc=0x0c0c5996u; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c0c5a24;
P_0c0c5998: /* original ffec, guest PC 0x0c0c5998 */
if(!s->budget--) { s->failed_pc=0x0c0c5998u; return 0; }
vf3_matrix_move(s,15,14);
goto P_0c0c599a;
P_0c0c599a: /* original 905e, guest PC 0x0c0c599a */
if(!s->budget--) { s->failed_pc=0x0c0c599au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5au,2);
goto P_0c0c599c;
P_0c0c599c: /* original ffd7, guest PC 0x0c0c599c */
if(!s->budget--) { s->failed_pc=0x0c0c599cu; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0c599e;
P_0c0c599e: /* original e034, guest PC 0x0c0c599e */
if(!s->budget--) { s->failed_pc=0x0c0c599eu; return 0; }
r[0]=0x00000034u;
goto P_0c0c59a0;
P_0c0c59a0: /* original f3f6, guest PC 0x0c0c59a0 */
if(!s->budget--) { s->failed_pc=0x0c0c59a0u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c59a2;
P_0c0c59a2: /* original c732, guest PC 0x0c0c59a2 */
if(!s->budget--) { s->failed_pc=0x0c0c59a2u; return 0; }
r[0]=0x0c0c5a6cu;
goto P_0c0c59a4;
P_0c0c59a4: /* original f408, guest PC 0x0c0c59a4 */
if(!s->budget--) { s->failed_pc=0x0c0c59a4u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c59a6;
P_0c0c59a6: /* original f4f5, guest PC 0x0c0c59a6 */
if(!s->budget--) { s->failed_pc=0x0c0c59a6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[15]))!=0);
goto P_0c0c59a8;
P_0c0c59a8: /* original 8d39, guest PC 0x0c0c59a8 */
if(!s->budget--) { s->failed_pc=0x0c0c59a8u; return 0; }
cond=r[17]&1u;
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'+');
if(cond) { goto P_0c0c5a1e; }
goto P_0c0c59ac;
P_0c0c59aa: /* original fd30, guest PC 0x0c0c59aa */
if(!s->budget--) { s->failed_pc=0x0c0c59aau; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'+');
goto P_0c0c59ac;
P_0c0c59ac: /* original f38d, guest PC 0x0c0c59ac */
if(!s->budget--) { s->failed_pc=0x0c0c59acu; return 0; }
fr[3]=0;
goto P_0c0c59ae;
P_0c0c59ae: /* original f3f5, guest PC 0x0c0c59ae */
if(!s->budget--) { s->failed_pc=0x0c0c59aeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0c59b0;
P_0c0c59b0: /* original 8b01, guest PC 0x0c0c59b0 */
if(!s->budget--) { s->failed_pc=0x0c0c59b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c59b6; }
goto P_0c0c59b2;
P_0c0c59b2: /* original a004, guest PC 0x0c0c59b2 */
if(!s->budget--) { s->failed_pc=0x0c0c59b2u; return 0; }
r[4]=r[12];
goto P_0c0c59be;
P_0c0c59b4: /* original 64c3, guest PC 0x0c0c59b4 */
if(!s->budget--) { s->failed_pc=0x0c0c59b4u; return 0; }
r[4]=r[12];
goto P_0c0c59b6;
P_0c0c59b6: /* original f3fc, guest PC 0x0c0c59b6 */
if(!s->budget--) { s->failed_pc=0x0c0c59b6u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0c59b8;
P_0c0c59b8: /* original f3c2, guest PC 0x0c0c59b8 */
if(!s->budget--) { s->failed_pc=0x0c0c59b8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'*');
goto P_0c0c59ba;
P_0c0c59ba: /* original f33d, guest PC 0x0c0c59ba */
if(!s->budget--) { s->failed_pc=0x0c0c59bau; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0c59bc;
P_0c0c59bc: /* original 045a, guest PC 0x0c0c59bc */
if(!s->budget--) { s->failed_pc=0x0c0c59bcu; return 0; }
r[4]=r[53];
goto P_0c0c59be;
P_0c0c59be: /* original 904d, guest PC 0x0c0c59be */
if(!s->budget--) { s->failed_pc=0x0c0c59beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5cu,2);
goto P_0c0c59c0;
P_0c0c59c0: /* original ffd7, guest PC 0x0c0c59c0 */
if(!s->budget--) { s->failed_pc=0x0c0c59c0u; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0c59c2;
P_0c0c59c2: /* original 904c, guest PC 0x0c0c59c2 */
if(!s->budget--) { s->failed_pc=0x0c0c59c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5eu,2);
goto P_0c0c59c4;
P_0c0c59c4: /* original fef6, guest PC 0x0c0c59c4 */
if(!s->budget--) { s->failed_pc=0x0c0c59c4u; return 0; }
vf3_matrix_load(s,ram,14,r[15]+r[0]);
goto P_0c0c59c6;
P_0c0c59c6: /* original 6043, guest PC 0x0c0c59c6 */
if(!s->budget--) { s->failed_pc=0x0c0c59c6u; return 0; }
r[0]=r[4];
goto P_0c0c59c8;
P_0c0c59c8: /* original 4000, guest PC 0x0c0c59c8 */
if(!s->budget--) { s->failed_pc=0x0c0c59c8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c59ca;
P_0c0c59ca: /* original 039d, guest PC 0x0c0c59ca */
if(!s->budget--) { s->failed_pc=0x0c0c59cau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[9]+r[0],2);
goto P_0c0c59cc;
P_0c0c59cc: /* original f2ec, guest PC 0x0c0c59cc */
if(!s->budget--) { s->failed_pc=0x0c0c59ccu; return 0; }
vf3_matrix_move(s,2,14);
goto P_0c0c59ce;
P_0c0c59ce: /* original 435a, guest PC 0x0c0c59ce */
if(!s->budget--) { s->failed_pc=0x0c0c59ceu; return 0; }
r[53]=r[3];
goto P_0c0c59d0;
P_0c0c59d0: /* original 9045, guest PC 0x0c0c59d0 */
if(!s->budget--) { s->failed_pc=0x0c0c59d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5eu,2);
goto P_0c0c59d2;
P_0c0c59d2: /* original f32d, guest PC 0x0c0c59d2 */
if(!s->budget--) { s->failed_pc=0x0c0c59d2u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c59d4;
P_0c0c59d4: /* original f230, guest PC 0x0c0c59d4 */
if(!s->budget--) { s->failed_pc=0x0c0c59d4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c59d6;
P_0c0c59d6: /* original ff27, guest PC 0x0c0c59d6 */
if(!s->budget--) { s->failed_pc=0x0c0c59d6u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c59d8;
P_0c0c59d8: /* original 9042, guest PC 0x0c0c59d8 */
if(!s->budget--) { s->failed_pc=0x0c0c59d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a60u,2);
goto P_0c0c59da;
P_0c0c59da: /* original fff7, guest PC 0x0c0c59da */
if(!s->budget--) { s->failed_pc=0x0c0c59dau; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0c59dc;
P_0c0c59dc: /* original 9441, guest PC 0x0c0c59dc */
if(!s->budget--) { s->failed_pc=0x0c0c59dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a62u,2);
goto P_0c0c59de;
P_0c0c59de: /* original 4d0b, guest PC 0x0c0c59de */
if(!s->budget--) { s->failed_pc=0x0c0c59deu; return 0; }
target=r[13];
r[16]=0x0c0c59e2u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c59e2u) { target=s->pc; goto dispatch; }
goto P_0c0c59e2;
P_0c0c59e0: /* original 34fc, guest PC 0x0c0c59e0 */
if(!s->budget--) { s->failed_pc=0x0c0c59e0u; return 0; }
r[4]+=r[15];
goto P_0c0c59e2;
P_0c0c59e2: /* original 903c, guest PC 0x0c0c59e2 */
if(!s->budget--) { s->failed_pc=0x0c0c59e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5eu,2);
goto P_0c0c59e4;
P_0c0c59e4: /* original f38d, guest PC 0x0c0c59e4 */
if(!s->budget--) { s->failed_pc=0x0c0c59e4u; return 0; }
fr[3]=0;
goto P_0c0c59e6;
P_0c0c59e6: /* original f2f6, guest PC 0x0c0c59e6 */
if(!s->budget--) { s->failed_pc=0x0c0c59e6u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c59e8;
P_0c0c59e8: /* original f235, guest PC 0x0c0c59e8 */
if(!s->budget--) { s->failed_pc=0x0c0c59e8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0c59ea;
P_0c0c59ea: /* original 8b05, guest PC 0x0c0c59ea */
if(!s->budget--) { s->failed_pc=0x0c0c59eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c59f8; }
goto P_0c0c59ec;
P_0c0c59ec: /* original e024, guest PC 0x0c0c59ec */
if(!s->budget--) { s->failed_pc=0x0c0c59ecu; return 0; }
r[0]=0x00000024u;
goto P_0c0c59ee;
P_0c0c59ee: /* original f3f6, guest PC 0x0c0c59ee */
if(!s->budget--) { s->failed_pc=0x0c0c59eeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c59f0;
P_0c0c59f0: /* original 9035, guest PC 0x0c0c59f0 */
if(!s->budget--) { s->failed_pc=0x0c0c59f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5eu,2);
goto P_0c0c59f2;
P_0c0c59f2: /* original f2f6, guest PC 0x0c0c59f2 */
if(!s->budget--) { s->failed_pc=0x0c0c59f2u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c59f4;
P_0c0c59f4: /* original a00c, guest PC 0x0c0c59f4 */
if(!s->budget--) { s->failed_pc=0x0c0c59f4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0c5a10;
P_0c0c59f6: /* original f231, guest PC 0x0c0c59f6 */
if(!s->budget--) { s->failed_pc=0x0c0c59f6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0c59f8;
P_0c0c59f8: /* original c71d, guest PC 0x0c0c59f8 */
if(!s->budget--) { s->failed_pc=0x0c0c59f8u; return 0; }
r[0]=0x0c0c5a70u;
goto P_0c0c59fa;
P_0c0c59fa: /* original f408, guest PC 0x0c0c59fa */
if(!s->budget--) { s->failed_pc=0x0c0c59fau; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c59fc;
P_0c0c59fc: /* original e024, guest PC 0x0c0c59fc */
if(!s->budget--) { s->failed_pc=0x0c0c59fcu; return 0; }
r[0]=0x00000024u;
goto P_0c0c59fe;
P_0c0c59fe: /* original f3f6, guest PC 0x0c0c59fe */
if(!s->budget--) { s->failed_pc=0x0c0c59feu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5a00;
P_0c0c5a00: /* original 902d, guest PC 0x0c0c5a00 */
if(!s->budget--) { s->failed_pc=0x0c0c5a00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5eu,2);
goto P_0c0c5a02;
P_0c0c5a02: /* original f2f6, guest PC 0x0c0c5a02 */
if(!s->budget--) { s->failed_pc=0x0c0c5a02u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c5a04;
P_0c0c5a04: /* original f230, guest PC 0x0c0c5a04 */
if(!s->budget--) { s->failed_pc=0x0c0c5a04u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5a06;
P_0c0c5a06: /* original f425, guest PC 0x0c0c5a06 */
if(!s->budget--) { s->failed_pc=0x0c0c5a06u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c0c5a08;
P_0c0c5a08: /* original 8b07, guest PC 0x0c0c5a08 */
if(!s->budget--) { s->failed_pc=0x0c0c5a08u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5a1a; }
goto P_0c0c5a0a;
P_0c0c5a0a: /* original 9028, guest PC 0x0c0c5a0a */
if(!s->budget--) { s->failed_pc=0x0c0c5a0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5eu,2);
goto P_0c0c5a0c;
P_0c0c5a0c: /* original f2f6, guest PC 0x0c0c5a0c */
if(!s->budget--) { s->failed_pc=0x0c0c5a0cu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c5a0e;
P_0c0c5a0e: /* original f230, guest PC 0x0c0c5a0e */
if(!s->budget--) { s->failed_pc=0x0c0c5a0eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0c5a10;
P_0c0c5a10: /* original 9025, guest PC 0x0c0c5a10 */
if(!s->budget--) { s->failed_pc=0x0c0c5a10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5eu,2);
goto P_0c0c5a12;
P_0c0c5a12: /* original ff27, guest PC 0x0c0c5a12 */
if(!s->budget--) { s->failed_pc=0x0c0c5a12u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c5a14;
P_0c0c5a14: /* original 9425, guest PC 0x0c0c5a14 */
if(!s->budget--) { s->failed_pc=0x0c0c5a14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a62u,2);
goto P_0c0c5a16;
P_0c0c5a16: /* original 4d0b, guest PC 0x0c0c5a16 */
if(!s->budget--) { s->failed_pc=0x0c0c5a16u; return 0; }
target=r[13];
r[16]=0x0c0c5a1au;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5a1au) { target=s->pc; goto dispatch; }
goto P_0c0c5a1a;
P_0c0c5a18: /* original 34fc, guest PC 0x0c0c5a18 */
if(!s->budget--) { s->failed_pc=0x0c0c5a18u; return 0; }
r[4]+=r[15];
goto P_0c0c5a1a;
P_0c0c5a1a: /* original 9020, guest PC 0x0c0c5a1a */
if(!s->budget--) { s->failed_pc=0x0c0c5a1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a5eu,2);
goto P_0c0c5a1c;
P_0c0c5a1c: /* original ffe7, guest PC 0x0c0c5a1c */
if(!s->budget--) { s->failed_pc=0x0c0c5a1cu; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c0c5a1e;
P_0c0c5a1e: /* original c712, guest PC 0x0c0c5a1e */
if(!s->budget--) { s->failed_pc=0x0c0c5a1eu; return 0; }
r[0]=0x0c0c5a68u;
goto P_0c0c5a20;
P_0c0c5a20: /* original f308, guest PC 0x0c0c5a20 */
if(!s->budget--) { s->failed_pc=0x0c0c5a20u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c5a22;
P_0c0c5a22: /* original ff30, guest PC 0x0c0c5a22 */
if(!s->budget--) { s->failed_pc=0x0c0c5a22u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c0c5a24;
P_0c0c5a24: /* original e014, guest PC 0x0c0c5a24 */
if(!s->budget--) { s->failed_pc=0x0c0c5a24u; return 0; }
r[0]=0x00000014u;
goto P_0c0c5a26;
P_0c0c5a26: /* original f3f6, guest PC 0x0c0c5a26 */
if(!s->budget--) { s->failed_pc=0x0c0c5a26u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c5a28;
P_0c0c5a28: /* original ff35, guest PC 0x0c0c5a28 */
if(!s->budget--) { s->failed_pc=0x0c0c5a28u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c0c5a2a;
P_0c0c5a2a: /* original 8bb6, guest PC 0x0c0c5a2a */
if(!s->budget--) { s->failed_pc=0x0c0c5a2au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c599a; }
goto P_0c0c5a2c;
P_0c0c5a2c: /* original 901a, guest PC 0x0c0c5a2c */
if(!s->budget--) { s->failed_pc=0x0c0c5a2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a64u,2);
goto P_0c0c5a2e;
P_0c0c5a2e: /* original e201, guest PC 0x0c0c5a2e */
if(!s->budget--) { s->failed_pc=0x0c0c5a2eu; return 0; }
r[2]=0x00000001u;
goto P_0c0c5a30;
P_0c0c5a30: /* original 03fe, guest PC 0x0c0c5a30 */
if(!s->budget--) { s->failed_pc=0x0c0c5a30u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0c5a32;
P_0c0c5a32: /* original e022, guest PC 0x0c0c5a32 */
if(!s->budget--) { s->failed_pc=0x0c0c5a32u; return 0; }
r[0]=0x00000022u;
goto P_0c0c5a34;
P_0c0c5a34: /* original 013d, guest PC 0x0c0c5a34 */
if(!s->budget--) { s->failed_pc=0x0c0c5a34u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c5a36;
P_0c0c5a36: /* original 212b, guest PC 0x0c0c5a36 */
if(!s->budget--) { s->failed_pc=0x0c0c5a36u; return 0; }
r[1]|=r[2];
goto P_0c0c5a38;
P_0c0c5a38: /* original 0315, guest PC 0x0c0c5a38 */
if(!s->budget--) { s->failed_pc=0x0c0c5a38u; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c0c5a3a;
P_0c0c5a3a: /* original 9114, guest PC 0x0c0c5a3a */
if(!s->budget--) { s->failed_pc=0x0c0c5a3au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5a66u,2);
goto P_0c0c5a3c;
P_0c0c5a3c: /* original 3f1c, guest PC 0x0c0c5a3c */
if(!s->budget--) { s->failed_pc=0x0c0c5a3cu; return 0; }
r[15]+=r[1];
goto P_0c0c5a3e;
P_0c0c5a3e: /* original 4f26, guest PC 0x0c0c5a3e */
if(!s->budget--) { s->failed_pc=0x0c0c5a3eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5a40;
P_0c0c5a40: /* original fcf9, guest PC 0x0c0c5a40 */
if(!s->budget--) { s->failed_pc=0x0c0c5a40u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c5a42;
P_0c0c5a42: /* original fdf9, guest PC 0x0c0c5a42 */
if(!s->budget--) { s->failed_pc=0x0c0c5a42u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c5a44;
P_0c0c5a44: /* original fef9, guest PC 0x0c0c5a44 */
if(!s->budget--) { s->failed_pc=0x0c0c5a44u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c5a46;
P_0c0c5a46: /* original fff9, guest PC 0x0c0c5a46 */
if(!s->budget--) { s->failed_pc=0x0c0c5a46u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c5a48;
P_0c0c5a48: /* original 68f6, guest PC 0x0c0c5a48 */
if(!s->budget--) { s->failed_pc=0x0c0c5a48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c5a4a;
P_0c0c5a4a: /* original 69f6, guest PC 0x0c0c5a4a */
if(!s->budget--) { s->failed_pc=0x0c0c5a4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c5a4c;
P_0c0c5a4c: /* original 6af6, guest PC 0x0c0c5a4c */
if(!s->budget--) { s->failed_pc=0x0c0c5a4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c5a4e;
P_0c0c5a4e: /* original 6bf6, guest PC 0x0c0c5a4e */
if(!s->budget--) { s->failed_pc=0x0c0c5a4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c5a50;
P_0c0c5a50: /* original 6cf6, guest PC 0x0c0c5a50 */
if(!s->budget--) { s->failed_pc=0x0c0c5a50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c5a52;
P_0c0c5a52: /* original 6df6, guest PC 0x0c0c5a52 */
if(!s->budget--) { s->failed_pc=0x0c0c5a52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5a54;
P_0c0c5a54: /* original 000b, guest PC 0x0c0c5a54 */
if(!s->budget--) { s->failed_pc=0x0c0c5a54u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5a56: /* original 6ef6, guest PC 0x0c0c5a56 */
if(!s->budget--) { s->failed_pc=0x0c0c5a56u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c5a58u,s,ram);
P_0c0c8b50: /* original 2fe6, guest PC 0x0c0c8b50 */
if(!s->budget--) { s->failed_pc=0x0c0c8b50u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c8b52;
P_0c0c8b52: /* original 4f22, guest PC 0x0c0c8b52 */
if(!s->budget--) { s->failed_pc=0x0c0c8b52u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c8b54;
P_0c0c8b54: /* original d31e, guest PC 0x0c0c8b54 */
if(!s->budget--) { s->failed_pc=0x0c0c8b54u; return 0; }
r[3]=read(ram,0x0c0c8bd0u,4);
goto P_0c0c8b56;
P_0c0c8b56: /* original 430b, guest PC 0x0c0c8b56 */
if(!s->budget--) { s->failed_pc=0x0c0c8b56u; return 0; }
target=r[3];
r[16]=0x0c0c8b5au;
r[14]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8b5au) { target=s->pc; goto dispatch; }
goto P_0c0c8b5a;
P_0c0c8b58: /* original 6e43, guest PC 0x0c0c8b58 */
if(!s->budget--) { s->failed_pc=0x0c0c8b58u; return 0; }
r[14]=r[4];
goto P_0c0c8b5a;
P_0c0c8b5a: /* original d51e, guest PC 0x0c0c8b5a */
if(!s->budget--) { s->failed_pc=0x0c0c8b5au; return 0; }
r[5]=read(ram,0x0c0c8bd4u,4);
goto P_0c0c8b5c;
P_0c0c8b5c: /* original e201, guest PC 0x0c0c8b5c */
if(!s->budget--) { s->failed_pc=0x0c0c8b5cu; return 0; }
r[2]=0x00000001u;
goto P_0c0c8b5e;
P_0c0c8b5e: /* original 6603, guest PC 0x0c0c8b5e */
if(!s->budget--) { s->failed_pc=0x0c0c8b5eu; return 0; }
r[6]=r[0];
goto P_0c0c8b60;
P_0c0c8b60: /* original 2628, guest PC 0x0c0c8b60 */
if(!s->budget--) { s->failed_pc=0x0c0c8b60u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[2])==0)!=0);
goto P_0c0c8b62;
P_0c0c8b62: /* original 5454, guest PC 0x0c0c8b62 */
if(!s->budget--) { s->failed_pc=0x0c0c8b62u; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c0c8b64;
P_0c0c8b64: /* original 8f03, guest PC 0x0c0c8b64 */
if(!s->budget--) { s->failed_pc=0x0c0c8b64u; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[5]+20,4);
if(!cond) { goto P_0c0c8b6e; }
goto P_0c0c8b68;
P_0c0c8b66: /* original 5555, guest PC 0x0c0c8b66 */
if(!s->budget--) { s->failed_pc=0x0c0c8b66u; return 0; }
r[5]=read(ram,r[5]+20,4);
goto P_0c0c8b68;
P_0c0c8b68: /* original 6643, guest PC 0x0c0c8b68 */
if(!s->budget--) { s->failed_pc=0x0c0c8b68u; return 0; }
r[6]=r[4];
goto P_0c0c8b6a;
P_0c0c8b6a: /* original 6453, guest PC 0x0c0c8b6a */
if(!s->budget--) { s->failed_pc=0x0c0c8b6au; return 0; }
r[4]=r[5];
goto P_0c0c8b6c;
P_0c0c8b6c: /* original 6563, guest PC 0x0c0c8b6c */
if(!s->budget--) { s->failed_pc=0x0c0c8b6cu; return 0; }
r[5]=r[6];
goto P_0c0c8b6e;
P_0c0c8b6e: /* original 901e, guest PC 0x0c0c8b6e */
if(!s->budget--) { s->failed_pc=0x0c0c8b6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8baeu,2);
goto P_0c0c8b70;
P_0c0c8b70: /* original 4f26, guest PC 0x0c0c8b70 */
if(!s->budget--) { s->failed_pc=0x0c0c8b70u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c8b72;
P_0c0c8b72: /* original 0e46, guest PC 0x0c0c8b72 */
if(!s->budget--) { s->failed_pc=0x0c0c8b72u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c8b74;
P_0c0c8b74: /* original 7004, guest PC 0x0c0c8b74 */
if(!s->budget--) { s->failed_pc=0x0c0c8b74u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c8b76;
P_0c0c8b76: /* original 0e56, guest PC 0x0c0c8b76 */
if(!s->budget--) { s->failed_pc=0x0c0c8b76u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c0c8b78;
P_0c0c8b78: /* original 70f8, guest PC 0x0c0c8b78 */
if(!s->budget--) { s->failed_pc=0x0c0c8b78u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c8b7a;
P_0c0c8b7a: /* original 6742, guest PC 0x0c0c8b7a */
if(!s->budget--) { s->failed_pc=0x0c0c8b7au; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c0c8b7c;
P_0c0c8b7c: /* original d316, guest PC 0x0c0c8b7c */
if(!s->budget--) { s->failed_pc=0x0c0c8b7cu; return 0; }
r[3]=read(ram,0x0c0c8bd8u,4);
goto P_0c0c8b7e;
P_0c0c8b7e: /* original d217, guest PC 0x0c0c8b7e */
if(!s->budget--) { s->failed_pc=0x0c0c8b7eu; return 0; }
r[2]=read(ram,0x0c0c8bdcu,4);
goto P_0c0c8b80;
P_0c0c8b80: /* original 273b, guest PC 0x0c0c8b80 */
if(!s->budget--) { s->failed_pc=0x0c0c8b80u; return 0; }
r[7]|=r[3];
goto P_0c0c8b82;
P_0c0c8b82: /* original 6652, guest PC 0x0c0c8b82 */
if(!s->budget--) { s->failed_pc=0x0c0c8b82u; return 0; }
tmp=read(ram,r[5],4);
r[6]=tmp;
goto P_0c0c8b84;
P_0c0c8b84: /* original 2472, guest PC 0x0c0c8b84 */
if(!s->budget--) { s->failed_pc=0x0c0c8b84u; return 0; }
write(ram,r[4],r[7],4);
goto P_0c0c8b86;
P_0c0c8b86: /* original e301, guest PC 0x0c0c8b86 */
if(!s->budget--) { s->failed_pc=0x0c0c8b86u; return 0; }
r[3]=0x00000001u;
goto P_0c0c8b88;
P_0c0c8b88: /* original 2629, guest PC 0x0c0c8b88 */
if(!s->budget--) { s->failed_pc=0x0c0c8b88u; return 0; }
r[6]&=r[2];
goto P_0c0c8b8a;
P_0c0c8b8a: /* original e207, guest PC 0x0c0c8b8a */
if(!s->budget--) { s->failed_pc=0x0c0c8b8au; return 0; }
r[2]=0x00000007u;
goto P_0c0c8b8c;
P_0c0c8b8c: /* original 2562, guest PC 0x0c0c8b8c */
if(!s->budget--) { s->failed_pc=0x0c0c8b8cu; return 0; }
write(ram,r[5],r[6],4);
goto P_0c0c8b8e;
P_0c0c8b8e: /* original 64e2, guest PC 0x0c0c8b8e */
if(!s->budget--) { s->failed_pc=0x0c0c8b8eu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0c8b90;
P_0c0c8b90: /* original d113, guest PC 0x0c0c8b90 */
if(!s->budget--) { s->failed_pc=0x0c0c8b90u; return 0; }
r[1]=read(ram,0x0c0c8be0u,4);
goto P_0c0c8b92;
P_0c0c8b92: /* original 241b, guest PC 0x0c0c8b92 */
if(!s->budget--) { s->failed_pc=0x0c0c8b92u; return 0; }
r[4]|=r[1];
goto P_0c0c8b94;
P_0c0c8b94: /* original 2e42, guest PC 0x0c0c8b94 */
if(!s->budget--) { s->failed_pc=0x0c0c8b94u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0c8b96;
P_0c0c8b96: /* original 64e3, guest PC 0x0c0c8b96 */
if(!s->budget--) { s->failed_pc=0x0c0c8b96u; return 0; }
r[4]=r[14];
goto P_0c0c8b98;
P_0c0c8b98: /* original 0e34, guest PC 0x0c0c8b98 */
if(!s->budget--) { s->failed_pc=0x0c0c8b98u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c8b9a;
P_0c0c8b9a: /* original 9009, guest PC 0x0c0c8b9a */
if(!s->budget--) { s->failed_pc=0x0c0c8b9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8bb0u,2);
goto P_0c0c8b9c;
P_0c0c8b9c: /* original 0e24, guest PC 0x0c0c8b9c */
if(!s->budget--) { s->failed_pc=0x0c0c8b9cu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0c8b9e;
P_0c0c8b9e: /* original a021, guest PC 0x0c0c8b9e */
if(!s->budget--) { s->failed_pc=0x0c0c8b9eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c8be4;
P_0c0c8ba0: /* original 6ef6, guest PC 0x0c0c8ba0 */
if(!s->budget--) { s->failed_pc=0x0c0c8ba0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c8ba2u,s,ram);
P_0c0c8be4: /* original d13d, guest PC 0x0c0c8be4 */
if(!s->budget--) { s->failed_pc=0x0c0c8be4u; return 0; }
r[1]=read(ram,0x0c0c8cdcu,4);
goto P_0c0c8be6;
P_0c0c8be6: /* original 4f22, guest PC 0x0c0c8be6 */
if(!s->budget--) { s->failed_pc=0x0c0c8be6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c8be8;
P_0c0c8be8: /* original 6212, guest PC 0x0c0c8be8 */
if(!s->budget--) { s->failed_pc=0x0c0c8be8u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0c8bea;
P_0c0c8bea: /* original d33b, guest PC 0x0c0c8bea */
if(!s->budget--) { s->failed_pc=0x0c0c8beau; return 0; }
r[3]=read(ram,0x0c0c8cd8u,4);
goto P_0c0c8bec;
P_0c0c8bec: /* original d539, guest PC 0x0c0c8bec */
if(!s->budget--) { s->failed_pc=0x0c0c8becu; return 0; }
r[5]=read(ram,0x0c0c8cd4u,4);
goto P_0c0c8bee;
P_0c0c8bee: /* original 7ff0, guest PC 0x0c0c8bee */
if(!s->budget--) { s->failed_pc=0x0c0c8beeu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0c8bf0;
P_0c0c8bf0: /* original 2238, guest PC 0x0c0c8bf0 */
if(!s->budget--) { s->failed_pc=0x0c0c8bf0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c8bf2;
P_0c0c8bf2: /* original 8b2f, guest PC 0x0c0c8bf2 */
if(!s->budget--) { s->failed_pc=0x0c0c8bf2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8c54; }
goto P_0c0c8bf4;
P_0c0c8bf4: /* original 9069, guest PC 0x0c0c8bf4 */
if(!s->budget--) { s->failed_pc=0x0c0c8bf4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8ccau,2);
goto P_0c0c8bf6;
P_0c0c8bf6: /* original 004e, guest PC 0x0c0c8bf6 */
if(!s->budget--) { s->failed_pc=0x0c0c8bf6u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c0c8bf8;
P_0c0c8bf8: /* original 1f02, guest PC 0x0c0c8bf8 */
if(!s->budget--) { s->failed_pc=0x0c0c8bf8u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c0c8bfa;
P_0c0c8bfa: /* original 9067, guest PC 0x0c0c8bfa */
if(!s->budget--) { s->failed_pc=0x0c0c8bfau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8cccu,2);
goto P_0c0c8bfc;
P_0c0c8bfc: /* original 034e, guest PC 0x0c0c8bfc */
if(!s->budget--) { s->failed_pc=0x0c0c8bfcu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0c8bfe;
P_0c0c8bfe: /* original 1f33, guest PC 0x0c0c8bfe */
if(!s->budget--) { s->failed_pc=0x0c0c8bfeu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0c8c00;
P_0c0c8c00: /* original 9065, guest PC 0x0c0c8c00 */
if(!s->budget--) { s->failed_pc=0x0c0c8c00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8cceu,2);
goto P_0c0c8c02;
P_0c0c8c02: /* original 024c, guest PC 0x0c0c8c02 */
if(!s->budget--) { s->failed_pc=0x0c0c8c02u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c8c04;
P_0c0c8c04: /* original 2f22, guest PC 0x0c0c8c04 */
if(!s->budget--) { s->failed_pc=0x0c0c8c04u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c8c06;
P_0c0c8c06: /* original 6342, guest PC 0x0c0c8c06 */
if(!s->budget--) { s->failed_pc=0x0c0c8c06u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0c8c08;
P_0c0c8c08: /* original 1f31, guest PC 0x0c0c8c08 */
if(!s->budget--) { s->failed_pc=0x0c0c8c08u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c8c0a;
P_0c0c8c0a: /* original 5553, guest PC 0x0c0c8c0a */
if(!s->budget--) { s->failed_pc=0x0c0c8c0au; return 0; }
r[5]=read(ram,r[5]+12,4);
goto P_0c0c8c0c;
P_0c0c8c0c: /* original 655c, guest PC 0x0c0c8c0c */
if(!s->budget--) { s->failed_pc=0x0c0c8c0cu; return 0; }
r[5]=r[5]&255u;
goto P_0c0c8c0e;
P_0c0c8c0e: /* original 2558, guest PC 0x0c0c8c0e */
if(!s->budget--) { s->failed_pc=0x0c0c8c0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0c8c10;
P_0c0c8c10: /* original 8b17, guest PC 0x0c0c8c10 */
if(!s->budget--) { s->failed_pc=0x0c0c8c10u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8c42; }
goto P_0c0c8c12;
P_0c0c8c12: /* original 63f2, guest PC 0x0c0c8c12 */
if(!s->budget--) { s->failed_pc=0x0c0c8c12u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c8c14;
P_0c0c8c14: /* original 7301, guest PC 0x0c0c8c14 */
if(!s->budget--) { s->failed_pc=0x0c0c8c14u; return 0; }
r[3]+=0x00000001u;
goto P_0c0c8c16;
P_0c0c8c16: /* original 2f32, guest PC 0x0c0c8c16 */
if(!s->budget--) { s->failed_pc=0x0c0c8c16u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c8c18;
P_0c0c8c18: /* original e304, guest PC 0x0c0c8c18 */
if(!s->budget--) { s->failed_pc=0x0c0c8c18u; return 0; }
r[3]=0x00000004u;
goto P_0c0c8c1a;
P_0c0c8c1a: /* original d231, guest PC 0x0c0c8c1a */
if(!s->budget--) { s->failed_pc=0x0c0c8c1au; return 0; }
r[2]=read(ram,0x0c0c8ce0u,4);
goto P_0c0c8c1c;
P_0c0c8c1c: /* original 51f1, guest PC 0x0c0c8c1c */
if(!s->budget--) { s->failed_pc=0x0c0c8c1cu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0c8c1e;
P_0c0c8c1e: /* original 2129, guest PC 0x0c0c8c1e */
if(!s->budget--) { s->failed_pc=0x0c0c8c1eu; return 0; }
r[1]&=r[2];
goto P_0c0c8c20;
P_0c0c8c20: /* original 1f11, guest PC 0x0c0c8c20 */
if(!s->budget--) { s->failed_pc=0x0c0c8c20u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0c8c22;
P_0c0c8c22: /* original 60f2, guest PC 0x0c0c8c22 */
if(!s->budget--) { s->failed_pc=0x0c0c8c22u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0c8c24;
P_0c0c8c24: /* original 3033, guest PC 0x0c0c8c24 */
if(!s->budget--) { s->failed_pc=0x0c0c8c24u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[3])!=0);
goto P_0c0c8c26;
P_0c0c8c26: /* original 8b09, guest PC 0x0c0c8c26 */
if(!s->budget--) { s->failed_pc=0x0c0c8c26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8c3c; }
goto P_0c0c8c28;
P_0c0c8c28: /* original 9052, guest PC 0x0c0c8c28 */
if(!s->budget--) { s->failed_pc=0x0c0c8c28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8cd0u,2);
goto P_0c0c8c2a;
P_0c0c8c2a: /* original e102, guest PC 0x0c0c8c2a */
if(!s->budget--) { s->failed_pc=0x0c0c8c2au; return 0; }
r[1]=0x00000002u;
goto P_0c0c8c2c;
P_0c0c8c2c: /* original e300, guest PC 0x0c0c8c2c */
if(!s->budget--) { s->failed_pc=0x0c0c8c2cu; return 0; }
r[3]=0x00000000u;
goto P_0c0c8c2e;
P_0c0c8c2e: /* original 0414, guest PC 0x0c0c8c2e */
if(!s->budget--) { s->failed_pc=0x0c0c8c2eu; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c0c8c30;
P_0c0c8c30: /* original 904d, guest PC 0x0c0c8c30 */
if(!s->budget--) { s->failed_pc=0x0c0c8c30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8cceu,2);
goto P_0c0c8c32;
P_0c0c8c32: /* original 0434, guest PC 0x0c0c8c32 */
if(!s->budget--) { s->failed_pc=0x0c0c8c32u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c0c8c34;
P_0c0c8c34: /* original 62f2, guest PC 0x0c0c8c34 */
if(!s->budget--) { s->failed_pc=0x0c0c8c34u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c8c36;
P_0c0c8c36: /* original 72ff, guest PC 0x0c0c8c36 */
if(!s->budget--) { s->failed_pc=0x0c0c8c36u; return 0; }
r[2]+=0xffffffffu;
goto P_0c0c8c38;
P_0c0c8c38: /* original a003, guest PC 0x0c0c8c38 */
if(!s->budget--) { s->failed_pc=0x0c0c8c38u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c8c42;
P_0c0c8c3a: /* original 2f22, guest PC 0x0c0c8c3a */
if(!s->budget--) { s->failed_pc=0x0c0c8c3au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c8c3c;
P_0c0c8c3c: /* original 9047, guest PC 0x0c0c8c3c */
if(!s->budget--) { s->failed_pc=0x0c0c8c3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8cceu,2);
goto P_0c0c8c3e;
P_0c0c8c3e: /* original 61f2, guest PC 0x0c0c8c3e */
if(!s->budget--) { s->failed_pc=0x0c0c8c3eu; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0c8c40;
P_0c0c8c40: /* original 0414, guest PC 0x0c0c8c40 */
if(!s->budget--) { s->failed_pc=0x0c0c8c40u; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c0c8c42;
P_0c0c8c42: /* original 63f3, guest PC 0x0c0c8c42 */
if(!s->budget--) { s->failed_pc=0x0c0c8c42u; return 0; }
r[3]=r[15];
goto P_0c0c8c44;
P_0c0c8c44: /* original 7304, guest PC 0x0c0c8c44 */
if(!s->budget--) { s->failed_pc=0x0c0c8c44u; return 0; }
r[3]+=0x00000004u;
goto P_0c0c8c46;
P_0c0c8c46: /* original 2f36, guest PC 0x0c0c8c46 */
if(!s->budget--) { s->failed_pc=0x0c0c8c46u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0c8c48;
P_0c0c8c48: /* original 56f4, guest PC 0x0c0c8c48 */
if(!s->budget--) { s->failed_pc=0x0c0c8c48u; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c0c8c4a;
P_0c0c8c4a: /* original 67f3, guest PC 0x0c0c8c4a */
if(!s->budget--) { s->failed_pc=0x0c0c8c4au; return 0; }
r[7]=r[15];
goto P_0c0c8c4c;
P_0c0c8c4c: /* original 7704, guest PC 0x0c0c8c4c */
if(!s->budget--) { s->failed_pc=0x0c0c8c4cu; return 0; }
r[7]+=0x00000004u;
goto P_0c0c8c4e;
P_0c0c8c4e: /* original bd44, guest PC 0x0c0c8c4e */
if(!s->budget--) { s->failed_pc=0x0c0c8c4eu; return 0; }
target=0x0c0c86dau; r[16]=0x0c0c8c52u;
r[5]=read(ram,r[15]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8c52u) { target=s->pc; goto dispatch; }
goto P_0c0c8c52;
P_0c0c8c50: /* original 55f3, guest PC 0x0c0c8c50 */
if(!s->budget--) { s->failed_pc=0x0c0c8c50u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c0c8c52;
P_0c0c8c52: /* original 7f04, guest PC 0x0c0c8c52 */
if(!s->budget--) { s->failed_pc=0x0c0c8c52u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c8c54;
P_0c0c8c54: /* original 7f10, guest PC 0x0c0c8c54 */
if(!s->budget--) { s->failed_pc=0x0c0c8c54u; return 0; }
r[15]+=0x00000010u;
goto P_0c0c8c56;
P_0c0c8c56: /* original 4f26, guest PC 0x0c0c8c56 */
if(!s->budget--) { s->failed_pc=0x0c0c8c56u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c8c58;
P_0c0c8c58: /* original 000b, guest PC 0x0c0c8c58 */
if(!s->budget--) { s->failed_pc=0x0c0c8c58u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c8c5a: /* original 0009, guest PC 0x0c0c8c5a */
if(!s->budget--) { s->failed_pc=0x0c0c8c5au; return 0; }
return vf3_matrix_family(0x0c0c8c5cu,s,ram);
P_0c0cc4dc: /* original 2fe6, guest PC 0x0c0cc4dc */
if(!s->budget--) { s->failed_pc=0x0c0cc4dcu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0cc4de;
P_0c0cc4de: /* original 6543, guest PC 0x0c0cc4de */
if(!s->budget--) { s->failed_pc=0x0c0cc4deu; return 0; }
r[5]=r[4];
goto P_0c0cc4e0;
P_0c0cc4e0: /* original 2fd6, guest PC 0x0c0cc4e0 */
if(!s->budget--) { s->failed_pc=0x0c0cc4e0u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0cc4e2;
P_0c0cc4e2: /* original 2fc6, guest PC 0x0c0cc4e2 */
if(!s->budget--) { s->failed_pc=0x0c0cc4e2u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0cc4e4;
P_0c0cc4e4: /* original 2fb6, guest PC 0x0c0cc4e4 */
if(!s->budget--) { s->failed_pc=0x0c0cc4e4u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0cc4e6;
P_0c0cc4e6: /* original 2fa6, guest PC 0x0c0cc4e6 */
if(!s->budget--) { s->failed_pc=0x0c0cc4e6u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0cc4e8;
P_0c0cc4e8: /* original 5d5d, guest PC 0x0c0cc4e8 */
if(!s->budget--) { s->failed_pc=0x0c0cc4e8u; return 0; }
r[13]=read(ram,r[5]+52,4);
goto P_0c0cc4ea;
P_0c0cc4ea: /* original 4f22, guest PC 0x0c0cc4ea */
if(!s->budget--) { s->failed_pc=0x0c0cc4eau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cc4ec;
P_0c0cc4ec: /* original 9e28, guest PC 0x0c0cc4ec */
if(!s->budget--) { s->failed_pc=0x0c0cc4ecu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc540u,2);
goto P_0c0cc4ee;
P_0c0cc4ee: /* original 2dd8, guest PC 0x0c0cc4ee */
if(!s->budget--) { s->failed_pc=0x0c0cc4eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0cc4f0;
P_0c0cc4f0: /* original 8d1f, guest PC 0x0c0cc4f0 */
if(!s->budget--) { s->failed_pc=0x0c0cc4f0u; return 0; }
cond=r[17]&1u;
r[14]+=r[4];
if(cond) { goto P_0c0cc532; }
goto P_0c0cc4f4;
P_0c0cc4f2: /* original 3e4c, guest PC 0x0c0cc4f2 */
if(!s->budget--) { s->failed_pc=0x0c0cc4f2u; return 0; }
r[14]+=r[4];
goto P_0c0cc4f4;
P_0c0cc4f4: /* original d215, guest PC 0x0c0cc4f4 */
if(!s->budget--) { s->failed_pc=0x0c0cc4f4u; return 0; }
r[2]=read(ram,0x0c0cc54cu,4);
goto P_0c0cc4f6;
P_0c0cc4f6: /* original 420b, guest PC 0x0c0cc4f6 */
if(!s->budget--) { s->failed_pc=0x0c0cc4f6u; return 0; }
target=r[2];
r[16]=0x0c0cc4fau;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cc4fau) { target=s->pc; goto dispatch; }
goto P_0c0cc4fa;
P_0c0cc4f8: /* original e400, guest PC 0x0c0cc4f8 */
if(!s->budget--) { s->failed_pc=0x0c0cc4f8u; return 0; }
r[4]=0x00000000u;
goto P_0c0cc4fa;
P_0c0cc4fa: /* original d315, guest PC 0x0c0cc4fa */
if(!s->budget--) { s->failed_pc=0x0c0cc4fau; return 0; }
r[3]=read(ram,0x0c0cc550u,4);
goto P_0c0cc4fc;
P_0c0cc4fc: /* original 430b, guest PC 0x0c0cc4fc */
if(!s->budget--) { s->failed_pc=0x0c0cc4fcu; return 0; }
target=r[3];
r[16]=0x0c0cc500u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cc500u) { target=s->pc; goto dispatch; }
goto P_0c0cc500;
P_0c0cc4fe: /* original 0009, guest PC 0x0c0cc4fe */
if(!s->budget--) { s->failed_pc=0x0c0cc4feu; return 0; }
goto P_0c0cc500;
P_0c0cc500: /* original db15, guest PC 0x0c0cc500 */
if(!s->budget--) { s->failed_pc=0x0c0cc500u; return 0; }
r[11]=read(ram,0x0c0cc558u,4);
goto P_0c0cc502;
P_0c0cc502: /* original da14, guest PC 0x0c0cc502 */
if(!s->budget--) { s->failed_pc=0x0c0cc502u; return 0; }
r[10]=read(ram,0x0c0cc554u,4);
goto P_0c0cc504;
P_0c0cc504: /* original a00a, guest PC 0x0c0cc504 */
if(!s->budget--) { s->failed_pc=0x0c0cc504u; return 0; }
r[12]=0x00000001u;
goto P_0c0cc51c;
P_0c0cc506: /* original ec01, guest PC 0x0c0cc506 */
if(!s->budget--) { s->failed_pc=0x0c0cc506u; return 0; }
r[12]=0x00000001u;
goto P_0c0cc508;
P_0c0cc508: /* original 85ed, guest PC 0x0c0cc508 */
if(!s->budget--) { s->failed_pc=0x0c0cc508u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+26,2);
goto P_0c0cc50a;
P_0c0cc50a: /* original 20c8, guest PC 0x0c0cc50a */
if(!s->budget--) { s->failed_pc=0x0c0cc50au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[12])==0)!=0);
goto P_0c0cc50c;
P_0c0cc50c: /* original 8904, guest PC 0x0c0cc50c */
if(!s->budget--) { s->failed_pc=0x0c0cc50cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc518; }
goto P_0c0cc50e;
P_0c0cc50e: /* original 4a0b, guest PC 0x0c0cc50e */
if(!s->budget--) { s->failed_pc=0x0c0cc50eu; return 0; }
target=r[10];
r[16]=0x0c0cc512u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cc512u) { target=s->pc; goto dispatch; }
goto P_0c0cc512;
P_0c0cc510: /* original 64e3, guest PC 0x0c0cc510 */
if(!s->budget--) { s->failed_pc=0x0c0cc510u; return 0; }
r[4]=r[14];
goto P_0c0cc512;
P_0c0cc512: /* original 85ee, guest PC 0x0c0cc512 */
if(!s->budget--) { s->failed_pc=0x0c0cc512u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c0cc514;
P_0c0cc514: /* original 4b0b, guest PC 0x0c0cc514 */
if(!s->budget--) { s->failed_pc=0x0c0cc514u; return 0; }
target=r[11];
r[16]=0x0c0cc518u;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cc518u) { target=s->pc; goto dispatch; }
goto P_0c0cc518;
P_0c0cc516: /* original 6403, guest PC 0x0c0cc516 */
if(!s->budget--) { s->failed_pc=0x0c0cc516u; return 0; }
r[4]=r[0];
goto P_0c0cc518;
P_0c0cc518: /* original 7dff, guest PC 0x0c0cc518 */
if(!s->budget--) { s->failed_pc=0x0c0cc518u; return 0; }
r[13]+=0xffffffffu;
goto P_0c0cc51a;
P_0c0cc51a: /* original 7e20, guest PC 0x0c0cc51a */
if(!s->budget--) { s->failed_pc=0x0c0cc51au; return 0; }
r[14]+=0x00000020u;
goto P_0c0cc51c;
P_0c0cc51c: /* original 2dd8, guest PC 0x0c0cc51c */
if(!s->budget--) { s->failed_pc=0x0c0cc51cu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0cc51e;
P_0c0cc51e: /* original 8bf3, guest PC 0x0c0cc51e */
if(!s->budget--) { s->failed_pc=0x0c0cc51eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc508; }
goto P_0c0cc520;
P_0c0cc520: /* original 4f26, guest PC 0x0c0cc520 */
if(!s->budget--) { s->failed_pc=0x0c0cc520u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cc522;
P_0c0cc522: /* original d20e, guest PC 0x0c0cc522 */
if(!s->budget--) { s->failed_pc=0x0c0cc522u; return 0; }
r[2]=read(ram,0x0c0cc55cu,4);
goto P_0c0cc524;
P_0c0cc524: /* original e401, guest PC 0x0c0cc524 */
if(!s->budget--) { s->failed_pc=0x0c0cc524u; return 0; }
r[4]=0x00000001u;
goto P_0c0cc526;
P_0c0cc526: /* original 6af6, guest PC 0x0c0cc526 */
if(!s->budget--) { s->failed_pc=0x0c0cc526u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cc528;
P_0c0cc528: /* original 6bf6, guest PC 0x0c0cc528 */
if(!s->budget--) { s->failed_pc=0x0c0cc528u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cc52a;
P_0c0cc52a: /* original 6cf6, guest PC 0x0c0cc52a */
if(!s->budget--) { s->failed_pc=0x0c0cc52au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cc52c;
P_0c0cc52c: /* original 6df6, guest PC 0x0c0cc52c */
if(!s->budget--) { s->failed_pc=0x0c0cc52cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cc52e;
P_0c0cc52e: /* original 422b, guest PC 0x0c0cc52e */
if(!s->budget--) { s->failed_pc=0x0c0cc52eu; return 0; }
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
P_0c0cc530: /* original 6ef6, guest PC 0x0c0cc530 */
if(!s->budget--) { s->failed_pc=0x0c0cc530u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0cc532;
P_0c0cc532: /* original 4f26, guest PC 0x0c0cc532 */
if(!s->budget--) { s->failed_pc=0x0c0cc532u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cc534;
P_0c0cc534: /* original 6af6, guest PC 0x0c0cc534 */
if(!s->budget--) { s->failed_pc=0x0c0cc534u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cc536;
P_0c0cc536: /* original 6bf6, guest PC 0x0c0cc536 */
if(!s->budget--) { s->failed_pc=0x0c0cc536u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cc538;
P_0c0cc538: /* original 6cf6, guest PC 0x0c0cc538 */
if(!s->budget--) { s->failed_pc=0x0c0cc538u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cc53a;
P_0c0cc53a: /* original 6df6, guest PC 0x0c0cc53a */
if(!s->budget--) { s->failed_pc=0x0c0cc53au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cc53c;
P_0c0cc53c: /* original 000b, guest PC 0x0c0cc53c */
if(!s->budget--) { s->failed_pc=0x0c0cc53cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cc53e: /* original 6ef6, guest PC 0x0c0cc53e */
if(!s->budget--) { s->failed_pc=0x0c0cc53eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0cc540u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
