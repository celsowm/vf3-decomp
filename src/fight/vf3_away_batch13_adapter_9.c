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
int vf3_away_batch13_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c084864u: goto P_0c084864;
case 0x0c084866u: goto P_0c084866;
case 0x0c084868u: goto P_0c084868;
case 0x0c08486au: goto P_0c08486a;
case 0x0c08486cu: goto P_0c08486c;
case 0x0c08486eu: goto P_0c08486e;
case 0x0c084870u: goto P_0c084870;
case 0x0c084872u: goto P_0c084872;
case 0x0c084874u: goto P_0c084874;
case 0x0c084876u: goto P_0c084876;
case 0x0c084878u: goto P_0c084878;
case 0x0c08487au: goto P_0c08487a;
case 0x0c08487cu: goto P_0c08487c;
case 0x0c08487eu: goto P_0c08487e;
case 0x0c084880u: goto P_0c084880;
case 0x0c084882u: goto P_0c084882;
case 0x0c084884u: goto P_0c084884;
case 0x0c084886u: goto P_0c084886;
case 0x0c084888u: goto P_0c084888;
case 0x0c08488au: goto P_0c08488a;
case 0x0c08488cu: goto P_0c08488c;
case 0x0c08488eu: goto P_0c08488e;
case 0x0c084890u: goto P_0c084890;
case 0x0c084892u: goto P_0c084892;
case 0x0c084894u: goto P_0c084894;
case 0x0c084896u: goto P_0c084896;
case 0x0c084898u: goto P_0c084898;
case 0x0c08489au: goto P_0c08489a;
case 0x0c08489cu: goto P_0c08489c;
case 0x0c08489eu: goto P_0c08489e;
case 0x0c0848a0u: goto P_0c0848a0;
case 0x0c0848a2u: goto P_0c0848a2;
case 0x0c0848a4u: goto P_0c0848a4;
case 0x0c0848a6u: goto P_0c0848a6;
case 0x0c0848a8u: goto P_0c0848a8;
case 0x0c0848aau: goto P_0c0848aa;
case 0x0c0848acu: goto P_0c0848ac;
case 0x0c0848aeu: goto P_0c0848ae;
case 0x0c0848b0u: goto P_0c0848b0;
case 0x0c0848b2u: goto P_0c0848b2;
case 0x0c0848b4u: goto P_0c0848b4;
case 0x0c0848b6u: goto P_0c0848b6;
case 0x0c0848b8u: goto P_0c0848b8;
case 0x0c0848bau: goto P_0c0848ba;
case 0x0c0848bcu: goto P_0c0848bc;
case 0x0c0848beu: goto P_0c0848be;
case 0x0c0848c0u: goto P_0c0848c0;
case 0x0c0848c2u: goto P_0c0848c2;
case 0x0c0848c4u: goto P_0c0848c4;
case 0x0c0848c6u: goto P_0c0848c6;
case 0x0c0848c8u: goto P_0c0848c8;
case 0x0c0848cau: goto P_0c0848ca;
case 0x0c0848ccu: goto P_0c0848cc;
case 0x0c0848ceu: goto P_0c0848ce;
case 0x0c0848d0u: goto P_0c0848d0;
case 0x0c0848d2u: goto P_0c0848d2;
case 0x0c0848d4u: goto P_0c0848d4;
case 0x0c0848d6u: goto P_0c0848d6;
case 0x0c0848d8u: goto P_0c0848d8;
case 0x0c0848dau: goto P_0c0848da;
case 0x0c0848dcu: goto P_0c0848dc;
case 0x0c0848deu: goto P_0c0848de;
case 0x0c0848e0u: goto P_0c0848e0;
case 0x0c0848e2u: goto P_0c0848e2;
case 0x0c0848e4u: goto P_0c0848e4;
case 0x0c0848e6u: goto P_0c0848e6;
case 0x0c0848e8u: goto P_0c0848e8;
case 0x0c0848eau: goto P_0c0848ea;
case 0x0c0848ecu: goto P_0c0848ec;
case 0x0c0848eeu: goto P_0c0848ee;
case 0x0c0848f0u: goto P_0c0848f0;
case 0x0c0848f2u: goto P_0c0848f2;
case 0x0c0848f4u: goto P_0c0848f4;
case 0x0c0848f6u: goto P_0c0848f6;
case 0x0c0848f8u: goto P_0c0848f8;
case 0x0c0848fau: goto P_0c0848fa;
case 0x0c0848fcu: goto P_0c0848fc;
case 0x0c0848feu: goto P_0c0848fe;
case 0x0c084900u: goto P_0c084900;
case 0x0c084902u: goto P_0c084902;
case 0x0c084904u: goto P_0c084904;
case 0x0c084906u: goto P_0c084906;
case 0x0c084908u: goto P_0c084908;
case 0x0c08490au: goto P_0c08490a;
case 0x0c08490cu: goto P_0c08490c;
case 0x0c08490eu: goto P_0c08490e;
case 0x0c084910u: goto P_0c084910;
case 0x0c084912u: goto P_0c084912;
case 0x0c084914u: goto P_0c084914;
case 0x0c084916u: goto P_0c084916;
case 0x0c084918u: goto P_0c084918;
case 0x0c08491au: goto P_0c08491a;
case 0x0c08491cu: goto P_0c08491c;
case 0x0c08491eu: goto P_0c08491e;
case 0x0c084920u: goto P_0c084920;
case 0x0c084922u: goto P_0c084922;
case 0x0c084924u: goto P_0c084924;
case 0x0c084926u: goto P_0c084926;
case 0x0c084928u: goto P_0c084928;
case 0x0c08492au: goto P_0c08492a;
case 0x0c08492cu: goto P_0c08492c;
case 0x0c08492eu: goto P_0c08492e;
case 0x0c084930u: goto P_0c084930;
case 0x0c084932u: goto P_0c084932;
case 0x0c084934u: goto P_0c084934;
case 0x0c084936u: goto P_0c084936;
case 0x0c084938u: goto P_0c084938;
case 0x0c08493au: goto P_0c08493a;
case 0x0c08493cu: goto P_0c08493c;
case 0x0c08493eu: goto P_0c08493e;
case 0x0c084940u: goto P_0c084940;
case 0x0c084942u: goto P_0c084942;
case 0x0c084944u: goto P_0c084944;
case 0x0c084946u: goto P_0c084946;
case 0x0c084948u: goto P_0c084948;
case 0x0c08494au: goto P_0c08494a;
case 0x0c08494cu: goto P_0c08494c;
case 0x0c08494eu: goto P_0c08494e;
case 0x0c084950u: goto P_0c084950;
case 0x0c08497cu: goto P_0c08497c;
case 0x0c08497eu: goto P_0c08497e;
case 0x0c084980u: goto P_0c084980;
case 0x0c084982u: goto P_0c084982;
case 0x0c084984u: goto P_0c084984;
case 0x0c084986u: goto P_0c084986;
case 0x0c084988u: goto P_0c084988;
case 0x0c08498au: goto P_0c08498a;
case 0x0c08498cu: goto P_0c08498c;
case 0x0c08498eu: goto P_0c08498e;
case 0x0c084990u: goto P_0c084990;
case 0x0c084992u: goto P_0c084992;
case 0x0c084994u: goto P_0c084994;
case 0x0c084996u: goto P_0c084996;
case 0x0c084998u: goto P_0c084998;
case 0x0c08499au: goto P_0c08499a;
case 0x0c08499cu: goto P_0c08499c;
case 0x0c08499eu: goto P_0c08499e;
case 0x0c0849a0u: goto P_0c0849a0;
case 0x0c0849a2u: goto P_0c0849a2;
case 0x0c0849a4u: goto P_0c0849a4;
case 0x0c0849a6u: goto P_0c0849a6;
case 0x0c0849a8u: goto P_0c0849a8;
case 0x0c0849aau: goto P_0c0849aa;
case 0x0c0849acu: goto P_0c0849ac;
case 0x0c0849aeu: goto P_0c0849ae;
case 0x0c0849b0u: goto P_0c0849b0;
case 0x0c0849b2u: goto P_0c0849b2;
case 0x0c0849b4u: goto P_0c0849b4;
case 0x0c0849b6u: goto P_0c0849b6;
case 0x0c0849b8u: goto P_0c0849b8;
case 0x0c0849bau: goto P_0c0849ba;
case 0x0c0849bcu: goto P_0c0849bc;
case 0x0c0849beu: goto P_0c0849be;
case 0x0c0849c0u: goto P_0c0849c0;
case 0x0c0849c2u: goto P_0c0849c2;
case 0x0c0849c4u: goto P_0c0849c4;
case 0x0c0849c6u: goto P_0c0849c6;
case 0x0c0849c8u: goto P_0c0849c8;
case 0x0c0849cau: goto P_0c0849ca;
case 0x0c0849ccu: goto P_0c0849cc;
case 0x0c0849ceu: goto P_0c0849ce;
case 0x0c0849d0u: goto P_0c0849d0;
case 0x0c0849d2u: goto P_0c0849d2;
case 0x0c0849d4u: goto P_0c0849d4;
case 0x0c0849d6u: goto P_0c0849d6;
case 0x0c0849d8u: goto P_0c0849d8;
case 0x0c0849dau: goto P_0c0849da;
case 0x0c0849dcu: goto P_0c0849dc;
case 0x0c0849deu: goto P_0c0849de;
case 0x0c0849e0u: goto P_0c0849e0;
case 0x0c0849e2u: goto P_0c0849e2;
case 0x0c0849e4u: goto P_0c0849e4;
case 0x0c0849e6u: goto P_0c0849e6;
case 0x0c0849e8u: goto P_0c0849e8;
case 0x0c0849eau: goto P_0c0849ea;
case 0x0c0849ecu: goto P_0c0849ec;
case 0x0c0849eeu: goto P_0c0849ee;
case 0x0c0849f0u: goto P_0c0849f0;
case 0x0c0849f2u: goto P_0c0849f2;
case 0x0c0849f4u: goto P_0c0849f4;
case 0x0c0849f6u: goto P_0c0849f6;
case 0x0c0849f8u: goto P_0c0849f8;
case 0x0c0849fau: goto P_0c0849fa;
case 0x0c0849fcu: goto P_0c0849fc;
case 0x0c0849feu: goto P_0c0849fe;
case 0x0c084a00u: goto P_0c084a00;
case 0x0c084a02u: goto P_0c084a02;
case 0x0c084a04u: goto P_0c084a04;
case 0x0c084a06u: goto P_0c084a06;
case 0x0c084a08u: goto P_0c084a08;
case 0x0c084a0au: goto P_0c084a0a;
case 0x0c084a0cu: goto P_0c084a0c;
case 0x0c084a0eu: goto P_0c084a0e;
case 0x0c084a10u: goto P_0c084a10;
case 0x0c084a12u: goto P_0c084a12;
case 0x0c084a14u: goto P_0c084a14;
case 0x0c084a16u: goto P_0c084a16;
case 0x0c084a18u: goto P_0c084a18;
case 0x0c084a1au: goto P_0c084a1a;
case 0x0c084a1cu: goto P_0c084a1c;
case 0x0c084a1eu: goto P_0c084a1e;
case 0x0c084a20u: goto P_0c084a20;
case 0x0c084a22u: goto P_0c084a22;
case 0x0c084a24u: goto P_0c084a24;
case 0x0c084a26u: goto P_0c084a26;
case 0x0c084a28u: goto P_0c084a28;
case 0x0c084a2au: goto P_0c084a2a;
case 0x0c084a2cu: goto P_0c084a2c;
case 0x0c084a2eu: goto P_0c084a2e;
case 0x0c084a30u: goto P_0c084a30;
case 0x0c084a32u: goto P_0c084a32;
case 0x0c084a34u: goto P_0c084a34;
case 0x0c084a36u: goto P_0c084a36;
case 0x0c084a38u: goto P_0c084a38;
case 0x0c084a3au: goto P_0c084a3a;
case 0x0c084a3cu: goto P_0c084a3c;
case 0x0c084a3eu: goto P_0c084a3e;
case 0x0c084a40u: goto P_0c084a40;
case 0x0c084a42u: goto P_0c084a42;
case 0x0c084a44u: goto P_0c084a44;
case 0x0c084a46u: goto P_0c084a46;
case 0x0c084a48u: goto P_0c084a48;
case 0x0c084a4au: goto P_0c084a4a;
case 0x0c084a4cu: goto P_0c084a4c;
case 0x0c084a4eu: goto P_0c084a4e;
case 0x0c084a50u: goto P_0c084a50;
case 0x0c084a52u: goto P_0c084a52;
case 0x0c084a54u: goto P_0c084a54;
case 0x0c084a56u: goto P_0c084a56;
case 0x0c084a58u: goto P_0c084a58;
case 0x0c084a5au: goto P_0c084a5a;
case 0x0c084a5cu: goto P_0c084a5c;
case 0x0c084a5eu: goto P_0c084a5e;
case 0x0c084a60u: goto P_0c084a60;
case 0x0c084a62u: goto P_0c084a62;
case 0x0c084a64u: goto P_0c084a64;
case 0x0c084a66u: goto P_0c084a66;
case 0x0c084a68u: goto P_0c084a68;
case 0x0c084a6au: goto P_0c084a6a;
case 0x0c084a6cu: goto P_0c084a6c;
case 0x0c084a6eu: goto P_0c084a6e;
case 0x0c084a70u: goto P_0c084a70;
case 0x0c084a72u: goto P_0c084a72;
case 0x0c084a74u: goto P_0c084a74;
case 0x0c084a76u: goto P_0c084a76;
case 0x0c084a78u: goto P_0c084a78;
case 0x0c084a7au: goto P_0c084a7a;
case 0x0c084a7cu: goto P_0c084a7c;
case 0x0c084a7eu: goto P_0c084a7e;
case 0x0c084a80u: goto P_0c084a80;
case 0x0c084a82u: goto P_0c084a82;
case 0x0c084a84u: goto P_0c084a84;
case 0x0c084a86u: goto P_0c084a86;
case 0x0c084a88u: goto P_0c084a88;
case 0x0c084a8au: goto P_0c084a8a;
case 0x0c084a8cu: goto P_0c084a8c;
case 0x0c084a8eu: goto P_0c084a8e;
case 0x0c084a90u: goto P_0c084a90;
case 0x0c084a92u: goto P_0c084a92;
case 0x0c084a94u: goto P_0c084a94;
default: return vf3_matrix_family(target,s,ram);
}
P_0c084864: /* original 2fe6, guest PC 0x0c084864 */
if(!s->budget--) { s->failed_pc=0x0c084864u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084866;
P_0c084866: /* original e010, guest PC 0x0c084866 */
if(!s->budget--) { s->failed_pc=0x0c084866u; return 0; }
r[0]=0x00000010u;
goto P_0c084868;
P_0c084868: /* original 2fd6, guest PC 0x0c084868 */
if(!s->budget--) { s->failed_pc=0x0c084868u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08486a;
P_0c08486a: /* original 2fc6, guest PC 0x0c08486a */
if(!s->budget--) { s->failed_pc=0x0c08486au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08486c;
P_0c08486c: /* original 2fb6, guest PC 0x0c08486c */
if(!s->budget--) { s->failed_pc=0x0c08486cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08486e;
P_0c08486e: /* original 2fa6, guest PC 0x0c08486e */
if(!s->budget--) { s->failed_pc=0x0c08486eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084870;
P_0c084870: /* original 2f96, guest PC 0x0c084870 */
if(!s->budget--) { s->failed_pc=0x0c084870u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084872;
P_0c084872: /* original 6943, guest PC 0x0c084872 */
if(!s->budget--) { s->failed_pc=0x0c084872u; return 0; }
r[9]=r[4];
goto P_0c084874;
P_0c084874: /* original 2f86, guest PC 0x0c084874 */
if(!s->budget--) { s->failed_pc=0x0c084874u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084876;
P_0c084876: /* original fffb, guest PC 0x0c084876 */
if(!s->budget--) { s->failed_pc=0x0c084876u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c084878;
P_0c084878: /* original ffeb, guest PC 0x0c084878 */
if(!s->budget--) { s->failed_pc=0x0c084878u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08487a;
P_0c08487a: /* original ffdb, guest PC 0x0c08487a */
if(!s->budget--) { s->failed_pc=0x0c08487au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c08487c;
P_0c08487c: /* original dc36, guest PC 0x0c08487c */
if(!s->budget--) { s->failed_pc=0x0c08487cu; return 0; }
r[12]=read(ram,0x0c084958u,4);
goto P_0c08487e;
P_0c08487e: /* original 4f22, guest PC 0x0c08487e */
if(!s->budget--) { s->failed_pc=0x0c08487eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c084880;
P_0c084880: /* original 54c8, guest PC 0x0c084880 */
if(!s->budget--) { s->failed_pc=0x0c084880u; return 0; }
r[4]=read(ram,r[12]+32,4);
goto P_0c084882;
P_0c084882: /* original f446, guest PC 0x0c084882 */
if(!s->budget--) { s->failed_pc=0x0c084882u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c084884;
P_0c084884: /* original e018, guest PC 0x0c084884 */
if(!s->budget--) { s->failed_pc=0x0c084884u; return 0; }
r[0]=0x00000018u;
goto P_0c084886;
P_0c084886: /* original f546, guest PC 0x0c084886 */
if(!s->budget--) { s->failed_pc=0x0c084886u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c084888;
P_0c084888: /* original c734, guest PC 0x0c084888 */
if(!s->budget--) { s->failed_pc=0x0c084888u; return 0; }
r[0]=code_base|0x0008495cu;
goto P_0c08488a;
P_0c08488a: /* original f34c, guest PC 0x0c08488a */
if(!s->budget--) { s->failed_pc=0x0c08488au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08488c;
P_0c08488c: /* original f432, guest PC 0x0c08488c */
if(!s->budget--) { s->failed_pc=0x0c08488cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c08488e;
P_0c08488e: /* original f05c, guest PC 0x0c08488e */
if(!s->budget--) { s->failed_pc=0x0c08488eu; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c084890;
P_0c084890: /* original 7ffc, guest PC 0x0c084890 */
if(!s->budget--) { s->failed_pc=0x0c084890u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c084892;
P_0c084892: /* original f208, guest PC 0x0c084892 */
if(!s->budget--) { s->failed_pc=0x0c084892u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c084894;
P_0c084894: /* original f45e, guest PC 0x0c084894 */
if(!s->budget--) { s->failed_pc=0x0c084894u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[5],fr[4],r[18]);
goto P_0c084896;
P_0c084896: /* original f425, guest PC 0x0c084896 */
if(!s->budget--) { s->failed_pc=0x0c084896u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c084898;
P_0c084898: /* original 894e, guest PC 0x0c084898 */
if(!s->budget--) { s->failed_pc=0x0c084898u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c084938; }
goto P_0c08489a;
P_0c08489a: /* original 54c4, guest PC 0x0c08489a */
if(!s->budget--) { s->failed_pc=0x0c08489au; return 0; }
r[4]=read(ram,r[12]+16,4);
goto P_0c08489c;
P_0c08489c: /* original 6e93, guest PC 0x0c08489c */
if(!s->budget--) { s->failed_pc=0x0c08489cu; return 0; }
r[14]=r[9];
goto P_0c08489e;
P_0c08489e: /* original d230, guest PC 0x0c08489e */
if(!s->budget--) { s->failed_pc=0x0c08489eu; return 0; }
r[2]=read(ram,0x0c084960u,4);
goto P_0c0848a0;
P_0c0848a0: /* original ea02, guest PC 0x0c0848a0 */
if(!s->budget--) { s->failed_pc=0x0c0848a0u; return 0; }
r[10]=0x00000002u;
goto P_0c0848a2;
P_0c0848a2: /* original 7e18, guest PC 0x0c0848a2 */
if(!s->budget--) { s->failed_pc=0x0c0848a2u; return 0; }
r[14]+=0x00000018u;
goto P_0c0848a4;
P_0c0848a4: /* original a045, guest PC 0x0c0848a4 */
if(!s->budget--) { s->failed_pc=0x0c0848a4u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c084932;
P_0c0848a6: /* original 2f22, guest PC 0x0c0848a6 */
if(!s->budget--) { s->failed_pc=0x0c0848a6u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0848a8;
P_0c0848a8: /* original 9053, guest PC 0x0c0848a8 */
if(!s->budget--) { s->failed_pc=0x0c0848a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084952u,2);
goto P_0c0848aa;
P_0c0848aa: /* original e604, guest PC 0x0c0848aa */
if(!s->budget--) { s->failed_pc=0x0c0848aau; return 0; }
r[6]=0x00000004u;
goto P_0c0848ac;
P_0c0848ac: /* original 054e, guest PC 0x0c0848ac */
if(!s->budget--) { s->failed_pc=0x0c0848acu; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0848ae;
P_0c0848ae: /* original 2568, guest PC 0x0c0848ae */
if(!s->budget--) { s->failed_pc=0x0c0848aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[6])==0)!=0);
goto P_0c0848b0;
P_0c0848b0: /* original 8b3b, guest PC 0x0c0848b0 */
if(!s->budget--) { s->failed_pc=0x0c0848b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08492a; }
goto P_0c0848b2;
P_0c0848b2: /* original 904f, guest PC 0x0c0848b2 */
if(!s->budget--) { s->failed_pc=0x0c0848b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084954u,2);
goto P_0c0848b4;
P_0c0848b4: /* original e50f, guest PC 0x0c0848b4 */
if(!s->budget--) { s->failed_pc=0x0c0848b4u; return 0; }
r[5]=0x0000000fu;
goto P_0c0848b6;
P_0c0848b6: /* original f446, guest PC 0x0c0848b6 */
if(!s->budget--) { s->failed_pc=0x0c0848b6u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0848b8;
P_0c0848b8: /* original e01c, guest PC 0x0c0848b8 */
if(!s->budget--) { s->failed_pc=0x0c0848b8u; return 0; }
r[0]=0x0000001cu;
goto P_0c0848ba;
P_0c0848ba: /* original d42a, guest PC 0x0c0848ba */
if(!s->budget--) { s->failed_pc=0x0c0848bau; return 0; }
r[4]=read(ram,0x0c084964u,4);
goto P_0c0848bc;
P_0c0848bc: /* original 044c, guest PC 0x0c0848bc */
if(!s->budget--) { s->failed_pc=0x0c0848bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0848be;
P_0c0848be: /* original 644c, guest PC 0x0c0848be */
if(!s->budget--) { s->failed_pc=0x0c0848beu; return 0; }
r[4]=r[4]&255u;
goto P_0c0848c0;
P_0c0848c0: /* original 2459, guest PC 0x0c0848c0 */
if(!s->budget--) { s->failed_pc=0x0c0848c0u; return 0; }
r[4]&=r[5];
goto P_0c0848c2;
P_0c0848c2: /* original 65f2, guest PC 0x0c0848c2 */
if(!s->budget--) { s->failed_pc=0x0c0848c2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0848c4;
P_0c0848c4: /* original 4408, guest PC 0x0c0848c4 */
if(!s->budget--) { s->failed_pc=0x0c0848c4u; return 0; }
r[4]<<=2;
goto P_0c0848c6;
P_0c0848c6: /* original 6043, guest PC 0x0c0848c6 */
if(!s->budget--) { s->failed_pc=0x0c0848c6u; return 0; }
r[0]=r[4];
goto P_0c0848c8;
P_0c0848c8: /* original f556, guest PC 0x0c0848c8 */
if(!s->budget--) { s->failed_pc=0x0c0848c8u; return 0; }
vf3_matrix_load(s,ram,5,r[5]+r[0]);
goto P_0c0848ca;
P_0c0848ca: /* original c727, guest PC 0x0c0848ca */
if(!s->budget--) { s->failed_pc=0x0c0848cau; return 0; }
r[0]=code_base|0x00084968u;
goto P_0c0848cc;
P_0c0848cc: /* original f608, guest PC 0x0c0848cc */
if(!s->budget--) { s->failed_pc=0x0c0848ccu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0848ce;
P_0c0848ce: /* original f560, guest PC 0x0c0848ce */
if(!s->budget--) { s->failed_pc=0x0c0848ceu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'+');
goto P_0c0848d0;
P_0c0848d0: /* original f545, guest PC 0x0c0848d0 */
if(!s->budget--) { s->failed_pc=0x0c0848d0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c0848d2;
P_0c0848d2: /* original 8d0d, guest PC 0x0c0848d2 */
if(!s->budget--) { s->failed_pc=0x0c0848d2u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(cond) { goto P_0c0848f0; }
goto P_0c0848d6;
P_0c0848d4: /* original e400, guest PC 0x0c0848d4 */
if(!s->budget--) { s->failed_pc=0x0c0848d4u; return 0; }
r[4]=0x00000000u;
goto P_0c0848d6;
P_0c0848d6: /* original f451, guest PC 0x0c0848d6 */
if(!s->budget--) { s->failed_pc=0x0c0848d6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c0848d8;
P_0c0848d8: /* original c724, guest PC 0x0c0848d8 */
if(!s->budget--) { s->failed_pc=0x0c0848d8u; return 0; }
r[0]=code_base|0x0008496cu;
goto P_0c0848da;
P_0c0848da: /* original f508, guest PC 0x0c0848da */
if(!s->budget--) { s->failed_pc=0x0c0848dau; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0848dc;
P_0c0848dc: /* original e50d, guest PC 0x0c0848dc */
if(!s->budget--) { s->failed_pc=0x0c0848dcu; return 0; }
r[5]=0x0000000du;
goto P_0c0848de;
P_0c0848de: /* original f452, guest PC 0x0c0848de */
if(!s->budget--) { s->failed_pc=0x0c0848deu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0848e0;
P_0c0848e0: /* original f43d, guest PC 0x0c0848e0 */
if(!s->budget--) { s->failed_pc=0x0c0848e0u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0848e2;
P_0c0848e2: /* original 045a, guest PC 0x0c0848e2 */
if(!s->budget--) { s->failed_pc=0x0c0848e2u; return 0; }
r[4]=r[53];
goto P_0c0848e4;
P_0c0848e4: /* original 644f, guest PC 0x0c0848e4 */
if(!s->budget--) { s->failed_pc=0x0c0848e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0848e6;
P_0c0848e6: /* original 4408, guest PC 0x0c0848e6 */
if(!s->budget--) { s->failed_pc=0x0c0848e6u; return 0; }
r[4]<<=2;
goto P_0c0848e8;
P_0c0848e8: /* original 624f, guest PC 0x0c0848e8 */
if(!s->budget--) { s->failed_pc=0x0c0848e8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0848ea;
P_0c0848ea: /* original 3253, guest PC 0x0c0848ea */
if(!s->budget--) { s->failed_pc=0x0c0848eau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[5])!=0);
goto P_0c0848ec;
P_0c0848ec: /* original 8b00, guest PC 0x0c0848ec */
if(!s->budget--) { s->failed_pc=0x0c0848ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0848f0; }
goto P_0c0848ee;
P_0c0848ee: /* original 6453, guest PC 0x0c0848ee */
if(!s->budget--) { s->failed_pc=0x0c0848eeu; return 0; }
r[4]=r[5];
goto P_0c0848f0;
P_0c0848f0: /* original 644f, guest PC 0x0c0848f0 */
if(!s->budget--) { s->failed_pc=0x0c0848f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0848f2;
P_0c0848f2: /* original e50e, guest PC 0x0c0848f2 */
if(!s->budget--) { s->failed_pc=0x0c0848f2u; return 0; }
r[5]=0x0000000eu;
goto P_0c0848f4;
P_0c0848f4: /* original 3548, guest PC 0x0c0848f4 */
if(!s->budget--) { s->failed_pc=0x0c0848f4u; return 0; }
r[5]-=r[4];
goto P_0c0848f6;
P_0c0848f6: /* original 6d53, guest PC 0x0c0848f6 */
if(!s->budget--) { s->failed_pc=0x0c0848f6u; return 0; }
r[13]=r[5];
goto P_0c0848f8;
P_0c0848f8: /* original 62df, guest PC 0x0c0848f8 */
if(!s->budget--) { s->failed_pc=0x0c0848f8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c0848fa;
P_0c0848fa: /* original 4215, guest PC 0x0c0848fa */
if(!s->budget--) { s->failed_pc=0x0c0848fau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0848fc;
P_0c0848fc: /* original 8b15, guest PC 0x0c0848fc */
if(!s->budget--) { s->failed_pc=0x0c0848fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08492a; }
goto P_0c0848fe;
P_0c0848fe: /* original e004, guest PC 0x0c0848fe */
if(!s->budget--) { s->failed_pc=0x0c0848feu; return 0; }
r[0]=0x00000004u;
goto P_0c084900;
P_0c084900: /* original d81b, guest PC 0x0c084900 */
if(!s->budget--) { s->failed_pc=0x0c084900u; return 0; }
r[8]=read(ram,0x0c084970u,4);
goto P_0c084902;
P_0c084902: /* original fde6, guest PC 0x0c084902 */
if(!s->budget--) { s->failed_pc=0x0c084902u; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c084904;
P_0c084904: /* original e008, guest PC 0x0c084904 */
if(!s->budget--) { s->failed_pc=0x0c084904u; return 0; }
r[0]=0x00000008u;
goto P_0c084906;
P_0c084906: /* original ffe6, guest PC 0x0c084906 */
if(!s->budget--) { s->failed_pc=0x0c084906u; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c084908;
P_0c084908: /* original e028, guest PC 0x0c084908 */
if(!s->budget--) { s->failed_pc=0x0c084908u; return 0; }
r[0]=0x00000028u;
goto P_0c08490a;
P_0c08490a: /* original fee8, guest PC 0x0c08490a */
if(!s->budget--) { s->failed_pc=0x0c08490au; return 0; }
vf3_matrix_load(s,ram,14,r[14]);
goto P_0c08490c;
P_0c08490c: /* original 480b, guest PC 0x0c08490c */
if(!s->budget--) { s->failed_pc=0x0c08490cu; return 0; }
target=r[8];
r[16]=code_base|0x0c084910u;
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084910u) { target=s->pc; goto dispatch; }
goto P_0c084910;
P_0c08490e: /* original 0bed, guest PC 0x0c08490e */
if(!s->budget--) { s->failed_pc=0x0c08490eu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c084910;
P_0c084910: /* original d818, guest PC 0x0c084910 */
if(!s->budget--) { s->failed_pc=0x0c084910u; return 0; }
r[8]=read(ram,0x0c084974u,4);
goto P_0c084912;
P_0c084912: /* original f5dc, guest PC 0x0c084912 */
if(!s->budget--) { s->failed_pc=0x0c084912u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c084914;
P_0c084914: /* original f6fc, guest PC 0x0c084914 */
if(!s->budget--) { s->failed_pc=0x0c084914u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c084916;
P_0c084916: /* original 480b, guest PC 0x0c084916 */
if(!s->budget--) { s->failed_pc=0x0c084916u; return 0; }
target=r[8];
r[16]=code_base|0x0c08491au;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08491au) { target=s->pc; goto dispatch; }
goto P_0c08491a;
P_0c084918: /* original f4ec, guest PC 0x0c084918 */
if(!s->budget--) { s->failed_pc=0x0c084918u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c08491a;
P_0c08491a: /* original d817, guest PC 0x0c08491a */
if(!s->budget--) { s->failed_pc=0x0c08491au; return 0; }
r[8]=read(ram,0x0c084978u,4);
goto P_0c08491c;
P_0c08491c: /* original 480b, guest PC 0x0c08491c */
if(!s->budget--) { s->failed_pc=0x0c08491cu; return 0; }
target=r[8];
r[16]=code_base|0x0c084920u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084920u) { target=s->pc; goto dispatch; }
goto P_0c084920;
P_0c08491e: /* original 64b3, guest PC 0x0c08491e */
if(!s->budget--) { s->failed_pc=0x0c08491eu; return 0; }
r[4]=r[11];
goto P_0c084920;
P_0c084920: /* original 7dff, guest PC 0x0c084920 */
if(!s->budget--) { s->failed_pc=0x0c084920u; return 0; }
r[13]+=0xffffffffu;
goto P_0c084922;
P_0c084922: /* original 63df, guest PC 0x0c084922 */
if(!s->budget--) { s->failed_pc=0x0c084922u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c084924;
P_0c084924: /* original 4315, guest PC 0x0c084924 */
if(!s->budget--) { s->failed_pc=0x0c084924u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c084926;
P_0c084926: /* original 8dea, guest PC 0x0c084926 */
if(!s->budget--) { s->failed_pc=0x0c084926u; return 0; }
cond=r[17]&1u;
r[14]+=0x0000002cu;
if(cond) { goto P_0c0848fe; }
goto P_0c08492a;
P_0c084928: /* original 7e2c, guest PC 0x0c084928 */
if(!s->budget--) { s->failed_pc=0x0c084928u; return 0; }
r[14]+=0x0000002cu;
goto P_0c08492a;
P_0c08492a: /* original 9e14, guest PC 0x0c08492a */
if(!s->budget--) { s->failed_pc=0x0c08492au; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084956u,2);
goto P_0c08492c;
P_0c08492c: /* original 7aff, guest PC 0x0c08492c */
if(!s->budget--) { s->failed_pc=0x0c08492cu; return 0; }
r[10]+=0xffffffffu;
goto P_0c08492e;
P_0c08492e: /* original 54c5, guest PC 0x0c08492e */
if(!s->budget--) { s->failed_pc=0x0c08492eu; return 0; }
r[4]=read(ram,r[12]+20,4);
goto P_0c084930;
P_0c084930: /* original 3e9c, guest PC 0x0c084930 */
if(!s->budget--) { s->failed_pc=0x0c084930u; return 0; }
r[14]+=r[9];
goto P_0c084932;
P_0c084932: /* original 63af, guest PC 0x0c084932 */
if(!s->budget--) { s->failed_pc=0x0c084932u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[10];
goto P_0c084934;
P_0c084934: /* original 4315, guest PC 0x0c084934 */
if(!s->budget--) { s->failed_pc=0x0c084934u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c084936;
P_0c084936: /* original 89b7, guest PC 0x0c084936 */
if(!s->budget--) { s->failed_pc=0x0c084936u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0848a8; }
goto P_0c084938;
P_0c084938: /* original 7f04, guest PC 0x0c084938 */
if(!s->budget--) { s->failed_pc=0x0c084938u; return 0; }
r[15]+=0x00000004u;
goto P_0c08493a;
P_0c08493a: /* original 4f26, guest PC 0x0c08493a */
if(!s->budget--) { s->failed_pc=0x0c08493au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08493c;
P_0c08493c: /* original fdf9, guest PC 0x0c08493c */
if(!s->budget--) { s->failed_pc=0x0c08493cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08493e;
P_0c08493e: /* original fef9, guest PC 0x0c08493e */
if(!s->budget--) { s->failed_pc=0x0c08493eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084940;
P_0c084940: /* original fff9, guest PC 0x0c084940 */
if(!s->budget--) { s->failed_pc=0x0c084940u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084942;
P_0c084942: /* original 68f6, guest PC 0x0c084942 */
if(!s->budget--) { s->failed_pc=0x0c084942u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c084944;
P_0c084944: /* original 69f6, guest PC 0x0c084944 */
if(!s->budget--) { s->failed_pc=0x0c084944u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c084946;
P_0c084946: /* original 6af6, guest PC 0x0c084946 */
if(!s->budget--) { s->failed_pc=0x0c084946u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c084948;
P_0c084948: /* original 6bf6, guest PC 0x0c084948 */
if(!s->budget--) { s->failed_pc=0x0c084948u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08494a;
P_0c08494a: /* original 6cf6, guest PC 0x0c08494a */
if(!s->budget--) { s->failed_pc=0x0c08494au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08494c;
P_0c08494c: /* original 6df6, guest PC 0x0c08494c */
if(!s->budget--) { s->failed_pc=0x0c08494cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08494e;
P_0c08494e: /* original 000b, guest PC 0x0c08494e */
if(!s->budget--) { s->failed_pc=0x0c08494eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c084950: /* original 6ef6, guest PC 0x0c084950 */
if(!s->budget--) { s->failed_pc=0x0c084950u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c084952u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c084952u; return 0; } return 1;
P_0c08497c: /* original 2fe6, guest PC 0x0c08497c */
if(!s->budget--) { s->failed_pc=0x0c08497cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08497e;
P_0c08497e: /* original c758, guest PC 0x0c08497e */
if(!s->budget--) { s->failed_pc=0x0c08497eu; return 0; }
r[0]=code_base|0x00084ae0u;
goto P_0c084980;
P_0c084980: /* original 2fd6, guest PC 0x0c084980 */
if(!s->budget--) { s->failed_pc=0x0c084980u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084982;
P_0c084982: /* original e30f, guest PC 0x0c084982 */
if(!s->budget--) { s->failed_pc=0x0c084982u; return 0; }
r[3]=0x0000000fu;
goto P_0c084984;
P_0c084984: /* original 2fc6, guest PC 0x0c084984 */
if(!s->budget--) { s->failed_pc=0x0c084984u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084986;
P_0c084986: /* original 6c43, guest PC 0x0c084986 */
if(!s->budget--) { s->failed_pc=0x0c084986u; return 0; }
r[12]=r[4];
goto P_0c084988;
P_0c084988: /* original fffb, guest PC 0x0c084988 */
if(!s->budget--) { s->failed_pc=0x0c084988u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08498a;
P_0c08498a: /* original e201, guest PC 0x0c08498a */
if(!s->budget--) { s->failed_pc=0x0c08498au; return 0; }
r[2]=0x00000001u;
goto P_0c08498c;
P_0c08498c: /* original ffeb, guest PC 0x0c08498c */
if(!s->budget--) { s->failed_pc=0x0c08498cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08498e;
P_0c08498e: /* original 6e53, guest PC 0x0c08498e */
if(!s->budget--) { s->failed_pc=0x0c08498eu; return 0; }
r[14]=r[5];
goto P_0c084990;
P_0c084990: /* original ffdb, guest PC 0x0c084990 */
if(!s->budget--) { s->failed_pc=0x0c084990u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c084992;
P_0c084992: /* original 6dc1, guest PC 0x0c084992 */
if(!s->budget--) { s->failed_pc=0x0c084992u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[13]=tmp;
goto P_0c084994;
P_0c084994: /* original 4f22, guest PC 0x0c084994 */
if(!s->budget--) { s->failed_pc=0x0c084994u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c084996;
P_0c084996: /* original 7d01, guest PC 0x0c084996 */
if(!s->budget--) { s->failed_pc=0x0c084996u; return 0; }
r[13]+=0x00000001u;
goto P_0c084998;
P_0c084998: /* original ff08, guest PC 0x0c084998 */
if(!s->budget--) { s->failed_pc=0x0c084998u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08499a;
P_0c08499a: /* original 2d39, guest PC 0x0c08499a */
if(!s->budget--) { s->failed_pc=0x0c08499au; return 0; }
r[13]&=r[3];
goto P_0c08499c;
P_0c08499c: /* original 3d23, guest PC 0x0c08499c */
if(!s->budget--) { s->failed_pc=0x0c08499cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[2])!=0);
goto P_0c08499e;
P_0c08499e: /* original 7fe8, guest PC 0x0c08499e */
if(!s->budget--) { s->failed_pc=0x0c08499eu; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0849a0;
P_0c0849a0: /* original c750, guest PC 0x0c0849a0 */
if(!s->budget--) { s->failed_pc=0x0c0849a0u; return 0; }
r[0]=code_base|0x00084ae4u;
goto P_0c0849a2;
P_0c0849a2: /* original 8f03, guest PC 0x0c0849a2 */
if(!s->budget--) { s->failed_pc=0x0c0849a2u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,14,r[0]);
if(!cond) { goto P_0c0849ac; }
goto P_0c0849a6;
P_0c0849a4: /* original fe08, guest PC 0x0c0849a4 */
if(!s->budget--) { s->failed_pc=0x0c0849a4u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c0849a6;
P_0c0849a6: /* original 85c2, guest PC 0x0c0849a6 */
if(!s->budget--) { s->failed_pc=0x0c0849a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+4,2);
goto P_0c0849a8;
P_0c0849a8: /* original 2008, guest PC 0x0c0849a8 */
if(!s->budget--) { s->failed_pc=0x0c0849a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0849aa;
P_0c0849aa: /* original 896b, guest PC 0x0c0849aa */
if(!s->budget--) { s->failed_pc=0x0c0849aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c084a84; }
goto P_0c0849ac;
P_0c0849ac: /* original 62d3, guest PC 0x0c0849ac */
if(!s->budget--) { s->failed_pc=0x0c0849acu; return 0; }
r[2]=r[13];
goto P_0c0849ae;
P_0c0849ae: /* original 63d3, guest PC 0x0c0849ae */
if(!s->budget--) { s->failed_pc=0x0c0849aeu; return 0; }
r[3]=r[13];
goto P_0c0849b0;
P_0c0849b0: /* original 4208, guest PC 0x0c0849b0 */
if(!s->budget--) { s->failed_pc=0x0c0849b0u; return 0; }
r[2]<<=2;
goto P_0c0849b2;
P_0c0849b2: /* original d44d, guest PC 0x0c0849b2 */
if(!s->budget--) { s->failed_pc=0x0c0849b2u; return 0; }
r[4]=read(ram,0x0c084ae8u,4);
goto P_0c0849b4;
P_0c0849b4: /* original 4300, guest PC 0x0c0849b4 */
if(!s->budget--) { s->failed_pc=0x0c0849b4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0849b6;
P_0c0849b6: /* original 332c, guest PC 0x0c0849b6 */
if(!s->budget--) { s->failed_pc=0x0c0849b6u; return 0; }
r[3]+=r[2];
goto P_0c0849b8;
P_0c0849b8: /* original 4308, guest PC 0x0c0849b8 */
if(!s->budget--) { s->failed_pc=0x0c0849b8u; return 0; }
r[3]<<=2;
goto P_0c0849ba;
P_0c0849ba: /* original 343c, guest PC 0x0c0849ba */
if(!s->budget--) { s->failed_pc=0x0c0849bau; return 0; }
r[4]+=r[3];
goto P_0c0849bc;
P_0c0849bc: /* original f349, guest PC 0x0c0849bc */
if(!s->budget--) { s->failed_pc=0x0c0849bcu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0849be;
P_0c0849be: /* original e00c, guest PC 0x0c0849be */
if(!s->budget--) { s->failed_pc=0x0c0849beu; return 0; }
r[0]=0x0000000cu;
goto P_0c0849c0;
P_0c0849c0: /* original ff37, guest PC 0x0c0849c0 */
if(!s->budget--) { s->failed_pc=0x0c0849c0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0849c2;
P_0c0849c2: /* original e014, guest PC 0x0c0849c2 */
if(!s->budget--) { s->failed_pc=0x0c0849c2u; return 0; }
r[0]=0x00000014u;
goto P_0c0849c4;
P_0c0849c4: /* original fd49, guest PC 0x0c0849c4 */
if(!s->budget--) { s->failed_pc=0x0c0849c4u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0849c6;
P_0c0849c6: /* original f349, guest PC 0x0c0849c6 */
if(!s->budget--) { s->failed_pc=0x0c0849c6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0849c8;
P_0c0849c8: /* original ff37, guest PC 0x0c0849c8 */
if(!s->budget--) { s->failed_pc=0x0c0849c8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0849ca;
P_0c0849ca: /* original e004, guest PC 0x0c0849ca */
if(!s->budget--) { s->failed_pc=0x0c0849cau; return 0; }
r[0]=0x00000004u;
goto P_0c0849cc;
P_0c0849cc: /* original f349, guest PC 0x0c0849cc */
if(!s->budget--) { s->failed_pc=0x0c0849ccu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0849ce;
P_0c0849ce: /* original ff37, guest PC 0x0c0849ce */
if(!s->budget--) { s->failed_pc=0x0c0849ceu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0849d0;
P_0c0849d0: /* original e010, guest PC 0x0c0849d0 */
if(!s->budget--) { s->failed_pc=0x0c0849d0u; return 0; }
r[0]=0x00000010u;
goto P_0c0849d2;
P_0c0849d2: /* original f349, guest PC 0x0c0849d2 */
if(!s->budget--) { s->failed_pc=0x0c0849d2u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0849d4;
P_0c0849d4: /* original ff37, guest PC 0x0c0849d4 */
if(!s->budget--) { s->failed_pc=0x0c0849d4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0849d6;
P_0c0849d6: /* original e008, guest PC 0x0c0849d6 */
if(!s->budget--) { s->failed_pc=0x0c0849d6u; return 0; }
r[0]=0x00000008u;
goto P_0c0849d8;
P_0c0849d8: /* original d344, guest PC 0x0c0849d8 */
if(!s->budget--) { s->failed_pc=0x0c0849d8u; return 0; }
r[3]=read(ram,0x0c084aecu,4);
goto P_0c0849da;
P_0c0849da: /* original f348, guest PC 0x0c0849da */
if(!s->budget--) { s->failed_pc=0x0c0849dau; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c0849dc;
P_0c0849dc: /* original 430b, guest PC 0x0c0849dc */
if(!s->budget--) { s->failed_pc=0x0c0849dcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0849e0u;
vf3_matrix_store(s,ram,3,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0849e0u) { target=s->pc; goto dispatch; }
goto P_0c0849e0;
P_0c0849de: /* original ff37, guest PC 0x0c0849de */
if(!s->budget--) { s->failed_pc=0x0c0849deu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0849e0;
P_0c0849e0: /* original 957d, guest PC 0x0c0849e0 */
if(!s->budget--) { s->failed_pc=0x0c0849e0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084adeu,2);
goto P_0c0849e2;
P_0c0849e2: /* original 6603, guest PC 0x0c0849e2 */
if(!s->budget--) { s->failed_pc=0x0c0849e2u; return 0; }
r[6]=r[0];
goto P_0c0849e4;
P_0c0849e4: /* original e203, guest PC 0x0c0849e4 */
if(!s->budget--) { s->failed_pc=0x0c0849e4u; return 0; }
r[2]=0x00000003u;
goto P_0c0849e6;
P_0c0849e6: /* original 6403, guest PC 0x0c0849e6 */
if(!s->budget--) { s->failed_pc=0x0c0849e6u; return 0; }
r[4]=r[0];
goto P_0c0849e8;
P_0c0849e8: /* original 2659, guest PC 0x0c0849e8 */
if(!s->budget--) { s->failed_pc=0x0c0849e8u; return 0; }
r[6]&=r[5];
goto P_0c0849ea;
P_0c0849ea: /* original d041, guest PC 0x0c0849ea */
if(!s->budget--) { s->failed_pc=0x0c0849eau; return 0; }
r[0]=read(ram,0x0c084af0u,4);
goto P_0c0849ec;
P_0c0849ec: /* original 465a, guest PC 0x0c0849ec */
if(!s->budget--) { s->failed_pc=0x0c0849ecu; return 0; }
r[53]=r[6];
goto P_0c0849ee;
P_0c0849ee: /* original e3f9, guest PC 0x0c0849ee */
if(!s->budget--) { s->failed_pc=0x0c0849eeu; return 0; }
r[3]=0xfffffff9u;
goto P_0c0849f0;
P_0c0849f0: /* original 6643, guest PC 0x0c0849f0 */
if(!s->budget--) { s->failed_pc=0x0c0849f0u; return 0; }
r[6]=r[4];
goto P_0c0849f2;
P_0c0849f2: /* original 2249, guest PC 0x0c0849f2 */
if(!s->budget--) { s->failed_pc=0x0c0849f2u; return 0; }
r[2]&=r[4];
goto P_0c0849f4;
P_0c0849f4: /* original e70e, guest PC 0x0c0849f4 */
if(!s->budget--) { s->failed_pc=0x0c0849f4u; return 0; }
r[7]=0x0000000eu;
goto P_0c0849f6;
P_0c0849f6: /* original 463c, guest PC 0x0c0849f6 */
if(!s->budget--) { s->failed_pc=0x0c0849f6u; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[6]>>((-r[3])&31u)):((int32_t)r[6]<0?0xffffffffu:0)):r[6]<<(r[3]&31u);
goto P_0c0849f8;
P_0c0849f8: /* original f32d, guest PC 0x0c0849f8 */
if(!s->budget--) { s->failed_pc=0x0c0849f8u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0849fa;
P_0c0849fa: /* original 4208, guest PC 0x0c0849fa */
if(!s->budget--) { s->failed_pc=0x0c0849fau; return 0; }
r[2]<<=2;
goto P_0c0849fc;
P_0c0849fc: /* original 6343, guest PC 0x0c0849fc */
if(!s->budget--) { s->failed_pc=0x0c0849fcu; return 0; }
r[3]=r[4];
goto P_0c0849fe;
P_0c0849fe: /* original 2679, guest PC 0x0c0849fe */
if(!s->budget--) { s->failed_pc=0x0c0849feu; return 0; }
r[6]&=r[7];
goto P_0c084a00;
P_0c084a00: /* original f626, guest PC 0x0c084a00 */
if(!s->budget--) { s->failed_pc=0x0c084a00u; return 0; }
vf3_matrix_load(s,ram,6,r[2]+r[0]);
goto P_0c084a02;
P_0c084a02: /* original 4601, guest PC 0x0c084a02 */
if(!s->budget--) { s->failed_pc=0x0c084a02u; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c084a04;
P_0c084a04: /* original d03b, guest PC 0x0c084a04 */
if(!s->budget--) { s->failed_pc=0x0c084a04u; return 0; }
r[0]=read(ram,0x0c084af4u,4);
goto P_0c084a06;
P_0c084a06: /* original 4600, guest PC 0x0c084a06 */
if(!s->budget--) { s->failed_pc=0x0c084a06u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c084a08;
P_0c084a08: /* original 066d, guest PC 0x0c084a08 */
if(!s->budget--) { s->failed_pc=0x0c084a08u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c084a0a;
P_0c084a0a: /* original c73b, guest PC 0x0c084a0a */
if(!s->budget--) { s->failed_pc=0x0c084a0au; return 0; }
r[0]=code_base|0x00084af8u;
goto P_0c084a0c;
P_0c084a0c: /* original f508, guest PC 0x0c084a0c */
if(!s->budget--) { s->failed_pc=0x0c084a0cu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c084a0e;
P_0c084a0e: /* original 4318, guest PC 0x0c084a0e */
if(!s->budget--) { s->failed_pc=0x0c084a0eu; return 0; }
r[3]<<=8;
goto P_0c084a10;
P_0c084a10: /* original f43c, guest PC 0x0c084a10 */
if(!s->budget--) { s->failed_pc=0x0c084a10u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c084a12;
P_0c084a12: /* original 2359, guest PC 0x0c084a12 */
if(!s->budget--) { s->failed_pc=0x0c084a12u; return 0; }
r[3]&=r[5];
goto P_0c084a14;
P_0c084a14: /* original f453, guest PC 0x0c084a14 */
if(!s->budget--) { s->failed_pc=0x0c084a14u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'/');
goto P_0c084a16;
P_0c084a16: /* original 2f32, guest PC 0x0c084a16 */
if(!s->budget--) { s->failed_pc=0x0c084a16u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c084a18;
P_0c084a18: /* original 435a, guest PC 0x0c084a18 */
if(!s->budget--) { s->failed_pc=0x0c084a18u; return 0; }
r[53]=r[3];
goto P_0c084a1a;
P_0c084a1a: /* original f32d, guest PC 0x0c084a1a */
if(!s->budget--) { s->failed_pc=0x0c084a1au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c084a1c;
P_0c084a1c: /* original ff40, guest PC 0x0c084a1c */
if(!s->budget--) { s->failed_pc=0x0c084a1cu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'+');
goto P_0c084a1e;
P_0c084a1e: /* original f43c, guest PC 0x0c084a1e */
if(!s->budget--) { s->failed_pc=0x0c084a1eu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c084a20;
P_0c084a20: /* original f453, guest PC 0x0c084a20 */
if(!s->budget--) { s->failed_pc=0x0c084a20u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'/');
goto P_0c084a22;
P_0c084a22: /* original 6343, guest PC 0x0c084a22 */
if(!s->budget--) { s->failed_pc=0x0c084a22u; return 0; }
r[3]=r[4];
goto P_0c084a24;
P_0c084a24: /* original 4418, guest PC 0x0c084a24 */
if(!s->budget--) { s->failed_pc=0x0c084a24u; return 0; }
r[4]<<=8;
goto P_0c084a26;
P_0c084a26: /* original d033, guest PC 0x0c084a26 */
if(!s->budget--) { s->failed_pc=0x0c084a26u; return 0; }
r[0]=read(ram,0x0c084af4u,4);
goto P_0c084a28;
P_0c084a28: /* original 4408, guest PC 0x0c084a28 */
if(!s->budget--) { s->failed_pc=0x0c084a28u; return 0; }
r[4]<<=2;
goto P_0c084a2a;
P_0c084a2a: /* original 2459, guest PC 0x0c084a2a */
if(!s->budget--) { s->failed_pc=0x0c084a2au; return 0; }
r[4]&=r[5];
goto P_0c084a2c;
P_0c084a2c: /* original 445a, guest PC 0x0c084a2c */
if(!s->budget--) { s->failed_pc=0x0c084a2cu; return 0; }
r[53]=r[4];
goto P_0c084a2e;
P_0c084a2e: /* original e2f7, guest PC 0x0c084a2e */
if(!s->budget--) { s->failed_pc=0x0c084a2eu; return 0; }
r[2]=0xfffffff7u;
goto P_0c084a30;
P_0c084a30: /* original 432c, guest PC 0x0c084a30 */
if(!s->budget--) { s->failed_pc=0x0c084a30u; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c084a32;
P_0c084a32: /* original 2379, guest PC 0x0c084a32 */
if(!s->budget--) { s->failed_pc=0x0c084a32u; return 0; }
r[3]&=r[7];
goto P_0c084a34;
P_0c084a34: /* original f32d, guest PC 0x0c084a34 */
if(!s->budget--) { s->failed_pc=0x0c084a34u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c084a36;
P_0c084a36: /* original 4301, guest PC 0x0c084a36 */
if(!s->budget--) { s->failed_pc=0x0c084a36u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]>>=1;
goto P_0c084a38;
P_0c084a38: /* original 4300, guest PC 0x0c084a38 */
if(!s->budget--) { s->failed_pc=0x0c084a38u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c084a3a;
P_0c084a3a: /* original 073d, guest PC 0x0c084a3a */
if(!s->budget--) { s->failed_pc=0x0c084a3au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c084a3c;
P_0c084a3c: /* original e028, guest PC 0x0c084a3c */
if(!s->budget--) { s->failed_pc=0x0c084a3cu; return 0; }
r[0]=0x00000028u;
goto P_0c084a3e;
P_0c084a3e: /* original fd40, guest PC 0x0c084a3e */
if(!s->budget--) { s->failed_pc=0x0c084a3eu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'+');
goto P_0c084a40;
P_0c084a40: /* original f43c, guest PC 0x0c084a40 */
if(!s->budget--) { s->failed_pc=0x0c084a40u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c084a42;
P_0c084a42: /* original f453, guest PC 0x0c084a42 */
if(!s->budget--) { s->failed_pc=0x0c084a42u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'/');
goto P_0c084a44;
P_0c084a44: /* original 0e65, guest PC 0x0c084a44 */
if(!s->budget--) { s->failed_pc=0x0c084a44u; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c084a46;
P_0c084a46: /* original e02a, guest PC 0x0c084a46 */
if(!s->budget--) { s->failed_pc=0x0c084a46u; return 0; }
r[0]=0x0000002au;
goto P_0c084a48;
P_0c084a48: /* original 0e75, guest PC 0x0c084a48 */
if(!s->budget--) { s->failed_pc=0x0c084a48u; return 0; }
write(ram,r[14]+r[0],r[7],2);
goto P_0c084a4a;
P_0c084a4a: /* original e014, guest PC 0x0c084a4a */
if(!s->budget--) { s->failed_pc=0x0c084a4au; return 0; }
r[0]=0x00000014u;
goto P_0c084a4c;
P_0c084a4c: /* original fe67, guest PC 0x0c084a4c */
if(!s->budget--) { s->failed_pc=0x0c084a4cu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c084a4e;
P_0c084a4e: /* original e014, guest PC 0x0c084a4e */
if(!s->budget--) { s->failed_pc=0x0c084a4eu; return 0; }
r[0]=0x00000014u;
goto P_0c084a50;
P_0c084a50: /* original f3f6, guest PC 0x0c084a50 */
if(!s->budget--) { s->failed_pc=0x0c084a50u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c084a52;
P_0c084a52: /* original e00c, guest PC 0x0c084a52 */
if(!s->budget--) { s->failed_pc=0x0c084a52u; return 0; }
r[0]=0x0000000cu;
goto P_0c084a54;
P_0c084a54: /* original fe37, guest PC 0x0c084a54 */
if(!s->budget--) { s->failed_pc=0x0c084a54u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c084a56;
P_0c084a56: /* original e010, guest PC 0x0c084a56 */
if(!s->budget--) { s->failed_pc=0x0c084a56u; return 0; }
r[0]=0x00000010u;
goto P_0c084a58;
P_0c084a58: /* original f3f6, guest PC 0x0c084a58 */
if(!s->budget--) { s->failed_pc=0x0c084a58u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c084a5a;
P_0c084a5a: /* original e018, guest PC 0x0c084a5a */
if(!s->budget--) { s->failed_pc=0x0c084a5au; return 0; }
r[0]=0x00000018u;
goto P_0c084a5c;
P_0c084a5c: /* original fe37, guest PC 0x0c084a5c */
if(!s->budget--) { s->failed_pc=0x0c084a5cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c084a5e;
P_0c084a5e: /* original fe40, guest PC 0x0c084a5e */
if(!s->budget--) { s->failed_pc=0x0c084a5eu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'+');
goto P_0c084a60;
P_0c084a60: /* original e00c, guest PC 0x0c084a60 */
if(!s->budget--) { s->failed_pc=0x0c084a60u; return 0; }
r[0]=0x0000000cu;
goto P_0c084a62;
P_0c084a62: /* original f3f6, guest PC 0x0c084a62 */
if(!s->budget--) { s->failed_pc=0x0c084a62u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c084a64;
P_0c084a64: /* original e01c, guest PC 0x0c084a64 */
if(!s->budget--) { s->failed_pc=0x0c084a64u; return 0; }
r[0]=0x0000001cu;
goto P_0c084a66;
P_0c084a66: /* original fe37, guest PC 0x0c084a66 */
if(!s->budget--) { s->failed_pc=0x0c084a66u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c084a68;
P_0c084a68: /* original e008, guest PC 0x0c084a68 */
if(!s->budget--) { s->failed_pc=0x0c084a68u; return 0; }
r[0]=0x00000008u;
goto P_0c084a6a;
P_0c084a6a: /* original f3f6, guest PC 0x0c084a6a */
if(!s->budget--) { s->failed_pc=0x0c084a6au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c084a6c;
P_0c084a6c: /* original e020, guest PC 0x0c084a6c */
if(!s->budget--) { s->failed_pc=0x0c084a6cu; return 0; }
r[0]=0x00000020u;
goto P_0c084a6e;
P_0c084a6e: /* original fe37, guest PC 0x0c084a6e */
if(!s->budget--) { s->failed_pc=0x0c084a6eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c084a70;
P_0c084a70: /* original e004, guest PC 0x0c084a70 */
if(!s->budget--) { s->failed_pc=0x0c084a70u; return 0; }
r[0]=0x00000004u;
goto P_0c084a72;
P_0c084a72: /* original f3f6, guest PC 0x0c084a72 */
if(!s->budget--) { s->failed_pc=0x0c084a72u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c084a74;
P_0c084a74: /* original e010, guest PC 0x0c084a74 */
if(!s->budget--) { s->failed_pc=0x0c084a74u; return 0; }
r[0]=0x00000010u;
goto P_0c084a76;
P_0c084a76: /* original fe37, guest PC 0x0c084a76 */
if(!s->budget--) { s->failed_pc=0x0c084a76u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c084a78;
P_0c084a78: /* original e004, guest PC 0x0c084a78 */
if(!s->budget--) { s->failed_pc=0x0c084a78u; return 0; }
r[0]=0x00000004u;
goto P_0c084a7a;
P_0c084a7a: /* original fefa, guest PC 0x0c084a7a */
if(!s->budget--) { s->failed_pc=0x0c084a7au; return 0; }
vf3_matrix_store(s,ram,15,r[14]);
goto P_0c084a7c;
P_0c084a7c: /* original fed7, guest PC 0x0c084a7c */
if(!s->budget--) { s->failed_pc=0x0c084a7cu; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c084a7e;
P_0c084a7e: /* original e008, guest PC 0x0c084a7e */
if(!s->budget--) { s->failed_pc=0x0c084a7eu; return 0; }
r[0]=0x00000008u;
goto P_0c084a80;
P_0c084a80: /* original fee7, guest PC 0x0c084a80 */
if(!s->budget--) { s->failed_pc=0x0c084a80u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c084a82;
P_0c084a82: /* original 2cd1, guest PC 0x0c084a82 */
if(!s->budget--) { s->failed_pc=0x0c084a82u; return 0; }
write(ram,r[12],r[13],2);
goto P_0c084a84;
P_0c084a84: /* original 7f18, guest PC 0x0c084a84 */
if(!s->budget--) { s->failed_pc=0x0c084a84u; return 0; }
r[15]+=0x00000018u;
goto P_0c084a86;
P_0c084a86: /* original 4f26, guest PC 0x0c084a86 */
if(!s->budget--) { s->failed_pc=0x0c084a86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c084a88;
P_0c084a88: /* original fdf9, guest PC 0x0c084a88 */
if(!s->budget--) { s->failed_pc=0x0c084a88u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084a8a;
P_0c084a8a: /* original fef9, guest PC 0x0c084a8a */
if(!s->budget--) { s->failed_pc=0x0c084a8au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084a8c;
P_0c084a8c: /* original fff9, guest PC 0x0c084a8c */
if(!s->budget--) { s->failed_pc=0x0c084a8cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084a8e;
P_0c084a8e: /* original 6cf6, guest PC 0x0c084a8e */
if(!s->budget--) { s->failed_pc=0x0c084a8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c084a90;
P_0c084a90: /* original 6df6, guest PC 0x0c084a90 */
if(!s->budget--) { s->failed_pc=0x0c084a90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c084a92;
P_0c084a92: /* original 000b, guest PC 0x0c084a92 */
if(!s->budget--) { s->failed_pc=0x0c084a92u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c084a94: /* original 6ef6, guest PC 0x0c084a94 */
if(!s->budget--) { s->failed_pc=0x0c084a94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c084a96u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
