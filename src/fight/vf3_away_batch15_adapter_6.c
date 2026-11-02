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
int vf3_away_batch15_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08a8c2u: goto P_0c08a8c2;
case 0x0c08a8c4u: goto P_0c08a8c4;
case 0x0c08a8c6u: goto P_0c08a8c6;
case 0x0c08a8c8u: goto P_0c08a8c8;
case 0x0c08a8cau: goto P_0c08a8ca;
case 0x0c08a8ccu: goto P_0c08a8cc;
case 0x0c08a8ceu: goto P_0c08a8ce;
case 0x0c08a8d0u: goto P_0c08a8d0;
case 0x0c08a934u: goto P_0c08a934;
case 0x0c08a936u: goto P_0c08a936;
case 0x0c08a938u: goto P_0c08a938;
case 0x0c08a93au: goto P_0c08a93a;
case 0x0c08a93cu: goto P_0c08a93c;
case 0x0c08a93eu: goto P_0c08a93e;
case 0x0c08a940u: goto P_0c08a940;
case 0x0c08a942u: goto P_0c08a942;
case 0x0c08a944u: goto P_0c08a944;
case 0x0c08a946u: goto P_0c08a946;
case 0x0c08a948u: goto P_0c08a948;
case 0x0c08a94au: goto P_0c08a94a;
case 0x0c08a94cu: goto P_0c08a94c;
case 0x0c08a94eu: goto P_0c08a94e;
case 0x0c08a950u: goto P_0c08a950;
case 0x0c08a952u: goto P_0c08a952;
case 0x0c08a954u: goto P_0c08a954;
case 0x0c08a956u: goto P_0c08a956;
case 0x0c08a958u: goto P_0c08a958;
case 0x0c08a95au: goto P_0c08a95a;
case 0x0c08a95cu: goto P_0c08a95c;
case 0x0c08a95eu: goto P_0c08a95e;
case 0x0c08a960u: goto P_0c08a960;
case 0x0c08a962u: goto P_0c08a962;
case 0x0c08a964u: goto P_0c08a964;
case 0x0c08a966u: goto P_0c08a966;
case 0x0c08a968u: goto P_0c08a968;
case 0x0c08a96au: goto P_0c08a96a;
case 0x0c08a96cu: goto P_0c08a96c;
case 0x0c08a96eu: goto P_0c08a96e;
case 0x0c08a970u: goto P_0c08a970;
case 0x0c08a972u: goto P_0c08a972;
case 0x0c08a974u: goto P_0c08a974;
case 0x0c08a976u: goto P_0c08a976;
case 0x0c08a978u: goto P_0c08a978;
case 0x0c08a97au: goto P_0c08a97a;
case 0x0c08a97cu: goto P_0c08a97c;
case 0x0c08a97eu: goto P_0c08a97e;
case 0x0c08a980u: goto P_0c08a980;
case 0x0c08a982u: goto P_0c08a982;
case 0x0c08a984u: goto P_0c08a984;
case 0x0c08a986u: goto P_0c08a986;
case 0x0c08a988u: goto P_0c08a988;
case 0x0c08a98au: goto P_0c08a98a;
case 0x0c08a98cu: goto P_0c08a98c;
case 0x0c08a98eu: goto P_0c08a98e;
case 0x0c08a990u: goto P_0c08a990;
case 0x0c08a992u: goto P_0c08a992;
case 0x0c08a994u: goto P_0c08a994;
case 0x0c08a996u: goto P_0c08a996;
case 0x0c08a998u: goto P_0c08a998;
case 0x0c08a99au: goto P_0c08a99a;
case 0x0c08a99cu: goto P_0c08a99c;
case 0x0c08a99eu: goto P_0c08a99e;
case 0x0c08a9a0u: goto P_0c08a9a0;
case 0x0c08a9a2u: goto P_0c08a9a2;
case 0x0c08a9a4u: goto P_0c08a9a4;
case 0x0c08a9a6u: goto P_0c08a9a6;
case 0x0c08a9a8u: goto P_0c08a9a8;
case 0x0c08a9aau: goto P_0c08a9aa;
case 0x0c08a9acu: goto P_0c08a9ac;
case 0x0c08a9aeu: goto P_0c08a9ae;
case 0x0c08a9b0u: goto P_0c08a9b0;
case 0x0c08a9b2u: goto P_0c08a9b2;
case 0x0c08a9b4u: goto P_0c08a9b4;
case 0x0c08a9b6u: goto P_0c08a9b6;
case 0x0c08a9b8u: goto P_0c08a9b8;
case 0x0c08a9bau: goto P_0c08a9ba;
case 0x0c08a9bcu: goto P_0c08a9bc;
case 0x0c08a9beu: goto P_0c08a9be;
case 0x0c08a9c0u: goto P_0c08a9c0;
case 0x0c08a9c2u: goto P_0c08a9c2;
case 0x0c08a9c4u: goto P_0c08a9c4;
case 0x0c08a9c6u: goto P_0c08a9c6;
case 0x0c08a9c8u: goto P_0c08a9c8;
case 0x0c08a9cau: goto P_0c08a9ca;
case 0x0c08a9ccu: goto P_0c08a9cc;
case 0x0c08a9ceu: goto P_0c08a9ce;
case 0x0c08a9d0u: goto P_0c08a9d0;
case 0x0c08a9d2u: goto P_0c08a9d2;
case 0x0c08a9d4u: goto P_0c08a9d4;
case 0x0c08a9d6u: goto P_0c08a9d6;
case 0x0c08a9d8u: goto P_0c08a9d8;
case 0x0c08a9dau: goto P_0c08a9da;
case 0x0c08a9dcu: goto P_0c08a9dc;
case 0x0c08a9deu: goto P_0c08a9de;
case 0x0c08a9e0u: goto P_0c08a9e0;
case 0x0c08a9e2u: goto P_0c08a9e2;
case 0x0c08a9e4u: goto P_0c08a9e4;
case 0x0c08a9e6u: goto P_0c08a9e6;
case 0x0c08a9e8u: goto P_0c08a9e8;
case 0x0c08a9eau: goto P_0c08a9ea;
case 0x0c08a9ecu: goto P_0c08a9ec;
case 0x0c08a9eeu: goto P_0c08a9ee;
case 0x0c08a9f0u: goto P_0c08a9f0;
case 0x0c08a9f2u: goto P_0c08a9f2;
case 0x0c08a9f4u: goto P_0c08a9f4;
case 0x0c08aa58u: goto P_0c08aa58;
case 0x0c08aa5au: goto P_0c08aa5a;
case 0x0c08aa5cu: goto P_0c08aa5c;
case 0x0c08aa5eu: goto P_0c08aa5e;
case 0x0c08aa60u: goto P_0c08aa60;
case 0x0c08aa62u: goto P_0c08aa62;
case 0x0c08aa64u: goto P_0c08aa64;
case 0x0c08aa66u: goto P_0c08aa66;
case 0x0c08aa68u: goto P_0c08aa68;
case 0x0c08aa6au: goto P_0c08aa6a;
case 0x0c08aa6cu: goto P_0c08aa6c;
case 0x0c08aa6eu: goto P_0c08aa6e;
case 0x0c08aa70u: goto P_0c08aa70;
case 0x0c08aa72u: goto P_0c08aa72;
case 0x0c08aa74u: goto P_0c08aa74;
case 0x0c08aa76u: goto P_0c08aa76;
case 0x0c08aa78u: goto P_0c08aa78;
case 0x0c08aa7au: goto P_0c08aa7a;
case 0x0c08aa7cu: goto P_0c08aa7c;
case 0x0c08aa7eu: goto P_0c08aa7e;
case 0x0c08aa80u: goto P_0c08aa80;
case 0x0c08aa82u: goto P_0c08aa82;
case 0x0c08aa84u: goto P_0c08aa84;
case 0x0c08aa86u: goto P_0c08aa86;
case 0x0c08aa88u: goto P_0c08aa88;
case 0x0c08aa8au: goto P_0c08aa8a;
case 0x0c08aa8cu: goto P_0c08aa8c;
case 0x0c08aa8eu: goto P_0c08aa8e;
case 0x0c08aa90u: goto P_0c08aa90;
case 0x0c08aa92u: goto P_0c08aa92;
case 0x0c08aa94u: goto P_0c08aa94;
case 0x0c08aa96u: goto P_0c08aa96;
case 0x0c08aa98u: goto P_0c08aa98;
case 0x0c08aa9au: goto P_0c08aa9a;
case 0x0c08aa9cu: goto P_0c08aa9c;
case 0x0c08aa9eu: goto P_0c08aa9e;
case 0x0c08aaa0u: goto P_0c08aaa0;
case 0x0c08aaa2u: goto P_0c08aaa2;
case 0x0c08aaa4u: goto P_0c08aaa4;
case 0x0c08aaa6u: goto P_0c08aaa6;
case 0x0c08aaa8u: goto P_0c08aaa8;
case 0x0c08aaaau: goto P_0c08aaaa;
case 0x0c08aaacu: goto P_0c08aaac;
case 0x0c08aaaeu: goto P_0c08aaae;
case 0x0c08aab0u: goto P_0c08aab0;
case 0x0c08aab2u: goto P_0c08aab2;
case 0x0c08aab4u: goto P_0c08aab4;
case 0x0c08aab6u: goto P_0c08aab6;
case 0x0c08aab8u: goto P_0c08aab8;
case 0x0c08aabau: goto P_0c08aaba;
case 0x0c08aabcu: goto P_0c08aabc;
case 0x0c08aabeu: goto P_0c08aabe;
case 0x0c08aac0u: goto P_0c08aac0;
case 0x0c08aac2u: goto P_0c08aac2;
case 0x0c08aac4u: goto P_0c08aac4;
case 0x0c08aac6u: goto P_0c08aac6;
case 0x0c08aac8u: goto P_0c08aac8;
case 0x0c08aacau: goto P_0c08aaca;
case 0x0c08aaccu: goto P_0c08aacc;
case 0x0c08aaceu: goto P_0c08aace;
case 0x0c08aad0u: goto P_0c08aad0;
case 0x0c08acc0u: goto P_0c08acc0;
case 0x0c08acc2u: goto P_0c08acc2;
case 0x0c08acc4u: goto P_0c08acc4;
case 0x0c08acc6u: goto P_0c08acc6;
case 0x0c08acc8u: goto P_0c08acc8;
case 0x0c08accau: goto P_0c08acca;
case 0x0c08acccu: goto P_0c08accc;
case 0x0c08acceu: goto P_0c08acce;
case 0x0c08acd0u: goto P_0c08acd0;
case 0x0c08acd2u: goto P_0c08acd2;
case 0x0c08acd4u: goto P_0c08acd4;
case 0x0c08acd6u: goto P_0c08acd6;
case 0x0c08acd8u: goto P_0c08acd8;
case 0x0c08acdau: goto P_0c08acda;
case 0x0c08acdcu: goto P_0c08acdc;
case 0x0c08acdeu: goto P_0c08acde;
case 0x0c08ace0u: goto P_0c08ace0;
case 0x0c08ace2u: goto P_0c08ace2;
case 0x0c08ace4u: goto P_0c08ace4;
case 0x0c08ace6u: goto P_0c08ace6;
case 0x0c08ace8u: goto P_0c08ace8;
case 0x0c08aceau: goto P_0c08acea;
case 0x0c08acecu: goto P_0c08acec;
case 0x0c08aceeu: goto P_0c08acee;
case 0x0c08acf0u: goto P_0c08acf0;
case 0x0c08acf2u: goto P_0c08acf2;
case 0x0c08acf4u: goto P_0c08acf4;
case 0x0c08acf6u: goto P_0c08acf6;
case 0x0c08acf8u: goto P_0c08acf8;
case 0x0c08acfau: goto P_0c08acfa;
case 0x0c08acfcu: goto P_0c08acfc;
case 0x0c08acfeu: goto P_0c08acfe;
case 0x0c08ad00u: goto P_0c08ad00;
case 0x0c08ad02u: goto P_0c08ad02;
case 0x0c08ad04u: goto P_0c08ad04;
case 0x0c08ad06u: goto P_0c08ad06;
case 0x0c08ad08u: goto P_0c08ad08;
case 0x0c08ad0au: goto P_0c08ad0a;
case 0x0c08ad0cu: goto P_0c08ad0c;
case 0x0c08ad0eu: goto P_0c08ad0e;
case 0x0c08ad10u: goto P_0c08ad10;
case 0x0c08ad12u: goto P_0c08ad12;
case 0x0c08ad14u: goto P_0c08ad14;
case 0x0c08ad16u: goto P_0c08ad16;
case 0x0c08ad18u: goto P_0c08ad18;
case 0x0c08ad1au: goto P_0c08ad1a;
case 0x0c08ad1cu: goto P_0c08ad1c;
case 0x0c08ad1eu: goto P_0c08ad1e;
case 0x0c08ad20u: goto P_0c08ad20;
case 0x0c08ad22u: goto P_0c08ad22;
case 0x0c08ad24u: goto P_0c08ad24;
case 0x0c08ad26u: goto P_0c08ad26;
case 0x0c08ad28u: goto P_0c08ad28;
case 0x0c08ad2au: goto P_0c08ad2a;
case 0x0c08ad2cu: goto P_0c08ad2c;
case 0x0c08ad2eu: goto P_0c08ad2e;
case 0x0c08ad30u: goto P_0c08ad30;
case 0x0c08ad32u: goto P_0c08ad32;
case 0x0c08ad34u: goto P_0c08ad34;
case 0x0c08ad36u: goto P_0c08ad36;
case 0x0c08ad38u: goto P_0c08ad38;
case 0x0c08ad3au: goto P_0c08ad3a;
case 0x0c08ad3cu: goto P_0c08ad3c;
case 0x0c08ad3eu: goto P_0c08ad3e;
case 0x0c08ad40u: goto P_0c08ad40;
case 0x0c08ad42u: goto P_0c08ad42;
case 0x0c08ad44u: goto P_0c08ad44;
case 0x0c08ad46u: goto P_0c08ad46;
case 0x0c08ad48u: goto P_0c08ad48;
case 0x0c08ad4au: goto P_0c08ad4a;
case 0x0c08ad4cu: goto P_0c08ad4c;
case 0x0c08ad4eu: goto P_0c08ad4e;
case 0x0c08ad50u: goto P_0c08ad50;
case 0x0c08ad52u: goto P_0c08ad52;
case 0x0c08ad54u: goto P_0c08ad54;
case 0x0c08ad56u: goto P_0c08ad56;
case 0x0c08ad58u: goto P_0c08ad58;
case 0x0c08ad5au: goto P_0c08ad5a;
case 0x0c08ad5cu: goto P_0c08ad5c;
case 0x0c08ad5eu: goto P_0c08ad5e;
case 0x0c08ad60u: goto P_0c08ad60;
case 0x0c08ad62u: goto P_0c08ad62;
case 0x0c08ad64u: goto P_0c08ad64;
case 0x0c08ad66u: goto P_0c08ad66;
case 0x0c08ad68u: goto P_0c08ad68;
case 0x0c08ad6au: goto P_0c08ad6a;
case 0x0c08ad6cu: goto P_0c08ad6c;
case 0x0c08ad6eu: goto P_0c08ad6e;
case 0x0c08ad70u: goto P_0c08ad70;
case 0x0c08ad72u: goto P_0c08ad72;
case 0x0c08ad74u: goto P_0c08ad74;
case 0x0c08ad76u: goto P_0c08ad76;
case 0x0c08ad78u: goto P_0c08ad78;
case 0x0c08ad7au: goto P_0c08ad7a;
case 0x0c08ad7cu: goto P_0c08ad7c;
case 0x0c08ad7eu: goto P_0c08ad7e;
case 0x0c08add0u: goto P_0c08add0;
case 0x0c08add2u: goto P_0c08add2;
case 0x0c08add4u: goto P_0c08add4;
case 0x0c08add6u: goto P_0c08add6;
case 0x0c08add8u: goto P_0c08add8;
case 0x0c08addau: goto P_0c08adda;
case 0x0c08addcu: goto P_0c08addc;
case 0x0c08addeu: goto P_0c08adde;
case 0x0c08ade0u: goto P_0c08ade0;
case 0x0c08ade2u: goto P_0c08ade2;
case 0x0c08ade4u: goto P_0c08ade4;
case 0x0c08ade6u: goto P_0c08ade6;
case 0x0c08ade8u: goto P_0c08ade8;
case 0x0c08adeau: goto P_0c08adea;
case 0x0c08adecu: goto P_0c08adec;
case 0x0c08adeeu: goto P_0c08adee;
case 0x0c08adf0u: goto P_0c08adf0;
case 0x0c08adf2u: goto P_0c08adf2;
case 0x0c08adf4u: goto P_0c08adf4;
case 0x0c08adf6u: goto P_0c08adf6;
case 0x0c08adf8u: goto P_0c08adf8;
case 0x0c08adfau: goto P_0c08adfa;
case 0x0c08adfcu: goto P_0c08adfc;
case 0x0c08adfeu: goto P_0c08adfe;
case 0x0c08ae00u: goto P_0c08ae00;
case 0x0c08ae02u: goto P_0c08ae02;
case 0x0c08ae04u: goto P_0c08ae04;
case 0x0c08ae06u: goto P_0c08ae06;
case 0x0c08ae08u: goto P_0c08ae08;
case 0x0c08ae0au: goto P_0c08ae0a;
case 0x0c08ae0cu: goto P_0c08ae0c;
case 0x0c08ae0eu: goto P_0c08ae0e;
case 0x0c08ae10u: goto P_0c08ae10;
case 0x0c08ae12u: goto P_0c08ae12;
case 0x0c08ae14u: goto P_0c08ae14;
case 0x0c08ae16u: goto P_0c08ae16;
case 0x0c08ae18u: goto P_0c08ae18;
case 0x0c08ae1au: goto P_0c08ae1a;
case 0x0c08ae1cu: goto P_0c08ae1c;
case 0x0c08ae1eu: goto P_0c08ae1e;
case 0x0c08ae20u: goto P_0c08ae20;
case 0x0c08ae22u: goto P_0c08ae22;
case 0x0c08ae24u: goto P_0c08ae24;
case 0x0c08ae26u: goto P_0c08ae26;
case 0x0c08ae28u: goto P_0c08ae28;
case 0x0c08ae2au: goto P_0c08ae2a;
case 0x0c08ae2cu: goto P_0c08ae2c;
case 0x0c08ae2eu: goto P_0c08ae2e;
case 0x0c08ae30u: goto P_0c08ae30;
case 0x0c08ae32u: goto P_0c08ae32;
case 0x0c08ae34u: goto P_0c08ae34;
case 0x0c08ae36u: goto P_0c08ae36;
case 0x0c08ae38u: goto P_0c08ae38;
case 0x0c08ae3au: goto P_0c08ae3a;
case 0x0c08ae3cu: goto P_0c08ae3c;
case 0x0c08ae3eu: goto P_0c08ae3e;
case 0x0c08ae40u: goto P_0c08ae40;
case 0x0c08ae42u: goto P_0c08ae42;
case 0x0c08ae44u: goto P_0c08ae44;
case 0x0c08ae46u: goto P_0c08ae46;
case 0x0c08ae48u: goto P_0c08ae48;
case 0x0c08ae4au: goto P_0c08ae4a;
case 0x0c08ae4cu: goto P_0c08ae4c;
case 0x0c08ae4eu: goto P_0c08ae4e;
case 0x0c08ae50u: goto P_0c08ae50;
case 0x0c08ae52u: goto P_0c08ae52;
case 0x0c08ae54u: goto P_0c08ae54;
case 0x0c08ae56u: goto P_0c08ae56;
case 0x0c08ae58u: goto P_0c08ae58;
case 0x0c08ae5au: goto P_0c08ae5a;
case 0x0c08ae5cu: goto P_0c08ae5c;
case 0x0c08ae5eu: goto P_0c08ae5e;
case 0x0c08ae60u: goto P_0c08ae60;
case 0x0c08ae62u: goto P_0c08ae62;
case 0x0c08ae64u: goto P_0c08ae64;
case 0x0c08ae66u: goto P_0c08ae66;
case 0x0c08ae68u: goto P_0c08ae68;
case 0x0c08ae6au: goto P_0c08ae6a;
case 0x0c08ae6cu: goto P_0c08ae6c;
case 0x0c08ae6eu: goto P_0c08ae6e;
case 0x0c08ae70u: goto P_0c08ae70;
case 0x0c08ae72u: goto P_0c08ae72;
case 0x0c08ae9cu: goto P_0c08ae9c;
case 0x0c08ae9eu: goto P_0c08ae9e;
case 0x0c08aea0u: goto P_0c08aea0;
case 0x0c08aea2u: goto P_0c08aea2;
case 0x0c08aea4u: goto P_0c08aea4;
case 0x0c08aea6u: goto P_0c08aea6;
case 0x0c08aea8u: goto P_0c08aea8;
case 0x0c08aeaau: goto P_0c08aeaa;
case 0x0c08aeacu: goto P_0c08aeac;
case 0x0c08aeaeu: goto P_0c08aeae;
case 0x0c08aeb0u: goto P_0c08aeb0;
case 0x0c08aeb2u: goto P_0c08aeb2;
case 0x0c08aeb4u: goto P_0c08aeb4;
case 0x0c08aeb6u: goto P_0c08aeb6;
case 0x0c08aeb8u: goto P_0c08aeb8;
case 0x0c08aebau: goto P_0c08aeba;
case 0x0c08aebcu: goto P_0c08aebc;
case 0x0c08aebeu: goto P_0c08aebe;
case 0x0c08aec0u: goto P_0c08aec0;
case 0x0c08aec2u: goto P_0c08aec2;
case 0x0c08aec4u: goto P_0c08aec4;
case 0x0c08aec6u: goto P_0c08aec6;
case 0x0c08aec8u: goto P_0c08aec8;
case 0x0c08aecau: goto P_0c08aeca;
case 0x0c08aeccu: goto P_0c08aecc;
case 0x0c08aeceu: goto P_0c08aece;
case 0x0c08aed0u: goto P_0c08aed0;
case 0x0c08aed2u: goto P_0c08aed2;
case 0x0c08aed4u: goto P_0c08aed4;
case 0x0c08aed6u: goto P_0c08aed6;
case 0x0c08aed8u: goto P_0c08aed8;
case 0x0c08aedau: goto P_0c08aeda;
case 0x0c08aedcu: goto P_0c08aedc;
case 0x0c08aedeu: goto P_0c08aede;
case 0x0c08aee0u: goto P_0c08aee0;
case 0x0c08aee2u: goto P_0c08aee2;
case 0x0c08aee4u: goto P_0c08aee4;
case 0x0c08aee6u: goto P_0c08aee6;
case 0x0c08aee8u: goto P_0c08aee8;
case 0x0c08aeeau: goto P_0c08aeea;
case 0x0c08aeecu: goto P_0c08aeec;
case 0x0c08aeeeu: goto P_0c08aeee;
case 0x0c08aef0u: goto P_0c08aef0;
case 0x0c08aef2u: goto P_0c08aef2;
case 0x0c08aef4u: goto P_0c08aef4;
case 0x0c08aef6u: goto P_0c08aef6;
case 0x0c08aef8u: goto P_0c08aef8;
case 0x0c08aefau: goto P_0c08aefa;
case 0x0c08aefcu: goto P_0c08aefc;
case 0x0c08aefeu: goto P_0c08aefe;
case 0x0c08af00u: goto P_0c08af00;
case 0x0c08af02u: goto P_0c08af02;
case 0x0c08af04u: goto P_0c08af04;
case 0x0c08af06u: goto P_0c08af06;
case 0x0c08af08u: goto P_0c08af08;
case 0x0c08af0au: goto P_0c08af0a;
case 0x0c08af0cu: goto P_0c08af0c;
case 0x0c08af0eu: goto P_0c08af0e;
case 0x0c08af10u: goto P_0c08af10;
case 0x0c08af12u: goto P_0c08af12;
case 0x0c08af14u: goto P_0c08af14;
case 0x0c08af16u: goto P_0c08af16;
case 0x0c08af18u: goto P_0c08af18;
case 0x0c08af1au: goto P_0c08af1a;
case 0x0c08af1cu: goto P_0c08af1c;
case 0x0c08af1eu: goto P_0c08af1e;
case 0x0c08af20u: goto P_0c08af20;
case 0x0c08af22u: goto P_0c08af22;
case 0x0c08af24u: goto P_0c08af24;
case 0x0c08af26u: goto P_0c08af26;
case 0x0c08af28u: goto P_0c08af28;
case 0x0c08af2au: goto P_0c08af2a;
case 0x0c08af2cu: goto P_0c08af2c;
case 0x0c08af2eu: goto P_0c08af2e;
case 0x0c08af30u: goto P_0c08af30;
case 0x0c08af32u: goto P_0c08af32;
case 0x0c08af34u: goto P_0c08af34;
case 0x0c08af36u: goto P_0c08af36;
case 0x0c08af38u: goto P_0c08af38;
case 0x0c08af3au: goto P_0c08af3a;
case 0x0c08af3cu: goto P_0c08af3c;
case 0x0c08af3eu: goto P_0c08af3e;
case 0x0c08af40u: goto P_0c08af40;
case 0x0c08af42u: goto P_0c08af42;
case 0x0c08af44u: goto P_0c08af44;
case 0x0c08af46u: goto P_0c08af46;
case 0x0c08af48u: goto P_0c08af48;
case 0x0c08af4au: goto P_0c08af4a;
case 0x0c08af4cu: goto P_0c08af4c;
case 0x0c08af4eu: goto P_0c08af4e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08a8c2: /* original 9532, guest PC 0x0c08a8c2 */
if(!s->budget--) { s->failed_pc=0x0c08a8c2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a92au,2);
goto P_0c08a8c4;
P_0c08a8c4: /* original e600, guest PC 0x0c08a8c4 */
if(!s->budget--) { s->failed_pc=0x0c08a8c4u; return 0; }
r[6]=0x00000000u;
goto P_0c08a8c6;
P_0c08a8c6: /* original 4510, guest PC 0x0c08a8c6 */
if(!s->budget--) { s->failed_pc=0x0c08a8c6u; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c08a8c8;
P_0c08a8c8: /* original 2462, guest PC 0x0c08a8c8 */
if(!s->budget--) { s->failed_pc=0x0c08a8c8u; return 0; }
write(ram,r[4],r[6],4);
goto P_0c08a8ca;
P_0c08a8ca: /* original 8ffc, guest PC 0x0c08a8ca */
if(!s->budget--) { s->failed_pc=0x0c08a8cau; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c08a8c6; }
goto P_0c08a8ce;
P_0c08a8cc: /* original 7404, guest PC 0x0c08a8cc */
if(!s->budget--) { s->failed_pc=0x0c08a8ccu; return 0; }
r[4]+=0x00000004u;
goto P_0c08a8ce;
P_0c08a8ce: /* original 000b, guest PC 0x0c08a8ce */
if(!s->budget--) { s->failed_pc=0x0c08a8ceu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c08a8d0: /* original 0009, guest PC 0x0c08a8d0 */
if(!s->budget--) { s->failed_pc=0x0c08a8d0u; return 0; }
if(!vf3_matrix_family(0x0c08a8d2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08a8d2u; return 0; } return 1;
P_0c08a934: /* original 2fe6, guest PC 0x0c08a934 */
if(!s->budget--) { s->failed_pc=0x0c08a934u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a936;
P_0c08a936: /* original 6e43, guest PC 0x0c08a936 */
if(!s->budget--) { s->failed_pc=0x0c08a936u; return 0; }
r[14]=r[4];
goto P_0c08a938;
P_0c08a938: /* original 2fd6, guest PC 0x0c08a938 */
if(!s->budget--) { s->failed_pc=0x0c08a938u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a93a;
P_0c08a93a: /* original 7e40, guest PC 0x0c08a93a */
if(!s->budget--) { s->failed_pc=0x0c08a93au; return 0; }
r[14]+=0x00000040u;
goto P_0c08a93c;
P_0c08a93c: /* original 2fc6, guest PC 0x0c08a93c */
if(!s->budget--) { s->failed_pc=0x0c08a93cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a93e;
P_0c08a93e: /* original 6d43, guest PC 0x0c08a93e */
if(!s->budget--) { s->failed_pc=0x0c08a93eu; return 0; }
r[13]=r[4];
goto P_0c08a940;
P_0c08a940: /* original 2fb6, guest PC 0x0c08a940 */
if(!s->budget--) { s->failed_pc=0x0c08a940u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a942;
P_0c08a942: /* original 4f22, guest PC 0x0c08a942 */
if(!s->budget--) { s->failed_pc=0x0c08a942u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08a944;
P_0c08a944: /* original 9c71, guest PC 0x0c08a944 */
if(!s->budget--) { s->failed_pc=0x0c08a944u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08aa2au,2);
goto P_0c08a946;
P_0c08a946: /* original 7fec, guest PC 0x0c08a946 */
if(!s->budget--) { s->failed_pc=0x0c08a946u; return 0; }
r[15]+=0xffffffecu;
goto P_0c08a948;
P_0c08a948: /* original bfbb, guest PC 0x0c08a948 */
if(!s->budget--) { s->failed_pc=0x0c08a948u; return 0; }
target=code_base|0x0c08a8c2u; r[16]=code_base|0x0c08a94cu;
r[12]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a94cu) { target=s->pc; goto dispatch; }
goto P_0c08a94c;
P_0c08a94a: /* original 3cdc, guest PC 0x0c08a94a */
if(!s->budget--) { s->failed_pc=0x0c08a94au; return 0; }
r[12]+=r[13];
goto P_0c08a94c;
P_0c08a94c: /* original d538, guest PC 0x0c08a94c */
if(!s->budget--) { s->failed_pc=0x0c08a94cu; return 0; }
r[5]=read(ram,0x0c08aa30u,4);
goto P_0c08a94e;
P_0c08a94e: /* original e060, guest PC 0x0c08a94e */
if(!s->budget--) { s->failed_pc=0x0c08a94eu; return 0; }
r[0]=0x00000060u;
goto P_0c08a950;
P_0c08a950: /* original 976c, guest PC 0x0c08a950 */
if(!s->budget--) { s->failed_pc=0x0c08a950u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08aa2cu,2);
goto P_0c08a952;
P_0c08a952: /* original 5454, guest PC 0x0c08a952 */
if(!s->budget--) { s->failed_pc=0x0c08a952u; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c08a954;
P_0c08a954: /* original 5655, guest PC 0x0c08a954 */
if(!s->budget--) { s->failed_pc=0x0c08a954u; return 0; }
r[6]=read(ram,r[5]+20,4);
goto P_0c08a956;
P_0c08a956: /* original 044c, guest PC 0x0c08a956 */
if(!s->budget--) { s->failed_pc=0x0c08a956u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c08a958;
P_0c08a958: /* original 066c, guest PC 0x0c08a958 */
if(!s->budget--) { s->failed_pc=0x0c08a958u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c08a95a;
P_0c08a95a: /* original d036, guest PC 0x0c08a95a */
if(!s->budget--) { s->failed_pc=0x0c08a95au; return 0; }
r[0]=read(ram,0x0c08aa34u,4);
goto P_0c08a95c;
P_0c08a95c: /* original 644c, guest PC 0x0c08a95c */
if(!s->budget--) { s->failed_pc=0x0c08a95cu; return 0; }
r[4]=r[4]&255u;
goto P_0c08a95e;
P_0c08a95e: /* original 4400, guest PC 0x0c08a95e */
if(!s->budget--) { s->failed_pc=0x0c08a95eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08a960;
P_0c08a960: /* original 034d, guest PC 0x0c08a960 */
if(!s->budget--) { s->failed_pc=0x0c08a960u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08a962;
P_0c08a962: /* original 666c, guest PC 0x0c08a962 */
if(!s->budget--) { s->failed_pc=0x0c08a962u; return 0; }
r[6]=r[6]&255u;
goto P_0c08a964;
P_0c08a964: /* original 4600, guest PC 0x0c08a964 */
if(!s->budget--) { s->failed_pc=0x0c08a964u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c08a966;
P_0c08a966: /* original 3738, guest PC 0x0c08a966 */
if(!s->budget--) { s->failed_pc=0x0c08a966u; return 0; }
r[7]-=r[3];
goto P_0c08a968;
P_0c08a968: /* original 026d, guest PC 0x0c08a968 */
if(!s->budget--) { s->failed_pc=0x0c08a968u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c08a96a;
P_0c08a96a: /* original 6473, guest PC 0x0c08a96a */
if(!s->budget--) { s->failed_pc=0x0c08a96au; return 0; }
r[4]=r[7];
goto P_0c08a96c;
P_0c08a96c: /* original 3428, guest PC 0x0c08a96c */
if(!s->budget--) { s->failed_pc=0x0c08a96cu; return 0; }
r[4]-=r[2];
goto P_0c08a96e;
P_0c08a96e: /* original 4411, guest PC 0x0c08a96e */
if(!s->budget--) { s->failed_pc=0x0c08a96eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c08a970;
P_0c08a970: /* original 8d01, guest PC 0x0c08a970 */
if(!s->budget--) { s->failed_pc=0x0c08a970u; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(cond) { goto P_0c08a976; }
goto P_0c08a974;
P_0c08a972: /* original e600, guest PC 0x0c08a972 */
if(!s->budget--) { s->failed_pc=0x0c08a972u; return 0; }
r[6]=0x00000000u;
goto P_0c08a974;
P_0c08a974: /* original 6463, guest PC 0x0c08a974 */
if(!s->budget--) { s->failed_pc=0x0c08a974u; return 0; }
r[4]=r[6];
goto P_0c08a976;
P_0c08a976: /* original 2d41, guest PC 0x0c08a976 */
if(!s->budget--) { s->failed_pc=0x0c08a976u; return 0; }
write(ram,r[13],r[4],2);
goto P_0c08a978;
P_0c08a978: /* original 6063, guest PC 0x0c08a978 */
if(!s->budget--) { s->failed_pc=0x0c08a978u; return 0; }
r[0]=r[6];
goto P_0c08a97a;
P_0c08a97a: /* original e60a, guest PC 0x0c08a97a */
if(!s->budget--) { s->failed_pc=0x0c08a97au; return 0; }
r[6]=0x0000000au;
goto P_0c08a97c;
P_0c08a97c: /* original 81d1, guest PC 0x0c08a97c */
if(!s->budget--) { s->failed_pc=0x0c08a97cu; return 0; }
write(ram,r[13]+2,r[0],2);
goto P_0c08a97e;
P_0c08a97e: /* original d42e, guest PC 0x0c08a97e */
if(!s->budget--) { s->failed_pc=0x0c08a97eu; return 0; }
r[4]=read(ram,0x0c08aa38u,4);
goto P_0c08a980;
P_0c08a980: /* original 6341, guest PC 0x0c08a980 */
if(!s->budget--) { s->failed_pc=0x0c08a980u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[3]=tmp;
goto P_0c08a982;
P_0c08a982: /* original 4610, guest PC 0x0c08a982 */
if(!s->budget--) { s->failed_pc=0x0c08a982u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c08a984;
P_0c08a984: /* original 2e31, guest PC 0x0c08a984 */
if(!s->budget--) { s->failed_pc=0x0c08a984u; return 0; }
write(ram,r[14],r[3],2);
goto P_0c08a986;
P_0c08a986: /* original 8541, guest PC 0x0c08a986 */
if(!s->budget--) { s->failed_pc=0x0c08a986u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c08a988;
P_0c08a988: /* original 81e1, guest PC 0x0c08a988 */
if(!s->budget--) { s->failed_pc=0x0c08a988u; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c08a98a;
P_0c08a98a: /* original e004, guest PC 0x0c08a98a */
if(!s->budget--) { s->failed_pc=0x0c08a98au; return 0; }
r[0]=0x00000004u;
goto P_0c08a98c;
P_0c08a98c: /* original f346, guest PC 0x0c08a98c */
if(!s->budget--) { s->failed_pc=0x0c08a98cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c08a98e;
P_0c08a98e: /* original 7408, guest PC 0x0c08a98e */
if(!s->budget--) { s->failed_pc=0x0c08a98eu; return 0; }
r[4]+=0x00000008u;
goto P_0c08a990;
P_0c08a990: /* original fe37, guest PC 0x0c08a990 */
if(!s->budget--) { s->failed_pc=0x0c08a990u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08a992;
P_0c08a992: /* original 8ff5, guest PC 0x0c08a992 */
if(!s->budget--) { s->failed_pc=0x0c08a992u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000010u;
if(!cond) { goto P_0c08a980; }
goto P_0c08a996;
P_0c08a994: /* original 7e10, guest PC 0x0c08a994 */
if(!s->budget--) { s->failed_pc=0x0c08a994u; return 0; }
r[14]+=0x00000010u;
goto P_0c08a996;
P_0c08a996: /* original 5b58, guest PC 0x0c08a996 */
if(!s->budget--) { s->failed_pc=0x0c08a996u; return 0; }
r[11]=read(ram,r[5]+32,4);
goto P_0c08a998;
P_0c08a998: /* original 65f3, guest PC 0x0c08a998 */
if(!s->budget--) { s->failed_pc=0x0c08a998u; return 0; }
r[5]=r[15];
goto P_0c08a99a;
P_0c08a99a: /* original d328, guest PC 0x0c08a99a */
if(!s->budget--) { s->failed_pc=0x0c08a99au; return 0; }
r[3]=read(ram,0x0c08aa3cu,4);
goto P_0c08a99c;
P_0c08a99c: /* original 7504, guest PC 0x0c08a99c */
if(!s->budget--) { s->failed_pc=0x0c08a99cu; return 0; }
r[5]+=0x00000004u;
goto P_0c08a99e;
P_0c08a99e: /* original 85bf, guest PC 0x0c08a99e */
if(!s->budget--) { s->failed_pc=0x0c08a99eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+30,2);
goto P_0c08a9a0;
P_0c08a9a0: /* original 66f3, guest PC 0x0c08a9a0 */
if(!s->budget--) { s->failed_pc=0x0c08a9a0u; return 0; }
r[6]=r[15];
goto P_0c08a9a2;
P_0c08a9a2: /* original 6b03, guest PC 0x0c08a9a2 */
if(!s->budget--) { s->failed_pc=0x0c08a9a2u; return 0; }
r[11]=r[0];
goto P_0c08a9a4;
P_0c08a9a4: /* original c726, guest PC 0x0c08a9a4 */
if(!s->budget--) { s->failed_pc=0x0c08a9a4u; return 0; }
r[0]=code_base|0x0008aa40u;
goto P_0c08a9a6;
P_0c08a9a6: /* original f308, guest PC 0x0c08a9a6 */
if(!s->budget--) { s->failed_pc=0x0c08a9a6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08a9a8;
P_0c08a9a8: /* original e004, guest PC 0x0c08a9a8 */
if(!s->budget--) { s->failed_pc=0x0c08a9a8u; return 0; }
r[0]=0x00000004u;
goto P_0c08a9aa;
P_0c08a9aa: /* original 3b3c, guest PC 0x0c08a9aa */
if(!s->budget--) { s->failed_pc=0x0c08a9aau; return 0; }
r[11]+=r[3];
goto P_0c08a9ac;
P_0c08a9ac: /* original ff37, guest PC 0x0c08a9ac */
if(!s->budget--) { s->failed_pc=0x0c08a9acu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a9ae;
P_0c08a9ae: /* original c725, guest PC 0x0c08a9ae */
if(!s->budget--) { s->failed_pc=0x0c08a9aeu; return 0; }
r[0]=code_base|0x0008aa44u;
goto P_0c08a9b0;
P_0c08a9b0: /* original f308, guest PC 0x0c08a9b0 */
if(!s->budget--) { s->failed_pc=0x0c08a9b0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08a9b2;
P_0c08a9b2: /* original ff3a, guest PC 0x0c08a9b2 */
if(!s->budget--) { s->failed_pc=0x0c08a9b2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08a9b4;
P_0c08a9b4: /* original d224, guest PC 0x0c08a9b4 */
if(!s->budget--) { s->failed_pc=0x0c08a9b4u; return 0; }
r[2]=read(ram,0x0c08aa48u,4);
goto P_0c08a9b6;
P_0c08a9b6: /* original 420b, guest PC 0x0c08a9b6 */
if(!s->budget--) { s->failed_pc=0x0c08a9b6u; return 0; }
target=r[2];
r[16]=code_base|0x0c08a9bau;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a9bau) { target=s->pc; goto dispatch; }
goto P_0c08a9ba;
P_0c08a9b8: /* original 64b3, guest PC 0x0c08a9b8 */
if(!s->budget--) { s->failed_pc=0x0c08a9b8u; return 0; }
r[4]=r[11];
goto P_0c08a9ba;
P_0c08a9ba: /* original e004, guest PC 0x0c08a9ba */
if(!s->budget--) { s->failed_pc=0x0c08a9bau; return 0; }
r[0]=0x00000004u;
goto P_0c08a9bc;
P_0c08a9bc: /* original f3f6, guest PC 0x0c08a9bc */
if(!s->budget--) { s->failed_pc=0x0c08a9bcu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08a9be;
P_0c08a9be: /* original e008, guest PC 0x0c08a9be */
if(!s->budget--) { s->failed_pc=0x0c08a9beu; return 0; }
r[0]=0x00000008u;
goto P_0c08a9c0;
P_0c08a9c0: /* original ff37, guest PC 0x0c08a9c0 */
if(!s->budget--) { s->failed_pc=0x0c08a9c0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a9c2;
P_0c08a9c2: /* original e00c, guest PC 0x0c08a9c2 */
if(!s->budget--) { s->failed_pc=0x0c08a9c2u; return 0; }
r[0]=0x0000000cu;
goto P_0c08a9c4;
P_0c08a9c4: /* original f38d, guest PC 0x0c08a9c4 */
if(!s->budget--) { s->failed_pc=0x0c08a9c4u; return 0; }
fr[3]=0;
goto P_0c08a9c6;
P_0c08a9c6: /* original ff37, guest PC 0x0c08a9c6 */
if(!s->budget--) { s->failed_pc=0x0c08a9c6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a9c8;
P_0c08a9c8: /* original c720, guest PC 0x0c08a9c8 */
if(!s->budget--) { s->failed_pc=0x0c08a9c8u; return 0; }
r[0]=code_base|0x0008aa4cu;
goto P_0c08a9ca;
P_0c08a9ca: /* original f3f8, guest PC 0x0c08a9ca */
if(!s->budget--) { s->failed_pc=0x0c08a9cau; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c08a9cc;
P_0c08a9cc: /* original f408, guest PC 0x0c08a9cc */
if(!s->budget--) { s->failed_pc=0x0c08a9ccu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c08a9ce;
P_0c08a9ce: /* original e010, guest PC 0x0c08a9ce */
if(!s->budget--) { s->failed_pc=0x0c08a9ceu; return 0; }
r[0]=0x00000010u;
goto P_0c08a9d0;
P_0c08a9d0: /* original f340, guest PC 0x0c08a9d0 */
if(!s->budget--) { s->failed_pc=0x0c08a9d0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c08a9d2;
P_0c08a9d2: /* original ff37, guest PC 0x0c08a9d2 */
if(!s->budget--) { s->failed_pc=0x0c08a9d2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a9d4;
P_0c08a9d4: /* original 9e2a, guest PC 0x0c08a9d4 */
if(!s->budget--) { s->failed_pc=0x0c08a9d4u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08aa2cu,2);
goto P_0c08a9d6;
P_0c08a9d6: /* original 66f3, guest PC 0x0c08a9d6 */
if(!s->budget--) { s->failed_pc=0x0c08a9d6u; return 0; }
r[6]=r[15];
goto P_0c08a9d8;
P_0c08a9d8: /* original 65c3, guest PC 0x0c08a9d8 */
if(!s->budget--) { s->failed_pc=0x0c08a9d8u; return 0; }
r[5]=r[12];
goto P_0c08a9da;
P_0c08a9da: /* original 7608, guest PC 0x0c08a9da */
if(!s->budget--) { s->failed_pc=0x0c08a9dau; return 0; }
r[6]+=0x00000008u;
goto P_0c08a9dc;
P_0c08a9dc: /* original 67b3, guest PC 0x0c08a9dc */
if(!s->budget--) { s->failed_pc=0x0c08a9dcu; return 0; }
r[7]=r[11];
goto P_0c08a9de;
P_0c08a9de: /* original be85, guest PC 0x0c08a9de */
if(!s->budget--) { s->failed_pc=0x0c08a9deu; return 0; }
target=code_base|0x0c08a6ecu; r[16]=code_base|0x0c08a9e2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a9e2u) { target=s->pc; goto dispatch; }
goto P_0c08a9e2;
P_0c08a9e0: /* original 64d3, guest PC 0x0c08a9e0 */
if(!s->budget--) { s->failed_pc=0x0c08a9e0u; return 0; }
r[4]=r[13];
goto P_0c08a9e2;
P_0c08a9e2: /* original 4e10, guest PC 0x0c08a9e2 */
if(!s->budget--) { s->failed_pc=0x0c08a9e2u; return 0; }
--r[14];
r[17]=(r[17]&~1u)|((r[14]==0)!=0);
goto P_0c08a9e4;
P_0c08a9e4: /* original 8ff7, guest PC 0x0c08a9e4 */
if(!s->budget--) { s->failed_pc=0x0c08a9e4u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000010u;
if(!cond) { goto P_0c08a9d6; }
goto P_0c08a9e8;
P_0c08a9e6: /* original 7c10, guest PC 0x0c08a9e6 */
if(!s->budget--) { s->failed_pc=0x0c08a9e6u; return 0; }
r[12]+=0x00000010u;
goto P_0c08a9e8;
P_0c08a9e8: /* original 7f14, guest PC 0x0c08a9e8 */
if(!s->budget--) { s->failed_pc=0x0c08a9e8u; return 0; }
r[15]+=0x00000014u;
goto P_0c08a9ea;
P_0c08a9ea: /* original 4f26, guest PC 0x0c08a9ea */
if(!s->budget--) { s->failed_pc=0x0c08a9eau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08a9ec;
P_0c08a9ec: /* original 6bf6, guest PC 0x0c08a9ec */
if(!s->budget--) { s->failed_pc=0x0c08a9ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08a9ee;
P_0c08a9ee: /* original 6cf6, guest PC 0x0c08a9ee */
if(!s->budget--) { s->failed_pc=0x0c08a9eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08a9f0;
P_0c08a9f0: /* original 6df6, guest PC 0x0c08a9f0 */
if(!s->budget--) { s->failed_pc=0x0c08a9f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08a9f2;
P_0c08a9f2: /* original 000b, guest PC 0x0c08a9f2 */
if(!s->budget--) { s->failed_pc=0x0c08a9f2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08a9f4: /* original 6ef6, guest PC 0x0c08a9f4 */
if(!s->budget--) { s->failed_pc=0x0c08a9f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08a9f6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08a9f6u; return 0; } return 1;
P_0c08aa58: /* original 2fe6, guest PC 0x0c08aa58 */
if(!s->budget--) { s->failed_pc=0x0c08aa58u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08aa5a;
P_0c08aa5a: /* original 2fd6, guest PC 0x0c08aa5a */
if(!s->budget--) { s->failed_pc=0x0c08aa5au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08aa5c;
P_0c08aa5c: /* original 2fc6, guest PC 0x0c08aa5c */
if(!s->budget--) { s->failed_pc=0x0c08aa5cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08aa5e;
P_0c08aa5e: /* original 2fb6, guest PC 0x0c08aa5e */
if(!s->budget--) { s->failed_pc=0x0c08aa5eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08aa60;
P_0c08aa60: /* original 2fa6, guest PC 0x0c08aa60 */
if(!s->budget--) { s->failed_pc=0x0c08aa60u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08aa62;
P_0c08aa62: /* original d21d, guest PC 0x0c08aa62 */
if(!s->budget--) { s->failed_pc=0x0c08aa62u; return 0; }
r[2]=read(ram,0x0c08aad8u,4);
goto P_0c08aa64;
P_0c08aa64: /* original 4f22, guest PC 0x0c08aa64 */
if(!s->budget--) { s->failed_pc=0x0c08aa64u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08aa66;
P_0c08aa66: /* original 6322, guest PC 0x0c08aa66 */
if(!s->budget--) { s->failed_pc=0x0c08aa66u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c08aa68;
P_0c08aa68: /* original 7ffc, guest PC 0x0c08aa68 */
if(!s->budget--) { s->failed_pc=0x0c08aa68u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08aa6a;
P_0c08aa6a: /* original 2f32, guest PC 0x0c08aa6a */
if(!s->budget--) { s->failed_pc=0x0c08aa6au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08aa6c;
P_0c08aa6c: /* original 6e41, guest PC 0x0c08aa6c */
if(!s->budget--) { s->failed_pc=0x0c08aa6cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[14]=tmp;
goto P_0c08aa6e;
P_0c08aa6e: /* original 9d30, guest PC 0x0c08aa6e */
if(!s->budget--) { s->failed_pc=0x0c08aa6eu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08aad2u,2);
goto P_0c08aa70;
P_0c08aa70: /* original 4e15, guest PC 0x0c08aa70 */
if(!s->budget--) { s->failed_pc=0x0c08aa70u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c08aa72;
P_0c08aa72: /* original 8f26, guest PC 0x0c08aa72 */
if(!s->budget--) { s->failed_pc=0x0c08aa72u; return 0; }
cond=r[17]&1u;
r[13]+=r[4];
if(!cond) { goto P_0c08aac2; }
goto P_0c08aa76;
P_0c08aa74: /* original 3d4c, guest PC 0x0c08aa74 */
if(!s->budget--) { s->failed_pc=0x0c08aa74u; return 0; }
r[13]+=r[4];
goto P_0c08aa76;
P_0c08aa76: /* original d219, guest PC 0x0c08aa76 */
if(!s->budget--) { s->failed_pc=0x0c08aa76u; return 0; }
r[2]=read(ram,0x0c08aadcu,4);
goto P_0c08aa78;
P_0c08aa78: /* original 420b, guest PC 0x0c08aa78 */
if(!s->budget--) { s->failed_pc=0x0c08aa78u; return 0; }
target=r[2];
r[16]=code_base|0x0c08aa7cu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08aa7cu) { target=s->pc; goto dispatch; }
goto P_0c08aa7c;
P_0c08aa7a: /* original e400, guest PC 0x0c08aa7a */
if(!s->budget--) { s->failed_pc=0x0c08aa7au; return 0; }
r[4]=0x00000000u;
goto P_0c08aa7c;
P_0c08aa7c: /* original 64f2, guest PC 0x0c08aa7c */
if(!s->budget--) { s->failed_pc=0x0c08aa7cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c08aa7e;
P_0c08aa7e: /* original e2f3, guest PC 0x0c08aa7e */
if(!s->budget--) { s->failed_pc=0x0c08aa7eu; return 0; }
r[2]=0xfffffff3u;
goto P_0c08aa80;
P_0c08aa80: /* original 9329, guest PC 0x0c08aa80 */
if(!s->budget--) { s->failed_pc=0x0c08aa80u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08aad6u,2);
goto P_0c08aa82;
P_0c08aa82: /* original e103, guest PC 0x0c08aa82 */
if(!s->budget--) { s->failed_pc=0x0c08aa82u; return 0; }
r[1]=0x00000003u;
goto P_0c08aa84;
P_0c08aa84: /* original 854f, guest PC 0x0c08aa84 */
if(!s->budget--) { s->failed_pc=0x0c08aa84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c08aa86;
P_0c08aa86: /* original 9c25, guest PC 0x0c08aa86 */
if(!s->budget--) { s->failed_pc=0x0c08aa86u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08aad4u,2);
goto P_0c08aa88;
P_0c08aa88: /* original 6403, guest PC 0x0c08aa88 */
if(!s->budget--) { s->failed_pc=0x0c08aa88u; return 0; }
r[4]=r[0];
goto P_0c08aa8a;
P_0c08aa8a: /* original 343c, guest PC 0x0c08aa8a */
if(!s->budget--) { s->failed_pc=0x0c08aa8au; return 0; }
r[4]+=r[3];
goto P_0c08aa8c;
P_0c08aa8c: /* original 442c, guest PC 0x0c08aa8c */
if(!s->budget--) { s->failed_pc=0x0c08aa8cu; return 0; }
r[4]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[4]>>((-r[2])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[2]&31u);
goto P_0c08aa8e;
P_0c08aa8e: /* original d214, guest PC 0x0c08aa8e */
if(!s->budget--) { s->failed_pc=0x0c08aa8eu; return 0; }
r[2]=read(ram,0x0c08aae0u,4);
goto P_0c08aa90;
P_0c08aa90: /* original 2419, guest PC 0x0c08aa90 */
if(!s->budget--) { s->failed_pc=0x0c08aa90u; return 0; }
r[4]&=r[1];
goto P_0c08aa92;
P_0c08aa92: /* original 420b, guest PC 0x0c08aa92 */
if(!s->budget--) { s->failed_pc=0x0c08aa92u; return 0; }
target=r[2];
r[16]=code_base|0x0c08aa96u;
r[12]+=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08aa96u) { target=s->pc; goto dispatch; }
goto P_0c08aa96;
P_0c08aa94: /* original 3c4c, guest PC 0x0c08aa94 */
if(!s->budget--) { s->failed_pc=0x0c08aa94u; return 0; }
r[12]+=r[4];
goto P_0c08aa96;
P_0c08aa96: /* original db14, guest PC 0x0c08aa96 */
if(!s->budget--) { s->failed_pc=0x0c08aa96u; return 0; }
r[11]=read(ram,0x0c08aae8u,4);
goto P_0c08aa98;
P_0c08aa98: /* original da12, guest PC 0x0c08aa98 */
if(!s->budget--) { s->failed_pc=0x0c08aa98u; return 0; }
r[10]=read(ram,0x0c08aae4u,4);
goto P_0c08aa9a;
P_0c08aa9a: /* original a006, guest PC 0x0c08aa9a */
if(!s->budget--) { s->failed_pc=0x0c08aa9au; return 0; }
goto P_0c08aaaa;
P_0c08aa9c: /* original 0009, guest PC 0x0c08aa9c */
if(!s->budget--) { s->failed_pc=0x0c08aa9cu; return 0; }
goto P_0c08aa9e;
P_0c08aa9e: /* original 4a0b, guest PC 0x0c08aa9e */
if(!s->budget--) { s->failed_pc=0x0c08aa9eu; return 0; }
target=r[10];
r[16]=code_base|0x0c08aaa2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08aaa2u) { target=s->pc; goto dispatch; }
goto P_0c08aaa2;
P_0c08aaa0: /* original 64d3, guest PC 0x0c08aaa0 */
if(!s->budget--) { s->failed_pc=0x0c08aaa0u; return 0; }
r[4]=r[13];
goto P_0c08aaa2;
P_0c08aaa2: /* original 4b0b, guest PC 0x0c08aaa2 */
if(!s->budget--) { s->failed_pc=0x0c08aaa2u; return 0; }
target=r[11];
r[16]=code_base|0x0c08aaa6u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08aaa6u) { target=s->pc; goto dispatch; }
goto P_0c08aaa6;
P_0c08aaa4: /* original 64c3, guest PC 0x0c08aaa4 */
if(!s->budget--) { s->failed_pc=0x0c08aaa4u; return 0; }
r[4]=r[12];
goto P_0c08aaa6;
P_0c08aaa6: /* original 7eff, guest PC 0x0c08aaa6 */
if(!s->budget--) { s->failed_pc=0x0c08aaa6u; return 0; }
r[14]+=0xffffffffu;
goto P_0c08aaa8;
P_0c08aaa8: /* original 7d10, guest PC 0x0c08aaa8 */
if(!s->budget--) { s->failed_pc=0x0c08aaa8u; return 0; }
r[13]+=0x00000010u;
goto P_0c08aaaa;
P_0c08aaaa: /* original 2ee8, guest PC 0x0c08aaaa */
if(!s->budget--) { s->failed_pc=0x0c08aaaau; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c08aaac;
P_0c08aaac: /* original 8bf7, guest PC 0x0c08aaac */
if(!s->budget--) { s->failed_pc=0x0c08aaacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08aa9e; }
goto P_0c08aaae;
P_0c08aaae: /* original 7f04, guest PC 0x0c08aaae */
if(!s->budget--) { s->failed_pc=0x0c08aaaeu; return 0; }
r[15]+=0x00000004u;
goto P_0c08aab0;
P_0c08aab0: /* original d30e, guest PC 0x0c08aab0 */
if(!s->budget--) { s->failed_pc=0x0c08aab0u; return 0; }
r[3]=read(ram,0x0c08aaecu,4);
goto P_0c08aab2;
P_0c08aab2: /* original 4f26, guest PC 0x0c08aab2 */
if(!s->budget--) { s->failed_pc=0x0c08aab2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08aab4;
P_0c08aab4: /* original e401, guest PC 0x0c08aab4 */
if(!s->budget--) { s->failed_pc=0x0c08aab4u; return 0; }
r[4]=0x00000001u;
goto P_0c08aab6;
P_0c08aab6: /* original 6af6, guest PC 0x0c08aab6 */
if(!s->budget--) { s->failed_pc=0x0c08aab6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08aab8;
P_0c08aab8: /* original 6bf6, guest PC 0x0c08aab8 */
if(!s->budget--) { s->failed_pc=0x0c08aab8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08aaba;
P_0c08aaba: /* original 6cf6, guest PC 0x0c08aaba */
if(!s->budget--) { s->failed_pc=0x0c08aabau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08aabc;
P_0c08aabc: /* original 6df6, guest PC 0x0c08aabc */
if(!s->budget--) { s->failed_pc=0x0c08aabcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08aabe;
P_0c08aabe: /* original 432b, guest PC 0x0c08aabe */
if(!s->budget--) { s->failed_pc=0x0c08aabeu; return 0; }
target=r[3];
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
P_0c08aac0: /* original 6ef6, guest PC 0x0c08aac0 */
if(!s->budget--) { s->failed_pc=0x0c08aac0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08aac2;
P_0c08aac2: /* original 7f04, guest PC 0x0c08aac2 */
if(!s->budget--) { s->failed_pc=0x0c08aac2u; return 0; }
r[15]+=0x00000004u;
goto P_0c08aac4;
P_0c08aac4: /* original 4f26, guest PC 0x0c08aac4 */
if(!s->budget--) { s->failed_pc=0x0c08aac4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08aac6;
P_0c08aac6: /* original 6af6, guest PC 0x0c08aac6 */
if(!s->budget--) { s->failed_pc=0x0c08aac6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08aac8;
P_0c08aac8: /* original 6bf6, guest PC 0x0c08aac8 */
if(!s->budget--) { s->failed_pc=0x0c08aac8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08aaca;
P_0c08aaca: /* original 6cf6, guest PC 0x0c08aaca */
if(!s->budget--) { s->failed_pc=0x0c08aacau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08aacc;
P_0c08aacc: /* original 6df6, guest PC 0x0c08aacc */
if(!s->budget--) { s->failed_pc=0x0c08aaccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08aace;
P_0c08aace: /* original 000b, guest PC 0x0c08aace */
if(!s->budget--) { s->failed_pc=0x0c08aaceu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08aad0: /* original 6ef6, guest PC 0x0c08aad0 */
if(!s->budget--) { s->failed_pc=0x0c08aad0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08aad2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08aad2u; return 0; } return 1;
P_0c08acc0: /* original 2fe6, guest PC 0x0c08acc0 */
if(!s->budget--) { s->failed_pc=0x0c08acc0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08acc2;
P_0c08acc2: /* original 2fd6, guest PC 0x0c08acc2 */
if(!s->budget--) { s->failed_pc=0x0c08acc2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08acc4;
P_0c08acc4: /* original 2fc6, guest PC 0x0c08acc4 */
if(!s->budget--) { s->failed_pc=0x0c08acc4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08acc6;
P_0c08acc6: /* original 2fb6, guest PC 0x0c08acc6 */
if(!s->budget--) { s->failed_pc=0x0c08acc6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08acc8;
P_0c08acc8: /* original 2fa6, guest PC 0x0c08acc8 */
if(!s->budget--) { s->failed_pc=0x0c08acc8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08acca;
P_0c08acca: /* original 2f96, guest PC 0x0c08acca */
if(!s->budget--) { s->failed_pc=0x0c08accau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08accc;
P_0c08accc: /* original 2f86, guest PC 0x0c08accc */
if(!s->budget--) { s->failed_pc=0x0c08acccu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08acce;
P_0c08acce: /* original fffb, guest PC 0x0c08acce */
if(!s->budget--) { s->failed_pc=0x0c08acceu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08acd0;
P_0c08acd0: /* original ffeb, guest PC 0x0c08acd0 */
if(!s->budget--) { s->failed_pc=0x0c08acd0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08acd2;
P_0c08acd2: /* original ffdb, guest PC 0x0c08acd2 */
if(!s->budget--) { s->failed_pc=0x0c08acd2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c08acd4;
P_0c08acd4: /* original ffcb, guest PC 0x0c08acd4 */
if(!s->budget--) { s->failed_pc=0x0c08acd4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c08acd6;
P_0c08acd6: /* original d132, guest PC 0x0c08acd6 */
if(!s->budget--) { s->failed_pc=0x0c08acd6u; return 0; }
r[1]=read(ram,0x0c08ada0u,4);
goto P_0c08acd8;
P_0c08acd8: /* original 4f22, guest PC 0x0c08acd8 */
if(!s->budget--) { s->failed_pc=0x0c08acd8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08acda;
P_0c08acda: /* original d330, guest PC 0x0c08acda */
if(!s->budget--) { s->failed_pc=0x0c08acdau; return 0; }
r[3]=read(ram,0x0c08ad9cu,4);
goto P_0c08acdc;
P_0c08acdc: /* original 6212, guest PC 0x0c08acdc */
if(!s->budget--) { s->failed_pc=0x0c08acdcu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c08acde;
P_0c08acde: /* original 7fec, guest PC 0x0c08acde */
if(!s->budget--) { s->failed_pc=0x0c08acdeu; return 0; }
r[15]+=0xffffffecu;
goto P_0c08ace0;
P_0c08ace0: /* original 2238, guest PC 0x0c08ace0 */
if(!s->budget--) { s->failed_pc=0x0c08ace0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c08ace2;
P_0c08ace2: /* original 8901, guest PC 0x0c08ace2 */
if(!s->budget--) { s->failed_pc=0x0c08ace2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ace8; }
goto P_0c08ace4;
P_0c08ace4: /* original a126, guest PC 0x0c08ace4 */
if(!s->budget--) { s->failed_pc=0x0c08ace4u; return 0; }
goto P_0c08af34;
P_0c08ace6: /* original 0009, guest PC 0x0c08ace6 */
if(!s->budget--) { s->failed_pc=0x0c08ace6u; return 0; }
goto P_0c08ace8;
P_0c08ace8: /* original dc2e, guest PC 0x0c08ace8 */
if(!s->budget--) { s->failed_pc=0x0c08ace8u; return 0; }
r[12]=read(ram,0x0c08ada4u,4);
goto P_0c08acea;
P_0c08acea: /* original e074, guest PC 0x0c08acea */
if(!s->budget--) { s->failed_pc=0x0c08aceau; return 0; }
r[0]=0x00000074u;
goto P_0c08acec;
P_0c08acec: /* original 6843, guest PC 0x0c08acec */
if(!s->budget--) { s->failed_pc=0x0c08acecu; return 0; }
r[8]=r[4];
goto P_0c08acee;
P_0c08acee: /* original 03ce, guest PC 0x0c08acee */
if(!s->budget--) { s->failed_pc=0x0c08aceeu; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c08acf0;
P_0c08acf0: /* original 1f33, guest PC 0x0c08acf0 */
if(!s->budget--) { s->failed_pc=0x0c08acf0u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c08acf2;
P_0c08acf2: /* original d32d, guest PC 0x0c08acf2 */
if(!s->budget--) { s->failed_pc=0x0c08acf2u; return 0; }
r[3]=read(ram,0x0c08ada8u,4);
goto P_0c08acf4;
P_0c08acf4: /* original d22d, guest PC 0x0c08acf4 */
if(!s->budget--) { s->failed_pc=0x0c08acf4u; return 0; }
r[2]=read(ram,0x0c08adacu,4);
goto P_0c08acf6;
P_0c08acf6: /* original 6432, guest PC 0x0c08acf6 */
if(!s->budget--) { s->failed_pc=0x0c08acf6u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c08acf8;
P_0c08acf8: /* original 2428, guest PC 0x0c08acf8 */
if(!s->budget--) { s->failed_pc=0x0c08acf8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c08acfa;
P_0c08acfa: /* original 8901, guest PC 0x0c08acfa */
if(!s->budget--) { s->failed_pc=0x0c08acfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ad00; }
goto P_0c08acfc;
P_0c08acfc: /* original a11a, guest PC 0x0c08acfc */
if(!s->budget--) { s->failed_pc=0x0c08acfcu; return 0; }
goto P_0c08af34;
P_0c08acfe: /* original 0009, guest PC 0x0c08acfe */
if(!s->budget--) { s->failed_pc=0x0c08acfeu; return 0; }
goto P_0c08ad00;
P_0c08ad00: /* original 8589, guest PC 0x0c08ad00 */
if(!s->budget--) { s->failed_pc=0x0c08ad00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+18,2);
goto P_0c08ad02;
P_0c08ad02: /* original 923f, guest PC 0x0c08ad02 */
if(!s->budget--) { s->failed_pc=0x0c08ad02u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ad84u,2);
goto P_0c08ad04;
P_0c08ad04: /* original 6303, guest PC 0x0c08ad04 */
if(!s->budget--) { s->failed_pc=0x0c08ad04u; return 0; }
r[3]=r[0];
goto P_0c08ad06;
P_0c08ad06: /* original 7301, guest PC 0x0c08ad06 */
if(!s->budget--) { s->failed_pc=0x0c08ad06u; return 0; }
r[3]+=0x00000001u;
goto P_0c08ad08;
P_0c08ad08: /* original 3320, guest PC 0x0c08ad08 */
if(!s->budget--) { s->failed_pc=0x0c08ad08u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c08ad0a;
P_0c08ad0a: /* original 8f04, guest PC 0x0c08ad0a */
if(!s->budget--) { s->failed_pc=0x0c08ad0au; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c08ad16; }
goto P_0c08ad0e;
P_0c08ad0c: /* original 2f32, guest PC 0x0c08ad0c */
if(!s->budget--) { s->failed_pc=0x0c08ad0cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08ad0e;
P_0c08ad0e: /* original 52f3, guest PC 0x0c08ad0e */
if(!s->budget--) { s->failed_pc=0x0c08ad0eu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c08ad10;
P_0c08ad10: /* original 6022, guest PC 0x0c08ad10 */
if(!s->budget--) { s->failed_pc=0x0c08ad10u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c08ad12;
P_0c08ad12: /* original cb02, guest PC 0x0c08ad12 */
if(!s->budget--) { s->failed_pc=0x0c08ad12u; return 0; }
r[0]|=2u;
goto P_0c08ad14;
P_0c08ad14: /* original 2202, guest PC 0x0c08ad14 */
if(!s->budget--) { s->failed_pc=0x0c08ad14u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c08ad16;
P_0c08ad16: /* original 63f2, guest PC 0x0c08ad16 */
if(!s->budget--) { s->failed_pc=0x0c08ad16u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08ad18;
P_0c08ad18: /* original c725, guest PC 0x0c08ad18 */
if(!s->budget--) { s->failed_pc=0x0c08ad18u; return 0; }
r[0]=code_base|0x0008adb0u;
goto P_0c08ad1a;
P_0c08ad1a: /* original fe08, guest PC 0x0c08ad1a */
if(!s->budget--) { s->failed_pc=0x0c08ad1au; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c08ad1c;
P_0c08ad1c: /* original c725, guest PC 0x0c08ad1c */
if(!s->budget--) { s->failed_pc=0x0c08ad1cu; return 0; }
r[0]=code_base|0x0008adb4u;
goto P_0c08ad1e;
P_0c08ad1e: /* original 435a, guest PC 0x0c08ad1e */
if(!s->budget--) { s->failed_pc=0x0c08ad1eu; return 0; }
r[53]=r[3];
goto P_0c08ad20;
P_0c08ad20: /* original ed01, guest PC 0x0c08ad20 */
if(!s->budget--) { s->failed_pc=0x0c08ad20u; return 0; }
r[13]=0x00000001u;
goto P_0c08ad22;
P_0c08ad22: /* original 62f2, guest PC 0x0c08ad22 */
if(!s->budget--) { s->failed_pc=0x0c08ad22u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c08ad24;
P_0c08ad24: /* original 932f, guest PC 0x0c08ad24 */
if(!s->budget--) { s->failed_pc=0x0c08ad24u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ad86u,2);
goto P_0c08ad26;
P_0c08ad26: /* original f32d, guest PC 0x0c08ad26 */
if(!s->budget--) { s->failed_pc=0x0c08ad26u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c08ad28;
P_0c08ad28: /* original da23, guest PC 0x0c08ad28 */
if(!s->budget--) { s->failed_pc=0x0c08ad28u; return 0; }
r[10]=read(ram,0x0c08adb8u,4);
goto P_0c08ad2a;
P_0c08ad2a: /* original ff08, guest PC 0x0c08ad2a */
if(!s->budget--) { s->failed_pc=0x0c08ad2au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08ad2c;
P_0c08ad2c: /* original 3233, guest PC 0x0c08ad2c */
if(!s->budget--) { s->failed_pc=0x0c08ad2cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c08ad2e;
P_0c08ad2e: /* original db23, guest PC 0x0c08ad2e */
if(!s->budget--) { s->failed_pc=0x0c08ad2eu; return 0; }
r[11]=read(ram,0x0c08adbcu,4);
goto P_0c08ad30;
P_0c08ad30: /* original 8d75, guest PC 0x0c08ad30 */
if(!s->budget--) { s->failed_pc=0x0c08ad30u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,12,3);
if(cond) { goto P_0c08ae1e; }
goto P_0c08ad34;
P_0c08ad32: /* original fc3c, guest PC 0x0c08ad32 */
if(!s->budget--) { s->failed_pc=0x0c08ad32u; return 0; }
vf3_matrix_move(s,12,3);
goto P_0c08ad34;
P_0c08ad34: /* original c722, guest PC 0x0c08ad34 */
if(!s->budget--) { s->failed_pc=0x0c08ad34u; return 0; }
r[0]=code_base|0x0008adc0u;
goto P_0c08ad36;
P_0c08ad36: /* original f0cc, guest PC 0x0c08ad36 */
if(!s->budget--) { s->failed_pc=0x0c08ad36u; return 0; }
vf3_matrix_move(s,0,12);
goto P_0c08ad38;
P_0c08ad38: /* original f408, guest PC 0x0c08ad38 */
if(!s->budget--) { s->failed_pc=0x0c08ad38u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c08ad3a;
P_0c08ad3a: /* original c722, guest PC 0x0c08ad3a */
if(!s->budget--) { s->failed_pc=0x0c08ad3au; return 0; }
r[0]=code_base|0x0008adc4u;
goto P_0c08ad3c;
P_0c08ad3c: /* original f508, guest PC 0x0c08ad3c */
if(!s->budget--) { s->failed_pc=0x0c08ad3cu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c08ad3e;
P_0c08ad3e: /* original e030, guest PC 0x0c08ad3e */
if(!s->budget--) { s->failed_pc=0x0c08ad3eu; return 0; }
r[0]=0x00000030u;
goto P_0c08ad40;
P_0c08ad40: /* original f45e, guest PC 0x0c08ad40 */
if(!s->budget--) { s->failed_pc=0x0c08ad40u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[5],fr[4],r[18]);
goto P_0c08ad42;
P_0c08ad42: /* original fd4c, guest PC 0x0c08ad42 */
if(!s->budget--) { s->failed_pc=0x0c08ad42u; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c08ad44;
P_0c08ad44: /* original f8d7, guest PC 0x0c08ad44 */
if(!s->budget--) { s->failed_pc=0x0c08ad44u; return 0; }
vf3_matrix_store(s,ram,13,r[8]+r[0]);
goto P_0c08ad46;
P_0c08ad46: /* original 60f2, guest PC 0x0c08ad46 */
if(!s->budget--) { s->failed_pc=0x0c08ad46u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c08ad48;
P_0c08ad48: /* original 8189, guest PC 0x0c08ad48 */
if(!s->budget--) { s->failed_pc=0x0c08ad48u; return 0; }
write(ram,r[8]+18,r[0],2);
goto P_0c08ad4a;
P_0c08ad4a: /* original c71f, guest PC 0x0c08ad4a */
if(!s->budget--) { s->failed_pc=0x0c08ad4au; return 0; }
r[0]=code_base|0x0008adc8u;
goto P_0c08ad4c;
P_0c08ad4c: /* original f308, guest PC 0x0c08ad4c */
if(!s->budget--) { s->failed_pc=0x0c08ad4cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08ad4e;
P_0c08ad4e: /* original e010, guest PC 0x0c08ad4e */
if(!s->budget--) { s->failed_pc=0x0c08ad4eu; return 0; }
r[0]=0x00000010u;
goto P_0c08ad50;
P_0c08ad50: /* original 5ec4, guest PC 0x0c08ad50 */
if(!s->budget--) { s->failed_pc=0x0c08ad50u; return 0; }
r[14]=read(ram,r[12]+16,4);
goto P_0c08ad52;
P_0c08ad52: /* original ff37, guest PC 0x0c08ad52 */
if(!s->budget--) { s->failed_pc=0x0c08ad52u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08ad54;
P_0c08ad54: /* original c71d, guest PC 0x0c08ad54 */
if(!s->budget--) { s->failed_pc=0x0c08ad54u; return 0; }
r[0]=code_base|0x0008adccu;
goto P_0c08ad56;
P_0c08ad56: /* original f308, guest PC 0x0c08ad56 */
if(!s->budget--) { s->failed_pc=0x0c08ad56u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08ad58;
P_0c08ad58: /* original fd30, guest PC 0x0c08ad58 */
if(!s->budget--) { s->failed_pc=0x0c08ad58u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'+');
goto P_0c08ad5a;
P_0c08ad5a: /* original a05c, guest PC 0x0c08ad5a */
if(!s->budget--) { s->failed_pc=0x0c08ad5au; return 0; }
r[3]=0x00000002u;
goto P_0c08ae16;
P_0c08ad5c: /* original e302, guest PC 0x0c08ad5c */
if(!s->budget--) { s->failed_pc=0x0c08ad5cu; return 0; }
r[3]=0x00000002u;
goto P_0c08ad5e;
P_0c08ad5e: /* original 9013, guest PC 0x0c08ad5e */
if(!s->budget--) { s->failed_pc=0x0c08ad5eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ad88u,2);
goto P_0c08ad60;
P_0c08ad60: /* original 09ec, guest PC 0x0c08ad60 */
if(!s->budget--) { s->failed_pc=0x0c08ad60u; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08ad62;
P_0c08ad62: /* original 9012, guest PC 0x0c08ad62 */
if(!s->budget--) { s->failed_pc=0x0c08ad62u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ad8au,2);
goto P_0c08ad64;
P_0c08ad64: /* original 699c, guest PC 0x0c08ad64 */
if(!s->budget--) { s->failed_pc=0x0c08ad64u; return 0; }
r[9]=r[9]&255u;
goto P_0c08ad66;
P_0c08ad66: /* original f4e6, guest PC 0x0c08ad66 */
if(!s->budget--) { s->failed_pc=0x0c08ad66u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08ad68;
P_0c08ad68: /* original 7008, guest PC 0x0c08ad68 */
if(!s->budget--) { s->failed_pc=0x0c08ad68u; return 0; }
r[0]+=0x00000008u;
goto P_0c08ad6a;
P_0c08ad6a: /* original f5e6, guest PC 0x0c08ad6a */
if(!s->budget--) { s->failed_pc=0x0c08ad6au; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08ad6c;
P_0c08ad6c: /* original e010, guest PC 0x0c08ad6c */
if(!s->budget--) { s->failed_pc=0x0c08ad6cu; return 0; }
r[0]=0x00000010u;
goto P_0c08ad6e;
P_0c08ad6e: /* original f3f6, guest PC 0x0c08ad6e */
if(!s->budget--) { s->failed_pc=0x0c08ad6eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08ad70;
P_0c08ad70: /* original f345, guest PC 0x0c08ad70 */
if(!s->budget--) { s->failed_pc=0x0c08ad70u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c08ad72;
P_0c08ad72: /* original 8d02, guest PC 0x0c08ad72 */
if(!s->budget--) { s->failed_pc=0x0c08ad72u; return 0; }
cond=r[17]&1u;
fr[5]^=0x80000000u;
if(cond) { goto P_0c08ad7a; }
goto P_0c08ad76;
P_0c08ad74: /* original f54d, guest PC 0x0c08ad74 */
if(!s->budget--) { s->failed_pc=0x0c08ad74u; return 0; }
fr[5]^=0x80000000u;
goto P_0c08ad76;
P_0c08ad76: /* original f5d5, guest PC 0x0c08ad76 */
if(!s->budget--) { s->failed_pc=0x0c08ad76u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[13]))!=0);
goto P_0c08ad78;
P_0c08ad78: /* original 8b2a, guest PC 0x0c08ad78 */
if(!s->budget--) { s->failed_pc=0x0c08ad78u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08add0; }
goto P_0c08ad7a;
P_0c08ad7a: /* original e3fe, guest PC 0x0c08ad7a */
if(!s->budget--) { s->failed_pc=0x0c08ad7au; return 0; }
r[3]=0xfffffffeu;
goto P_0c08ad7c;
P_0c08ad7c: /* original a046, guest PC 0x0c08ad7c */
if(!s->budget--) { s->failed_pc=0x0c08ad7cu; return 0; }
r[9]&=r[3];
goto P_0c08ae0c;
P_0c08ad7e: /* original 2939, guest PC 0x0c08ad7e */
if(!s->budget--) { s->failed_pc=0x0c08ad7eu; return 0; }
r[9]&=r[3];
if(!vf3_matrix_family(0x0c08ad80u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08ad80u; return 0; } return 1;
P_0c08add0: /* original 6193, guest PC 0x0c08add0 */
if(!s->budget--) { s->failed_pc=0x0c08add0u; return 0; }
r[1]=r[9];
goto P_0c08add2;
P_0c08add2: /* original 21d8, guest PC 0x0c08add2 */
if(!s->budget--) { s->failed_pc=0x0c08add2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[13])==0)!=0);
goto P_0c08add4;
P_0c08add4: /* original 8b1a, guest PC 0x0c08add4 */
if(!s->budget--) { s->failed_pc=0x0c08add4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08ae0c; }
goto P_0c08add6;
P_0c08add6: /* original d22b, guest PC 0x0c08add6 */
if(!s->budget--) { s->failed_pc=0x0c08add6u; return 0; }
r[2]=read(ram,0x0c08ae84u,4);
goto P_0c08add8;
P_0c08add8: /* original 29db, guest PC 0x0c08add8 */
if(!s->budget--) { s->failed_pc=0x0c08add8u; return 0; }
r[9]|=r[13];
goto P_0c08adda;
P_0c08adda: /* original 1e2d, guest PC 0x0c08adda */
if(!s->budget--) { s->failed_pc=0x0c08addau; return 0; }
write(ram,r[14]+52,r[2],4);
goto P_0c08addc;
P_0c08addc: /* original 904a, guest PC 0x0c08addc */
if(!s->budget--) { s->failed_pc=0x0c08addcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ae74u,2);
goto P_0c08adde;
P_0c08adde: /* original 81ef, guest PC 0x0c08adde */
if(!s->budget--) { s->failed_pc=0x0c08addeu; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c08ade0;
P_0c08ade0: /* original 9049, guest PC 0x0c08ade0 */
if(!s->budget--) { s->failed_pc=0x0c08ade0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ae76u,2);
goto P_0c08ade2;
P_0c08ade2: /* original fef7, guest PC 0x0c08ade2 */
if(!s->budget--) { s->failed_pc=0x0c08ade2u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c08ade4;
P_0c08ade4: /* original 7008, guest PC 0x0c08ade4 */
if(!s->budget--) { s->failed_pc=0x0c08ade4u; return 0; }
r[0]+=0x00000008u;
goto P_0c08ade6;
P_0c08ade6: /* original fee7, guest PC 0x0c08ade6 */
if(!s->budget--) { s->failed_pc=0x0c08ade6u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c08ade8;
P_0c08ade8: /* original 9346, guest PC 0x0c08ade8 */
if(!s->budget--) { s->failed_pc=0x0c08ade8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ae78u,2);
goto P_0c08adea;
P_0c08adea: /* original 1f31, guest PC 0x0c08adea */
if(!s->budget--) { s->failed_pc=0x0c08adeau; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c08adec;
P_0c08adec: /* original 4b0b, guest PC 0x0c08adec */
if(!s->budget--) { s->failed_pc=0x0c08adecu; return 0; }
target=r[11];
r[16]=code_base|0x0c08adf0u;
r[4]=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08adf0u) { target=s->pc; goto dispatch; }
goto P_0c08adf0;
P_0c08adee: /* original 6433, guest PC 0x0c08adee */
if(!s->budget--) { s->failed_pc=0x0c08adeeu; return 0; }
r[4]=r[3];
goto P_0c08adf0;
P_0c08adf0: /* original 4a0b, guest PC 0x0c08adf0 */
if(!s->budget--) { s->failed_pc=0x0c08adf0u; return 0; }
target=r[10];
r[16]=code_base|0x0c08adf4u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08adf4u) { target=s->pc; goto dispatch; }
goto P_0c08adf4;
P_0c08adf2: /* original 54f1, guest PC 0x0c08adf2 */
if(!s->budget--) { s->failed_pc=0x0c08adf2u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c08adf4;
P_0c08adf4: /* original 4b0b, guest PC 0x0c08adf4 */
if(!s->budget--) { s->failed_pc=0x0c08adf4u; return 0; }
target=r[11];
r[16]=code_base|0x0c08adf8u;
r[4]=0x0000006cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08adf8u) { target=s->pc; goto dispatch; }
goto P_0c08adf8;
P_0c08adf6: /* original e46c, guest PC 0x0c08adf6 */
if(!s->budget--) { s->failed_pc=0x0c08adf6u; return 0; }
r[4]=0x0000006cu;
goto P_0c08adf8;
P_0c08adf8: /* original 4a0b, guest PC 0x0c08adf8 */
if(!s->budget--) { s->failed_pc=0x0c08adf8u; return 0; }
target=r[10];
r[16]=code_base|0x0c08adfcu;
r[4]=0x0000006cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08adfcu) { target=s->pc; goto dispatch; }
goto P_0c08adfc;
P_0c08adfa: /* original e46c, guest PC 0x0c08adfa */
if(!s->budget--) { s->failed_pc=0x0c08adfau; return 0; }
r[4]=0x0000006cu;
goto P_0c08adfc;
P_0c08adfc: /* original e046, guest PC 0x0c08adfc */
if(!s->budget--) { s->failed_pc=0x0c08adfcu; return 0; }
r[0]=0x00000046u;
goto P_0c08adfe;
P_0c08adfe: /* original 55c5, guest PC 0x0c08adfe */
if(!s->budget--) { s->failed_pc=0x0c08adfeu; return 0; }
r[5]=read(ram,r[12]+20,4);
goto P_0c08ae00;
P_0c08ae00: /* original 06ed, guest PC 0x0c08ae00 */
if(!s->budget--) { s->failed_pc=0x0c08ae00u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08ae02;
P_0c08ae02: /* original d321, guest PC 0x0c08ae02 */
if(!s->budget--) { s->failed_pc=0x0c08ae02u; return 0; }
r[3]=read(ram,0x0c08ae88u,4);
goto P_0c08ae04;
P_0c08ae04: /* original 666d, guest PC 0x0c08ae04 */
if(!s->budget--) { s->failed_pc=0x0c08ae04u; return 0; }
r[6]=r[6]&65535u;
goto P_0c08ae06;
P_0c08ae06: /* original 76ff, guest PC 0x0c08ae06 */
if(!s->budget--) { s->failed_pc=0x0c08ae06u; return 0; }
r[6]+=0xffffffffu;
goto P_0c08ae08;
P_0c08ae08: /* original 430b, guest PC 0x0c08ae08 */
if(!s->budget--) { s->failed_pc=0x0c08ae08u; return 0; }
target=r[3];
r[16]=code_base|0x0c08ae0cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ae0cu) { target=s->pc; goto dispatch; }
goto P_0c08ae0c;
P_0c08ae0a: /* original 64e3, guest PC 0x0c08ae0a */
if(!s->budget--) { s->failed_pc=0x0c08ae0au; return 0; }
r[4]=r[14];
goto P_0c08ae0c;
P_0c08ae0c: /* original 9035, guest PC 0x0c08ae0c */
if(!s->budget--) { s->failed_pc=0x0c08ae0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ae7au,2);
goto P_0c08ae0e;
P_0c08ae0e: /* original 0e94, guest PC 0x0c08ae0e */
if(!s->budget--) { s->failed_pc=0x0c08ae0eu; return 0; }
write(ram,r[14]+r[0],r[9],1);
goto P_0c08ae10;
P_0c08ae10: /* original 53f2, guest PC 0x0c08ae10 */
if(!s->budget--) { s->failed_pc=0x0c08ae10u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c08ae12;
P_0c08ae12: /* original 5ec5, guest PC 0x0c08ae12 */
if(!s->budget--) { s->failed_pc=0x0c08ae12u; return 0; }
r[14]=read(ram,r[12]+20,4);
goto P_0c08ae14;
P_0c08ae14: /* original 73ff, guest PC 0x0c08ae14 */
if(!s->budget--) { s->failed_pc=0x0c08ae14u; return 0; }
r[3]+=0xffffffffu;
goto P_0c08ae16;
P_0c08ae16: /* original 6233, guest PC 0x0c08ae16 */
if(!s->budget--) { s->failed_pc=0x0c08ae16u; return 0; }
r[2]=r[3];
goto P_0c08ae18;
P_0c08ae18: /* original 2228, guest PC 0x0c08ae18 */
if(!s->budget--) { s->failed_pc=0x0c08ae18u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c08ae1a;
P_0c08ae1a: /* original 8fa0, guest PC 0x0c08ae1a */
if(!s->budget--) { s->failed_pc=0x0c08ae1au; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[3],4);
if(!cond) { goto P_0c08ad5e; }
goto P_0c08ae1e;
P_0c08ae1c: /* original 1f32, guest PC 0x0c08ae1c */
if(!s->budget--) { s->failed_pc=0x0c08ae1cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c08ae1e;
P_0c08ae1e: /* original 61f2, guest PC 0x0c08ae1e */
if(!s->budget--) { s->failed_pc=0x0c08ae1eu; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c08ae20;
P_0c08ae20: /* original 922c, guest PC 0x0c08ae20 */
if(!s->budget--) { s->failed_pc=0x0c08ae20u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ae7cu,2);
goto P_0c08ae22;
P_0c08ae22: /* original 3120, guest PC 0x0c08ae22 */
if(!s->budget--) { s->failed_pc=0x0c08ae22u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c08ae24;
P_0c08ae24: /* original 8b03, guest PC 0x0c08ae24 */
if(!s->budget--) { s->failed_pc=0x0c08ae24u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08ae2e; }
goto P_0c08ae26;
P_0c08ae26: /* original 53f3, guest PC 0x0c08ae26 */
if(!s->budget--) { s->failed_pc=0x0c08ae26u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c08ae28;
P_0c08ae28: /* original 6032, guest PC 0x0c08ae28 */
if(!s->budget--) { s->failed_pc=0x0c08ae28u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c08ae2a;
P_0c08ae2a: /* original cb02, guest PC 0x0c08ae2a */
if(!s->budget--) { s->failed_pc=0x0c08ae2au; return 0; }
r[0]|=2u;
goto P_0c08ae2c;
P_0c08ae2c: /* original 2302, guest PC 0x0c08ae2c */
if(!s->budget--) { s->failed_pc=0x0c08ae2cu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c08ae2e;
P_0c08ae2e: /* original 62f2, guest PC 0x0c08ae2e */
if(!s->budget--) { s->failed_pc=0x0c08ae2eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c08ae30;
P_0c08ae30: /* original 9325, guest PC 0x0c08ae30 */
if(!s->budget--) { s->failed_pc=0x0c08ae30u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ae7eu,2);
goto P_0c08ae32;
P_0c08ae32: /* original 3233, guest PC 0x0c08ae32 */
if(!s->budget--) { s->failed_pc=0x0c08ae32u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c08ae34;
P_0c08ae34: /* original 8959, guest PC 0x0c08ae34 */
if(!s->budget--) { s->failed_pc=0x0c08ae34u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08aeea; }
goto P_0c08ae36;
P_0c08ae36: /* original c715, guest PC 0x0c08ae36 */
if(!s->budget--) { s->failed_pc=0x0c08ae36u; return 0; }
r[0]=code_base|0x0008ae8cu;
goto P_0c08ae38;
P_0c08ae38: /* original f0cc, guest PC 0x0c08ae38 */
if(!s->budget--) { s->failed_pc=0x0c08ae38u; return 0; }
vf3_matrix_move(s,0,12);
goto P_0c08ae3a;
P_0c08ae3a: /* original f408, guest PC 0x0c08ae3a */
if(!s->budget--) { s->failed_pc=0x0c08ae3au; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c08ae3c;
P_0c08ae3c: /* original c714, guest PC 0x0c08ae3c */
if(!s->budget--) { s->failed_pc=0x0c08ae3cu; return 0; }
r[0]=code_base|0x0008ae90u;
goto P_0c08ae3e;
P_0c08ae3e: /* original f508, guest PC 0x0c08ae3e */
if(!s->budget--) { s->failed_pc=0x0c08ae3eu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c08ae40;
P_0c08ae40: /* original e03c, guest PC 0x0c08ae40 */
if(!s->budget--) { s->failed_pc=0x0c08ae40u; return 0; }
r[0]=0x0000003cu;
goto P_0c08ae42;
P_0c08ae42: /* original f45e, guest PC 0x0c08ae42 */
if(!s->budget--) { s->failed_pc=0x0c08ae42u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[5],fr[4],r[18]);
goto P_0c08ae44;
P_0c08ae44: /* original fd4c, guest PC 0x0c08ae44 */
if(!s->budget--) { s->failed_pc=0x0c08ae44u; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c08ae46;
P_0c08ae46: /* original f8d7, guest PC 0x0c08ae46 */
if(!s->budget--) { s->failed_pc=0x0c08ae46u; return 0; }
vf3_matrix_store(s,ram,13,r[8]+r[0]);
goto P_0c08ae48;
P_0c08ae48: /* original c712, guest PC 0x0c08ae48 */
if(!s->budget--) { s->failed_pc=0x0c08ae48u; return 0; }
r[0]=code_base|0x0008ae94u;
goto P_0c08ae4a;
P_0c08ae4a: /* original fc08, guest PC 0x0c08ae4a */
if(!s->budget--) { s->failed_pc=0x0c08ae4au; return 0; }
vf3_matrix_load(s,ram,12,r[0]);
goto P_0c08ae4c;
P_0c08ae4c: /* original c712, guest PC 0x0c08ae4c */
if(!s->budget--) { s->failed_pc=0x0c08ae4cu; return 0; }
r[0]=code_base|0x0008ae98u;
goto P_0c08ae4e;
P_0c08ae4e: /* original f408, guest PC 0x0c08ae4e */
if(!s->budget--) { s->failed_pc=0x0c08ae4eu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c08ae50;
P_0c08ae50: /* original 5ec4, guest PC 0x0c08ae50 */
if(!s->budget--) { s->failed_pc=0x0c08ae50u; return 0; }
r[14]=read(ram,r[12]+16,4);
goto P_0c08ae52;
P_0c08ae52: /* original fd41, guest PC 0x0c08ae52 */
if(!s->budget--) { s->failed_pc=0x0c08ae52u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'-');
goto P_0c08ae54;
P_0c08ae54: /* original a045, guest PC 0x0c08ae54 */
if(!s->budget--) { s->failed_pc=0x0c08ae54u; return 0; }
r[3]=0x00000002u;
goto P_0c08aee2;
P_0c08ae56: /* original e302, guest PC 0x0c08ae56 */
if(!s->budget--) { s->failed_pc=0x0c08ae56u; return 0; }
r[3]=0x00000002u;
goto P_0c08ae58;
P_0c08ae58: /* original 900f, guest PC 0x0c08ae58 */
if(!s->budget--) { s->failed_pc=0x0c08ae58u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ae7au,2);
goto P_0c08ae5a;
P_0c08ae5a: /* original 09ec, guest PC 0x0c08ae5a */
if(!s->budget--) { s->failed_pc=0x0c08ae5au; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08ae5c;
P_0c08ae5c: /* original 9010, guest PC 0x0c08ae5c */
if(!s->budget--) { s->failed_pc=0x0c08ae5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ae80u,2);
goto P_0c08ae5e;
P_0c08ae5e: /* original 699c, guest PC 0x0c08ae5e */
if(!s->budget--) { s->failed_pc=0x0c08ae5eu; return 0; }
r[9]=r[9]&255u;
goto P_0c08ae60;
P_0c08ae60: /* original f5e6, guest PC 0x0c08ae60 */
if(!s->budget--) { s->failed_pc=0x0c08ae60u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08ae62;
P_0c08ae62: /* original 7008, guest PC 0x0c08ae62 */
if(!s->budget--) { s->failed_pc=0x0c08ae62u; return 0; }
r[0]+=0x00000008u;
goto P_0c08ae64;
P_0c08ae64: /* original f4e6, guest PC 0x0c08ae64 */
if(!s->budget--) { s->failed_pc=0x0c08ae64u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08ae66;
P_0c08ae66: /* original f5c5, guest PC 0x0c08ae66 */
if(!s->budget--) { s->failed_pc=0x0c08ae66u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[12]))!=0);
goto P_0c08ae68;
P_0c08ae68: /* original 8d02, guest PC 0x0c08ae68 */
if(!s->budget--) { s->failed_pc=0x0c08ae68u; return 0; }
cond=r[17]&1u;
fr[4]^=0x80000000u;
if(cond) { goto P_0c08ae70; }
goto P_0c08ae6c;
P_0c08ae6a: /* original f44d, guest PC 0x0c08ae6a */
if(!s->budget--) { s->failed_pc=0x0c08ae6au; return 0; }
fr[4]^=0x80000000u;
goto P_0c08ae6c;
P_0c08ae6c: /* original fd45, guest PC 0x0c08ae6c */
if(!s->budget--) { s->failed_pc=0x0c08ae6cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[4]))!=0);
goto P_0c08ae6e;
P_0c08ae6e: /* original 8b15, guest PC 0x0c08ae6e */
if(!s->budget--) { s->failed_pc=0x0c08ae6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08ae9c; }
goto P_0c08ae70;
P_0c08ae70: /* original a032, guest PC 0x0c08ae70 */
if(!s->budget--) { s->failed_pc=0x0c08ae70u; return 0; }
r[9]=0x00000000u;
goto P_0c08aed8;
P_0c08ae72: /* original e900, guest PC 0x0c08ae72 */
if(!s->budget--) { s->failed_pc=0x0c08ae72u; return 0; }
r[9]=0x00000000u;
if(!vf3_matrix_family(0x0c08ae74u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08ae74u; return 0; } return 1;
P_0c08ae9c: /* original 6293, guest PC 0x0c08ae9c */
if(!s->budget--) { s->failed_pc=0x0c08ae9cu; return 0; }
r[2]=r[9];
goto P_0c08ae9e;
P_0c08ae9e: /* original 22d8, guest PC 0x0c08ae9e */
if(!s->budget--) { s->failed_pc=0x0c08ae9eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c08aea0;
P_0c08aea0: /* original 8b1a, guest PC 0x0c08aea0 */
if(!s->budget--) { s->failed_pc=0x0c08aea0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08aed8; }
goto P_0c08aea2;
P_0c08aea2: /* original d247, guest PC 0x0c08aea2 */
if(!s->budget--) { s->failed_pc=0x0c08aea2u; return 0; }
r[2]=read(ram,0x0c08afc0u,4);
goto P_0c08aea4;
P_0c08aea4: /* original 69d3, guest PC 0x0c08aea4 */
if(!s->budget--) { s->failed_pc=0x0c08aea4u; return 0; }
r[9]=r[13];
goto P_0c08aea6;
P_0c08aea6: /* original 1e2d, guest PC 0x0c08aea6 */
if(!s->budget--) { s->failed_pc=0x0c08aea6u; return 0; }
write(ram,r[14]+52,r[2],4);
goto P_0c08aea8;
P_0c08aea8: /* original 9083, guest PC 0x0c08aea8 */
if(!s->budget--) { s->failed_pc=0x0c08aea8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08afb2u,2);
goto P_0c08aeaa;
P_0c08aeaa: /* original 81ef, guest PC 0x0c08aeaa */
if(!s->budget--) { s->failed_pc=0x0c08aeaau; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c08aeac;
P_0c08aeac: /* original 9082, guest PC 0x0c08aeac */
if(!s->budget--) { s->failed_pc=0x0c08aeacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08afb4u,2);
goto P_0c08aeae;
P_0c08aeae: /* original fee7, guest PC 0x0c08aeae */
if(!s->budget--) { s->failed_pc=0x0c08aeaeu; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c08aeb0;
P_0c08aeb0: /* original 7008, guest PC 0x0c08aeb0 */
if(!s->budget--) { s->failed_pc=0x0c08aeb0u; return 0; }
r[0]+=0x00000008u;
goto P_0c08aeb2;
P_0c08aeb2: /* original fef7, guest PC 0x0c08aeb2 */
if(!s->budget--) { s->failed_pc=0x0c08aeb2u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c08aeb4;
P_0c08aeb4: /* original 937f, guest PC 0x0c08aeb4 */
if(!s->budget--) { s->failed_pc=0x0c08aeb4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08afb6u,2);
goto P_0c08aeb6;
P_0c08aeb6: /* original 1f31, guest PC 0x0c08aeb6 */
if(!s->budget--) { s->failed_pc=0x0c08aeb6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c08aeb8;
P_0c08aeb8: /* original 4b0b, guest PC 0x0c08aeb8 */
if(!s->budget--) { s->failed_pc=0x0c08aeb8u; return 0; }
target=r[11];
r[16]=code_base|0x0c08aebcu;
r[4]=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08aebcu) { target=s->pc; goto dispatch; }
goto P_0c08aebc;
P_0c08aeba: /* original 6433, guest PC 0x0c08aeba */
if(!s->budget--) { s->failed_pc=0x0c08aebau; return 0; }
r[4]=r[3];
goto P_0c08aebc;
P_0c08aebc: /* original 4a0b, guest PC 0x0c08aebc */
if(!s->budget--) { s->failed_pc=0x0c08aebcu; return 0; }
target=r[10];
r[16]=code_base|0x0c08aec0u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08aec0u) { target=s->pc; goto dispatch; }
goto P_0c08aec0;
P_0c08aebe: /* original 54f1, guest PC 0x0c08aebe */
if(!s->budget--) { s->failed_pc=0x0c08aebeu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c08aec0;
P_0c08aec0: /* original 4b0b, guest PC 0x0c08aec0 */
if(!s->budget--) { s->failed_pc=0x0c08aec0u; return 0; }
target=r[11];
r[16]=code_base|0x0c08aec4u;
r[4]=0x0000006cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08aec4u) { target=s->pc; goto dispatch; }
goto P_0c08aec4;
P_0c08aec2: /* original e46c, guest PC 0x0c08aec2 */
if(!s->budget--) { s->failed_pc=0x0c08aec2u; return 0; }
r[4]=0x0000006cu;
goto P_0c08aec4;
P_0c08aec4: /* original 4a0b, guest PC 0x0c08aec4 */
if(!s->budget--) { s->failed_pc=0x0c08aec4u; return 0; }
target=r[10];
r[16]=code_base|0x0c08aec8u;
r[4]=0x0000006cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08aec8u) { target=s->pc; goto dispatch; }
goto P_0c08aec8;
P_0c08aec6: /* original e46c, guest PC 0x0c08aec6 */
if(!s->budget--) { s->failed_pc=0x0c08aec6u; return 0; }
r[4]=0x0000006cu;
goto P_0c08aec8;
P_0c08aec8: /* original e046, guest PC 0x0c08aec8 */
if(!s->budget--) { s->failed_pc=0x0c08aec8u; return 0; }
r[0]=0x00000046u;
goto P_0c08aeca;
P_0c08aeca: /* original 55c5, guest PC 0x0c08aeca */
if(!s->budget--) { s->failed_pc=0x0c08aecau; return 0; }
r[5]=read(ram,r[12]+20,4);
goto P_0c08aecc;
P_0c08aecc: /* original 06ed, guest PC 0x0c08aecc */
if(!s->budget--) { s->failed_pc=0x0c08aeccu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08aece;
P_0c08aece: /* original d33d, guest PC 0x0c08aece */
if(!s->budget--) { s->failed_pc=0x0c08aeceu; return 0; }
r[3]=read(ram,0x0c08afc4u,4);
goto P_0c08aed0;
P_0c08aed0: /* original 666d, guest PC 0x0c08aed0 */
if(!s->budget--) { s->failed_pc=0x0c08aed0u; return 0; }
r[6]=r[6]&65535u;
goto P_0c08aed2;
P_0c08aed2: /* original 76ff, guest PC 0x0c08aed2 */
if(!s->budget--) { s->failed_pc=0x0c08aed2u; return 0; }
r[6]+=0xffffffffu;
goto P_0c08aed4;
P_0c08aed4: /* original 430b, guest PC 0x0c08aed4 */
if(!s->budget--) { s->failed_pc=0x0c08aed4u; return 0; }
target=r[3];
r[16]=code_base|0x0c08aed8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08aed8u) { target=s->pc; goto dispatch; }
goto P_0c08aed8;
P_0c08aed6: /* original 64e3, guest PC 0x0c08aed6 */
if(!s->budget--) { s->failed_pc=0x0c08aed6u; return 0; }
r[4]=r[14];
goto P_0c08aed8;
P_0c08aed8: /* original 906e, guest PC 0x0c08aed8 */
if(!s->budget--) { s->failed_pc=0x0c08aed8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08afb8u,2);
goto P_0c08aeda;
P_0c08aeda: /* original 0e94, guest PC 0x0c08aeda */
if(!s->budget--) { s->failed_pc=0x0c08aedau; return 0; }
write(ram,r[14]+r[0],r[9],1);
goto P_0c08aedc;
P_0c08aedc: /* original 63f2, guest PC 0x0c08aedc */
if(!s->budget--) { s->failed_pc=0x0c08aedcu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08aede;
P_0c08aede: /* original 5ec5, guest PC 0x0c08aede */
if(!s->budget--) { s->failed_pc=0x0c08aedeu; return 0; }
r[14]=read(ram,r[12]+20,4);
goto P_0c08aee0;
P_0c08aee0: /* original 73ff, guest PC 0x0c08aee0 */
if(!s->budget--) { s->failed_pc=0x0c08aee0u; return 0; }
r[3]+=0xffffffffu;
goto P_0c08aee2;
P_0c08aee2: /* original 6233, guest PC 0x0c08aee2 */
if(!s->budget--) { s->failed_pc=0x0c08aee2u; return 0; }
r[2]=r[3];
goto P_0c08aee4;
P_0c08aee4: /* original 2228, guest PC 0x0c08aee4 */
if(!s->budget--) { s->failed_pc=0x0c08aee4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c08aee6;
P_0c08aee6: /* original 8fb7, guest PC 0x0c08aee6 */
if(!s->budget--) { s->failed_pc=0x0c08aee6u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c08ae58; }
goto P_0c08aeea;
P_0c08aee8: /* original 2f32, guest PC 0x0c08aee8 */
if(!s->budget--) { s->failed_pc=0x0c08aee8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08aeea;
P_0c08aeea: /* original d237, guest PC 0x0c08aeea */
if(!s->budget--) { s->failed_pc=0x0c08aeeau; return 0; }
r[2]=read(ram,0x0c08afc8u,4);
goto P_0c08aeec;
P_0c08aeec: /* original 6020, guest PC 0x0c08aeec */
if(!s->budget--) { s->failed_pc=0x0c08aeecu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c08aeee;
P_0c08aeee: /* original 600c, guest PC 0x0c08aeee */
if(!s->budget--) { s->failed_pc=0x0c08aeeeu; return 0; }
r[0]=r[0]&255u;
goto P_0c08aef0;
P_0c08aef0: /* original c810, guest PC 0x0c08aef0 */
if(!s->budget--) { s->failed_pc=0x0c08aef0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c08aef2;
P_0c08aef2: /* original 8b1f, guest PC 0x0c08aef2 */
if(!s->budget--) { s->failed_pc=0x0c08aef2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08af34; }
goto P_0c08aef4;
P_0c08aef4: /* original 8588, guest PC 0x0c08aef4 */
if(!s->budget--) { s->failed_pc=0x0c08aef4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+16,2);
goto P_0c08aef6;
P_0c08aef6: /* original 9360, guest PC 0x0c08aef6 */
if(!s->budget--) { s->failed_pc=0x0c08aef6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08afbau,2);
goto P_0c08aef8;
P_0c08aef8: /* original 6403, guest PC 0x0c08aef8 */
if(!s->budget--) { s->failed_pc=0x0c08aef8u; return 0; }
r[4]=r[0];
goto P_0c08aefa;
P_0c08aefa: /* original 55f3, guest PC 0x0c08aefa */
if(!s->budget--) { s->failed_pc=0x0c08aefau; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c08aefc;
P_0c08aefc: /* original 7401, guest PC 0x0c08aefc */
if(!s->budget--) { s->failed_pc=0x0c08aefcu; return 0; }
r[4]+=0x00000001u;
goto P_0c08aefe;
P_0c08aefe: /* original 3430, guest PC 0x0c08aefe */
if(!s->budget--) { s->failed_pc=0x0c08aefeu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c08af00;
P_0c08af00: /* original 8f02, guest PC 0x0c08af00 */
if(!s->budget--) { s->failed_pc=0x0c08af00u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!cond) { goto P_0c08af08; }
goto P_0c08af04;
P_0c08af02: /* original 6552, guest PC 0x0c08af02 */
if(!s->budget--) { s->failed_pc=0x0c08af02u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c08af04;
P_0c08af04: /* original e108, guest PC 0x0c08af04 */
if(!s->budget--) { s->failed_pc=0x0c08af04u; return 0; }
r[1]=0x00000008u;
goto P_0c08af06;
P_0c08af06: /* original 251b, guest PC 0x0c08af06 */
if(!s->budget--) { s->failed_pc=0x0c08af06u; return 0; }
r[5]|=r[1];
goto P_0c08af08;
P_0c08af08: /* original 9358, guest PC 0x0c08af08 */
if(!s->budget--) { s->failed_pc=0x0c08af08u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08afbcu,2);
goto P_0c08af0a;
P_0c08af0a: /* original 3433, guest PC 0x0c08af0a */
if(!s->budget--) { s->failed_pc=0x0c08af0au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c08af0c;
P_0c08af0c: /* original 8b02, guest PC 0x0c08af0c */
if(!s->budget--) { s->failed_pc=0x0c08af0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08af14; }
goto P_0c08af0e;
P_0c08af0e: /* original e104, guest PC 0x0c08af0e */
if(!s->budget--) { s->failed_pc=0x0c08af0eu; return 0; }
r[1]=0x00000004u;
goto P_0c08af10;
P_0c08af10: /* original 251b, guest PC 0x0c08af10 */
if(!s->budget--) { s->failed_pc=0x0c08af10u; return 0; }
r[5]|=r[1];
goto P_0c08af12;
P_0c08af12: /* original e400, guest PC 0x0c08af12 */
if(!s->budget--) { s->failed_pc=0x0c08af12u; return 0; }
r[4]=0x00000000u;
goto P_0c08af14;
P_0c08af14: /* original c72d, guest PC 0x0c08af14 */
if(!s->budget--) { s->failed_pc=0x0c08af14u; return 0; }
r[0]=code_base|0x0008afccu;
goto P_0c08af16;
P_0c08af16: /* original 53f3, guest PC 0x0c08af16 */
if(!s->budget--) { s->failed_pc=0x0c08af16u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c08af18;
P_0c08af18: /* original 2352, guest PC 0x0c08af18 */
if(!s->budget--) { s->failed_pc=0x0c08af18u; return 0; }
write(ram,r[3],r[5],4);
goto P_0c08af1a;
P_0c08af1a: /* original 445a, guest PC 0x0c08af1a */
if(!s->budget--) { s->failed_pc=0x0c08af1au; return 0; }
r[53]=r[4];
goto P_0c08af1c;
P_0c08af1c: /* original f508, guest PC 0x0c08af1c */
if(!s->budget--) { s->failed_pc=0x0c08af1cu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c08af1e;
P_0c08af1e: /* original c72c, guest PC 0x0c08af1e */
if(!s->budget--) { s->failed_pc=0x0c08af1eu; return 0; }
r[0]=code_base|0x0008afd0u;
goto P_0c08af20;
P_0c08af20: /* original f408, guest PC 0x0c08af20 */
if(!s->budget--) { s->failed_pc=0x0c08af20u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c08af22;
P_0c08af22: /* original e020, guest PC 0x0c08af22 */
if(!s->budget--) { s->failed_pc=0x0c08af22u; return 0; }
r[0]=0x00000020u;
goto P_0c08af24;
P_0c08af24: /* original f32d, guest PC 0x0c08af24 */
if(!s->budget--) { s->failed_pc=0x0c08af24u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c08af26;
P_0c08af26: /* original f03c, guest PC 0x0c08af26 */
if(!s->budget--) { s->failed_pc=0x0c08af26u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c08af28;
P_0c08af28: /* original f54e, guest PC 0x0c08af28 */
if(!s->budget--) { s->failed_pc=0x0c08af28u; return 0; }
fr[5]=vf3_fpu_mac(fr[0],fr[4],fr[5],r[18]);
goto P_0c08af2a;
P_0c08af2a: /* original f63c, guest PC 0x0c08af2a */
if(!s->budget--) { s->failed_pc=0x0c08af2au; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08af2c;
P_0c08af2c: /* original f45c, guest PC 0x0c08af2c */
if(!s->budget--) { s->failed_pc=0x0c08af2cu; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c08af2e;
P_0c08af2e: /* original f847, guest PC 0x0c08af2e */
if(!s->budget--) { s->failed_pc=0x0c08af2eu; return 0; }
vf3_matrix_store(s,ram,4,r[8]+r[0]);
goto P_0c08af30;
P_0c08af30: /* original 6043, guest PC 0x0c08af30 */
if(!s->budget--) { s->failed_pc=0x0c08af30u; return 0; }
r[0]=r[4];
goto P_0c08af32;
P_0c08af32: /* original 8188, guest PC 0x0c08af32 */
if(!s->budget--) { s->failed_pc=0x0c08af32u; return 0; }
write(ram,r[8]+16,r[0],2);
goto P_0c08af34;
P_0c08af34: /* original 7f14, guest PC 0x0c08af34 */
if(!s->budget--) { s->failed_pc=0x0c08af34u; return 0; }
r[15]+=0x00000014u;
goto P_0c08af36;
P_0c08af36: /* original 4f26, guest PC 0x0c08af36 */
if(!s->budget--) { s->failed_pc=0x0c08af36u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08af38;
P_0c08af38: /* original fcf9, guest PC 0x0c08af38 */
if(!s->budget--) { s->failed_pc=0x0c08af38u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08af3a;
P_0c08af3a: /* original fdf9, guest PC 0x0c08af3a */
if(!s->budget--) { s->failed_pc=0x0c08af3au; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08af3c;
P_0c08af3c: /* original fef9, guest PC 0x0c08af3c */
if(!s->budget--) { s->failed_pc=0x0c08af3cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08af3e;
P_0c08af3e: /* original fff9, guest PC 0x0c08af3e */
if(!s->budget--) { s->failed_pc=0x0c08af3eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08af40;
P_0c08af40: /* original 68f6, guest PC 0x0c08af40 */
if(!s->budget--) { s->failed_pc=0x0c08af40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08af42;
P_0c08af42: /* original 69f6, guest PC 0x0c08af42 */
if(!s->budget--) { s->failed_pc=0x0c08af42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08af44;
P_0c08af44: /* original 6af6, guest PC 0x0c08af44 */
if(!s->budget--) { s->failed_pc=0x0c08af44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08af46;
P_0c08af46: /* original 6bf6, guest PC 0x0c08af46 */
if(!s->budget--) { s->failed_pc=0x0c08af46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08af48;
P_0c08af48: /* original 6cf6, guest PC 0x0c08af48 */
if(!s->budget--) { s->failed_pc=0x0c08af48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08af4a;
P_0c08af4a: /* original 6df6, guest PC 0x0c08af4a */
if(!s->budget--) { s->failed_pc=0x0c08af4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08af4c;
P_0c08af4c: /* original 000b, guest PC 0x0c08af4c */
if(!s->budget--) { s->failed_pc=0x0c08af4cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08af4e: /* original 6ef6, guest PC 0x0c08af4e */
if(!s->budget--) { s->failed_pc=0x0c08af4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08af50u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08af50u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
