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
int vf3_away_batch259_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0cc21au: goto P_0c0cc21a;
case 0x0c0cc21cu: goto P_0c0cc21c;
case 0x0c0cc21eu: goto P_0c0cc21e;
case 0x0c0cc220u: goto P_0c0cc220;
case 0x0c0cc222u: goto P_0c0cc222;
case 0x0c0cc224u: goto P_0c0cc224;
case 0x0c0cc226u: goto P_0c0cc226;
case 0x0c0cc228u: goto P_0c0cc228;
case 0x0c0cc22au: goto P_0c0cc22a;
case 0x0c0cc22cu: goto P_0c0cc22c;
case 0x0c0cc22eu: goto P_0c0cc22e;
case 0x0c0cc230u: goto P_0c0cc230;
case 0x0c0cc232u: goto P_0c0cc232;
case 0x0c0cc234u: goto P_0c0cc234;
case 0x0c0cc236u: goto P_0c0cc236;
case 0x0c0cc238u: goto P_0c0cc238;
case 0x0c0cc23au: goto P_0c0cc23a;
case 0x0c0cc23cu: goto P_0c0cc23c;
case 0x0c0cc23eu: goto P_0c0cc23e;
case 0x0c0cc240u: goto P_0c0cc240;
case 0x0c0cc242u: goto P_0c0cc242;
case 0x0c0cc244u: goto P_0c0cc244;
case 0x0c0cc246u: goto P_0c0cc246;
case 0x0c0cc248u: goto P_0c0cc248;
case 0x0c0cc24au: goto P_0c0cc24a;
case 0x0c0cc24cu: goto P_0c0cc24c;
case 0x0c0cc24eu: goto P_0c0cc24e;
case 0x0c0cc250u: goto P_0c0cc250;
case 0x0c0cc252u: goto P_0c0cc252;
case 0x0c0cc254u: goto P_0c0cc254;
case 0x0c0cc256u: goto P_0c0cc256;
case 0x0c0cc258u: goto P_0c0cc258;
case 0x0c0cc25au: goto P_0c0cc25a;
case 0x0c0cc25cu: goto P_0c0cc25c;
case 0x0c0cc25eu: goto P_0c0cc25e;
case 0x0c0cc260u: goto P_0c0cc260;
case 0x0c0cc262u: goto P_0c0cc262;
case 0x0c0cc264u: goto P_0c0cc264;
case 0x0c0cc266u: goto P_0c0cc266;
case 0x0c0cc268u: goto P_0c0cc268;
case 0x0c0cc26au: goto P_0c0cc26a;
case 0x0c0cc26cu: goto P_0c0cc26c;
case 0x0c0cc26eu: goto P_0c0cc26e;
case 0x0c0cc270u: goto P_0c0cc270;
case 0x0c0cc272u: goto P_0c0cc272;
case 0x0c0cc274u: goto P_0c0cc274;
case 0x0c0cc276u: goto P_0c0cc276;
case 0x0c0cc278u: goto P_0c0cc278;
case 0x0c0cc27au: goto P_0c0cc27a;
case 0x0c0cc27cu: goto P_0c0cc27c;
case 0x0c0cc27eu: goto P_0c0cc27e;
case 0x0c0cc280u: goto P_0c0cc280;
case 0x0c0cc282u: goto P_0c0cc282;
case 0x0c0cc284u: goto P_0c0cc284;
case 0x0c0cc286u: goto P_0c0cc286;
case 0x0c0cc288u: goto P_0c0cc288;
case 0x0c0cc28au: goto P_0c0cc28a;
case 0x0c0cc28cu: goto P_0c0cc28c;
case 0x0c0cc28eu: goto P_0c0cc28e;
case 0x0c0cc290u: goto P_0c0cc290;
case 0x0c0cc292u: goto P_0c0cc292;
case 0x0c0cc294u: goto P_0c0cc294;
case 0x0c0cc296u: goto P_0c0cc296;
case 0x0c0cc298u: goto P_0c0cc298;
case 0x0c0cc29au: goto P_0c0cc29a;
case 0x0c0cc29cu: goto P_0c0cc29c;
case 0x0c0cc29eu: goto P_0c0cc29e;
case 0x0c0cc2a0u: goto P_0c0cc2a0;
case 0x0c0cc2a2u: goto P_0c0cc2a2;
case 0x0c0cc2a4u: goto P_0c0cc2a4;
case 0x0c0cc2a6u: goto P_0c0cc2a6;
case 0x0c0cc2a8u: goto P_0c0cc2a8;
case 0x0c0cc2aau: goto P_0c0cc2aa;
case 0x0c0cc2acu: goto P_0c0cc2ac;
case 0x0c0cc2aeu: goto P_0c0cc2ae;
case 0x0c0cc2b0u: goto P_0c0cc2b0;
case 0x0c0cc2b2u: goto P_0c0cc2b2;
case 0x0c0cc2b4u: goto P_0c0cc2b4;
case 0x0c0cc2b6u: goto P_0c0cc2b6;
case 0x0c0cc2b8u: goto P_0c0cc2b8;
case 0x0c0cc2bau: goto P_0c0cc2ba;
case 0x0c0cc2bcu: goto P_0c0cc2bc;
case 0x0c0cc2beu: goto P_0c0cc2be;
case 0x0c0cc2c0u: goto P_0c0cc2c0;
case 0x0c0cc2c2u: goto P_0c0cc2c2;
case 0x0c0cc2c4u: goto P_0c0cc2c4;
case 0x0c0cc2c6u: goto P_0c0cc2c6;
case 0x0c0cc2c8u: goto P_0c0cc2c8;
case 0x0c0cc2cau: goto P_0c0cc2ca;
case 0x0c0cc2ccu: goto P_0c0cc2cc;
case 0x0c0cc2ceu: goto P_0c0cc2ce;
case 0x0c0cc2d0u: goto P_0c0cc2d0;
case 0x0c0cc2d2u: goto P_0c0cc2d2;
case 0x0c0cc2d4u: goto P_0c0cc2d4;
case 0x0c0cc4dcu: goto P_0c0cc4dc;
case 0x0c0cc4deu: goto P_0c0cc4de;
case 0x0c0cc4e0u: goto P_0c0cc4e0;
case 0x0c0cc4e2u: goto P_0c0cc4e2;
case 0x0c0cc4e4u: goto P_0c0cc4e4;
case 0x0c0cc4e6u: goto P_0c0cc4e6;
case 0x0c0cc4e8u: goto P_0c0cc4e8;
case 0x0c0cc4eau: goto P_0c0cc4ea;
case 0x0c0cc4ecu: goto P_0c0cc4ec;
case 0x0c0cc4eeu: goto P_0c0cc4ee;
case 0x0c0cc4f0u: goto P_0c0cc4f0;
case 0x0c0cc4f2u: goto P_0c0cc4f2;
case 0x0c0cc4f4u: goto P_0c0cc4f4;
case 0x0c0cc4f6u: goto P_0c0cc4f6;
case 0x0c0cc4f8u: goto P_0c0cc4f8;
case 0x0c0cc4fau: goto P_0c0cc4fa;
case 0x0c0cc4fcu: goto P_0c0cc4fc;
case 0x0c0cc4feu: goto P_0c0cc4fe;
case 0x0c0cc500u: goto P_0c0cc500;
case 0x0c0cc502u: goto P_0c0cc502;
case 0x0c0cc504u: goto P_0c0cc504;
case 0x0c0cc506u: goto P_0c0cc506;
case 0x0c0cc508u: goto P_0c0cc508;
case 0x0c0cc50au: goto P_0c0cc50a;
case 0x0c0cc50cu: goto P_0c0cc50c;
case 0x0c0cc50eu: goto P_0c0cc50e;
case 0x0c0cc510u: goto P_0c0cc510;
case 0x0c0cc512u: goto P_0c0cc512;
case 0x0c0cc514u: goto P_0c0cc514;
case 0x0c0cc516u: goto P_0c0cc516;
case 0x0c0cc518u: goto P_0c0cc518;
case 0x0c0cc51au: goto P_0c0cc51a;
case 0x0c0cc51cu: goto P_0c0cc51c;
case 0x0c0cc51eu: goto P_0c0cc51e;
case 0x0c0cc520u: goto P_0c0cc520;
case 0x0c0cc522u: goto P_0c0cc522;
case 0x0c0cc524u: goto P_0c0cc524;
case 0x0c0cc526u: goto P_0c0cc526;
case 0x0c0cc528u: goto P_0c0cc528;
case 0x0c0cc52au: goto P_0c0cc52a;
case 0x0c0cc52cu: goto P_0c0cc52c;
case 0x0c0cc52eu: goto P_0c0cc52e;
case 0x0c0cc530u: goto P_0c0cc530;
case 0x0c0cc532u: goto P_0c0cc532;
case 0x0c0cc534u: goto P_0c0cc534;
case 0x0c0cc536u: goto P_0c0cc536;
case 0x0c0cc538u: goto P_0c0cc538;
case 0x0c0cc53au: goto P_0c0cc53a;
case 0x0c0cc53cu: goto P_0c0cc53c;
case 0x0c0cc53eu: goto P_0c0cc53e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0cc21a: /* original 2fe6, guest PC 0x0c0cc21a */
if(!s->budget--) { s->failed_pc=0x0c0cc21au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc21c;
P_0c0cc21c: /* original ee1f, guest PC 0x0c0cc21c */
if(!s->budget--) { s->failed_pc=0x0c0cc21cu; return 0; }
r[14]=0x0000001fu;
goto P_0c0cc21e;
P_0c0cc21e: /* original 7ffc, guest PC 0x0c0cc21e */
if(!s->budget--) { s->failed_pc=0x0c0cc21eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0cc220;
P_0c0cc220: /* original 5253, guest PC 0x0c0cc220 */
if(!s->budget--) { s->failed_pc=0x0c0cc220u; return 0; }
r[2]=read(ram,r[5]+12,4);
goto P_0c0cc222;
P_0c0cc222: /* original 56f2, guest PC 0x0c0cc222 */
if(!s->budget--) { s->failed_pc=0x0c0cc222u; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c0cc224;
P_0c0cc224: /* original c752, guest PC 0x0c0cc224 */
if(!s->budget--) { s->failed_pc=0x0c0cc224u; return 0; }
r[0]=code_base|0x000cc370u;
goto P_0c0cc226;
P_0c0cc226: /* original f508, guest PC 0x0c0cc226 */
if(!s->budget--) { s->failed_pc=0x0c0cc226u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0cc228;
P_0c0cc228: /* original e3fb, guest PC 0x0c0cc228 */
if(!s->budget--) { s->failed_pc=0x0c0cc228u; return 0; }
r[3]=0xfffffffbu;
goto P_0c0cc22a;
P_0c0cc22a: /* original 6163, guest PC 0x0c0cc22a */
if(!s->budget--) { s->failed_pc=0x0c0cc22au; return 0; }
r[1]=r[6];
goto P_0c0cc22c;
P_0c0cc22c: /* original 21e9, guest PC 0x0c0cc22c */
if(!s->budget--) { s->failed_pc=0x0c0cc22cu; return 0; }
r[1]&=r[14];
goto P_0c0cc22e;
P_0c0cc22e: /* original 71f0, guest PC 0x0c0cc22e */
if(!s->budget--) { s->failed_pc=0x0c0cc22eu; return 0; }
r[1]+=0xfffffff0u;
goto P_0c0cc230;
P_0c0cc230: /* original 6063, guest PC 0x0c0cc230 */
if(!s->budget--) { s->failed_pc=0x0c0cc230u; return 0; }
r[0]=r[6];
goto P_0c0cc232;
P_0c0cc232: /* original 415a, guest PC 0x0c0cc232 */
if(!s->budget--) { s->failed_pc=0x0c0cc232u; return 0; }
r[53]=r[1];
goto P_0c0cc234;
P_0c0cc234: /* original 2228, guest PC 0x0c0cc234 */
if(!s->budget--) { s->failed_pc=0x0c0cc234u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0cc236;
P_0c0cc236: /* original 403c, guest PC 0x0c0cc236 */
if(!s->budget--) { s->failed_pc=0x0c0cc236u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c0cc238;
P_0c0cc238: /* original e10f, guest PC 0x0c0cc238 */
if(!s->budget--) { s->failed_pc=0x0c0cc238u; return 0; }
r[1]=0x0000000fu;
goto P_0c0cc23a;
P_0c0cc23a: /* original f32d, guest PC 0x0c0cc23a */
if(!s->budget--) { s->failed_pc=0x0c0cc23au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0cc23c;
P_0c0cc23c: /* original f43c, guest PC 0x0c0cc23c */
if(!s->budget--) { s->failed_pc=0x0c0cc23cu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0cc23e;
P_0c0cc23e: /* original f452, guest PC 0x0c0cc23e */
if(!s->budget--) { s->failed_pc=0x0c0cc23eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0cc240;
P_0c0cc240: /* original 8f02, guest PC 0x0c0cc240 */
if(!s->budget--) { s->failed_pc=0x0c0cc240u; return 0; }
cond=r[17]&1u;
r[1]&=r[0];
if(!cond) { goto P_0c0cc248; }
goto P_0c0cc244;
P_0c0cc242: /* original 2109, guest PC 0x0c0cc242 */
if(!s->budget--) { s->failed_pc=0x0c0cc242u; return 0; }
r[1]&=r[0];
goto P_0c0cc244;
P_0c0cc244: /* original a001, guest PC 0x0c0cc244 */
if(!s->budget--) { s->failed_pc=0x0c0cc244u; return 0; }
r[0]=0x00000007u;
goto P_0c0cc24a;
P_0c0cc246: /* original e007, guest PC 0x0c0cc246 */
if(!s->budget--) { s->failed_pc=0x0c0cc246u; return 0; }
r[0]=0x00000007u;
goto P_0c0cc248;
P_0c0cc248: /* original e0f1, guest PC 0x0c0cc248 */
if(!s->budget--) { s->failed_pc=0x0c0cc248u; return 0; }
r[0]=0xfffffff1u;
goto P_0c0cc24a;
P_0c0cc24a: /* original 310c, guest PC 0x0c0cc24a */
if(!s->budget--) { s->failed_pc=0x0c0cc24au; return 0; }
r[1]+=r[0];
goto P_0c0cc24c;
P_0c0cc24c: /* original 415a, guest PC 0x0c0cc24c */
if(!s->budget--) { s->failed_pc=0x0c0cc24cu; return 0; }
r[53]=r[1];
goto P_0c0cc24e;
P_0c0cc24e: /* original 6163, guest PC 0x0c0cc24e */
if(!s->budget--) { s->failed_pc=0x0c0cc24eu; return 0; }
r[1]=r[6];
goto P_0c0cc250;
P_0c0cc250: /* original e3f6, guest PC 0x0c0cc250 */
if(!s->budget--) { s->failed_pc=0x0c0cc250u; return 0; }
r[3]=0xfffffff6u;
goto P_0c0cc252;
P_0c0cc252: /* original 413c, guest PC 0x0c0cc252 */
if(!s->budget--) { s->failed_pc=0x0c0cc252u; return 0; }
r[1]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[1]>>((-r[3])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[3]&31u);
goto P_0c0cc254;
P_0c0cc254: /* original f32d, guest PC 0x0c0cc254 */
if(!s->budget--) { s->failed_pc=0x0c0cc254u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0cc256;
P_0c0cc256: /* original 21e9, guest PC 0x0c0cc256 */
if(!s->budget--) { s->failed_pc=0x0c0cc256u; return 0; }
r[1]&=r[14];
goto P_0c0cc258;
P_0c0cc258: /* original 71f0, guest PC 0x0c0cc258 */
if(!s->budget--) { s->failed_pc=0x0c0cc258u; return 0; }
r[1]+=0xfffffff0u;
goto P_0c0cc25a;
P_0c0cc25a: /* original 415a, guest PC 0x0c0cc25a */
if(!s->budget--) { s->failed_pc=0x0c0cc25au; return 0; }
r[53]=r[1];
goto P_0c0cc25c;
P_0c0cc25c: /* original 636c, guest PC 0x0c0cc25c */
if(!s->budget--) { s->failed_pc=0x0c0cc25cu; return 0; }
r[3]=r[6]&255u;
goto P_0c0cc25e;
P_0c0cc25e: /* original c745, guest PC 0x0c0cc25e */
if(!s->budget--) { s->failed_pc=0x0c0cc25eu; return 0; }
r[0]=code_base|0x000cc374u;
goto P_0c0cc260;
P_0c0cc260: /* original f73c, guest PC 0x0c0cc260 */
if(!s->budget--) { s->failed_pc=0x0c0cc260u; return 0; }
vf3_matrix_move(s,7,3);
goto P_0c0cc262;
P_0c0cc262: /* original f32d, guest PC 0x0c0cc262 */
if(!s->budget--) { s->failed_pc=0x0c0cc262u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0cc264;
P_0c0cc264: /* original f752, guest PC 0x0c0cc264 */
if(!s->budget--) { s->failed_pc=0x0c0cc264u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'*');
goto P_0c0cc266;
P_0c0cc266: /* original f63c, guest PC 0x0c0cc266 */
if(!s->budget--) { s->failed_pc=0x0c0cc266u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c0cc268;
P_0c0cc268: /* original f652, guest PC 0x0c0cc268 */
if(!s->budget--) { s->failed_pc=0x0c0cc268u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c0cc26a;
P_0c0cc26a: /* original 2f32, guest PC 0x0c0cc26a */
if(!s->budget--) { s->failed_pc=0x0c0cc26au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0cc26c;
P_0c0cc26c: /* original 435a, guest PC 0x0c0cc26c */
if(!s->budget--) { s->failed_pc=0x0c0cc26cu; return 0; }
r[53]=r[3];
goto P_0c0cc26e;
P_0c0cc26e: /* original f32d, guest PC 0x0c0cc26e */
if(!s->budget--) { s->failed_pc=0x0c0cc26eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0cc270;
P_0c0cc270: /* original f53c, guest PC 0x0c0cc270 */
if(!s->budget--) { s->failed_pc=0x0c0cc270u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0cc272;
P_0c0cc272: /* original f308, guest PC 0x0c0cc272 */
if(!s->budget--) { s->failed_pc=0x0c0cc272u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cc274;
P_0c0cc274: /* original e018, guest PC 0x0c0cc274 */
if(!s->budget--) { s->failed_pc=0x0c0cc274u; return 0; }
r[0]=0x00000018u;
goto P_0c0cc276;
P_0c0cc276: /* original f856, guest PC 0x0c0cc276 */
if(!s->budget--) { s->failed_pc=0x0c0cc276u; return 0; }
vf3_matrix_load(s,ram,8,r[5]+r[0]);
goto P_0c0cc278;
P_0c0cc278: /* original e01c, guest PC 0x0c0cc278 */
if(!s->budget--) { s->failed_pc=0x0c0cc278u; return 0; }
r[0]=0x0000001cu;
goto P_0c0cc27a;
P_0c0cc27a: /* original f532, guest PC 0x0c0cc27a */
if(!s->budget--) { s->failed_pc=0x0c0cc27au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0cc27c;
P_0c0cc27c: /* original f956, guest PC 0x0c0cc27c */
if(!s->budget--) { s->failed_pc=0x0c0cc27cu; return 0; }
vf3_matrix_load(s,ram,9,r[5]+r[0]);
goto P_0c0cc27e;
P_0c0cc27e: /* original e020, guest PC 0x0c0cc27e */
if(!s->budget--) { s->failed_pc=0x0c0cc27eu; return 0; }
r[0]=0x00000020u;
goto P_0c0cc280;
P_0c0cc280: /* original f25c, guest PC 0x0c0cc280 */
if(!s->budget--) { s->failed_pc=0x0c0cc280u; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c0cc282;
P_0c0cc282: /* original f952, guest PC 0x0c0cc282 */
if(!s->budget--) { s->failed_pc=0x0c0cc282u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[5],r[18],'*');
goto P_0c0cc284;
P_0c0cc284: /* original f852, guest PC 0x0c0cc284 */
if(!s->budget--) { s->failed_pc=0x0c0cc284u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[5],r[18],'*');
goto P_0c0cc286;
P_0c0cc286: /* original f556, guest PC 0x0c0cc286 */
if(!s->budget--) { s->failed_pc=0x0c0cc286u; return 0; }
vf3_matrix_load(s,ram,5,r[5]+r[0]);
goto P_0c0cc288;
P_0c0cc288: /* original f522, guest PC 0x0c0cc288 */
if(!s->budget--) { s->failed_pc=0x0c0cc288u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'*');
goto P_0c0cc28a;
P_0c0cc28a: /* original e00c, guest PC 0x0c0cc28a */
if(!s->budget--) { s->failed_pc=0x0c0cc28au; return 0; }
r[0]=0x0000000cu;
goto P_0c0cc28c;
P_0c0cc28c: /* original f480, guest PC 0x0c0cc28c */
if(!s->budget--) { s->failed_pc=0x0c0cc28cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'+');
goto P_0c0cc28e;
P_0c0cc28e: /* original f487, guest PC 0x0c0cc28e */
if(!s->budget--) { s->failed_pc=0x0c0cc28eu; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c0cc290;
P_0c0cc290: /* original e010, guest PC 0x0c0cc290 */
if(!s->budget--) { s->failed_pc=0x0c0cc290u; return 0; }
r[0]=0x00000010u;
goto P_0c0cc292;
P_0c0cc292: /* original f497, guest PC 0x0c0cc292 */
if(!s->budget--) { s->failed_pc=0x0c0cc292u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c0cc294;
P_0c0cc294: /* original e014, guest PC 0x0c0cc294 */
if(!s->budget--) { s->failed_pc=0x0c0cc294u; return 0; }
r[0]=0x00000014u;
goto P_0c0cc296;
P_0c0cc296: /* original f790, guest PC 0x0c0cc296 */
if(!s->budget--) { s->failed_pc=0x0c0cc296u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[9],r[18],'+');
goto P_0c0cc298;
P_0c0cc298: /* original f457, guest PC 0x0c0cc298 */
if(!s->budget--) { s->failed_pc=0x0c0cc298u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0cc29a;
P_0c0cc29a: /* original f278, guest PC 0x0c0cc29a */
if(!s->budget--) { s->failed_pc=0x0c0cc29au; return 0; }
vf3_matrix_load(s,ram,2,r[7]);
goto P_0c0cc29c;
P_0c0cc29c: /* original e004, guest PC 0x0c0cc29c */
if(!s->budget--) { s->failed_pc=0x0c0cc29cu; return 0; }
r[0]=0x00000004u;
goto P_0c0cc29e;
P_0c0cc29e: /* original f650, guest PC 0x0c0cc29e */
if(!s->budget--) { s->failed_pc=0x0c0cc29eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'+');
goto P_0c0cc2a0;
P_0c0cc2a0: /* original e3f8, guest PC 0x0c0cc2a0 */
if(!s->budget--) { s->failed_pc=0x0c0cc2a0u; return 0; }
r[3]=0xfffffff8u;
goto P_0c0cc2a2;
P_0c0cc2a2: /* original f420, guest PC 0x0c0cc2a2 */
if(!s->budget--) { s->failed_pc=0x0c0cc2a2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'+');
goto P_0c0cc2a4;
P_0c0cc2a4: /* original 463c, guest PC 0x0c0cc2a4 */
if(!s->budget--) { s->failed_pc=0x0c0cc2a4u; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[6]>>((-r[3])&31u)):((int32_t)r[6]<0?0xffffffffu:0)):r[6]<<(r[3]&31u);
goto P_0c0cc2a6;
P_0c0cc2a6: /* original e201, guest PC 0x0c0cc2a6 */
if(!s->budget--) { s->failed_pc=0x0c0cc2a6u; return 0; }
r[2]=0x00000001u;
goto P_0c0cc2a8;
P_0c0cc2a8: /* original 26e9, guest PC 0x0c0cc2a8 */
if(!s->budget--) { s->failed_pc=0x0c0cc2a8u; return 0; }
r[6]&=r[14];
goto P_0c0cc2aa;
P_0c0cc2aa: /* original f44a, guest PC 0x0c0cc2aa */
if(!s->budget--) { s->failed_pc=0x0c0cc2aau; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c0cc2ac;
P_0c0cc2ac: /* original f276, guest PC 0x0c0cc2ac */
if(!s->budget--) { s->failed_pc=0x0c0cc2acu; return 0; }
vf3_matrix_load(s,ram,2,r[7]+r[0]);
goto P_0c0cc2ae;
P_0c0cc2ae: /* original f720, guest PC 0x0c0cc2ae */
if(!s->budget--) { s->failed_pc=0x0c0cc2aeu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'+');
goto P_0c0cc2b0;
P_0c0cc2b0: /* original f477, guest PC 0x0c0cc2b0 */
if(!s->budget--) { s->failed_pc=0x0c0cc2b0u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c0cc2b2;
P_0c0cc2b2: /* original e008, guest PC 0x0c0cc2b2 */
if(!s->budget--) { s->failed_pc=0x0c0cc2b2u; return 0; }
r[0]=0x00000008u;
goto P_0c0cc2b4;
P_0c0cc2b4: /* original f276, guest PC 0x0c0cc2b4 */
if(!s->budget--) { s->failed_pc=0x0c0cc2b4u; return 0; }
vf3_matrix_load(s,ram,2,r[7]+r[0]);
goto P_0c0cc2b6;
P_0c0cc2b6: /* original f64d, guest PC 0x0c0cc2b6 */
if(!s->budget--) { s->failed_pc=0x0c0cc2b6u; return 0; }
fr[6]^=0x80000000u;
goto P_0c0cc2b8;
P_0c0cc2b8: /* original f621, guest PC 0x0c0cc2b8 */
if(!s->budget--) { s->failed_pc=0x0c0cc2b8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'-');
goto P_0c0cc2ba;
P_0c0cc2ba: /* original f467, guest PC 0x0c0cc2ba */
if(!s->budget--) { s->failed_pc=0x0c0cc2bau; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0cc2bc;
P_0c0cc2bc: /* original 5353, guest PC 0x0c0cc2bc */
if(!s->budget--) { s->failed_pc=0x0c0cc2bcu; return 0; }
r[3]=read(ram,r[5]+12,4);
goto P_0c0cc2be;
P_0c0cc2be: /* original 3327, guest PC 0x0c0cc2be */
if(!s->budget--) { s->failed_pc=0x0c0cc2beu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c0cc2c0;
P_0c0cc2c0: /* original 8f04, guest PC 0x0c0cc2c0 */
if(!s->budget--) { s->failed_pc=0x0c0cc2c0u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000004u;
if(!cond) { goto P_0c0cc2cc; }
goto P_0c0cc2c4;
P_0c0cc2c2: /* original 7604, guest PC 0x0c0cc2c2 */
if(!s->budget--) { s->failed_pc=0x0c0cc2c2u; return 0; }
r[6]+=0x00000004u;
goto P_0c0cc2c4;
P_0c0cc2c4: /* original e01c, guest PC 0x0c0cc2c4 */
if(!s->budget--) { s->failed_pc=0x0c0cc2c4u; return 0; }
r[0]=0x0000001cu;
goto P_0c0cc2c6;
P_0c0cc2c6: /* original 3607, guest PC 0x0c0cc2c6 */
if(!s->budget--) { s->failed_pc=0x0c0cc2c6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[0])!=0);
goto P_0c0cc2c8;
P_0c0cc2c8: /* original 8b00, guest PC 0x0c0cc2c8 */
if(!s->budget--) { s->failed_pc=0x0c0cc2c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc2cc; }
goto P_0c0cc2ca;
P_0c0cc2ca: /* original e61c, guest PC 0x0c0cc2ca */
if(!s->budget--) { s->failed_pc=0x0c0cc2cau; return 0; }
r[6]=0x0000001cu;
goto P_0c0cc2cc;
P_0c0cc2cc: /* original 6063, guest PC 0x0c0cc2cc */
if(!s->budget--) { s->failed_pc=0x0c0cc2ccu; return 0; }
r[0]=r[6];
goto P_0c0cc2ce;
P_0c0cc2ce: /* original 7f04, guest PC 0x0c0cc2ce */
if(!s->budget--) { s->failed_pc=0x0c0cc2ceu; return 0; }
r[15]+=0x00000004u;
goto P_0c0cc2d0;
P_0c0cc2d0: /* original 814f, guest PC 0x0c0cc2d0 */
if(!s->budget--) { s->failed_pc=0x0c0cc2d0u; return 0; }
write(ram,r[4]+30,r[0],2);
goto P_0c0cc2d2;
P_0c0cc2d2: /* original 000b, guest PC 0x0c0cc2d2 */
if(!s->budget--) { s->failed_pc=0x0c0cc2d2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cc2d4: /* original 6ef6, guest PC 0x0c0cc2d4 */
if(!s->budget--) { s->failed_pc=0x0c0cc2d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0cc2d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0cc2d6u; return 0; } return 1;
P_0c0cc4dc: /* original 2fe6, guest PC 0x0c0cc4dc */
if(!s->budget--) { s->failed_pc=0x0c0cc4dcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc4de;
P_0c0cc4de: /* original 6543, guest PC 0x0c0cc4de */
if(!s->budget--) { s->failed_pc=0x0c0cc4deu; return 0; }
r[5]=r[4];
goto P_0c0cc4e0;
P_0c0cc4e0: /* original 2fd6, guest PC 0x0c0cc4e0 */
if(!s->budget--) { s->failed_pc=0x0c0cc4e0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc4e2;
P_0c0cc4e2: /* original 2fc6, guest PC 0x0c0cc4e2 */
if(!s->budget--) { s->failed_pc=0x0c0cc4e2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc4e4;
P_0c0cc4e4: /* original 2fb6, guest PC 0x0c0cc4e4 */
if(!s->budget--) { s->failed_pc=0x0c0cc4e4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc4e6;
P_0c0cc4e6: /* original 2fa6, guest PC 0x0c0cc4e6 */
if(!s->budget--) { s->failed_pc=0x0c0cc4e6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc4e8;
P_0c0cc4e8: /* original 5d5d, guest PC 0x0c0cc4e8 */
if(!s->budget--) { s->failed_pc=0x0c0cc4e8u; return 0; }
r[13]=read(ram,r[5]+52,4);
goto P_0c0cc4ea;
P_0c0cc4ea: /* original 4f22, guest PC 0x0c0cc4ea */
if(!s->budget--) { s->failed_pc=0x0c0cc4eau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cc4ec;
P_0c0cc4ec: /* original 9e28, guest PC 0x0c0cc4ec */
if(!s->budget--) { s->failed_pc=0x0c0cc4ecu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc540u,2);
goto P_0c0cc4ee;
P_0c0cc4ee: /* original 2dd8, guest PC 0x0c0cc4ee */
if(!s->budget--) { s->failed_pc=0x0c0cc4eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0cc4f0;
P_0c0cc4f0: /* original 8d1f, guest PC 0x0c0cc4f0 */
if(!s->budget--) { s->failed_pc=0x0c0cc4f0u; return 0; }
cond=r[17]&1u;
r[14]+=r[4];
if(cond) { goto P_0c0cc532; }
goto P_0c0cc4f4;
P_0c0cc4f2: /* original 3e4c, guest PC 0x0c0cc4f2 */
if(!s->budget--) { s->failed_pc=0x0c0cc4f2u; return 0; }
r[14]+=r[4];
goto P_0c0cc4f4;
P_0c0cc4f4: /* original d215, guest PC 0x0c0cc4f4 */
if(!s->budget--) { s->failed_pc=0x0c0cc4f4u; return 0; }
r[2]=read(ram,0x0c0cc54cu,4);
goto P_0c0cc4f6;
P_0c0cc4f6: /* original 420b, guest PC 0x0c0cc4f6 */
if(!s->budget--) { s->failed_pc=0x0c0cc4f6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0cc4fau;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cc4fau) { target=s->pc; goto dispatch; }
goto P_0c0cc4fa;
P_0c0cc4f8: /* original e400, guest PC 0x0c0cc4f8 */
if(!s->budget--) { s->failed_pc=0x0c0cc4f8u; return 0; }
r[4]=0x00000000u;
goto P_0c0cc4fa;
P_0c0cc4fa: /* original d315, guest PC 0x0c0cc4fa */
if(!s->budget--) { s->failed_pc=0x0c0cc4fau; return 0; }
r[3]=read(ram,0x0c0cc550u,4);
goto P_0c0cc4fc;
P_0c0cc4fc: /* original 430b, guest PC 0x0c0cc4fc */
if(!s->budget--) { s->failed_pc=0x0c0cc4fcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0cc500u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cc500u) { target=s->pc; goto dispatch; }
goto P_0c0cc500;
P_0c0cc4fe: /* original 0009, guest PC 0x0c0cc4fe */
if(!s->budget--) { s->failed_pc=0x0c0cc4feu; return 0; }
goto P_0c0cc500;
P_0c0cc500: /* original db15, guest PC 0x0c0cc500 */
if(!s->budget--) { s->failed_pc=0x0c0cc500u; return 0; }
r[11]=read(ram,0x0c0cc558u,4);
goto P_0c0cc502;
P_0c0cc502: /* original da14, guest PC 0x0c0cc502 */
if(!s->budget--) { s->failed_pc=0x0c0cc502u; return 0; }
r[10]=read(ram,0x0c0cc554u,4);
goto P_0c0cc504;
P_0c0cc504: /* original a00a, guest PC 0x0c0cc504 */
if(!s->budget--) { s->failed_pc=0x0c0cc504u; return 0; }
r[12]=0x00000001u;
goto P_0c0cc51c;
P_0c0cc506: /* original ec01, guest PC 0x0c0cc506 */
if(!s->budget--) { s->failed_pc=0x0c0cc506u; return 0; }
r[12]=0x00000001u;
goto P_0c0cc508;
P_0c0cc508: /* original 85ed, guest PC 0x0c0cc508 */
if(!s->budget--) { s->failed_pc=0x0c0cc508u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+26,2);
goto P_0c0cc50a;
P_0c0cc50a: /* original 20c8, guest PC 0x0c0cc50a */
if(!s->budget--) { s->failed_pc=0x0c0cc50au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[12])==0)!=0);
goto P_0c0cc50c;
P_0c0cc50c: /* original 8904, guest PC 0x0c0cc50c */
if(!s->budget--) { s->failed_pc=0x0c0cc50cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc518; }
goto P_0c0cc50e;
P_0c0cc50e: /* original 4a0b, guest PC 0x0c0cc50e */
if(!s->budget--) { s->failed_pc=0x0c0cc50eu; return 0; }
target=r[10];
r[16]=code_base|0x0c0cc512u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cc512u) { target=s->pc; goto dispatch; }
goto P_0c0cc512;
P_0c0cc510: /* original 64e3, guest PC 0x0c0cc510 */
if(!s->budget--) { s->failed_pc=0x0c0cc510u; return 0; }
r[4]=r[14];
goto P_0c0cc512;
P_0c0cc512: /* original 85ee, guest PC 0x0c0cc512 */
if(!s->budget--) { s->failed_pc=0x0c0cc512u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+28,2);
goto P_0c0cc514;
P_0c0cc514: /* original 4b0b, guest PC 0x0c0cc514 */
if(!s->budget--) { s->failed_pc=0x0c0cc514u; return 0; }
target=r[11];
r[16]=code_base|0x0c0cc518u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cc518u) { target=s->pc; goto dispatch; }
goto P_0c0cc518;
P_0c0cc516: /* original 6403, guest PC 0x0c0cc516 */
if(!s->budget--) { s->failed_pc=0x0c0cc516u; return 0; }
r[4]=r[0];
goto P_0c0cc518;
P_0c0cc518: /* original 7dff, guest PC 0x0c0cc518 */
if(!s->budget--) { s->failed_pc=0x0c0cc518u; return 0; }
r[13]+=0xffffffffu;
goto P_0c0cc51a;
P_0c0cc51a: /* original 7e20, guest PC 0x0c0cc51a */
if(!s->budget--) { s->failed_pc=0x0c0cc51au; return 0; }
r[14]+=0x00000020u;
goto P_0c0cc51c;
P_0c0cc51c: /* original 2dd8, guest PC 0x0c0cc51c */
if(!s->budget--) { s->failed_pc=0x0c0cc51cu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0cc51e;
P_0c0cc51e: /* original 8bf3, guest PC 0x0c0cc51e */
if(!s->budget--) { s->failed_pc=0x0c0cc51eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc508; }
goto P_0c0cc520;
P_0c0cc520: /* original 4f26, guest PC 0x0c0cc520 */
if(!s->budget--) { s->failed_pc=0x0c0cc520u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cc522;
P_0c0cc522: /* original d20e, guest PC 0x0c0cc522 */
if(!s->budget--) { s->failed_pc=0x0c0cc522u; return 0; }
r[2]=read(ram,0x0c0cc55cu,4);
goto P_0c0cc524;
P_0c0cc524: /* original e401, guest PC 0x0c0cc524 */
if(!s->budget--) { s->failed_pc=0x0c0cc524u; return 0; }
r[4]=0x00000001u;
goto P_0c0cc526;
P_0c0cc526: /* original 6af6, guest PC 0x0c0cc526 */
if(!s->budget--) { s->failed_pc=0x0c0cc526u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cc528;
P_0c0cc528: /* original 6bf6, guest PC 0x0c0cc528 */
if(!s->budget--) { s->failed_pc=0x0c0cc528u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cc52a;
P_0c0cc52a: /* original 6cf6, guest PC 0x0c0cc52a */
if(!s->budget--) { s->failed_pc=0x0c0cc52au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cc52c;
P_0c0cc52c: /* original 6df6, guest PC 0x0c0cc52c */
if(!s->budget--) { s->failed_pc=0x0c0cc52cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cc52e;
P_0c0cc52e: /* original 422b, guest PC 0x0c0cc52e */
if(!s->budget--) { s->failed_pc=0x0c0cc52eu; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c0cc530: /* original 6ef6, guest PC 0x0c0cc530 */
if(!s->budget--) { s->failed_pc=0x0c0cc530u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0cc532;
P_0c0cc532: /* original 4f26, guest PC 0x0c0cc532 */
if(!s->budget--) { s->failed_pc=0x0c0cc532u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cc534;
P_0c0cc534: /* original 6af6, guest PC 0x0c0cc534 */
if(!s->budget--) { s->failed_pc=0x0c0cc534u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cc536;
P_0c0cc536: /* original 6bf6, guest PC 0x0c0cc536 */
if(!s->budget--) { s->failed_pc=0x0c0cc536u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cc538;
P_0c0cc538: /* original 6cf6, guest PC 0x0c0cc538 */
if(!s->budget--) { s->failed_pc=0x0c0cc538u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cc53a;
P_0c0cc53a: /* original 6df6, guest PC 0x0c0cc53a */
if(!s->budget--) { s->failed_pc=0x0c0cc53au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cc53c;
P_0c0cc53c: /* original 000b, guest PC 0x0c0cc53c */
if(!s->budget--) { s->failed_pc=0x0c0cc53cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cc53e: /* original 6ef6, guest PC 0x0c0cc53e */
if(!s->budget--) { s->failed_pc=0x0c0cc53eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0cc540u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0cc540u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
