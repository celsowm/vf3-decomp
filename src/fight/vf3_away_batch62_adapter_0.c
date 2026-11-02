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
int vf3_away_batch62_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03c1c0u: goto P_0c03c1c0;
case 0x0c03c1c2u: goto P_0c03c1c2;
case 0x0c03c1c4u: goto P_0c03c1c4;
case 0x0c03c1c6u: goto P_0c03c1c6;
case 0x0c03c1c8u: goto P_0c03c1c8;
case 0x0c03c1cau: goto P_0c03c1ca;
case 0x0c03c1ccu: goto P_0c03c1cc;
case 0x0c03c1ceu: goto P_0c03c1ce;
case 0x0c03c1d0u: goto P_0c03c1d0;
case 0x0c03c1d2u: goto P_0c03c1d2;
case 0x0c03c1d4u: goto P_0c03c1d4;
case 0x0c03c1d6u: goto P_0c03c1d6;
case 0x0c03c1d8u: goto P_0c03c1d8;
case 0x0c03c1dau: goto P_0c03c1da;
case 0x0c03c1dcu: goto P_0c03c1dc;
case 0x0c03c1deu: goto P_0c03c1de;
case 0x0c03c1e0u: goto P_0c03c1e0;
case 0x0c03c1e2u: goto P_0c03c1e2;
case 0x0c03c1e4u: goto P_0c03c1e4;
case 0x0c03c1e6u: goto P_0c03c1e6;
case 0x0c03c1e8u: goto P_0c03c1e8;
case 0x0c03c1eau: goto P_0c03c1ea;
case 0x0c03c1ecu: goto P_0c03c1ec;
case 0x0c03c1eeu: goto P_0c03c1ee;
case 0x0c03c1f0u: goto P_0c03c1f0;
case 0x0c03c1f2u: goto P_0c03c1f2;
case 0x0c03c1f4u: goto P_0c03c1f4;
case 0x0c03c1f6u: goto P_0c03c1f6;
case 0x0c03c1f8u: goto P_0c03c1f8;
case 0x0c03c1fau: goto P_0c03c1fa;
case 0x0c03c1fcu: goto P_0c03c1fc;
case 0x0c03c1feu: goto P_0c03c1fe;
case 0x0c03c200u: goto P_0c03c200;
case 0x0c03c202u: goto P_0c03c202;
case 0x0c03c204u: goto P_0c03c204;
case 0x0c03c206u: goto P_0c03c206;
case 0x0c03c208u: goto P_0c03c208;
case 0x0c03c5b0u: goto P_0c03c5b0;
case 0x0c03c5b2u: goto P_0c03c5b2;
case 0x0c03c5b4u: goto P_0c03c5b4;
case 0x0c03c5b6u: goto P_0c03c5b6;
case 0x0c03c5b8u: goto P_0c03c5b8;
case 0x0c03c5bau: goto P_0c03c5ba;
case 0x0c03c5bcu: goto P_0c03c5bc;
case 0x0c03c5beu: goto P_0c03c5be;
case 0x0c03c5c0u: goto P_0c03c5c0;
case 0x0c03c5c2u: goto P_0c03c5c2;
case 0x0c03c5c4u: goto P_0c03c5c4;
case 0x0c03c5c6u: goto P_0c03c5c6;
case 0x0c03c5c8u: goto P_0c03c5c8;
case 0x0c03c5cau: goto P_0c03c5ca;
case 0x0c03c5ccu: goto P_0c03c5cc;
case 0x0c03c5ceu: goto P_0c03c5ce;
case 0x0c03c5d0u: goto P_0c03c5d0;
case 0x0c03c5d2u: goto P_0c03c5d2;
case 0x0c03c5d4u: goto P_0c03c5d4;
case 0x0c03c5d6u: goto P_0c03c5d6;
case 0x0c03c5d8u: goto P_0c03c5d8;
case 0x0c03c5dau: goto P_0c03c5da;
case 0x0c03c5dcu: goto P_0c03c5dc;
case 0x0c03c5deu: goto P_0c03c5de;
case 0x0c03c5e0u: goto P_0c03c5e0;
case 0x0c03c5e2u: goto P_0c03c5e2;
case 0x0c03c5e4u: goto P_0c03c5e4;
case 0x0c03c5e6u: goto P_0c03c5e6;
case 0x0c03c5e8u: goto P_0c03c5e8;
case 0x0c03c5eau: goto P_0c03c5ea;
case 0x0c03d260u: goto P_0c03d260;
case 0x0c03d262u: goto P_0c03d262;
case 0x0c03d264u: goto P_0c03d264;
case 0x0c03d266u: goto P_0c03d266;
case 0x0c03d268u: goto P_0c03d268;
case 0x0c03d26au: goto P_0c03d26a;
case 0x0c03d26cu: goto P_0c03d26c;
case 0x0c03d26eu: goto P_0c03d26e;
case 0x0c03d270u: goto P_0c03d270;
case 0x0c03d272u: goto P_0c03d272;
case 0x0c03d274u: goto P_0c03d274;
case 0x0c03d276u: goto P_0c03d276;
case 0x0c03d278u: goto P_0c03d278;
case 0x0c03d27au: goto P_0c03d27a;
case 0x0c03d27cu: goto P_0c03d27c;
case 0x0c03d27eu: goto P_0c03d27e;
case 0x0c03dd00u: goto P_0c03dd00;
case 0x0c03dd02u: goto P_0c03dd02;
case 0x0c03dd04u: goto P_0c03dd04;
case 0x0c03dd06u: goto P_0c03dd06;
case 0x0c03dd08u: goto P_0c03dd08;
case 0x0c03dd30u: goto P_0c03dd30;
case 0x0c03dd32u: goto P_0c03dd32;
case 0x0c03dd34u: goto P_0c03dd34;
case 0x0c03dd36u: goto P_0c03dd36;
case 0x0c03dd38u: goto P_0c03dd38;
case 0x0c03dd3au: goto P_0c03dd3a;
case 0x0c03dd3cu: goto P_0c03dd3c;
case 0x0c03dd3eu: goto P_0c03dd3e;
case 0x0c03dd40u: goto P_0c03dd40;
case 0x0c03dd42u: goto P_0c03dd42;
case 0x0c03dd44u: goto P_0c03dd44;
case 0x0c03dd46u: goto P_0c03dd46;
case 0x0c03dd48u: goto P_0c03dd48;
case 0x0c03dd4au: goto P_0c03dd4a;
case 0x0c03dd4cu: goto P_0c03dd4c;
case 0x0c03dd4eu: goto P_0c03dd4e;
case 0x0c03dd50u: goto P_0c03dd50;
case 0x0c03dd52u: goto P_0c03dd52;
case 0x0c03dd54u: goto P_0c03dd54;
case 0x0c03dd56u: goto P_0c03dd56;
case 0x0c03dd58u: goto P_0c03dd58;
case 0x0c03dd5au: goto P_0c03dd5a;
case 0x0c03dd5cu: goto P_0c03dd5c;
case 0x0c03dd5eu: goto P_0c03dd5e;
case 0x0c03dd60u: goto P_0c03dd60;
case 0x0c03dd62u: goto P_0c03dd62;
case 0x0c03dd64u: goto P_0c03dd64;
case 0x0c03dd66u: goto P_0c03dd66;
case 0x0c03dd68u: goto P_0c03dd68;
case 0x0c03dd6au: goto P_0c03dd6a;
case 0x0c03dd6cu: goto P_0c03dd6c;
case 0x0c03dd6eu: goto P_0c03dd6e;
case 0x0c03dd70u: goto P_0c03dd70;
case 0x0c03dd72u: goto P_0c03dd72;
case 0x0c03dd74u: goto P_0c03dd74;
case 0x0c03dd76u: goto P_0c03dd76;
case 0x0c03dd78u: goto P_0c03dd78;
case 0x0c03dd7au: goto P_0c03dd7a;
case 0x0c03dd7cu: goto P_0c03dd7c;
case 0x0c03dd7eu: goto P_0c03dd7e;
case 0x0c03dd80u: goto P_0c03dd80;
case 0x0c03dd82u: goto P_0c03dd82;
case 0x0c03dd84u: goto P_0c03dd84;
case 0x0c03dd86u: goto P_0c03dd86;
case 0x0c03dd88u: goto P_0c03dd88;
case 0x0c03dd8au: goto P_0c03dd8a;
case 0x0c03dd8cu: goto P_0c03dd8c;
case 0x0c03dd8eu: goto P_0c03dd8e;
case 0x0c03dd90u: goto P_0c03dd90;
case 0x0c03dd92u: goto P_0c03dd92;
case 0x0c03dd94u: goto P_0c03dd94;
case 0x0c03dd96u: goto P_0c03dd96;
case 0x0c03ecb0u: goto P_0c03ecb0;
case 0x0c03ecb2u: goto P_0c03ecb2;
case 0x0c03ecb4u: goto P_0c03ecb4;
case 0x0c03ecb6u: goto P_0c03ecb6;
case 0x0c03ecb8u: goto P_0c03ecb8;
case 0x0c03ecbau: goto P_0c03ecba;
case 0x0c03ecbcu: goto P_0c03ecbc;
case 0x0c03ecbeu: goto P_0c03ecbe;
case 0x0c03ecc0u: goto P_0c03ecc0;
case 0x0c03ecc2u: goto P_0c03ecc2;
case 0x0c03ecc4u: goto P_0c03ecc4;
case 0x0c03ecc6u: goto P_0c03ecc6;
case 0x0c03ecc8u: goto P_0c03ecc8;
case 0x0c03eccau: goto P_0c03ecca;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c03c1c0: /* original fffb, guest PC 0x0c03c1c0 */
if(!s->budget--) { s->failed_pc=0x0c03c1c0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c03c1c2;
P_0c03c1c2: /* original ffeb, guest PC 0x0c03c1c2 */
if(!s->budget--) { s->failed_pc=0x0c03c1c2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c03c1c4;
P_0c03c1c4: /* original ffdb, guest PC 0x0c03c1c4 */
if(!s->budget--) { s->failed_pc=0x0c03c1c4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c03c1c6;
P_0c03c1c6: /* original ffcb, guest PC 0x0c03c1c6 */
if(!s->budget--) { s->failed_pc=0x0c03c1c6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c03c1c8;
P_0c03c1c8: /* original f049, guest PC 0x0c03c1c8 */
if(!s->budget--) { s->failed_pc=0x0c03c1c8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1ca;
P_0c03c1ca: /* original f149, guest PC 0x0c03c1ca */
if(!s->budget--) { s->failed_pc=0x0c03c1cau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1cc;
P_0c03c1cc: /* original f249, guest PC 0x0c03c1cc */
if(!s->budget--) { s->failed_pc=0x0c03c1ccu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1ce;
P_0c03c1ce: /* original f349, guest PC 0x0c03c1ce */
if(!s->budget--) { s->failed_pc=0x0c03c1ceu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1d0;
P_0c03c1d0: /* original f449, guest PC 0x0c03c1d0 */
if(!s->budget--) { s->failed_pc=0x0c03c1d0u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1d2;
P_0c03c1d2: /* original f549, guest PC 0x0c03c1d2 */
if(!s->budget--) { s->failed_pc=0x0c03c1d2u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1d4;
P_0c03c1d4: /* original f649, guest PC 0x0c03c1d4 */
if(!s->budget--) { s->failed_pc=0x0c03c1d4u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1d6;
P_0c03c1d6: /* original f749, guest PC 0x0c03c1d6 */
if(!s->budget--) { s->failed_pc=0x0c03c1d6u; return 0; }
vf3_matrix_load(s,ram,7,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1d8;
P_0c03c1d8: /* original f849, guest PC 0x0c03c1d8 */
if(!s->budget--) { s->failed_pc=0x0c03c1d8u; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1da;
P_0c03c1da: /* original f949, guest PC 0x0c03c1da */
if(!s->budget--) { s->failed_pc=0x0c03c1dau; return 0; }
vf3_matrix_load(s,ram,9,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1dc;
P_0c03c1dc: /* original fa49, guest PC 0x0c03c1dc */
if(!s->budget--) { s->failed_pc=0x0c03c1dcu; return 0; }
vf3_matrix_load(s,ram,10,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1de;
P_0c03c1de: /* original fb49, guest PC 0x0c03c1de */
if(!s->budget--) { s->failed_pc=0x0c03c1deu; return 0; }
vf3_matrix_load(s,ram,11,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1e0;
P_0c03c1e0: /* original fc49, guest PC 0x0c03c1e0 */
if(!s->budget--) { s->failed_pc=0x0c03c1e0u; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1e2;
P_0c03c1e2: /* original fd49, guest PC 0x0c03c1e2 */
if(!s->budget--) { s->failed_pc=0x0c03c1e2u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1e4;
P_0c03c1e4: /* original fe49, guest PC 0x0c03c1e4 */
if(!s->budget--) { s->failed_pc=0x0c03c1e4u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1e6;
P_0c03c1e6: /* original ff49, guest PC 0x0c03c1e6 */
if(!s->budget--) { s->failed_pc=0x0c03c1e6u; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1e8;
P_0c03c1e8: /* original fbfd, guest PC 0x0c03c1e8 */
if(!s->budget--) { s->failed_pc=0x0c03c1e8u; return 0; }
vf3_matrix_swap(s);
goto P_0c03c1ea;
P_0c03c1ea: /* original f1fd, guest PC 0x0c03c1ea */
if(!s->budget--) { s->failed_pc=0x0c03c1eau; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c03c1ec;
P_0c03c1ec: /* original f5fd, guest PC 0x0c03c1ec */
if(!s->budget--) { s->failed_pc=0x0c03c1ecu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c03c1ee;
P_0c03c1ee: /* original f9fd, guest PC 0x0c03c1ee */
if(!s->budget--) { s->failed_pc=0x0c03c1eeu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+8,r[18],fr+8)) goto unsupported;
goto P_0c03c1f0;
P_0c03c1f0: /* original fdfd, guest PC 0x0c03c1f0 */
if(!s->budget--) { s->failed_pc=0x0c03c1f0u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+12,r[18],fr+12)) goto unsupported;
goto P_0c03c1f2;
P_0c03c1f2: /* original fbfd, guest PC 0x0c03c1f2 */
if(!s->budget--) { s->failed_pc=0x0c03c1f2u; return 0; }
vf3_matrix_swap(s);
goto P_0c03c1f4;
P_0c03c1f4: /* original fcf9, guest PC 0x0c03c1f4 */
if(!s->budget--) { s->failed_pc=0x0c03c1f4u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1f6;
P_0c03c1f6: /* original fdf9, guest PC 0x0c03c1f6 */
if(!s->budget--) { s->failed_pc=0x0c03c1f6u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1f8;
P_0c03c1f8: /* original fef9, guest PC 0x0c03c1f8 */
if(!s->budget--) { s->failed_pc=0x0c03c1f8u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1fa;
P_0c03c1fa: /* original fff9, guest PC 0x0c03c1fa */
if(!s->budget--) { s->failed_pc=0x0c03c1fau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03c1fc;
P_0c03c1fc: /* original 000b, guest PC 0x0c03c1fc */
if(!s->budget--) { s->failed_pc=0x0c03c1fcu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03c1fe: /* original 0009, guest PC 0x0c03c1fe */
if(!s->budget--) { s->failed_pc=0x0c03c1feu; return 0; }
goto P_0c03c200;
P_0c03c200: /* original d491, guest PC 0x0c03c200 */
if(!s->budget--) { s->failed_pc=0x0c03c200u; return 0; }
r[4]=read(ram,0x0c03c448u,4);
goto P_0c03c202;
P_0c03c202: /* original d392, guest PC 0x0c03c202 */
if(!s->budget--) { s->failed_pc=0x0c03c202u; return 0; }
r[3]=read(ram,0x0c03c44cu,4);
goto P_0c03c204;
P_0c03c204: /* original 5442, guest PC 0x0c03c204 */
if(!s->budget--) { s->failed_pc=0x0c03c204u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c03c206;
P_0c03c206: /* original 432b, guest PC 0x0c03c206 */
if(!s->budget--) { s->failed_pc=0x0c03c206u; return 0; }
target=r[3];
r[4]+=0xffffffc0u;
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
P_0c03c208: /* original 74c0, guest PC 0x0c03c208 */
if(!s->budget--) { s->failed_pc=0x0c03c208u; return 0; }
r[4]+=0xffffffc0u;
if(!vf3_matrix_family(0x0c03c20au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03c20au; return 0; } return 1;
P_0c03c5b0: /* original fbfd, guest PC 0x0c03c5b0 */
if(!s->budget--) { s->failed_pc=0x0c03c5b0u; return 0; }
vf3_matrix_swap(s);
goto P_0c03c5b2;
P_0c03c5b2: /* original f38d, guest PC 0x0c03c5b2 */
if(!s->budget--) { s->failed_pc=0x0c03c5b2u; return 0; }
fr[3]=0;
goto P_0c03c5b4;
P_0c03c5b4: /* original fbb1, guest PC 0x0c03c5b4 */
if(!s->budget--) { s->failed_pc=0x0c03c5b4u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'-');
goto P_0c03c5b6;
P_0c03c5b6: /* original f78d, guest PC 0x0c03c5b6 */
if(!s->budget--) { s->failed_pc=0x0c03c5b6u; return 0; }
fr[7]=0;
goto P_0c03c5b8;
P_0c03c5b8: /* original ff9d, guest PC 0x0c03c5b8 */
if(!s->budget--) { s->failed_pc=0x0c03c5b8u; return 0; }
fr[15]=0x3f800000u;
goto P_0c03c5ba;
P_0c03c5ba: /* original f11d, guest PC 0x0c03c5ba */
if(!s->budget--) { s->failed_pc=0x0c03c5bau; return 0; }
r[53]=fr[1];
goto P_0c03c5bc;
P_0c03c5bc: /* original f3ed, guest PC 0x0c03c5bc */
if(!s->budget--) { s->failed_pc=0x0c03c5bcu; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c03c5be;
P_0c03c5be: /* original f14c, guest PC 0x0c03c5be */
if(!s->budget--) { s->failed_pc=0x0c03c5beu; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c03c5c0;
P_0c03c5c0: /* original f7ed, guest PC 0x0c03c5c0 */
if(!s->budget--) { s->failed_pc=0x0c03c5c0u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03c5c2;
P_0c03c5c2: /* original f40d, guest PC 0x0c03c5c2 */
if(!s->budget--) { s->failed_pc=0x0c03c5c2u; return 0; }
fr[4]=r[53];
goto P_0c03c5c4;
P_0c03c5c4: /* original fbed, guest PC 0x0c03c5c4 */
if(!s->budget--) { s->failed_pc=0x0c03c5c4u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c03c5c6;
P_0c03c5c6: /* original fc8d, guest PC 0x0c03c5c6 */
if(!s->budget--) { s->failed_pc=0x0c03c5c6u; return 0; }
fr[12]=0;
goto P_0c03c5c8;
P_0c03c5c8: /* original fee1, guest PC 0x0c03c5c8 */
if(!s->budget--) { s->failed_pc=0x0c03c5c8u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[14],r[18],'-');
goto P_0c03c5ca;
P_0c03c5ca: /* original fc31, guest PC 0x0c03c5ca */
if(!s->budget--) { s->failed_pc=0x0c03c5cau; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'-');
goto P_0c03c5cc;
P_0c03c5cc: /* original fd8d, guest PC 0x0c03c5cc */
if(!s->budget--) { s->failed_pc=0x0c03c5ccu; return 0; }
fr[13]=0;
goto P_0c03c5ce;
P_0c03c5ce: /* original fd71, guest PC 0x0c03c5ce */
if(!s->budget--) { s->failed_pc=0x0c03c5ceu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[7],r[18],'-');
goto P_0c03c5d0;
P_0c03c5d0: /* original f21d, guest PC 0x0c03c5d0 */
if(!s->budget--) { s->failed_pc=0x0c03c5d0u; return 0; }
r[53]=fr[2];
goto P_0c03c5d2;
P_0c03c5d2: /* original feb1, guest PC 0x0c03c5d2 */
if(!s->budget--) { s->failed_pc=0x0c03c5d2u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[11],r[18],'-');
goto P_0c03c5d4;
P_0c03c5d4: /* original f28c, guest PC 0x0c03c5d4 */
if(!s->budget--) { s->failed_pc=0x0c03c5d4u; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c03c5d6;
P_0c03c5d6: /* original f331, guest PC 0x0c03c5d6 */
if(!s->budget--) { s->failed_pc=0x0c03c5d6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[3],r[18],'-');
goto P_0c03c5d8;
P_0c03c5d8: /* original f80d, guest PC 0x0c03c5d8 */
if(!s->budget--) { s->failed_pc=0x0c03c5d8u; return 0; }
fr[8]=r[53];
goto P_0c03c5da;
P_0c03c5da: /* original f771, guest PC 0x0c03c5da */
if(!s->budget--) { s->failed_pc=0x0c03c5dau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[7],r[18],'-');
goto P_0c03c5dc;
P_0c03c5dc: /* original f61d, guest PC 0x0c03c5dc */
if(!s->budget--) { s->failed_pc=0x0c03c5dcu; return 0; }
r[53]=fr[6];
goto P_0c03c5de;
P_0c03c5de: /* original fbb1, guest PC 0x0c03c5de */
if(!s->budget--) { s->failed_pc=0x0c03c5deu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'-');
goto P_0c03c5e0;
P_0c03c5e0: /* original f69c, guest PC 0x0c03c5e0 */
if(!s->budget--) { s->failed_pc=0x0c03c5e0u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c03c5e2;
P_0c03c5e2: /* original f90d, guest PC 0x0c03c5e2 */
if(!s->budget--) { s->failed_pc=0x0c03c5e2u; return 0; }
fr[9]=r[53];
goto P_0c03c5e4;
P_0c03c5e4: /* original fbfd, guest PC 0x0c03c5e4 */
if(!s->budget--) { s->failed_pc=0x0c03c5e4u; return 0; }
vf3_matrix_swap(s);
goto P_0c03c5e6;
P_0c03c5e6: /* original 0009, guest PC 0x0c03c5e6 */
if(!s->budget--) { s->failed_pc=0x0c03c5e6u; return 0; }
goto P_0c03c5e8;
P_0c03c5e8: /* original 000b, guest PC 0x0c03c5e8 */
if(!s->budget--) { s->failed_pc=0x0c03c5e8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03c5ea: /* original 0009, guest PC 0x0c03c5ea */
if(!s->budget--) { s->failed_pc=0x0c03c5eau; return 0; }
if(!vf3_matrix_family(0x0c03c5ecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03c5ecu; return 0; } return 1;
P_0c03d260: /* original 4f22, guest PC 0x0c03d260 */
if(!s->budget--) { s->failed_pc=0x0c03d260u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03d262;
P_0c03d262: /* original d347, guest PC 0x0c03d262 */
if(!s->budget--) { s->failed_pc=0x0c03d262u; return 0; }
r[3]=read(ram,0x0c03d380u,4);
goto P_0c03d264;
P_0c03d264: /* original d445, guest PC 0x0c03d264 */
if(!s->budget--) { s->failed_pc=0x0c03d264u; return 0; }
r[4]=read(ram,0x0c03d37cu,4);
goto P_0c03d266;
P_0c03d266: /* original 430b, guest PC 0x0c03d266 */
if(!s->budget--) { s->failed_pc=0x0c03d266u; return 0; }
target=r[3];
r[16]=code_base|0x0c03d26au;
r[4]=read(ram,r[4]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d26au) { target=s->pc; goto dispatch; }
goto P_0c03d26a;
P_0c03d268: /* original 5442, guest PC 0x0c03d268 */
if(!s->budget--) { s->failed_pc=0x0c03d268u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c03d26a;
P_0c03d26a: /* original d246, guest PC 0x0c03d26a */
if(!s->budget--) { s->failed_pc=0x0c03d26au; return 0; }
r[2]=read(ram,0x0c03d384u,4);
goto P_0c03d26c;
P_0c03d26c: /* original 420b, guest PC 0x0c03d26c */
if(!s->budget--) { s->failed_pc=0x0c03d26cu; return 0; }
target=r[2];
r[16]=code_base|0x0c03d270u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d270u) { target=s->pc; goto dispatch; }
goto P_0c03d270;
P_0c03d26e: /* original 0009, guest PC 0x0c03d26e */
if(!s->budget--) { s->failed_pc=0x0c03d26eu; return 0; }
goto P_0c03d270;
P_0c03d270: /* original d346, guest PC 0x0c03d270 */
if(!s->budget--) { s->failed_pc=0x0c03d270u; return 0; }
r[3]=read(ram,0x0c03d38cu,4);
goto P_0c03d272;
P_0c03d272: /* original d445, guest PC 0x0c03d272 */
if(!s->budget--) { s->failed_pc=0x0c03d272u; return 0; }
r[4]=read(ram,0x0c03d388u,4);
goto P_0c03d274;
P_0c03d274: /* original 430b, guest PC 0x0c03d274 */
if(!s->budget--) { s->failed_pc=0x0c03d274u; return 0; }
target=r[3];
r[16]=code_base|0x0c03d278u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d278u) { target=s->pc; goto dispatch; }
goto P_0c03d278;
P_0c03d276: /* original 0009, guest PC 0x0c03d276 */
if(!s->budget--) { s->failed_pc=0x0c03d276u; return 0; }
goto P_0c03d278;
P_0c03d278: /* original d245, guest PC 0x0c03d278 */
if(!s->budget--) { s->failed_pc=0x0c03d278u; return 0; }
r[2]=read(ram,0x0c03d390u,4);
goto P_0c03d27a;
P_0c03d27a: /* original e401, guest PC 0x0c03d27a */
if(!s->budget--) { s->failed_pc=0x0c03d27au; return 0; }
r[4]=0x00000001u;
goto P_0c03d27c;
P_0c03d27c: /* original 422b, guest PC 0x0c03d27c */
if(!s->budget--) { s->failed_pc=0x0c03d27cu; return 0; }
target=r[2];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c03d27e: /* original 4f26, guest PC 0x0c03d27e */
if(!s->budget--) { s->failed_pc=0x0c03d27eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c03d280u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03d280u; return 0; } return 1;
P_0c03dd00: /* original d407, guest PC 0x0c03dd00 */
if(!s->budget--) { s->failed_pc=0x0c03dd00u; return 0; }
r[4]=read(ram,0x0c03dd20u,4);
goto P_0c03dd02;
P_0c03dd02: /* original d502, guest PC 0x0c03dd02 */
if(!s->budget--) { s->failed_pc=0x0c03dd02u; return 0; }
r[5]=read(ram,0x0c03dd0cu,4);
goto P_0c03dd04;
P_0c03dd04: /* original 5442, guest PC 0x0c03dd04 */
if(!s->budget--) { s->failed_pc=0x0c03dd04u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c03dd06;
P_0c03dd06: /* original a013, guest PC 0x0c03dd06 */
if(!s->budget--) { s->failed_pc=0x0c03dd06u; return 0; }
goto P_0c03dd30;
P_0c03dd08: /* original 0009, guest PC 0x0c03dd08 */
if(!s->budget--) { s->failed_pc=0x0c03dd08u; return 0; }
if(!vf3_matrix_family(0x0c03dd0au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03dd0au; return 0; } return 1;
P_0c03dd30: /* original fffb, guest PC 0x0c03dd30 */
if(!s->budget--) { s->failed_pc=0x0c03dd30u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c03dd32;
P_0c03dd32: /* original ffeb, guest PC 0x0c03dd32 */
if(!s->budget--) { s->failed_pc=0x0c03dd32u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c03dd34;
P_0c03dd34: /* original ffdb, guest PC 0x0c03dd34 */
if(!s->budget--) { s->failed_pc=0x0c03dd34u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c03dd36;
P_0c03dd36: /* original ffcb, guest PC 0x0c03dd36 */
if(!s->budget--) { s->failed_pc=0x0c03dd36u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c03dd38;
P_0c03dd38: /* original f3fd, guest PC 0x0c03dd38 */
if(!s->budget--) { s->failed_pc=0x0c03dd38u; return 0; }
r[18]^=0x100000u;
goto P_0c03dd3a;
P_0c03dd3a: /* original f049, guest PC 0x0c03dd3a */
if(!s->budget--) { s->failed_pc=0x0c03dd3au; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd3c;
P_0c03dd3c: /* original f249, guest PC 0x0c03dd3c */
if(!s->budget--) { s->failed_pc=0x0c03dd3cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd3e;
P_0c03dd3e: /* original f449, guest PC 0x0c03dd3e */
if(!s->budget--) { s->failed_pc=0x0c03dd3eu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd40;
P_0c03dd40: /* original f649, guest PC 0x0c03dd40 */
if(!s->budget--) { s->failed_pc=0x0c03dd40u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd42;
P_0c03dd42: /* original f849, guest PC 0x0c03dd42 */
if(!s->budget--) { s->failed_pc=0x0c03dd42u; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd44;
P_0c03dd44: /* original fa49, guest PC 0x0c03dd44 */
if(!s->budget--) { s->failed_pc=0x0c03dd44u; return 0; }
vf3_matrix_load(s,ram,10,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd46;
P_0c03dd46: /* original fc49, guest PC 0x0c03dd46 */
if(!s->budget--) { s->failed_pc=0x0c03dd46u; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd48;
P_0c03dd48: /* original fe49, guest PC 0x0c03dd48 */
if(!s->budget--) { s->failed_pc=0x0c03dd48u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd4a;
P_0c03dd4a: /* original f3fd, guest PC 0x0c03dd4a */
if(!s->budget--) { s->failed_pc=0x0c03dd4au; return 0; }
r[18]^=0x100000u;
goto P_0c03dd4c;
P_0c03dd4c: /* original fbfd, guest PC 0x0c03dd4c */
if(!s->budget--) { s->failed_pc=0x0c03dd4cu; return 0; }
vf3_matrix_swap(s);
goto P_0c03dd4e;
P_0c03dd4e: /* original 6453, guest PC 0x0c03dd4e */
if(!s->budget--) { s->failed_pc=0x0c03dd4eu; return 0; }
r[4]=r[5];
goto P_0c03dd50;
P_0c03dd50: /* original 0483, guest PC 0x0c03dd50 */
if(!s->budget--) { s->failed_pc=0x0c03dd50u; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c03dd52;
P_0c03dd52: /* original f1fd, guest PC 0x0c03dd52 */
if(!s->budget--) { s->failed_pc=0x0c03dd52u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c03dd54;
P_0c03dd54: /* original 7420, guest PC 0x0c03dd54 */
if(!s->budget--) { s->failed_pc=0x0c03dd54u; return 0; }
r[4]+=0x00000020u;
goto P_0c03dd56;
P_0c03dd56: /* original f5fd, guest PC 0x0c03dd56 */
if(!s->budget--) { s->failed_pc=0x0c03dd56u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c03dd58;
P_0c03dd58: /* original f9fd, guest PC 0x0c03dd58 */
if(!s->budget--) { s->failed_pc=0x0c03dd58u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+8,r[18],fr+8)) goto unsupported;
goto P_0c03dd5a;
P_0c03dd5a: /* original fdfd, guest PC 0x0c03dd5a */
if(!s->budget--) { s->failed_pc=0x0c03dd5au; return 0; }
if(!vf3_fpu_ftrv(xf,fr+12,r[18],fr+12)) goto unsupported;
goto P_0c03dd5c;
P_0c03dd5c: /* original 0483, guest PC 0x0c03dd5c */
if(!s->budget--) { s->failed_pc=0x0c03dd5cu; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c03dd5e;
P_0c03dd5e: /* original fbfd, guest PC 0x0c03dd5e */
if(!s->budget--) { s->failed_pc=0x0c03dd5eu; return 0; }
vf3_matrix_swap(s);
goto P_0c03dd60;
P_0c03dd60: /* original f059, guest PC 0x0c03dd60 */
if(!s->budget--) { s->failed_pc=0x0c03dd60u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd62;
P_0c03dd62: /* original f159, guest PC 0x0c03dd62 */
if(!s->budget--) { s->failed_pc=0x0c03dd62u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd64;
P_0c03dd64: /* original f259, guest PC 0x0c03dd64 */
if(!s->budget--) { s->failed_pc=0x0c03dd64u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd66;
P_0c03dd66: /* original f359, guest PC 0x0c03dd66 */
if(!s->budget--) { s->failed_pc=0x0c03dd66u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd68;
P_0c03dd68: /* original f459, guest PC 0x0c03dd68 */
if(!s->budget--) { s->failed_pc=0x0c03dd68u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd6a;
P_0c03dd6a: /* original f559, guest PC 0x0c03dd6a */
if(!s->budget--) { s->failed_pc=0x0c03dd6au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd6c;
P_0c03dd6c: /* original f659, guest PC 0x0c03dd6c */
if(!s->budget--) { s->failed_pc=0x0c03dd6cu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd6e;
P_0c03dd6e: /* original f759, guest PC 0x0c03dd6e */
if(!s->budget--) { s->failed_pc=0x0c03dd6eu; return 0; }
vf3_matrix_load(s,ram,7,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd70;
P_0c03dd70: /* original f859, guest PC 0x0c03dd70 */
if(!s->budget--) { s->failed_pc=0x0c03dd70u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd72;
P_0c03dd72: /* original f959, guest PC 0x0c03dd72 */
if(!s->budget--) { s->failed_pc=0x0c03dd72u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd74;
P_0c03dd74: /* original fa59, guest PC 0x0c03dd74 */
if(!s->budget--) { s->failed_pc=0x0c03dd74u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd76;
P_0c03dd76: /* original fb59, guest PC 0x0c03dd76 */
if(!s->budget--) { s->failed_pc=0x0c03dd76u; return 0; }
vf3_matrix_load(s,ram,11,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd78;
P_0c03dd78: /* original fc59, guest PC 0x0c03dd78 */
if(!s->budget--) { s->failed_pc=0x0c03dd78u; return 0; }
vf3_matrix_load(s,ram,12,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd7a;
P_0c03dd7a: /* original fd59, guest PC 0x0c03dd7a */
if(!s->budget--) { s->failed_pc=0x0c03dd7au; return 0; }
vf3_matrix_load(s,ram,13,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd7c;
P_0c03dd7c: /* original fe59, guest PC 0x0c03dd7c */
if(!s->budget--) { s->failed_pc=0x0c03dd7cu; return 0; }
vf3_matrix_load(s,ram,14,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd7e;
P_0c03dd7e: /* original ff59, guest PC 0x0c03dd7e */
if(!s->budget--) { s->failed_pc=0x0c03dd7eu; return 0; }
vf3_matrix_load(s,ram,15,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd80;
P_0c03dd80: /* original fbfd, guest PC 0x0c03dd80 */
if(!s->budget--) { s->failed_pc=0x0c03dd80u; return 0; }
vf3_matrix_swap(s);
goto P_0c03dd82;
P_0c03dd82: /* original f1fd, guest PC 0x0c03dd82 */
if(!s->budget--) { s->failed_pc=0x0c03dd82u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c03dd84;
P_0c03dd84: /* original f5fd, guest PC 0x0c03dd84 */
if(!s->budget--) { s->failed_pc=0x0c03dd84u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c03dd86;
P_0c03dd86: /* original f9fd, guest PC 0x0c03dd86 */
if(!s->budget--) { s->failed_pc=0x0c03dd86u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+8,r[18],fr+8)) goto unsupported;
goto P_0c03dd88;
P_0c03dd88: /* original fdfd, guest PC 0x0c03dd88 */
if(!s->budget--) { s->failed_pc=0x0c03dd88u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+12,r[18],fr+12)) goto unsupported;
goto P_0c03dd8a;
P_0c03dd8a: /* original fbfd, guest PC 0x0c03dd8a */
if(!s->budget--) { s->failed_pc=0x0c03dd8au; return 0; }
vf3_matrix_swap(s);
goto P_0c03dd8c;
P_0c03dd8c: /* original fcf9, guest PC 0x0c03dd8c */
if(!s->budget--) { s->failed_pc=0x0c03dd8cu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd8e;
P_0c03dd8e: /* original fdf9, guest PC 0x0c03dd8e */
if(!s->budget--) { s->failed_pc=0x0c03dd8eu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd90;
P_0c03dd90: /* original fef9, guest PC 0x0c03dd90 */
if(!s->budget--) { s->failed_pc=0x0c03dd90u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd92;
P_0c03dd92: /* original fff9, guest PC 0x0c03dd92 */
if(!s->budget--) { s->failed_pc=0x0c03dd92u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd94;
P_0c03dd94: /* original 000b, guest PC 0x0c03dd94 */
if(!s->budget--) { s->failed_pc=0x0c03dd94u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03dd96: /* original 0009, guest PC 0x0c03dd96 */
if(!s->budget--) { s->failed_pc=0x0c03dd96u; return 0; }
if(!vf3_matrix_family(0x0c03dd98u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03dd98u; return 0; } return 1;
P_0c03ecb0: /* original 4f22, guest PC 0x0c03ecb0 */
if(!s->budget--) { s->failed_pc=0x0c03ecb0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03ecb2;
P_0c03ecb2: /* original 7ffc, guest PC 0x0c03ecb2 */
if(!s->budget--) { s->failed_pc=0x0c03ecb2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03ecb4;
P_0c03ecb4: /* original 2f42, guest PC 0x0c03ecb4 */
if(!s->budget--) { s->failed_pc=0x0c03ecb4u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03ecb6;
P_0c03ecb6: /* original d366, guest PC 0x0c03ecb6 */
if(!s->budget--) { s->failed_pc=0x0c03ecb6u; return 0; }
r[3]=read(ram,0x0c03ee50u,4);
goto P_0c03ecb8;
P_0c03ecb8: /* original f58d, guest PC 0x0c03ecb8 */
if(!s->budget--) { s->failed_pc=0x0c03ecb8u; return 0; }
fr[5]=0;
goto P_0c03ecba;
P_0c03ecba: /* original 430b, guest PC 0x0c03ecba */
if(!s->budget--) { s->failed_pc=0x0c03ecbau; return 0; }
target=r[3];
r[16]=code_base|0x0c03ecbeu;
fr[4]=0;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03ecbeu) { target=s->pc; goto dispatch; }
goto P_0c03ecbe;
P_0c03ecbc: /* original f48d, guest PC 0x0c03ecbc */
if(!s->budget--) { s->failed_pc=0x0c03ecbcu; return 0; }
fr[4]=0;
goto P_0c03ecbe;
P_0c03ecbe: /* original b0bf, guest PC 0x0c03ecbe */
if(!s->budget--) { s->failed_pc=0x0c03ecbeu; return 0; }
target=code_base|0x0c03ee40u; r[16]=code_base|0x0c03ecc2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03ecc2u) { target=s->pc; goto dispatch; }
goto P_0c03ecc2;
P_0c03ecc0: /* original 0009, guest PC 0x0c03ecc0 */
if(!s->budget--) { s->failed_pc=0x0c03ecc0u; return 0; }
goto P_0c03ecc2;
P_0c03ecc2: /* original d364, guest PC 0x0c03ecc2 */
if(!s->budget--) { s->failed_pc=0x0c03ecc2u; return 0; }
r[3]=read(ram,0x0c03ee54u,4);
goto P_0c03ecc4;
P_0c03ecc4: /* original 64f2, guest PC 0x0c03ecc4 */
if(!s->budget--) { s->failed_pc=0x0c03ecc4u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c03ecc6;
P_0c03ecc6: /* original 7f04, guest PC 0x0c03ecc6 */
if(!s->budget--) { s->failed_pc=0x0c03ecc6u; return 0; }
r[15]+=0x00000004u;
goto P_0c03ecc8;
P_0c03ecc8: /* original 432b, guest PC 0x0c03ecc8 */
if(!s->budget--) { s->failed_pc=0x0c03ecc8u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c03ecca: /* original 4f26, guest PC 0x0c03ecca */
if(!s->budget--) { s->failed_pc=0x0c03eccau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c03ecccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03ecccu; return 0; } return 1;
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
unsupported: s->failed_pc=target; return 0;
}
