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
int vf3_away_batch7_adapter_10(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05bb38u: goto P_0c05bb38;
case 0x0c05bb3au: goto P_0c05bb3a;
case 0x0c05bb3cu: goto P_0c05bb3c;
case 0x0c05bb3eu: goto P_0c05bb3e;
case 0x0c05bb40u: goto P_0c05bb40;
case 0x0c05bb42u: goto P_0c05bb42;
case 0x0c05bb44u: goto P_0c05bb44;
case 0x0c05bb46u: goto P_0c05bb46;
case 0x0c05bb48u: goto P_0c05bb48;
case 0x0c05bb4au: goto P_0c05bb4a;
case 0x0c05bb4cu: goto P_0c05bb4c;
case 0x0c05bb4eu: goto P_0c05bb4e;
case 0x0c05bb50u: goto P_0c05bb50;
case 0x0c05bb52u: goto P_0c05bb52;
case 0x0c05bb54u: goto P_0c05bb54;
case 0x0c05bb56u: goto P_0c05bb56;
case 0x0c05bb58u: goto P_0c05bb58;
case 0x0c05bb5au: goto P_0c05bb5a;
case 0x0c05bb5cu: goto P_0c05bb5c;
case 0x0c05bb5eu: goto P_0c05bb5e;
case 0x0c05bb60u: goto P_0c05bb60;
case 0x0c05bb62u: goto P_0c05bb62;
case 0x0c05bb64u: goto P_0c05bb64;
case 0x0c05bb66u: goto P_0c05bb66;
case 0x0c05bb68u: goto P_0c05bb68;
case 0x0c05bb6au: goto P_0c05bb6a;
case 0x0c05bb6cu: goto P_0c05bb6c;
case 0x0c05bb6eu: goto P_0c05bb6e;
case 0x0c05bb70u: goto P_0c05bb70;
case 0x0c05bb72u: goto P_0c05bb72;
case 0x0c05bb74u: goto P_0c05bb74;
case 0x0c05bb76u: goto P_0c05bb76;
case 0x0c05bb78u: goto P_0c05bb78;
case 0x0c05bb7au: goto P_0c05bb7a;
case 0x0c05bb7cu: goto P_0c05bb7c;
case 0x0c05bb7eu: goto P_0c05bb7e;
case 0x0c05bb80u: goto P_0c05bb80;
case 0x0c05bb82u: goto P_0c05bb82;
case 0x0c05bb84u: goto P_0c05bb84;
case 0x0c05bb86u: goto P_0c05bb86;
case 0x0c05bb88u: goto P_0c05bb88;
case 0x0c05bb8au: goto P_0c05bb8a;
case 0x0c05bb8cu: goto P_0c05bb8c;
case 0x0c05bb8eu: goto P_0c05bb8e;
case 0x0c05bb90u: goto P_0c05bb90;
case 0x0c05bb92u: goto P_0c05bb92;
case 0x0c05bb94u: goto P_0c05bb94;
case 0x0c05bb96u: goto P_0c05bb96;
case 0x0c05bb98u: goto P_0c05bb98;
case 0x0c05bb9au: goto P_0c05bb9a;
case 0x0c05bb9cu: goto P_0c05bb9c;
case 0x0c05bb9eu: goto P_0c05bb9e;
case 0x0c05bba0u: goto P_0c05bba0;
case 0x0c05bba2u: goto P_0c05bba2;
case 0x0c05bba4u: goto P_0c05bba4;
case 0x0c05bba6u: goto P_0c05bba6;
case 0x0c05bba8u: goto P_0c05bba8;
case 0x0c05bbaau: goto P_0c05bbaa;
case 0x0c05bbacu: goto P_0c05bbac;
case 0x0c05bbaeu: goto P_0c05bbae;
case 0x0c05bbb0u: goto P_0c05bbb0;
case 0x0c05bbb2u: goto P_0c05bbb2;
case 0x0c05bbb4u: goto P_0c05bbb4;
case 0x0c05bbb6u: goto P_0c05bbb6;
case 0x0c05bbb8u: goto P_0c05bbb8;
case 0x0c05bbbau: goto P_0c05bbba;
case 0x0c05bbbcu: goto P_0c05bbbc;
case 0x0c05bbbeu: goto P_0c05bbbe;
case 0x0c05bbc0u: goto P_0c05bbc0;
case 0x0c05bbc2u: goto P_0c05bbc2;
case 0x0c05bbc4u: goto P_0c05bbc4;
case 0x0c05bbc6u: goto P_0c05bbc6;
case 0x0c05bbc8u: goto P_0c05bbc8;
case 0x0c05bbcau: goto P_0c05bbca;
case 0x0c05bbccu: goto P_0c05bbcc;
case 0x0c05bbceu: goto P_0c05bbce;
case 0x0c05bbd0u: goto P_0c05bbd0;
case 0x0c05bbd2u: goto P_0c05bbd2;
case 0x0c05bbd4u: goto P_0c05bbd4;
case 0x0c05bbd6u: goto P_0c05bbd6;
case 0x0c05bbd8u: goto P_0c05bbd8;
case 0x0c05bbdau: goto P_0c05bbda;
case 0x0c05bbdcu: goto P_0c05bbdc;
case 0x0c05bbdeu: goto P_0c05bbde;
case 0x0c05bbe0u: goto P_0c05bbe0;
case 0x0c05bbe2u: goto P_0c05bbe2;
case 0x0c05bbe4u: goto P_0c05bbe4;
case 0x0c05bbe6u: goto P_0c05bbe6;
case 0x0c05bbe8u: goto P_0c05bbe8;
case 0x0c05bbeau: goto P_0c05bbea;
case 0x0c05bbecu: goto P_0c05bbec;
case 0x0c05bbeeu: goto P_0c05bbee;
case 0x0c05bbf0u: goto P_0c05bbf0;
case 0x0c05bbf2u: goto P_0c05bbf2;
case 0x0c05bbf4u: goto P_0c05bbf4;
case 0x0c05bbf6u: goto P_0c05bbf6;
case 0x0c05bbf8u: goto P_0c05bbf8;
case 0x0c05bbfau: goto P_0c05bbfa;
case 0x0c05bbfcu: goto P_0c05bbfc;
case 0x0c05bbfeu: goto P_0c05bbfe;
case 0x0c05bc00u: goto P_0c05bc00;
case 0x0c05bc02u: goto P_0c05bc02;
case 0x0c05bc04u: goto P_0c05bc04;
case 0x0c05bc06u: goto P_0c05bc06;
case 0x0c05bc08u: goto P_0c05bc08;
case 0x0c05bc0au: goto P_0c05bc0a;
case 0x0c05bc0cu: goto P_0c05bc0c;
case 0x0c05bc0eu: goto P_0c05bc0e;
case 0x0c05bc10u: goto P_0c05bc10;
case 0x0c05bc12u: goto P_0c05bc12;
case 0x0c05bc14u: goto P_0c05bc14;
case 0x0c05bc16u: goto P_0c05bc16;
case 0x0c05bc18u: goto P_0c05bc18;
case 0x0c05bc1au: goto P_0c05bc1a;
case 0x0c05bc1cu: goto P_0c05bc1c;
case 0x0c05bc1eu: goto P_0c05bc1e;
case 0x0c05bc20u: goto P_0c05bc20;
case 0x0c05bc22u: goto P_0c05bc22;
case 0x0c05bc24u: goto P_0c05bc24;
case 0x0c05bc26u: goto P_0c05bc26;
case 0x0c05bc28u: goto P_0c05bc28;
case 0x0c05bc2au: goto P_0c05bc2a;
case 0x0c05bc2cu: goto P_0c05bc2c;
case 0x0c05bc2eu: goto P_0c05bc2e;
case 0x0c05bc30u: goto P_0c05bc30;
case 0x0c05bc32u: goto P_0c05bc32;
case 0x0c05bc34u: goto P_0c05bc34;
case 0x0c05bc36u: goto P_0c05bc36;
case 0x0c05bc38u: goto P_0c05bc38;
case 0x0c05bc3au: goto P_0c05bc3a;
case 0x0c05bc3cu: goto P_0c05bc3c;
case 0x0c05bc3eu: goto P_0c05bc3e;
case 0x0c05bc40u: goto P_0c05bc40;
case 0x0c05bc42u: goto P_0c05bc42;
case 0x0c05bc44u: goto P_0c05bc44;
case 0x0c05bc46u: goto P_0c05bc46;
case 0x0c05bc48u: goto P_0c05bc48;
case 0x0c05bc4au: goto P_0c05bc4a;
case 0x0c05bc4cu: goto P_0c05bc4c;
case 0x0c05bc4eu: goto P_0c05bc4e;
case 0x0c05bc50u: goto P_0c05bc50;
case 0x0c05bc52u: goto P_0c05bc52;
case 0x0c05bc54u: goto P_0c05bc54;
case 0x0c05bc56u: goto P_0c05bc56;
case 0x0c05bc58u: goto P_0c05bc58;
case 0x0c05bc5au: goto P_0c05bc5a;
case 0x0c05bc5cu: goto P_0c05bc5c;
case 0x0c05bc5eu: goto P_0c05bc5e;
case 0x0c05bc60u: goto P_0c05bc60;
case 0x0c05bc62u: goto P_0c05bc62;
case 0x0c05bc64u: goto P_0c05bc64;
case 0x0c05bc66u: goto P_0c05bc66;
case 0x0c05bc68u: goto P_0c05bc68;
case 0x0c05bc6au: goto P_0c05bc6a;
case 0x0c05bc6cu: goto P_0c05bc6c;
case 0x0c05bc6eu: goto P_0c05bc6e;
case 0x0c05bc70u: goto P_0c05bc70;
case 0x0c05bc72u: goto P_0c05bc72;
case 0x0c05bc74u: goto P_0c05bc74;
case 0x0c05bc76u: goto P_0c05bc76;
case 0x0c05bc78u: goto P_0c05bc78;
case 0x0c05bc7au: goto P_0c05bc7a;
case 0x0c05bc7cu: goto P_0c05bc7c;
case 0x0c05bc7eu: goto P_0c05bc7e;
case 0x0c05bc80u: goto P_0c05bc80;
case 0x0c05bc82u: goto P_0c05bc82;
case 0x0c05bca8u: goto P_0c05bca8;
case 0x0c05bcaau: goto P_0c05bcaa;
case 0x0c05bcacu: goto P_0c05bcac;
case 0x0c05bcaeu: goto P_0c05bcae;
case 0x0c05bcb0u: goto P_0c05bcb0;
case 0x0c05bcb2u: goto P_0c05bcb2;
case 0x0c05bcb4u: goto P_0c05bcb4;
case 0x0c05bcb6u: goto P_0c05bcb6;
case 0x0c05bcb8u: goto P_0c05bcb8;
case 0x0c05bcbau: goto P_0c05bcba;
case 0x0c05bcbcu: goto P_0c05bcbc;
case 0x0c05bcbeu: goto P_0c05bcbe;
case 0x0c05bcc0u: goto P_0c05bcc0;
case 0x0c05bcc2u: goto P_0c05bcc2;
case 0x0c05bcc4u: goto P_0c05bcc4;
case 0x0c05bcc6u: goto P_0c05bcc6;
case 0x0c05bcc8u: goto P_0c05bcc8;
case 0x0c05bccau: goto P_0c05bcca;
case 0x0c05bcccu: goto P_0c05bccc;
case 0x0c05bcceu: goto P_0c05bcce;
case 0x0c05bcd0u: goto P_0c05bcd0;
case 0x0c05bcd2u: goto P_0c05bcd2;
case 0x0c05bcd4u: goto P_0c05bcd4;
case 0x0c05bcd6u: goto P_0c05bcd6;
case 0x0c05bcd8u: goto P_0c05bcd8;
case 0x0c05bcdau: goto P_0c05bcda;
case 0x0c05bcdcu: goto P_0c05bcdc;
case 0x0c05bcdeu: goto P_0c05bcde;
case 0x0c05bce0u: goto P_0c05bce0;
case 0x0c05bce2u: goto P_0c05bce2;
case 0x0c05bce4u: goto P_0c05bce4;
case 0x0c05bce6u: goto P_0c05bce6;
case 0x0c05bce8u: goto P_0c05bce8;
case 0x0c05bceau: goto P_0c05bcea;
case 0x0c05bcecu: goto P_0c05bcec;
case 0x0c05bceeu: goto P_0c05bcee;
case 0x0c05bcf0u: goto P_0c05bcf0;
case 0x0c05bcf2u: goto P_0c05bcf2;
case 0x0c05bcf4u: goto P_0c05bcf4;
case 0x0c05bcf6u: goto P_0c05bcf6;
case 0x0c05bcf8u: goto P_0c05bcf8;
case 0x0c05bcfau: goto P_0c05bcfa;
case 0x0c05bcfcu: goto P_0c05bcfc;
case 0x0c05bcfeu: goto P_0c05bcfe;
case 0x0c05bd00u: goto P_0c05bd00;
case 0x0c05bd02u: goto P_0c05bd02;
case 0x0c05bd04u: goto P_0c05bd04;
case 0x0c05bd06u: goto P_0c05bd06;
case 0x0c05bd08u: goto P_0c05bd08;
case 0x0c05bd0au: goto P_0c05bd0a;
case 0x0c05bd0cu: goto P_0c05bd0c;
case 0x0c05bd0eu: goto P_0c05bd0e;
case 0x0c05bd10u: goto P_0c05bd10;
case 0x0c05bd12u: goto P_0c05bd12;
case 0x0c05bd14u: goto P_0c05bd14;
case 0x0c05bd16u: goto P_0c05bd16;
case 0x0c05bd18u: goto P_0c05bd18;
case 0x0c05bd1au: goto P_0c05bd1a;
case 0x0c05bd1cu: goto P_0c05bd1c;
case 0x0c05bd1eu: goto P_0c05bd1e;
case 0x0c05bd20u: goto P_0c05bd20;
case 0x0c05bd22u: goto P_0c05bd22;
case 0x0c05bd24u: goto P_0c05bd24;
case 0x0c05bd26u: goto P_0c05bd26;
case 0x0c05bd28u: goto P_0c05bd28;
case 0x0c05bd2au: goto P_0c05bd2a;
case 0x0c05bd2cu: goto P_0c05bd2c;
case 0x0c05bd2eu: goto P_0c05bd2e;
case 0x0c05bd30u: goto P_0c05bd30;
case 0x0c05bd32u: goto P_0c05bd32;
case 0x0c05bd34u: goto P_0c05bd34;
case 0x0c05bd36u: goto P_0c05bd36;
case 0x0c05bd38u: goto P_0c05bd38;
case 0x0c05bd3au: goto P_0c05bd3a;
case 0x0c05bd3cu: goto P_0c05bd3c;
case 0x0c05bd3eu: goto P_0c05bd3e;
case 0x0c05bd40u: goto P_0c05bd40;
case 0x0c05bd42u: goto P_0c05bd42;
case 0x0c05bd44u: goto P_0c05bd44;
case 0x0c05bd46u: goto P_0c05bd46;
case 0x0c05bd48u: goto P_0c05bd48;
case 0x0c05bd4au: goto P_0c05bd4a;
case 0x0c05bd4cu: goto P_0c05bd4c;
case 0x0c05bd4eu: goto P_0c05bd4e;
case 0x0c05bd50u: goto P_0c05bd50;
case 0x0c05bd52u: goto P_0c05bd52;
case 0x0c05bd54u: goto P_0c05bd54;
case 0x0c05bd56u: goto P_0c05bd56;
case 0x0c05bd58u: goto P_0c05bd58;
case 0x0c05bd5au: goto P_0c05bd5a;
case 0x0c05bd5cu: goto P_0c05bd5c;
case 0x0c05bd5eu: goto P_0c05bd5e;
case 0x0c05bd60u: goto P_0c05bd60;
case 0x0c05bd62u: goto P_0c05bd62;
case 0x0c05bd64u: goto P_0c05bd64;
case 0x0c05bd66u: goto P_0c05bd66;
case 0x0c05bd68u: goto P_0c05bd68;
case 0x0c05bd6au: goto P_0c05bd6a;
case 0x0c05bd6cu: goto P_0c05bd6c;
case 0x0c05bd6eu: goto P_0c05bd6e;
case 0x0c05bd70u: goto P_0c05bd70;
case 0x0c05bd72u: goto P_0c05bd72;
case 0x0c05bd74u: goto P_0c05bd74;
case 0x0c05bd76u: goto P_0c05bd76;
case 0x0c05bd78u: goto P_0c05bd78;
case 0x0c05bd7au: goto P_0c05bd7a;
case 0x0c05bd7cu: goto P_0c05bd7c;
case 0x0c05bd7eu: goto P_0c05bd7e;
case 0x0c05bd80u: goto P_0c05bd80;
case 0x0c05bd82u: goto P_0c05bd82;
case 0x0c05bd84u: goto P_0c05bd84;
case 0x0c05bd86u: goto P_0c05bd86;
case 0x0c05bd88u: goto P_0c05bd88;
case 0x0c05bd8au: goto P_0c05bd8a;
case 0x0c05bd8cu: goto P_0c05bd8c;
case 0x0c05bd8eu: goto P_0c05bd8e;
case 0x0c05bd90u: goto P_0c05bd90;
case 0x0c05bd92u: goto P_0c05bd92;
case 0x0c05bd94u: goto P_0c05bd94;
case 0x0c05bd96u: goto P_0c05bd96;
case 0x0c05bd98u: goto P_0c05bd98;
case 0x0c05bd9au: goto P_0c05bd9a;
case 0x0c05bd9cu: goto P_0c05bd9c;
case 0x0c05bd9eu: goto P_0c05bd9e;
case 0x0c05bda0u: goto P_0c05bda0;
case 0x0c05bda2u: goto P_0c05bda2;
case 0x0c05bda4u: goto P_0c05bda4;
case 0x0c05bda6u: goto P_0c05bda6;
case 0x0c05bda8u: goto P_0c05bda8;
case 0x0c05bdaau: goto P_0c05bdaa;
case 0x0c05bdacu: goto P_0c05bdac;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05bb38: /* original 2fe6, guest PC 0x0c05bb38 */
if(!s->budget--) { s->failed_pc=0x0c05bb38u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05bb3a;
P_0c05bb3a: /* original d653, guest PC 0x0c05bb3a */
if(!s->budget--) { s->failed_pc=0x0c05bb3au; return 0; }
r[6]=read(ram,0x0c05bc88u,4);
goto P_0c05bb3c;
P_0c05bb3c: /* original d553, guest PC 0x0c05bb3c */
if(!s->budget--) { s->failed_pc=0x0c05bb3cu; return 0; }
r[5]=read(ram,0x0c05bc8cu,4);
goto P_0c05bb3e;
P_0c05bb3e: /* original d754, guest PC 0x0c05bb3e */
if(!s->budget--) { s->failed_pc=0x0c05bb3eu; return 0; }
r[7]=read(ram,0x0c05bc90u,4);
goto P_0c05bb40;
P_0c05bb40: /* original 90a0, guest PC 0x0c05bb40 */
if(!s->budget--) { s->failed_pc=0x0c05bb40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05bc84u,2);
goto P_0c05bb42;
P_0c05bb42: /* original 034e, guest PC 0x0c05bb42 */
if(!s->budget--) { s->failed_pc=0x0c05bb42u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c05bb44;
P_0c05bb44: /* original e044, guest PC 0x0c05bb44 */
if(!s->budget--) { s->failed_pc=0x0c05bb44u; return 0; }
r[0]=0x00000044u;
goto P_0c05bb46;
P_0c05bb46: /* original 0736, guest PC 0x0c05bb46 */
if(!s->budget--) { s->failed_pc=0x0c05bb46u; return 0; }
write(ram,r[7]+r[0],r[3],4);
goto P_0c05bb48;
P_0c05bb48: /* original 7058, guest PC 0x0c05bb48 */
if(!s->budget--) { s->failed_pc=0x0c05bb48u; return 0; }
r[0]+=0x00000058u;
goto P_0c05bb4a;
P_0c05bb4a: /* original 024e, guest PC 0x0c05bb4a */
if(!s->budget--) { s->failed_pc=0x0c05bb4au; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c05bb4c;
P_0c05bb4c: /* original e048, guest PC 0x0c05bb4c */
if(!s->budget--) { s->failed_pc=0x0c05bb4cu; return 0; }
r[0]=0x00000048u;
goto P_0c05bb4e;
P_0c05bb4e: /* original 0726, guest PC 0x0c05bb4e */
if(!s->budget--) { s->failed_pc=0x0c05bb4eu; return 0; }
write(ram,r[7]+r[0],r[2],4);
goto P_0c05bb50;
P_0c05bb50: /* original e070, guest PC 0x0c05bb50 */
if(!s->budget--) { s->failed_pc=0x0c05bb50u; return 0; }
r[0]=0x00000070u;
goto P_0c05bb52;
P_0c05bb52: /* original f346, guest PC 0x0c05bb52 */
if(!s->budget--) { s->failed_pc=0x0c05bb52u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05bb54;
P_0c05bb54: /* original e050, guest PC 0x0c05bb54 */
if(!s->budget--) { s->failed_pc=0x0c05bb54u; return 0; }
r[0]=0x00000050u;
goto P_0c05bb56;
P_0c05bb56: /* original f737, guest PC 0x0c05bb56 */
if(!s->budget--) { s->failed_pc=0x0c05bb56u; return 0; }
vf3_matrix_store(s,ram,3,r[7]+r[0]);
goto P_0c05bb58;
P_0c05bb58: /* original e074, guest PC 0x0c05bb58 */
if(!s->budget--) { s->failed_pc=0x0c05bb58u; return 0; }
r[0]=0x00000074u;
goto P_0c05bb5a;
P_0c05bb5a: /* original f346, guest PC 0x0c05bb5a */
if(!s->budget--) { s->failed_pc=0x0c05bb5au; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05bb5c;
P_0c05bb5c: /* original e054, guest PC 0x0c05bb5c */
if(!s->budget--) { s->failed_pc=0x0c05bb5cu; return 0; }
r[0]=0x00000054u;
goto P_0c05bb5e;
P_0c05bb5e: /* original f737, guest PC 0x0c05bb5e */
if(!s->budget--) { s->failed_pc=0x0c05bb5eu; return 0; }
vf3_matrix_store(s,ram,3,r[7]+r[0]);
goto P_0c05bb60;
P_0c05bb60: /* original e078, guest PC 0x0c05bb60 */
if(!s->budget--) { s->failed_pc=0x0c05bb60u; return 0; }
r[0]=0x00000078u;
goto P_0c05bb62;
P_0c05bb62: /* original f346, guest PC 0x0c05bb62 */
if(!s->budget--) { s->failed_pc=0x0c05bb62u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05bb64;
P_0c05bb64: /* original e058, guest PC 0x0c05bb64 */
if(!s->budget--) { s->failed_pc=0x0c05bb64u; return 0; }
r[0]=0x00000058u;
goto P_0c05bb66;
P_0c05bb66: /* original f737, guest PC 0x0c05bb66 */
if(!s->budget--) { s->failed_pc=0x0c05bb66u; return 0; }
vf3_matrix_store(s,ram,3,r[7]+r[0]);
goto P_0c05bb68;
P_0c05bb68: /* original e07c, guest PC 0x0c05bb68 */
if(!s->budget--) { s->failed_pc=0x0c05bb68u; return 0; }
r[0]=0x0000007cu;
goto P_0c05bb6a;
P_0c05bb6a: /* original f346, guest PC 0x0c05bb6a */
if(!s->budget--) { s->failed_pc=0x0c05bb6au; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05bb6c;
P_0c05bb6c: /* original e05c, guest PC 0x0c05bb6c */
if(!s->budget--) { s->failed_pc=0x0c05bb6cu; return 0; }
r[0]=0x0000005cu;
goto P_0c05bb6e;
P_0c05bb6e: /* original 6463, guest PC 0x0c05bb6e */
if(!s->budget--) { s->failed_pc=0x0c05bb6eu; return 0; }
r[4]=r[6];
goto P_0c05bb70;
P_0c05bb70: /* original f737, guest PC 0x0c05bb70 */
if(!s->budget--) { s->failed_pc=0x0c05bb70u; return 0; }
vf3_matrix_store(s,ram,3,r[7]+r[0]);
goto P_0c05bb72;
P_0c05bb72: /* original d048, guest PC 0x0c05bb72 */
if(!s->budget--) { s->failed_pc=0x0c05bb72u; return 0; }
r[0]=read(ram,0x0c05bc94u,4);
goto P_0c05bb74;
P_0c05bb74: /* original 6e72, guest PC 0x0c05bb74 */
if(!s->budget--) { s->failed_pc=0x0c05bb74u; return 0; }
tmp=read(ram,r[7],4);
r[14]=tmp;
goto P_0c05bb76;
P_0c05bb76: /* original e140, guest PC 0x0c05bb76 */
if(!s->budget--) { s->failed_pc=0x0c05bb76u; return 0; }
r[1]=0x00000040u;
goto P_0c05bb78;
P_0c05bb78: /* original d347, guest PC 0x0c05bb78 */
if(!s->budget--) { s->failed_pc=0x0c05bb78u; return 0; }
r[3]=read(ram,0x0c05bc98u,4);
goto P_0c05bb7a;
P_0c05bb7a: /* original 21e9, guest PC 0x0c05bb7a */
if(!s->budget--) { s->failed_pc=0x0c05bb7au; return 0; }
r[1]&=r[14];
goto P_0c05bb7c;
P_0c05bb7c: /* original d247, guest PC 0x0c05bb7c */
if(!s->budget--) { s->failed_pc=0x0c05bb7cu; return 0; }
r[2]=read(ram,0x0c05bc9cu,4);
goto P_0c05bb7e;
P_0c05bb7e: /* original 23e9, guest PC 0x0c05bb7e */
if(!s->budget--) { s->failed_pc=0x0c05bb7eu; return 0; }
r[3]&=r[14];
goto P_0c05bb80;
P_0c05bb80: /* original 4329, guest PC 0x0c05bb80 */
if(!s->budget--) { s->failed_pc=0x0c05bb80u; return 0; }
r[3]>>=16;
goto P_0c05bb82;
P_0c05bb82: /* original 4319, guest PC 0x0c05bb82 */
if(!s->budget--) { s->failed_pc=0x0c05bb82u; return 0; }
r[3]>>=8;
goto P_0c05bb84;
P_0c05bb84: /* original 22e9, guest PC 0x0c05bb84 */
if(!s->budget--) { s->failed_pc=0x0c05bb84u; return 0; }
r[2]&=r[14];
goto P_0c05bb86;
P_0c05bb86: /* original 4229, guest PC 0x0c05bb86 */
if(!s->budget--) { s->failed_pc=0x0c05bb86u; return 0; }
r[2]>>=16;
goto P_0c05bb88;
P_0c05bb88: /* original 4209, guest PC 0x0c05bb88 */
if(!s->budget--) { s->failed_pc=0x0c05bb88u; return 0; }
r[2]>>=2;
goto P_0c05bb8a;
P_0c05bb8a: /* original 4209, guest PC 0x0c05bb8a */
if(!s->budget--) { s->failed_pc=0x0c05bb8au; return 0; }
r[2]>>=2;
goto P_0c05bb8c;
P_0c05bb8c: /* original 232b, guest PC 0x0c05bb8c */
if(!s->budget--) { s->failed_pc=0x0c05bb8cu; return 0; }
r[3]|=r[2];
goto P_0c05bb8e;
P_0c05bb8e: /* original 4109, guest PC 0x0c05bb8e */
if(!s->budget--) { s->failed_pc=0x0c05bb8eu; return 0; }
r[1]>>=2;
goto P_0c05bb90;
P_0c05bb90: /* original 4101, guest PC 0x0c05bb90 */
if(!s->budget--) { s->failed_pc=0x0c05bb90u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c05bb92;
P_0c05bb92: /* original 231b, guest PC 0x0c05bb92 */
if(!s->budget--) { s->failed_pc=0x0c05bb92u; return 0; }
r[3]|=r[1];
goto P_0c05bb94;
P_0c05bb94: /* original e220, guest PC 0x0c05bb94 */
if(!s->budget--) { s->failed_pc=0x0c05bb94u; return 0; }
r[2]=0x00000020u;
goto P_0c05bb96;
P_0c05bb96: /* original 22e9, guest PC 0x0c05bb96 */
if(!s->budget--) { s->failed_pc=0x0c05bb96u; return 0; }
r[2]&=r[14];
goto P_0c05bb98;
P_0c05bb98: /* original 4209, guest PC 0x0c05bb98 */
if(!s->budget--) { s->failed_pc=0x0c05bb98u; return 0; }
r[2]>>=2;
goto P_0c05bb9a;
P_0c05bb9a: /* original 4201, guest PC 0x0c05bb9a */
if(!s->budget--) { s->failed_pc=0x0c05bb9au; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]>>=1;
goto P_0c05bb9c;
P_0c05bb9c: /* original 232b, guest PC 0x0c05bb9c */
if(!s->budget--) { s->failed_pc=0x0c05bb9cu; return 0; }
r[3]|=r[2];
goto P_0c05bb9e;
P_0c05bb9e: /* original e110, guest PC 0x0c05bb9e */
if(!s->budget--) { s->failed_pc=0x0c05bb9eu; return 0; }
r[1]=0x00000010u;
goto P_0c05bba0;
P_0c05bba0: /* original 21e9, guest PC 0x0c05bba0 */
if(!s->budget--) { s->failed_pc=0x0c05bba0u; return 0; }
r[1]&=r[14];
goto P_0c05bba2;
P_0c05bba2: /* original 4109, guest PC 0x0c05bba2 */
if(!s->budget--) { s->failed_pc=0x0c05bba2u; return 0; }
r[1]>>=2;
goto P_0c05bba4;
P_0c05bba4: /* original 4101, guest PC 0x0c05bba4 */
if(!s->budget--) { s->failed_pc=0x0c05bba4u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c05bba6;
P_0c05bba6: /* original 231b, guest PC 0x0c05bba6 */
if(!s->budget--) { s->failed_pc=0x0c05bba6u; return 0; }
r[3]|=r[1];
goto P_0c05bba8;
P_0c05bba8: /* original e204, guest PC 0x0c05bba8 */
if(!s->budget--) { s->failed_pc=0x0c05bba8u; return 0; }
r[2]=0x00000004u;
goto P_0c05bbaa;
P_0c05bbaa: /* original 22e9, guest PC 0x0c05bbaa */
if(!s->budget--) { s->failed_pc=0x0c05bbaau; return 0; }
r[2]&=r[14];
goto P_0c05bbac;
P_0c05bbac: /* original 4209, guest PC 0x0c05bbac */
if(!s->budget--) { s->failed_pc=0x0c05bbacu; return 0; }
r[2]>>=2;
goto P_0c05bbae;
P_0c05bbae: /* original 232b, guest PC 0x0c05bbae */
if(!s->budget--) { s->failed_pc=0x0c05bbaeu; return 0; }
r[3]|=r[2];
goto P_0c05bbb0;
P_0c05bbb0: /* original d23b, guest PC 0x0c05bbb0 */
if(!s->budget--) { s->failed_pc=0x0c05bbb0u; return 0; }
r[2]=read(ram,0x0c05bca0u,4);
goto P_0c05bbb2;
P_0c05bbb2: /* original 4308, guest PC 0x0c05bbb2 */
if(!s->budget--) { s->failed_pc=0x0c05bbb2u; return 0; }
r[3]<<=2;
goto P_0c05bbb4;
P_0c05bbb4: /* original 033e, guest PC 0x0c05bbb4 */
if(!s->budget--) { s->failed_pc=0x0c05bbb4u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c05bbb6;
P_0c05bbb6: /* original 2232, guest PC 0x0c05bbb6 */
if(!s->budget--) { s->failed_pc=0x0c05bbb6u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c05bbb8;
P_0c05bbb8: /* original 6372, guest PC 0x0c05bbb8 */
if(!s->budget--) { s->failed_pc=0x0c05bbb8u; return 0; }
tmp=read(ram,r[7],4);
r[3]=tmp;
goto P_0c05bbba;
P_0c05bbba: /* original 2432, guest PC 0x0c05bbba */
if(!s->budget--) { s->failed_pc=0x0c05bbbau; return 0; }
write(ram,r[4],r[3],4);
goto P_0c05bbbc;
P_0c05bbbc: /* original d339, guest PC 0x0c05bbbc */
if(!s->budget--) { s->failed_pc=0x0c05bbbcu; return 0; }
r[3]=read(ram,0x0c05bca4u,4);
goto P_0c05bbbe;
P_0c05bbbe: /* original 6272, guest PC 0x0c05bbbe */
if(!s->budget--) { s->failed_pc=0x0c05bbbeu; return 0; }
tmp=read(ram,r[7],4);
r[2]=tmp;
goto P_0c05bbc0;
P_0c05bbc0: /* original 2239, guest PC 0x0c05bbc0 */
if(!s->budget--) { s->failed_pc=0x0c05bbc0u; return 0; }
r[2]&=r[3];
goto P_0c05bbc2;
P_0c05bbc2: /* original 4229, guest PC 0x0c05bbc2 */
if(!s->budget--) { s->failed_pc=0x0c05bbc2u; return 0; }
r[2]>>=16;
goto P_0c05bbc4;
P_0c05bbc4: /* original 4219, guest PC 0x0c05bbc4 */
if(!s->budget--) { s->failed_pc=0x0c05bbc4u; return 0; }
r[2]>>=8;
goto P_0c05bbc6;
P_0c05bbc6: /* original 2522, guest PC 0x0c05bbc6 */
if(!s->budget--) { s->failed_pc=0x0c05bbc6u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c05bbc8;
P_0c05bbc8: /* original 6023, guest PC 0x0c05bbc8 */
if(!s->budget--) { s->failed_pc=0x0c05bbc8u; return 0; }
r[0]=r[2];
goto P_0c05bbca;
P_0c05bbca: /* original 0009, guest PC 0x0c05bbca */
if(!s->budget--) { s->failed_pc=0x0c05bbcau; return 0; }
goto P_0c05bbcc;
P_0c05bbcc: /* original c801, guest PC 0x0c05bbcc */
if(!s->budget--) { s->failed_pc=0x0c05bbccu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c05bbce;
P_0c05bbce: /* original 8d02, guest PC 0x0c05bbce */
if(!s->budget--) { s->failed_pc=0x0c05bbceu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(cond) { goto P_0c05bbd6; }
goto P_0c05bbd2;
P_0c05bbd0: /* original 7404, guest PC 0x0c05bbd0 */
if(!s->budget--) { s->failed_pc=0x0c05bbd0u; return 0; }
r[4]+=0x00000004u;
goto P_0c05bbd2;
P_0c05bbd2: /* original a0e0, guest PC 0x0c05bbd2 */
if(!s->budget--) { s->failed_pc=0x0c05bbd2u; return 0; }
goto P_0c05bd96;
P_0c05bbd4: /* original 0009, guest PC 0x0c05bbd4 */
if(!s->budget--) { s->failed_pc=0x0c05bbd4u; return 0; }
goto P_0c05bbd6;
P_0c05bbd6: /* original 6e73, guest PC 0x0c05bbd6 */
if(!s->budget--) { s->failed_pc=0x0c05bbd6u; return 0; }
r[14]=r[7];
goto P_0c05bbd8;
P_0c05bbd8: /* original d231, guest PC 0x0c05bbd8 */
if(!s->budget--) { s->failed_pc=0x0c05bbd8u; return 0; }
r[2]=read(ram,0x0c05bca0u,4);
goto P_0c05bbda;
P_0c05bbda: /* original 7e10, guest PC 0x0c05bbda */
if(!s->budget--) { s->failed_pc=0x0c05bbdau; return 0; }
r[14]+=0x00000010u;
goto P_0c05bbdc;
P_0c05bbdc: /* original 5174, guest PC 0x0c05bbdc */
if(!s->budget--) { s->failed_pc=0x0c05bbdcu; return 0; }
r[1]=read(ram,r[7]+16,4);
goto P_0c05bbde;
P_0c05bbde: /* original 2412, guest PC 0x0c05bbde */
if(!s->budget--) { s->failed_pc=0x0c05bbdeu; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bbe0;
P_0c05bbe0: /* original 5175, guest PC 0x0c05bbe0 */
if(!s->budget--) { s->failed_pc=0x0c05bbe0u; return 0; }
r[1]=read(ram,r[7]+20,4);
goto P_0c05bbe2;
P_0c05bbe2: /* original 7404, guest PC 0x0c05bbe2 */
if(!s->budget--) { s->failed_pc=0x0c05bbe2u; return 0; }
r[4]+=0x00000004u;
goto P_0c05bbe4;
P_0c05bbe4: /* original 2412, guest PC 0x0c05bbe4 */
if(!s->budget--) { s->failed_pc=0x0c05bbe4u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bbe6;
P_0c05bbe6: /* original 7404, guest PC 0x0c05bbe6 */
if(!s->budget--) { s->failed_pc=0x0c05bbe6u; return 0; }
r[4]+=0x00000004u;
goto P_0c05bbe8;
P_0c05bbe8: /* original 5176, guest PC 0x0c05bbe8 */
if(!s->budget--) { s->failed_pc=0x0c05bbe8u; return 0; }
r[1]=read(ram,r[7]+24,4);
goto P_0c05bbea;
P_0c05bbea: /* original 2412, guest PC 0x0c05bbea */
if(!s->budget--) { s->failed_pc=0x0c05bbeau; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bbec;
P_0c05bbec: /* original 6022, guest PC 0x0c05bbec */
if(!s->budget--) { s->failed_pc=0x0c05bbecu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05bbee;
P_0c05bbee: /* original 8800, guest PC 0x0c05bbee */
if(!s->budget--) { s->failed_pc=0x0c05bbeeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c05bbf0;
P_0c05bbf0: /* original 8d0e, guest PC 0x0c05bbf0 */
if(!s->budget--) { s->failed_pc=0x0c05bbf0u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(cond) { goto P_0c05bc10; }
goto P_0c05bbf4;
P_0c05bbf2: /* original 7404, guest PC 0x0c05bbf2 */
if(!s->budget--) { s->failed_pc=0x0c05bbf2u; return 0; }
r[4]+=0x00000004u;
goto P_0c05bbf4;
P_0c05bbf4: /* original 8801, guest PC 0x0c05bbf4 */
if(!s->budget--) { s->failed_pc=0x0c05bbf4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05bbf6;
P_0c05bbf6: /* original 890d, guest PC 0x0c05bbf6 */
if(!s->budget--) { s->failed_pc=0x0c05bbf6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05bc14; }
goto P_0c05bbf8;
P_0c05bbf8: /* original 8802, guest PC 0x0c05bbf8 */
if(!s->budget--) { s->failed_pc=0x0c05bbf8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c05bbfa;
P_0c05bbfa: /* original 891a, guest PC 0x0c05bbfa */
if(!s->budget--) { s->failed_pc=0x0c05bbfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05bc32; }
goto P_0c05bbfc;
P_0c05bbfc: /* original 8803, guest PC 0x0c05bbfc */
if(!s->budget--) { s->failed_pc=0x0c05bbfcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05bbfe;
P_0c05bbfe: /* original 8953, guest PC 0x0c05bbfe */
if(!s->budget--) { s->failed_pc=0x0c05bbfeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05bca8; }
goto P_0c05bc00;
P_0c05bc00: /* original 8804, guest PC 0x0c05bc00 */
if(!s->budget--) { s->failed_pc=0x0c05bc00u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c05bc02;
P_0c05bc02: /* original 8959, guest PC 0x0c05bc02 */
if(!s->budget--) { s->failed_pc=0x0c05bc02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05bcb8; }
goto P_0c05bc04;
P_0c05bc04: /* original 8810, guest PC 0x0c05bc04 */
if(!s->budget--) { s->failed_pc=0x0c05bc04u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c05bc06;
P_0c05bc06: /* original 8b01, guest PC 0x0c05bc06 */
if(!s->budget--) { s->failed_pc=0x0c05bc06u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05bc0c; }
goto P_0c05bc08;
P_0c05bc08: /* original a083, guest PC 0x0c05bc08 */
if(!s->budget--) { s->failed_pc=0x0c05bc08u; return 0; }
goto P_0c05bd12;
P_0c05bc0a: /* original 0009, guest PC 0x0c05bc0a */
if(!s->budget--) { s->failed_pc=0x0c05bc0au; return 0; }
goto P_0c05bc0c;
P_0c05bc0c: /* original a0c7, guest PC 0x0c05bc0c */
if(!s->budget--) { s->failed_pc=0x0c05bc0cu; return 0; }
goto P_0c05bd9e;
P_0c05bc0e: /* original 0009, guest PC 0x0c05bc0e */
if(!s->budget--) { s->failed_pc=0x0c05bc0eu; return 0; }
goto P_0c05bc10;
P_0c05bc10: /* original a0c5, guest PC 0x0c05bc10 */
if(!s->budget--) { s->failed_pc=0x0c05bc10u; return 0; }
r[4]+=0x00000010u;
goto P_0c05bd9e;
P_0c05bc12: /* original 7410, guest PC 0x0c05bc12 */
if(!s->budget--) { s->failed_pc=0x0c05bc12u; return 0; }
r[4]+=0x00000010u;
goto P_0c05bc14;
P_0c05bc14: /* original 61e3, guest PC 0x0c05bc14 */
if(!s->budget--) { s->failed_pc=0x0c05bc14u; return 0; }
r[1]=r[14];
goto P_0c05bc16;
P_0c05bc16: /* original 5114, guest PC 0x0c05bc16 */
if(!s->budget--) { s->failed_pc=0x0c05bc16u; return 0; }
r[1]=read(ram,r[1]+16,4);
goto P_0c05bc18;
P_0c05bc18: /* original 2412, guest PC 0x0c05bc18 */
if(!s->budget--) { s->failed_pc=0x0c05bc18u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bc1a;
P_0c05bc1a: /* original 7404, guest PC 0x0c05bc1a */
if(!s->budget--) { s->failed_pc=0x0c05bc1au; return 0; }
r[4]+=0x00000004u;
goto P_0c05bc1c;
P_0c05bc1c: /* original 6173, guest PC 0x0c05bc1c */
if(!s->budget--) { s->failed_pc=0x0c05bc1cu; return 0; }
r[1]=r[7];
goto P_0c05bc1e;
P_0c05bc1e: /* original 5119, guest PC 0x0c05bc1e */
if(!s->budget--) { s->failed_pc=0x0c05bc1eu; return 0; }
r[1]=read(ram,r[1]+36,4);
goto P_0c05bc20;
P_0c05bc20: /* original 2412, guest PC 0x0c05bc20 */
if(!s->budget--) { s->failed_pc=0x0c05bc20u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bc22;
P_0c05bc22: /* original 7404, guest PC 0x0c05bc22 */
if(!s->budget--) { s->failed_pc=0x0c05bc22u; return 0; }
r[4]+=0x00000004u;
goto P_0c05bc24;
P_0c05bc24: /* original 6173, guest PC 0x0c05bc24 */
if(!s->budget--) { s->failed_pc=0x0c05bc24u; return 0; }
r[1]=r[7];
goto P_0c05bc26;
P_0c05bc26: /* original 511a, guest PC 0x0c05bc26 */
if(!s->budget--) { s->failed_pc=0x0c05bc26u; return 0; }
r[1]=read(ram,r[1]+40,4);
goto P_0c05bc28;
P_0c05bc28: /* original 2412, guest PC 0x0c05bc28 */
if(!s->budget--) { s->failed_pc=0x0c05bc28u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bc2a;
P_0c05bc2a: /* original 7404, guest PC 0x0c05bc2a */
if(!s->budget--) { s->failed_pc=0x0c05bc2au; return 0; }
r[4]+=0x00000004u;
goto P_0c05bc2c;
P_0c05bc2c: /* original 6173, guest PC 0x0c05bc2c */
if(!s->budget--) { s->failed_pc=0x0c05bc2cu; return 0; }
r[1]=r[7];
goto P_0c05bc2e;
P_0c05bc2e: /* original a06d, guest PC 0x0c05bc2e */
if(!s->budget--) { s->failed_pc=0x0c05bc2eu; return 0; }
r[1]=read(ram,r[1]+44,4);
goto P_0c05bd0c;
P_0c05bc30: /* original 511b, guest PC 0x0c05bc30 */
if(!s->budget--) { s->failed_pc=0x0c05bc30u; return 0; }
r[1]=read(ram,r[1]+44,4);
goto P_0c05bc32;
P_0c05bc32: /* original 7410, guest PC 0x0c05bc32 */
if(!s->budget--) { s->failed_pc=0x0c05bc32u; return 0; }
r[4]+=0x00000010u;
goto P_0c05bc34;
P_0c05bc34: /* original 60e3, guest PC 0x0c05bc34 */
if(!s->budget--) { s->failed_pc=0x0c05bc34u; return 0; }
r[0]=r[14];
goto P_0c05bc36;
P_0c05bc36: /* original 0009, guest PC 0x0c05bc36 */
if(!s->budget--) { s->failed_pc=0x0c05bc36u; return 0; }
goto P_0c05bc38;
P_0c05bc38: /* original 5004, guest PC 0x0c05bc38 */
if(!s->budget--) { s->failed_pc=0x0c05bc38u; return 0; }
r[0]=read(ram,r[0]+16,4);
goto P_0c05bc3a;
P_0c05bc3a: /* original 2402, guest PC 0x0c05bc3a */
if(!s->budget--) { s->failed_pc=0x0c05bc3au; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05bc3c;
P_0c05bc3c: /* original 7404, guest PC 0x0c05bc3c */
if(!s->budget--) { s->failed_pc=0x0c05bc3cu; return 0; }
r[4]+=0x00000004u;
goto P_0c05bc3e;
P_0c05bc3e: /* original 6073, guest PC 0x0c05bc3e */
if(!s->budget--) { s->failed_pc=0x0c05bc3eu; return 0; }
r[0]=r[7];
goto P_0c05bc40;
P_0c05bc40: /* original 0009, guest PC 0x0c05bc40 */
if(!s->budget--) { s->failed_pc=0x0c05bc40u; return 0; }
goto P_0c05bc42;
P_0c05bc42: /* original 5009, guest PC 0x0c05bc42 */
if(!s->budget--) { s->failed_pc=0x0c05bc42u; return 0; }
r[0]=read(ram,r[0]+36,4);
goto P_0c05bc44;
P_0c05bc44: /* original 2402, guest PC 0x0c05bc44 */
if(!s->budget--) { s->failed_pc=0x0c05bc44u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05bc46;
P_0c05bc46: /* original 7404, guest PC 0x0c05bc46 */
if(!s->budget--) { s->failed_pc=0x0c05bc46u; return 0; }
r[4]+=0x00000004u;
goto P_0c05bc48;
P_0c05bc48: /* original 6073, guest PC 0x0c05bc48 */
if(!s->budget--) { s->failed_pc=0x0c05bc48u; return 0; }
r[0]=r[7];
goto P_0c05bc4a;
P_0c05bc4a: /* original 0009, guest PC 0x0c05bc4a */
if(!s->budget--) { s->failed_pc=0x0c05bc4au; return 0; }
goto P_0c05bc4c;
P_0c05bc4c: /* original 500a, guest PC 0x0c05bc4c */
if(!s->budget--) { s->failed_pc=0x0c05bc4cu; return 0; }
r[0]=read(ram,r[0]+40,4);
goto P_0c05bc4e;
P_0c05bc4e: /* original 2402, guest PC 0x0c05bc4e */
if(!s->budget--) { s->failed_pc=0x0c05bc4eu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05bc50;
P_0c05bc50: /* original 7404, guest PC 0x0c05bc50 */
if(!s->budget--) { s->failed_pc=0x0c05bc50u; return 0; }
r[4]+=0x00000004u;
goto P_0c05bc52;
P_0c05bc52: /* original 6073, guest PC 0x0c05bc52 */
if(!s->budget--) { s->failed_pc=0x0c05bc52u; return 0; }
r[0]=r[7];
goto P_0c05bc54;
P_0c05bc54: /* original 0009, guest PC 0x0c05bc54 */
if(!s->budget--) { s->failed_pc=0x0c05bc54u; return 0; }
goto P_0c05bc56;
P_0c05bc56: /* original 500b, guest PC 0x0c05bc56 */
if(!s->budget--) { s->failed_pc=0x0c05bc56u; return 0; }
r[0]=read(ram,r[0]+44,4);
goto P_0c05bc58;
P_0c05bc58: /* original 2402, guest PC 0x0c05bc58 */
if(!s->budget--) { s->failed_pc=0x0c05bc58u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05bc5a;
P_0c05bc5a: /* original 7404, guest PC 0x0c05bc5a */
if(!s->budget--) { s->failed_pc=0x0c05bc5au; return 0; }
r[4]+=0x00000004u;
goto P_0c05bc5c;
P_0c05bc5c: /* original 6073, guest PC 0x0c05bc5c */
if(!s->budget--) { s->failed_pc=0x0c05bc5cu; return 0; }
r[0]=r[7];
goto P_0c05bc5e;
P_0c05bc5e: /* original 0009, guest PC 0x0c05bc5e */
if(!s->budget--) { s->failed_pc=0x0c05bc5eu; return 0; }
goto P_0c05bc60;
P_0c05bc60: /* original 500c, guest PC 0x0c05bc60 */
if(!s->budget--) { s->failed_pc=0x0c05bc60u; return 0; }
r[0]=read(ram,r[0]+48,4);
goto P_0c05bc62;
P_0c05bc62: /* original 2402, guest PC 0x0c05bc62 */
if(!s->budget--) { s->failed_pc=0x0c05bc62u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05bc64;
P_0c05bc64: /* original 7404, guest PC 0x0c05bc64 */
if(!s->budget--) { s->failed_pc=0x0c05bc64u; return 0; }
r[4]+=0x00000004u;
goto P_0c05bc66;
P_0c05bc66: /* original 6073, guest PC 0x0c05bc66 */
if(!s->budget--) { s->failed_pc=0x0c05bc66u; return 0; }
r[0]=r[7];
goto P_0c05bc68;
P_0c05bc68: /* original 0009, guest PC 0x0c05bc68 */
if(!s->budget--) { s->failed_pc=0x0c05bc68u; return 0; }
goto P_0c05bc6a;
P_0c05bc6a: /* original 500d, guest PC 0x0c05bc6a */
if(!s->budget--) { s->failed_pc=0x0c05bc6au; return 0; }
r[0]=read(ram,r[0]+52,4);
goto P_0c05bc6c;
P_0c05bc6c: /* original 2402, guest PC 0x0c05bc6c */
if(!s->budget--) { s->failed_pc=0x0c05bc6cu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05bc6e;
P_0c05bc6e: /* original 7404, guest PC 0x0c05bc6e */
if(!s->budget--) { s->failed_pc=0x0c05bc6eu; return 0; }
r[4]+=0x00000004u;
goto P_0c05bc70;
P_0c05bc70: /* original 6073, guest PC 0x0c05bc70 */
if(!s->budget--) { s->failed_pc=0x0c05bc70u; return 0; }
r[0]=r[7];
goto P_0c05bc72;
P_0c05bc72: /* original 0009, guest PC 0x0c05bc72 */
if(!s->budget--) { s->failed_pc=0x0c05bc72u; return 0; }
goto P_0c05bc74;
P_0c05bc74: /* original 500e, guest PC 0x0c05bc74 */
if(!s->budget--) { s->failed_pc=0x0c05bc74u; return 0; }
r[0]=read(ram,r[0]+56,4);
goto P_0c05bc76;
P_0c05bc76: /* original 2402, guest PC 0x0c05bc76 */
if(!s->budget--) { s->failed_pc=0x0c05bc76u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05bc78;
P_0c05bc78: /* original 7404, guest PC 0x0c05bc78 */
if(!s->budget--) { s->failed_pc=0x0c05bc78u; return 0; }
r[4]+=0x00000004u;
goto P_0c05bc7a;
P_0c05bc7a: /* original 6073, guest PC 0x0c05bc7a */
if(!s->budget--) { s->failed_pc=0x0c05bc7au; return 0; }
r[0]=r[7];
goto P_0c05bc7c;
P_0c05bc7c: /* original 0009, guest PC 0x0c05bc7c */
if(!s->budget--) { s->failed_pc=0x0c05bc7cu; return 0; }
goto P_0c05bc7e;
P_0c05bc7e: /* original 500f, guest PC 0x0c05bc7e */
if(!s->budget--) { s->failed_pc=0x0c05bc7eu; return 0; }
r[0]=read(ram,r[0]+60,4);
goto P_0c05bc80;
P_0c05bc80: /* original a045, guest PC 0x0c05bc80 */
if(!s->budget--) { s->failed_pc=0x0c05bc80u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05bd0e;
P_0c05bc82: /* original 2402, guest PC 0x0c05bc82 */
if(!s->budget--) { s->failed_pc=0x0c05bc82u; return 0; }
write(ram,r[4],r[0],4);
if(!vf3_matrix_family(0x0c05bc84u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05bc84u; return 0; } return 1;
P_0c05bca8: /* original e044, guest PC 0x0c05bca8 */
if(!s->budget--) { s->failed_pc=0x0c05bca8u; return 0; }
r[0]=0x00000044u;
goto P_0c05bcaa;
P_0c05bcaa: /* original 007e, guest PC 0x0c05bcaa */
if(!s->budget--) { s->failed_pc=0x0c05bcaau; return 0; }
r[0]=read(ram,r[7]+r[0],4);
goto P_0c05bcac;
P_0c05bcac: /* original 2402, guest PC 0x0c05bcac */
if(!s->budget--) { s->failed_pc=0x0c05bcacu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05bcae;
P_0c05bcae: /* original 7404, guest PC 0x0c05bcae */
if(!s->budget--) { s->failed_pc=0x0c05bcaeu; return 0; }
r[4]+=0x00000004u;
goto P_0c05bcb0;
P_0c05bcb0: /* original e048, guest PC 0x0c05bcb0 */
if(!s->budget--) { s->failed_pc=0x0c05bcb0u; return 0; }
r[0]=0x00000048u;
goto P_0c05bcb2;
P_0c05bcb2: /* original 017e, guest PC 0x0c05bcb2 */
if(!s->budget--) { s->failed_pc=0x0c05bcb2u; return 0; }
r[1]=read(ram,r[7]+r[0],4);
goto P_0c05bcb4;
P_0c05bcb4: /* original a06d, guest PC 0x0c05bcb4 */
if(!s->budget--) { s->failed_pc=0x0c05bcb4u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bd92;
P_0c05bcb6: /* original 2412, guest PC 0x0c05bcb6 */
if(!s->budget--) { s->failed_pc=0x0c05bcb6u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bcb8;
P_0c05bcb8: /* original e044, guest PC 0x0c05bcb8 */
if(!s->budget--) { s->failed_pc=0x0c05bcb8u; return 0; }
r[0]=0x00000044u;
goto P_0c05bcba;
P_0c05bcba: /* original 007e, guest PC 0x0c05bcba */
if(!s->budget--) { s->failed_pc=0x0c05bcbau; return 0; }
r[0]=read(ram,r[7]+r[0],4);
goto P_0c05bcbc;
P_0c05bcbc: /* original 2402, guest PC 0x0c05bcbc */
if(!s->budget--) { s->failed_pc=0x0c05bcbcu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05bcbe;
P_0c05bcbe: /* original 7404, guest PC 0x0c05bcbe */
if(!s->budget--) { s->failed_pc=0x0c05bcbeu; return 0; }
r[4]+=0x00000004u;
goto P_0c05bcc0;
P_0c05bcc0: /* original e048, guest PC 0x0c05bcc0 */
if(!s->budget--) { s->failed_pc=0x0c05bcc0u; return 0; }
r[0]=0x00000048u;
goto P_0c05bcc2;
P_0c05bcc2: /* original 017e, guest PC 0x0c05bcc2 */
if(!s->budget--) { s->failed_pc=0x0c05bcc2u; return 0; }
r[1]=read(ram,r[7]+r[0],4);
goto P_0c05bcc4;
P_0c05bcc4: /* original 2412, guest PC 0x0c05bcc4 */
if(!s->budget--) { s->failed_pc=0x0c05bcc4u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bcc6;
P_0c05bcc6: /* original 740c, guest PC 0x0c05bcc6 */
if(!s->budget--) { s->failed_pc=0x0c05bcc6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c05bcc8;
P_0c05bcc8: /* original 6173, guest PC 0x0c05bcc8 */
if(!s->budget--) { s->failed_pc=0x0c05bcc8u; return 0; }
r[1]=r[7];
goto P_0c05bcca;
P_0c05bcca: /* original 5118, guest PC 0x0c05bcca */
if(!s->budget--) { s->failed_pc=0x0c05bccau; return 0; }
r[1]=read(ram,r[1]+32,4);
goto P_0c05bccc;
P_0c05bccc: /* original 2412, guest PC 0x0c05bccc */
if(!s->budget--) { s->failed_pc=0x0c05bcccu; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bcce;
P_0c05bcce: /* original 7404, guest PC 0x0c05bcce */
if(!s->budget--) { s->failed_pc=0x0c05bcceu; return 0; }
r[4]+=0x00000004u;
goto P_0c05bcd0;
P_0c05bcd0: /* original 6173, guest PC 0x0c05bcd0 */
if(!s->budget--) { s->failed_pc=0x0c05bcd0u; return 0; }
r[1]=r[7];
goto P_0c05bcd2;
P_0c05bcd2: /* original 5119, guest PC 0x0c05bcd2 */
if(!s->budget--) { s->failed_pc=0x0c05bcd2u; return 0; }
r[1]=read(ram,r[1]+36,4);
goto P_0c05bcd4;
P_0c05bcd4: /* original 2412, guest PC 0x0c05bcd4 */
if(!s->budget--) { s->failed_pc=0x0c05bcd4u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bcd6;
P_0c05bcd6: /* original 7404, guest PC 0x0c05bcd6 */
if(!s->budget--) { s->failed_pc=0x0c05bcd6u; return 0; }
r[4]+=0x00000004u;
goto P_0c05bcd8;
P_0c05bcd8: /* original 6173, guest PC 0x0c05bcd8 */
if(!s->budget--) { s->failed_pc=0x0c05bcd8u; return 0; }
r[1]=r[7];
goto P_0c05bcda;
P_0c05bcda: /* original 511a, guest PC 0x0c05bcda */
if(!s->budget--) { s->failed_pc=0x0c05bcdau; return 0; }
r[1]=read(ram,r[1]+40,4);
goto P_0c05bcdc;
P_0c05bcdc: /* original 2412, guest PC 0x0c05bcdc */
if(!s->budget--) { s->failed_pc=0x0c05bcdcu; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bcde;
P_0c05bcde: /* original 7404, guest PC 0x0c05bcde */
if(!s->budget--) { s->failed_pc=0x0c05bcdeu; return 0; }
r[4]+=0x00000004u;
goto P_0c05bce0;
P_0c05bce0: /* original 6173, guest PC 0x0c05bce0 */
if(!s->budget--) { s->failed_pc=0x0c05bce0u; return 0; }
r[1]=r[7];
goto P_0c05bce2;
P_0c05bce2: /* original 511b, guest PC 0x0c05bce2 */
if(!s->budget--) { s->failed_pc=0x0c05bce2u; return 0; }
r[1]=read(ram,r[1]+44,4);
goto P_0c05bce4;
P_0c05bce4: /* original 2412, guest PC 0x0c05bce4 */
if(!s->budget--) { s->failed_pc=0x0c05bce4u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bce6;
P_0c05bce6: /* original 7404, guest PC 0x0c05bce6 */
if(!s->budget--) { s->failed_pc=0x0c05bce6u; return 0; }
r[4]+=0x00000004u;
goto P_0c05bce8;
P_0c05bce8: /* original 6173, guest PC 0x0c05bce8 */
if(!s->budget--) { s->failed_pc=0x0c05bce8u; return 0; }
r[1]=r[7];
goto P_0c05bcea;
P_0c05bcea: /* original 7150, guest PC 0x0c05bcea */
if(!s->budget--) { s->failed_pc=0x0c05bceau; return 0; }
r[1]+=0x00000050u;
goto P_0c05bcec;
P_0c05bcec: /* original 6112, guest PC 0x0c05bcec */
if(!s->budget--) { s->failed_pc=0x0c05bcecu; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c05bcee;
P_0c05bcee: /* original 2412, guest PC 0x0c05bcee */
if(!s->budget--) { s->failed_pc=0x0c05bceeu; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bcf0;
P_0c05bcf0: /* original 7404, guest PC 0x0c05bcf0 */
if(!s->budget--) { s->failed_pc=0x0c05bcf0u; return 0; }
r[4]+=0x00000004u;
goto P_0c05bcf2;
P_0c05bcf2: /* original 6173, guest PC 0x0c05bcf2 */
if(!s->budget--) { s->failed_pc=0x0c05bcf2u; return 0; }
r[1]=r[7];
goto P_0c05bcf4;
P_0c05bcf4: /* original 7154, guest PC 0x0c05bcf4 */
if(!s->budget--) { s->failed_pc=0x0c05bcf4u; return 0; }
r[1]+=0x00000054u;
goto P_0c05bcf6;
P_0c05bcf6: /* original 6112, guest PC 0x0c05bcf6 */
if(!s->budget--) { s->failed_pc=0x0c05bcf6u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c05bcf8;
P_0c05bcf8: /* original 2412, guest PC 0x0c05bcf8 */
if(!s->budget--) { s->failed_pc=0x0c05bcf8u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bcfa;
P_0c05bcfa: /* original 7404, guest PC 0x0c05bcfa */
if(!s->budget--) { s->failed_pc=0x0c05bcfau; return 0; }
r[4]+=0x00000004u;
goto P_0c05bcfc;
P_0c05bcfc: /* original 6173, guest PC 0x0c05bcfc */
if(!s->budget--) { s->failed_pc=0x0c05bcfcu; return 0; }
r[1]=r[7];
goto P_0c05bcfe;
P_0c05bcfe: /* original 7158, guest PC 0x0c05bcfe */
if(!s->budget--) { s->failed_pc=0x0c05bcfeu; return 0; }
r[1]+=0x00000058u;
goto P_0c05bd00;
P_0c05bd00: /* original 6112, guest PC 0x0c05bd00 */
if(!s->budget--) { s->failed_pc=0x0c05bd00u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c05bd02;
P_0c05bd02: /* original 2412, guest PC 0x0c05bd02 */
if(!s->budget--) { s->failed_pc=0x0c05bd02u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bd04;
P_0c05bd04: /* original 7404, guest PC 0x0c05bd04 */
if(!s->budget--) { s->failed_pc=0x0c05bd04u; return 0; }
r[4]+=0x00000004u;
goto P_0c05bd06;
P_0c05bd06: /* original 6173, guest PC 0x0c05bd06 */
if(!s->budget--) { s->failed_pc=0x0c05bd06u; return 0; }
r[1]=r[7];
goto P_0c05bd08;
P_0c05bd08: /* original 715c, guest PC 0x0c05bd08 */
if(!s->budget--) { s->failed_pc=0x0c05bd08u; return 0; }
r[1]+=0x0000005cu;
goto P_0c05bd0a;
P_0c05bd0a: /* original 6112, guest PC 0x0c05bd0a */
if(!s->budget--) { s->failed_pc=0x0c05bd0au; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c05bd0c;
P_0c05bd0c: /* original 2412, guest PC 0x0c05bd0c */
if(!s->budget--) { s->failed_pc=0x0c05bd0cu; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bd0e;
P_0c05bd0e: /* original a046, guest PC 0x0c05bd0e */
if(!s->budget--) { s->failed_pc=0x0c05bd0eu; return 0; }
r[4]+=0x00000004u;
goto P_0c05bd9e;
P_0c05bd10: /* original 7404, guest PC 0x0c05bd10 */
if(!s->budget--) { s->failed_pc=0x0c05bd10u; return 0; }
r[4]+=0x00000004u;
goto P_0c05bd12;
P_0c05bd12: /* original e314, guest PC 0x0c05bd12 */
if(!s->budget--) { s->failed_pc=0x0c05bd12u; return 0; }
r[3]=0x00000014u;
goto P_0c05bd14;
P_0c05bd14: /* original c783, guest PC 0x0c05bd14 */
if(!s->budget--) { s->failed_pc=0x0c05bd14u; return 0; }
r[0]=code_base|0x0005bf24u;
goto P_0c05bd16;
P_0c05bd16: /* original 33ec, guest PC 0x0c05bd16 */
if(!s->budget--) { s->failed_pc=0x0c05bd16u; return 0; }
r[3]+=r[14];
goto P_0c05bd18;
P_0c05bd18: /* original f408, guest PC 0x0c05bd18 */
if(!s->budget--) { s->failed_pc=0x0c05bd18u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c05bd1a;
P_0c05bd1a: /* original e010, guest PC 0x0c05bd1a */
if(!s->budget--) { s->failed_pc=0x0c05bd1au; return 0; }
r[0]=0x00000010u;
goto P_0c05bd1c;
P_0c05bd1c: /* original f3e6, guest PC 0x0c05bd1c */
if(!s->budget--) { s->failed_pc=0x0c05bd1cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c05bd1e;
P_0c05bd1e: /* original f342, guest PC 0x0c05bd1e */
if(!s->budget--) { s->failed_pc=0x0c05bd1eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05bd20;
P_0c05bd20: /* original f33d, guest PC 0x0c05bd20 */
if(!s->budget--) { s->failed_pc=0x0c05bd20u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05bd22;
P_0c05bd22: /* original 005a, guest PC 0x0c05bd22 */
if(!s->budget--) { s->failed_pc=0x0c05bd22u; return 0; }
r[0]=r[53];
goto P_0c05bd24;
P_0c05bd24: /* original f338, guest PC 0x0c05bd24 */
if(!s->budget--) { s->failed_pc=0x0c05bd24u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c05bd26;
P_0c05bd26: /* original 4028, guest PC 0x0c05bd26 */
if(!s->budget--) { s->failed_pc=0x0c05bd26u; return 0; }
r[0]<<=16;
goto P_0c05bd28;
P_0c05bd28: /* original 4018, guest PC 0x0c05bd28 */
if(!s->budget--) { s->failed_pc=0x0c05bd28u; return 0; }
r[0]<<=8;
goto P_0c05bd2a;
P_0c05bd2a: /* original f342, guest PC 0x0c05bd2a */
if(!s->budget--) { s->failed_pc=0x0c05bd2au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05bd2c;
P_0c05bd2c: /* original f33d, guest PC 0x0c05bd2c */
if(!s->budget--) { s->failed_pc=0x0c05bd2cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05bd2e;
P_0c05bd2e: /* original 035a, guest PC 0x0c05bd2e */
if(!s->budget--) { s->failed_pc=0x0c05bd2eu; return 0; }
r[3]=r[53];
goto P_0c05bd30;
P_0c05bd30: /* original 4328, guest PC 0x0c05bd30 */
if(!s->budget--) { s->failed_pc=0x0c05bd30u; return 0; }
r[3]<<=16;
goto P_0c05bd32;
P_0c05bd32: /* original 203b, guest PC 0x0c05bd32 */
if(!s->budget--) { s->failed_pc=0x0c05bd32u; return 0; }
r[0]|=r[3];
goto P_0c05bd34;
P_0c05bd34: /* original e318, guest PC 0x0c05bd34 */
if(!s->budget--) { s->failed_pc=0x0c05bd34u; return 0; }
r[3]=0x00000018u;
goto P_0c05bd36;
P_0c05bd36: /* original 33ec, guest PC 0x0c05bd36 */
if(!s->budget--) { s->failed_pc=0x0c05bd36u; return 0; }
r[3]+=r[14];
goto P_0c05bd38;
P_0c05bd38: /* original f338, guest PC 0x0c05bd38 */
if(!s->budget--) { s->failed_pc=0x0c05bd38u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c05bd3a;
P_0c05bd3a: /* original f342, guest PC 0x0c05bd3a */
if(!s->budget--) { s->failed_pc=0x0c05bd3au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05bd3c;
P_0c05bd3c: /* original f33d, guest PC 0x0c05bd3c */
if(!s->budget--) { s->failed_pc=0x0c05bd3cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05bd3e;
P_0c05bd3e: /* original 035a, guest PC 0x0c05bd3e */
if(!s->budget--) { s->failed_pc=0x0c05bd3eu; return 0; }
r[3]=r[53];
goto P_0c05bd40;
P_0c05bd40: /* original 4318, guest PC 0x0c05bd40 */
if(!s->budget--) { s->failed_pc=0x0c05bd40u; return 0; }
r[3]<<=8;
goto P_0c05bd42;
P_0c05bd42: /* original 203b, guest PC 0x0c05bd42 */
if(!s->budget--) { s->failed_pc=0x0c05bd42u; return 0; }
r[0]|=r[3];
goto P_0c05bd44;
P_0c05bd44: /* original e31c, guest PC 0x0c05bd44 */
if(!s->budget--) { s->failed_pc=0x0c05bd44u; return 0; }
r[3]=0x0000001cu;
goto P_0c05bd46;
P_0c05bd46: /* original 33ec, guest PC 0x0c05bd46 */
if(!s->budget--) { s->failed_pc=0x0c05bd46u; return 0; }
r[3]+=r[14];
goto P_0c05bd48;
P_0c05bd48: /* original f338, guest PC 0x0c05bd48 */
if(!s->budget--) { s->failed_pc=0x0c05bd48u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c05bd4a;
P_0c05bd4a: /* original f342, guest PC 0x0c05bd4a */
if(!s->budget--) { s->failed_pc=0x0c05bd4au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05bd4c;
P_0c05bd4c: /* original f33d, guest PC 0x0c05bd4c */
if(!s->budget--) { s->failed_pc=0x0c05bd4cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05bd4e;
P_0c05bd4e: /* original 035a, guest PC 0x0c05bd4e */
if(!s->budget--) { s->failed_pc=0x0c05bd4eu; return 0; }
r[3]=r[53];
goto P_0c05bd50;
P_0c05bd50: /* original 203b, guest PC 0x0c05bd50 */
if(!s->budget--) { s->failed_pc=0x0c05bd50u; return 0; }
r[0]|=r[3];
goto P_0c05bd52;
P_0c05bd52: /* original 6e73, guest PC 0x0c05bd52 */
if(!s->budget--) { s->failed_pc=0x0c05bd52u; return 0; }
r[14]=r[7];
goto P_0c05bd54;
P_0c05bd54: /* original 2402, guest PC 0x0c05bd54 */
if(!s->budget--) { s->failed_pc=0x0c05bd54u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05bd56;
P_0c05bd56: /* original 7e10, guest PC 0x0c05bd56 */
if(!s->budget--) { s->failed_pc=0x0c05bd56u; return 0; }
r[14]+=0x00000010u;
goto P_0c05bd58;
P_0c05bd58: /* original 7404, guest PC 0x0c05bd58 */
if(!s->budget--) { s->failed_pc=0x0c05bd58u; return 0; }
r[4]+=0x00000004u;
goto P_0c05bd5a;
P_0c05bd5a: /* original e020, guest PC 0x0c05bd5a */
if(!s->budget--) { s->failed_pc=0x0c05bd5au; return 0; }
r[0]=0x00000020u;
goto P_0c05bd5c;
P_0c05bd5c: /* original f3e6, guest PC 0x0c05bd5c */
if(!s->budget--) { s->failed_pc=0x0c05bd5cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c05bd5e;
P_0c05bd5e: /* original e024, guest PC 0x0c05bd5e */
if(!s->budget--) { s->failed_pc=0x0c05bd5eu; return 0; }
r[0]=0x00000024u;
goto P_0c05bd60;
P_0c05bd60: /* original f342, guest PC 0x0c05bd60 */
if(!s->budget--) { s->failed_pc=0x0c05bd60u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05bd62;
P_0c05bd62: /* original f33d, guest PC 0x0c05bd62 */
if(!s->budget--) { s->failed_pc=0x0c05bd62u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05bd64;
P_0c05bd64: /* original f3e6, guest PC 0x0c05bd64 */
if(!s->budget--) { s->failed_pc=0x0c05bd64u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c05bd66;
P_0c05bd66: /* original 035a, guest PC 0x0c05bd66 */
if(!s->budget--) { s->failed_pc=0x0c05bd66u; return 0; }
r[3]=r[53];
goto P_0c05bd68;
P_0c05bd68: /* original 4328, guest PC 0x0c05bd68 */
if(!s->budget--) { s->failed_pc=0x0c05bd68u; return 0; }
r[3]<<=16;
goto P_0c05bd6a;
P_0c05bd6a: /* original 4318, guest PC 0x0c05bd6a */
if(!s->budget--) { s->failed_pc=0x0c05bd6au; return 0; }
r[3]<<=8;
goto P_0c05bd6c;
P_0c05bd6c: /* original f342, guest PC 0x0c05bd6c */
if(!s->budget--) { s->failed_pc=0x0c05bd6cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05bd6e;
P_0c05bd6e: /* original f33d, guest PC 0x0c05bd6e */
if(!s->budget--) { s->failed_pc=0x0c05bd6eu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05bd70;
P_0c05bd70: /* original 005a, guest PC 0x0c05bd70 */
if(!s->budget--) { s->failed_pc=0x0c05bd70u; return 0; }
r[0]=r[53];
goto P_0c05bd72;
P_0c05bd72: /* original 4028, guest PC 0x0c05bd72 */
if(!s->budget--) { s->failed_pc=0x0c05bd72u; return 0; }
r[0]<<=16;
goto P_0c05bd74;
P_0c05bd74: /* original 230b, guest PC 0x0c05bd74 */
if(!s->budget--) { s->failed_pc=0x0c05bd74u; return 0; }
r[3]|=r[0];
goto P_0c05bd76;
P_0c05bd76: /* original e028, guest PC 0x0c05bd76 */
if(!s->budget--) { s->failed_pc=0x0c05bd76u; return 0; }
r[0]=0x00000028u;
goto P_0c05bd78;
P_0c05bd78: /* original f3e6, guest PC 0x0c05bd78 */
if(!s->budget--) { s->failed_pc=0x0c05bd78u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c05bd7a;
P_0c05bd7a: /* original f342, guest PC 0x0c05bd7a */
if(!s->budget--) { s->failed_pc=0x0c05bd7au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05bd7c;
P_0c05bd7c: /* original f33d, guest PC 0x0c05bd7c */
if(!s->budget--) { s->failed_pc=0x0c05bd7cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05bd7e;
P_0c05bd7e: /* original 005a, guest PC 0x0c05bd7e */
if(!s->budget--) { s->failed_pc=0x0c05bd7eu; return 0; }
r[0]=r[53];
goto P_0c05bd80;
P_0c05bd80: /* original 4018, guest PC 0x0c05bd80 */
if(!s->budget--) { s->failed_pc=0x0c05bd80u; return 0; }
r[0]<<=8;
goto P_0c05bd82;
P_0c05bd82: /* original 230b, guest PC 0x0c05bd82 */
if(!s->budget--) { s->failed_pc=0x0c05bd82u; return 0; }
r[3]|=r[0];
goto P_0c05bd84;
P_0c05bd84: /* original e02c, guest PC 0x0c05bd84 */
if(!s->budget--) { s->failed_pc=0x0c05bd84u; return 0; }
r[0]=0x0000002cu;
goto P_0c05bd86;
P_0c05bd86: /* original f3e6, guest PC 0x0c05bd86 */
if(!s->budget--) { s->failed_pc=0x0c05bd86u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c05bd88;
P_0c05bd88: /* original f342, guest PC 0x0c05bd88 */
if(!s->budget--) { s->failed_pc=0x0c05bd88u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05bd8a;
P_0c05bd8a: /* original f33d, guest PC 0x0c05bd8a */
if(!s->budget--) { s->failed_pc=0x0c05bd8au; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05bd8c;
P_0c05bd8c: /* original 005a, guest PC 0x0c05bd8c */
if(!s->budget--) { s->failed_pc=0x0c05bd8cu; return 0; }
r[0]=r[53];
goto P_0c05bd8e;
P_0c05bd8e: /* original 230b, guest PC 0x0c05bd8e */
if(!s->budget--) { s->failed_pc=0x0c05bd8eu; return 0; }
r[3]|=r[0];
goto P_0c05bd90;
P_0c05bd90: /* original 2432, guest PC 0x0c05bd90 */
if(!s->budget--) { s->failed_pc=0x0c05bd90u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c05bd92;
P_0c05bd92: /* original a004, guest PC 0x0c05bd92 */
if(!s->budget--) { s->failed_pc=0x0c05bd92u; return 0; }
r[4]+=0x0000000cu;
goto P_0c05bd9e;
P_0c05bd94: /* original 740c, guest PC 0x0c05bd94 */
if(!s->budget--) { s->failed_pc=0x0c05bd94u; return 0; }
r[4]+=0x0000000cu;
goto P_0c05bd96;
P_0c05bd96: /* original e040, guest PC 0x0c05bd96 */
if(!s->budget--) { s->failed_pc=0x0c05bd96u; return 0; }
r[0]=0x00000040u;
goto P_0c05bd98;
P_0c05bd98: /* original 017e, guest PC 0x0c05bd98 */
if(!s->budget--) { s->failed_pc=0x0c05bd98u; return 0; }
r[1]=read(ram,r[7]+r[0],4);
goto P_0c05bd9a;
P_0c05bd9a: /* original 2412, guest PC 0x0c05bd9a */
if(!s->budget--) { s->failed_pc=0x0c05bd9au; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bd9c;
P_0c05bd9c: /* original 741c, guest PC 0x0c05bd9c */
if(!s->budget--) { s->failed_pc=0x0c05bd9cu; return 0; }
r[4]+=0x0000001cu;
goto P_0c05bd9e;
P_0c05bd9e: /* original 3468, guest PC 0x0c05bd9e */
if(!s->budget--) { s->failed_pc=0x0c05bd9eu; return 0; }
r[4]-=r[6];
goto P_0c05bda0;
P_0c05bda0: /* original d761, guest PC 0x0c05bda0 */
if(!s->budget--) { s->failed_pc=0x0c05bda0u; return 0; }
r[7]=read(ram,0x0c05bf28u,4);
goto P_0c05bda2;
P_0c05bda2: /* original e000, guest PC 0x0c05bda2 */
if(!s->budget--) { s->failed_pc=0x0c05bda2u; return 0; }
r[0]=0x00000000u;
goto P_0c05bda4;
P_0c05bda4: /* original 6352, guest PC 0x0c05bda4 */
if(!s->budget--) { s->failed_pc=0x0c05bda4u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c05bda6;
P_0c05bda6: /* original 2732, guest PC 0x0c05bda6 */
if(!s->budget--) { s->failed_pc=0x0c05bda6u; return 0; }
write(ram,r[7],r[3],4);
goto P_0c05bda8;
P_0c05bda8: /* original 1741, guest PC 0x0c05bda8 */
if(!s->budget--) { s->failed_pc=0x0c05bda8u; return 0; }
write(ram,r[7]+4,r[4],4);
goto P_0c05bdaa;
P_0c05bdaa: /* original 000b, guest PC 0x0c05bdaa */
if(!s->budget--) { s->failed_pc=0x0c05bdaau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05bdac: /* original 6ef6, guest PC 0x0c05bdac */
if(!s->budget--) { s->failed_pc=0x0c05bdacu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05bdaeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05bdaeu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
