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
int vf3_away_batch120_adapter_24(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09690au: goto P_0c09690a;
case 0x0c09690cu: goto P_0c09690c;
case 0x0c09690eu: goto P_0c09690e;
case 0x0c096910u: goto P_0c096910;
case 0x0c096912u: goto P_0c096912;
case 0x0c096944u: goto P_0c096944;
case 0x0c096946u: goto P_0c096946;
case 0x0c096948u: goto P_0c096948;
case 0x0c09694au: goto P_0c09694a;
case 0x0c09694cu: goto P_0c09694c;
case 0x0c09694eu: goto P_0c09694e;
case 0x0c096950u: goto P_0c096950;
case 0x0c096952u: goto P_0c096952;
case 0x0c096954u: goto P_0c096954;
case 0x0c096956u: goto P_0c096956;
case 0x0c096958u: goto P_0c096958;
case 0x0c09695au: goto P_0c09695a;
case 0x0c09695cu: goto P_0c09695c;
case 0x0c09695eu: goto P_0c09695e;
case 0x0c096960u: goto P_0c096960;
case 0x0c096962u: goto P_0c096962;
case 0x0c096964u: goto P_0c096964;
case 0x0c096966u: goto P_0c096966;
case 0x0c096968u: goto P_0c096968;
case 0x0c09696au: goto P_0c09696a;
case 0x0c09696cu: goto P_0c09696c;
case 0x0c09696eu: goto P_0c09696e;
case 0x0c096970u: goto P_0c096970;
case 0x0c096972u: goto P_0c096972;
case 0x0c096974u: goto P_0c096974;
case 0x0c096976u: goto P_0c096976;
case 0x0c096978u: goto P_0c096978;
case 0x0c09697au: goto P_0c09697a;
case 0x0c09697cu: goto P_0c09697c;
case 0x0c09697eu: goto P_0c09697e;
case 0x0c096980u: goto P_0c096980;
case 0x0c096982u: goto P_0c096982;
case 0x0c096984u: goto P_0c096984;
case 0x0c096986u: goto P_0c096986;
case 0x0c096988u: goto P_0c096988;
case 0x0c09698au: goto P_0c09698a;
case 0x0c09698cu: goto P_0c09698c;
case 0x0c09698eu: goto P_0c09698e;
case 0x0c096990u: goto P_0c096990;
case 0x0c096992u: goto P_0c096992;
case 0x0c096994u: goto P_0c096994;
case 0x0c096996u: goto P_0c096996;
case 0x0c096998u: goto P_0c096998;
case 0x0c09699au: goto P_0c09699a;
case 0x0c09699cu: goto P_0c09699c;
case 0x0c09699eu: goto P_0c09699e;
case 0x0c0969a0u: goto P_0c0969a0;
case 0x0c0969a2u: goto P_0c0969a2;
case 0x0c0969a4u: goto P_0c0969a4;
case 0x0c0969a6u: goto P_0c0969a6;
case 0x0c0969a8u: goto P_0c0969a8;
case 0x0c0969aau: goto P_0c0969aa;
case 0x0c0969acu: goto P_0c0969ac;
case 0x0c0969aeu: goto P_0c0969ae;
case 0x0c0969b0u: goto P_0c0969b0;
case 0x0c0969b2u: goto P_0c0969b2;
case 0x0c0969b4u: goto P_0c0969b4;
case 0x0c0969b6u: goto P_0c0969b6;
case 0x0c0969b8u: goto P_0c0969b8;
case 0x0c0969bau: goto P_0c0969ba;
case 0x0c0969bcu: goto P_0c0969bc;
case 0x0c0969beu: goto P_0c0969be;
case 0x0c0969c0u: goto P_0c0969c0;
case 0x0c0969c2u: goto P_0c0969c2;
case 0x0c0969c4u: goto P_0c0969c4;
case 0x0c0969c6u: goto P_0c0969c6;
case 0x0c0969c8u: goto P_0c0969c8;
case 0x0c0969cau: goto P_0c0969ca;
case 0x0c0969ccu: goto P_0c0969cc;
case 0x0c0969ceu: goto P_0c0969ce;
case 0x0c0969d0u: goto P_0c0969d0;
case 0x0c0969d2u: goto P_0c0969d2;
case 0x0c0969d4u: goto P_0c0969d4;
case 0x0c0969d6u: goto P_0c0969d6;
case 0x0c0969d8u: goto P_0c0969d8;
case 0x0c0969dau: goto P_0c0969da;
case 0x0c0969dcu: goto P_0c0969dc;
case 0x0c0969deu: goto P_0c0969de;
case 0x0c0969e0u: goto P_0c0969e0;
case 0x0c0969e2u: goto P_0c0969e2;
case 0x0c0969e4u: goto P_0c0969e4;
case 0x0c0969e6u: goto P_0c0969e6;
case 0x0c0969e8u: goto P_0c0969e8;
case 0x0c0969eau: goto P_0c0969ea;
case 0x0c0969ecu: goto P_0c0969ec;
case 0x0c0969eeu: goto P_0c0969ee;
case 0x0c0969f0u: goto P_0c0969f0;
case 0x0c0969f2u: goto P_0c0969f2;
case 0x0c0969f4u: goto P_0c0969f4;
case 0x0c0969f6u: goto P_0c0969f6;
case 0x0c0969f8u: goto P_0c0969f8;
case 0x0c0969fau: goto P_0c0969fa;
case 0x0c0969fcu: goto P_0c0969fc;
case 0x0c0969feu: goto P_0c0969fe;
case 0x0c096a00u: goto P_0c096a00;
case 0x0c096a02u: goto P_0c096a02;
case 0x0c096a04u: goto P_0c096a04;
case 0x0c096a06u: goto P_0c096a06;
case 0x0c096a08u: goto P_0c096a08;
case 0x0c096a0au: goto P_0c096a0a;
case 0x0c096a0cu: goto P_0c096a0c;
case 0x0c096a0eu: goto P_0c096a0e;
case 0x0c096a10u: goto P_0c096a10;
case 0x0c096a12u: goto P_0c096a12;
case 0x0c096a14u: goto P_0c096a14;
case 0x0c096a16u: goto P_0c096a16;
case 0x0c096a18u: goto P_0c096a18;
case 0x0c096a1au: goto P_0c096a1a;
case 0x0c096a1cu: goto P_0c096a1c;
case 0x0c096a1eu: goto P_0c096a1e;
case 0x0c096a20u: goto P_0c096a20;
case 0x0c096a22u: goto P_0c096a22;
case 0x0c09a39cu: goto P_0c09a39c;
case 0x0c09a39eu: goto P_0c09a39e;
case 0x0c09a3a0u: goto P_0c09a3a0;
case 0x0c09a3a2u: goto P_0c09a3a2;
case 0x0c09a3a4u: goto P_0c09a3a4;
case 0x0c09a3a6u: goto P_0c09a3a6;
case 0x0c09a3a8u: goto P_0c09a3a8;
case 0x0c09a3aau: goto P_0c09a3aa;
case 0x0c09a3acu: goto P_0c09a3ac;
case 0x0c09a3aeu: goto P_0c09a3ae;
case 0x0c09a3b0u: goto P_0c09a3b0;
case 0x0c09a3b2u: goto P_0c09a3b2;
case 0x0c09a3b4u: goto P_0c09a3b4;
case 0x0c09a3b6u: goto P_0c09a3b6;
case 0x0c09a3b8u: goto P_0c09a3b8;
case 0x0c09a3bau: goto P_0c09a3ba;
case 0x0c09a3bcu: goto P_0c09a3bc;
case 0x0c09a3beu: goto P_0c09a3be;
case 0x0c09a3c0u: goto P_0c09a3c0;
case 0x0c09a3c2u: goto P_0c09a3c2;
case 0x0c09a3c4u: goto P_0c09a3c4;
case 0x0c09a3c6u: goto P_0c09a3c6;
case 0x0c09a3c8u: goto P_0c09a3c8;
case 0x0c09a3cau: goto P_0c09a3ca;
case 0x0c09a3ccu: goto P_0c09a3cc;
case 0x0c09a3ceu: goto P_0c09a3ce;
case 0x0c09a3d0u: goto P_0c09a3d0;
case 0x0c09a3d2u: goto P_0c09a3d2;
case 0x0c09a3d4u: goto P_0c09a3d4;
case 0x0c09a3d6u: goto P_0c09a3d6;
case 0x0c09a3d8u: goto P_0c09a3d8;
case 0x0c09a3dau: goto P_0c09a3da;
case 0x0c09a3dcu: goto P_0c09a3dc;
case 0x0c09a3deu: goto P_0c09a3de;
case 0x0c09a3e0u: goto P_0c09a3e0;
case 0x0c09a3e2u: goto P_0c09a3e2;
case 0x0c09a3e4u: goto P_0c09a3e4;
case 0x0c09a3e6u: goto P_0c09a3e6;
case 0x0c09a3e8u: goto P_0c09a3e8;
case 0x0c09a3eau: goto P_0c09a3ea;
case 0x0c09a3ecu: goto P_0c09a3ec;
case 0x0c09a3eeu: goto P_0c09a3ee;
case 0x0c09a3f0u: goto P_0c09a3f0;
case 0x0c09a3f2u: goto P_0c09a3f2;
case 0x0c09a3f4u: goto P_0c09a3f4;
case 0x0c09a3f6u: goto P_0c09a3f6;
case 0x0c09a3f8u: goto P_0c09a3f8;
case 0x0c09a3fau: goto P_0c09a3fa;
case 0x0c09a3fcu: goto P_0c09a3fc;
case 0x0c09a3feu: goto P_0c09a3fe;
case 0x0c09a400u: goto P_0c09a400;
case 0x0c09a402u: goto P_0c09a402;
case 0x0c09a404u: goto P_0c09a404;
case 0x0c09a406u: goto P_0c09a406;
case 0x0c09a408u: goto P_0c09a408;
case 0x0c09a40au: goto P_0c09a40a;
case 0x0c09a40cu: goto P_0c09a40c;
case 0x0c09a40eu: goto P_0c09a40e;
case 0x0c09a410u: goto P_0c09a410;
case 0x0c09a412u: goto P_0c09a412;
case 0x0c09a414u: goto P_0c09a414;
case 0x0c09a416u: goto P_0c09a416;
case 0x0c09a418u: goto P_0c09a418;
case 0x0c09a41au: goto P_0c09a41a;
case 0x0c09a41cu: goto P_0c09a41c;
case 0x0c09a41eu: goto P_0c09a41e;
case 0x0c09a420u: goto P_0c09a420;
case 0x0c09a422u: goto P_0c09a422;
case 0x0c09a424u: goto P_0c09a424;
case 0x0c09a426u: goto P_0c09a426;
case 0x0c09a428u: goto P_0c09a428;
case 0x0c09a42au: goto P_0c09a42a;
case 0x0c09a42cu: goto P_0c09a42c;
case 0x0c09a42eu: goto P_0c09a42e;
case 0x0c09a430u: goto P_0c09a430;
case 0x0c09a432u: goto P_0c09a432;
case 0x0c09a434u: goto P_0c09a434;
case 0x0c09a436u: goto P_0c09a436;
case 0x0c09a438u: goto P_0c09a438;
case 0x0c09a43au: goto P_0c09a43a;
case 0x0c09a43cu: goto P_0c09a43c;
case 0x0c09a43eu: goto P_0c09a43e;
case 0x0c09a440u: goto P_0c09a440;
case 0x0c09a442u: goto P_0c09a442;
case 0x0c09a444u: goto P_0c09a444;
case 0x0c09a446u: goto P_0c09a446;
case 0x0c09a448u: goto P_0c09a448;
case 0x0c09a44au: goto P_0c09a44a;
case 0x0c09a44cu: goto P_0c09a44c;
case 0x0c09a44eu: goto P_0c09a44e;
case 0x0c09a450u: goto P_0c09a450;
case 0x0c09a452u: goto P_0c09a452;
case 0x0c09a454u: goto P_0c09a454;
case 0x0c09a456u: goto P_0c09a456;
case 0x0c09a458u: goto P_0c09a458;
case 0x0c09a45au: goto P_0c09a45a;
case 0x0c09a45cu: goto P_0c09a45c;
case 0x0c09a45eu: goto P_0c09a45e;
case 0x0c09a460u: goto P_0c09a460;
case 0x0c09a462u: goto P_0c09a462;
case 0x0c09a464u: goto P_0c09a464;
case 0x0c09a466u: goto P_0c09a466;
case 0x0c09a468u: goto P_0c09a468;
case 0x0c09a46au: goto P_0c09a46a;
case 0x0c09a46cu: goto P_0c09a46c;
case 0x0c09a46eu: goto P_0c09a46e;
case 0x0c09a470u: goto P_0c09a470;
case 0x0c09a472u: goto P_0c09a472;
case 0x0c09a474u: goto P_0c09a474;
case 0x0c09a476u: goto P_0c09a476;
case 0x0c09a478u: goto P_0c09a478;
case 0x0c09a47au: goto P_0c09a47a;
case 0x0c09a47cu: goto P_0c09a47c;
case 0x0c09a47eu: goto P_0c09a47e;
case 0x0c09a480u: goto P_0c09a480;
case 0x0c09a482u: goto P_0c09a482;
case 0x0c09a484u: goto P_0c09a484;
case 0x0c09a486u: goto P_0c09a486;
case 0x0c09a488u: goto P_0c09a488;
case 0x0c09a48au: goto P_0c09a48a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09690a: /* original 6042, guest PC 0x0c09690a */
if(!s->budget--) { s->failed_pc=0x0c09690au; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c09690c;
P_0c09690c: /* original cb01, guest PC 0x0c09690c */
if(!s->budget--) { s->failed_pc=0x0c09690cu; return 0; }
r[0]|=1u;
goto P_0c09690e;
P_0c09690e: /* original 2402, guest PC 0x0c09690e */
if(!s->budget--) { s->failed_pc=0x0c09690eu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c096910;
P_0c096910: /* original 000b, guest PC 0x0c096910 */
if(!s->budget--) { s->failed_pc=0x0c096910u; return 0; }
target=r[16];
write(ram,r[4]+12,r[5],4);
s->pc=target; return ram->oob==0;
P_0c096912: /* original 1453, guest PC 0x0c096912 */
if(!s->budget--) { s->failed_pc=0x0c096912u; return 0; }
write(ram,r[4]+12,r[5],4);
if(!vf3_matrix_family(0x0c096914u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096914u; return 0; } return 1;
P_0c096944: /* original 2fe6, guest PC 0x0c096944 */
if(!s->budget--) { s->failed_pc=0x0c096944u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096946;
P_0c096946: /* original e600, guest PC 0x0c096946 */
if(!s->budget--) { s->failed_pc=0x0c096946u; return 0; }
r[6]=0x00000000u;
goto P_0c096948;
P_0c096948: /* original 2fd6, guest PC 0x0c096948 */
if(!s->budget--) { s->failed_pc=0x0c096948u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09694a;
P_0c09694a: /* original 6563, guest PC 0x0c09694a */
if(!s->budget--) { s->failed_pc=0x0c09694au; return 0; }
r[5]=r[6];
goto P_0c09694c;
P_0c09694c: /* original 2fc6, guest PC 0x0c09694c */
if(!s->budget--) { s->failed_pc=0x0c09694cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09694e;
P_0c09694e: /* original 2fb6, guest PC 0x0c09694e */
if(!s->budget--) { s->failed_pc=0x0c09694eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096950;
P_0c096950: /* original 2fa6, guest PC 0x0c096950 */
if(!s->budget--) { s->failed_pc=0x0c096950u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096952;
P_0c096952: /* original 2f96, guest PC 0x0c096952 */
if(!s->budget--) { s->failed_pc=0x0c096952u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096954;
P_0c096954: /* original 2f86, guest PC 0x0c096954 */
if(!s->budget--) { s->failed_pc=0x0c096954u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096956;
P_0c096956: /* original fffb, guest PC 0x0c096956 */
if(!s->budget--) { s->failed_pc=0x0c096956u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c096958;
P_0c096958: /* original 4f22, guest PC 0x0c096958 */
if(!s->budget--) { s->failed_pc=0x0c096958u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09695a;
P_0c09695a: /* original d336, guest PC 0x0c09695a */
if(!s->budget--) { s->failed_pc=0x0c09695au; return 0; }
r[3]=read(ram,0x0c096a34u,4);
goto P_0c09695c;
P_0c09695c: /* original de34, guest PC 0x0c09695c */
if(!s->budget--) { s->failed_pc=0x0c09695cu; return 0; }
r[14]=read(ram,0x0c096a30u,4);
goto P_0c09695e;
P_0c09695e: /* original 430b, guest PC 0x0c09695e */
if(!s->budget--) { s->failed_pc=0x0c09695eu; return 0; }
target=r[3];
r[16]=code_base|0x0c096962u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096962u) { target=s->pc; goto dispatch; }
goto P_0c096962;
P_0c096960: /* original 6463, guest PC 0x0c096960 */
if(!s->budget--) { s->failed_pc=0x0c096960u; return 0; }
r[4]=r[6];
goto P_0c096962;
P_0c096962: /* original e600, guest PC 0x0c096962 */
if(!s->budget--) { s->failed_pc=0x0c096962u; return 0; }
r[6]=0x00000000u;
goto P_0c096964;
P_0c096964: /* original d234, guest PC 0x0c096964 */
if(!s->budget--) { s->failed_pc=0x0c096964u; return 0; }
r[2]=read(ram,0x0c096a38u,4);
goto P_0c096966;
P_0c096966: /* original ff8d, guest PC 0x0c096966 */
if(!s->budget--) { s->failed_pc=0x0c096966u; return 0; }
fr[15]=0;
goto P_0c096968;
P_0c096968: /* original 6563, guest PC 0x0c096968 */
if(!s->budget--) { s->failed_pc=0x0c096968u; return 0; }
r[5]=r[6];
goto P_0c09696a;
P_0c09696a: /* original f5fc, guest PC 0x0c09696a */
if(!s->budget--) { s->failed_pc=0x0c09696au; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09696c;
P_0c09696c: /* original f4fc, guest PC 0x0c09696c */
if(!s->budget--) { s->failed_pc=0x0c09696cu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09696e;
P_0c09696e: /* original 420b, guest PC 0x0c09696e */
if(!s->budget--) { s->failed_pc=0x0c09696eu; return 0; }
target=r[2];
r[16]=code_base|0x0c096972u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096972u) { target=s->pc; goto dispatch; }
goto P_0c096972;
P_0c096970: /* original 6463, guest PC 0x0c096970 */
if(!s->budget--) { s->failed_pc=0x0c096970u; return 0; }
r[4]=r[6];
goto P_0c096972;
P_0c096972: /* original d332, guest PC 0x0c096972 */
if(!s->budget--) { s->failed_pc=0x0c096972u; return 0; }
r[3]=read(ram,0x0c096a3cu,4);
goto P_0c096974;
P_0c096974: /* original 430b, guest PC 0x0c096974 */
if(!s->budget--) { s->failed_pc=0x0c096974u; return 0; }
target=r[3];
r[16]=code_base|0x0c096978u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096978u) { target=s->pc; goto dispatch; }
goto P_0c096978;
P_0c096976: /* original 0009, guest PC 0x0c096976 */
if(!s->budget--) { s->failed_pc=0x0c096976u; return 0; }
goto P_0c096978;
P_0c096978: /* original d22e, guest PC 0x0c096978 */
if(!s->budget--) { s->failed_pc=0x0c096978u; return 0; }
r[2]=read(ram,0x0c096a34u,4);
goto P_0c09697a;
P_0c09697a: /* original e600, guest PC 0x0c09697a */
if(!s->budget--) { s->failed_pc=0x0c09697au; return 0; }
r[6]=0x00000000u;
goto P_0c09697c;
P_0c09697c: /* original 6563, guest PC 0x0c09697c */
if(!s->budget--) { s->failed_pc=0x0c09697cu; return 0; }
r[5]=r[6];
goto P_0c09697e;
P_0c09697e: /* original 420b, guest PC 0x0c09697e */
if(!s->budget--) { s->failed_pc=0x0c09697eu; return 0; }
target=r[2];
r[16]=code_base|0x0c096982u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096982u) { target=s->pc; goto dispatch; }
goto P_0c096982;
P_0c096980: /* original 6463, guest PC 0x0c096980 */
if(!s->budget--) { s->failed_pc=0x0c096980u; return 0; }
r[4]=r[6];
goto P_0c096982;
P_0c096982: /* original e600, guest PC 0x0c096982 */
if(!s->budget--) { s->failed_pc=0x0c096982u; return 0; }
r[6]=0x00000000u;
goto P_0c096984;
P_0c096984: /* original d32c, guest PC 0x0c096984 */
if(!s->budget--) { s->failed_pc=0x0c096984u; return 0; }
r[3]=read(ram,0x0c096a38u,4);
goto P_0c096986;
P_0c096986: /* original f5fc, guest PC 0x0c096986 */
if(!s->budget--) { s->failed_pc=0x0c096986u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c096988;
P_0c096988: /* original 6563, guest PC 0x0c096988 */
if(!s->budget--) { s->failed_pc=0x0c096988u; return 0; }
r[5]=r[6];
goto P_0c09698a;
P_0c09698a: /* original f4fc, guest PC 0x0c09698a */
if(!s->budget--) { s->failed_pc=0x0c09698au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09698c;
P_0c09698c: /* original 430b, guest PC 0x0c09698c */
if(!s->budget--) { s->failed_pc=0x0c09698cu; return 0; }
target=r[3];
r[16]=code_base|0x0c096990u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096990u) { target=s->pc; goto dispatch; }
goto P_0c096990;
P_0c09698e: /* original 6463, guest PC 0x0c09698e */
if(!s->budget--) { s->failed_pc=0x0c09698eu; return 0; }
r[4]=r[6];
goto P_0c096990;
P_0c096990: /* original d22a, guest PC 0x0c096990 */
if(!s->budget--) { s->failed_pc=0x0c096990u; return 0; }
r[2]=read(ram,0x0c096a3cu,4);
goto P_0c096992;
P_0c096992: /* original 420b, guest PC 0x0c096992 */
if(!s->budget--) { s->failed_pc=0x0c096992u; return 0; }
target=r[2];
r[16]=code_base|0x0c096996u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096996u) { target=s->pc; goto dispatch; }
goto P_0c096996;
P_0c096994: /* original 0009, guest PC 0x0c096994 */
if(!s->budget--) { s->failed_pc=0x0c096994u; return 0; }
goto P_0c096996;
P_0c096996: /* original d32a, guest PC 0x0c096996 */
if(!s->budget--) { s->failed_pc=0x0c096996u; return 0; }
r[3]=read(ram,0x0c096a40u,4);
goto P_0c096998;
P_0c096998: /* original 430b, guest PC 0x0c096998 */
if(!s->budget--) { s->failed_pc=0x0c096998u; return 0; }
target=r[3];
r[16]=code_base|0x0c09699cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09699cu) { target=s->pc; goto dispatch; }
goto P_0c09699c;
P_0c09699a: /* original 0009, guest PC 0x0c09699a */
if(!s->budget--) { s->failed_pc=0x0c09699au; return 0; }
goto P_0c09699c;
P_0c09699c: /* original 9442, guest PC 0x0c09699c */
if(!s->budget--) { s->failed_pc=0x0c09699cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a24u,2);
goto P_0c09699e;
P_0c09699e: /* original e802, guest PC 0x0c09699e */
if(!s->budget--) { s->failed_pc=0x0c09699eu; return 0; }
r[8]=0x00000002u;
goto P_0c0969a0;
P_0c0969a0: /* original 9a41, guest PC 0x0c0969a0 */
if(!s->budget--) { s->failed_pc=0x0c0969a0u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a26u,2);
goto P_0c0969a2;
P_0c0969a2: /* original ec00, guest PC 0x0c0969a2 */
if(!s->budget--) { s->failed_pc=0x0c0969a2u; return 0; }
r[12]=0x00000000u;
goto P_0c0969a4;
P_0c0969a4: /* original dd27, guest PC 0x0c0969a4 */
if(!s->budget--) { s->failed_pc=0x0c0969a4u; return 0; }
r[13]=read(ram,0x0c096a44u,4);
goto P_0c0969a6;
P_0c0969a6: /* original 34ec, guest PC 0x0c0969a6 */
if(!s->budget--) { s->failed_pc=0x0c0969a6u; return 0; }
r[4]+=r[14];
goto P_0c0969a8;
P_0c0969a8: /* original 3aec, guest PC 0x0c0969a8 */
if(!s->budget--) { s->failed_pc=0x0c0969a8u; return 0; }
r[10]+=r[14];
goto P_0c0969aa;
P_0c0969aa: /* original 6b43, guest PC 0x0c0969aa */
if(!s->budget--) { s->failed_pc=0x0c0969aau; return 0; }
r[11]=r[4];
goto P_0c0969ac;
P_0c0969ac: /* original 6943, guest PC 0x0c0969ac */
if(!s->budget--) { s->failed_pc=0x0c0969acu; return 0; }
r[9]=r[4];
goto P_0c0969ae;
P_0c0969ae: /* original 933a, guest PC 0x0c0969ae */
if(!s->budget--) { s->failed_pc=0x0c0969aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a26u,2);
goto P_0c0969b0;
P_0c0969b0: /* original 62c3, guest PC 0x0c0969b0 */
if(!s->budget--) { s->failed_pc=0x0c0969b0u; return 0; }
r[2]=r[12];
goto P_0c0969b2;
P_0c0969b2: /* original 4208, guest PC 0x0c0969b2 */
if(!s->budget--) { s->failed_pc=0x0c0969b2u; return 0; }
r[2]<<=2;
goto P_0c0969b4;
P_0c0969b4: /* original 33ec, guest PC 0x0c0969b4 */
if(!s->budget--) { s->failed_pc=0x0c0969b4u; return 0; }
r[3]+=r[14];
goto P_0c0969b6;
P_0c0969b6: /* original 323c, guest PC 0x0c0969b6 */
if(!s->budget--) { s->failed_pc=0x0c0969b6u; return 0; }
r[2]+=r[3];
goto P_0c0969b8;
P_0c0969b8: /* original 6122, guest PC 0x0c0969b8 */
if(!s->budget--) { s->failed_pc=0x0c0969b8u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0969ba;
P_0c0969ba: /* original 2118, guest PC 0x0c0969ba */
if(!s->budget--) { s->failed_pc=0x0c0969bau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0969bc;
P_0c0969bc: /* original 8901, guest PC 0x0c0969bc */
if(!s->budget--) { s->failed_pc=0x0c0969bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0969c2; }
goto P_0c0969be;
P_0c0969be: /* original 4d0b, guest PC 0x0c0969be */
if(!s->budget--) { s->failed_pc=0x0c0969beu; return 0; }
target=r[13];
r[16]=code_base|0x0c0969c2u;
tmp=read(ram,r[10],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0969c2u) { target=s->pc; goto dispatch; }
goto P_0c0969c2;
P_0c0969c0: /* original 64a2, guest PC 0x0c0969c0 */
if(!s->budget--) { s->failed_pc=0x0c0969c0u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0969c2;
P_0c0969c2: /* original 6392, guest PC 0x0c0969c2 */
if(!s->budget--) { s->failed_pc=0x0c0969c2u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c0969c4;
P_0c0969c4: /* original 2338, guest PC 0x0c0969c4 */
if(!s->budget--) { s->failed_pc=0x0c0969c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0969c6;
P_0c0969c6: /* original 8901, guest PC 0x0c0969c6 */
if(!s->budget--) { s->failed_pc=0x0c0969c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0969cc; }
goto P_0c0969c8;
P_0c0969c8: /* original 4d0b, guest PC 0x0c0969c8 */
if(!s->budget--) { s->failed_pc=0x0c0969c8u; return 0; }
target=r[13];
r[16]=code_base|0x0c0969ccu;
tmp=read(ram,r[11],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0969ccu) { target=s->pc; goto dispatch; }
goto P_0c0969cc;
P_0c0969ca: /* original 64b2, guest PC 0x0c0969ca */
if(!s->budget--) { s->failed_pc=0x0c0969cau; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c0969cc;
P_0c0969cc: /* original 7c01, guest PC 0x0c0969cc */
if(!s->budget--) { s->failed_pc=0x0c0969ccu; return 0; }
r[12]+=0x00000001u;
goto P_0c0969ce;
P_0c0969ce: /* original 3c83, guest PC 0x0c0969ce */
if(!s->budget--) { s->failed_pc=0x0c0969ceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[8])!=0);
goto P_0c0969d0;
P_0c0969d0: /* original 7904, guest PC 0x0c0969d0 */
if(!s->budget--) { s->failed_pc=0x0c0969d0u; return 0; }
r[9]+=0x00000004u;
goto P_0c0969d2;
P_0c0969d2: /* original 7b04, guest PC 0x0c0969d2 */
if(!s->budget--) { s->failed_pc=0x0c0969d2u; return 0; }
r[11]+=0x00000004u;
goto P_0c0969d4;
P_0c0969d4: /* original 8feb, guest PC 0x0c0969d4 */
if(!s->budget--) { s->failed_pc=0x0c0969d4u; return 0; }
cond=r[17]&1u;
r[10]+=0x00000004u;
if(!cond) { goto P_0c0969ae; }
goto P_0c0969d8;
P_0c0969d6: /* original 7a04, guest PC 0x0c0969d6 */
if(!s->budget--) { s->failed_pc=0x0c0969d6u; return 0; }
r[10]+=0x00000004u;
goto P_0c0969d8;
P_0c0969d8: /* original 9026, guest PC 0x0c0969d8 */
if(!s->budget--) { s->failed_pc=0x0c0969d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a28u,2);
goto P_0c0969da;
P_0c0969da: /* original 02ee, guest PC 0x0c0969da */
if(!s->budget--) { s->failed_pc=0x0c0969dau; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0969dc;
P_0c0969dc: /* original 2228, guest PC 0x0c0969dc */
if(!s->budget--) { s->failed_pc=0x0c0969dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0969de;
P_0c0969de: /* original 8901, guest PC 0x0c0969de */
if(!s->budget--) { s->failed_pc=0x0c0969deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0969e4; }
goto P_0c0969e0;
P_0c0969e0: /* original 4d0b, guest PC 0x0c0969e0 */
if(!s->budget--) { s->failed_pc=0x0c0969e0u; return 0; }
target=r[13];
r[16]=code_base|0x0c0969e4u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0969e4u) { target=s->pc; goto dispatch; }
goto P_0c0969e4;
P_0c0969e2: /* original 04ee, guest PC 0x0c0969e2 */
if(!s->budget--) { s->failed_pc=0x0c0969e2u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0969e4;
P_0c0969e4: /* original 9021, guest PC 0x0c0969e4 */
if(!s->budget--) { s->failed_pc=0x0c0969e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a2au,2);
goto P_0c0969e6;
P_0c0969e6: /* original 03ee, guest PC 0x0c0969e6 */
if(!s->budget--) { s->failed_pc=0x0c0969e6u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0969e8;
P_0c0969e8: /* original 2338, guest PC 0x0c0969e8 */
if(!s->budget--) { s->failed_pc=0x0c0969e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0969ea;
P_0c0969ea: /* original 8901, guest PC 0x0c0969ea */
if(!s->budget--) { s->failed_pc=0x0c0969eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0969f0; }
goto P_0c0969ec;
P_0c0969ec: /* original 4d0b, guest PC 0x0c0969ec */
if(!s->budget--) { s->failed_pc=0x0c0969ecu; return 0; }
target=r[13];
r[16]=code_base|0x0c0969f0u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0969f0u) { target=s->pc; goto dispatch; }
goto P_0c0969f0;
P_0c0969ee: /* original 04ee, guest PC 0x0c0969ee */
if(!s->budget--) { s->failed_pc=0x0c0969eeu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0969f0;
P_0c0969f0: /* original 901c, guest PC 0x0c0969f0 */
if(!s->budget--) { s->failed_pc=0x0c0969f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a2cu,2);
goto P_0c0969f2;
P_0c0969f2: /* original 03ee, guest PC 0x0c0969f2 */
if(!s->budget--) { s->failed_pc=0x0c0969f2u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0969f4;
P_0c0969f4: /* original 2338, guest PC 0x0c0969f4 */
if(!s->budget--) { s->failed_pc=0x0c0969f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0969f6;
P_0c0969f6: /* original 8901, guest PC 0x0c0969f6 */
if(!s->budget--) { s->failed_pc=0x0c0969f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0969fc; }
goto P_0c0969f8;
P_0c0969f8: /* original 4d0b, guest PC 0x0c0969f8 */
if(!s->budget--) { s->failed_pc=0x0c0969f8u; return 0; }
target=r[13];
r[16]=code_base|0x0c0969fcu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0969fcu) { target=s->pc; goto dispatch; }
goto P_0c0969fc;
P_0c0969fa: /* original 04ee, guest PC 0x0c0969fa */
if(!s->budget--) { s->failed_pc=0x0c0969fau; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0969fc;
P_0c0969fc: /* original 9017, guest PC 0x0c0969fc */
if(!s->budget--) { s->failed_pc=0x0c0969fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a2eu,2);
goto P_0c0969fe;
P_0c0969fe: /* original 03ee, guest PC 0x0c0969fe */
if(!s->budget--) { s->failed_pc=0x0c0969feu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c096a00;
P_0c096a00: /* original 2338, guest PC 0x0c096a00 */
if(!s->budget--) { s->failed_pc=0x0c096a00u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c096a02;
P_0c096a02: /* original 8901, guest PC 0x0c096a02 */
if(!s->budget--) { s->failed_pc=0x0c096a02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096a08; }
goto P_0c096a04;
P_0c096a04: /* original 4d0b, guest PC 0x0c096a04 */
if(!s->budget--) { s->failed_pc=0x0c096a04u; return 0; }
target=r[13];
r[16]=code_base|0x0c096a08u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096a08u) { target=s->pc; goto dispatch; }
goto P_0c096a08;
P_0c096a06: /* original 04ee, guest PC 0x0c096a06 */
if(!s->budget--) { s->failed_pc=0x0c096a06u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c096a08;
P_0c096a08: /* original d30f, guest PC 0x0c096a08 */
if(!s->budget--) { s->failed_pc=0x0c096a08u; return 0; }
r[3]=read(ram,0x0c096a48u,4);
goto P_0c096a0a;
P_0c096a0a: /* original 430b, guest PC 0x0c096a0a */
if(!s->budget--) { s->failed_pc=0x0c096a0au; return 0; }
target=r[3];
r[16]=code_base|0x0c096a0eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096a0eu) { target=s->pc; goto dispatch; }
goto P_0c096a0e;
P_0c096a0c: /* original 0009, guest PC 0x0c096a0c */
if(!s->budget--) { s->failed_pc=0x0c096a0cu; return 0; }
goto P_0c096a0e;
P_0c096a0e: /* original 4f26, guest PC 0x0c096a0e */
if(!s->budget--) { s->failed_pc=0x0c096a0eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096a10;
P_0c096a10: /* original d20e, guest PC 0x0c096a10 */
if(!s->budget--) { s->failed_pc=0x0c096a10u; return 0; }
r[2]=read(ram,0x0c096a4cu,4);
goto P_0c096a12;
P_0c096a12: /* original fff9, guest PC 0x0c096a12 */
if(!s->budget--) { s->failed_pc=0x0c096a12u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c096a14;
P_0c096a14: /* original 68f6, guest PC 0x0c096a14 */
if(!s->budget--) { s->failed_pc=0x0c096a14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c096a16;
P_0c096a16: /* original 69f6, guest PC 0x0c096a16 */
if(!s->budget--) { s->failed_pc=0x0c096a16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c096a18;
P_0c096a18: /* original 6af6, guest PC 0x0c096a18 */
if(!s->budget--) { s->failed_pc=0x0c096a18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c096a1a;
P_0c096a1a: /* original 6bf6, guest PC 0x0c096a1a */
if(!s->budget--) { s->failed_pc=0x0c096a1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c096a1c;
P_0c096a1c: /* original 6cf6, guest PC 0x0c096a1c */
if(!s->budget--) { s->failed_pc=0x0c096a1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c096a1e;
P_0c096a1e: /* original 6df6, guest PC 0x0c096a1e */
if(!s->budget--) { s->failed_pc=0x0c096a1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096a20;
P_0c096a20: /* original 422b, guest PC 0x0c096a20 */
if(!s->budget--) { s->failed_pc=0x0c096a20u; return 0; }
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
P_0c096a22: /* original 6ef6, guest PC 0x0c096a22 */
if(!s->budget--) { s->failed_pc=0x0c096a22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c096a24u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096a24u; return 0; } return 1;
P_0c09a39c: /* original 2fe6, guest PC 0x0c09a39c */
if(!s->budget--) { s->failed_pc=0x0c09a39cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09a39e;
P_0c09a39e: /* original e600, guest PC 0x0c09a39e */
if(!s->budget--) { s->failed_pc=0x0c09a39eu; return 0; }
r[6]=0x00000000u;
goto P_0c09a3a0;
P_0c09a3a0: /* original 2fd6, guest PC 0x0c09a3a0 */
if(!s->budget--) { s->failed_pc=0x0c09a3a0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09a3a2;
P_0c09a3a2: /* original 6563, guest PC 0x0c09a3a2 */
if(!s->budget--) { s->failed_pc=0x0c09a3a2u; return 0; }
r[5]=r[6];
goto P_0c09a3a4;
P_0c09a3a4: /* original 2fc6, guest PC 0x0c09a3a4 */
if(!s->budget--) { s->failed_pc=0x0c09a3a4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09a3a6;
P_0c09a3a6: /* original 2fb6, guest PC 0x0c09a3a6 */
if(!s->budget--) { s->failed_pc=0x0c09a3a6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09a3a8;
P_0c09a3a8: /* original fffb, guest PC 0x0c09a3a8 */
if(!s->budget--) { s->failed_pc=0x0c09a3a8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09a3aa;
P_0c09a3aa: /* original 4f22, guest PC 0x0c09a3aa */
if(!s->budget--) { s->failed_pc=0x0c09a3aau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09a3ac;
P_0c09a3ac: /* original d33d, guest PC 0x0c09a3ac */
if(!s->budget--) { s->failed_pc=0x0c09a3acu; return 0; }
r[3]=read(ram,0x0c09a4a4u,4);
goto P_0c09a3ae;
P_0c09a3ae: /* original db3c, guest PC 0x0c09a3ae */
if(!s->budget--) { s->failed_pc=0x0c09a3aeu; return 0; }
r[11]=read(ram,0x0c09a4a0u,4);
goto P_0c09a3b0;
P_0c09a3b0: /* original de39, guest PC 0x0c09a3b0 */
if(!s->budget--) { s->failed_pc=0x0c09a3b0u; return 0; }
r[14]=read(ram,0x0c09a498u,4);
goto P_0c09a3b2;
P_0c09a3b2: /* original dd3a, guest PC 0x0c09a3b2 */
if(!s->budget--) { s->failed_pc=0x0c09a3b2u; return 0; }
r[13]=read(ram,0x0c09a49cu,4);
goto P_0c09a3b4;
P_0c09a3b4: /* original 430b, guest PC 0x0c09a3b4 */
if(!s->budget--) { s->failed_pc=0x0c09a3b4u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a3b8u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a3b8u) { target=s->pc; goto dispatch; }
goto P_0c09a3b8;
P_0c09a3b6: /* original 6463, guest PC 0x0c09a3b6 */
if(!s->budget--) { s->failed_pc=0x0c09a3b6u; return 0; }
r[4]=r[6];
goto P_0c09a3b8;
P_0c09a3b8: /* original e600, guest PC 0x0c09a3b8 */
if(!s->budget--) { s->failed_pc=0x0c09a3b8u; return 0; }
r[6]=0x00000000u;
goto P_0c09a3ba;
P_0c09a3ba: /* original d23b, guest PC 0x0c09a3ba */
if(!s->budget--) { s->failed_pc=0x0c09a3bau; return 0; }
r[2]=read(ram,0x0c09a4a8u,4);
goto P_0c09a3bc;
P_0c09a3bc: /* original ff8d, guest PC 0x0c09a3bc */
if(!s->budget--) { s->failed_pc=0x0c09a3bcu; return 0; }
fr[15]=0;
goto P_0c09a3be;
P_0c09a3be: /* original 6563, guest PC 0x0c09a3be */
if(!s->budget--) { s->failed_pc=0x0c09a3beu; return 0; }
r[5]=r[6];
goto P_0c09a3c0;
P_0c09a3c0: /* original f5fc, guest PC 0x0c09a3c0 */
if(!s->budget--) { s->failed_pc=0x0c09a3c0u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09a3c2;
P_0c09a3c2: /* original f4fc, guest PC 0x0c09a3c2 */
if(!s->budget--) { s->failed_pc=0x0c09a3c2u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09a3c4;
P_0c09a3c4: /* original 420b, guest PC 0x0c09a3c4 */
if(!s->budget--) { s->failed_pc=0x0c09a3c4u; return 0; }
target=r[2];
r[16]=code_base|0x0c09a3c8u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a3c8u) { target=s->pc; goto dispatch; }
goto P_0c09a3c8;
P_0c09a3c6: /* original 6463, guest PC 0x0c09a3c6 */
if(!s->budget--) { s->failed_pc=0x0c09a3c6u; return 0; }
r[4]=r[6];
goto P_0c09a3c8;
P_0c09a3c8: /* original d338, guest PC 0x0c09a3c8 */
if(!s->budget--) { s->failed_pc=0x0c09a3c8u; return 0; }
r[3]=read(ram,0x0c09a4acu,4);
goto P_0c09a3ca;
P_0c09a3ca: /* original 430b, guest PC 0x0c09a3ca */
if(!s->budget--) { s->failed_pc=0x0c09a3cau; return 0; }
target=r[3];
r[16]=code_base|0x0c09a3ceu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a3ceu) { target=s->pc; goto dispatch; }
goto P_0c09a3ce;
P_0c09a3cc: /* original 0009, guest PC 0x0c09a3cc */
if(!s->budget--) { s->failed_pc=0x0c09a3ccu; return 0; }
goto P_0c09a3ce;
P_0c09a3ce: /* original d238, guest PC 0x0c09a3ce */
if(!s->budget--) { s->failed_pc=0x0c09a3ceu; return 0; }
r[2]=read(ram,0x0c09a4b0u,4);
goto P_0c09a3d0;
P_0c09a3d0: /* original 420b, guest PC 0x0c09a3d0 */
if(!s->budget--) { s->failed_pc=0x0c09a3d0u; return 0; }
target=r[2];
r[16]=code_base|0x0c09a3d4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a3d4u) { target=s->pc; goto dispatch; }
goto P_0c09a3d4;
P_0c09a3d2: /* original 0009, guest PC 0x0c09a3d2 */
if(!s->budget--) { s->failed_pc=0x0c09a3d2u; return 0; }
goto P_0c09a3d4;
P_0c09a3d4: /* original 905a, guest PC 0x0c09a3d4 */
if(!s->budget--) { s->failed_pc=0x0c09a3d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a48cu,2);
goto P_0c09a3d6;
P_0c09a3d6: /* original e301, guest PC 0x0c09a3d6 */
if(!s->budget--) { s->failed_pc=0x0c09a3d6u; return 0; }
r[3]=0x00000001u;
goto P_0c09a3d8;
P_0c09a3d8: /* original ec00, guest PC 0x0c09a3d8 */
if(!s->budget--) { s->failed_pc=0x0c09a3d8u; return 0; }
r[12]=0x00000000u;
goto P_0c09a3da;
P_0c09a3da: /* original 0d36, guest PC 0x0c09a3da */
if(!s->budget--) { s->failed_pc=0x0c09a3dau; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c09a3dc;
P_0c09a3dc: /* original c735, guest PC 0x0c09a3dc */
if(!s->budget--) { s->failed_pc=0x0c09a3dcu; return 0; }
r[0]=code_base|0x0009a4b4u;
goto P_0c09a3de;
P_0c09a3de: /* original f308, guest PC 0x0c09a3de */
if(!s->budget--) { s->failed_pc=0x0c09a3deu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09a3e0;
P_0c09a3e0: /* original fe3a, guest PC 0x0c09a3e0 */
if(!s->budget--) { s->failed_pc=0x0c09a3e0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c09a3e2;
P_0c09a3e2: /* original 9054, guest PC 0x0c09a3e2 */
if(!s->budget--) { s->failed_pc=0x0c09a3e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a48eu,2);
goto P_0c09a3e4;
P_0c09a3e4: /* original 0dc4, guest PC 0x0c09a3e4 */
if(!s->budget--) { s->failed_pc=0x0c09a3e4u; return 0; }
write(ram,r[13]+r[0],r[12],1);
goto P_0c09a3e6;
P_0c09a3e6: /* original 52e2, guest PC 0x0c09a3e6 */
if(!s->budget--) { s->failed_pc=0x0c09a3e6u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c09a3e8;
P_0c09a3e8: /* original 9352, guest PC 0x0c09a3e8 */
if(!s->budget--) { s->failed_pc=0x0c09a3e8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a490u,2);
goto P_0c09a3ea;
P_0c09a3ea: /* original 2239, guest PC 0x0c09a3ea */
if(!s->budget--) { s->failed_pc=0x0c09a3eau; return 0; }
r[2]&=r[3];
goto P_0c09a3ec;
P_0c09a3ec: /* original 1e22, guest PC 0x0c09a3ec */
if(!s->budget--) { s->failed_pc=0x0c09a3ecu; return 0; }
write(ram,r[14]+8,r[2],4);
goto P_0c09a3ee;
P_0c09a3ee: /* original d133, guest PC 0x0c09a3ee */
if(!s->budget--) { s->failed_pc=0x0c09a3eeu; return 0; }
r[1]=read(ram,0x0c09a4bcu,4);
goto P_0c09a3f0;
P_0c09a3f0: /* original de31, guest PC 0x0c09a3f0 */
if(!s->budget--) { s->failed_pc=0x0c09a3f0u; return 0; }
r[14]=read(ram,0x0c09a4b8u,4);
goto P_0c09a3f2;
P_0c09a3f2: /* original 410b, guest PC 0x0c09a3f2 */
if(!s->budget--) { s->failed_pc=0x0c09a3f2u; return 0; }
target=r[1];
r[16]=code_base|0x0c09a3f6u;
r[4]=read(ram,r[14]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a3f6u) { target=s->pc; goto dispatch; }
goto P_0c09a3f6;
P_0c09a3f4: /* original 54e6, guest PC 0x0c09a3f4 */
if(!s->budget--) { s->failed_pc=0x0c09a3f4u; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c09a3f6;
P_0c09a3f6: /* original d331, guest PC 0x0c09a3f6 */
if(!s->budget--) { s->failed_pc=0x0c09a3f6u; return 0; }
r[3]=read(ram,0x0c09a4bcu,4);
goto P_0c09a3f8;
P_0c09a3f8: /* original 430b, guest PC 0x0c09a3f8 */
if(!s->budget--) { s->failed_pc=0x0c09a3f8u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a3fcu;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a3fcu) { target=s->pc; goto dispatch; }
goto P_0c09a3fc;
P_0c09a3fa: /* original 54e4, guest PC 0x0c09a3fa */
if(!s->budget--) { s->failed_pc=0x0c09a3fau; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c09a3fc;
P_0c09a3fc: /* original d22f, guest PC 0x0c09a3fc */
if(!s->budget--) { s->failed_pc=0x0c09a3fcu; return 0; }
r[2]=read(ram,0x0c09a4bcu,4);
goto P_0c09a3fe;
P_0c09a3fe: /* original 420b, guest PC 0x0c09a3fe */
if(!s->budget--) { s->failed_pc=0x0c09a3feu; return 0; }
target=r[2];
r[16]=code_base|0x0c09a402u;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a402u) { target=s->pc; goto dispatch; }
goto P_0c09a402;
P_0c09a400: /* original 54e5, guest PC 0x0c09a400 */
if(!s->budget--) { s->failed_pc=0x0c09a400u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c09a402;
P_0c09a402: /* original d32e, guest PC 0x0c09a402 */
if(!s->budget--) { s->failed_pc=0x0c09a402u; return 0; }
r[3]=read(ram,0x0c09a4bcu,4);
goto P_0c09a404;
P_0c09a404: /* original 430b, guest PC 0x0c09a404 */
if(!s->budget--) { s->failed_pc=0x0c09a404u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a408u;
r[4]=read(ram,r[14]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a408u) { target=s->pc; goto dispatch; }
goto P_0c09a408;
P_0c09a406: /* original 54ef, guest PC 0x0c09a406 */
if(!s->budget--) { s->failed_pc=0x0c09a406u; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c09a408;
P_0c09a408: /* original d32c, guest PC 0x0c09a408 */
if(!s->budget--) { s->failed_pc=0x0c09a408u; return 0; }
r[3]=read(ram,0x0c09a4bcu,4);
goto P_0c09a40a;
P_0c09a40a: /* original e040, guest PC 0x0c09a40a */
if(!s->budget--) { s->failed_pc=0x0c09a40au; return 0; }
r[0]=0x00000040u;
goto P_0c09a40c;
P_0c09a40c: /* original 430b, guest PC 0x0c09a40c */
if(!s->budget--) { s->failed_pc=0x0c09a40cu; return 0; }
target=r[3];
r[16]=code_base|0x0c09a410u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a410u) { target=s->pc; goto dispatch; }
goto P_0c09a410;
P_0c09a40e: /* original 04ee, guest PC 0x0c09a40e */
if(!s->budget--) { s->failed_pc=0x0c09a40eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09a410;
P_0c09a410: /* original d22a, guest PC 0x0c09a410 */
if(!s->budget--) { s->failed_pc=0x0c09a410u; return 0; }
r[2]=read(ram,0x0c09a4bcu,4);
goto P_0c09a412;
P_0c09a412: /* original 420b, guest PC 0x0c09a412 */
if(!s->budget--) { s->failed_pc=0x0c09a412u; return 0; }
target=r[2];
r[16]=code_base|0x0c09a416u;
r[4]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a416u) { target=s->pc; goto dispatch; }
goto P_0c09a416;
P_0c09a414: /* original 54e7, guest PC 0x0c09a414 */
if(!s->budget--) { s->failed_pc=0x0c09a414u; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c09a416;
P_0c09a416: /* original d329, guest PC 0x0c09a416 */
if(!s->budget--) { s->failed_pc=0x0c09a416u; return 0; }
r[3]=read(ram,0x0c09a4bcu,4);
goto P_0c09a418;
P_0c09a418: /* original 430b, guest PC 0x0c09a418 */
if(!s->budget--) { s->failed_pc=0x0c09a418u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a41cu;
r[4]=read(ram,r[14]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a41cu) { target=s->pc; goto dispatch; }
goto P_0c09a41c;
P_0c09a41a: /* original 54ed, guest PC 0x0c09a41a */
if(!s->budget--) { s->failed_pc=0x0c09a41au; return 0; }
r[4]=read(ram,r[14]+52,4);
goto P_0c09a41c;
P_0c09a41c: /* original d227, guest PC 0x0c09a41c */
if(!s->budget--) { s->failed_pc=0x0c09a41cu; return 0; }
r[2]=read(ram,0x0c09a4bcu,4);
goto P_0c09a41e;
P_0c09a41e: /* original 420b, guest PC 0x0c09a41e */
if(!s->budget--) { s->failed_pc=0x0c09a41eu; return 0; }
target=r[2];
r[16]=code_base|0x0c09a422u;
r[4]=read(ram,r[14]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a422u) { target=s->pc; goto dispatch; }
goto P_0c09a422;
P_0c09a420: /* original 54ee, guest PC 0x0c09a420 */
if(!s->budget--) { s->failed_pc=0x0c09a420u; return 0; }
r[4]=read(ram,r[14]+56,4);
goto P_0c09a422;
P_0c09a422: /* original 9036, guest PC 0x0c09a422 */
if(!s->budget--) { s->failed_pc=0x0c09a422u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a492u,2);
goto P_0c09a424;
P_0c09a424: /* original 63c3, guest PC 0x0c09a424 */
if(!s->budget--) { s->failed_pc=0x0c09a424u; return 0; }
r[3]=r[12];
goto P_0c09a426;
P_0c09a426: /* original 0bc6, guest PC 0x0c09a426 */
if(!s->budget--) { s->failed_pc=0x0c09a426u; return 0; }
write(ram,r[11]+r[0],r[12],4);
goto P_0c09a428;
P_0c09a428: /* original 70fc, guest PC 0x0c09a428 */
if(!s->budget--) { s->failed_pc=0x0c09a428u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09a42a;
P_0c09a42a: /* original 0b36, guest PC 0x0c09a42a */
if(!s->budget--) { s->failed_pc=0x0c09a42au; return 0; }
write(ram,r[11]+r[0],r[3],4);
goto P_0c09a42c;
P_0c09a42c: /* original 9032, guest PC 0x0c09a42c */
if(!s->budget--) { s->failed_pc=0x0c09a42cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a494u,2);
goto P_0c09a42e;
P_0c09a42e: /* original 54e8, guest PC 0x0c09a42e */
if(!s->budget--) { s->failed_pc=0x0c09a42eu; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c09a430;
P_0c09a430: /* original 0434, guest PC 0x0c09a430 */
if(!s->budget--) { s->failed_pc=0x0c09a430u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c09a432;
P_0c09a432: /* original 7001, guest PC 0x0c09a432 */
if(!s->budget--) { s->failed_pc=0x0c09a432u; return 0; }
r[0]+=0x00000001u;
goto P_0c09a434;
P_0c09a434: /* original 0434, guest PC 0x0c09a434 */
if(!s->budget--) { s->failed_pc=0x0c09a434u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c09a436;
P_0c09a436: /* original 7001, guest PC 0x0c09a436 */
if(!s->budget--) { s->failed_pc=0x0c09a436u; return 0; }
r[0]+=0x00000001u;
goto P_0c09a438;
P_0c09a438: /* original 0434, guest PC 0x0c09a438 */
if(!s->budget--) { s->failed_pc=0x0c09a438u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c09a43a;
P_0c09a43a: /* original e010, guest PC 0x0c09a43a */
if(!s->budget--) { s->failed_pc=0x0c09a43au; return 0; }
r[0]=0x00000010u;
goto P_0c09a43c;
P_0c09a43c: /* original e329, guest PC 0x0c09a43c */
if(!s->budget--) { s->failed_pc=0x0c09a43cu; return 0; }
r[3]=0x00000029u;
goto P_0c09a43e;
P_0c09a43e: /* original 0d34, guest PC 0x0c09a43e */
if(!s->budget--) { s->failed_pc=0x0c09a43eu; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c09a440;
P_0c09a440: /* original 9029, guest PC 0x0c09a440 */
if(!s->budget--) { s->failed_pc=0x0c09a440u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a496u,2);
goto P_0c09a442;
P_0c09a442: /* original d31f, guest PC 0x0c09a442 */
if(!s->budget--) { s->failed_pc=0x0c09a442u; return 0; }
r[3]=read(ram,0x0c09a4c0u,4);
goto P_0c09a444;
P_0c09a444: /* original 54ec, guest PC 0x0c09a444 */
if(!s->budget--) { s->failed_pc=0x0c09a444u; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c09a446;
P_0c09a446: /* original 0436, guest PC 0x0c09a446 */
if(!s->budget--) { s->failed_pc=0x0c09a446u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c09a448;
P_0c09a448: /* original d31e, guest PC 0x0c09a448 */
if(!s->budget--) { s->failed_pc=0x0c09a448u; return 0; }
r[3]=read(ram,0x0c09a4c4u,4);
goto P_0c09a44a;
P_0c09a44a: /* original 430b, guest PC 0x0c09a44a */
if(!s->budget--) { s->failed_pc=0x0c09a44au; return 0; }
target=r[3];
r[16]=code_base|0x0c09a44eu;
r[4]=0x0000001eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a44eu) { target=s->pc; goto dispatch; }
goto P_0c09a44e;
P_0c09a44c: /* original e41e, guest PC 0x0c09a44c */
if(!s->budget--) { s->failed_pc=0x0c09a44cu; return 0; }
r[4]=0x0000001eu;
goto P_0c09a44e;
P_0c09a44e: /* original d21e, guest PC 0x0c09a44e */
if(!s->budget--) { s->failed_pc=0x0c09a44eu; return 0; }
r[2]=read(ram,0x0c09a4c8u,4);
goto P_0c09a450;
P_0c09a450: /* original 420b, guest PC 0x0c09a450 */
if(!s->budget--) { s->failed_pc=0x0c09a450u; return 0; }
target=r[2];
r[16]=code_base|0x0c09a454u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a454u) { target=s->pc; goto dispatch; }
goto P_0c09a454;
P_0c09a452: /* original 0009, guest PC 0x0c09a452 */
if(!s->budget--) { s->failed_pc=0x0c09a452u; return 0; }
goto P_0c09a454;
P_0c09a454: /* original d31d, guest PC 0x0c09a454 */
if(!s->budget--) { s->failed_pc=0x0c09a454u; return 0; }
r[3]=read(ram,0x0c09a4ccu,4);
goto P_0c09a456;
P_0c09a456: /* original 430b, guest PC 0x0c09a456 */
if(!s->budget--) { s->failed_pc=0x0c09a456u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a45au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a45au) { target=s->pc; goto dispatch; }
goto P_0c09a45a;
P_0c09a458: /* original 0009, guest PC 0x0c09a458 */
if(!s->budget--) { s->failed_pc=0x0c09a458u; return 0; }
goto P_0c09a45a;
P_0c09a45a: /* original d21d, guest PC 0x0c09a45a */
if(!s->budget--) { s->failed_pc=0x0c09a45au; return 0; }
r[2]=read(ram,0x0c09a4d0u,4);
goto P_0c09a45c;
P_0c09a45c: /* original 420b, guest PC 0x0c09a45c */
if(!s->budget--) { s->failed_pc=0x0c09a45cu; return 0; }
target=r[2];
r[16]=code_base|0x0c09a460u;
r[4]=0x0000001eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a460u) { target=s->pc; goto dispatch; }
goto P_0c09a460;
P_0c09a45e: /* original e41e, guest PC 0x0c09a45e */
if(!s->budget--) { s->failed_pc=0x0c09a45eu; return 0; }
r[4]=0x0000001eu;
goto P_0c09a460;
P_0c09a460: /* original d310, guest PC 0x0c09a460 */
if(!s->budget--) { s->failed_pc=0x0c09a460u; return 0; }
r[3]=read(ram,0x0c09a4a4u,4);
goto P_0c09a462;
P_0c09a462: /* original 65c3, guest PC 0x0c09a462 */
if(!s->budget--) { s->failed_pc=0x0c09a462u; return 0; }
r[5]=r[12];
goto P_0c09a464;
P_0c09a464: /* original 66c3, guest PC 0x0c09a464 */
if(!s->budget--) { s->failed_pc=0x0c09a464u; return 0; }
r[6]=r[12];
goto P_0c09a466;
P_0c09a466: /* original 430b, guest PC 0x0c09a466 */
if(!s->budget--) { s->failed_pc=0x0c09a466u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a46au;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a46au) { target=s->pc; goto dispatch; }
goto P_0c09a46a;
P_0c09a468: /* original 64c3, guest PC 0x0c09a468 */
if(!s->budget--) { s->failed_pc=0x0c09a468u; return 0; }
r[4]=r[12];
goto P_0c09a46a;
P_0c09a46a: /* original d20f, guest PC 0x0c09a46a */
if(!s->budget--) { s->failed_pc=0x0c09a46au; return 0; }
r[2]=read(ram,0x0c09a4a8u,4);
goto P_0c09a46c;
P_0c09a46c: /* original 65c3, guest PC 0x0c09a46c */
if(!s->budget--) { s->failed_pc=0x0c09a46cu; return 0; }
r[5]=r[12];
goto P_0c09a46e;
P_0c09a46e: /* original 66c3, guest PC 0x0c09a46e */
if(!s->budget--) { s->failed_pc=0x0c09a46eu; return 0; }
r[6]=r[12];
goto P_0c09a470;
P_0c09a470: /* original f5fc, guest PC 0x0c09a470 */
if(!s->budget--) { s->failed_pc=0x0c09a470u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09a472;
P_0c09a472: /* original f4fc, guest PC 0x0c09a472 */
if(!s->budget--) { s->failed_pc=0x0c09a472u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09a474;
P_0c09a474: /* original 420b, guest PC 0x0c09a474 */
if(!s->budget--) { s->failed_pc=0x0c09a474u; return 0; }
target=r[2];
r[16]=code_base|0x0c09a478u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a478u) { target=s->pc; goto dispatch; }
goto P_0c09a478;
P_0c09a476: /* original 64c3, guest PC 0x0c09a476 */
if(!s->budget--) { s->failed_pc=0x0c09a476u; return 0; }
r[4]=r[12];
goto P_0c09a478;
P_0c09a478: /* original 4f26, guest PC 0x0c09a478 */
if(!s->budget--) { s->failed_pc=0x0c09a478u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09a47a;
P_0c09a47a: /* original 84da, guest PC 0x0c09a47a */
if(!s->budget--) { s->failed_pc=0x0c09a47au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+10,1);
goto P_0c09a47c;
P_0c09a47c: /* original 7001, guest PC 0x0c09a47c */
if(!s->budget--) { s->failed_pc=0x0c09a47cu; return 0; }
r[0]+=0x00000001u;
goto P_0c09a47e;
P_0c09a47e: /* original 80da, guest PC 0x0c09a47e */
if(!s->budget--) { s->failed_pc=0x0c09a47eu; return 0; }
write(ram,r[13]+10,r[0],1);
goto P_0c09a480;
P_0c09a480: /* original fff9, guest PC 0x0c09a480 */
if(!s->budget--) { s->failed_pc=0x0c09a480u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09a482;
P_0c09a482: /* original 6bf6, guest PC 0x0c09a482 */
if(!s->budget--) { s->failed_pc=0x0c09a482u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09a484;
P_0c09a484: /* original 6cf6, guest PC 0x0c09a484 */
if(!s->budget--) { s->failed_pc=0x0c09a484u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09a486;
P_0c09a486: /* original 6df6, guest PC 0x0c09a486 */
if(!s->budget--) { s->failed_pc=0x0c09a486u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09a488;
P_0c09a488: /* original 000b, guest PC 0x0c09a488 */
if(!s->budget--) { s->failed_pc=0x0c09a488u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09a48a: /* original 6ef6, guest PC 0x0c09a48a */
if(!s->budget--) { s->failed_pc=0x0c09a48au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09a48cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09a48cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
