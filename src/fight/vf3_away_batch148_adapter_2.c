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
int vf3_away_batch148_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c055860u: goto P_0c055860;
case 0x0c055862u: goto P_0c055862;
case 0x0c055864u: goto P_0c055864;
case 0x0c055866u: goto P_0c055866;
case 0x0c055868u: goto P_0c055868;
case 0x0c05586au: goto P_0c05586a;
case 0x0c05586cu: goto P_0c05586c;
case 0x0c05586eu: goto P_0c05586e;
case 0x0c055870u: goto P_0c055870;
case 0x0c055872u: goto P_0c055872;
case 0x0c055874u: goto P_0c055874;
case 0x0c055876u: goto P_0c055876;
case 0x0c055878u: goto P_0c055878;
case 0x0c0558a0u: goto P_0c0558a0;
case 0x0c0558a2u: goto P_0c0558a2;
case 0x0c0558a4u: goto P_0c0558a4;
case 0x0c0558a6u: goto P_0c0558a6;
case 0x0c0558a8u: goto P_0c0558a8;
case 0x0c0558aau: goto P_0c0558aa;
case 0x0c0558acu: goto P_0c0558ac;
case 0x0c0558aeu: goto P_0c0558ae;
case 0x0c0558b0u: goto P_0c0558b0;
case 0x0c0558b2u: goto P_0c0558b2;
case 0x0c0558b4u: goto P_0c0558b4;
case 0x0c0558b6u: goto P_0c0558b6;
case 0x0c0558b8u: goto P_0c0558b8;
case 0x0c0558bau: goto P_0c0558ba;
case 0x0c0558bcu: goto P_0c0558bc;
case 0x0c0558beu: goto P_0c0558be;
case 0x0c0558c0u: goto P_0c0558c0;
case 0x0c0558c2u: goto P_0c0558c2;
case 0x0c0558c4u: goto P_0c0558c4;
case 0x0c0558c6u: goto P_0c0558c6;
case 0x0c0558c8u: goto P_0c0558c8;
case 0x0c0558cau: goto P_0c0558ca;
case 0x0c0558ccu: goto P_0c0558cc;
case 0x0c0558ceu: goto P_0c0558ce;
case 0x0c0558d0u: goto P_0c0558d0;
case 0x0c0558d2u: goto P_0c0558d2;
case 0x0c0558d4u: goto P_0c0558d4;
case 0x0c0558d6u: goto P_0c0558d6;
case 0x0c0558d8u: goto P_0c0558d8;
case 0x0c0558dau: goto P_0c0558da;
case 0x0c0558dcu: goto P_0c0558dc;
case 0x0c0558deu: goto P_0c0558de;
case 0x0c0558e0u: goto P_0c0558e0;
case 0x0c0558e2u: goto P_0c0558e2;
case 0x0c0558e4u: goto P_0c0558e4;
case 0x0c0558e6u: goto P_0c0558e6;
case 0x0c0558e8u: goto P_0c0558e8;
case 0x0c0558eau: goto P_0c0558ea;
case 0x0c0558ecu: goto P_0c0558ec;
case 0x0c0558eeu: goto P_0c0558ee;
case 0x0c0558f0u: goto P_0c0558f0;
case 0x0c0558f2u: goto P_0c0558f2;
case 0x0c0558f4u: goto P_0c0558f4;
case 0x0c0558f6u: goto P_0c0558f6;
case 0x0c0558f8u: goto P_0c0558f8;
case 0x0c0558fau: goto P_0c0558fa;
case 0x0c0558fcu: goto P_0c0558fc;
case 0x0c0558feu: goto P_0c0558fe;
case 0x0c055900u: goto P_0c055900;
case 0x0c055902u: goto P_0c055902;
case 0x0c055904u: goto P_0c055904;
case 0x0c055906u: goto P_0c055906;
case 0x0c055908u: goto P_0c055908;
case 0x0c05590au: goto P_0c05590a;
case 0x0c05590cu: goto P_0c05590c;
case 0x0c05590eu: goto P_0c05590e;
case 0x0c055910u: goto P_0c055910;
case 0x0c055912u: goto P_0c055912;
case 0x0c055914u: goto P_0c055914;
case 0x0c055916u: goto P_0c055916;
case 0x0c055918u: goto P_0c055918;
case 0x0c05591au: goto P_0c05591a;
case 0x0c05591cu: goto P_0c05591c;
case 0x0c05591eu: goto P_0c05591e;
case 0x0c055920u: goto P_0c055920;
case 0x0c055922u: goto P_0c055922;
case 0x0c055924u: goto P_0c055924;
case 0x0c055926u: goto P_0c055926;
case 0x0c055928u: goto P_0c055928;
case 0x0c05592au: goto P_0c05592a;
case 0x0c05592cu: goto P_0c05592c;
case 0x0c05592eu: goto P_0c05592e;
case 0x0c055930u: goto P_0c055930;
case 0x0c055932u: goto P_0c055932;
case 0x0c055934u: goto P_0c055934;
case 0x0c055936u: goto P_0c055936;
case 0x0c055938u: goto P_0c055938;
case 0x0c05593au: goto P_0c05593a;
case 0x0c05593cu: goto P_0c05593c;
case 0x0c05593eu: goto P_0c05593e;
case 0x0c055940u: goto P_0c055940;
case 0x0c055942u: goto P_0c055942;
case 0x0c055944u: goto P_0c055944;
case 0x0c055946u: goto P_0c055946;
case 0x0c055948u: goto P_0c055948;
case 0x0c05594au: goto P_0c05594a;
case 0x0c05594cu: goto P_0c05594c;
case 0x0c05594eu: goto P_0c05594e;
case 0x0c055950u: goto P_0c055950;
case 0x0c055952u: goto P_0c055952;
case 0x0c055954u: goto P_0c055954;
case 0x0c055956u: goto P_0c055956;
case 0x0c055958u: goto P_0c055958;
case 0x0c05595au: goto P_0c05595a;
case 0x0c05595cu: goto P_0c05595c;
case 0x0c05595eu: goto P_0c05595e;
case 0x0c055960u: goto P_0c055960;
case 0x0c055962u: goto P_0c055962;
case 0x0c055964u: goto P_0c055964;
case 0x0c055966u: goto P_0c055966;
case 0x0c055968u: goto P_0c055968;
case 0x0c05596au: goto P_0c05596a;
case 0x0c05596cu: goto P_0c05596c;
case 0x0c05596eu: goto P_0c05596e;
case 0x0c055970u: goto P_0c055970;
case 0x0c055972u: goto P_0c055972;
case 0x0c055974u: goto P_0c055974;
case 0x0c055976u: goto P_0c055976;
case 0x0c055978u: goto P_0c055978;
case 0x0c05597au: goto P_0c05597a;
case 0x0c05597cu: goto P_0c05597c;
case 0x0c05597eu: goto P_0c05597e;
case 0x0c055980u: goto P_0c055980;
case 0x0c055982u: goto P_0c055982;
case 0x0c055984u: goto P_0c055984;
case 0x0c055986u: goto P_0c055986;
case 0x0c055988u: goto P_0c055988;
case 0x0c055be0u: goto P_0c055be0;
case 0x0c055be2u: goto P_0c055be2;
case 0x0c055be4u: goto P_0c055be4;
case 0x0c055be6u: goto P_0c055be6;
case 0x0c055be8u: goto P_0c055be8;
case 0x0c055beau: goto P_0c055bea;
case 0x0c055becu: goto P_0c055bec;
case 0x0c055beeu: goto P_0c055bee;
case 0x0c055bf0u: goto P_0c055bf0;
case 0x0c055bf2u: goto P_0c055bf2;
case 0x0c055bf4u: goto P_0c055bf4;
case 0x0c055bf6u: goto P_0c055bf6;
case 0x0c055bf8u: goto P_0c055bf8;
case 0x0c055bfau: goto P_0c055bfa;
case 0x0c055bfcu: goto P_0c055bfc;
case 0x0c055bfeu: goto P_0c055bfe;
case 0x0c055c00u: goto P_0c055c00;
case 0x0c055c02u: goto P_0c055c02;
case 0x0c055c04u: goto P_0c055c04;
case 0x0c055c06u: goto P_0c055c06;
case 0x0c055c08u: goto P_0c055c08;
case 0x0c055c0au: goto P_0c055c0a;
case 0x0c055c0cu: goto P_0c055c0c;
case 0x0c055c0eu: goto P_0c055c0e;
case 0x0c055c10u: goto P_0c055c10;
case 0x0c055c12u: goto P_0c055c12;
case 0x0c055c14u: goto P_0c055c14;
case 0x0c055c16u: goto P_0c055c16;
case 0x0c055c18u: goto P_0c055c18;
case 0x0c055c1au: goto P_0c055c1a;
case 0x0c055c1cu: goto P_0c055c1c;
case 0x0c055c1eu: goto P_0c055c1e;
case 0x0c055c20u: goto P_0c055c20;
case 0x0c055c22u: goto P_0c055c22;
case 0x0c055c24u: goto P_0c055c24;
case 0x0c055c26u: goto P_0c055c26;
case 0x0c055c28u: goto P_0c055c28;
case 0x0c055c2au: goto P_0c055c2a;
case 0x0c055c2cu: goto P_0c055c2c;
case 0x0c055c2eu: goto P_0c055c2e;
case 0x0c055c30u: goto P_0c055c30;
case 0x0c055c32u: goto P_0c055c32;
case 0x0c055c34u: goto P_0c055c34;
case 0x0c055c36u: goto P_0c055c36;
case 0x0c055c38u: goto P_0c055c38;
case 0x0c055c3au: goto P_0c055c3a;
case 0x0c055c3cu: goto P_0c055c3c;
case 0x0c055c3eu: goto P_0c055c3e;
case 0x0c055c40u: goto P_0c055c40;
case 0x0c055c42u: goto P_0c055c42;
case 0x0c055c44u: goto P_0c055c44;
case 0x0c055c46u: goto P_0c055c46;
case 0x0c055c48u: goto P_0c055c48;
case 0x0c055c4au: goto P_0c055c4a;
case 0x0c055c4cu: goto P_0c055c4c;
case 0x0c055c4eu: goto P_0c055c4e;
case 0x0c055c50u: goto P_0c055c50;
case 0x0c055c52u: goto P_0c055c52;
case 0x0c055c54u: goto P_0c055c54;
case 0x0c055c56u: goto P_0c055c56;
case 0x0c055c58u: goto P_0c055c58;
case 0x0c055c5au: goto P_0c055c5a;
case 0x0c055c5cu: goto P_0c055c5c;
case 0x0c055d00u: goto P_0c055d00;
case 0x0c055d02u: goto P_0c055d02;
case 0x0c055d04u: goto P_0c055d04;
case 0x0c055d06u: goto P_0c055d06;
case 0x0c055d08u: goto P_0c055d08;
case 0x0c055d0au: goto P_0c055d0a;
case 0x0c055d0cu: goto P_0c055d0c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c055860: /* original d006, guest PC 0x0c055860 */
if(!s->budget--) { s->failed_pc=0x0c055860u; return 0; }
r[0]=read(ram,0x0c05587cu,4);
goto P_0c055862;
P_0c055862: /* original e101, guest PC 0x0c055862 */
if(!s->budget--) { s->failed_pc=0x0c055862u; return 0; }
r[1]=0x00000001u;
goto P_0c055864;
P_0c055864: /* original 2012, guest PC 0x0c055864 */
if(!s->budget--) { s->failed_pc=0x0c055864u; return 0; }
write(ram,r[0],r[1],4);
goto P_0c055866;
P_0c055866: /* original d006, guest PC 0x0c055866 */
if(!s->budget--) { s->failed_pc=0x0c055866u; return 0; }
r[0]=read(ram,0x0c055880u,4);
goto P_0c055868;
P_0c055868: /* original f04a, guest PC 0x0c055868 */
if(!s->budget--) { s->failed_pc=0x0c055868u; return 0; }
vf3_matrix_store(s,ram,4,r[0]);
goto P_0c05586a;
P_0c05586a: /* original c707, guest PC 0x0c05586a */
if(!s->budget--) { s->failed_pc=0x0c05586au; return 0; }
r[0]=code_base|0x00055888u;
goto P_0c05586c;
P_0c05586c: /* original f008, guest PC 0x0c05586c */
if(!s->budget--) { s->failed_pc=0x0c05586cu; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c05586e;
P_0c05586e: /* original f042, guest PC 0x0c05586e */
if(!s->budget--) { s->failed_pc=0x0c05586eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c055870;
P_0c055870: /* original f03d, guest PC 0x0c055870 */
if(!s->budget--) { s->failed_pc=0x0c055870u; return 0; }
r[53]=truncate_float(fr[0]);
goto P_0c055872;
P_0c055872: /* original 015a, guest PC 0x0c055872 */
if(!s->budget--) { s->failed_pc=0x0c055872u; return 0; }
r[1]=r[53];
goto P_0c055874;
P_0c055874: /* original d003, guest PC 0x0c055874 */
if(!s->budget--) { s->failed_pc=0x0c055874u; return 0; }
r[0]=read(ram,0x0c055884u,4);
goto P_0c055876;
P_0c055876: /* original a016, guest PC 0x0c055876 */
if(!s->budget--) { s->failed_pc=0x0c055876u; return 0; }
write(ram,r[0],r[1],4);
goto P_0c0558a6;
P_0c055878: /* original 2012, guest PC 0x0c055878 */
if(!s->budget--) { s->failed_pc=0x0c055878u; return 0; }
write(ram,r[0],r[1],4);
if(!vf3_matrix_family(0x0c05587au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05587au; return 0; } return 1;
P_0c0558a0: /* original d03a, guest PC 0x0c0558a0 */
if(!s->budget--) { s->failed_pc=0x0c0558a0u; return 0; }
r[0]=read(ram,0x0c05598cu,4);
goto P_0c0558a2;
P_0c0558a2: /* original e100, guest PC 0x0c0558a2 */
if(!s->budget--) { s->failed_pc=0x0c0558a2u; return 0; }
r[1]=0x00000000u;
goto P_0c0558a4;
P_0c0558a4: /* original 2012, guest PC 0x0c0558a4 */
if(!s->budget--) { s->failed_pc=0x0c0558a4u; return 0; }
write(ram,r[0],r[1],4);
goto P_0c0558a6;
P_0c0558a6: /* original d141, guest PC 0x0c0558a6 */
if(!s->budget--) { s->failed_pc=0x0c0558a6u; return 0; }
r[1]=read(ram,0x0c0559acu,4);
goto P_0c0558a8;
P_0c0558a8: /* original fffb, guest PC 0x0c0558a8 */
if(!s->budget--) { s->failed_pc=0x0c0558a8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0558aa;
P_0c0558aa: /* original e7e0, guest PC 0x0c0558aa */
if(!s->budget--) { s->failed_pc=0x0c0558aau; return 0; }
r[7]=0xffffffe0u;
goto P_0c0558ac;
P_0c0558ac: /* original ffeb, guest PC 0x0c0558ac */
if(!s->budget--) { s->failed_pc=0x0c0558acu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0558ae;
P_0c0558ae: /* original 4728, guest PC 0x0c0558ae */
if(!s->budget--) { s->failed_pc=0x0c0558aeu; return 0; }
r[7]<<=16;
goto P_0c0558b0;
P_0c0558b0: /* original ffdb, guest PC 0x0c0558b0 */
if(!s->budget--) { s->failed_pc=0x0c0558b0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0558b2;
P_0c0558b2: /* original 4718, guest PC 0x0c0558b2 */
if(!s->budget--) { s->failed_pc=0x0c0558b2u; return 0; }
r[7]<<=8;
goto P_0c0558b4;
P_0c0558b4: /* original ffcb, guest PC 0x0c0558b4 */
if(!s->budget--) { s->failed_pc=0x0c0558b4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0558b6;
P_0c0558b6: /* original 6277, guest PC 0x0c0558b6 */
if(!s->budget--) { s->failed_pc=0x0c0558b6u; return 0; }
r[2]=~r[7];
goto P_0c0558b8;
P_0c0558b8: /* original 6112, guest PC 0x0c0558b8 */
if(!s->budget--) { s->failed_pc=0x0c0558b8u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c0558ba;
P_0c0558ba: /* original 4201, guest PC 0x0c0558ba */
if(!s->budget--) { s->failed_pc=0x0c0558bau; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]>>=1;
goto P_0c0558bc;
P_0c0558bc: /* original 2fe6, guest PC 0x0c0558bc */
if(!s->budget--) { s->failed_pc=0x0c0558bcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558be;
P_0c0558be: /* original 4209, guest PC 0x0c0558be */
if(!s->budget--) { s->failed_pc=0x0c0558beu; return 0; }
r[2]>>=2;
goto P_0c0558c0;
P_0c0558c0: /* original 2fd6, guest PC 0x0c0558c0 */
if(!s->budget--) { s->failed_pc=0x0c0558c0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558c2;
P_0c0558c2: /* original 2fc6, guest PC 0x0c0558c2 */
if(!s->budget--) { s->failed_pc=0x0c0558c2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558c4;
P_0c0558c4: /* original 5610, guest PC 0x0c0558c4 */
if(!s->budget--) { s->failed_pc=0x0c0558c4u; return 0; }
r[6]=read(ram,r[1]+0,4);
goto P_0c0558c6;
P_0c0558c6: /* original 5312, guest PC 0x0c0558c6 */
if(!s->budget--) { s->failed_pc=0x0c0558c6u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c0558c8;
P_0c0558c8: /* original 2fb6, guest PC 0x0c0558c8 */
if(!s->budget--) { s->failed_pc=0x0c0558c8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558ca;
P_0c0558ca: /* original c739, guest PC 0x0c0558ca */
if(!s->budget--) { s->failed_pc=0x0c0558cau; return 0; }
r[0]=code_base|0x000559b0u;
goto P_0c0558cc;
P_0c0558cc: /* original 2fa6, guest PC 0x0c0558cc */
if(!s->budget--) { s->failed_pc=0x0c0558ccu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558ce;
P_0c0558ce: /* original 2f96, guest PC 0x0c0558ce */
if(!s->budget--) { s->failed_pc=0x0c0558ceu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558d0;
P_0c0558d0: /* original 2629, guest PC 0x0c0558d0 */
if(!s->budget--) { s->failed_pc=0x0c0558d0u; return 0; }
r[6]&=r[2];
goto P_0c0558d2;
P_0c0558d2: /* original 2f86, guest PC 0x0c0558d2 */
if(!s->budget--) { s->failed_pc=0x0c0558d2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0558d4;
P_0c0558d4: /* original 5814, guest PC 0x0c0558d4 */
if(!s->budget--) { s->failed_pc=0x0c0558d4u; return 0; }
r[8]=read(ram,r[1]+16,4);
goto P_0c0558d6;
P_0c0558d6: /* original 2329, guest PC 0x0c0558d6 */
if(!s->budget--) { s->failed_pc=0x0c0558d6u; return 0; }
r[3]&=r[2];
goto P_0c0558d8;
P_0c0558d8: /* original 2829, guest PC 0x0c0558d8 */
if(!s->budget--) { s->failed_pc=0x0c0558d8u; return 0; }
r[8]&=r[2];
goto P_0c0558da;
P_0c0558da: /* original 4f22, guest PC 0x0c0558da */
if(!s->budget--) { s->failed_pc=0x0c0558dau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0558dc;
P_0c0558dc: /* original 4f13, guest PC 0x0c0558dc */
if(!s->budget--) { s->failed_pc=0x0c0558dcu; return 0; }
if(!s->gbr_known) goto unsupported;
r[15]-=4; write(ram,r[15],s->gbr,4);
goto P_0c0558de;
P_0c0558de: /* original 4017, guest PC 0x0c0558de */
if(!s->budget--) { s->failed_pc=0x0c0558deu; return 0; }
s->gbr=read(ram,r[0],4); r[0]+=4; s->gbr_known=1;
goto P_0c0558e0;
P_0c0558e0: /* original 402a, guest PC 0x0c0558e0 */
if(!s->budget--) { s->failed_pc=0x0c0558e0u; return 0; }
r[16]=r[0];
goto P_0c0558e2;
P_0c0558e2: /* original 267b, guest PC 0x0c0558e2 */
if(!s->budget--) { s->failed_pc=0x0c0558e2u; return 0; }
r[6]|=r[7];
goto P_0c0558e4;
P_0c0558e4: /* original 237b, guest PC 0x0c0558e4 */
if(!s->budget--) { s->failed_pc=0x0c0558e4u; return 0; }
r[3]|=r[7];
goto P_0c0558e6;
P_0c0558e6: /* original 287b, guest PC 0x0c0558e6 */
if(!s->budget--) { s->failed_pc=0x0c0558e6u; return 0; }
r[8]|=r[7];
goto P_0c0558e8;
P_0c0558e8: /* original 6063, guest PC 0x0c0558e8 */
if(!s->budget--) { s->failed_pc=0x0c0558e8u; return 0; }
r[0]=r[6];
goto P_0c0558ea;
P_0c0558ea: /* original c212, guest PC 0x0c0558ea */
if(!s->budget--) { s->failed_pc=0x0c0558eau; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+72,r[0],4);
goto P_0c0558ec;
P_0c0558ec: /* original 6033, guest PC 0x0c0558ec */
if(!s->budget--) { s->failed_pc=0x0c0558ecu; return 0; }
r[0]=r[3];
goto P_0c0558ee;
P_0c0558ee: /* original c214, guest PC 0x0c0558ee */
if(!s->budget--) { s->failed_pc=0x0c0558eeu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+80,r[0],4);
goto P_0c0558f0;
P_0c0558f0: /* original 6083, guest PC 0x0c0558f0 */
if(!s->budget--) { s->failed_pc=0x0c0558f0u; return 0; }
r[0]=r[8];
goto P_0c0558f2;
P_0c0558f2: /* original c216, guest PC 0x0c0558f2 */
if(!s->budget--) { s->failed_pc=0x0c0558f2u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+88,r[0],4);
goto P_0c0558f4;
P_0c0558f4: /* original 5d40, guest PC 0x0c0558f4 */
if(!s->budget--) { s->failed_pc=0x0c0558f4u; return 0; }
r[13]=read(ram,r[4]+0,4);
goto P_0c0558f6;
P_0c0558f6: /* original 6e43, guest PC 0x0c0558f6 */
if(!s->budget--) { s->failed_pc=0x0c0558f6u; return 0; }
r[14]=r[4];
goto P_0c0558f8;
P_0c0558f8: /* original 4f22, guest PC 0x0c0558f8 */
if(!s->budget--) { s->failed_pc=0x0c0558f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0558fa;
P_0c0558fa: /* original 60d3, guest PC 0x0c0558fa */
if(!s->budget--) { s->failed_pc=0x0c0558fau; return 0; }
r[0]=r[13];
goto P_0c0558fc;
P_0c0558fc: /* original c83e, guest PC 0x0c0558fc */
if(!s->budget--) { s->failed_pc=0x0c0558fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&62u)==0)!=0);
goto P_0c0558fe;
P_0c0558fe: /* original 2fd6, guest PC 0x0c0558fe */
if(!s->budget--) { s->failed_pc=0x0c0558feu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055900;
P_0c055900: /* original 8927, guest PC 0x0c055900 */
if(!s->budget--) { s->failed_pc=0x0c055900u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055952; }
goto P_0c055902;
P_0c055902: /* original d123, guest PC 0x0c055902 */
if(!s->budget--) { s->failed_pc=0x0c055902u; return 0; }
r[1]=read(ram,0x0c055990u,4);
goto P_0c055904;
P_0c055904: /* original 410b, guest PC 0x0c055904 */
if(!s->budget--) { s->failed_pc=0x0c055904u; return 0; }
target=r[1];
r[16]=code_base|0x0c055908u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055908u) { target=s->pc; goto dispatch; }
goto P_0c055908;
P_0c055906: /* original e400, guest PC 0x0c055906 */
if(!s->budget--) { s->failed_pc=0x0c055906u; return 0; }
r[4]=0x00000000u;
goto P_0c055908;
P_0c055908: /* original 60d3, guest PC 0x0c055908 */
if(!s->budget--) { s->failed_pc=0x0c055908u; return 0; }
r[0]=r[13];
goto P_0c05590a;
P_0c05590a: /* original c802, guest PC 0x0c05590a */
if(!s->budget--) { s->failed_pc=0x0c05590au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c05590c;
P_0c05590c: /* original d121, guest PC 0x0c05590c */
if(!s->budget--) { s->failed_pc=0x0c05590cu; return 0; }
r[1]=read(ram,0x0c055994u,4);
goto P_0c05590e;
P_0c05590e: /* original 64e3, guest PC 0x0c05590e */
if(!s->budget--) { s->failed_pc=0x0c05590eu; return 0; }
r[4]=r[14];
goto P_0c055910;
P_0c055910: /* original 8d05, guest PC 0x0c055910 */
if(!s->budget--) { s->failed_pc=0x0c055910u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000008u;
if(cond) { goto P_0c05591e; }
goto P_0c055914;
P_0c055912: /* original 7408, guest PC 0x0c055912 */
if(!s->budget--) { s->failed_pc=0x0c055912u; return 0; }
r[4]+=0x00000008u;
goto P_0c055914;
P_0c055914: /* original f449, guest PC 0x0c055914 */
if(!s->budget--) { s->failed_pc=0x0c055914u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c055916;
P_0c055916: /* original f549, guest PC 0x0c055916 */
if(!s->budget--) { s->failed_pc=0x0c055916u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c055918;
P_0c055918: /* original 410b, guest PC 0x0c055918 */
if(!s->budget--) { s->failed_pc=0x0c055918u; return 0; }
target=r[1];
r[16]=code_base|0x0c05591cu;
vf3_matrix_load(s,ram,6,r[4]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05591cu) { target=s->pc; goto dispatch; }
goto P_0c05591c;
P_0c05591a: /* original f648, guest PC 0x0c05591a */
if(!s->budget--) { s->failed_pc=0x0c05591au; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c05591c;
P_0c05591c: /* original 60d3, guest PC 0x0c05591c */
if(!s->budget--) { s->failed_pc=0x0c05591cu; return 0; }
r[0]=r[13];
goto P_0c05591e;
P_0c05591e: /* original c838, guest PC 0x0c05591e */
if(!s->budget--) { s->failed_pc=0x0c05591eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&56u)==0)!=0);
goto P_0c055920;
P_0c055920: /* original 8d11, guest PC 0x0c055920 */
if(!s->budget--) { s->failed_pc=0x0c055920u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
if(cond) { goto P_0c055946; }
goto P_0c055924;
P_0c055922: /* original c820, guest PC 0x0c055922 */
if(!s->budget--) { s->failed_pc=0x0c055922u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c055924;
P_0c055924: /* original d31c, guest PC 0x0c055924 */
if(!s->budget--) { s->failed_pc=0x0c055924u; return 0; }
r[3]=read(ram,0x0c055998u,4);
goto P_0c055926;
P_0c055926: /* original 8902, guest PC 0x0c055926 */
if(!s->budget--) { s->failed_pc=0x0c055926u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05592e; }
goto P_0c055928;
P_0c055928: /* original 430b, guest PC 0x0c055928 */
if(!s->budget--) { s->failed_pc=0x0c055928u; return 0; }
target=r[3];
r[16]=code_base|0x0c05592cu;
r[4]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05592cu) { target=s->pc; goto dispatch; }
goto P_0c05592c;
P_0c05592a: /* original 54e7, guest PC 0x0c05592a */
if(!s->budget--) { s->failed_pc=0x0c05592au; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c05592c;
P_0c05592c: /* original 60d3, guest PC 0x0c05592c */
if(!s->budget--) { s->failed_pc=0x0c05592cu; return 0; }
r[0]=r[13];
goto P_0c05592e;
P_0c05592e: /* original c810, guest PC 0x0c05592e */
if(!s->budget--) { s->failed_pc=0x0c05592eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c055930;
P_0c055930: /* original d21a, guest PC 0x0c055930 */
if(!s->budget--) { s->failed_pc=0x0c055930u; return 0; }
r[2]=read(ram,0x0c05599cu,4);
goto P_0c055932;
P_0c055932: /* original 8902, guest PC 0x0c055932 */
if(!s->budget--) { s->failed_pc=0x0c055932u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05593a; }
goto P_0c055934;
P_0c055934: /* original 420b, guest PC 0x0c055934 */
if(!s->budget--) { s->failed_pc=0x0c055934u; return 0; }
target=r[2];
r[16]=code_base|0x0c055938u;
r[4]=read(ram,r[14]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055938u) { target=s->pc; goto dispatch; }
goto P_0c055938;
P_0c055936: /* original 54e6, guest PC 0x0c055936 */
if(!s->budget--) { s->failed_pc=0x0c055936u; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c055938;
P_0c055938: /* original 60d3, guest PC 0x0c055938 */
if(!s->budget--) { s->failed_pc=0x0c055938u; return 0; }
r[0]=r[13];
goto P_0c05593a;
P_0c05593a: /* original c808, guest PC 0x0c05593a */
if(!s->budget--) { s->failed_pc=0x0c05593au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c05593c;
P_0c05593c: /* original d118, guest PC 0x0c05593c */
if(!s->budget--) { s->failed_pc=0x0c05593cu; return 0; }
r[1]=read(ram,0x0c0559a0u,4);
goto P_0c05593e;
P_0c05593e: /* original 8902, guest PC 0x0c05593e */
if(!s->budget--) { s->failed_pc=0x0c05593eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055946; }
goto P_0c055940;
P_0c055940: /* original 410b, guest PC 0x0c055940 */
if(!s->budget--) { s->failed_pc=0x0c055940u; return 0; }
target=r[1];
r[16]=code_base|0x0c055944u;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055944u) { target=s->pc; goto dispatch; }
goto P_0c055944;
P_0c055942: /* original 54e5, guest PC 0x0c055942 */
if(!s->budget--) { s->failed_pc=0x0c055942u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c055944;
P_0c055944: /* original 60d3, guest PC 0x0c055944 */
if(!s->budget--) { s->failed_pc=0x0c055944u; return 0; }
r[0]=r[13];
goto P_0c055946;
P_0c055946: /* original c804, guest PC 0x0c055946 */
if(!s->budget--) { s->failed_pc=0x0c055946u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c055948;
P_0c055948: /* original d316, guest PC 0x0c055948 */
if(!s->budget--) { s->failed_pc=0x0c055948u; return 0; }
r[3]=read(ram,0x0c0559a4u,4);
goto P_0c05594a;
P_0c05594a: /* original 8902, guest PC 0x0c05594a */
if(!s->budget--) { s->failed_pc=0x0c05594au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055952; }
goto P_0c05594c;
P_0c05594c: /* original 64e3, guest PC 0x0c05594c */
if(!s->budget--) { s->failed_pc=0x0c05594cu; return 0; }
r[4]=r[14];
goto P_0c05594e;
P_0c05594e: /* original 430b, guest PC 0x0c05594e */
if(!s->budget--) { s->failed_pc=0x0c05594eu; return 0; }
target=r[3];
r[16]=code_base|0x0c055952u;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055952u) { target=s->pc; goto dispatch; }
goto P_0c055952;
P_0c055950: /* original 7420, guest PC 0x0c055950 */
if(!s->budget--) { s->failed_pc=0x0c055950u; return 0; }
r[4]+=0x00000020u;
goto P_0c055952;
P_0c055952: /* original 54e1, guest PC 0x0c055952 */
if(!s->budget--) { s->failed_pc=0x0c055952u; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c055954;
P_0c055954: /* original 2448, guest PC 0x0c055954 */
if(!s->budget--) { s->failed_pc=0x0c055954u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c055956;
P_0c055956: /* original 2fe6, guest PC 0x0c055956 */
if(!s->budget--) { s->failed_pc=0x0c055956u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055958;
P_0c055958: /* original 8903, guest PC 0x0c055958 */
if(!s->budget--) { s->failed_pc=0x0c055958u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055962; }
goto P_0c05595a;
P_0c05595a: /* original bea1, guest PC 0x0c05595a */
if(!s->budget--) { s->failed_pc=0x0c05595au; return 0; }
target=code_base|0x0c0556a0u; r[16]=code_base|0x0c05595eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05595eu) { target=s->pc; goto dispatch; }
goto P_0c05595e;
P_0c05595c: /* original 0009, guest PC 0x0c05595c */
if(!s->budget--) { s->failed_pc=0x0c05595cu; return 0; }
goto P_0c05595e;
P_0c05595e: /* original 5ef0, guest PC 0x0c05595e */
if(!s->budget--) { s->failed_pc=0x0c05595eu; return 0; }
r[14]=read(ram,r[15]+0,4);
goto P_0c055960;
P_0c055960: /* original 5df1, guest PC 0x0c055960 */
if(!s->budget--) { s->failed_pc=0x0c055960u; return 0; }
r[13]=read(ram,r[15]+4,4);
goto P_0c055962;
P_0c055962: /* original 54eb, guest PC 0x0c055962 */
if(!s->budget--) { s->failed_pc=0x0c055962u; return 0; }
r[4]=read(ram,r[14]+44,4);
goto P_0c055964;
P_0c055964: /* original 2448, guest PC 0x0c055964 */
if(!s->budget--) { s->failed_pc=0x0c055964u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c055966;
P_0c055966: /* original 8903, guest PC 0x0c055966 */
if(!s->budget--) { s->failed_pc=0x0c055966u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055970; }
goto P_0c055968;
P_0c055968: /* original bfc4, guest PC 0x0c055968 */
if(!s->budget--) { s->failed_pc=0x0c055968u; return 0; }
target=code_base|0x0c0558f4u; r[16]=code_base|0x0c05596cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05596cu) { target=s->pc; goto dispatch; }
goto P_0c05596c;
P_0c05596a: /* original 0009, guest PC 0x0c05596a */
if(!s->budget--) { s->failed_pc=0x0c05596au; return 0; }
goto P_0c05596c;
P_0c05596c: /* original 5df1, guest PC 0x0c05596c */
if(!s->budget--) { s->failed_pc=0x0c05596cu; return 0; }
r[13]=read(ram,r[15]+4,4);
goto P_0c05596e;
P_0c05596e: /* original 5ef0, guest PC 0x0c05596e */
if(!s->budget--) { s->failed_pc=0x0c05596eu; return 0; }
r[14]=read(ram,r[15]+0,4);
goto P_0c055970;
P_0c055970: /* original 60d3, guest PC 0x0c055970 */
if(!s->budget--) { s->failed_pc=0x0c055970u; return 0; }
r[0]=r[13];
goto P_0c055972;
P_0c055972: /* original c83e, guest PC 0x0c055972 */
if(!s->budget--) { s->failed_pc=0x0c055972u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&62u)==0)!=0);
goto P_0c055974;
P_0c055974: /* original d10c, guest PC 0x0c055974 */
if(!s->budget--) { s->failed_pc=0x0c055974u; return 0; }
r[1]=read(ram,0x0c0559a8u,4);
goto P_0c055976;
P_0c055976: /* original 7f08, guest PC 0x0c055976 */
if(!s->budget--) { s->failed_pc=0x0c055976u; return 0; }
r[15]+=0x00000008u;
goto P_0c055978;
P_0c055978: /* original 8901, guest PC 0x0c055978 */
if(!s->budget--) { s->failed_pc=0x0c055978u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05597e; }
goto P_0c05597a;
P_0c05597a: /* original 410b, guest PC 0x0c05597a */
if(!s->budget--) { s->failed_pc=0x0c05597au; return 0; }
target=r[1];
r[16]=code_base|0x0c05597eu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05597eu) { target=s->pc; goto dispatch; }
goto P_0c05597e;
P_0c05597c: /* original e401, guest PC 0x0c05597c */
if(!s->budget--) { s->failed_pc=0x0c05597cu; return 0; }
r[4]=0x00000001u;
goto P_0c05597e;
P_0c05597e: /* original 54ec, guest PC 0x0c05597e */
if(!s->budget--) { s->failed_pc=0x0c05597eu; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c055980;
P_0c055980: /* original 4f26, guest PC 0x0c055980 */
if(!s->budget--) { s->failed_pc=0x0c055980u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c055982;
P_0c055982: /* original 2448, guest PC 0x0c055982 */
if(!s->budget--) { s->failed_pc=0x0c055982u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c055984;
P_0c055984: /* original 8bb6, guest PC 0x0c055984 */
if(!s->budget--) { s->failed_pc=0x0c055984u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0558f4; }
goto P_0c055986;
P_0c055986: /* original 000b, guest PC 0x0c055986 */
if(!s->budget--) { s->failed_pc=0x0c055986u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c055988: /* original 0009, guest PC 0x0c055988 */
if(!s->budget--) { s->failed_pc=0x0c055988u; return 0; }
if(!vf3_matrix_family(0x0c05598au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05598au; return 0; } return 1;
P_0c055be0: /* original d01f, guest PC 0x0c055be0 */
if(!s->budget--) { s->failed_pc=0x0c055be0u; return 0; }
r[0]=read(ram,0x0c055c60u,4);
goto P_0c055be2;
P_0c055be2: /* original e100, guest PC 0x0c055be2 */
if(!s->budget--) { s->failed_pc=0x0c055be2u; return 0; }
r[1]=0x00000000u;
goto P_0c055be4;
P_0c055be4: /* original 2012, guest PC 0x0c055be4 */
if(!s->budget--) { s->failed_pc=0x0c055be4u; return 0; }
write(ram,r[0],r[1],4);
goto P_0c055be6;
P_0c055be6: /* original fffb, guest PC 0x0c055be6 */
if(!s->budget--) { s->failed_pc=0x0c055be6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c055be8;
P_0c055be8: /* original ffeb, guest PC 0x0c055be8 */
if(!s->budget--) { s->failed_pc=0x0c055be8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c055bea;
P_0c055bea: /* original ffdb, guest PC 0x0c055bea */
if(!s->budget--) { s->failed_pc=0x0c055beau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c055bec;
P_0c055bec: /* original ffcb, guest PC 0x0c055bec */
if(!s->budget--) { s->failed_pc=0x0c055becu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c055bee;
P_0c055bee: /* original 2fe6, guest PC 0x0c055bee */
if(!s->budget--) { s->failed_pc=0x0c055beeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055bf0;
P_0c055bf0: /* original 2fd6, guest PC 0x0c055bf0 */
if(!s->budget--) { s->failed_pc=0x0c055bf0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055bf2;
P_0c055bf2: /* original 2fc6, guest PC 0x0c055bf2 */
if(!s->budget--) { s->failed_pc=0x0c055bf2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055bf4;
P_0c055bf4: /* original 2fb6, guest PC 0x0c055bf4 */
if(!s->budget--) { s->failed_pc=0x0c055bf4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055bf6;
P_0c055bf6: /* original 2fa6, guest PC 0x0c055bf6 */
if(!s->budget--) { s->failed_pc=0x0c055bf6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055bf8;
P_0c055bf8: /* original 2f96, guest PC 0x0c055bf8 */
if(!s->budget--) { s->failed_pc=0x0c055bf8u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055bfa;
P_0c055bfa: /* original 2f86, guest PC 0x0c055bfa */
if(!s->budget--) { s->failed_pc=0x0c055bfau; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055bfc;
P_0c055bfc: /* original 4f22, guest PC 0x0c055bfc */
if(!s->budget--) { s->failed_pc=0x0c055bfcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c055bfe;
P_0c055bfe: /* original 6e43, guest PC 0x0c055bfe */
if(!s->budget--) { s->failed_pc=0x0c055bfeu; return 0; }
r[14]=r[4];
goto P_0c055c00;
P_0c055c00: /* original d348, guest PC 0x0c055c00 */
if(!s->budget--) { s->failed_pc=0x0c055c00u; return 0; }
r[3]=read(ram,0x0c055d24u,4);
goto P_0c055c02;
P_0c055c02: /* original 430b, guest PC 0x0c055c02 */
if(!s->budget--) { s->failed_pc=0x0c055c02u; return 0; }
target=r[3];
r[16]=code_base|0x0c055c06u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055c06u) { target=s->pc; goto dispatch; }
goto P_0c055c06;
P_0c055c04: /* original e400, guest PC 0x0c055c04 */
if(!s->budget--) { s->failed_pc=0x0c055c04u; return 0; }
r[4]=0x00000000u;
goto P_0c055c06;
P_0c055c06: /* original c605, guest PC 0x0c055c06 */
if(!s->budget--) { s->failed_pc=0x0c055c06u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+20,4);
goto P_0c055c08;
P_0c055c08: /* original 400b, guest PC 0x0c055c08 */
if(!s->budget--) { s->failed_pc=0x0c055c08u; return 0; }
target=r[0];
r[16]=code_base|0x0c055c0cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055c0cu) { target=s->pc; goto dispatch; }
goto P_0c055c0c;
P_0c055c0a: /* original 0009, guest PC 0x0c055c0a */
if(!s->budget--) { s->failed_pc=0x0c055c0au; return 0; }
goto P_0c055c0c;
P_0c055c0c: /* original d347, guest PC 0x0c055c0c */
if(!s->budget--) { s->failed_pc=0x0c055c0cu; return 0; }
r[3]=read(ram,0x0c055d2cu,4);
goto P_0c055c0e;
P_0c055c0e: /* original c749, guest PC 0x0c055c0e */
if(!s->budget--) { s->failed_pc=0x0c055c0eu; return 0; }
r[0]=code_base|0x00055d34u;
goto P_0c055c10;
P_0c055c10: /* original 6106, guest PC 0x0c055c10 */
if(!s->budget--) { s->failed_pc=0x0c055c10u; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[1]=tmp;
goto P_0c055c12;
P_0c055c12: /* original f418, guest PC 0x0c055c12 */
if(!s->budget--) { s->failed_pc=0x0c055c12u; return 0; }
vf3_matrix_load(s,ram,4,r[1]);
goto P_0c055c14;
P_0c055c14: /* original 6106, guest PC 0x0c055c14 */
if(!s->budget--) { s->failed_pc=0x0c055c14u; return 0; }
tmp=read(ram,r[0],4);
r[0]+=4;
r[1]=tmp;
goto P_0c055c16;
P_0c055c16: /* original 430b, guest PC 0x0c055c16 */
if(!s->budget--) { s->failed_pc=0x0c055c16u; return 0; }
target=r[3];
r[16]=code_base|0x0c055c1au;
vf3_matrix_load(s,ram,5,r[1]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055c1au) { target=s->pc; goto dispatch; }
goto P_0c055c1a;
P_0c055c18: /* original f518, guest PC 0x0c055c18 */
if(!s->budget--) { s->failed_pc=0x0c055c18u; return 0; }
vf3_matrix_load(s,ram,5,r[1]);
goto P_0c055c1a;
P_0c055c1a: /* original 54e1, guest PC 0x0c055c1a */
if(!s->budget--) { s->failed_pc=0x0c055c1au; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c055c1c;
P_0c055c1c: /* original c60b, guest PC 0x0c055c1c */
if(!s->budget--) { s->failed_pc=0x0c055c1cu; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+44,4);
goto P_0c055c1e;
P_0c055c1e: /* original 6503, guest PC 0x0c055c1e */
if(!s->budget--) { s->failed_pc=0x0c055c1eu; return 0; }
r[5]=r[0];
goto P_0c055c20;
P_0c055c20: /* original c604, guest PC 0x0c055c20 */
if(!s->budget--) { s->failed_pc=0x0c055c20u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+16,4);
goto P_0c055c22;
P_0c055c22: /* original 67e3, guest PC 0x0c055c22 */
if(!s->budget--) { s->failed_pc=0x0c055c22u; return 0; }
r[7]=r[14];
goto P_0c055c24;
P_0c055c24: /* original 400b, guest PC 0x0c055c24 */
if(!s->budget--) { s->failed_pc=0x0c055c24u; return 0; }
target=r[0];
r[16]=code_base|0x0c055c28u;
r[6]=read(ram,r[14]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055c28u) { target=s->pc; goto dispatch; }
goto P_0c055c28;
P_0c055c26: /* original 56e2, guest PC 0x0c055c26 */
if(!s->budget--) { s->failed_pc=0x0c055c26u; return 0; }
r[6]=read(ram,r[14]+8,4);
goto P_0c055c28;
P_0c055c28: /* original d33f, guest PC 0x0c055c28 */
if(!s->budget--) { s->failed_pc=0x0c055c28u; return 0; }
r[3]=read(ram,0x0c055d28u,4);
goto P_0c055c2a;
P_0c055c2a: /* original 430b, guest PC 0x0c055c2a */
if(!s->budget--) { s->failed_pc=0x0c055c2au; return 0; }
target=r[3];
r[16]=code_base|0x0c055c2eu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055c2eu) { target=s->pc; goto dispatch; }
goto P_0c055c2e;
P_0c055c2c: /* original e401, guest PC 0x0c055c2c */
if(!s->budget--) { s->failed_pc=0x0c055c2cu; return 0; }
r[4]=0x00000001u;
goto P_0c055c2e;
P_0c055c2e: /* original 64e3, guest PC 0x0c055c2e */
if(!s->budget--) { s->failed_pc=0x0c055c2eu; return 0; }
r[4]=r[14];
goto P_0c055c30;
P_0c055c30: /* original e001, guest PC 0x0c055c30 */
if(!s->budget--) { s->failed_pc=0x0c055c30u; return 0; }
r[0]=0x00000001u;
goto P_0c055c32;
P_0c055c32: /* original d10c, guest PC 0x0c055c32 */
if(!s->budget--) { s->failed_pc=0x0c055c32u; return 0; }
r[1]=read(ram,0x0c055c64u,4);
goto P_0c055c34;
P_0c055c34: /* original 410b, guest PC 0x0c055c34 */
if(!s->budget--) { s->failed_pc=0x0c055c34u; return 0; }
target=r[1];
r[16]=code_base|0x0c055c38u;
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+68,r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055c38u) { target=s->pc; goto dispatch; }
goto P_0c055c38;
P_0c055c36: /* original c211, guest PC 0x0c055c36 */
if(!s->budget--) { s->failed_pc=0x0c055c36u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+68,r[0],4);
goto P_0c055c38;
P_0c055c38: /* original c60c, guest PC 0x0c055c38 */
if(!s->budget--) { s->failed_pc=0x0c055c38u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+48,4);
goto P_0c055c3a;
P_0c055c3a: /* original c20b, guest PC 0x0c055c3a */
if(!s->budget--) { s->failed_pc=0x0c055c3au; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+44,r[0],4);
goto P_0c055c3c;
P_0c055c3c: /* original c60f, guest PC 0x0c055c3c */
if(!s->budget--) { s->failed_pc=0x0c055c3cu; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+60,4);
goto P_0c055c3e;
P_0c055c3e: /* original c20e, guest PC 0x0c055c3e */
if(!s->budget--) { s->failed_pc=0x0c055c3eu; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+56,r[0],4);
goto P_0c055c40;
P_0c055c40: /* original e000, guest PC 0x0c055c40 */
if(!s->budget--) { s->failed_pc=0x0c055c40u; return 0; }
r[0]=0x00000000u;
goto P_0c055c42;
P_0c055c42: /* original c211, guest PC 0x0c055c42 */
if(!s->budget--) { s->failed_pc=0x0c055c42u; return 0; }
if(!s->gbr_known) goto unsupported;
write(ram,s->gbr+68,r[0],4);
goto P_0c055c44;
P_0c055c44: /* original 4f26, guest PC 0x0c055c44 */
if(!s->budget--) { s->failed_pc=0x0c055c44u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c055c46;
P_0c055c46: /* original 68f6, guest PC 0x0c055c46 */
if(!s->budget--) { s->failed_pc=0x0c055c46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c055c48;
P_0c055c48: /* original 69f6, guest PC 0x0c055c48 */
if(!s->budget--) { s->failed_pc=0x0c055c48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c055c4a;
P_0c055c4a: /* original 6af6, guest PC 0x0c055c4a */
if(!s->budget--) { s->failed_pc=0x0c055c4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c055c4c;
P_0c055c4c: /* original 6bf6, guest PC 0x0c055c4c */
if(!s->budget--) { s->failed_pc=0x0c055c4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c055c4e;
P_0c055c4e: /* original 6cf6, guest PC 0x0c055c4e */
if(!s->budget--) { s->failed_pc=0x0c055c4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c055c50;
P_0c055c50: /* original 6df6, guest PC 0x0c055c50 */
if(!s->budget--) { s->failed_pc=0x0c055c50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c055c52;
P_0c055c52: /* original 6ef6, guest PC 0x0c055c52 */
if(!s->budget--) { s->failed_pc=0x0c055c52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c055c54;
P_0c055c54: /* original fcf9, guest PC 0x0c055c54 */
if(!s->budget--) { s->failed_pc=0x0c055c54u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c055c56;
P_0c055c56: /* original fdf9, guest PC 0x0c055c56 */
if(!s->budget--) { s->failed_pc=0x0c055c56u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c055c58;
P_0c055c58: /* original fef9, guest PC 0x0c055c58 */
if(!s->budget--) { s->failed_pc=0x0c055c58u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c055c5a;
P_0c055c5a: /* original 000b, guest PC 0x0c055c5a */
if(!s->budget--) { s->failed_pc=0x0c055c5au; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c055c5c: /* original fff9, guest PC 0x0c055c5c */
if(!s->budget--) { s->failed_pc=0x0c055c5cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c055c5eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c055c5eu; return 0; } return 1;
P_0c055d00: /* original 4f22, guest PC 0x0c055d00 */
if(!s->budget--) { s->failed_pc=0x0c055d00u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c055d02;
P_0c055d02: /* original d10b, guest PC 0x0c055d02 */
if(!s->budget--) { s->failed_pc=0x0c055d02u; return 0; }
r[1]=read(ram,0x0c055d30u,4);
goto P_0c055d04;
P_0c055d04: /* original 410b, guest PC 0x0c055d04 */
if(!s->budget--) { s->failed_pc=0x0c055d04u; return 0; }
target=r[1];
r[16]=code_base|0x0c055d08u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c055d08u) { target=s->pc; goto dispatch; }
goto P_0c055d08;
P_0c055d06: /* original 0009, guest PC 0x0c055d06 */
if(!s->budget--) { s->failed_pc=0x0c055d06u; return 0; }
goto P_0c055d08;
P_0c055d08: /* original 4f26, guest PC 0x0c055d08 */
if(!s->budget--) { s->failed_pc=0x0c055d08u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c055d0a;
P_0c055d0a: /* original 000b, guest PC 0x0c055d0a */
if(!s->budget--) { s->failed_pc=0x0c055d0au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c055d0c: /* original 0009, guest PC 0x0c055d0c */
if(!s->budget--) { s->failed_pc=0x0c055d0cu; return 0; }
if(!vf3_matrix_family(0x0c055d0eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c055d0eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
