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
int vf3_away_batch45_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c0a0280u: goto P_0c0a0280;
case 0x0c0a0282u: goto P_0c0a0282;
case 0x0c0a0284u: goto P_0c0a0284;
case 0x0c0a0286u: goto P_0c0a0286;
case 0x0c0a0288u: goto P_0c0a0288;
case 0x0c0a028au: goto P_0c0a028a;
case 0x0c0a028cu: goto P_0c0a028c;
case 0x0c0a028eu: goto P_0c0a028e;
case 0x0c0a0290u: goto P_0c0a0290;
case 0x0c0a0292u: goto P_0c0a0292;
case 0x0c0a0294u: goto P_0c0a0294;
case 0x0c0a0296u: goto P_0c0a0296;
case 0x0c0a0298u: goto P_0c0a0298;
case 0x0c0a029au: goto P_0c0a029a;
case 0x0c0a029cu: goto P_0c0a029c;
case 0x0c0a029eu: goto P_0c0a029e;
case 0x0c0a02a0u: goto P_0c0a02a0;
case 0x0c0a02a2u: goto P_0c0a02a2;
case 0x0c0a02a4u: goto P_0c0a02a4;
case 0x0c0a02a6u: goto P_0c0a02a6;
case 0x0c0a02a8u: goto P_0c0a02a8;
case 0x0c0a02aau: goto P_0c0a02aa;
case 0x0c0a02acu: goto P_0c0a02ac;
case 0x0c0a02aeu: goto P_0c0a02ae;
case 0x0c0a02b0u: goto P_0c0a02b0;
case 0x0c0a02b2u: goto P_0c0a02b2;
case 0x0c0a02b4u: goto P_0c0a02b4;
case 0x0c0a02b6u: goto P_0c0a02b6;
case 0x0c0a02b8u: goto P_0c0a02b8;
case 0x0c0a02bau: goto P_0c0a02ba;
case 0x0c0a02bcu: goto P_0c0a02bc;
case 0x0c0a02beu: goto P_0c0a02be;
case 0x0c0a02c0u: goto P_0c0a02c0;
case 0x0c0a02c2u: goto P_0c0a02c2;
case 0x0c0a02c4u: goto P_0c0a02c4;
case 0x0c0a02c6u: goto P_0c0a02c6;
case 0x0c0a02c8u: goto P_0c0a02c8;
case 0x0c0a02cau: goto P_0c0a02ca;
case 0x0c0a02ccu: goto P_0c0a02cc;
case 0x0c0a02ceu: goto P_0c0a02ce;
case 0x0c0a02d0u: goto P_0c0a02d0;
case 0x0c0a02d2u: goto P_0c0a02d2;
case 0x0c0a02d4u: goto P_0c0a02d4;
case 0x0c0a02d6u: goto P_0c0a02d6;
case 0x0c0a02d8u: goto P_0c0a02d8;
case 0x0c0a02dau: goto P_0c0a02da;
case 0x0c0a02dcu: goto P_0c0a02dc;
case 0x0c0a02deu: goto P_0c0a02de;
case 0x0c0a02e0u: goto P_0c0a02e0;
case 0x0c0a02e2u: goto P_0c0a02e2;
case 0x0c0a02e4u: goto P_0c0a02e4;
case 0x0c0a02e6u: goto P_0c0a02e6;
case 0x0c0a02e8u: goto P_0c0a02e8;
case 0x0c0a02eau: goto P_0c0a02ea;
case 0x0c0a02ecu: goto P_0c0a02ec;
case 0x0c0a02eeu: goto P_0c0a02ee;
case 0x0c0a02f0u: goto P_0c0a02f0;
case 0x0c0a02f2u: goto P_0c0a02f2;
case 0x0c0a02f4u: goto P_0c0a02f4;
case 0x0c0a02f6u: goto P_0c0a02f6;
case 0x0c0a02f8u: goto P_0c0a02f8;
case 0x0c0a02fau: goto P_0c0a02fa;
case 0x0c0a02fcu: goto P_0c0a02fc;
case 0x0c0a02feu: goto P_0c0a02fe;
case 0x0c0a0300u: goto P_0c0a0300;
case 0x0c0a0302u: goto P_0c0a0302;
case 0x0c0a0304u: goto P_0c0a0304;
case 0x0c0a0306u: goto P_0c0a0306;
case 0x0c0a0308u: goto P_0c0a0308;
case 0x0c0a030au: goto P_0c0a030a;
case 0x0c0a030cu: goto P_0c0a030c;
case 0x0c0a030eu: goto P_0c0a030e;
case 0x0c0a0310u: goto P_0c0a0310;
case 0x0c0a0312u: goto P_0c0a0312;
case 0x0c0a0314u: goto P_0c0a0314;
case 0x0c0a0316u: goto P_0c0a0316;
case 0x0c0a0318u: goto P_0c0a0318;
case 0x0c0a031au: goto P_0c0a031a;
case 0x0c0a031cu: goto P_0c0a031c;
case 0x0c0a031eu: goto P_0c0a031e;
case 0x0c0a0320u: goto P_0c0a0320;
case 0x0c0a0322u: goto P_0c0a0322;
case 0x0c0a0324u: goto P_0c0a0324;
case 0x0c0a0326u: goto P_0c0a0326;
case 0x0c0a0328u: goto P_0c0a0328;
case 0x0c0a032au: goto P_0c0a032a;
case 0x0c0a032cu: goto P_0c0a032c;
case 0x0c0a032eu: goto P_0c0a032e;
case 0x0c0a036cu: goto P_0c0a036c;
case 0x0c0a036eu: goto P_0c0a036e;
case 0x0c0a0370u: goto P_0c0a0370;
case 0x0c0a0372u: goto P_0c0a0372;
case 0x0c0a0374u: goto P_0c0a0374;
case 0x0c0a0376u: goto P_0c0a0376;
case 0x0c0a0378u: goto P_0c0a0378;
case 0x0c0a037au: goto P_0c0a037a;
case 0x0c0a037cu: goto P_0c0a037c;
case 0x0c0a037eu: goto P_0c0a037e;
case 0x0c0a0380u: goto P_0c0a0380;
case 0x0c0a0382u: goto P_0c0a0382;
case 0x0c0a0384u: goto P_0c0a0384;
case 0x0c0a0386u: goto P_0c0a0386;
case 0x0c0a0388u: goto P_0c0a0388;
case 0x0c0a038au: goto P_0c0a038a;
case 0x0c0a038cu: goto P_0c0a038c;
case 0x0c0a038eu: goto P_0c0a038e;
case 0x0c0a0390u: goto P_0c0a0390;
case 0x0c0a0392u: goto P_0c0a0392;
case 0x0c0a0394u: goto P_0c0a0394;
case 0x0c0a0396u: goto P_0c0a0396;
case 0x0c0a0398u: goto P_0c0a0398;
case 0x0c0a039au: goto P_0c0a039a;
case 0x0c0a039cu: goto P_0c0a039c;
case 0x0c0a039eu: goto P_0c0a039e;
case 0x0c0a03a0u: goto P_0c0a03a0;
case 0x0c0a03a2u: goto P_0c0a03a2;
case 0x0c0a03a4u: goto P_0c0a03a4;
case 0x0c0a03a6u: goto P_0c0a03a6;
case 0x0c0a03a8u: goto P_0c0a03a8;
case 0x0c0a03aau: goto P_0c0a03aa;
case 0x0c0a03acu: goto P_0c0a03ac;
case 0x0c0a03aeu: goto P_0c0a03ae;
case 0x0c0a03b0u: goto P_0c0a03b0;
case 0x0c0a03b2u: goto P_0c0a03b2;
case 0x0c0a03b4u: goto P_0c0a03b4;
case 0x0c0a03b6u: goto P_0c0a03b6;
case 0x0c0a03b8u: goto P_0c0a03b8;
case 0x0c0a03bau: goto P_0c0a03ba;
case 0x0c0a03bcu: goto P_0c0a03bc;
case 0x0c0a03beu: goto P_0c0a03be;
case 0x0c0a03c0u: goto P_0c0a03c0;
case 0x0c0a03c2u: goto P_0c0a03c2;
case 0x0c0a03c4u: goto P_0c0a03c4;
case 0x0c0a03c6u: goto P_0c0a03c6;
case 0x0c0a03c8u: goto P_0c0a03c8;
case 0x0c0a03cau: goto P_0c0a03ca;
case 0x0c0a03ccu: goto P_0c0a03cc;
case 0x0c0a03ceu: goto P_0c0a03ce;
case 0x0c0a03d0u: goto P_0c0a03d0;
case 0x0c0a03d2u: goto P_0c0a03d2;
case 0x0c0a03d4u: goto P_0c0a03d4;
case 0x0c0a03d6u: goto P_0c0a03d6;
case 0x0c0a03d8u: goto P_0c0a03d8;
case 0x0c0a03dau: goto P_0c0a03da;
case 0x0c0a03dcu: goto P_0c0a03dc;
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
P_0c0a0280: /* original 2fe6, guest PC 0x0c0a0280 */
if(!s->budget--) { s->failed_pc=0x0c0a0280u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0282;
P_0c0a0282: /* original 2fd6, guest PC 0x0c0a0282 */
if(!s->budget--) { s->failed_pc=0x0c0a0282u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0284;
P_0c0a0284: /* original 2fc6, guest PC 0x0c0a0284 */
if(!s->budget--) { s->failed_pc=0x0c0a0284u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0286;
P_0c0a0286: /* original ec2b, guest PC 0x0c0a0286 */
if(!s->budget--) { s->failed_pc=0x0c0a0286u; return 0; }
r[12]=0x0000002bu;
goto P_0c0a0288;
P_0c0a0288: /* original 2fb6, guest PC 0x0c0a0288 */
if(!s->budget--) { s->failed_pc=0x0c0a0288u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a028a;
P_0c0a028a: /* original 4f22, guest PC 0x0c0a028a */
if(!s->budget--) { s->failed_pc=0x0c0a028au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a028c;
P_0c0a028c: /* original d32f, guest PC 0x0c0a028c */
if(!s->budget--) { s->failed_pc=0x0c0a028cu; return 0; }
r[3]=read(ram,0x0c0a034cu,4);
goto P_0c0a028e;
P_0c0a028e: /* original de2e, guest PC 0x0c0a028e */
if(!s->budget--) { s->failed_pc=0x0c0a028eu; return 0; }
r[14]=read(ram,0x0c0a0348u,4);
goto P_0c0a0290;
P_0c0a0290: /* original 7ff8, guest PC 0x0c0a0290 */
if(!s->budget--) { s->failed_pc=0x0c0a0290u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a0292;
P_0c0a0292: /* original 1f31, guest PC 0x0c0a0292 */
if(!s->budget--) { s->failed_pc=0x0c0a0292u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0a0294;
P_0c0a0294: /* original e307, guest PC 0x0c0a0294 */
if(!s->budget--) { s->failed_pc=0x0c0a0294u; return 0; }
r[3]=0x00000007u;
goto P_0c0a0296;
P_0c0a0296: /* original d22e, guest PC 0x0c0a0296 */
if(!s->budget--) { s->failed_pc=0x0c0a0296u; return 0; }
r[2]=read(ram,0x0c0a0350u,4);
goto P_0c0a0298;
P_0c0a0298: /* original 6422, guest PC 0x0c0a0298 */
if(!s->budget--) { s->failed_pc=0x0c0a0298u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0a029a;
P_0c0a029a: /* original 3c48, guest PC 0x0c0a029a */
if(!s->budget--) { s->failed_pc=0x0c0a029au; return 0; }
r[12]-=r[4];
goto P_0c0a029c;
P_0c0a029c: /* original 2fc2, guest PC 0x0c0a029c */
if(!s->budget--) { s->failed_pc=0x0c0a029cu; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0a029e;
P_0c0a029e: /* original e428, guest PC 0x0c0a029e */
if(!s->budget--) { s->failed_pc=0x0c0a029eu; return 0; }
r[4]=0x00000028u;
goto P_0c0a02a0;
P_0c0a02a0: /* original d52c, guest PC 0x0c0a02a0 */
if(!s->budget--) { s->failed_pc=0x0c0a02a0u; return 0; }
r[5]=read(ram,0x0c0a0354u,4);
goto P_0c0a02a2;
P_0c0a02a2: /* original 4c3c, guest PC 0x0c0a02a2 */
if(!s->budget--) { s->failed_pc=0x0c0a02a2u; return 0; }
r[12]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[12]>>((-r[3])&31u)):((int32_t)r[12]<0?0xffffffffu:0)):r[12]<<(r[3]&31u);
goto P_0c0a02a4;
P_0c0a02a4: /* original d12c, guest PC 0x0c0a02a4 */
if(!s->budget--) { s->failed_pc=0x0c0a02a4u; return 0; }
r[1]=read(ram,0x0c0a0358u,4);
goto P_0c0a02a6;
P_0c0a02a6: /* original 24cb, guest PC 0x0c0a02a6 */
if(!s->budget--) { s->failed_pc=0x0c0a02a6u; return 0; }
r[4]|=r[12];
goto P_0c0a02a8;
P_0c0a02a8: /* original 410b, guest PC 0x0c0a02a8 */
if(!s->budget--) { s->failed_pc=0x0c0a02a8u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a02acu;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a02acu) { target=s->pc; goto dispatch; }
goto P_0c0a02ac;
P_0c0a02aa: /* original e601, guest PC 0x0c0a02aa */
if(!s->budget--) { s->failed_pc=0x0c0a02aau; return 0; }
r[6]=0x00000001u;
goto P_0c0a02ac;
P_0c0a02ac: /* original 9041, guest PC 0x0c0a02ac */
if(!s->budget--) { s->failed_pc=0x0c0a02acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0332u,2);
goto P_0c0a02ae;
P_0c0a02ae: /* original e41c, guest PC 0x0c0a02ae */
if(!s->budget--) { s->failed_pc=0x0c0a02aeu; return 0; }
r[4]=0x0000001cu;
goto P_0c0a02b0;
P_0c0a02b0: /* original dd2b, guest PC 0x0c0a02b0 */
if(!s->budget--) { s->failed_pc=0x0c0a02b0u; return 0; }
r[13]=read(ram,0x0c0a0360u,4);
goto P_0c0a02b2;
P_0c0a02b2: /* original 24cb, guest PC 0x0c0a02b2 */
if(!s->budget--) { s->failed_pc=0x0c0a02b2u; return 0; }
r[4]|=r[12];
goto P_0c0a02b4;
P_0c0a02b4: /* original 03ec, guest PC 0x0c0a02b4 */
if(!s->budget--) { s->failed_pc=0x0c0a02b4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02b6;
P_0c0a02b6: /* original db29, guest PC 0x0c0a02b6 */
if(!s->budget--) { s->failed_pc=0x0c0a02b6u; return 0; }
r[11]=read(ram,0x0c0a035cu,4);
goto P_0c0a02b8;
P_0c0a02b8: /* original 2f36, guest PC 0x0c0a02b8 */
if(!s->budget--) { s->failed_pc=0x0c0a02b8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02ba;
P_0c0a02ba: /* original 4d0b, guest PC 0x0c0a02ba */
if(!s->budget--) { s->failed_pc=0x0c0a02bau; return 0; }
target=r[13];
r[16]=code_base|0x0c0a02beu;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a02beu) { target=s->pc; goto dispatch; }
goto P_0c0a02be;
P_0c0a02bc: /* original 2fb6, guest PC 0x0c0a02bc */
if(!s->budget--) { s->failed_pc=0x0c0a02bcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02be;
P_0c0a02be: /* original 903b, guest PC 0x0c0a02be */
if(!s->budget--) { s->failed_pc=0x0c0a02beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0338u,2);
goto P_0c0a02c0;
P_0c0a02c0: /* original e420, guest PC 0x0c0a02c0 */
if(!s->budget--) { s->failed_pc=0x0c0a02c0u; return 0; }
r[4]=0x00000020u;
goto P_0c0a02c2;
P_0c0a02c2: /* original 24cb, guest PC 0x0c0a02c2 */
if(!s->budget--) { s->failed_pc=0x0c0a02c2u; return 0; }
r[4]|=r[12];
goto P_0c0a02c4;
P_0c0a02c4: /* original 03ec, guest PC 0x0c0a02c4 */
if(!s->budget--) { s->failed_pc=0x0c0a02c4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02c6;
P_0c0a02c6: /* original 2f36, guest PC 0x0c0a02c6 */
if(!s->budget--) { s->failed_pc=0x0c0a02c6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02c8;
P_0c0a02c8: /* original 4d0b, guest PC 0x0c0a02c8 */
if(!s->budget--) { s->failed_pc=0x0c0a02c8u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a02ccu;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a02ccu) { target=s->pc; goto dispatch; }
goto P_0c0a02cc;
P_0c0a02ca: /* original 2fb6, guest PC 0x0c0a02ca */
if(!s->budget--) { s->failed_pc=0x0c0a02cau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02cc;
P_0c0a02cc: /* original 9035, guest PC 0x0c0a02cc */
if(!s->budget--) { s->failed_pc=0x0c0a02ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a033au,2);
goto P_0c0a02ce;
P_0c0a02ce: /* original e424, guest PC 0x0c0a02ce */
if(!s->budget--) { s->failed_pc=0x0c0a02ceu; return 0; }
r[4]=0x00000024u;
goto P_0c0a02d0;
P_0c0a02d0: /* original 24cb, guest PC 0x0c0a02d0 */
if(!s->budget--) { s->failed_pc=0x0c0a02d0u; return 0; }
r[4]|=r[12];
goto P_0c0a02d2;
P_0c0a02d2: /* original 03ec, guest PC 0x0c0a02d2 */
if(!s->budget--) { s->failed_pc=0x0c0a02d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02d4;
P_0c0a02d4: /* original 2f36, guest PC 0x0c0a02d4 */
if(!s->budget--) { s->failed_pc=0x0c0a02d4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02d6;
P_0c0a02d6: /* original 4d0b, guest PC 0x0c0a02d6 */
if(!s->budget--) { s->failed_pc=0x0c0a02d6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a02dau;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a02dau) { target=s->pc; goto dispatch; }
goto P_0c0a02da;
P_0c0a02d8: /* original 2fb6, guest PC 0x0c0a02d8 */
if(!s->budget--) { s->failed_pc=0x0c0a02d8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02da;
P_0c0a02da: /* original 902f, guest PC 0x0c0a02da */
if(!s->budget--) { s->failed_pc=0x0c0a02dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a033cu,2);
goto P_0c0a02dc;
P_0c0a02dc: /* original e428, guest PC 0x0c0a02dc */
if(!s->budget--) { s->failed_pc=0x0c0a02dcu; return 0; }
r[4]=0x00000028u;
goto P_0c0a02de;
P_0c0a02de: /* original 24cb, guest PC 0x0c0a02de */
if(!s->budget--) { s->failed_pc=0x0c0a02deu; return 0; }
r[4]|=r[12];
goto P_0c0a02e0;
P_0c0a02e0: /* original 03ec, guest PC 0x0c0a02e0 */
if(!s->budget--) { s->failed_pc=0x0c0a02e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02e2;
P_0c0a02e2: /* original 2f36, guest PC 0x0c0a02e2 */
if(!s->budget--) { s->failed_pc=0x0c0a02e2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02e4;
P_0c0a02e4: /* original 4d0b, guest PC 0x0c0a02e4 */
if(!s->budget--) { s->failed_pc=0x0c0a02e4u; return 0; }
target=r[13];
r[16]=code_base|0x0c0a02e8u;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a02e8u) { target=s->pc; goto dispatch; }
goto P_0c0a02e8;
P_0c0a02e6: /* original 2fb6, guest PC 0x0c0a02e6 */
if(!s->budget--) { s->failed_pc=0x0c0a02e6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a02e8;
P_0c0a02e8: /* original 9029, guest PC 0x0c0a02e8 */
if(!s->budget--) { s->failed_pc=0x0c0a02e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a033eu,2);
goto P_0c0a02ea;
P_0c0a02ea: /* original e307, guest PC 0x0c0a02ea */
if(!s->budget--) { s->failed_pc=0x0c0a02eau; return 0; }
r[3]=0x00000007u;
goto P_0c0a02ec;
P_0c0a02ec: /* original e601, guest PC 0x0c0a02ec */
if(!s->budget--) { s->failed_pc=0x0c0a02ecu; return 0; }
r[6]=0x00000001u;
goto P_0c0a02ee;
P_0c0a02ee: /* original 04ec, guest PC 0x0c0a02ee */
if(!s->budget--) { s->failed_pc=0x0c0a02eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02f0;
P_0c0a02f0: /* original d01c, guest PC 0x0c0a02f0 */
if(!s->budget--) { s->failed_pc=0x0c0a02f0u; return 0; }
r[0]=read(ram,0x0c0a0364u,4);
goto P_0c0a02f2;
P_0c0a02f2: /* original 044c, guest PC 0x0c0a02f2 */
if(!s->budget--) { s->failed_pc=0x0c0a02f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a02f4;
P_0c0a02f4: /* original 9024, guest PC 0x0c0a02f4 */
if(!s->budget--) { s->failed_pc=0x0c0a02f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0340u,2);
goto P_0c0a02f6;
P_0c0a02f6: /* original 0e44, guest PC 0x0c0a02f6 */
if(!s->budget--) { s->failed_pc=0x0c0a02f6u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0a02f8;
P_0c0a02f8: /* original 70f9, guest PC 0x0c0a02f8 */
if(!s->budget--) { s->failed_pc=0x0c0a02f8u; return 0; }
r[0]+=0xfffffff9u;
goto P_0c0a02fa;
P_0c0a02fa: /* original 04ec, guest PC 0x0c0a02fa */
if(!s->budget--) { s->failed_pc=0x0c0a02fau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a02fc;
P_0c0a02fc: /* original 52f8, guest PC 0x0c0a02fc */
if(!s->budget--) { s->failed_pc=0x0c0a02fcu; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c0a02fe;
P_0c0a02fe: /* original 4400, guest PC 0x0c0a02fe */
if(!s->budget--) { s->failed_pc=0x0c0a02feu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a0300;
P_0c0a0300: /* original 951e, guest PC 0x0c0a0300 */
if(!s->budget--) { s->failed_pc=0x0c0a0300u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0340u,2);
goto P_0c0a0302;
P_0c0a0302: /* original 740e, guest PC 0x0c0a0302 */
if(!s->budget--) { s->failed_pc=0x0c0a0302u; return 0; }
r[4]+=0x0000000eu;
goto P_0c0a0304;
P_0c0a0304: /* original 423c, guest PC 0x0c0a0304 */
if(!s->budget--) { s->failed_pc=0x0c0a0304u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[2]>>((-r[3])&31u)):((int32_t)r[2]<0?0xffffffffu:0)):r[2]<<(r[3]&31u);
goto P_0c0a0306;
P_0c0a0306: /* original 4400, guest PC 0x0c0a0306 */
if(!s->budget--) { s->failed_pc=0x0c0a0306u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a0308;
P_0c0a0308: /* original 242b, guest PC 0x0c0a0308 */
if(!s->budget--) { s->failed_pc=0x0c0a0308u; return 0; }
r[4]|=r[2];
goto P_0c0a030a;
P_0c0a030a: /* original d213, guest PC 0x0c0a030a */
if(!s->budget--) { s->failed_pc=0x0c0a030au; return 0; }
r[2]=read(ram,0x0c0a0358u,4);
goto P_0c0a030c;
P_0c0a030c: /* original 420b, guest PC 0x0c0a030c */
if(!s->budget--) { s->failed_pc=0x0c0a030cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a0310u;
r[5]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0310u) { target=s->pc; goto dispatch; }
goto P_0c0a0310;
P_0c0a030e: /* original 35ec, guest PC 0x0c0a030e */
if(!s->budget--) { s->failed_pc=0x0c0a030eu; return 0; }
r[5]+=r[14];
goto P_0c0a0310;
P_0c0a0310: /* original 55f9, guest PC 0x0c0a0310 */
if(!s->budget--) { s->failed_pc=0x0c0a0310u; return 0; }
r[5]=read(ram,r[15]+36,4);
goto P_0c0a0312;
P_0c0a0312: /* original e3fa, guest PC 0x0c0a0312 */
if(!s->budget--) { s->failed_pc=0x0c0a0312u; return 0; }
r[3]=0xfffffffau;
goto P_0c0a0314;
P_0c0a0314: /* original 9415, guest PC 0x0c0a0314 */
if(!s->budget--) { s->failed_pc=0x0c0a0314u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0342u,2);
goto P_0c0a0316;
P_0c0a0316: /* original 5553, guest PC 0x0c0a0316 */
if(!s->budget--) { s->failed_pc=0x0c0a0316u; return 0; }
r[5]=read(ram,r[5]+12,4);
goto P_0c0a0318;
P_0c0a0318: /* original 453c, guest PC 0x0c0a0318 */
if(!s->budget--) { s->failed_pc=0x0c0a0318u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c0a031a;
P_0c0a031a: /* original 2f56, guest PC 0x0c0a031a */
if(!s->budget--) { s->failed_pc=0x0c0a031au; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a031c;
P_0c0a031c: /* original d212, guest PC 0x0c0a031c */
if(!s->budget--) { s->failed_pc=0x0c0a031cu; return 0; }
r[2]=read(ram,0x0c0a0368u,4);
goto P_0c0a031e;
P_0c0a031e: /* original 4d0b, guest PC 0x0c0a031e */
if(!s->budget--) { s->failed_pc=0x0c0a031eu; return 0; }
target=r[13];
r[16]=code_base|0x0c0a0322u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a0322u) { target=s->pc; goto dispatch; }
goto P_0c0a0322;
P_0c0a0320: /* original 2f26, guest PC 0x0c0a0320 */
if(!s->budget--) { s->failed_pc=0x0c0a0320u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0322;
P_0c0a0322: /* original 7f30, guest PC 0x0c0a0322 */
if(!s->budget--) { s->failed_pc=0x0c0a0322u; return 0; }
r[15]+=0x00000030u;
goto P_0c0a0324;
P_0c0a0324: /* original 4f26, guest PC 0x0c0a0324 */
if(!s->budget--) { s->failed_pc=0x0c0a0324u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0326;
P_0c0a0326: /* original 6bf6, guest PC 0x0c0a0326 */
if(!s->budget--) { s->failed_pc=0x0c0a0326u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a0328;
P_0c0a0328: /* original 6cf6, guest PC 0x0c0a0328 */
if(!s->budget--) { s->failed_pc=0x0c0a0328u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a032a;
P_0c0a032a: /* original 6df6, guest PC 0x0c0a032a */
if(!s->budget--) { s->failed_pc=0x0c0a032au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a032c;
P_0c0a032c: /* original 000b, guest PC 0x0c0a032c */
if(!s->budget--) { s->failed_pc=0x0c0a032cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a032e: /* original 6ef6, guest PC 0x0c0a032e */
if(!s->budget--) { s->failed_pc=0x0c0a032eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a0330u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a0330u; return 0; } return 1;
P_0c0a036c: /* original 2fe6, guest PC 0x0c0a036c */
if(!s->budget--) { s->failed_pc=0x0c0a036cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a036e;
P_0c0a036e: /* original e606, guest PC 0x0c0a036e */
if(!s->budget--) { s->failed_pc=0x0c0a036eu; return 0; }
r[6]=0x00000006u;
goto P_0c0a0370;
P_0c0a0370: /* original 2fd6, guest PC 0x0c0a0370 */
if(!s->budget--) { s->failed_pc=0x0c0a0370u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0372;
P_0c0a0372: /* original e700, guest PC 0x0c0a0372 */
if(!s->budget--) { s->failed_pc=0x0c0a0372u; return 0; }
r[7]=0x00000000u;
goto P_0c0a0374;
P_0c0a0374: /* original 2fc6, guest PC 0x0c0a0374 */
if(!s->budget--) { s->failed_pc=0x0c0a0374u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0376;
P_0c0a0376: /* original 2fb6, guest PC 0x0c0a0376 */
if(!s->budget--) { s->failed_pc=0x0c0a0376u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a0378;
P_0c0a0378: /* original d433, guest PC 0x0c0a0378 */
if(!s->budget--) { s->failed_pc=0x0c0a0378u; return 0; }
r[4]=read(ram,0x0c0a0448u,4);
goto P_0c0a037a;
P_0c0a037a: /* original 9063, guest PC 0x0c0a037a */
if(!s->budget--) { s->failed_pc=0x0c0a037au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0444u,2);
goto P_0c0a037c;
P_0c0a037c: /* original 4f22, guest PC 0x0c0a037c */
if(!s->budget--) { s->failed_pc=0x0c0a037cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a037e;
P_0c0a037e: /* original 054c, guest PC 0x0c0a037e */
if(!s->budget--) { s->failed_pc=0x0c0a037eu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a0380;
P_0c0a0380: /* original dc32, guest PC 0x0c0a0380 */
if(!s->budget--) { s->failed_pc=0x0c0a0380u; return 0; }
r[12]=read(ram,0x0c0a044cu,4);
goto P_0c0a0382;
P_0c0a0382: /* original 3563, guest PC 0x0c0a0382 */
if(!s->budget--) { s->failed_pc=0x0c0a0382u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c0a0384;
P_0c0a0384: /* original 8f08, guest PC 0x0c0a0384 */
if(!s->budget--) { s->failed_pc=0x0c0a0384u; return 0; }
cond=r[17]&1u;
r[14]=r[7];
if(!cond) { goto P_0c0a0398; }
goto P_0c0a0388;
P_0c0a0386: /* original 6e73, guest PC 0x0c0a0386 */
if(!s->budget--) { s->failed_pc=0x0c0a0386u; return 0; }
r[14]=r[7];
goto P_0c0a0388;
P_0c0a0388: /* original e50c, guest PC 0x0c0a0388 */
if(!s->budget--) { s->failed_pc=0x0c0a0388u; return 0; }
r[5]=0x0000000cu;
goto P_0c0a038a;
P_0c0a038a: /* original 6053, guest PC 0x0c0a038a */
if(!s->budget--) { s->failed_pc=0x0c0a038au; return 0; }
r[0]=r[5];
goto P_0c0a038c;
P_0c0a038c: /* original 707c, guest PC 0x0c0a038c */
if(!s->budget--) { s->failed_pc=0x0c0a038cu; return 0; }
r[0]+=0x0000007cu;
goto P_0c0a038e;
P_0c0a038e: /* original 034c, guest PC 0x0c0a038e */
if(!s->budget--) { s->failed_pc=0x0c0a038eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a0390;
P_0c0a0390: /* original 3353, guest PC 0x0c0a0390 */
if(!s->budget--) { s->failed_pc=0x0c0a0390u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[5])!=0);
goto P_0c0a0392;
P_0c0a0392: /* original 8f01, guest PC 0x0c0a0392 */
if(!s->budget--) { s->failed_pc=0x0c0a0392u; return 0; }
cond=r[17]&1u;
r[14]=r[6];
if(!cond) { goto P_0c0a0398; }
goto P_0c0a0396;
P_0c0a0394: /* original 6e63, guest PC 0x0c0a0394 */
if(!s->budget--) { s->failed_pc=0x0c0a0394u; return 0; }
r[14]=r[6];
goto P_0c0a0396;
P_0c0a0396: /* original 6e53, guest PC 0x0c0a0396 */
if(!s->budget--) { s->failed_pc=0x0c0a0396u; return 0; }
r[14]=r[5];
goto P_0c0a0398;
P_0c0a0398: /* original eb18, guest PC 0x0c0a0398 */
if(!s->budget--) { s->failed_pc=0x0c0a0398u; return 0; }
r[11]=0x00000018u;
goto P_0c0a039a;
P_0c0a039a: /* original a018, guest PC 0x0c0a039a */
if(!s->budget--) { s->failed_pc=0x0c0a039au; return 0; }
r[13]=r[7];
goto P_0c0a03ce;
P_0c0a039c: /* original 6d73, guest PC 0x0c0a039c */
if(!s->budget--) { s->failed_pc=0x0c0a039cu; return 0; }
r[13]=r[7];
goto P_0c0a039e;
P_0c0a039e: /* original 65e3, guest PC 0x0c0a039e */
if(!s->budget--) { s->failed_pc=0x0c0a039eu; return 0; }
r[5]=r[14];
goto P_0c0a03a0;
P_0c0a03a0: /* original b03d, guest PC 0x0c0a03a0 */
if(!s->budget--) { s->failed_pc=0x0c0a03a0u; return 0; }
target=code_base|0x0c0a041eu; r[16]=code_base|0x0c0a03a4u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a03a4u) { target=s->pc; goto dispatch; }
goto P_0c0a03a4;
P_0c0a03a2: /* original 64d3, guest PC 0x0c0a03a2 */
if(!s->budget--) { s->failed_pc=0x0c0a03a2u; return 0; }
r[4]=r[13];
goto P_0c0a03a4;
P_0c0a03a4: /* original 65e3, guest PC 0x0c0a03a4 */
if(!s->budget--) { s->failed_pc=0x0c0a03a4u; return 0; }
r[5]=r[14];
goto P_0c0a03a6;
P_0c0a03a6: /* original 63c3, guest PC 0x0c0a03a6 */
if(!s->budget--) { s->failed_pc=0x0c0a03a6u; return 0; }
r[3]=r[12];
goto P_0c0a03a8;
P_0c0a03a8: /* original 4508, guest PC 0x0c0a03a8 */
if(!s->budget--) { s->failed_pc=0x0c0a03a8u; return 0; }
r[5]<<=2;
goto P_0c0a03aa;
P_0c0a03aa: /* original 353c, guest PC 0x0c0a03aa */
if(!s->budget--) { s->failed_pc=0x0c0a03aau; return 0; }
r[5]+=r[3];
goto P_0c0a03ac;
P_0c0a03ac: /* original b056, guest PC 0x0c0a03ac */
if(!s->budget--) { s->failed_pc=0x0c0a03acu; return 0; }
target=code_base|0x0c0a045cu; r[16]=code_base|0x0c0a03b0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a03b0u) { target=s->pc; goto dispatch; }
goto P_0c0a03b0;
P_0c0a03ae: /* original 64d3, guest PC 0x0c0a03ae */
if(!s->budget--) { s->failed_pc=0x0c0a03aeu; return 0; }
r[4]=r[13];
goto P_0c0a03b0;
P_0c0a03b0: /* original 63c3, guest PC 0x0c0a03b0 */
if(!s->budget--) { s->failed_pc=0x0c0a03b0u; return 0; }
r[3]=r[12];
goto P_0c0a03b2;
P_0c0a03b2: /* original 65e3, guest PC 0x0c0a03b2 */
if(!s->budget--) { s->failed_pc=0x0c0a03b2u; return 0; }
r[5]=r[14];
goto P_0c0a03b4;
P_0c0a03b4: /* original 7348, guest PC 0x0c0a03b4 */
if(!s->budget--) { s->failed_pc=0x0c0a03b4u; return 0; }
r[3]+=0x00000048u;
goto P_0c0a03b6;
P_0c0a03b6: /* original 4508, guest PC 0x0c0a03b6 */
if(!s->budget--) { s->failed_pc=0x0c0a03b6u; return 0; }
r[5]<<=2;
goto P_0c0a03b8;
P_0c0a03b8: /* original 353c, guest PC 0x0c0a03b8 */
if(!s->budget--) { s->failed_pc=0x0c0a03b8u; return 0; }
r[5]+=r[3];
goto P_0c0a03ba;
P_0c0a03ba: /* original b08f, guest PC 0x0c0a03ba */
if(!s->budget--) { s->failed_pc=0x0c0a03bau; return 0; }
target=code_base|0x0c0a04dcu; r[16]=code_base|0x0c0a03beu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a03beu) { target=s->pc; goto dispatch; }
goto P_0c0a03be;
P_0c0a03bc: /* original 64d3, guest PC 0x0c0a03bc */
if(!s->budget--) { s->failed_pc=0x0c0a03bcu; return 0; }
r[4]=r[13];
goto P_0c0a03be;
P_0c0a03be: /* original 9642, guest PC 0x0c0a03be */
if(!s->budget--) { s->failed_pc=0x0c0a03beu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0446u,2);
goto P_0c0a03c0;
P_0c0a03c0: /* original 65e3, guest PC 0x0c0a03c0 */
if(!s->budget--) { s->failed_pc=0x0c0a03c0u; return 0; }
r[5]=r[14];
goto P_0c0a03c2;
P_0c0a03c2: /* original 36cc, guest PC 0x0c0a03c2 */
if(!s->budget--) { s->failed_pc=0x0c0a03c2u; return 0; }
r[6]+=r[12];
goto P_0c0a03c4;
P_0c0a03c4: /* original 36ec, guest PC 0x0c0a03c4 */
if(!s->budget--) { s->failed_pc=0x0c0a03c4u; return 0; }
r[6]+=r[14];
goto P_0c0a03c6;
P_0c0a03c6: /* original b0e1, guest PC 0x0c0a03c6 */
if(!s->budget--) { s->failed_pc=0x0c0a03c6u; return 0; }
target=code_base|0x0c0a058cu; r[16]=code_base|0x0c0a03cau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a03cau) { target=s->pc; goto dispatch; }
goto P_0c0a03ca;
P_0c0a03c8: /* original 64d3, guest PC 0x0c0a03c8 */
if(!s->budget--) { s->failed_pc=0x0c0a03c8u; return 0; }
r[4]=r[13];
goto P_0c0a03ca;
P_0c0a03ca: /* original 7e01, guest PC 0x0c0a03ca */
if(!s->budget--) { s->failed_pc=0x0c0a03cau; return 0; }
r[14]+=0x00000001u;
goto P_0c0a03cc;
P_0c0a03cc: /* original 7d04, guest PC 0x0c0a03cc */
if(!s->budget--) { s->failed_pc=0x0c0a03ccu; return 0; }
r[13]+=0x00000004u;
goto P_0c0a03ce;
P_0c0a03ce: /* original 3db3, guest PC 0x0c0a03ce */
if(!s->budget--) { s->failed_pc=0x0c0a03ceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[11])!=0);
goto P_0c0a03d0;
P_0c0a03d0: /* original 8be5, guest PC 0x0c0a03d0 */
if(!s->budget--) { s->failed_pc=0x0c0a03d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a039e; }
goto P_0c0a03d2;
P_0c0a03d2: /* original 4f26, guest PC 0x0c0a03d2 */
if(!s->budget--) { s->failed_pc=0x0c0a03d2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a03d4;
P_0c0a03d4: /* original 6bf6, guest PC 0x0c0a03d4 */
if(!s->budget--) { s->failed_pc=0x0c0a03d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a03d6;
P_0c0a03d6: /* original 6cf6, guest PC 0x0c0a03d6 */
if(!s->budget--) { s->failed_pc=0x0c0a03d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a03d8;
P_0c0a03d8: /* original 6df6, guest PC 0x0c0a03d8 */
if(!s->budget--) { s->failed_pc=0x0c0a03d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a03da;
P_0c0a03da: /* original 000b, guest PC 0x0c0a03da */
if(!s->budget--) { s->failed_pc=0x0c0a03dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a03dc: /* original 6ef6, guest PC 0x0c0a03dc */
if(!s->budget--) { s->failed_pc=0x0c0a03dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a03deu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
