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
int vf3_fifth_leaf_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0352dcu: goto P_0c0352dc;
case 0x0c0352deu: goto P_0c0352de;
case 0x0c0352e0u: goto P_0c0352e0;
case 0x0c0352e2u: goto P_0c0352e2;
case 0x0c0352e4u: goto P_0c0352e4;
case 0x0c0352e6u: goto P_0c0352e6;
case 0x0c0352e8u: goto P_0c0352e8;
case 0x0c0352eau: goto P_0c0352ea;
case 0x0c0352ecu: goto P_0c0352ec;
case 0x0c0352eeu: goto P_0c0352ee;
case 0x0c0352f0u: goto P_0c0352f0;
case 0x0c0352f2u: goto P_0c0352f2;
case 0x0c0352f4u: goto P_0c0352f4;
case 0x0c0352f6u: goto P_0c0352f6;
case 0x0c0352f8u: goto P_0c0352f8;
case 0x0c0352fau: goto P_0c0352fa;
case 0x0c0352fcu: goto P_0c0352fc;
case 0x0c0352feu: goto P_0c0352fe;
case 0x0c035300u: goto P_0c035300;
case 0x0c036594u: goto P_0c036594;
case 0x0c036596u: goto P_0c036596;
case 0x0c036598u: goto P_0c036598;
case 0x0c03659au: goto P_0c03659a;
case 0x0c03659cu: goto P_0c03659c;
case 0x0c03659eu: goto P_0c03659e;
case 0x0c0365a0u: goto P_0c0365a0;
case 0x0c0365a2u: goto P_0c0365a2;
case 0x0c0365a4u: goto P_0c0365a4;
case 0x0c0365a6u: goto P_0c0365a6;
case 0x0c0365a8u: goto P_0c0365a8;
case 0x0c0365aau: goto P_0c0365aa;
case 0x0c0365acu: goto P_0c0365ac;
case 0x0c0365aeu: goto P_0c0365ae;
case 0x0c0365b0u: goto P_0c0365b0;
case 0x0c0365b2u: goto P_0c0365b2;
case 0x0c0365b4u: goto P_0c0365b4;
case 0x0c0365b6u: goto P_0c0365b6;
case 0x0c0365b8u: goto P_0c0365b8;
case 0x0c0365bau: goto P_0c0365ba;
case 0x0c0365bcu: goto P_0c0365bc;
case 0x0c0365beu: goto P_0c0365be;
case 0x0c0365c0u: goto P_0c0365c0;
case 0x0c0365c2u: goto P_0c0365c2;
case 0x0c0365c4u: goto P_0c0365c4;
case 0x0c0365c6u: goto P_0c0365c6;
case 0x0c0365c8u: goto P_0c0365c8;
case 0x0c0365cau: goto P_0c0365ca;
case 0x0c0365ccu: goto P_0c0365cc;
case 0x0c0365ceu: goto P_0c0365ce;
case 0x0c0365d0u: goto P_0c0365d0;
case 0x0c0365d2u: goto P_0c0365d2;
case 0x0c03c092u: goto P_0c03c092;
case 0x0c03c094u: goto P_0c03c094;
case 0x0c03c096u: goto P_0c03c096;
case 0x0c03c098u: goto P_0c03c098;
case 0x0c03c09au: goto P_0c03c09a;
case 0x0c03c09cu: goto P_0c03c09c;
case 0x0c03c09eu: goto P_0c03c09e;
case 0x0c03c0a0u: goto P_0c03c0a0;
case 0x0c03c0a2u: goto P_0c03c0a2;
case 0x0c03c0a4u: goto P_0c03c0a4;
case 0x0c03c0a6u: goto P_0c03c0a6;
case 0x0c03c0a8u: goto P_0c03c0a8;
case 0x0c03c0aau: goto P_0c03c0aa;
case 0x0c03c0acu: goto P_0c03c0ac;
case 0x0c03c0aeu: goto P_0c03c0ae;
case 0x0c03c0b0u: goto P_0c03c0b0;
case 0x0c03c0b2u: goto P_0c03c0b2;
case 0x0c03c0b4u: goto P_0c03c0b4;
case 0x0c03c0b6u: goto P_0c03c0b6;
case 0x0c03c0b8u: goto P_0c03c0b8;
case 0x0c03c0bau: goto P_0c03c0ba;
case 0x0c03c0bcu: goto P_0c03c0bc;
case 0x0c03c0beu: goto P_0c03c0be;
case 0x0c03c0c0u: goto P_0c03c0c0;
case 0x0c03c0c2u: goto P_0c03c0c2;
case 0x0c03c0c4u: goto P_0c03c0c4;
case 0x0c03c0c6u: goto P_0c03c0c6;
case 0x0c03c0c8u: goto P_0c03c0c8;
case 0x0c03c0cau: goto P_0c03c0ca;
case 0x0c03c0ccu: goto P_0c03c0cc;
case 0x0c03c0ceu: goto P_0c03c0ce;
case 0x0c03c0d0u: goto P_0c03c0d0;
case 0x0c03c0d2u: goto P_0c03c0d2;
case 0x0c03c0d4u: goto P_0c03c0d4;
case 0x0c03c0d6u: goto P_0c03c0d6;
case 0x0c03c0d8u: goto P_0c03c0d8;
case 0x0c03c0dau: goto P_0c03c0da;
case 0x0c03c0dcu: goto P_0c03c0dc;
case 0x0c03c0deu: goto P_0c03c0de;
case 0x0c03c51au: goto P_0c03c51a;
case 0x0c03c51cu: goto P_0c03c51c;
case 0x0c03c51eu: goto P_0c03c51e;
case 0x0c03c520u: goto P_0c03c520;
case 0x0c03c522u: goto P_0c03c522;
case 0x0c03c524u: goto P_0c03c524;
case 0x0c03c526u: goto P_0c03c526;
case 0x0c03c528u: goto P_0c03c528;
case 0x0c03c52au: goto P_0c03c52a;
case 0x0c03c530u: goto P_0c03c530;
case 0x0c03c532u: goto P_0c03c532;
case 0x0c03c534u: goto P_0c03c534;
case 0x0c03c536u: goto P_0c03c536;
case 0x0c03c538u: goto P_0c03c538;
case 0x0c03c53au: goto P_0c03c53a;
case 0x0c03c53cu: goto P_0c03c53c;
case 0x0c03c53eu: goto P_0c03c53e;
case 0x0c03c540u: goto P_0c03c540;
case 0x0c03c542u: goto P_0c03c542;
case 0x0c03c544u: goto P_0c03c544;
case 0x0c03c546u: goto P_0c03c546;
case 0x0c03c548u: goto P_0c03c548;
case 0x0c03c54au: goto P_0c03c54a;
case 0x0c03c54cu: goto P_0c03c54c;
case 0x0c03c54eu: goto P_0c03c54e;
case 0x0c03c550u: goto P_0c03c550;
case 0x0c03c552u: goto P_0c03c552;
case 0x0c03c554u: goto P_0c03c554;
case 0x0c03c556u: goto P_0c03c556;
case 0x0c03c558u: goto P_0c03c558;
case 0x0c03c55au: goto P_0c03c55a;
case 0x0c03c55cu: goto P_0c03c55c;
case 0x0c03c55eu: goto P_0c03c55e;
case 0x0c03c560u: goto P_0c03c560;
case 0x0c03c562u: goto P_0c03c562;
case 0x0c03c564u: goto P_0c03c564;
case 0x0c03c566u: goto P_0c03c566;
case 0x0c03c568u: goto P_0c03c568;
case 0x0c03c56au: goto P_0c03c56a;
case 0x0c03c56cu: goto P_0c03c56c;
case 0x0c03c56eu: goto P_0c03c56e;
case 0x0c03c570u: goto P_0c03c570;
case 0x0c03c572u: goto P_0c03c572;
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
case 0x0c03e980u: goto P_0c03e980;
case 0x0c03e982u: goto P_0c03e982;
case 0x0c03e984u: goto P_0c03e984;
case 0x0c03e986u: goto P_0c03e986;
case 0x0c03e988u: goto P_0c03e988;
case 0x0c03e98au: goto P_0c03e98a;
case 0x0c03e98cu: goto P_0c03e98c;
case 0x0c03e98eu: goto P_0c03e98e;
case 0x0c03e990u: goto P_0c03e990;
case 0x0c03e992u: goto P_0c03e992;
case 0x0c03e994u: goto P_0c03e994;
case 0x0c03e996u: goto P_0c03e996;
case 0x0c03e998u: goto P_0c03e998;
case 0x0c03e99au: goto P_0c03e99a;
case 0x0c03e99cu: goto P_0c03e99c;
case 0x0c03e99eu: goto P_0c03e99e;
case 0x0c03e9a0u: goto P_0c03e9a0;
case 0x0c03e9a2u: goto P_0c03e9a2;
case 0x0c03e9a4u: goto P_0c03e9a4;
case 0x0c03e9a6u: goto P_0c03e9a6;
case 0x0c03e9a8u: goto P_0c03e9a8;
case 0x0c03e9aau: goto P_0c03e9aa;
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
case 0x0c03eff4u: goto P_0c03eff4;
case 0x0c03eff6u: goto P_0c03eff6;
case 0x0c03eff8u: goto P_0c03eff8;
case 0x0c03effau: goto P_0c03effa;
case 0x0c03effcu: goto P_0c03effc;
case 0x0c03effeu: goto P_0c03effe;
case 0x0c03f000u: goto P_0c03f000;
case 0x0c03f002u: goto P_0c03f002;
case 0x0c03f004u: goto P_0c03f004;
case 0x0c03f006u: goto P_0c03f006;
case 0x0c03f008u: goto P_0c03f008;
case 0x0c03f00au: goto P_0c03f00a;
case 0x0c03f00cu: goto P_0c03f00c;
case 0x0c03f00eu: goto P_0c03f00e;
case 0x0c03f010u: goto P_0c03f010;
case 0x0c03f012u: goto P_0c03f012;
case 0x0c03f014u: goto P_0c03f014;
case 0x0c03f016u: goto P_0c03f016;
case 0x0c03f018u: goto P_0c03f018;
case 0x0c03f01au: goto P_0c03f01a;
case 0x0c03f01cu: goto P_0c03f01c;
case 0x0c03f020u: goto P_0c03f020;
case 0x0c03f022u: goto P_0c03f022;
case 0x0c03f024u: goto P_0c03f024;
case 0x0c03f026u: goto P_0c03f026;
case 0x0c03f028u: goto P_0c03f028;
case 0x0c03f02au: goto P_0c03f02a;
case 0x0c03f02cu: goto P_0c03f02c;
case 0x0c03f02eu: goto P_0c03f02e;
case 0x0c03f030u: goto P_0c03f030;
case 0x0c03f032u: goto P_0c03f032;
case 0x0c03f034u: goto P_0c03f034;
case 0x0c03f036u: goto P_0c03f036;
case 0x0c03ffd0u: goto P_0c03ffd0;
case 0x0c03ffd2u: goto P_0c03ffd2;
case 0x0c03ffd4u: goto P_0c03ffd4;
case 0x0c03ffd6u: goto P_0c03ffd6;
case 0x0c03ffd8u: goto P_0c03ffd8;
case 0x0c03ffdau: goto P_0c03ffda;
case 0x0c03ffdcu: goto P_0c03ffdc;
case 0x0c03ffdeu: goto P_0c03ffde;
case 0x0c03ffe0u: goto P_0c03ffe0;
case 0x0c03ffe2u: goto P_0c03ffe2;
case 0x0c03ffe4u: goto P_0c03ffe4;
case 0x0c040010u: goto P_0c040010;
case 0x0c040012u: goto P_0c040012;
case 0x0c040014u: goto P_0c040014;
case 0x0c040016u: goto P_0c040016;
case 0x0c040018u: goto P_0c040018;
case 0x0c04001au: goto P_0c04001a;
case 0x0c04001cu: goto P_0c04001c;
case 0x0c04001eu: goto P_0c04001e;
case 0x0c040020u: goto P_0c040020;
case 0x0c040022u: goto P_0c040022;
case 0x0c040024u: goto P_0c040024;
case 0x0c040026u: goto P_0c040026;
case 0x0c040028u: goto P_0c040028;
case 0x0c04002au: goto P_0c04002a;
case 0x0c04002cu: goto P_0c04002c;
case 0x0c04002eu: goto P_0c04002e;
case 0x0c040030u: goto P_0c040030;
case 0x0c040032u: goto P_0c040032;
case 0x0c040034u: goto P_0c040034;
case 0x0c040036u: goto P_0c040036;
case 0x0c040038u: goto P_0c040038;
case 0x0c04003au: goto P_0c04003a;
case 0x0c04003cu: goto P_0c04003c;
case 0x0c04003eu: goto P_0c04003e;
case 0x0c040040u: goto P_0c040040;
case 0x0c040042u: goto P_0c040042;
case 0x0c040044u: goto P_0c040044;
case 0x0c040046u: goto P_0c040046;
case 0x0c040048u: goto P_0c040048;
case 0x0c04004au: goto P_0c04004a;
case 0x0c04004cu: goto P_0c04004c;
case 0x0c04004eu: goto P_0c04004e;
case 0x0c040050u: goto P_0c040050;
case 0x0c040052u: goto P_0c040052;
case 0x0c040054u: goto P_0c040054;
case 0x0c040056u: goto P_0c040056;
case 0x0c040058u: goto P_0c040058;
case 0x0c04005au: goto P_0c04005a;
case 0x0c04005cu: goto P_0c04005c;
case 0x0c04005eu: goto P_0c04005e;
case 0x0c040060u: goto P_0c040060;
case 0x0c040062u: goto P_0c040062;
case 0x0c040064u: goto P_0c040064;
case 0x0c040066u: goto P_0c040066;
case 0x0c040068u: goto P_0c040068;
case 0x0c04006au: goto P_0c04006a;
case 0x0c04006cu: goto P_0c04006c;
case 0x0c040070u: goto P_0c040070;
case 0x0c040072u: goto P_0c040072;
case 0x0c040074u: goto P_0c040074;
case 0x0c04396eu: goto P_0c04396e;
case 0x0c043970u: goto P_0c043970;
case 0x0c043972u: goto P_0c043972;
case 0x0c043974u: goto P_0c043974;
case 0x0c043976u: goto P_0c043976;
case 0x0c043978u: goto P_0c043978;
case 0x0c04397au: goto P_0c04397a;
case 0x0c04397cu: goto P_0c04397c;
case 0x0c04397eu: goto P_0c04397e;
case 0x0c043980u: goto P_0c043980;
case 0x0c043982u: goto P_0c043982;
case 0x0c043984u: goto P_0c043984;
case 0x0c043986u: goto P_0c043986;
case 0x0c043988u: goto P_0c043988;
case 0x0c04398au: goto P_0c04398a;
case 0x0c04398cu: goto P_0c04398c;
case 0x0c04398eu: goto P_0c04398e;
case 0x0c043990u: goto P_0c043990;
case 0x0c043992u: goto P_0c043992;
case 0x0c043994u: goto P_0c043994;
case 0x0c043996u: goto P_0c043996;
case 0x0c043998u: goto P_0c043998;
case 0x0c04399au: goto P_0c04399a;
case 0x0c04399cu: goto P_0c04399c;
case 0x0c04399eu: goto P_0c04399e;
case 0x0c0439a0u: goto P_0c0439a0;
case 0x0c0439a2u: goto P_0c0439a2;
case 0x0c0439a4u: goto P_0c0439a4;
case 0x0c0439a6u: goto P_0c0439a6;
case 0x0c0439a8u: goto P_0c0439a8;
case 0x0c0439aau: goto P_0c0439aa;
case 0x0c0439acu: goto P_0c0439ac;
case 0x0c0439aeu: goto P_0c0439ae;
case 0x0c0439b0u: goto P_0c0439b0;
case 0x0c0439b2u: goto P_0c0439b2;
case 0x0c0439b4u: goto P_0c0439b4;
case 0x0c0439b6u: goto P_0c0439b6;
case 0x0c0439b8u: goto P_0c0439b8;
case 0x0c0439c0u: goto P_0c0439c0;
case 0x0c0439c2u: goto P_0c0439c2;
case 0x0c0439c4u: goto P_0c0439c4;
case 0x0c0439c6u: goto P_0c0439c6;
case 0x0c0439c8u: goto P_0c0439c8;
case 0x0c0439cau: goto P_0c0439ca;
case 0x0c0439ccu: goto P_0c0439cc;
case 0x0c0439ceu: goto P_0c0439ce;
case 0x0c0439d0u: goto P_0c0439d0;
case 0x0c0439d2u: goto P_0c0439d2;
case 0x0c0439d4u: goto P_0c0439d4;
case 0x0c0439d6u: goto P_0c0439d6;
case 0x0c0439d8u: goto P_0c0439d8;
case 0x0c0439dau: goto P_0c0439da;
case 0x0c0439dcu: goto P_0c0439dc;
case 0x0c0439deu: goto P_0c0439de;
case 0x0c0439e0u: goto P_0c0439e0;
case 0x0c0439e2u: goto P_0c0439e2;
case 0x0c0439e4u: goto P_0c0439e4;
case 0x0c0439e6u: goto P_0c0439e6;
case 0x0c0439e8u: goto P_0c0439e8;
case 0x0c0439eau: goto P_0c0439ea;
case 0x0c0439ecu: goto P_0c0439ec;
case 0x0c0439eeu: goto P_0c0439ee;
case 0x0c0439f0u: goto P_0c0439f0;
case 0x0c0439f2u: goto P_0c0439f2;
case 0x0c0439f4u: goto P_0c0439f4;
case 0x0c0439f6u: goto P_0c0439f6;
case 0x0c0439f8u: goto P_0c0439f8;
case 0x0c0439fau: goto P_0c0439fa;
case 0x0c0439fcu: goto P_0c0439fc;
case 0x0c0439feu: goto P_0c0439fe;
case 0x0c043a00u: goto P_0c043a00;
case 0x0c043a02u: goto P_0c043a02;
case 0x0c043a04u: goto P_0c043a04;
case 0x0c043a06u: goto P_0c043a06;
case 0x0c043a08u: goto P_0c043a08;
case 0x0c043a0au: goto P_0c043a0a;
case 0x0c043a0cu: goto P_0c043a0c;
case 0x0c0441b6u: goto P_0c0441b6;
case 0x0c0441b8u: goto P_0c0441b8;
case 0x0c0441bau: goto P_0c0441ba;
case 0x0c0441bcu: goto P_0c0441bc;
case 0x0c0441beu: goto P_0c0441be;
case 0x0c0441c0u: goto P_0c0441c0;
case 0x0c0441c2u: goto P_0c0441c2;
case 0x0c0441c4u: goto P_0c0441c4;
case 0x0c0441c6u: goto P_0c0441c6;
case 0x0c0441c8u: goto P_0c0441c8;
case 0x0c0441cau: goto P_0c0441ca;
case 0x0c0441ccu: goto P_0c0441cc;
case 0x0c0441ceu: goto P_0c0441ce;
case 0x0c0441d0u: goto P_0c0441d0;
case 0x0c0441d2u: goto P_0c0441d2;
case 0x0c0441d4u: goto P_0c0441d4;
case 0x0c0441d6u: goto P_0c0441d6;
case 0x0c0441d8u: goto P_0c0441d8;
case 0x0c0441dau: goto P_0c0441da;
case 0x0c0441dcu: goto P_0c0441dc;
case 0x0c0441deu: goto P_0c0441de;
case 0x0c0441e0u: goto P_0c0441e0;
case 0x0c0441e2u: goto P_0c0441e2;
case 0x0c0441e4u: goto P_0c0441e4;
case 0x0c044c7cu: goto P_0c044c7c;
case 0x0c044c7eu: goto P_0c044c7e;
case 0x0c044c80u: goto P_0c044c80;
case 0x0c044c82u: goto P_0c044c82;
case 0x0c044c84u: goto P_0c044c84;
case 0x0c044c86u: goto P_0c044c86;
case 0x0c044c88u: goto P_0c044c88;
case 0x0c044c8au: goto P_0c044c8a;
case 0x0c044c8cu: goto P_0c044c8c;
case 0x0c044c8eu: goto P_0c044c8e;
case 0x0c044c90u: goto P_0c044c90;
case 0x0c044c92u: goto P_0c044c92;
case 0x0c044c94u: goto P_0c044c94;
case 0x0c044c96u: goto P_0c044c96;
case 0x0c044c98u: goto P_0c044c98;
case 0x0c044c9au: goto P_0c044c9a;
case 0x0c044c9cu: goto P_0c044c9c;
case 0x0c044c9eu: goto P_0c044c9e;
case 0x0c044ca0u: goto P_0c044ca0;
case 0x0c044ca2u: goto P_0c044ca2;
case 0x0c044ca4u: goto P_0c044ca4;
case 0x0c044ca6u: goto P_0c044ca6;
case 0x0c044ca8u: goto P_0c044ca8;
case 0x0c044caau: goto P_0c044caa;
case 0x0c044cacu: goto P_0c044cac;
case 0x0c044caeu: goto P_0c044cae;
case 0x0c044cb0u: goto P_0c044cb0;
case 0x0c044cb2u: goto P_0c044cb2;
case 0x0c044cb4u: goto P_0c044cb4;
case 0x0c044cb6u: goto P_0c044cb6;
case 0x0c044cb8u: goto P_0c044cb8;
case 0x0c044cbau: goto P_0c044cba;
case 0x0c044cbcu: goto P_0c044cbc;
case 0x0c044cbeu: goto P_0c044cbe;
case 0x0c044cc0u: goto P_0c044cc0;
case 0x0c044cc2u: goto P_0c044cc2;
case 0x0c044cc4u: goto P_0c044cc4;
case 0x0c044cc6u: goto P_0c044cc6;
case 0x0c044cc8u: goto P_0c044cc8;
case 0x0c044ccau: goto P_0c044cca;
case 0x0c044cccu: goto P_0c044ccc;
case 0x0c044cceu: goto P_0c044cce;
case 0x0c044cd0u: goto P_0c044cd0;
case 0x0c044cd2u: goto P_0c044cd2;
case 0x0c044cd4u: goto P_0c044cd4;
case 0x0c044cd6u: goto P_0c044cd6;
case 0x0c044cd8u: goto P_0c044cd8;
case 0x0c044cdau: goto P_0c044cda;
case 0x0c044cdcu: goto P_0c044cdc;
case 0x0c044cdeu: goto P_0c044cde;
case 0x0c044ce0u: goto P_0c044ce0;
case 0x0c044ce2u: goto P_0c044ce2;
case 0x0c044ce4u: goto P_0c044ce4;
case 0x0c044ce6u: goto P_0c044ce6;
case 0x0c044ce8u: goto P_0c044ce8;
case 0x0c044ceau: goto P_0c044cea;
case 0x0c044cecu: goto P_0c044cec;
case 0x0c044ceeu: goto P_0c044cee;
case 0x0c044cf0u: goto P_0c044cf0;
case 0x0c044cf2u: goto P_0c044cf2;
case 0x0c044cf4u: goto P_0c044cf4;
case 0x0c044cf6u: goto P_0c044cf6;
case 0x0c044cf8u: goto P_0c044cf8;
case 0x0c044cfau: goto P_0c044cfa;
case 0x0c044cfcu: goto P_0c044cfc;
case 0x0c044cfeu: goto P_0c044cfe;
case 0x0c044d00u: goto P_0c044d00;
case 0x0c044d02u: goto P_0c044d02;
case 0x0c044d04u: goto P_0c044d04;
case 0x0c044d06u: goto P_0c044d06;
case 0x0c044d08u: goto P_0c044d08;
case 0x0c044d0au: goto P_0c044d0a;
case 0x0c044d0cu: goto P_0c044d0c;
case 0x0c044d0eu: goto P_0c044d0e;
case 0x0c044d50u: goto P_0c044d50;
case 0x0c044d52u: goto P_0c044d52;
case 0x0c044d54u: goto P_0c044d54;
case 0x0c044d56u: goto P_0c044d56;
case 0x0c044d58u: goto P_0c044d58;
case 0x0c044d5au: goto P_0c044d5a;
case 0x0c044d5cu: goto P_0c044d5c;
case 0x0c044d5eu: goto P_0c044d5e;
case 0x0c044d60u: goto P_0c044d60;
case 0x0c044d62u: goto P_0c044d62;
case 0x0c044d64u: goto P_0c044d64;
case 0x0c044d66u: goto P_0c044d66;
case 0x0c044d68u: goto P_0c044d68;
case 0x0c044d6au: goto P_0c044d6a;
case 0x0c044d6cu: goto P_0c044d6c;
case 0x0c044d6eu: goto P_0c044d6e;
case 0x0c044d70u: goto P_0c044d70;
case 0x0c044d72u: goto P_0c044d72;
case 0x0c044d74u: goto P_0c044d74;
case 0x0c044d76u: goto P_0c044d76;
case 0x0c044d78u: goto P_0c044d78;
case 0x0c044d7au: goto P_0c044d7a;
case 0x0c044d7cu: goto P_0c044d7c;
case 0x0c044d7eu: goto P_0c044d7e;
case 0x0c044d80u: goto P_0c044d80;
case 0x0c044d82u: goto P_0c044d82;
case 0x0c044d84u: goto P_0c044d84;
case 0x0c044d86u: goto P_0c044d86;
case 0x0c044d88u: goto P_0c044d88;
case 0x0c044d8au: goto P_0c044d8a;
case 0x0c044d8cu: goto P_0c044d8c;
case 0x0c044d8eu: goto P_0c044d8e;
case 0x0c044d90u: goto P_0c044d90;
case 0x0c044d92u: goto P_0c044d92;
case 0x0c044d94u: goto P_0c044d94;
case 0x0c044d96u: goto P_0c044d96;
case 0x0c044d98u: goto P_0c044d98;
case 0x0c044d9au: goto P_0c044d9a;
case 0x0c044d9cu: goto P_0c044d9c;
case 0x0c044d9eu: goto P_0c044d9e;
case 0x0c044da0u: goto P_0c044da0;
case 0x0c044da2u: goto P_0c044da2;
case 0x0c044da4u: goto P_0c044da4;
case 0x0c044da6u: goto P_0c044da6;
case 0x0c044da8u: goto P_0c044da8;
case 0x0c044daau: goto P_0c044daa;
case 0x0c044dacu: goto P_0c044dac;
case 0x0c044daeu: goto P_0c044dae;
case 0x0c044db0u: goto P_0c044db0;
case 0x0c044db2u: goto P_0c044db2;
case 0x0c044db4u: goto P_0c044db4;
case 0x0c044db6u: goto P_0c044db6;
case 0x0c044db8u: goto P_0c044db8;
case 0x0c044dbau: goto P_0c044dba;
case 0x0c044dbcu: goto P_0c044dbc;
case 0x0c044dbeu: goto P_0c044dbe;
case 0x0c044dc0u: goto P_0c044dc0;
case 0x0c044dc2u: goto P_0c044dc2;
case 0x0c044dc4u: goto P_0c044dc4;
case 0x0c044dc6u: goto P_0c044dc6;
case 0x0c044dc8u: goto P_0c044dc8;
case 0x0c044dcau: goto P_0c044dca;
case 0x0c044dccu: goto P_0c044dcc;
case 0x0c044dceu: goto P_0c044dce;
case 0x0c044dd0u: goto P_0c044dd0;
case 0x0c044dd2u: goto P_0c044dd2;
case 0x0c044dd4u: goto P_0c044dd4;
case 0x0c044dd6u: goto P_0c044dd6;
case 0x0c044dd8u: goto P_0c044dd8;
case 0x0c044ddau: goto P_0c044dda;
case 0x0c044ddcu: goto P_0c044ddc;
case 0x0c044ddeu: goto P_0c044dde;
case 0x0c044de0u: goto P_0c044de0;
case 0x0c044de2u: goto P_0c044de2;
case 0x0c044de4u: goto P_0c044de4;
case 0x0c044de6u: goto P_0c044de6;
case 0x0c044de8u: goto P_0c044de8;
case 0x0c044deau: goto P_0c044dea;
case 0x0c044decu: goto P_0c044dec;
case 0x0c044deeu: goto P_0c044dee;
case 0x0c044df0u: goto P_0c044df0;
case 0x0c044df2u: goto P_0c044df2;
case 0x0c044df4u: goto P_0c044df4;
case 0x0c044df6u: goto P_0c044df6;
case 0x0c044df8u: goto P_0c044df8;
case 0x0c044dfau: goto P_0c044dfa;
case 0x0c044dfcu: goto P_0c044dfc;
case 0x0c044dfeu: goto P_0c044dfe;
case 0x0c044e00u: goto P_0c044e00;
case 0x0c044e02u: goto P_0c044e02;
case 0x0c044e04u: goto P_0c044e04;
case 0x0c044e06u: goto P_0c044e06;
case 0x0c044e08u: goto P_0c044e08;
case 0x0c044e0au: goto P_0c044e0a;
case 0x0c044e0cu: goto P_0c044e0c;
case 0x0c044e0eu: goto P_0c044e0e;
case 0x0c044e10u: goto P_0c044e10;
case 0x0c044e12u: goto P_0c044e12;
case 0x0c044e14u: goto P_0c044e14;
case 0x0c044e16u: goto P_0c044e16;
case 0x0c044e18u: goto P_0c044e18;
case 0x0c044e1au: goto P_0c044e1a;
case 0x0c044e1cu: goto P_0c044e1c;
case 0x0c044e1eu: goto P_0c044e1e;
case 0x0c044e20u: goto P_0c044e20;
case 0x0c044e22u: goto P_0c044e22;
case 0x0c044e24u: goto P_0c044e24;
case 0x0c044e26u: goto P_0c044e26;
case 0x0c044e28u: goto P_0c044e28;
case 0x0c044e2au: goto P_0c044e2a;
case 0x0c044e2cu: goto P_0c044e2c;
case 0x0c044e2eu: goto P_0c044e2e;
case 0x0c044e30u: goto P_0c044e30;
case 0x0c044e32u: goto P_0c044e32;
case 0x0c044e34u: goto P_0c044e34;
case 0x0c044e36u: goto P_0c044e36;
case 0x0c044e38u: goto P_0c044e38;
case 0x0c044e3au: goto P_0c044e3a;
case 0x0c044e3cu: goto P_0c044e3c;
case 0x0c044e3eu: goto P_0c044e3e;
case 0x0c044e40u: goto P_0c044e40;
case 0x0c044e42u: goto P_0c044e42;
case 0x0c044e44u: goto P_0c044e44;
case 0x0c044e46u: goto P_0c044e46;
case 0x0c044e48u: goto P_0c044e48;
case 0x0c044e6cu: goto P_0c044e6c;
case 0x0c044e6eu: goto P_0c044e6e;
case 0x0c044e70u: goto P_0c044e70;
case 0x0c044e72u: goto P_0c044e72;
case 0x0c044e74u: goto P_0c044e74;
case 0x0c044e76u: goto P_0c044e76;
case 0x0c044e78u: goto P_0c044e78;
case 0x0c044e7au: goto P_0c044e7a;
case 0x0c044e7cu: goto P_0c044e7c;
case 0x0c044e7eu: goto P_0c044e7e;
case 0x0c044e80u: goto P_0c044e80;
case 0x0c044e82u: goto P_0c044e82;
case 0x0c044e84u: goto P_0c044e84;
case 0x0c044e86u: goto P_0c044e86;
case 0x0c044e88u: goto P_0c044e88;
case 0x0c044e8au: goto P_0c044e8a;
case 0x0c044e8cu: goto P_0c044e8c;
case 0x0c044e8eu: goto P_0c044e8e;
case 0x0c044e90u: goto P_0c044e90;
case 0x0c044e92u: goto P_0c044e92;
case 0x0c044e94u: goto P_0c044e94;
case 0x0c044e96u: goto P_0c044e96;
case 0x0c044e98u: goto P_0c044e98;
case 0x0c044e9au: goto P_0c044e9a;
case 0x0c044e9cu: goto P_0c044e9c;
case 0x0c044e9eu: goto P_0c044e9e;
case 0x0c044ea0u: goto P_0c044ea0;
case 0x0c044ea2u: goto P_0c044ea2;
case 0x0c044ea4u: goto P_0c044ea4;
case 0x0c044ea6u: goto P_0c044ea6;
case 0x0c044ea8u: goto P_0c044ea8;
case 0x0c044eaau: goto P_0c044eaa;
case 0x0c044eacu: goto P_0c044eac;
case 0x0c044eaeu: goto P_0c044eae;
case 0x0c044eb0u: goto P_0c044eb0;
case 0x0c044eb2u: goto P_0c044eb2;
case 0x0c044eb4u: goto P_0c044eb4;
case 0x0c044eb6u: goto P_0c044eb6;
case 0x0c044eb8u: goto P_0c044eb8;
case 0x0c044ebau: goto P_0c044eba;
case 0x0c044ebcu: goto P_0c044ebc;
case 0x0c044ebeu: goto P_0c044ebe;
case 0x0c044ec0u: goto P_0c044ec0;
case 0x0c044ec2u: goto P_0c044ec2;
case 0x0c044ec4u: goto P_0c044ec4;
case 0x0c044ec6u: goto P_0c044ec6;
case 0x0c044ec8u: goto P_0c044ec8;
case 0x0c044ecau: goto P_0c044eca;
case 0x0c044eccu: goto P_0c044ecc;
case 0x0c044eceu: goto P_0c044ece;
case 0x0c044ed0u: goto P_0c044ed0;
case 0x0c044ed2u: goto P_0c044ed2;
case 0x0c044ed4u: goto P_0c044ed4;
case 0x0c044ed6u: goto P_0c044ed6;
case 0x0c044ed8u: goto P_0c044ed8;
case 0x0c044edau: goto P_0c044eda;
case 0x0c044edcu: goto P_0c044edc;
case 0x0c044edeu: goto P_0c044ede;
case 0x0c044ee0u: goto P_0c044ee0;
case 0x0c044ee2u: goto P_0c044ee2;
case 0x0c044ee4u: goto P_0c044ee4;
case 0x0c044ee6u: goto P_0c044ee6;
case 0x0c044ee8u: goto P_0c044ee8;
case 0x0c044eeau: goto P_0c044eea;
case 0x0c044eecu: goto P_0c044eec;
case 0x0c044eeeu: goto P_0c044eee;
case 0x0c044ef0u: goto P_0c044ef0;
case 0x0c044ef2u: goto P_0c044ef2;
case 0x0c044ef4u: goto P_0c044ef4;
case 0x0c044ef6u: goto P_0c044ef6;
case 0x0c044ef8u: goto P_0c044ef8;
case 0x0c044efau: goto P_0c044efa;
case 0x0c044efcu: goto P_0c044efc;
case 0x0c044efeu: goto P_0c044efe;
case 0x0c044f00u: goto P_0c044f00;
case 0x0c044f02u: goto P_0c044f02;
case 0x0c044f04u: goto P_0c044f04;
case 0x0c044f06u: goto P_0c044f06;
case 0x0c044f08u: goto P_0c044f08;
case 0x0c044f0au: goto P_0c044f0a;
case 0x0c044f0cu: goto P_0c044f0c;
case 0x0c044f0eu: goto P_0c044f0e;
case 0x0c044f10u: goto P_0c044f10;
case 0x0c044f12u: goto P_0c044f12;
case 0x0c044f14u: goto P_0c044f14;
case 0x0c044f16u: goto P_0c044f16;
case 0x0c044f18u: goto P_0c044f18;
case 0x0c044f1au: goto P_0c044f1a;
case 0x0c044f1cu: goto P_0c044f1c;
case 0x0c044f1eu: goto P_0c044f1e;
case 0x0c044f20u: goto P_0c044f20;
case 0x0c044f22u: goto P_0c044f22;
case 0x0c044f24u: goto P_0c044f24;
case 0x0c044f26u: goto P_0c044f26;
case 0x0c044f28u: goto P_0c044f28;
case 0x0c044f2au: goto P_0c044f2a;
case 0x0c044f2cu: goto P_0c044f2c;
case 0x0c044f2eu: goto P_0c044f2e;
case 0x0c044f30u: goto P_0c044f30;
case 0x0c044f32u: goto P_0c044f32;
case 0x0c044f34u: goto P_0c044f34;
case 0x0c044f36u: goto P_0c044f36;
case 0x0c044f38u: goto P_0c044f38;
case 0x0c044f3au: goto P_0c044f3a;
case 0x0c044f3cu: goto P_0c044f3c;
case 0x0c044f3eu: goto P_0c044f3e;
case 0x0c044f40u: goto P_0c044f40;
case 0x0c044f42u: goto P_0c044f42;
case 0x0c044f44u: goto P_0c044f44;
case 0x0c044f46u: goto P_0c044f46;
case 0x0c044f48u: goto P_0c044f48;
case 0x0c044f4au: goto P_0c044f4a;
case 0x0c044f4cu: goto P_0c044f4c;
case 0x0c044f4eu: goto P_0c044f4e;
case 0x0c044f50u: goto P_0c044f50;
case 0x0c044f52u: goto P_0c044f52;
case 0x0c044f54u: goto P_0c044f54;
case 0x0c044f56u: goto P_0c044f56;
case 0x0c044f58u: goto P_0c044f58;
case 0x0c044f5au: goto P_0c044f5a;
case 0x0c044f5cu: goto P_0c044f5c;
case 0x0c044f5eu: goto P_0c044f5e;
case 0x0c044f60u: goto P_0c044f60;
case 0x0c044f62u: goto P_0c044f62;
case 0x0c044f64u: goto P_0c044f64;
case 0x0c044f66u: goto P_0c044f66;
case 0x0c044f68u: goto P_0c044f68;
case 0x0c044f6au: goto P_0c044f6a;
case 0x0c044f6cu: goto P_0c044f6c;
case 0x0c044f6eu: goto P_0c044f6e;
case 0x0c044f70u: goto P_0c044f70;
case 0x0c044f72u: goto P_0c044f72;
case 0x0c044f74u: goto P_0c044f74;
case 0x0c044f76u: goto P_0c044f76;
case 0x0c044f78u: goto P_0c044f78;
case 0x0c044f7au: goto P_0c044f7a;
case 0x0c0459fcu: goto P_0c0459fc;
case 0x0c0459feu: goto P_0c0459fe;
case 0x0c045a00u: goto P_0c045a00;
case 0x0c045a02u: goto P_0c045a02;
case 0x0c045a04u: goto P_0c045a04;
case 0x0c045a06u: goto P_0c045a06;
case 0x0c045a08u: goto P_0c045a08;
case 0x0c045a0au: goto P_0c045a0a;
case 0x0c045a0cu: goto P_0c045a0c;
case 0x0c045a0eu: goto P_0c045a0e;
case 0x0c045a10u: goto P_0c045a10;
case 0x0c045a12u: goto P_0c045a12;
case 0x0c045a14u: goto P_0c045a14;
case 0x0c045a16u: goto P_0c045a16;
case 0x0c045a18u: goto P_0c045a18;
case 0x0c045a1au: goto P_0c045a1a;
case 0x0c045a1cu: goto P_0c045a1c;
case 0x0c045a1eu: goto P_0c045a1e;
case 0x0c045a20u: goto P_0c045a20;
case 0x0c045a22u: goto P_0c045a22;
case 0x0c045a24u: goto P_0c045a24;
case 0x0c045a26u: goto P_0c045a26;
case 0x0c045a28u: goto P_0c045a28;
case 0x0c045a2au: goto P_0c045a2a;
case 0x0c045a2cu: goto P_0c045a2c;
case 0x0c045a2eu: goto P_0c045a2e;
case 0x0c045a30u: goto P_0c045a30;
case 0x0c045a5eu: goto P_0c045a5e;
case 0x0c045a60u: goto P_0c045a60;
case 0x0c045a62u: goto P_0c045a62;
case 0x0c045a64u: goto P_0c045a64;
case 0x0c045a66u: goto P_0c045a66;
case 0x0c045a68u: goto P_0c045a68;
case 0x0c045a6au: goto P_0c045a6a;
case 0x0c045a6cu: goto P_0c045a6c;
case 0x0c045a6eu: goto P_0c045a6e;
case 0x0c045a70u: goto P_0c045a70;
case 0x0c045a72u: goto P_0c045a72;
case 0x0c045a74u: goto P_0c045a74;
case 0x0c045a76u: goto P_0c045a76;
case 0x0c045a78u: goto P_0c045a78;
case 0x0c045a7au: goto P_0c045a7a;
case 0x0c045a7cu: goto P_0c045a7c;
case 0x0c045a7eu: goto P_0c045a7e;
case 0x0c045a80u: goto P_0c045a80;
case 0x0c045a82u: goto P_0c045a82;
case 0x0c045a84u: goto P_0c045a84;
case 0x0c045a86u: goto P_0c045a86;
case 0x0c045f62u: goto P_0c045f62;
case 0x0c045f64u: goto P_0c045f64;
case 0x0c045f66u: goto P_0c045f66;
case 0x0c045f68u: goto P_0c045f68;
case 0x0c045f6au: goto P_0c045f6a;
case 0x0c045f6cu: goto P_0c045f6c;
case 0x0c045f6eu: goto P_0c045f6e;
case 0x0c045f70u: goto P_0c045f70;
case 0x0c045f72u: goto P_0c045f72;
case 0x0c045f74u: goto P_0c045f74;
case 0x0c045f76u: goto P_0c045f76;
case 0x0c045f78u: goto P_0c045f78;
case 0x0c045f7au: goto P_0c045f7a;
case 0x0c045f7cu: goto P_0c045f7c;
case 0x0c0460a6u: goto P_0c0460a6;
case 0x0c0460a8u: goto P_0c0460a8;
case 0x0c0460aau: goto P_0c0460aa;
case 0x0c0460acu: goto P_0c0460ac;
case 0x0c0460aeu: goto P_0c0460ae;
case 0x0c0460b0u: goto P_0c0460b0;
case 0x0c0460b2u: goto P_0c0460b2;
case 0x0c0460b4u: goto P_0c0460b4;
case 0x0c0460b6u: goto P_0c0460b6;
case 0x0c0460b8u: goto P_0c0460b8;
case 0x0c0460bau: goto P_0c0460ba;
case 0x0c0460bcu: goto P_0c0460bc;
case 0x0c0460beu: goto P_0c0460be;
case 0x0c0460c0u: goto P_0c0460c0;
case 0x0c0460c2u: goto P_0c0460c2;
case 0x0c0460c4u: goto P_0c0460c4;
case 0x0c0460c6u: goto P_0c0460c6;
case 0x0c0460c8u: goto P_0c0460c8;
case 0x0c0460cau: goto P_0c0460ca;
case 0x0c0460ccu: goto P_0c0460cc;
case 0x0c0460ceu: goto P_0c0460ce;
case 0x0c048008u: goto P_0c048008;
case 0x0c04800au: goto P_0c04800a;
case 0x0c04800cu: goto P_0c04800c;
case 0x0c04800eu: goto P_0c04800e;
case 0x0c048010u: goto P_0c048010;
case 0x0c048012u: goto P_0c048012;
case 0x0c048014u: goto P_0c048014;
case 0x0c048016u: goto P_0c048016;
case 0x0c04860eu: goto P_0c04860e;
case 0x0c048610u: goto P_0c048610;
case 0x0c048612u: goto P_0c048612;
case 0x0c048614u: goto P_0c048614;
case 0x0c048616u: goto P_0c048616;
case 0x0c048618u: goto P_0c048618;
case 0x0c04861au: goto P_0c04861a;
case 0x0c04861cu: goto P_0c04861c;
case 0x0c04861eu: goto P_0c04861e;
case 0x0c048620u: goto P_0c048620;
case 0x0c048622u: goto P_0c048622;
case 0x0c048624u: goto P_0c048624;
case 0x0c048626u: goto P_0c048626;
case 0x0c048628u: goto P_0c048628;
case 0x0c04862au: goto P_0c04862a;
case 0x0c04862cu: goto P_0c04862c;
case 0x0c04862eu: goto P_0c04862e;
case 0x0c048630u: goto P_0c048630;
case 0x0c048632u: goto P_0c048632;
case 0x0c048634u: goto P_0c048634;
case 0x0c048636u: goto P_0c048636;
case 0x0c048638u: goto P_0c048638;
case 0x0c04863au: goto P_0c04863a;
case 0x0c04863cu: goto P_0c04863c;
case 0x0c04863eu: goto P_0c04863e;
case 0x0c048640u: goto P_0c048640;
case 0x0c048642u: goto P_0c048642;
case 0x0c048644u: goto P_0c048644;
case 0x0c048646u: goto P_0c048646;
case 0x0c048648u: goto P_0c048648;
case 0x0c04864au: goto P_0c04864a;
case 0x0c04864cu: goto P_0c04864c;
case 0x0c04864eu: goto P_0c04864e;
case 0x0c048650u: goto P_0c048650;
case 0x0c048652u: goto P_0c048652;
case 0x0c048654u: goto P_0c048654;
case 0x0c048656u: goto P_0c048656;
case 0x0c048658u: goto P_0c048658;
case 0x0c04865au: goto P_0c04865a;
case 0x0c048698u: goto P_0c048698;
case 0x0c04869au: goto P_0c04869a;
case 0x0c0486a4u: goto P_0c0486a4;
case 0x0c0486a6u: goto P_0c0486a6;
case 0x0c0486a8u: goto P_0c0486a8;
case 0x0c0486aau: goto P_0c0486aa;
case 0x0c0486acu: goto P_0c0486ac;
case 0x0c0486aeu: goto P_0c0486ae;
case 0x0c0486b0u: goto P_0c0486b0;
case 0x0c0486b2u: goto P_0c0486b2;
case 0x0c0486b4u: goto P_0c0486b4;
case 0x0c0486b6u: goto P_0c0486b6;
case 0x0c0486b8u: goto P_0c0486b8;
case 0x0c0486bau: goto P_0c0486ba;
case 0x0c0486bcu: goto P_0c0486bc;
case 0x0c0486beu: goto P_0c0486be;
case 0x0c0486c0u: goto P_0c0486c0;
case 0x0c0486c2u: goto P_0c0486c2;
case 0x0c0486c4u: goto P_0c0486c4;
case 0x0c0486c6u: goto P_0c0486c6;
case 0x0c0486c8u: goto P_0c0486c8;
case 0x0c0486cau: goto P_0c0486ca;
case 0x0c0486ccu: goto P_0c0486cc;
case 0x0c0486ceu: goto P_0c0486ce;
case 0x0c0486d0u: goto P_0c0486d0;
case 0x0c0486d2u: goto P_0c0486d2;
case 0x0c0486d4u: goto P_0c0486d4;
case 0x0c0486d6u: goto P_0c0486d6;
case 0x0c0486d8u: goto P_0c0486d8;
case 0x0c0486dau: goto P_0c0486da;
case 0x0c0486dcu: goto P_0c0486dc;
case 0x0c0486deu: goto P_0c0486de;
case 0x0c0486e0u: goto P_0c0486e0;
case 0x0c0486e2u: goto P_0c0486e2;
case 0x0c0486e4u: goto P_0c0486e4;
case 0x0c0486e6u: goto P_0c0486e6;
case 0x0c0486e8u: goto P_0c0486e8;
case 0x0c0486eau: goto P_0c0486ea;
case 0x0c0486ecu: goto P_0c0486ec;
case 0x0c0486eeu: goto P_0c0486ee;
case 0x0c0486f0u: goto P_0c0486f0;
case 0x0c0486f2u: goto P_0c0486f2;
case 0x0c0486f4u: goto P_0c0486f4;
case 0x0c0486f6u: goto P_0c0486f6;
case 0x0c0486f8u: goto P_0c0486f8;
case 0x0c0486fau: goto P_0c0486fa;
case 0x0c0486fcu: goto P_0c0486fc;
case 0x0c0486feu: goto P_0c0486fe;
case 0x0c048700u: goto P_0c048700;
case 0x0c048702u: goto P_0c048702;
case 0x0c048704u: goto P_0c048704;
case 0x0c048706u: goto P_0c048706;
case 0x0c048708u: goto P_0c048708;
case 0x0c04870au: goto P_0c04870a;
case 0x0c04870cu: goto P_0c04870c;
case 0x0c04870eu: goto P_0c04870e;
case 0x0c048710u: goto P_0c048710;
case 0x0c048712u: goto P_0c048712;
case 0x0c048714u: goto P_0c048714;
case 0x0c048716u: goto P_0c048716;
case 0x0c048718u: goto P_0c048718;
case 0x0c04871au: goto P_0c04871a;
case 0x0c04871cu: goto P_0c04871c;
case 0x0c04871eu: goto P_0c04871e;
case 0x0c048720u: goto P_0c048720;
case 0x0c048722u: goto P_0c048722;
case 0x0c048724u: goto P_0c048724;
case 0x0c048726u: goto P_0c048726;
case 0x0c048728u: goto P_0c048728;
case 0x0c04872au: goto P_0c04872a;
case 0x0c04872cu: goto P_0c04872c;
case 0x0c04872eu: goto P_0c04872e;
case 0x0c048730u: goto P_0c048730;
case 0x0c048732u: goto P_0c048732;
case 0x0c048734u: goto P_0c048734;
case 0x0c048736u: goto P_0c048736;
case 0x0c048738u: goto P_0c048738;
case 0x0c04873au: goto P_0c04873a;
case 0x0c04873cu: goto P_0c04873c;
case 0x0c04873eu: goto P_0c04873e;
case 0x0c048740u: goto P_0c048740;
case 0x0c048742u: goto P_0c048742;
case 0x0c048744u: goto P_0c048744;
case 0x0c048746u: goto P_0c048746;
case 0x0c048748u: goto P_0c048748;
case 0x0c04874au: goto P_0c04874a;
case 0x0c04874cu: goto P_0c04874c;
case 0x0c04874eu: goto P_0c04874e;
case 0x0c048750u: goto P_0c048750;
case 0x0c048752u: goto P_0c048752;
case 0x0c048754u: goto P_0c048754;
case 0x0c048756u: goto P_0c048756;
case 0x0c048758u: goto P_0c048758;
case 0x0c04875au: goto P_0c04875a;
case 0x0c04875cu: goto P_0c04875c;
case 0x0c04875eu: goto P_0c04875e;
case 0x0c048760u: goto P_0c048760;
case 0x0c048762u: goto P_0c048762;
case 0x0c048764u: goto P_0c048764;
case 0x0c048766u: goto P_0c048766;
case 0x0c048768u: goto P_0c048768;
case 0x0c04876cu: goto P_0c04876c;
case 0x0c04876eu: goto P_0c04876e;
case 0x0c048770u: goto P_0c048770;
case 0x0c048772u: goto P_0c048772;
case 0x0c048774u: goto P_0c048774;
case 0x0c048776u: goto P_0c048776;
case 0x0c048778u: goto P_0c048778;
case 0x0c04877au: goto P_0c04877a;
case 0x0c04877cu: goto P_0c04877c;
case 0x0c04877eu: goto P_0c04877e;
case 0x0c048780u: goto P_0c048780;
case 0x0c048784u: goto P_0c048784;
case 0x0c048786u: goto P_0c048786;
case 0x0c048caau: goto P_0c048caa;
case 0x0c048cacu: goto P_0c048cac;
case 0x0c048caeu: goto P_0c048cae;
case 0x0c048cb0u: goto P_0c048cb0;
case 0x0c048cb2u: goto P_0c048cb2;
case 0x0c048cb4u: goto P_0c048cb4;
case 0x0c048cb6u: goto P_0c048cb6;
case 0x0c048cb8u: goto P_0c048cb8;
case 0x0c04bd2au: goto P_0c04bd2a;
case 0x0c04bd2cu: goto P_0c04bd2c;
case 0x0c04bd2eu: goto P_0c04bd2e;
case 0x0c04bd30u: goto P_0c04bd30;
case 0x0c04bd32u: goto P_0c04bd32;
case 0x0c04bd34u: goto P_0c04bd34;
case 0x0c04bd36u: goto P_0c04bd36;
case 0x0c04bd38u: goto P_0c04bd38;
case 0x0c04bd3au: goto P_0c04bd3a;
case 0x0c04bd3cu: goto P_0c04bd3c;
case 0x0c04bd3eu: goto P_0c04bd3e;
case 0x0c04bd40u: goto P_0c04bd40;
case 0x0c04bd42u: goto P_0c04bd42;
case 0x0c04bd44u: goto P_0c04bd44;
case 0x0c04bd46u: goto P_0c04bd46;
case 0x0c04bd48u: goto P_0c04bd48;
case 0x0c04bd4au: goto P_0c04bd4a;
case 0x0c04bd4cu: goto P_0c04bd4c;
case 0x0c04bd4eu: goto P_0c04bd4e;
case 0x0c04bd50u: goto P_0c04bd50;
case 0x0c04bd52u: goto P_0c04bd52;
case 0x0c04bd54u: goto P_0c04bd54;
case 0x0c04bd56u: goto P_0c04bd56;
case 0x0c04bd58u: goto P_0c04bd58;
case 0x0c04bd5au: goto P_0c04bd5a;
case 0x0c04bd5cu: goto P_0c04bd5c;
case 0x0c053cacu: goto P_0c053cac;
case 0x0c053caeu: goto P_0c053cae;
case 0x0c053cb0u: goto P_0c053cb0;
case 0x0c053cb2u: goto P_0c053cb2;
case 0x0c053cb4u: goto P_0c053cb4;
case 0x0c053cb6u: goto P_0c053cb6;
case 0x0c053cb8u: goto P_0c053cb8;
case 0x0c053cbau: goto P_0c053cba;
case 0x0c053cbcu: goto P_0c053cbc;
case 0x0c053cbeu: goto P_0c053cbe;
case 0x0c053cc0u: goto P_0c053cc0;
case 0x0c053cc2u: goto P_0c053cc2;
case 0x0c053cc4u: goto P_0c053cc4;
case 0x0c053cc6u: goto P_0c053cc6;
case 0x0c053cc8u: goto P_0c053cc8;
case 0x0c053ccau: goto P_0c053cca;
case 0x0c053cccu: goto P_0c053ccc;
case 0x0c053cceu: goto P_0c053cce;
case 0x0c053cd0u: goto P_0c053cd0;
case 0x0c053cd2u: goto P_0c053cd2;
case 0x0c053cd4u: goto P_0c053cd4;
case 0x0c053cd6u: goto P_0c053cd6;
case 0x0c053cd8u: goto P_0c053cd8;
case 0x0c053cdau: goto P_0c053cda;
case 0x0c053cdcu: goto P_0c053cdc;
case 0x0c053cdeu: goto P_0c053cde;
case 0x0c053ce0u: goto P_0c053ce0;
case 0x0c053ce2u: goto P_0c053ce2;
case 0x0c0559b4u: goto P_0c0559b4;
case 0x0c0559b6u: goto P_0c0559b6;
case 0x0c0559b8u: goto P_0c0559b8;
case 0x0c0559bau: goto P_0c0559ba;
case 0x0c0559bcu: goto P_0c0559bc;
case 0x0c0559beu: goto P_0c0559be;
case 0x0c0559c0u: goto P_0c0559c0;
case 0x0c0559c2u: goto P_0c0559c2;
case 0x0c0559c4u: goto P_0c0559c4;
case 0x0c0559c6u: goto P_0c0559c6;
case 0x0c0559c8u: goto P_0c0559c8;
case 0x0c0559cau: goto P_0c0559ca;
case 0x0c0559ccu: goto P_0c0559cc;
case 0x0c0559ceu: goto P_0c0559ce;
case 0x0c0559d0u: goto P_0c0559d0;
case 0x0c0559d2u: goto P_0c0559d2;
case 0x0c0559d4u: goto P_0c0559d4;
case 0x0c0559d6u: goto P_0c0559d6;
case 0x0c0559d8u: goto P_0c0559d8;
case 0x0c0559dau: goto P_0c0559da;
case 0x0c0559dcu: goto P_0c0559dc;
case 0x0c0559deu: goto P_0c0559de;
case 0x0c0559e0u: goto P_0c0559e0;
case 0x0c0559e2u: goto P_0c0559e2;
case 0x0c0559e4u: goto P_0c0559e4;
case 0x0c0559e6u: goto P_0c0559e6;
case 0x0c0559e8u: goto P_0c0559e8;
case 0x0c0559eau: goto P_0c0559ea;
case 0x0c0559ecu: goto P_0c0559ec;
case 0x0c0559eeu: goto P_0c0559ee;
case 0x0c0559f0u: goto P_0c0559f0;
case 0x0c0559f2u: goto P_0c0559f2;
case 0x0c0559f4u: goto P_0c0559f4;
case 0x0c0559f6u: goto P_0c0559f6;
case 0x0c0559f8u: goto P_0c0559f8;
case 0x0c0559fau: goto P_0c0559fa;
case 0x0c0559fcu: goto P_0c0559fc;
case 0x0c0559feu: goto P_0c0559fe;
case 0x0c055a00u: goto P_0c055a00;
case 0x0c055a02u: goto P_0c055a02;
case 0x0c055a04u: goto P_0c055a04;
case 0x0c055a06u: goto P_0c055a06;
case 0x0c055a08u: goto P_0c055a08;
case 0x0c055a0au: goto P_0c055a0a;
case 0x0c055a0cu: goto P_0c055a0c;
case 0x0c055a0eu: goto P_0c055a0e;
case 0x0c055a10u: goto P_0c055a10;
case 0x0c056340u: goto P_0c056340;
case 0x0c056342u: goto P_0c056342;
case 0x0c056344u: goto P_0c056344;
case 0x0c056346u: goto P_0c056346;
case 0x0c056348u: goto P_0c056348;
case 0x0c05634au: goto P_0c05634a;
case 0x0c05634cu: goto P_0c05634c;
case 0x0c05634eu: goto P_0c05634e;
case 0x0c056350u: goto P_0c056350;
case 0x0c056352u: goto P_0c056352;
case 0x0c0696c6u: goto P_0c0696c6;
case 0x0c0696c8u: goto P_0c0696c8;
case 0x0c0696cau: goto P_0c0696ca;
case 0x0c0696ccu: goto P_0c0696cc;
case 0x0c0696ceu: goto P_0c0696ce;
case 0x0c0696d0u: goto P_0c0696d0;
case 0x0c0696d2u: goto P_0c0696d2;
case 0x0c0696d4u: goto P_0c0696d4;
case 0x0c0696d6u: goto P_0c0696d6;
case 0x0c0696d8u: goto P_0c0696d8;
case 0x0c0696dau: goto P_0c0696da;
case 0x0c0696dcu: goto P_0c0696dc;
case 0x0c0696deu: goto P_0c0696de;
case 0x0c0696e0u: goto P_0c0696e0;
case 0x0c0696e2u: goto P_0c0696e2;
case 0x0c0696e4u: goto P_0c0696e4;
case 0x0c06bea4u: goto P_0c06bea4;
case 0x0c06bea6u: goto P_0c06bea6;
case 0x0c06bea8u: goto P_0c06bea8;
case 0x0c06beaau: goto P_0c06beaa;
case 0x0c06beacu: goto P_0c06beac;
case 0x0c06beaeu: goto P_0c06beae;
case 0x0c06beb0u: goto P_0c06beb0;
case 0x0c06beb2u: goto P_0c06beb2;
case 0x0c06beb4u: goto P_0c06beb4;
case 0x0c06beb6u: goto P_0c06beb6;
case 0x0c06beb8u: goto P_0c06beb8;
case 0x0c06bebau: goto P_0c06beba;
case 0x0c06bebcu: goto P_0c06bebc;
case 0x0c06bebeu: goto P_0c06bebe;
case 0x0c06bec0u: goto P_0c06bec0;
case 0x0c06bec2u: goto P_0c06bec2;
case 0x0c06bec4u: goto P_0c06bec4;
case 0x0c06bec6u: goto P_0c06bec6;
case 0x0c06bec8u: goto P_0c06bec8;
case 0x0c06becau: goto P_0c06beca;
case 0x0c06beccu: goto P_0c06becc;
case 0x0c06beceu: goto P_0c06bece;
case 0x0c06bed0u: goto P_0c06bed0;
case 0x0c06bed2u: goto P_0c06bed2;
case 0x0c06bed4u: goto P_0c06bed4;
case 0x0c06bed6u: goto P_0c06bed6;
case 0x0c06bed8u: goto P_0c06bed8;
case 0x0c06bedau: goto P_0c06beda;
case 0x0c06bedcu: goto P_0c06bedc;
case 0x0c06bedeu: goto P_0c06bede;
case 0x0c06bee0u: goto P_0c06bee0;
case 0x0c06bee2u: goto P_0c06bee2;
case 0x0c06bee4u: goto P_0c06bee4;
case 0x0c06bee6u: goto P_0c06bee6;
case 0x0c06bee8u: goto P_0c06bee8;
case 0x0c06beeau: goto P_0c06beea;
case 0x0c06beecu: goto P_0c06beec;
case 0x0c06beeeu: goto P_0c06beee;
case 0x0c06bef0u: goto P_0c06bef0;
case 0x0c06bef2u: goto P_0c06bef2;
case 0x0c06bef4u: goto P_0c06bef4;
case 0x0c06bef6u: goto P_0c06bef6;
case 0x0c06bef8u: goto P_0c06bef8;
case 0x0c06befau: goto P_0c06befa;
case 0x0c06befcu: goto P_0c06befc;
case 0x0c06befeu: goto P_0c06befe;
case 0x0c06bf08u: goto P_0c06bf08;
case 0x0c06bf0au: goto P_0c06bf0a;
case 0x0c06bf0cu: goto P_0c06bf0c;
case 0x0c06bf0eu: goto P_0c06bf0e;
case 0x0c06bf10u: goto P_0c06bf10;
case 0x0c06bf12u: goto P_0c06bf12;
case 0x0c06bf14u: goto P_0c06bf14;
case 0x0c06bf16u: goto P_0c06bf16;
case 0x0c06bf18u: goto P_0c06bf18;
case 0x0c06bf1au: goto P_0c06bf1a;
case 0x0c06bf1cu: goto P_0c06bf1c;
case 0x0c06bf1eu: goto P_0c06bf1e;
case 0x0c06bf20u: goto P_0c06bf20;
case 0x0c06bf22u: goto P_0c06bf22;
case 0x0c06bf24u: goto P_0c06bf24;
case 0x0c06bf26u: goto P_0c06bf26;
case 0x0c06bf28u: goto P_0c06bf28;
case 0x0c06bf2au: goto P_0c06bf2a;
case 0x0c06bf2cu: goto P_0c06bf2c;
case 0x0c06bf2eu: goto P_0c06bf2e;
case 0x0c06bf30u: goto P_0c06bf30;
case 0x0c06bf32u: goto P_0c06bf32;
case 0x0c06bf34u: goto P_0c06bf34;
case 0x0c06bf36u: goto P_0c06bf36;
case 0x0c06bf38u: goto P_0c06bf38;
case 0x0c06bf3au: goto P_0c06bf3a;
case 0x0c06bf3cu: goto P_0c06bf3c;
case 0x0c06bf3eu: goto P_0c06bf3e;
case 0x0c06bf40u: goto P_0c06bf40;
case 0x0c06bf42u: goto P_0c06bf42;
case 0x0c06bf44u: goto P_0c06bf44;
case 0x0c06bf46u: goto P_0c06bf46;
case 0x0c06bf48u: goto P_0c06bf48;
case 0x0c06bf4au: goto P_0c06bf4a;
case 0x0c06bf4cu: goto P_0c06bf4c;
case 0x0c06bf4eu: goto P_0c06bf4e;
case 0x0c06bf50u: goto P_0c06bf50;
case 0x0c06bf52u: goto P_0c06bf52;
case 0x0c06c3d4u: goto P_0c06c3d4;
case 0x0c06c3d6u: goto P_0c06c3d6;
case 0x0c06c3d8u: goto P_0c06c3d8;
case 0x0c06c3dau: goto P_0c06c3da;
case 0x0c06c3dcu: goto P_0c06c3dc;
case 0x0c06c3deu: goto P_0c06c3de;
case 0x0c06c3e0u: goto P_0c06c3e0;
case 0x0c06c3e2u: goto P_0c06c3e2;
case 0x0c06c3e4u: goto P_0c06c3e4;
case 0x0c06c3e6u: goto P_0c06c3e6;
case 0x0c06c3e8u: goto P_0c06c3e8;
case 0x0c06c3eau: goto P_0c06c3ea;
case 0x0c06c3ecu: goto P_0c06c3ec;
case 0x0c06c3eeu: goto P_0c06c3ee;
case 0x0c06c3f0u: goto P_0c06c3f0;
case 0x0c06c3f2u: goto P_0c06c3f2;
case 0x0c06c3f4u: goto P_0c06c3f4;
case 0x0c06c3f6u: goto P_0c06c3f6;
case 0x0c06c3f8u: goto P_0c06c3f8;
case 0x0c06c3fau: goto P_0c06c3fa;
case 0x0c06c3fcu: goto P_0c06c3fc;
case 0x0c06c3feu: goto P_0c06c3fe;
case 0x0c06c400u: goto P_0c06c400;
case 0x0c06c402u: goto P_0c06c402;
case 0x0c06c404u: goto P_0c06c404;
case 0x0c06c42au: goto P_0c06c42a;
case 0x0c06c42cu: goto P_0c06c42c;
case 0x0c06c42eu: goto P_0c06c42e;
case 0x0c06c430u: goto P_0c06c430;
case 0x0c06c432u: goto P_0c06c432;
case 0x0c06c434u: goto P_0c06c434;
case 0x0c06c436u: goto P_0c06c436;
case 0x0c06c438u: goto P_0c06c438;
case 0x0c06c43au: goto P_0c06c43a;
case 0x0c06c43cu: goto P_0c06c43c;
case 0x0c06c43eu: goto P_0c06c43e;
case 0x0c06c440u: goto P_0c06c440;
case 0x0c06c442u: goto P_0c06c442;
case 0x0c06c444u: goto P_0c06c444;
case 0x0c06c446u: goto P_0c06c446;
case 0x0c06c448u: goto P_0c06c448;
case 0x0c06c44au: goto P_0c06c44a;
case 0x0c06c44cu: goto P_0c06c44c;
case 0x0c06c44eu: goto P_0c06c44e;
case 0x0c06c450u: goto P_0c06c450;
case 0x0c06c452u: goto P_0c06c452;
case 0x0c06c454u: goto P_0c06c454;
case 0x0c06c456u: goto P_0c06c456;
case 0x0c06c458u: goto P_0c06c458;
case 0x0c06c45au: goto P_0c06c45a;
case 0x0c06c45cu: goto P_0c06c45c;
case 0x0c06c45eu: goto P_0c06c45e;
case 0x0c06c460u: goto P_0c06c460;
case 0x0c06c462u: goto P_0c06c462;
case 0x0c06c464u: goto P_0c06c464;
case 0x0c06c466u: goto P_0c06c466;
case 0x0c06c468u: goto P_0c06c468;
case 0x0c06c46au: goto P_0c06c46a;
case 0x0c06c46cu: goto P_0c06c46c;
case 0x0c06c46eu: goto P_0c06c46e;
case 0x0c06c470u: goto P_0c06c470;
case 0x0c06c472u: goto P_0c06c472;
case 0x0c06c474u: goto P_0c06c474;
case 0x0c06c476u: goto P_0c06c476;
case 0x0c06c478u: goto P_0c06c478;
case 0x0c06d772u: goto P_0c06d772;
case 0x0c06d774u: goto P_0c06d774;
case 0x0c06d776u: goto P_0c06d776;
case 0x0c06d778u: goto P_0c06d778;
case 0x0c06d77au: goto P_0c06d77a;
case 0x0c06d77cu: goto P_0c06d77c;
case 0x0c06d77eu: goto P_0c06d77e;
case 0x0c06d780u: goto P_0c06d780;
case 0x0c06d782u: goto P_0c06d782;
case 0x0c06d784u: goto P_0c06d784;
case 0x0c06d786u: goto P_0c06d786;
case 0x0c06d788u: goto P_0c06d788;
case 0x0c06d78au: goto P_0c06d78a;
case 0x0c06d78cu: goto P_0c06d78c;
case 0x0c06d78eu: goto P_0c06d78e;
case 0x0c06d790u: goto P_0c06d790;
case 0x0c0701feu: goto P_0c0701fe;
case 0x0c070200u: goto P_0c070200;
case 0x0c070202u: goto P_0c070202;
case 0x0c070204u: goto P_0c070204;
case 0x0c070206u: goto P_0c070206;
case 0x0c070208u: goto P_0c070208;
case 0x0c07020au: goto P_0c07020a;
case 0x0c07020cu: goto P_0c07020c;
case 0x0c07020eu: goto P_0c07020e;
case 0x0c070210u: goto P_0c070210;
case 0x0c070212u: goto P_0c070212;
case 0x0c070214u: goto P_0c070214;
case 0x0c070216u: goto P_0c070216;
case 0x0c070218u: goto P_0c070218;
case 0x0c07021au: goto P_0c07021a;
case 0x0c07021cu: goto P_0c07021c;
case 0x0c07021eu: goto P_0c07021e;
case 0x0c070220u: goto P_0c070220;
case 0x0c070222u: goto P_0c070222;
case 0x0c070224u: goto P_0c070224;
case 0x0c070252u: goto P_0c070252;
case 0x0c070254u: goto P_0c070254;
case 0x0c070256u: goto P_0c070256;
case 0x0c070258u: goto P_0c070258;
case 0x0c07025au: goto P_0c07025a;
case 0x0c07025cu: goto P_0c07025c;
case 0x0c07025eu: goto P_0c07025e;
case 0x0c070260u: goto P_0c070260;
case 0x0c070262u: goto P_0c070262;
case 0x0c070264u: goto P_0c070264;
case 0x0c070266u: goto P_0c070266;
case 0x0c070268u: goto P_0c070268;
case 0x0c07026au: goto P_0c07026a;
case 0x0c07026cu: goto P_0c07026c;
case 0x0c07026eu: goto P_0c07026e;
case 0x0c070270u: goto P_0c070270;
case 0x0c070272u: goto P_0c070272;
case 0x0c070274u: goto P_0c070274;
case 0x0c070276u: goto P_0c070276;
case 0x0c070278u: goto P_0c070278;
case 0x0c07027au: goto P_0c07027a;
case 0x0c07027cu: goto P_0c07027c;
case 0x0c07027eu: goto P_0c07027e;
case 0x0c070280u: goto P_0c070280;
case 0x0c070282u: goto P_0c070282;
case 0x0c070284u: goto P_0c070284;
case 0x0c070286u: goto P_0c070286;
case 0x0c070288u: goto P_0c070288;
case 0x0c07028au: goto P_0c07028a;
case 0x0c07028cu: goto P_0c07028c;
case 0x0c07028eu: goto P_0c07028e;
case 0x0c070290u: goto P_0c070290;
case 0x0c070292u: goto P_0c070292;
case 0x0c070294u: goto P_0c070294;
case 0x0c070296u: goto P_0c070296;
case 0x0c070298u: goto P_0c070298;
case 0x0c07029au: goto P_0c07029a;
case 0x0c07029cu: goto P_0c07029c;
case 0x0c07029eu: goto P_0c07029e;
case 0x0c0702a0u: goto P_0c0702a0;
case 0x0c0702a2u: goto P_0c0702a2;
case 0x0c0702a4u: goto P_0c0702a4;
case 0x0c0702a6u: goto P_0c0702a6;
case 0x0c0702a8u: goto P_0c0702a8;
case 0x0c0702aau: goto P_0c0702aa;
case 0x0c0702acu: goto P_0c0702ac;
case 0x0c0702aeu: goto P_0c0702ae;
case 0x0c0702b0u: goto P_0c0702b0;
case 0x0c0702b2u: goto P_0c0702b2;
case 0x0c0702b4u: goto P_0c0702b4;
case 0x0c0702b6u: goto P_0c0702b6;
case 0x0c0702b8u: goto P_0c0702b8;
case 0x0c0702bau: goto P_0c0702ba;
case 0x0c0702bcu: goto P_0c0702bc;
case 0x0c0702beu: goto P_0c0702be;
case 0x0c0702c0u: goto P_0c0702c0;
case 0x0c0702c2u: goto P_0c0702c2;
case 0x0c0702c4u: goto P_0c0702c4;
case 0x0c0702c6u: goto P_0c0702c6;
case 0x0c0702c8u: goto P_0c0702c8;
case 0x0c0702cau: goto P_0c0702ca;
case 0x0c0702ccu: goto P_0c0702cc;
case 0x0c0702ceu: goto P_0c0702ce;
case 0x0c0702d0u: goto P_0c0702d0;
case 0x0c0702d2u: goto P_0c0702d2;
case 0x0c0702d4u: goto P_0c0702d4;
case 0x0c0702d6u: goto P_0c0702d6;
case 0x0c0702d8u: goto P_0c0702d8;
case 0x0c0702dau: goto P_0c0702da;
case 0x0c0702dcu: goto P_0c0702dc;
case 0x0c0702deu: goto P_0c0702de;
case 0x0c0702e0u: goto P_0c0702e0;
case 0x0c0702e2u: goto P_0c0702e2;
case 0x0c0702e4u: goto P_0c0702e4;
case 0x0c0702e6u: goto P_0c0702e6;
case 0x0c0702e8u: goto P_0c0702e8;
case 0x0c0702eau: goto P_0c0702ea;
case 0x0c0702ecu: goto P_0c0702ec;
case 0x0c0702eeu: goto P_0c0702ee;
case 0x0c0702f0u: goto P_0c0702f0;
case 0x0c0702f2u: goto P_0c0702f2;
case 0x0c0702f4u: goto P_0c0702f4;
case 0x0c0702f6u: goto P_0c0702f6;
case 0x0c0702f8u: goto P_0c0702f8;
case 0x0c0702fau: goto P_0c0702fa;
case 0x0c0702fcu: goto P_0c0702fc;
case 0x0c0702feu: goto P_0c0702fe;
case 0x0c070300u: goto P_0c070300;
case 0x0c070302u: goto P_0c070302;
case 0x0c070304u: goto P_0c070304;
case 0x0c070306u: goto P_0c070306;
case 0x0c070308u: goto P_0c070308;
case 0x0c07030au: goto P_0c07030a;
case 0x0c07030cu: goto P_0c07030c;
case 0x0c07030eu: goto P_0c07030e;
case 0x0c070310u: goto P_0c070310;
case 0x0c070312u: goto P_0c070312;
case 0x0c070314u: goto P_0c070314;
case 0x0c070316u: goto P_0c070316;
case 0x0c070318u: goto P_0c070318;
case 0x0c07031au: goto P_0c07031a;
case 0x0c07031cu: goto P_0c07031c;
case 0x0c07031eu: goto P_0c07031e;
case 0x0c070320u: goto P_0c070320;
case 0x0c070322u: goto P_0c070322;
case 0x0c070324u: goto P_0c070324;
case 0x0c070326u: goto P_0c070326;
case 0x0c070328u: goto P_0c070328;
case 0x0c07032au: goto P_0c07032a;
case 0x0c07032cu: goto P_0c07032c;
case 0x0c07032eu: goto P_0c07032e;
case 0x0c070330u: goto P_0c070330;
case 0x0c070332u: goto P_0c070332;
case 0x0c070334u: goto P_0c070334;
case 0x0c070336u: goto P_0c070336;
case 0x0c070338u: goto P_0c070338;
case 0x0c07033au: goto P_0c07033a;
case 0x0c07033cu: goto P_0c07033c;
case 0x0c070344u: goto P_0c070344;
case 0x0c070346u: goto P_0c070346;
case 0x0c070348u: goto P_0c070348;
case 0x0c07034au: goto P_0c07034a;
case 0x0c07034cu: goto P_0c07034c;
case 0x0c07034eu: goto P_0c07034e;
case 0x0c070350u: goto P_0c070350;
case 0x0c070352u: goto P_0c070352;
case 0x0c070354u: goto P_0c070354;
case 0x0c070356u: goto P_0c070356;
case 0x0c070358u: goto P_0c070358;
case 0x0c07035au: goto P_0c07035a;
case 0x0c07035cu: goto P_0c07035c;
case 0x0c07035eu: goto P_0c07035e;
case 0x0c070360u: goto P_0c070360;
case 0x0c070362u: goto P_0c070362;
case 0x0c070364u: goto P_0c070364;
case 0x0c070366u: goto P_0c070366;
case 0x0c070368u: goto P_0c070368;
case 0x0c07036au: goto P_0c07036a;
case 0x0c07036cu: goto P_0c07036c;
case 0x0c07036eu: goto P_0c07036e;
case 0x0c070370u: goto P_0c070370;
case 0x0c070372u: goto P_0c070372;
case 0x0c070374u: goto P_0c070374;
case 0x0c070376u: goto P_0c070376;
case 0x0c070378u: goto P_0c070378;
case 0x0c07037au: goto P_0c07037a;
case 0x0c07037cu: goto P_0c07037c;
case 0x0c07037eu: goto P_0c07037e;
case 0x0c070380u: goto P_0c070380;
case 0x0c070382u: goto P_0c070382;
case 0x0c070384u: goto P_0c070384;
case 0x0c070386u: goto P_0c070386;
case 0x0c070388u: goto P_0c070388;
case 0x0c070390u: goto P_0c070390;
case 0x0c070392u: goto P_0c070392;
case 0x0c070394u: goto P_0c070394;
case 0x0c070396u: goto P_0c070396;
case 0x0c070398u: goto P_0c070398;
case 0x0c07039au: goto P_0c07039a;
case 0x0c07039cu: goto P_0c07039c;
case 0x0c07039eu: goto P_0c07039e;
case 0x0c0703a0u: goto P_0c0703a0;
case 0x0c0703a2u: goto P_0c0703a2;
case 0x0c0703a4u: goto P_0c0703a4;
case 0x0c0703a6u: goto P_0c0703a6;
case 0x0c0703a8u: goto P_0c0703a8;
case 0x0c0703aau: goto P_0c0703aa;
case 0x0c0703acu: goto P_0c0703ac;
case 0x0c0703aeu: goto P_0c0703ae;
case 0x0c0703b0u: goto P_0c0703b0;
case 0x0c0703b2u: goto P_0c0703b2;
case 0x0c0703b4u: goto P_0c0703b4;
case 0x0c0703b6u: goto P_0c0703b6;
case 0x0c0703b8u: goto P_0c0703b8;
case 0x0c0703bau: goto P_0c0703ba;
case 0x0c0703bcu: goto P_0c0703bc;
case 0x0c0703beu: goto P_0c0703be;
case 0x0c0703c0u: goto P_0c0703c0;
case 0x0c0703c2u: goto P_0c0703c2;
case 0x0c0703c4u: goto P_0c0703c4;
case 0x0c0703c6u: goto P_0c0703c6;
case 0x0c0703c8u: goto P_0c0703c8;
case 0x0c0703cau: goto P_0c0703ca;
case 0x0c0703ccu: goto P_0c0703cc;
case 0x0c0703d8u: goto P_0c0703d8;
case 0x0c0703dau: goto P_0c0703da;
case 0x0c0703dcu: goto P_0c0703dc;
case 0x0c0703deu: goto P_0c0703de;
case 0x0c0703e0u: goto P_0c0703e0;
case 0x0c0703e2u: goto P_0c0703e2;
case 0x0c0703e4u: goto P_0c0703e4;
case 0x0c0703e6u: goto P_0c0703e6;
case 0x0c0703e8u: goto P_0c0703e8;
case 0x0c0703eau: goto P_0c0703ea;
case 0x0c0703ecu: goto P_0c0703ec;
case 0x0c0703eeu: goto P_0c0703ee;
case 0x0c0703f0u: goto P_0c0703f0;
case 0x0c0703f2u: goto P_0c0703f2;
case 0x0c0703f4u: goto P_0c0703f4;
case 0x0c0703f6u: goto P_0c0703f6;
case 0x0c0703f8u: goto P_0c0703f8;
case 0x0c07042au: goto P_0c07042a;
case 0x0c07042cu: goto P_0c07042c;
case 0x0c07042eu: goto P_0c07042e;
case 0x0c070430u: goto P_0c070430;
case 0x0c070432u: goto P_0c070432;
case 0x0c070434u: goto P_0c070434;
case 0x0c070436u: goto P_0c070436;
case 0x0c070438u: goto P_0c070438;
case 0x0c07043au: goto P_0c07043a;
case 0x0c07043cu: goto P_0c07043c;
case 0x0c07043eu: goto P_0c07043e;
case 0x0c070440u: goto P_0c070440;
case 0x0c070442u: goto P_0c070442;
case 0x0c070444u: goto P_0c070444;
case 0x0c070446u: goto P_0c070446;
case 0x0c070448u: goto P_0c070448;
case 0x0c07044au: goto P_0c07044a;
case 0x0c07044cu: goto P_0c07044c;
case 0x0c07044eu: goto P_0c07044e;
case 0x0c070450u: goto P_0c070450;
case 0x0c070452u: goto P_0c070452;
case 0x0c070454u: goto P_0c070454;
case 0x0c070456u: goto P_0c070456;
case 0x0c070458u: goto P_0c070458;
case 0x0c07045au: goto P_0c07045a;
case 0x0c07045cu: goto P_0c07045c;
case 0x0c07045eu: goto P_0c07045e;
case 0x0c070460u: goto P_0c070460;
case 0x0c070462u: goto P_0c070462;
case 0x0c070464u: goto P_0c070464;
case 0x0c070466u: goto P_0c070466;
case 0x0c070468u: goto P_0c070468;
case 0x0c07046au: goto P_0c07046a;
case 0x0c07046cu: goto P_0c07046c;
case 0x0c07046eu: goto P_0c07046e;
case 0x0c070470u: goto P_0c070470;
case 0x0c070472u: goto P_0c070472;
case 0x0c070474u: goto P_0c070474;
case 0x0c070476u: goto P_0c070476;
case 0x0c070478u: goto P_0c070478;
case 0x0c07047au: goto P_0c07047a;
case 0x0c07047cu: goto P_0c07047c;
case 0x0c07047eu: goto P_0c07047e;
case 0x0c070480u: goto P_0c070480;
case 0x0c070482u: goto P_0c070482;
case 0x0c070484u: goto P_0c070484;
case 0x0c070486u: goto P_0c070486;
case 0x0c070488u: goto P_0c070488;
case 0x0c07048au: goto P_0c07048a;
case 0x0c07048cu: goto P_0c07048c;
case 0x0c07048eu: goto P_0c07048e;
case 0x0c070490u: goto P_0c070490;
case 0x0c070492u: goto P_0c070492;
case 0x0c070494u: goto P_0c070494;
case 0x0c070496u: goto P_0c070496;
case 0x0c070498u: goto P_0c070498;
case 0x0c07049au: goto P_0c07049a;
case 0x0c07049cu: goto P_0c07049c;
case 0x0c07049eu: goto P_0c07049e;
case 0x0c0704a0u: goto P_0c0704a0;
case 0x0c0704a2u: goto P_0c0704a2;
case 0x0c0704a4u: goto P_0c0704a4;
case 0x0c0704a6u: goto P_0c0704a6;
case 0x0c0704a8u: goto P_0c0704a8;
case 0x0c0704aau: goto P_0c0704aa;
case 0x0c0704acu: goto P_0c0704ac;
case 0x0c0704aeu: goto P_0c0704ae;
case 0x0c0704b0u: goto P_0c0704b0;
case 0x0c0704b2u: goto P_0c0704b2;
case 0x0c0704b4u: goto P_0c0704b4;
case 0x0c0704b6u: goto P_0c0704b6;
case 0x0c0704b8u: goto P_0c0704b8;
case 0x0c0704bau: goto P_0c0704ba;
case 0x0c0704bcu: goto P_0c0704bc;
case 0x0c0704beu: goto P_0c0704be;
case 0x0c0704c0u: goto P_0c0704c0;
case 0x0c0704c2u: goto P_0c0704c2;
case 0x0c0704c4u: goto P_0c0704c4;
case 0x0c0704c6u: goto P_0c0704c6;
case 0x0c0704c8u: goto P_0c0704c8;
case 0x0c0704cau: goto P_0c0704ca;
case 0x0c0704ccu: goto P_0c0704cc;
case 0x0c0704ceu: goto P_0c0704ce;
case 0x0c0704d0u: goto P_0c0704d0;
case 0x0c0704d2u: goto P_0c0704d2;
case 0x0c0704d4u: goto P_0c0704d4;
case 0x0c0704d6u: goto P_0c0704d6;
case 0x0c0704dcu: goto P_0c0704dc;
case 0x0c0704deu: goto P_0c0704de;
case 0x0c0704e0u: goto P_0c0704e0;
case 0x0c0704e2u: goto P_0c0704e2;
case 0x0c0704e4u: goto P_0c0704e4;
case 0x0c0704e6u: goto P_0c0704e6;
case 0x0c0704e8u: goto P_0c0704e8;
case 0x0c0704eau: goto P_0c0704ea;
case 0x0c0704ecu: goto P_0c0704ec;
case 0x0c0704eeu: goto P_0c0704ee;
case 0x0c0704f0u: goto P_0c0704f0;
case 0x0c0704f2u: goto P_0c0704f2;
case 0x0c0704f4u: goto P_0c0704f4;
case 0x0c0704f6u: goto P_0c0704f6;
case 0x0c0704f8u: goto P_0c0704f8;
case 0x0c0704fau: goto P_0c0704fa;
case 0x0c0704fcu: goto P_0c0704fc;
case 0x0c0704feu: goto P_0c0704fe;
case 0x0c070500u: goto P_0c070500;
case 0x0c070502u: goto P_0c070502;
case 0x0c070504u: goto P_0c070504;
case 0x0c070506u: goto P_0c070506;
case 0x0c070508u: goto P_0c070508;
case 0x0c07050au: goto P_0c07050a;
case 0x0c07050cu: goto P_0c07050c;
case 0x0c07050eu: goto P_0c07050e;
case 0x0c070510u: goto P_0c070510;
case 0x0c070512u: goto P_0c070512;
case 0x0c070514u: goto P_0c070514;
case 0x0c070516u: goto P_0c070516;
case 0x0c070518u: goto P_0c070518;
case 0x0c07051au: goto P_0c07051a;
case 0x0c07051cu: goto P_0c07051c;
case 0x0c07051eu: goto P_0c07051e;
case 0x0c070520u: goto P_0c070520;
case 0x0c070522u: goto P_0c070522;
case 0x0c070528u: goto P_0c070528;
case 0x0c07052au: goto P_0c07052a;
case 0x0c07052cu: goto P_0c07052c;
case 0x0c07052eu: goto P_0c07052e;
case 0x0c070530u: goto P_0c070530;
case 0x0c070532u: goto P_0c070532;
case 0x0c070534u: goto P_0c070534;
case 0x0c070536u: goto P_0c070536;
case 0x0c070538u: goto P_0c070538;
case 0x0c07053au: goto P_0c07053a;
case 0x0c07053cu: goto P_0c07053c;
case 0x0c07053eu: goto P_0c07053e;
case 0x0c070540u: goto P_0c070540;
case 0x0c070542u: goto P_0c070542;
case 0x0c070544u: goto P_0c070544;
case 0x0c070546u: goto P_0c070546;
case 0x0c070548u: goto P_0c070548;
case 0x0c07054au: goto P_0c07054a;
case 0x0c07054cu: goto P_0c07054c;
case 0x0c07054eu: goto P_0c07054e;
case 0x0c070550u: goto P_0c070550;
case 0x0c070552u: goto P_0c070552;
case 0x0c070554u: goto P_0c070554;
case 0x0c070556u: goto P_0c070556;
case 0x0c070558u: goto P_0c070558;
case 0x0c07055au: goto P_0c07055a;
case 0x0c07055cu: goto P_0c07055c;
case 0x0c07055eu: goto P_0c07055e;
case 0x0c070560u: goto P_0c070560;
case 0x0c070562u: goto P_0c070562;
case 0x0c070564u: goto P_0c070564;
case 0x0c070566u: goto P_0c070566;
case 0x0c070568u: goto P_0c070568;
case 0x0c07056au: goto P_0c07056a;
case 0x0c07056cu: goto P_0c07056c;
case 0x0c07056eu: goto P_0c07056e;
case 0x0c070574u: goto P_0c070574;
case 0x0c070576u: goto P_0c070576;
case 0x0c070578u: goto P_0c070578;
case 0x0c07057au: goto P_0c07057a;
case 0x0c07057cu: goto P_0c07057c;
case 0x0c07057eu: goto P_0c07057e;
case 0x0c070580u: goto P_0c070580;
case 0x0c070582u: goto P_0c070582;
case 0x0c070584u: goto P_0c070584;
case 0x0c070586u: goto P_0c070586;
case 0x0c070588u: goto P_0c070588;
case 0x0c07058au: goto P_0c07058a;
case 0x0c07058cu: goto P_0c07058c;
case 0x0c07058eu: goto P_0c07058e;
case 0x0c070590u: goto P_0c070590;
case 0x0c070592u: goto P_0c070592;
case 0x0c070594u: goto P_0c070594;
case 0x0c070596u: goto P_0c070596;
case 0x0c070598u: goto P_0c070598;
case 0x0c07059au: goto P_0c07059a;
case 0x0c07059cu: goto P_0c07059c;
case 0x0c07059eu: goto P_0c07059e;
case 0x0c0705a0u: goto P_0c0705a0;
case 0x0c0705a2u: goto P_0c0705a2;
case 0x0c0705a4u: goto P_0c0705a4;
case 0x0c0705a6u: goto P_0c0705a6;
case 0x0c0705a8u: goto P_0c0705a8;
case 0x0c0705aau: goto P_0c0705aa;
case 0x0c0705acu: goto P_0c0705ac;
case 0x0c0705b8u: goto P_0c0705b8;
case 0x0c0705bau: goto P_0c0705ba;
case 0x0c0705bcu: goto P_0c0705bc;
case 0x0c0705beu: goto P_0c0705be;
case 0x0c0705c0u: goto P_0c0705c0;
case 0x0c0705c2u: goto P_0c0705c2;
case 0x0c0705c4u: goto P_0c0705c4;
case 0x0c0705c6u: goto P_0c0705c6;
case 0x0c0705c8u: goto P_0c0705c8;
case 0x0c0705cau: goto P_0c0705ca;
case 0x0c0705ccu: goto P_0c0705cc;
case 0x0c0705ceu: goto P_0c0705ce;
case 0x0c0705d0u: goto P_0c0705d0;
case 0x0c0705d2u: goto P_0c0705d2;
case 0x0c0705d4u: goto P_0c0705d4;
case 0x0c0705d6u: goto P_0c0705d6;
case 0x0c0705d8u: goto P_0c0705d8;
case 0x0c0709ceu: goto P_0c0709ce;
case 0x0c0709d0u: goto P_0c0709d0;
case 0x0c0709d2u: goto P_0c0709d2;
case 0x0c0709d4u: goto P_0c0709d4;
case 0x0c0709d6u: goto P_0c0709d6;
case 0x0c0709d8u: goto P_0c0709d8;
case 0x0c0709dau: goto P_0c0709da;
case 0x0c0709dcu: goto P_0c0709dc;
case 0x0c0709deu: goto P_0c0709de;
case 0x0c0709e0u: goto P_0c0709e0;
case 0x0c0709e2u: goto P_0c0709e2;
case 0x0c0709e4u: goto P_0c0709e4;
case 0x0c0709e6u: goto P_0c0709e6;
case 0x0c0709e8u: goto P_0c0709e8;
case 0x0c0709eau: goto P_0c0709ea;
case 0x0c0709ecu: goto P_0c0709ec;
case 0x0c0709eeu: goto P_0c0709ee;
case 0x0c0709f0u: goto P_0c0709f0;
case 0x0c0709f2u: goto P_0c0709f2;
case 0x0c0709f4u: goto P_0c0709f4;
case 0x0c0709f6u: goto P_0c0709f6;
case 0x0c0709f8u: goto P_0c0709f8;
case 0x0c0709fau: goto P_0c0709fa;
case 0x0c0709fcu: goto P_0c0709fc;
case 0x0c0709feu: goto P_0c0709fe;
case 0x0c070a00u: goto P_0c070a00;
case 0x0c070a02u: goto P_0c070a02;
case 0x0c070a04u: goto P_0c070a04;
case 0x0c070a06u: goto P_0c070a06;
case 0x0c070a08u: goto P_0c070a08;
case 0x0c070a0au: goto P_0c070a0a;
case 0x0c070a0cu: goto P_0c070a0c;
case 0x0c070a0eu: goto P_0c070a0e;
case 0x0c070a10u: goto P_0c070a10;
case 0x0c070a12u: goto P_0c070a12;
case 0x0c070a14u: goto P_0c070a14;
case 0x0c070a16u: goto P_0c070a16;
case 0x0c070a18u: goto P_0c070a18;
case 0x0c070a1au: goto P_0c070a1a;
case 0x0c070a1cu: goto P_0c070a1c;
case 0x0c070a1eu: goto P_0c070a1e;
case 0x0c070a20u: goto P_0c070a20;
case 0x0c070a22u: goto P_0c070a22;
case 0x0c070a24u: goto P_0c070a24;
case 0x0c070a26u: goto P_0c070a26;
case 0x0c070a28u: goto P_0c070a28;
case 0x0c070a2au: goto P_0c070a2a;
case 0x0c070a2cu: goto P_0c070a2c;
case 0x0c070a2eu: goto P_0c070a2e;
case 0x0c070a30u: goto P_0c070a30;
case 0x0c070a32u: goto P_0c070a32;
case 0x0c070a34u: goto P_0c070a34;
case 0x0c070a36u: goto P_0c070a36;
case 0x0c070a38u: goto P_0c070a38;
case 0x0c070a3au: goto P_0c070a3a;
case 0x0c070a3cu: goto P_0c070a3c;
case 0x0c070a3eu: goto P_0c070a3e;
case 0x0c070a40u: goto P_0c070a40;
case 0x0c070a42u: goto P_0c070a42;
case 0x0c070a44u: goto P_0c070a44;
case 0x0c070a46u: goto P_0c070a46;
case 0x0c070a48u: goto P_0c070a48;
case 0x0c070a4au: goto P_0c070a4a;
case 0x0c070a4cu: goto P_0c070a4c;
case 0x0c070a4eu: goto P_0c070a4e;
case 0x0c070a50u: goto P_0c070a50;
case 0x0c070a52u: goto P_0c070a52;
case 0x0c070a54u: goto P_0c070a54;
case 0x0c070a56u: goto P_0c070a56;
case 0x0c070a58u: goto P_0c070a58;
case 0x0c070a5au: goto P_0c070a5a;
case 0x0c070a5cu: goto P_0c070a5c;
case 0x0c070a5eu: goto P_0c070a5e;
case 0x0c070a60u: goto P_0c070a60;
case 0x0c070a62u: goto P_0c070a62;
case 0x0c070a64u: goto P_0c070a64;
case 0x0c070a66u: goto P_0c070a66;
case 0x0c070a68u: goto P_0c070a68;
case 0x0c070a6au: goto P_0c070a6a;
case 0x0c070a6cu: goto P_0c070a6c;
case 0x0c070a6eu: goto P_0c070a6e;
case 0x0c070a70u: goto P_0c070a70;
case 0x0c070a72u: goto P_0c070a72;
case 0x0c070a74u: goto P_0c070a74;
case 0x0c070a76u: goto P_0c070a76;
case 0x0c070a78u: goto P_0c070a78;
case 0x0c070a7au: goto P_0c070a7a;
case 0x0c070a7cu: goto P_0c070a7c;
case 0x0c070a7eu: goto P_0c070a7e;
case 0x0c070a80u: goto P_0c070a80;
case 0x0c070a82u: goto P_0c070a82;
case 0x0c070a84u: goto P_0c070a84;
case 0x0c070a86u: goto P_0c070a86;
case 0x0c070a88u: goto P_0c070a88;
case 0x0c070a8au: goto P_0c070a8a;
case 0x0c070a8cu: goto P_0c070a8c;
case 0x0c070a8eu: goto P_0c070a8e;
case 0x0c070a90u: goto P_0c070a90;
case 0x0c070a92u: goto P_0c070a92;
case 0x0c070a94u: goto P_0c070a94;
case 0x0c070a96u: goto P_0c070a96;
case 0x0c070a98u: goto P_0c070a98;
case 0x0c070a9au: goto P_0c070a9a;
case 0x0c070a9cu: goto P_0c070a9c;
case 0x0c070a9eu: goto P_0c070a9e;
case 0x0c070aa0u: goto P_0c070aa0;
case 0x0c070aa2u: goto P_0c070aa2;
case 0x0c070aa4u: goto P_0c070aa4;
case 0x0c070aa6u: goto P_0c070aa6;
case 0x0c070aa8u: goto P_0c070aa8;
case 0x0c070aaau: goto P_0c070aaa;
case 0x0c070aacu: goto P_0c070aac;
case 0x0c070aaeu: goto P_0c070aae;
case 0x0c070ab0u: goto P_0c070ab0;
case 0x0c070ab2u: goto P_0c070ab2;
case 0x0c070ab4u: goto P_0c070ab4;
case 0x0c070abcu: goto P_0c070abc;
case 0x0c070abeu: goto P_0c070abe;
case 0x0c070ac0u: goto P_0c070ac0;
case 0x0c070ac2u: goto P_0c070ac2;
case 0x0c070ac4u: goto P_0c070ac4;
case 0x0c070ac6u: goto P_0c070ac6;
case 0x0c070ac8u: goto P_0c070ac8;
case 0x0c070acau: goto P_0c070aca;
case 0x0c070accu: goto P_0c070acc;
case 0x0c070aceu: goto P_0c070ace;
case 0x0c070ad0u: goto P_0c070ad0;
case 0x0c070ad2u: goto P_0c070ad2;
case 0x0c070ad4u: goto P_0c070ad4;
case 0x0c070ad6u: goto P_0c070ad6;
case 0x0c070ad8u: goto P_0c070ad8;
case 0x0c070adau: goto P_0c070ada;
case 0x0c070adcu: goto P_0c070adc;
case 0x0c070adeu: goto P_0c070ade;
case 0x0c070ae0u: goto P_0c070ae0;
case 0x0c070ae2u: goto P_0c070ae2;
case 0x0c070ae4u: goto P_0c070ae4;
case 0x0c070ae6u: goto P_0c070ae6;
case 0x0c070ae8u: goto P_0c070ae8;
case 0x0c070aeau: goto P_0c070aea;
case 0x0c070aecu: goto P_0c070aec;
case 0x0c070aeeu: goto P_0c070aee;
case 0x0c070af0u: goto P_0c070af0;
case 0x0c070af2u: goto P_0c070af2;
case 0x0c070af4u: goto P_0c070af4;
case 0x0c070af6u: goto P_0c070af6;
case 0x0c070af8u: goto P_0c070af8;
case 0x0c070afau: goto P_0c070afa;
case 0x0c070afcu: goto P_0c070afc;
case 0x0c070afeu: goto P_0c070afe;
case 0x0c070b00u: goto P_0c070b00;
case 0x0c070b08u: goto P_0c070b08;
case 0x0c070b0au: goto P_0c070b0a;
case 0x0c070b0cu: goto P_0c070b0c;
case 0x0c070b0eu: goto P_0c070b0e;
case 0x0c070b10u: goto P_0c070b10;
case 0x0c070b12u: goto P_0c070b12;
case 0x0c070b14u: goto P_0c070b14;
case 0x0c070b16u: goto P_0c070b16;
case 0x0c070b18u: goto P_0c070b18;
case 0x0c070b1au: goto P_0c070b1a;
case 0x0c070b1cu: goto P_0c070b1c;
case 0x0c070b1eu: goto P_0c070b1e;
case 0x0c070b20u: goto P_0c070b20;
case 0x0c070b22u: goto P_0c070b22;
case 0x0c070b24u: goto P_0c070b24;
case 0x0c070b26u: goto P_0c070b26;
case 0x0c070b28u: goto P_0c070b28;
case 0x0c070b2au: goto P_0c070b2a;
case 0x0c070b2cu: goto P_0c070b2c;
case 0x0c070b2eu: goto P_0c070b2e;
case 0x0c070b30u: goto P_0c070b30;
case 0x0c070b32u: goto P_0c070b32;
case 0x0c070b34u: goto P_0c070b34;
case 0x0c070b36u: goto P_0c070b36;
case 0x0c070b38u: goto P_0c070b38;
case 0x0c070b3au: goto P_0c070b3a;
case 0x0c070b3cu: goto P_0c070b3c;
case 0x0c070b3eu: goto P_0c070b3e;
case 0x0c070b40u: goto P_0c070b40;
case 0x0c070b42u: goto P_0c070b42;
case 0x0c070b44u: goto P_0c070b44;
case 0x0c070b50u: goto P_0c070b50;
case 0x0c070b52u: goto P_0c070b52;
case 0x0c070b54u: goto P_0c070b54;
case 0x0c070b56u: goto P_0c070b56;
case 0x0c070b58u: goto P_0c070b58;
case 0x0c070b5au: goto P_0c070b5a;
case 0x0c070b5cu: goto P_0c070b5c;
case 0x0c070b5eu: goto P_0c070b5e;
case 0x0c070b60u: goto P_0c070b60;
case 0x0c070b62u: goto P_0c070b62;
case 0x0c070b64u: goto P_0c070b64;
case 0x0c070b66u: goto P_0c070b66;
case 0x0c070b68u: goto P_0c070b68;
case 0x0c070b6au: goto P_0c070b6a;
case 0x0c070b6cu: goto P_0c070b6c;
case 0x0c070b6eu: goto P_0c070b6e;
case 0x0c070b70u: goto P_0c070b70;
case 0x0c070ba2u: goto P_0c070ba2;
case 0x0c070ba4u: goto P_0c070ba4;
case 0x0c070ba6u: goto P_0c070ba6;
case 0x0c070ba8u: goto P_0c070ba8;
case 0x0c070baau: goto P_0c070baa;
case 0x0c070bacu: goto P_0c070bac;
case 0x0c070baeu: goto P_0c070bae;
case 0x0c070bb0u: goto P_0c070bb0;
case 0x0c070bb2u: goto P_0c070bb2;
case 0x0c070bb4u: goto P_0c070bb4;
case 0x0c070bb6u: goto P_0c070bb6;
case 0x0c070bb8u: goto P_0c070bb8;
case 0x0c070bbau: goto P_0c070bba;
case 0x0c070bbcu: goto P_0c070bbc;
case 0x0c070bbeu: goto P_0c070bbe;
case 0x0c070bc0u: goto P_0c070bc0;
case 0x0c070bc2u: goto P_0c070bc2;
case 0x0c070bc4u: goto P_0c070bc4;
case 0x0c070bc6u: goto P_0c070bc6;
case 0x0c070bc8u: goto P_0c070bc8;
case 0x0c070bcau: goto P_0c070bca;
case 0x0c070bccu: goto P_0c070bcc;
case 0x0c070bceu: goto P_0c070bce;
case 0x0c070bd0u: goto P_0c070bd0;
case 0x0c070bd2u: goto P_0c070bd2;
case 0x0c070bd4u: goto P_0c070bd4;
case 0x0c070bd6u: goto P_0c070bd6;
case 0x0c070bd8u: goto P_0c070bd8;
case 0x0c070bdau: goto P_0c070bda;
case 0x0c070bdcu: goto P_0c070bdc;
case 0x0c070bdeu: goto P_0c070bde;
case 0x0c070be0u: goto P_0c070be0;
case 0x0c070be2u: goto P_0c070be2;
case 0x0c070be4u: goto P_0c070be4;
case 0x0c070be6u: goto P_0c070be6;
case 0x0c070be8u: goto P_0c070be8;
case 0x0c070beau: goto P_0c070bea;
case 0x0c070becu: goto P_0c070bec;
case 0x0c070beeu: goto P_0c070bee;
case 0x0c070bf0u: goto P_0c070bf0;
case 0x0c070bf2u: goto P_0c070bf2;
case 0x0c070bf4u: goto P_0c070bf4;
case 0x0c070bf6u: goto P_0c070bf6;
case 0x0c070bf8u: goto P_0c070bf8;
case 0x0c070bfau: goto P_0c070bfa;
case 0x0c070bfcu: goto P_0c070bfc;
case 0x0c070bfeu: goto P_0c070bfe;
case 0x0c070c00u: goto P_0c070c00;
case 0x0c070c02u: goto P_0c070c02;
case 0x0c070c04u: goto P_0c070c04;
case 0x0c070c06u: goto P_0c070c06;
case 0x0c070c08u: goto P_0c070c08;
case 0x0c070c0au: goto P_0c070c0a;
case 0x0c070c0cu: goto P_0c070c0c;
case 0x0c070c0eu: goto P_0c070c0e;
case 0x0c070c10u: goto P_0c070c10;
case 0x0c070c12u: goto P_0c070c12;
case 0x0c070c14u: goto P_0c070c14;
case 0x0c070c16u: goto P_0c070c16;
case 0x0c070c18u: goto P_0c070c18;
case 0x0c070c1au: goto P_0c070c1a;
case 0x0c070c1cu: goto P_0c070c1c;
case 0x0c070c1eu: goto P_0c070c1e;
case 0x0c070c20u: goto P_0c070c20;
case 0x0c070c22u: goto P_0c070c22;
case 0x0c070c24u: goto P_0c070c24;
case 0x0c070c26u: goto P_0c070c26;
case 0x0c070c28u: goto P_0c070c28;
case 0x0c070c2au: goto P_0c070c2a;
case 0x0c070c2cu: goto P_0c070c2c;
case 0x0c070c2eu: goto P_0c070c2e;
case 0x0c070c30u: goto P_0c070c30;
case 0x0c070c32u: goto P_0c070c32;
case 0x0c070c34u: goto P_0c070c34;
case 0x0c070c36u: goto P_0c070c36;
case 0x0c070c38u: goto P_0c070c38;
case 0x0c070c3au: goto P_0c070c3a;
case 0x0c070c3cu: goto P_0c070c3c;
case 0x0c070c3eu: goto P_0c070c3e;
case 0x0c070c40u: goto P_0c070c40;
case 0x0c070c42u: goto P_0c070c42;
case 0x0c070c44u: goto P_0c070c44;
case 0x0c070c46u: goto P_0c070c46;
case 0x0c070c48u: goto P_0c070c48;
case 0x0c070c4au: goto P_0c070c4a;
case 0x0c070c4cu: goto P_0c070c4c;
case 0x0c070c4eu: goto P_0c070c4e;
case 0x0c070c50u: goto P_0c070c50;
case 0x0c070c52u: goto P_0c070c52;
case 0x0c070c54u: goto P_0c070c54;
case 0x0c070c56u: goto P_0c070c56;
case 0x0c070c58u: goto P_0c070c58;
case 0x0c070c5au: goto P_0c070c5a;
case 0x0c070c5cu: goto P_0c070c5c;
case 0x0c070c5eu: goto P_0c070c5e;
case 0x0c070c60u: goto P_0c070c60;
case 0x0c070c62u: goto P_0c070c62;
case 0x0c070c64u: goto P_0c070c64;
case 0x0c070c66u: goto P_0c070c66;
case 0x0c070c68u: goto P_0c070c68;
case 0x0c070c6au: goto P_0c070c6a;
case 0x0c070c6cu: goto P_0c070c6c;
case 0x0c070c6eu: goto P_0c070c6e;
case 0x0c070c70u: goto P_0c070c70;
case 0x0c070c72u: goto P_0c070c72;
case 0x0c070c74u: goto P_0c070c74;
case 0x0c070c76u: goto P_0c070c76;
case 0x0c070c78u: goto P_0c070c78;
case 0x0c070c7au: goto P_0c070c7a;
case 0x0c070c7cu: goto P_0c070c7c;
case 0x0c070c7eu: goto P_0c070c7e;
case 0x0c070c80u: goto P_0c070c80;
case 0x0c070c82u: goto P_0c070c82;
case 0x0c070c84u: goto P_0c070c84;
case 0x0c070c86u: goto P_0c070c86;
case 0x0c070c88u: goto P_0c070c88;
case 0x0c070c90u: goto P_0c070c90;
case 0x0c070c92u: goto P_0c070c92;
case 0x0c070c94u: goto P_0c070c94;
case 0x0c070c96u: goto P_0c070c96;
case 0x0c070c98u: goto P_0c070c98;
case 0x0c070c9au: goto P_0c070c9a;
case 0x0c070c9cu: goto P_0c070c9c;
case 0x0c070c9eu: goto P_0c070c9e;
case 0x0c070ca0u: goto P_0c070ca0;
case 0x0c070ca2u: goto P_0c070ca2;
case 0x0c070ca4u: goto P_0c070ca4;
case 0x0c070ca6u: goto P_0c070ca6;
case 0x0c070ca8u: goto P_0c070ca8;
case 0x0c070caau: goto P_0c070caa;
case 0x0c070cacu: goto P_0c070cac;
case 0x0c070caeu: goto P_0c070cae;
case 0x0c070cb0u: goto P_0c070cb0;
case 0x0c070cb2u: goto P_0c070cb2;
case 0x0c070cb4u: goto P_0c070cb4;
case 0x0c070cb6u: goto P_0c070cb6;
case 0x0c070cb8u: goto P_0c070cb8;
case 0x0c070cbau: goto P_0c070cba;
case 0x0c070cbcu: goto P_0c070cbc;
case 0x0c070cbeu: goto P_0c070cbe;
case 0x0c070cc0u: goto P_0c070cc0;
case 0x0c070cc2u: goto P_0c070cc2;
case 0x0c070cc4u: goto P_0c070cc4;
case 0x0c070cc6u: goto P_0c070cc6;
case 0x0c070cc8u: goto P_0c070cc8;
case 0x0c070ccau: goto P_0c070cca;
case 0x0c070cccu: goto P_0c070ccc;
case 0x0c070cceu: goto P_0c070cce;
case 0x0c070cd0u: goto P_0c070cd0;
case 0x0c070cd2u: goto P_0c070cd2;
case 0x0c070cd4u: goto P_0c070cd4;
case 0x0c070cd6u: goto P_0c070cd6;
case 0x0c070cd8u: goto P_0c070cd8;
case 0x0c070cdau: goto P_0c070cda;
case 0x0c070cdcu: goto P_0c070cdc;
case 0x0c070cdeu: goto P_0c070cde;
case 0x0c070ce0u: goto P_0c070ce0;
case 0x0c070ce2u: goto P_0c070ce2;
case 0x0c070ce4u: goto P_0c070ce4;
case 0x0c070ce6u: goto P_0c070ce6;
case 0x0c070ce8u: goto P_0c070ce8;
case 0x0c070ceau: goto P_0c070cea;
case 0x0c070cecu: goto P_0c070cec;
case 0x0c070ceeu: goto P_0c070cee;
case 0x0c070cf0u: goto P_0c070cf0;
case 0x0c070cf2u: goto P_0c070cf2;
case 0x0c070cf4u: goto P_0c070cf4;
case 0x0c070cf6u: goto P_0c070cf6;
case 0x0c070cf8u: goto P_0c070cf8;
case 0x0c070cfau: goto P_0c070cfa;
case 0x0c070cfcu: goto P_0c070cfc;
case 0x0c070cfeu: goto P_0c070cfe;
case 0x0c070d00u: goto P_0c070d00;
case 0x0c070d02u: goto P_0c070d02;
case 0x0c070d04u: goto P_0c070d04;
case 0x0c070d06u: goto P_0c070d06;
case 0x0c070d08u: goto P_0c070d08;
case 0x0c070d0au: goto P_0c070d0a;
case 0x0c070d0cu: goto P_0c070d0c;
case 0x0c070d0eu: goto P_0c070d0e;
case 0x0c070d10u: goto P_0c070d10;
case 0x0c070d12u: goto P_0c070d12;
case 0x0c070d14u: goto P_0c070d14;
case 0x0c070d16u: goto P_0c070d16;
case 0x0c070d18u: goto P_0c070d18;
case 0x0c070d1au: goto P_0c070d1a;
case 0x0c070d1cu: goto P_0c070d1c;
case 0x0c070d1eu: goto P_0c070d1e;
case 0x0c070d24u: goto P_0c070d24;
case 0x0c070d26u: goto P_0c070d26;
case 0x0c070d28u: goto P_0c070d28;
case 0x0c070d2au: goto P_0c070d2a;
case 0x0c070d2cu: goto P_0c070d2c;
case 0x0c070d2eu: goto P_0c070d2e;
case 0x0c070d30u: goto P_0c070d30;
case 0x0c070d32u: goto P_0c070d32;
case 0x0c070d34u: goto P_0c070d34;
case 0x0c070d36u: goto P_0c070d36;
case 0x0c070d38u: goto P_0c070d38;
case 0x0c070d3au: goto P_0c070d3a;
case 0x0c070d3cu: goto P_0c070d3c;
case 0x0c070d3eu: goto P_0c070d3e;
case 0x0c070d40u: goto P_0c070d40;
case 0x0c070d42u: goto P_0c070d42;
case 0x0c070d44u: goto P_0c070d44;
case 0x0c070d46u: goto P_0c070d46;
case 0x0c070d48u: goto P_0c070d48;
case 0x0c070d4au: goto P_0c070d4a;
case 0x0c070d4cu: goto P_0c070d4c;
case 0x0c070d4eu: goto P_0c070d4e;
case 0x0c070d50u: goto P_0c070d50;
case 0x0c070d52u: goto P_0c070d52;
case 0x0c070d54u: goto P_0c070d54;
case 0x0c070d56u: goto P_0c070d56;
case 0x0c070d58u: goto P_0c070d58;
case 0x0c070d5au: goto P_0c070d5a;
case 0x0c070d5cu: goto P_0c070d5c;
case 0x0c070d5eu: goto P_0c070d5e;
case 0x0c070d60u: goto P_0c070d60;
case 0x0c070d62u: goto P_0c070d62;
case 0x0c070d64u: goto P_0c070d64;
case 0x0c070d66u: goto P_0c070d66;
case 0x0c070d68u: goto P_0c070d68;
case 0x0c070d6au: goto P_0c070d6a;
case 0x0c070d70u: goto P_0c070d70;
case 0x0c070d72u: goto P_0c070d72;
case 0x0c070d74u: goto P_0c070d74;
case 0x0c070d76u: goto P_0c070d76;
case 0x0c070d78u: goto P_0c070d78;
case 0x0c070d7au: goto P_0c070d7a;
case 0x0c070d7cu: goto P_0c070d7c;
case 0x0c070d7eu: goto P_0c070d7e;
case 0x0c070d80u: goto P_0c070d80;
case 0x0c070d82u: goto P_0c070d82;
case 0x0c070d84u: goto P_0c070d84;
case 0x0c070d86u: goto P_0c070d86;
case 0x0c070d88u: goto P_0c070d88;
case 0x0c070d8au: goto P_0c070d8a;
case 0x0c070d8cu: goto P_0c070d8c;
case 0x0c070d8eu: goto P_0c070d8e;
case 0x0c070d90u: goto P_0c070d90;
case 0x0c070d92u: goto P_0c070d92;
case 0x0c070d94u: goto P_0c070d94;
case 0x0c070d96u: goto P_0c070d96;
case 0x0c070d98u: goto P_0c070d98;
case 0x0c070d9au: goto P_0c070d9a;
case 0x0c070d9cu: goto P_0c070d9c;
case 0x0c070d9eu: goto P_0c070d9e;
case 0x0c070da0u: goto P_0c070da0;
case 0x0c070da2u: goto P_0c070da2;
case 0x0c070da4u: goto P_0c070da4;
case 0x0c070da6u: goto P_0c070da6;
case 0x0c070da8u: goto P_0c070da8;
case 0x0c070db4u: goto P_0c070db4;
case 0x0c070db6u: goto P_0c070db6;
case 0x0c070db8u: goto P_0c070db8;
case 0x0c070dbau: goto P_0c070dba;
case 0x0c070dbcu: goto P_0c070dbc;
case 0x0c070dbeu: goto P_0c070dbe;
case 0x0c070dc0u: goto P_0c070dc0;
case 0x0c070dc2u: goto P_0c070dc2;
case 0x0c070dc4u: goto P_0c070dc4;
case 0x0c070dc6u: goto P_0c070dc6;
case 0x0c070dc8u: goto P_0c070dc8;
case 0x0c070dcau: goto P_0c070dca;
case 0x0c070dccu: goto P_0c070dcc;
case 0x0c070dceu: goto P_0c070dce;
case 0x0c070dd0u: goto P_0c070dd0;
case 0x0c070dd2u: goto P_0c070dd2;
case 0x0c070dd4u: goto P_0c070dd4;
case 0x0c070e06u: goto P_0c070e06;
case 0x0c070e08u: goto P_0c070e08;
case 0x0c070e0au: goto P_0c070e0a;
case 0x0c070e0cu: goto P_0c070e0c;
case 0x0c070e0eu: goto P_0c070e0e;
case 0x0c070e10u: goto P_0c070e10;
case 0x0c070e12u: goto P_0c070e12;
case 0x0c070e14u: goto P_0c070e14;
case 0x0c070e16u: goto P_0c070e16;
case 0x0c070e18u: goto P_0c070e18;
case 0x0c070e1au: goto P_0c070e1a;
case 0x0c070e1cu: goto P_0c070e1c;
case 0x0c070e1eu: goto P_0c070e1e;
case 0x0c070e20u: goto P_0c070e20;
case 0x0c070e22u: goto P_0c070e22;
case 0x0c070e24u: goto P_0c070e24;
case 0x0c070e26u: goto P_0c070e26;
case 0x0c070e28u: goto P_0c070e28;
case 0x0c070e2au: goto P_0c070e2a;
case 0x0c070e2cu: goto P_0c070e2c;
case 0x0c070e2eu: goto P_0c070e2e;
case 0x0c070e30u: goto P_0c070e30;
case 0x0c070e32u: goto P_0c070e32;
case 0x0c070e34u: goto P_0c070e34;
case 0x0c070e36u: goto P_0c070e36;
case 0x0c070e38u: goto P_0c070e38;
case 0x0c070e3au: goto P_0c070e3a;
case 0x0c070e3cu: goto P_0c070e3c;
case 0x0c070e3eu: goto P_0c070e3e;
case 0x0c070e40u: goto P_0c070e40;
case 0x0c070e42u: goto P_0c070e42;
case 0x0c070e44u: goto P_0c070e44;
case 0x0c070e46u: goto P_0c070e46;
case 0x0c070e48u: goto P_0c070e48;
case 0x0c070e4au: goto P_0c070e4a;
case 0x0c070e4cu: goto P_0c070e4c;
case 0x0c070e4eu: goto P_0c070e4e;
case 0x0c070e50u: goto P_0c070e50;
case 0x0c070e52u: goto P_0c070e52;
case 0x0c070e54u: goto P_0c070e54;
case 0x0c070e56u: goto P_0c070e56;
case 0x0c070e58u: goto P_0c070e58;
case 0x0c070e5au: goto P_0c070e5a;
case 0x0c070e5cu: goto P_0c070e5c;
case 0x0c070e5eu: goto P_0c070e5e;
case 0x0c070e60u: goto P_0c070e60;
case 0x0c070e62u: goto P_0c070e62;
case 0x0c070e64u: goto P_0c070e64;
case 0x0c070e66u: goto P_0c070e66;
case 0x0c070e68u: goto P_0c070e68;
case 0x0c070e6au: goto P_0c070e6a;
case 0x0c070e6cu: goto P_0c070e6c;
case 0x0c070e6eu: goto P_0c070e6e;
case 0x0c070e70u: goto P_0c070e70;
case 0x0c070e72u: goto P_0c070e72;
case 0x0c070e74u: goto P_0c070e74;
case 0x0c070e76u: goto P_0c070e76;
case 0x0c070e78u: goto P_0c070e78;
case 0x0c070e7au: goto P_0c070e7a;
case 0x0c070e7cu: goto P_0c070e7c;
case 0x0c070e7eu: goto P_0c070e7e;
case 0x0c070e80u: goto P_0c070e80;
case 0x0c070e82u: goto P_0c070e82;
case 0x0c070e84u: goto P_0c070e84;
case 0x0c070e86u: goto P_0c070e86;
case 0x0c070e88u: goto P_0c070e88;
case 0x0c070e8au: goto P_0c070e8a;
case 0x0c070e8cu: goto P_0c070e8c;
case 0x0c070e8eu: goto P_0c070e8e;
case 0x0c070e90u: goto P_0c070e90;
case 0x0c070e92u: goto P_0c070e92;
case 0x0c070e94u: goto P_0c070e94;
case 0x0c070e96u: goto P_0c070e96;
case 0x0c070e98u: goto P_0c070e98;
case 0x0c070e9au: goto P_0c070e9a;
case 0x0c070e9cu: goto P_0c070e9c;
case 0x0c070e9eu: goto P_0c070e9e;
case 0x0c070ea0u: goto P_0c070ea0;
case 0x0c070ea2u: goto P_0c070ea2;
case 0x0c070ea4u: goto P_0c070ea4;
case 0x0c070ea6u: goto P_0c070ea6;
case 0x0c070ea8u: goto P_0c070ea8;
case 0x0c070eaau: goto P_0c070eaa;
case 0x0c070eacu: goto P_0c070eac;
case 0x0c070eaeu: goto P_0c070eae;
case 0x0c070eb0u: goto P_0c070eb0;
case 0x0c070eb2u: goto P_0c070eb2;
case 0x0c070eb4u: goto P_0c070eb4;
case 0x0c070eb6u: goto P_0c070eb6;
case 0x0c070eb8u: goto P_0c070eb8;
case 0x0c070ebau: goto P_0c070eba;
case 0x0c070ebcu: goto P_0c070ebc;
case 0x0c070ebeu: goto P_0c070ebe;
case 0x0c070ec0u: goto P_0c070ec0;
case 0x0c070ec2u: goto P_0c070ec2;
case 0x0c070ec4u: goto P_0c070ec4;
case 0x0c070ec6u: goto P_0c070ec6;
case 0x0c070ec8u: goto P_0c070ec8;
case 0x0c070ecau: goto P_0c070eca;
case 0x0c070eccu: goto P_0c070ecc;
case 0x0c070eceu: goto P_0c070ece;
case 0x0c070ed0u: goto P_0c070ed0;
case 0x0c070ed2u: goto P_0c070ed2;
case 0x0c070ed4u: goto P_0c070ed4;
case 0x0c070ed6u: goto P_0c070ed6;
case 0x0c070ed8u: goto P_0c070ed8;
case 0x0c070edau: goto P_0c070eda;
case 0x0c070edcu: goto P_0c070edc;
case 0x0c070edeu: goto P_0c070ede;
case 0x0c070ee0u: goto P_0c070ee0;
case 0x0c070ee2u: goto P_0c070ee2;
case 0x0c070ee4u: goto P_0c070ee4;
case 0x0c070ee6u: goto P_0c070ee6;
case 0x0c070ee8u: goto P_0c070ee8;
case 0x0c070eeau: goto P_0c070eea;
case 0x0c070eecu: goto P_0c070eec;
case 0x0c070eeeu: goto P_0c070eee;
case 0x0c070ef4u: goto P_0c070ef4;
case 0x0c070ef6u: goto P_0c070ef6;
case 0x0c070ef8u: goto P_0c070ef8;
case 0x0c070efau: goto P_0c070efa;
case 0x0c070efcu: goto P_0c070efc;
case 0x0c070efeu: goto P_0c070efe;
case 0x0c070f00u: goto P_0c070f00;
case 0x0c070f02u: goto P_0c070f02;
case 0x0c070f04u: goto P_0c070f04;
case 0x0c070f06u: goto P_0c070f06;
case 0x0c070f08u: goto P_0c070f08;
case 0x0c070f0au: goto P_0c070f0a;
case 0x0c070f0cu: goto P_0c070f0c;
case 0x0c070f0eu: goto P_0c070f0e;
case 0x0c070f10u: goto P_0c070f10;
case 0x0c070f12u: goto P_0c070f12;
case 0x0c070f14u: goto P_0c070f14;
case 0x0c070f16u: goto P_0c070f16;
case 0x0c070f18u: goto P_0c070f18;
case 0x0c070f1au: goto P_0c070f1a;
case 0x0c070f1cu: goto P_0c070f1c;
case 0x0c070f1eu: goto P_0c070f1e;
case 0x0c070f20u: goto P_0c070f20;
case 0x0c070f22u: goto P_0c070f22;
case 0x0c070f24u: goto P_0c070f24;
case 0x0c070f26u: goto P_0c070f26;
case 0x0c070f28u: goto P_0c070f28;
case 0x0c070f2au: goto P_0c070f2a;
case 0x0c070f2cu: goto P_0c070f2c;
case 0x0c070f2eu: goto P_0c070f2e;
case 0x0c070f30u: goto P_0c070f30;
case 0x0c070f32u: goto P_0c070f32;
case 0x0c070f34u: goto P_0c070f34;
case 0x0c070f36u: goto P_0c070f36;
case 0x0c070f38u: goto P_0c070f38;
case 0x0c070f3au: goto P_0c070f3a;
case 0x0c070f40u: goto P_0c070f40;
case 0x0c070f42u: goto P_0c070f42;
case 0x0c070f44u: goto P_0c070f44;
case 0x0c070f46u: goto P_0c070f46;
case 0x0c070f48u: goto P_0c070f48;
case 0x0c070f4au: goto P_0c070f4a;
case 0x0c070f4cu: goto P_0c070f4c;
case 0x0c070f4eu: goto P_0c070f4e;
case 0x0c070f50u: goto P_0c070f50;
case 0x0c070f52u: goto P_0c070f52;
case 0x0c070f54u: goto P_0c070f54;
case 0x0c070f56u: goto P_0c070f56;
case 0x0c070f58u: goto P_0c070f58;
case 0x0c070f5au: goto P_0c070f5a;
case 0x0c070f5cu: goto P_0c070f5c;
case 0x0c070f5eu: goto P_0c070f5e;
case 0x0c070f60u: goto P_0c070f60;
case 0x0c070f62u: goto P_0c070f62;
case 0x0c070f64u: goto P_0c070f64;
case 0x0c070f66u: goto P_0c070f66;
case 0x0c070f68u: goto P_0c070f68;
case 0x0c070f6au: goto P_0c070f6a;
case 0x0c070f6cu: goto P_0c070f6c;
case 0x0c070f6eu: goto P_0c070f6e;
case 0x0c070f70u: goto P_0c070f70;
case 0x0c070f72u: goto P_0c070f72;
case 0x0c070f74u: goto P_0c070f74;
case 0x0c070f76u: goto P_0c070f76;
case 0x0c070f78u: goto P_0c070f78;
case 0x0c070f84u: goto P_0c070f84;
case 0x0c070f86u: goto P_0c070f86;
case 0x0c070f88u: goto P_0c070f88;
case 0x0c070f8au: goto P_0c070f8a;
case 0x0c070f8cu: goto P_0c070f8c;
case 0x0c070f8eu: goto P_0c070f8e;
case 0x0c070f90u: goto P_0c070f90;
case 0x0c070f92u: goto P_0c070f92;
case 0x0c070f94u: goto P_0c070f94;
case 0x0c070f96u: goto P_0c070f96;
case 0x0c070f98u: goto P_0c070f98;
case 0x0c070f9au: goto P_0c070f9a;
case 0x0c070f9cu: goto P_0c070f9c;
case 0x0c070f9eu: goto P_0c070f9e;
case 0x0c070fa0u: goto P_0c070fa0;
case 0x0c070fa2u: goto P_0c070fa2;
case 0x0c070fa4u: goto P_0c070fa4;
case 0x0c070fd6u: goto P_0c070fd6;
case 0x0c070fd8u: goto P_0c070fd8;
case 0x0c070fdau: goto P_0c070fda;
case 0x0c070fdcu: goto P_0c070fdc;
case 0x0c070fdeu: goto P_0c070fde;
case 0x0c070fe0u: goto P_0c070fe0;
case 0x0c070fe2u: goto P_0c070fe2;
case 0x0c070fe4u: goto P_0c070fe4;
case 0x0c070fe6u: goto P_0c070fe6;
case 0x0c070fe8u: goto P_0c070fe8;
case 0x0c070feau: goto P_0c070fea;
case 0x0c070fecu: goto P_0c070fec;
case 0x0c070feeu: goto P_0c070fee;
case 0x0c070ff0u: goto P_0c070ff0;
case 0x0c070ff2u: goto P_0c070ff2;
case 0x0c070ff4u: goto P_0c070ff4;
case 0x0c070ff6u: goto P_0c070ff6;
case 0x0c070ff8u: goto P_0c070ff8;
case 0x0c070ffau: goto P_0c070ffa;
case 0x0c070ffcu: goto P_0c070ffc;
case 0x0c070ffeu: goto P_0c070ffe;
case 0x0c071000u: goto P_0c071000;
case 0x0c071002u: goto P_0c071002;
case 0x0c071004u: goto P_0c071004;
case 0x0c071006u: goto P_0c071006;
case 0x0c071008u: goto P_0c071008;
case 0x0c07100au: goto P_0c07100a;
case 0x0c07100cu: goto P_0c07100c;
case 0x0c07100eu: goto P_0c07100e;
case 0x0c071010u: goto P_0c071010;
case 0x0c071012u: goto P_0c071012;
case 0x0c071014u: goto P_0c071014;
case 0x0c071016u: goto P_0c071016;
case 0x0c071018u: goto P_0c071018;
case 0x0c07101au: goto P_0c07101a;
case 0x0c07101cu: goto P_0c07101c;
case 0x0c07101eu: goto P_0c07101e;
case 0x0c071020u: goto P_0c071020;
case 0x0c071022u: goto P_0c071022;
case 0x0c071024u: goto P_0c071024;
case 0x0c071026u: goto P_0c071026;
case 0x0c071028u: goto P_0c071028;
case 0x0c07102au: goto P_0c07102a;
case 0x0c07102cu: goto P_0c07102c;
case 0x0c07102eu: goto P_0c07102e;
case 0x0c071030u: goto P_0c071030;
case 0x0c071032u: goto P_0c071032;
case 0x0c071034u: goto P_0c071034;
case 0x0c071036u: goto P_0c071036;
case 0x0c071038u: goto P_0c071038;
case 0x0c07103au: goto P_0c07103a;
case 0x0c07103cu: goto P_0c07103c;
case 0x0c07103eu: goto P_0c07103e;
case 0x0c071040u: goto P_0c071040;
case 0x0c071042u: goto P_0c071042;
case 0x0c071044u: goto P_0c071044;
case 0x0c071046u: goto P_0c071046;
case 0x0c071048u: goto P_0c071048;
case 0x0c07104au: goto P_0c07104a;
case 0x0c07104cu: goto P_0c07104c;
case 0x0c07104eu: goto P_0c07104e;
case 0x0c071050u: goto P_0c071050;
case 0x0c071052u: goto P_0c071052;
case 0x0c071054u: goto P_0c071054;
case 0x0c071056u: goto P_0c071056;
case 0x0c071058u: goto P_0c071058;
case 0x0c07105au: goto P_0c07105a;
case 0x0c07105cu: goto P_0c07105c;
case 0x0c07105eu: goto P_0c07105e;
case 0x0c071060u: goto P_0c071060;
case 0x0c071062u: goto P_0c071062;
case 0x0c071064u: goto P_0c071064;
case 0x0c071066u: goto P_0c071066;
case 0x0c071068u: goto P_0c071068;
case 0x0c07106au: goto P_0c07106a;
case 0x0c07106cu: goto P_0c07106c;
case 0x0c07106eu: goto P_0c07106e;
case 0x0c071070u: goto P_0c071070;
case 0x0c071072u: goto P_0c071072;
case 0x0c071074u: goto P_0c071074;
case 0x0c071076u: goto P_0c071076;
case 0x0c071078u: goto P_0c071078;
case 0x0c07107au: goto P_0c07107a;
case 0x0c07107cu: goto P_0c07107c;
case 0x0c07107eu: goto P_0c07107e;
case 0x0c071080u: goto P_0c071080;
case 0x0c071082u: goto P_0c071082;
case 0x0c071084u: goto P_0c071084;
case 0x0c071086u: goto P_0c071086;
case 0x0c071088u: goto P_0c071088;
case 0x0c07108au: goto P_0c07108a;
case 0x0c07108cu: goto P_0c07108c;
case 0x0c07108eu: goto P_0c07108e;
case 0x0c071090u: goto P_0c071090;
case 0x0c071092u: goto P_0c071092;
case 0x0c071094u: goto P_0c071094;
case 0x0c071096u: goto P_0c071096;
case 0x0c071098u: goto P_0c071098;
case 0x0c07109au: goto P_0c07109a;
case 0x0c07109cu: goto P_0c07109c;
case 0x0c07109eu: goto P_0c07109e;
case 0x0c0710a0u: goto P_0c0710a0;
case 0x0c0710a2u: goto P_0c0710a2;
case 0x0c0710a4u: goto P_0c0710a4;
case 0x0c0710a6u: goto P_0c0710a6;
case 0x0c0710a8u: goto P_0c0710a8;
case 0x0c0710aau: goto P_0c0710aa;
case 0x0c0710acu: goto P_0c0710ac;
case 0x0c0710aeu: goto P_0c0710ae;
case 0x0c0710b0u: goto P_0c0710b0;
case 0x0c0710b2u: goto P_0c0710b2;
case 0x0c0710b4u: goto P_0c0710b4;
case 0x0c0710b6u: goto P_0c0710b6;
case 0x0c0710b8u: goto P_0c0710b8;
case 0x0c0710bau: goto P_0c0710ba;
case 0x0c0710bcu: goto P_0c0710bc;
case 0x0c0710beu: goto P_0c0710be;
case 0x0c0710c0u: goto P_0c0710c0;
case 0x0c0710c8u: goto P_0c0710c8;
case 0x0c0710cau: goto P_0c0710ca;
case 0x0c0710ccu: goto P_0c0710cc;
case 0x0c0710ceu: goto P_0c0710ce;
case 0x0c0710d0u: goto P_0c0710d0;
case 0x0c0710d2u: goto P_0c0710d2;
case 0x0c0710d4u: goto P_0c0710d4;
case 0x0c0710d6u: goto P_0c0710d6;
case 0x0c0710d8u: goto P_0c0710d8;
case 0x0c0710dau: goto P_0c0710da;
case 0x0c0710dcu: goto P_0c0710dc;
case 0x0c0710deu: goto P_0c0710de;
case 0x0c0710e0u: goto P_0c0710e0;
case 0x0c0710e2u: goto P_0c0710e2;
case 0x0c0710e4u: goto P_0c0710e4;
case 0x0c0710e6u: goto P_0c0710e6;
case 0x0c0710e8u: goto P_0c0710e8;
case 0x0c0710eau: goto P_0c0710ea;
case 0x0c0710ecu: goto P_0c0710ec;
case 0x0c0710eeu: goto P_0c0710ee;
case 0x0c0710f0u: goto P_0c0710f0;
case 0x0c0710f2u: goto P_0c0710f2;
case 0x0c0710f4u: goto P_0c0710f4;
case 0x0c0710f6u: goto P_0c0710f6;
case 0x0c0710f8u: goto P_0c0710f8;
case 0x0c0710fau: goto P_0c0710fa;
case 0x0c0710fcu: goto P_0c0710fc;
case 0x0c0710feu: goto P_0c0710fe;
case 0x0c071100u: goto P_0c071100;
case 0x0c071102u: goto P_0c071102;
case 0x0c071104u: goto P_0c071104;
case 0x0c071106u: goto P_0c071106;
case 0x0c071108u: goto P_0c071108;
case 0x0c07110au: goto P_0c07110a;
case 0x0c07110cu: goto P_0c07110c;
case 0x0c07110eu: goto P_0c07110e;
case 0x0c071110u: goto P_0c071110;
case 0x0c071112u: goto P_0c071112;
case 0x0c071114u: goto P_0c071114;
case 0x0c071116u: goto P_0c071116;
case 0x0c071118u: goto P_0c071118;
case 0x0c07111au: goto P_0c07111a;
case 0x0c07111cu: goto P_0c07111c;
case 0x0c07111eu: goto P_0c07111e;
case 0x0c071120u: goto P_0c071120;
case 0x0c071122u: goto P_0c071122;
case 0x0c071124u: goto P_0c071124;
case 0x0c071126u: goto P_0c071126;
case 0x0c071128u: goto P_0c071128;
case 0x0c07112au: goto P_0c07112a;
case 0x0c07112cu: goto P_0c07112c;
case 0x0c07112eu: goto P_0c07112e;
case 0x0c071130u: goto P_0c071130;
case 0x0c071132u: goto P_0c071132;
case 0x0c071134u: goto P_0c071134;
case 0x0c071136u: goto P_0c071136;
case 0x0c071138u: goto P_0c071138;
case 0x0c07113au: goto P_0c07113a;
case 0x0c07113cu: goto P_0c07113c;
case 0x0c07113eu: goto P_0c07113e;
case 0x0c071890u: goto P_0c071890;
case 0x0c071892u: goto P_0c071892;
case 0x0c071894u: goto P_0c071894;
case 0x0c071896u: goto P_0c071896;
case 0x0c071898u: goto P_0c071898;
case 0x0c07189au: goto P_0c07189a;
case 0x0c07189cu: goto P_0c07189c;
case 0x0c07189eu: goto P_0c07189e;
case 0x0c0718a0u: goto P_0c0718a0;
case 0x0c0718a2u: goto P_0c0718a2;
case 0x0c0718a4u: goto P_0c0718a4;
case 0x0c0718a6u: goto P_0c0718a6;
case 0x0c0718a8u: goto P_0c0718a8;
case 0x0c0718aau: goto P_0c0718aa;
case 0x0c0718acu: goto P_0c0718ac;
case 0x0c0718aeu: goto P_0c0718ae;
case 0x0c0718b0u: goto P_0c0718b0;
case 0x0c0718b2u: goto P_0c0718b2;
case 0x0c0718b4u: goto P_0c0718b4;
case 0x0c0718b6u: goto P_0c0718b6;
case 0x0c0718b8u: goto P_0c0718b8;
case 0x0c0718bau: goto P_0c0718ba;
case 0x0c0718bcu: goto P_0c0718bc;
case 0x0c0718beu: goto P_0c0718be;
case 0x0c0718c0u: goto P_0c0718c0;
case 0x0c0718c2u: goto P_0c0718c2;
case 0x0c0718c4u: goto P_0c0718c4;
case 0x0c0718c6u: goto P_0c0718c6;
case 0x0c0718c8u: goto P_0c0718c8;
case 0x0c0718cau: goto P_0c0718ca;
case 0x0c0718ccu: goto P_0c0718cc;
case 0x0c0718ceu: goto P_0c0718ce;
case 0x0c0718d0u: goto P_0c0718d0;
case 0x0c0718d2u: goto P_0c0718d2;
case 0x0c0718d4u: goto P_0c0718d4;
case 0x0c0718d6u: goto P_0c0718d6;
case 0x0c0718d8u: goto P_0c0718d8;
case 0x0c0718dau: goto P_0c0718da;
case 0x0c0718dcu: goto P_0c0718dc;
case 0x0c0718deu: goto P_0c0718de;
case 0x0c0718e0u: goto P_0c0718e0;
case 0x0c0718e2u: goto P_0c0718e2;
case 0x0c0718e4u: goto P_0c0718e4;
case 0x0c0718e6u: goto P_0c0718e6;
case 0x0c0718e8u: goto P_0c0718e8;
case 0x0c0718eau: goto P_0c0718ea;
case 0x0c0718ecu: goto P_0c0718ec;
case 0x0c0718eeu: goto P_0c0718ee;
case 0x0c0718f0u: goto P_0c0718f0;
case 0x0c0718f2u: goto P_0c0718f2;
case 0x0c0718f4u: goto P_0c0718f4;
case 0x0c0718f6u: goto P_0c0718f6;
case 0x0c0718f8u: goto P_0c0718f8;
case 0x0c0718fau: goto P_0c0718fa;
case 0x0c0718fcu: goto P_0c0718fc;
case 0x0c0718feu: goto P_0c0718fe;
case 0x0c071900u: goto P_0c071900;
case 0x0c071902u: goto P_0c071902;
case 0x0c071904u: goto P_0c071904;
case 0x0c071906u: goto P_0c071906;
case 0x0c071908u: goto P_0c071908;
case 0x0c07190au: goto P_0c07190a;
case 0x0c07190cu: goto P_0c07190c;
case 0x0c07190eu: goto P_0c07190e;
case 0x0c071910u: goto P_0c071910;
case 0x0c071912u: goto P_0c071912;
case 0x0c071914u: goto P_0c071914;
case 0x0c071916u: goto P_0c071916;
case 0x0c071918u: goto P_0c071918;
case 0x0c07191au: goto P_0c07191a;
case 0x0c07191cu: goto P_0c07191c;
case 0x0c07191eu: goto P_0c07191e;
case 0x0c071920u: goto P_0c071920;
case 0x0c071dc4u: goto P_0c071dc4;
case 0x0c071dc6u: goto P_0c071dc6;
case 0x0c071dc8u: goto P_0c071dc8;
case 0x0c071dcau: goto P_0c071dca;
case 0x0c071dccu: goto P_0c071dcc;
case 0x0c071dceu: goto P_0c071dce;
case 0x0c071dd0u: goto P_0c071dd0;
case 0x0c071dd2u: goto P_0c071dd2;
case 0x0c071dd4u: goto P_0c071dd4;
case 0x0c071dd6u: goto P_0c071dd6;
case 0x0c071dd8u: goto P_0c071dd8;
case 0x0c071ddau: goto P_0c071dda;
case 0x0c071ddcu: goto P_0c071ddc;
case 0x0c071ddeu: goto P_0c071dde;
case 0x0c071de0u: goto P_0c071de0;
case 0x0c071de2u: goto P_0c071de2;
case 0x0c071de4u: goto P_0c071de4;
case 0x0c071de6u: goto P_0c071de6;
case 0x0c071de8u: goto P_0c071de8;
case 0x0c071deau: goto P_0c071dea;
case 0x0c071decu: goto P_0c071dec;
case 0x0c071deeu: goto P_0c071dee;
case 0x0c071df0u: goto P_0c071df0;
case 0x0c071df2u: goto P_0c071df2;
case 0x0c071df4u: goto P_0c071df4;
case 0x0c071df6u: goto P_0c071df6;
case 0x0c071df8u: goto P_0c071df8;
case 0x0c071dfau: goto P_0c071dfa;
case 0x0c071dfcu: goto P_0c071dfc;
case 0x0c071dfeu: goto P_0c071dfe;
case 0x0c071e00u: goto P_0c071e00;
case 0x0c071e02u: goto P_0c071e02;
case 0x0c071e04u: goto P_0c071e04;
case 0x0c071e06u: goto P_0c071e06;
case 0x0c071e08u: goto P_0c071e08;
case 0x0c071e0au: goto P_0c071e0a;
case 0x0c071e0cu: goto P_0c071e0c;
case 0x0c071e0eu: goto P_0c071e0e;
case 0x0c071e10u: goto P_0c071e10;
case 0x0c071e12u: goto P_0c071e12;
case 0x0c071e14u: goto P_0c071e14;
case 0x0c071e16u: goto P_0c071e16;
case 0x0c071e18u: goto P_0c071e18;
case 0x0c071e1au: goto P_0c071e1a;
case 0x0c071e1cu: goto P_0c071e1c;
case 0x0c071e1eu: goto P_0c071e1e;
case 0x0c071e20u: goto P_0c071e20;
case 0x0c071e22u: goto P_0c071e22;
case 0x0c071e24u: goto P_0c071e24;
case 0x0c071e26u: goto P_0c071e26;
case 0x0c071e28u: goto P_0c071e28;
case 0x0c071e2au: goto P_0c071e2a;
case 0x0c071e2cu: goto P_0c071e2c;
case 0x0c071e2eu: goto P_0c071e2e;
case 0x0c071e30u: goto P_0c071e30;
case 0x0c071e32u: goto P_0c071e32;
case 0x0c071e34u: goto P_0c071e34;
case 0x0c071e36u: goto P_0c071e36;
case 0x0c071e38u: goto P_0c071e38;
case 0x0c071e3au: goto P_0c071e3a;
case 0x0c071e3cu: goto P_0c071e3c;
case 0x0c071e3eu: goto P_0c071e3e;
case 0x0c071e40u: goto P_0c071e40;
case 0x0c071e42u: goto P_0c071e42;
case 0x0c071e44u: goto P_0c071e44;
case 0x0c071e46u: goto P_0c071e46;
case 0x0c071e48u: goto P_0c071e48;
case 0x0c071e4au: goto P_0c071e4a;
case 0x0c071e4cu: goto P_0c071e4c;
case 0x0c071e4eu: goto P_0c071e4e;
case 0x0c071e50u: goto P_0c071e50;
case 0x0c071e52u: goto P_0c071e52;
case 0x0c071e54u: goto P_0c071e54;
case 0x0c071e56u: goto P_0c071e56;
case 0x0c071e58u: goto P_0c071e58;
case 0x0c071e5au: goto P_0c071e5a;
case 0x0c071e5cu: goto P_0c071e5c;
case 0x0c071e64u: goto P_0c071e64;
case 0x0c071e66u: goto P_0c071e66;
case 0x0c071e68u: goto P_0c071e68;
case 0x0c071e6au: goto P_0c071e6a;
case 0x0c071e6cu: goto P_0c071e6c;
case 0x0c071e6eu: goto P_0c071e6e;
case 0x0c071e70u: goto P_0c071e70;
case 0x0c071e72u: goto P_0c071e72;
case 0x0c071e74u: goto P_0c071e74;
case 0x0c071e76u: goto P_0c071e76;
case 0x0c071e78u: goto P_0c071e78;
case 0x0c071e7au: goto P_0c071e7a;
case 0x0c071e7cu: goto P_0c071e7c;
case 0x0c071e7eu: goto P_0c071e7e;
case 0x0c071e80u: goto P_0c071e80;
case 0x0c071e82u: goto P_0c071e82;
case 0x0c071e84u: goto P_0c071e84;
case 0x0c071e86u: goto P_0c071e86;
case 0x0c071e88u: goto P_0c071e88;
case 0x0c071e8au: goto P_0c071e8a;
case 0x0c071e8cu: goto P_0c071e8c;
case 0x0c071e8eu: goto P_0c071e8e;
case 0x0c071e90u: goto P_0c071e90;
case 0x0c071e92u: goto P_0c071e92;
case 0x0c071e94u: goto P_0c071e94;
case 0x0c071e96u: goto P_0c071e96;
case 0x0c071e98u: goto P_0c071e98;
case 0x0c071e9au: goto P_0c071e9a;
case 0x0c071e9cu: goto P_0c071e9c;
case 0x0c071e9eu: goto P_0c071e9e;
case 0x0c071ea0u: goto P_0c071ea0;
case 0x0c071ea2u: goto P_0c071ea2;
case 0x0c071ea4u: goto P_0c071ea4;
case 0x0c071ea6u: goto P_0c071ea6;
case 0x0c071ea8u: goto P_0c071ea8;
case 0x0c071eaau: goto P_0c071eaa;
case 0x0c071eacu: goto P_0c071eac;
case 0x0c071eaeu: goto P_0c071eae;
case 0x0c071eb0u: goto P_0c071eb0;
case 0x0c071eb2u: goto P_0c071eb2;
case 0x0c071eb4u: goto P_0c071eb4;
case 0x0c071eb6u: goto P_0c071eb6;
case 0x0c071eb8u: goto P_0c071eb8;
case 0x0c071ebau: goto P_0c071eba;
case 0x0c071ebcu: goto P_0c071ebc;
case 0x0c071ebeu: goto P_0c071ebe;
case 0x0c071ec0u: goto P_0c071ec0;
case 0x0c071ec2u: goto P_0c071ec2;
case 0x0c071ec4u: goto P_0c071ec4;
case 0x0c071ec6u: goto P_0c071ec6;
case 0x0c071ec8u: goto P_0c071ec8;
case 0x0c071ecau: goto P_0c071eca;
case 0x0c071eccu: goto P_0c071ecc;
case 0x0c071eceu: goto P_0c071ece;
case 0x0c071ed0u: goto P_0c071ed0;
case 0x0c071ed2u: goto P_0c071ed2;
case 0x0c071ed4u: goto P_0c071ed4;
case 0x0c071ed6u: goto P_0c071ed6;
case 0x0c071ed8u: goto P_0c071ed8;
case 0x0c071edau: goto P_0c071eda;
case 0x0c071edcu: goto P_0c071edc;
case 0x0c071edeu: goto P_0c071ede;
case 0x0c071ee0u: goto P_0c071ee0;
case 0x0c071ee2u: goto P_0c071ee2;
case 0x0c071ee4u: goto P_0c071ee4;
case 0x0c071ee6u: goto P_0c071ee6;
case 0x0c071ee8u: goto P_0c071ee8;
case 0x0c071eeau: goto P_0c071eea;
case 0x0c071eecu: goto P_0c071eec;
case 0x0c071eeeu: goto P_0c071eee;
case 0x0c071ef0u: goto P_0c071ef0;
case 0x0c071ef2u: goto P_0c071ef2;
case 0x0c071ef4u: goto P_0c071ef4;
case 0x0c071ef6u: goto P_0c071ef6;
case 0x0c071ef8u: goto P_0c071ef8;
case 0x0c071efau: goto P_0c071efa;
case 0x0c071efcu: goto P_0c071efc;
case 0x0c071efeu: goto P_0c071efe;
case 0x0c071f00u: goto P_0c071f00;
case 0x0c071f02u: goto P_0c071f02;
case 0x0c071f04u: goto P_0c071f04;
case 0x0c071f06u: goto P_0c071f06;
case 0x0c071f08u: goto P_0c071f08;
case 0x0c071f0au: goto P_0c071f0a;
case 0x0c071f0cu: goto P_0c071f0c;
case 0x0c071f0eu: goto P_0c071f0e;
case 0x0c071f10u: goto P_0c071f10;
case 0x0c071f12u: goto P_0c071f12;
case 0x0c071f14u: goto P_0c071f14;
case 0x0c071f16u: goto P_0c071f16;
case 0x0c071f18u: goto P_0c071f18;
case 0x0c071f1au: goto P_0c071f1a;
case 0x0c071f1cu: goto P_0c071f1c;
case 0x0c071f1eu: goto P_0c071f1e;
case 0x0c071f20u: goto P_0c071f20;
case 0x0c071f22u: goto P_0c071f22;
case 0x0c071f24u: goto P_0c071f24;
case 0x0c071f26u: goto P_0c071f26;
case 0x0c071f28u: goto P_0c071f28;
case 0x0c071f2au: goto P_0c071f2a;
case 0x0c071f2cu: goto P_0c071f2c;
case 0x0c071f2eu: goto P_0c071f2e;
case 0x0c071f30u: goto P_0c071f30;
case 0x0c071f32u: goto P_0c071f32;
case 0x0c071f34u: goto P_0c071f34;
case 0x0c071f36u: goto P_0c071f36;
case 0x0c071f38u: goto P_0c071f38;
case 0x0c071f3au: goto P_0c071f3a;
case 0x0c071f3cu: goto P_0c071f3c;
case 0x0c071f3eu: goto P_0c071f3e;
case 0x0c071f40u: goto P_0c071f40;
case 0x0c071f42u: goto P_0c071f42;
case 0x0c071f44u: goto P_0c071f44;
case 0x0c071f46u: goto P_0c071f46;
case 0x0c071f48u: goto P_0c071f48;
case 0x0c071f4au: goto P_0c071f4a;
case 0x0c071f4cu: goto P_0c071f4c;
case 0x0c071f4eu: goto P_0c071f4e;
case 0x0c071f50u: goto P_0c071f50;
case 0x0c071f52u: goto P_0c071f52;
case 0x0c071f54u: goto P_0c071f54;
case 0x0c071f56u: goto P_0c071f56;
case 0x0c071f58u: goto P_0c071f58;
case 0x0c071f5au: goto P_0c071f5a;
case 0x0c071f5cu: goto P_0c071f5c;
case 0x0c071f5eu: goto P_0c071f5e;
case 0x0c071f60u: goto P_0c071f60;
case 0x0c071f62u: goto P_0c071f62;
case 0x0c071f64u: goto P_0c071f64;
case 0x0c071f66u: goto P_0c071f66;
case 0x0c071f68u: goto P_0c071f68;
case 0x0c071f6au: goto P_0c071f6a;
case 0x0c071f6cu: goto P_0c071f6c;
case 0x0c071f6eu: goto P_0c071f6e;
case 0x0c071f70u: goto P_0c071f70;
case 0x0c071f72u: goto P_0c071f72;
case 0x0c071f74u: goto P_0c071f74;
case 0x0c071f76u: goto P_0c071f76;
case 0x0c071f78u: goto P_0c071f78;
case 0x0c071f7au: goto P_0c071f7a;
case 0x0c071f7cu: goto P_0c071f7c;
case 0x0c071f7eu: goto P_0c071f7e;
case 0x0c071f80u: goto P_0c071f80;
case 0x0c071f82u: goto P_0c071f82;
case 0x0c071f84u: goto P_0c071f84;
case 0x0c071f86u: goto P_0c071f86;
case 0x0c071f88u: goto P_0c071f88;
case 0x0c071f8au: goto P_0c071f8a;
case 0x0c071f8cu: goto P_0c071f8c;
case 0x0c071f8eu: goto P_0c071f8e;
case 0x0c071f90u: goto P_0c071f90;
case 0x0c071f92u: goto P_0c071f92;
case 0x0c071f94u: goto P_0c071f94;
case 0x0c071f96u: goto P_0c071f96;
case 0x0c071f98u: goto P_0c071f98;
case 0x0c071f9au: goto P_0c071f9a;
case 0x0c071f9cu: goto P_0c071f9c;
case 0x0c071f9eu: goto P_0c071f9e;
case 0x0c071fa0u: goto P_0c071fa0;
case 0x0c071fa2u: goto P_0c071fa2;
case 0x0c071fa4u: goto P_0c071fa4;
case 0x0c071fa6u: goto P_0c071fa6;
case 0x0c071fa8u: goto P_0c071fa8;
case 0x0c071faau: goto P_0c071faa;
case 0x0c071facu: goto P_0c071fac;
case 0x0c071faeu: goto P_0c071fae;
case 0x0c071fb0u: goto P_0c071fb0;
case 0x0c071fb2u: goto P_0c071fb2;
case 0x0c071fb4u: goto P_0c071fb4;
case 0x0c071fb6u: goto P_0c071fb6;
case 0x0c071fb8u: goto P_0c071fb8;
case 0x0c071fbau: goto P_0c071fba;
case 0x0c071fbcu: goto P_0c071fbc;
case 0x0c071fbeu: goto P_0c071fbe;
case 0x0c071fc0u: goto P_0c071fc0;
case 0x0c071fc2u: goto P_0c071fc2;
case 0x0c071fc4u: goto P_0c071fc4;
case 0x0c071fc6u: goto P_0c071fc6;
case 0x0c071fc8u: goto P_0c071fc8;
case 0x0c071fcau: goto P_0c071fca;
case 0x0c071fccu: goto P_0c071fcc;
case 0x0c071fd4u: goto P_0c071fd4;
case 0x0c071fd6u: goto P_0c071fd6;
case 0x0c071fd8u: goto P_0c071fd8;
case 0x0c071fdau: goto P_0c071fda;
case 0x0c071fdcu: goto P_0c071fdc;
case 0x0c071fdeu: goto P_0c071fde;
case 0x0c071fe0u: goto P_0c071fe0;
case 0x0c071fe2u: goto P_0c071fe2;
case 0x0c071fe4u: goto P_0c071fe4;
case 0x0c071fe6u: goto P_0c071fe6;
case 0x0c071fe8u: goto P_0c071fe8;
case 0x0c071feau: goto P_0c071fea;
case 0x0c071fecu: goto P_0c071fec;
case 0x0c071feeu: goto P_0c071fee;
case 0x0c071ff0u: goto P_0c071ff0;
case 0x0c071ff2u: goto P_0c071ff2;
case 0x0c071ff4u: goto P_0c071ff4;
case 0x0c071ff6u: goto P_0c071ff6;
case 0x0c071ff8u: goto P_0c071ff8;
case 0x0c071ffau: goto P_0c071ffa;
case 0x0c071ffcu: goto P_0c071ffc;
case 0x0c071ffeu: goto P_0c071ffe;
case 0x0c072000u: goto P_0c072000;
case 0x0c072002u: goto P_0c072002;
case 0x0c072004u: goto P_0c072004;
case 0x0c072006u: goto P_0c072006;
case 0x0c072008u: goto P_0c072008;
case 0x0c07200au: goto P_0c07200a;
case 0x0c07200cu: goto P_0c07200c;
case 0x0c07200eu: goto P_0c07200e;
case 0x0c072010u: goto P_0c072010;
case 0x0c072012u: goto P_0c072012;
case 0x0c072014u: goto P_0c072014;
case 0x0c072016u: goto P_0c072016;
case 0x0c072018u: goto P_0c072018;
case 0x0c07201au: goto P_0c07201a;
case 0x0c07201cu: goto P_0c07201c;
case 0x0c07201eu: goto P_0c07201e;
case 0x0c072020u: goto P_0c072020;
case 0x0c072022u: goto P_0c072022;
case 0x0c072024u: goto P_0c072024;
case 0x0c072026u: goto P_0c072026;
case 0x0c072028u: goto P_0c072028;
case 0x0c07202au: goto P_0c07202a;
case 0x0c07202cu: goto P_0c07202c;
case 0x0c07202eu: goto P_0c07202e;
case 0x0c072030u: goto P_0c072030;
case 0x0c072032u: goto P_0c072032;
case 0x0c072034u: goto P_0c072034;
case 0x0c072036u: goto P_0c072036;
case 0x0c072038u: goto P_0c072038;
case 0x0c07203au: goto P_0c07203a;
case 0x0c07203cu: goto P_0c07203c;
case 0x0c07203eu: goto P_0c07203e;
case 0x0c072040u: goto P_0c072040;
case 0x0c072042u: goto P_0c072042;
case 0x0c072044u: goto P_0c072044;
case 0x0c072046u: goto P_0c072046;
case 0x0c072048u: goto P_0c072048;
case 0x0c07204au: goto P_0c07204a;
case 0x0c07204cu: goto P_0c07204c;
case 0x0c07204eu: goto P_0c07204e;
case 0x0c072050u: goto P_0c072050;
case 0x0c072052u: goto P_0c072052;
case 0x0c072054u: goto P_0c072054;
case 0x0c072056u: goto P_0c072056;
case 0x0c072058u: goto P_0c072058;
case 0x0c07205au: goto P_0c07205a;
case 0x0c07205cu: goto P_0c07205c;
case 0x0c07205eu: goto P_0c07205e;
case 0x0c072060u: goto P_0c072060;
case 0x0c072062u: goto P_0c072062;
case 0x0c072064u: goto P_0c072064;
case 0x0c072066u: goto P_0c072066;
case 0x0c072068u: goto P_0c072068;
case 0x0c07206au: goto P_0c07206a;
case 0x0c07206cu: goto P_0c07206c;
case 0x0c07206eu: goto P_0c07206e;
case 0x0c072070u: goto P_0c072070;
case 0x0c072072u: goto P_0c072072;
case 0x0c072074u: goto P_0c072074;
case 0x0c073f82u: goto P_0c073f82;
case 0x0c073f84u: goto P_0c073f84;
case 0x0c073f86u: goto P_0c073f86;
case 0x0c073f88u: goto P_0c073f88;
case 0x0c073f8au: goto P_0c073f8a;
case 0x0c073f8cu: goto P_0c073f8c;
case 0x0c073f8eu: goto P_0c073f8e;
case 0x0c073f90u: goto P_0c073f90;
case 0x0c073f92u: goto P_0c073f92;
case 0x0c073f94u: goto P_0c073f94;
case 0x0c073f96u: goto P_0c073f96;
case 0x0c073f98u: goto P_0c073f98;
case 0x0c073f9au: goto P_0c073f9a;
case 0x0c073f9cu: goto P_0c073f9c;
case 0x0c073f9eu: goto P_0c073f9e;
case 0x0c073fa0u: goto P_0c073fa0;
case 0x0c073fa2u: goto P_0c073fa2;
case 0x0c073fa4u: goto P_0c073fa4;
case 0x0c073fa6u: goto P_0c073fa6;
case 0x0c073fa8u: goto P_0c073fa8;
case 0x0c073faau: goto P_0c073faa;
case 0x0c073facu: goto P_0c073fac;
case 0x0c073faeu: goto P_0c073fae;
case 0x0c073fb0u: goto P_0c073fb0;
case 0x0c073fb2u: goto P_0c073fb2;
case 0x0c074702u: goto P_0c074702;
case 0x0c074704u: goto P_0c074704;
case 0x0c074706u: goto P_0c074706;
case 0x0c074708u: goto P_0c074708;
case 0x0c07470au: goto P_0c07470a;
case 0x0c07470cu: goto P_0c07470c;
case 0x0c07470eu: goto P_0c07470e;
case 0x0c074710u: goto P_0c074710;
case 0x0c074712u: goto P_0c074712;
case 0x0c074714u: goto P_0c074714;
case 0x0c074716u: goto P_0c074716;
case 0x0c074718u: goto P_0c074718;
case 0x0c07471au: goto P_0c07471a;
case 0x0c07471cu: goto P_0c07471c;
case 0x0c07471eu: goto P_0c07471e;
case 0x0c074720u: goto P_0c074720;
case 0x0c074722u: goto P_0c074722;
case 0x0c074724u: goto P_0c074724;
case 0x0c074726u: goto P_0c074726;
case 0x0c074728u: goto P_0c074728;
case 0x0c07472au: goto P_0c07472a;
case 0x0c07472cu: goto P_0c07472c;
case 0x0c07472eu: goto P_0c07472e;
case 0x0c074730u: goto P_0c074730;
case 0x0c074732u: goto P_0c074732;
case 0x0c074734u: goto P_0c074734;
case 0x0c074736u: goto P_0c074736;
case 0x0c074738u: goto P_0c074738;
case 0x0c07473au: goto P_0c07473a;
case 0x0c07473cu: goto P_0c07473c;
case 0x0c07482eu: goto P_0c07482e;
case 0x0c074830u: goto P_0c074830;
case 0x0c074832u: goto P_0c074832;
case 0x0c074834u: goto P_0c074834;
case 0x0c074836u: goto P_0c074836;
case 0x0c074838u: goto P_0c074838;
case 0x0c07483au: goto P_0c07483a;
case 0x0c07483cu: goto P_0c07483c;
case 0x0c07483eu: goto P_0c07483e;
case 0x0c074840u: goto P_0c074840;
case 0x0c074842u: goto P_0c074842;
case 0x0c074844u: goto P_0c074844;
case 0x0c074846u: goto P_0c074846;
case 0x0c074848u: goto P_0c074848;
case 0x0c07484au: goto P_0c07484a;
case 0x0c07484cu: goto P_0c07484c;
case 0x0c07484eu: goto P_0c07484e;
case 0x0c074850u: goto P_0c074850;
case 0x0c074852u: goto P_0c074852;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0352dc: /* original 4f22, guest PC 0x0c0352dc */
if(!s->budget--) { s->failed_pc=0x0c0352dcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0352de;
P_0c0352de: /* original 6322, guest PC 0x0c0352de */
if(!s->budget--) { s->failed_pc=0x0c0352deu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0352e0;
P_0c0352e0: /* original 5135, guest PC 0x0c0352e0 */
if(!s->budget--) { s->failed_pc=0x0c0352e0u; return 0; }
r[1]=read(ram,r[3]+20,4);
goto P_0c0352e2;
P_0c0352e2: /* original 7ff8, guest PC 0x0c0352e2 */
if(!s->budget--) { s->failed_pc=0x0c0352e2u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0352e4;
P_0c0352e4: /* original 5018, guest PC 0x0c0352e4 */
if(!s->budget--) { s->failed_pc=0x0c0352e4u; return 0; }
r[0]=read(ram,r[1]+32,4);
goto P_0c0352e6;
P_0c0352e6: /* original 400b, guest PC 0x0c0352e6 */
if(!s->budget--) { s->failed_pc=0x0c0352e6u; return 0; }
target=r[0];
r[16]=0x0c0352eau;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0352eau) { target=s->pc; goto dispatch; }
goto P_0c0352ea;
P_0c0352e8: /* original 64f3, guest PC 0x0c0352e8 */
if(!s->budget--) { s->failed_pc=0x0c0352e8u; return 0; }
r[4]=r[15];
goto P_0c0352ea;
P_0c0352ea: /* original 6403, guest PC 0x0c0352ea */
if(!s->budget--) { s->failed_pc=0x0c0352eau; return 0; }
r[4]=r[0];
goto P_0c0352ec;
P_0c0352ec: /* original 2448, guest PC 0x0c0352ec */
if(!s->budget--) { s->failed_pc=0x0c0352ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0352ee;
P_0c0352ee: /* original 8b03, guest PC 0x0c0352ee */
if(!s->budget--) { s->failed_pc=0x0c0352eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0352f8; }
goto P_0c0352f0;
P_0c0352f0: /* original 7f08, guest PC 0x0c0352f0 */
if(!s->budget--) { s->failed_pc=0x0c0352f0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0352f2;
P_0c0352f2: /* original 4f26, guest PC 0x0c0352f2 */
if(!s->budget--) { s->failed_pc=0x0c0352f2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0352f4;
P_0c0352f4: /* original 000b, guest PC 0x0c0352f4 */
if(!s->budget--) { s->failed_pc=0x0c0352f4u; return 0; }
target=r[16];
r[0]=0xffffffffu;
s->pc=target; return ram->oob==0;
P_0c0352f6: /* original e0ff, guest PC 0x0c0352f6 */
if(!s->budget--) { s->failed_pc=0x0c0352f6u; return 0; }
r[0]=0xffffffffu;
goto P_0c0352f8;
P_0c0352f8: /* original 60f2, guest PC 0x0c0352f8 */
if(!s->budget--) { s->failed_pc=0x0c0352f8u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0352fa;
P_0c0352fa: /* original 7f08, guest PC 0x0c0352fa */
if(!s->budget--) { s->failed_pc=0x0c0352fau; return 0; }
r[15]+=0x00000008u;
goto P_0c0352fc;
P_0c0352fc: /* original 4f26, guest PC 0x0c0352fc */
if(!s->budget--) { s->failed_pc=0x0c0352fcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0352fe;
P_0c0352fe: /* original 000b, guest PC 0x0c0352fe */
if(!s->budget--) { s->failed_pc=0x0c0352feu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c035300: /* original 0009, guest PC 0x0c035300 */
if(!s->budget--) { s->failed_pc=0x0c035300u; return 0; }
return vf3_matrix_family(0x0c035302u,s,ram);
P_0c036594: /* original 4f22, guest PC 0x0c036594 */
if(!s->budget--) { s->failed_pc=0x0c036594u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c036596;
P_0c036596: /* original 013e, guest PC 0x0c036596 */
if(!s->budget--) { s->failed_pc=0x0c036596u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c036598;
P_0c036598: /* original 2118, guest PC 0x0c036598 */
if(!s->budget--) { s->failed_pc=0x0c036598u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c03659a;
P_0c03659a: /* original 8918, guest PC 0x0c03659a */
if(!s->budget--) { s->failed_pc=0x0c03659au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0365ce; }
goto P_0c03659c;
P_0c03659c: /* original 60f3, guest PC 0x0c03659c */
if(!s->budget--) { s->failed_pc=0x0c03659cu; return 0; }
r[0]=r[15];
goto P_0c03659e;
P_0c03659e: /* original 7008, guest PC 0x0c03659e */
if(!s->budget--) { s->failed_pc=0x0c03659eu; return 0; }
r[0]+=0x00000008u;
goto P_0c0365a0;
P_0c0365a0: /* original e503, guest PC 0x0c0365a0 */
if(!s->budget--) { s->failed_pc=0x0c0365a0u; return 0; }
r[5]=0x00000003u;
goto P_0c0365a2;
P_0c0365a2: /* original 7004, guest PC 0x0c0365a2 */
if(!s->budget--) { s->failed_pc=0x0c0365a2u; return 0; }
r[0]+=0x00000004u;
goto P_0c0365a4;
P_0c0365a4: /* original 2508, guest PC 0x0c0365a4 */
if(!s->budget--) { s->failed_pc=0x0c0365a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[0])==0)!=0);
goto P_0c0365a6;
P_0c0365a6: /* original 8903, guest PC 0x0c0365a6 */
if(!s->budget--) { s->failed_pc=0x0c0365a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0365b0; }
goto P_0c0365a8;
P_0c0365a8: /* original 65f3, guest PC 0x0c0365a8 */
if(!s->budget--) { s->failed_pc=0x0c0365a8u; return 0; }
r[5]=r[15];
goto P_0c0365aa;
P_0c0365aa: /* original 7508, guest PC 0x0c0365aa */
if(!s->budget--) { s->failed_pc=0x0c0365aau; return 0; }
r[5]+=0x00000008u;
goto P_0c0365ac;
P_0c0365ac: /* original a003, guest PC 0x0c0365ac */
if(!s->budget--) { s->failed_pc=0x0c0365acu; return 0; }
r[5]+=0x00000008u;
goto P_0c0365b6;
P_0c0365ae: /* original 7508, guest PC 0x0c0365ae */
if(!s->budget--) { s->failed_pc=0x0c0365aeu; return 0; }
r[5]+=0x00000008u;
goto P_0c0365b0;
P_0c0365b0: /* original 65f3, guest PC 0x0c0365b0 */
if(!s->budget--) { s->failed_pc=0x0c0365b0u; return 0; }
r[5]=r[15];
goto P_0c0365b2;
P_0c0365b2: /* original 7508, guest PC 0x0c0365b2 */
if(!s->budget--) { s->failed_pc=0x0c0365b2u; return 0; }
r[5]+=0x00000008u;
goto P_0c0365b4;
P_0c0365b4: /* original 7504, guest PC 0x0c0365b4 */
if(!s->budget--) { s->failed_pc=0x0c0365b4u; return 0; }
r[5]+=0x00000004u;
goto P_0c0365b6;
P_0c0365b6: /* original d325, guest PC 0x0c0365b6 */
if(!s->budget--) { s->failed_pc=0x0c0365b6u; return 0; }
r[3]=read(ram,0x0c03664cu,4);
goto P_0c0365b8;
P_0c0365b8: /* original 6653, guest PC 0x0c0365b8 */
if(!s->budget--) { s->failed_pc=0x0c0365b8u; return 0; }
r[6]=r[5];
goto P_0c0365ba;
P_0c0365ba: /* original d423, guest PC 0x0c0365ba */
if(!s->budget--) { s->failed_pc=0x0c0365bau; return 0; }
r[4]=read(ram,0x0c036648u,4);
goto P_0c0365bc;
P_0c0365bc: /* original 430b, guest PC 0x0c0365bc */
if(!s->budget--) { s->failed_pc=0x0c0365bcu; return 0; }
target=r[3];
r[16]=0x0c0365c0u;
r[5]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0365c0u) { target=s->pc; goto dispatch; }
goto P_0c0365c0;
P_0c0365be: /* original 55f2, guest PC 0x0c0365be */
if(!s->budget--) { s->failed_pc=0x0c0365beu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0365c0;
P_0c0365c0: /* original d223, guest PC 0x0c0365c0 */
if(!s->budget--) { s->failed_pc=0x0c0365c0u; return 0; }
r[2]=read(ram,0x0c036650u,4);
goto P_0c0365c2;
P_0c0365c2: /* original 6e22, guest PC 0x0c0365c2 */
if(!s->budget--) { s->failed_pc=0x0c0365c2u; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c0365c4;
P_0c0365c4: /* original 2ee8, guest PC 0x0c0365c4 */
if(!s->budget--) { s->failed_pc=0x0c0365c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0365c6;
P_0c0365c6: /* original 8902, guest PC 0x0c0365c6 */
if(!s->budget--) { s->failed_pc=0x0c0365c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0365ce; }
goto P_0c0365c8;
P_0c0365c8: /* original d41f, guest PC 0x0c0365c8 */
if(!s->budget--) { s->failed_pc=0x0c0365c8u; return 0; }
r[4]=read(ram,0x0c036648u,4);
goto P_0c0365ca;
P_0c0365ca: /* original 4e0b, guest PC 0x0c0365ca */
if(!s->budget--) { s->failed_pc=0x0c0365cau; return 0; }
target=r[14];
r[16]=0x0c0365ceu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0365ceu) { target=s->pc; goto dispatch; }
goto P_0c0365ce;
P_0c0365cc: /* original 0009, guest PC 0x0c0365cc */
if(!s->budget--) { s->failed_pc=0x0c0365ccu; return 0; }
goto P_0c0365ce;
P_0c0365ce: /* original 4f26, guest PC 0x0c0365ce */
if(!s->budget--) { s->failed_pc=0x0c0365ceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0365d0;
P_0c0365d0: /* original 000b, guest PC 0x0c0365d0 */
if(!s->budget--) { s->failed_pc=0x0c0365d0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0365d2: /* original 6ef6, guest PC 0x0c0365d2 */
if(!s->budget--) { s->failed_pc=0x0c0365d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0365d4u,s,ram);
P_0c03c092: /* original 4f22, guest PC 0x0c03c092 */
if(!s->budget--) { s->failed_pc=0x0c03c092u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03c094;
P_0c03c094: /* original 7ffc, guest PC 0x0c03c094 */
if(!s->budget--) { s->failed_pc=0x0c03c094u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03c096;
P_0c03c096: /* original 2f42, guest PC 0x0c03c096 */
if(!s->budget--) { s->failed_pc=0x0c03c096u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03c098;
P_0c03c098: /* original d321, guest PC 0x0c03c098 */
if(!s->budget--) { s->failed_pc=0x0c03c098u; return 0; }
r[3]=read(ram,0x0c03c120u,4);
goto P_0c03c09a;
P_0c03c09a: /* original 430b, guest PC 0x0c03c09a */
if(!s->budget--) { s->failed_pc=0x0c03c09au; return 0; }
target=r[3];
r[16]=0x0c03c09eu;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03c09eu) { target=s->pc; goto dispatch; }
goto P_0c03c09e;
P_0c03c09c: /* original e400, guest PC 0x0c03c09c */
if(!s->budget--) { s->failed_pc=0x0c03c09cu; return 0; }
r[4]=0x00000000u;
goto P_0c03c09e;
P_0c03c09e: /* original d422, guest PC 0x0c03c09e */
if(!s->budget--) { s->failed_pc=0x0c03c09eu; return 0; }
r[4]=read(ram,0x0c03c128u,4);
goto P_0c03c0a0;
P_0c03c0a0: /* original d520, guest PC 0x0c03c0a0 */
if(!s->budget--) { s->failed_pc=0x0c03c0a0u; return 0; }
r[5]=read(ram,0x0c03c124u,4);
goto P_0c03c0a2;
P_0c03c0a2: /* original 6140, guest PC 0x0c03c0a2 */
if(!s->budget--) { s->failed_pc=0x0c03c0a2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[1]=tmp;
goto P_0c03c0a4;
P_0c03c0a4: /* original 6253, guest PC 0x0c03c0a4 */
if(!s->budget--) { s->failed_pc=0x0c03c0a4u; return 0; }
r[2]=r[5];
goto P_0c03c0a6;
P_0c03c0a6: /* original 6e53, guest PC 0x0c03c0a6 */
if(!s->budget--) { s->failed_pc=0x0c03c0a6u; return 0; }
r[14]=r[5];
goto P_0c03c0a8;
P_0c03c0a8: /* original 6313, guest PC 0x0c03c0a8 */
if(!s->budget--) { s->failed_pc=0x0c03c0a8u; return 0; }
r[3]=r[1];
goto P_0c03c0aa;
P_0c03c0aa: /* original 4100, guest PC 0x0c03c0aa */
if(!s->budget--) { s->failed_pc=0x0c03c0aau; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c03c0ac;
P_0c03c0ac: /* original 313c, guest PC 0x0c03c0ac */
if(!s->budget--) { s->failed_pc=0x0c03c0acu; return 0; }
r[1]+=r[3];
goto P_0c03c0ae;
P_0c03c0ae: /* original d31f, guest PC 0x0c03c0ae */
if(!s->budget--) { s->failed_pc=0x0c03c0aeu; return 0; }
r[3]=read(ram,0x0c03c12cu,4);
goto P_0c03c0b0;
P_0c03c0b0: /* original 4108, guest PC 0x0c03c0b0 */
if(!s->budget--) { s->failed_pc=0x0c03c0b0u; return 0; }
r[1]<<=2;
goto P_0c03c0b2;
P_0c03c0b2: /* original 611e, guest PC 0x0c03c0b2 */
if(!s->budget--) { s->failed_pc=0x0c03c0b2u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)r[1];
goto P_0c03c0b4;
P_0c03c0b4: /* original 315c, guest PC 0x0c03c0b4 */
if(!s->budget--) { s->failed_pc=0x0c03c0b4u; return 0; }
r[1]+=r[5];
goto P_0c03c0b6;
P_0c03c0b6: /* original 430b, guest PC 0x0c03c0b6 */
if(!s->budget--) { s->failed_pc=0x0c03c0b6u; return 0; }
target=r[3];
r[16]=0x0c03c0bau;
r[0]=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03c0bau) { target=s->pc; goto dispatch; }
goto P_0c03c0ba;
P_0c03c0b8: /* original e00c, guest PC 0x0c03c0b8 */
if(!s->budget--) { s->failed_pc=0x0c03c0b8u; return 0; }
r[0]=0x0000000cu;
goto P_0c03c0ba;
P_0c03c0ba: /* original 62f2, guest PC 0x0c03c0ba */
if(!s->budget--) { s->failed_pc=0x0c03c0bau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c03c0bc;
P_0c03c0bc: /* original 61e3, guest PC 0x0c03c0bc */
if(!s->budget--) { s->failed_pc=0x0c03c0bcu; return 0; }
r[1]=r[14];
goto P_0c03c0be;
P_0c03c0be: /* original 2420, guest PC 0x0c03c0be */
if(!s->budget--) { s->failed_pc=0x0c03c0beu; return 0; }
write(ram,r[4],r[2],1);
goto P_0c03c0c0;
P_0c03c0c0: /* original 6240, guest PC 0x0c03c0c0 */
if(!s->budget--) { s->failed_pc=0x0c03c0c0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c03c0c2;
P_0c03c0c2: /* original 6323, guest PC 0x0c03c0c2 */
if(!s->budget--) { s->failed_pc=0x0c03c0c2u; return 0; }
r[3]=r[2];
goto P_0c03c0c4;
P_0c03c0c4: /* original 4200, guest PC 0x0c03c0c4 */
if(!s->budget--) { s->failed_pc=0x0c03c0c4u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c03c0c6;
P_0c03c0c6: /* original 323c, guest PC 0x0c03c0c6 */
if(!s->budget--) { s->failed_pc=0x0c03c0c6u; return 0; }
r[2]+=r[3];
goto P_0c03c0c8;
P_0c03c0c8: /* original d318, guest PC 0x0c03c0c8 */
if(!s->budget--) { s->failed_pc=0x0c03c0c8u; return 0; }
r[3]=read(ram,0x0c03c12cu,4);
goto P_0c03c0ca;
P_0c03c0ca: /* original 4208, guest PC 0x0c03c0ca */
if(!s->budget--) { s->failed_pc=0x0c03c0cau; return 0; }
r[2]<<=2;
goto P_0c03c0cc;
P_0c03c0cc: /* original 622e, guest PC 0x0c03c0cc */
if(!s->budget--) { s->failed_pc=0x0c03c0ccu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[2];
goto P_0c03c0ce;
P_0c03c0ce: /* original 325c, guest PC 0x0c03c0ce */
if(!s->budget--) { s->failed_pc=0x0c03c0ceu; return 0; }
r[2]+=r[5];
goto P_0c03c0d0;
P_0c03c0d0: /* original 430b, guest PC 0x0c03c0d0 */
if(!s->budget--) { s->failed_pc=0x0c03c0d0u; return 0; }
target=r[3];
r[16]=0x0c03c0d4u;
r[0]=0x0000000cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03c0d4u) { target=s->pc; goto dispatch; }
goto P_0c03c0d4;
P_0c03c0d2: /* original e00c, guest PC 0x0c03c0d2 */
if(!s->budget--) { s->failed_pc=0x0c03c0d2u; return 0; }
r[0]=0x0000000cu;
goto P_0c03c0d4;
P_0c03c0d4: /* original 7f04, guest PC 0x0c03c0d4 */
if(!s->budget--) { s->failed_pc=0x0c03c0d4u; return 0; }
r[15]+=0x00000004u;
goto P_0c03c0d6;
P_0c03c0d6: /* original d216, guest PC 0x0c03c0d6 */
if(!s->budget--) { s->failed_pc=0x0c03c0d6u; return 0; }
r[2]=read(ram,0x0c03c130u,4);
goto P_0c03c0d8;
P_0c03c0d8: /* original 4f26, guest PC 0x0c03c0d8 */
if(!s->budget--) { s->failed_pc=0x0c03c0d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03c0da;
P_0c03c0da: /* original 54e2, guest PC 0x0c03c0da */
if(!s->budget--) { s->failed_pc=0x0c03c0dau; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c03c0dc;
P_0c03c0dc: /* original 422b, guest PC 0x0c03c0dc */
if(!s->budget--) { s->failed_pc=0x0c03c0dcu; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c03c0de: /* original 6ef6, guest PC 0x0c03c0de */
if(!s->budget--) { s->failed_pc=0x0c03c0deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03c0e0u,s,ram);
P_0c03c51a: /* original f10b, guest PC 0x0c03c51a */
if(!s->budget--) { s->failed_pc=0x0c03c51au; return 0; }
r[1]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[1]);
goto P_0c03c51c;
P_0c03c51c: /* original 8f00, guest PC 0x0c03c51c */
if(!s->budget--) { s->failed_pc=0x0c03c51cu; return 0; }
cond=r[17]&1u;
write(ram,r[3]+8,r[7],4);
if(!cond) { goto P_0c03c520; }
goto P_0c03c520;
P_0c03c51e: /* original 1372, guest PC 0x0c03c51e */
if(!s->budget--) { s->failed_pc=0x0c03c51eu; return 0; }
write(ram,r[3]+8,r[7],4);
goto P_0c03c520;
P_0c03c520: /* original 2448, guest PC 0x0c03c520 */
if(!s->budget--) { s->failed_pc=0x0c03c520u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03c522;
P_0c03c522: /* original 8f05, guest PC 0x0c03c522 */
if(!s->budget--) { s->failed_pc=0x0c03c522u; return 0; }
cond=r[17]&1u;
write(ram,r[3],r[6],2);
if(!cond) { goto P_0c03c530; }
goto P_0c03c526;
P_0c03c524: /* original 2361, guest PC 0x0c03c524 */
if(!s->budget--) { s->failed_pc=0x0c03c524u; return 0; }
write(ram,r[3],r[6],2);
goto P_0c03c526;
P_0c03c526: /* original f3fd, guest PC 0x0c03c526 */
if(!s->budget--) { s->failed_pc=0x0c03c526u; return 0; }
r[18]^=0x100000u;
goto P_0c03c528;
P_0c03c528: /* original 000b, guest PC 0x0c03c528 */
if(!s->budget--) { s->failed_pc=0x0c03c528u; return 0; }
target=r[16];
vf3_matrix_swap(s);
s->pc=target; return ram->oob==0;
P_0c03c52a: /* original fbfd, guest PC 0x0c03c52a */
if(!s->budget--) { s->failed_pc=0x0c03c52au; return 0; }
vf3_matrix_swap(s);
return vf3_matrix_family(0x0c03c52cu,s,ram);
P_0c03c530: /* original e104, guest PC 0x0c03c530 */
if(!s->budget--) { s->failed_pc=0x0c03c530u; return 0; }
r[1]=0x00000004u;
goto P_0c03c532;
P_0c03c532: /* original 0483, guest PC 0x0c03c532 */
if(!s->budget--) { s->failed_pc=0x0c03c532u; return 0; }
goto P_0c03c534;
P_0c03c534: /* original 2418, guest PC 0x0c03c534 */
if(!s->budget--) { s->failed_pc=0x0c03c534u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[1])==0)!=0);
goto P_0c03c536;
P_0c03c536: /* original 8912, guest PC 0x0c03c536 */
if(!s->budget--) { s->failed_pc=0x0c03c536u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03c55e; }
goto P_0c03c538;
P_0c03c538: /* original f3fd, guest PC 0x0c03c538 */
if(!s->budget--) { s->failed_pc=0x0c03c538u; return 0; }
r[18]^=0x100000u;
goto P_0c03c53a;
P_0c03c53a: /* original f049, guest PC 0x0c03c53a */
if(!s->budget--) { s->failed_pc=0x0c03c53au; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c53c;
P_0c03c53c: /* original f149, guest PC 0x0c03c53c */
if(!s->budget--) { s->failed_pc=0x0c03c53cu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c53e;
P_0c03c53e: /* original f249, guest PC 0x0c03c53e */
if(!s->budget--) { s->failed_pc=0x0c03c53eu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c540;
P_0c03c540: /* original f349, guest PC 0x0c03c540 */
if(!s->budget--) { s->failed_pc=0x0c03c540u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c542;
P_0c03c542: /* original f449, guest PC 0x0c03c542 */
if(!s->budget--) { s->failed_pc=0x0c03c542u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c544;
P_0c03c544: /* original f549, guest PC 0x0c03c544 */
if(!s->budget--) { s->failed_pc=0x0c03c544u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c546;
P_0c03c546: /* original f649, guest PC 0x0c03c546 */
if(!s->budget--) { s->failed_pc=0x0c03c546u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c548;
P_0c03c548: /* original f749, guest PC 0x0c03c548 */
if(!s->budget--) { s->failed_pc=0x0c03c548u; return 0; }
vf3_matrix_load(s,ram,7,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c54a;
P_0c03c54a: /* original f849, guest PC 0x0c03c54a */
if(!s->budget--) { s->failed_pc=0x0c03c54au; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c54c;
P_0c03c54c: /* original f949, guest PC 0x0c03c54c */
if(!s->budget--) { s->failed_pc=0x0c03c54cu; return 0; }
vf3_matrix_load(s,ram,9,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c54e;
P_0c03c54e: /* original fa49, guest PC 0x0c03c54e */
if(!s->budget--) { s->failed_pc=0x0c03c54eu; return 0; }
vf3_matrix_load(s,ram,10,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c550;
P_0c03c550: /* original fb49, guest PC 0x0c03c550 */
if(!s->budget--) { s->failed_pc=0x0c03c550u; return 0; }
vf3_matrix_load(s,ram,11,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c552;
P_0c03c552: /* original fc49, guest PC 0x0c03c552 */
if(!s->budget--) { s->failed_pc=0x0c03c552u; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c554;
P_0c03c554: /* original fd49, guest PC 0x0c03c554 */
if(!s->budget--) { s->failed_pc=0x0c03c554u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c556;
P_0c03c556: /* original fe49, guest PC 0x0c03c556 */
if(!s->budget--) { s->failed_pc=0x0c03c556u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c558;
P_0c03c558: /* original ff49, guest PC 0x0c03c558 */
if(!s->budget--) { s->failed_pc=0x0c03c558u; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c55a;
P_0c03c55a: /* original 000b, guest PC 0x0c03c55a */
if(!s->budget--) { s->failed_pc=0x0c03c55au; return 0; }
target=r[16];
vf3_matrix_swap(s);
s->pc=target; return ram->oob==0;
P_0c03c55c: /* original fbfd, guest PC 0x0c03c55c */
if(!s->budget--) { s->failed_pc=0x0c03c55cu; return 0; }
vf3_matrix_swap(s);
goto P_0c03c55e;
P_0c03c55e: /* original f049, guest PC 0x0c03c55e */
if(!s->budget--) { s->failed_pc=0x0c03c55eu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c560;
P_0c03c560: /* original f249, guest PC 0x0c03c560 */
if(!s->budget--) { s->failed_pc=0x0c03c560u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c562;
P_0c03c562: /* original f449, guest PC 0x0c03c562 */
if(!s->budget--) { s->failed_pc=0x0c03c562u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c564;
P_0c03c564: /* original f649, guest PC 0x0c03c564 */
if(!s->budget--) { s->failed_pc=0x0c03c564u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c566;
P_0c03c566: /* original f849, guest PC 0x0c03c566 */
if(!s->budget--) { s->failed_pc=0x0c03c566u; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c568;
P_0c03c568: /* original fa49, guest PC 0x0c03c568 */
if(!s->budget--) { s->failed_pc=0x0c03c568u; return 0; }
vf3_matrix_load(s,ram,10,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c56a;
P_0c03c56a: /* original fc49, guest PC 0x0c03c56a */
if(!s->budget--) { s->failed_pc=0x0c03c56au; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c56c;
P_0c03c56c: /* original fe49, guest PC 0x0c03c56c */
if(!s->budget--) { s->failed_pc=0x0c03c56cu; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03c56e;
P_0c03c56e: /* original f3fd, guest PC 0x0c03c56e */
if(!s->budget--) { s->failed_pc=0x0c03c56eu; return 0; }
r[18]^=0x100000u;
goto P_0c03c570;
P_0c03c570: /* original 000b, guest PC 0x0c03c570 */
if(!s->budget--) { s->failed_pc=0x0c03c570u; return 0; }
target=r[16];
vf3_matrix_swap(s);
s->pc=target; return ram->oob==0;
P_0c03c572: /* original fbfd, guest PC 0x0c03c572 */
if(!s->budget--) { s->failed_pc=0x0c03c572u; return 0; }
vf3_matrix_swap(s);
return vf3_matrix_family(0x0c03c574u,s,ram);
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
r[16]=0x0c03d26au;
r[4]=read(ram,r[4]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03d26au) { target=s->pc; goto dispatch; }
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
r[16]=0x0c03d270u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03d270u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c03d278u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03d278u) { target=s->pc; goto dispatch; }
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
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c03d27e: /* original 4f26, guest PC 0x0c03d27e */
if(!s->budget--) { s->failed_pc=0x0c03d27eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c03d280u,s,ram);
P_0c03e980: /* original 4f22, guest PC 0x0c03e980 */
if(!s->budget--) { s->failed_pc=0x0c03e980u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03e982;
P_0c03e982: /* original d31d, guest PC 0x0c03e982 */
if(!s->budget--) { s->failed_pc=0x0c03e982u; return 0; }
r[3]=read(ram,0x0c03e9f8u,4);
goto P_0c03e984;
P_0c03e984: /* original 7ffc, guest PC 0x0c03e984 */
if(!s->budget--) { s->failed_pc=0x0c03e984u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03e986;
P_0c03e986: /* original 430b, guest PC 0x0c03e986 */
if(!s->budget--) { s->failed_pc=0x0c03e986u; return 0; }
target=r[3];
r[16]=0x0c03e98au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03e98au) { target=s->pc; goto dispatch; }
goto P_0c03e98a;
P_0c03e988: /* original 0009, guest PC 0x0c03e988 */
if(!s->budget--) { s->failed_pc=0x0c03e988u; return 0; }
goto P_0c03e98a;
P_0c03e98a: /* original d517, guest PC 0x0c03e98a */
if(!s->budget--) { s->failed_pc=0x0c03e98au; return 0; }
r[5]=read(ram,0x0c03e9e8u,4);
goto P_0c03e98c;
P_0c03e98c: /* original 2f52, guest PC 0x0c03e98c */
if(!s->budget--) { s->failed_pc=0x0c03e98cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c03e98e;
P_0c03e98e: /* original 9324, guest PC 0x0c03e98e */
if(!s->budget--) { s->failed_pc=0x0c03e98eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e9dau,2);
goto P_0c03e990;
P_0c03e990: /* original 64f2, guest PC 0x0c03e990 */
if(!s->budget--) { s->failed_pc=0x0c03e990u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c03e992;
P_0c03e992: /* original d216, guest PC 0x0c03e992 */
if(!s->budget--) { s->failed_pc=0x0c03e992u; return 0; }
r[2]=read(ram,0x0c03e9ecu,4);
goto P_0c03e994;
P_0c03e994: /* original 353c, guest PC 0x0c03e994 */
if(!s->budget--) { s->failed_pc=0x0c03e994u; return 0; }
r[5]+=r[3];
goto P_0c03e996;
P_0c03e996: /* original 420b, guest PC 0x0c03e996 */
if(!s->budget--) { s->failed_pc=0x0c03e996u; return 0; }
target=r[2];
r[16]=0x0c03e99au;
r[4]+=0x00000068u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03e99au) { target=s->pc; goto dispatch; }
goto P_0c03e99a;
P_0c03e998: /* original 7468, guest PC 0x0c03e998 */
if(!s->budget--) { s->failed_pc=0x0c03e998u; return 0; }
r[4]+=0x00000068u;
goto P_0c03e99a;
P_0c03e99a: /* original d314, guest PC 0x0c03e99a */
if(!s->budget--) { s->failed_pc=0x0c03e99au; return 0; }
r[3]=read(ram,0x0c03e9ecu,4);
goto P_0c03e99c;
P_0c03e99c: /* original d418, guest PC 0x0c03e99c */
if(!s->budget--) { s->failed_pc=0x0c03e99cu; return 0; }
r[4]=read(ram,0x0c03ea00u,4);
goto P_0c03e99e;
P_0c03e99e: /* original d517, guest PC 0x0c03e99e */
if(!s->budget--) { s->failed_pc=0x0c03e99eu; return 0; }
r[5]=read(ram,0x0c03e9fcu,4);
goto P_0c03e9a0;
P_0c03e9a0: /* original 430b, guest PC 0x0c03e9a0 */
if(!s->budget--) { s->failed_pc=0x0c03e9a0u; return 0; }
target=r[3];
r[16]=0x0c03e9a4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03e9a4u) { target=s->pc; goto dispatch; }
goto P_0c03e9a4;
P_0c03e9a2: /* original 0009, guest PC 0x0c03e9a2 */
if(!s->budget--) { s->failed_pc=0x0c03e9a2u; return 0; }
goto P_0c03e9a4;
P_0c03e9a4: /* original d214, guest PC 0x0c03e9a4 */
if(!s->budget--) { s->failed_pc=0x0c03e9a4u; return 0; }
r[2]=read(ram,0x0c03e9f8u,4);
goto P_0c03e9a6;
P_0c03e9a6: /* original 7f04, guest PC 0x0c03e9a6 */
if(!s->budget--) { s->failed_pc=0x0c03e9a6u; return 0; }
r[15]+=0x00000004u;
goto P_0c03e9a8;
P_0c03e9a8: /* original 422b, guest PC 0x0c03e9a8 */
if(!s->budget--) { s->failed_pc=0x0c03e9a8u; return 0; }
target=r[2];
r[16]=read(ram,r[15],4); r[15]+=4;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c03e9aa: /* original 4f26, guest PC 0x0c03e9aa */
if(!s->budget--) { s->failed_pc=0x0c03e9aau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c03e9acu,s,ram);
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
r[16]=0x0c03ecbeu;
fr[4]=0;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ecbeu) { target=s->pc; goto dispatch; }
goto P_0c03ecbe;
P_0c03ecbc: /* original f48d, guest PC 0x0c03ecbc */
if(!s->budget--) { s->failed_pc=0x0c03ecbcu; return 0; }
fr[4]=0;
goto P_0c03ecbe;
P_0c03ecbe: /* original b0bf, guest PC 0x0c03ecbe */
if(!s->budget--) { s->failed_pc=0x0c03ecbeu; return 0; }
target=0x0c03ee40u; r[16]=0x0c03ecc2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ecc2u) { target=s->pc; goto dispatch; }
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
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c03ecca: /* original 4f26, guest PC 0x0c03ecca */
if(!s->budget--) { s->failed_pc=0x0c03eccau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c03ecccu,s,ram);
P_0c03eff4: /* original 4f22, guest PC 0x0c03eff4 */
if(!s->budget--) { s->failed_pc=0x0c03eff4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03eff6;
P_0c03eff6: /* original d329, guest PC 0x0c03eff6 */
if(!s->budget--) { s->failed_pc=0x0c03eff6u; return 0; }
r[3]=read(ram,0x0c03f09cu,4);
goto P_0c03eff8;
P_0c03eff8: /* original 430b, guest PC 0x0c03eff8 */
if(!s->budget--) { s->failed_pc=0x0c03eff8u; return 0; }
target=r[3];
r[16]=0x0c03effcu;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03effcu) { target=s->pc; goto dispatch; }
goto P_0c03effc;
P_0c03effa: /* original e400, guest PC 0x0c03effa */
if(!s->budget--) { s->failed_pc=0x0c03effau; return 0; }
r[4]=0x00000000u;
goto P_0c03effc;
P_0c03effc: /* original d229, guest PC 0x0c03effc */
if(!s->budget--) { s->failed_pc=0x0c03effcu; return 0; }
r[2]=read(ram,0x0c03f0a4u,4);
goto P_0c03effe;
P_0c03effe: /* original d428, guest PC 0x0c03effe */
if(!s->budget--) { s->failed_pc=0x0c03effeu; return 0; }
r[4]=read(ram,0x0c03f0a0u,4);
goto P_0c03f000;
P_0c03f000: /* original 420b, guest PC 0x0c03f000 */
if(!s->budget--) { s->failed_pc=0x0c03f000u; return 0; }
target=r[2];
r[16]=0x0c03f004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f004u) { target=s->pc; goto dispatch; }
goto P_0c03f004;
P_0c03f002: /* original 0009, guest PC 0x0c03f002 */
if(!s->budget--) { s->failed_pc=0x0c03f002u; return 0; }
goto P_0c03f004;
P_0c03f004: /* original d329, guest PC 0x0c03f004 */
if(!s->budget--) { s->failed_pc=0x0c03f004u; return 0; }
r[3]=read(ram,0x0c03f0acu,4);
goto P_0c03f006;
P_0c03f006: /* original d428, guest PC 0x0c03f006 */
if(!s->budget--) { s->failed_pc=0x0c03f006u; return 0; }
r[4]=read(ram,0x0c03f0a8u,4);
goto P_0c03f008;
P_0c03f008: /* original 430b, guest PC 0x0c03f008 */
if(!s->budget--) { s->failed_pc=0x0c03f008u; return 0; }
target=r[3];
r[16]=0x0c03f00cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f00cu) { target=s->pc; goto dispatch; }
goto P_0c03f00c;
P_0c03f00a: /* original 0009, guest PC 0x0c03f00a */
if(!s->budget--) { s->failed_pc=0x0c03f00au; return 0; }
goto P_0c03f00c;
P_0c03f00c: /* original 64e2, guest PC 0x0c03f00c */
if(!s->budget--) { s->failed_pc=0x0c03f00cu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c03f00e;
P_0c03f00e: /* original 2448, guest PC 0x0c03f00e */
if(!s->budget--) { s->failed_pc=0x0c03f00eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03f010;
P_0c03f010: /* original 8b06, guest PC 0x0c03f010 */
if(!s->budget--) { s->failed_pc=0x0c03f010u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f020; }
goto P_0c03f012;
P_0c03f012: /* original d328, guest PC 0x0c03f012 */
if(!s->budget--) { s->failed_pc=0x0c03f012u; return 0; }
r[3]=read(ram,0x0c03f0b4u,4);
goto P_0c03f014;
P_0c03f014: /* original d526, guest PC 0x0c03f014 */
if(!s->budget--) { s->failed_pc=0x0c03f014u; return 0; }
r[5]=read(ram,0x0c03f0b0u,4);
goto P_0c03f016;
P_0c03f016: /* original 430b, guest PC 0x0c03f016 */
if(!s->budget--) { s->failed_pc=0x0c03f016u; return 0; }
target=r[3];
r[16]=0x0c03f01au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f01au) { target=s->pc; goto dispatch; }
goto P_0c03f01a;
P_0c03f018: /* original 64e3, guest PC 0x0c03f018 */
if(!s->budget--) { s->failed_pc=0x0c03f018u; return 0; }
r[4]=r[14];
goto P_0c03f01a;
P_0c03f01a: /* original a008, guest PC 0x0c03f01a */
if(!s->budget--) { s->failed_pc=0x0c03f01au; return 0; }
goto P_0c03f02e;
P_0c03f01c: /* original 0009, guest PC 0x0c03f01c */
if(!s->budget--) { s->failed_pc=0x0c03f01cu; return 0; }
return vf3_matrix_family(0x0c03f01eu,s,ram);
P_0c03f020: /* original 6043, guest PC 0x0c03f020 */
if(!s->budget--) { s->failed_pc=0x0c03f020u; return 0; }
r[0]=r[4];
goto P_0c03f022;
P_0c03f022: /* original 8801, guest PC 0x0c03f022 */
if(!s->budget--) { s->failed_pc=0x0c03f022u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c03f024;
P_0c03f024: /* original 8b03, guest PC 0x0c03f024 */
if(!s->budget--) { s->failed_pc=0x0c03f024u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f02e; }
goto P_0c03f026;
P_0c03f026: /* original d224, guest PC 0x0c03f026 */
if(!s->budget--) { s->failed_pc=0x0c03f026u; return 0; }
r[2]=read(ram,0x0c03f0b8u,4);
goto P_0c03f028;
P_0c03f028: /* original d521, guest PC 0x0c03f028 */
if(!s->budget--) { s->failed_pc=0x0c03f028u; return 0; }
r[5]=read(ram,0x0c03f0b0u,4);
goto P_0c03f02a;
P_0c03f02a: /* original 420b, guest PC 0x0c03f02a */
if(!s->budget--) { s->failed_pc=0x0c03f02au; return 0; }
target=r[2];
r[16]=0x0c03f02eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f02eu) { target=s->pc; goto dispatch; }
goto P_0c03f02e;
P_0c03f02c: /* original 64e3, guest PC 0x0c03f02c */
if(!s->budget--) { s->failed_pc=0x0c03f02cu; return 0; }
r[4]=r[14];
goto P_0c03f02e;
P_0c03f02e: /* original 4f26, guest PC 0x0c03f02e */
if(!s->budget--) { s->failed_pc=0x0c03f02eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f030;
P_0c03f030: /* original d322, guest PC 0x0c03f030 */
if(!s->budget--) { s->failed_pc=0x0c03f030u; return 0; }
r[3]=read(ram,0x0c03f0bcu,4);
goto P_0c03f032;
P_0c03f032: /* original e401, guest PC 0x0c03f032 */
if(!s->budget--) { s->failed_pc=0x0c03f032u; return 0; }
r[4]=0x00000001u;
goto P_0c03f034;
P_0c03f034: /* original 432b, guest PC 0x0c03f034 */
if(!s->budget--) { s->failed_pc=0x0c03f034u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c03f036: /* original 6ef6, guest PC 0x0c03f036 */
if(!s->budget--) { s->failed_pc=0x0c03f036u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03f038u,s,ram);
P_0c03ffd0: /* original 4f22, guest PC 0x0c03ffd0 */
if(!s->budget--) { s->failed_pc=0x0c03ffd0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03ffd2;
P_0c03ffd2: /* original 7ffc, guest PC 0x0c03ffd2 */
if(!s->budget--) { s->failed_pc=0x0c03ffd2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03ffd4;
P_0c03ffd4: /* original 2f42, guest PC 0x0c03ffd4 */
if(!s->budget--) { s->failed_pc=0x0c03ffd4u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03ffd6;
P_0c03ffd6: /* original d32a, guest PC 0x0c03ffd6 */
if(!s->budget--) { s->failed_pc=0x0c03ffd6u; return 0; }
r[3]=read(ram,0x0c040080u,4);
goto P_0c03ffd8;
P_0c03ffd8: /* original f58d, guest PC 0x0c03ffd8 */
if(!s->budget--) { s->failed_pc=0x0c03ffd8u; return 0; }
fr[5]=0;
goto P_0c03ffda;
P_0c03ffda: /* original 430b, guest PC 0x0c03ffda */
if(!s->budget--) { s->failed_pc=0x0c03ffdau; return 0; }
target=r[3];
r[16]=0x0c03ffdeu;
fr[4]=0;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ffdeu) { target=s->pc; goto dispatch; }
goto P_0c03ffde;
P_0c03ffdc: /* original f48d, guest PC 0x0c03ffdc */
if(!s->budget--) { s->failed_pc=0x0c03ffdcu; return 0; }
fr[4]=0;
goto P_0c03ffde;
P_0c03ffde: /* original 64f2, guest PC 0x0c03ffde */
if(!s->budget--) { s->failed_pc=0x0c03ffdeu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c03ffe0;
P_0c03ffe0: /* original 7f04, guest PC 0x0c03ffe0 */
if(!s->budget--) { s->failed_pc=0x0c03ffe0u; return 0; }
r[15]+=0x00000004u;
goto P_0c03ffe2;
P_0c03ffe2: /* original a015, guest PC 0x0c03ffe2 */
if(!s->budget--) { s->failed_pc=0x0c03ffe2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c040010;
P_0c03ffe4: /* original 4f26, guest PC 0x0c03ffe4 */
if(!s->budget--) { s->failed_pc=0x0c03ffe4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c03ffe6u,s,ram);
P_0c040010: /* original 2fe6, guest PC 0x0c040010 */
if(!s->budget--) { s->failed_pc=0x0c040010u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c040012;
P_0c040012: /* original 6e43, guest PC 0x0c040012 */
if(!s->budget--) { s->failed_pc=0x0c040012u; return 0; }
r[14]=r[4];
goto P_0c040014;
P_0c040014: /* original 63e2, guest PC 0x0c040014 */
if(!s->budget--) { s->failed_pc=0x0c040014u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c040016;
P_0c040016: /* original 4f22, guest PC 0x0c040016 */
if(!s->budget--) { s->failed_pc=0x0c040016u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c040018;
P_0c040018: /* original 4311, guest PC 0x0c040018 */
if(!s->budget--) { s->failed_pc=0x0c040018u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c04001a;
P_0c04001a: /* original 8b29, guest PC 0x0c04001a */
if(!s->budget--) { s->failed_pc=0x0c04001au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040070; }
goto P_0c04001c;
P_0c04001c: /* original 51e6, guest PC 0x0c04001c */
if(!s->budget--) { s->failed_pc=0x0c04001cu; return 0; }
r[1]=read(ram,r[14]+24,4);
goto P_0c04001e;
P_0c04001e: /* original 2118, guest PC 0x0c04001e */
if(!s->budget--) { s->failed_pc=0x0c04001eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c040020;
P_0c040020: /* original 8926, guest PC 0x0c040020 */
if(!s->budget--) { s->failed_pc=0x0c040020u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040070; }
goto P_0c040022;
P_0c040022: /* original d319, guest PC 0x0c040022 */
if(!s->budget--) { s->failed_pc=0x0c040022u; return 0; }
r[3]=read(ram,0x0c040088u,4);
goto P_0c040024;
P_0c040024: /* original e40c, guest PC 0x0c040024 */
if(!s->budget--) { s->failed_pc=0x0c040024u; return 0; }
r[4]=0x0000000cu;
goto P_0c040026;
P_0c040026: /* original 2342, guest PC 0x0c040026 */
if(!s->budget--) { s->failed_pc=0x0c040026u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c040028;
P_0c040028: /* original d218, guest PC 0x0c040028 */
if(!s->budget--) { s->failed_pc=0x0c040028u; return 0; }
r[2]=read(ram,0x0c04008cu,4);
goto P_0c04002a;
P_0c04002a: /* original 2242, guest PC 0x0c04002a */
if(!s->budget--) { s->failed_pc=0x0c04002au; return 0; }
write(ram,r[2],r[4],4);
goto P_0c04002c;
P_0c04002c: /* original d118, guest PC 0x0c04002c */
if(!s->budget--) { s->failed_pc=0x0c04002cu; return 0; }
r[1]=read(ram,0x0c040090u,4);
goto P_0c04002e;
P_0c04002e: /* original 410b, guest PC 0x0c04002e */
if(!s->budget--) { s->failed_pc=0x0c04002eu; return 0; }
target=r[1];
r[16]=0x0c040032u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c040032u) { target=s->pc; goto dispatch; }
goto P_0c040032;
P_0c040030: /* original e400, guest PC 0x0c040030 */
if(!s->budget--) { s->failed_pc=0x0c040030u; return 0; }
r[4]=0x00000000u;
goto P_0c040032;
P_0c040032: /* original d319, guest PC 0x0c040032 */
if(!s->budget--) { s->failed_pc=0x0c040032u; return 0; }
r[3]=read(ram,0x0c040098u,4);
goto P_0c040034;
P_0c040034: /* original d417, guest PC 0x0c040034 */
if(!s->budget--) { s->failed_pc=0x0c040034u; return 0; }
r[4]=read(ram,0x0c040094u,4);
goto P_0c040036;
P_0c040036: /* original 430b, guest PC 0x0c040036 */
if(!s->budget--) { s->failed_pc=0x0c040036u; return 0; }
target=r[3];
r[16]=0x0c04003au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04003au) { target=s->pc; goto dispatch; }
goto P_0c04003a;
P_0c040038: /* original 0009, guest PC 0x0c040038 */
if(!s->budget--) { s->failed_pc=0x0c040038u; return 0; }
goto P_0c04003a;
P_0c04003a: /* original d219, guest PC 0x0c04003a */
if(!s->budget--) { s->failed_pc=0x0c04003au; return 0; }
r[2]=read(ram,0x0c0400a0u,4);
goto P_0c04003c;
P_0c04003c: /* original d417, guest PC 0x0c04003c */
if(!s->budget--) { s->failed_pc=0x0c04003cu; return 0; }
r[4]=read(ram,0x0c04009cu,4);
goto P_0c04003e;
P_0c04003e: /* original 420b, guest PC 0x0c04003e */
if(!s->budget--) { s->failed_pc=0x0c04003eu; return 0; }
target=r[2];
r[16]=0x0c040042u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c040042u) { target=s->pc; goto dispatch; }
goto P_0c040042;
P_0c040040: /* original 0009, guest PC 0x0c040040 */
if(!s->budget--) { s->failed_pc=0x0c040040u; return 0; }
goto P_0c040042;
P_0c040042: /* original d119, guest PC 0x0c040042 */
if(!s->budget--) { s->failed_pc=0x0c040042u; return 0; }
r[1]=read(ram,0x0c0400a8u,4);
goto P_0c040044;
P_0c040044: /* original d019, guest PC 0x0c040044 */
if(!s->budget--) { s->failed_pc=0x0c040044u; return 0; }
r[0]=read(ram,0x0c0400acu,4);
goto P_0c040046;
P_0c040046: /* original 6212, guest PC 0x0c040046 */
if(!s->budget--) { s->failed_pc=0x0c040046u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c040048;
P_0c040048: /* original d316, guest PC 0x0c040048 */
if(!s->budget--) { s->failed_pc=0x0c040048u; return 0; }
r[3]=read(ram,0x0c0400a4u,4);
goto P_0c04004a;
P_0c04004a: /* original 4208, guest PC 0x0c04004a */
if(!s->budget--) { s->failed_pc=0x0c04004au; return 0; }
r[2]<<=2;
goto P_0c04004c;
P_0c04004c: /* original 022e, guest PC 0x0c04004c */
if(!s->budget--) { s->failed_pc=0x0c04004cu; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c04004e;
P_0c04004e: /* original 2322, guest PC 0x0c04004e */
if(!s->budget--) { s->failed_pc=0x0c04004eu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c040050;
P_0c040050: /* original e200, guest PC 0x0c040050 */
if(!s->budget--) { s->failed_pc=0x0c040050u; return 0; }
r[2]=0x00000000u;
goto P_0c040052;
P_0c040052: /* original 7304, guest PC 0x0c040052 */
if(!s->budget--) { s->failed_pc=0x0c040052u; return 0; }
r[3]+=0x00000004u;
goto P_0c040054;
P_0c040054: /* original 2322, guest PC 0x0c040054 */
if(!s->budget--) { s->failed_pc=0x0c040054u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c040056;
P_0c040056: /* original d217, guest PC 0x0c040056 */
if(!s->budget--) { s->failed_pc=0x0c040056u; return 0; }
r[2]=read(ram,0x0c0400b4u,4);
goto P_0c040058;
P_0c040058: /* original d115, guest PC 0x0c040058 */
if(!s->budget--) { s->failed_pc=0x0c040058u; return 0; }
r[1]=read(ram,0x0c0400b0u,4);
goto P_0c04005a;
P_0c04005a: /* original 2122, guest PC 0x0c04005a */
if(!s->budget--) { s->failed_pc=0x0c04005au; return 0; }
write(ram,r[1],r[2],4);
goto P_0c04005c;
P_0c04005c: /* original d216, guest PC 0x0c04005c */
if(!s->budget--) { s->failed_pc=0x0c04005cu; return 0; }
r[2]=read(ram,0x0c0400b8u,4);
goto P_0c04005e;
P_0c04005e: /* original d511, guest PC 0x0c04005e */
if(!s->budget--) { s->failed_pc=0x0c04005eu; return 0; }
r[5]=read(ram,0x0c0400a4u,4);
goto P_0c040060;
P_0c040060: /* original 420b, guest PC 0x0c040060 */
if(!s->budget--) { s->failed_pc=0x0c040060u; return 0; }
target=r[2];
r[16]=0x0c040064u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c040064u) { target=s->pc; goto dispatch; }
goto P_0c040064;
P_0c040062: /* original 64e3, guest PC 0x0c040062 */
if(!s->budget--) { s->failed_pc=0x0c040062u; return 0; }
r[4]=r[14];
goto P_0c040064;
P_0c040064: /* original 4f26, guest PC 0x0c040064 */
if(!s->budget--) { s->failed_pc=0x0c040064u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c040066;
P_0c040066: /* original d315, guest PC 0x0c040066 */
if(!s->budget--) { s->failed_pc=0x0c040066u; return 0; }
r[3]=read(ram,0x0c0400bcu,4);
goto P_0c040068;
P_0c040068: /* original e401, guest PC 0x0c040068 */
if(!s->budget--) { s->failed_pc=0x0c040068u; return 0; }
r[4]=0x00000001u;
goto P_0c04006a;
P_0c04006a: /* original 432b, guest PC 0x0c04006a */
if(!s->budget--) { s->failed_pc=0x0c04006au; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c04006c: /* original 6ef6, guest PC 0x0c04006c */
if(!s->budget--) { s->failed_pc=0x0c04006cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04006eu,s,ram);
P_0c040070: /* original 4f26, guest PC 0x0c040070 */
if(!s->budget--) { s->failed_pc=0x0c040070u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c040072;
P_0c040072: /* original 000b, guest PC 0x0c040072 */
if(!s->budget--) { s->failed_pc=0x0c040072u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c040074: /* original 6ef6, guest PC 0x0c040074 */
if(!s->budget--) { s->failed_pc=0x0c040074u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c040076u,s,ram);
P_0c04396e: /* original 4f22, guest PC 0x0c04396e */
if(!s->budget--) { s->failed_pc=0x0c04396eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043970;
P_0c043970: /* original 2232, guest PC 0x0c043970 */
if(!s->budget--) { s->failed_pc=0x0c043970u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c043972;
P_0c043972: /* original d037, guest PC 0x0c043972 */
if(!s->budget--) { s->failed_pc=0x0c043972u; return 0; }
r[0]=read(ram,0x0c043a50u,4);
goto P_0c043974;
P_0c043974: /* original 6302, guest PC 0x0c043974 */
if(!s->budget--) { s->failed_pc=0x0c043974u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c043976;
P_0c043976: /* original 7301, guest PC 0x0c043976 */
if(!s->budget--) { s->failed_pc=0x0c043976u; return 0; }
r[3]+=0x00000001u;
goto P_0c043978;
P_0c043978: /* original 2032, guest PC 0x0c043978 */
if(!s->budget--) { s->failed_pc=0x0c043978u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c04397a;
P_0c04397a: /* original de36, guest PC 0x0c04397a */
if(!s->budget--) { s->failed_pc=0x0c04397au; return 0; }
r[14]=read(ram,0x0c043a54u,4);
goto P_0c04397c;
P_0c04397c: /* original 52e2, guest PC 0x0c04397c */
if(!s->budget--) { s->failed_pc=0x0c04397cu; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c04397e;
P_0c04397e: /* original 7201, guest PC 0x0c04397e */
if(!s->budget--) { s->failed_pc=0x0c04397eu; return 0; }
r[2]+=0x00000001u;
goto P_0c043980;
P_0c043980: /* original 1e22, guest PC 0x0c043980 */
if(!s->budget--) { s->failed_pc=0x0c043980u; return 0; }
write(ram,r[14]+8,r[2],4);
goto P_0c043982;
P_0c043982: /* original d235, guest PC 0x0c043982 */
if(!s->budget--) { s->failed_pc=0x0c043982u; return 0; }
r[2]=read(ram,0x0c043a58u,4);
goto P_0c043984;
P_0c043984: /* original 6322, guest PC 0x0c043984 */
if(!s->budget--) { s->failed_pc=0x0c043984u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c043986;
P_0c043986: /* original 2338, guest PC 0x0c043986 */
if(!s->budget--) { s->failed_pc=0x0c043986u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c043988;
P_0c043988: /* original 890d, guest PC 0x0c043988 */
if(!s->budget--) { s->failed_pc=0x0c043988u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0439a6; }
goto P_0c04398a;
P_0c04398a: /* original 53e5, guest PC 0x0c04398a */
if(!s->budget--) { s->failed_pc=0x0c04398au; return 0; }
r[3]=read(ram,r[14]+20,4);
goto P_0c04398c;
P_0c04398c: /* original 7301, guest PC 0x0c04398c */
if(!s->budget--) { s->failed_pc=0x0c04398cu; return 0; }
r[3]+=0x00000001u;
goto P_0c04398e;
P_0c04398e: /* original 1e35, guest PC 0x0c04398e */
if(!s->budget--) { s->failed_pc=0x0c04398eu; return 0; }
write(ram,r[14]+20,r[3],4);
goto P_0c043990;
P_0c043990: /* original d132, guest PC 0x0c043990 */
if(!s->budget--) { s->failed_pc=0x0c043990u; return 0; }
r[1]=read(ram,0x0c043a5cu,4);
goto P_0c043992;
P_0c043992: /* original 6d12, guest PC 0x0c043992 */
if(!s->budget--) { s->failed_pc=0x0c043992u; return 0; }
tmp=read(ram,r[1],4);
r[13]=tmp;
goto P_0c043994;
P_0c043994: /* original 2dd8, guest PC 0x0c043994 */
if(!s->budget--) { s->failed_pc=0x0c043994u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c043996;
P_0c043996: /* original 890c, guest PC 0x0c043996 */
if(!s->budget--) { s->failed_pc=0x0c043996u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0439b2; }
goto P_0c043998;
P_0c043998: /* original 56e2, guest PC 0x0c043998 */
if(!s->budget--) { s->failed_pc=0x0c043998u; return 0; }
r[6]=read(ram,r[14]+8,4);
goto P_0c04399a;
P_0c04399a: /* original e5ff, guest PC 0x0c04399a */
if(!s->budget--) { s->failed_pc=0x0c04399au; return 0; }
r[5]=0xffffffffu;
goto P_0c04399c;
P_0c04399c: /* original e700, guest PC 0x0c04399c */
if(!s->budget--) { s->failed_pc=0x0c04399cu; return 0; }
r[7]=0x00000000u;
goto P_0c04399e;
P_0c04399e: /* original 4d0b, guest PC 0x0c04399e */
if(!s->budget--) { s->failed_pc=0x0c04399eu; return 0; }
target=r[13];
r[16]=0x0c0439a2u;
r[4]=r[7];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0439a2u) { target=s->pc; goto dispatch; }
goto P_0c0439a2;
P_0c0439a0: /* original 6473, guest PC 0x0c0439a0 */
if(!s->budget--) { s->failed_pc=0x0c0439a0u; return 0; }
r[4]=r[7];
goto P_0c0439a2;
P_0c0439a2: /* original a006, guest PC 0x0c0439a2 */
if(!s->budget--) { s->failed_pc=0x0c0439a2u; return 0; }
goto P_0c0439b2;
P_0c0439a4: /* original 0009, guest PC 0x0c0439a4 */
if(!s->budget--) { s->failed_pc=0x0c0439a4u; return 0; }
goto P_0c0439a6;
P_0c0439a6: /* original b105, guest PC 0x0c0439a6 */
if(!s->budget--) { s->failed_pc=0x0c0439a6u; return 0; }
target=0x0c043bb4u; r[16]=0x0c0439aau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0439aau) { target=s->pc; goto dispatch; }
goto P_0c0439aa;
P_0c0439a8: /* original 0009, guest PC 0x0c0439a8 */
if(!s->budget--) { s->failed_pc=0x0c0439a8u; return 0; }
goto P_0c0439aa;
P_0c0439aa: /* original d128, guest PC 0x0c0439aa */
if(!s->budget--) { s->failed_pc=0x0c0439aau; return 0; }
r[1]=read(ram,0x0c043a4cu,4);
goto P_0c0439ac;
P_0c0439ac: /* original d32c, guest PC 0x0c0439ac */
if(!s->budget--) { s->failed_pc=0x0c0439acu; return 0; }
r[3]=read(ram,0x0c043a60u,4);
goto P_0c0439ae;
P_0c0439ae: /* original 6212, guest PC 0x0c0439ae */
if(!s->budget--) { s->failed_pc=0x0c0439aeu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0439b0;
P_0c0439b0: /* original 2322, guest PC 0x0c0439b0 */
if(!s->budget--) { s->failed_pc=0x0c0439b0u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0439b2;
P_0c0439b2: /* original 4f26, guest PC 0x0c0439b2 */
if(!s->budget--) { s->failed_pc=0x0c0439b2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0439b4;
P_0c0439b4: /* original 6df6, guest PC 0x0c0439b4 */
if(!s->budget--) { s->failed_pc=0x0c0439b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0439b6;
P_0c0439b6: /* original 000b, guest PC 0x0c0439b6 */
if(!s->budget--) { s->failed_pc=0x0c0439b6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0439b8: /* original 6ef6, guest PC 0x0c0439b8 */
if(!s->budget--) { s->failed_pc=0x0c0439b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0439bau,s,ram);
P_0c0439c0: /* original 4f22, guest PC 0x0c0439c0 */
if(!s->budget--) { s->failed_pc=0x0c0439c0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0439c2;
P_0c0439c2: /* original 2322, guest PC 0x0c0439c2 */
if(!s->budget--) { s->failed_pc=0x0c0439c2u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0439c4;
P_0c0439c4: /* original d028, guest PC 0x0c0439c4 */
if(!s->budget--) { s->failed_pc=0x0c0439c4u; return 0; }
r[0]=read(ram,0x0c043a68u,4);
goto P_0c0439c6;
P_0c0439c6: /* original 7ffc, guest PC 0x0c0439c6 */
if(!s->budget--) { s->failed_pc=0x0c0439c6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0439c8;
P_0c0439c8: /* original 6302, guest PC 0x0c0439c8 */
if(!s->budget--) { s->failed_pc=0x0c0439c8u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c0439ca;
P_0c0439ca: /* original 7301, guest PC 0x0c0439ca */
if(!s->budget--) { s->failed_pc=0x0c0439cau; return 0; }
r[3]+=0x00000001u;
goto P_0c0439cc;
P_0c0439cc: /* original 2032, guest PC 0x0c0439cc */
if(!s->budget--) { s->failed_pc=0x0c0439ccu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c0439ce;
P_0c0439ce: /* original 0002, guest PC 0x0c0439ce */
if(!s->budget--) { s->failed_pc=0x0c0439ceu; return 0; }
r[0]=r[17];
goto P_0c0439d0;
P_0c0439d0: /* original 4009, guest PC 0x0c0439d0 */
if(!s->budget--) { s->failed_pc=0x0c0439d0u; return 0; }
r[0]>>=2;
goto P_0c0439d2;
P_0c0439d2: /* original 4009, guest PC 0x0c0439d2 */
if(!s->budget--) { s->failed_pc=0x0c0439d2u; return 0; }
r[0]>>=2;
goto P_0c0439d4;
P_0c0439d4: /* original c90f, guest PC 0x0c0439d4 */
if(!s->budget--) { s->failed_pc=0x0c0439d4u; return 0; }
r[0]&=15u;
goto P_0c0439d6;
P_0c0439d6: /* original 2f02, guest PC 0x0c0439d6 */
if(!s->budget--) { s->failed_pc=0x0c0439d6u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0439d8;
P_0c0439d8: /* original 0002, guest PC 0x0c0439d8 */
if(!s->budget--) { s->failed_pc=0x0c0439d8u; return 0; }
r[0]=r[17];
goto P_0c0439da;
P_0c0439da: /* original 932d, guest PC 0x0c0439da */
if(!s->budget--) { s->failed_pc=0x0c0439dau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043a38u,2);
goto P_0c0439dc;
P_0c0439dc: /* original 2039, guest PC 0x0c0439dc */
if(!s->budget--) { s->failed_pc=0x0c0439dcu; return 0; }
r[0]&=r[3];
goto P_0c0439de;
P_0c0439de: /* original cbf0, guest PC 0x0c0439de */
if(!s->budget--) { s->failed_pc=0x0c0439deu; return 0; }
r[0]|=240u;
goto P_0c0439e0;
P_0c0439e0: /* original 400e, guest PC 0x0c0439e0 */
if(!s->budget--) { s->failed_pc=0x0c0439e0u; return 0; }
r[17]=r[0];
goto P_0c0439e2;
P_0c0439e2: /* original d222, guest PC 0x0c0439e2 */
if(!s->budget--) { s->failed_pc=0x0c0439e2u; return 0; }
r[2]=read(ram,0x0c043a6cu,4);
goto P_0c0439e4;
P_0c0439e4: /* original 6022, guest PC 0x0c0439e4 */
if(!s->budget--) { s->failed_pc=0x0c0439e4u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0439e6;
P_0c0439e6: /* original 7001, guest PC 0x0c0439e6 */
if(!s->budget--) { s->failed_pc=0x0c0439e6u; return 0; }
r[0]+=0x00000001u;
goto P_0c0439e8;
P_0c0439e8: /* original b18c, guest PC 0x0c0439e8 */
if(!s->budget--) { s->failed_pc=0x0c0439e8u; return 0; }
target=0x0c043d04u; r[16]=0x0c0439ecu;
write(ram,r[2],r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0439ecu) { target=s->pc; goto dispatch; }
goto P_0c0439ec;
P_0c0439ea: /* original 2202, guest PC 0x0c0439ea */
if(!s->budget--) { s->failed_pc=0x0c0439eau; return 0; }
write(ram,r[2],r[0],4);
goto P_0c0439ec;
P_0c0439ec: /* original 60f2, guest PC 0x0c0439ec */
if(!s->budget--) { s->failed_pc=0x0c0439ecu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0439ee;
P_0c0439ee: /* original 0202, guest PC 0x0c0439ee */
if(!s->budget--) { s->failed_pc=0x0c0439eeu; return 0; }
r[2]=r[17];
goto P_0c0439f0;
P_0c0439f0: /* original 9322, guest PC 0x0c0439f0 */
if(!s->budget--) { s->failed_pc=0x0c0439f0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043a38u,2);
goto P_0c0439f2;
P_0c0439f2: /* original c90f, guest PC 0x0c0439f2 */
if(!s->budget--) { s->failed_pc=0x0c0439f2u; return 0; }
r[0]&=15u;
goto P_0c0439f4;
P_0c0439f4: /* original 4008, guest PC 0x0c0439f4 */
if(!s->budget--) { s->failed_pc=0x0c0439f4u; return 0; }
r[0]<<=2;
goto P_0c0439f6;
P_0c0439f6: /* original 2239, guest PC 0x0c0439f6 */
if(!s->budget--) { s->failed_pc=0x0c0439f6u; return 0; }
r[2]&=r[3];
goto P_0c0439f8;
P_0c0439f8: /* original 4008, guest PC 0x0c0439f8 */
if(!s->budget--) { s->failed_pc=0x0c0439f8u; return 0; }
r[0]<<=2;
goto P_0c0439fa;
P_0c0439fa: /* original 202b, guest PC 0x0c0439fa */
if(!s->budget--) { s->failed_pc=0x0c0439fau; return 0; }
r[0]|=r[2];
goto P_0c0439fc;
P_0c0439fc: /* original 400e, guest PC 0x0c0439fc */
if(!s->budget--) { s->failed_pc=0x0c0439fcu; return 0; }
r[17]=r[0];
goto P_0c0439fe;
P_0c0439fe: /* original d213, guest PC 0x0c0439fe */
if(!s->budget--) { s->failed_pc=0x0c0439feu; return 0; }
r[2]=read(ram,0x0c043a4cu,4);
goto P_0c043a00;
P_0c043a00: /* original 7f04, guest PC 0x0c043a00 */
if(!s->budget--) { s->failed_pc=0x0c043a00u; return 0; }
r[15]+=0x00000004u;
goto P_0c043a02;
P_0c043a02: /* original 4f26, guest PC 0x0c043a02 */
if(!s->budget--) { s->failed_pc=0x0c043a02u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043a04;
P_0c043a04: /* original d11a, guest PC 0x0c043a04 */
if(!s->budget--) { s->failed_pc=0x0c043a04u; return 0; }
r[1]=read(ram,0x0c043a70u,4);
goto P_0c043a06;
P_0c043a06: /* original 6322, guest PC 0x0c043a06 */
if(!s->budget--) { s->failed_pc=0x0c043a06u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c043a08;
P_0c043a08: /* original 2132, guest PC 0x0c043a08 */
if(!s->budget--) { s->failed_pc=0x0c043a08u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c043a0a;
P_0c043a0a: /* original 000b, guest PC 0x0c043a0a */
if(!s->budget--) { s->failed_pc=0x0c043a0au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c043a0c: /* original 0009, guest PC 0x0c043a0c */
if(!s->budget--) { s->failed_pc=0x0c043a0cu; return 0; }
return vf3_matrix_family(0x0c043a0eu,s,ram);
P_0c0441b6: /* original 6743, guest PC 0x0c0441b6 */
if(!s->budget--) { s->failed_pc=0x0c0441b6u; return 0; }
r[7]=r[4];
goto P_0c0441b8;
P_0c0441b8: /* original 2fc6, guest PC 0x0c0441b8 */
if(!s->budget--) { s->failed_pc=0x0c0441b8u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0441ba;
P_0c0441ba: /* original d63d, guest PC 0x0c0441ba */
if(!s->budget--) { s->failed_pc=0x0c0441bau; return 0; }
r[6]=read(ram,0x0c0442b0u,4);
goto P_0c0441bc;
P_0c0441bc: /* original e020, guest PC 0x0c0441bc */
if(!s->budget--) { s->failed_pc=0x0c0441bcu; return 0; }
r[0]=0x00000020u;
goto P_0c0441be;
P_0c0441be: /* original 6c46, guest PC 0x0c0441be */
if(!s->budget--) { s->failed_pc=0x0c0441beu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[12]=tmp;
goto P_0c0441c0;
P_0c0441c0: /* original 7704, guest PC 0x0c0441c0 */
if(!s->budget--) { s->failed_pc=0x0c0441c0u; return 0; }
r[7]+=0x00000004u;
goto P_0c0441c2;
P_0c0441c2: /* original e100, guest PC 0x0c0441c2 */
if(!s->budget--) { s->failed_pc=0x0c0441c2u; return 0; }
r[1]=0x00000000u;
goto P_0c0441c4;
P_0c0441c4: /* original 6363, guest PC 0x0c0441c4 */
if(!s->budget--) { s->failed_pc=0x0c0441c4u; return 0; }
r[3]=r[6];
goto P_0c0441c6;
P_0c0441c6: /* original 23c8, guest PC 0x0c0441c6 */
if(!s->budget--) { s->failed_pc=0x0c0441c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0441c8;
P_0c0441c8: /* original 8906, guest PC 0x0c0441c8 */
if(!s->budget--) { s->failed_pc=0x0c0441c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0441d8; }
goto P_0c0441ca;
P_0c0441ca: /* original 3560, guest PC 0x0c0441ca */
if(!s->budget--) { s->failed_pc=0x0c0441cau; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c0441cc;
P_0c0441cc: /* original 8b02, guest PC 0x0c0441cc */
if(!s->budget--) { s->failed_pc=0x0c0441ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0441d4; }
goto P_0c0441ce;
P_0c0441ce: /* original 6073, guest PC 0x0c0441ce */
if(!s->budget--) { s->failed_pc=0x0c0441ceu; return 0; }
r[0]=r[7];
goto P_0c0441d0;
P_0c0441d0: /* original 000b, guest PC 0x0c0441d0 */
if(!s->budget--) { s->failed_pc=0x0c0441d0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
s->pc=target; return ram->oob==0;
P_0c0441d2: /* original 6cf6, guest PC 0x0c0441d2 */
if(!s->budget--) { s->failed_pc=0x0c0441d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0441d4;
P_0c0441d4: /* original 7404, guest PC 0x0c0441d4 */
if(!s->budget--) { s->failed_pc=0x0c0441d4u; return 0; }
r[4]+=0x00000004u;
goto P_0c0441d6;
P_0c0441d6: /* original 6743, guest PC 0x0c0441d6 */
if(!s->budget--) { s->failed_pc=0x0c0441d6u; return 0; }
r[7]=r[4];
goto P_0c0441d8;
P_0c0441d8: /* original 7101, guest PC 0x0c0441d8 */
if(!s->budget--) { s->failed_pc=0x0c0441d8u; return 0; }
r[1]+=0x00000001u;
goto P_0c0441da;
P_0c0441da: /* original 4601, guest PC 0x0c0441da */
if(!s->budget--) { s->failed_pc=0x0c0441dau; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c0441dc;
P_0c0441dc: /* original 3102, guest PC 0x0c0441dc */
if(!s->budget--) { s->failed_pc=0x0c0441dcu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[0])!=0);
goto P_0c0441de;
P_0c0441de: /* original 8bf1, guest PC 0x0c0441de */
if(!s->budget--) { s->failed_pc=0x0c0441deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0441c4; }
goto P_0c0441e0;
P_0c0441e0: /* original e000, guest PC 0x0c0441e0 */
if(!s->budget--) { s->failed_pc=0x0c0441e0u; return 0; }
r[0]=0x00000000u;
goto P_0c0441e2;
P_0c0441e2: /* original 000b, guest PC 0x0c0441e2 */
if(!s->budget--) { s->failed_pc=0x0c0441e2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
s->pc=target; return ram->oob==0;
P_0c0441e4: /* original 6cf6, guest PC 0x0c0441e4 */
if(!s->budget--) { s->failed_pc=0x0c0441e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
return vf3_matrix_family(0x0c0441e6u,s,ram);
P_0c044c7c: /* original d531, guest PC 0x0c044c7c */
if(!s->budget--) { s->failed_pc=0x0c044c7cu; return 0; }
r[5]=read(ram,0x0c044d44u,4);
goto P_0c044c7e;
P_0c044c7e: /* original 4415, guest PC 0x0c044c7e */
if(!s->budget--) { s->failed_pc=0x0c044c7eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c044c80;
P_0c044c80: /* original 9049, guest PC 0x0c044c80 */
if(!s->budget--) { s->failed_pc=0x0c044c80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044d16u,2);
goto P_0c044c82;
P_0c044c82: /* original 6352, guest PC 0x0c044c82 */
if(!s->budget--) { s->failed_pc=0x0c044c82u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c044c84;
P_0c044c84: /* original 6103, guest PC 0x0c044c84 */
if(!s->budget--) { s->failed_pc=0x0c044c84u; return 0; }
r[1]=r[0];
goto P_0c044c86;
P_0c044c86: /* original 710c, guest PC 0x0c044c86 */
if(!s->budget--) { s->failed_pc=0x0c044c86u; return 0; }
r[1]+=0x0000000cu;
goto P_0c044c88;
P_0c044c88: /* original 6233, guest PC 0x0c044c88 */
if(!s->budget--) { s->failed_pc=0x0c044c88u; return 0; }
r[2]=r[3];
goto P_0c044c8a;
P_0c044c8a: /* original 312c, guest PC 0x0c044c8a */
if(!s->budget--) { s->failed_pc=0x0c044c8au; return 0; }
r[1]+=r[2];
goto P_0c044c8c;
P_0c044c8c: /* original 6112, guest PC 0x0c044c8c */
if(!s->budget--) { s->failed_pc=0x0c044c8cu; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c044c8e;
P_0c044c8e: /* original 023e, guest PC 0x0c044c8e */
if(!s->budget--) { s->failed_pc=0x0c044c8eu; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c044c90;
P_0c044c90: /* original 4108, guest PC 0x0c044c90 */
if(!s->budget--) { s->failed_pc=0x0c044c90u; return 0; }
r[1]<<=2;
goto P_0c044c92;
P_0c044c92: /* original 321c, guest PC 0x0c044c92 */
if(!s->budget--) { s->failed_pc=0x0c044c92u; return 0; }
r[2]+=r[1];
goto P_0c044c94;
P_0c044c94: /* original 0326, guest PC 0x0c044c94 */
if(!s->budget--) { s->failed_pc=0x0c044c94u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044c96;
P_0c044c96: /* original 6152, guest PC 0x0c044c96 */
if(!s->budget--) { s->failed_pc=0x0c044c96u; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c044c98;
P_0c044c98: /* original 973e, guest PC 0x0c044c98 */
if(!s->budget--) { s->failed_pc=0x0c044c98u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044d18u,2);
goto P_0c044c9a;
P_0c044c9a: /* original 011e, guest PC 0x0c044c9a */
if(!s->budget--) { s->failed_pc=0x0c044c9au; return 0; }
r[1]=read(ram,r[1]+r[0],4);
goto P_0c044c9c;
P_0c044c9c: /* original 8f05, guest PC 0x0c044c9c */
if(!s->budget--) { s->failed_pc=0x0c044c9cu; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(!cond) { goto P_0c044caa; }
goto P_0c044ca0;
P_0c044c9e: /* original e600, guest PC 0x0c044c9e */
if(!s->budget--) { s->failed_pc=0x0c044c9eu; return 0; }
r[6]=0x00000000u;
goto P_0c044ca0;
P_0c044ca0: /* original 7601, guest PC 0x0c044ca0 */
if(!s->budget--) { s->failed_pc=0x0c044ca0u; return 0; }
r[6]+=0x00000001u;
goto P_0c044ca2;
P_0c044ca2: /* original 2172, guest PC 0x0c044ca2 */
if(!s->budget--) { s->failed_pc=0x0c044ca2u; return 0; }
write(ram,r[1],r[7],4);
goto P_0c044ca4;
P_0c044ca4: /* original 3643, guest PC 0x0c044ca4 */
if(!s->budget--) { s->failed_pc=0x0c044ca4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[4])!=0);
goto P_0c044ca6;
P_0c044ca6: /* original 8ffb, guest PC 0x0c044ca6 */
if(!s->budget--) { s->failed_pc=0x0c044ca6u; return 0; }
cond=r[17]&1u;
r[1]+=0x00000004u;
if(!cond) { goto P_0c044ca0; }
goto P_0c044caa;
P_0c044ca8: /* original 7104, guest PC 0x0c044ca8 */
if(!s->budget--) { s->failed_pc=0x0c044ca8u; return 0; }
r[1]+=0x00000004u;
goto P_0c044caa;
P_0c044caa: /* original 9036, guest PC 0x0c044caa */
if(!s->budget--) { s->failed_pc=0x0c044caau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044d1au,2);
goto P_0c044cac;
P_0c044cac: /* original 6252, guest PC 0x0c044cac */
if(!s->budget--) { s->failed_pc=0x0c044cacu; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c044cae;
P_0c044cae: /* original 0246, guest PC 0x0c044cae */
if(!s->budget--) { s->failed_pc=0x0c044caeu; return 0; }
write(ram,r[2]+r[0],r[4],4);
goto P_0c044cb0;
P_0c044cb0: /* original 7004, guest PC 0x0c044cb0 */
if(!s->budget--) { s->failed_pc=0x0c044cb0u; return 0; }
r[0]+=0x00000004u;
goto P_0c044cb2;
P_0c044cb2: /* original 6352, guest PC 0x0c044cb2 */
if(!s->budget--) { s->failed_pc=0x0c044cb2u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c044cb4;
P_0c044cb4: /* original 4408, guest PC 0x0c044cb4 */
if(!s->budget--) { s->failed_pc=0x0c044cb4u; return 0; }
r[4]<<=2;
goto P_0c044cb6;
P_0c044cb6: /* original 023e, guest PC 0x0c044cb6 */
if(!s->budget--) { s->failed_pc=0x0c044cb6u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c044cb8;
P_0c044cb8: /* original 324c, guest PC 0x0c044cb8 */
if(!s->budget--) { s->failed_pc=0x0c044cb8u; return 0; }
r[2]+=r[4];
goto P_0c044cba;
P_0c044cba: /* original 0326, guest PC 0x0c044cba */
if(!s->budget--) { s->failed_pc=0x0c044cbau; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044cbc;
P_0c044cbc: /* original 000b, guest PC 0x0c044cbc */
if(!s->budget--) { s->failed_pc=0x0c044cbcu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c044cbe: /* original e000, guest PC 0x0c044cbe */
if(!s->budget--) { s->failed_pc=0x0c044cbeu; return 0; }
r[0]=0x00000000u;
goto P_0c044cc0;
P_0c044cc0: /* original 2fe6, guest PC 0x0c044cc0 */
if(!s->budget--) { s->failed_pc=0x0c044cc0u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c044cc2;
P_0c044cc2: /* original e044, guest PC 0x0c044cc2 */
if(!s->budget--) { s->failed_pc=0x0c044cc2u; return 0; }
r[0]=0x00000044u;
goto P_0c044cc4;
P_0c044cc4: /* original 2fd6, guest PC 0x0c044cc4 */
if(!s->budget--) { s->failed_pc=0x0c044cc4u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c044cc6;
P_0c044cc6: /* original 2fc6, guest PC 0x0c044cc6 */
if(!s->budget--) { s->failed_pc=0x0c044cc6u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c044cc8;
P_0c044cc8: /* original 2fb6, guest PC 0x0c044cc8 */
if(!s->budget--) { s->failed_pc=0x0c044cc8u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c044cca;
P_0c044cca: /* original 6b73, guest PC 0x0c044cca */
if(!s->budget--) { s->failed_pc=0x0c044ccau; return 0; }
r[11]=r[7];
goto P_0c044ccc;
P_0c044ccc: /* original 2fa6, guest PC 0x0c044ccc */
if(!s->budget--) { s->failed_pc=0x0c044cccu; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c044cce;
P_0c044cce: /* original 2f96, guest PC 0x0c044cce */
if(!s->budget--) { s->failed_pc=0x0c044cceu; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c044cd0;
P_0c044cd0: /* original 6943, guest PC 0x0c044cd0 */
if(!s->budget--) { s->failed_pc=0x0c044cd0u; return 0; }
r[9]=r[4];
goto P_0c044cd2;
P_0c044cd2: /* original 2f86, guest PC 0x0c044cd2 */
if(!s->budget--) { s->failed_pc=0x0c044cd2u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c044cd4;
P_0c044cd4: /* original 4f22, guest PC 0x0c044cd4 */
if(!s->budget--) { s->failed_pc=0x0c044cd4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c044cd6;
P_0c044cd6: /* original 4f12, guest PC 0x0c044cd6 */
if(!s->budget--) { s->failed_pc=0x0c044cd6u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c044cd8;
P_0c044cd8: /* original 7fe4, guest PC 0x0c044cd8 */
if(!s->budget--) { s->failed_pc=0x0c044cd8u; return 0; }
r[15]+=0xffffffe4u;
goto P_0c044cda;
P_0c044cda: /* original 2f50, guest PC 0x0c044cda */
if(!s->budget--) { s->failed_pc=0x0c044cdau; return 0; }
write(ram,r[15],r[5],1);
goto P_0c044cdc;
P_0c044cdc: /* original 1f66, guest PC 0x0c044cdc */
if(!s->budget--) { s->failed_pc=0x0c044cdcu; return 0; }
write(ram,r[15]+24,r[6],4);
goto P_0c044cde;
P_0c044cde: /* original 63f0, guest PC 0x0c044cde */
if(!s->budget--) { s->failed_pc=0x0c044cdeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[3]=tmp;
goto P_0c044ce0;
P_0c044ce0: /* original 0cfe, guest PC 0x0c044ce0 */
if(!s->budget--) { s->failed_pc=0x0c044ce0u; return 0; }
r[12]=read(ram,r[15]+r[0],4);
goto P_0c044ce2;
P_0c044ce2: /* original 633c, guest PC 0x0c044ce2 */
if(!s->budget--) { s->failed_pc=0x0c044ce2u; return 0; }
r[3]=r[3]&255u;
goto P_0c044ce4;
P_0c044ce4: /* original 1f31, guest PC 0x0c044ce4 */
if(!s->budget--) { s->failed_pc=0x0c044ce4u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c044ce6;
P_0c044ce6: /* original 2f36, guest PC 0x0c044ce6 */
if(!s->budget--) { s->failed_pc=0x0c044ce6u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c044ce8;
P_0c044ce8: /* original 2f96, guest PC 0x0c044ce8 */
if(!s->budget--) { s->failed_pc=0x0c044ce8u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c044cea;
P_0c044cea: /* original d217, guest PC 0x0c044cea */
if(!s->budget--) { s->failed_pc=0x0c044ceau; return 0; }
r[2]=read(ram,0x0c044d48u,4);
goto P_0c044cec;
P_0c044cec: /* original d117, guest PC 0x0c044cec */
if(!s->budget--) { s->failed_pc=0x0c044cecu; return 0; }
r[1]=read(ram,0x0c044d4cu,4);
goto P_0c044cee;
P_0c044cee: /* original 410b, guest PC 0x0c044cee */
if(!s->budget--) { s->failed_pc=0x0c044ceeu; return 0; }
target=r[1];
r[16]=0x0c044cf2u;
r[15]-=4; write(ram,r[15],r[2],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c044cf2u) { target=s->pc; goto dispatch; }
goto P_0c044cf2;
P_0c044cf0: /* original 2f26, guest PC 0x0c044cf0 */
if(!s->budget--) { s->failed_pc=0x0c044cf0u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c044cf2;
P_0c044cf2: /* original ea2c, guest PC 0x0c044cf2 */
if(!s->budget--) { s->failed_pc=0x0c044cf2u; return 0; }
r[10]=0x0000002cu;
goto P_0c044cf4;
P_0c044cf4: /* original de13, guest PC 0x0c044cf4 */
if(!s->budget--) { s->failed_pc=0x0c044cf4u; return 0; }
r[14]=read(ram,0x0c044d44u,4);
goto P_0c044cf6;
P_0c044cf6: /* original 29af, guest PC 0x0c044cf6 */
if(!s->budget--) { s->failed_pc=0x0c044cf6u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[9]*(int32_t)(int16_t)r[10]);
goto P_0c044cf8;
P_0c044cf8: /* original 64e2, guest PC 0x0c044cf8 */
if(!s->budget--) { s->failed_pc=0x0c044cf8u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c044cfa;
P_0c044cfa: /* original 6343, guest PC 0x0c044cfa */
if(!s->budget--) { s->failed_pc=0x0c044cfau; return 0; }
r[3]=r[4];
goto P_0c044cfc;
P_0c044cfc: /* original 7328, guest PC 0x0c044cfc */
if(!s->budget--) { s->failed_pc=0x0c044cfcu; return 0; }
r[3]+=0x00000028u;
goto P_0c044cfe;
P_0c044cfe: /* original 0a1a, guest PC 0x0c044cfe */
if(!s->budget--) { s->failed_pc=0x0c044cfeu; return 0; }
r[10]=r[19];
goto P_0c044d00;
P_0c044d00: /* original 6aaf, guest PC 0x0c044d00 */
if(!s->budget--) { s->failed_pc=0x0c044d00u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)r[10];
goto P_0c044d02;
P_0c044d02: /* original 33ac, guest PC 0x0c044d02 */
if(!s->budget--) { s->failed_pc=0x0c044d02u; return 0; }
r[3]+=r[10];
goto P_0c044d04;
P_0c044d04: /* original 8436, guest PC 0x0c044d04 */
if(!s->budget--) { s->failed_pc=0x0c044d04u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+6,1);
goto P_0c044d06;
P_0c044d06: /* original 2008, guest PC 0x0c044d06 */
if(!s->budget--) { s->failed_pc=0x0c044d06u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c044d08;
P_0c044d08: /* original 8d22, guest PC 0x0c044d08 */
if(!s->budget--) { s->failed_pc=0x0c044d08u; return 0; }
cond=r[17]&1u;
r[15]+=0x0000000cu;
if(cond) { goto P_0c044d50; }
goto P_0c044d0c;
P_0c044d0a: /* original 7f0c, guest PC 0x0c044d0a */
if(!s->budget--) { s->failed_pc=0x0c044d0au; return 0; }
r[15]+=0x0000000cu;
goto P_0c044d0c;
P_0c044d0c: /* original a12b, guest PC 0x0c044d0c */
if(!s->budget--) { s->failed_pc=0x0c044d0cu; return 0; }
r[0]=0xffffffffu;
goto P_0c044f66;
P_0c044d0e: /* original e0ff, guest PC 0x0c044d0e */
if(!s->budget--) { s->failed_pc=0x0c044d0eu; return 0; }
r[0]=0xffffffffu;
return vf3_matrix_family(0x0c044d10u,s,ram);
P_0c044d50: /* original 60f0, guest PC 0x0c044d50 */
if(!s->budget--) { s->failed_pc=0x0c044d50u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[0]=tmp;
goto P_0c044d52;
P_0c044d52: /* original 62f3, guest PC 0x0c044d52 */
if(!s->budget--) { s->failed_pc=0x0c044d52u; return 0; }
r[2]=r[15];
goto P_0c044d54;
P_0c044d54: /* original 7210, guest PC 0x0c044d54 */
if(!s->budget--) { s->failed_pc=0x0c044d54u; return 0; }
r[2]+=0x00000010u;
goto P_0c044d56;
P_0c044d56: /* original 68b3, guest PC 0x0c044d56 */
if(!s->budget--) { s->failed_pc=0x0c044d56u; return 0; }
r[8]=r[11];
goto P_0c044d58;
P_0c044d58: /* original 8036, guest PC 0x0c044d58 */
if(!s->budget--) { s->failed_pc=0x0c044d58u; return 0; }
write(ram,r[3]+6,r[0],1);
goto P_0c044d5a;
P_0c044d5a: /* original 38cc, guest PC 0x0c044d5a */
if(!s->budget--) { s->failed_pc=0x0c044d5au; return 0; }
r[8]+=r[12];
goto P_0c044d5c;
P_0c044d5c: /* original 6483, guest PC 0x0c044d5c */
if(!s->budget--) { s->failed_pc=0x0c044d5cu; return 0; }
r[4]=r[8];
goto P_0c044d5e;
P_0c044d5e: /* original 7403, guest PC 0x0c044d5e */
if(!s->budget--) { s->failed_pc=0x0c044d5eu; return 0; }
r[4]+=0x00000003u;
goto P_0c044d60;
P_0c044d60: /* original 1f42, guest PC 0x0c044d60 */
if(!s->budget--) { s->failed_pc=0x0c044d60u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c044d62;
P_0c044d62: /* original e403, guest PC 0x0c044d62 */
if(!s->budget--) { s->failed_pc=0x0c044d62u; return 0; }
r[4]=0x00000003u;
goto P_0c044d64;
P_0c044d64: /* original d03c, guest PC 0x0c044d64 */
if(!s->budget--) { s->failed_pc=0x0c044d64u; return 0; }
r[0]=read(ram,0x0c044e58u,4);
goto P_0c044d66;
P_0c044d66: /* original 039c, guest PC 0x0c044d66 */
if(!s->budget--) { s->failed_pc=0x0c044d66u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+r[0],1);
goto P_0c044d68;
P_0c044d68: /* original 2230, guest PC 0x0c044d68 */
if(!s->budget--) { s->failed_pc=0x0c044d68u; return 0; }
write(ram,r[2],r[3],1);
goto P_0c044d6a;
P_0c044d6a: /* original e2fa, guest PC 0x0c044d6a */
if(!s->budget--) { s->failed_pc=0x0c044d6au; return 0; }
r[2]=0xfffffffau;
goto P_0c044d6c;
P_0c044d6c: /* original 956d, guest PC 0x0c044d6c */
if(!s->budget--) { s->failed_pc=0x0c044d6cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044e4au,2);
goto P_0c044d6e;
P_0c044d6e: /* original 2539, guest PC 0x0c044d6e */
if(!s->budget--) { s->failed_pc=0x0c044d6eu; return 0; }
r[5]&=r[3];
goto P_0c044d70;
P_0c044d70: /* original 655c, guest PC 0x0c044d70 */
if(!s->budget--) { s->failed_pc=0x0c044d70u; return 0; }
r[5]=r[5]&255u;
goto P_0c044d72;
P_0c044d72: /* original 1f53, guest PC 0x0c044d72 */
if(!s->budget--) { s->failed_pc=0x0c044d72u; return 0; }
write(ram,r[15]+12,r[5],4);
goto P_0c044d74;
P_0c044d74: /* original 452c, guest PC 0x0c044d74 */
if(!s->budget--) { s->failed_pc=0x0c044d74u; return 0; }
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[5]>>((-r[2])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[2]&31u);
goto P_0c044d76;
P_0c044d76: /* original 2549, guest PC 0x0c044d76 */
if(!s->budget--) { s->failed_pc=0x0c044d76u; return 0; }
r[5]&=r[4];
goto P_0c044d78;
P_0c044d78: /* original 2f52, guest PC 0x0c044d78 */
if(!s->budget--) { s->failed_pc=0x0c044d78u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c044d7a;
P_0c044d7a: /* original 6de2, guest PC 0x0c044d7a */
if(!s->budget--) { s->failed_pc=0x0c044d7au; return 0; }
tmp=read(ram,r[14],4);
r[13]=tmp;
goto P_0c044d7c;
P_0c044d7c: /* original 9066, guest PC 0x0c044d7c */
if(!s->budget--) { s->failed_pc=0x0c044d7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044e4cu,2);
goto P_0c044d7e;
P_0c044d7e: /* original 62d3, guest PC 0x0c044d7e */
if(!s->budget--) { s->failed_pc=0x0c044d7eu; return 0; }
r[2]=r[13];
goto P_0c044d80;
P_0c044d80: /* original 032e, guest PC 0x0c044d80 */
if(!s->budget--) { s->failed_pc=0x0c044d80u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c044d82;
P_0c044d82: /* original 4315, guest PC 0x0c044d82 */
if(!s->budget--) { s->failed_pc=0x0c044d82u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c044d84;
P_0c044d84: /* original 8b0f, guest PC 0x0c044d84 */
if(!s->budget--) { s->failed_pc=0x0c044d84u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c044da6; }
goto P_0c044d86;
P_0c044d86: /* original 9062, guest PC 0x0c044d86 */
if(!s->budget--) { s->failed_pc=0x0c044d86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044e4eu,2);
goto P_0c044d88;
P_0c044d88: /* original 01de, guest PC 0x0c044d88 */
if(!s->budget--) { s->failed_pc=0x0c044d88u; return 0; }
r[1]=read(ram,r[13]+r[0],4);
goto P_0c044d8a;
P_0c044d8a: /* original 4115, guest PC 0x0c044d8a */
if(!s->budget--) { s->failed_pc=0x0c044d8au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c044d8c;
P_0c044d8c: /* original 8b0b, guest PC 0x0c044d8c */
if(!s->budget--) { s->failed_pc=0x0c044d8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c044da6; }
goto P_0c044d8e;
P_0c044d8e: /* original 905f, guest PC 0x0c044d8e */
if(!s->budget--) { s->failed_pc=0x0c044d8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044e50u,2);
goto P_0c044d90;
P_0c044d90: /* original 02de, guest PC 0x0c044d90 */
if(!s->budget--) { s->failed_pc=0x0c044d90u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c044d92;
P_0c044d92: /* original 6322, guest PC 0x0c044d92 */
if(!s->budget--) { s->failed_pc=0x0c044d92u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c044d94;
P_0c044d94: /* original 62f2, guest PC 0x0c044d94 */
if(!s->budget--) { s->failed_pc=0x0c044d94u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c044d96;
P_0c044d96: /* original 4329, guest PC 0x0c044d96 */
if(!s->budget--) { s->failed_pc=0x0c044d96u; return 0; }
r[3]>>=16;
goto P_0c044d98;
P_0c044d98: /* original 633f, guest PC 0x0c044d98 */
if(!s->budget--) { s->failed_pc=0x0c044d98u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c044d9a;
P_0c044d9a: /* original 2439, guest PC 0x0c044d9a */
if(!s->budget--) { s->failed_pc=0x0c044d9au; return 0; }
r[4]&=r[3];
goto P_0c044d9c;
P_0c044d9c: /* original 3240, guest PC 0x0c044d9c */
if(!s->budget--) { s->failed_pc=0x0c044d9cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[4])!=0);
goto P_0c044d9e;
P_0c044d9e: /* original 8b02, guest PC 0x0c044d9e */
if(!s->budget--) { s->failed_pc=0x0c044d9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c044da6; }
goto P_0c044da0;
P_0c044da0: /* original 9054, guest PC 0x0c044da0 */
if(!s->budget--) { s->failed_pc=0x0c044da0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044e4cu,2);
goto P_0c044da2;
P_0c044da2: /* original bf6b, guest PC 0x0c044da2 */
if(!s->budget--) { s->failed_pc=0x0c044da2u; return 0; }
target=0x0c044c7cu; r[16]=0x0c044da6u;
r[4]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c044da6u) { target=s->pc; goto dispatch; }
goto P_0c044da6;
P_0c044da4: /* original 04de, guest PC 0x0c044da4 */
if(!s->budget--) { s->failed_pc=0x0c044da4u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c044da6;
P_0c044da6: /* original 9053, guest PC 0x0c044da6 */
if(!s->budget--) { s->failed_pc=0x0c044da6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044e50u,2);
goto P_0c044da8;
P_0c044da8: /* original 62e2, guest PC 0x0c044da8 */
if(!s->budget--) { s->failed_pc=0x0c044da8u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c044daa;
P_0c044daa: /* original 6103, guest PC 0x0c044daa */
if(!s->budget--) { s->failed_pc=0x0c044daau; return 0; }
r[1]=r[0];
goto P_0c044dac;
P_0c044dac: /* original 710c, guest PC 0x0c044dac */
if(!s->budget--) { s->failed_pc=0x0c044dacu; return 0; }
r[1]+=0x0000000cu;
goto P_0c044dae;
P_0c044dae: /* original 6323, guest PC 0x0c044dae */
if(!s->budget--) { s->failed_pc=0x0c044daeu; return 0; }
r[3]=r[2];
goto P_0c044db0;
P_0c044db0: /* original 313c, guest PC 0x0c044db0 */
if(!s->budget--) { s->failed_pc=0x0c044db0u; return 0; }
r[1]+=r[3];
goto P_0c044db2;
P_0c044db2: /* original 6112, guest PC 0x0c044db2 */
if(!s->budget--) { s->failed_pc=0x0c044db2u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c044db4;
P_0c044db4: /* original 032e, guest PC 0x0c044db4 */
if(!s->budget--) { s->failed_pc=0x0c044db4u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c044db6;
P_0c044db6: /* original 4108, guest PC 0x0c044db6 */
if(!s->budget--) { s->failed_pc=0x0c044db6u; return 0; }
r[1]<<=2;
goto P_0c044db8;
P_0c044db8: /* original 331c, guest PC 0x0c044db8 */
if(!s->budget--) { s->failed_pc=0x0c044db8u; return 0; }
r[3]+=r[1];
goto P_0c044dba;
P_0c044dba: /* original 0236, guest PC 0x0c044dba */
if(!s->budget--) { s->failed_pc=0x0c044dbau; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c044dbc;
P_0c044dbc: /* original 618c, guest PC 0x0c044dbc */
if(!s->budget--) { s->failed_pc=0x0c044dbcu; return 0; }
r[1]=r[8]&255u;
goto P_0c044dbe;
P_0c044dbe: /* original 62f2, guest PC 0x0c044dbe */
if(!s->budget--) { s->failed_pc=0x0c044dbeu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c044dc0;
P_0c044dc0: /* original 6de2, guest PC 0x0c044dc0 */
if(!s->budget--) { s->failed_pc=0x0c044dc0u; return 0; }
tmp=read(ram,r[14],4);
r[13]=tmp;
goto P_0c044dc2;
P_0c044dc2: /* original 4228, guest PC 0x0c044dc2 */
if(!s->budget--) { s->failed_pc=0x0c044dc2u; return 0; }
r[2]<<=16;
goto P_0c044dc4;
P_0c044dc4: /* original 0dde, guest PC 0x0c044dc4 */
if(!s->budget--) { s->failed_pc=0x0c044dc4u; return 0; }
r[13]=read(ram,r[13]+r[0],4);
goto P_0c044dc6;
P_0c044dc6: /* original 221b, guest PC 0x0c044dc6 */
if(!s->budget--) { s->failed_pc=0x0c044dc6u; return 0; }
r[2]|=r[1];
goto P_0c044dc8;
P_0c044dc8: /* original 1f15, guest PC 0x0c044dc8 */
if(!s->budget--) { s->failed_pc=0x0c044dc8u; return 0; }
write(ram,r[15]+20,r[1],4);
goto P_0c044dca;
P_0c044dca: /* original 2d22, guest PC 0x0c044dca */
if(!s->budget--) { s->failed_pc=0x0c044dcau; return 0; }
write(ram,r[13],r[2],4);
goto P_0c044dcc;
P_0c044dcc: /* original 7d04, guest PC 0x0c044dcc */
if(!s->budget--) { s->failed_pc=0x0c044dccu; return 0; }
r[13]+=0x00000004u;
goto P_0c044dce;
P_0c044dce: /* original 2fd6, guest PC 0x0c044dce */
if(!s->budget--) { s->failed_pc=0x0c044dceu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c044dd0;
P_0c044dd0: /* original 7d04, guest PC 0x0c044dd0 */
if(!s->budget--) { s->failed_pc=0x0c044dd0u; return 0; }
r[13]+=0x00000004u;
goto P_0c044dd2;
P_0c044dd2: /* original 60e2, guest PC 0x0c044dd2 */
if(!s->budget--) { s->failed_pc=0x0c044dd2u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c044dd4;
P_0c044dd4: /* original 913d, guest PC 0x0c044dd4 */
if(!s->budget--) { s->failed_pc=0x0c044dd4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044e52u,2);
goto P_0c044dd6;
P_0c044dd6: /* original 6303, guest PC 0x0c044dd6 */
if(!s->budget--) { s->failed_pc=0x0c044dd6u; return 0; }
r[3]=r[0];
goto P_0c044dd8;
P_0c044dd8: /* original 313c, guest PC 0x0c044dd8 */
if(!s->budget--) { s->failed_pc=0x0c044dd8u; return 0; }
r[1]+=r[3];
goto P_0c044dda;
P_0c044dda: /* original 6310, guest PC 0x0c044dda */
if(!s->budget--) { s->failed_pc=0x0c044ddau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[3]=tmp;
goto P_0c044ddc;
P_0c044ddc: /* original 6233, guest PC 0x0c044ddc */
if(!s->budget--) { s->failed_pc=0x0c044ddcu; return 0; }
r[2]=r[3];
goto P_0c044dde;
P_0c044dde: /* original 4300, guest PC 0x0c044dde */
if(!s->budget--) { s->failed_pc=0x0c044ddeu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c044de0;
P_0c044de0: /* original 332c, guest PC 0x0c044de0 */
if(!s->budget--) { s->failed_pc=0x0c044de0u; return 0; }
r[3]+=r[2];
goto P_0c044de2;
P_0c044de2: /* original 4308, guest PC 0x0c044de2 */
if(!s->budget--) { s->failed_pc=0x0c044de2u; return 0; }
r[3]<<=2;
goto P_0c044de4;
P_0c044de4: /* original 4308, guest PC 0x0c044de4 */
if(!s->budget--) { s->failed_pc=0x0c044de4u; return 0; }
r[3]<<=2;
goto P_0c044de6;
P_0c044de6: /* original 9235, guest PC 0x0c044de6 */
if(!s->budget--) { s->failed_pc=0x0c044de6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044e54u,2);
goto P_0c044de8;
P_0c044de8: /* original 4300, guest PC 0x0c044de8 */
if(!s->budget--) { s->failed_pc=0x0c044de8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c044dea;
P_0c044dea: /* original 633c, guest PC 0x0c044dea */
if(!s->budget--) { s->failed_pc=0x0c044deau; return 0; }
r[3]=r[3]&255u;
goto P_0c044dec;
P_0c044dec: /* original 6493, guest PC 0x0c044dec */
if(!s->budget--) { s->failed_pc=0x0c044decu; return 0; }
r[4]=r[9];
goto P_0c044dee;
P_0c044dee: /* original 302c, guest PC 0x0c044dee */
if(!s->budget--) { s->failed_pc=0x0c044deeu; return 0; }
r[0]+=r[2];
goto P_0c044df0;
P_0c044df0: /* original 303c, guest PC 0x0c044df0 */
if(!s->budget--) { s->failed_pc=0x0c044df0u; return 0; }
r[0]+=r[3];
goto P_0c044df2;
P_0c044df2: /* original d31a, guest PC 0x0c044df2 */
if(!s->budget--) { s->failed_pc=0x0c044df2u; return 0; }
r[3]=read(ram,0x0c044e5cu,4);
goto P_0c044df4;
P_0c044df4: /* original 4408, guest PC 0x0c044df4 */
if(!s->budget--) { s->failed_pc=0x0c044df4u; return 0; }
r[4]<<=2;
goto P_0c044df6;
P_0c044df6: /* original 430b, guest PC 0x0c044df6 */
if(!s->budget--) { s->failed_pc=0x0c044df6u; return 0; }
target=r[3];
r[16]=0x0c044dfau;
r[4]=read(ram,r[4]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c044dfau) { target=s->pc; goto dispatch; }
goto P_0c044dfa;
P_0c044df8: /* original 044e, guest PC 0x0c044df8 */
if(!s->budget--) { s->failed_pc=0x0c044df8u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c044dfa;
P_0c044dfa: /* original 62f6, guest PC 0x0c044dfa */
if(!s->budget--) { s->failed_pc=0x0c044dfau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c044dfc;
P_0c044dfc: /* original 2202, guest PC 0x0c044dfc */
if(!s->budget--) { s->failed_pc=0x0c044dfcu; return 0; }
write(ram,r[2],r[0],4);
goto P_0c044dfe;
P_0c044dfe: /* original e010, guest PC 0x0c044dfe */
if(!s->budget--) { s->failed_pc=0x0c044dfeu; return 0; }
r[0]=0x00000010u;
goto P_0c044e00;
P_0c044e00: /* original 09fc, guest PC 0x0c044e00 */
if(!s->budget--) { s->failed_pc=0x0c044e00u; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c044e02;
P_0c044e02: /* original 60e2, guest PC 0x0c044e02 */
if(!s->budget--) { s->failed_pc=0x0c044e02u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c044e04;
P_0c044e04: /* original 9127, guest PC 0x0c044e04 */
if(!s->budget--) { s->failed_pc=0x0c044e04u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044e56u,2);
goto P_0c044e06;
P_0c044e06: /* original d616, guest PC 0x0c044e06 */
if(!s->budget--) { s->failed_pc=0x0c044e06u; return 0; }
r[6]=read(ram,0x0c044e60u,4);
goto P_0c044e08;
P_0c044e08: /* original 001e, guest PC 0x0c044e08 */
if(!s->budget--) { s->failed_pc=0x0c044e08u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c044e0a;
P_0c044e0a: /* original 57f6, guest PC 0x0c044e0a */
if(!s->budget--) { s->failed_pc=0x0c044e0au; return 0; }
r[7]=read(ram,r[15]+24,4);
goto P_0c044e0c;
P_0c044e0c: /* original d416, guest PC 0x0c044e0c */
if(!s->budget--) { s->failed_pc=0x0c044e0cu; return 0; }
r[4]=read(ram,0x0c044e68u,4);
goto P_0c044e0e;
P_0c044e0e: /* original 8801, guest PC 0x0c044e0e */
if(!s->budget--) { s->failed_pc=0x0c044e0eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c044e10;
P_0c044e10: /* original d514, guest PC 0x0c044e10 */
if(!s->budget--) { s->failed_pc=0x0c044e10u; return 0; }
r[5]=read(ram,0x0c044e64u,4);
goto P_0c044e12;
P_0c044e12: /* original 8f2b, guest PC 0x0c044e12 */
if(!s->budget--) { s->failed_pc=0x0c044e12u; return 0; }
cond=r[17]&1u;
r[9]=r[9]&255u;
if(!cond) { goto P_0c044e6c; }
goto P_0c044e16;
P_0c044e14: /* original 699c, guest PC 0x0c044e14 */
if(!s->budget--) { s->failed_pc=0x0c044e14u; return 0; }
r[9]=r[9]&255u;
goto P_0c044e16;
P_0c044e16: /* original 53f1, guest PC 0x0c044e16 */
if(!s->budget--) { s->failed_pc=0x0c044e16u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c044e18;
P_0c044e18: /* original 4928, guest PC 0x0c044e18 */
if(!s->budget--) { s->failed_pc=0x0c044e18u; return 0; }
r[9]<<=16;
goto P_0c044e1a;
P_0c044e1a: /* original 50f3, guest PC 0x0c044e1a */
if(!s->budget--) { s->failed_pc=0x0c044e1au; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c044e1c;
P_0c044e1c: /* original 2949, guest PC 0x0c044e1c */
if(!s->budget--) { s->failed_pc=0x0c044e1cu; return 0; }
r[9]&=r[4];
goto P_0c044e1e;
P_0c044e1e: /* original 4328, guest PC 0x0c044e1e */
if(!s->budget--) { s->failed_pc=0x0c044e1eu; return 0; }
r[3]<<=16;
goto P_0c044e20;
P_0c044e20: /* original 4b15, guest PC 0x0c044e20 */
if(!s->budget--) { s->failed_pc=0x0c044e20u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>0)!=0);
goto P_0c044e22;
P_0c044e22: /* original 4318, guest PC 0x0c044e22 */
if(!s->budget--) { s->failed_pc=0x0c044e22u; return 0; }
r[3]<<=8;
goto P_0c044e24;
P_0c044e24: /* original 4018, guest PC 0x0c044e24 */
if(!s->budget--) { s->failed_pc=0x0c044e24u; return 0; }
r[0]<<=8;
goto P_0c044e26;
P_0c044e26: /* original 2369, guest PC 0x0c044e26 */
if(!s->budget--) { s->failed_pc=0x0c044e26u; return 0; }
r[3]&=r[6];
goto P_0c044e28;
P_0c044e28: /* original 2059, guest PC 0x0c044e28 */
if(!s->budget--) { s->failed_pc=0x0c044e28u; return 0; }
r[0]&=r[5];
goto P_0c044e2a;
P_0c044e2a: /* original 239b, guest PC 0x0c044e2a */
if(!s->budget--) { s->failed_pc=0x0c044e2au; return 0; }
r[3]|=r[9];
goto P_0c044e2c;
P_0c044e2c: /* original 230b, guest PC 0x0c044e2c */
if(!s->budget--) { s->failed_pc=0x0c044e2cu; return 0; }
r[3]|=r[0];
goto P_0c044e2e;
P_0c044e2e: /* original 50f5, guest PC 0x0c044e2e */
if(!s->budget--) { s->failed_pc=0x0c044e2eu; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c044e30;
P_0c044e30: /* original 230b, guest PC 0x0c044e30 */
if(!s->budget--) { s->failed_pc=0x0c044e30u; return 0; }
r[3]|=r[0];
goto P_0c044e32;
P_0c044e32: /* original 2d32, guest PC 0x0c044e32 */
if(!s->budget--) { s->failed_pc=0x0c044e32u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c044e34;
P_0c044e34: /* original 7d04, guest PC 0x0c044e34 */
if(!s->budget--) { s->failed_pc=0x0c044e34u; return 0; }
r[13]+=0x00000004u;
goto P_0c044e36;
P_0c044e36: /* original 8f43, guest PC 0x0c044e36 */
if(!s->budget--) { s->failed_pc=0x0c044e36u; return 0; }
cond=r[17]&1u;
r[9]=0x00000000u;
if(!cond) { goto P_0c044ec0; }
goto P_0c044e3a;
P_0c044e38: /* original e900, guest PC 0x0c044e38 */
if(!s->budget--) { s->failed_pc=0x0c044e38u; return 0; }
r[9]=0x00000000u;
goto P_0c044e3a;
P_0c044e3a: /* original 6376, guest PC 0x0c044e3a */
if(!s->budget--) { s->failed_pc=0x0c044e3au; return 0; }
tmp=read(ram,r[7],4);
r[7]+=4;
r[3]=tmp;
goto P_0c044e3c;
P_0c044e3c: /* original 7901, guest PC 0x0c044e3c */
if(!s->budget--) { s->failed_pc=0x0c044e3cu; return 0; }
r[9]+=0x00000001u;
goto P_0c044e3e;
P_0c044e3e: /* original 39b3, guest PC 0x0c044e3e */
if(!s->budget--) { s->failed_pc=0x0c044e3eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[11])!=0);
goto P_0c044e40;
P_0c044e40: /* original 2d32, guest PC 0x0c044e40 */
if(!s->budget--) { s->failed_pc=0x0c044e40u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c044e42;
P_0c044e42: /* original 8ffa, guest PC 0x0c044e42 */
if(!s->budget--) { s->failed_pc=0x0c044e42u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000004u;
if(!cond) { goto P_0c044e3a; }
goto P_0c044e46;
P_0c044e44: /* original 7d04, guest PC 0x0c044e44 */
if(!s->budget--) { s->failed_pc=0x0c044e44u; return 0; }
r[13]+=0x00000004u;
goto P_0c044e46;
P_0c044e46: /* original a03b, guest PC 0x0c044e46 */
if(!s->budget--) { s->failed_pc=0x0c044e46u; return 0; }
goto P_0c044ec0;
P_0c044e48: /* original 0009, guest PC 0x0c044e48 */
if(!s->budget--) { s->failed_pc=0x0c044e48u; return 0; }
return vf3_matrix_family(0x0c044e4au,s,ram);
P_0c044e6c: /* original 53f3, guest PC 0x0c044e6c */
if(!s->budget--) { s->failed_pc=0x0c044e6cu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c044e6e;
P_0c044e6e: /* original 4918, guest PC 0x0c044e6e */
if(!s->budget--) { s->failed_pc=0x0c044e6eu; return 0; }
r[9]<<=8;
goto P_0c044e70;
P_0c044e70: /* original 4828, guest PC 0x0c044e70 */
if(!s->budget--) { s->failed_pc=0x0c044e70u; return 0; }
r[8]<<=16;
goto P_0c044e72;
P_0c044e72: /* original 50f1, guest PC 0x0c044e72 */
if(!s->budget--) { s->failed_pc=0x0c044e72u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c044e74;
P_0c044e74: /* original 4328, guest PC 0x0c044e74 */
if(!s->budget--) { s->failed_pc=0x0c044e74u; return 0; }
r[3]<<=16;
goto P_0c044e76;
P_0c044e76: /* original 4b15, guest PC 0x0c044e76 */
if(!s->budget--) { s->failed_pc=0x0c044e76u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>0)!=0);
goto P_0c044e78;
P_0c044e78: /* original 4818, guest PC 0x0c044e78 */
if(!s->budget--) { s->failed_pc=0x0c044e78u; return 0; }
r[8]<<=8;
goto P_0c044e7a;
P_0c044e7a: /* original 2349, guest PC 0x0c044e7a */
if(!s->budget--) { s->failed_pc=0x0c044e7au; return 0; }
r[3]&=r[4];
goto P_0c044e7c;
P_0c044e7c: /* original 2959, guest PC 0x0c044e7c */
if(!s->budget--) { s->failed_pc=0x0c044e7cu; return 0; }
r[9]&=r[5];
goto P_0c044e7e;
P_0c044e7e: /* original 2869, guest PC 0x0c044e7e */
if(!s->budget--) { s->failed_pc=0x0c044e7eu; return 0; }
r[8]&=r[6];
goto P_0c044e80;
P_0c044e80: /* original 239b, guest PC 0x0c044e80 */
if(!s->budget--) { s->failed_pc=0x0c044e80u; return 0; }
r[3]|=r[9];
goto P_0c044e82;
P_0c044e82: /* original 238b, guest PC 0x0c044e82 */
if(!s->budget--) { s->failed_pc=0x0c044e82u; return 0; }
r[3]|=r[8];
goto P_0c044e84;
P_0c044e84: /* original 230b, guest PC 0x0c044e84 */
if(!s->budget--) { s->failed_pc=0x0c044e84u; return 0; }
r[3]|=r[0];
goto P_0c044e86;
P_0c044e86: /* original 2d32, guest PC 0x0c044e86 */
if(!s->budget--) { s->failed_pc=0x0c044e86u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c044e88;
P_0c044e88: /* original 7d04, guest PC 0x0c044e88 */
if(!s->budget--) { s->failed_pc=0x0c044e88u; return 0; }
r[13]+=0x00000004u;
goto P_0c044e8a;
P_0c044e8a: /* original 8f19, guest PC 0x0c044e8a */
if(!s->budget--) { s->failed_pc=0x0c044e8au; return 0; }
cond=r[17]&1u;
r[8]=0x00000000u;
if(!cond) { goto P_0c044ec0; }
goto P_0c044e8e;
P_0c044e8c: /* original e800, guest PC 0x0c044e8c */
if(!s->budget--) { s->failed_pc=0x0c044e8cu; return 0; }
r[8]=0x00000000u;
goto P_0c044e8e;
P_0c044e8e: /* original 6976, guest PC 0x0c044e8e */
if(!s->budget--) { s->failed_pc=0x0c044e8eu; return 0; }
tmp=read(ram,r[7],4);
r[7]+=4;
r[9]=tmp;
goto P_0c044e90;
P_0c044e90: /* original 7801, guest PC 0x0c044e90 */
if(!s->budget--) { s->failed_pc=0x0c044e90u; return 0; }
r[8]+=0x00000001u;
goto P_0c044e92;
P_0c044e92: /* original 38b3, guest PC 0x0c044e92 */
if(!s->budget--) { s->failed_pc=0x0c044e92u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[11])!=0);
goto P_0c044e94;
P_0c044e94: /* original 6293, guest PC 0x0c044e94 */
if(!s->budget--) { s->failed_pc=0x0c044e94u; return 0; }
r[2]=r[9];
goto P_0c044e96;
P_0c044e96: /* original 6393, guest PC 0x0c044e96 */
if(!s->budget--) { s->failed_pc=0x0c044e96u; return 0; }
r[3]=r[9];
goto P_0c044e98;
P_0c044e98: /* original 4228, guest PC 0x0c044e98 */
if(!s->budget--) { s->failed_pc=0x0c044e98u; return 0; }
r[2]<<=16;
goto P_0c044e9a;
P_0c044e9a: /* original 6193, guest PC 0x0c044e9a */
if(!s->budget--) { s->failed_pc=0x0c044e9au; return 0; }
r[1]=r[9];
goto P_0c044e9c;
P_0c044e9c: /* original 4318, guest PC 0x0c044e9c */
if(!s->budget--) { s->failed_pc=0x0c044e9cu; return 0; }
r[3]<<=8;
goto P_0c044e9e;
P_0c044e9e: /* original 4218, guest PC 0x0c044e9e */
if(!s->budget--) { s->failed_pc=0x0c044e9eu; return 0; }
r[2]<<=8;
goto P_0c044ea0;
P_0c044ea0: /* original 2349, guest PC 0x0c044ea0 */
if(!s->budget--) { s->failed_pc=0x0c044ea0u; return 0; }
r[3]&=r[4];
goto P_0c044ea2;
P_0c044ea2: /* original 2269, guest PC 0x0c044ea2 */
if(!s->budget--) { s->failed_pc=0x0c044ea2u; return 0; }
r[2]&=r[6];
goto P_0c044ea4;
P_0c044ea4: /* original 223b, guest PC 0x0c044ea4 */
if(!s->budget--) { s->failed_pc=0x0c044ea4u; return 0; }
r[2]|=r[3];
goto P_0c044ea6;
P_0c044ea6: /* original e3f8, guest PC 0x0c044ea6 */
if(!s->budget--) { s->failed_pc=0x0c044ea6u; return 0; }
r[3]=0xfffffff8u;
goto P_0c044ea8;
P_0c044ea8: /* original 413c, guest PC 0x0c044ea8 */
if(!s->budget--) { s->failed_pc=0x0c044ea8u; return 0; }
r[1]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[1]>>((-r[3])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[3]&31u);
goto P_0c044eaa;
P_0c044eaa: /* original 2159, guest PC 0x0c044eaa */
if(!s->budget--) { s->failed_pc=0x0c044eaau; return 0; }
r[1]&=r[5];
goto P_0c044eac;
P_0c044eac: /* original 221b, guest PC 0x0c044eac */
if(!s->budget--) { s->failed_pc=0x0c044eacu; return 0; }
r[2]|=r[1];
goto P_0c044eae;
P_0c044eae: /* original 6193, guest PC 0x0c044eae */
if(!s->budget--) { s->failed_pc=0x0c044eaeu; return 0; }
r[1]=r[9];
goto P_0c044eb0;
P_0c044eb0: /* original 4129, guest PC 0x0c044eb0 */
if(!s->budget--) { s->failed_pc=0x0c044eb0u; return 0; }
r[1]>>=16;
goto P_0c044eb2;
P_0c044eb2: /* original 4119, guest PC 0x0c044eb2 */
if(!s->budget--) { s->failed_pc=0x0c044eb2u; return 0; }
r[1]>>=8;
goto P_0c044eb4;
P_0c044eb4: /* original 611e, guest PC 0x0c044eb4 */
if(!s->budget--) { s->failed_pc=0x0c044eb4u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)r[1];
goto P_0c044eb6;
P_0c044eb6: /* original 611c, guest PC 0x0c044eb6 */
if(!s->budget--) { s->failed_pc=0x0c044eb6u; return 0; }
r[1]=r[1]&255u;
goto P_0c044eb8;
P_0c044eb8: /* original 221b, guest PC 0x0c044eb8 */
if(!s->budget--) { s->failed_pc=0x0c044eb8u; return 0; }
r[2]|=r[1];
goto P_0c044eba;
P_0c044eba: /* original 2d22, guest PC 0x0c044eba */
if(!s->budget--) { s->failed_pc=0x0c044ebau; return 0; }
write(ram,r[13],r[2],4);
goto P_0c044ebc;
P_0c044ebc: /* original 8fe7, guest PC 0x0c044ebc */
if(!s->budget--) { s->failed_pc=0x0c044ebcu; return 0; }
cond=r[17]&1u;
r[13]+=0x00000004u;
if(!cond) { goto P_0c044e8e; }
goto P_0c044ec0;
P_0c044ebe: /* original 7d04, guest PC 0x0c044ebe */
if(!s->budget--) { s->failed_pc=0x0c044ebeu; return 0; }
r[13]+=0x00000004u;
goto P_0c044ec0;
P_0c044ec0: /* original 9179, guest PC 0x0c044ec0 */
if(!s->budget--) { s->failed_pc=0x0c044ec0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044fb6u,2);
goto P_0c044ec2;
P_0c044ec2: /* original 60e2, guest PC 0x0c044ec2 */
if(!s->budget--) { s->failed_pc=0x0c044ec2u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c044ec4;
P_0c044ec4: /* original 001e, guest PC 0x0c044ec4 */
if(!s->budget--) { s->failed_pc=0x0c044ec4u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c044ec6;
P_0c044ec6: /* original 8801, guest PC 0x0c044ec6 */
if(!s->budget--) { s->failed_pc=0x0c044ec6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c044ec8;
P_0c044ec8: /* original 8b1c, guest PC 0x0c044ec8 */
if(!s->budget--) { s->failed_pc=0x0c044ec8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c044f04; }
goto P_0c044eca;
P_0c044eca: /* original e040, guest PC 0x0c044eca */
if(!s->budget--) { s->failed_pc=0x0c044ecau; return 0; }
r[0]=0x00000040u;
goto P_0c044ecc;
P_0c044ecc: /* original 4c15, guest PC 0x0c044ecc */
if(!s->budget--) { s->failed_pc=0x0c044eccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c044ece;
P_0c044ece: /* original 07fe, guest PC 0x0c044ece */
if(!s->budget--) { s->failed_pc=0x0c044eceu; return 0; }
r[7]=read(ram,r[15]+r[0],4);
goto P_0c044ed0;
P_0c044ed0: /* original 8f23, guest PC 0x0c044ed0 */
if(!s->budget--) { s->failed_pc=0x0c044ed0u; return 0; }
cond=r[17]&1u;
r[11]=0x00000000u;
if(!cond) { goto P_0c044f1a; }
goto P_0c044ed4;
P_0c044ed2: /* original eb00, guest PC 0x0c044ed2 */
if(!s->budget--) { s->failed_pc=0x0c044ed2u; return 0; }
r[11]=0x00000000u;
goto P_0c044ed4;
P_0c044ed4: /* original 8471, guest PC 0x0c044ed4 */
if(!s->budget--) { s->failed_pc=0x0c044ed4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+1,1);
goto P_0c044ed6;
P_0c044ed6: /* original 7b01, guest PC 0x0c044ed6 */
if(!s->budget--) { s->failed_pc=0x0c044ed6u; return 0; }
r[11]+=0x00000001u;
goto P_0c044ed8;
P_0c044ed8: /* original 6170, guest PC 0x0c044ed8 */
if(!s->budget--) { s->failed_pc=0x0c044ed8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[1]=tmp;
goto P_0c044eda;
P_0c044eda: /* original 3bc3, guest PC 0x0c044eda */
if(!s->budget--) { s->failed_pc=0x0c044edau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[12])!=0);
goto P_0c044edc;
P_0c044edc: /* original 4028, guest PC 0x0c044edc */
if(!s->budget--) { s->failed_pc=0x0c044edcu; return 0; }
r[0]<<=16;
goto P_0c044ede;
P_0c044ede: /* original 2049, guest PC 0x0c044ede */
if(!s->budget--) { s->failed_pc=0x0c044edeu; return 0; }
r[0]&=r[4];
goto P_0c044ee0;
P_0c044ee0: /* original 6303, guest PC 0x0c044ee0 */
if(!s->budget--) { s->failed_pc=0x0c044ee0u; return 0; }
r[3]=r[0];
goto P_0c044ee2;
P_0c044ee2: /* original 8472, guest PC 0x0c044ee2 */
if(!s->budget--) { s->failed_pc=0x0c044ee2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+2,1);
goto P_0c044ee4;
P_0c044ee4: /* original 4128, guest PC 0x0c044ee4 */
if(!s->budget--) { s->failed_pc=0x0c044ee4u; return 0; }
r[1]<<=16;
goto P_0c044ee6;
P_0c044ee6: /* original 4018, guest PC 0x0c044ee6 */
if(!s->budget--) { s->failed_pc=0x0c044ee6u; return 0; }
r[0]<<=8;
goto P_0c044ee8;
P_0c044ee8: /* original 2059, guest PC 0x0c044ee8 */
if(!s->budget--) { s->failed_pc=0x0c044ee8u; return 0; }
r[0]&=r[5];
goto P_0c044eea;
P_0c044eea: /* original 230b, guest PC 0x0c044eea */
if(!s->budget--) { s->failed_pc=0x0c044eeau; return 0; }
r[3]|=r[0];
goto P_0c044eec;
P_0c044eec: /* original 8473, guest PC 0x0c044eec */
if(!s->budget--) { s->failed_pc=0x0c044eecu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+3,1);
goto P_0c044eee;
P_0c044eee: /* original 4118, guest PC 0x0c044eee */
if(!s->budget--) { s->failed_pc=0x0c044eeeu; return 0; }
r[1]<<=8;
goto P_0c044ef0;
P_0c044ef0: /* original 2169, guest PC 0x0c044ef0 */
if(!s->budget--) { s->failed_pc=0x0c044ef0u; return 0; }
r[1]&=r[6];
goto P_0c044ef2;
P_0c044ef2: /* original 600c, guest PC 0x0c044ef2 */
if(!s->budget--) { s->failed_pc=0x0c044ef2u; return 0; }
r[0]=r[0]&255u;
goto P_0c044ef4;
P_0c044ef4: /* original 231b, guest PC 0x0c044ef4 */
if(!s->budget--) { s->failed_pc=0x0c044ef4u; return 0; }
r[3]|=r[1];
goto P_0c044ef6;
P_0c044ef6: /* original 230b, guest PC 0x0c044ef6 */
if(!s->budget--) { s->failed_pc=0x0c044ef6u; return 0; }
r[3]|=r[0];
goto P_0c044ef8;
P_0c044ef8: /* original 2d32, guest PC 0x0c044ef8 */
if(!s->budget--) { s->failed_pc=0x0c044ef8u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c044efa;
P_0c044efa: /* original 7d04, guest PC 0x0c044efa */
if(!s->budget--) { s->failed_pc=0x0c044efau; return 0; }
r[13]+=0x00000004u;
goto P_0c044efc;
P_0c044efc: /* original 8fea, guest PC 0x0c044efc */
if(!s->budget--) { s->failed_pc=0x0c044efcu; return 0; }
cond=r[17]&1u;
r[7]+=0x00000004u;
if(!cond) { goto P_0c044ed4; }
goto P_0c044f00;
P_0c044efe: /* original 7704, guest PC 0x0c044efe */
if(!s->budget--) { s->failed_pc=0x0c044efeu; return 0; }
r[7]+=0x00000004u;
goto P_0c044f00;
P_0c044f00: /* original a00b, guest PC 0x0c044f00 */
if(!s->budget--) { s->failed_pc=0x0c044f00u; return 0; }
goto P_0c044f1a;
P_0c044f02: /* original 0009, guest PC 0x0c044f02 */
if(!s->budget--) { s->failed_pc=0x0c044f02u; return 0; }
goto P_0c044f04;
P_0c044f04: /* original e040, guest PC 0x0c044f04 */
if(!s->budget--) { s->failed_pc=0x0c044f04u; return 0; }
r[0]=0x00000040u;
goto P_0c044f06;
P_0c044f06: /* original 4c15, guest PC 0x0c044f06 */
if(!s->budget--) { s->failed_pc=0x0c044f06u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c044f08;
P_0c044f08: /* original 05fe, guest PC 0x0c044f08 */
if(!s->budget--) { s->failed_pc=0x0c044f08u; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c044f0a;
P_0c044f0a: /* original 8f06, guest PC 0x0c044f0a */
if(!s->budget--) { s->failed_pc=0x0c044f0au; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(!cond) { goto P_0c044f1a; }
goto P_0c044f0e;
P_0c044f0c: /* original e400, guest PC 0x0c044f0c */
if(!s->budget--) { s->failed_pc=0x0c044f0cu; return 0; }
r[4]=0x00000000u;
goto P_0c044f0e;
P_0c044f0e: /* original 6356, guest PC 0x0c044f0e */
if(!s->budget--) { s->failed_pc=0x0c044f0eu; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[3]=tmp;
goto P_0c044f10;
P_0c044f10: /* original 7401, guest PC 0x0c044f10 */
if(!s->budget--) { s->failed_pc=0x0c044f10u; return 0; }
r[4]+=0x00000001u;
goto P_0c044f12;
P_0c044f12: /* original 34c3, guest PC 0x0c044f12 */
if(!s->budget--) { s->failed_pc=0x0c044f12u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[12])!=0);
goto P_0c044f14;
P_0c044f14: /* original 2d32, guest PC 0x0c044f14 */
if(!s->budget--) { s->failed_pc=0x0c044f14u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c044f16;
P_0c044f16: /* original 8ffa, guest PC 0x0c044f16 */
if(!s->budget--) { s->failed_pc=0x0c044f16u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000004u;
if(!cond) { goto P_0c044f0e; }
goto P_0c044f1a;
P_0c044f18: /* original 7d04, guest PC 0x0c044f18 */
if(!s->budget--) { s->failed_pc=0x0c044f18u; return 0; }
r[13]+=0x00000004u;
goto P_0c044f1a;
P_0c044f1a: /* original 904d, guest PC 0x0c044f1a */
if(!s->budget--) { s->failed_pc=0x0c044f1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044fb8u,2);
goto P_0c044f1c;
P_0c044f1c: /* original 52f2, guest PC 0x0c044f1c */
if(!s->budget--) { s->failed_pc=0x0c044f1cu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c044f1e;
P_0c044f1e: /* original 63e2, guest PC 0x0c044f1e */
if(!s->budget--) { s->failed_pc=0x0c044f1eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044f20;
P_0c044f20: /* original 0326, guest PC 0x0c044f20 */
if(!s->budget--) { s->failed_pc=0x0c044f20u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c044f22;
P_0c044f22: /* original 7004, guest PC 0x0c044f22 */
if(!s->budget--) { s->failed_pc=0x0c044f22u; return 0; }
r[0]+=0x00000004u;
goto P_0c044f24;
P_0c044f24: /* original 63e2, guest PC 0x0c044f24 */
if(!s->budget--) { s->failed_pc=0x0c044f24u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044f26;
P_0c044f26: /* original 52f2, guest PC 0x0c044f26 */
if(!s->budget--) { s->failed_pc=0x0c044f26u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c044f28;
P_0c044f28: /* original 013e, guest PC 0x0c044f28 */
if(!s->budget--) { s->failed_pc=0x0c044f28u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c044f2a;
P_0c044f2a: /* original 4208, guest PC 0x0c044f2a */
if(!s->budget--) { s->failed_pc=0x0c044f2au; return 0; }
r[2]<<=2;
goto P_0c044f2c;
P_0c044f2c: /* original 312c, guest PC 0x0c044f2c */
if(!s->budget--) { s->failed_pc=0x0c044f2cu; return 0; }
r[1]+=r[2];
goto P_0c044f2e;
P_0c044f2e: /* original 0316, guest PC 0x0c044f2e */
if(!s->budget--) { s->failed_pc=0x0c044f2eu; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c044f30;
P_0c044f30: /* original 7004, guest PC 0x0c044f30 */
if(!s->budget--) { s->failed_pc=0x0c044f30u; return 0; }
r[0]+=0x00000004u;
goto P_0c044f32;
P_0c044f32: /* original 63e2, guest PC 0x0c044f32 */
if(!s->budget--) { s->failed_pc=0x0c044f32u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044f34;
P_0c044f34: /* original 62e2, guest PC 0x0c044f34 */
if(!s->budget--) { s->failed_pc=0x0c044f34u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c044f36;
P_0c044f36: /* original 013e, guest PC 0x0c044f36 */
if(!s->budget--) { s->failed_pc=0x0c044f36u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c044f38;
P_0c044f38: /* original 7228, guest PC 0x0c044f38 */
if(!s->budget--) { s->failed_pc=0x0c044f38u; return 0; }
r[2]+=0x00000028u;
goto P_0c044f3a;
P_0c044f3a: /* original 7101, guest PC 0x0c044f3a */
if(!s->budget--) { s->failed_pc=0x0c044f3au; return 0; }
r[1]+=0x00000001u;
goto P_0c044f3c;
P_0c044f3c: /* original 0316, guest PC 0x0c044f3c */
if(!s->budget--) { s->failed_pc=0x0c044f3cu; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c044f3e;
P_0c044f3e: /* original 71ff, guest PC 0x0c044f3e */
if(!s->budget--) { s->failed_pc=0x0c044f3eu; return 0; }
r[1]+=0xffffffffu;
goto P_0c044f40;
P_0c044f40: /* original 32ac, guest PC 0x0c044f40 */
if(!s->budget--) { s->failed_pc=0x0c044f40u; return 0; }
r[2]+=r[10];
goto P_0c044f42;
P_0c044f42: /* original 1216, guest PC 0x0c044f42 */
if(!s->budget--) { s->failed_pc=0x0c044f42u; return 0; }
write(ram,r[2]+24,r[1],4);
goto P_0c044f44;
P_0c044f44: /* original 63e2, guest PC 0x0c044f44 */
if(!s->budget--) { s->failed_pc=0x0c044f44u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044f46;
P_0c044f46: /* original d21e, guest PC 0x0c044f46 */
if(!s->budget--) { s->failed_pc=0x0c044f46u; return 0; }
r[2]=read(ram,0x0c044fc0u,4);
goto P_0c044f48;
P_0c044f48: /* original 013e, guest PC 0x0c044f48 */
if(!s->budget--) { s->failed_pc=0x0c044f48u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c044f4a;
P_0c044f4a: /* original 2129, guest PC 0x0c044f4a */
if(!s->budget--) { s->failed_pc=0x0c044f4au; return 0; }
r[1]&=r[2];
goto P_0c044f4c;
P_0c044f4c: /* original 0316, guest PC 0x0c044f4c */
if(!s->budget--) { s->failed_pc=0x0c044f4cu; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c044f4e;
P_0c044f4e: /* original 63e2, guest PC 0x0c044f4e */
if(!s->budget--) { s->failed_pc=0x0c044f4eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c044f50;
P_0c044f50: /* original 013e, guest PC 0x0c044f50 */
if(!s->budget--) { s->failed_pc=0x0c044f50u; return 0; }
r[1]=read(ram,r[3]+r[0],4);
goto P_0c044f52;
P_0c044f52: /* original 2118, guest PC 0x0c044f52 */
if(!s->budget--) { s->failed_pc=0x0c044f52u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c044f54;
P_0c044f54: /* original 8b03, guest PC 0x0c044f54 */
if(!s->budget--) { s->failed_pc=0x0c044f54u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c044f5e; }
goto P_0c044f56;
P_0c044f56: /* original 9030, guest PC 0x0c044f56 */
if(!s->budget--) { s->failed_pc=0x0c044f56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c044fbau,2);
goto P_0c044f58;
P_0c044f58: /* original e301, guest PC 0x0c044f58 */
if(!s->budget--) { s->failed_pc=0x0c044f58u; return 0; }
r[3]=0x00000001u;
goto P_0c044f5a;
P_0c044f5a: /* original 61e2, guest PC 0x0c044f5a */
if(!s->budget--) { s->failed_pc=0x0c044f5au; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c044f5c;
P_0c044f5c: /* original 0136, guest PC 0x0c044f5c */
if(!s->budget--) { s->failed_pc=0x0c044f5cu; return 0; }
write(ram,r[1]+r[0],r[3],4);
goto P_0c044f5e;
P_0c044f5e: /* original 60e2, guest PC 0x0c044f5e */
if(!s->budget--) { s->failed_pc=0x0c044f5eu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c044f60;
P_0c044f60: /* original 7028, guest PC 0x0c044f60 */
if(!s->budget--) { s->failed_pc=0x0c044f60u; return 0; }
r[0]+=0x00000028u;
goto P_0c044f62;
P_0c044f62: /* original 30ac, guest PC 0x0c044f62 */
if(!s->budget--) { s->failed_pc=0x0c044f62u; return 0; }
r[0]+=r[10];
goto P_0c044f64;
P_0c044f64: /* original 5006, guest PC 0x0c044f64 */
if(!s->budget--) { s->failed_pc=0x0c044f64u; return 0; }
r[0]=read(ram,r[0]+24,4);
goto P_0c044f66;
P_0c044f66: /* original 7f1c, guest PC 0x0c044f66 */
if(!s->budget--) { s->failed_pc=0x0c044f66u; return 0; }
r[15]+=0x0000001cu;
goto P_0c044f68;
P_0c044f68: /* original 4f16, guest PC 0x0c044f68 */
if(!s->budget--) { s->failed_pc=0x0c044f68u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c044f6a;
P_0c044f6a: /* original 4f26, guest PC 0x0c044f6a */
if(!s->budget--) { s->failed_pc=0x0c044f6au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c044f6c;
P_0c044f6c: /* original 68f6, guest PC 0x0c044f6c */
if(!s->budget--) { s->failed_pc=0x0c044f6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c044f6e;
P_0c044f6e: /* original 69f6, guest PC 0x0c044f6e */
if(!s->budget--) { s->failed_pc=0x0c044f6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c044f70;
P_0c044f70: /* original 6af6, guest PC 0x0c044f70 */
if(!s->budget--) { s->failed_pc=0x0c044f70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c044f72;
P_0c044f72: /* original 6bf6, guest PC 0x0c044f72 */
if(!s->budget--) { s->failed_pc=0x0c044f72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c044f74;
P_0c044f74: /* original 6cf6, guest PC 0x0c044f74 */
if(!s->budget--) { s->failed_pc=0x0c044f74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c044f76;
P_0c044f76: /* original 6df6, guest PC 0x0c044f76 */
if(!s->budget--) { s->failed_pc=0x0c044f76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c044f78;
P_0c044f78: /* original 000b, guest PC 0x0c044f78 */
if(!s->budget--) { s->failed_pc=0x0c044f78u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c044f7a: /* original 6ef6, guest PC 0x0c044f7a */
if(!s->budget--) { s->failed_pc=0x0c044f7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c044f7cu,s,ram);
P_0c0459fc: /* original 4f22, guest PC 0x0c0459fc */
if(!s->budget--) { s->failed_pc=0x0c0459fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0459fe;
P_0c0459fe: /* original 6353, guest PC 0x0c0459fe */
if(!s->budget--) { s->failed_pc=0x0c0459feu; return 0; }
r[3]=r[5];
goto P_0c045a00;
P_0c045a00: /* original 7ff4, guest PC 0x0c045a00 */
if(!s->budget--) { s->failed_pc=0x0c045a00u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c045a02;
P_0c045a02: /* original 1f41, guest PC 0x0c045a02 */
if(!s->budget--) { s->failed_pc=0x0c045a02u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c045a04;
P_0c045a04: /* original 1f52, guest PC 0x0c045a04 */
if(!s->budget--) { s->failed_pc=0x0c045a04u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c045a06;
P_0c045a06: /* original 2f56, guest PC 0x0c045a06 */
if(!s->budget--) { s->failed_pc=0x0c045a06u; return 0; }
r[15]-=4; write(ram,r[15],r[5],4);
goto P_0c045a08;
P_0c045a08: /* original 52f2, guest PC 0x0c045a08 */
if(!s->budget--) { s->failed_pc=0x0c045a08u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c045a0a;
P_0c045a0a: /* original 2f26, guest PC 0x0c045a0a */
if(!s->budget--) { s->failed_pc=0x0c045a0au; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c045a0c;
P_0c045a0c: /* original d395, guest PC 0x0c045a0c */
if(!s->budget--) { s->failed_pc=0x0c045a0cu; return 0; }
r[3]=read(ram,0x0c045c64u,4);
goto P_0c045a0e;
P_0c045a0e: /* original d296, guest PC 0x0c045a0e */
if(!s->budget--) { s->failed_pc=0x0c045a0eu; return 0; }
r[2]=read(ram,0x0c045c68u,4);
goto P_0c045a10;
P_0c045a10: /* original 420b, guest PC 0x0c045a10 */
if(!s->budget--) { s->failed_pc=0x0c045a10u; return 0; }
target=r[2];
r[16]=0x0c045a14u;
r[15]-=4; write(ram,r[15],r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045a14u) { target=s->pc; goto dispatch; }
goto P_0c045a14;
P_0c045a12: /* original 2f36, guest PC 0x0c045a12 */
if(!s->budget--) { s->failed_pc=0x0c045a12u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c045a14;
P_0c045a14: /* original 51f5, guest PC 0x0c045a14 */
if(!s->budget--) { s->failed_pc=0x0c045a14u; return 0; }
r[1]=read(ram,r[15]+20,4);
goto P_0c045a16;
P_0c045a16: /* original e300, guest PC 0x0c045a16 */
if(!s->budget--) { s->failed_pc=0x0c045a16u; return 0; }
r[3]=0x00000000u;
goto P_0c045a18;
P_0c045a18: /* original e509, guest PC 0x0c045a18 */
if(!s->budget--) { s->failed_pc=0x0c045a18u; return 0; }
r[5]=0x00000009u;
goto P_0c045a1a;
P_0c045a1a: /* original 1f13, guest PC 0x0c045a1a */
if(!s->budget--) { s->failed_pc=0x0c045a1au; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c045a1c;
P_0c045a1c: /* original e701, guest PC 0x0c045a1c */
if(!s->budget--) { s->failed_pc=0x0c045a1cu; return 0; }
r[7]=0x00000001u;
goto P_0c045a1e;
P_0c045a1e: /* original 2f36, guest PC 0x0c045a1e */
if(!s->budget--) { s->failed_pc=0x0c045a1eu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c045a20;
P_0c045a20: /* original 2f36, guest PC 0x0c045a20 */
if(!s->budget--) { s->failed_pc=0x0c045a20u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c045a22;
P_0c045a22: /* original 66f3, guest PC 0x0c045a22 */
if(!s->budget--) { s->failed_pc=0x0c045a22u; return 0; }
r[6]=r[15];
goto P_0c045a24;
P_0c045a24: /* original 7614, guest PC 0x0c045a24 */
if(!s->budget--) { s->failed_pc=0x0c045a24u; return 0; }
r[6]+=0x00000014u;
goto P_0c045a26;
P_0c045a26: /* original b94b, guest PC 0x0c045a26 */
if(!s->budget--) { s->failed_pc=0x0c045a26u; return 0; }
target=0x0c044cc0u; r[16]=0x0c045a2au;
r[4]=read(ram,r[15]+24,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045a2au) { target=s->pc; goto dispatch; }
goto P_0c045a2a;
P_0c045a28: /* original 54f6, guest PC 0x0c045a28 */
if(!s->budget--) { s->failed_pc=0x0c045a28u; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c045a2a;
P_0c045a2a: /* original 7f20, guest PC 0x0c045a2a */
if(!s->budget--) { s->failed_pc=0x0c045a2au; return 0; }
r[15]+=0x00000020u;
goto P_0c045a2c;
P_0c045a2c: /* original 4f26, guest PC 0x0c045a2c */
if(!s->budget--) { s->failed_pc=0x0c045a2cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045a2e;
P_0c045a2e: /* original 000b, guest PC 0x0c045a2e */
if(!s->budget--) { s->failed_pc=0x0c045a2eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c045a30: /* original 0009, guest PC 0x0c045a30 */
if(!s->budget--) { s->failed_pc=0x0c045a30u; return 0; }
return vf3_matrix_family(0x0c045a32u,s,ram);
P_0c045a5e: /* original 4f22, guest PC 0x0c045a5e */
if(!s->budget--) { s->failed_pc=0x0c045a5eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045a60;
P_0c045a60: /* original 6343, guest PC 0x0c045a60 */
if(!s->budget--) { s->failed_pc=0x0c045a60u; return 0; }
r[3]=r[4];
goto P_0c045a62;
P_0c045a62: /* original 7ffc, guest PC 0x0c045a62 */
if(!s->budget--) { s->failed_pc=0x0c045a62u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c045a64;
P_0c045a64: /* original 2f42, guest PC 0x0c045a64 */
if(!s->budget--) { s->failed_pc=0x0c045a64u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c045a66;
P_0c045a66: /* original 2f46, guest PC 0x0c045a66 */
if(!s->budget--) { s->failed_pc=0x0c045a66u; return 0; }
r[15]-=4; write(ram,r[15],r[4],4);
goto P_0c045a68;
P_0c045a68: /* original d282, guest PC 0x0c045a68 */
if(!s->budget--) { s->failed_pc=0x0c045a68u; return 0; }
r[2]=read(ram,0x0c045c74u,4);
goto P_0c045a6a;
P_0c045a6a: /* original d37f, guest PC 0x0c045a6a */
if(!s->budget--) { s->failed_pc=0x0c045a6au; return 0; }
r[3]=read(ram,0x0c045c68u,4);
goto P_0c045a6c;
P_0c045a6c: /* original 430b, guest PC 0x0c045a6c */
if(!s->budget--) { s->failed_pc=0x0c045a6cu; return 0; }
target=r[3];
r[16]=0x0c045a70u;
r[15]-=4; write(ram,r[15],r[2],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045a70u) { target=s->pc; goto dispatch; }
goto P_0c045a70;
P_0c045a6e: /* original 2f26, guest PC 0x0c045a6e */
if(!s->budget--) { s->failed_pc=0x0c045a6eu; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c045a70;
P_0c045a70: /* original e100, guest PC 0x0c045a70 */
if(!s->budget--) { s->failed_pc=0x0c045a70u; return 0; }
r[1]=0x00000000u;
goto P_0c045a72;
P_0c045a72: /* original 2f16, guest PC 0x0c045a72 */
if(!s->budget--) { s->failed_pc=0x0c045a72u; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c045a74;
P_0c045a74: /* original 6613, guest PC 0x0c045a74 */
if(!s->budget--) { s->failed_pc=0x0c045a74u; return 0; }
r[6]=r[1];
goto P_0c045a76;
P_0c045a76: /* original e501, guest PC 0x0c045a76 */
if(!s->budget--) { s->failed_pc=0x0c045a76u; return 0; }
r[5]=0x00000001u;
goto P_0c045a78;
P_0c045a78: /* original 2f16, guest PC 0x0c045a78 */
if(!s->budget--) { s->failed_pc=0x0c045a78u; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c045a7a;
P_0c045a7a: /* original 6713, guest PC 0x0c045a7a */
if(!s->budget--) { s->failed_pc=0x0c045a7au; return 0; }
r[7]=r[1];
goto P_0c045a7c;
P_0c045a7c: /* original b920, guest PC 0x0c045a7c */
if(!s->budget--) { s->failed_pc=0x0c045a7cu; return 0; }
target=0x0c044cc0u; r[16]=0x0c045a80u;
r[4]=read(ram,r[15]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045a80u) { target=s->pc; goto dispatch; }
goto P_0c045a80;
P_0c045a7e: /* original 54f4, guest PC 0x0c045a7e */
if(!s->budget--) { s->failed_pc=0x0c045a7eu; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c045a80;
P_0c045a80: /* original 7f14, guest PC 0x0c045a80 */
if(!s->budget--) { s->failed_pc=0x0c045a80u; return 0; }
r[15]+=0x00000014u;
goto P_0c045a82;
P_0c045a82: /* original 4f26, guest PC 0x0c045a82 */
if(!s->budget--) { s->failed_pc=0x0c045a82u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045a84;
P_0c045a84: /* original 000b, guest PC 0x0c045a84 */
if(!s->budget--) { s->failed_pc=0x0c045a84u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c045a86: /* original 0009, guest PC 0x0c045a86 */
if(!s->budget--) { s->failed_pc=0x0c045a86u; return 0; }
return vf3_matrix_family(0x0c045a88u,s,ram);
P_0c045f62: /* original 4f22, guest PC 0x0c045f62 */
if(!s->budget--) { s->failed_pc=0x0c045f62u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045f64;
P_0c045f64: /* original d02d, guest PC 0x0c045f64 */
if(!s->budget--) { s->failed_pc=0x0c045f64u; return 0; }
r[0]=read(ram,0x0c04601cu,4);
goto P_0c045f66;
P_0c045f66: /* original 4e08, guest PC 0x0c045f66 */
if(!s->budget--) { s->failed_pc=0x0c045f66u; return 0; }
r[14]<<=2;
goto P_0c045f68;
P_0c045f68: /* original a004, guest PC 0x0c045f68 */
if(!s->budget--) { s->failed_pc=0x0c045f68u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c045f74;
P_0c045f6a: /* original 0eee, guest PC 0x0c045f6a */
if(!s->budget--) { s->failed_pc=0x0c045f6au; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c045f6c;
P_0c045f6c: /* original 62e2, guest PC 0x0c045f6c */
if(!s->budget--) { s->failed_pc=0x0c045f6cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c045f6e;
P_0c045f6e: /* original 420b, guest PC 0x0c045f6e */
if(!s->budget--) { s->failed_pc=0x0c045f6eu; return 0; }
target=r[2];
r[16]=0x0c045f72u;
r[4]=read(ram,r[14]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045f72u) { target=s->pc; goto dispatch; }
goto P_0c045f72;
P_0c045f70: /* original 54e2, guest PC 0x0c045f70 */
if(!s->budget--) { s->failed_pc=0x0c045f70u; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c045f72;
P_0c045f72: /* original 5ee1, guest PC 0x0c045f72 */
if(!s->budget--) { s->failed_pc=0x0c045f72u; return 0; }
r[14]=read(ram,r[14]+4,4);
goto P_0c045f74;
P_0c045f74: /* original 2ee8, guest PC 0x0c045f74 */
if(!s->budget--) { s->failed_pc=0x0c045f74u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c045f76;
P_0c045f76: /* original 8bf9, guest PC 0x0c045f76 */
if(!s->budget--) { s->failed_pc=0x0c045f76u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c045f6c; }
goto P_0c045f78;
P_0c045f78: /* original 4f26, guest PC 0x0c045f78 */
if(!s->budget--) { s->failed_pc=0x0c045f78u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045f7a;
P_0c045f7a: /* original 000b, guest PC 0x0c045f7a */
if(!s->budget--) { s->failed_pc=0x0c045f7au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c045f7c: /* original 6ef6, guest PC 0x0c045f7c */
if(!s->budget--) { s->failed_pc=0x0c045f7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c045f7eu,s,ram);
P_0c0460a6: /* original 4f22, guest PC 0x0c0460a6 */
if(!s->budget--) { s->failed_pc=0x0c0460a6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0460a8;
P_0c0460a8: /* original d10d, guest PC 0x0c0460a8 */
if(!s->budget--) { s->failed_pc=0x0c0460a8u; return 0; }
r[1]=read(ram,0x0c0460e0u,4);
goto P_0c0460aa;
P_0c0460aa: /* original d20c, guest PC 0x0c0460aa */
if(!s->budget--) { s->failed_pc=0x0c0460aau; return 0; }
r[2]=read(ram,0x0c0460dcu,4);
goto P_0c0460ac;
P_0c0460ac: /* original 6312, guest PC 0x0c0460ac */
if(!s->budget--) { s->failed_pc=0x0c0460acu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c0460ae;
P_0c0460ae: /* original 2232, guest PC 0x0c0460ae */
if(!s->budget--) { s->failed_pc=0x0c0460aeu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0460b0;
P_0c0460b0: /* original bf55, guest PC 0x0c0460b0 */
if(!s->budget--) { s->failed_pc=0x0c0460b0u; return 0; }
target=0x0c045f5eu; r[16]=0x0c0460b4u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0460b4u) { target=s->pc; goto dispatch; }
goto P_0c0460b4;
P_0c0460b2: /* original e400, guest PC 0x0c0460b2 */
if(!s->budget--) { s->failed_pc=0x0c0460b2u; return 0; }
r[4]=0x00000000u;
goto P_0c0460b4;
P_0c0460b4: /* original d208, guest PC 0x0c0460b4 */
if(!s->budget--) { s->failed_pc=0x0c0460b4u; return 0; }
r[2]=read(ram,0x0c0460d8u,4);
goto P_0c0460b6;
P_0c0460b6: /* original 6e22, guest PC 0x0c0460b6 */
if(!s->budget--) { s->failed_pc=0x0c0460b6u; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c0460b8;
P_0c0460b8: /* original 2ee8, guest PC 0x0c0460b8 */
if(!s->budget--) { s->failed_pc=0x0c0460b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0460ba;
P_0c0460ba: /* original 8901, guest PC 0x0c0460ba */
if(!s->budget--) { s->failed_pc=0x0c0460bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0460c0; }
goto P_0c0460bc;
P_0c0460bc: /* original 4e0b, guest PC 0x0c0460bc */
if(!s->budget--) { s->failed_pc=0x0c0460bcu; return 0; }
target=r[14];
r[16]=0x0c0460c0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0460c0u) { target=s->pc; goto dispatch; }
goto P_0c0460c0;
P_0c0460be: /* original 0009, guest PC 0x0c0460be */
if(!s->budget--) { s->failed_pc=0x0c0460beu; return 0; }
goto P_0c0460c0;
P_0c0460c0: /* original d207, guest PC 0x0c0460c0 */
if(!s->budget--) { s->failed_pc=0x0c0460c0u; return 0; }
r[2]=read(ram,0x0c0460e0u,4);
goto P_0c0460c2;
P_0c0460c2: /* original d108, guest PC 0x0c0460c2 */
if(!s->budget--) { s->failed_pc=0x0c0460c2u; return 0; }
r[1]=read(ram,0x0c0460e4u,4);
goto P_0c0460c4;
P_0c0460c4: /* original 6322, guest PC 0x0c0460c4 */
if(!s->budget--) { s->failed_pc=0x0c0460c4u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0460c6;
P_0c0460c6: /* original 4f26, guest PC 0x0c0460c6 */
if(!s->budget--) { s->failed_pc=0x0c0460c6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0460c8;
P_0c0460c8: /* original e000, guest PC 0x0c0460c8 */
if(!s->budget--) { s->failed_pc=0x0c0460c8u; return 0; }
r[0]=0x00000000u;
goto P_0c0460ca;
P_0c0460ca: /* original 2132, guest PC 0x0c0460ca */
if(!s->budget--) { s->failed_pc=0x0c0460cau; return 0; }
write(ram,r[1],r[3],4);
goto P_0c0460cc;
P_0c0460cc: /* original 000b, guest PC 0x0c0460cc */
if(!s->budget--) { s->failed_pc=0x0c0460ccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0460ce: /* original 6ef6, guest PC 0x0c0460ce */
if(!s->budget--) { s->failed_pc=0x0c0460ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0460d0u,s,ram);
P_0c048008: /* original f60b, guest PC 0x0c048008 */
if(!s->budget--) { s->failed_pc=0x0c048008u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c04800a;
P_0c04800a: /* original 8900, guest PC 0x0c04800a */
if(!s->budget--) { s->failed_pc=0x0c04800au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04800e; }
goto P_0c04800c;
P_0c04800c: /* original 6263, guest PC 0x0c04800c */
if(!s->budget--) { s->failed_pc=0x0c04800cu; return 0; }
r[2]=r[6];
goto P_0c04800e;
P_0c04800e: /* original 2622, guest PC 0x0c04800e */
if(!s->budget--) { s->failed_pc=0x0c04800eu; return 0; }
write(ram,r[6],r[2],4);
goto P_0c048010;
P_0c048010: /* original f3fd, guest PC 0x0c048010 */
if(!s->budget--) { s->failed_pc=0x0c048010u; return 0; }
r[18]^=0x100000u;
goto P_0c048012;
P_0c048012: /* original 0683, guest PC 0x0c048012 */
if(!s->budget--) { s->failed_pc=0x0c048012u; return 0; }
goto P_0c048014;
P_0c048014: /* original 000b, guest PC 0x0c048014 */
if(!s->budget--) { s->failed_pc=0x0c048014u; return 0; }
target=r[16];
r[6]+=0x00000020u;
s->pc=target; return ram->oob==0;
P_0c048016: /* original 7620, guest PC 0x0c048016 */
if(!s->budget--) { s->failed_pc=0x0c048016u; return 0; }
r[6]+=0x00000020u;
return vf3_matrix_family(0x0c048018u,s,ram);
P_0c04860e: /* original f449, guest PC 0x0c04860e */
if(!s->budget--) { s->failed_pc=0x0c04860eu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048610;
P_0c048610: /* original f649, guest PC 0x0c048610 */
if(!s->budget--) { s->failed_pc=0x0c048610u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048612;
P_0c048612: /* original f049, guest PC 0x0c048612 */
if(!s->budget--) { s->failed_pc=0x0c048612u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048614;
P_0c048614: /* original f270, guest PC 0x0c048614 */
if(!s->budget--) { s->failed_pc=0x0c048614u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'+');
goto P_0c048616;
P_0c048616: /* original f79d, guest PC 0x0c048616 */
if(!s->budget--) { s->failed_pc=0x0c048616u; return 0; }
fr[7]=0x3f800000u;
goto P_0c048618;
P_0c048618: /* original f38d, guest PC 0x0c048618 */
if(!s->budget--) { s->failed_pc=0x0c048618u; return 0; }
fr[3]=0;
goto P_0c04861a;
P_0c04861a: /* original fb8d, guest PC 0x0c04861a */
if(!s->budget--) { s->failed_pc=0x0c04861au; return 0; }
fr[11]=0;
goto P_0c04861c;
P_0c04861c: /* original f5fd, guest PC 0x0c04861c */
if(!s->budget--) { s->failed_pc=0x0c04861cu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c04861e;
P_0c04861e: /* original 6146, guest PC 0x0c04861e */
if(!s->budget--) { s->failed_pc=0x0c04861eu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[1]=tmp;
goto P_0c048620;
P_0c048620: /* original 6246, guest PC 0x0c048620 */
if(!s->budget--) { s->failed_pc=0x0c048620u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[2]=tmp;
goto P_0c048622;
P_0c048622: /* original 0483, guest PC 0x0c048622 */
if(!s->budget--) { s->failed_pc=0x0c048622u; return 0; }
goto P_0c048624;
P_0c048624: /* original 7420, guest PC 0x0c048624 */
if(!s->budget--) { s->failed_pc=0x0c048624u; return 0; }
r[4]+=0x00000020u;
goto P_0c048626;
P_0c048626: /* original ff1d, guest PC 0x0c048626 */
if(!s->budget--) { s->failed_pc=0x0c048626u; return 0; }
r[53]=fr[15];
goto P_0c048628;
P_0c048628: /* original f3ed, guest PC 0x0c048628 */
if(!s->budget--) { s->failed_pc=0x0c048628u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c04862a;
P_0c04862a: /* original f79d, guest PC 0x0c04862a */
if(!s->budget--) { s->failed_pc=0x0c04862au; return 0; }
fr[7]=0x3f800000u;
goto P_0c04862c;
P_0c04862c: /* original f743, guest PC 0x0c04862c */
if(!s->budget--) { s->failed_pc=0x0c04862cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
goto P_0c04862e;
P_0c04862e: /* original 0483, guest PC 0x0c04862e */
if(!s->budget--) { s->failed_pc=0x0c04862eu; return 0; }
goto P_0c048630;
P_0c048630: /* original f3b5, guest PC 0x0c048630 */
if(!s->budget--) { s->failed_pc=0x0c048630u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[11]))!=0);
goto P_0c048632;
P_0c048632: /* original 74e0, guest PC 0x0c048632 */
if(!s->budget--) { s->failed_pc=0x0c048632u; return 0; }
r[4]+=0xffffffe0u;
goto P_0c048634;
P_0c048634: /* original f8ed, guest PC 0x0c048634 */
if(!s->budget--) { s->failed_pc=0x0c048634u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c048636;
P_0c048636: /* original f20d, guest PC 0x0c048636 */
if(!s->budget--) { s->failed_pc=0x0c048636u; return 0; }
fr[2]=r[53];
goto P_0c048638;
P_0c048638: /* original 8b00, guest PC 0x0c048638 */
if(!s->budget--) { s->failed_pc=0x0c048638u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04863c; }
goto P_0c04863a;
P_0c04863a: /* original f230, guest PC 0x0c04863a */
if(!s->budget--) { s->failed_pc=0x0c04863au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c04863c;
P_0c04863c: /* original 2888, guest PC 0x0c04863c */
if(!s->budget--) { s->failed_pc=0x0c04863cu; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c04863e;
P_0c04863e: /* original f38d, guest PC 0x0c04863e */
if(!s->budget--) { s->failed_pc=0x0c04863eu; return 0; }
fr[3]=0;
goto P_0c048640;
P_0c048640: /* original 8d30, guest PC 0x0c048640 */
if(!s->budget--) { s->failed_pc=0x0c048640u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=0)!=0);
if(cond) { goto P_0c0486a4; }
goto P_0c048644;
P_0c048642: /* original 4811, guest PC 0x0c048642 */
if(!s->budget--) { s->failed_pc=0x0c048642u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=0)!=0);
goto P_0c048644;
P_0c048644: /* original 8f28, guest PC 0x0c048644 */
if(!s->budget--) { s->failed_pc=0x0c048644u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[3]))!=0);
if(!cond) { goto P_0c048698; }
goto P_0c048648;
P_0c048646: /* original fb35, guest PC 0x0c048646 */
if(!s->budget--) { s->failed_pc=0x0c048646u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[3]))!=0);
goto P_0c048648;
P_0c048648: /* original fbb2, guest PC 0x0c048648 */
if(!s->budget--) { s->failed_pc=0x0c048648u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'*');
goto P_0c04864a;
P_0c04864a: /* original f09d, guest PC 0x0c04864a */
if(!s->budget--) { s->failed_pc=0x0c04864au; return 0; }
fr[0]=0x3f800000u;
goto P_0c04864c;
P_0c04864c: /* original 8b2a, guest PC 0x0c04864c */
if(!s->budget--) { s->failed_pc=0x0c04864cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0486a4; }
goto P_0c04864e;
P_0c04864e: /* original fbb0, guest PC 0x0c04864e */
if(!s->budget--) { s->failed_pc=0x0c04864eu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'+');
goto P_0c048650;
P_0c048650: /* original fb05, guest PC 0x0c048650 */
if(!s->budget--) { s->failed_pc=0x0c048650u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[0]))!=0);
goto P_0c048652;
P_0c048652: /* original fb01, guest PC 0x0c048652 */
if(!s->budget--) { s->failed_pc=0x0c048652u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[0],r[18],'-');
goto P_0c048654;
P_0c048654: /* original 8b26, guest PC 0x0c048654 */
if(!s->budget--) { s->failed_pc=0x0c048654u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0486a4; }
goto P_0c048656;
P_0c048656: /* original fbb2, guest PC 0x0c048656 */
if(!s->budget--) { s->failed_pc=0x0c048656u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'*');
goto P_0c048658;
P_0c048658: /* original 0823, guest PC 0x0c048658 */
if(!s->budget--) { s->failed_pc=0x0c048658u; return 0; }
target=r[8]+0x0c04865cu;
fr[3]=vf3_fpu_binary(fr[3],fr[11],r[18],'+');
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c04865a: /* original f3b0, guest PC 0x0c04865a */
if(!s->budget--) { s->failed_pc=0x0c04865au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[11],r[18],'+');
return vf3_matrix_family(0x0c04865cu,s,ram);
P_0c048698: /* original a004, guest PC 0x0c048698 */
if(!s->budget--) { s->failed_pc=0x0c048698u; return 0; }
fr[2]=0x3f800000u;
goto P_0c0486a4;
P_0c04869a: /* original f29d, guest PC 0x0c04869a */
if(!s->budget--) { s->failed_pc=0x0c04869au; return 0; }
fr[2]=0x3f800000u;
return vf3_matrix_family(0x0c04869cu,s,ram);
P_0c0486a4: /* original f62b, guest PC 0x0c0486a4 */
if(!s->budget--) { s->failed_pc=0x0c0486a4u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c0486a6;
P_0c0486a6: /* original 7628, guest PC 0x0c0486a6 */
if(!s->budget--) { s->failed_pc=0x0c0486a6u; return 0; }
r[6]+=0x00000028u;
goto P_0c0486a8;
P_0c0486a8: /* original f62b, guest PC 0x0c0486a8 */
if(!s->budget--) { s->failed_pc=0x0c0486a8u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c0486aa;
P_0c0486aa: /* original f672, guest PC 0x0c0486aa */
if(!s->budget--) { s->failed_pc=0x0c0486aau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c0486ac;
P_0c0486ac: /* original 2626, guest PC 0x0c0486ac */
if(!s->budget--) { s->failed_pc=0x0c0486acu; return 0; }
r[6]-=4; write(ram,r[6],r[2],4);
goto P_0c0486ae;
P_0c0486ae: /* original f572, guest PC 0x0c0486ae */
if(!s->budget--) { s->failed_pc=0x0c0486aeu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c0486b0;
P_0c0486b0: /* original 2616, guest PC 0x0c0486b0 */
if(!s->budget--) { s->failed_pc=0x0c0486b0u; return 0; }
r[6]-=4; write(ram,r[6],r[1],4);
goto P_0c0486b2;
P_0c0486b2: /* original f66b, guest PC 0x0c0486b2 */
if(!s->budget--) { s->failed_pc=0x0c0486b2u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c0486b4;
P_0c0486b4: /* original f64b, guest PC 0x0c0486b4 */
if(!s->budget--) { s->failed_pc=0x0c0486b4u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c0486b6;
P_0c0486b6: /* original 2662, guest PC 0x0c0486b6 */
if(!s->budget--) { s->failed_pc=0x0c0486b6u; return 0; }
write(ram,r[6],r[6],4);
goto P_0c0486b8;
P_0c0486b8: /* original f28d, guest PC 0x0c0486b8 */
if(!s->budget--) { s->failed_pc=0x0c0486b8u; return 0; }
fr[2]=0;
goto P_0c0486ba;
P_0c0486ba: /* original f250, guest PC 0x0c0486ba */
if(!s->budget--) { s->failed_pc=0x0c0486bau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0486bc;
P_0c0486bc: /* original f38d, guest PC 0x0c0486bc */
if(!s->budget--) { s->failed_pc=0x0c0486bcu; return 0; }
fr[3]=0;
goto P_0c0486be;
P_0c0486be: /* original f360, guest PC 0x0c0486be */
if(!s->budget--) { s->failed_pc=0x0c0486beu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'+');
goto P_0c0486c0;
P_0c0486c0: /* original f449, guest PC 0x0c0486c0 */
if(!s->budget--) { s->failed_pc=0x0c0486c0u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0486c2;
P_0c0486c2: /* original f649, guest PC 0x0c0486c2 */
if(!s->budget--) { s->failed_pc=0x0c0486c2u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0486c4;
P_0c0486c4: /* original f79d, guest PC 0x0c0486c4 */
if(!s->budget--) { s->failed_pc=0x0c0486c4u; return 0; }
fr[7]=0x3f800000u;
goto P_0c0486c6;
P_0c0486c6: /* original 7408, guest PC 0x0c0486c6 */
if(!s->budget--) { s->failed_pc=0x0c0486c6u; return 0; }
r[4]+=0x00000008u;
goto P_0c0486c8;
P_0c0486c8: /* original 0683, guest PC 0x0c0486c8 */
if(!s->budget--) { s->failed_pc=0x0c0486c8u; return 0; }
goto P_0c0486ca;
P_0c0486ca: /* original 7638, guest PC 0x0c0486ca */
if(!s->budget--) { s->failed_pc=0x0c0486cau; return 0; }
r[6]+=0x00000038u;
goto P_0c0486cc;
P_0c0486cc: /* original f5fd, guest PC 0x0c0486cc */
if(!s->budget--) { s->failed_pc=0x0c0486ccu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c0486ce;
P_0c0486ce: /* original f049, guest PC 0x0c0486ce */
if(!s->budget--) { s->failed_pc=0x0c0486ceu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0486d0;
P_0c0486d0: /* original 7420, guest PC 0x0c0486d0 */
if(!s->budget--) { s->failed_pc=0x0c0486d0u; return 0; }
r[4]+=0x00000020u;
goto P_0c0486d2;
P_0c0486d2: /* original f79d, guest PC 0x0c0486d2 */
if(!s->budget--) { s->failed_pc=0x0c0486d2u; return 0; }
fr[7]=0x3f800000u;
goto P_0c0486d4;
P_0c0486d4: /* original 0483, guest PC 0x0c0486d4 */
if(!s->budget--) { s->failed_pc=0x0c0486d4u; return 0; }
goto P_0c0486d6;
P_0c0486d6: /* original f743, guest PC 0x0c0486d6 */
if(!s->budget--) { s->failed_pc=0x0c0486d6u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
goto P_0c0486d8;
P_0c0486d8: /* original 74e0, guest PC 0x0c0486d8 */
if(!s->budget--) { s->failed_pc=0x0c0486d8u; return 0; }
r[4]+=0xffffffe0u;
goto P_0c0486da;
P_0c0486da: /* original fb8d, guest PC 0x0c0486da */
if(!s->budget--) { s->failed_pc=0x0c0486dau; return 0; }
fr[11]=0;
goto P_0c0486dc;
P_0c0486dc: /* original f672, guest PC 0x0c0486dc */
if(!s->budget--) { s->failed_pc=0x0c0486dcu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c0486de;
P_0c0486de: /* original f60b, guest PC 0x0c0486de */
if(!s->budget--) { s->failed_pc=0x0c0486deu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c0486e0;
P_0c0486e0: /* original f572, guest PC 0x0c0486e0 */
if(!s->budget--) { s->failed_pc=0x0c0486e0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c0486e2;
P_0c0486e2: /* original f66b, guest PC 0x0c0486e2 */
if(!s->budget--) { s->failed_pc=0x0c0486e2u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c0486e4;
P_0c0486e4: /* original f361, guest PC 0x0c0486e4 */
if(!s->budget--) { s->failed_pc=0x0c0486e4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'-');
goto P_0c0486e6;
P_0c0486e6: /* original f64b, guest PC 0x0c0486e6 */
if(!s->budget--) { s->failed_pc=0x0c0486e6u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c0486e8;
P_0c0486e8: /* original f251, guest PC 0x0c0486e8 */
if(!s->budget--) { s->failed_pc=0x0c0486e8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0486ea;
P_0c0486ea: /* original 2662, guest PC 0x0c0486ea */
if(!s->budget--) { s->failed_pc=0x0c0486eau; return 0; }
write(ram,r[6],r[6],4);
goto P_0c0486ec;
P_0c0486ec: /* original fb50, guest PC 0x0c0486ec */
if(!s->budget--) { s->failed_pc=0x0c0486ecu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[5],r[18],'+');
goto P_0c0486ee;
P_0c0486ee: /* original f61d, guest PC 0x0c0486ee */
if(!s->budget--) { s->failed_pc=0x0c0486eeu; return 0; }
r[53]=fr[6];
goto P_0c0486f0;
P_0c0486f0: /* original f449, guest PC 0x0c0486f0 */
if(!s->budget--) { s->failed_pc=0x0c0486f0u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0486f2;
P_0c0486f2: /* original f649, guest PC 0x0c0486f2 */
if(!s->budget--) { s->failed_pc=0x0c0486f2u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0486f4;
P_0c0486f4: /* original f79d, guest PC 0x0c0486f4 */
if(!s->budget--) { s->failed_pc=0x0c0486f4u; return 0; }
fr[7]=0x3f800000u;
goto P_0c0486f6;
P_0c0486f6: /* original 7408, guest PC 0x0c0486f6 */
if(!s->budget--) { s->failed_pc=0x0c0486f6u; return 0; }
r[4]+=0x00000008u;
goto P_0c0486f8;
P_0c0486f8: /* original 0683, guest PC 0x0c0486f8 */
if(!s->budget--) { s->failed_pc=0x0c0486f8u; return 0; }
goto P_0c0486fa;
P_0c0486fa: /* original 7638, guest PC 0x0c0486fa */
if(!s->budget--) { s->failed_pc=0x0c0486fau; return 0; }
r[6]+=0x00000038u;
goto P_0c0486fc;
P_0c0486fc: /* original f5fd, guest PC 0x0c0486fc */
if(!s->budget--) { s->failed_pc=0x0c0486fcu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c0486fe;
P_0c0486fe: /* original f049, guest PC 0x0c0486fe */
if(!s->budget--) { s->failed_pc=0x0c0486feu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048700;
P_0c048700: /* original 0483, guest PC 0x0c048700 */
if(!s->budget--) { s->failed_pc=0x0c048700u; return 0; }
goto P_0c048702;
P_0c048702: /* original 7420, guest PC 0x0c048702 */
if(!s->budget--) { s->failed_pc=0x0c048702u; return 0; }
r[4]+=0x00000020u;
goto P_0c048704;
P_0c048704: /* original f79d, guest PC 0x0c048704 */
if(!s->budget--) { s->failed_pc=0x0c048704u; return 0; }
fr[7]=0x3f800000u;
goto P_0c048706;
P_0c048706: /* original 0483, guest PC 0x0c048706 */
if(!s->budget--) { s->failed_pc=0x0c048706u; return 0; }
goto P_0c048708;
P_0c048708: /* original f743, guest PC 0x0c048708 */
if(!s->budget--) { s->failed_pc=0x0c048708u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
goto P_0c04870a;
P_0c04870a: /* original 74e0, guest PC 0x0c04870a */
if(!s->budget--) { s->failed_pc=0x0c04870au; return 0; }
r[4]+=0xffffffe0u;
goto P_0c04870c;
P_0c04870c: /* original f672, guest PC 0x0c04870c */
if(!s->budget--) { s->failed_pc=0x0c04870cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c04870e;
P_0c04870e: /* original f60b, guest PC 0x0c04870e */
if(!s->budget--) { s->failed_pc=0x0c04870eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c048710;
P_0c048710: /* original f572, guest PC 0x0c048710 */
if(!s->budget--) { s->failed_pc=0x0c048710u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c048712;
P_0c048712: /* original f66b, guest PC 0x0c048712 */
if(!s->budget--) { s->failed_pc=0x0c048712u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c048714;
P_0c048714: /* original fb51, guest PC 0x0c048714 */
if(!s->budget--) { s->failed_pc=0x0c048714u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[5],r[18],'-');
goto P_0c048716;
P_0c048716: /* original f64b, guest PC 0x0c048716 */
if(!s->budget--) { s->failed_pc=0x0c048716u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c048718;
P_0c048718: /* original f3b2, guest PC 0x0c048718 */
if(!s->budget--) { s->failed_pc=0x0c048718u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[11],r[18],'*');
goto P_0c04871a;
P_0c04871a: /* original fb0d, guest PC 0x0c04871a */
if(!s->budget--) { s->failed_pc=0x0c04871au; return 0; }
fr[11]=r[53];
goto P_0c04871c;
P_0c04871c: /* original fb61, guest PC 0x0c04871c */
if(!s->budget--) { s->failed_pc=0x0c04871cu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[6],r[18],'-');
goto P_0c04871e;
P_0c04871e: /* original 6043, guest PC 0x0c04871e */
if(!s->budget--) { s->failed_pc=0x0c04871eu; return 0; }
r[0]=r[4];
goto P_0c048720;
P_0c048720: /* original f409, guest PC 0x0c048720 */
if(!s->budget--) { s->failed_pc=0x0c048720u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c048722;
P_0c048722: /* original f2b2, guest PC 0x0c048722 */
if(!s->budget--) { s->failed_pc=0x0c048722u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[11],r[18],'*');
goto P_0c048724;
P_0c048724: /* original f609, guest PC 0x0c048724 */
if(!s->budget--) { s->failed_pc=0x0c048724u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
r[0]+=(r[18]&0x100000u)?8:4;
goto P_0c048726;
P_0c048726: /* original f79d, guest PC 0x0c048726 */
if(!s->budget--) { s->failed_pc=0x0c048726u; return 0; }
fr[7]=0x3f800000u;
goto P_0c048728;
P_0c048728: /* original f235, guest PC 0x0c048728 */
if(!s->budget--) { s->failed_pc=0x0c048728u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c04872a;
P_0c04872a: /* original 2662, guest PC 0x0c04872a */
if(!s->budget--) { s->failed_pc=0x0c04872au; return 0; }
write(ram,r[6],r[6],4);
goto P_0c04872c;
P_0c04872c: /* original 7418, guest PC 0x0c04872c */
if(!s->budget--) { s->failed_pc=0x0c04872cu; return 0; }
r[4]+=0x00000018u;
goto P_0c04872e;
P_0c04872e: /* original f5fd, guest PC 0x0c04872e */
if(!s->budget--) { s->failed_pc=0x0c04872eu; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c048730;
P_0c048730: /* original 8b1c, guest PC 0x0c048730 */
if(!s->budget--) { s->failed_pc=0x0c048730u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04876c; }
goto P_0c048732;
P_0c048732: /* original 0683, guest PC 0x0c048732 */
if(!s->budget--) { s->failed_pc=0x0c048732u; return 0; }
goto P_0c048734;
P_0c048734: /* original 7638, guest PC 0x0c048734 */
if(!s->budget--) { s->failed_pc=0x0c048734u; return 0; }
r[6]+=0x00000038u;
goto P_0c048736;
P_0c048736: /* original f049, guest PC 0x0c048736 */
if(!s->budget--) { s->failed_pc=0x0c048736u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c048738;
P_0c048738: /* original 7420, guest PC 0x0c048738 */
if(!s->budget--) { s->failed_pc=0x0c048738u; return 0; }
r[4]+=0x00000020u;
goto P_0c04873a;
P_0c04873a: /* original f79d, guest PC 0x0c04873a */
if(!s->budget--) { s->failed_pc=0x0c04873au; return 0; }
fr[7]=0x3f800000u;
goto P_0c04873c;
P_0c04873c: /* original 0483, guest PC 0x0c04873c */
if(!s->budget--) { s->failed_pc=0x0c04873cu; return 0; }
goto P_0c04873e;
P_0c04873e: /* original f743, guest PC 0x0c04873e */
if(!s->budget--) { s->failed_pc=0x0c04873eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'/');
goto P_0c048740;
P_0c048740: /* original 74e0, guest PC 0x0c048740 */
if(!s->budget--) { s->failed_pc=0x0c048740u; return 0; }
r[4]+=0xffffffe0u;
goto P_0c048742;
P_0c048742: /* original f672, guest PC 0x0c048742 */
if(!s->budget--) { s->failed_pc=0x0c048742u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c048744;
P_0c048744: /* original 6063, guest PC 0x0c048744 */
if(!s->budget--) { s->failed_pc=0x0c048744u; return 0; }
r[0]=r[6];
goto P_0c048746;
P_0c048746: /* original f572, guest PC 0x0c048746 */
if(!s->budget--) { s->failed_pc=0x0c048746u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c048748;
P_0c048748: /* original 4021, guest PC 0x0c048748 */
if(!s->budget--) { s->failed_pc=0x0c048748u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c04874a;
P_0c04874a: /* original f60b, guest PC 0x0c04874a */
if(!s->budget--) { s->failed_pc=0x0c04874au; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c04874c;
P_0c04874c: /* original 7540, guest PC 0x0c04874c */
if(!s->budget--) { s->failed_pc=0x0c04874cu; return 0; }
r[5]+=0x00000040u;
goto P_0c04874e;
P_0c04874e: /* original f66b, guest PC 0x0c04874e */
if(!s->budget--) { s->failed_pc=0x0c04874eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c048750;
P_0c048750: /* original 7540, guest PC 0x0c048750 */
if(!s->budget--) { s->failed_pc=0x0c048750u; return 0; }
r[5]+=0x00000040u;
goto P_0c048752;
P_0c048752: /* original f64b, guest PC 0x0c048752 */
if(!s->budget--) { s->failed_pc=0x0c048752u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c048754;
P_0c048754: /* original 79bc, guest PC 0x0c048754 */
if(!s->budget--) { s->failed_pc=0x0c048754u; return 0; }
r[9]+=0xffffffbcu;
goto P_0c048756;
P_0c048756: /* original 2602, guest PC 0x0c048756 */
if(!s->budget--) { s->failed_pc=0x0c048756u; return 0; }
write(ram,r[6],r[0],4);
goto P_0c048758;
P_0c048758: /* original 2998, guest PC 0x0c048758 */
if(!s->budget--) { s->failed_pc=0x0c048758u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c04875a;
P_0c04875a: /* original 0683, guest PC 0x0c04875a */
if(!s->budget--) { s->failed_pc=0x0c04875au; return 0; }
goto P_0c04875c;
P_0c04875c: /* original 8d03, guest PC 0x0c04875c */
if(!s->budget--) { s->failed_pc=0x0c04875cu; return 0; }
cond=r[17]&1u;
r[6]+=0x00000020u;
if(cond) { goto P_0c048766; }
goto P_0c048760;
P_0c04875e: /* original 7620, guest PC 0x0c04875e */
if(!s->budget--) { s->failed_pc=0x0c04875eu; return 0; }
r[6]+=0x00000020u;
goto P_0c048760;
P_0c048760: /* original f28d, guest PC 0x0c048760 */
if(!s->budget--) { s->failed_pc=0x0c048760u; return 0; }
fr[2]=0;
goto P_0c048762;
P_0c048762: /* original af54, guest PC 0x0c048762 */
if(!s->budget--) { s->failed_pc=0x0c048762u; return 0; }
r[4]+=0x00000008u;
goto P_0c04860e;
P_0c048764: /* original 7408, guest PC 0x0c048764 */
if(!s->budget--) { s->failed_pc=0x0c048764u; return 0; }
r[4]+=0x00000008u;
goto P_0c048766;
P_0c048766: /* original 000b, guest PC 0x0c048766 */
if(!s->budget--) { s->failed_pc=0x0c048766u; return 0; }
target=r[16];
r[18]^=0x100000u;
s->pc=target; return ram->oob==0;
P_0c048768: /* original f3fd, guest PC 0x0c048768 */
if(!s->budget--) { s->failed_pc=0x0c048768u; return 0; }
r[18]^=0x100000u;
return vf3_matrix_family(0x0c04876au,s,ram);
P_0c04876c: /* original e1ff, guest PC 0x0c04876c */
if(!s->budget--) { s->failed_pc=0x0c04876cu; return 0; }
r[1]=0xffffffffu;
goto P_0c04876e;
P_0c04876e: /* original 79bc, guest PC 0x0c04876e */
if(!s->budget--) { s->failed_pc=0x0c04876eu; return 0; }
r[9]+=0xffffffbcu;
goto P_0c048770;
P_0c048770: /* original 2612, guest PC 0x0c048770 */
if(!s->budget--) { s->failed_pc=0x0c048770u; return 0; }
write(ram,r[6],r[1],4);
goto P_0c048772;
P_0c048772: /* original 7408, guest PC 0x0c048772 */
if(!s->budget--) { s->failed_pc=0x0c048772u; return 0; }
r[4]+=0x00000008u;
goto P_0c048774;
P_0c048774: /* original 2998, guest PC 0x0c048774 */
if(!s->budget--) { s->failed_pc=0x0c048774u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c048776;
P_0c048776: /* original 0683, guest PC 0x0c048776 */
if(!s->budget--) { s->failed_pc=0x0c048776u; return 0; }
goto P_0c048778;
P_0c048778: /* original 8d04, guest PC 0x0c048778 */
if(!s->budget--) { s->failed_pc=0x0c048778u; return 0; }
cond=r[17]&1u;
r[6]+=0xffffffc0u;
if(cond) { goto P_0c048784; }
goto P_0c04877c;
P_0c04877a: /* original 76c0, guest PC 0x0c04877a */
if(!s->budget--) { s->failed_pc=0x0c04877au; return 0; }
r[6]+=0xffffffc0u;
goto P_0c04877c;
P_0c04877c: /* original f28d, guest PC 0x0c04877c */
if(!s->budget--) { s->failed_pc=0x0c04877cu; return 0; }
fr[2]=0;
goto P_0c04877e;
P_0c04877e: /* original af46, guest PC 0x0c04877e */
if(!s->budget--) { s->failed_pc=0x0c04877eu; return 0; }
r[4]+=0x00000008u;
goto P_0c04860e;
P_0c048780: /* original 7408, guest PC 0x0c048780 */
if(!s->budget--) { s->failed_pc=0x0c048780u; return 0; }
r[4]+=0x00000008u;
return vf3_matrix_family(0x0c048782u,s,ram);
P_0c048784: /* original 000b, guest PC 0x0c048784 */
if(!s->budget--) { s->failed_pc=0x0c048784u; return 0; }
target=r[16];
r[18]^=0x100000u;
s->pc=target; return ram->oob==0;
P_0c048786: /* original f3fd, guest PC 0x0c048786 */
if(!s->budget--) { s->failed_pc=0x0c048786u; return 0; }
r[18]^=0x100000u;
return vf3_matrix_family(0x0c048788u,s,ram);
P_0c048caa: /* original f60b, guest PC 0x0c048caa */
if(!s->budget--) { s->failed_pc=0x0c048caau; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[6]);
goto P_0c048cac;
P_0c048cac: /* original 8900, guest PC 0x0c048cac */
if(!s->budget--) { s->failed_pc=0x0c048cacu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c048cb0; }
goto P_0c048cae;
P_0c048cae: /* original 6263, guest PC 0x0c048cae */
if(!s->budget--) { s->failed_pc=0x0c048caeu; return 0; }
r[2]=r[6];
goto P_0c048cb0;
P_0c048cb0: /* original 2622, guest PC 0x0c048cb0 */
if(!s->budget--) { s->failed_pc=0x0c048cb0u; return 0; }
write(ram,r[6],r[2],4);
goto P_0c048cb2;
P_0c048cb2: /* original f3fd, guest PC 0x0c048cb2 */
if(!s->budget--) { s->failed_pc=0x0c048cb2u; return 0; }
r[18]^=0x100000u;
goto P_0c048cb4;
P_0c048cb4: /* original 0683, guest PC 0x0c048cb4 */
if(!s->budget--) { s->failed_pc=0x0c048cb4u; return 0; }
goto P_0c048cb6;
P_0c048cb6: /* original 000b, guest PC 0x0c048cb6 */
if(!s->budget--) { s->failed_pc=0x0c048cb6u; return 0; }
target=r[16];
r[6]+=0x00000020u;
s->pc=target; return ram->oob==0;
P_0c048cb8: /* original 7620, guest PC 0x0c048cb8 */
if(!s->budget--) { s->failed_pc=0x0c048cb8u; return 0; }
r[6]+=0x00000020u;
return vf3_matrix_family(0x0c048cbau,s,ram);
P_0c04bd2a: /* original 4f22, guest PC 0x0c04bd2a */
if(!s->budget--) { s->failed_pc=0x0c04bd2au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04bd2c;
P_0c04bd2c: /* original 023e, guest PC 0x0c04bd2c */
if(!s->budget--) { s->failed_pc=0x0c04bd2cu; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c04bd2e;
P_0c04bd2e: /* original 8b04, guest PC 0x0c04bd2e */
if(!s->budget--) { s->failed_pc=0x0c04bd2eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04bd3a; }
goto P_0c04bd30;
P_0c04bd30: /* original 9036, guest PC 0x0c04bd30 */
if(!s->budget--) { s->failed_pc=0x0c04bd30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bda0u,2);
goto P_0c04bd32;
P_0c04bd32: /* original 61e2, guest PC 0x0c04bd32 */
if(!s->budget--) { s->failed_pc=0x0c04bd32u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c04bd34;
P_0c04bd34: /* original 011e, guest PC 0x0c04bd34 */
if(!s->budget--) { s->failed_pc=0x0c04bd34u; return 0; }
r[1]=read(ram,r[1]+r[0],4);
goto P_0c04bd36;
P_0c04bd36: /* original a001, guest PC 0x0c04bd36 */
if(!s->budget--) { s->failed_pc=0x0c04bd36u; return 0; }
r[1]+=r[4];
goto P_0c04bd3c;
P_0c04bd38: /* original 314c, guest PC 0x0c04bd38 */
if(!s->budget--) { s->failed_pc=0x0c04bd38u; return 0; }
r[1]+=r[4];
goto P_0c04bd3a;
P_0c04bd3a: /* original d11b, guest PC 0x0c04bd3a */
if(!s->budget--) { s->failed_pc=0x0c04bd3au; return 0; }
r[1]=read(ram,0x0c04bda8u,4);
goto P_0c04bd3c;
P_0c04bd3c: /* original 1215, guest PC 0x0c04bd3c */
if(!s->budget--) { s->failed_pc=0x0c04bd3cu; return 0; }
write(ram,r[2]+20,r[1],4);
goto P_0c04bd3e;
P_0c04bd3e: /* original 9030, guest PC 0x0c04bd3e */
if(!s->budget--) { s->failed_pc=0x0c04bd3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bda2u,2);
goto P_0c04bd40;
P_0c04bd40: /* original 64e2, guest PC 0x0c04bd40 */
if(!s->budget--) { s->failed_pc=0x0c04bd40u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c04bd42;
P_0c04bd42: /* original d31a, guest PC 0x0c04bd42 */
if(!s->budget--) { s->failed_pc=0x0c04bd42u; return 0; }
r[3]=read(ram,0x0c04bdacu,4);
goto P_0c04bd44;
P_0c04bd44: /* original 044e, guest PC 0x0c04bd44 */
if(!s->budget--) { s->failed_pc=0x0c04bd44u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c04bd46;
P_0c04bd46: /* original 430b, guest PC 0x0c04bd46 */
if(!s->budget--) { s->failed_pc=0x0c04bd46u; return 0; }
target=r[3];
r[16]=0x0c04bd4au;
r[4]+=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04bd4au) { target=s->pc; goto dispatch; }
goto P_0c04bd4a;
P_0c04bd48: /* original 7418, guest PC 0x0c04bd48 */
if(!s->budget--) { s->failed_pc=0x0c04bd48u; return 0; }
r[4]+=0x00000018u;
goto P_0c04bd4a;
P_0c04bd4a: /* original 2008, guest PC 0x0c04bd4a */
if(!s->budget--) { s->failed_pc=0x0c04bd4au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04bd4c;
P_0c04bd4c: /* original 8b04, guest PC 0x0c04bd4c */
if(!s->budget--) { s->failed_pc=0x0c04bd4cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04bd58; }
goto P_0c04bd4e;
P_0c04bd4e: /* original d318, guest PC 0x0c04bd4e */
if(!s->budget--) { s->failed_pc=0x0c04bd4eu; return 0; }
r[3]=read(ram,0x0c04bdb0u,4);
goto P_0c04bd50;
P_0c04bd50: /* original e501, guest PC 0x0c04bd50 */
if(!s->budget--) { s->failed_pc=0x0c04bd50u; return 0; }
r[5]=0x00000001u;
goto P_0c04bd52;
P_0c04bd52: /* original 64e2, guest PC 0x0c04bd52 */
if(!s->budget--) { s->failed_pc=0x0c04bd52u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c04bd54;
P_0c04bd54: /* original 430b, guest PC 0x0c04bd54 */
if(!s->budget--) { s->failed_pc=0x0c04bd54u; return 0; }
target=r[3];
r[16]=0x0c04bd58u;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04bd58u) { target=s->pc; goto dispatch; }
goto P_0c04bd58;
P_0c04bd56: /* original 7404, guest PC 0x0c04bd56 */
if(!s->budget--) { s->failed_pc=0x0c04bd56u; return 0; }
r[4]+=0x00000004u;
goto P_0c04bd58;
P_0c04bd58: /* original 4f26, guest PC 0x0c04bd58 */
if(!s->budget--) { s->failed_pc=0x0c04bd58u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04bd5a;
P_0c04bd5a: /* original 000b, guest PC 0x0c04bd5a */
if(!s->budget--) { s->failed_pc=0x0c04bd5au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04bd5c: /* original 6ef6, guest PC 0x0c04bd5c */
if(!s->budget--) { s->failed_pc=0x0c04bd5cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04bd5eu,s,ram);
P_0c053cac: /* original 4f22, guest PC 0x0c053cac */
if(!s->budget--) { s->failed_pc=0x0c053cacu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c053cae;
P_0c053cae: /* original 0eee, guest PC 0x0c053cae */
if(!s->budget--) { s->failed_pc=0x0c053caeu; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c053cb0;
P_0c053cb0: /* original d325, guest PC 0x0c053cb0 */
if(!s->budget--) { s->failed_pc=0x0c053cb0u; return 0; }
r[3]=read(ram,0x0c053d48u,4);
goto P_0c053cb2;
P_0c053cb2: /* original 7ffc, guest PC 0x0c053cb2 */
if(!s->budget--) { s->failed_pc=0x0c053cb2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c053cb4;
P_0c053cb4: /* original 430b, guest PC 0x0c053cb4 */
if(!s->budget--) { s->failed_pc=0x0c053cb4u; return 0; }
target=r[3];
r[16]=0x0c053cb8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053cb8u) { target=s->pc; goto dispatch; }
goto P_0c053cb8;
P_0c053cb6: /* original 64e3, guest PC 0x0c053cb6 */
if(!s->budget--) { s->failed_pc=0x0c053cb6u; return 0; }
r[4]=r[14];
goto P_0c053cb8;
P_0c053cb8: /* original 2f02, guest PC 0x0c053cb8 */
if(!s->budget--) { s->failed_pc=0x0c053cb8u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c053cba;
P_0c053cba: /* original d324, guest PC 0x0c053cba */
if(!s->budget--) { s->failed_pc=0x0c053cbau; return 0; }
r[3]=read(ram,0x0c053d4cu,4);
goto P_0c053cbc;
P_0c053cbc: /* original 430b, guest PC 0x0c053cbc */
if(!s->budget--) { s->failed_pc=0x0c053cbcu; return 0; }
target=r[3];
r[16]=0x0c053cc0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c053cc0u) { target=s->pc; goto dispatch; }
goto P_0c053cc0;
P_0c053cbe: /* original 64e3, guest PC 0x0c053cbe */
if(!s->budget--) { s->failed_pc=0x0c053cbeu; return 0; }
r[4]=r[14];
goto P_0c053cc0;
P_0c053cc0: /* original 62f2, guest PC 0x0c053cc0 */
if(!s->budget--) { s->failed_pc=0x0c053cc0u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c053cc2;
P_0c053cc2: /* original 6403, guest PC 0x0c053cc2 */
if(!s->budget--) { s->failed_pc=0x0c053cc2u; return 0; }
r[4]=r[0];
goto P_0c053cc4;
P_0c053cc4: /* original 6320, guest PC 0x0c053cc4 */
if(!s->budget--) { s->failed_pc=0x0c053cc4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c053cc6;
P_0c053cc6: /* original 2338, guest PC 0x0c053cc6 */
if(!s->budget--) { s->failed_pc=0x0c053cc6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c053cc8;
P_0c053cc8: /* original 8902, guest PC 0x0c053cc8 */
if(!s->budget--) { s->failed_pc=0x0c053cc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c053cd0; }
goto P_0c053cca;
P_0c053cca: /* original 6042, guest PC 0x0c053cca */
if(!s->budget--) { s->failed_pc=0x0c053ccau; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c053ccc;
P_0c053ccc: /* original c802, guest PC 0x0c053ccc */
if(!s->budget--) { s->failed_pc=0x0c053cccu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c053cce;
P_0c053cce: /* original 8b04, guest PC 0x0c053cce */
if(!s->budget--) { s->failed_pc=0x0c053cceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c053cda; }
goto P_0c053cd0;
P_0c053cd0: /* original 7f04, guest PC 0x0c053cd0 */
if(!s->budget--) { s->failed_pc=0x0c053cd0u; return 0; }
r[15]+=0x00000004u;
goto P_0c053cd2;
P_0c053cd2: /* original 4f26, guest PC 0x0c053cd2 */
if(!s->budget--) { s->failed_pc=0x0c053cd2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053cd4;
P_0c053cd4: /* original e000, guest PC 0x0c053cd4 */
if(!s->budget--) { s->failed_pc=0x0c053cd4u; return 0; }
r[0]=0x00000000u;
goto P_0c053cd6;
P_0c053cd6: /* original 000b, guest PC 0x0c053cd6 */
if(!s->budget--) { s->failed_pc=0x0c053cd6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c053cd8: /* original 6ef6, guest PC 0x0c053cd8 */
if(!s->budget--) { s->failed_pc=0x0c053cd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c053cda;
P_0c053cda: /* original e001, guest PC 0x0c053cda */
if(!s->budget--) { s->failed_pc=0x0c053cdau; return 0; }
r[0]=0x00000001u;
goto P_0c053cdc;
P_0c053cdc: /* original 7f04, guest PC 0x0c053cdc */
if(!s->budget--) { s->failed_pc=0x0c053cdcu; return 0; }
r[15]+=0x00000004u;
goto P_0c053cde;
P_0c053cde: /* original 4f26, guest PC 0x0c053cde */
if(!s->budget--) { s->failed_pc=0x0c053cdeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053ce0;
P_0c053ce0: /* original 000b, guest PC 0x0c053ce0 */
if(!s->budget--) { s->failed_pc=0x0c053ce0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c053ce2: /* original 6ef6, guest PC 0x0c053ce2 */
if(!s->budget--) { s->failed_pc=0x0c053ce2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c053ce4u,s,ram);
P_0c0559b4: /* original d117, guest PC 0x0c0559b4 */
if(!s->budget--) { s->failed_pc=0x0c0559b4u; return 0; }
r[1]=read(ram,0x0c055a14u,4);
goto P_0c0559b6;
P_0c0559b6: /* original e7ff, guest PC 0x0c0559b6 */
if(!s->budget--) { s->failed_pc=0x0c0559b6u; return 0; }
r[7]=0xffffffffu;
goto P_0c0559b8;
P_0c0559b8: /* original c612, guest PC 0x0c0559b8 */
if(!s->budget--) { s->failed_pc=0x0c0559b8u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+72,4);
goto P_0c0559ba;
P_0c0559ba: /* original 4709, guest PC 0x0c0559ba */
if(!s->budget--) { s->failed_pc=0x0c0559bau; return 0; }
r[7]>>=2;
goto P_0c0559bc;
P_0c0559bc: /* original 4709, guest PC 0x0c0559bc */
if(!s->budget--) { s->failed_pc=0x0c0559bcu; return 0; }
r[7]>>=2;
goto P_0c0559be;
P_0c0559be: /* original 6112, guest PC 0x0c0559be */
if(!s->budget--) { s->failed_pc=0x0c0559beu; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c0559c0;
P_0c0559c0: /* original 4709, guest PC 0x0c0559c0 */
if(!s->budget--) { s->failed_pc=0x0c0559c0u; return 0; }
r[7]>>=2;
goto P_0c0559c2;
P_0c0559c2: /* original 6303, guest PC 0x0c0559c2 */
if(!s->budget--) { s->failed_pc=0x0c0559c2u; return 0; }
r[3]=r[0];
goto P_0c0559c4;
P_0c0559c4: /* original c616, guest PC 0x0c0559c4 */
if(!s->budget--) { s->failed_pc=0x0c0559c4u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+88,4);
goto P_0c0559c6;
P_0c0559c6: /* original 6803, guest PC 0x0c0559c6 */
if(!s->budget--) { s->failed_pc=0x0c0559c6u; return 0; }
r[8]=r[0];
goto P_0c0559c8;
P_0c0559c8: /* original c614, guest PC 0x0c0559c8 */
if(!s->budget--) { s->failed_pc=0x0c0559c8u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+80,4);
goto P_0c0559ca;
P_0c0559ca: /* original 6277, guest PC 0x0c0559ca */
if(!s->budget--) { s->failed_pc=0x0c0559cau; return 0; }
r[2]=~r[7];
goto P_0c0559cc;
P_0c0559cc: /* original 5410, guest PC 0x0c0559cc */
if(!s->budget--) { s->failed_pc=0x0c0559ccu; return 0; }
r[4]=read(ram,r[1]+0,4);
goto P_0c0559ce;
P_0c0559ce: /* original 5512, guest PC 0x0c0559ce */
if(!s->budget--) { s->failed_pc=0x0c0559ceu; return 0; }
r[5]=read(ram,r[1]+8,4);
goto P_0c0559d0;
P_0c0559d0: /* original 5614, guest PC 0x0c0559d0 */
if(!s->budget--) { s->failed_pc=0x0c0559d0u; return 0; }
r[6]=read(ram,r[1]+16,4);
goto P_0c0559d2;
P_0c0559d2: /* original 2379, guest PC 0x0c0559d2 */
if(!s->budget--) { s->failed_pc=0x0c0559d2u; return 0; }
r[3]&=r[7];
goto P_0c0559d4;
P_0c0559d4: /* original 4f17, guest PC 0x0c0559d4 */
if(!s->budget--) { s->failed_pc=0x0c0559d4u; return 0; }
s->gbr=read(ram,r[15],4); r[15]+=4; s->gbr_known=1;
goto P_0c0559d6;
P_0c0559d6: /* original 2079, guest PC 0x0c0559d6 */
if(!s->budget--) { s->failed_pc=0x0c0559d6u; return 0; }
r[0]&=r[7];
goto P_0c0559d8;
P_0c0559d8: /* original 2879, guest PC 0x0c0559d8 */
if(!s->budget--) { s->failed_pc=0x0c0559d8u; return 0; }
r[8]&=r[7];
goto P_0c0559da;
P_0c0559da: /* original 2429, guest PC 0x0c0559da */
if(!s->budget--) { s->failed_pc=0x0c0559dau; return 0; }
r[4]&=r[2];
goto P_0c0559dc;
P_0c0559dc: /* original 2529, guest PC 0x0c0559dc */
if(!s->budget--) { s->failed_pc=0x0c0559dcu; return 0; }
r[5]&=r[2];
goto P_0c0559de;
P_0c0559de: /* original 2629, guest PC 0x0c0559de */
if(!s->budget--) { s->failed_pc=0x0c0559deu; return 0; }
r[6]&=r[2];
goto P_0c0559e0;
P_0c0559e0: /* original 243b, guest PC 0x0c0559e0 */
if(!s->budget--) { s->failed_pc=0x0c0559e0u; return 0; }
r[4]|=r[3];
goto P_0c0559e2;
P_0c0559e2: /* original 250b, guest PC 0x0c0559e2 */
if(!s->budget--) { s->failed_pc=0x0c0559e2u; return 0; }
r[5]|=r[0];
goto P_0c0559e4;
P_0c0559e4: /* original 268b, guest PC 0x0c0559e4 */
if(!s->budget--) { s->failed_pc=0x0c0559e4u; return 0; }
r[6]|=r[8];
goto P_0c0559e6;
P_0c0559e6: /* original 1140, guest PC 0x0c0559e6 */
if(!s->budget--) { s->failed_pc=0x0c0559e6u; return 0; }
write(ram,r[1]+0,r[4],4);
goto P_0c0559e8;
P_0c0559e8: /* original 1152, guest PC 0x0c0559e8 */
if(!s->budget--) { s->failed_pc=0x0c0559e8u; return 0; }
write(ram,r[1]+8,r[5],4);
goto P_0c0559ea;
P_0c0559ea: /* original 1164, guest PC 0x0c0559ea */
if(!s->budget--) { s->failed_pc=0x0c0559eau; return 0; }
write(ram,r[1]+16,r[6],4);
goto P_0c0559ec;
P_0c0559ec: /* original d10a, guest PC 0x0c0559ec */
if(!s->budget--) { s->failed_pc=0x0c0559ecu; return 0; }
r[1]=read(ram,0x0c055a18u,4);
goto P_0c0559ee;
P_0c0559ee: /* original e07f, guest PC 0x0c0559ee */
if(!s->budget--) { s->failed_pc=0x0c0559eeu; return 0; }
r[0]=0x0000007fu;
goto P_0c0559f0;
P_0c0559f0: /* original 4f26, guest PC 0x0c0559f0 */
if(!s->budget--) { s->failed_pc=0x0c0559f0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0559f2;
P_0c0559f2: /* original 4028, guest PC 0x0c0559f2 */
if(!s->budget--) { s->failed_pc=0x0c0559f2u; return 0; }
r[0]<<=16;
goto P_0c0559f4;
P_0c0559f4: /* original 68f6, guest PC 0x0c0559f4 */
if(!s->budget--) { s->failed_pc=0x0c0559f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0559f6;
P_0c0559f6: /* original 4018, guest PC 0x0c0559f6 */
if(!s->budget--) { s->failed_pc=0x0c0559f6u; return 0; }
r[0]<<=8;
goto P_0c0559f8;
P_0c0559f8: /* original 69f6, guest PC 0x0c0559f8 */
if(!s->budget--) { s->failed_pc=0x0c0559f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0559fa;
P_0c0559fa: /* original 4001, guest PC 0x0c0559fa */
if(!s->budget--) { s->failed_pc=0x0c0559fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c0559fc;
P_0c0559fc: /* original 6af6, guest PC 0x0c0559fc */
if(!s->budget--) { s->failed_pc=0x0c0559fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0559fe;
P_0c0559fe: /* original 2102, guest PC 0x0c0559fe */
if(!s->budget--) { s->failed_pc=0x0c0559feu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c055a00;
P_0c055a00: /* original 6bf6, guest PC 0x0c055a00 */
if(!s->budget--) { s->failed_pc=0x0c055a00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c055a02;
P_0c055a02: /* original 6cf6, guest PC 0x0c055a02 */
if(!s->budget--) { s->failed_pc=0x0c055a02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c055a04;
P_0c055a04: /* original 6df6, guest PC 0x0c055a04 */
if(!s->budget--) { s->failed_pc=0x0c055a04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c055a06;
P_0c055a06: /* original 6ef6, guest PC 0x0c055a06 */
if(!s->budget--) { s->failed_pc=0x0c055a06u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c055a08;
P_0c055a08: /* original fcf9, guest PC 0x0c055a08 */
if(!s->budget--) { s->failed_pc=0x0c055a08u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c055a0a;
P_0c055a0a: /* original fdf9, guest PC 0x0c055a0a */
if(!s->budget--) { s->failed_pc=0x0c055a0au; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c055a0c;
P_0c055a0c: /* original fef9, guest PC 0x0c055a0c */
if(!s->budget--) { s->failed_pc=0x0c055a0cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c055a0e;
P_0c055a0e: /* original 000b, guest PC 0x0c055a0e */
if(!s->budget--) { s->failed_pc=0x0c055a0eu; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c055a10: /* original fff9, guest PC 0x0c055a10 */
if(!s->budget--) { s->failed_pc=0x0c055a10u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
return vf3_matrix_family(0x0c055a12u,s,ram);
P_0c056340: /* original f10b, guest PC 0x0c056340 */
if(!s->budget--) { s->failed_pc=0x0c056340u; return 0; }
r[1]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[1]);
goto P_0c056342;
P_0c056342: /* original f02d, guest PC 0x0c056342 */
if(!s->budget--) { s->failed_pc=0x0c056342u; return 0; }
fr[0]=vf3_fpu_float(r[53],r[18]);
goto P_0c056344;
P_0c056344: /* original 711c, guest PC 0x0c056344 */
if(!s->budget--) { s->failed_pc=0x0c056344u; return 0; }
r[1]+=0x0000001cu;
goto P_0c056346;
P_0c056346: /* original f162, guest PC 0x0c056346 */
if(!s->budget--) { s->failed_pc=0x0c056346u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[6],r[18],'*');
goto P_0c056348;
P_0c056348: /* original f252, guest PC 0x0c056348 */
if(!s->budget--) { s->failed_pc=0x0c056348u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'*');
goto P_0c05634a;
P_0c05634a: /* original f042, guest PC 0x0c05634a */
if(!s->budget--) { s->failed_pc=0x0c05634au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c05634c;
P_0c05634c: /* original f11a, guest PC 0x0c05634c */
if(!s->budget--) { s->failed_pc=0x0c05634cu; return 0; }
vf3_matrix_store(s,ram,1,r[1]);
goto P_0c05634e;
P_0c05634e: /* original f12b, guest PC 0x0c05634e */
if(!s->budget--) { s->failed_pc=0x0c05634eu; return 0; }
r[1]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[1]);
goto P_0c056350;
P_0c056350: /* original 000b, guest PC 0x0c056350 */
if(!s->budget--) { s->failed_pc=0x0c056350u; return 0; }
target=r[16];
r[1]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[1]);
s->pc=target; return ram->oob==0;
P_0c056352: /* original f10b, guest PC 0x0c056352 */
if(!s->budget--) { s->failed_pc=0x0c056352u; return 0; }
r[1]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[1]);
return vf3_matrix_family(0x0c056354u,s,ram);
P_0c0696c6: /* original 4f22, guest PC 0x0c0696c6 */
if(!s->budget--) { s->failed_pc=0x0c0696c6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0696c8;
P_0c0696c8: /* original 7ff8, guest PC 0x0c0696c8 */
if(!s->budget--) { s->failed_pc=0x0c0696c8u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0696ca;
P_0c0696ca: /* original 1f41, guest PC 0x0c0696ca */
if(!s->budget--) { s->failed_pc=0x0c0696cau; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0696cc;
P_0c0696cc: /* original 2f52, guest PC 0x0c0696cc */
if(!s->budget--) { s->failed_pc=0x0c0696ccu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0696ce;
P_0c0696ce: /* original d33c, guest PC 0x0c0696ce */
if(!s->budget--) { s->failed_pc=0x0c0696ceu; return 0; }
r[3]=read(ram,0x0c0697c0u,4);
goto P_0c0696d0;
P_0c0696d0: /* original 430b, guest PC 0x0c0696d0 */
if(!s->budget--) { s->failed_pc=0x0c0696d0u; return 0; }
target=r[3];
r[16]=0x0c0696d4u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0696d4u) { target=s->pc; goto dispatch; }
goto P_0c0696d4;
P_0c0696d2: /* original 54f1, guest PC 0x0c0696d2 */
if(!s->budget--) { s->failed_pc=0x0c0696d2u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0696d4;
P_0c0696d4: /* original 62f2, guest PC 0x0c0696d4 */
if(!s->budget--) { s->failed_pc=0x0c0696d4u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0696d6;
P_0c0696d6: /* original 302c, guest PC 0x0c0696d6 */
if(!s->budget--) { s->failed_pc=0x0c0696d6u; return 0; }
r[0]+=r[2];
goto P_0c0696d8;
P_0c0696d8: /* original 2f02, guest PC 0x0c0696d8 */
if(!s->budget--) { s->failed_pc=0x0c0696d8u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0696da;
P_0c0696da: /* original 6503, guest PC 0x0c0696da */
if(!s->budget--) { s->failed_pc=0x0c0696dau; return 0; }
r[5]=r[0];
goto P_0c0696dc;
P_0c0696dc: /* original 54f1, guest PC 0x0c0696dc */
if(!s->budget--) { s->failed_pc=0x0c0696dcu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0696de;
P_0c0696de: /* original 7f08, guest PC 0x0c0696de */
if(!s->budget--) { s->failed_pc=0x0c0696deu; return 0; }
r[15]+=0x00000008u;
goto P_0c0696e0;
P_0c0696e0: /* original d338, guest PC 0x0c0696e0 */
if(!s->budget--) { s->failed_pc=0x0c0696e0u; return 0; }
r[3]=read(ram,0x0c0697c4u,4);
goto P_0c0696e2;
P_0c0696e2: /* original 432b, guest PC 0x0c0696e2 */
if(!s->budget--) { s->failed_pc=0x0c0696e2u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0696e4: /* original 4f26, guest PC 0x0c0696e4 */
if(!s->budget--) { s->failed_pc=0x0c0696e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0696e6u,s,ram);
P_0c06bea4: /* original 2fe6, guest PC 0x0c06bea4 */
if(!s->budget--) { s->failed_pc=0x0c06bea4u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c06bea6;
P_0c06bea6: /* original e20f, guest PC 0x0c06bea6 */
if(!s->budget--) { s->failed_pc=0x0c06bea6u; return 0; }
r[2]=0x0000000fu;
goto P_0c06bea8;
P_0c06bea8: /* original 2fd6, guest PC 0x0c06bea8 */
if(!s->budget--) { s->failed_pc=0x0c06bea8u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c06beaa;
P_0c06beaa: /* original 2fc6, guest PC 0x0c06beaa */
if(!s->budget--) { s->failed_pc=0x0c06beaau; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c06beac;
P_0c06beac: /* original 6742, guest PC 0x0c06beac */
if(!s->budget--) { s->failed_pc=0x0c06beacu; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c06beae;
P_0c06beae: /* original d343, guest PC 0x0c06beae */
if(!s->budget--) { s->failed_pc=0x0c06beaeu; return 0; }
r[3]=read(ram,0x0c06bfbcu,4);
goto P_0c06beb0;
P_0c06beb0: /* original 2729, guest PC 0x0c06beb0 */
if(!s->budget--) { s->failed_pc=0x0c06beb0u; return 0; }
r[7]&=r[2];
goto P_0c06beb2;
P_0c06beb2: /* original 6d52, guest PC 0x0c06beb2 */
if(!s->budget--) { s->failed_pc=0x0c06beb2u; return 0; }
tmp=read(ram,r[5],4);
r[13]=tmp;
goto P_0c06beb4;
P_0c06beb4: /* original 6e30, guest PC 0x0c06beb4 */
if(!s->budget--) { s->failed_pc=0x0c06beb4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[14]=tmp;
goto P_0c06beb6;
P_0c06beb6: /* original 2778, guest PC 0x0c06beb6 */
if(!s->budget--) { s->failed_pc=0x0c06beb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c06beb8;
P_0c06beb8: /* original 6c73, guest PC 0x0c06beb8 */
if(!s->budget--) { s->failed_pc=0x0c06beb8u; return 0; }
r[12]=r[7];
goto P_0c06beba;
P_0c06beba: /* original 8f05, guest PC 0x0c06beba */
if(!s->budget--) { s->failed_pc=0x0c06bebau; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c06bec8; }
goto P_0c06bebe;
P_0c06bebc: /* original 7c01, guest PC 0x0c06bebc */
if(!s->budget--) { s->failed_pc=0x0c06bebcu; return 0; }
r[12]+=0x00000001u;
goto P_0c06bebe;
P_0c06bebe: /* original 2dd8, guest PC 0x0c06bebe */
if(!s->budget--) { s->failed_pc=0x0c06bebeu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c06bec0;
P_0c06bec0: /* original 8918, guest PC 0x0c06bec0 */
if(!s->budget--) { s->failed_pc=0x0c06bec0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06bef4; }
goto P_0c06bec2;
P_0c06bec2: /* original 7dff, guest PC 0x0c06bec2 */
if(!s->budget--) { s->failed_pc=0x0c06bec2u; return 0; }
r[13]+=0xffffffffu;
goto P_0c06bec4;
P_0c06bec4: /* original a016, guest PC 0x0c06bec4 */
if(!s->budget--) { s->failed_pc=0x0c06bec4u; return 0; }
r[7]=r[12];
goto P_0c06bef4;
P_0c06bec6: /* original 67c3, guest PC 0x0c06bec6 */
if(!s->budget--) { s->failed_pc=0x0c06bec6u; return 0; }
r[7]=r[12];
goto P_0c06bec8;
P_0c06bec8: /* original d03d, guest PC 0x0c06bec8 */
if(!s->budget--) { s->failed_pc=0x0c06bec8u; return 0; }
r[0]=read(ram,0x0c06bfc0u,4);
goto P_0c06beca;
P_0c06beca: /* original 2668, guest PC 0x0c06beca */
if(!s->budget--) { s->failed_pc=0x0c06becau; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06becc;
P_0c06becc: /* original 027c, guest PC 0x0c06becc */
if(!s->budget--) { s->failed_pc=0x0c06beccu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c06bece;
P_0c06bece: /* original 8f06, guest PC 0x0c06bece */
if(!s->budget--) { s->failed_pc=0x0c06beceu; return 0; }
cond=r[17]&1u;
r[7]=r[2]&255u;
if(!cond) { goto P_0c06bede; }
goto P_0c06bed2;
P_0c06bed0: /* original 672c, guest PC 0x0c06bed0 */
if(!s->budget--) { s->failed_pc=0x0c06bed0u; return 0; }
r[7]=r[2]&255u;
goto P_0c06bed2;
P_0c06bed2: /* original 926b, guest PC 0x0c06bed2 */
if(!s->budget--) { s->failed_pc=0x0c06bed2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bfacu,2);
goto P_0c06bed4;
P_0c06bed4: /* original 2778, guest PC 0x0c06bed4 */
if(!s->budget--) { s->failed_pc=0x0c06bed4u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c06bed6;
P_0c06bed6: /* original 8d08, guest PC 0x0c06bed6 */
if(!s->budget--) { s->failed_pc=0x0c06bed6u; return 0; }
cond=r[17]&1u;
r[14]&=r[2];
if(cond) { goto P_0c06beea; }
goto P_0c06beda;
P_0c06bed8: /* original 2e29, guest PC 0x0c06bed8 */
if(!s->budget--) { s->failed_pc=0x0c06bed8u; return 0; }
r[14]&=r[2];
goto P_0c06beda;
P_0c06beda: /* original a005, guest PC 0x0c06beda */
if(!s->budget--) { s->failed_pc=0x0c06bedau; return 0; }
r[3]=0x00000001u;
goto P_0c06bee8;
P_0c06bedc: /* original e301, guest PC 0x0c06bedc */
if(!s->budget--) { s->failed_pc=0x0c06bedcu; return 0; }
r[3]=0x00000001u;
goto P_0c06bede;
P_0c06bede: /* original 9166, guest PC 0x0c06bede */
if(!s->budget--) { s->failed_pc=0x0c06bedeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bfaeu,2);
goto P_0c06bee0;
P_0c06bee0: /* original 2778, guest PC 0x0c06bee0 */
if(!s->budget--) { s->failed_pc=0x0c06bee0u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c06bee2;
P_0c06bee2: /* original 8d02, guest PC 0x0c06bee2 */
if(!s->budget--) { s->failed_pc=0x0c06bee2u; return 0; }
cond=r[17]&1u;
r[14]&=r[1];
if(cond) { goto P_0c06beea; }
goto P_0c06bee6;
P_0c06bee4: /* original 2e19, guest PC 0x0c06bee4 */
if(!s->budget--) { s->failed_pc=0x0c06bee4u; return 0; }
r[14]&=r[1];
goto P_0c06bee6;
P_0c06bee6: /* original e302, guest PC 0x0c06bee6 */
if(!s->budget--) { s->failed_pc=0x0c06bee6u; return 0; }
r[3]=0x00000002u;
goto P_0c06bee8;
P_0c06bee8: /* original 2e3b, guest PC 0x0c06bee8 */
if(!s->budget--) { s->failed_pc=0x0c06bee8u; return 0; }
r[14]|=r[3];
goto P_0c06beea;
P_0c06beea: /* original d234, guest PC 0x0c06beea */
if(!s->budget--) { s->failed_pc=0x0c06beeau; return 0; }
r[2]=read(ram,0x0c06bfbcu,4);
goto P_0c06beec;
P_0c06beec: /* original e30f, guest PC 0x0c06beec */
if(!s->budget--) { s->failed_pc=0x0c06beecu; return 0; }
r[3]=0x0000000fu;
goto P_0c06beee;
P_0c06beee: /* original 67c3, guest PC 0x0c06beee */
if(!s->budget--) { s->failed_pc=0x0c06beeeu; return 0; }
r[7]=r[12];
goto P_0c06bef0;
P_0c06bef0: /* original 2739, guest PC 0x0c06bef0 */
if(!s->budget--) { s->failed_pc=0x0c06bef0u; return 0; }
r[7]&=r[3];
goto P_0c06bef2;
P_0c06bef2: /* original 22e0, guest PC 0x0c06bef2 */
if(!s->budget--) { s->failed_pc=0x0c06bef2u; return 0; }
write(ram,r[2],r[14],1);
goto P_0c06bef4;
P_0c06bef4: /* original 2472, guest PC 0x0c06bef4 */
if(!s->budget--) { s->failed_pc=0x0c06bef4u; return 0; }
write(ram,r[4],r[7],4);
goto P_0c06bef6;
P_0c06bef6: /* original 25d2, guest PC 0x0c06bef6 */
if(!s->budget--) { s->failed_pc=0x0c06bef6u; return 0; }
write(ram,r[5],r[13],4);
goto P_0c06bef8;
P_0c06bef8: /* original 6cf6, guest PC 0x0c06bef8 */
if(!s->budget--) { s->failed_pc=0x0c06bef8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06befa;
P_0c06befa: /* original 6df6, guest PC 0x0c06befa */
if(!s->budget--) { s->failed_pc=0x0c06befau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06befc;
P_0c06befc: /* original 000b, guest PC 0x0c06befc */
if(!s->budget--) { s->failed_pc=0x0c06befcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06befe: /* original 6ef6, guest PC 0x0c06befe */
if(!s->budget--) { s->failed_pc=0x0c06befeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06bf00u,s,ram);
P_0c06bf08: /* original 4f22, guest PC 0x0c06bf08 */
if(!s->budget--) { s->failed_pc=0x0c06bf08u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06bf0a;
P_0c06bf0a: /* original 03ec, guest PC 0x0c06bf0a */
if(!s->budget--) { s->failed_pc=0x0c06bf0au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bf0c;
P_0c06bf0c: /* original 7ff8, guest PC 0x0c06bf0c */
if(!s->budget--) { s->failed_pc=0x0c06bf0cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06bf0e;
P_0c06bf0e: /* original 65f3, guest PC 0x0c06bf0e */
if(!s->budget--) { s->failed_pc=0x0c06bf0eu; return 0; }
r[5]=r[15];
goto P_0c06bf10;
P_0c06bf10: /* original 64f3, guest PC 0x0c06bf10 */
if(!s->budget--) { s->failed_pc=0x0c06bf10u; return 0; }
r[4]=r[15];
goto P_0c06bf12;
P_0c06bf12: /* original 1f31, guest PC 0x0c06bf12 */
if(!s->budget--) { s->failed_pc=0x0c06bf12u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c06bf14;
P_0c06bf14: /* original 904d, guest PC 0x0c06bf14 */
if(!s->budget--) { s->failed_pc=0x0c06bf14u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bfb2u,2);
goto P_0c06bf16;
P_0c06bf16: /* original 02ec, guest PC 0x0c06bf16 */
if(!s->budget--) { s->failed_pc=0x0c06bf16u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bf18;
P_0c06bf18: /* original 2f22, guest PC 0x0c06bf18 */
if(!s->budget--) { s->failed_pc=0x0c06bf18u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c06bf1a;
P_0c06bf1a: /* original bfc3, guest PC 0x0c06bf1a */
if(!s->budget--) { s->failed_pc=0x0c06bf1au; return 0; }
target=0x0c06bea4u; r[16]=0x0c06bf1eu;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06bf1eu) { target=s->pc; goto dispatch; }
goto P_0c06bf1e;
P_0c06bf1c: /* original 7404, guest PC 0x0c06bf1c */
if(!s->budget--) { s->failed_pc=0x0c06bf1cu; return 0; }
r[4]+=0x00000004u;
goto P_0c06bf1e;
P_0c06bf1e: /* original 9047, guest PC 0x0c06bf1e */
if(!s->budget--) { s->failed_pc=0x0c06bf1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bfb0u,2);
goto P_0c06bf20;
P_0c06bf20: /* original 65f3, guest PC 0x0c06bf20 */
if(!s->budget--) { s->failed_pc=0x0c06bf20u; return 0; }
r[5]=r[15];
goto P_0c06bf22;
P_0c06bf22: /* original 52f1, guest PC 0x0c06bf22 */
if(!s->budget--) { s->failed_pc=0x0c06bf22u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c06bf24;
P_0c06bf24: /* original 64f3, guest PC 0x0c06bf24 */
if(!s->budget--) { s->failed_pc=0x0c06bf24u; return 0; }
r[4]=r[15];
goto P_0c06bf26;
P_0c06bf26: /* original e601, guest PC 0x0c06bf26 */
if(!s->budget--) { s->failed_pc=0x0c06bf26u; return 0; }
r[6]=0x00000001u;
goto P_0c06bf28;
P_0c06bf28: /* original 0e24, guest PC 0x0c06bf28 */
if(!s->budget--) { s->failed_pc=0x0c06bf28u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c06bf2a;
P_0c06bf2a: /* original 9042, guest PC 0x0c06bf2a */
if(!s->budget--) { s->failed_pc=0x0c06bf2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bfb2u,2);
goto P_0c06bf2c;
P_0c06bf2c: /* original 63f2, guest PC 0x0c06bf2c */
if(!s->budget--) { s->failed_pc=0x0c06bf2cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06bf2e;
P_0c06bf2e: /* original 0e34, guest PC 0x0c06bf2e */
if(!s->budget--) { s->failed_pc=0x0c06bf2eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06bf30;
P_0c06bf30: /* original 7008, guest PC 0x0c06bf30 */
if(!s->budget--) { s->failed_pc=0x0c06bf30u; return 0; }
r[0]+=0x00000008u;
goto P_0c06bf32;
P_0c06bf32: /* original 02ec, guest PC 0x0c06bf32 */
if(!s->budget--) { s->failed_pc=0x0c06bf32u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bf34;
P_0c06bf34: /* original 1f21, guest PC 0x0c06bf34 */
if(!s->budget--) { s->failed_pc=0x0c06bf34u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c06bf36;
P_0c06bf36: /* original 903d, guest PC 0x0c06bf36 */
if(!s->budget--) { s->failed_pc=0x0c06bf36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bfb4u,2);
goto P_0c06bf38;
P_0c06bf38: /* original 03ec, guest PC 0x0c06bf38 */
if(!s->budget--) { s->failed_pc=0x0c06bf38u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c06bf3a;
P_0c06bf3a: /* original 2f32, guest PC 0x0c06bf3a */
if(!s->budget--) { s->failed_pc=0x0c06bf3au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06bf3c;
P_0c06bf3c: /* original bfb2, guest PC 0x0c06bf3c */
if(!s->budget--) { s->failed_pc=0x0c06bf3cu; return 0; }
target=0x0c06bea4u; r[16]=0x0c06bf40u;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06bf40u) { target=s->pc; goto dispatch; }
goto P_0c06bf40;
P_0c06bf3e: /* original 7404, guest PC 0x0c06bf3e */
if(!s->budget--) { s->failed_pc=0x0c06bf3eu; return 0; }
r[4]+=0x00000004u;
goto P_0c06bf40;
P_0c06bf40: /* original 9039, guest PC 0x0c06bf40 */
if(!s->budget--) { s->failed_pc=0x0c06bf40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bfb6u,2);
goto P_0c06bf42;
P_0c06bf42: /* original 52f1, guest PC 0x0c06bf42 */
if(!s->budget--) { s->failed_pc=0x0c06bf42u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c06bf44;
P_0c06bf44: /* original 0e24, guest PC 0x0c06bf44 */
if(!s->budget--) { s->failed_pc=0x0c06bf44u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c06bf46;
P_0c06bf46: /* original 63f2, guest PC 0x0c06bf46 */
if(!s->budget--) { s->failed_pc=0x0c06bf46u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06bf48;
P_0c06bf48: /* original 7f08, guest PC 0x0c06bf48 */
if(!s->budget--) { s->failed_pc=0x0c06bf48u; return 0; }
r[15]+=0x00000008u;
goto P_0c06bf4a;
P_0c06bf4a: /* original 4f26, guest PC 0x0c06bf4a */
if(!s->budget--) { s->failed_pc=0x0c06bf4au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06bf4c;
P_0c06bf4c: /* original 9032, guest PC 0x0c06bf4c */
if(!s->budget--) { s->failed_pc=0x0c06bf4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06bfb4u,2);
goto P_0c06bf4e;
P_0c06bf4e: /* original 0e34, guest PC 0x0c06bf4e */
if(!s->budget--) { s->failed_pc=0x0c06bf4eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06bf50;
P_0c06bf50: /* original 000b, guest PC 0x0c06bf50 */
if(!s->budget--) { s->failed_pc=0x0c06bf50u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06bf52: /* original 6ef6, guest PC 0x0c06bf52 */
if(!s->budget--) { s->failed_pc=0x0c06bf52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06bf54u,s,ram);
P_0c06c3d4: /* original 4f22, guest PC 0x0c06c3d4 */
if(!s->budget--) { s->failed_pc=0x0c06c3d4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c3d6;
P_0c06c3d6: /* original 6032, guest PC 0x0c06c3d6 */
if(!s->budget--) { s->failed_pc=0x0c06c3d6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c06c3d8;
P_0c06c3d8: /* original c91f, guest PC 0x0c06c3d8 */
if(!s->budget--) { s->failed_pc=0x0c06c3d8u; return 0; }
r[0]&=31u;
goto P_0c06c3da;
P_0c06c3da: /* original 7ff8, guest PC 0x0c06c3da */
if(!s->budget--) { s->failed_pc=0x0c06c3dau; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06c3dc;
P_0c06c3dc: /* original 3022, guest PC 0x0c06c3dc */
if(!s->budget--) { s->failed_pc=0x0c06c3dcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>=r[2])!=0);
goto P_0c06c3de;
P_0c06c3de: /* original 2f02, guest PC 0x0c06c3de */
if(!s->budget--) { s->failed_pc=0x0c06c3deu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06c3e0;
P_0c06c3e0: /* original 890d, guest PC 0x0c06c3e0 */
if(!s->budget--) { s->failed_pc=0x0c06c3e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c3fe; }
goto P_0c06c3e2;
P_0c06c3e2: /* original e307, guest PC 0x0c06c3e2 */
if(!s->budget--) { s->failed_pc=0x0c06c3e2u; return 0; }
r[3]=0x00000007u;
goto P_0c06c3e4;
P_0c06c3e4: /* original 453d, guest PC 0x0c06c3e4 */
if(!s->budget--) { s->failed_pc=0x0c06c3e4u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c06c3e6;
P_0c06c3e6: /* original 4400, guest PC 0x0c06c3e6 */
if(!s->budget--) { s->failed_pc=0x0c06c3e6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c3e8;
P_0c06c3e8: /* original 245b, guest PC 0x0c06c3e8 */
if(!s->budget--) { s->failed_pc=0x0c06c3e8u; return 0; }
r[4]|=r[5];
goto P_0c06c3ea;
P_0c06c3ea: /* original e120, guest PC 0x0c06c3ea */
if(!s->budget--) { s->failed_pc=0x0c06c3eau; return 0; }
r[1]=0x00000020u;
goto P_0c06c3ec;
P_0c06c3ec: /* original 2f42, guest PC 0x0c06c3ec */
if(!s->budget--) { s->failed_pc=0x0c06c3ecu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06c3ee;
P_0c06c3ee: /* original d223, guest PC 0x0c06c3ee */
if(!s->budget--) { s->failed_pc=0x0c06c3eeu; return 0; }
r[2]=read(ram,0x0c06c47cu,4);
goto P_0c06c3f0;
P_0c06c3f0: /* original 1f21, guest PC 0x0c06c3f0 */
if(!s->budget--) { s->failed_pc=0x0c06c3f0u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c06c3f2;
P_0c06c3f2: /* original 2f16, guest PC 0x0c06c3f2 */
if(!s->budget--) { s->failed_pc=0x0c06c3f2u; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c06c3f4;
P_0c06c3f4: /* original d223, guest PC 0x0c06c3f4 */
if(!s->budget--) { s->failed_pc=0x0c06c3f4u; return 0; }
r[2]=read(ram,0x0c06c484u,4);
goto P_0c06c3f6;
P_0c06c3f6: /* original 55f1, guest PC 0x0c06c3f6 */
if(!s->budget--) { s->failed_pc=0x0c06c3f6u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c06c3f8;
P_0c06c3f8: /* original 420b, guest PC 0x0c06c3f8 */
if(!s->budget--) { s->failed_pc=0x0c06c3f8u; return 0; }
target=r[2];
r[16]=0x0c06c3fcu;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06c3fcu) { target=s->pc; goto dispatch; }
goto P_0c06c3fc;
P_0c06c3fa: /* original 54f2, guest PC 0x0c06c3fa */
if(!s->budget--) { s->failed_pc=0x0c06c3fau; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c06c3fc;
P_0c06c3fc: /* original 7f04, guest PC 0x0c06c3fc */
if(!s->budget--) { s->failed_pc=0x0c06c3fcu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c3fe;
P_0c06c3fe: /* original 7f08, guest PC 0x0c06c3fe */
if(!s->budget--) { s->failed_pc=0x0c06c3feu; return 0; }
r[15]+=0x00000008u;
goto P_0c06c400;
P_0c06c400: /* original 4f26, guest PC 0x0c06c400 */
if(!s->budget--) { s->failed_pc=0x0c06c400u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c402;
P_0c06c402: /* original 000b, guest PC 0x0c06c402 */
if(!s->budget--) { s->failed_pc=0x0c06c402u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06c404: /* original 0009, guest PC 0x0c06c404 */
if(!s->budget--) { s->failed_pc=0x0c06c404u; return 0; }
return vf3_matrix_family(0x0c06c406u,s,ram);
P_0c06c42a: /* original 4f22, guest PC 0x0c06c42a */
if(!s->budget--) { s->failed_pc=0x0c06c42au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c42c;
P_0c06c42c: /* original d313, guest PC 0x0c06c42c */
if(!s->budget--) { s->failed_pc=0x0c06c42cu; return 0; }
r[3]=read(ram,0x0c06c47cu,4);
goto P_0c06c42e;
P_0c06c42e: /* original 6e63, guest PC 0x0c06c42e */
if(!s->budget--) { s->failed_pc=0x0c06c42eu; return 0; }
r[14]=r[6];
goto P_0c06c430;
P_0c06c430: /* original 7ffc, guest PC 0x0c06c430 */
if(!s->budget--) { s->failed_pc=0x0c06c430u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c432;
P_0c06c432: /* original 2f32, guest PC 0x0c06c432 */
if(!s->budget--) { s->failed_pc=0x0c06c432u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06c434;
P_0c06c434: /* original e307, guest PC 0x0c06c434 */
if(!s->budget--) { s->failed_pc=0x0c06c434u; return 0; }
r[3]=0x00000007u;
goto P_0c06c436;
P_0c06c436: /* original d217, guest PC 0x0c06c436 */
if(!s->budget--) { s->failed_pc=0x0c06c436u; return 0; }
r[2]=read(ram,0x0c06c494u,4);
goto P_0c06c438;
P_0c06c438: /* original 453d, guest PC 0x0c06c438 */
if(!s->budget--) { s->failed_pc=0x0c06c438u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c06c43a;
P_0c06c43a: /* original 2d5b, guest PC 0x0c06c43a */
if(!s->budget--) { s->failed_pc=0x0c06c43au; return 0; }
r[13]|=r[5];
goto P_0c06c43c;
P_0c06c43c: /* original 6020, guest PC 0x0c06c43c */
if(!s->budget--) { s->failed_pc=0x0c06c43cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c06c43e;
P_0c06c43e: /* original 8801, guest PC 0x0c06c43e */
if(!s->budget--) { s->failed_pc=0x0c06c43eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c440;
P_0c06c440: /* original 8d0d, guest PC 0x0c06c440 */
if(!s->budget--) { s->failed_pc=0x0c06c440u; return 0; }
cond=r[17]&1u;
r[6]=r[0];
if(cond) { goto P_0c06c45e; }
goto P_0c06c444;
P_0c06c442: /* original 6603, guest PC 0x0c06c442 */
if(!s->budget--) { s->failed_pc=0x0c06c442u; return 0; }
r[6]=r[0];
goto P_0c06c444;
P_0c06c444: /* original 36e0, guest PC 0x0c06c444 */
if(!s->budget--) { s->failed_pc=0x0c06c444u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[14])!=0);
goto P_0c06c446;
P_0c06c446: /* original 890a, guest PC 0x0c06c446 */
if(!s->budget--) { s->failed_pc=0x0c06c446u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c45e; }
goto P_0c06c448;
P_0c06c448: /* original 2ee8, guest PC 0x0c06c448 */
if(!s->budget--) { s->failed_pc=0x0c06c448u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c06c44a;
P_0c06c44a: /* original 8908, guest PC 0x0c06c44a */
if(!s->budget--) { s->failed_pc=0x0c06c44au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c45e; }
goto P_0c06c44c;
P_0c06c44c: /* original 2f66, guest PC 0x0c06c44c */
if(!s->budget--) { s->failed_pc=0x0c06c44cu; return 0; }
r[15]-=4; write(ram,r[15],r[6],4);
goto P_0c06c44e;
P_0c06c44e: /* original 2fe6, guest PC 0x0c06c44e */
if(!s->budget--) { s->failed_pc=0x0c06c44eu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c06c450;
P_0c06c450: /* original d311, guest PC 0x0c06c450 */
if(!s->budget--) { s->failed_pc=0x0c06c450u; return 0; }
r[3]=read(ram,0x0c06c498u,4);
goto P_0c06c452;
P_0c06c452: /* original 2f36, guest PC 0x0c06c452 */
if(!s->budget--) { s->failed_pc=0x0c06c452u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c06c454;
P_0c06c454: /* original d20e, guest PC 0x0c06c454 */
if(!s->budget--) { s->failed_pc=0x0c06c454u; return 0; }
r[2]=read(ram,0x0c06c490u,4);
goto P_0c06c456;
P_0c06c456: /* original 420b, guest PC 0x0c06c456 */
if(!s->budget--) { s->failed_pc=0x0c06c456u; return 0; }
target=r[2];
r[16]=0x0c06c45au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06c45au) { target=s->pc; goto dispatch; }
goto P_0c06c45a;
P_0c06c458: /* original 64d3, guest PC 0x0c06c458 */
if(!s->budget--) { s->failed_pc=0x0c06c458u; return 0; }
r[4]=r[13];
goto P_0c06c45a;
P_0c06c45a: /* original a009, guest PC 0x0c06c45a */
if(!s->budget--) { s->failed_pc=0x0c06c45au; return 0; }
r[15]+=0x0000000cu;
goto P_0c06c470;
P_0c06c45c: /* original 7f0c, guest PC 0x0c06c45c */
if(!s->budget--) { s->failed_pc=0x0c06c45cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c06c45e;
P_0c06c45e: /* original e320, guest PC 0x0c06c45e */
if(!s->budget--) { s->failed_pc=0x0c06c45eu; return 0; }
r[3]=0x00000020u;
goto P_0c06c460;
P_0c06c460: /* original 65d3, guest PC 0x0c06c460 */
if(!s->budget--) { s->failed_pc=0x0c06c460u; return 0; }
r[5]=r[13];
goto P_0c06c462;
P_0c06c462: /* original e608, guest PC 0x0c06c462 */
if(!s->budget--) { s->failed_pc=0x0c06c462u; return 0; }
r[6]=0x00000008u;
goto P_0c06c464;
P_0c06c464: /* original 2f36, guest PC 0x0c06c464 */
if(!s->budget--) { s->failed_pc=0x0c06c464u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c06c466;
P_0c06c466: /* original d207, guest PC 0x0c06c466 */
if(!s->budget--) { s->failed_pc=0x0c06c466u; return 0; }
r[2]=read(ram,0x0c06c484u,4);
goto P_0c06c468;
P_0c06c468: /* original e701, guest PC 0x0c06c468 */
if(!s->budget--) { s->failed_pc=0x0c06c468u; return 0; }
r[7]=0x00000001u;
goto P_0c06c46a;
P_0c06c46a: /* original 420b, guest PC 0x0c06c46a */
if(!s->budget--) { s->failed_pc=0x0c06c46au; return 0; }
target=r[2];
r[16]=0x0c06c46eu;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06c46eu) { target=s->pc; goto dispatch; }
goto P_0c06c46e;
P_0c06c46c: /* original 54f1, guest PC 0x0c06c46c */
if(!s->budget--) { s->failed_pc=0x0c06c46cu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c06c46e;
P_0c06c46e: /* original 7f04, guest PC 0x0c06c46e */
if(!s->budget--) { s->failed_pc=0x0c06c46eu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c470;
P_0c06c470: /* original 7f04, guest PC 0x0c06c470 */
if(!s->budget--) { s->failed_pc=0x0c06c470u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c472;
P_0c06c472: /* original 4f26, guest PC 0x0c06c472 */
if(!s->budget--) { s->failed_pc=0x0c06c472u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c474;
P_0c06c474: /* original 6df6, guest PC 0x0c06c474 */
if(!s->budget--) { s->failed_pc=0x0c06c474u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06c476;
P_0c06c476: /* original 000b, guest PC 0x0c06c476 */
if(!s->budget--) { s->failed_pc=0x0c06c476u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c478: /* original 6ef6, guest PC 0x0c06c478 */
if(!s->budget--) { s->failed_pc=0x0c06c478u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06c47au,s,ram);
P_0c06d772: /* original 4f22, guest PC 0x0c06d772 */
if(!s->budget--) { s->failed_pc=0x0c06d772u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06d774;
P_0c06d774: /* original 6030, guest PC 0x0c06d774 */
if(!s->budget--) { s->failed_pc=0x0c06d774u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c06d776;
P_0c06d776: /* original 600c, guest PC 0x0c06d776 */
if(!s->budget--) { s->failed_pc=0x0c06d776u; return 0; }
r[0]=r[0]&255u;
goto P_0c06d778;
P_0c06d778: /* original c90f, guest PC 0x0c06d778 */
if(!s->budget--) { s->failed_pc=0x0c06d778u; return 0; }
r[0]&=15u;
goto P_0c06d77a;
P_0c06d77a: /* original 7ffc, guest PC 0x0c06d77a */
if(!s->budget--) { s->failed_pc=0x0c06d77au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06d77c;
P_0c06d77c: /* original 2f02, guest PC 0x0c06d77c */
if(!s->budget--) { s->failed_pc=0x0c06d77cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06d77e;
P_0c06d77e: /* original 4008, guest PC 0x0c06d77e */
if(!s->budget--) { s->failed_pc=0x0c06d77eu; return 0; }
r[0]<<=2;
goto P_0c06d780;
P_0c06d780: /* original d147, guest PC 0x0c06d780 */
if(!s->budget--) { s->failed_pc=0x0c06d780u; return 0; }
r[1]=read(ram,0x0c06d8a0u,4);
goto P_0c06d782;
P_0c06d782: /* original 021e, guest PC 0x0c06d782 */
if(!s->budget--) { s->failed_pc=0x0c06d782u; return 0; }
r[2]=read(ram,r[1]+r[0],4);
goto P_0c06d784;
P_0c06d784: /* original 420b, guest PC 0x0c06d784 */
if(!s->budget--) { s->failed_pc=0x0c06d784u; return 0; }
target=r[2];
r[16]=0x0c06d788u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06d788u) { target=s->pc; goto dispatch; }
goto P_0c06d788;
P_0c06d786: /* original 0009, guest PC 0x0c06d786 */
if(!s->budget--) { s->failed_pc=0x0c06d786u; return 0; }
goto P_0c06d788;
P_0c06d788: /* original 7f04, guest PC 0x0c06d788 */
if(!s->budget--) { s->failed_pc=0x0c06d788u; return 0; }
r[15]+=0x00000004u;
goto P_0c06d78a;
P_0c06d78a: /* original d446, guest PC 0x0c06d78a */
if(!s->budget--) { s->failed_pc=0x0c06d78au; return 0; }
r[4]=read(ram,0x0c06d8a4u,4);
goto P_0c06d78c;
P_0c06d78c: /* original 4f26, guest PC 0x0c06d78c */
if(!s->budget--) { s->failed_pc=0x0c06d78cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06d78e;
P_0c06d78e: /* original 000b, guest PC 0x0c06d78e */
if(!s->budget--) { s->failed_pc=0x0c06d78eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06d790: /* original 0009, guest PC 0x0c06d790 */
if(!s->budget--) { s->failed_pc=0x0c06d790u; return 0; }
return vf3_matrix_family(0x0c06d792u,s,ram);
P_0c0701fe: /* original f40b, guest PC 0x0c0701fe */
if(!s->budget--) { s->failed_pc=0x0c0701feu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070200;
P_0c070200: /* original 65f3, guest PC 0x0c070200 */
if(!s->budget--) { s->failed_pc=0x0c070200u; return 0; }
r[5]=r[15];
goto P_0c070202;
P_0c070202: /* original 64e3, guest PC 0x0c070202 */
if(!s->budget--) { s->failed_pc=0x0c070202u; return 0; }
r[4]=r[14];
goto P_0c070204;
P_0c070204: /* original 7544, guest PC 0x0c070204 */
if(!s->budget--) { s->failed_pc=0x0c070204u; return 0; }
r[5]+=0x00000044u;
goto P_0c070206;
P_0c070206: /* original f049, guest PC 0x0c070206 */
if(!s->budget--) { s->failed_pc=0x0c070206u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070208;
P_0c070208: /* original f359, guest PC 0x0c070208 */
if(!s->budget--) { s->failed_pc=0x0c070208u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07020a;
P_0c07020a: /* original f149, guest PC 0x0c07020a */
if(!s->budget--) { s->failed_pc=0x0c07020au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07020c;
P_0c07020c: /* original f459, guest PC 0x0c07020c */
if(!s->budget--) { s->failed_pc=0x0c07020cu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07020e;
P_0c07020e: /* original f249, guest PC 0x0c07020e */
if(!s->budget--) { s->failed_pc=0x0c07020eu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070210;
P_0c070210: /* original f559, guest PC 0x0c070210 */
if(!s->budget--) { s->failed_pc=0x0c070210u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070212;
P_0c070212: /* original f030, guest PC 0x0c070212 */
if(!s->budget--) { s->failed_pc=0x0c070212u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070214;
P_0c070214: /* original f250, guest PC 0x0c070214 */
if(!s->budget--) { s->failed_pc=0x0c070214u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070216;
P_0c070216: /* original f140, guest PC 0x0c070216 */
if(!s->budget--) { s->failed_pc=0x0c070216u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070218;
P_0c070218: /* original f42b, guest PC 0x0c070218 */
if(!s->budget--) { s->failed_pc=0x0c070218u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07021a;
P_0c07021a: /* original f41b, guest PC 0x0c07021a */
if(!s->budget--) { s->failed_pc=0x0c07021au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07021c;
P_0c07021c: /* original f40b, guest PC 0x0c07021c */
if(!s->budget--) { s->failed_pc=0x0c07021cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07021e;
P_0c07021e: /* original 0009, guest PC 0x0c07021e */
if(!s->budget--) { s->failed_pc=0x0c07021eu; return 0; }
goto P_0c070220;
P_0c070220: /* original d306, guest PC 0x0c070220 */
if(!s->budget--) { s->failed_pc=0x0c070220u; return 0; }
r[3]=read(ram,0x0c07023cu,4);
goto P_0c070222;
P_0c070222: /* original 432b, guest PC 0x0c070222 */
if(!s->budget--) { s->failed_pc=0x0c070222u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070224: /* original 0009, guest PC 0x0c070224 */
if(!s->budget--) { s->failed_pc=0x0c070224u; return 0; }
return vf3_matrix_family(0x0c070226u,s,ram);
P_0c070252: /* original f40b, guest PC 0x0c070252 */
if(!s->budget--) { s->failed_pc=0x0c070252u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070254;
P_0c070254: /* original 65f3, guest PC 0x0c070254 */
if(!s->budget--) { s->failed_pc=0x0c070254u; return 0; }
r[5]=r[15];
goto P_0c070256;
P_0c070256: /* original 64f3, guest PC 0x0c070256 */
if(!s->budget--) { s->failed_pc=0x0c070256u; return 0; }
r[4]=r[15];
goto P_0c070258;
P_0c070258: /* original 66f3, guest PC 0x0c070258 */
if(!s->budget--) { s->failed_pc=0x0c070258u; return 0; }
r[6]=r[15];
goto P_0c07025a;
P_0c07025a: /* original 7438, guest PC 0x0c07025a */
if(!s->budget--) { s->failed_pc=0x0c07025au; return 0; }
r[4]+=0x00000038u;
goto P_0c07025c;
P_0c07025c: /* original 7638, guest PC 0x0c07025c */
if(!s->budget--) { s->failed_pc=0x0c07025cu; return 0; }
r[6]+=0x00000038u;
goto P_0c07025e;
P_0c07025e: /* original 7544, guest PC 0x0c07025e */
if(!s->budget--) { s->failed_pc=0x0c07025eu; return 0; }
r[5]+=0x00000044u;
goto P_0c070260;
P_0c070260: /* original f059, guest PC 0x0c070260 */
if(!s->budget--) { s->failed_pc=0x0c070260u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070262;
P_0c070262: /* original f369, guest PC 0x0c070262 */
if(!s->budget--) { s->failed_pc=0x0c070262u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070264;
P_0c070264: /* original f159, guest PC 0x0c070264 */
if(!s->budget--) { s->failed_pc=0x0c070264u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070266;
P_0c070266: /* original f469, guest PC 0x0c070266 */
if(!s->budget--) { s->failed_pc=0x0c070266u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070268;
P_0c070268: /* original f031, guest PC 0x0c070268 */
if(!s->budget--) { s->failed_pc=0x0c070268u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c07026a;
P_0c07026a: /* original f258, guest PC 0x0c07026a */
if(!s->budget--) { s->failed_pc=0x0c07026au; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c07026c;
P_0c07026c: /* original f568, guest PC 0x0c07026c */
if(!s->budget--) { s->failed_pc=0x0c07026cu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c07026e;
P_0c07026e: /* original f141, guest PC 0x0c07026e */
if(!s->budget--) { s->failed_pc=0x0c07026eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070270;
P_0c070270: /* original f251, guest PC 0x0c070270 */
if(!s->budget--) { s->failed_pc=0x0c070270u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070272;
P_0c070272: /* original 7408, guest PC 0x0c070272 */
if(!s->budget--) { s->failed_pc=0x0c070272u; return 0; }
r[4]+=0x00000008u;
goto P_0c070274;
P_0c070274: /* original f42a, guest PC 0x0c070274 */
if(!s->budget--) { s->failed_pc=0x0c070274u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070276;
P_0c070276: /* original f41b, guest PC 0x0c070276 */
if(!s->budget--) { s->failed_pc=0x0c070276u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070278;
P_0c070278: /* original f40b, guest PC 0x0c070278 */
if(!s->budget--) { s->failed_pc=0x0c070278u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07027a;
P_0c07027a: /* original 0009, guest PC 0x0c07027a */
if(!s->budget--) { s->failed_pc=0x0c07027au; return 0; }
goto P_0c07027c;
P_0c07027c: /* original e00c, guest PC 0x0c07027c */
if(!s->budget--) { s->failed_pc=0x0c07027cu; return 0; }
r[0]=0x0000000cu;
goto P_0c07027e;
P_0c07027e: /* original f4fc, guest PC 0x0c07027e */
if(!s->budget--) { s->failed_pc=0x0c07027eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070280;
P_0c070280: /* original f3f6, guest PC 0x0c070280 */
if(!s->budget--) { s->failed_pc=0x0c070280u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c070282;
P_0c070282: /* original 64f3, guest PC 0x0c070282 */
if(!s->budget--) { s->failed_pc=0x0c070282u; return 0; }
r[4]=r[15];
goto P_0c070284;
P_0c070284: /* original 65f3, guest PC 0x0c070284 */
if(!s->budget--) { s->failed_pc=0x0c070284u; return 0; }
r[5]=r[15];
goto P_0c070286;
P_0c070286: /* original 7438, guest PC 0x0c070286 */
if(!s->budget--) { s->failed_pc=0x0c070286u; return 0; }
r[4]+=0x00000038u;
goto P_0c070288;
P_0c070288: /* original f431, guest PC 0x0c070288 */
if(!s->budget--) { s->failed_pc=0x0c070288u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c07028a;
P_0c07028a: /* original 7538, guest PC 0x0c07028a */
if(!s->budget--) { s->failed_pc=0x0c07028au; return 0; }
r[5]+=0x00000038u;
goto P_0c07028c;
P_0c07028c: /* original f059, guest PC 0x0c07028c */
if(!s->budget--) { s->failed_pc=0x0c07028cu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07028e;
P_0c07028e: /* original f159, guest PC 0x0c07028e */
if(!s->budget--) { s->failed_pc=0x0c07028eu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070290;
P_0c070290: /* original f259, guest PC 0x0c070290 */
if(!s->budget--) { s->failed_pc=0x0c070290u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070292;
P_0c070292: /* original f38d, guest PC 0x0c070292 */
if(!s->budget--) { s->failed_pc=0x0c070292u; return 0; }
fr[3]=0;
goto P_0c070294;
P_0c070294: /* original f0ed, guest PC 0x0c070294 */
if(!s->budget--) { s->failed_pc=0x0c070294u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070296;
P_0c070296: /* original f37d, guest PC 0x0c070296 */
if(!s->budget--) { s->failed_pc=0x0c070296u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070298;
P_0c070298: /* original f342, guest PC 0x0c070298 */
if(!s->budget--) { s->failed_pc=0x0c070298u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c07029a;
P_0c07029a: /* original 740c, guest PC 0x0c07029a */
if(!s->budget--) { s->failed_pc=0x0c07029au; return 0; }
r[4]+=0x0000000cu;
goto P_0c07029c;
P_0c07029c: /* original f232, guest PC 0x0c07029c */
if(!s->budget--) { s->failed_pc=0x0c07029cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07029e;
P_0c07029e: /* original f132, guest PC 0x0c07029e */
if(!s->budget--) { s->failed_pc=0x0c07029eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0702a0;
P_0c0702a0: /* original f032, guest PC 0x0c0702a0 */
if(!s->budget--) { s->failed_pc=0x0c0702a0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0702a2;
P_0c0702a2: /* original f42b, guest PC 0x0c0702a2 */
if(!s->budget--) { s->failed_pc=0x0c0702a2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0702a4;
P_0c0702a4: /* original f41b, guest PC 0x0c0702a4 */
if(!s->budget--) { s->failed_pc=0x0c0702a4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0702a6;
P_0c0702a6: /* original f40b, guest PC 0x0c0702a6 */
if(!s->budget--) { s->failed_pc=0x0c0702a6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0702a8;
P_0c0702a8: /* original 64f3, guest PC 0x0c0702a8 */
if(!s->budget--) { s->failed_pc=0x0c0702a8u; return 0; }
r[4]=r[15];
goto P_0c0702aa;
P_0c0702aa: /* original 65f3, guest PC 0x0c0702aa */
if(!s->budget--) { s->failed_pc=0x0c0702aau; return 0; }
r[5]=r[15];
goto P_0c0702ac;
P_0c0702ac: /* original 7444, guest PC 0x0c0702ac */
if(!s->budget--) { s->failed_pc=0x0c0702acu; return 0; }
r[4]+=0x00000044u;
goto P_0c0702ae;
P_0c0702ae: /* original 7538, guest PC 0x0c0702ae */
if(!s->budget--) { s->failed_pc=0x0c0702aeu; return 0; }
r[5]+=0x00000038u;
goto P_0c0702b0;
P_0c0702b0: /* original f049, guest PC 0x0c0702b0 */
if(!s->budget--) { s->failed_pc=0x0c0702b0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0702b2;
P_0c0702b2: /* original f359, guest PC 0x0c0702b2 */
if(!s->budget--) { s->failed_pc=0x0c0702b2u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702b4;
P_0c0702b4: /* original f149, guest PC 0x0c0702b4 */
if(!s->budget--) { s->failed_pc=0x0c0702b4u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0702b6;
P_0c0702b6: /* original f459, guest PC 0x0c0702b6 */
if(!s->budget--) { s->failed_pc=0x0c0702b6u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702b8;
P_0c0702b8: /* original f249, guest PC 0x0c0702b8 */
if(!s->budget--) { s->failed_pc=0x0c0702b8u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0702ba;
P_0c0702ba: /* original f559, guest PC 0x0c0702ba */
if(!s->budget--) { s->failed_pc=0x0c0702bau; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702bc;
P_0c0702bc: /* original f030, guest PC 0x0c0702bc */
if(!s->budget--) { s->failed_pc=0x0c0702bcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c0702be;
P_0c0702be: /* original f250, guest PC 0x0c0702be */
if(!s->budget--) { s->failed_pc=0x0c0702beu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0702c0;
P_0c0702c0: /* original f140, guest PC 0x0c0702c0 */
if(!s->budget--) { s->failed_pc=0x0c0702c0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c0702c2;
P_0c0702c2: /* original f42b, guest PC 0x0c0702c2 */
if(!s->budget--) { s->failed_pc=0x0c0702c2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0702c4;
P_0c0702c4: /* original f41b, guest PC 0x0c0702c4 */
if(!s->budget--) { s->failed_pc=0x0c0702c4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0702c6;
P_0c0702c6: /* original f40b, guest PC 0x0c0702c6 */
if(!s->budget--) { s->failed_pc=0x0c0702c6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0702c8;
P_0c0702c8: /* original 65f3, guest PC 0x0c0702c8 */
if(!s->budget--) { s->failed_pc=0x0c0702c8u; return 0; }
r[5]=r[15];
goto P_0c0702ca;
P_0c0702ca: /* original 64e3, guest PC 0x0c0702ca */
if(!s->budget--) { s->failed_pc=0x0c0702cau; return 0; }
r[4]=r[14];
goto P_0c0702cc;
P_0c0702cc: /* original 7544, guest PC 0x0c0702cc */
if(!s->budget--) { s->failed_pc=0x0c0702ccu; return 0; }
r[5]+=0x00000044u;
goto P_0c0702ce;
P_0c0702ce: /* original 66a3, guest PC 0x0c0702ce */
if(!s->budget--) { s->failed_pc=0x0c0702ceu; return 0; }
r[6]=r[10];
goto P_0c0702d0;
P_0c0702d0: /* original f059, guest PC 0x0c0702d0 */
if(!s->budget--) { s->failed_pc=0x0c0702d0u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702d2;
P_0c0702d2: /* original f369, guest PC 0x0c0702d2 */
if(!s->budget--) { s->failed_pc=0x0c0702d2u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0702d4;
P_0c0702d4: /* original f159, guest PC 0x0c0702d4 */
if(!s->budget--) { s->failed_pc=0x0c0702d4u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702d6;
P_0c0702d6: /* original f469, guest PC 0x0c0702d6 */
if(!s->budget--) { s->failed_pc=0x0c0702d6u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0702d8;
P_0c0702d8: /* original f259, guest PC 0x0c0702d8 */
if(!s->budget--) { s->failed_pc=0x0c0702d8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702da;
P_0c0702da: /* original f569, guest PC 0x0c0702da */
if(!s->budget--) { s->failed_pc=0x0c0702dau; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0702dc;
P_0c0702dc: /* original 740c, guest PC 0x0c0702dc */
if(!s->budget--) { s->failed_pc=0x0c0702dcu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0702de;
P_0c0702de: /* original f030, guest PC 0x0c0702de */
if(!s->budget--) { s->failed_pc=0x0c0702deu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c0702e0;
P_0c0702e0: /* original f250, guest PC 0x0c0702e0 */
if(!s->budget--) { s->failed_pc=0x0c0702e0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0702e2;
P_0c0702e2: /* original f140, guest PC 0x0c0702e2 */
if(!s->budget--) { s->failed_pc=0x0c0702e2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c0702e4;
P_0c0702e4: /* original f42b, guest PC 0x0c0702e4 */
if(!s->budget--) { s->failed_pc=0x0c0702e4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0702e6;
P_0c0702e6: /* original f41b, guest PC 0x0c0702e6 */
if(!s->budget--) { s->failed_pc=0x0c0702e6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0702e8;
P_0c0702e8: /* original f40b, guest PC 0x0c0702e8 */
if(!s->budget--) { s->failed_pc=0x0c0702e8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0702ea;
P_0c0702ea: /* original 0009, guest PC 0x0c0702ea */
if(!s->budget--) { s->failed_pc=0x0c0702eau; return 0; }
goto P_0c0702ec;
P_0c0702ec: /* original 64f3, guest PC 0x0c0702ec */
if(!s->budget--) { s->failed_pc=0x0c0702ecu; return 0; }
r[4]=r[15];
goto P_0c0702ee;
P_0c0702ee: /* original 7444, guest PC 0x0c0702ee */
if(!s->budget--) { s->failed_pc=0x0c0702eeu; return 0; }
r[4]+=0x00000044u;
goto P_0c0702f0;
P_0c0702f0: /* original 6693, guest PC 0x0c0702f0 */
if(!s->budget--) { s->failed_pc=0x0c0702f0u; return 0; }
r[6]=r[9];
goto P_0c0702f2;
P_0c0702f2: /* original 65e3, guest PC 0x0c0702f2 */
if(!s->budget--) { s->failed_pc=0x0c0702f2u; return 0; }
r[5]=r[14];
goto P_0c0702f4;
P_0c0702f4: /* original f059, guest PC 0x0c0702f4 */
if(!s->budget--) { s->failed_pc=0x0c0702f4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702f6;
P_0c0702f6: /* original f369, guest PC 0x0c0702f6 */
if(!s->budget--) { s->failed_pc=0x0c0702f6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0702f8;
P_0c0702f8: /* original f159, guest PC 0x0c0702f8 */
if(!s->budget--) { s->failed_pc=0x0c0702f8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0702fa;
P_0c0702fa: /* original f469, guest PC 0x0c0702fa */
if(!s->budget--) { s->failed_pc=0x0c0702fau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0702fc;
P_0c0702fc: /* original f031, guest PC 0x0c0702fc */
if(!s->budget--) { s->failed_pc=0x0c0702fcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0702fe;
P_0c0702fe: /* original f258, guest PC 0x0c0702fe */
if(!s->budget--) { s->failed_pc=0x0c0702feu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070300;
P_0c070300: /* original f568, guest PC 0x0c070300 */
if(!s->budget--) { s->failed_pc=0x0c070300u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070302;
P_0c070302: /* original f141, guest PC 0x0c070302 */
if(!s->budget--) { s->failed_pc=0x0c070302u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070304;
P_0c070304: /* original f251, guest PC 0x0c070304 */
if(!s->budget--) { s->failed_pc=0x0c070304u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070306;
P_0c070306: /* original 7408, guest PC 0x0c070306 */
if(!s->budget--) { s->failed_pc=0x0c070306u; return 0; }
r[4]+=0x00000008u;
goto P_0c070308;
P_0c070308: /* original f42a, guest PC 0x0c070308 */
if(!s->budget--) { s->failed_pc=0x0c070308u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07030a;
P_0c07030a: /* original f41b, guest PC 0x0c07030a */
if(!s->budget--) { s->failed_pc=0x0c07030au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07030c;
P_0c07030c: /* original f40b, guest PC 0x0c07030c */
if(!s->budget--) { s->failed_pc=0x0c07030cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07030e;
P_0c07030e: /* original 0009, guest PC 0x0c07030e */
if(!s->budget--) { s->failed_pc=0x0c07030eu; return 0; }
goto P_0c070310;
P_0c070310: /* original 64f3, guest PC 0x0c070310 */
if(!s->budget--) { s->failed_pc=0x0c070310u; return 0; }
r[4]=r[15];
goto P_0c070312;
P_0c070312: /* original 7444, guest PC 0x0c070312 */
if(!s->budget--) { s->failed_pc=0x0c070312u; return 0; }
r[4]+=0x00000044u;
goto P_0c070314;
P_0c070314: /* original f049, guest PC 0x0c070314 */
if(!s->budget--) { s->failed_pc=0x0c070314u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070316;
P_0c070316: /* original f149, guest PC 0x0c070316 */
if(!s->budget--) { s->failed_pc=0x0c070316u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070318;
P_0c070318: /* original f249, guest PC 0x0c070318 */
if(!s->budget--) { s->failed_pc=0x0c070318u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07031a;
P_0c07031a: /* original f38d, guest PC 0x0c07031a */
if(!s->budget--) { s->failed_pc=0x0c07031au; return 0; }
fr[3]=0;
goto P_0c07031c;
P_0c07031c: /* original f0ed, guest PC 0x0c07031c */
if(!s->budget--) { s->failed_pc=0x0c07031cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07031e;
P_0c07031e: /* original f03c, guest PC 0x0c07031e */
if(!s->budget--) { s->failed_pc=0x0c07031eu; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070320;
P_0c070320: /* original f06d, guest PC 0x0c070320 */
if(!s->budget--) { s->failed_pc=0x0c070320u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070322;
P_0c070322: /* original 0009, guest PC 0x0c070322 */
if(!s->budget--) { s->failed_pc=0x0c070322u; return 0; }
goto P_0c070324;
P_0c070324: /* original f38d, guest PC 0x0c070324 */
if(!s->budget--) { s->failed_pc=0x0c070324u; return 0; }
fr[3]=0;
goto P_0c070326;
P_0c070326: /* original f035, guest PC 0x0c070326 */
if(!s->budget--) { s->failed_pc=0x0c070326u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c070328;
P_0c070328: /* original e014, guest PC 0x0c070328 */
if(!s->budget--) { s->failed_pc=0x0c070328u; return 0; }
r[0]=0x00000014u;
goto P_0c07032a;
P_0c07032a: /* original 8d03, guest PC 0x0c07032a */
if(!s->budget--) { s->failed_pc=0x0c07032au; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c070334; }
goto P_0c07032e;
P_0c07032c: /* original ff07, guest PC 0x0c07032c */
if(!s->budget--) { s->failed_pc=0x0c07032cu; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c07032e;
P_0c07032e: /* original d304, guest PC 0x0c07032e */
if(!s->budget--) { s->failed_pc=0x0c07032eu; return 0; }
r[3]=read(ram,0x0c070340u,4);
goto P_0c070330;
P_0c070330: /* original 432b, guest PC 0x0c070330 */
if(!s->budget--) { s->failed_pc=0x0c070330u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070332: /* original 0009, guest PC 0x0c070332 */
if(!s->budget--) { s->failed_pc=0x0c070332u; return 0; }
goto P_0c070334;
P_0c070334: /* original 64f3, guest PC 0x0c070334 */
if(!s->budget--) { s->failed_pc=0x0c070334u; return 0; }
r[4]=r[15];
goto P_0c070336;
P_0c070336: /* original 7444, guest PC 0x0c070336 */
if(!s->budget--) { s->failed_pc=0x0c070336u; return 0; }
r[4]+=0x00000044u;
goto P_0c070338;
P_0c070338: /* original 65c3, guest PC 0x0c070338 */
if(!s->budget--) { s->failed_pc=0x0c070338u; return 0; }
r[5]=r[12];
goto P_0c07033a;
P_0c07033a: /* original a003, guest PC 0x0c07033a */
if(!s->budget--) { s->failed_pc=0x0c07033au; return 0; }
goto P_0c070344;
P_0c07033c: /* original 0009, guest PC 0x0c07033c */
if(!s->budget--) { s->failed_pc=0x0c07033cu; return 0; }
return vf3_matrix_family(0x0c07033eu,s,ram);
P_0c070344: /* original f049, guest PC 0x0c070344 */
if(!s->budget--) { s->failed_pc=0x0c070344u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070346;
P_0c070346: /* original f549, guest PC 0x0c070346 */
if(!s->budget--) { s->failed_pc=0x0c070346u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070348;
P_0c070348: /* original f648, guest PC 0x0c070348 */
if(!s->budget--) { s->failed_pc=0x0c070348u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c07034a;
P_0c07034a: /* original f859, guest PC 0x0c07034a */
if(!s->budget--) { s->failed_pc=0x0c07034au; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07034c;
P_0c07034c: /* original f959, guest PC 0x0c07034c */
if(!s->budget--) { s->failed_pc=0x0c07034cu; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07034e;
P_0c07034e: /* original fa58, guest PC 0x0c07034e */
if(!s->budget--) { s->failed_pc=0x0c07034eu; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c070350;
P_0c070350: /* original f35c, guest PC 0x0c070350 */
if(!s->budget--) { s->failed_pc=0x0c070350u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c070352;
P_0c070352: /* original f382, guest PC 0x0c070352 */
if(!s->budget--) { s->failed_pc=0x0c070352u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c070354;
P_0c070354: /* original f20c, guest PC 0x0c070354 */
if(!s->budget--) { s->failed_pc=0x0c070354u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c070356;
P_0c070356: /* original f2a2, guest PC 0x0c070356 */
if(!s->budget--) { s->failed_pc=0x0c070356u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c070358;
P_0c070358: /* original f16c, guest PC 0x0c070358 */
if(!s->budget--) { s->failed_pc=0x0c070358u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c07035a;
P_0c07035a: /* original f192, guest PC 0x0c07035a */
if(!s->budget--) { s->failed_pc=0x0c07035au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c07035c;
P_0c07035c: /* original f34d, guest PC 0x0c07035c */
if(!s->budget--) { s->failed_pc=0x0c07035cu; return 0; }
fr[3]^=0x80000000u;
goto P_0c07035e;
P_0c07035e: /* original f39e, guest PC 0x0c07035e */
if(!s->budget--) { s->failed_pc=0x0c07035eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070360;
P_0c070360: /* original f24d, guest PC 0x0c070360 */
if(!s->budget--) { s->failed_pc=0x0c070360u; return 0; }
fr[2]^=0x80000000u;
goto P_0c070362;
P_0c070362: /* original f06c, guest PC 0x0c070362 */
if(!s->budget--) { s->failed_pc=0x0c070362u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c070364;
P_0c070364: /* original f28e, guest PC 0x0c070364 */
if(!s->budget--) { s->failed_pc=0x0c070364u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c070366;
P_0c070366: /* original f14d, guest PC 0x0c070366 */
if(!s->budget--) { s->failed_pc=0x0c070366u; return 0; }
fr[1]^=0x80000000u;
goto P_0c070368;
P_0c070368: /* original f05c, guest PC 0x0c070368 */
if(!s->budget--) { s->failed_pc=0x0c070368u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c07036a;
P_0c07036a: /* original f1ae, guest PC 0x0c07036a */
if(!s->budget--) { s->failed_pc=0x0c07036au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c07036c;
P_0c07036c: /* original f08d, guest PC 0x0c07036c */
if(!s->budget--) { s->failed_pc=0x0c07036cu; return 0; }
fr[0]=0;
goto P_0c07036e;
P_0c07036e: /* original f0ed, guest PC 0x0c07036e */
if(!s->budget--) { s->failed_pc=0x0c07036eu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070370;
P_0c070370: /* original f03c, guest PC 0x0c070370 */
if(!s->budget--) { s->failed_pc=0x0c070370u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070372;
P_0c070372: /* original f06d, guest PC 0x0c070372 */
if(!s->budget--) { s->failed_pc=0x0c070372u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070374;
P_0c070374: /* original fc0c, guest PC 0x0c070374 */
if(!s->budget--) { s->failed_pc=0x0c070374u; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c070376;
P_0c070376: /* original ffc5, guest PC 0x0c070376 */
if(!s->budget--) { s->failed_pc=0x0c070376u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c070378;
P_0c070378: /* original 8902, guest PC 0x0c070378 */
if(!s->budget--) { s->failed_pc=0x0c070378u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070380; }
goto P_0c07037a;
P_0c07037a: /* original d304, guest PC 0x0c07037a */
if(!s->budget--) { s->failed_pc=0x0c07037au; return 0; }
r[3]=read(ram,0x0c07038cu,4);
goto P_0c07037c;
P_0c07037c: /* original 432b, guest PC 0x0c07037c */
if(!s->budget--) { s->failed_pc=0x0c07037cu; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c07037e: /* original 0009, guest PC 0x0c07037e */
if(!s->budget--) { s->failed_pc=0x0c07037eu; return 0; }
goto P_0c070380;
P_0c070380: /* original 64f3, guest PC 0x0c070380 */
if(!s->budget--) { s->failed_pc=0x0c070380u; return 0; }
r[4]=r[15];
goto P_0c070382;
P_0c070382: /* original 7444, guest PC 0x0c070382 */
if(!s->budget--) { s->failed_pc=0x0c070382u; return 0; }
r[4]+=0x00000044u;
goto P_0c070384;
P_0c070384: /* original 65c3, guest PC 0x0c070384 */
if(!s->budget--) { s->failed_pc=0x0c070384u; return 0; }
r[5]=r[12];
goto P_0c070386;
P_0c070386: /* original a003, guest PC 0x0c070386 */
if(!s->budget--) { s->failed_pc=0x0c070386u; return 0; }
goto P_0c070390;
P_0c070388: /* original 0009, guest PC 0x0c070388 */
if(!s->budget--) { s->failed_pc=0x0c070388u; return 0; }
return vf3_matrix_family(0x0c07038au,s,ram);
P_0c070390: /* original f049, guest PC 0x0c070390 */
if(!s->budget--) { s->failed_pc=0x0c070390u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070392;
P_0c070392: /* original f149, guest PC 0x0c070392 */
if(!s->budget--) { s->failed_pc=0x0c070392u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070394;
P_0c070394: /* original f249, guest PC 0x0c070394 */
if(!s->budget--) { s->failed_pc=0x0c070394u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070396;
P_0c070396: /* original f38d, guest PC 0x0c070396 */
if(!s->budget--) { s->failed_pc=0x0c070396u; return 0; }
fr[3]=0;
goto P_0c070398;
P_0c070398: /* original f459, guest PC 0x0c070398 */
if(!s->budget--) { s->failed_pc=0x0c070398u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07039a;
P_0c07039a: /* original f559, guest PC 0x0c07039a */
if(!s->budget--) { s->failed_pc=0x0c07039au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07039c;
P_0c07039c: /* original f659, guest PC 0x0c07039c */
if(!s->budget--) { s->failed_pc=0x0c07039cu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07039e;
P_0c07039e: /* original f78d, guest PC 0x0c07039e */
if(!s->budget--) { s->failed_pc=0x0c07039eu; return 0; }
fr[7]=0;
goto P_0c0703a0;
P_0c0703a0: /* original f4ed, guest PC 0x0c0703a0 */
if(!s->budget--) { s->failed_pc=0x0c0703a0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c0703a2;
P_0c0703a2: /* original f07c, guest PC 0x0c0703a2 */
if(!s->budget--) { s->failed_pc=0x0c0703a2u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c0703a4;
P_0c0703a4: /* original f38d, guest PC 0x0c0703a4 */
if(!s->budget--) { s->failed_pc=0x0c0703a4u; return 0; }
fr[3]=0;
goto P_0c0703a6;
P_0c0703a6: /* original f40c, guest PC 0x0c0703a6 */
if(!s->budget--) { s->failed_pc=0x0c0703a6u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0703a8;
P_0c0703a8: /* original f345, guest PC 0x0c0703a8 */
if(!s->budget--) { s->failed_pc=0x0c0703a8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0703aa;
P_0c0703aa: /* original 8902, guest PC 0x0c0703aa */
if(!s->budget--) { s->failed_pc=0x0c0703aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0703b2; }
goto P_0c0703ac;
P_0c0703ac: /* original d308, guest PC 0x0c0703ac */
if(!s->budget--) { s->failed_pc=0x0c0703acu; return 0; }
r[3]=read(ram,0x0c0703d0u,4);
goto P_0c0703ae;
P_0c0703ae: /* original 432b, guest PC 0x0c0703ae */
if(!s->budget--) { s->failed_pc=0x0c0703aeu; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0703b0: /* original 0009, guest PC 0x0c0703b0 */
if(!s->budget--) { s->failed_pc=0x0c0703b0u; return 0; }
goto P_0c0703b2;
P_0c0703b2: /* original e014, guest PC 0x0c0703b2 */
if(!s->budget--) { s->failed_pc=0x0c0703b2u; return 0; }
r[0]=0x00000014u;
goto P_0c0703b4;
P_0c0703b4: /* original f3f6, guest PC 0x0c0703b4 */
if(!s->budget--) { s->failed_pc=0x0c0703b4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0703b6;
P_0c0703b6: /* original ff35, guest PC 0x0c0703b6 */
if(!s->budget--) { s->failed_pc=0x0c0703b6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c0703b8;
P_0c0703b8: /* original 8902, guest PC 0x0c0703b8 */
if(!s->budget--) { s->failed_pc=0x0c0703b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0703c0; }
goto P_0c0703ba;
P_0c0703ba: /* original d306, guest PC 0x0c0703ba */
if(!s->budget--) { s->failed_pc=0x0c0703bau; return 0; }
r[3]=read(ram,0x0c0703d4u,4);
goto P_0c0703bc;
P_0c0703bc: /* original 432b, guest PC 0x0c0703bc */
if(!s->budget--) { s->failed_pc=0x0c0703bcu; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0703be: /* original 0009, guest PC 0x0c0703be */
if(!s->budget--) { s->failed_pc=0x0c0703beu; return 0; }
goto P_0c0703c0;
P_0c0703c0: /* original 64f3, guest PC 0x0c0703c0 */
if(!s->budget--) { s->failed_pc=0x0c0703c0u; return 0; }
r[4]=r[15];
goto P_0c0703c2;
P_0c0703c2: /* original 65f3, guest PC 0x0c0703c2 */
if(!s->budget--) { s->failed_pc=0x0c0703c2u; return 0; }
r[5]=r[15];
goto P_0c0703c4;
P_0c0703c4: /* original 7444, guest PC 0x0c0703c4 */
if(!s->budget--) { s->failed_pc=0x0c0703c4u; return 0; }
r[4]+=0x00000044u;
goto P_0c0703c6;
P_0c0703c6: /* original f4fc, guest PC 0x0c0703c6 */
if(!s->budget--) { s->failed_pc=0x0c0703c6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0703c8;
P_0c0703c8: /* original 7544, guest PC 0x0c0703c8 */
if(!s->budget--) { s->failed_pc=0x0c0703c8u; return 0; }
r[5]+=0x00000044u;
goto P_0c0703ca;
P_0c0703ca: /* original a005, guest PC 0x0c0703ca */
if(!s->budget--) { s->failed_pc=0x0c0703cau; return 0; }
goto P_0c0703d8;
P_0c0703cc: /* original 0009, guest PC 0x0c0703cc */
if(!s->budget--) { s->failed_pc=0x0c0703ccu; return 0; }
return vf3_matrix_family(0x0c0703ceu,s,ram);
P_0c0703d8: /* original f059, guest PC 0x0c0703d8 */
if(!s->budget--) { s->failed_pc=0x0c0703d8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0703da;
P_0c0703da: /* original f159, guest PC 0x0c0703da */
if(!s->budget--) { s->failed_pc=0x0c0703dau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0703dc;
P_0c0703dc: /* original f259, guest PC 0x0c0703dc */
if(!s->budget--) { s->failed_pc=0x0c0703dcu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0703de;
P_0c0703de: /* original f38d, guest PC 0x0c0703de */
if(!s->budget--) { s->failed_pc=0x0c0703deu; return 0; }
fr[3]=0;
goto P_0c0703e0;
P_0c0703e0: /* original f0ed, guest PC 0x0c0703e0 */
if(!s->budget--) { s->failed_pc=0x0c0703e0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0703e2;
P_0c0703e2: /* original f37d, guest PC 0x0c0703e2 */
if(!s->budget--) { s->failed_pc=0x0c0703e2u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0703e4;
P_0c0703e4: /* original f342, guest PC 0x0c0703e4 */
if(!s->budget--) { s->failed_pc=0x0c0703e4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0703e6;
P_0c0703e6: /* original 740c, guest PC 0x0c0703e6 */
if(!s->budget--) { s->failed_pc=0x0c0703e6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0703e8;
P_0c0703e8: /* original f232, guest PC 0x0c0703e8 */
if(!s->budget--) { s->failed_pc=0x0c0703e8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0703ea;
P_0c0703ea: /* original f132, guest PC 0x0c0703ea */
if(!s->budget--) { s->failed_pc=0x0c0703eau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0703ec;
P_0c0703ec: /* original f032, guest PC 0x0c0703ec */
if(!s->budget--) { s->failed_pc=0x0c0703ecu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0703ee;
P_0c0703ee: /* original f42b, guest PC 0x0c0703ee */
if(!s->budget--) { s->failed_pc=0x0c0703eeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0703f0;
P_0c0703f0: /* original f41b, guest PC 0x0c0703f0 */
if(!s->budget--) { s->failed_pc=0x0c0703f0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0703f2;
P_0c0703f2: /* original f40b, guest PC 0x0c0703f2 */
if(!s->budget--) { s->failed_pc=0x0c0703f2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0703f4;
P_0c0703f4: /* original d306, guest PC 0x0c0703f4 */
if(!s->budget--) { s->failed_pc=0x0c0703f4u; return 0; }
r[3]=read(ram,0x0c070410u,4);
goto P_0c0703f6;
P_0c0703f6: /* original 432b, guest PC 0x0c0703f6 */
if(!s->budget--) { s->failed_pc=0x0c0703f6u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0703f8: /* original 0009, guest PC 0x0c0703f8 */
if(!s->budget--) { s->failed_pc=0x0c0703f8u; return 0; }
return vf3_matrix_family(0x0c0703fau,s,ram);
P_0c07042a: /* original f40b, guest PC 0x0c07042a */
if(!s->budget--) { s->failed_pc=0x0c07042au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07042c;
P_0c07042c: /* original 65f3, guest PC 0x0c07042c */
if(!s->budget--) { s->failed_pc=0x0c07042cu; return 0; }
r[5]=r[15];
goto P_0c07042e;
P_0c07042e: /* original 64f3, guest PC 0x0c07042e */
if(!s->budget--) { s->failed_pc=0x0c07042eu; return 0; }
r[4]=r[15];
goto P_0c070430;
P_0c070430: /* original 66f3, guest PC 0x0c070430 */
if(!s->budget--) { s->failed_pc=0x0c070430u; return 0; }
r[6]=r[15];
goto P_0c070432;
P_0c070432: /* original 7438, guest PC 0x0c070432 */
if(!s->budget--) { s->failed_pc=0x0c070432u; return 0; }
r[4]+=0x00000038u;
goto P_0c070434;
P_0c070434: /* original 7638, guest PC 0x0c070434 */
if(!s->budget--) { s->failed_pc=0x0c070434u; return 0; }
r[6]+=0x00000038u;
goto P_0c070436;
P_0c070436: /* original 7544, guest PC 0x0c070436 */
if(!s->budget--) { s->failed_pc=0x0c070436u; return 0; }
r[5]+=0x00000044u;
goto P_0c070438;
P_0c070438: /* original f059, guest PC 0x0c070438 */
if(!s->budget--) { s->failed_pc=0x0c070438u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07043a;
P_0c07043a: /* original f369, guest PC 0x0c07043a */
if(!s->budget--) { s->failed_pc=0x0c07043au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07043c;
P_0c07043c: /* original f159, guest PC 0x0c07043c */
if(!s->budget--) { s->failed_pc=0x0c07043cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07043e;
P_0c07043e: /* original f469, guest PC 0x0c07043e */
if(!s->budget--) { s->failed_pc=0x0c07043eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070440;
P_0c070440: /* original f031, guest PC 0x0c070440 */
if(!s->budget--) { s->failed_pc=0x0c070440u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070442;
P_0c070442: /* original f258, guest PC 0x0c070442 */
if(!s->budget--) { s->failed_pc=0x0c070442u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070444;
P_0c070444: /* original f568, guest PC 0x0c070444 */
if(!s->budget--) { s->failed_pc=0x0c070444u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070446;
P_0c070446: /* original f141, guest PC 0x0c070446 */
if(!s->budget--) { s->failed_pc=0x0c070446u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070448;
P_0c070448: /* original f251, guest PC 0x0c070448 */
if(!s->budget--) { s->failed_pc=0x0c070448u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c07044a;
P_0c07044a: /* original 7408, guest PC 0x0c07044a */
if(!s->budget--) { s->failed_pc=0x0c07044au; return 0; }
r[4]+=0x00000008u;
goto P_0c07044c;
P_0c07044c: /* original f42a, guest PC 0x0c07044c */
if(!s->budget--) { s->failed_pc=0x0c07044cu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07044e;
P_0c07044e: /* original f41b, guest PC 0x0c07044e */
if(!s->budget--) { s->failed_pc=0x0c07044eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070450;
P_0c070450: /* original f40b, guest PC 0x0c070450 */
if(!s->budget--) { s->failed_pc=0x0c070450u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070452;
P_0c070452: /* original 0009, guest PC 0x0c070452 */
if(!s->budget--) { s->failed_pc=0x0c070452u; return 0; }
goto P_0c070454;
P_0c070454: /* original f4fc, guest PC 0x0c070454 */
if(!s->budget--) { s->failed_pc=0x0c070454u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070456;
P_0c070456: /* original f4c1, guest PC 0x0c070456 */
if(!s->budget--) { s->failed_pc=0x0c070456u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[12],r[18],'-');
goto P_0c070458;
P_0c070458: /* original 64f3, guest PC 0x0c070458 */
if(!s->budget--) { s->failed_pc=0x0c070458u; return 0; }
r[4]=r[15];
goto P_0c07045a;
P_0c07045a: /* original 65f3, guest PC 0x0c07045a */
if(!s->budget--) { s->failed_pc=0x0c07045au; return 0; }
r[5]=r[15];
goto P_0c07045c;
P_0c07045c: /* original 7438, guest PC 0x0c07045c */
if(!s->budget--) { s->failed_pc=0x0c07045cu; return 0; }
r[4]+=0x00000038u;
goto P_0c07045e;
P_0c07045e: /* original 7538, guest PC 0x0c07045e */
if(!s->budget--) { s->failed_pc=0x0c07045eu; return 0; }
r[5]+=0x00000038u;
goto P_0c070460;
P_0c070460: /* original f059, guest PC 0x0c070460 */
if(!s->budget--) { s->failed_pc=0x0c070460u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070462;
P_0c070462: /* original f159, guest PC 0x0c070462 */
if(!s->budget--) { s->failed_pc=0x0c070462u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070464;
P_0c070464: /* original f259, guest PC 0x0c070464 */
if(!s->budget--) { s->failed_pc=0x0c070464u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070466;
P_0c070466: /* original f38d, guest PC 0x0c070466 */
if(!s->budget--) { s->failed_pc=0x0c070466u; return 0; }
fr[3]=0;
goto P_0c070468;
P_0c070468: /* original f0ed, guest PC 0x0c070468 */
if(!s->budget--) { s->failed_pc=0x0c070468u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07046a;
P_0c07046a: /* original f37d, guest PC 0x0c07046a */
if(!s->budget--) { s->failed_pc=0x0c07046au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c07046c;
P_0c07046c: /* original f342, guest PC 0x0c07046c */
if(!s->budget--) { s->failed_pc=0x0c07046cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c07046e;
P_0c07046e: /* original 740c, guest PC 0x0c07046e */
if(!s->budget--) { s->failed_pc=0x0c07046eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c070470;
P_0c070470: /* original f232, guest PC 0x0c070470 */
if(!s->budget--) { s->failed_pc=0x0c070470u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070472;
P_0c070472: /* original f132, guest PC 0x0c070472 */
if(!s->budget--) { s->failed_pc=0x0c070472u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070474;
P_0c070474: /* original f032, guest PC 0x0c070474 */
if(!s->budget--) { s->failed_pc=0x0c070474u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070476;
P_0c070476: /* original f42b, guest PC 0x0c070476 */
if(!s->budget--) { s->failed_pc=0x0c070476u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070478;
P_0c070478: /* original f41b, guest PC 0x0c070478 */
if(!s->budget--) { s->failed_pc=0x0c070478u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07047a;
P_0c07047a: /* original f40b, guest PC 0x0c07047a */
if(!s->budget--) { s->failed_pc=0x0c07047au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07047c;
P_0c07047c: /* original 64f3, guest PC 0x0c07047c */
if(!s->budget--) { s->failed_pc=0x0c07047cu; return 0; }
r[4]=r[15];
goto P_0c07047e;
P_0c07047e: /* original 65f3, guest PC 0x0c07047e */
if(!s->budget--) { s->failed_pc=0x0c07047eu; return 0; }
r[5]=r[15];
goto P_0c070480;
P_0c070480: /* original 7444, guest PC 0x0c070480 */
if(!s->budget--) { s->failed_pc=0x0c070480u; return 0; }
r[4]+=0x00000044u;
goto P_0c070482;
P_0c070482: /* original 7538, guest PC 0x0c070482 */
if(!s->budget--) { s->failed_pc=0x0c070482u; return 0; }
r[5]+=0x00000038u;
goto P_0c070484;
P_0c070484: /* original f049, guest PC 0x0c070484 */
if(!s->budget--) { s->failed_pc=0x0c070484u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070486;
P_0c070486: /* original f359, guest PC 0x0c070486 */
if(!s->budget--) { s->failed_pc=0x0c070486u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070488;
P_0c070488: /* original f149, guest PC 0x0c070488 */
if(!s->budget--) { s->failed_pc=0x0c070488u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07048a;
P_0c07048a: /* original f459, guest PC 0x0c07048a */
if(!s->budget--) { s->failed_pc=0x0c07048au; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07048c;
P_0c07048c: /* original f249, guest PC 0x0c07048c */
if(!s->budget--) { s->failed_pc=0x0c07048cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07048e;
P_0c07048e: /* original f559, guest PC 0x0c07048e */
if(!s->budget--) { s->failed_pc=0x0c07048eu; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070490;
P_0c070490: /* original f030, guest PC 0x0c070490 */
if(!s->budget--) { s->failed_pc=0x0c070490u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070492;
P_0c070492: /* original f250, guest PC 0x0c070492 */
if(!s->budget--) { s->failed_pc=0x0c070492u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070494;
P_0c070494: /* original f140, guest PC 0x0c070494 */
if(!s->budget--) { s->failed_pc=0x0c070494u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070496;
P_0c070496: /* original f42b, guest PC 0x0c070496 */
if(!s->budget--) { s->failed_pc=0x0c070496u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070498;
P_0c070498: /* original f41b, guest PC 0x0c070498 */
if(!s->budget--) { s->failed_pc=0x0c070498u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07049a;
P_0c07049a: /* original f40b, guest PC 0x0c07049a */
if(!s->budget--) { s->failed_pc=0x0c07049au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07049c;
P_0c07049c: /* original 65f3, guest PC 0x0c07049c */
if(!s->budget--) { s->failed_pc=0x0c07049cu; return 0; }
r[5]=r[15];
goto P_0c07049e;
P_0c07049e: /* original 64e3, guest PC 0x0c07049e */
if(!s->budget--) { s->failed_pc=0x0c07049eu; return 0; }
r[4]=r[14];
goto P_0c0704a0;
P_0c0704a0: /* original 7544, guest PC 0x0c0704a0 */
if(!s->budget--) { s->failed_pc=0x0c0704a0u; return 0; }
r[5]+=0x00000044u;
goto P_0c0704a2;
P_0c0704a2: /* original 6693, guest PC 0x0c0704a2 */
if(!s->budget--) { s->failed_pc=0x0c0704a2u; return 0; }
r[6]=r[9];
goto P_0c0704a4;
P_0c0704a4: /* original f059, guest PC 0x0c0704a4 */
if(!s->budget--) { s->failed_pc=0x0c0704a4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0704a6;
P_0c0704a6: /* original f369, guest PC 0x0c0704a6 */
if(!s->budget--) { s->failed_pc=0x0c0704a6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0704a8;
P_0c0704a8: /* original f159, guest PC 0x0c0704a8 */
if(!s->budget--) { s->failed_pc=0x0c0704a8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0704aa;
P_0c0704aa: /* original f469, guest PC 0x0c0704aa */
if(!s->budget--) { s->failed_pc=0x0c0704aau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0704ac;
P_0c0704ac: /* original f259, guest PC 0x0c0704ac */
if(!s->budget--) { s->failed_pc=0x0c0704acu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0704ae;
P_0c0704ae: /* original f569, guest PC 0x0c0704ae */
if(!s->budget--) { s->failed_pc=0x0c0704aeu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0704b0;
P_0c0704b0: /* original 740c, guest PC 0x0c0704b0 */
if(!s->budget--) { s->failed_pc=0x0c0704b0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0704b2;
P_0c0704b2: /* original f030, guest PC 0x0c0704b2 */
if(!s->budget--) { s->failed_pc=0x0c0704b2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c0704b4;
P_0c0704b4: /* original f250, guest PC 0x0c0704b4 */
if(!s->budget--) { s->failed_pc=0x0c0704b4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0704b6;
P_0c0704b6: /* original f140, guest PC 0x0c0704b6 */
if(!s->budget--) { s->failed_pc=0x0c0704b6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c0704b8;
P_0c0704b8: /* original f42b, guest PC 0x0c0704b8 */
if(!s->budget--) { s->failed_pc=0x0c0704b8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0704ba;
P_0c0704ba: /* original f41b, guest PC 0x0c0704ba */
if(!s->budget--) { s->failed_pc=0x0c0704bau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0704bc;
P_0c0704bc: /* original f40b, guest PC 0x0c0704bc */
if(!s->budget--) { s->failed_pc=0x0c0704bcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0704be;
P_0c0704be: /* original 0009, guest PC 0x0c0704be */
if(!s->budget--) { s->failed_pc=0x0c0704beu; return 0; }
goto P_0c0704c0;
P_0c0704c0: /* original 50fa, guest PC 0x0c0704c0 */
if(!s->budget--) { s->failed_pc=0x0c0704c0u; return 0; }
r[0]=read(ram,r[15]+40,4);
goto P_0c0704c2;
P_0c0704c2: /* original 8801, guest PC 0x0c0704c2 */
if(!s->budget--) { s->failed_pc=0x0c0704c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0704c4;
P_0c0704c4: /* original 8902, guest PC 0x0c0704c4 */
if(!s->budget--) { s->failed_pc=0x0c0704c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0704cc; }
goto P_0c0704c6;
P_0c0704c6: /* original d304, guest PC 0x0c0704c6 */
if(!s->budget--) { s->failed_pc=0x0c0704c6u; return 0; }
r[3]=read(ram,0x0c0704d8u,4);
goto P_0c0704c8;
P_0c0704c8: /* original 432b, guest PC 0x0c0704c8 */
if(!s->budget--) { s->failed_pc=0x0c0704c8u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0704ca: /* original 0009, guest PC 0x0c0704ca */
if(!s->budget--) { s->failed_pc=0x0c0704cau; return 0; }
goto P_0c0704cc;
P_0c0704cc: /* original 64f3, guest PC 0x0c0704cc */
if(!s->budget--) { s->failed_pc=0x0c0704ccu; return 0; }
r[4]=r[15];
goto P_0c0704ce;
P_0c0704ce: /* original 7444, guest PC 0x0c0704ce */
if(!s->budget--) { s->failed_pc=0x0c0704ceu; return 0; }
r[4]+=0x00000044u;
goto P_0c0704d0;
P_0c0704d0: /* original 66a3, guest PC 0x0c0704d0 */
if(!s->budget--) { s->failed_pc=0x0c0704d0u; return 0; }
r[6]=r[10];
goto P_0c0704d2;
P_0c0704d2: /* original 65d3, guest PC 0x0c0704d2 */
if(!s->budget--) { s->failed_pc=0x0c0704d2u; return 0; }
r[5]=r[13];
goto P_0c0704d4;
P_0c0704d4: /* original a002, guest PC 0x0c0704d4 */
if(!s->budget--) { s->failed_pc=0x0c0704d4u; return 0; }
goto P_0c0704dc;
P_0c0704d6: /* original 0009, guest PC 0x0c0704d6 */
if(!s->budget--) { s->failed_pc=0x0c0704d6u; return 0; }
return vf3_matrix_family(0x0c0704d8u,s,ram);
P_0c0704dc: /* original f059, guest PC 0x0c0704dc */
if(!s->budget--) { s->failed_pc=0x0c0704dcu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0704de;
P_0c0704de: /* original f369, guest PC 0x0c0704de */
if(!s->budget--) { s->failed_pc=0x0c0704deu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0704e0;
P_0c0704e0: /* original f159, guest PC 0x0c0704e0 */
if(!s->budget--) { s->failed_pc=0x0c0704e0u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0704e2;
P_0c0704e2: /* original f469, guest PC 0x0c0704e2 */
if(!s->budget--) { s->failed_pc=0x0c0704e2u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0704e4;
P_0c0704e4: /* original f031, guest PC 0x0c0704e4 */
if(!s->budget--) { s->failed_pc=0x0c0704e4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0704e6;
P_0c0704e6: /* original f258, guest PC 0x0c0704e6 */
if(!s->budget--) { s->failed_pc=0x0c0704e6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0704e8;
P_0c0704e8: /* original f568, guest PC 0x0c0704e8 */
if(!s->budget--) { s->failed_pc=0x0c0704e8u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0704ea;
P_0c0704ea: /* original f141, guest PC 0x0c0704ea */
if(!s->budget--) { s->failed_pc=0x0c0704eau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0704ec;
P_0c0704ec: /* original f251, guest PC 0x0c0704ec */
if(!s->budget--) { s->failed_pc=0x0c0704ecu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0704ee;
P_0c0704ee: /* original 7408, guest PC 0x0c0704ee */
if(!s->budget--) { s->failed_pc=0x0c0704eeu; return 0; }
r[4]+=0x00000008u;
goto P_0c0704f0;
P_0c0704f0: /* original f42a, guest PC 0x0c0704f0 */
if(!s->budget--) { s->failed_pc=0x0c0704f0u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0704f2;
P_0c0704f2: /* original f41b, guest PC 0x0c0704f2 */
if(!s->budget--) { s->failed_pc=0x0c0704f2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0704f4;
P_0c0704f4: /* original f40b, guest PC 0x0c0704f4 */
if(!s->budget--) { s->failed_pc=0x0c0704f4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0704f6;
P_0c0704f6: /* original 0009, guest PC 0x0c0704f6 */
if(!s->budget--) { s->failed_pc=0x0c0704f6u; return 0; }
goto P_0c0704f8;
P_0c0704f8: /* original 64f3, guest PC 0x0c0704f8 */
if(!s->budget--) { s->failed_pc=0x0c0704f8u; return 0; }
r[4]=r[15];
goto P_0c0704fa;
P_0c0704fa: /* original 7444, guest PC 0x0c0704fa */
if(!s->budget--) { s->failed_pc=0x0c0704fau; return 0; }
r[4]+=0x00000044u;
goto P_0c0704fc;
P_0c0704fc: /* original f049, guest PC 0x0c0704fc */
if(!s->budget--) { s->failed_pc=0x0c0704fcu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0704fe;
P_0c0704fe: /* original f149, guest PC 0x0c0704fe */
if(!s->budget--) { s->failed_pc=0x0c0704feu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070500;
P_0c070500: /* original f249, guest PC 0x0c070500 */
if(!s->budget--) { s->failed_pc=0x0c070500u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070502;
P_0c070502: /* original f38d, guest PC 0x0c070502 */
if(!s->budget--) { s->failed_pc=0x0c070502u; return 0; }
fr[3]=0;
goto P_0c070504;
P_0c070504: /* original f0ed, guest PC 0x0c070504 */
if(!s->budget--) { s->failed_pc=0x0c070504u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070506;
P_0c070506: /* original f03c, guest PC 0x0c070506 */
if(!s->budget--) { s->failed_pc=0x0c070506u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070508;
P_0c070508: /* original f06d, guest PC 0x0c070508 */
if(!s->budget--) { s->failed_pc=0x0c070508u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c07050a;
P_0c07050a: /* original 0009, guest PC 0x0c07050a */
if(!s->budget--) { s->failed_pc=0x0c07050au; return 0; }
goto P_0c07050c;
P_0c07050c: /* original f38d, guest PC 0x0c07050c */
if(!s->budget--) { s->failed_pc=0x0c07050cu; return 0; }
fr[3]=0;
goto P_0c07050e;
P_0c07050e: /* original fc0c, guest PC 0x0c07050e */
if(!s->budget--) { s->failed_pc=0x0c07050eu; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c070510;
P_0c070510: /* original fc35, guest PC 0x0c070510 */
if(!s->budget--) { s->failed_pc=0x0c070510u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[12])>as_float(fr[3]))!=0);
goto P_0c070512;
P_0c070512: /* original 8902, guest PC 0x0c070512 */
if(!s->budget--) { s->failed_pc=0x0c070512u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07051a; }
goto P_0c070514;
P_0c070514: /* original d303, guest PC 0x0c070514 */
if(!s->budget--) { s->failed_pc=0x0c070514u; return 0; }
r[3]=read(ram,0x0c070524u,4);
goto P_0c070516;
P_0c070516: /* original 432b, guest PC 0x0c070516 */
if(!s->budget--) { s->failed_pc=0x0c070516u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070518: /* original 0009, guest PC 0x0c070518 */
if(!s->budget--) { s->failed_pc=0x0c070518u; return 0; }
goto P_0c07051a;
P_0c07051a: /* original 64f3, guest PC 0x0c07051a */
if(!s->budget--) { s->failed_pc=0x0c07051au; return 0; }
r[4]=r[15];
goto P_0c07051c;
P_0c07051c: /* original 7444, guest PC 0x0c07051c */
if(!s->budget--) { s->failed_pc=0x0c07051cu; return 0; }
r[4]+=0x00000044u;
goto P_0c07051e;
P_0c07051e: /* original 65b3, guest PC 0x0c07051e */
if(!s->budget--) { s->failed_pc=0x0c07051eu; return 0; }
r[5]=r[11];
goto P_0c070520;
P_0c070520: /* original a002, guest PC 0x0c070520 */
if(!s->budget--) { s->failed_pc=0x0c070520u; return 0; }
goto P_0c070528;
P_0c070522: /* original 0009, guest PC 0x0c070522 */
if(!s->budget--) { s->failed_pc=0x0c070522u; return 0; }
return vf3_matrix_family(0x0c070524u,s,ram);
P_0c070528: /* original f049, guest PC 0x0c070528 */
if(!s->budget--) { s->failed_pc=0x0c070528u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07052a;
P_0c07052a: /* original f549, guest PC 0x0c07052a */
if(!s->budget--) { s->failed_pc=0x0c07052au; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07052c;
P_0c07052c: /* original f648, guest PC 0x0c07052c */
if(!s->budget--) { s->failed_pc=0x0c07052cu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c07052e;
P_0c07052e: /* original f859, guest PC 0x0c07052e */
if(!s->budget--) { s->failed_pc=0x0c07052eu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070530;
P_0c070530: /* original f959, guest PC 0x0c070530 */
if(!s->budget--) { s->failed_pc=0x0c070530u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070532;
P_0c070532: /* original fa58, guest PC 0x0c070532 */
if(!s->budget--) { s->failed_pc=0x0c070532u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c070534;
P_0c070534: /* original f35c, guest PC 0x0c070534 */
if(!s->budget--) { s->failed_pc=0x0c070534u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c070536;
P_0c070536: /* original f382, guest PC 0x0c070536 */
if(!s->budget--) { s->failed_pc=0x0c070536u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c070538;
P_0c070538: /* original f20c, guest PC 0x0c070538 */
if(!s->budget--) { s->failed_pc=0x0c070538u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c07053a;
P_0c07053a: /* original f2a2, guest PC 0x0c07053a */
if(!s->budget--) { s->failed_pc=0x0c07053au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c07053c;
P_0c07053c: /* original f16c, guest PC 0x0c07053c */
if(!s->budget--) { s->failed_pc=0x0c07053cu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c07053e;
P_0c07053e: /* original f192, guest PC 0x0c07053e */
if(!s->budget--) { s->failed_pc=0x0c07053eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c070540;
P_0c070540: /* original f34d, guest PC 0x0c070540 */
if(!s->budget--) { s->failed_pc=0x0c070540u; return 0; }
fr[3]^=0x80000000u;
goto P_0c070542;
P_0c070542: /* original f39e, guest PC 0x0c070542 */
if(!s->budget--) { s->failed_pc=0x0c070542u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070544;
P_0c070544: /* original f24d, guest PC 0x0c070544 */
if(!s->budget--) { s->failed_pc=0x0c070544u; return 0; }
fr[2]^=0x80000000u;
goto P_0c070546;
P_0c070546: /* original f06c, guest PC 0x0c070546 */
if(!s->budget--) { s->failed_pc=0x0c070546u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c070548;
P_0c070548: /* original f28e, guest PC 0x0c070548 */
if(!s->budget--) { s->failed_pc=0x0c070548u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c07054a;
P_0c07054a: /* original f14d, guest PC 0x0c07054a */
if(!s->budget--) { s->failed_pc=0x0c07054au; return 0; }
fr[1]^=0x80000000u;
goto P_0c07054c;
P_0c07054c: /* original f05c, guest PC 0x0c07054c */
if(!s->budget--) { s->failed_pc=0x0c07054cu; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c07054e;
P_0c07054e: /* original f1ae, guest PC 0x0c07054e */
if(!s->budget--) { s->failed_pc=0x0c07054eu; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c070550;
P_0c070550: /* original f08d, guest PC 0x0c070550 */
if(!s->budget--) { s->failed_pc=0x0c070550u; return 0; }
fr[0]=0;
goto P_0c070552;
P_0c070552: /* original f0ed, guest PC 0x0c070552 */
if(!s->budget--) { s->failed_pc=0x0c070552u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070554;
P_0c070554: /* original f03c, guest PC 0x0c070554 */
if(!s->budget--) { s->failed_pc=0x0c070554u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070556;
P_0c070556: /* original f06d, guest PC 0x0c070556 */
if(!s->budget--) { s->failed_pc=0x0c070556u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070558;
P_0c070558: /* original ff05, guest PC 0x0c070558 */
if(!s->budget--) { s->failed_pc=0x0c070558u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[0]))!=0);
goto P_0c07055a;
P_0c07055a: /* original e010, guest PC 0x0c07055a */
if(!s->budget--) { s->failed_pc=0x0c07055au; return 0; }
r[0]=0x00000010u;
goto P_0c07055c;
P_0c07055c: /* original 8d03, guest PC 0x0c07055c */
if(!s->budget--) { s->failed_pc=0x0c07055cu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c070566; }
goto P_0c070560;
P_0c07055e: /* original ff07, guest PC 0x0c07055e */
if(!s->budget--) { s->failed_pc=0x0c07055eu; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c070560;
P_0c070560: /* original d303, guest PC 0x0c070560 */
if(!s->budget--) { s->failed_pc=0x0c070560u; return 0; }
r[3]=read(ram,0x0c070570u,4);
goto P_0c070562;
P_0c070562: /* original 432b, guest PC 0x0c070562 */
if(!s->budget--) { s->failed_pc=0x0c070562u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070564: /* original 0009, guest PC 0x0c070564 */
if(!s->budget--) { s->failed_pc=0x0c070564u; return 0; }
goto P_0c070566;
P_0c070566: /* original 64f3, guest PC 0x0c070566 */
if(!s->budget--) { s->failed_pc=0x0c070566u; return 0; }
r[4]=r[15];
goto P_0c070568;
P_0c070568: /* original 7444, guest PC 0x0c070568 */
if(!s->budget--) { s->failed_pc=0x0c070568u; return 0; }
r[4]+=0x00000044u;
goto P_0c07056a;
P_0c07056a: /* original 65b3, guest PC 0x0c07056a */
if(!s->budget--) { s->failed_pc=0x0c07056au; return 0; }
r[5]=r[11];
goto P_0c07056c;
P_0c07056c: /* original a002, guest PC 0x0c07056c */
if(!s->budget--) { s->failed_pc=0x0c07056cu; return 0; }
goto P_0c070574;
P_0c07056e: /* original 0009, guest PC 0x0c07056e */
if(!s->budget--) { s->failed_pc=0x0c07056eu; return 0; }
return vf3_matrix_family(0x0c070570u,s,ram);
P_0c070574: /* original f049, guest PC 0x0c070574 */
if(!s->budget--) { s->failed_pc=0x0c070574u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070576;
P_0c070576: /* original f149, guest PC 0x0c070576 */
if(!s->budget--) { s->failed_pc=0x0c070576u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070578;
P_0c070578: /* original f249, guest PC 0x0c070578 */
if(!s->budget--) { s->failed_pc=0x0c070578u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07057a;
P_0c07057a: /* original f38d, guest PC 0x0c07057a */
if(!s->budget--) { s->failed_pc=0x0c07057au; return 0; }
fr[3]=0;
goto P_0c07057c;
P_0c07057c: /* original f459, guest PC 0x0c07057c */
if(!s->budget--) { s->failed_pc=0x0c07057cu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07057e;
P_0c07057e: /* original f559, guest PC 0x0c07057e */
if(!s->budget--) { s->failed_pc=0x0c07057eu; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070580;
P_0c070580: /* original f659, guest PC 0x0c070580 */
if(!s->budget--) { s->failed_pc=0x0c070580u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070582;
P_0c070582: /* original f78d, guest PC 0x0c070582 */
if(!s->budget--) { s->failed_pc=0x0c070582u; return 0; }
fr[7]=0;
goto P_0c070584;
P_0c070584: /* original f4ed, guest PC 0x0c070584 */
if(!s->budget--) { s->failed_pc=0x0c070584u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c070586;
P_0c070586: /* original f07c, guest PC 0x0c070586 */
if(!s->budget--) { s->failed_pc=0x0c070586u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c070588;
P_0c070588: /* original f38d, guest PC 0x0c070588 */
if(!s->budget--) { s->failed_pc=0x0c070588u; return 0; }
fr[3]=0;
goto P_0c07058a;
P_0c07058a: /* original f40c, guest PC 0x0c07058a */
if(!s->budget--) { s->failed_pc=0x0c07058au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c07058c;
P_0c07058c: /* original f345, guest PC 0x0c07058c */
if(!s->budget--) { s->failed_pc=0x0c07058cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c07058e;
P_0c07058e: /* original 8902, guest PC 0x0c07058e */
if(!s->budget--) { s->failed_pc=0x0c07058eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070596; }
goto P_0c070590;
P_0c070590: /* original d307, guest PC 0x0c070590 */
if(!s->budget--) { s->failed_pc=0x0c070590u; return 0; }
r[3]=read(ram,0x0c0705b0u,4);
goto P_0c070592;
P_0c070592: /* original 432b, guest PC 0x0c070592 */
if(!s->budget--) { s->failed_pc=0x0c070592u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070594: /* original 0009, guest PC 0x0c070594 */
if(!s->budget--) { s->failed_pc=0x0c070594u; return 0; }
goto P_0c070596;
P_0c070596: /* original ffc5, guest PC 0x0c070596 */
if(!s->budget--) { s->failed_pc=0x0c070596u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c070598;
P_0c070598: /* original 8902, guest PC 0x0c070598 */
if(!s->budget--) { s->failed_pc=0x0c070598u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0705a0; }
goto P_0c07059a;
P_0c07059a: /* original d206, guest PC 0x0c07059a */
if(!s->budget--) { s->failed_pc=0x0c07059au; return 0; }
r[2]=read(ram,0x0c0705b4u,4);
goto P_0c07059c;
P_0c07059c: /* original 422b, guest PC 0x0c07059c */
if(!s->budget--) { s->failed_pc=0x0c07059cu; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c07059e: /* original 0009, guest PC 0x0c07059e */
if(!s->budget--) { s->failed_pc=0x0c07059eu; return 0; }
goto P_0c0705a0;
P_0c0705a0: /* original 64f3, guest PC 0x0c0705a0 */
if(!s->budget--) { s->failed_pc=0x0c0705a0u; return 0; }
r[4]=r[15];
goto P_0c0705a2;
P_0c0705a2: /* original 65f3, guest PC 0x0c0705a2 */
if(!s->budget--) { s->failed_pc=0x0c0705a2u; return 0; }
r[5]=r[15];
goto P_0c0705a4;
P_0c0705a4: /* original 7444, guest PC 0x0c0705a4 */
if(!s->budget--) { s->failed_pc=0x0c0705a4u; return 0; }
r[4]+=0x00000044u;
goto P_0c0705a6;
P_0c0705a6: /* original f4fc, guest PC 0x0c0705a6 */
if(!s->budget--) { s->failed_pc=0x0c0705a6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0705a8;
P_0c0705a8: /* original 7544, guest PC 0x0c0705a8 */
if(!s->budget--) { s->failed_pc=0x0c0705a8u; return 0; }
r[5]+=0x00000044u;
goto P_0c0705aa;
P_0c0705aa: /* original a005, guest PC 0x0c0705aa */
if(!s->budget--) { s->failed_pc=0x0c0705aau; return 0; }
goto P_0c0705b8;
P_0c0705ac: /* original 0009, guest PC 0x0c0705ac */
if(!s->budget--) { s->failed_pc=0x0c0705acu; return 0; }
return vf3_matrix_family(0x0c0705aeu,s,ram);
P_0c0705b8: /* original f059, guest PC 0x0c0705b8 */
if(!s->budget--) { s->failed_pc=0x0c0705b8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0705ba;
P_0c0705ba: /* original f159, guest PC 0x0c0705ba */
if(!s->budget--) { s->failed_pc=0x0c0705bau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0705bc;
P_0c0705bc: /* original f259, guest PC 0x0c0705bc */
if(!s->budget--) { s->failed_pc=0x0c0705bcu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0705be;
P_0c0705be: /* original f38d, guest PC 0x0c0705be */
if(!s->budget--) { s->failed_pc=0x0c0705beu; return 0; }
fr[3]=0;
goto P_0c0705c0;
P_0c0705c0: /* original f0ed, guest PC 0x0c0705c0 */
if(!s->budget--) { s->failed_pc=0x0c0705c0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0705c2;
P_0c0705c2: /* original f37d, guest PC 0x0c0705c2 */
if(!s->budget--) { s->failed_pc=0x0c0705c2u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0705c4;
P_0c0705c4: /* original f342, guest PC 0x0c0705c4 */
if(!s->budget--) { s->failed_pc=0x0c0705c4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0705c6;
P_0c0705c6: /* original 740c, guest PC 0x0c0705c6 */
if(!s->budget--) { s->failed_pc=0x0c0705c6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0705c8;
P_0c0705c8: /* original f232, guest PC 0x0c0705c8 */
if(!s->budget--) { s->failed_pc=0x0c0705c8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0705ca;
P_0c0705ca: /* original f132, guest PC 0x0c0705ca */
if(!s->budget--) { s->failed_pc=0x0c0705cau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0705cc;
P_0c0705cc: /* original f032, guest PC 0x0c0705cc */
if(!s->budget--) { s->failed_pc=0x0c0705ccu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0705ce;
P_0c0705ce: /* original f42b, guest PC 0x0c0705ce */
if(!s->budget--) { s->failed_pc=0x0c0705ceu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0705d0;
P_0c0705d0: /* original f41b, guest PC 0x0c0705d0 */
if(!s->budget--) { s->failed_pc=0x0c0705d0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0705d2;
P_0c0705d2: /* original f40b, guest PC 0x0c0705d2 */
if(!s->budget--) { s->failed_pc=0x0c0705d2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0705d4;
P_0c0705d4: /* original d206, guest PC 0x0c0705d4 */
if(!s->budget--) { s->failed_pc=0x0c0705d4u; return 0; }
r[2]=read(ram,0x0c0705f0u,4);
goto P_0c0705d6;
P_0c0705d6: /* original 422b, guest PC 0x0c0705d6 */
if(!s->budget--) { s->failed_pc=0x0c0705d6u; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0705d8: /* original 0009, guest PC 0x0c0705d8 */
if(!s->budget--) { s->failed_pc=0x0c0705d8u; return 0; }
return vf3_matrix_family(0x0c0705dau,s,ram);
P_0c0709ce: /* original f40b, guest PC 0x0c0709ce */
if(!s->budget--) { s->failed_pc=0x0c0709ceu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0709d0;
P_0c0709d0: /* original 65f3, guest PC 0x0c0709d0 */
if(!s->budget--) { s->failed_pc=0x0c0709d0u; return 0; }
r[5]=r[15];
goto P_0c0709d2;
P_0c0709d2: /* original 64f3, guest PC 0x0c0709d2 */
if(!s->budget--) { s->failed_pc=0x0c0709d2u; return 0; }
r[4]=r[15];
goto P_0c0709d4;
P_0c0709d4: /* original 66f3, guest PC 0x0c0709d4 */
if(!s->budget--) { s->failed_pc=0x0c0709d4u; return 0; }
r[6]=r[15];
goto P_0c0709d6;
P_0c0709d6: /* original 7438, guest PC 0x0c0709d6 */
if(!s->budget--) { s->failed_pc=0x0c0709d6u; return 0; }
r[4]+=0x00000038u;
goto P_0c0709d8;
P_0c0709d8: /* original 7638, guest PC 0x0c0709d8 */
if(!s->budget--) { s->failed_pc=0x0c0709d8u; return 0; }
r[6]+=0x00000038u;
goto P_0c0709da;
P_0c0709da: /* original 7544, guest PC 0x0c0709da */
if(!s->budget--) { s->failed_pc=0x0c0709dau; return 0; }
r[5]+=0x00000044u;
goto P_0c0709dc;
P_0c0709dc: /* original f059, guest PC 0x0c0709dc */
if(!s->budget--) { s->failed_pc=0x0c0709dcu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0709de;
P_0c0709de: /* original f369, guest PC 0x0c0709de */
if(!s->budget--) { s->failed_pc=0x0c0709deu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0709e0;
P_0c0709e0: /* original f159, guest PC 0x0c0709e0 */
if(!s->budget--) { s->failed_pc=0x0c0709e0u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0709e2;
P_0c0709e2: /* original f469, guest PC 0x0c0709e2 */
if(!s->budget--) { s->failed_pc=0x0c0709e2u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0709e4;
P_0c0709e4: /* original f031, guest PC 0x0c0709e4 */
if(!s->budget--) { s->failed_pc=0x0c0709e4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0709e6;
P_0c0709e6: /* original f258, guest PC 0x0c0709e6 */
if(!s->budget--) { s->failed_pc=0x0c0709e6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0709e8;
P_0c0709e8: /* original f568, guest PC 0x0c0709e8 */
if(!s->budget--) { s->failed_pc=0x0c0709e8u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0709ea;
P_0c0709ea: /* original f141, guest PC 0x0c0709ea */
if(!s->budget--) { s->failed_pc=0x0c0709eau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0709ec;
P_0c0709ec: /* original f251, guest PC 0x0c0709ec */
if(!s->budget--) { s->failed_pc=0x0c0709ecu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0709ee;
P_0c0709ee: /* original 7408, guest PC 0x0c0709ee */
if(!s->budget--) { s->failed_pc=0x0c0709eeu; return 0; }
r[4]+=0x00000008u;
goto P_0c0709f0;
P_0c0709f0: /* original f42a, guest PC 0x0c0709f0 */
if(!s->budget--) { s->failed_pc=0x0c0709f0u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0709f2;
P_0c0709f2: /* original f41b, guest PC 0x0c0709f2 */
if(!s->budget--) { s->failed_pc=0x0c0709f2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0709f4;
P_0c0709f4: /* original f40b, guest PC 0x0c0709f4 */
if(!s->budget--) { s->failed_pc=0x0c0709f4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0709f6;
P_0c0709f6: /* original 0009, guest PC 0x0c0709f6 */
if(!s->budget--) { s->failed_pc=0x0c0709f6u; return 0; }
goto P_0c0709f8;
P_0c0709f8: /* original f4fc, guest PC 0x0c0709f8 */
if(!s->budget--) { s->failed_pc=0x0c0709f8u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0709fa;
P_0c0709fa: /* original f4c1, guest PC 0x0c0709fa */
if(!s->budget--) { s->failed_pc=0x0c0709fau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[12],r[18],'-');
goto P_0c0709fc;
P_0c0709fc: /* original 64f3, guest PC 0x0c0709fc */
if(!s->budget--) { s->failed_pc=0x0c0709fcu; return 0; }
r[4]=r[15];
goto P_0c0709fe;
P_0c0709fe: /* original 65f3, guest PC 0x0c0709fe */
if(!s->budget--) { s->failed_pc=0x0c0709feu; return 0; }
r[5]=r[15];
goto P_0c070a00;
P_0c070a00: /* original 7438, guest PC 0x0c070a00 */
if(!s->budget--) { s->failed_pc=0x0c070a00u; return 0; }
r[4]+=0x00000038u;
goto P_0c070a02;
P_0c070a02: /* original 7538, guest PC 0x0c070a02 */
if(!s->budget--) { s->failed_pc=0x0c070a02u; return 0; }
r[5]+=0x00000038u;
goto P_0c070a04;
P_0c070a04: /* original f059, guest PC 0x0c070a04 */
if(!s->budget--) { s->failed_pc=0x0c070a04u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a06;
P_0c070a06: /* original f159, guest PC 0x0c070a06 */
if(!s->budget--) { s->failed_pc=0x0c070a06u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a08;
P_0c070a08: /* original f259, guest PC 0x0c070a08 */
if(!s->budget--) { s->failed_pc=0x0c070a08u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a0a;
P_0c070a0a: /* original f38d, guest PC 0x0c070a0a */
if(!s->budget--) { s->failed_pc=0x0c070a0au; return 0; }
fr[3]=0;
goto P_0c070a0c;
P_0c070a0c: /* original f0ed, guest PC 0x0c070a0c */
if(!s->budget--) { s->failed_pc=0x0c070a0cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070a0e;
P_0c070a0e: /* original f37d, guest PC 0x0c070a0e */
if(!s->budget--) { s->failed_pc=0x0c070a0eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070a10;
P_0c070a10: /* original f342, guest PC 0x0c070a10 */
if(!s->budget--) { s->failed_pc=0x0c070a10u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070a12;
P_0c070a12: /* original 740c, guest PC 0x0c070a12 */
if(!s->budget--) { s->failed_pc=0x0c070a12u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070a14;
P_0c070a14: /* original f232, guest PC 0x0c070a14 */
if(!s->budget--) { s->failed_pc=0x0c070a14u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070a16;
P_0c070a16: /* original f132, guest PC 0x0c070a16 */
if(!s->budget--) { s->failed_pc=0x0c070a16u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070a18;
P_0c070a18: /* original f032, guest PC 0x0c070a18 */
if(!s->budget--) { s->failed_pc=0x0c070a18u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070a1a;
P_0c070a1a: /* original f42b, guest PC 0x0c070a1a */
if(!s->budget--) { s->failed_pc=0x0c070a1au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070a1c;
P_0c070a1c: /* original f41b, guest PC 0x0c070a1c */
if(!s->budget--) { s->failed_pc=0x0c070a1cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070a1e;
P_0c070a1e: /* original f40b, guest PC 0x0c070a1e */
if(!s->budget--) { s->failed_pc=0x0c070a1eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070a20;
P_0c070a20: /* original 64f3, guest PC 0x0c070a20 */
if(!s->budget--) { s->failed_pc=0x0c070a20u; return 0; }
r[4]=r[15];
goto P_0c070a22;
P_0c070a22: /* original 65f3, guest PC 0x0c070a22 */
if(!s->budget--) { s->failed_pc=0x0c070a22u; return 0; }
r[5]=r[15];
goto P_0c070a24;
P_0c070a24: /* original 7444, guest PC 0x0c070a24 */
if(!s->budget--) { s->failed_pc=0x0c070a24u; return 0; }
r[4]+=0x00000044u;
goto P_0c070a26;
P_0c070a26: /* original 7538, guest PC 0x0c070a26 */
if(!s->budget--) { s->failed_pc=0x0c070a26u; return 0; }
r[5]+=0x00000038u;
goto P_0c070a28;
P_0c070a28: /* original f049, guest PC 0x0c070a28 */
if(!s->budget--) { s->failed_pc=0x0c070a28u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070a2a;
P_0c070a2a: /* original f359, guest PC 0x0c070a2a */
if(!s->budget--) { s->failed_pc=0x0c070a2au; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a2c;
P_0c070a2c: /* original f149, guest PC 0x0c070a2c */
if(!s->budget--) { s->failed_pc=0x0c070a2cu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070a2e;
P_0c070a2e: /* original f459, guest PC 0x0c070a2e */
if(!s->budget--) { s->failed_pc=0x0c070a2eu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a30;
P_0c070a30: /* original f249, guest PC 0x0c070a30 */
if(!s->budget--) { s->failed_pc=0x0c070a30u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070a32;
P_0c070a32: /* original f559, guest PC 0x0c070a32 */
if(!s->budget--) { s->failed_pc=0x0c070a32u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a34;
P_0c070a34: /* original f030, guest PC 0x0c070a34 */
if(!s->budget--) { s->failed_pc=0x0c070a34u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070a36;
P_0c070a36: /* original f250, guest PC 0x0c070a36 */
if(!s->budget--) { s->failed_pc=0x0c070a36u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070a38;
P_0c070a38: /* original f140, guest PC 0x0c070a38 */
if(!s->budget--) { s->failed_pc=0x0c070a38u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070a3a;
P_0c070a3a: /* original f42b, guest PC 0x0c070a3a */
if(!s->budget--) { s->failed_pc=0x0c070a3au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070a3c;
P_0c070a3c: /* original f41b, guest PC 0x0c070a3c */
if(!s->budget--) { s->failed_pc=0x0c070a3cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070a3e;
P_0c070a3e: /* original f40b, guest PC 0x0c070a3e */
if(!s->budget--) { s->failed_pc=0x0c070a3eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070a40;
P_0c070a40: /* original 65f3, guest PC 0x0c070a40 */
if(!s->budget--) { s->failed_pc=0x0c070a40u; return 0; }
r[5]=r[15];
goto P_0c070a42;
P_0c070a42: /* original 64e3, guest PC 0x0c070a42 */
if(!s->budget--) { s->failed_pc=0x0c070a42u; return 0; }
r[4]=r[14];
goto P_0c070a44;
P_0c070a44: /* original 7544, guest PC 0x0c070a44 */
if(!s->budget--) { s->failed_pc=0x0c070a44u; return 0; }
r[5]+=0x00000044u;
goto P_0c070a46;
P_0c070a46: /* original 66a3, guest PC 0x0c070a46 */
if(!s->budget--) { s->failed_pc=0x0c070a46u; return 0; }
r[6]=r[10];
goto P_0c070a48;
P_0c070a48: /* original f059, guest PC 0x0c070a48 */
if(!s->budget--) { s->failed_pc=0x0c070a48u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a4a;
P_0c070a4a: /* original f369, guest PC 0x0c070a4a */
if(!s->budget--) { s->failed_pc=0x0c070a4au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070a4c;
P_0c070a4c: /* original f159, guest PC 0x0c070a4c */
if(!s->budget--) { s->failed_pc=0x0c070a4cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a4e;
P_0c070a4e: /* original f469, guest PC 0x0c070a4e */
if(!s->budget--) { s->failed_pc=0x0c070a4eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070a50;
P_0c070a50: /* original f259, guest PC 0x0c070a50 */
if(!s->budget--) { s->failed_pc=0x0c070a50u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a52;
P_0c070a52: /* original f569, guest PC 0x0c070a52 */
if(!s->budget--) { s->failed_pc=0x0c070a52u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070a54;
P_0c070a54: /* original 740c, guest PC 0x0c070a54 */
if(!s->budget--) { s->failed_pc=0x0c070a54u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070a56;
P_0c070a56: /* original f030, guest PC 0x0c070a56 */
if(!s->budget--) { s->failed_pc=0x0c070a56u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070a58;
P_0c070a58: /* original f250, guest PC 0x0c070a58 */
if(!s->budget--) { s->failed_pc=0x0c070a58u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070a5a;
P_0c070a5a: /* original f140, guest PC 0x0c070a5a */
if(!s->budget--) { s->failed_pc=0x0c070a5au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070a5c;
P_0c070a5c: /* original f42b, guest PC 0x0c070a5c */
if(!s->budget--) { s->failed_pc=0x0c070a5cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070a5e;
P_0c070a5e: /* original f41b, guest PC 0x0c070a5e */
if(!s->budget--) { s->failed_pc=0x0c070a5eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070a60;
P_0c070a60: /* original f40b, guest PC 0x0c070a60 */
if(!s->budget--) { s->failed_pc=0x0c070a60u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070a62;
P_0c070a62: /* original 0009, guest PC 0x0c070a62 */
if(!s->budget--) { s->failed_pc=0x0c070a62u; return 0; }
goto P_0c070a64;
P_0c070a64: /* original 64f3, guest PC 0x0c070a64 */
if(!s->budget--) { s->failed_pc=0x0c070a64u; return 0; }
r[4]=r[15];
goto P_0c070a66;
P_0c070a66: /* original 7444, guest PC 0x0c070a66 */
if(!s->budget--) { s->failed_pc=0x0c070a66u; return 0; }
r[4]+=0x00000044u;
goto P_0c070a68;
P_0c070a68: /* original 6693, guest PC 0x0c070a68 */
if(!s->budget--) { s->failed_pc=0x0c070a68u; return 0; }
r[6]=r[9];
goto P_0c070a6a;
P_0c070a6a: /* original 65e3, guest PC 0x0c070a6a */
if(!s->budget--) { s->failed_pc=0x0c070a6au; return 0; }
r[5]=r[14];
goto P_0c070a6c;
P_0c070a6c: /* original f059, guest PC 0x0c070a6c */
if(!s->budget--) { s->failed_pc=0x0c070a6cu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a6e;
P_0c070a6e: /* original f369, guest PC 0x0c070a6e */
if(!s->budget--) { s->failed_pc=0x0c070a6eu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070a70;
P_0c070a70: /* original f159, guest PC 0x0c070a70 */
if(!s->budget--) { s->failed_pc=0x0c070a70u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070a72;
P_0c070a72: /* original f469, guest PC 0x0c070a72 */
if(!s->budget--) { s->failed_pc=0x0c070a72u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070a74;
P_0c070a74: /* original f031, guest PC 0x0c070a74 */
if(!s->budget--) { s->failed_pc=0x0c070a74u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070a76;
P_0c070a76: /* original f258, guest PC 0x0c070a76 */
if(!s->budget--) { s->failed_pc=0x0c070a76u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070a78;
P_0c070a78: /* original f568, guest PC 0x0c070a78 */
if(!s->budget--) { s->failed_pc=0x0c070a78u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070a7a;
P_0c070a7a: /* original f141, guest PC 0x0c070a7a */
if(!s->budget--) { s->failed_pc=0x0c070a7au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070a7c;
P_0c070a7c: /* original f251, guest PC 0x0c070a7c */
if(!s->budget--) { s->failed_pc=0x0c070a7cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070a7e;
P_0c070a7e: /* original 7408, guest PC 0x0c070a7e */
if(!s->budget--) { s->failed_pc=0x0c070a7eu; return 0; }
r[4]+=0x00000008u;
goto P_0c070a80;
P_0c070a80: /* original f42a, guest PC 0x0c070a80 */
if(!s->budget--) { s->failed_pc=0x0c070a80u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070a82;
P_0c070a82: /* original f41b, guest PC 0x0c070a82 */
if(!s->budget--) { s->failed_pc=0x0c070a82u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070a84;
P_0c070a84: /* original f40b, guest PC 0x0c070a84 */
if(!s->budget--) { s->failed_pc=0x0c070a84u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070a86;
P_0c070a86: /* original 0009, guest PC 0x0c070a86 */
if(!s->budget--) { s->failed_pc=0x0c070a86u; return 0; }
goto P_0c070a88;
P_0c070a88: /* original 64f3, guest PC 0x0c070a88 */
if(!s->budget--) { s->failed_pc=0x0c070a88u; return 0; }
r[4]=r[15];
goto P_0c070a8a;
P_0c070a8a: /* original 7444, guest PC 0x0c070a8a */
if(!s->budget--) { s->failed_pc=0x0c070a8au; return 0; }
r[4]+=0x00000044u;
goto P_0c070a8c;
P_0c070a8c: /* original f049, guest PC 0x0c070a8c */
if(!s->budget--) { s->failed_pc=0x0c070a8cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070a8e;
P_0c070a8e: /* original f149, guest PC 0x0c070a8e */
if(!s->budget--) { s->failed_pc=0x0c070a8eu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070a90;
P_0c070a90: /* original f249, guest PC 0x0c070a90 */
if(!s->budget--) { s->failed_pc=0x0c070a90u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070a92;
P_0c070a92: /* original f38d, guest PC 0x0c070a92 */
if(!s->budget--) { s->failed_pc=0x0c070a92u; return 0; }
fr[3]=0;
goto P_0c070a94;
P_0c070a94: /* original f0ed, guest PC 0x0c070a94 */
if(!s->budget--) { s->failed_pc=0x0c070a94u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070a96;
P_0c070a96: /* original f03c, guest PC 0x0c070a96 */
if(!s->budget--) { s->failed_pc=0x0c070a96u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070a98;
P_0c070a98: /* original f06d, guest PC 0x0c070a98 */
if(!s->budget--) { s->failed_pc=0x0c070a98u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070a9a;
P_0c070a9a: /* original 0009, guest PC 0x0c070a9a */
if(!s->budget--) { s->failed_pc=0x0c070a9au; return 0; }
goto P_0c070a9c;
P_0c070a9c: /* original f38d, guest PC 0x0c070a9c */
if(!s->budget--) { s->failed_pc=0x0c070a9cu; return 0; }
fr[3]=0;
goto P_0c070a9e;
P_0c070a9e: /* original f035, guest PC 0x0c070a9e */
if(!s->budget--) { s->failed_pc=0x0c070a9eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c070aa0;
P_0c070aa0: /* original e020, guest PC 0x0c070aa0 */
if(!s->budget--) { s->failed_pc=0x0c070aa0u; return 0; }
r[0]=0x00000020u;
goto P_0c070aa2;
P_0c070aa2: /* original 8d03, guest PC 0x0c070aa2 */
if(!s->budget--) { s->failed_pc=0x0c070aa2u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c070aac; }
goto P_0c070aa6;
P_0c070aa4: /* original ff07, guest PC 0x0c070aa4 */
if(!s->budget--) { s->failed_pc=0x0c070aa4u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c070aa6;
P_0c070aa6: /* original d304, guest PC 0x0c070aa6 */
if(!s->budget--) { s->failed_pc=0x0c070aa6u; return 0; }
r[3]=read(ram,0x0c070ab8u,4);
goto P_0c070aa8;
P_0c070aa8: /* original 432b, guest PC 0x0c070aa8 */
if(!s->budget--) { s->failed_pc=0x0c070aa8u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070aaa: /* original 0009, guest PC 0x0c070aaa */
if(!s->budget--) { s->failed_pc=0x0c070aaau; return 0; }
goto P_0c070aac;
P_0c070aac: /* original 64f3, guest PC 0x0c070aac */
if(!s->budget--) { s->failed_pc=0x0c070aacu; return 0; }
r[4]=r[15];
goto P_0c070aae;
P_0c070aae: /* original 7444, guest PC 0x0c070aae */
if(!s->budget--) { s->failed_pc=0x0c070aaeu; return 0; }
r[4]+=0x00000044u;
goto P_0c070ab0;
P_0c070ab0: /* original 65c3, guest PC 0x0c070ab0 */
if(!s->budget--) { s->failed_pc=0x0c070ab0u; return 0; }
r[5]=r[12];
goto P_0c070ab2;
P_0c070ab2: /* original a003, guest PC 0x0c070ab2 */
if(!s->budget--) { s->failed_pc=0x0c070ab2u; return 0; }
goto P_0c070abc;
P_0c070ab4: /* original 0009, guest PC 0x0c070ab4 */
if(!s->budget--) { s->failed_pc=0x0c070ab4u; return 0; }
return vf3_matrix_family(0x0c070ab6u,s,ram);
P_0c070abc: /* original f049, guest PC 0x0c070abc */
if(!s->budget--) { s->failed_pc=0x0c070abcu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070abe;
P_0c070abe: /* original f549, guest PC 0x0c070abe */
if(!s->budget--) { s->failed_pc=0x0c070abeu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070ac0;
P_0c070ac0: /* original f648, guest PC 0x0c070ac0 */
if(!s->budget--) { s->failed_pc=0x0c070ac0u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c070ac2;
P_0c070ac2: /* original f859, guest PC 0x0c070ac2 */
if(!s->budget--) { s->failed_pc=0x0c070ac2u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070ac4;
P_0c070ac4: /* original f959, guest PC 0x0c070ac4 */
if(!s->budget--) { s->failed_pc=0x0c070ac4u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070ac6;
P_0c070ac6: /* original fa58, guest PC 0x0c070ac6 */
if(!s->budget--) { s->failed_pc=0x0c070ac6u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c070ac8;
P_0c070ac8: /* original f35c, guest PC 0x0c070ac8 */
if(!s->budget--) { s->failed_pc=0x0c070ac8u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c070aca;
P_0c070aca: /* original f382, guest PC 0x0c070aca */
if(!s->budget--) { s->failed_pc=0x0c070acau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c070acc;
P_0c070acc: /* original f20c, guest PC 0x0c070acc */
if(!s->budget--) { s->failed_pc=0x0c070accu; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c070ace;
P_0c070ace: /* original f2a2, guest PC 0x0c070ace */
if(!s->budget--) { s->failed_pc=0x0c070aceu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c070ad0;
P_0c070ad0: /* original f16c, guest PC 0x0c070ad0 */
if(!s->budget--) { s->failed_pc=0x0c070ad0u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c070ad2;
P_0c070ad2: /* original f192, guest PC 0x0c070ad2 */
if(!s->budget--) { s->failed_pc=0x0c070ad2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c070ad4;
P_0c070ad4: /* original f34d, guest PC 0x0c070ad4 */
if(!s->budget--) { s->failed_pc=0x0c070ad4u; return 0; }
fr[3]^=0x80000000u;
goto P_0c070ad6;
P_0c070ad6: /* original f39e, guest PC 0x0c070ad6 */
if(!s->budget--) { s->failed_pc=0x0c070ad6u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070ad8;
P_0c070ad8: /* original f24d, guest PC 0x0c070ad8 */
if(!s->budget--) { s->failed_pc=0x0c070ad8u; return 0; }
fr[2]^=0x80000000u;
goto P_0c070ada;
P_0c070ada: /* original f06c, guest PC 0x0c070ada */
if(!s->budget--) { s->failed_pc=0x0c070adau; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c070adc;
P_0c070adc: /* original f28e, guest PC 0x0c070adc */
if(!s->budget--) { s->failed_pc=0x0c070adcu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c070ade;
P_0c070ade: /* original f14d, guest PC 0x0c070ade */
if(!s->budget--) { s->failed_pc=0x0c070adeu; return 0; }
fr[1]^=0x80000000u;
goto P_0c070ae0;
P_0c070ae0: /* original f05c, guest PC 0x0c070ae0 */
if(!s->budget--) { s->failed_pc=0x0c070ae0u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c070ae2;
P_0c070ae2: /* original f1ae, guest PC 0x0c070ae2 */
if(!s->budget--) { s->failed_pc=0x0c070ae2u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c070ae4;
P_0c070ae4: /* original f08d, guest PC 0x0c070ae4 */
if(!s->budget--) { s->failed_pc=0x0c070ae4u; return 0; }
fr[0]=0;
goto P_0c070ae6;
P_0c070ae6: /* original f0ed, guest PC 0x0c070ae6 */
if(!s->budget--) { s->failed_pc=0x0c070ae6u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070ae8;
P_0c070ae8: /* original f03c, guest PC 0x0c070ae8 */
if(!s->budget--) { s->failed_pc=0x0c070ae8u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070aea;
P_0c070aea: /* original f06d, guest PC 0x0c070aea */
if(!s->budget--) { s->failed_pc=0x0c070aeau; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070aec;
P_0c070aec: /* original fc0c, guest PC 0x0c070aec */
if(!s->budget--) { s->failed_pc=0x0c070aecu; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c070aee;
P_0c070aee: /* original ffc5, guest PC 0x0c070aee */
if(!s->budget--) { s->failed_pc=0x0c070aeeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c070af0;
P_0c070af0: /* original 8902, guest PC 0x0c070af0 */
if(!s->budget--) { s->failed_pc=0x0c070af0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070af8; }
goto P_0c070af2;
P_0c070af2: /* original d304, guest PC 0x0c070af2 */
if(!s->budget--) { s->failed_pc=0x0c070af2u; return 0; }
r[3]=read(ram,0x0c070b04u,4);
goto P_0c070af4;
P_0c070af4: /* original 432b, guest PC 0x0c070af4 */
if(!s->budget--) { s->failed_pc=0x0c070af4u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070af6: /* original 0009, guest PC 0x0c070af6 */
if(!s->budget--) { s->failed_pc=0x0c070af6u; return 0; }
goto P_0c070af8;
P_0c070af8: /* original 64f3, guest PC 0x0c070af8 */
if(!s->budget--) { s->failed_pc=0x0c070af8u; return 0; }
r[4]=r[15];
goto P_0c070afa;
P_0c070afa: /* original 7444, guest PC 0x0c070afa */
if(!s->budget--) { s->failed_pc=0x0c070afau; return 0; }
r[4]+=0x00000044u;
goto P_0c070afc;
P_0c070afc: /* original 65c3, guest PC 0x0c070afc */
if(!s->budget--) { s->failed_pc=0x0c070afcu; return 0; }
r[5]=r[12];
goto P_0c070afe;
P_0c070afe: /* original a003, guest PC 0x0c070afe */
if(!s->budget--) { s->failed_pc=0x0c070afeu; return 0; }
goto P_0c070b08;
P_0c070b00: /* original 0009, guest PC 0x0c070b00 */
if(!s->budget--) { s->failed_pc=0x0c070b00u; return 0; }
return vf3_matrix_family(0x0c070b02u,s,ram);
P_0c070b08: /* original f049, guest PC 0x0c070b08 */
if(!s->budget--) { s->failed_pc=0x0c070b08u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070b0a;
P_0c070b0a: /* original f149, guest PC 0x0c070b0a */
if(!s->budget--) { s->failed_pc=0x0c070b0au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070b0c;
P_0c070b0c: /* original f249, guest PC 0x0c070b0c */
if(!s->budget--) { s->failed_pc=0x0c070b0cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070b0e;
P_0c070b0e: /* original f38d, guest PC 0x0c070b0e */
if(!s->budget--) { s->failed_pc=0x0c070b0eu; return 0; }
fr[3]=0;
goto P_0c070b10;
P_0c070b10: /* original f459, guest PC 0x0c070b10 */
if(!s->budget--) { s->failed_pc=0x0c070b10u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b12;
P_0c070b12: /* original f559, guest PC 0x0c070b12 */
if(!s->budget--) { s->failed_pc=0x0c070b12u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b14;
P_0c070b14: /* original f659, guest PC 0x0c070b14 */
if(!s->budget--) { s->failed_pc=0x0c070b14u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b16;
P_0c070b16: /* original f78d, guest PC 0x0c070b16 */
if(!s->budget--) { s->failed_pc=0x0c070b16u; return 0; }
fr[7]=0;
goto P_0c070b18;
P_0c070b18: /* original f4ed, guest PC 0x0c070b18 */
if(!s->budget--) { s->failed_pc=0x0c070b18u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c070b1a;
P_0c070b1a: /* original f07c, guest PC 0x0c070b1a */
if(!s->budget--) { s->failed_pc=0x0c070b1au; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c070b1c;
P_0c070b1c: /* original f38d, guest PC 0x0c070b1c */
if(!s->budget--) { s->failed_pc=0x0c070b1cu; return 0; }
fr[3]=0;
goto P_0c070b1e;
P_0c070b1e: /* original f40c, guest PC 0x0c070b1e */
if(!s->budget--) { s->failed_pc=0x0c070b1eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c070b20;
P_0c070b20: /* original f345, guest PC 0x0c070b20 */
if(!s->budget--) { s->failed_pc=0x0c070b20u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c070b22;
P_0c070b22: /* original 8902, guest PC 0x0c070b22 */
if(!s->budget--) { s->failed_pc=0x0c070b22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070b2a; }
goto P_0c070b24;
P_0c070b24: /* original d308, guest PC 0x0c070b24 */
if(!s->budget--) { s->failed_pc=0x0c070b24u; return 0; }
r[3]=read(ram,0x0c070b48u,4);
goto P_0c070b26;
P_0c070b26: /* original 432b, guest PC 0x0c070b26 */
if(!s->budget--) { s->failed_pc=0x0c070b26u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070b28: /* original 0009, guest PC 0x0c070b28 */
if(!s->budget--) { s->failed_pc=0x0c070b28u; return 0; }
goto P_0c070b2a;
P_0c070b2a: /* original e020, guest PC 0x0c070b2a */
if(!s->budget--) { s->failed_pc=0x0c070b2au; return 0; }
r[0]=0x00000020u;
goto P_0c070b2c;
P_0c070b2c: /* original f3f6, guest PC 0x0c070b2c */
if(!s->budget--) { s->failed_pc=0x0c070b2cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c070b2e;
P_0c070b2e: /* original ff35, guest PC 0x0c070b2e */
if(!s->budget--) { s->failed_pc=0x0c070b2eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c070b30;
P_0c070b30: /* original 8902, guest PC 0x0c070b30 */
if(!s->budget--) { s->failed_pc=0x0c070b30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070b38; }
goto P_0c070b32;
P_0c070b32: /* original d306, guest PC 0x0c070b32 */
if(!s->budget--) { s->failed_pc=0x0c070b32u; return 0; }
r[3]=read(ram,0x0c070b4cu,4);
goto P_0c070b34;
P_0c070b34: /* original 432b, guest PC 0x0c070b34 */
if(!s->budget--) { s->failed_pc=0x0c070b34u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070b36: /* original 0009, guest PC 0x0c070b36 */
if(!s->budget--) { s->failed_pc=0x0c070b36u; return 0; }
goto P_0c070b38;
P_0c070b38: /* original 64f3, guest PC 0x0c070b38 */
if(!s->budget--) { s->failed_pc=0x0c070b38u; return 0; }
r[4]=r[15];
goto P_0c070b3a;
P_0c070b3a: /* original 65f3, guest PC 0x0c070b3a */
if(!s->budget--) { s->failed_pc=0x0c070b3au; return 0; }
r[5]=r[15];
goto P_0c070b3c;
P_0c070b3c: /* original 7444, guest PC 0x0c070b3c */
if(!s->budget--) { s->failed_pc=0x0c070b3cu; return 0; }
r[4]+=0x00000044u;
goto P_0c070b3e;
P_0c070b3e: /* original f4fc, guest PC 0x0c070b3e */
if(!s->budget--) { s->failed_pc=0x0c070b3eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070b40;
P_0c070b40: /* original 7544, guest PC 0x0c070b40 */
if(!s->budget--) { s->failed_pc=0x0c070b40u; return 0; }
r[5]+=0x00000044u;
goto P_0c070b42;
P_0c070b42: /* original a005, guest PC 0x0c070b42 */
if(!s->budget--) { s->failed_pc=0x0c070b42u; return 0; }
goto P_0c070b50;
P_0c070b44: /* original 0009, guest PC 0x0c070b44 */
if(!s->budget--) { s->failed_pc=0x0c070b44u; return 0; }
return vf3_matrix_family(0x0c070b46u,s,ram);
P_0c070b50: /* original f059, guest PC 0x0c070b50 */
if(!s->budget--) { s->failed_pc=0x0c070b50u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b52;
P_0c070b52: /* original f159, guest PC 0x0c070b52 */
if(!s->budget--) { s->failed_pc=0x0c070b52u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b54;
P_0c070b54: /* original f259, guest PC 0x0c070b54 */
if(!s->budget--) { s->failed_pc=0x0c070b54u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070b56;
P_0c070b56: /* original f38d, guest PC 0x0c070b56 */
if(!s->budget--) { s->failed_pc=0x0c070b56u; return 0; }
fr[3]=0;
goto P_0c070b58;
P_0c070b58: /* original f0ed, guest PC 0x0c070b58 */
if(!s->budget--) { s->failed_pc=0x0c070b58u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070b5a;
P_0c070b5a: /* original f37d, guest PC 0x0c070b5a */
if(!s->budget--) { s->failed_pc=0x0c070b5au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070b5c;
P_0c070b5c: /* original f342, guest PC 0x0c070b5c */
if(!s->budget--) { s->failed_pc=0x0c070b5cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070b5e;
P_0c070b5e: /* original 740c, guest PC 0x0c070b5e */
if(!s->budget--) { s->failed_pc=0x0c070b5eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c070b60;
P_0c070b60: /* original f232, guest PC 0x0c070b60 */
if(!s->budget--) { s->failed_pc=0x0c070b60u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070b62;
P_0c070b62: /* original f132, guest PC 0x0c070b62 */
if(!s->budget--) { s->failed_pc=0x0c070b62u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070b64;
P_0c070b64: /* original f032, guest PC 0x0c070b64 */
if(!s->budget--) { s->failed_pc=0x0c070b64u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070b66;
P_0c070b66: /* original f42b, guest PC 0x0c070b66 */
if(!s->budget--) { s->failed_pc=0x0c070b66u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070b68;
P_0c070b68: /* original f41b, guest PC 0x0c070b68 */
if(!s->budget--) { s->failed_pc=0x0c070b68u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070b6a;
P_0c070b6a: /* original f40b, guest PC 0x0c070b6a */
if(!s->budget--) { s->failed_pc=0x0c070b6au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070b6c;
P_0c070b6c: /* original d306, guest PC 0x0c070b6c */
if(!s->budget--) { s->failed_pc=0x0c070b6cu; return 0; }
r[3]=read(ram,0x0c070b88u,4);
goto P_0c070b6e;
P_0c070b6e: /* original 432b, guest PC 0x0c070b6e */
if(!s->budget--) { s->failed_pc=0x0c070b6eu; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070b70: /* original 0009, guest PC 0x0c070b70 */
if(!s->budget--) { s->failed_pc=0x0c070b70u; return 0; }
return vf3_matrix_family(0x0c070b72u,s,ram);
P_0c070ba2: /* original f40b, guest PC 0x0c070ba2 */
if(!s->budget--) { s->failed_pc=0x0c070ba2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070ba4;
P_0c070ba4: /* original 65f3, guest PC 0x0c070ba4 */
if(!s->budget--) { s->failed_pc=0x0c070ba4u; return 0; }
r[5]=r[15];
goto P_0c070ba6;
P_0c070ba6: /* original 64f3, guest PC 0x0c070ba6 */
if(!s->budget--) { s->failed_pc=0x0c070ba6u; return 0; }
r[4]=r[15];
goto P_0c070ba8;
P_0c070ba8: /* original 66f3, guest PC 0x0c070ba8 */
if(!s->budget--) { s->failed_pc=0x0c070ba8u; return 0; }
r[6]=r[15];
goto P_0c070baa;
P_0c070baa: /* original 7438, guest PC 0x0c070baa */
if(!s->budget--) { s->failed_pc=0x0c070baau; return 0; }
r[4]+=0x00000038u;
goto P_0c070bac;
P_0c070bac: /* original 7638, guest PC 0x0c070bac */
if(!s->budget--) { s->failed_pc=0x0c070bacu; return 0; }
r[6]+=0x00000038u;
goto P_0c070bae;
P_0c070bae: /* original 7544, guest PC 0x0c070bae */
if(!s->budget--) { s->failed_pc=0x0c070baeu; return 0; }
r[5]+=0x00000044u;
goto P_0c070bb0;
P_0c070bb0: /* original f059, guest PC 0x0c070bb0 */
if(!s->budget--) { s->failed_pc=0x0c070bb0u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070bb2;
P_0c070bb2: /* original f369, guest PC 0x0c070bb2 */
if(!s->budget--) { s->failed_pc=0x0c070bb2u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070bb4;
P_0c070bb4: /* original f159, guest PC 0x0c070bb4 */
if(!s->budget--) { s->failed_pc=0x0c070bb4u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070bb6;
P_0c070bb6: /* original f469, guest PC 0x0c070bb6 */
if(!s->budget--) { s->failed_pc=0x0c070bb6u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070bb8;
P_0c070bb8: /* original f031, guest PC 0x0c070bb8 */
if(!s->budget--) { s->failed_pc=0x0c070bb8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070bba;
P_0c070bba: /* original f258, guest PC 0x0c070bba */
if(!s->budget--) { s->failed_pc=0x0c070bbau; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070bbc;
P_0c070bbc: /* original f568, guest PC 0x0c070bbc */
if(!s->budget--) { s->failed_pc=0x0c070bbcu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070bbe;
P_0c070bbe: /* original f141, guest PC 0x0c070bbe */
if(!s->budget--) { s->failed_pc=0x0c070bbeu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070bc0;
P_0c070bc0: /* original f251, guest PC 0x0c070bc0 */
if(!s->budget--) { s->failed_pc=0x0c070bc0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070bc2;
P_0c070bc2: /* original 7408, guest PC 0x0c070bc2 */
if(!s->budget--) { s->failed_pc=0x0c070bc2u; return 0; }
r[4]+=0x00000008u;
goto P_0c070bc4;
P_0c070bc4: /* original f42a, guest PC 0x0c070bc4 */
if(!s->budget--) { s->failed_pc=0x0c070bc4u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070bc6;
P_0c070bc6: /* original f41b, guest PC 0x0c070bc6 */
if(!s->budget--) { s->failed_pc=0x0c070bc6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070bc8;
P_0c070bc8: /* original f40b, guest PC 0x0c070bc8 */
if(!s->budget--) { s->failed_pc=0x0c070bc8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070bca;
P_0c070bca: /* original 0009, guest PC 0x0c070bca */
if(!s->budget--) { s->failed_pc=0x0c070bcau; return 0; }
goto P_0c070bcc;
P_0c070bcc: /* original f4fc, guest PC 0x0c070bcc */
if(!s->budget--) { s->failed_pc=0x0c070bccu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070bce;
P_0c070bce: /* original f4c1, guest PC 0x0c070bce */
if(!s->budget--) { s->failed_pc=0x0c070bceu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[12],r[18],'-');
goto P_0c070bd0;
P_0c070bd0: /* original 64f3, guest PC 0x0c070bd0 */
if(!s->budget--) { s->failed_pc=0x0c070bd0u; return 0; }
r[4]=r[15];
goto P_0c070bd2;
P_0c070bd2: /* original 65f3, guest PC 0x0c070bd2 */
if(!s->budget--) { s->failed_pc=0x0c070bd2u; return 0; }
r[5]=r[15];
goto P_0c070bd4;
P_0c070bd4: /* original 7438, guest PC 0x0c070bd4 */
if(!s->budget--) { s->failed_pc=0x0c070bd4u; return 0; }
r[4]+=0x00000038u;
goto P_0c070bd6;
P_0c070bd6: /* original 7538, guest PC 0x0c070bd6 */
if(!s->budget--) { s->failed_pc=0x0c070bd6u; return 0; }
r[5]+=0x00000038u;
goto P_0c070bd8;
P_0c070bd8: /* original f059, guest PC 0x0c070bd8 */
if(!s->budget--) { s->failed_pc=0x0c070bd8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070bda;
P_0c070bda: /* original f159, guest PC 0x0c070bda */
if(!s->budget--) { s->failed_pc=0x0c070bdau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070bdc;
P_0c070bdc: /* original f259, guest PC 0x0c070bdc */
if(!s->budget--) { s->failed_pc=0x0c070bdcu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070bde;
P_0c070bde: /* original f38d, guest PC 0x0c070bde */
if(!s->budget--) { s->failed_pc=0x0c070bdeu; return 0; }
fr[3]=0;
goto P_0c070be0;
P_0c070be0: /* original f0ed, guest PC 0x0c070be0 */
if(!s->budget--) { s->failed_pc=0x0c070be0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070be2;
P_0c070be2: /* original f37d, guest PC 0x0c070be2 */
if(!s->budget--) { s->failed_pc=0x0c070be2u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070be4;
P_0c070be4: /* original f342, guest PC 0x0c070be4 */
if(!s->budget--) { s->failed_pc=0x0c070be4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070be6;
P_0c070be6: /* original 740c, guest PC 0x0c070be6 */
if(!s->budget--) { s->failed_pc=0x0c070be6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070be8;
P_0c070be8: /* original f232, guest PC 0x0c070be8 */
if(!s->budget--) { s->failed_pc=0x0c070be8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070bea;
P_0c070bea: /* original f132, guest PC 0x0c070bea */
if(!s->budget--) { s->failed_pc=0x0c070beau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070bec;
P_0c070bec: /* original f032, guest PC 0x0c070bec */
if(!s->budget--) { s->failed_pc=0x0c070becu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070bee;
P_0c070bee: /* original f42b, guest PC 0x0c070bee */
if(!s->budget--) { s->failed_pc=0x0c070beeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070bf0;
P_0c070bf0: /* original f41b, guest PC 0x0c070bf0 */
if(!s->budget--) { s->failed_pc=0x0c070bf0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070bf2;
P_0c070bf2: /* original f40b, guest PC 0x0c070bf2 */
if(!s->budget--) { s->failed_pc=0x0c070bf2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070bf4;
P_0c070bf4: /* original 64f3, guest PC 0x0c070bf4 */
if(!s->budget--) { s->failed_pc=0x0c070bf4u; return 0; }
r[4]=r[15];
goto P_0c070bf6;
P_0c070bf6: /* original 65f3, guest PC 0x0c070bf6 */
if(!s->budget--) { s->failed_pc=0x0c070bf6u; return 0; }
r[5]=r[15];
goto P_0c070bf8;
P_0c070bf8: /* original 7444, guest PC 0x0c070bf8 */
if(!s->budget--) { s->failed_pc=0x0c070bf8u; return 0; }
r[4]+=0x00000044u;
goto P_0c070bfa;
P_0c070bfa: /* original 7538, guest PC 0x0c070bfa */
if(!s->budget--) { s->failed_pc=0x0c070bfau; return 0; }
r[5]+=0x00000038u;
goto P_0c070bfc;
P_0c070bfc: /* original f049, guest PC 0x0c070bfc */
if(!s->budget--) { s->failed_pc=0x0c070bfcu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070bfe;
P_0c070bfe: /* original f359, guest PC 0x0c070bfe */
if(!s->budget--) { s->failed_pc=0x0c070bfeu; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c00;
P_0c070c00: /* original f149, guest PC 0x0c070c00 */
if(!s->budget--) { s->failed_pc=0x0c070c00u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070c02;
P_0c070c02: /* original f459, guest PC 0x0c070c02 */
if(!s->budget--) { s->failed_pc=0x0c070c02u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c04;
P_0c070c04: /* original f249, guest PC 0x0c070c04 */
if(!s->budget--) { s->failed_pc=0x0c070c04u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070c06;
P_0c070c06: /* original f559, guest PC 0x0c070c06 */
if(!s->budget--) { s->failed_pc=0x0c070c06u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c08;
P_0c070c08: /* original f030, guest PC 0x0c070c08 */
if(!s->budget--) { s->failed_pc=0x0c070c08u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070c0a;
P_0c070c0a: /* original f250, guest PC 0x0c070c0a */
if(!s->budget--) { s->failed_pc=0x0c070c0au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070c0c;
P_0c070c0c: /* original f140, guest PC 0x0c070c0c */
if(!s->budget--) { s->failed_pc=0x0c070c0cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070c0e;
P_0c070c0e: /* original f42b, guest PC 0x0c070c0e */
if(!s->budget--) { s->failed_pc=0x0c070c0eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070c10;
P_0c070c10: /* original f41b, guest PC 0x0c070c10 */
if(!s->budget--) { s->failed_pc=0x0c070c10u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070c12;
P_0c070c12: /* original f40b, guest PC 0x0c070c12 */
if(!s->budget--) { s->failed_pc=0x0c070c12u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070c14;
P_0c070c14: /* original 65f3, guest PC 0x0c070c14 */
if(!s->budget--) { s->failed_pc=0x0c070c14u; return 0; }
r[5]=r[15];
goto P_0c070c16;
P_0c070c16: /* original 64e3, guest PC 0x0c070c16 */
if(!s->budget--) { s->failed_pc=0x0c070c16u; return 0; }
r[4]=r[14];
goto P_0c070c18;
P_0c070c18: /* original 7544, guest PC 0x0c070c18 */
if(!s->budget--) { s->failed_pc=0x0c070c18u; return 0; }
r[5]+=0x00000044u;
goto P_0c070c1a;
P_0c070c1a: /* original 6693, guest PC 0x0c070c1a */
if(!s->budget--) { s->failed_pc=0x0c070c1au; return 0; }
r[6]=r[9];
goto P_0c070c1c;
P_0c070c1c: /* original f059, guest PC 0x0c070c1c */
if(!s->budget--) { s->failed_pc=0x0c070c1cu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c1e;
P_0c070c1e: /* original f369, guest PC 0x0c070c1e */
if(!s->budget--) { s->failed_pc=0x0c070c1eu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070c20;
P_0c070c20: /* original f159, guest PC 0x0c070c20 */
if(!s->budget--) { s->failed_pc=0x0c070c20u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c22;
P_0c070c22: /* original f469, guest PC 0x0c070c22 */
if(!s->budget--) { s->failed_pc=0x0c070c22u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070c24;
P_0c070c24: /* original f259, guest PC 0x0c070c24 */
if(!s->budget--) { s->failed_pc=0x0c070c24u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c26;
P_0c070c26: /* original f569, guest PC 0x0c070c26 */
if(!s->budget--) { s->failed_pc=0x0c070c26u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070c28;
P_0c070c28: /* original 740c, guest PC 0x0c070c28 */
if(!s->budget--) { s->failed_pc=0x0c070c28u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070c2a;
P_0c070c2a: /* original f030, guest PC 0x0c070c2a */
if(!s->budget--) { s->failed_pc=0x0c070c2au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070c2c;
P_0c070c2c: /* original f250, guest PC 0x0c070c2c */
if(!s->budget--) { s->failed_pc=0x0c070c2cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070c2e;
P_0c070c2e: /* original f140, guest PC 0x0c070c2e */
if(!s->budget--) { s->failed_pc=0x0c070c2eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070c30;
P_0c070c30: /* original f42b, guest PC 0x0c070c30 */
if(!s->budget--) { s->failed_pc=0x0c070c30u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070c32;
P_0c070c32: /* original f41b, guest PC 0x0c070c32 */
if(!s->budget--) { s->failed_pc=0x0c070c32u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070c34;
P_0c070c34: /* original f40b, guest PC 0x0c070c34 */
if(!s->budget--) { s->failed_pc=0x0c070c34u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070c36;
P_0c070c36: /* original 0009, guest PC 0x0c070c36 */
if(!s->budget--) { s->failed_pc=0x0c070c36u; return 0; }
goto P_0c070c38;
P_0c070c38: /* original 64f3, guest PC 0x0c070c38 */
if(!s->budget--) { s->failed_pc=0x0c070c38u; return 0; }
r[4]=r[15];
goto P_0c070c3a;
P_0c070c3a: /* original 742c, guest PC 0x0c070c3a */
if(!s->budget--) { s->failed_pc=0x0c070c3au; return 0; }
r[4]+=0x0000002cu;
goto P_0c070c3c;
P_0c070c3c: /* original 6683, guest PC 0x0c070c3c */
if(!s->budget--) { s->failed_pc=0x0c070c3cu; return 0; }
r[6]=r[8];
goto P_0c070c3e;
P_0c070c3e: /* original 65e3, guest PC 0x0c070c3e */
if(!s->budget--) { s->failed_pc=0x0c070c3eu; return 0; }
r[5]=r[14];
goto P_0c070c40;
P_0c070c40: /* original f059, guest PC 0x0c070c40 */
if(!s->budget--) { s->failed_pc=0x0c070c40u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c42;
P_0c070c42: /* original f369, guest PC 0x0c070c42 */
if(!s->budget--) { s->failed_pc=0x0c070c42u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070c44;
P_0c070c44: /* original f159, guest PC 0x0c070c44 */
if(!s->budget--) { s->failed_pc=0x0c070c44u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c46;
P_0c070c46: /* original f469, guest PC 0x0c070c46 */
if(!s->budget--) { s->failed_pc=0x0c070c46u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070c48;
P_0c070c48: /* original f031, guest PC 0x0c070c48 */
if(!s->budget--) { s->failed_pc=0x0c070c48u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070c4a;
P_0c070c4a: /* original f258, guest PC 0x0c070c4a */
if(!s->budget--) { s->failed_pc=0x0c070c4au; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070c4c;
P_0c070c4c: /* original f568, guest PC 0x0c070c4c */
if(!s->budget--) { s->failed_pc=0x0c070c4cu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070c4e;
P_0c070c4e: /* original f141, guest PC 0x0c070c4e */
if(!s->budget--) { s->failed_pc=0x0c070c4eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070c50;
P_0c070c50: /* original f251, guest PC 0x0c070c50 */
if(!s->budget--) { s->failed_pc=0x0c070c50u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070c52;
P_0c070c52: /* original 7408, guest PC 0x0c070c52 */
if(!s->budget--) { s->failed_pc=0x0c070c52u; return 0; }
r[4]+=0x00000008u;
goto P_0c070c54;
P_0c070c54: /* original f42a, guest PC 0x0c070c54 */
if(!s->budget--) { s->failed_pc=0x0c070c54u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070c56;
P_0c070c56: /* original f41b, guest PC 0x0c070c56 */
if(!s->budget--) { s->failed_pc=0x0c070c56u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070c58;
P_0c070c58: /* original f40b, guest PC 0x0c070c58 */
if(!s->budget--) { s->failed_pc=0x0c070c58u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070c5a;
P_0c070c5a: /* original 0009, guest PC 0x0c070c5a */
if(!s->budget--) { s->failed_pc=0x0c070c5au; return 0; }
goto P_0c070c5c;
P_0c070c5c: /* original 64f3, guest PC 0x0c070c5c */
if(!s->budget--) { s->failed_pc=0x0c070c5cu; return 0; }
r[4]=r[15];
goto P_0c070c5e;
P_0c070c5e: /* original 742c, guest PC 0x0c070c5e */
if(!s->budget--) { s->failed_pc=0x0c070c5eu; return 0; }
r[4]+=0x0000002cu;
goto P_0c070c60;
P_0c070c60: /* original f049, guest PC 0x0c070c60 */
if(!s->budget--) { s->failed_pc=0x0c070c60u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070c62;
P_0c070c62: /* original f149, guest PC 0x0c070c62 */
if(!s->budget--) { s->failed_pc=0x0c070c62u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070c64;
P_0c070c64: /* original f249, guest PC 0x0c070c64 */
if(!s->budget--) { s->failed_pc=0x0c070c64u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070c66;
P_0c070c66: /* original f38d, guest PC 0x0c070c66 */
if(!s->budget--) { s->failed_pc=0x0c070c66u; return 0; }
fr[3]=0;
goto P_0c070c68;
P_0c070c68: /* original f0ed, guest PC 0x0c070c68 */
if(!s->budget--) { s->failed_pc=0x0c070c68u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070c6a;
P_0c070c6a: /* original f03c, guest PC 0x0c070c6a */
if(!s->budget--) { s->failed_pc=0x0c070c6au; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070c6c;
P_0c070c6c: /* original f06d, guest PC 0x0c070c6c */
if(!s->budget--) { s->failed_pc=0x0c070c6cu; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070c6e;
P_0c070c6e: /* original 0009, guest PC 0x0c070c6e */
if(!s->budget--) { s->failed_pc=0x0c070c6eu; return 0; }
goto P_0c070c70;
P_0c070c70: /* original f38d, guest PC 0x0c070c70 */
if(!s->budget--) { s->failed_pc=0x0c070c70u; return 0; }
fr[3]=0;
goto P_0c070c72;
P_0c070c72: /* original f035, guest PC 0x0c070c72 */
if(!s->budget--) { s->failed_pc=0x0c070c72u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c070c74;
P_0c070c74: /* original 8902, guest PC 0x0c070c74 */
if(!s->budget--) { s->failed_pc=0x0c070c74u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070c7c; }
goto P_0c070c76;
P_0c070c76: /* original d305, guest PC 0x0c070c76 */
if(!s->budget--) { s->failed_pc=0x0c070c76u; return 0; }
r[3]=read(ram,0x0c070c8cu,4);
goto P_0c070c78;
P_0c070c78: /* original 432b, guest PC 0x0c070c78 */
if(!s->budget--) { s->failed_pc=0x0c070c78u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070c7a: /* original 0009, guest PC 0x0c070c7a */
if(!s->budget--) { s->failed_pc=0x0c070c7au; return 0; }
goto P_0c070c7c;
P_0c070c7c: /* original 64f3, guest PC 0x0c070c7c */
if(!s->budget--) { s->failed_pc=0x0c070c7cu; return 0; }
r[4]=r[15];
goto P_0c070c7e;
P_0c070c7e: /* original 65f3, guest PC 0x0c070c7e */
if(!s->budget--) { s->failed_pc=0x0c070c7eu; return 0; }
r[5]=r[15];
goto P_0c070c80;
P_0c070c80: /* original 742c, guest PC 0x0c070c80 */
if(!s->budget--) { s->failed_pc=0x0c070c80u; return 0; }
r[4]+=0x0000002cu;
goto P_0c070c82;
P_0c070c82: /* original f4dc, guest PC 0x0c070c82 */
if(!s->budget--) { s->failed_pc=0x0c070c82u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c070c84;
P_0c070c84: /* original 752c, guest PC 0x0c070c84 */
if(!s->budget--) { s->failed_pc=0x0c070c84u; return 0; }
r[5]+=0x0000002cu;
goto P_0c070c86;
P_0c070c86: /* original a003, guest PC 0x0c070c86 */
if(!s->budget--) { s->failed_pc=0x0c070c86u; return 0; }
goto P_0c070c90;
P_0c070c88: /* original 0009, guest PC 0x0c070c88 */
if(!s->budget--) { s->failed_pc=0x0c070c88u; return 0; }
return vf3_matrix_family(0x0c070c8au,s,ram);
P_0c070c90: /* original f059, guest PC 0x0c070c90 */
if(!s->budget--) { s->failed_pc=0x0c070c90u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c92;
P_0c070c92: /* original f159, guest PC 0x0c070c92 */
if(!s->budget--) { s->failed_pc=0x0c070c92u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c94;
P_0c070c94: /* original f259, guest PC 0x0c070c94 */
if(!s->budget--) { s->failed_pc=0x0c070c94u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070c96;
P_0c070c96: /* original f38d, guest PC 0x0c070c96 */
if(!s->budget--) { s->failed_pc=0x0c070c96u; return 0; }
fr[3]=0;
goto P_0c070c98;
P_0c070c98: /* original f0ed, guest PC 0x0c070c98 */
if(!s->budget--) { s->failed_pc=0x0c070c98u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070c9a;
P_0c070c9a: /* original f37d, guest PC 0x0c070c9a */
if(!s->budget--) { s->failed_pc=0x0c070c9au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070c9c;
P_0c070c9c: /* original f342, guest PC 0x0c070c9c */
if(!s->budget--) { s->failed_pc=0x0c070c9cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070c9e;
P_0c070c9e: /* original 740c, guest PC 0x0c070c9e */
if(!s->budget--) { s->failed_pc=0x0c070c9eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c070ca0;
P_0c070ca0: /* original f232, guest PC 0x0c070ca0 */
if(!s->budget--) { s->failed_pc=0x0c070ca0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070ca2;
P_0c070ca2: /* original f132, guest PC 0x0c070ca2 */
if(!s->budget--) { s->failed_pc=0x0c070ca2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070ca4;
P_0c070ca4: /* original f032, guest PC 0x0c070ca4 */
if(!s->budget--) { s->failed_pc=0x0c070ca4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070ca6;
P_0c070ca6: /* original f42b, guest PC 0x0c070ca6 */
if(!s->budget--) { s->failed_pc=0x0c070ca6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070ca8;
P_0c070ca8: /* original f41b, guest PC 0x0c070ca8 */
if(!s->budget--) { s->failed_pc=0x0c070ca8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070caa;
P_0c070caa: /* original f40b, guest PC 0x0c070caa */
if(!s->budget--) { s->failed_pc=0x0c070caau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070cac;
P_0c070cac: /* original 66f3, guest PC 0x0c070cac */
if(!s->budget--) { s->failed_pc=0x0c070cacu; return 0; }
r[6]=r[15];
goto P_0c070cae;
P_0c070cae: /* original 64e3, guest PC 0x0c070cae */
if(!s->budget--) { s->failed_pc=0x0c070caeu; return 0; }
r[4]=r[14];
goto P_0c070cb0;
P_0c070cb0: /* original 6583, guest PC 0x0c070cb0 */
if(!s->budget--) { s->failed_pc=0x0c070cb0u; return 0; }
r[5]=r[8];
goto P_0c070cb2;
P_0c070cb2: /* original 762c, guest PC 0x0c070cb2 */
if(!s->budget--) { s->failed_pc=0x0c070cb2u; return 0; }
r[6]+=0x0000002cu;
goto P_0c070cb4;
P_0c070cb4: /* original f059, guest PC 0x0c070cb4 */
if(!s->budget--) { s->failed_pc=0x0c070cb4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070cb6;
P_0c070cb6: /* original f369, guest PC 0x0c070cb6 */
if(!s->budget--) { s->failed_pc=0x0c070cb6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070cb8;
P_0c070cb8: /* original f159, guest PC 0x0c070cb8 */
if(!s->budget--) { s->failed_pc=0x0c070cb8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070cba;
P_0c070cba: /* original f469, guest PC 0x0c070cba */
if(!s->budget--) { s->failed_pc=0x0c070cbau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070cbc;
P_0c070cbc: /* original f259, guest PC 0x0c070cbc */
if(!s->budget--) { s->failed_pc=0x0c070cbcu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070cbe;
P_0c070cbe: /* original f569, guest PC 0x0c070cbe */
if(!s->budget--) { s->failed_pc=0x0c070cbeu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070cc0;
P_0c070cc0: /* original 740c, guest PC 0x0c070cc0 */
if(!s->budget--) { s->failed_pc=0x0c070cc0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070cc2;
P_0c070cc2: /* original f030, guest PC 0x0c070cc2 */
if(!s->budget--) { s->failed_pc=0x0c070cc2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070cc4;
P_0c070cc4: /* original f250, guest PC 0x0c070cc4 */
if(!s->budget--) { s->failed_pc=0x0c070cc4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070cc6;
P_0c070cc6: /* original f140, guest PC 0x0c070cc6 */
if(!s->budget--) { s->failed_pc=0x0c070cc6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070cc8;
P_0c070cc8: /* original f42b, guest PC 0x0c070cc8 */
if(!s->budget--) { s->failed_pc=0x0c070cc8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070cca;
P_0c070cca: /* original f41b, guest PC 0x0c070cca */
if(!s->budget--) { s->failed_pc=0x0c070ccau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070ccc;
P_0c070ccc: /* original f40b, guest PC 0x0c070ccc */
if(!s->budget--) { s->failed_pc=0x0c070cccu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070cce;
P_0c070cce: /* original 0009, guest PC 0x0c070cce */
if(!s->budget--) { s->failed_pc=0x0c070cceu; return 0; }
goto P_0c070cd0;
P_0c070cd0: /* original 64f3, guest PC 0x0c070cd0 */
if(!s->budget--) { s->failed_pc=0x0c070cd0u; return 0; }
r[4]=r[15];
goto P_0c070cd2;
P_0c070cd2: /* original 7444, guest PC 0x0c070cd2 */
if(!s->budget--) { s->failed_pc=0x0c070cd2u; return 0; }
r[4]+=0x00000044u;
goto P_0c070cd4;
P_0c070cd4: /* original 66a3, guest PC 0x0c070cd4 */
if(!s->budget--) { s->failed_pc=0x0c070cd4u; return 0; }
r[6]=r[10];
goto P_0c070cd6;
P_0c070cd6: /* original 65d3, guest PC 0x0c070cd6 */
if(!s->budget--) { s->failed_pc=0x0c070cd6u; return 0; }
r[5]=r[13];
goto P_0c070cd8;
P_0c070cd8: /* original f059, guest PC 0x0c070cd8 */
if(!s->budget--) { s->failed_pc=0x0c070cd8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070cda;
P_0c070cda: /* original f369, guest PC 0x0c070cda */
if(!s->budget--) { s->failed_pc=0x0c070cdau; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070cdc;
P_0c070cdc: /* original f159, guest PC 0x0c070cdc */
if(!s->budget--) { s->failed_pc=0x0c070cdcu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070cde;
P_0c070cde: /* original f469, guest PC 0x0c070cde */
if(!s->budget--) { s->failed_pc=0x0c070cdeu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070ce0;
P_0c070ce0: /* original f031, guest PC 0x0c070ce0 */
if(!s->budget--) { s->failed_pc=0x0c070ce0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070ce2;
P_0c070ce2: /* original f258, guest PC 0x0c070ce2 */
if(!s->budget--) { s->failed_pc=0x0c070ce2u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070ce4;
P_0c070ce4: /* original f568, guest PC 0x0c070ce4 */
if(!s->budget--) { s->failed_pc=0x0c070ce4u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070ce6;
P_0c070ce6: /* original f141, guest PC 0x0c070ce6 */
if(!s->budget--) { s->failed_pc=0x0c070ce6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070ce8;
P_0c070ce8: /* original f251, guest PC 0x0c070ce8 */
if(!s->budget--) { s->failed_pc=0x0c070ce8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070cea;
P_0c070cea: /* original 7408, guest PC 0x0c070cea */
if(!s->budget--) { s->failed_pc=0x0c070ceau; return 0; }
r[4]+=0x00000008u;
goto P_0c070cec;
P_0c070cec: /* original f42a, guest PC 0x0c070cec */
if(!s->budget--) { s->failed_pc=0x0c070cecu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070cee;
P_0c070cee: /* original f41b, guest PC 0x0c070cee */
if(!s->budget--) { s->failed_pc=0x0c070ceeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070cf0;
P_0c070cf0: /* original f40b, guest PC 0x0c070cf0 */
if(!s->budget--) { s->failed_pc=0x0c070cf0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070cf2;
P_0c070cf2: /* original 0009, guest PC 0x0c070cf2 */
if(!s->budget--) { s->failed_pc=0x0c070cf2u; return 0; }
goto P_0c070cf4;
P_0c070cf4: /* original 64f3, guest PC 0x0c070cf4 */
if(!s->budget--) { s->failed_pc=0x0c070cf4u; return 0; }
r[4]=r[15];
goto P_0c070cf6;
P_0c070cf6: /* original 7444, guest PC 0x0c070cf6 */
if(!s->budget--) { s->failed_pc=0x0c070cf6u; return 0; }
r[4]+=0x00000044u;
goto P_0c070cf8;
P_0c070cf8: /* original f049, guest PC 0x0c070cf8 */
if(!s->budget--) { s->failed_pc=0x0c070cf8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070cfa;
P_0c070cfa: /* original f149, guest PC 0x0c070cfa */
if(!s->budget--) { s->failed_pc=0x0c070cfau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070cfc;
P_0c070cfc: /* original f249, guest PC 0x0c070cfc */
if(!s->budget--) { s->failed_pc=0x0c070cfcu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070cfe;
P_0c070cfe: /* original f38d, guest PC 0x0c070cfe */
if(!s->budget--) { s->failed_pc=0x0c070cfeu; return 0; }
fr[3]=0;
goto P_0c070d00;
P_0c070d00: /* original f0ed, guest PC 0x0c070d00 */
if(!s->budget--) { s->failed_pc=0x0c070d00u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070d02;
P_0c070d02: /* original f03c, guest PC 0x0c070d02 */
if(!s->budget--) { s->failed_pc=0x0c070d02u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070d04;
P_0c070d04: /* original f06d, guest PC 0x0c070d04 */
if(!s->budget--) { s->failed_pc=0x0c070d04u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070d06;
P_0c070d06: /* original 0009, guest PC 0x0c070d06 */
if(!s->budget--) { s->failed_pc=0x0c070d06u; return 0; }
goto P_0c070d08;
P_0c070d08: /* original f38d, guest PC 0x0c070d08 */
if(!s->budget--) { s->failed_pc=0x0c070d08u; return 0; }
fr[3]=0;
goto P_0c070d0a;
P_0c070d0a: /* original fc0c, guest PC 0x0c070d0a */
if(!s->budget--) { s->failed_pc=0x0c070d0au; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c070d0c;
P_0c070d0c: /* original fc35, guest PC 0x0c070d0c */
if(!s->budget--) { s->failed_pc=0x0c070d0cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[12])>as_float(fr[3]))!=0);
goto P_0c070d0e;
P_0c070d0e: /* original 8902, guest PC 0x0c070d0e */
if(!s->budget--) { s->failed_pc=0x0c070d0eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070d16; }
goto P_0c070d10;
P_0c070d10: /* original d303, guest PC 0x0c070d10 */
if(!s->budget--) { s->failed_pc=0x0c070d10u; return 0; }
r[3]=read(ram,0x0c070d20u,4);
goto P_0c070d12;
P_0c070d12: /* original 432b, guest PC 0x0c070d12 */
if(!s->budget--) { s->failed_pc=0x0c070d12u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070d14: /* original 0009, guest PC 0x0c070d14 */
if(!s->budget--) { s->failed_pc=0x0c070d14u; return 0; }
goto P_0c070d16;
P_0c070d16: /* original 64f3, guest PC 0x0c070d16 */
if(!s->budget--) { s->failed_pc=0x0c070d16u; return 0; }
r[4]=r[15];
goto P_0c070d18;
P_0c070d18: /* original 7444, guest PC 0x0c070d18 */
if(!s->budget--) { s->failed_pc=0x0c070d18u; return 0; }
r[4]+=0x00000044u;
goto P_0c070d1a;
P_0c070d1a: /* original 65b3, guest PC 0x0c070d1a */
if(!s->budget--) { s->failed_pc=0x0c070d1au; return 0; }
r[5]=r[11];
goto P_0c070d1c;
P_0c070d1c: /* original a002, guest PC 0x0c070d1c */
if(!s->budget--) { s->failed_pc=0x0c070d1cu; return 0; }
goto P_0c070d24;
P_0c070d1e: /* original 0009, guest PC 0x0c070d1e */
if(!s->budget--) { s->failed_pc=0x0c070d1eu; return 0; }
return vf3_matrix_family(0x0c070d20u,s,ram);
P_0c070d24: /* original f049, guest PC 0x0c070d24 */
if(!s->budget--) { s->failed_pc=0x0c070d24u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070d26;
P_0c070d26: /* original f549, guest PC 0x0c070d26 */
if(!s->budget--) { s->failed_pc=0x0c070d26u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070d28;
P_0c070d28: /* original f648, guest PC 0x0c070d28 */
if(!s->budget--) { s->failed_pc=0x0c070d28u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c070d2a;
P_0c070d2a: /* original f859, guest PC 0x0c070d2a */
if(!s->budget--) { s->failed_pc=0x0c070d2au; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070d2c;
P_0c070d2c: /* original f959, guest PC 0x0c070d2c */
if(!s->budget--) { s->failed_pc=0x0c070d2cu; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070d2e;
P_0c070d2e: /* original fa58, guest PC 0x0c070d2e */
if(!s->budget--) { s->failed_pc=0x0c070d2eu; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c070d30;
P_0c070d30: /* original f35c, guest PC 0x0c070d30 */
if(!s->budget--) { s->failed_pc=0x0c070d30u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c070d32;
P_0c070d32: /* original f382, guest PC 0x0c070d32 */
if(!s->budget--) { s->failed_pc=0x0c070d32u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c070d34;
P_0c070d34: /* original f20c, guest PC 0x0c070d34 */
if(!s->budget--) { s->failed_pc=0x0c070d34u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c070d36;
P_0c070d36: /* original f2a2, guest PC 0x0c070d36 */
if(!s->budget--) { s->failed_pc=0x0c070d36u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c070d38;
P_0c070d38: /* original f16c, guest PC 0x0c070d38 */
if(!s->budget--) { s->failed_pc=0x0c070d38u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c070d3a;
P_0c070d3a: /* original f192, guest PC 0x0c070d3a */
if(!s->budget--) { s->failed_pc=0x0c070d3au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c070d3c;
P_0c070d3c: /* original f34d, guest PC 0x0c070d3c */
if(!s->budget--) { s->failed_pc=0x0c070d3cu; return 0; }
fr[3]^=0x80000000u;
goto P_0c070d3e;
P_0c070d3e: /* original f39e, guest PC 0x0c070d3e */
if(!s->budget--) { s->failed_pc=0x0c070d3eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070d40;
P_0c070d40: /* original f24d, guest PC 0x0c070d40 */
if(!s->budget--) { s->failed_pc=0x0c070d40u; return 0; }
fr[2]^=0x80000000u;
goto P_0c070d42;
P_0c070d42: /* original f06c, guest PC 0x0c070d42 */
if(!s->budget--) { s->failed_pc=0x0c070d42u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c070d44;
P_0c070d44: /* original f28e, guest PC 0x0c070d44 */
if(!s->budget--) { s->failed_pc=0x0c070d44u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c070d46;
P_0c070d46: /* original f14d, guest PC 0x0c070d46 */
if(!s->budget--) { s->failed_pc=0x0c070d46u; return 0; }
fr[1]^=0x80000000u;
goto P_0c070d48;
P_0c070d48: /* original f05c, guest PC 0x0c070d48 */
if(!s->budget--) { s->failed_pc=0x0c070d48u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c070d4a;
P_0c070d4a: /* original f1ae, guest PC 0x0c070d4a */
if(!s->budget--) { s->failed_pc=0x0c070d4au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c070d4c;
P_0c070d4c: /* original f08d, guest PC 0x0c070d4c */
if(!s->budget--) { s->failed_pc=0x0c070d4cu; return 0; }
fr[0]=0;
goto P_0c070d4e;
P_0c070d4e: /* original f0ed, guest PC 0x0c070d4e */
if(!s->budget--) { s->failed_pc=0x0c070d4eu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070d50;
P_0c070d50: /* original f03c, guest PC 0x0c070d50 */
if(!s->budget--) { s->failed_pc=0x0c070d50u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070d52;
P_0c070d52: /* original f06d, guest PC 0x0c070d52 */
if(!s->budget--) { s->failed_pc=0x0c070d52u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070d54;
P_0c070d54: /* original ff05, guest PC 0x0c070d54 */
if(!s->budget--) { s->failed_pc=0x0c070d54u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[0]))!=0);
goto P_0c070d56;
P_0c070d56: /* original e01c, guest PC 0x0c070d56 */
if(!s->budget--) { s->failed_pc=0x0c070d56u; return 0; }
r[0]=0x0000001cu;
goto P_0c070d58;
P_0c070d58: /* original 8d03, guest PC 0x0c070d58 */
if(!s->budget--) { s->failed_pc=0x0c070d58u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c070d62; }
goto P_0c070d5c;
P_0c070d5a: /* original ff07, guest PC 0x0c070d5a */
if(!s->budget--) { s->failed_pc=0x0c070d5au; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c070d5c;
P_0c070d5c: /* original d303, guest PC 0x0c070d5c */
if(!s->budget--) { s->failed_pc=0x0c070d5cu; return 0; }
r[3]=read(ram,0x0c070d6cu,4);
goto P_0c070d5e;
P_0c070d5e: /* original 432b, guest PC 0x0c070d5e */
if(!s->budget--) { s->failed_pc=0x0c070d5eu; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070d60: /* original 0009, guest PC 0x0c070d60 */
if(!s->budget--) { s->failed_pc=0x0c070d60u; return 0; }
goto P_0c070d62;
P_0c070d62: /* original 64f3, guest PC 0x0c070d62 */
if(!s->budget--) { s->failed_pc=0x0c070d62u; return 0; }
r[4]=r[15];
goto P_0c070d64;
P_0c070d64: /* original 7444, guest PC 0x0c070d64 */
if(!s->budget--) { s->failed_pc=0x0c070d64u; return 0; }
r[4]+=0x00000044u;
goto P_0c070d66;
P_0c070d66: /* original 65b3, guest PC 0x0c070d66 */
if(!s->budget--) { s->failed_pc=0x0c070d66u; return 0; }
r[5]=r[11];
goto P_0c070d68;
P_0c070d68: /* original a002, guest PC 0x0c070d68 */
if(!s->budget--) { s->failed_pc=0x0c070d68u; return 0; }
goto P_0c070d70;
P_0c070d6a: /* original 0009, guest PC 0x0c070d6a */
if(!s->budget--) { s->failed_pc=0x0c070d6au; return 0; }
return vf3_matrix_family(0x0c070d6cu,s,ram);
P_0c070d70: /* original f049, guest PC 0x0c070d70 */
if(!s->budget--) { s->failed_pc=0x0c070d70u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070d72;
P_0c070d72: /* original f149, guest PC 0x0c070d72 */
if(!s->budget--) { s->failed_pc=0x0c070d72u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070d74;
P_0c070d74: /* original f249, guest PC 0x0c070d74 */
if(!s->budget--) { s->failed_pc=0x0c070d74u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070d76;
P_0c070d76: /* original f38d, guest PC 0x0c070d76 */
if(!s->budget--) { s->failed_pc=0x0c070d76u; return 0; }
fr[3]=0;
goto P_0c070d78;
P_0c070d78: /* original f459, guest PC 0x0c070d78 */
if(!s->budget--) { s->failed_pc=0x0c070d78u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070d7a;
P_0c070d7a: /* original f559, guest PC 0x0c070d7a */
if(!s->budget--) { s->failed_pc=0x0c070d7au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070d7c;
P_0c070d7c: /* original f659, guest PC 0x0c070d7c */
if(!s->budget--) { s->failed_pc=0x0c070d7cu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070d7e;
P_0c070d7e: /* original f78d, guest PC 0x0c070d7e */
if(!s->budget--) { s->failed_pc=0x0c070d7eu; return 0; }
fr[7]=0;
goto P_0c070d80;
P_0c070d80: /* original f4ed, guest PC 0x0c070d80 */
if(!s->budget--) { s->failed_pc=0x0c070d80u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c070d82;
P_0c070d82: /* original f07c, guest PC 0x0c070d82 */
if(!s->budget--) { s->failed_pc=0x0c070d82u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c070d84;
P_0c070d84: /* original f38d, guest PC 0x0c070d84 */
if(!s->budget--) { s->failed_pc=0x0c070d84u; return 0; }
fr[3]=0;
goto P_0c070d86;
P_0c070d86: /* original f40c, guest PC 0x0c070d86 */
if(!s->budget--) { s->failed_pc=0x0c070d86u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c070d88;
P_0c070d88: /* original f345, guest PC 0x0c070d88 */
if(!s->budget--) { s->failed_pc=0x0c070d88u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c070d8a;
P_0c070d8a: /* original 8902, guest PC 0x0c070d8a */
if(!s->budget--) { s->failed_pc=0x0c070d8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070d92; }
goto P_0c070d8c;
P_0c070d8c: /* original d307, guest PC 0x0c070d8c */
if(!s->budget--) { s->failed_pc=0x0c070d8cu; return 0; }
r[3]=read(ram,0x0c070dacu,4);
goto P_0c070d8e;
P_0c070d8e: /* original 432b, guest PC 0x0c070d8e */
if(!s->budget--) { s->failed_pc=0x0c070d8eu; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070d90: /* original 0009, guest PC 0x0c070d90 */
if(!s->budget--) { s->failed_pc=0x0c070d90u; return 0; }
goto P_0c070d92;
P_0c070d92: /* original ffc5, guest PC 0x0c070d92 */
if(!s->budget--) { s->failed_pc=0x0c070d92u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c070d94;
P_0c070d94: /* original 8902, guest PC 0x0c070d94 */
if(!s->budget--) { s->failed_pc=0x0c070d94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070d9c; }
goto P_0c070d96;
P_0c070d96: /* original d206, guest PC 0x0c070d96 */
if(!s->budget--) { s->failed_pc=0x0c070d96u; return 0; }
r[2]=read(ram,0x0c070db0u,4);
goto P_0c070d98;
P_0c070d98: /* original 422b, guest PC 0x0c070d98 */
if(!s->budget--) { s->failed_pc=0x0c070d98u; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070d9a: /* original 0009, guest PC 0x0c070d9a */
if(!s->budget--) { s->failed_pc=0x0c070d9au; return 0; }
goto P_0c070d9c;
P_0c070d9c: /* original 64f3, guest PC 0x0c070d9c */
if(!s->budget--) { s->failed_pc=0x0c070d9cu; return 0; }
r[4]=r[15];
goto P_0c070d9e;
P_0c070d9e: /* original 65f3, guest PC 0x0c070d9e */
if(!s->budget--) { s->failed_pc=0x0c070d9eu; return 0; }
r[5]=r[15];
goto P_0c070da0;
P_0c070da0: /* original 7444, guest PC 0x0c070da0 */
if(!s->budget--) { s->failed_pc=0x0c070da0u; return 0; }
r[4]+=0x00000044u;
goto P_0c070da2;
P_0c070da2: /* original f4fc, guest PC 0x0c070da2 */
if(!s->budget--) { s->failed_pc=0x0c070da2u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070da4;
P_0c070da4: /* original 7544, guest PC 0x0c070da4 */
if(!s->budget--) { s->failed_pc=0x0c070da4u; return 0; }
r[5]+=0x00000044u;
goto P_0c070da6;
P_0c070da6: /* original a005, guest PC 0x0c070da6 */
if(!s->budget--) { s->failed_pc=0x0c070da6u; return 0; }
goto P_0c070db4;
P_0c070da8: /* original 0009, guest PC 0x0c070da8 */
if(!s->budget--) { s->failed_pc=0x0c070da8u; return 0; }
return vf3_matrix_family(0x0c070daau,s,ram);
P_0c070db4: /* original f059, guest PC 0x0c070db4 */
if(!s->budget--) { s->failed_pc=0x0c070db4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070db6;
P_0c070db6: /* original f159, guest PC 0x0c070db6 */
if(!s->budget--) { s->failed_pc=0x0c070db6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070db8;
P_0c070db8: /* original f259, guest PC 0x0c070db8 */
if(!s->budget--) { s->failed_pc=0x0c070db8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070dba;
P_0c070dba: /* original f38d, guest PC 0x0c070dba */
if(!s->budget--) { s->failed_pc=0x0c070dbau; return 0; }
fr[3]=0;
goto P_0c070dbc;
P_0c070dbc: /* original f0ed, guest PC 0x0c070dbc */
if(!s->budget--) { s->failed_pc=0x0c070dbcu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070dbe;
P_0c070dbe: /* original f37d, guest PC 0x0c070dbe */
if(!s->budget--) { s->failed_pc=0x0c070dbeu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070dc0;
P_0c070dc0: /* original f342, guest PC 0x0c070dc0 */
if(!s->budget--) { s->failed_pc=0x0c070dc0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070dc2;
P_0c070dc2: /* original 740c, guest PC 0x0c070dc2 */
if(!s->budget--) { s->failed_pc=0x0c070dc2u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070dc4;
P_0c070dc4: /* original f232, guest PC 0x0c070dc4 */
if(!s->budget--) { s->failed_pc=0x0c070dc4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070dc6;
P_0c070dc6: /* original f132, guest PC 0x0c070dc6 */
if(!s->budget--) { s->failed_pc=0x0c070dc6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070dc8;
P_0c070dc8: /* original f032, guest PC 0x0c070dc8 */
if(!s->budget--) { s->failed_pc=0x0c070dc8u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070dca;
P_0c070dca: /* original f42b, guest PC 0x0c070dca */
if(!s->budget--) { s->failed_pc=0x0c070dcau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070dcc;
P_0c070dcc: /* original f41b, guest PC 0x0c070dcc */
if(!s->budget--) { s->failed_pc=0x0c070dccu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070dce;
P_0c070dce: /* original f40b, guest PC 0x0c070dce */
if(!s->budget--) { s->failed_pc=0x0c070dceu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070dd0;
P_0c070dd0: /* original d206, guest PC 0x0c070dd0 */
if(!s->budget--) { s->failed_pc=0x0c070dd0u; return 0; }
r[2]=read(ram,0x0c070decu,4);
goto P_0c070dd2;
P_0c070dd2: /* original 422b, guest PC 0x0c070dd2 */
if(!s->budget--) { s->failed_pc=0x0c070dd2u; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070dd4: /* original 0009, guest PC 0x0c070dd4 */
if(!s->budget--) { s->failed_pc=0x0c070dd4u; return 0; }
return vf3_matrix_family(0x0c070dd6u,s,ram);
P_0c070e06: /* original f40b, guest PC 0x0c070e06 */
if(!s->budget--) { s->failed_pc=0x0c070e06u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070e08;
P_0c070e08: /* original 65f3, guest PC 0x0c070e08 */
if(!s->budget--) { s->failed_pc=0x0c070e08u; return 0; }
r[5]=r[15];
goto P_0c070e0a;
P_0c070e0a: /* original 64f3, guest PC 0x0c070e0a */
if(!s->budget--) { s->failed_pc=0x0c070e0au; return 0; }
r[4]=r[15];
goto P_0c070e0c;
P_0c070e0c: /* original 66f3, guest PC 0x0c070e0c */
if(!s->budget--) { s->failed_pc=0x0c070e0cu; return 0; }
r[6]=r[15];
goto P_0c070e0e;
P_0c070e0e: /* original 7438, guest PC 0x0c070e0e */
if(!s->budget--) { s->failed_pc=0x0c070e0eu; return 0; }
r[4]+=0x00000038u;
goto P_0c070e10;
P_0c070e10: /* original 7638, guest PC 0x0c070e10 */
if(!s->budget--) { s->failed_pc=0x0c070e10u; return 0; }
r[6]+=0x00000038u;
goto P_0c070e12;
P_0c070e12: /* original 7544, guest PC 0x0c070e12 */
if(!s->budget--) { s->failed_pc=0x0c070e12u; return 0; }
r[5]+=0x00000044u;
goto P_0c070e14;
P_0c070e14: /* original f059, guest PC 0x0c070e14 */
if(!s->budget--) { s->failed_pc=0x0c070e14u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e16;
P_0c070e16: /* original f369, guest PC 0x0c070e16 */
if(!s->budget--) { s->failed_pc=0x0c070e16u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070e18;
P_0c070e18: /* original f159, guest PC 0x0c070e18 */
if(!s->budget--) { s->failed_pc=0x0c070e18u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e1a;
P_0c070e1a: /* original f469, guest PC 0x0c070e1a */
if(!s->budget--) { s->failed_pc=0x0c070e1au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070e1c;
P_0c070e1c: /* original f031, guest PC 0x0c070e1c */
if(!s->budget--) { s->failed_pc=0x0c070e1cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070e1e;
P_0c070e1e: /* original f258, guest PC 0x0c070e1e */
if(!s->budget--) { s->failed_pc=0x0c070e1eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070e20;
P_0c070e20: /* original f568, guest PC 0x0c070e20 */
if(!s->budget--) { s->failed_pc=0x0c070e20u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070e22;
P_0c070e22: /* original f141, guest PC 0x0c070e22 */
if(!s->budget--) { s->failed_pc=0x0c070e22u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070e24;
P_0c070e24: /* original f251, guest PC 0x0c070e24 */
if(!s->budget--) { s->failed_pc=0x0c070e24u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070e26;
P_0c070e26: /* original 7408, guest PC 0x0c070e26 */
if(!s->budget--) { s->failed_pc=0x0c070e26u; return 0; }
r[4]+=0x00000008u;
goto P_0c070e28;
P_0c070e28: /* original f42a, guest PC 0x0c070e28 */
if(!s->budget--) { s->failed_pc=0x0c070e28u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070e2a;
P_0c070e2a: /* original f41b, guest PC 0x0c070e2a */
if(!s->budget--) { s->failed_pc=0x0c070e2au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070e2c;
P_0c070e2c: /* original f40b, guest PC 0x0c070e2c */
if(!s->budget--) { s->failed_pc=0x0c070e2cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070e2e;
P_0c070e2e: /* original 0009, guest PC 0x0c070e2e */
if(!s->budget--) { s->failed_pc=0x0c070e2eu; return 0; }
goto P_0c070e30;
P_0c070e30: /* original e01c, guest PC 0x0c070e30 */
if(!s->budget--) { s->failed_pc=0x0c070e30u; return 0; }
r[0]=0x0000001cu;
goto P_0c070e32;
P_0c070e32: /* original f4fc, guest PC 0x0c070e32 */
if(!s->budget--) { s->failed_pc=0x0c070e32u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070e34;
P_0c070e34: /* original f3f6, guest PC 0x0c070e34 */
if(!s->budget--) { s->failed_pc=0x0c070e34u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c070e36;
P_0c070e36: /* original 64f3, guest PC 0x0c070e36 */
if(!s->budget--) { s->failed_pc=0x0c070e36u; return 0; }
r[4]=r[15];
goto P_0c070e38;
P_0c070e38: /* original 65f3, guest PC 0x0c070e38 */
if(!s->budget--) { s->failed_pc=0x0c070e38u; return 0; }
r[5]=r[15];
goto P_0c070e3a;
P_0c070e3a: /* original 7438, guest PC 0x0c070e3a */
if(!s->budget--) { s->failed_pc=0x0c070e3au; return 0; }
r[4]+=0x00000038u;
goto P_0c070e3c;
P_0c070e3c: /* original f431, guest PC 0x0c070e3c */
if(!s->budget--) { s->failed_pc=0x0c070e3cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c070e3e;
P_0c070e3e: /* original 7538, guest PC 0x0c070e3e */
if(!s->budget--) { s->failed_pc=0x0c070e3eu; return 0; }
r[5]+=0x00000038u;
goto P_0c070e40;
P_0c070e40: /* original f059, guest PC 0x0c070e40 */
if(!s->budget--) { s->failed_pc=0x0c070e40u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e42;
P_0c070e42: /* original f159, guest PC 0x0c070e42 */
if(!s->budget--) { s->failed_pc=0x0c070e42u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e44;
P_0c070e44: /* original f259, guest PC 0x0c070e44 */
if(!s->budget--) { s->failed_pc=0x0c070e44u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e46;
P_0c070e46: /* original f38d, guest PC 0x0c070e46 */
if(!s->budget--) { s->failed_pc=0x0c070e46u; return 0; }
fr[3]=0;
goto P_0c070e48;
P_0c070e48: /* original f0ed, guest PC 0x0c070e48 */
if(!s->budget--) { s->failed_pc=0x0c070e48u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070e4a;
P_0c070e4a: /* original f37d, guest PC 0x0c070e4a */
if(!s->budget--) { s->failed_pc=0x0c070e4au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070e4c;
P_0c070e4c: /* original f342, guest PC 0x0c070e4c */
if(!s->budget--) { s->failed_pc=0x0c070e4cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070e4e;
P_0c070e4e: /* original 740c, guest PC 0x0c070e4e */
if(!s->budget--) { s->failed_pc=0x0c070e4eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c070e50;
P_0c070e50: /* original f232, guest PC 0x0c070e50 */
if(!s->budget--) { s->failed_pc=0x0c070e50u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070e52;
P_0c070e52: /* original f132, guest PC 0x0c070e52 */
if(!s->budget--) { s->failed_pc=0x0c070e52u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070e54;
P_0c070e54: /* original f032, guest PC 0x0c070e54 */
if(!s->budget--) { s->failed_pc=0x0c070e54u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070e56;
P_0c070e56: /* original f42b, guest PC 0x0c070e56 */
if(!s->budget--) { s->failed_pc=0x0c070e56u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070e58;
P_0c070e58: /* original f41b, guest PC 0x0c070e58 */
if(!s->budget--) { s->failed_pc=0x0c070e58u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070e5a;
P_0c070e5a: /* original f40b, guest PC 0x0c070e5a */
if(!s->budget--) { s->failed_pc=0x0c070e5au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070e5c;
P_0c070e5c: /* original 64f3, guest PC 0x0c070e5c */
if(!s->budget--) { s->failed_pc=0x0c070e5cu; return 0; }
r[4]=r[15];
goto P_0c070e5e;
P_0c070e5e: /* original 65f3, guest PC 0x0c070e5e */
if(!s->budget--) { s->failed_pc=0x0c070e5eu; return 0; }
r[5]=r[15];
goto P_0c070e60;
P_0c070e60: /* original 7444, guest PC 0x0c070e60 */
if(!s->budget--) { s->failed_pc=0x0c070e60u; return 0; }
r[4]+=0x00000044u;
goto P_0c070e62;
P_0c070e62: /* original 7538, guest PC 0x0c070e62 */
if(!s->budget--) { s->failed_pc=0x0c070e62u; return 0; }
r[5]+=0x00000038u;
goto P_0c070e64;
P_0c070e64: /* original f049, guest PC 0x0c070e64 */
if(!s->budget--) { s->failed_pc=0x0c070e64u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070e66;
P_0c070e66: /* original f359, guest PC 0x0c070e66 */
if(!s->budget--) { s->failed_pc=0x0c070e66u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e68;
P_0c070e68: /* original f149, guest PC 0x0c070e68 */
if(!s->budget--) { s->failed_pc=0x0c070e68u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070e6a;
P_0c070e6a: /* original f459, guest PC 0x0c070e6a */
if(!s->budget--) { s->failed_pc=0x0c070e6au; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e6c;
P_0c070e6c: /* original f249, guest PC 0x0c070e6c */
if(!s->budget--) { s->failed_pc=0x0c070e6cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070e6e;
P_0c070e6e: /* original f559, guest PC 0x0c070e6e */
if(!s->budget--) { s->failed_pc=0x0c070e6eu; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e70;
P_0c070e70: /* original f030, guest PC 0x0c070e70 */
if(!s->budget--) { s->failed_pc=0x0c070e70u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070e72;
P_0c070e72: /* original f250, guest PC 0x0c070e72 */
if(!s->budget--) { s->failed_pc=0x0c070e72u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070e74;
P_0c070e74: /* original f140, guest PC 0x0c070e74 */
if(!s->budget--) { s->failed_pc=0x0c070e74u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070e76;
P_0c070e76: /* original f42b, guest PC 0x0c070e76 */
if(!s->budget--) { s->failed_pc=0x0c070e76u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070e78;
P_0c070e78: /* original f41b, guest PC 0x0c070e78 */
if(!s->budget--) { s->failed_pc=0x0c070e78u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070e7a;
P_0c070e7a: /* original f40b, guest PC 0x0c070e7a */
if(!s->budget--) { s->failed_pc=0x0c070e7au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070e7c;
P_0c070e7c: /* original 65f3, guest PC 0x0c070e7c */
if(!s->budget--) { s->failed_pc=0x0c070e7cu; return 0; }
r[5]=r[15];
goto P_0c070e7e;
P_0c070e7e: /* original 64d3, guest PC 0x0c070e7e */
if(!s->budget--) { s->failed_pc=0x0c070e7eu; return 0; }
r[4]=r[13];
goto P_0c070e80;
P_0c070e80: /* original 7544, guest PC 0x0c070e80 */
if(!s->budget--) { s->failed_pc=0x0c070e80u; return 0; }
r[5]+=0x00000044u;
goto P_0c070e82;
P_0c070e82: /* original 66a3, guest PC 0x0c070e82 */
if(!s->budget--) { s->failed_pc=0x0c070e82u; return 0; }
r[6]=r[10];
goto P_0c070e84;
P_0c070e84: /* original f059, guest PC 0x0c070e84 */
if(!s->budget--) { s->failed_pc=0x0c070e84u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e86;
P_0c070e86: /* original f369, guest PC 0x0c070e86 */
if(!s->budget--) { s->failed_pc=0x0c070e86u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070e88;
P_0c070e88: /* original f159, guest PC 0x0c070e88 */
if(!s->budget--) { s->failed_pc=0x0c070e88u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e8a;
P_0c070e8a: /* original f469, guest PC 0x0c070e8a */
if(!s->budget--) { s->failed_pc=0x0c070e8au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070e8c;
P_0c070e8c: /* original f259, guest PC 0x0c070e8c */
if(!s->budget--) { s->failed_pc=0x0c070e8cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070e8e;
P_0c070e8e: /* original f569, guest PC 0x0c070e8e */
if(!s->budget--) { s->failed_pc=0x0c070e8eu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070e90;
P_0c070e90: /* original 740c, guest PC 0x0c070e90 */
if(!s->budget--) { s->failed_pc=0x0c070e90u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070e92;
P_0c070e92: /* original f030, guest PC 0x0c070e92 */
if(!s->budget--) { s->failed_pc=0x0c070e92u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c070e94;
P_0c070e94: /* original f250, guest PC 0x0c070e94 */
if(!s->budget--) { s->failed_pc=0x0c070e94u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c070e96;
P_0c070e96: /* original f140, guest PC 0x0c070e96 */
if(!s->budget--) { s->failed_pc=0x0c070e96u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c070e98;
P_0c070e98: /* original f42b, guest PC 0x0c070e98 */
if(!s->budget--) { s->failed_pc=0x0c070e98u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070e9a;
P_0c070e9a: /* original f41b, guest PC 0x0c070e9a */
if(!s->budget--) { s->failed_pc=0x0c070e9au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070e9c;
P_0c070e9c: /* original f40b, guest PC 0x0c070e9c */
if(!s->budget--) { s->failed_pc=0x0c070e9cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070e9e;
P_0c070e9e: /* original 0009, guest PC 0x0c070e9e */
if(!s->budget--) { s->failed_pc=0x0c070e9eu; return 0; }
goto P_0c070ea0;
P_0c070ea0: /* original 64f3, guest PC 0x0c070ea0 */
if(!s->budget--) { s->failed_pc=0x0c070ea0u; return 0; }
r[4]=r[15];
goto P_0c070ea2;
P_0c070ea2: /* original 7444, guest PC 0x0c070ea2 */
if(!s->budget--) { s->failed_pc=0x0c070ea2u; return 0; }
r[4]+=0x00000044u;
goto P_0c070ea4;
P_0c070ea4: /* original 6693, guest PC 0x0c070ea4 */
if(!s->budget--) { s->failed_pc=0x0c070ea4u; return 0; }
r[6]=r[9];
goto P_0c070ea6;
P_0c070ea6: /* original 65d3, guest PC 0x0c070ea6 */
if(!s->budget--) { s->failed_pc=0x0c070ea6u; return 0; }
r[5]=r[13];
goto P_0c070ea8;
P_0c070ea8: /* original f059, guest PC 0x0c070ea8 */
if(!s->budget--) { s->failed_pc=0x0c070ea8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070eaa;
P_0c070eaa: /* original f369, guest PC 0x0c070eaa */
if(!s->budget--) { s->failed_pc=0x0c070eaau; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070eac;
P_0c070eac: /* original f159, guest PC 0x0c070eac */
if(!s->budget--) { s->failed_pc=0x0c070eacu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070eae;
P_0c070eae: /* original f469, guest PC 0x0c070eae */
if(!s->budget--) { s->failed_pc=0x0c070eaeu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070eb0;
P_0c070eb0: /* original f031, guest PC 0x0c070eb0 */
if(!s->budget--) { s->failed_pc=0x0c070eb0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070eb2;
P_0c070eb2: /* original f258, guest PC 0x0c070eb2 */
if(!s->budget--) { s->failed_pc=0x0c070eb2u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070eb4;
P_0c070eb4: /* original f568, guest PC 0x0c070eb4 */
if(!s->budget--) { s->failed_pc=0x0c070eb4u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070eb6;
P_0c070eb6: /* original f141, guest PC 0x0c070eb6 */
if(!s->budget--) { s->failed_pc=0x0c070eb6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070eb8;
P_0c070eb8: /* original f251, guest PC 0x0c070eb8 */
if(!s->budget--) { s->failed_pc=0x0c070eb8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070eba;
P_0c070eba: /* original 7408, guest PC 0x0c070eba */
if(!s->budget--) { s->failed_pc=0x0c070ebau; return 0; }
r[4]+=0x00000008u;
goto P_0c070ebc;
P_0c070ebc: /* original f42a, guest PC 0x0c070ebc */
if(!s->budget--) { s->failed_pc=0x0c070ebcu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070ebe;
P_0c070ebe: /* original f41b, guest PC 0x0c070ebe */
if(!s->budget--) { s->failed_pc=0x0c070ebeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070ec0;
P_0c070ec0: /* original f40b, guest PC 0x0c070ec0 */
if(!s->budget--) { s->failed_pc=0x0c070ec0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070ec2;
P_0c070ec2: /* original 0009, guest PC 0x0c070ec2 */
if(!s->budget--) { s->failed_pc=0x0c070ec2u; return 0; }
goto P_0c070ec4;
P_0c070ec4: /* original 64f3, guest PC 0x0c070ec4 */
if(!s->budget--) { s->failed_pc=0x0c070ec4u; return 0; }
r[4]=r[15];
goto P_0c070ec6;
P_0c070ec6: /* original 7444, guest PC 0x0c070ec6 */
if(!s->budget--) { s->failed_pc=0x0c070ec6u; return 0; }
r[4]+=0x00000044u;
goto P_0c070ec8;
P_0c070ec8: /* original f049, guest PC 0x0c070ec8 */
if(!s->budget--) { s->failed_pc=0x0c070ec8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070eca;
P_0c070eca: /* original f149, guest PC 0x0c070eca */
if(!s->budget--) { s->failed_pc=0x0c070ecau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070ecc;
P_0c070ecc: /* original f249, guest PC 0x0c070ecc */
if(!s->budget--) { s->failed_pc=0x0c070eccu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070ece;
P_0c070ece: /* original f38d, guest PC 0x0c070ece */
if(!s->budget--) { s->failed_pc=0x0c070eceu; return 0; }
fr[3]=0;
goto P_0c070ed0;
P_0c070ed0: /* original f0ed, guest PC 0x0c070ed0 */
if(!s->budget--) { s->failed_pc=0x0c070ed0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070ed2;
P_0c070ed2: /* original f03c, guest PC 0x0c070ed2 */
if(!s->budget--) { s->failed_pc=0x0c070ed2u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070ed4;
P_0c070ed4: /* original f06d, guest PC 0x0c070ed4 */
if(!s->budget--) { s->failed_pc=0x0c070ed4u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070ed6;
P_0c070ed6: /* original 0009, guest PC 0x0c070ed6 */
if(!s->budget--) { s->failed_pc=0x0c070ed6u; return 0; }
goto P_0c070ed8;
P_0c070ed8: /* original f38d, guest PC 0x0c070ed8 */
if(!s->budget--) { s->failed_pc=0x0c070ed8u; return 0; }
fr[3]=0;
goto P_0c070eda;
P_0c070eda: /* original fc0c, guest PC 0x0c070eda */
if(!s->budget--) { s->failed_pc=0x0c070edau; return 0; }
vf3_matrix_move(s,12,0);
goto P_0c070edc;
P_0c070edc: /* original fc35, guest PC 0x0c070edc */
if(!s->budget--) { s->failed_pc=0x0c070edcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[12])>as_float(fr[3]))!=0);
goto P_0c070ede;
P_0c070ede: /* original 8902, guest PC 0x0c070ede */
if(!s->budget--) { s->failed_pc=0x0c070edeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070ee6; }
goto P_0c070ee0;
P_0c070ee0: /* original d303, guest PC 0x0c070ee0 */
if(!s->budget--) { s->failed_pc=0x0c070ee0u; return 0; }
r[3]=read(ram,0x0c070ef0u,4);
goto P_0c070ee2;
P_0c070ee2: /* original 432b, guest PC 0x0c070ee2 */
if(!s->budget--) { s->failed_pc=0x0c070ee2u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070ee4: /* original 0009, guest PC 0x0c070ee4 */
if(!s->budget--) { s->failed_pc=0x0c070ee4u; return 0; }
goto P_0c070ee6;
P_0c070ee6: /* original 64f3, guest PC 0x0c070ee6 */
if(!s->budget--) { s->failed_pc=0x0c070ee6u; return 0; }
r[4]=r[15];
goto P_0c070ee8;
P_0c070ee8: /* original 7444, guest PC 0x0c070ee8 */
if(!s->budget--) { s->failed_pc=0x0c070ee8u; return 0; }
r[4]+=0x00000044u;
goto P_0c070eea;
P_0c070eea: /* original 65c3, guest PC 0x0c070eea */
if(!s->budget--) { s->failed_pc=0x0c070eeau; return 0; }
r[5]=r[12];
goto P_0c070eec;
P_0c070eec: /* original a002, guest PC 0x0c070eec */
if(!s->budget--) { s->failed_pc=0x0c070eecu; return 0; }
goto P_0c070ef4;
P_0c070eee: /* original 0009, guest PC 0x0c070eee */
if(!s->budget--) { s->failed_pc=0x0c070eeeu; return 0; }
return vf3_matrix_family(0x0c070ef0u,s,ram);
P_0c070ef4: /* original f049, guest PC 0x0c070ef4 */
if(!s->budget--) { s->failed_pc=0x0c070ef4u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070ef6;
P_0c070ef6: /* original f549, guest PC 0x0c070ef6 */
if(!s->budget--) { s->failed_pc=0x0c070ef6u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070ef8;
P_0c070ef8: /* original f648, guest PC 0x0c070ef8 */
if(!s->budget--) { s->failed_pc=0x0c070ef8u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c070efa;
P_0c070efa: /* original f859, guest PC 0x0c070efa */
if(!s->budget--) { s->failed_pc=0x0c070efau; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070efc;
P_0c070efc: /* original f959, guest PC 0x0c070efc */
if(!s->budget--) { s->failed_pc=0x0c070efcu; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070efe;
P_0c070efe: /* original fa58, guest PC 0x0c070efe */
if(!s->budget--) { s->failed_pc=0x0c070efeu; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c070f00;
P_0c070f00: /* original f35c, guest PC 0x0c070f00 */
if(!s->budget--) { s->failed_pc=0x0c070f00u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c070f02;
P_0c070f02: /* original f382, guest PC 0x0c070f02 */
if(!s->budget--) { s->failed_pc=0x0c070f02u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c070f04;
P_0c070f04: /* original f20c, guest PC 0x0c070f04 */
if(!s->budget--) { s->failed_pc=0x0c070f04u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c070f06;
P_0c070f06: /* original f2a2, guest PC 0x0c070f06 */
if(!s->budget--) { s->failed_pc=0x0c070f06u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c070f08;
P_0c070f08: /* original f16c, guest PC 0x0c070f08 */
if(!s->budget--) { s->failed_pc=0x0c070f08u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c070f0a;
P_0c070f0a: /* original f192, guest PC 0x0c070f0a */
if(!s->budget--) { s->failed_pc=0x0c070f0au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c070f0c;
P_0c070f0c: /* original f34d, guest PC 0x0c070f0c */
if(!s->budget--) { s->failed_pc=0x0c070f0cu; return 0; }
fr[3]^=0x80000000u;
goto P_0c070f0e;
P_0c070f0e: /* original f39e, guest PC 0x0c070f0e */
if(!s->budget--) { s->failed_pc=0x0c070f0eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c070f10;
P_0c070f10: /* original f24d, guest PC 0x0c070f10 */
if(!s->budget--) { s->failed_pc=0x0c070f10u; return 0; }
fr[2]^=0x80000000u;
goto P_0c070f12;
P_0c070f12: /* original f06c, guest PC 0x0c070f12 */
if(!s->budget--) { s->failed_pc=0x0c070f12u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c070f14;
P_0c070f14: /* original f28e, guest PC 0x0c070f14 */
if(!s->budget--) { s->failed_pc=0x0c070f14u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c070f16;
P_0c070f16: /* original f14d, guest PC 0x0c070f16 */
if(!s->budget--) { s->failed_pc=0x0c070f16u; return 0; }
fr[1]^=0x80000000u;
goto P_0c070f18;
P_0c070f18: /* original f05c, guest PC 0x0c070f18 */
if(!s->budget--) { s->failed_pc=0x0c070f18u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c070f1a;
P_0c070f1a: /* original f1ae, guest PC 0x0c070f1a */
if(!s->budget--) { s->failed_pc=0x0c070f1au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c070f1c;
P_0c070f1c: /* original f08d, guest PC 0x0c070f1c */
if(!s->budget--) { s->failed_pc=0x0c070f1cu; return 0; }
fr[0]=0;
goto P_0c070f1e;
P_0c070f1e: /* original f0ed, guest PC 0x0c070f1e */
if(!s->budget--) { s->failed_pc=0x0c070f1eu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070f20;
P_0c070f20: /* original f03c, guest PC 0x0c070f20 */
if(!s->budget--) { s->failed_pc=0x0c070f20u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c070f22;
P_0c070f22: /* original f06d, guest PC 0x0c070f22 */
if(!s->budget--) { s->failed_pc=0x0c070f22u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c070f24;
P_0c070f24: /* original ff05, guest PC 0x0c070f24 */
if(!s->budget--) { s->failed_pc=0x0c070f24u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[0]))!=0);
goto P_0c070f26;
P_0c070f26: /* original e024, guest PC 0x0c070f26 */
if(!s->budget--) { s->failed_pc=0x0c070f26u; return 0; }
r[0]=0x00000024u;
goto P_0c070f28;
P_0c070f28: /* original 8d03, guest PC 0x0c070f28 */
if(!s->budget--) { s->failed_pc=0x0c070f28u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,0,r[15]+r[0]);
if(cond) { goto P_0c070f32; }
goto P_0c070f2c;
P_0c070f2a: /* original ff07, guest PC 0x0c070f2a */
if(!s->budget--) { s->failed_pc=0x0c070f2au; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c070f2c;
P_0c070f2c: /* original d303, guest PC 0x0c070f2c */
if(!s->budget--) { s->failed_pc=0x0c070f2cu; return 0; }
r[3]=read(ram,0x0c070f3cu,4);
goto P_0c070f2e;
P_0c070f2e: /* original 432b, guest PC 0x0c070f2e */
if(!s->budget--) { s->failed_pc=0x0c070f2eu; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070f30: /* original 0009, guest PC 0x0c070f30 */
if(!s->budget--) { s->failed_pc=0x0c070f30u; return 0; }
goto P_0c070f32;
P_0c070f32: /* original 64f3, guest PC 0x0c070f32 */
if(!s->budget--) { s->failed_pc=0x0c070f32u; return 0; }
r[4]=r[15];
goto P_0c070f34;
P_0c070f34: /* original 7444, guest PC 0x0c070f34 */
if(!s->budget--) { s->failed_pc=0x0c070f34u; return 0; }
r[4]+=0x00000044u;
goto P_0c070f36;
P_0c070f36: /* original 65c3, guest PC 0x0c070f36 */
if(!s->budget--) { s->failed_pc=0x0c070f36u; return 0; }
r[5]=r[12];
goto P_0c070f38;
P_0c070f38: /* original a002, guest PC 0x0c070f38 */
if(!s->budget--) { s->failed_pc=0x0c070f38u; return 0; }
goto P_0c070f40;
P_0c070f3a: /* original 0009, guest PC 0x0c070f3a */
if(!s->budget--) { s->failed_pc=0x0c070f3au; return 0; }
return vf3_matrix_family(0x0c070f3cu,s,ram);
P_0c070f40: /* original f049, guest PC 0x0c070f40 */
if(!s->budget--) { s->failed_pc=0x0c070f40u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070f42;
P_0c070f42: /* original f149, guest PC 0x0c070f42 */
if(!s->budget--) { s->failed_pc=0x0c070f42u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070f44;
P_0c070f44: /* original f249, guest PC 0x0c070f44 */
if(!s->budget--) { s->failed_pc=0x0c070f44u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c070f46;
P_0c070f46: /* original f38d, guest PC 0x0c070f46 */
if(!s->budget--) { s->failed_pc=0x0c070f46u; return 0; }
fr[3]=0;
goto P_0c070f48;
P_0c070f48: /* original f459, guest PC 0x0c070f48 */
if(!s->budget--) { s->failed_pc=0x0c070f48u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070f4a;
P_0c070f4a: /* original f559, guest PC 0x0c070f4a */
if(!s->budget--) { s->failed_pc=0x0c070f4au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070f4c;
P_0c070f4c: /* original f659, guest PC 0x0c070f4c */
if(!s->budget--) { s->failed_pc=0x0c070f4cu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070f4e;
P_0c070f4e: /* original f78d, guest PC 0x0c070f4e */
if(!s->budget--) { s->failed_pc=0x0c070f4eu; return 0; }
fr[7]=0;
goto P_0c070f50;
P_0c070f50: /* original f4ed, guest PC 0x0c070f50 */
if(!s->budget--) { s->failed_pc=0x0c070f50u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c070f52;
P_0c070f52: /* original f07c, guest PC 0x0c070f52 */
if(!s->budget--) { s->failed_pc=0x0c070f52u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c070f54;
P_0c070f54: /* original f38d, guest PC 0x0c070f54 */
if(!s->budget--) { s->failed_pc=0x0c070f54u; return 0; }
fr[3]=0;
goto P_0c070f56;
P_0c070f56: /* original f40c, guest PC 0x0c070f56 */
if(!s->budget--) { s->failed_pc=0x0c070f56u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c070f58;
P_0c070f58: /* original f345, guest PC 0x0c070f58 */
if(!s->budget--) { s->failed_pc=0x0c070f58u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c070f5a;
P_0c070f5a: /* original 8902, guest PC 0x0c070f5a */
if(!s->budget--) { s->failed_pc=0x0c070f5au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070f62; }
goto P_0c070f5c;
P_0c070f5c: /* original d307, guest PC 0x0c070f5c */
if(!s->budget--) { s->failed_pc=0x0c070f5cu; return 0; }
r[3]=read(ram,0x0c070f7cu,4);
goto P_0c070f5e;
P_0c070f5e: /* original 432b, guest PC 0x0c070f5e */
if(!s->budget--) { s->failed_pc=0x0c070f5eu; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070f60: /* original 0009, guest PC 0x0c070f60 */
if(!s->budget--) { s->failed_pc=0x0c070f60u; return 0; }
goto P_0c070f62;
P_0c070f62: /* original ffc5, guest PC 0x0c070f62 */
if(!s->budget--) { s->failed_pc=0x0c070f62u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[12]))!=0);
goto P_0c070f64;
P_0c070f64: /* original 8902, guest PC 0x0c070f64 */
if(!s->budget--) { s->failed_pc=0x0c070f64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070f6c; }
goto P_0c070f66;
P_0c070f66: /* original d206, guest PC 0x0c070f66 */
if(!s->budget--) { s->failed_pc=0x0c070f66u; return 0; }
r[2]=read(ram,0x0c070f80u,4);
goto P_0c070f68;
P_0c070f68: /* original 422b, guest PC 0x0c070f68 */
if(!s->budget--) { s->failed_pc=0x0c070f68u; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070f6a: /* original 0009, guest PC 0x0c070f6a */
if(!s->budget--) { s->failed_pc=0x0c070f6au; return 0; }
goto P_0c070f6c;
P_0c070f6c: /* original 64f3, guest PC 0x0c070f6c */
if(!s->budget--) { s->failed_pc=0x0c070f6cu; return 0; }
r[4]=r[15];
goto P_0c070f6e;
P_0c070f6e: /* original 65f3, guest PC 0x0c070f6e */
if(!s->budget--) { s->failed_pc=0x0c070f6eu; return 0; }
r[5]=r[15];
goto P_0c070f70;
P_0c070f70: /* original 7444, guest PC 0x0c070f70 */
if(!s->budget--) { s->failed_pc=0x0c070f70u; return 0; }
r[4]+=0x00000044u;
goto P_0c070f72;
P_0c070f72: /* original f4fc, guest PC 0x0c070f72 */
if(!s->budget--) { s->failed_pc=0x0c070f72u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c070f74;
P_0c070f74: /* original 7544, guest PC 0x0c070f74 */
if(!s->budget--) { s->failed_pc=0x0c070f74u; return 0; }
r[5]+=0x00000044u;
goto P_0c070f76;
P_0c070f76: /* original a005, guest PC 0x0c070f76 */
if(!s->budget--) { s->failed_pc=0x0c070f76u; return 0; }
goto P_0c070f84;
P_0c070f78: /* original 0009, guest PC 0x0c070f78 */
if(!s->budget--) { s->failed_pc=0x0c070f78u; return 0; }
return vf3_matrix_family(0x0c070f7au,s,ram);
P_0c070f84: /* original f059, guest PC 0x0c070f84 */
if(!s->budget--) { s->failed_pc=0x0c070f84u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070f86;
P_0c070f86: /* original f159, guest PC 0x0c070f86 */
if(!s->budget--) { s->failed_pc=0x0c070f86u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070f88;
P_0c070f88: /* original f259, guest PC 0x0c070f88 */
if(!s->budget--) { s->failed_pc=0x0c070f88u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070f8a;
P_0c070f8a: /* original f38d, guest PC 0x0c070f8a */
if(!s->budget--) { s->failed_pc=0x0c070f8au; return 0; }
fr[3]=0;
goto P_0c070f8c;
P_0c070f8c: /* original f0ed, guest PC 0x0c070f8c */
if(!s->budget--) { s->failed_pc=0x0c070f8cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c070f8e;
P_0c070f8e: /* original f37d, guest PC 0x0c070f8e */
if(!s->budget--) { s->failed_pc=0x0c070f8eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c070f90;
P_0c070f90: /* original f342, guest PC 0x0c070f90 */
if(!s->budget--) { s->failed_pc=0x0c070f90u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c070f92;
P_0c070f92: /* original 740c, guest PC 0x0c070f92 */
if(!s->budget--) { s->failed_pc=0x0c070f92u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070f94;
P_0c070f94: /* original f232, guest PC 0x0c070f94 */
if(!s->budget--) { s->failed_pc=0x0c070f94u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c070f96;
P_0c070f96: /* original f132, guest PC 0x0c070f96 */
if(!s->budget--) { s->failed_pc=0x0c070f96u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c070f98;
P_0c070f98: /* original f032, guest PC 0x0c070f98 */
if(!s->budget--) { s->failed_pc=0x0c070f98u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c070f9a;
P_0c070f9a: /* original f42b, guest PC 0x0c070f9a */
if(!s->budget--) { s->failed_pc=0x0c070f9au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070f9c;
P_0c070f9c: /* original f41b, guest PC 0x0c070f9c */
if(!s->budget--) { s->failed_pc=0x0c070f9cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070f9e;
P_0c070f9e: /* original f40b, guest PC 0x0c070f9e */
if(!s->budget--) { s->failed_pc=0x0c070f9eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070fa0;
P_0c070fa0: /* original d206, guest PC 0x0c070fa0 */
if(!s->budget--) { s->failed_pc=0x0c070fa0u; return 0; }
r[2]=read(ram,0x0c070fbcu,4);
goto P_0c070fa2;
P_0c070fa2: /* original 422b, guest PC 0x0c070fa2 */
if(!s->budget--) { s->failed_pc=0x0c070fa2u; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070fa4: /* original 0009, guest PC 0x0c070fa4 */
if(!s->budget--) { s->failed_pc=0x0c070fa4u; return 0; }
return vf3_matrix_family(0x0c070fa6u,s,ram);
P_0c070fd6: /* original f40b, guest PC 0x0c070fd6 */
if(!s->budget--) { s->failed_pc=0x0c070fd6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070fd8;
P_0c070fd8: /* original 65f3, guest PC 0x0c070fd8 */
if(!s->budget--) { s->failed_pc=0x0c070fd8u; return 0; }
r[5]=r[15];
goto P_0c070fda;
P_0c070fda: /* original 64f3, guest PC 0x0c070fda */
if(!s->budget--) { s->failed_pc=0x0c070fdau; return 0; }
r[4]=r[15];
goto P_0c070fdc;
P_0c070fdc: /* original 66f3, guest PC 0x0c070fdc */
if(!s->budget--) { s->failed_pc=0x0c070fdcu; return 0; }
r[6]=r[15];
goto P_0c070fde;
P_0c070fde: /* original 7438, guest PC 0x0c070fde */
if(!s->budget--) { s->failed_pc=0x0c070fdeu; return 0; }
r[4]+=0x00000038u;
goto P_0c070fe0;
P_0c070fe0: /* original 7638, guest PC 0x0c070fe0 */
if(!s->budget--) { s->failed_pc=0x0c070fe0u; return 0; }
r[6]+=0x00000038u;
goto P_0c070fe2;
P_0c070fe2: /* original 7544, guest PC 0x0c070fe2 */
if(!s->budget--) { s->failed_pc=0x0c070fe2u; return 0; }
r[5]+=0x00000044u;
goto P_0c070fe4;
P_0c070fe4: /* original f059, guest PC 0x0c070fe4 */
if(!s->budget--) { s->failed_pc=0x0c070fe4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070fe6;
P_0c070fe6: /* original f369, guest PC 0x0c070fe6 */
if(!s->budget--) { s->failed_pc=0x0c070fe6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070fe8;
P_0c070fe8: /* original f159, guest PC 0x0c070fe8 */
if(!s->budget--) { s->failed_pc=0x0c070fe8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070fea;
P_0c070fea: /* original f469, guest PC 0x0c070fea */
if(!s->budget--) { s->failed_pc=0x0c070feau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070fec;
P_0c070fec: /* original f031, guest PC 0x0c070fec */
if(!s->budget--) { s->failed_pc=0x0c070fecu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070fee;
P_0c070fee: /* original f258, guest PC 0x0c070fee */
if(!s->budget--) { s->failed_pc=0x0c070feeu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070ff0;
P_0c070ff0: /* original f568, guest PC 0x0c070ff0 */
if(!s->budget--) { s->failed_pc=0x0c070ff0u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070ff2;
P_0c070ff2: /* original f141, guest PC 0x0c070ff2 */
if(!s->budget--) { s->failed_pc=0x0c070ff2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070ff4;
P_0c070ff4: /* original f251, guest PC 0x0c070ff4 */
if(!s->budget--) { s->failed_pc=0x0c070ff4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070ff6;
P_0c070ff6: /* original 7408, guest PC 0x0c070ff6 */
if(!s->budget--) { s->failed_pc=0x0c070ff6u; return 0; }
r[4]+=0x00000008u;
goto P_0c070ff8;
P_0c070ff8: /* original f42a, guest PC 0x0c070ff8 */
if(!s->budget--) { s->failed_pc=0x0c070ff8u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070ffa;
P_0c070ffa: /* original f41b, guest PC 0x0c070ffa */
if(!s->budget--) { s->failed_pc=0x0c070ffau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070ffc;
P_0c070ffc: /* original f40b, guest PC 0x0c070ffc */
if(!s->budget--) { s->failed_pc=0x0c070ffcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070ffe;
P_0c070ffe: /* original 0009, guest PC 0x0c070ffe */
if(!s->budget--) { s->failed_pc=0x0c070ffeu; return 0; }
goto P_0c071000;
P_0c071000: /* original e024, guest PC 0x0c071000 */
if(!s->budget--) { s->failed_pc=0x0c071000u; return 0; }
r[0]=0x00000024u;
goto P_0c071002;
P_0c071002: /* original f4fc, guest PC 0x0c071002 */
if(!s->budget--) { s->failed_pc=0x0c071002u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c071004;
P_0c071004: /* original f3f6, guest PC 0x0c071004 */
if(!s->budget--) { s->failed_pc=0x0c071004u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c071006;
P_0c071006: /* original 64f3, guest PC 0x0c071006 */
if(!s->budget--) { s->failed_pc=0x0c071006u; return 0; }
r[4]=r[15];
goto P_0c071008;
P_0c071008: /* original 65f3, guest PC 0x0c071008 */
if(!s->budget--) { s->failed_pc=0x0c071008u; return 0; }
r[5]=r[15];
goto P_0c07100a;
P_0c07100a: /* original 7438, guest PC 0x0c07100a */
if(!s->budget--) { s->failed_pc=0x0c07100au; return 0; }
r[4]+=0x00000038u;
goto P_0c07100c;
P_0c07100c: /* original f431, guest PC 0x0c07100c */
if(!s->budget--) { s->failed_pc=0x0c07100cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c07100e;
P_0c07100e: /* original 7538, guest PC 0x0c07100e */
if(!s->budget--) { s->failed_pc=0x0c07100eu; return 0; }
r[5]+=0x00000038u;
goto P_0c071010;
P_0c071010: /* original f059, guest PC 0x0c071010 */
if(!s->budget--) { s->failed_pc=0x0c071010u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071012;
P_0c071012: /* original f159, guest PC 0x0c071012 */
if(!s->budget--) { s->failed_pc=0x0c071012u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071014;
P_0c071014: /* original f259, guest PC 0x0c071014 */
if(!s->budget--) { s->failed_pc=0x0c071014u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071016;
P_0c071016: /* original f38d, guest PC 0x0c071016 */
if(!s->budget--) { s->failed_pc=0x0c071016u; return 0; }
fr[3]=0;
goto P_0c071018;
P_0c071018: /* original f0ed, guest PC 0x0c071018 */
if(!s->budget--) { s->failed_pc=0x0c071018u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07101a;
P_0c07101a: /* original f37d, guest PC 0x0c07101a */
if(!s->budget--) { s->failed_pc=0x0c07101au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c07101c;
P_0c07101c: /* original f342, guest PC 0x0c07101c */
if(!s->budget--) { s->failed_pc=0x0c07101cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c07101e;
P_0c07101e: /* original 740c, guest PC 0x0c07101e */
if(!s->budget--) { s->failed_pc=0x0c07101eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c071020;
P_0c071020: /* original f232, guest PC 0x0c071020 */
if(!s->budget--) { s->failed_pc=0x0c071020u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071022;
P_0c071022: /* original f132, guest PC 0x0c071022 */
if(!s->budget--) { s->failed_pc=0x0c071022u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071024;
P_0c071024: /* original f032, guest PC 0x0c071024 */
if(!s->budget--) { s->failed_pc=0x0c071024u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071026;
P_0c071026: /* original f42b, guest PC 0x0c071026 */
if(!s->budget--) { s->failed_pc=0x0c071026u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071028;
P_0c071028: /* original f41b, guest PC 0x0c071028 */
if(!s->budget--) { s->failed_pc=0x0c071028u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07102a;
P_0c07102a: /* original f40b, guest PC 0x0c07102a */
if(!s->budget--) { s->failed_pc=0x0c07102au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07102c;
P_0c07102c: /* original 64f3, guest PC 0x0c07102c */
if(!s->budget--) { s->failed_pc=0x0c07102cu; return 0; }
r[4]=r[15];
goto P_0c07102e;
P_0c07102e: /* original 65f3, guest PC 0x0c07102e */
if(!s->budget--) { s->failed_pc=0x0c07102eu; return 0; }
r[5]=r[15];
goto P_0c071030;
P_0c071030: /* original 7444, guest PC 0x0c071030 */
if(!s->budget--) { s->failed_pc=0x0c071030u; return 0; }
r[4]+=0x00000044u;
goto P_0c071032;
P_0c071032: /* original 7538, guest PC 0x0c071032 */
if(!s->budget--) { s->failed_pc=0x0c071032u; return 0; }
r[5]+=0x00000038u;
goto P_0c071034;
P_0c071034: /* original f049, guest PC 0x0c071034 */
if(!s->budget--) { s->failed_pc=0x0c071034u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071036;
P_0c071036: /* original f359, guest PC 0x0c071036 */
if(!s->budget--) { s->failed_pc=0x0c071036u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071038;
P_0c071038: /* original f149, guest PC 0x0c071038 */
if(!s->budget--) { s->failed_pc=0x0c071038u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07103a;
P_0c07103a: /* original f459, guest PC 0x0c07103a */
if(!s->budget--) { s->failed_pc=0x0c07103au; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07103c;
P_0c07103c: /* original f249, guest PC 0x0c07103c */
if(!s->budget--) { s->failed_pc=0x0c07103cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07103e;
P_0c07103e: /* original f559, guest PC 0x0c07103e */
if(!s->budget--) { s->failed_pc=0x0c07103eu; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071040;
P_0c071040: /* original f030, guest PC 0x0c071040 */
if(!s->budget--) { s->failed_pc=0x0c071040u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c071042;
P_0c071042: /* original f250, guest PC 0x0c071042 */
if(!s->budget--) { s->failed_pc=0x0c071042u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071044;
P_0c071044: /* original f140, guest PC 0x0c071044 */
if(!s->budget--) { s->failed_pc=0x0c071044u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071046;
P_0c071046: /* original f42b, guest PC 0x0c071046 */
if(!s->budget--) { s->failed_pc=0x0c071046u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071048;
P_0c071048: /* original f41b, guest PC 0x0c071048 */
if(!s->budget--) { s->failed_pc=0x0c071048u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07104a;
P_0c07104a: /* original f40b, guest PC 0x0c07104a */
if(!s->budget--) { s->failed_pc=0x0c07104au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07104c;
P_0c07104c: /* original 65f3, guest PC 0x0c07104c */
if(!s->budget--) { s->failed_pc=0x0c07104cu; return 0; }
r[5]=r[15];
goto P_0c07104e;
P_0c07104e: /* original 64d3, guest PC 0x0c07104e */
if(!s->budget--) { s->failed_pc=0x0c07104eu; return 0; }
r[4]=r[13];
goto P_0c071050;
P_0c071050: /* original 7544, guest PC 0x0c071050 */
if(!s->budget--) { s->failed_pc=0x0c071050u; return 0; }
r[5]+=0x00000044u;
goto P_0c071052;
P_0c071052: /* original 6693, guest PC 0x0c071052 */
if(!s->budget--) { s->failed_pc=0x0c071052u; return 0; }
r[6]=r[9];
goto P_0c071054;
P_0c071054: /* original f059, guest PC 0x0c071054 */
if(!s->budget--) { s->failed_pc=0x0c071054u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071056;
P_0c071056: /* original f369, guest PC 0x0c071056 */
if(!s->budget--) { s->failed_pc=0x0c071056u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071058;
P_0c071058: /* original f159, guest PC 0x0c071058 */
if(!s->budget--) { s->failed_pc=0x0c071058u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07105a;
P_0c07105a: /* original f469, guest PC 0x0c07105a */
if(!s->budget--) { s->failed_pc=0x0c07105au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07105c;
P_0c07105c: /* original f259, guest PC 0x0c07105c */
if(!s->budget--) { s->failed_pc=0x0c07105cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07105e;
P_0c07105e: /* original f569, guest PC 0x0c07105e */
if(!s->budget--) { s->failed_pc=0x0c07105eu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071060;
P_0c071060: /* original 740c, guest PC 0x0c071060 */
if(!s->budget--) { s->failed_pc=0x0c071060u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071062;
P_0c071062: /* original f030, guest PC 0x0c071062 */
if(!s->budget--) { s->failed_pc=0x0c071062u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c071064;
P_0c071064: /* original f250, guest PC 0x0c071064 */
if(!s->budget--) { s->failed_pc=0x0c071064u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071066;
P_0c071066: /* original f140, guest PC 0x0c071066 */
if(!s->budget--) { s->failed_pc=0x0c071066u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071068;
P_0c071068: /* original f42b, guest PC 0x0c071068 */
if(!s->budget--) { s->failed_pc=0x0c071068u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07106a;
P_0c07106a: /* original f41b, guest PC 0x0c07106a */
if(!s->budget--) { s->failed_pc=0x0c07106au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07106c;
P_0c07106c: /* original f40b, guest PC 0x0c07106c */
if(!s->budget--) { s->failed_pc=0x0c07106cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07106e;
P_0c07106e: /* original 0009, guest PC 0x0c07106e */
if(!s->budget--) { s->failed_pc=0x0c07106eu; return 0; }
goto P_0c071070;
P_0c071070: /* original 64f3, guest PC 0x0c071070 */
if(!s->budget--) { s->failed_pc=0x0c071070u; return 0; }
r[4]=r[15];
goto P_0c071072;
P_0c071072: /* original 56f1, guest PC 0x0c071072 */
if(!s->budget--) { s->failed_pc=0x0c071072u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c071074;
P_0c071074: /* original 742c, guest PC 0x0c071074 */
if(!s->budget--) { s->failed_pc=0x0c071074u; return 0; }
r[4]+=0x0000002cu;
goto P_0c071076;
P_0c071076: /* original 65d3, guest PC 0x0c071076 */
if(!s->budget--) { s->failed_pc=0x0c071076u; return 0; }
r[5]=r[13];
goto P_0c071078;
P_0c071078: /* original f059, guest PC 0x0c071078 */
if(!s->budget--) { s->failed_pc=0x0c071078u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07107a;
P_0c07107a: /* original f369, guest PC 0x0c07107a */
if(!s->budget--) { s->failed_pc=0x0c07107au; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07107c;
P_0c07107c: /* original f159, guest PC 0x0c07107c */
if(!s->budget--) { s->failed_pc=0x0c07107cu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07107e;
P_0c07107e: /* original f469, guest PC 0x0c07107e */
if(!s->budget--) { s->failed_pc=0x0c07107eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071080;
P_0c071080: /* original f031, guest PC 0x0c071080 */
if(!s->budget--) { s->failed_pc=0x0c071080u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071082;
P_0c071082: /* original f258, guest PC 0x0c071082 */
if(!s->budget--) { s->failed_pc=0x0c071082u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071084;
P_0c071084: /* original f568, guest PC 0x0c071084 */
if(!s->budget--) { s->failed_pc=0x0c071084u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071086;
P_0c071086: /* original f141, guest PC 0x0c071086 */
if(!s->budget--) { s->failed_pc=0x0c071086u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071088;
P_0c071088: /* original f251, guest PC 0x0c071088 */
if(!s->budget--) { s->failed_pc=0x0c071088u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c07108a;
P_0c07108a: /* original 7408, guest PC 0x0c07108a */
if(!s->budget--) { s->failed_pc=0x0c07108au; return 0; }
r[4]+=0x00000008u;
goto P_0c07108c;
P_0c07108c: /* original f42a, guest PC 0x0c07108c */
if(!s->budget--) { s->failed_pc=0x0c07108cu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07108e;
P_0c07108e: /* original f41b, guest PC 0x0c07108e */
if(!s->budget--) { s->failed_pc=0x0c07108eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071090;
P_0c071090: /* original f40b, guest PC 0x0c071090 */
if(!s->budget--) { s->failed_pc=0x0c071090u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071092;
P_0c071092: /* original 0009, guest PC 0x0c071092 */
if(!s->budget--) { s->failed_pc=0x0c071092u; return 0; }
goto P_0c071094;
P_0c071094: /* original 64f3, guest PC 0x0c071094 */
if(!s->budget--) { s->failed_pc=0x0c071094u; return 0; }
r[4]=r[15];
goto P_0c071096;
P_0c071096: /* original 742c, guest PC 0x0c071096 */
if(!s->budget--) { s->failed_pc=0x0c071096u; return 0; }
r[4]+=0x0000002cu;
goto P_0c071098;
P_0c071098: /* original f049, guest PC 0x0c071098 */
if(!s->budget--) { s->failed_pc=0x0c071098u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07109a;
P_0c07109a: /* original f149, guest PC 0x0c07109a */
if(!s->budget--) { s->failed_pc=0x0c07109au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07109c;
P_0c07109c: /* original f249, guest PC 0x0c07109c */
if(!s->budget--) { s->failed_pc=0x0c07109cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07109e;
P_0c07109e: /* original f38d, guest PC 0x0c07109e */
if(!s->budget--) { s->failed_pc=0x0c07109eu; return 0; }
fr[3]=0;
goto P_0c0710a0;
P_0c0710a0: /* original f0ed, guest PC 0x0c0710a0 */
if(!s->budget--) { s->failed_pc=0x0c0710a0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0710a2;
P_0c0710a2: /* original f03c, guest PC 0x0c0710a2 */
if(!s->budget--) { s->failed_pc=0x0c0710a2u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c0710a4;
P_0c0710a4: /* original f06d, guest PC 0x0c0710a4 */
if(!s->budget--) { s->failed_pc=0x0c0710a4u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c0710a6;
P_0c0710a6: /* original 0009, guest PC 0x0c0710a6 */
if(!s->budget--) { s->failed_pc=0x0c0710a6u; return 0; }
goto P_0c0710a8;
P_0c0710a8: /* original f38d, guest PC 0x0c0710a8 */
if(!s->budget--) { s->failed_pc=0x0c0710a8u; return 0; }
fr[3]=0;
goto P_0c0710aa;
P_0c0710aa: /* original f035, guest PC 0x0c0710aa */
if(!s->budget--) { s->failed_pc=0x0c0710aau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])>as_float(fr[3]))!=0);
goto P_0c0710ac;
P_0c0710ac: /* original 8902, guest PC 0x0c0710ac */
if(!s->budget--) { s->failed_pc=0x0c0710acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0710b4; }
goto P_0c0710ae;
P_0c0710ae: /* original d305, guest PC 0x0c0710ae */
if(!s->budget--) { s->failed_pc=0x0c0710aeu; return 0; }
r[3]=read(ram,0x0c0710c4u,4);
goto P_0c0710b0;
P_0c0710b0: /* original 432b, guest PC 0x0c0710b0 */
if(!s->budget--) { s->failed_pc=0x0c0710b0u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0710b2: /* original 0009, guest PC 0x0c0710b2 */
if(!s->budget--) { s->failed_pc=0x0c0710b2u; return 0; }
goto P_0c0710b4;
P_0c0710b4: /* original 64f3, guest PC 0x0c0710b4 */
if(!s->budget--) { s->failed_pc=0x0c0710b4u; return 0; }
r[4]=r[15];
goto P_0c0710b6;
P_0c0710b6: /* original 65f3, guest PC 0x0c0710b6 */
if(!s->budget--) { s->failed_pc=0x0c0710b6u; return 0; }
r[5]=r[15];
goto P_0c0710b8;
P_0c0710b8: /* original 742c, guest PC 0x0c0710b8 */
if(!s->budget--) { s->failed_pc=0x0c0710b8u; return 0; }
r[4]+=0x0000002cu;
goto P_0c0710ba;
P_0c0710ba: /* original f4dc, guest PC 0x0c0710ba */
if(!s->budget--) { s->failed_pc=0x0c0710bau; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0710bc;
P_0c0710bc: /* original 752c, guest PC 0x0c0710bc */
if(!s->budget--) { s->failed_pc=0x0c0710bcu; return 0; }
r[5]+=0x0000002cu;
goto P_0c0710be;
P_0c0710be: /* original a003, guest PC 0x0c0710be */
if(!s->budget--) { s->failed_pc=0x0c0710beu; return 0; }
goto P_0c0710c8;
P_0c0710c0: /* original 0009, guest PC 0x0c0710c0 */
if(!s->budget--) { s->failed_pc=0x0c0710c0u; return 0; }
return vf3_matrix_family(0x0c0710c2u,s,ram);
P_0c0710c8: /* original f059, guest PC 0x0c0710c8 */
if(!s->budget--) { s->failed_pc=0x0c0710c8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710ca;
P_0c0710ca: /* original f159, guest PC 0x0c0710ca */
if(!s->budget--) { s->failed_pc=0x0c0710cau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710cc;
P_0c0710cc: /* original f259, guest PC 0x0c0710cc */
if(!s->budget--) { s->failed_pc=0x0c0710ccu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710ce;
P_0c0710ce: /* original f38d, guest PC 0x0c0710ce */
if(!s->budget--) { s->failed_pc=0x0c0710ceu; return 0; }
fr[3]=0;
goto P_0c0710d0;
P_0c0710d0: /* original f0ed, guest PC 0x0c0710d0 */
if(!s->budget--) { s->failed_pc=0x0c0710d0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0710d2;
P_0c0710d2: /* original f37d, guest PC 0x0c0710d2 */
if(!s->budget--) { s->failed_pc=0x0c0710d2u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0710d4;
P_0c0710d4: /* original f342, guest PC 0x0c0710d4 */
if(!s->budget--) { s->failed_pc=0x0c0710d4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0710d6;
P_0c0710d6: /* original 740c, guest PC 0x0c0710d6 */
if(!s->budget--) { s->failed_pc=0x0c0710d6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0710d8;
P_0c0710d8: /* original f232, guest PC 0x0c0710d8 */
if(!s->budget--) { s->failed_pc=0x0c0710d8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0710da;
P_0c0710da: /* original f132, guest PC 0x0c0710da */
if(!s->budget--) { s->failed_pc=0x0c0710dau; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c0710dc;
P_0c0710dc: /* original f032, guest PC 0x0c0710dc */
if(!s->budget--) { s->failed_pc=0x0c0710dcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c0710de;
P_0c0710de: /* original f42b, guest PC 0x0c0710de */
if(!s->budget--) { s->failed_pc=0x0c0710deu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0710e0;
P_0c0710e0: /* original f41b, guest PC 0x0c0710e0 */
if(!s->budget--) { s->failed_pc=0x0c0710e0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0710e2;
P_0c0710e2: /* original f40b, guest PC 0x0c0710e2 */
if(!s->budget--) { s->failed_pc=0x0c0710e2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0710e4;
P_0c0710e4: /* original 55f1, guest PC 0x0c0710e4 */
if(!s->budget--) { s->failed_pc=0x0c0710e4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0710e6;
P_0c0710e6: /* original 66f3, guest PC 0x0c0710e6 */
if(!s->budget--) { s->failed_pc=0x0c0710e6u; return 0; }
r[6]=r[15];
goto P_0c0710e8;
P_0c0710e8: /* original 64d3, guest PC 0x0c0710e8 */
if(!s->budget--) { s->failed_pc=0x0c0710e8u; return 0; }
r[4]=r[13];
goto P_0c0710ea;
P_0c0710ea: /* original 762c, guest PC 0x0c0710ea */
if(!s->budget--) { s->failed_pc=0x0c0710eau; return 0; }
r[6]+=0x0000002cu;
goto P_0c0710ec;
P_0c0710ec: /* original f059, guest PC 0x0c0710ec */
if(!s->budget--) { s->failed_pc=0x0c0710ecu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710ee;
P_0c0710ee: /* original f369, guest PC 0x0c0710ee */
if(!s->budget--) { s->failed_pc=0x0c0710eeu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0710f0;
P_0c0710f0: /* original f159, guest PC 0x0c0710f0 */
if(!s->budget--) { s->failed_pc=0x0c0710f0u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710f2;
P_0c0710f2: /* original f469, guest PC 0x0c0710f2 */
if(!s->budget--) { s->failed_pc=0x0c0710f2u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0710f4;
P_0c0710f4: /* original f259, guest PC 0x0c0710f4 */
if(!s->budget--) { s->failed_pc=0x0c0710f4u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0710f6;
P_0c0710f6: /* original f569, guest PC 0x0c0710f6 */
if(!s->budget--) { s->failed_pc=0x0c0710f6u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0710f8;
P_0c0710f8: /* original 740c, guest PC 0x0c0710f8 */
if(!s->budget--) { s->failed_pc=0x0c0710f8u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0710fa;
P_0c0710fa: /* original f030, guest PC 0x0c0710fa */
if(!s->budget--) { s->failed_pc=0x0c0710fau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c0710fc;
P_0c0710fc: /* original f250, guest PC 0x0c0710fc */
if(!s->budget--) { s->failed_pc=0x0c0710fcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c0710fe;
P_0c0710fe: /* original f140, guest PC 0x0c0710fe */
if(!s->budget--) { s->failed_pc=0x0c0710feu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071100;
P_0c071100: /* original f42b, guest PC 0x0c071100 */
if(!s->budget--) { s->failed_pc=0x0c071100u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071102;
P_0c071102: /* original f41b, guest PC 0x0c071102 */
if(!s->budget--) { s->failed_pc=0x0c071102u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071104;
P_0c071104: /* original f40b, guest PC 0x0c071104 */
if(!s->budget--) { s->failed_pc=0x0c071104u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071106;
P_0c071106: /* original 0009, guest PC 0x0c071106 */
if(!s->budget--) { s->failed_pc=0x0c071106u; return 0; }
goto P_0c071108;
P_0c071108: /* original 52f1, guest PC 0x0c071108 */
if(!s->budget--) { s->failed_pc=0x0c071108u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07110a;
P_0c07110a: /* original 7d18, guest PC 0x0c07110a */
if(!s->budget--) { s->failed_pc=0x0c07110au; return 0; }
r[13]+=0x00000018u;
goto P_0c07110c;
P_0c07110c: /* original 78e8, guest PC 0x0c07110c */
if(!s->budget--) { s->failed_pc=0x0c07110cu; return 0; }
r[8]+=0xffffffe8u;
goto P_0c07110e;
P_0c07110e: /* original 7218, guest PC 0x0c07110e */
if(!s->budget--) { s->failed_pc=0x0c07110eu; return 0; }
r[2]+=0x00000018u;
goto P_0c071110;
P_0c071110: /* original 1f21, guest PC 0x0c071110 */
if(!s->budget--) { s->failed_pc=0x0c071110u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c071112;
P_0c071112: /* original 7ee8, guest PC 0x0c071112 */
if(!s->budget--) { s->failed_pc=0x0c071112u; return 0; }
r[14]+=0xffffffe8u;
goto P_0c071114;
P_0c071114: /* original 63f2, guest PC 0x0c071114 */
if(!s->budget--) { s->failed_pc=0x0c071114u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c071116;
P_0c071116: /* original 73ff, guest PC 0x0c071116 */
if(!s->budget--) { s->failed_pc=0x0c071116u; return 0; }
r[3]+=0xffffffffu;
goto P_0c071118;
P_0c071118: /* original 4315, guest PC 0x0c071118 */
if(!s->budget--) { s->failed_pc=0x0c071118u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c07111a;
P_0c07111a: /* original 8f03, guest PC 0x0c07111a */
if(!s->budget--) { s->failed_pc=0x0c07111au; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c071124; }
goto P_0c07111e;
P_0c07111c: /* original 2f32, guest PC 0x0c07111c */
if(!s->budget--) { s->failed_pc=0x0c07111cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07111e;
P_0c07111e: /* original d11d, guest PC 0x0c07111e */
if(!s->budget--) { s->failed_pc=0x0c07111eu; return 0; }
r[1]=read(ram,0x0c071194u,4);
goto P_0c071120;
P_0c071120: /* original 412b, guest PC 0x0c071120 */
if(!s->budget--) { s->failed_pc=0x0c071120u; return 0; }
target=r[1];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c071122: /* original 0009, guest PC 0x0c071122 */
if(!s->budget--) { s->failed_pc=0x0c071122u; return 0; }
goto P_0c071124;
P_0c071124: /* original 7f5c, guest PC 0x0c071124 */
if(!s->budget--) { s->failed_pc=0x0c071124u; return 0; }
r[15]+=0x0000005cu;
goto P_0c071126;
P_0c071126: /* original 4f26, guest PC 0x0c071126 */
if(!s->budget--) { s->failed_pc=0x0c071126u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c071128;
P_0c071128: /* original fcf9, guest PC 0x0c071128 */
if(!s->budget--) { s->failed_pc=0x0c071128u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07112a;
P_0c07112a: /* original fdf9, guest PC 0x0c07112a */
if(!s->budget--) { s->failed_pc=0x0c07112au; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07112c;
P_0c07112c: /* original fef9, guest PC 0x0c07112c */
if(!s->budget--) { s->failed_pc=0x0c07112cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07112e;
P_0c07112e: /* original fff9, guest PC 0x0c07112e */
if(!s->budget--) { s->failed_pc=0x0c07112eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c071130;
P_0c071130: /* original 68f6, guest PC 0x0c071130 */
if(!s->budget--) { s->failed_pc=0x0c071130u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c071132;
P_0c071132: /* original 69f6, guest PC 0x0c071132 */
if(!s->budget--) { s->failed_pc=0x0c071132u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c071134;
P_0c071134: /* original 6af6, guest PC 0x0c071134 */
if(!s->budget--) { s->failed_pc=0x0c071134u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c071136;
P_0c071136: /* original 6bf6, guest PC 0x0c071136 */
if(!s->budget--) { s->failed_pc=0x0c071136u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c071138;
P_0c071138: /* original 6cf6, guest PC 0x0c071138 */
if(!s->budget--) { s->failed_pc=0x0c071138u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07113a;
P_0c07113a: /* original 6df6, guest PC 0x0c07113a */
if(!s->budget--) { s->failed_pc=0x0c07113au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07113c;
P_0c07113c: /* original 000b, guest PC 0x0c07113c */
if(!s->budget--) { s->failed_pc=0x0c07113cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07113e: /* original 6ef6, guest PC 0x0c07113e */
if(!s->budget--) { s->failed_pc=0x0c07113eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c071140u,s,ram);
P_0c071890: /* original f40b, guest PC 0x0c071890 */
if(!s->budget--) { s->failed_pc=0x0c071890u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071892;
P_0c071892: /* original 0009, guest PC 0x0c071892 */
if(!s->budget--) { s->failed_pc=0x0c071892u; return 0; }
goto P_0c071894;
P_0c071894: /* original 65f2, guest PC 0x0c071894 */
if(!s->budget--) { s->failed_pc=0x0c071894u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c071896;
P_0c071896: /* original 64a3, guest PC 0x0c071896 */
if(!s->budget--) { s->failed_pc=0x0c071896u; return 0; }
r[4]=r[10];
goto P_0c071898;
P_0c071898: /* original 66e3, guest PC 0x0c071898 */
if(!s->budget--) { s->failed_pc=0x0c071898u; return 0; }
r[6]=r[14];
goto P_0c07189a;
P_0c07189a: /* original f059, guest PC 0x0c07189a */
if(!s->budget--) { s->failed_pc=0x0c07189au; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07189c;
P_0c07189c: /* original f369, guest PC 0x0c07189c */
if(!s->budget--) { s->failed_pc=0x0c07189cu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07189e;
P_0c07189e: /* original f159, guest PC 0x0c07189e */
if(!s->budget--) { s->failed_pc=0x0c07189eu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0718a0;
P_0c0718a0: /* original f469, guest PC 0x0c0718a0 */
if(!s->budget--) { s->failed_pc=0x0c0718a0u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c0718a2;
P_0c0718a2: /* original f031, guest PC 0x0c0718a2 */
if(!s->budget--) { s->failed_pc=0x0c0718a2u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0718a4;
P_0c0718a4: /* original f258, guest PC 0x0c0718a4 */
if(!s->budget--) { s->failed_pc=0x0c0718a4u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c0718a6;
P_0c0718a6: /* original f568, guest PC 0x0c0718a6 */
if(!s->budget--) { s->failed_pc=0x0c0718a6u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c0718a8;
P_0c0718a8: /* original f141, guest PC 0x0c0718a8 */
if(!s->budget--) { s->failed_pc=0x0c0718a8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c0718aa;
P_0c0718aa: /* original f251, guest PC 0x0c0718aa */
if(!s->budget--) { s->failed_pc=0x0c0718aau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c0718ac;
P_0c0718ac: /* original 7408, guest PC 0x0c0718ac */
if(!s->budget--) { s->failed_pc=0x0c0718acu; return 0; }
r[4]+=0x00000008u;
goto P_0c0718ae;
P_0c0718ae: /* original f42a, guest PC 0x0c0718ae */
if(!s->budget--) { s->failed_pc=0x0c0718aeu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0718b0;
P_0c0718b0: /* original f41b, guest PC 0x0c0718b0 */
if(!s->budget--) { s->failed_pc=0x0c0718b0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0718b2;
P_0c0718b2: /* original f40b, guest PC 0x0c0718b2 */
if(!s->budget--) { s->failed_pc=0x0c0718b2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0718b4;
P_0c0718b4: /* original 66e3, guest PC 0x0c0718b4 */
if(!s->budget--) { s->failed_pc=0x0c0718b4u; return 0; }
r[6]=r[14];
goto P_0c0718b6;
P_0c0718b6: /* original 64a3, guest PC 0x0c0718b6 */
if(!s->budget--) { s->failed_pc=0x0c0718b6u; return 0; }
r[4]=r[10];
goto P_0c0718b8;
P_0c0718b8: /* original 65d3, guest PC 0x0c0718b8 */
if(!s->budget--) { s->failed_pc=0x0c0718b8u; return 0; }
r[5]=r[13];
goto P_0c0718ba;
P_0c0718ba: /* original 760c, guest PC 0x0c0718ba */
if(!s->budget--) { s->failed_pc=0x0c0718bau; return 0; }
r[6]+=0x0000000cu;
goto P_0c0718bc;
P_0c0718bc: /* original f049, guest PC 0x0c0718bc */
if(!s->budget--) { s->failed_pc=0x0c0718bcu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0718be;
P_0c0718be: /* original f549, guest PC 0x0c0718be */
if(!s->budget--) { s->failed_pc=0x0c0718beu; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0718c0;
P_0c0718c0: /* original f648, guest PC 0x0c0718c0 */
if(!s->budget--) { s->failed_pc=0x0c0718c0u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0718c2;
P_0c0718c2: /* original f859, guest PC 0x0c0718c2 */
if(!s->budget--) { s->failed_pc=0x0c0718c2u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0718c4;
P_0c0718c4: /* original f959, guest PC 0x0c0718c4 */
if(!s->budget--) { s->failed_pc=0x0c0718c4u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0718c6;
P_0c0718c6: /* original fa58, guest PC 0x0c0718c6 */
if(!s->budget--) { s->failed_pc=0x0c0718c6u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c0718c8;
P_0c0718c8: /* original 760c, guest PC 0x0c0718c8 */
if(!s->budget--) { s->failed_pc=0x0c0718c8u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0718ca;
P_0c0718ca: /* original f35c, guest PC 0x0c0718ca */
if(!s->budget--) { s->failed_pc=0x0c0718cau; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0718cc;
P_0c0718cc: /* original f382, guest PC 0x0c0718cc */
if(!s->budget--) { s->failed_pc=0x0c0718ccu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c0718ce;
P_0c0718ce: /* original f20c, guest PC 0x0c0718ce */
if(!s->budget--) { s->failed_pc=0x0c0718ceu; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c0718d0;
P_0c0718d0: /* original f2a2, guest PC 0x0c0718d0 */
if(!s->budget--) { s->failed_pc=0x0c0718d0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c0718d2;
P_0c0718d2: /* original f16c, guest PC 0x0c0718d2 */
if(!s->budget--) { s->failed_pc=0x0c0718d2u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c0718d4;
P_0c0718d4: /* original f192, guest PC 0x0c0718d4 */
if(!s->budget--) { s->failed_pc=0x0c0718d4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c0718d6;
P_0c0718d6: /* original f34d, guest PC 0x0c0718d6 */
if(!s->budget--) { s->failed_pc=0x0c0718d6u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0718d8;
P_0c0718d8: /* original f39e, guest PC 0x0c0718d8 */
if(!s->budget--) { s->failed_pc=0x0c0718d8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c0718da;
P_0c0718da: /* original f24d, guest PC 0x0c0718da */
if(!s->budget--) { s->failed_pc=0x0c0718dau; return 0; }
fr[2]^=0x80000000u;
goto P_0c0718dc;
P_0c0718dc: /* original f06c, guest PC 0x0c0718dc */
if(!s->budget--) { s->failed_pc=0x0c0718dcu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0718de;
P_0c0718de: /* original f28e, guest PC 0x0c0718de */
if(!s->budget--) { s->failed_pc=0x0c0718deu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c0718e0;
P_0c0718e0: /* original f14d, guest PC 0x0c0718e0 */
if(!s->budget--) { s->failed_pc=0x0c0718e0u; return 0; }
fr[1]^=0x80000000u;
goto P_0c0718e2;
P_0c0718e2: /* original f63b, guest PC 0x0c0718e2 */
if(!s->budget--) { s->failed_pc=0x0c0718e2u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c0718e4;
P_0c0718e4: /* original f05c, guest PC 0x0c0718e4 */
if(!s->budget--) { s->failed_pc=0x0c0718e4u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0718e6;
P_0c0718e6: /* original f1ae, guest PC 0x0c0718e6 */
if(!s->budget--) { s->failed_pc=0x0c0718e6u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c0718e8;
P_0c0718e8: /* original f62b, guest PC 0x0c0718e8 */
if(!s->budget--) { s->failed_pc=0x0c0718e8u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c0718ea;
P_0c0718ea: /* original f61b, guest PC 0x0c0718ea */
if(!s->budget--) { s->failed_pc=0x0c0718eau; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c0718ec;
P_0c0718ec: /* original 64e3, guest PC 0x0c0718ec */
if(!s->budget--) { s->failed_pc=0x0c0718ecu; return 0; }
r[4]=r[14];
goto P_0c0718ee;
P_0c0718ee: /* original 740c, guest PC 0x0c0718ee */
if(!s->budget--) { s->failed_pc=0x0c0718eeu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0718f0;
P_0c0718f0: /* original f049, guest PC 0x0c0718f0 */
if(!s->budget--) { s->failed_pc=0x0c0718f0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0718f2;
P_0c0718f2: /* original f149, guest PC 0x0c0718f2 */
if(!s->budget--) { s->failed_pc=0x0c0718f2u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0718f4;
P_0c0718f4: /* original f249, guest PC 0x0c0718f4 */
if(!s->budget--) { s->failed_pc=0x0c0718f4u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0718f6;
P_0c0718f6: /* original f38d, guest PC 0x0c0718f6 */
if(!s->budget--) { s->failed_pc=0x0c0718f6u; return 0; }
fr[3]=0;
goto P_0c0718f8;
P_0c0718f8: /* original f0ed, guest PC 0x0c0718f8 */
if(!s->budget--) { s->failed_pc=0x0c0718f8u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0718fa;
P_0c0718fa: /* original f37d, guest PC 0x0c0718fa */
if(!s->budget--) { s->failed_pc=0x0c0718fau; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0718fc;
P_0c0718fc: /* original f232, guest PC 0x0c0718fc */
if(!s->budget--) { s->failed_pc=0x0c0718fcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0718fe;
P_0c0718fe: /* original f132, guest PC 0x0c0718fe */
if(!s->budget--) { s->failed_pc=0x0c0718feu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071900;
P_0c071900: /* original f032, guest PC 0x0c071900 */
if(!s->budget--) { s->failed_pc=0x0c071900u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071902;
P_0c071902: /* original f42b, guest PC 0x0c071902 */
if(!s->budget--) { s->failed_pc=0x0c071902u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071904;
P_0c071904: /* original f41b, guest PC 0x0c071904 */
if(!s->budget--) { s->failed_pc=0x0c071904u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071906;
P_0c071906: /* original f40b, guest PC 0x0c071906 */
if(!s->budget--) { s->failed_pc=0x0c071906u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071908;
P_0c071908: /* original 61f3, guest PC 0x0c071908 */
if(!s->budget--) { s->failed_pc=0x0c071908u; return 0; }
r[1]=r[15];
goto P_0c07190a;
P_0c07190a: /* original 7154, guest PC 0x0c07190a */
if(!s->budget--) { s->failed_pc=0x0c07190au; return 0; }
r[1]+=0x00000054u;
goto P_0c07190c;
P_0c07190c: /* original 62f2, guest PC 0x0c07190c */
if(!s->budget--) { s->failed_pc=0x0c07190cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07190e;
P_0c07190e: /* original 6eb3, guest PC 0x0c07190e */
if(!s->budget--) { s->failed_pc=0x0c07190eu; return 0; }
r[14]=r[11];
goto P_0c071910;
P_0c071910: /* original 7218, guest PC 0x0c071910 */
if(!s->budget--) { s->failed_pc=0x0c071910u; return 0; }
r[2]+=0x00000018u;
goto P_0c071912;
P_0c071912: /* original 2f22, guest PC 0x0c071912 */
if(!s->budget--) { s->failed_pc=0x0c071912u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c071914;
P_0c071914: /* original 53f3, guest PC 0x0c071914 */
if(!s->budget--) { s->failed_pc=0x0c071914u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c071916;
P_0c071916: /* original 73ff, guest PC 0x0c071916 */
if(!s->budget--) { s->failed_pc=0x0c071916u; return 0; }
r[3]+=0xffffffffu;
goto P_0c071918;
P_0c071918: /* original 1f34, guest PC 0x0c071918 */
if(!s->budget--) { s->failed_pc=0x0c071918u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c07191a;
P_0c07191a: /* original 1f13, guest PC 0x0c07191a */
if(!s->budget--) { s->failed_pc=0x0c07191au; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c07191c;
P_0c07191c: /* original d103, guest PC 0x0c07191c */
if(!s->budget--) { s->failed_pc=0x0c07191cu; return 0; }
r[1]=read(ram,0x0c07192cu,4);
goto P_0c07191e;
P_0c07191e: /* original 412b, guest PC 0x0c07191e */
if(!s->budget--) { s->failed_pc=0x0c07191eu; return 0; }
target=r[1];
r[11]+=0x00000018u;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c071920: /* original 7b18, guest PC 0x0c071920 */
if(!s->budget--) { s->failed_pc=0x0c071920u; return 0; }
r[11]+=0x00000018u;
return vf3_matrix_family(0x0c071922u,s,ram);
P_0c071dc4: /* original f40b, guest PC 0x0c071dc4 */
if(!s->budget--) { s->failed_pc=0x0c071dc4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071dc6;
P_0c071dc6: /* original 0009, guest PC 0x0c071dc6 */
if(!s->budget--) { s->failed_pc=0x0c071dc6u; return 0; }
goto P_0c071dc8;
P_0c071dc8: /* original 64a3, guest PC 0x0c071dc8 */
if(!s->budget--) { s->failed_pc=0x0c071dc8u; return 0; }
r[4]=r[10];
goto P_0c071dca;
P_0c071dca: /* original 6583, guest PC 0x0c071dca */
if(!s->budget--) { s->failed_pc=0x0c071dcau; return 0; }
r[5]=r[8];
goto P_0c071dcc;
P_0c071dcc: /* original 66e3, guest PC 0x0c071dcc */
if(!s->budget--) { s->failed_pc=0x0c071dccu; return 0; }
r[6]=r[14];
goto P_0c071dce;
P_0c071dce: /* original f059, guest PC 0x0c071dce */
if(!s->budget--) { s->failed_pc=0x0c071dceu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071dd0;
P_0c071dd0: /* original f369, guest PC 0x0c071dd0 */
if(!s->budget--) { s->failed_pc=0x0c071dd0u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071dd2;
P_0c071dd2: /* original f159, guest PC 0x0c071dd2 */
if(!s->budget--) { s->failed_pc=0x0c071dd2u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071dd4;
P_0c071dd4: /* original f469, guest PC 0x0c071dd4 */
if(!s->budget--) { s->failed_pc=0x0c071dd4u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071dd6;
P_0c071dd6: /* original f031, guest PC 0x0c071dd6 */
if(!s->budget--) { s->failed_pc=0x0c071dd6u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071dd8;
P_0c071dd8: /* original f258, guest PC 0x0c071dd8 */
if(!s->budget--) { s->failed_pc=0x0c071dd8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071dda;
P_0c071dda: /* original f568, guest PC 0x0c071dda */
if(!s->budget--) { s->failed_pc=0x0c071ddau; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071ddc;
P_0c071ddc: /* original f141, guest PC 0x0c071ddc */
if(!s->budget--) { s->failed_pc=0x0c071ddcu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071dde;
P_0c071dde: /* original f251, guest PC 0x0c071dde */
if(!s->budget--) { s->failed_pc=0x0c071ddeu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071de0;
P_0c071de0: /* original 7408, guest PC 0x0c071de0 */
if(!s->budget--) { s->failed_pc=0x0c071de0u; return 0; }
r[4]+=0x00000008u;
goto P_0c071de2;
P_0c071de2: /* original f42a, guest PC 0x0c071de2 */
if(!s->budget--) { s->failed_pc=0x0c071de2u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071de4;
P_0c071de4: /* original f41b, guest PC 0x0c071de4 */
if(!s->budget--) { s->failed_pc=0x0c071de4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071de6;
P_0c071de6: /* original f40b, guest PC 0x0c071de6 */
if(!s->budget--) { s->failed_pc=0x0c071de6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071de8;
P_0c071de8: /* original 66e3, guest PC 0x0c071de8 */
if(!s->budget--) { s->failed_pc=0x0c071de8u; return 0; }
r[6]=r[14];
goto P_0c071dea;
P_0c071dea: /* original 64a3, guest PC 0x0c071dea */
if(!s->budget--) { s->failed_pc=0x0c071deau; return 0; }
r[4]=r[10];
goto P_0c071dec;
P_0c071dec: /* original 65d3, guest PC 0x0c071dec */
if(!s->budget--) { s->failed_pc=0x0c071decu; return 0; }
r[5]=r[13];
goto P_0c071dee;
P_0c071dee: /* original 760c, guest PC 0x0c071dee */
if(!s->budget--) { s->failed_pc=0x0c071deeu; return 0; }
r[6]+=0x0000000cu;
goto P_0c071df0;
P_0c071df0: /* original f049, guest PC 0x0c071df0 */
if(!s->budget--) { s->failed_pc=0x0c071df0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071df2;
P_0c071df2: /* original f549, guest PC 0x0c071df2 */
if(!s->budget--) { s->failed_pc=0x0c071df2u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071df4;
P_0c071df4: /* original f648, guest PC 0x0c071df4 */
if(!s->budget--) { s->failed_pc=0x0c071df4u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c071df6;
P_0c071df6: /* original f859, guest PC 0x0c071df6 */
if(!s->budget--) { s->failed_pc=0x0c071df6u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071df8;
P_0c071df8: /* original f959, guest PC 0x0c071df8 */
if(!s->budget--) { s->failed_pc=0x0c071df8u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071dfa;
P_0c071dfa: /* original fa58, guest PC 0x0c071dfa */
if(!s->budget--) { s->failed_pc=0x0c071dfau; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071dfc;
P_0c071dfc: /* original 760c, guest PC 0x0c071dfc */
if(!s->budget--) { s->failed_pc=0x0c071dfcu; return 0; }
r[6]+=0x0000000cu;
goto P_0c071dfe;
P_0c071dfe: /* original f35c, guest PC 0x0c071dfe */
if(!s->budget--) { s->failed_pc=0x0c071dfeu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c071e00;
P_0c071e00: /* original f382, guest PC 0x0c071e00 */
if(!s->budget--) { s->failed_pc=0x0c071e00u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c071e02;
P_0c071e02: /* original f20c, guest PC 0x0c071e02 */
if(!s->budget--) { s->failed_pc=0x0c071e02u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c071e04;
P_0c071e04: /* original f2a2, guest PC 0x0c071e04 */
if(!s->budget--) { s->failed_pc=0x0c071e04u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c071e06;
P_0c071e06: /* original f16c, guest PC 0x0c071e06 */
if(!s->budget--) { s->failed_pc=0x0c071e06u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071e08;
P_0c071e08: /* original f192, guest PC 0x0c071e08 */
if(!s->budget--) { s->failed_pc=0x0c071e08u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071e0a;
P_0c071e0a: /* original f34d, guest PC 0x0c071e0a */
if(!s->budget--) { s->failed_pc=0x0c071e0au; return 0; }
fr[3]^=0x80000000u;
goto P_0c071e0c;
P_0c071e0c: /* original f39e, guest PC 0x0c071e0c */
if(!s->budget--) { s->failed_pc=0x0c071e0cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071e0e;
P_0c071e0e: /* original f24d, guest PC 0x0c071e0e */
if(!s->budget--) { s->failed_pc=0x0c071e0eu; return 0; }
fr[2]^=0x80000000u;
goto P_0c071e10;
P_0c071e10: /* original f06c, guest PC 0x0c071e10 */
if(!s->budget--) { s->failed_pc=0x0c071e10u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c071e12;
P_0c071e12: /* original f28e, guest PC 0x0c071e12 */
if(!s->budget--) { s->failed_pc=0x0c071e12u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c071e14;
P_0c071e14: /* original f14d, guest PC 0x0c071e14 */
if(!s->budget--) { s->failed_pc=0x0c071e14u; return 0; }
fr[1]^=0x80000000u;
goto P_0c071e16;
P_0c071e16: /* original f63b, guest PC 0x0c071e16 */
if(!s->budget--) { s->failed_pc=0x0c071e16u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c071e18;
P_0c071e18: /* original f05c, guest PC 0x0c071e18 */
if(!s->budget--) { s->failed_pc=0x0c071e18u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071e1a;
P_0c071e1a: /* original f1ae, guest PC 0x0c071e1a */
if(!s->budget--) { s->failed_pc=0x0c071e1au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071e1c;
P_0c071e1c: /* original f62b, guest PC 0x0c071e1c */
if(!s->budget--) { s->failed_pc=0x0c071e1cu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c071e1e;
P_0c071e1e: /* original f61b, guest PC 0x0c071e1e */
if(!s->budget--) { s->failed_pc=0x0c071e1eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c071e20;
P_0c071e20: /* original 64e3, guest PC 0x0c071e20 */
if(!s->budget--) { s->failed_pc=0x0c071e20u; return 0; }
r[4]=r[14];
goto P_0c071e22;
P_0c071e22: /* original 740c, guest PC 0x0c071e22 */
if(!s->budget--) { s->failed_pc=0x0c071e22u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071e24;
P_0c071e24: /* original f049, guest PC 0x0c071e24 */
if(!s->budget--) { s->failed_pc=0x0c071e24u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071e26;
P_0c071e26: /* original f149, guest PC 0x0c071e26 */
if(!s->budget--) { s->failed_pc=0x0c071e26u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071e28;
P_0c071e28: /* original f249, guest PC 0x0c071e28 */
if(!s->budget--) { s->failed_pc=0x0c071e28u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071e2a;
P_0c071e2a: /* original f38d, guest PC 0x0c071e2a */
if(!s->budget--) { s->failed_pc=0x0c071e2au; return 0; }
fr[3]=0;
goto P_0c071e2c;
P_0c071e2c: /* original f0ed, guest PC 0x0c071e2c */
if(!s->budget--) { s->failed_pc=0x0c071e2cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071e2e;
P_0c071e2e: /* original f37d, guest PC 0x0c071e2e */
if(!s->budget--) { s->failed_pc=0x0c071e2eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071e30;
P_0c071e30: /* original f232, guest PC 0x0c071e30 */
if(!s->budget--) { s->failed_pc=0x0c071e30u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071e32;
P_0c071e32: /* original f132, guest PC 0x0c071e32 */
if(!s->budget--) { s->failed_pc=0x0c071e32u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071e34;
P_0c071e34: /* original f032, guest PC 0x0c071e34 */
if(!s->budget--) { s->failed_pc=0x0c071e34u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071e36;
P_0c071e36: /* original f42b, guest PC 0x0c071e36 */
if(!s->budget--) { s->failed_pc=0x0c071e36u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071e38;
P_0c071e38: /* original f41b, guest PC 0x0c071e38 */
if(!s->budget--) { s->failed_pc=0x0c071e38u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071e3a;
P_0c071e3a: /* original f40b, guest PC 0x0c071e3a */
if(!s->budget--) { s->failed_pc=0x0c071e3au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071e3c;
P_0c071e3c: /* original 2fe2, guest PC 0x0c071e3c */
if(!s->budget--) { s->failed_pc=0x0c071e3cu; return 0; }
write(ram,r[15],r[14],4);
goto P_0c071e3e;
P_0c071e3e: /* original 6eb3, guest PC 0x0c071e3e */
if(!s->budget--) { s->failed_pc=0x0c071e3eu; return 0; }
r[14]=r[11];
goto P_0c071e40;
P_0c071e40: /* original 53f5, guest PC 0x0c071e40 */
if(!s->budget--) { s->failed_pc=0x0c071e40u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c071e42;
P_0c071e42: /* original 7b18, guest PC 0x0c071e42 */
if(!s->budget--) { s->failed_pc=0x0c071e42u; return 0; }
r[11]+=0x00000018u;
goto P_0c071e44;
P_0c071e44: /* original 6233, guest PC 0x0c071e44 */
if(!s->budget--) { s->failed_pc=0x0c071e44u; return 0; }
r[2]=r[3];
goto P_0c071e46;
P_0c071e46: /* original 3297, guest PC 0x0c071e46 */
if(!s->budget--) { s->failed_pc=0x0c071e46u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[9])!=0);
goto P_0c071e48;
P_0c071e48: /* original 1f31, guest PC 0x0c071e48 */
if(!s->budget--) { s->failed_pc=0x0c071e48u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c071e4a;
P_0c071e4a: /* original 8d03, guest PC 0x0c071e4a */
if(!s->budget--) { s->failed_pc=0x0c071e4au; return 0; }
cond=r[17]&1u;
r[8]+=0x00000018u;
if(cond) { goto P_0c071e54; }
goto P_0c071e4e;
P_0c071e4c: /* original 7818, guest PC 0x0c071e4c */
if(!s->budget--) { s->failed_pc=0x0c071e4cu; return 0; }
r[8]+=0x00000018u;
goto P_0c071e4e;
P_0c071e4e: /* original d304, guest PC 0x0c071e4e */
if(!s->budget--) { s->failed_pc=0x0c071e4eu; return 0; }
r[3]=read(ram,0x0c071e60u,4);
goto P_0c071e50;
P_0c071e50: /* original 432b, guest PC 0x0c071e50 */
if(!s->budget--) { s->failed_pc=0x0c071e50u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c071e52: /* original 0009, guest PC 0x0c071e52 */
if(!s->budget--) { s->failed_pc=0x0c071e52u; return 0; }
goto P_0c071e54;
P_0c071e54: /* original 65f2, guest PC 0x0c071e54 */
if(!s->budget--) { s->failed_pc=0x0c071e54u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c071e56;
P_0c071e56: /* original 64d3, guest PC 0x0c071e56 */
if(!s->budget--) { s->failed_pc=0x0c071e56u; return 0; }
r[4]=r[13];
goto P_0c071e58;
P_0c071e58: /* original 66e3, guest PC 0x0c071e58 */
if(!s->budget--) { s->failed_pc=0x0c071e58u; return 0; }
r[6]=r[14];
goto P_0c071e5a;
P_0c071e5a: /* original a003, guest PC 0x0c071e5a */
if(!s->budget--) { s->failed_pc=0x0c071e5au; return 0; }
goto P_0c071e64;
P_0c071e5c: /* original 0009, guest PC 0x0c071e5c */
if(!s->budget--) { s->failed_pc=0x0c071e5cu; return 0; }
return vf3_matrix_family(0x0c071e5eu,s,ram);
P_0c071e64: /* original f059, guest PC 0x0c071e64 */
if(!s->budget--) { s->failed_pc=0x0c071e64u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071e66;
P_0c071e66: /* original f369, guest PC 0x0c071e66 */
if(!s->budget--) { s->failed_pc=0x0c071e66u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071e68;
P_0c071e68: /* original f159, guest PC 0x0c071e68 */
if(!s->budget--) { s->failed_pc=0x0c071e68u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071e6a;
P_0c071e6a: /* original f469, guest PC 0x0c071e6a */
if(!s->budget--) { s->failed_pc=0x0c071e6au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071e6c;
P_0c071e6c: /* original f031, guest PC 0x0c071e6c */
if(!s->budget--) { s->failed_pc=0x0c071e6cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071e6e;
P_0c071e6e: /* original f258, guest PC 0x0c071e6e */
if(!s->budget--) { s->failed_pc=0x0c071e6eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071e70;
P_0c071e70: /* original f568, guest PC 0x0c071e70 */
if(!s->budget--) { s->failed_pc=0x0c071e70u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071e72;
P_0c071e72: /* original f141, guest PC 0x0c071e72 */
if(!s->budget--) { s->failed_pc=0x0c071e72u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071e74;
P_0c071e74: /* original f251, guest PC 0x0c071e74 */
if(!s->budget--) { s->failed_pc=0x0c071e74u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071e76;
P_0c071e76: /* original 7408, guest PC 0x0c071e76 */
if(!s->budget--) { s->failed_pc=0x0c071e76u; return 0; }
r[4]+=0x00000008u;
goto P_0c071e78;
P_0c071e78: /* original f42a, guest PC 0x0c071e78 */
if(!s->budget--) { s->failed_pc=0x0c071e78u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071e7a;
P_0c071e7a: /* original f41b, guest PC 0x0c071e7a */
if(!s->budget--) { s->failed_pc=0x0c071e7au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071e7c;
P_0c071e7c: /* original f40b, guest PC 0x0c071e7c */
if(!s->budget--) { s->failed_pc=0x0c071e7cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071e7e;
P_0c071e7e: /* original 0009, guest PC 0x0c071e7e */
if(!s->budget--) { s->failed_pc=0x0c071e7eu; return 0; }
goto P_0c071e80;
P_0c071e80: /* original 64a3, guest PC 0x0c071e80 */
if(!s->budget--) { s->failed_pc=0x0c071e80u; return 0; }
r[4]=r[10];
goto P_0c071e82;
P_0c071e82: /* original 65b3, guest PC 0x0c071e82 */
if(!s->budget--) { s->failed_pc=0x0c071e82u; return 0; }
r[5]=r[11];
goto P_0c071e84;
P_0c071e84: /* original 66e3, guest PC 0x0c071e84 */
if(!s->budget--) { s->failed_pc=0x0c071e84u; return 0; }
r[6]=r[14];
goto P_0c071e86;
P_0c071e86: /* original f059, guest PC 0x0c071e86 */
if(!s->budget--) { s->failed_pc=0x0c071e86u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071e88;
P_0c071e88: /* original f369, guest PC 0x0c071e88 */
if(!s->budget--) { s->failed_pc=0x0c071e88u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071e8a;
P_0c071e8a: /* original f159, guest PC 0x0c071e8a */
if(!s->budget--) { s->failed_pc=0x0c071e8au; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071e8c;
P_0c071e8c: /* original f469, guest PC 0x0c071e8c */
if(!s->budget--) { s->failed_pc=0x0c071e8cu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071e8e;
P_0c071e8e: /* original f031, guest PC 0x0c071e8e */
if(!s->budget--) { s->failed_pc=0x0c071e8eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071e90;
P_0c071e90: /* original f258, guest PC 0x0c071e90 */
if(!s->budget--) { s->failed_pc=0x0c071e90u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071e92;
P_0c071e92: /* original f568, guest PC 0x0c071e92 */
if(!s->budget--) { s->failed_pc=0x0c071e92u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071e94;
P_0c071e94: /* original f141, guest PC 0x0c071e94 */
if(!s->budget--) { s->failed_pc=0x0c071e94u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071e96;
P_0c071e96: /* original f251, guest PC 0x0c071e96 */
if(!s->budget--) { s->failed_pc=0x0c071e96u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071e98;
P_0c071e98: /* original 7408, guest PC 0x0c071e98 */
if(!s->budget--) { s->failed_pc=0x0c071e98u; return 0; }
r[4]+=0x00000008u;
goto P_0c071e9a;
P_0c071e9a: /* original f42a, guest PC 0x0c071e9a */
if(!s->budget--) { s->failed_pc=0x0c071e9au; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071e9c;
P_0c071e9c: /* original f41b, guest PC 0x0c071e9c */
if(!s->budget--) { s->failed_pc=0x0c071e9cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071e9e;
P_0c071e9e: /* original f40b, guest PC 0x0c071e9e */
if(!s->budget--) { s->failed_pc=0x0c071e9eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071ea0;
P_0c071ea0: /* original 64c3, guest PC 0x0c071ea0 */
if(!s->budget--) { s->failed_pc=0x0c071ea0u; return 0; }
r[4]=r[12];
goto P_0c071ea2;
P_0c071ea2: /* original 6583, guest PC 0x0c071ea2 */
if(!s->budget--) { s->failed_pc=0x0c071ea2u; return 0; }
r[5]=r[8];
goto P_0c071ea4;
P_0c071ea4: /* original 66e3, guest PC 0x0c071ea4 */
if(!s->budget--) { s->failed_pc=0x0c071ea4u; return 0; }
r[6]=r[14];
goto P_0c071ea6;
P_0c071ea6: /* original f059, guest PC 0x0c071ea6 */
if(!s->budget--) { s->failed_pc=0x0c071ea6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ea8;
P_0c071ea8: /* original f369, guest PC 0x0c071ea8 */
if(!s->budget--) { s->failed_pc=0x0c071ea8u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071eaa;
P_0c071eaa: /* original f159, guest PC 0x0c071eaa */
if(!s->budget--) { s->failed_pc=0x0c071eaau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071eac;
P_0c071eac: /* original f469, guest PC 0x0c071eac */
if(!s->budget--) { s->failed_pc=0x0c071eacu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071eae;
P_0c071eae: /* original f031, guest PC 0x0c071eae */
if(!s->budget--) { s->failed_pc=0x0c071eaeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071eb0;
P_0c071eb0: /* original f258, guest PC 0x0c071eb0 */
if(!s->budget--) { s->failed_pc=0x0c071eb0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071eb2;
P_0c071eb2: /* original f568, guest PC 0x0c071eb2 */
if(!s->budget--) { s->failed_pc=0x0c071eb2u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071eb4;
P_0c071eb4: /* original f141, guest PC 0x0c071eb4 */
if(!s->budget--) { s->failed_pc=0x0c071eb4u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071eb6;
P_0c071eb6: /* original f251, guest PC 0x0c071eb6 */
if(!s->budget--) { s->failed_pc=0x0c071eb6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071eb8;
P_0c071eb8: /* original 7408, guest PC 0x0c071eb8 */
if(!s->budget--) { s->failed_pc=0x0c071eb8u; return 0; }
r[4]+=0x00000008u;
goto P_0c071eba;
P_0c071eba: /* original f42a, guest PC 0x0c071eba */
if(!s->budget--) { s->failed_pc=0x0c071ebau; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071ebc;
P_0c071ebc: /* original f41b, guest PC 0x0c071ebc */
if(!s->budget--) { s->failed_pc=0x0c071ebcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071ebe;
P_0c071ebe: /* original f40b, guest PC 0x0c071ebe */
if(!s->budget--) { s->failed_pc=0x0c071ebeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071ec0;
P_0c071ec0: /* original 66f3, guest PC 0x0c071ec0 */
if(!s->budget--) { s->failed_pc=0x0c071ec0u; return 0; }
r[6]=r[15];
goto P_0c071ec2;
P_0c071ec2: /* original 64c3, guest PC 0x0c071ec2 */
if(!s->budget--) { s->failed_pc=0x0c071ec2u; return 0; }
r[4]=r[12];
goto P_0c071ec4;
P_0c071ec4: /* original 65a3, guest PC 0x0c071ec4 */
if(!s->budget--) { s->failed_pc=0x0c071ec4u; return 0; }
r[5]=r[10];
goto P_0c071ec6;
P_0c071ec6: /* original 7624, guest PC 0x0c071ec6 */
if(!s->budget--) { s->failed_pc=0x0c071ec6u; return 0; }
r[6]+=0x00000024u;
goto P_0c071ec8;
P_0c071ec8: /* original f049, guest PC 0x0c071ec8 */
if(!s->budget--) { s->failed_pc=0x0c071ec8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071eca;
P_0c071eca: /* original f549, guest PC 0x0c071eca */
if(!s->budget--) { s->failed_pc=0x0c071ecau; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071ecc;
P_0c071ecc: /* original f648, guest PC 0x0c071ecc */
if(!s->budget--) { s->failed_pc=0x0c071eccu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c071ece;
P_0c071ece: /* original f859, guest PC 0x0c071ece */
if(!s->budget--) { s->failed_pc=0x0c071eceu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ed0;
P_0c071ed0: /* original f959, guest PC 0x0c071ed0 */
if(!s->budget--) { s->failed_pc=0x0c071ed0u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ed2;
P_0c071ed2: /* original fa58, guest PC 0x0c071ed2 */
if(!s->budget--) { s->failed_pc=0x0c071ed2u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071ed4;
P_0c071ed4: /* original 760c, guest PC 0x0c071ed4 */
if(!s->budget--) { s->failed_pc=0x0c071ed4u; return 0; }
r[6]+=0x0000000cu;
goto P_0c071ed6;
P_0c071ed6: /* original f35c, guest PC 0x0c071ed6 */
if(!s->budget--) { s->failed_pc=0x0c071ed6u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c071ed8;
P_0c071ed8: /* original f382, guest PC 0x0c071ed8 */
if(!s->budget--) { s->failed_pc=0x0c071ed8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c071eda;
P_0c071eda: /* original f20c, guest PC 0x0c071eda */
if(!s->budget--) { s->failed_pc=0x0c071edau; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c071edc;
P_0c071edc: /* original f2a2, guest PC 0x0c071edc */
if(!s->budget--) { s->failed_pc=0x0c071edcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c071ede;
P_0c071ede: /* original f16c, guest PC 0x0c071ede */
if(!s->budget--) { s->failed_pc=0x0c071edeu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071ee0;
P_0c071ee0: /* original f192, guest PC 0x0c071ee0 */
if(!s->budget--) { s->failed_pc=0x0c071ee0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071ee2;
P_0c071ee2: /* original f34d, guest PC 0x0c071ee2 */
if(!s->budget--) { s->failed_pc=0x0c071ee2u; return 0; }
fr[3]^=0x80000000u;
goto P_0c071ee4;
P_0c071ee4: /* original f39e, guest PC 0x0c071ee4 */
if(!s->budget--) { s->failed_pc=0x0c071ee4u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071ee6;
P_0c071ee6: /* original f24d, guest PC 0x0c071ee6 */
if(!s->budget--) { s->failed_pc=0x0c071ee6u; return 0; }
fr[2]^=0x80000000u;
goto P_0c071ee8;
P_0c071ee8: /* original f06c, guest PC 0x0c071ee8 */
if(!s->budget--) { s->failed_pc=0x0c071ee8u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c071eea;
P_0c071eea: /* original f28e, guest PC 0x0c071eea */
if(!s->budget--) { s->failed_pc=0x0c071eeau; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c071eec;
P_0c071eec: /* original f14d, guest PC 0x0c071eec */
if(!s->budget--) { s->failed_pc=0x0c071eecu; return 0; }
fr[1]^=0x80000000u;
goto P_0c071eee;
P_0c071eee: /* original f63b, guest PC 0x0c071eee */
if(!s->budget--) { s->failed_pc=0x0c071eeeu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c071ef0;
P_0c071ef0: /* original f05c, guest PC 0x0c071ef0 */
if(!s->budget--) { s->failed_pc=0x0c071ef0u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071ef2;
P_0c071ef2: /* original f1ae, guest PC 0x0c071ef2 */
if(!s->budget--) { s->failed_pc=0x0c071ef2u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071ef4;
P_0c071ef4: /* original f62b, guest PC 0x0c071ef4 */
if(!s->budget--) { s->failed_pc=0x0c071ef4u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c071ef6;
P_0c071ef6: /* original f61b, guest PC 0x0c071ef6 */
if(!s->budget--) { s->failed_pc=0x0c071ef6u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c071ef8;
P_0c071ef8: /* original 66f3, guest PC 0x0c071ef8 */
if(!s->budget--) { s->failed_pc=0x0c071ef8u; return 0; }
r[6]=r[15];
goto P_0c071efa;
P_0c071efa: /* original 64d3, guest PC 0x0c071efa */
if(!s->budget--) { s->failed_pc=0x0c071efau; return 0; }
r[4]=r[13];
goto P_0c071efc;
P_0c071efc: /* original 65c3, guest PC 0x0c071efc */
if(!s->budget--) { s->failed_pc=0x0c071efcu; return 0; }
r[5]=r[12];
goto P_0c071efe;
P_0c071efe: /* original 7618, guest PC 0x0c071efe */
if(!s->budget--) { s->failed_pc=0x0c071efeu; return 0; }
r[6]+=0x00000018u;
goto P_0c071f00;
P_0c071f00: /* original f049, guest PC 0x0c071f00 */
if(!s->budget--) { s->failed_pc=0x0c071f00u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f02;
P_0c071f02: /* original f549, guest PC 0x0c071f02 */
if(!s->budget--) { s->failed_pc=0x0c071f02u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f04;
P_0c071f04: /* original f648, guest PC 0x0c071f04 */
if(!s->budget--) { s->failed_pc=0x0c071f04u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c071f06;
P_0c071f06: /* original f859, guest PC 0x0c071f06 */
if(!s->budget--) { s->failed_pc=0x0c071f06u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071f08;
P_0c071f08: /* original f959, guest PC 0x0c071f08 */
if(!s->budget--) { s->failed_pc=0x0c071f08u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071f0a;
P_0c071f0a: /* original fa58, guest PC 0x0c071f0a */
if(!s->budget--) { s->failed_pc=0x0c071f0au; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c071f0c;
P_0c071f0c: /* original 760c, guest PC 0x0c071f0c */
if(!s->budget--) { s->failed_pc=0x0c071f0cu; return 0; }
r[6]+=0x0000000cu;
goto P_0c071f0e;
P_0c071f0e: /* original f35c, guest PC 0x0c071f0e */
if(!s->budget--) { s->failed_pc=0x0c071f0eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c071f10;
P_0c071f10: /* original f382, guest PC 0x0c071f10 */
if(!s->budget--) { s->failed_pc=0x0c071f10u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c071f12;
P_0c071f12: /* original f20c, guest PC 0x0c071f12 */
if(!s->budget--) { s->failed_pc=0x0c071f12u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c071f14;
P_0c071f14: /* original f2a2, guest PC 0x0c071f14 */
if(!s->budget--) { s->failed_pc=0x0c071f14u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c071f16;
P_0c071f16: /* original f16c, guest PC 0x0c071f16 */
if(!s->budget--) { s->failed_pc=0x0c071f16u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c071f18;
P_0c071f18: /* original f192, guest PC 0x0c071f18 */
if(!s->budget--) { s->failed_pc=0x0c071f18u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c071f1a;
P_0c071f1a: /* original f34d, guest PC 0x0c071f1a */
if(!s->budget--) { s->failed_pc=0x0c071f1au; return 0; }
fr[3]^=0x80000000u;
goto P_0c071f1c;
P_0c071f1c: /* original f39e, guest PC 0x0c071f1c */
if(!s->budget--) { s->failed_pc=0x0c071f1cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c071f1e;
P_0c071f1e: /* original f24d, guest PC 0x0c071f1e */
if(!s->budget--) { s->failed_pc=0x0c071f1eu; return 0; }
fr[2]^=0x80000000u;
goto P_0c071f20;
P_0c071f20: /* original f06c, guest PC 0x0c071f20 */
if(!s->budget--) { s->failed_pc=0x0c071f20u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c071f22;
P_0c071f22: /* original f28e, guest PC 0x0c071f22 */
if(!s->budget--) { s->failed_pc=0x0c071f22u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c071f24;
P_0c071f24: /* original f14d, guest PC 0x0c071f24 */
if(!s->budget--) { s->failed_pc=0x0c071f24u; return 0; }
fr[1]^=0x80000000u;
goto P_0c071f26;
P_0c071f26: /* original f63b, guest PC 0x0c071f26 */
if(!s->budget--) { s->failed_pc=0x0c071f26u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c071f28;
P_0c071f28: /* original f05c, guest PC 0x0c071f28 */
if(!s->budget--) { s->failed_pc=0x0c071f28u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c071f2a;
P_0c071f2a: /* original f1ae, guest PC 0x0c071f2a */
if(!s->budget--) { s->failed_pc=0x0c071f2au; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c071f2c;
P_0c071f2c: /* original f62b, guest PC 0x0c071f2c */
if(!s->budget--) { s->failed_pc=0x0c071f2cu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c071f2e;
P_0c071f2e: /* original f61b, guest PC 0x0c071f2e */
if(!s->budget--) { s->failed_pc=0x0c071f2eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c071f30;
P_0c071f30: /* original 64f3, guest PC 0x0c071f30 */
if(!s->budget--) { s->failed_pc=0x0c071f30u; return 0; }
r[4]=r[15];
goto P_0c071f32;
P_0c071f32: /* original 7424, guest PC 0x0c071f32 */
if(!s->budget--) { s->failed_pc=0x0c071f32u; return 0; }
r[4]+=0x00000024u;
goto P_0c071f34;
P_0c071f34: /* original f049, guest PC 0x0c071f34 */
if(!s->budget--) { s->failed_pc=0x0c071f34u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f36;
P_0c071f36: /* original f149, guest PC 0x0c071f36 */
if(!s->budget--) { s->failed_pc=0x0c071f36u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f38;
P_0c071f38: /* original f249, guest PC 0x0c071f38 */
if(!s->budget--) { s->failed_pc=0x0c071f38u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f3a;
P_0c071f3a: /* original f38d, guest PC 0x0c071f3a */
if(!s->budget--) { s->failed_pc=0x0c071f3au; return 0; }
fr[3]=0;
goto P_0c071f3c;
P_0c071f3c: /* original f0ed, guest PC 0x0c071f3c */
if(!s->budget--) { s->failed_pc=0x0c071f3cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071f3e;
P_0c071f3e: /* original f37d, guest PC 0x0c071f3e */
if(!s->budget--) { s->failed_pc=0x0c071f3eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071f40;
P_0c071f40: /* original f232, guest PC 0x0c071f40 */
if(!s->budget--) { s->failed_pc=0x0c071f40u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071f42;
P_0c071f42: /* original f132, guest PC 0x0c071f42 */
if(!s->budget--) { s->failed_pc=0x0c071f42u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071f44;
P_0c071f44: /* original f032, guest PC 0x0c071f44 */
if(!s->budget--) { s->failed_pc=0x0c071f44u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071f46;
P_0c071f46: /* original f42b, guest PC 0x0c071f46 */
if(!s->budget--) { s->failed_pc=0x0c071f46u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071f48;
P_0c071f48: /* original f41b, guest PC 0x0c071f48 */
if(!s->budget--) { s->failed_pc=0x0c071f48u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071f4a;
P_0c071f4a: /* original f40b, guest PC 0x0c071f4a */
if(!s->budget--) { s->failed_pc=0x0c071f4au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071f4c;
P_0c071f4c: /* original 64f3, guest PC 0x0c071f4c */
if(!s->budget--) { s->failed_pc=0x0c071f4cu; return 0; }
r[4]=r[15];
goto P_0c071f4e;
P_0c071f4e: /* original 7418, guest PC 0x0c071f4e */
if(!s->budget--) { s->failed_pc=0x0c071f4eu; return 0; }
r[4]+=0x00000018u;
goto P_0c071f50;
P_0c071f50: /* original f049, guest PC 0x0c071f50 */
if(!s->budget--) { s->failed_pc=0x0c071f50u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f52;
P_0c071f52: /* original f149, guest PC 0x0c071f52 */
if(!s->budget--) { s->failed_pc=0x0c071f52u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f54;
P_0c071f54: /* original f249, guest PC 0x0c071f54 */
if(!s->budget--) { s->failed_pc=0x0c071f54u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f56;
P_0c071f56: /* original f38d, guest PC 0x0c071f56 */
if(!s->budget--) { s->failed_pc=0x0c071f56u; return 0; }
fr[3]=0;
goto P_0c071f58;
P_0c071f58: /* original f0ed, guest PC 0x0c071f58 */
if(!s->budget--) { s->failed_pc=0x0c071f58u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071f5a;
P_0c071f5a: /* original f37d, guest PC 0x0c071f5a */
if(!s->budget--) { s->failed_pc=0x0c071f5au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071f5c;
P_0c071f5c: /* original f232, guest PC 0x0c071f5c */
if(!s->budget--) { s->failed_pc=0x0c071f5cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071f5e;
P_0c071f5e: /* original f132, guest PC 0x0c071f5e */
if(!s->budget--) { s->failed_pc=0x0c071f5eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071f60;
P_0c071f60: /* original f032, guest PC 0x0c071f60 */
if(!s->budget--) { s->failed_pc=0x0c071f60u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071f62;
P_0c071f62: /* original f42b, guest PC 0x0c071f62 */
if(!s->budget--) { s->failed_pc=0x0c071f62u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071f64;
P_0c071f64: /* original f41b, guest PC 0x0c071f64 */
if(!s->budget--) { s->failed_pc=0x0c071f64u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071f66;
P_0c071f66: /* original f40b, guest PC 0x0c071f66 */
if(!s->budget--) { s->failed_pc=0x0c071f66u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071f68;
P_0c071f68: /* original 65f3, guest PC 0x0c071f68 */
if(!s->budget--) { s->failed_pc=0x0c071f68u; return 0; }
r[5]=r[15];
goto P_0c071f6a;
P_0c071f6a: /* original 64e3, guest PC 0x0c071f6a */
if(!s->budget--) { s->failed_pc=0x0c071f6au; return 0; }
r[4]=r[14];
goto P_0c071f6c;
P_0c071f6c: /* original 66f3, guest PC 0x0c071f6c */
if(!s->budget--) { s->failed_pc=0x0c071f6cu; return 0; }
r[6]=r[15];
goto P_0c071f6e;
P_0c071f6e: /* original 740c, guest PC 0x0c071f6e */
if(!s->budget--) { s->failed_pc=0x0c071f6eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c071f70;
P_0c071f70: /* original 7618, guest PC 0x0c071f70 */
if(!s->budget--) { s->failed_pc=0x0c071f70u; return 0; }
r[6]+=0x00000018u;
goto P_0c071f72;
P_0c071f72: /* original 7524, guest PC 0x0c071f72 */
if(!s->budget--) { s->failed_pc=0x0c071f72u; return 0; }
r[5]+=0x00000024u;
goto P_0c071f74;
P_0c071f74: /* original f059, guest PC 0x0c071f74 */
if(!s->budget--) { s->failed_pc=0x0c071f74u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071f76;
P_0c071f76: /* original f369, guest PC 0x0c071f76 */
if(!s->budget--) { s->failed_pc=0x0c071f76u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071f78;
P_0c071f78: /* original f159, guest PC 0x0c071f78 */
if(!s->budget--) { s->failed_pc=0x0c071f78u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071f7a;
P_0c071f7a: /* original f469, guest PC 0x0c071f7a */
if(!s->budget--) { s->failed_pc=0x0c071f7au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071f7c;
P_0c071f7c: /* original f259, guest PC 0x0c071f7c */
if(!s->budget--) { s->failed_pc=0x0c071f7cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071f7e;
P_0c071f7e: /* original f569, guest PC 0x0c071f7e */
if(!s->budget--) { s->failed_pc=0x0c071f7eu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071f80;
P_0c071f80: /* original 740c, guest PC 0x0c071f80 */
if(!s->budget--) { s->failed_pc=0x0c071f80u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071f82;
P_0c071f82: /* original f030, guest PC 0x0c071f82 */
if(!s->budget--) { s->failed_pc=0x0c071f82u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c071f84;
P_0c071f84: /* original f250, guest PC 0x0c071f84 */
if(!s->budget--) { s->failed_pc=0x0c071f84u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071f86;
P_0c071f86: /* original f140, guest PC 0x0c071f86 */
if(!s->budget--) { s->failed_pc=0x0c071f86u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071f88;
P_0c071f88: /* original f42b, guest PC 0x0c071f88 */
if(!s->budget--) { s->failed_pc=0x0c071f88u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071f8a;
P_0c071f8a: /* original f41b, guest PC 0x0c071f8a */
if(!s->budget--) { s->failed_pc=0x0c071f8au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071f8c;
P_0c071f8c: /* original f40b, guest PC 0x0c071f8c */
if(!s->budget--) { s->failed_pc=0x0c071f8cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071f8e;
P_0c071f8e: /* original 0009, guest PC 0x0c071f8e */
if(!s->budget--) { s->failed_pc=0x0c071f8eu; return 0; }
goto P_0c071f90;
P_0c071f90: /* original 64e3, guest PC 0x0c071f90 */
if(!s->budget--) { s->failed_pc=0x0c071f90u; return 0; }
r[4]=r[14];
goto P_0c071f92;
P_0c071f92: /* original 740c, guest PC 0x0c071f92 */
if(!s->budget--) { s->failed_pc=0x0c071f92u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071f94;
P_0c071f94: /* original f049, guest PC 0x0c071f94 */
if(!s->budget--) { s->failed_pc=0x0c071f94u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f96;
P_0c071f96: /* original f149, guest PC 0x0c071f96 */
if(!s->budget--) { s->failed_pc=0x0c071f96u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f98;
P_0c071f98: /* original f249, guest PC 0x0c071f98 */
if(!s->budget--) { s->failed_pc=0x0c071f98u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071f9a;
P_0c071f9a: /* original f38d, guest PC 0x0c071f9a */
if(!s->budget--) { s->failed_pc=0x0c071f9au; return 0; }
fr[3]=0;
goto P_0c071f9c;
P_0c071f9c: /* original f0ed, guest PC 0x0c071f9c */
if(!s->budget--) { s->failed_pc=0x0c071f9cu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c071f9e;
P_0c071f9e: /* original f37d, guest PC 0x0c071f9e */
if(!s->budget--) { s->failed_pc=0x0c071f9eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c071fa0;
P_0c071fa0: /* original f232, guest PC 0x0c071fa0 */
if(!s->budget--) { s->failed_pc=0x0c071fa0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071fa2;
P_0c071fa2: /* original f132, guest PC 0x0c071fa2 */
if(!s->budget--) { s->failed_pc=0x0c071fa2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071fa4;
P_0c071fa4: /* original f032, guest PC 0x0c071fa4 */
if(!s->budget--) { s->failed_pc=0x0c071fa4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071fa6;
P_0c071fa6: /* original f42b, guest PC 0x0c071fa6 */
if(!s->budget--) { s->failed_pc=0x0c071fa6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071fa8;
P_0c071fa8: /* original f41b, guest PC 0x0c071fa8 */
if(!s->budget--) { s->failed_pc=0x0c071fa8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071faa;
P_0c071faa: /* original f40b, guest PC 0x0c071faa */
if(!s->budget--) { s->failed_pc=0x0c071faau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071fac;
P_0c071fac: /* original 2fe2, guest PC 0x0c071fac */
if(!s->budget--) { s->failed_pc=0x0c071facu; return 0; }
write(ram,r[15],r[14],4);
goto P_0c071fae;
P_0c071fae: /* original 6eb3, guest PC 0x0c071fae */
if(!s->budget--) { s->failed_pc=0x0c071faeu; return 0; }
r[14]=r[11];
goto P_0c071fb0;
P_0c071fb0: /* original 53f1, guest PC 0x0c071fb0 */
if(!s->budget--) { s->failed_pc=0x0c071fb0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c071fb2;
P_0c071fb2: /* original 7b18, guest PC 0x0c071fb2 */
if(!s->budget--) { s->failed_pc=0x0c071fb2u; return 0; }
r[11]+=0x00000018u;
goto P_0c071fb4;
P_0c071fb4: /* original 7818, guest PC 0x0c071fb4 */
if(!s->budget--) { s->failed_pc=0x0c071fb4u; return 0; }
r[8]+=0x00000018u;
goto P_0c071fb6;
P_0c071fb6: /* original 73ff, guest PC 0x0c071fb6 */
if(!s->budget--) { s->failed_pc=0x0c071fb6u; return 0; }
r[3]+=0xffffffffu;
goto P_0c071fb8;
P_0c071fb8: /* original 3397, guest PC 0x0c071fb8 */
if(!s->budget--) { s->failed_pc=0x0c071fb8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[9])!=0);
goto P_0c071fba;
P_0c071fba: /* original 8f03, guest PC 0x0c071fba */
if(!s->budget--) { s->failed_pc=0x0c071fbau; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[3],4);
if(!cond) { goto P_0c071fc4; }
goto P_0c071fbe;
P_0c071fbc: /* original 1f31, guest PC 0x0c071fbc */
if(!s->budget--) { s->failed_pc=0x0c071fbcu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c071fbe;
P_0c071fbe: /* original d204, guest PC 0x0c071fbe */
if(!s->budget--) { s->failed_pc=0x0c071fbeu; return 0; }
r[2]=read(ram,0x0c071fd0u,4);
goto P_0c071fc0;
P_0c071fc0: /* original 422b, guest PC 0x0c071fc0 */
if(!s->budget--) { s->failed_pc=0x0c071fc0u; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c071fc2: /* original 0009, guest PC 0x0c071fc2 */
if(!s->budget--) { s->failed_pc=0x0c071fc2u; return 0; }
goto P_0c071fc4;
P_0c071fc4: /* original 65f2, guest PC 0x0c071fc4 */
if(!s->budget--) { s->failed_pc=0x0c071fc4u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c071fc6;
P_0c071fc6: /* original 64d3, guest PC 0x0c071fc6 */
if(!s->budget--) { s->failed_pc=0x0c071fc6u; return 0; }
r[4]=r[13];
goto P_0c071fc8;
P_0c071fc8: /* original 66e3, guest PC 0x0c071fc8 */
if(!s->budget--) { s->failed_pc=0x0c071fc8u; return 0; }
r[6]=r[14];
goto P_0c071fca;
P_0c071fca: /* original a003, guest PC 0x0c071fca */
if(!s->budget--) { s->failed_pc=0x0c071fcau; return 0; }
goto P_0c071fd4;
P_0c071fcc: /* original 0009, guest PC 0x0c071fcc */
if(!s->budget--) { s->failed_pc=0x0c071fccu; return 0; }
return vf3_matrix_family(0x0c071fceu,s,ram);
P_0c071fd4: /* original f059, guest PC 0x0c071fd4 */
if(!s->budget--) { s->failed_pc=0x0c071fd4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071fd6;
P_0c071fd6: /* original f369, guest PC 0x0c071fd6 */
if(!s->budget--) { s->failed_pc=0x0c071fd6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071fd8;
P_0c071fd8: /* original f159, guest PC 0x0c071fd8 */
if(!s->budget--) { s->failed_pc=0x0c071fd8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071fda;
P_0c071fda: /* original f469, guest PC 0x0c071fda */
if(!s->budget--) { s->failed_pc=0x0c071fdau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071fdc;
P_0c071fdc: /* original f031, guest PC 0x0c071fdc */
if(!s->budget--) { s->failed_pc=0x0c071fdcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c071fde;
P_0c071fde: /* original f258, guest PC 0x0c071fde */
if(!s->budget--) { s->failed_pc=0x0c071fdeu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c071fe0;
P_0c071fe0: /* original f568, guest PC 0x0c071fe0 */
if(!s->budget--) { s->failed_pc=0x0c071fe0u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c071fe2;
P_0c071fe2: /* original f141, guest PC 0x0c071fe2 */
if(!s->budget--) { s->failed_pc=0x0c071fe2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c071fe4;
P_0c071fe4: /* original f251, guest PC 0x0c071fe4 */
if(!s->budget--) { s->failed_pc=0x0c071fe4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c071fe6;
P_0c071fe6: /* original 7408, guest PC 0x0c071fe6 */
if(!s->budget--) { s->failed_pc=0x0c071fe6u; return 0; }
r[4]+=0x00000008u;
goto P_0c071fe8;
P_0c071fe8: /* original f42a, guest PC 0x0c071fe8 */
if(!s->budget--) { s->failed_pc=0x0c071fe8u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071fea;
P_0c071fea: /* original f41b, guest PC 0x0c071fea */
if(!s->budget--) { s->failed_pc=0x0c071feau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c071fec;
P_0c071fec: /* original f40b, guest PC 0x0c071fec */
if(!s->budget--) { s->failed_pc=0x0c071fecu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c071fee;
P_0c071fee: /* original 0009, guest PC 0x0c071fee */
if(!s->budget--) { s->failed_pc=0x0c071feeu; return 0; }
goto P_0c071ff0;
P_0c071ff0: /* original 64a3, guest PC 0x0c071ff0 */
if(!s->budget--) { s->failed_pc=0x0c071ff0u; return 0; }
r[4]=r[10];
goto P_0c071ff2;
P_0c071ff2: /* original 6583, guest PC 0x0c071ff2 */
if(!s->budget--) { s->failed_pc=0x0c071ff2u; return 0; }
r[5]=r[8];
goto P_0c071ff4;
P_0c071ff4: /* original 66e3, guest PC 0x0c071ff4 */
if(!s->budget--) { s->failed_pc=0x0c071ff4u; return 0; }
r[6]=r[14];
goto P_0c071ff6;
P_0c071ff6: /* original f059, guest PC 0x0c071ff6 */
if(!s->budget--) { s->failed_pc=0x0c071ff6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ff8;
P_0c071ff8: /* original f369, guest PC 0x0c071ff8 */
if(!s->budget--) { s->failed_pc=0x0c071ff8u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071ffa;
P_0c071ffa: /* original f159, guest PC 0x0c071ffa */
if(!s->budget--) { s->failed_pc=0x0c071ffau; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071ffc;
P_0c071ffc: /* original f469, guest PC 0x0c071ffc */
if(!s->budget--) { s->failed_pc=0x0c071ffcu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071ffe;
P_0c071ffe: /* original f031, guest PC 0x0c071ffe */
if(!s->budget--) { s->failed_pc=0x0c071ffeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c072000;
P_0c072000: /* original f258, guest PC 0x0c072000 */
if(!s->budget--) { s->failed_pc=0x0c072000u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c072002;
P_0c072002: /* original f568, guest PC 0x0c072002 */
if(!s->budget--) { s->failed_pc=0x0c072002u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c072004;
P_0c072004: /* original f141, guest PC 0x0c072004 */
if(!s->budget--) { s->failed_pc=0x0c072004u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c072006;
P_0c072006: /* original f251, guest PC 0x0c072006 */
if(!s->budget--) { s->failed_pc=0x0c072006u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c072008;
P_0c072008: /* original 7408, guest PC 0x0c072008 */
if(!s->budget--) { s->failed_pc=0x0c072008u; return 0; }
r[4]+=0x00000008u;
goto P_0c07200a;
P_0c07200a: /* original f42a, guest PC 0x0c07200a */
if(!s->budget--) { s->failed_pc=0x0c07200au; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07200c;
P_0c07200c: /* original f41b, guest PC 0x0c07200c */
if(!s->budget--) { s->failed_pc=0x0c07200cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07200e;
P_0c07200e: /* original f40b, guest PC 0x0c07200e */
if(!s->budget--) { s->failed_pc=0x0c07200eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072010;
P_0c072010: /* original 66e3, guest PC 0x0c072010 */
if(!s->budget--) { s->failed_pc=0x0c072010u; return 0; }
r[6]=r[14];
goto P_0c072012;
P_0c072012: /* original 64d3, guest PC 0x0c072012 */
if(!s->budget--) { s->failed_pc=0x0c072012u; return 0; }
r[4]=r[13];
goto P_0c072014;
P_0c072014: /* original 65a3, guest PC 0x0c072014 */
if(!s->budget--) { s->failed_pc=0x0c072014u; return 0; }
r[5]=r[10];
goto P_0c072016;
P_0c072016: /* original 760c, guest PC 0x0c072016 */
if(!s->budget--) { s->failed_pc=0x0c072016u; return 0; }
r[6]+=0x0000000cu;
goto P_0c072018;
P_0c072018: /* original f049, guest PC 0x0c072018 */
if(!s->budget--) { s->failed_pc=0x0c072018u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07201a;
P_0c07201a: /* original f549, guest PC 0x0c07201a */
if(!s->budget--) { s->failed_pc=0x0c07201au; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07201c;
P_0c07201c: /* original f648, guest PC 0x0c07201c */
if(!s->budget--) { s->failed_pc=0x0c07201cu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c07201e;
P_0c07201e: /* original f859, guest PC 0x0c07201e */
if(!s->budget--) { s->failed_pc=0x0c07201eu; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072020;
P_0c072020: /* original f959, guest PC 0x0c072020 */
if(!s->budget--) { s->failed_pc=0x0c072020u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c072022;
P_0c072022: /* original fa58, guest PC 0x0c072022 */
if(!s->budget--) { s->failed_pc=0x0c072022u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c072024;
P_0c072024: /* original 760c, guest PC 0x0c072024 */
if(!s->budget--) { s->failed_pc=0x0c072024u; return 0; }
r[6]+=0x0000000cu;
goto P_0c072026;
P_0c072026: /* original f35c, guest PC 0x0c072026 */
if(!s->budget--) { s->failed_pc=0x0c072026u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c072028;
P_0c072028: /* original f382, guest PC 0x0c072028 */
if(!s->budget--) { s->failed_pc=0x0c072028u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c07202a;
P_0c07202a: /* original f20c, guest PC 0x0c07202a */
if(!s->budget--) { s->failed_pc=0x0c07202au; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c07202c;
P_0c07202c: /* original f2a2, guest PC 0x0c07202c */
if(!s->budget--) { s->failed_pc=0x0c07202cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c07202e;
P_0c07202e: /* original f16c, guest PC 0x0c07202e */
if(!s->budget--) { s->failed_pc=0x0c07202eu; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c072030;
P_0c072030: /* original f192, guest PC 0x0c072030 */
if(!s->budget--) { s->failed_pc=0x0c072030u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c072032;
P_0c072032: /* original f34d, guest PC 0x0c072032 */
if(!s->budget--) { s->failed_pc=0x0c072032u; return 0; }
fr[3]^=0x80000000u;
goto P_0c072034;
P_0c072034: /* original f39e, guest PC 0x0c072034 */
if(!s->budget--) { s->failed_pc=0x0c072034u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c072036;
P_0c072036: /* original f24d, guest PC 0x0c072036 */
if(!s->budget--) { s->failed_pc=0x0c072036u; return 0; }
fr[2]^=0x80000000u;
goto P_0c072038;
P_0c072038: /* original f06c, guest PC 0x0c072038 */
if(!s->budget--) { s->failed_pc=0x0c072038u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c07203a;
P_0c07203a: /* original f28e, guest PC 0x0c07203a */
if(!s->budget--) { s->failed_pc=0x0c07203au; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c07203c;
P_0c07203c: /* original f14d, guest PC 0x0c07203c */
if(!s->budget--) { s->failed_pc=0x0c07203cu; return 0; }
fr[1]^=0x80000000u;
goto P_0c07203e;
P_0c07203e: /* original f63b, guest PC 0x0c07203e */
if(!s->budget--) { s->failed_pc=0x0c07203eu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c072040;
P_0c072040: /* original f05c, guest PC 0x0c072040 */
if(!s->budget--) { s->failed_pc=0x0c072040u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c072042;
P_0c072042: /* original f1ae, guest PC 0x0c072042 */
if(!s->budget--) { s->failed_pc=0x0c072042u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c072044;
P_0c072044: /* original f62b, guest PC 0x0c072044 */
if(!s->budget--) { s->failed_pc=0x0c072044u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c072046;
P_0c072046: /* original f61b, guest PC 0x0c072046 */
if(!s->budget--) { s->failed_pc=0x0c072046u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c072048;
P_0c072048: /* original 64e3, guest PC 0x0c072048 */
if(!s->budget--) { s->failed_pc=0x0c072048u; return 0; }
r[4]=r[14];
goto P_0c07204a;
P_0c07204a: /* original 740c, guest PC 0x0c07204a */
if(!s->budget--) { s->failed_pc=0x0c07204au; return 0; }
r[4]+=0x0000000cu;
goto P_0c07204c;
P_0c07204c: /* original f049, guest PC 0x0c07204c */
if(!s->budget--) { s->failed_pc=0x0c07204cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07204e;
P_0c07204e: /* original f149, guest PC 0x0c07204e */
if(!s->budget--) { s->failed_pc=0x0c07204eu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072050;
P_0c072050: /* original f249, guest PC 0x0c072050 */
if(!s->budget--) { s->failed_pc=0x0c072050u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c072052;
P_0c072052: /* original f38d, guest PC 0x0c072052 */
if(!s->budget--) { s->failed_pc=0x0c072052u; return 0; }
fr[3]=0;
goto P_0c072054;
P_0c072054: /* original f0ed, guest PC 0x0c072054 */
if(!s->budget--) { s->failed_pc=0x0c072054u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c072056;
P_0c072056: /* original f37d, guest PC 0x0c072056 */
if(!s->budget--) { s->failed_pc=0x0c072056u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c072058;
P_0c072058: /* original f232, guest PC 0x0c072058 */
if(!s->budget--) { s->failed_pc=0x0c072058u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c07205a;
P_0c07205a: /* original f132, guest PC 0x0c07205a */
if(!s->budget--) { s->failed_pc=0x0c07205au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c07205c;
P_0c07205c: /* original f032, guest PC 0x0c07205c */
if(!s->budget--) { s->failed_pc=0x0c07205cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c07205e;
P_0c07205e: /* original f42b, guest PC 0x0c07205e */
if(!s->budget--) { s->failed_pc=0x0c07205eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c072060;
P_0c072060: /* original f41b, guest PC 0x0c072060 */
if(!s->budget--) { s->failed_pc=0x0c072060u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c072062;
P_0c072062: /* original f40b, guest PC 0x0c072062 */
if(!s->budget--) { s->failed_pc=0x0c072062u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c072064;
P_0c072064: /* original 7f60, guest PC 0x0c072064 */
if(!s->budget--) { s->failed_pc=0x0c072064u; return 0; }
r[15]+=0x00000060u;
goto P_0c072066;
P_0c072066: /* original 68f6, guest PC 0x0c072066 */
if(!s->budget--) { s->failed_pc=0x0c072066u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c072068;
P_0c072068: /* original 69f6, guest PC 0x0c072068 */
if(!s->budget--) { s->failed_pc=0x0c072068u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07206a;
P_0c07206a: /* original 6af6, guest PC 0x0c07206a */
if(!s->budget--) { s->failed_pc=0x0c07206au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07206c;
P_0c07206c: /* original 6bf6, guest PC 0x0c07206c */
if(!s->budget--) { s->failed_pc=0x0c07206cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07206e;
P_0c07206e: /* original 6cf6, guest PC 0x0c07206e */
if(!s->budget--) { s->failed_pc=0x0c07206eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c072070;
P_0c072070: /* original 6df6, guest PC 0x0c072070 */
if(!s->budget--) { s->failed_pc=0x0c072070u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c072072;
P_0c072072: /* original 000b, guest PC 0x0c072072 */
if(!s->budget--) { s->failed_pc=0x0c072072u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c072074: /* original 6ef6, guest PC 0x0c072074 */
if(!s->budget--) { s->failed_pc=0x0c072074u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c072076u,s,ram);
P_0c073f82: /* original 4f22, guest PC 0x0c073f82 */
if(!s->budget--) { s->failed_pc=0x0c073f82u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c073f84;
P_0c073f84: /* original 7ff8, guest PC 0x0c073f84 */
if(!s->budget--) { s->failed_pc=0x0c073f84u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c073f86;
P_0c073f86: /* original 2f42, guest PC 0x0c073f86 */
if(!s->budget--) { s->failed_pc=0x0c073f86u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c073f88;
P_0c073f88: /* original 1f51, guest PC 0x0c073f88 */
if(!s->budget--) { s->failed_pc=0x0c073f88u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c073f8a;
P_0c073f8a: /* original d11e, guest PC 0x0c073f8a */
if(!s->budget--) { s->failed_pc=0x0c073f8au; return 0; }
r[1]=read(ram,0x0c074004u,4);
goto P_0c073f8c;
P_0c073f8c: /* original d31c, guest PC 0x0c073f8c */
if(!s->budget--) { s->failed_pc=0x0c073f8cu; return 0; }
r[3]=read(ram,0x0c074000u,4);
goto P_0c073f8e;
P_0c073f8e: /* original 6212, guest PC 0x0c073f8e */
if(!s->budget--) { s->failed_pc=0x0c073f8eu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c073f90;
P_0c073f90: /* original 2238, guest PC 0x0c073f90 */
if(!s->budget--) { s->failed_pc=0x0c073f90u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c073f92;
P_0c073f92: /* original 8b0b, guest PC 0x0c073f92 */
if(!s->budget--) { s->failed_pc=0x0c073f92u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073fac; }
goto P_0c073f94;
P_0c073f94: /* original d31c, guest PC 0x0c073f94 */
if(!s->budget--) { s->failed_pc=0x0c073f94u; return 0; }
r[3]=read(ram,0x0c074008u,4);
goto P_0c073f96;
P_0c073f96: /* original 6030, guest PC 0x0c073f96 */
if(!s->budget--) { s->failed_pc=0x0c073f96u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c073f98;
P_0c073f98: /* original 600c, guest PC 0x0c073f98 */
if(!s->budget--) { s->failed_pc=0x0c073f98u; return 0; }
r[0]=r[0]&255u;
goto P_0c073f9a;
P_0c073f9a: /* original c90f, guest PC 0x0c073f9a */
if(!s->budget--) { s->failed_pc=0x0c073f9au; return 0; }
r[0]&=15u;
goto P_0c073f9c;
P_0c073f9c: /* original 880d, guest PC 0x0c073f9c */
if(!s->budget--) { s->failed_pc=0x0c073f9cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c073f9e;
P_0c073f9e: /* original 8905, guest PC 0x0c073f9e */
if(!s->budget--) { s->failed_pc=0x0c073f9eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c073fac; }
goto P_0c073fa0;
P_0c073fa0: /* original 55f1, guest PC 0x0c073fa0 */
if(!s->budget--) { s->failed_pc=0x0c073fa0u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c073fa2;
P_0c073fa2: /* original b007, guest PC 0x0c073fa2 */
if(!s->budget--) { s->failed_pc=0x0c073fa2u; return 0; }
target=0x0c073fb4u; r[16]=0x0c073fa6u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073fa6u) { target=s->pc; goto dispatch; }
goto P_0c073fa6;
P_0c073fa4: /* original 64f2, guest PC 0x0c073fa4 */
if(!s->budget--) { s->failed_pc=0x0c073fa4u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c073fa6;
P_0c073fa6: /* original 65f2, guest PC 0x0c073fa6 */
if(!s->budget--) { s->failed_pc=0x0c073fa6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c073fa8;
P_0c073fa8: /* original b004, guest PC 0x0c073fa8 */
if(!s->budget--) { s->failed_pc=0x0c073fa8u; return 0; }
target=0x0c073fb4u; r[16]=0x0c073facu;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073facu) { target=s->pc; goto dispatch; }
goto P_0c073fac;
P_0c073faa: /* original 54f1, guest PC 0x0c073faa */
if(!s->budget--) { s->failed_pc=0x0c073faau; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c073fac;
P_0c073fac: /* original 7f08, guest PC 0x0c073fac */
if(!s->budget--) { s->failed_pc=0x0c073facu; return 0; }
r[15]+=0x00000008u;
goto P_0c073fae;
P_0c073fae: /* original 4f26, guest PC 0x0c073fae */
if(!s->budget--) { s->failed_pc=0x0c073faeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c073fb0;
P_0c073fb0: /* original 000b, guest PC 0x0c073fb0 */
if(!s->budget--) { s->failed_pc=0x0c073fb0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c073fb2: /* original 0009, guest PC 0x0c073fb2 */
if(!s->budget--) { s->failed_pc=0x0c073fb2u; return 0; }
return vf3_matrix_family(0x0c073fb4u,s,ram);
P_0c074702: /* original 9030, guest PC 0x0c074702 */
if(!s->budget--) { s->failed_pc=0x0c074702u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074766u,2);
goto P_0c074704;
P_0c074704: /* original 9630, guest PC 0x0c074704 */
if(!s->budget--) { s->failed_pc=0x0c074704u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074768u,2);
goto P_0c074706;
P_0c074706: /* original f446, guest PC 0x0c074706 */
if(!s->budget--) { s->failed_pc=0x0c074706u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c074708;
P_0c074708: /* original 7008, guest PC 0x0c074708 */
if(!s->budget--) { s->failed_pc=0x0c074708u; return 0; }
r[0]+=0x00000008u;
goto P_0c07470a;
P_0c07470a: /* original f546, guest PC 0x0c07470a */
if(!s->budget--) { s->failed_pc=0x0c07470au; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c07470c;
P_0c07470c: /* original 70dc, guest PC 0x0c07470c */
if(!s->budget--) { s->failed_pc=0x0c07470cu; return 0; }
r[0]+=0xffffffdcu;
goto P_0c07470e;
P_0c07470e: /* original 054e, guest PC 0x0c07470e */
if(!s->budget--) { s->failed_pc=0x0c07470eu; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c074710;
P_0c074710: /* original 902b, guest PC 0x0c074710 */
if(!s->budget--) { s->failed_pc=0x0c074710u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07476au,2);
goto P_0c074712;
P_0c074712: /* original 365c, guest PC 0x0c074712 */
if(!s->budget--) { s->failed_pc=0x0c074712u; return 0; }
r[6]+=r[5];
goto P_0c074714;
P_0c074714: /* original f346, guest PC 0x0c074714 */
if(!s->budget--) { s->failed_pc=0x0c074714u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c074716;
P_0c074716: /* original 3560, guest PC 0x0c074716 */
if(!s->budget--) { s->failed_pc=0x0c074716u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c074718;
P_0c074718: /* original f340, guest PC 0x0c074718 */
if(!s->budget--) { s->failed_pc=0x0c074718u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c07471a;
P_0c07471a: /* original f437, guest PC 0x0c07471a */
if(!s->budget--) { s->failed_pc=0x0c07471au; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07471c;
P_0c07471c: /* original 7008, guest PC 0x0c07471c */
if(!s->budget--) { s->failed_pc=0x0c07471cu; return 0; }
r[0]+=0x00000008u;
goto P_0c07471e;
P_0c07471e: /* original f246, guest PC 0x0c07471e */
if(!s->budget--) { s->failed_pc=0x0c07471eu; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c074720;
P_0c074720: /* original f250, guest PC 0x0c074720 */
if(!s->budget--) { s->failed_pc=0x0c074720u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c074722;
P_0c074722: /* original 8d0a, guest PC 0x0c074722 */
if(!s->budget--) { s->failed_pc=0x0c074722u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,2,r[4]+r[0]);
if(cond) { goto P_0c07473a; }
goto P_0c074726;
P_0c074724: /* original f427, guest PC 0x0c074724 */
if(!s->budget--) { s->failed_pc=0x0c074724u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c074726;
P_0c074726: /* original e008, guest PC 0x0c074726 */
if(!s->budget--) { s->failed_pc=0x0c074726u; return 0; }
r[0]=0x00000008u;
goto P_0c074728;
P_0c074728: /* original f358, guest PC 0x0c074728 */
if(!s->budget--) { s->failed_pc=0x0c074728u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c07472a;
P_0c07472a: /* original f340, guest PC 0x0c07472a */
if(!s->budget--) { s->failed_pc=0x0c07472au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c07472c;
P_0c07472c: /* original f53a, guest PC 0x0c07472c */
if(!s->budget--) { s->failed_pc=0x0c07472cu; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c07472e;
P_0c07472e: /* original f256, guest PC 0x0c07472e */
if(!s->budget--) { s->failed_pc=0x0c07472eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c074730;
P_0c074730: /* original f250, guest PC 0x0c074730 */
if(!s->budget--) { s->failed_pc=0x0c074730u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c074732;
P_0c074732: /* original f527, guest PC 0x0c074732 */
if(!s->budget--) { s->failed_pc=0x0c074732u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c074734;
P_0c074734: /* original 750c, guest PC 0x0c074734 */
if(!s->budget--) { s->failed_pc=0x0c074734u; return 0; }
r[5]+=0x0000000cu;
goto P_0c074736;
P_0c074736: /* original 3560, guest PC 0x0c074736 */
if(!s->budget--) { s->failed_pc=0x0c074736u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c074738;
P_0c074738: /* original 8bf5, guest PC 0x0c074738 */
if(!s->budget--) { s->failed_pc=0x0c074738u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074726; }
goto P_0c07473a;
P_0c07473a: /* original 000b, guest PC 0x0c07473a */
if(!s->budget--) { s->failed_pc=0x0c07473au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07473c: /* original 0009, guest PC 0x0c07473c */
if(!s->budget--) { s->failed_pc=0x0c07473cu; return 0; }
return vf3_matrix_family(0x0c07473eu,s,ram);
P_0c07482e: /* original 4f22, guest PC 0x0c07482e */
if(!s->budget--) { s->failed_pc=0x0c07482eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c074830;
P_0c074830: /* original 7ff8, guest PC 0x0c074830 */
if(!s->budget--) { s->failed_pc=0x0c074830u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c074832;
P_0c074832: /* original 2f42, guest PC 0x0c074832 */
if(!s->budget--) { s->failed_pc=0x0c074832u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c074834;
P_0c074834: /* original 1f51, guest PC 0x0c074834 */
if(!s->budget--) { s->failed_pc=0x0c074834u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c074836;
P_0c074836: /* original d121, guest PC 0x0c074836 */
if(!s->budget--) { s->failed_pc=0x0c074836u; return 0; }
r[1]=read(ram,0x0c0748bcu,4);
goto P_0c074838;
P_0c074838: /* original d31f, guest PC 0x0c074838 */
if(!s->budget--) { s->failed_pc=0x0c074838u; return 0; }
r[3]=read(ram,0x0c0748b8u,4);
goto P_0c07483a;
P_0c07483a: /* original 6212, guest PC 0x0c07483a */
if(!s->budget--) { s->failed_pc=0x0c07483au; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c07483c;
P_0c07483c: /* original 2238, guest PC 0x0c07483c */
if(!s->budget--) { s->failed_pc=0x0c07483cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07483e;
P_0c07483e: /* original 8b05, guest PC 0x0c07483e */
if(!s->budget--) { s->failed_pc=0x0c07483eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07484c; }
goto P_0c074840;
P_0c074840: /* original 55f1, guest PC 0x0c074840 */
if(!s->budget--) { s->failed_pc=0x0c074840u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c074842;
P_0c074842: /* original b007, guest PC 0x0c074842 */
if(!s->budget--) { s->failed_pc=0x0c074842u; return 0; }
target=0x0c074854u; r[16]=0x0c074846u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074846u) { target=s->pc; goto dispatch; }
goto P_0c074846;
P_0c074844: /* original 64f2, guest PC 0x0c074844 */
if(!s->budget--) { s->failed_pc=0x0c074844u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c074846;
P_0c074846: /* original 65f2, guest PC 0x0c074846 */
if(!s->budget--) { s->failed_pc=0x0c074846u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c074848;
P_0c074848: /* original b004, guest PC 0x0c074848 */
if(!s->budget--) { s->failed_pc=0x0c074848u; return 0; }
target=0x0c074854u; r[16]=0x0c07484cu;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07484cu) { target=s->pc; goto dispatch; }
goto P_0c07484c;
P_0c07484a: /* original 54f1, guest PC 0x0c07484a */
if(!s->budget--) { s->failed_pc=0x0c07484au; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07484c;
P_0c07484c: /* original 7f08, guest PC 0x0c07484c */
if(!s->budget--) { s->failed_pc=0x0c07484cu; return 0; }
r[15]+=0x00000008u;
goto P_0c07484e;
P_0c07484e: /* original 4f26, guest PC 0x0c07484e */
if(!s->budget--) { s->failed_pc=0x0c07484eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c074850;
P_0c074850: /* original 000b, guest PC 0x0c074850 */
if(!s->budget--) { s->failed_pc=0x0c074850u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c074852: /* original 0009, guest PC 0x0c074852 */
if(!s->budget--) { s->failed_pc=0x0c074852u; return 0; }
return vf3_matrix_family(0x0c074854u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
