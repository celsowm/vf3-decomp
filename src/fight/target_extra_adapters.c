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
int vf3_target_extra_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04fe46u: goto P_0c04fe46;
case 0x0c04fe48u: goto P_0c04fe48;
case 0x0c04fe4au: goto P_0c04fe4a;
case 0x0c04fe4cu: goto P_0c04fe4c;
case 0x0c04fe4eu: goto P_0c04fe4e;
case 0x0c04fe50u: goto P_0c04fe50;
case 0x0c04fe52u: goto P_0c04fe52;
case 0x0c04fe54u: goto P_0c04fe54;
case 0x0c04fe56u: goto P_0c04fe56;
case 0x0c04fe58u: goto P_0c04fe58;
case 0x0c04fe5au: goto P_0c04fe5a;
case 0x0c04fe5cu: goto P_0c04fe5c;
case 0x0c04fe5eu: goto P_0c04fe5e;
case 0x0c04fe60u: goto P_0c04fe60;
case 0x0c04fe62u: goto P_0c04fe62;
case 0x0c04fe64u: goto P_0c04fe64;
case 0x0c04fe66u: goto P_0c04fe66;
case 0x0c04fe68u: goto P_0c04fe68;
case 0x0c04fe6au: goto P_0c04fe6a;
case 0x0c04fe6cu: goto P_0c04fe6c;
case 0x0c04fe6eu: goto P_0c04fe6e;
case 0x0c04fe70u: goto P_0c04fe70;
case 0x0c04fe72u: goto P_0c04fe72;
case 0x0c04fe74u: goto P_0c04fe74;
case 0x0c04fe76u: goto P_0c04fe76;
case 0x0c04fe78u: goto P_0c04fe78;
case 0x0c04fe7au: goto P_0c04fe7a;
case 0x0c04fe7cu: goto P_0c04fe7c;
case 0x0c04fe7eu: goto P_0c04fe7e;
case 0x0c04fe80u: goto P_0c04fe80;
case 0x0c04fe82u: goto P_0c04fe82;
case 0x0c04fe84u: goto P_0c04fe84;
case 0x0c04fe86u: goto P_0c04fe86;
case 0x0c04fe88u: goto P_0c04fe88;
case 0x0c04fe8au: goto P_0c04fe8a;
case 0x0c04fe8cu: goto P_0c04fe8c;
case 0x0c04fe8eu: goto P_0c04fe8e;
case 0x0c04fe90u: goto P_0c04fe90;
case 0x0c04fe92u: goto P_0c04fe92;
case 0x0c04fe94u: goto P_0c04fe94;
case 0x0c04fe96u: goto P_0c04fe96;
case 0x0c04fe98u: goto P_0c04fe98;
case 0x0c04fe9au: goto P_0c04fe9a;
case 0x0c04fe9cu: goto P_0c04fe9c;
case 0x0c05ae5au: goto P_0c05ae5a;
case 0x0c05ae5cu: goto P_0c05ae5c;
case 0x0c05ae5eu: goto P_0c05ae5e;
case 0x0c05ae60u: goto P_0c05ae60;
case 0x0c05ae62u: goto P_0c05ae62;
case 0x0c05ae64u: goto P_0c05ae64;
case 0x0c05ae66u: goto P_0c05ae66;
case 0x0c05ae68u: goto P_0c05ae68;
case 0x0c05ae6au: goto P_0c05ae6a;
case 0x0c05ae6cu: goto P_0c05ae6c;
case 0x0c05ae6eu: goto P_0c05ae6e;
case 0x0c05ae70u: goto P_0c05ae70;
case 0x0c05ae72u: goto P_0c05ae72;
case 0x0c05ae74u: goto P_0c05ae74;
case 0x0c05ae76u: goto P_0c05ae76;
case 0x0c05ae78u: goto P_0c05ae78;
case 0x0c05ae7au: goto P_0c05ae7a;
case 0x0c05ae7cu: goto P_0c05ae7c;
case 0x0c05ae7eu: goto P_0c05ae7e;
case 0x0c05ae80u: goto P_0c05ae80;
case 0x0c05ae82u: goto P_0c05ae82;
case 0x0c05ae84u: goto P_0c05ae84;
case 0x0c05ae86u: goto P_0c05ae86;
case 0x0c05ae88u: goto P_0c05ae88;
case 0x0c05ae8au: goto P_0c05ae8a;
case 0x0c05ae8cu: goto P_0c05ae8c;
case 0x0c05ae8eu: goto P_0c05ae8e;
case 0x0c05ae90u: goto P_0c05ae90;
case 0x0c05ae92u: goto P_0c05ae92;
case 0x0c05ae94u: goto P_0c05ae94;
case 0x0c05ae96u: goto P_0c05ae96;
case 0x0c05ae98u: goto P_0c05ae98;
case 0x0c05ae9au: goto P_0c05ae9a;
case 0x0c05ae9cu: goto P_0c05ae9c;
case 0x0c05ae9eu: goto P_0c05ae9e;
case 0x0c05aea0u: goto P_0c05aea0;
case 0x0c05aea2u: goto P_0c05aea2;
case 0x0c05aea4u: goto P_0c05aea4;
case 0x0c05aea6u: goto P_0c05aea6;
case 0x0c05aea8u: goto P_0c05aea8;
case 0x0c05aeaau: goto P_0c05aeaa;
case 0x0c05aeacu: goto P_0c05aeac;
case 0x0c05aeaeu: goto P_0c05aeae;
case 0x0c05aeb0u: goto P_0c05aeb0;
case 0x0c05aeb2u: goto P_0c05aeb2;
case 0x0c05aeb4u: goto P_0c05aeb4;
case 0x0c05aeb6u: goto P_0c05aeb6;
case 0x0c05aeb8u: goto P_0c05aeb8;
case 0x0c05aebau: goto P_0c05aeba;
case 0x0c05aebcu: goto P_0c05aebc;
case 0x0c05aebeu: goto P_0c05aebe;
case 0x0c05aec0u: goto P_0c05aec0;
case 0x0c05aec2u: goto P_0c05aec2;
case 0x0c05aec4u: goto P_0c05aec4;
case 0x0c05aec6u: goto P_0c05aec6;
case 0x0c05aec8u: goto P_0c05aec8;
case 0x0c05aecau: goto P_0c05aeca;
case 0x0c05aeccu: goto P_0c05aecc;
case 0x0c05aeceu: goto P_0c05aece;
case 0x0c05aed0u: goto P_0c05aed0;
case 0x0c05aed2u: goto P_0c05aed2;
case 0x0c05aed4u: goto P_0c05aed4;
case 0x0c05aed6u: goto P_0c05aed6;
case 0x0c05aed8u: goto P_0c05aed8;
case 0x0c05aedau: goto P_0c05aeda;
case 0x0c05aedcu: goto P_0c05aedc;
case 0x0c05aedeu: goto P_0c05aede;
case 0x0c05aee0u: goto P_0c05aee0;
case 0x0c05aee2u: goto P_0c05aee2;
case 0x0c05aee4u: goto P_0c05aee4;
case 0x0c05aee6u: goto P_0c05aee6;
case 0x0c05aee8u: goto P_0c05aee8;
case 0x0c05aeeau: goto P_0c05aeea;
case 0x0c05aeecu: goto P_0c05aeec;
case 0x0c05aeeeu: goto P_0c05aeee;
case 0x0c05aef0u: goto P_0c05aef0;
case 0x0c05aef2u: goto P_0c05aef2;
case 0x0c05aef4u: goto P_0c05aef4;
case 0x0c05aef6u: goto P_0c05aef6;
case 0x0c05aef8u: goto P_0c05aef8;
case 0x0c05aefau: goto P_0c05aefa;
case 0x0c05aefcu: goto P_0c05aefc;
case 0x0c05aefeu: goto P_0c05aefe;
case 0x0c05af00u: goto P_0c05af00;
case 0x0c05af02u: goto P_0c05af02;
case 0x0c05af04u: goto P_0c05af04;
case 0x0c05af06u: goto P_0c05af06;
case 0x0c05af08u: goto P_0c05af08;
case 0x0c05af0au: goto P_0c05af0a;
case 0x0c05af0cu: goto P_0c05af0c;
case 0x0c05af0eu: goto P_0c05af0e;
case 0x0c05af10u: goto P_0c05af10;
case 0x0c05af12u: goto P_0c05af12;
case 0x0c05af14u: goto P_0c05af14;
case 0x0c05af16u: goto P_0c05af16;
case 0x0c05af18u: goto P_0c05af18;
case 0x0c05af1au: goto P_0c05af1a;
case 0x0c05af1cu: goto P_0c05af1c;
case 0x0c05af1eu: goto P_0c05af1e;
case 0x0c05af20u: goto P_0c05af20;
case 0x0c05af22u: goto P_0c05af22;
case 0x0c05af24u: goto P_0c05af24;
case 0x0c05af26u: goto P_0c05af26;
case 0x0c05af28u: goto P_0c05af28;
case 0x0c07f08eu: goto P_0c07f08e;
case 0x0c07f090u: goto P_0c07f090;
case 0x0c07f092u: goto P_0c07f092;
case 0x0c07f094u: goto P_0c07f094;
case 0x0c07f096u: goto P_0c07f096;
case 0x0c07f098u: goto P_0c07f098;
case 0x0c07f09au: goto P_0c07f09a;
case 0x0c07f09cu: goto P_0c07f09c;
case 0x0c07f09eu: goto P_0c07f09e;
case 0x0c07f0a0u: goto P_0c07f0a0;
case 0x0c07f0a2u: goto P_0c07f0a2;
case 0x0c07f0a4u: goto P_0c07f0a4;
case 0x0c07f0a6u: goto P_0c07f0a6;
case 0x0c07f0a8u: goto P_0c07f0a8;
case 0x0c07f0aau: goto P_0c07f0aa;
case 0x0c07f0acu: goto P_0c07f0ac;
case 0x0c07f0aeu: goto P_0c07f0ae;
case 0x0c07f0b0u: goto P_0c07f0b0;
case 0x0c07f0b2u: goto P_0c07f0b2;
case 0x0c07f100u: goto P_0c07f100;
case 0x0c07f102u: goto P_0c07f102;
case 0x0c07f104u: goto P_0c07f104;
case 0x0c07f106u: goto P_0c07f106;
case 0x0c07f108u: goto P_0c07f108;
case 0x0c07f10au: goto P_0c07f10a;
case 0x0c07f10cu: goto P_0c07f10c;
case 0x0c07f10eu: goto P_0c07f10e;
case 0x0c07f110u: goto P_0c07f110;
case 0x0c07f112u: goto P_0c07f112;
case 0x0c07f114u: goto P_0c07f114;
case 0x0c07f116u: goto P_0c07f116;
case 0x0c07f118u: goto P_0c07f118;
case 0x0c07f11au: goto P_0c07f11a;
case 0x0c07f11cu: goto P_0c07f11c;
case 0x0c07f11eu: goto P_0c07f11e;
case 0x0c07f120u: goto P_0c07f120;
case 0x0c07f122u: goto P_0c07f122;
case 0x0c07f124u: goto P_0c07f124;
case 0x0c080796u: goto P_0c080796;
case 0x0c080798u: goto P_0c080798;
case 0x0c08079au: goto P_0c08079a;
case 0x0c08079cu: goto P_0c08079c;
case 0x0c08079eu: goto P_0c08079e;
case 0x0c0807a0u: goto P_0c0807a0;
case 0x0c0807a2u: goto P_0c0807a2;
case 0x0c0807a4u: goto P_0c0807a4;
case 0x0c0807a6u: goto P_0c0807a6;
case 0x0c0807a8u: goto P_0c0807a8;
case 0x0c0807aau: goto P_0c0807aa;
case 0x0c0807acu: goto P_0c0807ac;
case 0x0c0807aeu: goto P_0c0807ae;
case 0x0c0807b0u: goto P_0c0807b0;
case 0x0c0807b2u: goto P_0c0807b2;
case 0x0c0807b4u: goto P_0c0807b4;
case 0x0c0807b6u: goto P_0c0807b6;
case 0x0c0807b8u: goto P_0c0807b8;
case 0x0c0807bau: goto P_0c0807ba;
case 0x0c0807bcu: goto P_0c0807bc;
case 0x0c0807beu: goto P_0c0807be;
case 0x0c0807c0u: goto P_0c0807c0;
case 0x0c0807c2u: goto P_0c0807c2;
case 0x0c0807c4u: goto P_0c0807c4;
case 0x0c0807c6u: goto P_0c0807c6;
case 0x0c0807c8u: goto P_0c0807c8;
case 0x0c0807cau: goto P_0c0807ca;
case 0x0c0807ccu: goto P_0c0807cc;
case 0x0c0a1fd2u: goto P_0c0a1fd2;
case 0x0c0a1fd4u: goto P_0c0a1fd4;
case 0x0c0a1fd6u: goto P_0c0a1fd6;
case 0x0c0a1fd8u: goto P_0c0a1fd8;
case 0x0c0a1fdau: goto P_0c0a1fda;
case 0x0c0a1fdcu: goto P_0c0a1fdc;
case 0x0c0a1fdeu: goto P_0c0a1fde;
case 0x0c0a1fe0u: goto P_0c0a1fe0;
case 0x0c0a1fe2u: goto P_0c0a1fe2;
case 0x0c0a1fe4u: goto P_0c0a1fe4;
case 0x0c0a1fe6u: goto P_0c0a1fe6;
case 0x0c0a1fe8u: goto P_0c0a1fe8;
case 0x0c0a1feau: goto P_0c0a1fea;
case 0x0c0a1fecu: goto P_0c0a1fec;
case 0x0c0a1feeu: goto P_0c0a1fee;
case 0x0c0a1ff0u: goto P_0c0a1ff0;
case 0x0c0a1ff2u: goto P_0c0a1ff2;
case 0x0c0a1ff4u: goto P_0c0a1ff4;
case 0x0c0a65d4u: goto P_0c0a65d4;
case 0x0c0a65d6u: goto P_0c0a65d6;
case 0x0c0a65d8u: goto P_0c0a65d8;
case 0x0c0a65dau: goto P_0c0a65da;
case 0x0c0a65dcu: goto P_0c0a65dc;
case 0x0c0a65deu: goto P_0c0a65de;
case 0x0c0a65e0u: goto P_0c0a65e0;
case 0x0c0a65e2u: goto P_0c0a65e2;
case 0x0c0a65e4u: goto P_0c0a65e4;
case 0x0c0a65e6u: goto P_0c0a65e6;
case 0x0c0a65e8u: goto P_0c0a65e8;
case 0x0c0a65eau: goto P_0c0a65ea;
case 0x0c0a65ecu: goto P_0c0a65ec;
case 0x0c0a65eeu: goto P_0c0a65ee;
case 0x0c0a65f0u: goto P_0c0a65f0;
case 0x0c0a65f2u: goto P_0c0a65f2;
case 0x0c0a65f4u: goto P_0c0a65f4;
case 0x0c0a65f6u: goto P_0c0a65f6;
case 0x0c0a65f8u: goto P_0c0a65f8;
case 0x0c0a65fau: goto P_0c0a65fa;
case 0x0c0a65fcu: goto P_0c0a65fc;
case 0x0c0a65feu: goto P_0c0a65fe;
case 0x0c0a6600u: goto P_0c0a6600;
case 0x0c0a6602u: goto P_0c0a6602;
case 0x0c0a6604u: goto P_0c0a6604;
case 0x0c0a6606u: goto P_0c0a6606;
case 0x0c0a6608u: goto P_0c0a6608;
case 0x0c0a660au: goto P_0c0a660a;
case 0x0c0a660cu: goto P_0c0a660c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04fe46: /* original 4f22, guest PC 0x0c04fe46 */
if(!s->budget--) { s->failed_pc=0x0c04fe46u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04fe48;
P_0c04fe48: /* original 4f12, guest PC 0x0c04fe48 */
if(!s->budget--) { s->failed_pc=0x0c04fe48u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fe4a;
P_0c04fe4a: /* original 7ffc, guest PC 0x0c04fe4a */
if(!s->budget--) { s->failed_pc=0x0c04fe4au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04fe4c;
P_0c04fe4c: /* original 2f61, guest PC 0x0c04fe4c */
if(!s->budget--) { s->failed_pc=0x0c04fe4cu; return 0; }
write(ram,r[15],r[6],2);
goto P_0c04fe4e;
P_0c04fe4e: /* original 9e39, guest PC 0x0c04fe4e */
if(!s->budget--) { s->failed_pc=0x0c04fe4eu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fec4u,2);
goto P_0c04fe50;
P_0c04fe50: /* original d31d, guest PC 0x0c04fe50 */
if(!s->budget--) { s->failed_pc=0x0c04fe50u; return 0; }
r[3]=read(ram,0x0c04fec8u,4);
goto P_0c04fe52;
P_0c04fe52: /* original 24ef, guest PC 0x0c04fe52 */
if(!s->budget--) { s->failed_pc=0x0c04fe52u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[14]);
goto P_0c04fe54;
P_0c04fe54: /* original 0e1a, guest PC 0x0c04fe54 */
if(!s->budget--) { s->failed_pc=0x0c04fe54u; return 0; }
r[14]=r[19];
goto P_0c04fe56;
P_0c04fe56: /* original 6eef, guest PC 0x0c04fe56 */
if(!s->budget--) { s->failed_pc=0x0c04fe56u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04fe58;
P_0c04fe58: /* original 3e3c, guest PC 0x0c04fe58 */
if(!s->budget--) { s->failed_pc=0x0c04fe58u; return 0; }
r[14]+=r[3];
goto P_0c04fe5a;
P_0c04fe5a: /* original 52e7, guest PC 0x0c04fe5a */
if(!s->budget--) { s->failed_pc=0x0c04fe5au; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04fe5c;
P_0c04fe5c: /* original 6122, guest PC 0x0c04fe5c */
if(!s->budget--) { s->failed_pc=0x0c04fe5cu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c04fe5e;
P_0c04fe5e: /* original 3d17, guest PC 0x0c04fe5e */
if(!s->budget--) { s->failed_pc=0x0c04fe5eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>(int32_t)r[1])!=0);
goto P_0c04fe60;
P_0c04fe60: /* original 8b0a, guest PC 0x0c04fe60 */
if(!s->budget--) { s->failed_pc=0x0c04fe60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fe78; }
goto P_0c04fe62;
P_0c04fe62: /* original 60f1, guest PC 0x0c04fe62 */
if(!s->budget--) { s->failed_pc=0x0c04fe62u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[0]=tmp;
goto P_0c04fe64;
P_0c04fe64: /* original 600d, guest PC 0x0c04fe64 */
if(!s->budget--) { s->failed_pc=0x0c04fe64u; return 0; }
r[0]=r[0]&65535u;
goto P_0c04fe66;
P_0c04fe66: /* original 2f06, guest PC 0x0c04fe66 */
if(!s->budget--) { s->failed_pc=0x0c04fe66u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe68;
P_0c04fe68: /* original 2fd6, guest PC 0x0c04fe68 */
if(!s->budget--) { s->failed_pc=0x0c04fe68u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe6a;
P_0c04fe6a: /* original 2f46, guest PC 0x0c04fe6a */
if(!s->budget--) { s->failed_pc=0x0c04fe6au; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe6c;
P_0c04fe6c: /* original d218, guest PC 0x0c04fe6c */
if(!s->budget--) { s->failed_pc=0x0c04fe6cu; return 0; }
r[2]=read(ram,0x0c04fed0u,4);
goto P_0c04fe6e;
P_0c04fe6e: /* original d119, guest PC 0x0c04fe6e */
if(!s->budget--) { s->failed_pc=0x0c04fe6eu; return 0; }
r[1]=read(ram,0x0c04fed4u,4);
goto P_0c04fe70;
P_0c04fe70: /* original 410b, guest PC 0x0c04fe70 */
if(!s->budget--) { s->failed_pc=0x0c04fe70u; return 0; }
target=r[1];
r[16]=0x0c04fe74u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fe74u) { target=s->pc; goto dispatch; }
goto P_0c04fe74;
P_0c04fe72: /* original 2f26, guest PC 0x0c04fe72 */
if(!s->budget--) { s->failed_pc=0x0c04fe72u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe74;
P_0c04fe74: /* original a00d, guest PC 0x0c04fe74 */
if(!s->budget--) { s->failed_pc=0x0c04fe74u; return 0; }
r[15]+=0x00000010u;
goto P_0c04fe92;
P_0c04fe76: /* original 7f10, guest PC 0x0c04fe76 */
if(!s->budget--) { s->failed_pc=0x0c04fe76u; return 0; }
r[15]+=0x00000010u;
goto P_0c04fe78;
P_0c04fe78: /* original 66f1, guest PC 0x0c04fe78 */
if(!s->budget--) { s->failed_pc=0x0c04fe78u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[6]=tmp;
goto P_0c04fe7a;
P_0c04fe7a: /* original 7f04, guest PC 0x0c04fe7a */
if(!s->budget--) { s->failed_pc=0x0c04fe7au; return 0; }
r[15]+=0x00000004u;
goto P_0c04fe7c;
P_0c04fe7c: /* original 4f16, guest PC 0x0c04fe7c */
if(!s->budget--) { s->failed_pc=0x0c04fe7cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fe7e;
P_0c04fe7e: /* original d113, guest PC 0x0c04fe7e */
if(!s->budget--) { s->failed_pc=0x0c04fe7eu; return 0; }
r[1]=read(ram,0x0c04feccu,4);
goto P_0c04fe80;
P_0c04fe80: /* original 65d3, guest PC 0x0c04fe80 */
if(!s->budget--) { s->failed_pc=0x0c04fe80u; return 0; }
r[5]=r[13];
goto P_0c04fe82;
P_0c04fe82: /* original 54e9, guest PC 0x0c04fe82 */
if(!s->budget--) { s->failed_pc=0x0c04fe82u; return 0; }
r[4]=read(ram,r[14]+36,4);
goto P_0c04fe84;
P_0c04fe84: /* original 4500, guest PC 0x0c04fe84 */
if(!s->budget--) { s->failed_pc=0x0c04fe84u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c04fe86;
P_0c04fe86: /* original 4f26, guest PC 0x0c04fe86 */
if(!s->budget--) { s->failed_pc=0x0c04fe86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fe88;
P_0c04fe88: /* original 6312, guest PC 0x0c04fe88 */
if(!s->budget--) { s->failed_pc=0x0c04fe88u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c04fe8a;
P_0c04fe8a: /* original 5234, guest PC 0x0c04fe8a */
if(!s->budget--) { s->failed_pc=0x0c04fe8au; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c04fe8c;
P_0c04fe8c: /* original 6df6, guest PC 0x0c04fe8c */
if(!s->budget--) { s->failed_pc=0x0c04fe8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fe8e;
P_0c04fe8e: /* original 422b, guest PC 0x0c04fe8e */
if(!s->budget--) { s->failed_pc=0x0c04fe8eu; return 0; }
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
P_0c04fe90: /* original 6ef6, guest PC 0x0c04fe90 */
if(!s->budget--) { s->failed_pc=0x0c04fe90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04fe92;
P_0c04fe92: /* original 7f04, guest PC 0x0c04fe92 */
if(!s->budget--) { s->failed_pc=0x0c04fe92u; return 0; }
r[15]+=0x00000004u;
goto P_0c04fe94;
P_0c04fe94: /* original 4f16, guest PC 0x0c04fe94 */
if(!s->budget--) { s->failed_pc=0x0c04fe94u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fe96;
P_0c04fe96: /* original 4f26, guest PC 0x0c04fe96 */
if(!s->budget--) { s->failed_pc=0x0c04fe96u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fe98;
P_0c04fe98: /* original 6df6, guest PC 0x0c04fe98 */
if(!s->budget--) { s->failed_pc=0x0c04fe98u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fe9a;
P_0c04fe9a: /* original 000b, guest PC 0x0c04fe9a */
if(!s->budget--) { s->failed_pc=0x0c04fe9au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04fe9c: /* original 6ef6, guest PC 0x0c04fe9c */
if(!s->budget--) { s->failed_pc=0x0c04fe9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04fe9eu,s,ram);
P_0c05ae5a: /* original 4f22, guest PC 0x0c05ae5a */
if(!s->budget--) { s->failed_pc=0x0c05ae5au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05ae5c;
P_0c05ae5c: /* original d237, guest PC 0x0c05ae5c */
if(!s->budget--) { s->failed_pc=0x0c05ae5cu; return 0; }
r[2]=read(ram,0x0c05af3cu,4);
goto P_0c05ae5e;
P_0c05ae5e: /* original 7fe8, guest PC 0x0c05ae5e */
if(!s->budget--) { s->failed_pc=0x0c05ae5eu; return 0; }
r[15]+=0xffffffe8u;
goto P_0c05ae60;
P_0c05ae60: /* original d337, guest PC 0x0c05ae60 */
if(!s->budget--) { s->failed_pc=0x0c05ae60u; return 0; }
r[3]=read(ram,0x0c05af40u,4);
goto P_0c05ae62;
P_0c05ae62: /* original 67f3, guest PC 0x0c05ae62 */
if(!s->budget--) { s->failed_pc=0x0c05ae62u; return 0; }
r[7]=r[15];
goto P_0c05ae64;
P_0c05ae64: /* original 61f3, guest PC 0x0c05ae64 */
if(!s->budget--) { s->failed_pc=0x0c05ae64u; return 0; }
r[1]=r[15];
goto P_0c05ae66;
P_0c05ae66: /* original 430b, guest PC 0x0c05ae66 */
if(!s->budget--) { s->failed_pc=0x0c05ae66u; return 0; }
target=r[3];
r[16]=0x0c05ae6au;
r[0]=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05ae6au) { target=s->pc; goto dispatch; }
goto P_0c05ae6a;
P_0c05ae68: /* original e018, guest PC 0x0c05ae68 */
if(!s->budget--) { s->failed_pc=0x0c05ae68u; return 0; }
r[0]=0x00000018u;
goto P_0c05ae6a;
P_0c05ae6a: /* original d136, guest PC 0x0c05ae6a */
if(!s->budget--) { s->failed_pc=0x0c05ae6au; return 0; }
r[1]=read(ram,0x0c05af44u,4);
goto P_0c05ae6c;
P_0c05ae6c: /* original 6012, guest PC 0x0c05ae6c */
if(!s->budget--) { s->failed_pc=0x0c05ae6cu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05ae6e;
P_0c05ae6e: /* original 8801, guest PC 0x0c05ae6e */
if(!s->budget--) { s->failed_pc=0x0c05ae6eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05ae70;
P_0c05ae70: /* original 8903, guest PC 0x0c05ae70 */
if(!s->budget--) { s->failed_pc=0x0c05ae70u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ae7a; }
goto P_0c05ae72;
P_0c05ae72: /* original d335, guest PC 0x0c05ae72 */
if(!s->budget--) { s->failed_pc=0x0c05ae72u; return 0; }
r[3]=read(ram,0x0c05af48u,4);
goto P_0c05ae74;
P_0c05ae74: /* original 6032, guest PC 0x0c05ae74 */
if(!s->budget--) { s->failed_pc=0x0c05ae74u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05ae76;
P_0c05ae76: /* original c810, guest PC 0x0c05ae76 */
if(!s->budget--) { s->failed_pc=0x0c05ae76u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c05ae78;
P_0c05ae78: /* original 8902, guest PC 0x0c05ae78 */
if(!s->budget--) { s->failed_pc=0x0c05ae78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ae80; }
goto P_0c05ae7a;
P_0c05ae7a: /* original 9e58, guest PC 0x0c05ae7a */
if(!s->budget--) { s->failed_pc=0x0c05ae7au; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05af2eu,2);
goto P_0c05ae7c;
P_0c05ae7c: /* original a001, guest PC 0x0c05ae7c */
if(!s->budget--) { s->failed_pc=0x0c05ae7cu; return 0; }
goto P_0c05ae82;
P_0c05ae7e: /* original 0009, guest PC 0x0c05ae7e */
if(!s->budget--) { s->failed_pc=0x0c05ae7eu; return 0; }
goto P_0c05ae80;
P_0c05ae80: /* original 9e56, guest PC 0x0c05ae80 */
if(!s->budget--) { s->failed_pc=0x0c05ae80u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05af30u,2);
goto P_0c05ae82;
P_0c05ae82: /* original 6053, guest PC 0x0c05ae82 */
if(!s->budget--) { s->failed_pc=0x0c05ae82u; return 0; }
r[0]=r[5];
goto P_0c05ae84;
P_0c05ae84: /* original 0009, guest PC 0x0c05ae84 */
if(!s->budget--) { s->failed_pc=0x0c05ae84u; return 0; }
goto P_0c05ae86;
P_0c05ae86: /* original 8801, guest PC 0x0c05ae86 */
if(!s->budget--) { s->failed_pc=0x0c05ae86u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05ae88;
P_0c05ae88: /* original 8b14, guest PC 0x0c05ae88 */
if(!s->budget--) { s->failed_pc=0x0c05ae88u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05aeb4; }
goto P_0c05ae8a;
P_0c05ae8a: /* original 761f, guest PC 0x0c05ae8a */
if(!s->budget--) { s->failed_pc=0x0c05ae8au; return 0; }
r[6]+=0x0000001fu;
goto P_0c05ae8c;
P_0c05ae8c: /* original d22f, guest PC 0x0c05ae8c */
if(!s->budget--) { s->failed_pc=0x0c05ae8cu; return 0; }
r[2]=read(ram,0x0c05af4cu,4);
goto P_0c05ae8e;
P_0c05ae8e: /* original e3e0, guest PC 0x0c05ae8e */
if(!s->budget--) { s->failed_pc=0x0c05ae8eu; return 0; }
r[3]=0xffffffe0u;
goto P_0c05ae90;
P_0c05ae90: /* original d02f, guest PC 0x0c05ae90 */
if(!s->budget--) { s->failed_pc=0x0c05ae90u; return 0; }
r[0]=read(ram,0x0c05af50u,4);
goto P_0c05ae92;
P_0c05ae92: /* original 2639, guest PC 0x0c05ae92 */
if(!s->budget--) { s->failed_pc=0x0c05ae92u; return 0; }
r[6]&=r[3];
goto P_0c05ae94;
P_0c05ae94: /* original 6102, guest PC 0x0c05ae94 */
if(!s->budget--) { s->failed_pc=0x0c05ae94u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c05ae96;
P_0c05ae96: /* original 2129, guest PC 0x0c05ae96 */
if(!s->budget--) { s->failed_pc=0x0c05ae96u; return 0; }
r[1]&=r[2];
goto P_0c05ae98;
P_0c05ae98: /* original e316, guest PC 0x0c05ae98 */
if(!s->budget--) { s->failed_pc=0x0c05ae98u; return 0; }
r[3]=0x00000016u;
goto P_0c05ae9a;
P_0c05ae9a: /* original 453d, guest PC 0x0c05ae9a */
if(!s->budget--) { s->failed_pc=0x0c05ae9au; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c05ae9c;
P_0c05ae9c: /* original 215b, guest PC 0x0c05ae9c */
if(!s->budget--) { s->failed_pc=0x0c05ae9cu; return 0; }
r[1]|=r[5];
goto P_0c05ae9e;
P_0c05ae9e: /* original 6063, guest PC 0x0c05ae9e */
if(!s->budget--) { s->failed_pc=0x0c05ae9eu; return 0; }
r[0]=r[6];
goto P_0c05aea0;
P_0c05aea0: /* original 0009, guest PC 0x0c05aea0 */
if(!s->budget--) { s->failed_pc=0x0c05aea0u; return 0; }
goto P_0c05aea2;
P_0c05aea2: /* original 4009, guest PC 0x0c05aea2 */
if(!s->budget--) { s->failed_pc=0x0c05aea2u; return 0; }
r[0]>>=2;
goto P_0c05aea4;
P_0c05aea4: /* original 4009, guest PC 0x0c05aea4 */
if(!s->budget--) { s->failed_pc=0x0c05aea4u; return 0; }
r[0]>>=2;
goto P_0c05aea6;
P_0c05aea6: /* original 4001, guest PC 0x0c05aea6 */
if(!s->budget--) { s->failed_pc=0x0c05aea6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c05aea8;
P_0c05aea8: /* original c91f, guest PC 0x0c05aea8 */
if(!s->budget--) { s->failed_pc=0x0c05aea8u; return 0; }
r[0]&=31u;
goto P_0c05aeaa;
P_0c05aeaa: /* original 4028, guest PC 0x0c05aeaa */
if(!s->budget--) { s->failed_pc=0x0c05aeaau; return 0; }
r[0]<<=16;
goto P_0c05aeac;
P_0c05aeac: /* original 210b, guest PC 0x0c05aeac */
if(!s->budget--) { s->failed_pc=0x0c05aeacu; return 0; }
r[1]|=r[0];
goto P_0c05aeae;
P_0c05aeae: /* original d028, guest PC 0x0c05aeae */
if(!s->budget--) { s->failed_pc=0x0c05aeaeu; return 0; }
r[0]=read(ram,0x0c05af50u,4);
goto P_0c05aeb0;
P_0c05aeb0: /* original a019, guest PC 0x0c05aeb0 */
if(!s->budget--) { s->failed_pc=0x0c05aeb0u; return 0; }
write(ram,r[0],r[1],4);
goto P_0c05aee6;
P_0c05aeb2: /* original 2012, guest PC 0x0c05aeb2 */
if(!s->budget--) { s->failed_pc=0x0c05aeb2u; return 0; }
write(ram,r[0],r[1],4);
goto P_0c05aeb4;
P_0c05aeb4: /* original d223, guest PC 0x0c05aeb4 */
if(!s->budget--) { s->failed_pc=0x0c05aeb4u; return 0; }
r[2]=read(ram,0x0c05af44u,4);
goto P_0c05aeb6;
P_0c05aeb6: /* original 6022, guest PC 0x0c05aeb6 */
if(!s->budget--) { s->failed_pc=0x0c05aeb6u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05aeb8;
P_0c05aeb8: /* original 8801, guest PC 0x0c05aeb8 */
if(!s->budget--) { s->failed_pc=0x0c05aeb8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05aeba;
P_0c05aeba: /* original 8910, guest PC 0x0c05aeba */
if(!s->budget--) { s->failed_pc=0x0c05aebau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05aede; }
goto P_0c05aebc;
P_0c05aebc: /* original d322, guest PC 0x0c05aebc */
if(!s->budget--) { s->failed_pc=0x0c05aebcu; return 0; }
r[3]=read(ram,0x0c05af48u,4);
goto P_0c05aebe;
P_0c05aebe: /* original e501, guest PC 0x0c05aebe */
if(!s->budget--) { s->failed_pc=0x0c05aebeu; return 0; }
r[5]=0x00000001u;
goto P_0c05aec0;
P_0c05aec0: /* original 6032, guest PC 0x0c05aec0 */
if(!s->budget--) { s->failed_pc=0x0c05aec0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05aec2;
P_0c05aec2: /* original 2059, guest PC 0x0c05aec2 */
if(!s->budget--) { s->failed_pc=0x0c05aec2u; return 0; }
r[0]&=r[5];
goto P_0c05aec4;
P_0c05aec4: /* original 8801, guest PC 0x0c05aec4 */
if(!s->budget--) { s->failed_pc=0x0c05aec4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05aec6;
P_0c05aec6: /* original 8906, guest PC 0x0c05aec6 */
if(!s->budget--) { s->failed_pc=0x0c05aec6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05aed6; }
goto P_0c05aec8;
P_0c05aec8: /* original d11f, guest PC 0x0c05aec8 */
if(!s->budget--) { s->failed_pc=0x0c05aec8u; return 0; }
r[1]=read(ram,0x0c05af48u,4);
goto P_0c05aeca;
P_0c05aeca: /* original 6012, guest PC 0x0c05aeca */
if(!s->budget--) { s->failed_pc=0x0c05aecau; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05aecc;
P_0c05aecc: /* original c92c, guest PC 0x0c05aecc */
if(!s->budget--) { s->failed_pc=0x0c05aeccu; return 0; }
r[0]&=44u;
goto P_0c05aece;
P_0c05aece: /* original 8820, guest PC 0x0c05aece */
if(!s->budget--) { s->failed_pc=0x0c05aeceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c05aed0;
P_0c05aed0: /* original 8b01, guest PC 0x0c05aed0 */
if(!s->budget--) { s->failed_pc=0x0c05aed0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05aed6; }
goto P_0c05aed2;
P_0c05aed2: /* original 2558, guest PC 0x0c05aed2 */
if(!s->budget--) { s->failed_pc=0x0c05aed2u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c05aed4;
P_0c05aed4: /* original 8b06, guest PC 0x0c05aed4 */
if(!s->budget--) { s->failed_pc=0x0c05aed4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05aee4; }
goto P_0c05aed6;
P_0c05aed6: /* original d31c, guest PC 0x0c05aed6 */
if(!s->budget--) { s->failed_pc=0x0c05aed6u; return 0; }
r[3]=read(ram,0x0c05af48u,4);
goto P_0c05aed8;
P_0c05aed8: /* original 6032, guest PC 0x0c05aed8 */
if(!s->budget--) { s->failed_pc=0x0c05aed8u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05aeda;
P_0c05aeda: /* original c820, guest PC 0x0c05aeda */
if(!s->budget--) { s->failed_pc=0x0c05aedau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c05aedc;
P_0c05aedc: /* original 8902, guest PC 0x0c05aedc */
if(!s->budget--) { s->failed_pc=0x0c05aedcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05aee4; }
goto P_0c05aede;
P_0c05aede: /* original 9628, guest PC 0x0c05aede */
if(!s->budget--) { s->failed_pc=0x0c05aedeu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05af32u,2);
goto P_0c05aee0;
P_0c05aee0: /* original a001, guest PC 0x0c05aee0 */
if(!s->budget--) { s->failed_pc=0x0c05aee0u; return 0; }
goto P_0c05aee6;
P_0c05aee2: /* original 0009, guest PC 0x0c05aee2 */
if(!s->budget--) { s->failed_pc=0x0c05aee2u; return 0; }
goto P_0c05aee4;
P_0c05aee4: /* original 9626, guest PC 0x0c05aee4 */
if(!s->budget--) { s->failed_pc=0x0c05aee4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05af34u,2);
goto P_0c05aee6;
P_0c05aee6: /* original e048, guest PC 0x0c05aee6 */
if(!s->budget--) { s->failed_pc=0x0c05aee6u; return 0; }
r[0]=0x00000048u;
goto P_0c05aee8;
P_0c05aee8: /* original 9325, guest PC 0x0c05aee8 */
if(!s->budget--) { s->failed_pc=0x0c05aee8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05af36u,2);
goto P_0c05aeea;
P_0c05aeea: /* original d51a, guest PC 0x0c05aeea */
if(!s->budget--) { s->failed_pc=0x0c05aeeau; return 0; }
r[5]=read(ram,0x0c05af54u,4);
goto P_0c05aeec;
P_0c05aeec: /* original 05e6, guest PC 0x0c05aeec */
if(!s->budget--) { s->failed_pc=0x0c05aeecu; return 0; }
write(ram,r[5]+r[0],r[14],4);
goto P_0c05aeee;
P_0c05aeee: /* original e04c, guest PC 0x0c05aeee */
if(!s->budget--) { s->failed_pc=0x0c05aeeeu; return 0; }
r[0]=0x0000004cu;
goto P_0c05aef0;
P_0c05aef0: /* original 3430, guest PC 0x0c05aef0 */
if(!s->budget--) { s->failed_pc=0x0c05aef0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c05aef2;
P_0c05aef2: /* original 8d02, guest PC 0x0c05aef2 */
if(!s->budget--) { s->failed_pc=0x0c05aef2u; return 0; }
cond=r[17]&1u;
write(ram,r[5]+r[0],r[6],4);
if(cond) { goto P_0c05aefa; }
goto P_0c05aef6;
P_0c05aef4: /* original 0566, guest PC 0x0c05aef4 */
if(!s->budget--) { s->failed_pc=0x0c05aef4u; return 0; }
write(ram,r[5]+r[0],r[6],4);
goto P_0c05aef6;
P_0c05aef6: /* original a002, guest PC 0x0c05aef6 */
if(!s->budget--) { s->failed_pc=0x0c05aef6u; return 0; }
r[0]=r[4];
goto P_0c05aefe;
P_0c05aef8: /* original 6043, guest PC 0x0c05aef8 */
if(!s->budget--) { s->failed_pc=0x0c05aef8u; return 0; }
r[0]=r[4];
goto P_0c05aefa;
P_0c05aefa: /* original d117, guest PC 0x0c05aefa */
if(!s->budget--) { s->failed_pc=0x0c05aefau; return 0; }
r[1]=read(ram,0x0c05af58u,4);
goto P_0c05aefc;
P_0c05aefc: /* original 6012, guest PC 0x0c05aefc */
if(!s->budget--) { s->failed_pc=0x0c05aefcu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05aefe;
P_0c05aefe: /* original 4008, guest PC 0x0c05aefe */
if(!s->budget--) { s->failed_pc=0x0c05aefeu; return 0; }
r[0]<<=2;
goto P_0c05af00;
P_0c05af00: /* original 027e, guest PC 0x0c05af00 */
if(!s->budget--) { s->failed_pc=0x0c05af00u; return 0; }
r[2]=read(ram,r[7]+r[0],4);
goto P_0c05af02;
P_0c05af02: /* original e050, guest PC 0x0c05af02 */
if(!s->budget--) { s->failed_pc=0x0c05af02u; return 0; }
r[0]=0x00000050u;
goto P_0c05af04;
P_0c05af04: /* original 4209, guest PC 0x0c05af04 */
if(!s->budget--) { s->failed_pc=0x0c05af04u; return 0; }
r[2]>>=2;
goto P_0c05af06;
P_0c05af06: /* original 4201, guest PC 0x0c05af06 */
if(!s->budget--) { s->failed_pc=0x0c05af06u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]>>=1;
goto P_0c05af08;
P_0c05af08: /* original 0526, guest PC 0x0c05af08 */
if(!s->budget--) { s->failed_pc=0x0c05af08u; return 0; }
write(ram,r[5]+r[0],r[2],4);
goto P_0c05af0a;
P_0c05af0a: /* original e04c, guest PC 0x0c05af0a */
if(!s->budget--) { s->failed_pc=0x0c05af0au; return 0; }
r[0]=0x0000004cu;
goto P_0c05af0c;
P_0c05af0c: /* original 035e, guest PC 0x0c05af0c */
if(!s->budget--) { s->failed_pc=0x0c05af0cu; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c05af0e;
P_0c05af0e: /* original e048, guest PC 0x0c05af0e */
if(!s->budget--) { s->failed_pc=0x0c05af0eu; return 0; }
r[0]=0x00000048u;
goto P_0c05af10;
P_0c05af10: /* original 025e, guest PC 0x0c05af10 */
if(!s->budget--) { s->failed_pc=0x0c05af10u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c05af12;
P_0c05af12: /* original e050, guest PC 0x0c05af12 */
if(!s->budget--) { s->failed_pc=0x0c05af12u; return 0; }
r[0]=0x00000050u;
goto P_0c05af14;
P_0c05af14: /* original 0237, guest PC 0x0c05af14 */
if(!s->budget--) { s->failed_pc=0x0c05af14u; return 0; }
r[19]=r[2]*r[3];
goto P_0c05af16;
P_0c05af16: /* original 031a, guest PC 0x0c05af16 */
if(!s->budget--) { s->failed_pc=0x0c05af16u; return 0; }
r[3]=r[19];
goto P_0c05af18;
P_0c05af18: /* original 015e, guest PC 0x0c05af18 */
if(!s->budget--) { s->failed_pc=0x0c05af18u; return 0; }
r[1]=read(ram,r[5]+r[0],4);
goto P_0c05af1a;
P_0c05af1a: /* original e060, guest PC 0x0c05af1a */
if(!s->budget--) { s->failed_pc=0x0c05af1au; return 0; }
r[0]=0x00000060u;
goto P_0c05af1c;
P_0c05af1c: /* original 0317, guest PC 0x0c05af1c */
if(!s->budget--) { s->failed_pc=0x0c05af1cu; return 0; }
r[19]=r[3]*r[1];
goto P_0c05af1e;
P_0c05af1e: /* original 031a, guest PC 0x0c05af1e */
if(!s->budget--) { s->failed_pc=0x0c05af1eu; return 0; }
r[3]=r[19];
goto P_0c05af20;
P_0c05af20: /* original 0536, guest PC 0x0c05af20 */
if(!s->budget--) { s->failed_pc=0x0c05af20u; return 0; }
write(ram,r[5]+r[0],r[3],4);
goto P_0c05af22;
P_0c05af22: /* original 7f18, guest PC 0x0c05af22 */
if(!s->budget--) { s->failed_pc=0x0c05af22u; return 0; }
r[15]+=0x00000018u;
goto P_0c05af24;
P_0c05af24: /* original 4f26, guest PC 0x0c05af24 */
if(!s->budget--) { s->failed_pc=0x0c05af24u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05af26;
P_0c05af26: /* original 000b, guest PC 0x0c05af26 */
if(!s->budget--) { s->failed_pc=0x0c05af26u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05af28: /* original 6ef6, guest PC 0x0c05af28 */
if(!s->budget--) { s->failed_pc=0x0c05af28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c05af2au,s,ram);
P_0c07f08e: /* original 4f22, guest PC 0x0c07f08e */
if(!s->budget--) { s->failed_pc=0x0c07f08eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07f090;
P_0c07f090: /* original 7ffc, guest PC 0x0c07f090 */
if(!s->budget--) { s->failed_pc=0x0c07f090u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07f092;
P_0c07f092: /* original 2f42, guest PC 0x0c07f092 */
if(!s->budget--) { s->failed_pc=0x0c07f092u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07f094;
P_0c07f094: /* original d318, guest PC 0x0c07f094 */
if(!s->budget--) { s->failed_pc=0x0c07f094u; return 0; }
r[3]=read(ram,0x0c07f0f8u,4);
goto P_0c07f096;
P_0c07f096: /* original 9e16, guest PC 0x0c07f096 */
if(!s->budget--) { s->failed_pc=0x0c07f096u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f0c6u,2);
goto P_0c07f098;
P_0c07f098: /* original 6432, guest PC 0x0c07f098 */
if(!s->budget--) { s->failed_pc=0x0c07f098u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c07f09a;
P_0c07f09a: /* original 2429, guest PC 0x0c07f09a */
if(!s->budget--) { s->failed_pc=0x0c07f09au; return 0; }
r[4]&=r[2];
goto P_0c07f09c;
P_0c07f09c: /* original 2448, guest PC 0x0c07f09c */
if(!s->budget--) { s->failed_pc=0x0c07f09cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07f09e;
P_0c07f09e: /* original 8b2f, guest PC 0x0c07f09e */
if(!s->budget--) { s->failed_pc=0x0c07f09eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07f100; }
goto P_0c07f0a0;
P_0c07f0a0: /* original e000, guest PC 0x0c07f0a0 */
if(!s->budget--) { s->failed_pc=0x0c07f0a0u; return 0; }
r[0]=0x00000000u;
goto P_0c07f0a2;
P_0c07f0a2: /* original 2f06, guest PC 0x0c07f0a2 */
if(!s->budget--) { s->failed_pc=0x0c07f0a2u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f0a4;
P_0c07f0a4: /* original 9510, guest PC 0x0c07f0a4 */
if(!s->budget--) { s->failed_pc=0x0c07f0a4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f0c8u,2);
goto P_0c07f0a6;
P_0c07f0a6: /* original 940e, guest PC 0x0c07f0a6 */
if(!s->budget--) { s->failed_pc=0x0c07f0a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f0c6u,2);
goto P_0c07f0a8;
P_0c07f0a8: /* original d314, guest PC 0x0c07f0a8 */
if(!s->budget--) { s->failed_pc=0x0c07f0a8u; return 0; }
r[3]=read(ram,0x0c07f0fcu,4);
goto P_0c07f0aa;
P_0c07f0aa: /* original d608, guest PC 0x0c07f0aa */
if(!s->budget--) { s->failed_pc=0x0c07f0aau; return 0; }
r[6]=read(ram,0x0c07f0ccu,4);
goto P_0c07f0ac;
P_0c07f0ac: /* original 430b, guest PC 0x0c07f0ac */
if(!s->budget--) { s->failed_pc=0x0c07f0acu; return 0; }
target=r[3];
r[16]=0x0c07f0b0u;
r[7]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f0b0u) { target=s->pc; goto dispatch; }
goto P_0c07f0b0;
P_0c07f0ae: /* original 6703, guest PC 0x0c07f0ae */
if(!s->budget--) { s->failed_pc=0x0c07f0aeu; return 0; }
r[7]=r[0];
goto P_0c07f0b0;
P_0c07f0b0: /* original a031, guest PC 0x0c07f0b0 */
if(!s->budget--) { s->failed_pc=0x0c07f0b0u; return 0; }
goto P_0c07f116;
P_0c07f0b2: /* original 0009, guest PC 0x0c07f0b2 */
if(!s->budget--) { s->failed_pc=0x0c07f0b2u; return 0; }
return vf3_matrix_family(0x0c07f0b4u,s,ram);
P_0c07f100: /* original 6043, guest PC 0x0c07f100 */
if(!s->budget--) { s->failed_pc=0x0c07f100u; return 0; }
r[0]=r[4];
goto P_0c07f102;
P_0c07f102: /* original 8810, guest PC 0x0c07f102 */
if(!s->budget--) { s->failed_pc=0x0c07f102u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c07f104;
P_0c07f104: /* original 8b08, guest PC 0x0c07f104 */
if(!s->budget--) { s->failed_pc=0x0c07f104u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07f118; }
goto P_0c07f106;
P_0c07f106: /* original e300, guest PC 0x0c07f106 */
if(!s->budget--) { s->failed_pc=0x0c07f106u; return 0; }
r[3]=0x00000000u;
goto P_0c07f108;
P_0c07f108: /* original 2f36, guest PC 0x0c07f108 */
if(!s->budget--) { s->failed_pc=0x0c07f108u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f10a;
P_0c07f10a: /* original 6733, guest PC 0x0c07f10a */
if(!s->budget--) { s->failed_pc=0x0c07f10au; return 0; }
r[7]=r[3];
goto P_0c07f10c;
P_0c07f10c: /* original 9575, guest PC 0x0c07f10c */
if(!s->budget--) { s->failed_pc=0x0c07f10cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f1fau,2);
goto P_0c07f10e;
P_0c07f10e: /* original d63e, guest PC 0x0c07f10e */
if(!s->budget--) { s->failed_pc=0x0c07f10eu; return 0; }
r[6]=read(ram,0x0c07f208u,4);
goto P_0c07f110;
P_0c07f110: /* original d23e, guest PC 0x0c07f110 */
if(!s->budget--) { s->failed_pc=0x0c07f110u; return 0; }
r[2]=read(ram,0x0c07f20cu,4);
goto P_0c07f112;
P_0c07f112: /* original 420b, guest PC 0x0c07f112 */
if(!s->budget--) { s->failed_pc=0x0c07f112u; return 0; }
target=r[2];
r[16]=0x0c07f116u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f116u) { target=s->pc; goto dispatch; }
goto P_0c07f116;
P_0c07f114: /* original 64e3, guest PC 0x0c07f114 */
if(!s->budget--) { s->failed_pc=0x0c07f114u; return 0; }
r[4]=r[14];
goto P_0c07f116;
P_0c07f116: /* original 7f04, guest PC 0x0c07f116 */
if(!s->budget--) { s->failed_pc=0x0c07f116u; return 0; }
r[15]+=0x00000004u;
goto P_0c07f118;
P_0c07f118: /* original 64f2, guest PC 0x0c07f118 */
if(!s->budget--) { s->failed_pc=0x0c07f118u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07f11a;
P_0c07f11a: /* original 7f04, guest PC 0x0c07f11a */
if(!s->budget--) { s->failed_pc=0x0c07f11au; return 0; }
r[15]+=0x00000004u;
goto P_0c07f11c;
P_0c07f11c: /* original 4f26, guest PC 0x0c07f11c */
if(!s->budget--) { s->failed_pc=0x0c07f11cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07f11e;
P_0c07f11e: /* original d33c, guest PC 0x0c07f11e */
if(!s->budget--) { s->failed_pc=0x0c07f11eu; return 0; }
r[3]=read(ram,0x0c07f210u,4);
goto P_0c07f120;
P_0c07f120: /* original 65e3, guest PC 0x0c07f120 */
if(!s->budget--) { s->failed_pc=0x0c07f120u; return 0; }
r[5]=r[14];
goto P_0c07f122;
P_0c07f122: /* original 432b, guest PC 0x0c07f122 */
if(!s->budget--) { s->failed_pc=0x0c07f122u; return 0; }
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
P_0c07f124: /* original 6ef6, guest PC 0x0c07f124 */
if(!s->budget--) { s->failed_pc=0x0c07f124u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07f126u,s,ram);
P_0c080796: /* original 4f22, guest PC 0x0c080796 */
if(!s->budget--) { s->failed_pc=0x0c080796u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c080798;
P_0c080798: /* original 650d, guest PC 0x0c080798 */
if(!s->budget--) { s->failed_pc=0x0c080798u; return 0; }
r[5]=r[0]&65535u;
goto P_0c08079a;
P_0c08079a: /* original 8542, guest PC 0x0c08079a */
if(!s->budget--) { s->failed_pc=0x0c08079au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+4,2);
goto P_0c08079c;
P_0c08079c: /* original 9342, guest PC 0x0c08079c */
if(!s->budget--) { s->failed_pc=0x0c08079cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080824u,2);
goto P_0c08079e;
P_0c08079e: /* original 6e0d, guest PC 0x0c08079e */
if(!s->budget--) { s->failed_pc=0x0c08079eu; return 0; }
r[14]=r[0]&65535u;
goto P_0c0807a0;
P_0c0807a0: /* original 6641, guest PC 0x0c0807a0 */
if(!s->budget--) { s->failed_pc=0x0c0807a0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[6]=tmp;
goto P_0c0807a2;
P_0c0807a2: /* original 3e30, guest PC 0x0c0807a2 */
if(!s->budget--) { s->failed_pc=0x0c0807a2u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c0807a4;
P_0c0807a4: /* original 7ffc, guest PC 0x0c0807a4 */
if(!s->budget--) { s->failed_pc=0x0c0807a4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0807a6;
P_0c0807a6: /* original 8f0e, guest PC 0x0c0807a6 */
if(!s->budget--) { s->failed_pc=0x0c0807a6u; return 0; }
cond=r[17]&1u;
r[6]=r[6]&65535u;
if(!cond) { goto P_0c0807c6; }
goto P_0c0807aa;
P_0c0807a8: /* original 666d, guest PC 0x0c0807a8 */
if(!s->budget--) { s->failed_pc=0x0c0807a8u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0807aa;
P_0c0807aa: /* original e207, guest PC 0x0c0807aa */
if(!s->budget--) { s->failed_pc=0x0c0807aau; return 0; }
r[2]=0x00000007u;
goto P_0c0807ac;
P_0c0807ac: /* original 452d, guest PC 0x0c0807ac */
if(!s->budget--) { s->failed_pc=0x0c0807acu; return 0; }
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?r[5]>>((-r[2])&31u):0):r[5]<<(r[2]&31u);
goto P_0c0807ae;
P_0c0807ae: /* original 4600, guest PC 0x0c0807ae */
if(!s->budget--) { s->failed_pc=0x0c0807aeu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0807b0;
P_0c0807b0: /* original 265b, guest PC 0x0c0807b0 */
if(!s->budget--) { s->failed_pc=0x0c0807b0u; return 0; }
r[6]|=r[5];
goto P_0c0807b2;
P_0c0807b2: /* original 65e3, guest PC 0x0c0807b2 */
if(!s->budget--) { s->failed_pc=0x0c0807b2u; return 0; }
r[5]=r[14];
goto P_0c0807b4;
P_0c0807b4: /* original 2f62, guest PC 0x0c0807b4 */
if(!s->budget--) { s->failed_pc=0x0c0807b4u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0807b6;
P_0c0807b6: /* original e100, guest PC 0x0c0807b6 */
if(!s->budget--) { s->failed_pc=0x0c0807b6u; return 0; }
r[1]=0x00000000u;
goto P_0c0807b8;
P_0c0807b8: /* original 6713, guest PC 0x0c0807b8 */
if(!s->budget--) { s->failed_pc=0x0c0807b8u; return 0; }
r[7]=r[1];
goto P_0c0807ba;
P_0c0807ba: /* original 2f16, guest PC 0x0c0807ba */
if(!s->budget--) { s->failed_pc=0x0c0807bau; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0807bc;
P_0c0807bc: /* original d61b, guest PC 0x0c0807bc */
if(!s->budget--) { s->failed_pc=0x0c0807bcu; return 0; }
r[6]=read(ram,0x0c08082cu,4);
goto P_0c0807be;
P_0c0807be: /* original d31c, guest PC 0x0c0807be */
if(!s->budget--) { s->failed_pc=0x0c0807beu; return 0; }
r[3]=read(ram,0x0c080830u,4);
goto P_0c0807c0;
P_0c0807c0: /* original 430b, guest PC 0x0c0807c0 */
if(!s->budget--) { s->failed_pc=0x0c0807c0u; return 0; }
target=r[3];
r[16]=0x0c0807c4u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0807c4u) { target=s->pc; goto dispatch; }
goto P_0c0807c4;
P_0c0807c2: /* original 54f1, guest PC 0x0c0807c2 */
if(!s->budget--) { s->failed_pc=0x0c0807c2u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0807c4;
P_0c0807c4: /* original 7f04, guest PC 0x0c0807c4 */
if(!s->budget--) { s->failed_pc=0x0c0807c4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0807c6;
P_0c0807c6: /* original 7f04, guest PC 0x0c0807c6 */
if(!s->budget--) { s->failed_pc=0x0c0807c6u; return 0; }
r[15]+=0x00000004u;
goto P_0c0807c8;
P_0c0807c8: /* original 4f26, guest PC 0x0c0807c8 */
if(!s->budget--) { s->failed_pc=0x0c0807c8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0807ca;
P_0c0807ca: /* original 000b, guest PC 0x0c0807ca */
if(!s->budget--) { s->failed_pc=0x0c0807cau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0807cc: /* original 6ef6, guest PC 0x0c0807cc */
if(!s->budget--) { s->failed_pc=0x0c0807ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0807ceu,s,ram);
P_0c0a1fd2: /* original 4f22, guest PC 0x0c0a1fd2 */
if(!s->budget--) { s->failed_pc=0x0c0a1fd2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a1fd4;
P_0c0a1fd4: /* original d308, guest PC 0x0c0a1fd4 */
if(!s->budget--) { s->failed_pc=0x0c0a1fd4u; return 0; }
r[3]=read(ram,0x0c0a1ff8u,4);
goto P_0c0a1fd6;
P_0c0a1fd6: /* original 430b, guest PC 0x0c0a1fd6 */
if(!s->budget--) { s->failed_pc=0x0c0a1fd6u; return 0; }
target=r[3];
r[16]=0x0c0a1fdau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a1fdau) { target=s->pc; goto dispatch; }
goto P_0c0a1fda;
P_0c0a1fd8: /* original 0009, guest PC 0x0c0a1fd8 */
if(!s->budget--) { s->failed_pc=0x0c0a1fd8u; return 0; }
goto P_0c0a1fda;
P_0c0a1fda: /* original 6403, guest PC 0x0c0a1fda */
if(!s->budget--) { s->failed_pc=0x0c0a1fdau; return 0; }
r[4]=r[0];
goto P_0c0a1fdc;
P_0c0a1fdc: /* original 6241, guest PC 0x0c0a1fdc */
if(!s->budget--) { s->failed_pc=0x0c0a1fdcu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[2]=tmp;
goto P_0c0a1fde;
P_0c0a1fde: /* original 2228, guest PC 0x0c0a1fde */
if(!s->budget--) { s->failed_pc=0x0c0a1fdeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a1fe0;
P_0c0a1fe0: /* original 8905, guest PC 0x0c0a1fe0 */
if(!s->budget--) { s->failed_pc=0x0c0a1fe0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1fee; }
goto P_0c0a1fe2;
P_0c0a1fe2: /* original 8541, guest PC 0x0c0a1fe2 */
if(!s->budget--) { s->failed_pc=0x0c0a1fe2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c0a1fe4;
P_0c0a1fe4: /* original 2008, guest PC 0x0c0a1fe4 */
if(!s->budget--) { s->failed_pc=0x0c0a1fe4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a1fe6;
P_0c0a1fe6: /* original 8902, guest PC 0x0c0a1fe6 */
if(!s->budget--) { s->failed_pc=0x0c0a1fe6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a1fee; }
goto P_0c0a1fe8;
P_0c0a1fe8: /* original 4f26, guest PC 0x0c0a1fe8 */
if(!s->budget--) { s->failed_pc=0x0c0a1fe8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a1fea;
P_0c0a1fea: /* original 000b, guest PC 0x0c0a1fea */
if(!s->budget--) { s->failed_pc=0x0c0a1feau; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c0a1fec: /* original e001, guest PC 0x0c0a1fec */
if(!s->budget--) { s->failed_pc=0x0c0a1fecu; return 0; }
r[0]=0x00000001u;
goto P_0c0a1fee;
P_0c0a1fee: /* original e000, guest PC 0x0c0a1fee */
if(!s->budget--) { s->failed_pc=0x0c0a1feeu; return 0; }
r[0]=0x00000000u;
goto P_0c0a1ff0;
P_0c0a1ff0: /* original 4f26, guest PC 0x0c0a1ff0 */
if(!s->budget--) { s->failed_pc=0x0c0a1ff0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a1ff2;
P_0c0a1ff2: /* original 000b, guest PC 0x0c0a1ff2 */
if(!s->budget--) { s->failed_pc=0x0c0a1ff2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a1ff4: /* original 0009, guest PC 0x0c0a1ff4 */
if(!s->budget--) { s->failed_pc=0x0c0a1ff4u; return 0; }
return vf3_matrix_family(0x0c0a1ff6u,s,ram);
P_0c0a65d4: /* original 4f22, guest PC 0x0c0a65d4 */
if(!s->budget--) { s->failed_pc=0x0c0a65d4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a65d6;
P_0c0a65d6: /* original 7ff0, guest PC 0x0c0a65d6 */
if(!s->budget--) { s->failed_pc=0x0c0a65d6u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a65d8;
P_0c0a65d8: /* original 2f42, guest PC 0x0c0a65d8 */
if(!s->budget--) { s->failed_pc=0x0c0a65d8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a65da;
P_0c0a65da: /* original d312, guest PC 0x0c0a65da */
if(!s->budget--) { s->failed_pc=0x0c0a65dau; return 0; }
r[3]=read(ram,0x0c0a6624u,4);
goto P_0c0a65dc;
P_0c0a65dc: /* original 430b, guest PC 0x0c0a65dc */
if(!s->budget--) { s->failed_pc=0x0c0a65dcu; return 0; }
target=r[3];
r[16]=0x0c0a65e0u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a65e0u) { target=s->pc; goto dispatch; }
goto P_0c0a65e0;
P_0c0a65de: /* original 7410, guest PC 0x0c0a65de */
if(!s->budget--) { s->failed_pc=0x0c0a65deu; return 0; }
r[4]+=0x00000010u;
goto P_0c0a65e0;
P_0c0a65e0: /* original 64e2, guest PC 0x0c0a65e0 */
if(!s->budget--) { s->failed_pc=0x0c0a65e0u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0a65e2;
P_0c0a65e2: /* original 6be3, guest PC 0x0c0a65e2 */
if(!s->budget--) { s->failed_pc=0x0c0a65e2u; return 0; }
r[11]=r[14];
goto P_0c0a65e4;
P_0c0a65e4: /* original 6ec3, guest PC 0x0c0a65e4 */
if(!s->budget--) { s->failed_pc=0x0c0a65e4u; return 0; }
r[14]=r[12];
goto P_0c0a65e6;
P_0c0a65e6: /* original 7e04, guest PC 0x0c0a65e6 */
if(!s->budget--) { s->failed_pc=0x0c0a65e6u; return 0; }
r[14]+=0x00000004u;
goto P_0c0a65e8;
P_0c0a65e8: /* original 6d4c, guest PC 0x0c0a65e8 */
if(!s->budget--) { s->failed_pc=0x0c0a65e8u; return 0; }
r[13]=r[4]&255u;
goto P_0c0a65ea;
P_0c0a65ea: /* original 2cd2, guest PC 0x0c0a65ea */
if(!s->budget--) { s->failed_pc=0x0c0a65eau; return 0; }
write(ram,r[12],r[13],4);
goto P_0c0a65ec;
P_0c0a65ec: /* original 7b04, guest PC 0x0c0a65ec */
if(!s->budget--) { s->failed_pc=0x0c0a65ecu; return 0; }
r[11]+=0x00000004u;
goto P_0c0a65ee;
P_0c0a65ee: /* original d20e, guest PC 0x0c0a65ee */
if(!s->budget--) { s->failed_pc=0x0c0a65eeu; return 0; }
r[2]=read(ram,0x0c0a6628u,4);
goto P_0c0a65f0;
P_0c0a65f0: /* original 65e3, guest PC 0x0c0a65f0 */
if(!s->budget--) { s->failed_pc=0x0c0a65f0u; return 0; }
r[5]=r[14];
goto P_0c0a65f2;
P_0c0a65f2: /* original 420b, guest PC 0x0c0a65f2 */
if(!s->budget--) { s->failed_pc=0x0c0a65f2u; return 0; }
target=r[2];
r[16]=0x0c0a65f6u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a65f6u) { target=s->pc; goto dispatch; }
goto P_0c0a65f6;
P_0c0a65f4: /* original 64b3, guest PC 0x0c0a65f4 */
if(!s->budget--) { s->failed_pc=0x0c0a65f4u; return 0; }
r[4]=r[11];
goto P_0c0a65f6;
P_0c0a65f6: /* original 7dff, guest PC 0x0c0a65f6 */
if(!s->budget--) { s->failed_pc=0x0c0a65f6u; return 0; }
r[13]+=0xffffffffu;
goto P_0c0a65f8;
P_0c0a65f8: /* original 4d15, guest PC 0x0c0a65f8 */
if(!s->budget--) { s->failed_pc=0x0c0a65f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c0a65fa;
P_0c0a65fa: /* original 7b0c, guest PC 0x0c0a65fa */
if(!s->budget--) { s->failed_pc=0x0c0a65fau; return 0; }
r[11]+=0x0000000cu;
goto P_0c0a65fc;
P_0c0a65fc: /* original 8df7, guest PC 0x0c0a65fc */
if(!s->budget--) { s->failed_pc=0x0c0a65fcu; return 0; }
cond=r[17]&1u;
r[14]+=0x0000000cu;
if(cond) { goto P_0c0a65ee; }
goto P_0c0a6600;
P_0c0a65fe: /* original 7e0c, guest PC 0x0c0a65fe */
if(!s->budget--) { s->failed_pc=0x0c0a65feu; return 0; }
r[14]+=0x0000000cu;
goto P_0c0a6600;
P_0c0a6600: /* original 7f10, guest PC 0x0c0a6600 */
if(!s->budget--) { s->failed_pc=0x0c0a6600u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a6602;
P_0c0a6602: /* original 4f26, guest PC 0x0c0a6602 */
if(!s->budget--) { s->failed_pc=0x0c0a6602u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a6604;
P_0c0a6604: /* original 6bf6, guest PC 0x0c0a6604 */
if(!s->budget--) { s->failed_pc=0x0c0a6604u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a6606;
P_0c0a6606: /* original 6cf6, guest PC 0x0c0a6606 */
if(!s->budget--) { s->failed_pc=0x0c0a6606u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a6608;
P_0c0a6608: /* original 6df6, guest PC 0x0c0a6608 */
if(!s->budget--) { s->failed_pc=0x0c0a6608u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a660a;
P_0c0a660a: /* original 000b, guest PC 0x0c0a660a */
if(!s->budget--) { s->failed_pc=0x0c0a660au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a660c: /* original 6ef6, guest PC 0x0c0a660c */
if(!s->budget--) { s->failed_pc=0x0c0a660cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a660eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c04fe46u,0x0c04fe48u,0x0c04fe4au,0x0c04fe4cu,0x0c04fe4eu,0x0c04fe50u,0x0c04fe52u,0x0c04fe54u,0x0c04fe56u,0x0c04fe58u,0x0c04fe5au,0x0c04fe5cu,0x0c04fe5eu,0x0c04fe60u,0x0c04fe62u,0x0c04fe64u,
0x0c04fe66u,0x0c04fe68u,0x0c04fe6au,0x0c04fe6cu,0x0c04fe6eu,0x0c04fe70u,0x0c04fe72u,0x0c04fe74u,0x0c04fe76u,0x0c04fe78u,0x0c04fe7au,0x0c04fe7cu,0x0c04fe7eu,0x0c04fe80u,0x0c04fe82u,0x0c04fe84u,
0x0c04fe86u,0x0c04fe88u,0x0c04fe8au,0x0c04fe8cu,0x0c04fe8eu,0x0c04fe90u,0x0c04fe92u,0x0c04fe94u,0x0c04fe96u,0x0c04fe98u,0x0c04fe9au,0x0c04fe9cu,0x0c05ae5au,0x0c05ae5cu,0x0c05ae5eu,0x0c05ae60u,
0x0c05ae62u,0x0c05ae64u,0x0c05ae66u,0x0c05ae68u,0x0c05ae6au,0x0c05ae6cu,0x0c05ae6eu,0x0c05ae70u,0x0c05ae72u,0x0c05ae74u,0x0c05ae76u,0x0c05ae78u,0x0c05ae7au,0x0c05ae7cu,0x0c05ae7eu,0x0c05ae80u,
0x0c05ae82u,0x0c05ae84u,0x0c05ae86u,0x0c05ae88u,0x0c05ae8au,0x0c05ae8cu,0x0c05ae8eu,0x0c05ae90u,0x0c05ae92u,0x0c05ae94u,0x0c05ae96u,0x0c05ae98u,0x0c05ae9au,0x0c05ae9cu,0x0c05ae9eu,0x0c05aea0u,
0x0c05aea2u,0x0c05aea4u,0x0c05aea6u,0x0c05aea8u,0x0c05aeaau,0x0c05aeacu,0x0c05aeaeu,0x0c05aeb0u,0x0c05aeb2u,0x0c05aeb4u,0x0c05aeb6u,0x0c05aeb8u,0x0c05aebau,0x0c05aebcu,0x0c05aebeu,0x0c05aec0u,
0x0c05aec2u,0x0c05aec4u,0x0c05aec6u,0x0c05aec8u,0x0c05aecau,0x0c05aeccu,0x0c05aeceu,0x0c05aed0u,0x0c05aed2u,0x0c05aed4u,0x0c05aed6u,0x0c05aed8u,0x0c05aedau,0x0c05aedcu,0x0c05aedeu,0x0c05aee0u,
0x0c05aee2u,0x0c05aee4u,0x0c05aee6u,0x0c05aee8u,0x0c05aeeau,0x0c05aeecu,0x0c05aeeeu,0x0c05aef0u,0x0c05aef2u,0x0c05aef4u,0x0c05aef6u,0x0c05aef8u,0x0c05aefau,0x0c05aefcu,0x0c05aefeu,0x0c05af00u,
0x0c05af02u,0x0c05af04u,0x0c05af06u,0x0c05af08u,0x0c05af0au,0x0c05af0cu,0x0c05af0eu,0x0c05af10u,0x0c05af12u,0x0c05af14u,0x0c05af16u,0x0c05af18u,0x0c05af1au,0x0c05af1cu,0x0c05af1eu,0x0c05af20u,
0x0c05af22u,0x0c05af24u,0x0c05af26u,0x0c05af28u,0x0c07f08eu,0x0c07f090u,0x0c07f092u,0x0c07f094u,0x0c07f096u,0x0c07f098u,0x0c07f09au,0x0c07f09cu,0x0c07f09eu,0x0c07f0a0u,0x0c07f0a2u,0x0c07f0a4u,
0x0c07f0a6u,0x0c07f0a8u,0x0c07f0aau,0x0c07f0acu,0x0c07f0aeu,0x0c07f0b0u,0x0c07f0b2u,0x0c07f100u,0x0c07f102u,0x0c07f104u,0x0c07f106u,0x0c07f108u,0x0c07f10au,0x0c07f10cu,0x0c07f10eu,0x0c07f110u,
0x0c07f112u,0x0c07f114u,0x0c07f116u,0x0c07f118u,0x0c07f11au,0x0c07f11cu,0x0c07f11eu,0x0c07f120u,0x0c07f122u,0x0c07f124u,0x0c080796u,0x0c080798u,0x0c08079au,0x0c08079cu,0x0c08079eu,0x0c0807a0u,
0x0c0807a2u,0x0c0807a4u,0x0c0807a6u,0x0c0807a8u,0x0c0807aau,0x0c0807acu,0x0c0807aeu,0x0c0807b0u,0x0c0807b2u,0x0c0807b4u,0x0c0807b6u,0x0c0807b8u,0x0c0807bau,0x0c0807bcu,0x0c0807beu,0x0c0807c0u,
0x0c0807c2u,0x0c0807c4u,0x0c0807c6u,0x0c0807c8u,0x0c0807cau,0x0c0807ccu,0x0c0a1fd2u,0x0c0a1fd4u,0x0c0a1fd6u,0x0c0a1fd8u,0x0c0a1fdau,0x0c0a1fdcu,0x0c0a1fdeu,0x0c0a1fe0u,0x0c0a1fe2u,0x0c0a1fe4u,
0x0c0a1fe6u,0x0c0a1fe8u,0x0c0a1feau,0x0c0a1fecu,0x0c0a1feeu,0x0c0a1ff0u,0x0c0a1ff2u,0x0c0a1ff4u,0x0c0a65d4u,0x0c0a65d6u,0x0c0a65d8u,0x0c0a65dau,0x0c0a65dcu,0x0c0a65deu,0x0c0a65e0u,0x0c0a65e2u,
0x0c0a65e4u,0x0c0a65e6u,0x0c0a65e8u,0x0c0a65eau,0x0c0a65ecu,0x0c0a65eeu,0x0c0a65f0u,0x0c0a65f2u,0x0c0a65f4u,0x0c0a65f6u,0x0c0a65f8u,0x0c0a65fau,0x0c0a65fcu,0x0c0a65feu,0x0c0a6600u,0x0c0a6602u,
0x0c0a6604u,0x0c0a6606u,0x0c0a6608u,0x0c0a660au,0x0c0a660cu,
};
int vf3_target_extra_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
