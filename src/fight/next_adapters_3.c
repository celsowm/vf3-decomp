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
int vf3_next_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0bd8f6u: goto P_0c0bd8f6;
case 0x0c0bd8f8u: goto P_0c0bd8f8;
case 0x0c0bd8fau: goto P_0c0bd8fa;
case 0x0c0bd8fcu: goto P_0c0bd8fc;
case 0x0c0bd8feu: goto P_0c0bd8fe;
case 0x0c0bd900u: goto P_0c0bd900;
case 0x0c0bd902u: goto P_0c0bd902;
case 0x0c0bd904u: goto P_0c0bd904;
case 0x0c0bd906u: goto P_0c0bd906;
case 0x0c0bd908u: goto P_0c0bd908;
case 0x0c0bd90au: goto P_0c0bd90a;
case 0x0c0bd90cu: goto P_0c0bd90c;
case 0x0c0bd90eu: goto P_0c0bd90e;
case 0x0c0bd910u: goto P_0c0bd910;
case 0x0c0bd912u: goto P_0c0bd912;
case 0x0c0bd914u: goto P_0c0bd914;
case 0x0c0bd916u: goto P_0c0bd916;
case 0x0c0bd918u: goto P_0c0bd918;
case 0x0c0bd91au: goto P_0c0bd91a;
case 0x0c0bd91cu: goto P_0c0bd91c;
case 0x0c0bd91eu: goto P_0c0bd91e;
case 0x0c0bd920u: goto P_0c0bd920;
case 0x0c0bd922u: goto P_0c0bd922;
case 0x0c0bd924u: goto P_0c0bd924;
case 0x0c0bd926u: goto P_0c0bd926;
case 0x0c0bd928u: goto P_0c0bd928;
case 0x0c0bd92au: goto P_0c0bd92a;
case 0x0c0bd92cu: goto P_0c0bd92c;
case 0x0c0bd92eu: goto P_0c0bd92e;
case 0x0c0bd930u: goto P_0c0bd930;
case 0x0c0bd932u: goto P_0c0bd932;
case 0x0c0bd934u: goto P_0c0bd934;
case 0x0c0bd936u: goto P_0c0bd936;
case 0x0c0bd938u: goto P_0c0bd938;
case 0x0c0bd93au: goto P_0c0bd93a;
case 0x0c0bd93cu: goto P_0c0bd93c;
case 0x0c0bd93eu: goto P_0c0bd93e;
case 0x0c0bd940u: goto P_0c0bd940;
case 0x0c0bd942u: goto P_0c0bd942;
case 0x0c0bd944u: goto P_0c0bd944;
case 0x0c0bd946u: goto P_0c0bd946;
case 0x0c0bd948u: goto P_0c0bd948;
case 0x0c0bd94au: goto P_0c0bd94a;
case 0x0c0bd94cu: goto P_0c0bd94c;
case 0x0c0bd94eu: goto P_0c0bd94e;
case 0x0c0bd950u: goto P_0c0bd950;
case 0x0c0bd952u: goto P_0c0bd952;
case 0x0c0bd954u: goto P_0c0bd954;
case 0x0c0bd956u: goto P_0c0bd956;
case 0x0c0bd958u: goto P_0c0bd958;
case 0x0c0bd95au: goto P_0c0bd95a;
case 0x0c0bd95cu: goto P_0c0bd95c;
case 0x0c0bd95eu: goto P_0c0bd95e;
case 0x0c0bd960u: goto P_0c0bd960;
case 0x0c0bd962u: goto P_0c0bd962;
case 0x0c0bd964u: goto P_0c0bd964;
case 0x0c0bd966u: goto P_0c0bd966;
case 0x0c0bd968u: goto P_0c0bd968;
case 0x0c0bd96au: goto P_0c0bd96a;
case 0x0c0bd96cu: goto P_0c0bd96c;
case 0x0c0bd96eu: goto P_0c0bd96e;
case 0x0c0bd970u: goto P_0c0bd970;
case 0x0c0bd972u: goto P_0c0bd972;
case 0x0c0bd974u: goto P_0c0bd974;
case 0x0c0bd976u: goto P_0c0bd976;
case 0x0c0bd978u: goto P_0c0bd978;
case 0x0c0bd97au: goto P_0c0bd97a;
case 0x0c0bd97cu: goto P_0c0bd97c;
case 0x0c0bd97eu: goto P_0c0bd97e;
case 0x0c0bd980u: goto P_0c0bd980;
case 0x0c0bd982u: goto P_0c0bd982;
case 0x0c0bd984u: goto P_0c0bd984;
case 0x0c0bd986u: goto P_0c0bd986;
case 0x0c0bd988u: goto P_0c0bd988;
case 0x0c0bd98au: goto P_0c0bd98a;
case 0x0c0bd98cu: goto P_0c0bd98c;
case 0x0c0bd98eu: goto P_0c0bd98e;
case 0x0c0bd990u: goto P_0c0bd990;
case 0x0c0bd992u: goto P_0c0bd992;
case 0x0c0bd994u: goto P_0c0bd994;
case 0x0c0bd996u: goto P_0c0bd996;
case 0x0c0bd998u: goto P_0c0bd998;
case 0x0c0bd99au: goto P_0c0bd99a;
case 0x0c0bd99cu: goto P_0c0bd99c;
case 0x0c0bd99eu: goto P_0c0bd99e;
case 0x0c0bd9a0u: goto P_0c0bd9a0;
case 0x0c0bd9a2u: goto P_0c0bd9a2;
case 0x0c0bd9a4u: goto P_0c0bd9a4;
case 0x0c0bd9a6u: goto P_0c0bd9a6;
case 0x0c0bd9a8u: goto P_0c0bd9a8;
case 0x0c0bd9aau: goto P_0c0bd9aa;
case 0x0c0bd9acu: goto P_0c0bd9ac;
case 0x0c0bd9aeu: goto P_0c0bd9ae;
case 0x0c0bd9b0u: goto P_0c0bd9b0;
case 0x0c0bd9b2u: goto P_0c0bd9b2;
case 0x0c0bd9b4u: goto P_0c0bd9b4;
case 0x0c0bd9b6u: goto P_0c0bd9b6;
case 0x0c0bd9b8u: goto P_0c0bd9b8;
case 0x0c0bd9bau: goto P_0c0bd9ba;
case 0x0c0bd9bcu: goto P_0c0bd9bc;
case 0x0c0bd9beu: goto P_0c0bd9be;
case 0x0c0bd9c0u: goto P_0c0bd9c0;
case 0x0c0bd9c2u: goto P_0c0bd9c2;
case 0x0c0bd9c4u: goto P_0c0bd9c4;
case 0x0c0bd9c6u: goto P_0c0bd9c6;
case 0x0c0bd9c8u: goto P_0c0bd9c8;
case 0x0c0bd9cau: goto P_0c0bd9ca;
case 0x0c0bd9ccu: goto P_0c0bd9cc;
case 0x0c0bd9ceu: goto P_0c0bd9ce;
case 0x0c0bd9d0u: goto P_0c0bd9d0;
case 0x0c0bd9d2u: goto P_0c0bd9d2;
case 0x0c0bd9d4u: goto P_0c0bd9d4;
case 0x0c0bd9d6u: goto P_0c0bd9d6;
case 0x0c0bd9d8u: goto P_0c0bd9d8;
case 0x0c0bd9dau: goto P_0c0bd9da;
case 0x0c0bd9dcu: goto P_0c0bd9dc;
case 0x0c0bd9deu: goto P_0c0bd9de;
case 0x0c0bd9e0u: goto P_0c0bd9e0;
case 0x0c0bd9e2u: goto P_0c0bd9e2;
case 0x0c0bd9e4u: goto P_0c0bd9e4;
case 0x0c0bd9e6u: goto P_0c0bd9e6;
case 0x0c0bd9e8u: goto P_0c0bd9e8;
case 0x0c0bd9eau: goto P_0c0bd9ea;
case 0x0c0bd9ecu: goto P_0c0bd9ec;
case 0x0c0bd9eeu: goto P_0c0bd9ee;
case 0x0c0bd9f0u: goto P_0c0bd9f0;
case 0x0c0bd9f2u: goto P_0c0bd9f2;
case 0x0c0bd9f4u: goto P_0c0bd9f4;
case 0x0c0bd9f6u: goto P_0c0bd9f6;
case 0x0c0bd9f8u: goto P_0c0bd9f8;
case 0x0c0bd9fau: goto P_0c0bd9fa;
case 0x0c0bd9fcu: goto P_0c0bd9fc;
case 0x0c0bd9feu: goto P_0c0bd9fe;
case 0x0c0bda00u: goto P_0c0bda00;
case 0x0c0bda02u: goto P_0c0bda02;
case 0x0c0bda04u: goto P_0c0bda04;
case 0x0c0bda06u: goto P_0c0bda06;
case 0x0c0bda08u: goto P_0c0bda08;
case 0x0c0bda0au: goto P_0c0bda0a;
case 0x0c0bda0cu: goto P_0c0bda0c;
case 0x0c0bda0eu: goto P_0c0bda0e;
case 0x0c0bda10u: goto P_0c0bda10;
case 0x0c0bda12u: goto P_0c0bda12;
case 0x0c0bda14u: goto P_0c0bda14;
case 0x0c0bda16u: goto P_0c0bda16;
case 0x0c0bda18u: goto P_0c0bda18;
case 0x0c0bda1au: goto P_0c0bda1a;
case 0x0c0bda1cu: goto P_0c0bda1c;
case 0x0c0bda1eu: goto P_0c0bda1e;
case 0x0c0bda20u: goto P_0c0bda20;
case 0x0c0bda22u: goto P_0c0bda22;
case 0x0c0bda24u: goto P_0c0bda24;
case 0x0c0bda26u: goto P_0c0bda26;
case 0x0c0bda28u: goto P_0c0bda28;
case 0x0c0bda2au: goto P_0c0bda2a;
case 0x0c0bda2cu: goto P_0c0bda2c;
case 0x0c0bda2eu: goto P_0c0bda2e;
case 0x0c0bda30u: goto P_0c0bda30;
case 0x0c0bda32u: goto P_0c0bda32;
case 0x0c0bda34u: goto P_0c0bda34;
case 0x0c0bda36u: goto P_0c0bda36;
case 0x0c0bda38u: goto P_0c0bda38;
case 0x0c0bda3au: goto P_0c0bda3a;
case 0x0c0bda3cu: goto P_0c0bda3c;
case 0x0c0bda3eu: goto P_0c0bda3e;
case 0x0c0bda40u: goto P_0c0bda40;
case 0x0c0bda42u: goto P_0c0bda42;
case 0x0c0bda44u: goto P_0c0bda44;
case 0x0c0bda46u: goto P_0c0bda46;
case 0x0c0bda48u: goto P_0c0bda48;
case 0x0c0bda4au: goto P_0c0bda4a;
case 0x0c0bda4cu: goto P_0c0bda4c;
case 0x0c0bda4eu: goto P_0c0bda4e;
case 0x0c0bdac8u: goto P_0c0bdac8;
case 0x0c0bdacau: goto P_0c0bdaca;
case 0x0c0bdaccu: goto P_0c0bdacc;
case 0x0c0bdaceu: goto P_0c0bdace;
case 0x0c0bdad0u: goto P_0c0bdad0;
case 0x0c0bdad2u: goto P_0c0bdad2;
case 0x0c0bdad4u: goto P_0c0bdad4;
case 0x0c0bdad6u: goto P_0c0bdad6;
case 0x0c0bdad8u: goto P_0c0bdad8;
case 0x0c0bdadau: goto P_0c0bdada;
case 0x0c0bdadcu: goto P_0c0bdadc;
case 0x0c0bdadeu: goto P_0c0bdade;
case 0x0c0bdae0u: goto P_0c0bdae0;
case 0x0c0bdae2u: goto P_0c0bdae2;
case 0x0c0bdae4u: goto P_0c0bdae4;
case 0x0c0bdae6u: goto P_0c0bdae6;
case 0x0c0bdae8u: goto P_0c0bdae8;
case 0x0c0bdaeau: goto P_0c0bdaea;
case 0x0c0bdaecu: goto P_0c0bdaec;
case 0x0c0bdaeeu: goto P_0c0bdaee;
case 0x0c0bdaf0u: goto P_0c0bdaf0;
case 0x0c0bdaf2u: goto P_0c0bdaf2;
case 0x0c0bdaf4u: goto P_0c0bdaf4;
case 0x0c0bdaf6u: goto P_0c0bdaf6;
case 0x0c0bdaf8u: goto P_0c0bdaf8;
case 0x0c0bdafau: goto P_0c0bdafa;
case 0x0c0bdafcu: goto P_0c0bdafc;
case 0x0c0bdafeu: goto P_0c0bdafe;
case 0x0c0bdb00u: goto P_0c0bdb00;
case 0x0c0bdb02u: goto P_0c0bdb02;
case 0x0c0bdb04u: goto P_0c0bdb04;
case 0x0c0bdb06u: goto P_0c0bdb06;
case 0x0c0bdb08u: goto P_0c0bdb08;
case 0x0c0bdb0au: goto P_0c0bdb0a;
case 0x0c0bdb0cu: goto P_0c0bdb0c;
case 0x0c0bdb0eu: goto P_0c0bdb0e;
case 0x0c0bdb10u: goto P_0c0bdb10;
case 0x0c0bdb12u: goto P_0c0bdb12;
case 0x0c0bdb14u: goto P_0c0bdb14;
case 0x0c0bdb16u: goto P_0c0bdb16;
case 0x0c0bdb18u: goto P_0c0bdb18;
case 0x0c0bdb1au: goto P_0c0bdb1a;
case 0x0c0bdb1cu: goto P_0c0bdb1c;
case 0x0c0bdb1eu: goto P_0c0bdb1e;
case 0x0c0bdb20u: goto P_0c0bdb20;
case 0x0c0bdb22u: goto P_0c0bdb22;
case 0x0c0bdb24u: goto P_0c0bdb24;
case 0x0c0bdb26u: goto P_0c0bdb26;
case 0x0c0bdb28u: goto P_0c0bdb28;
case 0x0c0bdb2au: goto P_0c0bdb2a;
case 0x0c0bdb2cu: goto P_0c0bdb2c;
case 0x0c0bdb2eu: goto P_0c0bdb2e;
case 0x0c0bdb30u: goto P_0c0bdb30;
case 0x0c0bdb32u: goto P_0c0bdb32;
case 0x0c0bdb34u: goto P_0c0bdb34;
case 0x0c0bdb36u: goto P_0c0bdb36;
case 0x0c0bdb38u: goto P_0c0bdb38;
case 0x0c0bdb3au: goto P_0c0bdb3a;
case 0x0c0bdb3cu: goto P_0c0bdb3c;
case 0x0c0bdb3eu: goto P_0c0bdb3e;
case 0x0c0bdb40u: goto P_0c0bdb40;
case 0x0c0bdb42u: goto P_0c0bdb42;
case 0x0c0bdb44u: goto P_0c0bdb44;
case 0x0c0bdb46u: goto P_0c0bdb46;
case 0x0c0bdb48u: goto P_0c0bdb48;
case 0x0c0bdb4au: goto P_0c0bdb4a;
case 0x0c0bdb4cu: goto P_0c0bdb4c;
case 0x0c0bdb4eu: goto P_0c0bdb4e;
case 0x0c0bdb50u: goto P_0c0bdb50;
case 0x0c0bdb52u: goto P_0c0bdb52;
case 0x0c0bdb54u: goto P_0c0bdb54;
case 0x0c0bdb56u: goto P_0c0bdb56;
case 0x0c0bdb58u: goto P_0c0bdb58;
case 0x0c0bdb5au: goto P_0c0bdb5a;
case 0x0c0bdb5cu: goto P_0c0bdb5c;
case 0x0c0bdb5eu: goto P_0c0bdb5e;
case 0x0c0bdb60u: goto P_0c0bdb60;
case 0x0c0bdb62u: goto P_0c0bdb62;
case 0x0c0bdb64u: goto P_0c0bdb64;
case 0x0c0bdb66u: goto P_0c0bdb66;
case 0x0c0bdb68u: goto P_0c0bdb68;
case 0x0c0bdb6au: goto P_0c0bdb6a;
case 0x0c0bdb6cu: goto P_0c0bdb6c;
case 0x0c0bdb6eu: goto P_0c0bdb6e;
case 0x0c0bdb70u: goto P_0c0bdb70;
case 0x0c0bdb72u: goto P_0c0bdb72;
case 0x0c0bdb74u: goto P_0c0bdb74;
case 0x0c0bdb76u: goto P_0c0bdb76;
case 0x0c0bdb78u: goto P_0c0bdb78;
case 0x0c0bdb7au: goto P_0c0bdb7a;
case 0x0c0bdb7cu: goto P_0c0bdb7c;
case 0x0c0bdb7eu: goto P_0c0bdb7e;
case 0x0c0bdb80u: goto P_0c0bdb80;
case 0x0c0bdb82u: goto P_0c0bdb82;
case 0x0c0bdb84u: goto P_0c0bdb84;
case 0x0c0bdb86u: goto P_0c0bdb86;
case 0x0c0bdb88u: goto P_0c0bdb88;
case 0x0c0bdb8au: goto P_0c0bdb8a;
case 0x0c0bdb8cu: goto P_0c0bdb8c;
case 0x0c0bdb8eu: goto P_0c0bdb8e;
case 0x0c0bdb90u: goto P_0c0bdb90;
case 0x0c0bdb92u: goto P_0c0bdb92;
case 0x0c0bdb94u: goto P_0c0bdb94;
case 0x0c0bdb96u: goto P_0c0bdb96;
case 0x0c0bdb98u: goto P_0c0bdb98;
case 0x0c0bdb9au: goto P_0c0bdb9a;
case 0x0c0bdb9cu: goto P_0c0bdb9c;
case 0x0c0bdb9eu: goto P_0c0bdb9e;
case 0x0c0bdba0u: goto P_0c0bdba0;
case 0x0c0bdba2u: goto P_0c0bdba2;
case 0x0c0bdba4u: goto P_0c0bdba4;
case 0x0c0bdba6u: goto P_0c0bdba6;
case 0x0c0bdba8u: goto P_0c0bdba8;
case 0x0c0bdbaau: goto P_0c0bdbaa;
case 0x0c0bdbacu: goto P_0c0bdbac;
case 0x0c0bdbaeu: goto P_0c0bdbae;
case 0x0c0bdbb0u: goto P_0c0bdbb0;
case 0x0c0bdbb2u: goto P_0c0bdbb2;
case 0x0c0bdbb4u: goto P_0c0bdbb4;
case 0x0c0bdbb6u: goto P_0c0bdbb6;
case 0x0c0bdbb8u: goto P_0c0bdbb8;
case 0x0c0bdbbau: goto P_0c0bdbba;
case 0x0c0bdbbcu: goto P_0c0bdbbc;
case 0x0c0bdbbeu: goto P_0c0bdbbe;
case 0x0c0bdbc0u: goto P_0c0bdbc0;
case 0x0c0bdbc2u: goto P_0c0bdbc2;
case 0x0c0bdbc4u: goto P_0c0bdbc4;
case 0x0c0bdbc6u: goto P_0c0bdbc6;
case 0x0c0bdbc8u: goto P_0c0bdbc8;
case 0x0c0bdbcau: goto P_0c0bdbca;
case 0x0c0bdbccu: goto P_0c0bdbcc;
case 0x0c0bdbceu: goto P_0c0bdbce;
case 0x0c0bdbd0u: goto P_0c0bdbd0;
case 0x0c0bdbd2u: goto P_0c0bdbd2;
case 0x0c0bdbd4u: goto P_0c0bdbd4;
case 0x0c0bdbd6u: goto P_0c0bdbd6;
case 0x0c0bdbd8u: goto P_0c0bdbd8;
case 0x0c0be05eu: goto P_0c0be05e;
case 0x0c0be060u: goto P_0c0be060;
case 0x0c0be062u: goto P_0c0be062;
case 0x0c0be064u: goto P_0c0be064;
case 0x0c0be066u: goto P_0c0be066;
case 0x0c0be068u: goto P_0c0be068;
case 0x0c0be06au: goto P_0c0be06a;
case 0x0c0be06cu: goto P_0c0be06c;
case 0x0c0be06eu: goto P_0c0be06e;
case 0x0c0be070u: goto P_0c0be070;
case 0x0c0be072u: goto P_0c0be072;
case 0x0c0be074u: goto P_0c0be074;
case 0x0c0be076u: goto P_0c0be076;
case 0x0c0be078u: goto P_0c0be078;
case 0x0c0be07au: goto P_0c0be07a;
case 0x0c0be07cu: goto P_0c0be07c;
case 0x0c0be07eu: goto P_0c0be07e;
case 0x0c0be080u: goto P_0c0be080;
case 0x0c0be082u: goto P_0c0be082;
case 0x0c0be084u: goto P_0c0be084;
case 0x0c0be086u: goto P_0c0be086;
case 0x0c0be088u: goto P_0c0be088;
case 0x0c0be08au: goto P_0c0be08a;
case 0x0c0be08cu: goto P_0c0be08c;
case 0x0c0be08eu: goto P_0c0be08e;
case 0x0c0be090u: goto P_0c0be090;
case 0x0c0be092u: goto P_0c0be092;
case 0x0c0be094u: goto P_0c0be094;
case 0x0c0be096u: goto P_0c0be096;
case 0x0c0be098u: goto P_0c0be098;
case 0x0c0be09au: goto P_0c0be09a;
case 0x0c0be09cu: goto P_0c0be09c;
case 0x0c0be09eu: goto P_0c0be09e;
case 0x0c0be0a0u: goto P_0c0be0a0;
case 0x0c0be0a2u: goto P_0c0be0a2;
case 0x0c0be0a4u: goto P_0c0be0a4;
case 0x0c0be0a6u: goto P_0c0be0a6;
case 0x0c0be0a8u: goto P_0c0be0a8;
case 0x0c0be0aau: goto P_0c0be0aa;
case 0x0c0be0acu: goto P_0c0be0ac;
case 0x0c0be0aeu: goto P_0c0be0ae;
case 0x0c0be0b0u: goto P_0c0be0b0;
case 0x0c0be0b2u: goto P_0c0be0b2;
case 0x0c0be0b4u: goto P_0c0be0b4;
case 0x0c0be0b6u: goto P_0c0be0b6;
case 0x0c0be0b8u: goto P_0c0be0b8;
case 0x0c0be0bau: goto P_0c0be0ba;
case 0x0c0be0bcu: goto P_0c0be0bc;
case 0x0c0be0beu: goto P_0c0be0be;
case 0x0c0be0c0u: goto P_0c0be0c0;
case 0x0c0be0c2u: goto P_0c0be0c2;
case 0x0c0be0c4u: goto P_0c0be0c4;
case 0x0c0be0c6u: goto P_0c0be0c6;
case 0x0c0be0c8u: goto P_0c0be0c8;
case 0x0c0be0cau: goto P_0c0be0ca;
case 0x0c0be0ccu: goto P_0c0be0cc;
case 0x0c0be0ceu: goto P_0c0be0ce;
case 0x0c0be0d0u: goto P_0c0be0d0;
case 0x0c0be0d2u: goto P_0c0be0d2;
case 0x0c0be0d4u: goto P_0c0be0d4;
case 0x0c0be0d6u: goto P_0c0be0d6;
case 0x0c0be0d8u: goto P_0c0be0d8;
case 0x0c0be0dau: goto P_0c0be0da;
case 0x0c0be0dcu: goto P_0c0be0dc;
case 0x0c0be0deu: goto P_0c0be0de;
case 0x0c0be0e0u: goto P_0c0be0e0;
case 0x0c0be0e2u: goto P_0c0be0e2;
case 0x0c0be0e4u: goto P_0c0be0e4;
case 0x0c0be0e6u: goto P_0c0be0e6;
case 0x0c0be0e8u: goto P_0c0be0e8;
case 0x0c0be0eau: goto P_0c0be0ea;
case 0x0c0be0ecu: goto P_0c0be0ec;
case 0x0c0be0eeu: goto P_0c0be0ee;
case 0x0c0be0f0u: goto P_0c0be0f0;
case 0x0c0be0f2u: goto P_0c0be0f2;
case 0x0c0be0f4u: goto P_0c0be0f4;
case 0x0c0be0f6u: goto P_0c0be0f6;
case 0x0c0be0f8u: goto P_0c0be0f8;
case 0x0c0be0fau: goto P_0c0be0fa;
case 0x0c0be0fcu: goto P_0c0be0fc;
case 0x0c0be0feu: goto P_0c0be0fe;
case 0x0c0be100u: goto P_0c0be100;
case 0x0c0be102u: goto P_0c0be102;
case 0x0c0be104u: goto P_0c0be104;
case 0x0c0be106u: goto P_0c0be106;
case 0x0c0be108u: goto P_0c0be108;
case 0x0c0be10au: goto P_0c0be10a;
case 0x0c0be10cu: goto P_0c0be10c;
case 0x0c0be10eu: goto P_0c0be10e;
case 0x0c0be110u: goto P_0c0be110;
case 0x0c0be112u: goto P_0c0be112;
case 0x0c0be114u: goto P_0c0be114;
case 0x0c0be116u: goto P_0c0be116;
case 0x0c0be118u: goto P_0c0be118;
case 0x0c0be11au: goto P_0c0be11a;
case 0x0c0be11cu: goto P_0c0be11c;
case 0x0c0be11eu: goto P_0c0be11e;
case 0x0c0be120u: goto P_0c0be120;
case 0x0c0be122u: goto P_0c0be122;
case 0x0c0be124u: goto P_0c0be124;
case 0x0c0be126u: goto P_0c0be126;
case 0x0c0be128u: goto P_0c0be128;
case 0x0c0be12au: goto P_0c0be12a;
case 0x0c0be12cu: goto P_0c0be12c;
case 0x0c0be12eu: goto P_0c0be12e;
case 0x0c0be130u: goto P_0c0be130;
case 0x0c0be132u: goto P_0c0be132;
case 0x0c0be134u: goto P_0c0be134;
case 0x0c0be136u: goto P_0c0be136;
case 0x0c0be138u: goto P_0c0be138;
case 0x0c0be13au: goto P_0c0be13a;
case 0x0c0be13cu: goto P_0c0be13c;
case 0x0c0be13eu: goto P_0c0be13e;
case 0x0c0be140u: goto P_0c0be140;
case 0x0c0be142u: goto P_0c0be142;
case 0x0c0be144u: goto P_0c0be144;
case 0x0c0be146u: goto P_0c0be146;
case 0x0c0be148u: goto P_0c0be148;
case 0x0c0be14au: goto P_0c0be14a;
case 0x0c0be14cu: goto P_0c0be14c;
case 0x0c0be14eu: goto P_0c0be14e;
case 0x0c0be150u: goto P_0c0be150;
case 0x0c0be152u: goto P_0c0be152;
case 0x0c0be154u: goto P_0c0be154;
case 0x0c0be156u: goto P_0c0be156;
case 0x0c0be158u: goto P_0c0be158;
case 0x0c0be15au: goto P_0c0be15a;
case 0x0c0be15cu: goto P_0c0be15c;
case 0x0c0be15eu: goto P_0c0be15e;
case 0x0c0be160u: goto P_0c0be160;
case 0x0c0be162u: goto P_0c0be162;
case 0x0c0be164u: goto P_0c0be164;
case 0x0c0be166u: goto P_0c0be166;
case 0x0c0be168u: goto P_0c0be168;
case 0x0c0be16au: goto P_0c0be16a;
case 0x0c0be16cu: goto P_0c0be16c;
case 0x0c0be16eu: goto P_0c0be16e;
case 0x0c0be170u: goto P_0c0be170;
case 0x0c0be172u: goto P_0c0be172;
case 0x0c0be174u: goto P_0c0be174;
case 0x0c0be176u: goto P_0c0be176;
case 0x0c0be178u: goto P_0c0be178;
case 0x0c0be17au: goto P_0c0be17a;
case 0x0c0be17cu: goto P_0c0be17c;
case 0x0c0be17eu: goto P_0c0be17e;
case 0x0c0be180u: goto P_0c0be180;
case 0x0c0be182u: goto P_0c0be182;
case 0x0c0be184u: goto P_0c0be184;
case 0x0c0be186u: goto P_0c0be186;
case 0x0c0be188u: goto P_0c0be188;
case 0x0c0be18au: goto P_0c0be18a;
case 0x0c0be18cu: goto P_0c0be18c;
case 0x0c0be18eu: goto P_0c0be18e;
case 0x0c0be190u: goto P_0c0be190;
case 0x0c0be192u: goto P_0c0be192;
case 0x0c0be194u: goto P_0c0be194;
case 0x0c0be196u: goto P_0c0be196;
case 0x0c0be198u: goto P_0c0be198;
case 0x0c0be19au: goto P_0c0be19a;
case 0x0c0be19cu: goto P_0c0be19c;
case 0x0c0be19eu: goto P_0c0be19e;
case 0x0c0be1a0u: goto P_0c0be1a0;
case 0x0c0be1a2u: goto P_0c0be1a2;
case 0x0c0be1a4u: goto P_0c0be1a4;
case 0x0c0be1a6u: goto P_0c0be1a6;
case 0x0c0be1a8u: goto P_0c0be1a8;
case 0x0c0be1aau: goto P_0c0be1aa;
case 0x0c0be1acu: goto P_0c0be1ac;
case 0x0c0be1aeu: goto P_0c0be1ae;
case 0x0c0be1b0u: goto P_0c0be1b0;
case 0x0c0be1b2u: goto P_0c0be1b2;
case 0x0c0be1b4u: goto P_0c0be1b4;
case 0x0c0be1b6u: goto P_0c0be1b6;
case 0x0c0be230u: goto P_0c0be230;
case 0x0c0be232u: goto P_0c0be232;
case 0x0c0be234u: goto P_0c0be234;
case 0x0c0be236u: goto P_0c0be236;
case 0x0c0be238u: goto P_0c0be238;
case 0x0c0be23au: goto P_0c0be23a;
case 0x0c0be23cu: goto P_0c0be23c;
case 0x0c0be23eu: goto P_0c0be23e;
case 0x0c0be240u: goto P_0c0be240;
case 0x0c0be242u: goto P_0c0be242;
case 0x0c0be244u: goto P_0c0be244;
case 0x0c0be246u: goto P_0c0be246;
case 0x0c0be248u: goto P_0c0be248;
case 0x0c0be24au: goto P_0c0be24a;
case 0x0c0be24cu: goto P_0c0be24c;
case 0x0c0be24eu: goto P_0c0be24e;
case 0x0c0be250u: goto P_0c0be250;
case 0x0c0be252u: goto P_0c0be252;
case 0x0c0be254u: goto P_0c0be254;
case 0x0c0be256u: goto P_0c0be256;
case 0x0c0be258u: goto P_0c0be258;
case 0x0c0be25au: goto P_0c0be25a;
case 0x0c0be25cu: goto P_0c0be25c;
case 0x0c0be25eu: goto P_0c0be25e;
case 0x0c0be260u: goto P_0c0be260;
case 0x0c0be262u: goto P_0c0be262;
case 0x0c0be264u: goto P_0c0be264;
case 0x0c0be266u: goto P_0c0be266;
case 0x0c0be268u: goto P_0c0be268;
case 0x0c0be26au: goto P_0c0be26a;
case 0x0c0be26cu: goto P_0c0be26c;
case 0x0c0be26eu: goto P_0c0be26e;
case 0x0c0be270u: goto P_0c0be270;
case 0x0c0be272u: goto P_0c0be272;
case 0x0c0be274u: goto P_0c0be274;
case 0x0c0be276u: goto P_0c0be276;
case 0x0c0be278u: goto P_0c0be278;
case 0x0c0be27au: goto P_0c0be27a;
case 0x0c0be27cu: goto P_0c0be27c;
case 0x0c0be27eu: goto P_0c0be27e;
case 0x0c0be280u: goto P_0c0be280;
case 0x0c0be282u: goto P_0c0be282;
case 0x0c0be284u: goto P_0c0be284;
case 0x0c0be286u: goto P_0c0be286;
case 0x0c0be288u: goto P_0c0be288;
case 0x0c0be28au: goto P_0c0be28a;
case 0x0c0be28cu: goto P_0c0be28c;
case 0x0c0be28eu: goto P_0c0be28e;
case 0x0c0be290u: goto P_0c0be290;
case 0x0c0be292u: goto P_0c0be292;
case 0x0c0be294u: goto P_0c0be294;
case 0x0c0be296u: goto P_0c0be296;
case 0x0c0be298u: goto P_0c0be298;
case 0x0c0be29au: goto P_0c0be29a;
case 0x0c0be29cu: goto P_0c0be29c;
case 0x0c0be29eu: goto P_0c0be29e;
case 0x0c0be2a0u: goto P_0c0be2a0;
case 0x0c0be2a2u: goto P_0c0be2a2;
case 0x0c0be2a4u: goto P_0c0be2a4;
case 0x0c0be2a6u: goto P_0c0be2a6;
case 0x0c0be2a8u: goto P_0c0be2a8;
case 0x0c0be2aau: goto P_0c0be2aa;
case 0x0c0be2acu: goto P_0c0be2ac;
case 0x0c0be2aeu: goto P_0c0be2ae;
case 0x0c0be2b0u: goto P_0c0be2b0;
case 0x0c0be2b2u: goto P_0c0be2b2;
case 0x0c0be2b4u: goto P_0c0be2b4;
case 0x0c0be2b6u: goto P_0c0be2b6;
case 0x0c0be2b8u: goto P_0c0be2b8;
case 0x0c0be2bau: goto P_0c0be2ba;
case 0x0c0be2bcu: goto P_0c0be2bc;
case 0x0c0be2beu: goto P_0c0be2be;
case 0x0c0be2c0u: goto P_0c0be2c0;
case 0x0c0be2c2u: goto P_0c0be2c2;
case 0x0c0be2c4u: goto P_0c0be2c4;
case 0x0c0be2c6u: goto P_0c0be2c6;
case 0x0c0be2c8u: goto P_0c0be2c8;
case 0x0c0be2cau: goto P_0c0be2ca;
case 0x0c0be2ccu: goto P_0c0be2cc;
case 0x0c0be2ceu: goto P_0c0be2ce;
case 0x0c0be2d0u: goto P_0c0be2d0;
case 0x0c0be2d2u: goto P_0c0be2d2;
case 0x0c0be2d4u: goto P_0c0be2d4;
case 0x0c0be2d6u: goto P_0c0be2d6;
case 0x0c0be2d8u: goto P_0c0be2d8;
case 0x0c0be2dau: goto P_0c0be2da;
case 0x0c0be2dcu: goto P_0c0be2dc;
case 0x0c0be2deu: goto P_0c0be2de;
case 0x0c0be2e0u: goto P_0c0be2e0;
case 0x0c0be2e2u: goto P_0c0be2e2;
case 0x0c0be2e4u: goto P_0c0be2e4;
case 0x0c0be2e6u: goto P_0c0be2e6;
case 0x0c0be2e8u: goto P_0c0be2e8;
case 0x0c0be2eau: goto P_0c0be2ea;
case 0x0c0be2ecu: goto P_0c0be2ec;
case 0x0c0be2eeu: goto P_0c0be2ee;
case 0x0c0be2f0u: goto P_0c0be2f0;
case 0x0c0be2f2u: goto P_0c0be2f2;
case 0x0c0be2f4u: goto P_0c0be2f4;
case 0x0c0be2f6u: goto P_0c0be2f6;
case 0x0c0be2f8u: goto P_0c0be2f8;
case 0x0c0be2fau: goto P_0c0be2fa;
case 0x0c0be2fcu: goto P_0c0be2fc;
case 0x0c0be2feu: goto P_0c0be2fe;
case 0x0c0be300u: goto P_0c0be300;
case 0x0c0be302u: goto P_0c0be302;
case 0x0c0be304u: goto P_0c0be304;
case 0x0c0be306u: goto P_0c0be306;
case 0x0c0be308u: goto P_0c0be308;
case 0x0c0be30au: goto P_0c0be30a;
case 0x0c0be30cu: goto P_0c0be30c;
case 0x0c0be30eu: goto P_0c0be30e;
case 0x0c0be310u: goto P_0c0be310;
case 0x0c0be312u: goto P_0c0be312;
case 0x0c0be314u: goto P_0c0be314;
case 0x0c0be316u: goto P_0c0be316;
case 0x0c0be318u: goto P_0c0be318;
case 0x0c0be31au: goto P_0c0be31a;
case 0x0c0be31cu: goto P_0c0be31c;
case 0x0c0be31eu: goto P_0c0be31e;
case 0x0c0be320u: goto P_0c0be320;
case 0x0c0be322u: goto P_0c0be322;
case 0x0c0be324u: goto P_0c0be324;
case 0x0c0be326u: goto P_0c0be326;
case 0x0c0be328u: goto P_0c0be328;
case 0x0c0be32au: goto P_0c0be32a;
case 0x0c0be32cu: goto P_0c0be32c;
case 0x0c0be32eu: goto P_0c0be32e;
case 0x0c0be330u: goto P_0c0be330;
case 0x0c0be332u: goto P_0c0be332;
case 0x0c0be334u: goto P_0c0be334;
case 0x0c0be336u: goto P_0c0be336;
case 0x0c0be338u: goto P_0c0be338;
case 0x0c0be33au: goto P_0c0be33a;
case 0x0c0c10a2u: goto P_0c0c10a2;
case 0x0c0c10a4u: goto P_0c0c10a4;
case 0x0c0c10a6u: goto P_0c0c10a6;
case 0x0c0c10a8u: goto P_0c0c10a8;
case 0x0c0c10aau: goto P_0c0c10aa;
case 0x0c0c10acu: goto P_0c0c10ac;
case 0x0c0c10aeu: goto P_0c0c10ae;
case 0x0c0c10b0u: goto P_0c0c10b0;
case 0x0c0c10b2u: goto P_0c0c10b2;
case 0x0c0c10b4u: goto P_0c0c10b4;
case 0x0c0c10b6u: goto P_0c0c10b6;
case 0x0c0c10b8u: goto P_0c0c10b8;
case 0x0c0c10bau: goto P_0c0c10ba;
case 0x0c0c10bcu: goto P_0c0c10bc;
case 0x0c0c10beu: goto P_0c0c10be;
case 0x0c0c10c0u: goto P_0c0c10c0;
case 0x0c0c10c2u: goto P_0c0c10c2;
case 0x0c0c10c4u: goto P_0c0c10c4;
case 0x0c0c10c6u: goto P_0c0c10c6;
case 0x0c0c10c8u: goto P_0c0c10c8;
case 0x0c0c10cau: goto P_0c0c10ca;
case 0x0c0c10ccu: goto P_0c0c10cc;
case 0x0c0c10ceu: goto P_0c0c10ce;
case 0x0c0c10d0u: goto P_0c0c10d0;
case 0x0c0c10d2u: goto P_0c0c10d2;
case 0x0c0c10d4u: goto P_0c0c10d4;
case 0x0c0c10d6u: goto P_0c0c10d6;
case 0x0c0c10d8u: goto P_0c0c10d8;
case 0x0c0c10dau: goto P_0c0c10da;
case 0x0c0c10dcu: goto P_0c0c10dc;
case 0x0c0c10deu: goto P_0c0c10de;
case 0x0c0c10e0u: goto P_0c0c10e0;
case 0x0c0c10e2u: goto P_0c0c10e2;
case 0x0c0c10e4u: goto P_0c0c10e4;
case 0x0c0c10e6u: goto P_0c0c10e6;
case 0x0c0c10e8u: goto P_0c0c10e8;
case 0x0c0c10eau: goto P_0c0c10ea;
case 0x0c0c10ecu: goto P_0c0c10ec;
case 0x0c0c10eeu: goto P_0c0c10ee;
case 0x0c0c10f0u: goto P_0c0c10f0;
case 0x0c0c10f2u: goto P_0c0c10f2;
case 0x0c0c10f4u: goto P_0c0c10f4;
case 0x0c0c10f6u: goto P_0c0c10f6;
case 0x0c0c10f8u: goto P_0c0c10f8;
case 0x0c0c10fau: goto P_0c0c10fa;
case 0x0c0c10fcu: goto P_0c0c10fc;
case 0x0c0c10feu: goto P_0c0c10fe;
case 0x0c0c1100u: goto P_0c0c1100;
case 0x0c0c1102u: goto P_0c0c1102;
case 0x0c0c1104u: goto P_0c0c1104;
case 0x0c0c1106u: goto P_0c0c1106;
case 0x0c0c1108u: goto P_0c0c1108;
case 0x0c0c110au: goto P_0c0c110a;
case 0x0c0c110cu: goto P_0c0c110c;
case 0x0c0c110eu: goto P_0c0c110e;
case 0x0c0c1110u: goto P_0c0c1110;
case 0x0c0c1112u: goto P_0c0c1112;
case 0x0c0c1114u: goto P_0c0c1114;
case 0x0c0c1116u: goto P_0c0c1116;
case 0x0c0c1118u: goto P_0c0c1118;
case 0x0c0c111au: goto P_0c0c111a;
case 0x0c0c111cu: goto P_0c0c111c;
case 0x0c0c111eu: goto P_0c0c111e;
case 0x0c0c1120u: goto P_0c0c1120;
case 0x0c0c1122u: goto P_0c0c1122;
case 0x0c0c1124u: goto P_0c0c1124;
case 0x0c0c1126u: goto P_0c0c1126;
case 0x0c0c1128u: goto P_0c0c1128;
case 0x0c0c112au: goto P_0c0c112a;
case 0x0c0c112cu: goto P_0c0c112c;
case 0x0c0c112eu: goto P_0c0c112e;
case 0x0c0c1130u: goto P_0c0c1130;
case 0x0c0c1132u: goto P_0c0c1132;
case 0x0c0c1134u: goto P_0c0c1134;
case 0x0c0c1136u: goto P_0c0c1136;
case 0x0c0c1138u: goto P_0c0c1138;
case 0x0c0c113au: goto P_0c0c113a;
case 0x0c0c113cu: goto P_0c0c113c;
case 0x0c0c113eu: goto P_0c0c113e;
case 0x0c0c1140u: goto P_0c0c1140;
case 0x0c0c1142u: goto P_0c0c1142;
case 0x0c0c1144u: goto P_0c0c1144;
case 0x0c0c1146u: goto P_0c0c1146;
case 0x0c0c1148u: goto P_0c0c1148;
case 0x0c0c114au: goto P_0c0c114a;
case 0x0c0c114cu: goto P_0c0c114c;
case 0x0c0c114eu: goto P_0c0c114e;
case 0x0c0c1150u: goto P_0c0c1150;
case 0x0c0c1152u: goto P_0c0c1152;
case 0x0c0c1154u: goto P_0c0c1154;
case 0x0c0c1156u: goto P_0c0c1156;
case 0x0c0c1158u: goto P_0c0c1158;
case 0x0c0c115au: goto P_0c0c115a;
case 0x0c0c115cu: goto P_0c0c115c;
case 0x0c0c115eu: goto P_0c0c115e;
case 0x0c0c1160u: goto P_0c0c1160;
case 0x0c0c1162u: goto P_0c0c1162;
case 0x0c0c1164u: goto P_0c0c1164;
case 0x0c0c1166u: goto P_0c0c1166;
case 0x0c0c1168u: goto P_0c0c1168;
case 0x0c0c116au: goto P_0c0c116a;
case 0x0c0c116cu: goto P_0c0c116c;
case 0x0c0c116eu: goto P_0c0c116e;
case 0x0c0c1170u: goto P_0c0c1170;
case 0x0c0c1172u: goto P_0c0c1172;
case 0x0c0c1174u: goto P_0c0c1174;
case 0x0c0c1176u: goto P_0c0c1176;
case 0x0c0c1178u: goto P_0c0c1178;
case 0x0c0c117au: goto P_0c0c117a;
case 0x0c0c117cu: goto P_0c0c117c;
case 0x0c0c19e8u: goto P_0c0c19e8;
case 0x0c0c19eau: goto P_0c0c19ea;
case 0x0c0c19ecu: goto P_0c0c19ec;
case 0x0c0c19eeu: goto P_0c0c19ee;
case 0x0c0c19f0u: goto P_0c0c19f0;
case 0x0c0c19f2u: goto P_0c0c19f2;
case 0x0c0c19f4u: goto P_0c0c19f4;
case 0x0c0c19f6u: goto P_0c0c19f6;
case 0x0c0c19f8u: goto P_0c0c19f8;
case 0x0c0c19fau: goto P_0c0c19fa;
case 0x0c0c19fcu: goto P_0c0c19fc;
case 0x0c0c19feu: goto P_0c0c19fe;
case 0x0c0c1a00u: goto P_0c0c1a00;
case 0x0c0c1a02u: goto P_0c0c1a02;
case 0x0c0c1a04u: goto P_0c0c1a04;
case 0x0c0c1a06u: goto P_0c0c1a06;
case 0x0c0c1a08u: goto P_0c0c1a08;
case 0x0c0c1a0au: goto P_0c0c1a0a;
case 0x0c0c1a0cu: goto P_0c0c1a0c;
case 0x0c0c1a0eu: goto P_0c0c1a0e;
case 0x0c0c1a10u: goto P_0c0c1a10;
case 0x0c0c1a12u: goto P_0c0c1a12;
case 0x0c0c1a14u: goto P_0c0c1a14;
case 0x0c0c1a16u: goto P_0c0c1a16;
case 0x0c0c1a18u: goto P_0c0c1a18;
case 0x0c0c1a1au: goto P_0c0c1a1a;
case 0x0c0c1a1cu: goto P_0c0c1a1c;
case 0x0c0c1a1eu: goto P_0c0c1a1e;
case 0x0c0c1a20u: goto P_0c0c1a20;
case 0x0c0c1a22u: goto P_0c0c1a22;
case 0x0c0c1a24u: goto P_0c0c1a24;
case 0x0c0c1a26u: goto P_0c0c1a26;
case 0x0c0c1a28u: goto P_0c0c1a28;
case 0x0c0c1a2au: goto P_0c0c1a2a;
case 0x0c0c1a2cu: goto P_0c0c1a2c;
case 0x0c0c1a2eu: goto P_0c0c1a2e;
case 0x0c0c1a30u: goto P_0c0c1a30;
case 0x0c0c1a32u: goto P_0c0c1a32;
case 0x0c0c1a34u: goto P_0c0c1a34;
case 0x0c0c1a36u: goto P_0c0c1a36;
case 0x0c0c1a38u: goto P_0c0c1a38;
case 0x0c0c1a3au: goto P_0c0c1a3a;
case 0x0c0c1a3cu: goto P_0c0c1a3c;
case 0x0c0c1a3eu: goto P_0c0c1a3e;
case 0x0c0c1a40u: goto P_0c0c1a40;
case 0x0c0c1a42u: goto P_0c0c1a42;
case 0x0c0c1a44u: goto P_0c0c1a44;
case 0x0c0c1a46u: goto P_0c0c1a46;
case 0x0c0c1a48u: goto P_0c0c1a48;
case 0x0c0c1a4au: goto P_0c0c1a4a;
case 0x0c0c1a4cu: goto P_0c0c1a4c;
case 0x0c0c1a4eu: goto P_0c0c1a4e;
case 0x0c0c1a50u: goto P_0c0c1a50;
case 0x0c0c1a52u: goto P_0c0c1a52;
case 0x0c0c1a54u: goto P_0c0c1a54;
case 0x0c0c1a56u: goto P_0c0c1a56;
case 0x0c0c1a58u: goto P_0c0c1a58;
case 0x0c0c1a5au: goto P_0c0c1a5a;
case 0x0c0c1a5cu: goto P_0c0c1a5c;
case 0x0c0c1a5eu: goto P_0c0c1a5e;
case 0x0c0c1a60u: goto P_0c0c1a60;
case 0x0c0c1d86u: goto P_0c0c1d86;
case 0x0c0c1d88u: goto P_0c0c1d88;
case 0x0c0c1d8au: goto P_0c0c1d8a;
case 0x0c0c1d8cu: goto P_0c0c1d8c;
case 0x0c0c1d8eu: goto P_0c0c1d8e;
case 0x0c0c1d90u: goto P_0c0c1d90;
case 0x0c0c1d92u: goto P_0c0c1d92;
case 0x0c0c1d94u: goto P_0c0c1d94;
case 0x0c0c1d96u: goto P_0c0c1d96;
case 0x0c0c1d98u: goto P_0c0c1d98;
case 0x0c0c1d9au: goto P_0c0c1d9a;
case 0x0c0c1d9cu: goto P_0c0c1d9c;
case 0x0c0c1d9eu: goto P_0c0c1d9e;
case 0x0c0c1da0u: goto P_0c0c1da0;
case 0x0c0c1da2u: goto P_0c0c1da2;
case 0x0c0c1da4u: goto P_0c0c1da4;
case 0x0c0c298cu: goto P_0c0c298c;
case 0x0c0c298eu: goto P_0c0c298e;
case 0x0c0c2990u: goto P_0c0c2990;
case 0x0c0c2992u: goto P_0c0c2992;
case 0x0c0c2994u: goto P_0c0c2994;
case 0x0c0c2996u: goto P_0c0c2996;
case 0x0c0c2998u: goto P_0c0c2998;
case 0x0c0c299au: goto P_0c0c299a;
case 0x0c0c299cu: goto P_0c0c299c;
case 0x0c0c299eu: goto P_0c0c299e;
case 0x0c0c29a0u: goto P_0c0c29a0;
case 0x0c0c29a2u: goto P_0c0c29a2;
case 0x0c0c29a4u: goto P_0c0c29a4;
case 0x0c0c29a6u: goto P_0c0c29a6;
case 0x0c0c29a8u: goto P_0c0c29a8;
case 0x0c0c29aau: goto P_0c0c29aa;
case 0x0c0c29acu: goto P_0c0c29ac;
case 0x0c0c29aeu: goto P_0c0c29ae;
case 0x0c0c29b0u: goto P_0c0c29b0;
case 0x0c0c29b2u: goto P_0c0c29b2;
case 0x0c0c29b4u: goto P_0c0c29b4;
case 0x0c0c29b6u: goto P_0c0c29b6;
case 0x0c0c29b8u: goto P_0c0c29b8;
case 0x0c0c29bau: goto P_0c0c29ba;
case 0x0c0c29bcu: goto P_0c0c29bc;
case 0x0c0c29beu: goto P_0c0c29be;
case 0x0c0c29c0u: goto P_0c0c29c0;
case 0x0c0c29c2u: goto P_0c0c29c2;
case 0x0c0c29c4u: goto P_0c0c29c4;
case 0x0c0c29c6u: goto P_0c0c29c6;
case 0x0c0c29c8u: goto P_0c0c29c8;
case 0x0c0c29cau: goto P_0c0c29ca;
case 0x0c0c29ccu: goto P_0c0c29cc;
case 0x0c0c29ceu: goto P_0c0c29ce;
case 0x0c0c29d0u: goto P_0c0c29d0;
case 0x0c0c29d2u: goto P_0c0c29d2;
case 0x0c0c29d4u: goto P_0c0c29d4;
case 0x0c0c29d6u: goto P_0c0c29d6;
case 0x0c0c29d8u: goto P_0c0c29d8;
case 0x0c0c29dau: goto P_0c0c29da;
case 0x0c0c29dcu: goto P_0c0c29dc;
case 0x0c0c29deu: goto P_0c0c29de;
case 0x0c0c29e0u: goto P_0c0c29e0;
case 0x0c0c29e2u: goto P_0c0c29e2;
case 0x0c0c29e4u: goto P_0c0c29e4;
case 0x0c0c29e6u: goto P_0c0c29e6;
case 0x0c0c29e8u: goto P_0c0c29e8;
case 0x0c0c29eau: goto P_0c0c29ea;
case 0x0c0c29ecu: goto P_0c0c29ec;
case 0x0c0c29eeu: goto P_0c0c29ee;
case 0x0c0c29f0u: goto P_0c0c29f0;
case 0x0c0c29f2u: goto P_0c0c29f2;
case 0x0c0c29f4u: goto P_0c0c29f4;
case 0x0c0c29f6u: goto P_0c0c29f6;
case 0x0c0c29f8u: goto P_0c0c29f8;
case 0x0c0c29fau: goto P_0c0c29fa;
case 0x0c0c29fcu: goto P_0c0c29fc;
case 0x0c0c29feu: goto P_0c0c29fe;
case 0x0c0c2a00u: goto P_0c0c2a00;
case 0x0c0c2a02u: goto P_0c0c2a02;
case 0x0c0c2a04u: goto P_0c0c2a04;
case 0x0c0c2a06u: goto P_0c0c2a06;
case 0x0c0c2a08u: goto P_0c0c2a08;
case 0x0c0c2a0au: goto P_0c0c2a0a;
case 0x0c0c2a0cu: goto P_0c0c2a0c;
case 0x0c0c2a0eu: goto P_0c0c2a0e;
case 0x0c0c2a10u: goto P_0c0c2a10;
case 0x0c0c2a12u: goto P_0c0c2a12;
case 0x0c0c2a14u: goto P_0c0c2a14;
case 0x0c0c2a16u: goto P_0c0c2a16;
case 0x0c0c2a18u: goto P_0c0c2a18;
case 0x0c0c2a1au: goto P_0c0c2a1a;
case 0x0c0c2a1cu: goto P_0c0c2a1c;
case 0x0c0c2a1eu: goto P_0c0c2a1e;
case 0x0c0c2a20u: goto P_0c0c2a20;
case 0x0c0c2a22u: goto P_0c0c2a22;
case 0x0c0c2a24u: goto P_0c0c2a24;
case 0x0c0c2a26u: goto P_0c0c2a26;
case 0x0c0c2a28u: goto P_0c0c2a28;
case 0x0c0c2a2au: goto P_0c0c2a2a;
case 0x0c0c2a2cu: goto P_0c0c2a2c;
case 0x0c0c2a2eu: goto P_0c0c2a2e;
case 0x0c0c2a30u: goto P_0c0c2a30;
case 0x0c0c2a32u: goto P_0c0c2a32;
case 0x0c0c2a34u: goto P_0c0c2a34;
case 0x0c0c2a36u: goto P_0c0c2a36;
case 0x0c0c2a38u: goto P_0c0c2a38;
case 0x0c0c2a3au: goto P_0c0c2a3a;
case 0x0c0c2a3cu: goto P_0c0c2a3c;
case 0x0c0c2a3eu: goto P_0c0c2a3e;
case 0x0c0c2a40u: goto P_0c0c2a40;
case 0x0c0c2a42u: goto P_0c0c2a42;
case 0x0c0c2a44u: goto P_0c0c2a44;
case 0x0c0c2a46u: goto P_0c0c2a46;
case 0x0c0c2a48u: goto P_0c0c2a48;
case 0x0c0c2a4au: goto P_0c0c2a4a;
case 0x0c0c2a4cu: goto P_0c0c2a4c;
case 0x0c0c2a4eu: goto P_0c0c2a4e;
case 0x0c0c2a50u: goto P_0c0c2a50;
case 0x0c0c2a52u: goto P_0c0c2a52;
case 0x0c0c2a54u: goto P_0c0c2a54;
case 0x0c0c2a56u: goto P_0c0c2a56;
case 0x0c0c2a58u: goto P_0c0c2a58;
case 0x0c0c2a5au: goto P_0c0c2a5a;
case 0x0c0c2a5cu: goto P_0c0c2a5c;
case 0x0c0c2a5eu: goto P_0c0c2a5e;
case 0x0c0c2a60u: goto P_0c0c2a60;
case 0x0c0c2a62u: goto P_0c0c2a62;
case 0x0c0c2a64u: goto P_0c0c2a64;
case 0x0c0c2a66u: goto P_0c0c2a66;
case 0x0c0c2a68u: goto P_0c0c2a68;
case 0x0c0c2a6au: goto P_0c0c2a6a;
case 0x0c0c2a6cu: goto P_0c0c2a6c;
case 0x0c0c2a6eu: goto P_0c0c2a6e;
case 0x0c0c2a70u: goto P_0c0c2a70;
case 0x0c0c2a72u: goto P_0c0c2a72;
case 0x0c0c2a74u: goto P_0c0c2a74;
case 0x0c0c2a76u: goto P_0c0c2a76;
case 0x0c0c2a78u: goto P_0c0c2a78;
case 0x0c0c2a7au: goto P_0c0c2a7a;
case 0x0c0c2a7cu: goto P_0c0c2a7c;
case 0x0c0c2a7eu: goto P_0c0c2a7e;
case 0x0c0c2a80u: goto P_0c0c2a80;
case 0x0c0c2a82u: goto P_0c0c2a82;
case 0x0c0c2a84u: goto P_0c0c2a84;
case 0x0c0c2a86u: goto P_0c0c2a86;
case 0x0c0c2a88u: goto P_0c0c2a88;
case 0x0c0c2a8au: goto P_0c0c2a8a;
case 0x0c0c2a8cu: goto P_0c0c2a8c;
case 0x0c0c2a8eu: goto P_0c0c2a8e;
case 0x0c0c2a90u: goto P_0c0c2a90;
case 0x0c0c2a92u: goto P_0c0c2a92;
case 0x0c0c2a94u: goto P_0c0c2a94;
case 0x0c0c2a96u: goto P_0c0c2a96;
case 0x0c0c2a98u: goto P_0c0c2a98;
case 0x0c0c2a9au: goto P_0c0c2a9a;
case 0x0c0c2a9cu: goto P_0c0c2a9c;
case 0x0c0c2a9eu: goto P_0c0c2a9e;
case 0x0c0c2aa0u: goto P_0c0c2aa0;
case 0x0c0c2aa2u: goto P_0c0c2aa2;
case 0x0c0c2aa4u: goto P_0c0c2aa4;
case 0x0c0c2aa6u: goto P_0c0c2aa6;
case 0x0c0c2aa8u: goto P_0c0c2aa8;
case 0x0c0c2aaau: goto P_0c0c2aaa;
case 0x0c0c2aacu: goto P_0c0c2aac;
case 0x0c0c2aaeu: goto P_0c0c2aae;
case 0x0c0c2ab0u: goto P_0c0c2ab0;
case 0x0c0c2ab2u: goto P_0c0c2ab2;
case 0x0c0c2ab4u: goto P_0c0c2ab4;
case 0x0c0c2ab6u: goto P_0c0c2ab6;
case 0x0c0c2ab8u: goto P_0c0c2ab8;
case 0x0c0c2abau: goto P_0c0c2aba;
case 0x0c0c2abcu: goto P_0c0c2abc;
case 0x0c0c2abeu: goto P_0c0c2abe;
case 0x0c0c2ac0u: goto P_0c0c2ac0;
case 0x0c0c2ac2u: goto P_0c0c2ac2;
case 0x0c0c2ac4u: goto P_0c0c2ac4;
case 0x0c0c2ac6u: goto P_0c0c2ac6;
case 0x0c0c2ac8u: goto P_0c0c2ac8;
case 0x0c0c2acau: goto P_0c0c2aca;
case 0x0c0c2accu: goto P_0c0c2acc;
case 0x0c0c2aceu: goto P_0c0c2ace;
case 0x0c0c2ad0u: goto P_0c0c2ad0;
case 0x0c0c2ad2u: goto P_0c0c2ad2;
case 0x0c0c2ad4u: goto P_0c0c2ad4;
case 0x0c0c2ad6u: goto P_0c0c2ad6;
case 0x0c0c2ad8u: goto P_0c0c2ad8;
case 0x0c0c2adau: goto P_0c0c2ada;
case 0x0c0c2adcu: goto P_0c0c2adc;
case 0x0c0c2adeu: goto P_0c0c2ade;
case 0x0c0c2ae0u: goto P_0c0c2ae0;
case 0x0c0c2ae2u: goto P_0c0c2ae2;
case 0x0c0c2ae4u: goto P_0c0c2ae4;
case 0x0c0c2ae6u: goto P_0c0c2ae6;
case 0x0c0c2ae8u: goto P_0c0c2ae8;
case 0x0c0c2aeau: goto P_0c0c2aea;
case 0x0c0c2aecu: goto P_0c0c2aec;
case 0x0c0c2aeeu: goto P_0c0c2aee;
case 0x0c0c2af0u: goto P_0c0c2af0;
case 0x0c0c2af2u: goto P_0c0c2af2;
case 0x0c0c2af4u: goto P_0c0c2af4;
case 0x0c0c2af6u: goto P_0c0c2af6;
case 0x0c0c2af8u: goto P_0c0c2af8;
case 0x0c0c2afau: goto P_0c0c2afa;
case 0x0c0c2afcu: goto P_0c0c2afc;
case 0x0c0c2afeu: goto P_0c0c2afe;
case 0x0c0c2b00u: goto P_0c0c2b00;
case 0x0c0c2b02u: goto P_0c0c2b02;
case 0x0c0c2b04u: goto P_0c0c2b04;
case 0x0c0c2b06u: goto P_0c0c2b06;
case 0x0c0c2b08u: goto P_0c0c2b08;
case 0x0c0c2b0au: goto P_0c0c2b0a;
case 0x0c0c2b0cu: goto P_0c0c2b0c;
case 0x0c0c2b0eu: goto P_0c0c2b0e;
case 0x0c0c2b10u: goto P_0c0c2b10;
case 0x0c0c2b12u: goto P_0c0c2b12;
case 0x0c0c2b14u: goto P_0c0c2b14;
case 0x0c0c2bb4u: goto P_0c0c2bb4;
case 0x0c0c2bb6u: goto P_0c0c2bb6;
case 0x0c0c2bb8u: goto P_0c0c2bb8;
case 0x0c0c2bbau: goto P_0c0c2bba;
case 0x0c0c2bbcu: goto P_0c0c2bbc;
case 0x0c0c2bbeu: goto P_0c0c2bbe;
case 0x0c0c2bc0u: goto P_0c0c2bc0;
case 0x0c0c2bc2u: goto P_0c0c2bc2;
case 0x0c0c2bc4u: goto P_0c0c2bc4;
case 0x0c0c2bc6u: goto P_0c0c2bc6;
case 0x0c0c2bc8u: goto P_0c0c2bc8;
case 0x0c0c2bcau: goto P_0c0c2bca;
case 0x0c0c2bccu: goto P_0c0c2bcc;
case 0x0c0c2bceu: goto P_0c0c2bce;
case 0x0c0c2bd0u: goto P_0c0c2bd0;
case 0x0c0c2bd2u: goto P_0c0c2bd2;
case 0x0c0c2bd4u: goto P_0c0c2bd4;
case 0x0c0c2bd6u: goto P_0c0c2bd6;
case 0x0c0c2bd8u: goto P_0c0c2bd8;
case 0x0c0c2bdau: goto P_0c0c2bda;
case 0x0c0c2bdcu: goto P_0c0c2bdc;
case 0x0c0c2bdeu: goto P_0c0c2bde;
case 0x0c0c2be0u: goto P_0c0c2be0;
case 0x0c0c2be2u: goto P_0c0c2be2;
case 0x0c0c2be4u: goto P_0c0c2be4;
case 0x0c0c2be6u: goto P_0c0c2be6;
case 0x0c0c2be8u: goto P_0c0c2be8;
case 0x0c0c2beau: goto P_0c0c2bea;
case 0x0c0c2becu: goto P_0c0c2bec;
case 0x0c0c2beeu: goto P_0c0c2bee;
case 0x0c0c2bf0u: goto P_0c0c2bf0;
case 0x0c0c2bf2u: goto P_0c0c2bf2;
case 0x0c0c2bf4u: goto P_0c0c2bf4;
case 0x0c0c2bf6u: goto P_0c0c2bf6;
case 0x0c0c2bf8u: goto P_0c0c2bf8;
case 0x0c0c2bfau: goto P_0c0c2bfa;
case 0x0c0c2bfcu: goto P_0c0c2bfc;
case 0x0c0c2bfeu: goto P_0c0c2bfe;
case 0x0c0c2c00u: goto P_0c0c2c00;
case 0x0c0c2c02u: goto P_0c0c2c02;
case 0x0c0c2c04u: goto P_0c0c2c04;
case 0x0c0c2c06u: goto P_0c0c2c06;
case 0x0c0c2c08u: goto P_0c0c2c08;
case 0x0c0c2c0au: goto P_0c0c2c0a;
case 0x0c0c2c0cu: goto P_0c0c2c0c;
case 0x0c0c2c0eu: goto P_0c0c2c0e;
case 0x0c0c2c10u: goto P_0c0c2c10;
case 0x0c0c2c12u: goto P_0c0c2c12;
case 0x0c0c2c14u: goto P_0c0c2c14;
case 0x0c0c2c16u: goto P_0c0c2c16;
case 0x0c0c2c18u: goto P_0c0c2c18;
case 0x0c0c2c1au: goto P_0c0c2c1a;
case 0x0c0c2c1cu: goto P_0c0c2c1c;
case 0x0c0c2c1eu: goto P_0c0c2c1e;
case 0x0c0c2c20u: goto P_0c0c2c20;
case 0x0c0c2c22u: goto P_0c0c2c22;
case 0x0c0c2c24u: goto P_0c0c2c24;
case 0x0c0c2c26u: goto P_0c0c2c26;
case 0x0c0c2c28u: goto P_0c0c2c28;
case 0x0c0c2c2au: goto P_0c0c2c2a;
case 0x0c0c4ebau: goto P_0c0c4eba;
case 0x0c0c4ebcu: goto P_0c0c4ebc;
case 0x0c0c4ebeu: goto P_0c0c4ebe;
case 0x0c0c4ec0u: goto P_0c0c4ec0;
case 0x0c0c4ec2u: goto P_0c0c4ec2;
case 0x0c0c4ec4u: goto P_0c0c4ec4;
case 0x0c0c4ec6u: goto P_0c0c4ec6;
case 0x0c0c4ec8u: goto P_0c0c4ec8;
case 0x0c0c4ecau: goto P_0c0c4eca;
case 0x0c0c4eccu: goto P_0c0c4ecc;
case 0x0c0c4eceu: goto P_0c0c4ece;
case 0x0c0c4ed0u: goto P_0c0c4ed0;
case 0x0c0c4ed2u: goto P_0c0c4ed2;
case 0x0c0c4ed4u: goto P_0c0c4ed4;
case 0x0c0c4ed6u: goto P_0c0c4ed6;
case 0x0c0c4ed8u: goto P_0c0c4ed8;
case 0x0c0c4edau: goto P_0c0c4eda;
case 0x0c0c4edcu: goto P_0c0c4edc;
case 0x0c0c4edeu: goto P_0c0c4ede;
case 0x0c0c4ee0u: goto P_0c0c4ee0;
case 0x0c0c4ee2u: goto P_0c0c4ee2;
case 0x0c0c4ee4u: goto P_0c0c4ee4;
case 0x0c0c4ee6u: goto P_0c0c4ee6;
case 0x0c0c4ee8u: goto P_0c0c4ee8;
case 0x0c0c4eeau: goto P_0c0c4eea;
case 0x0c0c4eecu: goto P_0c0c4eec;
case 0x0c0c4eeeu: goto P_0c0c4eee;
case 0x0c0c4ef0u: goto P_0c0c4ef0;
case 0x0c0c4ef2u: goto P_0c0c4ef2;
case 0x0c0c4ef4u: goto P_0c0c4ef4;
case 0x0c0c4ef6u: goto P_0c0c4ef6;
case 0x0c0c4ef8u: goto P_0c0c4ef8;
case 0x0c0c4efau: goto P_0c0c4efa;
case 0x0c0c4efcu: goto P_0c0c4efc;
case 0x0c0c4efeu: goto P_0c0c4efe;
case 0x0c0c4f00u: goto P_0c0c4f00;
case 0x0c0c4f02u: goto P_0c0c4f02;
case 0x0c0c4f04u: goto P_0c0c4f04;
case 0x0c0c4f06u: goto P_0c0c4f06;
case 0x0c0c4f08u: goto P_0c0c4f08;
case 0x0c0c4f0au: goto P_0c0c4f0a;
case 0x0c0c4f0cu: goto P_0c0c4f0c;
case 0x0c0c4f0eu: goto P_0c0c4f0e;
case 0x0c0c4f10u: goto P_0c0c4f10;
case 0x0c0c4f12u: goto P_0c0c4f12;
case 0x0c0c4f14u: goto P_0c0c4f14;
case 0x0c0c4f16u: goto P_0c0c4f16;
case 0x0c0c4f18u: goto P_0c0c4f18;
case 0x0c0c4f1au: goto P_0c0c4f1a;
case 0x0c0c4f1cu: goto P_0c0c4f1c;
case 0x0c0c4f1eu: goto P_0c0c4f1e;
case 0x0c0c4f20u: goto P_0c0c4f20;
case 0x0c0c4f22u: goto P_0c0c4f22;
case 0x0c0c4f24u: goto P_0c0c4f24;
case 0x0c0c4f26u: goto P_0c0c4f26;
case 0x0c0c4f28u: goto P_0c0c4f28;
case 0x0c0c4f2au: goto P_0c0c4f2a;
case 0x0c0c4f2cu: goto P_0c0c4f2c;
case 0x0c0c4f2eu: goto P_0c0c4f2e;
case 0x0c0c4f30u: goto P_0c0c4f30;
case 0x0c0c4f32u: goto P_0c0c4f32;
case 0x0c0c4f34u: goto P_0c0c4f34;
case 0x0c0c4f36u: goto P_0c0c4f36;
case 0x0c0c4f38u: goto P_0c0c4f38;
case 0x0c0c4f3au: goto P_0c0c4f3a;
case 0x0c0c4f3cu: goto P_0c0c4f3c;
case 0x0c0c4f3eu: goto P_0c0c4f3e;
case 0x0c0c4f40u: goto P_0c0c4f40;
case 0x0c0c4f80u: goto P_0c0c4f80;
case 0x0c0c4f82u: goto P_0c0c4f82;
case 0x0c0c4f84u: goto P_0c0c4f84;
case 0x0c0c4f86u: goto P_0c0c4f86;
case 0x0c0c4f88u: goto P_0c0c4f88;
case 0x0c0c4f8au: goto P_0c0c4f8a;
case 0x0c0c4f8cu: goto P_0c0c4f8c;
case 0x0c0c4f8eu: goto P_0c0c4f8e;
case 0x0c0c4f90u: goto P_0c0c4f90;
case 0x0c0c4f92u: goto P_0c0c4f92;
case 0x0c0c4f94u: goto P_0c0c4f94;
case 0x0c0c4f96u: goto P_0c0c4f96;
case 0x0c0c4f98u: goto P_0c0c4f98;
case 0x0c0c4f9au: goto P_0c0c4f9a;
case 0x0c0c4f9cu: goto P_0c0c4f9c;
case 0x0c0c4f9eu: goto P_0c0c4f9e;
case 0x0c0c4fa0u: goto P_0c0c4fa0;
case 0x0c0c4fa2u: goto P_0c0c4fa2;
case 0x0c0c4fa4u: goto P_0c0c4fa4;
case 0x0c0c4fa6u: goto P_0c0c4fa6;
case 0x0c0c4fa8u: goto P_0c0c4fa8;
case 0x0c0c4faau: goto P_0c0c4faa;
case 0x0c0c4facu: goto P_0c0c4fac;
case 0x0c0c4faeu: goto P_0c0c4fae;
case 0x0c0c4fb0u: goto P_0c0c4fb0;
case 0x0c0c4fb2u: goto P_0c0c4fb2;
case 0x0c0c4fb4u: goto P_0c0c4fb4;
case 0x0c0c4fb6u: goto P_0c0c4fb6;
case 0x0c0c4fb8u: goto P_0c0c4fb8;
case 0x0c0c4fbau: goto P_0c0c4fba;
case 0x0c0c4fbcu: goto P_0c0c4fbc;
case 0x0c0c4fbeu: goto P_0c0c4fbe;
case 0x0c0c4fc0u: goto P_0c0c4fc0;
case 0x0c0c4fc2u: goto P_0c0c4fc2;
case 0x0c0c4fc4u: goto P_0c0c4fc4;
case 0x0c0c4fc6u: goto P_0c0c4fc6;
case 0x0c0c4fc8u: goto P_0c0c4fc8;
case 0x0c0c4fcau: goto P_0c0c4fca;
case 0x0c0c4fccu: goto P_0c0c4fcc;
case 0x0c0c4fceu: goto P_0c0c4fce;
case 0x0c0c4fd0u: goto P_0c0c4fd0;
case 0x0c0c4fd2u: goto P_0c0c4fd2;
case 0x0c0c4fd4u: goto P_0c0c4fd4;
case 0x0c0c4fd6u: goto P_0c0c4fd6;
case 0x0c0c4fd8u: goto P_0c0c4fd8;
case 0x0c0c4fdau: goto P_0c0c4fda;
case 0x0c0c4fdcu: goto P_0c0c4fdc;
case 0x0c0c4fdeu: goto P_0c0c4fde;
case 0x0c0c4fe0u: goto P_0c0c4fe0;
case 0x0c0c4fe2u: goto P_0c0c4fe2;
case 0x0c0c4fe4u: goto P_0c0c4fe4;
case 0x0c0c4fe6u: goto P_0c0c4fe6;
case 0x0c0c4fe8u: goto P_0c0c4fe8;
case 0x0c0c4feau: goto P_0c0c4fea;
case 0x0c0c4fecu: goto P_0c0c4fec;
case 0x0c0c4feeu: goto P_0c0c4fee;
case 0x0c0c4ff0u: goto P_0c0c4ff0;
case 0x0c0c4ff2u: goto P_0c0c4ff2;
case 0x0c0c4ff4u: goto P_0c0c4ff4;
case 0x0c0c4ff6u: goto P_0c0c4ff6;
case 0x0c0c4ff8u: goto P_0c0c4ff8;
case 0x0c0c4ffau: goto P_0c0c4ffa;
case 0x0c0c4ffcu: goto P_0c0c4ffc;
case 0x0c0c4ffeu: goto P_0c0c4ffe;
case 0x0c0c5000u: goto P_0c0c5000;
case 0x0c0c5002u: goto P_0c0c5002;
case 0x0c0c5004u: goto P_0c0c5004;
case 0x0c0c5006u: goto P_0c0c5006;
case 0x0c0c5008u: goto P_0c0c5008;
case 0x0c0c500au: goto P_0c0c500a;
case 0x0c0c500cu: goto P_0c0c500c;
case 0x0c0c500eu: goto P_0c0c500e;
case 0x0c0c5010u: goto P_0c0c5010;
case 0x0c0c5012u: goto P_0c0c5012;
case 0x0c0c5014u: goto P_0c0c5014;
case 0x0c0c5016u: goto P_0c0c5016;
case 0x0c0c5018u: goto P_0c0c5018;
case 0x0c0c501au: goto P_0c0c501a;
case 0x0c0c501cu: goto P_0c0c501c;
case 0x0c0c501eu: goto P_0c0c501e;
case 0x0c0c5020u: goto P_0c0c5020;
case 0x0c0c5022u: goto P_0c0c5022;
case 0x0c0c5024u: goto P_0c0c5024;
case 0x0c0c5048u: goto P_0c0c5048;
case 0x0c0c504au: goto P_0c0c504a;
case 0x0c0c504cu: goto P_0c0c504c;
case 0x0c0c504eu: goto P_0c0c504e;
case 0x0c0c5050u: goto P_0c0c5050;
case 0x0c0c5052u: goto P_0c0c5052;
case 0x0c0c5054u: goto P_0c0c5054;
case 0x0c0c5056u: goto P_0c0c5056;
case 0x0c0c5058u: goto P_0c0c5058;
case 0x0c0c505au: goto P_0c0c505a;
case 0x0c0c505cu: goto P_0c0c505c;
case 0x0c0c505eu: goto P_0c0c505e;
case 0x0c0c5060u: goto P_0c0c5060;
case 0x0c0c5a74u: goto P_0c0c5a74;
case 0x0c0c5a76u: goto P_0c0c5a76;
case 0x0c0c5a78u: goto P_0c0c5a78;
case 0x0c0c5a7au: goto P_0c0c5a7a;
case 0x0c0c5a7cu: goto P_0c0c5a7c;
case 0x0c0c5a7eu: goto P_0c0c5a7e;
case 0x0c0c5a80u: goto P_0c0c5a80;
case 0x0c0c5a82u: goto P_0c0c5a82;
case 0x0c0c5a84u: goto P_0c0c5a84;
case 0x0c0c5a86u: goto P_0c0c5a86;
case 0x0c0c5a88u: goto P_0c0c5a88;
case 0x0c0c5a8au: goto P_0c0c5a8a;
case 0x0c0c5a8cu: goto P_0c0c5a8c;
case 0x0c0c5a8eu: goto P_0c0c5a8e;
case 0x0c0c5a90u: goto P_0c0c5a90;
case 0x0c0c5a92u: goto P_0c0c5a92;
case 0x0c0c5a94u: goto P_0c0c5a94;
case 0x0c0c5a96u: goto P_0c0c5a96;
case 0x0c0c5a98u: goto P_0c0c5a98;
case 0x0c0c5a9au: goto P_0c0c5a9a;
case 0x0c0c5a9cu: goto P_0c0c5a9c;
case 0x0c0c5a9eu: goto P_0c0c5a9e;
case 0x0c0c5aa0u: goto P_0c0c5aa0;
case 0x0c0c5aa2u: goto P_0c0c5aa2;
case 0x0c0c5aa4u: goto P_0c0c5aa4;
case 0x0c0c5aa6u: goto P_0c0c5aa6;
case 0x0c0c5aa8u: goto P_0c0c5aa8;
case 0x0c0c5aaau: goto P_0c0c5aaa;
case 0x0c0c5aacu: goto P_0c0c5aac;
case 0x0c0c5aaeu: goto P_0c0c5aae;
case 0x0c0c5ab0u: goto P_0c0c5ab0;
case 0x0c0c5ab2u: goto P_0c0c5ab2;
case 0x0c0c5ab4u: goto P_0c0c5ab4;
case 0x0c0c5ab6u: goto P_0c0c5ab6;
case 0x0c0c5ab8u: goto P_0c0c5ab8;
case 0x0c0c5abau: goto P_0c0c5aba;
case 0x0c0c5abcu: goto P_0c0c5abc;
case 0x0c0c5abeu: goto P_0c0c5abe;
case 0x0c0c5ac0u: goto P_0c0c5ac0;
case 0x0c0c5ac2u: goto P_0c0c5ac2;
case 0x0c0c5ac4u: goto P_0c0c5ac4;
case 0x0c0c5ac6u: goto P_0c0c5ac6;
case 0x0c0c5ac8u: goto P_0c0c5ac8;
case 0x0c0c5acau: goto P_0c0c5aca;
case 0x0c0c5accu: goto P_0c0c5acc;
case 0x0c0c5aceu: goto P_0c0c5ace;
case 0x0c0c5ad0u: goto P_0c0c5ad0;
case 0x0c0c5ad2u: goto P_0c0c5ad2;
case 0x0c0c5ad4u: goto P_0c0c5ad4;
case 0x0c0c5ad6u: goto P_0c0c5ad6;
case 0x0c0c5ad8u: goto P_0c0c5ad8;
case 0x0c0c5adau: goto P_0c0c5ada;
case 0x0c0c5adcu: goto P_0c0c5adc;
case 0x0c0c5adeu: goto P_0c0c5ade;
case 0x0c0c5ae0u: goto P_0c0c5ae0;
case 0x0c0c5ae2u: goto P_0c0c5ae2;
case 0x0c0c5ae4u: goto P_0c0c5ae4;
case 0x0c0c5ae6u: goto P_0c0c5ae6;
case 0x0c0c5ae8u: goto P_0c0c5ae8;
case 0x0c0c5aeau: goto P_0c0c5aea;
case 0x0c0c5aecu: goto P_0c0c5aec;
case 0x0c0c5b08u: goto P_0c0c5b08;
case 0x0c0c5b0au: goto P_0c0c5b0a;
case 0x0c0c5b0cu: goto P_0c0c5b0c;
case 0x0c0c5b0eu: goto P_0c0c5b0e;
case 0x0c0c5b10u: goto P_0c0c5b10;
case 0x0c0c5b12u: goto P_0c0c5b12;
case 0x0c0c5b14u: goto P_0c0c5b14;
case 0x0c0c5b16u: goto P_0c0c5b16;
case 0x0c0c5b18u: goto P_0c0c5b18;
case 0x0c0c5b1au: goto P_0c0c5b1a;
case 0x0c0c5b1cu: goto P_0c0c5b1c;
case 0x0c0c5b1eu: goto P_0c0c5b1e;
case 0x0c0c5b20u: goto P_0c0c5b20;
case 0x0c0c5b22u: goto P_0c0c5b22;
case 0x0c0c5b24u: goto P_0c0c5b24;
case 0x0c0c5b26u: goto P_0c0c5b26;
case 0x0c0c5b28u: goto P_0c0c5b28;
case 0x0c0c5b2au: goto P_0c0c5b2a;
case 0x0c0c5b2cu: goto P_0c0c5b2c;
case 0x0c0c5b2eu: goto P_0c0c5b2e;
case 0x0c0c5b30u: goto P_0c0c5b30;
case 0x0c0c5b32u: goto P_0c0c5b32;
case 0x0c0c5b34u: goto P_0c0c5b34;
case 0x0c0c5b36u: goto P_0c0c5b36;
case 0x0c0c5b38u: goto P_0c0c5b38;
case 0x0c0c5b3au: goto P_0c0c5b3a;
case 0x0c0c5b3cu: goto P_0c0c5b3c;
case 0x0c0c5b3eu: goto P_0c0c5b3e;
case 0x0c0c5b40u: goto P_0c0c5b40;
case 0x0c0c5b42u: goto P_0c0c5b42;
case 0x0c0c5b44u: goto P_0c0c5b44;
case 0x0c0c5b46u: goto P_0c0c5b46;
case 0x0c0c5b48u: goto P_0c0c5b48;
case 0x0c0c5b4au: goto P_0c0c5b4a;
case 0x0c0c5b4cu: goto P_0c0c5b4c;
case 0x0c0c5b4eu: goto P_0c0c5b4e;
case 0x0c0c5b50u: goto P_0c0c5b50;
case 0x0c0c5b52u: goto P_0c0c5b52;
case 0x0c0c5b54u: goto P_0c0c5b54;
case 0x0c0c5b56u: goto P_0c0c5b56;
case 0x0c0c5b58u: goto P_0c0c5b58;
case 0x0c0c5b5au: goto P_0c0c5b5a;
case 0x0c0c5b5cu: goto P_0c0c5b5c;
case 0x0c0c5b5eu: goto P_0c0c5b5e;
case 0x0c0c5b60u: goto P_0c0c5b60;
case 0x0c0c5b62u: goto P_0c0c5b62;
case 0x0c0c5b64u: goto P_0c0c5b64;
case 0x0c0c5b66u: goto P_0c0c5b66;
case 0x0c0c5b68u: goto P_0c0c5b68;
case 0x0c0c5b6au: goto P_0c0c5b6a;
case 0x0c0c5b6cu: goto P_0c0c5b6c;
case 0x0c0c5b6eu: goto P_0c0c5b6e;
case 0x0c0c5b70u: goto P_0c0c5b70;
case 0x0c0c5b72u: goto P_0c0c5b72;
case 0x0c0c5b74u: goto P_0c0c5b74;
case 0x0c0c5b76u: goto P_0c0c5b76;
case 0x0c0c5b78u: goto P_0c0c5b78;
case 0x0c0c5b7au: goto P_0c0c5b7a;
case 0x0c0c5b7cu: goto P_0c0c5b7c;
case 0x0c0c5b7eu: goto P_0c0c5b7e;
case 0x0c0c5b80u: goto P_0c0c5b80;
case 0x0c0c5b82u: goto P_0c0c5b82;
case 0x0c0c5b84u: goto P_0c0c5b84;
case 0x0c0c5b86u: goto P_0c0c5b86;
case 0x0c0c5b88u: goto P_0c0c5b88;
case 0x0c0c5b8au: goto P_0c0c5b8a;
case 0x0c0c5b8cu: goto P_0c0c5b8c;
case 0x0c0c5b8eu: goto P_0c0c5b8e;
case 0x0c0c5b90u: goto P_0c0c5b90;
case 0x0c0c5b92u: goto P_0c0c5b92;
case 0x0c0c5b94u: goto P_0c0c5b94;
case 0x0c0c5b96u: goto P_0c0c5b96;
case 0x0c0c5b98u: goto P_0c0c5b98;
case 0x0c0c5b9au: goto P_0c0c5b9a;
case 0x0c0c5b9cu: goto P_0c0c5b9c;
case 0x0c0c5b9eu: goto P_0c0c5b9e;
case 0x0c0c5ba0u: goto P_0c0c5ba0;
case 0x0c0c5ba2u: goto P_0c0c5ba2;
case 0x0c0c5ba4u: goto P_0c0c5ba4;
case 0x0c0c5ba6u: goto P_0c0c5ba6;
case 0x0c0c5ba8u: goto P_0c0c5ba8;
case 0x0c0c5baau: goto P_0c0c5baa;
case 0x0c0c5bacu: goto P_0c0c5bac;
case 0x0c0c5baeu: goto P_0c0c5bae;
case 0x0c0c5bb0u: goto P_0c0c5bb0;
case 0x0c0c5bb2u: goto P_0c0c5bb2;
case 0x0c0c5bb4u: goto P_0c0c5bb4;
case 0x0c0c5bb6u: goto P_0c0c5bb6;
case 0x0c0c5bb8u: goto P_0c0c5bb8;
case 0x0c0c5bbau: goto P_0c0c5bba;
case 0x0c0c7104u: goto P_0c0c7104;
case 0x0c0c7106u: goto P_0c0c7106;
case 0x0c0c7108u: goto P_0c0c7108;
case 0x0c0c710au: goto P_0c0c710a;
case 0x0c0c710cu: goto P_0c0c710c;
case 0x0c0c710eu: goto P_0c0c710e;
case 0x0c0c7110u: goto P_0c0c7110;
case 0x0c0c7112u: goto P_0c0c7112;
case 0x0c0c7114u: goto P_0c0c7114;
case 0x0c0c7116u: goto P_0c0c7116;
case 0x0c0c7118u: goto P_0c0c7118;
case 0x0c0c711au: goto P_0c0c711a;
case 0x0c0c711cu: goto P_0c0c711c;
case 0x0c0c711eu: goto P_0c0c711e;
case 0x0c0c7120u: goto P_0c0c7120;
case 0x0c0c7122u: goto P_0c0c7122;
case 0x0c0c7124u: goto P_0c0c7124;
case 0x0c0c7126u: goto P_0c0c7126;
case 0x0c0c7128u: goto P_0c0c7128;
case 0x0c0c712au: goto P_0c0c712a;
case 0x0c0c712cu: goto P_0c0c712c;
case 0x0c0c712eu: goto P_0c0c712e;
case 0x0c0c7130u: goto P_0c0c7130;
case 0x0c0c7132u: goto P_0c0c7132;
case 0x0c0c7134u: goto P_0c0c7134;
case 0x0c0c7136u: goto P_0c0c7136;
case 0x0c0c7138u: goto P_0c0c7138;
case 0x0c0c713au: goto P_0c0c713a;
case 0x0c0c713cu: goto P_0c0c713c;
case 0x0c0c713eu: goto P_0c0c713e;
case 0x0c0c7140u: goto P_0c0c7140;
case 0x0c0c7142u: goto P_0c0c7142;
case 0x0c0c7144u: goto P_0c0c7144;
case 0x0c0c7146u: goto P_0c0c7146;
case 0x0c0c7148u: goto P_0c0c7148;
case 0x0c0c714au: goto P_0c0c714a;
case 0x0c0c714cu: goto P_0c0c714c;
case 0x0c0c714eu: goto P_0c0c714e;
case 0x0c0c7150u: goto P_0c0c7150;
case 0x0c0c7152u: goto P_0c0c7152;
case 0x0c0c7154u: goto P_0c0c7154;
case 0x0c0c7156u: goto P_0c0c7156;
case 0x0c0c7158u: goto P_0c0c7158;
case 0x0c0c715au: goto P_0c0c715a;
case 0x0c0c715cu: goto P_0c0c715c;
case 0x0c0c715eu: goto P_0c0c715e;
case 0x0c0c7160u: goto P_0c0c7160;
case 0x0c0c7162u: goto P_0c0c7162;
case 0x0c0c7164u: goto P_0c0c7164;
case 0x0c0c7166u: goto P_0c0c7166;
case 0x0c0c7168u: goto P_0c0c7168;
case 0x0c0c716au: goto P_0c0c716a;
case 0x0c0c716cu: goto P_0c0c716c;
case 0x0c0c716eu: goto P_0c0c716e;
case 0x0c0c7170u: goto P_0c0c7170;
case 0x0c0c7172u: goto P_0c0c7172;
case 0x0c0c7174u: goto P_0c0c7174;
case 0x0c0c7176u: goto P_0c0c7176;
case 0x0c0c7178u: goto P_0c0c7178;
case 0x0c0c717au: goto P_0c0c717a;
case 0x0c0c717cu: goto P_0c0c717c;
case 0x0c0c717eu: goto P_0c0c717e;
case 0x0c0c7180u: goto P_0c0c7180;
case 0x0c0c7182u: goto P_0c0c7182;
case 0x0c0c7184u: goto P_0c0c7184;
case 0x0c0c7186u: goto P_0c0c7186;
case 0x0c0c7188u: goto P_0c0c7188;
case 0x0c0c718au: goto P_0c0c718a;
case 0x0c0c718cu: goto P_0c0c718c;
case 0x0c0c718eu: goto P_0c0c718e;
case 0x0c0c7190u: goto P_0c0c7190;
case 0x0c0c7192u: goto P_0c0c7192;
case 0x0c0c7194u: goto P_0c0c7194;
case 0x0c0c7196u: goto P_0c0c7196;
case 0x0c0c7198u: goto P_0c0c7198;
case 0x0c0c719au: goto P_0c0c719a;
case 0x0c0c719cu: goto P_0c0c719c;
case 0x0c0c719eu: goto P_0c0c719e;
case 0x0c0c71a0u: goto P_0c0c71a0;
case 0x0c0c71a2u: goto P_0c0c71a2;
case 0x0c0c71a4u: goto P_0c0c71a4;
case 0x0c0c71a6u: goto P_0c0c71a6;
case 0x0c0c71a8u: goto P_0c0c71a8;
case 0x0c0c71aau: goto P_0c0c71aa;
case 0x0c0c71acu: goto P_0c0c71ac;
case 0x0c0c71aeu: goto P_0c0c71ae;
case 0x0c0c71b0u: goto P_0c0c71b0;
case 0x0c0c71b2u: goto P_0c0c71b2;
case 0x0c0c71b4u: goto P_0c0c71b4;
case 0x0c0c71b6u: goto P_0c0c71b6;
case 0x0c0c71b8u: goto P_0c0c71b8;
case 0x0c0c71bau: goto P_0c0c71ba;
case 0x0c0c71bcu: goto P_0c0c71bc;
case 0x0c0c71beu: goto P_0c0c71be;
case 0x0c0c71c0u: goto P_0c0c71c0;
case 0x0c0c71c2u: goto P_0c0c71c2;
case 0x0c0c71c4u: goto P_0c0c71c4;
case 0x0c0c71c6u: goto P_0c0c71c6;
case 0x0c0c71c8u: goto P_0c0c71c8;
case 0x0c0c71cau: goto P_0c0c71ca;
case 0x0c0c71ccu: goto P_0c0c71cc;
case 0x0c0c71ceu: goto P_0c0c71ce;
case 0x0c0c71d0u: goto P_0c0c71d0;
case 0x0c0c71d2u: goto P_0c0c71d2;
case 0x0c0c71d4u: goto P_0c0c71d4;
case 0x0c0c71d6u: goto P_0c0c71d6;
case 0x0c0c71d8u: goto P_0c0c71d8;
case 0x0c0c71dau: goto P_0c0c71da;
case 0x0c0c71dcu: goto P_0c0c71dc;
case 0x0c0c71deu: goto P_0c0c71de;
case 0x0c0c71e0u: goto P_0c0c71e0;
case 0x0c0c71e2u: goto P_0c0c71e2;
case 0x0c0c71e4u: goto P_0c0c71e4;
case 0x0c0c71e6u: goto P_0c0c71e6;
case 0x0c0c71e8u: goto P_0c0c71e8;
case 0x0c0c71eau: goto P_0c0c71ea;
case 0x0c0c71ecu: goto P_0c0c71ec;
case 0x0c0c721cu: goto P_0c0c721c;
case 0x0c0c721eu: goto P_0c0c721e;
case 0x0c0c7220u: goto P_0c0c7220;
case 0x0c0c7222u: goto P_0c0c7222;
case 0x0c0c7224u: goto P_0c0c7224;
case 0x0c0c7226u: goto P_0c0c7226;
case 0x0c0c7228u: goto P_0c0c7228;
case 0x0c0c722au: goto P_0c0c722a;
case 0x0c0c722cu: goto P_0c0c722c;
case 0x0c0c722eu: goto P_0c0c722e;
case 0x0c0c7230u: goto P_0c0c7230;
case 0x0c0c7232u: goto P_0c0c7232;
case 0x0c0c7234u: goto P_0c0c7234;
case 0x0c0c7236u: goto P_0c0c7236;
case 0x0c0c7238u: goto P_0c0c7238;
case 0x0c0c723au: goto P_0c0c723a;
case 0x0c0c723cu: goto P_0c0c723c;
case 0x0c0c723eu: goto P_0c0c723e;
case 0x0c0c7240u: goto P_0c0c7240;
case 0x0c0c7242u: goto P_0c0c7242;
case 0x0c0c7244u: goto P_0c0c7244;
case 0x0c0c7246u: goto P_0c0c7246;
case 0x0c0c7248u: goto P_0c0c7248;
case 0x0c0c724au: goto P_0c0c724a;
case 0x0c0c724cu: goto P_0c0c724c;
case 0x0c0c724eu: goto P_0c0c724e;
case 0x0c0c7250u: goto P_0c0c7250;
case 0x0c0c7252u: goto P_0c0c7252;
case 0x0c0c7254u: goto P_0c0c7254;
case 0x0c0c7256u: goto P_0c0c7256;
case 0x0c0c7258u: goto P_0c0c7258;
case 0x0c0c725au: goto P_0c0c725a;
case 0x0c0c725cu: goto P_0c0c725c;
case 0x0c0c725eu: goto P_0c0c725e;
case 0x0c0c7260u: goto P_0c0c7260;
case 0x0c0c7262u: goto P_0c0c7262;
case 0x0c0c7264u: goto P_0c0c7264;
case 0x0c0c7266u: goto P_0c0c7266;
case 0x0c0c7268u: goto P_0c0c7268;
case 0x0c0c726au: goto P_0c0c726a;
case 0x0c0c726cu: goto P_0c0c726c;
case 0x0c0c726eu: goto P_0c0c726e;
case 0x0c0c7270u: goto P_0c0c7270;
case 0x0c0c7272u: goto P_0c0c7272;
case 0x0c0c7274u: goto P_0c0c7274;
case 0x0c0c7276u: goto P_0c0c7276;
case 0x0c0c7278u: goto P_0c0c7278;
case 0x0c0c727au: goto P_0c0c727a;
case 0x0c0c727cu: goto P_0c0c727c;
case 0x0c0c727eu: goto P_0c0c727e;
case 0x0c0c7280u: goto P_0c0c7280;
case 0x0c0c7282u: goto P_0c0c7282;
case 0x0c0c7284u: goto P_0c0c7284;
case 0x0c0c7286u: goto P_0c0c7286;
case 0x0c0c7288u: goto P_0c0c7288;
case 0x0c0c728au: goto P_0c0c728a;
case 0x0c0c728cu: goto P_0c0c728c;
case 0x0c0c728eu: goto P_0c0c728e;
case 0x0c0c7290u: goto P_0c0c7290;
case 0x0c0c7292u: goto P_0c0c7292;
case 0x0c0c7294u: goto P_0c0c7294;
case 0x0c0c7296u: goto P_0c0c7296;
case 0x0c0c7298u: goto P_0c0c7298;
case 0x0c0c729au: goto P_0c0c729a;
case 0x0c0c729cu: goto P_0c0c729c;
case 0x0c0c729eu: goto P_0c0c729e;
case 0x0c0c72a0u: goto P_0c0c72a0;
case 0x0c0c72a2u: goto P_0c0c72a2;
case 0x0c0c72a4u: goto P_0c0c72a4;
case 0x0c0c72a6u: goto P_0c0c72a6;
case 0x0c0c72a8u: goto P_0c0c72a8;
case 0x0c0c72aau: goto P_0c0c72aa;
case 0x0c0c72acu: goto P_0c0c72ac;
case 0x0c0c72aeu: goto P_0c0c72ae;
case 0x0c0c72b0u: goto P_0c0c72b0;
case 0x0c0c72b2u: goto P_0c0c72b2;
case 0x0c0c7e00u: goto P_0c0c7e00;
case 0x0c0c7e02u: goto P_0c0c7e02;
case 0x0c0c7e04u: goto P_0c0c7e04;
case 0x0c0c7e06u: goto P_0c0c7e06;
case 0x0c0c7e08u: goto P_0c0c7e08;
case 0x0c0c7e0au: goto P_0c0c7e0a;
case 0x0c0c7e0cu: goto P_0c0c7e0c;
case 0x0c0c7e0eu: goto P_0c0c7e0e;
case 0x0c0c7e10u: goto P_0c0c7e10;
case 0x0c0c7e12u: goto P_0c0c7e12;
case 0x0c0c7e14u: goto P_0c0c7e14;
case 0x0c0c7e16u: goto P_0c0c7e16;
case 0x0c0c7e18u: goto P_0c0c7e18;
case 0x0c0c7e1au: goto P_0c0c7e1a;
case 0x0c0c7e1cu: goto P_0c0c7e1c;
case 0x0c0c7e1eu: goto P_0c0c7e1e;
case 0x0c0c7e20u: goto P_0c0c7e20;
case 0x0c0c7e22u: goto P_0c0c7e22;
case 0x0c0c7e24u: goto P_0c0c7e24;
case 0x0c0c7e26u: goto P_0c0c7e26;
case 0x0c0c7e28u: goto P_0c0c7e28;
case 0x0c0c86dau: goto P_0c0c86da;
case 0x0c0c86dcu: goto P_0c0c86dc;
case 0x0c0c86deu: goto P_0c0c86de;
case 0x0c0c86e0u: goto P_0c0c86e0;
case 0x0c0c86e2u: goto P_0c0c86e2;
case 0x0c0c86e4u: goto P_0c0c86e4;
case 0x0c0c86e6u: goto P_0c0c86e6;
case 0x0c0c86e8u: goto P_0c0c86e8;
case 0x0c0c86eau: goto P_0c0c86ea;
case 0x0c0c86ecu: goto P_0c0c86ec;
case 0x0c0c8be6u: goto P_0c0c8be6;
case 0x0c0c8be8u: goto P_0c0c8be8;
case 0x0c0c8beau: goto P_0c0c8bea;
case 0x0c0c8becu: goto P_0c0c8bec;
case 0x0c0c8beeu: goto P_0c0c8bee;
case 0x0c0c8bf0u: goto P_0c0c8bf0;
case 0x0c0c8bf2u: goto P_0c0c8bf2;
case 0x0c0c8bf4u: goto P_0c0c8bf4;
case 0x0c0c8bf6u: goto P_0c0c8bf6;
case 0x0c0c8bf8u: goto P_0c0c8bf8;
case 0x0c0c8bfau: goto P_0c0c8bfa;
case 0x0c0c8bfcu: goto P_0c0c8bfc;
case 0x0c0c8bfeu: goto P_0c0c8bfe;
case 0x0c0c8c00u: goto P_0c0c8c00;
case 0x0c0c8c02u: goto P_0c0c8c02;
case 0x0c0c8c04u: goto P_0c0c8c04;
case 0x0c0c8c06u: goto P_0c0c8c06;
case 0x0c0c8c08u: goto P_0c0c8c08;
case 0x0c0c8c0au: goto P_0c0c8c0a;
case 0x0c0c8c0cu: goto P_0c0c8c0c;
case 0x0c0c8c0eu: goto P_0c0c8c0e;
case 0x0c0c8c10u: goto P_0c0c8c10;
case 0x0c0c8c12u: goto P_0c0c8c12;
case 0x0c0c8c14u: goto P_0c0c8c14;
case 0x0c0c8c16u: goto P_0c0c8c16;
case 0x0c0c8c18u: goto P_0c0c8c18;
case 0x0c0c8c1au: goto P_0c0c8c1a;
case 0x0c0c8c1cu: goto P_0c0c8c1c;
case 0x0c0c8c1eu: goto P_0c0c8c1e;
case 0x0c0c8c20u: goto P_0c0c8c20;
case 0x0c0c8c22u: goto P_0c0c8c22;
case 0x0c0c8c24u: goto P_0c0c8c24;
case 0x0c0c8c26u: goto P_0c0c8c26;
case 0x0c0c8c28u: goto P_0c0c8c28;
case 0x0c0c8c2au: goto P_0c0c8c2a;
case 0x0c0c8c2cu: goto P_0c0c8c2c;
case 0x0c0c8c2eu: goto P_0c0c8c2e;
case 0x0c0c8c30u: goto P_0c0c8c30;
case 0x0c0c8c32u: goto P_0c0c8c32;
case 0x0c0c8c34u: goto P_0c0c8c34;
case 0x0c0c8c36u: goto P_0c0c8c36;
case 0x0c0c8c38u: goto P_0c0c8c38;
case 0x0c0c8c3au: goto P_0c0c8c3a;
case 0x0c0c8c3cu: goto P_0c0c8c3c;
case 0x0c0c8c3eu: goto P_0c0c8c3e;
case 0x0c0c8c40u: goto P_0c0c8c40;
case 0x0c0c8c42u: goto P_0c0c8c42;
case 0x0c0c8c44u: goto P_0c0c8c44;
case 0x0c0c8c46u: goto P_0c0c8c46;
case 0x0c0c8c48u: goto P_0c0c8c48;
case 0x0c0c8c4au: goto P_0c0c8c4a;
case 0x0c0c8c4cu: goto P_0c0c8c4c;
case 0x0c0c8c4eu: goto P_0c0c8c4e;
case 0x0c0c8c50u: goto P_0c0c8c50;
case 0x0c0c8c52u: goto P_0c0c8c52;
case 0x0c0c8c54u: goto P_0c0c8c54;
case 0x0c0c8c56u: goto P_0c0c8c56;
case 0x0c0c8c58u: goto P_0c0c8c58;
case 0x0c0c8c5au: goto P_0c0c8c5a;
case 0x0c0c9c08u: goto P_0c0c9c08;
case 0x0c0c9c0au: goto P_0c0c9c0a;
case 0x0c0ca32au: goto P_0c0ca32a;
case 0x0c0ca32cu: goto P_0c0ca32c;
case 0x0c0cc44eu: goto P_0c0cc44e;
case 0x0c0cc450u: goto P_0c0cc450;
case 0x0c0cc452u: goto P_0c0cc452;
case 0x0c0cc454u: goto P_0c0cc454;
case 0x0c0cc456u: goto P_0c0cc456;
case 0x0c0cc458u: goto P_0c0cc458;
case 0x0c0cc45au: goto P_0c0cc45a;
case 0x0c0cc45cu: goto P_0c0cc45c;
case 0x0c0cc45eu: goto P_0c0cc45e;
case 0x0c0cc460u: goto P_0c0cc460;
case 0x0c0cc462u: goto P_0c0cc462;
case 0x0c0cc464u: goto P_0c0cc464;
case 0x0c0cc466u: goto P_0c0cc466;
case 0x0c0cc468u: goto P_0c0cc468;
case 0x0c0cc46au: goto P_0c0cc46a;
case 0x0c0cc46cu: goto P_0c0cc46c;
case 0x0c0cc46eu: goto P_0c0cc46e;
case 0x0c0cc470u: goto P_0c0cc470;
case 0x0c0cc472u: goto P_0c0cc472;
case 0x0c0cc474u: goto P_0c0cc474;
case 0x0c0cc476u: goto P_0c0cc476;
case 0x0c0cc478u: goto P_0c0cc478;
case 0x0c0cc47au: goto P_0c0cc47a;
case 0x0c0cc47cu: goto P_0c0cc47c;
case 0x0c0cc47eu: goto P_0c0cc47e;
case 0x0c0cc480u: goto P_0c0cc480;
case 0x0c0cc482u: goto P_0c0cc482;
case 0x0c0cc484u: goto P_0c0cc484;
case 0x0c0cc486u: goto P_0c0cc486;
case 0x0c0cc488u: goto P_0c0cc488;
case 0x0c0cc48au: goto P_0c0cc48a;
case 0x0c0cc48cu: goto P_0c0cc48c;
case 0x0c0cc48eu: goto P_0c0cc48e;
case 0x0c0cc490u: goto P_0c0cc490;
case 0x0c0cc492u: goto P_0c0cc492;
case 0x0c0cc494u: goto P_0c0cc494;
case 0x0c0cc496u: goto P_0c0cc496;
case 0x0c0cc498u: goto P_0c0cc498;
case 0x0c0cc49au: goto P_0c0cc49a;
case 0x0c0cc49cu: goto P_0c0cc49c;
case 0x0c0cc49eu: goto P_0c0cc49e;
case 0x0c0cc4a0u: goto P_0c0cc4a0;
case 0x0c0cc4a2u: goto P_0c0cc4a2;
case 0x0c0cc4a4u: goto P_0c0cc4a4;
case 0x0c0cc4a6u: goto P_0c0cc4a6;
case 0x0c0cc4a8u: goto P_0c0cc4a8;
case 0x0c0cc4aau: goto P_0c0cc4aa;
case 0x0c0cc4acu: goto P_0c0cc4ac;
case 0x0c0cc4aeu: goto P_0c0cc4ae;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0bd8f6: /* original 4f22, guest PC 0x0c0bd8f6 */
if(!s->budget--) { s->failed_pc=0x0c0bd8f6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0bd8f8;
P_0c0bd8f8: /* original 94aa, guest PC 0x0c0bd8f8 */
if(!s->budget--) { s->failed_pc=0x0c0bd8f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda50u,2);
goto P_0c0bd8fa;
P_0c0bd8fa: /* original de72, guest PC 0x0c0bd8fa */
if(!s->budget--) { s->failed_pc=0x0c0bd8fau; return 0; }
r[14]=read(ram,0x0c0bdac4u,4);
goto P_0c0bd8fc;
P_0c0bd8fc: /* original 4e0b, guest PC 0x0c0bd8fc */
if(!s->budget--) { s->failed_pc=0x0c0bd8fcu; return 0; }
target=r[14];
r[16]=0x0c0bd900u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd900u) { target=s->pc; goto dispatch; }
goto P_0c0bd900;
P_0c0bd8fe: /* original 0009, guest PC 0x0c0bd8fe */
if(!s->budget--) { s->failed_pc=0x0c0bd8feu; return 0; }
goto P_0c0bd900;
P_0c0bd900: /* original 94a7, guest PC 0x0c0bd900 */
if(!s->budget--) { s->failed_pc=0x0c0bd900u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda52u,2);
goto P_0c0bd902;
P_0c0bd902: /* original 4e0b, guest PC 0x0c0bd902 */
if(!s->budget--) { s->failed_pc=0x0c0bd902u; return 0; }
target=r[14];
r[16]=0x0c0bd906u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd906u) { target=s->pc; goto dispatch; }
goto P_0c0bd906;
P_0c0bd904: /* original 0009, guest PC 0x0c0bd904 */
if(!s->budget--) { s->failed_pc=0x0c0bd904u; return 0; }
goto P_0c0bd906;
P_0c0bd906: /* original 94a5, guest PC 0x0c0bd906 */
if(!s->budget--) { s->failed_pc=0x0c0bd906u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda54u,2);
goto P_0c0bd908;
P_0c0bd908: /* original 4e0b, guest PC 0x0c0bd908 */
if(!s->budget--) { s->failed_pc=0x0c0bd908u; return 0; }
target=r[14];
r[16]=0x0c0bd90cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd90cu) { target=s->pc; goto dispatch; }
goto P_0c0bd90c;
P_0c0bd90a: /* original 0009, guest PC 0x0c0bd90a */
if(!s->budget--) { s->failed_pc=0x0c0bd90au; return 0; }
goto P_0c0bd90c;
P_0c0bd90c: /* original 94a3, guest PC 0x0c0bd90c */
if(!s->budget--) { s->failed_pc=0x0c0bd90cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda56u,2);
goto P_0c0bd90e;
P_0c0bd90e: /* original 4e0b, guest PC 0x0c0bd90e */
if(!s->budget--) { s->failed_pc=0x0c0bd90eu; return 0; }
target=r[14];
r[16]=0x0c0bd912u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd912u) { target=s->pc; goto dispatch; }
goto P_0c0bd912;
P_0c0bd910: /* original 0009, guest PC 0x0c0bd910 */
if(!s->budget--) { s->failed_pc=0x0c0bd910u; return 0; }
goto P_0c0bd912;
P_0c0bd912: /* original 94a1, guest PC 0x0c0bd912 */
if(!s->budget--) { s->failed_pc=0x0c0bd912u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda58u,2);
goto P_0c0bd914;
P_0c0bd914: /* original 4e0b, guest PC 0x0c0bd914 */
if(!s->budget--) { s->failed_pc=0x0c0bd914u; return 0; }
target=r[14];
r[16]=0x0c0bd918u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd918u) { target=s->pc; goto dispatch; }
goto P_0c0bd918;
P_0c0bd916: /* original 0009, guest PC 0x0c0bd916 */
if(!s->budget--) { s->failed_pc=0x0c0bd916u; return 0; }
goto P_0c0bd918;
P_0c0bd918: /* original 949f, guest PC 0x0c0bd918 */
if(!s->budget--) { s->failed_pc=0x0c0bd918u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda5au,2);
goto P_0c0bd91a;
P_0c0bd91a: /* original 4e0b, guest PC 0x0c0bd91a */
if(!s->budget--) { s->failed_pc=0x0c0bd91au; return 0; }
target=r[14];
r[16]=0x0c0bd91eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd91eu) { target=s->pc; goto dispatch; }
goto P_0c0bd91e;
P_0c0bd91c: /* original 0009, guest PC 0x0c0bd91c */
if(!s->budget--) { s->failed_pc=0x0c0bd91cu; return 0; }
goto P_0c0bd91e;
P_0c0bd91e: /* original 949d, guest PC 0x0c0bd91e */
if(!s->budget--) { s->failed_pc=0x0c0bd91eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda5cu,2);
goto P_0c0bd920;
P_0c0bd920: /* original 4e0b, guest PC 0x0c0bd920 */
if(!s->budget--) { s->failed_pc=0x0c0bd920u; return 0; }
target=r[14];
r[16]=0x0c0bd924u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd924u) { target=s->pc; goto dispatch; }
goto P_0c0bd924;
P_0c0bd922: /* original 0009, guest PC 0x0c0bd922 */
if(!s->budget--) { s->failed_pc=0x0c0bd922u; return 0; }
goto P_0c0bd924;
P_0c0bd924: /* original 949b, guest PC 0x0c0bd924 */
if(!s->budget--) { s->failed_pc=0x0c0bd924u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda5eu,2);
goto P_0c0bd926;
P_0c0bd926: /* original 4e0b, guest PC 0x0c0bd926 */
if(!s->budget--) { s->failed_pc=0x0c0bd926u; return 0; }
target=r[14];
r[16]=0x0c0bd92au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd92au) { target=s->pc; goto dispatch; }
goto P_0c0bd92a;
P_0c0bd928: /* original 0009, guest PC 0x0c0bd928 */
if(!s->budget--) { s->failed_pc=0x0c0bd928u; return 0; }
goto P_0c0bd92a;
P_0c0bd92a: /* original 9499, guest PC 0x0c0bd92a */
if(!s->budget--) { s->failed_pc=0x0c0bd92au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda60u,2);
goto P_0c0bd92c;
P_0c0bd92c: /* original 4e0b, guest PC 0x0c0bd92c */
if(!s->budget--) { s->failed_pc=0x0c0bd92cu; return 0; }
target=r[14];
r[16]=0x0c0bd930u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd930u) { target=s->pc; goto dispatch; }
goto P_0c0bd930;
P_0c0bd92e: /* original 0009, guest PC 0x0c0bd92e */
if(!s->budget--) { s->failed_pc=0x0c0bd92eu; return 0; }
goto P_0c0bd930;
P_0c0bd930: /* original 9497, guest PC 0x0c0bd930 */
if(!s->budget--) { s->failed_pc=0x0c0bd930u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda62u,2);
goto P_0c0bd932;
P_0c0bd932: /* original 4e0b, guest PC 0x0c0bd932 */
if(!s->budget--) { s->failed_pc=0x0c0bd932u; return 0; }
target=r[14];
r[16]=0x0c0bd936u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd936u) { target=s->pc; goto dispatch; }
goto P_0c0bd936;
P_0c0bd934: /* original 0009, guest PC 0x0c0bd934 */
if(!s->budget--) { s->failed_pc=0x0c0bd934u; return 0; }
goto P_0c0bd936;
P_0c0bd936: /* original 9495, guest PC 0x0c0bd936 */
if(!s->budget--) { s->failed_pc=0x0c0bd936u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda64u,2);
goto P_0c0bd938;
P_0c0bd938: /* original 4e0b, guest PC 0x0c0bd938 */
if(!s->budget--) { s->failed_pc=0x0c0bd938u; return 0; }
target=r[14];
r[16]=0x0c0bd93cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd93cu) { target=s->pc; goto dispatch; }
goto P_0c0bd93c;
P_0c0bd93a: /* original 0009, guest PC 0x0c0bd93a */
if(!s->budget--) { s->failed_pc=0x0c0bd93au; return 0; }
goto P_0c0bd93c;
P_0c0bd93c: /* original 9493, guest PC 0x0c0bd93c */
if(!s->budget--) { s->failed_pc=0x0c0bd93cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda66u,2);
goto P_0c0bd93e;
P_0c0bd93e: /* original 4e0b, guest PC 0x0c0bd93e */
if(!s->budget--) { s->failed_pc=0x0c0bd93eu; return 0; }
target=r[14];
r[16]=0x0c0bd942u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd942u) { target=s->pc; goto dispatch; }
goto P_0c0bd942;
P_0c0bd940: /* original 0009, guest PC 0x0c0bd940 */
if(!s->budget--) { s->failed_pc=0x0c0bd940u; return 0; }
goto P_0c0bd942;
P_0c0bd942: /* original 9491, guest PC 0x0c0bd942 */
if(!s->budget--) { s->failed_pc=0x0c0bd942u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda68u,2);
goto P_0c0bd944;
P_0c0bd944: /* original 4e0b, guest PC 0x0c0bd944 */
if(!s->budget--) { s->failed_pc=0x0c0bd944u; return 0; }
target=r[14];
r[16]=0x0c0bd948u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd948u) { target=s->pc; goto dispatch; }
goto P_0c0bd948;
P_0c0bd946: /* original 0009, guest PC 0x0c0bd946 */
if(!s->budget--) { s->failed_pc=0x0c0bd946u; return 0; }
goto P_0c0bd948;
P_0c0bd948: /* original 948f, guest PC 0x0c0bd948 */
if(!s->budget--) { s->failed_pc=0x0c0bd948u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda6au,2);
goto P_0c0bd94a;
P_0c0bd94a: /* original 4e0b, guest PC 0x0c0bd94a */
if(!s->budget--) { s->failed_pc=0x0c0bd94au; return 0; }
target=r[14];
r[16]=0x0c0bd94eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd94eu) { target=s->pc; goto dispatch; }
goto P_0c0bd94e;
P_0c0bd94c: /* original 0009, guest PC 0x0c0bd94c */
if(!s->budget--) { s->failed_pc=0x0c0bd94cu; return 0; }
goto P_0c0bd94e;
P_0c0bd94e: /* original 948d, guest PC 0x0c0bd94e */
if(!s->budget--) { s->failed_pc=0x0c0bd94eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda6cu,2);
goto P_0c0bd950;
P_0c0bd950: /* original 4e0b, guest PC 0x0c0bd950 */
if(!s->budget--) { s->failed_pc=0x0c0bd950u; return 0; }
target=r[14];
r[16]=0x0c0bd954u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd954u) { target=s->pc; goto dispatch; }
goto P_0c0bd954;
P_0c0bd952: /* original 0009, guest PC 0x0c0bd952 */
if(!s->budget--) { s->failed_pc=0x0c0bd952u; return 0; }
goto P_0c0bd954;
P_0c0bd954: /* original 948b, guest PC 0x0c0bd954 */
if(!s->budget--) { s->failed_pc=0x0c0bd954u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda6eu,2);
goto P_0c0bd956;
P_0c0bd956: /* original 4e0b, guest PC 0x0c0bd956 */
if(!s->budget--) { s->failed_pc=0x0c0bd956u; return 0; }
target=r[14];
r[16]=0x0c0bd95au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd95au) { target=s->pc; goto dispatch; }
goto P_0c0bd95a;
P_0c0bd958: /* original 0009, guest PC 0x0c0bd958 */
if(!s->budget--) { s->failed_pc=0x0c0bd958u; return 0; }
goto P_0c0bd95a;
P_0c0bd95a: /* original 9489, guest PC 0x0c0bd95a */
if(!s->budget--) { s->failed_pc=0x0c0bd95au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda70u,2);
goto P_0c0bd95c;
P_0c0bd95c: /* original 4e0b, guest PC 0x0c0bd95c */
if(!s->budget--) { s->failed_pc=0x0c0bd95cu; return 0; }
target=r[14];
r[16]=0x0c0bd960u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd960u) { target=s->pc; goto dispatch; }
goto P_0c0bd960;
P_0c0bd95e: /* original 0009, guest PC 0x0c0bd95e */
if(!s->budget--) { s->failed_pc=0x0c0bd95eu; return 0; }
goto P_0c0bd960;
P_0c0bd960: /* original 9487, guest PC 0x0c0bd960 */
if(!s->budget--) { s->failed_pc=0x0c0bd960u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda72u,2);
goto P_0c0bd962;
P_0c0bd962: /* original 4e0b, guest PC 0x0c0bd962 */
if(!s->budget--) { s->failed_pc=0x0c0bd962u; return 0; }
target=r[14];
r[16]=0x0c0bd966u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd966u) { target=s->pc; goto dispatch; }
goto P_0c0bd966;
P_0c0bd964: /* original 0009, guest PC 0x0c0bd964 */
if(!s->budget--) { s->failed_pc=0x0c0bd964u; return 0; }
goto P_0c0bd966;
P_0c0bd966: /* original 9485, guest PC 0x0c0bd966 */
if(!s->budget--) { s->failed_pc=0x0c0bd966u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda74u,2);
goto P_0c0bd968;
P_0c0bd968: /* original 4e0b, guest PC 0x0c0bd968 */
if(!s->budget--) { s->failed_pc=0x0c0bd968u; return 0; }
target=r[14];
r[16]=0x0c0bd96cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd96cu) { target=s->pc; goto dispatch; }
goto P_0c0bd96c;
P_0c0bd96a: /* original 0009, guest PC 0x0c0bd96a */
if(!s->budget--) { s->failed_pc=0x0c0bd96au; return 0; }
goto P_0c0bd96c;
P_0c0bd96c: /* original 9483, guest PC 0x0c0bd96c */
if(!s->budget--) { s->failed_pc=0x0c0bd96cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda76u,2);
goto P_0c0bd96e;
P_0c0bd96e: /* original 4e0b, guest PC 0x0c0bd96e */
if(!s->budget--) { s->failed_pc=0x0c0bd96eu; return 0; }
target=r[14];
r[16]=0x0c0bd972u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd972u) { target=s->pc; goto dispatch; }
goto P_0c0bd972;
P_0c0bd970: /* original 0009, guest PC 0x0c0bd970 */
if(!s->budget--) { s->failed_pc=0x0c0bd970u; return 0; }
goto P_0c0bd972;
P_0c0bd972: /* original 9481, guest PC 0x0c0bd972 */
if(!s->budget--) { s->failed_pc=0x0c0bd972u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda78u,2);
goto P_0c0bd974;
P_0c0bd974: /* original 4e0b, guest PC 0x0c0bd974 */
if(!s->budget--) { s->failed_pc=0x0c0bd974u; return 0; }
target=r[14];
r[16]=0x0c0bd978u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd978u) { target=s->pc; goto dispatch; }
goto P_0c0bd978;
P_0c0bd976: /* original 0009, guest PC 0x0c0bd976 */
if(!s->budget--) { s->failed_pc=0x0c0bd976u; return 0; }
goto P_0c0bd978;
P_0c0bd978: /* original 947f, guest PC 0x0c0bd978 */
if(!s->budget--) { s->failed_pc=0x0c0bd978u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda7au,2);
goto P_0c0bd97a;
P_0c0bd97a: /* original 4e0b, guest PC 0x0c0bd97a */
if(!s->budget--) { s->failed_pc=0x0c0bd97au; return 0; }
target=r[14];
r[16]=0x0c0bd97eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd97eu) { target=s->pc; goto dispatch; }
goto P_0c0bd97e;
P_0c0bd97c: /* original 0009, guest PC 0x0c0bd97c */
if(!s->budget--) { s->failed_pc=0x0c0bd97cu; return 0; }
goto P_0c0bd97e;
P_0c0bd97e: /* original 947d, guest PC 0x0c0bd97e */
if(!s->budget--) { s->failed_pc=0x0c0bd97eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda7cu,2);
goto P_0c0bd980;
P_0c0bd980: /* original 4e0b, guest PC 0x0c0bd980 */
if(!s->budget--) { s->failed_pc=0x0c0bd980u; return 0; }
target=r[14];
r[16]=0x0c0bd984u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd984u) { target=s->pc; goto dispatch; }
goto P_0c0bd984;
P_0c0bd982: /* original 0009, guest PC 0x0c0bd982 */
if(!s->budget--) { s->failed_pc=0x0c0bd982u; return 0; }
goto P_0c0bd984;
P_0c0bd984: /* original 947b, guest PC 0x0c0bd984 */
if(!s->budget--) { s->failed_pc=0x0c0bd984u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda7eu,2);
goto P_0c0bd986;
P_0c0bd986: /* original 4e0b, guest PC 0x0c0bd986 */
if(!s->budget--) { s->failed_pc=0x0c0bd986u; return 0; }
target=r[14];
r[16]=0x0c0bd98au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd98au) { target=s->pc; goto dispatch; }
goto P_0c0bd98a;
P_0c0bd988: /* original 0009, guest PC 0x0c0bd988 */
if(!s->budget--) { s->failed_pc=0x0c0bd988u; return 0; }
goto P_0c0bd98a;
P_0c0bd98a: /* original 9479, guest PC 0x0c0bd98a */
if(!s->budget--) { s->failed_pc=0x0c0bd98au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda80u,2);
goto P_0c0bd98c;
P_0c0bd98c: /* original 4e0b, guest PC 0x0c0bd98c */
if(!s->budget--) { s->failed_pc=0x0c0bd98cu; return 0; }
target=r[14];
r[16]=0x0c0bd990u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd990u) { target=s->pc; goto dispatch; }
goto P_0c0bd990;
P_0c0bd98e: /* original 0009, guest PC 0x0c0bd98e */
if(!s->budget--) { s->failed_pc=0x0c0bd98eu; return 0; }
goto P_0c0bd990;
P_0c0bd990: /* original 9477, guest PC 0x0c0bd990 */
if(!s->budget--) { s->failed_pc=0x0c0bd990u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda82u,2);
goto P_0c0bd992;
P_0c0bd992: /* original 4e0b, guest PC 0x0c0bd992 */
if(!s->budget--) { s->failed_pc=0x0c0bd992u; return 0; }
target=r[14];
r[16]=0x0c0bd996u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd996u) { target=s->pc; goto dispatch; }
goto P_0c0bd996;
P_0c0bd994: /* original 0009, guest PC 0x0c0bd994 */
if(!s->budget--) { s->failed_pc=0x0c0bd994u; return 0; }
goto P_0c0bd996;
P_0c0bd996: /* original 9475, guest PC 0x0c0bd996 */
if(!s->budget--) { s->failed_pc=0x0c0bd996u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda84u,2);
goto P_0c0bd998;
P_0c0bd998: /* original 4e0b, guest PC 0x0c0bd998 */
if(!s->budget--) { s->failed_pc=0x0c0bd998u; return 0; }
target=r[14];
r[16]=0x0c0bd99cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd99cu) { target=s->pc; goto dispatch; }
goto P_0c0bd99c;
P_0c0bd99a: /* original 0009, guest PC 0x0c0bd99a */
if(!s->budget--) { s->failed_pc=0x0c0bd99au; return 0; }
goto P_0c0bd99c;
P_0c0bd99c: /* original 9473, guest PC 0x0c0bd99c */
if(!s->budget--) { s->failed_pc=0x0c0bd99cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda86u,2);
goto P_0c0bd99e;
P_0c0bd99e: /* original 4e0b, guest PC 0x0c0bd99e */
if(!s->budget--) { s->failed_pc=0x0c0bd99eu; return 0; }
target=r[14];
r[16]=0x0c0bd9a2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd9a2u) { target=s->pc; goto dispatch; }
goto P_0c0bd9a2;
P_0c0bd9a0: /* original 0009, guest PC 0x0c0bd9a0 */
if(!s->budget--) { s->failed_pc=0x0c0bd9a0u; return 0; }
goto P_0c0bd9a2;
P_0c0bd9a2: /* original 9471, guest PC 0x0c0bd9a2 */
if(!s->budget--) { s->failed_pc=0x0c0bd9a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda88u,2);
goto P_0c0bd9a4;
P_0c0bd9a4: /* original 4e0b, guest PC 0x0c0bd9a4 */
if(!s->budget--) { s->failed_pc=0x0c0bd9a4u; return 0; }
target=r[14];
r[16]=0x0c0bd9a8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd9a8u) { target=s->pc; goto dispatch; }
goto P_0c0bd9a8;
P_0c0bd9a6: /* original 0009, guest PC 0x0c0bd9a6 */
if(!s->budget--) { s->failed_pc=0x0c0bd9a6u; return 0; }
goto P_0c0bd9a8;
P_0c0bd9a8: /* original 946f, guest PC 0x0c0bd9a8 */
if(!s->budget--) { s->failed_pc=0x0c0bd9a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda8au,2);
goto P_0c0bd9aa;
P_0c0bd9aa: /* original 4e0b, guest PC 0x0c0bd9aa */
if(!s->budget--) { s->failed_pc=0x0c0bd9aau; return 0; }
target=r[14];
r[16]=0x0c0bd9aeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd9aeu) { target=s->pc; goto dispatch; }
goto P_0c0bd9ae;
P_0c0bd9ac: /* original 0009, guest PC 0x0c0bd9ac */
if(!s->budget--) { s->failed_pc=0x0c0bd9acu; return 0; }
goto P_0c0bd9ae;
P_0c0bd9ae: /* original 946d, guest PC 0x0c0bd9ae */
if(!s->budget--) { s->failed_pc=0x0c0bd9aeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda8cu,2);
goto P_0c0bd9b0;
P_0c0bd9b0: /* original 4e0b, guest PC 0x0c0bd9b0 */
if(!s->budget--) { s->failed_pc=0x0c0bd9b0u; return 0; }
target=r[14];
r[16]=0x0c0bd9b4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd9b4u) { target=s->pc; goto dispatch; }
goto P_0c0bd9b4;
P_0c0bd9b2: /* original 0009, guest PC 0x0c0bd9b2 */
if(!s->budget--) { s->failed_pc=0x0c0bd9b2u; return 0; }
goto P_0c0bd9b4;
P_0c0bd9b4: /* original 946b, guest PC 0x0c0bd9b4 */
if(!s->budget--) { s->failed_pc=0x0c0bd9b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda8eu,2);
goto P_0c0bd9b6;
P_0c0bd9b6: /* original 4e0b, guest PC 0x0c0bd9b6 */
if(!s->budget--) { s->failed_pc=0x0c0bd9b6u; return 0; }
target=r[14];
r[16]=0x0c0bd9bau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd9bau) { target=s->pc; goto dispatch; }
goto P_0c0bd9ba;
P_0c0bd9b8: /* original 0009, guest PC 0x0c0bd9b8 */
if(!s->budget--) { s->failed_pc=0x0c0bd9b8u; return 0; }
goto P_0c0bd9ba;
P_0c0bd9ba: /* original 9469, guest PC 0x0c0bd9ba */
if(!s->budget--) { s->failed_pc=0x0c0bd9bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda90u,2);
goto P_0c0bd9bc;
P_0c0bd9bc: /* original 4e0b, guest PC 0x0c0bd9bc */
if(!s->budget--) { s->failed_pc=0x0c0bd9bcu; return 0; }
target=r[14];
r[16]=0x0c0bd9c0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd9c0u) { target=s->pc; goto dispatch; }
goto P_0c0bd9c0;
P_0c0bd9be: /* original 0009, guest PC 0x0c0bd9be */
if(!s->budget--) { s->failed_pc=0x0c0bd9beu; return 0; }
goto P_0c0bd9c0;
P_0c0bd9c0: /* original 9467, guest PC 0x0c0bd9c0 */
if(!s->budget--) { s->failed_pc=0x0c0bd9c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda92u,2);
goto P_0c0bd9c2;
P_0c0bd9c2: /* original 4e0b, guest PC 0x0c0bd9c2 */
if(!s->budget--) { s->failed_pc=0x0c0bd9c2u; return 0; }
target=r[14];
r[16]=0x0c0bd9c6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd9c6u) { target=s->pc; goto dispatch; }
goto P_0c0bd9c6;
P_0c0bd9c4: /* original 0009, guest PC 0x0c0bd9c4 */
if(!s->budget--) { s->failed_pc=0x0c0bd9c4u; return 0; }
goto P_0c0bd9c6;
P_0c0bd9c6: /* original 9465, guest PC 0x0c0bd9c6 */
if(!s->budget--) { s->failed_pc=0x0c0bd9c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda94u,2);
goto P_0c0bd9c8;
P_0c0bd9c8: /* original 4e0b, guest PC 0x0c0bd9c8 */
if(!s->budget--) { s->failed_pc=0x0c0bd9c8u; return 0; }
target=r[14];
r[16]=0x0c0bd9ccu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd9ccu) { target=s->pc; goto dispatch; }
goto P_0c0bd9cc;
P_0c0bd9ca: /* original 0009, guest PC 0x0c0bd9ca */
if(!s->budget--) { s->failed_pc=0x0c0bd9cau; return 0; }
goto P_0c0bd9cc;
P_0c0bd9cc: /* original 9463, guest PC 0x0c0bd9cc */
if(!s->budget--) { s->failed_pc=0x0c0bd9ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda96u,2);
goto P_0c0bd9ce;
P_0c0bd9ce: /* original 4e0b, guest PC 0x0c0bd9ce */
if(!s->budget--) { s->failed_pc=0x0c0bd9ceu; return 0; }
target=r[14];
r[16]=0x0c0bd9d2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd9d2u) { target=s->pc; goto dispatch; }
goto P_0c0bd9d2;
P_0c0bd9d0: /* original 0009, guest PC 0x0c0bd9d0 */
if(!s->budget--) { s->failed_pc=0x0c0bd9d0u; return 0; }
goto P_0c0bd9d2;
P_0c0bd9d2: /* original 9461, guest PC 0x0c0bd9d2 */
if(!s->budget--) { s->failed_pc=0x0c0bd9d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda98u,2);
goto P_0c0bd9d4;
P_0c0bd9d4: /* original 4e0b, guest PC 0x0c0bd9d4 */
if(!s->budget--) { s->failed_pc=0x0c0bd9d4u; return 0; }
target=r[14];
r[16]=0x0c0bd9d8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd9d8u) { target=s->pc; goto dispatch; }
goto P_0c0bd9d8;
P_0c0bd9d6: /* original 0009, guest PC 0x0c0bd9d6 */
if(!s->budget--) { s->failed_pc=0x0c0bd9d6u; return 0; }
goto P_0c0bd9d8;
P_0c0bd9d8: /* original 945f, guest PC 0x0c0bd9d8 */
if(!s->budget--) { s->failed_pc=0x0c0bd9d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda9au,2);
goto P_0c0bd9da;
P_0c0bd9da: /* original 4e0b, guest PC 0x0c0bd9da */
if(!s->budget--) { s->failed_pc=0x0c0bd9dau; return 0; }
target=r[14];
r[16]=0x0c0bd9deu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd9deu) { target=s->pc; goto dispatch; }
goto P_0c0bd9de;
P_0c0bd9dc: /* original 0009, guest PC 0x0c0bd9dc */
if(!s->budget--) { s->failed_pc=0x0c0bd9dcu; return 0; }
goto P_0c0bd9de;
P_0c0bd9de: /* original 945d, guest PC 0x0c0bd9de */
if(!s->budget--) { s->failed_pc=0x0c0bd9deu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda9cu,2);
goto P_0c0bd9e0;
P_0c0bd9e0: /* original 4e0b, guest PC 0x0c0bd9e0 */
if(!s->budget--) { s->failed_pc=0x0c0bd9e0u; return 0; }
target=r[14];
r[16]=0x0c0bd9e4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd9e4u) { target=s->pc; goto dispatch; }
goto P_0c0bd9e4;
P_0c0bd9e2: /* original 0009, guest PC 0x0c0bd9e2 */
if(!s->budget--) { s->failed_pc=0x0c0bd9e2u; return 0; }
goto P_0c0bd9e4;
P_0c0bd9e4: /* original 945b, guest PC 0x0c0bd9e4 */
if(!s->budget--) { s->failed_pc=0x0c0bd9e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bda9eu,2);
goto P_0c0bd9e6;
P_0c0bd9e6: /* original 4e0b, guest PC 0x0c0bd9e6 */
if(!s->budget--) { s->failed_pc=0x0c0bd9e6u; return 0; }
target=r[14];
r[16]=0x0c0bd9eau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd9eau) { target=s->pc; goto dispatch; }
goto P_0c0bd9ea;
P_0c0bd9e8: /* original 0009, guest PC 0x0c0bd9e8 */
if(!s->budget--) { s->failed_pc=0x0c0bd9e8u; return 0; }
goto P_0c0bd9ea;
P_0c0bd9ea: /* original 9459, guest PC 0x0c0bd9ea */
if(!s->budget--) { s->failed_pc=0x0c0bd9eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdaa0u,2);
goto P_0c0bd9ec;
P_0c0bd9ec: /* original 4e0b, guest PC 0x0c0bd9ec */
if(!s->budget--) { s->failed_pc=0x0c0bd9ecu; return 0; }
target=r[14];
r[16]=0x0c0bd9f0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd9f0u) { target=s->pc; goto dispatch; }
goto P_0c0bd9f0;
P_0c0bd9ee: /* original 0009, guest PC 0x0c0bd9ee */
if(!s->budget--) { s->failed_pc=0x0c0bd9eeu; return 0; }
goto P_0c0bd9f0;
P_0c0bd9f0: /* original 9457, guest PC 0x0c0bd9f0 */
if(!s->budget--) { s->failed_pc=0x0c0bd9f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdaa2u,2);
goto P_0c0bd9f2;
P_0c0bd9f2: /* original 4e0b, guest PC 0x0c0bd9f2 */
if(!s->budget--) { s->failed_pc=0x0c0bd9f2u; return 0; }
target=r[14];
r[16]=0x0c0bd9f6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd9f6u) { target=s->pc; goto dispatch; }
goto P_0c0bd9f6;
P_0c0bd9f4: /* original 0009, guest PC 0x0c0bd9f4 */
if(!s->budget--) { s->failed_pc=0x0c0bd9f4u; return 0; }
goto P_0c0bd9f6;
P_0c0bd9f6: /* original 9455, guest PC 0x0c0bd9f6 */
if(!s->budget--) { s->failed_pc=0x0c0bd9f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdaa4u,2);
goto P_0c0bd9f8;
P_0c0bd9f8: /* original 4e0b, guest PC 0x0c0bd9f8 */
if(!s->budget--) { s->failed_pc=0x0c0bd9f8u; return 0; }
target=r[14];
r[16]=0x0c0bd9fcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bd9fcu) { target=s->pc; goto dispatch; }
goto P_0c0bd9fc;
P_0c0bd9fa: /* original 0009, guest PC 0x0c0bd9fa */
if(!s->budget--) { s->failed_pc=0x0c0bd9fau; return 0; }
goto P_0c0bd9fc;
P_0c0bd9fc: /* original 9453, guest PC 0x0c0bd9fc */
if(!s->budget--) { s->failed_pc=0x0c0bd9fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdaa6u,2);
goto P_0c0bd9fe;
P_0c0bd9fe: /* original 4e0b, guest PC 0x0c0bd9fe */
if(!s->budget--) { s->failed_pc=0x0c0bd9feu; return 0; }
target=r[14];
r[16]=0x0c0bda02u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bda02u) { target=s->pc; goto dispatch; }
goto P_0c0bda02;
P_0c0bda00: /* original 0009, guest PC 0x0c0bda00 */
if(!s->budget--) { s->failed_pc=0x0c0bda00u; return 0; }
goto P_0c0bda02;
P_0c0bda02: /* original 9451, guest PC 0x0c0bda02 */
if(!s->budget--) { s->failed_pc=0x0c0bda02u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdaa8u,2);
goto P_0c0bda04;
P_0c0bda04: /* original 4e0b, guest PC 0x0c0bda04 */
if(!s->budget--) { s->failed_pc=0x0c0bda04u; return 0; }
target=r[14];
r[16]=0x0c0bda08u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bda08u) { target=s->pc; goto dispatch; }
goto P_0c0bda08;
P_0c0bda06: /* original 0009, guest PC 0x0c0bda06 */
if(!s->budget--) { s->failed_pc=0x0c0bda06u; return 0; }
goto P_0c0bda08;
P_0c0bda08: /* original 944f, guest PC 0x0c0bda08 */
if(!s->budget--) { s->failed_pc=0x0c0bda08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdaaau,2);
goto P_0c0bda0a;
P_0c0bda0a: /* original 4e0b, guest PC 0x0c0bda0a */
if(!s->budget--) { s->failed_pc=0x0c0bda0au; return 0; }
target=r[14];
r[16]=0x0c0bda0eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bda0eu) { target=s->pc; goto dispatch; }
goto P_0c0bda0e;
P_0c0bda0c: /* original 0009, guest PC 0x0c0bda0c */
if(!s->budget--) { s->failed_pc=0x0c0bda0cu; return 0; }
goto P_0c0bda0e;
P_0c0bda0e: /* original 944d, guest PC 0x0c0bda0e */
if(!s->budget--) { s->failed_pc=0x0c0bda0eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdaacu,2);
goto P_0c0bda10;
P_0c0bda10: /* original 4e0b, guest PC 0x0c0bda10 */
if(!s->budget--) { s->failed_pc=0x0c0bda10u; return 0; }
target=r[14];
r[16]=0x0c0bda14u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bda14u) { target=s->pc; goto dispatch; }
goto P_0c0bda14;
P_0c0bda12: /* original 0009, guest PC 0x0c0bda12 */
if(!s->budget--) { s->failed_pc=0x0c0bda12u; return 0; }
goto P_0c0bda14;
P_0c0bda14: /* original 944b, guest PC 0x0c0bda14 */
if(!s->budget--) { s->failed_pc=0x0c0bda14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdaaeu,2);
goto P_0c0bda16;
P_0c0bda16: /* original 4e0b, guest PC 0x0c0bda16 */
if(!s->budget--) { s->failed_pc=0x0c0bda16u; return 0; }
target=r[14];
r[16]=0x0c0bda1au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bda1au) { target=s->pc; goto dispatch; }
goto P_0c0bda1a;
P_0c0bda18: /* original 0009, guest PC 0x0c0bda18 */
if(!s->budget--) { s->failed_pc=0x0c0bda18u; return 0; }
goto P_0c0bda1a;
P_0c0bda1a: /* original 9449, guest PC 0x0c0bda1a */
if(!s->budget--) { s->failed_pc=0x0c0bda1au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdab0u,2);
goto P_0c0bda1c;
P_0c0bda1c: /* original 4e0b, guest PC 0x0c0bda1c */
if(!s->budget--) { s->failed_pc=0x0c0bda1cu; return 0; }
target=r[14];
r[16]=0x0c0bda20u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bda20u) { target=s->pc; goto dispatch; }
goto P_0c0bda20;
P_0c0bda1e: /* original 0009, guest PC 0x0c0bda1e */
if(!s->budget--) { s->failed_pc=0x0c0bda1eu; return 0; }
goto P_0c0bda20;
P_0c0bda20: /* original 9447, guest PC 0x0c0bda20 */
if(!s->budget--) { s->failed_pc=0x0c0bda20u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdab2u,2);
goto P_0c0bda22;
P_0c0bda22: /* original 4e0b, guest PC 0x0c0bda22 */
if(!s->budget--) { s->failed_pc=0x0c0bda22u; return 0; }
target=r[14];
r[16]=0x0c0bda26u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bda26u) { target=s->pc; goto dispatch; }
goto P_0c0bda26;
P_0c0bda24: /* original 0009, guest PC 0x0c0bda24 */
if(!s->budget--) { s->failed_pc=0x0c0bda24u; return 0; }
goto P_0c0bda26;
P_0c0bda26: /* original 9445, guest PC 0x0c0bda26 */
if(!s->budget--) { s->failed_pc=0x0c0bda26u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdab4u,2);
goto P_0c0bda28;
P_0c0bda28: /* original 4e0b, guest PC 0x0c0bda28 */
if(!s->budget--) { s->failed_pc=0x0c0bda28u; return 0; }
target=r[14];
r[16]=0x0c0bda2cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bda2cu) { target=s->pc; goto dispatch; }
goto P_0c0bda2c;
P_0c0bda2a: /* original 0009, guest PC 0x0c0bda2a */
if(!s->budget--) { s->failed_pc=0x0c0bda2au; return 0; }
goto P_0c0bda2c;
P_0c0bda2c: /* original 9443, guest PC 0x0c0bda2c */
if(!s->budget--) { s->failed_pc=0x0c0bda2cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdab6u,2);
goto P_0c0bda2e;
P_0c0bda2e: /* original 4e0b, guest PC 0x0c0bda2e */
if(!s->budget--) { s->failed_pc=0x0c0bda2eu; return 0; }
target=r[14];
r[16]=0x0c0bda32u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bda32u) { target=s->pc; goto dispatch; }
goto P_0c0bda32;
P_0c0bda30: /* original 0009, guest PC 0x0c0bda30 */
if(!s->budget--) { s->failed_pc=0x0c0bda30u; return 0; }
goto P_0c0bda32;
P_0c0bda32: /* original 9441, guest PC 0x0c0bda32 */
if(!s->budget--) { s->failed_pc=0x0c0bda32u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdab8u,2);
goto P_0c0bda34;
P_0c0bda34: /* original 4e0b, guest PC 0x0c0bda34 */
if(!s->budget--) { s->failed_pc=0x0c0bda34u; return 0; }
target=r[14];
r[16]=0x0c0bda38u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bda38u) { target=s->pc; goto dispatch; }
goto P_0c0bda38;
P_0c0bda36: /* original 0009, guest PC 0x0c0bda36 */
if(!s->budget--) { s->failed_pc=0x0c0bda36u; return 0; }
goto P_0c0bda38;
P_0c0bda38: /* original 943f, guest PC 0x0c0bda38 */
if(!s->budget--) { s->failed_pc=0x0c0bda38u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdabau,2);
goto P_0c0bda3a;
P_0c0bda3a: /* original 4e0b, guest PC 0x0c0bda3a */
if(!s->budget--) { s->failed_pc=0x0c0bda3au; return 0; }
target=r[14];
r[16]=0x0c0bda3eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bda3eu) { target=s->pc; goto dispatch; }
goto P_0c0bda3e;
P_0c0bda3c: /* original 0009, guest PC 0x0c0bda3c */
if(!s->budget--) { s->failed_pc=0x0c0bda3cu; return 0; }
goto P_0c0bda3e;
P_0c0bda3e: /* original 943d, guest PC 0x0c0bda3e */
if(!s->budget--) { s->failed_pc=0x0c0bda3eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdabcu,2);
goto P_0c0bda40;
P_0c0bda40: /* original 4e0b, guest PC 0x0c0bda40 */
if(!s->budget--) { s->failed_pc=0x0c0bda40u; return 0; }
target=r[14];
r[16]=0x0c0bda44u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bda44u) { target=s->pc; goto dispatch; }
goto P_0c0bda44;
P_0c0bda42: /* original 0009, guest PC 0x0c0bda42 */
if(!s->budget--) { s->failed_pc=0x0c0bda42u; return 0; }
goto P_0c0bda44;
P_0c0bda44: /* original 943b, guest PC 0x0c0bda44 */
if(!s->budget--) { s->failed_pc=0x0c0bda44u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdabeu,2);
goto P_0c0bda46;
P_0c0bda46: /* original 4e0b, guest PC 0x0c0bda46 */
if(!s->budget--) { s->failed_pc=0x0c0bda46u; return 0; }
target=r[14];
r[16]=0x0c0bda4au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bda4au) { target=s->pc; goto dispatch; }
goto P_0c0bda4a;
P_0c0bda48: /* original 0009, guest PC 0x0c0bda48 */
if(!s->budget--) { s->failed_pc=0x0c0bda48u; return 0; }
goto P_0c0bda4a;
P_0c0bda4a: /* original 9439, guest PC 0x0c0bda4a */
if(!s->budget--) { s->failed_pc=0x0c0bda4au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdac0u,2);
goto P_0c0bda4c;
P_0c0bda4c: /* original a03c, guest PC 0x0c0bda4c */
if(!s->budget--) { s->failed_pc=0x0c0bda4cu; return 0; }
goto P_0c0bdac8;
P_0c0bda4e: /* original 0009, guest PC 0x0c0bda4e */
if(!s->budget--) { s->failed_pc=0x0c0bda4eu; return 0; }
return vf3_matrix_family(0x0c0bda50u,s,ram);
P_0c0bdac8: /* original 4e0b, guest PC 0x0c0bdac8 */
if(!s->budget--) { s->failed_pc=0x0c0bdac8u; return 0; }
target=r[14];
r[16]=0x0c0bdaccu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdaccu) { target=s->pc; goto dispatch; }
goto P_0c0bdacc;
P_0c0bdaca: /* original 0009, guest PC 0x0c0bdaca */
if(!s->budget--) { s->failed_pc=0x0c0bdacau; return 0; }
goto P_0c0bdacc;
P_0c0bdacc: /* original 9485, guest PC 0x0c0bdacc */
if(!s->budget--) { s->failed_pc=0x0c0bdaccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdbdau,2);
goto P_0c0bdace;
P_0c0bdace: /* original 4e0b, guest PC 0x0c0bdace */
if(!s->budget--) { s->failed_pc=0x0c0bdaceu; return 0; }
target=r[14];
r[16]=0x0c0bdad2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdad2u) { target=s->pc; goto dispatch; }
goto P_0c0bdad2;
P_0c0bdad0: /* original 0009, guest PC 0x0c0bdad0 */
if(!s->budget--) { s->failed_pc=0x0c0bdad0u; return 0; }
goto P_0c0bdad2;
P_0c0bdad2: /* original 9483, guest PC 0x0c0bdad2 */
if(!s->budget--) { s->failed_pc=0x0c0bdad2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdbdcu,2);
goto P_0c0bdad4;
P_0c0bdad4: /* original 4e0b, guest PC 0x0c0bdad4 */
if(!s->budget--) { s->failed_pc=0x0c0bdad4u; return 0; }
target=r[14];
r[16]=0x0c0bdad8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdad8u) { target=s->pc; goto dispatch; }
goto P_0c0bdad8;
P_0c0bdad6: /* original 0009, guest PC 0x0c0bdad6 */
if(!s->budget--) { s->failed_pc=0x0c0bdad6u; return 0; }
goto P_0c0bdad8;
P_0c0bdad8: /* original 9481, guest PC 0x0c0bdad8 */
if(!s->budget--) { s->failed_pc=0x0c0bdad8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdbdeu,2);
goto P_0c0bdada;
P_0c0bdada: /* original 4e0b, guest PC 0x0c0bdada */
if(!s->budget--) { s->failed_pc=0x0c0bdadau; return 0; }
target=r[14];
r[16]=0x0c0bdadeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdadeu) { target=s->pc; goto dispatch; }
goto P_0c0bdade;
P_0c0bdadc: /* original 0009, guest PC 0x0c0bdadc */
if(!s->budget--) { s->failed_pc=0x0c0bdadcu; return 0; }
goto P_0c0bdade;
P_0c0bdade: /* original 947f, guest PC 0x0c0bdade */
if(!s->budget--) { s->failed_pc=0x0c0bdadeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdbe0u,2);
goto P_0c0bdae0;
P_0c0bdae0: /* original 4e0b, guest PC 0x0c0bdae0 */
if(!s->budget--) { s->failed_pc=0x0c0bdae0u; return 0; }
target=r[14];
r[16]=0x0c0bdae4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdae4u) { target=s->pc; goto dispatch; }
goto P_0c0bdae4;
P_0c0bdae2: /* original 0009, guest PC 0x0c0bdae2 */
if(!s->budget--) { s->failed_pc=0x0c0bdae2u; return 0; }
goto P_0c0bdae4;
P_0c0bdae4: /* original 947d, guest PC 0x0c0bdae4 */
if(!s->budget--) { s->failed_pc=0x0c0bdae4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdbe2u,2);
goto P_0c0bdae6;
P_0c0bdae6: /* original 4e0b, guest PC 0x0c0bdae6 */
if(!s->budget--) { s->failed_pc=0x0c0bdae6u; return 0; }
target=r[14];
r[16]=0x0c0bdaeau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdaeau) { target=s->pc; goto dispatch; }
goto P_0c0bdaea;
P_0c0bdae8: /* original 0009, guest PC 0x0c0bdae8 */
if(!s->budget--) { s->failed_pc=0x0c0bdae8u; return 0; }
goto P_0c0bdaea;
P_0c0bdaea: /* original 947b, guest PC 0x0c0bdaea */
if(!s->budget--) { s->failed_pc=0x0c0bdaeau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdbe4u,2);
goto P_0c0bdaec;
P_0c0bdaec: /* original 4e0b, guest PC 0x0c0bdaec */
if(!s->budget--) { s->failed_pc=0x0c0bdaecu; return 0; }
target=r[14];
r[16]=0x0c0bdaf0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdaf0u) { target=s->pc; goto dispatch; }
goto P_0c0bdaf0;
P_0c0bdaee: /* original 0009, guest PC 0x0c0bdaee */
if(!s->budget--) { s->failed_pc=0x0c0bdaeeu; return 0; }
goto P_0c0bdaf0;
P_0c0bdaf0: /* original 9479, guest PC 0x0c0bdaf0 */
if(!s->budget--) { s->failed_pc=0x0c0bdaf0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdbe6u,2);
goto P_0c0bdaf2;
P_0c0bdaf2: /* original 4e0b, guest PC 0x0c0bdaf2 */
if(!s->budget--) { s->failed_pc=0x0c0bdaf2u; return 0; }
target=r[14];
r[16]=0x0c0bdaf6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdaf6u) { target=s->pc; goto dispatch; }
goto P_0c0bdaf6;
P_0c0bdaf4: /* original 0009, guest PC 0x0c0bdaf4 */
if(!s->budget--) { s->failed_pc=0x0c0bdaf4u; return 0; }
goto P_0c0bdaf6;
P_0c0bdaf6: /* original 9477, guest PC 0x0c0bdaf6 */
if(!s->budget--) { s->failed_pc=0x0c0bdaf6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdbe8u,2);
goto P_0c0bdaf8;
P_0c0bdaf8: /* original 4e0b, guest PC 0x0c0bdaf8 */
if(!s->budget--) { s->failed_pc=0x0c0bdaf8u; return 0; }
target=r[14];
r[16]=0x0c0bdafcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdafcu) { target=s->pc; goto dispatch; }
goto P_0c0bdafc;
P_0c0bdafa: /* original 0009, guest PC 0x0c0bdafa */
if(!s->budget--) { s->failed_pc=0x0c0bdafau; return 0; }
goto P_0c0bdafc;
P_0c0bdafc: /* original 9475, guest PC 0x0c0bdafc */
if(!s->budget--) { s->failed_pc=0x0c0bdafcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdbeau,2);
goto P_0c0bdafe;
P_0c0bdafe: /* original 4e0b, guest PC 0x0c0bdafe */
if(!s->budget--) { s->failed_pc=0x0c0bdafeu; return 0; }
target=r[14];
r[16]=0x0c0bdb02u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb02u) { target=s->pc; goto dispatch; }
goto P_0c0bdb02;
P_0c0bdb00: /* original 0009, guest PC 0x0c0bdb00 */
if(!s->budget--) { s->failed_pc=0x0c0bdb00u; return 0; }
goto P_0c0bdb02;
P_0c0bdb02: /* original 9473, guest PC 0x0c0bdb02 */
if(!s->budget--) { s->failed_pc=0x0c0bdb02u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdbecu,2);
goto P_0c0bdb04;
P_0c0bdb04: /* original 4e0b, guest PC 0x0c0bdb04 */
if(!s->budget--) { s->failed_pc=0x0c0bdb04u; return 0; }
target=r[14];
r[16]=0x0c0bdb08u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb08u) { target=s->pc; goto dispatch; }
goto P_0c0bdb08;
P_0c0bdb06: /* original 0009, guest PC 0x0c0bdb06 */
if(!s->budget--) { s->failed_pc=0x0c0bdb06u; return 0; }
goto P_0c0bdb08;
P_0c0bdb08: /* original 9471, guest PC 0x0c0bdb08 */
if(!s->budget--) { s->failed_pc=0x0c0bdb08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdbeeu,2);
goto P_0c0bdb0a;
P_0c0bdb0a: /* original 4e0b, guest PC 0x0c0bdb0a */
if(!s->budget--) { s->failed_pc=0x0c0bdb0au; return 0; }
target=r[14];
r[16]=0x0c0bdb0eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb0eu) { target=s->pc; goto dispatch; }
goto P_0c0bdb0e;
P_0c0bdb0c: /* original 0009, guest PC 0x0c0bdb0c */
if(!s->budget--) { s->failed_pc=0x0c0bdb0cu; return 0; }
goto P_0c0bdb0e;
P_0c0bdb0e: /* original 946f, guest PC 0x0c0bdb0e */
if(!s->budget--) { s->failed_pc=0x0c0bdb0eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdbf0u,2);
goto P_0c0bdb10;
P_0c0bdb10: /* original 4e0b, guest PC 0x0c0bdb10 */
if(!s->budget--) { s->failed_pc=0x0c0bdb10u; return 0; }
target=r[14];
r[16]=0x0c0bdb14u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb14u) { target=s->pc; goto dispatch; }
goto P_0c0bdb14;
P_0c0bdb12: /* original 0009, guest PC 0x0c0bdb12 */
if(!s->budget--) { s->failed_pc=0x0c0bdb12u; return 0; }
goto P_0c0bdb14;
P_0c0bdb14: /* original 946d, guest PC 0x0c0bdb14 */
if(!s->budget--) { s->failed_pc=0x0c0bdb14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdbf2u,2);
goto P_0c0bdb16;
P_0c0bdb16: /* original 4e0b, guest PC 0x0c0bdb16 */
if(!s->budget--) { s->failed_pc=0x0c0bdb16u; return 0; }
target=r[14];
r[16]=0x0c0bdb1au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb1au) { target=s->pc; goto dispatch; }
goto P_0c0bdb1a;
P_0c0bdb18: /* original 0009, guest PC 0x0c0bdb18 */
if(!s->budget--) { s->failed_pc=0x0c0bdb18u; return 0; }
goto P_0c0bdb1a;
P_0c0bdb1a: /* original 946b, guest PC 0x0c0bdb1a */
if(!s->budget--) { s->failed_pc=0x0c0bdb1au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdbf4u,2);
goto P_0c0bdb1c;
P_0c0bdb1c: /* original 4e0b, guest PC 0x0c0bdb1c */
if(!s->budget--) { s->failed_pc=0x0c0bdb1cu; return 0; }
target=r[14];
r[16]=0x0c0bdb20u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb20u) { target=s->pc; goto dispatch; }
goto P_0c0bdb20;
P_0c0bdb1e: /* original 0009, guest PC 0x0c0bdb1e */
if(!s->budget--) { s->failed_pc=0x0c0bdb1eu; return 0; }
goto P_0c0bdb20;
P_0c0bdb20: /* original 9469, guest PC 0x0c0bdb20 */
if(!s->budget--) { s->failed_pc=0x0c0bdb20u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdbf6u,2);
goto P_0c0bdb22;
P_0c0bdb22: /* original 4e0b, guest PC 0x0c0bdb22 */
if(!s->budget--) { s->failed_pc=0x0c0bdb22u; return 0; }
target=r[14];
r[16]=0x0c0bdb26u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb26u) { target=s->pc; goto dispatch; }
goto P_0c0bdb26;
P_0c0bdb24: /* original 0009, guest PC 0x0c0bdb24 */
if(!s->budget--) { s->failed_pc=0x0c0bdb24u; return 0; }
goto P_0c0bdb26;
P_0c0bdb26: /* original 9467, guest PC 0x0c0bdb26 */
if(!s->budget--) { s->failed_pc=0x0c0bdb26u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdbf8u,2);
goto P_0c0bdb28;
P_0c0bdb28: /* original 4e0b, guest PC 0x0c0bdb28 */
if(!s->budget--) { s->failed_pc=0x0c0bdb28u; return 0; }
target=r[14];
r[16]=0x0c0bdb2cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb2cu) { target=s->pc; goto dispatch; }
goto P_0c0bdb2c;
P_0c0bdb2a: /* original 0009, guest PC 0x0c0bdb2a */
if(!s->budget--) { s->failed_pc=0x0c0bdb2au; return 0; }
goto P_0c0bdb2c;
P_0c0bdb2c: /* original 9465, guest PC 0x0c0bdb2c */
if(!s->budget--) { s->failed_pc=0x0c0bdb2cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdbfau,2);
goto P_0c0bdb2e;
P_0c0bdb2e: /* original 4e0b, guest PC 0x0c0bdb2e */
if(!s->budget--) { s->failed_pc=0x0c0bdb2eu; return 0; }
target=r[14];
r[16]=0x0c0bdb32u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb32u) { target=s->pc; goto dispatch; }
goto P_0c0bdb32;
P_0c0bdb30: /* original 0009, guest PC 0x0c0bdb30 */
if(!s->budget--) { s->failed_pc=0x0c0bdb30u; return 0; }
goto P_0c0bdb32;
P_0c0bdb32: /* original 9463, guest PC 0x0c0bdb32 */
if(!s->budget--) { s->failed_pc=0x0c0bdb32u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdbfcu,2);
goto P_0c0bdb34;
P_0c0bdb34: /* original 4e0b, guest PC 0x0c0bdb34 */
if(!s->budget--) { s->failed_pc=0x0c0bdb34u; return 0; }
target=r[14];
r[16]=0x0c0bdb38u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb38u) { target=s->pc; goto dispatch; }
goto P_0c0bdb38;
P_0c0bdb36: /* original 0009, guest PC 0x0c0bdb36 */
if(!s->budget--) { s->failed_pc=0x0c0bdb36u; return 0; }
goto P_0c0bdb38;
P_0c0bdb38: /* original 9461, guest PC 0x0c0bdb38 */
if(!s->budget--) { s->failed_pc=0x0c0bdb38u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdbfeu,2);
goto P_0c0bdb3a;
P_0c0bdb3a: /* original 4e0b, guest PC 0x0c0bdb3a */
if(!s->budget--) { s->failed_pc=0x0c0bdb3au; return 0; }
target=r[14];
r[16]=0x0c0bdb3eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb3eu) { target=s->pc; goto dispatch; }
goto P_0c0bdb3e;
P_0c0bdb3c: /* original 0009, guest PC 0x0c0bdb3c */
if(!s->budget--) { s->failed_pc=0x0c0bdb3cu; return 0; }
goto P_0c0bdb3e;
P_0c0bdb3e: /* original 945f, guest PC 0x0c0bdb3e */
if(!s->budget--) { s->failed_pc=0x0c0bdb3eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc00u,2);
goto P_0c0bdb40;
P_0c0bdb40: /* original 4e0b, guest PC 0x0c0bdb40 */
if(!s->budget--) { s->failed_pc=0x0c0bdb40u; return 0; }
target=r[14];
r[16]=0x0c0bdb44u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb44u) { target=s->pc; goto dispatch; }
goto P_0c0bdb44;
P_0c0bdb42: /* original 0009, guest PC 0x0c0bdb42 */
if(!s->budget--) { s->failed_pc=0x0c0bdb42u; return 0; }
goto P_0c0bdb44;
P_0c0bdb44: /* original 945d, guest PC 0x0c0bdb44 */
if(!s->budget--) { s->failed_pc=0x0c0bdb44u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc02u,2);
goto P_0c0bdb46;
P_0c0bdb46: /* original 4e0b, guest PC 0x0c0bdb46 */
if(!s->budget--) { s->failed_pc=0x0c0bdb46u; return 0; }
target=r[14];
r[16]=0x0c0bdb4au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb4au) { target=s->pc; goto dispatch; }
goto P_0c0bdb4a;
P_0c0bdb48: /* original 0009, guest PC 0x0c0bdb48 */
if(!s->budget--) { s->failed_pc=0x0c0bdb48u; return 0; }
goto P_0c0bdb4a;
P_0c0bdb4a: /* original 945b, guest PC 0x0c0bdb4a */
if(!s->budget--) { s->failed_pc=0x0c0bdb4au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc04u,2);
goto P_0c0bdb4c;
P_0c0bdb4c: /* original 4e0b, guest PC 0x0c0bdb4c */
if(!s->budget--) { s->failed_pc=0x0c0bdb4cu; return 0; }
target=r[14];
r[16]=0x0c0bdb50u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb50u) { target=s->pc; goto dispatch; }
goto P_0c0bdb50;
P_0c0bdb4e: /* original 0009, guest PC 0x0c0bdb4e */
if(!s->budget--) { s->failed_pc=0x0c0bdb4eu; return 0; }
goto P_0c0bdb50;
P_0c0bdb50: /* original 9459, guest PC 0x0c0bdb50 */
if(!s->budget--) { s->failed_pc=0x0c0bdb50u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc06u,2);
goto P_0c0bdb52;
P_0c0bdb52: /* original 4e0b, guest PC 0x0c0bdb52 */
if(!s->budget--) { s->failed_pc=0x0c0bdb52u; return 0; }
target=r[14];
r[16]=0x0c0bdb56u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb56u) { target=s->pc; goto dispatch; }
goto P_0c0bdb56;
P_0c0bdb54: /* original 0009, guest PC 0x0c0bdb54 */
if(!s->budget--) { s->failed_pc=0x0c0bdb54u; return 0; }
goto P_0c0bdb56;
P_0c0bdb56: /* original 9457, guest PC 0x0c0bdb56 */
if(!s->budget--) { s->failed_pc=0x0c0bdb56u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc08u,2);
goto P_0c0bdb58;
P_0c0bdb58: /* original 4e0b, guest PC 0x0c0bdb58 */
if(!s->budget--) { s->failed_pc=0x0c0bdb58u; return 0; }
target=r[14];
r[16]=0x0c0bdb5cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb5cu) { target=s->pc; goto dispatch; }
goto P_0c0bdb5c;
P_0c0bdb5a: /* original 0009, guest PC 0x0c0bdb5a */
if(!s->budget--) { s->failed_pc=0x0c0bdb5au; return 0; }
goto P_0c0bdb5c;
P_0c0bdb5c: /* original 9455, guest PC 0x0c0bdb5c */
if(!s->budget--) { s->failed_pc=0x0c0bdb5cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc0au,2);
goto P_0c0bdb5e;
P_0c0bdb5e: /* original 4e0b, guest PC 0x0c0bdb5e */
if(!s->budget--) { s->failed_pc=0x0c0bdb5eu; return 0; }
target=r[14];
r[16]=0x0c0bdb62u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb62u) { target=s->pc; goto dispatch; }
goto P_0c0bdb62;
P_0c0bdb60: /* original 0009, guest PC 0x0c0bdb60 */
if(!s->budget--) { s->failed_pc=0x0c0bdb60u; return 0; }
goto P_0c0bdb62;
P_0c0bdb62: /* original 9453, guest PC 0x0c0bdb62 */
if(!s->budget--) { s->failed_pc=0x0c0bdb62u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc0cu,2);
goto P_0c0bdb64;
P_0c0bdb64: /* original 4e0b, guest PC 0x0c0bdb64 */
if(!s->budget--) { s->failed_pc=0x0c0bdb64u; return 0; }
target=r[14];
r[16]=0x0c0bdb68u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb68u) { target=s->pc; goto dispatch; }
goto P_0c0bdb68;
P_0c0bdb66: /* original 0009, guest PC 0x0c0bdb66 */
if(!s->budget--) { s->failed_pc=0x0c0bdb66u; return 0; }
goto P_0c0bdb68;
P_0c0bdb68: /* original 9451, guest PC 0x0c0bdb68 */
if(!s->budget--) { s->failed_pc=0x0c0bdb68u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc0eu,2);
goto P_0c0bdb6a;
P_0c0bdb6a: /* original 4e0b, guest PC 0x0c0bdb6a */
if(!s->budget--) { s->failed_pc=0x0c0bdb6au; return 0; }
target=r[14];
r[16]=0x0c0bdb6eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb6eu) { target=s->pc; goto dispatch; }
goto P_0c0bdb6e;
P_0c0bdb6c: /* original 0009, guest PC 0x0c0bdb6c */
if(!s->budget--) { s->failed_pc=0x0c0bdb6cu; return 0; }
goto P_0c0bdb6e;
P_0c0bdb6e: /* original 944f, guest PC 0x0c0bdb6e */
if(!s->budget--) { s->failed_pc=0x0c0bdb6eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc10u,2);
goto P_0c0bdb70;
P_0c0bdb70: /* original 4e0b, guest PC 0x0c0bdb70 */
if(!s->budget--) { s->failed_pc=0x0c0bdb70u; return 0; }
target=r[14];
r[16]=0x0c0bdb74u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb74u) { target=s->pc; goto dispatch; }
goto P_0c0bdb74;
P_0c0bdb72: /* original 0009, guest PC 0x0c0bdb72 */
if(!s->budget--) { s->failed_pc=0x0c0bdb72u; return 0; }
goto P_0c0bdb74;
P_0c0bdb74: /* original 944d, guest PC 0x0c0bdb74 */
if(!s->budget--) { s->failed_pc=0x0c0bdb74u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc12u,2);
goto P_0c0bdb76;
P_0c0bdb76: /* original 4e0b, guest PC 0x0c0bdb76 */
if(!s->budget--) { s->failed_pc=0x0c0bdb76u; return 0; }
target=r[14];
r[16]=0x0c0bdb7au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb7au) { target=s->pc; goto dispatch; }
goto P_0c0bdb7a;
P_0c0bdb78: /* original 0009, guest PC 0x0c0bdb78 */
if(!s->budget--) { s->failed_pc=0x0c0bdb78u; return 0; }
goto P_0c0bdb7a;
P_0c0bdb7a: /* original 944b, guest PC 0x0c0bdb7a */
if(!s->budget--) { s->failed_pc=0x0c0bdb7au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc14u,2);
goto P_0c0bdb7c;
P_0c0bdb7c: /* original 4e0b, guest PC 0x0c0bdb7c */
if(!s->budget--) { s->failed_pc=0x0c0bdb7cu; return 0; }
target=r[14];
r[16]=0x0c0bdb80u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb80u) { target=s->pc; goto dispatch; }
goto P_0c0bdb80;
P_0c0bdb7e: /* original 0009, guest PC 0x0c0bdb7e */
if(!s->budget--) { s->failed_pc=0x0c0bdb7eu; return 0; }
goto P_0c0bdb80;
P_0c0bdb80: /* original 9449, guest PC 0x0c0bdb80 */
if(!s->budget--) { s->failed_pc=0x0c0bdb80u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc16u,2);
goto P_0c0bdb82;
P_0c0bdb82: /* original 4e0b, guest PC 0x0c0bdb82 */
if(!s->budget--) { s->failed_pc=0x0c0bdb82u; return 0; }
target=r[14];
r[16]=0x0c0bdb86u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb86u) { target=s->pc; goto dispatch; }
goto P_0c0bdb86;
P_0c0bdb84: /* original 0009, guest PC 0x0c0bdb84 */
if(!s->budget--) { s->failed_pc=0x0c0bdb84u; return 0; }
goto P_0c0bdb86;
P_0c0bdb86: /* original 9447, guest PC 0x0c0bdb86 */
if(!s->budget--) { s->failed_pc=0x0c0bdb86u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc18u,2);
goto P_0c0bdb88;
P_0c0bdb88: /* original 4e0b, guest PC 0x0c0bdb88 */
if(!s->budget--) { s->failed_pc=0x0c0bdb88u; return 0; }
target=r[14];
r[16]=0x0c0bdb8cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb8cu) { target=s->pc; goto dispatch; }
goto P_0c0bdb8c;
P_0c0bdb8a: /* original 0009, guest PC 0x0c0bdb8a */
if(!s->budget--) { s->failed_pc=0x0c0bdb8au; return 0; }
goto P_0c0bdb8c;
P_0c0bdb8c: /* original 9445, guest PC 0x0c0bdb8c */
if(!s->budget--) { s->failed_pc=0x0c0bdb8cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc1au,2);
goto P_0c0bdb8e;
P_0c0bdb8e: /* original 4e0b, guest PC 0x0c0bdb8e */
if(!s->budget--) { s->failed_pc=0x0c0bdb8eu; return 0; }
target=r[14];
r[16]=0x0c0bdb92u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb92u) { target=s->pc; goto dispatch; }
goto P_0c0bdb92;
P_0c0bdb90: /* original 0009, guest PC 0x0c0bdb90 */
if(!s->budget--) { s->failed_pc=0x0c0bdb90u; return 0; }
goto P_0c0bdb92;
P_0c0bdb92: /* original 9443, guest PC 0x0c0bdb92 */
if(!s->budget--) { s->failed_pc=0x0c0bdb92u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc1cu,2);
goto P_0c0bdb94;
P_0c0bdb94: /* original 4e0b, guest PC 0x0c0bdb94 */
if(!s->budget--) { s->failed_pc=0x0c0bdb94u; return 0; }
target=r[14];
r[16]=0x0c0bdb98u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb98u) { target=s->pc; goto dispatch; }
goto P_0c0bdb98;
P_0c0bdb96: /* original 0009, guest PC 0x0c0bdb96 */
if(!s->budget--) { s->failed_pc=0x0c0bdb96u; return 0; }
goto P_0c0bdb98;
P_0c0bdb98: /* original 9441, guest PC 0x0c0bdb98 */
if(!s->budget--) { s->failed_pc=0x0c0bdb98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc1eu,2);
goto P_0c0bdb9a;
P_0c0bdb9a: /* original 4e0b, guest PC 0x0c0bdb9a */
if(!s->budget--) { s->failed_pc=0x0c0bdb9au; return 0; }
target=r[14];
r[16]=0x0c0bdb9eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdb9eu) { target=s->pc; goto dispatch; }
goto P_0c0bdb9e;
P_0c0bdb9c: /* original 0009, guest PC 0x0c0bdb9c */
if(!s->budget--) { s->failed_pc=0x0c0bdb9cu; return 0; }
goto P_0c0bdb9e;
P_0c0bdb9e: /* original 943f, guest PC 0x0c0bdb9e */
if(!s->budget--) { s->failed_pc=0x0c0bdb9eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc20u,2);
goto P_0c0bdba0;
P_0c0bdba0: /* original 4e0b, guest PC 0x0c0bdba0 */
if(!s->budget--) { s->failed_pc=0x0c0bdba0u; return 0; }
target=r[14];
r[16]=0x0c0bdba4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdba4u) { target=s->pc; goto dispatch; }
goto P_0c0bdba4;
P_0c0bdba2: /* original 0009, guest PC 0x0c0bdba2 */
if(!s->budget--) { s->failed_pc=0x0c0bdba2u; return 0; }
goto P_0c0bdba4;
P_0c0bdba4: /* original 943d, guest PC 0x0c0bdba4 */
if(!s->budget--) { s->failed_pc=0x0c0bdba4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc22u,2);
goto P_0c0bdba6;
P_0c0bdba6: /* original 4e0b, guest PC 0x0c0bdba6 */
if(!s->budget--) { s->failed_pc=0x0c0bdba6u; return 0; }
target=r[14];
r[16]=0x0c0bdbaau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdbaau) { target=s->pc; goto dispatch; }
goto P_0c0bdbaa;
P_0c0bdba8: /* original 0009, guest PC 0x0c0bdba8 */
if(!s->budget--) { s->failed_pc=0x0c0bdba8u; return 0; }
goto P_0c0bdbaa;
P_0c0bdbaa: /* original 943b, guest PC 0x0c0bdbaa */
if(!s->budget--) { s->failed_pc=0x0c0bdbaau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc24u,2);
goto P_0c0bdbac;
P_0c0bdbac: /* original 4e0b, guest PC 0x0c0bdbac */
if(!s->budget--) { s->failed_pc=0x0c0bdbacu; return 0; }
target=r[14];
r[16]=0x0c0bdbb0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdbb0u) { target=s->pc; goto dispatch; }
goto P_0c0bdbb0;
P_0c0bdbae: /* original 0009, guest PC 0x0c0bdbae */
if(!s->budget--) { s->failed_pc=0x0c0bdbaeu; return 0; }
goto P_0c0bdbb0;
P_0c0bdbb0: /* original 9439, guest PC 0x0c0bdbb0 */
if(!s->budget--) { s->failed_pc=0x0c0bdbb0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc26u,2);
goto P_0c0bdbb2;
P_0c0bdbb2: /* original 4e0b, guest PC 0x0c0bdbb2 */
if(!s->budget--) { s->failed_pc=0x0c0bdbb2u; return 0; }
target=r[14];
r[16]=0x0c0bdbb6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdbb6u) { target=s->pc; goto dispatch; }
goto P_0c0bdbb6;
P_0c0bdbb4: /* original 0009, guest PC 0x0c0bdbb4 */
if(!s->budget--) { s->failed_pc=0x0c0bdbb4u; return 0; }
goto P_0c0bdbb6;
P_0c0bdbb6: /* original 9437, guest PC 0x0c0bdbb6 */
if(!s->budget--) { s->failed_pc=0x0c0bdbb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc28u,2);
goto P_0c0bdbb8;
P_0c0bdbb8: /* original 4e0b, guest PC 0x0c0bdbb8 */
if(!s->budget--) { s->failed_pc=0x0c0bdbb8u; return 0; }
target=r[14];
r[16]=0x0c0bdbbcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdbbcu) { target=s->pc; goto dispatch; }
goto P_0c0bdbbc;
P_0c0bdbba: /* original 0009, guest PC 0x0c0bdbba */
if(!s->budget--) { s->failed_pc=0x0c0bdbbau; return 0; }
goto P_0c0bdbbc;
P_0c0bdbbc: /* original 9435, guest PC 0x0c0bdbbc */
if(!s->budget--) { s->failed_pc=0x0c0bdbbcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc2au,2);
goto P_0c0bdbbe;
P_0c0bdbbe: /* original 4e0b, guest PC 0x0c0bdbbe */
if(!s->budget--) { s->failed_pc=0x0c0bdbbeu; return 0; }
target=r[14];
r[16]=0x0c0bdbc2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdbc2u) { target=s->pc; goto dispatch; }
goto P_0c0bdbc2;
P_0c0bdbc0: /* original 0009, guest PC 0x0c0bdbc0 */
if(!s->budget--) { s->failed_pc=0x0c0bdbc0u; return 0; }
goto P_0c0bdbc2;
P_0c0bdbc2: /* original 9433, guest PC 0x0c0bdbc2 */
if(!s->budget--) { s->failed_pc=0x0c0bdbc2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc2cu,2);
goto P_0c0bdbc4;
P_0c0bdbc4: /* original 4e0b, guest PC 0x0c0bdbc4 */
if(!s->budget--) { s->failed_pc=0x0c0bdbc4u; return 0; }
target=r[14];
r[16]=0x0c0bdbc8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdbc8u) { target=s->pc; goto dispatch; }
goto P_0c0bdbc8;
P_0c0bdbc6: /* original 0009, guest PC 0x0c0bdbc6 */
if(!s->budget--) { s->failed_pc=0x0c0bdbc6u; return 0; }
goto P_0c0bdbc8;
P_0c0bdbc8: /* original 9431, guest PC 0x0c0bdbc8 */
if(!s->budget--) { s->failed_pc=0x0c0bdbc8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc2eu,2);
goto P_0c0bdbca;
P_0c0bdbca: /* original 4e0b, guest PC 0x0c0bdbca */
if(!s->budget--) { s->failed_pc=0x0c0bdbcau; return 0; }
target=r[14];
r[16]=0x0c0bdbceu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdbceu) { target=s->pc; goto dispatch; }
goto P_0c0bdbce;
P_0c0bdbcc: /* original 0009, guest PC 0x0c0bdbcc */
if(!s->budget--) { s->failed_pc=0x0c0bdbccu; return 0; }
goto P_0c0bdbce;
P_0c0bdbce: /* original 942f, guest PC 0x0c0bdbce */
if(!s->budget--) { s->failed_pc=0x0c0bdbceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bdc30u,2);
goto P_0c0bdbd0;
P_0c0bdbd0: /* original 4e0b, guest PC 0x0c0bdbd0 */
if(!s->budget--) { s->failed_pc=0x0c0bdbd0u; return 0; }
target=r[14];
r[16]=0x0c0bdbd4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0bdbd4u) { target=s->pc; goto dispatch; }
goto P_0c0bdbd4;
P_0c0bdbd2: /* original 0009, guest PC 0x0c0bdbd2 */
if(!s->budget--) { s->failed_pc=0x0c0bdbd2u; return 0; }
goto P_0c0bdbd4;
P_0c0bdbd4: /* original 4f26, guest PC 0x0c0bdbd4 */
if(!s->budget--) { s->failed_pc=0x0c0bdbd4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0bdbd6;
P_0c0bdbd6: /* original 000b, guest PC 0x0c0bdbd6 */
if(!s->budget--) { s->failed_pc=0x0c0bdbd6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0bdbd8: /* original 6ef6, guest PC 0x0c0bdbd8 */
if(!s->budget--) { s->failed_pc=0x0c0bdbd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0bdbdau,s,ram);
P_0c0be05e: /* original 4f22, guest PC 0x0c0be05e */
if(!s->budget--) { s->failed_pc=0x0c0be05eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0be060;
P_0c0be060: /* original 94aa, guest PC 0x0c0be060 */
if(!s->budget--) { s->failed_pc=0x0c0be060u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1b8u,2);
goto P_0c0be062;
P_0c0be062: /* original de72, guest PC 0x0c0be062 */
if(!s->budget--) { s->failed_pc=0x0c0be062u; return 0; }
r[14]=read(ram,0x0c0be22cu,4);
goto P_0c0be064;
P_0c0be064: /* original 4e0b, guest PC 0x0c0be064 */
if(!s->budget--) { s->failed_pc=0x0c0be064u; return 0; }
target=r[14];
r[16]=0x0c0be068u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be068u) { target=s->pc; goto dispatch; }
goto P_0c0be068;
P_0c0be066: /* original 0009, guest PC 0x0c0be066 */
if(!s->budget--) { s->failed_pc=0x0c0be066u; return 0; }
goto P_0c0be068;
P_0c0be068: /* original 94a7, guest PC 0x0c0be068 */
if(!s->budget--) { s->failed_pc=0x0c0be068u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1bau,2);
goto P_0c0be06a;
P_0c0be06a: /* original 4e0b, guest PC 0x0c0be06a */
if(!s->budget--) { s->failed_pc=0x0c0be06au; return 0; }
target=r[14];
r[16]=0x0c0be06eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be06eu) { target=s->pc; goto dispatch; }
goto P_0c0be06e;
P_0c0be06c: /* original 0009, guest PC 0x0c0be06c */
if(!s->budget--) { s->failed_pc=0x0c0be06cu; return 0; }
goto P_0c0be06e;
P_0c0be06e: /* original 94a5, guest PC 0x0c0be06e */
if(!s->budget--) { s->failed_pc=0x0c0be06eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1bcu,2);
goto P_0c0be070;
P_0c0be070: /* original 4e0b, guest PC 0x0c0be070 */
if(!s->budget--) { s->failed_pc=0x0c0be070u; return 0; }
target=r[14];
r[16]=0x0c0be074u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be074u) { target=s->pc; goto dispatch; }
goto P_0c0be074;
P_0c0be072: /* original 0009, guest PC 0x0c0be072 */
if(!s->budget--) { s->failed_pc=0x0c0be072u; return 0; }
goto P_0c0be074;
P_0c0be074: /* original 94a3, guest PC 0x0c0be074 */
if(!s->budget--) { s->failed_pc=0x0c0be074u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1beu,2);
goto P_0c0be076;
P_0c0be076: /* original 4e0b, guest PC 0x0c0be076 */
if(!s->budget--) { s->failed_pc=0x0c0be076u; return 0; }
target=r[14];
r[16]=0x0c0be07au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be07au) { target=s->pc; goto dispatch; }
goto P_0c0be07a;
P_0c0be078: /* original 0009, guest PC 0x0c0be078 */
if(!s->budget--) { s->failed_pc=0x0c0be078u; return 0; }
goto P_0c0be07a;
P_0c0be07a: /* original 94a1, guest PC 0x0c0be07a */
if(!s->budget--) { s->failed_pc=0x0c0be07au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1c0u,2);
goto P_0c0be07c;
P_0c0be07c: /* original 4e0b, guest PC 0x0c0be07c */
if(!s->budget--) { s->failed_pc=0x0c0be07cu; return 0; }
target=r[14];
r[16]=0x0c0be080u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be080u) { target=s->pc; goto dispatch; }
goto P_0c0be080;
P_0c0be07e: /* original 0009, guest PC 0x0c0be07e */
if(!s->budget--) { s->failed_pc=0x0c0be07eu; return 0; }
goto P_0c0be080;
P_0c0be080: /* original 949f, guest PC 0x0c0be080 */
if(!s->budget--) { s->failed_pc=0x0c0be080u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1c2u,2);
goto P_0c0be082;
P_0c0be082: /* original 4e0b, guest PC 0x0c0be082 */
if(!s->budget--) { s->failed_pc=0x0c0be082u; return 0; }
target=r[14];
r[16]=0x0c0be086u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be086u) { target=s->pc; goto dispatch; }
goto P_0c0be086;
P_0c0be084: /* original 0009, guest PC 0x0c0be084 */
if(!s->budget--) { s->failed_pc=0x0c0be084u; return 0; }
goto P_0c0be086;
P_0c0be086: /* original 949d, guest PC 0x0c0be086 */
if(!s->budget--) { s->failed_pc=0x0c0be086u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1c4u,2);
goto P_0c0be088;
P_0c0be088: /* original 4e0b, guest PC 0x0c0be088 */
if(!s->budget--) { s->failed_pc=0x0c0be088u; return 0; }
target=r[14];
r[16]=0x0c0be08cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be08cu) { target=s->pc; goto dispatch; }
goto P_0c0be08c;
P_0c0be08a: /* original 0009, guest PC 0x0c0be08a */
if(!s->budget--) { s->failed_pc=0x0c0be08au; return 0; }
goto P_0c0be08c;
P_0c0be08c: /* original 949b, guest PC 0x0c0be08c */
if(!s->budget--) { s->failed_pc=0x0c0be08cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1c6u,2);
goto P_0c0be08e;
P_0c0be08e: /* original 4e0b, guest PC 0x0c0be08e */
if(!s->budget--) { s->failed_pc=0x0c0be08eu; return 0; }
target=r[14];
r[16]=0x0c0be092u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be092u) { target=s->pc; goto dispatch; }
goto P_0c0be092;
P_0c0be090: /* original 0009, guest PC 0x0c0be090 */
if(!s->budget--) { s->failed_pc=0x0c0be090u; return 0; }
goto P_0c0be092;
P_0c0be092: /* original 9499, guest PC 0x0c0be092 */
if(!s->budget--) { s->failed_pc=0x0c0be092u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1c8u,2);
goto P_0c0be094;
P_0c0be094: /* original 4e0b, guest PC 0x0c0be094 */
if(!s->budget--) { s->failed_pc=0x0c0be094u; return 0; }
target=r[14];
r[16]=0x0c0be098u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be098u) { target=s->pc; goto dispatch; }
goto P_0c0be098;
P_0c0be096: /* original 0009, guest PC 0x0c0be096 */
if(!s->budget--) { s->failed_pc=0x0c0be096u; return 0; }
goto P_0c0be098;
P_0c0be098: /* original 9497, guest PC 0x0c0be098 */
if(!s->budget--) { s->failed_pc=0x0c0be098u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1cau,2);
goto P_0c0be09a;
P_0c0be09a: /* original 4e0b, guest PC 0x0c0be09a */
if(!s->budget--) { s->failed_pc=0x0c0be09au; return 0; }
target=r[14];
r[16]=0x0c0be09eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be09eu) { target=s->pc; goto dispatch; }
goto P_0c0be09e;
P_0c0be09c: /* original 0009, guest PC 0x0c0be09c */
if(!s->budget--) { s->failed_pc=0x0c0be09cu; return 0; }
goto P_0c0be09e;
P_0c0be09e: /* original 9495, guest PC 0x0c0be09e */
if(!s->budget--) { s->failed_pc=0x0c0be09eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1ccu,2);
goto P_0c0be0a0;
P_0c0be0a0: /* original 4e0b, guest PC 0x0c0be0a0 */
if(!s->budget--) { s->failed_pc=0x0c0be0a0u; return 0; }
target=r[14];
r[16]=0x0c0be0a4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be0a4u) { target=s->pc; goto dispatch; }
goto P_0c0be0a4;
P_0c0be0a2: /* original 0009, guest PC 0x0c0be0a2 */
if(!s->budget--) { s->failed_pc=0x0c0be0a2u; return 0; }
goto P_0c0be0a4;
P_0c0be0a4: /* original 9493, guest PC 0x0c0be0a4 */
if(!s->budget--) { s->failed_pc=0x0c0be0a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1ceu,2);
goto P_0c0be0a6;
P_0c0be0a6: /* original 4e0b, guest PC 0x0c0be0a6 */
if(!s->budget--) { s->failed_pc=0x0c0be0a6u; return 0; }
target=r[14];
r[16]=0x0c0be0aau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be0aau) { target=s->pc; goto dispatch; }
goto P_0c0be0aa;
P_0c0be0a8: /* original 0009, guest PC 0x0c0be0a8 */
if(!s->budget--) { s->failed_pc=0x0c0be0a8u; return 0; }
goto P_0c0be0aa;
P_0c0be0aa: /* original 9491, guest PC 0x0c0be0aa */
if(!s->budget--) { s->failed_pc=0x0c0be0aau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1d0u,2);
goto P_0c0be0ac;
P_0c0be0ac: /* original 4e0b, guest PC 0x0c0be0ac */
if(!s->budget--) { s->failed_pc=0x0c0be0acu; return 0; }
target=r[14];
r[16]=0x0c0be0b0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be0b0u) { target=s->pc; goto dispatch; }
goto P_0c0be0b0;
P_0c0be0ae: /* original 0009, guest PC 0x0c0be0ae */
if(!s->budget--) { s->failed_pc=0x0c0be0aeu; return 0; }
goto P_0c0be0b0;
P_0c0be0b0: /* original 948f, guest PC 0x0c0be0b0 */
if(!s->budget--) { s->failed_pc=0x0c0be0b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1d2u,2);
goto P_0c0be0b2;
P_0c0be0b2: /* original 4e0b, guest PC 0x0c0be0b2 */
if(!s->budget--) { s->failed_pc=0x0c0be0b2u; return 0; }
target=r[14];
r[16]=0x0c0be0b6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be0b6u) { target=s->pc; goto dispatch; }
goto P_0c0be0b6;
P_0c0be0b4: /* original 0009, guest PC 0x0c0be0b4 */
if(!s->budget--) { s->failed_pc=0x0c0be0b4u; return 0; }
goto P_0c0be0b6;
P_0c0be0b6: /* original 948d, guest PC 0x0c0be0b6 */
if(!s->budget--) { s->failed_pc=0x0c0be0b6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1d4u,2);
goto P_0c0be0b8;
P_0c0be0b8: /* original 4e0b, guest PC 0x0c0be0b8 */
if(!s->budget--) { s->failed_pc=0x0c0be0b8u; return 0; }
target=r[14];
r[16]=0x0c0be0bcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be0bcu) { target=s->pc; goto dispatch; }
goto P_0c0be0bc;
P_0c0be0ba: /* original 0009, guest PC 0x0c0be0ba */
if(!s->budget--) { s->failed_pc=0x0c0be0bau; return 0; }
goto P_0c0be0bc;
P_0c0be0bc: /* original 948b, guest PC 0x0c0be0bc */
if(!s->budget--) { s->failed_pc=0x0c0be0bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1d6u,2);
goto P_0c0be0be;
P_0c0be0be: /* original 4e0b, guest PC 0x0c0be0be */
if(!s->budget--) { s->failed_pc=0x0c0be0beu; return 0; }
target=r[14];
r[16]=0x0c0be0c2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be0c2u) { target=s->pc; goto dispatch; }
goto P_0c0be0c2;
P_0c0be0c0: /* original 0009, guest PC 0x0c0be0c0 */
if(!s->budget--) { s->failed_pc=0x0c0be0c0u; return 0; }
goto P_0c0be0c2;
P_0c0be0c2: /* original 9489, guest PC 0x0c0be0c2 */
if(!s->budget--) { s->failed_pc=0x0c0be0c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1d8u,2);
goto P_0c0be0c4;
P_0c0be0c4: /* original 4e0b, guest PC 0x0c0be0c4 */
if(!s->budget--) { s->failed_pc=0x0c0be0c4u; return 0; }
target=r[14];
r[16]=0x0c0be0c8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be0c8u) { target=s->pc; goto dispatch; }
goto P_0c0be0c8;
P_0c0be0c6: /* original 0009, guest PC 0x0c0be0c6 */
if(!s->budget--) { s->failed_pc=0x0c0be0c6u; return 0; }
goto P_0c0be0c8;
P_0c0be0c8: /* original 9487, guest PC 0x0c0be0c8 */
if(!s->budget--) { s->failed_pc=0x0c0be0c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1dau,2);
goto P_0c0be0ca;
P_0c0be0ca: /* original 4e0b, guest PC 0x0c0be0ca */
if(!s->budget--) { s->failed_pc=0x0c0be0cau; return 0; }
target=r[14];
r[16]=0x0c0be0ceu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be0ceu) { target=s->pc; goto dispatch; }
goto P_0c0be0ce;
P_0c0be0cc: /* original 0009, guest PC 0x0c0be0cc */
if(!s->budget--) { s->failed_pc=0x0c0be0ccu; return 0; }
goto P_0c0be0ce;
P_0c0be0ce: /* original 9485, guest PC 0x0c0be0ce */
if(!s->budget--) { s->failed_pc=0x0c0be0ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1dcu,2);
goto P_0c0be0d0;
P_0c0be0d0: /* original 4e0b, guest PC 0x0c0be0d0 */
if(!s->budget--) { s->failed_pc=0x0c0be0d0u; return 0; }
target=r[14];
r[16]=0x0c0be0d4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be0d4u) { target=s->pc; goto dispatch; }
goto P_0c0be0d4;
P_0c0be0d2: /* original 0009, guest PC 0x0c0be0d2 */
if(!s->budget--) { s->failed_pc=0x0c0be0d2u; return 0; }
goto P_0c0be0d4;
P_0c0be0d4: /* original 9483, guest PC 0x0c0be0d4 */
if(!s->budget--) { s->failed_pc=0x0c0be0d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1deu,2);
goto P_0c0be0d6;
P_0c0be0d6: /* original 4e0b, guest PC 0x0c0be0d6 */
if(!s->budget--) { s->failed_pc=0x0c0be0d6u; return 0; }
target=r[14];
r[16]=0x0c0be0dau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be0dau) { target=s->pc; goto dispatch; }
goto P_0c0be0da;
P_0c0be0d8: /* original 0009, guest PC 0x0c0be0d8 */
if(!s->budget--) { s->failed_pc=0x0c0be0d8u; return 0; }
goto P_0c0be0da;
P_0c0be0da: /* original 9481, guest PC 0x0c0be0da */
if(!s->budget--) { s->failed_pc=0x0c0be0dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1e0u,2);
goto P_0c0be0dc;
P_0c0be0dc: /* original 4e0b, guest PC 0x0c0be0dc */
if(!s->budget--) { s->failed_pc=0x0c0be0dcu; return 0; }
target=r[14];
r[16]=0x0c0be0e0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be0e0u) { target=s->pc; goto dispatch; }
goto P_0c0be0e0;
P_0c0be0de: /* original 0009, guest PC 0x0c0be0de */
if(!s->budget--) { s->failed_pc=0x0c0be0deu; return 0; }
goto P_0c0be0e0;
P_0c0be0e0: /* original 947f, guest PC 0x0c0be0e0 */
if(!s->budget--) { s->failed_pc=0x0c0be0e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1e2u,2);
goto P_0c0be0e2;
P_0c0be0e2: /* original 4e0b, guest PC 0x0c0be0e2 */
if(!s->budget--) { s->failed_pc=0x0c0be0e2u; return 0; }
target=r[14];
r[16]=0x0c0be0e6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be0e6u) { target=s->pc; goto dispatch; }
goto P_0c0be0e6;
P_0c0be0e4: /* original 0009, guest PC 0x0c0be0e4 */
if(!s->budget--) { s->failed_pc=0x0c0be0e4u; return 0; }
goto P_0c0be0e6;
P_0c0be0e6: /* original 947d, guest PC 0x0c0be0e6 */
if(!s->budget--) { s->failed_pc=0x0c0be0e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1e4u,2);
goto P_0c0be0e8;
P_0c0be0e8: /* original 4e0b, guest PC 0x0c0be0e8 */
if(!s->budget--) { s->failed_pc=0x0c0be0e8u; return 0; }
target=r[14];
r[16]=0x0c0be0ecu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be0ecu) { target=s->pc; goto dispatch; }
goto P_0c0be0ec;
P_0c0be0ea: /* original 0009, guest PC 0x0c0be0ea */
if(!s->budget--) { s->failed_pc=0x0c0be0eau; return 0; }
goto P_0c0be0ec;
P_0c0be0ec: /* original 947b, guest PC 0x0c0be0ec */
if(!s->budget--) { s->failed_pc=0x0c0be0ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1e6u,2);
goto P_0c0be0ee;
P_0c0be0ee: /* original 4e0b, guest PC 0x0c0be0ee */
if(!s->budget--) { s->failed_pc=0x0c0be0eeu; return 0; }
target=r[14];
r[16]=0x0c0be0f2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be0f2u) { target=s->pc; goto dispatch; }
goto P_0c0be0f2;
P_0c0be0f0: /* original 0009, guest PC 0x0c0be0f0 */
if(!s->budget--) { s->failed_pc=0x0c0be0f0u; return 0; }
goto P_0c0be0f2;
P_0c0be0f2: /* original 9479, guest PC 0x0c0be0f2 */
if(!s->budget--) { s->failed_pc=0x0c0be0f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1e8u,2);
goto P_0c0be0f4;
P_0c0be0f4: /* original 4e0b, guest PC 0x0c0be0f4 */
if(!s->budget--) { s->failed_pc=0x0c0be0f4u; return 0; }
target=r[14];
r[16]=0x0c0be0f8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be0f8u) { target=s->pc; goto dispatch; }
goto P_0c0be0f8;
P_0c0be0f6: /* original 0009, guest PC 0x0c0be0f6 */
if(!s->budget--) { s->failed_pc=0x0c0be0f6u; return 0; }
goto P_0c0be0f8;
P_0c0be0f8: /* original 9477, guest PC 0x0c0be0f8 */
if(!s->budget--) { s->failed_pc=0x0c0be0f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1eau,2);
goto P_0c0be0fa;
P_0c0be0fa: /* original 4e0b, guest PC 0x0c0be0fa */
if(!s->budget--) { s->failed_pc=0x0c0be0fau; return 0; }
target=r[14];
r[16]=0x0c0be0feu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be0feu) { target=s->pc; goto dispatch; }
goto P_0c0be0fe;
P_0c0be0fc: /* original 0009, guest PC 0x0c0be0fc */
if(!s->budget--) { s->failed_pc=0x0c0be0fcu; return 0; }
goto P_0c0be0fe;
P_0c0be0fe: /* original 9475, guest PC 0x0c0be0fe */
if(!s->budget--) { s->failed_pc=0x0c0be0feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1ecu,2);
goto P_0c0be100;
P_0c0be100: /* original 4e0b, guest PC 0x0c0be100 */
if(!s->budget--) { s->failed_pc=0x0c0be100u; return 0; }
target=r[14];
r[16]=0x0c0be104u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be104u) { target=s->pc; goto dispatch; }
goto P_0c0be104;
P_0c0be102: /* original 0009, guest PC 0x0c0be102 */
if(!s->budget--) { s->failed_pc=0x0c0be102u; return 0; }
goto P_0c0be104;
P_0c0be104: /* original 9473, guest PC 0x0c0be104 */
if(!s->budget--) { s->failed_pc=0x0c0be104u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1eeu,2);
goto P_0c0be106;
P_0c0be106: /* original 4e0b, guest PC 0x0c0be106 */
if(!s->budget--) { s->failed_pc=0x0c0be106u; return 0; }
target=r[14];
r[16]=0x0c0be10au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be10au) { target=s->pc; goto dispatch; }
goto P_0c0be10a;
P_0c0be108: /* original 0009, guest PC 0x0c0be108 */
if(!s->budget--) { s->failed_pc=0x0c0be108u; return 0; }
goto P_0c0be10a;
P_0c0be10a: /* original 9471, guest PC 0x0c0be10a */
if(!s->budget--) { s->failed_pc=0x0c0be10au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1f0u,2);
goto P_0c0be10c;
P_0c0be10c: /* original 4e0b, guest PC 0x0c0be10c */
if(!s->budget--) { s->failed_pc=0x0c0be10cu; return 0; }
target=r[14];
r[16]=0x0c0be110u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be110u) { target=s->pc; goto dispatch; }
goto P_0c0be110;
P_0c0be10e: /* original 0009, guest PC 0x0c0be10e */
if(!s->budget--) { s->failed_pc=0x0c0be10eu; return 0; }
goto P_0c0be110;
P_0c0be110: /* original 946f, guest PC 0x0c0be110 */
if(!s->budget--) { s->failed_pc=0x0c0be110u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1f2u,2);
goto P_0c0be112;
P_0c0be112: /* original 4e0b, guest PC 0x0c0be112 */
if(!s->budget--) { s->failed_pc=0x0c0be112u; return 0; }
target=r[14];
r[16]=0x0c0be116u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be116u) { target=s->pc; goto dispatch; }
goto P_0c0be116;
P_0c0be114: /* original 0009, guest PC 0x0c0be114 */
if(!s->budget--) { s->failed_pc=0x0c0be114u; return 0; }
goto P_0c0be116;
P_0c0be116: /* original 946d, guest PC 0x0c0be116 */
if(!s->budget--) { s->failed_pc=0x0c0be116u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1f4u,2);
goto P_0c0be118;
P_0c0be118: /* original 4e0b, guest PC 0x0c0be118 */
if(!s->budget--) { s->failed_pc=0x0c0be118u; return 0; }
target=r[14];
r[16]=0x0c0be11cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be11cu) { target=s->pc; goto dispatch; }
goto P_0c0be11c;
P_0c0be11a: /* original 0009, guest PC 0x0c0be11a */
if(!s->budget--) { s->failed_pc=0x0c0be11au; return 0; }
goto P_0c0be11c;
P_0c0be11c: /* original 946b, guest PC 0x0c0be11c */
if(!s->budget--) { s->failed_pc=0x0c0be11cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1f6u,2);
goto P_0c0be11e;
P_0c0be11e: /* original 4e0b, guest PC 0x0c0be11e */
if(!s->budget--) { s->failed_pc=0x0c0be11eu; return 0; }
target=r[14];
r[16]=0x0c0be122u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be122u) { target=s->pc; goto dispatch; }
goto P_0c0be122;
P_0c0be120: /* original 0009, guest PC 0x0c0be120 */
if(!s->budget--) { s->failed_pc=0x0c0be120u; return 0; }
goto P_0c0be122;
P_0c0be122: /* original 9469, guest PC 0x0c0be122 */
if(!s->budget--) { s->failed_pc=0x0c0be122u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1f8u,2);
goto P_0c0be124;
P_0c0be124: /* original 4e0b, guest PC 0x0c0be124 */
if(!s->budget--) { s->failed_pc=0x0c0be124u; return 0; }
target=r[14];
r[16]=0x0c0be128u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be128u) { target=s->pc; goto dispatch; }
goto P_0c0be128;
P_0c0be126: /* original 0009, guest PC 0x0c0be126 */
if(!s->budget--) { s->failed_pc=0x0c0be126u; return 0; }
goto P_0c0be128;
P_0c0be128: /* original 9467, guest PC 0x0c0be128 */
if(!s->budget--) { s->failed_pc=0x0c0be128u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1fau,2);
goto P_0c0be12a;
P_0c0be12a: /* original 4e0b, guest PC 0x0c0be12a */
if(!s->budget--) { s->failed_pc=0x0c0be12au; return 0; }
target=r[14];
r[16]=0x0c0be12eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be12eu) { target=s->pc; goto dispatch; }
goto P_0c0be12e;
P_0c0be12c: /* original 0009, guest PC 0x0c0be12c */
if(!s->budget--) { s->failed_pc=0x0c0be12cu; return 0; }
goto P_0c0be12e;
P_0c0be12e: /* original 9465, guest PC 0x0c0be12e */
if(!s->budget--) { s->failed_pc=0x0c0be12eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1fcu,2);
goto P_0c0be130;
P_0c0be130: /* original 4e0b, guest PC 0x0c0be130 */
if(!s->budget--) { s->failed_pc=0x0c0be130u; return 0; }
target=r[14];
r[16]=0x0c0be134u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be134u) { target=s->pc; goto dispatch; }
goto P_0c0be134;
P_0c0be132: /* original 0009, guest PC 0x0c0be132 */
if(!s->budget--) { s->failed_pc=0x0c0be132u; return 0; }
goto P_0c0be134;
P_0c0be134: /* original 9463, guest PC 0x0c0be134 */
if(!s->budget--) { s->failed_pc=0x0c0be134u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be1feu,2);
goto P_0c0be136;
P_0c0be136: /* original 4e0b, guest PC 0x0c0be136 */
if(!s->budget--) { s->failed_pc=0x0c0be136u; return 0; }
target=r[14];
r[16]=0x0c0be13au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be13au) { target=s->pc; goto dispatch; }
goto P_0c0be13a;
P_0c0be138: /* original 0009, guest PC 0x0c0be138 */
if(!s->budget--) { s->failed_pc=0x0c0be138u; return 0; }
goto P_0c0be13a;
P_0c0be13a: /* original 9461, guest PC 0x0c0be13a */
if(!s->budget--) { s->failed_pc=0x0c0be13au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be200u,2);
goto P_0c0be13c;
P_0c0be13c: /* original 4e0b, guest PC 0x0c0be13c */
if(!s->budget--) { s->failed_pc=0x0c0be13cu; return 0; }
target=r[14];
r[16]=0x0c0be140u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be140u) { target=s->pc; goto dispatch; }
goto P_0c0be140;
P_0c0be13e: /* original 0009, guest PC 0x0c0be13e */
if(!s->budget--) { s->failed_pc=0x0c0be13eu; return 0; }
goto P_0c0be140;
P_0c0be140: /* original 945f, guest PC 0x0c0be140 */
if(!s->budget--) { s->failed_pc=0x0c0be140u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be202u,2);
goto P_0c0be142;
P_0c0be142: /* original 4e0b, guest PC 0x0c0be142 */
if(!s->budget--) { s->failed_pc=0x0c0be142u; return 0; }
target=r[14];
r[16]=0x0c0be146u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be146u) { target=s->pc; goto dispatch; }
goto P_0c0be146;
P_0c0be144: /* original 0009, guest PC 0x0c0be144 */
if(!s->budget--) { s->failed_pc=0x0c0be144u; return 0; }
goto P_0c0be146;
P_0c0be146: /* original 945d, guest PC 0x0c0be146 */
if(!s->budget--) { s->failed_pc=0x0c0be146u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be204u,2);
goto P_0c0be148;
P_0c0be148: /* original 4e0b, guest PC 0x0c0be148 */
if(!s->budget--) { s->failed_pc=0x0c0be148u; return 0; }
target=r[14];
r[16]=0x0c0be14cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be14cu) { target=s->pc; goto dispatch; }
goto P_0c0be14c;
P_0c0be14a: /* original 0009, guest PC 0x0c0be14a */
if(!s->budget--) { s->failed_pc=0x0c0be14au; return 0; }
goto P_0c0be14c;
P_0c0be14c: /* original 945b, guest PC 0x0c0be14c */
if(!s->budget--) { s->failed_pc=0x0c0be14cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be206u,2);
goto P_0c0be14e;
P_0c0be14e: /* original 4e0b, guest PC 0x0c0be14e */
if(!s->budget--) { s->failed_pc=0x0c0be14eu; return 0; }
target=r[14];
r[16]=0x0c0be152u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be152u) { target=s->pc; goto dispatch; }
goto P_0c0be152;
P_0c0be150: /* original 0009, guest PC 0x0c0be150 */
if(!s->budget--) { s->failed_pc=0x0c0be150u; return 0; }
goto P_0c0be152;
P_0c0be152: /* original 9459, guest PC 0x0c0be152 */
if(!s->budget--) { s->failed_pc=0x0c0be152u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be208u,2);
goto P_0c0be154;
P_0c0be154: /* original 4e0b, guest PC 0x0c0be154 */
if(!s->budget--) { s->failed_pc=0x0c0be154u; return 0; }
target=r[14];
r[16]=0x0c0be158u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be158u) { target=s->pc; goto dispatch; }
goto P_0c0be158;
P_0c0be156: /* original 0009, guest PC 0x0c0be156 */
if(!s->budget--) { s->failed_pc=0x0c0be156u; return 0; }
goto P_0c0be158;
P_0c0be158: /* original 9457, guest PC 0x0c0be158 */
if(!s->budget--) { s->failed_pc=0x0c0be158u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be20au,2);
goto P_0c0be15a;
P_0c0be15a: /* original 4e0b, guest PC 0x0c0be15a */
if(!s->budget--) { s->failed_pc=0x0c0be15au; return 0; }
target=r[14];
r[16]=0x0c0be15eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be15eu) { target=s->pc; goto dispatch; }
goto P_0c0be15e;
P_0c0be15c: /* original 0009, guest PC 0x0c0be15c */
if(!s->budget--) { s->failed_pc=0x0c0be15cu; return 0; }
goto P_0c0be15e;
P_0c0be15e: /* original 9455, guest PC 0x0c0be15e */
if(!s->budget--) { s->failed_pc=0x0c0be15eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be20cu,2);
goto P_0c0be160;
P_0c0be160: /* original 4e0b, guest PC 0x0c0be160 */
if(!s->budget--) { s->failed_pc=0x0c0be160u; return 0; }
target=r[14];
r[16]=0x0c0be164u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be164u) { target=s->pc; goto dispatch; }
goto P_0c0be164;
P_0c0be162: /* original 0009, guest PC 0x0c0be162 */
if(!s->budget--) { s->failed_pc=0x0c0be162u; return 0; }
goto P_0c0be164;
P_0c0be164: /* original 9453, guest PC 0x0c0be164 */
if(!s->budget--) { s->failed_pc=0x0c0be164u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be20eu,2);
goto P_0c0be166;
P_0c0be166: /* original 4e0b, guest PC 0x0c0be166 */
if(!s->budget--) { s->failed_pc=0x0c0be166u; return 0; }
target=r[14];
r[16]=0x0c0be16au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be16au) { target=s->pc; goto dispatch; }
goto P_0c0be16a;
P_0c0be168: /* original 0009, guest PC 0x0c0be168 */
if(!s->budget--) { s->failed_pc=0x0c0be168u; return 0; }
goto P_0c0be16a;
P_0c0be16a: /* original 9451, guest PC 0x0c0be16a */
if(!s->budget--) { s->failed_pc=0x0c0be16au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be210u,2);
goto P_0c0be16c;
P_0c0be16c: /* original 4e0b, guest PC 0x0c0be16c */
if(!s->budget--) { s->failed_pc=0x0c0be16cu; return 0; }
target=r[14];
r[16]=0x0c0be170u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be170u) { target=s->pc; goto dispatch; }
goto P_0c0be170;
P_0c0be16e: /* original 0009, guest PC 0x0c0be16e */
if(!s->budget--) { s->failed_pc=0x0c0be16eu; return 0; }
goto P_0c0be170;
P_0c0be170: /* original 944f, guest PC 0x0c0be170 */
if(!s->budget--) { s->failed_pc=0x0c0be170u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be212u,2);
goto P_0c0be172;
P_0c0be172: /* original 4e0b, guest PC 0x0c0be172 */
if(!s->budget--) { s->failed_pc=0x0c0be172u; return 0; }
target=r[14];
r[16]=0x0c0be176u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be176u) { target=s->pc; goto dispatch; }
goto P_0c0be176;
P_0c0be174: /* original 0009, guest PC 0x0c0be174 */
if(!s->budget--) { s->failed_pc=0x0c0be174u; return 0; }
goto P_0c0be176;
P_0c0be176: /* original 944d, guest PC 0x0c0be176 */
if(!s->budget--) { s->failed_pc=0x0c0be176u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be214u,2);
goto P_0c0be178;
P_0c0be178: /* original 4e0b, guest PC 0x0c0be178 */
if(!s->budget--) { s->failed_pc=0x0c0be178u; return 0; }
target=r[14];
r[16]=0x0c0be17cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be17cu) { target=s->pc; goto dispatch; }
goto P_0c0be17c;
P_0c0be17a: /* original 0009, guest PC 0x0c0be17a */
if(!s->budget--) { s->failed_pc=0x0c0be17au; return 0; }
goto P_0c0be17c;
P_0c0be17c: /* original 944b, guest PC 0x0c0be17c */
if(!s->budget--) { s->failed_pc=0x0c0be17cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be216u,2);
goto P_0c0be17e;
P_0c0be17e: /* original 4e0b, guest PC 0x0c0be17e */
if(!s->budget--) { s->failed_pc=0x0c0be17eu; return 0; }
target=r[14];
r[16]=0x0c0be182u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be182u) { target=s->pc; goto dispatch; }
goto P_0c0be182;
P_0c0be180: /* original 0009, guest PC 0x0c0be180 */
if(!s->budget--) { s->failed_pc=0x0c0be180u; return 0; }
goto P_0c0be182;
P_0c0be182: /* original 9449, guest PC 0x0c0be182 */
if(!s->budget--) { s->failed_pc=0x0c0be182u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be218u,2);
goto P_0c0be184;
P_0c0be184: /* original 4e0b, guest PC 0x0c0be184 */
if(!s->budget--) { s->failed_pc=0x0c0be184u; return 0; }
target=r[14];
r[16]=0x0c0be188u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be188u) { target=s->pc; goto dispatch; }
goto P_0c0be188;
P_0c0be186: /* original 0009, guest PC 0x0c0be186 */
if(!s->budget--) { s->failed_pc=0x0c0be186u; return 0; }
goto P_0c0be188;
P_0c0be188: /* original 9447, guest PC 0x0c0be188 */
if(!s->budget--) { s->failed_pc=0x0c0be188u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be21au,2);
goto P_0c0be18a;
P_0c0be18a: /* original 4e0b, guest PC 0x0c0be18a */
if(!s->budget--) { s->failed_pc=0x0c0be18au; return 0; }
target=r[14];
r[16]=0x0c0be18eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be18eu) { target=s->pc; goto dispatch; }
goto P_0c0be18e;
P_0c0be18c: /* original 0009, guest PC 0x0c0be18c */
if(!s->budget--) { s->failed_pc=0x0c0be18cu; return 0; }
goto P_0c0be18e;
P_0c0be18e: /* original 9445, guest PC 0x0c0be18e */
if(!s->budget--) { s->failed_pc=0x0c0be18eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be21cu,2);
goto P_0c0be190;
P_0c0be190: /* original 4e0b, guest PC 0x0c0be190 */
if(!s->budget--) { s->failed_pc=0x0c0be190u; return 0; }
target=r[14];
r[16]=0x0c0be194u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be194u) { target=s->pc; goto dispatch; }
goto P_0c0be194;
P_0c0be192: /* original 0009, guest PC 0x0c0be192 */
if(!s->budget--) { s->failed_pc=0x0c0be192u; return 0; }
goto P_0c0be194;
P_0c0be194: /* original 9443, guest PC 0x0c0be194 */
if(!s->budget--) { s->failed_pc=0x0c0be194u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be21eu,2);
goto P_0c0be196;
P_0c0be196: /* original 4e0b, guest PC 0x0c0be196 */
if(!s->budget--) { s->failed_pc=0x0c0be196u; return 0; }
target=r[14];
r[16]=0x0c0be19au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be19au) { target=s->pc; goto dispatch; }
goto P_0c0be19a;
P_0c0be198: /* original 0009, guest PC 0x0c0be198 */
if(!s->budget--) { s->failed_pc=0x0c0be198u; return 0; }
goto P_0c0be19a;
P_0c0be19a: /* original 9441, guest PC 0x0c0be19a */
if(!s->budget--) { s->failed_pc=0x0c0be19au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be220u,2);
goto P_0c0be19c;
P_0c0be19c: /* original 4e0b, guest PC 0x0c0be19c */
if(!s->budget--) { s->failed_pc=0x0c0be19cu; return 0; }
target=r[14];
r[16]=0x0c0be1a0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be1a0u) { target=s->pc; goto dispatch; }
goto P_0c0be1a0;
P_0c0be19e: /* original 0009, guest PC 0x0c0be19e */
if(!s->budget--) { s->failed_pc=0x0c0be19eu; return 0; }
goto P_0c0be1a0;
P_0c0be1a0: /* original 943f, guest PC 0x0c0be1a0 */
if(!s->budget--) { s->failed_pc=0x0c0be1a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be222u,2);
goto P_0c0be1a2;
P_0c0be1a2: /* original 4e0b, guest PC 0x0c0be1a2 */
if(!s->budget--) { s->failed_pc=0x0c0be1a2u; return 0; }
target=r[14];
r[16]=0x0c0be1a6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be1a6u) { target=s->pc; goto dispatch; }
goto P_0c0be1a6;
P_0c0be1a4: /* original 0009, guest PC 0x0c0be1a4 */
if(!s->budget--) { s->failed_pc=0x0c0be1a4u; return 0; }
goto P_0c0be1a6;
P_0c0be1a6: /* original 943d, guest PC 0x0c0be1a6 */
if(!s->budget--) { s->failed_pc=0x0c0be1a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be224u,2);
goto P_0c0be1a8;
P_0c0be1a8: /* original 4e0b, guest PC 0x0c0be1a8 */
if(!s->budget--) { s->failed_pc=0x0c0be1a8u; return 0; }
target=r[14];
r[16]=0x0c0be1acu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be1acu) { target=s->pc; goto dispatch; }
goto P_0c0be1ac;
P_0c0be1aa: /* original 0009, guest PC 0x0c0be1aa */
if(!s->budget--) { s->failed_pc=0x0c0be1aau; return 0; }
goto P_0c0be1ac;
P_0c0be1ac: /* original 943b, guest PC 0x0c0be1ac */
if(!s->budget--) { s->failed_pc=0x0c0be1acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be226u,2);
goto P_0c0be1ae;
P_0c0be1ae: /* original 4e0b, guest PC 0x0c0be1ae */
if(!s->budget--) { s->failed_pc=0x0c0be1aeu; return 0; }
target=r[14];
r[16]=0x0c0be1b2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be1b2u) { target=s->pc; goto dispatch; }
goto P_0c0be1b2;
P_0c0be1b0: /* original 0009, guest PC 0x0c0be1b0 */
if(!s->budget--) { s->failed_pc=0x0c0be1b0u; return 0; }
goto P_0c0be1b2;
P_0c0be1b2: /* original 9439, guest PC 0x0c0be1b2 */
if(!s->budget--) { s->failed_pc=0x0c0be1b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be228u,2);
goto P_0c0be1b4;
P_0c0be1b4: /* original a03c, guest PC 0x0c0be1b4 */
if(!s->budget--) { s->failed_pc=0x0c0be1b4u; return 0; }
goto P_0c0be230;
P_0c0be1b6: /* original 0009, guest PC 0x0c0be1b6 */
if(!s->budget--) { s->failed_pc=0x0c0be1b6u; return 0; }
return vf3_matrix_family(0x0c0be1b8u,s,ram);
P_0c0be230: /* original 4e0b, guest PC 0x0c0be230 */
if(!s->budget--) { s->failed_pc=0x0c0be230u; return 0; }
target=r[14];
r[16]=0x0c0be234u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be234u) { target=s->pc; goto dispatch; }
goto P_0c0be234;
P_0c0be232: /* original 0009, guest PC 0x0c0be232 */
if(!s->budget--) { s->failed_pc=0x0c0be232u; return 0; }
goto P_0c0be234;
P_0c0be234: /* original 9482, guest PC 0x0c0be234 */
if(!s->budget--) { s->failed_pc=0x0c0be234u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be33cu,2);
goto P_0c0be236;
P_0c0be236: /* original 4e0b, guest PC 0x0c0be236 */
if(!s->budget--) { s->failed_pc=0x0c0be236u; return 0; }
target=r[14];
r[16]=0x0c0be23au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be23au) { target=s->pc; goto dispatch; }
goto P_0c0be23a;
P_0c0be238: /* original 0009, guest PC 0x0c0be238 */
if(!s->budget--) { s->failed_pc=0x0c0be238u; return 0; }
goto P_0c0be23a;
P_0c0be23a: /* original 9480, guest PC 0x0c0be23a */
if(!s->budget--) { s->failed_pc=0x0c0be23au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be33eu,2);
goto P_0c0be23c;
P_0c0be23c: /* original 4e0b, guest PC 0x0c0be23c */
if(!s->budget--) { s->failed_pc=0x0c0be23cu; return 0; }
target=r[14];
r[16]=0x0c0be240u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be240u) { target=s->pc; goto dispatch; }
goto P_0c0be240;
P_0c0be23e: /* original 0009, guest PC 0x0c0be23e */
if(!s->budget--) { s->failed_pc=0x0c0be23eu; return 0; }
goto P_0c0be240;
P_0c0be240: /* original 947e, guest PC 0x0c0be240 */
if(!s->budget--) { s->failed_pc=0x0c0be240u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be340u,2);
goto P_0c0be242;
P_0c0be242: /* original 4e0b, guest PC 0x0c0be242 */
if(!s->budget--) { s->failed_pc=0x0c0be242u; return 0; }
target=r[14];
r[16]=0x0c0be246u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be246u) { target=s->pc; goto dispatch; }
goto P_0c0be246;
P_0c0be244: /* original 0009, guest PC 0x0c0be244 */
if(!s->budget--) { s->failed_pc=0x0c0be244u; return 0; }
goto P_0c0be246;
P_0c0be246: /* original 947c, guest PC 0x0c0be246 */
if(!s->budget--) { s->failed_pc=0x0c0be246u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be342u,2);
goto P_0c0be248;
P_0c0be248: /* original 4e0b, guest PC 0x0c0be248 */
if(!s->budget--) { s->failed_pc=0x0c0be248u; return 0; }
target=r[14];
r[16]=0x0c0be24cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be24cu) { target=s->pc; goto dispatch; }
goto P_0c0be24c;
P_0c0be24a: /* original 0009, guest PC 0x0c0be24a */
if(!s->budget--) { s->failed_pc=0x0c0be24au; return 0; }
goto P_0c0be24c;
P_0c0be24c: /* original 947a, guest PC 0x0c0be24c */
if(!s->budget--) { s->failed_pc=0x0c0be24cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be344u,2);
goto P_0c0be24e;
P_0c0be24e: /* original 4e0b, guest PC 0x0c0be24e */
if(!s->budget--) { s->failed_pc=0x0c0be24eu; return 0; }
target=r[14];
r[16]=0x0c0be252u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be252u) { target=s->pc; goto dispatch; }
goto P_0c0be252;
P_0c0be250: /* original 0009, guest PC 0x0c0be250 */
if(!s->budget--) { s->failed_pc=0x0c0be250u; return 0; }
goto P_0c0be252;
P_0c0be252: /* original 9478, guest PC 0x0c0be252 */
if(!s->budget--) { s->failed_pc=0x0c0be252u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be346u,2);
goto P_0c0be254;
P_0c0be254: /* original 4e0b, guest PC 0x0c0be254 */
if(!s->budget--) { s->failed_pc=0x0c0be254u; return 0; }
target=r[14];
r[16]=0x0c0be258u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be258u) { target=s->pc; goto dispatch; }
goto P_0c0be258;
P_0c0be256: /* original 0009, guest PC 0x0c0be256 */
if(!s->budget--) { s->failed_pc=0x0c0be256u; return 0; }
goto P_0c0be258;
P_0c0be258: /* original 9476, guest PC 0x0c0be258 */
if(!s->budget--) { s->failed_pc=0x0c0be258u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be348u,2);
goto P_0c0be25a;
P_0c0be25a: /* original 4e0b, guest PC 0x0c0be25a */
if(!s->budget--) { s->failed_pc=0x0c0be25au; return 0; }
target=r[14];
r[16]=0x0c0be25eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be25eu) { target=s->pc; goto dispatch; }
goto P_0c0be25e;
P_0c0be25c: /* original 0009, guest PC 0x0c0be25c */
if(!s->budget--) { s->failed_pc=0x0c0be25cu; return 0; }
goto P_0c0be25e;
P_0c0be25e: /* original 9474, guest PC 0x0c0be25e */
if(!s->budget--) { s->failed_pc=0x0c0be25eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be34au,2);
goto P_0c0be260;
P_0c0be260: /* original 4e0b, guest PC 0x0c0be260 */
if(!s->budget--) { s->failed_pc=0x0c0be260u; return 0; }
target=r[14];
r[16]=0x0c0be264u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be264u) { target=s->pc; goto dispatch; }
goto P_0c0be264;
P_0c0be262: /* original 0009, guest PC 0x0c0be262 */
if(!s->budget--) { s->failed_pc=0x0c0be262u; return 0; }
goto P_0c0be264;
P_0c0be264: /* original 9472, guest PC 0x0c0be264 */
if(!s->budget--) { s->failed_pc=0x0c0be264u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be34cu,2);
goto P_0c0be266;
P_0c0be266: /* original 4e0b, guest PC 0x0c0be266 */
if(!s->budget--) { s->failed_pc=0x0c0be266u; return 0; }
target=r[14];
r[16]=0x0c0be26au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be26au) { target=s->pc; goto dispatch; }
goto P_0c0be26a;
P_0c0be268: /* original 0009, guest PC 0x0c0be268 */
if(!s->budget--) { s->failed_pc=0x0c0be268u; return 0; }
goto P_0c0be26a;
P_0c0be26a: /* original 9470, guest PC 0x0c0be26a */
if(!s->budget--) { s->failed_pc=0x0c0be26au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be34eu,2);
goto P_0c0be26c;
P_0c0be26c: /* original 4e0b, guest PC 0x0c0be26c */
if(!s->budget--) { s->failed_pc=0x0c0be26cu; return 0; }
target=r[14];
r[16]=0x0c0be270u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be270u) { target=s->pc; goto dispatch; }
goto P_0c0be270;
P_0c0be26e: /* original 0009, guest PC 0x0c0be26e */
if(!s->budget--) { s->failed_pc=0x0c0be26eu; return 0; }
goto P_0c0be270;
P_0c0be270: /* original 946e, guest PC 0x0c0be270 */
if(!s->budget--) { s->failed_pc=0x0c0be270u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be350u,2);
goto P_0c0be272;
P_0c0be272: /* original 4e0b, guest PC 0x0c0be272 */
if(!s->budget--) { s->failed_pc=0x0c0be272u; return 0; }
target=r[14];
r[16]=0x0c0be276u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be276u) { target=s->pc; goto dispatch; }
goto P_0c0be276;
P_0c0be274: /* original 0009, guest PC 0x0c0be274 */
if(!s->budget--) { s->failed_pc=0x0c0be274u; return 0; }
goto P_0c0be276;
P_0c0be276: /* original 946c, guest PC 0x0c0be276 */
if(!s->budget--) { s->failed_pc=0x0c0be276u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be352u,2);
goto P_0c0be278;
P_0c0be278: /* original 4e0b, guest PC 0x0c0be278 */
if(!s->budget--) { s->failed_pc=0x0c0be278u; return 0; }
target=r[14];
r[16]=0x0c0be27cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be27cu) { target=s->pc; goto dispatch; }
goto P_0c0be27c;
P_0c0be27a: /* original 0009, guest PC 0x0c0be27a */
if(!s->budget--) { s->failed_pc=0x0c0be27au; return 0; }
goto P_0c0be27c;
P_0c0be27c: /* original 946a, guest PC 0x0c0be27c */
if(!s->budget--) { s->failed_pc=0x0c0be27cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be354u,2);
goto P_0c0be27e;
P_0c0be27e: /* original 4e0b, guest PC 0x0c0be27e */
if(!s->budget--) { s->failed_pc=0x0c0be27eu; return 0; }
target=r[14];
r[16]=0x0c0be282u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be282u) { target=s->pc; goto dispatch; }
goto P_0c0be282;
P_0c0be280: /* original 0009, guest PC 0x0c0be280 */
if(!s->budget--) { s->failed_pc=0x0c0be280u; return 0; }
goto P_0c0be282;
P_0c0be282: /* original 9468, guest PC 0x0c0be282 */
if(!s->budget--) { s->failed_pc=0x0c0be282u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be356u,2);
goto P_0c0be284;
P_0c0be284: /* original 4e0b, guest PC 0x0c0be284 */
if(!s->budget--) { s->failed_pc=0x0c0be284u; return 0; }
target=r[14];
r[16]=0x0c0be288u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be288u) { target=s->pc; goto dispatch; }
goto P_0c0be288;
P_0c0be286: /* original 0009, guest PC 0x0c0be286 */
if(!s->budget--) { s->failed_pc=0x0c0be286u; return 0; }
goto P_0c0be288;
P_0c0be288: /* original 9466, guest PC 0x0c0be288 */
if(!s->budget--) { s->failed_pc=0x0c0be288u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be358u,2);
goto P_0c0be28a;
P_0c0be28a: /* original 4e0b, guest PC 0x0c0be28a */
if(!s->budget--) { s->failed_pc=0x0c0be28au; return 0; }
target=r[14];
r[16]=0x0c0be28eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be28eu) { target=s->pc; goto dispatch; }
goto P_0c0be28e;
P_0c0be28c: /* original 0009, guest PC 0x0c0be28c */
if(!s->budget--) { s->failed_pc=0x0c0be28cu; return 0; }
goto P_0c0be28e;
P_0c0be28e: /* original 9464, guest PC 0x0c0be28e */
if(!s->budget--) { s->failed_pc=0x0c0be28eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be35au,2);
goto P_0c0be290;
P_0c0be290: /* original 4e0b, guest PC 0x0c0be290 */
if(!s->budget--) { s->failed_pc=0x0c0be290u; return 0; }
target=r[14];
r[16]=0x0c0be294u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be294u) { target=s->pc; goto dispatch; }
goto P_0c0be294;
P_0c0be292: /* original 0009, guest PC 0x0c0be292 */
if(!s->budget--) { s->failed_pc=0x0c0be292u; return 0; }
goto P_0c0be294;
P_0c0be294: /* original 9462, guest PC 0x0c0be294 */
if(!s->budget--) { s->failed_pc=0x0c0be294u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be35cu,2);
goto P_0c0be296;
P_0c0be296: /* original 4e0b, guest PC 0x0c0be296 */
if(!s->budget--) { s->failed_pc=0x0c0be296u; return 0; }
target=r[14];
r[16]=0x0c0be29au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be29au) { target=s->pc; goto dispatch; }
goto P_0c0be29a;
P_0c0be298: /* original 0009, guest PC 0x0c0be298 */
if(!s->budget--) { s->failed_pc=0x0c0be298u; return 0; }
goto P_0c0be29a;
P_0c0be29a: /* original 9460, guest PC 0x0c0be29a */
if(!s->budget--) { s->failed_pc=0x0c0be29au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be35eu,2);
goto P_0c0be29c;
P_0c0be29c: /* original 4e0b, guest PC 0x0c0be29c */
if(!s->budget--) { s->failed_pc=0x0c0be29cu; return 0; }
target=r[14];
r[16]=0x0c0be2a0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be2a0u) { target=s->pc; goto dispatch; }
goto P_0c0be2a0;
P_0c0be29e: /* original 0009, guest PC 0x0c0be29e */
if(!s->budget--) { s->failed_pc=0x0c0be29eu; return 0; }
goto P_0c0be2a0;
P_0c0be2a0: /* original 945e, guest PC 0x0c0be2a0 */
if(!s->budget--) { s->failed_pc=0x0c0be2a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be360u,2);
goto P_0c0be2a2;
P_0c0be2a2: /* original 4e0b, guest PC 0x0c0be2a2 */
if(!s->budget--) { s->failed_pc=0x0c0be2a2u; return 0; }
target=r[14];
r[16]=0x0c0be2a6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be2a6u) { target=s->pc; goto dispatch; }
goto P_0c0be2a6;
P_0c0be2a4: /* original 0009, guest PC 0x0c0be2a4 */
if(!s->budget--) { s->failed_pc=0x0c0be2a4u; return 0; }
goto P_0c0be2a6;
P_0c0be2a6: /* original 945c, guest PC 0x0c0be2a6 */
if(!s->budget--) { s->failed_pc=0x0c0be2a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be362u,2);
goto P_0c0be2a8;
P_0c0be2a8: /* original 4e0b, guest PC 0x0c0be2a8 */
if(!s->budget--) { s->failed_pc=0x0c0be2a8u; return 0; }
target=r[14];
r[16]=0x0c0be2acu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be2acu) { target=s->pc; goto dispatch; }
goto P_0c0be2ac;
P_0c0be2aa: /* original 0009, guest PC 0x0c0be2aa */
if(!s->budget--) { s->failed_pc=0x0c0be2aau; return 0; }
goto P_0c0be2ac;
P_0c0be2ac: /* original 945a, guest PC 0x0c0be2ac */
if(!s->budget--) { s->failed_pc=0x0c0be2acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be364u,2);
goto P_0c0be2ae;
P_0c0be2ae: /* original 4e0b, guest PC 0x0c0be2ae */
if(!s->budget--) { s->failed_pc=0x0c0be2aeu; return 0; }
target=r[14];
r[16]=0x0c0be2b2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be2b2u) { target=s->pc; goto dispatch; }
goto P_0c0be2b2;
P_0c0be2b0: /* original 0009, guest PC 0x0c0be2b0 */
if(!s->budget--) { s->failed_pc=0x0c0be2b0u; return 0; }
goto P_0c0be2b2;
P_0c0be2b2: /* original 9458, guest PC 0x0c0be2b2 */
if(!s->budget--) { s->failed_pc=0x0c0be2b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be366u,2);
goto P_0c0be2b4;
P_0c0be2b4: /* original 4e0b, guest PC 0x0c0be2b4 */
if(!s->budget--) { s->failed_pc=0x0c0be2b4u; return 0; }
target=r[14];
r[16]=0x0c0be2b8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be2b8u) { target=s->pc; goto dispatch; }
goto P_0c0be2b8;
P_0c0be2b6: /* original 0009, guest PC 0x0c0be2b6 */
if(!s->budget--) { s->failed_pc=0x0c0be2b6u; return 0; }
goto P_0c0be2b8;
P_0c0be2b8: /* original 9456, guest PC 0x0c0be2b8 */
if(!s->budget--) { s->failed_pc=0x0c0be2b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be368u,2);
goto P_0c0be2ba;
P_0c0be2ba: /* original 4e0b, guest PC 0x0c0be2ba */
if(!s->budget--) { s->failed_pc=0x0c0be2bau; return 0; }
target=r[14];
r[16]=0x0c0be2beu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be2beu) { target=s->pc; goto dispatch; }
goto P_0c0be2be;
P_0c0be2bc: /* original 0009, guest PC 0x0c0be2bc */
if(!s->budget--) { s->failed_pc=0x0c0be2bcu; return 0; }
goto P_0c0be2be;
P_0c0be2be: /* original 9454, guest PC 0x0c0be2be */
if(!s->budget--) { s->failed_pc=0x0c0be2beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be36au,2);
goto P_0c0be2c0;
P_0c0be2c0: /* original 4e0b, guest PC 0x0c0be2c0 */
if(!s->budget--) { s->failed_pc=0x0c0be2c0u; return 0; }
target=r[14];
r[16]=0x0c0be2c4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be2c4u) { target=s->pc; goto dispatch; }
goto P_0c0be2c4;
P_0c0be2c2: /* original 0009, guest PC 0x0c0be2c2 */
if(!s->budget--) { s->failed_pc=0x0c0be2c2u; return 0; }
goto P_0c0be2c4;
P_0c0be2c4: /* original 9452, guest PC 0x0c0be2c4 */
if(!s->budget--) { s->failed_pc=0x0c0be2c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be36cu,2);
goto P_0c0be2c6;
P_0c0be2c6: /* original 4e0b, guest PC 0x0c0be2c6 */
if(!s->budget--) { s->failed_pc=0x0c0be2c6u; return 0; }
target=r[14];
r[16]=0x0c0be2cau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be2cau) { target=s->pc; goto dispatch; }
goto P_0c0be2ca;
P_0c0be2c8: /* original 0009, guest PC 0x0c0be2c8 */
if(!s->budget--) { s->failed_pc=0x0c0be2c8u; return 0; }
goto P_0c0be2ca;
P_0c0be2ca: /* original 9450, guest PC 0x0c0be2ca */
if(!s->budget--) { s->failed_pc=0x0c0be2cau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be36eu,2);
goto P_0c0be2cc;
P_0c0be2cc: /* original 4e0b, guest PC 0x0c0be2cc */
if(!s->budget--) { s->failed_pc=0x0c0be2ccu; return 0; }
target=r[14];
r[16]=0x0c0be2d0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be2d0u) { target=s->pc; goto dispatch; }
goto P_0c0be2d0;
P_0c0be2ce: /* original 0009, guest PC 0x0c0be2ce */
if(!s->budget--) { s->failed_pc=0x0c0be2ceu; return 0; }
goto P_0c0be2d0;
P_0c0be2d0: /* original 944e, guest PC 0x0c0be2d0 */
if(!s->budget--) { s->failed_pc=0x0c0be2d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be370u,2);
goto P_0c0be2d2;
P_0c0be2d2: /* original 4e0b, guest PC 0x0c0be2d2 */
if(!s->budget--) { s->failed_pc=0x0c0be2d2u; return 0; }
target=r[14];
r[16]=0x0c0be2d6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be2d6u) { target=s->pc; goto dispatch; }
goto P_0c0be2d6;
P_0c0be2d4: /* original 0009, guest PC 0x0c0be2d4 */
if(!s->budget--) { s->failed_pc=0x0c0be2d4u; return 0; }
goto P_0c0be2d6;
P_0c0be2d6: /* original 944c, guest PC 0x0c0be2d6 */
if(!s->budget--) { s->failed_pc=0x0c0be2d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be372u,2);
goto P_0c0be2d8;
P_0c0be2d8: /* original 4e0b, guest PC 0x0c0be2d8 */
if(!s->budget--) { s->failed_pc=0x0c0be2d8u; return 0; }
target=r[14];
r[16]=0x0c0be2dcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be2dcu) { target=s->pc; goto dispatch; }
goto P_0c0be2dc;
P_0c0be2da: /* original 0009, guest PC 0x0c0be2da */
if(!s->budget--) { s->failed_pc=0x0c0be2dau; return 0; }
goto P_0c0be2dc;
P_0c0be2dc: /* original 944a, guest PC 0x0c0be2dc */
if(!s->budget--) { s->failed_pc=0x0c0be2dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be374u,2);
goto P_0c0be2de;
P_0c0be2de: /* original 4e0b, guest PC 0x0c0be2de */
if(!s->budget--) { s->failed_pc=0x0c0be2deu; return 0; }
target=r[14];
r[16]=0x0c0be2e2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be2e2u) { target=s->pc; goto dispatch; }
goto P_0c0be2e2;
P_0c0be2e0: /* original 0009, guest PC 0x0c0be2e0 */
if(!s->budget--) { s->failed_pc=0x0c0be2e0u; return 0; }
goto P_0c0be2e2;
P_0c0be2e2: /* original 9448, guest PC 0x0c0be2e2 */
if(!s->budget--) { s->failed_pc=0x0c0be2e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be376u,2);
goto P_0c0be2e4;
P_0c0be2e4: /* original 4e0b, guest PC 0x0c0be2e4 */
if(!s->budget--) { s->failed_pc=0x0c0be2e4u; return 0; }
target=r[14];
r[16]=0x0c0be2e8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be2e8u) { target=s->pc; goto dispatch; }
goto P_0c0be2e8;
P_0c0be2e6: /* original 0009, guest PC 0x0c0be2e6 */
if(!s->budget--) { s->failed_pc=0x0c0be2e6u; return 0; }
goto P_0c0be2e8;
P_0c0be2e8: /* original 9446, guest PC 0x0c0be2e8 */
if(!s->budget--) { s->failed_pc=0x0c0be2e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be378u,2);
goto P_0c0be2ea;
P_0c0be2ea: /* original 4e0b, guest PC 0x0c0be2ea */
if(!s->budget--) { s->failed_pc=0x0c0be2eau; return 0; }
target=r[14];
r[16]=0x0c0be2eeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be2eeu) { target=s->pc; goto dispatch; }
goto P_0c0be2ee;
P_0c0be2ec: /* original 0009, guest PC 0x0c0be2ec */
if(!s->budget--) { s->failed_pc=0x0c0be2ecu; return 0; }
goto P_0c0be2ee;
P_0c0be2ee: /* original 9444, guest PC 0x0c0be2ee */
if(!s->budget--) { s->failed_pc=0x0c0be2eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be37au,2);
goto P_0c0be2f0;
P_0c0be2f0: /* original 4e0b, guest PC 0x0c0be2f0 */
if(!s->budget--) { s->failed_pc=0x0c0be2f0u; return 0; }
target=r[14];
r[16]=0x0c0be2f4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be2f4u) { target=s->pc; goto dispatch; }
goto P_0c0be2f4;
P_0c0be2f2: /* original 0009, guest PC 0x0c0be2f2 */
if(!s->budget--) { s->failed_pc=0x0c0be2f2u; return 0; }
goto P_0c0be2f4;
P_0c0be2f4: /* original 9442, guest PC 0x0c0be2f4 */
if(!s->budget--) { s->failed_pc=0x0c0be2f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be37cu,2);
goto P_0c0be2f6;
P_0c0be2f6: /* original 4e0b, guest PC 0x0c0be2f6 */
if(!s->budget--) { s->failed_pc=0x0c0be2f6u; return 0; }
target=r[14];
r[16]=0x0c0be2fau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be2fau) { target=s->pc; goto dispatch; }
goto P_0c0be2fa;
P_0c0be2f8: /* original 0009, guest PC 0x0c0be2f8 */
if(!s->budget--) { s->failed_pc=0x0c0be2f8u; return 0; }
goto P_0c0be2fa;
P_0c0be2fa: /* original 9440, guest PC 0x0c0be2fa */
if(!s->budget--) { s->failed_pc=0x0c0be2fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be37eu,2);
goto P_0c0be2fc;
P_0c0be2fc: /* original 4e0b, guest PC 0x0c0be2fc */
if(!s->budget--) { s->failed_pc=0x0c0be2fcu; return 0; }
target=r[14];
r[16]=0x0c0be300u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be300u) { target=s->pc; goto dispatch; }
goto P_0c0be300;
P_0c0be2fe: /* original 0009, guest PC 0x0c0be2fe */
if(!s->budget--) { s->failed_pc=0x0c0be2feu; return 0; }
goto P_0c0be300;
P_0c0be300: /* original 943e, guest PC 0x0c0be300 */
if(!s->budget--) { s->failed_pc=0x0c0be300u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be380u,2);
goto P_0c0be302;
P_0c0be302: /* original 4e0b, guest PC 0x0c0be302 */
if(!s->budget--) { s->failed_pc=0x0c0be302u; return 0; }
target=r[14];
r[16]=0x0c0be306u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be306u) { target=s->pc; goto dispatch; }
goto P_0c0be306;
P_0c0be304: /* original 0009, guest PC 0x0c0be304 */
if(!s->budget--) { s->failed_pc=0x0c0be304u; return 0; }
goto P_0c0be306;
P_0c0be306: /* original 943c, guest PC 0x0c0be306 */
if(!s->budget--) { s->failed_pc=0x0c0be306u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be382u,2);
goto P_0c0be308;
P_0c0be308: /* original 4e0b, guest PC 0x0c0be308 */
if(!s->budget--) { s->failed_pc=0x0c0be308u; return 0; }
target=r[14];
r[16]=0x0c0be30cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be30cu) { target=s->pc; goto dispatch; }
goto P_0c0be30c;
P_0c0be30a: /* original 0009, guest PC 0x0c0be30a */
if(!s->budget--) { s->failed_pc=0x0c0be30au; return 0; }
goto P_0c0be30c;
P_0c0be30c: /* original 943a, guest PC 0x0c0be30c */
if(!s->budget--) { s->failed_pc=0x0c0be30cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be384u,2);
goto P_0c0be30e;
P_0c0be30e: /* original 4e0b, guest PC 0x0c0be30e */
if(!s->budget--) { s->failed_pc=0x0c0be30eu; return 0; }
target=r[14];
r[16]=0x0c0be312u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be312u) { target=s->pc; goto dispatch; }
goto P_0c0be312;
P_0c0be310: /* original 0009, guest PC 0x0c0be310 */
if(!s->budget--) { s->failed_pc=0x0c0be310u; return 0; }
goto P_0c0be312;
P_0c0be312: /* original 9438, guest PC 0x0c0be312 */
if(!s->budget--) { s->failed_pc=0x0c0be312u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be386u,2);
goto P_0c0be314;
P_0c0be314: /* original 4e0b, guest PC 0x0c0be314 */
if(!s->budget--) { s->failed_pc=0x0c0be314u; return 0; }
target=r[14];
r[16]=0x0c0be318u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be318u) { target=s->pc; goto dispatch; }
goto P_0c0be318;
P_0c0be316: /* original 0009, guest PC 0x0c0be316 */
if(!s->budget--) { s->failed_pc=0x0c0be316u; return 0; }
goto P_0c0be318;
P_0c0be318: /* original 9436, guest PC 0x0c0be318 */
if(!s->budget--) { s->failed_pc=0x0c0be318u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be388u,2);
goto P_0c0be31a;
P_0c0be31a: /* original 4e0b, guest PC 0x0c0be31a */
if(!s->budget--) { s->failed_pc=0x0c0be31au; return 0; }
target=r[14];
r[16]=0x0c0be31eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be31eu) { target=s->pc; goto dispatch; }
goto P_0c0be31e;
P_0c0be31c: /* original 0009, guest PC 0x0c0be31c */
if(!s->budget--) { s->failed_pc=0x0c0be31cu; return 0; }
goto P_0c0be31e;
P_0c0be31e: /* original 9434, guest PC 0x0c0be31e */
if(!s->budget--) { s->failed_pc=0x0c0be31eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be38au,2);
goto P_0c0be320;
P_0c0be320: /* original 4e0b, guest PC 0x0c0be320 */
if(!s->budget--) { s->failed_pc=0x0c0be320u; return 0; }
target=r[14];
r[16]=0x0c0be324u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be324u) { target=s->pc; goto dispatch; }
goto P_0c0be324;
P_0c0be322: /* original 0009, guest PC 0x0c0be322 */
if(!s->budget--) { s->failed_pc=0x0c0be322u; return 0; }
goto P_0c0be324;
P_0c0be324: /* original 9432, guest PC 0x0c0be324 */
if(!s->budget--) { s->failed_pc=0x0c0be324u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be38cu,2);
goto P_0c0be326;
P_0c0be326: /* original 4e0b, guest PC 0x0c0be326 */
if(!s->budget--) { s->failed_pc=0x0c0be326u; return 0; }
target=r[14];
r[16]=0x0c0be32au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be32au) { target=s->pc; goto dispatch; }
goto P_0c0be32a;
P_0c0be328: /* original 0009, guest PC 0x0c0be328 */
if(!s->budget--) { s->failed_pc=0x0c0be328u; return 0; }
goto P_0c0be32a;
P_0c0be32a: /* original 9430, guest PC 0x0c0be32a */
if(!s->budget--) { s->failed_pc=0x0c0be32au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be38eu,2);
goto P_0c0be32c;
P_0c0be32c: /* original 4e0b, guest PC 0x0c0be32c */
if(!s->budget--) { s->failed_pc=0x0c0be32cu; return 0; }
target=r[14];
r[16]=0x0c0be330u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be330u) { target=s->pc; goto dispatch; }
goto P_0c0be330;
P_0c0be32e: /* original 0009, guest PC 0x0c0be32e */
if(!s->budget--) { s->failed_pc=0x0c0be32eu; return 0; }
goto P_0c0be330;
P_0c0be330: /* original 942e, guest PC 0x0c0be330 */
if(!s->budget--) { s->failed_pc=0x0c0be330u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0be390u,2);
goto P_0c0be332;
P_0c0be332: /* original 4e0b, guest PC 0x0c0be332 */
if(!s->budget--) { s->failed_pc=0x0c0be332u; return 0; }
target=r[14];
r[16]=0x0c0be336u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0be336u) { target=s->pc; goto dispatch; }
goto P_0c0be336;
P_0c0be334: /* original 0009, guest PC 0x0c0be334 */
if(!s->budget--) { s->failed_pc=0x0c0be334u; return 0; }
goto P_0c0be336;
P_0c0be336: /* original 4f26, guest PC 0x0c0be336 */
if(!s->budget--) { s->failed_pc=0x0c0be336u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0be338;
P_0c0be338: /* original 000b, guest PC 0x0c0be338 */
if(!s->budget--) { s->failed_pc=0x0c0be338u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0be33a: /* original 6ef6, guest PC 0x0c0be33a */
if(!s->budget--) { s->failed_pc=0x0c0be33au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0be33cu,s,ram);
P_0c0c10a2: /* original 2fe6, guest PC 0x0c0c10a2 */
if(!s->budget--) { s->failed_pc=0x0c0c10a2u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c10a4;
P_0c0c10a4: /* original e600, guest PC 0x0c0c10a4 */
if(!s->budget--) { s->failed_pc=0x0c0c10a4u; return 0; }
r[6]=0x00000000u;
goto P_0c0c10a6;
P_0c0c10a6: /* original 2fd6, guest PC 0x0c0c10a6 */
if(!s->budget--) { s->failed_pc=0x0c0c10a6u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0c10a8;
P_0c0c10a8: /* original d54d, guest PC 0x0c0c10a8 */
if(!s->budget--) { s->failed_pc=0x0c0c10a8u; return 0; }
r[5]=read(ram,0x0c0c11e0u,4);
goto P_0c0c10aa;
P_0c0c10aa: /* original 7ff0, guest PC 0x0c0c10aa */
if(!s->budget--) { s->failed_pc=0x0c0c10aau; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0c10ac;
P_0c0c10ac: /* original 6353, guest PC 0x0c0c10ac */
if(!s->budget--) { s->failed_pc=0x0c0c10acu; return 0; }
r[3]=r[5];
goto P_0c0c10ae;
P_0c0c10ae: /* original 7358, guest PC 0x0c0c10ae */
if(!s->budget--) { s->failed_pc=0x0c0c10aeu; return 0; }
r[3]+=0x00000058u;
goto P_0c0c10b0;
P_0c0c10b0: /* original 6253, guest PC 0x0c0c10b0 */
if(!s->budget--) { s->failed_pc=0x0c0c10b0u; return 0; }
r[2]=r[5];
goto P_0c0c10b2;
P_0c0c10b2: /* original 722c, guest PC 0x0c0c10b2 */
if(!s->budget--) { s->failed_pc=0x0c0c10b2u; return 0; }
r[2]+=0x0000002cu;
goto P_0c0c10b4;
P_0c0c10b4: /* original 2f52, guest PC 0x0c0c10b4 */
if(!s->budget--) { s->failed_pc=0x0c0c10b4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c10b6;
P_0c0c10b6: /* original 1f31, guest PC 0x0c0c10b6 */
if(!s->budget--) { s->failed_pc=0x0c0c10b6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c10b8;
P_0c0c10b8: /* original 1f23, guest PC 0x0c0c10b8 */
if(!s->budget--) { s->failed_pc=0x0c0c10b8u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0c10ba;
P_0c0c10ba: /* original 9388, guest PC 0x0c0c10ba */
if(!s->budget--) { s->failed_pc=0x0c0c10bau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11ceu,2);
goto P_0c0c10bc;
P_0c0c10bc: /* original 335c, guest PC 0x0c0c10bc */
if(!s->budget--) { s->failed_pc=0x0c0c10bcu; return 0; }
r[3]+=r[5];
goto P_0c0c10be;
P_0c0c10be: /* original 1f32, guest PC 0x0c0c10be */
if(!s->budget--) { s->failed_pc=0x0c0c10beu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0c10c0;
P_0c0c10c0: /* original 9286, guest PC 0x0c0c10c0 */
if(!s->budget--) { s->failed_pc=0x0c0c10c0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11d0u,2);
goto P_0c0c10c2;
P_0c0c10c2: /* original 2248, guest PC 0x0c0c10c2 */
if(!s->budget--) { s->failed_pc=0x0c0c10c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0c10c4;
P_0c0c10c4: /* original 8d03, guest PC 0x0c0c10c4 */
if(!s->budget--) { s->failed_pc=0x0c0c10c4u; return 0; }
cond=r[17]&1u;
r[5]=0x00000004u;
if(cond) { goto P_0c0c10ce; }
goto P_0c0c10c8;
P_0c0c10c6: /* original e504, guest PC 0x0c0c10c6 */
if(!s->budget--) { s->failed_pc=0x0c0c10c6u; return 0; }
r[5]=0x00000004u;
goto P_0c0c10c8;
P_0c0c10c8: /* original 6763, guest PC 0x0c0c10c8 */
if(!s->budget--) { s->failed_pc=0x0c0c10c8u; return 0; }
r[7]=r[6];
goto P_0c0c10ca;
P_0c0c10ca: /* original a002, guest PC 0x0c0c10ca */
if(!s->budget--) { s->failed_pc=0x0c0c10cau; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10d2;
P_0c0c10cc: /* original 7601, guest PC 0x0c0c10cc */
if(!s->budget--) { s->failed_pc=0x0c0c10ccu; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10ce;
P_0c0c10ce: /* original 6753, guest PC 0x0c0c10ce */
if(!s->budget--) { s->failed_pc=0x0c0c10ceu; return 0; }
r[7]=r[5];
goto P_0c0c10d0;
P_0c0c10d0: /* original 7501, guest PC 0x0c0c10d0 */
if(!s->budget--) { s->failed_pc=0x0c0c10d0u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c10d2;
P_0c0c10d2: /* original 937e, guest PC 0x0c0c10d2 */
if(!s->budget--) { s->failed_pc=0x0c0c10d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11d2u,2);
goto P_0c0c10d4;
P_0c0c10d4: /* original 2348, guest PC 0x0c0c10d4 */
if(!s->budget--) { s->failed_pc=0x0c0c10d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0c10d6;
P_0c0c10d6: /* original 8902, guest PC 0x0c0c10d6 */
if(!s->budget--) { s->failed_pc=0x0c0c10d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c10de; }
goto P_0c0c10d8;
P_0c0c10d8: /* original 6d63, guest PC 0x0c0c10d8 */
if(!s->budget--) { s->failed_pc=0x0c0c10d8u; return 0; }
r[13]=r[6];
goto P_0c0c10da;
P_0c0c10da: /* original a002, guest PC 0x0c0c10da */
if(!s->budget--) { s->failed_pc=0x0c0c10dau; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10e2;
P_0c0c10dc: /* original 7601, guest PC 0x0c0c10dc */
if(!s->budget--) { s->failed_pc=0x0c0c10dcu; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10de;
P_0c0c10de: /* original 6d53, guest PC 0x0c0c10de */
if(!s->budget--) { s->failed_pc=0x0c0c10deu; return 0; }
r[13]=r[5];
goto P_0c0c10e0;
P_0c0c10e0: /* original 7501, guest PC 0x0c0c10e0 */
if(!s->budget--) { s->failed_pc=0x0c0c10e0u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c10e2;
P_0c0c10e2: /* original 9277, guest PC 0x0c0c10e2 */
if(!s->budget--) { s->failed_pc=0x0c0c10e2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11d4u,2);
goto P_0c0c10e4;
P_0c0c10e4: /* original 2248, guest PC 0x0c0c10e4 */
if(!s->budget--) { s->failed_pc=0x0c0c10e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0c10e6;
P_0c0c10e6: /* original 8902, guest PC 0x0c0c10e6 */
if(!s->budget--) { s->failed_pc=0x0c0c10e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c10ee; }
goto P_0c0c10e8;
P_0c0c10e8: /* original 6e63, guest PC 0x0c0c10e8 */
if(!s->budget--) { s->failed_pc=0x0c0c10e8u; return 0; }
r[14]=r[6];
goto P_0c0c10ea;
P_0c0c10ea: /* original a002, guest PC 0x0c0c10ea */
if(!s->budget--) { s->failed_pc=0x0c0c10eau; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10f2;
P_0c0c10ec: /* original 7601, guest PC 0x0c0c10ec */
if(!s->budget--) { s->failed_pc=0x0c0c10ecu; return 0; }
r[6]+=0x00000001u;
goto P_0c0c10ee;
P_0c0c10ee: /* original 6e53, guest PC 0x0c0c10ee */
if(!s->budget--) { s->failed_pc=0x0c0c10eeu; return 0; }
r[14]=r[5];
goto P_0c0c10f0;
P_0c0c10f0: /* original 7501, guest PC 0x0c0c10f0 */
if(!s->budget--) { s->failed_pc=0x0c0c10f0u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c10f2;
P_0c0c10f2: /* original 9370, guest PC 0x0c0c10f2 */
if(!s->budget--) { s->failed_pc=0x0c0c10f2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11d6u,2);
goto P_0c0c10f4;
P_0c0c10f4: /* original 2438, guest PC 0x0c0c10f4 */
if(!s->budget--) { s->failed_pc=0x0c0c10f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c10f6;
P_0c0c10f6: /* original 8901, guest PC 0x0c0c10f6 */
if(!s->budget--) { s->failed_pc=0x0c0c10f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c10fc; }
goto P_0c0c10f8;
P_0c0c10f8: /* original a001, guest PC 0x0c0c10f8 */
if(!s->budget--) { s->failed_pc=0x0c0c10f8u; return 0; }
r[4]=r[6];
goto P_0c0c10fe;
P_0c0c10fa: /* original 6463, guest PC 0x0c0c10fa */
if(!s->budget--) { s->failed_pc=0x0c0c10fau; return 0; }
r[4]=r[6];
goto P_0c0c10fc;
P_0c0c10fc: /* original 6453, guest PC 0x0c0c10fc */
if(!s->budget--) { s->failed_pc=0x0c0c10fcu; return 0; }
r[4]=r[5];
goto P_0c0c10fe;
P_0c0c10fe: /* original 63f2, guest PC 0x0c0c10fe */
if(!s->budget--) { s->failed_pc=0x0c0c10feu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c1100;
P_0c0c1100: /* original e026, guest PC 0x0c0c1100 */
if(!s->budget--) { s->failed_pc=0x0c0c1100u; return 0; }
r[0]=0x00000026u;
goto P_0c0c1102;
P_0c0c1102: /* original 0375, guest PC 0x0c0c1102 */
if(!s->budget--) { s->failed_pc=0x0c0c1102u; return 0; }
write(ram,r[3]+r[0],r[7],2);
goto P_0c0c1104;
P_0c0c1104: /* original e026, guest PC 0x0c0c1104 */
if(!s->budget--) { s->failed_pc=0x0c0c1104u; return 0; }
r[0]=0x00000026u;
goto P_0c0c1106;
P_0c0c1106: /* original 53f3, guest PC 0x0c0c1106 */
if(!s->budget--) { s->failed_pc=0x0c0c1106u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0c1108;
P_0c0c1108: /* original 03d5, guest PC 0x0c0c1108 */
if(!s->budget--) { s->failed_pc=0x0c0c1108u; return 0; }
write(ram,r[3]+r[0],r[13],2);
goto P_0c0c110a;
P_0c0c110a: /* original e026, guest PC 0x0c0c110a */
if(!s->budget--) { s->failed_pc=0x0c0c110au; return 0; }
r[0]=0x00000026u;
goto P_0c0c110c;
P_0c0c110c: /* original 53f1, guest PC 0x0c0c110c */
if(!s->budget--) { s->failed_pc=0x0c0c110cu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c110e;
P_0c0c110e: /* original 03e5, guest PC 0x0c0c110e */
if(!s->budget--) { s->failed_pc=0x0c0c110eu; return 0; }
write(ram,r[3]+r[0],r[14],2);
goto P_0c0c1110;
P_0c0c1110: /* original e026, guest PC 0x0c0c1110 */
if(!s->budget--) { s->failed_pc=0x0c0c1110u; return 0; }
r[0]=0x00000026u;
goto P_0c0c1112;
P_0c0c1112: /* original 53f2, guest PC 0x0c0c1112 */
if(!s->budget--) { s->failed_pc=0x0c0c1112u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c1114;
P_0c0c1114: /* original 7f10, guest PC 0x0c0c1114 */
if(!s->budget--) { s->failed_pc=0x0c0c1114u; return 0; }
r[15]+=0x00000010u;
goto P_0c0c1116;
P_0c0c1116: /* original 0345, guest PC 0x0c0c1116 */
if(!s->budget--) { s->failed_pc=0x0c0c1116u; return 0; }
write(ram,r[3]+r[0],r[4],2);
goto P_0c0c1118;
P_0c0c1118: /* original 6df6, guest PC 0x0c0c1118 */
if(!s->budget--) { s->failed_pc=0x0c0c1118u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c111a;
P_0c0c111a: /* original 000b, guest PC 0x0c0c111a */
if(!s->budget--) { s->failed_pc=0x0c0c111au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c111c: /* original 6ef6, guest PC 0x0c0c111c */
if(!s->budget--) { s->failed_pc=0x0c0c111cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c111e;
P_0c0c111e: /* original 4f22, guest PC 0x0c0c111e */
if(!s->budget--) { s->failed_pc=0x0c0c111eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c1120;
P_0c0c1120: /* original e022, guest PC 0x0c0c1120 */
if(!s->budget--) { s->failed_pc=0x0c0c1120u; return 0; }
r[0]=0x00000022u;
goto P_0c0c1122;
P_0c0c1122: /* original 7ff0, guest PC 0x0c0c1122 */
if(!s->budget--) { s->failed_pc=0x0c0c1122u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0c1124;
P_0c0c1124: /* original 2f52, guest PC 0x0c0c1124 */
if(!s->budget--) { s->failed_pc=0x0c0c1124u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0c1126;
P_0c0c1126: /* original 1f61, guest PC 0x0c0c1126 */
if(!s->budget--) { s->failed_pc=0x0c0c1126u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0c1128;
P_0c0c1128: /* original d52d, guest PC 0x0c0c1128 */
if(!s->budget--) { s->failed_pc=0x0c0c1128u; return 0; }
r[5]=read(ram,0x0c0c11e0u,4);
goto P_0c0c112a;
P_0c0c112a: /* original 6353, guest PC 0x0c0c112a */
if(!s->budget--) { s->failed_pc=0x0c0c112au; return 0; }
r[3]=r[5];
goto P_0c0c112c;
P_0c0c112c: /* original 7358, guest PC 0x0c0c112c */
if(!s->budget--) { s->failed_pc=0x0c0c112cu; return 0; }
r[3]+=0x00000058u;
goto P_0c0c112e;
P_0c0c112e: /* original 1f32, guest PC 0x0c0c112e */
if(!s->budget--) { s->failed_pc=0x0c0c112eu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0c1130;
P_0c0c1130: /* original 6753, guest PC 0x0c0c1130 */
if(!s->budget--) { s->failed_pc=0x0c0c1130u; return 0; }
r[7]=r[5];
goto P_0c0c1132;
P_0c0c1132: /* original 6273, guest PC 0x0c0c1132 */
if(!s->budget--) { s->failed_pc=0x0c0c1132u; return 0; }
r[2]=r[7];
goto P_0c0c1134;
P_0c0c1134: /* original 722c, guest PC 0x0c0c1134 */
if(!s->budget--) { s->failed_pc=0x0c0c1134u; return 0; }
r[2]+=0x0000002cu;
goto P_0c0c1136;
P_0c0c1136: /* original 1f23, guest PC 0x0c0c1136 */
if(!s->budget--) { s->failed_pc=0x0c0c1136u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0c1138;
P_0c0c1138: /* original 9649, guest PC 0x0c0c1138 */
if(!s->budget--) { s->failed_pc=0x0c0c1138u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c11ceu,2);
goto P_0c0c113a;
P_0c0c113a: /* original 037d, guest PC 0x0c0c113a */
if(!s->budget--) { s->failed_pc=0x0c0c113au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+r[0],2);
goto P_0c0c113c;
P_0c0c113c: /* original 365c, guest PC 0x0c0c113c */
if(!s->budget--) { s->failed_pc=0x0c0c113cu; return 0; }
r[6]+=r[5];
goto P_0c0c113e;
P_0c0c113e: /* original d529, guest PC 0x0c0c113e */
if(!s->budget--) { s->failed_pc=0x0c0c113eu; return 0; }
r[5]=read(ram,0x0c0c11e4u,4);
goto P_0c0c1140;
P_0c0c1140: /* original 2359, guest PC 0x0c0c1140 */
if(!s->budget--) { s->failed_pc=0x0c0c1140u; return 0; }
r[3]&=r[5];
goto P_0c0c1142;
P_0c0c1142: /* original 0735, guest PC 0x0c0c1142 */
if(!s->budget--) { s->failed_pc=0x0c0c1142u; return 0; }
write(ram,r[7]+r[0],r[3],2);
goto P_0c0c1144;
P_0c0c1144: /* original e022, guest PC 0x0c0c1144 */
if(!s->budget--) { s->failed_pc=0x0c0c1144u; return 0; }
r[0]=0x00000022u;
goto P_0c0c1146;
P_0c0c1146: /* original 53f2, guest PC 0x0c0c1146 */
if(!s->budget--) { s->failed_pc=0x0c0c1146u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c1148;
P_0c0c1148: /* original 023d, guest PC 0x0c0c1148 */
if(!s->budget--) { s->failed_pc=0x0c0c1148u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c114a;
P_0c0c114a: /* original 2259, guest PC 0x0c0c114a */
if(!s->budget--) { s->failed_pc=0x0c0c114au; return 0; }
r[2]&=r[5];
goto P_0c0c114c;
P_0c0c114c: /* original 0325, guest PC 0x0c0c114c */
if(!s->budget--) { s->failed_pc=0x0c0c114cu; return 0; }
write(ram,r[3]+r[0],r[2],2);
goto P_0c0c114e;
P_0c0c114e: /* original e022, guest PC 0x0c0c114e */
if(!s->budget--) { s->failed_pc=0x0c0c114eu; return 0; }
r[0]=0x00000022u;
goto P_0c0c1150;
P_0c0c1150: /* original 53f3, guest PC 0x0c0c1150 */
if(!s->budget--) { s->failed_pc=0x0c0c1150u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0c1152;
P_0c0c1152: /* original 023d, guest PC 0x0c0c1152 */
if(!s->budget--) { s->failed_pc=0x0c0c1152u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c1154;
P_0c0c1154: /* original 2259, guest PC 0x0c0c1154 */
if(!s->budget--) { s->failed_pc=0x0c0c1154u; return 0; }
r[2]&=r[5];
goto P_0c0c1156;
P_0c0c1156: /* original 0325, guest PC 0x0c0c1156 */
if(!s->budget--) { s->failed_pc=0x0c0c1156u; return 0; }
write(ram,r[3]+r[0],r[2],2);
goto P_0c0c1158;
P_0c0c1158: /* original 036d, guest PC 0x0c0c1158 */
if(!s->budget--) { s->failed_pc=0x0c0c1158u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c0c115a;
P_0c0c115a: /* original 2359, guest PC 0x0c0c115a */
if(!s->budget--) { s->failed_pc=0x0c0c115au; return 0; }
r[3]&=r[5];
goto P_0c0c115c;
P_0c0c115c: /* original bfa1, guest PC 0x0c0c115c */
if(!s->budget--) { s->failed_pc=0x0c0c115cu; return 0; }
target=0x0c0c10a2u; r[16]=0x0c0c1160u;
write(ram,r[6]+r[0],r[3],2);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1160u) { target=s->pc; goto dispatch; }
goto P_0c0c1160;
P_0c0c115e: /* original 0635, guest PC 0x0c0c115e */
if(!s->budget--) { s->failed_pc=0x0c0c115eu; return 0; }
write(ram,r[6]+r[0],r[3],2);
goto P_0c0c1160;
P_0c0c1160: /* original 63f2, guest PC 0x0c0c1160 */
if(!s->budget--) { s->failed_pc=0x0c0c1160u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c1162;
P_0c0c1162: /* original e022, guest PC 0x0c0c1162 */
if(!s->budget--) { s->failed_pc=0x0c0c1162u; return 0; }
r[0]=0x00000022u;
goto P_0c0c1164;
P_0c0c1164: /* original e202, guest PC 0x0c0c1164 */
if(!s->budget--) { s->failed_pc=0x0c0c1164u; return 0; }
r[2]=0x00000002u;
goto P_0c0c1166;
P_0c0c1166: /* original 013d, guest PC 0x0c0c1166 */
if(!s->budget--) { s->failed_pc=0x0c0c1166u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c1168;
P_0c0c1168: /* original 212b, guest PC 0x0c0c1168 */
if(!s->budget--) { s->failed_pc=0x0c0c1168u; return 0; }
r[1]|=r[2];
goto P_0c0c116a;
P_0c0c116a: /* original 0315, guest PC 0x0c0c116a */
if(!s->budget--) { s->failed_pc=0x0c0c116au; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c0c116c;
P_0c0c116c: /* original e022, guest PC 0x0c0c116c */
if(!s->budget--) { s->failed_pc=0x0c0c116cu; return 0; }
r[0]=0x00000022u;
goto P_0c0c116e;
P_0c0c116e: /* original 53f1, guest PC 0x0c0c116e */
if(!s->budget--) { s->failed_pc=0x0c0c116eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c1170;
P_0c0c1170: /* original 7f10, guest PC 0x0c0c1170 */
if(!s->budget--) { s->failed_pc=0x0c0c1170u; return 0; }
r[15]+=0x00000010u;
goto P_0c0c1172;
P_0c0c1172: /* original 4f26, guest PC 0x0c0c1172 */
if(!s->budget--) { s->failed_pc=0x0c0c1172u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c1174;
P_0c0c1174: /* original 013d, guest PC 0x0c0c1174 */
if(!s->budget--) { s->failed_pc=0x0c0c1174u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c0c1176;
P_0c0c1176: /* original 212b, guest PC 0x0c0c1176 */
if(!s->budget--) { s->failed_pc=0x0c0c1176u; return 0; }
r[1]|=r[2];
goto P_0c0c1178;
P_0c0c1178: /* original 0315, guest PC 0x0c0c1178 */
if(!s->budget--) { s->failed_pc=0x0c0c1178u; return 0; }
write(ram,r[3]+r[0],r[1],2);
goto P_0c0c117a;
P_0c0c117a: /* original 000b, guest PC 0x0c0c117a */
if(!s->budget--) { s->failed_pc=0x0c0c117au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c117c: /* original 0009, guest PC 0x0c0c117c */
if(!s->budget--) { s->failed_pc=0x0c0c117cu; return 0; }
return vf3_matrix_family(0x0c0c117eu,s,ram);
P_0c0c19e8: /* original 2fe6, guest PC 0x0c0c19e8 */
if(!s->budget--) { s->failed_pc=0x0c0c19e8u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c19ea;
P_0c0c19ea: /* original 2fd6, guest PC 0x0c0c19ea */
if(!s->budget--) { s->failed_pc=0x0c0c19eau; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0c19ec;
P_0c0c19ec: /* original 4f22, guest PC 0x0c0c19ec */
if(!s->budget--) { s->failed_pc=0x0c0c19ecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c19ee;
P_0c0c19ee: /* original 934b, guest PC 0x0c0c19ee */
if(!s->budget--) { s->failed_pc=0x0c0c19eeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1a88u,2);
goto P_0c0c19f0;
P_0c0c19f0: /* original dd27, guest PC 0x0c0c19f0 */
if(!s->budget--) { s->failed_pc=0x0c0c19f0u; return 0; }
r[13]=read(ram,0x0c0c1a90u,4);
goto P_0c0c19f2;
P_0c0c19f2: /* original 7ff8, guest PC 0x0c0c19f2 */
if(!s->budget--) { s->failed_pc=0x0c0c19f2u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c19f4;
P_0c0c19f4: /* original 33dc, guest PC 0x0c0c19f4 */
if(!s->budget--) { s->failed_pc=0x0c0c19f4u; return 0; }
r[3]+=r[13];
goto P_0c0c19f6;
P_0c0c19f6: /* original 2f32, guest PC 0x0c0c19f6 */
if(!s->budget--) { s->failed_pc=0x0c0c19f6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c19f8;
P_0c0c19f8: /* original 9047, guest PC 0x0c0c19f8 */
if(!s->budget--) { s->failed_pc=0x0c0c19f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1a8au,2);
goto P_0c0c19fa;
P_0c0c19fa: /* original 0ede, guest PC 0x0c0c19fa */
if(!s->budget--) { s->failed_pc=0x0c0c19fau; return 0; }
r[14]=read(ram,r[13]+r[0],4);
goto P_0c0c19fc;
P_0c0c19fc: /* original 7004, guest PC 0x0c0c19fc */
if(!s->budget--) { s->failed_pc=0x0c0c19fcu; return 0; }
r[0]+=0x00000004u;
goto P_0c0c19fe;
P_0c0c19fe: /* original 03de, guest PC 0x0c0c19fe */
if(!s->budget--) { s->failed_pc=0x0c0c19feu; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c0c1a00;
P_0c0c1a00: /* original 1f31, guest PC 0x0c0c1a00 */
if(!s->budget--) { s->failed_pc=0x0c0c1a00u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c1a02;
P_0c0c1a02: /* original 9641, guest PC 0x0c0c1a02 */
if(!s->budget--) { s->failed_pc=0x0c0c1a02u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1a88u,2);
goto P_0c0c1a04;
P_0c0c1a04: /* original 9442, guest PC 0x0c0c1a04 */
if(!s->budget--) { s->failed_pc=0x0c0c1a04u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1a8cu,2);
goto P_0c0c1a06;
P_0c0c1a06: /* original 36dc, guest PC 0x0c0c1a06 */
if(!s->budget--) { s->failed_pc=0x0c0c1a06u; return 0; }
r[6]+=r[13];
goto P_0c0c1a08;
P_0c0c1a08: /* original bb89, guest PC 0x0c0c1a08 */
if(!s->budget--) { s->failed_pc=0x0c0c1a08u; return 0; }
target=0x0c0c111eu; r[16]=0x0c0c1a0cu;
r[5]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1a0cu) { target=s->pc; goto dispatch; }
goto P_0c0c1a0c;
P_0c0c1a0a: /* original 65d3, guest PC 0x0c0c1a0a */
if(!s->budget--) { s->failed_pc=0x0c0c1a0au; return 0; }
r[5]=r[13];
goto P_0c0c1a0c;
P_0c0c1a0c: /* original e210, guest PC 0x0c0c1a0c */
if(!s->budget--) { s->failed_pc=0x0c0c1a0cu; return 0; }
r[2]=0x00000010u;
goto P_0c0c1a0e;
P_0c0c1a0e: /* original 3e22, guest PC 0x0c0c1a0e */
if(!s->budget--) { s->failed_pc=0x0c0c1a0eu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[2])!=0);
goto P_0c0c1a10;
P_0c0c1a10: /* original 8916, guest PC 0x0c0c1a10 */
if(!s->budget--) { s->failed_pc=0x0c0c1a10u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1a40; }
goto P_0c0c1a12;
P_0c0c1a12: /* original d420, guest PC 0x0c0c1a12 */
if(!s->budget--) { s->failed_pc=0x0c0c1a12u; return 0; }
r[4]=read(ram,0x0c0c1a94u,4);
goto P_0c0c1a14;
P_0c0c1a14: /* original 2ee8, guest PC 0x0c0c1a14 */
if(!s->budget--) { s->failed_pc=0x0c0c1a14u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c1a16;
P_0c0c1a16: /* original 8d0e, guest PC 0x0c0c1a16 */
if(!s->budget--) { s->failed_pc=0x0c0c1a16u; return 0; }
cond=r[17]&1u;
r[5]=0x00000001u;
if(cond) { goto P_0c0c1a36; }
goto P_0c0c1a1a;
P_0c0c1a18: /* original e501, guest PC 0x0c0c1a18 */
if(!s->budget--) { s->failed_pc=0x0c0c1a18u; return 0; }
r[5]=0x00000001u;
goto P_0c0c1a1a;
P_0c0c1a1a: /* original 66e3, guest PC 0x0c0c1a1a */
if(!s->budget--) { s->failed_pc=0x0c0c1a1au; return 0; }
r[6]=r[14];
goto P_0c0c1a1c;
P_0c0c1a1c: /* original 4615, guest PC 0x0c0c1a1c */
if(!s->budget--) { s->failed_pc=0x0c0c1a1cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c0c1a1e;
P_0c0c1a1e: /* original 8b0a, guest PC 0x0c0c1a1e */
if(!s->budget--) { s->failed_pc=0x0c0c1a1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1a36; }
goto P_0c0c1a20;
P_0c0c1a20: /* original 6043, guest PC 0x0c0c1a20 */
if(!s->budget--) { s->failed_pc=0x0c0c1a20u; return 0; }
r[0]=r[4];
goto P_0c0c1a22;
P_0c0c1a22: /* original 6753, guest PC 0x0c0c1a22 */
if(!s->budget--) { s->failed_pc=0x0c0c1a22u; return 0; }
r[7]=r[5];
goto P_0c0c1a24;
P_0c0c1a24: /* original 4001, guest PC 0x0c0c1a24 */
if(!s->budget--) { s->failed_pc=0x0c0c1a24u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c0c1a26;
P_0c0c1a26: /* original 76ff, guest PC 0x0c0c1a26 */
if(!s->budget--) { s->failed_pc=0x0c0c1a26u; return 0; }
r[6]+=0xffffffffu;
goto P_0c0c1a28;
P_0c0c1a28: /* original 4700, guest PC 0x0c0c1a28 */
if(!s->budget--) { s->failed_pc=0x0c0c1a28u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c0c1a2a;
P_0c0c1a2a: /* original 4615, guest PC 0x0c0c1a2a */
if(!s->budget--) { s->failed_pc=0x0c0c1a2au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c0c1a2c;
P_0c0c1a2c: /* original 600d, guest PC 0x0c0c1a2c */
if(!s->budget--) { s->failed_pc=0x0c0c1a2cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c1a2e;
P_0c0c1a2e: /* original 677d, guest PC 0x0c0c1a2e */
if(!s->budget--) { s->failed_pc=0x0c0c1a2eu; return 0; }
r[7]=r[7]&65535u;
goto P_0c0c1a30;
P_0c0c1a30: /* original 240b, guest PC 0x0c0c1a30 */
if(!s->budget--) { s->failed_pc=0x0c0c1a30u; return 0; }
r[4]|=r[0];
goto P_0c0c1a32;
P_0c0c1a32: /* original 8df5, guest PC 0x0c0c1a32 */
if(!s->budget--) { s->failed_pc=0x0c0c1a32u; return 0; }
cond=r[17]&1u;
r[5]|=r[7];
if(cond) { goto P_0c0c1a20; }
goto P_0c0c1a36;
P_0c0c1a34: /* original 257b, guest PC 0x0c0c1a34 */
if(!s->budget--) { s->failed_pc=0x0c0c1a34u; return 0; }
r[5]|=r[7];
goto P_0c0c1a36;
P_0c0c1a36: /* original 53f1, guest PC 0x0c0c1a36 */
if(!s->budget--) { s->failed_pc=0x0c0c1a36u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c1a38;
P_0c0c1a38: /* original 62f2, guest PC 0x0c0c1a38 */
if(!s->budget--) { s->failed_pc=0x0c0c1a38u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c1a3a;
P_0c0c1a3a: /* original 3320, guest PC 0x0c0c1a3a */
if(!s->budget--) { s->failed_pc=0x0c0c1a3au; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0c1a3c;
P_0c0c1a3c: /* original 8900, guest PC 0x0c0c1a3c */
if(!s->budget--) { s->failed_pc=0x0c0c1a3cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1a40; }
goto P_0c0c1a3e;
P_0c0c1a3e: /* original 2ee8, guest PC 0x0c0c1a3e */
if(!s->budget--) { s->failed_pc=0x0c0c1a3eu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c1a40;
P_0c0c1a40: /* original e310, guest PC 0x0c0c1a40 */
if(!s->budget--) { s->failed_pc=0x0c0c1a40u; return 0; }
r[3]=0x00000010u;
goto P_0c0c1a42;
P_0c0c1a42: /* original 7e01, guest PC 0x0c0c1a42 */
if(!s->budget--) { s->failed_pc=0x0c0c1a42u; return 0; }
r[14]+=0x00000001u;
goto P_0c0c1a44;
P_0c0c1a44: /* original 3e32, guest PC 0x0c0c1a44 */
if(!s->budget--) { s->failed_pc=0x0c0c1a44u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[3])!=0);
goto P_0c0c1a46;
P_0c0c1a46: /* original 8b05, guest PC 0x0c0c1a46 */
if(!s->budget--) { s->failed_pc=0x0c0c1a46u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1a54; }
goto P_0c0c1a48;
P_0c0c1a48: /* original e121, guest PC 0x0c0c1a48 */
if(!s->budget--) { s->failed_pc=0x0c0c1a48u; return 0; }
r[1]=0x00000021u;
goto P_0c0c1a4a;
P_0c0c1a4a: /* original 3e16, guest PC 0x0c0c1a4a */
if(!s->budget--) { s->failed_pc=0x0c0c1a4au; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[1])!=0);
goto P_0c0c1a4c;
P_0c0c1a4c: /* original 8902, guest PC 0x0c0c1a4c */
if(!s->budget--) { s->failed_pc=0x0c0c1a4cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1a54; }
goto P_0c0c1a4e;
P_0c0c1a4e: /* original 60e3, guest PC 0x0c0c1a4e */
if(!s->budget--) { s->failed_pc=0x0c0c1a4eu; return 0; }
r[0]=r[14];
goto P_0c0c1a50;
P_0c0c1a50: /* original eeff, guest PC 0x0c0c1a50 */
if(!s->budget--) { s->failed_pc=0x0c0c1a50u; return 0; }
r[14]=0xffffffffu;
goto P_0c0c1a52;
P_0c0c1a52: /* original 8810, guest PC 0x0c0c1a52 */
if(!s->budget--) { s->failed_pc=0x0c0c1a52u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c0c1a54;
P_0c0c1a54: /* original 7f08, guest PC 0x0c0c1a54 */
if(!s->budget--) { s->failed_pc=0x0c0c1a54u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c1a56;
P_0c0c1a56: /* original 9018, guest PC 0x0c0c1a56 */
if(!s->budget--) { s->failed_pc=0x0c0c1a56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1a8au,2);
goto P_0c0c1a58;
P_0c0c1a58: /* original 4f26, guest PC 0x0c0c1a58 */
if(!s->budget--) { s->failed_pc=0x0c0c1a58u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c1a5a;
P_0c0c1a5a: /* original 0de6, guest PC 0x0c0c1a5a */
if(!s->budget--) { s->failed_pc=0x0c0c1a5au; return 0; }
write(ram,r[13]+r[0],r[14],4);
goto P_0c0c1a5c;
P_0c0c1a5c: /* original 6df6, guest PC 0x0c0c1a5c */
if(!s->budget--) { s->failed_pc=0x0c0c1a5cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c1a5e;
P_0c0c1a5e: /* original 000b, guest PC 0x0c0c1a5e */
if(!s->budget--) { s->failed_pc=0x0c0c1a5eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c1a60: /* original 6ef6, guest PC 0x0c0c1a60 */
if(!s->budget--) { s->failed_pc=0x0c0c1a60u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c1a62u,s,ram);
P_0c0c1d86: /* original 2fe6, guest PC 0x0c0c1d86 */
if(!s->budget--) { s->failed_pc=0x0c0c1d86u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c1d88;
P_0c0c1d88: /* original 6e43, guest PC 0x0c0c1d88 */
if(!s->budget--) { s->failed_pc=0x0c0c1d88u; return 0; }
r[14]=r[4];
goto P_0c0c1d8a;
P_0c0c1d8a: /* original 2fd6, guest PC 0x0c0c1d8a */
if(!s->budget--) { s->failed_pc=0x0c0c1d8au; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0c1d8c;
P_0c0c1d8c: /* original e026, guest PC 0x0c0c1d8c */
if(!s->budget--) { s->failed_pc=0x0c0c1d8cu; return 0; }
r[0]=0x00000026u;
goto P_0c0c1d8e;
P_0c0c1d8e: /* original 2fc6, guest PC 0x0c0c1d8e */
if(!s->budget--) { s->failed_pc=0x0c0c1d8eu; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0c1d90;
P_0c0c1d90: /* original e67f, guest PC 0x0c0c1d90 */
if(!s->budget--) { s->failed_pc=0x0c0c1d90u; return 0; }
r[6]=0x0000007fu;
goto P_0c0c1d92;
P_0c0c1d92: /* original 2fb6, guest PC 0x0c0c1d92 */
if(!s->budget--) { s->failed_pc=0x0c0c1d92u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0c1d94;
P_0c0c1d94: /* original 2fa6, guest PC 0x0c0c1d94 */
if(!s->budget--) { s->failed_pc=0x0c0c1d94u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0c1d96;
P_0c0c1d96: /* original 2f96, guest PC 0x0c0c1d96 */
if(!s->budget--) { s->failed_pc=0x0c0c1d96u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0c1d98;
P_0c0c1d98: /* original 2f86, guest PC 0x0c0c1d98 */
if(!s->budget--) { s->failed_pc=0x0c0c1d98u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0c1d9a;
P_0c0c1d9a: /* original fffb, guest PC 0x0c0c1d9a */
if(!s->budget--) { s->failed_pc=0x0c0c1d9au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c1d9c;
P_0c0c1d9c: /* original ffeb, guest PC 0x0c0c1d9c */
if(!s->budget--) { s->failed_pc=0x0c0c1d9cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0c1d9e;
P_0c0c1d9e: /* original ffdb, guest PC 0x0c0c1d9e */
if(!s->budget--) { s->failed_pc=0x0c0c1d9eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0c1da0;
P_0c0c1da0: /* original ffcb, guest PC 0x0c0c1da0 */
if(!s->budget--) { s->failed_pc=0x0c0c1da0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0c1da2;
P_0c0c1da2: /* original 03ed, guest PC 0x0c0c1da2 */
if(!s->budget--) { s->failed_pc=0x0c0c1da2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c1da4;
P_0c0c1da4: /* original d01c, guest PC 0x0c0c1da4 */
if(!s->budget--) { s->failed_pc=0x0c0c1da4u; return 0; }
r[0]=read(ram,0x0c0c1e18u,4);
return vf3_matrix_family(0x0c0c1da6u,s,ram);
P_0c0c298c: /* original 2fe6, guest PC 0x0c0c298c */
if(!s->budget--) { s->failed_pc=0x0c0c298cu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c298e;
P_0c0c298e: /* original 2fd6, guest PC 0x0c0c298e */
if(!s->budget--) { s->failed_pc=0x0c0c298eu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0c2990;
P_0c0c2990: /* original 2fc6, guest PC 0x0c0c2990 */
if(!s->budget--) { s->failed_pc=0x0c0c2990u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0c2992;
P_0c0c2992: /* original 4f22, guest PC 0x0c0c2992 */
if(!s->budget--) { s->failed_pc=0x0c0c2992u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c2994;
P_0c0c2994: /* original 90bf, guest PC 0x0c0c2994 */
if(!s->budget--) { s->failed_pc=0x0c0c2994u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b16u,2);
goto P_0c0c2996;
P_0c0c2996: /* original dc67, guest PC 0x0c0c2996 */
if(!s->budget--) { s->failed_pc=0x0c0c2996u; return 0; }
r[12]=read(ram,0x0c0c2b34u,4);
goto P_0c0c2998;
P_0c0c2998: /* original 3f0c, guest PC 0x0c0c2998 */
if(!s->budget--) { s->failed_pc=0x0c0c2998u; return 0; }
r[15]+=r[0];
goto P_0c0c299a;
P_0c0c299a: /* original 90bd, guest PC 0x0c0c299a */
if(!s->budget--) { s->failed_pc=0x0c0c299au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b18u,2);
goto P_0c0c299c;
P_0c0c299c: /* original 0dce, guest PC 0x0c0c299c */
if(!s->budget--) { s->failed_pc=0x0c0c299cu; return 0; }
r[13]=read(ram,r[12]+r[0],4);
goto P_0c0c299e;
P_0c0c299e: /* original 2fc2, guest PC 0x0c0c299e */
if(!s->budget--) { s->failed_pc=0x0c0c299eu; return 0; }
write(ram,r[15],r[12],4);
goto P_0c0c29a0;
P_0c0c29a0: /* original d365, guest PC 0x0c0c29a0 */
if(!s->budget--) { s->failed_pc=0x0c0c29a0u; return 0; }
r[3]=read(ram,0x0c0c2b38u,4);
goto P_0c0c29a2;
P_0c0c29a2: /* original 430b, guest PC 0x0c0c29a2 */
if(!s->budget--) { s->failed_pc=0x0c0c29a2u; return 0; }
target=r[3];
r[16]=0x0c0c29a6u;
r[4]=0x00000015u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c29a6u) { target=s->pc; goto dispatch; }
goto P_0c0c29a6;
P_0c0c29a4: /* original e415, guest PC 0x0c0c29a4 */
if(!s->budget--) { s->failed_pc=0x0c0c29a4u; return 0; }
r[4]=0x00000015u;
goto P_0c0c29a6;
P_0c0c29a6: /* original 6e03, guest PC 0x0c0c29a6 */
if(!s->budget--) { s->failed_pc=0x0c0c29a6u; return 0; }
r[14]=r[0];
goto P_0c0c29a8;
P_0c0c29a8: /* original c764, guest PC 0x0c0c29a8 */
if(!s->budget--) { s->failed_pc=0x0c0c29a8u; return 0; }
r[0]=0x0c0c2b3cu;
goto P_0c0c29aa;
P_0c0c29aa: /* original f808, guest PC 0x0c0c29aa */
if(!s->budget--) { s->failed_pc=0x0c0c29aau; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c0c29ac;
P_0c0c29ac: /* original e01c, guest PC 0x0c0c29ac */
if(!s->budget--) { s->failed_pc=0x0c0c29acu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c29ae;
P_0c0c29ae: /* original f7e6, guest PC 0x0c0c29ae */
if(!s->budget--) { s->failed_pc=0x0c0c29aeu; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c29b0;
P_0c0c29b0: /* original e018, guest PC 0x0c0c29b0 */
if(!s->budget--) { s->failed_pc=0x0c0c29b0u; return 0; }
r[0]=0x00000018u;
goto P_0c0c29b2;
P_0c0c29b2: /* original 94b2, guest PC 0x0c0c29b2 */
if(!s->budget--) { s->failed_pc=0x0c0c29b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b1au,2);
goto P_0c0c29b4;
P_0c0c29b4: /* original d362, guest PC 0x0c0c29b4 */
if(!s->budget--) { s->failed_pc=0x0c0c29b4u; return 0; }
r[3]=read(ram,0x0c0c2b40u,4);
goto P_0c0c29b6;
P_0c0c29b6: /* original f6e6, guest PC 0x0c0c29b6 */
if(!s->budget--) { s->failed_pc=0x0c0c29b6u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c29b8;
P_0c0c29b8: /* original f58d, guest PC 0x0c0c29b8 */
if(!s->budget--) { s->failed_pc=0x0c0c29b8u; return 0; }
fr[5]=0;
goto P_0c0c29ba;
P_0c0c29ba: /* original f48d, guest PC 0x0c0c29ba */
if(!s->budget--) { s->failed_pc=0x0c0c29bau; return 0; }
fr[4]=0;
goto P_0c0c29bc;
P_0c0c29bc: /* original 430b, guest PC 0x0c0c29bc */
if(!s->budget--) { s->failed_pc=0x0c0c29bcu; return 0; }
target=r[3];
r[16]=0x0c0c29c0u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c29c0u) { target=s->pc; goto dispatch; }
goto P_0c0c29c0;
P_0c0c29be: /* original 34fc, guest PC 0x0c0c29be */
if(!s->budget--) { s->failed_pc=0x0c0c29beu; return 0; }
r[4]+=r[15];
goto P_0c0c29c0;
P_0c0c29c0: /* original e014, guest PC 0x0c0c29c0 */
if(!s->budget--) { s->failed_pc=0x0c0c29c0u; return 0; }
r[0]=0x00000014u;
goto P_0c0c29c2;
P_0c0c29c2: /* original 94aa, guest PC 0x0c0c29c2 */
if(!s->budget--) { s->failed_pc=0x0c0c29c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b1au,2);
goto P_0c0c29c4;
P_0c0c29c4: /* original f9e6, guest PC 0x0c0c29c4 */
if(!s->budget--) { s->failed_pc=0x0c0c29c4u; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c0c29c6;
P_0c0c29c6: /* original e010, guest PC 0x0c0c29c6 */
if(!s->budget--) { s->failed_pc=0x0c0c29c6u; return 0; }
r[0]=0x00000010u;
goto P_0c0c29c8;
P_0c0c29c8: /* original f8e6, guest PC 0x0c0c29c8 */
if(!s->budget--) { s->failed_pc=0x0c0c29c8u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0c29ca;
P_0c0c29ca: /* original e00c, guest PC 0x0c0c29ca */
if(!s->budget--) { s->failed_pc=0x0c0c29cau; return 0; }
r[0]=0x0000000cu;
goto P_0c0c29cc;
P_0c0c29cc: /* original f7e6, guest PC 0x0c0c29cc */
if(!s->budget--) { s->failed_pc=0x0c0c29ccu; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0c29ce;
P_0c0c29ce: /* original e008, guest PC 0x0c0c29ce */
if(!s->budget--) { s->failed_pc=0x0c0c29ceu; return 0; }
r[0]=0x00000008u;
goto P_0c0c29d0;
P_0c0c29d0: /* original f6e6, guest PC 0x0c0c29d0 */
if(!s->budget--) { s->failed_pc=0x0c0c29d0u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0c29d2;
P_0c0c29d2: /* original e004, guest PC 0x0c0c29d2 */
if(!s->budget--) { s->failed_pc=0x0c0c29d2u; return 0; }
r[0]=0x00000004u;
goto P_0c0c29d4;
P_0c0c29d4: /* original d35b, guest PC 0x0c0c29d4 */
if(!s->budget--) { s->failed_pc=0x0c0c29d4u; return 0; }
r[3]=read(ram,0x0c0c2b44u,4);
goto P_0c0c29d6;
P_0c0c29d6: /* original f5e6, guest PC 0x0c0c29d6 */
if(!s->budget--) { s->failed_pc=0x0c0c29d6u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0c29d8;
P_0c0c29d8: /* original f4e8, guest PC 0x0c0c29d8 */
if(!s->budget--) { s->failed_pc=0x0c0c29d8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
goto P_0c0c29da;
P_0c0c29da: /* original 430b, guest PC 0x0c0c29da */
if(!s->budget--) { s->failed_pc=0x0c0c29dau; return 0; }
target=r[3];
r[16]=0x0c0c29deu;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c29deu) { target=s->pc; goto dispatch; }
goto P_0c0c29de;
P_0c0c29dc: /* original 34fc, guest PC 0x0c0c29dc */
if(!s->budget--) { s->failed_pc=0x0c0c29dcu; return 0; }
r[4]+=r[15];
goto P_0c0c29de;
P_0c0c29de: /* original 909d, guest PC 0x0c0c29de */
if(!s->budget--) { s->failed_pc=0x0c0c29deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b1cu,2);
goto P_0c0c29e0;
P_0c0c29e0: /* original e200, guest PC 0x0c0c29e0 */
if(!s->budget--) { s->failed_pc=0x0c0c29e0u; return 0; }
r[2]=0x00000000u;
goto P_0c0c29e2;
P_0c0c29e2: /* original 0f26, guest PC 0x0c0c29e2 */
if(!s->budget--) { s->failed_pc=0x0c0c29e2u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0c29e4;
P_0c0c29e4: /* original 909c, guest PC 0x0c0c29e4 */
if(!s->budget--) { s->failed_pc=0x0c0c29e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b20u,2);
goto P_0c0c29e6;
P_0c0c29e6: /* original 939a, guest PC 0x0c0c29e6 */
if(!s->budget--) { s->failed_pc=0x0c0c29e6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b1eu,2);
goto P_0c0c29e8;
P_0c0c29e8: /* original 0f36, guest PC 0x0c0c29e8 */
if(!s->budget--) { s->failed_pc=0x0c0c29e8u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0c29ea;
P_0c0c29ea: /* original 909a, guest PC 0x0c0c29ea */
if(!s->budget--) { s->failed_pc=0x0c0c29eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b22u,2);
goto P_0c0c29ec;
P_0c0c29ec: /* original f39d, guest PC 0x0c0c29ec */
if(!s->budget--) { s->failed_pc=0x0c0c29ecu; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c29ee;
P_0c0c29ee: /* original ff37, guest PC 0x0c0c29ee */
if(!s->budget--) { s->failed_pc=0x0c0c29eeu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c29f0;
P_0c0c29f0: /* original 9293, guest PC 0x0c0c29f0 */
if(!s->budget--) { s->failed_pc=0x0c0c29f0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b1au,2);
goto P_0c0c29f2;
P_0c0c29f2: /* original 9197, guest PC 0x0c0c29f2 */
if(!s->budget--) { s->failed_pc=0x0c0c29f2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b24u,2);
goto P_0c0c29f4;
P_0c0c29f4: /* original d354, guest PC 0x0c0c29f4 */
if(!s->budget--) { s->failed_pc=0x0c0c29f4u; return 0; }
r[3]=read(ram,0x0c0c2b48u,4);
goto P_0c0c29f6;
P_0c0c29f6: /* original 32fc, guest PC 0x0c0c29f6 */
if(!s->budget--) { s->failed_pc=0x0c0c29f6u; return 0; }
r[2]+=r[15];
goto P_0c0c29f8;
P_0c0c29f8: /* original 31fc, guest PC 0x0c0c29f8 */
if(!s->budget--) { s->failed_pc=0x0c0c29f8u; return 0; }
r[1]+=r[15];
goto P_0c0c29fa;
P_0c0c29fa: /* original 430b, guest PC 0x0c0c29fa */
if(!s->budget--) { s->failed_pc=0x0c0c29fau; return 0; }
target=r[3];
r[16]=0x0c0c29feu;
r[0]=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c29feu) { target=s->pc; goto dispatch; }
goto P_0c0c29fe;
P_0c0c29fc: /* original e034, guest PC 0x0c0c29fc */
if(!s->budget--) { s->failed_pc=0x0c0c29fcu; return 0; }
r[0]=0x00000034u;
goto P_0c0c29fe;
P_0c0c29fe: /* original 928c, guest PC 0x0c0c29fe */
if(!s->budget--) { s->failed_pc=0x0c0c29feu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b1au,2);
goto P_0c0c2a00;
P_0c0c2a00: /* original 9191, guest PC 0x0c0c2a00 */
if(!s->budget--) { s->failed_pc=0x0c0c2a00u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b26u,2);
goto P_0c0c2a02;
P_0c0c2a02: /* original d351, guest PC 0x0c0c2a02 */
if(!s->budget--) { s->failed_pc=0x0c0c2a02u; return 0; }
r[3]=read(ram,0x0c0c2b48u,4);
goto P_0c0c2a04;
P_0c0c2a04: /* original 32fc, guest PC 0x0c0c2a04 */
if(!s->budget--) { s->failed_pc=0x0c0c2a04u; return 0; }
r[2]+=r[15];
goto P_0c0c2a06;
P_0c0c2a06: /* original 31fc, guest PC 0x0c0c2a06 */
if(!s->budget--) { s->failed_pc=0x0c0c2a06u; return 0; }
r[1]+=r[15];
goto P_0c0c2a08;
P_0c0c2a08: /* original 430b, guest PC 0x0c0c2a08 */
if(!s->budget--) { s->failed_pc=0x0c0c2a08u; return 0; }
target=r[3];
r[16]=0x0c0c2a0cu;
r[0]=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2a0cu) { target=s->pc; goto dispatch; }
goto P_0c0c2a0c;
P_0c0c2a0a: /* original e034, guest PC 0x0c0c2a0a */
if(!s->budget--) { s->failed_pc=0x0c0c2a0au; return 0; }
r[0]=0x00000034u;
goto P_0c0c2a0c;
P_0c0c2a0c: /* original 9285, guest PC 0x0c0c2a0c */
if(!s->budget--) { s->failed_pc=0x0c0c2a0cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b1au,2);
goto P_0c0c2a0e;
P_0c0c2a0e: /* original 61f3, guest PC 0x0c0c2a0e */
if(!s->budget--) { s->failed_pc=0x0c0c2a0eu; return 0; }
r[1]=r[15];
goto P_0c0c2a10;
P_0c0c2a10: /* original d34d, guest PC 0x0c0c2a10 */
if(!s->budget--) { s->failed_pc=0x0c0c2a10u; return 0; }
r[3]=read(ram,0x0c0c2b48u,4);
goto P_0c0c2a12;
P_0c0c2a12: /* original 716c, guest PC 0x0c0c2a12 */
if(!s->budget--) { s->failed_pc=0x0c0c2a12u; return 0; }
r[1]+=0x0000006cu;
goto P_0c0c2a14;
P_0c0c2a14: /* original 32fc, guest PC 0x0c0c2a14 */
if(!s->budget--) { s->failed_pc=0x0c0c2a14u; return 0; }
r[2]+=r[15];
goto P_0c0c2a16;
P_0c0c2a16: /* original 430b, guest PC 0x0c0c2a16 */
if(!s->budget--) { s->failed_pc=0x0c0c2a16u; return 0; }
target=r[3];
r[16]=0x0c0c2a1au;
r[0]=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2a1au) { target=s->pc; goto dispatch; }
goto P_0c0c2a1a;
P_0c0c2a18: /* original e034, guest PC 0x0c0c2a18 */
if(!s->budget--) { s->failed_pc=0x0c0c2a18u; return 0; }
r[0]=0x00000034u;
goto P_0c0c2a1a;
P_0c0c2a1a: /* original 927e, guest PC 0x0c0c2a1a */
if(!s->budget--) { s->failed_pc=0x0c0c2a1au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b1au,2);
goto P_0c0c2a1c;
P_0c0c2a1c: /* original 61f3, guest PC 0x0c0c2a1c */
if(!s->budget--) { s->failed_pc=0x0c0c2a1cu; return 0; }
r[1]=r[15];
goto P_0c0c2a1e;
P_0c0c2a1e: /* original d34a, guest PC 0x0c0c2a1e */
if(!s->budget--) { s->failed_pc=0x0c0c2a1eu; return 0; }
r[3]=read(ram,0x0c0c2b48u,4);
goto P_0c0c2a20;
P_0c0c2a20: /* original 7138, guest PC 0x0c0c2a20 */
if(!s->budget--) { s->failed_pc=0x0c0c2a20u; return 0; }
r[1]+=0x00000038u;
goto P_0c0c2a22;
P_0c0c2a22: /* original 32fc, guest PC 0x0c0c2a22 */
if(!s->budget--) { s->failed_pc=0x0c0c2a22u; return 0; }
r[2]+=r[15];
goto P_0c0c2a24;
P_0c0c2a24: /* original 430b, guest PC 0x0c0c2a24 */
if(!s->budget--) { s->failed_pc=0x0c0c2a24u; return 0; }
target=r[3];
r[16]=0x0c0c2a28u;
r[0]=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2a28u) { target=s->pc; goto dispatch; }
goto P_0c0c2a28;
P_0c0c2a26: /* original e034, guest PC 0x0c0c2a26 */
if(!s->budget--) { s->failed_pc=0x0c0c2a26u; return 0; }
r[0]=0x00000034u;
goto P_0c0c2a28;
P_0c0c2a28: /* original 9277, guest PC 0x0c0c2a28 */
if(!s->budget--) { s->failed_pc=0x0c0c2a28u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b1au,2);
goto P_0c0c2a2a;
P_0c0c2a2a: /* original 61f3, guest PC 0x0c0c2a2a */
if(!s->budget--) { s->failed_pc=0x0c0c2a2au; return 0; }
r[1]=r[15];
goto P_0c0c2a2c;
P_0c0c2a2c: /* original d346, guest PC 0x0c0c2a2c */
if(!s->budget--) { s->failed_pc=0x0c0c2a2cu; return 0; }
r[3]=read(ram,0x0c0c2b48u,4);
goto P_0c0c2a2e;
P_0c0c2a2e: /* original 7104, guest PC 0x0c0c2a2e */
if(!s->budget--) { s->failed_pc=0x0c0c2a2eu; return 0; }
r[1]+=0x00000004u;
goto P_0c0c2a30;
P_0c0c2a30: /* original 32fc, guest PC 0x0c0c2a30 */
if(!s->budget--) { s->failed_pc=0x0c0c2a30u; return 0; }
r[2]+=r[15];
goto P_0c0c2a32;
P_0c0c2a32: /* original 430b, guest PC 0x0c0c2a32 */
if(!s->budget--) { s->failed_pc=0x0c0c2a32u; return 0; }
target=r[3];
r[16]=0x0c0c2a36u;
r[0]=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2a36u) { target=s->pc; goto dispatch; }
goto P_0c0c2a36;
P_0c0c2a34: /* original e034, guest PC 0x0c0c2a34 */
if(!s->budget--) { s->failed_pc=0x0c0c2a34u; return 0; }
r[0]=0x00000034u;
goto P_0c0c2a36;
P_0c0c2a36: /* original d445, guest PC 0x0c0c2a36 */
if(!s->budget--) { s->failed_pc=0x0c0c2a36u; return 0; }
r[4]=read(ram,0x0c0c2b4cu,4);
goto P_0c0c2a38;
P_0c0c2a38: /* original e02a, guest PC 0x0c0c2a38 */
if(!s->budget--) { s->failed_pc=0x0c0c2a38u; return 0; }
r[0]=0x0000002au;
goto P_0c0c2a3a;
P_0c0c2a3a: /* original 024d, guest PC 0x0c0c2a3a */
if(!s->budget--) { s->failed_pc=0x0c0c2a3au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c2a3c;
P_0c0c2a3c: /* original 906d, guest PC 0x0c0c2a3c */
if(!s->budget--) { s->failed_pc=0x0c0c2a3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b1au,2);
goto P_0c0c2a3e;
P_0c0c2a3e: /* original 622d, guest PC 0x0c0c2a3e */
if(!s->budget--) { s->failed_pc=0x0c0c2a3eu; return 0; }
r[2]=r[2]&65535u;
goto P_0c0c2a40;
P_0c0c2a40: /* original 0f26, guest PC 0x0c0c2a40 */
if(!s->budget--) { s->failed_pc=0x0c0c2a40u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0c2a42;
P_0c0c2a42: /* original e03a, guest PC 0x0c0c2a42 */
if(!s->budget--) { s->failed_pc=0x0c0c2a42u; return 0; }
r[0]=0x0000003au;
goto P_0c0c2a44;
P_0c0c2a44: /* original 034d, guest PC 0x0c0c2a44 */
if(!s->budget--) { s->failed_pc=0x0c0c2a44u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c2a46;
P_0c0c2a46: /* original 906d, guest PC 0x0c0c2a46 */
if(!s->budget--) { s->failed_pc=0x0c0c2a46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b24u,2);
goto P_0c0c2a48;
P_0c0c2a48: /* original 633d, guest PC 0x0c0c2a48 */
if(!s->budget--) { s->failed_pc=0x0c0c2a48u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c2a4a;
P_0c0c2a4a: /* original 0f36, guest PC 0x0c0c2a4a */
if(!s->budget--) { s->failed_pc=0x0c0c2a4au; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0c2a4c;
P_0c0c2a4c: /* original e03c, guest PC 0x0c0c2a4c */
if(!s->budget--) { s->failed_pc=0x0c0c2a4cu; return 0; }
r[0]=0x0000003cu;
goto P_0c0c2a4e;
P_0c0c2a4e: /* original 034d, guest PC 0x0c0c2a4e */
if(!s->budget--) { s->failed_pc=0x0c0c2a4eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c2a50;
P_0c0c2a50: /* original 9069, guest PC 0x0c0c2a50 */
if(!s->budget--) { s->failed_pc=0x0c0c2a50u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b26u,2);
goto P_0c0c2a52;
P_0c0c2a52: /* original 633d, guest PC 0x0c0c2a52 */
if(!s->budget--) { s->failed_pc=0x0c0c2a52u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c2a54;
P_0c0c2a54: /* original 0f36, guest PC 0x0c0c2a54 */
if(!s->budget--) { s->failed_pc=0x0c0c2a54u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0c2a56;
P_0c0c2a56: /* original e03e, guest PC 0x0c0c2a56 */
if(!s->budget--) { s->failed_pc=0x0c0c2a56u; return 0; }
r[0]=0x0000003eu;
goto P_0c0c2a58;
P_0c0c2a58: /* original 034d, guest PC 0x0c0c2a58 */
if(!s->budget--) { s->failed_pc=0x0c0c2a58u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c2a5a;
P_0c0c2a5a: /* original e06c, guest PC 0x0c0c2a5a */
if(!s->budget--) { s->failed_pc=0x0c0c2a5au; return 0; }
r[0]=0x0000006cu;
goto P_0c0c2a5c;
P_0c0c2a5c: /* original 633d, guest PC 0x0c0c2a5c */
if(!s->budget--) { s->failed_pc=0x0c0c2a5cu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c2a5e;
P_0c0c2a5e: /* original 0f36, guest PC 0x0c0c2a5e */
if(!s->budget--) { s->failed_pc=0x0c0c2a5eu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0c2a60;
P_0c0c2a60: /* original e040, guest PC 0x0c0c2a60 */
if(!s->budget--) { s->failed_pc=0x0c0c2a60u; return 0; }
r[0]=0x00000040u;
goto P_0c0c2a62;
P_0c0c2a62: /* original 034d, guest PC 0x0c0c2a62 */
if(!s->budget--) { s->failed_pc=0x0c0c2a62u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c2a64;
P_0c0c2a64: /* original 7442, guest PC 0x0c0c2a64 */
if(!s->budget--) { s->failed_pc=0x0c0c2a64u; return 0; }
r[4]+=0x00000042u;
goto P_0c0c2a66;
P_0c0c2a66: /* original 633d, guest PC 0x0c0c2a66 */
if(!s->budget--) { s->failed_pc=0x0c0c2a66u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c2a68;
P_0c0c2a68: /* original 1f3e, guest PC 0x0c0c2a68 */
if(!s->budget--) { s->failed_pc=0x0c0c2a68u; return 0; }
write(ram,r[15]+56,r[3],4);
goto P_0c0c2a6a;
P_0c0c2a6a: /* original 6341, guest PC 0x0c0c2a6a */
if(!s->budget--) { s->failed_pc=0x0c0c2a6au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[3]=tmp;
goto P_0c0c2a6c;
P_0c0c2a6c: /* original 633d, guest PC 0x0c0c2a6c */
if(!s->budget--) { s->failed_pc=0x0c0c2a6cu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c2a6e;
P_0c0c2a6e: /* original 1f31, guest PC 0x0c0c2a6e */
if(!s->budget--) { s->failed_pc=0x0c0c2a6eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c2a70;
P_0c0c2a70: /* original 63db, guest PC 0x0c0c2a70 */
if(!s->budget--) { s->failed_pc=0x0c0c2a70u; return 0; }
r[3]=0u-r[13];
goto P_0c0c2a72;
P_0c0c2a72: /* original 435a, guest PC 0x0c0c2a72 */
if(!s->budget--) { s->failed_pc=0x0c0c2a72u; return 0; }
r[53]=r[3];
goto P_0c0c2a74;
P_0c0c2a74: /* original d436, guest PC 0x0c0c2a74 */
if(!s->budget--) { s->failed_pc=0x0c0c2a74u; return 0; }
r[4]=read(ram,0x0c0c2b50u,4);
goto P_0c0c2a76;
P_0c0c2a76: /* original f32d, guest PC 0x0c0c2a76 */
if(!s->budget--) { s->failed_pc=0x0c0c2a76u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c2a78;
P_0c0c2a78: /* original c736, guest PC 0x0c0c2a78 */
if(!s->budget--) { s->failed_pc=0x0c0c2a78u; return 0; }
r[0]=0x0c0c2b54u;
goto P_0c0c2a7a;
P_0c0c2a7a: /* original f208, guest PC 0x0c0c2a7a */
if(!s->budget--) { s->failed_pc=0x0c0c2a7au; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c2a7c;
P_0c0c2a7c: /* original f148, guest PC 0x0c0c2a7c */
if(!s->budget--) { s->failed_pc=0x0c0c2a7cu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
goto P_0c0c2a7e;
P_0c0c2a7e: /* original 9053, guest PC 0x0c0c2a7e */
if(!s->budget--) { s->failed_pc=0x0c0c2a7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b28u,2);
goto P_0c0c2a80;
P_0c0c2a80: /* original f320, guest PC 0x0c0c2a80 */
if(!s->budget--) { s->failed_pc=0x0c0c2a80u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c0c2a82;
P_0c0c2a82: /* original f312, guest PC 0x0c0c2a82 */
if(!s->budget--) { s->failed_pc=0x0c0c2a82u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'*');
goto P_0c0c2a84;
P_0c0c2a84: /* original ff37, guest PC 0x0c0c2a84 */
if(!s->budget--) { s->failed_pc=0x0c0c2a84u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c2a86;
P_0c0c2a86: /* original c734, guest PC 0x0c0c2a86 */
if(!s->budget--) { s->failed_pc=0x0c0c2a86u; return 0; }
r[0]=0x0c0c2b58u;
goto P_0c0c2a88;
P_0c0c2a88: /* original f408, guest PC 0x0c0c2a88 */
if(!s->budget--) { s->failed_pc=0x0c0c2a88u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c2a8a;
P_0c0c2a8a: /* original f148, guest PC 0x0c0c2a8a */
if(!s->budget--) { s->failed_pc=0x0c0c2a8au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
goto P_0c0c2a8c;
P_0c0c2a8c: /* original f04c, guest PC 0x0c0c2a8c */
if(!s->budget--) { s->failed_pc=0x0c0c2a8cu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0c2a8e;
P_0c0c2a8e: /* original f31e, guest PC 0x0c0c2a8e */
if(!s->budget--) { s->failed_pc=0x0c0c2a8eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[1],fr[3],r[18]);
goto P_0c0c2a90;
P_0c0c2a90: /* original 904b, guest PC 0x0c0c2a90 */
if(!s->budget--) { s->failed_pc=0x0c0c2a90u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b2au,2);
goto P_0c0c2a92;
P_0c0c2a92: /* original ff37, guest PC 0x0c0c2a92 */
if(!s->budget--) { s->failed_pc=0x0c0c2a92u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c2a94;
P_0c0c2a94: /* original f148, guest PC 0x0c0c2a94 */
if(!s->budget--) { s->failed_pc=0x0c0c2a94u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
goto P_0c0c2a96;
P_0c0c2a96: /* original 9049, guest PC 0x0c0c2a96 */
if(!s->budget--) { s->failed_pc=0x0c0c2a96u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b2cu,2);
goto P_0c0c2a98;
P_0c0c2a98: /* original f31e, guest PC 0x0c0c2a98 */
if(!s->budget--) { s->failed_pc=0x0c0c2a98u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[1],fr[3],r[18]);
goto P_0c0c2a9a;
P_0c0c2a9a: /* original ff37, guest PC 0x0c0c2a9a */
if(!s->budget--) { s->failed_pc=0x0c0c2a9au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c2a9c;
P_0c0c2a9c: /* original e074, guest PC 0x0c0c2a9c */
if(!s->budget--) { s->failed_pc=0x0c0c2a9cu; return 0; }
r[0]=0x00000074u;
goto P_0c0c2a9e;
P_0c0c2a9e: /* original f148, guest PC 0x0c0c2a9e */
if(!s->budget--) { s->failed_pc=0x0c0c2a9eu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
goto P_0c0c2aa0;
P_0c0c2aa0: /* original f31e, guest PC 0x0c0c2aa0 */
if(!s->budget--) { s->failed_pc=0x0c0c2aa0u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[1],fr[3],r[18]);
goto P_0c0c2aa2;
P_0c0c2aa2: /* original ff37, guest PC 0x0c0c2aa2 */
if(!s->budget--) { s->failed_pc=0x0c0c2aa2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c2aa4;
P_0c0c2aa4: /* original e040, guest PC 0x0c0c2aa4 */
if(!s->budget--) { s->failed_pc=0x0c0c2aa4u; return 0; }
r[0]=0x00000040u;
goto P_0c0c2aa6;
P_0c0c2aa6: /* original f148, guest PC 0x0c0c2aa6 */
if(!s->budget--) { s->failed_pc=0x0c0c2aa6u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
goto P_0c0c2aa8;
P_0c0c2aa8: /* original f31e, guest PC 0x0c0c2aa8 */
if(!s->budget--) { s->failed_pc=0x0c0c2aa8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[1],fr[3],r[18]);
goto P_0c0c2aaa;
P_0c0c2aaa: /* original ff37, guest PC 0x0c0c2aaa */
if(!s->budget--) { s->failed_pc=0x0c0c2aaau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c2aac;
P_0c0c2aac: /* original e00c, guest PC 0x0c0c2aac */
if(!s->budget--) { s->failed_pc=0x0c0c2aacu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c2aae;
P_0c0c2aae: /* original f148, guest PC 0x0c0c2aae */
if(!s->budget--) { s->failed_pc=0x0c0c2aaeu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
goto P_0c0c2ab0;
P_0c0c2ab0: /* original f31e, guest PC 0x0c0c2ab0 */
if(!s->budget--) { s->failed_pc=0x0c0c2ab0u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[1],fr[3],r[18]);
goto P_0c0c2ab2;
P_0c0c2ab2: /* original ff37, guest PC 0x0c0c2ab2 */
if(!s->budget--) { s->failed_pc=0x0c0c2ab2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c2ab4;
P_0c0c2ab4: /* original de29, guest PC 0x0c0c2ab4 */
if(!s->budget--) { s->failed_pc=0x0c0c2ab4u; return 0; }
r[14]=read(ram,0x0c0c2b5cu,4);
goto P_0c0c2ab6;
P_0c0c2ab6: /* original 9430, guest PC 0x0c0c2ab6 */
if(!s->budget--) { s->failed_pc=0x0c0c2ab6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b1au,2);
goto P_0c0c2ab8;
P_0c0c2ab8: /* original 4e0b, guest PC 0x0c0c2ab8 */
if(!s->budget--) { s->failed_pc=0x0c0c2ab8u; return 0; }
target=r[14];
r[16]=0x0c0c2abcu;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2abcu) { target=s->pc; goto dispatch; }
goto P_0c0c2abc;
P_0c0c2aba: /* original 34fc, guest PC 0x0c0c2aba */
if(!s->budget--) { s->failed_pc=0x0c0c2abau; return 0; }
r[4]+=r[15];
goto P_0c0c2abc;
P_0c0c2abc: /* original 9432, guest PC 0x0c0c2abc */
if(!s->budget--) { s->failed_pc=0x0c0c2abcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b24u,2);
goto P_0c0c2abe;
P_0c0c2abe: /* original 4e0b, guest PC 0x0c0c2abe */
if(!s->budget--) { s->failed_pc=0x0c0c2abeu; return 0; }
target=r[14];
r[16]=0x0c0c2ac2u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2ac2u) { target=s->pc; goto dispatch; }
goto P_0c0c2ac2;
P_0c0c2ac0: /* original 34fc, guest PC 0x0c0c2ac0 */
if(!s->budget--) { s->failed_pc=0x0c0c2ac0u; return 0; }
r[4]+=r[15];
goto P_0c0c2ac2;
P_0c0c2ac2: /* original 9430, guest PC 0x0c0c2ac2 */
if(!s->budget--) { s->failed_pc=0x0c0c2ac2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b26u,2);
goto P_0c0c2ac4;
P_0c0c2ac4: /* original 4e0b, guest PC 0x0c0c2ac4 */
if(!s->budget--) { s->failed_pc=0x0c0c2ac4u; return 0; }
target=r[14];
r[16]=0x0c0c2ac8u;
r[4]+=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2ac8u) { target=s->pc; goto dispatch; }
goto P_0c0c2ac8;
P_0c0c2ac6: /* original 34fc, guest PC 0x0c0c2ac6 */
if(!s->budget--) { s->failed_pc=0x0c0c2ac6u; return 0; }
r[4]+=r[15];
goto P_0c0c2ac8;
P_0c0c2ac8: /* original 64f3, guest PC 0x0c0c2ac8 */
if(!s->budget--) { s->failed_pc=0x0c0c2ac8u; return 0; }
r[4]=r[15];
goto P_0c0c2aca;
P_0c0c2aca: /* original 4e0b, guest PC 0x0c0c2aca */
if(!s->budget--) { s->failed_pc=0x0c0c2acau; return 0; }
target=r[14];
r[16]=0x0c0c2aceu;
r[4]+=0x0000006cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2aceu) { target=s->pc; goto dispatch; }
goto P_0c0c2ace;
P_0c0c2acc: /* original 746c, guest PC 0x0c0c2acc */
if(!s->budget--) { s->failed_pc=0x0c0c2accu; return 0; }
r[4]+=0x0000006cu;
goto P_0c0c2ace;
P_0c0c2ace: /* original 64f3, guest PC 0x0c0c2ace */
if(!s->budget--) { s->failed_pc=0x0c0c2aceu; return 0; }
r[4]=r[15];
goto P_0c0c2ad0;
P_0c0c2ad0: /* original 4e0b, guest PC 0x0c0c2ad0 */
if(!s->budget--) { s->failed_pc=0x0c0c2ad0u; return 0; }
target=r[14];
r[16]=0x0c0c2ad4u;
r[4]+=0x00000038u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2ad4u) { target=s->pc; goto dispatch; }
goto P_0c0c2ad4;
P_0c0c2ad2: /* original 7438, guest PC 0x0c0c2ad2 */
if(!s->budget--) { s->failed_pc=0x0c0c2ad2u; return 0; }
r[4]+=0x00000038u;
goto P_0c0c2ad4;
P_0c0c2ad4: /* original 64f3, guest PC 0x0c0c2ad4 */
if(!s->budget--) { s->failed_pc=0x0c0c2ad4u; return 0; }
r[4]=r[15];
goto P_0c0c2ad6;
P_0c0c2ad6: /* original 4e0b, guest PC 0x0c0c2ad6 */
if(!s->budget--) { s->failed_pc=0x0c0c2ad6u; return 0; }
target=r[14];
r[16]=0x0c0c2adau;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2adau) { target=s->pc; goto dispatch; }
goto P_0c0c2ada;
P_0c0c2ad8: /* original 7404, guest PC 0x0c0c2ad8 */
if(!s->budget--) { s->failed_pc=0x0c0c2ad8u; return 0; }
r[4]+=0x00000004u;
goto P_0c0c2ada;
P_0c0c2ada: /* original e507, guest PC 0x0c0c2ada */
if(!s->budget--) { s->failed_pc=0x0c0c2adau; return 0; }
r[5]=0x00000007u;
goto P_0c0c2adc;
P_0c0c2adc: /* original 9027, guest PC 0x0c0c2adc */
if(!s->budget--) { s->failed_pc=0x0c0c2adcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b2eu,2);
goto P_0c0c2ade;
P_0c0c2ade: /* original 25d9, guest PC 0x0c0c2ade */
if(!s->budget--) { s->failed_pc=0x0c0c2adeu; return 0; }
r[5]&=r[13];
goto P_0c0c2ae0;
P_0c0c2ae0: /* original 2558, guest PC 0x0c0c2ae0 */
if(!s->budget--) { s->failed_pc=0x0c0c2ae0u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0c2ae2;
P_0c0c2ae2: /* original 8f04, guest PC 0x0c0c2ae2 */
if(!s->budget--) { s->failed_pc=0x0c0c2ae2u; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
if(!cond) { goto P_0c0c2aee; }
goto P_0c0c2ae6;
P_0c0c2ae4: /* original 04cd, guest PC 0x0c0c2ae4 */
if(!s->budget--) { s->failed_pc=0x0c0c2ae4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0c2ae6;
P_0c0c2ae6: /* original e23f, guest PC 0x0c0c2ae6 */
if(!s->budget--) { s->failed_pc=0x0c0c2ae6u; return 0; }
r[2]=0x0000003fu;
goto P_0c0c2ae8;
P_0c0c2ae8: /* original 7401, guest PC 0x0c0c2ae8 */
if(!s->budget--) { s->failed_pc=0x0c0c2ae8u; return 0; }
r[4]+=0x00000001u;
goto P_0c0c2aea;
P_0c0c2aea: /* original 2429, guest PC 0x0c0c2aea */
if(!s->budget--) { s->failed_pc=0x0c0c2aeau; return 0; }
r[4]&=r[2];
goto P_0c0c2aec;
P_0c0c2aec: /* original 0c45, guest PC 0x0c0c2aec */
if(!s->budget--) { s->failed_pc=0x0c0c2aecu; return 0; }
write(ram,r[12]+r[0],r[4],2);
goto P_0c0c2aee;
P_0c0c2aee: /* original 941f, guest PC 0x0c0c2aee */
if(!s->budget--) { s->failed_pc=0x0c0c2aeeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b30u,2);
goto P_0c0c2af0;
P_0c0c2af0: /* original 63f2, guest PC 0x0c0c2af0 */
if(!s->budget--) { s->failed_pc=0x0c0c2af0u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c2af2;
P_0c0c2af2: /* original 24d9, guest PC 0x0c0c2af2 */
if(!s->budget--) { s->failed_pc=0x0c0c2af2u; return 0; }
r[4]&=r[13];
goto P_0c0c2af4;
P_0c0c2af4: /* original 6043, guest PC 0x0c0c2af4 */
if(!s->budget--) { s->failed_pc=0x0c0c2af4u; return 0; }
r[0]=r[4];
goto P_0c0c2af6;
P_0c0c2af6: /* original 813b, guest PC 0x0c0c2af6 */
if(!s->budget--) { s->failed_pc=0x0c0c2af6u; return 0; }
write(ram,r[3]+22,r[0],2);
goto P_0c0c2af8;
P_0c0c2af8: /* original 900e, guest PC 0x0c0c2af8 */
if(!s->budget--) { s->failed_pc=0x0c0c2af8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b18u,2);
goto P_0c0c2afa;
P_0c0c2afa: /* original 7d01, guest PC 0x0c0c2afa */
if(!s->budget--) { s->failed_pc=0x0c0c2afau; return 0; }
r[13]+=0x00000001u;
goto P_0c0c2afc;
P_0c0c2afc: /* original e301, guest PC 0x0c0c2afc */
if(!s->budget--) { s->failed_pc=0x0c0c2afcu; return 0; }
r[3]=0x00000001u;
goto P_0c0c2afe;
P_0c0c2afe: /* original 0cd6, guest PC 0x0c0c2afe */
if(!s->budget--) { s->failed_pc=0x0c0c2afeu; return 0; }
write(ram,r[12]+r[0],r[13],4);
goto P_0c0c2b00;
P_0c0c2b00: /* original e022, guest PC 0x0c0c2b00 */
if(!s->budget--) { s->failed_pc=0x0c0c2b00u; return 0; }
r[0]=0x00000022u;
goto P_0c0c2b02;
P_0c0c2b02: /* original 02cd, guest PC 0x0c0c2b02 */
if(!s->budget--) { s->failed_pc=0x0c0c2b02u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0c2b04;
P_0c0c2b04: /* original 223b, guest PC 0x0c0c2b04 */
if(!s->budget--) { s->failed_pc=0x0c0c2b04u; return 0; }
r[2]|=r[3];
goto P_0c0c2b06;
P_0c0c2b06: /* original 0c25, guest PC 0x0c0c2b06 */
if(!s->budget--) { s->failed_pc=0x0c0c2b06u; return 0; }
write(ram,r[12]+r[0],r[2],2);
goto P_0c0c2b08;
P_0c0c2b08: /* original 9113, guest PC 0x0c0c2b08 */
if(!s->budget--) { s->failed_pc=0x0c0c2b08u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2b32u,2);
goto P_0c0c2b0a;
P_0c0c2b0a: /* original 3f1c, guest PC 0x0c0c2b0a */
if(!s->budget--) { s->failed_pc=0x0c0c2b0au; return 0; }
r[15]+=r[1];
goto P_0c0c2b0c;
P_0c0c2b0c: /* original 4f26, guest PC 0x0c0c2b0c */
if(!s->budget--) { s->failed_pc=0x0c0c2b0cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c2b0e;
P_0c0c2b0e: /* original 6cf6, guest PC 0x0c0c2b0e */
if(!s->budget--) { s->failed_pc=0x0c0c2b0eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c2b10;
P_0c0c2b10: /* original 6df6, guest PC 0x0c0c2b10 */
if(!s->budget--) { s->failed_pc=0x0c0c2b10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c2b12;
P_0c0c2b12: /* original 000b, guest PC 0x0c0c2b12 */
if(!s->budget--) { s->failed_pc=0x0c0c2b12u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c2b14: /* original 6ef6, guest PC 0x0c0c2b14 */
if(!s->budget--) { s->failed_pc=0x0c0c2b14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c2b16u,s,ram);
P_0c0c2bb4: /* original 4f22, guest PC 0x0c0c2bb4 */
if(!s->budget--) { s->failed_pc=0x0c0c2bb4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c2bb6;
P_0c0c2bb6: /* original de2b, guest PC 0x0c0c2bb6 */
if(!s->budget--) { s->failed_pc=0x0c0c2bb6u; return 0; }
r[14]=read(ram,0x0c0c2c64u,4);
goto P_0c0c2bb8;
P_0c0c2bb8: /* original 9038, guest PC 0x0c0c2bb8 */
if(!s->budget--) { s->failed_pc=0x0c0c2bb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2c2cu,2);
goto P_0c0c2bba;
P_0c0c2bba: /* original 4f12, guest PC 0x0c0c2bba */
if(!s->budget--) { s->failed_pc=0x0c0c2bbau; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c2bbc;
P_0c0c2bbc: /* original 00ee, guest PC 0x0c0c2bbc */
if(!s->budget--) { s->failed_pc=0x0c0c2bbcu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0c2bbe;
P_0c0c2bbe: /* original 88ff, guest PC 0x0c0c2bbe */
if(!s->budget--) { s->failed_pc=0x0c0c2bbeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c2bc0;
P_0c0c2bc0: /* original 7ff4, guest PC 0x0c0c2bc0 */
if(!s->budget--) { s->failed_pc=0x0c0c2bc0u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c2bc2;
P_0c0c2bc2: /* original 8d02, guest PC 0x0c0c2bc2 */
if(!s->budget--) { s->failed_pc=0x0c0c2bc2u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0c2bca; }
goto P_0c0c2bc6;
P_0c0c2bc4: /* original 6403, guest PC 0x0c0c2bc4 */
if(!s->budget--) { s->failed_pc=0x0c0c2bc4u; return 0; }
r[4]=r[0];
goto P_0c0c2bc6;
P_0c0c2bc6: /* original bee1, guest PC 0x0c0c2bc6 */
if(!s->budget--) { s->failed_pc=0x0c0c2bc6u; return 0; }
target=0x0c0c298cu; r[16]=0x0c0c2bcau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2bcau) { target=s->pc; goto dispatch; }
goto P_0c0c2bca;
P_0c0c2bc8: /* original 0009, guest PC 0x0c0c2bc8 */
if(!s->budget--) { s->failed_pc=0x0c0c2bc8u; return 0; }
goto P_0c0c2bca;
P_0c0c2bca: /* original 9030, guest PC 0x0c0c2bca */
if(!s->budget--) { s->failed_pc=0x0c0c2bcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2c2eu,2);
goto P_0c0c2bcc;
P_0c0c2bcc: /* original e320, guest PC 0x0c0c2bcc */
if(!s->budget--) { s->failed_pc=0x0c0c2bccu; return 0; }
r[3]=0x00000020u;
goto P_0c0c2bce;
P_0c0c2bce: /* original 04ee, guest PC 0x0c0c2bce */
if(!s->budget--) { s->failed_pc=0x0c0c2bceu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c2bd0;
P_0c0c2bd0: /* original 3437, guest PC 0x0c0c2bd0 */
if(!s->budget--) { s->failed_pc=0x0c0c2bd0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c0c2bd2;
P_0c0c2bd2: /* original 8905, guest PC 0x0c0c2bd2 */
if(!s->budget--) { s->failed_pc=0x0c0c2bd2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2be0; }
goto P_0c0c2bd4;
P_0c0c2bd4: /* original 6043, guest PC 0x0c0c2bd4 */
if(!s->budget--) { s->failed_pc=0x0c0c2bd4u; return 0; }
r[0]=r[4];
goto P_0c0c2bd6;
P_0c0c2bd6: /* original 88ff, guest PC 0x0c0c2bd6 */
if(!s->budget--) { s->failed_pc=0x0c0c2bd6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c2bd8;
P_0c0c2bd8: /* original 8902, guest PC 0x0c0c2bd8 */
if(!s->budget--) { s->failed_pc=0x0c0c2bd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c2be0; }
goto P_0c0c2bda;
P_0c0c2bda: /* original d223, guest PC 0x0c0c2bda */
if(!s->budget--) { s->failed_pc=0x0c0c2bdau; return 0; }
r[2]=read(ram,0x0c0c2c68u,4);
goto P_0c0c2bdc;
P_0c0c2bdc: /* original 420b, guest PC 0x0c0c2bdc */
if(!s->budget--) { s->failed_pc=0x0c0c2bdcu; return 0; }
target=r[2];
r[16]=0x0c0c2be0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2be0u) { target=s->pc; goto dispatch; }
goto P_0c0c2be0;
P_0c0c2bde: /* original 0009, guest PC 0x0c0c2bde */
if(!s->budget--) { s->failed_pc=0x0c0c2bdeu; return 0; }
goto P_0c0c2be0;
P_0c0c2be0: /* original 9026, guest PC 0x0c0c2be0 */
if(!s->budget--) { s->failed_pc=0x0c0c2be0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2c30u,2);
goto P_0c0c2be2;
P_0c0c2be2: /* original 00ee, guest PC 0x0c0c2be2 */
if(!s->budget--) { s->failed_pc=0x0c0c2be2u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0c2be4;
P_0c0c2be4: /* original 88ff, guest PC 0x0c0c2be4 */
if(!s->budget--) { s->failed_pc=0x0c0c2be4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c2be6;
P_0c0c2be6: /* original 8d0d, guest PC 0x0c0c2be6 */
if(!s->budget--) { s->failed_pc=0x0c0c2be6u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0c2c04; }
goto P_0c0c2bea;
P_0c0c2be8: /* original 6403, guest PC 0x0c0c2be8 */
if(!s->budget--) { s->failed_pc=0x0c0c2be8u; return 0; }
r[4]=r[0];
goto P_0c0c2bea;
P_0c0c2bea: /* original 9021, guest PC 0x0c0c2bea */
if(!s->budget--) { s->failed_pc=0x0c0c2beau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2c30u,2);
goto P_0c0c2bec;
P_0c0c2bec: /* original 6243, guest PC 0x0c0c2bec */
if(!s->budget--) { s->failed_pc=0x0c0c2becu; return 0; }
r[2]=r[4];
goto P_0c0c2bee;
P_0c0c2bee: /* original 72ff, guest PC 0x0c0c2bee */
if(!s->budget--) { s->failed_pc=0x0c0c2beeu; return 0; }
r[2]+=0xffffffffu;
goto P_0c0c2bf0;
P_0c0c2bf0: /* original 4421, guest PC 0x0c0c2bf0 */
if(!s->budget--) { s->failed_pc=0x0c0c2bf0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]=(uint32_t)((int32_t)r[4]>>1);
goto P_0c0c2bf2;
P_0c0c2bf2: /* original 0e26, guest PC 0x0c0c2bf2 */
if(!s->budget--) { s->failed_pc=0x0c0c2bf2u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c2bf4;
P_0c0c2bf4: /* original 931d, guest PC 0x0c0c2bf4 */
if(!s->budget--) { s->failed_pc=0x0c0c2bf4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2c32u,2);
goto P_0c0c2bf6;
P_0c0c2bf6: /* original 4408, guest PC 0x0c0c2bf6 */
if(!s->budget--) { s->failed_pc=0x0c0c2bf6u; return 0; }
r[4]<<=2;
goto P_0c0c2bf8;
P_0c0c2bf8: /* original d21c, guest PC 0x0c0c2bf8 */
if(!s->budget--) { s->failed_pc=0x0c0c2bf8u; return 0; }
r[2]=read(ram,0x0c0c2c6cu,4);
goto P_0c0c2bfa;
P_0c0c2bfa: /* original 2439, guest PC 0x0c0c2bfa */
if(!s->budget--) { s->failed_pc=0x0c0c2bfau; return 0; }
r[4]&=r[3];
goto P_0c0c2bfc;
P_0c0c2bfc: /* original 901a, guest PC 0x0c0c2bfc */
if(!s->budget--) { s->failed_pc=0x0c0c2bfcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2c34u,2);
goto P_0c0c2bfe;
P_0c0c2bfe: /* original 0427, guest PC 0x0c0c2bfe */
if(!s->budget--) { s->failed_pc=0x0c0c2bfeu; return 0; }
r[19]=r[4]*r[2];
goto P_0c0c2c00;
P_0c0c2c00: /* original 041a, guest PC 0x0c0c2c00 */
if(!s->budget--) { s->failed_pc=0x0c0c2c00u; return 0; }
r[4]=r[19];
goto P_0c0c2c02;
P_0c0c2c02: /* original 0e46, guest PC 0x0c0c2c02 */
if(!s->budget--) { s->failed_pc=0x0c0c2c02u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c2c04;
P_0c0c2c04: /* original 62e3, guest PC 0x0c0c2c04 */
if(!s->budget--) { s->failed_pc=0x0c0c2c04u; return 0; }
r[2]=r[14];
goto P_0c0c2c06;
P_0c0c2c06: /* original 63e3, guest PC 0x0c0c2c06 */
if(!s->budget--) { s->failed_pc=0x0c0c2c06u; return 0; }
r[3]=r[14];
goto P_0c0c2c08;
P_0c0c2c08: /* original 722c, guest PC 0x0c0c2c08 */
if(!s->budget--) { s->failed_pc=0x0c0c2c08u; return 0; }
r[2]+=0x0000002cu;
goto P_0c0c2c0a;
P_0c0c2c0a: /* original 1fe2, guest PC 0x0c0c2c0a */
if(!s->budget--) { s->failed_pc=0x0c0c2c0au; return 0; }
write(ram,r[15]+8,r[14],4);
goto P_0c0c2c0c;
P_0c0c2c0c: /* original 7358, guest PC 0x0c0c2c0c */
if(!s->budget--) { s->failed_pc=0x0c0c2c0cu; return 0; }
r[3]+=0x00000058u;
goto P_0c0c2c0e;
P_0c0c2c0e: /* original 1f31, guest PC 0x0c0c2c0e */
if(!s->budget--) { s->failed_pc=0x0c0c2c0eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c2c10;
P_0c0c2c10: /* original 2f22, guest PC 0x0c0c2c10 */
if(!s->budget--) { s->failed_pc=0x0c0c2c10u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c2c12;
P_0c0c2c12: /* original 9410, guest PC 0x0c0c2c12 */
if(!s->budget--) { s->failed_pc=0x0c0c2c12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2c36u,2);
goto P_0c0c2c14;
P_0c0c2c14: /* original b8b7, guest PC 0x0c0c2c14 */
if(!s->budget--) { s->failed_pc=0x0c0c2c14u; return 0; }
target=0x0c0c1d86u; r[16]=0x0c0c2c18u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2c18u) { target=s->pc; goto dispatch; }
goto P_0c0c2c18;
P_0c0c2c16: /* original 34ec, guest PC 0x0c0c2c16 */
if(!s->budget--) { s->failed_pc=0x0c0c2c16u; return 0; }
r[4]+=r[14];
goto P_0c0c2c18;
P_0c0c2c18: /* original b8b5, guest PC 0x0c0c2c18 */
if(!s->budget--) { s->failed_pc=0x0c0c2c18u; return 0; }
target=0x0c0c1d86u; r[16]=0x0c0c2c1cu;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2c1cu) { target=s->pc; goto dispatch; }
goto P_0c0c2c1c;
P_0c0c2c1a: /* original 54f1, guest PC 0x0c0c2c1a */
if(!s->budget--) { s->failed_pc=0x0c0c2c1au; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c2c1c;
P_0c0c2c1c: /* original b8b3, guest PC 0x0c0c2c1c */
if(!s->budget--) { s->failed_pc=0x0c0c2c1cu; return 0; }
target=0x0c0c1d86u; r[16]=0x0c0c2c20u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c2c20u) { target=s->pc; goto dispatch; }
goto P_0c0c2c20;
P_0c0c2c1e: /* original 64f2, guest PC 0x0c0c2c1e */
if(!s->budget--) { s->failed_pc=0x0c0c2c1eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c2c20;
P_0c0c2c20: /* original 54f2, guest PC 0x0c0c2c20 */
if(!s->budget--) { s->failed_pc=0x0c0c2c20u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0c2c22;
P_0c0c2c22: /* original 7f0c, guest PC 0x0c0c2c22 */
if(!s->budget--) { s->failed_pc=0x0c0c2c22u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c2c24;
P_0c0c2c24: /* original 4f16, guest PC 0x0c0c2c24 */
if(!s->budget--) { s->failed_pc=0x0c0c2c24u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c2c26;
P_0c0c2c26: /* original 4f26, guest PC 0x0c0c2c26 */
if(!s->budget--) { s->failed_pc=0x0c0c2c26u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c2c28;
P_0c0c2c28: /* original a8ad, guest PC 0x0c0c2c28 */
if(!s->budget--) { s->failed_pc=0x0c0c2c28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c1d86;
P_0c0c2c2a: /* original 6ef6, guest PC 0x0c0c2c2a */
if(!s->budget--) { s->failed_pc=0x0c0c2c2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c2c2cu,s,ram);
P_0c0c4eba: /* original 4f22, guest PC 0x0c0c4eba */
if(!s->budget--) { s->failed_pc=0x0c0c4ebau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c4ebc;
P_0c0c4ebc: /* original 4f12, guest PC 0x0c0c4ebc */
if(!s->budget--) { s->failed_pc=0x0c0c4ebcu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c4ebe;
P_0c0c4ebe: /* original 7ff4, guest PC 0x0c0c4ebe */
if(!s->budget--) { s->failed_pc=0x0c0c4ebeu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c4ec0;
P_0c0c4ec0: /* original 1f41, guest PC 0x0c0c4ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ec0u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0c4ec2;
P_0c0c4ec2: /* original db28, guest PC 0x0c0c4ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ec2u; return 0; }
r[11]=read(ram,0x0c0c4f64u,4);
goto P_0c0c4ec4;
P_0c0c4ec4: /* original d728, guest PC 0x0c0c4ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ec4u; return 0; }
r[7]=read(ram,0x0c0c4f68u,4);
goto P_0c0c4ec6;
P_0c0c4ec6: /* original 64b2, guest PC 0x0c0c4ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ec6u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c0c4ec8;
P_0c0c4ec8: /* original 84b9, guest PC 0x0c0c4ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ec8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+9,1);
goto P_0c0c4eca;
P_0c0c4eca: /* original 6343, guest PC 0x0c0c4eca */
if(!s->budget--) { s->failed_pc=0x0c0c4ecau; return 0; }
r[3]=r[4];
goto P_0c0c4ecc;
P_0c0c4ecc: /* original 2379, guest PC 0x0c0c4ecc */
if(!s->budget--) { s->failed_pc=0x0c0c4eccu; return 0; }
r[3]&=r[7];
goto P_0c0c4ece;
P_0c0c4ece: /* original 2338, guest PC 0x0c0c4ece */
if(!s->budget--) { s->failed_pc=0x0c0c4eceu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c4ed0;
P_0c0c4ed0: /* original 2f32, guest PC 0x0c0c4ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ed0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c4ed2;
P_0c0c4ed2: /* original 660c, guest PC 0x0c0c4ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ed2u; return 0; }
r[6]=r[0]&255u;
goto P_0c0c4ed4;
P_0c0c4ed4: /* original 8d05, guest PC 0x0c0c4ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ed4u; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[11]+4,4);
if(cond) { goto P_0c0c4ee2; }
goto P_0c0c4ed8;
P_0c0c4ed6: /* original 55b1, guest PC 0x0c0c4ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ed6u; return 0; }
r[5]=read(ram,r[11]+4,4);
goto P_0c0c4ed8;
P_0c0c4ed8: /* original d324, guest PC 0x0c0c4ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ed8u; return 0; }
r[3]=read(ram,0x0c0c4f6cu,4);
goto P_0c0c4eda;
P_0c0c4eda: /* original 2358, guest PC 0x0c0c4eda */
if(!s->budget--) { s->failed_pc=0x0c0c4edau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0c4edc;
P_0c0c4edc: /* original 8901, guest PC 0x0c0c4edc */
if(!s->budget--) { s->failed_pc=0x0c0c4edcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4ee2; }
goto P_0c0c4ede;
P_0c0c4ede: /* original a099, guest PC 0x0c0c4ede */
if(!s->budget--) { s->failed_pc=0x0c0c4edeu; return 0; }
goto P_0c0c5014;
P_0c0c4ee0: /* original 0009, guest PC 0x0c0c4ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ee0u; return 0; }
goto P_0c0c4ee2;
P_0c0c4ee2: /* original 9232, guest PC 0x0c0c4ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ee2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f4au,2);
goto P_0c0c4ee4;
P_0c0c4ee4: /* original 2249, guest PC 0x0c0c4ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ee4u; return 0; }
r[2]&=r[4];
goto P_0c0c4ee6;
P_0c0c4ee6: /* original 2228, guest PC 0x0c0c4ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ee6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c4ee8;
P_0c0c4ee8: /* original 8d02, guest PC 0x0c0c4ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ee8u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[2],4);
if(cond) { goto P_0c0c4ef0; }
goto P_0c0c4eec;
P_0c0c4eea: /* original 2f22, guest PC 0x0c0c4eea */
if(!s->budget--) { s->failed_pc=0x0c0c4eeau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c4eec;
P_0c0c4eec: /* original a092, guest PC 0x0c0c4eec */
if(!s->budget--) { s->failed_pc=0x0c0c4eecu; return 0; }
goto P_0c0c5014;
P_0c0c4eee: /* original 0009, guest PC 0x0c0c4eee */
if(!s->budget--) { s->failed_pc=0x0c0c4eeeu; return 0; }
goto P_0c0c4ef0;
P_0c0c4ef0: /* original e320, guest PC 0x0c0c4ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ef0u; return 0; }
r[3]=0x00000020u;
goto P_0c0c4ef2;
P_0c0c4ef2: /* original 3637, guest PC 0x0c0c4ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ef2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[3])!=0);
goto P_0c0c4ef4;
P_0c0c4ef4: /* original 8b01, guest PC 0x0c0c4ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ef4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4efa; }
goto P_0c0c4ef6;
P_0c0c4ef6: /* original a08d, guest PC 0x0c0c4ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ef6u; return 0; }
goto P_0c0c5014;
P_0c0c4ef8: /* original 0009, guest PC 0x0c0c4ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ef8u; return 0; }
goto P_0c0c4efa;
P_0c0c4efa: /* original d21d, guest PC 0x0c0c4efa */
if(!s->budget--) { s->failed_pc=0x0c0c4efau; return 0; }
r[2]=read(ram,0x0c0c4f70u,4);
goto P_0c0c4efc;
P_0c0c4efc: /* original 2248, guest PC 0x0c0c4efc */
if(!s->budget--) { s->failed_pc=0x0c0c4efcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0c4efe;
P_0c0c4efe: /* original 8b01, guest PC 0x0c0c4efe */
if(!s->budget--) { s->failed_pc=0x0c0c4efeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4f04; }
goto P_0c0c4f00;
P_0c0c4f00: /* original a088, guest PC 0x0c0c4f00 */
if(!s->budget--) { s->failed_pc=0x0c0c4f00u; return 0; }
goto P_0c0c5014;
P_0c0c4f02: /* original 0009, guest PC 0x0c0c4f02 */
if(!s->budget--) { s->failed_pc=0x0c0c4f02u; return 0; }
goto P_0c0c4f04;
P_0c0c4f04: /* original d31b, guest PC 0x0c0c4f04 */
if(!s->budget--) { s->failed_pc=0x0c0c4f04u; return 0; }
r[3]=read(ram,0x0c0c4f74u,4);
goto P_0c0c4f06;
P_0c0c4f06: /* original 2438, guest PC 0x0c0c4f06 */
if(!s->budget--) { s->failed_pc=0x0c0c4f06u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c4f08;
P_0c0c4f08: /* original 8903, guest PC 0x0c0c4f08 */
if(!s->budget--) { s->failed_pc=0x0c0c4f08u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4f12; }
goto P_0c0c4f0a;
P_0c0c4f0a: /* original 2578, guest PC 0x0c0c4f0a */
if(!s->budget--) { s->failed_pc=0x0c0c4f0au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[7])==0)!=0);
goto P_0c0c4f0c;
P_0c0c4f0c: /* original 8901, guest PC 0x0c0c4f0c */
if(!s->budget--) { s->failed_pc=0x0c0c4f0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4f12; }
goto P_0c0c4f0e;
P_0c0c4f0e: /* original a081, guest PC 0x0c0c4f0e */
if(!s->budget--) { s->failed_pc=0x0c0c4f0eu; return 0; }
goto P_0c0c5014;
P_0c0c4f10: /* original 0009, guest PC 0x0c0c4f10 */
if(!s->budget--) { s->failed_pc=0x0c0c4f10u; return 0; }
goto P_0c0c4f12;
P_0c0c4f12: /* original 901b, guest PC 0x0c0c4f12 */
if(!s->budget--) { s->failed_pc=0x0c0c4f12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f4cu,2);
goto P_0c0c4f14;
P_0c0c4f14: /* original da18, guest PC 0x0c0c4f14 */
if(!s->budget--) { s->failed_pc=0x0c0c4f14u; return 0; }
r[10]=read(ram,0x0c0c4f78u,4);
goto P_0c0c4f16;
P_0c0c4f16: /* original 00ad, guest PC 0x0c0c4f16 */
if(!s->budget--) { s->failed_pc=0x0c0c4f16u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c0c4f18;
P_0c0c4f18: /* original 88ff, guest PC 0x0c0c4f18 */
if(!s->budget--) { s->failed_pc=0x0c0c4f18u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c4f1a;
P_0c0c4f1a: /* original 8d7b, guest PC 0x0c0c4f1a */
if(!s->budget--) { s->failed_pc=0x0c0c4f1au; return 0; }
cond=r[17]&1u;
r[12]=r[0];
if(cond) { goto P_0c0c5014; }
goto P_0c0c4f1e;
P_0c0c4f1c: /* original 6c03, guest PC 0x0c0c4f1c */
if(!s->budget--) { s->failed_pc=0x0c0c4f1cu; return 0; }
r[12]=r[0];
goto P_0c0c4f1e;
P_0c0c4f1e: /* original d317, guest PC 0x0c0c4f1e */
if(!s->budget--) { s->failed_pc=0x0c0c4f1eu; return 0; }
r[3]=read(ram,0x0c0c4f7cu,4);
goto P_0c0c4f20;
P_0c0c4f20: /* original 6432, guest PC 0x0c0c4f20 */
if(!s->budget--) { s->failed_pc=0x0c0c4f20u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0c4f22;
P_0c0c4f22: /* original 854f, guest PC 0x0c0c4f22 */
if(!s->budget--) { s->failed_pc=0x0c0c4f22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c0c4f24;
P_0c0c4f24: /* original 6503, guest PC 0x0c0c4f24 */
if(!s->budget--) { s->failed_pc=0x0c0c4f24u; return 0; }
r[5]=r[0];
goto P_0c0c4f26;
P_0c0c4f26: /* original 854e, guest PC 0x0c0c4f26 */
if(!s->budget--) { s->failed_pc=0x0c0c4f26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+28,2);
goto P_0c0c4f28;
P_0c0c4f28: /* original 81f4, guest PC 0x0c0c4f28 */
if(!s->budget--) { s->failed_pc=0x0c0c4f28u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c0c4f2a;
P_0c0c4f2a: /* original 9010, guest PC 0x0c0c4f2a */
if(!s->budget--) { s->failed_pc=0x0c0c4f2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f4eu,2);
goto P_0c0c4f2c;
P_0c0c4f2c: /* original 9211, guest PC 0x0c0c4f2c */
if(!s->budget--) { s->failed_pc=0x0c0c4f2cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f52u,2);
goto P_0c0c4f2e;
P_0c0c4f2e: /* original 064d, guest PC 0x0c0c4f2e */
if(!s->budget--) { s->failed_pc=0x0c0c4f2eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c4f30;
P_0c0c4f30: /* original 900e, guest PC 0x0c0c4f30 */
if(!s->budget--) { s->failed_pc=0x0c0c4f30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f50u,2);
goto P_0c0c4f32;
P_0c0c4f32: /* original 3c20, guest PC 0x0c0c4f32 */
if(!s->budget--) { s->failed_pc=0x0c0c4f32u; return 0; }
r[17]=(r[17]&~1u)|((r[12]==r[2])!=0);
goto P_0c0c4f34;
P_0c0c4f34: /* original 04ad, guest PC 0x0c0c4f34 */
if(!s->budget--) { s->failed_pc=0x0c0c4f34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c0c4f36;
P_0c0c4f36: /* original 354c, guest PC 0x0c0c4f36 */
if(!s->budget--) { s->failed_pc=0x0c0c4f36u; return 0; }
r[5]+=r[4];
goto P_0c0c4f38;
P_0c0c4f38: /* original 8f22, guest PC 0x0c0c4f38 */
if(!s->budget--) { s->failed_pc=0x0c0c4f38u; return 0; }
cond=r[17]&1u;
r[5]=0u-r[5];
if(!cond) { goto P_0c0c4f80; }
goto P_0c0c4f3c;
P_0c0c4f3a: /* original 655b, guest PC 0x0c0c4f3a */
if(!s->budget--) { s->failed_pc=0x0c0c4f3au; return 0; }
r[5]=0u-r[5];
goto P_0c0c4f3c;
P_0c0c4f3c: /* original 940a, guest PC 0x0c0c4f3c */
if(!s->budget--) { s->failed_pc=0x0c0c4f3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f54u,2);
goto P_0c0c4f3e;
P_0c0c4f3e: /* original a020, guest PC 0x0c0c4f3e */
if(!s->budget--) { s->failed_pc=0x0c0c4f3eu; return 0; }
goto P_0c0c4f82;
P_0c0c4f40: /* original 0009, guest PC 0x0c0c4f40 */
if(!s->budget--) { s->failed_pc=0x0c0c4f40u; return 0; }
return vf3_matrix_family(0x0c0c4f42u,s,ram);
P_0c0c4f80: /* original 9451, guest PC 0x0c0c4f80 */
if(!s->budget--) { s->failed_pc=0x0c0c4f80u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5026u,2);
goto P_0c0c4f82;
P_0c0c4f82: /* original 6d5d, guest PC 0x0c0c4f82 */
if(!s->budget--) { s->failed_pc=0x0c0c4f82u; return 0; }
r[13]=r[5]&65535u;
goto P_0c0c4f84;
P_0c0c4f84: /* original 9351, guest PC 0x0c0c4f84 */
if(!s->budget--) { s->failed_pc=0x0c0c4f84u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c502au,2);
goto P_0c0c4f86;
P_0c0c4f86: /* original 0d47, guest PC 0x0c0c4f86 */
if(!s->budget--) { s->failed_pc=0x0c0c4f86u; return 0; }
r[19]=r[13]*r[4];
goto P_0c0c4f88;
P_0c0c4f88: /* original 944e, guest PC 0x0c0c4f88 */
if(!s->budget--) { s->failed_pc=0x0c0c4f88u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5028u,2);
goto P_0c0c4f8a;
P_0c0c4f8a: /* original 3637, guest PC 0x0c0c4f8a */
if(!s->budget--) { s->failed_pc=0x0c0c4f8au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[3])!=0);
goto P_0c0c4f8c;
P_0c0c4f8c: /* original 8f01, guest PC 0x0c0c4f8c */
if(!s->budget--) { s->failed_pc=0x0c0c4f8cu; return 0; }
cond=r[17]&1u;
r[13]=r[19];
if(!cond) { goto P_0c0c4f92; }
goto P_0c0c4f90;
P_0c0c4f8e: /* original 0d1a, guest PC 0x0c0c4f8e */
if(!s->budget--) { s->failed_pc=0x0c0c4f8eu; return 0; }
r[13]=r[19];
goto P_0c0c4f90;
P_0c0c4f90: /* original 944c, guest PC 0x0c0c4f90 */
if(!s->budget--) { s->failed_pc=0x0c0c4f90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c502cu,2);
goto P_0c0c4f92;
P_0c0c4f92: /* original d328, guest PC 0x0c0c4f92 */
if(!s->budget--) { s->failed_pc=0x0c0c4f92u; return 0; }
r[3]=read(ram,0x0c0c5034u,4);
goto P_0c0c4f94;
P_0c0c4f94: /* original 61d3, guest PC 0x0c0c4f94 */
if(!s->budget--) { s->failed_pc=0x0c0c4f94u; return 0; }
r[1]=r[13];
goto P_0c0c4f96;
P_0c0c4f96: /* original 430b, guest PC 0x0c0c4f96 */
if(!s->budget--) { s->failed_pc=0x0c0c4f96u; return 0; }
target=r[3];
r[16]=0x0c0c4f9au;
r[0]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c4f9au) { target=s->pc; goto dispatch; }
goto P_0c0c4f9a;
P_0c0c4f98: /* original 6043, guest PC 0x0c0c4f98 */
if(!s->budget--) { s->failed_pc=0x0c0c4f98u; return 0; }
r[0]=r[4];
goto P_0c0c4f9a;
P_0c0c4f9a: /* original 4621, guest PC 0x0c0c4f9a */
if(!s->budget--) { s->failed_pc=0x0c0c4f9au; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]=(uint32_t)((int32_t)r[6]>>1);
goto P_0c0c4f9c;
P_0c0c4f9c: /* original 6d03, guest PC 0x0c0c4f9c */
if(!s->budget--) { s->failed_pc=0x0c0c4f9cu; return 0; }
r[13]=r[0];
goto P_0c0c4f9e;
P_0c0c4f9e: /* original 2f62, guest PC 0x0c0c4f9e */
if(!s->budget--) { s->failed_pc=0x0c0c4f9eu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0c4fa0;
P_0c0c4fa0: /* original d325, guest PC 0x0c0c4fa0 */
if(!s->budget--) { s->failed_pc=0x0c0c4fa0u; return 0; }
r[3]=read(ram,0x0c0c5038u,4);
goto P_0c0c4fa2;
P_0c0c4fa2: /* original 430b, guest PC 0x0c0c4fa2 */
if(!s->budget--) { s->failed_pc=0x0c0c4fa2u; return 0; }
target=r[3];
r[16]=0x0c0c4fa6u;
r[4]=(uint32_t)(int32_t)(int16_t)r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c4fa6u) { target=s->pc; goto dispatch; }
goto P_0c0c4fa6;
P_0c0c4fa4: /* original 646f, guest PC 0x0c0c4fa4 */
if(!s->budget--) { s->failed_pc=0x0c0c4fa4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c0c4fa6;
P_0c0c4fa6: /* original c725, guest PC 0x0c0c4fa6 */
if(!s->budget--) { s->failed_pc=0x0c0c4fa6u; return 0; }
r[0]=0x0c0c503cu;
goto P_0c0c4fa8;
P_0c0c4fa8: /* original d325, guest PC 0x0c0c4fa8 */
if(!s->budget--) { s->failed_pc=0x0c0c4fa8u; return 0; }
r[3]=read(ram,0x0c0c5040u,4);
goto P_0c0c4faa;
P_0c0c4faa: /* original f508, guest PC 0x0c0c4faa */
if(!s->budget--) { s->failed_pc=0x0c0c4faau; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c4fac;
P_0c0c4fac: /* original f40c, guest PC 0x0c0c4fac */
if(!s->budget--) { s->failed_pc=0x0c0c4facu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0c4fae;
P_0c0c4fae: /* original 430b, guest PC 0x0c0c4fae */
if(!s->budget--) { s->failed_pc=0x0c0c4faeu; return 0; }
target=r[3];
r[16]=0x0c0c4fb2u;
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c4fb2u) { target=s->pc; goto dispatch; }
goto P_0c0c4fb2;
P_0c0c4fb0: /* original f452, guest PC 0x0c0c4fb0 */
if(!s->budget--) { s->failed_pc=0x0c0c4fb0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0c4fb2;
P_0c0c4fb2: /* original 640f, guest PC 0x0c0c4fb2 */
if(!s->budget--) { s->failed_pc=0x0c0c4fb2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0c4fb4;
P_0c0c4fb4: /* original 85f4, guest PC 0x0c0c4fb4 */
if(!s->budget--) { s->failed_pc=0x0c0c4fb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c0c4fb6;
P_0c0c4fb6: /* original d21f, guest PC 0x0c0c4fb6 */
if(!s->budget--) { s->failed_pc=0x0c0c4fb6u; return 0; }
r[2]=read(ram,0x0c0c5034u,4);
goto P_0c0c4fb8;
P_0c0c4fb8: /* original 6303, guest PC 0x0c0c4fb8 */
if(!s->budget--) { s->failed_pc=0x0c0c4fb8u; return 0; }
r[3]=r[0];
goto P_0c0c4fba;
P_0c0c4fba: /* original 4000, guest PC 0x0c0c4fba */
if(!s->budget--) { s->failed_pc=0x0c0c4fbau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c4fbc;
P_0c0c4fbc: /* original 303c, guest PC 0x0c0c4fbc */
if(!s->budget--) { s->failed_pc=0x0c0c4fbcu; return 0; }
r[0]+=r[3];
goto P_0c0c4fbe;
P_0c0c4fbe: /* original 4008, guest PC 0x0c0c4fbe */
if(!s->budget--) { s->failed_pc=0x0c0c4fbeu; return 0; }
r[0]<<=2;
goto P_0c0c4fc0;
P_0c0c4fc0: /* original 4008, guest PC 0x0c0c4fc0 */
if(!s->budget--) { s->failed_pc=0x0c0c4fc0u; return 0; }
r[0]<<=2;
goto P_0c0c4fc2;
P_0c0c4fc2: /* original 4008, guest PC 0x0c0c4fc2 */
if(!s->budget--) { s->failed_pc=0x0c0c4fc2u; return 0; }
r[0]<<=2;
goto P_0c0c4fc4;
P_0c0c4fc4: /* original 6103, guest PC 0x0c0c4fc4 */
if(!s->budget--) { s->failed_pc=0x0c0c4fc4u; return 0; }
r[1]=r[0];
goto P_0c0c4fc6;
P_0c0c4fc6: /* original 420b, guest PC 0x0c0c4fc6 */
if(!s->budget--) { s->failed_pc=0x0c0c4fc6u; return 0; }
target=r[2];
r[16]=0x0c0c4fcau;
r[0]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c4fcau) { target=s->pc; goto dispatch; }
goto P_0c0c4fca;
P_0c0c4fc8: /* original 6043, guest PC 0x0c0c4fc8 */
if(!s->budget--) { s->failed_pc=0x0c0c4fc8u; return 0; }
r[0]=r[4];
goto P_0c0c4fca;
P_0c0c4fca: /* original 6e03, guest PC 0x0c0c4fca */
if(!s->budget--) { s->failed_pc=0x0c0c4fcau; return 0; }
r[14]=r[0];
goto P_0c0c4fcc;
P_0c0c4fcc: /* original 902f, guest PC 0x0c0c4fcc */
if(!s->budget--) { s->failed_pc=0x0c0c4fccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c502eu,2);
goto P_0c0c4fce;
P_0c0c4fce: /* original 65d3, guest PC 0x0c0c4fce */
if(!s->budget--) { s->failed_pc=0x0c0c4fceu; return 0; }
r[5]=r[13];
goto P_0c0c4fd0;
P_0c0c4fd0: /* original 67c3, guest PC 0x0c0c4fd0 */
if(!s->budget--) { s->failed_pc=0x0c0c4fd0u; return 0; }
r[7]=r[12];
goto P_0c0c4fd2;
P_0c0c4fd2: /* original 04ad, guest PC 0x0c0c4fd2 */
if(!s->budget--) { s->failed_pc=0x0c0c4fd2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c0c4fd4;
P_0c0c4fd4: /* original da1b, guest PC 0x0c0c4fd4 */
if(!s->budget--) { s->failed_pc=0x0c0c4fd4u; return 0; }
r[10]=read(ram,0x0c0c5044u,4);
goto P_0c0c4fd6;
P_0c0c4fd6: /* original 3e48, guest PC 0x0c0c4fd6 */
if(!s->budget--) { s->failed_pc=0x0c0c4fd6u; return 0; }
r[14]-=r[4];
goto P_0c0c4fd8;
P_0c0c4fd8: /* original 66e3, guest PC 0x0c0c4fd8 */
if(!s->budget--) { s->failed_pc=0x0c0c4fd8u; return 0; }
r[6]=r[14];
goto P_0c0c4fda;
P_0c0c4fda: /* original 2fa6, guest PC 0x0c0c4fda */
if(!s->budget--) { s->failed_pc=0x0c0c4fdau; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0c4fdc;
P_0c0c4fdc: /* original b034, guest PC 0x0c0c4fdc */
if(!s->budget--) { s->failed_pc=0x0c0c4fdcu; return 0; }
target=0x0c0c5048u; r[16]=0x0c0c4fe0u;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c4fe0u) { target=s->pc; goto dispatch; }
goto P_0c0c4fe0;
P_0c0c4fde: /* original 54f2, guest PC 0x0c0c4fde */
if(!s->budget--) { s->failed_pc=0x0c0c4fdeu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0c4fe0;
P_0c0c4fe0: /* original e01c, guest PC 0x0c0c4fe0 */
if(!s->budget--) { s->failed_pc=0x0c0c4fe0u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c4fe2;
P_0c0c4fe2: /* original 62e3, guest PC 0x0c0c4fe2 */
if(!s->budget--) { s->failed_pc=0x0c0c4fe2u; return 0; }
r[2]=r[14];
goto P_0c0c4fe4;
P_0c0c4fe4: /* original e40f, guest PC 0x0c0c4fe4 */
if(!s->budget--) { s->failed_pc=0x0c0c4fe4u; return 0; }
r[4]=0x0000000fu;
goto P_0c0c4fe6;
P_0c0c4fe6: /* original e507, guest PC 0x0c0c4fe6 */
if(!s->budget--) { s->failed_pc=0x0c0c4fe6u; return 0; }
r[5]=0x00000007u;
goto P_0c0c4fe8;
P_0c0c4fe8: /* original 2259, guest PC 0x0c0c4fe8 */
if(!s->budget--) { s->failed_pc=0x0c0c4fe8u; return 0; }
r[2]&=r[5];
goto P_0c0c4fea;
P_0c0c4fea: /* original 7f04, guest PC 0x0c0c4fea */
if(!s->budget--) { s->failed_pc=0x0c0c4feau; return 0; }
r[15]+=0x00000004u;
goto P_0c0c4fec;
P_0c0c4fec: /* original 2f22, guest PC 0x0c0c4fec */
if(!s->budget--) { s->failed_pc=0x0c0c4fecu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c4fee;
P_0c0c4fee: /* original 00bc, guest PC 0x0c0c4fee */
if(!s->budget--) { s->failed_pc=0x0c0c4feeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c4ff0;
P_0c0c4ff0: /* original 600c, guest PC 0x0c0c4ff0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ff0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c4ff2;
P_0c0c4ff2: /* original 2409, guest PC 0x0c0c4ff2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ff2u; return 0; }
r[4]&=r[0];
goto P_0c0c4ff4;
P_0c0c4ff4: /* original 6043, guest PC 0x0c0c4ff4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ff4u; return 0; }
r[0]=r[4];
goto P_0c0c4ff6;
P_0c0c4ff6: /* original 880d, guest PC 0x0c0c4ff6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ff6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0c4ff8;
P_0c0c4ff8: /* original 8b06, guest PC 0x0c0c4ff8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ff8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5008; }
goto P_0c0c4ffa;
P_0c0c4ffa: /* original 65d3, guest PC 0x0c0c4ffa */
if(!s->budget--) { s->failed_pc=0x0c0c4ffau; return 0; }
r[5]=r[13];
goto P_0c0c4ffc;
P_0c0c4ffc: /* original 66e3, guest PC 0x0c0c4ffc */
if(!s->budget--) { s->failed_pc=0x0c0c4ffcu; return 0; }
r[6]=r[14];
goto P_0c0c4ffe;
P_0c0c4ffe: /* original b539, guest PC 0x0c0c4ffe */
if(!s->budget--) { s->failed_pc=0x0c0c4ffeu; return 0; }
target=0x0c0c5a74u; r[16]=0x0c0c5002u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5002u) { target=s->pc; goto dispatch; }
goto P_0c0c5002;
P_0c0c5000: /* original 54f1, guest PC 0x0c0c5000 */
if(!s->budget--) { s->failed_pc=0x0c0c5000u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c5002;
P_0c0c5002: /* original 9415, guest PC 0x0c0c5002 */
if(!s->budget--) { s->failed_pc=0x0c0c5002u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5030u,2);
goto P_0c0c5004;
P_0c0c5004: /* original a002, guest PC 0x0c0c5004 */
if(!s->budget--) { s->failed_pc=0x0c0c5004u; return 0; }
goto P_0c0c500c;
P_0c0c5006: /* original 0009, guest PC 0x0c0c5006 */
if(!s->budget--) { s->failed_pc=0x0c0c5006u; return 0; }
goto P_0c0c5008;
P_0c0c5008: /* original 64d3, guest PC 0x0c0c5008 */
if(!s->budget--) { s->failed_pc=0x0c0c5008u; return 0; }
r[4]=r[13];
goto P_0c0c500a;
P_0c0c500a: /* original 2459, guest PC 0x0c0c500a */
if(!s->budget--) { s->failed_pc=0x0c0c500au; return 0; }
r[4]&=r[5];
goto P_0c0c500c;
P_0c0c500c: /* original 6043, guest PC 0x0c0c500c */
if(!s->budget--) { s->failed_pc=0x0c0c500cu; return 0; }
r[0]=r[4];
goto P_0c0c500e;
P_0c0c500e: /* original 81aa, guest PC 0x0c0c500e */
if(!s->budget--) { s->failed_pc=0x0c0c500eu; return 0; }
write(ram,r[10]+20,r[0],2);
goto P_0c0c5010;
P_0c0c5010: /* original 60f2, guest PC 0x0c0c5010 */
if(!s->budget--) { s->failed_pc=0x0c0c5010u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0c5012;
P_0c0c5012: /* original 81ab, guest PC 0x0c0c5012 */
if(!s->budget--) { s->failed_pc=0x0c0c5012u; return 0; }
write(ram,r[10]+22,r[0],2);
goto P_0c0c5014;
P_0c0c5014: /* original 7f0c, guest PC 0x0c0c5014 */
if(!s->budget--) { s->failed_pc=0x0c0c5014u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c5016;
P_0c0c5016: /* original 4f16, guest PC 0x0c0c5016 */
if(!s->budget--) { s->failed_pc=0x0c0c5016u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5018;
P_0c0c5018: /* original 4f26, guest PC 0x0c0c5018 */
if(!s->budget--) { s->failed_pc=0x0c0c5018u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c501a;
P_0c0c501a: /* original 6af6, guest PC 0x0c0c501a */
if(!s->budget--) { s->failed_pc=0x0c0c501au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c501c;
P_0c0c501c: /* original 6bf6, guest PC 0x0c0c501c */
if(!s->budget--) { s->failed_pc=0x0c0c501cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c501e;
P_0c0c501e: /* original 6cf6, guest PC 0x0c0c501e */
if(!s->budget--) { s->failed_pc=0x0c0c501eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c5020;
P_0c0c5020: /* original 6df6, guest PC 0x0c0c5020 */
if(!s->budget--) { s->failed_pc=0x0c0c5020u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5022;
P_0c0c5022: /* original 000b, guest PC 0x0c0c5022 */
if(!s->budget--) { s->failed_pc=0x0c0c5022u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5024: /* original 6ef6, guest PC 0x0c0c5024 */
if(!s->budget--) { s->failed_pc=0x0c0c5024u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c5026u,s,ram);
P_0c0c5048: /* original 2fe6, guest PC 0x0c0c5048 */
if(!s->budget--) { s->failed_pc=0x0c0c5048u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c504a;
P_0c0c504a: /* original 2fd6, guest PC 0x0c0c504a */
if(!s->budget--) { s->failed_pc=0x0c0c504au; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0c504c;
P_0c0c504c: /* original 2fc6, guest PC 0x0c0c504c */
if(!s->budget--) { s->failed_pc=0x0c0c504cu; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0c504e;
P_0c0c504e: /* original ec00, guest PC 0x0c0c504e */
if(!s->budget--) { s->failed_pc=0x0c0c504eu; return 0; }
r[12]=0x00000000u;
goto P_0c0c5050;
P_0c0c5050: /* original 2fb6, guest PC 0x0c0c5050 */
if(!s->budget--) { s->failed_pc=0x0c0c5050u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0c5052;
P_0c0c5052: /* original 2fa6, guest PC 0x0c0c5052 */
if(!s->budget--) { s->failed_pc=0x0c0c5052u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0c5054;
P_0c0c5054: /* original 2f96, guest PC 0x0c0c5054 */
if(!s->budget--) { s->failed_pc=0x0c0c5054u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0c5056;
P_0c0c5056: /* original 6973, guest PC 0x0c0c5056 */
if(!s->budget--) { s->failed_pc=0x0c0c5056u; return 0; }
r[9]=r[7];
goto P_0c0c5058;
P_0c0c5058: /* original 2f86, guest PC 0x0c0c5058 */
if(!s->budget--) { s->failed_pc=0x0c0c5058u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0c505a;
P_0c0c505a: /* original fffb, guest PC 0x0c0c505a */
if(!s->budget--) { s->failed_pc=0x0c0c505au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c505c;
P_0c0c505c: /* original ffeb, guest PC 0x0c0c505c */
if(!s->budget--) { s->failed_pc=0x0c0c505cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0c505e;
P_0c0c505e: /* original ffdb, guest PC 0x0c0c505e */
if(!s->budget--) { s->failed_pc=0x0c0c505eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0c5060;
P_0c0c5060: /* original ffcb, guest PC 0x0c0c5060 */
if(!s->budget--) { s->failed_pc=0x0c0c5060u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
return vf3_matrix_family(0x0c0c5062u,s,ram);
P_0c0c5a74: /* original 2fe6, guest PC 0x0c0c5a74 */
if(!s->budget--) { s->failed_pc=0x0c0c5a74u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c5a76;
P_0c0c5a76: /* original 2fd6, guest PC 0x0c0c5a76 */
if(!s->budget--) { s->failed_pc=0x0c0c5a76u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0c5a78;
P_0c0c5a78: /* original 2fc6, guest PC 0x0c0c5a78 */
if(!s->budget--) { s->failed_pc=0x0c0c5a78u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0c5a7a;
P_0c0c5a7a: /* original 2fb6, guest PC 0x0c0c5a7a */
if(!s->budget--) { s->failed_pc=0x0c0c5a7au; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0c5a7c;
P_0c0c5a7c: /* original 2fa6, guest PC 0x0c0c5a7c */
if(!s->budget--) { s->failed_pc=0x0c0c5a7cu; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0c5a7e;
P_0c0c5a7e: /* original 2f86, guest PC 0x0c0c5a7e */
if(!s->budget--) { s->failed_pc=0x0c0c5a7eu; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0c5a80;
P_0c0c5a80: /* original d21e, guest PC 0x0c0c5a80 */
if(!s->budget--) { s->failed_pc=0x0c0c5a80u; return 0; }
r[2]=read(ram,0x0c0c5afcu,4);
goto P_0c0c5a82;
P_0c0c5a82: /* original 4f22, guest PC 0x0c0c5a82 */
if(!s->budget--) { s->failed_pc=0x0c0c5a82u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5a84;
P_0c0c5a84: /* original 6022, guest PC 0x0c0c5a84 */
if(!s->budget--) { s->failed_pc=0x0c0c5a84u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0c5a86;
P_0c0c5a86: /* original d31c, guest PC 0x0c0c5a86 */
if(!s->budget--) { s->failed_pc=0x0c0c5a86u; return 0; }
r[3]=read(ram,0x0c0c5af8u,4);
goto P_0c0c5a88;
P_0c0c5a88: /* original 7ff8, guest PC 0x0c0c5a88 */
if(!s->budget--) { s->failed_pc=0x0c0c5a88u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c5a8a;
P_0c0c5a8a: /* original 2038, guest PC 0x0c0c5a8a */
if(!s->budget--) { s->failed_pc=0x0c0c5a8au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[3])==0)!=0);
goto P_0c0c5a8c;
P_0c0c5a8c: /* original 8901, guest PC 0x0c0c5a8c */
if(!s->budget--) { s->failed_pc=0x0c0c5a8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5a92; }
goto P_0c0c5a8e;
P_0c0c5a8e: /* original a087, guest PC 0x0c0c5a8e */
if(!s->budget--) { s->failed_pc=0x0c0c5a8eu; return 0; }
goto P_0c0c5ba0;
P_0c0c5a90: /* original 0009, guest PC 0x0c0c5a90 */
if(!s->budget--) { s->failed_pc=0x0c0c5a90u; return 0; }
goto P_0c0c5a92;
P_0c0c5a92: /* original 902c, guest PC 0x0c0c5a92 */
if(!s->budget--) { s->failed_pc=0x0c0c5a92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5aeeu,2);
goto P_0c0c5a94;
P_0c0c5a94: /* original 666b, guest PC 0x0c0c5a94 */
if(!s->budget--) { s->failed_pc=0x0c0c5a94u; return 0; }
r[6]=0u-r[6];
goto P_0c0c5a96;
P_0c0c5a96: /* original 932b, guest PC 0x0c0c5a96 */
if(!s->budget--) { s->failed_pc=0x0c0c5a96u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5af0u,2);
goto P_0c0c5a98;
P_0c0c5a98: /* original 054e, guest PC 0x0c0c5a98 */
if(!s->budget--) { s->failed_pc=0x0c0c5a98u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0c5a9a;
P_0c0c5a9a: /* original 7501, guest PC 0x0c0c5a9a */
if(!s->budget--) { s->failed_pc=0x0c0c5a9au; return 0; }
r[5]+=0x00000001u;
goto P_0c0c5a9c;
P_0c0c5a9c: /* original 3533, guest PC 0x0c0c5a9c */
if(!s->budget--) { s->failed_pc=0x0c0c5a9cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[3])!=0);
goto P_0c0c5a9e;
P_0c0c5a9e: /* original 8f01, guest PC 0x0c0c5a9e */
if(!s->budget--) { s->failed_pc=0x0c0c5a9eu; return 0; }
cond=r[17]&1u;
r[14]=0x00000000u;
if(!cond) { goto P_0c0c5aa4; }
goto P_0c0c5aa2;
P_0c0c5aa0: /* original ee00, guest PC 0x0c0c5aa0 */
if(!s->budget--) { s->failed_pc=0x0c0c5aa0u; return 0; }
r[14]=0x00000000u;
goto P_0c0c5aa2;
P_0c0c5aa2: /* original 65e3, guest PC 0x0c0c5aa2 */
if(!s->budget--) { s->failed_pc=0x0c0c5aa2u; return 0; }
r[5]=r[14];
goto P_0c0c5aa4;
P_0c0c5aa4: /* original e764, guest PC 0x0c0c5aa4 */
if(!s->budget--) { s->failed_pc=0x0c0c5aa4u; return 0; }
r[7]=0x00000064u;
goto P_0c0c5aa6;
P_0c0c5aa6: /* original 0456, guest PC 0x0c0c5aa6 */
if(!s->budget--) { s->failed_pc=0x0c0c5aa6u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0c5aa8;
P_0c0c5aa8: /* original 3768, guest PC 0x0c0c5aa8 */
if(!s->budget--) { s->failed_pc=0x0c0c5aa8u; return 0; }
r[7]-=r[6];
goto P_0c0c5aaa;
P_0c0c5aaa: /* original 9d22, guest PC 0x0c0c5aaa */
if(!s->budget--) { s->failed_pc=0x0c0c5aaau; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5af2u,2);
goto P_0c0c5aac;
P_0c0c5aac: /* original db14, guest PC 0x0c0c5aac */
if(!s->budget--) { s->failed_pc=0x0c0c5aacu; return 0; }
r[11]=read(ram,0x0c0c5b00u,4);
goto P_0c0c5aae;
P_0c0c5aae: /* original 4521, guest PC 0x0c0c5aae */
if(!s->budget--) { s->failed_pc=0x0c0c5aaeu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]=(uint32_t)((int32_t)r[5]>>1);
goto P_0c0c5ab0;
P_0c0c5ab0: /* original 4711, guest PC 0x0c0c5ab0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ab0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=0)!=0);
goto P_0c0c5ab2;
P_0c0c5ab2: /* original 8913, guest PC 0x0c0c5ab2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ab2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5adc; }
goto P_0c0c5ab4;
P_0c0c5ab4: /* original 6673, guest PC 0x0c0c5ab4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ab4u; return 0; }
r[6]=r[7];
goto P_0c0c5ab6;
P_0c0c5ab6: /* original 36dc, guest PC 0x0c0c5ab6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ab6u; return 0; }
r[6]+=r[13];
goto P_0c0c5ab8;
P_0c0c5ab8: /* original 4611, guest PC 0x0c0c5ab8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ab8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=0)!=0);
goto P_0c0c5aba;
P_0c0c5aba: /* original 8d01, guest PC 0x0c0c5aba */
if(!s->budget--) { s->failed_pc=0x0c0c5abau; return 0; }
cond=r[17]&1u;
r[5]-=r[7];
if(cond) { goto P_0c0c5ac0; }
goto P_0c0c5abe;
P_0c0c5abc: /* original 3578, guest PC 0x0c0c5abc */
if(!s->budget--) { s->failed_pc=0x0c0c5abcu; return 0; }
r[5]-=r[7];
goto P_0c0c5abe;
P_0c0c5abe: /* original 66e3, guest PC 0x0c0c5abe */
if(!s->budget--) { s->failed_pc=0x0c0c5abeu; return 0; }
r[6]=r[14];
goto P_0c0c5ac0;
P_0c0c5ac0: /* original d310, guest PC 0x0c0c5ac0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ac0u; return 0; }
r[3]=read(ram,0x0c0c5b04u,4);
goto P_0c0c5ac2;
P_0c0c5ac2: /* original 60d3, guest PC 0x0c0c5ac2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ac2u; return 0; }
r[0]=r[13];
goto P_0c0c5ac4;
P_0c0c5ac4: /* original 430b, guest PC 0x0c0c5ac4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ac4u; return 0; }
target=r[3];
r[16]=0x0c0c5ac8u;
r[1]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c5ac8u) { target=s->pc; goto dispatch; }
goto P_0c0c5ac8;
P_0c0c5ac6: /* original 6153, guest PC 0x0c0c5ac6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ac6u; return 0; }
r[1]=r[5];
goto P_0c0c5ac8;
P_0c0c5ac8: /* original 6703, guest PC 0x0c0c5ac8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ac8u; return 0; }
r[7]=r[0];
goto P_0c0c5aca;
P_0c0c5aca: /* original 4708, guest PC 0x0c0c5aca */
if(!s->budget--) { s->failed_pc=0x0c0c5acau; return 0; }
r[7]<<=2;
goto P_0c0c5acc;
P_0c0c5acc: /* original 6303, guest PC 0x0c0c5acc */
if(!s->budget--) { s->failed_pc=0x0c0c5accu; return 0; }
r[3]=r[0];
goto P_0c0c5ace;
P_0c0c5ace: /* original 373c, guest PC 0x0c0c5ace */
if(!s->budget--) { s->failed_pc=0x0c0c5aceu; return 0; }
r[7]+=r[3];
goto P_0c0c5ad0;
P_0c0c5ad0: /* original 4708, guest PC 0x0c0c5ad0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ad0u; return 0; }
r[7]<<=2;
goto P_0c0c5ad2;
P_0c0c5ad2: /* original 4708, guest PC 0x0c0c5ad2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ad2u; return 0; }
r[7]<<=2;
goto P_0c0c5ad4;
P_0c0c5ad4: /* original 4700, guest PC 0x0c0c5ad4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ad4u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c0c5ad6;
P_0c0c5ad6: /* original 3578, guest PC 0x0c0c5ad6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ad6u; return 0; }
r[5]-=r[7];
goto P_0c0c5ad8;
P_0c0c5ad8: /* original a019, guest PC 0x0c0c5ad8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ad8u; return 0; }
r[7]=r[14];
goto P_0c0c5b0e;
P_0c0c5ada: /* original 67e3, guest PC 0x0c0c5ada */
if(!s->budget--) { s->failed_pc=0x0c0c5adau; return 0; }
r[7]=r[14];
goto P_0c0c5adc;
P_0c0c5adc: /* original 960a, guest PC 0x0c0c5adc */
if(!s->budget--) { s->failed_pc=0x0c0c5adcu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5af4u,2);
goto P_0c0c5ade;
P_0c0c5ade: /* original 3767, guest PC 0x0c0c5ade */
if(!s->budget--) { s->failed_pc=0x0c0c5adeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>(int32_t)r[6])!=0);
goto P_0c0c5ae0;
P_0c0c5ae0: /* original 8b00, guest PC 0x0c0c5ae0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ae0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5ae4; }
goto P_0c0c5ae2;
P_0c0c5ae2: /* original 6763, guest PC 0x0c0c5ae2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ae2u; return 0; }
r[7]=r[6];
goto P_0c0c5ae4;
P_0c0c5ae4: /* original 3678, guest PC 0x0c0c5ae4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ae4u; return 0; }
r[6]-=r[7];
goto P_0c0c5ae6;
P_0c0c5ae6: /* original 4611, guest PC 0x0c0c5ae6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ae6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=0)!=0);
goto P_0c0c5ae8;
P_0c0c5ae8: /* original 890e, guest PC 0x0c0c5ae8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ae8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5b08; }
goto P_0c0c5aea;
P_0c0c5aea: /* original a010, guest PC 0x0c0c5aea */
if(!s->budget--) { s->failed_pc=0x0c0c5aeau; return 0; }
r[6]=r[14];
goto P_0c0c5b0e;
P_0c0c5aec: /* original 66e3, guest PC 0x0c0c5aec */
if(!s->budget--) { s->failed_pc=0x0c0c5aecu; return 0; }
r[6]=r[14];
return vf3_matrix_family(0x0c0c5aeeu,s,ram);
P_0c0c5b08: /* original 36d7, guest PC 0x0c0c5b08 */
if(!s->budget--) { s->failed_pc=0x0c0c5b08u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[13])!=0);
goto P_0c0c5b0a;
P_0c0c5b0a: /* original 8b00, guest PC 0x0c0c5b0a */
if(!s->budget--) { s->failed_pc=0x0c0c5b0au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5b0e; }
goto P_0c0c5b0c;
P_0c0c5b0c: /* original 66d3, guest PC 0x0c0c5b0c */
if(!s->budget--) { s->failed_pc=0x0c0c5b0cu; return 0; }
r[6]=r[13];
goto P_0c0c5b0e;
P_0c0c5b0e: /* original 9c55, guest PC 0x0c0c5b0e */
if(!s->budget--) { s->failed_pc=0x0c0c5b0eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5bbcu,2);
goto P_0c0c5b10;
P_0c0c5b10: /* original 3c78, guest PC 0x0c0c5b10 */
if(!s->budget--) { s->failed_pc=0x0c0c5b10u; return 0; }
r[12]-=r[7];
goto P_0c0c5b12;
P_0c0c5b12: /* original 3c68, guest PC 0x0c0c5b12 */
if(!s->budget--) { s->failed_pc=0x0c0c5b12u; return 0; }
r[12]-=r[6];
goto P_0c0c5b14;
P_0c0c5b14: /* original 4c11, guest PC 0x0c0c5b14 */
if(!s->budget--) { s->failed_pc=0x0c0c5b14u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=0)!=0);
goto P_0c0c5b16;
P_0c0c5b16: /* original 8d01, guest PC 0x0c0c5b16 */
if(!s->budget--) { s->failed_pc=0x0c0c5b16u; return 0; }
cond=r[17]&1u;
r[2]=r[4];
if(cond) { goto P_0c0c5b1c; }
goto P_0c0c5b1a;
P_0c0c5b18: /* original 6243, guest PC 0x0c0c5b18 */
if(!s->budget--) { s->failed_pc=0x0c0c5b18u; return 0; }
r[2]=r[4];
goto P_0c0c5b1a;
P_0c0c5b1a: /* original 6ce3, guest PC 0x0c0c5b1a */
if(!s->budget--) { s->failed_pc=0x0c0c5b1au; return 0; }
r[12]=r[14];
goto P_0c0c5b1c;
P_0c0c5b1c: /* original 6353, guest PC 0x0c0c5b1c */
if(!s->budget--) { s->failed_pc=0x0c0c5b1cu; return 0; }
r[3]=r[5];
goto P_0c0c5b1e;
P_0c0c5b1e: /* original 4308, guest PC 0x0c0c5b1e */
if(!s->budget--) { s->failed_pc=0x0c0c5b1eu; return 0; }
r[3]<<=2;
goto P_0c0c5b20;
P_0c0c5b20: /* original 7208, guest PC 0x0c0c5b20 */
if(!s->budget--) { s->failed_pc=0x0c0c5b20u; return 0; }
r[2]+=0x00000008u;
goto P_0c0c5b22;
P_0c0c5b22: /* original 332c, guest PC 0x0c0c5b22 */
if(!s->budget--) { s->failed_pc=0x0c0c5b22u; return 0; }
r[3]+=r[2];
goto P_0c0c5b24;
P_0c0c5b24: /* original 2778, guest PC 0x0c0c5b24 */
if(!s->budget--) { s->failed_pc=0x0c0c5b24u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c5b26;
P_0c0c5b26: /* original 2f32, guest PC 0x0c0c5b26 */
if(!s->budget--) { s->failed_pc=0x0c0c5b26u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c5b28;
P_0c0c5b28: /* original 8d08, guest PC 0x0c0c5b28 */
if(!s->budget--) { s->failed_pc=0x0c0c5b28u; return 0; }
cond=r[17]&1u;
r[10]=0x00000008u;
if(cond) { goto P_0c0c5b3c; }
goto P_0c0c5b2c;
P_0c0c5b2a: /* original ea08, guest PC 0x0c0c5b2a */
if(!s->budget--) { s->failed_pc=0x0c0c5b2au; return 0; }
r[10]=0x00000008u;
goto P_0c0c5b2c;
P_0c0c5b2c: /* original 6073, guest PC 0x0c0c5b2c */
if(!s->budget--) { s->failed_pc=0x0c0c5b2cu; return 0; }
r[0]=r[7];
goto P_0c0c5b2e;
P_0c0c5b2e: /* original 4015, guest PC 0x0c0c5b2e */
if(!s->budget--) { s->failed_pc=0x0c0c5b2eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c0c5b30;
P_0c0c5b30: /* original 8b04, guest PC 0x0c0c5b30 */
if(!s->budget--) { s->failed_pc=0x0c0c5b30u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5b3c; }
goto P_0c0c5b32;
P_0c0c5b32: /* original 70ff, guest PC 0x0c0c5b32 */
if(!s->budget--) { s->failed_pc=0x0c0c5b32u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c5b34;
P_0c0c5b34: /* original 2ba1, guest PC 0x0c0c5b34 */
if(!s->budget--) { s->failed_pc=0x0c0c5b34u; return 0; }
write(ram,r[11],r[10],2);
goto P_0c0c5b36;
P_0c0c5b36: /* original 4015, guest PC 0x0c0c5b36 */
if(!s->budget--) { s->failed_pc=0x0c0c5b36u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c0c5b38;
P_0c0c5b38: /* original 8dfb, guest PC 0x0c0c5b38 */
if(!s->budget--) { s->failed_pc=0x0c0c5b38u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000002u;
if(cond) { goto P_0c0c5b32; }
goto P_0c0c5b3c;
P_0c0c5b3a: /* original 7b02, guest PC 0x0c0c5b3a */
if(!s->budget--) { s->failed_pc=0x0c0c5b3au; return 0; }
r[11]+=0x00000002u;
goto P_0c0c5b3c;
P_0c0c5b3c: /* original 2668, guest PC 0x0c0c5b3c */
if(!s->budget--) { s->failed_pc=0x0c0c5b3cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0c5b3e;
P_0c0c5b3e: /* original 8925, guest PC 0x0c0c5b3e */
if(!s->budget--) { s->failed_pc=0x0c0c5b3eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5b8c; }
goto P_0c0c5b40;
P_0c0c5b40: /* original 63d3, guest PC 0x0c0c5b40 */
if(!s->budget--) { s->failed_pc=0x0c0c5b40u; return 0; }
r[3]=r[13];
goto P_0c0c5b42;
P_0c0c5b42: /* original 3368, guest PC 0x0c0c5b42 */
if(!s->budget--) { s->failed_pc=0x0c0c5b42u; return 0; }
r[3]-=r[6];
goto P_0c0c5b44;
P_0c0c5b44: /* original c71e, guest PC 0x0c0c5b44 */
if(!s->budget--) { s->failed_pc=0x0c0c5b44u; return 0; }
r[0]=0x0c0c5bc0u;
goto P_0c0c5b46;
P_0c0c5b46: /* original 6863, guest PC 0x0c0c5b46 */
if(!s->budget--) { s->failed_pc=0x0c0c5b46u; return 0; }
r[8]=r[6];
goto P_0c0c5b48;
P_0c0c5b48: /* original f608, guest PC 0x0c0c5b48 */
if(!s->budget--) { s->failed_pc=0x0c0c5b48u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0c5b4a;
P_0c0c5b4a: /* original 4815, guest PC 0x0c0c5b4a */
if(!s->budget--) { s->failed_pc=0x0c0c5b4au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>0)!=0);
goto P_0c0c5b4c;
P_0c0c5b4c: /* original 1f31, guest PC 0x0c0c5b4c */
if(!s->budget--) { s->failed_pc=0x0c0c5b4cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c5b4e;
P_0c0c5b4e: /* original 435a, guest PC 0x0c0c5b4e */
if(!s->budget--) { s->failed_pc=0x0c0c5b4eu; return 0; }
r[53]=r[3];
goto P_0c0c5b50;
P_0c0c5b50: /* original f56c, guest PC 0x0c0c5b50 */
if(!s->budget--) { s->failed_pc=0x0c0c5b50u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c0c5b52;
P_0c0c5b52: /* original f32d, guest PC 0x0c0c5b52 */
if(!s->budget--) { s->failed_pc=0x0c0c5b52u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c5b54;
P_0c0c5b54: /* original f43c, guest PC 0x0c0c5b54 */
if(!s->budget--) { s->failed_pc=0x0c0c5b54u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0c5b56;
P_0c0c5b56: /* original 8f19, guest PC 0x0c0c5b56 */
if(!s->budget--) { s->failed_pc=0x0c0c5b56u; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
if(!cond) { goto P_0c0c5b8c; }
goto P_0c0c5b5a;
P_0c0c5b58: /* original f542, guest PC 0x0c0c5b58 */
if(!s->budget--) { s->failed_pc=0x0c0c5b58u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c0c5b5a;
P_0c0c5b5a: /* original 62f2, guest PC 0x0c0c5b5a */
if(!s->budget--) { s->failed_pc=0x0c0c5b5au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c5b5c;
P_0c0c5b5c: /* original 7501, guest PC 0x0c0c5b5c */
if(!s->budget--) { s->failed_pc=0x0c0c5b5cu; return 0; }
r[5]+=0x00000001u;
goto P_0c0c5b5e;
P_0c0c5b5e: /* original 35d3, guest PC 0x0c0c5b5e */
if(!s->budget--) { s->failed_pc=0x0c0c5b5eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[13])!=0);
goto P_0c0c5b60;
P_0c0c5b60: /* original 7204, guest PC 0x0c0c5b60 */
if(!s->budget--) { s->failed_pc=0x0c0c5b60u; return 0; }
r[2]+=0x00000004u;
goto P_0c0c5b62;
P_0c0c5b62: /* original 2f22, guest PC 0x0c0c5b62 */
if(!s->budget--) { s->failed_pc=0x0c0c5b62u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c5b64;
P_0c0c5b64: /* original 72fc, guest PC 0x0c0c5b64 */
if(!s->budget--) { s->failed_pc=0x0c0c5b64u; return 0; }
r[2]+=0xfffffffcu;
goto P_0c0c5b66;
P_0c0c5b66: /* original 8f04, guest PC 0x0c0c5b66 */
if(!s->budget--) { s->failed_pc=0x0c0c5b66u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[2]);
if(!cond) { goto P_0c0c5b72; }
goto P_0c0c5b6a;
P_0c0c5b68: /* original f428, guest PC 0x0c0c5b68 */
if(!s->budget--) { s->failed_pc=0x0c0c5b68u; return 0; }
vf3_matrix_load(s,ram,4,r[2]);
goto P_0c0c5b6a;
P_0c0c5b6a: /* original 6243, guest PC 0x0c0c5b6a */
if(!s->budget--) { s->failed_pc=0x0c0c5b6au; return 0; }
r[2]=r[4];
goto P_0c0c5b6c;
P_0c0c5b6c: /* original 7208, guest PC 0x0c0c5b6c */
if(!s->budget--) { s->failed_pc=0x0c0c5b6cu; return 0; }
r[2]+=0x00000008u;
goto P_0c0c5b6e;
P_0c0c5b6e: /* original 2f22, guest PC 0x0c0c5b6e */
if(!s->budget--) { s->failed_pc=0x0c0c5b6eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c5b70;
P_0c0c5b70: /* original 65e3, guest PC 0x0c0c5b70 */
if(!s->budget--) { s->failed_pc=0x0c0c5b70u; return 0; }
r[5]=r[14];
goto P_0c0c5b72;
P_0c0c5b72: /* original d314, guest PC 0x0c0c5b72 */
if(!s->budget--) { s->failed_pc=0x0c0c5b72u; return 0; }
r[3]=read(ram,0x0c0c5bc4u,4);
goto P_0c0c5b74;
P_0c0c5b74: /* original f452, guest PC 0x0c0c5b74 */
if(!s->budget--) { s->failed_pc=0x0c0c5b74u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0c5b76;
P_0c0c5b76: /* original f560, guest PC 0x0c0c5b76 */
if(!s->budget--) { s->failed_pc=0x0c0c5b76u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'+');
goto P_0c0c5b78;
P_0c0c5b78: /* original 78ff, guest PC 0x0c0c5b78 */
if(!s->budget--) { s->failed_pc=0x0c0c5b78u; return 0; }
r[8]+=0xffffffffu;
goto P_0c0c5b7a;
P_0c0c5b7a: /* original f338, guest PC 0x0c0c5b7a */
if(!s->budget--) { s->failed_pc=0x0c0c5b7au; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c0c5b7c;
P_0c0c5b7c: /* original 4815, guest PC 0x0c0c5b7c */
if(!s->budget--) { s->failed_pc=0x0c0c5b7cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>0)!=0);
goto P_0c0c5b7e;
P_0c0c5b7e: /* original f432, guest PC 0x0c0c5b7e */
if(!s->budget--) { s->failed_pc=0x0c0c5b7eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0c5b80;
P_0c0c5b80: /* original f43d, guest PC 0x0c0c5b80 */
if(!s->budget--) { s->failed_pc=0x0c0c5b80u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0c5b82;
P_0c0c5b82: /* original 005a, guest PC 0x0c0c5b82 */
if(!s->budget--) { s->failed_pc=0x0c0c5b82u; return 0; }
r[0]=r[53];
goto P_0c0c5b84;
P_0c0c5b84: /* original 7008, guest PC 0x0c0c5b84 */
if(!s->budget--) { s->failed_pc=0x0c0c5b84u; return 0; }
r[0]+=0x00000008u;
goto P_0c0c5b86;
P_0c0c5b86: /* original 2b01, guest PC 0x0c0c5b86 */
if(!s->budget--) { s->failed_pc=0x0c0c5b86u; return 0; }
write(ram,r[11],r[0],2);
goto P_0c0c5b88;
P_0c0c5b88: /* original 8de7, guest PC 0x0c0c5b88 */
if(!s->budget--) { s->failed_pc=0x0c0c5b88u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000002u;
if(cond) { goto P_0c0c5b5a; }
goto P_0c0c5b8c;
P_0c0c5b8a: /* original 7b02, guest PC 0x0c0c5b8a */
if(!s->budget--) { s->failed_pc=0x0c0c5b8au; return 0; }
r[11]+=0x00000002u;
goto P_0c0c5b8c;
P_0c0c5b8c: /* original 2cc8, guest PC 0x0c0c5b8c */
if(!s->budget--) { s->failed_pc=0x0c0c5b8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0c5b8e;
P_0c0c5b8e: /* original 8907, guest PC 0x0c0c5b8e */
if(!s->budget--) { s->failed_pc=0x0c0c5b8eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5ba0; }
goto P_0c0c5b90;
P_0c0c5b90: /* original 64c3, guest PC 0x0c0c5b90 */
if(!s->budget--) { s->failed_pc=0x0c0c5b90u; return 0; }
r[4]=r[12];
goto P_0c0c5b92;
P_0c0c5b92: /* original 4415, guest PC 0x0c0c5b92 */
if(!s->budget--) { s->failed_pc=0x0c0c5b92u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0c5b94;
P_0c0c5b94: /* original 8b04, guest PC 0x0c0c5b94 */
if(!s->budget--) { s->failed_pc=0x0c0c5b94u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5ba0; }
goto P_0c0c5b96;
P_0c0c5b96: /* original 74ff, guest PC 0x0c0c5b96 */
if(!s->budget--) { s->failed_pc=0x0c0c5b96u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0c5b98;
P_0c0c5b98: /* original 2ba1, guest PC 0x0c0c5b98 */
if(!s->budget--) { s->failed_pc=0x0c0c5b98u; return 0; }
write(ram,r[11],r[10],2);
goto P_0c0c5b9a;
P_0c0c5b9a: /* original 4415, guest PC 0x0c0c5b9a */
if(!s->budget--) { s->failed_pc=0x0c0c5b9au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0c5b9c;
P_0c0c5b9c: /* original 8dfb, guest PC 0x0c0c5b9c */
if(!s->budget--) { s->failed_pc=0x0c0c5b9cu; return 0; }
cond=r[17]&1u;
r[11]+=0x00000002u;
if(cond) { goto P_0c0c5b96; }
goto P_0c0c5ba0;
P_0c0c5b9e: /* original 7b02, guest PC 0x0c0c5b9e */
if(!s->budget--) { s->failed_pc=0x0c0c5b9eu; return 0; }
r[11]+=0x00000002u;
goto P_0c0c5ba0;
P_0c0c5ba0: /* original 7f08, guest PC 0x0c0c5ba0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ba0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c5ba2;
P_0c0c5ba2: /* original d309, guest PC 0x0c0c5ba2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ba2u; return 0; }
r[3]=read(ram,0x0c0c5bc8u,4);
goto P_0c0c5ba4;
P_0c0c5ba4: /* original 4f26, guest PC 0x0c0c5ba4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ba4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5ba6;
P_0c0c5ba6: /* original 2372, guest PC 0x0c0c5ba6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ba6u; return 0; }
write(ram,r[3],r[7],4);
goto P_0c0c5ba8;
P_0c0c5ba8: /* original 376c, guest PC 0x0c0c5ba8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ba8u; return 0; }
r[7]+=r[6];
goto P_0c0c5baa;
P_0c0c5baa: /* original d208, guest PC 0x0c0c5baa */
if(!s->budget--) { s->failed_pc=0x0c0c5baau; return 0; }
r[2]=read(ram,0x0c0c5bccu,4);
goto P_0c0c5bac;
P_0c0c5bac: /* original 2272, guest PC 0x0c0c5bac */
if(!s->budget--) { s->failed_pc=0x0c0c5bacu; return 0; }
write(ram,r[2],r[7],4);
goto P_0c0c5bae;
P_0c0c5bae: /* original 68f6, guest PC 0x0c0c5bae */
if(!s->budget--) { s->failed_pc=0x0c0c5baeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c5bb0;
P_0c0c5bb0: /* original 6af6, guest PC 0x0c0c5bb0 */
if(!s->budget--) { s->failed_pc=0x0c0c5bb0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c5bb2;
P_0c0c5bb2: /* original 6bf6, guest PC 0x0c0c5bb2 */
if(!s->budget--) { s->failed_pc=0x0c0c5bb2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c5bb4;
P_0c0c5bb4: /* original 6cf6, guest PC 0x0c0c5bb4 */
if(!s->budget--) { s->failed_pc=0x0c0c5bb4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c5bb6;
P_0c0c5bb6: /* original 6df6, guest PC 0x0c0c5bb6 */
if(!s->budget--) { s->failed_pc=0x0c0c5bb6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5bb8;
P_0c0c5bb8: /* original 000b, guest PC 0x0c0c5bb8 */
if(!s->budget--) { s->failed_pc=0x0c0c5bb8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5bba: /* original 6ef6, guest PC 0x0c0c5bba */
if(!s->budget--) { s->failed_pc=0x0c0c5bbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c5bbcu,s,ram);
P_0c0c7104: /* original 2fe6, guest PC 0x0c0c7104 */
if(!s->budget--) { s->failed_pc=0x0c0c7104u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c7106;
P_0c0c7106: /* original 2fd6, guest PC 0x0c0c7106 */
if(!s->budget--) { s->failed_pc=0x0c0c7106u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0c7108;
P_0c0c7108: /* original 2fc6, guest PC 0x0c0c7108 */
if(!s->budget--) { s->failed_pc=0x0c0c7108u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0c710a;
P_0c0c710a: /* original 2fb6, guest PC 0x0c0c710a */
if(!s->budget--) { s->failed_pc=0x0c0c710au; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0c710c;
P_0c0c710c: /* original 2fa6, guest PC 0x0c0c710c */
if(!s->budget--) { s->failed_pc=0x0c0c710cu; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0c710e;
P_0c0c710e: /* original 2f96, guest PC 0x0c0c710e */
if(!s->budget--) { s->failed_pc=0x0c0c710eu; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0c7110;
P_0c0c7110: /* original e90f, guest PC 0x0c0c7110 */
if(!s->budget--) { s->failed_pc=0x0c0c7110u; return 0; }
r[9]=0x0000000fu;
goto P_0c0c7112;
P_0c0c7112: /* original 2f86, guest PC 0x0c0c7112 */
if(!s->budget--) { s->failed_pc=0x0c0c7112u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0c7114;
P_0c0c7114: /* original 4f22, guest PC 0x0c0c7114 */
if(!s->budget--) { s->failed_pc=0x0c0c7114u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7116;
P_0c0c7116: /* original 906a, guest PC 0x0c0c7116 */
if(!s->budget--) { s->failed_pc=0x0c0c7116u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71eeu,2);
goto P_0c0c7118;
P_0c0c7118: /* original db38, guest PC 0x0c0c7118 */
if(!s->budget--) { s->failed_pc=0x0c0c7118u; return 0; }
r[11]=read(ram,0x0c0c71fcu,4);
goto P_0c0c711a;
P_0c0c711a: /* original 4f12, guest PC 0x0c0c711a */
if(!s->budget--) { s->failed_pc=0x0c0c711au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c711c;
P_0c0c711c: /* original d338, guest PC 0x0c0c711c */
if(!s->budget--) { s->failed_pc=0x0c0c711cu; return 0; }
r[3]=read(ram,0x0c0c7200u,4);
goto P_0c0c711e;
P_0c0c711e: /* original 3f0c, guest PC 0x0c0c711e */
if(!s->budget--) { s->failed_pc=0x0c0c711eu; return 0; }
r[15]+=r[0];
goto P_0c0c7120;
P_0c0c7120: /* original e01c, guest PC 0x0c0c7120 */
if(!s->budget--) { s->failed_pc=0x0c0c7120u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7122;
P_0c0c7122: /* original 00bc, guest PC 0x0c0c7122 */
if(!s->budget--) { s->failed_pc=0x0c0c7122u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c7124;
P_0c0c7124: /* original 600c, guest PC 0x0c0c7124 */
if(!s->budget--) { s->failed_pc=0x0c0c7124u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c7126;
P_0c0c7126: /* original 2909, guest PC 0x0c0c7126 */
if(!s->budget--) { s->failed_pc=0x0c0c7126u; return 0; }
r[9]&=r[0];
goto P_0c0c7128;
P_0c0c7128: /* original 6030, guest PC 0x0c0c7128 */
if(!s->budget--) { s->failed_pc=0x0c0c7128u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0c712a;
P_0c0c712a: /* original 600c, guest PC 0x0c0c712a */
if(!s->budget--) { s->failed_pc=0x0c0c712au; return 0; }
r[0]=r[0]&255u;
goto P_0c0c712c;
P_0c0c712c: /* original 8804, guest PC 0x0c0c712c */
if(!s->budget--) { s->failed_pc=0x0c0c712cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0c712e;
P_0c0c712e: /* original 8b01, guest PC 0x0c0c712e */
if(!s->budget--) { s->failed_pc=0x0c0c712eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7134; }
goto P_0c0c7130;
P_0c0c7130: /* original a0b4, guest PC 0x0c0c7130 */
if(!s->budget--) { s->failed_pc=0x0c0c7130u; return 0; }
goto P_0c0c729c;
P_0c0c7132: /* original 0009, guest PC 0x0c0c7132 */
if(!s->budget--) { s->failed_pc=0x0c0c7132u; return 0; }
goto P_0c0c7134;
P_0c0c7134: /* original 6242, guest PC 0x0c0c7134 */
if(!s->budget--) { s->failed_pc=0x0c0c7134u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0c7136;
P_0c0c7136: /* original 935b, guest PC 0x0c0c7136 */
if(!s->budget--) { s->failed_pc=0x0c0c7136u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71f0u,2);
goto P_0c0c7138;
P_0c0c7138: /* original 2238, guest PC 0x0c0c7138 */
if(!s->budget--) { s->failed_pc=0x0c0c7138u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c713a;
P_0c0c713a: /* original 8901, guest PC 0x0c0c713a */
if(!s->budget--) { s->failed_pc=0x0c0c713au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7140; }
goto P_0c0c713c;
P_0c0c713c: /* original a0ae, guest PC 0x0c0c713c */
if(!s->budget--) { s->failed_pc=0x0c0c713cu; return 0; }
goto P_0c0c729c;
P_0c0c713e: /* original 0009, guest PC 0x0c0c713e */
if(!s->budget--) { s->failed_pc=0x0c0c713eu; return 0; }
goto P_0c0c7140;
P_0c0c7140: /* original 9057, guest PC 0x0c0c7140 */
if(!s->budget--) { s->failed_pc=0x0c0c7140u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71f2u,2);
goto P_0c0c7142;
P_0c0c7142: /* original ec00, guest PC 0x0c0c7142 */
if(!s->budget--) { s->failed_pc=0x0c0c7142u; return 0; }
r[12]=0x00000000u;
goto P_0c0c7144;
P_0c0c7144: /* original 004c, guest PC 0x0c0c7144 */
if(!s->budget--) { s->failed_pc=0x0c0c7144u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7146;
P_0c0c7146: /* original 8817, guest PC 0x0c0c7146 */
if(!s->budget--) { s->failed_pc=0x0c0c7146u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000017u)!=0);
goto P_0c0c7148;
P_0c0c7148: /* original 8d08, guest PC 0x0c0c7148 */
if(!s->budget--) { s->failed_pc=0x0c0c7148u; return 0; }
cond=r[17]&1u;
r[8]=0x00000020u;
if(cond) { goto P_0c0c715c; }
goto P_0c0c714c;
P_0c0c714a: /* original e820, guest PC 0x0c0c714a */
if(!s->budget--) { s->failed_pc=0x0c0c714au; return 0; }
r[8]=0x00000020u;
goto P_0c0c714c;
P_0c0c714c: /* original 9051, guest PC 0x0c0c714c */
if(!s->budget--) { s->failed_pc=0x0c0c714cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71f2u,2);
goto P_0c0c714e;
P_0c0c714e: /* original 004c, guest PC 0x0c0c714e */
if(!s->budget--) { s->failed_pc=0x0c0c714eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7150;
P_0c0c7150: /* original 8807, guest PC 0x0c0c7150 */
if(!s->budget--) { s->failed_pc=0x0c0c7150u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0c7152;
P_0c0c7152: /* original 8903, guest PC 0x0c0c7152 */
if(!s->budget--) { s->failed_pc=0x0c0c7152u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c715c; }
goto P_0c0c7154;
P_0c0c7154: /* original 904e, guest PC 0x0c0c7154 */
if(!s->budget--) { s->failed_pc=0x0c0c7154u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71f4u,2);
goto P_0c0c7156;
P_0c0c7156: /* original 034c, guest PC 0x0c0c7156 */
if(!s->budget--) { s->failed_pc=0x0c0c7156u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7158;
P_0c0c7158: /* original 3387, guest PC 0x0c0c7158 */
if(!s->budget--) { s->failed_pc=0x0c0c7158u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[8])!=0);
goto P_0c0c715a;
P_0c0c715a: /* original 8903, guest PC 0x0c0c715a */
if(!s->budget--) { s->failed_pc=0x0c0c715au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7164; }
goto P_0c0c715c;
P_0c0c715c: /* original 904b, guest PC 0x0c0c715c */
if(!s->budget--) { s->failed_pc=0x0c0c715cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71f6u,2);
goto P_0c0c715e;
P_0c0c715e: /* original 004c, guest PC 0x0c0c715e */
if(!s->budget--) { s->failed_pc=0x0c0c715eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7160;
P_0c0c7160: /* original 8803, guest PC 0x0c0c7160 */
if(!s->budget--) { s->failed_pc=0x0c0c7160u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c7162;
P_0c0c7162: /* original 8b0a, guest PC 0x0c0c7162 */
if(!s->budget--) { s->failed_pc=0x0c0c7162u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c717a; }
goto P_0c0c7164;
P_0c0c7164: /* original 6093, guest PC 0x0c0c7164 */
if(!s->budget--) { s->failed_pc=0x0c0c7164u; return 0; }
r[0]=r[9];
goto P_0c0c7166;
P_0c0c7166: /* original 8802, guest PC 0x0c0c7166 */
if(!s->budget--) { s->failed_pc=0x0c0c7166u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c7168;
P_0c0c7168: /* original 8d06, guest PC 0x0c0c7168 */
if(!s->budget--) { s->failed_pc=0x0c0c7168u; return 0; }
cond=r[17]&1u;
r[4]=0x00000009u;
if(cond) { goto P_0c0c7178; }
goto P_0c0c716c;
P_0c0c716a: /* original e409, guest PC 0x0c0c716a */
if(!s->budget--) { s->failed_pc=0x0c0c716au; return 0; }
r[4]=0x00000009u;
goto P_0c0c716c;
P_0c0c716c: /* original 8807, guest PC 0x0c0c716c */
if(!s->budget--) { s->failed_pc=0x0c0c716cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0c716e;
P_0c0c716e: /* original 8901, guest PC 0x0c0c716e */
if(!s->budget--) { s->failed_pc=0x0c0c716eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7174; }
goto P_0c0c7170;
P_0c0c7170: /* original 880e, guest PC 0x0c0c7170 */
if(!s->budget--) { s->failed_pc=0x0c0c7170u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c0c7172;
P_0c0c7172: /* original 8b02, guest PC 0x0c0c7172 */
if(!s->budget--) { s->failed_pc=0x0c0c7172u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c717a; }
goto P_0c0c7174;
P_0c0c7174: /* original a001, guest PC 0x0c0c7174 */
if(!s->budget--) { s->failed_pc=0x0c0c7174u; return 0; }
r[12]=r[4];
goto P_0c0c717a;
P_0c0c7176: /* original 6c43, guest PC 0x0c0c7176 */
if(!s->budget--) { s->failed_pc=0x0c0c7176u; return 0; }
r[12]=r[4];
goto P_0c0c7178;
P_0c0c7178: /* original ec01, guest PC 0x0c0c7178 */
if(!s->budget--) { s->failed_pc=0x0c0c7178u; return 0; }
r[12]=0x00000001u;
goto P_0c0c717a;
P_0c0c717a: /* original d322, guest PC 0x0c0c717a */
if(!s->budget--) { s->failed_pc=0x0c0c717au; return 0; }
r[3]=read(ram,0x0c0c7204u,4);
goto P_0c0c717c;
P_0c0c717c: /* original 430b, guest PC 0x0c0c717c */
if(!s->budget--) { s->failed_pc=0x0c0c717cu; return 0; }
target=r[3];
r[16]=0x0c0c7180u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7180u) { target=s->pc; goto dispatch; }
goto P_0c0c7180;
P_0c0c717e: /* original e400, guest PC 0x0c0c717e */
if(!s->budget--) { s->failed_pc=0x0c0c717eu; return 0; }
r[4]=0x00000000u;
goto P_0c0c7180;
P_0c0c7180: /* original d221, guest PC 0x0c0c7180 */
if(!s->budget--) { s->failed_pc=0x0c0c7180u; return 0; }
r[2]=read(ram,0x0c0c7208u,4);
goto P_0c0c7182;
P_0c0c7182: /* original 420b, guest PC 0x0c0c7182 */
if(!s->budget--) { s->failed_pc=0x0c0c7182u; return 0; }
target=r[2];
r[16]=0x0c0c7186u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7186u) { target=s->pc; goto dispatch; }
goto P_0c0c7186;
P_0c0c7184: /* original 0009, guest PC 0x0c0c7184 */
if(!s->budget--) { s->failed_pc=0x0c0c7184u; return 0; }
goto P_0c0c7186;
P_0c0c7186: /* original 6093, guest PC 0x0c0c7186 */
if(!s->budget--) { s->failed_pc=0x0c0c7186u; return 0; }
r[0]=r[9];
goto P_0c0c7188;
P_0c0c7188: /* original d120, guest PC 0x0c0c7188 */
if(!s->budget--) { s->failed_pc=0x0c0c7188u; return 0; }
r[1]=read(ram,0x0c0c720cu,4);
goto P_0c0c718a;
P_0c0c718a: /* original 4008, guest PC 0x0c0c718a */
if(!s->budget--) { s->failed_pc=0x0c0c718au; return 0; }
r[0]<<=2;
goto P_0c0c718c;
P_0c0c718c: /* original 4000, guest PC 0x0c0c718c */
if(!s->budget--) { s->failed_pc=0x0c0c718cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c718e;
P_0c0c718e: /* original 001e, guest PC 0x0c0c718e */
if(!s->budget--) { s->failed_pc=0x0c0c718eu; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c0c7190;
P_0c0c7190: /* original 88ff, guest PC 0x0c0c7190 */
if(!s->budget--) { s->failed_pc=0x0c0c7190u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c7192;
P_0c0c7192: /* original 8975, guest PC 0x0c0c7192 */
if(!s->budget--) { s->failed_pc=0x0c0c7192u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7280; }
goto P_0c0c7194;
P_0c0c7194: /* original d21e, guest PC 0x0c0c7194 */
if(!s->budget--) { s->failed_pc=0x0c0c7194u; return 0; }
r[2]=read(ram,0x0c0c7210u,4);
goto P_0c0c7196;
P_0c0c7196: /* original 6a22, guest PC 0x0c0c7196 */
if(!s->budget--) { s->failed_pc=0x0c0c7196u; return 0; }
tmp=read(ram,r[2],4);
r[10]=tmp;
goto P_0c0c7198;
P_0c0c7198: /* original 2aa8, guest PC 0x0c0c7198 */
if(!s->budget--) { s->failed_pc=0x0c0c7198u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0c719a;
P_0c0c719a: /* original 8971, guest PC 0x0c0c719a */
if(!s->budget--) { s->failed_pc=0x0c0c719au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7280; }
goto P_0c0c719c;
P_0c0c719c: /* original 6093, guest PC 0x0c0c719c */
if(!s->budget--) { s->failed_pc=0x0c0c719cu; return 0; }
r[0]=r[9];
goto P_0c0c719e;
P_0c0c719e: /* original de1d, guest PC 0x0c0c719e */
if(!s->budget--) { s->failed_pc=0x0c0c719eu; return 0; }
r[14]=read(ram,0x0c0c7214u,4);
goto P_0c0c71a0;
P_0c0c71a0: /* original 9d2a, guest PC 0x0c0c71a0 */
if(!s->budget--) { s->failed_pc=0x0c0c71a0u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71f8u,2);
goto P_0c0c71a2;
P_0c0c71a2: /* original 8801, guest PC 0x0c0c71a2 */
if(!s->budget--) { s->failed_pc=0x0c0c71a2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c71a4;
P_0c0c71a4: /* original 893a, guest PC 0x0c0c71a4 */
if(!s->budget--) { s->failed_pc=0x0c0c71a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c721c; }
goto P_0c0c71a6;
P_0c0c71a6: /* original d01c, guest PC 0x0c0c71a6 */
if(!s->budget--) { s->failed_pc=0x0c0c71a6u; return 0; }
r[0]=read(ram,0x0c0c7218u,4);
goto P_0c0c71a8;
P_0c0c71a8: /* original 6302, guest PC 0x0c0c71a8 */
if(!s->budget--) { s->failed_pc=0x0c0c71a8u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c0c71aa;
P_0c0c71aa: /* original 2838, guest PC 0x0c0c71aa */
if(!s->budget--) { s->failed_pc=0x0c0c71aau; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c0c71ac;
P_0c0c71ac: /* original 8b04, guest PC 0x0c0c71ac */
if(!s->budget--) { s->failed_pc=0x0c0c71acu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c71b8; }
goto P_0c0c71ae;
P_0c0c71ae: /* original e01c, guest PC 0x0c0c71ae */
if(!s->budget--) { s->failed_pc=0x0c0c71aeu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c71b0;
P_0c0c71b0: /* original 00bc, guest PC 0x0c0c71b0 */
if(!s->budget--) { s->failed_pc=0x0c0c71b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c71b2;
P_0c0c71b2: /* original 600c, guest PC 0x0c0c71b2 */
if(!s->budget--) { s->failed_pc=0x0c0c71b2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c71b4;
P_0c0c71b4: /* original 881f, guest PC 0x0c0c71b4 */
if(!s->budget--) { s->failed_pc=0x0c0c71b4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001fu)!=0);
goto P_0c0c71b6;
P_0c0c71b6: /* original 8b0b, guest PC 0x0c0c71b6 */
if(!s->budget--) { s->failed_pc=0x0c0c71b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c71d0; }
goto P_0c0c71b8;
P_0c0c71b8: /* original 4e0b, guest PC 0x0c0c71b8 */
if(!s->budget--) { s->failed_pc=0x0c0c71b8u; return 0; }
target=r[14];
r[16]=0x0c0c71bcu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c71bcu) { target=s->pc; goto dispatch; }
goto P_0c0c71bc;
P_0c0c71ba: /* original 64d3, guest PC 0x0c0c71ba */
if(!s->budget--) { s->failed_pc=0x0c0c71bau; return 0; }
r[4]=r[13];
goto P_0c0c71bc;
P_0c0c71bc: /* original e01c, guest PC 0x0c0c71bc */
if(!s->budget--) { s->failed_pc=0x0c0c71bcu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c71be;
P_0c0c71be: /* original 00bc, guest PC 0x0c0c71be */
if(!s->budget--) { s->failed_pc=0x0c0c71beu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c71c0;
P_0c0c71c0: /* original 600c, guest PC 0x0c0c71c0 */
if(!s->budget--) { s->failed_pc=0x0c0c71c0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c71c2;
P_0c0c71c2: /* original 881f, guest PC 0x0c0c71c2 */
if(!s->budget--) { s->failed_pc=0x0c0c71c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001fu)!=0);
goto P_0c0c71c4;
P_0c0c71c4: /* original 8b5c, guest PC 0x0c0c71c4 */
if(!s->budget--) { s->failed_pc=0x0c0c71c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7280; }
goto P_0c0c71c6;
P_0c0c71c6: /* original 9418, guest PC 0x0c0c71c6 */
if(!s->budget--) { s->failed_pc=0x0c0c71c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71fau,2);
goto P_0c0c71c8;
P_0c0c71c8: /* original 4e0b, guest PC 0x0c0c71c8 */
if(!s->budget--) { s->failed_pc=0x0c0c71c8u; return 0; }
target=r[14];
r[16]=0x0c0c71ccu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c71ccu) { target=s->pc; goto dispatch; }
goto P_0c0c71cc;
P_0c0c71ca: /* original 0009, guest PC 0x0c0c71ca */
if(!s->budget--) { s->failed_pc=0x0c0c71cau; return 0; }
goto P_0c0c71cc;
P_0c0c71cc: /* original a058, guest PC 0x0c0c71cc */
if(!s->budget--) { s->failed_pc=0x0c0c71ccu; return 0; }
goto P_0c0c7280;
P_0c0c71ce: /* original 0009, guest PC 0x0c0c71ce */
if(!s->budget--) { s->failed_pc=0x0c0c71ceu; return 0; }
goto P_0c0c71d0;
P_0c0c71d0: /* original 85a6, guest PC 0x0c0c71d0 */
if(!s->budget--) { s->failed_pc=0x0c0c71d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+12,2);
goto P_0c0c71d2;
P_0c0c71d2: /* original 600d, guest PC 0x0c0c71d2 */
if(!s->budget--) { s->failed_pc=0x0c0c71d2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c71d4;
P_0c0c71d4: /* original 6303, guest PC 0x0c0c71d4 */
if(!s->budget--) { s->failed_pc=0x0c0c71d4u; return 0; }
r[3]=r[0];
goto P_0c0c71d6;
P_0c0c71d6: /* original 33c8, guest PC 0x0c0c71d6 */
if(!s->budget--) { s->failed_pc=0x0c0c71d6u; return 0; }
r[3]-=r[12];
goto P_0c0c71d8;
P_0c0c71d8: /* original 6c33, guest PC 0x0c0c71d8 */
if(!s->budget--) { s->failed_pc=0x0c0c71d8u; return 0; }
r[12]=r[3];
goto P_0c0c71da;
P_0c0c71da: /* original 4c15, guest PC 0x0c0c71da */
if(!s->budget--) { s->failed_pc=0x0c0c71dau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c0c71dc;
P_0c0c71dc: /* original 8b50, guest PC 0x0c0c71dc */
if(!s->budget--) { s->failed_pc=0x0c0c71dcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7280; }
goto P_0c0c71de;
P_0c0c71de: /* original 64d3, guest PC 0x0c0c71de */
if(!s->budget--) { s->failed_pc=0x0c0c71deu; return 0; }
r[4]=r[13];
goto P_0c0c71e0;
P_0c0c71e0: /* original 4e0b, guest PC 0x0c0c71e0 */
if(!s->budget--) { s->failed_pc=0x0c0c71e0u; return 0; }
target=r[14];
r[16]=0x0c0c71e4u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c71e4u) { target=s->pc; goto dispatch; }
goto P_0c0c71e4;
P_0c0c71e2: /* original 7d01, guest PC 0x0c0c71e2 */
if(!s->budget--) { s->failed_pc=0x0c0c71e2u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c71e4;
P_0c0c71e4: /* original 7cff, guest PC 0x0c0c71e4 */
if(!s->budget--) { s->failed_pc=0x0c0c71e4u; return 0; }
r[12]+=0xffffffffu;
goto P_0c0c71e6;
P_0c0c71e6: /* original 4c15, guest PC 0x0c0c71e6 */
if(!s->budget--) { s->failed_pc=0x0c0c71e6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c0c71e8;
P_0c0c71e8: /* original 89f9, guest PC 0x0c0c71e8 */
if(!s->budget--) { s->failed_pc=0x0c0c71e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c71de; }
goto P_0c0c71ea;
P_0c0c71ea: /* original a049, guest PC 0x0c0c71ea */
if(!s->budget--) { s->failed_pc=0x0c0c71eau; return 0; }
goto P_0c0c7280;
P_0c0c71ec: /* original 0009, guest PC 0x0c0c71ec */
if(!s->budget--) { s->failed_pc=0x0c0c71ecu; return 0; }
return vf3_matrix_family(0x0c0c71eeu,s,ram);
P_0c0c721c: /* original c726, guest PC 0x0c0c721c */
if(!s->budget--) { s->failed_pc=0x0c0c721cu; return 0; }
r[0]=0x0c0c72b8u;
goto P_0c0c721e;
P_0c0c721e: /* original d328, guest PC 0x0c0c721e */
if(!s->budget--) { s->failed_pc=0x0c0c721eu; return 0; }
r[3]=read(ram,0x0c0c72c0u,4);
goto P_0c0c7220;
P_0c0c7220: /* original f508, guest PC 0x0c0c7220 */
if(!s->budget--) { s->failed_pc=0x0c0c7220u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c7222;
P_0c0c7222: /* original e400, guest PC 0x0c0c7222 */
if(!s->budget--) { s->failed_pc=0x0c0c7222u; return 0; }
r[4]=0x00000000u;
goto P_0c0c7224;
P_0c0c7224: /* original c725, guest PC 0x0c0c7224 */
if(!s->budget--) { s->failed_pc=0x0c0c7224u; return 0; }
r[0]=0x0c0c72bcu;
goto P_0c0c7226;
P_0c0c7226: /* original 430b, guest PC 0x0c0c7226 */
if(!s->budget--) { s->failed_pc=0x0c0c7226u; return 0; }
target=r[3];
r[16]=0x0c0c722au;
vf3_matrix_load(s,ram,4,r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c722au) { target=s->pc; goto dispatch; }
goto P_0c0c722a;
P_0c0c7228: /* original f408, guest PC 0x0c0c7228 */
if(!s->budget--) { s->failed_pc=0x0c0c7228u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c722a;
P_0c0c722a: /* original 64d3, guest PC 0x0c0c722a */
if(!s->budget--) { s->failed_pc=0x0c0c722au; return 0; }
r[4]=r[13];
goto P_0c0c722c;
P_0c0c722c: /* original 4e0b, guest PC 0x0c0c722c */
if(!s->budget--) { s->failed_pc=0x0c0c722cu; return 0; }
target=r[14];
r[16]=0x0c0c7230u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7230u) { target=s->pc; goto dispatch; }
goto P_0c0c7230;
P_0c0c722e: /* original 7d01, guest PC 0x0c0c722e */
if(!s->budget--) { s->failed_pc=0x0c0c722eu; return 0; }
r[13]+=0x00000001u;
goto P_0c0c7230;
P_0c0c7230: /* original e334, guest PC 0x0c0c7230 */
if(!s->budget--) { s->failed_pc=0x0c0c7230u; return 0; }
r[3]=0x00000034u;
goto P_0c0c7232;
P_0c0c7232: /* original e01c, guest PC 0x0c0c7232 */
if(!s->budget--) { s->failed_pc=0x0c0c7232u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7234;
P_0c0c7234: /* original 02bc, guest PC 0x0c0c7234 */
if(!s->budget--) { s->failed_pc=0x0c0c7234u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c7236;
P_0c0c7236: /* original 2f20, guest PC 0x0c0c7236 */
if(!s->budget--) { s->failed_pc=0x0c0c7236u; return 0; }
write(ram,r[15],r[2],1);
goto P_0c0c7238;
P_0c0c7238: /* original 622c, guest PC 0x0c0c7238 */
if(!s->budget--) { s->failed_pc=0x0c0c7238u; return 0; }
r[2]=r[2]&255u;
goto P_0c0c723a;
P_0c0c723a: /* original 64f0, guest PC 0x0c0c723a */
if(!s->budget--) { s->failed_pc=0x0c0c723au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[4]=tmp;
goto P_0c0c723c;
P_0c0c723c: /* original 4208, guest PC 0x0c0c723c */
if(!s->budget--) { s->failed_pc=0x0c0c723cu; return 0; }
r[2]<<=2;
goto P_0c0c723e;
P_0c0c723e: /* original d022, guest PC 0x0c0c723e */
if(!s->budget--) { s->failed_pc=0x0c0c723eu; return 0; }
r[0]=read(ram,0x0c0c72c8u,4);
goto P_0c0c7240;
P_0c0c7240: /* original 4208, guest PC 0x0c0c7240 */
if(!s->budget--) { s->failed_pc=0x0c0c7240u; return 0; }
r[2]<<=2;
goto P_0c0c7242;
P_0c0c7242: /* original 644c, guest PC 0x0c0c7242 */
if(!s->budget--) { s->failed_pc=0x0c0c7242u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c7244;
P_0c0c7244: /* original db1f, guest PC 0x0c0c7244 */
if(!s->budget--) { s->failed_pc=0x0c0c7244u; return 0; }
r[11]=read(ram,0x0c0c72c4u,4);
goto P_0c0c7246;
P_0c0c7246: /* original 243f, guest PC 0x0c0c7246 */
if(!s->budget--) { s->failed_pc=0x0c0c7246u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c0c7248;
P_0c0c7248: /* original 4208, guest PC 0x0c0c7248 */
if(!s->budget--) { s->failed_pc=0x0c0c7248u; return 0; }
r[2]<<=2;
goto P_0c0c724a;
P_0c0c724a: /* original 3b2c, guest PC 0x0c0c724a */
if(!s->budget--) { s->failed_pc=0x0c0c724au; return 0; }
r[11]+=r[2];
goto P_0c0c724c;
P_0c0c724c: /* original d21c, guest PC 0x0c0c724c */
if(!s->budget--) { s->failed_pc=0x0c0c724cu; return 0; }
r[2]=read(ram,0x0c0c72c0u,4);
goto P_0c0c724e;
P_0c0c724e: /* original 041a, guest PC 0x0c0c724e */
if(!s->budget--) { s->failed_pc=0x0c0c724eu; return 0; }
r[4]=r[19];
goto P_0c0c7250;
P_0c0c7250: /* original 644f, guest PC 0x0c0c7250 */
if(!s->budget--) { s->failed_pc=0x0c0c7250u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0c7252;
P_0c0c7252: /* original 044c, guest PC 0x0c0c7252 */
if(!s->budget--) { s->failed_pc=0x0c0c7252u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7254;
P_0c0c7254: /* original e010, guest PC 0x0c0c7254 */
if(!s->budget--) { s->failed_pc=0x0c0c7254u; return 0; }
r[0]=0x00000010u;
goto P_0c0c7256;
P_0c0c7256: /* original f5b6, guest PC 0x0c0c7256 */
if(!s->budget--) { s->failed_pc=0x0c0c7256u; return 0; }
vf3_matrix_load(s,ram,5,r[11]+r[0]);
goto P_0c0c7258;
P_0c0c7258: /* original e014, guest PC 0x0c0c7258 */
if(!s->budget--) { s->failed_pc=0x0c0c7258u; return 0; }
r[0]=0x00000014u;
goto P_0c0c725a;
P_0c0c725a: /* original 420b, guest PC 0x0c0c725a */
if(!s->budget--) { s->failed_pc=0x0c0c725au; return 0; }
target=r[2];
r[16]=0x0c0c725eu;
vf3_matrix_load(s,ram,4,r[11]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c725eu) { target=s->pc; goto dispatch; }
goto P_0c0c725e;
P_0c0c725c: /* original f4b6, guest PC 0x0c0c725c */
if(!s->budget--) { s->failed_pc=0x0c0c725cu; return 0; }
vf3_matrix_load(s,ram,4,r[11]+r[0]);
goto P_0c0c725e;
P_0c0c725e: /* original d21b, guest PC 0x0c0c725e */
if(!s->budget--) { s->failed_pc=0x0c0c725eu; return 0; }
r[2]=read(ram,0x0c0c72ccu,4);
goto P_0c0c7260;
P_0c0c7260: /* original 6322, guest PC 0x0c0c7260 */
if(!s->budget--) { s->failed_pc=0x0c0c7260u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0c7262;
P_0c0c7262: /* original 2838, guest PC 0x0c0c7262 */
if(!s->budget--) { s->failed_pc=0x0c0c7262u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c0c7264;
P_0c0c7264: /* original 8b0c, guest PC 0x0c0c7264 */
if(!s->budget--) { s->failed_pc=0x0c0c7264u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7280; }
goto P_0c0c7266;
P_0c0c7266: /* original 85a6, guest PC 0x0c0c7266 */
if(!s->budget--) { s->failed_pc=0x0c0c7266u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+12,2);
goto P_0c0c7268;
P_0c0c7268: /* original 600d, guest PC 0x0c0c7268 */
if(!s->budget--) { s->failed_pc=0x0c0c7268u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c726a;
P_0c0c726a: /* original 30c8, guest PC 0x0c0c726a */
if(!s->budget--) { s->failed_pc=0x0c0c726au; return 0; }
r[0]-=r[12];
goto P_0c0c726c;
P_0c0c726c: /* original 6c03, guest PC 0x0c0c726c */
if(!s->budget--) { s->failed_pc=0x0c0c726cu; return 0; }
r[12]=r[0];
goto P_0c0c726e;
P_0c0c726e: /* original 7cff, guest PC 0x0c0c726e */
if(!s->budget--) { s->failed_pc=0x0c0c726eu; return 0; }
r[12]+=0xffffffffu;
goto P_0c0c7270;
P_0c0c7270: /* original 4c15, guest PC 0x0c0c7270 */
if(!s->budget--) { s->failed_pc=0x0c0c7270u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c0c7272;
P_0c0c7272: /* original 8b05, guest PC 0x0c0c7272 */
if(!s->budget--) { s->failed_pc=0x0c0c7272u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7280; }
goto P_0c0c7274;
P_0c0c7274: /* original 64d3, guest PC 0x0c0c7274 */
if(!s->budget--) { s->failed_pc=0x0c0c7274u; return 0; }
r[4]=r[13];
goto P_0c0c7276;
P_0c0c7276: /* original 4e0b, guest PC 0x0c0c7276 */
if(!s->budget--) { s->failed_pc=0x0c0c7276u; return 0; }
target=r[14];
r[16]=0x0c0c727au;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c727au) { target=s->pc; goto dispatch; }
goto P_0c0c727a;
P_0c0c7278: /* original 7d01, guest PC 0x0c0c7278 */
if(!s->budget--) { s->failed_pc=0x0c0c7278u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c727a;
P_0c0c727a: /* original 7cff, guest PC 0x0c0c727a */
if(!s->budget--) { s->failed_pc=0x0c0c727au; return 0; }
r[12]+=0xffffffffu;
goto P_0c0c727c;
P_0c0c727c: /* original 4c15, guest PC 0x0c0c727c */
if(!s->budget--) { s->failed_pc=0x0c0c727cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c0c727e;
P_0c0c727e: /* original 89f9, guest PC 0x0c0c727e */
if(!s->budget--) { s->failed_pc=0x0c0c727eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7274; }
goto P_0c0c7280;
P_0c0c7280: /* original 9118, guest PC 0x0c0c7280 */
if(!s->budget--) { s->failed_pc=0x0c0c7280u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c72b4u,2);
goto P_0c0c7282;
P_0c0c7282: /* original e401, guest PC 0x0c0c7282 */
if(!s->budget--) { s->failed_pc=0x0c0c7282u; return 0; }
r[4]=0x00000001u;
goto P_0c0c7284;
P_0c0c7284: /* original d312, guest PC 0x0c0c7284 */
if(!s->budget--) { s->failed_pc=0x0c0c7284u; return 0; }
r[3]=read(ram,0x0c0c72d0u,4);
goto P_0c0c7286;
P_0c0c7286: /* original 3f1c, guest PC 0x0c0c7286 */
if(!s->budget--) { s->failed_pc=0x0c0c7286u; return 0; }
r[15]+=r[1];
goto P_0c0c7288;
P_0c0c7288: /* original 4f16, guest PC 0x0c0c7288 */
if(!s->budget--) { s->failed_pc=0x0c0c7288u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c728a;
P_0c0c728a: /* original 4f26, guest PC 0x0c0c728a */
if(!s->budget--) { s->failed_pc=0x0c0c728au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c728c;
P_0c0c728c: /* original 68f6, guest PC 0x0c0c728c */
if(!s->budget--) { s->failed_pc=0x0c0c728cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c728e;
P_0c0c728e: /* original 69f6, guest PC 0x0c0c728e */
if(!s->budget--) { s->failed_pc=0x0c0c728eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c7290;
P_0c0c7290: /* original 6af6, guest PC 0x0c0c7290 */
if(!s->budget--) { s->failed_pc=0x0c0c7290u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c7292;
P_0c0c7292: /* original 6bf6, guest PC 0x0c0c7292 */
if(!s->budget--) { s->failed_pc=0x0c0c7292u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7294;
P_0c0c7294: /* original 6cf6, guest PC 0x0c0c7294 */
if(!s->budget--) { s->failed_pc=0x0c0c7294u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7296;
P_0c0c7296: /* original 6df6, guest PC 0x0c0c7296 */
if(!s->budget--) { s->failed_pc=0x0c0c7296u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c7298;
P_0c0c7298: /* original 432b, guest PC 0x0c0c7298 */
if(!s->budget--) { s->failed_pc=0x0c0c7298u; return 0; }
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
P_0c0c729a: /* original 6ef6, guest PC 0x0c0c729a */
if(!s->budget--) { s->failed_pc=0x0c0c729au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c729c;
P_0c0c729c: /* original 910a, guest PC 0x0c0c729c */
if(!s->budget--) { s->failed_pc=0x0c0c729cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c72b4u,2);
goto P_0c0c729e;
P_0c0c729e: /* original 3f1c, guest PC 0x0c0c729e */
if(!s->budget--) { s->failed_pc=0x0c0c729eu; return 0; }
r[15]+=r[1];
goto P_0c0c72a0;
P_0c0c72a0: /* original 4f16, guest PC 0x0c0c72a0 */
if(!s->budget--) { s->failed_pc=0x0c0c72a0u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c72a2;
P_0c0c72a2: /* original 4f26, guest PC 0x0c0c72a2 */
if(!s->budget--) { s->failed_pc=0x0c0c72a2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c72a4;
P_0c0c72a4: /* original 68f6, guest PC 0x0c0c72a4 */
if(!s->budget--) { s->failed_pc=0x0c0c72a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c72a6;
P_0c0c72a6: /* original 69f6, guest PC 0x0c0c72a6 */
if(!s->budget--) { s->failed_pc=0x0c0c72a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c72a8;
P_0c0c72a8: /* original 6af6, guest PC 0x0c0c72a8 */
if(!s->budget--) { s->failed_pc=0x0c0c72a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c72aa;
P_0c0c72aa: /* original 6bf6, guest PC 0x0c0c72aa */
if(!s->budget--) { s->failed_pc=0x0c0c72aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c72ac;
P_0c0c72ac: /* original 6cf6, guest PC 0x0c0c72ac */
if(!s->budget--) { s->failed_pc=0x0c0c72acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c72ae;
P_0c0c72ae: /* original 6df6, guest PC 0x0c0c72ae */
if(!s->budget--) { s->failed_pc=0x0c0c72aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c72b0;
P_0c0c72b0: /* original 000b, guest PC 0x0c0c72b0 */
if(!s->budget--) { s->failed_pc=0x0c0c72b0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c72b2: /* original 6ef6, guest PC 0x0c0c72b2 */
if(!s->budget--) { s->failed_pc=0x0c0c72b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c72b4u,s,ram);
P_0c0c7e00: /* original 7ff8, guest PC 0x0c0c7e00 */
if(!s->budget--) { s->failed_pc=0x0c0c7e00u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c7e02;
P_0c0c7e02: /* original 2f42, guest PC 0x0c0c7e02 */
if(!s->budget--) { s->failed_pc=0x0c0c7e02u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c7e04;
P_0c0c7e04: /* original 1f51, guest PC 0x0c0c7e04 */
if(!s->budget--) { s->failed_pc=0x0c0c7e04u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0c7e06;
P_0c0c7e06: /* original 63f2, guest PC 0x0c0c7e06 */
if(!s->budget--) { s->failed_pc=0x0c0c7e06u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c7e08;
P_0c0c7e08: /* original d544, guest PC 0x0c0c7e08 */
if(!s->budget--) { s->failed_pc=0x0c0c7e08u; return 0; }
r[5]=read(ram,0x0c0c7f1cu,4);
goto P_0c0c7e0a;
P_0c0c7e0a: /* original 2338, guest PC 0x0c0c7e0a */
if(!s->budget--) { s->failed_pc=0x0c0c7e0au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c7e0c;
P_0c0c7e0c: /* original 8b01, guest PC 0x0c0c7e0c */
if(!s->budget--) { s->failed_pc=0x0c0c7e0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7e12; }
goto P_0c0c7e0e;
P_0c0c7e0e: /* original a001, guest PC 0x0c0c7e0e */
if(!s->budget--) { s->failed_pc=0x0c0c7e0eu; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c0c7e14;
P_0c0c7e10: /* original 5454, guest PC 0x0c0c7e10 */
if(!s->budget--) { s->failed_pc=0x0c0c7e10u; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c0c7e12;
P_0c0c7e12: /* original 5455, guest PC 0x0c0c7e12 */
if(!s->budget--) { s->failed_pc=0x0c0c7e12u; return 0; }
r[4]=read(ram,r[5]+20,4);
goto P_0c0c7e14;
P_0c0c7e14: /* original 65f2, guest PC 0x0c0c7e14 */
if(!s->budget--) { s->failed_pc=0x0c0c7e14u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0c7e16;
P_0c0c7e16: /* original 56f1, guest PC 0x0c0c7e16 */
if(!s->budget--) { s->failed_pc=0x0c0c7e16u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c0c7e18;
P_0c0c7e18: /* original a000, guest PC 0x0c0c7e18 */
if(!s->budget--) { s->failed_pc=0x0c0c7e18u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c7e1c;
P_0c0c7e1a: /* original 7f08, guest PC 0x0c0c7e1a */
if(!s->budget--) { s->failed_pc=0x0c0c7e1au; return 0; }
r[15]+=0x00000008u;
goto P_0c0c7e1c;
P_0c0c7e1c: /* original 2fe6, guest PC 0x0c0c7e1c */
if(!s->budget--) { s->failed_pc=0x0c0c7e1cu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c7e1e;
P_0c0c7e1e: /* original e00c, guest PC 0x0c0c7e1e */
if(!s->budget--) { s->failed_pc=0x0c0c7e1eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c7e20;
P_0c0c7e20: /* original 2fd6, guest PC 0x0c0c7e20 */
if(!s->budget--) { s->failed_pc=0x0c0c7e20u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0c7e22;
P_0c0c7e22: /* original 6d53, guest PC 0x0c0c7e22 */
if(!s->budget--) { s->failed_pc=0x0c0c7e22u; return 0; }
r[13]=r[5];
goto P_0c0c7e24;
P_0c0c7e24: /* original 2fc6, guest PC 0x0c0c7e24 */
if(!s->budget--) { s->failed_pc=0x0c0c7e24u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0c7e26;
P_0c0c7e26: /* original 2fb6, guest PC 0x0c0c7e26 */
if(!s->budget--) { s->failed_pc=0x0c0c7e26u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0c7e28;
P_0c0c7e28: /* original fffb, guest PC 0x0c0c7e28 */
if(!s->budget--) { s->failed_pc=0x0c0c7e28u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
return vf3_matrix_family(0x0c0c7e2au,s,ram);
P_0c0c86da: /* original 2fe6, guest PC 0x0c0c86da */
if(!s->budget--) { s->failed_pc=0x0c0c86dau; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c86dc;
P_0c0c86dc: /* original e044, guest PC 0x0c0c86dc */
if(!s->budget--) { s->failed_pc=0x0c0c86dcu; return 0; }
r[0]=0x00000044u;
goto P_0c0c86de;
P_0c0c86de: /* original 2fd6, guest PC 0x0c0c86de */
if(!s->budget--) { s->failed_pc=0x0c0c86deu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0c86e0;
P_0c0c86e0: /* original 6e43, guest PC 0x0c0c86e0 */
if(!s->budget--) { s->failed_pc=0x0c0c86e0u; return 0; }
r[14]=r[4];
goto P_0c0c86e2;
P_0c0c86e2: /* original 2fc6, guest PC 0x0c0c86e2 */
if(!s->budget--) { s->failed_pc=0x0c0c86e2u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0c86e4;
P_0c0c86e4: /* original e302, guest PC 0x0c0c86e4 */
if(!s->budget--) { s->failed_pc=0x0c0c86e4u; return 0; }
r[3]=0x00000002u;
goto P_0c0c86e6;
P_0c0c86e6: /* original fffb, guest PC 0x0c0c86e6 */
if(!s->budget--) { s->failed_pc=0x0c0c86e6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c86e8;
P_0c0c86e8: /* original ffeb, guest PC 0x0c0c86e8 */
if(!s->budget--) { s->failed_pc=0x0c0c86e8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0c86ea;
P_0c0c86ea: /* original ffdb, guest PC 0x0c0c86ea */
if(!s->budget--) { s->failed_pc=0x0c0c86eau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0c86ec;
P_0c0c86ec: /* original ffcb, guest PC 0x0c0c86ec */
if(!s->budget--) { s->failed_pc=0x0c0c86ecu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
return vf3_matrix_family(0x0c0c86eeu,s,ram);
P_0c0c8be6: /* original 4f22, guest PC 0x0c0c8be6 */
if(!s->budget--) { s->failed_pc=0x0c0c8be6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c8be8;
P_0c0c8be8: /* original 6212, guest PC 0x0c0c8be8 */
if(!s->budget--) { s->failed_pc=0x0c0c8be8u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0c8bea;
P_0c0c8bea: /* original d33b, guest PC 0x0c0c8bea */
if(!s->budget--) { s->failed_pc=0x0c0c8beau; return 0; }
r[3]=read(ram,0x0c0c8cd8u,4);
goto P_0c0c8bec;
P_0c0c8bec: /* original d539, guest PC 0x0c0c8bec */
if(!s->budget--) { s->failed_pc=0x0c0c8becu; return 0; }
r[5]=read(ram,0x0c0c8cd4u,4);
goto P_0c0c8bee;
P_0c0c8bee: /* original 7ff0, guest PC 0x0c0c8bee */
if(!s->budget--) { s->failed_pc=0x0c0c8beeu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0c8bf0;
P_0c0c8bf0: /* original 2238, guest PC 0x0c0c8bf0 */
if(!s->budget--) { s->failed_pc=0x0c0c8bf0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c8bf2;
P_0c0c8bf2: /* original 8b2f, guest PC 0x0c0c8bf2 */
if(!s->budget--) { s->failed_pc=0x0c0c8bf2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8c54; }
goto P_0c0c8bf4;
P_0c0c8bf4: /* original 9069, guest PC 0x0c0c8bf4 */
if(!s->budget--) { s->failed_pc=0x0c0c8bf4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8ccau,2);
goto P_0c0c8bf6;
P_0c0c8bf6: /* original 004e, guest PC 0x0c0c8bf6 */
if(!s->budget--) { s->failed_pc=0x0c0c8bf6u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c0c8bf8;
P_0c0c8bf8: /* original 1f02, guest PC 0x0c0c8bf8 */
if(!s->budget--) { s->failed_pc=0x0c0c8bf8u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c0c8bfa;
P_0c0c8bfa: /* original 9067, guest PC 0x0c0c8bfa */
if(!s->budget--) { s->failed_pc=0x0c0c8bfau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8cccu,2);
goto P_0c0c8bfc;
P_0c0c8bfc: /* original 034e, guest PC 0x0c0c8bfc */
if(!s->budget--) { s->failed_pc=0x0c0c8bfcu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0c8bfe;
P_0c0c8bfe: /* original 1f33, guest PC 0x0c0c8bfe */
if(!s->budget--) { s->failed_pc=0x0c0c8bfeu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0c8c00;
P_0c0c8c00: /* original 9065, guest PC 0x0c0c8c00 */
if(!s->budget--) { s->failed_pc=0x0c0c8c00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8cceu,2);
goto P_0c0c8c02;
P_0c0c8c02: /* original 024c, guest PC 0x0c0c8c02 */
if(!s->budget--) { s->failed_pc=0x0c0c8c02u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c8c04;
P_0c0c8c04: /* original 2f22, guest PC 0x0c0c8c04 */
if(!s->budget--) { s->failed_pc=0x0c0c8c04u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c8c06;
P_0c0c8c06: /* original 6342, guest PC 0x0c0c8c06 */
if(!s->budget--) { s->failed_pc=0x0c0c8c06u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0c8c08;
P_0c0c8c08: /* original 1f31, guest PC 0x0c0c8c08 */
if(!s->budget--) { s->failed_pc=0x0c0c8c08u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c8c0a;
P_0c0c8c0a: /* original 5553, guest PC 0x0c0c8c0a */
if(!s->budget--) { s->failed_pc=0x0c0c8c0au; return 0; }
r[5]=read(ram,r[5]+12,4);
goto P_0c0c8c0c;
P_0c0c8c0c: /* original 655c, guest PC 0x0c0c8c0c */
if(!s->budget--) { s->failed_pc=0x0c0c8c0cu; return 0; }
r[5]=r[5]&255u;
goto P_0c0c8c0e;
P_0c0c8c0e: /* original 2558, guest PC 0x0c0c8c0e */
if(!s->budget--) { s->failed_pc=0x0c0c8c0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0c8c10;
P_0c0c8c10: /* original 8b17, guest PC 0x0c0c8c10 */
if(!s->budget--) { s->failed_pc=0x0c0c8c10u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8c42; }
goto P_0c0c8c12;
P_0c0c8c12: /* original 63f2, guest PC 0x0c0c8c12 */
if(!s->budget--) { s->failed_pc=0x0c0c8c12u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c8c14;
P_0c0c8c14: /* original 7301, guest PC 0x0c0c8c14 */
if(!s->budget--) { s->failed_pc=0x0c0c8c14u; return 0; }
r[3]+=0x00000001u;
goto P_0c0c8c16;
P_0c0c8c16: /* original 2f32, guest PC 0x0c0c8c16 */
if(!s->budget--) { s->failed_pc=0x0c0c8c16u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c8c18;
P_0c0c8c18: /* original e304, guest PC 0x0c0c8c18 */
if(!s->budget--) { s->failed_pc=0x0c0c8c18u; return 0; }
r[3]=0x00000004u;
goto P_0c0c8c1a;
P_0c0c8c1a: /* original d231, guest PC 0x0c0c8c1a */
if(!s->budget--) { s->failed_pc=0x0c0c8c1au; return 0; }
r[2]=read(ram,0x0c0c8ce0u,4);
goto P_0c0c8c1c;
P_0c0c8c1c: /* original 51f1, guest PC 0x0c0c8c1c */
if(!s->budget--) { s->failed_pc=0x0c0c8c1cu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0c8c1e;
P_0c0c8c1e: /* original 2129, guest PC 0x0c0c8c1e */
if(!s->budget--) { s->failed_pc=0x0c0c8c1eu; return 0; }
r[1]&=r[2];
goto P_0c0c8c20;
P_0c0c8c20: /* original 1f11, guest PC 0x0c0c8c20 */
if(!s->budget--) { s->failed_pc=0x0c0c8c20u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0c8c22;
P_0c0c8c22: /* original 60f2, guest PC 0x0c0c8c22 */
if(!s->budget--) { s->failed_pc=0x0c0c8c22u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0c8c24;
P_0c0c8c24: /* original 3033, guest PC 0x0c0c8c24 */
if(!s->budget--) { s->failed_pc=0x0c0c8c24u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[3])!=0);
goto P_0c0c8c26;
P_0c0c8c26: /* original 8b09, guest PC 0x0c0c8c26 */
if(!s->budget--) { s->failed_pc=0x0c0c8c26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8c3c; }
goto P_0c0c8c28;
P_0c0c8c28: /* original 9052, guest PC 0x0c0c8c28 */
if(!s->budget--) { s->failed_pc=0x0c0c8c28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8cd0u,2);
goto P_0c0c8c2a;
P_0c0c8c2a: /* original e102, guest PC 0x0c0c8c2a */
if(!s->budget--) { s->failed_pc=0x0c0c8c2au; return 0; }
r[1]=0x00000002u;
goto P_0c0c8c2c;
P_0c0c8c2c: /* original e300, guest PC 0x0c0c8c2c */
if(!s->budget--) { s->failed_pc=0x0c0c8c2cu; return 0; }
r[3]=0x00000000u;
goto P_0c0c8c2e;
P_0c0c8c2e: /* original 0414, guest PC 0x0c0c8c2e */
if(!s->budget--) { s->failed_pc=0x0c0c8c2eu; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c0c8c30;
P_0c0c8c30: /* original 904d, guest PC 0x0c0c8c30 */
if(!s->budget--) { s->failed_pc=0x0c0c8c30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8cceu,2);
goto P_0c0c8c32;
P_0c0c8c32: /* original 0434, guest PC 0x0c0c8c32 */
if(!s->budget--) { s->failed_pc=0x0c0c8c32u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c0c8c34;
P_0c0c8c34: /* original 62f2, guest PC 0x0c0c8c34 */
if(!s->budget--) { s->failed_pc=0x0c0c8c34u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c8c36;
P_0c0c8c36: /* original 72ff, guest PC 0x0c0c8c36 */
if(!s->budget--) { s->failed_pc=0x0c0c8c36u; return 0; }
r[2]+=0xffffffffu;
goto P_0c0c8c38;
P_0c0c8c38: /* original a003, guest PC 0x0c0c8c38 */
if(!s->budget--) { s->failed_pc=0x0c0c8c38u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c8c42;
P_0c0c8c3a: /* original 2f22, guest PC 0x0c0c8c3a */
if(!s->budget--) { s->failed_pc=0x0c0c8c3au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c8c3c;
P_0c0c8c3c: /* original 9047, guest PC 0x0c0c8c3c */
if(!s->budget--) { s->failed_pc=0x0c0c8c3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8cceu,2);
goto P_0c0c8c3e;
P_0c0c8c3e: /* original 61f2, guest PC 0x0c0c8c3e */
if(!s->budget--) { s->failed_pc=0x0c0c8c3eu; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0c8c40;
P_0c0c8c40: /* original 0414, guest PC 0x0c0c8c40 */
if(!s->budget--) { s->failed_pc=0x0c0c8c40u; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c0c8c42;
P_0c0c8c42: /* original 63f3, guest PC 0x0c0c8c42 */
if(!s->budget--) { s->failed_pc=0x0c0c8c42u; return 0; }
r[3]=r[15];
goto P_0c0c8c44;
P_0c0c8c44: /* original 7304, guest PC 0x0c0c8c44 */
if(!s->budget--) { s->failed_pc=0x0c0c8c44u; return 0; }
r[3]+=0x00000004u;
goto P_0c0c8c46;
P_0c0c8c46: /* original 2f36, guest PC 0x0c0c8c46 */
if(!s->budget--) { s->failed_pc=0x0c0c8c46u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0c8c48;
P_0c0c8c48: /* original 56f4, guest PC 0x0c0c8c48 */
if(!s->budget--) { s->failed_pc=0x0c0c8c48u; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c0c8c4a;
P_0c0c8c4a: /* original 67f3, guest PC 0x0c0c8c4a */
if(!s->budget--) { s->failed_pc=0x0c0c8c4au; return 0; }
r[7]=r[15];
goto P_0c0c8c4c;
P_0c0c8c4c: /* original 7704, guest PC 0x0c0c8c4c */
if(!s->budget--) { s->failed_pc=0x0c0c8c4cu; return 0; }
r[7]+=0x00000004u;
goto P_0c0c8c4e;
P_0c0c8c4e: /* original bd44, guest PC 0x0c0c8c4e */
if(!s->budget--) { s->failed_pc=0x0c0c8c4eu; return 0; }
target=0x0c0c86dau; r[16]=0x0c0c8c52u;
r[5]=read(ram,r[15]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8c52u) { target=s->pc; goto dispatch; }
goto P_0c0c8c52;
P_0c0c8c50: /* original 55f3, guest PC 0x0c0c8c50 */
if(!s->budget--) { s->failed_pc=0x0c0c8c50u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c0c8c52;
P_0c0c8c52: /* original 7f04, guest PC 0x0c0c8c52 */
if(!s->budget--) { s->failed_pc=0x0c0c8c52u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c8c54;
P_0c0c8c54: /* original 7f10, guest PC 0x0c0c8c54 */
if(!s->budget--) { s->failed_pc=0x0c0c8c54u; return 0; }
r[15]+=0x00000010u;
goto P_0c0c8c56;
P_0c0c8c56: /* original 4f26, guest PC 0x0c0c8c56 */
if(!s->budget--) { s->failed_pc=0x0c0c8c56u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c8c58;
P_0c0c8c58: /* original 000b, guest PC 0x0c0c8c58 */
if(!s->budget--) { s->failed_pc=0x0c0c8c58u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c8c5a: /* original 0009, guest PC 0x0c0c8c5a */
if(!s->budget--) { s->failed_pc=0x0c0c8c5au; return 0; }
return vf3_matrix_family(0x0c0c8c5cu,s,ram);
P_0c0c9c08: /* original 000b, guest PC 0x0c0c9c08 */
if(!s->budget--) { s->failed_pc=0x0c0c9c08u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c9c0a: /* original 0009, guest PC 0x0c0c9c0a */
if(!s->budget--) { s->failed_pc=0x0c0c9c0au; return 0; }
return vf3_matrix_family(0x0c0c9c0cu,s,ram);
P_0c0ca32a: /* original 000b, guest PC 0x0c0ca32a */
if(!s->budget--) { s->failed_pc=0x0c0ca32au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0ca32c: /* original 0009, guest PC 0x0c0ca32c */
if(!s->budget--) { s->failed_pc=0x0c0ca32cu; return 0; }
return vf3_matrix_family(0x0c0ca32eu,s,ram);
P_0c0cc44e: /* original 4f22, guest PC 0x0c0cc44e */
if(!s->budget--) { s->failed_pc=0x0c0cc44eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cc450;
P_0c0cc450: /* original 5d4d, guest PC 0x0c0cc450 */
if(!s->budget--) { s->failed_pc=0x0c0cc450u; return 0; }
r[13]=read(ram,r[4]+52,4);
goto P_0c0cc452;
P_0c0cc452: /* original 9e2d, guest PC 0x0c0cc452 */
if(!s->budget--) { s->failed_pc=0x0c0cc452u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc4b0u,2);
goto P_0c0cc454;
P_0c0cc454: /* original fd46, guest PC 0x0c0cc454 */
if(!s->budget--) { s->failed_pc=0x0c0cc454u; return 0; }
vf3_matrix_load(s,ram,13,r[4]+r[0]);
goto P_0c0cc456;
P_0c0cc456: /* original 2dd8, guest PC 0x0c0cc456 */
if(!s->budget--) { s->failed_pc=0x0c0cc456u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0cc458;
P_0c0cc458: /* original 5947, guest PC 0x0c0cc458 */
if(!s->budget--) { s->failed_pc=0x0c0cc458u; return 0; }
r[9]=read(ram,r[4]+28,4);
goto P_0c0cc45a;
P_0c0cc45a: /* original 7ffc, guest PC 0x0c0cc45a */
if(!s->budget--) { s->failed_pc=0x0c0cc45au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0cc45c;
P_0c0cc45c: /* original 5a49, guest PC 0x0c0cc45c */
if(!s->budget--) { s->failed_pc=0x0c0cc45cu; return 0; }
r[10]=read(ram,r[4]+36,4);
goto P_0c0cc45e;
P_0c0cc45e: /* original 5b4a, guest PC 0x0c0cc45e */
if(!s->budget--) { s->failed_pc=0x0c0cc45eu; return 0; }
r[11]=read(ram,r[4]+40,4);
goto P_0c0cc460;
P_0c0cc460: /* original 8d1a, guest PC 0x0c0cc460 */
if(!s->budget--) { s->failed_pc=0x0c0cc460u; return 0; }
cond=r[17]&1u;
r[14]+=r[4];
if(cond) { goto P_0c0cc498; }
goto P_0c0cc464;
P_0c0cc462: /* original 3e4c, guest PC 0x0c0cc462 */
if(!s->budget--) { s->failed_pc=0x0c0cc462u; return 0; }
r[14]+=r[4];
goto P_0c0cc464;
P_0c0cc464: /* original a016, guest PC 0x0c0cc464 */
if(!s->budget--) { s->failed_pc=0x0c0cc464u; return 0; }
r[12]=0x00000001u;
goto P_0c0cc494;
P_0c0cc466: /* original ec01, guest PC 0x0c0cc466 */
if(!s->budget--) { s->failed_pc=0x0c0cc466u; return 0; }
r[12]=0x00000001u;
goto P_0c0cc468;
P_0c0cc468: /* original 85ed, guest PC 0x0c0cc468 */
if(!s->budget--) { s->failed_pc=0x0c0cc468u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+26,2);
goto P_0c0cc46a;
P_0c0cc46a: /* original 20c8, guest PC 0x0c0cc46a */
if(!s->budget--) { s->failed_pc=0x0c0cc46au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[12])==0)!=0);
goto P_0c0cc46c;
P_0c0cc46c: /* original 8d10, guest PC 0x0c0cc46c */
if(!s->budget--) { s->failed_pc=0x0c0cc46cu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[0],4);
if(cond) { goto P_0c0cc490; }
goto P_0c0cc470;
P_0c0cc46e: /* original 2f02, guest PC 0x0c0cc46e */
if(!s->budget--) { s->failed_pc=0x0c0cc46eu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0cc470;
P_0c0cc470: /* original 2fb6, guest PC 0x0c0cc470 */
if(!s->budget--) { s->failed_pc=0x0c0cc470u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0cc472;
P_0c0cc472: /* original 6693, guest PC 0x0c0cc472 */
if(!s->budget--) { s->failed_pc=0x0c0cc472u; return 0; }
r[6]=r[9];
goto P_0c0cc474;
P_0c0cc474: /* original 65f3, guest PC 0x0c0cc474 */
if(!s->budget--) { s->failed_pc=0x0c0cc474u; return 0; }
r[5]=r[15];
goto P_0c0cc476;
P_0c0cc476: /* original 7504, guest PC 0x0c0cc476 */
if(!s->budget--) { s->failed_pc=0x0c0cc476u; return 0; }
r[5]+=0x00000004u;
goto P_0c0cc478;
P_0c0cc478: /* original f5dc, guest PC 0x0c0cc478 */
if(!s->budget--) { s->failed_pc=0x0c0cc478u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c0cc47a;
P_0c0cc47a: /* original 67a3, guest PC 0x0c0cc47a */
if(!s->budget--) { s->failed_pc=0x0c0cc47au; return 0; }
r[7]=r[10];
goto P_0c0cc47c;
P_0c0cc47c: /* original f4fc, guest PC 0x0c0cc47c */
if(!s->budget--) { s->failed_pc=0x0c0cc47cu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0cc47e;
P_0c0cc47e: /* original bf59, guest PC 0x0c0cc47e */
if(!s->budget--) { s->failed_pc=0x0c0cc47eu; return 0; }
target=0x0c0cc334u; r[16]=0x0c0cc482u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cc482u) { target=s->pc; goto dispatch; }
goto P_0c0cc482;
P_0c0cc480: /* original 64e3, guest PC 0x0c0cc480 */
if(!s->budget--) { s->failed_pc=0x0c0cc480u; return 0; }
r[4]=r[14];
goto P_0c0cc482;
P_0c0cc482: /* original 7f04, guest PC 0x0c0cc482 */
if(!s->budget--) { s->failed_pc=0x0c0cc482u; return 0; }
r[15]+=0x00000004u;
goto P_0c0cc484;
P_0c0cc484: /* original f4ec, guest PC 0x0c0cc484 */
if(!s->budget--) { s->failed_pc=0x0c0cc484u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0cc486;
P_0c0cc486: /* original 65f3, guest PC 0x0c0cc486 */
if(!s->budget--) { s->failed_pc=0x0c0cc486u; return 0; }
r[5]=r[15];
goto P_0c0cc488;
P_0c0cc488: /* original bfb2, guest PC 0x0c0cc488 */
if(!s->budget--) { s->failed_pc=0x0c0cc488u; return 0; }
target=0x0c0cc3f0u; r[16]=0x0c0cc48cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cc48cu) { target=s->pc; goto dispatch; }
goto P_0c0cc48c;
P_0c0cc48a: /* original 64e3, guest PC 0x0c0cc48a */
if(!s->budget--) { s->failed_pc=0x0c0cc48au; return 0; }
r[4]=r[14];
goto P_0c0cc48c;
P_0c0cc48c: /* original 60f2, guest PC 0x0c0cc48c */
if(!s->budget--) { s->failed_pc=0x0c0cc48cu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0cc48e;
P_0c0cc48e: /* original 81ed, guest PC 0x0c0cc48e */
if(!s->budget--) { s->failed_pc=0x0c0cc48eu; return 0; }
write(ram,r[14]+26,r[0],2);
goto P_0c0cc490;
P_0c0cc490: /* original 7dff, guest PC 0x0c0cc490 */
if(!s->budget--) { s->failed_pc=0x0c0cc490u; return 0; }
r[13]+=0xffffffffu;
goto P_0c0cc492;
P_0c0cc492: /* original 7e20, guest PC 0x0c0cc492 */
if(!s->budget--) { s->failed_pc=0x0c0cc492u; return 0; }
r[14]+=0x00000020u;
goto P_0c0cc494;
P_0c0cc494: /* original 2dd8, guest PC 0x0c0cc494 */
if(!s->budget--) { s->failed_pc=0x0c0cc494u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0cc496;
P_0c0cc496: /* original 8be7, guest PC 0x0c0cc496 */
if(!s->budget--) { s->failed_pc=0x0c0cc496u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc468; }
goto P_0c0cc498;
P_0c0cc498: /* original 7f04, guest PC 0x0c0cc498 */
if(!s->budget--) { s->failed_pc=0x0c0cc498u; return 0; }
r[15]+=0x00000004u;
goto P_0c0cc49a;
P_0c0cc49a: /* original 4f26, guest PC 0x0c0cc49a */
if(!s->budget--) { s->failed_pc=0x0c0cc49au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cc49c;
P_0c0cc49c: /* original fdf9, guest PC 0x0c0cc49c */
if(!s->budget--) { s->failed_pc=0x0c0cc49cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cc49e;
P_0c0cc49e: /* original fef9, guest PC 0x0c0cc49e */
if(!s->budget--) { s->failed_pc=0x0c0cc49eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cc4a0;
P_0c0cc4a0: /* original fff9, guest PC 0x0c0cc4a0 */
if(!s->budget--) { s->failed_pc=0x0c0cc4a0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cc4a2;
P_0c0cc4a2: /* original 69f6, guest PC 0x0c0cc4a2 */
if(!s->budget--) { s->failed_pc=0x0c0cc4a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0cc4a4;
P_0c0cc4a4: /* original 6af6, guest PC 0x0c0cc4a4 */
if(!s->budget--) { s->failed_pc=0x0c0cc4a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cc4a6;
P_0c0cc4a6: /* original 6bf6, guest PC 0x0c0cc4a6 */
if(!s->budget--) { s->failed_pc=0x0c0cc4a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cc4a8;
P_0c0cc4a8: /* original 6cf6, guest PC 0x0c0cc4a8 */
if(!s->budget--) { s->failed_pc=0x0c0cc4a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cc4aa;
P_0c0cc4aa: /* original 6df6, guest PC 0x0c0cc4aa */
if(!s->budget--) { s->failed_pc=0x0c0cc4aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cc4ac;
P_0c0cc4ac: /* original 000b, guest PC 0x0c0cc4ac */
if(!s->budget--) { s->failed_pc=0x0c0cc4acu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cc4ae: /* original 6ef6, guest PC 0x0c0cc4ae */
if(!s->budget--) { s->failed_pc=0x0c0cc4aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0cc4b0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
