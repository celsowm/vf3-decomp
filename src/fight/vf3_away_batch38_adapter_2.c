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
int vf3_away_batch38_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c055d40u: goto P_0c055d40;
case 0x0c055d42u: goto P_0c055d42;
case 0x0c055d44u: goto P_0c055d44;
case 0x0c055d46u: goto P_0c055d46;
case 0x0c055d48u: goto P_0c055d48;
case 0x0c055d4au: goto P_0c055d4a;
case 0x0c055d4cu: goto P_0c055d4c;
case 0x0c055d4eu: goto P_0c055d4e;
case 0x0c055d50u: goto P_0c055d50;
case 0x0c055d52u: goto P_0c055d52;
case 0x0c055d54u: goto P_0c055d54;
case 0x0c055d56u: goto P_0c055d56;
case 0x0c055d58u: goto P_0c055d58;
case 0x0c055d5au: goto P_0c055d5a;
case 0x0c055d5cu: goto P_0c055d5c;
case 0x0c055d5eu: goto P_0c055d5e;
case 0x0c055d60u: goto P_0c055d60;
case 0x0c055d62u: goto P_0c055d62;
case 0x0c055d64u: goto P_0c055d64;
case 0x0c055d66u: goto P_0c055d66;
case 0x0c055d68u: goto P_0c055d68;
case 0x0c055d6au: goto P_0c055d6a;
case 0x0c055d6cu: goto P_0c055d6c;
case 0x0c055d6eu: goto P_0c055d6e;
case 0x0c055d70u: goto P_0c055d70;
case 0x0c055d72u: goto P_0c055d72;
case 0x0c055d74u: goto P_0c055d74;
case 0x0c055d76u: goto P_0c055d76;
case 0x0c055d78u: goto P_0c055d78;
case 0x0c055d7au: goto P_0c055d7a;
case 0x0c055d7cu: goto P_0c055d7c;
case 0x0c055d7eu: goto P_0c055d7e;
case 0x0c055d80u: goto P_0c055d80;
case 0x0c055d82u: goto P_0c055d82;
case 0x0c055d84u: goto P_0c055d84;
case 0x0c055d86u: goto P_0c055d86;
case 0x0c055d88u: goto P_0c055d88;
case 0x0c055d8au: goto P_0c055d8a;
case 0x0c055d8cu: goto P_0c055d8c;
case 0x0c055d8eu: goto P_0c055d8e;
case 0x0c055d90u: goto P_0c055d90;
case 0x0c055d92u: goto P_0c055d92;
case 0x0c055d94u: goto P_0c055d94;
case 0x0c055d96u: goto P_0c055d96;
case 0x0c055d98u: goto P_0c055d98;
case 0x0c055d9au: goto P_0c055d9a;
case 0x0c055d9cu: goto P_0c055d9c;
case 0x0c055d9eu: goto P_0c055d9e;
case 0x0c055da0u: goto P_0c055da0;
case 0x0c055da2u: goto P_0c055da2;
case 0x0c055da4u: goto P_0c055da4;
case 0x0c055da6u: goto P_0c055da6;
case 0x0c055da8u: goto P_0c055da8;
case 0x0c055daau: goto P_0c055daa;
case 0x0c055dacu: goto P_0c055dac;
case 0x0c055daeu: goto P_0c055dae;
case 0x0c055db0u: goto P_0c055db0;
case 0x0c055db2u: goto P_0c055db2;
case 0x0c055db4u: goto P_0c055db4;
case 0x0c055db6u: goto P_0c055db6;
case 0x0c055db8u: goto P_0c055db8;
case 0x0c06c360u: goto P_0c06c360;
case 0x0c06c362u: goto P_0c06c362;
case 0x0c06c364u: goto P_0c06c364;
case 0x0c06c366u: goto P_0c06c366;
case 0x0c06c368u: goto P_0c06c368;
case 0x0c06c36au: goto P_0c06c36a;
case 0x0c06c36cu: goto P_0c06c36c;
case 0x0c06c36eu: goto P_0c06c36e;
case 0x0c06c370u: goto P_0c06c370;
case 0x0c06c372u: goto P_0c06c372;
case 0x0c06c374u: goto P_0c06c374;
case 0x0c06c376u: goto P_0c06c376;
case 0x0c06c378u: goto P_0c06c378;
case 0x0c06c37au: goto P_0c06c37a;
case 0x0c06c37cu: goto P_0c06c37c;
case 0x0c06c37eu: goto P_0c06c37e;
case 0x0c06c380u: goto P_0c06c380;
case 0x0c06c382u: goto P_0c06c382;
case 0x0c06c384u: goto P_0c06c384;
case 0x0c06c386u: goto P_0c06c386;
case 0x0c06c388u: goto P_0c06c388;
case 0x0c06c38au: goto P_0c06c38a;
case 0x0c06c38cu: goto P_0c06c38c;
case 0x0c06c38eu: goto P_0c06c38e;
case 0x0c06c390u: goto P_0c06c390;
case 0x0c06c392u: goto P_0c06c392;
case 0x0c06c394u: goto P_0c06c394;
case 0x0c06c396u: goto P_0c06c396;
case 0x0c06c398u: goto P_0c06c398;
case 0x0c06c39au: goto P_0c06c39a;
case 0x0c06c39cu: goto P_0c06c39c;
case 0x0c06c39eu: goto P_0c06c39e;
case 0x0c06c3a0u: goto P_0c06c3a0;
case 0x0c06c3a2u: goto P_0c06c3a2;
case 0x0c06c3a4u: goto P_0c06c3a4;
case 0x0c06c3a6u: goto P_0c06c3a6;
case 0x0c06c3a8u: goto P_0c06c3a8;
case 0x0c06c3aau: goto P_0c06c3aa;
case 0x0c06c3acu: goto P_0c06c3ac;
case 0x0c06c3aeu: goto P_0c06c3ae;
case 0x0c06c3b0u: goto P_0c06c3b0;
case 0x0c06c3b2u: goto P_0c06c3b2;
case 0x0c06c3b4u: goto P_0c06c3b4;
case 0x0c06c3b6u: goto P_0c06c3b6;
case 0x0c06c3b8u: goto P_0c06c3b8;
case 0x0c06c3bau: goto P_0c06c3ba;
case 0x0c06c3bcu: goto P_0c06c3bc;
case 0x0c06c3beu: goto P_0c06c3be;
case 0x0c06c3c0u: goto P_0c06c3c0;
case 0x0c06c3c2u: goto P_0c06c3c2;
case 0x0c06c3c4u: goto P_0c06c3c4;
case 0x0c06c3c6u: goto P_0c06c3c6;
case 0x0c06c3c8u: goto P_0c06c3c8;
case 0x0c06c3cau: goto P_0c06c3ca;
case 0x0c06c3ccu: goto P_0c06c3cc;
case 0x0c06c3ceu: goto P_0c06c3ce;
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
case 0x0c06c8a4u: goto P_0c06c8a4;
case 0x0c06c8a6u: goto P_0c06c8a6;
case 0x0c06c8a8u: goto P_0c06c8a8;
case 0x0c06c8aau: goto P_0c06c8aa;
case 0x0c06c8acu: goto P_0c06c8ac;
case 0x0c06c8aeu: goto P_0c06c8ae;
case 0x0c06c8b0u: goto P_0c06c8b0;
case 0x0c06c8b2u: goto P_0c06c8b2;
case 0x0c06c8b4u: goto P_0c06c8b4;
case 0x0c06c8b6u: goto P_0c06c8b6;
case 0x0c06c8b8u: goto P_0c06c8b8;
case 0x0c06c8bau: goto P_0c06c8ba;
case 0x0c06c8bcu: goto P_0c06c8bc;
case 0x0c06c8beu: goto P_0c06c8be;
case 0x0c06c8c0u: goto P_0c06c8c0;
case 0x0c06c8c2u: goto P_0c06c8c2;
case 0x0c06c8c4u: goto P_0c06c8c4;
case 0x0c06c8c6u: goto P_0c06c8c6;
case 0x0c06c8c8u: goto P_0c06c8c8;
case 0x0c06c8cau: goto P_0c06c8ca;
case 0x0c06c8ccu: goto P_0c06c8cc;
case 0x0c06c8ceu: goto P_0c06c8ce;
case 0x0c06c8d0u: goto P_0c06c8d0;
case 0x0c06c8d2u: goto P_0c06c8d2;
case 0x0c06c8d4u: goto P_0c06c8d4;
case 0x0c06c8d6u: goto P_0c06c8d6;
case 0x0c06c8d8u: goto P_0c06c8d8;
case 0x0c06c8dau: goto P_0c06c8da;
case 0x0c06c8dcu: goto P_0c06c8dc;
case 0x0c06c8deu: goto P_0c06c8de;
case 0x0c06c8e0u: goto P_0c06c8e0;
case 0x0c06c8e2u: goto P_0c06c8e2;
case 0x0c06c8e4u: goto P_0c06c8e4;
case 0x0c06c8e6u: goto P_0c06c8e6;
case 0x0c06c8e8u: goto P_0c06c8e8;
case 0x0c06c8eau: goto P_0c06c8ea;
case 0x0c06c8ecu: goto P_0c06c8ec;
case 0x0c06c8eeu: goto P_0c06c8ee;
case 0x0c06c8f0u: goto P_0c06c8f0;
case 0x0c06c8f2u: goto P_0c06c8f2;
case 0x0c06c8f4u: goto P_0c06c8f4;
case 0x0c06c914u: goto P_0c06c914;
case 0x0c06c916u: goto P_0c06c916;
case 0x0c06c918u: goto P_0c06c918;
case 0x0c06c91au: goto P_0c06c91a;
case 0x0c06c91cu: goto P_0c06c91c;
case 0x0c06c91eu: goto P_0c06c91e;
case 0x0c06c920u: goto P_0c06c920;
case 0x0c06c922u: goto P_0c06c922;
case 0x0c06c924u: goto P_0c06c924;
case 0x0c06c926u: goto P_0c06c926;
case 0x0c06c928u: goto P_0c06c928;
case 0x0c06c92au: goto P_0c06c92a;
case 0x0c06c92cu: goto P_0c06c92c;
case 0x0c06c92eu: goto P_0c06c92e;
case 0x0c06c930u: goto P_0c06c930;
case 0x0c06c932u: goto P_0c06c932;
case 0x0c06c934u: goto P_0c06c934;
case 0x0c06c936u: goto P_0c06c936;
case 0x0c06c938u: goto P_0c06c938;
case 0x0c06c93au: goto P_0c06c93a;
case 0x0c06c93cu: goto P_0c06c93c;
case 0x0c06c93eu: goto P_0c06c93e;
case 0x0c06c940u: goto P_0c06c940;
case 0x0c06c942u: goto P_0c06c942;
case 0x0c06c944u: goto P_0c06c944;
case 0x0c06c946u: goto P_0c06c946;
case 0x0c06c948u: goto P_0c06c948;
case 0x0c06c94au: goto P_0c06c94a;
case 0x0c06c94cu: goto P_0c06c94c;
case 0x0c06c94eu: goto P_0c06c94e;
case 0x0c06c950u: goto P_0c06c950;
case 0x0c06c952u: goto P_0c06c952;
case 0x0c06c954u: goto P_0c06c954;
case 0x0c06c956u: goto P_0c06c956;
case 0x0c06c958u: goto P_0c06c958;
case 0x0c06c95au: goto P_0c06c95a;
case 0x0c06c95cu: goto P_0c06c95c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c055d40: /* original 4f22, guest PC 0x0c055d40 */
if(!s->budget--) { s->failed_pc=0x0c055d40u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c055d42;
P_0c055d42: /* original d01f, guest PC 0x0c055d42 */
if(!s->budget--) { s->failed_pc=0x0c055d42u; return 0; }
r[0]=read(ram,0x0c055dc0u,4);
goto P_0c055d44;
P_0c055d44: /* original 6102, guest PC 0x0c055d44 */
if(!s->budget--) { s->failed_pc=0x0c055d44u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c055d46;
P_0c055d46: /* original 4115, guest PC 0x0c055d46 */
if(!s->budget--) { s->failed_pc=0x0c055d46u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c055d48;
P_0c055d48: /* original d01c, guest PC 0x0c055d48 */
if(!s->budget--) { s->failed_pc=0x0c055d48u; return 0; }
r[0]=read(ram,0x0c055dbcu,4);
goto P_0c055d4a;
P_0c055d4a: /* original 8d0e, guest PC 0x0c055d4a */
if(!s->budget--) { s->failed_pc=0x0c055d4au; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c055d6a; }
goto P_0c055d4e;
P_0c055d4c: /* original 6403, guest PC 0x0c055d4c */
if(!s->budget--) { s->failed_pc=0x0c055d4cu; return 0; }
r[4]=r[0];
goto P_0c055d4e;
P_0c055d4e: /* original 7440, guest PC 0x0c055d4e */
if(!s->budget--) { s->failed_pc=0x0c055d4eu; return 0; }
r[4]+=0x00000040u;
goto P_0c055d50;
P_0c055d50: /* original 6503, guest PC 0x0c055d50 */
if(!s->budget--) { s->failed_pc=0x0c055d50u; return 0; }
r[5]=r[0];
goto P_0c055d52;
P_0c055d52: /* original d31c, guest PC 0x0c055d52 */
if(!s->budget--) { s->failed_pc=0x0c055d52u; return 0; }
r[3]=read(ram,0x0c055dc4u,4);
goto P_0c055d54;
P_0c055d54: /* original 430b, guest PC 0x0c055d54 */
if(!s->budget--) { s->failed_pc=0x0c055d54u; return 0; }
target=r[3];
r[16]=code_base|0x0c055d58u;
r[5]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055d58u) { target=s->pc; goto dispatch; }
goto P_0c055d58;
P_0c055d56: /* original 7568, guest PC 0x0c055d56 */
if(!s->budget--) { s->failed_pc=0x0c055d56u; return 0; }
r[5]+=0x00000068u;
goto P_0c055d58;
P_0c055d58: /* original d01c, guest PC 0x0c055d58 */
if(!s->budget--) { s->failed_pc=0x0c055d58u; return 0; }
r[0]=read(ram,0x0c055dccu,4);
goto P_0c055d5a;
P_0c055d5a: /* original d11f, guest PC 0x0c055d5a */
if(!s->budget--) { s->failed_pc=0x0c055d5au; return 0; }
r[1]=read(ram,0x0c055dd8u,4);
goto P_0c055d5c;
P_0c055d5c: /* original d220, guest PC 0x0c055d5c */
if(!s->budget--) { s->failed_pc=0x0c055d5cu; return 0; }
r[2]=read(ram,0x0c055de0u,4);
goto P_0c055d5e;
P_0c055d5e: /* original c204, guest PC 0x0c055d5e */
if(!s->budget--) { s->failed_pc=0x0c055d5eu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+16,r[0],4);
goto P_0c055d60;
P_0c055d60: /* original 6013, guest PC 0x0c055d60 */
if(!s->budget--) { s->failed_pc=0x0c055d60u; return 0; }
r[0]=r[1];
goto P_0c055d62;
P_0c055d62: /* original c205, guest PC 0x0c055d62 */
if(!s->budget--) { s->failed_pc=0x0c055d62u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+20,r[0],4);
goto P_0c055d64;
P_0c055d64: /* original 6023, guest PC 0x0c055d64 */
if(!s->budget--) { s->failed_pc=0x0c055d64u; return 0; }
r[0]=r[2];
goto P_0c055d66;
P_0c055d66: /* original a025, guest PC 0x0c055d66 */
if(!s->budget--) { s->failed_pc=0x0c055d66u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+12,r[0],4);
goto P_0c055db4;
P_0c055d68: /* original c203, guest PC 0x0c055d68 */
if(!s->budget--) { s->failed_pc=0x0c055d68u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+12,r[0],4);
goto P_0c055d6a;
P_0c055d6a: /* original 2fe6, guest PC 0x0c055d6a */
if(!s->budget--) { s->failed_pc=0x0c055d6au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055d6c;
P_0c055d6c: /* original 2fd6, guest PC 0x0c055d6c */
if(!s->budget--) { s->failed_pc=0x0c055d6cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055d6e;
P_0c055d6e: /* original 6e03, guest PC 0x0c055d6e */
if(!s->budget--) { s->failed_pc=0x0c055d6eu; return 0; }
r[14]=r[0];
goto P_0c055d70;
P_0c055d70: /* original ed10, guest PC 0x0c055d70 */
if(!s->budget--) { s->failed_pc=0x0c055d70u; return 0; }
r[13]=0x00000010u;
goto P_0c055d72;
P_0c055d72: /* original 61e2, guest PC 0x0c055d72 */
if(!s->budget--) { s->failed_pc=0x0c055d72u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c055d74;
P_0c055d74: /* original 4115, guest PC 0x0c055d74 */
if(!s->budget--) { s->failed_pc=0x0c055d74u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c055d76;
P_0c055d76: /* original 8f0b, guest PC 0x0c055d76 */
if(!s->budget--) { s->failed_pc=0x0c055d76u; return 0; }
cond=r[17]&1u;
r[4]=r[14];
if(!cond) { goto P_0c055d90; }
goto P_0c055d7a;
P_0c055d78: /* original 64e3, guest PC 0x0c055d78 */
if(!s->budget--) { s->failed_pc=0x0c055d78u; return 0; }
r[4]=r[14];
goto P_0c055d7a;
P_0c055d7a: /* original 7440, guest PC 0x0c055d7a */
if(!s->budget--) { s->failed_pc=0x0c055d7au; return 0; }
r[4]+=0x00000040u;
goto P_0c055d7c;
P_0c055d7c: /* original 65e3, guest PC 0x0c055d7c */
if(!s->budget--) { s->failed_pc=0x0c055d7cu; return 0; }
r[5]=r[14];
goto P_0c055d7e;
P_0c055d7e: /* original d311, guest PC 0x0c055d7e */
if(!s->budget--) { s->failed_pc=0x0c055d7eu; return 0; }
r[3]=read(ram,0x0c055dc4u,4);
goto P_0c055d80;
P_0c055d80: /* original 430b, guest PC 0x0c055d80 */
if(!s->budget--) { s->failed_pc=0x0c055d80u; return 0; }
target=r[3];
r[16]=code_base|0x0c055d84u;
r[5]+=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055d84u) { target=s->pc; goto dispatch; }
goto P_0c055d84;
P_0c055d82: /* original 7568, guest PC 0x0c055d82 */
if(!s->budget--) { s->failed_pc=0x0c055d82u; return 0; }
r[5]+=0x00000068u;
goto P_0c055d84;
P_0c055d84: /* original 64e3, guest PC 0x0c055d84 */
if(!s->budget--) { s->failed_pc=0x0c055d84u; return 0; }
r[4]=r[14];
goto P_0c055d86;
P_0c055d86: /* original 7434, guest PC 0x0c055d86 */
if(!s->budget--) { s->failed_pc=0x0c055d86u; return 0; }
r[4]+=0x00000034u;
goto P_0c055d88;
P_0c055d88: /* original 65e3, guest PC 0x0c055d88 */
if(!s->budget--) { s->failed_pc=0x0c055d88u; return 0; }
r[5]=r[14];
goto P_0c055d8a;
P_0c055d8a: /* original d30f, guest PC 0x0c055d8a */
if(!s->budget--) { s->failed_pc=0x0c055d8au; return 0; }
r[3]=read(ram,0x0c055dc8u,4);
goto P_0c055d8c;
P_0c055d8c: /* original 430b, guest PC 0x0c055d8c */
if(!s->budget--) { s->failed_pc=0x0c055d8cu; return 0; }
target=r[3];
r[16]=code_base|0x0c055d90u;
r[5]+=0x0000005cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055d90u) { target=s->pc; goto dispatch; }
goto P_0c055d90;
P_0c055d8e: /* original 755c, guest PC 0x0c055d8e */
if(!s->budget--) { s->failed_pc=0x0c055d8eu; return 0; }
r[5]+=0x0000005cu;
goto P_0c055d90;
P_0c055d90: /* original e3b0, guest PC 0x0c055d90 */
if(!s->budget--) { s->failed_pc=0x0c055d90u; return 0; }
r[3]=0xffffffb0u;
goto P_0c055d92;
P_0c055d92: /* original 623c, guest PC 0x0c055d92 */
if(!s->budget--) { s->failed_pc=0x0c055d92u; return 0; }
r[2]=r[3]&255u;
goto P_0c055d94;
P_0c055d94: /* original 4d10, guest PC 0x0c055d94 */
if(!s->budget--) { s->failed_pc=0x0c055d94u; return 0; }
--r[13];
r[17]=(r[17]&~1u)|((r[13]==0)!=0);
goto P_0c055d96;
P_0c055d96: /* original 8fec, guest PC 0x0c055d96 */
if(!s->budget--) { s->failed_pc=0x0c055d96u; return 0; }
cond=r[17]&1u;
r[14]+=r[2];
if(!cond) { goto P_0c055d72; }
goto P_0c055d9a;
P_0c055d98: /* original 3e2c, guest PC 0x0c055d98 */
if(!s->budget--) { s->failed_pc=0x0c055d98u; return 0; }
r[14]+=r[2];
goto P_0c055d9a;
P_0c055d9a: /* original 6df6, guest PC 0x0c055d9a */
if(!s->budget--) { s->failed_pc=0x0c055d9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c055d9c;
P_0c055d9c: /* original 6ef6, guest PC 0x0c055d9c */
if(!s->budget--) { s->failed_pc=0x0c055d9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c055d9e;
P_0c055d9e: /* original d00c, guest PC 0x0c055d9e */
if(!s->budget--) { s->failed_pc=0x0c055d9eu; return 0; }
r[0]=read(ram,0x0c055dd0u,4);
goto P_0c055da0;
P_0c055da0: /* original e380, guest PC 0x0c055da0 */
if(!s->budget--) { s->failed_pc=0x0c055da0u; return 0; }
r[3]=0xffffff80u;
goto P_0c055da2;
P_0c055da2: /* original d10e, guest PC 0x0c055da2 */
if(!s->budget--) { s->failed_pc=0x0c055da2u; return 0; }
r[1]=read(ram,0x0c055ddcu,4);
goto P_0c055da4;
P_0c055da4: /* original 633c, guest PC 0x0c055da4 */
if(!s->budget--) { s->failed_pc=0x0c055da4u; return 0; }
r[3]=r[3]&255u;
goto P_0c055da6;
P_0c055da6: /* original d20e, guest PC 0x0c055da6 */
if(!s->budget--) { s->failed_pc=0x0c055da6u; return 0; }
r[2]=read(ram,0x0c055de0u,4);
goto P_0c055da8;
P_0c055da8: /* original c204, guest PC 0x0c055da8 */
if(!s->budget--) { s->failed_pc=0x0c055da8u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+16,r[0],4);
goto P_0c055daa;
P_0c055daa: /* original 6013, guest PC 0x0c055daa */
if(!s->budget--) { s->failed_pc=0x0c055daau; return 0; }
r[0]=r[1];
goto P_0c055dac;
P_0c055dac: /* original c205, guest PC 0x0c055dac */
if(!s->budget--) { s->failed_pc=0x0c055dacu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+20,r[0],4);
goto P_0c055dae;
P_0c055dae: /* original 6023, guest PC 0x0c055dae */
if(!s->budget--) { s->failed_pc=0x0c055daeu; return 0; }
r[0]=r[2];
goto P_0c055db0;
P_0c055db0: /* original 303c, guest PC 0x0c055db0 */
if(!s->budget--) { s->failed_pc=0x0c055db0u; return 0; }
r[0]+=r[3];
goto P_0c055db2;
P_0c055db2: /* original c203, guest PC 0x0c055db2 */
if(!s->budget--) { s->failed_pc=0x0c055db2u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+12,r[0],4);
goto P_0c055db4;
P_0c055db4: /* original 4f26, guest PC 0x0c055db4 */
if(!s->budget--) { s->failed_pc=0x0c055db4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c055db6;
P_0c055db6: /* original 000b, guest PC 0x0c055db6 */
if(!s->budget--) { s->failed_pc=0x0c055db6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c055db8: /* original 0009, guest PC 0x0c055db8 */
if(!s->budget--) { s->failed_pc=0x0c055db8u; return 0; }
if(!vf3_matrix_family(0x0c055dbau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c055dbau; return 0; } return 1;
P_0c06c360: /* original 4f22, guest PC 0x0c06c360 */
if(!s->budget--) { s->failed_pc=0x0c06c360u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c362;
P_0c06c362: /* original e21f, guest PC 0x0c06c362 */
if(!s->budget--) { s->failed_pc=0x0c06c362u; return 0; }
r[2]=0x0000001fu;
goto P_0c06c364;
P_0c06c364: /* original e108, guest PC 0x0c06c364 */
if(!s->budget--) { s->failed_pc=0x0c06c364u; return 0; }
r[1]=0x00000008u;
goto P_0c06c366;
P_0c06c366: /* original 7ffc, guest PC 0x0c06c366 */
if(!s->budget--) { s->failed_pc=0x0c06c366u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c368;
P_0c06c368: /* original 2f42, guest PC 0x0c06c368 */
if(!s->budget--) { s->failed_pc=0x0c06c368u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06c36a;
P_0c06c36a: /* original d345, guest PC 0x0c06c36a */
if(!s->budget--) { s->failed_pc=0x0c06c36au; return 0; }
r[3]=read(ram,0x0c06c480u,4);
goto P_0c06c36c;
P_0c06c36c: /* original d443, guest PC 0x0c06c36c */
if(!s->budget--) { s->failed_pc=0x0c06c36cu; return 0; }
r[4]=read(ram,0x0c06c47cu,4);
goto P_0c06c36e;
P_0c06c36e: /* original 6532, guest PC 0x0c06c36e */
if(!s->budget--) { s->failed_pc=0x0c06c36eu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06c370;
P_0c06c370: /* original 2529, guest PC 0x0c06c370 */
if(!s->budget--) { s->failed_pc=0x0c06c370u; return 0; }
r[5]&=r[2];
goto P_0c06c372;
P_0c06c372: /* original 3513, guest PC 0x0c06c372 */
if(!s->budget--) { s->failed_pc=0x0c06c372u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[1])!=0);
goto P_0c06c374;
P_0c06c374: /* original 8b03, guest PC 0x0c06c374 */
if(!s->budget--) { s->failed_pc=0x0c06c374u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c37e; }
goto P_0c06c376;
P_0c06c376: /* original 7f04, guest PC 0x0c06c376 */
if(!s->budget--) { s->failed_pc=0x0c06c376u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c378;
P_0c06c378: /* original 4f26, guest PC 0x0c06c378 */
if(!s->budget--) { s->failed_pc=0x0c06c378u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c37a;
P_0c06c37a: /* original 000b, guest PC 0x0c06c37a */
if(!s->budget--) { s->failed_pc=0x0c06c37au; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c06c37c: /* original 6053, guest PC 0x0c06c37c */
if(!s->budget--) { s->failed_pc=0x0c06c37cu; return 0; }
r[0]=r[5];
goto P_0c06c37e;
P_0c06c37e: /* original e220, guest PC 0x0c06c37e */
if(!s->budget--) { s->failed_pc=0x0c06c37eu; return 0; }
r[2]=0x00000020u;
goto P_0c06c380;
P_0c06c380: /* original e615, guest PC 0x0c06c380 */
if(!s->budget--) { s->failed_pc=0x0c06c380u; return 0; }
r[6]=0x00000015u;
goto P_0c06c382;
P_0c06c382: /* original 2f26, guest PC 0x0c06c382 */
if(!s->budget--) { s->failed_pc=0x0c06c382u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c384;
P_0c06c384: /* original d33f, guest PC 0x0c06c384 */
if(!s->budget--) { s->failed_pc=0x0c06c384u; return 0; }
r[3]=read(ram,0x0c06c484u,4);
goto P_0c06c386;
P_0c06c386: /* original e701, guest PC 0x0c06c386 */
if(!s->budget--) { s->failed_pc=0x0c06c386u; return 0; }
r[7]=0x00000001u;
goto P_0c06c388;
P_0c06c388: /* original 430b, guest PC 0x0c06c388 */
if(!s->budget--) { s->failed_pc=0x0c06c388u; return 0; }
target=r[3];
r[16]=code_base|0x0c06c38cu;
r[5]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c38cu) { target=s->pc; goto dispatch; }
goto P_0c06c38c;
P_0c06c38a: /* original 55f1, guest PC 0x0c06c38a */
if(!s->budget--) { s->failed_pc=0x0c06c38au; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c06c38c;
P_0c06c38c: /* original e000, guest PC 0x0c06c38c */
if(!s->budget--) { s->failed_pc=0x0c06c38cu; return 0; }
r[0]=0x00000000u;
goto P_0c06c38e;
P_0c06c38e: /* original 7f04, guest PC 0x0c06c38e */
if(!s->budget--) { s->failed_pc=0x0c06c38eu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c390;
P_0c06c390: /* original 7f04, guest PC 0x0c06c390 */
if(!s->budget--) { s->failed_pc=0x0c06c390u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c392;
P_0c06c392: /* original 4f26, guest PC 0x0c06c392 */
if(!s->budget--) { s->failed_pc=0x0c06c392u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c394;
P_0c06c394: /* original 000b, guest PC 0x0c06c394 */
if(!s->budget--) { s->failed_pc=0x0c06c394u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06c396: /* original 0009, guest PC 0x0c06c396 */
if(!s->budget--) { s->failed_pc=0x0c06c396u; return 0; }
goto P_0c06c398;
P_0c06c398: /* original 4f22, guest PC 0x0c06c398 */
if(!s->budget--) { s->failed_pc=0x0c06c398u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c39a;
P_0c06c39a: /* original e21f, guest PC 0x0c06c39a */
if(!s->budget--) { s->failed_pc=0x0c06c39au; return 0; }
r[2]=0x0000001fu;
goto P_0c06c39c;
P_0c06c39c: /* original e108, guest PC 0x0c06c39c */
if(!s->budget--) { s->failed_pc=0x0c06c39cu; return 0; }
r[1]=0x00000008u;
goto P_0c06c39e;
P_0c06c39e: /* original 7ffc, guest PC 0x0c06c39e */
if(!s->budget--) { s->failed_pc=0x0c06c39eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c3a0;
P_0c06c3a0: /* original 2f42, guest PC 0x0c06c3a0 */
if(!s->budget--) { s->failed_pc=0x0c06c3a0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06c3a2;
P_0c06c3a2: /* original d337, guest PC 0x0c06c3a2 */
if(!s->budget--) { s->failed_pc=0x0c06c3a2u; return 0; }
r[3]=read(ram,0x0c06c480u,4);
goto P_0c06c3a4;
P_0c06c3a4: /* original d435, guest PC 0x0c06c3a4 */
if(!s->budget--) { s->failed_pc=0x0c06c3a4u; return 0; }
r[4]=read(ram,0x0c06c47cu,4);
goto P_0c06c3a6;
P_0c06c3a6: /* original 6532, guest PC 0x0c06c3a6 */
if(!s->budget--) { s->failed_pc=0x0c06c3a6u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06c3a8;
P_0c06c3a8: /* original 2529, guest PC 0x0c06c3a8 */
if(!s->budget--) { s->failed_pc=0x0c06c3a8u; return 0; }
r[5]&=r[2];
goto P_0c06c3aa;
P_0c06c3aa: /* original 3513, guest PC 0x0c06c3aa */
if(!s->budget--) { s->failed_pc=0x0c06c3aau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[1])!=0);
goto P_0c06c3ac;
P_0c06c3ac: /* original 8b03, guest PC 0x0c06c3ac */
if(!s->budget--) { s->failed_pc=0x0c06c3acu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c3b6; }
goto P_0c06c3ae;
P_0c06c3ae: /* original 7f04, guest PC 0x0c06c3ae */
if(!s->budget--) { s->failed_pc=0x0c06c3aeu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c3b0;
P_0c06c3b0: /* original 4f26, guest PC 0x0c06c3b0 */
if(!s->budget--) { s->failed_pc=0x0c06c3b0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c3b2;
P_0c06c3b2: /* original 000b, guest PC 0x0c06c3b2 */
if(!s->budget--) { s->failed_pc=0x0c06c3b2u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c06c3b4: /* original 6053, guest PC 0x0c06c3b4 */
if(!s->budget--) { s->failed_pc=0x0c06c3b4u; return 0; }
r[0]=r[5];
goto P_0c06c3b6;
P_0c06c3b6: /* original e220, guest PC 0x0c06c3b6 */
if(!s->budget--) { s->failed_pc=0x0c06c3b6u; return 0; }
r[2]=0x00000020u;
goto P_0c06c3b8;
P_0c06c3b8: /* original e618, guest PC 0x0c06c3b8 */
if(!s->budget--) { s->failed_pc=0x0c06c3b8u; return 0; }
r[6]=0x00000018u;
goto P_0c06c3ba;
P_0c06c3ba: /* original 2f26, guest PC 0x0c06c3ba */
if(!s->budget--) { s->failed_pc=0x0c06c3bau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c3bc;
P_0c06c3bc: /* original d331, guest PC 0x0c06c3bc */
if(!s->budget--) { s->failed_pc=0x0c06c3bcu; return 0; }
r[3]=read(ram,0x0c06c484u,4);
goto P_0c06c3be;
P_0c06c3be: /* original e701, guest PC 0x0c06c3be */
if(!s->budget--) { s->failed_pc=0x0c06c3beu; return 0; }
r[7]=0x00000001u;
goto P_0c06c3c0;
P_0c06c3c0: /* original 430b, guest PC 0x0c06c3c0 */
if(!s->budget--) { s->failed_pc=0x0c06c3c0u; return 0; }
target=r[3];
r[16]=code_base|0x0c06c3c4u;
r[5]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c3c4u) { target=s->pc; goto dispatch; }
goto P_0c06c3c4;
P_0c06c3c2: /* original 55f1, guest PC 0x0c06c3c2 */
if(!s->budget--) { s->failed_pc=0x0c06c3c2u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c06c3c4;
P_0c06c3c4: /* original e000, guest PC 0x0c06c3c4 */
if(!s->budget--) { s->failed_pc=0x0c06c3c4u; return 0; }
r[0]=0x00000000u;
goto P_0c06c3c6;
P_0c06c3c6: /* original 7f04, guest PC 0x0c06c3c6 */
if(!s->budget--) { s->failed_pc=0x0c06c3c6u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c3c8;
P_0c06c3c8: /* original 7f04, guest PC 0x0c06c3c8 */
if(!s->budget--) { s->failed_pc=0x0c06c3c8u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c3ca;
P_0c06c3ca: /* original 4f26, guest PC 0x0c06c3ca */
if(!s->budget--) { s->failed_pc=0x0c06c3cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c3cc;
P_0c06c3cc: /* original 000b, guest PC 0x0c06c3cc */
if(!s->budget--) { s->failed_pc=0x0c06c3ccu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06c3ce: /* original 0009, guest PC 0x0c06c3ce */
if(!s->budget--) { s->failed_pc=0x0c06c3ceu; return 0; }
if(!vf3_matrix_family(0x0c06c3d0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06c3d0u; return 0; } return 1;
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
r[16]=code_base|0x0c06c41au;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c41au) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(0x0c06c422u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06c422u; return 0; } return 1;
P_0c06c8a4: /* original 2fe6, guest PC 0x0c06c8a4 */
if(!s->budget--) { s->failed_pc=0x0c06c8a4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c8a6;
P_0c06c8a6: /* original e207, guest PC 0x0c06c8a6 */
if(!s->budget--) { s->failed_pc=0x0c06c8a6u; return 0; }
r[2]=0x00000007u;
goto P_0c06c8a8;
P_0c06c8a8: /* original 2fd6, guest PC 0x0c06c8a8 */
if(!s->budget--) { s->failed_pc=0x0c06c8a8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c8aa;
P_0c06c8aa: /* original ee08, guest PC 0x0c06c8aa */
if(!s->budget--) { s->failed_pc=0x0c06c8aau; return 0; }
r[14]=0x00000008u;
goto P_0c06c8ac;
P_0c06c8ac: /* original d317, guest PC 0x0c06c8ac */
if(!s->budget--) { s->failed_pc=0x0c06c8acu; return 0; }
r[3]=read(ram,0x0c06c90cu,4);
goto P_0c06c8ae;
P_0c06c8ae: /* original 9023, guest PC 0x0c06c8ae */
if(!s->budget--) { s->failed_pc=0x0c06c8aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8f8u,2);
goto P_0c06c8b0;
P_0c06c8b0: /* original 6432, guest PC 0x0c06c8b0 */
if(!s->budget--) { s->failed_pc=0x0c06c8b0u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c06c8b2;
P_0c06c8b2: /* original 4f22, guest PC 0x0c06c8b2 */
if(!s->budget--) { s->failed_pc=0x0c06c8b2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c8b4;
P_0c06c8b4: /* original 7401, guest PC 0x0c06c8b4 */
if(!s->budget--) { s->failed_pc=0x0c06c8b4u; return 0; }
r[4]+=0x00000001u;
goto P_0c06c8b6;
P_0c06c8b6: /* original 6543, guest PC 0x0c06c8b6 */
if(!s->budget--) { s->failed_pc=0x0c06c8b6u; return 0; }
r[5]=r[4];
goto P_0c06c8b8;
P_0c06c8b8: /* original d413, guest PC 0x0c06c8b8 */
if(!s->budget--) { s->failed_pc=0x0c06c8b8u; return 0; }
r[4]=read(ram,0x0c06c908u,4);
goto P_0c06c8ba;
P_0c06c8ba: /* original 7ffc, guest PC 0x0c06c8ba */
if(!s->budget--) { s->failed_pc=0x0c06c8bau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c8bc;
P_0c06c8bc: /* original 014c, guest PC 0x0c06c8bc */
if(!s->budget--) { s->failed_pc=0x0c06c8bcu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c8be;
P_0c06c8be: /* original 452d, guest PC 0x0c06c8be */
if(!s->budget--) { s->failed_pc=0x0c06c8beu; return 0; }
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?r[5]>>((-r[2])&31u):0):r[5]<<(r[2]&31u);
goto P_0c06c8c0;
P_0c06c8c0: /* original 6013, guest PC 0x0c06c8c0 */
if(!s->budget--) { s->failed_pc=0x0c06c8c0u; return 0; }
r[0]=r[1];
goto P_0c06c8c2;
P_0c06c8c2: /* original 8801, guest PC 0x0c06c8c2 */
if(!s->budget--) { s->failed_pc=0x0c06c8c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c8c4;
P_0c06c8c4: /* original 2f12, guest PC 0x0c06c8c4 */
if(!s->budget--) { s->failed_pc=0x0c06c8c4u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c06c8c6;
P_0c06c8c6: /* original 8f02, guest PC 0x0c06c8c6 */
if(!s->budget--) { s->failed_pc=0x0c06c8c6u; return 0; }
cond=r[17]&1u;
r[14]|=r[5];
if(!cond) { goto P_0c06c8ce; }
goto P_0c06c8ca;
P_0c06c8c8: /* original 2e5b, guest PC 0x0c06c8c8 */
if(!s->budget--) { s->failed_pc=0x0c06c8c8u; return 0; }
r[14]|=r[5];
goto P_0c06c8ca;
P_0c06c8ca: /* original ee4e, guest PC 0x0c06c8ca */
if(!s->budget--) { s->failed_pc=0x0c06c8cau; return 0; }
r[14]=0x0000004eu;
goto P_0c06c8cc;
P_0c06c8cc: /* original 2e5b, guest PC 0x0c06c8cc */
if(!s->budget--) { s->failed_pc=0x0c06c8ccu; return 0; }
r[14]|=r[5];
goto P_0c06c8ce;
P_0c06c8ce: /* original 9017, guest PC 0x0c06c8ce */
if(!s->budget--) { s->failed_pc=0x0c06c8ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c900u,2);
goto P_0c06c8d0;
P_0c06c8d0: /* original 004c, guest PC 0x0c06c8d0 */
if(!s->budget--) { s->failed_pc=0x0c06c8d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c8d2;
P_0c06c8d2: /* original 8801, guest PC 0x0c06c8d2 */
if(!s->budget--) { s->failed_pc=0x0c06c8d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c8d4;
P_0c06c8d4: /* original 8d34, guest PC 0x0c06c8d4 */
if(!s->budget--) { s->failed_pc=0x0c06c8d4u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c06c940; }
goto P_0c06c8d8;
P_0c06c8d6: /* original 6503, guest PC 0x0c06c8d6 */
if(!s->budget--) { s->failed_pc=0x0c06c8d6u; return 0; }
r[5]=r[0];
goto P_0c06c8d8;
P_0c06c8d8: /* original 900d, guest PC 0x0c06c8d8 */
if(!s->budget--) { s->failed_pc=0x0c06c8d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8f6u,2);
goto P_0c06c8da;
P_0c06c8da: /* original 004c, guest PC 0x0c06c8da */
if(!s->budget--) { s->failed_pc=0x0c06c8dau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c8dc;
P_0c06c8dc: /* original 8801, guest PC 0x0c06c8dc */
if(!s->budget--) { s->failed_pc=0x0c06c8dcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c8de;
P_0c06c8de: /* original 8d19, guest PC 0x0c06c8de */
if(!s->budget--) { s->failed_pc=0x0c06c8deu; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c06c914; }
goto P_0c06c8e2;
P_0c06c8e0: /* original 6503, guest PC 0x0c06c8e0 */
if(!s->budget--) { s->failed_pc=0x0c06c8e0u; return 0; }
r[5]=r[0];
goto P_0c06c8e2;
P_0c06c8e2: /* original 900a, guest PC 0x0c06c8e2 */
if(!s->budget--) { s->failed_pc=0x0c06c8e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8fau,2);
goto P_0c06c8e4;
P_0c06c8e4: /* original 064c, guest PC 0x0c06c8e4 */
if(!s->budget--) { s->failed_pc=0x0c06c8e4u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c8e6;
P_0c06c8e6: /* original 70ff, guest PC 0x0c06c8e6 */
if(!s->budget--) { s->failed_pc=0x0c06c8e6u; return 0; }
r[0]+=0xffffffffu;
goto P_0c06c8e8;
P_0c06c8e8: /* original 054c, guest PC 0x0c06c8e8 */
if(!s->budget--) { s->failed_pc=0x0c06c8e8u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c8ea;
P_0c06c8ea: /* original 2558, guest PC 0x0c06c8ea */
if(!s->budget--) { s->failed_pc=0x0c06c8eau; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06c8ec;
P_0c06c8ec: /* original 8b1d, guest PC 0x0c06c8ec */
if(!s->budget--) { s->failed_pc=0x0c06c8ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c92a; }
goto P_0c06c8ee;
P_0c06c8ee: /* original 2668, guest PC 0x0c06c8ee */
if(!s->budget--) { s->failed_pc=0x0c06c8eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06c8f0;
P_0c06c8f0: /* original 8b1b, guest PC 0x0c06c8f0 */
if(!s->budget--) { s->failed_pc=0x0c06c8f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c92a; }
goto P_0c06c8f2;
P_0c06c8f2: /* original a022, guest PC 0x0c06c8f2 */
if(!s->budget--) { s->failed_pc=0x0c06c8f2u; return 0; }
goto P_0c06c93a;
P_0c06c8f4: /* original 0009, guest PC 0x0c06c8f4 */
if(!s->budget--) { s->failed_pc=0x0c06c8f4u; return 0; }
if(!vf3_matrix_family(0x0c06c8f6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06c8f6u; return 0; } return 1;
P_0c06c914: /* original 60f2, guest PC 0x0c06c914 */
if(!s->budget--) { s->failed_pc=0x0c06c914u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c06c916;
P_0c06c916: /* original 8801, guest PC 0x0c06c916 */
if(!s->budget--) { s->failed_pc=0x0c06c916u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c918;
P_0c06c918: /* original 89e3, guest PC 0x0c06c918 */
if(!s->budget--) { s->failed_pc=0x0c06c918u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c8e2; }
goto P_0c06c91a;
P_0c06c91a: /* original 906d, guest PC 0x0c06c91a */
if(!s->budget--) { s->failed_pc=0x0c06c91au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c9f8u,2);
goto P_0c06c91c;
P_0c06c91c: /* original 064c, guest PC 0x0c06c91c */
if(!s->budget--) { s->failed_pc=0x0c06c91cu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c91e;
P_0c06c91e: /* original 70ff, guest PC 0x0c06c91e */
if(!s->budget--) { s->failed_pc=0x0c06c91eu; return 0; }
r[0]+=0xffffffffu;
goto P_0c06c920;
P_0c06c920: /* original 054c, guest PC 0x0c06c920 */
if(!s->budget--) { s->failed_pc=0x0c06c920u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c922;
P_0c06c922: /* original 2558, guest PC 0x0c06c922 */
if(!s->budget--) { s->failed_pc=0x0c06c922u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06c924;
P_0c06c924: /* original 8b01, guest PC 0x0c06c924 */
if(!s->budget--) { s->failed_pc=0x0c06c924u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c92a; }
goto P_0c06c926;
P_0c06c926: /* original 2668, guest PC 0x0c06c926 */
if(!s->budget--) { s->failed_pc=0x0c06c926u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06c928;
P_0c06c928: /* original 8907, guest PC 0x0c06c928 */
if(!s->budget--) { s->failed_pc=0x0c06c928u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c93a; }
goto P_0c06c92a;
P_0c06c92a: /* original 9066, guest PC 0x0c06c92a */
if(!s->budget--) { s->failed_pc=0x0c06c92au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c9fau,2);
goto P_0c06c92c;
P_0c06c92c: /* original 064c, guest PC 0x0c06c92c */
if(!s->budget--) { s->failed_pc=0x0c06c92cu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c92e;
P_0c06c92e: /* original 6453, guest PC 0x0c06c92e */
if(!s->budget--) { s->failed_pc=0x0c06c92eu; return 0; }
r[4]=r[5];
goto P_0c06c930;
P_0c06c930: /* original 3462, guest PC 0x0c06c930 */
if(!s->budget--) { s->failed_pc=0x0c06c930u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[6])!=0);
goto P_0c06c932;
P_0c06c932: /* original 8905, guest PC 0x0c06c932 */
if(!s->budget--) { s->failed_pc=0x0c06c932u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c940; }
goto P_0c06c934;
P_0c06c934: /* original dd32, guest PC 0x0c06c934 */
if(!s->budget--) { s->failed_pc=0x0c06c934u; return 0; }
r[13]=read(ram,0x0c06ca00u,4);
goto P_0c06c936;
P_0c06c936: /* original a004, guest PC 0x0c06c936 */
if(!s->budget--) { s->failed_pc=0x0c06c936u; return 0; }
goto P_0c06c942;
P_0c06c938: /* original 0009, guest PC 0x0c06c938 */
if(!s->budget--) { s->failed_pc=0x0c06c938u; return 0; }
goto P_0c06c93a;
P_0c06c93a: /* original dd32, guest PC 0x0c06c93a */
if(!s->budget--) { s->failed_pc=0x0c06c93au; return 0; }
r[13]=read(ram,0x0c06ca04u,4);
goto P_0c06c93c;
P_0c06c93c: /* original a001, guest PC 0x0c06c93c */
if(!s->budget--) { s->failed_pc=0x0c06c93cu; return 0; }
goto P_0c06c942;
P_0c06c93e: /* original 0009, guest PC 0x0c06c93e */
if(!s->budget--) { s->failed_pc=0x0c06c93eu; return 0; }
goto P_0c06c940;
P_0c06c940: /* original dd31, guest PC 0x0c06c940 */
if(!s->budget--) { s->failed_pc=0x0c06c940u; return 0; }
r[13]=read(ram,0x0c06ca08u,4);
goto P_0c06c942;
P_0c06c942: /* original bd29, guest PC 0x0c06c942 */
if(!s->budget--) { s->failed_pc=0x0c06c942u; return 0; }
target=code_base|0x0c06c398u; r[16]=code_base|0x0c06c946u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c946u) { target=s->pc; goto dispatch; }
goto P_0c06c946;
P_0c06c944: /* original 64e3, guest PC 0x0c06c944 */
if(!s->budget--) { s->failed_pc=0x0c06c944u; return 0; }
r[4]=r[14];
goto P_0c06c946;
P_0c06c946: /* original 2008, guest PC 0x0c06c946 */
if(!s->budget--) { s->failed_pc=0x0c06c946u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06c948;
P_0c06c948: /* original 8904, guest PC 0x0c06c948 */
if(!s->budget--) { s->failed_pc=0x0c06c948u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c954; }
goto P_0c06c94a;
P_0c06c94a: /* original d230, guest PC 0x0c06c94a */
if(!s->budget--) { s->failed_pc=0x0c06c94au; return 0; }
r[2]=read(ram,0x0c06ca0cu,4);
goto P_0c06c94c;
P_0c06c94c: /* original 65d3, guest PC 0x0c06c94c */
if(!s->budget--) { s->failed_pc=0x0c06c94cu; return 0; }
r[5]=r[13];
goto P_0c06c94e;
P_0c06c94e: /* original e601, guest PC 0x0c06c94e */
if(!s->budget--) { s->failed_pc=0x0c06c94eu; return 0; }
r[6]=0x00000001u;
goto P_0c06c950;
P_0c06c950: /* original 420b, guest PC 0x0c06c950 */
if(!s->budget--) { s->failed_pc=0x0c06c950u; return 0; }
target=r[2];
r[16]=code_base|0x0c06c954u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c954u) { target=s->pc; goto dispatch; }
goto P_0c06c954;
P_0c06c952: /* original 64e3, guest PC 0x0c06c952 */
if(!s->budget--) { s->failed_pc=0x0c06c952u; return 0; }
r[4]=r[14];
goto P_0c06c954;
P_0c06c954: /* original 7f04, guest PC 0x0c06c954 */
if(!s->budget--) { s->failed_pc=0x0c06c954u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c956;
P_0c06c956: /* original 4f26, guest PC 0x0c06c956 */
if(!s->budget--) { s->failed_pc=0x0c06c956u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c958;
P_0c06c958: /* original 6df6, guest PC 0x0c06c958 */
if(!s->budget--) { s->failed_pc=0x0c06c958u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06c95a;
P_0c06c95a: /* original 000b, guest PC 0x0c06c95a */
if(!s->budget--) { s->failed_pc=0x0c06c95au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c95c: /* original 6ef6, guest PC 0x0c06c95c */
if(!s->budget--) { s->failed_pc=0x0c06c95cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06c95eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
