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
int vf3_away_batch10_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03ee40u: goto P_0c03ee40;
case 0x0c03ee42u: goto P_0c03ee42;
case 0x0c03ee44u: goto P_0c03ee44;
case 0x0c03ee46u: goto P_0c03ee46;
case 0x0c03ee90u: goto P_0c03ee90;
case 0x0c03ee92u: goto P_0c03ee92;
case 0x0c03ee94u: goto P_0c03ee94;
case 0x0c03ee96u: goto P_0c03ee96;
case 0x0c03ee98u: goto P_0c03ee98;
case 0x0c03ee9au: goto P_0c03ee9a;
case 0x0c03ee9cu: goto P_0c03ee9c;
case 0x0c03ee9eu: goto P_0c03ee9e;
case 0x0c03eea0u: goto P_0c03eea0;
case 0x0c03eea2u: goto P_0c03eea2;
case 0x0c03eea4u: goto P_0c03eea4;
case 0x0c03eea6u: goto P_0c03eea6;
case 0x0c03eea8u: goto P_0c03eea8;
case 0x0c03eeaau: goto P_0c03eeaa;
case 0x0c03eeacu: goto P_0c03eeac;
case 0x0c03eeaeu: goto P_0c03eeae;
case 0x0c03eeb0u: goto P_0c03eeb0;
case 0x0c03eeb2u: goto P_0c03eeb2;
case 0x0c03eeb4u: goto P_0c03eeb4;
case 0x0c03eeb6u: goto P_0c03eeb6;
case 0x0c03eeb8u: goto P_0c03eeb8;
case 0x0c03eebau: goto P_0c03eeba;
case 0x0c03eebcu: goto P_0c03eebc;
case 0x0c03eebeu: goto P_0c03eebe;
case 0x0c03eec0u: goto P_0c03eec0;
case 0x0c03eec2u: goto P_0c03eec2;
case 0x0c03eec4u: goto P_0c03eec4;
case 0x0c03eec6u: goto P_0c03eec6;
case 0x0c03eec8u: goto P_0c03eec8;
case 0x0c03eecau: goto P_0c03eeca;
case 0x0c03eeccu: goto P_0c03eecc;
case 0x0c03eeceu: goto P_0c03eece;
case 0x0c03eed0u: goto P_0c03eed0;
case 0x0c03eed2u: goto P_0c03eed2;
case 0x0c03eed4u: goto P_0c03eed4;
case 0x0c03eed6u: goto P_0c03eed6;
case 0x0c03eed8u: goto P_0c03eed8;
case 0x0c03eedau: goto P_0c03eeda;
case 0x0c03eedcu: goto P_0c03eedc;
case 0x0c03eedeu: goto P_0c03eede;
case 0x0c03eee0u: goto P_0c03eee0;
case 0x0c03eee2u: goto P_0c03eee2;
case 0x0c03eee4u: goto P_0c03eee4;
case 0x0c03eee6u: goto P_0c03eee6;
case 0x0c03eee8u: goto P_0c03eee8;
case 0x0c03eeeau: goto P_0c03eeea;
case 0x0c03eeecu: goto P_0c03eeec;
case 0x0c03eeeeu: goto P_0c03eeee;
case 0x0c03eef0u: goto P_0c03eef0;
case 0x0c03eef2u: goto P_0c03eef2;
case 0x0c03eef4u: goto P_0c03eef4;
case 0x0c03eef6u: goto P_0c03eef6;
case 0x0c03eef8u: goto P_0c03eef8;
case 0x0c03eefau: goto P_0c03eefa;
case 0x0c03eefcu: goto P_0c03eefc;
case 0x0c03eefeu: goto P_0c03eefe;
case 0x0c03ef00u: goto P_0c03ef00;
case 0x0c03ef02u: goto P_0c03ef02;
case 0x0c03f5a0u: goto P_0c03f5a0;
case 0x0c03f5a2u: goto P_0c03f5a2;
case 0x0c03f5a4u: goto P_0c03f5a4;
case 0x0c03f5a6u: goto P_0c03f5a6;
case 0x0c03f5a8u: goto P_0c03f5a8;
case 0x0c03f5aau: goto P_0c03f5aa;
case 0x0c03f5acu: goto P_0c03f5ac;
case 0x0c03f5aeu: goto P_0c03f5ae;
case 0x0c03f5b0u: goto P_0c03f5b0;
case 0x0c03f5b2u: goto P_0c03f5b2;
case 0x0c03f5b4u: goto P_0c03f5b4;
case 0x0c03f5b6u: goto P_0c03f5b6;
case 0x0c03f5b8u: goto P_0c03f5b8;
case 0x0c03f5bau: goto P_0c03f5ba;
case 0x0c03f5bcu: goto P_0c03f5bc;
case 0x0c03f5beu: goto P_0c03f5be;
case 0x0c03f5c0u: goto P_0c03f5c0;
case 0x0c03f5c2u: goto P_0c03f5c2;
case 0x0c03f5d0u: goto P_0c03f5d0;
case 0x0c03f5d2u: goto P_0c03f5d2;
case 0x0c03f5d4u: goto P_0c03f5d4;
case 0x0c03f5d6u: goto P_0c03f5d6;
case 0x0c03f5d8u: goto P_0c03f5d8;
case 0x0c03f5dau: goto P_0c03f5da;
case 0x0c03f5dcu: goto P_0c03f5dc;
case 0x0c03f5deu: goto P_0c03f5de;
case 0x0c03f5e0u: goto P_0c03f5e0;
case 0x0c03f5e2u: goto P_0c03f5e2;
case 0x0c03f5e4u: goto P_0c03f5e4;
case 0x0c03f5e6u: goto P_0c03f5e6;
case 0x0c03f5e8u: goto P_0c03f5e8;
case 0x0c03f5eau: goto P_0c03f5ea;
case 0x0c03f5ecu: goto P_0c03f5ec;
case 0x0c03f5eeu: goto P_0c03f5ee;
case 0x0c03f5f0u: goto P_0c03f5f0;
case 0x0c03f5f2u: goto P_0c03f5f2;
case 0x0c03f5f4u: goto P_0c03f5f4;
case 0x0c03f5f6u: goto P_0c03f5f6;
case 0x0c03f5f8u: goto P_0c03f5f8;
case 0x0c03f5fau: goto P_0c03f5fa;
case 0x0c03f5fcu: goto P_0c03f5fc;
case 0x0c03f5feu: goto P_0c03f5fe;
case 0x0c03f600u: goto P_0c03f600;
case 0x0c03f602u: goto P_0c03f602;
case 0x0c03f604u: goto P_0c03f604;
case 0x0c03f606u: goto P_0c03f606;
case 0x0c03f608u: goto P_0c03f608;
case 0x0c03f60au: goto P_0c03f60a;
case 0x0c03f60cu: goto P_0c03f60c;
case 0x0c03f60eu: goto P_0c03f60e;
case 0x0c03f610u: goto P_0c03f610;
case 0x0c03f612u: goto P_0c03f612;
case 0x0c03f614u: goto P_0c03f614;
case 0x0c03f616u: goto P_0c03f616;
case 0x0c03f618u: goto P_0c03f618;
case 0x0c03f61au: goto P_0c03f61a;
case 0x0c03f61cu: goto P_0c03f61c;
case 0x0c03f61eu: goto P_0c03f61e;
case 0x0c03f620u: goto P_0c03f620;
case 0x0c03f622u: goto P_0c03f622;
case 0x0c03f624u: goto P_0c03f624;
case 0x0c03f626u: goto P_0c03f626;
case 0x0c03f628u: goto P_0c03f628;
case 0x0c03f62au: goto P_0c03f62a;
case 0x0c03f62cu: goto P_0c03f62c;
case 0x0c03f62eu: goto P_0c03f62e;
case 0x0c03f630u: goto P_0c03f630;
case 0x0c03f632u: goto P_0c03f632;
case 0x0c03f634u: goto P_0c03f634;
case 0x0c03f636u: goto P_0c03f636;
case 0x0c03f638u: goto P_0c03f638;
case 0x0c03f63au: goto P_0c03f63a;
case 0x0c03f63cu: goto P_0c03f63c;
case 0x0c03f63eu: goto P_0c03f63e;
case 0x0c03f640u: goto P_0c03f640;
case 0x0c03f642u: goto P_0c03f642;
case 0x0c03f644u: goto P_0c03f644;
case 0x0c03f646u: goto P_0c03f646;
case 0x0c03f648u: goto P_0c03f648;
case 0x0c03f64au: goto P_0c03f64a;
case 0x0c03f64cu: goto P_0c03f64c;
case 0x0c03f64eu: goto P_0c03f64e;
case 0x0c03f650u: goto P_0c03f650;
case 0x0c03f652u: goto P_0c03f652;
case 0x0c03f654u: goto P_0c03f654;
case 0x0c03f656u: goto P_0c03f656;
case 0x0c03f658u: goto P_0c03f658;
case 0x0c03f65au: goto P_0c03f65a;
case 0x0c03f65cu: goto P_0c03f65c;
case 0x0c03f65eu: goto P_0c03f65e;
case 0x0c03f660u: goto P_0c03f660;
case 0x0c03f662u: goto P_0c03f662;
case 0x0c03f664u: goto P_0c03f664;
case 0x0c03f666u: goto P_0c03f666;
case 0x0c03f668u: goto P_0c03f668;
case 0x0c03f66au: goto P_0c03f66a;
case 0x0c03f66cu: goto P_0c03f66c;
case 0x0c03f66eu: goto P_0c03f66e;
case 0x0c03f670u: goto P_0c03f670;
case 0x0c03f672u: goto P_0c03f672;
case 0x0c03f674u: goto P_0c03f674;
case 0x0c03f676u: goto P_0c03f676;
case 0x0c03f678u: goto P_0c03f678;
case 0x0c03f67au: goto P_0c03f67a;
case 0x0c03f67cu: goto P_0c03f67c;
case 0x0c03f67eu: goto P_0c03f67e;
case 0x0c03f680u: goto P_0c03f680;
case 0x0c03f682u: goto P_0c03f682;
case 0x0c03f684u: goto P_0c03f684;
case 0x0c03fc90u: goto P_0c03fc90;
case 0x0c03fc92u: goto P_0c03fc92;
case 0x0c03fc94u: goto P_0c03fc94;
case 0x0c03fc96u: goto P_0c03fc96;
case 0x0c03fc98u: goto P_0c03fc98;
case 0x0c03fc9au: goto P_0c03fc9a;
case 0x0c03fc9cu: goto P_0c03fc9c;
case 0x0c03fc9eu: goto P_0c03fc9e;
case 0x0c03fca0u: goto P_0c03fca0;
case 0x0c03fca2u: goto P_0c03fca2;
case 0x0c03fca4u: goto P_0c03fca4;
case 0x0c03fca6u: goto P_0c03fca6;
case 0x0c03fca8u: goto P_0c03fca8;
case 0x0c03fcaau: goto P_0c03fcaa;
case 0x0c03fcacu: goto P_0c03fcac;
case 0x0c03fcaeu: goto P_0c03fcae;
case 0x0c03fcb0u: goto P_0c03fcb0;
case 0x0c03fcb2u: goto P_0c03fcb2;
case 0x0c03fcb4u: goto P_0c03fcb4;
case 0x0c03fcb6u: goto P_0c03fcb6;
case 0x0c03fcb8u: goto P_0c03fcb8;
case 0x0c03fcbau: goto P_0c03fcba;
case 0x0c03fcbcu: goto P_0c03fcbc;
case 0x0c03fcbeu: goto P_0c03fcbe;
case 0x0c03fcc0u: goto P_0c03fcc0;
case 0x0c03fcc2u: goto P_0c03fcc2;
case 0x0c03fcc4u: goto P_0c03fcc4;
case 0x0c03fcc6u: goto P_0c03fcc6;
case 0x0c03fcc8u: goto P_0c03fcc8;
case 0x0c03fccau: goto P_0c03fcca;
case 0x0c03fcccu: goto P_0c03fccc;
case 0x0c03fcceu: goto P_0c03fcce;
case 0x0c03fcd0u: goto P_0c03fcd0;
case 0x0c03fcd2u: goto P_0c03fcd2;
case 0x0c03fcd4u: goto P_0c03fcd4;
case 0x0c03fcd6u: goto P_0c03fcd6;
case 0x0c03fcd8u: goto P_0c03fcd8;
case 0x0c03fcdau: goto P_0c03fcda;
case 0x0c03fcdcu: goto P_0c03fcdc;
case 0x0c03fcdeu: goto P_0c03fcde;
case 0x0c03fce0u: goto P_0c03fce0;
case 0x0c03fce2u: goto P_0c03fce2;
case 0x0c03fce4u: goto P_0c03fce4;
case 0x0c03fce6u: goto P_0c03fce6;
case 0x0c03fce8u: goto P_0c03fce8;
case 0x0c03fceau: goto P_0c03fcea;
case 0x0c03fcecu: goto P_0c03fcec;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03ee40: /* original d40f, guest PC 0x0c03ee40 */
if(!s->budget--) { s->failed_pc=0x0c03ee40u; return 0; }
r[4]=read(ram,0x0c03ee80u,4);
goto P_0c03ee42;
P_0c03ee42: /* original d508, guest PC 0x0c03ee42 */
if(!s->budget--) { s->failed_pc=0x0c03ee42u; return 0; }
r[5]=read(ram,0x0c03ee64u,4);
goto P_0c03ee44;
P_0c03ee44: /* original a024, guest PC 0x0c03ee44 */
if(!s->budget--) { s->failed_pc=0x0c03ee44u; return 0; }
goto P_0c03ee90;
P_0c03ee46: /* original 0009, guest PC 0x0c03ee46 */
if(!s->budget--) { s->failed_pc=0x0c03ee46u; return 0; }
if(!vf3_matrix_family(0x0c03ee48u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03ee48u; return 0; } return 1;
P_0c03ee90: /* original f38d, guest PC 0x0c03ee90 */
if(!s->budget--) { s->failed_pc=0x0c03ee90u; return 0; }
fr[3]=0;
goto P_0c03ee92;
P_0c03ee92: /* original fbfd, guest PC 0x0c03ee92 */
if(!s->budget--) { s->failed_pc=0x0c03ee92u; return 0; }
vf3_matrix_swap(s);
goto P_0c03ee94;
P_0c03ee94: /* original f11d, guest PC 0x0c03ee94 */
if(!s->budget--) { s->failed_pc=0x0c03ee94u; return 0; }
r[53]=fr[1];
goto P_0c03ee96;
P_0c03ee96: /* original f14c, guest PC 0x0c03ee96 */
if(!s->budget--) { s->failed_pc=0x0c03ee96u; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c03ee98;
P_0c03ee98: /* original f40d, guest PC 0x0c03ee98 */
if(!s->budget--) { s->failed_pc=0x0c03ee98u; return 0; }
fr[4]=r[53];
goto P_0c03ee9a;
P_0c03ee9a: /* original f21d, guest PC 0x0c03ee9a */
if(!s->budget--) { s->failed_pc=0x0c03ee9au; return 0; }
r[53]=fr[2];
goto P_0c03ee9c;
P_0c03ee9c: /* original f28c, guest PC 0x0c03ee9c */
if(!s->budget--) { s->failed_pc=0x0c03ee9cu; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c03ee9e;
P_0c03ee9e: /* original f80d, guest PC 0x0c03ee9e */
if(!s->budget--) { s->failed_pc=0x0c03ee9eu; return 0; }
fr[8]=r[53];
goto P_0c03eea0;
P_0c03eea0: /* original f61d, guest PC 0x0c03eea0 */
if(!s->budget--) { s->failed_pc=0x0c03eea0u; return 0; }
r[53]=fr[6];
goto P_0c03eea2;
P_0c03eea2: /* original f69c, guest PC 0x0c03eea2 */
if(!s->budget--) { s->failed_pc=0x0c03eea2u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c03eea4;
P_0c03eea4: /* original f90d, guest PC 0x0c03eea4 */
if(!s->budget--) { s->failed_pc=0x0c03eea4u; return 0; }
fr[9]=r[53];
goto P_0c03eea6;
P_0c03eea6: /* original fbfd, guest PC 0x0c03eea6 */
if(!s->budget--) { s->failed_pc=0x0c03eea6u; return 0; }
vf3_matrix_swap(s);
goto P_0c03eea8;
P_0c03eea8: /* original f059, guest PC 0x0c03eea8 */
if(!s->budget--) { s->failed_pc=0x0c03eea8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03eeaa;
P_0c03eeaa: /* original f159, guest PC 0x0c03eeaa */
if(!s->budget--) { s->failed_pc=0x0c03eeaau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03eeac;
P_0c03eeac: /* original f259, guest PC 0x0c03eeac */
if(!s->budget--) { s->failed_pc=0x0c03eeacu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03eeae;
P_0c03eeae: /* original f658, guest PC 0x0c03eeae */
if(!s->budget--) { s->failed_pc=0x0c03eeaeu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
goto P_0c03eeb0;
P_0c03eeb0: /* original 75f4, guest PC 0x0c03eeb0 */
if(!s->budget--) { s->failed_pc=0x0c03eeb0u; return 0; }
r[5]+=0xfffffff4u;
goto P_0c03eeb2;
P_0c03eeb2: /* original f459, guest PC 0x0c03eeb2 */
if(!s->budget--) { s->failed_pc=0x0c03eeb2u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03eeb4;
P_0c03eeb4: /* original f78d, guest PC 0x0c03eeb4 */
if(!s->budget--) { s->failed_pc=0x0c03eeb4u; return 0; }
fr[7]=0;
goto P_0c03eeb6;
P_0c03eeb6: /* original f1fd, guest PC 0x0c03eeb6 */
if(!s->budget--) { s->failed_pc=0x0c03eeb6u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c03eeb8;
P_0c03eeb8: /* original f559, guest PC 0x0c03eeb8 */
if(!s->budget--) { s->failed_pc=0x0c03eeb8u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03eeba;
P_0c03eeba: /* original e010, guest PC 0x0c03eeba */
if(!s->budget--) { s->failed_pc=0x0c03eebau; return 0; }
r[0]=0x00000010u;
goto P_0c03eebc;
P_0c03eebc: /* original f5fd, guest PC 0x0c03eebc */
if(!s->budget--) { s->failed_pc=0x0c03eebcu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c03eebe;
P_0c03eebe: /* original f407, guest PC 0x0c03eebe */
if(!s->budget--) { s->failed_pc=0x0c03eebeu; return 0; }
vf3_matrix_store(s,ram,0,r[4]+r[0]);
goto P_0c03eec0;
P_0c03eec0: /* original e014, guest PC 0x0c03eec0 */
if(!s->budget--) { s->failed_pc=0x0c03eec0u; return 0; }
r[0]=0x00000014u;
goto P_0c03eec2;
P_0c03eec2: /* original f417, guest PC 0x0c03eec2 */
if(!s->budget--) { s->failed_pc=0x0c03eec2u; return 0; }
vf3_matrix_store(s,ram,1,r[4]+r[0]);
goto P_0c03eec4;
P_0c03eec4: /* original e018, guest PC 0x0c03eec4 */
if(!s->budget--) { s->failed_pc=0x0c03eec4u; return 0; }
r[0]=0x00000018u;
goto P_0c03eec6;
P_0c03eec6: /* original f427, guest PC 0x0c03eec6 */
if(!s->budget--) { s->failed_pc=0x0c03eec6u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c03eec8;
P_0c03eec8: /* original fbfd, guest PC 0x0c03eec8 */
if(!s->budget--) { s->failed_pc=0x0c03eec8u; return 0; }
vf3_matrix_swap(s);
goto P_0c03eeca;
P_0c03eeca: /* original f11d, guest PC 0x0c03eeca */
if(!s->budget--) { s->failed_pc=0x0c03eecau; return 0; }
r[53]=fr[1];
goto P_0c03eecc;
P_0c03eecc: /* original f14c, guest PC 0x0c03eecc */
if(!s->budget--) { s->failed_pc=0x0c03eeccu; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c03eece;
P_0c03eece: /* original f40d, guest PC 0x0c03eece */
if(!s->budget--) { s->failed_pc=0x0c03eeceu; return 0; }
fr[4]=r[53];
goto P_0c03eed0;
P_0c03eed0: /* original fbfd, guest PC 0x0c03eed0 */
if(!s->budget--) { s->failed_pc=0x0c03eed0u; return 0; }
vf3_matrix_swap(s);
goto P_0c03eed2;
P_0c03eed2: /* original f78d, guest PC 0x0c03eed2 */
if(!s->budget--) { s->failed_pc=0x0c03eed2u; return 0; }
fr[7]=0;
goto P_0c03eed4;
P_0c03eed4: /* original f5ed, guest PC 0x0c03eed4 */
if(!s->budget--) { s->failed_pc=0x0c03eed4u; return 0; }
if(!vf3_fpu_fipr(fr+4,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03eed6;
P_0c03eed6: /* original fbfd, guest PC 0x0c03eed6 */
if(!s->budget--) { s->failed_pc=0x0c03eed6u; return 0; }
vf3_matrix_swap(s);
goto P_0c03eed8;
P_0c03eed8: /* original f21d, guest PC 0x0c03eed8 */
if(!s->budget--) { s->failed_pc=0x0c03eed8u; return 0; }
r[53]=fr[2];
goto P_0c03eeda;
P_0c03eeda: /* original f28c, guest PC 0x0c03eeda */
if(!s->budget--) { s->failed_pc=0x0c03eedau; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c03eedc;
P_0c03eedc: /* original f80d, guest PC 0x0c03eedc */
if(!s->budget--) { s->failed_pc=0x0c03eedcu; return 0; }
fr[8]=r[53];
goto P_0c03eede;
P_0c03eede: /* original fbfd, guest PC 0x0c03eede */
if(!s->budget--) { s->failed_pc=0x0c03eedeu; return 0; }
vf3_matrix_swap(s);
goto P_0c03eee0;
P_0c03eee0: /* original f77d, guest PC 0x0c03eee0 */
if(!s->budget--) { s->failed_pc=0x0c03eee0u; return 0; }
if(!vf3_fpu_fsrra(fr[7],r[18],&fr[7])) goto unsupported;
goto P_0c03eee2;
P_0c03eee2: /* original fbfd, guest PC 0x0c03eee2 */
if(!s->budget--) { s->failed_pc=0x0c03eee2u; return 0; }
vf3_matrix_swap(s);
goto P_0c03eee4;
P_0c03eee4: /* original f61d, guest PC 0x0c03eee4 */
if(!s->budget--) { s->failed_pc=0x0c03eee4u; return 0; }
r[53]=fr[6];
goto P_0c03eee6;
P_0c03eee6: /* original f69c, guest PC 0x0c03eee6 */
if(!s->budget--) { s->failed_pc=0x0c03eee6u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c03eee8;
P_0c03eee8: /* original f90d, guest PC 0x0c03eee8 */
if(!s->budget--) { s->failed_pc=0x0c03eee8u; return 0; }
fr[9]=r[53];
goto P_0c03eeea;
P_0c03eeea: /* original fbfd, guest PC 0x0c03eeea */
if(!s->budget--) { s->failed_pc=0x0c03eeeau; return 0; }
vf3_matrix_swap(s);
goto P_0c03eeec;
P_0c03eeec: /* original f472, guest PC 0x0c03eeec */
if(!s->budget--) { s->failed_pc=0x0c03eeecu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c03eeee;
P_0c03eeee: /* original f572, guest PC 0x0c03eeee */
if(!s->budget--) { s->failed_pc=0x0c03eeeeu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c03eef0;
P_0c03eef0: /* original f672, guest PC 0x0c03eef0 */
if(!s->budget--) { s->failed_pc=0x0c03eef0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c03eef2;
P_0c03eef2: /* original e000, guest PC 0x0c03eef2 */
if(!s->budget--) { s->failed_pc=0x0c03eef2u; return 0; }
r[0]=0x00000000u;
goto P_0c03eef4;
P_0c03eef4: /* original f447, guest PC 0x0c03eef4 */
if(!s->budget--) { s->failed_pc=0x0c03eef4u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c03eef6;
P_0c03eef6: /* original e004, guest PC 0x0c03eef6 */
if(!s->budget--) { s->failed_pc=0x0c03eef6u; return 0; }
r[0]=0x00000004u;
goto P_0c03eef8;
P_0c03eef8: /* original f457, guest PC 0x0c03eef8 */
if(!s->budget--) { s->failed_pc=0x0c03eef8u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c03eefa;
P_0c03eefa: /* original e008, guest PC 0x0c03eefa */
if(!s->budget--) { s->failed_pc=0x0c03eefau; return 0; }
r[0]=0x00000008u;
goto P_0c03eefc;
P_0c03eefc: /* original f467, guest PC 0x0c03eefc */
if(!s->budget--) { s->failed_pc=0x0c03eefcu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c03eefe;
P_0c03eefe: /* original 0009, guest PC 0x0c03eefe */
if(!s->budget--) { s->failed_pc=0x0c03eefeu; return 0; }
goto P_0c03ef00;
P_0c03ef00: /* original 000b, guest PC 0x0c03ef00 */
if(!s->budget--) { s->failed_pc=0x0c03ef00u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03ef02: /* original 0009, guest PC 0x0c03ef02 */
if(!s->budget--) { s->failed_pc=0x0c03ef02u; return 0; }
if(!vf3_matrix_family(0x0c03ef04u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03ef04u; return 0; } return 1;
P_0c03f5a0: /* original 2fe6, guest PC 0x0c03f5a0 */
if(!s->budget--) { s->failed_pc=0x0c03f5a0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5a2;
P_0c03f5a2: /* original e300, guest PC 0x0c03f5a2 */
if(!s->budget--) { s->failed_pc=0x0c03f5a2u; return 0; }
r[3]=0x00000000u;
goto P_0c03f5a4;
P_0c03f5a4: /* original 2fd6, guest PC 0x0c03f5a4 */
if(!s->budget--) { s->failed_pc=0x0c03f5a4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5a6;
P_0c03f5a6: /* original 2fc6, guest PC 0x0c03f5a6 */
if(!s->budget--) { s->failed_pc=0x0c03f5a6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5a8;
P_0c03f5a8: /* original 6c43, guest PC 0x0c03f5a8 */
if(!s->budget--) { s->failed_pc=0x0c03f5a8u; return 0; }
r[12]=r[4];
goto P_0c03f5aa;
P_0c03f5aa: /* original 2fb6, guest PC 0x0c03f5aa */
if(!s->budget--) { s->failed_pc=0x0c03f5aau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5ac;
P_0c03f5ac: /* original 2fa6, guest PC 0x0c03f5ac */
if(!s->budget--) { s->failed_pc=0x0c03f5acu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5ae;
P_0c03f5ae: /* original 2f96, guest PC 0x0c03f5ae */
if(!s->budget--) { s->failed_pc=0x0c03f5aeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5b0;
P_0c03f5b0: /* original 2f86, guest PC 0x0c03f5b0 */
if(!s->budget--) { s->failed_pc=0x0c03f5b0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5b2;
P_0c03f5b2: /* original 4f22, guest PC 0x0c03f5b2 */
if(!s->budget--) { s->failed_pc=0x0c03f5b2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f5b4;
P_0c03f5b4: /* original 4f12, guest PC 0x0c03f5b4 */
if(!s->budget--) { s->failed_pc=0x0c03f5b4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03f5b6;
P_0c03f5b6: /* original 7ffc, guest PC 0x0c03f5b6 */
if(!s->budget--) { s->failed_pc=0x0c03f5b6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03f5b8;
P_0c03f5b8: /* original 2f32, guest PC 0x0c03f5b8 */
if(!s->budget--) { s->failed_pc=0x0c03f5b8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c03f5ba;
P_0c03f5ba: /* original d37a, guest PC 0x0c03f5ba */
if(!s->budget--) { s->failed_pc=0x0c03f5bau; return 0; }
r[3]=read(ram,0x0c03f7a4u,4);
goto P_0c03f5bc;
P_0c03f5bc: /* original de78, guest PC 0x0c03f5bc */
if(!s->budget--) { s->failed_pc=0x0c03f5bcu; return 0; }
r[14]=read(ram,0x0c03f7a0u,4);
goto P_0c03f5be;
P_0c03f5be: /* original d974, guest PC 0x0c03f5be */
if(!s->budget--) { s->failed_pc=0x0c03f5beu; return 0; }
r[9]=read(ram,0x0c03f790u,4);
goto P_0c03f5c0;
P_0c03f5c0: /* original a052, guest PC 0x0c03f5c0 */
if(!s->budget--) { s->failed_pc=0x0c03f5c0u; return 0; }
tmp=read(ram,r[3],4);
r[11]=tmp;
goto P_0c03f668;
P_0c03f5c2: /* original 6b32, guest PC 0x0c03f5c2 */
if(!s->budget--) { s->failed_pc=0x0c03f5c2u; return 0; }
tmp=read(ram,r[3],4);
r[11]=tmp;
if(!vf3_matrix_family(0x0c03f5c4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f5c4u; return 0; } return 1;
P_0c03f5d0: /* original 6db3, guest PC 0x0c03f5d0 */
if(!s->budget--) { s->failed_pc=0x0c03f5d0u; return 0; }
r[13]=r[11];
goto P_0c03f5d2;
P_0c03f5d2: /* original 63e2, guest PC 0x0c03f5d2 */
if(!s->budget--) { s->failed_pc=0x0c03f5d2u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03f5d4;
P_0c03f5d4: /* original 4d08, guest PC 0x0c03f5d4 */
if(!s->budget--) { s->failed_pc=0x0c03f5d4u; return 0; }
r[13]<<=2;
goto P_0c03f5d6;
P_0c03f5d6: /* original 4d00, guest PC 0x0c03f5d6 */
if(!s->budget--) { s->failed_pc=0x0c03f5d6u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c03f5d8;
P_0c03f5d8: /* original 33dc, guest PC 0x0c03f5d8 */
if(!s->budget--) { s->failed_pc=0x0c03f5d8u; return 0; }
r[3]+=r[13];
goto P_0c03f5da;
P_0c03f5da: /* original 6232, guest PC 0x0c03f5da */
if(!s->budget--) { s->failed_pc=0x0c03f5dau; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c03f5dc;
P_0c03f5dc: /* original 2228, guest PC 0x0c03f5dc */
if(!s->budget--) { s->failed_pc=0x0c03f5dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03f5de;
P_0c03f5de: /* original 8f09, guest PC 0x0c03f5de */
if(!s->budget--) { s->failed_pc=0x0c03f5deu; return 0; }
cond=r[17]&1u;
r[4]=r[11];
if(!cond) { goto P_0c03f5f4; }
goto P_0c03f5e2;
P_0c03f5e0: /* original 64b3, guest PC 0x0c03f5e0 */
if(!s->budget--) { s->failed_pc=0x0c03f5e0u; return 0; }
r[4]=r[11];
goto P_0c03f5e2;
P_0c03f5e2: /* original 62e2, guest PC 0x0c03f5e2 */
if(!s->budget--) { s->failed_pc=0x0c03f5e2u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f5e4;
P_0c03f5e4: /* original e104, guest PC 0x0c03f5e4 */
if(!s->budget--) { s->failed_pc=0x0c03f5e4u; return 0; }
r[1]=0x00000004u;
goto P_0c03f5e6;
P_0c03f5e6: /* original d370, guest PC 0x0c03f5e6 */
if(!s->budget--) { s->failed_pc=0x0c03f5e6u; return 0; }
r[3]=read(ram,0x0c03f7a8u,4);
goto P_0c03f5e8;
P_0c03f5e8: /* original 32dc, guest PC 0x0c03f5e8 */
if(!s->budget--) { s->failed_pc=0x0c03f5e8u; return 0; }
r[2]+=r[13];
goto P_0c03f5ea;
P_0c03f5ea: /* original 312c, guest PC 0x0c03f5ea */
if(!s->budget--) { s->failed_pc=0x0c03f5eau; return 0; }
r[1]+=r[2];
goto P_0c03f5ec;
P_0c03f5ec: /* original 430b, guest PC 0x0c03f5ec */
if(!s->budget--) { s->failed_pc=0x0c03f5ecu; return 0; }
target=r[3];
r[16]=code_base|0x0c03f5f0u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f5f0u) { target=s->pc; goto dispatch; }
goto P_0c03f5f0;
P_0c03f5ee: /* original 2f16, guest PC 0x0c03f5ee */
if(!s->budget--) { s->failed_pc=0x0c03f5eeu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5f0;
P_0c03f5f0: /* original 63f6, guest PC 0x0c03f5f0 */
if(!s->budget--) { s->failed_pc=0x0c03f5f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c03f5f2;
P_0c03f5f2: /* original 2302, guest PC 0x0c03f5f2 */
if(!s->budget--) { s->failed_pc=0x0c03f5f2u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c03f5f4;
P_0c03f5f4: /* original 62e2, guest PC 0x0c03f5f4 */
if(!s->budget--) { s->failed_pc=0x0c03f5f4u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f5f6;
P_0c03f5f6: /* original ea3c, guest PC 0x0c03f5f6 */
if(!s->budget--) { s->failed_pc=0x0c03f5f6u; return 0; }
r[10]=0x0000003cu;
goto P_0c03f5f8;
P_0c03f5f8: /* original 68b3, guest PC 0x0c03f5f8 */
if(!s->budget--) { s->failed_pc=0x0c03f5f8u; return 0; }
r[8]=r[11];
goto P_0c03f5fa;
P_0c03f5fa: /* original 4800, guest PC 0x0c03f5fa */
if(!s->budget--) { s->failed_pc=0x0c03f5fau; return 0; }
r[17]=(r[17]&~1u)|((r[8]>>31)!=0);
r[8]<<=1;
goto P_0c03f5fc;
P_0c03f5fc: /* original 32dc, guest PC 0x0c03f5fc */
if(!s->budget--) { s->failed_pc=0x0c03f5fcu; return 0; }
r[2]+=r[13];
goto P_0c03f5fe;
P_0c03f5fe: /* original 6322, guest PC 0x0c03f5fe */
if(!s->budget--) { s->failed_pc=0x0c03f5feu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f600;
P_0c03f600: /* original 7301, guest PC 0x0c03f600 */
if(!s->budget--) { s->failed_pc=0x0c03f600u; return 0; }
r[3]+=0x00000001u;
goto P_0c03f602;
P_0c03f602: /* original 2232, guest PC 0x0c03f602 */
if(!s->budget--) { s->failed_pc=0x0c03f602u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c03f604;
P_0c03f604: /* original 62e2, guest PC 0x0c03f604 */
if(!s->budget--) { s->failed_pc=0x0c03f604u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f606;
P_0c03f606: /* original 6192, guest PC 0x0c03f606 */
if(!s->budget--) { s->failed_pc=0x0c03f606u; return 0; }
tmp=read(ram,r[9],4);
r[1]=tmp;
goto P_0c03f608;
P_0c03f608: /* original 32dc, guest PC 0x0c03f608 */
if(!s->budget--) { s->failed_pc=0x0c03f608u; return 0; }
r[2]+=r[13];
goto P_0c03f60a;
P_0c03f60a: /* original 5d21, guest PC 0x0c03f60a */
if(!s->budget--) { s->failed_pc=0x0c03f60au; return 0; }
r[13]=read(ram,r[2]+4,4);
goto P_0c03f60c;
P_0c03f60c: /* original 381c, guest PC 0x0c03f60c */
if(!s->budget--) { s->failed_pc=0x0c03f60cu; return 0; }
r[8]+=r[1];
goto P_0c03f60e;
P_0c03f60e: /* original d267, guest PC 0x0c03f60e */
if(!s->budget--) { s->failed_pc=0x0c03f60eu; return 0; }
r[2]=read(ram,0x0c03f7acu,4);
goto P_0c03f610;
P_0c03f610: /* original 0da7, guest PC 0x0c03f610 */
if(!s->budget--) { s->failed_pc=0x0c03f610u; return 0; }
r[19]=r[13]*r[10];
goto P_0c03f612;
P_0c03f612: /* original 6081, guest PC 0x0c03f612 */
if(!s->budget--) { s->failed_pc=0x0c03f612u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[0]=tmp;
goto P_0c03f614;
P_0c03f614: /* original 6322, guest PC 0x0c03f614 */
if(!s->budget--) { s->failed_pc=0x0c03f614u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f616;
P_0c03f616: /* original 88ff, guest PC 0x0c03f616 */
if(!s->budget--) { s->failed_pc=0x0c03f616u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03f618;
P_0c03f618: /* original 0a1a, guest PC 0x0c03f618 */
if(!s->budget--) { s->failed_pc=0x0c03f618u; return 0; }
r[10]=r[19];
goto P_0c03f61a;
P_0c03f61a: /* original 8f03, guest PC 0x0c03f61a */
if(!s->budget--) { s->failed_pc=0x0c03f61au; return 0; }
cond=r[17]&1u;
r[10]+=r[3];
if(!cond) { goto P_0c03f624; }
goto P_0c03f61e;
P_0c03f61c: /* original 3a3c, guest PC 0x0c03f61c */
if(!s->budget--) { s->failed_pc=0x0c03f61cu; return 0; }
r[10]+=r[3];
goto P_0c03f61e;
P_0c03f61e: /* original b367, guest PC 0x0c03f61e */
if(!s->budget--) { s->failed_pc=0x0c03f61eu; return 0; }
target=code_base|0x0c03fcf0u; r[16]=code_base|0x0c03f622u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f622u) { target=s->pc; goto dispatch; }
goto P_0c03f622;
P_0c03f620: /* original 0009, guest PC 0x0c03f620 */
if(!s->budget--) { s->failed_pc=0x0c03f620u; return 0; }
goto P_0c03f622;
P_0c03f622: /* original 2801, guest PC 0x0c03f622 */
if(!s->budget--) { s->failed_pc=0x0c03f622u; return 0; }
write(ram,r[8],r[0],2);
goto P_0c03f624;
P_0c03f624: /* original 60b3, guest PC 0x0c03f624 */
if(!s->budget--) { s->failed_pc=0x0c03f624u; return 0; }
r[0]=r[11];
goto P_0c03f626;
P_0c03f626: /* original 0009, guest PC 0x0c03f626 */
if(!s->budget--) { s->failed_pc=0x0c03f626u; return 0; }
goto P_0c03f628;
P_0c03f628: /* original 6392, guest PC 0x0c03f628 */
if(!s->budget--) { s->failed_pc=0x0c03f628u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c03f62a;
P_0c03f62a: /* original 4000, guest PC 0x0c03f62a */
if(!s->budget--) { s->failed_pc=0x0c03f62au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c03f62c;
P_0c03f62c: /* original 083d, guest PC 0x0c03f62c */
if(!s->budget--) { s->failed_pc=0x0c03f62cu; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c03f62e;
P_0c03f62e: /* original 53ab, guest PC 0x0c03f62e */
if(!s->budget--) { s->failed_pc=0x0c03f62eu; return 0; }
r[3]=read(ram,r[10]+44,4);
goto P_0c03f630;
P_0c03f630: /* original 2338, guest PC 0x0c03f630 */
if(!s->budget--) { s->failed_pc=0x0c03f630u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03f632;
P_0c03f632: /* original 8b0b, guest PC 0x0c03f632 */
if(!s->budget--) { s->failed_pc=0x0c03f632u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f64c; }
goto P_0c03f634;
P_0c03f634: /* original d35e, guest PC 0x0c03f634 */
if(!s->budget--) { s->failed_pc=0x0c03f634u; return 0; }
r[3]=read(ram,0x0c03f7b0u,4);
goto P_0c03f636;
P_0c03f636: /* original 65d3, guest PC 0x0c03f636 */
if(!s->budget--) { s->failed_pc=0x0c03f636u; return 0; }
r[5]=r[13];
goto P_0c03f638;
P_0c03f638: /* original 56c2, guest PC 0x0c03f638 */
if(!s->budget--) { s->failed_pc=0x0c03f638u; return 0; }
r[6]=read(ram,r[12]+8,4);
goto P_0c03f63a;
P_0c03f63a: /* original 430b, guest PC 0x0c03f63a */
if(!s->budget--) { s->failed_pc=0x0c03f63au; return 0; }
target=r[3];
r[16]=code_base|0x0c03f63eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f63eu) { target=s->pc; goto dispatch; }
goto P_0c03f63e;
P_0c03f63c: /* original 64c3, guest PC 0x0c03f63c */
if(!s->budget--) { s->failed_pc=0x0c03f63cu; return 0; }
r[4]=r[12];
goto P_0c03f63e;
P_0c03f63e: /* original 62f2, guest PC 0x0c03f63e */
if(!s->budget--) { s->failed_pc=0x0c03f63eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c03f640;
P_0c03f640: /* original 220b, guest PC 0x0c03f640 */
if(!s->budget--) { s->failed_pc=0x0c03f640u; return 0; }
r[2]|=r[0];
goto P_0c03f642;
P_0c03f642: /* original 2f22, guest PC 0x0c03f642 */
if(!s->budget--) { s->failed_pc=0x0c03f642u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c03f644;
P_0c03f644: /* original d35b, guest PC 0x0c03f644 */
if(!s->budget--) { s->failed_pc=0x0c03f644u; return 0; }
r[3]=read(ram,0x0c03f7b4u,4);
goto P_0c03f646;
P_0c03f646: /* original 430b, guest PC 0x0c03f646 */
if(!s->budget--) { s->failed_pc=0x0c03f646u; return 0; }
target=r[3];
r[16]=code_base|0x0c03f64au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f64au) { target=s->pc; goto dispatch; }
goto P_0c03f64a;
P_0c03f648: /* original 64d3, guest PC 0x0c03f648 */
if(!s->budget--) { s->failed_pc=0x0c03f648u; return 0; }
r[4]=r[13];
goto P_0c03f64a;
P_0c03f64a: /* original 1ade, guest PC 0x0c03f64a */
if(!s->budget--) { s->failed_pc=0x0c03f64au; return 0; }
write(ram,r[10]+56,r[13],4);
goto P_0c03f64c;
P_0c03f64c: /* original d253, guest PC 0x0c03f64c */
if(!s->budget--) { s->failed_pc=0x0c03f64cu; return 0; }
r[2]=read(ram,0x0c03f79cu,4);
goto P_0c03f64e;
P_0c03f64e: /* original 6483, guest PC 0x0c03f64e */
if(!s->budget--) { s->failed_pc=0x0c03f64eu; return 0; }
r[4]=r[8];
goto P_0c03f650;
P_0c03f650: /* original 4408, guest PC 0x0c03f650 */
if(!s->budget--) { s->failed_pc=0x0c03f650u; return 0; }
r[4]<<=2;
goto P_0c03f652;
P_0c03f652: /* original 65d3, guest PC 0x0c03f652 */
if(!s->budget--) { s->failed_pc=0x0c03f652u; return 0; }
r[5]=r[13];
goto P_0c03f654;
P_0c03f654: /* original 6322, guest PC 0x0c03f654 */
if(!s->budget--) { s->failed_pc=0x0c03f654u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f656;
P_0c03f656: /* original 4408, guest PC 0x0c03f656 */
if(!s->budget--) { s->failed_pc=0x0c03f656u; return 0; }
r[4]<<=2;
goto P_0c03f658;
P_0c03f658: /* original 4400, guest PC 0x0c03f658 */
if(!s->budget--) { s->failed_pc=0x0c03f658u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c03f65a;
P_0c03f65a: /* original b319, guest PC 0x0c03f65a */
if(!s->budget--) { s->failed_pc=0x0c03f65au; return 0; }
target=code_base|0x0c03fc90u; r[16]=code_base|0x0c03f65eu;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f65eu) { target=s->pc; goto dispatch; }
goto P_0c03f65e;
P_0c03f65c: /* original 343c, guest PC 0x0c03f65c */
if(!s->budget--) { s->failed_pc=0x0c03f65cu; return 0; }
r[4]+=r[3];
goto P_0c03f65e;
P_0c03f65e: /* original 53ab, guest PC 0x0c03f65e */
if(!s->budget--) { s->failed_pc=0x0c03f65eu; return 0; }
r[3]=read(ram,r[10]+44,4);
goto P_0c03f660;
P_0c03f660: /* original 7b01, guest PC 0x0c03f660 */
if(!s->budget--) { s->failed_pc=0x0c03f660u; return 0; }
r[11]+=0x00000001u;
goto P_0c03f662;
P_0c03f662: /* original 7c10, guest PC 0x0c03f662 */
if(!s->budget--) { s->failed_pc=0x0c03f662u; return 0; }
r[12]+=0x00000010u;
goto P_0c03f664;
P_0c03f664: /* original 7301, guest PC 0x0c03f664 */
if(!s->budget--) { s->failed_pc=0x0c03f664u; return 0; }
r[3]+=0x00000001u;
goto P_0c03f666;
P_0c03f666: /* original 1a3b, guest PC 0x0c03f666 */
if(!s->budget--) { s->failed_pc=0x0c03f666u; return 0; }
write(ram,r[10]+44,r[3],4);
goto P_0c03f668;
P_0c03f668: /* original 50c1, guest PC 0x0c03f668 */
if(!s->budget--) { s->failed_pc=0x0c03f668u; return 0; }
r[0]=read(ram,r[12]+4,4);
goto P_0c03f66a;
P_0c03f66a: /* original 88ff, guest PC 0x0c03f66a */
if(!s->budget--) { s->failed_pc=0x0c03f66au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03f66c;
P_0c03f66c: /* original 8bb0, guest PC 0x0c03f66c */
if(!s->budget--) { s->failed_pc=0x0c03f66cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f5d0; }
goto P_0c03f66e;
P_0c03f66e: /* original 60f2, guest PC 0x0c03f66e */
if(!s->budget--) { s->failed_pc=0x0c03f66eu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c03f670;
P_0c03f670: /* original 7f04, guest PC 0x0c03f670 */
if(!s->budget--) { s->failed_pc=0x0c03f670u; return 0; }
r[15]+=0x00000004u;
goto P_0c03f672;
P_0c03f672: /* original 4f16, guest PC 0x0c03f672 */
if(!s->budget--) { s->failed_pc=0x0c03f672u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f674;
P_0c03f674: /* original 4f26, guest PC 0x0c03f674 */
if(!s->budget--) { s->failed_pc=0x0c03f674u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f676;
P_0c03f676: /* original 68f6, guest PC 0x0c03f676 */
if(!s->budget--) { s->failed_pc=0x0c03f676u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03f678;
P_0c03f678: /* original 69f6, guest PC 0x0c03f678 */
if(!s->budget--) { s->failed_pc=0x0c03f678u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03f67a;
P_0c03f67a: /* original 6af6, guest PC 0x0c03f67a */
if(!s->budget--) { s->failed_pc=0x0c03f67au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03f67c;
P_0c03f67c: /* original 6bf6, guest PC 0x0c03f67c */
if(!s->budget--) { s->failed_pc=0x0c03f67cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f67e;
P_0c03f67e: /* original 6cf6, guest PC 0x0c03f67e */
if(!s->budget--) { s->failed_pc=0x0c03f67eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f680;
P_0c03f680: /* original 6df6, guest PC 0x0c03f680 */
if(!s->budget--) { s->failed_pc=0x0c03f680u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f682;
P_0c03f682: /* original 000b, guest PC 0x0c03f682 */
if(!s->budget--) { s->failed_pc=0x0c03f682u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f684: /* original 6ef6, guest PC 0x0c03f684 */
if(!s->budget--) { s->failed_pc=0x0c03f684u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03f686u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f686u; return 0; } return 1;
P_0c03fc90: /* original 2fe6, guest PC 0x0c03fc90 */
if(!s->budget--) { s->failed_pc=0x0c03fc90u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fc92;
P_0c03fc92: /* original 6e43, guest PC 0x0c03fc92 */
if(!s->budget--) { s->failed_pc=0x0c03fc92u; return 0; }
r[14]=r[4];
goto P_0c03fc94;
P_0c03fc94: /* original d32d, guest PC 0x0c03fc94 */
if(!s->budget--) { s->failed_pc=0x0c03fc94u; return 0; }
r[3]=read(ram,0x0c03fd4cu,4);
goto P_0c03fc96;
P_0c03fc96: /* original 4f22, guest PC 0x0c03fc96 */
if(!s->budget--) { s->failed_pc=0x0c03fc96u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03fc98;
P_0c03fc98: /* original 2e32, guest PC 0x0c03fc98 */
if(!s->budget--) { s->failed_pc=0x0c03fc98u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c03fc9a;
P_0c03fc9a: /* original d22d, guest PC 0x0c03fc9a */
if(!s->budget--) { s->failed_pc=0x0c03fc9au; return 0; }
r[2]=read(ram,0x0c03fd50u,4);
goto P_0c03fc9c;
P_0c03fc9c: /* original 1e21, guest PC 0x0c03fc9c */
if(!s->budget--) { s->failed_pc=0x0c03fc9cu; return 0; }
write(ram,r[14]+4,r[2],4);
goto P_0c03fc9e;
P_0c03fc9e: /* original e200, guest PC 0x0c03fc9e */
if(!s->budget--) { s->failed_pc=0x0c03fc9eu; return 0; }
r[2]=0x00000000u;
goto P_0c03fca0;
P_0c03fca0: /* original 9352, guest PC 0x0c03fca0 */
if(!s->budget--) { s->failed_pc=0x0c03fca0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03fd48u,2);
goto P_0c03fca2;
P_0c03fca2: /* original 1e32, guest PC 0x0c03fca2 */
if(!s->budget--) { s->failed_pc=0x0c03fca2u; return 0; }
write(ram,r[14]+8,r[3],4);
goto P_0c03fca4;
P_0c03fca4: /* original 1e23, guest PC 0x0c03fca4 */
if(!s->budget--) { s->failed_pc=0x0c03fca4u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c03fca6;
P_0c03fca6: /* original d32b, guest PC 0x0c03fca6 */
if(!s->budget--) { s->failed_pc=0x0c03fca6u; return 0; }
r[3]=read(ram,0x0c03fd54u,4);
goto P_0c03fca8;
P_0c03fca8: /* original 430b, guest PC 0x0c03fca8 */
if(!s->budget--) { s->failed_pc=0x0c03fca8u; return 0; }
target=r[3];
r[16]=code_base|0x0c03fcacu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03fcacu) { target=s->pc; goto dispatch; }
goto P_0c03fcac;
P_0c03fcaa: /* original 64e3, guest PC 0x0c03fcaa */
if(!s->budget--) { s->failed_pc=0x0c03fcaau; return 0; }
r[4]=r[14];
goto P_0c03fcac;
P_0c03fcac: /* original 55e3, guest PC 0x0c03fcac */
if(!s->budget--) { s->failed_pc=0x0c03fcacu; return 0; }
r[5]=read(ram,r[14]+12,4);
goto P_0c03fcae;
P_0c03fcae: /* original e3e5, guest PC 0x0c03fcae */
if(!s->budget--) { s->failed_pc=0x0c03fcaeu; return 0; }
r[3]=0xffffffe5u;
goto P_0c03fcb0;
P_0c03fcb0: /* original e407, guest PC 0x0c03fcb0 */
if(!s->budget--) { s->failed_pc=0x0c03fcb0u; return 0; }
r[4]=0x00000007u;
goto P_0c03fcb2;
P_0c03fcb2: /* original 453d, guest PC 0x0c03fcb2 */
if(!s->budget--) { s->failed_pc=0x0c03fcb2u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c03fcb4;
P_0c03fcb4: /* original 2549, guest PC 0x0c03fcb4 */
if(!s->budget--) { s->failed_pc=0x0c03fcb4u; return 0; }
r[5]&=r[4];
goto P_0c03fcb6;
P_0c03fcb6: /* original 2558, guest PC 0x0c03fcb6 */
if(!s->budget--) { s->failed_pc=0x0c03fcb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c03fcb8;
P_0c03fcb8: /* original e200, guest PC 0x0c03fcb8 */
if(!s->budget--) { s->failed_pc=0x0c03fcb8u; return 0; }
r[2]=0x00000000u;
goto P_0c03fcba;
P_0c03fcba: /* original 8d04, guest PC 0x0c03fcba */
if(!s->budget--) { s->failed_pc=0x0c03fcbau; return 0; }
cond=r[17]&1u;
write(ram,r[14]+20,r[2],4);
if(cond) { goto P_0c03fcc6; }
goto P_0c03fcbe;
P_0c03fcbc: /* original 1e25, guest PC 0x0c03fcbc */
if(!s->budget--) { s->failed_pc=0x0c03fcbcu; return 0; }
write(ram,r[14]+20,r[2],4);
goto P_0c03fcbe;
P_0c03fcbe: /* original 6053, guest PC 0x0c03fcbe */
if(!s->budget--) { s->failed_pc=0x0c03fcbeu; return 0; }
r[0]=r[5];
goto P_0c03fcc0;
P_0c03fcc0: /* original 0009, guest PC 0x0c03fcc0 */
if(!s->budget--) { s->failed_pc=0x0c03fcc0u; return 0; }
goto P_0c03fcc2;
P_0c03fcc2: /* original 8802, guest PC 0x0c03fcc2 */
if(!s->budget--) { s->failed_pc=0x0c03fcc2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c03fcc4;
P_0c03fcc4: /* original 8b01, guest PC 0x0c03fcc4 */
if(!s->budget--) { s->failed_pc=0x0c03fcc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fcca; }
goto P_0c03fcc6;
P_0c03fcc6: /* original e301, guest PC 0x0c03fcc6 */
if(!s->budget--) { s->failed_pc=0x0c03fcc6u; return 0; }
r[3]=0x00000001u;
goto P_0c03fcc8;
P_0c03fcc8: /* original 1e35, guest PC 0x0c03fcc8 */
if(!s->budget--) { s->failed_pc=0x0c03fcc8u; return 0; }
write(ram,r[14]+20,r[3],4);
goto P_0c03fcca;
P_0c03fcca: /* original 50e2, guest PC 0x0c03fcca */
if(!s->budget--) { s->failed_pc=0x0c03fccau; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c03fccc;
P_0c03fccc: /* original d522, guest PC 0x0c03fccc */
if(!s->budget--) { s->failed_pc=0x0c03fcccu; return 0; }
r[5]=read(ram,0x0c03fd58u,4);
goto P_0c03fcce;
P_0c03fcce: /* original 4009, guest PC 0x0c03fcce */
if(!s->budget--) { s->failed_pc=0x0c03fcceu; return 0; }
r[0]>>=2;
goto P_0c03fcd0;
P_0c03fcd0: /* original 4001, guest PC 0x0c03fcd0 */
if(!s->budget--) { s->failed_pc=0x0c03fcd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c03fcd2;
P_0c03fcd2: /* original 2049, guest PC 0x0c03fcd2 */
if(!s->budget--) { s->failed_pc=0x0c03fcd2u; return 0; }
r[0]&=r[4];
goto P_0c03fcd4;
P_0c03fcd4: /* original 4008, guest PC 0x0c03fcd4 */
if(!s->budget--) { s->failed_pc=0x0c03fcd4u; return 0; }
r[0]<<=2;
goto P_0c03fcd6;
P_0c03fcd6: /* original f356, guest PC 0x0c03fcd6 */
if(!s->budget--) { s->failed_pc=0x0c03fcd6u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c03fcd8;
P_0c03fcd8: /* original e018, guest PC 0x0c03fcd8 */
if(!s->budget--) { s->failed_pc=0x0c03fcd8u; return 0; }
r[0]=0x00000018u;
goto P_0c03fcda;
P_0c03fcda: /* original 4f26, guest PC 0x0c03fcda */
if(!s->budget--) { s->failed_pc=0x0c03fcdau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03fcdc;
P_0c03fcdc: /* original fe37, guest PC 0x0c03fcdc */
if(!s->budget--) { s->failed_pc=0x0c03fcdcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c03fcde;
P_0c03fcde: /* original 50e2, guest PC 0x0c03fcde */
if(!s->budget--) { s->failed_pc=0x0c03fcdeu; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c03fce0;
P_0c03fce0: /* original 2049, guest PC 0x0c03fce0 */
if(!s->budget--) { s->failed_pc=0x0c03fce0u; return 0; }
r[0]&=r[4];
goto P_0c03fce2;
P_0c03fce2: /* original 4008, guest PC 0x0c03fce2 */
if(!s->budget--) { s->failed_pc=0x0c03fce2u; return 0; }
r[0]<<=2;
goto P_0c03fce4;
P_0c03fce4: /* original f356, guest PC 0x0c03fce4 */
if(!s->budget--) { s->failed_pc=0x0c03fce4u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c03fce6;
P_0c03fce6: /* original e01c, guest PC 0x0c03fce6 */
if(!s->budget--) { s->failed_pc=0x0c03fce6u; return 0; }
r[0]=0x0000001cu;
goto P_0c03fce8;
P_0c03fce8: /* original fe37, guest PC 0x0c03fce8 */
if(!s->budget--) { s->failed_pc=0x0c03fce8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c03fcea;
P_0c03fcea: /* original 000b, guest PC 0x0c03fcea */
if(!s->budget--) { s->failed_pc=0x0c03fceau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03fcec: /* original 6ef6, guest PC 0x0c03fcec */
if(!s->budget--) { s->failed_pc=0x0c03fcecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03fceeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03fceeu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
