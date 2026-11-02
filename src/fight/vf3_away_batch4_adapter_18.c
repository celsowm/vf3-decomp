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
int vf3_away_batch4_adapter_18(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04d95eu: goto P_0c04d95e;
case 0x0c04d960u: goto P_0c04d960;
case 0x0c04d962u: goto P_0c04d962;
case 0x0c04d964u: goto P_0c04d964;
case 0x0c04d966u: goto P_0c04d966;
case 0x0c04d968u: goto P_0c04d968;
case 0x0c04d96au: goto P_0c04d96a;
case 0x0c04d96cu: goto P_0c04d96c;
case 0x0c04d96eu: goto P_0c04d96e;
case 0x0c04d970u: goto P_0c04d970;
case 0x0c04d972u: goto P_0c04d972;
case 0x0c04d974u: goto P_0c04d974;
case 0x0c04d976u: goto P_0c04d976;
case 0x0c04d978u: goto P_0c04d978;
case 0x0c04d97au: goto P_0c04d97a;
case 0x0c04d97cu: goto P_0c04d97c;
case 0x0c04d97eu: goto P_0c04d97e;
case 0x0c04d980u: goto P_0c04d980;
case 0x0c04d982u: goto P_0c04d982;
case 0x0c04d984u: goto P_0c04d984;
case 0x0c04d986u: goto P_0c04d986;
case 0x0c04d988u: goto P_0c04d988;
case 0x0c04d98au: goto P_0c04d98a;
case 0x0c04d98cu: goto P_0c04d98c;
case 0x0c04d98eu: goto P_0c04d98e;
case 0x0c04d990u: goto P_0c04d990;
case 0x0c04d992u: goto P_0c04d992;
case 0x0c04d994u: goto P_0c04d994;
case 0x0c04d996u: goto P_0c04d996;
case 0x0c04d998u: goto P_0c04d998;
case 0x0c04d99au: goto P_0c04d99a;
case 0x0c04d99cu: goto P_0c04d99c;
case 0x0c04d99eu: goto P_0c04d99e;
case 0x0c04d9a0u: goto P_0c04d9a0;
case 0x0c04d9a2u: goto P_0c04d9a2;
case 0x0c04d9a4u: goto P_0c04d9a4;
case 0x0c04d9a6u: goto P_0c04d9a6;
case 0x0c04d9a8u: goto P_0c04d9a8;
case 0x0c04d9aau: goto P_0c04d9aa;
case 0x0c04d9acu: goto P_0c04d9ac;
case 0x0c04d9aeu: goto P_0c04d9ae;
case 0x0c04d9b0u: goto P_0c04d9b0;
case 0x0c04d9b2u: goto P_0c04d9b2;
case 0x0c04d9b4u: goto P_0c04d9b4;
case 0x0c04d9b6u: goto P_0c04d9b6;
case 0x0c04d9b8u: goto P_0c04d9b8;
case 0x0c04d9fcu: goto P_0c04d9fc;
case 0x0c04d9feu: goto P_0c04d9fe;
case 0x0c04da00u: goto P_0c04da00;
case 0x0c04da02u: goto P_0c04da02;
case 0x0c04da04u: goto P_0c04da04;
case 0x0c04da06u: goto P_0c04da06;
case 0x0c04da08u: goto P_0c04da08;
case 0x0c04da0au: goto P_0c04da0a;
case 0x0c04da0cu: goto P_0c04da0c;
case 0x0c04da0eu: goto P_0c04da0e;
case 0x0c04da10u: goto P_0c04da10;
case 0x0c04da12u: goto P_0c04da12;
case 0x0c04da14u: goto P_0c04da14;
case 0x0c04da16u: goto P_0c04da16;
case 0x0c04da18u: goto P_0c04da18;
case 0x0c04da1au: goto P_0c04da1a;
case 0x0c04da1cu: goto P_0c04da1c;
case 0x0c04da1eu: goto P_0c04da1e;
case 0x0c04da20u: goto P_0c04da20;
case 0x0c04da22u: goto P_0c04da22;
case 0x0c04da24u: goto P_0c04da24;
case 0x0c04da26u: goto P_0c04da26;
case 0x0c04da28u: goto P_0c04da28;
case 0x0c04da2au: goto P_0c04da2a;
case 0x0c04da2cu: goto P_0c04da2c;
case 0x0c04da2eu: goto P_0c04da2e;
case 0x0c04da30u: goto P_0c04da30;
case 0x0c04da32u: goto P_0c04da32;
case 0x0c04da34u: goto P_0c04da34;
case 0x0c04da36u: goto P_0c04da36;
case 0x0c04da38u: goto P_0c04da38;
case 0x0c04da3au: goto P_0c04da3a;
case 0x0c04da3cu: goto P_0c04da3c;
case 0x0c04da3eu: goto P_0c04da3e;
case 0x0c04da40u: goto P_0c04da40;
case 0x0c04da42u: goto P_0c04da42;
case 0x0c04da44u: goto P_0c04da44;
case 0x0c04da46u: goto P_0c04da46;
case 0x0c04da48u: goto P_0c04da48;
case 0x0c04da4au: goto P_0c04da4a;
case 0x0c04da4cu: goto P_0c04da4c;
case 0x0c04da4eu: goto P_0c04da4e;
case 0x0c04da50u: goto P_0c04da50;
case 0x0c04da52u: goto P_0c04da52;
case 0x0c04da54u: goto P_0c04da54;
case 0x0c04da56u: goto P_0c04da56;
case 0x0c04da58u: goto P_0c04da58;
case 0x0c04da5au: goto P_0c04da5a;
case 0x0c04da5cu: goto P_0c04da5c;
case 0x0c04da5eu: goto P_0c04da5e;
case 0x0c04da60u: goto P_0c04da60;
case 0x0c04da62u: goto P_0c04da62;
case 0x0c04da64u: goto P_0c04da64;
case 0x0c04da66u: goto P_0c04da66;
case 0x0c04da68u: goto P_0c04da68;
case 0x0c04da6au: goto P_0c04da6a;
case 0x0c04da6cu: goto P_0c04da6c;
case 0x0c04da6eu: goto P_0c04da6e;
case 0x0c04da70u: goto P_0c04da70;
case 0x0c04da72u: goto P_0c04da72;
case 0x0c04da74u: goto P_0c04da74;
case 0x0c04da76u: goto P_0c04da76;
case 0x0c04da78u: goto P_0c04da78;
case 0x0c04da7au: goto P_0c04da7a;
case 0x0c04da7cu: goto P_0c04da7c;
case 0x0c04da7eu: goto P_0c04da7e;
case 0x0c04da80u: goto P_0c04da80;
case 0x0c04da82u: goto P_0c04da82;
case 0x0c04da84u: goto P_0c04da84;
case 0x0c04da86u: goto P_0c04da86;
case 0x0c04da88u: goto P_0c04da88;
case 0x0c04da8au: goto P_0c04da8a;
case 0x0c04da8cu: goto P_0c04da8c;
case 0x0c04da8eu: goto P_0c04da8e;
case 0x0c04da90u: goto P_0c04da90;
case 0x0c04da92u: goto P_0c04da92;
case 0x0c04da94u: goto P_0c04da94;
case 0x0c04da96u: goto P_0c04da96;
case 0x0c04da98u: goto P_0c04da98;
case 0x0c04da9au: goto P_0c04da9a;
case 0x0c04da9cu: goto P_0c04da9c;
case 0x0c04da9eu: goto P_0c04da9e;
case 0x0c04daa0u: goto P_0c04daa0;
case 0x0c04daa2u: goto P_0c04daa2;
case 0x0c04daa4u: goto P_0c04daa4;
case 0x0c04daa6u: goto P_0c04daa6;
case 0x0c04daa8u: goto P_0c04daa8;
case 0x0c04daaau: goto P_0c04daaa;
case 0x0c04daacu: goto P_0c04daac;
case 0x0c04daaeu: goto P_0c04daae;
case 0x0c04dab0u: goto P_0c04dab0;
case 0x0c04dab2u: goto P_0c04dab2;
case 0x0c04dab4u: goto P_0c04dab4;
case 0x0c04dab6u: goto P_0c04dab6;
case 0x0c04dab8u: goto P_0c04dab8;
case 0x0c04dabau: goto P_0c04daba;
case 0x0c04dabcu: goto P_0c04dabc;
case 0x0c04dabeu: goto P_0c04dabe;
case 0x0c04dac0u: goto P_0c04dac0;
case 0x0c04dac2u: goto P_0c04dac2;
case 0x0c04dac4u: goto P_0c04dac4;
case 0x0c04dac6u: goto P_0c04dac6;
case 0x0c04dac8u: goto P_0c04dac8;
case 0x0c04dacau: goto P_0c04daca;
case 0x0c04daccu: goto P_0c04dacc;
case 0x0c04daceu: goto P_0c04dace;
case 0x0c04dad0u: goto P_0c04dad0;
case 0x0c04dad2u: goto P_0c04dad2;
case 0x0c04dad4u: goto P_0c04dad4;
case 0x0c04dad6u: goto P_0c04dad6;
case 0x0c04dad8u: goto P_0c04dad8;
case 0x0c04dadau: goto P_0c04dada;
case 0x0c04dadcu: goto P_0c04dadc;
case 0x0c04db28u: goto P_0c04db28;
case 0x0c04db2au: goto P_0c04db2a;
case 0x0c04db2cu: goto P_0c04db2c;
case 0x0c04db2eu: goto P_0c04db2e;
case 0x0c04db30u: goto P_0c04db30;
case 0x0c04db32u: goto P_0c04db32;
case 0x0c04db34u: goto P_0c04db34;
case 0x0c04db36u: goto P_0c04db36;
case 0x0c04db38u: goto P_0c04db38;
case 0x0c04db3au: goto P_0c04db3a;
case 0x0c04db3cu: goto P_0c04db3c;
case 0x0c04db3eu: goto P_0c04db3e;
case 0x0c04db40u: goto P_0c04db40;
case 0x0c04db42u: goto P_0c04db42;
case 0x0c04db44u: goto P_0c04db44;
case 0x0c04db46u: goto P_0c04db46;
case 0x0c04db48u: goto P_0c04db48;
case 0x0c04db4au: goto P_0c04db4a;
case 0x0c04db4cu: goto P_0c04db4c;
case 0x0c04db4eu: goto P_0c04db4e;
case 0x0c04db50u: goto P_0c04db50;
case 0x0c04db52u: goto P_0c04db52;
case 0x0c04db54u: goto P_0c04db54;
case 0x0c04db56u: goto P_0c04db56;
case 0x0c04db58u: goto P_0c04db58;
case 0x0c04db5au: goto P_0c04db5a;
case 0x0c04db5cu: goto P_0c04db5c;
case 0x0c04db5eu: goto P_0c04db5e;
case 0x0c04db60u: goto P_0c04db60;
case 0x0c04db62u: goto P_0c04db62;
case 0x0c04db64u: goto P_0c04db64;
case 0x0c04db66u: goto P_0c04db66;
case 0x0c04db68u: goto P_0c04db68;
case 0x0c04db6au: goto P_0c04db6a;
case 0x0c04db6cu: goto P_0c04db6c;
case 0x0c04db6eu: goto P_0c04db6e;
case 0x0c04db70u: goto P_0c04db70;
case 0x0c04db72u: goto P_0c04db72;
case 0x0c04db74u: goto P_0c04db74;
case 0x0c04db76u: goto P_0c04db76;
case 0x0c04db78u: goto P_0c04db78;
case 0x0c04db7au: goto P_0c04db7a;
case 0x0c04db7cu: goto P_0c04db7c;
case 0x0c04db7eu: goto P_0c04db7e;
case 0x0c04db80u: goto P_0c04db80;
case 0x0c04db82u: goto P_0c04db82;
case 0x0c04db84u: goto P_0c04db84;
case 0x0c04db86u: goto P_0c04db86;
case 0x0c04db88u: goto P_0c04db88;
case 0x0c04db8au: goto P_0c04db8a;
case 0x0c04db8cu: goto P_0c04db8c;
case 0x0c04db8eu: goto P_0c04db8e;
case 0x0c04db90u: goto P_0c04db90;
case 0x0c04db92u: goto P_0c04db92;
case 0x0c04db94u: goto P_0c04db94;
case 0x0c04db96u: goto P_0c04db96;
case 0x0c04db98u: goto P_0c04db98;
case 0x0c04db9au: goto P_0c04db9a;
case 0x0c04db9cu: goto P_0c04db9c;
case 0x0c04db9eu: goto P_0c04db9e;
case 0x0c04dba0u: goto P_0c04dba0;
case 0x0c04dba2u: goto P_0c04dba2;
case 0x0c04dba4u: goto P_0c04dba4;
case 0x0c04dba6u: goto P_0c04dba6;
case 0x0c04dba8u: goto P_0c04dba8;
case 0x0c04dbaau: goto P_0c04dbaa;
case 0x0c04dbacu: goto P_0c04dbac;
case 0x0c04dbaeu: goto P_0c04dbae;
case 0x0c04dbb0u: goto P_0c04dbb0;
case 0x0c04dbb2u: goto P_0c04dbb2;
case 0x0c04dbb4u: goto P_0c04dbb4;
case 0x0c04dbb6u: goto P_0c04dbb6;
case 0x0c04dbb8u: goto P_0c04dbb8;
case 0x0c04dbbau: goto P_0c04dbba;
case 0x0c04dbbcu: goto P_0c04dbbc;
case 0x0c04dbbeu: goto P_0c04dbbe;
case 0x0c04dbc0u: goto P_0c04dbc0;
case 0x0c04dbc2u: goto P_0c04dbc2;
case 0x0c04dbc4u: goto P_0c04dbc4;
case 0x0c04dbc6u: goto P_0c04dbc6;
case 0x0c04dbc8u: goto P_0c04dbc8;
case 0x0c04dbcau: goto P_0c04dbca;
case 0x0c04dbccu: goto P_0c04dbcc;
case 0x0c04dbceu: goto P_0c04dbce;
case 0x0c04dbd0u: goto P_0c04dbd0;
case 0x0c04dbd2u: goto P_0c04dbd2;
case 0x0c04dbd4u: goto P_0c04dbd4;
case 0x0c04dbd6u: goto P_0c04dbd6;
case 0x0c04dbd8u: goto P_0c04dbd8;
case 0x0c04dbdau: goto P_0c04dbda;
case 0x0c04dbdcu: goto P_0c04dbdc;
case 0x0c04dbdeu: goto P_0c04dbde;
case 0x0c04dbe0u: goto P_0c04dbe0;
case 0x0c04dbe2u: goto P_0c04dbe2;
case 0x0c04dbe4u: goto P_0c04dbe4;
case 0x0c04dbe6u: goto P_0c04dbe6;
case 0x0c04dbe8u: goto P_0c04dbe8;
case 0x0c04dbeau: goto P_0c04dbea;
case 0x0c04dbecu: goto P_0c04dbec;
case 0x0c04dbeeu: goto P_0c04dbee;
case 0x0c04dbf0u: goto P_0c04dbf0;
case 0x0c04dbf2u: goto P_0c04dbf2;
case 0x0c04dbf4u: goto P_0c04dbf4;
case 0x0c04dbf6u: goto P_0c04dbf6;
case 0x0c04dbf8u: goto P_0c04dbf8;
case 0x0c04dbfau: goto P_0c04dbfa;
case 0x0c04dbfcu: goto P_0c04dbfc;
case 0x0c04dbfeu: goto P_0c04dbfe;
case 0x0c04dc00u: goto P_0c04dc00;
case 0x0c04dc02u: goto P_0c04dc02;
case 0x0c04dc04u: goto P_0c04dc04;
case 0x0c04dc06u: goto P_0c04dc06;
case 0x0c04dc08u: goto P_0c04dc08;
case 0x0c04dc0au: goto P_0c04dc0a;
case 0x0c04dc0cu: goto P_0c04dc0c;
case 0x0c04dc0eu: goto P_0c04dc0e;
case 0x0c04dc10u: goto P_0c04dc10;
case 0x0c04dc12u: goto P_0c04dc12;
case 0x0c04dc14u: goto P_0c04dc14;
case 0x0c04dc16u: goto P_0c04dc16;
case 0x0c04dc18u: goto P_0c04dc18;
case 0x0c04dc50u: goto P_0c04dc50;
case 0x0c04dc52u: goto P_0c04dc52;
case 0x0c04dc54u: goto P_0c04dc54;
case 0x0c04dc56u: goto P_0c04dc56;
case 0x0c04dc58u: goto P_0c04dc58;
case 0x0c04dc5au: goto P_0c04dc5a;
case 0x0c04dc5cu: goto P_0c04dc5c;
case 0x0c04dc5eu: goto P_0c04dc5e;
case 0x0c04dc60u: goto P_0c04dc60;
case 0x0c04dc62u: goto P_0c04dc62;
case 0x0c04dc64u: goto P_0c04dc64;
case 0x0c04dc66u: goto P_0c04dc66;
case 0x0c04dc68u: goto P_0c04dc68;
case 0x0c04dc6au: goto P_0c04dc6a;
case 0x0c04dc6cu: goto P_0c04dc6c;
case 0x0c04dc6eu: goto P_0c04dc6e;
case 0x0c04dc70u: goto P_0c04dc70;
case 0x0c04dc72u: goto P_0c04dc72;
case 0x0c04dc74u: goto P_0c04dc74;
case 0x0c04dc76u: goto P_0c04dc76;
case 0x0c04dc78u: goto P_0c04dc78;
case 0x0c04dc7au: goto P_0c04dc7a;
case 0x0c04dc7cu: goto P_0c04dc7c;
case 0x0c04dc7eu: goto P_0c04dc7e;
case 0x0c04dc80u: goto P_0c04dc80;
case 0x0c04dc82u: goto P_0c04dc82;
case 0x0c04dc84u: goto P_0c04dc84;
case 0x0c04dc86u: goto P_0c04dc86;
case 0x0c04dc88u: goto P_0c04dc88;
case 0x0c04dc8au: goto P_0c04dc8a;
case 0x0c04dc8cu: goto P_0c04dc8c;
case 0x0c04dc8eu: goto P_0c04dc8e;
case 0x0c04dc90u: goto P_0c04dc90;
case 0x0c04dc92u: goto P_0c04dc92;
case 0x0c04dc94u: goto P_0c04dc94;
case 0x0c04dc96u: goto P_0c04dc96;
case 0x0c04dc98u: goto P_0c04dc98;
case 0x0c04dc9au: goto P_0c04dc9a;
case 0x0c04dc9cu: goto P_0c04dc9c;
case 0x0c04dc9eu: goto P_0c04dc9e;
case 0x0c04dca0u: goto P_0c04dca0;
case 0x0c04dca2u: goto P_0c04dca2;
case 0x0c04dca4u: goto P_0c04dca4;
case 0x0c04dca6u: goto P_0c04dca6;
case 0x0c04dca8u: goto P_0c04dca8;
case 0x0c04dcaau: goto P_0c04dcaa;
case 0x0c04dcacu: goto P_0c04dcac;
case 0x0c04dcaeu: goto P_0c04dcae;
case 0x0c04dcb0u: goto P_0c04dcb0;
case 0x0c04dcb2u: goto P_0c04dcb2;
case 0x0c04dcb4u: goto P_0c04dcb4;
case 0x0c04dcb6u: goto P_0c04dcb6;
case 0x0c04dcb8u: goto P_0c04dcb8;
case 0x0c04dcbau: goto P_0c04dcba;
case 0x0c04dcbcu: goto P_0c04dcbc;
case 0x0c04dcbeu: goto P_0c04dcbe;
case 0x0c04dcc0u: goto P_0c04dcc0;
case 0x0c04dcc2u: goto P_0c04dcc2;
case 0x0c04dcc4u: goto P_0c04dcc4;
case 0x0c04dcc6u: goto P_0c04dcc6;
case 0x0c04dcc8u: goto P_0c04dcc8;
case 0x0c04dccau: goto P_0c04dcca;
case 0x0c04dcccu: goto P_0c04dccc;
case 0x0c04dcceu: goto P_0c04dcce;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04d95e: /* original 2fe6, guest PC 0x0c04d95e */
if(!s->budget--) { s->failed_pc=0x0c04d95eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d960;
P_0c04d960: /* original 6e43, guest PC 0x0c04d960 */
if(!s->budget--) { s->failed_pc=0x0c04d960u; return 0; }
r[14]=r[4];
goto P_0c04d962;
P_0c04d962: /* original 2fd6, guest PC 0x0c04d962 */
if(!s->budget--) { s->failed_pc=0x0c04d962u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d964;
P_0c04d964: /* original 2fc6, guest PC 0x0c04d964 */
if(!s->budget--) { s->failed_pc=0x0c04d964u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d966;
P_0c04d966: /* original 6c53, guest PC 0x0c04d966 */
if(!s->budget--) { s->failed_pc=0x0c04d966u; return 0; }
r[12]=r[5];
goto P_0c04d968;
P_0c04d968: /* original 2fb6, guest PC 0x0c04d968 */
if(!s->budget--) { s->failed_pc=0x0c04d968u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d96a;
P_0c04d96a: /* original 2fa6, guest PC 0x0c04d96a */
if(!s->budget--) { s->failed_pc=0x0c04d96au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d96c;
P_0c04d96c: /* original 6a73, guest PC 0x0c04d96c */
if(!s->budget--) { s->failed_pc=0x0c04d96cu; return 0; }
r[10]=r[7];
goto P_0c04d96e;
P_0c04d96e: /* original 2f96, guest PC 0x0c04d96e */
if(!s->budget--) { s->failed_pc=0x0c04d96eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d970;
P_0c04d970: /* original 4f22, guest PC 0x0c04d970 */
if(!s->budget--) { s->failed_pc=0x0c04d970u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04d972;
P_0c04d972: /* original 4f12, guest PC 0x0c04d972 */
if(!s->budget--) { s->failed_pc=0x0c04d972u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04d974;
P_0c04d974: /* original 7fc8, guest PC 0x0c04d974 */
if(!s->budget--) { s->failed_pc=0x0c04d974u; return 0; }
r[15]+=0xffffffc8u;
goto P_0c04d976;
P_0c04d976: /* original 2f62, guest PC 0x0c04d976 */
if(!s->budget--) { s->failed_pc=0x0c04d976u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c04d978;
P_0c04d978: /* original 9322, guest PC 0x0c04d978 */
if(!s->budget--) { s->failed_pc=0x0c04d978u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d9c0u,2);
goto P_0c04d97a;
P_0c04d97a: /* original 2e3f, guest PC 0x0c04d97a */
if(!s->budget--) { s->failed_pc=0x0c04d97au; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c04d97c;
P_0c04d97c: /* original 031a, guest PC 0x0c04d97c */
if(!s->budget--) { s->failed_pc=0x0c04d97cu; return 0; }
r[3]=r[19];
goto P_0c04d97e;
P_0c04d97e: /* original 633f, guest PC 0x0c04d97e */
if(!s->budget--) { s->failed_pc=0x0c04d97eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04d980;
P_0c04d980: /* original 1f32, guest PC 0x0c04d980 */
if(!s->budget--) { s->failed_pc=0x0c04d980u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c04d982;
P_0c04d982: /* original d21b, guest PC 0x0c04d982 */
if(!s->budget--) { s->failed_pc=0x0c04d982u; return 0; }
r[2]=read(ram,0x0c04d9f0u,4);
goto P_0c04d984;
P_0c04d984: /* original 332c, guest PC 0x0c04d984 */
if(!s->budget--) { s->failed_pc=0x0c04d984u; return 0; }
r[3]+=r[2];
goto P_0c04d986;
P_0c04d986: /* original 1f31, guest PC 0x0c04d986 */
if(!s->budget--) { s->failed_pc=0x0c04d986u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c04d988;
P_0c04d988: /* original 2fa6, guest PC 0x0c04d988 */
if(!s->budget--) { s->failed_pc=0x0c04d988u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d98a;
P_0c04d98a: /* original 51f1, guest PC 0x0c04d98a */
if(!s->budget--) { s->failed_pc=0x0c04d98au; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c04d98c;
P_0c04d98c: /* original 2f16, guest PC 0x0c04d98c */
if(!s->budget--) { s->failed_pc=0x0c04d98cu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d98e;
P_0c04d98e: /* original 2fc6, guest PC 0x0c04d98e */
if(!s->budget--) { s->failed_pc=0x0c04d98eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d990;
P_0c04d990: /* original 2fe6, guest PC 0x0c04d990 */
if(!s->budget--) { s->failed_pc=0x0c04d990u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d992;
P_0c04d992: /* original d118, guest PC 0x0c04d992 */
if(!s->budget--) { s->failed_pc=0x0c04d992u; return 0; }
r[1]=read(ram,0x0c04d9f4u,4);
goto P_0c04d994;
P_0c04d994: /* original d312, guest PC 0x0c04d994 */
if(!s->budget--) { s->failed_pc=0x0c04d994u; return 0; }
r[3]=read(ram,0x0c04d9e0u,4);
goto P_0c04d996;
P_0c04d996: /* original 430b, guest PC 0x0c04d996 */
if(!s->budget--) { s->failed_pc=0x0c04d996u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d99au;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d99au) { target=s->pc; goto dispatch; }
goto P_0c04d99a;
P_0c04d998: /* original 2f16, guest PC 0x0c04d998 */
if(!s->budget--) { s->failed_pc=0x0c04d998u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d99a;
P_0c04d99a: /* original 7f14, guest PC 0x0c04d99a */
if(!s->budget--) { s->failed_pc=0x0c04d99au; return 0; }
r[15]+=0x00000014u;
goto P_0c04d99c;
P_0c04d99c: /* original eb00, guest PC 0x0c04d99c */
if(!s->budget--) { s->failed_pc=0x0c04d99cu; return 0; }
r[11]=0x00000000u;
goto P_0c04d99e;
P_0c04d99e: /* original 2ab2, guest PC 0x0c04d99e */
if(!s->budget--) { s->failed_pc=0x0c04d99eu; return 0; }
write(ram,r[10],r[11],4);
goto P_0c04d9a0;
P_0c04d9a0: /* original 52f1, guest PC 0x0c04d9a0 */
if(!s->budget--) { s->failed_pc=0x0c04d9a0u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c04d9a2;
P_0c04d9a2: /* original 8422, guest PC 0x0c04d9a2 */
if(!s->budget--) { s->failed_pc=0x0c04d9a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+2,1);
goto P_0c04d9a4;
P_0c04d9a4: /* original 2008, guest PC 0x0c04d9a4 */
if(!s->budget--) { s->failed_pc=0x0c04d9a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d9a6;
P_0c04d9a6: /* original 8934, guest PC 0x0c04d9a6 */
if(!s->budget--) { s->failed_pc=0x0c04d9a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04da12; }
goto P_0c04d9a8;
P_0c04d9a8: /* original d213, guest PC 0x0c04d9a8 */
if(!s->budget--) { s->failed_pc=0x0c04d9a8u; return 0; }
r[2]=read(ram,0x0c04d9f8u,4);
goto P_0c04d9aa;
P_0c04d9aa: /* original 420b, guest PC 0x0c04d9aa */
if(!s->budget--) { s->failed_pc=0x0c04d9aau; return 0; }
target=r[2];
r[16]=code_base|0x0c04d9aeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d9aeu) { target=s->pc; goto dispatch; }
goto P_0c04d9ae;
P_0c04d9ac: /* original 64e3, guest PC 0x0c04d9ac */
if(!s->budget--) { s->failed_pc=0x0c04d9acu; return 0; }
r[4]=r[14];
goto P_0c04d9ae;
P_0c04d9ae: /* original 2008, guest PC 0x0c04d9ae */
if(!s->budget--) { s->failed_pc=0x0c04d9aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d9b0;
P_0c04d9b0: /* original 8b24, guest PC 0x0c04d9b0 */
if(!s->budget--) { s->failed_pc=0x0c04d9b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d9fc; }
goto P_0c04d9b2;
P_0c04d9b2: /* original ba8c, guest PC 0x0c04d9b2 */
if(!s->budget--) { s->failed_pc=0x0c04d9b2u; return 0; }
target=code_base|0x0c04ceceu; r[16]=code_base|0x0c04d9b6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d9b6u) { target=s->pc; goto dispatch; }
goto P_0c04d9b6;
P_0c04d9b4: /* original 64e3, guest PC 0x0c04d9b4 */
if(!s->budget--) { s->failed_pc=0x0c04d9b4u; return 0; }
r[4]=r[14];
goto P_0c04d9b6;
P_0c04d9b6: /* original a02c, guest PC 0x0c04d9b6 */
if(!s->budget--) { s->failed_pc=0x0c04d9b6u; return 0; }
goto P_0c04da12;
P_0c04d9b8: /* original 0009, guest PC 0x0c04d9b8 */
if(!s->budget--) { s->failed_pc=0x0c04d9b8u; return 0; }
if(!vf3_matrix_family(0x0c04d9bau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04d9bau; return 0; } return 1;
P_0c04d9fc: /* original d33b, guest PC 0x0c04d9fc */
if(!s->budget--) { s->failed_pc=0x0c04d9fcu; return 0; }
r[3]=read(ram,0x0c04daecu,4);
goto P_0c04d9fe;
P_0c04d9fe: /* original 430b, guest PC 0x0c04d9fe */
if(!s->budget--) { s->failed_pc=0x0c04d9feu; return 0; }
target=r[3];
r[16]=code_base|0x0c04da02u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04da02u) { target=s->pc; goto dispatch; }
goto P_0c04da02;
P_0c04da00: /* original 64e3, guest PC 0x0c04da00 */
if(!s->budget--) { s->failed_pc=0x0c04da00u; return 0; }
r[4]=r[14];
goto P_0c04da02;
P_0c04da02: /* original 2008, guest PC 0x0c04da02 */
if(!s->budget--) { s->failed_pc=0x0c04da02u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04da04;
P_0c04da04: /* original 8905, guest PC 0x0c04da04 */
if(!s->budget--) { s->failed_pc=0x0c04da04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04da12; }
goto P_0c04da06;
P_0c04da06: /* original 52f2, guest PC 0x0c04da06 */
if(!s->budget--) { s->failed_pc=0x0c04da06u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c04da08;
P_0c04da08: /* original d339, guest PC 0x0c04da08 */
if(!s->budget--) { s->failed_pc=0x0c04da08u; return 0; }
r[3]=read(ram,0x0c04daf0u,4);
goto P_0c04da0a;
P_0c04da0a: /* original 323c, guest PC 0x0c04da0a */
if(!s->budget--) { s->failed_pc=0x0c04da0au; return 0; }
r[2]+=r[3];
goto P_0c04da0c;
P_0c04da0c: /* original 8428, guest PC 0x0c04da0c */
if(!s->budget--) { s->failed_pc=0x0c04da0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04da0e;
P_0c04da0e: /* original 2008, guest PC 0x0c04da0e */
if(!s->budget--) { s->failed_pc=0x0c04da0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04da10;
P_0c04da10: /* original 8b02, guest PC 0x0c04da10 */
if(!s->budget--) { s->failed_pc=0x0c04da10u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04da18; }
goto P_0c04da12;
P_0c04da12: /* original 9064, guest PC 0x0c04da12 */
if(!s->budget--) { s->failed_pc=0x0c04da12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dadeu,2);
goto P_0c04da14;
P_0c04da14: /* original a096, guest PC 0x0c04da14 */
if(!s->budget--) { s->failed_pc=0x0c04da14u; return 0; }
goto P_0c04db44;
P_0c04da16: /* original 0009, guest PC 0x0c04da16 */
if(!s->budget--) { s->failed_pc=0x0c04da16u; return 0; }
goto P_0c04da18;
P_0c04da18: /* original d336, guest PC 0x0c04da18 */
if(!s->budget--) { s->failed_pc=0x0c04da18u; return 0; }
r[3]=read(ram,0x0c04daf4u,4);
goto P_0c04da1a;
P_0c04da1a: /* original 430b, guest PC 0x0c04da1a */
if(!s->budget--) { s->failed_pc=0x0c04da1au; return 0; }
target=r[3];
r[16]=code_base|0x0c04da1eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04da1eu) { target=s->pc; goto dispatch; }
goto P_0c04da1e;
P_0c04da1c: /* original 64e3, guest PC 0x0c04da1c */
if(!s->budget--) { s->failed_pc=0x0c04da1cu; return 0; }
r[4]=r[14];
goto P_0c04da1e;
P_0c04da1e: /* original 4011, guest PC 0x0c04da1e */
if(!s->budget--) { s->failed_pc=0x0c04da1eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04da20;
P_0c04da20: /* original 8902, guest PC 0x0c04da20 */
if(!s->budget--) { s->failed_pc=0x0c04da20u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04da28; }
goto P_0c04da22;
P_0c04da22: /* original 905d, guest PC 0x0c04da22 */
if(!s->budget--) { s->failed_pc=0x0c04da22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dae0u,2);
goto P_0c04da24;
P_0c04da24: /* original a08e, guest PC 0x0c04da24 */
if(!s->budget--) { s->failed_pc=0x0c04da24u; return 0; }
goto P_0c04db44;
P_0c04da26: /* original 0009, guest PC 0x0c04da26 */
if(!s->budget--) { s->failed_pc=0x0c04da26u; return 0; }
goto P_0c04da28;
P_0c04da28: /* original 53f1, guest PC 0x0c04da28 */
if(!s->budget--) { s->failed_pc=0x0c04da28u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c04da2a;
P_0c04da2a: /* original 5237, guest PC 0x0c04da2a */
if(!s->budget--) { s->failed_pc=0x0c04da2au; return 0; }
r[2]=read(ram,r[3]+28,4);
goto P_0c04da2c;
P_0c04da2c: /* original 512e, guest PC 0x0c04da2c */
if(!s->budget--) { s->failed_pc=0x0c04da2cu; return 0; }
r[1]=read(ram,r[2]+56,4);
goto P_0c04da2e;
P_0c04da2e: /* original 2118, guest PC 0x0c04da2e */
if(!s->budget--) { s->failed_pc=0x0c04da2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c04da30;
P_0c04da30: /* original 8928, guest PC 0x0c04da30 */
if(!s->budget--) { s->failed_pc=0x0c04da30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04da84; }
goto P_0c04da32;
P_0c04da32: /* original d331, guest PC 0x0c04da32 */
if(!s->budget--) { s->failed_pc=0x0c04da32u; return 0; }
r[3]=read(ram,0x0c04daf8u,4);
goto P_0c04da34;
P_0c04da34: /* original 65c3, guest PC 0x0c04da34 */
if(!s->budget--) { s->failed_pc=0x0c04da34u; return 0; }
r[5]=r[12];
goto P_0c04da36;
P_0c04da36: /* original 430b, guest PC 0x0c04da36 */
if(!s->budget--) { s->failed_pc=0x0c04da36u; return 0; }
target=r[3];
r[16]=code_base|0x0c04da3au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04da3au) { target=s->pc; goto dispatch; }
goto P_0c04da3a;
P_0c04da38: /* original 64e3, guest PC 0x0c04da38 */
if(!s->budget--) { s->failed_pc=0x0c04da38u; return 0; }
r[4]=r[14];
goto P_0c04da3a;
P_0c04da3a: /* original 4011, guest PC 0x0c04da3a */
if(!s->budget--) { s->failed_pc=0x0c04da3au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04da3c;
P_0c04da3c: /* original 8b22, guest PC 0x0c04da3c */
if(!s->budget--) { s->failed_pc=0x0c04da3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04da84; }
goto P_0c04da3e;
P_0c04da3e: /* original d32f, guest PC 0x0c04da3e */
if(!s->budget--) { s->failed_pc=0x0c04da3eu; return 0; }
r[3]=read(ram,0x0c04dafcu,4);
goto P_0c04da40;
P_0c04da40: /* original 66f3, guest PC 0x0c04da40 */
if(!s->budget--) { s->failed_pc=0x0c04da40u; return 0; }
r[6]=r[15];
goto P_0c04da42;
P_0c04da42: /* original 65c3, guest PC 0x0c04da42 */
if(!s->budget--) { s->failed_pc=0x0c04da42u; return 0; }
r[5]=r[12];
goto P_0c04da44;
P_0c04da44: /* original 760c, guest PC 0x0c04da44 */
if(!s->budget--) { s->failed_pc=0x0c04da44u; return 0; }
r[6]+=0x0000000cu;
goto P_0c04da46;
P_0c04da46: /* original 430b, guest PC 0x0c04da46 */
if(!s->budget--) { s->failed_pc=0x0c04da46u; return 0; }
target=r[3];
r[16]=code_base|0x0c04da4au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04da4au) { target=s->pc; goto dispatch; }
goto P_0c04da4a;
P_0c04da48: /* original 64e3, guest PC 0x0c04da48 */
if(!s->budget--) { s->failed_pc=0x0c04da48u; return 0; }
r[4]=r[14];
goto P_0c04da4a;
P_0c04da4a: /* original 4011, guest PC 0x0c04da4a */
if(!s->budget--) { s->failed_pc=0x0c04da4au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04da4c;
P_0c04da4c: /* original 8b02, guest PC 0x0c04da4c */
if(!s->budget--) { s->failed_pc=0x0c04da4cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04da54; }
goto P_0c04da4e;
P_0c04da4e: /* original 9048, guest PC 0x0c04da4e */
if(!s->budget--) { s->failed_pc=0x0c04da4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dae2u,2);
goto P_0c04da50;
P_0c04da50: /* original a078, guest PC 0x0c04da50 */
if(!s->budget--) { s->failed_pc=0x0c04da50u; return 0; }
goto P_0c04db44;
P_0c04da52: /* original 0009, guest PC 0x0c04da52 */
if(!s->budget--) { s->failed_pc=0x0c04da52u; return 0; }
goto P_0c04da54;
P_0c04da54: /* original d32a, guest PC 0x0c04da54 */
if(!s->budget--) { s->failed_pc=0x0c04da54u; return 0; }
r[3]=read(ram,0x0c04db00u,4);
goto P_0c04da56;
P_0c04da56: /* original 65f3, guest PC 0x0c04da56 */
if(!s->budget--) { s->failed_pc=0x0c04da56u; return 0; }
r[5]=r[15];
goto P_0c04da58;
P_0c04da58: /* original 750c, guest PC 0x0c04da58 */
if(!s->budget--) { s->failed_pc=0x0c04da58u; return 0; }
r[5]+=0x0000000cu;
goto P_0c04da5a;
P_0c04da5a: /* original 430b, guest PC 0x0c04da5a */
if(!s->budget--) { s->failed_pc=0x0c04da5au; return 0; }
target=r[3];
r[16]=code_base|0x0c04da5eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04da5eu) { target=s->pc; goto dispatch; }
goto P_0c04da5e;
P_0c04da5c: /* original 64e3, guest PC 0x0c04da5c */
if(!s->budget--) { s->failed_pc=0x0c04da5cu; return 0; }
r[4]=r[14];
goto P_0c04da5e;
P_0c04da5e: /* original 4011, guest PC 0x0c04da5e */
if(!s->budget--) { s->failed_pc=0x0c04da5eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04da60;
P_0c04da60: /* original 8b02, guest PC 0x0c04da60 */
if(!s->budget--) { s->failed_pc=0x0c04da60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04da68; }
goto P_0c04da62;
P_0c04da62: /* original 903f, guest PC 0x0c04da62 */
if(!s->budget--) { s->failed_pc=0x0c04da62u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dae4u,2);
goto P_0c04da64;
P_0c04da64: /* original a06e, guest PC 0x0c04da64 */
if(!s->budget--) { s->failed_pc=0x0c04da64u; return 0; }
goto P_0c04db44;
P_0c04da66: /* original 0009, guest PC 0x0c04da66 */
if(!s->budget--) { s->failed_pc=0x0c04da66u; return 0; }
goto P_0c04da68;
P_0c04da68: /* original d326, guest PC 0x0c04da68 */
if(!s->budget--) { s->failed_pc=0x0c04da68u; return 0; }
r[3]=read(ram,0x0c04db04u,4);
goto P_0c04da6a;
P_0c04da6a: /* original e500, guest PC 0x0c04da6a */
if(!s->budget--) { s->failed_pc=0x0c04da6au; return 0; }
r[5]=0x00000000u;
goto P_0c04da6c;
P_0c04da6c: /* original 430b, guest PC 0x0c04da6c */
if(!s->budget--) { s->failed_pc=0x0c04da6cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04da70u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04da70u) { target=s->pc; goto dispatch; }
goto P_0c04da70;
P_0c04da6e: /* original 64e3, guest PC 0x0c04da6e */
if(!s->budget--) { s->failed_pc=0x0c04da6eu; return 0; }
r[4]=r[14];
goto P_0c04da70;
P_0c04da70: /* original d225, guest PC 0x0c04da70 */
if(!s->budget--) { s->failed_pc=0x0c04da70u; return 0; }
r[2]=read(ram,0x0c04db08u,4);
goto P_0c04da72;
P_0c04da72: /* original 600d, guest PC 0x0c04da72 */
if(!s->budget--) { s->failed_pc=0x0c04da72u; return 0; }
r[0]=r[0]&65535u;
goto P_0c04da74;
P_0c04da74: /* original 3020, guest PC 0x0c04da74 */
if(!s->budget--) { s->failed_pc=0x0c04da74u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[2])!=0);
goto P_0c04da76;
P_0c04da76: /* original 8b05, guest PC 0x0c04da76 */
if(!s->budget--) { s->failed_pc=0x0c04da76u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04da84; }
goto P_0c04da78;
P_0c04da78: /* original d324, guest PC 0x0c04da78 */
if(!s->budget--) { s->failed_pc=0x0c04da78u; return 0; }
r[3]=read(ram,0x0c04db0cu,4);
goto P_0c04da7a;
P_0c04da7a: /* original 430b, guest PC 0x0c04da7a */
if(!s->budget--) { s->failed_pc=0x0c04da7au; return 0; }
target=r[3];
r[16]=code_base|0x0c04da7eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04da7eu) { target=s->pc; goto dispatch; }
goto P_0c04da7e;
P_0c04da7c: /* original 64e3, guest PC 0x0c04da7c */
if(!s->budget--) { s->failed_pc=0x0c04da7cu; return 0; }
r[4]=r[14];
goto P_0c04da7e;
P_0c04da7e: /* original 6903, guest PC 0x0c04da7e */
if(!s->budget--) { s->failed_pc=0x0c04da7eu; return 0; }
r[9]=r[0];
goto P_0c04da80;
P_0c04da80: /* original 4911, guest PC 0x0c04da80 */
if(!s->budget--) { s->failed_pc=0x0c04da80u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=0)!=0);
goto P_0c04da82;
P_0c04da82: /* original 8902, guest PC 0x0c04da82 */
if(!s->budget--) { s->failed_pc=0x0c04da82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04da8a; }
goto P_0c04da84;
P_0c04da84: /* original 902f, guest PC 0x0c04da84 */
if(!s->budget--) { s->failed_pc=0x0c04da84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dae6u,2);
goto P_0c04da86;
P_0c04da86: /* original a05d, guest PC 0x0c04da86 */
if(!s->budget--) { s->failed_pc=0x0c04da86u; return 0; }
goto P_0c04db44;
P_0c04da88: /* original 0009, guest PC 0x0c04da88 */
if(!s->budget--) { s->failed_pc=0x0c04da88u; return 0; }
goto P_0c04da8a;
P_0c04da8a: /* original d321, guest PC 0x0c04da8a */
if(!s->budget--) { s->failed_pc=0x0c04da8au; return 0; }
r[3]=read(ram,0x0c04db10u,4);
goto P_0c04da8c;
P_0c04da8c: /* original 6593, guest PC 0x0c04da8c */
if(!s->budget--) { s->failed_pc=0x0c04da8cu; return 0; }
r[5]=r[9];
goto P_0c04da8e;
P_0c04da8e: /* original 430b, guest PC 0x0c04da8e */
if(!s->budget--) { s->failed_pc=0x0c04da8eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04da92u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04da92u) { target=s->pc; goto dispatch; }
goto P_0c04da92;
P_0c04da90: /* original 64e3, guest PC 0x0c04da90 */
if(!s->budget--) { s->failed_pc=0x0c04da90u; return 0; }
r[4]=r[14];
goto P_0c04da92;
P_0c04da92: /* original d220, guest PC 0x0c04da92 */
if(!s->budget--) { s->failed_pc=0x0c04da92u; return 0; }
r[2]=read(ram,0x0c04db14u,4);
goto P_0c04da94;
P_0c04da94: /* original 420b, guest PC 0x0c04da94 */
if(!s->budget--) { s->failed_pc=0x0c04da94u; return 0; }
target=r[2];
r[16]=code_base|0x0c04da98u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04da98u) { target=s->pc; goto dispatch; }
goto P_0c04da98;
P_0c04da96: /* original 64e3, guest PC 0x0c04da96 */
if(!s->budget--) { s->failed_pc=0x0c04da96u; return 0; }
r[4]=r[14];
goto P_0c04da98;
P_0c04da98: /* original 6d03, guest PC 0x0c04da98 */
if(!s->budget--) { s->failed_pc=0x0c04da98u; return 0; }
r[13]=r[0];
goto P_0c04da9a;
P_0c04da9a: /* original 2dd8, guest PC 0x0c04da9a */
if(!s->budget--) { s->failed_pc=0x0c04da9au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c04da9c;
P_0c04da9c: /* original 8b02, guest PC 0x0c04da9c */
if(!s->budget--) { s->failed_pc=0x0c04da9cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04daa4; }
goto P_0c04da9e;
P_0c04da9e: /* original 9023, guest PC 0x0c04da9e */
if(!s->budget--) { s->failed_pc=0x0c04da9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dae8u,2);
goto P_0c04daa0;
P_0c04daa0: /* original a050, guest PC 0x0c04daa0 */
if(!s->budget--) { s->failed_pc=0x0c04daa0u; return 0; }
goto P_0c04db44;
P_0c04daa2: /* original 0009, guest PC 0x0c04daa2 */
if(!s->budget--) { s->failed_pc=0x0c04daa2u; return 0; }
goto P_0c04daa4;
P_0c04daa4: /* original e401, guest PC 0x0c04daa4 */
if(!s->budget--) { s->failed_pc=0x0c04daa4u; return 0; }
r[4]=0x00000001u;
goto P_0c04daa6;
P_0c04daa6: /* original e202, guest PC 0x0c04daa6 */
if(!s->budget--) { s->failed_pc=0x0c04daa6u; return 0; }
r[2]=0x00000002u;
goto P_0c04daa8;
P_0c04daa8: /* original 6043, guest PC 0x0c04daa8 */
if(!s->budget--) { s->failed_pc=0x0c04daa8u; return 0; }
r[0]=r[4];
goto P_0c04daaa;
P_0c04daaa: /* original 1d42, guest PC 0x0c04daaa */
if(!s->budget--) { s->failed_pc=0x0c04daaau; return 0; }
write(ram,r[13]+8,r[4],4);
goto P_0c04daac;
P_0c04daac: /* original 1d21, guest PC 0x0c04daac */
if(!s->budget--) { s->failed_pc=0x0c04daacu; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c04daae;
P_0c04daae: /* original 1d9b, guest PC 0x0c04daae */
if(!s->budget--) { s->failed_pc=0x0c04daaeu; return 0; }
write(ram,r[13]+44,r[9],4);
goto P_0c04dab0;
P_0c04dab0: /* original d319, guest PC 0x0c04dab0 */
if(!s->budget--) { s->failed_pc=0x0c04dab0u; return 0; }
r[3]=read(ram,0x0c04db18u,4);
goto P_0c04dab2;
P_0c04dab2: /* original 1d3e, guest PC 0x0c04dab2 */
if(!s->budget--) { s->failed_pc=0x0c04dab2u; return 0; }
write(ram,r[13]+56,r[3],4);
goto P_0c04dab4;
P_0c04dab4: /* original 1dbc, guest PC 0x0c04dab4 */
if(!s->budget--) { s->failed_pc=0x0c04dab4u; return 0; }
write(ram,r[13]+48,r[11],4);
goto P_0c04dab6;
P_0c04dab6: /* original 1dea, guest PC 0x0c04dab6 */
if(!s->budget--) { s->failed_pc=0x0c04dab6u; return 0; }
write(ram,r[13]+40,r[14],4);
goto P_0c04dab8;
P_0c04dab8: /* original 81d1, guest PC 0x0c04dab8 */
if(!s->budget--) { s->failed_pc=0x0c04dab8u; return 0; }
write(ram,r[13]+2,r[0],2);
goto P_0c04daba;
P_0c04daba: /* original 60b3, guest PC 0x0c04daba */
if(!s->budget--) { s->failed_pc=0x0c04dabau; return 0; }
r[0]=r[11];
goto P_0c04dabc;
P_0c04dabc: /* original 80d1, guest PC 0x0c04dabc */
if(!s->budget--) { s->failed_pc=0x0c04dabcu; return 0; }
write(ram,r[13]+1,r[0],1);
goto P_0c04dabe;
P_0c04dabe: /* original 53d1, guest PC 0x0c04dabe */
if(!s->budget--) { s->failed_pc=0x0c04dabeu; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c04dac0;
P_0c04dac0: /* original 2f36, guest PC 0x0c04dac0 */
if(!s->budget--) { s->failed_pc=0x0c04dac0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dac2;
P_0c04dac2: /* original d216, guest PC 0x0c04dac2 */
if(!s->budget--) { s->failed_pc=0x0c04dac2u; return 0; }
r[2]=read(ram,0x0c04db1cu,4);
goto P_0c04dac4;
P_0c04dac4: /* original d316, guest PC 0x0c04dac4 */
if(!s->budget--) { s->failed_pc=0x0c04dac4u; return 0; }
r[3]=read(ram,0x0c04db20u,4);
goto P_0c04dac6;
P_0c04dac6: /* original 430b, guest PC 0x0c04dac6 */
if(!s->budget--) { s->failed_pc=0x0c04dac6u; return 0; }
target=r[3];
r[16]=code_base|0x0c04dacau;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dacau) { target=s->pc; goto dispatch; }
goto P_0c04daca;
P_0c04dac8: /* original 2f26, guest PC 0x0c04dac8 */
if(!s->budget--) { s->failed_pc=0x0c04dac8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04daca;
P_0c04daca: /* original 51db, guest PC 0x0c04daca */
if(!s->budget--) { s->failed_pc=0x0c04dacau; return 0; }
r[1]=read(ram,r[13]+44,4);
goto P_0c04dacc;
P_0c04dacc: /* original 2f16, guest PC 0x0c04dacc */
if(!s->budget--) { s->failed_pc=0x0c04daccu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dace;
P_0c04dace: /* original d315, guest PC 0x0c04dace */
if(!s->budget--) { s->failed_pc=0x0c04daceu; return 0; }
r[3]=read(ram,0x0c04db24u,4);
goto P_0c04dad0;
P_0c04dad0: /* original d213, guest PC 0x0c04dad0 */
if(!s->budget--) { s->failed_pc=0x0c04dad0u; return 0; }
r[2]=read(ram,0x0c04db20u,4);
goto P_0c04dad2;
P_0c04dad2: /* original 420b, guest PC 0x0c04dad2 */
if(!s->budget--) { s->failed_pc=0x0c04dad2u; return 0; }
target=r[2];
r[16]=code_base|0x0c04dad6u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dad6u) { target=s->pc; goto dispatch; }
goto P_0c04dad6;
P_0c04dad4: /* original 2f36, guest PC 0x0c04dad4 */
if(!s->budget--) { s->failed_pc=0x0c04dad4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dad6;
P_0c04dad6: /* original 64d3, guest PC 0x0c04dad6 */
if(!s->budget--) { s->failed_pc=0x0c04dad6u; return 0; }
r[4]=r[13];
goto P_0c04dad8;
P_0c04dad8: /* original 7f10, guest PC 0x0c04dad8 */
if(!s->budget--) { s->failed_pc=0x0c04dad8u; return 0; }
r[15]+=0x00000010u;
goto P_0c04dada;
P_0c04dada: /* original a028, guest PC 0x0c04dada */
if(!s->budget--) { s->failed_pc=0x0c04dadau; return 0; }
r[4]+=0x00000010u;
goto P_0c04db2e;
P_0c04dadc: /* original 7410, guest PC 0x0c04dadc */
if(!s->budget--) { s->failed_pc=0x0c04dadcu; return 0; }
r[4]+=0x00000010u;
if(!vf3_matrix_family(0x0c04dadeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04dadeu; return 0; } return 1;
P_0c04db28: /* original 63c4, guest PC 0x0c04db28 */
if(!s->budget--) { s->failed_pc=0x0c04db28u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[12]+=1;
r[3]=tmp;
goto P_0c04db2a;
P_0c04db2a: /* original 2430, guest PC 0x0c04db2a */
if(!s->budget--) { s->failed_pc=0x0c04db2au; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04db2c;
P_0c04db2c: /* original 7401, guest PC 0x0c04db2c */
if(!s->budget--) { s->failed_pc=0x0c04db2cu; return 0; }
r[4]+=0x00000001u;
goto P_0c04db2e;
P_0c04db2e: /* original 62c0, guest PC 0x0c04db2e */
if(!s->budget--) { s->failed_pc=0x0c04db2eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[2]=tmp;
goto P_0c04db30;
P_0c04db30: /* original 2228, guest PC 0x0c04db30 */
if(!s->budget--) { s->failed_pc=0x0c04db30u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04db32;
P_0c04db32: /* original 8bf9, guest PC 0x0c04db32 */
if(!s->budget--) { s->failed_pc=0x0c04db32u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04db28; }
goto P_0c04db34;
P_0c04db34: /* original 24b0, guest PC 0x0c04db34 */
if(!s->budget--) { s->failed_pc=0x0c04db34u; return 0; }
write(ram,r[4],r[11],1);
goto P_0c04db36;
P_0c04db36: /* original 64d3, guest PC 0x0c04db36 */
if(!s->budget--) { s->failed_pc=0x0c04db36u; return 0; }
r[4]=r[13];
goto P_0c04db38;
P_0c04db38: /* original d33a, guest PC 0x0c04db38 */
if(!s->budget--) { s->failed_pc=0x0c04db38u; return 0; }
r[3]=read(ram,0x0c04dc24u,4);
goto P_0c04db3a;
P_0c04db3a: /* original 65f2, guest PC 0x0c04db3a */
if(!s->budget--) { s->failed_pc=0x0c04db3au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04db3c;
P_0c04db3c: /* original 430b, guest PC 0x0c04db3c */
if(!s->budget--) { s->failed_pc=0x0c04db3cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04db40u;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04db40u) { target=s->pc; goto dispatch; }
goto P_0c04db40;
P_0c04db3e: /* original 7420, guest PC 0x0c04db3e */
if(!s->budget--) { s->failed_pc=0x0c04db3eu; return 0; }
r[4]+=0x00000020u;
goto P_0c04db40;
P_0c04db40: /* original e000, guest PC 0x0c04db40 */
if(!s->budget--) { s->failed_pc=0x0c04db40u; return 0; }
r[0]=0x00000000u;
goto P_0c04db42;
P_0c04db42: /* original 2ad2, guest PC 0x0c04db42 */
if(!s->budget--) { s->failed_pc=0x0c04db42u; return 0; }
write(ram,r[10],r[13],4);
goto P_0c04db44;
P_0c04db44: /* original 7f38, guest PC 0x0c04db44 */
if(!s->budget--) { s->failed_pc=0x0c04db44u; return 0; }
r[15]+=0x00000038u;
goto P_0c04db46;
P_0c04db46: /* original 4f16, guest PC 0x0c04db46 */
if(!s->budget--) { s->failed_pc=0x0c04db46u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04db48;
P_0c04db48: /* original 4f26, guest PC 0x0c04db48 */
if(!s->budget--) { s->failed_pc=0x0c04db48u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04db4a;
P_0c04db4a: /* original 69f6, guest PC 0x0c04db4a */
if(!s->budget--) { s->failed_pc=0x0c04db4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04db4c;
P_0c04db4c: /* original 6af6, guest PC 0x0c04db4c */
if(!s->budget--) { s->failed_pc=0x0c04db4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04db4e;
P_0c04db4e: /* original 6bf6, guest PC 0x0c04db4e */
if(!s->budget--) { s->failed_pc=0x0c04db4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04db50;
P_0c04db50: /* original 6cf6, guest PC 0x0c04db50 */
if(!s->budget--) { s->failed_pc=0x0c04db50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04db52;
P_0c04db52: /* original 6df6, guest PC 0x0c04db52 */
if(!s->budget--) { s->failed_pc=0x0c04db52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04db54;
P_0c04db54: /* original 000b, guest PC 0x0c04db54 */
if(!s->budget--) { s->failed_pc=0x0c04db54u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04db56: /* original 6ef6, guest PC 0x0c04db56 */
if(!s->budget--) { s->failed_pc=0x0c04db56u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04db58;
P_0c04db58: /* original 2fe6, guest PC 0x0c04db58 */
if(!s->budget--) { s->failed_pc=0x0c04db58u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db5a;
P_0c04db5a: /* original 2fd6, guest PC 0x0c04db5a */
if(!s->budget--) { s->failed_pc=0x0c04db5au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db5c;
P_0c04db5c: /* original 6d43, guest PC 0x0c04db5c */
if(!s->budget--) { s->failed_pc=0x0c04db5cu; return 0; }
r[13]=r[4];
goto P_0c04db5e;
P_0c04db5e: /* original 2fc6, guest PC 0x0c04db5e */
if(!s->budget--) { s->failed_pc=0x0c04db5eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db60;
P_0c04db60: /* original 6c53, guest PC 0x0c04db60 */
if(!s->budget--) { s->failed_pc=0x0c04db60u; return 0; }
r[12]=r[5];
goto P_0c04db62;
P_0c04db62: /* original 2fb6, guest PC 0x0c04db62 */
if(!s->budget--) { s->failed_pc=0x0c04db62u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db64;
P_0c04db64: /* original 2fa6, guest PC 0x0c04db64 */
if(!s->budget--) { s->failed_pc=0x0c04db64u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db66;
P_0c04db66: /* original 6a73, guest PC 0x0c04db66 */
if(!s->budget--) { s->failed_pc=0x0c04db66u; return 0; }
r[10]=r[7];
goto P_0c04db68;
P_0c04db68: /* original 2f96, guest PC 0x0c04db68 */
if(!s->budget--) { s->failed_pc=0x0c04db68u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db6a;
P_0c04db6a: /* original 4f22, guest PC 0x0c04db6a */
if(!s->budget--) { s->failed_pc=0x0c04db6au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04db6c;
P_0c04db6c: /* original 4f12, guest PC 0x0c04db6c */
if(!s->budget--) { s->failed_pc=0x0c04db6cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04db6e;
P_0c04db6e: /* original 7fd0, guest PC 0x0c04db6e */
if(!s->budget--) { s->failed_pc=0x0c04db6eu; return 0; }
r[15]+=0xffffffd0u;
goto P_0c04db70;
P_0c04db70: /* original 2f62, guest PC 0x0c04db70 */
if(!s->budget--) { s->failed_pc=0x0c04db70u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c04db72;
P_0c04db72: /* original 2f76, guest PC 0x0c04db72 */
if(!s->budget--) { s->failed_pc=0x0c04db72u; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db74;
P_0c04db74: /* original 53f1, guest PC 0x0c04db74 */
if(!s->budget--) { s->failed_pc=0x0c04db74u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c04db76;
P_0c04db76: /* original 2f36, guest PC 0x0c04db76 */
if(!s->budget--) { s->failed_pc=0x0c04db76u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db78;
P_0c04db78: /* original 2fc6, guest PC 0x0c04db78 */
if(!s->budget--) { s->failed_pc=0x0c04db78u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db7a;
P_0c04db7a: /* original 2fd6, guest PC 0x0c04db7a */
if(!s->budget--) { s->failed_pc=0x0c04db7au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db7c;
P_0c04db7c: /* original d22b, guest PC 0x0c04db7c */
if(!s->budget--) { s->failed_pc=0x0c04db7cu; return 0; }
r[2]=read(ram,0x0c04dc2cu,4);
goto P_0c04db7e;
P_0c04db7e: /* original d32a, guest PC 0x0c04db7e */
if(!s->budget--) { s->failed_pc=0x0c04db7eu; return 0; }
r[3]=read(ram,0x0c04dc28u,4);
goto P_0c04db80;
P_0c04db80: /* original 420b, guest PC 0x0c04db80 */
if(!s->budget--) { s->failed_pc=0x0c04db80u; return 0; }
target=r[2];
r[16]=code_base|0x0c04db84u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04db84u) { target=s->pc; goto dispatch; }
goto P_0c04db84;
P_0c04db82: /* original 2f36, guest PC 0x0c04db82 */
if(!s->budget--) { s->failed_pc=0x0c04db82u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db84;
P_0c04db84: /* original eb00, guest PC 0x0c04db84 */
if(!s->budget--) { s->failed_pc=0x0c04db84u; return 0; }
r[11]=0x00000000u;
goto P_0c04db86;
P_0c04db86: /* original 2ab2, guest PC 0x0c04db86 */
if(!s->budget--) { s->failed_pc=0x0c04db86u; return 0; }
write(ram,r[10],r[11],4);
goto P_0c04db88;
P_0c04db88: /* original 9347, guest PC 0x0c04db88 */
if(!s->budget--) { s->failed_pc=0x0c04db88u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dc1au,2);
goto P_0c04db8a;
P_0c04db8a: /* original d029, guest PC 0x0c04db8a */
if(!s->budget--) { s->failed_pc=0x0c04db8au; return 0; }
r[0]=read(ram,0x0c04dc30u,4);
goto P_0c04db8c;
P_0c04db8c: /* original 2d3f, guest PC 0x0c04db8c */
if(!s->budget--) { s->failed_pc=0x0c04db8cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[3]);
goto P_0c04db8e;
P_0c04db8e: /* original 031a, guest PC 0x0c04db8e */
if(!s->budget--) { s->failed_pc=0x0c04db8eu; return 0; }
r[3]=r[19];
goto P_0c04db90;
P_0c04db90: /* original 633f, guest PC 0x0c04db90 */
if(!s->budget--) { s->failed_pc=0x0c04db90u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04db92;
P_0c04db92: /* original 023c, guest PC 0x0c04db92 */
if(!s->budget--) { s->failed_pc=0x0c04db92u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04db94;
P_0c04db94: /* original 2228, guest PC 0x0c04db94 */
if(!s->budget--) { s->failed_pc=0x0c04db94u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04db96;
P_0c04db96: /* original 8d16, guest PC 0x0c04db96 */
if(!s->budget--) { s->failed_pc=0x0c04db96u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000014u;
if(cond) { goto P_0c04dbc6; }
goto P_0c04db9a;
P_0c04db98: /* original 7f14, guest PC 0x0c04db98 */
if(!s->budget--) { s->failed_pc=0x0c04db98u; return 0; }
r[15]+=0x00000014u;
goto P_0c04db9a;
P_0c04db9a: /* original d326, guest PC 0x0c04db9a */
if(!s->budget--) { s->failed_pc=0x0c04db9au; return 0; }
r[3]=read(ram,0x0c04dc34u,4);
goto P_0c04db9c;
P_0c04db9c: /* original 430b, guest PC 0x0c04db9c */
if(!s->budget--) { s->failed_pc=0x0c04db9cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04dba0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dba0u) { target=s->pc; goto dispatch; }
goto P_0c04dba0;
P_0c04db9e: /* original 64d3, guest PC 0x0c04db9e */
if(!s->budget--) { s->failed_pc=0x0c04db9eu; return 0; }
r[4]=r[13];
goto P_0c04dba0;
P_0c04dba0: /* original 2008, guest PC 0x0c04dba0 */
if(!s->budget--) { s->failed_pc=0x0c04dba0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04dba2;
P_0c04dba2: /* original 8b03, guest PC 0x0c04dba2 */
if(!s->budget--) { s->failed_pc=0x0c04dba2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04dbac; }
goto P_0c04dba4;
P_0c04dba4: /* original b993, guest PC 0x0c04dba4 */
if(!s->budget--) { s->failed_pc=0x0c04dba4u; return 0; }
target=code_base|0x0c04ceceu; r[16]=code_base|0x0c04dba8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dba8u) { target=s->pc; goto dispatch; }
goto P_0c04dba8;
P_0c04dba6: /* original 64d3, guest PC 0x0c04dba6 */
if(!s->budget--) { s->failed_pc=0x0c04dba6u; return 0; }
r[4]=r[13];
goto P_0c04dba8;
P_0c04dba8: /* original a00d, guest PC 0x0c04dba8 */
if(!s->budget--) { s->failed_pc=0x0c04dba8u; return 0; }
goto P_0c04dbc6;
P_0c04dbaa: /* original 0009, guest PC 0x0c04dbaa */
if(!s->budget--) { s->failed_pc=0x0c04dbaau; return 0; }
goto P_0c04dbac;
P_0c04dbac: /* original d222, guest PC 0x0c04dbac */
if(!s->budget--) { s->failed_pc=0x0c04dbacu; return 0; }
r[2]=read(ram,0x0c04dc38u,4);
goto P_0c04dbae;
P_0c04dbae: /* original 420b, guest PC 0x0c04dbae */
if(!s->budget--) { s->failed_pc=0x0c04dbaeu; return 0; }
target=r[2];
r[16]=code_base|0x0c04dbb2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dbb2u) { target=s->pc; goto dispatch; }
goto P_0c04dbb2;
P_0c04dbb0: /* original 64d3, guest PC 0x0c04dbb0 */
if(!s->budget--) { s->failed_pc=0x0c04dbb0u; return 0; }
r[4]=r[13];
goto P_0c04dbb2;
P_0c04dbb2: /* original 2008, guest PC 0x0c04dbb2 */
if(!s->budget--) { s->failed_pc=0x0c04dbb2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04dbb4;
P_0c04dbb4: /* original 8907, guest PC 0x0c04dbb4 */
if(!s->budget--) { s->failed_pc=0x0c04dbb4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04dbc6; }
goto P_0c04dbb6;
P_0c04dbb6: /* original 9330, guest PC 0x0c04dbb6 */
if(!s->budget--) { s->failed_pc=0x0c04dbb6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dc1au,2);
goto P_0c04dbb8;
P_0c04dbb8: /* original d020, guest PC 0x0c04dbb8 */
if(!s->budget--) { s->failed_pc=0x0c04dbb8u; return 0; }
r[0]=read(ram,0x0c04dc3cu,4);
goto P_0c04dbba;
P_0c04dbba: /* original 2d3f, guest PC 0x0c04dbba */
if(!s->budget--) { s->failed_pc=0x0c04dbbau; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[3]);
goto P_0c04dbbc;
P_0c04dbbc: /* original 031a, guest PC 0x0c04dbbc */
if(!s->budget--) { s->failed_pc=0x0c04dbbcu; return 0; }
r[3]=r[19];
goto P_0c04dbbe;
P_0c04dbbe: /* original 633f, guest PC 0x0c04dbbe */
if(!s->budget--) { s->failed_pc=0x0c04dbbeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04dbc0;
P_0c04dbc0: /* original 023c, guest PC 0x0c04dbc0 */
if(!s->budget--) { s->failed_pc=0x0c04dbc0u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04dbc2;
P_0c04dbc2: /* original 2228, guest PC 0x0c04dbc2 */
if(!s->budget--) { s->failed_pc=0x0c04dbc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04dbc4;
P_0c04dbc4: /* original 8b02, guest PC 0x0c04dbc4 */
if(!s->budget--) { s->failed_pc=0x0c04dbc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04dbcc; }
goto P_0c04dbc6;
P_0c04dbc6: /* original 9029, guest PC 0x0c04dbc6 */
if(!s->budget--) { s->failed_pc=0x0c04dbc6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dc1cu,2);
goto P_0c04dbc8;
P_0c04dbc8: /* original a078, guest PC 0x0c04dbc8 */
if(!s->budget--) { s->failed_pc=0x0c04dbc8u; return 0; }
goto P_0c04dcbc;
P_0c04dbca: /* original 0009, guest PC 0x0c04dbca */
if(!s->budget--) { s->failed_pc=0x0c04dbcau; return 0; }
goto P_0c04dbcc;
P_0c04dbcc: /* original d31c, guest PC 0x0c04dbcc */
if(!s->budget--) { s->failed_pc=0x0c04dbccu; return 0; }
r[3]=read(ram,0x0c04dc40u,4);
goto P_0c04dbce;
P_0c04dbce: /* original 430b, guest PC 0x0c04dbce */
if(!s->budget--) { s->failed_pc=0x0c04dbceu; return 0; }
target=r[3];
r[16]=code_base|0x0c04dbd2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dbd2u) { target=s->pc; goto dispatch; }
goto P_0c04dbd2;
P_0c04dbd0: /* original 64d3, guest PC 0x0c04dbd0 */
if(!s->budget--) { s->failed_pc=0x0c04dbd0u; return 0; }
r[4]=r[13];
goto P_0c04dbd2;
P_0c04dbd2: /* original 4011, guest PC 0x0c04dbd2 */
if(!s->budget--) { s->failed_pc=0x0c04dbd2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04dbd4;
P_0c04dbd4: /* original 8902, guest PC 0x0c04dbd4 */
if(!s->budget--) { s->failed_pc=0x0c04dbd4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04dbdc; }
goto P_0c04dbd6;
P_0c04dbd6: /* original 9022, guest PC 0x0c04dbd6 */
if(!s->budget--) { s->failed_pc=0x0c04dbd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dc1eu,2);
goto P_0c04dbd8;
P_0c04dbd8: /* original a070, guest PC 0x0c04dbd8 */
if(!s->budget--) { s->failed_pc=0x0c04dbd8u; return 0; }
goto P_0c04dcbc;
P_0c04dbda: /* original 0009, guest PC 0x0c04dbda */
if(!s->budget--) { s->failed_pc=0x0c04dbdau; return 0; }
goto P_0c04dbdc;
P_0c04dbdc: /* original d319, guest PC 0x0c04dbdc */
if(!s->budget--) { s->failed_pc=0x0c04dbdcu; return 0; }
r[3]=read(ram,0x0c04dc44u,4);
goto P_0c04dbde;
P_0c04dbde: /* original 65c3, guest PC 0x0c04dbde */
if(!s->budget--) { s->failed_pc=0x0c04dbdeu; return 0; }
r[5]=r[12];
goto P_0c04dbe0;
P_0c04dbe0: /* original 430b, guest PC 0x0c04dbe0 */
if(!s->budget--) { s->failed_pc=0x0c04dbe0u; return 0; }
target=r[3];
r[16]=code_base|0x0c04dbe4u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dbe4u) { target=s->pc; goto dispatch; }
goto P_0c04dbe4;
P_0c04dbe2: /* original 64d3, guest PC 0x0c04dbe2 */
if(!s->budget--) { s->failed_pc=0x0c04dbe2u; return 0; }
r[4]=r[13];
goto P_0c04dbe4;
P_0c04dbe4: /* original 4011, guest PC 0x0c04dbe4 */
if(!s->budget--) { s->failed_pc=0x0c04dbe4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04dbe6;
P_0c04dbe6: /* original 8b15, guest PC 0x0c04dbe6 */
if(!s->budget--) { s->failed_pc=0x0c04dbe6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04dc14; }
goto P_0c04dbe8;
P_0c04dbe8: /* original d217, guest PC 0x0c04dbe8 */
if(!s->budget--) { s->failed_pc=0x0c04dbe8u; return 0; }
r[2]=read(ram,0x0c04dc48u,4);
goto P_0c04dbea;
P_0c04dbea: /* original 66f3, guest PC 0x0c04dbea */
if(!s->budget--) { s->failed_pc=0x0c04dbeau; return 0; }
r[6]=r[15];
goto P_0c04dbec;
P_0c04dbec: /* original 65c3, guest PC 0x0c04dbec */
if(!s->budget--) { s->failed_pc=0x0c04dbecu; return 0; }
r[5]=r[12];
goto P_0c04dbee;
P_0c04dbee: /* original 7604, guest PC 0x0c04dbee */
if(!s->budget--) { s->failed_pc=0x0c04dbeeu; return 0; }
r[6]+=0x00000004u;
goto P_0c04dbf0;
P_0c04dbf0: /* original 420b, guest PC 0x0c04dbf0 */
if(!s->budget--) { s->failed_pc=0x0c04dbf0u; return 0; }
target=r[2];
r[16]=code_base|0x0c04dbf4u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dbf4u) { target=s->pc; goto dispatch; }
goto P_0c04dbf4;
P_0c04dbf2: /* original 64d3, guest PC 0x0c04dbf2 */
if(!s->budget--) { s->failed_pc=0x0c04dbf2u; return 0; }
r[4]=r[13];
goto P_0c04dbf4;
P_0c04dbf4: /* original 4011, guest PC 0x0c04dbf4 */
if(!s->budget--) { s->failed_pc=0x0c04dbf4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04dbf6;
P_0c04dbf6: /* original 8b07, guest PC 0x0c04dbf6 */
if(!s->budget--) { s->failed_pc=0x0c04dbf6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04dc08; }
goto P_0c04dbf8;
P_0c04dbf8: /* original 65c3, guest PC 0x0c04dbf8 */
if(!s->budget--) { s->failed_pc=0x0c04dbf8u; return 0; }
r[5]=r[12];
goto P_0c04dbfa;
P_0c04dbfa: /* original b58a, guest PC 0x0c04dbfa */
if(!s->budget--) { s->failed_pc=0x0c04dbfau; return 0; }
target=code_base|0x0c04e712u; r[16]=code_base|0x0c04dbfeu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dbfeu) { target=s->pc; goto dispatch; }
goto P_0c04dbfe;
P_0c04dbfc: /* original 64d3, guest PC 0x0c04dbfc */
if(!s->budget--) { s->failed_pc=0x0c04dbfcu; return 0; }
r[4]=r[13];
goto P_0c04dbfe;
P_0c04dbfe: /* original 4011, guest PC 0x0c04dbfe */
if(!s->budget--) { s->failed_pc=0x0c04dbfeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04dc00;
P_0c04dc00: /* original 8d02, guest PC 0x0c04dc00 */
if(!s->budget--) { s->failed_pc=0x0c04dc00u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c04dc08; }
goto P_0c04dc04;
P_0c04dc02: /* original 6403, guest PC 0x0c04dc02 */
if(!s->budget--) { s->failed_pc=0x0c04dc02u; return 0; }
r[4]=r[0];
goto P_0c04dc04;
P_0c04dc04: /* original a05a, guest PC 0x0c04dc04 */
if(!s->budget--) { s->failed_pc=0x0c04dc04u; return 0; }
r[0]=r[4];
goto P_0c04dcbc;
P_0c04dc06: /* original 6043, guest PC 0x0c04dc06 */
if(!s->budget--) { s->failed_pc=0x0c04dc06u; return 0; }
r[0]=r[4];
goto P_0c04dc08;
P_0c04dc08: /* original d210, guest PC 0x0c04dc08 */
if(!s->budget--) { s->failed_pc=0x0c04dc08u; return 0; }
r[2]=read(ram,0x0c04dc4cu,4);
goto P_0c04dc0a;
P_0c04dc0a: /* original 420b, guest PC 0x0c04dc0a */
if(!s->budget--) { s->failed_pc=0x0c04dc0au; return 0; }
target=r[2];
r[16]=code_base|0x0c04dc0eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dc0eu) { target=s->pc; goto dispatch; }
goto P_0c04dc0e;
P_0c04dc0c: /* original 64d3, guest PC 0x0c04dc0c */
if(!s->budget--) { s->failed_pc=0x0c04dc0cu; return 0; }
r[4]=r[13];
goto P_0c04dc0e;
P_0c04dc0e: /* original 6903, guest PC 0x0c04dc0e */
if(!s->budget--) { s->failed_pc=0x0c04dc0eu; return 0; }
r[9]=r[0];
goto P_0c04dc10;
P_0c04dc10: /* original 4911, guest PC 0x0c04dc10 */
if(!s->budget--) { s->failed_pc=0x0c04dc10u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=0)!=0);
goto P_0c04dc12;
P_0c04dc12: /* original 891d, guest PC 0x0c04dc12 */
if(!s->budget--) { s->failed_pc=0x0c04dc12u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04dc50; }
goto P_0c04dc14;
P_0c04dc14: /* original 9004, guest PC 0x0c04dc14 */
if(!s->budget--) { s->failed_pc=0x0c04dc14u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dc20u,2);
goto P_0c04dc16;
P_0c04dc16: /* original a051, guest PC 0x0c04dc16 */
if(!s->budget--) { s->failed_pc=0x0c04dc16u; return 0; }
goto P_0c04dcbc;
P_0c04dc18: /* original 0009, guest PC 0x0c04dc18 */
if(!s->budget--) { s->failed_pc=0x0c04dc18u; return 0; }
if(!vf3_matrix_family(0x0c04dc1au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04dc1au; return 0; } return 1;
P_0c04dc50: /* original d240, guest PC 0x0c04dc50 */
if(!s->budget--) { s->failed_pc=0x0c04dc50u; return 0; }
r[2]=read(ram,0x0c04dd54u,4);
goto P_0c04dc52;
P_0c04dc52: /* original 6593, guest PC 0x0c04dc52 */
if(!s->budget--) { s->failed_pc=0x0c04dc52u; return 0; }
r[5]=r[9];
goto P_0c04dc54;
P_0c04dc54: /* original 420b, guest PC 0x0c04dc54 */
if(!s->budget--) { s->failed_pc=0x0c04dc54u; return 0; }
target=r[2];
r[16]=code_base|0x0c04dc58u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dc58u) { target=s->pc; goto dispatch; }
goto P_0c04dc58;
P_0c04dc56: /* original 64d3, guest PC 0x0c04dc56 */
if(!s->budget--) { s->failed_pc=0x0c04dc56u; return 0; }
r[4]=r[13];
goto P_0c04dc58;
P_0c04dc58: /* original d33f, guest PC 0x0c04dc58 */
if(!s->budget--) { s->failed_pc=0x0c04dc58u; return 0; }
r[3]=read(ram,0x0c04dd58u,4);
goto P_0c04dc5a;
P_0c04dc5a: /* original 430b, guest PC 0x0c04dc5a */
if(!s->budget--) { s->failed_pc=0x0c04dc5au; return 0; }
target=r[3];
r[16]=code_base|0x0c04dc5eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dc5eu) { target=s->pc; goto dispatch; }
goto P_0c04dc5e;
P_0c04dc5c: /* original 64d3, guest PC 0x0c04dc5c */
if(!s->budget--) { s->failed_pc=0x0c04dc5cu; return 0; }
r[4]=r[13];
goto P_0c04dc5e;
P_0c04dc5e: /* original 6e03, guest PC 0x0c04dc5e */
if(!s->budget--) { s->failed_pc=0x0c04dc5eu; return 0; }
r[14]=r[0];
goto P_0c04dc60;
P_0c04dc60: /* original 2ee8, guest PC 0x0c04dc60 */
if(!s->budget--) { s->failed_pc=0x0c04dc60u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c04dc62;
P_0c04dc62: /* original 8b02, guest PC 0x0c04dc62 */
if(!s->budget--) { s->failed_pc=0x0c04dc62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04dc6a; }
goto P_0c04dc64;
P_0c04dc64: /* original 9071, guest PC 0x0c04dc64 */
if(!s->budget--) { s->failed_pc=0x0c04dc64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dd4au,2);
goto P_0c04dc66;
P_0c04dc66: /* original a029, guest PC 0x0c04dc66 */
if(!s->budget--) { s->failed_pc=0x0c04dc66u; return 0; }
goto P_0c04dcbc;
P_0c04dc68: /* original 0009, guest PC 0x0c04dc68 */
if(!s->budget--) { s->failed_pc=0x0c04dc68u; return 0; }
goto P_0c04dc6a;
P_0c04dc6a: /* original e301, guest PC 0x0c04dc6a */
if(!s->budget--) { s->failed_pc=0x0c04dc6au; return 0; }
r[3]=0x00000001u;
goto P_0c04dc6c;
P_0c04dc6c: /* original 60b3, guest PC 0x0c04dc6c */
if(!s->budget--) { s->failed_pc=0x0c04dc6cu; return 0; }
r[0]=r[11];
goto P_0c04dc6e;
P_0c04dc6e: /* original 1eb2, guest PC 0x0c04dc6e */
if(!s->budget--) { s->failed_pc=0x0c04dc6eu; return 0; }
write(ram,r[14]+8,r[11],4);
goto P_0c04dc70;
P_0c04dc70: /* original 1e31, guest PC 0x0c04dc70 */
if(!s->budget--) { s->failed_pc=0x0c04dc70u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c04dc72;
P_0c04dc72: /* original 1e9b, guest PC 0x0c04dc72 */
if(!s->budget--) { s->failed_pc=0x0c04dc72u; return 0; }
write(ram,r[14]+44,r[9],4);
goto P_0c04dc74;
P_0c04dc74: /* original d239, guest PC 0x0c04dc74 */
if(!s->budget--) { s->failed_pc=0x0c04dc74u; return 0; }
r[2]=read(ram,0x0c04dd5cu,4);
goto P_0c04dc76;
P_0c04dc76: /* original 1e2e, guest PC 0x0c04dc76 */
if(!s->budget--) { s->failed_pc=0x0c04dc76u; return 0; }
write(ram,r[14]+56,r[2],4);
goto P_0c04dc78;
P_0c04dc78: /* original 1ebc, guest PC 0x0c04dc78 */
if(!s->budget--) { s->failed_pc=0x0c04dc78u; return 0; }
write(ram,r[14]+48,r[11],4);
goto P_0c04dc7a;
P_0c04dc7a: /* original 1eda, guest PC 0x0c04dc7a */
if(!s->budget--) { s->failed_pc=0x0c04dc7au; return 0; }
write(ram,r[14]+40,r[13],4);
goto P_0c04dc7c;
P_0c04dc7c: /* original 81e1, guest PC 0x0c04dc7c */
if(!s->budget--) { s->failed_pc=0x0c04dc7cu; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c04dc7e;
P_0c04dc7e: /* original 80e1, guest PC 0x0c04dc7e */
if(!s->budget--) { s->failed_pc=0x0c04dc7eu; return 0; }
write(ram,r[14]+1,r[0],1);
goto P_0c04dc80;
P_0c04dc80: /* original 53e1, guest PC 0x0c04dc80 */
if(!s->budget--) { s->failed_pc=0x0c04dc80u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c04dc82;
P_0c04dc82: /* original 2f36, guest PC 0x0c04dc82 */
if(!s->budget--) { s->failed_pc=0x0c04dc82u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dc84;
P_0c04dc84: /* original d337, guest PC 0x0c04dc84 */
if(!s->budget--) { s->failed_pc=0x0c04dc84u; return 0; }
r[3]=read(ram,0x0c04dd64u,4);
goto P_0c04dc86;
P_0c04dc86: /* original d236, guest PC 0x0c04dc86 */
if(!s->budget--) { s->failed_pc=0x0c04dc86u; return 0; }
r[2]=read(ram,0x0c04dd60u,4);
goto P_0c04dc88;
P_0c04dc88: /* original 430b, guest PC 0x0c04dc88 */
if(!s->budget--) { s->failed_pc=0x0c04dc88u; return 0; }
target=r[3];
r[16]=code_base|0x0c04dc8cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dc8cu) { target=s->pc; goto dispatch; }
goto P_0c04dc8c;
P_0c04dc8a: /* original 2f26, guest PC 0x0c04dc8a */
if(!s->budget--) { s->failed_pc=0x0c04dc8au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dc8c;
P_0c04dc8c: /* original 51eb, guest PC 0x0c04dc8c */
if(!s->budget--) { s->failed_pc=0x0c04dc8cu; return 0; }
r[1]=read(ram,r[14]+44,4);
goto P_0c04dc8e;
P_0c04dc8e: /* original 2f16, guest PC 0x0c04dc8e */
if(!s->budget--) { s->failed_pc=0x0c04dc8eu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dc90;
P_0c04dc90: /* original d335, guest PC 0x0c04dc90 */
if(!s->budget--) { s->failed_pc=0x0c04dc90u; return 0; }
r[3]=read(ram,0x0c04dd68u,4);
goto P_0c04dc92;
P_0c04dc92: /* original d234, guest PC 0x0c04dc92 */
if(!s->budget--) { s->failed_pc=0x0c04dc92u; return 0; }
r[2]=read(ram,0x0c04dd64u,4);
goto P_0c04dc94;
P_0c04dc94: /* original 420b, guest PC 0x0c04dc94 */
if(!s->budget--) { s->failed_pc=0x0c04dc94u; return 0; }
target=r[2];
r[16]=code_base|0x0c04dc98u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dc98u) { target=s->pc; goto dispatch; }
goto P_0c04dc98;
P_0c04dc96: /* original 2f36, guest PC 0x0c04dc96 */
if(!s->budget--) { s->failed_pc=0x0c04dc96u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dc98;
P_0c04dc98: /* original 64e3, guest PC 0x0c04dc98 */
if(!s->budget--) { s->failed_pc=0x0c04dc98u; return 0; }
r[4]=r[14];
goto P_0c04dc9a;
P_0c04dc9a: /* original 7f10, guest PC 0x0c04dc9a */
if(!s->budget--) { s->failed_pc=0x0c04dc9au; return 0; }
r[15]+=0x00000010u;
goto P_0c04dc9c;
P_0c04dc9c: /* original a003, guest PC 0x0c04dc9c */
if(!s->budget--) { s->failed_pc=0x0c04dc9cu; return 0; }
r[4]+=0x00000010u;
goto P_0c04dca6;
P_0c04dc9e: /* original 7410, guest PC 0x0c04dc9e */
if(!s->budget--) { s->failed_pc=0x0c04dc9eu; return 0; }
r[4]+=0x00000010u;
goto P_0c04dca0;
P_0c04dca0: /* original 63c4, guest PC 0x0c04dca0 */
if(!s->budget--) { s->failed_pc=0x0c04dca0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[12]+=1;
r[3]=tmp;
goto P_0c04dca2;
P_0c04dca2: /* original 2430, guest PC 0x0c04dca2 */
if(!s->budget--) { s->failed_pc=0x0c04dca2u; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04dca4;
P_0c04dca4: /* original 7401, guest PC 0x0c04dca4 */
if(!s->budget--) { s->failed_pc=0x0c04dca4u; return 0; }
r[4]+=0x00000001u;
goto P_0c04dca6;
P_0c04dca6: /* original 62c0, guest PC 0x0c04dca6 */
if(!s->budget--) { s->failed_pc=0x0c04dca6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[2]=tmp;
goto P_0c04dca8;
P_0c04dca8: /* original 2228, guest PC 0x0c04dca8 */
if(!s->budget--) { s->failed_pc=0x0c04dca8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04dcaa;
P_0c04dcaa: /* original 8bf9, guest PC 0x0c04dcaa */
if(!s->budget--) { s->failed_pc=0x0c04dcaau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04dca0; }
goto P_0c04dcac;
P_0c04dcac: /* original 24b0, guest PC 0x0c04dcac */
if(!s->budget--) { s->failed_pc=0x0c04dcacu; return 0; }
write(ram,r[4],r[11],1);
goto P_0c04dcae;
P_0c04dcae: /* original 64e3, guest PC 0x0c04dcae */
if(!s->budget--) { s->failed_pc=0x0c04dcaeu; return 0; }
r[4]=r[14];
goto P_0c04dcb0;
P_0c04dcb0: /* original d32e, guest PC 0x0c04dcb0 */
if(!s->budget--) { s->failed_pc=0x0c04dcb0u; return 0; }
r[3]=read(ram,0x0c04dd6cu,4);
goto P_0c04dcb2;
P_0c04dcb2: /* original 65f2, guest PC 0x0c04dcb2 */
if(!s->budget--) { s->failed_pc=0x0c04dcb2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04dcb4;
P_0c04dcb4: /* original 430b, guest PC 0x0c04dcb4 */
if(!s->budget--) { s->failed_pc=0x0c04dcb4u; return 0; }
target=r[3];
r[16]=code_base|0x0c04dcb8u;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dcb8u) { target=s->pc; goto dispatch; }
goto P_0c04dcb8;
P_0c04dcb6: /* original 7420, guest PC 0x0c04dcb6 */
if(!s->budget--) { s->failed_pc=0x0c04dcb6u; return 0; }
r[4]+=0x00000020u;
goto P_0c04dcb8;
P_0c04dcb8: /* original e000, guest PC 0x0c04dcb8 */
if(!s->budget--) { s->failed_pc=0x0c04dcb8u; return 0; }
r[0]=0x00000000u;
goto P_0c04dcba;
P_0c04dcba: /* original 2ae2, guest PC 0x0c04dcba */
if(!s->budget--) { s->failed_pc=0x0c04dcbau; return 0; }
write(ram,r[10],r[14],4);
goto P_0c04dcbc;
P_0c04dcbc: /* original 7f30, guest PC 0x0c04dcbc */
if(!s->budget--) { s->failed_pc=0x0c04dcbcu; return 0; }
r[15]+=0x00000030u;
goto P_0c04dcbe;
P_0c04dcbe: /* original 4f16, guest PC 0x0c04dcbe */
if(!s->budget--) { s->failed_pc=0x0c04dcbeu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04dcc0;
P_0c04dcc0: /* original 4f26, guest PC 0x0c04dcc0 */
if(!s->budget--) { s->failed_pc=0x0c04dcc0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04dcc2;
P_0c04dcc2: /* original 69f6, guest PC 0x0c04dcc2 */
if(!s->budget--) { s->failed_pc=0x0c04dcc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04dcc4;
P_0c04dcc4: /* original 6af6, guest PC 0x0c04dcc4 */
if(!s->budget--) { s->failed_pc=0x0c04dcc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04dcc6;
P_0c04dcc6: /* original 6bf6, guest PC 0x0c04dcc6 */
if(!s->budget--) { s->failed_pc=0x0c04dcc6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04dcc8;
P_0c04dcc8: /* original 6cf6, guest PC 0x0c04dcc8 */
if(!s->budget--) { s->failed_pc=0x0c04dcc8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04dcca;
P_0c04dcca: /* original 6df6, guest PC 0x0c04dcca */
if(!s->budget--) { s->failed_pc=0x0c04dccau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04dccc;
P_0c04dccc: /* original 000b, guest PC 0x0c04dccc */
if(!s->budget--) { s->failed_pc=0x0c04dcccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04dcce: /* original 6ef6, guest PC 0x0c04dcce */
if(!s->budget--) { s->failed_pc=0x0c04dcceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04dcd0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04dcd0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
