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
int vf3_motion_group_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c094e8cu: goto P_0c094e8c;
case 0x0c094e8eu: goto P_0c094e8e;
case 0x0c094e90u: goto P_0c094e90;
case 0x0c094e92u: goto P_0c094e92;
case 0x0c094e94u: goto P_0c094e94;
case 0x0c094e96u: goto P_0c094e96;
case 0x0c094eb0u: goto P_0c094eb0;
case 0x0c094eb2u: goto P_0c094eb2;
case 0x0c094eb4u: goto P_0c094eb4;
case 0x0c094eb6u: goto P_0c094eb6;
case 0x0c094eb8u: goto P_0c094eb8;
case 0x0c094ebau: goto P_0c094eba;
case 0x0c094ebcu: goto P_0c094ebc;
case 0x0c094ebeu: goto P_0c094ebe;
case 0x0c094ec0u: goto P_0c094ec0;
case 0x0c094ec2u: goto P_0c094ec2;
case 0x0c094ec4u: goto P_0c094ec4;
case 0x0c094ec6u: goto P_0c094ec6;
case 0x0c094ec8u: goto P_0c094ec8;
case 0x0c094ecau: goto P_0c094eca;
case 0x0c094eccu: goto P_0c094ecc;
case 0x0c094eceu: goto P_0c094ece;
case 0x0c094ed0u: goto P_0c094ed0;
case 0x0c094ed2u: goto P_0c094ed2;
case 0x0c094ed4u: goto P_0c094ed4;
case 0x0c094ed6u: goto P_0c094ed6;
case 0x0c094ed8u: goto P_0c094ed8;
case 0x0c094edau: goto P_0c094eda;
case 0x0c094edcu: goto P_0c094edc;
case 0x0c094edeu: goto P_0c094ede;
case 0x0c094ee0u: goto P_0c094ee0;
case 0x0c094ee2u: goto P_0c094ee2;
case 0x0c094ee4u: goto P_0c094ee4;
case 0x0c094ee6u: goto P_0c094ee6;
case 0x0c094ee8u: goto P_0c094ee8;
case 0x0c094eeau: goto P_0c094eea;
case 0x0c094eecu: goto P_0c094eec;
case 0x0c094eeeu: goto P_0c094eee;
case 0x0c094ef0u: goto P_0c094ef0;
case 0x0c094ef2u: goto P_0c094ef2;
case 0x0c094ef4u: goto P_0c094ef4;
case 0x0c094ef6u: goto P_0c094ef6;
case 0x0c094ef8u: goto P_0c094ef8;
case 0x0c094efau: goto P_0c094efa;
case 0x0c094efcu: goto P_0c094efc;
case 0x0c094efeu: goto P_0c094efe;
case 0x0c094f00u: goto P_0c094f00;
case 0x0c094f02u: goto P_0c094f02;
case 0x0c094f04u: goto P_0c094f04;
case 0x0c094f06u: goto P_0c094f06;
case 0x0c094f08u: goto P_0c094f08;
case 0x0c094f0au: goto P_0c094f0a;
case 0x0c094f0cu: goto P_0c094f0c;
case 0x0c094f0eu: goto P_0c094f0e;
case 0x0c094f10u: goto P_0c094f10;
case 0x0c094f12u: goto P_0c094f12;
case 0x0c094f14u: goto P_0c094f14;
case 0x0c094f16u: goto P_0c094f16;
case 0x0c094f18u: goto P_0c094f18;
case 0x0c094f1au: goto P_0c094f1a;
case 0x0c094f1cu: goto P_0c094f1c;
case 0x0c094f1eu: goto P_0c094f1e;
case 0x0c094f20u: goto P_0c094f20;
case 0x0c094f22u: goto P_0c094f22;
case 0x0c094f24u: goto P_0c094f24;
case 0x0c094f26u: goto P_0c094f26;
case 0x0c094f28u: goto P_0c094f28;
case 0x0c094f2au: goto P_0c094f2a;
case 0x0c094f2cu: goto P_0c094f2c;
case 0x0c094f2eu: goto P_0c094f2e;
case 0x0c094f30u: goto P_0c094f30;
case 0x0c094f32u: goto P_0c094f32;
case 0x0c094f34u: goto P_0c094f34;
case 0x0c094f36u: goto P_0c094f36;
case 0x0c094f38u: goto P_0c094f38;
case 0x0c094f3au: goto P_0c094f3a;
case 0x0c094f3cu: goto P_0c094f3c;
case 0x0c094f3eu: goto P_0c094f3e;
case 0x0c094f40u: goto P_0c094f40;
case 0x0c094f42u: goto P_0c094f42;
case 0x0c094f44u: goto P_0c094f44;
case 0x0c094f46u: goto P_0c094f46;
case 0x0c094f48u: goto P_0c094f48;
case 0x0c094f4au: goto P_0c094f4a;
case 0x0c094f4cu: goto P_0c094f4c;
case 0x0c094f4eu: goto P_0c094f4e;
case 0x0c094f50u: goto P_0c094f50;
case 0x0c094f52u: goto P_0c094f52;
case 0x0c094f54u: goto P_0c094f54;
case 0x0c094f56u: goto P_0c094f56;
case 0x0c094f58u: goto P_0c094f58;
case 0x0c094f5au: goto P_0c094f5a;
case 0x0c094f5cu: goto P_0c094f5c;
case 0x0c094f5eu: goto P_0c094f5e;
case 0x0c094f60u: goto P_0c094f60;
case 0x0c094f62u: goto P_0c094f62;
case 0x0c094f64u: goto P_0c094f64;
case 0x0c094f66u: goto P_0c094f66;
case 0x0c094f68u: goto P_0c094f68;
case 0x0c094f6au: goto P_0c094f6a;
case 0x0c094f6cu: goto P_0c094f6c;
case 0x0c094f6eu: goto P_0c094f6e;
case 0x0c094f70u: goto P_0c094f70;
case 0x0c094f72u: goto P_0c094f72;
case 0x0c094f74u: goto P_0c094f74;
case 0x0c094f76u: goto P_0c094f76;
case 0x0c094f78u: goto P_0c094f78;
case 0x0c094f7au: goto P_0c094f7a;
case 0x0c094f7cu: goto P_0c094f7c;
case 0x0c094fc0u: goto P_0c094fc0;
case 0x0c094fc2u: goto P_0c094fc2;
case 0x0c094fc4u: goto P_0c094fc4;
case 0x0c094fc6u: goto P_0c094fc6;
case 0x0c094fc8u: goto P_0c094fc8;
case 0x0c094fcau: goto P_0c094fca;
case 0x0c094fccu: goto P_0c094fcc;
case 0x0c094fceu: goto P_0c094fce;
case 0x0c094fd0u: goto P_0c094fd0;
case 0x0c094fd2u: goto P_0c094fd2;
case 0x0c094fd4u: goto P_0c094fd4;
case 0x0c094fd6u: goto P_0c094fd6;
case 0x0c094fd8u: goto P_0c094fd8;
case 0x0c094fdau: goto P_0c094fda;
case 0x0c094fdcu: goto P_0c094fdc;
case 0x0c094fdeu: goto P_0c094fde;
case 0x0c094fe0u: goto P_0c094fe0;
case 0x0c094fe2u: goto P_0c094fe2;
case 0x0c094fe4u: goto P_0c094fe4;
case 0x0c094fe6u: goto P_0c094fe6;
case 0x0c094fe8u: goto P_0c094fe8;
case 0x0c094feau: goto P_0c094fea;
case 0x0c094fecu: goto P_0c094fec;
case 0x0c094feeu: goto P_0c094fee;
case 0x0c094ff0u: goto P_0c094ff0;
case 0x0c094ff2u: goto P_0c094ff2;
case 0x0c094ff4u: goto P_0c094ff4;
case 0x0c094ff6u: goto P_0c094ff6;
case 0x0c094ff8u: goto P_0c094ff8;
case 0x0c094ffau: goto P_0c094ffa;
case 0x0c094ffcu: goto P_0c094ffc;
case 0x0c094ffeu: goto P_0c094ffe;
case 0x0c095000u: goto P_0c095000;
case 0x0c095002u: goto P_0c095002;
case 0x0c095004u: goto P_0c095004;
case 0x0c095006u: goto P_0c095006;
case 0x0c095008u: goto P_0c095008;
case 0x0c09500au: goto P_0c09500a;
case 0x0c09500cu: goto P_0c09500c;
case 0x0c09500eu: goto P_0c09500e;
case 0x0c095010u: goto P_0c095010;
case 0x0c095012u: goto P_0c095012;
case 0x0c095014u: goto P_0c095014;
case 0x0c095016u: goto P_0c095016;
case 0x0c095018u: goto P_0c095018;
case 0x0c09501au: goto P_0c09501a;
case 0x0c09501cu: goto P_0c09501c;
case 0x0c09501eu: goto P_0c09501e;
case 0x0c095020u: goto P_0c095020;
case 0x0c095022u: goto P_0c095022;
case 0x0c095024u: goto P_0c095024;
case 0x0c095026u: goto P_0c095026;
case 0x0c095028u: goto P_0c095028;
case 0x0c09502au: goto P_0c09502a;
case 0x0c09502cu: goto P_0c09502c;
case 0x0c09502eu: goto P_0c09502e;
case 0x0c095030u: goto P_0c095030;
case 0x0c095032u: goto P_0c095032;
case 0x0c095034u: goto P_0c095034;
case 0x0c095036u: goto P_0c095036;
case 0x0c095038u: goto P_0c095038;
case 0x0c09503au: goto P_0c09503a;
case 0x0c09503cu: goto P_0c09503c;
case 0x0c09503eu: goto P_0c09503e;
case 0x0c095040u: goto P_0c095040;
case 0x0c095042u: goto P_0c095042;
case 0x0c095044u: goto P_0c095044;
case 0x0c095046u: goto P_0c095046;
case 0x0c095048u: goto P_0c095048;
case 0x0c09504au: goto P_0c09504a;
case 0x0c09504cu: goto P_0c09504c;
case 0x0c09504eu: goto P_0c09504e;
case 0x0c095050u: goto P_0c095050;
case 0x0c095052u: goto P_0c095052;
case 0x0c095054u: goto P_0c095054;
case 0x0c095056u: goto P_0c095056;
case 0x0c095058u: goto P_0c095058;
case 0x0c09505au: goto P_0c09505a;
case 0x0c09505cu: goto P_0c09505c;
case 0x0c09505eu: goto P_0c09505e;
case 0x0c095060u: goto P_0c095060;
case 0x0c095062u: goto P_0c095062;
case 0x0c095064u: goto P_0c095064;
case 0x0c095066u: goto P_0c095066;
case 0x0c095068u: goto P_0c095068;
case 0x0c09506au: goto P_0c09506a;
case 0x0c09506cu: goto P_0c09506c;
case 0x0c09506eu: goto P_0c09506e;
case 0x0c095070u: goto P_0c095070;
case 0x0c095072u: goto P_0c095072;
case 0x0c095074u: goto P_0c095074;
case 0x0c095076u: goto P_0c095076;
case 0x0c095078u: goto P_0c095078;
case 0x0c09507au: goto P_0c09507a;
case 0x0c09507cu: goto P_0c09507c;
case 0x0c09507eu: goto P_0c09507e;
case 0x0c095080u: goto P_0c095080;
case 0x0c095082u: goto P_0c095082;
case 0x0c095084u: goto P_0c095084;
case 0x0c095086u: goto P_0c095086;
case 0x0c095088u: goto P_0c095088;
case 0x0c09508au: goto P_0c09508a;
case 0x0c09508cu: goto P_0c09508c;
case 0x0c09508eu: goto P_0c09508e;
case 0x0c095090u: goto P_0c095090;
case 0x0c095092u: goto P_0c095092;
case 0x0c095094u: goto P_0c095094;
case 0x0c095096u: goto P_0c095096;
case 0x0c095098u: goto P_0c095098;
case 0x0c09509au: goto P_0c09509a;
case 0x0c09509cu: goto P_0c09509c;
case 0x0c09509eu: goto P_0c09509e;
case 0x0c0950a0u: goto P_0c0950a0;
case 0x0c0950a2u: goto P_0c0950a2;
case 0x0c0950a4u: goto P_0c0950a4;
case 0x0c0950a6u: goto P_0c0950a6;
case 0x0c0950a8u: goto P_0c0950a8;
case 0x0c0950aau: goto P_0c0950aa;
case 0x0c0950acu: goto P_0c0950ac;
case 0x0c0950aeu: goto P_0c0950ae;
case 0x0c0950b0u: goto P_0c0950b0;
case 0x0c0950b2u: goto P_0c0950b2;
case 0x0c0950b4u: goto P_0c0950b4;
case 0x0c0950b6u: goto P_0c0950b6;
case 0x0c0950b8u: goto P_0c0950b8;
case 0x0c0950bau: goto P_0c0950ba;
case 0x0c0950bcu: goto P_0c0950bc;
case 0x0c0950beu: goto P_0c0950be;
case 0x0c0950c0u: goto P_0c0950c0;
case 0x0c0950c2u: goto P_0c0950c2;
case 0x0c0950c4u: goto P_0c0950c4;
case 0x0c0950c6u: goto P_0c0950c6;
case 0x0c0950c8u: goto P_0c0950c8;
case 0x0c0950cau: goto P_0c0950ca;
case 0x0c0950ccu: goto P_0c0950cc;
case 0x0c0950ceu: goto P_0c0950ce;
case 0x0c0950d0u: goto P_0c0950d0;
case 0x0c0950d2u: goto P_0c0950d2;
case 0x0c0950d4u: goto P_0c0950d4;
case 0x0c0950d6u: goto P_0c0950d6;
case 0x0c0950d8u: goto P_0c0950d8;
case 0x0c0950dau: goto P_0c0950da;
case 0x0c0950dcu: goto P_0c0950dc;
case 0x0c0950deu: goto P_0c0950de;
case 0x0c0950e0u: goto P_0c0950e0;
case 0x0c0950e2u: goto P_0c0950e2;
case 0x0c0950e4u: goto P_0c0950e4;
case 0x0c0950e6u: goto P_0c0950e6;
case 0x0c0950e8u: goto P_0c0950e8;
case 0x0c0950eau: goto P_0c0950ea;
case 0x0c0950ecu: goto P_0c0950ec;
case 0x0c0950eeu: goto P_0c0950ee;
case 0x0c0950f0u: goto P_0c0950f0;
case 0x0c0950f2u: goto P_0c0950f2;
case 0x0c0950f4u: goto P_0c0950f4;
case 0x0c0950f6u: goto P_0c0950f6;
case 0x0c0950f8u: goto P_0c0950f8;
case 0x0c0950fau: goto P_0c0950fa;
case 0x0c0950fcu: goto P_0c0950fc;
case 0x0c0950feu: goto P_0c0950fe;
case 0x0c095100u: goto P_0c095100;
case 0x0c095102u: goto P_0c095102;
case 0x0c095104u: goto P_0c095104;
case 0x0c095106u: goto P_0c095106;
case 0x0c095108u: goto P_0c095108;
case 0x0c09510au: goto P_0c09510a;
case 0x0c09510cu: goto P_0c09510c;
case 0x0c09510eu: goto P_0c09510e;
case 0x0c095110u: goto P_0c095110;
case 0x0c095112u: goto P_0c095112;
case 0x0c095114u: goto P_0c095114;
default: return vf3_matrix_family(target,s,ram);
}
P_0c094e8c: /* original 4f22, guest PC 0x0c094e8c */
if(!s->budget--) { s->failed_pc=0x0c094e8cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c094e8e;
P_0c094e8e: /* original d507, guest PC 0x0c094e8e */
if(!s->budget--) { s->failed_pc=0x0c094e8eu; return 0; }
r[5]=read(ram,0x0c094eacu,4);
goto P_0c094e90;
P_0c094e90: /* original 2008, guest PC 0x0c094e90 */
if(!s->budget--) { s->failed_pc=0x0c094e90u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c094e92;
P_0c094e92: /* original 8b0d, guest PC 0x0c094e92 */
if(!s->budget--) { s->failed_pc=0x0c094e92u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094eb0; }
goto P_0c094e94;
P_0c094e94: /* original a00d, guest PC 0x0c094e94 */
if(!s->budget--) { s->failed_pc=0x0c094e94u; return 0; }
r[10]=read(ram,r[5]+16,4);
goto P_0c094eb2;
P_0c094e96: /* original 5a54, guest PC 0x0c094e96 */
if(!s->budget--) { s->failed_pc=0x0c094e96u; return 0; }
r[10]=read(ram,r[5]+16,4);
return vf3_matrix_family(0x0c094e98u,s,ram);
P_0c094eb0: /* original 5a55, guest PC 0x0c094eb0 */
if(!s->budget--) { s->failed_pc=0x0c094eb0u; return 0; }
r[10]=read(ram,r[5]+20,4);
goto P_0c094eb2;
P_0c094eb2: /* original 9064, guest PC 0x0c094eb2 */
if(!s->budget--) { s->failed_pc=0x0c094eb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094f7eu,2);
goto P_0c094eb4;
P_0c094eb4: /* original e501, guest PC 0x0c094eb4 */
if(!s->budget--) { s->failed_pc=0x0c094eb4u; return 0; }
r[5]=0x00000001u;
goto P_0c094eb6;
P_0c094eb6: /* original 04a6, guest PC 0x0c094eb6 */
if(!s->budget--) { s->failed_pc=0x0c094eb6u; return 0; }
write(ram,r[4]+r[0],r[10],4);
goto P_0c094eb8;
P_0c094eb8: /* original 70fa, guest PC 0x0c094eb8 */
if(!s->budget--) { s->failed_pc=0x0c094eb8u; return 0; }
r[0]+=0xfffffffau;
goto P_0c094eba;
P_0c094eba: /* original 0454, guest PC 0x0c094eba */
if(!s->budget--) { s->failed_pc=0x0c094ebau; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c094ebc;
P_0c094ebc: /* original e022, guest PC 0x0c094ebc */
if(!s->budget--) { s->failed_pc=0x0c094ebcu; return 0; }
r[0]=0x00000022u;
goto P_0c094ebe;
P_0c094ebe: /* original 5345, guest PC 0x0c094ebe */
if(!s->budget--) { s->failed_pc=0x0c094ebeu; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c094ec0;
P_0c094ec0: /* original 0435, guest PC 0x0c094ec0 */
if(!s->budget--) { s->failed_pc=0x0c094ec0u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c094ec2;
P_0c094ec2: /* original 707e, guest PC 0x0c094ec2 */
if(!s->budget--) { s->failed_pc=0x0c094ec2u; return 0; }
r[0]+=0x0000007eu;
goto P_0c094ec4;
P_0c094ec4: /* original 0da6, guest PC 0x0c094ec4 */
if(!s->budget--) { s->failed_pc=0x0c094ec4u; return 0; }
write(ram,r[13]+r[0],r[10],4);
goto P_0c094ec6;
P_0c094ec6: /* original 70fa, guest PC 0x0c094ec6 */
if(!s->budget--) { s->failed_pc=0x0c094ec6u; return 0; }
r[0]+=0xfffffffau;
goto P_0c094ec8;
P_0c094ec8: /* original 0d54, guest PC 0x0c094ec8 */
if(!s->budget--) { s->failed_pc=0x0c094ec8u; return 0; }
write(ram,r[13]+r[0],r[5],1);
goto P_0c094eca;
P_0c094eca: /* original e022, guest PC 0x0c094eca */
if(!s->budget--) { s->failed_pc=0x0c094ecau; return 0; }
r[0]=0x00000022u;
goto P_0c094ecc;
P_0c094ecc: /* original 5345, guest PC 0x0c094ecc */
if(!s->budget--) { s->failed_pc=0x0c094eccu; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c094ece;
P_0c094ece: /* original 0d35, guest PC 0x0c094ece */
if(!s->budget--) { s->failed_pc=0x0c094eceu; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c094ed0;
P_0c094ed0: /* original 707e, guest PC 0x0c094ed0 */
if(!s->budget--) { s->failed_pc=0x0c094ed0u; return 0; }
r[0]+=0x0000007eu;
goto P_0c094ed2;
P_0c094ed2: /* original 0ca6, guest PC 0x0c094ed2 */
if(!s->budget--) { s->failed_pc=0x0c094ed2u; return 0; }
write(ram,r[12]+r[0],r[10],4);
goto P_0c094ed4;
P_0c094ed4: /* original 70fa, guest PC 0x0c094ed4 */
if(!s->budget--) { s->failed_pc=0x0c094ed4u; return 0; }
r[0]+=0xfffffffau;
goto P_0c094ed6;
P_0c094ed6: /* original 0c54, guest PC 0x0c094ed6 */
if(!s->budget--) { s->failed_pc=0x0c094ed6u; return 0; }
write(ram,r[12]+r[0],r[5],1);
goto P_0c094ed8;
P_0c094ed8: /* original e022, guest PC 0x0c094ed8 */
if(!s->budget--) { s->failed_pc=0x0c094ed8u; return 0; }
r[0]=0x00000022u;
goto P_0c094eda;
P_0c094eda: /* original 5345, guest PC 0x0c094eda */
if(!s->budget--) { s->failed_pc=0x0c094edau; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c094edc;
P_0c094edc: /* original 0c35, guest PC 0x0c094edc */
if(!s->budget--) { s->failed_pc=0x0c094edcu; return 0; }
write(ram,r[12]+r[0],r[3],2);
goto P_0c094ede;
P_0c094ede: /* original 707e, guest PC 0x0c094ede */
if(!s->budget--) { s->failed_pc=0x0c094edeu; return 0; }
r[0]+=0x0000007eu;
goto P_0c094ee0;
P_0c094ee0: /* original 0ea6, guest PC 0x0c094ee0 */
if(!s->budget--) { s->failed_pc=0x0c094ee0u; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c094ee2;
P_0c094ee2: /* original 70fa, guest PC 0x0c094ee2 */
if(!s->budget--) { s->failed_pc=0x0c094ee2u; return 0; }
r[0]+=0xfffffffau;
goto P_0c094ee4;
P_0c094ee4: /* original 0e54, guest PC 0x0c094ee4 */
if(!s->budget--) { s->failed_pc=0x0c094ee4u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c094ee6;
P_0c094ee6: /* original e022, guest PC 0x0c094ee6 */
if(!s->budget--) { s->failed_pc=0x0c094ee6u; return 0; }
r[0]=0x00000022u;
goto P_0c094ee8;
P_0c094ee8: /* original 5345, guest PC 0x0c094ee8 */
if(!s->budget--) { s->failed_pc=0x0c094ee8u; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c094eea;
P_0c094eea: /* original 0e35, guest PC 0x0c094eea */
if(!s->budget--) { s->failed_pc=0x0c094eeau; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c094eec;
P_0c094eec: /* original 707e, guest PC 0x0c094eec */
if(!s->budget--) { s->failed_pc=0x0c094eecu; return 0; }
r[0]+=0x0000007eu;
goto P_0c094eee;
P_0c094eee: /* original 0ba6, guest PC 0x0c094eee */
if(!s->budget--) { s->failed_pc=0x0c094eeeu; return 0; }
write(ram,r[11]+r[0],r[10],4);
goto P_0c094ef0;
P_0c094ef0: /* original 70fa, guest PC 0x0c094ef0 */
if(!s->budget--) { s->failed_pc=0x0c094ef0u; return 0; }
r[0]+=0xfffffffau;
goto P_0c094ef2;
P_0c094ef2: /* original 0b54, guest PC 0x0c094ef2 */
if(!s->budget--) { s->failed_pc=0x0c094ef2u; return 0; }
write(ram,r[11]+r[0],r[5],1);
goto P_0c094ef4;
P_0c094ef4: /* original e022, guest PC 0x0c094ef4 */
if(!s->budget--) { s->failed_pc=0x0c094ef4u; return 0; }
r[0]=0x00000022u;
goto P_0c094ef6;
P_0c094ef6: /* original 5345, guest PC 0x0c094ef6 */
if(!s->budget--) { s->failed_pc=0x0c094ef6u; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c094ef8;
P_0c094ef8: /* original e679, guest PC 0x0c094ef8 */
if(!s->budget--) { s->failed_pc=0x0c094ef8u; return 0; }
r[6]=0x00000079u;
goto P_0c094efa;
P_0c094efa: /* original 0b35, guest PC 0x0c094efa */
if(!s->budget--) { s->failed_pc=0x0c094efau; return 0; }
write(ram,r[11]+r[0],r[3],2);
goto P_0c094efc;
P_0c094efc: /* original e068, guest PC 0x0c094efc */
if(!s->budget--) { s->failed_pc=0x0c094efcu; return 0; }
r[0]=0x00000068u;
goto P_0c094efe;
P_0c094efe: /* original d221, guest PC 0x0c094efe */
if(!s->budget--) { s->failed_pc=0x0c094efeu; return 0; }
r[2]=read(ram,0x0c094f84u,4);
goto P_0c094f00;
P_0c094f00: /* original 0426, guest PC 0x0c094f00 */
if(!s->budget--) { s->failed_pc=0x0c094f00u; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c094f02;
P_0c094f02: /* original d321, guest PC 0x0c094f02 */
if(!s->budget--) { s->failed_pc=0x0c094f02u; return 0; }
r[3]=read(ram,0x0c094f88u,4);
goto P_0c094f04;
P_0c094f04: /* original 0d36, guest PC 0x0c094f04 */
if(!s->budget--) { s->failed_pc=0x0c094f04u; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c094f06;
P_0c094f06: /* original d221, guest PC 0x0c094f06 */
if(!s->budget--) { s->failed_pc=0x0c094f06u; return 0; }
r[2]=read(ram,0x0c094f8cu,4);
goto P_0c094f08;
P_0c094f08: /* original 0c26, guest PC 0x0c094f08 */
if(!s->budget--) { s->failed_pc=0x0c094f08u; return 0; }
write(ram,r[12]+r[0],r[2],4);
goto P_0c094f0a;
P_0c094f0a: /* original d321, guest PC 0x0c094f0a */
if(!s->budget--) { s->failed_pc=0x0c094f0au; return 0; }
r[3]=read(ram,0x0c094f90u,4);
goto P_0c094f0c;
P_0c094f0c: /* original 0e36, guest PC 0x0c094f0c */
if(!s->budget--) { s->failed_pc=0x0c094f0cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c094f0e;
P_0c094f0e: /* original d221, guest PC 0x0c094f0e */
if(!s->budget--) { s->failed_pc=0x0c094f0eu; return 0; }
r[2]=read(ram,0x0c094f94u,4);
goto P_0c094f10;
P_0c094f10: /* original 0b26, guest PC 0x0c094f10 */
if(!s->budget--) { s->failed_pc=0x0c094f10u; return 0; }
write(ram,r[11]+r[0],r[2],4);
goto P_0c094f12;
P_0c094f12: /* original 5045, guest PC 0x0c094f12 */
if(!s->budget--) { s->failed_pc=0x0c094f12u; return 0; }
r[0]=read(ram,r[4]+20,4);
goto P_0c094f14;
P_0c094f14: /* original 8805, guest PC 0x0c094f14 */
if(!s->budget--) { s->failed_pc=0x0c094f14u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c094f16;
P_0c094f16: /* original 8f18, guest PC 0x0c094f16 */
if(!s->budget--) { s->failed_pc=0x0c094f16u; return 0; }
cond=r[17]&1u;
r[5]=0x00000010u;
if(!cond) { goto P_0c094f4a; }
goto P_0c094f1a;
P_0c094f18: /* original e510, guest PC 0x0c094f18 */
if(!s->budget--) { s->failed_pc=0x0c094f18u; return 0; }
r[5]=0x00000010u;
goto P_0c094f1a;
P_0c094f1a: /* original d21f, guest PC 0x0c094f1a */
if(!s->budget--) { s->failed_pc=0x0c094f1au; return 0; }
r[2]=read(ram,0x0c094f98u,4);
goto P_0c094f1c;
P_0c094f1c: /* original e050, guest PC 0x0c094f1c */
if(!s->budget--) { s->failed_pc=0x0c094f1cu; return 0; }
r[0]=0x00000050u;
goto P_0c094f1e;
P_0c094f1e: /* original 0426, guest PC 0x0c094f1e */
if(!s->budget--) { s->failed_pc=0x0c094f1eu; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c094f20;
P_0c094f20: /* original d31e, guest PC 0x0c094f20 */
if(!s->budget--) { s->failed_pc=0x0c094f20u; return 0; }
r[3]=read(ram,0x0c094f9cu,4);
goto P_0c094f22;
P_0c094f22: /* original 0d36, guest PC 0x0c094f22 */
if(!s->budget--) { s->failed_pc=0x0c094f22u; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c094f24;
P_0c094f24: /* original d21e, guest PC 0x0c094f24 */
if(!s->budget--) { s->failed_pc=0x0c094f24u; return 0; }
r[2]=read(ram,0x0c094fa0u,4);
goto P_0c094f26;
P_0c094f26: /* original 0c26, guest PC 0x0c094f26 */
if(!s->budget--) { s->failed_pc=0x0c094f26u; return 0; }
write(ram,r[12]+r[0],r[2],4);
goto P_0c094f28;
P_0c094f28: /* original d31e, guest PC 0x0c094f28 */
if(!s->budget--) { s->failed_pc=0x0c094f28u; return 0; }
r[3]=read(ram,0x0c094fa4u,4);
goto P_0c094f2a;
P_0c094f2a: /* original 0e36, guest PC 0x0c094f2a */
if(!s->budget--) { s->failed_pc=0x0c094f2au; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c094f2c;
P_0c094f2c: /* original d21e, guest PC 0x0c094f2c */
if(!s->budget--) { s->failed_pc=0x0c094f2cu; return 0; }
r[2]=read(ram,0x0c094fa8u,4);
goto P_0c094f2e;
P_0c094f2e: /* original 0b26, guest PC 0x0c094f2e */
if(!s->budget--) { s->failed_pc=0x0c094f2eu; return 0; }
write(ram,r[11]+r[0],r[2],4);
goto P_0c094f30;
P_0c094f30: /* original 6063, guest PC 0x0c094f30 */
if(!s->budget--) { s->failed_pc=0x0c094f30u; return 0; }
r[0]=r[6];
goto P_0c094f32;
P_0c094f32: /* original e637, guest PC 0x0c094f32 */
if(!s->budget--) { s->failed_pc=0x0c094f32u; return 0; }
r[6]=0x00000037u;
goto P_0c094f34;
P_0c094f34: /* original 814f, guest PC 0x0c094f34 */
if(!s->budget--) { s->failed_pc=0x0c094f34u; return 0; }
write(ram,r[4]+30,r[0],2);
goto P_0c094f36;
P_0c094f36: /* original 6063, guest PC 0x0c094f36 */
if(!s->budget--) { s->failed_pc=0x0c094f36u; return 0; }
r[0]=r[6];
goto P_0c094f38;
P_0c094f38: /* original 81df, guest PC 0x0c094f38 */
if(!s->budget--) { s->failed_pc=0x0c094f38u; return 0; }
write(ram,r[13]+30,r[0],2);
goto P_0c094f3a;
P_0c094f3a: /* original 6053, guest PC 0x0c094f3a */
if(!s->budget--) { s->failed_pc=0x0c094f3au; return 0; }
r[0]=r[5];
goto P_0c094f3c;
P_0c094f3c: /* original 81cf, guest PC 0x0c094f3c */
if(!s->budget--) { s->failed_pc=0x0c094f3cu; return 0; }
write(ram,r[12]+30,r[0],2);
goto P_0c094f3e;
P_0c094f3e: /* original 6063, guest PC 0x0c094f3e */
if(!s->budget--) { s->failed_pc=0x0c094f3eu; return 0; }
r[0]=r[6];
goto P_0c094f40;
P_0c094f40: /* original 81ef, guest PC 0x0c094f40 */
if(!s->budget--) { s->failed_pc=0x0c094f40u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c094f42;
P_0c094f42: /* original 6053, guest PC 0x0c094f42 */
if(!s->budget--) { s->failed_pc=0x0c094f42u; return 0; }
r[0]=r[5];
goto P_0c094f44;
P_0c094f44: /* original 951c, guest PC 0x0c094f44 */
if(!s->budget--) { s->failed_pc=0x0c094f44u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094f80u,2);
goto P_0c094f46;
P_0c094f46: /* original a055, guest PC 0x0c094f46 */
if(!s->budget--) { s->failed_pc=0x0c094f46u; return 0; }
write(ram,r[11]+30,r[0],2);
goto P_0c094ff4;
P_0c094f48: /* original 81bf, guest PC 0x0c094f48 */
if(!s->budget--) { s->failed_pc=0x0c094f48u; return 0; }
write(ram,r[11]+30,r[0],2);
goto P_0c094f4a;
P_0c094f4a: /* original 8812, guest PC 0x0c094f4a */
if(!s->budget--) { s->failed_pc=0x0c094f4au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c094f4c;
P_0c094f4c: /* original 8b38, guest PC 0x0c094f4c */
if(!s->budget--) { s->failed_pc=0x0c094f4cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094fc0; }
goto P_0c094f4e;
P_0c094f4e: /* original d317, guest PC 0x0c094f4e */
if(!s->budget--) { s->failed_pc=0x0c094f4eu; return 0; }
r[3]=read(ram,0x0c094facu,4);
goto P_0c094f50;
P_0c094f50: /* original e050, guest PC 0x0c094f50 */
if(!s->budget--) { s->failed_pc=0x0c094f50u; return 0; }
r[0]=0x00000050u;
goto P_0c094f52;
P_0c094f52: /* original 0436, guest PC 0x0c094f52 */
if(!s->budget--) { s->failed_pc=0x0c094f52u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c094f54;
P_0c094f54: /* original d216, guest PC 0x0c094f54 */
if(!s->budget--) { s->failed_pc=0x0c094f54u; return 0; }
r[2]=read(ram,0x0c094fb0u,4);
goto P_0c094f56;
P_0c094f56: /* original 0d26, guest PC 0x0c094f56 */
if(!s->budget--) { s->failed_pc=0x0c094f56u; return 0; }
write(ram,r[13]+r[0],r[2],4);
goto P_0c094f58;
P_0c094f58: /* original d316, guest PC 0x0c094f58 */
if(!s->budget--) { s->failed_pc=0x0c094f58u; return 0; }
r[3]=read(ram,0x0c094fb4u,4);
goto P_0c094f5a;
P_0c094f5a: /* original 0c36, guest PC 0x0c094f5a */
if(!s->budget--) { s->failed_pc=0x0c094f5au; return 0; }
write(ram,r[12]+r[0],r[3],4);
goto P_0c094f5c;
P_0c094f5c: /* original d216, guest PC 0x0c094f5c */
if(!s->budget--) { s->failed_pc=0x0c094f5cu; return 0; }
r[2]=read(ram,0x0c094fb8u,4);
goto P_0c094f5e;
P_0c094f5e: /* original 0e26, guest PC 0x0c094f5e */
if(!s->budget--) { s->failed_pc=0x0c094f5eu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c094f60;
P_0c094f60: /* original d316, guest PC 0x0c094f60 */
if(!s->budget--) { s->failed_pc=0x0c094f60u; return 0; }
r[3]=read(ram,0x0c094fbcu,4);
goto P_0c094f62;
P_0c094f62: /* original 0b36, guest PC 0x0c094f62 */
if(!s->budget--) { s->failed_pc=0x0c094f62u; return 0; }
write(ram,r[11]+r[0],r[3],4);
goto P_0c094f64;
P_0c094f64: /* original 6063, guest PC 0x0c094f64 */
if(!s->budget--) { s->failed_pc=0x0c094f64u; return 0; }
r[0]=r[6];
goto P_0c094f66;
P_0c094f66: /* original e647, guest PC 0x0c094f66 */
if(!s->budget--) { s->failed_pc=0x0c094f66u; return 0; }
r[6]=0x00000047u;
goto P_0c094f68;
P_0c094f68: /* original 814f, guest PC 0x0c094f68 */
if(!s->budget--) { s->failed_pc=0x0c094f68u; return 0; }
write(ram,r[4]+30,r[0],2);
goto P_0c094f6a;
P_0c094f6a: /* original 6063, guest PC 0x0c094f6a */
if(!s->budget--) { s->failed_pc=0x0c094f6au; return 0; }
r[0]=r[6];
goto P_0c094f6c;
P_0c094f6c: /* original 81df, guest PC 0x0c094f6c */
if(!s->budget--) { s->failed_pc=0x0c094f6cu; return 0; }
write(ram,r[13]+30,r[0],2);
goto P_0c094f6e;
P_0c094f6e: /* original 6053, guest PC 0x0c094f6e */
if(!s->budget--) { s->failed_pc=0x0c094f6eu; return 0; }
r[0]=r[5];
goto P_0c094f70;
P_0c094f70: /* original 81cf, guest PC 0x0c094f70 */
if(!s->budget--) { s->failed_pc=0x0c094f70u; return 0; }
write(ram,r[12]+30,r[0],2);
goto P_0c094f72;
P_0c094f72: /* original 6063, guest PC 0x0c094f72 */
if(!s->budget--) { s->failed_pc=0x0c094f72u; return 0; }
r[0]=r[6];
goto P_0c094f74;
P_0c094f74: /* original 81ef, guest PC 0x0c094f74 */
if(!s->budget--) { s->failed_pc=0x0c094f74u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c094f76;
P_0c094f76: /* original 6053, guest PC 0x0c094f76 */
if(!s->budget--) { s->failed_pc=0x0c094f76u; return 0; }
r[0]=r[5];
goto P_0c094f78;
P_0c094f78: /* original 9503, guest PC 0x0c094f78 */
if(!s->budget--) { s->failed_pc=0x0c094f78u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094f82u,2);
goto P_0c094f7a;
P_0c094f7a: /* original a03b, guest PC 0x0c094f7a */
if(!s->budget--) { s->failed_pc=0x0c094f7au; return 0; }
write(ram,r[11]+30,r[0],2);
goto P_0c094ff4;
P_0c094f7c: /* original 81bf, guest PC 0x0c094f7c */
if(!s->budget--) { s->failed_pc=0x0c094f7cu; return 0; }
write(ram,r[11]+30,r[0],2);
return vf3_matrix_family(0x0c094f7eu,s,ram);
P_0c094fc0: /* original 5045, guest PC 0x0c094fc0 */
if(!s->budget--) { s->failed_pc=0x0c094fc0u; return 0; }
r[0]=read(ram,r[4]+20,4);
goto P_0c094fc2;
P_0c094fc2: /* original 8807, guest PC 0x0c094fc2 */
if(!s->budget--) { s->failed_pc=0x0c094fc2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c094fc4;
P_0c094fc4: /* original 8b2f, guest PC 0x0c094fc4 */
if(!s->budget--) { s->failed_pc=0x0c094fc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c095026; }
goto P_0c094fc6;
P_0c094fc6: /* original d357, guest PC 0x0c094fc6 */
if(!s->budget--) { s->failed_pc=0x0c094fc6u; return 0; }
r[3]=read(ram,0x0c095124u,4);
goto P_0c094fc8;
P_0c094fc8: /* original e050, guest PC 0x0c094fc8 */
if(!s->budget--) { s->failed_pc=0x0c094fc8u; return 0; }
r[0]=0x00000050u;
goto P_0c094fca;
P_0c094fca: /* original e63c, guest PC 0x0c094fca */
if(!s->budget--) { s->failed_pc=0x0c094fcau; return 0; }
r[6]=0x0000003cu;
goto P_0c094fcc;
P_0c094fcc: /* original 0436, guest PC 0x0c094fcc */
if(!s->budget--) { s->failed_pc=0x0c094fccu; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c094fce;
P_0c094fce: /* original d256, guest PC 0x0c094fce */
if(!s->budget--) { s->failed_pc=0x0c094fceu; return 0; }
r[2]=read(ram,0x0c095128u,4);
goto P_0c094fd0;
P_0c094fd0: /* original 0d26, guest PC 0x0c094fd0 */
if(!s->budget--) { s->failed_pc=0x0c094fd0u; return 0; }
write(ram,r[13]+r[0],r[2],4);
goto P_0c094fd2;
P_0c094fd2: /* original d356, guest PC 0x0c094fd2 */
if(!s->budget--) { s->failed_pc=0x0c094fd2u; return 0; }
r[3]=read(ram,0x0c09512cu,4);
goto P_0c094fd4;
P_0c094fd4: /* original 0c36, guest PC 0x0c094fd4 */
if(!s->budget--) { s->failed_pc=0x0c094fd4u; return 0; }
write(ram,r[12]+r[0],r[3],4);
goto P_0c094fd6;
P_0c094fd6: /* original d256, guest PC 0x0c094fd6 */
if(!s->budget--) { s->failed_pc=0x0c094fd6u; return 0; }
r[2]=read(ram,0x0c095130u,4);
goto P_0c094fd8;
P_0c094fd8: /* original 0e26, guest PC 0x0c094fd8 */
if(!s->budget--) { s->failed_pc=0x0c094fd8u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c094fda;
P_0c094fda: /* original d356, guest PC 0x0c094fda */
if(!s->budget--) { s->failed_pc=0x0c094fdau; return 0; }
r[3]=read(ram,0x0c095134u,4);
goto P_0c094fdc;
P_0c094fdc: /* original 0b36, guest PC 0x0c094fdc */
if(!s->budget--) { s->failed_pc=0x0c094fdcu; return 0; }
write(ram,r[11]+r[0],r[3],4);
goto P_0c094fde;
P_0c094fde: /* original e05c, guest PC 0x0c094fde */
if(!s->budget--) { s->failed_pc=0x0c094fdeu; return 0; }
r[0]=0x0000005cu;
goto P_0c094fe0;
P_0c094fe0: /* original 814f, guest PC 0x0c094fe0 */
if(!s->budget--) { s->failed_pc=0x0c094fe0u; return 0; }
write(ram,r[4]+30,r[0],2);
goto P_0c094fe2;
P_0c094fe2: /* original 6063, guest PC 0x0c094fe2 */
if(!s->budget--) { s->failed_pc=0x0c094fe2u; return 0; }
r[0]=r[6];
goto P_0c094fe4;
P_0c094fe4: /* original 81df, guest PC 0x0c094fe4 */
if(!s->budget--) { s->failed_pc=0x0c094fe4u; return 0; }
write(ram,r[13]+30,r[0],2);
goto P_0c094fe6;
P_0c094fe6: /* original 6053, guest PC 0x0c094fe6 */
if(!s->budget--) { s->failed_pc=0x0c094fe6u; return 0; }
r[0]=r[5];
goto P_0c094fe8;
P_0c094fe8: /* original 81cf, guest PC 0x0c094fe8 */
if(!s->budget--) { s->failed_pc=0x0c094fe8u; return 0; }
write(ram,r[12]+30,r[0],2);
goto P_0c094fea;
P_0c094fea: /* original 6063, guest PC 0x0c094fea */
if(!s->budget--) { s->failed_pc=0x0c094feau; return 0; }
r[0]=r[6];
goto P_0c094fec;
P_0c094fec: /* original 81ef, guest PC 0x0c094fec */
if(!s->budget--) { s->failed_pc=0x0c094fecu; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c094fee;
P_0c094fee: /* original 6053, guest PC 0x0c094fee */
if(!s->budget--) { s->failed_pc=0x0c094feeu; return 0; }
r[0]=r[5];
goto P_0c094ff0;
P_0c094ff0: /* original 81bf, guest PC 0x0c094ff0 */
if(!s->budget--) { s->failed_pc=0x0c094ff0u; return 0; }
write(ram,r[11]+30,r[0],2);
goto P_0c094ff2;
P_0c094ff2: /* original 9590, guest PC 0x0c094ff2 */
if(!s->budget--) { s->failed_pc=0x0c094ff2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095116u,2);
goto P_0c094ff4;
P_0c094ff4: /* original d050, guest PC 0x0c094ff4 */
if(!s->budget--) { s->failed_pc=0x0c094ff4u; return 0; }
r[0]=read(ram,0x0c095138u,4);
goto P_0c094ff6;
P_0c094ff6: /* original 6953, guest PC 0x0c094ff6 */
if(!s->budget--) { s->failed_pc=0x0c094ff6u; return 0; }
r[9]=r[5];
goto P_0c094ff8;
P_0c094ff8: /* original 4908, guest PC 0x0c094ff8 */
if(!s->budget--) { s->failed_pc=0x0c094ff8u; return 0; }
r[9]<<=2;
goto P_0c094ffa;
P_0c094ffa: /* original 099e, guest PC 0x0c094ffa */
if(!s->budget--) { s->failed_pc=0x0c094ffau; return 0; }
r[9]=read(ram,r[9]+r[0],4);
goto P_0c094ffc;
P_0c094ffc: /* original 6693, guest PC 0x0c094ffc */
if(!s->budget--) { s->failed_pc=0x0c094ffcu; return 0; }
r[6]=r[9];
goto P_0c094ffe;
P_0c094ffe: /* original b01a, guest PC 0x0c094ffe */
if(!s->budget--) { s->failed_pc=0x0c094ffeu; return 0; }
target=0x0c095036u; r[16]=0x0c095002u;
r[5]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c095002u) { target=s->pc; goto dispatch; }
goto P_0c095002;
P_0c095000: /* original 65a3, guest PC 0x0c095000 */
if(!s->budget--) { s->failed_pc=0x0c095000u; return 0; }
r[5]=r[10];
goto P_0c095002;
P_0c095002: /* original 599b, guest PC 0x0c095002 */
if(!s->budget--) { s->failed_pc=0x0c095002u; return 0; }
r[9]=read(ram,r[9]+44,4);
goto P_0c095004;
P_0c095004: /* original 65a3, guest PC 0x0c095004 */
if(!s->budget--) { s->failed_pc=0x0c095004u; return 0; }
r[5]=r[10];
goto P_0c095006;
P_0c095006: /* original 6693, guest PC 0x0c095006 */
if(!s->budget--) { s->failed_pc=0x0c095006u; return 0; }
r[6]=r[9];
goto P_0c095008;
P_0c095008: /* original b015, guest PC 0x0c095008 */
if(!s->budget--) { s->failed_pc=0x0c095008u; return 0; }
target=0x0c095036u; r[16]=0x0c09500cu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09500cu) { target=s->pc; goto dispatch; }
goto P_0c09500c;
P_0c09500a: /* original 64c3, guest PC 0x0c09500a */
if(!s->budget--) { s->failed_pc=0x0c09500au; return 0; }
r[4]=r[12];
goto P_0c09500c;
P_0c09500c: /* original 569b, guest PC 0x0c09500c */
if(!s->budget--) { s->failed_pc=0x0c09500cu; return 0; }
r[6]=read(ram,r[9]+44,4);
goto P_0c09500e;
P_0c09500e: /* original 65a3, guest PC 0x0c09500e */
if(!s->budget--) { s->failed_pc=0x0c09500eu; return 0; }
r[5]=r[10];
goto P_0c095010;
P_0c095010: /* original b011, guest PC 0x0c095010 */
if(!s->budget--) { s->failed_pc=0x0c095010u; return 0; }
target=0x0c095036u; r[16]=0x0c095014u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c095014u) { target=s->pc; goto dispatch; }
goto P_0c095014;
P_0c095012: /* original 64d3, guest PC 0x0c095012 */
if(!s->budget--) { s->failed_pc=0x0c095012u; return 0; }
r[4]=r[13];
goto P_0c095014;
P_0c095014: /* original 5d9c, guest PC 0x0c095014 */
if(!s->budget--) { s->failed_pc=0x0c095014u; return 0; }
r[13]=read(ram,r[9]+48,4);
goto P_0c095016;
P_0c095016: /* original 65a3, guest PC 0x0c095016 */
if(!s->budget--) { s->failed_pc=0x0c095016u; return 0; }
r[5]=r[10];
goto P_0c095018;
P_0c095018: /* original 66d3, guest PC 0x0c095018 */
if(!s->budget--) { s->failed_pc=0x0c095018u; return 0; }
r[6]=r[13];
goto P_0c09501a;
P_0c09501a: /* original b00c, guest PC 0x0c09501a */
if(!s->budget--) { s->failed_pc=0x0c09501au; return 0; }
target=0x0c095036u; r[16]=0x0c09501eu;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09501eu) { target=s->pc; goto dispatch; }
goto P_0c09501e;
P_0c09501c: /* original 64b3, guest PC 0x0c09501c */
if(!s->budget--) { s->failed_pc=0x0c09501cu; return 0; }
r[4]=r[11];
goto P_0c09501e;
P_0c09501e: /* original 56db, guest PC 0x0c09501e */
if(!s->budget--) { s->failed_pc=0x0c09501eu; return 0; }
r[6]=read(ram,r[13]+44,4);
goto P_0c095020;
P_0c095020: /* original 65a3, guest PC 0x0c095020 */
if(!s->budget--) { s->failed_pc=0x0c095020u; return 0; }
r[5]=r[10];
goto P_0c095022;
P_0c095022: /* original b008, guest PC 0x0c095022 */
if(!s->budget--) { s->failed_pc=0x0c095022u; return 0; }
target=0x0c095036u; r[16]=0x0c095026u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c095026u) { target=s->pc; goto dispatch; }
goto P_0c095026;
P_0c095024: /* original 64e3, guest PC 0x0c095024 */
if(!s->budget--) { s->failed_pc=0x0c095024u; return 0; }
r[4]=r[14];
goto P_0c095026;
P_0c095026: /* original 4f26, guest PC 0x0c095026 */
if(!s->budget--) { s->failed_pc=0x0c095026u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c095028;
P_0c095028: /* original 69f6, guest PC 0x0c095028 */
if(!s->budget--) { s->failed_pc=0x0c095028u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09502a;
P_0c09502a: /* original 6af6, guest PC 0x0c09502a */
if(!s->budget--) { s->failed_pc=0x0c09502au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09502c;
P_0c09502c: /* original 6bf6, guest PC 0x0c09502c */
if(!s->budget--) { s->failed_pc=0x0c09502cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09502e;
P_0c09502e: /* original 6cf6, guest PC 0x0c09502e */
if(!s->budget--) { s->failed_pc=0x0c09502eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c095030;
P_0c095030: /* original 6df6, guest PC 0x0c095030 */
if(!s->budget--) { s->failed_pc=0x0c095030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c095032;
P_0c095032: /* original 000b, guest PC 0x0c095032 */
if(!s->budget--) { s->failed_pc=0x0c095032u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c095034: /* original 6ef6, guest PC 0x0c095034 */
if(!s->budget--) { s->failed_pc=0x0c095034u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c095036;
P_0c095036: /* original 2fe6, guest PC 0x0c095036 */
if(!s->budget--) { s->failed_pc=0x0c095036u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c095038;
P_0c095038: /* original 6e43, guest PC 0x0c095038 */
if(!s->budget--) { s->failed_pc=0x0c095038u; return 0; }
r[14]=r[4];
goto P_0c09503a;
P_0c09503a: /* original e301, guest PC 0x0c09503a */
if(!s->budget--) { s->failed_pc=0x0c09503au; return 0; }
r[3]=0x00000001u;
goto P_0c09503c;
P_0c09503c: /* original 2fd6, guest PC 0x0c09503c */
if(!s->budget--) { s->failed_pc=0x0c09503cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09503e;
P_0c09503e: /* original 906b, guest PC 0x0c09503e */
if(!s->budget--) { s->failed_pc=0x0c09503eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095118u,2);
goto P_0c095040;
P_0c095040: /* original 4f22, guest PC 0x0c095040 */
if(!s->budget--) { s->failed_pc=0x0c095040u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c095042;
P_0c095042: /* original 0e36, guest PC 0x0c095042 */
if(!s->budget--) { s->failed_pc=0x0c095042u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c095044;
P_0c095044: /* original e024, guest PC 0x0c095044 */
if(!s->budget--) { s->failed_pc=0x0c095044u; return 0; }
r[0]=0x00000024u;
goto P_0c095046;
P_0c095046: /* original 54e4, guest PC 0x0c095046 */
if(!s->budget--) { s->failed_pc=0x0c095046u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c095048;
P_0c095048: /* original 6342, guest PC 0x0c095048 */
if(!s->budget--) { s->failed_pc=0x0c095048u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c09504a;
P_0c09504a: /* original 0e35, guest PC 0x0c09504a */
if(!s->budget--) { s->failed_pc=0x0c09504au; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c09504c;
P_0c09504c: /* original 63e3, guest PC 0x0c09504c */
if(!s->budget--) { s->failed_pc=0x0c09504cu; return 0; }
r[3]=r[14];
goto P_0c09504e;
P_0c09504e: /* original 5241, guest PC 0x0c09504e */
if(!s->budget--) { s->failed_pc=0x0c09504eu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c095050;
P_0c095050: /* original 7348, guest PC 0x0c095050 */
if(!s->budget--) { s->failed_pc=0x0c095050u; return 0; }
r[3]+=0x00000048u;
goto P_0c095052;
P_0c095052: /* original 1e2d, guest PC 0x0c095052 */
if(!s->budget--) { s->failed_pc=0x0c095052u; return 0; }
write(ram,r[14]+52,r[2],4);
goto P_0c095054;
P_0c095054: /* original 5242, guest PC 0x0c095054 */
if(!s->budget--) { s->failed_pc=0x0c095054u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c095056;
P_0c095056: /* original 2321, guest PC 0x0c095056 */
if(!s->budget--) { s->failed_pc=0x0c095056u; return 0; }
write(ram,r[3],r[2],2);
goto P_0c095058;
P_0c095058: /* original 905f, guest PC 0x0c095058 */
if(!s->budget--) { s->failed_pc=0x0c095058u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09511au,2);
goto P_0c09505a;
P_0c09505a: /* original 5244, guest PC 0x0c09505a */
if(!s->budget--) { s->failed_pc=0x0c09505au; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c09505c;
P_0c09505c: /* original 035c, guest PC 0x0c09505c */
if(!s->budget--) { s->failed_pc=0x0c09505cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c09505e;
P_0c09505e: /* original e500, guest PC 0x0c09505e */
if(!s->budget--) { s->failed_pc=0x0c09505eu; return 0; }
r[5]=0x00000000u;
goto P_0c095060;
P_0c095060: /* original 905c, guest PC 0x0c095060 */
if(!s->budget--) { s->failed_pc=0x0c095060u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09511cu,2);
goto P_0c095062;
P_0c095062: /* original 633c, guest PC 0x0c095062 */
if(!s->budget--) { s->failed_pc=0x0c095062u; return 0; }
r[3]=r[3]&255u;
goto P_0c095064;
P_0c095064: /* original 4308, guest PC 0x0c095064 */
if(!s->budget--) { s->failed_pc=0x0c095064u; return 0; }
r[3]<<=2;
goto P_0c095066;
P_0c095066: /* original 332c, guest PC 0x0c095066 */
if(!s->budget--) { s->failed_pc=0x0c095066u; return 0; }
r[3]+=r[2];
goto P_0c095068;
P_0c095068: /* original 0e36, guest PC 0x0c095068 */
if(!s->budget--) { s->failed_pc=0x0c095068u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09506a;
P_0c09506a: /* original 04ee, guest PC 0x0c09506a */
if(!s->budget--) { s->failed_pc=0x0c09506au; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09506c;
P_0c09506c: /* original 70e8, guest PC 0x0c09506c */
if(!s->budget--) { s->failed_pc=0x0c09506cu; return 0; }
r[0]+=0xffffffe8u;
goto P_0c09506e;
P_0c09506e: /* original 6442, guest PC 0x0c09506e */
if(!s->budget--) { s->failed_pc=0x0c09506eu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c095070;
P_0c095070: /* original 0e46, guest PC 0x0c095070 */
if(!s->budget--) { s->failed_pc=0x0c095070u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c095072;
P_0c095072: /* original e042, guest PC 0x0c095072 */
if(!s->budget--) { s->failed_pc=0x0c095072u; return 0; }
r[0]=0x00000042u;
goto P_0c095074;
P_0c095074: /* original 1e5f, guest PC 0x0c095074 */
if(!s->budget--) { s->failed_pc=0x0c095074u; return 0; }
write(ram,r[14]+60,r[5],4);
goto P_0c095076;
P_0c095076: /* original 0e55, guest PC 0x0c095076 */
if(!s->budget--) { s->failed_pc=0x0c095076u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c095078;
P_0c095078: /* original 7056, guest PC 0x0c095078 */
if(!s->budget--) { s->failed_pc=0x0c095078u; return 0; }
r[0]+=0x00000056u;
goto P_0c09507a;
P_0c09507a: /* original 1e5e, guest PC 0x0c09507a */
if(!s->budget--) { s->failed_pc=0x0c09507au; return 0; }
write(ram,r[14]+56,r[5],4);
goto P_0c09507c;
P_0c09507c: /* original 0e55, guest PC 0x0c09507c */
if(!s->budget--) { s->failed_pc=0x0c09507cu; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c09507e;
P_0c09507e: /* original 70f0, guest PC 0x0c09507e */
if(!s->budget--) { s->failed_pc=0x0c09507eu; return 0; }
r[0]+=0xfffffff0u;
goto P_0c095080;
P_0c095080: /* original 0e54, guest PC 0x0c095080 */
if(!s->budget--) { s->failed_pc=0x0c095080u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c095082;
P_0c095082: /* original 8441, guest PC 0x0c095082 */
if(!s->budget--) { s->failed_pc=0x0c095082u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c095084;
P_0c095084: /* original 6540, guest PC 0x0c095084 */
if(!s->budget--) { s->failed_pc=0x0c095084u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[5]=tmp;
goto P_0c095086;
P_0c095086: /* original 670c, guest PC 0x0c095086 */
if(!s->budget--) { s->failed_pc=0x0c095086u; return 0; }
r[7]=r[0]&255u;
goto P_0c095088;
P_0c095088: /* original 8541, guest PC 0x0c095088 */
if(!s->budget--) { s->failed_pc=0x0c095088u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c09508a;
P_0c09508a: /* original 6d5c, guest PC 0x0c09508a */
if(!s->budget--) { s->failed_pc=0x0c09508au; return 0; }
r[13]=r[5]&255u;
goto P_0c09508c;
P_0c09508c: /* original 6303, guest PC 0x0c09508c */
if(!s->budget--) { s->failed_pc=0x0c09508cu; return 0; }
r[3]=r[0];
goto P_0c09508e;
P_0c09508e: /* original 9046, guest PC 0x0c09508e */
if(!s->budget--) { s->failed_pc=0x0c09508eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09511eu,2);
goto P_0c095090;
P_0c095090: /* original 0e34, guest PC 0x0c095090 */
if(!s->budget--) { s->failed_pc=0x0c095090u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c095092;
P_0c095092: /* original 7003, guest PC 0x0c095092 */
if(!s->budget--) { s->failed_pc=0x0c095092u; return 0; }
r[0]+=0x00000003u;
goto P_0c095094;
P_0c095094: /* original 475a, guest PC 0x0c095094 */
if(!s->budget--) { s->failed_pc=0x0c095094u; return 0; }
r[53]=r[7];
goto P_0c095096;
P_0c095096: /* original 63e3, guest PC 0x0c095096 */
if(!s->budget--) { s->failed_pc=0x0c095096u; return 0; }
r[3]=r[14];
goto P_0c095098;
P_0c095098: /* original 734c, guest PC 0x0c095098 */
if(!s->budget--) { s->failed_pc=0x0c095098u; return 0; }
r[3]+=0x0000004cu;
goto P_0c09509a;
P_0c09509a: /* original f32d, guest PC 0x0c09509a */
if(!s->budget--) { s->failed_pc=0x0c09509au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c09509c;
P_0c09509c: /* original f43c, guest PC 0x0c09509c */
if(!s->budget--) { s->failed_pc=0x0c09509cu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c09509e;
P_0c09509e: /* original f49d, guest PC 0x0c09509e */
if(!s->budget--) { s->failed_pc=0x0c09509eu; return 0; }
fr[4]=0x3f800000u;
goto P_0c0950a0;
P_0c0950a0: /* original f433, guest PC 0x0c0950a0 */
if(!s->budget--) { s->failed_pc=0x0c0950a0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c0950a2;
P_0c0950a2: /* original fe47, guest PC 0x0c0950a2 */
if(!s->budget--) { s->failed_pc=0x0c0950a2u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0950a4;
P_0c0950a4: /* original 7004, guest PC 0x0c0950a4 */
if(!s->budget--) { s->failed_pc=0x0c0950a4u; return 0; }
r[0]+=0x00000004u;
goto P_0c0950a6;
P_0c0950a6: /* original f38d, guest PC 0x0c0950a6 */
if(!s->budget--) { s->failed_pc=0x0c0950a6u; return 0; }
fr[3]=0;
goto P_0c0950a8;
P_0c0950a8: /* original fe37, guest PC 0x0c0950a8 */
if(!s->budget--) { s->failed_pc=0x0c0950a8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0950aa;
P_0c0950aa: /* original e068, guest PC 0x0c0950aa */
if(!s->budget--) { s->failed_pc=0x0c0950aau; return 0; }
r[0]=0x00000068u;
goto P_0c0950ac;
P_0c0950ac: /* original 5261, guest PC 0x0c0950ac */
if(!s->budget--) { s->failed_pc=0x0c0950acu; return 0; }
r[2]=read(ram,r[6]+4,4);
goto P_0c0950ae;
P_0c0950ae: /* original 5121, guest PC 0x0c0950ae */
if(!s->budget--) { s->failed_pc=0x0c0950aeu; return 0; }
r[1]=read(ram,r[2]+4,4);
goto P_0c0950b0;
P_0c0950b0: /* original 2312, guest PC 0x0c0950b0 */
if(!s->budget--) { s->failed_pc=0x0c0950b0u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0950b2;
P_0c0950b2: /* original 03ee, guest PC 0x0c0950b2 */
if(!s->budget--) { s->failed_pc=0x0c0950b2u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0950b4;
P_0c0950b4: /* original e074, guest PC 0x0c0950b4 */
if(!s->budget--) { s->failed_pc=0x0c0950b4u; return 0; }
r[0]=0x00000074u;
goto P_0c0950b6;
P_0c0950b6: /* original 0e36, guest PC 0x0c0950b6 */
if(!s->budget--) { s->failed_pc=0x0c0950b6u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0950b8;
P_0c0950b8: /* original 4d08, guest PC 0x0c0950b8 */
if(!s->budget--) { s->failed_pc=0x0c0950b8u; return 0; }
r[13]<<=2;
goto P_0c0950ba;
P_0c0950ba: /* original 85ef, guest PC 0x0c0950ba */
if(!s->budget--) { s->failed_pc=0x0c0950bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0950bc;
P_0c0950bc: /* original 9130, guest PC 0x0c0950bc */
if(!s->budget--) { s->failed_pc=0x0c0950bcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c095120u,2);
goto P_0c0950be;
P_0c0950be: /* original 6303, guest PC 0x0c0950be */
if(!s->budget--) { s->failed_pc=0x0c0950beu; return 0; }
r[3]=r[0];
goto P_0c0950c0;
P_0c0950c0: /* original 4000, guest PC 0x0c0950c0 */
if(!s->budget--) { s->failed_pc=0x0c0950c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0950c2;
P_0c0950c2: /* original 303c, guest PC 0x0c0950c2 */
if(!s->budget--) { s->failed_pc=0x0c0950c2u; return 0; }
r[0]+=r[3];
goto P_0c0950c4;
P_0c0950c4: /* original 63e3, guest PC 0x0c0950c4 */
if(!s->budget--) { s->failed_pc=0x0c0950c4u; return 0; }
r[3]=r[14];
goto P_0c0950c6;
P_0c0950c6: /* original 734c, guest PC 0x0c0950c6 */
if(!s->budget--) { s->failed_pc=0x0c0950c6u; return 0; }
r[3]+=0x0000004cu;
goto P_0c0950c8;
P_0c0950c8: /* original 4008, guest PC 0x0c0950c8 */
if(!s->budget--) { s->failed_pc=0x0c0950c8u; return 0; }
r[0]<<=2;
goto P_0c0950ca;
P_0c0950ca: /* original 33dc, guest PC 0x0c0950ca */
if(!s->budget--) { s->failed_pc=0x0c0950cau; return 0; }
r[3]+=r[13];
goto P_0c0950cc;
P_0c0950cc: /* original 4000, guest PC 0x0c0950cc */
if(!s->budget--) { s->failed_pc=0x0c0950ccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0950ce;
P_0c0950ce: /* original 31ec, guest PC 0x0c0950ce */
if(!s->budget--) { s->failed_pc=0x0c0950ceu; return 0; }
r[1]+=r[14];
goto P_0c0950d0;
P_0c0950d0: /* original 2102, guest PC 0x0c0950d0 */
if(!s->budget--) { s->failed_pc=0x0c0950d0u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0950d2;
P_0c0950d2: /* original e07c, guest PC 0x0c0950d2 */
if(!s->budget--) { s->failed_pc=0x0c0950d2u; return 0; }
r[0]=0x0000007cu;
goto P_0c0950d4;
P_0c0950d4: /* original 6232, guest PC 0x0c0950d4 */
if(!s->budget--) { s->failed_pc=0x0c0950d4u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0950d6;
P_0c0950d6: /* original 63e3, guest PC 0x0c0950d6 */
if(!s->budget--) { s->failed_pc=0x0c0950d6u; return 0; }
r[3]=r[14];
goto P_0c0950d8;
P_0c0950d8: /* original 734c, guest PC 0x0c0950d8 */
if(!s->budget--) { s->failed_pc=0x0c0950d8u; return 0; }
r[3]+=0x0000004cu;
goto P_0c0950da;
P_0c0950da: /* original 0e26, guest PC 0x0c0950da */
if(!s->budget--) { s->failed_pc=0x0c0950dau; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0950dc;
P_0c0950dc: /* original e078, guest PC 0x0c0950dc */
if(!s->budget--) { s->failed_pc=0x0c0950dcu; return 0; }
r[0]=0x00000078u;
goto P_0c0950de;
P_0c0950de: /* original 6232, guest PC 0x0c0950de */
if(!s->budget--) { s->failed_pc=0x0c0950deu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0950e0;
P_0c0950e0: /* original 0e26, guest PC 0x0c0950e0 */
if(!s->budget--) { s->failed_pc=0x0c0950e0u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0950e2;
P_0c0950e2: /* original 85ef, guest PC 0x0c0950e2 */
if(!s->budget--) { s->failed_pc=0x0c0950e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0950e4;
P_0c0950e4: /* original 6703, guest PC 0x0c0950e4 */
if(!s->budget--) { s->failed_pc=0x0c0950e4u; return 0; }
r[7]=r[0];
goto P_0c0950e6;
P_0c0950e6: /* original e074, guest PC 0x0c0950e6 */
if(!s->budget--) { s->failed_pc=0x0c0950e6u; return 0; }
r[0]=0x00000074u;
goto P_0c0950e8;
P_0c0950e8: /* original 06ee, guest PC 0x0c0950e8 */
if(!s->budget--) { s->failed_pc=0x0c0950e8u; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c0950ea;
P_0c0950ea: /* original e078, guest PC 0x0c0950ea */
if(!s->budget--) { s->failed_pc=0x0c0950eau; return 0; }
r[0]=0x00000078u;
goto P_0c0950ec;
P_0c0950ec: /* original 05ee, guest PC 0x0c0950ec */
if(!s->budget--) { s->failed_pc=0x0c0950ecu; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0950ee;
P_0c0950ee: /* original bc25, guest PC 0x0c0950ee */
if(!s->budget--) { s->failed_pc=0x0c0950eeu; return 0; }
target=0x0c09493cu; r[16]=0x0c0950f2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0950f2u) { target=s->pc; goto dispatch; }
goto P_0c0950f2;
P_0c0950f0: /* original 64e3, guest PC 0x0c0950f0 */
if(!s->budget--) { s->failed_pc=0x0c0950f0u; return 0; }
r[4]=r[14];
goto P_0c0950f2;
P_0c0950f2: /* original 62e3, guest PC 0x0c0950f2 */
if(!s->budget--) { s->failed_pc=0x0c0950f2u; return 0; }
r[2]=r[14];
goto P_0c0950f4;
P_0c0950f4: /* original 724c, guest PC 0x0c0950f4 */
if(!s->budget--) { s->failed_pc=0x0c0950f4u; return 0; }
r[2]+=0x0000004cu;
goto P_0c0950f6;
P_0c0950f6: /* original 32dc, guest PC 0x0c0950f6 */
if(!s->budget--) { s->failed_pc=0x0c0950f6u; return 0; }
r[2]+=r[13];
goto P_0c0950f8;
P_0c0950f8: /* original 6322, guest PC 0x0c0950f8 */
if(!s->budget--) { s->failed_pc=0x0c0950f8u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0950fa;
P_0c0950fa: /* original 62e3, guest PC 0x0c0950fa */
if(!s->budget--) { s->failed_pc=0x0c0950fau; return 0; }
r[2]=r[14];
goto P_0c0950fc;
P_0c0950fc: /* original 724c, guest PC 0x0c0950fc */
if(!s->budget--) { s->failed_pc=0x0c0950fcu; return 0; }
r[2]+=0x0000004cu;
goto P_0c0950fe;
P_0c0950fe: /* original 4f26, guest PC 0x0c0950fe */
if(!s->budget--) { s->failed_pc=0x0c0950feu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c095100;
P_0c095100: /* original e070, guest PC 0x0c095100 */
if(!s->budget--) { s->failed_pc=0x0c095100u; return 0; }
r[0]=0x00000070u;
goto P_0c095102;
P_0c095102: /* original 3d2c, guest PC 0x0c095102 */
if(!s->budget--) { s->failed_pc=0x0c095102u; return 0; }
r[13]+=r[2];
goto P_0c095104;
P_0c095104: /* original 0e36, guest PC 0x0c095104 */
if(!s->budget--) { s->failed_pc=0x0c095104u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c095106;
P_0c095106: /* original 63d2, guest PC 0x0c095106 */
if(!s->budget--) { s->failed_pc=0x0c095106u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c095108;
P_0c095108: /* original e06c, guest PC 0x0c095108 */
if(!s->budget--) { s->failed_pc=0x0c095108u; return 0; }
r[0]=0x0000006cu;
goto P_0c09510a;
P_0c09510a: /* original 0e36, guest PC 0x0c09510a */
if(!s->budget--) { s->failed_pc=0x0c09510au; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09510c;
P_0c09510c: /* original d20b, guest PC 0x0c09510c */
if(!s->budget--) { s->failed_pc=0x0c09510cu; return 0; }
r[2]=read(ram,0x0c09513cu,4);
goto P_0c09510e;
P_0c09510e: /* original 1e23, guest PC 0x0c09510e */
if(!s->budget--) { s->failed_pc=0x0c09510eu; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c095110;
P_0c095110: /* original 6df6, guest PC 0x0c095110 */
if(!s->budget--) { s->failed_pc=0x0c095110u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c095112;
P_0c095112: /* original 000b, guest PC 0x0c095112 */
if(!s->budget--) { s->failed_pc=0x0c095112u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c095114: /* original 6ef6, guest PC 0x0c095114 */
if(!s->budget--) { s->failed_pc=0x0c095114u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c095116u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c094e8cu,0x0c094e8eu,0x0c094e90u,0x0c094e92u,0x0c094e94u,0x0c094e96u,0x0c094eb0u,0x0c094eb2u,0x0c094eb4u,0x0c094eb6u,0x0c094eb8u,0x0c094ebau,0x0c094ebcu,0x0c094ebeu,0x0c094ec0u,0x0c094ec2u,
0x0c094ec4u,0x0c094ec6u,0x0c094ec8u,0x0c094ecau,0x0c094eccu,0x0c094eceu,0x0c094ed0u,0x0c094ed2u,0x0c094ed4u,0x0c094ed6u,0x0c094ed8u,0x0c094edau,0x0c094edcu,0x0c094edeu,0x0c094ee0u,0x0c094ee2u,
0x0c094ee4u,0x0c094ee6u,0x0c094ee8u,0x0c094eeau,0x0c094eecu,0x0c094eeeu,0x0c094ef0u,0x0c094ef2u,0x0c094ef4u,0x0c094ef6u,0x0c094ef8u,0x0c094efau,0x0c094efcu,0x0c094efeu,0x0c094f00u,0x0c094f02u,
0x0c094f04u,0x0c094f06u,0x0c094f08u,0x0c094f0au,0x0c094f0cu,0x0c094f0eu,0x0c094f10u,0x0c094f12u,0x0c094f14u,0x0c094f16u,0x0c094f18u,0x0c094f1au,0x0c094f1cu,0x0c094f1eu,0x0c094f20u,0x0c094f22u,
0x0c094f24u,0x0c094f26u,0x0c094f28u,0x0c094f2au,0x0c094f2cu,0x0c094f2eu,0x0c094f30u,0x0c094f32u,0x0c094f34u,0x0c094f36u,0x0c094f38u,0x0c094f3au,0x0c094f3cu,0x0c094f3eu,0x0c094f40u,0x0c094f42u,
0x0c094f44u,0x0c094f46u,0x0c094f48u,0x0c094f4au,0x0c094f4cu,0x0c094f4eu,0x0c094f50u,0x0c094f52u,0x0c094f54u,0x0c094f56u,0x0c094f58u,0x0c094f5au,0x0c094f5cu,0x0c094f5eu,0x0c094f60u,0x0c094f62u,
0x0c094f64u,0x0c094f66u,0x0c094f68u,0x0c094f6au,0x0c094f6cu,0x0c094f6eu,0x0c094f70u,0x0c094f72u,0x0c094f74u,0x0c094f76u,0x0c094f78u,0x0c094f7au,0x0c094f7cu,0x0c094fc0u,0x0c094fc2u,0x0c094fc4u,
0x0c094fc6u,0x0c094fc8u,0x0c094fcau,0x0c094fccu,0x0c094fceu,0x0c094fd0u,0x0c094fd2u,0x0c094fd4u,0x0c094fd6u,0x0c094fd8u,0x0c094fdau,0x0c094fdcu,0x0c094fdeu,0x0c094fe0u,0x0c094fe2u,0x0c094fe4u,
0x0c094fe6u,0x0c094fe8u,0x0c094feau,0x0c094fecu,0x0c094feeu,0x0c094ff0u,0x0c094ff2u,0x0c094ff4u,0x0c094ff6u,0x0c094ff8u,0x0c094ffau,0x0c094ffcu,0x0c094ffeu,0x0c095000u,0x0c095002u,0x0c095004u,
0x0c095006u,0x0c095008u,0x0c09500au,0x0c09500cu,0x0c09500eu,0x0c095010u,0x0c095012u,0x0c095014u,0x0c095016u,0x0c095018u,0x0c09501au,0x0c09501cu,0x0c09501eu,0x0c095020u,0x0c095022u,0x0c095024u,
0x0c095026u,0x0c095028u,0x0c09502au,0x0c09502cu,0x0c09502eu,0x0c095030u,0x0c095032u,0x0c095034u,0x0c095036u,0x0c095038u,0x0c09503au,0x0c09503cu,0x0c09503eu,0x0c095040u,0x0c095042u,0x0c095044u,
0x0c095046u,0x0c095048u,0x0c09504au,0x0c09504cu,0x0c09504eu,0x0c095050u,0x0c095052u,0x0c095054u,0x0c095056u,0x0c095058u,0x0c09505au,0x0c09505cu,0x0c09505eu,0x0c095060u,0x0c095062u,0x0c095064u,
0x0c095066u,0x0c095068u,0x0c09506au,0x0c09506cu,0x0c09506eu,0x0c095070u,0x0c095072u,0x0c095074u,0x0c095076u,0x0c095078u,0x0c09507au,0x0c09507cu,0x0c09507eu,0x0c095080u,0x0c095082u,0x0c095084u,
0x0c095086u,0x0c095088u,0x0c09508au,0x0c09508cu,0x0c09508eu,0x0c095090u,0x0c095092u,0x0c095094u,0x0c095096u,0x0c095098u,0x0c09509au,0x0c09509cu,0x0c09509eu,0x0c0950a0u,0x0c0950a2u,0x0c0950a4u,
0x0c0950a6u,0x0c0950a8u,0x0c0950aau,0x0c0950acu,0x0c0950aeu,0x0c0950b0u,0x0c0950b2u,0x0c0950b4u,0x0c0950b6u,0x0c0950b8u,0x0c0950bau,0x0c0950bcu,0x0c0950beu,0x0c0950c0u,0x0c0950c2u,0x0c0950c4u,
0x0c0950c6u,0x0c0950c8u,0x0c0950cau,0x0c0950ccu,0x0c0950ceu,0x0c0950d0u,0x0c0950d2u,0x0c0950d4u,0x0c0950d6u,0x0c0950d8u,0x0c0950dau,0x0c0950dcu,0x0c0950deu,0x0c0950e0u,0x0c0950e2u,0x0c0950e4u,
0x0c0950e6u,0x0c0950e8u,0x0c0950eau,0x0c0950ecu,0x0c0950eeu,0x0c0950f0u,0x0c0950f2u,0x0c0950f4u,0x0c0950f6u,0x0c0950f8u,0x0c0950fau,0x0c0950fcu,0x0c0950feu,0x0c095100u,0x0c095102u,0x0c095104u,
0x0c095106u,0x0c095108u,0x0c09510au,0x0c09510cu,0x0c09510eu,0x0c095110u,0x0c095112u,0x0c095114u,
};
int vf3_motion_group_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
