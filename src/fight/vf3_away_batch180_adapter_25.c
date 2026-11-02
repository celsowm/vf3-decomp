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
int vf3_away_batch180_adapter_25(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a2d48u: goto P_0c0a2d48;
case 0x0c0a2d4au: goto P_0c0a2d4a;
case 0x0c0a2d4cu: goto P_0c0a2d4c;
case 0x0c0a2d4eu: goto P_0c0a2d4e;
case 0x0c0a2d50u: goto P_0c0a2d50;
case 0x0c0a2d52u: goto P_0c0a2d52;
case 0x0c0a2d54u: goto P_0c0a2d54;
case 0x0c0a2d56u: goto P_0c0a2d56;
case 0x0c0a2d58u: goto P_0c0a2d58;
case 0x0c0a2d5au: goto P_0c0a2d5a;
case 0x0c0a2d5cu: goto P_0c0a2d5c;
case 0x0c0a2d5eu: goto P_0c0a2d5e;
case 0x0c0a2d60u: goto P_0c0a2d60;
case 0x0c0a2d62u: goto P_0c0a2d62;
case 0x0c0a2d64u: goto P_0c0a2d64;
case 0x0c0a2d66u: goto P_0c0a2d66;
case 0x0c0a2d68u: goto P_0c0a2d68;
case 0x0c0a2d6au: goto P_0c0a2d6a;
case 0x0c0a2d6cu: goto P_0c0a2d6c;
case 0x0c0a2d6eu: goto P_0c0a2d6e;
case 0x0c0a2d70u: goto P_0c0a2d70;
case 0x0c0a2d72u: goto P_0c0a2d72;
case 0x0c0a2d74u: goto P_0c0a2d74;
case 0x0c0a2d76u: goto P_0c0a2d76;
case 0x0c0a2d78u: goto P_0c0a2d78;
case 0x0c0a2d7au: goto P_0c0a2d7a;
case 0x0c0a2d7cu: goto P_0c0a2d7c;
case 0x0c0a2d7eu: goto P_0c0a2d7e;
case 0x0c0a2d80u: goto P_0c0a2d80;
case 0x0c0a2d82u: goto P_0c0a2d82;
case 0x0c0a2d84u: goto P_0c0a2d84;
case 0x0c0a2d86u: goto P_0c0a2d86;
case 0x0c0a2d88u: goto P_0c0a2d88;
case 0x0c0a2d8au: goto P_0c0a2d8a;
case 0x0c0a2d8cu: goto P_0c0a2d8c;
case 0x0c0a2d8eu: goto P_0c0a2d8e;
case 0x0c0a2d90u: goto P_0c0a2d90;
case 0x0c0a2d92u: goto P_0c0a2d92;
case 0x0c0a2d94u: goto P_0c0a2d94;
case 0x0c0a2d96u: goto P_0c0a2d96;
case 0x0c0a2d98u: goto P_0c0a2d98;
case 0x0c0a2d9au: goto P_0c0a2d9a;
case 0x0c0a2d9cu: goto P_0c0a2d9c;
case 0x0c0a2d9eu: goto P_0c0a2d9e;
case 0x0c0a2da0u: goto P_0c0a2da0;
case 0x0c0a2da2u: goto P_0c0a2da2;
case 0x0c0a2da4u: goto P_0c0a2da4;
case 0x0c0a2da6u: goto P_0c0a2da6;
case 0x0c0a2da8u: goto P_0c0a2da8;
case 0x0c0a2daau: goto P_0c0a2daa;
case 0x0c0a2dacu: goto P_0c0a2dac;
case 0x0c0a2daeu: goto P_0c0a2dae;
case 0x0c0a2db0u: goto P_0c0a2db0;
case 0x0c0a2db2u: goto P_0c0a2db2;
case 0x0c0a2db4u: goto P_0c0a2db4;
case 0x0c0a2db6u: goto P_0c0a2db6;
case 0x0c0a2db8u: goto P_0c0a2db8;
case 0x0c0a2dbau: goto P_0c0a2dba;
case 0x0c0a2dbcu: goto P_0c0a2dbc;
case 0x0c0a2dbeu: goto P_0c0a2dbe;
case 0x0c0a2dc0u: goto P_0c0a2dc0;
case 0x0c0a2dc2u: goto P_0c0a2dc2;
case 0x0c0a2dc4u: goto P_0c0a2dc4;
case 0x0c0a2dc6u: goto P_0c0a2dc6;
case 0x0c0a2dc8u: goto P_0c0a2dc8;
case 0x0c0a2dcau: goto P_0c0a2dca;
case 0x0c0a2dccu: goto P_0c0a2dcc;
case 0x0c0a2dceu: goto P_0c0a2dce;
case 0x0c0a2dd0u: goto P_0c0a2dd0;
case 0x0c0a2dd2u: goto P_0c0a2dd2;
case 0x0c0a2dd4u: goto P_0c0a2dd4;
case 0x0c0a2dd6u: goto P_0c0a2dd6;
case 0x0c0a2dd8u: goto P_0c0a2dd8;
case 0x0c0a2ddau: goto P_0c0a2dda;
case 0x0c0a2ddcu: goto P_0c0a2ddc;
case 0x0c0a2ddeu: goto P_0c0a2dde;
case 0x0c0a2de0u: goto P_0c0a2de0;
case 0x0c0a2de2u: goto P_0c0a2de2;
case 0x0c0a2de4u: goto P_0c0a2de4;
case 0x0c0a2de6u: goto P_0c0a2de6;
case 0x0c0a2de8u: goto P_0c0a2de8;
case 0x0c0a2deau: goto P_0c0a2dea;
case 0x0c0a2decu: goto P_0c0a2dec;
case 0x0c0a2deeu: goto P_0c0a2dee;
case 0x0c0a2df0u: goto P_0c0a2df0;
case 0x0c0a2df2u: goto P_0c0a2df2;
case 0x0c0a2df4u: goto P_0c0a2df4;
case 0x0c0a2df6u: goto P_0c0a2df6;
case 0x0c0a7794u: goto P_0c0a7794;
case 0x0c0a7796u: goto P_0c0a7796;
case 0x0c0a7798u: goto P_0c0a7798;
case 0x0c0a779au: goto P_0c0a779a;
case 0x0c0a779cu: goto P_0c0a779c;
case 0x0c0a779eu: goto P_0c0a779e;
case 0x0c0a77a0u: goto P_0c0a77a0;
case 0x0c0a77a2u: goto P_0c0a77a2;
case 0x0c0a77a4u: goto P_0c0a77a4;
case 0x0c0a77a6u: goto P_0c0a77a6;
case 0x0c0a77a8u: goto P_0c0a77a8;
case 0x0c0a77aau: goto P_0c0a77aa;
case 0x0c0a77acu: goto P_0c0a77ac;
case 0x0c0a77aeu: goto P_0c0a77ae;
case 0x0c0a77b0u: goto P_0c0a77b0;
case 0x0c0a77b2u: goto P_0c0a77b2;
case 0x0c0a77b4u: goto P_0c0a77b4;
case 0x0c0a77b6u: goto P_0c0a77b6;
case 0x0c0a77b8u: goto P_0c0a77b8;
case 0x0c0a77bau: goto P_0c0a77ba;
case 0x0c0a77bcu: goto P_0c0a77bc;
case 0x0c0a77beu: goto P_0c0a77be;
case 0x0c0a77c0u: goto P_0c0a77c0;
case 0x0c0a77c2u: goto P_0c0a77c2;
case 0x0c0a77c4u: goto P_0c0a77c4;
case 0x0c0a77c6u: goto P_0c0a77c6;
case 0x0c0a77c8u: goto P_0c0a77c8;
case 0x0c0a77cau: goto P_0c0a77ca;
case 0x0c0a77ccu: goto P_0c0a77cc;
case 0x0c0a77ceu: goto P_0c0a77ce;
case 0x0c0a77d0u: goto P_0c0a77d0;
case 0x0c0a77d2u: goto P_0c0a77d2;
case 0x0c0a77d4u: goto P_0c0a77d4;
case 0x0c0a77d6u: goto P_0c0a77d6;
case 0x0c0a77d8u: goto P_0c0a77d8;
case 0x0c0a77dau: goto P_0c0a77da;
case 0x0c0a77dcu: goto P_0c0a77dc;
case 0x0c0a77e2u: goto P_0c0a77e2;
case 0x0c0a77e4u: goto P_0c0a77e4;
case 0x0c0a77e6u: goto P_0c0a77e6;
case 0x0c0a77e8u: goto P_0c0a77e8;
case 0x0c0a77eau: goto P_0c0a77ea;
case 0x0c0a77ecu: goto P_0c0a77ec;
case 0x0c0a77eeu: goto P_0c0a77ee;
case 0x0c0a77f0u: goto P_0c0a77f0;
case 0x0c0a77f2u: goto P_0c0a77f2;
case 0x0c0a77f4u: goto P_0c0a77f4;
case 0x0c0a77f6u: goto P_0c0a77f6;
case 0x0c0a77f8u: goto P_0c0a77f8;
case 0x0c0a77fau: goto P_0c0a77fa;
case 0x0c0a77fcu: goto P_0c0a77fc;
case 0x0c0a77feu: goto P_0c0a77fe;
case 0x0c0a7800u: goto P_0c0a7800;
case 0x0c0a7802u: goto P_0c0a7802;
case 0x0c0a7804u: goto P_0c0a7804;
case 0x0c0a7806u: goto P_0c0a7806;
case 0x0c0a7808u: goto P_0c0a7808;
case 0x0c0a780au: goto P_0c0a780a;
case 0x0c0a780cu: goto P_0c0a780c;
case 0x0c0a780eu: goto P_0c0a780e;
case 0x0c0a7810u: goto P_0c0a7810;
case 0x0c0a7812u: goto P_0c0a7812;
case 0x0c0a7814u: goto P_0c0a7814;
case 0x0c0a7816u: goto P_0c0a7816;
case 0x0c0a7818u: goto P_0c0a7818;
case 0x0c0a781au: goto P_0c0a781a;
case 0x0c0a781cu: goto P_0c0a781c;
case 0x0c0a781eu: goto P_0c0a781e;
case 0x0c0a7850u: goto P_0c0a7850;
case 0x0c0a7852u: goto P_0c0a7852;
case 0x0c0a7854u: goto P_0c0a7854;
case 0x0c0a7856u: goto P_0c0a7856;
case 0x0c0a7858u: goto P_0c0a7858;
case 0x0c0a785au: goto P_0c0a785a;
case 0x0c0a785cu: goto P_0c0a785c;
case 0x0c0a785eu: goto P_0c0a785e;
case 0x0c0a7860u: goto P_0c0a7860;
case 0x0c0a7862u: goto P_0c0a7862;
case 0x0c0a7864u: goto P_0c0a7864;
case 0x0c0a7866u: goto P_0c0a7866;
case 0x0c0a7868u: goto P_0c0a7868;
case 0x0c0a786au: goto P_0c0a786a;
case 0x0c0a786cu: goto P_0c0a786c;
case 0x0c0a786eu: goto P_0c0a786e;
case 0x0c0a7870u: goto P_0c0a7870;
case 0x0c0a7872u: goto P_0c0a7872;
case 0x0c0a7874u: goto P_0c0a7874;
case 0x0c0a7876u: goto P_0c0a7876;
case 0x0c0a7878u: goto P_0c0a7878;
case 0x0c0a787au: goto P_0c0a787a;
case 0x0c0a787cu: goto P_0c0a787c;
case 0x0c0a787eu: goto P_0c0a787e;
case 0x0c0a7880u: goto P_0c0a7880;
case 0x0c0a7882u: goto P_0c0a7882;
case 0x0c0a7884u: goto P_0c0a7884;
case 0x0c0a7886u: goto P_0c0a7886;
case 0x0c0a7888u: goto P_0c0a7888;
case 0x0c0a788au: goto P_0c0a788a;
case 0x0c0a788cu: goto P_0c0a788c;
case 0x0c0a788eu: goto P_0c0a788e;
case 0x0c0a7890u: goto P_0c0a7890;
case 0x0c0a7892u: goto P_0c0a7892;
case 0x0c0a7894u: goto P_0c0a7894;
case 0x0c0a7896u: goto P_0c0a7896;
case 0x0c0a7898u: goto P_0c0a7898;
case 0x0c0a789au: goto P_0c0a789a;
case 0x0c0a789cu: goto P_0c0a789c;
case 0x0c0a789eu: goto P_0c0a789e;
case 0x0c0a78a0u: goto P_0c0a78a0;
case 0x0c0a78a2u: goto P_0c0a78a2;
case 0x0c0a78a4u: goto P_0c0a78a4;
case 0x0c0a78a6u: goto P_0c0a78a6;
case 0x0c0a78a8u: goto P_0c0a78a8;
case 0x0c0a78aau: goto P_0c0a78aa;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a2d48: /* original 2fe6, guest PC 0x0c0a2d48 */
if(!s->budget--) { s->failed_pc=0x0c0a2d48u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2d4a;
P_0c0a2d4a: /* original 6e43, guest PC 0x0c0a2d4a */
if(!s->budget--) { s->failed_pc=0x0c0a2d4au; return 0; }
r[14]=r[4];
goto P_0c0a2d4c;
P_0c0a2d4c: /* original 2fd6, guest PC 0x0c0a2d4c */
if(!s->budget--) { s->failed_pc=0x0c0a2d4cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2d4e;
P_0c0a2d4e: /* original 6d53, guest PC 0x0c0a2d4e */
if(!s->budget--) { s->failed_pc=0x0c0a2d4eu; return 0; }
r[13]=r[5];
goto P_0c0a2d50;
P_0c0a2d50: /* original 4f22, guest PC 0x0c0a2d50 */
if(!s->budget--) { s->failed_pc=0x0c0a2d50u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2d52;
P_0c0a2d52: /* original 53e1, guest PC 0x0c0a2d52 */
if(!s->budget--) { s->failed_pc=0x0c0a2d52u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2d54;
P_0c0a2d54: /* original 2338, guest PC 0x0c0a2d54 */
if(!s->budget--) { s->failed_pc=0x0c0a2d54u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2d56;
P_0c0a2d56: /* original 8933, guest PC 0x0c0a2d56 */
if(!s->budget--) { s->failed_pc=0x0c0a2d56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2dc0; }
goto P_0c0a2d58;
P_0c0a2d58: /* original 53e1, guest PC 0x0c0a2d58 */
if(!s->budget--) { s->failed_pc=0x0c0a2d58u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2d5a;
P_0c0a2d5a: /* original 33d2, guest PC 0x0c0a2d5a */
if(!s->budget--) { s->failed_pc=0x0c0a2d5au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2d5c;
P_0c0a2d5c: /* original 8930, guest PC 0x0c0a2d5c */
if(!s->budget--) { s->failed_pc=0x0c0a2d5cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2dc0; }
goto P_0c0a2d5e;
P_0c0a2d5e: /* original 51e1, guest PC 0x0c0a2d5e */
if(!s->budget--) { s->failed_pc=0x0c0a2d5eu; return 0; }
r[1]=read(ram,r[14]+4,4);
goto P_0c0a2d60;
P_0c0a2d60: /* original 31dc, guest PC 0x0c0a2d60 */
if(!s->budget--) { s->failed_pc=0x0c0a2d60u; return 0; }
r[1]+=r[13];
goto P_0c0a2d62;
P_0c0a2d62: /* original 6313, guest PC 0x0c0a2d62 */
if(!s->budget--) { s->failed_pc=0x0c0a2d62u; return 0; }
r[3]=r[1];
goto P_0c0a2d64;
P_0c0a2d64: /* original 1e11, guest PC 0x0c0a2d64 */
if(!s->budget--) { s->failed_pc=0x0c0a2d64u; return 0; }
write(ram,r[14]+4,r[1],4);
goto P_0c0a2d66;
P_0c0a2d66: /* original 5231, guest PC 0x0c0a2d66 */
if(!s->budget--) { s->failed_pc=0x0c0a2d66u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c0a2d68;
P_0c0a2d68: /* original 2228, guest PC 0x0c0a2d68 */
if(!s->budget--) { s->failed_pc=0x0c0a2d68u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2d6a;
P_0c0a2d6a: /* original 8907, guest PC 0x0c0a2d6a */
if(!s->budget--) { s->failed_pc=0x0c0a2d6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d7c; }
goto P_0c0a2d6c;
P_0c0a2d6c: /* original 52e1, guest PC 0x0c0a2d6c */
if(!s->budget--) { s->failed_pc=0x0c0a2d6cu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0a2d6e;
P_0c0a2d6e: /* original 5321, guest PC 0x0c0a2d6e */
if(!s->budget--) { s->failed_pc=0x0c0a2d6eu; return 0; }
r[3]=read(ram,r[2]+4,4);
goto P_0c0a2d70;
P_0c0a2d70: /* original 33d2, guest PC 0x0c0a2d70 */
if(!s->budget--) { s->failed_pc=0x0c0a2d70u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2d72;
P_0c0a2d72: /* original 8903, guest PC 0x0c0a2d72 */
if(!s->budget--) { s->failed_pc=0x0c0a2d72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d7c; }
goto P_0c0a2d74;
P_0c0a2d74: /* original 54e1, guest PC 0x0c0a2d74 */
if(!s->budget--) { s->failed_pc=0x0c0a2d74u; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c0a2d76;
P_0c0a2d76: /* original 5341, guest PC 0x0c0a2d76 */
if(!s->budget--) { s->failed_pc=0x0c0a2d76u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0a2d78;
P_0c0a2d78: /* original 33dc, guest PC 0x0c0a2d78 */
if(!s->budget--) { s->failed_pc=0x0c0a2d78u; return 0; }
r[3]+=r[13];
goto P_0c0a2d7a;
P_0c0a2d7a: /* original 1431, guest PC 0x0c0a2d7a */
if(!s->budget--) { s->failed_pc=0x0c0a2d7au; return 0; }
write(ram,r[4]+4,r[3],4);
goto P_0c0a2d7c;
P_0c0a2d7c: /* original 52e1, guest PC 0x0c0a2d7c */
if(!s->budget--) { s->failed_pc=0x0c0a2d7cu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0a2d7e;
P_0c0a2d7e: /* original 5323, guest PC 0x0c0a2d7e */
if(!s->budget--) { s->failed_pc=0x0c0a2d7eu; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c0a2d80;
P_0c0a2d80: /* original 2338, guest PC 0x0c0a2d80 */
if(!s->budget--) { s->failed_pc=0x0c0a2d80u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2d82;
P_0c0a2d82: /* original 8907, guest PC 0x0c0a2d82 */
if(!s->budget--) { s->failed_pc=0x0c0a2d82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d94; }
goto P_0c0a2d84;
P_0c0a2d84: /* original 53e1, guest PC 0x0c0a2d84 */
if(!s->budget--) { s->failed_pc=0x0c0a2d84u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2d86;
P_0c0a2d86: /* original 5233, guest PC 0x0c0a2d86 */
if(!s->budget--) { s->failed_pc=0x0c0a2d86u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c0a2d88;
P_0c0a2d88: /* original 32d2, guest PC 0x0c0a2d88 */
if(!s->budget--) { s->failed_pc=0x0c0a2d88u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[13])!=0);
goto P_0c0a2d8a;
P_0c0a2d8a: /* original 8903, guest PC 0x0c0a2d8a */
if(!s->budget--) { s->failed_pc=0x0c0a2d8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d94; }
goto P_0c0a2d8c;
P_0c0a2d8c: /* original 54e1, guest PC 0x0c0a2d8c */
if(!s->budget--) { s->failed_pc=0x0c0a2d8cu; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c0a2d8e;
P_0c0a2d8e: /* original 5243, guest PC 0x0c0a2d8e */
if(!s->budget--) { s->failed_pc=0x0c0a2d8eu; return 0; }
r[2]=read(ram,r[4]+12,4);
goto P_0c0a2d90;
P_0c0a2d90: /* original 32dc, guest PC 0x0c0a2d90 */
if(!s->budget--) { s->failed_pc=0x0c0a2d90u; return 0; }
r[2]+=r[13];
goto P_0c0a2d92;
P_0c0a2d92: /* original 1423, guest PC 0x0c0a2d92 */
if(!s->budget--) { s->failed_pc=0x0c0a2d92u; return 0; }
write(ram,r[4]+12,r[2],4);
goto P_0c0a2d94;
P_0c0a2d94: /* original c718, guest PC 0x0c0a2d94 */
if(!s->budget--) { s->failed_pc=0x0c0a2d94u; return 0; }
r[0]=code_base|0x000a2df8u;
goto P_0c0a2d96;
P_0c0a2d96: /* original 53e1, guest PC 0x0c0a2d96 */
if(!s->budget--) { s->failed_pc=0x0c0a2d96u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2d98;
P_0c0a2d98: /* original f408, guest PC 0x0c0a2d98 */
if(!s->budget--) { s->failed_pc=0x0c0a2d98u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0a2d9a;
P_0c0a2d9a: /* original e010, guest PC 0x0c0a2d9a */
if(!s->budget--) { s->failed_pc=0x0c0a2d9au; return 0; }
r[0]=0x00000010u;
goto P_0c0a2d9c;
P_0c0a2d9c: /* original f336, guest PC 0x0c0a2d9c */
if(!s->budget--) { s->failed_pc=0x0c0a2d9cu; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0a2d9e;
P_0c0a2d9e: /* original f342, guest PC 0x0c0a2d9e */
if(!s->budget--) { s->failed_pc=0x0c0a2d9eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a2da0;
P_0c0a2da0: /* original f337, guest PC 0x0c0a2da0 */
if(!s->budget--) { s->failed_pc=0x0c0a2da0u; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c0a2da2;
P_0c0a2da2: /* original e014, guest PC 0x0c0a2da2 */
if(!s->budget--) { s->failed_pc=0x0c0a2da2u; return 0; }
r[0]=0x00000014u;
goto P_0c0a2da4;
P_0c0a2da4: /* original 53e1, guest PC 0x0c0a2da4 */
if(!s->budget--) { s->failed_pc=0x0c0a2da4u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2da6;
P_0c0a2da6: /* original f336, guest PC 0x0c0a2da6 */
if(!s->budget--) { s->failed_pc=0x0c0a2da6u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0a2da8;
P_0c0a2da8: /* original f342, guest PC 0x0c0a2da8 */
if(!s->budget--) { s->failed_pc=0x0c0a2da8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a2daa;
P_0c0a2daa: /* original f337, guest PC 0x0c0a2daa */
if(!s->budget--) { s->failed_pc=0x0c0a2daau; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c0a2dac;
P_0c0a2dac: /* original e018, guest PC 0x0c0a2dac */
if(!s->budget--) { s->failed_pc=0x0c0a2dacu; return 0; }
r[0]=0x00000018u;
goto P_0c0a2dae;
P_0c0a2dae: /* original 53e1, guest PC 0x0c0a2dae */
if(!s->budget--) { s->failed_pc=0x0c0a2daeu; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2db0;
P_0c0a2db0: /* original f336, guest PC 0x0c0a2db0 */
if(!s->budget--) { s->failed_pc=0x0c0a2db0u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0a2db2;
P_0c0a2db2: /* original f342, guest PC 0x0c0a2db2 */
if(!s->budget--) { s->failed_pc=0x0c0a2db2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a2db4;
P_0c0a2db4: /* original f337, guest PC 0x0c0a2db4 */
if(!s->budget--) { s->failed_pc=0x0c0a2db4u; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c0a2db6;
P_0c0a2db6: /* original e01c, guest PC 0x0c0a2db6 */
if(!s->budget--) { s->failed_pc=0x0c0a2db6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a2db8;
P_0c0a2db8: /* original 53e1, guest PC 0x0c0a2db8 */
if(!s->budget--) { s->failed_pc=0x0c0a2db8u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2dba;
P_0c0a2dba: /* original f336, guest PC 0x0c0a2dba */
if(!s->budget--) { s->failed_pc=0x0c0a2dbau; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0a2dbc;
P_0c0a2dbc: /* original f342, guest PC 0x0c0a2dbc */
if(!s->budget--) { s->failed_pc=0x0c0a2dbcu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a2dbe;
P_0c0a2dbe: /* original f337, guest PC 0x0c0a2dbe */
if(!s->budget--) { s->failed_pc=0x0c0a2dbeu; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c0a2dc0;
P_0c0a2dc0: /* original 53eb, guest PC 0x0c0a2dc0 */
if(!s->budget--) { s->failed_pc=0x0c0a2dc0u; return 0; }
r[3]=read(ram,r[14]+44,4);
goto P_0c0a2dc2;
P_0c0a2dc2: /* original 2338, guest PC 0x0c0a2dc2 */
if(!s->budget--) { s->failed_pc=0x0c0a2dc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2dc4;
P_0c0a2dc4: /* original 8908, guest PC 0x0c0a2dc4 */
if(!s->budget--) { s->failed_pc=0x0c0a2dc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2dd8; }
goto P_0c0a2dc6;
P_0c0a2dc6: /* original 53eb, guest PC 0x0c0a2dc6 */
if(!s->budget--) { s->failed_pc=0x0c0a2dc6u; return 0; }
r[3]=read(ram,r[14]+44,4);
goto P_0c0a2dc8;
P_0c0a2dc8: /* original 33d2, guest PC 0x0c0a2dc8 */
if(!s->budget--) { s->failed_pc=0x0c0a2dc8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2dca;
P_0c0a2dca: /* original 8905, guest PC 0x0c0a2dca */
if(!s->budget--) { s->failed_pc=0x0c0a2dcau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2dd8; }
goto P_0c0a2dcc;
P_0c0a2dcc: /* original 51eb, guest PC 0x0c0a2dcc */
if(!s->budget--) { s->failed_pc=0x0c0a2dccu; return 0; }
r[1]=read(ram,r[14]+44,4);
goto P_0c0a2dce;
P_0c0a2dce: /* original 65d3, guest PC 0x0c0a2dce */
if(!s->budget--) { s->failed_pc=0x0c0a2dceu; return 0; }
r[5]=r[13];
goto P_0c0a2dd0;
P_0c0a2dd0: /* original 31dc, guest PC 0x0c0a2dd0 */
if(!s->budget--) { s->failed_pc=0x0c0a2dd0u; return 0; }
r[1]+=r[13];
goto P_0c0a2dd2;
P_0c0a2dd2: /* original 1e1b, guest PC 0x0c0a2dd2 */
if(!s->budget--) { s->failed_pc=0x0c0a2dd2u; return 0; }
write(ram,r[14]+44,r[1],4);
goto P_0c0a2dd4;
P_0c0a2dd4: /* original bfb8, guest PC 0x0c0a2dd4 */
if(!s->budget--) { s->failed_pc=0x0c0a2dd4u; return 0; }
target=code_base|0x0c0a2d48u; r[16]=code_base|0x0c0a2dd8u;
r[4]=r[1];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2dd8u) { target=s->pc; goto dispatch; }
goto P_0c0a2dd8;
P_0c0a2dd6: /* original 6413, guest PC 0x0c0a2dd6 */
if(!s->budget--) { s->failed_pc=0x0c0a2dd6u; return 0; }
r[4]=r[1];
goto P_0c0a2dd8;
P_0c0a2dd8: /* original 52ec, guest PC 0x0c0a2dd8 */
if(!s->budget--) { s->failed_pc=0x0c0a2dd8u; return 0; }
r[2]=read(ram,r[14]+48,4);
goto P_0c0a2dda;
P_0c0a2dda: /* original 2228, guest PC 0x0c0a2dda */
if(!s->budget--) { s->failed_pc=0x0c0a2ddau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2ddc;
P_0c0a2ddc: /* original 8908, guest PC 0x0c0a2ddc */
if(!s->budget--) { s->failed_pc=0x0c0a2ddcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2df0; }
goto P_0c0a2dde;
P_0c0a2dde: /* original 53ec, guest PC 0x0c0a2dde */
if(!s->budget--) { s->failed_pc=0x0c0a2ddeu; return 0; }
r[3]=read(ram,r[14]+48,4);
goto P_0c0a2de0;
P_0c0a2de0: /* original 33d2, guest PC 0x0c0a2de0 */
if(!s->budget--) { s->failed_pc=0x0c0a2de0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2de2;
P_0c0a2de2: /* original 8905, guest PC 0x0c0a2de2 */
if(!s->budget--) { s->failed_pc=0x0c0a2de2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2df0; }
goto P_0c0a2de4;
P_0c0a2de4: /* original 51ec, guest PC 0x0c0a2de4 */
if(!s->budget--) { s->failed_pc=0x0c0a2de4u; return 0; }
r[1]=read(ram,r[14]+48,4);
goto P_0c0a2de6;
P_0c0a2de6: /* original 64d3, guest PC 0x0c0a2de6 */
if(!s->budget--) { s->failed_pc=0x0c0a2de6u; return 0; }
r[4]=r[13];
goto P_0c0a2de8;
P_0c0a2de8: /* original 31dc, guest PC 0x0c0a2de8 */
if(!s->budget--) { s->failed_pc=0x0c0a2de8u; return 0; }
r[1]+=r[13];
goto P_0c0a2dea;
P_0c0a2dea: /* original 1e1c, guest PC 0x0c0a2dea */
if(!s->budget--) { s->failed_pc=0x0c0a2deau; return 0; }
write(ram,r[14]+48,r[1],4);
goto P_0c0a2dec;
P_0c0a2dec: /* original afb1, guest PC 0x0c0a2dec */
if(!s->budget--) { s->failed_pc=0x0c0a2decu; return 0; }
r[14]=r[1];
goto P_0c0a2d52;
P_0c0a2dee: /* original 6e13, guest PC 0x0c0a2dee */
if(!s->budget--) { s->failed_pc=0x0c0a2deeu; return 0; }
r[14]=r[1];
goto P_0c0a2df0;
P_0c0a2df0: /* original 4f26, guest PC 0x0c0a2df0 */
if(!s->budget--) { s->failed_pc=0x0c0a2df0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2df2;
P_0c0a2df2: /* original 6df6, guest PC 0x0c0a2df2 */
if(!s->budget--) { s->failed_pc=0x0c0a2df2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2df4;
P_0c0a2df4: /* original 000b, guest PC 0x0c0a2df4 */
if(!s->budget--) { s->failed_pc=0x0c0a2df4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2df6: /* original 6ef6, guest PC 0x0c0a2df6 */
if(!s->budget--) { s->failed_pc=0x0c0a2df6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a2df8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2df8u; return 0; } return 1;
P_0c0a7794: /* original 2fe6, guest PC 0x0c0a7794 */
if(!s->budget--) { s->failed_pc=0x0c0a7794u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7796;
P_0c0a7796: /* original 6e43, guest PC 0x0c0a7796 */
if(!s->budget--) { s->failed_pc=0x0c0a7796u; return 0; }
r[14]=r[4];
goto P_0c0a7798;
P_0c0a7798: /* original 4f22, guest PC 0x0c0a7798 */
if(!s->budget--) { s->failed_pc=0x0c0a7798u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a779a;
P_0c0a779a: /* original 2ee8, guest PC 0x0c0a779a */
if(!s->budget--) { s->failed_pc=0x0c0a779au; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a779c;
P_0c0a779c: /* original 7ffc, guest PC 0x0c0a779c */
if(!s->budget--) { s->failed_pc=0x0c0a779cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a779e;
P_0c0a779e: /* original 8d1a, guest PC 0x0c0a779e */
if(!s->budget--) { s->failed_pc=0x0c0a779eu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[5],4);
if(cond) { goto P_0c0a77d6; }
goto P_0c0a77a2;
P_0c0a77a0: /* original 2f52, guest PC 0x0c0a77a0 */
if(!s->budget--) { s->failed_pc=0x0c0a77a0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0a77a2;
P_0c0a77a2: /* original e024, guest PC 0x0c0a77a2 */
if(!s->budget--) { s->failed_pc=0x0c0a77a2u; return 0; }
r[0]=0x00000024u;
goto P_0c0a77a4;
P_0c0a77a4: /* original f5e6, guest PC 0x0c0a77a4 */
if(!s->budget--) { s->failed_pc=0x0c0a77a4u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a77a6;
P_0c0a77a6: /* original e01c, guest PC 0x0c0a77a6 */
if(!s->budget--) { s->failed_pc=0x0c0a77a6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a77a8;
P_0c0a77a8: /* original f4e6, guest PC 0x0c0a77a8 */
if(!s->budget--) { s->failed_pc=0x0c0a77a8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a77aa;
P_0c0a77aa: /* original 84e7, guest PC 0x0c0a77aa */
if(!s->budget--) { s->failed_pc=0x0c0a77aau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+7,1);
goto P_0c0a77ac;
P_0c0a77ac: /* original 660c, guest PC 0x0c0a77ac */
if(!s->budget--) { s->failed_pc=0x0c0a77acu; return 0; }
r[6]=r[0]&255u;
goto P_0c0a77ae;
P_0c0a77ae: /* original 84e6, guest PC 0x0c0a77ae */
if(!s->budget--) { s->failed_pc=0x0c0a77aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+6,1);
goto P_0c0a77b0;
P_0c0a77b0: /* original 650c, guest PC 0x0c0a77b0 */
if(!s->budget--) { s->failed_pc=0x0c0a77b0u; return 0; }
r[5]=r[0]&255u;
goto P_0c0a77b2;
P_0c0a77b2: /* original 84e5, guest PC 0x0c0a77b2 */
if(!s->budget--) { s->failed_pc=0x0c0a77b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+5,1);
goto P_0c0a77b4;
P_0c0a77b4: /* original b12a, guest PC 0x0c0a77b4 */
if(!s->budget--) { s->failed_pc=0x0c0a77b4u; return 0; }
target=code_base|0x0c0a7a0cu; r[16]=code_base|0x0c0a77b8u;
r[4]=r[0]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a77b8u) { target=s->pc; goto dispatch; }
goto P_0c0a77b8;
P_0c0a77b6: /* original 640c, guest PC 0x0c0a77b6 */
if(!s->budget--) { s->failed_pc=0x0c0a77b6u; return 0; }
r[4]=r[0]&255u;
goto P_0c0a77b8;
P_0c0a77b8: /* original 64f2, guest PC 0x0c0a77b8 */
if(!s->budget--) { s->failed_pc=0x0c0a77b8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a77ba;
P_0c0a77ba: /* original e010, guest PC 0x0c0a77ba */
if(!s->budget--) { s->failed_pc=0x0c0a77bau; return 0; }
r[0]=0x00000010u;
goto P_0c0a77bc;
P_0c0a77bc: /* original f5e6, guest PC 0x0c0a77bc */
if(!s->budget--) { s->failed_pc=0x0c0a77bcu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a77be;
P_0c0a77be: /* original 044c, guest PC 0x0c0a77be */
if(!s->budget--) { s->failed_pc=0x0c0a77beu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a77c0;
P_0c0a77c0: /* original e014, guest PC 0x0c0a77c0 */
if(!s->budget--) { s->failed_pc=0x0c0a77c0u; return 0; }
r[0]=0x00000014u;
goto P_0c0a77c2;
P_0c0a77c2: /* original b0a1, guest PC 0x0c0a77c2 */
if(!s->budget--) { s->failed_pc=0x0c0a77c2u; return 0; }
target=code_base|0x0c0a7908u; r[16]=code_base|0x0c0a77c6u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a77c6u) { target=s->pc; goto dispatch; }
goto P_0c0a77c6;
P_0c0a77c4: /* original f4e6, guest PC 0x0c0a77c4 */
if(!s->budget--) { s->failed_pc=0x0c0a77c4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a77c6;
P_0c0a77c6: /* original 85e7, guest PC 0x0c0a77c6 */
if(!s->budget--) { s->failed_pc=0x0c0a77c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a77c8;
P_0c0a77c8: /* original 7f04, guest PC 0x0c0a77c8 */
if(!s->budget--) { s->failed_pc=0x0c0a77c8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a77ca;
P_0c0a77ca: /* original 4f26, guest PC 0x0c0a77ca */
if(!s->budget--) { s->failed_pc=0x0c0a77cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a77cc;
P_0c0a77cc: /* original 6503, guest PC 0x0c0a77cc */
if(!s->budget--) { s->failed_pc=0x0c0a77ccu; return 0; }
r[5]=r[0];
goto P_0c0a77ce;
P_0c0a77ce: /* original 85e6, guest PC 0x0c0a77ce */
if(!s->budget--) { s->failed_pc=0x0c0a77ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0a77d0;
P_0c0a77d0: /* original 6403, guest PC 0x0c0a77d0 */
if(!s->budget--) { s->failed_pc=0x0c0a77d0u; return 0; }
r[4]=r[0];
goto P_0c0a77d2;
P_0c0a77d2: /* original a006, guest PC 0x0c0a77d2 */
if(!s->budget--) { s->failed_pc=0x0c0a77d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a77e2;
P_0c0a77d4: /* original 6ef6, guest PC 0x0c0a77d4 */
if(!s->budget--) { s->failed_pc=0x0c0a77d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a77d6;
P_0c0a77d6: /* original 7f04, guest PC 0x0c0a77d6 */
if(!s->budget--) { s->failed_pc=0x0c0a77d6u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a77d8;
P_0c0a77d8: /* original 4f26, guest PC 0x0c0a77d8 */
if(!s->budget--) { s->failed_pc=0x0c0a77d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a77da;
P_0c0a77da: /* original 000b, guest PC 0x0c0a77da */
if(!s->budget--) { s->failed_pc=0x0c0a77dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a77dc: /* original 6ef6, guest PC 0x0c0a77dc */
if(!s->budget--) { s->failed_pc=0x0c0a77dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a77deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a77deu; return 0; } return 1;
P_0c0a77e2: /* original 4f22, guest PC 0x0c0a77e2 */
if(!s->budget--) { s->failed_pc=0x0c0a77e2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a77e4;
P_0c0a77e4: /* original 6043, guest PC 0x0c0a77e4 */
if(!s->budget--) { s->failed_pc=0x0c0a77e4u; return 0; }
r[0]=r[4];
goto P_0c0a77e6;
P_0c0a77e6: /* original e300, guest PC 0x0c0a77e6 */
if(!s->budget--) { s->failed_pc=0x0c0a77e6u; return 0; }
r[3]=0x00000000u;
goto P_0c0a77e8;
P_0c0a77e8: /* original 7fec, guest PC 0x0c0a77e8 */
if(!s->budget--) { s->failed_pc=0x0c0a77e8u; return 0; }
r[15]+=0xffffffecu;
goto P_0c0a77ea;
P_0c0a77ea: /* original 81f6, guest PC 0x0c0a77ea */
if(!s->budget--) { s->failed_pc=0x0c0a77eau; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c0a77ec;
P_0c0a77ec: /* original 6053, guest PC 0x0c0a77ec */
if(!s->budget--) { s->failed_pc=0x0c0a77ecu; return 0; }
r[0]=r[5];
goto P_0c0a77ee;
P_0c0a77ee: /* original 81f8, guest PC 0x0c0a77ee */
if(!s->budget--) { s->failed_pc=0x0c0a77eeu; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c0a77f0;
P_0c0a77f0: /* original 2f36, guest PC 0x0c0a77f0 */
if(!s->budget--) { s->failed_pc=0x0c0a77f0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a77f2;
P_0c0a77f2: /* original 85fa, guest PC 0x0c0a77f2 */
if(!s->budget--) { s->failed_pc=0x0c0a77f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+20,2);
goto P_0c0a77f4;
P_0c0a77f4: /* original 2f06, guest PC 0x0c0a77f4 */
if(!s->budget--) { s->failed_pc=0x0c0a77f4u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a77f6;
P_0c0a77f6: /* original 85fa, guest PC 0x0c0a77f6 */
if(!s->budget--) { s->failed_pc=0x0c0a77f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+20,2);
goto P_0c0a77f8;
P_0c0a77f8: /* original 65f3, guest PC 0x0c0a77f8 */
if(!s->budget--) { s->failed_pc=0x0c0a77f8u; return 0; }
r[5]=r[15];
goto P_0c0a77fa;
P_0c0a77fa: /* original 66f3, guest PC 0x0c0a77fa */
if(!s->budget--) { s->failed_pc=0x0c0a77fau; return 0; }
r[6]=r[15];
goto P_0c0a77fc;
P_0c0a77fc: /* original d213, guest PC 0x0c0a77fc */
if(!s->budget--) { s->failed_pc=0x0c0a77fcu; return 0; }
r[2]=read(ram,0x0c0a784cu,4);
goto P_0c0a77fe;
P_0c0a77fe: /* original 64f3, guest PC 0x0c0a77fe */
if(!s->budget--) { s->failed_pc=0x0c0a77feu; return 0; }
r[4]=r[15];
goto P_0c0a7800;
P_0c0a7800: /* original 750c, guest PC 0x0c0a7800 */
if(!s->budget--) { s->failed_pc=0x0c0a7800u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0a7802;
P_0c0a7802: /* original 6703, guest PC 0x0c0a7802 */
if(!s->budget--) { s->failed_pc=0x0c0a7802u; return 0; }
r[7]=r[0];
goto P_0c0a7804;
P_0c0a7804: /* original 7610, guest PC 0x0c0a7804 */
if(!s->budget--) { s->failed_pc=0x0c0a7804u; return 0; }
r[6]+=0x00000010u;
goto P_0c0a7806;
P_0c0a7806: /* original 420b, guest PC 0x0c0a7806 */
if(!s->budget--) { s->failed_pc=0x0c0a7806u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a780au;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a780au) { target=s->pc; goto dispatch; }
goto P_0c0a780a;
P_0c0a7808: /* original 7408, guest PC 0x0c0a7808 */
if(!s->budget--) { s->failed_pc=0x0c0a7808u; return 0; }
r[4]+=0x00000008u;
goto P_0c0a780a;
P_0c0a780a: /* original e010, guest PC 0x0c0a780a */
if(!s->budget--) { s->failed_pc=0x0c0a780au; return 0; }
r[0]=0x00000010u;
goto P_0c0a780c;
P_0c0a780c: /* original f6f6, guest PC 0x0c0a780c */
if(!s->budget--) { s->failed_pc=0x0c0a780cu; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0a780e;
P_0c0a780e: /* original e00c, guest PC 0x0c0a780e */
if(!s->budget--) { s->failed_pc=0x0c0a780eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0a7810;
P_0c0a7810: /* original f5f6, guest PC 0x0c0a7810 */
if(!s->budget--) { s->failed_pc=0x0c0a7810u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0a7812;
P_0c0a7812: /* original e008, guest PC 0x0c0a7812 */
if(!s->budget--) { s->failed_pc=0x0c0a7812u; return 0; }
r[0]=0x00000008u;
goto P_0c0a7814;
P_0c0a7814: /* original b01c, guest PC 0x0c0a7814 */
if(!s->budget--) { s->failed_pc=0x0c0a7814u; return 0; }
target=code_base|0x0c0a7850u; r[16]=code_base|0x0c0a7818u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7818u) { target=s->pc; goto dispatch; }
goto P_0c0a7818;
P_0c0a7816: /* original f4f6, guest PC 0x0c0a7816 */
if(!s->budget--) { s->failed_pc=0x0c0a7816u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0a7818;
P_0c0a7818: /* original 7f1c, guest PC 0x0c0a7818 */
if(!s->budget--) { s->failed_pc=0x0c0a7818u; return 0; }
r[15]+=0x0000001cu;
goto P_0c0a781a;
P_0c0a781a: /* original 4f26, guest PC 0x0c0a781a */
if(!s->budget--) { s->failed_pc=0x0c0a781au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a781c;
P_0c0a781c: /* original 000b, guest PC 0x0c0a781c */
if(!s->budget--) { s->failed_pc=0x0c0a781cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a781e: /* original 0009, guest PC 0x0c0a781e */
if(!s->budget--) { s->failed_pc=0x0c0a781eu; return 0; }
if(!vf3_matrix_family(0x0c0a7820u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7820u; return 0; } return 1;
P_0c0a7850: /* original d43f, guest PC 0x0c0a7850 */
if(!s->budget--) { s->failed_pc=0x0c0a7850u; return 0; }
r[4]=read(ram,0x0c0a7950u,4);
goto P_0c0a7852;
P_0c0a7852: /* original e040, guest PC 0x0c0a7852 */
if(!s->budget--) { s->failed_pc=0x0c0a7852u; return 0; }
r[0]=0x00000040u;
goto P_0c0a7854;
P_0c0a7854: /* original f447, guest PC 0x0c0a7854 */
if(!s->budget--) { s->failed_pc=0x0c0a7854u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0a7856;
P_0c0a7856: /* original e044, guest PC 0x0c0a7856 */
if(!s->budget--) { s->failed_pc=0x0c0a7856u; return 0; }
r[0]=0x00000044u;
goto P_0c0a7858;
P_0c0a7858: /* original f457, guest PC 0x0c0a7858 */
if(!s->budget--) { s->failed_pc=0x0c0a7858u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0a785a;
P_0c0a785a: /* original e048, guest PC 0x0c0a785a */
if(!s->budget--) { s->failed_pc=0x0c0a785au; return 0; }
r[0]=0x00000048u;
goto P_0c0a785c;
P_0c0a785c: /* original a000, guest PC 0x0c0a785c */
if(!s->budget--) { s->failed_pc=0x0c0a785cu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0a7860;
P_0c0a785e: /* original f467, guest PC 0x0c0a785e */
if(!s->budget--) { s->failed_pc=0x0c0a785eu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0a7860;
P_0c0a7860: /* original 2fe6, guest PC 0x0c0a7860 */
if(!s->budget--) { s->failed_pc=0x0c0a7860u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7862;
P_0c0a7862: /* original e040, guest PC 0x0c0a7862 */
if(!s->budget--) { s->failed_pc=0x0c0a7862u; return 0; }
r[0]=0x00000040u;
goto P_0c0a7864;
P_0c0a7864: /* original de3a, guest PC 0x0c0a7864 */
if(!s->budget--) { s->failed_pc=0x0c0a7864u; return 0; }
r[14]=read(ram,0x0c0a7950u,4);
goto P_0c0a7866;
P_0c0a7866: /* original 4f22, guest PC 0x0c0a7866 */
if(!s->budget--) { s->failed_pc=0x0c0a7866u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7868;
P_0c0a7868: /* original f4e6, guest PC 0x0c0a7868 */
if(!s->budget--) { s->failed_pc=0x0c0a7868u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a786a;
P_0c0a786a: /* original e044, guest PC 0x0c0a786a */
if(!s->budget--) { s->failed_pc=0x0c0a786au; return 0; }
r[0]=0x00000044u;
goto P_0c0a786c;
P_0c0a786c: /* original f5e6, guest PC 0x0c0a786c */
if(!s->budget--) { s->failed_pc=0x0c0a786cu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a786e;
P_0c0a786e: /* original e048, guest PC 0x0c0a786e */
if(!s->budget--) { s->failed_pc=0x0c0a786eu; return 0; }
r[0]=0x00000048u;
goto P_0c0a7870;
P_0c0a7870: /* original d338, guest PC 0x0c0a7870 */
if(!s->budget--) { s->failed_pc=0x0c0a7870u; return 0; }
r[3]=read(ram,0x0c0a7954u,4);
goto P_0c0a7872;
P_0c0a7872: /* original 7ff4, guest PC 0x0c0a7872 */
if(!s->budget--) { s->failed_pc=0x0c0a7872u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a7874;
P_0c0a7874: /* original f6e6, guest PC 0x0c0a7874 */
if(!s->budget--) { s->failed_pc=0x0c0a7874u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0a7876;
P_0c0a7876: /* original 430b, guest PC 0x0c0a7876 */
if(!s->budget--) { s->failed_pc=0x0c0a7876u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a787au;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a787au) { target=s->pc; goto dispatch; }
goto P_0c0a787a;
P_0c0a7878: /* original e400, guest PC 0x0c0a7878 */
if(!s->budget--) { s->failed_pc=0x0c0a7878u; return 0; }
r[4]=0x00000000u;
goto P_0c0a787a;
P_0c0a787a: /* original d237, guest PC 0x0c0a787a */
if(!s->budget--) { s->failed_pc=0x0c0a787au; return 0; }
r[2]=read(ram,0x0c0a7958u,4);
goto P_0c0a787c;
P_0c0a787c: /* original 420b, guest PC 0x0c0a787c */
if(!s->budget--) { s->failed_pc=0x0c0a787cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7880u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7880u) { target=s->pc; goto dispatch; }
goto P_0c0a7880;
P_0c0a787e: /* original e400, guest PC 0x0c0a787e */
if(!s->budget--) { s->failed_pc=0x0c0a787eu; return 0; }
r[4]=0x00000000u;
goto P_0c0a7880;
P_0c0a7880: /* original d336, guest PC 0x0c0a7880 */
if(!s->budget--) { s->failed_pc=0x0c0a7880u; return 0; }
r[3]=read(ram,0x0c0a795cu,4);
goto P_0c0a7882;
P_0c0a7882: /* original 9463, guest PC 0x0c0a7882 */
if(!s->budget--) { s->failed_pc=0x0c0a7882u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a794cu,2);
goto P_0c0a7884;
P_0c0a7884: /* original 430b, guest PC 0x0c0a7884 */
if(!s->budget--) { s->failed_pc=0x0c0a7884u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7888u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7888u) { target=s->pc; goto dispatch; }
goto P_0c0a7888;
P_0c0a7886: /* original 34ec, guest PC 0x0c0a7886 */
if(!s->budget--) { s->failed_pc=0x0c0a7886u; return 0; }
r[4]+=r[14];
goto P_0c0a7888;
P_0c0a7888: /* original d235, guest PC 0x0c0a7888 */
if(!s->budget--) { s->failed_pc=0x0c0a7888u; return 0; }
r[2]=read(ram,0x0c0a7960u,4);
goto P_0c0a788a;
P_0c0a788a: /* original 420b, guest PC 0x0c0a788a */
if(!s->budget--) { s->failed_pc=0x0c0a788au; return 0; }
target=r[2];
r[16]=code_base|0x0c0a788eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a788eu) { target=s->pc; goto dispatch; }
goto P_0c0a788e;
P_0c0a788c: /* original 0009, guest PC 0x0c0a788c */
if(!s->budget--) { s->failed_pc=0x0c0a788cu; return 0; }
goto P_0c0a788e;
P_0c0a788e: /* original d335, guest PC 0x0c0a788e */
if(!s->budget--) { s->failed_pc=0x0c0a788eu; return 0; }
r[3]=read(ram,0x0c0a7964u,4);
goto P_0c0a7890;
P_0c0a7890: /* original 64e3, guest PC 0x0c0a7890 */
if(!s->budget--) { s->failed_pc=0x0c0a7890u; return 0; }
r[4]=r[14];
goto P_0c0a7892;
P_0c0a7892: /* original 65f3, guest PC 0x0c0a7892 */
if(!s->budget--) { s->failed_pc=0x0c0a7892u; return 0; }
r[5]=r[15];
goto P_0c0a7894;
P_0c0a7894: /* original 430b, guest PC 0x0c0a7894 */
if(!s->budget--) { s->failed_pc=0x0c0a7894u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7898u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7898u) { target=s->pc; goto dispatch; }
goto P_0c0a7898;
P_0c0a7896: /* original 7440, guest PC 0x0c0a7896 */
if(!s->budget--) { s->failed_pc=0x0c0a7896u; return 0; }
r[4]+=0x00000040u;
goto P_0c0a7898;
P_0c0a7898: /* original d233, guest PC 0x0c0a7898 */
if(!s->budget--) { s->failed_pc=0x0c0a7898u; return 0; }
r[2]=read(ram,0x0c0a7968u,4);
goto P_0c0a789a;
P_0c0a789a: /* original 420b, guest PC 0x0c0a789a */
if(!s->budget--) { s->failed_pc=0x0c0a789au; return 0; }
target=r[2];
r[16]=code_base|0x0c0a789eu;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a789eu) { target=s->pc; goto dispatch; }
goto P_0c0a789e;
P_0c0a789c: /* original 64f3, guest PC 0x0c0a789c */
if(!s->budget--) { s->failed_pc=0x0c0a789cu; return 0; }
r[4]=r[15];
goto P_0c0a789e;
P_0c0a789e: /* original d333, guest PC 0x0c0a789e */
if(!s->budget--) { s->failed_pc=0x0c0a789eu; return 0; }
r[3]=read(ram,0x0c0a796cu,4);
goto P_0c0a78a0;
P_0c0a78a0: /* original 430b, guest PC 0x0c0a78a0 */
if(!s->budget--) { s->failed_pc=0x0c0a78a0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a78a4u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a78a4u) { target=s->pc; goto dispatch; }
goto P_0c0a78a4;
P_0c0a78a2: /* original e401, guest PC 0x0c0a78a2 */
if(!s->budget--) { s->failed_pc=0x0c0a78a2u; return 0; }
r[4]=0x00000001u;
goto P_0c0a78a4;
P_0c0a78a4: /* original 7f0c, guest PC 0x0c0a78a4 */
if(!s->budget--) { s->failed_pc=0x0c0a78a4u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a78a6;
P_0c0a78a6: /* original 4f26, guest PC 0x0c0a78a6 */
if(!s->budget--) { s->failed_pc=0x0c0a78a6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a78a8;
P_0c0a78a8: /* original 000b, guest PC 0x0c0a78a8 */
if(!s->budget--) { s->failed_pc=0x0c0a78a8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a78aa: /* original 6ef6, guest PC 0x0c0a78aa */
if(!s->budget--) { s->failed_pc=0x0c0a78aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a78acu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a78acu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
