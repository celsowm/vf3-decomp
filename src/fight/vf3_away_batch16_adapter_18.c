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
int vf3_away_batch16_adapter_18(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08fccau: goto P_0c08fcca;
case 0x0c08fcccu: goto P_0c08fccc;
case 0x0c08fcceu: goto P_0c08fcce;
case 0x0c08fcd0u: goto P_0c08fcd0;
case 0x0c08fcd2u: goto P_0c08fcd2;
case 0x0c08fcd4u: goto P_0c08fcd4;
case 0x0c08fcd6u: goto P_0c08fcd6;
case 0x0c08fcd8u: goto P_0c08fcd8;
case 0x0c08fcdau: goto P_0c08fcda;
case 0x0c08fcdcu: goto P_0c08fcdc;
case 0x0c08fcdeu: goto P_0c08fcde;
case 0x0c08fce0u: goto P_0c08fce0;
case 0x0c08fce2u: goto P_0c08fce2;
case 0x0c08fce4u: goto P_0c08fce4;
case 0x0c08fce6u: goto P_0c08fce6;
case 0x0c08fce8u: goto P_0c08fce8;
case 0x0c08fceau: goto P_0c08fcea;
case 0x0c08fcecu: goto P_0c08fcec;
case 0x0c08fceeu: goto P_0c08fcee;
case 0x0c08fcf0u: goto P_0c08fcf0;
case 0x0c08fcf2u: goto P_0c08fcf2;
case 0x0c08fcf4u: goto P_0c08fcf4;
case 0x0c08fcf6u: goto P_0c08fcf6;
case 0x0c08fcf8u: goto P_0c08fcf8;
case 0x0c08fcfau: goto P_0c08fcfa;
case 0x0c08fcfcu: goto P_0c08fcfc;
case 0x0c08fcfeu: goto P_0c08fcfe;
case 0x0c08fd00u: goto P_0c08fd00;
case 0x0c08fd02u: goto P_0c08fd02;
case 0x0c08fd04u: goto P_0c08fd04;
case 0x0c08fd06u: goto P_0c08fd06;
case 0x0c08fd08u: goto P_0c08fd08;
case 0x0c08fd0au: goto P_0c08fd0a;
case 0x0c08fd0cu: goto P_0c08fd0c;
case 0x0c08fd0eu: goto P_0c08fd0e;
case 0x0c08fd10u: goto P_0c08fd10;
case 0x0c08fd12u: goto P_0c08fd12;
case 0x0c08fd14u: goto P_0c08fd14;
case 0x0c08fd16u: goto P_0c08fd16;
case 0x0c08fd18u: goto P_0c08fd18;
case 0x0c08fd1au: goto P_0c08fd1a;
case 0x0c08fd1cu: goto P_0c08fd1c;
case 0x0c08fd1eu: goto P_0c08fd1e;
case 0x0c08fd20u: goto P_0c08fd20;
case 0x0c08fd22u: goto P_0c08fd22;
case 0x0c08fd24u: goto P_0c08fd24;
case 0x0c08fd34u: goto P_0c08fd34;
case 0x0c08fd36u: goto P_0c08fd36;
case 0x0c08fd38u: goto P_0c08fd38;
case 0x0c08fd3au: goto P_0c08fd3a;
case 0x0c08fd3cu: goto P_0c08fd3c;
case 0x0c08fd3eu: goto P_0c08fd3e;
case 0x0c08fd40u: goto P_0c08fd40;
case 0x0c08fd42u: goto P_0c08fd42;
case 0x0c08fd44u: goto P_0c08fd44;
case 0x0c08fd46u: goto P_0c08fd46;
case 0x0c08fd48u: goto P_0c08fd48;
case 0x0c08fd4au: goto P_0c08fd4a;
case 0x0c08fd4cu: goto P_0c08fd4c;
case 0x0c08fd4eu: goto P_0c08fd4e;
case 0x0c08fd50u: goto P_0c08fd50;
case 0x0c08fd52u: goto P_0c08fd52;
case 0x0c08fd54u: goto P_0c08fd54;
case 0x0c08fd56u: goto P_0c08fd56;
case 0x0c08fd58u: goto P_0c08fd58;
case 0x0c08fd5au: goto P_0c08fd5a;
case 0x0c08fd5cu: goto P_0c08fd5c;
case 0x0c08fd5eu: goto P_0c08fd5e;
case 0x0c08fd60u: goto P_0c08fd60;
case 0x0c08fd62u: goto P_0c08fd62;
case 0x0c08fd64u: goto P_0c08fd64;
case 0x0c08fd66u: goto P_0c08fd66;
case 0x0c08fd68u: goto P_0c08fd68;
case 0x0c08fd6au: goto P_0c08fd6a;
case 0x0c08fd6cu: goto P_0c08fd6c;
case 0x0c08fd6eu: goto P_0c08fd6e;
case 0x0c08fd70u: goto P_0c08fd70;
case 0x0c08fd72u: goto P_0c08fd72;
case 0x0c08fd74u: goto P_0c08fd74;
case 0x0c08fd76u: goto P_0c08fd76;
case 0x0c08fd78u: goto P_0c08fd78;
case 0x0c08fd7au: goto P_0c08fd7a;
case 0x0c08fd7cu: goto P_0c08fd7c;
case 0x0c08fd7eu: goto P_0c08fd7e;
case 0x0c08fd80u: goto P_0c08fd80;
case 0x0c08fd82u: goto P_0c08fd82;
case 0x0c08fd84u: goto P_0c08fd84;
case 0x0c08fd86u: goto P_0c08fd86;
case 0x0c08fd88u: goto P_0c08fd88;
case 0x0c08fd8au: goto P_0c08fd8a;
case 0x0c08fd8cu: goto P_0c08fd8c;
case 0x0c08fd8eu: goto P_0c08fd8e;
case 0x0c08fd90u: goto P_0c08fd90;
case 0x0c08fd92u: goto P_0c08fd92;
case 0x0c08fd94u: goto P_0c08fd94;
case 0x0c08fd96u: goto P_0c08fd96;
case 0x0c08fd98u: goto P_0c08fd98;
case 0x0c08fd9au: goto P_0c08fd9a;
case 0x0c08fd9cu: goto P_0c08fd9c;
case 0x0c08fd9eu: goto P_0c08fd9e;
case 0x0c08fda0u: goto P_0c08fda0;
case 0x0c08fda2u: goto P_0c08fda2;
case 0x0c08fda4u: goto P_0c08fda4;
case 0x0c08fda6u: goto P_0c08fda6;
case 0x0c08fda8u: goto P_0c08fda8;
case 0x0c08fdaau: goto P_0c08fdaa;
case 0x0c08fdacu: goto P_0c08fdac;
case 0x0c08fdaeu: goto P_0c08fdae;
case 0x0c08fdb0u: goto P_0c08fdb0;
case 0x0c08fdb2u: goto P_0c08fdb2;
case 0x0c08fdb4u: goto P_0c08fdb4;
case 0x0c08fdb6u: goto P_0c08fdb6;
case 0x0c08fdb8u: goto P_0c08fdb8;
case 0x0c08fdbau: goto P_0c08fdba;
case 0x0c08fdbcu: goto P_0c08fdbc;
case 0x0c08fdbeu: goto P_0c08fdbe;
case 0x0c08fdc0u: goto P_0c08fdc0;
case 0x0c08fdc2u: goto P_0c08fdc2;
case 0x0c08fdc4u: goto P_0c08fdc4;
case 0x0c08fdc6u: goto P_0c08fdc6;
case 0x0c08fdc8u: goto P_0c08fdc8;
case 0x0c08fdcau: goto P_0c08fdca;
case 0x0c08fdccu: goto P_0c08fdcc;
case 0x0c08fdceu: goto P_0c08fdce;
case 0x0c08fdd0u: goto P_0c08fdd0;
case 0x0c08fdd2u: goto P_0c08fdd2;
case 0x0c08fdd4u: goto P_0c08fdd4;
case 0x0c08fdd6u: goto P_0c08fdd6;
case 0x0c08fdd8u: goto P_0c08fdd8;
case 0x0c08fddau: goto P_0c08fdda;
case 0x0c08fddcu: goto P_0c08fddc;
case 0x0c08fddeu: goto P_0c08fdde;
case 0x0c08fde0u: goto P_0c08fde0;
case 0x0c08fde2u: goto P_0c08fde2;
case 0x0c08fde4u: goto P_0c08fde4;
case 0x0c08fde6u: goto P_0c08fde6;
case 0x0c08fde8u: goto P_0c08fde8;
case 0x0c08fdeau: goto P_0c08fdea;
case 0x0c08fdecu: goto P_0c08fdec;
case 0x0c08fdeeu: goto P_0c08fdee;
case 0x0c08fdf0u: goto P_0c08fdf0;
case 0x0c08fdf2u: goto P_0c08fdf2;
case 0x0c08fdf4u: goto P_0c08fdf4;
case 0x0c08fdf6u: goto P_0c08fdf6;
case 0x0c08fdf8u: goto P_0c08fdf8;
case 0x0c08fdfau: goto P_0c08fdfa;
case 0x0c08fdfcu: goto P_0c08fdfc;
case 0x0c08fdfeu: goto P_0c08fdfe;
case 0x0c08fe00u: goto P_0c08fe00;
case 0x0c08fe02u: goto P_0c08fe02;
case 0x0c08fe04u: goto P_0c08fe04;
case 0x0c08fe06u: goto P_0c08fe06;
case 0x0c08fe08u: goto P_0c08fe08;
case 0x0c08fe0au: goto P_0c08fe0a;
case 0x0c08fe0cu: goto P_0c08fe0c;
case 0x0c08fe0eu: goto P_0c08fe0e;
case 0x0c08fe10u: goto P_0c08fe10;
case 0x0c08fe12u: goto P_0c08fe12;
case 0x0c08fe14u: goto P_0c08fe14;
case 0x0c08fe16u: goto P_0c08fe16;
case 0x0c08fe18u: goto P_0c08fe18;
case 0x0c08fe1au: goto P_0c08fe1a;
case 0x0c08fe1cu: goto P_0c08fe1c;
case 0x0c08fe1eu: goto P_0c08fe1e;
case 0x0c08fe20u: goto P_0c08fe20;
case 0x0c08fe22u: goto P_0c08fe22;
case 0x0c08fe24u: goto P_0c08fe24;
case 0x0c08fe26u: goto P_0c08fe26;
case 0x0c08fe28u: goto P_0c08fe28;
case 0x0c08fe2au: goto P_0c08fe2a;
case 0x0c08fe2cu: goto P_0c08fe2c;
case 0x0c08fe2eu: goto P_0c08fe2e;
case 0x0c08fe30u: goto P_0c08fe30;
case 0x0c08fe32u: goto P_0c08fe32;
case 0x0c08fe34u: goto P_0c08fe34;
case 0x0c08fe36u: goto P_0c08fe36;
case 0x0c08fe38u: goto P_0c08fe38;
case 0x0c08fe3au: goto P_0c08fe3a;
case 0x0c08fe3cu: goto P_0c08fe3c;
case 0x0c08fe3eu: goto P_0c08fe3e;
case 0x0c08fe40u: goto P_0c08fe40;
case 0x0c08fe42u: goto P_0c08fe42;
case 0x0c08fe44u: goto P_0c08fe44;
case 0x0c08fe46u: goto P_0c08fe46;
case 0x0c08fe48u: goto P_0c08fe48;
case 0x0c08fe4au: goto P_0c08fe4a;
case 0x0c08fe4cu: goto P_0c08fe4c;
case 0x0c08fe4eu: goto P_0c08fe4e;
case 0x0c08fe50u: goto P_0c08fe50;
case 0x0c08fe52u: goto P_0c08fe52;
case 0x0c08fe54u: goto P_0c08fe54;
case 0x0c08fe56u: goto P_0c08fe56;
case 0x0c08fe58u: goto P_0c08fe58;
case 0x0c08fe5au: goto P_0c08fe5a;
case 0x0c08fe5cu: goto P_0c08fe5c;
case 0x0c08fe5eu: goto P_0c08fe5e;
case 0x0c08fe60u: goto P_0c08fe60;
case 0x0c08fe62u: goto P_0c08fe62;
case 0x0c08fe64u: goto P_0c08fe64;
case 0x0c08fe66u: goto P_0c08fe66;
case 0x0c08fe68u: goto P_0c08fe68;
case 0x0c08fe6au: goto P_0c08fe6a;
case 0x0c08fe6cu: goto P_0c08fe6c;
case 0x0c08fe6eu: goto P_0c08fe6e;
case 0x0c08fe70u: goto P_0c08fe70;
case 0x0c08fe72u: goto P_0c08fe72;
case 0x0c08fe74u: goto P_0c08fe74;
case 0x0c08fe76u: goto P_0c08fe76;
case 0x0c08fe78u: goto P_0c08fe78;
case 0x0c08fe7au: goto P_0c08fe7a;
case 0x0c08fe7cu: goto P_0c08fe7c;
case 0x0c08fe7eu: goto P_0c08fe7e;
case 0x0c08fe80u: goto P_0c08fe80;
case 0x0c08fe82u: goto P_0c08fe82;
case 0x0c08fe84u: goto P_0c08fe84;
case 0x0c08fe86u: goto P_0c08fe86;
case 0x0c08fe88u: goto P_0c08fe88;
case 0x0c08fe8au: goto P_0c08fe8a;
case 0x0c08fe9cu: goto P_0c08fe9c;
case 0x0c08fe9eu: goto P_0c08fe9e;
case 0x0c08fea0u: goto P_0c08fea0;
case 0x0c08fea2u: goto P_0c08fea2;
case 0x0c08fea4u: goto P_0c08fea4;
case 0x0c08fea6u: goto P_0c08fea6;
case 0x0c08fea8u: goto P_0c08fea8;
case 0x0c08feaau: goto P_0c08feaa;
case 0x0c08feacu: goto P_0c08feac;
case 0x0c08feaeu: goto P_0c08feae;
case 0x0c08feb0u: goto P_0c08feb0;
case 0x0c08feb2u: goto P_0c08feb2;
case 0x0c08feb4u: goto P_0c08feb4;
case 0x0c08feb6u: goto P_0c08feb6;
case 0x0c08feb8u: goto P_0c08feb8;
case 0x0c08febau: goto P_0c08feba;
case 0x0c08febcu: goto P_0c08febc;
case 0x0c08febeu: goto P_0c08febe;
case 0x0c08fec0u: goto P_0c08fec0;
case 0x0c08fec2u: goto P_0c08fec2;
case 0x0c08fec4u: goto P_0c08fec4;
case 0x0c08fec6u: goto P_0c08fec6;
case 0x0c08fec8u: goto P_0c08fec8;
case 0x0c08fecau: goto P_0c08feca;
case 0x0c08feccu: goto P_0c08fecc;
case 0x0c08feceu: goto P_0c08fece;
case 0x0c08fed0u: goto P_0c08fed0;
case 0x0c08fed2u: goto P_0c08fed2;
case 0x0c08fed4u: goto P_0c08fed4;
case 0x0c08fed6u: goto P_0c08fed6;
case 0x0c08fed8u: goto P_0c08fed8;
case 0x0c08fedau: goto P_0c08feda;
case 0x0c08fedcu: goto P_0c08fedc;
case 0x0c08fedeu: goto P_0c08fede;
case 0x0c08fee0u: goto P_0c08fee0;
case 0x0c08fee2u: goto P_0c08fee2;
case 0x0c08fee4u: goto P_0c08fee4;
case 0x0c08fee6u: goto P_0c08fee6;
case 0x0c08fee8u: goto P_0c08fee8;
case 0x0c08feeau: goto P_0c08feea;
case 0x0c08feecu: goto P_0c08feec;
case 0x0c08feeeu: goto P_0c08feee;
case 0x0c08fef0u: goto P_0c08fef0;
case 0x0c08fef2u: goto P_0c08fef2;
case 0x0c08fef4u: goto P_0c08fef4;
case 0x0c08fef6u: goto P_0c08fef6;
case 0x0c08fef8u: goto P_0c08fef8;
case 0x0c08fefau: goto P_0c08fefa;
case 0x0c08fefcu: goto P_0c08fefc;
case 0x0c08fefeu: goto P_0c08fefe;
case 0x0c08ff00u: goto P_0c08ff00;
case 0x0c08ff02u: goto P_0c08ff02;
case 0x0c08ff04u: goto P_0c08ff04;
case 0x0c08ff06u: goto P_0c08ff06;
case 0x0c08ff08u: goto P_0c08ff08;
case 0x0c08ff0au: goto P_0c08ff0a;
case 0x0c08ff0cu: goto P_0c08ff0c;
case 0x0c08ff0eu: goto P_0c08ff0e;
case 0x0c08ff10u: goto P_0c08ff10;
case 0x0c08ff12u: goto P_0c08ff12;
case 0x0c08ff14u: goto P_0c08ff14;
case 0x0c08ff16u: goto P_0c08ff16;
case 0x0c08ff18u: goto P_0c08ff18;
case 0x0c08ff1au: goto P_0c08ff1a;
case 0x0c08ff1cu: goto P_0c08ff1c;
case 0x0c08ff1eu: goto P_0c08ff1e;
case 0x0c08ff20u: goto P_0c08ff20;
case 0x0c08ff22u: goto P_0c08ff22;
case 0x0c08ff24u: goto P_0c08ff24;
case 0x0c08ff26u: goto P_0c08ff26;
case 0x0c08ff28u: goto P_0c08ff28;
case 0x0c08ff2au: goto P_0c08ff2a;
case 0x0c08ff2cu: goto P_0c08ff2c;
case 0x0c08ff2eu: goto P_0c08ff2e;
case 0x0c08ff30u: goto P_0c08ff30;
case 0x0c08ff32u: goto P_0c08ff32;
case 0x0c08ff34u: goto P_0c08ff34;
case 0x0c08ff36u: goto P_0c08ff36;
case 0x0c08ff38u: goto P_0c08ff38;
case 0x0c08ff3au: goto P_0c08ff3a;
case 0x0c08ff3cu: goto P_0c08ff3c;
case 0x0c08ff3eu: goto P_0c08ff3e;
case 0x0c08ff40u: goto P_0c08ff40;
case 0x0c08ff42u: goto P_0c08ff42;
case 0x0c08ff44u: goto P_0c08ff44;
case 0x0c08ff46u: goto P_0c08ff46;
case 0x0c08ff48u: goto P_0c08ff48;
case 0x0c08ff4au: goto P_0c08ff4a;
case 0x0c08ff4cu: goto P_0c08ff4c;
case 0x0c08ff4eu: goto P_0c08ff4e;
case 0x0c08ff50u: goto P_0c08ff50;
case 0x0c08ff52u: goto P_0c08ff52;
case 0x0c08ff54u: goto P_0c08ff54;
case 0x0c08ff56u: goto P_0c08ff56;
case 0x0c08ff58u: goto P_0c08ff58;
case 0x0c08ff5au: goto P_0c08ff5a;
case 0x0c08ff5cu: goto P_0c08ff5c;
case 0x0c08ff5eu: goto P_0c08ff5e;
case 0x0c08ff60u: goto P_0c08ff60;
case 0x0c08ff62u: goto P_0c08ff62;
case 0x0c08ff64u: goto P_0c08ff64;
case 0x0c08ff66u: goto P_0c08ff66;
case 0x0c08ff68u: goto P_0c08ff68;
case 0x0c08ff6au: goto P_0c08ff6a;
case 0x0c08ff6cu: goto P_0c08ff6c;
case 0x0c08ff6eu: goto P_0c08ff6e;
case 0x0c08ff70u: goto P_0c08ff70;
case 0x0c08ff72u: goto P_0c08ff72;
case 0x0c08ff74u: goto P_0c08ff74;
case 0x0c08ff76u: goto P_0c08ff76;
case 0x0c08ff78u: goto P_0c08ff78;
case 0x0c08ff7au: goto P_0c08ff7a;
case 0x0c08ff7cu: goto P_0c08ff7c;
case 0x0c08ff7eu: goto P_0c08ff7e;
case 0x0c08ff80u: goto P_0c08ff80;
case 0x0c08ff82u: goto P_0c08ff82;
case 0x0c08ff84u: goto P_0c08ff84;
case 0x0c08ff86u: goto P_0c08ff86;
case 0x0c08ff88u: goto P_0c08ff88;
case 0x0c08ff8au: goto P_0c08ff8a;
case 0x0c08ff8cu: goto P_0c08ff8c;
case 0x0c08ff8eu: goto P_0c08ff8e;
case 0x0c08ff90u: goto P_0c08ff90;
case 0x0c08ff92u: goto P_0c08ff92;
case 0x0c08ff94u: goto P_0c08ff94;
case 0x0c08ff96u: goto P_0c08ff96;
case 0x0c08ff98u: goto P_0c08ff98;
case 0x0c08ff9au: goto P_0c08ff9a;
case 0x0c08ff9cu: goto P_0c08ff9c;
case 0x0c08ff9eu: goto P_0c08ff9e;
case 0x0c08ffa0u: goto P_0c08ffa0;
case 0x0c08ffa2u: goto P_0c08ffa2;
case 0x0c08ffa4u: goto P_0c08ffa4;
case 0x0c08ffa6u: goto P_0c08ffa6;
case 0x0c08ffa8u: goto P_0c08ffa8;
case 0x0c08ffaau: goto P_0c08ffaa;
case 0x0c08ffacu: goto P_0c08ffac;
case 0x0c08ffaeu: goto P_0c08ffae;
case 0x0c08ffb0u: goto P_0c08ffb0;
case 0x0c08ffb2u: goto P_0c08ffb2;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08fcca: /* original e070, guest PC 0x0c08fcca */
if(!s->budget--) { s->failed_pc=0x0c08fccau; return 0; }
r[0]=0x00000070u;
goto P_0c08fccc;
P_0c08fccc: /* original fffb, guest PC 0x0c08fccc */
if(!s->budget--) { s->failed_pc=0x0c08fcccu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08fcce;
P_0c08fcce: /* original ffeb, guest PC 0x0c08fcce */
if(!s->budget--) { s->failed_pc=0x0c08fcceu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08fcd0;
P_0c08fcd0: /* original ffcb, guest PC 0x0c08fcd0 */
if(!s->budget--) { s->failed_pc=0x0c08fcd0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c08fcd2;
P_0c08fcd2: /* original f546, guest PC 0x0c08fcd2 */
if(!s->budget--) { s->failed_pc=0x0c08fcd2u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c08fcd4;
P_0c08fcd4: /* original e074, guest PC 0x0c08fcd4 */
if(!s->budget--) { s->failed_pc=0x0c08fcd4u; return 0; }
r[0]=0x00000074u;
goto P_0c08fcd6;
P_0c08fcd6: /* original f946, guest PC 0x0c08fcd6 */
if(!s->budget--) { s->failed_pc=0x0c08fcd6u; return 0; }
vf3_matrix_load(s,ram,9,r[4]+r[0]);
goto P_0c08fcd8;
P_0c08fcd8: /* original e078, guest PC 0x0c08fcd8 */
if(!s->budget--) { s->failed_pc=0x0c08fcd8u; return 0; }
r[0]=0x00000078u;
goto P_0c08fcda;
P_0c08fcda: /* original f846, guest PC 0x0c08fcda */
if(!s->budget--) { s->failed_pc=0x0c08fcdau; return 0; }
vf3_matrix_load(s,ram,8,r[4]+r[0]);
goto P_0c08fcdc;
P_0c08fcdc: /* original 7040, guest PC 0x0c08fcdc */
if(!s->budget--) { s->failed_pc=0x0c08fcdcu; return 0; }
r[0]+=0x00000040u;
goto P_0c08fcde;
P_0c08fcde: /* original fa46, guest PC 0x0c08fcde */
if(!s->budget--) { s->failed_pc=0x0c08fcdeu; return 0; }
vf3_matrix_load(s,ram,10,r[4]+r[0]);
goto P_0c08fce0;
P_0c08fce0: /* original 7004, guest PC 0x0c08fce0 */
if(!s->budget--) { s->failed_pc=0x0c08fce0u; return 0; }
r[0]+=0x00000004u;
goto P_0c08fce2;
P_0c08fce2: /* original fb46, guest PC 0x0c08fce2 */
if(!s->budget--) { s->failed_pc=0x0c08fce2u; return 0; }
vf3_matrix_load(s,ram,11,r[4]+r[0]);
goto P_0c08fce4;
P_0c08fce4: /* original 7004, guest PC 0x0c08fce4 */
if(!s->budget--) { s->failed_pc=0x0c08fce4u; return 0; }
r[0]+=0x00000004u;
goto P_0c08fce6;
P_0c08fce6: /* original ff46, guest PC 0x0c08fce6 */
if(!s->budget--) { s->failed_pc=0x0c08fce6u; return 0; }
vf3_matrix_load(s,ram,15,r[4]+r[0]);
goto P_0c08fce8;
P_0c08fce8: /* original 7040, guest PC 0x0c08fce8 */
if(!s->budget--) { s->failed_pc=0x0c08fce8u; return 0; }
r[0]+=0x00000040u;
goto P_0c08fcea;
P_0c08fcea: /* original fc46, guest PC 0x0c08fcea */
if(!s->budget--) { s->failed_pc=0x0c08fceau; return 0; }
vf3_matrix_load(s,ram,12,r[4]+r[0]);
goto P_0c08fcec;
P_0c08fcec: /* original 7004, guest PC 0x0c08fcec */
if(!s->budget--) { s->failed_pc=0x0c08fcecu; return 0; }
r[0]+=0x00000004u;
goto P_0c08fcee;
P_0c08fcee: /* original fe46, guest PC 0x0c08fcee */
if(!s->budget--) { s->failed_pc=0x0c08fceeu; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c08fcf0;
P_0c08fcf0: /* original 7004, guest PC 0x0c08fcf0 */
if(!s->budget--) { s->failed_pc=0x0c08fcf0u; return 0; }
r[0]+=0x00000004u;
goto P_0c08fcf2;
P_0c08fcf2: /* original f146, guest PC 0x0c08fcf2 */
if(!s->budget--) { s->failed_pc=0x0c08fcf2u; return 0; }
vf3_matrix_load(s,ram,1,r[4]+r[0]);
goto P_0c08fcf4;
P_0c08fcf4: /* original 7040, guest PC 0x0c08fcf4 */
if(!s->budget--) { s->failed_pc=0x0c08fcf4u; return 0; }
r[0]+=0x00000040u;
goto P_0c08fcf6;
P_0c08fcf6: /* original f446, guest PC 0x0c08fcf6 */
if(!s->budget--) { s->failed_pc=0x0c08fcf6u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c08fcf8;
P_0c08fcf8: /* original f5c1, guest PC 0x0c08fcf8 */
if(!s->budget--) { s->failed_pc=0x0c08fcf8u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[12],r[18],'-');
goto P_0c08fcfa;
P_0c08fcfa: /* original 7004, guest PC 0x0c08fcfa */
if(!s->budget--) { s->failed_pc=0x0c08fcfau; return 0; }
r[0]+=0x00000004u;
goto P_0c08fcfc;
P_0c08fcfc: /* original f811, guest PC 0x0c08fcfc */
if(!s->budget--) { s->failed_pc=0x0c08fcfcu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[1],r[18],'-');
goto P_0c08fcfe;
P_0c08fcfe: /* original f9e1, guest PC 0x0c08fcfe */
if(!s->budget--) { s->failed_pc=0x0c08fcfeu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[14],r[18],'-');
goto P_0c08fd00;
P_0c08fd00: /* original f746, guest PC 0x0c08fd00 */
if(!s->budget--) { s->failed_pc=0x0c08fd00u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c08fd02;
P_0c08fd02: /* original 7004, guest PC 0x0c08fd02 */
if(!s->budget--) { s->failed_pc=0x0c08fd02u; return 0; }
r[0]+=0x00000004u;
goto P_0c08fd04;
P_0c08fd04: /* original f646, guest PC 0x0c08fd04 */
if(!s->budget--) { s->failed_pc=0x0c08fd04u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c08fd06;
P_0c08fd06: /* original 7fe0, guest PC 0x0c08fd06 */
if(!s->budget--) { s->failed_pc=0x0c08fd06u; return 0; }
r[15]+=0xffffffe0u;
goto P_0c08fd08;
P_0c08fd08: /* original f35c, guest PC 0x0c08fd08 */
if(!s->budget--) { s->failed_pc=0x0c08fd08u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c08fd0a;
P_0c08fd0a: /* original f352, guest PC 0x0c08fd0a */
if(!s->budget--) { s->failed_pc=0x0c08fd0au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c08fd0c;
P_0c08fd0c: /* original f09c, guest PC 0x0c08fd0c */
if(!s->budget--) { s->failed_pc=0x0c08fd0cu; return 0; }
vf3_matrix_move(s,0,9);
goto P_0c08fd0e;
P_0c08fd0e: /* original e018, guest PC 0x0c08fd0e */
if(!s->budget--) { s->failed_pc=0x0c08fd0eu; return 0; }
r[0]=0x00000018u;
goto P_0c08fd10;
P_0c08fd10: /* original f39e, guest PC 0x0c08fd10 */
if(!s->budget--) { s->failed_pc=0x0c08fd10u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c08fd12;
P_0c08fd12: /* original ff37, guest PC 0x0c08fd12 */
if(!s->budget--) { s->failed_pc=0x0c08fd12u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08fd14;
P_0c08fd14: /* original c706, guest PC 0x0c08fd14 */
if(!s->budget--) { s->failed_pc=0x0c08fd14u; return 0; }
r[0]=code_base|0x0008fd30u;
goto P_0c08fd16;
P_0c08fd16: /* original f08c, guest PC 0x0c08fd16 */
if(!s->budget--) { s->failed_pc=0x0c08fd16u; return 0; }
vf3_matrix_move(s,0,8);
goto P_0c08fd18;
P_0c08fd18: /* original f38e, guest PC 0x0c08fd18 */
if(!s->budget--) { s->failed_pc=0x0c08fd18u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[8],fr[3],r[18]);
goto P_0c08fd1a;
P_0c08fd1a: /* original ff3a, guest PC 0x0c08fd1a */
if(!s->budget--) { s->failed_pc=0x0c08fd1au; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08fd1c;
P_0c08fd1c: /* original f208, guest PC 0x0c08fd1c */
if(!s->budget--) { s->failed_pc=0x0c08fd1cu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c08fd1e;
P_0c08fd1e: /* original f235, guest PC 0x0c08fd1e */
if(!s->budget--) { s->failed_pc=0x0c08fd1eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c08fd20;
P_0c08fd20: /* original 8b08, guest PC 0x0c08fd20 */
if(!s->budget--) { s->failed_pc=0x0c08fd20u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08fd34; }
goto P_0c08fd22;
P_0c08fd22: /* original a008, guest PC 0x0c08fd22 */
if(!s->budget--) { s->failed_pc=0x0c08fd22u; return 0; }
fr[3]=0;
goto P_0c08fd36;
P_0c08fd24: /* original f38d, guest PC 0x0c08fd24 */
if(!s->budget--) { s->failed_pc=0x0c08fd24u; return 0; }
fr[3]=0;
if(!vf3_matrix_family(0x0c08fd26u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08fd26u; return 0; } return 1;
P_0c08fd34: /* original f37d, guest PC 0x0c08fd34 */
if(!s->budget--) { s->failed_pc=0x0c08fd34u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c08fd36;
P_0c08fd36: /* original f2f8, guest PC 0x0c08fd36 */
if(!s->budget--) { s->failed_pc=0x0c08fd36u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c08fd38;
P_0c08fd38: /* original fac1, guest PC 0x0c08fd38 */
if(!s->budget--) { s->failed_pc=0x0c08fd38u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[12],r[18],'-');
goto P_0c08fd3a;
P_0c08fd3a: /* original fbe1, guest PC 0x0c08fd3a */
if(!s->budget--) { s->failed_pc=0x0c08fd3au; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[14],r[18],'-');
goto P_0c08fd3c;
P_0c08fd3c: /* original e00c, guest PC 0x0c08fd3c */
if(!s->budget--) { s->failed_pc=0x0c08fd3cu; return 0; }
r[0]=0x0000000cu;
goto P_0c08fd3e;
P_0c08fd3e: /* original f232, guest PC 0x0c08fd3e */
if(!s->budget--) { s->failed_pc=0x0c08fd3eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c08fd40;
P_0c08fd40: /* original ff11, guest PC 0x0c08fd40 */
if(!s->budget--) { s->failed_pc=0x0c08fd40u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[1],r[18],'-');
goto P_0c08fd42;
P_0c08fd42: /* original ff27, guest PC 0x0c08fd42 */
if(!s->budget--) { s->failed_pc=0x0c08fd42u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c08fd44;
P_0c08fd44: /* original e014, guest PC 0x0c08fd44 */
if(!s->budget--) { s->failed_pc=0x0c08fd44u; return 0; }
r[0]=0x00000014u;
goto P_0c08fd46;
P_0c08fd46: /* original f35c, guest PC 0x0c08fd46 */
if(!s->budget--) { s->failed_pc=0x0c08fd46u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c08fd48;
P_0c08fd48: /* original f52c, guest PC 0x0c08fd48 */
if(!s->budget--) { s->failed_pc=0x0c08fd48u; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c08fd4a;
P_0c08fd4a: /* original f532, guest PC 0x0c08fd4a */
if(!s->budget--) { s->failed_pc=0x0c08fd4au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c08fd4c;
P_0c08fd4c: /* original f39c, guest PC 0x0c08fd4c */
if(!s->budget--) { s->failed_pc=0x0c08fd4cu; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c08fd4e;
P_0c08fd4e: /* original f92c, guest PC 0x0c08fd4e */
if(!s->budget--) { s->failed_pc=0x0c08fd4eu; return 0; }
vf3_matrix_move(s,9,2);
goto P_0c08fd50;
P_0c08fd50: /* original f932, guest PC 0x0c08fd50 */
if(!s->budget--) { s->failed_pc=0x0c08fd50u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'*');
goto P_0c08fd52;
P_0c08fd52: /* original f38c, guest PC 0x0c08fd52 */
if(!s->budget--) { s->failed_pc=0x0c08fd52u; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c08fd54;
P_0c08fd54: /* original f82c, guest PC 0x0c08fd54 */
if(!s->budget--) { s->failed_pc=0x0c08fd54u; return 0; }
vf3_matrix_move(s,8,2);
goto P_0c08fd56;
P_0c08fd56: /* original f832, guest PC 0x0c08fd56 */
if(!s->budget--) { s->failed_pc=0x0c08fd56u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'*');
goto P_0c08fd58;
P_0c08fd58: /* original f3ac, guest PC 0x0c08fd58 */
if(!s->budget--) { s->failed_pc=0x0c08fd58u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c08fd5a;
P_0c08fd5a: /* original f3a2, guest PC 0x0c08fd5a */
if(!s->budget--) { s->failed_pc=0x0c08fd5au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[10],r[18],'*');
goto P_0c08fd5c;
P_0c08fd5c: /* original f0bc, guest PC 0x0c08fd5c */
if(!s->budget--) { s->failed_pc=0x0c08fd5cu; return 0; }
vf3_matrix_move(s,0,11);
goto P_0c08fd5e;
P_0c08fd5e: /* original f3be, guest PC 0x0c08fd5e */
if(!s->budget--) { s->failed_pc=0x0c08fd5eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[11],fr[3],r[18]);
goto P_0c08fd60;
P_0c08fd60: /* original ff37, guest PC 0x0c08fd60 */
if(!s->budget--) { s->failed_pc=0x0c08fd60u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08fd62;
P_0c08fd62: /* original e004, guest PC 0x0c08fd62 */
if(!s->budget--) { s->failed_pc=0x0c08fd62u; return 0; }
r[0]=0x00000004u;
goto P_0c08fd64;
P_0c08fd64: /* original f0fc, guest PC 0x0c08fd64 */
if(!s->budget--) { s->failed_pc=0x0c08fd64u; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c08fd66;
P_0c08fd66: /* original f3fe, guest PC 0x0c08fd66 */
if(!s->budget--) { s->failed_pc=0x0c08fd66u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[15],fr[3],r[18]);
goto P_0c08fd68;
P_0c08fd68: /* original ff37, guest PC 0x0c08fd68 */
if(!s->budget--) { s->failed_pc=0x0c08fd68u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08fd6a;
P_0c08fd6a: /* original c74a, guest PC 0x0c08fd6a */
if(!s->budget--) { s->failed_pc=0x0c08fd6au; return 0; }
r[0]=code_base|0x0008fe94u;
goto P_0c08fd6c;
P_0c08fd6c: /* original f208, guest PC 0x0c08fd6c */
if(!s->budget--) { s->failed_pc=0x0c08fd6cu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c08fd6e;
P_0c08fd6e: /* original f235, guest PC 0x0c08fd6e */
if(!s->budget--) { s->failed_pc=0x0c08fd6eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c08fd70;
P_0c08fd70: /* original 8b01, guest PC 0x0c08fd70 */
if(!s->budget--) { s->failed_pc=0x0c08fd70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08fd76; }
goto P_0c08fd72;
P_0c08fd72: /* original a001, guest PC 0x0c08fd72 */
if(!s->budget--) { s->failed_pc=0x0c08fd72u; return 0; }
fr[3]=0;
goto P_0c08fd78;
P_0c08fd74: /* original f38d, guest PC 0x0c08fd74 */
if(!s->budget--) { s->failed_pc=0x0c08fd74u; return 0; }
fr[3]=0;
goto P_0c08fd76;
P_0c08fd76: /* original f37d, guest PC 0x0c08fd76 */
if(!s->budget--) { s->failed_pc=0x0c08fd76u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c08fd78;
P_0c08fd78: /* original e008, guest PC 0x0c08fd78 */
if(!s->budget--) { s->failed_pc=0x0c08fd78u; return 0; }
r[0]=0x00000008u;
goto P_0c08fd7a;
P_0c08fd7a: /* original f4c1, guest PC 0x0c08fd7a */
if(!s->budget--) { s->failed_pc=0x0c08fd7au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[12],r[18],'-');
goto P_0c08fd7c;
P_0c08fd7c: /* original ff37, guest PC 0x0c08fd7c */
if(!s->budget--) { s->failed_pc=0x0c08fd7cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08fd7e;
P_0c08fd7e: /* original e008, guest PC 0x0c08fd7e */
if(!s->budget--) { s->failed_pc=0x0c08fd7eu; return 0; }
r[0]=0x00000008u;
goto P_0c08fd80;
P_0c08fd80: /* original f3ac, guest PC 0x0c08fd80 */
if(!s->budget--) { s->failed_pc=0x0c08fd80u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c08fd82;
P_0c08fd82: /* original f7e1, guest PC 0x0c08fd82 */
if(!s->budget--) { s->failed_pc=0x0c08fd82u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[14],r[18],'-');
goto P_0c08fd84;
P_0c08fd84: /* original faf6, guest PC 0x0c08fd84 */
if(!s->budget--) { s->failed_pc=0x0c08fd84u; return 0; }
vf3_matrix_load(s,ram,10,r[15]+r[0]);
goto P_0c08fd86;
P_0c08fd86: /* original e008, guest PC 0x0c08fd86 */
if(!s->budget--) { s->failed_pc=0x0c08fd86u; return 0; }
r[0]=0x00000008u;
goto P_0c08fd88;
P_0c08fd88: /* original fe4c, guest PC 0x0c08fd88 */
if(!s->budget--) { s->failed_pc=0x0c08fd88u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c08fd8a;
P_0c08fd8a: /* original fe42, guest PC 0x0c08fd8a */
if(!s->budget--) { s->failed_pc=0x0c08fd8au; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'*');
goto P_0c08fd8c;
P_0c08fd8c: /* original fa32, guest PC 0x0c08fd8c */
if(!s->budget--) { s->failed_pc=0x0c08fd8cu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[3],r[18],'*');
goto P_0c08fd8e;
P_0c08fd8e: /* original f3bc, guest PC 0x0c08fd8e */
if(!s->budget--) { s->failed_pc=0x0c08fd8eu; return 0; }
vf3_matrix_move(s,3,11);
goto P_0c08fd90;
P_0c08fd90: /* original fbf6, guest PC 0x0c08fd90 */
if(!s->budget--) { s->failed_pc=0x0c08fd90u; return 0; }
vf3_matrix_load(s,ram,11,r[15]+r[0]);
goto P_0c08fd92;
P_0c08fd92: /* original e008, guest PC 0x0c08fd92 */
if(!s->budget--) { s->failed_pc=0x0c08fd92u; return 0; }
r[0]=0x00000008u;
goto P_0c08fd94;
P_0c08fd94: /* original f07c, guest PC 0x0c08fd94 */
if(!s->budget--) { s->failed_pc=0x0c08fd94u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c08fd96;
P_0c08fd96: /* original f611, guest PC 0x0c08fd96 */
if(!s->budget--) { s->failed_pc=0x0c08fd96u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[1],r[18],'-');
goto P_0c08fd98;
P_0c08fd98: /* original fb32, guest PC 0x0c08fd98 */
if(!s->budget--) { s->failed_pc=0x0c08fd98u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[3],r[18],'*');
goto P_0c08fd9a;
P_0c08fd9a: /* original f3fc, guest PC 0x0c08fd9a */
if(!s->budget--) { s->failed_pc=0x0c08fd9au; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c08fd9c;
P_0c08fd9c: /* original fff6, guest PC 0x0c08fd9c */
if(!s->budget--) { s->failed_pc=0x0c08fd9cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]+r[0]);
goto P_0c08fd9e;
P_0c08fd9e: /* original c73d, guest PC 0x0c08fd9e */
if(!s->budget--) { s->failed_pc=0x0c08fd9eu; return 0; }
r[0]=code_base|0x0008fe94u;
goto P_0c08fda0;
P_0c08fda0: /* original f208, guest PC 0x0c08fda0 */
if(!s->budget--) { s->failed_pc=0x0c08fda0u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c08fda2;
P_0c08fda2: /* original ff32, guest PC 0x0c08fda2 */
if(!s->budget--) { s->failed_pc=0x0c08fda2u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c08fda4;
P_0c08fda4: /* original f3ec, guest PC 0x0c08fda4 */
if(!s->budget--) { s->failed_pc=0x0c08fda4u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c08fda6;
P_0c08fda6: /* original f37e, guest PC 0x0c08fda6 */
if(!s->budget--) { s->failed_pc=0x0c08fda6u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[7],fr[3],r[18]);
goto P_0c08fda8;
P_0c08fda8: /* original f06c, guest PC 0x0c08fda8 */
if(!s->budget--) { s->failed_pc=0x0c08fda8u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c08fdaa;
P_0c08fdaa: /* original fe3c, guest PC 0x0c08fdaa */
if(!s->budget--) { s->failed_pc=0x0c08fdaau; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c08fdac;
P_0c08fdac: /* original fe6e, guest PC 0x0c08fdac */
if(!s->budget--) { s->failed_pc=0x0c08fdacu; return 0; }
fr[14]=vf3_fpu_mac(fr[0],fr[6],fr[14],r[18]);
goto P_0c08fdae;
P_0c08fdae: /* original f2e5, guest PC 0x0c08fdae */
if(!s->budget--) { s->failed_pc=0x0c08fdaeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[14]))!=0);
goto P_0c08fdb0;
P_0c08fdb0: /* original 8f02, guest PC 0x0c08fdb0 */
if(!s->budget--) { s->failed_pc=0x0c08fdb0u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,3,4);
if(!cond) { goto P_0c08fdb8; }
goto P_0c08fdb4;
P_0c08fdb2: /* original f34c, guest PC 0x0c08fdb2 */
if(!s->budget--) { s->failed_pc=0x0c08fdb2u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08fdb4;
P_0c08fdb4: /* original a001, guest PC 0x0c08fdb4 */
if(!s->budget--) { s->failed_pc=0x0c08fdb4u; return 0; }
fr[14]=0;
goto P_0c08fdba;
P_0c08fdb6: /* original fe8d, guest PC 0x0c08fdb6 */
if(!s->budget--) { s->failed_pc=0x0c08fdb6u; return 0; }
fr[14]=0;
goto P_0c08fdb8;
P_0c08fdb8: /* original fe7d, guest PC 0x0c08fdb8 */
if(!s->budget--) { s->failed_pc=0x0c08fdb8u; return 0; }
if(!vf3_fpu_fsrra(fr[14],r[18],&fr[14])) goto unsupported;
goto P_0c08fdba;
P_0c08fdba: /* original f4ec, guest PC 0x0c08fdba */
if(!s->budget--) { s->failed_pc=0x0c08fdbau; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c08fdbc;
P_0c08fdbc: /* original f432, guest PC 0x0c08fdbc */
if(!s->budget--) { s->failed_pc=0x0c08fdbcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c08fdbe;
P_0c08fdbe: /* original f37c, guest PC 0x0c08fdbe */
if(!s->budget--) { s->failed_pc=0x0c08fdbeu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c08fdc0;
P_0c08fdc0: /* original f7ec, guest PC 0x0c08fdc0 */
if(!s->budget--) { s->failed_pc=0x0c08fdc0u; return 0; }
vf3_matrix_move(s,7,14);
goto P_0c08fdc2;
P_0c08fdc2: /* original f732, guest PC 0x0c08fdc2 */
if(!s->budget--) { s->failed_pc=0x0c08fdc2u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c08fdc4;
P_0c08fdc4: /* original f36c, guest PC 0x0c08fdc4 */
if(!s->budget--) { s->failed_pc=0x0c08fdc4u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c08fdc6;
P_0c08fdc6: /* original f6ec, guest PC 0x0c08fdc6 */
if(!s->budget--) { s->failed_pc=0x0c08fdc6u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c08fdc8;
P_0c08fdc8: /* original f632, guest PC 0x0c08fdc8 */
if(!s->budget--) { s->failed_pc=0x0c08fdc8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c08fdca;
P_0c08fdca: /* original f35c, guest PC 0x0c08fdca */
if(!s->budget--) { s->failed_pc=0x0c08fdcau; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c08fdcc;
P_0c08fdcc: /* original f54c, guest PC 0x0c08fdcc */
if(!s->budget--) { s->failed_pc=0x0c08fdccu; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c08fdce;
P_0c08fdce: /* original f532, guest PC 0x0c08fdce */
if(!s->budget--) { s->failed_pc=0x0c08fdceu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c08fdd0;
P_0c08fdd0: /* original f07c, guest PC 0x0c08fdd0 */
if(!s->budget--) { s->failed_pc=0x0c08fdd0u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c08fdd2;
P_0c08fdd2: /* original f4a2, guest PC 0x0c08fdd2 */
if(!s->budget--) { s->failed_pc=0x0c08fdd2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[10],r[18],'*');
goto P_0c08fdd4;
P_0c08fdd4: /* original 905a, guest PC 0x0c08fdd4 */
if(!s->budget--) { s->failed_pc=0x0c08fdd4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08fe8cu,2);
goto P_0c08fdd6;
P_0c08fdd6: /* original 925a, guest PC 0x0c08fdd6 */
if(!s->budget--) { s->failed_pc=0x0c08fdd6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08fe8eu,2);
goto P_0c08fdd8;
P_0c08fdd8: /* original f25c, guest PC 0x0c08fdd8 */
if(!s->budget--) { s->failed_pc=0x0c08fdd8u; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c08fdda;
P_0c08fdda: /* original f29e, guest PC 0x0c08fdda */
if(!s->budget--) { s->failed_pc=0x0c08fddau; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[9],fr[2],r[18]);
goto P_0c08fddc;
P_0c08fddc: /* original f06c, guest PC 0x0c08fddc */
if(!s->budget--) { s->failed_pc=0x0c08fddcu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c08fdde;
P_0c08fdde: /* original 034d, guest PC 0x0c08fdde */
if(!s->budget--) { s->failed_pc=0x0c08fddeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08fde0;
P_0c08fde0: /* original f32c, guest PC 0x0c08fde0 */
if(!s->budget--) { s->failed_pc=0x0c08fde0u; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c08fde2;
P_0c08fde2: /* original f38e, guest PC 0x0c08fde2 */
if(!s->budget--) { s->failed_pc=0x0c08fde2u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[8],fr[3],r[18]);
goto P_0c08fde4;
P_0c08fde4: /* original f07c, guest PC 0x0c08fde4 */
if(!s->budget--) { s->failed_pc=0x0c08fde4u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c08fde6;
P_0c08fde6: /* original 6433, guest PC 0x0c08fde6 */
if(!s->budget--) { s->failed_pc=0x0c08fde6u; return 0; }
r[4]=r[3];
goto P_0c08fde8;
P_0c08fde8: /* original f24c, guest PC 0x0c08fde8 */
if(!s->budget--) { s->failed_pc=0x0c08fde8u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c08fdea;
P_0c08fdea: /* original f2be, guest PC 0x0c08fdea */
if(!s->budget--) { s->failed_pc=0x0c08fdeau; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[11],fr[2],r[18]);
goto P_0c08fdec;
P_0c08fdec: /* original f06c, guest PC 0x0c08fdec */
if(!s->budget--) { s->failed_pc=0x0c08fdecu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c08fdee;
P_0c08fdee: /* original 4421, guest PC 0x0c08fdee */
if(!s->budget--) { s->failed_pc=0x0c08fdeeu; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]=(uint32_t)((int32_t)r[4]>>1);
goto P_0c08fdf0;
P_0c08fdf0: /* original f53c, guest PC 0x0c08fdf0 */
if(!s->budget--) { s->failed_pc=0x0c08fdf0u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c08fdf2;
P_0c08fdf2: /* original 342c, guest PC 0x0c08fdf2 */
if(!s->budget--) { s->failed_pc=0x0c08fdf2u; return 0; }
r[4]+=r[2];
goto P_0c08fdf4;
P_0c08fdf4: /* original f32c, guest PC 0x0c08fdf4 */
if(!s->budget--) { s->failed_pc=0x0c08fdf4u; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c08fdf6;
P_0c08fdf6: /* original f3fe, guest PC 0x0c08fdf6 */
if(!s->budget--) { s->failed_pc=0x0c08fdf6u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[15],fr[3],r[18]);
goto P_0c08fdf8;
P_0c08fdf8: /* original f43c, guest PC 0x0c08fdf8 */
if(!s->budget--) { s->failed_pc=0x0c08fdf8u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c08fdfa;
P_0c08fdfa: /* original e010, guest PC 0x0c08fdfa */
if(!s->budget--) { s->failed_pc=0x0c08fdfau; return 0; }
r[0]=0x00000010u;
goto P_0c08fdfc;
P_0c08fdfc: /* original 63f3, guest PC 0x0c08fdfc */
if(!s->budget--) { s->failed_pc=0x0c08fdfcu; return 0; }
r[3]=r[15];
goto P_0c08fdfe;
P_0c08fdfe: /* original 644f, guest PC 0x0c08fdfe */
if(!s->budget--) { s->failed_pc=0x0c08fdfeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c08fe00;
P_0c08fe00: /* original 61f3, guest PC 0x0c08fe00 */
if(!s->budget--) { s->failed_pc=0x0c08fe00u; return 0; }
r[1]=r[15];
goto P_0c08fe02;
P_0c08fe02: /* original 445a, guest PC 0x0c08fe02 */
if(!s->budget--) { s->failed_pc=0x0c08fe02u; return 0; }
r[53]=r[4];
goto P_0c08fe04;
P_0c08fe04: /* original 7310, guest PC 0x0c08fe04 */
if(!s->budget--) { s->failed_pc=0x0c08fe04u; return 0; }
r[3]+=0x00000010u;
goto P_0c08fe06;
P_0c08fe06: /* original 711c, guest PC 0x0c08fe06 */
if(!s->budget--) { s->failed_pc=0x0c08fe06u; return 0; }
r[1]+=0x0000001cu;
goto P_0c08fe08;
P_0c08fe08: /* original f0fd, guest PC 0x0c08fe08 */
if(!s->budget--) { s->failed_pc=0x0c08fe08u; return 0; }
vf3_fpu_fsca(r[53],fr+0);
goto P_0c08fe0a;
P_0c08fe0a: /* original f10a, guest PC 0x0c08fe0a */
if(!s->budget--) { s->failed_pc=0x0c08fe0au; return 0; }
vf3_matrix_store(s,ram,0,r[1]);
goto P_0c08fe0c;
P_0c08fe0c: /* original f31a, guest PC 0x0c08fe0c */
if(!s->budget--) { s->failed_pc=0x0c08fe0cu; return 0; }
vf3_matrix_store(s,ram,1,r[3]);
goto P_0c08fe0e;
P_0c08fe0e: /* original fff6, guest PC 0x0c08fe0e */
if(!s->budget--) { s->failed_pc=0x0c08fe0eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]+r[0]);
goto P_0c08fe10;
P_0c08fe10: /* original f35c, guest PC 0x0c08fe10 */
if(!s->budget--) { s->failed_pc=0x0c08fe10u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c08fe12;
P_0c08fe12: /* original f5fc, guest PC 0x0c08fe12 */
if(!s->budget--) { s->failed_pc=0x0c08fe12u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08fe14;
P_0c08fe14: /* original f531, guest PC 0x0c08fe14 */
if(!s->budget--) { s->failed_pc=0x0c08fe14u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c08fe16;
P_0c08fe16: /* original f68d, guest PC 0x0c08fe16 */
if(!s->budget--) { s->failed_pc=0x0c08fe16u; return 0; }
fr[6]=0;
goto P_0c08fe18;
P_0c08fe18: /* original f34c, guest PC 0x0c08fe18 */
if(!s->budget--) { s->failed_pc=0x0c08fe18u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08fe1a;
P_0c08fe1a: /* original f4fc, guest PC 0x0c08fe1a */
if(!s->budget--) { s->failed_pc=0x0c08fe1au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08fe1c;
P_0c08fe1c: /* original f431, guest PC 0x0c08fe1c */
if(!s->budget--) { s->failed_pc=0x0c08fe1cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c08fe1e;
P_0c08fe1e: /* original f25c, guest PC 0x0c08fe1e */
if(!s->budget--) { s->failed_pc=0x0c08fe1eu; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c08fe20;
P_0c08fe20: /* original f261, guest PC 0x0c08fe20 */
if(!s->budget--) { s->failed_pc=0x0c08fe20u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'-');
goto P_0c08fe22;
P_0c08fe22: /* original f38d, guest PC 0x0c08fe22 */
if(!s->budget--) { s->failed_pc=0x0c08fe22u; return 0; }
fr[3]=0;
goto P_0c08fe24;
P_0c08fe24: /* original f325, guest PC 0x0c08fe24 */
if(!s->budget--) { s->failed_pc=0x0c08fe24u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c08fe26;
P_0c08fe26: /* original 8f01, guest PC 0x0c08fe26 */
if(!s->budget--) { s->failed_pc=0x0c08fe26u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,3,4);
if(!cond) { goto P_0c08fe2c; }
goto P_0c08fe2a;
P_0c08fe28: /* original f34c, guest PC 0x0c08fe28 */
if(!s->budget--) { s->failed_pc=0x0c08fe28u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08fe2a;
P_0c08fe2a: /* original f56c, guest PC 0x0c08fe2a */
if(!s->budget--) { s->failed_pc=0x0c08fe2au; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c08fe2c;
P_0c08fe2c: /* original f361, guest PC 0x0c08fe2c */
if(!s->budget--) { s->failed_pc=0x0c08fe2cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'-');
goto P_0c08fe2e;
P_0c08fe2e: /* original f28d, guest PC 0x0c08fe2e */
if(!s->budget--) { s->failed_pc=0x0c08fe2eu; return 0; }
fr[2]=0;
goto P_0c08fe30;
P_0c08fe30: /* original f235, guest PC 0x0c08fe30 */
if(!s->budget--) { s->failed_pc=0x0c08fe30u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c08fe32;
P_0c08fe32: /* original 8b00, guest PC 0x0c08fe32 */
if(!s->budget--) { s->failed_pc=0x0c08fe32u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08fe36; }
goto P_0c08fe34;
P_0c08fe34: /* original f46c, guest PC 0x0c08fe34 */
if(!s->budget--) { s->failed_pc=0x0c08fe34u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c08fe36;
P_0c08fe36: /* original f540, guest PC 0x0c08fe36 */
if(!s->budget--) { s->failed_pc=0x0c08fe36u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'+');
goto P_0c08fe38;
P_0c08fe38: /* original c717, guest PC 0x0c08fe38 */
if(!s->budget--) { s->failed_pc=0x0c08fe38u; return 0; }
r[0]=code_base|0x0008fe98u;
goto P_0c08fe3a;
P_0c08fe3a: /* original f608, guest PC 0x0c08fe3a */
if(!s->budget--) { s->failed_pc=0x0c08fe3au; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c08fe3c;
P_0c08fe3c: /* original 7f20, guest PC 0x0c08fe3c */
if(!s->budget--) { s->failed_pc=0x0c08fe3cu; return 0; }
r[15]+=0x00000020u;
goto P_0c08fe3e;
P_0c08fe3e: /* original f49d, guest PC 0x0c08fe3e */
if(!s->budget--) { s->failed_pc=0x0c08fe3eu; return 0; }
fr[4]=0x3f800000u;
goto P_0c08fe40;
P_0c08fe40: /* original fcf9, guest PC 0x0c08fe40 */
if(!s->budget--) { s->failed_pc=0x0c08fe40u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08fe42;
P_0c08fe42: /* original f05c, guest PC 0x0c08fe42 */
if(!s->budget--) { s->failed_pc=0x0c08fe42u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c08fe44;
P_0c08fe44: /* original f46e, guest PC 0x0c08fe44 */
if(!s->budget--) { s->failed_pc=0x0c08fe44u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[6],fr[4],r[18]);
goto P_0c08fe46;
P_0c08fe46: /* original fef9, guest PC 0x0c08fe46 */
if(!s->budget--) { s->failed_pc=0x0c08fe46u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08fe48;
P_0c08fe48: /* original f34c, guest PC 0x0c08fe48 */
if(!s->budget--) { s->failed_pc=0x0c08fe48u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08fe4a;
P_0c08fe4a: /* original f432, guest PC 0x0c08fe4a */
if(!s->budget--) { s->failed_pc=0x0c08fe4au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c08fe4c;
P_0c08fe4c: /* original f04c, guest PC 0x0c08fe4c */
if(!s->budget--) { s->failed_pc=0x0c08fe4cu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c08fe4e;
P_0c08fe4e: /* original 000b, guest PC 0x0c08fe4e */
if(!s->budget--) { s->failed_pc=0x0c08fe4eu; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c08fe50: /* original fff9, guest PC 0x0c08fe50 */
if(!s->budget--) { s->failed_pc=0x0c08fe50u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08fe52;
P_0c08fe52: /* original 2fe6, guest PC 0x0c08fe52 */
if(!s->budget--) { s->failed_pc=0x0c08fe52u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08fe54;
P_0c08fe54: /* original 6263, guest PC 0x0c08fe54 */
if(!s->budget--) { s->failed_pc=0x0c08fe54u; return 0; }
r[2]=r[6];
goto P_0c08fe56;
P_0c08fe56: /* original 2fd6, guest PC 0x0c08fe56 */
if(!s->budget--) { s->failed_pc=0x0c08fe56u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08fe58;
P_0c08fe58: /* original e010, guest PC 0x0c08fe58 */
if(!s->budget--) { s->failed_pc=0x0c08fe58u; return 0; }
r[0]=0x00000010u;
goto P_0c08fe5a;
P_0c08fe5a: /* original fffb, guest PC 0x0c08fe5a */
if(!s->budget--) { s->failed_pc=0x0c08fe5au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08fe5c;
P_0c08fe5c: /* original ffeb, guest PC 0x0c08fe5c */
if(!s->budget--) { s->failed_pc=0x0c08fe5cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08fe5e;
P_0c08fe5e: /* original ffdb, guest PC 0x0c08fe5e */
if(!s->budget--) { s->failed_pc=0x0c08fe5eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c08fe60;
P_0c08fe60: /* original ffcb, guest PC 0x0c08fe60 */
if(!s->budget--) { s->failed_pc=0x0c08fe60u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c08fe62;
P_0c08fe62: /* original 4f22, guest PC 0x0c08fe62 */
if(!s->budget--) { s->failed_pc=0x0c08fe62u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08fe64;
P_0c08fe64: /* original 7fd8, guest PC 0x0c08fe64 */
if(!s->budget--) { s->failed_pc=0x0c08fe64u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c08fe66;
P_0c08fe66: /* original 1f56, guest PC 0x0c08fe66 */
if(!s->budget--) { s->failed_pc=0x0c08fe66u; return 0; }
write(ram,r[15]+24,r[5],4);
goto P_0c08fe68;
P_0c08fe68: /* original ff67, guest PC 0x0c08fe68 */
if(!s->budget--) { s->failed_pc=0x0c08fe68u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c08fe6a;
P_0c08fe6a: /* original 1f65, guest PC 0x0c08fe6a */
if(!s->budget--) { s->failed_pc=0x0c08fe6au; return 0; }
write(ram,r[15]+20,r[6],4);
goto P_0c08fe6c;
P_0c08fe6c: /* original 53f6, guest PC 0x0c08fe6c */
if(!s->budget--) { s->failed_pc=0x0c08fe6cu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c08fe6e;
P_0c08fe6e: /* original 5d4c, guest PC 0x0c08fe6e */
if(!s->budget--) { s->failed_pc=0x0c08fe6eu; return 0; }
r[13]=read(ram,r[4]+48,4);
goto P_0c08fe70;
P_0c08fe70: /* original fd38, guest PC 0x0c08fe70 */
if(!s->budget--) { s->failed_pc=0x0c08fe70u; return 0; }
vf3_matrix_load(s,ram,13,r[3]);
goto P_0c08fe72;
P_0c08fe72: /* original 930d, guest PC 0x0c08fe72 */
if(!s->budget--) { s->failed_pc=0x0c08fe72u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08fe90u,2);
goto P_0c08fe74;
P_0c08fe74: /* original fe28, guest PC 0x0c08fe74 */
if(!s->budget--) { s->failed_pc=0x0c08fe74u; return 0; }
vf3_matrix_load(s,ram,14,r[2]);
goto P_0c08fe76;
P_0c08fe76: /* original 23d8, guest PC 0x0c08fe76 */
if(!s->budget--) { s->failed_pc=0x0c08fe76u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c08fe78;
P_0c08fe78: /* original fc7c, guest PC 0x0c08fe78 */
if(!s->budget--) { s->failed_pc=0x0c08fe78u; return 0; }
vf3_matrix_move(s,12,7);
goto P_0c08fe7a;
P_0c08fe7a: /* original 8d0f, guest PC 0x0c08fe7a */
if(!s->budget--) { s->failed_pc=0x0c08fe7au; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,15,8);
if(cond) { goto P_0c08fe9c; }
goto P_0c08fe7e;
P_0c08fe7c: /* original ff8c, guest PC 0x0c08fe7c */
if(!s->budget--) { s->failed_pc=0x0c08fe7cu; return 0; }
vf3_matrix_move(s,15,8);
goto P_0c08fe7e;
P_0c08fe7e: /* original e008, guest PC 0x0c08fe7e */
if(!s->budget--) { s->failed_pc=0x0c08fe7eu; return 0; }
r[0]=0x00000008u;
goto P_0c08fe80;
P_0c08fe80: /* original ff8d, guest PC 0x0c08fe80 */
if(!s->budget--) { s->failed_pc=0x0c08fe80u; return 0; }
fr[15]=0;
goto P_0c08fe82;
P_0c08fe82: /* original ff47, guest PC 0x0c08fe82 */
if(!s->budget--) { s->failed_pc=0x0c08fe82u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c08fe84;
P_0c08fe84: /* original e004, guest PC 0x0c08fe84 */
if(!s->budget--) { s->failed_pc=0x0c08fe84u; return 0; }
r[0]=0x00000004u;
goto P_0c08fe86;
P_0c08fe86: /* original ee00, guest PC 0x0c08fe86 */
if(!s->budget--) { s->failed_pc=0x0c08fe86u; return 0; }
r[14]=0x00000000u;
goto P_0c08fe88;
P_0c08fe88: /* original a046, guest PC 0x0c08fe88 */
if(!s->budget--) { s->failed_pc=0x0c08fe88u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c08ff18;
P_0c08fe8a: /* original ff57, guest PC 0x0c08fe8a */
if(!s->budget--) { s->failed_pc=0x0c08fe8au; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
if(!vf3_matrix_family(0x0c08fe8cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08fe8cu; return 0; } return 1;
P_0c08fe9c: /* original e024, guest PC 0x0c08fe9c */
if(!s->budget--) { s->failed_pc=0x0c08fe9cu; return 0; }
r[0]=0x00000024u;
goto P_0c08fe9e;
P_0c08fe9e: /* original 63f3, guest PC 0x0c08fe9e */
if(!s->budget--) { s->failed_pc=0x0c08fe9eu; return 0; }
r[3]=r[15];
goto P_0c08fea0;
P_0c08fea0: /* original ff47, guest PC 0x0c08fea0 */
if(!s->budget--) { s->failed_pc=0x0c08fea0u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c08fea2;
P_0c08fea2: /* original e010, guest PC 0x0c08fea2 */
if(!s->budget--) { s->failed_pc=0x0c08fea2u; return 0; }
r[0]=0x00000010u;
goto P_0c08fea4;
P_0c08fea4: /* original 7320, guest PC 0x0c08fea4 */
if(!s->budget--) { s->failed_pc=0x0c08fea4u; return 0; }
r[3]+=0x00000020u;
goto P_0c08fea6;
P_0c08fea6: /* original f6f6, guest PC 0x0c08fea6 */
if(!s->budget--) { s->failed_pc=0x0c08fea6u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c08fea8;
P_0c08fea8: /* original e028, guest PC 0x0c08fea8 */
if(!s->budget--) { s->failed_pc=0x0c08fea8u; return 0; }
r[0]=0x00000028u;
goto P_0c08feaa;
P_0c08feaa: /* original f7cc, guest PC 0x0c08feaa */
if(!s->budget--) { s->failed_pc=0x0c08feaau; return 0; }
vf3_matrix_move(s,7,12);
goto P_0c08feac;
P_0c08feac: /* original 2f36, guest PC 0x0c08feac */
if(!s->budget--) { s->failed_pc=0x0c08feacu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08feae;
P_0c08feae: /* original 66f3, guest PC 0x0c08feae */
if(!s->budget--) { s->failed_pc=0x0c08feaeu; return 0; }
r[6]=r[15];
goto P_0c08feb0;
P_0c08feb0: /* original 65f3, guest PC 0x0c08feb0 */
if(!s->budget--) { s->failed_pc=0x0c08feb0u; return 0; }
r[5]=r[15];
goto P_0c08feb2;
P_0c08feb2: /* original d341, guest PC 0x0c08feb2 */
if(!s->budget--) { s->failed_pc=0x0c08feb2u; return 0; }
r[3]=read(ram,0x0c08ffb8u,4);
goto P_0c08feb4;
P_0c08feb4: /* original 67f3, guest PC 0x0c08feb4 */
if(!s->budget--) { s->failed_pc=0x0c08feb4u; return 0; }
r[7]=r[15];
goto P_0c08feb6;
P_0c08feb6: /* original f4f6, guest PC 0x0c08feb6 */
if(!s->budget--) { s->failed_pc=0x0c08feb6u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08feb8;
P_0c08feb8: /* original 64f3, guest PC 0x0c08feb8 */
if(!s->budget--) { s->failed_pc=0x0c08feb8u; return 0; }
r[4]=r[15];
goto P_0c08feba;
P_0c08feba: /* original 7504, guest PC 0x0c08feba */
if(!s->budget--) { s->failed_pc=0x0c08febau; return 0; }
r[5]+=0x00000004u;
goto P_0c08febc;
P_0c08febc: /* original 7608, guest PC 0x0c08febc */
if(!s->budget--) { s->failed_pc=0x0c08febcu; return 0; }
r[6]+=0x00000008u;
goto P_0c08febe;
P_0c08febe: /* original 7710, guest PC 0x0c08febe */
if(!s->budget--) { s->failed_pc=0x0c08febeu; return 0; }
r[7]+=0x00000010u;
goto P_0c08fec0;
P_0c08fec0: /* original 430b, guest PC 0x0c08fec0 */
if(!s->budget--) { s->failed_pc=0x0c08fec0u; return 0; }
target=r[3];
r[16]=code_base|0x0c08fec4u;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08fec4u) { target=s->pc; goto dispatch; }
goto P_0c08fec4;
P_0c08fec2: /* original 740c, guest PC 0x0c08fec2 */
if(!s->budget--) { s->failed_pc=0x0c08fec2u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08fec4;
P_0c08fec4: /* original 7f04, guest PC 0x0c08fec4 */
if(!s->budget--) { s->failed_pc=0x0c08fec4u; return 0; }
r[15]+=0x00000004u;
goto P_0c08fec6;
P_0c08fec6: /* original 5ef3, guest PC 0x0c08fec6 */
if(!s->budget--) { s->failed_pc=0x0c08fec6u; return 0; }
r[14]=read(ram,r[15]+12,4);
goto P_0c08fec8;
P_0c08fec8: /* original 2ee8, guest PC 0x0c08fec8 */
if(!s->budget--) { s->failed_pc=0x0c08fec8u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c08feca;
P_0c08feca: /* original 8925, guest PC 0x0c08feca */
if(!s->budget--) { s->failed_pc=0x0c08fecau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ff18; }
goto P_0c08fecc;
P_0c08fecc: /* original e008, guest PC 0x0c08fecc */
if(!s->budget--) { s->failed_pc=0x0c08feccu; return 0; }
r[0]=0x00000008u;
goto P_0c08fece;
P_0c08fece: /* original f5cc, guest PC 0x0c08fece */
if(!s->budget--) { s->failed_pc=0x0c08feceu; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c08fed0;
P_0c08fed0: /* original f6f6, guest PC 0x0c08fed0 */
if(!s->budget--) { s->failed_pc=0x0c08fed0u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c08fed2;
P_0c08fed2: /* original e004, guest PC 0x0c08fed2 */
if(!s->budget--) { s->failed_pc=0x0c08fed2u; return 0; }
r[0]=0x00000004u;
goto P_0c08fed4;
P_0c08fed4: /* original f7f6, guest PC 0x0c08fed4 */
if(!s->budget--) { s->failed_pc=0x0c08fed4u; return 0; }
vf3_matrix_load(s,ram,7,r[15]+r[0]);
goto P_0c08fed6;
P_0c08fed6: /* original e010, guest PC 0x0c08fed6 */
if(!s->budget--) { s->failed_pc=0x0c08fed6u; return 0; }
r[0]=0x00000010u;
goto P_0c08fed8;
P_0c08fed8: /* original f4f6, guest PC 0x0c08fed8 */
if(!s->budget--) { s->failed_pc=0x0c08fed8u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08feda;
P_0c08feda: /* original c738, guest PC 0x0c08feda */
if(!s->budget--) { s->failed_pc=0x0c08fedau; return 0; }
r[0]=code_base|0x0008ffbcu;
goto P_0c08fedc;
P_0c08fedc: /* original f571, guest PC 0x0c08fedc */
if(!s->budget--) { s->failed_pc=0x0c08fedcu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'-');
goto P_0c08fede;
P_0c08fede: /* original f208, guest PC 0x0c08fede */
if(!s->budget--) { s->failed_pc=0x0c08fedeu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c08fee0;
P_0c08fee0: /* original f461, guest PC 0x0c08fee0 */
if(!s->budget--) { s->failed_pc=0x0c08fee0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c08fee2;
P_0c08fee2: /* original f05c, guest PC 0x0c08fee2 */
if(!s->budget--) { s->failed_pc=0x0c08fee2u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c08fee4;
P_0c08fee4: /* original f84c, guest PC 0x0c08fee4 */
if(!s->budget--) { s->failed_pc=0x0c08fee4u; return 0; }
vf3_matrix_move(s,8,4);
goto P_0c08fee6;
P_0c08fee6: /* original f842, guest PC 0x0c08fee6 */
if(!s->budget--) { s->failed_pc=0x0c08fee6u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'*');
goto P_0c08fee8;
P_0c08fee8: /* original f85e, guest PC 0x0c08fee8 */
if(!s->budget--) { s->failed_pc=0x0c08fee8u; return 0; }
fr[8]=vf3_fpu_mac(fr[0],fr[5],fr[8],r[18]);
goto P_0c08feea;
P_0c08feea: /* original f285, guest PC 0x0c08feea */
if(!s->budget--) { s->failed_pc=0x0c08feeau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[8]))!=0);
goto P_0c08feec;
P_0c08feec: /* original 8b01, guest PC 0x0c08feec */
if(!s->budget--) { s->failed_pc=0x0c08feecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08fef2; }
goto P_0c08feee;
P_0c08feee: /* original a002, guest PC 0x0c08feee */
if(!s->budget--) { s->failed_pc=0x0c08feeeu; return 0; }
fr[3]=0;
goto P_0c08fef6;
P_0c08fef0: /* original f38d, guest PC 0x0c08fef0 */
if(!s->budget--) { s->failed_pc=0x0c08fef0u; return 0; }
fr[3]=0;
goto P_0c08fef2;
P_0c08fef2: /* original f38c, guest PC 0x0c08fef2 */
if(!s->budget--) { s->failed_pc=0x0c08fef2u; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c08fef4;
P_0c08fef4: /* original f37d, guest PC 0x0c08fef4 */
if(!s->budget--) { s->failed_pc=0x0c08fef4u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c08fef6;
P_0c08fef6: /* original c732, guest PC 0x0c08fef6 */
if(!s->budget--) { s->failed_pc=0x0c08fef6u; return 0; }
r[0]=code_base|0x0008ffc0u;
goto P_0c08fef8;
P_0c08fef8: /* original ff3a, guest PC 0x0c08fef8 */
if(!s->budget--) { s->failed_pc=0x0c08fef8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08fefa;
P_0c08fefa: /* original f24c, guest PC 0x0c08fefa */
if(!s->budget--) { s->failed_pc=0x0c08fefau; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c08fefc;
P_0c08fefc: /* original f43c, guest PC 0x0c08fefc */
if(!s->budget--) { s->failed_pc=0x0c08fefcu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c08fefe;
P_0c08fefe: /* original f422, guest PC 0x0c08fefe */
if(!s->budget--) { s->failed_pc=0x0c08fefeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'*');
goto P_0c08ff00;
P_0c08ff00: /* original f25c, guest PC 0x0c08ff00 */
if(!s->budget--) { s->failed_pc=0x0c08ff00u; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c08ff02;
P_0c08ff02: /* original f53c, guest PC 0x0c08ff02 */
if(!s->budget--) { s->failed_pc=0x0c08ff02u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c08ff04;
P_0c08ff04: /* original f522, guest PC 0x0c08ff04 */
if(!s->budget--) { s->failed_pc=0x0c08ff04u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'*');
goto P_0c08ff06;
P_0c08ff06: /* original f808, guest PC 0x0c08ff06 */
if(!s->budget--) { s->failed_pc=0x0c08ff06u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c08ff08;
P_0c08ff08: /* original e008, guest PC 0x0c08ff08 */
if(!s->budget--) { s->failed_pc=0x0c08ff08u; return 0; }
r[0]=0x00000008u;
goto P_0c08ff0a;
P_0c08ff0a: /* original f482, guest PC 0x0c08ff0a */
if(!s->budget--) { s->failed_pc=0x0c08ff0au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'*');
goto P_0c08ff0c;
P_0c08ff0c: /* original f582, guest PC 0x0c08ff0c */
if(!s->budget--) { s->failed_pc=0x0c08ff0cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'*');
goto P_0c08ff0e;
P_0c08ff0e: /* original f640, guest PC 0x0c08ff0e */
if(!s->budget--) { s->failed_pc=0x0c08ff0eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'+');
goto P_0c08ff10;
P_0c08ff10: /* original f750, guest PC 0x0c08ff10 */
if(!s->budget--) { s->failed_pc=0x0c08ff10u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'+');
goto P_0c08ff12;
P_0c08ff12: /* original ff67, guest PC 0x0c08ff12 */
if(!s->budget--) { s->failed_pc=0x0c08ff12u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c08ff14;
P_0c08ff14: /* original e004, guest PC 0x0c08ff14 */
if(!s->budget--) { s->failed_pc=0x0c08ff14u; return 0; }
r[0]=0x00000004u;
goto P_0c08ff16;
P_0c08ff16: /* original ff77, guest PC 0x0c08ff16 */
if(!s->budget--) { s->failed_pc=0x0c08ff16u; return 0; }
vf3_matrix_store(s,ram,7,r[15]+r[0]);
goto P_0c08ff18;
P_0c08ff18: /* original 934c, guest PC 0x0c08ff18 */
if(!s->budget--) { s->failed_pc=0x0c08ff18u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ffb4u,2);
goto P_0c08ff1a;
P_0c08ff1a: /* original 2d38, guest PC 0x0c08ff1a */
if(!s->budget--) { s->failed_pc=0x0c08ff1au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[3])==0)!=0);
goto P_0c08ff1c;
P_0c08ff1c: /* original 8907, guest PC 0x0c08ff1c */
if(!s->budget--) { s->failed_pc=0x0c08ff1cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ff2e; }
goto P_0c08ff1e;
P_0c08ff1e: /* original e004, guest PC 0x0c08ff1e */
if(!s->budget--) { s->failed_pc=0x0c08ff1eu; return 0; }
r[0]=0x00000004u;
goto P_0c08ff20;
P_0c08ff20: /* original d328, guest PC 0x0c08ff20 */
if(!s->budget--) { s->failed_pc=0x0c08ff20u; return 0; }
r[3]=read(ram,0x0c08ffc4u,4);
goto P_0c08ff22;
P_0c08ff22: /* original f5f6, guest PC 0x0c08ff22 */
if(!s->budget--) { s->failed_pc=0x0c08ff22u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c08ff24;
P_0c08ff24: /* original e008, guest PC 0x0c08ff24 */
if(!s->budget--) { s->failed_pc=0x0c08ff24u; return 0; }
r[0]=0x00000008u;
goto P_0c08ff26;
P_0c08ff26: /* original 430b, guest PC 0x0c08ff26 */
if(!s->budget--) { s->failed_pc=0x0c08ff26u; return 0; }
target=r[3];
r[16]=code_base|0x0c08ff2au;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ff2au) { target=s->pc; goto dispatch; }
goto P_0c08ff2a;
P_0c08ff28: /* original f4f6, guest PC 0x0c08ff28 */
if(!s->budget--) { s->failed_pc=0x0c08ff28u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08ff2a;
P_0c08ff2a: /* original a007, guest PC 0x0c08ff2a */
if(!s->budget--) { s->failed_pc=0x0c08ff2au; return 0; }
goto P_0c08ff3c;
P_0c08ff2c: /* original 0009, guest PC 0x0c08ff2c */
if(!s->budget--) { s->failed_pc=0x0c08ff2cu; return 0; }
goto P_0c08ff2e;
P_0c08ff2e: /* original e004, guest PC 0x0c08ff2e */
if(!s->budget--) { s->failed_pc=0x0c08ff2eu; return 0; }
r[0]=0x00000004u;
goto P_0c08ff30;
P_0c08ff30: /* original d325, guest PC 0x0c08ff30 */
if(!s->budget--) { s->failed_pc=0x0c08ff30u; return 0; }
r[3]=read(ram,0x0c08ffc8u,4);
goto P_0c08ff32;
P_0c08ff32: /* original f5f8, guest PC 0x0c08ff32 */
if(!s->budget--) { s->failed_pc=0x0c08ff32u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c08ff34;
P_0c08ff34: /* original f6f6, guest PC 0x0c08ff34 */
if(!s->budget--) { s->failed_pc=0x0c08ff34u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c08ff36;
P_0c08ff36: /* original e008, guest PC 0x0c08ff36 */
if(!s->budget--) { s->failed_pc=0x0c08ff36u; return 0; }
r[0]=0x00000008u;
goto P_0c08ff38;
P_0c08ff38: /* original 430b, guest PC 0x0c08ff38 */
if(!s->budget--) { s->failed_pc=0x0c08ff38u; return 0; }
target=r[3];
r[16]=code_base|0x0c08ff3cu;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ff3cu) { target=s->pc; goto dispatch; }
goto P_0c08ff3c;
P_0c08ff3a: /* original f4f6, guest PC 0x0c08ff3a */
if(!s->budget--) { s->failed_pc=0x0c08ff3au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08ff3c;
P_0c08ff3c: /* original e01c, guest PC 0x0c08ff3c */
if(!s->budget--) { s->failed_pc=0x0c08ff3cu; return 0; }
r[0]=0x0000001cu;
goto P_0c08ff3e;
P_0c08ff3e: /* original ff0a, guest PC 0x0c08ff3e */
if(!s->budget--) { s->failed_pc=0x0c08ff3eu; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c08ff40;
P_0c08ff40: /* original f30c, guest PC 0x0c08ff40 */
if(!s->budget--) { s->failed_pc=0x0c08ff40u; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c08ff42;
P_0c08ff42: /* original ff37, guest PC 0x0c08ff42 */
if(!s->budget--) { s->failed_pc=0x0c08ff42u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08ff44;
P_0c08ff44: /* original e010, guest PC 0x0c08ff44 */
if(!s->budget--) { s->failed_pc=0x0c08ff44u; return 0; }
r[0]=0x00000010u;
goto P_0c08ff46;
P_0c08ff46: /* original f3f6, guest PC 0x0c08ff46 */
if(!s->budget--) { s->failed_pc=0x0c08ff46u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08ff48;
P_0c08ff48: /* original e008, guest PC 0x0c08ff48 */
if(!s->budget--) { s->failed_pc=0x0c08ff48u; return 0; }
r[0]=0x00000008u;
goto P_0c08ff4a;
P_0c08ff4a: /* original ff37, guest PC 0x0c08ff4a */
if(!s->budget--) { s->failed_pc=0x0c08ff4au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08ff4c;
P_0c08ff4c: /* original e004, guest PC 0x0c08ff4c */
if(!s->budget--) { s->failed_pc=0x0c08ff4cu; return 0; }
r[0]=0x00000004u;
goto P_0c08ff4e;
P_0c08ff4e: /* original ffc7, guest PC 0x0c08ff4e */
if(!s->budget--) { s->failed_pc=0x0c08ff4eu; return 0; }
vf3_matrix_store(s,ram,12,r[15]+r[0]);
goto P_0c08ff50;
P_0c08ff50: /* original e008, guest PC 0x0c08ff50 */
if(!s->budget--) { s->failed_pc=0x0c08ff50u; return 0; }
r[0]=0x00000008u;
goto P_0c08ff52;
P_0c08ff52: /* original d31c, guest PC 0x0c08ff52 */
if(!s->budget--) { s->failed_pc=0x0c08ff52u; return 0; }
r[3]=read(ram,0x0c08ffc4u,4);
goto P_0c08ff54;
P_0c08ff54: /* original f5cc, guest PC 0x0c08ff54 */
if(!s->budget--) { s->failed_pc=0x0c08ff54u; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c08ff56;
P_0c08ff56: /* original 430b, guest PC 0x0c08ff56 */
if(!s->budget--) { s->failed_pc=0x0c08ff56u; return 0; }
target=r[3];
r[16]=code_base|0x0c08ff5au;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ff5au) { target=s->pc; goto dispatch; }
goto P_0c08ff5a;
P_0c08ff58: /* original f4f6, guest PC 0x0c08ff58 */
if(!s->budget--) { s->failed_pc=0x0c08ff58u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08ff5a;
P_0c08ff5a: /* original e01c, guest PC 0x0c08ff5a */
if(!s->budget--) { s->failed_pc=0x0c08ff5au; return 0; }
r[0]=0x0000001cu;
goto P_0c08ff5c;
P_0c08ff5c: /* original ff0a, guest PC 0x0c08ff5c */
if(!s->budget--) { s->failed_pc=0x0c08ff5cu; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c08ff5e;
P_0c08ff5e: /* original f3f6, guest PC 0x0c08ff5e */
if(!s->budget--) { s->failed_pc=0x0c08ff5eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08ff60;
P_0c08ff60: /* original f28d, guest PC 0x0c08ff60 */
if(!s->budget--) { s->failed_pc=0x0c08ff60u; return 0; }
fr[2]=0;
goto P_0c08ff62;
P_0c08ff62: /* original f3f1, guest PC 0x0c08ff62 */
if(!s->budget--) { s->failed_pc=0x0c08ff62u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'-');
goto P_0c08ff64;
P_0c08ff64: /* original f235, guest PC 0x0c08ff64 */
if(!s->budget--) { s->failed_pc=0x0c08ff64u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c08ff66;
P_0c08ff66: /* original 8d03, guest PC 0x0c08ff66 */
if(!s->budget--) { s->failed_pc=0x0c08ff66u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,0);
if(cond) { goto P_0c08ff70; }
goto P_0c08ff6a;
P_0c08ff68: /* original f40c, guest PC 0x0c08ff68 */
if(!s->budget--) { s->failed_pc=0x0c08ff68u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c08ff6a;
P_0c08ff6a: /* original e01c, guest PC 0x0c08ff6a */
if(!s->budget--) { s->failed_pc=0x0c08ff6au; return 0; }
r[0]=0x0000001cu;
goto P_0c08ff6c;
P_0c08ff6c: /* original a001, guest PC 0x0c08ff6c */
if(!s->budget--) { s->failed_pc=0x0c08ff6cu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c08ff72;
P_0c08ff6e: /* original f5f6, guest PC 0x0c08ff6e */
if(!s->budget--) { s->failed_pc=0x0c08ff6eu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c08ff70;
P_0c08ff70: /* original f5fc, guest PC 0x0c08ff70 */
if(!s->budget--) { s->failed_pc=0x0c08ff70u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08ff72;
P_0c08ff72: /* original f34c, guest PC 0x0c08ff72 */
if(!s->budget--) { s->failed_pc=0x0c08ff72u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08ff74;
P_0c08ff74: /* original f3f1, guest PC 0x0c08ff74 */
if(!s->budget--) { s->failed_pc=0x0c08ff74u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'-');
goto P_0c08ff76;
P_0c08ff76: /* original f28d, guest PC 0x0c08ff76 */
if(!s->budget--) { s->failed_pc=0x0c08ff76u; return 0; }
fr[2]=0;
goto P_0c08ff78;
P_0c08ff78: /* original f235, guest PC 0x0c08ff78 */
if(!s->budget--) { s->failed_pc=0x0c08ff78u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c08ff7a;
P_0c08ff7a: /* original 8b00, guest PC 0x0c08ff7a */
if(!s->budget--) { s->failed_pc=0x0c08ff7au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08ff7e; }
goto P_0c08ff7c;
P_0c08ff7c: /* original f4fc, guest PC 0x0c08ff7c */
if(!s->budget--) { s->failed_pc=0x0c08ff7cu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08ff7e;
P_0c08ff7e: /* original d313, guest PC 0x0c08ff7e */
if(!s->budget--) { s->failed_pc=0x0c08ff7eu; return 0; }
r[3]=read(ram,0x0c08ffccu,4);
goto P_0c08ff80;
P_0c08ff80: /* original e40f, guest PC 0x0c08ff80 */
if(!s->budget--) { s->failed_pc=0x0c08ff80u; return 0; }
r[4]=0x0000000fu;
goto P_0c08ff82;
P_0c08ff82: /* original 6030, guest PC 0x0c08ff82 */
if(!s->budget--) { s->failed_pc=0x0c08ff82u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c08ff84;
P_0c08ff84: /* original 600c, guest PC 0x0c08ff84 */
if(!s->budget--) { s->failed_pc=0x0c08ff84u; return 0; }
r[0]=r[0]&255u;
goto P_0c08ff86;
P_0c08ff86: /* original 2409, guest PC 0x0c08ff86 */
if(!s->budget--) { s->failed_pc=0x0c08ff86u; return 0; }
r[4]&=r[0];
goto P_0c08ff88;
P_0c08ff88: /* original 6043, guest PC 0x0c08ff88 */
if(!s->budget--) { s->failed_pc=0x0c08ff88u; return 0; }
r[0]=r[4];
goto P_0c08ff8a;
P_0c08ff8a: /* original 880b, guest PC 0x0c08ff8a */
if(!s->budget--) { s->failed_pc=0x0c08ff8au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c08ff8c;
P_0c08ff8c: /* original 8b01, guest PC 0x0c08ff8c */
if(!s->budget--) { s->failed_pc=0x0c08ff8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08ff92; }
goto P_0c08ff8e;
P_0c08ff8e: /* original f4fc, guest PC 0x0c08ff8e */
if(!s->budget--) { s->failed_pc=0x0c08ff8eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08ff90;
P_0c08ff90: /* original f5fc, guest PC 0x0c08ff90 */
if(!s->budget--) { s->failed_pc=0x0c08ff90u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08ff92;
P_0c08ff92: /* original fd50, guest PC 0x0c08ff92 */
if(!s->budget--) { s->failed_pc=0x0c08ff92u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[5],r[18],'+');
goto P_0c08ff94;
P_0c08ff94: /* original 1fe3, guest PC 0x0c08ff94 */
if(!s->budget--) { s->failed_pc=0x0c08ff94u; return 0; }
write(ram,r[15]+12,r[14],4);
goto P_0c08ff96;
P_0c08ff96: /* original 53f6, guest PC 0x0c08ff96 */
if(!s->budget--) { s->failed_pc=0x0c08ff96u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c08ff98;
P_0c08ff98: /* original fe40, guest PC 0x0c08ff98 */
if(!s->budget--) { s->failed_pc=0x0c08ff98u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'+');
goto P_0c08ff9a;
P_0c08ff9a: /* original f3da, guest PC 0x0c08ff9a */
if(!s->budget--) { s->failed_pc=0x0c08ff9au; return 0; }
vf3_matrix_store(s,ram,13,r[3]);
goto P_0c08ff9c;
P_0c08ff9c: /* original 53f5, guest PC 0x0c08ff9c */
if(!s->budget--) { s->failed_pc=0x0c08ff9cu; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c08ff9e;
P_0c08ff9e: /* original f3ea, guest PC 0x0c08ff9e */
if(!s->budget--) { s->failed_pc=0x0c08ff9eu; return 0; }
vf3_matrix_store(s,ram,14,r[3]);
goto P_0c08ffa0;
P_0c08ffa0: /* original 50f3, guest PC 0x0c08ffa0 */
if(!s->budget--) { s->failed_pc=0x0c08ffa0u; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c08ffa2;
P_0c08ffa2: /* original 7f28, guest PC 0x0c08ffa2 */
if(!s->budget--) { s->failed_pc=0x0c08ffa2u; return 0; }
r[15]+=0x00000028u;
goto P_0c08ffa4;
P_0c08ffa4: /* original 4f26, guest PC 0x0c08ffa4 */
if(!s->budget--) { s->failed_pc=0x0c08ffa4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08ffa6;
P_0c08ffa6: /* original fcf9, guest PC 0x0c08ffa6 */
if(!s->budget--) { s->failed_pc=0x0c08ffa6u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08ffa8;
P_0c08ffa8: /* original fdf9, guest PC 0x0c08ffa8 */
if(!s->budget--) { s->failed_pc=0x0c08ffa8u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08ffaa;
P_0c08ffaa: /* original fef9, guest PC 0x0c08ffaa */
if(!s->budget--) { s->failed_pc=0x0c08ffaau; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08ffac;
P_0c08ffac: /* original fff9, guest PC 0x0c08ffac */
if(!s->budget--) { s->failed_pc=0x0c08ffacu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08ffae;
P_0c08ffae: /* original 6df6, guest PC 0x0c08ffae */
if(!s->budget--) { s->failed_pc=0x0c08ffaeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08ffb0;
P_0c08ffb0: /* original 000b, guest PC 0x0c08ffb0 */
if(!s->budget--) { s->failed_pc=0x0c08ffb0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08ffb2: /* original 6ef6, guest PC 0x0c08ffb2 */
if(!s->budget--) { s->failed_pc=0x0c08ffb2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08ffb4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08ffb4u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
