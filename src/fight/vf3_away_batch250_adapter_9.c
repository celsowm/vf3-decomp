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
int vf3_away_batch250_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0475f0u: goto P_0c0475f0;
case 0x0c0475f2u: goto P_0c0475f2;
case 0x0c0475f4u: goto P_0c0475f4;
case 0x0c0475f6u: goto P_0c0475f6;
case 0x0c0475f8u: goto P_0c0475f8;
case 0x0c0475fau: goto P_0c0475fa;
case 0x0c0475fcu: goto P_0c0475fc;
case 0x0c0475feu: goto P_0c0475fe;
case 0x0c047600u: goto P_0c047600;
case 0x0c047602u: goto P_0c047602;
case 0x0c047604u: goto P_0c047604;
case 0x0c047606u: goto P_0c047606;
case 0x0c047608u: goto P_0c047608;
case 0x0c04760au: goto P_0c04760a;
case 0x0c04760cu: goto P_0c04760c;
case 0x0c04760eu: goto P_0c04760e;
case 0x0c047610u: goto P_0c047610;
case 0x0c047612u: goto P_0c047612;
case 0x0c047614u: goto P_0c047614;
case 0x0c047616u: goto P_0c047616;
case 0x0c047618u: goto P_0c047618;
case 0x0c04761au: goto P_0c04761a;
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
case 0x0c05e1b2u: goto P_0c05e1b2;
case 0x0c05e1b4u: goto P_0c05e1b4;
case 0x0c05e1b6u: goto P_0c05e1b6;
case 0x0c05e1b8u: goto P_0c05e1b8;
case 0x0c05e1bau: goto P_0c05e1ba;
case 0x0c05e1bcu: goto P_0c05e1bc;
case 0x0c05e1beu: goto P_0c05e1be;
case 0x0c05e1c0u: goto P_0c05e1c0;
case 0x0c05e3d6u: goto P_0c05e3d6;
case 0x0c05e3d8u: goto P_0c05e3d8;
case 0x0c05e3dau: goto P_0c05e3da;
case 0x0c05e3dcu: goto P_0c05e3dc;
case 0x0c05e3deu: goto P_0c05e3de;
case 0x0c05e3e0u: goto P_0c05e3e0;
case 0x0c05e3e2u: goto P_0c05e3e2;
case 0x0c05e3e4u: goto P_0c05e3e4;
case 0x0c05e3e6u: goto P_0c05e3e6;
case 0x0c05e3e8u: goto P_0c05e3e8;
case 0x0c05e3eau: goto P_0c05e3ea;
case 0x0c05e3ecu: goto P_0c05e3ec;
case 0x0c05e3eeu: goto P_0c05e3ee;
case 0x0c05e3f0u: goto P_0c05e3f0;
case 0x0c05e3f2u: goto P_0c05e3f2;
case 0x0c05e3f4u: goto P_0c05e3f4;
case 0x0c05e3f6u: goto P_0c05e3f6;
case 0x0c05e3f8u: goto P_0c05e3f8;
case 0x0c05e754u: goto P_0c05e754;
case 0x0c05e756u: goto P_0c05e756;
case 0x0c05e758u: goto P_0c05e758;
case 0x0c05e75au: goto P_0c05e75a;
case 0x0c05e75cu: goto P_0c05e75c;
case 0x0c05e75eu: goto P_0c05e75e;
case 0x0c05e760u: goto P_0c05e760;
case 0x0c05e762u: goto P_0c05e762;
case 0x0c05e764u: goto P_0c05e764;
case 0x0c05e766u: goto P_0c05e766;
case 0x0c05e768u: goto P_0c05e768;
case 0x0c05e76au: goto P_0c05e76a;
case 0x0c05e76cu: goto P_0c05e76c;
case 0x0c05e76eu: goto P_0c05e76e;
case 0x0c05e770u: goto P_0c05e770;
case 0x0c05e772u: goto P_0c05e772;
case 0x0c05e774u: goto P_0c05e774;
case 0x0c05e776u: goto P_0c05e776;
case 0x0c05e778u: goto P_0c05e778;
case 0x0c05e77au: goto P_0c05e77a;
case 0x0c05e77cu: goto P_0c05e77c;
case 0x0c05e77eu: goto P_0c05e77e;
case 0x0c05e780u: goto P_0c05e780;
case 0x0c05e782u: goto P_0c05e782;
case 0x0c05e784u: goto P_0c05e784;
case 0x0c05e786u: goto P_0c05e786;
case 0x0c05e788u: goto P_0c05e788;
case 0x0c05e78au: goto P_0c05e78a;
case 0x0c05e78cu: goto P_0c05e78c;
case 0x0c05e78eu: goto P_0c05e78e;
case 0x0c05e790u: goto P_0c05e790;
case 0x0c05e792u: goto P_0c05e792;
case 0x0c05e794u: goto P_0c05e794;
case 0x0c05e94eu: goto P_0c05e94e;
case 0x0c05e950u: goto P_0c05e950;
case 0x0c05e952u: goto P_0c05e952;
case 0x0c05e954u: goto P_0c05e954;
case 0x0c05e956u: goto P_0c05e956;
case 0x0c05e958u: goto P_0c05e958;
case 0x0c05e95au: goto P_0c05e95a;
case 0x0c05e95cu: goto P_0c05e95c;
case 0x0c05e95eu: goto P_0c05e95e;
case 0x0c05e960u: goto P_0c05e960;
case 0x0c05e962u: goto P_0c05e962;
case 0x0c05e964u: goto P_0c05e964;
case 0x0c05e966u: goto P_0c05e966;
case 0x0c05e968u: goto P_0c05e968;
case 0x0c05e96au: goto P_0c05e96a;
case 0x0c05e96cu: goto P_0c05e96c;
case 0x0c05e96eu: goto P_0c05e96e;
case 0x0c05e970u: goto P_0c05e970;
case 0x0c05e972u: goto P_0c05e972;
case 0x0c05e974u: goto P_0c05e974;
case 0x0c05e976u: goto P_0c05e976;
case 0x0c05e978u: goto P_0c05e978;
case 0x0c05e97au: goto P_0c05e97a;
case 0x0c05e97cu: goto P_0c05e97c;
case 0x0c05e97eu: goto P_0c05e97e;
case 0x0c05e980u: goto P_0c05e980;
case 0x0c05e982u: goto P_0c05e982;
case 0x0c05e984u: goto P_0c05e984;
case 0x0c05e986u: goto P_0c05e986;
case 0x0c05e988u: goto P_0c05e988;
case 0x0c05e98au: goto P_0c05e98a;
case 0x0c05e98cu: goto P_0c05e98c;
case 0x0c05e98eu: goto P_0c05e98e;
case 0x0c05e990u: goto P_0c05e990;
case 0x0c05e992u: goto P_0c05e992;
case 0x0c05e994u: goto P_0c05e994;
case 0x0c05e996u: goto P_0c05e996;
case 0x0c05e998u: goto P_0c05e998;
case 0x0c05e99au: goto P_0c05e99a;
case 0x0c05e99cu: goto P_0c05e99c;
case 0x0c05e99eu: goto P_0c05e99e;
case 0x0c05e9a0u: goto P_0c05e9a0;
case 0x0c05e9a2u: goto P_0c05e9a2;
case 0x0c05e9a4u: goto P_0c05e9a4;
case 0x0c05e9a6u: goto P_0c05e9a6;
case 0x0c05e9a8u: goto P_0c05e9a8;
case 0x0c05e9aau: goto P_0c05e9aa;
case 0x0c05e9acu: goto P_0c05e9ac;
case 0x0c05e9aeu: goto P_0c05e9ae;
case 0x0c05e9b0u: goto P_0c05e9b0;
case 0x0c05e9b2u: goto P_0c05e9b2;
case 0x0c05ece2u: goto P_0c05ece2;
case 0x0c05ece4u: goto P_0c05ece4;
case 0x0c05ece6u: goto P_0c05ece6;
case 0x0c05ece8u: goto P_0c05ece8;
case 0x0c05eceau: goto P_0c05ecea;
case 0x0c05ececu: goto P_0c05ecec;
case 0x0c05eceeu: goto P_0c05ecee;
case 0x0c05ecf0u: goto P_0c05ecf0;
case 0x0c05ecf2u: goto P_0c05ecf2;
case 0x0c05ecf4u: goto P_0c05ecf4;
case 0x0c05ecf6u: goto P_0c05ecf6;
case 0x0c05ecf8u: goto P_0c05ecf8;
case 0x0c05ecfau: goto P_0c05ecfa;
case 0x0c05ecfcu: goto P_0c05ecfc;
case 0x0c05ecfeu: goto P_0c05ecfe;
case 0x0c05ed00u: goto P_0c05ed00;
case 0x0c05ed02u: goto P_0c05ed02;
case 0x0c05ed04u: goto P_0c05ed04;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0475f0: /* original c401, guest PC 0x0c0475f0 */
if(!s->budget--) { s->failed_pc=0x0c0475f0u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,s->gbr+1,1);
goto P_0c0475f2;
P_0c0475f2: /* original d20a, guest PC 0x0c0475f2 */
if(!s->budget--) { s->failed_pc=0x0c0475f2u; return 0; }
r[2]=read(ram,0x0c04761cu,4);
goto P_0c0475f4;
P_0c0475f4: /* original 8803, guest PC 0x0c0475f4 */
if(!s->budget--) { s->failed_pc=0x0c0475f4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0475f6;
P_0c0475f6: /* original 4408, guest PC 0x0c0475f6 */
if(!s->budget--) { s->failed_pc=0x0c0475f6u; return 0; }
r[4]<<=2;
goto P_0c0475f8;
P_0c0475f8: /* original 6023, guest PC 0x0c0475f8 */
if(!s->budget--) { s->failed_pc=0x0c0475f8u; return 0; }
r[0]=r[2];
goto P_0c0475fa;
P_0c0475fa: /* original 8907, guest PC 0x0c0475fa */
if(!s->budget--) { s->failed_pc=0x0c0475fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04760c; }
goto P_0c0475fc;
P_0c0475fc: /* original 6155, guest PC 0x0c0475fc */
if(!s->budget--) { s->failed_pc=0x0c0475fcu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]+=2;
r[1]=tmp;
goto P_0c0475fe;
P_0c0475fe: /* original 4610, guest PC 0x0c0475fe */
if(!s->budget--) { s->failed_pc=0x0c0475feu; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c047600;
P_0c047600: /* original 0415, guest PC 0x0c047600 */
if(!s->budget--) { s->failed_pc=0x0c047600u; return 0; }
write(ram,r[4]+r[0],r[1],2);
goto P_0c047602;
P_0c047602: /* original 8ffb, guest PC 0x0c047602 */
if(!s->budget--) { s->failed_pc=0x0c047602u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c0475fc; }
goto P_0c047606;
P_0c047604: /* original 7404, guest PC 0x0c047604 */
if(!s->budget--) { s->failed_pc=0x0c047604u; return 0; }
r[4]+=0x00000004u;
goto P_0c047606;
P_0c047606: /* original e001, guest PC 0x0c047606 */
if(!s->budget--) { s->failed_pc=0x0c047606u; return 0; }
r[0]=0x00000001u;
goto P_0c047608;
P_0c047608: /* original 000b, guest PC 0x0c047608 */
if(!s->budget--) { s->failed_pc=0x0c047608u; return 0; }
target=r[16];
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+0,r[0],1);
s->pc=target; return ram->oob==0;
P_0c04760a: /* original c000, guest PC 0x0c04760a */
if(!s->budget--) { s->failed_pc=0x0c04760au; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+0,r[0],1);
goto P_0c04760c;
P_0c04760c: /* original 6156, guest PC 0x0c04760c */
if(!s->budget--) { s->failed_pc=0x0c04760cu; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[1]=tmp;
goto P_0c04760e;
P_0c04760e: /* original 4610, guest PC 0x0c04760e */
if(!s->budget--) { s->failed_pc=0x0c04760eu; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c047610;
P_0c047610: /* original 0416, guest PC 0x0c047610 */
if(!s->budget--) { s->failed_pc=0x0c047610u; return 0; }
write(ram,r[4]+r[0],r[1],4);
goto P_0c047612;
P_0c047612: /* original 8ffb, guest PC 0x0c047612 */
if(!s->budget--) { s->failed_pc=0x0c047612u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c04760c; }
goto P_0c047616;
P_0c047614: /* original 7404, guest PC 0x0c047614 */
if(!s->budget--) { s->failed_pc=0x0c047614u; return 0; }
r[4]+=0x00000004u;
goto P_0c047616;
P_0c047616: /* original e001, guest PC 0x0c047616 */
if(!s->budget--) { s->failed_pc=0x0c047616u; return 0; }
r[0]=0x00000001u;
goto P_0c047618;
P_0c047618: /* original 000b, guest PC 0x0c047618 */
if(!s->budget--) { s->failed_pc=0x0c047618u; return 0; }
target=r[16];
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+0,r[0],1);
s->pc=target; return ram->oob==0;
P_0c04761a: /* original c000, guest PC 0x0c04761a */
if(!s->budget--) { s->failed_pc=0x0c04761au; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+0,r[0],1);
if(!vf3_matrix_family(0x0c04761cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04761cu; return 0; } return 1;
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
P_0c05e1b2: /* original 4f22, guest PC 0x0c05e1b2 */
if(!s->budget--) { s->failed_pc=0x0c05e1b2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e1b4;
P_0c05e1b4: /* original 9461, guest PC 0x0c05e1b4 */
if(!s->budget--) { s->failed_pc=0x0c05e1b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e27au,2);
goto P_0c05e1b6;
P_0c05e1b6: /* original d339, guest PC 0x0c05e1b6 */
if(!s->budget--) { s->failed_pc=0x0c05e1b6u; return 0; }
r[3]=read(ram,0x0c05e29cu,4);
goto P_0c05e1b8;
P_0c05e1b8: /* original 430b, guest PC 0x0c05e1b8 */
if(!s->budget--) { s->failed_pc=0x0c05e1b8u; return 0; }
target=r[3];
r[16]=code_base|0x0c05e1bcu;
r[5]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e1bcu) { target=s->pc; goto dispatch; }
goto P_0c05e1bc;
P_0c05e1ba: /* original 55f1, guest PC 0x0c05e1ba */
if(!s->budget--) { s->failed_pc=0x0c05e1bau; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c05e1bc;
P_0c05e1bc: /* original 4f26, guest PC 0x0c05e1bc */
if(!s->budget--) { s->failed_pc=0x0c05e1bcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e1be;
P_0c05e1be: /* original 000b, guest PC 0x0c05e1be */
if(!s->budget--) { s->failed_pc=0x0c05e1beu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05e1c0: /* original e000, guest PC 0x0c05e1c0 */
if(!s->budget--) { s->failed_pc=0x0c05e1c0u; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c05e1c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05e1c2u; return 0; } return 1;
P_0c05e3d6: /* original 6353, guest PC 0x0c05e3d6 */
if(!s->budget--) { s->failed_pc=0x0c05e3d6u; return 0; }
r[3]=r[5];
goto P_0c05e3d8;
P_0c05e3d8: /* original d011, guest PC 0x0c05e3d8 */
if(!s->budget--) { s->failed_pc=0x0c05e3d8u; return 0; }
r[0]=read(ram,0x0c05e420u,4);
goto P_0c05e3da;
P_0c05e3da: /* original 4308, guest PC 0x0c05e3da */
if(!s->budget--) { s->failed_pc=0x0c05e3dau; return 0; }
r[3]<<=2;
goto P_0c05e3dc;
P_0c05e3dc: /* original 4f22, guest PC 0x0c05e3dc */
if(!s->budget--) { s->failed_pc=0x0c05e3dcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e3de;
P_0c05e3de: /* original 7ffc, guest PC 0x0c05e3de */
if(!s->budget--) { s->failed_pc=0x0c05e3deu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05e3e0;
P_0c05e3e0: /* original 2f52, guest PC 0x0c05e3e0 */
if(!s->budget--) { s->failed_pc=0x0c05e3e0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c05e3e2;
P_0c05e3e2: /* original 033e, guest PC 0x0c05e3e2 */
if(!s->budget--) { s->failed_pc=0x0c05e3e2u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c05e3e4;
P_0c05e3e4: /* original 430b, guest PC 0x0c05e3e4 */
if(!s->budget--) { s->failed_pc=0x0c05e3e4u; return 0; }
target=r[3];
r[16]=code_base|0x0c05e3e8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e3e8u) { target=s->pc; goto dispatch; }
goto P_0c05e3e8;
P_0c05e3e6: /* original 0009, guest PC 0x0c05e3e6 */
if(!s->budget--) { s->failed_pc=0x0c05e3e6u; return 0; }
goto P_0c05e3e8;
P_0c05e3e8: /* original d30e, guest PC 0x0c05e3e8 */
if(!s->budget--) { s->failed_pc=0x0c05e3e8u; return 0; }
r[3]=read(ram,0x0c05e424u,4);
goto P_0c05e3ea;
P_0c05e3ea: /* original d20f, guest PC 0x0c05e3ea */
if(!s->budget--) { s->failed_pc=0x0c05e3eau; return 0; }
r[2]=read(ram,0x0c05e428u,4);
goto P_0c05e3ec;
P_0c05e3ec: /* original 6132, guest PC 0x0c05e3ec */
if(!s->budget--) { s->failed_pc=0x0c05e3ecu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c05e3ee;
P_0c05e3ee: /* original 2129, guest PC 0x0c05e3ee */
if(!s->budget--) { s->failed_pc=0x0c05e3eeu; return 0; }
r[1]&=r[2];
goto P_0c05e3f0;
P_0c05e3f0: /* original 2312, guest PC 0x0c05e3f0 */
if(!s->budget--) { s->failed_pc=0x0c05e3f0u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c05e3f2;
P_0c05e3f2: /* original 7f04, guest PC 0x0c05e3f2 */
if(!s->budget--) { s->failed_pc=0x0c05e3f2u; return 0; }
r[15]+=0x00000004u;
goto P_0c05e3f4;
P_0c05e3f4: /* original 4f26, guest PC 0x0c05e3f4 */
if(!s->budget--) { s->failed_pc=0x0c05e3f4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e3f6;
P_0c05e3f6: /* original 000b, guest PC 0x0c05e3f6 */
if(!s->budget--) { s->failed_pc=0x0c05e3f6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05e3f8: /* original 0009, guest PC 0x0c05e3f8 */
if(!s->budget--) { s->failed_pc=0x0c05e3f8u; return 0; }
if(!vf3_matrix_family(0x0c05e3fau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05e3fau; return 0; } return 1;
P_0c05e754: /* original 2fe6, guest PC 0x0c05e754 */
if(!s->budget--) { s->failed_pc=0x0c05e754u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05e756;
P_0c05e756: /* original 2fd6, guest PC 0x0c05e756 */
if(!s->budget--) { s->failed_pc=0x0c05e756u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05e758;
P_0c05e758: /* original 4f22, guest PC 0x0c05e758 */
if(!s->budget--) { s->failed_pc=0x0c05e758u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e75a;
P_0c05e75a: /* original b383, guest PC 0x0c05e75a */
if(!s->budget--) { s->failed_pc=0x0c05e75au; return 0; }
target=code_base|0x0c05ee64u; r[16]=code_base|0x0c05e75eu;
r[14]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e75eu) { target=s->pc; goto dispatch; }
goto P_0c05e75e;
P_0c05e75c: /* original 6e43, guest PC 0x0c05e75c */
if(!s->budget--) { s->failed_pc=0x0c05e75cu; return 0; }
r[14]=r[4];
goto P_0c05e75e;
P_0c05e75e: /* original 6d03, guest PC 0x0c05e75e */
if(!s->budget--) { s->failed_pc=0x0c05e75eu; return 0; }
r[13]=r[0];
goto P_0c05e760;
P_0c05e760: /* original 2dd8, guest PC 0x0c05e760 */
if(!s->budget--) { s->failed_pc=0x0c05e760u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c05e762;
P_0c05e762: /* original 8b12, guest PC 0x0c05e762 */
if(!s->budget--) { s->failed_pc=0x0c05e762u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e78a; }
goto P_0c05e764;
P_0c05e764: /* original 60e2, guest PC 0x0c05e764 */
if(!s->budget--) { s->failed_pc=0x0c05e764u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05e766;
P_0c05e766: /* original 600d, guest PC 0x0c05e766 */
if(!s->budget--) { s->failed_pc=0x0c05e766u; return 0; }
r[0]=r[0]&65535u;
goto P_0c05e768;
P_0c05e768: /* original 8803, guest PC 0x0c05e768 */
if(!s->budget--) { s->failed_pc=0x0c05e768u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05e76a;
P_0c05e76a: /* original 8b04, guest PC 0x0c05e76a */
if(!s->budget--) { s->failed_pc=0x0c05e76au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e776; }
goto P_0c05e76c;
P_0c05e76c: /* original d235, guest PC 0x0c05e76c */
if(!s->budget--) { s->failed_pc=0x0c05e76cu; return 0; }
r[2]=read(ram,0x0c05e844u,4);
goto P_0c05e76e;
P_0c05e76e: /* original 420b, guest PC 0x0c05e76e */
if(!s->budget--) { s->failed_pc=0x0c05e76eu; return 0; }
target=r[2];
r[16]=code_base|0x0c05e772u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e772u) { target=s->pc; goto dispatch; }
goto P_0c05e772;
P_0c05e770: /* original 64e3, guest PC 0x0c05e770 */
if(!s->budget--) { s->failed_pc=0x0c05e770u; return 0; }
r[4]=r[14];
goto P_0c05e772;
P_0c05e772: /* original a004, guest PC 0x0c05e772 */
if(!s->budget--) { s->failed_pc=0x0c05e772u; return 0; }
goto P_0c05e77e;
P_0c05e774: /* original 0009, guest PC 0x0c05e774 */
if(!s->budget--) { s->failed_pc=0x0c05e774u; return 0; }
goto P_0c05e776;
P_0c05e776: /* original 65e3, guest PC 0x0c05e776 */
if(!s->budget--) { s->failed_pc=0x0c05e776u; return 0; }
r[5]=r[14];
goto P_0c05e778;
P_0c05e778: /* original d233, guest PC 0x0c05e778 */
if(!s->budget--) { s->failed_pc=0x0c05e778u; return 0; }
r[2]=read(ram,0x0c05e848u,4);
goto P_0c05e77a;
P_0c05e77a: /* original 420b, guest PC 0x0c05e77a */
if(!s->budget--) { s->failed_pc=0x0c05e77au; return 0; }
target=r[2];
r[16]=code_base|0x0c05e77eu;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e77eu) { target=s->pc; goto dispatch; }
goto P_0c05e77e;
P_0c05e77c: /* original 54e5, guest PC 0x0c05e77c */
if(!s->budget--) { s->failed_pc=0x0c05e77cu; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c05e77e;
P_0c05e77e: /* original 8803, guest PC 0x0c05e77e */
if(!s->budget--) { s->failed_pc=0x0c05e77eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05e780;
P_0c05e780: /* original 8f03, guest PC 0x0c05e780 */
if(!s->budget--) { s->failed_pc=0x0c05e780u; return 0; }
cond=r[17]&1u;
r[13]=r[0];
if(!cond) { goto P_0c05e78a; }
goto P_0c05e784;
P_0c05e782: /* original 6d03, guest PC 0x0c05e782 */
if(!s->budget--) { s->failed_pc=0x0c05e782u; return 0; }
r[13]=r[0];
goto P_0c05e784;
P_0c05e784: /* original d231, guest PC 0x0c05e784 */
if(!s->budget--) { s->failed_pc=0x0c05e784u; return 0; }
r[2]=read(ram,0x0c05e84cu,4);
goto P_0c05e786;
P_0c05e786: /* original 420b, guest PC 0x0c05e786 */
if(!s->budget--) { s->failed_pc=0x0c05e786u; return 0; }
target=r[2];
r[16]=code_base|0x0c05e78au;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e78au) { target=s->pc; goto dispatch; }
goto P_0c05e78a;
P_0c05e788: /* original e403, guest PC 0x0c05e788 */
if(!s->budget--) { s->failed_pc=0x0c05e788u; return 0; }
r[4]=0x00000003u;
goto P_0c05e78a;
P_0c05e78a: /* original 60d3, guest PC 0x0c05e78a */
if(!s->budget--) { s->failed_pc=0x0c05e78au; return 0; }
r[0]=r[13];
goto P_0c05e78c;
P_0c05e78c: /* original 0009, guest PC 0x0c05e78c */
if(!s->budget--) { s->failed_pc=0x0c05e78cu; return 0; }
goto P_0c05e78e;
P_0c05e78e: /* original 4f26, guest PC 0x0c05e78e */
if(!s->budget--) { s->failed_pc=0x0c05e78eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e790;
P_0c05e790: /* original 6df6, guest PC 0x0c05e790 */
if(!s->budget--) { s->failed_pc=0x0c05e790u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05e792;
P_0c05e792: /* original 000b, guest PC 0x0c05e792 */
if(!s->budget--) { s->failed_pc=0x0c05e792u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05e794: /* original 6ef6, guest PC 0x0c05e794 */
if(!s->budget--) { s->failed_pc=0x0c05e794u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05e796u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05e796u; return 0; } return 1;
P_0c05e94e: /* original 2fe6, guest PC 0x0c05e94e */
if(!s->budget--) { s->failed_pc=0x0c05e94eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05e950;
P_0c05e950: /* original 4f22, guest PC 0x0c05e950 */
if(!s->budget--) { s->failed_pc=0x0c05e950u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e952;
P_0c05e952: /* original 6063, guest PC 0x0c05e952 */
if(!s->budget--) { s->failed_pc=0x0c05e952u; return 0; }
r[0]=r[6];
goto P_0c05e954;
P_0c05e954: /* original 0009, guest PC 0x0c05e954 */
if(!s->budget--) { s->failed_pc=0x0c05e954u; return 0; }
goto P_0c05e956;
P_0c05e956: /* original 8801, guest PC 0x0c05e956 */
if(!s->budget--) { s->failed_pc=0x0c05e956u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05e958;
P_0c05e958: /* original 8d04, guest PC 0x0c05e958 */
if(!s->budget--) { s->failed_pc=0x0c05e958u; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(cond) { goto P_0c05e964; }
goto P_0c05e95c;
P_0c05e95a: /* original 6e43, guest PC 0x0c05e95a */
if(!s->budget--) { s->failed_pc=0x0c05e95au; return 0; }
r[14]=r[4];
goto P_0c05e95c;
P_0c05e95c: /* original 6073, guest PC 0x0c05e95c */
if(!s->budget--) { s->failed_pc=0x0c05e95cu; return 0; }
r[0]=r[7];
goto P_0c05e95e;
P_0c05e95e: /* original 0009, guest PC 0x0c05e95e */
if(!s->budget--) { s->failed_pc=0x0c05e95eu; return 0; }
goto P_0c05e960;
P_0c05e960: /* original 8801, guest PC 0x0c05e960 */
if(!s->budget--) { s->failed_pc=0x0c05e960u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05e962;
P_0c05e962: /* original 8b03, guest PC 0x0c05e962 */
if(!s->budget--) { s->failed_pc=0x0c05e962u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e96c; }
goto P_0c05e964;
P_0c05e964: /* original 4f26, guest PC 0x0c05e964 */
if(!s->budget--) { s->failed_pc=0x0c05e964u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e966;
P_0c05e966: /* original e004, guest PC 0x0c05e966 */
if(!s->budget--) { s->failed_pc=0x0c05e966u; return 0; }
r[0]=0x00000004u;
goto P_0c05e968;
P_0c05e968: /* original 000b, guest PC 0x0c05e968 */
if(!s->budget--) { s->failed_pc=0x0c05e968u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05e96a: /* original 6ef6, guest PC 0x0c05e96a */
if(!s->budget--) { s->failed_pc=0x0c05e96au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c05e96c;
P_0c05e96c: /* original 60e2, guest PC 0x0c05e96c */
if(!s->budget--) { s->failed_pc=0x0c05e96cu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05e96e;
P_0c05e96e: /* original 600d, guest PC 0x0c05e96e */
if(!s->budget--) { s->failed_pc=0x0c05e96eu; return 0; }
r[0]=r[0]&65535u;
goto P_0c05e970;
P_0c05e970: /* original 8803, guest PC 0x0c05e970 */
if(!s->budget--) { s->failed_pc=0x0c05e970u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05e972;
P_0c05e972: /* original 8b05, guest PC 0x0c05e972 */
if(!s->budget--) { s->failed_pc=0x0c05e972u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e980; }
goto P_0c05e974;
P_0c05e974: /* original 57e6, guest PC 0x0c05e974 */
if(!s->budget--) { s->failed_pc=0x0c05e974u; return 0; }
r[7]=read(ram,r[14]+24,4);
goto P_0c05e976;
P_0c05e976: /* original 56e3, guest PC 0x0c05e976 */
if(!s->budget--) { s->failed_pc=0x0c05e976u; return 0; }
r[6]=read(ram,r[14]+12,4);
goto P_0c05e978;
P_0c05e978: /* original b4f3, guest PC 0x0c05e978 */
if(!s->budget--) { s->failed_pc=0x0c05e978u; return 0; }
target=code_base|0x0c05f362u; r[16]=code_base|0x0c05e97cu;
r[4]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e97cu) { target=s->pc; goto dispatch; }
goto P_0c05e97c;
P_0c05e97a: /* original 54e7, guest PC 0x0c05e97a */
if(!s->budget--) { s->failed_pc=0x0c05e97au; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c05e97c;
P_0c05e97c: /* original a016, guest PC 0x0c05e97c */
if(!s->budget--) { s->failed_pc=0x0c05e97cu; return 0; }
goto P_0c05e9ac;
P_0c05e97e: /* original 0009, guest PC 0x0c05e97e */
if(!s->budget--) { s->failed_pc=0x0c05e97eu; return 0; }
goto P_0c05e980;
P_0c05e980: /* original 54e6, guest PC 0x0c05e980 */
if(!s->budget--) { s->failed_pc=0x0c05e980u; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c05e982;
P_0c05e982: /* original e204, guest PC 0x0c05e982 */
if(!s->budget--) { s->failed_pc=0x0c05e982u; return 0; }
r[2]=0x00000004u;
goto P_0c05e984;
P_0c05e984: /* original 2248, guest PC 0x0c05e984 */
if(!s->budget--) { s->failed_pc=0x0c05e984u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c05e986;
P_0c05e986: /* original 890d, guest PC 0x0c05e986 */
if(!s->budget--) { s->failed_pc=0x0c05e986u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05e9a4; }
goto P_0c05e988;
P_0c05e988: /* original e101, guest PC 0x0c05e988 */
if(!s->budget--) { s->failed_pc=0x0c05e988u; return 0; }
r[1]=0x00000001u;
goto P_0c05e98a;
P_0c05e98a: /* original 2148, guest PC 0x0c05e98a */
if(!s->budget--) { s->failed_pc=0x0c05e98au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c05e98c;
P_0c05e98c: /* original 890a, guest PC 0x0c05e98c */
if(!s->budget--) { s->failed_pc=0x0c05e98cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05e9a4; }
goto P_0c05e98e;
P_0c05e98e: /* original e208, guest PC 0x0c05e98e */
if(!s->budget--) { s->failed_pc=0x0c05e98eu; return 0; }
r[2]=0x00000008u;
goto P_0c05e990;
P_0c05e990: /* original 2248, guest PC 0x0c05e990 */
if(!s->budget--) { s->failed_pc=0x0c05e990u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c05e992;
P_0c05e992: /* original 8b07, guest PC 0x0c05e992 */
if(!s->budget--) { s->failed_pc=0x0c05e992u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e9a4; }
goto P_0c05e994;
P_0c05e994: /* original e120, guest PC 0x0c05e994 */
if(!s->budget--) { s->failed_pc=0x0c05e994u; return 0; }
r[1]=0x00000020u;
goto P_0c05e996;
P_0c05e996: /* original 2148, guest PC 0x0c05e996 */
if(!s->budget--) { s->failed_pc=0x0c05e996u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c05e998;
P_0c05e998: /* original 8b04, guest PC 0x0c05e998 */
if(!s->budget--) { s->failed_pc=0x0c05e998u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05e9a4; }
goto P_0c05e99a;
P_0c05e99a: /* original 56e3, guest PC 0x0c05e99a */
if(!s->budget--) { s->failed_pc=0x0c05e99au; return 0; }
r[6]=read(ram,r[14]+12,4);
goto P_0c05e99c;
P_0c05e99c: /* original b4b8, guest PC 0x0c05e99c */
if(!s->budget--) { s->failed_pc=0x0c05e99cu; return 0; }
target=code_base|0x0c05f310u; r[16]=code_base|0x0c05e9a0u;
r[4]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e9a0u) { target=s->pc; goto dispatch; }
goto P_0c05e9a0;
P_0c05e99e: /* original 54e7, guest PC 0x0c05e99e */
if(!s->budget--) { s->failed_pc=0x0c05e99eu; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c05e9a0;
P_0c05e9a0: /* original a004, guest PC 0x0c05e9a0 */
if(!s->budget--) { s->failed_pc=0x0c05e9a0u; return 0; }
goto P_0c05e9ac;
P_0c05e9a2: /* original 0009, guest PC 0x0c05e9a2 */
if(!s->budget--) { s->failed_pc=0x0c05e9a2u; return 0; }
goto P_0c05e9a4;
P_0c05e9a4: /* original 56e5, guest PC 0x0c05e9a4 */
if(!s->budget--) { s->failed_pc=0x0c05e9a4u; return 0; }
r[6]=read(ram,r[14]+20,4);
goto P_0c05e9a6;
P_0c05e9a6: /* original d236, guest PC 0x0c05e9a6 */
if(!s->budget--) { s->failed_pc=0x0c05e9a6u; return 0; }
r[2]=read(ram,0x0c05ea80u,4);
goto P_0c05e9a8;
P_0c05e9a8: /* original 420b, guest PC 0x0c05e9a8 */
if(!s->budget--) { s->failed_pc=0x0c05e9a8u; return 0; }
target=r[2];
r[16]=code_base|0x0c05e9acu;
r[4]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05e9acu) { target=s->pc; goto dispatch; }
goto P_0c05e9ac;
P_0c05e9aa: /* original 54e7, guest PC 0x0c05e9aa */
if(!s->budget--) { s->failed_pc=0x0c05e9aau; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c05e9ac;
P_0c05e9ac: /* original e000, guest PC 0x0c05e9ac */
if(!s->budget--) { s->failed_pc=0x0c05e9acu; return 0; }
r[0]=0x00000000u;
goto P_0c05e9ae;
P_0c05e9ae: /* original 4f26, guest PC 0x0c05e9ae */
if(!s->budget--) { s->failed_pc=0x0c05e9aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e9b0;
P_0c05e9b0: /* original 000b, guest PC 0x0c05e9b0 */
if(!s->budget--) { s->failed_pc=0x0c05e9b0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05e9b2: /* original 6ef6, guest PC 0x0c05e9b2 */
if(!s->budget--) { s->failed_pc=0x0c05e9b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05e9b4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05e9b4u; return 0; } return 1;
P_0c05ece2: /* original 2fe6, guest PC 0x0c05ece2 */
if(!s->budget--) { s->failed_pc=0x0c05ece2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05ece4;
P_0c05ece4: /* original 4f22, guest PC 0x0c05ece4 */
if(!s->budget--) { s->failed_pc=0x0c05ece4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05ece6;
P_0c05ece6: /* original 6e43, guest PC 0x0c05ece6 */
if(!s->budget--) { s->failed_pc=0x0c05ece6u; return 0; }
r[14]=r[4];
goto P_0c05ece8;
P_0c05ece8: /* original 60e2, guest PC 0x0c05ece8 */
if(!s->budget--) { s->failed_pc=0x0c05ece8u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05ecea;
P_0c05ecea: /* original 600d, guest PC 0x0c05ecea */
if(!s->budget--) { s->failed_pc=0x0c05eceau; return 0; }
r[0]=r[0]&65535u;
goto P_0c05ecec;
P_0c05ecec: /* original 8803, guest PC 0x0c05ecec */
if(!s->budget--) { s->failed_pc=0x0c05ececu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05ecee;
P_0c05ecee: /* original 8b04, guest PC 0x0c05ecee */
if(!s->budget--) { s->failed_pc=0x0c05eceeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05ecfa; }
goto P_0c05ecf0;
P_0c05ecf0: /* original d20f, guest PC 0x0c05ecf0 */
if(!s->budget--) { s->failed_pc=0x0c05ecf0u; return 0; }
r[2]=read(ram,0x0c05ed30u,4);
goto P_0c05ecf2;
P_0c05ecf2: /* original 420b, guest PC 0x0c05ecf2 */
if(!s->budget--) { s->failed_pc=0x0c05ecf2u; return 0; }
target=r[2];
r[16]=code_base|0x0c05ecf6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05ecf6u) { target=s->pc; goto dispatch; }
goto P_0c05ecf6;
P_0c05ecf4: /* original 64e3, guest PC 0x0c05ecf4 */
if(!s->budget--) { s->failed_pc=0x0c05ecf4u; return 0; }
r[4]=r[14];
goto P_0c05ecf6;
P_0c05ecf6: /* original a003, guest PC 0x0c05ecf6 */
if(!s->budget--) { s->failed_pc=0x0c05ecf6u; return 0; }
goto P_0c05ed00;
P_0c05ecf8: /* original 0009, guest PC 0x0c05ecf8 */
if(!s->budget--) { s->failed_pc=0x0c05ecf8u; return 0; }
goto P_0c05ecfa;
P_0c05ecfa: /* original d20e, guest PC 0x0c05ecfa */
if(!s->budget--) { s->failed_pc=0x0c05ecfau; return 0; }
r[2]=read(ram,0x0c05ed34u,4);
goto P_0c05ecfc;
P_0c05ecfc: /* original 420b, guest PC 0x0c05ecfc */
if(!s->budget--) { s->failed_pc=0x0c05ecfcu; return 0; }
target=r[2];
r[16]=code_base|0x0c05ed00u;
r[4]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05ed00u) { target=s->pc; goto dispatch; }
goto P_0c05ed00;
P_0c05ecfe: /* original 54e7, guest PC 0x0c05ecfe */
if(!s->budget--) { s->failed_pc=0x0c05ecfeu; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c05ed00;
P_0c05ed00: /* original 4f26, guest PC 0x0c05ed00 */
if(!s->budget--) { s->failed_pc=0x0c05ed00u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05ed02;
P_0c05ed02: /* original 000b, guest PC 0x0c05ed02 */
if(!s->budget--) { s->failed_pc=0x0c05ed02u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05ed04: /* original 6ef6, guest PC 0x0c05ed04 */
if(!s->budget--) { s->failed_pc=0x0c05ed04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05ed06u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05ed06u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
