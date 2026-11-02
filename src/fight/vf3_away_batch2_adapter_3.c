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
int vf3_away_batch2_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0396c0u: goto P_0c0396c0;
case 0x0c0396c2u: goto P_0c0396c2;
case 0x0c0396c4u: goto P_0c0396c4;
case 0x0c0396c6u: goto P_0c0396c6;
case 0x0c0396c8u: goto P_0c0396c8;
case 0x0c0396cau: goto P_0c0396ca;
case 0x0c0396ccu: goto P_0c0396cc;
case 0x0c0396ceu: goto P_0c0396ce;
case 0x0c0396d0u: goto P_0c0396d0;
case 0x0c0396d2u: goto P_0c0396d2;
case 0x0c0396d4u: goto P_0c0396d4;
case 0x0c0396d6u: goto P_0c0396d6;
case 0x0c0396d8u: goto P_0c0396d8;
case 0x0c0396dau: goto P_0c0396da;
case 0x0c0396dcu: goto P_0c0396dc;
case 0x0c0396deu: goto P_0c0396de;
case 0x0c0396e0u: goto P_0c0396e0;
case 0x0c0396e2u: goto P_0c0396e2;
case 0x0c0396e4u: goto P_0c0396e4;
case 0x0c0396e6u: goto P_0c0396e6;
case 0x0c0396e8u: goto P_0c0396e8;
case 0x0c0396eau: goto P_0c0396ea;
case 0x0c0396f0u: goto P_0c0396f0;
case 0x0c0396f2u: goto P_0c0396f2;
case 0x0c039700u: goto P_0c039700;
case 0x0c039702u: goto P_0c039702;
case 0x0c039704u: goto P_0c039704;
case 0x0c039706u: goto P_0c039706;
case 0x0c039708u: goto P_0c039708;
case 0x0c03970au: goto P_0c03970a;
case 0x0c03970cu: goto P_0c03970c;
case 0x0c03970eu: goto P_0c03970e;
case 0x0c039710u: goto P_0c039710;
case 0x0c039712u: goto P_0c039712;
case 0x0c039714u: goto P_0c039714;
case 0x0c039716u: goto P_0c039716;
case 0x0c039718u: goto P_0c039718;
case 0x0c03971au: goto P_0c03971a;
case 0x0c03971cu: goto P_0c03971c;
case 0x0c03971eu: goto P_0c03971e;
case 0x0c039720u: goto P_0c039720;
case 0x0c039722u: goto P_0c039722;
case 0x0c039724u: goto P_0c039724;
case 0x0c039726u: goto P_0c039726;
case 0x0c039728u: goto P_0c039728;
case 0x0c03972au: goto P_0c03972a;
case 0x0c03972cu: goto P_0c03972c;
case 0x0c03972eu: goto P_0c03972e;
case 0x0c039730u: goto P_0c039730;
case 0x0c039fd0u: goto P_0c039fd0;
case 0x0c039fd2u: goto P_0c039fd2;
case 0x0c039fd4u: goto P_0c039fd4;
case 0x0c039fd6u: goto P_0c039fd6;
case 0x0c039fd8u: goto P_0c039fd8;
case 0x0c039fdau: goto P_0c039fda;
case 0x0c039fdcu: goto P_0c039fdc;
case 0x0c039fdeu: goto P_0c039fde;
case 0x0c039fe0u: goto P_0c039fe0;
case 0x0c039fe2u: goto P_0c039fe2;
case 0x0c039fe4u: goto P_0c039fe4;
case 0x0c039fe6u: goto P_0c039fe6;
case 0x0c039fe8u: goto P_0c039fe8;
case 0x0c039feau: goto P_0c039fea;
case 0x0c039fecu: goto P_0c039fec;
case 0x0c039feeu: goto P_0c039fee;
case 0x0c039ff0u: goto P_0c039ff0;
case 0x0c039ff2u: goto P_0c039ff2;
case 0x0c039ff4u: goto P_0c039ff4;
case 0x0c039ff6u: goto P_0c039ff6;
case 0x0c039ff8u: goto P_0c039ff8;
case 0x0c039ffau: goto P_0c039ffa;
case 0x0c039ffcu: goto P_0c039ffc;
case 0x0c039ffeu: goto P_0c039ffe;
case 0x0c03a000u: goto P_0c03a000;
case 0x0c03a002u: goto P_0c03a002;
case 0x0c03a004u: goto P_0c03a004;
case 0x0c03a006u: goto P_0c03a006;
case 0x0c03a008u: goto P_0c03a008;
case 0x0c03a00au: goto P_0c03a00a;
case 0x0c03a00cu: goto P_0c03a00c;
case 0x0c03a00eu: goto P_0c03a00e;
case 0x0c03a010u: goto P_0c03a010;
case 0x0c03a012u: goto P_0c03a012;
case 0x0c03a014u: goto P_0c03a014;
case 0x0c03a016u: goto P_0c03a016;
case 0x0c03a018u: goto P_0c03a018;
case 0x0c03a01au: goto P_0c03a01a;
case 0x0c03a01cu: goto P_0c03a01c;
case 0x0c03a01eu: goto P_0c03a01e;
case 0x0c03a020u: goto P_0c03a020;
case 0x0c03a022u: goto P_0c03a022;
case 0x0c03a024u: goto P_0c03a024;
case 0x0c03a026u: goto P_0c03a026;
case 0x0c03a028u: goto P_0c03a028;
case 0x0c03a02au: goto P_0c03a02a;
case 0x0c03a02cu: goto P_0c03a02c;
case 0x0c03a02eu: goto P_0c03a02e;
case 0x0c03a030u: goto P_0c03a030;
case 0x0c03a032u: goto P_0c03a032;
case 0x0c03a034u: goto P_0c03a034;
case 0x0c03a040u: goto P_0c03a040;
case 0x0c03a042u: goto P_0c03a042;
case 0x0c03a044u: goto P_0c03a044;
case 0x0c03a046u: goto P_0c03a046;
case 0x0c03a048u: goto P_0c03a048;
case 0x0c03a04au: goto P_0c03a04a;
case 0x0c03a04cu: goto P_0c03a04c;
case 0x0c03a04eu: goto P_0c03a04e;
case 0x0c03a050u: goto P_0c03a050;
case 0x0c03a052u: goto P_0c03a052;
case 0x0c03a054u: goto P_0c03a054;
case 0x0c03a140u: goto P_0c03a140;
case 0x0c03a142u: goto P_0c03a142;
case 0x0c03a144u: goto P_0c03a144;
case 0x0c03a146u: goto P_0c03a146;
case 0x0c03a148u: goto P_0c03a148;
case 0x0c03a14au: goto P_0c03a14a;
case 0x0c03a14cu: goto P_0c03a14c;
case 0x0c03a14eu: goto P_0c03a14e;
case 0x0c03a150u: goto P_0c03a150;
case 0x0c03a152u: goto P_0c03a152;
case 0x0c03a154u: goto P_0c03a154;
case 0x0c03a156u: goto P_0c03a156;
case 0x0c03a6e0u: goto P_0c03a6e0;
case 0x0c03a6e2u: goto P_0c03a6e2;
case 0x0c03a6e4u: goto P_0c03a6e4;
case 0x0c03a6e6u: goto P_0c03a6e6;
case 0x0c03a6e8u: goto P_0c03a6e8;
case 0x0c03a6eau: goto P_0c03a6ea;
case 0x0c03a6ecu: goto P_0c03a6ec;
case 0x0c03a6eeu: goto P_0c03a6ee;
case 0x0c03a6f0u: goto P_0c03a6f0;
case 0x0c03a6f2u: goto P_0c03a6f2;
case 0x0c03a6f4u: goto P_0c03a6f4;
case 0x0c03a6f6u: goto P_0c03a6f6;
case 0x0c03a6f8u: goto P_0c03a6f8;
case 0x0c03a6fau: goto P_0c03a6fa;
case 0x0c03a6fcu: goto P_0c03a6fc;
case 0x0c03a6feu: goto P_0c03a6fe;
case 0x0c03a700u: goto P_0c03a700;
case 0x0c03a702u: goto P_0c03a702;
case 0x0c03a704u: goto P_0c03a704;
case 0x0c03a706u: goto P_0c03a706;
case 0x0c03a708u: goto P_0c03a708;
case 0x0c03a70au: goto P_0c03a70a;
case 0x0c03a70cu: goto P_0c03a70c;
case 0x0c03a70eu: goto P_0c03a70e;
case 0x0c03a710u: goto P_0c03a710;
case 0x0c03a712u: goto P_0c03a712;
case 0x0c03a714u: goto P_0c03a714;
case 0x0c03a716u: goto P_0c03a716;
case 0x0c03a718u: goto P_0c03a718;
case 0x0c03a71au: goto P_0c03a71a;
case 0x0c03a71cu: goto P_0c03a71c;
case 0x0c03a71eu: goto P_0c03a71e;
case 0x0c03a720u: goto P_0c03a720;
case 0x0c03a722u: goto P_0c03a722;
case 0x0c03a724u: goto P_0c03a724;
case 0x0c03a726u: goto P_0c03a726;
case 0x0c03a728u: goto P_0c03a728;
case 0x0c03a72au: goto P_0c03a72a;
case 0x0c03a72cu: goto P_0c03a72c;
case 0x0c03a72eu: goto P_0c03a72e;
case 0x0c03a730u: goto P_0c03a730;
case 0x0c03a732u: goto P_0c03a732;
case 0x0c03a734u: goto P_0c03a734;
case 0x0c03a736u: goto P_0c03a736;
case 0x0c03a738u: goto P_0c03a738;
case 0x0c03a73au: goto P_0c03a73a;
case 0x0c03a73cu: goto P_0c03a73c;
case 0x0c03a73eu: goto P_0c03a73e;
case 0x0c03a740u: goto P_0c03a740;
case 0x0c03a742u: goto P_0c03a742;
case 0x0c03a744u: goto P_0c03a744;
case 0x0c03a746u: goto P_0c03a746;
case 0x0c03a748u: goto P_0c03a748;
case 0x0c03a74au: goto P_0c03a74a;
case 0x0c03a750u: goto P_0c03a750;
case 0x0c03a752u: goto P_0c03a752;
case 0x0c03a754u: goto P_0c03a754;
case 0x0c03a756u: goto P_0c03a756;
case 0x0c03a950u: goto P_0c03a950;
case 0x0c03a952u: goto P_0c03a952;
case 0x0c03a954u: goto P_0c03a954;
case 0x0c03a956u: goto P_0c03a956;
case 0x0c03a958u: goto P_0c03a958;
case 0x0c03a95au: goto P_0c03a95a;
case 0x0c03a95cu: goto P_0c03a95c;
case 0x0c03a95eu: goto P_0c03a95e;
case 0x0c03a960u: goto P_0c03a960;
case 0x0c03a962u: goto P_0c03a962;
case 0x0c03a964u: goto P_0c03a964;
case 0x0c03a966u: goto P_0c03a966;
case 0x0c03a968u: goto P_0c03a968;
case 0x0c03a96au: goto P_0c03a96a;
case 0x0c03a96cu: goto P_0c03a96c;
case 0x0c03a96eu: goto P_0c03a96e;
case 0x0c03a970u: goto P_0c03a970;
case 0x0c03a972u: goto P_0c03a972;
case 0x0c03a974u: goto P_0c03a974;
case 0x0c03a976u: goto P_0c03a976;
case 0x0c03a978u: goto P_0c03a978;
case 0x0c03a97au: goto P_0c03a97a;
case 0x0c03a97cu: goto P_0c03a97c;
case 0x0c03a97eu: goto P_0c03a97e;
case 0x0c03a980u: goto P_0c03a980;
case 0x0c03a982u: goto P_0c03a982;
case 0x0c03a984u: goto P_0c03a984;
case 0x0c03a986u: goto P_0c03a986;
case 0x0c03a988u: goto P_0c03a988;
case 0x0c03a98au: goto P_0c03a98a;
case 0x0c03a98cu: goto P_0c03a98c;
case 0x0c03a98eu: goto P_0c03a98e;
case 0x0c03a990u: goto P_0c03a990;
case 0x0c03a992u: goto P_0c03a992;
case 0x0c03a994u: goto P_0c03a994;
case 0x0c03a9a0u: goto P_0c03a9a0;
case 0x0c03a9a2u: goto P_0c03a9a2;
case 0x0c03a9a4u: goto P_0c03a9a4;
case 0x0c03a9a6u: goto P_0c03a9a6;
case 0x0c03a9a8u: goto P_0c03a9a8;
case 0x0c03a9aau: goto P_0c03a9aa;
case 0x0c03a9acu: goto P_0c03a9ac;
case 0x0c03a9aeu: goto P_0c03a9ae;
case 0x0c03a9b0u: goto P_0c03a9b0;
case 0x0c03a9b2u: goto P_0c03a9b2;
case 0x0c03a9b4u: goto P_0c03a9b4;
case 0x0c03a9b6u: goto P_0c03a9b6;
case 0x0c03a9b8u: goto P_0c03a9b8;
case 0x0c03a9bau: goto P_0c03a9ba;
case 0x0c03a9bcu: goto P_0c03a9bc;
case 0x0c03a9beu: goto P_0c03a9be;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0396c0: /* original 2fd6, guest PC 0x0c0396c0 */
if(!s->budget--) { s->failed_pc=0x0c0396c0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0396c2;
P_0c0396c2: /* original 4408, guest PC 0x0c0396c2 */
if(!s->budget--) { s->failed_pc=0x0c0396c2u; return 0; }
r[4]<<=2;
goto P_0c0396c4;
P_0c0396c4: /* original 7ffc, guest PC 0x0c0396c4 */
if(!s->budget--) { s->failed_pc=0x0c0396c4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0396c6;
P_0c0396c6: /* original 2f42, guest PC 0x0c0396c6 */
if(!s->budget--) { s->failed_pc=0x0c0396c6u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0396c8;
P_0c0396c8: /* original d35e, guest PC 0x0c0396c8 */
if(!s->budget--) { s->failed_pc=0x0c0396c8u; return 0; }
r[3]=read(ram,0x0c039844u,4);
goto P_0c0396ca;
P_0c0396ca: /* original d15f, guest PC 0x0c0396ca */
if(!s->budget--) { s->failed_pc=0x0c0396cau; return 0; }
r[1]=read(ram,0x0c039848u,4);
goto P_0c0396cc;
P_0c0396cc: /* original 6032, guest PC 0x0c0396cc */
if(!s->budget--) { s->failed_pc=0x0c0396ccu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0396ce;
P_0c0396ce: /* original 044e, guest PC 0x0c0396ce */
if(!s->budget--) { s->failed_pc=0x0c0396ceu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c0396d0;
P_0c0396d0: /* original 6243, guest PC 0x0c0396d0 */
if(!s->budget--) { s->failed_pc=0x0c0396d0u; return 0; }
r[2]=r[4];
goto P_0c0396d2;
P_0c0396d2: /* original 4229, guest PC 0x0c0396d2 */
if(!s->budget--) { s->failed_pc=0x0c0396d2u; return 0; }
r[2]>>=16;
goto P_0c0396d4;
P_0c0396d4: /* original 4219, guest PC 0x0c0396d4 */
if(!s->budget--) { s->failed_pc=0x0c0396d4u; return 0; }
r[2]>>=8;
goto P_0c0396d6;
P_0c0396d6: /* original 2122, guest PC 0x0c0396d6 */
if(!s->budget--) { s->failed_pc=0x0c0396d6u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c0396d8;
P_0c0396d8: /* original e100, guest PC 0x0c0396d8 */
if(!s->budget--) { s->failed_pc=0x0c0396d8u; return 0; }
r[1]=0x00000000u;
goto P_0c0396da;
P_0c0396da: /* original d35c, guest PC 0x0c0396da */
if(!s->budget--) { s->failed_pc=0x0c0396dau; return 0; }
r[3]=read(ram,0x0c03984cu,4);
goto P_0c0396dc;
P_0c0396dc: /* original 2322, guest PC 0x0c0396dc */
if(!s->budget--) { s->failed_pc=0x0c0396dcu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0396de;
P_0c0396de: /* original d75c, guest PC 0x0c0396de */
if(!s->budget--) { s->failed_pc=0x0c0396deu; return 0; }
r[7]=read(ram,0x0c039850u,4);
goto P_0c0396e0;
P_0c0396e0: /* original d25c, guest PC 0x0c0396e0 */
if(!s->budget--) { s->failed_pc=0x0c0396e0u; return 0; }
r[2]=read(ram,0x0c039854u,4);
goto P_0c0396e2;
P_0c0396e2: /* original 2749, guest PC 0x0c0396e2 */
if(!s->budget--) { s->failed_pc=0x0c0396e2u; return 0; }
r[7]&=r[4];
goto P_0c0396e4;
P_0c0396e4: /* original 272b, guest PC 0x0c0396e4 */
if(!s->budget--) { s->failed_pc=0x0c0396e4u; return 0; }
r[7]|=r[2];
goto P_0c0396e6;
P_0c0396e6: /* original 6d73, guest PC 0x0c0396e6 */
if(!s->budget--) { s->failed_pc=0x0c0396e6u; return 0; }
r[13]=r[7];
goto P_0c0396e8;
P_0c0396e8: /* original a013, guest PC 0x0c0396e8 */
if(!s->budget--) { s->failed_pc=0x0c0396e8u; return 0; }
r[0]=0x00000008u;
goto P_0c039712;
P_0c0396ea: /* original e008, guest PC 0x0c0396ea */
if(!s->budget--) { s->failed_pc=0x0c0396eau; return 0; }
r[0]=0x00000008u;
if(!vf3_matrix_family(0x0c0396ecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0396ecu; return 0; } return 1;
P_0c0396f0: /* original a00a, guest PC 0x0c0396f0 */
if(!s->budget--) { s->failed_pc=0x0c0396f0u; return 0; }
r[4]=r[0];
goto P_0c039708;
P_0c0396f2: /* original 6403, guest PC 0x0c0396f2 */
if(!s->budget--) { s->failed_pc=0x0c0396f2u; return 0; }
r[4]=r[0];
if(!vf3_matrix_family(0x0c0396f4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0396f4u; return 0; } return 1;
P_0c039700: /* original 6256, guest PC 0x0c039700 */
if(!s->budget--) { s->failed_pc=0x0c039700u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[2]=tmp;
goto P_0c039702;
P_0c039702: /* original 74ff, guest PC 0x0c039702 */
if(!s->budget--) { s->failed_pc=0x0c039702u; return 0; }
r[4]+=0xffffffffu;
goto P_0c039704;
P_0c039704: /* original 2d22, guest PC 0x0c039704 */
if(!s->budget--) { s->failed_pc=0x0c039704u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c039706;
P_0c039706: /* original 7d04, guest PC 0x0c039706 */
if(!s->budget--) { s->failed_pc=0x0c039706u; return 0; }
r[13]+=0x00000004u;
goto P_0c039708;
P_0c039708: /* original 2448, guest PC 0x0c039708 */
if(!s->budget--) { s->failed_pc=0x0c039708u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03970a;
P_0c03970a: /* original 8bf9, guest PC 0x0c03970a */
if(!s->budget--) { s->failed_pc=0x0c03970au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c039700; }
goto P_0c03970c;
P_0c03970c: /* original 0783, guest PC 0x0c03970c */
if(!s->budget--) { s->failed_pc=0x0c03970cu; return 0; }
if((r[7]&0xFC000000u)==0xE0000000u) pref(ram,r[7]);
goto P_0c03970e;
P_0c03970e: /* original 7101, guest PC 0x0c03970e */
if(!s->budget--) { s->failed_pc=0x0c03970eu; return 0; }
r[1]+=0x00000001u;
goto P_0c039710;
P_0c039710: /* original 7720, guest PC 0x0c039710 */
if(!s->budget--) { s->failed_pc=0x0c039710u; return 0; }
r[7]+=0x00000020u;
goto P_0c039712;
P_0c039712: /* original 3163, guest PC 0x0c039712 */
if(!s->budget--) { s->failed_pc=0x0c039712u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[6])!=0);
goto P_0c039714;
P_0c039714: /* original 8bec, guest PC 0x0c039714 */
if(!s->budget--) { s->failed_pc=0x0c039714u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0396f0; }
goto P_0c039716;
P_0c039716: /* original d24b, guest PC 0x0c039716 */
if(!s->budget--) { s->failed_pc=0x0c039716u; return 0; }
r[2]=read(ram,0x0c039844u,4);
goto P_0c039718;
P_0c039718: /* original 64f2, guest PC 0x0c039718 */
if(!s->budget--) { s->failed_pc=0x0c039718u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c03971a;
P_0c03971a: /* original 7f04, guest PC 0x0c03971a */
if(!s->budget--) { s->failed_pc=0x0c03971au; return 0; }
r[15]+=0x00000004u;
goto P_0c03971c;
P_0c03971c: /* original 6322, guest PC 0x0c03971c */
if(!s->budget--) { s->failed_pc=0x0c03971cu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03971e;
P_0c03971e: /* original d14e, guest PC 0x0c03971e */
if(!s->budget--) { s->failed_pc=0x0c03971eu; return 0; }
r[1]=read(ram,0x0c039858u,4);
goto P_0c039720;
P_0c039720: /* original 343c, guest PC 0x0c039720 */
if(!s->budget--) { s->failed_pc=0x0c039720u; return 0; }
r[4]+=r[3];
goto P_0c039722;
P_0c039722: /* original d34b, guest PC 0x0c039722 */
if(!s->budget--) { s->failed_pc=0x0c039722u; return 0; }
r[3]=read(ram,0x0c039850u,4);
goto P_0c039724;
P_0c039724: /* original 6042, guest PC 0x0c039724 */
if(!s->budget--) { s->failed_pc=0x0c039724u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c039726;
P_0c039726: /* original 2739, guest PC 0x0c039726 */
if(!s->budget--) { s->failed_pc=0x0c039726u; return 0; }
r[7]&=r[3];
goto P_0c039728;
P_0c039728: /* original 2019, guest PC 0x0c039728 */
if(!s->budget--) { s->failed_pc=0x0c039728u; return 0; }
r[0]&=r[1];
goto P_0c03972a;
P_0c03972a: /* original 207b, guest PC 0x0c03972a */
if(!s->budget--) { s->failed_pc=0x0c03972au; return 0; }
r[0]|=r[7];
goto P_0c03972c;
P_0c03972c: /* original 2402, guest PC 0x0c03972c */
if(!s->budget--) { s->failed_pc=0x0c03972cu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c03972e;
P_0c03972e: /* original 000b, guest PC 0x0c03972e */
if(!s->budget--) { s->failed_pc=0x0c03972eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c039730: /* original 6df6, guest PC 0x0c039730 */
if(!s->budget--) { s->failed_pc=0x0c039730u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
if(!vf3_matrix_family(0x0c039732u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c039732u; return 0; } return 1;
P_0c039fd0: /* original f34c, guest PC 0x0c039fd0 */
if(!s->budget--) { s->failed_pc=0x0c039fd0u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c039fd2;
P_0c039fd2: /* original f35d, guest PC 0x0c039fd2 */
if(!s->budget--) { s->failed_pc=0x0c039fd2u; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c039fd4;
P_0c039fd4: /* original f69d, guest PC 0x0c039fd4 */
if(!s->budget--) { s->failed_pc=0x0c039fd4u; return 0; }
fr[6]=0x3f800000u;
goto P_0c039fd6;
P_0c039fd6: /* original f365, guest PC 0x0c039fd6 */
if(!s->budget--) { s->failed_pc=0x0c039fd6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c039fd8;
P_0c039fd8: /* original 8d02, guest PC 0x0c039fd8 */
if(!s->budget--) { s->failed_pc=0x0c039fd8u; return 0; }
cond=r[17]&1u;
fr[7]=0;
if(cond) { goto P_0c039fe0; }
goto P_0c039fdc;
P_0c039fda: /* original f78d, guest PC 0x0c039fda */
if(!s->budget--) { s->failed_pc=0x0c039fdau; return 0; }
fr[7]=0;
goto P_0c039fdc;
P_0c039fdc: /* original a002, guest PC 0x0c039fdc */
if(!s->budget--) { s->failed_pc=0x0c039fdcu; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c039fe4;
P_0c039fde: /* original f54c, guest PC 0x0c039fde */
if(!s->budget--) { s->failed_pc=0x0c039fdeu; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c039fe0;
P_0c039fe0: /* original f56c, guest PC 0x0c039fe0 */
if(!s->budget--) { s->failed_pc=0x0c039fe0u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c039fe2;
P_0c039fe2: /* original f543, guest PC 0x0c039fe2 */
if(!s->budget--) { s->failed_pc=0x0c039fe2u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'/');
goto P_0c039fe4;
P_0c039fe4: /* original e40d, guest PC 0x0c039fe4 */
if(!s->budget--) { s->failed_pc=0x0c039fe4u; return 0; }
r[4]=0x0000000du;
goto P_0c039fe6;
P_0c039fe6: /* original e501, guest PC 0x0c039fe6 */
if(!s->budget--) { s->failed_pc=0x0c039fe6u; return 0; }
r[5]=0x00000001u;
goto P_0c039fe8;
P_0c039fe8: /* original 445a, guest PC 0x0c039fe8 */
if(!s->budget--) { s->failed_pc=0x0c039fe8u; return 0; }
r[53]=r[4];
goto P_0c039fea;
P_0c039fea: /* original 6343, guest PC 0x0c039fea */
if(!s->budget--) { s->failed_pc=0x0c039feau; return 0; }
r[3]=r[4];
goto P_0c039fec;
P_0c039fec: /* original 4300, guest PC 0x0c039fec */
if(!s->budget--) { s->failed_pc=0x0c039fecu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c039fee;
P_0c039fee: /* original 74ff, guest PC 0x0c039fee */
if(!s->budget--) { s->failed_pc=0x0c039feeu; return 0; }
r[4]+=0xffffffffu;
goto P_0c039ff0;
P_0c039ff0: /* original f32d, guest PC 0x0c039ff0 */
if(!s->budget--) { s->failed_pc=0x0c039ff0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c039ff2;
P_0c039ff2: /* original 435a, guest PC 0x0c039ff2 */
if(!s->budget--) { s->failed_pc=0x0c039ff2u; return 0; }
r[53]=r[3];
goto P_0c039ff4;
P_0c039ff4: /* original 3453, guest PC 0x0c039ff4 */
if(!s->budget--) { s->failed_pc=0x0c039ff4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c039ff6;
P_0c039ff6: /* original f22d, guest PC 0x0c039ff6 */
if(!s->budget--) { s->failed_pc=0x0c039ff6u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c039ff8;
P_0c039ff8: /* original f83c, guest PC 0x0c039ff8 */
if(!s->budget--) { s->failed_pc=0x0c039ff8u; return 0; }
vf3_matrix_move(s,8,3);
goto P_0c039ffa;
P_0c039ffa: /* original f382, guest PC 0x0c039ffa */
if(!s->budget--) { s->failed_pc=0x0c039ffau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c039ffc;
P_0c039ffc: /* original f270, guest PC 0x0c039ffc */
if(!s->budget--) { s->failed_pc=0x0c039ffcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'+');
goto P_0c039ffe;
P_0c039ffe: /* original f352, guest PC 0x0c039ffe */
if(!s->budget--) { s->failed_pc=0x0c039ffeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a000;
P_0c03a000: /* original f260, guest PC 0x0c03a000 */
if(!s->budget--) { s->failed_pc=0x0c03a000u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'+');
goto P_0c03a002;
P_0c03a002: /* original f352, guest PC 0x0c03a002 */
if(!s->budget--) { s->failed_pc=0x0c03a002u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a004;
P_0c03a004: /* original f73c, guest PC 0x0c03a004 */
if(!s->budget--) { s->failed_pc=0x0c03a004u; return 0; }
vf3_matrix_move(s,7,3);
goto P_0c03a006;
P_0c03a006: /* original 8def, guest PC 0x0c03a006 */
if(!s->budget--) { s->failed_pc=0x0c03a006u; return 0; }
cond=r[17]&1u;
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'/');
if(cond) { goto P_0c039fe8; }
goto P_0c03a00a;
P_0c03a008: /* original f723, guest PC 0x0c03a008 */
if(!s->budget--) { s->failed_pc=0x0c03a008u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'/');
goto P_0c03a00a;
P_0c03a00a: /* original f760, guest PC 0x0c03a00a */
if(!s->budget--) { s->failed_pc=0x0c03a00au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'+');
goto P_0c03a00c;
P_0c03a00c: /* original c713, guest PC 0x0c03a00c */
if(!s->budget--) { s->failed_pc=0x0c03a00cu; return 0; }
r[0]=code_base|0x0003a05cu;
goto P_0c03a00e;
P_0c03a00e: /* original f465, guest PC 0x0c03a00e */
if(!s->budget--) { s->failed_pc=0x0c03a00eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c03a010;
P_0c03a010: /* original d315, guest PC 0x0c03a010 */
if(!s->budget--) { s->failed_pc=0x0c03a010u; return 0; }
r[3]=read(ram,0x0c03a068u,4);
goto P_0c03a012;
P_0c03a012: /* original f573, guest PC 0x0c03a012 */
if(!s->budget--) { s->failed_pc=0x0c03a012u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'/');
goto P_0c03a014;
P_0c03a014: /* original f708, guest PC 0x0c03a014 */
if(!s->budget--) { s->failed_pc=0x0c03a014u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c03a016;
P_0c03a016: /* original c712, guest PC 0x0c03a016 */
if(!s->budget--) { s->failed_pc=0x0c03a016u; return 0; }
r[0]=code_base|0x0003a060u;
goto P_0c03a018;
P_0c03a018: /* original f208, guest PC 0x0c03a018 */
if(!s->budget--) { s->failed_pc=0x0c03a018u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a01a;
P_0c03a01a: /* original c712, guest PC 0x0c03a01a */
if(!s->budget--) { s->failed_pc=0x0c03a01au; return 0; }
r[0]=code_base|0x0003a064u;
goto P_0c03a01c;
P_0c03a01c: /* original f108, guest PC 0x0c03a01c */
if(!s->budget--) { s->failed_pc=0x0c03a01cu; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c03a01e;
P_0c03a01e: /* original f35c, guest PC 0x0c03a01e */
if(!s->budget--) { s->failed_pc=0x0c03a01eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c03a020;
P_0c03a020: /* original f370, guest PC 0x0c03a020 */
if(!s->budget--) { s->failed_pc=0x0c03a020u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'+');
goto P_0c03a022;
P_0c03a022: /* original f322, guest PC 0x0c03a022 */
if(!s->budget--) { s->failed_pc=0x0c03a022u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c03a024;
P_0c03a024: /* original f373, guest PC 0x0c03a024 */
if(!s->budget--) { s->failed_pc=0x0c03a024u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'/');
goto P_0c03a026;
P_0c03a026: /* original f310, guest PC 0x0c03a026 */
if(!s->budget--) { s->failed_pc=0x0c03a026u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'+');
goto P_0c03a028;
P_0c03a028: /* original f33d, guest PC 0x0c03a028 */
if(!s->budget--) { s->failed_pc=0x0c03a028u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03a02a;
P_0c03a02a: /* original 045a, guest PC 0x0c03a02a */
if(!s->budget--) { s->failed_pc=0x0c03a02au; return 0; }
r[4]=r[53];
goto P_0c03a02c;
P_0c03a02c: /* original 8f08, guest PC 0x0c03a02c */
if(!s->budget--) { s->failed_pc=0x0c03a02cu; return 0; }
cond=r[17]&1u;
r[4]&=r[3];
if(!cond) { goto P_0c03a040; }
goto P_0c03a030;
P_0c03a02e: /* original 2439, guest PC 0x0c03a02e */
if(!s->budget--) { s->failed_pc=0x0c03a02eu; return 0; }
r[4]&=r[3];
goto P_0c03a030;
P_0c03a030: /* original 9011, guest PC 0x0c03a030 */
if(!s->budget--) { s->failed_pc=0x0c03a030u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a056u,2);
goto P_0c03a032;
P_0c03a032: /* original a00a, guest PC 0x0c03a032 */
if(!s->budget--) { s->failed_pc=0x0c03a032u; return 0; }
goto P_0c03a04a;
P_0c03a034: /* original 0009, guest PC 0x0c03a034 */
if(!s->budget--) { s->failed_pc=0x0c03a034u; return 0; }
if(!vf3_matrix_family(0x0c03a036u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a036u; return 0; } return 1;
P_0c03a040: /* original c70a, guest PC 0x0c03a040 */
if(!s->budget--) { s->failed_pc=0x0c03a040u; return 0; }
r[0]=code_base|0x0003a06cu;
goto P_0c03a042;
P_0c03a042: /* original f308, guest PC 0x0c03a042 */
if(!s->budget--) { s->failed_pc=0x0c03a042u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03a044;
P_0c03a044: /* original f345, guest PC 0x0c03a044 */
if(!s->budget--) { s->failed_pc=0x0c03a044u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c03a046;
P_0c03a046: /* original 8b03, guest PC 0x0c03a046 */
if(!s->budget--) { s->failed_pc=0x0c03a046u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a050; }
goto P_0c03a048;
P_0c03a048: /* original d003, guest PC 0x0c03a048 */
if(!s->budget--) { s->failed_pc=0x0c03a048u; return 0; }
r[0]=read(ram,0x0c03a058u,4);
goto P_0c03a04a;
P_0c03a04a: /* original 3048, guest PC 0x0c03a04a */
if(!s->budget--) { s->failed_pc=0x0c03a04au; return 0; }
r[0]-=r[4];
goto P_0c03a04c;
P_0c03a04c: /* original 000b, guest PC 0x0c03a04c */
if(!s->budget--) { s->failed_pc=0x0c03a04cu; return 0; }
target=r[16];
r[0]=r[0]&65535u;
s->pc=target; return ram->oob==0;
P_0c03a04e: /* original 600d, guest PC 0x0c03a04e */
if(!s->budget--) { s->failed_pc=0x0c03a04eu; return 0; }
r[0]=r[0]&65535u;
goto P_0c03a050;
P_0c03a050: /* original 6043, guest PC 0x0c03a050 */
if(!s->budget--) { s->failed_pc=0x0c03a050u; return 0; }
r[0]=r[4];
goto P_0c03a052;
P_0c03a052: /* original 000b, guest PC 0x0c03a052 */
if(!s->budget--) { s->failed_pc=0x0c03a052u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03a054: /* original 0009, guest PC 0x0c03a054 */
if(!s->budget--) { s->failed_pc=0x0c03a054u; return 0; }
if(!vf3_matrix_family(0x0c03a056u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a056u; return 0; } return 1;
P_0c03a140: /* original 2fe6, guest PC 0x0c03a140 */
if(!s->budget--) { s->failed_pc=0x0c03a140u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03a142;
P_0c03a142: /* original 6e4d, guest PC 0x0c03a142 */
if(!s->budget--) { s->failed_pc=0x0c03a142u; return 0; }
r[14]=r[4]&65535u;
goto P_0c03a144;
P_0c03a144: /* original d337, guest PC 0x0c03a144 */
if(!s->budget--) { s->failed_pc=0x0c03a144u; return 0; }
r[3]=read(ram,0x0c03a224u,4);
goto P_0c03a146;
P_0c03a146: /* original 3e37, guest PC 0x0c03a146 */
if(!s->budget--) { s->failed_pc=0x0c03a146u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[3])!=0);
goto P_0c03a148;
P_0c03a148: /* original 8b02, guest PC 0x0c03a148 */
if(!s->budget--) { s->failed_pc=0x0c03a148u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03a150; }
goto P_0c03a14a;
P_0c03a14a: /* original d137, guest PC 0x0c03a14a */
if(!s->budget--) { s->failed_pc=0x0c03a14au; return 0; }
r[1]=read(ram,0x0c03a228u,4);
goto P_0c03a14c;
P_0c03a14c: /* original 31e8, guest PC 0x0c03a14c */
if(!s->budget--) { s->failed_pc=0x0c03a14cu; return 0; }
r[1]-=r[14];
goto P_0c03a14e;
P_0c03a14e: /* original 6e13, guest PC 0x0c03a14e */
if(!s->budget--) { s->failed_pc=0x0c03a14eu; return 0; }
r[14]=r[1];
goto P_0c03a150;
P_0c03a150: /* original 9466, guest PC 0x0c03a150 */
if(!s->budget--) { s->failed_pc=0x0c03a150u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03a220u,2);
goto P_0c03a152;
P_0c03a152: /* original 34e8, guest PC 0x0c03a152 */
if(!s->budget--) { s->failed_pc=0x0c03a152u; return 0; }
r[4]-=r[14];
goto P_0c03a154;
P_0c03a154: /* original a2c4, guest PC 0x0c03a154 */
if(!s->budget--) { s->failed_pc=0x0c03a154u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c03a6e0;
P_0c03a156: /* original 6ef6, guest PC 0x0c03a156 */
if(!s->budget--) { s->failed_pc=0x0c03a156u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03a158u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a158u; return 0; } return 1;
P_0c03a6e0: /* original 644d, guest PC 0x0c03a6e0 */
if(!s->budget--) { s->failed_pc=0x0c03a6e0u; return 0; }
r[4]=r[4]&65535u;
goto P_0c03a6e2;
P_0c03a6e2: /* original 445a, guest PC 0x0c03a6e2 */
if(!s->budget--) { s->failed_pc=0x0c03a6e2u; return 0; }
r[53]=r[4];
goto P_0c03a6e4;
P_0c03a6e4: /* original c78d, guest PC 0x0c03a6e4 */
if(!s->budget--) { s->failed_pc=0x0c03a6e4u; return 0; }
r[0]=code_base|0x0003a91cu;
goto P_0c03a6e6;
P_0c03a6e6: /* original f708, guest PC 0x0c03a6e6 */
if(!s->budget--) { s->failed_pc=0x0c03a6e6u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c03a6e8;
P_0c03a6e8: /* original c78d, guest PC 0x0c03a6e8 */
if(!s->budget--) { s->failed_pc=0x0c03a6e8u; return 0; }
r[0]=code_base|0x0003a920u;
goto P_0c03a6ea;
P_0c03a6ea: /* original f208, guest PC 0x0c03a6ea */
if(!s->budget--) { s->failed_pc=0x0c03a6eau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a6ec;
P_0c03a6ec: /* original c78d, guest PC 0x0c03a6ec */
if(!s->budget--) { s->failed_pc=0x0c03a6ecu; return 0; }
r[0]=code_base|0x0003a924u;
goto P_0c03a6ee;
P_0c03a6ee: /* original f32d, guest PC 0x0c03a6ee */
if(!s->budget--) { s->failed_pc=0x0c03a6eeu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a6f0;
P_0c03a6f0: /* original f108, guest PC 0x0c03a6f0 */
if(!s->budget--) { s->failed_pc=0x0c03a6f0u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c03a6f2;
P_0c03a6f2: /* original c78d, guest PC 0x0c03a6f2 */
if(!s->budget--) { s->failed_pc=0x0c03a6f2u; return 0; }
r[0]=code_base|0x0003a928u;
goto P_0c03a6f4;
P_0c03a6f4: /* original f508, guest PC 0x0c03a6f4 */
if(!s->budget--) { s->failed_pc=0x0c03a6f4u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03a6f6;
P_0c03a6f6: /* original c78d, guest PC 0x0c03a6f6 */
if(!s->budget--) { s->failed_pc=0x0c03a6f6u; return 0; }
r[0]=code_base|0x0003a92cu;
goto P_0c03a6f8;
P_0c03a6f8: /* original f008, guest PC 0x0c03a6f8 */
if(!s->budget--) { s->failed_pc=0x0c03a6f8u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c03a6fa;
P_0c03a6fa: /* original e40b, guest PC 0x0c03a6fa */
if(!s->budget--) { s->failed_pc=0x0c03a6fau; return 0; }
r[4]=0x0000000bu;
goto P_0c03a6fc;
P_0c03a6fc: /* original e503, guest PC 0x0c03a6fc */
if(!s->budget--) { s->failed_pc=0x0c03a6fcu; return 0; }
r[5]=0x00000003u;
goto P_0c03a6fe;
P_0c03a6fe: /* original f322, guest PC 0x0c03a6fe */
if(!s->budget--) { s->failed_pc=0x0c03a6feu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c03a700;
P_0c03a700: /* original f313, guest PC 0x0c03a700 */
if(!s->budget--) { s->failed_pc=0x0c03a700u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'/');
goto P_0c03a702;
P_0c03a702: /* original f43c, guest PC 0x0c03a702 */
if(!s->budget--) { s->failed_pc=0x0c03a702u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03a704;
P_0c03a704: /* original f473, guest PC 0x0c03a704 */
if(!s->budget--) { s->failed_pc=0x0c03a704u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'/');
goto P_0c03a706;
P_0c03a706: /* original f34c, guest PC 0x0c03a706 */
if(!s->budget--) { s->failed_pc=0x0c03a706u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03a708;
P_0c03a708: /* original f353, guest PC 0x0c03a708 */
if(!s->budget--) { s->failed_pc=0x0c03a708u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'/');
goto P_0c03a70a;
P_0c03a70a: /* original f300, guest PC 0x0c03a70a */
if(!s->budget--) { s->failed_pc=0x0c03a70au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'+');
goto P_0c03a70c;
P_0c03a70c: /* original f33d, guest PC 0x0c03a70c */
if(!s->budget--) { s->failed_pc=0x0c03a70cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03a70e;
P_0c03a70e: /* original 065a, guest PC 0x0c03a70e */
if(!s->budget--) { s->failed_pc=0x0c03a70eu; return 0; }
r[6]=r[53];
goto P_0c03a710;
P_0c03a710: /* original 465a, guest PC 0x0c03a710 */
if(!s->budget--) { s->failed_pc=0x0c03a710u; return 0; }
r[53]=r[6];
goto P_0c03a712;
P_0c03a712: /* original f32d, guest PC 0x0c03a712 */
if(!s->budget--) { s->failed_pc=0x0c03a712u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a714;
P_0c03a714: /* original f352, guest PC 0x0c03a714 */
if(!s->budget--) { s->failed_pc=0x0c03a714u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a716;
P_0c03a716: /* original f58d, guest PC 0x0c03a716 */
if(!s->budget--) { s->failed_pc=0x0c03a716u; return 0; }
fr[5]=0;
goto P_0c03a718;
P_0c03a718: /* original f431, guest PC 0x0c03a718 */
if(!s->budget--) { s->failed_pc=0x0c03a718u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c03a71a;
P_0c03a71a: /* original f64c, guest PC 0x0c03a71a */
if(!s->budget--) { s->failed_pc=0x0c03a71au; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c03a71c;
P_0c03a71c: /* original f642, guest PC 0x0c03a71c */
if(!s->budget--) { s->failed_pc=0x0c03a71cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c03a71e;
P_0c03a71e: /* original 445a, guest PC 0x0c03a71e */
if(!s->budget--) { s->failed_pc=0x0c03a71eu; return 0; }
r[53]=r[4];
goto P_0c03a720;
P_0c03a720: /* original 74fe, guest PC 0x0c03a720 */
if(!s->budget--) { s->failed_pc=0x0c03a720u; return 0; }
r[4]+=0xfffffffeu;
goto P_0c03a722;
P_0c03a722: /* original 3453, guest PC 0x0c03a722 */
if(!s->budget--) { s->failed_pc=0x0c03a722u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c03a724;
P_0c03a724: /* original f22d, guest PC 0x0c03a724 */
if(!s->budget--) { s->failed_pc=0x0c03a724u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a726;
P_0c03a726: /* original f251, guest PC 0x0c03a726 */
if(!s->budget--) { s->failed_pc=0x0c03a726u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c03a728;
P_0c03a728: /* original f56c, guest PC 0x0c03a728 */
if(!s->budget--) { s->failed_pc=0x0c03a728u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c03a72a;
P_0c03a72a: /* original 8df8, guest PC 0x0c03a72a */
if(!s->budget--) { s->failed_pc=0x0c03a72au; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
if(cond) { goto P_0c03a71e; }
goto P_0c03a72e;
P_0c03a72c: /* original f523, guest PC 0x0c03a72c */
if(!s->budget--) { s->failed_pc=0x0c03a72cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
goto P_0c03a72e;
P_0c03a72e: /* original f69d, guest PC 0x0c03a72e */
if(!s->budget--) { s->failed_pc=0x0c03a72eu; return 0; }
fr[6]=0x3f800000u;
goto P_0c03a730;
P_0c03a730: /* original e301, guest PC 0x0c03a730 */
if(!s->budget--) { s->failed_pc=0x0c03a730u; return 0; }
r[3]=0x00000001u;
goto P_0c03a732;
P_0c03a732: /* original f36c, guest PC 0x0c03a732 */
if(!s->budget--) { s->failed_pc=0x0c03a732u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c03a734;
P_0c03a734: /* original f351, guest PC 0x0c03a734 */
if(!s->budget--) { s->failed_pc=0x0c03a734u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c03a736;
P_0c03a736: /* original 2638, guest PC 0x0c03a736 */
if(!s->budget--) { s->failed_pc=0x0c03a736u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c03a738;
P_0c03a738: /* original f433, guest PC 0x0c03a738 */
if(!s->budget--) { s->failed_pc=0x0c03a738u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c03a73a;
P_0c03a73a: /* original f24c, guest PC 0x0c03a73a */
if(!s->budget--) { s->failed_pc=0x0c03a73au; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c03a73c;
P_0c03a73c: /* original f272, guest PC 0x0c03a73c */
if(!s->budget--) { s->failed_pc=0x0c03a73cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c03a73e;
P_0c03a73e: /* original f04c, guest PC 0x0c03a73e */
if(!s->budget--) { s->failed_pc=0x0c03a73eu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a740;
P_0c03a740: /* original f64e, guest PC 0x0c03a740 */
if(!s->budget--) { s->failed_pc=0x0c03a740u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[4],fr[6],r[18]);
goto P_0c03a742;
P_0c03a742: /* original f42c, guest PC 0x0c03a742 */
if(!s->budget--) { s->failed_pc=0x0c03a742u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c03a744;
P_0c03a744: /* original 8f04, guest PC 0x0c03a744 */
if(!s->budget--) { s->failed_pc=0x0c03a744u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
if(!cond) { goto P_0c03a750; }
goto P_0c03a748;
P_0c03a746: /* original f463, guest PC 0x0c03a746 */
if(!s->budget--) { s->failed_pc=0x0c03a746u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
goto P_0c03a748;
P_0c03a748: /* original 000b, guest PC 0x0c03a748 */
if(!s->budget--) { s->failed_pc=0x0c03a748u; return 0; }
target=r[16];
vf3_matrix_move(s,0,4);
s->pc=target; return ram->oob==0;
P_0c03a74a: /* original f04c, guest PC 0x0c03a74a */
if(!s->budget--) { s->failed_pc=0x0c03a74au; return 0; }
vf3_matrix_move(s,0,4);
if(!vf3_matrix_family(0x0c03a74cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a74cu; return 0; } return 1;
P_0c03a750: /* original f04c, guest PC 0x0c03a750 */
if(!s->budget--) { s->failed_pc=0x0c03a750u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c03a752;
P_0c03a752: /* original f04d, guest PC 0x0c03a752 */
if(!s->budget--) { s->failed_pc=0x0c03a752u; return 0; }
fr[0]^=0x80000000u;
goto P_0c03a754;
P_0c03a754: /* original 000b, guest PC 0x0c03a754 */
if(!s->budget--) { s->failed_pc=0x0c03a754u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03a756: /* original 0009, guest PC 0x0c03a756 */
if(!s->budget--) { s->failed_pc=0x0c03a756u; return 0; }
if(!vf3_matrix_family(0x0c03a758u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a758u; return 0; } return 1;
P_0c03a950: /* original 9378, guest PC 0x0c03a950 */
if(!s->budget--) { s->failed_pc=0x0c03a950u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03aa44u,2);
goto P_0c03a952;
P_0c03a952: /* original 644d, guest PC 0x0c03a952 */
if(!s->budget--) { s->failed_pc=0x0c03a952u; return 0; }
r[4]=r[4]&65535u;
goto P_0c03a954;
P_0c03a954: /* original 9277, guest PC 0x0c03a954 */
if(!s->budget--) { s->failed_pc=0x0c03a954u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03aa46u,2);
goto P_0c03a956;
P_0c03a956: /* original 2349, guest PC 0x0c03a956 */
if(!s->budget--) { s->failed_pc=0x0c03a956u; return 0; }
r[3]&=r[4];
goto P_0c03a958;
P_0c03a958: /* original 3320, guest PC 0x0c03a958 */
if(!s->budget--) { s->failed_pc=0x0c03a958u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c03a95a;
P_0c03a95a: /* original 8939, guest PC 0x0c03a95a */
if(!s->budget--) { s->failed_pc=0x0c03a95au; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c03a9d0u,s,ram); }
goto P_0c03a95c;
P_0c03a95c: /* original 644d, guest PC 0x0c03a95c */
if(!s->budget--) { s->failed_pc=0x0c03a95cu; return 0; }
r[4]=r[4]&65535u;
goto P_0c03a95e;
P_0c03a95e: /* original 445a, guest PC 0x0c03a95e */
if(!s->budget--) { s->failed_pc=0x0c03a95eu; return 0; }
r[53]=r[4];
goto P_0c03a960;
P_0c03a960: /* original c739, guest PC 0x0c03a960 */
if(!s->budget--) { s->failed_pc=0x0c03a960u; return 0; }
r[0]=code_base|0x0003aa48u;
goto P_0c03a962;
P_0c03a962: /* original f208, guest PC 0x0c03a962 */
if(!s->budget--) { s->failed_pc=0x0c03a962u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c03a964;
P_0c03a964: /* original c739, guest PC 0x0c03a964 */
if(!s->budget--) { s->failed_pc=0x0c03a964u; return 0; }
r[0]=code_base|0x0003aa4cu;
goto P_0c03a966;
P_0c03a966: /* original f108, guest PC 0x0c03a966 */
if(!s->budget--) { s->failed_pc=0x0c03a966u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c03a968;
P_0c03a968: /* original c739, guest PC 0x0c03a968 */
if(!s->budget--) { s->failed_pc=0x0c03a968u; return 0; }
r[0]=code_base|0x0003aa50u;
goto P_0c03a96a;
P_0c03a96a: /* original f32d, guest PC 0x0c03a96a */
if(!s->budget--) { s->failed_pc=0x0c03a96au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a96c;
P_0c03a96c: /* original f508, guest PC 0x0c03a96c */
if(!s->budget--) { s->failed_pc=0x0c03a96cu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03a96e;
P_0c03a96e: /* original c739, guest PC 0x0c03a96e */
if(!s->budget--) { s->failed_pc=0x0c03a96eu; return 0; }
r[0]=code_base|0x0003aa54u;
goto P_0c03a970;
P_0c03a970: /* original f008, guest PC 0x0c03a970 */
if(!s->budget--) { s->failed_pc=0x0c03a970u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c03a972;
P_0c03a972: /* original e40d, guest PC 0x0c03a972 */
if(!s->budget--) { s->failed_pc=0x0c03a972u; return 0; }
r[4]=0x0000000du;
goto P_0c03a974;
P_0c03a974: /* original f322, guest PC 0x0c03a974 */
if(!s->budget--) { s->failed_pc=0x0c03a974u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c03a976;
P_0c03a976: /* original f43c, guest PC 0x0c03a976 */
if(!s->budget--) { s->failed_pc=0x0c03a976u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03a978;
P_0c03a978: /* original f413, guest PC 0x0c03a978 */
if(!s->budget--) { s->failed_pc=0x0c03a978u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'/');
goto P_0c03a97a;
P_0c03a97a: /* original f34c, guest PC 0x0c03a97a */
if(!s->budget--) { s->failed_pc=0x0c03a97au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c03a97c;
P_0c03a97c: /* original f353, guest PC 0x0c03a97c */
if(!s->budget--) { s->failed_pc=0x0c03a97cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'/');
goto P_0c03a97e;
P_0c03a97e: /* original f300, guest PC 0x0c03a97e */
if(!s->budget--) { s->failed_pc=0x0c03a97eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[0],r[18],'+');
goto P_0c03a980;
P_0c03a980: /* original f33d, guest PC 0x0c03a980 */
if(!s->budget--) { s->failed_pc=0x0c03a980u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c03a982;
P_0c03a982: /* original 065a, guest PC 0x0c03a982 */
if(!s->budget--) { s->failed_pc=0x0c03a982u; return 0; }
r[6]=r[53];
goto P_0c03a984;
P_0c03a984: /* original 465a, guest PC 0x0c03a984 */
if(!s->budget--) { s->failed_pc=0x0c03a984u; return 0; }
r[53]=r[6];
goto P_0c03a986;
P_0c03a986: /* original f32d, guest PC 0x0c03a986 */
if(!s->budget--) { s->failed_pc=0x0c03a986u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a988;
P_0c03a988: /* original f352, guest PC 0x0c03a988 */
if(!s->budget--) { s->failed_pc=0x0c03a988u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c03a98a;
P_0c03a98a: /* original f58d, guest PC 0x0c03a98a */
if(!s->budget--) { s->failed_pc=0x0c03a98au; return 0; }
fr[5]=0;
goto P_0c03a98c;
P_0c03a98c: /* original f431, guest PC 0x0c03a98c */
if(!s->budget--) { s->failed_pc=0x0c03a98cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c03a98e;
P_0c03a98e: /* original f64c, guest PC 0x0c03a98e */
if(!s->budget--) { s->failed_pc=0x0c03a98eu; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c03a990;
P_0c03a990: /* original f642, guest PC 0x0c03a990 */
if(!s->budget--) { s->failed_pc=0x0c03a990u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c03a992;
P_0c03a992: /* original a00b, guest PC 0x0c03a992 */
if(!s->budget--) { s->failed_pc=0x0c03a992u; return 0; }
r[5]=0x00000003u;
goto P_0c03a9ac;
P_0c03a994: /* original e503, guest PC 0x0c03a994 */
if(!s->budget--) { s->failed_pc=0x0c03a994u; return 0; }
r[5]=0x00000003u;
if(!vf3_matrix_family(0x0c03a996u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a996u; return 0; } return 1;
P_0c03a9a0: /* original 445a, guest PC 0x0c03a9a0 */
if(!s->budget--) { s->failed_pc=0x0c03a9a0u; return 0; }
r[53]=r[4];
goto P_0c03a9a2;
P_0c03a9a2: /* original 74fe, guest PC 0x0c03a9a2 */
if(!s->budget--) { s->failed_pc=0x0c03a9a2u; return 0; }
r[4]+=0xfffffffeu;
goto P_0c03a9a4;
P_0c03a9a4: /* original f32d, guest PC 0x0c03a9a4 */
if(!s->budget--) { s->failed_pc=0x0c03a9a4u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03a9a6;
P_0c03a9a6: /* original f351, guest PC 0x0c03a9a6 */
if(!s->budget--) { s->failed_pc=0x0c03a9a6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c03a9a8;
P_0c03a9a8: /* original f56c, guest PC 0x0c03a9a8 */
if(!s->budget--) { s->failed_pc=0x0c03a9a8u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c03a9aa;
P_0c03a9aa: /* original f533, guest PC 0x0c03a9aa */
if(!s->budget--) { s->failed_pc=0x0c03a9aau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'/');
goto P_0c03a9ac;
P_0c03a9ac: /* original 3453, guest PC 0x0c03a9ac */
if(!s->budget--) { s->failed_pc=0x0c03a9acu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c03a9ae;
P_0c03a9ae: /* original 89f7, guest PC 0x0c03a9ae */
if(!s->budget--) { s->failed_pc=0x0c03a9aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03a9a0; }
goto P_0c03a9b0;
P_0c03a9b0: /* original f39d, guest PC 0x0c03a9b0 */
if(!s->budget--) { s->failed_pc=0x0c03a9b0u; return 0; }
fr[3]=0x3f800000u;
goto P_0c03a9b2;
P_0c03a9b2: /* original f351, guest PC 0x0c03a9b2 */
if(!s->budget--) { s->failed_pc=0x0c03a9b2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c03a9b4;
P_0c03a9b4: /* original e301, guest PC 0x0c03a9b4 */
if(!s->budget--) { s->failed_pc=0x0c03a9b4u; return 0; }
r[3]=0x00000001u;
goto P_0c03a9b6;
P_0c03a9b6: /* original 2638, guest PC 0x0c03a9b6 */
if(!s->budget--) { s->failed_pc=0x0c03a9b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c03a9b8;
P_0c03a9b8: /* original 8f02, guest PC 0x0c03a9b8 */
if(!s->budget--) { s->failed_pc=0x0c03a9b8u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
if(!cond) { return vf3_matrix_family(0x0c03a9c0u,s,ram); }
goto P_0c03a9bc;
P_0c03a9ba: /* original f433, guest PC 0x0c03a9ba */
if(!s->budget--) { s->failed_pc=0x0c03a9bau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c03a9bc;
P_0c03a9bc: /* original 000b, guest PC 0x0c03a9bc */
if(!s->budget--) { s->failed_pc=0x0c03a9bcu; return 0; }
target=r[16];
vf3_matrix_move(s,0,4);
s->pc=target; return ram->oob==0;
P_0c03a9be: /* original f04c, guest PC 0x0c03a9be */
if(!s->budget--) { s->failed_pc=0x0c03a9beu; return 0; }
vf3_matrix_move(s,0,4);
return vf3_matrix_family(0x0c03a9c0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
