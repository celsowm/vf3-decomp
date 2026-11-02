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
int vf3_away_batch44_adapter_24(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c081098u: goto P_0c081098;
case 0x0c08109au: goto P_0c08109a;
case 0x0c08109cu: goto P_0c08109c;
case 0x0c08109eu: goto P_0c08109e;
case 0x0c0810a0u: goto P_0c0810a0;
case 0x0c0810a2u: goto P_0c0810a2;
case 0x0c0810a4u: goto P_0c0810a4;
case 0x0c0810a6u: goto P_0c0810a6;
case 0x0c0810a8u: goto P_0c0810a8;
case 0x0c0810aau: goto P_0c0810aa;
case 0x0c0810acu: goto P_0c0810ac;
case 0x0c0810aeu: goto P_0c0810ae;
case 0x0c0810b0u: goto P_0c0810b0;
case 0x0c0810b2u: goto P_0c0810b2;
case 0x0c0810b4u: goto P_0c0810b4;
case 0x0c0810b6u: goto P_0c0810b6;
case 0x0c0810b8u: goto P_0c0810b8;
case 0x0c0810bau: goto P_0c0810ba;
case 0x0c0810bcu: goto P_0c0810bc;
case 0x0c0810beu: goto P_0c0810be;
case 0x0c0810c0u: goto P_0c0810c0;
case 0x0c0810c2u: goto P_0c0810c2;
case 0x0c0810c4u: goto P_0c0810c4;
case 0x0c0810c6u: goto P_0c0810c6;
case 0x0c0810c8u: goto P_0c0810c8;
case 0x0c0810cau: goto P_0c0810ca;
case 0x0c0810ccu: goto P_0c0810cc;
case 0x0c0810ceu: goto P_0c0810ce;
case 0x0c0810d0u: goto P_0c0810d0;
case 0x0c0810d2u: goto P_0c0810d2;
case 0x0c0810d4u: goto P_0c0810d4;
case 0x0c0810d6u: goto P_0c0810d6;
case 0x0c0810d8u: goto P_0c0810d8;
case 0x0c0810dau: goto P_0c0810da;
case 0x0c0810dcu: goto P_0c0810dc;
case 0x0c0810deu: goto P_0c0810de;
case 0x0c0810e0u: goto P_0c0810e0;
case 0x0c0810e2u: goto P_0c0810e2;
case 0x0c0810e4u: goto P_0c0810e4;
case 0x0c0810e6u: goto P_0c0810e6;
case 0x0c0810e8u: goto P_0c0810e8;
case 0x0c0810eau: goto P_0c0810ea;
case 0x0c0810ecu: goto P_0c0810ec;
case 0x0c0810eeu: goto P_0c0810ee;
case 0x0c0810f0u: goto P_0c0810f0;
case 0x0c0810f2u: goto P_0c0810f2;
case 0x0c0810f4u: goto P_0c0810f4;
case 0x0c0810f6u: goto P_0c0810f6;
case 0x0c0810f8u: goto P_0c0810f8;
case 0x0c0810fau: goto P_0c0810fa;
case 0x0c0810fcu: goto P_0c0810fc;
case 0x0c0810feu: goto P_0c0810fe;
case 0x0c081100u: goto P_0c081100;
case 0x0c081102u: goto P_0c081102;
case 0x0c081104u: goto P_0c081104;
case 0x0c081106u: goto P_0c081106;
case 0x0c081108u: goto P_0c081108;
case 0x0c08110au: goto P_0c08110a;
case 0x0c08110cu: goto P_0c08110c;
case 0x0c08110eu: goto P_0c08110e;
case 0x0c081110u: goto P_0c081110;
case 0x0c081112u: goto P_0c081112;
case 0x0c081114u: goto P_0c081114;
case 0x0c081116u: goto P_0c081116;
case 0x0c081118u: goto P_0c081118;
case 0x0c08111au: goto P_0c08111a;
case 0x0c08111cu: goto P_0c08111c;
case 0x0c08111eu: goto P_0c08111e;
case 0x0c081120u: goto P_0c081120;
case 0x0c081122u: goto P_0c081122;
case 0x0c081124u: goto P_0c081124;
case 0x0c081126u: goto P_0c081126;
case 0x0c09571cu: goto P_0c09571c;
case 0x0c09571eu: goto P_0c09571e;
case 0x0c095720u: goto P_0c095720;
case 0x0c095722u: goto P_0c095722;
case 0x0c096864u: goto P_0c096864;
case 0x0c096866u: goto P_0c096866;
case 0x0c096868u: goto P_0c096868;
case 0x0c09686au: goto P_0c09686a;
case 0x0c09686cu: goto P_0c09686c;
case 0x0c09686eu: goto P_0c09686e;
case 0x0c096870u: goto P_0c096870;
case 0x0c096872u: goto P_0c096872;
case 0x0c096874u: goto P_0c096874;
case 0x0c096876u: goto P_0c096876;
case 0x0c096878u: goto P_0c096878;
case 0x0c09687au: goto P_0c09687a;
case 0x0c09687cu: goto P_0c09687c;
case 0x0c09687eu: goto P_0c09687e;
case 0x0c096880u: goto P_0c096880;
case 0x0c096882u: goto P_0c096882;
case 0x0c096884u: goto P_0c096884;
case 0x0c096886u: goto P_0c096886;
case 0x0c096888u: goto P_0c096888;
case 0x0c09688au: goto P_0c09688a;
case 0x0c09688cu: goto P_0c09688c;
case 0x0c09688eu: goto P_0c09688e;
case 0x0c096890u: goto P_0c096890;
case 0x0c096892u: goto P_0c096892;
case 0x0c096894u: goto P_0c096894;
case 0x0c096896u: goto P_0c096896;
case 0x0c096898u: goto P_0c096898;
case 0x0c09689au: goto P_0c09689a;
case 0x0c09689cu: goto P_0c09689c;
case 0x0c09689eu: goto P_0c09689e;
case 0x0c0968a0u: goto P_0c0968a0;
case 0x0c0968a2u: goto P_0c0968a2;
case 0x0c0968a4u: goto P_0c0968a4;
case 0x0c0968a6u: goto P_0c0968a6;
case 0x0c0968a8u: goto P_0c0968a8;
case 0x0c0968aau: goto P_0c0968aa;
case 0x0c0968acu: goto P_0c0968ac;
case 0x0c0968aeu: goto P_0c0968ae;
case 0x0c0a7f5au: goto P_0c0a7f5a;
case 0x0c0a7f5cu: goto P_0c0a7f5c;
case 0x0c0a7f5eu: goto P_0c0a7f5e;
case 0x0c0a7f60u: goto P_0c0a7f60;
case 0x0c0a7f62u: goto P_0c0a7f62;
case 0x0c0a7f64u: goto P_0c0a7f64;
case 0x0c0a7f66u: goto P_0c0a7f66;
case 0x0c0a7f68u: goto P_0c0a7f68;
case 0x0c0a7f6au: goto P_0c0a7f6a;
case 0x0c0a7f6cu: goto P_0c0a7f6c;
case 0x0c0a7f6eu: goto P_0c0a7f6e;
case 0x0c0a7f70u: goto P_0c0a7f70;
case 0x0c0a7f72u: goto P_0c0a7f72;
case 0x0c0a7f74u: goto P_0c0a7f74;
case 0x0c0a7f76u: goto P_0c0a7f76;
case 0x0c0a7f78u: goto P_0c0a7f78;
case 0x0c0a7f7au: goto P_0c0a7f7a;
case 0x0c0a7f7cu: goto P_0c0a7f7c;
case 0x0c0a7f7eu: goto P_0c0a7f7e;
case 0x0c0a7f80u: goto P_0c0a7f80;
case 0x0c0a7f82u: goto P_0c0a7f82;
case 0x0c0a7f84u: goto P_0c0a7f84;
case 0x0c0a7f86u: goto P_0c0a7f86;
case 0x0c0a7f88u: goto P_0c0a7f88;
case 0x0c0a7f8au: goto P_0c0a7f8a;
case 0x0c0a7f8cu: goto P_0c0a7f8c;
case 0x0c0a7f8eu: goto P_0c0a7f8e;
case 0x0c0a7f90u: goto P_0c0a7f90;
case 0x0c0a7f92u: goto P_0c0a7f92;
case 0x0c0a7f94u: goto P_0c0a7f94;
case 0x0c0a7f96u: goto P_0c0a7f96;
case 0x0c0a7f98u: goto P_0c0a7f98;
case 0x0c0a7f9au: goto P_0c0a7f9a;
case 0x0c0a7f9cu: goto P_0c0a7f9c;
case 0x0c0a7f9eu: goto P_0c0a7f9e;
case 0x0c0a7fa0u: goto P_0c0a7fa0;
case 0x0c0a7fa2u: goto P_0c0a7fa2;
case 0x0c0a7fa4u: goto P_0c0a7fa4;
case 0x0c0a7fc0u: goto P_0c0a7fc0;
case 0x0c0a7fc2u: goto P_0c0a7fc2;
case 0x0c0a7fc4u: goto P_0c0a7fc4;
case 0x0c0a7fc6u: goto P_0c0a7fc6;
case 0x0c0a7fc8u: goto P_0c0a7fc8;
case 0x0c0a7fcau: goto P_0c0a7fca;
case 0x0c0a7fccu: goto P_0c0a7fcc;
case 0x0c0a7fceu: goto P_0c0a7fce;
case 0x0c0a7fd0u: goto P_0c0a7fd0;
case 0x0c0a7fd2u: goto P_0c0a7fd2;
case 0x0c0a7fd4u: goto P_0c0a7fd4;
case 0x0c0a7fd6u: goto P_0c0a7fd6;
case 0x0c0a7fd8u: goto P_0c0a7fd8;
case 0x0c0a7fdau: goto P_0c0a7fda;
case 0x0c0a7fdcu: goto P_0c0a7fdc;
case 0x0c0a7fdeu: goto P_0c0a7fde;
case 0x0c0a7fe0u: goto P_0c0a7fe0;
case 0x0c0a7fe2u: goto P_0c0a7fe2;
case 0x0c0a7fe4u: goto P_0c0a7fe4;
case 0x0c0a7fe6u: goto P_0c0a7fe6;
case 0x0c0a7fe8u: goto P_0c0a7fe8;
case 0x0c0a7feau: goto P_0c0a7fea;
case 0x0c0a7fecu: goto P_0c0a7fec;
case 0x0c0a7feeu: goto P_0c0a7fee;
case 0x0c0a7ff0u: goto P_0c0a7ff0;
case 0x0c0a7ff2u: goto P_0c0a7ff2;
case 0x0c0a7ff4u: goto P_0c0a7ff4;
case 0x0c0a7ff6u: goto P_0c0a7ff6;
case 0x0c0a7ff8u: goto P_0c0a7ff8;
case 0x0c0a7ffau: goto P_0c0a7ffa;
case 0x0c0a7ffcu: goto P_0c0a7ffc;
case 0x0c0a7ffeu: goto P_0c0a7ffe;
case 0x0c0a8000u: goto P_0c0a8000;
case 0x0c0a8002u: goto P_0c0a8002;
case 0x0c0a8004u: goto P_0c0a8004;
case 0x0c0a8006u: goto P_0c0a8006;
case 0x0c0a8008u: goto P_0c0a8008;
case 0x0c0a800au: goto P_0c0a800a;
case 0x0c0a800cu: goto P_0c0a800c;
case 0x0c0a800eu: goto P_0c0a800e;
case 0x0c0a8010u: goto P_0c0a8010;
case 0x0c0a8012u: goto P_0c0a8012;
case 0x0c0a8014u: goto P_0c0a8014;
case 0x0c0a8016u: goto P_0c0a8016;
case 0x0c0a8018u: goto P_0c0a8018;
case 0x0c0a801au: goto P_0c0a801a;
case 0x0c0a801cu: goto P_0c0a801c;
case 0x0c0a801eu: goto P_0c0a801e;
case 0x0c0a8020u: goto P_0c0a8020;
case 0x0c0a8022u: goto P_0c0a8022;
case 0x0c0a8024u: goto P_0c0a8024;
case 0x0c0a8026u: goto P_0c0a8026;
case 0x0c0a8028u: goto P_0c0a8028;
case 0x0c0a802au: goto P_0c0a802a;
case 0x0c0a802cu: goto P_0c0a802c;
case 0x0c0a802eu: goto P_0c0a802e;
case 0x0c0a8030u: goto P_0c0a8030;
case 0x0c0a8032u: goto P_0c0a8032;
case 0x0c0a8034u: goto P_0c0a8034;
case 0x0c0a8036u: goto P_0c0a8036;
case 0x0c0a8038u: goto P_0c0a8038;
case 0x0c0a803au: goto P_0c0a803a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c081098: /* original 4f22, guest PC 0x0c081098 */
if(!s->budget--) { s->failed_pc=0x0c081098u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08109a;
P_0c08109a: /* original 6742, guest PC 0x0c08109a */
if(!s->budget--) { s->failed_pc=0x0c08109au; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c08109c;
P_0c08109c: /* original d330, guest PC 0x0c08109c */
if(!s->budget--) { s->failed_pc=0x0c08109cu; return 0; }
r[3]=read(ram,0x0c081160u,4);
goto P_0c08109e;
P_0c08109e: /* original 4f12, guest PC 0x0c08109e */
if(!s->budget--) { s->failed_pc=0x0c08109eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0810a0;
P_0c0810a0: /* original 6173, guest PC 0x0c0810a0 */
if(!s->budget--) { s->failed_pc=0x0c0810a0u; return 0; }
r[1]=r[7];
goto P_0c0810a2;
P_0c0810a2: /* original 430b, guest PC 0x0c0810a2 */
if(!s->budget--) { s->failed_pc=0x0c0810a2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0810a6u;
r[0]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0810a6u) { target=s->pc; goto dispatch; }
goto P_0c0810a6;
P_0c0810a4: /* original 6053, guest PC 0x0c0810a4 */
if(!s->budget--) { s->failed_pc=0x0c0810a4u; return 0; }
r[0]=r[5];
goto P_0c0810a6;
P_0c0810a6: /* original 6603, guest PC 0x0c0810a6 */
if(!s->budget--) { s->failed_pc=0x0c0810a6u; return 0; }
r[6]=r[0];
goto P_0c0810a8;
P_0c0810a8: /* original 6273, guest PC 0x0c0810a8 */
if(!s->budget--) { s->failed_pc=0x0c0810a8u; return 0; }
r[2]=r[7];
goto P_0c0810aa;
P_0c0810aa: /* original 0567, guest PC 0x0c0810aa */
if(!s->budget--) { s->failed_pc=0x0c0810aau; return 0; }
r[19]=r[5]*r[6];
goto P_0c0810ac;
P_0c0810ac: /* original 2462, guest PC 0x0c0810ac */
if(!s->budget--) { s->failed_pc=0x0c0810acu; return 0; }
write(ram,r[4],r[6],4);
goto P_0c0810ae;
P_0c0810ae: /* original 051a, guest PC 0x0c0810ae */
if(!s->budget--) { s->failed_pc=0x0c0810aeu; return 0; }
r[5]=r[19];
goto P_0c0810b0;
P_0c0810b0: /* original 4f16, guest PC 0x0c0810b0 */
if(!s->budget--) { s->failed_pc=0x0c0810b0u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0810b2;
P_0c0810b2: /* original 3258, guest PC 0x0c0810b2 */
if(!s->budget--) { s->failed_pc=0x0c0810b2u; return 0; }
r[2]-=r[5];
goto P_0c0810b4;
P_0c0810b4: /* original 4f26, guest PC 0x0c0810b4 */
if(!s->budget--) { s->failed_pc=0x0c0810b4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0810b6;
P_0c0810b6: /* original 6023, guest PC 0x0c0810b6 */
if(!s->budget--) { s->failed_pc=0x0c0810b6u; return 0; }
r[0]=r[2];
goto P_0c0810b8;
P_0c0810b8: /* original 000b, guest PC 0x0c0810b8 */
if(!s->budget--) { s->failed_pc=0x0c0810b8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0810ba: /* original 0009, guest PC 0x0c0810ba */
if(!s->budget--) { s->failed_pc=0x0c0810bau; return 0; }
goto P_0c0810bc;
P_0c0810bc: /* original 2fe6, guest PC 0x0c0810bc */
if(!s->budget--) { s->failed_pc=0x0c0810bcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0810be;
P_0c0810be: /* original d329, guest PC 0x0c0810be */
if(!s->budget--) { s->failed_pc=0x0c0810beu; return 0; }
r[3]=read(ram,0x0c081164u,4);
goto P_0c0810c0;
P_0c0810c0: /* original 4f22, guest PC 0x0c0810c0 */
if(!s->budget--) { s->failed_pc=0x0c0810c0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0810c2;
P_0c0810c2: /* original 6030, guest PC 0x0c0810c2 */
if(!s->budget--) { s->failed_pc=0x0c0810c2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0810c4;
P_0c0810c4: /* original 600c, guest PC 0x0c0810c4 */
if(!s->budget--) { s->failed_pc=0x0c0810c4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0810c6;
P_0c0810c6: /* original 8803, guest PC 0x0c0810c6 */
if(!s->budget--) { s->failed_pc=0x0c0810c6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0810c8;
P_0c0810c8: /* original 8b10, guest PC 0x0c0810c8 */
if(!s->budget--) { s->failed_pc=0x0c0810c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0810ec; }
goto P_0c0810ca;
P_0c0810ca: /* original d128, guest PC 0x0c0810ca */
if(!s->budget--) { s->failed_pc=0x0c0810cau; return 0; }
r[1]=read(ram,0x0c08116cu,4);
goto P_0c0810cc;
P_0c0810cc: /* original d326, guest PC 0x0c0810cc */
if(!s->budget--) { s->failed_pc=0x0c0810ccu; return 0; }
r[3]=read(ram,0x0c081168u,4);
goto P_0c0810ce;
P_0c0810ce: /* original 6212, guest PC 0x0c0810ce */
if(!s->budget--) { s->failed_pc=0x0c0810ceu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0810d0;
P_0c0810d0: /* original 2238, guest PC 0x0c0810d0 */
if(!s->budget--) { s->failed_pc=0x0c0810d0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0810d2;
P_0c0810d2: /* original 8b0b, guest PC 0x0c0810d2 */
if(!s->budget--) { s->failed_pc=0x0c0810d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0810ec; }
goto P_0c0810d4;
P_0c0810d4: /* original d327, guest PC 0x0c0810d4 */
if(!s->budget--) { s->failed_pc=0x0c0810d4u; return 0; }
r[3]=read(ram,0x0c081174u,4);
goto P_0c0810d6;
P_0c0810d6: /* original e500, guest PC 0x0c0810d6 */
if(!s->budget--) { s->failed_pc=0x0c0810d6u; return 0; }
r[5]=0x00000000u;
goto P_0c0810d8;
P_0c0810d8: /* original de25, guest PC 0x0c0810d8 */
if(!s->budget--) { s->failed_pc=0x0c0810d8u; return 0; }
r[14]=read(ram,0x0c081170u,4);
goto P_0c0810da;
P_0c0810da: /* original 430b, guest PC 0x0c0810da */
if(!s->budget--) { s->failed_pc=0x0c0810dau; return 0; }
target=r[3];
r[16]=code_base|0x0c0810deu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0810deu) { target=s->pc; goto dispatch; }
goto P_0c0810de;
P_0c0810dc: /* original 64e3, guest PC 0x0c0810dc */
if(!s->budget--) { s->failed_pc=0x0c0810dcu; return 0; }
r[4]=r[14];
goto P_0c0810de;
P_0c0810de: /* original d226, guest PC 0x0c0810de */
if(!s->budget--) { s->failed_pc=0x0c0810deu; return 0; }
r[2]=read(ram,0x0c081178u,4);
goto P_0c0810e0;
P_0c0810e0: /* original 420b, guest PC 0x0c0810e0 */
if(!s->budget--) { s->failed_pc=0x0c0810e0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0810e4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0810e4u) { target=s->pc; goto dispatch; }
goto P_0c0810e4;
P_0c0810e2: /* original 0009, guest PC 0x0c0810e2 */
if(!s->budget--) { s->failed_pc=0x0c0810e2u; return 0; }
goto P_0c0810e4;
P_0c0810e4: /* original d323, guest PC 0x0c0810e4 */
if(!s->budget--) { s->failed_pc=0x0c0810e4u; return 0; }
r[3]=read(ram,0x0c081174u,4);
goto P_0c0810e6;
P_0c0810e6: /* original 9533, guest PC 0x0c0810e6 */
if(!s->budget--) { s->failed_pc=0x0c0810e6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081150u,2);
goto P_0c0810e8;
P_0c0810e8: /* original 430b, guest PC 0x0c0810e8 */
if(!s->budget--) { s->failed_pc=0x0c0810e8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0810ecu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0810ecu) { target=s->pc; goto dispatch; }
goto P_0c0810ec;
P_0c0810ea: /* original 64e3, guest PC 0x0c0810ea */
if(!s->budget--) { s->failed_pc=0x0c0810eau; return 0; }
r[4]=r[14];
goto P_0c0810ec;
P_0c0810ec: /* original 4f26, guest PC 0x0c0810ec */
if(!s->budget--) { s->failed_pc=0x0c0810ecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0810ee;
P_0c0810ee: /* original 000b, guest PC 0x0c0810ee */
if(!s->budget--) { s->failed_pc=0x0c0810eeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0810f0: /* original 6ef6, guest PC 0x0c0810f0 */
if(!s->budget--) { s->failed_pc=0x0c0810f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0810f2;
P_0c0810f2: /* original 2fe6, guest PC 0x0c0810f2 */
if(!s->budget--) { s->failed_pc=0x0c0810f2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0810f4;
P_0c0810f4: /* original d31b, guest PC 0x0c0810f4 */
if(!s->budget--) { s->failed_pc=0x0c0810f4u; return 0; }
r[3]=read(ram,0x0c081164u,4);
goto P_0c0810f6;
P_0c0810f6: /* original 4f22, guest PC 0x0c0810f6 */
if(!s->budget--) { s->failed_pc=0x0c0810f6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0810f8;
P_0c0810f8: /* original 6030, guest PC 0x0c0810f8 */
if(!s->budget--) { s->failed_pc=0x0c0810f8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0810fa;
P_0c0810fa: /* original 600c, guest PC 0x0c0810fa */
if(!s->budget--) { s->failed_pc=0x0c0810fau; return 0; }
r[0]=r[0]&255u;
goto P_0c0810fc;
P_0c0810fc: /* original 8803, guest PC 0x0c0810fc */
if(!s->budget--) { s->failed_pc=0x0c0810fcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0810fe;
P_0c0810fe: /* original 8910, guest PC 0x0c0810fe */
if(!s->budget--) { s->failed_pc=0x0c0810feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c081122; }
goto P_0c081100;
P_0c081100: /* original d11a, guest PC 0x0c081100 */
if(!s->budget--) { s->failed_pc=0x0c081100u; return 0; }
r[1]=read(ram,0x0c08116cu,4);
goto P_0c081102;
P_0c081102: /* original d319, guest PC 0x0c081102 */
if(!s->budget--) { s->failed_pc=0x0c081102u; return 0; }
r[3]=read(ram,0x0c081168u,4);
goto P_0c081104;
P_0c081104: /* original 6212, guest PC 0x0c081104 */
if(!s->budget--) { s->failed_pc=0x0c081104u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c081106;
P_0c081106: /* original 2238, guest PC 0x0c081106 */
if(!s->budget--) { s->failed_pc=0x0c081106u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c081108;
P_0c081108: /* original 8b0b, guest PC 0x0c081108 */
if(!s->budget--) { s->failed_pc=0x0c081108u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c081122; }
goto P_0c08110a;
P_0c08110a: /* original d31a, guest PC 0x0c08110a */
if(!s->budget--) { s->failed_pc=0x0c08110au; return 0; }
r[3]=read(ram,0x0c081174u,4);
goto P_0c08110c;
P_0c08110c: /* original e500, guest PC 0x0c08110c */
if(!s->budget--) { s->failed_pc=0x0c08110cu; return 0; }
r[5]=0x00000000u;
goto P_0c08110e;
P_0c08110e: /* original de18, guest PC 0x0c08110e */
if(!s->budget--) { s->failed_pc=0x0c08110eu; return 0; }
r[14]=read(ram,0x0c081170u,4);
goto P_0c081110;
P_0c081110: /* original 430b, guest PC 0x0c081110 */
if(!s->budget--) { s->failed_pc=0x0c081110u; return 0; }
target=r[3];
r[16]=code_base|0x0c081114u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081114u) { target=s->pc; goto dispatch; }
goto P_0c081114;
P_0c081112: /* original 64e3, guest PC 0x0c081112 */
if(!s->budget--) { s->failed_pc=0x0c081112u; return 0; }
r[4]=r[14];
goto P_0c081114;
P_0c081114: /* original d219, guest PC 0x0c081114 */
if(!s->budget--) { s->failed_pc=0x0c081114u; return 0; }
r[2]=read(ram,0x0c08117cu,4);
goto P_0c081116;
P_0c081116: /* original 420b, guest PC 0x0c081116 */
if(!s->budget--) { s->failed_pc=0x0c081116u; return 0; }
target=r[2];
r[16]=code_base|0x0c08111au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08111au) { target=s->pc; goto dispatch; }
goto P_0c08111a;
P_0c081118: /* original 0009, guest PC 0x0c081118 */
if(!s->budget--) { s->failed_pc=0x0c081118u; return 0; }
goto P_0c08111a;
P_0c08111a: /* original d316, guest PC 0x0c08111a */
if(!s->budget--) { s->failed_pc=0x0c08111au; return 0; }
r[3]=read(ram,0x0c081174u,4);
goto P_0c08111c;
P_0c08111c: /* original 9518, guest PC 0x0c08111c */
if(!s->budget--) { s->failed_pc=0x0c08111cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081150u,2);
goto P_0c08111e;
P_0c08111e: /* original 430b, guest PC 0x0c08111e */
if(!s->budget--) { s->failed_pc=0x0c08111eu; return 0; }
target=r[3];
r[16]=code_base|0x0c081122u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c081122u) { target=s->pc; goto dispatch; }
goto P_0c081122;
P_0c081120: /* original 64e3, guest PC 0x0c081120 */
if(!s->budget--) { s->failed_pc=0x0c081120u; return 0; }
r[4]=r[14];
goto P_0c081122;
P_0c081122: /* original 4f26, guest PC 0x0c081122 */
if(!s->budget--) { s->failed_pc=0x0c081122u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c081124;
P_0c081124: /* original 000b, guest PC 0x0c081124 */
if(!s->budget--) { s->failed_pc=0x0c081124u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c081126: /* original 6ef6, guest PC 0x0c081126 */
if(!s->budget--) { s->failed_pc=0x0c081126u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c081128u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c081128u; return 0; } return 1;
P_0c09571c: /* original d21c, guest PC 0x0c09571c */
if(!s->budget--) { s->failed_pc=0x0c09571cu; return 0; }
r[2]=read(ram,0x0c095790u,4);
goto P_0c09571e;
P_0c09571e: /* original 6322, guest PC 0x0c09571e */
if(!s->budget--) { s->failed_pc=0x0c09571eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c095720;
P_0c095720: /* original 432b, guest PC 0x0c095720 */
if(!s->budget--) { s->failed_pc=0x0c095720u; return 0; }
target=r[3];
r[4]=0x00000001u;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
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
P_0c095722: /* original e401, guest PC 0x0c095722 */
if(!s->budget--) { s->failed_pc=0x0c095722u; return 0; }
r[4]=0x00000001u;
if(!vf3_matrix_family(0x0c095724u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095724u; return 0; } return 1;
P_0c096864: /* original 2fe6, guest PC 0x0c096864 */
if(!s->budget--) { s->failed_pc=0x0c096864u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096866;
P_0c096866: /* original 4f22, guest PC 0x0c096866 */
if(!s->budget--) { s->failed_pc=0x0c096866u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c096868;
P_0c096868: /* original 7ff8, guest PC 0x0c096868 */
if(!s->budget--) { s->failed_pc=0x0c096868u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c09686a;
P_0c09686a: /* original 2f42, guest PC 0x0c09686a */
if(!s->budget--) { s->failed_pc=0x0c09686au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09686c;
P_0c09686c: /* original d311, guest PC 0x0c09686c */
if(!s->budget--) { s->failed_pc=0x0c09686cu; return 0; }
r[3]=read(ram,0x0c0968b4u,4);
goto P_0c09686e;
P_0c09686e: /* original 430b, guest PC 0x0c09686e */
if(!s->budget--) { s->failed_pc=0x0c09686eu; return 0; }
target=r[3];
r[16]=code_base|0x0c096872u;
write(ram,r[15]+4,r[5],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096872u) { target=s->pc; goto dispatch; }
goto P_0c096872;
P_0c096870: /* original 1f51, guest PC 0x0c096870 */
if(!s->budget--) { s->failed_pc=0x0c096870u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c096872;
P_0c096872: /* original 6e03, guest PC 0x0c096872 */
if(!s->budget--) { s->failed_pc=0x0c096872u; return 0; }
r[14]=r[0];
goto P_0c096874;
P_0c096874: /* original 2ee8, guest PC 0x0c096874 */
if(!s->budget--) { s->failed_pc=0x0c096874u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c096876;
P_0c096876: /* original 8905, guest PC 0x0c096876 */
if(!s->budget--) { s->failed_pc=0x0c096876u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096884; }
goto P_0c096878;
P_0c096878: /* original d30f, guest PC 0x0c096878 */
if(!s->budget--) { s->failed_pc=0x0c096878u; return 0; }
r[3]=read(ram,0x0c0968b8u,4);
goto P_0c09687a;
P_0c09687a: /* original 430b, guest PC 0x0c09687a */
if(!s->budget--) { s->failed_pc=0x0c09687au; return 0; }
target=r[3];
r[16]=code_base|0x0c09687eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09687eu) { target=s->pc; goto dispatch; }
goto P_0c09687e;
P_0c09687c: /* original 64e3, guest PC 0x0c09687c */
if(!s->budget--) { s->failed_pc=0x0c09687cu; return 0; }
r[4]=r[14];
goto P_0c09687e;
P_0c09687e: /* original d20f, guest PC 0x0c09687e */
if(!s->budget--) { s->failed_pc=0x0c09687eu; return 0; }
r[2]=read(ram,0x0c0968bcu,4);
goto P_0c096880;
P_0c096880: /* original 420b, guest PC 0x0c096880 */
if(!s->budget--) { s->failed_pc=0x0c096880u; return 0; }
target=r[2];
r[16]=code_base|0x0c096884u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096884u) { target=s->pc; goto dispatch; }
goto P_0c096884;
P_0c096882: /* original 64e3, guest PC 0x0c096882 */
if(!s->budget--) { s->failed_pc=0x0c096882u; return 0; }
r[4]=r[14];
goto P_0c096884;
P_0c096884: /* original 0002, guest PC 0x0c096884 */
if(!s->budget--) { s->failed_pc=0x0c096884u; return 0; }
r[0]=r[17];
goto P_0c096886;
P_0c096886: /* original 9313, guest PC 0x0c096886 */
if(!s->budget--) { s->failed_pc=0x0c096886u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0968b0u,2);
goto P_0c096888;
P_0c096888: /* original 2039, guest PC 0x0c096888 */
if(!s->budget--) { s->failed_pc=0x0c096888u; return 0; }
r[0]&=r[3];
goto P_0c09688a;
P_0c09688a: /* original cbe0, guest PC 0x0c09688a */
if(!s->budget--) { s->failed_pc=0x0c09688au; return 0; }
r[0]|=224u;
goto P_0c09688c;
P_0c09688c: /* original 400e, guest PC 0x0c09688c */
if(!s->budget--) { s->failed_pc=0x0c09688cu; return 0; }
r[17]=r[0];
goto P_0c09688e;
P_0c09688e: /* original d20c, guest PC 0x0c09688e */
if(!s->budget--) { s->failed_pc=0x0c09688eu; return 0; }
r[2]=read(ram,0x0c0968c0u,4);
goto P_0c096890;
P_0c096890: /* original 420b, guest PC 0x0c096890 */
if(!s->budget--) { s->failed_pc=0x0c096890u; return 0; }
target=r[2];
r[16]=code_base|0x0c096894u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096894u) { target=s->pc; goto dispatch; }
goto P_0c096894;
P_0c096892: /* original 0009, guest PC 0x0c096892 */
if(!s->budget--) { s->failed_pc=0x0c096892u; return 0; }
goto P_0c096894;
P_0c096894: /* original d10b, guest PC 0x0c096894 */
if(!s->budget--) { s->failed_pc=0x0c096894u; return 0; }
r[1]=read(ram,0x0c0968c4u,4);
goto P_0c096896;
P_0c096896: /* original 410b, guest PC 0x0c096896 */
if(!s->budget--) { s->failed_pc=0x0c096896u; return 0; }
target=r[1];
r[16]=code_base|0x0c09689au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09689au) { target=s->pc; goto dispatch; }
goto P_0c09689a;
P_0c096898: /* original 0009, guest PC 0x0c096898 */
if(!s->budget--) { s->failed_pc=0x0c096898u; return 0; }
goto P_0c09689a;
P_0c09689a: /* original 0002, guest PC 0x0c09689a */
if(!s->budget--) { s->failed_pc=0x0c09689au; return 0; }
r[0]=r[17];
goto P_0c09689c;
P_0c09689c: /* original 9208, guest PC 0x0c09689c */
if(!s->budget--) { s->failed_pc=0x0c09689cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0968b0u,2);
goto P_0c09689e;
P_0c09689e: /* original 2029, guest PC 0x0c09689e */
if(!s->budget--) { s->failed_pc=0x0c09689eu; return 0; }
r[0]&=r[2];
goto P_0c0968a0;
P_0c0968a0: /* original 400e, guest PC 0x0c0968a0 */
if(!s->budget--) { s->failed_pc=0x0c0968a0u; return 0; }
r[17]=r[0];
goto P_0c0968a2;
P_0c0968a2: /* original 64f2, guest PC 0x0c0968a2 */
if(!s->budget--) { s->failed_pc=0x0c0968a2u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0968a4;
P_0c0968a4: /* original 55f1, guest PC 0x0c0968a4 */
if(!s->budget--) { s->failed_pc=0x0c0968a4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0968a6;
P_0c0968a6: /* original 7f08, guest PC 0x0c0968a6 */
if(!s->budget--) { s->failed_pc=0x0c0968a6u; return 0; }
r[15]+=0x00000008u;
goto P_0c0968a8;
P_0c0968a8: /* original 4f26, guest PC 0x0c0968a8 */
if(!s->budget--) { s->failed_pc=0x0c0968a8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0968aa;
P_0c0968aa: /* original d307, guest PC 0x0c0968aa */
if(!s->budget--) { s->failed_pc=0x0c0968aau; return 0; }
r[3]=read(ram,0x0c0968c8u,4);
goto P_0c0968ac;
P_0c0968ac: /* original 432b, guest PC 0x0c0968ac */
if(!s->budget--) { s->failed_pc=0x0c0968acu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09571cu: goto P_0c09571c;
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
P_0c0968ae: /* original 6ef6, guest PC 0x0c0968ae */
if(!s->budget--) { s->failed_pc=0x0c0968aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0968b0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0968b0u; return 0; } return 1;
P_0c0a7f5a: /* original 2fe6, guest PC 0x0c0a7f5a */
if(!s->budget--) { s->failed_pc=0x0c0a7f5au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f5c;
P_0c0a7f5c: /* original 2fd6, guest PC 0x0c0a7f5c */
if(!s->budget--) { s->failed_pc=0x0c0a7f5cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f5e;
P_0c0a7f5e: /* original 2fc6, guest PC 0x0c0a7f5e */
if(!s->budget--) { s->failed_pc=0x0c0a7f5eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f60;
P_0c0a7f60: /* original 2fb6, guest PC 0x0c0a7f60 */
if(!s->budget--) { s->failed_pc=0x0c0a7f60u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f62;
P_0c0a7f62: /* original 6b43, guest PC 0x0c0a7f62 */
if(!s->budget--) { s->failed_pc=0x0c0a7f62u; return 0; }
r[11]=r[4];
goto P_0c0a7f64;
P_0c0a7f64: /* original 2fa6, guest PC 0x0c0a7f64 */
if(!s->budget--) { s->failed_pc=0x0c0a7f64u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f66;
P_0c0a7f66: /* original e400, guest PC 0x0c0a7f66 */
if(!s->budget--) { s->failed_pc=0x0c0a7f66u; return 0; }
r[4]=0x00000000u;
goto P_0c0a7f68;
P_0c0a7f68: /* original 4f22, guest PC 0x0c0a7f68 */
if(!s->budget--) { s->failed_pc=0x0c0a7f68u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7f6a;
P_0c0a7f6a: /* original 6e43, guest PC 0x0c0a7f6a */
if(!s->budget--) { s->failed_pc=0x0c0a7f6au; return 0; }
r[14]=r[4];
goto P_0c0a7f6c;
P_0c0a7f6c: /* original 7ff4, guest PC 0x0c0a7f6c */
if(!s->budget--) { s->failed_pc=0x0c0a7f6cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a7f6e;
P_0c0a7f6e: /* original 1f52, guest PC 0x0c0a7f6e */
if(!s->budget--) { s->failed_pc=0x0c0a7f6eu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0a7f70;
P_0c0a7f70: /* original 9319, guest PC 0x0c0a7f70 */
if(!s->budget--) { s->failed_pc=0x0c0a7f70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7fa6u,2);
goto P_0c0a7f72;
P_0c0a7f72: /* original 3b33, guest PC 0x0c0a7f72 */
if(!s->budget--) { s->failed_pc=0x0c0a7f72u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[3])!=0);
goto P_0c0a7f74;
P_0c0a7f74: /* original 8f03, guest PC 0x0c0a7f74 */
if(!s->budget--) { s->failed_pc=0x0c0a7f74u; return 0; }
cond=r[17]&1u;
r[10]=r[14];
if(!cond) { goto P_0c0a7f7e; }
goto P_0c0a7f78;
P_0c0a7f76: /* original 6ae3, guest PC 0x0c0a7f76 */
if(!s->budget--) { s->failed_pc=0x0c0a7f76u; return 0; }
r[10]=r[14];
goto P_0c0a7f78;
P_0c0a7f78: /* original de0d, guest PC 0x0c0a7f78 */
if(!s->budget--) { s->failed_pc=0x0c0a7f78u; return 0; }
r[14]=read(ram,0x0c0a7fb0u,4);
goto P_0c0a7f7a;
P_0c0a7f7a: /* original a056, guest PC 0x0c0a7f7a */
if(!s->budget--) { s->failed_pc=0x0c0a7f7au; return 0; }
goto P_0c0a802a;
P_0c0a7f7c: /* original 0009, guest PC 0x0c0a7f7c */
if(!s->budget--) { s->failed_pc=0x0c0a7f7cu; return 0; }
goto P_0c0a7f7e;
P_0c0a7f7e: /* original d00d, guest PC 0x0c0a7f7e */
if(!s->budget--) { s->failed_pc=0x0c0a7f7eu; return 0; }
r[0]=read(ram,0x0c0a7fb4u,4);
goto P_0c0a7f80;
P_0c0a7f80: /* original 63b3, guest PC 0x0c0a7f80 */
if(!s->budget--) { s->failed_pc=0x0c0a7f80u; return 0; }
r[3]=r[11];
goto P_0c0a7f82;
P_0c0a7f82: /* original 4308, guest PC 0x0c0a7f82 */
if(!s->budget--) { s->failed_pc=0x0c0a7f82u; return 0; }
r[3]<<=2;
goto P_0c0a7f84;
P_0c0a7f84: /* original 023e, guest PC 0x0c0a7f84 */
if(!s->budget--) { s->failed_pc=0x0c0a7f84u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0a7f86;
P_0c0a7f86: /* original 1f21, guest PC 0x0c0a7f86 */
if(!s->budget--) { s->failed_pc=0x0c0a7f86u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a7f88;
P_0c0a7f88: /* original d30b, guest PC 0x0c0a7f88 */
if(!s->budget--) { s->failed_pc=0x0c0a7f88u; return 0; }
r[3]=read(ram,0x0c0a7fb8u,4);
goto P_0c0a7f8a;
P_0c0a7f8a: /* original e500, guest PC 0x0c0a7f8a */
if(!s->budget--) { s->failed_pc=0x0c0a7f8au; return 0; }
r[5]=0x00000000u;
goto P_0c0a7f8c;
P_0c0a7f8c: /* original 430b, guest PC 0x0c0a7f8c */
if(!s->budget--) { s->failed_pc=0x0c0a7f8cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7f90u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7f90u) { target=s->pc; goto dispatch; }
goto P_0c0a7f90;
P_0c0a7f8e: /* original 54f1, guest PC 0x0c0a7f8e */
if(!s->budget--) { s->failed_pc=0x0c0a7f8eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0a7f90;
P_0c0a7f90: /* original dc0a, guest PC 0x0c0a7f90 */
if(!s->budget--) { s->failed_pc=0x0c0a7f90u; return 0; }
r[12]=read(ram,0x0c0a7fbcu,4);
goto P_0c0a7f92;
P_0c0a7f92: /* original 6d03, guest PC 0x0c0a7f92 */
if(!s->budget--) { s->failed_pc=0x0c0a7f92u; return 0; }
r[13]=r[0];
goto P_0c0a7f94;
P_0c0a7f94: /* original 2dd8, guest PC 0x0c0a7f94 */
if(!s->budget--) { s->failed_pc=0x0c0a7f94u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0a7f96;
P_0c0a7f96: /* original 8b13, guest PC 0x0c0a7f96 */
if(!s->budget--) { s->failed_pc=0x0c0a7f96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7fc0; }
goto P_0c0a7f98;
P_0c0a7f98: /* original 64b3, guest PC 0x0c0a7f98 */
if(!s->budget--) { s->failed_pc=0x0c0a7f98u; return 0; }
r[4]=r[11];
goto P_0c0a7f9a;
P_0c0a7f9a: /* original d306, guest PC 0x0c0a7f9a */
if(!s->budget--) { s->failed_pc=0x0c0a7f9au; return 0; }
r[3]=read(ram,0x0c0a7fb4u,4);
goto P_0c0a7f9c;
P_0c0a7f9c: /* original eeff, guest PC 0x0c0a7f9c */
if(!s->budget--) { s->failed_pc=0x0c0a7f9cu; return 0; }
r[14]=0xffffffffu;
goto P_0c0a7f9e;
P_0c0a7f9e: /* original 4408, guest PC 0x0c0a7f9e */
if(!s->budget--) { s->failed_pc=0x0c0a7f9eu; return 0; }
r[4]<<=2;
goto P_0c0a7fa0;
P_0c0a7fa0: /* original e570, guest PC 0x0c0a7fa0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa0u; return 0; }
r[5]=0x00000070u;
goto P_0c0a7fa2;
P_0c0a7fa2: /* original a016, guest PC 0x0c0a7fa2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa2u; return 0; }
r[4]+=r[3];
goto P_0c0a7fd2;
P_0c0a7fa4: /* original 343c, guest PC 0x0c0a7fa4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa4u; return 0; }
r[4]+=r[3];
if(!vf3_matrix_family(0x0c0a7fa6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7fa6u; return 0; } return 1;
P_0c0a7fc0: /* original d234, guest PC 0x0c0a7fc0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc0u; return 0; }
r[2]=read(ram,0x0c0a8094u,4);
goto P_0c0a7fc2;
P_0c0a7fc2: /* original 65f3, guest PC 0x0c0a7fc2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc2u; return 0; }
r[5]=r[15];
goto P_0c0a7fc4;
P_0c0a7fc4: /* original 420b, guest PC 0x0c0a7fc4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7fc8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7fc8u) { target=s->pc; goto dispatch; }
goto P_0c0a7fc8;
P_0c0a7fc6: /* original 64d3, guest PC 0x0c0a7fc6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc6u; return 0; }
r[4]=r[13];
goto P_0c0a7fc8;
P_0c0a7fc8: /* original 63f2, guest PC 0x0c0a7fc8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a7fca;
P_0c0a7fca: /* original 2338, guest PC 0x0c0a7fca */
if(!s->budget--) { s->failed_pc=0x0c0a7fcau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a7fcc;
P_0c0a7fcc: /* original 8b05, guest PC 0x0c0a7fcc */
if(!s->budget--) { s->failed_pc=0x0c0a7fccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7fda; }
goto P_0c0a7fce;
P_0c0a7fce: /* original e400, guest PC 0x0c0a7fce */
if(!s->budget--) { s->failed_pc=0x0c0a7fceu; return 0; }
r[4]=0x00000000u;
goto P_0c0a7fd0;
P_0c0a7fd0: /* original e571, guest PC 0x0c0a7fd0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd0u; return 0; }
r[5]=0x00000071u;
goto P_0c0a7fd2;
P_0c0a7fd2: /* original 4c0b, guest PC 0x0c0a7fd2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd2u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a7fd6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7fd6u) { target=s->pc; goto dispatch; }
goto P_0c0a7fd6;
P_0c0a7fd4: /* original 0009, guest PC 0x0c0a7fd4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd4u; return 0; }
goto P_0c0a7fd6;
P_0c0a7fd6: /* original a028, guest PC 0x0c0a7fd6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd6u; return 0; }
goto P_0c0a802a;
P_0c0a7fd8: /* original 0009, guest PC 0x0c0a7fd8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd8u; return 0; }
goto P_0c0a7fda;
P_0c0a7fda: /* original 62f2, guest PC 0x0c0a7fda */
if(!s->budget--) { s->failed_pc=0x0c0a7fdau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a7fdc;
P_0c0a7fdc: /* original 9356, guest PC 0x0c0a7fdc */
if(!s->budget--) { s->failed_pc=0x0c0a7fdcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a808cu,2);
goto P_0c0a7fde;
P_0c0a7fde: /* original 9156, guest PC 0x0c0a7fde */
if(!s->budget--) { s->failed_pc=0x0c0a7fdeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a808eu,2);
goto P_0c0a7fe0;
P_0c0a7fe0: /* original 323c, guest PC 0x0c0a7fe0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe0u; return 0; }
r[2]+=r[3];
goto P_0c0a7fe2;
P_0c0a7fe2: /* original 2219, guest PC 0x0c0a7fe2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe2u; return 0; }
r[2]&=r[1];
goto P_0c0a7fe4;
P_0c0a7fe4: /* original 6523, guest PC 0x0c0a7fe4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe4u; return 0; }
r[5]=r[2];
goto P_0c0a7fe6;
P_0c0a7fe6: /* original 4519, guest PC 0x0c0a7fe6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe6u; return 0; }
r[5]>>=8;
goto P_0c0a7fe8;
P_0c0a7fe8: /* original 4509, guest PC 0x0c0a7fe8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe8u; return 0; }
r[5]>>=2;
goto P_0c0a7fea;
P_0c0a7fea: /* original 2f22, guest PC 0x0c0a7fea */
if(!s->budget--) { s->failed_pc=0x0c0a7feau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a7fec;
P_0c0a7fec: /* original 56f2, guest PC 0x0c0a7fec */
if(!s->budget--) { s->failed_pc=0x0c0a7fecu; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c0a7fee;
P_0c0a7fee: /* original 4501, guest PC 0x0c0a7fee */
if(!s->budget--) { s->failed_pc=0x0c0a7feeu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c0a7ff0;
P_0c0a7ff0: /* original d329, guest PC 0x0c0a7ff0 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff0u; return 0; }
r[3]=read(ram,0x0c0a8098u,4);
goto P_0c0a7ff2;
P_0c0a7ff2: /* original 430b, guest PC 0x0c0a7ff2 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7ff6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7ff6u) { target=s->pc; goto dispatch; }
goto P_0c0a7ff6;
P_0c0a7ff4: /* original 64d3, guest PC 0x0c0a7ff4 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff4u; return 0; }
r[4]=r[13];
goto P_0c0a7ff6;
P_0c0a7ff6: /* original 6403, guest PC 0x0c0a7ff6 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff6u; return 0; }
r[4]=r[0];
goto P_0c0a7ff8;
P_0c0a7ff8: /* original 4415, guest PC 0x0c0a7ff8 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0a7ffa;
P_0c0a7ffa: /* original 8901, guest PC 0x0c0a7ffa */
if(!s->budget--) { s->failed_pc=0x0c0a7ffau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8000; }
goto P_0c0a7ffc;
P_0c0a7ffc: /* original 4c0b, guest PC 0x0c0a7ffc */
if(!s->budget--) { s->failed_pc=0x0c0a7ffcu; return 0; }
target=r[12];
r[16]=code_base|0x0c0a8000u;
r[5]=0x00000072u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8000u) { target=s->pc; goto dispatch; }
goto P_0c0a8000;
P_0c0a7ffe: /* original e572, guest PC 0x0c0a7ffe */
if(!s->budget--) { s->failed_pc=0x0c0a7ffeu; return 0; }
r[5]=0x00000072u;
goto P_0c0a8000;
P_0c0a8000: /* original d326, guest PC 0x0c0a8000 */
if(!s->budget--) { s->failed_pc=0x0c0a8000u; return 0; }
r[3]=read(ram,0x0c0a809cu,4);
goto P_0c0a8002;
P_0c0a8002: /* original 430b, guest PC 0x0c0a8002 */
if(!s->budget--) { s->failed_pc=0x0c0a8002u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8006u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8006u) { target=s->pc; goto dispatch; }
goto P_0c0a8006;
P_0c0a8004: /* original 64d3, guest PC 0x0c0a8004 */
if(!s->budget--) { s->failed_pc=0x0c0a8004u; return 0; }
r[4]=r[13];
goto P_0c0a8006;
P_0c0a8006: /* original 6e03, guest PC 0x0c0a8006 */
if(!s->budget--) { s->failed_pc=0x0c0a8006u; return 0; }
r[14]=r[0];
goto P_0c0a8008;
P_0c0a8008: /* original 2ee8, guest PC 0x0c0a8008 */
if(!s->budget--) { s->failed_pc=0x0c0a8008u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a800a;
P_0c0a800a: /* original 890b, guest PC 0x0c0a800a */
if(!s->budget--) { s->failed_pc=0x0c0a800au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8024; }
goto P_0c0a800c;
P_0c0a800c: /* original e30a, guest PC 0x0c0a800c */
if(!s->budget--) { s->failed_pc=0x0c0a800cu; return 0; }
r[3]=0x0000000au;
goto P_0c0a800e;
P_0c0a800e: /* original 3a33, guest PC 0x0c0a800e */
if(!s->budget--) { s->failed_pc=0x0c0a800eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c0a8010;
P_0c0a8010: /* original 8905, guest PC 0x0c0a8010 */
if(!s->budget--) { s->failed_pc=0x0c0a8010u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a801e; }
goto P_0c0a8012;
P_0c0a8012: /* original d123, guest PC 0x0c0a8012 */
if(!s->budget--) { s->failed_pc=0x0c0a8012u; return 0; }
r[1]=read(ram,0x0c0a80a0u,4);
goto P_0c0a8014;
P_0c0a8014: /* original 7a01, guest PC 0x0c0a8014 */
if(!s->budget--) { s->failed_pc=0x0c0a8014u; return 0; }
r[10]+=0x00000001u;
goto P_0c0a8016;
P_0c0a8016: /* original 410b, guest PC 0x0c0a8016 */
if(!s->budget--) { s->failed_pc=0x0c0a8016u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a801au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a801au) { target=s->pc; goto dispatch; }
goto P_0c0a801a;
P_0c0a8018: /* original 64d3, guest PC 0x0c0a8018 */
if(!s->budget--) { s->failed_pc=0x0c0a8018u; return 0; }
r[4]=r[13];
goto P_0c0a801a;
P_0c0a801a: /* original afb5, guest PC 0x0c0a801a */
if(!s->budget--) { s->failed_pc=0x0c0a801au; return 0; }
goto P_0c0a7f88;
P_0c0a801c: /* original 0009, guest PC 0x0c0a801c */
if(!s->budget--) { s->failed_pc=0x0c0a801cu; return 0; }
goto P_0c0a801e;
P_0c0a801e: /* original e573, guest PC 0x0c0a801e */
if(!s->budget--) { s->failed_pc=0x0c0a801eu; return 0; }
r[5]=0x00000073u;
goto P_0c0a8020;
P_0c0a8020: /* original 4c0b, guest PC 0x0c0a8020 */
if(!s->budget--) { s->failed_pc=0x0c0a8020u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a8024u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8024u) { target=s->pc; goto dispatch; }
goto P_0c0a8024;
P_0c0a8022: /* original 64e3, guest PC 0x0c0a8022 */
if(!s->budget--) { s->failed_pc=0x0c0a8022u; return 0; }
r[4]=r[14];
goto P_0c0a8024;
P_0c0a8024: /* original d21e, guest PC 0x0c0a8024 */
if(!s->budget--) { s->failed_pc=0x0c0a8024u; return 0; }
r[2]=read(ram,0x0c0a80a0u,4);
goto P_0c0a8026;
P_0c0a8026: /* original 420b, guest PC 0x0c0a8026 */
if(!s->budget--) { s->failed_pc=0x0c0a8026u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a802au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a802au) { target=s->pc; goto dispatch; }
goto P_0c0a802a;
P_0c0a8028: /* original 64d3, guest PC 0x0c0a8028 */
if(!s->budget--) { s->failed_pc=0x0c0a8028u; return 0; }
r[4]=r[13];
goto P_0c0a802a;
P_0c0a802a: /* original 7f0c, guest PC 0x0c0a802a */
if(!s->budget--) { s->failed_pc=0x0c0a802au; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a802c;
P_0c0a802c: /* original 60e3, guest PC 0x0c0a802c */
if(!s->budget--) { s->failed_pc=0x0c0a802cu; return 0; }
r[0]=r[14];
goto P_0c0a802e;
P_0c0a802e: /* original 4f26, guest PC 0x0c0a802e */
if(!s->budget--) { s->failed_pc=0x0c0a802eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8030;
P_0c0a8030: /* original 6af6, guest PC 0x0c0a8030 */
if(!s->budget--) { s->failed_pc=0x0c0a8030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8032;
P_0c0a8032: /* original 6bf6, guest PC 0x0c0a8032 */
if(!s->budget--) { s->failed_pc=0x0c0a8032u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8034;
P_0c0a8034: /* original 6cf6, guest PC 0x0c0a8034 */
if(!s->budget--) { s->failed_pc=0x0c0a8034u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8036;
P_0c0a8036: /* original 6df6, guest PC 0x0c0a8036 */
if(!s->budget--) { s->failed_pc=0x0c0a8036u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8038;
P_0c0a8038: /* original 000b, guest PC 0x0c0a8038 */
if(!s->budget--) { s->failed_pc=0x0c0a8038u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a803a: /* original 6ef6, guest PC 0x0c0a803a */
if(!s->budget--) { s->failed_pc=0x0c0a803au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a803cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a803cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
