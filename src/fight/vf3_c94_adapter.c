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
int vf3_c94_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c02eed8u: goto P_0c02eed8;
case 0x0c02eedau: goto P_0c02eeda;
case 0x0c02eedcu: goto P_0c02eedc;
case 0x0c02eedeu: goto P_0c02eede;
case 0x0c02eee0u: goto P_0c02eee0;
case 0x0c02eee2u: goto P_0c02eee2;
case 0x0c02eee4u: goto P_0c02eee4;
case 0x0c02eee6u: goto P_0c02eee6;
case 0x0c02eee8u: goto P_0c02eee8;
case 0x0c0364b8u: goto P_0c0364b8;
case 0x0c0364bau: goto P_0c0364ba;
case 0x0c0364bcu: goto P_0c0364bc;
case 0x0c0364beu: goto P_0c0364be;
case 0x0c0364c0u: goto P_0c0364c0;
case 0x0c0364c2u: goto P_0c0364c2;
case 0x0c036dd4u: goto P_0c036dd4;
case 0x0c036dd6u: goto P_0c036dd6;
case 0x0c036dd8u: goto P_0c036dd8;
case 0x0c036ddau: goto P_0c036dda;
case 0x0c036ddcu: goto P_0c036ddc;
case 0x0c036ddeu: goto P_0c036dde;
case 0x0c036de0u: goto P_0c036de0;
case 0x0c036de2u: goto P_0c036de2;
case 0x0c036de4u: goto P_0c036de4;
case 0x0c036de6u: goto P_0c036de6;
case 0x0c036de8u: goto P_0c036de8;
case 0x0c036deau: goto P_0c036dea;
case 0x0c036decu: goto P_0c036dec;
case 0x0c036deeu: goto P_0c036dee;
case 0x0c036df0u: goto P_0c036df0;
case 0x0c036df2u: goto P_0c036df2;
case 0x0c036df4u: goto P_0c036df4;
case 0x0c036df6u: goto P_0c036df6;
case 0x0c036df8u: goto P_0c036df8;
case 0x0c036dfau: goto P_0c036dfa;
case 0x0c036dfcu: goto P_0c036dfc;
case 0x0c036dfeu: goto P_0c036dfe;
case 0x0c036e00u: goto P_0c036e00;
case 0x0c036e02u: goto P_0c036e02;
case 0x0c036e04u: goto P_0c036e04;
case 0x0c036e06u: goto P_0c036e06;
case 0x0c036e08u: goto P_0c036e08;
case 0x0c036e0au: goto P_0c036e0a;
case 0x0c036e0cu: goto P_0c036e0c;
case 0x0c036e0eu: goto P_0c036e0e;
case 0x0c036e10u: goto P_0c036e10;
case 0x0c036e12u: goto P_0c036e12;
case 0x0c036e14u: goto P_0c036e14;
case 0x0c036e16u: goto P_0c036e16;
case 0x0c036e18u: goto P_0c036e18;
case 0x0c036e1au: goto P_0c036e1a;
case 0x0c036e1cu: goto P_0c036e1c;
case 0x0c036e1eu: goto P_0c036e1e;
case 0x0c036e20u: goto P_0c036e20;
case 0x0c03750au: goto P_0c03750a;
case 0x0c03750cu: goto P_0c03750c;
case 0x0c03750eu: goto P_0c03750e;
case 0x0c037510u: goto P_0c037510;
case 0x0c037512u: goto P_0c037512;
case 0x0c037514u: goto P_0c037514;
case 0x0c037516u: goto P_0c037516;
case 0x0c037518u: goto P_0c037518;
case 0x0c03751au: goto P_0c03751a;
case 0x0c03751cu: goto P_0c03751c;
case 0x0c03751eu: goto P_0c03751e;
case 0x0c037520u: goto P_0c037520;
case 0x0c037522u: goto P_0c037522;
case 0x0c037524u: goto P_0c037524;
case 0x0c037526u: goto P_0c037526;
case 0x0c037528u: goto P_0c037528;
case 0x0c03752au: goto P_0c03752a;
case 0x0c03752cu: goto P_0c03752c;
case 0x0c03752eu: goto P_0c03752e;
case 0x0c037530u: goto P_0c037530;
case 0x0c037532u: goto P_0c037532;
case 0x0c037534u: goto P_0c037534;
case 0x0c037536u: goto P_0c037536;
case 0x0c037538u: goto P_0c037538;
case 0x0c03753au: goto P_0c03753a;
case 0x0c03753cu: goto P_0c03753c;
case 0x0c03753eu: goto P_0c03753e;
case 0x0c037540u: goto P_0c037540;
case 0x0c037542u: goto P_0c037542;
case 0x0c037544u: goto P_0c037544;
case 0x0c037546u: goto P_0c037546;
case 0x0c037548u: goto P_0c037548;
case 0x0c037578u: goto P_0c037578;
case 0x0c03757au: goto P_0c03757a;
case 0x0c037864u: goto P_0c037864;
case 0x0c037866u: goto P_0c037866;
case 0x0c037868u: goto P_0c037868;
case 0x0c03786au: goto P_0c03786a;
case 0x0c03786cu: goto P_0c03786c;
case 0x0c03786eu: goto P_0c03786e;
case 0x0c037870u: goto P_0c037870;
case 0x0c037872u: goto P_0c037872;
case 0x0c037874u: goto P_0c037874;
case 0x0c037876u: goto P_0c037876;
case 0x0c037878u: goto P_0c037878;
case 0x0c039080u: goto P_0c039080;
case 0x0c039082u: goto P_0c039082;
case 0x0c039084u: goto P_0c039084;
case 0x0c039086u: goto P_0c039086;
case 0x0c039088u: goto P_0c039088;
case 0x0c03908au: goto P_0c03908a;
case 0x0c03908cu: goto P_0c03908c;
case 0x0c03908eu: goto P_0c03908e;
case 0x0c039090u: goto P_0c039090;
case 0x0c039092u: goto P_0c039092;
case 0x0c039094u: goto P_0c039094;
case 0x0c039096u: goto P_0c039096;
case 0x0c039098u: goto P_0c039098;
case 0x0c03909au: goto P_0c03909a;
case 0x0c03909cu: goto P_0c03909c;
case 0x0c03909eu: goto P_0c03909e;
case 0x0c0390a0u: goto P_0c0390a0;
case 0x0c0390a2u: goto P_0c0390a2;
case 0x0c0390a4u: goto P_0c0390a4;
case 0x0c0390a6u: goto P_0c0390a6;
case 0x0c0390a8u: goto P_0c0390a8;
case 0x0c0390aau: goto P_0c0390aa;
case 0x0c0390acu: goto P_0c0390ac;
case 0x0c0390aeu: goto P_0c0390ae;
case 0x0c0390b0u: goto P_0c0390b0;
case 0x0c0390b2u: goto P_0c0390b2;
case 0x0c0390b4u: goto P_0c0390b4;
case 0x0c0390b6u: goto P_0c0390b6;
case 0x0c0390b8u: goto P_0c0390b8;
case 0x0c0390bau: goto P_0c0390ba;
case 0x0c0390bcu: goto P_0c0390bc;
case 0x0c0390beu: goto P_0c0390be;
case 0x0c0390c0u: goto P_0c0390c0;
case 0x0c0390c2u: goto P_0c0390c2;
case 0x0c0390c4u: goto P_0c0390c4;
case 0x0c0390c6u: goto P_0c0390c6;
case 0x0c0390c8u: goto P_0c0390c8;
case 0x0c0390cau: goto P_0c0390ca;
case 0x0c0390ccu: goto P_0c0390cc;
case 0x0c0390ceu: goto P_0c0390ce;
case 0x0c0390d0u: goto P_0c0390d0;
case 0x0c0390d2u: goto P_0c0390d2;
case 0x0c0390d4u: goto P_0c0390d4;
case 0x0c0390d6u: goto P_0c0390d6;
case 0x0c0390d8u: goto P_0c0390d8;
case 0x0c0390dau: goto P_0c0390da;
case 0x0c0393c0u: goto P_0c0393c0;
case 0x0c0393c2u: goto P_0c0393c2;
case 0x0c0393c4u: goto P_0c0393c4;
case 0x0c0393c6u: goto P_0c0393c6;
case 0x0c0393c8u: goto P_0c0393c8;
case 0x0c0393cau: goto P_0c0393ca;
case 0x0c0393ccu: goto P_0c0393cc;
case 0x0c0393ceu: goto P_0c0393ce;
case 0x0c0393d0u: goto P_0c0393d0;
case 0x0c0393d2u: goto P_0c0393d2;
case 0x0c0393d4u: goto P_0c0393d4;
case 0x0c0393e0u: goto P_0c0393e0;
case 0x0c0393e2u: goto P_0c0393e2;
case 0x0c0393e4u: goto P_0c0393e4;
case 0x0c0393e6u: goto P_0c0393e6;
case 0x0c0393e8u: goto P_0c0393e8;
case 0x0c0393eau: goto P_0c0393ea;
case 0x0c0393ecu: goto P_0c0393ec;
case 0x0c0393eeu: goto P_0c0393ee;
case 0x0c0393f0u: goto P_0c0393f0;
case 0x0c0393f2u: goto P_0c0393f2;
case 0x0c0393f4u: goto P_0c0393f4;
case 0x0c0394e0u: goto P_0c0394e0;
case 0x0c0394e2u: goto P_0c0394e2;
case 0x0c0394e4u: goto P_0c0394e4;
case 0x0c0394e6u: goto P_0c0394e6;
case 0x0c0394e8u: goto P_0c0394e8;
case 0x0c0394eau: goto P_0c0394ea;
case 0x0c0394ecu: goto P_0c0394ec;
case 0x0c0394eeu: goto P_0c0394ee;
case 0x0c0394f0u: goto P_0c0394f0;
case 0x0c0394f2u: goto P_0c0394f2;
case 0x0c0394f4u: goto P_0c0394f4;
case 0x0c0394f6u: goto P_0c0394f6;
case 0x0c0394f8u: goto P_0c0394f8;
case 0x0c0397a0u: goto P_0c0397a0;
case 0x0c0397a2u: goto P_0c0397a2;
case 0x0c0397a4u: goto P_0c0397a4;
case 0x0c0397a6u: goto P_0c0397a6;
case 0x0c0397a8u: goto P_0c0397a8;
case 0x0c0397aau: goto P_0c0397aa;
case 0x0c0397acu: goto P_0c0397ac;
case 0x0c0397aeu: goto P_0c0397ae;
case 0x0c0397b0u: goto P_0c0397b0;
case 0x0c0397b2u: goto P_0c0397b2;
case 0x0c039c90u: goto P_0c039c90;
case 0x0c039c92u: goto P_0c039c92;
case 0x0c039c94u: goto P_0c039c94;
case 0x0c039c96u: goto P_0c039c96;
case 0x0c039c98u: goto P_0c039c98;
case 0x0c039c9au: goto P_0c039c9a;
case 0x0c039c9cu: goto P_0c039c9c;
case 0x0c039c9eu: goto P_0c039c9e;
case 0x0c039ca0u: goto P_0c039ca0;
case 0x0c039ca2u: goto P_0c039ca2;
case 0x0c039ca4u: goto P_0c039ca4;
case 0x0c039ca6u: goto P_0c039ca6;
case 0x0c039ca8u: goto P_0c039ca8;
case 0x0c039caau: goto P_0c039caa;
case 0x0c03b2d0u: goto P_0c03b2d0;
case 0x0c03b2d2u: goto P_0c03b2d2;
case 0x0c03b2d4u: goto P_0c03b2d4;
case 0x0c03b2d6u: goto P_0c03b2d6;
case 0x0c03b2d8u: goto P_0c03b2d8;
case 0x0c03b2dau: goto P_0c03b2da;
case 0x0c03b2dcu: goto P_0c03b2dc;
case 0x0c03b2deu: goto P_0c03b2de;
case 0x0c03b2e0u: goto P_0c03b2e0;
case 0x0c03b2e2u: goto P_0c03b2e2;
case 0x0c03b2e4u: goto P_0c03b2e4;
case 0x0c03b2e6u: goto P_0c03b2e6;
case 0x0c03b2e8u: goto P_0c03b2e8;
case 0x0c03b2eau: goto P_0c03b2ea;
case 0x0c03b2ecu: goto P_0c03b2ec;
case 0x0c03b2eeu: goto P_0c03b2ee;
case 0x0c03b2f0u: goto P_0c03b2f0;
case 0x0c03b2f2u: goto P_0c03b2f2;
case 0x0c03b2f4u: goto P_0c03b2f4;
case 0x0c03d0c0u: goto P_0c03d0c0;
case 0x0c03d0c2u: goto P_0c03d0c2;
case 0x0c03d0c4u: goto P_0c03d0c4;
case 0x0c03d0c6u: goto P_0c03d0c6;
case 0x0c03d0c8u: goto P_0c03d0c8;
case 0x0c03d0cau: goto P_0c03d0ca;
case 0x0c03d0ccu: goto P_0c03d0cc;
case 0x0c03d0ceu: goto P_0c03d0ce;
case 0x0c03d0d0u: goto P_0c03d0d0;
case 0x0c03d0d2u: goto P_0c03d0d2;
case 0x0c03d0d4u: goto P_0c03d0d4;
case 0x0c03d0d6u: goto P_0c03d0d6;
case 0x0c03d0d8u: goto P_0c03d0d8;
case 0x0c03d0dau: goto P_0c03d0da;
case 0x0c03d280u: goto P_0c03d280;
case 0x0c03d282u: goto P_0c03d282;
case 0x0c03d284u: goto P_0c03d284;
case 0x0c03d286u: goto P_0c03d286;
case 0x0c03d288u: goto P_0c03d288;
case 0x0c03d28au: goto P_0c03d28a;
case 0x0c03d28cu: goto P_0c03d28c;
case 0x0c03d28eu: goto P_0c03d28e;
case 0x0c03d290u: goto P_0c03d290;
case 0x0c03d292u: goto P_0c03d292;
case 0x0c03d294u: goto P_0c03d294;
case 0x0c03d296u: goto P_0c03d296;
case 0x0c03d298u: goto P_0c03d298;
case 0x0c03d29au: goto P_0c03d29a;
case 0x0c03d29cu: goto P_0c03d29c;
case 0x0c03d29eu: goto P_0c03d29e;
case 0x0c03d2a0u: goto P_0c03d2a0;
case 0x0c03d2a2u: goto P_0c03d2a2;
case 0x0c03d2a4u: goto P_0c03d2a4;
case 0x0c03d2a6u: goto P_0c03d2a6;
case 0x0c03da30u: goto P_0c03da30;
case 0x0c03da32u: goto P_0c03da32;
case 0x0c03da34u: goto P_0c03da34;
case 0x0c03da36u: goto P_0c03da36;
case 0x0c03da38u: goto P_0c03da38;
case 0x0c03da3au: goto P_0c03da3a;
case 0x0c03da3cu: goto P_0c03da3c;
case 0x0c03da3eu: goto P_0c03da3e;
case 0x0c03da40u: goto P_0c03da40;
case 0x0c03da42u: goto P_0c03da42;
case 0x0c03da44u: goto P_0c03da44;
case 0x0c03da46u: goto P_0c03da46;
case 0x0c03da48u: goto P_0c03da48;
case 0x0c03da4au: goto P_0c03da4a;
case 0x0c03da4cu: goto P_0c03da4c;
case 0x0c03da4eu: goto P_0c03da4e;
case 0x0c03ecd0u: goto P_0c03ecd0;
case 0x0c03ecd2u: goto P_0c03ecd2;
case 0x0c03ecd4u: goto P_0c03ecd4;
case 0x0c03ecd6u: goto P_0c03ecd6;
case 0x0c03ecd8u: goto P_0c03ecd8;
case 0x0c03ecdau: goto P_0c03ecda;
case 0x0c03ecdcu: goto P_0c03ecdc;
case 0x0c03ecdeu: goto P_0c03ecde;
case 0x0c03ece0u: goto P_0c03ece0;
case 0x0c03ece2u: goto P_0c03ece2;
case 0x0c03ece4u: goto P_0c03ece4;
case 0x0c03ece6u: goto P_0c03ece6;
case 0x0c03ece8u: goto P_0c03ece8;
case 0x0c03eceau: goto P_0c03ecea;
case 0x0c03ececu: goto P_0c03ecec;
case 0x0c03ed20u: goto P_0c03ed20;
case 0x0c03ed22u: goto P_0c03ed22;
case 0x0c03ed24u: goto P_0c03ed24;
case 0x0c03ed26u: goto P_0c03ed26;
case 0x0c03ed28u: goto P_0c03ed28;
case 0x0c03ed2au: goto P_0c03ed2a;
case 0x0c03ed2cu: goto P_0c03ed2c;
case 0x0c03ed2eu: goto P_0c03ed2e;
case 0x0c03ed30u: goto P_0c03ed30;
case 0x0c03ed32u: goto P_0c03ed32;
case 0x0c03ed34u: goto P_0c03ed34;
case 0x0c03ed36u: goto P_0c03ed36;
case 0x0c03ed38u: goto P_0c03ed38;
case 0x0c03ed3au: goto P_0c03ed3a;
case 0x0c03ed3cu: goto P_0c03ed3c;
case 0x0c03ed3eu: goto P_0c03ed3e;
case 0x0c03ed40u: goto P_0c03ed40;
case 0x0c03ed42u: goto P_0c03ed42;
case 0x0c03ed44u: goto P_0c03ed44;
case 0x0c03ef10u: goto P_0c03ef10;
case 0x0c03ef12u: goto P_0c03ef12;
case 0x0c03ef14u: goto P_0c03ef14;
case 0x0c03ef16u: goto P_0c03ef16;
case 0x0c03ef18u: goto P_0c03ef18;
case 0x0c03ef1au: goto P_0c03ef1a;
case 0x0c03ef1cu: goto P_0c03ef1c;
case 0x0c03ef1eu: goto P_0c03ef1e;
case 0x0c03ef20u: goto P_0c03ef20;
case 0x0c03ef22u: goto P_0c03ef22;
case 0x0c03ef24u: goto P_0c03ef24;
case 0x0c03ef26u: goto P_0c03ef26;
case 0x0c03ef28u: goto P_0c03ef28;
case 0x0c03ef2au: goto P_0c03ef2a;
case 0x0c03ef2cu: goto P_0c03ef2c;
case 0x0c03ef2eu: goto P_0c03ef2e;
case 0x0c03ef30u: goto P_0c03ef30;
case 0x0c03ef32u: goto P_0c03ef32;
case 0x0c03ef34u: goto P_0c03ef34;
case 0x0c03ef36u: goto P_0c03ef36;
case 0x0c03ef38u: goto P_0c03ef38;
case 0x0c03ef3au: goto P_0c03ef3a;
case 0x0c03ef3cu: goto P_0c03ef3c;
case 0x0c03ef3eu: goto P_0c03ef3e;
case 0x0c03ef40u: goto P_0c03ef40;
case 0x0c03ef42u: goto P_0c03ef42;
case 0x0c03ef44u: goto P_0c03ef44;
case 0x0c03ef46u: goto P_0c03ef46;
case 0x0c03ef48u: goto P_0c03ef48;
case 0x0c03ef4au: goto P_0c03ef4a;
case 0x0c03ef4cu: goto P_0c03ef4c;
case 0x0c03ef4eu: goto P_0c03ef4e;
case 0x0c03ef50u: goto P_0c03ef50;
case 0x0c03ef52u: goto P_0c03ef52;
case 0x0c03ef54u: goto P_0c03ef54;
case 0x0c03ef56u: goto P_0c03ef56;
case 0x0c03ef58u: goto P_0c03ef58;
case 0x0c03ef5au: goto P_0c03ef5a;
case 0x0c03ef5cu: goto P_0c03ef5c;
case 0x0c03ef5eu: goto P_0c03ef5e;
case 0x0c03ef60u: goto P_0c03ef60;
case 0x0c03ef62u: goto P_0c03ef62;
case 0x0c03ef64u: goto P_0c03ef64;
case 0x0c03ef66u: goto P_0c03ef66;
case 0x0c03ef68u: goto P_0c03ef68;
case 0x0c03ef6au: goto P_0c03ef6a;
case 0x0c03ef6cu: goto P_0c03ef6c;
case 0x0c03ef6eu: goto P_0c03ef6e;
case 0x0c03ef70u: goto P_0c03ef70;
case 0x0c03ef72u: goto P_0c03ef72;
case 0x0c03ef74u: goto P_0c03ef74;
case 0x0c03ef76u: goto P_0c03ef76;
case 0x0c03ef78u: goto P_0c03ef78;
case 0x0c03ef7au: goto P_0c03ef7a;
case 0x0c03ef7cu: goto P_0c03ef7c;
case 0x0c03ef7eu: goto P_0c03ef7e;
case 0x0c03ef80u: goto P_0c03ef80;
case 0x0c03ef82u: goto P_0c03ef82;
case 0x0c03ef84u: goto P_0c03ef84;
case 0x0c03ef86u: goto P_0c03ef86;
case 0x0c03ef88u: goto P_0c03ef88;
case 0x0c03ef8au: goto P_0c03ef8a;
case 0x0c03ef8cu: goto P_0c03ef8c;
case 0x0c03ef8eu: goto P_0c03ef8e;
case 0x0c03ef90u: goto P_0c03ef90;
case 0x0c03ffb0u: goto P_0c03ffb0;
case 0x0c03ffb2u: goto P_0c03ffb2;
case 0x0c03ffb4u: goto P_0c03ffb4;
case 0x0c03ffb6u: goto P_0c03ffb6;
case 0x0c03ffb8u: goto P_0c03ffb8;
case 0x0c03ffbau: goto P_0c03ffba;
case 0x0c03ffbcu: goto P_0c03ffbc;
case 0x0c03ffbeu: goto P_0c03ffbe;
case 0x0c043e52u: goto P_0c043e52;
case 0x0c043e54u: goto P_0c043e54;
case 0x0c043e56u: goto P_0c043e56;
case 0x0c043e58u: goto P_0c043e58;
case 0x0c043e5au: goto P_0c043e5a;
case 0x0c043e5cu: goto P_0c043e5c;
case 0x0c043e5eu: goto P_0c043e5e;
case 0x0c043e60u: goto P_0c043e60;
case 0x0c043e62u: goto P_0c043e62;
case 0x0c043e64u: goto P_0c043e64;
case 0x0c043e66u: goto P_0c043e66;
case 0x0c043e68u: goto P_0c043e68;
case 0x0c043e6au: goto P_0c043e6a;
case 0x0c043e6cu: goto P_0c043e6c;
case 0x0c043e6eu: goto P_0c043e6e;
case 0x0c043e70u: goto P_0c043e70;
case 0x0c043e72u: goto P_0c043e72;
case 0x0c043e74u: goto P_0c043e74;
case 0x0c043e76u: goto P_0c043e76;
case 0x0c043e78u: goto P_0c043e78;
case 0x0c043e7au: goto P_0c043e7a;
case 0x0c043e7cu: goto P_0c043e7c;
case 0x0c043e7eu: goto P_0c043e7e;
case 0x0c043e80u: goto P_0c043e80;
case 0x0c043e82u: goto P_0c043e82;
case 0x0c043e84u: goto P_0c043e84;
case 0x0c043e86u: goto P_0c043e86;
case 0x0c043e88u: goto P_0c043e88;
case 0x0c043e8au: goto P_0c043e8a;
case 0x0c043e8cu: goto P_0c043e8c;
case 0x0c043e8eu: goto P_0c043e8e;
case 0x0c043e90u: goto P_0c043e90;
case 0x0c043e92u: goto P_0c043e92;
case 0x0c043e94u: goto P_0c043e94;
case 0x0c043e96u: goto P_0c043e96;
case 0x0c043e98u: goto P_0c043e98;
case 0x0c043e9au: goto P_0c043e9a;
case 0x0c043e9cu: goto P_0c043e9c;
case 0x0c043e9eu: goto P_0c043e9e;
case 0x0c043ea0u: goto P_0c043ea0;
case 0x0c043ea2u: goto P_0c043ea2;
case 0x0c043ea4u: goto P_0c043ea4;
case 0x0c043ea6u: goto P_0c043ea6;
case 0x0c043ea8u: goto P_0c043ea8;
case 0x0c043eaau: goto P_0c043eaa;
case 0x0c043eacu: goto P_0c043eac;
case 0x0c043eaeu: goto P_0c043eae;
case 0x0c043eb0u: goto P_0c043eb0;
case 0x0c043eb2u: goto P_0c043eb2;
case 0x0c043eb4u: goto P_0c043eb4;
case 0x0c043eb6u: goto P_0c043eb6;
case 0x0c0459bcu: goto P_0c0459bc;
case 0x0c0459beu: goto P_0c0459be;
case 0x0c0459c0u: goto P_0c0459c0;
case 0x0c0459c2u: goto P_0c0459c2;
case 0x0c0459c4u: goto P_0c0459c4;
case 0x0c0459c6u: goto P_0c0459c6;
case 0x0c0459c8u: goto P_0c0459c8;
case 0x0c0459cau: goto P_0c0459ca;
case 0x0c0459ccu: goto P_0c0459cc;
case 0x0c0459ceu: goto P_0c0459ce;
case 0x0c0459d0u: goto P_0c0459d0;
case 0x0c0459d2u: goto P_0c0459d2;
case 0x0c0459d4u: goto P_0c0459d4;
case 0x0c0459d6u: goto P_0c0459d6;
case 0x0c0459d8u: goto P_0c0459d8;
case 0x0c0459dau: goto P_0c0459da;
case 0x0c0459dcu: goto P_0c0459dc;
case 0x0c0459deu: goto P_0c0459de;
case 0x0c0459e0u: goto P_0c0459e0;
case 0x0c0459e2u: goto P_0c0459e2;
case 0x0c0459e4u: goto P_0c0459e4;
case 0x0c045a34u: goto P_0c045a34;
case 0x0c045a36u: goto P_0c045a36;
case 0x0c045a38u: goto P_0c045a38;
case 0x0c045a3au: goto P_0c045a3a;
case 0x0c045a3cu: goto P_0c045a3c;
case 0x0c045a3eu: goto P_0c045a3e;
case 0x0c045a40u: goto P_0c045a40;
case 0x0c045a42u: goto P_0c045a42;
case 0x0c045a44u: goto P_0c045a44;
case 0x0c045a46u: goto P_0c045a46;
case 0x0c045a48u: goto P_0c045a48;
case 0x0c045a4au: goto P_0c045a4a;
case 0x0c045a4cu: goto P_0c045a4c;
case 0x0c045a4eu: goto P_0c045a4e;
case 0x0c045a50u: goto P_0c045a50;
case 0x0c045a52u: goto P_0c045a52;
case 0x0c045a54u: goto P_0c045a54;
case 0x0c045a56u: goto P_0c045a56;
case 0x0c045a58u: goto P_0c045a58;
case 0x0c045a5au: goto P_0c045a5a;
case 0x0c045a5cu: goto P_0c045a5c;
case 0x0c045a8au: goto P_0c045a8a;
case 0x0c045a8cu: goto P_0c045a8c;
case 0x0c045a8eu: goto P_0c045a8e;
case 0x0c045a90u: goto P_0c045a90;
case 0x0c045a92u: goto P_0c045a92;
case 0x0c045a94u: goto P_0c045a94;
case 0x0c045a96u: goto P_0c045a96;
case 0x0c045a98u: goto P_0c045a98;
case 0x0c045a9au: goto P_0c045a9a;
case 0x0c045a9cu: goto P_0c045a9c;
case 0x0c045a9eu: goto P_0c045a9e;
case 0x0c045aa0u: goto P_0c045aa0;
case 0x0c045aa2u: goto P_0c045aa2;
case 0x0c045aa4u: goto P_0c045aa4;
case 0x0c045aa6u: goto P_0c045aa6;
case 0x0c045aa8u: goto P_0c045aa8;
case 0x0c045aaau: goto P_0c045aaa;
case 0x0c045aacu: goto P_0c045aac;
case 0x0c045aaeu: goto P_0c045aae;
case 0x0c045ab0u: goto P_0c045ab0;
case 0x0c045ab2u: goto P_0c045ab2;
case 0x0c045ae0u: goto P_0c045ae0;
case 0x0c045ae2u: goto P_0c045ae2;
case 0x0c045ae4u: goto P_0c045ae4;
case 0x0c045ae6u: goto P_0c045ae6;
case 0x0c045ae8u: goto P_0c045ae8;
case 0x0c045aeau: goto P_0c045aea;
case 0x0c045aecu: goto P_0c045aec;
case 0x0c045aeeu: goto P_0c045aee;
case 0x0c045af0u: goto P_0c045af0;
case 0x0c045af2u: goto P_0c045af2;
case 0x0c045af4u: goto P_0c045af4;
case 0x0c045af6u: goto P_0c045af6;
case 0x0c045af8u: goto P_0c045af8;
case 0x0c045afau: goto P_0c045afa;
case 0x0c045afcu: goto P_0c045afc;
case 0x0c045afeu: goto P_0c045afe;
case 0x0c045b00u: goto P_0c045b00;
case 0x0c045b02u: goto P_0c045b02;
case 0x0c045b04u: goto P_0c045b04;
case 0x0c045b06u: goto P_0c045b06;
case 0x0c045b08u: goto P_0c045b08;
case 0x0c045b36u: goto P_0c045b36;
case 0x0c045b38u: goto P_0c045b38;
case 0x0c045b3au: goto P_0c045b3a;
case 0x0c045b3cu: goto P_0c045b3c;
case 0x0c045b3eu: goto P_0c045b3e;
case 0x0c045b40u: goto P_0c045b40;
case 0x0c045b42u: goto P_0c045b42;
case 0x0c045b44u: goto P_0c045b44;
case 0x0c045b46u: goto P_0c045b46;
case 0x0c045b48u: goto P_0c045b48;
case 0x0c045b4au: goto P_0c045b4a;
case 0x0c045b4cu: goto P_0c045b4c;
case 0x0c045b4eu: goto P_0c045b4e;
case 0x0c045b50u: goto P_0c045b50;
case 0x0c045b52u: goto P_0c045b52;
case 0x0c045b54u: goto P_0c045b54;
case 0x0c045b56u: goto P_0c045b56;
case 0x0c045b58u: goto P_0c045b58;
case 0x0c045b5au: goto P_0c045b5a;
case 0x0c045b5cu: goto P_0c045b5c;
case 0x0c045b5eu: goto P_0c045b5e;
case 0x0c045d14u: goto P_0c045d14;
case 0x0c045d16u: goto P_0c045d16;
case 0x0c045d18u: goto P_0c045d18;
case 0x0c045d1au: goto P_0c045d1a;
case 0x0c045d1cu: goto P_0c045d1c;
case 0x0c045d1eu: goto P_0c045d1e;
case 0x0c045d20u: goto P_0c045d20;
case 0x0c045d22u: goto P_0c045d22;
case 0x0c045d24u: goto P_0c045d24;
case 0x0c045d26u: goto P_0c045d26;
case 0x0c045d28u: goto P_0c045d28;
case 0x0c045d2au: goto P_0c045d2a;
case 0x0c045d2cu: goto P_0c045d2c;
case 0x0c045d2eu: goto P_0c045d2e;
case 0x0c045d30u: goto P_0c045d30;
case 0x0c045d32u: goto P_0c045d32;
case 0x0c045d34u: goto P_0c045d34;
case 0x0c045d36u: goto P_0c045d36;
case 0x0c045d38u: goto P_0c045d38;
case 0x0c045d3au: goto P_0c045d3a;
case 0x0c045d3cu: goto P_0c045d3c;
case 0x0c045d5au: goto P_0c045d5a;
case 0x0c045d5cu: goto P_0c045d5c;
case 0x0c045d5eu: goto P_0c045d5e;
case 0x0c045d60u: goto P_0c045d60;
case 0x0c045d62u: goto P_0c045d62;
case 0x0c045d64u: goto P_0c045d64;
case 0x0c045d66u: goto P_0c045d66;
case 0x0c045d68u: goto P_0c045d68;
case 0x0c045d6au: goto P_0c045d6a;
case 0x0c045d6cu: goto P_0c045d6c;
case 0x0c045d6eu: goto P_0c045d6e;
case 0x0c045d70u: goto P_0c045d70;
case 0x0c045d72u: goto P_0c045d72;
case 0x0c045d74u: goto P_0c045d74;
case 0x0c045d76u: goto P_0c045d76;
case 0x0c045d78u: goto P_0c045d78;
case 0x0c045d7au: goto P_0c045d7a;
case 0x0c045d7cu: goto P_0c045d7c;
case 0x0c045d7eu: goto P_0c045d7e;
case 0x0c045d80u: goto P_0c045d80;
case 0x0c045d82u: goto P_0c045d82;
case 0x0c045e94u: goto P_0c045e94;
case 0x0c045e96u: goto P_0c045e96;
case 0x0c045e98u: goto P_0c045e98;
case 0x0c045e9au: goto P_0c045e9a;
case 0x0c045e9cu: goto P_0c045e9c;
case 0x0c045e9eu: goto P_0c045e9e;
case 0x0c045ea0u: goto P_0c045ea0;
case 0x0c045ea2u: goto P_0c045ea2;
case 0x0c045ea4u: goto P_0c045ea4;
case 0x0c045ea6u: goto P_0c045ea6;
case 0x0c045ea8u: goto P_0c045ea8;
case 0x0c045eaau: goto P_0c045eaa;
case 0x0c045eacu: goto P_0c045eac;
case 0x0c045eaeu: goto P_0c045eae;
case 0x0c045eb0u: goto P_0c045eb0;
case 0x0c045eb2u: goto P_0c045eb2;
case 0x0c045eb4u: goto P_0c045eb4;
case 0x0c045eb6u: goto P_0c045eb6;
case 0x0c045eb8u: goto P_0c045eb8;
case 0x0c045ebau: goto P_0c045eba;
case 0x0c045ebcu: goto P_0c045ebc;
case 0x0c050bfeu: goto P_0c050bfe;
case 0x0c050c00u: goto P_0c050c00;
case 0x0c050c02u: goto P_0c050c02;
case 0x0c050c04u: goto P_0c050c04;
case 0x0c050c06u: goto P_0c050c06;
case 0x0c050c08u: goto P_0c050c08;
case 0x0c050c0au: goto P_0c050c0a;
case 0x0c050c0cu: goto P_0c050c0c;
case 0x0c050c0eu: goto P_0c050c0e;
case 0x0c050c10u: goto P_0c050c10;
case 0x0c050c12u: goto P_0c050c12;
case 0x0c050c14u: goto P_0c050c14;
case 0x0c050c16u: goto P_0c050c16;
case 0x0c050c18u: goto P_0c050c18;
case 0x0c050c1au: goto P_0c050c1a;
case 0x0c050c1cu: goto P_0c050c1c;
case 0x0c050c1eu: goto P_0c050c1e;
case 0x0c050c20u: goto P_0c050c20;
case 0x0c050c22u: goto P_0c050c22;
case 0x0c050c24u: goto P_0c050c24;
case 0x0c050c26u: goto P_0c050c26;
case 0x0c050c28u: goto P_0c050c28;
case 0x0c050c2au: goto P_0c050c2a;
case 0x0c050c2cu: goto P_0c050c2c;
case 0x0c050c2eu: goto P_0c050c2e;
case 0x0c050c30u: goto P_0c050c30;
case 0x0c050c32u: goto P_0c050c32;
case 0x0c051324u: goto P_0c051324;
case 0x0c051326u: goto P_0c051326;
case 0x0c051328u: goto P_0c051328;
case 0x0c05132au: goto P_0c05132a;
case 0x0c05132cu: goto P_0c05132c;
case 0x0c05132eu: goto P_0c05132e;
case 0x0c051330u: goto P_0c051330;
case 0x0c051332u: goto P_0c051332;
case 0x0c051334u: goto P_0c051334;
case 0x0c051336u: goto P_0c051336;
case 0x0c051338u: goto P_0c051338;
case 0x0c05133au: goto P_0c05133a;
case 0x0c05133cu: goto P_0c05133c;
case 0x0c051340u: goto P_0c051340;
case 0x0c051342u: goto P_0c051342;
case 0x0c051344u: goto P_0c051344;
case 0x0c051346u: goto P_0c051346;
case 0x0c051348u: goto P_0c051348;
case 0x0c051350u: goto P_0c051350;
case 0x0c051352u: goto P_0c051352;
case 0x0c051354u: goto P_0c051354;
case 0x0c051356u: goto P_0c051356;
case 0x0c051358u: goto P_0c051358;
case 0x0c05135au: goto P_0c05135a;
case 0x0c05135cu: goto P_0c05135c;
case 0x0c05135eu: goto P_0c05135e;
case 0x0c051360u: goto P_0c051360;
case 0x0c051362u: goto P_0c051362;
case 0x0c051364u: goto P_0c051364;
case 0x0c051366u: goto P_0c051366;
case 0x0c051368u: goto P_0c051368;
case 0x0c05136au: goto P_0c05136a;
case 0x0c05136cu: goto P_0c05136c;
case 0x0c05136eu: goto P_0c05136e;
case 0x0c051370u: goto P_0c051370;
case 0x0c051372u: goto P_0c051372;
case 0x0c051374u: goto P_0c051374;
case 0x0c051376u: goto P_0c051376;
case 0x0c051378u: goto P_0c051378;
case 0x0c05137au: goto P_0c05137a;
case 0x0c05137cu: goto P_0c05137c;
case 0x0c05137eu: goto P_0c05137e;
case 0x0c051380u: goto P_0c051380;
case 0x0c051382u: goto P_0c051382;
case 0x0c051384u: goto P_0c051384;
case 0x0c051386u: goto P_0c051386;
case 0x0c051388u: goto P_0c051388;
case 0x0c05138au: goto P_0c05138a;
case 0x0c05138cu: goto P_0c05138c;
case 0x0c05138eu: goto P_0c05138e;
case 0x0c051390u: goto P_0c051390;
case 0x0c051392u: goto P_0c051392;
case 0x0c051394u: goto P_0c051394;
case 0x0c051396u: goto P_0c051396;
case 0x0c051398u: goto P_0c051398;
case 0x0c05139au: goto P_0c05139a;
case 0x0c05139cu: goto P_0c05139c;
case 0x0c05139eu: goto P_0c05139e;
case 0x0c0513a0u: goto P_0c0513a0;
case 0x0c0513a2u: goto P_0c0513a2;
case 0x0c0513a4u: goto P_0c0513a4;
case 0x0c0513a6u: goto P_0c0513a6;
case 0x0c0513a8u: goto P_0c0513a8;
case 0x0c0513aau: goto P_0c0513aa;
case 0x0c0513acu: goto P_0c0513ac;
case 0x0c0513aeu: goto P_0c0513ae;
case 0x0c0513b0u: goto P_0c0513b0;
case 0x0c0513b2u: goto P_0c0513b2;
case 0x0c0513b4u: goto P_0c0513b4;
case 0x0c0513b6u: goto P_0c0513b6;
case 0x0c0513b8u: goto P_0c0513b8;
case 0x0c0513bau: goto P_0c0513ba;
case 0x0c0513bcu: goto P_0c0513bc;
case 0x0c0513beu: goto P_0c0513be;
case 0x0c0513c0u: goto P_0c0513c0;
case 0x0c0513c2u: goto P_0c0513c2;
case 0x0c0513c4u: goto P_0c0513c4;
case 0x0c0513c6u: goto P_0c0513c6;
case 0x0c0513c8u: goto P_0c0513c8;
case 0x0c0513cau: goto P_0c0513ca;
case 0x0c0513ccu: goto P_0c0513cc;
case 0x0c0513ceu: goto P_0c0513ce;
case 0x0c0513d0u: goto P_0c0513d0;
case 0x0c0513d2u: goto P_0c0513d2;
case 0x0c0513d4u: goto P_0c0513d4;
case 0x0c0513d6u: goto P_0c0513d6;
case 0x0c0513d8u: goto P_0c0513d8;
case 0x0c0513dau: goto P_0c0513da;
case 0x0c0513dcu: goto P_0c0513dc;
case 0x0c0513deu: goto P_0c0513de;
case 0x0c0513e0u: goto P_0c0513e0;
case 0x0c0513e2u: goto P_0c0513e2;
case 0x0c0513e4u: goto P_0c0513e4;
case 0x0c0513e6u: goto P_0c0513e6;
case 0x0c0513e8u: goto P_0c0513e8;
case 0x0c0513eau: goto P_0c0513ea;
case 0x0c0513ecu: goto P_0c0513ec;
case 0x0c051400u: goto P_0c051400;
case 0x0c051402u: goto P_0c051402;
case 0x0c051404u: goto P_0c051404;
case 0x0c051406u: goto P_0c051406;
case 0x0c051408u: goto P_0c051408;
case 0x0c05140au: goto P_0c05140a;
case 0x0c05140cu: goto P_0c05140c;
case 0x0c05140eu: goto P_0c05140e;
case 0x0c051410u: goto P_0c051410;
case 0x0c051412u: goto P_0c051412;
case 0x0c051414u: goto P_0c051414;
case 0x0c054530u: goto P_0c054530;
case 0x0c054532u: goto P_0c054532;
case 0x0c054534u: goto P_0c054534;
case 0x0c054536u: goto P_0c054536;
case 0x0c054538u: goto P_0c054538;
case 0x0c05453au: goto P_0c05453a;
case 0x0c05453cu: goto P_0c05453c;
case 0x0c058780u: goto P_0c058780;
case 0x0c058782u: goto P_0c058782;
case 0x0c058784u: goto P_0c058784;
case 0x0c058788u: goto P_0c058788;
case 0x0c05878au: goto P_0c05878a;
case 0x0c05878cu: goto P_0c05878c;
case 0x0c0587d8u: goto P_0c0587d8;
case 0x0c0587dau: goto P_0c0587da;
case 0x0c0587dcu: goto P_0c0587dc;
case 0x0c0587deu: goto P_0c0587de;
case 0x0c0587e0u: goto P_0c0587e0;
case 0x0c0587e2u: goto P_0c0587e2;
case 0x0c0587e4u: goto P_0c0587e4;
case 0x0c0587e6u: goto P_0c0587e6;
case 0x0c0587e8u: goto P_0c0587e8;
case 0x0c0587eau: goto P_0c0587ea;
case 0x0c0587ecu: goto P_0c0587ec;
case 0x0c0587eeu: goto P_0c0587ee;
case 0x0c0587f0u: goto P_0c0587f0;
case 0x0c0587f2u: goto P_0c0587f2;
case 0x0c0587f4u: goto P_0c0587f4;
case 0x0c0587f6u: goto P_0c0587f6;
case 0x0c0587f8u: goto P_0c0587f8;
case 0x0c0587fau: goto P_0c0587fa;
case 0x0c0587fcu: goto P_0c0587fc;
case 0x0c0587feu: goto P_0c0587fe;
case 0x0c058800u: goto P_0c058800;
case 0x0c058802u: goto P_0c058802;
case 0x0c058804u: goto P_0c058804;
case 0x0c058806u: goto P_0c058806;
case 0x0c058808u: goto P_0c058808;
case 0x0c05880au: goto P_0c05880a;
case 0x0c05880cu: goto P_0c05880c;
case 0x0c05880eu: goto P_0c05880e;
case 0x0c058810u: goto P_0c058810;
case 0x0c058812u: goto P_0c058812;
case 0x0c058814u: goto P_0c058814;
case 0x0c058816u: goto P_0c058816;
case 0x0c058818u: goto P_0c058818;
case 0x0c05881au: goto P_0c05881a;
case 0x0c05881cu: goto P_0c05881c;
case 0x0c05881eu: goto P_0c05881e;
case 0x0c058820u: goto P_0c058820;
case 0x0c058822u: goto P_0c058822;
case 0x0c058824u: goto P_0c058824;
case 0x0c058826u: goto P_0c058826;
case 0x0c058828u: goto P_0c058828;
case 0x0c05882au: goto P_0c05882a;
case 0x0c05882cu: goto P_0c05882c;
case 0x0c05882eu: goto P_0c05882e;
case 0x0c058830u: goto P_0c058830;
case 0x0c058832u: goto P_0c058832;
case 0x0c058834u: goto P_0c058834;
case 0x0c058836u: goto P_0c058836;
case 0x0c058838u: goto P_0c058838;
case 0x0c05883au: goto P_0c05883a;
case 0x0c05883cu: goto P_0c05883c;
case 0x0c05883eu: goto P_0c05883e;
case 0x0c058840u: goto P_0c058840;
case 0x0c058842u: goto P_0c058842;
case 0x0c058844u: goto P_0c058844;
case 0x0c058846u: goto P_0c058846;
case 0x0c058848u: goto P_0c058848;
case 0x0c05884au: goto P_0c05884a;
case 0x0c05884cu: goto P_0c05884c;
case 0x0c05884eu: goto P_0c05884e;
case 0x0c058850u: goto P_0c058850;
case 0x0c058852u: goto P_0c058852;
case 0x0c058854u: goto P_0c058854;
case 0x0c058856u: goto P_0c058856;
case 0x0c058858u: goto P_0c058858;
case 0x0c05885au: goto P_0c05885a;
case 0x0c05885cu: goto P_0c05885c;
case 0x0c05885eu: goto P_0c05885e;
case 0x0c058860u: goto P_0c058860;
case 0x0c058862u: goto P_0c058862;
case 0x0c058864u: goto P_0c058864;
case 0x0c058866u: goto P_0c058866;
case 0x0c058868u: goto P_0c058868;
case 0x0c05886au: goto P_0c05886a;
case 0x0c05886cu: goto P_0c05886c;
case 0x0c05886eu: goto P_0c05886e;
case 0x0c058870u: goto P_0c058870;
case 0x0c058872u: goto P_0c058872;
case 0x0c058874u: goto P_0c058874;
case 0x0c058876u: goto P_0c058876;
case 0x0c058878u: goto P_0c058878;
case 0x0c05887au: goto P_0c05887a;
case 0x0c05887cu: goto P_0c05887c;
case 0x0c05887eu: goto P_0c05887e;
case 0x0c058880u: goto P_0c058880;
case 0x0c058882u: goto P_0c058882;
case 0x0c058884u: goto P_0c058884;
case 0x0c058886u: goto P_0c058886;
case 0x0c058888u: goto P_0c058888;
case 0x0c05888au: goto P_0c05888a;
case 0x0c05888cu: goto P_0c05888c;
case 0x0c05888eu: goto P_0c05888e;
case 0x0c058890u: goto P_0c058890;
case 0x0c058892u: goto P_0c058892;
case 0x0c058894u: goto P_0c058894;
case 0x0c058896u: goto P_0c058896;
case 0x0c058898u: goto P_0c058898;
case 0x0c05889au: goto P_0c05889a;
case 0x0c05889cu: goto P_0c05889c;
case 0x0c05889eu: goto P_0c05889e;
case 0x0c0588a0u: goto P_0c0588a0;
case 0x0c0588a2u: goto P_0c0588a2;
case 0x0c0588a4u: goto P_0c0588a4;
case 0x0c0588a6u: goto P_0c0588a6;
case 0x0c0588a8u: goto P_0c0588a8;
case 0x0c0588aau: goto P_0c0588aa;
case 0x0c0588acu: goto P_0c0588ac;
case 0x0c0588aeu: goto P_0c0588ae;
case 0x0c0588b0u: goto P_0c0588b0;
case 0x0c0588b2u: goto P_0c0588b2;
case 0x0c0588b4u: goto P_0c0588b4;
case 0x0c0588b6u: goto P_0c0588b6;
case 0x0c0588b8u: goto P_0c0588b8;
case 0x0c0588bau: goto P_0c0588ba;
case 0x0c0588bcu: goto P_0c0588bc;
case 0x0c0588beu: goto P_0c0588be;
case 0x0c0588c0u: goto P_0c0588c0;
case 0x0c0588c2u: goto P_0c0588c2;
case 0x0c0588c4u: goto P_0c0588c4;
case 0x0c0588c6u: goto P_0c0588c6;
case 0x0c0588c8u: goto P_0c0588c8;
case 0x0c0588cau: goto P_0c0588ca;
case 0x0c0588ccu: goto P_0c0588cc;
case 0x0c0588ceu: goto P_0c0588ce;
case 0x0c0588d0u: goto P_0c0588d0;
case 0x0c0588d2u: goto P_0c0588d2;
case 0x0c0588d4u: goto P_0c0588d4;
case 0x0c0588d6u: goto P_0c0588d6;
case 0x0c0588d8u: goto P_0c0588d8;
case 0x0c0588dau: goto P_0c0588da;
case 0x0c0588dcu: goto P_0c0588dc;
case 0x0c0588deu: goto P_0c0588de;
case 0x0c0588e0u: goto P_0c0588e0;
case 0x0c0588e2u: goto P_0c0588e2;
case 0x0c0588e4u: goto P_0c0588e4;
case 0x0c0588e6u: goto P_0c0588e6;
case 0x0c0588e8u: goto P_0c0588e8;
case 0x0c0588eau: goto P_0c0588ea;
case 0x0c0588ecu: goto P_0c0588ec;
case 0x0c0588eeu: goto P_0c0588ee;
case 0x0c05961cu: goto P_0c05961c;
case 0x0c05c4a2u: goto P_0c05c4a2;
case 0x0c05c4a4u: goto P_0c05c4a4;
case 0x0c05c4a6u: goto P_0c05c4a6;
case 0x0c05c4a8u: goto P_0c05c4a8;
case 0x0c05c4aau: goto P_0c05c4aa;
case 0x0c05c4acu: goto P_0c05c4ac;
case 0x0c05c4aeu: goto P_0c05c4ae;
case 0x0c05c4b0u: goto P_0c05c4b0;
case 0x0c05c4b2u: goto P_0c05c4b2;
case 0x0c05c4b4u: goto P_0c05c4b4;
case 0x0c05c4b6u: goto P_0c05c4b6;
case 0x0c05c4b8u: goto P_0c05c4b8;
case 0x0c05c4bau: goto P_0c05c4ba;
case 0x0c05c8a6u: goto P_0c05c8a6;
case 0x0c05c8a8u: goto P_0c05c8a8;
case 0x0c05c8aau: goto P_0c05c8aa;
case 0x0c05c8acu: goto P_0c05c8ac;
case 0x0c05c8aeu: goto P_0c05c8ae;
case 0x0c05c8b0u: goto P_0c05c8b0;
case 0x0c05c8b2u: goto P_0c05c8b2;
case 0x0c05c8b4u: goto P_0c05c8b4;
case 0x0c05c8b6u: goto P_0c05c8b6;
case 0x0c05c8b8u: goto P_0c05c8b8;
case 0x0c05c8bau: goto P_0c05c8ba;
case 0x0c05c8bcu: goto P_0c05c8bc;
case 0x0c05c8beu: goto P_0c05c8be;
case 0x0c05c8c0u: goto P_0c05c8c0;
case 0x0c05c8c2u: goto P_0c05c8c2;
case 0x0c05c8c4u: goto P_0c05c8c4;
case 0x0c05c8c6u: goto P_0c05c8c6;
case 0x0c05c8c8u: goto P_0c05c8c8;
case 0x0c05c8cau: goto P_0c05c8ca;
case 0x0c05c8ccu: goto P_0c05c8cc;
case 0x0c05c8ceu: goto P_0c05c8ce;
case 0x0c05c8d0u: goto P_0c05c8d0;
case 0x0c05c8d2u: goto P_0c05c8d2;
case 0x0c05c8d4u: goto P_0c05c8d4;
case 0x0c05c8d6u: goto P_0c05c8d6;
case 0x0c05c8d8u: goto P_0c05c8d8;
case 0x0c05c8dau: goto P_0c05c8da;
case 0x0c05c8dcu: goto P_0c05c8dc;
case 0x0c05c8deu: goto P_0c05c8de;
case 0x0c05c8e0u: goto P_0c05c8e0;
case 0x0c05c8e2u: goto P_0c05c8e2;
case 0x0c05c8e4u: goto P_0c05c8e4;
case 0x0c05c8e6u: goto P_0c05c8e6;
case 0x0c05c8e8u: goto P_0c05c8e8;
case 0x0c05c8eau: goto P_0c05c8ea;
case 0x0c05c8ecu: goto P_0c05c8ec;
case 0x0c05c8eeu: goto P_0c05c8ee;
case 0x0c05c8f0u: goto P_0c05c8f0;
case 0x0c05c8f2u: goto P_0c05c8f2;
case 0x0c05c8f4u: goto P_0c05c8f4;
case 0x0c05c8f6u: goto P_0c05c8f6;
case 0x0c05c8f8u: goto P_0c05c8f8;
case 0x0c05c8fau: goto P_0c05c8fa;
case 0x0c05c8fcu: goto P_0c05c8fc;
case 0x0c05c8feu: goto P_0c05c8fe;
case 0x0c05c900u: goto P_0c05c900;
case 0x0c05c902u: goto P_0c05c902;
case 0x0c05c904u: goto P_0c05c904;
case 0x0c05c906u: goto P_0c05c906;
case 0x0c05c908u: goto P_0c05c908;
case 0x0c05c90au: goto P_0c05c90a;
case 0x0c05c90cu: goto P_0c05c90c;
case 0x0c05cbeeu: goto P_0c05cbee;
case 0x0c05cbf0u: goto P_0c05cbf0;
case 0x0c05cbf2u: goto P_0c05cbf2;
case 0x0c05cbf4u: goto P_0c05cbf4;
case 0x0c05cbf6u: goto P_0c05cbf6;
case 0x0c05cbf8u: goto P_0c05cbf8;
case 0x0c05cbfau: goto P_0c05cbfa;
case 0x0c05cbfcu: goto P_0c05cbfc;
case 0x0c05cbfeu: goto P_0c05cbfe;
case 0x0c05cc00u: goto P_0c05cc00;
case 0x0c05cc02u: goto P_0c05cc02;
case 0x0c05cc04u: goto P_0c05cc04;
case 0x0c05cc06u: goto P_0c05cc06;
case 0x0c05cc08u: goto P_0c05cc08;
case 0x0c05cc0au: goto P_0c05cc0a;
case 0x0c05cc0cu: goto P_0c05cc0c;
case 0x0c05cc0eu: goto P_0c05cc0e;
case 0x0c05cc10u: goto P_0c05cc10;
case 0x0c05cc12u: goto P_0c05cc12;
case 0x0c05cc14u: goto P_0c05cc14;
case 0x0c05cc16u: goto P_0c05cc16;
case 0x0c05cc18u: goto P_0c05cc18;
case 0x0c05cc1au: goto P_0c05cc1a;
case 0x0c05cc1cu: goto P_0c05cc1c;
case 0x0c05cc1eu: goto P_0c05cc1e;
case 0x0c05ddaau: goto P_0c05ddaa;
case 0x0c05ddacu: goto P_0c05ddac;
case 0x0c05ddaeu: goto P_0c05ddae;
case 0x0c05ddb0u: goto P_0c05ddb0;
case 0x0c05ddb2u: goto P_0c05ddb2;
case 0x0c05ddb4u: goto P_0c05ddb4;
case 0x0c05ddb6u: goto P_0c05ddb6;
case 0x0c05ddb8u: goto P_0c05ddb8;
case 0x0c05ddbau: goto P_0c05ddba;
case 0x0c05ddbcu: goto P_0c05ddbc;
case 0x0c05ddbeu: goto P_0c05ddbe;
case 0x0c05ddc0u: goto P_0c05ddc0;
case 0x0c05ddc2u: goto P_0c05ddc2;
case 0x0c05ddc4u: goto P_0c05ddc4;
case 0x0c05ddc6u: goto P_0c05ddc6;
case 0x0c05ddc8u: goto P_0c05ddc8;
case 0x0c05ddcau: goto P_0c05ddca;
case 0x0c05ddccu: goto P_0c05ddcc;
case 0x0c05ddceu: goto P_0c05ddce;
case 0x0c05ddd0u: goto P_0c05ddd0;
case 0x0c05ddd2u: goto P_0c05ddd2;
case 0x0c05ddd4u: goto P_0c05ddd4;
case 0x0c05ddd6u: goto P_0c05ddd6;
case 0x0c05ddd8u: goto P_0c05ddd8;
case 0x0c05dddau: goto P_0c05ddda;
case 0x0c05dddcu: goto P_0c05dddc;
case 0x0c05dddeu: goto P_0c05ddde;
case 0x0c05dde0u: goto P_0c05dde0;
case 0x0c05dde2u: goto P_0c05dde2;
case 0x0c05dde4u: goto P_0c05dde4;
case 0x0c05dde6u: goto P_0c05dde6;
case 0x0c05dde8u: goto P_0c05dde8;
case 0x0c05ddeau: goto P_0c05ddea;
case 0x0c05ddecu: goto P_0c05ddec;
case 0x0c05ddeeu: goto P_0c05ddee;
case 0x0c05ddf0u: goto P_0c05ddf0;
case 0x0c05e12eu: goto P_0c05e12e;
case 0x0c05e130u: goto P_0c05e130;
case 0x0c05e132u: goto P_0c05e132;
case 0x0c05e134u: goto P_0c05e134;
case 0x0c05e136u: goto P_0c05e136;
case 0x0c05e138u: goto P_0c05e138;
case 0x0c05e13au: goto P_0c05e13a;
case 0x0c05e13cu: goto P_0c05e13c;
case 0x0c05e13eu: goto P_0c05e13e;
case 0x0c05e140u: goto P_0c05e140;
case 0x0c05e142u: goto P_0c05e142;
case 0x0c05e144u: goto P_0c05e144;
case 0x0c05e146u: goto P_0c05e146;
case 0x0c05e148u: goto P_0c05e148;
case 0x0c05e14au: goto P_0c05e14a;
case 0x0c05e14cu: goto P_0c05e14c;
case 0x0c05e14eu: goto P_0c05e14e;
case 0x0c05e150u: goto P_0c05e150;
case 0x0c05e152u: goto P_0c05e152;
case 0x0c05e154u: goto P_0c05e154;
case 0x0c05e156u: goto P_0c05e156;
case 0x0c05e158u: goto P_0c05e158;
case 0x0c05e15au: goto P_0c05e15a;
case 0x0c05e15cu: goto P_0c05e15c;
case 0x0c05e15eu: goto P_0c05e15e;
case 0x0c05e160u: goto P_0c05e160;
case 0x0c05e162u: goto P_0c05e162;
case 0x0c05e164u: goto P_0c05e164;
case 0x0c05e166u: goto P_0c05e166;
case 0x0c05e168u: goto P_0c05e168;
case 0x0c05e16au: goto P_0c05e16a;
case 0x0c05e16cu: goto P_0c05e16c;
case 0x0c05e16eu: goto P_0c05e16e;
case 0x0c05e170u: goto P_0c05e170;
case 0x0c05e172u: goto P_0c05e172;
case 0x0c05e174u: goto P_0c05e174;
case 0x0c05e176u: goto P_0c05e176;
case 0x0c05e178u: goto P_0c05e178;
case 0x0c05e17au: goto P_0c05e17a;
case 0x0c05e17cu: goto P_0c05e17c;
case 0x0c05e17eu: goto P_0c05e17e;
case 0x0c05e180u: goto P_0c05e180;
case 0x0c05e182u: goto P_0c05e182;
case 0x0c05e184u: goto P_0c05e184;
case 0x0c05e186u: goto P_0c05e186;
case 0x0c05e188u: goto P_0c05e188;
case 0x0c05e18au: goto P_0c05e18a;
case 0x0c05e18cu: goto P_0c05e18c;
case 0x0c05e18eu: goto P_0c05e18e;
case 0x0c05e190u: goto P_0c05e190;
case 0x0c05e192u: goto P_0c05e192;
case 0x0c05e194u: goto P_0c05e194;
case 0x0c05e196u: goto P_0c05e196;
case 0x0c05e198u: goto P_0c05e198;
case 0x0c05e19au: goto P_0c05e19a;
case 0x0c05e19cu: goto P_0c05e19c;
case 0x0c05e19eu: goto P_0c05e19e;
case 0x0c05e1a0u: goto P_0c05e1a0;
case 0x0c05e1a2u: goto P_0c05e1a2;
case 0x0c05e1a4u: goto P_0c05e1a4;
case 0x0c05e1a6u: goto P_0c05e1a6;
case 0x0c05e1a8u: goto P_0c05e1a8;
case 0x0c05e1aau: goto P_0c05e1aa;
case 0x0c05e1acu: goto P_0c05e1ac;
case 0x0c05e1aeu: goto P_0c05e1ae;
case 0x0c05e1b0u: goto P_0c05e1b0;
case 0x0c05e1c2u: goto P_0c05e1c2;
case 0x0c05e1c4u: goto P_0c05e1c4;
case 0x0c05e1c6u: goto P_0c05e1c6;
case 0x0c05e1c8u: goto P_0c05e1c8;
case 0x0c05e1cau: goto P_0c05e1ca;
case 0x0c05e1ccu: goto P_0c05e1cc;
case 0x0c05e1ceu: goto P_0c05e1ce;
case 0x0c05e1d0u: goto P_0c05e1d0;
case 0x0c05e332u: goto P_0c05e332;
case 0x0c05e334u: goto P_0c05e334;
case 0x0c05e336u: goto P_0c05e336;
case 0x0c05e338u: goto P_0c05e338;
case 0x0c05e33au: goto P_0c05e33a;
case 0x0c05e33cu: goto P_0c05e33c;
case 0x0c05e33eu: goto P_0c05e33e;
case 0x0c05e340u: goto P_0c05e340;
case 0x0c05e634u: goto P_0c05e634;
case 0x0c05e636u: goto P_0c05e636;
case 0x0c05e638u: goto P_0c05e638;
case 0x0c05e63au: goto P_0c05e63a;
case 0x0c05e63cu: goto P_0c05e63c;
case 0x0c05e63eu: goto P_0c05e63e;
case 0x0c05e640u: goto P_0c05e640;
case 0x0c05e642u: goto P_0c05e642;
case 0x0c05e644u: goto P_0c05e644;
case 0x0c05e646u: goto P_0c05e646;
case 0x0c05e684u: goto P_0c05e684;
case 0x0c05e686u: goto P_0c05e686;
case 0x0c05e688u: goto P_0c05e688;
case 0x0c05e68au: goto P_0c05e68a;
case 0x0c05e68cu: goto P_0c05e68c;
case 0x0c05e68eu: goto P_0c05e68e;
case 0x0c05e690u: goto P_0c05e690;
case 0x0c05e692u: goto P_0c05e692;
case 0x0c05e694u: goto P_0c05e694;
case 0x0c05e696u: goto P_0c05e696;
case 0x0c05e698u: goto P_0c05e698;
case 0x0c05e69au: goto P_0c05e69a;
case 0x0c05e69cu: goto P_0c05e69c;
case 0x0c05e69eu: goto P_0c05e69e;
case 0x0c05e6a0u: goto P_0c05e6a0;
case 0x0c05e6a2u: goto P_0c05e6a2;
case 0x0c05e6a4u: goto P_0c05e6a4;
case 0x0c05e6a6u: goto P_0c05e6a6;
case 0x0c05e6a8u: goto P_0c05e6a8;
case 0x0c05e6b4u: goto P_0c05e6b4;
case 0x0c05e6b6u: goto P_0c05e6b6;
case 0x0c05e6b8u: goto P_0c05e6b8;
case 0x0c05e6bau: goto P_0c05e6ba;
case 0x0c05e6bcu: goto P_0c05e6bc;
case 0x0c05e6beu: goto P_0c05e6be;
case 0x0c05e6c0u: goto P_0c05e6c0;
case 0x0c05e6c2u: goto P_0c05e6c2;
case 0x0c05e6c4u: goto P_0c05e6c4;
case 0x0c05e6c6u: goto P_0c05e6c6;
case 0x0c05e6c8u: goto P_0c05e6c8;
case 0x0c05e6cau: goto P_0c05e6ca;
case 0x0c05e6ccu: goto P_0c05e6cc;
case 0x0c05e6ceu: goto P_0c05e6ce;
case 0x0c05e6d0u: goto P_0c05e6d0;
case 0x0c05e6d2u: goto P_0c05e6d2;
case 0x0c05e6d4u: goto P_0c05e6d4;
case 0x0c05e6d6u: goto P_0c05e6d6;
case 0x0c05e6d8u: goto P_0c05e6d8;
case 0x0c05e6dau: goto P_0c05e6da;
case 0x0c05e6dcu: goto P_0c05e6dc;
case 0x0c05e728u: goto P_0c05e728;
case 0x0c05e72au: goto P_0c05e72a;
case 0x0c05e72cu: goto P_0c05e72c;
case 0x0c05e72eu: goto P_0c05e72e;
case 0x0c05e730u: goto P_0c05e730;
case 0x0c05e732u: goto P_0c05e732;
case 0x0c05e734u: goto P_0c05e734;
case 0x0c05e736u: goto P_0c05e736;
case 0x0c05e738u: goto P_0c05e738;
case 0x0c05e73au: goto P_0c05e73a;
case 0x0c05e73cu: goto P_0c05e73c;
case 0x0c05e73eu: goto P_0c05e73e;
case 0x0c05e740u: goto P_0c05e740;
case 0x0c05e742u: goto P_0c05e742;
case 0x0c05e744u: goto P_0c05e744;
case 0x0c05e746u: goto P_0c05e746;
case 0x0c05e748u: goto P_0c05e748;
case 0x0c05e74au: goto P_0c05e74a;
case 0x0c05e74cu: goto P_0c05e74c;
case 0x0c05e74eu: goto P_0c05e74e;
case 0x0c05e750u: goto P_0c05e750;
case 0x0c05e752u: goto P_0c05e752;
case 0x0c05f33cu: goto P_0c05f33c;
case 0x0c05f33eu: goto P_0c05f33e;
case 0x0c05f340u: goto P_0c05f340;
case 0x0c05f342u: goto P_0c05f342;
case 0x0c05f344u: goto P_0c05f344;
case 0x0c05f346u: goto P_0c05f346;
case 0x0c05f348u: goto P_0c05f348;
case 0x0c05f34au: goto P_0c05f34a;
case 0x0c05f34cu: goto P_0c05f34c;
case 0x0c05f34eu: goto P_0c05f34e;
case 0x0c05f350u: goto P_0c05f350;
case 0x0c05f352u: goto P_0c05f352;
case 0x0c05f354u: goto P_0c05f354;
case 0x0c05f356u: goto P_0c05f356;
case 0x0c05f358u: goto P_0c05f358;
case 0x0c05f35au: goto P_0c05f35a;
case 0x0c05f35cu: goto P_0c05f35c;
case 0x0c05f35eu: goto P_0c05f35e;
case 0x0c05f360u: goto P_0c05f360;
case 0x0c05f3eau: goto P_0c05f3ea;
case 0x0c05f3ecu: goto P_0c05f3ec;
case 0x0c05f3eeu: goto P_0c05f3ee;
case 0x0c05f3f0u: goto P_0c05f3f0;
case 0x0c05f3f2u: goto P_0c05f3f2;
case 0x0c05f3f4u: goto P_0c05f3f4;
case 0x0c05f3f6u: goto P_0c05f3f6;
case 0x0c05f3f8u: goto P_0c05f3f8;
case 0x0c05f3fau: goto P_0c05f3fa;
case 0x0c05f3fcu: goto P_0c05f3fc;
case 0x0c05f3feu: goto P_0c05f3fe;
case 0x0c05f400u: goto P_0c05f400;
case 0x0c05f402u: goto P_0c05f402;
case 0x0c05f404u: goto P_0c05f404;
case 0x0c05f406u: goto P_0c05f406;
case 0x0c05f408u: goto P_0c05f408;
case 0x0c05f40au: goto P_0c05f40a;
case 0x0c05f40cu: goto P_0c05f40c;
case 0x0c05f40eu: goto P_0c05f40e;
case 0x0c05f410u: goto P_0c05f410;
case 0x0c05f412u: goto P_0c05f412;
case 0x0c05f414u: goto P_0c05f414;
case 0x0c05f416u: goto P_0c05f416;
case 0x0c05f418u: goto P_0c05f418;
case 0x0c05f41au: goto P_0c05f41a;
case 0x0c05f41cu: goto P_0c05f41c;
case 0x0c05f41eu: goto P_0c05f41e;
case 0x0c05f420u: goto P_0c05f420;
case 0x0c05f422u: goto P_0c05f422;
case 0x0c05f424u: goto P_0c05f424;
case 0x0c05f426u: goto P_0c05f426;
case 0x0c05f428u: goto P_0c05f428;
case 0x0c05f42au: goto P_0c05f42a;
case 0x0c05f42cu: goto P_0c05f42c;
case 0x0c05f42eu: goto P_0c05f42e;
case 0x0c05f430u: goto P_0c05f430;
case 0x0c05f432u: goto P_0c05f432;
case 0x0c05f434u: goto P_0c05f434;
case 0x0c05f436u: goto P_0c05f436;
case 0x0c05f438u: goto P_0c05f438;
case 0x0c05f43au: goto P_0c05f43a;
case 0x0c05f43cu: goto P_0c05f43c;
case 0x0c05ff82u: goto P_0c05ff82;
case 0x0c05ff84u: goto P_0c05ff84;
case 0x0c05ff86u: goto P_0c05ff86;
case 0x0c05ff88u: goto P_0c05ff88;
case 0x0c05ff8au: goto P_0c05ff8a;
case 0x0c05ff8cu: goto P_0c05ff8c;
case 0x0c05ff8eu: goto P_0c05ff8e;
case 0x0c05ff90u: goto P_0c05ff90;
case 0x0c05ff92u: goto P_0c05ff92;
case 0x0c05ff94u: goto P_0c05ff94;
case 0x0c05ff96u: goto P_0c05ff96;
case 0x0c05ff98u: goto P_0c05ff98;
case 0x0c05ff9au: goto P_0c05ff9a;
case 0x0c05ff9cu: goto P_0c05ff9c;
case 0x0c05ff9eu: goto P_0c05ff9e;
case 0x0c05ffa0u: goto P_0c05ffa0;
case 0x0c05ffa2u: goto P_0c05ffa2;
case 0x0c05ffa4u: goto P_0c05ffa4;
case 0x0c05ffa6u: goto P_0c05ffa6;
case 0x0c05ffa8u: goto P_0c05ffa8;
case 0x0c05ffaau: goto P_0c05ffaa;
case 0x0c05ffacu: goto P_0c05ffac;
case 0x0c05ffaeu: goto P_0c05ffae;
case 0x0c05ffb0u: goto P_0c05ffb0;
case 0x0c05ffb2u: goto P_0c05ffb2;
case 0x0c05ffb4u: goto P_0c05ffb4;
case 0x0c05ffb6u: goto P_0c05ffb6;
case 0x0c05ffb8u: goto P_0c05ffb8;
case 0x0c05ffbau: goto P_0c05ffba;
case 0x0c05ffbcu: goto P_0c05ffbc;
case 0x0c05ffbeu: goto P_0c05ffbe;
case 0x0c05ffc0u: goto P_0c05ffc0;
case 0x0c05ffc2u: goto P_0c05ffc2;
case 0x0c05ffc4u: goto P_0c05ffc4;
case 0x0c05ffc6u: goto P_0c05ffc6;
case 0x0c05ffc8u: goto P_0c05ffc8;
case 0x0c05ffcau: goto P_0c05ffca;
case 0x0c062e60u: goto P_0c062e60;
case 0x0c062e62u: goto P_0c062e62;
case 0x0c062e64u: goto P_0c062e64;
case 0x0c062e66u: goto P_0c062e66;
case 0x0c062e68u: goto P_0c062e68;
case 0x0c062e6au: goto P_0c062e6a;
case 0x0c062e6cu: goto P_0c062e6c;
case 0x0c062e6eu: goto P_0c062e6e;
case 0x0c062e70u: goto P_0c062e70;
case 0x0c062e72u: goto P_0c062e72;
case 0x0c062e74u: goto P_0c062e74;
case 0x0c062e76u: goto P_0c062e76;
case 0x0c062e78u: goto P_0c062e78;
case 0x0c062e7au: goto P_0c062e7a;
case 0x0c062e7cu: goto P_0c062e7c;
case 0x0c063418u: goto P_0c063418;
case 0x0c06341au: goto P_0c06341a;
case 0x0c06341cu: goto P_0c06341c;
case 0x0c06341eu: goto P_0c06341e;
case 0x0c063420u: goto P_0c063420;
case 0x0c063422u: goto P_0c063422;
case 0x0c063424u: goto P_0c063424;
case 0x0c063426u: goto P_0c063426;
case 0x0c063428u: goto P_0c063428;
case 0x0c06342au: goto P_0c06342a;
case 0x0c06342cu: goto P_0c06342c;
case 0x0c06342eu: goto P_0c06342e;
case 0x0c063430u: goto P_0c063430;
case 0x0c063432u: goto P_0c063432;
case 0x0c063434u: goto P_0c063434;
case 0x0c0641f4u: goto P_0c0641f4;
case 0x0c0641f6u: goto P_0c0641f6;
case 0x0c0641f8u: goto P_0c0641f8;
case 0x0c0641fau: goto P_0c0641fa;
case 0x0c0641fcu: goto P_0c0641fc;
case 0x0c0641feu: goto P_0c0641fe;
case 0x0c064200u: goto P_0c064200;
case 0x0c064202u: goto P_0c064202;
case 0x0c064204u: goto P_0c064204;
case 0x0c064206u: goto P_0c064206;
case 0x0c064208u: goto P_0c064208;
case 0x0c06420au: goto P_0c06420a;
case 0x0c06420cu: goto P_0c06420c;
case 0x0c06420eu: goto P_0c06420e;
case 0x0c064210u: goto P_0c064210;
case 0x0c064212u: goto P_0c064212;
case 0x0c064214u: goto P_0c064214;
case 0x0c064216u: goto P_0c064216;
case 0x0c064218u: goto P_0c064218;
case 0x0c06421au: goto P_0c06421a;
case 0x0c066cd8u: goto P_0c066cd8;
case 0x0c066cdau: goto P_0c066cda;
case 0x0c066cdcu: goto P_0c066cdc;
case 0x0c066cdeu: goto P_0c066cde;
case 0x0c066ce0u: goto P_0c066ce0;
case 0x0c066ce2u: goto P_0c066ce2;
case 0x0c066ce4u: goto P_0c066ce4;
case 0x0c066ce6u: goto P_0c066ce6;
case 0x0c066ce8u: goto P_0c066ce8;
case 0x0c066ceau: goto P_0c066cea;
case 0x0c066d48u: goto P_0c066d48;
case 0x0c06c406u: goto P_0c06c406;
case 0x0c06c408u: goto P_0c06c408;
case 0x0c06c40au: goto P_0c06c40a;
case 0x0c06c40cu: goto P_0c06c40c;
case 0x0c06c40eu: goto P_0c06c40e;
case 0x0c06c410u: goto P_0c06c410;
case 0x0c06c412u: goto P_0c06c412;
case 0x0c06c414u: goto P_0c06c414;
case 0x0c06c416u: goto P_0c06c416;
case 0x0c06c418u: goto P_0c06c418;
case 0x0c06c41au: goto P_0c06c41a;
case 0x0c06c41cu: goto P_0c06c41c;
case 0x0c06c41eu: goto P_0c06c41e;
case 0x0c06c420u: goto P_0c06c420;
case 0x0c06dae8u: goto P_0c06dae8;
case 0x0c06daeau: goto P_0c06daea;
case 0x0c06daecu: goto P_0c06daec;
case 0x0c06daeeu: goto P_0c06daee;
case 0x0c06daf0u: goto P_0c06daf0;
case 0x0c06daf2u: goto P_0c06daf2;
case 0x0c06daf4u: goto P_0c06daf4;
case 0x0c06daf6u: goto P_0c06daf6;
case 0x0c06daf8u: goto P_0c06daf8;
case 0x0c06dafau: goto P_0c06dafa;
case 0x0c06dafcu: goto P_0c06dafc;
case 0x0c06dafeu: goto P_0c06dafe;
case 0x0c06db00u: goto P_0c06db00;
case 0x0c06db02u: goto P_0c06db02;
case 0x0c06db04u: goto P_0c06db04;
case 0x0c06db06u: goto P_0c06db06;
case 0x0c06db08u: goto P_0c06db08;
case 0x0c06db0au: goto P_0c06db0a;
case 0x0c06db0cu: goto P_0c06db0c;
case 0x0c06db0eu: goto P_0c06db0e;
case 0x0c06db10u: goto P_0c06db10;
case 0x0c06db12u: goto P_0c06db12;
case 0x0c06db14u: goto P_0c06db14;
case 0x0c06db16u: goto P_0c06db16;
case 0x0c06db18u: goto P_0c06db18;
case 0x0c06db1au: goto P_0c06db1a;
case 0x0c06db1cu: goto P_0c06db1c;
case 0x0c06db1eu: goto P_0c06db1e;
case 0x0c06db20u: goto P_0c06db20;
case 0x0c06db22u: goto P_0c06db22;
case 0x0c06db24u: goto P_0c06db24;
case 0x0c06db26u: goto P_0c06db26;
case 0x0c06db28u: goto P_0c06db28;
case 0x0c06db2au: goto P_0c06db2a;
case 0x0c06db2cu: goto P_0c06db2c;
case 0x0c06db2eu: goto P_0c06db2e;
case 0x0c06db30u: goto P_0c06db30;
case 0x0c06db32u: goto P_0c06db32;
case 0x0c07023au: goto P_0c07023a;
case 0x0c07023cu: goto P_0c07023c;
case 0x0c07023eu: goto P_0c07023e;
case 0x0c070240u: goto P_0c070240;
case 0x0c070242u: goto P_0c070242;
case 0x0c070244u: goto P_0c070244;
case 0x0c070246u: goto P_0c070246;
case 0x0c070248u: goto P_0c070248;
case 0x0c07024au: goto P_0c07024a;
case 0x0c07024cu: goto P_0c07024c;
case 0x0c07024eu: goto P_0c07024e;
case 0x0c070250u: goto P_0c070250;
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
case 0x0c070fbau: goto P_0c070fba;
case 0x0c070fbcu: goto P_0c070fbc;
case 0x0c070fbeu: goto P_0c070fbe;
case 0x0c070fc0u: goto P_0c070fc0;
case 0x0c070fc2u: goto P_0c070fc2;
case 0x0c070fc4u: goto P_0c070fc4;
case 0x0c070fc6u: goto P_0c070fc6;
case 0x0c070fc8u: goto P_0c070fc8;
case 0x0c070fcau: goto P_0c070fca;
case 0x0c070fccu: goto P_0c070fcc;
case 0x0c070fceu: goto P_0c070fce;
case 0x0c070fd0u: goto P_0c070fd0;
case 0x0c070fd2u: goto P_0c070fd2;
case 0x0c070fd4u: goto P_0c070fd4;
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
case 0x0c073098u: goto P_0c073098;
case 0x0c07309au: goto P_0c07309a;
case 0x0c07309cu: goto P_0c07309c;
case 0x0c07309eu: goto P_0c07309e;
case 0x0c0730a0u: goto P_0c0730a0;
case 0x0c0730a2u: goto P_0c0730a2;
case 0x0c0730a4u: goto P_0c0730a4;
case 0x0c0730a6u: goto P_0c0730a6;
case 0x0c0730a8u: goto P_0c0730a8;
case 0x0c0730aau: goto P_0c0730aa;
case 0x0c0730acu: goto P_0c0730ac;
case 0x0c0730aeu: goto P_0c0730ae;
case 0x0c0730b0u: goto P_0c0730b0;
case 0x0c0730b2u: goto P_0c0730b2;
case 0x0c0730b4u: goto P_0c0730b4;
case 0x0c0730b6u: goto P_0c0730b6;
case 0x0c0730b8u: goto P_0c0730b8;
case 0x0c0730bau: goto P_0c0730ba;
case 0x0c0730bcu: goto P_0c0730bc;
case 0x0c0730beu: goto P_0c0730be;
case 0x0c0730c0u: goto P_0c0730c0;
case 0x0c0730c2u: goto P_0c0730c2;
case 0x0c0730c4u: goto P_0c0730c4;
case 0x0c0730c6u: goto P_0c0730c6;
case 0x0c0730c8u: goto P_0c0730c8;
case 0x0c0730cau: goto P_0c0730ca;
case 0x0c0730ccu: goto P_0c0730cc;
case 0x0c0730ceu: goto P_0c0730ce;
case 0x0c0730d0u: goto P_0c0730d0;
case 0x0c0730d2u: goto P_0c0730d2;
case 0x0c0730d4u: goto P_0c0730d4;
case 0x0c0730d6u: goto P_0c0730d6;
case 0x0c0730d8u: goto P_0c0730d8;
case 0x0c0730dau: goto P_0c0730da;
case 0x0c0730dcu: goto P_0c0730dc;
case 0x0c0730deu: goto P_0c0730de;
case 0x0c0730e0u: goto P_0c0730e0;
case 0x0c0730e2u: goto P_0c0730e2;
case 0x0c0730e4u: goto P_0c0730e4;
case 0x0c0730e6u: goto P_0c0730e6;
case 0x0c0730e8u: goto P_0c0730e8;
case 0x0c0730eau: goto P_0c0730ea;
case 0x0c0734feu: goto P_0c0734fe;
case 0x0c073500u: goto P_0c073500;
case 0x0c073502u: goto P_0c073502;
case 0x0c073504u: goto P_0c073504;
case 0x0c073506u: goto P_0c073506;
case 0x0c073508u: goto P_0c073508;
case 0x0c07350au: goto P_0c07350a;
case 0x0c07350cu: goto P_0c07350c;
case 0x0c07350eu: goto P_0c07350e;
case 0x0c073510u: goto P_0c073510;
case 0x0c073512u: goto P_0c073512;
case 0x0c073514u: goto P_0c073514;
case 0x0c073516u: goto P_0c073516;
case 0x0c073518u: goto P_0c073518;
case 0x0c07351au: goto P_0c07351a;
case 0x0c07351cu: goto P_0c07351c;
case 0x0c07351eu: goto P_0c07351e;
case 0x0c073520u: goto P_0c073520;
case 0x0c073522u: goto P_0c073522;
case 0x0c073524u: goto P_0c073524;
case 0x0c073526u: goto P_0c073526;
case 0x0c073528u: goto P_0c073528;
case 0x0c07352au: goto P_0c07352a;
case 0x0c07352cu: goto P_0c07352c;
case 0x0c07352eu: goto P_0c07352e;
case 0x0c073530u: goto P_0c073530;
case 0x0c073532u: goto P_0c073532;
case 0x0c073534u: goto P_0c073534;
case 0x0c073536u: goto P_0c073536;
case 0x0c073538u: goto P_0c073538;
case 0x0c07353au: goto P_0c07353a;
case 0x0c07353cu: goto P_0c07353c;
case 0x0c07353eu: goto P_0c07353e;
case 0x0c073540u: goto P_0c073540;
case 0x0c07ba28u: goto P_0c07ba28;
case 0x0c07ba2au: goto P_0c07ba2a;
case 0x0c07ba2cu: goto P_0c07ba2c;
case 0x0c07ba2eu: goto P_0c07ba2e;
case 0x0c07ba30u: goto P_0c07ba30;
case 0x0c07ba32u: goto P_0c07ba32;
case 0x0c07ba34u: goto P_0c07ba34;
case 0x0c07ba36u: goto P_0c07ba36;
case 0x0c07ba38u: goto P_0c07ba38;
case 0x0c07ba3au: goto P_0c07ba3a;
case 0x0c07ba3cu: goto P_0c07ba3c;
case 0x0c07ba3eu: goto P_0c07ba3e;
case 0x0c07ba40u: goto P_0c07ba40;
case 0x0c07ba42u: goto P_0c07ba42;
case 0x0c07ba44u: goto P_0c07ba44;
case 0x0c07ba46u: goto P_0c07ba46;
case 0x0c07ba48u: goto P_0c07ba48;
case 0x0c07ba4au: goto P_0c07ba4a;
case 0x0c07ba4cu: goto P_0c07ba4c;
case 0x0c07ba4eu: goto P_0c07ba4e;
case 0x0c07ba50u: goto P_0c07ba50;
case 0x0c07ba52u: goto P_0c07ba52;
case 0x0c07ba54u: goto P_0c07ba54;
case 0x0c07ba56u: goto P_0c07ba56;
case 0x0c07ba58u: goto P_0c07ba58;
case 0x0c07ba5au: goto P_0c07ba5a;
case 0x0c07ba5cu: goto P_0c07ba5c;
case 0x0c07ba5eu: goto P_0c07ba5e;
case 0x0c07ba60u: goto P_0c07ba60;
case 0x0c07ba62u: goto P_0c07ba62;
case 0x0c07ba64u: goto P_0c07ba64;
case 0x0c07ba66u: goto P_0c07ba66;
case 0x0c07ba68u: goto P_0c07ba68;
case 0x0c07ba6au: goto P_0c07ba6a;
case 0x0c07ba6cu: goto P_0c07ba6c;
case 0x0c07ba6eu: goto P_0c07ba6e;
case 0x0c07ba70u: goto P_0c07ba70;
case 0x0c07ba72u: goto P_0c07ba72;
case 0x0c07ba74u: goto P_0c07ba74;
case 0x0c07ba76u: goto P_0c07ba76;
case 0x0c07ba78u: goto P_0c07ba78;
case 0x0c07ba7au: goto P_0c07ba7a;
case 0x0c07ba7cu: goto P_0c07ba7c;
case 0x0c07ba7eu: goto P_0c07ba7e;
case 0x0c07ba80u: goto P_0c07ba80;
case 0x0c07ba82u: goto P_0c07ba82;
case 0x0c07ba84u: goto P_0c07ba84;
case 0x0c07ba86u: goto P_0c07ba86;
case 0x0c07ba88u: goto P_0c07ba88;
case 0x0c07ba8au: goto P_0c07ba8a;
case 0x0c07ba8cu: goto P_0c07ba8c;
case 0x0c07ba8eu: goto P_0c07ba8e;
case 0x0c07ba90u: goto P_0c07ba90;
case 0x0c07ba92u: goto P_0c07ba92;
case 0x0c07ba94u: goto P_0c07ba94;
case 0x0c07ba96u: goto P_0c07ba96;
case 0x0c07ba98u: goto P_0c07ba98;
case 0x0c07ba9au: goto P_0c07ba9a;
case 0x0c07ba9cu: goto P_0c07ba9c;
case 0x0c07ba9eu: goto P_0c07ba9e;
case 0x0c07baa0u: goto P_0c07baa0;
case 0x0c07baa2u: goto P_0c07baa2;
case 0x0c07baa4u: goto P_0c07baa4;
case 0x0c07baa6u: goto P_0c07baa6;
case 0x0c07baa8u: goto P_0c07baa8;
case 0x0c07baaau: goto P_0c07baaa;
case 0x0c07baacu: goto P_0c07baac;
case 0x0c07baaeu: goto P_0c07baae;
case 0x0c07bab0u: goto P_0c07bab0;
case 0x0c07bab2u: goto P_0c07bab2;
case 0x0c07bab4u: goto P_0c07bab4;
case 0x0c07bab6u: goto P_0c07bab6;
case 0x0c07bab8u: goto P_0c07bab8;
case 0x0c07babau: goto P_0c07baba;
case 0x0c07babcu: goto P_0c07babc;
case 0x0c07babeu: goto P_0c07babe;
case 0x0c07bac0u: goto P_0c07bac0;
case 0x0c07bac2u: goto P_0c07bac2;
case 0x0c07bac4u: goto P_0c07bac4;
case 0x0c07bac6u: goto P_0c07bac6;
case 0x0c07bac8u: goto P_0c07bac8;
case 0x0c07bacau: goto P_0c07baca;
case 0x0c07baccu: goto P_0c07bacc;
case 0x0c07baceu: goto P_0c07bace;
case 0x0c07bad0u: goto P_0c07bad0;
case 0x0c07bad2u: goto P_0c07bad2;
case 0x0c07bad4u: goto P_0c07bad4;
case 0x0c07bad6u: goto P_0c07bad6;
case 0x0c07bad8u: goto P_0c07bad8;
case 0x0c07badau: goto P_0c07bada;
case 0x0c07badcu: goto P_0c07badc;
case 0x0c07badeu: goto P_0c07bade;
case 0x0c07bae0u: goto P_0c07bae0;
case 0x0c07bae2u: goto P_0c07bae2;
case 0x0c07bae4u: goto P_0c07bae4;
case 0x0c07bae6u: goto P_0c07bae6;
case 0x0c07bae8u: goto P_0c07bae8;
case 0x0c07baeau: goto P_0c07baea;
case 0x0c07baecu: goto P_0c07baec;
case 0x0c07baeeu: goto P_0c07baee;
case 0x0c07baf0u: goto P_0c07baf0;
case 0x0c07baf2u: goto P_0c07baf2;
case 0x0c07baf4u: goto P_0c07baf4;
case 0x0c07baf6u: goto P_0c07baf6;
case 0x0c07baf8u: goto P_0c07baf8;
case 0x0c07bafau: goto P_0c07bafa;
case 0x0c07bafcu: goto P_0c07bafc;
case 0x0c07bafeu: goto P_0c07bafe;
case 0x0c07bb00u: goto P_0c07bb00;
case 0x0c07bb02u: goto P_0c07bb02;
case 0x0c07bb04u: goto P_0c07bb04;
case 0x0c07bb06u: goto P_0c07bb06;
case 0x0c07bb08u: goto P_0c07bb08;
case 0x0c07bb0au: goto P_0c07bb0a;
case 0x0c07bb0cu: goto P_0c07bb0c;
case 0x0c07bb0eu: goto P_0c07bb0e;
case 0x0c07bb10u: goto P_0c07bb10;
case 0x0c07bb12u: goto P_0c07bb12;
case 0x0c07bb14u: goto P_0c07bb14;
case 0x0c07bb16u: goto P_0c07bb16;
case 0x0c07bb18u: goto P_0c07bb18;
case 0x0c07bb1au: goto P_0c07bb1a;
case 0x0c07bb1cu: goto P_0c07bb1c;
case 0x0c07bb1eu: goto P_0c07bb1e;
case 0x0c07bb20u: goto P_0c07bb20;
case 0x0c07bb22u: goto P_0c07bb22;
case 0x0c07bb24u: goto P_0c07bb24;
case 0x0c07bb26u: goto P_0c07bb26;
case 0x0c07bb28u: goto P_0c07bb28;
case 0x0c07bb2au: goto P_0c07bb2a;
case 0x0c07bb2cu: goto P_0c07bb2c;
case 0x0c07bb2eu: goto P_0c07bb2e;
case 0x0c07bb30u: goto P_0c07bb30;
case 0x0c07bb32u: goto P_0c07bb32;
case 0x0c07bb34u: goto P_0c07bb34;
case 0x0c07bb36u: goto P_0c07bb36;
case 0x0c07bb38u: goto P_0c07bb38;
case 0x0c07bb3au: goto P_0c07bb3a;
case 0x0c07bb3cu: goto P_0c07bb3c;
case 0x0c07bb3eu: goto P_0c07bb3e;
case 0x0c07bb40u: goto P_0c07bb40;
case 0x0c07bb42u: goto P_0c07bb42;
case 0x0c07bb44u: goto P_0c07bb44;
case 0x0c07bb46u: goto P_0c07bb46;
case 0x0c07bba0u: goto P_0c07bba0;
case 0x0c07bba2u: goto P_0c07bba2;
case 0x0c07bba4u: goto P_0c07bba4;
case 0x0c07bba6u: goto P_0c07bba6;
case 0x0c07bba8u: goto P_0c07bba8;
case 0x0c07bbaau: goto P_0c07bbaa;
case 0x0c07bbacu: goto P_0c07bbac;
case 0x0c07bbaeu: goto P_0c07bbae;
case 0x0c07bbb0u: goto P_0c07bbb0;
case 0x0c07bbb2u: goto P_0c07bbb2;
case 0x0c07bbb4u: goto P_0c07bbb4;
case 0x0c07bbb6u: goto P_0c07bbb6;
case 0x0c07bbb8u: goto P_0c07bbb8;
case 0x0c07bbbau: goto P_0c07bbba;
case 0x0c07bbbcu: goto P_0c07bbbc;
case 0x0c07bbbeu: goto P_0c07bbbe;
case 0x0c07bbc0u: goto P_0c07bbc0;
case 0x0c07bbc2u: goto P_0c07bbc2;
case 0x0c07bbc4u: goto P_0c07bbc4;
case 0x0c07bbc6u: goto P_0c07bbc6;
case 0x0c07bbc8u: goto P_0c07bbc8;
case 0x0c07bbcau: goto P_0c07bbca;
case 0x0c07bbccu: goto P_0c07bbcc;
case 0x0c07bbceu: goto P_0c07bbce;
case 0x0c07bbd0u: goto P_0c07bbd0;
case 0x0c07bbd2u: goto P_0c07bbd2;
case 0x0c07bbd4u: goto P_0c07bbd4;
case 0x0c07bbd6u: goto P_0c07bbd6;
case 0x0c07bbd8u: goto P_0c07bbd8;
case 0x0c07bbdau: goto P_0c07bbda;
case 0x0c07bbdcu: goto P_0c07bbdc;
case 0x0c07bbdeu: goto P_0c07bbde;
case 0x0c07bbe0u: goto P_0c07bbe0;
case 0x0c07bbe2u: goto P_0c07bbe2;
case 0x0c07bbe4u: goto P_0c07bbe4;
case 0x0c07bbe6u: goto P_0c07bbe6;
case 0x0c07bbe8u: goto P_0c07bbe8;
case 0x0c07bbeau: goto P_0c07bbea;
case 0x0c07bbecu: goto P_0c07bbec;
case 0x0c07bbeeu: goto P_0c07bbee;
case 0x0c07bbf0u: goto P_0c07bbf0;
case 0x0c07bbf2u: goto P_0c07bbf2;
case 0x0c07bbf4u: goto P_0c07bbf4;
case 0x0c07bbf6u: goto P_0c07bbf6;
case 0x0c07bbf8u: goto P_0c07bbf8;
case 0x0c07bbfau: goto P_0c07bbfa;
case 0x0c07bbfcu: goto P_0c07bbfc;
case 0x0c07bbfeu: goto P_0c07bbfe;
case 0x0c07bc00u: goto P_0c07bc00;
case 0x0c07bc02u: goto P_0c07bc02;
case 0x0c07bc04u: goto P_0c07bc04;
case 0x0c07bc06u: goto P_0c07bc06;
case 0x0c07bc08u: goto P_0c07bc08;
case 0x0c07bc0au: goto P_0c07bc0a;
case 0x0c07bc0cu: goto P_0c07bc0c;
case 0x0c07bc0eu: goto P_0c07bc0e;
case 0x0c07bc10u: goto P_0c07bc10;
case 0x0c07bc12u: goto P_0c07bc12;
case 0x0c07bc14u: goto P_0c07bc14;
case 0x0c07bc16u: goto P_0c07bc16;
case 0x0c07bc18u: goto P_0c07bc18;
case 0x0c07bc1au: goto P_0c07bc1a;
case 0x0c07bc1cu: goto P_0c07bc1c;
case 0x0c07bc1eu: goto P_0c07bc1e;
case 0x0c07bc20u: goto P_0c07bc20;
case 0x0c07bc22u: goto P_0c07bc22;
case 0x0c07bc24u: goto P_0c07bc24;
case 0x0c07bc26u: goto P_0c07bc26;
case 0x0c07bc28u: goto P_0c07bc28;
case 0x0c07bc2au: goto P_0c07bc2a;
case 0x0c07bc2cu: goto P_0c07bc2c;
case 0x0c07bc2eu: goto P_0c07bc2e;
case 0x0c07bc30u: goto P_0c07bc30;
case 0x0c07bc32u: goto P_0c07bc32;
case 0x0c07bc34u: goto P_0c07bc34;
case 0x0c07bc36u: goto P_0c07bc36;
case 0x0c07bc38u: goto P_0c07bc38;
case 0x0c07bc3au: goto P_0c07bc3a;
case 0x0c07bc3cu: goto P_0c07bc3c;
case 0x0c07bc3eu: goto P_0c07bc3e;
case 0x0c07bc40u: goto P_0c07bc40;
case 0x0c07bc42u: goto P_0c07bc42;
case 0x0c07bc44u: goto P_0c07bc44;
case 0x0c07bc46u: goto P_0c07bc46;
case 0x0c07bc48u: goto P_0c07bc48;
case 0x0c07bc4au: goto P_0c07bc4a;
case 0x0c07bc4cu: goto P_0c07bc4c;
case 0x0c07bc4eu: goto P_0c07bc4e;
case 0x0c07bc50u: goto P_0c07bc50;
case 0x0c07bc52u: goto P_0c07bc52;
case 0x0c07bc54u: goto P_0c07bc54;
case 0x0c07bc56u: goto P_0c07bc56;
case 0x0c07bc58u: goto P_0c07bc58;
case 0x0c07bc5au: goto P_0c07bc5a;
case 0x0c07bc5cu: goto P_0c07bc5c;
case 0x0c07bc5eu: goto P_0c07bc5e;
case 0x0c07bc60u: goto P_0c07bc60;
case 0x0c07bc62u: goto P_0c07bc62;
case 0x0c07bc64u: goto P_0c07bc64;
case 0x0c07bc66u: goto P_0c07bc66;
case 0x0c07bc68u: goto P_0c07bc68;
case 0x0c07bc6au: goto P_0c07bc6a;
case 0x0c07bc6cu: goto P_0c07bc6c;
case 0x0c07bc6eu: goto P_0c07bc6e;
case 0x0c07bc70u: goto P_0c07bc70;
case 0x0c07bc72u: goto P_0c07bc72;
case 0x0c07bc74u: goto P_0c07bc74;
case 0x0c07bc76u: goto P_0c07bc76;
case 0x0c07bc78u: goto P_0c07bc78;
case 0x0c07bc7au: goto P_0c07bc7a;
case 0x0c07bc7cu: goto P_0c07bc7c;
case 0x0c07bc7eu: goto P_0c07bc7e;
case 0x0c07bc80u: goto P_0c07bc80;
case 0x0c07bc82u: goto P_0c07bc82;
case 0x0c07bc84u: goto P_0c07bc84;
case 0x0c07bc86u: goto P_0c07bc86;
case 0x0c07bc88u: goto P_0c07bc88;
case 0x0c07bc8au: goto P_0c07bc8a;
case 0x0c07bc8cu: goto P_0c07bc8c;
case 0x0c07bc8eu: goto P_0c07bc8e;
case 0x0c07bc90u: goto P_0c07bc90;
case 0x0c07bc92u: goto P_0c07bc92;
case 0x0c07bc94u: goto P_0c07bc94;
case 0x0c07bc96u: goto P_0c07bc96;
case 0x0c07bc98u: goto P_0c07bc98;
case 0x0c07bc9au: goto P_0c07bc9a;
case 0x0c07bc9cu: goto P_0c07bc9c;
case 0x0c07bc9eu: goto P_0c07bc9e;
case 0x0c07bca0u: goto P_0c07bca0;
case 0x0c07bca2u: goto P_0c07bca2;
case 0x0c07bca4u: goto P_0c07bca4;
case 0x0c07bca6u: goto P_0c07bca6;
case 0x0c07bca8u: goto P_0c07bca8;
case 0x0c07bcaau: goto P_0c07bcaa;
case 0x0c07bcacu: goto P_0c07bcac;
case 0x0c07bcaeu: goto P_0c07bcae;
case 0x0c07bcb0u: goto P_0c07bcb0;
case 0x0c07bcb2u: goto P_0c07bcb2;
case 0x0c07bcb4u: goto P_0c07bcb4;
case 0x0c07bcb6u: goto P_0c07bcb6;
case 0x0c07bcb8u: goto P_0c07bcb8;
case 0x0c07bcbau: goto P_0c07bcba;
case 0x0c07bcbcu: goto P_0c07bcbc;
case 0x0c07bcbeu: goto P_0c07bcbe;
case 0x0c07bcc0u: goto P_0c07bcc0;
case 0x0c07bcc2u: goto P_0c07bcc2;
case 0x0c07bcc4u: goto P_0c07bcc4;
case 0x0c07bcc6u: goto P_0c07bcc6;
case 0x0c07bcc8u: goto P_0c07bcc8;
case 0x0c07bccau: goto P_0c07bcca;
case 0x0c07bcccu: goto P_0c07bccc;
case 0x0c07bcceu: goto P_0c07bcce;
case 0x0c07bcd0u: goto P_0c07bcd0;
case 0x0c07bcd2u: goto P_0c07bcd2;
case 0x0c07bcd4u: goto P_0c07bcd4;
case 0x0c07bcd6u: goto P_0c07bcd6;
case 0x0c07bcd8u: goto P_0c07bcd8;
case 0x0c07bcdau: goto P_0c07bcda;
case 0x0c07bcdcu: goto P_0c07bcdc;
case 0x0c07bcdeu: goto P_0c07bcde;
case 0x0c07bce0u: goto P_0c07bce0;
case 0x0c07bce2u: goto P_0c07bce2;
case 0x0c07bce4u: goto P_0c07bce4;
case 0x0c07bce6u: goto P_0c07bce6;
case 0x0c07bce8u: goto P_0c07bce8;
case 0x0c07bceau: goto P_0c07bcea;
case 0x0c07bcecu: goto P_0c07bcec;
case 0x0c07bceeu: goto P_0c07bcee;
case 0x0c07bcf0u: goto P_0c07bcf0;
case 0x0c07bcf2u: goto P_0c07bcf2;
case 0x0c07bcf4u: goto P_0c07bcf4;
case 0x0c07bcf6u: goto P_0c07bcf6;
case 0x0c07bcf8u: goto P_0c07bcf8;
case 0x0c07bd14u: goto P_0c07bd14;
case 0x0c07bd16u: goto P_0c07bd16;
case 0x0c07bd18u: goto P_0c07bd18;
case 0x0c07bd1au: goto P_0c07bd1a;
case 0x0c07bd1cu: goto P_0c07bd1c;
case 0x0c07bd1eu: goto P_0c07bd1e;
case 0x0c07bd20u: goto P_0c07bd20;
case 0x0c07bd22u: goto P_0c07bd22;
case 0x0c07bd24u: goto P_0c07bd24;
case 0x0c07bd26u: goto P_0c07bd26;
case 0x0c07bd28u: goto P_0c07bd28;
case 0x0c07bd2au: goto P_0c07bd2a;
case 0x0c07bd2cu: goto P_0c07bd2c;
case 0x0c07bd2eu: goto P_0c07bd2e;
case 0x0c07bd30u: goto P_0c07bd30;
case 0x0c07bd32u: goto P_0c07bd32;
case 0x0c07bd34u: goto P_0c07bd34;
case 0x0c07bd36u: goto P_0c07bd36;
case 0x0c07bd38u: goto P_0c07bd38;
case 0x0c07bd3au: goto P_0c07bd3a;
case 0x0c07bd3cu: goto P_0c07bd3c;
case 0x0c07bd3eu: goto P_0c07bd3e;
case 0x0c07bd40u: goto P_0c07bd40;
case 0x0c07bd42u: goto P_0c07bd42;
case 0x0c07bd44u: goto P_0c07bd44;
case 0x0c07bd46u: goto P_0c07bd46;
case 0x0c07bd48u: goto P_0c07bd48;
case 0x0c07bd4au: goto P_0c07bd4a;
case 0x0c07bd4cu: goto P_0c07bd4c;
case 0x0c07bd4eu: goto P_0c07bd4e;
case 0x0c07bd50u: goto P_0c07bd50;
case 0x0c07bd52u: goto P_0c07bd52;
case 0x0c07bd54u: goto P_0c07bd54;
case 0x0c07bd56u: goto P_0c07bd56;
case 0x0c07bd58u: goto P_0c07bd58;
case 0x0c07bd5au: goto P_0c07bd5a;
case 0x0c07bd5cu: goto P_0c07bd5c;
case 0x0c07bd5eu: goto P_0c07bd5e;
case 0x0c07bd60u: goto P_0c07bd60;
case 0x0c07bd62u: goto P_0c07bd62;
case 0x0c07bd64u: goto P_0c07bd64;
case 0x0c07bd66u: goto P_0c07bd66;
case 0x0c07bd68u: goto P_0c07bd68;
case 0x0c07bd6au: goto P_0c07bd6a;
case 0x0c07bd6cu: goto P_0c07bd6c;
case 0x0c07bd6eu: goto P_0c07bd6e;
case 0x0c07bd70u: goto P_0c07bd70;
case 0x0c07bd72u: goto P_0c07bd72;
case 0x0c07bd74u: goto P_0c07bd74;
case 0x0c07bd76u: goto P_0c07bd76;
case 0x0c07bd78u: goto P_0c07bd78;
case 0x0c07bd7au: goto P_0c07bd7a;
case 0x0c07bd7cu: goto P_0c07bd7c;
case 0x0c07bd7eu: goto P_0c07bd7e;
case 0x0c07bd80u: goto P_0c07bd80;
case 0x0c07bd82u: goto P_0c07bd82;
case 0x0c07bd84u: goto P_0c07bd84;
case 0x0c07bd86u: goto P_0c07bd86;
case 0x0c07bd88u: goto P_0c07bd88;
case 0x0c07bd8au: goto P_0c07bd8a;
case 0x0c07bd8cu: goto P_0c07bd8c;
case 0x0c07bd8eu: goto P_0c07bd8e;
case 0x0c07bd90u: goto P_0c07bd90;
case 0x0c07bd92u: goto P_0c07bd92;
case 0x0c07bd94u: goto P_0c07bd94;
case 0x0c07bd96u: goto P_0c07bd96;
case 0x0c07bd98u: goto P_0c07bd98;
case 0x0c07bd9au: goto P_0c07bd9a;
case 0x0c07bd9cu: goto P_0c07bd9c;
case 0x0c07bd9eu: goto P_0c07bd9e;
case 0x0c07bda0u: goto P_0c07bda0;
case 0x0c07bda2u: goto P_0c07bda2;
case 0x0c07bda4u: goto P_0c07bda4;
case 0x0c07bda6u: goto P_0c07bda6;
case 0x0c07bda8u: goto P_0c07bda8;
case 0x0c07bdaau: goto P_0c07bdaa;
case 0x0c07bdacu: goto P_0c07bdac;
case 0x0c07bdaeu: goto P_0c07bdae;
case 0x0c07bdb0u: goto P_0c07bdb0;
case 0x0c07bdb2u: goto P_0c07bdb2;
case 0x0c07bdb4u: goto P_0c07bdb4;
case 0x0c07bdb6u: goto P_0c07bdb6;
case 0x0c07bdb8u: goto P_0c07bdb8;
case 0x0c07bdbau: goto P_0c07bdba;
case 0x0c07bdbcu: goto P_0c07bdbc;
case 0x0c07bdbeu: goto P_0c07bdbe;
case 0x0c07bdc0u: goto P_0c07bdc0;
case 0x0c07bdc2u: goto P_0c07bdc2;
case 0x0c07bdc4u: goto P_0c07bdc4;
case 0x0c07bdc6u: goto P_0c07bdc6;
case 0x0c07bdc8u: goto P_0c07bdc8;
case 0x0c07bdcau: goto P_0c07bdca;
case 0x0c07bdccu: goto P_0c07bdcc;
case 0x0c07bdceu: goto P_0c07bdce;
case 0x0c07bdd0u: goto P_0c07bdd0;
case 0x0c07bdd2u: goto P_0c07bdd2;
case 0x0c07bdd4u: goto P_0c07bdd4;
case 0x0c07bdd6u: goto P_0c07bdd6;
case 0x0c07bdd8u: goto P_0c07bdd8;
case 0x0c07bddau: goto P_0c07bdda;
case 0x0c07bddcu: goto P_0c07bddc;
case 0x0c07bddeu: goto P_0c07bdde;
case 0x0c07bde0u: goto P_0c07bde0;
case 0x0c07bde2u: goto P_0c07bde2;
case 0x0c07bde4u: goto P_0c07bde4;
case 0x0c07bde6u: goto P_0c07bde6;
case 0x0c07bde8u: goto P_0c07bde8;
case 0x0c07bdeau: goto P_0c07bdea;
case 0x0c07bdecu: goto P_0c07bdec;
case 0x0c07bdeeu: goto P_0c07bdee;
case 0x0c07bdf0u: goto P_0c07bdf0;
case 0x0c07bdf2u: goto P_0c07bdf2;
case 0x0c07bdf4u: goto P_0c07bdf4;
case 0x0c07bdf6u: goto P_0c07bdf6;
case 0x0c07bdf8u: goto P_0c07bdf8;
case 0x0c07bdfau: goto P_0c07bdfa;
case 0x0c07bdfcu: goto P_0c07bdfc;
case 0x0c07bdfeu: goto P_0c07bdfe;
case 0x0c07be00u: goto P_0c07be00;
case 0x0c07be02u: goto P_0c07be02;
case 0x0c07be04u: goto P_0c07be04;
case 0x0c07be06u: goto P_0c07be06;
case 0x0c07be08u: goto P_0c07be08;
case 0x0c07be0au: goto P_0c07be0a;
case 0x0c07be0cu: goto P_0c07be0c;
case 0x0c07be0eu: goto P_0c07be0e;
case 0x0c07be10u: goto P_0c07be10;
case 0x0c07be12u: goto P_0c07be12;
case 0x0c07be14u: goto P_0c07be14;
case 0x0c07be16u: goto P_0c07be16;
case 0x0c07be18u: goto P_0c07be18;
case 0x0c07be1au: goto P_0c07be1a;
case 0x0c07be1cu: goto P_0c07be1c;
case 0x0c07be1eu: goto P_0c07be1e;
case 0x0c07be20u: goto P_0c07be20;
case 0x0c07be22u: goto P_0c07be22;
case 0x0c07be24u: goto P_0c07be24;
case 0x0c07be26u: goto P_0c07be26;
case 0x0c07be28u: goto P_0c07be28;
case 0x0c07be2au: goto P_0c07be2a;
case 0x0c07be2cu: goto P_0c07be2c;
case 0x0c07be2eu: goto P_0c07be2e;
case 0x0c07be30u: goto P_0c07be30;
case 0x0c07be32u: goto P_0c07be32;
case 0x0c07be34u: goto P_0c07be34;
case 0x0c07be36u: goto P_0c07be36;
case 0x0c07be38u: goto P_0c07be38;
case 0x0c07be3au: goto P_0c07be3a;
case 0x0c07be3cu: goto P_0c07be3c;
case 0x0c07be3eu: goto P_0c07be3e;
case 0x0c07be40u: goto P_0c07be40;
case 0x0c07be42u: goto P_0c07be42;
case 0x0c07be44u: goto P_0c07be44;
case 0x0c07be46u: goto P_0c07be46;
case 0x0c07be48u: goto P_0c07be48;
case 0x0c07be4au: goto P_0c07be4a;
case 0x0c07be4cu: goto P_0c07be4c;
case 0x0c07be4eu: goto P_0c07be4e;
case 0x0c07be50u: goto P_0c07be50;
case 0x0c07be52u: goto P_0c07be52;
case 0x0c07be54u: goto P_0c07be54;
case 0x0c07be56u: goto P_0c07be56;
case 0x0c07be58u: goto P_0c07be58;
case 0x0c07be5au: goto P_0c07be5a;
case 0x0c07be5cu: goto P_0c07be5c;
case 0x0c07be5eu: goto P_0c07be5e;
case 0x0c07be60u: goto P_0c07be60;
case 0x0c07be62u: goto P_0c07be62;
case 0x0c07be64u: goto P_0c07be64;
case 0x0c07be66u: goto P_0c07be66;
case 0x0c07be68u: goto P_0c07be68;
case 0x0c07be6au: goto P_0c07be6a;
case 0x0c07be6cu: goto P_0c07be6c;
case 0x0c07be6eu: goto P_0c07be6e;
case 0x0c07be70u: goto P_0c07be70;
case 0x0c07be72u: goto P_0c07be72;
case 0x0c07be74u: goto P_0c07be74;
case 0x0c07be76u: goto P_0c07be76;
case 0x0c07be78u: goto P_0c07be78;
case 0x0c07be7au: goto P_0c07be7a;
case 0x0c07be7cu: goto P_0c07be7c;
case 0x0c07be7eu: goto P_0c07be7e;
case 0x0c07be80u: goto P_0c07be80;
case 0x0c07be82u: goto P_0c07be82;
case 0x0c07be84u: goto P_0c07be84;
case 0x0c07be86u: goto P_0c07be86;
case 0x0c07be88u: goto P_0c07be88;
case 0x0c07be8au: goto P_0c07be8a;
case 0x0c07be8cu: goto P_0c07be8c;
case 0x0c07be8eu: goto P_0c07be8e;
case 0x0c07be90u: goto P_0c07be90;
case 0x0c07be92u: goto P_0c07be92;
case 0x0c07be94u: goto P_0c07be94;
case 0x0c07be96u: goto P_0c07be96;
case 0x0c07be98u: goto P_0c07be98;
case 0x0c07be9au: goto P_0c07be9a;
case 0x0c07beb0u: goto P_0c07beb0;
case 0x0c07beb2u: goto P_0c07beb2;
case 0x0c07beb4u: goto P_0c07beb4;
case 0x0c07beb6u: goto P_0c07beb6;
case 0x0c07beb8u: goto P_0c07beb8;
case 0x0c07bebau: goto P_0c07beba;
case 0x0c07bebcu: goto P_0c07bebc;
case 0x0c07bebeu: goto P_0c07bebe;
case 0x0c07bec0u: goto P_0c07bec0;
case 0x0c07bec2u: goto P_0c07bec2;
case 0x0c07bec4u: goto P_0c07bec4;
case 0x0c07bec6u: goto P_0c07bec6;
case 0x0c07bec8u: goto P_0c07bec8;
case 0x0c07becau: goto P_0c07beca;
case 0x0c07beccu: goto P_0c07becc;
case 0x0c07beceu: goto P_0c07bece;
case 0x0c07bed0u: goto P_0c07bed0;
case 0x0c07bed2u: goto P_0c07bed2;
case 0x0c07bed4u: goto P_0c07bed4;
case 0x0c07bed6u: goto P_0c07bed6;
case 0x0c07bed8u: goto P_0c07bed8;
case 0x0c07bedau: goto P_0c07beda;
case 0x0c07bedcu: goto P_0c07bedc;
case 0x0c07bedeu: goto P_0c07bede;
case 0x0c07bee0u: goto P_0c07bee0;
case 0x0c07bee2u: goto P_0c07bee2;
case 0x0c07bee4u: goto P_0c07bee4;
case 0x0c07bee6u: goto P_0c07bee6;
case 0x0c07bee8u: goto P_0c07bee8;
case 0x0c07beeau: goto P_0c07beea;
case 0x0c07beecu: goto P_0c07beec;
case 0x0c07beeeu: goto P_0c07beee;
case 0x0c07bef0u: goto P_0c07bef0;
case 0x0c07bef2u: goto P_0c07bef2;
case 0x0c07bef4u: goto P_0c07bef4;
case 0x0c07bef6u: goto P_0c07bef6;
case 0x0c07bef8u: goto P_0c07bef8;
case 0x0c07befau: goto P_0c07befa;
case 0x0c07befcu: goto P_0c07befc;
case 0x0c07befeu: goto P_0c07befe;
case 0x0c07bf00u: goto P_0c07bf00;
case 0x0c07bf02u: goto P_0c07bf02;
case 0x0c07bf04u: goto P_0c07bf04;
case 0x0c07bf06u: goto P_0c07bf06;
case 0x0c07bf08u: goto P_0c07bf08;
case 0x0c07bf0au: goto P_0c07bf0a;
case 0x0c07bf0cu: goto P_0c07bf0c;
case 0x0c07bf0eu: goto P_0c07bf0e;
case 0x0c07bf10u: goto P_0c07bf10;
case 0x0c07bf12u: goto P_0c07bf12;
case 0x0c07bf14u: goto P_0c07bf14;
case 0x0c07bf16u: goto P_0c07bf16;
case 0x0c07bf18u: goto P_0c07bf18;
case 0x0c07bf1au: goto P_0c07bf1a;
case 0x0c07bf1cu: goto P_0c07bf1c;
case 0x0c07bf1eu: goto P_0c07bf1e;
case 0x0c07bf20u: goto P_0c07bf20;
case 0x0c07bf22u: goto P_0c07bf22;
case 0x0c07bf24u: goto P_0c07bf24;
case 0x0c07bf26u: goto P_0c07bf26;
case 0x0c07bf28u: goto P_0c07bf28;
case 0x0c07bf2au: goto P_0c07bf2a;
case 0x0c07bf2cu: goto P_0c07bf2c;
case 0x0c07bf2eu: goto P_0c07bf2e;
case 0x0c07bf30u: goto P_0c07bf30;
case 0x0c07bf32u: goto P_0c07bf32;
case 0x0c07bf34u: goto P_0c07bf34;
case 0x0c07bf36u: goto P_0c07bf36;
case 0x0c07bf38u: goto P_0c07bf38;
case 0x0c07bf3au: goto P_0c07bf3a;
case 0x0c07bf3cu: goto P_0c07bf3c;
case 0x0c07bf3eu: goto P_0c07bf3e;
case 0x0c07bf40u: goto P_0c07bf40;
case 0x0c07bf42u: goto P_0c07bf42;
case 0x0c07bf44u: goto P_0c07bf44;
case 0x0c07bf46u: goto P_0c07bf46;
case 0x0c07bf48u: goto P_0c07bf48;
case 0x0c07bf4au: goto P_0c07bf4a;
case 0x0c07bf4cu: goto P_0c07bf4c;
case 0x0c07bf4eu: goto P_0c07bf4e;
case 0x0c07bf50u: goto P_0c07bf50;
case 0x0c07bf52u: goto P_0c07bf52;
case 0x0c07bf54u: goto P_0c07bf54;
case 0x0c07bf56u: goto P_0c07bf56;
case 0x0c07bf58u: goto P_0c07bf58;
case 0x0c07bf5au: goto P_0c07bf5a;
case 0x0c07bf5cu: goto P_0c07bf5c;
case 0x0c07bf5eu: goto P_0c07bf5e;
case 0x0c07bf60u: goto P_0c07bf60;
case 0x0c07bf62u: goto P_0c07bf62;
case 0x0c07bf64u: goto P_0c07bf64;
case 0x0c07bf66u: goto P_0c07bf66;
case 0x0c07bf68u: goto P_0c07bf68;
case 0x0c07bf6au: goto P_0c07bf6a;
case 0x0c07bf6cu: goto P_0c07bf6c;
case 0x0c07bf6eu: goto P_0c07bf6e;
case 0x0c07bf70u: goto P_0c07bf70;
case 0x0c07bf72u: goto P_0c07bf72;
case 0x0c07bf74u: goto P_0c07bf74;
case 0x0c07bf76u: goto P_0c07bf76;
case 0x0c07bf78u: goto P_0c07bf78;
case 0x0c07bf7au: goto P_0c07bf7a;
case 0x0c07bf7cu: goto P_0c07bf7c;
case 0x0c07bf7eu: goto P_0c07bf7e;
case 0x0c07bf80u: goto P_0c07bf80;
case 0x0c07bf82u: goto P_0c07bf82;
case 0x0c07bf84u: goto P_0c07bf84;
case 0x0c07bf86u: goto P_0c07bf86;
case 0x0c07bf88u: goto P_0c07bf88;
case 0x0c07bf8au: goto P_0c07bf8a;
case 0x0c07bf8cu: goto P_0c07bf8c;
case 0x0c07bf8eu: goto P_0c07bf8e;
case 0x0c07bf90u: goto P_0c07bf90;
case 0x0c07bf92u: goto P_0c07bf92;
case 0x0c07bf94u: goto P_0c07bf94;
case 0x0c07bf96u: goto P_0c07bf96;
case 0x0c07bf98u: goto P_0c07bf98;
case 0x0c07bf9au: goto P_0c07bf9a;
case 0x0c07bf9cu: goto P_0c07bf9c;
case 0x0c07bf9eu: goto P_0c07bf9e;
case 0x0c07bfa0u: goto P_0c07bfa0;
case 0x0c07bfa2u: goto P_0c07bfa2;
case 0x0c07bfa4u: goto P_0c07bfa4;
case 0x0c07bfa6u: goto P_0c07bfa6;
case 0x0c07bfa8u: goto P_0c07bfa8;
case 0x0c07bfaau: goto P_0c07bfaa;
case 0x0c07bfacu: goto P_0c07bfac;
case 0x0c07bfaeu: goto P_0c07bfae;
case 0x0c07bfb0u: goto P_0c07bfb0;
case 0x0c07bfb2u: goto P_0c07bfb2;
case 0x0c07bfb4u: goto P_0c07bfb4;
case 0x0c07bfb6u: goto P_0c07bfb6;
case 0x0c07bfb8u: goto P_0c07bfb8;
case 0x0c07bfbau: goto P_0c07bfba;
case 0x0c07bfbcu: goto P_0c07bfbc;
case 0x0c07bfbeu: goto P_0c07bfbe;
case 0x0c07bfc0u: goto P_0c07bfc0;
case 0x0c07bfc2u: goto P_0c07bfc2;
case 0x0c07bfc4u: goto P_0c07bfc4;
case 0x0c07bfc6u: goto P_0c07bfc6;
case 0x0c07bfc8u: goto P_0c07bfc8;
case 0x0c07bfcau: goto P_0c07bfca;
case 0x0c07bfccu: goto P_0c07bfcc;
case 0x0c07bfceu: goto P_0c07bfce;
case 0x0c07bfd0u: goto P_0c07bfd0;
case 0x0c07bfd2u: goto P_0c07bfd2;
case 0x0c07bfd4u: goto P_0c07bfd4;
case 0x0c07bfd6u: goto P_0c07bfd6;
case 0x0c07bfd8u: goto P_0c07bfd8;
case 0x0c07bfdau: goto P_0c07bfda;
case 0x0c07bfdcu: goto P_0c07bfdc;
case 0x0c07bfdeu: goto P_0c07bfde;
case 0x0c07bfe0u: goto P_0c07bfe0;
case 0x0c07bfe2u: goto P_0c07bfe2;
case 0x0c07bfe4u: goto P_0c07bfe4;
case 0x0c07bfe6u: goto P_0c07bfe6;
case 0x0c07bfe8u: goto P_0c07bfe8;
case 0x0c07bfeau: goto P_0c07bfea;
case 0x0c07bfecu: goto P_0c07bfec;
case 0x0c07bfeeu: goto P_0c07bfee;
case 0x0c07bff0u: goto P_0c07bff0;
case 0x0c07bff2u: goto P_0c07bff2;
case 0x0c07bff4u: goto P_0c07bff4;
case 0x0c07bff6u: goto P_0c07bff6;
case 0x0c07bff8u: goto P_0c07bff8;
case 0x0c07bffau: goto P_0c07bffa;
case 0x0c07bffcu: goto P_0c07bffc;
case 0x0c07bffeu: goto P_0c07bffe;
case 0x0c07c000u: goto P_0c07c000;
case 0x0c07c002u: goto P_0c07c002;
case 0x0c07c004u: goto P_0c07c004;
case 0x0c07c006u: goto P_0c07c006;
case 0x0c07c008u: goto P_0c07c008;
case 0x0c07c00au: goto P_0c07c00a;
case 0x0c07c00cu: goto P_0c07c00c;
case 0x0c07c00eu: goto P_0c07c00e;
case 0x0c07c010u: goto P_0c07c010;
case 0x0c07c012u: goto P_0c07c012;
case 0x0c07c014u: goto P_0c07c014;
case 0x0c07c016u: goto P_0c07c016;
case 0x0c07c018u: goto P_0c07c018;
case 0x0c07c01au: goto P_0c07c01a;
case 0x0c07c01cu: goto P_0c07c01c;
case 0x0c07c01eu: goto P_0c07c01e;
case 0x0c07c020u: goto P_0c07c020;
case 0x0c07c022u: goto P_0c07c022;
case 0x0c07c024u: goto P_0c07c024;
case 0x0c07c026u: goto P_0c07c026;
case 0x0c07c028u: goto P_0c07c028;
case 0x0c07c02au: goto P_0c07c02a;
case 0x0c07c02cu: goto P_0c07c02c;
case 0x0c07c02eu: goto P_0c07c02e;
case 0x0c07c030u: goto P_0c07c030;
case 0x0c07c032u: goto P_0c07c032;
case 0x0c07c034u: goto P_0c07c034;
case 0x0c07c036u: goto P_0c07c036;
case 0x0c07c038u: goto P_0c07c038;
case 0x0c07c03au: goto P_0c07c03a;
case 0x0c07c03cu: goto P_0c07c03c;
case 0x0c07c03eu: goto P_0c07c03e;
case 0x0c07c040u: goto P_0c07c040;
case 0x0c07c042u: goto P_0c07c042;
case 0x0c07c05cu: goto P_0c07c05c;
case 0x0c07c05eu: goto P_0c07c05e;
case 0x0c07c060u: goto P_0c07c060;
case 0x0c07c062u: goto P_0c07c062;
case 0x0c07c064u: goto P_0c07c064;
case 0x0c07c066u: goto P_0c07c066;
case 0x0c07c068u: goto P_0c07c068;
case 0x0c07c06au: goto P_0c07c06a;
case 0x0c07c06cu: goto P_0c07c06c;
case 0x0c07c06eu: goto P_0c07c06e;
case 0x0c07c070u: goto P_0c07c070;
case 0x0c07c072u: goto P_0c07c072;
case 0x0c07c074u: goto P_0c07c074;
case 0x0c07c076u: goto P_0c07c076;
case 0x0c07c078u: goto P_0c07c078;
case 0x0c07c07au: goto P_0c07c07a;
case 0x0c07c07cu: goto P_0c07c07c;
case 0x0c07c07eu: goto P_0c07c07e;
case 0x0c07c080u: goto P_0c07c080;
case 0x0c07c082u: goto P_0c07c082;
case 0x0c07c084u: goto P_0c07c084;
case 0x0c07c086u: goto P_0c07c086;
case 0x0c07c088u: goto P_0c07c088;
case 0x0c07c08au: goto P_0c07c08a;
case 0x0c07c08cu: goto P_0c07c08c;
case 0x0c07c08eu: goto P_0c07c08e;
case 0x0c07c090u: goto P_0c07c090;
case 0x0c07c092u: goto P_0c07c092;
case 0x0c07c094u: goto P_0c07c094;
case 0x0c07c096u: goto P_0c07c096;
case 0x0c07c098u: goto P_0c07c098;
case 0x0c07c09au: goto P_0c07c09a;
case 0x0c07c09cu: goto P_0c07c09c;
case 0x0c07c09eu: goto P_0c07c09e;
case 0x0c07c0a0u: goto P_0c07c0a0;
case 0x0c07c0a2u: goto P_0c07c0a2;
case 0x0c07c0a4u: goto P_0c07c0a4;
case 0x0c07c0a6u: goto P_0c07c0a6;
case 0x0c07c0a8u: goto P_0c07c0a8;
case 0x0c07c0aau: goto P_0c07c0aa;
case 0x0c07c0acu: goto P_0c07c0ac;
case 0x0c07c0aeu: goto P_0c07c0ae;
case 0x0c07c0b0u: goto P_0c07c0b0;
case 0x0c07c0b2u: goto P_0c07c0b2;
case 0x0c07c0b4u: goto P_0c07c0b4;
case 0x0c07c0b6u: goto P_0c07c0b6;
case 0x0c07c0b8u: goto P_0c07c0b8;
case 0x0c07c0bau: goto P_0c07c0ba;
case 0x0c07c0bcu: goto P_0c07c0bc;
case 0x0c07c0beu: goto P_0c07c0be;
case 0x0c07c0c0u: goto P_0c07c0c0;
case 0x0c07c0c2u: goto P_0c07c0c2;
case 0x0c07c0c4u: goto P_0c07c0c4;
case 0x0c07c0c6u: goto P_0c07c0c6;
case 0x0c07c0c8u: goto P_0c07c0c8;
case 0x0c07c0cau: goto P_0c07c0ca;
case 0x0c07c0ccu: goto P_0c07c0cc;
case 0x0c07c0ceu: goto P_0c07c0ce;
case 0x0c07c0d0u: goto P_0c07c0d0;
case 0x0c07c0d2u: goto P_0c07c0d2;
case 0x0c07c0d4u: goto P_0c07c0d4;
case 0x0c07c0d6u: goto P_0c07c0d6;
case 0x0c07c0d8u: goto P_0c07c0d8;
case 0x0c07c0dau: goto P_0c07c0da;
case 0x0c07c0dcu: goto P_0c07c0dc;
case 0x0c07c0deu: goto P_0c07c0de;
case 0x0c07c0e0u: goto P_0c07c0e0;
case 0x0c07c0e2u: goto P_0c07c0e2;
case 0x0c07c0e4u: goto P_0c07c0e4;
case 0x0c07c0e6u: goto P_0c07c0e6;
case 0x0c07c0e8u: goto P_0c07c0e8;
case 0x0c07c0eau: goto P_0c07c0ea;
case 0x0c07c0ecu: goto P_0c07c0ec;
case 0x0c07c0eeu: goto P_0c07c0ee;
case 0x0c07c0f0u: goto P_0c07c0f0;
case 0x0c07c0f2u: goto P_0c07c0f2;
case 0x0c07c0f4u: goto P_0c07c0f4;
case 0x0c07c0f6u: goto P_0c07c0f6;
case 0x0c07c0f8u: goto P_0c07c0f8;
case 0x0c07c0fau: goto P_0c07c0fa;
case 0x0c07c0fcu: goto P_0c07c0fc;
case 0x0c07c0feu: goto P_0c07c0fe;
case 0x0c07c100u: goto P_0c07c100;
case 0x0c07c102u: goto P_0c07c102;
case 0x0c07c12cu: goto P_0c07c12c;
case 0x0c07c12eu: goto P_0c07c12e;
case 0x0c07c130u: goto P_0c07c130;
case 0x0c07c132u: goto P_0c07c132;
case 0x0c07c134u: goto P_0c07c134;
case 0x0c07c136u: goto P_0c07c136;
case 0x0c07c138u: goto P_0c07c138;
case 0x0c07c13au: goto P_0c07c13a;
case 0x0c07c13cu: goto P_0c07c13c;
case 0x0c07c13eu: goto P_0c07c13e;
case 0x0c07c140u: goto P_0c07c140;
case 0x0c07c142u: goto P_0c07c142;
case 0x0c07c144u: goto P_0c07c144;
case 0x0c07c146u: goto P_0c07c146;
case 0x0c07c148u: goto P_0c07c148;
case 0x0c07c14au: goto P_0c07c14a;
case 0x0c07c14cu: goto P_0c07c14c;
case 0x0c07c14eu: goto P_0c07c14e;
case 0x0c07c150u: goto P_0c07c150;
case 0x0c07c152u: goto P_0c07c152;
case 0x0c07c154u: goto P_0c07c154;
case 0x0c07c156u: goto P_0c07c156;
case 0x0c07c158u: goto P_0c07c158;
case 0x0c07c15au: goto P_0c07c15a;
case 0x0c07c15cu: goto P_0c07c15c;
case 0x0c07c15eu: goto P_0c07c15e;
case 0x0c07c160u: goto P_0c07c160;
case 0x0c07c162u: goto P_0c07c162;
case 0x0c07c164u: goto P_0c07c164;
case 0x0c07c166u: goto P_0c07c166;
case 0x0c07c168u: goto P_0c07c168;
case 0x0c07c16au: goto P_0c07c16a;
case 0x0c07c16cu: goto P_0c07c16c;
case 0x0c07c16eu: goto P_0c07c16e;
case 0x0c07c170u: goto P_0c07c170;
case 0x0c07c172u: goto P_0c07c172;
case 0x0c07c174u: goto P_0c07c174;
case 0x0c07c176u: goto P_0c07c176;
case 0x0c07c178u: goto P_0c07c178;
case 0x0c07c17au: goto P_0c07c17a;
case 0x0c07c17cu: goto P_0c07c17c;
case 0x0c07c17eu: goto P_0c07c17e;
case 0x0c07c180u: goto P_0c07c180;
case 0x0c07c182u: goto P_0c07c182;
case 0x0c07c184u: goto P_0c07c184;
case 0x0c07c186u: goto P_0c07c186;
case 0x0c07c188u: goto P_0c07c188;
case 0x0c07c18au: goto P_0c07c18a;
case 0x0c07c18cu: goto P_0c07c18c;
case 0x0c07c18eu: goto P_0c07c18e;
case 0x0c07c190u: goto P_0c07c190;
case 0x0c07c192u: goto P_0c07c192;
case 0x0c07c194u: goto P_0c07c194;
case 0x0c07c196u: goto P_0c07c196;
case 0x0c07c198u: goto P_0c07c198;
case 0x0c07c19au: goto P_0c07c19a;
case 0x0c07c19cu: goto P_0c07c19c;
case 0x0c07c19eu: goto P_0c07c19e;
case 0x0c07c1a0u: goto P_0c07c1a0;
case 0x0c07c1a2u: goto P_0c07c1a2;
case 0x0c07c1a4u: goto P_0c07c1a4;
case 0x0c07c1a6u: goto P_0c07c1a6;
case 0x0c07c1a8u: goto P_0c07c1a8;
case 0x0c07c1aau: goto P_0c07c1aa;
case 0x0c07c1acu: goto P_0c07c1ac;
case 0x0c07c1aeu: goto P_0c07c1ae;
case 0x0c07c1b0u: goto P_0c07c1b0;
case 0x0c07c1b2u: goto P_0c07c1b2;
case 0x0c07c1b4u: goto P_0c07c1b4;
case 0x0c07c1b6u: goto P_0c07c1b6;
case 0x0c07c1b8u: goto P_0c07c1b8;
case 0x0c07c1bau: goto P_0c07c1ba;
case 0x0c07c1bcu: goto P_0c07c1bc;
case 0x0c07c1beu: goto P_0c07c1be;
case 0x0c07c1c0u: goto P_0c07c1c0;
case 0x0c07c1c2u: goto P_0c07c1c2;
case 0x0c07c1c4u: goto P_0c07c1c4;
case 0x0c07c1c6u: goto P_0c07c1c6;
case 0x0c07c1c8u: goto P_0c07c1c8;
case 0x0c07c1cau: goto P_0c07c1ca;
case 0x0c07c1ccu: goto P_0c07c1cc;
case 0x0c07c1ceu: goto P_0c07c1ce;
case 0x0c07c1d0u: goto P_0c07c1d0;
case 0x0c07c1d2u: goto P_0c07c1d2;
case 0x0c07c1d4u: goto P_0c07c1d4;
case 0x0c07c1d6u: goto P_0c07c1d6;
case 0x0c07c1d8u: goto P_0c07c1d8;
case 0x0c07c1dau: goto P_0c07c1da;
case 0x0c07c1dcu: goto P_0c07c1dc;
case 0x0c07c1deu: goto P_0c07c1de;
case 0x0c07c1e0u: goto P_0c07c1e0;
case 0x0c07c1e2u: goto P_0c07c1e2;
case 0x0c07c1e4u: goto P_0c07c1e4;
case 0x0c07c1e6u: goto P_0c07c1e6;
case 0x0c07c1e8u: goto P_0c07c1e8;
case 0x0c07c1eau: goto P_0c07c1ea;
case 0x0c07c1ecu: goto P_0c07c1ec;
case 0x0c07c1eeu: goto P_0c07c1ee;
case 0x0c07c1f0u: goto P_0c07c1f0;
case 0x0c07c1f2u: goto P_0c07c1f2;
case 0x0c07c1f4u: goto P_0c07c1f4;
case 0x0c07c1f6u: goto P_0c07c1f6;
case 0x0c07c1f8u: goto P_0c07c1f8;
case 0x0c07c1fau: goto P_0c07c1fa;
case 0x0c07c1fcu: goto P_0c07c1fc;
case 0x0c07c1feu: goto P_0c07c1fe;
case 0x0c07c200u: goto P_0c07c200;
case 0x0c07c202u: goto P_0c07c202;
case 0x0c07c204u: goto P_0c07c204;
case 0x0c07c206u: goto P_0c07c206;
case 0x0c07c208u: goto P_0c07c208;
case 0x0c07c20au: goto P_0c07c20a;
case 0x0c07c20cu: goto P_0c07c20c;
case 0x0c07c20eu: goto P_0c07c20e;
case 0x0c07c210u: goto P_0c07c210;
case 0x0c07c212u: goto P_0c07c212;
case 0x0c07c214u: goto P_0c07c214;
case 0x0c07c216u: goto P_0c07c216;
case 0x0c07c218u: goto P_0c07c218;
case 0x0c07c21au: goto P_0c07c21a;
case 0x0c07c21cu: goto P_0c07c21c;
case 0x0c07c21eu: goto P_0c07c21e;
case 0x0c07c220u: goto P_0c07c220;
case 0x0c07c222u: goto P_0c07c222;
case 0x0c07c224u: goto P_0c07c224;
case 0x0c07c226u: goto P_0c07c226;
case 0x0c07c228u: goto P_0c07c228;
case 0x0c07c22au: goto P_0c07c22a;
case 0x0c07c22cu: goto P_0c07c22c;
case 0x0c07c22eu: goto P_0c07c22e;
case 0x0c07c230u: goto P_0c07c230;
case 0x0c07c232u: goto P_0c07c232;
case 0x0c07c234u: goto P_0c07c234;
case 0x0c07c236u: goto P_0c07c236;
case 0x0c07c238u: goto P_0c07c238;
case 0x0c07c23au: goto P_0c07c23a;
case 0x0c07c23cu: goto P_0c07c23c;
case 0x0c07c23eu: goto P_0c07c23e;
case 0x0c07c240u: goto P_0c07c240;
case 0x0c07c242u: goto P_0c07c242;
case 0x0c07c244u: goto P_0c07c244;
case 0x0c07c246u: goto P_0c07c246;
case 0x0c07c248u: goto P_0c07c248;
case 0x0c07c24au: goto P_0c07c24a;
case 0x0c07c24cu: goto P_0c07c24c;
case 0x0c07c24eu: goto P_0c07c24e;
case 0x0c07c250u: goto P_0c07c250;
case 0x0c07c252u: goto P_0c07c252;
case 0x0c07c254u: goto P_0c07c254;
case 0x0c07c256u: goto P_0c07c256;
case 0x0c07c258u: goto P_0c07c258;
case 0x0c07c25au: goto P_0c07c25a;
case 0x0c07c25cu: goto P_0c07c25c;
case 0x0c07c25eu: goto P_0c07c25e;
case 0x0c07c260u: goto P_0c07c260;
case 0x0c07c262u: goto P_0c07c262;
case 0x0c07c264u: goto P_0c07c264;
case 0x0c07c266u: goto P_0c07c266;
case 0x0c07c268u: goto P_0c07c268;
case 0x0c07c26au: goto P_0c07c26a;
case 0x0c07c26cu: goto P_0c07c26c;
case 0x0c07c26eu: goto P_0c07c26e;
case 0x0c07c270u: goto P_0c07c270;
case 0x0c07c272u: goto P_0c07c272;
case 0x0c07c274u: goto P_0c07c274;
case 0x0c07c276u: goto P_0c07c276;
case 0x0c07c278u: goto P_0c07c278;
case 0x0c07c27au: goto P_0c07c27a;
case 0x0c07c27cu: goto P_0c07c27c;
case 0x0c07c27eu: goto P_0c07c27e;
case 0x0c07c280u: goto P_0c07c280;
case 0x0c07c282u: goto P_0c07c282;
case 0x0c07c284u: goto P_0c07c284;
case 0x0c07c286u: goto P_0c07c286;
case 0x0c07c288u: goto P_0c07c288;
case 0x0c07c28au: goto P_0c07c28a;
case 0x0c07c28cu: goto P_0c07c28c;
case 0x0c07c28eu: goto P_0c07c28e;
case 0x0c07c290u: goto P_0c07c290;
case 0x0c07c292u: goto P_0c07c292;
case 0x0c07c294u: goto P_0c07c294;
case 0x0c07c296u: goto P_0c07c296;
case 0x0c07c298u: goto P_0c07c298;
case 0x0c07c29au: goto P_0c07c29a;
case 0x0c07c29cu: goto P_0c07c29c;
case 0x0c07c29eu: goto P_0c07c29e;
case 0x0c07c2a0u: goto P_0c07c2a0;
case 0x0c07c2a2u: goto P_0c07c2a2;
case 0x0c07c2a4u: goto P_0c07c2a4;
case 0x0c07c2a6u: goto P_0c07c2a6;
case 0x0c07c2a8u: goto P_0c07c2a8;
case 0x0c07c2aau: goto P_0c07c2aa;
case 0x0c07c2acu: goto P_0c07c2ac;
case 0x0c07c2aeu: goto P_0c07c2ae;
case 0x0c07c2b0u: goto P_0c07c2b0;
case 0x0c07c2b2u: goto P_0c07c2b2;
case 0x0c07c2b4u: goto P_0c07c2b4;
case 0x0c07c2d0u: goto P_0c07c2d0;
case 0x0c07c2d2u: goto P_0c07c2d2;
case 0x0c07c2d4u: goto P_0c07c2d4;
case 0x0c07c2d6u: goto P_0c07c2d6;
case 0x0c07c2d8u: goto P_0c07c2d8;
case 0x0c07c2dau: goto P_0c07c2da;
case 0x0c07c2dcu: goto P_0c07c2dc;
case 0x0c07c2deu: goto P_0c07c2de;
case 0x0c07c2e0u: goto P_0c07c2e0;
case 0x0c07c2e2u: goto P_0c07c2e2;
case 0x0c07c2e4u: goto P_0c07c2e4;
case 0x0c07c2e6u: goto P_0c07c2e6;
case 0x0c07c2e8u: goto P_0c07c2e8;
case 0x0c07c2eau: goto P_0c07c2ea;
case 0x0c07c2ecu: goto P_0c07c2ec;
case 0x0c07c2eeu: goto P_0c07c2ee;
case 0x0c07c2f0u: goto P_0c07c2f0;
case 0x0c07c2f2u: goto P_0c07c2f2;
case 0x0c07c2f4u: goto P_0c07c2f4;
case 0x0c07c2f6u: goto P_0c07c2f6;
case 0x0c07c2f8u: goto P_0c07c2f8;
case 0x0c07c2fau: goto P_0c07c2fa;
case 0x0c07c2fcu: goto P_0c07c2fc;
case 0x0c07c2feu: goto P_0c07c2fe;
case 0x0c07c300u: goto P_0c07c300;
case 0x0c07c302u: goto P_0c07c302;
case 0x0c07c304u: goto P_0c07c304;
case 0x0c07c306u: goto P_0c07c306;
case 0x0c07c308u: goto P_0c07c308;
case 0x0c07c30au: goto P_0c07c30a;
case 0x0c07c30cu: goto P_0c07c30c;
case 0x0c07c30eu: goto P_0c07c30e;
case 0x0c07c310u: goto P_0c07c310;
case 0x0c07c312u: goto P_0c07c312;
case 0x0c07c314u: goto P_0c07c314;
case 0x0c07c316u: goto P_0c07c316;
case 0x0c07c318u: goto P_0c07c318;
case 0x0c07c31au: goto P_0c07c31a;
case 0x0c07c31cu: goto P_0c07c31c;
case 0x0c07c31eu: goto P_0c07c31e;
case 0x0c07c320u: goto P_0c07c320;
case 0x0c07c322u: goto P_0c07c322;
case 0x0c07c324u: goto P_0c07c324;
case 0x0c07c326u: goto P_0c07c326;
case 0x0c07c328u: goto P_0c07c328;
case 0x0c07c32au: goto P_0c07c32a;
case 0x0c07c32cu: goto P_0c07c32c;
case 0x0c07c32eu: goto P_0c07c32e;
case 0x0c07c330u: goto P_0c07c330;
case 0x0c07c332u: goto P_0c07c332;
case 0x0c07c722u: goto P_0c07c722;
case 0x0c07c724u: goto P_0c07c724;
case 0x0c07c726u: goto P_0c07c726;
case 0x0c07c728u: goto P_0c07c728;
case 0x0c07c72au: goto P_0c07c72a;
case 0x0c07c72cu: goto P_0c07c72c;
case 0x0c07c72eu: goto P_0c07c72e;
case 0x0c07c730u: goto P_0c07c730;
case 0x0c07c732u: goto P_0c07c732;
case 0x0c07c734u: goto P_0c07c734;
case 0x0c07c736u: goto P_0c07c736;
case 0x0c07c738u: goto P_0c07c738;
case 0x0c07c73au: goto P_0c07c73a;
case 0x0c07c73cu: goto P_0c07c73c;
case 0x0c07c73eu: goto P_0c07c73e;
case 0x0c07c740u: goto P_0c07c740;
case 0x0c07c742u: goto P_0c07c742;
case 0x0c07c744u: goto P_0c07c744;
case 0x0c07c746u: goto P_0c07c746;
case 0x0c07c748u: goto P_0c07c748;
case 0x0c07c74au: goto P_0c07c74a;
case 0x0c07c74cu: goto P_0c07c74c;
case 0x0c07c74eu: goto P_0c07c74e;
case 0x0c07c750u: goto P_0c07c750;
case 0x0c07c752u: goto P_0c07c752;
case 0x0c07c754u: goto P_0c07c754;
case 0x0c07c756u: goto P_0c07c756;
case 0x0c07c758u: goto P_0c07c758;
case 0x0c07c75au: goto P_0c07c75a;
case 0x0c07c75cu: goto P_0c07c75c;
case 0x0c07c75eu: goto P_0c07c75e;
case 0x0c07c760u: goto P_0c07c760;
case 0x0c07c762u: goto P_0c07c762;
case 0x0c07c764u: goto P_0c07c764;
case 0x0c07c766u: goto P_0c07c766;
case 0x0c07c768u: goto P_0c07c768;
case 0x0c07c76au: goto P_0c07c76a;
case 0x0c07c76cu: goto P_0c07c76c;
case 0x0c07c76eu: goto P_0c07c76e;
case 0x0c07c770u: goto P_0c07c770;
case 0x0c07ca2au: goto P_0c07ca2a;
case 0x0c07ca2cu: goto P_0c07ca2c;
case 0x0c07ca2eu: goto P_0c07ca2e;
case 0x0c07ca30u: goto P_0c07ca30;
case 0x0c07ca32u: goto P_0c07ca32;
case 0x0c07ca34u: goto P_0c07ca34;
case 0x0c07ca36u: goto P_0c07ca36;
case 0x0c07ca38u: goto P_0c07ca38;
case 0x0c07ca3au: goto P_0c07ca3a;
case 0x0c07ca3cu: goto P_0c07ca3c;
case 0x0c07ca3eu: goto P_0c07ca3e;
case 0x0c07ca40u: goto P_0c07ca40;
case 0x0c07ca42u: goto P_0c07ca42;
case 0x0c07ca44u: goto P_0c07ca44;
case 0x0c07ca46u: goto P_0c07ca46;
case 0x0c07ca48u: goto P_0c07ca48;
case 0x0c07ca4au: goto P_0c07ca4a;
case 0x0c07ca4cu: goto P_0c07ca4c;
case 0x0c07ca4eu: goto P_0c07ca4e;
case 0x0c07ca50u: goto P_0c07ca50;
case 0x0c07ca52u: goto P_0c07ca52;
case 0x0c07ca54u: goto P_0c07ca54;
case 0x0c07ca56u: goto P_0c07ca56;
case 0x0c07ca58u: goto P_0c07ca58;
case 0x0c07ca5au: goto P_0c07ca5a;
case 0x0c07ca5cu: goto P_0c07ca5c;
case 0x0c07ca5eu: goto P_0c07ca5e;
case 0x0c07e1cau: goto P_0c07e1ca;
case 0x0c07e1ccu: goto P_0c07e1cc;
case 0x0c07e1ceu: goto P_0c07e1ce;
case 0x0c07e1d0u: goto P_0c07e1d0;
case 0x0c07e1d2u: goto P_0c07e1d2;
case 0x0c07e1d4u: goto P_0c07e1d4;
case 0x0c07e1d6u: goto P_0c07e1d6;
case 0x0c07e1d8u: goto P_0c07e1d8;
case 0x0c07e1dau: goto P_0c07e1da;
case 0x0c07e1dcu: goto P_0c07e1dc;
case 0x0c07e1deu: goto P_0c07e1de;
case 0x0c07e1e0u: goto P_0c07e1e0;
case 0x0c07e1e2u: goto P_0c07e1e2;
case 0x0c07e1e4u: goto P_0c07e1e4;
case 0x0c07e1e6u: goto P_0c07e1e6;
case 0x0c07e1e8u: goto P_0c07e1e8;
case 0x0c07e1eau: goto P_0c07e1ea;
case 0x0c07e1ecu: goto P_0c07e1ec;
case 0x0c07e1eeu: goto P_0c07e1ee;
case 0x0c07e1f0u: goto P_0c07e1f0;
case 0x0c07e1f2u: goto P_0c07e1f2;
case 0x0c07e1f4u: goto P_0c07e1f4;
case 0x0c07e1f6u: goto P_0c07e1f6;
case 0x0c07e1f8u: goto P_0c07e1f8;
case 0x0c07e1fau: goto P_0c07e1fa;
case 0x0c07e1fcu: goto P_0c07e1fc;
case 0x0c07e1feu: goto P_0c07e1fe;
case 0x0c07e200u: goto P_0c07e200;
case 0x0c07e202u: goto P_0c07e202;
case 0x0c07e204u: goto P_0c07e204;
case 0x0c07e206u: goto P_0c07e206;
case 0x0c07e208u: goto P_0c07e208;
case 0x0c07e20au: goto P_0c07e20a;
case 0x0c07e20cu: goto P_0c07e20c;
case 0x0c07e20eu: goto P_0c07e20e;
case 0x0c07e210u: goto P_0c07e210;
case 0x0c07e212u: goto P_0c07e212;
case 0x0c07e214u: goto P_0c07e214;
case 0x0c07e216u: goto P_0c07e216;
case 0x0c07e218u: goto P_0c07e218;
case 0x0c07e21au: goto P_0c07e21a;
case 0x0c07e21cu: goto P_0c07e21c;
case 0x0c07e21eu: goto P_0c07e21e;
case 0x0c07e220u: goto P_0c07e220;
case 0x0c07eba8u: goto P_0c07eba8;
case 0x0c07ebaau: goto P_0c07ebaa;
case 0x0c07ebacu: goto P_0c07ebac;
case 0x0c07ebaeu: goto P_0c07ebae;
case 0x0c07ebb0u: goto P_0c07ebb0;
case 0x0c07ebb2u: goto P_0c07ebb2;
case 0x0c07ebb4u: goto P_0c07ebb4;
case 0x0c07ebb6u: goto P_0c07ebb6;
case 0x0c07ebb8u: goto P_0c07ebb8;
case 0x0c07ebbau: goto P_0c07ebba;
case 0x0c07ebbcu: goto P_0c07ebbc;
case 0x0c07ebbeu: goto P_0c07ebbe;
case 0x0c07ebc0u: goto P_0c07ebc0;
case 0x0c07ebc2u: goto P_0c07ebc2;
case 0x0c07ebc4u: goto P_0c07ebc4;
case 0x0c07ebc6u: goto P_0c07ebc6;
case 0x0c07ebc8u: goto P_0c07ebc8;
case 0x0c07ebcau: goto P_0c07ebca;
case 0x0c07ebccu: goto P_0c07ebcc;
case 0x0c07ebceu: goto P_0c07ebce;
case 0x0c07ebd0u: goto P_0c07ebd0;
case 0x0c07ebd2u: goto P_0c07ebd2;
case 0x0c07ebd4u: goto P_0c07ebd4;
case 0x0c07ebd6u: goto P_0c07ebd6;
case 0x0c07ebd8u: goto P_0c07ebd8;
case 0x0c07ebdau: goto P_0c07ebda;
case 0x0c07ebdcu: goto P_0c07ebdc;
case 0x0c07ebdeu: goto P_0c07ebde;
case 0x0c07ebe0u: goto P_0c07ebe0;
case 0x0c07ebe2u: goto P_0c07ebe2;
case 0x0c07ebe4u: goto P_0c07ebe4;
case 0x0c07ebe6u: goto P_0c07ebe6;
case 0x0c07ebe8u: goto P_0c07ebe8;
case 0x0c07ebeau: goto P_0c07ebea;
case 0x0c07ebecu: goto P_0c07ebec;
case 0x0c07ebeeu: goto P_0c07ebee;
case 0x0c07ebf0u: goto P_0c07ebf0;
case 0x0c07ebf2u: goto P_0c07ebf2;
case 0x0c07ebf4u: goto P_0c07ebf4;
case 0x0c07ebf6u: goto P_0c07ebf6;
case 0x0c07ebf8u: goto P_0c07ebf8;
case 0x0c07ebfau: goto P_0c07ebfa;
case 0x0c07ebfcu: goto P_0c07ebfc;
case 0x0c07ebfeu: goto P_0c07ebfe;
case 0x0c07ec00u: goto P_0c07ec00;
case 0x0c07ec40u: goto P_0c07ec40;
case 0x0c07ec42u: goto P_0c07ec42;
case 0x0c07ec44u: goto P_0c07ec44;
case 0x0c07ec46u: goto P_0c07ec46;
case 0x0c07ec48u: goto P_0c07ec48;
case 0x0c07ec4au: goto P_0c07ec4a;
case 0x0c07ec4cu: goto P_0c07ec4c;
case 0x0c07ec4eu: goto P_0c07ec4e;
case 0x0c07ec50u: goto P_0c07ec50;
case 0x0c07ec52u: goto P_0c07ec52;
case 0x0c07ec54u: goto P_0c07ec54;
case 0x0c07ec56u: goto P_0c07ec56;
case 0x0c07ec58u: goto P_0c07ec58;
case 0x0c07ec5au: goto P_0c07ec5a;
case 0x0c07ec5cu: goto P_0c07ec5c;
case 0x0c07ec5eu: goto P_0c07ec5e;
case 0x0c07ec60u: goto P_0c07ec60;
case 0x0c07ec62u: goto P_0c07ec62;
case 0x0c07ec64u: goto P_0c07ec64;
case 0x0c07ec66u: goto P_0c07ec66;
case 0x0c07ec68u: goto P_0c07ec68;
case 0x0c07ec6au: goto P_0c07ec6a;
case 0x0c07ec6cu: goto P_0c07ec6c;
case 0x0c07ec6eu: goto P_0c07ec6e;
case 0x0c07ec70u: goto P_0c07ec70;
case 0x0c07ec72u: goto P_0c07ec72;
case 0x0c07ec74u: goto P_0c07ec74;
case 0x0c07ec76u: goto P_0c07ec76;
case 0x0c07ec78u: goto P_0c07ec78;
case 0x0c07ec7au: goto P_0c07ec7a;
case 0x0c07ec7cu: goto P_0c07ec7c;
case 0x0c07ec7eu: goto P_0c07ec7e;
case 0x0c07ec80u: goto P_0c07ec80;
case 0x0c07ec82u: goto P_0c07ec82;
case 0x0c07ec84u: goto P_0c07ec84;
case 0x0c07ec86u: goto P_0c07ec86;
case 0x0c07ec88u: goto P_0c07ec88;
case 0x0c07ec8au: goto P_0c07ec8a;
case 0x0c07ec8cu: goto P_0c07ec8c;
case 0x0c07ec8eu: goto P_0c07ec8e;
case 0x0c07ec90u: goto P_0c07ec90;
case 0x0c07ec92u: goto P_0c07ec92;
case 0x0c07ec94u: goto P_0c07ec94;
case 0x0c07ec96u: goto P_0c07ec96;
case 0x0c07ec98u: goto P_0c07ec98;
case 0x0c07ec9au: goto P_0c07ec9a;
case 0x0c07ec9cu: goto P_0c07ec9c;
case 0x0c07ec9eu: goto P_0c07ec9e;
case 0x0c07eca0u: goto P_0c07eca0;
case 0x0c07eca2u: goto P_0c07eca2;
case 0x0c07eca4u: goto P_0c07eca4;
case 0x0c07eca6u: goto P_0c07eca6;
case 0x0c07eca8u: goto P_0c07eca8;
case 0x0c07ecaau: goto P_0c07ecaa;
case 0x0c07ecacu: goto P_0c07ecac;
case 0x0c07ecaeu: goto P_0c07ecae;
case 0x0c07ecb0u: goto P_0c07ecb0;
case 0x0c07ecb2u: goto P_0c07ecb2;
case 0x0c07ecb4u: goto P_0c07ecb4;
case 0x0c07ecb6u: goto P_0c07ecb6;
case 0x0c07ecb8u: goto P_0c07ecb8;
case 0x0c07ecbau: goto P_0c07ecba;
case 0x0c07ecbcu: goto P_0c07ecbc;
case 0x0c07ecbeu: goto P_0c07ecbe;
case 0x0c07ecc0u: goto P_0c07ecc0;
case 0x0c07ecc2u: goto P_0c07ecc2;
case 0x0c07ecc4u: goto P_0c07ecc4;
case 0x0c07ecc6u: goto P_0c07ecc6;
case 0x0c07ecc8u: goto P_0c07ecc8;
case 0x0c07eccau: goto P_0c07ecca;
case 0x0c07ecccu: goto P_0c07eccc;
case 0x0c07ecceu: goto P_0c07ecce;
case 0x0c07ecd0u: goto P_0c07ecd0;
case 0x0c07ecd2u: goto P_0c07ecd2;
case 0x0c07ecd4u: goto P_0c07ecd4;
case 0x0c07ecd6u: goto P_0c07ecd6;
case 0x0c07ecd8u: goto P_0c07ecd8;
case 0x0c07ecdau: goto P_0c07ecda;
case 0x0c07ecdcu: goto P_0c07ecdc;
case 0x0c07ecdeu: goto P_0c07ecde;
case 0x0c07ece0u: goto P_0c07ece0;
case 0x0c07ece2u: goto P_0c07ece2;
case 0x0c07ece4u: goto P_0c07ece4;
case 0x0c07ece6u: goto P_0c07ece6;
case 0x0c07ece8u: goto P_0c07ece8;
case 0x0c07eceau: goto P_0c07ecea;
case 0x0c07ececu: goto P_0c07ecec;
case 0x0c07eceeu: goto P_0c07ecee;
case 0x0c07ecf0u: goto P_0c07ecf0;
case 0x0c07ecf2u: goto P_0c07ecf2;
case 0x0c07ecf4u: goto P_0c07ecf4;
case 0x0c07ecf6u: goto P_0c07ecf6;
case 0x0c07ecf8u: goto P_0c07ecf8;
case 0x0c07ecfau: goto P_0c07ecfa;
case 0x0c07ecfcu: goto P_0c07ecfc;
case 0x0c07ecfeu: goto P_0c07ecfe;
case 0x0c07ed00u: goto P_0c07ed00;
case 0x0c07ed02u: goto P_0c07ed02;
case 0x0c07ed04u: goto P_0c07ed04;
case 0x0c07ed06u: goto P_0c07ed06;
case 0x0c07ed08u: goto P_0c07ed08;
case 0x0c07ed0au: goto P_0c07ed0a;
case 0x0c07ed0cu: goto P_0c07ed0c;
case 0x0c07ed0eu: goto P_0c07ed0e;
case 0x0c07ed10u: goto P_0c07ed10;
case 0x0c07ed12u: goto P_0c07ed12;
case 0x0c07ed14u: goto P_0c07ed14;
case 0x0c07ed16u: goto P_0c07ed16;
case 0x0c07ed18u: goto P_0c07ed18;
case 0x0c07ed1au: goto P_0c07ed1a;
case 0x0c07ed1cu: goto P_0c07ed1c;
case 0x0c07ed1eu: goto P_0c07ed1e;
case 0x0c07ed20u: goto P_0c07ed20;
case 0x0c07ed58u: goto P_0c07ed58;
case 0x0c07ed5au: goto P_0c07ed5a;
case 0x0c07ed5cu: goto P_0c07ed5c;
case 0x0c07ed5eu: goto P_0c07ed5e;
case 0x0c07ed60u: goto P_0c07ed60;
case 0x0c07ed62u: goto P_0c07ed62;
case 0x0c07ed64u: goto P_0c07ed64;
case 0x0c07ed66u: goto P_0c07ed66;
case 0x0c07ed68u: goto P_0c07ed68;
case 0x0c07ed6au: goto P_0c07ed6a;
case 0x0c07ed6cu: goto P_0c07ed6c;
case 0x0c07ed6eu: goto P_0c07ed6e;
case 0x0c07ed70u: goto P_0c07ed70;
case 0x0c07ed72u: goto P_0c07ed72;
case 0x0c07ed74u: goto P_0c07ed74;
case 0x0c07ed76u: goto P_0c07ed76;
case 0x0c07ed78u: goto P_0c07ed78;
case 0x0c07ed7au: goto P_0c07ed7a;
case 0x0c07ed7cu: goto P_0c07ed7c;
case 0x0c07ed7eu: goto P_0c07ed7e;
case 0x0c07ed80u: goto P_0c07ed80;
case 0x0c07ed82u: goto P_0c07ed82;
case 0x0c07ed84u: goto P_0c07ed84;
case 0x0c07ed86u: goto P_0c07ed86;
case 0x0c07ed88u: goto P_0c07ed88;
case 0x0c07ed8au: goto P_0c07ed8a;
case 0x0c07ed8cu: goto P_0c07ed8c;
case 0x0c07ed8eu: goto P_0c07ed8e;
case 0x0c07ed90u: goto P_0c07ed90;
case 0x0c07ed92u: goto P_0c07ed92;
case 0x0c07ed94u: goto P_0c07ed94;
case 0x0c07ed96u: goto P_0c07ed96;
case 0x0c07ed98u: goto P_0c07ed98;
case 0x0c07ed9au: goto P_0c07ed9a;
case 0x0c07ed9cu: goto P_0c07ed9c;
case 0x0c07ed9eu: goto P_0c07ed9e;
case 0x0c07eda0u: goto P_0c07eda0;
case 0x0c07eda2u: goto P_0c07eda2;
case 0x0c07eda4u: goto P_0c07eda4;
case 0x0c07eda6u: goto P_0c07eda6;
case 0x0c07eda8u: goto P_0c07eda8;
case 0x0c07edaau: goto P_0c07edaa;
case 0x0c07edacu: goto P_0c07edac;
case 0x0c07edaeu: goto P_0c07edae;
case 0x0c07edb0u: goto P_0c07edb0;
case 0x0c07edb2u: goto P_0c07edb2;
case 0x0c07edb4u: goto P_0c07edb4;
case 0x0c07edb6u: goto P_0c07edb6;
case 0x0c07edb8u: goto P_0c07edb8;
case 0x0c07edbau: goto P_0c07edba;
case 0x0c07edbcu: goto P_0c07edbc;
case 0x0c07edbeu: goto P_0c07edbe;
case 0x0c07edc0u: goto P_0c07edc0;
case 0x0c07edc2u: goto P_0c07edc2;
case 0x0c07edc4u: goto P_0c07edc4;
case 0x0c07edc6u: goto P_0c07edc6;
case 0x0c07edc8u: goto P_0c07edc8;
case 0x0c07edcau: goto P_0c07edca;
case 0x0c07edccu: goto P_0c07edcc;
case 0x0c07edceu: goto P_0c07edce;
case 0x0c07edd0u: goto P_0c07edd0;
case 0x0c07edd2u: goto P_0c07edd2;
case 0x0c07edd4u: goto P_0c07edd4;
case 0x0c07edd6u: goto P_0c07edd6;
case 0x0c07edd8u: goto P_0c07edd8;
case 0x0c07eddau: goto P_0c07edda;
case 0x0c07eddcu: goto P_0c07eddc;
case 0x0c07eddeu: goto P_0c07edde;
case 0x0c07ede0u: goto P_0c07ede0;
case 0x0c07ede2u: goto P_0c07ede2;
case 0x0c07ede4u: goto P_0c07ede4;
case 0x0c07ede6u: goto P_0c07ede6;
case 0x0c07ede8u: goto P_0c07ede8;
case 0x0c07edeau: goto P_0c07edea;
case 0x0c07edecu: goto P_0c07edec;
case 0x0c07edeeu: goto P_0c07edee;
case 0x0c07edf0u: goto P_0c07edf0;
case 0x0c07edf2u: goto P_0c07edf2;
case 0x0c07edf4u: goto P_0c07edf4;
case 0x0c07edf6u: goto P_0c07edf6;
case 0x0c07edf8u: goto P_0c07edf8;
case 0x0c07edfau: goto P_0c07edfa;
case 0x0c07edfcu: goto P_0c07edfc;
case 0x0c07edfeu: goto P_0c07edfe;
case 0x0c07ee00u: goto P_0c07ee00;
case 0x0c07ee02u: goto P_0c07ee02;
case 0x0c07ee04u: goto P_0c07ee04;
case 0x0c07ee06u: goto P_0c07ee06;
case 0x0c07ee08u: goto P_0c07ee08;
case 0x0c07ee0au: goto P_0c07ee0a;
case 0x0c07ee0cu: goto P_0c07ee0c;
case 0x0c07ee0eu: goto P_0c07ee0e;
case 0x0c07ee10u: goto P_0c07ee10;
case 0x0c07ee12u: goto P_0c07ee12;
case 0x0c07ee14u: goto P_0c07ee14;
case 0x0c07ee16u: goto P_0c07ee16;
case 0x0c07ee18u: goto P_0c07ee18;
case 0x0c07ee1au: goto P_0c07ee1a;
case 0x0c07ee1cu: goto P_0c07ee1c;
case 0x0c07ee1eu: goto P_0c07ee1e;
case 0x0c07ee20u: goto P_0c07ee20;
case 0x0c07ee22u: goto P_0c07ee22;
case 0x0c07ee24u: goto P_0c07ee24;
case 0x0c07ee26u: goto P_0c07ee26;
case 0x0c07ee28u: goto P_0c07ee28;
case 0x0c07ee2au: goto P_0c07ee2a;
case 0x0c07ee2cu: goto P_0c07ee2c;
case 0x0c07ee2eu: goto P_0c07ee2e;
case 0x0c07ee30u: goto P_0c07ee30;
case 0x0c07ee32u: goto P_0c07ee32;
case 0x0c080266u: goto P_0c080266;
case 0x0c080268u: goto P_0c080268;
case 0x0c08026au: goto P_0c08026a;
case 0x0c08026cu: goto P_0c08026c;
case 0x0c08026eu: goto P_0c08026e;
case 0x0c080270u: goto P_0c080270;
case 0x0c080272u: goto P_0c080272;
case 0x0c080274u: goto P_0c080274;
case 0x0c080276u: goto P_0c080276;
case 0x0c080278u: goto P_0c080278;
case 0x0c08027au: goto P_0c08027a;
case 0x0c08027cu: goto P_0c08027c;
case 0x0c08027eu: goto P_0c08027e;
case 0x0c080280u: goto P_0c080280;
case 0x0c080282u: goto P_0c080282;
case 0x0c080284u: goto P_0c080284;
case 0x0c080286u: goto P_0c080286;
case 0x0c080288u: goto P_0c080288;
case 0x0c08028au: goto P_0c08028a;
case 0x0c08439eu: goto P_0c08439e;
case 0x0c0843a0u: goto P_0c0843a0;
case 0x0c0843a2u: goto P_0c0843a2;
case 0x0c0843a4u: goto P_0c0843a4;
case 0x0c0843a6u: goto P_0c0843a6;
case 0x0c0843a8u: goto P_0c0843a8;
case 0x0c0843aau: goto P_0c0843aa;
case 0x0c0843acu: goto P_0c0843ac;
case 0x0c0843aeu: goto P_0c0843ae;
case 0x0c0843b0u: goto P_0c0843b0;
case 0x0c0843b2u: goto P_0c0843b2;
case 0x0c0843b4u: goto P_0c0843b4;
case 0x0c0843b6u: goto P_0c0843b6;
case 0x0c0843b8u: goto P_0c0843b8;
case 0x0c0843bau: goto P_0c0843ba;
case 0x0c0843bcu: goto P_0c0843bc;
case 0x0c0843beu: goto P_0c0843be;
case 0x0c0843c0u: goto P_0c0843c0;
case 0x0c0843c2u: goto P_0c0843c2;
case 0x0c0843c4u: goto P_0c0843c4;
case 0x0c0843c6u: goto P_0c0843c6;
case 0x0c0843c8u: goto P_0c0843c8;
case 0x0c0843cau: goto P_0c0843ca;
case 0x0c0843ccu: goto P_0c0843cc;
case 0x0c0843ceu: goto P_0c0843ce;
case 0x0c0843d0u: goto P_0c0843d0;
case 0x0c0843d2u: goto P_0c0843d2;
case 0x0c0843d4u: goto P_0c0843d4;
case 0x0c0968d0u: goto P_0c0968d0;
case 0x0c0968d2u: goto P_0c0968d2;
case 0x0c0968d4u: goto P_0c0968d4;
case 0x0c0968d6u: goto P_0c0968d6;
case 0x0c0968d8u: goto P_0c0968d8;
case 0x0c0968dau: goto P_0c0968da;
case 0x0c0968dcu: goto P_0c0968dc;
case 0x0c0968deu: goto P_0c0968de;
case 0x0c0968e0u: goto P_0c0968e0;
case 0x0c0968e2u: goto P_0c0968e2;
case 0x0c0968e4u: goto P_0c0968e4;
case 0x0c0968e6u: goto P_0c0968e6;
case 0x0c0968e8u: goto P_0c0968e8;
case 0x0c0968eau: goto P_0c0968ea;
case 0x0c0968ecu: goto P_0c0968ec;
case 0x0c0968eeu: goto P_0c0968ee;
case 0x0c0968f0u: goto P_0c0968f0;
case 0x0c0968f2u: goto P_0c0968f2;
case 0x0c0968f4u: goto P_0c0968f4;
case 0x0c0968f6u: goto P_0c0968f6;
case 0x0c096d5eu: goto P_0c096d5e;
case 0x0c096d60u: goto P_0c096d60;
case 0x0c096d62u: goto P_0c096d62;
case 0x0c096d64u: goto P_0c096d64;
case 0x0c096d66u: goto P_0c096d66;
case 0x0c096d68u: goto P_0c096d68;
case 0x0c096d6au: goto P_0c096d6a;
case 0x0c096d6cu: goto P_0c096d6c;
case 0x0c096d6eu: goto P_0c096d6e;
case 0x0c096d70u: goto P_0c096d70;
case 0x0c096d72u: goto P_0c096d72;
case 0x0c096d74u: goto P_0c096d74;
case 0x0c096d76u: goto P_0c096d76;
case 0x0c096d78u: goto P_0c096d78;
case 0x0c096d7au: goto P_0c096d7a;
case 0x0c096d7cu: goto P_0c096d7c;
case 0x0c096d7eu: goto P_0c096d7e;
case 0x0c096d80u: goto P_0c096d80;
case 0x0c096d82u: goto P_0c096d82;
case 0x0c096d84u: goto P_0c096d84;
case 0x0c096d86u: goto P_0c096d86;
case 0x0c096d88u: goto P_0c096d88;
case 0x0c096d8au: goto P_0c096d8a;
case 0x0c096d8cu: goto P_0c096d8c;
case 0x0c096d8eu: goto P_0c096d8e;
case 0x0c096d90u: goto P_0c096d90;
case 0x0c096d92u: goto P_0c096d92;
case 0x0c096d94u: goto P_0c096d94;
case 0x0c096d96u: goto P_0c096d96;
case 0x0c096d98u: goto P_0c096d98;
case 0x0c096d9au: goto P_0c096d9a;
case 0x0c096d9cu: goto P_0c096d9c;
case 0x0c096d9eu: goto P_0c096d9e;
case 0x0c096da0u: goto P_0c096da0;
case 0x0c096da2u: goto P_0c096da2;
case 0x0c096da4u: goto P_0c096da4;
case 0x0c096da6u: goto P_0c096da6;
case 0x0c096da8u: goto P_0c096da8;
case 0x0c096daau: goto P_0c096daa;
case 0x0c096dacu: goto P_0c096dac;
case 0x0c096daeu: goto P_0c096dae;
case 0x0c096db0u: goto P_0c096db0;
case 0x0c096db2u: goto P_0c096db2;
case 0x0c096db4u: goto P_0c096db4;
case 0x0c096db6u: goto P_0c096db6;
case 0x0c096db8u: goto P_0c096db8;
case 0x0c096dbau: goto P_0c096dba;
case 0x0c096dbcu: goto P_0c096dbc;
case 0x0c096dbeu: goto P_0c096dbe;
case 0x0c096f9au: goto P_0c096f9a;
case 0x0c096f9cu: goto P_0c096f9c;
case 0x0c096f9eu: goto P_0c096f9e;
case 0x0c096fa0u: goto P_0c096fa0;
case 0x0c096fa2u: goto P_0c096fa2;
case 0x0c096fa4u: goto P_0c096fa4;
case 0x0c096fa6u: goto P_0c096fa6;
case 0x0c096fa8u: goto P_0c096fa8;
case 0x0c096faau: goto P_0c096faa;
case 0x0c096facu: goto P_0c096fac;
case 0x0c096faeu: goto P_0c096fae;
case 0x0c096fb0u: goto P_0c096fb0;
case 0x0c096fb2u: goto P_0c096fb2;
case 0x0c096fb4u: goto P_0c096fb4;
case 0x0c096fb6u: goto P_0c096fb6;
case 0x0c096fb8u: goto P_0c096fb8;
case 0x0c096fbau: goto P_0c096fba;
case 0x0c096fbcu: goto P_0c096fbc;
case 0x0c096fbeu: goto P_0c096fbe;
case 0x0c096fc0u: goto P_0c096fc0;
case 0x0c096fc2u: goto P_0c096fc2;
case 0x0c096fc4u: goto P_0c096fc4;
case 0x0c096fc6u: goto P_0c096fc6;
case 0x0c096fc8u: goto P_0c096fc8;
case 0x0c096fcau: goto P_0c096fca;
case 0x0c096fccu: goto P_0c096fcc;
case 0x0c096fceu: goto P_0c096fce;
case 0x0c096fd0u: goto P_0c096fd0;
case 0x0c096fd2u: goto P_0c096fd2;
case 0x0c096fd4u: goto P_0c096fd4;
case 0x0c096fd6u: goto P_0c096fd6;
case 0x0c096fd8u: goto P_0c096fd8;
case 0x0c096fdau: goto P_0c096fda;
case 0x0c096fdcu: goto P_0c096fdc;
case 0x0c096fdeu: goto P_0c096fde;
case 0x0c096fe0u: goto P_0c096fe0;
case 0x0c096fe2u: goto P_0c096fe2;
case 0x0c096fe4u: goto P_0c096fe4;
case 0x0c096fe6u: goto P_0c096fe6;
case 0x0c097942u: goto P_0c097942;
case 0x0c097944u: goto P_0c097944;
case 0x0c097946u: goto P_0c097946;
case 0x0c097948u: goto P_0c097948;
case 0x0c09794au: goto P_0c09794a;
case 0x0c09794cu: goto P_0c09794c;
case 0x0c09794eu: goto P_0c09794e;
case 0x0c097950u: goto P_0c097950;
case 0x0c097952u: goto P_0c097952;
case 0x0c097954u: goto P_0c097954;
case 0x0c097956u: goto P_0c097956;
case 0x0c097958u: goto P_0c097958;
case 0x0c09795au: goto P_0c09795a;
case 0x0c09795cu: goto P_0c09795c;
case 0x0c09795eu: goto P_0c09795e;
case 0x0c097960u: goto P_0c097960;
case 0x0c097962u: goto P_0c097962;
case 0x0c097964u: goto P_0c097964;
case 0x0c097966u: goto P_0c097966;
case 0x0c097968u: goto P_0c097968;
case 0x0c09796au: goto P_0c09796a;
case 0x0c09796cu: goto P_0c09796c;
case 0x0c09796eu: goto P_0c09796e;
case 0x0c097970u: goto P_0c097970;
case 0x0c097972u: goto P_0c097972;
case 0x0c097974u: goto P_0c097974;
case 0x0c097976u: goto P_0c097976;
case 0x0c097978u: goto P_0c097978;
case 0x0c09797au: goto P_0c09797a;
case 0x0c09797cu: goto P_0c09797c;
case 0x0c09797eu: goto P_0c09797e;
case 0x0c097980u: goto P_0c097980;
case 0x0c097982u: goto P_0c097982;
case 0x0c097984u: goto P_0c097984;
case 0x0c097986u: goto P_0c097986;
case 0x0c097988u: goto P_0c097988;
case 0x0c09798au: goto P_0c09798a;
case 0x0c09798cu: goto P_0c09798c;
case 0x0c09798eu: goto P_0c09798e;
case 0x0c097990u: goto P_0c097990;
case 0x0c097992u: goto P_0c097992;
case 0x0c097994u: goto P_0c097994;
case 0x0c097996u: goto P_0c097996;
case 0x0c097998u: goto P_0c097998;
case 0x0c09799au: goto P_0c09799a;
case 0x0c09799cu: goto P_0c09799c;
case 0x0c09799eu: goto P_0c09799e;
case 0x0c0979a0u: goto P_0c0979a0;
case 0x0c0979a2u: goto P_0c0979a2;
case 0x0c0979a4u: goto P_0c0979a4;
case 0x0c0979a6u: goto P_0c0979a6;
case 0x0c0979a8u: goto P_0c0979a8;
case 0x0c0979aau: goto P_0c0979aa;
case 0x0c0979acu: goto P_0c0979ac;
case 0x0c0a12d2u: goto P_0c0a12d2;
case 0x0c0a12d4u: goto P_0c0a12d4;
case 0x0c0a12d6u: goto P_0c0a12d6;
case 0x0c0a12d8u: goto P_0c0a12d8;
case 0x0c0a12dau: goto P_0c0a12da;
case 0x0c0a12dcu: goto P_0c0a12dc;
case 0x0c0a12deu: goto P_0c0a12de;
case 0x0c0a12e0u: goto P_0c0a12e0;
case 0x0c0a12e2u: goto P_0c0a12e2;
case 0x0c0a293au: goto P_0c0a293a;
case 0x0c0a293cu: goto P_0c0a293c;
case 0x0c0a293eu: goto P_0c0a293e;
case 0x0c0a2940u: goto P_0c0a2940;
case 0x0c0a2942u: goto P_0c0a2942;
case 0x0c0a2944u: goto P_0c0a2944;
case 0x0c0a2946u: goto P_0c0a2946;
case 0x0c0a2948u: goto P_0c0a2948;
case 0x0c0a294au: goto P_0c0a294a;
case 0x0c0a294cu: goto P_0c0a294c;
case 0x0c0a294eu: goto P_0c0a294e;
case 0x0c0a2950u: goto P_0c0a2950;
case 0x0c0a2952u: goto P_0c0a2952;
case 0x0c0a2954u: goto P_0c0a2954;
case 0x0c0a2956u: goto P_0c0a2956;
case 0x0c0a2958u: goto P_0c0a2958;
case 0x0c0a295au: goto P_0c0a295a;
case 0x0c0a295cu: goto P_0c0a295c;
case 0x0c0a7ba8u: goto P_0c0a7ba8;
case 0x0c0a7baau: goto P_0c0a7baa;
case 0x0c0a7bacu: goto P_0c0a7bac;
case 0x0c0a7baeu: goto P_0c0a7bae;
case 0x0c0a7bb0u: goto P_0c0a7bb0;
case 0x0c0a7bb2u: goto P_0c0a7bb2;
case 0x0c0a7bb4u: goto P_0c0a7bb4;
case 0x0c0a7bb6u: goto P_0c0a7bb6;
case 0x0c0a7bb8u: goto P_0c0a7bb8;
case 0x0c0a7bbau: goto P_0c0a7bba;
case 0x0c0a7bbcu: goto P_0c0a7bbc;
case 0x0c0a7bbeu: goto P_0c0a7bbe;
case 0x0c0a7bc0u: goto P_0c0a7bc0;
case 0x0c0a7bc2u: goto P_0c0a7bc2;
case 0x0c0a7bc4u: goto P_0c0a7bc4;
case 0x0c0a7bc6u: goto P_0c0a7bc6;
case 0x0c0a7bc8u: goto P_0c0a7bc8;
case 0x0c0a7bcau: goto P_0c0a7bca;
case 0x0c0a7bccu: goto P_0c0a7bcc;
case 0x0c0a7bceu: goto P_0c0a7bce;
case 0x0c0a7bd0u: goto P_0c0a7bd0;
case 0x0c0a7bd2u: goto P_0c0a7bd2;
case 0x0c0a7bd4u: goto P_0c0a7bd4;
case 0x0c0a7bd6u: goto P_0c0a7bd6;
case 0x0c0a7bd8u: goto P_0c0a7bd8;
case 0x0c0a7bdau: goto P_0c0a7bda;
case 0x0c0a7bdcu: goto P_0c0a7bdc;
case 0x0c0a7bdeu: goto P_0c0a7bde;
case 0x0c0a7be0u: goto P_0c0a7be0;
case 0x0c0a87aau: goto P_0c0a87aa;
case 0x0c0a87acu: goto P_0c0a87ac;
case 0x0c0a87aeu: goto P_0c0a87ae;
case 0x0c0a87b0u: goto P_0c0a87b0;
case 0x0c0a87b2u: goto P_0c0a87b2;
case 0x0c0a87b4u: goto P_0c0a87b4;
case 0x0c0a87b6u: goto P_0c0a87b6;
case 0x0c0a87b8u: goto P_0c0a87b8;
case 0x0c0a87bau: goto P_0c0a87ba;
case 0x0c0a87bcu: goto P_0c0a87bc;
case 0x0c0a87beu: goto P_0c0a87be;
case 0x0c0a87c0u: goto P_0c0a87c0;
case 0x0c0a87c2u: goto P_0c0a87c2;
case 0x0c0a87c4u: goto P_0c0a87c4;
case 0x0c0a87c6u: goto P_0c0a87c6;
case 0x0c0a87c8u: goto P_0c0a87c8;
case 0x0c0a87cau: goto P_0c0a87ca;
case 0x0c0a87ccu: goto P_0c0a87cc;
case 0x0c0a87ceu: goto P_0c0a87ce;
case 0x0c0a87d0u: goto P_0c0a87d0;
case 0x0c0a87d2u: goto P_0c0a87d2;
case 0x0c0a87d4u: goto P_0c0a87d4;
case 0x0c0a87d6u: goto P_0c0a87d6;
case 0x0c0a87d8u: goto P_0c0a87d8;
case 0x0c0a87dau: goto P_0c0a87da;
case 0x0c0a87dcu: goto P_0c0a87dc;
case 0x0c0a87deu: goto P_0c0a87de;
case 0x0c0a87e0u: goto P_0c0a87e0;
case 0x0c0a87e2u: goto P_0c0a87e2;
case 0x0c0a87e4u: goto P_0c0a87e4;
case 0x0c0a87e6u: goto P_0c0a87e6;
case 0x0c0a87e8u: goto P_0c0a87e8;
case 0x0c0c1a66u: goto P_0c0c1a66;
case 0x0c0c1a68u: goto P_0c0c1a68;
case 0x0c0c1a6au: goto P_0c0c1a6a;
case 0x0c0c1a6cu: goto P_0c0c1a6c;
case 0x0c0c1a6eu: goto P_0c0c1a6e;
case 0x0c0c1a70u: goto P_0c0c1a70;
case 0x0c0c1a72u: goto P_0c0c1a72;
case 0x0c0c1a74u: goto P_0c0c1a74;
case 0x0c0c1a76u: goto P_0c0c1a76;
case 0x0c0c1a78u: goto P_0c0c1a78;
case 0x0c0c1a7au: goto P_0c0c1a7a;
case 0x0c0c1a7cu: goto P_0c0c1a7c;
case 0x0c0c1a7eu: goto P_0c0c1a7e;
case 0x0c0c1a80u: goto P_0c0c1a80;
case 0x0c0c1a82u: goto P_0c0c1a82;
case 0x0c0c1a84u: goto P_0c0c1a84;
case 0x0c0c1a86u: goto P_0c0c1a86;
case 0x0c0c2d06u: goto P_0c0c2d06;
case 0x0c0c2d08u: goto P_0c0c2d08;
case 0x0c0c2d0au: goto P_0c0c2d0a;
case 0x0c0c2d0cu: goto P_0c0c2d0c;
case 0x0c0c2d0eu: goto P_0c0c2d0e;
case 0x0c0c74bcu: goto P_0c0c74bc;
case 0x0c0c74beu: goto P_0c0c74be;
case 0x0c0c74c0u: goto P_0c0c74c0;
case 0x0c0c74c2u: goto P_0c0c74c2;
case 0x0c0c74c4u: goto P_0c0c74c4;
case 0x0c0c74c6u: goto P_0c0c74c6;
case 0x0c0c74c8u: goto P_0c0c74c8;
case 0x0c0c74cau: goto P_0c0c74ca;
case 0x0c0c74ccu: goto P_0c0c74cc;
case 0x0c0c74ceu: goto P_0c0c74ce;
case 0x0c0c74d0u: goto P_0c0c74d0;
case 0x0c0c74d2u: goto P_0c0c74d2;
case 0x0c0c74d4u: goto P_0c0c74d4;
case 0x0c0c74d6u: goto P_0c0c74d6;
case 0x0c0c74d8u: goto P_0c0c74d8;
case 0x0c0c74dau: goto P_0c0c74da;
case 0x0c0c74dcu: goto P_0c0c74dc;
case 0x0c0c74deu: goto P_0c0c74de;
case 0x0c0c74e0u: goto P_0c0c74e0;
case 0x0c0c74e2u: goto P_0c0c74e2;
case 0x0c0c74e4u: goto P_0c0c74e4;
case 0x0c0c74e6u: goto P_0c0c74e6;
case 0x0c0c74e8u: goto P_0c0c74e8;
case 0x0c0c74eau: goto P_0c0c74ea;
case 0x0c0c74ecu: goto P_0c0c74ec;
case 0x0c0c74eeu: goto P_0c0c74ee;
case 0x0c0c74f0u: goto P_0c0c74f0;
case 0x0c0c74f2u: goto P_0c0c74f2;
case 0x0c0c74f4u: goto P_0c0c74f4;
case 0x0c0c74f6u: goto P_0c0c74f6;
case 0x0c0c74f8u: goto P_0c0c74f8;
case 0x0c0c74fau: goto P_0c0c74fa;
case 0x0c0c74fcu: goto P_0c0c74fc;
case 0x0c0c74feu: goto P_0c0c74fe;
case 0x0c0c7500u: goto P_0c0c7500;
case 0x0c0c7502u: goto P_0c0c7502;
case 0x0c0c7504u: goto P_0c0c7504;
case 0x0c0c7506u: goto P_0c0c7506;
case 0x0c0c7508u: goto P_0c0c7508;
case 0x0c0c750au: goto P_0c0c750a;
case 0x0c0c750cu: goto P_0c0c750c;
case 0x0c0c750eu: goto P_0c0c750e;
case 0x0c0c7510u: goto P_0c0c7510;
case 0x0c0c7512u: goto P_0c0c7512;
case 0x0c0c7514u: goto P_0c0c7514;
case 0x0c0c7516u: goto P_0c0c7516;
case 0x0c0c7518u: goto P_0c0c7518;
case 0x0c0c751au: goto P_0c0c751a;
case 0x0c0c751cu: goto P_0c0c751c;
case 0x0c0c751eu: goto P_0c0c751e;
case 0x0c0c7520u: goto P_0c0c7520;
case 0x0c0c7522u: goto P_0c0c7522;
case 0x0c0c7524u: goto P_0c0c7524;
case 0x0c0c7526u: goto P_0c0c7526;
case 0x0c0c7528u: goto P_0c0c7528;
case 0x0c0c752au: goto P_0c0c752a;
case 0x0c0c752cu: goto P_0c0c752c;
case 0x0c0c752eu: goto P_0c0c752e;
case 0x0c0c7530u: goto P_0c0c7530;
case 0x0c0c7532u: goto P_0c0c7532;
case 0x0c0c7534u: goto P_0c0c7534;
case 0x0c0c7536u: goto P_0c0c7536;
case 0x0c0c7538u: goto P_0c0c7538;
case 0x0c0c753au: goto P_0c0c753a;
case 0x0c0c753cu: goto P_0c0c753c;
case 0x0c0c753eu: goto P_0c0c753e;
case 0x0c0c7540u: goto P_0c0c7540;
case 0x0c0c7542u: goto P_0c0c7542;
default: return vf3_matrix_family(target,s,ram);
}
P_0c02eed8: /* original f00b, guest PC 0x0c02eed8 */
if(!s->budget--) { s->failed_pc=0x0c02eed8u; return 0; }
r[0]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[0]);
goto P_0c02eeda;
P_0c02eeda: /* original 02ee, guest PC 0x0c02eeda */
if(!s->budget--) { s->failed_pc=0x0c02eedau; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c02eedc;
P_0c02eedc: /* original 0b0c, guest PC 0x0c02eedc */
if(!s->budget--) { s->failed_pc=0x0c02eedcu; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c02eede;
P_0c02eede: /* original eee9, guest PC 0x0c02eede */
if(!s->budget--) { s->failed_pc=0x0c02eedeu; return 0; }
r[14]=0xffffffe9u;
goto P_0c02eee0;
P_0c02eee0: /* original 0c02, guest PC 0x0c02eee0 */
if(!s->budget--) { s->failed_pc=0x0c02eee0u; return 0; }
r[12]=r[17];
goto P_0c02eee2;
P_0c02eee2: /* original 1326, guest PC 0x0c02eee2 */
if(!s->budget--) { s->failed_pc=0x0c02eee2u; return 0; }
write(ram,r[3]+24,r[2],4);
goto P_0c02eee4;
P_0c02eee4: /* original 3b02, guest PC 0x0c02eee4 */
if(!s->budget--) { s->failed_pc=0x0c02eee4u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>=r[0])!=0);
goto P_0c02eee6;
P_0c02eee6: /* original 000b, guest PC 0x0c02eee6 */
if(!s->budget--) { s->failed_pc=0x0c02eee6u; return 0; }
target=r[16];
r[17]=(r[17]&~1u)|((((r[6]^r[0])&0xffu)==0 || ((r[6]^r[0])&0xff00u)==0 || ((r[6]^r[0])&0xff0000u)==0 || ((r[6]^r[0])&0xff000000u)==0)!=0);
s->pc=target; return ram->oob==0;
P_0c02eee8: /* original 260c, guest PC 0x0c02eee8 */
if(!s->budget--) { s->failed_pc=0x0c02eee8u; return 0; }
r[17]=(r[17]&~1u)|((((r[6]^r[0])&0xffu)==0 || ((r[6]^r[0])&0xff00u)==0 || ((r[6]^r[0])&0xff0000u)==0 || ((r[6]^r[0])&0xff000000u)==0)!=0);
return vf3_matrix_family(0x0c02eeeau,s,ram);
P_0c0364b8: /* original 2fe6, guest PC 0x0c0364b8 */
if(!s->budget--) { s->failed_pc=0x0c0364b8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0364ba;
P_0c0364ba: /* original 2fd6, guest PC 0x0c0364ba */
if(!s->budget--) { s->failed_pc=0x0c0364bau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0364bc;
P_0c0364bc: /* original 2fc6, guest PC 0x0c0364bc */
if(!s->budget--) { s->failed_pc=0x0c0364bcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0364be;
P_0c0364be: /* original 2fb6, guest PC 0x0c0364be */
if(!s->budget--) { s->failed_pc=0x0c0364beu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0364c0;
P_0c0364c0: /* original 2fa6, guest PC 0x0c0364c0 */
if(!s->budget--) { s->failed_pc=0x0c0364c0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0364c2;
P_0c0364c2: /* original 2f96, guest PC 0x0c0364c2 */
if(!s->budget--) { s->failed_pc=0x0c0364c2u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
return vf3_matrix_family(0x0c0364c4u,s,ram);
P_0c036dd4: /* original 4f22, guest PC 0x0c036dd4 */
if(!s->budget--) { s->failed_pc=0x0c036dd4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c036dd6;
P_0c036dd6: /* original d121, guest PC 0x0c036dd6 */
if(!s->budget--) { s->failed_pc=0x0c036dd6u; return 0; }
r[1]=read(ram,0x0c036e5cu,4);
goto P_0c036dd8;
P_0c036dd8: /* original 6210, guest PC 0x0c036dd8 */
if(!s->budget--) { s->failed_pc=0x0c036dd8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[2]=tmp;
goto P_0c036dda;
P_0c036dda: /* original 4f12, guest PC 0x0c036dda */
if(!s->budget--) { s->failed_pc=0x0c036ddau; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c036ddc;
P_0c036ddc: /* original 2228, guest PC 0x0c036ddc */
if(!s->budget--) { s->failed_pc=0x0c036ddcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c036dde;
P_0c036dde: /* original 8902, guest PC 0x0c036dde */
if(!s->budget--) { s->failed_pc=0x0c036ddeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c036de6; }
goto P_0c036de0;
P_0c036de0: /* original d21f, guest PC 0x0c036de0 */
if(!s->budget--) { s->failed_pc=0x0c036de0u; return 0; }
r[2]=read(ram,0x0c036e60u,4);
goto P_0c036de2;
P_0c036de2: /* original 420b, guest PC 0x0c036de2 */
if(!s->budget--) { s->failed_pc=0x0c036de2u; return 0; }
target=r[2];
r[16]=code_base|0x0c036de6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c036de6u) { target=s->pc; goto dispatch; }
goto P_0c036de6;
P_0c036de4: /* original 0009, guest PC 0x0c036de4 */
if(!s->budget--) { s->failed_pc=0x0c036de4u; return 0; }
goto P_0c036de6;
P_0c036de6: /* original d31f, guest PC 0x0c036de6 */
if(!s->budget--) { s->failed_pc=0x0c036de6u; return 0; }
r[3]=read(ram,0x0c036e64u,4);
goto P_0c036de8;
P_0c036de8: /* original e500, guest PC 0x0c036de8 */
if(!s->budget--) { s->failed_pc=0x0c036de8u; return 0; }
r[5]=0x00000000u;
goto P_0c036dea;
P_0c036dea: /* original 962e, guest PC 0x0c036dea */
if(!s->budget--) { s->failed_pc=0x0c036deau; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c036e4au,2);
goto P_0c036dec;
P_0c036dec: /* original dc1a, guest PC 0x0c036dec */
if(!s->budget--) { s->failed_pc=0x0c036decu; return 0; }
r[12]=read(ram,0x0c036e58u,4);
goto P_0c036dee;
P_0c036dee: /* original 430b, guest PC 0x0c036dee */
if(!s->budget--) { s->failed_pc=0x0c036deeu; return 0; }
target=r[3];
r[16]=code_base|0x0c036df2u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c036df2u) { target=s->pc; goto dispatch; }
goto P_0c036df2;
P_0c036df0: /* original 64c3, guest PC 0x0c036df0 */
if(!s->budget--) { s->failed_pc=0x0c036df0u; return 0; }
r[4]=r[12];
goto P_0c036df2;
P_0c036df2: /* original ed00, guest PC 0x0c036df2 */
if(!s->budget--) { s->failed_pc=0x0c036df2u; return 0; }
r[13]=0x00000000u;
goto P_0c036df4;
P_0c036df4: /* original da1c, guest PC 0x0c036df4 */
if(!s->budget--) { s->failed_pc=0x0c036df4u; return 0; }
r[10]=read(ram,0x0c036e68u,4);
goto P_0c036df6;
P_0c036df6: /* original 6ed3, guest PC 0x0c036df6 */
if(!s->budget--) { s->failed_pc=0x0c036df6u; return 0; }
r[14]=r[13];
goto P_0c036df8;
P_0c036df8: /* original eb18, guest PC 0x0c036df8 */
if(!s->budget--) { s->failed_pc=0x0c036df8u; return 0; }
r[11]=0x00000018u;
goto P_0c036dfa;
P_0c036dfa: /* original e434, guest PC 0x0c036dfa */
if(!s->budget--) { s->failed_pc=0x0c036dfau; return 0; }
r[4]=0x00000034u;
goto P_0c036dfc;
P_0c036dfc: /* original 2e4f, guest PC 0x0c036dfc */
if(!s->budget--) { s->failed_pc=0x0c036dfcu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[4]);
goto P_0c036dfe;
P_0c036dfe: /* original 041a, guest PC 0x0c036dfe */
if(!s->budget--) { s->failed_pc=0x0c036dfeu; return 0; }
r[4]=r[19];
goto P_0c036e00;
P_0c036e00: /* original 644f, guest PC 0x0c036e00 */
if(!s->budget--) { s->failed_pc=0x0c036e00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c036e02;
P_0c036e02: /* original be29, guest PC 0x0c036e02 */
if(!s->budget--) { s->failed_pc=0x0c036e02u; return 0; }
target=0x0c036a58u; r[16]=code_base|0x0c036e06u;
r[4]+=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c036e06u) { target=s->pc; goto dispatch; }
goto P_0c036e06;
P_0c036e04: /* original 34cc, guest PC 0x0c036e04 */
if(!s->budget--) { s->failed_pc=0x0c036e04u; return 0; }
r[4]+=r[12];
goto P_0c036e06;
P_0c036e06: /* original 60e3, guest PC 0x0c036e06 */
if(!s->budget--) { s->failed_pc=0x0c036e06u; return 0; }
r[0]=r[14];
goto P_0c036e08;
P_0c036e08: /* original 7e01, guest PC 0x0c036e08 */
if(!s->budget--) { s->failed_pc=0x0c036e08u; return 0; }
r[14]+=0x00000001u;
goto P_0c036e0a;
P_0c036e0a: /* original 3eb3, guest PC 0x0c036e0a */
if(!s->budget--) { s->failed_pc=0x0c036e0au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[11])!=0);
goto P_0c036e0c;
P_0c036e0c: /* original 4008, guest PC 0x0c036e0c */
if(!s->budget--) { s->failed_pc=0x0c036e0cu; return 0; }
r[0]<<=2;
goto P_0c036e0e;
P_0c036e0e: /* original 8ff4, guest PC 0x0c036e0e */
if(!s->budget--) { s->failed_pc=0x0c036e0eu; return 0; }
cond=r[17]&1u;
write(ram,r[10]+r[0],r[13],4);
if(!cond) { goto P_0c036dfa; }
goto P_0c036e12;
P_0c036e10: /* original 0ad6, guest PC 0x0c036e10 */
if(!s->budget--) { s->failed_pc=0x0c036e10u; return 0; }
write(ram,r[10]+r[0],r[13],4);
goto P_0c036e12;
P_0c036e12: /* original 4f16, guest PC 0x0c036e12 */
if(!s->budget--) { s->failed_pc=0x0c036e12u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c036e14;
P_0c036e14: /* original 4f26, guest PC 0x0c036e14 */
if(!s->budget--) { s->failed_pc=0x0c036e14u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c036e16;
P_0c036e16: /* original 6af6, guest PC 0x0c036e16 */
if(!s->budget--) { s->failed_pc=0x0c036e16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c036e18;
P_0c036e18: /* original 6bf6, guest PC 0x0c036e18 */
if(!s->budget--) { s->failed_pc=0x0c036e18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c036e1a;
P_0c036e1a: /* original 6cf6, guest PC 0x0c036e1a */
if(!s->budget--) { s->failed_pc=0x0c036e1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c036e1c;
P_0c036e1c: /* original 6df6, guest PC 0x0c036e1c */
if(!s->budget--) { s->failed_pc=0x0c036e1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c036e1e;
P_0c036e1e: /* original 000b, guest PC 0x0c036e1e */
if(!s->budget--) { s->failed_pc=0x0c036e1eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c036e20: /* original 6ef6, guest PC 0x0c036e20 */
if(!s->budget--) { s->failed_pc=0x0c036e20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c036e22u,s,ram);
P_0c03750a: /* original 4f22, guest PC 0x0c03750a */
if(!s->budget--) { s->failed_pc=0x0c03750au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03750c;
P_0c03750c: /* original 7ff8, guest PC 0x0c03750c */
if(!s->budget--) { s->failed_pc=0x0c03750cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c03750e;
P_0c03750e: /* original 1f41, guest PC 0x0c03750e */
if(!s->budget--) { s->failed_pc=0x0c03750eu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c037510;
P_0c037510: /* original b010, guest PC 0x0c037510 */
if(!s->budget--) { s->failed_pc=0x0c037510u; return 0; }
target=0x0c037534u; r[16]=code_base|0x0c037514u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c037514u) { target=s->pc; goto dispatch; }
goto P_0c037514;
P_0c037512: /* original 0009, guest PC 0x0c037512 */
if(!s->budget--) { s->failed_pc=0x0c037512u; return 0; }
goto P_0c037514;
P_0c037514: /* original b00e, guest PC 0x0c037514 */
if(!s->budget--) { s->failed_pc=0x0c037514u; return 0; }
target=0x0c037534u; r[16]=code_base|0x0c037518u;
write(ram,r[15],r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c037518u) { target=s->pc; goto dispatch; }
goto P_0c037518;
P_0c037516: /* original 2f02, guest PC 0x0c037516 */
if(!s->budget--) { s->failed_pc=0x0c037516u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c037518;
P_0c037518: /* original 62f2, guest PC 0x0c037518 */
if(!s->budget--) { s->failed_pc=0x0c037518u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c03751a;
P_0c03751a: /* original 3200, guest PC 0x0c03751a */
if(!s->budget--) { s->failed_pc=0x0c03751au; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[0])!=0);
goto P_0c03751c;
P_0c03751c: /* original 8902, guest PC 0x0c03751c */
if(!s->budget--) { s->failed_pc=0x0c03751cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c037524; }
goto P_0c03751e;
P_0c03751e: /* original 7e01, guest PC 0x0c03751e */
if(!s->budget--) { s->failed_pc=0x0c03751eu; return 0; }
r[14]+=0x00000001u;
goto P_0c037520;
P_0c037520: /* original 3ed3, guest PC 0x0c037520 */
if(!s->budget--) { s->failed_pc=0x0c037520u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[13])!=0);
goto P_0c037522;
P_0c037522: /* original 8bf5, guest PC 0x0c037522 */
if(!s->budget--) { s->failed_pc=0x0c037522u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c037510; }
goto P_0c037524;
P_0c037524: /* original 55f1, guest PC 0x0c037524 */
if(!s->budget--) { s->failed_pc=0x0c037524u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c037526;
P_0c037526: /* original b027, guest PC 0x0c037526 */
if(!s->budget--) { s->failed_pc=0x0c037526u; return 0; }
target=0x0c037578u; r[16]=code_base|0x0c03752au;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03752au) { target=s->pc; goto dispatch; }
goto P_0c03752a;
P_0c037528: /* original 64f2, guest PC 0x0c037528 */
if(!s->budget--) { s->failed_pc=0x0c037528u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c03752a;
P_0c03752a: /* original 7f08, guest PC 0x0c03752a */
if(!s->budget--) { s->failed_pc=0x0c03752au; return 0; }
r[15]+=0x00000008u;
goto P_0c03752c;
P_0c03752c: /* original 4f26, guest PC 0x0c03752c */
if(!s->budget--) { s->failed_pc=0x0c03752cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03752e;
P_0c03752e: /* original 6df6, guest PC 0x0c03752e */
if(!s->budget--) { s->failed_pc=0x0c03752eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c037530;
P_0c037530: /* original 000b, guest PC 0x0c037530 */
if(!s->budget--) { s->failed_pc=0x0c037530u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c037532: /* original 6ef6, guest PC 0x0c037532 */
if(!s->budget--) { s->failed_pc=0x0c037532u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c037534;
P_0c037534: /* original d30d, guest PC 0x0c037534 */
if(!s->budget--) { s->failed_pc=0x0c037534u; return 0; }
r[3]=read(ram,0x0c03756cu,4);
goto P_0c037536;
P_0c037536: /* original 6432, guest PC 0x0c037536 */
if(!s->budget--) { s->failed_pc=0x0c037536u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c037538;
P_0c037538: /* original d20d, guest PC 0x0c037538 */
if(!s->budget--) { s->failed_pc=0x0c037538u; return 0; }
r[2]=read(ram,0x0c037570u,4);
goto P_0c03753a;
P_0c03753a: /* original 4428, guest PC 0x0c03753a */
if(!s->budget--) { s->failed_pc=0x0c03753au; return 0; }
r[4]<<=16;
goto P_0c03753c;
P_0c03753c: /* original d10d, guest PC 0x0c03753c */
if(!s->budget--) { s->failed_pc=0x0c03753cu; return 0; }
r[1]=read(ram,0x0c037574u,4);
goto P_0c03753e;
P_0c03753e: /* original 2429, guest PC 0x0c03753e */
if(!s->budget--) { s->failed_pc=0x0c03753eu; return 0; }
r[4]&=r[2];
goto P_0c037540;
P_0c037540: /* original 6512, guest PC 0x0c037540 */
if(!s->budget--) { s->failed_pc=0x0c037540u; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c037542;
P_0c037542: /* original 655d, guest PC 0x0c037542 */
if(!s->budget--) { s->failed_pc=0x0c037542u; return 0; }
r[5]=r[5]&65535u;
goto P_0c037544;
P_0c037544: /* original 245b, guest PC 0x0c037544 */
if(!s->budget--) { s->failed_pc=0x0c037544u; return 0; }
r[4]|=r[5];
goto P_0c037546;
P_0c037546: /* original 000b, guest PC 0x0c037546 */
if(!s->budget--) { s->failed_pc=0x0c037546u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c037548: /* original 6043, guest PC 0x0c037548 */
if(!s->budget--) { s->failed_pc=0x0c037548u; return 0; }
r[0]=r[4];
return vf3_matrix_family(0x0c03754au,s,ram);
P_0c037578: /* original 2fe6, guest PC 0x0c037578 */
if(!s->budget--) { s->failed_pc=0x0c037578u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03757a;
P_0c03757a: /* original 6e53, guest PC 0x0c03757a */
if(!s->budget--) { s->failed_pc=0x0c03757au; return 0; }
r[14]=r[5];
return vf3_matrix_family(0x0c03757cu,s,ram);
P_0c037864: /* original 4f22, guest PC 0x0c037864 */
if(!s->budget--) { s->failed_pc=0x0c037864u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c037866;
P_0c037866: /* original 7ffc, guest PC 0x0c037866 */
if(!s->budget--) { s->failed_pc=0x0c037866u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c037868;
P_0c037868: /* original b00b, guest PC 0x0c037868 */
if(!s->budget--) { s->failed_pc=0x0c037868u; return 0; }
target=0x0c037882u; r[16]=code_base|0x0c03786cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03786cu) { target=s->pc; goto dispatch; }
goto P_0c03786c;
P_0c03786a: /* original 0009, guest PC 0x0c03786a */
if(!s->budget--) { s->failed_pc=0x0c03786au; return 0; }
goto P_0c03786c;
P_0c03786c: /* original 4019, guest PC 0x0c03786c */
if(!s->budget--) { s->failed_pc=0x0c03786cu; return 0; }
r[0]>>=8;
goto P_0c03786e;
P_0c03786e: /* original c903, guest PC 0x0c03786e */
if(!s->budget--) { s->failed_pc=0x0c03786eu; return 0; }
r[0]&=3u;
goto P_0c037870;
P_0c037870: /* original 2f02, guest PC 0x0c037870 */
if(!s->budget--) { s->failed_pc=0x0c037870u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c037872;
P_0c037872: /* original 7f04, guest PC 0x0c037872 */
if(!s->budget--) { s->failed_pc=0x0c037872u; return 0; }
r[15]+=0x00000004u;
goto P_0c037874;
P_0c037874: /* original 4f26, guest PC 0x0c037874 */
if(!s->budget--) { s->failed_pc=0x0c037874u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c037876;
P_0c037876: /* original 000b, guest PC 0x0c037876 */
if(!s->budget--) { s->failed_pc=0x0c037876u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c037878: /* original 0009, guest PC 0x0c037878 */
if(!s->budget--) { s->failed_pc=0x0c037878u; return 0; }
return vf3_matrix_family(0x0c03787au,s,ram);
P_0c039080: /* original 4f22, guest PC 0x0c039080 */
if(!s->budget--) { s->failed_pc=0x0c039080u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c039082;
P_0c039082: /* original 6173, guest PC 0x0c039082 */
if(!s->budget--) { s->failed_pc=0x0c039082u; return 0; }
r[1]=r[7];
goto P_0c039084;
P_0c039084: /* original 7ff0, guest PC 0x0c039084 */
if(!s->budget--) { s->failed_pc=0x0c039084u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c039086;
P_0c039086: /* original 2f42, guest PC 0x0c039086 */
if(!s->budget--) { s->failed_pc=0x0c039086u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c039088;
P_0c039088: /* original 1f51, guest PC 0x0c039088 */
if(!s->budget--) { s->failed_pc=0x0c039088u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c03908a;
P_0c03908a: /* original 1f62, guest PC 0x0c03908a */
if(!s->budget--) { s->failed_pc=0x0c03908au; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c03908c;
P_0c03908c: /* original 1f73, guest PC 0x0c03908c */
if(!s->budget--) { s->failed_pc=0x0c03908cu; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c03908e;
P_0c03908e: /* original d328, guest PC 0x0c03908e */
if(!s->budget--) { s->failed_pc=0x0c03908eu; return 0; }
r[3]=read(ram,0x0c039130u,4);
goto P_0c039090;
P_0c039090: /* original 6032, guest PC 0x0c039090 */
if(!s->budget--) { s->failed_pc=0x0c039090u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c039092;
P_0c039092: /* original 2f76, guest PC 0x0c039092 */
if(!s->budget--) { s->failed_pc=0x0c039092u; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c039094;
P_0c039094: /* original d427, guest PC 0x0c039094 */
if(!s->budget--) { s->failed_pc=0x0c039094u; return 0; }
r[4]=read(ram,0x0c039134u,4);
goto P_0c039096;
P_0c039096: /* original 8802, guest PC 0x0c039096 */
if(!s->budget--) { s->failed_pc=0x0c039096u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c039098;
P_0c039098: /* original d327, guest PC 0x0c039098 */
if(!s->budget--) { s->failed_pc=0x0c039098u; return 0; }
r[3]=read(ram,0x0c039138u,4);
goto P_0c03909a;
P_0c03909a: /* original 56f2, guest PC 0x0c03909a */
if(!s->budget--) { s->failed_pc=0x0c03909au; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c03909c;
P_0c03909c: /* original 57f3, guest PC 0x0c03909c */
if(!s->budget--) { s->failed_pc=0x0c03909cu; return 0; }
r[7]=read(ram,r[15]+12,4);
goto P_0c03909e;
P_0c03909e: /* original 430b, guest PC 0x0c03909e */
if(!s->budget--) { s->failed_pc=0x0c03909eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0390a2u;
r[5]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0390a2u) { target=s->pc; goto dispatch; }
goto P_0c0390a2;
P_0c0390a0: /* original 55f1, guest PC 0x0c0390a0 */
if(!s->budget--) { s->failed_pc=0x0c0390a0u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0390a2;
P_0c0390a2: /* original e200, guest PC 0x0c0390a2 */
if(!s->budget--) { s->failed_pc=0x0c0390a2u; return 0; }
r[2]=0x00000000u;
goto P_0c0390a4;
P_0c0390a4: /* original 6623, guest PC 0x0c0390a4 */
if(!s->budget--) { s->failed_pc=0x0c0390a4u; return 0; }
r[6]=r[2];
goto P_0c0390a6;
P_0c0390a6: /* original 2f26, guest PC 0x0c0390a6 */
if(!s->budget--) { s->failed_pc=0x0c0390a6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0390a8;
P_0c0390a8: /* original d424, guest PC 0x0c0390a8 */
if(!s->budget--) { s->failed_pc=0x0c0390a8u; return 0; }
r[4]=read(ram,0x0c03913cu,4);
goto P_0c0390aa;
P_0c0390aa: /* original 6723, guest PC 0x0c0390aa */
if(!s->budget--) { s->failed_pc=0x0c0390aau; return 0; }
r[7]=r[2];
goto P_0c0390ac;
P_0c0390ac: /* original d324, guest PC 0x0c0390ac */
if(!s->budget--) { s->failed_pc=0x0c0390acu; return 0; }
r[3]=read(ram,0x0c039140u,4);
goto P_0c0390ae;
P_0c0390ae: /* original 430b, guest PC 0x0c0390ae */
if(!s->budget--) { s->failed_pc=0x0c0390aeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0390b2u;
r[5]=r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0390b2u) { target=s->pc; goto dispatch; }
goto P_0c0390b2;
P_0c0390b0: /* original 6523, guest PC 0x0c0390b0 */
if(!s->budget--) { s->failed_pc=0x0c0390b0u; return 0; }
r[5]=r[2];
goto P_0c0390b2;
P_0c0390b2: /* original e200, guest PC 0x0c0390b2 */
if(!s->budget--) { s->failed_pc=0x0c0390b2u; return 0; }
r[2]=0x00000000u;
goto P_0c0390b4;
P_0c0390b4: /* original 6623, guest PC 0x0c0390b4 */
if(!s->budget--) { s->failed_pc=0x0c0390b4u; return 0; }
r[6]=r[2];
goto P_0c0390b6;
P_0c0390b6: /* original 2f26, guest PC 0x0c0390b6 */
if(!s->budget--) { s->failed_pc=0x0c0390b6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0390b8;
P_0c0390b8: /* original d422, guest PC 0x0c0390b8 */
if(!s->budget--) { s->failed_pc=0x0c0390b8u; return 0; }
r[4]=read(ram,0x0c039144u,4);
goto P_0c0390ba;
P_0c0390ba: /* original 6723, guest PC 0x0c0390ba */
if(!s->budget--) { s->failed_pc=0x0c0390bau; return 0; }
r[7]=r[2];
goto P_0c0390bc;
P_0c0390bc: /* original d320, guest PC 0x0c0390bc */
if(!s->budget--) { s->failed_pc=0x0c0390bcu; return 0; }
r[3]=read(ram,0x0c039140u,4);
goto P_0c0390be;
P_0c0390be: /* original 430b, guest PC 0x0c0390be */
if(!s->budget--) { s->failed_pc=0x0c0390beu; return 0; }
target=r[3];
r[16]=code_base|0x0c0390c2u;
r[5]=r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0390c2u) { target=s->pc; goto dispatch; }
goto P_0c0390c2;
P_0c0390c0: /* original 6523, guest PC 0x0c0390c0 */
if(!s->budget--) { s->failed_pc=0x0c0390c0u; return 0; }
r[5]=r[2];
goto P_0c0390c2;
P_0c0390c2: /* original d41e, guest PC 0x0c0390c2 */
if(!s->budget--) { s->failed_pc=0x0c0390c2u; return 0; }
r[4]=read(ram,0x0c03913cu,4);
goto P_0c0390c4;
P_0c0390c4: /* original e701, guest PC 0x0c0390c4 */
if(!s->budget--) { s->failed_pc=0x0c0390c4u; return 0; }
r[7]=0x00000001u;
goto P_0c0390c6;
P_0c0390c6: /* original d220, guest PC 0x0c0390c6 */
if(!s->budget--) { s->failed_pc=0x0c0390c6u; return 0; }
r[2]=read(ram,0x0c039148u,4);
goto P_0c0390c8;
P_0c0390c8: /* original d51e, guest PC 0x0c0390c8 */
if(!s->budget--) { s->failed_pc=0x0c0390c8u; return 0; }
r[5]=read(ram,0x0c039144u,4);
goto P_0c0390ca;
P_0c0390ca: /* original 420b, guest PC 0x0c0390ca */
if(!s->budget--) { s->failed_pc=0x0c0390cau; return 0; }
target=r[2];
r[16]=code_base|0x0c0390ceu;
r[6]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0390ceu) { target=s->pc; goto dispatch; }
goto P_0c0390ce;
P_0c0390cc: /* original e600, guest PC 0x0c0390cc */
if(!s->budget--) { s->failed_pc=0x0c0390ccu; return 0; }
r[6]=0x00000000u;
goto P_0c0390ce;
P_0c0390ce: /* original d31f, guest PC 0x0c0390ce */
if(!s->budget--) { s->failed_pc=0x0c0390ceu; return 0; }
r[3]=read(ram,0x0c03914cu,4);
goto P_0c0390d0;
P_0c0390d0: /* original 430b, guest PC 0x0c0390d0 */
if(!s->budget--) { s->failed_pc=0x0c0390d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0390d4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0390d4u) { target=s->pc; goto dispatch; }
goto P_0c0390d4;
P_0c0390d2: /* original 0009, guest PC 0x0c0390d2 */
if(!s->budget--) { s->failed_pc=0x0c0390d2u; return 0; }
goto P_0c0390d4;
P_0c0390d4: /* original 7f1c, guest PC 0x0c0390d4 */
if(!s->budget--) { s->failed_pc=0x0c0390d4u; return 0; }
r[15]+=0x0000001cu;
goto P_0c0390d6;
P_0c0390d6: /* original 4f26, guest PC 0x0c0390d6 */
if(!s->budget--) { s->failed_pc=0x0c0390d6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0390d8;
P_0c0390d8: /* original 000b, guest PC 0x0c0390d8 */
if(!s->budget--) { s->failed_pc=0x0c0390d8u; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c0390da: /* original e001, guest PC 0x0c0390da */
if(!s->budget--) { s->failed_pc=0x0c0390dau; return 0; }
r[0]=0x00000001u;
return vf3_matrix_family(0x0c0390dcu,s,ram);
P_0c0393c0: /* original 4f22, guest PC 0x0c0393c0 */
if(!s->budget--) { s->failed_pc=0x0c0393c0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0393c2;
P_0c0393c2: /* original 6343, guest PC 0x0c0393c2 */
if(!s->budget--) { s->failed_pc=0x0c0393c2u; return 0; }
r[3]=r[4];
goto P_0c0393c4;
P_0c0393c4: /* original 7ffc, guest PC 0x0c0393c4 */
if(!s->budget--) { s->failed_pc=0x0c0393c4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0393c6;
P_0c0393c6: /* original 2f42, guest PC 0x0c0393c6 */
if(!s->budget--) { s->failed_pc=0x0c0393c6u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0393c8;
P_0c0393c8: /* original d230, guest PC 0x0c0393c8 */
if(!s->budget--) { s->failed_pc=0x0c0393c8u; return 0; }
r[2]=read(ram,0x0c03948cu,4);
goto P_0c0393ca;
P_0c0393ca: /* original 420b, guest PC 0x0c0393ca */
if(!s->budget--) { s->failed_pc=0x0c0393cau; return 0; }
target=r[2];
r[16]=code_base|0x0c0393ceu;
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0393ceu) { target=s->pc; goto dispatch; }
goto P_0c0393ce;
P_0c0393cc: /* original 2f46, guest PC 0x0c0393cc */
if(!s->budget--) { s->failed_pc=0x0c0393ccu; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0393ce;
P_0c0393ce: /* original 7f08, guest PC 0x0c0393ce */
if(!s->budget--) { s->failed_pc=0x0c0393ceu; return 0; }
r[15]+=0x00000008u;
goto P_0c0393d0;
P_0c0393d0: /* original 4f26, guest PC 0x0c0393d0 */
if(!s->budget--) { s->failed_pc=0x0c0393d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0393d2;
P_0c0393d2: /* original 000b, guest PC 0x0c0393d2 */
if(!s->budget--) { s->failed_pc=0x0c0393d2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0393d4: /* original 0009, guest PC 0x0c0393d4 */
if(!s->budget--) { s->failed_pc=0x0c0393d4u; return 0; }
return vf3_matrix_family(0x0c0393d6u,s,ram);
P_0c0393e0: /* original 4f22, guest PC 0x0c0393e0 */
if(!s->budget--) { s->failed_pc=0x0c0393e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0393e2;
P_0c0393e2: /* original 6343, guest PC 0x0c0393e2 */
if(!s->budget--) { s->failed_pc=0x0c0393e2u; return 0; }
r[3]=r[4];
goto P_0c0393e4;
P_0c0393e4: /* original 7ffc, guest PC 0x0c0393e4 */
if(!s->budget--) { s->failed_pc=0x0c0393e4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0393e6;
P_0c0393e6: /* original 2f42, guest PC 0x0c0393e6 */
if(!s->budget--) { s->failed_pc=0x0c0393e6u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0393e8;
P_0c0393e8: /* original d229, guest PC 0x0c0393e8 */
if(!s->budget--) { s->failed_pc=0x0c0393e8u; return 0; }
r[2]=read(ram,0x0c039490u,4);
goto P_0c0393ea;
P_0c0393ea: /* original 420b, guest PC 0x0c0393ea */
if(!s->budget--) { s->failed_pc=0x0c0393eau; return 0; }
target=r[2];
r[16]=code_base|0x0c0393eeu;
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0393eeu) { target=s->pc; goto dispatch; }
goto P_0c0393ee;
P_0c0393ec: /* original 2f46, guest PC 0x0c0393ec */
if(!s->budget--) { s->failed_pc=0x0c0393ecu; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0393ee;
P_0c0393ee: /* original 7f08, guest PC 0x0c0393ee */
if(!s->budget--) { s->failed_pc=0x0c0393eeu; return 0; }
r[15]+=0x00000008u;
goto P_0c0393f0;
P_0c0393f0: /* original 4f26, guest PC 0x0c0393f0 */
if(!s->budget--) { s->failed_pc=0x0c0393f0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0393f2;
P_0c0393f2: /* original 000b, guest PC 0x0c0393f2 */
if(!s->budget--) { s->failed_pc=0x0c0393f2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0393f4: /* original 0009, guest PC 0x0c0393f4 */
if(!s->budget--) { s->failed_pc=0x0c0393f4u; return 0; }
return vf3_matrix_family(0x0c0393f6u,s,ram);
P_0c0394e0: /* original 4f22, guest PC 0x0c0394e0 */
if(!s->budget--) { s->failed_pc=0x0c0394e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0394e2;
P_0c0394e2: /* original d338, guest PC 0x0c0394e2 */
if(!s->budget--) { s->failed_pc=0x0c0394e2u; return 0; }
r[3]=read(ram,0x0c0395c4u,4);
goto P_0c0394e4;
P_0c0394e4: /* original 243b, guest PC 0x0c0394e4 */
if(!s->budget--) { s->failed_pc=0x0c0394e4u; return 0; }
r[4]|=r[3];
goto P_0c0394e6;
P_0c0394e6: /* original 7ffc, guest PC 0x0c0394e6 */
if(!s->budget--) { s->failed_pc=0x0c0394e6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0394e8;
P_0c0394e8: /* original 6243, guest PC 0x0c0394e8 */
if(!s->budget--) { s->failed_pc=0x0c0394e8u; return 0; }
r[2]=r[4];
goto P_0c0394ea;
P_0c0394ea: /* original 2f42, guest PC 0x0c0394ea */
if(!s->budget--) { s->failed_pc=0x0c0394eau; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0394ec;
P_0c0394ec: /* original d136, guest PC 0x0c0394ec */
if(!s->budget--) { s->failed_pc=0x0c0394ecu; return 0; }
r[1]=read(ram,0x0c0395c8u,4);
goto P_0c0394ee;
P_0c0394ee: /* original 410b, guest PC 0x0c0394ee */
if(!s->budget--) { s->failed_pc=0x0c0394eeu; return 0; }
target=r[1];
r[16]=code_base|0x0c0394f2u;
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0394f2u) { target=s->pc; goto dispatch; }
goto P_0c0394f2;
P_0c0394f0: /* original 2f46, guest PC 0x0c0394f0 */
if(!s->budget--) { s->failed_pc=0x0c0394f0u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0394f2;
P_0c0394f2: /* original 7f08, guest PC 0x0c0394f2 */
if(!s->budget--) { s->failed_pc=0x0c0394f2u; return 0; }
r[15]+=0x00000008u;
goto P_0c0394f4;
P_0c0394f4: /* original 4f26, guest PC 0x0c0394f4 */
if(!s->budget--) { s->failed_pc=0x0c0394f4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0394f6;
P_0c0394f6: /* original 000b, guest PC 0x0c0394f6 */
if(!s->budget--) { s->failed_pc=0x0c0394f6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0394f8: /* original 0009, guest PC 0x0c0394f8 */
if(!s->budget--) { s->failed_pc=0x0c0394f8u; return 0; }
return vf3_matrix_family(0x0c0394fau,s,ram);
P_0c0397a0: /* original 4f22, guest PC 0x0c0397a0 */
if(!s->budget--) { s->failed_pc=0x0c0397a0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0397a2;
P_0c0397a2: /* original d337, guest PC 0x0c0397a2 */
if(!s->budget--) { s->failed_pc=0x0c0397a2u; return 0; }
r[3]=read(ram,0x0c039880u,4);
goto P_0c0397a4;
P_0c0397a4: /* original 7ffc, guest PC 0x0c0397a4 */
if(!s->budget--) { s->failed_pc=0x0c0397a4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0397a6;
P_0c0397a6: /* original 430b, guest PC 0x0c0397a6 */
if(!s->budget--) { s->failed_pc=0x0c0397a6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0397aau;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0397aau) { target=s->pc; goto dispatch; }
goto P_0c0397aa;
P_0c0397a8: /* original 64f3, guest PC 0x0c0397a8 */
if(!s->budget--) { s->failed_pc=0x0c0397a8u; return 0; }
r[4]=r[15];
goto P_0c0397aa;
P_0c0397aa: /* original 60f2, guest PC 0x0c0397aa */
if(!s->budget--) { s->failed_pc=0x0c0397aau; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0397ac;
P_0c0397ac: /* original 7f04, guest PC 0x0c0397ac */
if(!s->budget--) { s->failed_pc=0x0c0397acu; return 0; }
r[15]+=0x00000004u;
goto P_0c0397ae;
P_0c0397ae: /* original 4f26, guest PC 0x0c0397ae */
if(!s->budget--) { s->failed_pc=0x0c0397aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0397b0;
P_0c0397b0: /* original 000b, guest PC 0x0c0397b0 */
if(!s->budget--) { s->failed_pc=0x0c0397b0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0397b2: /* original 0009, guest PC 0x0c0397b2 */
if(!s->budget--) { s->failed_pc=0x0c0397b2u; return 0; }
return vf3_matrix_family(0x0c0397b4u,s,ram);
P_0c039c90: /* original 4f22, guest PC 0x0c039c90 */
if(!s->budget--) { s->failed_pc=0x0c039c90u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c039c92;
P_0c039c92: /* original 6353, guest PC 0x0c039c92 */
if(!s->budget--) { s->failed_pc=0x0c039c92u; return 0; }
r[3]=r[5];
goto P_0c039c94;
P_0c039c94: /* original 7ff8, guest PC 0x0c039c94 */
if(!s->budget--) { s->failed_pc=0x0c039c94u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c039c96;
P_0c039c96: /* original 1f41, guest PC 0x0c039c96 */
if(!s->budget--) { s->failed_pc=0x0c039c96u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c039c98;
P_0c039c98: /* original 2f52, guest PC 0x0c039c98 */
if(!s->budget--) { s->failed_pc=0x0c039c98u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c039c9a;
P_0c039c9a: /* original 2f56, guest PC 0x0c039c9a */
if(!s->budget--) { s->failed_pc=0x0c039c9au; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c039c9c;
P_0c039c9c: /* original d32f, guest PC 0x0c039c9c */
if(!s->budget--) { s->failed_pc=0x0c039c9cu; return 0; }
r[3]=read(ram,0x0c039d5cu,4);
goto P_0c039c9e;
P_0c039c9e: /* original 52f2, guest PC 0x0c039c9e */
if(!s->budget--) { s->failed_pc=0x0c039c9eu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c039ca0;
P_0c039ca0: /* original 430b, guest PC 0x0c039ca0 */
if(!s->budget--) { s->failed_pc=0x0c039ca0u; return 0; }
target=r[3];
r[16]=code_base|0x0c039ca4u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c039ca4u) { target=s->pc; goto dispatch; }
goto P_0c039ca4;
P_0c039ca2: /* original 2f26, guest PC 0x0c039ca2 */
if(!s->budget--) { s->failed_pc=0x0c039ca2u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c039ca4;
P_0c039ca4: /* original 7f10, guest PC 0x0c039ca4 */
if(!s->budget--) { s->failed_pc=0x0c039ca4u; return 0; }
r[15]+=0x00000010u;
goto P_0c039ca6;
P_0c039ca6: /* original 4f26, guest PC 0x0c039ca6 */
if(!s->budget--) { s->failed_pc=0x0c039ca6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c039ca8;
P_0c039ca8: /* original 000b, guest PC 0x0c039ca8 */
if(!s->budget--) { s->failed_pc=0x0c039ca8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c039caa: /* original 0009, guest PC 0x0c039caa */
if(!s->budget--) { s->failed_pc=0x0c039caau; return 0; }
return vf3_matrix_family(0x0c039cacu,s,ram);
P_0c03b2d0: /* original 4f22, guest PC 0x0c03b2d0 */
if(!s->budget--) { s->failed_pc=0x0c03b2d0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03b2d2;
P_0c03b2d2: /* original 9066, guest PC 0x0c03b2d2 */
if(!s->budget--) { s->failed_pc=0x0c03b2d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03b3a2u,2);
goto P_0c03b2d4;
P_0c03b2d4: /* original e500, guest PC 0x0c03b2d4 */
if(!s->budget--) { s->failed_pc=0x0c03b2d4u; return 0; }
r[5]=0x00000000u;
goto P_0c03b2d6;
P_0c03b2d6: /* original 9665, guest PC 0x0c03b2d6 */
if(!s->budget--) { s->failed_pc=0x0c03b2d6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03b3a4u,2);
goto P_0c03b2d8;
P_0c03b2d8: /* original 3f0c, guest PC 0x0c03b2d8 */
if(!s->budget--) { s->failed_pc=0x0c03b2d8u; return 0; }
r[15]+=r[0];
goto P_0c03b2da;
P_0c03b2da: /* original f48d, guest PC 0x0c03b2da */
if(!s->budget--) { s->failed_pc=0x0c03b2dau; return 0; }
fr[4]=0;
goto P_0c03b2dc;
P_0c03b2dc: /* original 64f3, guest PC 0x0c03b2dc */
if(!s->budget--) { s->failed_pc=0x0c03b2dcu; return 0; }
r[4]=r[15];
goto P_0c03b2de;
P_0c03b2de: /* original 7501, guest PC 0x0c03b2de */
if(!s->budget--) { s->failed_pc=0x0c03b2deu; return 0; }
r[5]+=0x00000001u;
goto P_0c03b2e0;
P_0c03b2e0: /* original f44a, guest PC 0x0c03b2e0 */
if(!s->budget--) { s->failed_pc=0x0c03b2e0u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c03b2e2;
P_0c03b2e2: /* original 3563, guest PC 0x0c03b2e2 */
if(!s->budget--) { s->failed_pc=0x0c03b2e2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c03b2e4;
P_0c03b2e4: /* original 8ffb, guest PC 0x0c03b2e4 */
if(!s->budget--) { s->failed_pc=0x0c03b2e4u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c03b2de; }
goto P_0c03b2e8;
P_0c03b2e6: /* original 7404, guest PC 0x0c03b2e6 */
if(!s->budget--) { s->failed_pc=0x0c03b2e6u; return 0; }
r[4]+=0x00000004u;
goto P_0c03b2e8;
P_0c03b2e8: /* original b032, guest PC 0x0c03b2e8 */
if(!s->budget--) { s->failed_pc=0x0c03b2e8u; return 0; }
target=0x0c03b350u; r[16]=code_base|0x0c03b2ecu;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03b2ecu) { target=s->pc; goto dispatch; }
goto P_0c03b2ec;
P_0c03b2ea: /* original 64f3, guest PC 0x0c03b2ea */
if(!s->budget--) { s->failed_pc=0x0c03b2eau; return 0; }
r[4]=r[15];
goto P_0c03b2ec;
P_0c03b2ec: /* original 915b, guest PC 0x0c03b2ec */
if(!s->budget--) { s->failed_pc=0x0c03b2ecu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03b3a6u,2);
goto P_0c03b2ee;
P_0c03b2ee: /* original 3f1c, guest PC 0x0c03b2ee */
if(!s->budget--) { s->failed_pc=0x0c03b2eeu; return 0; }
r[15]+=r[1];
goto P_0c03b2f0;
P_0c03b2f0: /* original 4f26, guest PC 0x0c03b2f0 */
if(!s->budget--) { s->failed_pc=0x0c03b2f0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03b2f2;
P_0c03b2f2: /* original 000b, guest PC 0x0c03b2f2 */
if(!s->budget--) { s->failed_pc=0x0c03b2f2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03b2f4: /* original 0009, guest PC 0x0c03b2f4 */
if(!s->budget--) { s->failed_pc=0x0c03b2f4u; return 0; }
return vf3_matrix_family(0x0c03b2f6u,s,ram);
P_0c03d0c0: /* original f449, guest PC 0x0c03d0c0 */
if(!s->budget--) { s->failed_pc=0x0c03d0c0u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03d0c2;
P_0c03d0c2: /* original f549, guest PC 0x0c03d0c2 */
if(!s->budget--) { s->failed_pc=0x0c03d0c2u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03d0c4;
P_0c03d0c4: /* original f649, guest PC 0x0c03d0c4 */
if(!s->budget--) { s->failed_pc=0x0c03d0c4u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03d0c6;
P_0c03d0c6: /* original f78d, guest PC 0x0c03d0c6 */
if(!s->budget--) { s->failed_pc=0x0c03d0c6u; return 0; }
fr[7]=0;
goto P_0c03d0c8;
P_0c03d0c8: /* original f5ed, guest PC 0x0c03d0c8 */
if(!s->budget--) { s->failed_pc=0x0c03d0c8u; return 0; }
if(!vf3_fpu_fipr(fr+4,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03d0ca;
P_0c03d0ca: /* original f77d, guest PC 0x0c03d0ca */
if(!s->budget--) { s->failed_pc=0x0c03d0cau; return 0; }
if(!vf3_fpu_fsrra(fr[7],r[18],&fr[7])) goto unsupported;
goto P_0c03d0cc;
P_0c03d0cc: /* original f672, guest PC 0x0c03d0cc */
if(!s->budget--) { s->failed_pc=0x0c03d0ccu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c03d0ce;
P_0c03d0ce: /* original f572, guest PC 0x0c03d0ce */
if(!s->budget--) { s->failed_pc=0x0c03d0ceu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c03d0d0;
P_0c03d0d0: /* original f472, guest PC 0x0c03d0d0 */
if(!s->budget--) { s->failed_pc=0x0c03d0d0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c03d0d2;
P_0c03d0d2: /* original f46b, guest PC 0x0c03d0d2 */
if(!s->budget--) { s->failed_pc=0x0c03d0d2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c03d0d4;
P_0c03d0d4: /* original f45b, guest PC 0x0c03d0d4 */
if(!s->budget--) { s->failed_pc=0x0c03d0d4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[4]);
goto P_0c03d0d6;
P_0c03d0d6: /* original f44b, guest PC 0x0c03d0d6 */
if(!s->budget--) { s->failed_pc=0x0c03d0d6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c03d0d8;
P_0c03d0d8: /* original 000b, guest PC 0x0c03d0d8 */
if(!s->budget--) { s->failed_pc=0x0c03d0d8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03d0da: /* original 0009, guest PC 0x0c03d0da */
if(!s->budget--) { s->failed_pc=0x0c03d0dau; return 0; }
return vf3_matrix_family(0x0c03d0dcu,s,ram);
P_0c03d280: /* original 4f22, guest PC 0x0c03d280 */
if(!s->budget--) { s->failed_pc=0x0c03d280u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03d282;
P_0c03d282: /* original d33f, guest PC 0x0c03d282 */
if(!s->budget--) { s->failed_pc=0x0c03d282u; return 0; }
r[3]=read(ram,0x0c03d380u,4);
goto P_0c03d284;
P_0c03d284: /* original d43d, guest PC 0x0c03d284 */
if(!s->budget--) { s->failed_pc=0x0c03d284u; return 0; }
r[4]=read(ram,0x0c03d37cu,4);
goto P_0c03d286;
P_0c03d286: /* original 430b, guest PC 0x0c03d286 */
if(!s->budget--) { s->failed_pc=0x0c03d286u; return 0; }
target=r[3];
r[16]=code_base|0x0c03d28au;
r[4]=read(ram,r[4]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03d28au) { target=s->pc; goto dispatch; }
goto P_0c03d28a;
P_0c03d288: /* original 5442, guest PC 0x0c03d288 */
if(!s->budget--) { s->failed_pc=0x0c03d288u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c03d28a;
P_0c03d28a: /* original d33b, guest PC 0x0c03d28a */
if(!s->budget--) { s->failed_pc=0x0c03d28au; return 0; }
r[3]=read(ram,0x0c03d378u,4);
goto P_0c03d28c;
P_0c03d28c: /* original d441, guest PC 0x0c03d28c */
if(!s->budget--) { s->failed_pc=0x0c03d28cu; return 0; }
r[4]=read(ram,0x0c03d394u,4);
goto P_0c03d28e;
P_0c03d28e: /* original 430b, guest PC 0x0c03d28e */
if(!s->budget--) { s->failed_pc=0x0c03d28eu; return 0; }
target=r[3];
r[16]=code_base|0x0c03d292u;
r[4]=read(ram,r[4]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03d292u) { target=s->pc; goto dispatch; }
goto P_0c03d292;
P_0c03d290: /* original 5442, guest PC 0x0c03d290 */
if(!s->budget--) { s->failed_pc=0x0c03d290u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c03d292;
P_0c03d292: /* original d23c, guest PC 0x0c03d292 */
if(!s->budget--) { s->failed_pc=0x0c03d292u; return 0; }
r[2]=read(ram,0x0c03d384u,4);
goto P_0c03d294;
P_0c03d294: /* original 420b, guest PC 0x0c03d294 */
if(!s->budget--) { s->failed_pc=0x0c03d294u; return 0; }
target=r[2];
r[16]=code_base|0x0c03d298u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03d298u) { target=s->pc; goto dispatch; }
goto P_0c03d298;
P_0c03d296: /* original 0009, guest PC 0x0c03d296 */
if(!s->budget--) { s->failed_pc=0x0c03d296u; return 0; }
goto P_0c03d298;
P_0c03d298: /* original d33c, guest PC 0x0c03d298 */
if(!s->budget--) { s->failed_pc=0x0c03d298u; return 0; }
r[3]=read(ram,0x0c03d38cu,4);
goto P_0c03d29a;
P_0c03d29a: /* original d43b, guest PC 0x0c03d29a */
if(!s->budget--) { s->failed_pc=0x0c03d29au; return 0; }
r[4]=read(ram,0x0c03d388u,4);
goto P_0c03d29c;
P_0c03d29c: /* original 430b, guest PC 0x0c03d29c */
if(!s->budget--) { s->failed_pc=0x0c03d29cu; return 0; }
target=r[3];
r[16]=code_base|0x0c03d2a0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03d2a0u) { target=s->pc; goto dispatch; }
goto P_0c03d2a0;
P_0c03d29e: /* original 0009, guest PC 0x0c03d29e */
if(!s->budget--) { s->failed_pc=0x0c03d29eu; return 0; }
goto P_0c03d2a0;
P_0c03d2a0: /* original d23b, guest PC 0x0c03d2a0 */
if(!s->budget--) { s->failed_pc=0x0c03d2a0u; return 0; }
r[2]=read(ram,0x0c03d390u,4);
goto P_0c03d2a2;
P_0c03d2a2: /* original e401, guest PC 0x0c03d2a2 */
if(!s->budget--) { s->failed_pc=0x0c03d2a2u; return 0; }
r[4]=0x00000001u;
goto P_0c03d2a4;
P_0c03d2a4: /* original 422b, guest PC 0x0c03d2a4 */
if(!s->budget--) { s->failed_pc=0x0c03d2a4u; return 0; }
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
P_0c03d2a6: /* original 4f26, guest PC 0x0c03d2a6 */
if(!s->budget--) { s->failed_pc=0x0c03d2a6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c03d2a8u,s,ram);
P_0c03da30: /* original 4f22, guest PC 0x0c03da30 */
if(!s->budget--) { s->failed_pc=0x0c03da30u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03da32;
P_0c03da32: /* original 7ff8, guest PC 0x0c03da32 */
if(!s->budget--) { s->failed_pc=0x0c03da32u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c03da34;
P_0c03da34: /* original 2f42, guest PC 0x0c03da34 */
if(!s->budget--) { s->failed_pc=0x0c03da34u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03da36;
P_0c03da36: /* original d37d, guest PC 0x0c03da36 */
if(!s->budget--) { s->failed_pc=0x0c03da36u; return 0; }
r[3]=read(ram,0x0c03dc2cu,4);
goto P_0c03da38;
P_0c03da38: /* original d484, guest PC 0x0c03da38 */
if(!s->budget--) { s->failed_pc=0x0c03da38u; return 0; }
r[4]=read(ram,0x0c03dc4cu,4);
goto P_0c03da3a;
P_0c03da3a: /* original 430b, guest PC 0x0c03da3a */
if(!s->budget--) { s->failed_pc=0x0c03da3au; return 0; }
target=r[3];
r[16]=code_base|0x0c03da3eu;
write(ram,r[15]+4,r[5],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03da3eu) { target=s->pc; goto dispatch; }
goto P_0c03da3e;
P_0c03da3c: /* original 1f51, guest PC 0x0c03da3c */
if(!s->budget--) { s->failed_pc=0x0c03da3cu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c03da3e;
P_0c03da3e: /* original d384, guest PC 0x0c03da3e */
if(!s->budget--) { s->failed_pc=0x0c03da3eu; return 0; }
r[3]=read(ram,0x0c03dc50u,4);
goto P_0c03da40;
P_0c03da40: /* original 55f1, guest PC 0x0c03da40 */
if(!s->budget--) { s->failed_pc=0x0c03da40u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c03da42;
P_0c03da42: /* original 430b, guest PC 0x0c03da42 */
if(!s->budget--) { s->failed_pc=0x0c03da42u; return 0; }
target=r[3];
r[16]=code_base|0x0c03da46u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03da46u) { target=s->pc; goto dispatch; }
goto P_0c03da46;
P_0c03da44: /* original 64f2, guest PC 0x0c03da44 */
if(!s->budget--) { s->failed_pc=0x0c03da44u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c03da46;
P_0c03da46: /* original d280, guest PC 0x0c03da46 */
if(!s->budget--) { s->failed_pc=0x0c03da46u; return 0; }
r[2]=read(ram,0x0c03dc48u,4);
goto P_0c03da48;
P_0c03da48: /* original 7f08, guest PC 0x0c03da48 */
if(!s->budget--) { s->failed_pc=0x0c03da48u; return 0; }
r[15]+=0x00000008u;
goto P_0c03da4a;
P_0c03da4a: /* original e401, guest PC 0x0c03da4a */
if(!s->budget--) { s->failed_pc=0x0c03da4au; return 0; }
r[4]=0x00000001u;
goto P_0c03da4c;
P_0c03da4c: /* original 422b, guest PC 0x0c03da4c */
if(!s->budget--) { s->failed_pc=0x0c03da4cu; return 0; }
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
P_0c03da4e: /* original 4f26, guest PC 0x0c03da4e */
if(!s->budget--) { s->failed_pc=0x0c03da4eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c03da50u,s,ram);
P_0c03ecd0: /* original 4f22, guest PC 0x0c03ecd0 */
if(!s->budget--) { s->failed_pc=0x0c03ecd0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03ecd2;
P_0c03ecd2: /* original 7ffc, guest PC 0x0c03ecd2 */
if(!s->budget--) { s->failed_pc=0x0c03ecd2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03ecd4;
P_0c03ecd4: /* original 2f42, guest PC 0x0c03ecd4 */
if(!s->budget--) { s->failed_pc=0x0c03ecd4u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03ecd6;
P_0c03ecd6: /* original d360, guest PC 0x0c03ecd6 */
if(!s->budget--) { s->failed_pc=0x0c03ecd6u; return 0; }
r[3]=read(ram,0x0c03ee58u,4);
goto P_0c03ecd8;
P_0c03ecd8: /* original f58d, guest PC 0x0c03ecd8 */
if(!s->budget--) { s->failed_pc=0x0c03ecd8u; return 0; }
fr[5]=0;
goto P_0c03ecda;
P_0c03ecda: /* original 430b, guest PC 0x0c03ecda */
if(!s->budget--) { s->failed_pc=0x0c03ecdau; return 0; }
target=r[3];
r[16]=code_base|0x0c03ecdeu;
fr[4]=0;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ecdeu) { target=s->pc; goto dispatch; }
goto P_0c03ecde;
P_0c03ecdc: /* original f48d, guest PC 0x0c03ecdc */
if(!s->budget--) { s->failed_pc=0x0c03ecdcu; return 0; }
fr[4]=0;
goto P_0c03ecde;
P_0c03ecde: /* original d25f, guest PC 0x0c03ecde */
if(!s->budget--) { s->failed_pc=0x0c03ecdeu; return 0; }
r[2]=read(ram,0x0c03ee5cu,4);
goto P_0c03ece0;
P_0c03ece0: /* original 420b, guest PC 0x0c03ece0 */
if(!s->budget--) { s->failed_pc=0x0c03ece0u; return 0; }
target=r[2];
r[16]=code_base|0x0c03ece4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ece4u) { target=s->pc; goto dispatch; }
goto P_0c03ece4;
P_0c03ece2: /* original 0009, guest PC 0x0c03ece2 */
if(!s->budget--) { s->failed_pc=0x0c03ece2u; return 0; }
goto P_0c03ece4;
P_0c03ece4: /* original d35b, guest PC 0x0c03ece4 */
if(!s->budget--) { s->failed_pc=0x0c03ece4u; return 0; }
r[3]=read(ram,0x0c03ee54u,4);
goto P_0c03ece6;
P_0c03ece6: /* original 64f2, guest PC 0x0c03ece6 */
if(!s->budget--) { s->failed_pc=0x0c03ece6u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c03ece8;
P_0c03ece8: /* original 7f04, guest PC 0x0c03ece8 */
if(!s->budget--) { s->failed_pc=0x0c03ece8u; return 0; }
r[15]+=0x00000004u;
goto P_0c03ecea;
P_0c03ecea: /* original 432b, guest PC 0x0c03ecea */
if(!s->budget--) { s->failed_pc=0x0c03eceau; return 0; }
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
P_0c03ecec: /* original 4f26, guest PC 0x0c03ecec */
if(!s->budget--) { s->failed_pc=0x0c03ececu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c03eceeu,s,ram);
P_0c03ed20: /* original 4f22, guest PC 0x0c03ed20 */
if(!s->budget--) { s->failed_pc=0x0c03ed20u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03ed22;
P_0c03ed22: /* original e004, guest PC 0x0c03ed22 */
if(!s->budget--) { s->failed_pc=0x0c03ed22u; return 0; }
r[0]=0x00000004u;
goto P_0c03ed24;
P_0c03ed24: /* original 7ff8, guest PC 0x0c03ed24 */
if(!s->budget--) { s->failed_pc=0x0c03ed24u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c03ed26;
P_0c03ed26: /* original 2f42, guest PC 0x0c03ed26 */
if(!s->budget--) { s->failed_pc=0x0c03ed26u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03ed28;
P_0c03ed28: /* original ff47, guest PC 0x0c03ed28 */
if(!s->budget--) { s->failed_pc=0x0c03ed28u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c03ed2a;
P_0c03ed2a: /* original d34b, guest PC 0x0c03ed2a */
if(!s->budget--) { s->failed_pc=0x0c03ed2au; return 0; }
r[3]=read(ram,0x0c03ee58u,4);
goto P_0c03ed2c;
P_0c03ed2c: /* original f58d, guest PC 0x0c03ed2c */
if(!s->budget--) { s->failed_pc=0x0c03ed2cu; return 0; }
fr[5]=0;
goto P_0c03ed2e;
P_0c03ed2e: /* original 430b, guest PC 0x0c03ed2e */
if(!s->budget--) { s->failed_pc=0x0c03ed2eu; return 0; }
target=r[3];
r[16]=code_base|0x0c03ed32u;
fr[4]=0;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ed32u) { target=s->pc; goto dispatch; }
goto P_0c03ed32;
P_0c03ed30: /* original f48d, guest PC 0x0c03ed30 */
if(!s->budget--) { s->failed_pc=0x0c03ed30u; return 0; }
fr[4]=0;
goto P_0c03ed32;
P_0c03ed32: /* original d24a, guest PC 0x0c03ed32 */
if(!s->budget--) { s->failed_pc=0x0c03ed32u; return 0; }
r[2]=read(ram,0x0c03ee5cu,4);
goto P_0c03ed34;
P_0c03ed34: /* original 420b, guest PC 0x0c03ed34 */
if(!s->budget--) { s->failed_pc=0x0c03ed34u; return 0; }
target=r[2];
r[16]=code_base|0x0c03ed38u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ed38u) { target=s->pc; goto dispatch; }
goto P_0c03ed38;
P_0c03ed36: /* original 0009, guest PC 0x0c03ed36 */
if(!s->budget--) { s->failed_pc=0x0c03ed36u; return 0; }
goto P_0c03ed38;
P_0c03ed38: /* original e004, guest PC 0x0c03ed38 */
if(!s->budget--) { s->failed_pc=0x0c03ed38u; return 0; }
r[0]=0x00000004u;
goto P_0c03ed3a;
P_0c03ed3a: /* original d349, guest PC 0x0c03ed3a */
if(!s->budget--) { s->failed_pc=0x0c03ed3au; return 0; }
r[3]=read(ram,0x0c03ee60u,4);
goto P_0c03ed3c;
P_0c03ed3c: /* original 64f2, guest PC 0x0c03ed3c */
if(!s->budget--) { s->failed_pc=0x0c03ed3cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c03ed3e;
P_0c03ed3e: /* original f4f6, guest PC 0x0c03ed3e */
if(!s->budget--) { s->failed_pc=0x0c03ed3eu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c03ed40;
P_0c03ed40: /* original 7f08, guest PC 0x0c03ed40 */
if(!s->budget--) { s->failed_pc=0x0c03ed40u; return 0; }
r[15]+=0x00000008u;
goto P_0c03ed42;
P_0c03ed42: /* original 432b, guest PC 0x0c03ed42 */
if(!s->budget--) { s->failed_pc=0x0c03ed42u; return 0; }
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
P_0c03ed44: /* original 4f26, guest PC 0x0c03ed44 */
if(!s->budget--) { s->failed_pc=0x0c03ed44u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c03ed46u,s,ram);
P_0c03ef10: /* original 2fe6, guest PC 0x0c03ef10 */
if(!s->budget--) { s->failed_pc=0x0c03ef10u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03ef12;
P_0c03ef12: /* original 2fd6, guest PC 0x0c03ef12 */
if(!s->budget--) { s->failed_pc=0x0c03ef12u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03ef14;
P_0c03ef14: /* original 2fc6, guest PC 0x0c03ef14 */
if(!s->budget--) { s->failed_pc=0x0c03ef14u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03ef16;
P_0c03ef16: /* original 4f22, guest PC 0x0c03ef16 */
if(!s->budget--) { s->failed_pc=0x0c03ef16u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03ef18;
P_0c03ef18: /* original d31e, guest PC 0x0c03ef18 */
if(!s->budget--) { s->failed_pc=0x0c03ef18u; return 0; }
r[3]=read(ram,0x0c03ef94u,4);
goto P_0c03ef1a;
P_0c03ef1a: /* original 430b, guest PC 0x0c03ef1a */
if(!s->budget--) { s->failed_pc=0x0c03ef1au; return 0; }
target=r[3];
r[16]=code_base|0x0c03ef1eu;
r[4]=0x00000002u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ef1eu) { target=s->pc; goto dispatch; }
goto P_0c03ef1e;
P_0c03ef1c: /* original e402, guest PC 0x0c03ef1c */
if(!s->budget--) { s->failed_pc=0x0c03ef1cu; return 0; }
r[4]=0x00000002u;
goto P_0c03ef1e;
P_0c03ef1e: /* original dd1e, guest PC 0x0c03ef1e */
if(!s->budget--) { s->failed_pc=0x0c03ef1eu; return 0; }
r[13]=read(ram,0x0c03ef98u,4);
goto P_0c03ef20;
P_0c03ef20: /* original 4d0b, guest PC 0x0c03ef20 */
if(!s->budget--) { s->failed_pc=0x0c03ef20u; return 0; }
target=r[13];
r[16]=code_base|0x0c03ef24u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ef24u) { target=s->pc; goto dispatch; }
goto P_0c03ef24;
P_0c03ef22: /* original 0009, guest PC 0x0c03ef22 */
if(!s->budget--) { s->failed_pc=0x0c03ef22u; return 0; }
goto P_0c03ef24;
P_0c03ef24: /* original de1d, guest PC 0x0c03ef24 */
if(!s->budget--) { s->failed_pc=0x0c03ef24u; return 0; }
r[14]=read(ram,0x0c03ef9cu,4);
goto P_0c03ef26;
P_0c03ef26: /* original e004, guest PC 0x0c03ef26 */
if(!s->budget--) { s->failed_pc=0x0c03ef26u; return 0; }
r[0]=0x00000004u;
goto P_0c03ef28;
P_0c03ef28: /* original f48d, guest PC 0x0c03ef28 */
if(!s->budget--) { s->failed_pc=0x0c03ef28u; return 0; }
fr[4]=0;
goto P_0c03ef2a;
P_0c03ef2a: /* original 65e3, guest PC 0x0c03ef2a */
if(!s->budget--) { s->failed_pc=0x0c03ef2au; return 0; }
r[5]=r[14];
goto P_0c03ef2c;
P_0c03ef2c: /* original fe4a, guest PC 0x0c03ef2c */
if(!s->budget--) { s->failed_pc=0x0c03ef2cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]);
goto P_0c03ef2e;
P_0c03ef2e: /* original fe47, guest PC 0x0c03ef2e */
if(!s->budget--) { s->failed_pc=0x0c03ef2eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c03ef30;
P_0c03ef30: /* original e008, guest PC 0x0c03ef30 */
if(!s->budget--) { s->failed_pc=0x0c03ef30u; return 0; }
r[0]=0x00000008u;
goto P_0c03ef32;
P_0c03ef32: /* original f39d, guest PC 0x0c03ef32 */
if(!s->budget--) { s->failed_pc=0x0c03ef32u; return 0; }
fr[3]=0x3f800000u;
goto P_0c03ef34;
P_0c03ef34: /* original fe37, guest PC 0x0c03ef34 */
if(!s->budget--) { s->failed_pc=0x0c03ef34u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c03ef36;
P_0c03ef36: /* original dc1a, guest PC 0x0c03ef36 */
if(!s->budget--) { s->failed_pc=0x0c03ef36u; return 0; }
r[12]=read(ram,0x0c03efa0u,4);
goto P_0c03ef38;
P_0c03ef38: /* original 4c0b, guest PC 0x0c03ef38 */
if(!s->budget--) { s->failed_pc=0x0c03ef38u; return 0; }
target=r[12];
r[16]=code_base|0x0c03ef3cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ef3cu) { target=s->pc; goto dispatch; }
goto P_0c03ef3c;
P_0c03ef3a: /* original 64e3, guest PC 0x0c03ef3a */
if(!s->budget--) { s->failed_pc=0x0c03ef3au; return 0; }
r[4]=r[14];
goto P_0c03ef3c;
P_0c03ef3c: /* original 4d0b, guest PC 0x0c03ef3c */
if(!s->budget--) { s->failed_pc=0x0c03ef3cu; return 0; }
target=r[13];
r[16]=code_base|0x0c03ef40u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ef40u) { target=s->pc; goto dispatch; }
goto P_0c03ef40;
P_0c03ef3e: /* original 0009, guest PC 0x0c03ef3e */
if(!s->budget--) { s->failed_pc=0x0c03ef3eu; return 0; }
goto P_0c03ef40;
P_0c03ef40: /* original d314, guest PC 0x0c03ef40 */
if(!s->budget--) { s->failed_pc=0x0c03ef40u; return 0; }
r[3]=read(ram,0x0c03ef94u,4);
goto P_0c03ef42;
P_0c03ef42: /* original 430b, guest PC 0x0c03ef42 */
if(!s->budget--) { s->failed_pc=0x0c03ef42u; return 0; }
target=r[3];
r[16]=code_base|0x0c03ef46u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ef46u) { target=s->pc; goto dispatch; }
goto P_0c03ef46;
P_0c03ef44: /* original e401, guest PC 0x0c03ef44 */
if(!s->budget--) { s->failed_pc=0x0c03ef44u; return 0; }
r[4]=0x00000001u;
goto P_0c03ef46;
P_0c03ef46: /* original 4d0b, guest PC 0x0c03ef46 */
if(!s->budget--) { s->failed_pc=0x0c03ef46u; return 0; }
target=r[13];
r[16]=code_base|0x0c03ef4au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ef4au) { target=s->pc; goto dispatch; }
goto P_0c03ef4a;
P_0c03ef48: /* original 0009, guest PC 0x0c03ef48 */
if(!s->budget--) { s->failed_pc=0x0c03ef48u; return 0; }
goto P_0c03ef4a;
P_0c03ef4a: /* original d416, guest PC 0x0c03ef4a */
if(!s->budget--) { s->failed_pc=0x0c03ef4au; return 0; }
r[4]=read(ram,0x0c03efa4u,4);
goto P_0c03ef4c;
P_0c03ef4c: /* original 65e3, guest PC 0x0c03ef4c */
if(!s->budget--) { s->failed_pc=0x0c03ef4cu; return 0; }
r[5]=r[14];
goto P_0c03ef4e;
P_0c03ef4e: /* original 4c0b, guest PC 0x0c03ef4e */
if(!s->budget--) { s->failed_pc=0x0c03ef4eu; return 0; }
target=r[12];
r[16]=code_base|0x0c03ef52u;
r[5]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ef52u) { target=s->pc; goto dispatch; }
goto P_0c03ef52;
P_0c03ef50: /* original 7510, guest PC 0x0c03ef50 */
if(!s->budget--) { s->failed_pc=0x0c03ef50u; return 0; }
r[5]+=0x00000010u;
goto P_0c03ef52;
P_0c03ef52: /* original d414, guest PC 0x0c03ef52 */
if(!s->budget--) { s->failed_pc=0x0c03ef52u; return 0; }
r[4]=read(ram,0x0c03efa4u,4);
goto P_0c03ef54;
P_0c03ef54: /* original e004, guest PC 0x0c03ef54 */
if(!s->budget--) { s->failed_pc=0x0c03ef54u; return 0; }
r[0]=0x00000004u;
goto P_0c03ef56;
P_0c03ef56: /* original f2e8, guest PC 0x0c03ef56 */
if(!s->budget--) { s->failed_pc=0x0c03ef56u; return 0; }
vf3_matrix_load(s,ram,2,r[14]);
goto P_0c03ef58;
P_0c03ef58: /* original 6103, guest PC 0x0c03ef58 */
if(!s->budget--) { s->failed_pc=0x0c03ef58u; return 0; }
r[1]=r[0];
goto P_0c03ef5a;
P_0c03ef5a: /* original f348, guest PC 0x0c03ef5a */
if(!s->budget--) { s->failed_pc=0x0c03ef5au; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c03ef5c;
P_0c03ef5c: /* original 314c, guest PC 0x0c03ef5c */
if(!s->budget--) { s->failed_pc=0x0c03ef5cu; return 0; }
r[1]+=r[4];
goto P_0c03ef5e;
P_0c03ef5e: /* original 65e3, guest PC 0x0c03ef5e */
if(!s->budget--) { s->failed_pc=0x0c03ef5eu; return 0; }
r[5]=r[14];
goto P_0c03ef60;
P_0c03ef60: /* original f230, guest PC 0x0c03ef60 */
if(!s->budget--) { s->failed_pc=0x0c03ef60u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c03ef62;
P_0c03ef62: /* original fe2a, guest PC 0x0c03ef62 */
if(!s->budget--) { s->failed_pc=0x0c03ef62u; return 0; }
vf3_matrix_store(s,ram,2,r[14]);
goto P_0c03ef64;
P_0c03ef64: /* original f2e6, guest PC 0x0c03ef64 */
if(!s->budget--) { s->failed_pc=0x0c03ef64u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c03ef66;
P_0c03ef66: /* original f318, guest PC 0x0c03ef66 */
if(!s->budget--) { s->failed_pc=0x0c03ef66u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c03ef68;
P_0c03ef68: /* original f230, guest PC 0x0c03ef68 */
if(!s->budget--) { s->failed_pc=0x0c03ef68u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c03ef6a;
P_0c03ef6a: /* original fe27, guest PC 0x0c03ef6a */
if(!s->budget--) { s->failed_pc=0x0c03ef6au; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c03ef6c;
P_0c03ef6c: /* original e008, guest PC 0x0c03ef6c */
if(!s->budget--) { s->failed_pc=0x0c03ef6cu; return 0; }
r[0]=0x00000008u;
goto P_0c03ef6e;
P_0c03ef6e: /* original 6103, guest PC 0x0c03ef6e */
if(!s->budget--) { s->failed_pc=0x0c03ef6eu; return 0; }
r[1]=r[0];
goto P_0c03ef70;
P_0c03ef70: /* original 314c, guest PC 0x0c03ef70 */
if(!s->budget--) { s->failed_pc=0x0c03ef70u; return 0; }
r[1]+=r[4];
goto P_0c03ef72;
P_0c03ef72: /* original f2e6, guest PC 0x0c03ef72 */
if(!s->budget--) { s->failed_pc=0x0c03ef72u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c03ef74;
P_0c03ef74: /* original f318, guest PC 0x0c03ef74 */
if(!s->budget--) { s->failed_pc=0x0c03ef74u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c03ef76;
P_0c03ef76: /* original f230, guest PC 0x0c03ef76 */
if(!s->budget--) { s->failed_pc=0x0c03ef76u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c03ef78;
P_0c03ef78: /* original fe27, guest PC 0x0c03ef78 */
if(!s->budget--) { s->failed_pc=0x0c03ef78u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c03ef7a;
P_0c03ef7a: /* original 4c0b, guest PC 0x0c03ef7a */
if(!s->budget--) { s->failed_pc=0x0c03ef7au; return 0; }
target=r[12];
r[16]=code_base|0x0c03ef7eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ef7eu) { target=s->pc; goto dispatch; }
goto P_0c03ef7e;
P_0c03ef7c: /* original 64e3, guest PC 0x0c03ef7c */
if(!s->budget--) { s->failed_pc=0x0c03ef7cu; return 0; }
r[4]=r[14];
goto P_0c03ef7e;
P_0c03ef7e: /* original d30a, guest PC 0x0c03ef7e */
if(!s->budget--) { s->failed_pc=0x0c03ef7eu; return 0; }
r[3]=read(ram,0x0c03efa8u,4);
goto P_0c03ef80;
P_0c03ef80: /* original 430b, guest PC 0x0c03ef80 */
if(!s->budget--) { s->failed_pc=0x0c03ef80u; return 0; }
target=r[3];
r[16]=code_base|0x0c03ef84u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ef84u) { target=s->pc; goto dispatch; }
goto P_0c03ef84;
P_0c03ef82: /* original 64e3, guest PC 0x0c03ef82 */
if(!s->budget--) { s->failed_pc=0x0c03ef82u; return 0; }
r[4]=r[14];
goto P_0c03ef84;
P_0c03ef84: /* original 4d0b, guest PC 0x0c03ef84 */
if(!s->budget--) { s->failed_pc=0x0c03ef84u; return 0; }
target=r[13];
r[16]=code_base|0x0c03ef88u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ef88u) { target=s->pc; goto dispatch; }
goto P_0c03ef88;
P_0c03ef86: /* original 0009, guest PC 0x0c03ef86 */
if(!s->budget--) { s->failed_pc=0x0c03ef86u; return 0; }
goto P_0c03ef88;
P_0c03ef88: /* original 4f26, guest PC 0x0c03ef88 */
if(!s->budget--) { s->failed_pc=0x0c03ef88u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03ef8a;
P_0c03ef8a: /* original 6cf6, guest PC 0x0c03ef8a */
if(!s->budget--) { s->failed_pc=0x0c03ef8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03ef8c;
P_0c03ef8c: /* original 6df6, guest PC 0x0c03ef8c */
if(!s->budget--) { s->failed_pc=0x0c03ef8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03ef8e;
P_0c03ef8e: /* original 000b, guest PC 0x0c03ef8e */
if(!s->budget--) { s->failed_pc=0x0c03ef8eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03ef90: /* original 6ef6, guest PC 0x0c03ef90 */
if(!s->budget--) { s->failed_pc=0x0c03ef90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03ef92u,s,ram);
P_0c03ffb0: /* original 4f22, guest PC 0x0c03ffb0 */
if(!s->budget--) { s->failed_pc=0x0c03ffb0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03ffb2;
P_0c03ffb2: /* original d331, guest PC 0x0c03ffb2 */
if(!s->budget--) { s->failed_pc=0x0c03ffb2u; return 0; }
r[3]=read(ram,0x0c040078u,4);
goto P_0c03ffb4;
P_0c03ffb4: /* original 430b, guest PC 0x0c03ffb4 */
if(!s->budget--) { s->failed_pc=0x0c03ffb4u; return 0; }
target=r[3];
r[16]=code_base|0x0c03ffb8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03ffb8u) { target=s->pc; goto dispatch; }
goto P_0c03ffb8;
P_0c03ffb6: /* original 0009, guest PC 0x0c03ffb6 */
if(!s->budget--) { s->failed_pc=0x0c03ffb6u; return 0; }
goto P_0c03ffb8;
P_0c03ffb8: /* original d230, guest PC 0x0c03ffb8 */
if(!s->budget--) { s->failed_pc=0x0c03ffb8u; return 0; }
r[2]=read(ram,0x0c04007cu,4);
goto P_0c03ffba;
P_0c03ffba: /* original e401, guest PC 0x0c03ffba */
if(!s->budget--) { s->failed_pc=0x0c03ffbau; return 0; }
r[4]=0x00000001u;
goto P_0c03ffbc;
P_0c03ffbc: /* original 422b, guest PC 0x0c03ffbc */
if(!s->budget--) { s->failed_pc=0x0c03ffbcu; return 0; }
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
P_0c03ffbe: /* original 4f26, guest PC 0x0c03ffbe */
if(!s->budget--) { s->failed_pc=0x0c03ffbeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c03ffc0u,s,ram);
P_0c043e52: /* original 0002, guest PC 0x0c043e52 */
if(!s->budget--) { s->failed_pc=0x0c043e52u; return 0; }
r[0]=r[17];
goto P_0c043e54;
P_0c043e54: /* original 2fe6, guest PC 0x0c043e54 */
if(!s->budget--) { s->failed_pc=0x0c043e54u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043e56;
P_0c043e56: /* original 2fd6, guest PC 0x0c043e56 */
if(!s->budget--) { s->failed_pc=0x0c043e56u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043e58;
P_0c043e58: /* original 4f22, guest PC 0x0c043e58 */
if(!s->budget--) { s->failed_pc=0x0c043e58u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043e5a;
P_0c043e5a: /* original 4009, guest PC 0x0c043e5a */
if(!s->budget--) { s->failed_pc=0x0c043e5au; return 0; }
r[0]>>=2;
goto P_0c043e5c;
P_0c043e5c: /* original 4009, guest PC 0x0c043e5c */
if(!s->budget--) { s->failed_pc=0x0c043e5cu; return 0; }
r[0]>>=2;
goto P_0c043e5e;
P_0c043e5e: /* original c90f, guest PC 0x0c043e5e */
if(!s->budget--) { s->failed_pc=0x0c043e5eu; return 0; }
r[0]&=15u;
goto P_0c043e60;
P_0c043e60: /* original 7ffc, guest PC 0x0c043e60 */
if(!s->budget--) { s->failed_pc=0x0c043e60u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c043e62;
P_0c043e62: /* original 2f02, guest PC 0x0c043e62 */
if(!s->budget--) { s->failed_pc=0x0c043e62u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c043e64;
P_0c043e64: /* original 0002, guest PC 0x0c043e64 */
if(!s->budget--) { s->failed_pc=0x0c043e64u; return 0; }
r[0]=r[17];
goto P_0c043e66;
P_0c043e66: /* original 9343, guest PC 0x0c043e66 */
if(!s->budget--) { s->failed_pc=0x0c043e66u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043ef0u,2);
goto P_0c043e68;
P_0c043e68: /* original 2039, guest PC 0x0c043e68 */
if(!s->budget--) { s->failed_pc=0x0c043e68u; return 0; }
r[0]&=r[3];
goto P_0c043e6a;
P_0c043e6a: /* original cbf0, guest PC 0x0c043e6a */
if(!s->budget--) { s->failed_pc=0x0c043e6au; return 0; }
r[0]|=240u;
goto P_0c043e6c;
P_0c043e6c: /* original 400e, guest PC 0x0c043e6c */
if(!s->budget--) { s->failed_pc=0x0c043e6cu; return 0; }
r[17]=r[0];
goto P_0c043e6e;
P_0c043e6e: /* original 9240, guest PC 0x0c043e6e */
if(!s->budget--) { s->failed_pc=0x0c043e6eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043ef2u,2);
goto P_0c043e70;
P_0c043e70: /* original d328, guest PC 0x0c043e70 */
if(!s->budget--) { s->failed_pc=0x0c043e70u; return 0; }
r[3]=read(ram,0x0c043f14u,4);
goto P_0c043e72;
P_0c043e72: /* original 6132, guest PC 0x0c043e72 */
if(!s->budget--) { s->failed_pc=0x0c043e72u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c043e74;
P_0c043e74: /* original 2129, guest PC 0x0c043e74 */
if(!s->budget--) { s->failed_pc=0x0c043e74u; return 0; }
r[1]&=r[2];
goto P_0c043e76;
P_0c043e76: /* original 2312, guest PC 0x0c043e76 */
if(!s->budget--) { s->failed_pc=0x0c043e76u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c043e78;
P_0c043e78: /* original de28, guest PC 0x0c043e78 */
if(!s->budget--) { s->failed_pc=0x0c043e78u; return 0; }
r[14]=read(ram,0x0c043f1cu,4);
goto P_0c043e7a;
P_0c043e7a: /* original dd27, guest PC 0x0c043e7a */
if(!s->budget--) { s->failed_pc=0x0c043e7au; return 0; }
r[13]=read(ram,0x0c043f18u,4);
goto P_0c043e7c;
P_0c043e7c: /* original 4d0b, guest PC 0x0c043e7c */
if(!s->budget--) { s->failed_pc=0x0c043e7cu; return 0; }
target=r[13];
r[16]=code_base|0x0c043e80u;
r[4]=read(ram,r[14]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043e80u) { target=s->pc; goto dispatch; }
goto P_0c043e80;
P_0c043e7e: /* original 54e3, guest PC 0x0c043e7e */
if(!s->budget--) { s->failed_pc=0x0c043e7eu; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c043e80;
P_0c043e80: /* original 4d0b, guest PC 0x0c043e80 */
if(!s->budget--) { s->failed_pc=0x0c043e80u; return 0; }
target=r[13];
r[16]=code_base|0x0c043e84u;
r[4]=read(ram,r[14]+16,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043e84u) { target=s->pc; goto dispatch; }
goto P_0c043e84;
P_0c043e82: /* original 54e4, guest PC 0x0c043e82 */
if(!s->budget--) { s->failed_pc=0x0c043e82u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c043e84;
P_0c043e84: /* original 4d0b, guest PC 0x0c043e84 */
if(!s->budget--) { s->failed_pc=0x0c043e84u; return 0; }
target=r[13];
r[16]=code_base|0x0c043e88u;
r[4]=read(ram,r[14]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043e88u) { target=s->pc; goto dispatch; }
goto P_0c043e88;
P_0c043e86: /* original 54e2, guest PC 0x0c043e86 */
if(!s->budget--) { s->failed_pc=0x0c043e86u; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c043e88;
P_0c043e88: /* original 4d0b, guest PC 0x0c043e88 */
if(!s->budget--) { s->failed_pc=0x0c043e88u; return 0; }
target=r[13];
r[16]=code_base|0x0c043e8cu;
r[4]=read(ram,r[14]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043e8cu) { target=s->pc; goto dispatch; }
goto P_0c043e8c;
P_0c043e8a: /* original 54e1, guest PC 0x0c043e8a */
if(!s->budget--) { s->failed_pc=0x0c043e8au; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c043e8c;
P_0c043e8c: /* original d324, guest PC 0x0c043e8c */
if(!s->budget--) { s->failed_pc=0x0c043e8cu; return 0; }
r[3]=read(ram,0x0c043f20u,4);
goto P_0c043e8e;
P_0c043e8e: /* original 430b, guest PC 0x0c043e8e */
if(!s->budget--) { s->failed_pc=0x0c043e8eu; return 0; }
target=r[3];
r[16]=code_base|0x0c043e92u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043e92u) { target=s->pc; goto dispatch; }
goto P_0c043e92;
P_0c043e90: /* original 0009, guest PC 0x0c043e90 */
if(!s->budget--) { s->failed_pc=0x0c043e90u; return 0; }
goto P_0c043e92;
P_0c043e92: /* original d225, guest PC 0x0c043e92 */
if(!s->budget--) { s->failed_pc=0x0c043e92u; return 0; }
r[2]=read(ram,0x0c043f28u,4);
goto P_0c043e94;
P_0c043e94: /* original d423, guest PC 0x0c043e94 */
if(!s->budget--) { s->failed_pc=0x0c043e94u; return 0; }
r[4]=read(ram,0x0c043f24u,4);
goto P_0c043e96;
P_0c043e96: /* original 962d, guest PC 0x0c043e96 */
if(!s->budget--) { s->failed_pc=0x0c043e96u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043ef4u,2);
goto P_0c043e98;
P_0c043e98: /* original 420b, guest PC 0x0c043e98 */
if(!s->budget--) { s->failed_pc=0x0c043e98u; return 0; }
target=r[2];
r[16]=code_base|0x0c043e9cu;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043e9cu) { target=s->pc; goto dispatch; }
goto P_0c043e9c;
P_0c043e9a: /* original e500, guest PC 0x0c043e9a */
if(!s->budget--) { s->failed_pc=0x0c043e9au; return 0; }
r[5]=0x00000000u;
goto P_0c043e9c;
P_0c043e9c: /* original 60f2, guest PC 0x0c043e9c */
if(!s->budget--) { s->failed_pc=0x0c043e9cu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c043e9e;
P_0c043e9e: /* original 0302, guest PC 0x0c043e9e */
if(!s->budget--) { s->failed_pc=0x0c043e9eu; return 0; }
r[3]=r[17];
goto P_0c043ea0;
P_0c043ea0: /* original 9226, guest PC 0x0c043ea0 */
if(!s->budget--) { s->failed_pc=0x0c043ea0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c043ef0u,2);
goto P_0c043ea2;
P_0c043ea2: /* original c90f, guest PC 0x0c043ea2 */
if(!s->budget--) { s->failed_pc=0x0c043ea2u; return 0; }
r[0]&=15u;
goto P_0c043ea4;
P_0c043ea4: /* original 4008, guest PC 0x0c043ea4 */
if(!s->budget--) { s->failed_pc=0x0c043ea4u; return 0; }
r[0]<<=2;
goto P_0c043ea6;
P_0c043ea6: /* original 2329, guest PC 0x0c043ea6 */
if(!s->budget--) { s->failed_pc=0x0c043ea6u; return 0; }
r[3]&=r[2];
goto P_0c043ea8;
P_0c043ea8: /* original 4008, guest PC 0x0c043ea8 */
if(!s->budget--) { s->failed_pc=0x0c043ea8u; return 0; }
r[0]<<=2;
goto P_0c043eaa;
P_0c043eaa: /* original 203b, guest PC 0x0c043eaa */
if(!s->budget--) { s->failed_pc=0x0c043eaau; return 0; }
r[0]|=r[3];
goto P_0c043eac;
P_0c043eac: /* original 400e, guest PC 0x0c043eac */
if(!s->budget--) { s->failed_pc=0x0c043eacu; return 0; }
r[17]=r[0];
goto P_0c043eae;
P_0c043eae: /* original 7f04, guest PC 0x0c043eae */
if(!s->budget--) { s->failed_pc=0x0c043eaeu; return 0; }
r[15]+=0x00000004u;
goto P_0c043eb0;
P_0c043eb0: /* original 4f26, guest PC 0x0c043eb0 */
if(!s->budget--) { s->failed_pc=0x0c043eb0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043eb2;
P_0c043eb2: /* original 6df6, guest PC 0x0c043eb2 */
if(!s->budget--) { s->failed_pc=0x0c043eb2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c043eb4;
P_0c043eb4: /* original 000b, guest PC 0x0c043eb4 */
if(!s->budget--) { s->failed_pc=0x0c043eb4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c043eb6: /* original 6ef6, guest PC 0x0c043eb6 */
if(!s->budget--) { s->failed_pc=0x0c043eb6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c043eb8u,s,ram);
P_0c0459bc: /* original 4f22, guest PC 0x0c0459bc */
if(!s->budget--) { s->failed_pc=0x0c0459bcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0459be;
P_0c0459be: /* original 6032, guest PC 0x0c0459be */
if(!s->budget--) { s->failed_pc=0x0c0459beu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0459c0;
P_0c0459c0: /* original 401b, guest PC 0x0c0459c0 */
if(!s->budget--) { s->failed_pc=0x0c0459c0u; return 0; }
tmp=read(ram,r[0],1);
r[17]=(r[17]&~1u)|((tmp==0)!=0);
write(ram,r[0],tmp|0x80u,1);
goto P_0c0459c2;
P_0c0459c2: /* original 8907, guest PC 0x0c0459c2 */
if(!s->budget--) { s->failed_pc=0x0c0459c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0459d4; }
goto P_0c0459c4;
P_0c0459c4: /* original d20c, guest PC 0x0c0459c4 */
if(!s->budget--) { s->failed_pc=0x0c0459c4u; return 0; }
r[2]=read(ram,0x0c0459f8u,4);
goto P_0c0459c6;
P_0c0459c6: /* original d10b, guest PC 0x0c0459c6 */
if(!s->budget--) { s->failed_pc=0x0c0459c6u; return 0; }
r[1]=read(ram,0x0c0459f4u,4);
goto P_0c0459c8;
P_0c0459c8: /* original 420b, guest PC 0x0c0459c8 */
if(!s->budget--) { s->failed_pc=0x0c0459c8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0459ccu;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0459ccu) { target=s->pc; goto dispatch; }
goto P_0c0459cc;
P_0c0459ca: /* original 2f16, guest PC 0x0c0459ca */
if(!s->budget--) { s->failed_pc=0x0c0459cau; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0459cc;
P_0c0459cc: /* original 7f04, guest PC 0x0c0459cc */
if(!s->budget--) { s->failed_pc=0x0c0459ccu; return 0; }
r[15]+=0x00000004u;
goto P_0c0459ce;
P_0c0459ce: /* original 4f26, guest PC 0x0c0459ce */
if(!s->budget--) { s->failed_pc=0x0c0459ceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0459d0;
P_0c0459d0: /* original 000b, guest PC 0x0c0459d0 */
if(!s->budget--) { s->failed_pc=0x0c0459d0u; return 0; }
target=r[16];
r[0]=0xfffffffeu;
s->pc=target; return ram->oob==0;
P_0c0459d2: /* original e0fe, guest PC 0x0c0459d2 */
if(!s->budget--) { s->failed_pc=0x0c0459d2u; return 0; }
r[0]=0xfffffffeu;
goto P_0c0459d4;
P_0c0459d4: /* original b012, guest PC 0x0c0459d4 */
if(!s->budget--) { s->failed_pc=0x0c0459d4u; return 0; }
target=0x0c0459fcu; r[16]=code_base|0x0c0459d8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0459d8u) { target=s->pc; goto dispatch; }
goto P_0c0459d8;
P_0c0459d6: /* original 0009, guest PC 0x0c0459d6 */
if(!s->budget--) { s->failed_pc=0x0c0459d6u; return 0; }
goto P_0c0459d8;
P_0c0459d8: /* original d305, guest PC 0x0c0459d8 */
if(!s->budget--) { s->failed_pc=0x0c0459d8u; return 0; }
r[3]=read(ram,0x0c0459f0u,4);
goto P_0c0459da;
P_0c0459da: /* original e100, guest PC 0x0c0459da */
if(!s->budget--) { s->failed_pc=0x0c0459dau; return 0; }
r[1]=0x00000000u;
goto P_0c0459dc;
P_0c0459dc: /* original 6232, guest PC 0x0c0459dc */
if(!s->budget--) { s->failed_pc=0x0c0459dcu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0459de;
P_0c0459de: /* original 2210, guest PC 0x0c0459de */
if(!s->budget--) { s->failed_pc=0x0c0459deu; return 0; }
write(ram,r[2],r[1],1);
goto P_0c0459e0;
P_0c0459e0: /* original 4f26, guest PC 0x0c0459e0 */
if(!s->budget--) { s->failed_pc=0x0c0459e0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0459e2;
P_0c0459e2: /* original 000b, guest PC 0x0c0459e2 */
if(!s->budget--) { s->failed_pc=0x0c0459e2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0459e4: /* original 0009, guest PC 0x0c0459e4 */
if(!s->budget--) { s->failed_pc=0x0c0459e4u; return 0; }
return vf3_matrix_family(0x0c0459e6u,s,ram);
P_0c045a34: /* original 4f22, guest PC 0x0c045a34 */
if(!s->budget--) { s->failed_pc=0x0c045a34u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045a36;
P_0c045a36: /* original 6032, guest PC 0x0c045a36 */
if(!s->budget--) { s->failed_pc=0x0c045a36u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c045a38;
P_0c045a38: /* original 401b, guest PC 0x0c045a38 */
if(!s->budget--) { s->failed_pc=0x0c045a38u; return 0; }
tmp=read(ram,r[0],1);
r[17]=(r[17]&~1u)|((tmp==0)!=0);
write(ram,r[0],tmp|0x80u,1);
goto P_0c045a3a;
P_0c045a3a: /* original 8907, guest PC 0x0c045a3a */
if(!s->budget--) { s->failed_pc=0x0c045a3au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c045a4c; }
goto P_0c045a3c;
P_0c045a3c: /* original d28a, guest PC 0x0c045a3c */
if(!s->budget--) { s->failed_pc=0x0c045a3cu; return 0; }
r[2]=read(ram,0x0c045c68u,4);
goto P_0c045a3e;
P_0c045a3e: /* original d18c, guest PC 0x0c045a3e */
if(!s->budget--) { s->failed_pc=0x0c045a3eu; return 0; }
r[1]=read(ram,0x0c045c70u,4);
goto P_0c045a40;
P_0c045a40: /* original 420b, guest PC 0x0c045a40 */
if(!s->budget--) { s->failed_pc=0x0c045a40u; return 0; }
target=r[2];
r[16]=code_base|0x0c045a44u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045a44u) { target=s->pc; goto dispatch; }
goto P_0c045a44;
P_0c045a42: /* original 2f16, guest PC 0x0c045a42 */
if(!s->budget--) { s->failed_pc=0x0c045a42u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045a44;
P_0c045a44: /* original 7f04, guest PC 0x0c045a44 */
if(!s->budget--) { s->failed_pc=0x0c045a44u; return 0; }
r[15]+=0x00000004u;
goto P_0c045a46;
P_0c045a46: /* original 4f26, guest PC 0x0c045a46 */
if(!s->budget--) { s->failed_pc=0x0c045a46u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045a48;
P_0c045a48: /* original 000b, guest PC 0x0c045a48 */
if(!s->budget--) { s->failed_pc=0x0c045a48u; return 0; }
target=r[16];
r[0]=0xfffffffeu;
s->pc=target; return ram->oob==0;
P_0c045a4a: /* original e0fe, guest PC 0x0c045a4a */
if(!s->budget--) { s->failed_pc=0x0c045a4au; return 0; }
r[0]=0xfffffffeu;
goto P_0c045a4c;
P_0c045a4c: /* original b007, guest PC 0x0c045a4c */
if(!s->budget--) { s->failed_pc=0x0c045a4cu; return 0; }
target=0x0c045a5eu; r[16]=code_base|0x0c045a50u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045a50u) { target=s->pc; goto dispatch; }
goto P_0c045a50;
P_0c045a4e: /* original 0009, guest PC 0x0c045a4e */
if(!s->budget--) { s->failed_pc=0x0c045a4eu; return 0; }
goto P_0c045a50;
P_0c045a50: /* original d386, guest PC 0x0c045a50 */
if(!s->budget--) { s->failed_pc=0x0c045a50u; return 0; }
r[3]=read(ram,0x0c045c6cu,4);
goto P_0c045a52;
P_0c045a52: /* original e100, guest PC 0x0c045a52 */
if(!s->budget--) { s->failed_pc=0x0c045a52u; return 0; }
r[1]=0x00000000u;
goto P_0c045a54;
P_0c045a54: /* original 6232, guest PC 0x0c045a54 */
if(!s->budget--) { s->failed_pc=0x0c045a54u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c045a56;
P_0c045a56: /* original 2210, guest PC 0x0c045a56 */
if(!s->budget--) { s->failed_pc=0x0c045a56u; return 0; }
write(ram,r[2],r[1],1);
goto P_0c045a58;
P_0c045a58: /* original 4f26, guest PC 0x0c045a58 */
if(!s->budget--) { s->failed_pc=0x0c045a58u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045a5a;
P_0c045a5a: /* original 000b, guest PC 0x0c045a5a */
if(!s->budget--) { s->failed_pc=0x0c045a5au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c045a5c: /* original 0009, guest PC 0x0c045a5c */
if(!s->budget--) { s->failed_pc=0x0c045a5cu; return 0; }
return vf3_matrix_family(0x0c045a5eu,s,ram);
P_0c045a8a: /* original 4f22, guest PC 0x0c045a8a */
if(!s->budget--) { s->failed_pc=0x0c045a8au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045a8c;
P_0c045a8c: /* original 6032, guest PC 0x0c045a8c */
if(!s->budget--) { s->failed_pc=0x0c045a8cu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c045a8e;
P_0c045a8e: /* original 401b, guest PC 0x0c045a8e */
if(!s->budget--) { s->failed_pc=0x0c045a8eu; return 0; }
tmp=read(ram,r[0],1);
r[17]=(r[17]&~1u)|((tmp==0)!=0);
write(ram,r[0],tmp|0x80u,1);
goto P_0c045a90;
P_0c045a90: /* original 8907, guest PC 0x0c045a90 */
if(!s->budget--) { s->failed_pc=0x0c045a90u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c045aa2; }
goto P_0c045a92;
P_0c045a92: /* original d275, guest PC 0x0c045a92 */
if(!s->budget--) { s->failed_pc=0x0c045a92u; return 0; }
r[2]=read(ram,0x0c045c68u,4);
goto P_0c045a94;
P_0c045a94: /* original d176, guest PC 0x0c045a94 */
if(!s->budget--) { s->failed_pc=0x0c045a94u; return 0; }
r[1]=read(ram,0x0c045c70u,4);
goto P_0c045a96;
P_0c045a96: /* original 420b, guest PC 0x0c045a96 */
if(!s->budget--) { s->failed_pc=0x0c045a96u; return 0; }
target=r[2];
r[16]=code_base|0x0c045a9au;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045a9au) { target=s->pc; goto dispatch; }
goto P_0c045a9a;
P_0c045a98: /* original 2f16, guest PC 0x0c045a98 */
if(!s->budget--) { s->failed_pc=0x0c045a98u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045a9a;
P_0c045a9a: /* original 7f04, guest PC 0x0c045a9a */
if(!s->budget--) { s->failed_pc=0x0c045a9au; return 0; }
r[15]+=0x00000004u;
goto P_0c045a9c;
P_0c045a9c: /* original 4f26, guest PC 0x0c045a9c */
if(!s->budget--) { s->failed_pc=0x0c045a9cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045a9e;
P_0c045a9e: /* original 000b, guest PC 0x0c045a9e */
if(!s->budget--) { s->failed_pc=0x0c045a9eu; return 0; }
target=r[16];
r[0]=0xfffffffeu;
s->pc=target; return ram->oob==0;
P_0c045aa0: /* original e0fe, guest PC 0x0c045aa0 */
if(!s->budget--) { s->failed_pc=0x0c045aa0u; return 0; }
r[0]=0xfffffffeu;
goto P_0c045aa2;
P_0c045aa2: /* original b007, guest PC 0x0c045aa2 */
if(!s->budget--) { s->failed_pc=0x0c045aa2u; return 0; }
target=0x0c045ab4u; r[16]=code_base|0x0c045aa6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045aa6u) { target=s->pc; goto dispatch; }
goto P_0c045aa6;
P_0c045aa4: /* original 0009, guest PC 0x0c045aa4 */
if(!s->budget--) { s->failed_pc=0x0c045aa4u; return 0; }
goto P_0c045aa6;
P_0c045aa6: /* original d371, guest PC 0x0c045aa6 */
if(!s->budget--) { s->failed_pc=0x0c045aa6u; return 0; }
r[3]=read(ram,0x0c045c6cu,4);
goto P_0c045aa8;
P_0c045aa8: /* original e100, guest PC 0x0c045aa8 */
if(!s->budget--) { s->failed_pc=0x0c045aa8u; return 0; }
r[1]=0x00000000u;
goto P_0c045aaa;
P_0c045aaa: /* original 6232, guest PC 0x0c045aaa */
if(!s->budget--) { s->failed_pc=0x0c045aaau; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c045aac;
P_0c045aac: /* original 2210, guest PC 0x0c045aac */
if(!s->budget--) { s->failed_pc=0x0c045aacu; return 0; }
write(ram,r[2],r[1],1);
goto P_0c045aae;
P_0c045aae: /* original 4f26, guest PC 0x0c045aae */
if(!s->budget--) { s->failed_pc=0x0c045aaeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045ab0;
P_0c045ab0: /* original 000b, guest PC 0x0c045ab0 */
if(!s->budget--) { s->failed_pc=0x0c045ab0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c045ab2: /* original 0009, guest PC 0x0c045ab2 */
if(!s->budget--) { s->failed_pc=0x0c045ab2u; return 0; }
return vf3_matrix_family(0x0c045ab4u,s,ram);
P_0c045ae0: /* original 4f22, guest PC 0x0c045ae0 */
if(!s->budget--) { s->failed_pc=0x0c045ae0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045ae2;
P_0c045ae2: /* original 6032, guest PC 0x0c045ae2 */
if(!s->budget--) { s->failed_pc=0x0c045ae2u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c045ae4;
P_0c045ae4: /* original 401b, guest PC 0x0c045ae4 */
if(!s->budget--) { s->failed_pc=0x0c045ae4u; return 0; }
tmp=read(ram,r[0],1);
r[17]=(r[17]&~1u)|((tmp==0)!=0);
write(ram,r[0],tmp|0x80u,1);
goto P_0c045ae6;
P_0c045ae6: /* original 8907, guest PC 0x0c045ae6 */
if(!s->budget--) { s->failed_pc=0x0c045ae6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c045af8; }
goto P_0c045ae8;
P_0c045ae8: /* original d25f, guest PC 0x0c045ae8 */
if(!s->budget--) { s->failed_pc=0x0c045ae8u; return 0; }
r[2]=read(ram,0x0c045c68u,4);
goto P_0c045aea;
P_0c045aea: /* original d161, guest PC 0x0c045aea */
if(!s->budget--) { s->failed_pc=0x0c045aeau; return 0; }
r[1]=read(ram,0x0c045c70u,4);
goto P_0c045aec;
P_0c045aec: /* original 420b, guest PC 0x0c045aec */
if(!s->budget--) { s->failed_pc=0x0c045aecu; return 0; }
target=r[2];
r[16]=code_base|0x0c045af0u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045af0u) { target=s->pc; goto dispatch; }
goto P_0c045af0;
P_0c045aee: /* original 2f16, guest PC 0x0c045aee */
if(!s->budget--) { s->failed_pc=0x0c045aeeu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045af0;
P_0c045af0: /* original 7f04, guest PC 0x0c045af0 */
if(!s->budget--) { s->failed_pc=0x0c045af0u; return 0; }
r[15]+=0x00000004u;
goto P_0c045af2;
P_0c045af2: /* original 4f26, guest PC 0x0c045af2 */
if(!s->budget--) { s->failed_pc=0x0c045af2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045af4;
P_0c045af4: /* original 000b, guest PC 0x0c045af4 */
if(!s->budget--) { s->failed_pc=0x0c045af4u; return 0; }
target=r[16];
r[0]=0xfffffffeu;
s->pc=target; return ram->oob==0;
P_0c045af6: /* original e0fe, guest PC 0x0c045af6 */
if(!s->budget--) { s->failed_pc=0x0c045af6u; return 0; }
r[0]=0xfffffffeu;
goto P_0c045af8;
P_0c045af8: /* original b007, guest PC 0x0c045af8 */
if(!s->budget--) { s->failed_pc=0x0c045af8u; return 0; }
target=0x0c045b0au; r[16]=code_base|0x0c045afcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045afcu) { target=s->pc; goto dispatch; }
goto P_0c045afc;
P_0c045afa: /* original 0009, guest PC 0x0c045afa */
if(!s->budget--) { s->failed_pc=0x0c045afau; return 0; }
goto P_0c045afc;
P_0c045afc: /* original d35b, guest PC 0x0c045afc */
if(!s->budget--) { s->failed_pc=0x0c045afcu; return 0; }
r[3]=read(ram,0x0c045c6cu,4);
goto P_0c045afe;
P_0c045afe: /* original e100, guest PC 0x0c045afe */
if(!s->budget--) { s->failed_pc=0x0c045afeu; return 0; }
r[1]=0x00000000u;
goto P_0c045b00;
P_0c045b00: /* original 6232, guest PC 0x0c045b00 */
if(!s->budget--) { s->failed_pc=0x0c045b00u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c045b02;
P_0c045b02: /* original 2210, guest PC 0x0c045b02 */
if(!s->budget--) { s->failed_pc=0x0c045b02u; return 0; }
write(ram,r[2],r[1],1);
goto P_0c045b04;
P_0c045b04: /* original 4f26, guest PC 0x0c045b04 */
if(!s->budget--) { s->failed_pc=0x0c045b04u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045b06;
P_0c045b06: /* original 000b, guest PC 0x0c045b06 */
if(!s->budget--) { s->failed_pc=0x0c045b06u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c045b08: /* original 0009, guest PC 0x0c045b08 */
if(!s->budget--) { s->failed_pc=0x0c045b08u; return 0; }
return vf3_matrix_family(0x0c045b0au,s,ram);
P_0c045b36: /* original 4f22, guest PC 0x0c045b36 */
if(!s->budget--) { s->failed_pc=0x0c045b36u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045b38;
P_0c045b38: /* original 6032, guest PC 0x0c045b38 */
if(!s->budget--) { s->failed_pc=0x0c045b38u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c045b3a;
P_0c045b3a: /* original 401b, guest PC 0x0c045b3a */
if(!s->budget--) { s->failed_pc=0x0c045b3au; return 0; }
tmp=read(ram,r[0],1);
r[17]=(r[17]&~1u)|((tmp==0)!=0);
write(ram,r[0],tmp|0x80u,1);
goto P_0c045b3c;
P_0c045b3c: /* original 8907, guest PC 0x0c045b3c */
if(!s->budget--) { s->failed_pc=0x0c045b3cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c045b4e; }
goto P_0c045b3e;
P_0c045b3e: /* original d24a, guest PC 0x0c045b3e */
if(!s->budget--) { s->failed_pc=0x0c045b3eu; return 0; }
r[2]=read(ram,0x0c045c68u,4);
goto P_0c045b40;
P_0c045b40: /* original d14b, guest PC 0x0c045b40 */
if(!s->budget--) { s->failed_pc=0x0c045b40u; return 0; }
r[1]=read(ram,0x0c045c70u,4);
goto P_0c045b42;
P_0c045b42: /* original 420b, guest PC 0x0c045b42 */
if(!s->budget--) { s->failed_pc=0x0c045b42u; return 0; }
target=r[2];
r[16]=code_base|0x0c045b46u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045b46u) { target=s->pc; goto dispatch; }
goto P_0c045b46;
P_0c045b44: /* original 2f16, guest PC 0x0c045b44 */
if(!s->budget--) { s->failed_pc=0x0c045b44u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045b46;
P_0c045b46: /* original 7f04, guest PC 0x0c045b46 */
if(!s->budget--) { s->failed_pc=0x0c045b46u; return 0; }
r[15]+=0x00000004u;
goto P_0c045b48;
P_0c045b48: /* original 4f26, guest PC 0x0c045b48 */
if(!s->budget--) { s->failed_pc=0x0c045b48u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045b4a;
P_0c045b4a: /* original 000b, guest PC 0x0c045b4a */
if(!s->budget--) { s->failed_pc=0x0c045b4au; return 0; }
target=r[16];
r[0]=0xfffffffeu;
s->pc=target; return ram->oob==0;
P_0c045b4c: /* original e0fe, guest PC 0x0c045b4c */
if(!s->budget--) { s->failed_pc=0x0c045b4cu; return 0; }
r[0]=0xfffffffeu;
goto P_0c045b4e;
P_0c045b4e: /* original b007, guest PC 0x0c045b4e */
if(!s->budget--) { s->failed_pc=0x0c045b4eu; return 0; }
target=0x0c045b60u; r[16]=code_base|0x0c045b52u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045b52u) { target=s->pc; goto dispatch; }
goto P_0c045b52;
P_0c045b50: /* original 0009, guest PC 0x0c045b50 */
if(!s->budget--) { s->failed_pc=0x0c045b50u; return 0; }
goto P_0c045b52;
P_0c045b52: /* original d346, guest PC 0x0c045b52 */
if(!s->budget--) { s->failed_pc=0x0c045b52u; return 0; }
r[3]=read(ram,0x0c045c6cu,4);
goto P_0c045b54;
P_0c045b54: /* original e100, guest PC 0x0c045b54 */
if(!s->budget--) { s->failed_pc=0x0c045b54u; return 0; }
r[1]=0x00000000u;
goto P_0c045b56;
P_0c045b56: /* original 6232, guest PC 0x0c045b56 */
if(!s->budget--) { s->failed_pc=0x0c045b56u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c045b58;
P_0c045b58: /* original 2210, guest PC 0x0c045b58 */
if(!s->budget--) { s->failed_pc=0x0c045b58u; return 0; }
write(ram,r[2],r[1],1);
goto P_0c045b5a;
P_0c045b5a: /* original 4f26, guest PC 0x0c045b5a */
if(!s->budget--) { s->failed_pc=0x0c045b5au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045b5c;
P_0c045b5c: /* original 000b, guest PC 0x0c045b5c */
if(!s->budget--) { s->failed_pc=0x0c045b5cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c045b5e: /* original 0009, guest PC 0x0c045b5e */
if(!s->budget--) { s->failed_pc=0x0c045b5eu; return 0; }
return vf3_matrix_family(0x0c045b60u,s,ram);
P_0c045d14: /* original 4f22, guest PC 0x0c045d14 */
if(!s->budget--) { s->failed_pc=0x0c045d14u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045d16;
P_0c045d16: /* original 6032, guest PC 0x0c045d16 */
if(!s->budget--) { s->failed_pc=0x0c045d16u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c045d18;
P_0c045d18: /* original 401b, guest PC 0x0c045d18 */
if(!s->budget--) { s->failed_pc=0x0c045d18u; return 0; }
tmp=read(ram,r[0],1);
r[17]=(r[17]&~1u)|((tmp==0)!=0);
write(ram,r[0],tmp|0x80u,1);
goto P_0c045d1a;
P_0c045d1a: /* original 8907, guest PC 0x0c045d1a */
if(!s->budget--) { s->failed_pc=0x0c045d1au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c045d2c; }
goto P_0c045d1c;
P_0c045d1c: /* original d225, guest PC 0x0c045d1c */
if(!s->budget--) { s->failed_pc=0x0c045d1cu; return 0; }
r[2]=read(ram,0x0c045db4u,4);
goto P_0c045d1e;
P_0c045d1e: /* original d124, guest PC 0x0c045d1e */
if(!s->budget--) { s->failed_pc=0x0c045d1eu; return 0; }
r[1]=read(ram,0x0c045db0u,4);
goto P_0c045d20;
P_0c045d20: /* original 420b, guest PC 0x0c045d20 */
if(!s->budget--) { s->failed_pc=0x0c045d20u; return 0; }
target=r[2];
r[16]=code_base|0x0c045d24u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045d24u) { target=s->pc; goto dispatch; }
goto P_0c045d24;
P_0c045d22: /* original 2f16, guest PC 0x0c045d22 */
if(!s->budget--) { s->failed_pc=0x0c045d22u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045d24;
P_0c045d24: /* original 7f04, guest PC 0x0c045d24 */
if(!s->budget--) { s->failed_pc=0x0c045d24u; return 0; }
r[15]+=0x00000004u;
goto P_0c045d26;
P_0c045d26: /* original 4f26, guest PC 0x0c045d26 */
if(!s->budget--) { s->failed_pc=0x0c045d26u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045d28;
P_0c045d28: /* original 000b, guest PC 0x0c045d28 */
if(!s->budget--) { s->failed_pc=0x0c045d28u; return 0; }
target=r[16];
r[0]=0xfffffffeu;
s->pc=target; return ram->oob==0;
P_0c045d2a: /* original e0fe, guest PC 0x0c045d2a */
if(!s->budget--) { s->failed_pc=0x0c045d2au; return 0; }
r[0]=0xfffffffeu;
goto P_0c045d2c;
P_0c045d2c: /* original b007, guest PC 0x0c045d2c */
if(!s->budget--) { s->failed_pc=0x0c045d2cu; return 0; }
target=0x0c045d3eu; r[16]=code_base|0x0c045d30u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045d30u) { target=s->pc; goto dispatch; }
goto P_0c045d30;
P_0c045d2e: /* original 0009, guest PC 0x0c045d2e */
if(!s->budget--) { s->failed_pc=0x0c045d2eu; return 0; }
goto P_0c045d30;
P_0c045d30: /* original d31e, guest PC 0x0c045d30 */
if(!s->budget--) { s->failed_pc=0x0c045d30u; return 0; }
r[3]=read(ram,0x0c045dacu,4);
goto P_0c045d32;
P_0c045d32: /* original e100, guest PC 0x0c045d32 */
if(!s->budget--) { s->failed_pc=0x0c045d32u; return 0; }
r[1]=0x00000000u;
goto P_0c045d34;
P_0c045d34: /* original 6232, guest PC 0x0c045d34 */
if(!s->budget--) { s->failed_pc=0x0c045d34u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c045d36;
P_0c045d36: /* original 2210, guest PC 0x0c045d36 */
if(!s->budget--) { s->failed_pc=0x0c045d36u; return 0; }
write(ram,r[2],r[1],1);
goto P_0c045d38;
P_0c045d38: /* original 4f26, guest PC 0x0c045d38 */
if(!s->budget--) { s->failed_pc=0x0c045d38u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045d3a;
P_0c045d3a: /* original 000b, guest PC 0x0c045d3a */
if(!s->budget--) { s->failed_pc=0x0c045d3au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c045d3c: /* original 0009, guest PC 0x0c045d3c */
if(!s->budget--) { s->failed_pc=0x0c045d3cu; return 0; }
return vf3_matrix_family(0x0c045d3eu,s,ram);
P_0c045d5a: /* original 4f22, guest PC 0x0c045d5a */
if(!s->budget--) { s->failed_pc=0x0c045d5au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045d5c;
P_0c045d5c: /* original 6032, guest PC 0x0c045d5c */
if(!s->budget--) { s->failed_pc=0x0c045d5cu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c045d5e;
P_0c045d5e: /* original 401b, guest PC 0x0c045d5e */
if(!s->budget--) { s->failed_pc=0x0c045d5eu; return 0; }
tmp=read(ram,r[0],1);
r[17]=(r[17]&~1u)|((tmp==0)!=0);
write(ram,r[0],tmp|0x80u,1);
goto P_0c045d60;
P_0c045d60: /* original 8907, guest PC 0x0c045d60 */
if(!s->budget--) { s->failed_pc=0x0c045d60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c045d72; }
goto P_0c045d62;
P_0c045d62: /* original d214, guest PC 0x0c045d62 */
if(!s->budget--) { s->failed_pc=0x0c045d62u; return 0; }
r[2]=read(ram,0x0c045db4u,4);
goto P_0c045d64;
P_0c045d64: /* original d112, guest PC 0x0c045d64 */
if(!s->budget--) { s->failed_pc=0x0c045d64u; return 0; }
r[1]=read(ram,0x0c045db0u,4);
goto P_0c045d66;
P_0c045d66: /* original 420b, guest PC 0x0c045d66 */
if(!s->budget--) { s->failed_pc=0x0c045d66u; return 0; }
target=r[2];
r[16]=code_base|0x0c045d6au;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045d6au) { target=s->pc; goto dispatch; }
goto P_0c045d6a;
P_0c045d68: /* original 2f16, guest PC 0x0c045d68 */
if(!s->budget--) { s->failed_pc=0x0c045d68u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045d6a;
P_0c045d6a: /* original 7f04, guest PC 0x0c045d6a */
if(!s->budget--) { s->failed_pc=0x0c045d6au; return 0; }
r[15]+=0x00000004u;
goto P_0c045d6c;
P_0c045d6c: /* original 4f26, guest PC 0x0c045d6c */
if(!s->budget--) { s->failed_pc=0x0c045d6cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045d6e;
P_0c045d6e: /* original 000b, guest PC 0x0c045d6e */
if(!s->budget--) { s->failed_pc=0x0c045d6eu; return 0; }
target=r[16];
r[0]=0xfffffffeu;
s->pc=target; return ram->oob==0;
P_0c045d70: /* original e0fe, guest PC 0x0c045d70 */
if(!s->budget--) { s->failed_pc=0x0c045d70u; return 0; }
r[0]=0xfffffffeu;
goto P_0c045d72;
P_0c045d72: /* original b007, guest PC 0x0c045d72 */
if(!s->budget--) { s->failed_pc=0x0c045d72u; return 0; }
target=0x0c045d84u; r[16]=code_base|0x0c045d76u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045d76u) { target=s->pc; goto dispatch; }
goto P_0c045d76;
P_0c045d74: /* original 0009, guest PC 0x0c045d74 */
if(!s->budget--) { s->failed_pc=0x0c045d74u; return 0; }
goto P_0c045d76;
P_0c045d76: /* original d30d, guest PC 0x0c045d76 */
if(!s->budget--) { s->failed_pc=0x0c045d76u; return 0; }
r[3]=read(ram,0x0c045dacu,4);
goto P_0c045d78;
P_0c045d78: /* original e100, guest PC 0x0c045d78 */
if(!s->budget--) { s->failed_pc=0x0c045d78u; return 0; }
r[1]=0x00000000u;
goto P_0c045d7a;
P_0c045d7a: /* original 6232, guest PC 0x0c045d7a */
if(!s->budget--) { s->failed_pc=0x0c045d7au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c045d7c;
P_0c045d7c: /* original 2210, guest PC 0x0c045d7c */
if(!s->budget--) { s->failed_pc=0x0c045d7cu; return 0; }
write(ram,r[2],r[1],1);
goto P_0c045d7e;
P_0c045d7e: /* original 4f26, guest PC 0x0c045d7e */
if(!s->budget--) { s->failed_pc=0x0c045d7eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045d80;
P_0c045d80: /* original 000b, guest PC 0x0c045d80 */
if(!s->budget--) { s->failed_pc=0x0c045d80u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c045d82: /* original 0009, guest PC 0x0c045d82 */
if(!s->budget--) { s->failed_pc=0x0c045d82u; return 0; }
return vf3_matrix_family(0x0c045d84u,s,ram);
P_0c045e94: /* original 4f22, guest PC 0x0c045e94 */
if(!s->budget--) { s->failed_pc=0x0c045e94u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045e96;
P_0c045e96: /* original 6032, guest PC 0x0c045e96 */
if(!s->budget--) { s->failed_pc=0x0c045e96u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c045e98;
P_0c045e98: /* original 401b, guest PC 0x0c045e98 */
if(!s->budget--) { s->failed_pc=0x0c045e98u; return 0; }
tmp=read(ram,r[0],1);
r[17]=(r[17]&~1u)|((tmp==0)!=0);
write(ram,r[0],tmp|0x80u,1);
goto P_0c045e9a;
P_0c045e9a: /* original 8907, guest PC 0x0c045e9a */
if(!s->budget--) { s->failed_pc=0x0c045e9au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c045eac; }
goto P_0c045e9c;
P_0c045e9c: /* original d20f, guest PC 0x0c045e9c */
if(!s->budget--) { s->failed_pc=0x0c045e9cu; return 0; }
r[2]=read(ram,0x0c045edcu,4);
goto P_0c045e9e;
P_0c045e9e: /* original d10e, guest PC 0x0c045e9e */
if(!s->budget--) { s->failed_pc=0x0c045e9eu; return 0; }
r[1]=read(ram,0x0c045ed8u,4);
goto P_0c045ea0;
P_0c045ea0: /* original 420b, guest PC 0x0c045ea0 */
if(!s->budget--) { s->failed_pc=0x0c045ea0u; return 0; }
target=r[2];
r[16]=code_base|0x0c045ea4u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045ea4u) { target=s->pc; goto dispatch; }
goto P_0c045ea4;
P_0c045ea2: /* original 2f16, guest PC 0x0c045ea2 */
if(!s->budget--) { s->failed_pc=0x0c045ea2u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045ea4;
P_0c045ea4: /* original 7f04, guest PC 0x0c045ea4 */
if(!s->budget--) { s->failed_pc=0x0c045ea4u; return 0; }
r[15]+=0x00000004u;
goto P_0c045ea6;
P_0c045ea6: /* original 4f26, guest PC 0x0c045ea6 */
if(!s->budget--) { s->failed_pc=0x0c045ea6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045ea8;
P_0c045ea8: /* original 000b, guest PC 0x0c045ea8 */
if(!s->budget--) { s->failed_pc=0x0c045ea8u; return 0; }
target=r[16];
r[0]=0xfffffffeu;
s->pc=target; return ram->oob==0;
P_0c045eaa: /* original e0fe, guest PC 0x0c045eaa */
if(!s->budget--) { s->failed_pc=0x0c045eaau; return 0; }
r[0]=0xfffffffeu;
goto P_0c045eac;
P_0c045eac: /* original b007, guest PC 0x0c045eac */
if(!s->budget--) { s->failed_pc=0x0c045eacu; return 0; }
target=0x0c045ebeu; r[16]=code_base|0x0c045eb0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c045eb0u) { target=s->pc; goto dispatch; }
goto P_0c045eb0;
P_0c045eae: /* original 0009, guest PC 0x0c045eae */
if(!s->budget--) { s->failed_pc=0x0c045eaeu; return 0; }
goto P_0c045eb0;
P_0c045eb0: /* original d308, guest PC 0x0c045eb0 */
if(!s->budget--) { s->failed_pc=0x0c045eb0u; return 0; }
r[3]=read(ram,0x0c045ed4u,4);
goto P_0c045eb2;
P_0c045eb2: /* original e100, guest PC 0x0c045eb2 */
if(!s->budget--) { s->failed_pc=0x0c045eb2u; return 0; }
r[1]=0x00000000u;
goto P_0c045eb4;
P_0c045eb4: /* original 6232, guest PC 0x0c045eb4 */
if(!s->budget--) { s->failed_pc=0x0c045eb4u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c045eb6;
P_0c045eb6: /* original 2210, guest PC 0x0c045eb6 */
if(!s->budget--) { s->failed_pc=0x0c045eb6u; return 0; }
write(ram,r[2],r[1],1);
goto P_0c045eb8;
P_0c045eb8: /* original 4f26, guest PC 0x0c045eb8 */
if(!s->budget--) { s->failed_pc=0x0c045eb8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045eba;
P_0c045eba: /* original 000b, guest PC 0x0c045eba */
if(!s->budget--) { s->failed_pc=0x0c045ebau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c045ebc: /* original 0009, guest PC 0x0c045ebc */
if(!s->budget--) { s->failed_pc=0x0c045ebcu; return 0; }
return vf3_matrix_family(0x0c045ebeu,s,ram);
P_0c050bfe: /* original 4f22, guest PC 0x0c050bfe */
if(!s->budget--) { s->failed_pc=0x0c050bfeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c050c00;
P_0c050c00: /* original 7ffc, guest PC 0x0c050c00 */
if(!s->budget--) { s->failed_pc=0x0c050c00u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c050c02;
P_0c050c02: /* original 2f42, guest PC 0x0c050c02 */
if(!s->budget--) { s->failed_pc=0x0c050c02u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c050c04;
P_0c050c04: /* original d20c, guest PC 0x0c050c04 */
if(!s->budget--) { s->failed_pc=0x0c050c04u; return 0; }
r[2]=read(ram,0x0c050c38u,4);
goto P_0c050c06;
P_0c050c06: /* original 420b, guest PC 0x0c050c06 */
if(!s->budget--) { s->failed_pc=0x0c050c06u; return 0; }
target=r[2];
r[16]=code_base|0x0c050c0au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050c0au) { target=s->pc; goto dispatch; }
goto P_0c050c0a;
P_0c050c08: /* original 0009, guest PC 0x0c050c08 */
if(!s->budget--) { s->failed_pc=0x0c050c08u; return 0; }
goto P_0c050c0a;
P_0c050c0a: /* original 63f2, guest PC 0x0c050c0a */
if(!s->budget--) { s->failed_pc=0x0c050c0au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c050c0c;
P_0c050c0c: /* original d20b, guest PC 0x0c050c0c */
if(!s->budget--) { s->failed_pc=0x0c050c0cu; return 0; }
r[2]=read(ram,0x0c050c3cu,4);
goto P_0c050c0e;
P_0c050c0e: /* original 2232, guest PC 0x0c050c0e */
if(!s->budget--) { s->failed_pc=0x0c050c0eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c050c10;
P_0c050c10: /* original 6823, guest PC 0x0c050c10 */
if(!s->budget--) { s->failed_pc=0x0c050c10u; return 0; }
r[8]=r[2];
goto P_0c050c12;
P_0c050c12: /* original 930f, guest PC 0x0c050c12 */
if(!s->budget--) { s->failed_pc=0x0c050c12u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c050c34u,2);
goto P_0c050c14;
P_0c050c14: /* original 6122, guest PC 0x0c050c14 */
if(!s->budget--) { s->failed_pc=0x0c050c14u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c050c16;
P_0c050c16: /* original 2139, guest PC 0x0c050c16 */
if(!s->budget--) { s->failed_pc=0x0c050c16u; return 0; }
r[1]&=r[3];
goto P_0c050c18;
P_0c050c18: /* original 900d, guest PC 0x0c050c18 */
if(!s->budget--) { s->failed_pc=0x0c050c18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c050c36u,2);
goto P_0c050c1a;
P_0c050c1a: /* original 210b, guest PC 0x0c050c1a */
if(!s->budget--) { s->failed_pc=0x0c050c1au; return 0; }
r[1]|=r[0];
goto P_0c050c1c;
P_0c050c1c: /* original 2812, guest PC 0x0c050c1c */
if(!s->budget--) { s->failed_pc=0x0c050c1cu; return 0; }
write(ram,r[8],r[1],4);
goto P_0c050c1e;
P_0c050c1e: /* original 6123, guest PC 0x0c050c1e */
if(!s->budget--) { s->failed_pc=0x0c050c1eu; return 0; }
r[1]=r[2];
goto P_0c050c20;
P_0c050c20: /* original e3f7, guest PC 0x0c050c20 */
if(!s->budget--) { s->failed_pc=0x0c050c20u; return 0; }
r[3]=0xfffffff7u;
goto P_0c050c22;
P_0c050c22: /* original 6022, guest PC 0x0c050c22 */
if(!s->budget--) { s->failed_pc=0x0c050c22u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c050c24;
P_0c050c24: /* original 2039, guest PC 0x0c050c24 */
if(!s->budget--) { s->failed_pc=0x0c050c24u; return 0; }
r[0]&=r[3];
goto P_0c050c26;
P_0c050c26: /* original cb08, guest PC 0x0c050c26 */
if(!s->budget--) { s->failed_pc=0x0c050c26u; return 0; }
r[0]|=8u;
goto P_0c050c28;
P_0c050c28: /* original 2102, guest PC 0x0c050c28 */
if(!s->budget--) { s->failed_pc=0x0c050c28u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c050c2a;
P_0c050c2a: /* original 7f04, guest PC 0x0c050c2a */
if(!s->budget--) { s->failed_pc=0x0c050c2au; return 0; }
r[15]+=0x00000004u;
goto P_0c050c2c;
P_0c050c2c: /* original 4f26, guest PC 0x0c050c2c */
if(!s->budget--) { s->failed_pc=0x0c050c2cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c050c2e;
P_0c050c2e: /* original 68f6, guest PC 0x0c050c2e */
if(!s->budget--) { s->failed_pc=0x0c050c2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c050c30;
P_0c050c30: /* original 000b, guest PC 0x0c050c30 */
if(!s->budget--) { s->failed_pc=0x0c050c30u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c050c32: /* original 0009, guest PC 0x0c050c32 */
if(!s->budget--) { s->failed_pc=0x0c050c32u; return 0; }
return vf3_matrix_family(0x0c050c34u,s,ram);
P_0c051324: /* original 7ff8, guest PC 0x0c051324 */
if(!s->budget--) { s->failed_pc=0x0c051324u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c051326;
P_0c051326: /* original 0002, guest PC 0x0c051326 */
if(!s->budget--) { s->failed_pc=0x0c051326u; return 0; }
r[0]=r[17];
goto P_0c051328;
P_0c051328: /* original 4009, guest PC 0x0c051328 */
if(!s->budget--) { s->failed_pc=0x0c051328u; return 0; }
r[0]>>=2;
goto P_0c05132a;
P_0c05132a: /* original 4009, guest PC 0x0c05132a */
if(!s->budget--) { s->failed_pc=0x0c05132au; return 0; }
r[0]>>=2;
goto P_0c05132c;
P_0c05132c: /* original c90f, guest PC 0x0c05132c */
if(!s->budget--) { s->failed_pc=0x0c05132cu; return 0; }
r[0]&=15u;
goto P_0c05132e;
P_0c05132e: /* original 81f1, guest PC 0x0c05132e */
if(!s->budget--) { s->failed_pc=0x0c05132eu; return 0; }
write(ram,r[15]+2,r[0],2);
goto P_0c051330;
P_0c051330: /* original 0002, guest PC 0x0c051330 */
if(!s->budget--) { s->failed_pc=0x0c051330u; return 0; }
r[0]=r[17];
goto P_0c051332;
P_0c051332: /* original 9304, guest PC 0x0c051332 */
if(!s->budget--) { s->failed_pc=0x0c051332u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05133eu,2);
goto P_0c051334;
P_0c051334: /* original 2039, guest PC 0x0c051334 */
if(!s->budget--) { s->failed_pc=0x0c051334u; return 0; }
r[0]&=r[3];
goto P_0c051336;
P_0c051336: /* original cbf0, guest PC 0x0c051336 */
if(!s->budget--) { s->failed_pc=0x0c051336u; return 0; }
r[0]|=240u;
goto P_0c051338;
P_0c051338: /* original 400e, guest PC 0x0c051338 */
if(!s->budget--) { s->failed_pc=0x0c051338u; return 0; }
r[17]=r[0];
goto P_0c05133a;
P_0c05133a: /* original a001, guest PC 0x0c05133a */
if(!s->budget--) { s->failed_pc=0x0c05133au; return 0; }
goto P_0c051340;
P_0c05133c: /* original 0009, guest PC 0x0c05133c */
if(!s->budget--) { s->failed_pc=0x0c05133cu; return 0; }
return vf3_matrix_family(0x0c05133eu,s,ram);
P_0c051340: /* original c703, guest PC 0x0c051340 */
if(!s->budget--) { s->failed_pc=0x0c051340u; return 0; }
r[0]=0x0c051350u;
goto P_0c051342;
P_0c051342: /* original d102, guest PC 0x0c051342 */
if(!s->budget--) { s->failed_pc=0x0c051342u; return 0; }
r[1]=read(ram,0x0c05134cu,4);
goto P_0c051344;
P_0c051344: /* original 210b, guest PC 0x0c051344 */
if(!s->budget--) { s->failed_pc=0x0c051344u; return 0; }
r[1]|=r[0];
goto P_0c051346;
P_0c051346: /* original 412b, guest PC 0x0c051346 */
if(!s->budget--) { s->failed_pc=0x0c051346u; return 0; }
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
P_0c051348: /* original 0009, guest PC 0x0c051348 */
if(!s->budget--) { s->failed_pc=0x0c051348u; return 0; }
return vf3_matrix_family(0x0c05134au,s,ram);
P_0c051350: /* original d229, guest PC 0x0c051350 */
if(!s->budget--) { s->failed_pc=0x0c051350u; return 0; }
r[2]=read(ram,0x0c0513f8u,4);
goto P_0c051352;
P_0c051352: /* original 6022, guest PC 0x0c051352 */
if(!s->budget--) { s->failed_pc=0x0c051352u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c051354;
P_0c051354: /* original 4009, guest PC 0x0c051354 */
if(!s->budget--) { s->failed_pc=0x0c051354u; return 0; }
r[0]>>=2;
goto P_0c051356;
P_0c051356: /* original 4009, guest PC 0x0c051356 */
if(!s->budget--) { s->failed_pc=0x0c051356u; return 0; }
r[0]>>=2;
goto P_0c051358;
P_0c051358: /* original 4001, guest PC 0x0c051358 */
if(!s->budget--) { s->failed_pc=0x0c051358u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c05135a;
P_0c05135a: /* original c901, guest PC 0x0c05135a */
if(!s->budget--) { s->failed_pc=0x0c05135au; return 0; }
r[0]&=1u;
goto P_0c05135c;
P_0c05135c: /* original 8801, guest PC 0x0c05135c */
if(!s->budget--) { s->failed_pc=0x0c05135cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05135e;
P_0c05135e: /* original 8b27, guest PC 0x0c05135e */
if(!s->budget--) { s->failed_pc=0x0c05135eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0513b0; }
goto P_0c051360;
P_0c051360: /* original e100, guest PC 0x0c051360 */
if(!s->budget--) { s->failed_pc=0x0c051360u; return 0; }
r[1]=0x00000000u;
goto P_0c051362;
P_0c051362: /* original 1f11, guest PC 0x0c051362 */
if(!s->budget--) { s->failed_pc=0x0c051362u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c051364;
P_0c051364: /* original a00b, guest PC 0x0c051364 */
if(!s->budget--) { s->failed_pc=0x0c051364u; return 0; }
goto P_0c05137e;
P_0c051366: /* original 0009, guest PC 0x0c051366 */
if(!s->budget--) { s->failed_pc=0x0c051366u; return 0; }
goto P_0c051368;
P_0c051368: /* original 52f1, guest PC 0x0c051368 */
if(!s->budget--) { s->failed_pc=0x0c051368u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c05136a;
P_0c05136a: /* original 4208, guest PC 0x0c05136a */
if(!s->budget--) { s->failed_pc=0x0c05136au; return 0; }
r[2]<<=2;
goto P_0c05136c;
P_0c05136c: /* original 4208, guest PC 0x0c05136c */
if(!s->budget--) { s->failed_pc=0x0c05136cu; return 0; }
r[2]<<=2;
goto P_0c05136e;
P_0c05136e: /* original 4200, guest PC 0x0c05136e */
if(!s->budget--) { s->failed_pc=0x0c05136eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c051370;
P_0c051370: /* original d322, guest PC 0x0c051370 */
if(!s->budget--) { s->failed_pc=0x0c051370u; return 0; }
r[3]=read(ram,0x0c0513fcu,4);
goto P_0c051372;
P_0c051372: /* original 223b, guest PC 0x0c051372 */
if(!s->budget--) { s->failed_pc=0x0c051372u; return 0; }
r[2]|=r[3];
goto P_0c051374;
P_0c051374: /* original e100, guest PC 0x0c051374 */
if(!s->budget--) { s->failed_pc=0x0c051374u; return 0; }
r[1]=0x00000000u;
goto P_0c051376;
P_0c051376: /* original 2212, guest PC 0x0c051376 */
if(!s->budget--) { s->failed_pc=0x0c051376u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c051378;
P_0c051378: /* original 52f1, guest PC 0x0c051378 */
if(!s->budget--) { s->failed_pc=0x0c051378u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c05137a;
P_0c05137a: /* original 7201, guest PC 0x0c05137a */
if(!s->budget--) { s->failed_pc=0x0c05137au; return 0; }
r[2]+=0x00000001u;
goto P_0c05137c;
P_0c05137c: /* original 1f21, guest PC 0x0c05137c */
if(!s->budget--) { s->failed_pc=0x0c05137cu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c05137e;
P_0c05137e: /* original 9336, guest PC 0x0c05137e */
if(!s->budget--) { s->failed_pc=0x0c05137eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0513eeu,2);
goto P_0c051380;
P_0c051380: /* original 51f1, guest PC 0x0c051380 */
if(!s->budget--) { s->failed_pc=0x0c051380u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c051382;
P_0c051382: /* original 3132, guest PC 0x0c051382 */
if(!s->budget--) { s->failed_pc=0x0c051382u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[3])!=0);
goto P_0c051384;
P_0c051384: /* original 8bf0, guest PC 0x0c051384 */
if(!s->budget--) { s->failed_pc=0x0c051384u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c051368; }
goto P_0c051386;
P_0c051386: /* original 9333, guest PC 0x0c051386 */
if(!s->budget--) { s->failed_pc=0x0c051386u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0513f0u,2);
goto P_0c051388;
P_0c051388: /* original 1f31, guest PC 0x0c051388 */
if(!s->budget--) { s->failed_pc=0x0c051388u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c05138a;
P_0c05138a: /* original a00b, guest PC 0x0c05138a */
if(!s->budget--) { s->failed_pc=0x0c05138au; return 0; }
goto P_0c0513a4;
P_0c05138c: /* original 0009, guest PC 0x0c05138c */
if(!s->budget--) { s->failed_pc=0x0c05138cu; return 0; }
goto P_0c05138e;
P_0c05138e: /* original 51f1, guest PC 0x0c05138e */
if(!s->budget--) { s->failed_pc=0x0c05138eu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c051390;
P_0c051390: /* original 4108, guest PC 0x0c051390 */
if(!s->budget--) { s->failed_pc=0x0c051390u; return 0; }
r[1]<<=2;
goto P_0c051392;
P_0c051392: /* original 4108, guest PC 0x0c051392 */
if(!s->budget--) { s->failed_pc=0x0c051392u; return 0; }
r[1]<<=2;
goto P_0c051394;
P_0c051394: /* original 4100, guest PC 0x0c051394 */
if(!s->budget--) { s->failed_pc=0x0c051394u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c051396;
P_0c051396: /* original d319, guest PC 0x0c051396 */
if(!s->budget--) { s->failed_pc=0x0c051396u; return 0; }
r[3]=read(ram,0x0c0513fcu,4);
goto P_0c051398;
P_0c051398: /* original 213b, guest PC 0x0c051398 */
if(!s->budget--) { s->failed_pc=0x0c051398u; return 0; }
r[1]|=r[3];
goto P_0c05139a;
P_0c05139a: /* original e200, guest PC 0x0c05139a */
if(!s->budget--) { s->failed_pc=0x0c05139au; return 0; }
r[2]=0x00000000u;
goto P_0c05139c;
P_0c05139c: /* original 2122, guest PC 0x0c05139c */
if(!s->budget--) { s->failed_pc=0x0c05139cu; return 0; }
write(ram,r[1],r[2],4);
goto P_0c05139e;
P_0c05139e: /* original 51f1, guest PC 0x0c05139e */
if(!s->budget--) { s->failed_pc=0x0c05139eu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0513a0;
P_0c0513a0: /* original 7101, guest PC 0x0c0513a0 */
if(!s->budget--) { s->failed_pc=0x0c0513a0u; return 0; }
r[1]+=0x00000001u;
goto P_0c0513a2;
P_0c0513a2: /* original 1f11, guest PC 0x0c0513a2 */
if(!s->budget--) { s->failed_pc=0x0c0513a2u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0513a4;
P_0c0513a4: /* original 9325, guest PC 0x0c0513a4 */
if(!s->budget--) { s->failed_pc=0x0c0513a4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0513f2u,2);
goto P_0c0513a6;
P_0c0513a6: /* original 52f1, guest PC 0x0c0513a6 */
if(!s->budget--) { s->failed_pc=0x0c0513a6u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0513a8;
P_0c0513a8: /* original 3232, guest PC 0x0c0513a8 */
if(!s->budget--) { s->failed_pc=0x0c0513a8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c0513aa;
P_0c0513aa: /* original 8bf0, guest PC 0x0c0513aa */
if(!s->budget--) { s->failed_pc=0x0c0513aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05138e; }
goto P_0c0513ac;
P_0c0513ac: /* original a013, guest PC 0x0c0513ac */
if(!s->budget--) { s->failed_pc=0x0c0513acu; return 0; }
goto P_0c0513d6;
P_0c0513ae: /* original 0009, guest PC 0x0c0513ae */
if(!s->budget--) { s->failed_pc=0x0c0513aeu; return 0; }
goto P_0c0513b0;
P_0c0513b0: /* original e100, guest PC 0x0c0513b0 */
if(!s->budget--) { s->failed_pc=0x0c0513b0u; return 0; }
r[1]=0x00000000u;
goto P_0c0513b2;
P_0c0513b2: /* original 1f11, guest PC 0x0c0513b2 */
if(!s->budget--) { s->failed_pc=0x0c0513b2u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0513b4;
P_0c0513b4: /* original a00b, guest PC 0x0c0513b4 */
if(!s->budget--) { s->failed_pc=0x0c0513b4u; return 0; }
goto P_0c0513ce;
P_0c0513b6: /* original 0009, guest PC 0x0c0513b6 */
if(!s->budget--) { s->failed_pc=0x0c0513b6u; return 0; }
goto P_0c0513b8;
P_0c0513b8: /* original 52f1, guest PC 0x0c0513b8 */
if(!s->budget--) { s->failed_pc=0x0c0513b8u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0513ba;
P_0c0513ba: /* original 4208, guest PC 0x0c0513ba */
if(!s->budget--) { s->failed_pc=0x0c0513bau; return 0; }
r[2]<<=2;
goto P_0c0513bc;
P_0c0513bc: /* original 4208, guest PC 0x0c0513bc */
if(!s->budget--) { s->failed_pc=0x0c0513bcu; return 0; }
r[2]<<=2;
goto P_0c0513be;
P_0c0513be: /* original 4200, guest PC 0x0c0513be */
if(!s->budget--) { s->failed_pc=0x0c0513beu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0513c0;
P_0c0513c0: /* original d30e, guest PC 0x0c0513c0 */
if(!s->budget--) { s->failed_pc=0x0c0513c0u; return 0; }
r[3]=read(ram,0x0c0513fcu,4);
goto P_0c0513c2;
P_0c0513c2: /* original 223b, guest PC 0x0c0513c2 */
if(!s->budget--) { s->failed_pc=0x0c0513c2u; return 0; }
r[2]|=r[3];
goto P_0c0513c4;
P_0c0513c4: /* original e100, guest PC 0x0c0513c4 */
if(!s->budget--) { s->failed_pc=0x0c0513c4u; return 0; }
r[1]=0x00000000u;
goto P_0c0513c6;
P_0c0513c6: /* original 2212, guest PC 0x0c0513c6 */
if(!s->budget--) { s->failed_pc=0x0c0513c6u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c0513c8;
P_0c0513c8: /* original 52f1, guest PC 0x0c0513c8 */
if(!s->budget--) { s->failed_pc=0x0c0513c8u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0513ca;
P_0c0513ca: /* original 7201, guest PC 0x0c0513ca */
if(!s->budget--) { s->failed_pc=0x0c0513cau; return 0; }
r[2]+=0x00000001u;
goto P_0c0513cc;
P_0c0513cc: /* original 1f21, guest PC 0x0c0513cc */
if(!s->budget--) { s->failed_pc=0x0c0513ccu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0513ce;
P_0c0513ce: /* original 9311, guest PC 0x0c0513ce */
if(!s->budget--) { s->failed_pc=0x0c0513ceu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0513f4u,2);
goto P_0c0513d0;
P_0c0513d0: /* original 51f1, guest PC 0x0c0513d0 */
if(!s->budget--) { s->failed_pc=0x0c0513d0u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0513d2;
P_0c0513d2: /* original 3132, guest PC 0x0c0513d2 */
if(!s->budget--) { s->failed_pc=0x0c0513d2u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[3])!=0);
goto P_0c0513d4;
P_0c0513d4: /* original 8bf0, guest PC 0x0c0513d4 */
if(!s->budget--) { s->failed_pc=0x0c0513d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0513b8; }
goto P_0c0513d6;
P_0c0513d6: /* original 85f1, guest PC 0x0c0513d6 */
if(!s->budget--) { s->failed_pc=0x0c0513d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+2,2);
goto P_0c0513d8;
P_0c0513d8: /* original 600d, guest PC 0x0c0513d8 */
if(!s->budget--) { s->failed_pc=0x0c0513d8u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0513da;
P_0c0513da: /* original c90f, guest PC 0x0c0513da */
if(!s->budget--) { s->failed_pc=0x0c0513dau; return 0; }
r[0]&=15u;
goto P_0c0513dc;
P_0c0513dc: /* original 4008, guest PC 0x0c0513dc */
if(!s->budget--) { s->failed_pc=0x0c0513dcu; return 0; }
r[0]<<=2;
goto P_0c0513de;
P_0c0513de: /* original 4008, guest PC 0x0c0513de */
if(!s->budget--) { s->failed_pc=0x0c0513deu; return 0; }
r[0]<<=2;
goto P_0c0513e0;
P_0c0513e0: /* original 0302, guest PC 0x0c0513e0 */
if(!s->budget--) { s->failed_pc=0x0c0513e0u; return 0; }
r[3]=r[17];
goto P_0c0513e2;
P_0c0513e2: /* original 9208, guest PC 0x0c0513e2 */
if(!s->budget--) { s->failed_pc=0x0c0513e2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0513f6u,2);
goto P_0c0513e4;
P_0c0513e4: /* original 2329, guest PC 0x0c0513e4 */
if(!s->budget--) { s->failed_pc=0x0c0513e4u; return 0; }
r[3]&=r[2];
goto P_0c0513e6;
P_0c0513e6: /* original 203b, guest PC 0x0c0513e6 */
if(!s->budget--) { s->failed_pc=0x0c0513e6u; return 0; }
r[0]|=r[3];
goto P_0c0513e8;
P_0c0513e8: /* original 400e, guest PC 0x0c0513e8 */
if(!s->budget--) { s->failed_pc=0x0c0513e8u; return 0; }
r[17]=r[0];
goto P_0c0513ea;
P_0c0513ea: /* original a009, guest PC 0x0c0513ea */
if(!s->budget--) { s->failed_pc=0x0c0513eau; return 0; }
goto P_0c051400;
P_0c0513ec: /* original 0009, guest PC 0x0c0513ec */
if(!s->budget--) { s->failed_pc=0x0c0513ecu; return 0; }
return vf3_matrix_family(0x0c0513eeu,s,ram);
P_0c051400: /* original 0009, guest PC 0x0c051400 */
if(!s->budget--) { s->failed_pc=0x0c051400u; return 0; }
goto P_0c051402;
P_0c051402: /* original 0009, guest PC 0x0c051402 */
if(!s->budget--) { s->failed_pc=0x0c051402u; return 0; }
goto P_0c051404;
P_0c051404: /* original 0009, guest PC 0x0c051404 */
if(!s->budget--) { s->failed_pc=0x0c051404u; return 0; }
goto P_0c051406;
P_0c051406: /* original 0009, guest PC 0x0c051406 */
if(!s->budget--) { s->failed_pc=0x0c051406u; return 0; }
goto P_0c051408;
P_0c051408: /* original 0009, guest PC 0x0c051408 */
if(!s->budget--) { s->failed_pc=0x0c051408u; return 0; }
goto P_0c05140a;
P_0c05140a: /* original 0009, guest PC 0x0c05140a */
if(!s->budget--) { s->failed_pc=0x0c05140au; return 0; }
goto P_0c05140c;
P_0c05140c: /* original 0009, guest PC 0x0c05140c */
if(!s->budget--) { s->failed_pc=0x0c05140cu; return 0; }
goto P_0c05140e;
P_0c05140e: /* original 0009, guest PC 0x0c05140e */
if(!s->budget--) { s->failed_pc=0x0c05140eu; return 0; }
goto P_0c051410;
P_0c051410: /* original 7f08, guest PC 0x0c051410 */
if(!s->budget--) { s->failed_pc=0x0c051410u; return 0; }
r[15]+=0x00000008u;
goto P_0c051412;
P_0c051412: /* original 000b, guest PC 0x0c051412 */
if(!s->budget--) { s->failed_pc=0x0c051412u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c051414: /* original 0009, guest PC 0x0c051414 */
if(!s->budget--) { s->failed_pc=0x0c051414u; return 0; }
return vf3_matrix_family(0x0c051416u,s,ram);
P_0c054530: /* original 4f22, guest PC 0x0c054530 */
if(!s->budget--) { s->failed_pc=0x0c054530u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c054532;
P_0c054532: /* original d303, guest PC 0x0c054532 */
if(!s->budget--) { s->failed_pc=0x0c054532u; return 0; }
r[3]=read(ram,0x0c054540u,4);
goto P_0c054534;
P_0c054534: /* original 430b, guest PC 0x0c054534 */
if(!s->budget--) { s->failed_pc=0x0c054534u; return 0; }
target=r[3];
r[16]=code_base|0x0c054538u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c054538u) { target=s->pc; goto dispatch; }
goto P_0c054538;
P_0c054536: /* original 0009, guest PC 0x0c054536 */
if(!s->budget--) { s->failed_pc=0x0c054536u; return 0; }
goto P_0c054538;
P_0c054538: /* original 4f26, guest PC 0x0c054538 */
if(!s->budget--) { s->failed_pc=0x0c054538u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05453a;
P_0c05453a: /* original 000b, guest PC 0x0c05453a */
if(!s->budget--) { s->failed_pc=0x0c05453au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05453c: /* original 0009, guest PC 0x0c05453c */
if(!s->budget--) { s->failed_pc=0x0c05453cu; return 0; }
return vf3_matrix_family(0x0c05453eu,s,ram);
P_0c058780: /* original 4f22, guest PC 0x0c058780 */
if(!s->budget--) { s->failed_pc=0x0c058780u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c058782;
P_0c058782: /* original a048, guest PC 0x0c058782 */
if(!s->budget--) { s->failed_pc=0x0c058782u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c058816;
P_0c058784: /* original 4f22, guest PC 0x0c058784 */
if(!s->budget--) { s->failed_pc=0x0c058784u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
return vf3_matrix_family(0x0c058786u,s,ram);
P_0c058788: /* original 4f22, guest PC 0x0c058788 */
if(!s->budget--) { s->failed_pc=0x0c058788u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05878a;
P_0c05878a: /* original a025, guest PC 0x0c05878a */
if(!s->budget--) { s->failed_pc=0x0c05878au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0587d8;
P_0c05878c: /* original 4f22, guest PC 0x0c05878c */
if(!s->budget--) { s->failed_pc=0x0c05878cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
return vf3_matrix_family(0x0c05878eu,s,ram);
P_0c0587d8: /* original bf40, guest PC 0x0c0587d8 */
if(!s->budget--) { s->failed_pc=0x0c0587d8u; return 0; }
target=0x0c05865cu; r[16]=code_base|0x0c0587dcu;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0587dcu) { target=s->pc; goto dispatch; }
goto P_0c0587dc;
P_0c0587da: /* original 65e3, guest PC 0x0c0587da */
if(!s->budget--) { s->failed_pc=0x0c0587dau; return 0; }
r[5]=r[14];
goto P_0c0587dc;
P_0c0587dc: /* original 2f06, guest PC 0x0c0587dc */
if(!s->budget--) { s->failed_pc=0x0c0587dcu; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0587de;
P_0c0587de: /* original e008, guest PC 0x0c0587de */
if(!s->budget--) { s->failed_pc=0x0c0587deu; return 0; }
r[0]=0x00000008u;
goto P_0c0587e0;
P_0c0587e0: /* original f096, guest PC 0x0c0587e0 */
if(!s->budget--) { s->failed_pc=0x0c0587e0u; return 0; }
vf3_matrix_load(s,ram,0,r[9]+r[0]);
goto P_0c0587e2;
P_0c0587e2: /* original 62e3, guest PC 0x0c0587e2 */
if(!s->budget--) { s->failed_pc=0x0c0587e2u; return 0; }
r[2]=r[14];
goto P_0c0587e4;
P_0c0587e4: /* original 72d0, guest PC 0x0c0587e4 */
if(!s->budget--) { s->failed_pc=0x0c0587e4u; return 0; }
r[2]+=0xffffffd0u;
goto P_0c0587e6;
P_0c0587e6: /* original 6583, guest PC 0x0c0587e6 */
if(!s->budget--) { s->failed_pc=0x0c0587e6u; return 0; }
r[5]=r[8];
goto P_0c0587e8;
P_0c0587e8: /* original f79d, guest PC 0x0c0587e8 */
if(!s->budget--) { s->failed_pc=0x0c0587e8u; return 0; }
fr[7]=0x3f800000u;
goto P_0c0587ea;
P_0c0587ea: /* original be89, guest PC 0x0c0587ea */
if(!s->budget--) { s->failed_pc=0x0c0587eau; return 0; }
target=0x0c058500u; r[16]=code_base|0x0c0587eeu;
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'/');
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0587eeu) { target=s->pc; goto dispatch; }
goto P_0c0587ee;
P_0c0587ec: /* original f703, guest PC 0x0c0587ec */
if(!s->budget--) { s->failed_pc=0x0c0587ecu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'/');
goto P_0c0587ee;
P_0c0587ee: /* original 0c83, guest PC 0x0c0587ee */
if(!s->budget--) { s->failed_pc=0x0c0587eeu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0587f0;
P_0c0587f0: /* original 7c20, guest PC 0x0c0587f0 */
if(!s->budget--) { s->failed_pc=0x0c0587f0u; return 0; }
r[12]+=0x00000020u;
goto P_0c0587f2;
P_0c0587f2: /* original fa9d, guest PC 0x0c0587f2 */
if(!s->budget--) { s->failed_pc=0x0c0587f2u; return 0; }
fr[10]=0x3f800000u;
goto P_0c0587f4;
P_0c0587f4: /* original fa23, guest PC 0x0c0587f4 */
if(!s->budget--) { s->failed_pc=0x0c0587f4u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[2],r[18],'/');
goto P_0c0587f6;
P_0c0587f6: /* original f80c, guest PC 0x0c0587f6 */
if(!s->budget--) { s->failed_pc=0x0c0587f6u; return 0; }
vf3_matrix_move(s,8,0);
goto P_0c0587f8;
P_0c0587f8: /* original 62e3, guest PC 0x0c0587f8 */
if(!s->budget--) { s->failed_pc=0x0c0587f8u; return 0; }
r[2]=r[14];
goto P_0c0587fa;
P_0c0587fa: /* original fc4c, guest PC 0x0c0587fa */
if(!s->budget--) { s->failed_pc=0x0c0587fau; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c0587fc;
P_0c0587fc: /* original be80, guest PC 0x0c0587fc */
if(!s->budget--) { s->failed_pc=0x0c0587fcu; return 0; }
target=0x0c058500u; r[16]=code_base|0x0c058800u;
r[5]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c058800u) { target=s->pc; goto dispatch; }
goto P_0c058800;
P_0c0587fe: /* original 6563, guest PC 0x0c0587fe */
if(!s->budget--) { s->failed_pc=0x0c0587feu; return 0; }
r[5]=r[6];
goto P_0c058800;
P_0c058800: /* original 0c83, guest PC 0x0c058800 */
if(!s->budget--) { s->failed_pc=0x0c058800u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c058802;
P_0c058802: /* original fb9d, guest PC 0x0c058802 */
if(!s->budget--) { s->failed_pc=0x0c058802u; return 0; }
fr[11]=0x3f800000u;
goto P_0c058804;
P_0c058804: /* original 62e3, guest PC 0x0c058804 */
if(!s->budget--) { s->failed_pc=0x0c058804u; return 0; }
r[2]=r[14];
goto P_0c058806;
P_0c058806: /* original fb23, guest PC 0x0c058806 */
if(!s->budget--) { s->failed_pc=0x0c058806u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[2],r[18],'/');
goto P_0c058808;
P_0c058808: /* original f298, guest PC 0x0c058808 */
if(!s->budget--) { s->failed_pc=0x0c058808u; return 0; }
vf3_matrix_load(s,ram,2,r[9]);
goto P_0c05880a;
P_0c05880a: /* original 72e8, guest PC 0x0c05880a */
if(!s->budget--) { s->failed_pc=0x0c05880au; return 0; }
r[2]+=0xffffffe8u;
goto P_0c05880c;
P_0c05880c: /* original 6125, guest PC 0x0c05880c */
if(!s->budget--) { s->failed_pc=0x0c05880cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[1]=tmp;
goto P_0c05880e;
P_0c05880e: /* original f3fd, guest PC 0x0c05880e */
if(!s->budget--) { s->failed_pc=0x0c05880eu; return 0; }
r[18]^=0x100000u;
goto P_0c058810;
P_0c058810: /* original 6221, guest PC 0x0c058810 */
if(!s->budget--) { s->failed_pc=0x0c058810u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]=tmp;
goto P_0c058812;
P_0c058812: /* original a01e, guest PC 0x0c058812 */
if(!s->budget--) { s->failed_pc=0x0c058812u; return 0; }
vf3_matrix_move(s,6,0);
goto P_0c058852;
P_0c058814: /* original f60c, guest PC 0x0c058814 */
if(!s->budget--) { s->failed_pc=0x0c058814u; return 0; }
vf3_matrix_move(s,6,0);
goto P_0c058816;
P_0c058816: /* original bf21, guest PC 0x0c058816 */
if(!s->budget--) { s->failed_pc=0x0c058816u; return 0; }
target=0x0c05865cu; r[16]=code_base|0x0c05881au;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05881au) { target=s->pc; goto dispatch; }
goto P_0c05881a;
P_0c058818: /* original 65e3, guest PC 0x0c058818 */
if(!s->budget--) { s->failed_pc=0x0c058818u; return 0; }
r[5]=r[14];
goto P_0c05881a;
P_0c05881a: /* original 2f06, guest PC 0x0c05881a */
if(!s->budget--) { s->failed_pc=0x0c05881au; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05881c;
P_0c05881c: /* original e008, guest PC 0x0c05881c */
if(!s->budget--) { s->failed_pc=0x0c05881cu; return 0; }
r[0]=0x00000008u;
goto P_0c05881e;
P_0c05881e: /* original f086, guest PC 0x0c05881e */
if(!s->budget--) { s->failed_pc=0x0c05881eu; return 0; }
vf3_matrix_load(s,ram,0,r[8]+r[0]);
goto P_0c058820;
P_0c058820: /* original 62e3, guest PC 0x0c058820 */
if(!s->budget--) { s->failed_pc=0x0c058820u; return 0; }
r[2]=r[14];
goto P_0c058822;
P_0c058822: /* original 72e8, guest PC 0x0c058822 */
if(!s->budget--) { s->failed_pc=0x0c058822u; return 0; }
r[2]+=0xffffffe8u;
goto P_0c058824;
P_0c058824: /* original 6593, guest PC 0x0c058824 */
if(!s->budget--) { s->failed_pc=0x0c058824u; return 0; }
r[5]=r[9];
goto P_0c058826;
P_0c058826: /* original f79d, guest PC 0x0c058826 */
if(!s->budget--) { s->failed_pc=0x0c058826u; return 0; }
fr[7]=0x3f800000u;
goto P_0c058828;
P_0c058828: /* original be6a, guest PC 0x0c058828 */
if(!s->budget--) { s->failed_pc=0x0c058828u; return 0; }
target=0x0c058500u; r[16]=code_base|0x0c05882cu;
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'/');
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05882cu) { target=s->pc; goto dispatch; }
goto P_0c05882c;
P_0c05882a: /* original f703, guest PC 0x0c05882a */
if(!s->budget--) { s->failed_pc=0x0c05882au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[0],r[18],'/');
goto P_0c05882c;
P_0c05882c: /* original 0c83, guest PC 0x0c05882c */
if(!s->budget--) { s->failed_pc=0x0c05882cu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c05882e;
P_0c05882e: /* original 7c20, guest PC 0x0c05882e */
if(!s->budget--) { s->failed_pc=0x0c05882eu; return 0; }
r[12]+=0x00000020u;
goto P_0c058830;
P_0c058830: /* original f80c, guest PC 0x0c058830 */
if(!s->budget--) { s->failed_pc=0x0c058830u; return 0; }
vf3_matrix_move(s,8,0);
goto P_0c058832;
P_0c058832: /* original fa9d, guest PC 0x0c058832 */
if(!s->budget--) { s->failed_pc=0x0c058832u; return 0; }
fr[10]=0x3f800000u;
goto P_0c058834;
P_0c058834: /* original fa23, guest PC 0x0c058834 */
if(!s->budget--) { s->failed_pc=0x0c058834u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[2],r[18],'/');
goto P_0c058836;
P_0c058836: /* original fc4c, guest PC 0x0c058836 */
if(!s->budget--) { s->failed_pc=0x0c058836u; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c058838;
P_0c058838: /* original 62e3, guest PC 0x0c058838 */
if(!s->budget--) { s->failed_pc=0x0c058838u; return 0; }
r[2]=r[14];
goto P_0c05883a;
P_0c05883a: /* original be61, guest PC 0x0c05883a */
if(!s->budget--) { s->failed_pc=0x0c05883au; return 0; }
target=0x0c058500u; r[16]=code_base|0x0c05883eu;
r[5]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05883eu) { target=s->pc; goto dispatch; }
goto P_0c05883e;
P_0c05883c: /* original 6563, guest PC 0x0c05883c */
if(!s->budget--) { s->failed_pc=0x0c05883cu; return 0; }
r[5]=r[6];
goto P_0c05883e;
P_0c05883e: /* original 0c83, guest PC 0x0c05883e */
if(!s->budget--) { s->failed_pc=0x0c05883eu; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c058840;
P_0c058840: /* original fb9d, guest PC 0x0c058840 */
if(!s->budget--) { s->failed_pc=0x0c058840u; return 0; }
fr[11]=0x3f800000u;
goto P_0c058842;
P_0c058842: /* original 62e3, guest PC 0x0c058842 */
if(!s->budget--) { s->failed_pc=0x0c058842u; return 0; }
r[2]=r[14];
goto P_0c058844;
P_0c058844: /* original fb23, guest PC 0x0c058844 */
if(!s->budget--) { s->failed_pc=0x0c058844u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[2],r[18],'/');
goto P_0c058846;
P_0c058846: /* original 72d0, guest PC 0x0c058846 */
if(!s->budget--) { s->failed_pc=0x0c058846u; return 0; }
r[2]+=0xffffffd0u;
goto P_0c058848;
P_0c058848: /* original f288, guest PC 0x0c058848 */
if(!s->budget--) { s->failed_pc=0x0c058848u; return 0; }
vf3_matrix_load(s,ram,2,r[8]);
goto P_0c05884a;
P_0c05884a: /* original 6125, guest PC 0x0c05884a */
if(!s->budget--) { s->failed_pc=0x0c05884au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[1]=tmp;
goto P_0c05884c;
P_0c05884c: /* original f3fd, guest PC 0x0c05884c */
if(!s->budget--) { s->failed_pc=0x0c05884cu; return 0; }
r[18]^=0x100000u;
goto P_0c05884e;
P_0c05884e: /* original 6221, guest PC 0x0c05884e */
if(!s->budget--) { s->failed_pc=0x0c05884eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]=tmp;
goto P_0c058850;
P_0c058850: /* original f60c, guest PC 0x0c058850 */
if(!s->budget--) { s->failed_pc=0x0c058850u; return 0; }
vf3_matrix_move(s,6,0);
goto P_0c058852;
P_0c058852: /* original c607, guest PC 0x0c058852 */
if(!s->budget--) { s->failed_pc=0x0c058852u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+28,4);
goto P_0c058854;
P_0c058854: /* original f8a2, guest PC 0x0c058854 */
if(!s->budget--) { s->failed_pc=0x0c058854u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[10],r[18],'*');
goto P_0c058856;
P_0c058856: /* original f9a2, guest PC 0x0c058856 */
if(!s->budget--) { s->failed_pc=0x0c058856u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[10],r[18],'*');
goto P_0c058858;
P_0c058858: /* original f272, guest PC 0x0c058858 */
if(!s->budget--) { s->failed_pc=0x0c058858u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c05885a;
P_0c05885a: /* original f372, guest PC 0x0c05885a */
if(!s->budget--) { s->failed_pc=0x0c05885au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c05885c;
P_0c05885c: /* original 405a, guest PC 0x0c05885c */
if(!s->budget--) { s->failed_pc=0x0c05885cu; return 0; }
r[53]=r[0];
goto P_0c05885e;
P_0c05885e: /* original fa71, guest PC 0x0c05885e */
if(!s->budget--) { s->failed_pc=0x0c05885eu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[7],r[18],'-');
goto P_0c058860;
P_0c058860: /* original f00d, guest PC 0x0c058860 */
if(!s->budget--) { s->failed_pc=0x0c058860u; return 0; }
fr[0]=r[53];
goto P_0c058862;
P_0c058862: /* original f071, guest PC 0x0c058862 */
if(!s->budget--) { s->failed_pc=0x0c058862u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[7],r[18],'-');
goto P_0c058864;
P_0c058864: /* original f6b2, guest PC 0x0c058864 */
if(!s->budget--) { s->failed_pc=0x0c058864u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c058866;
P_0c058866: /* original f1b2, guest PC 0x0c058866 */
if(!s->budget--) { s->failed_pc=0x0c058866u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[11],r[18],'*');
goto P_0c058868;
P_0c058868: /* original fb71, guest PC 0x0c058868 */
if(!s->budget--) { s->failed_pc=0x0c058868u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[7],r[18],'-');
goto P_0c05886a;
P_0c05886a: /* original ff0b, guest PC 0x0c05886a */
if(!s->budget--) { s->failed_pc=0x0c05886au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c05886c;
P_0c05886c: /* original f0a3, guest PC 0x0c05886c */
if(!s->budget--) { s->failed_pc=0x0c05886cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[10],r[18],'/');
goto P_0c05886e;
P_0c05886e: /* original f821, guest PC 0x0c05886e */
if(!s->budget--) { s->failed_pc=0x0c05886eu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[2],r[18],'-');
goto P_0c058870;
P_0c058870: /* original f931, guest PC 0x0c058870 */
if(!s->budget--) { s->failed_pc=0x0c058870u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'-');
goto P_0c058872;
P_0c058872: /* original 425a, guest PC 0x0c058872 */
if(!s->budget--) { s->failed_pc=0x0c058872u; return 0; }
r[53]=r[2];
goto P_0c058874;
P_0c058874: /* original fe2d, guest PC 0x0c058874 */
if(!s->budget--) { s->failed_pc=0x0c058874u; return 0; }
fr[14]=vf3_fpu_float(r[53],r[18]);
goto P_0c058876;
P_0c058876: /* original 415a, guest PC 0x0c058876 */
if(!s->budget--) { s->failed_pc=0x0c058876u; return 0; }
r[53]=r[1];
goto P_0c058878;
P_0c058878: /* original fa2d, guest PC 0x0c058878 */
if(!s->budget--) { s->failed_pc=0x0c058878u; return 0; }
fr[10]=vf3_fpu_float(r[53],r[18]);
goto P_0c05887a;
P_0c05887a: /* original f621, guest PC 0x0c05887a */
if(!s->budget--) { s->failed_pc=0x0c05887au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'-');
goto P_0c05887c;
P_0c05887c: /* original 60f6, guest PC 0x0c05887c */
if(!s->budget--) { s->failed_pc=0x0c05887cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[0]=tmp;
goto P_0c05887e;
P_0c05887e: /* original f131, guest PC 0x0c05887e */
if(!s->budget--) { s->failed_pc=0x0c05887eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'-');
goto P_0c058880;
P_0c058880: /* original 61f6, guest PC 0x0c058880 */
if(!s->budget--) { s->failed_pc=0x0c058880u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c058882;
P_0c058882: /* original fef2, guest PC 0x0c058882 */
if(!s->budget--) { s->failed_pc=0x0c058882u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c058884;
P_0c058884: /* original faf2, guest PC 0x0c058884 */
if(!s->budget--) { s->failed_pc=0x0c058884u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[15],r[18],'*');
goto P_0c058886;
P_0c058886: /* original 4f26, guest PC 0x0c058886 */
if(!s->budget--) { s->failed_pc=0x0c058886u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c058888;
P_0c058888: /* original fde1, guest PC 0x0c058888 */
if(!s->budget--) { s->failed_pc=0x0c058888u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[14],r[18],'-');
goto P_0c05888a;
P_0c05888a: /* original fca1, guest PC 0x0c05888a */
if(!s->budget--) { s->failed_pc=0x0c05888au; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[10],r[18],'-');
goto P_0c05888c;
P_0c05888c: /* original 405a, guest PC 0x0c05888c */
if(!s->budget--) { s->failed_pc=0x0c05888cu; return 0; }
r[53]=r[0];
goto P_0c05888e;
P_0c05888e: /* original f5e1, guest PC 0x0c05888e */
if(!s->budget--) { s->failed_pc=0x0c05888eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'-');
goto P_0c058890;
P_0c058890: /* original 7c3c, guest PC 0x0c058890 */
if(!s->budget--) { s->failed_pc=0x0c058890u; return 0; }
r[12]+=0x0000003cu;
goto P_0c058892;
P_0c058892: /* original f4a1, guest PC 0x0c058892 */
if(!s->budget--) { s->failed_pc=0x0c058892u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[10],r[18],'-');
goto P_0c058894;
P_0c058894: /* original ff3c, guest PC 0x0c058894 */
if(!s->budget--) { s->failed_pc=0x0c058894u; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c058896;
P_0c058896: /* original ff9e, guest PC 0x0c058896 */
if(!s->budget--) { s->failed_pc=0x0c058896u; return 0; }
fr[15]=vf3_fpu_mac(fr[0],fr[9],fr[15],r[18]);
goto P_0c058898;
P_0c058898: /* original f92c, guest PC 0x0c058898 */
if(!s->budget--) { s->failed_pc=0x0c058898u; return 0; }
vf3_matrix_move(s,9,2);
goto P_0c05889a;
P_0c05889a: /* original f98e, guest PC 0x0c05889a */
if(!s->budget--) { s->failed_pc=0x0c05889au; return 0; }
fr[9]=vf3_fpu_mac(fr[0],fr[8],fr[9],r[18]);
goto P_0c05889c;
P_0c05889c: /* original f8ec, guest PC 0x0c05889c */
if(!s->budget--) { s->failed_pc=0x0c05889cu; return 0; }
vf3_matrix_move(s,8,14);
goto P_0c05889e;
P_0c05889e: /* original f8de, guest PC 0x0c05889e */
if(!s->budget--) { s->failed_pc=0x0c05889eu; return 0; }
fr[8]=vf3_fpu_mac(fr[0],fr[13],fr[8],r[18]);
goto P_0c0588a0;
P_0c0588a0: /* original fdac, guest PC 0x0c0588a0 */
if(!s->budget--) { s->failed_pc=0x0c0588a0u; return 0; }
vf3_matrix_move(s,13,10);
goto P_0c0588a2;
P_0c0588a2: /* original fdce, guest PC 0x0c0588a2 */
if(!s->budget--) { s->failed_pc=0x0c0588a2u; return 0; }
fr[13]=vf3_fpu_mac(fr[0],fr[12],fr[13],r[18]);
goto P_0c0588a4;
P_0c0588a4: /* original f00d, guest PC 0x0c0588a4 */
if(!s->budget--) { s->failed_pc=0x0c0588a4u; return 0; }
fr[0]=r[53];
goto P_0c0588a6;
P_0c0588a6: /* original f0b3, guest PC 0x0c0588a6 */
if(!s->budget--) { s->failed_pc=0x0c0588a6u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'/');
goto P_0c0588a8;
P_0c0588a8: /* original 4a5a, guest PC 0x0c0588a8 */
if(!s->budget--) { s->failed_pc=0x0c0588a8u; return 0; }
r[53]=r[10];
goto P_0c0588aa;
P_0c0588aa: /* original fc0d, guest PC 0x0c0588aa */
if(!s->budget--) { s->failed_pc=0x0c0588aau; return 0; }
fr[12]=r[53];
goto P_0c0588ac;
P_0c0588ac: /* original ffc2, guest PC 0x0c0588ac */
if(!s->budget--) { s->failed_pc=0x0c0588acu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[12],r[18],'*');
goto P_0c0588ae;
P_0c0588ae: /* original c618, guest PC 0x0c0588ae */
if(!s->budget--) { s->failed_pc=0x0c0588aeu; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+96,4);
goto P_0c0588b0;
P_0c0588b0: /* original f9c2, guest PC 0x0c0588b0 */
if(!s->budget--) { s->failed_pc=0x0c0588b0u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[12],r[18],'*');
goto P_0c0588b2;
P_0c0588b2: /* original 2c12, guest PC 0x0c0588b2 */
if(!s->budget--) { s->failed_pc=0x0c0588b2u; return 0; }
write(ram,r[12],r[1],4);
goto P_0c0588b4;
P_0c0588b4: /* original 2c06, guest PC 0x0c0588b4 */
if(!s->budget--) { s->failed_pc=0x0c0588b4u; return 0; }
tmp=r[0]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0588b6;
P_0c0588b6: /* original fc8b, guest PC 0x0c0588b6 */
if(!s->budget--) { s->failed_pc=0x0c0588b6u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c0588b8;
P_0c0588b8: /* original fcdb, guest PC 0x0c0588b8 */
if(!s->budget--) { s->failed_pc=0x0c0588b8u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c0588ba;
P_0c0588ba: /* original 2ca6, guest PC 0x0c0588ba */
if(!s->budget--) { s->failed_pc=0x0c0588bau; return 0; }
tmp=r[10]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0588bc;
P_0c0588bc: /* original fcfb, guest PC 0x0c0588bc */
if(!s->budget--) { s->failed_pc=0x0c0588bcu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[12]);
goto P_0c0588be;
P_0c0588be: /* original fc9b, guest PC 0x0c0588be */
if(!s->budget--) { s->failed_pc=0x0c0588beu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c0588c0;
P_0c0588c0: /* original 2cc6, guest PC 0x0c0588c0 */
if(!s->budget--) { s->failed_pc=0x0c0588c0u; return 0; }
tmp=r[12]; r[12]-=4; write(ram,r[12],tmp,4);
goto P_0c0588c2;
P_0c0588c2: /* original 0c83, guest PC 0x0c0588c2 */
if(!s->budget--) { s->failed_pc=0x0c0588c2u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c0588c4;
P_0c0588c4: /* original 7c2c, guest PC 0x0c0588c4 */
if(!s->budget--) { s->failed_pc=0x0c0588c4u; return 0; }
r[12]+=0x0000002cu;
goto P_0c0588c6;
P_0c0588c6: /* original f31e, guest PC 0x0c0588c6 */
if(!s->budget--) { s->failed_pc=0x0c0588c6u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[1],fr[3],r[18]);
goto P_0c0588c8;
P_0c0588c8: /* original 2ca2, guest PC 0x0c0588c8 */
if(!s->budget--) { s->failed_pc=0x0c0588c8u; return 0; }
write(ram,r[12],r[10],4);
goto P_0c0588ca;
P_0c0588ca: /* original f26e, guest PC 0x0c0588ca */
if(!s->budget--) { s->failed_pc=0x0c0588cau; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[6],fr[2],r[18]);
goto P_0c0588cc;
P_0c0588cc: /* original 7c04, guest PC 0x0c0588cc */
if(!s->budget--) { s->failed_pc=0x0c0588ccu; return 0; }
r[12]+=0x00000004u;
goto P_0c0588ce;
P_0c0588ce: /* original fe5e, guest PC 0x0c0588ce */
if(!s->budget--) { s->failed_pc=0x0c0588ceu; return 0; }
fr[14]=vf3_fpu_mac(fr[0],fr[5],fr[14],r[18]);
goto P_0c0588d0;
P_0c0588d0: /* original 1c02, guest PC 0x0c0588d0 */
if(!s->budget--) { s->failed_pc=0x0c0588d0u; return 0; }
write(ram,r[12]+8,r[0],4);
goto P_0c0588d2;
P_0c0588d2: /* original fa4e, guest PC 0x0c0588d2 */
if(!s->budget--) { s->failed_pc=0x0c0588d2u; return 0; }
fr[10]=vf3_fpu_mac(fr[0],fr[4],fr[10],r[18]);
goto P_0c0588d4;
P_0c0588d4: /* original e004, guest PC 0x0c0588d4 */
if(!s->budget--) { s->failed_pc=0x0c0588d4u; return 0; }
r[0]=0x00000004u;
goto P_0c0588d6;
P_0c0588d6: /* original f3c2, guest PC 0x0c0588d6 */
if(!s->budget--) { s->failed_pc=0x0c0588d6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'*');
goto P_0c0588d8;
P_0c0588d8: /* original 1c13, guest PC 0x0c0588d8 */
if(!s->budget--) { s->failed_pc=0x0c0588d8u; return 0; }
write(ram,r[12]+12,r[1],4);
goto P_0c0588da;
P_0c0588da: /* original f2c2, guest PC 0x0c0588da */
if(!s->budget--) { s->failed_pc=0x0c0588dau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[12],r[18],'*');
goto P_0c0588dc;
P_0c0588dc: /* original fce7, guest PC 0x0c0588dc */
if(!s->budget--) { s->failed_pc=0x0c0588dcu; return 0; }
vf3_matrix_store(s,ram,14,r[12]+r[0]);
goto P_0c0588de;
P_0c0588de: /* original fcaa, guest PC 0x0c0588de */
if(!s->budget--) { s->failed_pc=0x0c0588deu; return 0; }
vf3_matrix_store(s,ram,10,r[12]);
goto P_0c0588e0;
P_0c0588e0: /* original 7cf8, guest PC 0x0c0588e0 */
if(!s->budget--) { s->failed_pc=0x0c0588e0u; return 0; }
r[12]+=0xfffffff8u;
goto P_0c0588e2;
P_0c0588e2: /* original fc3a, guest PC 0x0c0588e2 */
if(!s->budget--) { s->failed_pc=0x0c0588e2u; return 0; }
vf3_matrix_store(s,ram,3,r[12]);
goto P_0c0588e4;
P_0c0588e4: /* original fc2b, guest PC 0x0c0588e4 */
if(!s->budget--) { s->failed_pc=0x0c0588e4u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[12]);
goto P_0c0588e6;
P_0c0588e6: /* original f3fd, guest PC 0x0c0588e6 */
if(!s->budget--) { s->failed_pc=0x0c0588e6u; return 0; }
r[18]^=0x100000u;
goto P_0c0588e8;
P_0c0588e8: /* original 7cfc, guest PC 0x0c0588e8 */
if(!s->budget--) { s->failed_pc=0x0c0588e8u; return 0; }
r[12]+=0xfffffffcu;
goto P_0c0588ea;
P_0c0588ea: /* original f498, guest PC 0x0c0588ea */
if(!s->budget--) { s->failed_pc=0x0c0588eau; return 0; }
vf3_matrix_load(s,ram,4,r[9]);
goto P_0c0588ec;
P_0c0588ec: /* original 000b, guest PC 0x0c0588ec */
if(!s->budget--) { s->failed_pc=0x0c0588ecu; return 0; }
target=r[16];
vf3_matrix_load(s,ram,8,r[6]);
s->pc=target; return ram->oob==0;
P_0c0588ee: /* original f868, guest PC 0x0c0588ee */
if(!s->budget--) { s->failed_pc=0x0c0588eeu; return 0; }
vf3_matrix_load(s,ram,8,r[6]);
return vf3_matrix_family(0x0c0588f0u,s,ram);
P_0c05961c: /* original 2fe6, guest PC 0x0c05961c */
if(!s->budget--) { s->failed_pc=0x0c05961cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
return vf3_matrix_family(0x0c05961eu,s,ram);
P_0c05c4a2: /* original 2fe6, guest PC 0x0c05c4a2 */
if(!s->budget--) { s->failed_pc=0x0c05c4a2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c4a4;
P_0c05c4a4: /* original 2fd6, guest PC 0x0c05c4a4 */
if(!s->budget--) { s->failed_pc=0x0c05c4a4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c4a6;
P_0c05c4a6: /* original 2fc6, guest PC 0x0c05c4a6 */
if(!s->budget--) { s->failed_pc=0x0c05c4a6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c4a8;
P_0c05c4a8: /* original 2fb6, guest PC 0x0c05c4a8 */
if(!s->budget--) { s->failed_pc=0x0c05c4a8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c4aa;
P_0c05c4aa: /* original eb02, guest PC 0x0c05c4aa */
if(!s->budget--) { s->failed_pc=0x0c05c4aau; return 0; }
r[11]=0x00000002u;
goto P_0c05c4ac;
P_0c05c4ac: /* original d23c, guest PC 0x0c05c4ac */
if(!s->budget--) { s->failed_pc=0x0c05c4acu; return 0; }
r[2]=read(ram,0x0c05c5a0u,4);
goto P_0c05c4ae;
P_0c05c4ae: /* original 2fa6, guest PC 0x0c05c4ae */
if(!s->budget--) { s->failed_pc=0x0c05c4aeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c4b0;
P_0c05c4b0: /* original 2f96, guest PC 0x0c05c4b0 */
if(!s->budget--) { s->failed_pc=0x0c05c4b0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c4b2;
P_0c05c4b2: /* original 6a43, guest PC 0x0c05c4b2 */
if(!s->budget--) { s->failed_pc=0x0c05c4b2u; return 0; }
r[10]=r[4];
goto P_0c05c4b4;
P_0c05c4b4: /* original d33b, guest PC 0x0c05c4b4 */
if(!s->budget--) { s->failed_pc=0x0c05c4b4u; return 0; }
r[3]=read(ram,0x0c05c5a4u,4);
goto P_0c05c4b6;
P_0c05c4b6: /* original e900, guest PC 0x0c05c4b6 */
if(!s->budget--) { s->failed_pc=0x0c05c4b6u; return 0; }
r[9]=0x00000000u;
goto P_0c05c4b8;
P_0c05c4b8: /* original 2f86, guest PC 0x0c05c4b8 */
if(!s->budget--) { s->failed_pc=0x0c05c4b8u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c4ba;
P_0c05c4ba: /* original 6853, guest PC 0x0c05c4ba */
if(!s->budget--) { s->failed_pc=0x0c05c4bau; return 0; }
r[8]=r[5];
return vf3_matrix_family(0x0c05c4bcu,s,ram);
P_0c05c8a6: /* original 4f22, guest PC 0x0c05c8a6 */
if(!s->budget--) { s->failed_pc=0x0c05c8a6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05c8a8;
P_0c05c8a8: /* original 7ffc, guest PC 0x0c05c8a8 */
if(!s->budget--) { s->failed_pc=0x0c05c8a8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05c8aa;
P_0c05c8aa: /* original 6032, guest PC 0x0c05c8aa */
if(!s->budget--) { s->failed_pc=0x0c05c8aau; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05c8ac;
P_0c05c8ac: /* original 014e, guest PC 0x0c05c8ac */
if(!s->budget--) { s->failed_pc=0x0c05c8acu; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c05c8ae;
P_0c05c8ae: /* original 6053, guest PC 0x0c05c8ae */
if(!s->budget--) { s->failed_pc=0x0c05c8aeu; return 0; }
r[0]=r[5];
goto P_0c05c8b0;
P_0c05c8b0: /* original 0009, guest PC 0x0c05c8b0 */
if(!s->budget--) { s->failed_pc=0x0c05c8b0u; return 0; }
goto P_0c05c8b2;
P_0c05c8b2: /* original 02be, guest PC 0x0c05c8b2 */
if(!s->budget--) { s->failed_pc=0x0c05c8b2u; return 0; }
r[2]=read(ram,r[11]+r[0],4);
goto P_0c05c8b4;
P_0c05c8b4: /* original 3128, guest PC 0x0c05c8b4 */
if(!s->budget--) { s->failed_pc=0x0c05c8b4u; return 0; }
r[1]-=r[2];
goto P_0c05c8b6;
P_0c05c8b6: /* original d221, guest PC 0x0c05c8b6 */
if(!s->budget--) { s->failed_pc=0x0c05c8b6u; return 0; }
r[2]=read(ram,0x0c05c93cu,4);
goto P_0c05c8b8;
P_0c05c8b8: /* original 420b, guest PC 0x0c05c8b8 */
if(!s->budget--) { s->failed_pc=0x0c05c8b8u; return 0; }
target=r[2];
r[16]=code_base|0x0c05c8bcu;
r[0]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05c8bcu) { target=s->pc; goto dispatch; }
goto P_0c05c8bc;
P_0c05c8ba: /* original e004, guest PC 0x0c05c8ba */
if(!s->budget--) { s->failed_pc=0x0c05c8bau; return 0; }
r[0]=0x00000004u;
goto P_0c05c8bc;
P_0c05c8bc: /* original d920, guest PC 0x0c05c8bc */
if(!s->budget--) { s->failed_pc=0x0c05c8bcu; return 0; }
r[9]=read(ram,0x0c05c940u,4);
goto P_0c05c8be;
P_0c05c8be: /* original 4008, guest PC 0x0c05c8be */
if(!s->budget--) { s->failed_pc=0x0c05c8beu; return 0; }
r[0]<<=2;
goto P_0c05c8c0;
P_0c05c8c0: /* original dd20, guest PC 0x0c05c8c0 */
if(!s->budget--) { s->failed_pc=0x0c05c8c0u; return 0; }
r[13]=read(ram,0x0c05c944u,4);
goto P_0c05c8c2;
P_0c05c8c2: /* original 6ab3, guest PC 0x0c05c8c2 */
if(!s->budget--) { s->failed_pc=0x0c05c8c2u; return 0; }
r[10]=r[11];
goto P_0c05c8c4;
P_0c05c8c4: /* original 9e31, guest PC 0x0c05c8c4 */
if(!s->budget--) { s->failed_pc=0x0c05c8c4u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05c92au,2);
goto P_0c05c8c6;
P_0c05c8c6: /* original 6c03, guest PC 0x0c05c8c6 */
if(!s->budget--) { s->failed_pc=0x0c05c8c6u; return 0; }
r[12]=r[0];
goto P_0c05c8c8;
P_0c05c8c8: /* original 3a5c, guest PC 0x0c05c8c8 */
if(!s->budget--) { s->failed_pc=0x0c05c8c8u; return 0; }
r[10]+=r[5];
goto P_0c05c8ca;
P_0c05c8ca: /* original 63f3, guest PC 0x0c05c8ca */
if(!s->budget--) { s->failed_pc=0x0c05c8cau; return 0; }
r[3]=r[15];
goto P_0c05c8cc;
P_0c05c8cc: /* original 2f36, guest PC 0x0c05c8cc */
if(!s->budget--) { s->failed_pc=0x0c05c8ccu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05c8ce;
P_0c05c8ce: /* original e710, guest PC 0x0c05c8ce */
if(!s->budget--) { s->failed_pc=0x0c05c8ceu; return 0; }
r[7]=0x00000010u;
goto P_0c05c8d0;
P_0c05c8d0: /* original 65a2, guest PC 0x0c05c8d0 */
if(!s->budget--) { s->failed_pc=0x0c05c8d0u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c05c8d2;
P_0c05c8d2: /* original 66c3, guest PC 0x0c05c8d2 */
if(!s->budget--) { s->failed_pc=0x0c05c8d2u; return 0; }
r[6]=r[12];
goto P_0c05c8d4;
P_0c05c8d4: /* original 490b, guest PC 0x0c05c8d4 */
if(!s->budget--) { s->failed_pc=0x0c05c8d4u; return 0; }
target=r[9];
r[16]=code_base|0x0c05c8d8u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05c8d8u) { target=s->pc; goto dispatch; }
goto P_0c05c8d8;
P_0c05c8d6: /* original 64d3, guest PC 0x0c05c8d6 */
if(!s->budget--) { s->failed_pc=0x0c05c8d6u; return 0; }
r[4]=r[13];
goto P_0c05c8d8;
P_0c05c8d8: /* original 30e0, guest PC 0x0c05c8d8 */
if(!s->budget--) { s->failed_pc=0x0c05c8d8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[14])!=0);
goto P_0c05c8da;
P_0c05c8da: /* original 8df6, guest PC 0x0c05c8da */
if(!s->budget--) { s->failed_pc=0x0c05c8dau; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c05c8ca; }
goto P_0c05c8de;
P_0c05c8dc: /* original 7f04, guest PC 0x0c05c8dc */
if(!s->budget--) { s->failed_pc=0x0c05c8dcu; return 0; }
r[15]+=0x00000004u;
goto P_0c05c8de;
P_0c05c8de: /* original d313, guest PC 0x0c05c8de */
if(!s->budget--) { s->failed_pc=0x0c05c8deu; return 0; }
r[3]=read(ram,0x0c05c92cu,4);
goto P_0c05c8e0;
P_0c05c8e0: /* original d015, guest PC 0x0c05c8e0 */
if(!s->budget--) { s->failed_pc=0x0c05c8e0u; return 0; }
r[0]=read(ram,0x0c05c938u,4);
goto P_0c05c8e2;
P_0c05c8e2: /* original 6332, guest PC 0x0c05c8e2 */
if(!s->budget--) { s->failed_pc=0x0c05c8e2u; return 0; }
tmp=read(ram,r[3],4);
r[3]=tmp;
goto P_0c05c8e4;
P_0c05c8e4: /* original 02be, guest PC 0x0c05c8e4 */
if(!s->budget--) { s->failed_pc=0x0c05c8e4u; return 0; }
r[2]=read(ram,r[11]+r[0],4);
goto P_0c05c8e6;
P_0c05c8e6: /* original 33bc, guest PC 0x0c05c8e6 */
if(!s->budget--) { s->failed_pc=0x0c05c8e6u; return 0; }
r[3]+=r[11];
goto P_0c05c8e8;
P_0c05c8e8: /* original d011, guest PC 0x0c05c8e8 */
if(!s->budget--) { s->failed_pc=0x0c05c8e8u; return 0; }
r[0]=read(ram,0x0c05c930u,4);
goto P_0c05c8ea;
P_0c05c8ea: /* original 4208, guest PC 0x0c05c8ea */
if(!s->budget--) { s->failed_pc=0x0c05c8eau; return 0; }
r[2]<<=2;
goto P_0c05c8ec;
P_0c05c8ec: /* original 01be, guest PC 0x0c05c8ec */
if(!s->budget--) { s->failed_pc=0x0c05c8ecu; return 0; }
r[1]=read(ram,r[11]+r[0],4);
goto P_0c05c8ee;
P_0c05c8ee: /* original 321c, guest PC 0x0c05c8ee */
if(!s->budget--) { s->failed_pc=0x0c05c8eeu; return 0; }
r[2]+=r[1];
goto P_0c05c8f0;
P_0c05c8f0: /* original 2322, guest PC 0x0c05c8f0 */
if(!s->budget--) { s->failed_pc=0x0c05c8f0u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c05c8f2;
P_0c05c8f2: /* original 61f2, guest PC 0x0c05c8f2 */
if(!s->budget--) { s->failed_pc=0x0c05c8f2u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c05c8f4;
P_0c05c8f4: /* original d214, guest PC 0x0c05c8f4 */
if(!s->budget--) { s->failed_pc=0x0c05c8f4u; return 0; }
r[2]=read(ram,0x0c05c948u,4);
goto P_0c05c8f6;
P_0c05c8f6: /* original 6312, guest PC 0x0c05c8f6 */
if(!s->budget--) { s->failed_pc=0x0c05c8f6u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c05c8f8;
P_0c05c8f8: /* original 2232, guest PC 0x0c05c8f8 */
if(!s->budget--) { s->failed_pc=0x0c05c8f8u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c05c8fa;
P_0c05c8fa: /* original e000, guest PC 0x0c05c8fa */
if(!s->budget--) { s->failed_pc=0x0c05c8fau; return 0; }
r[0]=0x00000000u;
goto P_0c05c8fc;
P_0c05c8fc: /* original 7f04, guest PC 0x0c05c8fc */
if(!s->budget--) { s->failed_pc=0x0c05c8fcu; return 0; }
r[15]+=0x00000004u;
goto P_0c05c8fe;
P_0c05c8fe: /* original 4f26, guest PC 0x0c05c8fe */
if(!s->budget--) { s->failed_pc=0x0c05c8feu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05c900;
P_0c05c900: /* original 69f6, guest PC 0x0c05c900 */
if(!s->budget--) { s->failed_pc=0x0c05c900u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05c902;
P_0c05c902: /* original 6af6, guest PC 0x0c05c902 */
if(!s->budget--) { s->failed_pc=0x0c05c902u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05c904;
P_0c05c904: /* original 6bf6, guest PC 0x0c05c904 */
if(!s->budget--) { s->failed_pc=0x0c05c904u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05c906;
P_0c05c906: /* original 6cf6, guest PC 0x0c05c906 */
if(!s->budget--) { s->failed_pc=0x0c05c906u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05c908;
P_0c05c908: /* original 6df6, guest PC 0x0c05c908 */
if(!s->budget--) { s->failed_pc=0x0c05c908u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05c90a;
P_0c05c90a: /* original 000b, guest PC 0x0c05c90a */
if(!s->budget--) { s->failed_pc=0x0c05c90au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05c90c: /* original 6ef6, guest PC 0x0c05c90c */
if(!s->budget--) { s->failed_pc=0x0c05c90cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c05c90eu,s,ram);
P_0c05cbee: /* original 4f22, guest PC 0x0c05cbee */
if(!s->budget--) { s->failed_pc=0x0c05cbeeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05cbf0;
P_0c05cbf0: /* original de34, guest PC 0x0c05cbf0 */
if(!s->budget--) { s->failed_pc=0x0c05cbf0u; return 0; }
r[14]=read(ram,0x0c05ccc4u,4);
goto P_0c05cbf2;
P_0c05cbf2: /* original 7ff8, guest PC 0x0c05cbf2 */
if(!s->budget--) { s->failed_pc=0x0c05cbf2u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c05cbf4;
P_0c05cbf4: /* original 1f51, guest PC 0x0c05cbf4 */
if(!s->budget--) { s->failed_pc=0x0c05cbf4u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c05cbf6;
P_0c05cbf6: /* original 65f3, guest PC 0x0c05cbf6 */
if(!s->budget--) { s->failed_pc=0x0c05cbf6u; return 0; }
r[5]=r[15];
goto P_0c05cbf8;
P_0c05cbf8: /* original 2f62, guest PC 0x0c05cbf8 */
if(!s->budget--) { s->failed_pc=0x0c05cbf8u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c05cbfa;
P_0c05cbfa: /* original 7504, guest PC 0x0c05cbfa */
if(!s->budget--) { s->failed_pc=0x0c05cbfau; return 0; }
r[5]+=0x00000004u;
goto P_0c05cbfc;
P_0c05cbfc: /* original 6322, guest PC 0x0c05cbfc */
if(!s->budget--) { s->failed_pc=0x0c05cbfcu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c05cbfe;
P_0c05cbfe: /* original e604, guest PC 0x0c05cbfe */
if(!s->budget--) { s->failed_pc=0x0c05cbfeu; return 0; }
r[6]=0x00000004u;
goto P_0c05cc00;
P_0c05cc00: /* original 343c, guest PC 0x0c05cc00 */
if(!s->budget--) { s->failed_pc=0x0c05cc00u; return 0; }
r[4]+=r[3];
goto P_0c05cc02;
P_0c05cc02: /* original 2e42, guest PC 0x0c05cc02 */
if(!s->budget--) { s->failed_pc=0x0c05cc02u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c05cc04;
P_0c05cc04: /* original d331, guest PC 0x0c05cc04 */
if(!s->budget--) { s->failed_pc=0x0c05cc04u; return 0; }
r[3]=read(ram,0x0c05ccccu,4);
goto P_0c05cc06;
P_0c05cc06: /* original 430b, guest PC 0x0c05cc06 */
if(!s->budget--) { s->failed_pc=0x0c05cc06u; return 0; }
target=r[3];
r[16]=code_base|0x0c05cc0au;
tmp=read(ram,r[4],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05cc0au) { target=s->pc; goto dispatch; }
goto P_0c05cc0a;
P_0c05cc08: /* original 6442, guest PC 0x0c05cc08 */
if(!s->budget--) { s->failed_pc=0x0c05cc08u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05cc0a;
P_0c05cc0a: /* original e000, guest PC 0x0c05cc0a */
if(!s->budget--) { s->failed_pc=0x0c05cc0au; return 0; }
r[0]=0x00000000u;
goto P_0c05cc0c;
P_0c05cc0c: /* original 62e2, guest PC 0x0c05cc0c */
if(!s->budget--) { s->failed_pc=0x0c05cc0cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c05cc0e;
P_0c05cc0e: /* original 63f2, guest PC 0x0c05cc0e */
if(!s->budget--) { s->failed_pc=0x0c05cc0eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c05cc10;
P_0c05cc10: /* original 6122, guest PC 0x0c05cc10 */
if(!s->budget--) { s->failed_pc=0x0c05cc10u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c05cc12;
P_0c05cc12: /* original 4308, guest PC 0x0c05cc12 */
if(!s->budget--) { s->failed_pc=0x0c05cc12u; return 0; }
r[3]<<=2;
goto P_0c05cc14;
P_0c05cc14: /* original 313c, guest PC 0x0c05cc14 */
if(!s->budget--) { s->failed_pc=0x0c05cc14u; return 0; }
r[1]+=r[3];
goto P_0c05cc16;
P_0c05cc16: /* original 2212, guest PC 0x0c05cc16 */
if(!s->budget--) { s->failed_pc=0x0c05cc16u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c05cc18;
P_0c05cc18: /* original 7f08, guest PC 0x0c05cc18 */
if(!s->budget--) { s->failed_pc=0x0c05cc18u; return 0; }
r[15]+=0x00000008u;
goto P_0c05cc1a;
P_0c05cc1a: /* original 4f26, guest PC 0x0c05cc1a */
if(!s->budget--) { s->failed_pc=0x0c05cc1au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05cc1c;
P_0c05cc1c: /* original 000b, guest PC 0x0c05cc1c */
if(!s->budget--) { s->failed_pc=0x0c05cc1cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05cc1e: /* original 6ef6, guest PC 0x0c05cc1e */
if(!s->budget--) { s->failed_pc=0x0c05cc1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c05cc20u,s,ram);
P_0c05ddaa: /* original 4f22, guest PC 0x0c05ddaa */
if(!s->budget--) { s->failed_pc=0x0c05ddaau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05ddac;
P_0c05ddac: /* original de29, guest PC 0x0c05ddac */
if(!s->budget--) { s->failed_pc=0x0c05ddacu; return 0; }
r[14]=read(ram,0x0c05de54u,4);
goto P_0c05ddae;
P_0c05ddae: /* original 6043, guest PC 0x0c05ddae */
if(!s->budget--) { s->failed_pc=0x0c05ddaeu; return 0; }
r[0]=r[4];
goto P_0c05ddb0;
P_0c05ddb0: /* original 0009, guest PC 0x0c05ddb0 */
if(!s->budget--) { s->failed_pc=0x0c05ddb0u; return 0; }
goto P_0c05ddb2;
P_0c05ddb2: /* original 8801, guest PC 0x0c05ddb2 */
if(!s->budget--) { s->failed_pc=0x0c05ddb2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05ddb4;
P_0c05ddb4: /* original 8b0a, guest PC 0x0c05ddb4 */
if(!s->budget--) { s->failed_pc=0x0c05ddb4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05ddcc; }
goto P_0c05ddb6;
P_0c05ddb6: /* original e3fe, guest PC 0x0c05ddb6 */
if(!s->budget--) { s->failed_pc=0x0c05ddb6u; return 0; }
r[3]=0xfffffffeu;
goto P_0c05ddb8;
P_0c05ddb8: /* original d227, guest PC 0x0c05ddb8 */
if(!s->budget--) { s->failed_pc=0x0c05ddb8u; return 0; }
r[2]=read(ram,0x0c05de58u,4);
goto P_0c05ddba;
P_0c05ddba: /* original 6522, guest PC 0x0c05ddba */
if(!s->budget--) { s->failed_pc=0x0c05ddbau; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c05ddbc;
P_0c05ddbc: /* original 2539, guest PC 0x0c05ddbc */
if(!s->budget--) { s->failed_pc=0x0c05ddbcu; return 0; }
r[5]&=r[3];
goto P_0c05ddbe;
P_0c05ddbe: /* original 4e0b, guest PC 0x0c05ddbe */
if(!s->budget--) { s->failed_pc=0x0c05ddbeu; return 0; }
target=r[14];
r[16]=code_base|0x0c05ddc2u;
r[4]=0x00000044u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05ddc2u) { target=s->pc; goto dispatch; }
goto P_0c05ddc2;
P_0c05ddc0: /* original e444, guest PC 0x0c05ddc0 */
if(!s->budget--) { s->failed_pc=0x0c05ddc0u; return 0; }
r[4]=0x00000044u;
goto P_0c05ddc2;
P_0c05ddc2: /* original d326, guest PC 0x0c05ddc2 */
if(!s->budget--) { s->failed_pc=0x0c05ddc2u; return 0; }
r[3]=read(ram,0x0c05de5cu,4);
goto P_0c05ddc4;
P_0c05ddc4: /* original 6032, guest PC 0x0c05ddc4 */
if(!s->budget--) { s->failed_pc=0x0c05ddc4u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05ddc6;
P_0c05ddc6: /* original cb08, guest PC 0x0c05ddc6 */
if(!s->budget--) { s->failed_pc=0x0c05ddc6u; return 0; }
r[0]|=8u;
goto P_0c05ddc8;
P_0c05ddc8: /* original a008, guest PC 0x0c05ddc8 */
if(!s->budget--) { s->failed_pc=0x0c05ddc8u; return 0; }
r[5]=r[0];
goto P_0c05dddc;
P_0c05ddca: /* original 6503, guest PC 0x0c05ddca */
if(!s->budget--) { s->failed_pc=0x0c05ddcau; return 0; }
r[5]=r[0];
goto P_0c05ddcc;
P_0c05ddcc: /* original d222, guest PC 0x0c05ddcc */
if(!s->budget--) { s->failed_pc=0x0c05ddccu; return 0; }
r[2]=read(ram,0x0c05de58u,4);
goto P_0c05ddce;
P_0c05ddce: /* original e3fe, guest PC 0x0c05ddce */
if(!s->budget--) { s->failed_pc=0x0c05ddceu; return 0; }
r[3]=0xfffffffeu;
goto P_0c05ddd0;
P_0c05ddd0: /* original 6522, guest PC 0x0c05ddd0 */
if(!s->budget--) { s->failed_pc=0x0c05ddd0u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c05ddd2;
P_0c05ddd2: /* original 2539, guest PC 0x0c05ddd2 */
if(!s->budget--) { s->failed_pc=0x0c05ddd2u; return 0; }
r[5]&=r[3];
goto P_0c05ddd4;
P_0c05ddd4: /* original 4e0b, guest PC 0x0c05ddd4 */
if(!s->budget--) { s->failed_pc=0x0c05ddd4u; return 0; }
target=r[14];
r[16]=code_base|0x0c05ddd8u;
r[4]=0x00000044u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05ddd8u) { target=s->pc; goto dispatch; }
goto P_0c05ddd8;
P_0c05ddd6: /* original e444, guest PC 0x0c05ddd6 */
if(!s->budget--) { s->failed_pc=0x0c05ddd6u; return 0; }
r[4]=0x00000044u;
goto P_0c05ddd8;
P_0c05ddd8: /* original d320, guest PC 0x0c05ddd8 */
if(!s->budget--) { s->failed_pc=0x0c05ddd8u; return 0; }
r[3]=read(ram,0x0c05de5cu,4);
goto P_0c05ddda;
P_0c05ddda: /* original 6532, guest PC 0x0c05ddda */
if(!s->budget--) { s->failed_pc=0x0c05dddau; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c05dddc;
P_0c05dddc: /* original 942a, guest PC 0x0c05dddc */
if(!s->budget--) { s->failed_pc=0x0c05dddcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05de34u,2);
goto P_0c05ddde;
P_0c05ddde: /* original 4e0b, guest PC 0x0c05ddde */
if(!s->budget--) { s->failed_pc=0x0c05dddeu; return 0; }
target=r[14];
r[16]=code_base|0x0c05dde2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05dde2u) { target=s->pc; goto dispatch; }
goto P_0c05dde2;
P_0c05dde0: /* original 0009, guest PC 0x0c05dde0 */
if(!s->budget--) { s->failed_pc=0x0c05dde0u; return 0; }
goto P_0c05dde2;
P_0c05dde2: /* original d21d, guest PC 0x0c05dde2 */
if(!s->budget--) { s->failed_pc=0x0c05dde2u; return 0; }
r[2]=read(ram,0x0c05de58u,4);
goto P_0c05dde4;
P_0c05dde4: /* original 6522, guest PC 0x0c05dde4 */
if(!s->budget--) { s->failed_pc=0x0c05dde4u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c05dde6;
P_0c05dde6: /* original 4e0b, guest PC 0x0c05dde6 */
if(!s->budget--) { s->failed_pc=0x0c05dde6u; return 0; }
target=r[14];
r[16]=code_base|0x0c05ddeau;
r[4]=0x00000044u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05ddeau) { target=s->pc; goto dispatch; }
goto P_0c05ddea;
P_0c05dde8: /* original e444, guest PC 0x0c05dde8 */
if(!s->budget--) { s->failed_pc=0x0c05dde8u; return 0; }
r[4]=0x00000044u;
goto P_0c05ddea;
P_0c05ddea: /* original e000, guest PC 0x0c05ddea */
if(!s->budget--) { s->failed_pc=0x0c05ddeau; return 0; }
r[0]=0x00000000u;
goto P_0c05ddec;
P_0c05ddec: /* original 4f26, guest PC 0x0c05ddec */
if(!s->budget--) { s->failed_pc=0x0c05ddecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05ddee;
P_0c05ddee: /* original 000b, guest PC 0x0c05ddee */
if(!s->budget--) { s->failed_pc=0x0c05ddeeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05ddf0: /* original 6ef6, guest PC 0x0c05ddf0 */
if(!s->budget--) { s->failed_pc=0x0c05ddf0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c05ddf2u,s,ram);
P_0c05e12e: /* original 4f22, guest PC 0x0c05e12e */
if(!s->budget--) { s->failed_pc=0x0c05e12eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e130;
P_0c05e130: /* original cac4, guest PC 0x0c05e130 */
if(!s->budget--) { s->failed_pc=0x0c05e130u; return 0; }
r[0]^=196u;
goto P_0c05e132;
P_0c05e132: /* original 0c16, guest PC 0x0c05e132 */
if(!s->budget--) { s->failed_pc=0x0c05e132u; return 0; }
write(ram,r[12]+r[0],r[1],4);
goto P_0c05e134;
P_0c05e134: /* original cadc, guest PC 0x0c05e134 */
if(!s->budget--) { s->failed_pc=0x0c05e134u; return 0; }
r[0]^=220u;
goto P_0c05e136;
P_0c05e136: /* original 0c16, guest PC 0x0c05e136 */
if(!s->budget--) { s->failed_pc=0x0c05e136u; return 0; }
write(ram,r[12]+r[0],r[1],4);
goto P_0c05e138;
P_0c05e138: /* original cacc, guest PC 0x0c05e138 */
if(!s->budget--) { s->failed_pc=0x0c05e138u; return 0; }
r[0]^=204u;
goto P_0c05e13a;
P_0c05e13a: /* original 0c16, guest PC 0x0c05e13a */
if(!s->budget--) { s->failed_pc=0x0c05e13au; return 0; }
write(ram,r[12]+r[0],r[1],4);
goto P_0c05e13c;
P_0c05e13c: /* original cd40, guest PC 0x0c05e13c */
if(!s->budget--) { s->failed_pc=0x0c05e13cu; return 0; }
s->failed_pc=0x0c05e13cu; return 0;
goto P_0c05e13e;
P_0c05e13e: /* original 0c16, guest PC 0x0c05e13e */
if(!s->budget--) { s->failed_pc=0x0c05e13eu; return 0; }
write(ram,r[12]+r[0],r[1],4);
goto P_0c05e140;
P_0c05e140: /* original cd48, guest PC 0x0c05e140 */
if(!s->budget--) { s->failed_pc=0x0c05e140u; return 0; }
s->failed_pc=0x0c05e140u; return 0;
goto P_0c05e142;
P_0c05e142: /* original 0c16, guest PC 0x0c05e142 */
if(!s->budget--) { s->failed_pc=0x0c05e142u; return 0; }
write(ram,r[12]+r[0],r[1],4);
goto P_0c05e144;
P_0c05e144: /* original 2fe6, guest PC 0x0c05e144 */
if(!s->budget--) { s->failed_pc=0x0c05e144u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05e146;
P_0c05e146: /* original 4f22, guest PC 0x0c05e146 */
if(!s->budget--) { s->failed_pc=0x0c05e146u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e148;
P_0c05e148: /* original d34f, guest PC 0x0c05e148 */
if(!s->budget--) { s->failed_pc=0x0c05e148u; return 0; }
r[3]=read(ram,0x0c05e288u,4);
goto P_0c05e14a;
P_0c05e14a: /* original 2348, guest PC 0x0c05e14a */
if(!s->budget--) { s->failed_pc=0x0c05e14au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c05e14c;
P_0c05e14c: /* original 8900, guest PC 0x0c05e14c */
if(!s->budget--) { s->failed_pc=0x0c05e14cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05e150; }
goto P_0c05e14e;
P_0c05e14e: /* original e400, guest PC 0x0c05e14e */
if(!s->budget--) { s->failed_pc=0x0c05e14eu; return 0; }
r[4]=0x00000000u;
goto P_0c05e150;
P_0c05e150: /* original d34e, guest PC 0x0c05e150 */
if(!s->budget--) { s->failed_pc=0x0c05e150u; return 0; }
r[3]=read(ram,0x0c05e28cu,4);
goto P_0c05e152;
P_0c05e152: /* original 2348, guest PC 0x0c05e152 */
if(!s->budget--) { s->failed_pc=0x0c05e152u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c05e154;
P_0c05e154: /* original 8900, guest PC 0x0c05e154 */
if(!s->budget--) { s->failed_pc=0x0c05e154u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05e158; }
goto P_0c05e156;
P_0c05e156: /* original 948d, guest PC 0x0c05e156 */
if(!s->budget--) { s->failed_pc=0x0c05e156u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e274u,2);
goto P_0c05e158;
P_0c05e158: /* original d34d, guest PC 0x0c05e158 */
if(!s->budget--) { s->failed_pc=0x0c05e158u; return 0; }
r[3]=read(ram,0x0c05e290u,4);
goto P_0c05e15a;
P_0c05e15a: /* original 2342, guest PC 0x0c05e15a */
if(!s->budget--) { s->failed_pc=0x0c05e15au; return 0; }
write(ram,r[3],r[4],4);
goto P_0c05e15c;
P_0c05e15c: /* original d24d, guest PC 0x0c05e15c */
if(!s->budget--) { s->failed_pc=0x0c05e15cu; return 0; }
r[2]=read(ram,0x0c05e294u,4);
goto P_0c05e15e;
P_0c05e15e: /* original d14e, guest PC 0x0c05e15e */
if(!s->budget--) { s->failed_pc=0x0c05e15eu; return 0; }
r[1]=read(ram,0x0c05e298u,4);
goto P_0c05e160;
P_0c05e160: /* original 6e12, guest PC 0x0c05e160 */
if(!s->budget--) { s->failed_pc=0x0c05e160u; return 0; }
tmp=read(ram,r[1],4);
r[14]=tmp;
goto P_0c05e162;
P_0c05e162: /* original 2e29, guest PC 0x0c05e162 */
if(!s->budget--) { s->failed_pc=0x0c05e162u; return 0; }
r[14]&=r[2];
goto P_0c05e164;
P_0c05e164: /* original 644c, guest PC 0x0c05e164 */
if(!s->budget--) { s->failed_pc=0x0c05e164u; return 0; }
r[4]=r[4]&255u;
goto P_0c05e166;
P_0c05e166: /* original e30f, guest PC 0x0c05e166 */
if(!s->budget--) { s->failed_pc=0x0c05e166u; return 0; }
r[3]=0x0000000fu;
goto P_0c05e168;
P_0c05e168: /* original 443d, guest PC 0x0c05e168 */
if(!s->budget--) { s->failed_pc=0x0c05e168u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c05e16a;
P_0c05e16a: /* original 2e4b, guest PC 0x0c05e16a */
if(!s->budget--) { s->failed_pc=0x0c05e16au; return 0; }
r[14]|=r[4];
goto P_0c05e16c;
P_0c05e16c: /* original 21e2, guest PC 0x0c05e16c */
if(!s->budget--) { s->failed_pc=0x0c05e16cu; return 0; }
write(ram,r[1],r[14],4);
goto P_0c05e16e;
P_0c05e16e: /* original 65e3, guest PC 0x0c05e16e */
if(!s->budget--) { s->failed_pc=0x0c05e16eu; return 0; }
r[5]=r[14];
goto P_0c05e170;
P_0c05e170: /* original d24a, guest PC 0x0c05e170 */
if(!s->budget--) { s->failed_pc=0x0c05e170u; return 0; }
r[2]=read(ram,0x0c05e29cu,4);
goto P_0c05e172;
P_0c05e172: /* original 420b, guest PC 0x0c05e172 */
if(!s->budget--) { s->failed_pc=0x0c05e172u; return 0; }
target=r[2];
r[16]=code_base|0x0c05e176u;
r[4]=0x00000048u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e176u) { target=s->pc; goto dispatch; }
goto P_0c05e176;
P_0c05e174: /* original e448, guest PC 0x0c05e174 */
if(!s->budget--) { s->failed_pc=0x0c05e174u; return 0; }
r[4]=0x00000048u;
goto P_0c05e176;
P_0c05e176: /* original e000, guest PC 0x0c05e176 */
if(!s->budget--) { s->failed_pc=0x0c05e176u; return 0; }
r[0]=0x00000000u;
goto P_0c05e178;
P_0c05e178: /* original 4f26, guest PC 0x0c05e178 */
if(!s->budget--) { s->failed_pc=0x0c05e178u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e17a;
P_0c05e17a: /* original 000b, guest PC 0x0c05e17a */
if(!s->budget--) { s->failed_pc=0x0c05e17au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05e17c: /* original 6ef6, guest PC 0x0c05e17c */
if(!s->budget--) { s->failed_pc=0x0c05e17cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c05e17e;
P_0c05e17e: /* original 4f22, guest PC 0x0c05e17e */
if(!s->budget--) { s->failed_pc=0x0c05e17eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e180;
P_0c05e180: /* original d347, guest PC 0x0c05e180 */
if(!s->budget--) { s->failed_pc=0x0c05e180u; return 0; }
r[3]=read(ram,0x0c05e2a0u,4);
goto P_0c05e182;
P_0c05e182: /* original 7ffc, guest PC 0x0c05e182 */
if(!s->budget--) { s->failed_pc=0x0c05e182u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05e184;
P_0c05e184: /* original d245, guest PC 0x0c05e184 */
if(!s->budget--) { s->failed_pc=0x0c05e184u; return 0; }
r[2]=read(ram,0x0c05e29cu,4);
goto P_0c05e186;
P_0c05e186: /* original 65f3, guest PC 0x0c05e186 */
if(!s->budget--) { s->failed_pc=0x0c05e186u; return 0; }
r[5]=r[15];
goto P_0c05e188;
P_0c05e188: /* original ff4a, guest PC 0x0c05e188 */
if(!s->budget--) { s->failed_pc=0x0c05e188u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c05e18a;
P_0c05e18a: /* original 6552, guest PC 0x0c05e18a */
if(!s->budget--) { s->failed_pc=0x0c05e18au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c05e18c;
P_0c05e18c: /* original 2539, guest PC 0x0c05e18c */
if(!s->budget--) { s->failed_pc=0x0c05e18cu; return 0; }
r[5]&=r[3];
goto P_0c05e18e;
P_0c05e18e: /* original 420b, guest PC 0x0c05e18e */
if(!s->budget--) { s->failed_pc=0x0c05e18eu; return 0; }
target=r[2];
r[16]=code_base|0x0c05e192u;
r[4]=0x00000078u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e192u) { target=s->pc; goto dispatch; }
goto P_0c05e192;
P_0c05e190: /* original e478, guest PC 0x0c05e190 */
if(!s->budget--) { s->failed_pc=0x0c05e190u; return 0; }
r[4]=0x00000078u;
goto P_0c05e192;
P_0c05e192: /* original 7f04, guest PC 0x0c05e192 */
if(!s->budget--) { s->failed_pc=0x0c05e192u; return 0; }
r[15]+=0x00000004u;
goto P_0c05e194;
P_0c05e194: /* original 4f26, guest PC 0x0c05e194 */
if(!s->budget--) { s->failed_pc=0x0c05e194u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e196;
P_0c05e196: /* original 000b, guest PC 0x0c05e196 */
if(!s->budget--) { s->failed_pc=0x0c05e196u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05e198: /* original e000, guest PC 0x0c05e198 */
if(!s->budget--) { s->failed_pc=0x0c05e198u; return 0; }
r[0]=0x00000000u;
goto P_0c05e19a;
P_0c05e19a: /* original 4f22, guest PC 0x0c05e19a */
if(!s->budget--) { s->failed_pc=0x0c05e19au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e19c;
P_0c05e19c: /* original 946b, guest PC 0x0c05e19c */
if(!s->budget--) { s->failed_pc=0x0c05e19cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e276u,2);
goto P_0c05e19e;
P_0c05e19e: /* original d33f, guest PC 0x0c05e19e */
if(!s->budget--) { s->failed_pc=0x0c05e19eu; return 0; }
r[3]=read(ram,0x0c05e29cu,4);
goto P_0c05e1a0;
P_0c05e1a0: /* original 430b, guest PC 0x0c05e1a0 */
if(!s->budget--) { s->failed_pc=0x0c05e1a0u; return 0; }
target=r[3];
r[16]=code_base|0x0c05e1a4u;
r[5]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e1a4u) { target=s->pc; goto dispatch; }
goto P_0c05e1a4;
P_0c05e1a2: /* original 55f1, guest PC 0x0c05e1a2 */
if(!s->budget--) { s->failed_pc=0x0c05e1a2u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c05e1a4;
P_0c05e1a4: /* original 9468, guest PC 0x0c05e1a4 */
if(!s->budget--) { s->failed_pc=0x0c05e1a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e278u,2);
goto P_0c05e1a6;
P_0c05e1a6: /* original d33d, guest PC 0x0c05e1a6 */
if(!s->budget--) { s->failed_pc=0x0c05e1a6u; return 0; }
r[3]=read(ram,0x0c05e29cu,4);
goto P_0c05e1a8;
P_0c05e1a8: /* original 430b, guest PC 0x0c05e1a8 */
if(!s->budget--) { s->failed_pc=0x0c05e1a8u; return 0; }
target=r[3];
r[16]=code_base|0x0c05e1acu;
r[5]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e1acu) { target=s->pc; goto dispatch; }
goto P_0c05e1ac;
P_0c05e1aa: /* original 55f2, guest PC 0x0c05e1aa */
if(!s->budget--) { s->failed_pc=0x0c05e1aau; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c05e1ac;
P_0c05e1ac: /* original 4f26, guest PC 0x0c05e1ac */
if(!s->budget--) { s->failed_pc=0x0c05e1acu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e1ae;
P_0c05e1ae: /* original 000b, guest PC 0x0c05e1ae */
if(!s->budget--) { s->failed_pc=0x0c05e1aeu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05e1b0: /* original e000, guest PC 0x0c05e1b0 */
if(!s->budget--) { s->failed_pc=0x0c05e1b0u; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c05e1b2u,s,ram);
P_0c05e1c2: /* original 4f22, guest PC 0x0c05e1c2 */
if(!s->budget--) { s->failed_pc=0x0c05e1c2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e1c4;
P_0c05e1c4: /* original 945a, guest PC 0x0c05e1c4 */
if(!s->budget--) { s->failed_pc=0x0c05e1c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e27cu,2);
goto P_0c05e1c6;
P_0c05e1c6: /* original d335, guest PC 0x0c05e1c6 */
if(!s->budget--) { s->failed_pc=0x0c05e1c6u; return 0; }
r[3]=read(ram,0x0c05e29cu,4);
goto P_0c05e1c8;
P_0c05e1c8: /* original 430b, guest PC 0x0c05e1c8 */
if(!s->budget--) { s->failed_pc=0x0c05e1c8u; return 0; }
target=r[3];
r[16]=code_base|0x0c05e1ccu;
r[5]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e1ccu) { target=s->pc; goto dispatch; }
goto P_0c05e1cc;
P_0c05e1ca: /* original 55f1, guest PC 0x0c05e1ca */
if(!s->budget--) { s->failed_pc=0x0c05e1cau; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c05e1cc;
P_0c05e1cc: /* original 4f26, guest PC 0x0c05e1cc */
if(!s->budget--) { s->failed_pc=0x0c05e1ccu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e1ce;
P_0c05e1ce: /* original 000b, guest PC 0x0c05e1ce */
if(!s->budget--) { s->failed_pc=0x0c05e1ceu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05e1d0: /* original e000, guest PC 0x0c05e1d0 */
if(!s->budget--) { s->failed_pc=0x0c05e1d0u; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c05e1d2u,s,ram);
P_0c05e332: /* original 4f22, guest PC 0x0c05e332 */
if(!s->budget--) { s->failed_pc=0x0c05e332u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e334;
P_0c05e334: /* original 55f1, guest PC 0x0c05e334 */
if(!s->budget--) { s->failed_pc=0x0c05e334u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c05e336;
P_0c05e336: /* original d333, guest PC 0x0c05e336 */
if(!s->budget--) { s->failed_pc=0x0c05e336u; return 0; }
r[3]=read(ram,0x0c05e404u,4);
goto P_0c05e338;
P_0c05e338: /* original 430b, guest PC 0x0c05e338 */
if(!s->budget--) { s->failed_pc=0x0c05e338u; return 0; }
target=r[3];
r[16]=code_base|0x0c05e33cu;
r[4]=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e33cu) { target=s->pc; goto dispatch; }
goto P_0c05e33c;
P_0c05e33a: /* original e440, guest PC 0x0c05e33a */
if(!s->budget--) { s->failed_pc=0x0c05e33au; return 0; }
r[4]=0x00000040u;
goto P_0c05e33c;
P_0c05e33c: /* original 4f26, guest PC 0x0c05e33c */
if(!s->budget--) { s->failed_pc=0x0c05e33cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e33e;
P_0c05e33e: /* original 000b, guest PC 0x0c05e33e */
if(!s->budget--) { s->failed_pc=0x0c05e33eu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05e340: /* original e000, guest PC 0x0c05e340 */
if(!s->budget--) { s->failed_pc=0x0c05e340u; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c05e342u,s,ram);
P_0c05e634: /* original 4f22, guest PC 0x0c05e634 */
if(!s->budget--) { s->failed_pc=0x0c05e634u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e636;
P_0c05e636: /* original d311, guest PC 0x0c05e636 */
if(!s->budget--) { s->failed_pc=0x0c05e636u; return 0; }
r[3]=read(ram,0x0c05e67cu,4);
goto P_0c05e638;
P_0c05e638: /* original 430b, guest PC 0x0c05e638 */
if(!s->budget--) { s->failed_pc=0x0c05e638u; return 0; }
target=r[3];
r[16]=code_base|0x0c05e63cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e63cu) { target=s->pc; goto dispatch; }
goto P_0c05e63c;
P_0c05e63a: /* original 0009, guest PC 0x0c05e63a */
if(!s->budget--) { s->failed_pc=0x0c05e63au; return 0; }
goto P_0c05e63c;
P_0c05e63c: /* original d210, guest PC 0x0c05e63c */
if(!s->budget--) { s->failed_pc=0x0c05e63cu; return 0; }
r[2]=read(ram,0x0c05e680u,4);
goto P_0c05e63e;
P_0c05e63e: /* original 420b, guest PC 0x0c05e63e */
if(!s->budget--) { s->failed_pc=0x0c05e63eu; return 0; }
target=r[2];
r[16]=code_base|0x0c05e642u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e642u) { target=s->pc; goto dispatch; }
goto P_0c05e642;
P_0c05e640: /* original 0009, guest PC 0x0c05e640 */
if(!s->budget--) { s->failed_pc=0x0c05e640u; return 0; }
goto P_0c05e642;
P_0c05e642: /* original 4f26, guest PC 0x0c05e642 */
if(!s->budget--) { s->failed_pc=0x0c05e642u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e644;
P_0c05e644: /* original 000b, guest PC 0x0c05e644 */
if(!s->budget--) { s->failed_pc=0x0c05e644u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05e646: /* original e000, guest PC 0x0c05e646 */
if(!s->budget--) { s->failed_pc=0x0c05e646u; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c05e648u,s,ram);
P_0c05e684: /* original e601, guest PC 0x0c05e684 */
if(!s->budget--) { s->failed_pc=0x0c05e684u; return 0; }
r[6]=0x00000001u;
goto P_0c05e686;
P_0c05e686: /* original 6343, guest PC 0x0c05e686 */
if(!s->budget--) { s->failed_pc=0x0c05e686u; return 0; }
r[3]=r[4];
goto P_0c05e688;
P_0c05e688: /* original 2368, guest PC 0x0c05e688 */
if(!s->budget--) { s->failed_pc=0x0c05e688u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c05e68a;
P_0c05e68a: /* original 8d06, guest PC 0x0c05e68a */
if(!s->budget--) { s->failed_pc=0x0c05e68au; return 0; }
cond=r[17]&1u;
r[5]=0x0000000bu;
if(cond) { goto P_0c05e69a; }
goto P_0c05e68e;
P_0c05e68c: /* original e50b, guest PC 0x0c05e68c */
if(!s->budget--) { s->failed_pc=0x0c05e68cu; return 0; }
r[5]=0x0000000bu;
goto P_0c05e68e;
P_0c05e68e: /* original d11e, guest PC 0x0c05e68e */
if(!s->budget--) { s->failed_pc=0x0c05e68eu; return 0; }
r[1]=read(ram,0x0c05e708u,4);
goto P_0c05e690;
P_0c05e690: /* original 2162, guest PC 0x0c05e690 */
if(!s->budget--) { s->failed_pc=0x0c05e690u; return 0; }
write(ram,r[1],r[6],4);
goto P_0c05e692;
P_0c05e692: /* original d31e, guest PC 0x0c05e692 */
if(!s->budget--) { s->failed_pc=0x0c05e692u; return 0; }
r[3]=read(ram,0x0c05e70cu,4);
goto P_0c05e694;
P_0c05e694: /* original 2342, guest PC 0x0c05e694 */
if(!s->budget--) { s->failed_pc=0x0c05e694u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c05e696;
P_0c05e696: /* original a003, guest PC 0x0c05e696 */
if(!s->budget--) { s->failed_pc=0x0c05e696u; return 0; }
r[5]=0x00000000u;
goto P_0c05e6a0;
P_0c05e698: /* original e500, guest PC 0x0c05e698 */
if(!s->budget--) { s->failed_pc=0x0c05e698u; return 0; }
r[5]=0x00000000u;
goto P_0c05e69a;
P_0c05e69a: /* original e300, guest PC 0x0c05e69a */
if(!s->budget--) { s->failed_pc=0x0c05e69au; return 0; }
r[3]=0x00000000u;
goto P_0c05e69c;
P_0c05e69c: /* original d21a, guest PC 0x0c05e69c */
if(!s->budget--) { s->failed_pc=0x0c05e69cu; return 0; }
r[2]=read(ram,0x0c05e708u,4);
goto P_0c05e69e;
P_0c05e69e: /* original 2232, guest PC 0x0c05e69e */
if(!s->budget--) { s->failed_pc=0x0c05e69eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c05e6a0;
P_0c05e6a0: /* original d01b, guest PC 0x0c05e6a0 */
if(!s->budget--) { s->failed_pc=0x0c05e6a0u; return 0; }
r[0]=read(ram,0x0c05e710u,4);
goto P_0c05e6a2;
P_0c05e6a2: /* original e103, guest PC 0x0c05e6a2 */
if(!s->budget--) { s->failed_pc=0x0c05e6a2u; return 0; }
r[1]=0x00000003u;
goto P_0c05e6a4;
P_0c05e6a4: /* original 2012, guest PC 0x0c05e6a4 */
if(!s->budget--) { s->failed_pc=0x0c05e6a4u; return 0; }
write(ram,r[0],r[1],4);
goto P_0c05e6a6;
P_0c05e6a6: /* original 000b, guest PC 0x0c05e6a6 */
if(!s->budget--) { s->failed_pc=0x0c05e6a6u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c05e6a8: /* original 6053, guest PC 0x0c05e6a8 */
if(!s->budget--) { s->failed_pc=0x0c05e6a8u; return 0; }
r[0]=r[5];
return vf3_matrix_family(0x0c05e6aau,s,ram);
P_0c05e6b4: /* original 4f22, guest PC 0x0c05e6b4 */
if(!s->budget--) { s->failed_pc=0x0c05e6b4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e6b6;
P_0c05e6b6: /* original 7ff8, guest PC 0x0c05e6b6 */
if(!s->budget--) { s->failed_pc=0x0c05e6b6u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c05e6b8;
P_0c05e6b8: /* original d317, guest PC 0x0c05e6b8 */
if(!s->budget--) { s->failed_pc=0x0c05e6b8u; return 0; }
r[3]=read(ram,0x0c05e718u,4);
goto P_0c05e6ba;
P_0c05e6ba: /* original 1f41, guest PC 0x0c05e6ba */
if(!s->budget--) { s->failed_pc=0x0c05e6bau; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c05e6bc;
P_0c05e6bc: /* original 9421, guest PC 0x0c05e6bc */
if(!s->budget--) { s->failed_pc=0x0c05e6bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e702u,2);
goto P_0c05e6be;
P_0c05e6be: /* original 430b, guest PC 0x0c05e6be */
if(!s->budget--) { s->failed_pc=0x0c05e6beu; return 0; }
target=r[3];
r[16]=code_base|0x0c05e6c2u;
write(ram,r[15],r[5],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e6c2u) { target=s->pc; goto dispatch; }
goto P_0c05e6c2;
P_0c05e6c0: /* original 2f52, guest PC 0x0c05e6c0 */
if(!s->budget--) { s->failed_pc=0x0c05e6c0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c05e6c2;
P_0c05e6c2: /* original 6403, guest PC 0x0c05e6c2 */
if(!s->budget--) { s->failed_pc=0x0c05e6c2u; return 0; }
r[4]=r[0];
goto P_0c05e6c4;
P_0c05e6c4: /* original 951e, guest PC 0x0c05e6c4 */
if(!s->budget--) { s->failed_pc=0x0c05e6c4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e704u,2);
goto P_0c05e6c6;
P_0c05e6c6: /* original 6343, guest PC 0x0c05e6c6 */
if(!s->budget--) { s->failed_pc=0x0c05e6c6u; return 0; }
r[3]=r[4];
goto P_0c05e6c8;
P_0c05e6c8: /* original 52f1, guest PC 0x0c05e6c8 */
if(!s->budget--) { s->failed_pc=0x0c05e6c8u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c05e6ca;
P_0c05e6ca: /* original 2359, guest PC 0x0c05e6ca */
if(!s->budget--) { s->failed_pc=0x0c05e6cau; return 0; }
r[3]&=r[5];
goto P_0c05e6cc;
P_0c05e6cc: /* original 2232, guest PC 0x0c05e6cc */
if(!s->budget--) { s->failed_pc=0x0c05e6ccu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c05e6ce;
P_0c05e6ce: /* original 4429, guest PC 0x0c05e6ce */
if(!s->budget--) { s->failed_pc=0x0c05e6ceu; return 0; }
r[4]>>=16;
goto P_0c05e6d0;
P_0c05e6d0: /* original 62f2, guest PC 0x0c05e6d0 */
if(!s->budget--) { s->failed_pc=0x0c05e6d0u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c05e6d2;
P_0c05e6d2: /* original 2459, guest PC 0x0c05e6d2 */
if(!s->budget--) { s->failed_pc=0x0c05e6d2u; return 0; }
r[4]&=r[5];
goto P_0c05e6d4;
P_0c05e6d4: /* original 2242, guest PC 0x0c05e6d4 */
if(!s->budget--) { s->failed_pc=0x0c05e6d4u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c05e6d6;
P_0c05e6d6: /* original 7f08, guest PC 0x0c05e6d6 */
if(!s->budget--) { s->failed_pc=0x0c05e6d6u; return 0; }
r[15]+=0x00000008u;
goto P_0c05e6d8;
P_0c05e6d8: /* original 4f26, guest PC 0x0c05e6d8 */
if(!s->budget--) { s->failed_pc=0x0c05e6d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e6da;
P_0c05e6da: /* original 000b, guest PC 0x0c05e6da */
if(!s->budget--) { s->failed_pc=0x0c05e6dau; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05e6dc: /* original e000, guest PC 0x0c05e6dc */
if(!s->budget--) { s->failed_pc=0x0c05e6dcu; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c05e6deu,s,ram);
P_0c05e728: /* original 4f22, guest PC 0x0c05e728 */
if(!s->budget--) { s->failed_pc=0x0c05e728u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05e72a;
P_0c05e72a: /* original e2fb, guest PC 0x0c05e72a */
if(!s->budget--) { s->failed_pc=0x0c05e72au; return 0; }
r[2]=0xfffffffbu;
goto P_0c05e72c;
P_0c05e72c: /* original 9383, guest PC 0x0c05e72c */
if(!s->budget--) { s->failed_pc=0x0c05e72cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e836u,2);
goto P_0c05e72e;
P_0c05e72e: /* original 7ffc, guest PC 0x0c05e72e */
if(!s->budget--) { s->failed_pc=0x0c05e72eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05e730;
P_0c05e730: /* original 2439, guest PC 0x0c05e730 */
if(!s->budget--) { s->failed_pc=0x0c05e730u; return 0; }
r[4]&=r[3];
goto P_0c05e732;
P_0c05e732: /* original 442c, guest PC 0x0c05e732 */
if(!s->budget--) { s->failed_pc=0x0c05e732u; return 0; }
r[4]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[4]>>((-r[2])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[2]&31u);
goto P_0c05e734;
P_0c05e734: /* original 2f42, guest PC 0x0c05e734 */
if(!s->budget--) { s->failed_pc=0x0c05e734u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05e736;
P_0c05e736: /* original 947f, guest PC 0x0c05e736 */
if(!s->budget--) { s->failed_pc=0x0c05e736u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e838u,2);
goto P_0c05e738;
P_0c05e738: /* original d240, guest PC 0x0c05e738 */
if(!s->budget--) { s->failed_pc=0x0c05e738u; return 0; }
r[2]=read(ram,0x0c05e83cu,4);
goto P_0c05e73a;
P_0c05e73a: /* original 420b, guest PC 0x0c05e73a */
if(!s->budget--) { s->failed_pc=0x0c05e73au; return 0; }
target=r[2];
r[16]=code_base|0x0c05e73eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e73eu) { target=s->pc; goto dispatch; }
goto P_0c05e73e;
P_0c05e73c: /* original 0009, guest PC 0x0c05e73c */
if(!s->budget--) { s->failed_pc=0x0c05e73cu; return 0; }
goto P_0c05e73e;
P_0c05e73e: /* original e3e0, guest PC 0x0c05e73e */
if(!s->budget--) { s->failed_pc=0x0c05e73eu; return 0; }
r[3]=0xffffffe0u;
goto P_0c05e740;
P_0c05e740: /* original 65f2, guest PC 0x0c05e740 */
if(!s->budget--) { s->failed_pc=0x0c05e740u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c05e742;
P_0c05e742: /* original 2039, guest PC 0x0c05e742 */
if(!s->budget--) { s->failed_pc=0x0c05e742u; return 0; }
r[0]&=r[3];
goto P_0c05e744;
P_0c05e744: /* original 9478, guest PC 0x0c05e744 */
if(!s->budget--) { s->failed_pc=0x0c05e744u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05e838u,2);
goto P_0c05e746;
P_0c05e746: /* original d23e, guest PC 0x0c05e746 */
if(!s->budget--) { s->failed_pc=0x0c05e746u; return 0; }
r[2]=read(ram,0x0c05e840u,4);
goto P_0c05e748;
P_0c05e748: /* original 420b, guest PC 0x0c05e748 */
if(!s->budget--) { s->failed_pc=0x0c05e748u; return 0; }
target=r[2];
r[16]=code_base|0x0c05e74cu;
r[5]|=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05e74cu) { target=s->pc; goto dispatch; }
goto P_0c05e74c;
P_0c05e74a: /* original 250b, guest PC 0x0c05e74a */
if(!s->budget--) { s->failed_pc=0x0c05e74au; return 0; }
r[5]|=r[0];
goto P_0c05e74c;
P_0c05e74c: /* original 7f04, guest PC 0x0c05e74c */
if(!s->budget--) { s->failed_pc=0x0c05e74cu; return 0; }
r[15]+=0x00000004u;
goto P_0c05e74e;
P_0c05e74e: /* original 4f26, guest PC 0x0c05e74e */
if(!s->budget--) { s->failed_pc=0x0c05e74eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05e750;
P_0c05e750: /* original 000b, guest PC 0x0c05e750 */
if(!s->budget--) { s->failed_pc=0x0c05e750u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05e752: /* original e000, guest PC 0x0c05e752 */
if(!s->budget--) { s->failed_pc=0x0c05e752u; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c05e754u,s,ram);
P_0c05f33c: /* original 4f22, guest PC 0x0c05f33c */
if(!s->budget--) { s->failed_pc=0x0c05f33cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05f33e;
P_0c05f33e: /* original 7ff4, guest PC 0x0c05f33e */
if(!s->budget--) { s->failed_pc=0x0c05f33eu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c05f340;
P_0c05f340: /* original 2f62, guest PC 0x0c05f340 */
if(!s->budget--) { s->failed_pc=0x0c05f340u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c05f342;
P_0c05f342: /* original 1f52, guest PC 0x0c05f342 */
if(!s->budget--) { s->failed_pc=0x0c05f342u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c05f344;
P_0c05f344: /* original 1f41, guest PC 0x0c05f344 */
if(!s->budget--) { s->failed_pc=0x0c05f344u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c05f346;
P_0c05f346: /* original 65f2, guest PC 0x0c05f346 */
if(!s->budget--) { s->failed_pc=0x0c05f346u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c05f348;
P_0c05f348: /* original beb6, guest PC 0x0c05f348 */
if(!s->budget--) { s->failed_pc=0x0c05f348u; return 0; }
target=0x0c05f0b8u; r[16]=code_base|0x0c05f34cu;
r[4]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05f34cu) { target=s->pc; goto dispatch; }
goto P_0c05f34c;
P_0c05f34a: /* original 6453, guest PC 0x0c05f34a */
if(!s->budget--) { s->failed_pc=0x0c05f34au; return 0; }
r[4]=r[5];
goto P_0c05f34c;
P_0c05f34c: /* original 2f02, guest PC 0x0c05f34c */
if(!s->budget--) { s->failed_pc=0x0c05f34cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c05f34e;
P_0c05f34e: /* original 6603, guest PC 0x0c05f34e */
if(!s->budget--) { s->failed_pc=0x0c05f34eu; return 0; }
r[6]=r[0];
goto P_0c05f350;
P_0c05f350: /* original d315, guest PC 0x0c05f350 */
if(!s->budget--) { s->failed_pc=0x0c05f350u; return 0; }
r[3]=read(ram,0x0c05f3a8u,4);
goto P_0c05f352;
P_0c05f352: /* original 4608, guest PC 0x0c05f352 */
if(!s->budget--) { s->failed_pc=0x0c05f352u; return 0; }
r[6]<<=2;
goto P_0c05f354;
P_0c05f354: /* original d012, guest PC 0x0c05f354 */
if(!s->budget--) { s->failed_pc=0x0c05f354u; return 0; }
r[0]=read(ram,0x0c05f3a0u,4);
goto P_0c05f356;
P_0c05f356: /* original 066e, guest PC 0x0c05f356 */
if(!s->budget--) { s->failed_pc=0x0c05f356u; return 0; }
r[6]=read(ram,r[6]+r[0],4);
goto P_0c05f358;
P_0c05f358: /* original 55f2, guest PC 0x0c05f358 */
if(!s->budget--) { s->failed_pc=0x0c05f358u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c05f35a;
P_0c05f35a: /* original 54f1, guest PC 0x0c05f35a */
if(!s->budget--) { s->failed_pc=0x0c05f35au; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c05f35c;
P_0c05f35c: /* original 7f0c, guest PC 0x0c05f35c */
if(!s->budget--) { s->failed_pc=0x0c05f35cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c05f35e;
P_0c05f35e: /* original 432b, guest PC 0x0c05f35e */
if(!s->budget--) { s->failed_pc=0x0c05f35eu; return 0; }
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
P_0c05f360: /* original 4f26, guest PC 0x0c05f360 */
if(!s->budget--) { s->failed_pc=0x0c05f360u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c05f362u,s,ram);
P_0c05f3ea: /* original 4f22, guest PC 0x0c05f3ea */
if(!s->budget--) { s->failed_pc=0x0c05f3eau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05f3ec;
P_0c05f3ec: /* original 7ff8, guest PC 0x0c05f3ec */
if(!s->budget--) { s->failed_pc=0x0c05f3ecu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c05f3ee;
P_0c05f3ee: /* original 2f62, guest PC 0x0c05f3ee */
if(!s->budget--) { s->failed_pc=0x0c05f3eeu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c05f3f0;
P_0c05f3f0: /* original 1f71, guest PC 0x0c05f3f0 */
if(!s->budget--) { s->failed_pc=0x0c05f3f0u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c05f3f2;
P_0c05f3f2: /* original 65f2, guest PC 0x0c05f3f2 */
if(!s->budget--) { s->failed_pc=0x0c05f3f2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c05f3f4;
P_0c05f3f4: /* original be60, guest PC 0x0c05f3f4 */
if(!s->budget--) { s->failed_pc=0x0c05f3f4u; return 0; }
target=0x0c05f0b8u; r[16]=code_base|0x0c05f3f8u;
r[4]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05f3f8u) { target=s->pc; goto dispatch; }
goto P_0c05f3f8;
P_0c05f3f6: /* original 6453, guest PC 0x0c05f3f6 */
if(!s->budget--) { s->failed_pc=0x0c05f3f6u; return 0; }
r[4]=r[5];
goto P_0c05f3f8;
P_0c05f3f8: /* original 6403, guest PC 0x0c05f3f8 */
if(!s->budget--) { s->failed_pc=0x0c05f3f8u; return 0; }
r[4]=r[0];
goto P_0c05f3fa;
P_0c05f3fa: /* original 6203, guest PC 0x0c05f3fa */
if(!s->budget--) { s->failed_pc=0x0c05f3fau; return 0; }
r[2]=r[0];
goto P_0c05f3fc;
P_0c05f3fc: /* original 50f1, guest PC 0x0c05f3fc */
if(!s->budget--) { s->failed_pc=0x0c05f3fcu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c05f3fe;
P_0c05f3fe: /* original c801, guest PC 0x0c05f3fe */
if(!s->budget--) { s->failed_pc=0x0c05f3feu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c05f400;
P_0c05f400: /* original 8d06, guest PC 0x0c05f400 */
if(!s->budget--) { s->failed_pc=0x0c05f400u; return 0; }
cond=r[17]&1u;
r[2]<<=2;
if(cond) { goto P_0c05f410; }
goto P_0c05f404;
P_0c05f402: /* original 4208, guest PC 0x0c05f402 */
if(!s->budget--) { s->failed_pc=0x0c05f402u; return 0; }
r[2]<<=2;
goto P_0c05f404;
P_0c05f404: /* original d032, guest PC 0x0c05f404 */
if(!s->budget--) { s->failed_pc=0x0c05f404u; return 0; }
r[0]=read(ram,0x0c05f4d0u,4);
goto P_0c05f406;
P_0c05f406: /* original 0c2e, guest PC 0x0c05f406 */
if(!s->budget--) { s->failed_pc=0x0c05f406u; return 0; }
r[12]=read(ram,r[2]+r[0],4);
goto P_0c05f408;
P_0c05f408: /* original d032, guest PC 0x0c05f408 */
if(!s->budget--) { s->failed_pc=0x0c05f408u; return 0; }
r[0]=read(ram,0x0c05f4d4u,4);
goto P_0c05f40a;
P_0c05f40a: /* original 0a2e, guest PC 0x0c05f40a */
if(!s->budget--) { s->failed_pc=0x0c05f40au; return 0; }
r[10]=read(ram,r[2]+r[0],4);
goto P_0c05f40c;
P_0c05f40c: /* original a004, guest PC 0x0c05f40c */
if(!s->budget--) { s->failed_pc=0x0c05f40cu; return 0; }
r[10]+=0x0000000au;
goto P_0c05f418;
P_0c05f40e: /* original 7a0a, guest PC 0x0c05f40e */
if(!s->budget--) { s->failed_pc=0x0c05f40eu; return 0; }
r[10]+=0x0000000au;
goto P_0c05f410;
P_0c05f410: /* original d02c, guest PC 0x0c05f410 */
if(!s->budget--) { s->failed_pc=0x0c05f410u; return 0; }
r[0]=read(ram,0x0c05f4c4u,4);
goto P_0c05f412;
P_0c05f412: /* original 0c2e, guest PC 0x0c05f412 */
if(!s->budget--) { s->failed_pc=0x0c05f412u; return 0; }
r[12]=read(ram,r[2]+r[0],4);
goto P_0c05f414;
P_0c05f414: /* original d02c, guest PC 0x0c05f414 */
if(!s->budget--) { s->failed_pc=0x0c05f414u; return 0; }
r[0]=read(ram,0x0c05f4c8u,4);
goto P_0c05f416;
P_0c05f416: /* original 0a2e, guest PC 0x0c05f416 */
if(!s->budget--) { s->failed_pc=0x0c05f416u; return 0; }
r[10]=read(ram,r[2]+r[0],4);
goto P_0c05f418;
P_0c05f418: /* original d22f, guest PC 0x0c05f418 */
if(!s->budget--) { s->failed_pc=0x0c05f418u; return 0; }
r[2]=read(ram,0x0c05f4d8u,4);
goto P_0c05f41a;
P_0c05f41a: /* original 66c3, guest PC 0x0c05f41a */
if(!s->budget--) { s->failed_pc=0x0c05f41au; return 0; }
r[6]=r[12];
goto P_0c05f41c;
P_0c05f41c: /* original 65d3, guest PC 0x0c05f41c */
if(!s->budget--) { s->failed_pc=0x0c05f41cu; return 0; }
r[5]=r[13];
goto P_0c05f41e;
P_0c05f41e: /* original 420b, guest PC 0x0c05f41e */
if(!s->budget--) { s->failed_pc=0x0c05f41eu; return 0; }
target=r[2];
r[16]=code_base|0x0c05f422u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05f422u) { target=s->pc; goto dispatch; }
goto P_0c05f422;
P_0c05f420: /* original 64e3, guest PC 0x0c05f420 */
if(!s->budget--) { s->failed_pc=0x0c05f420u; return 0; }
r[4]=r[14];
goto P_0c05f422;
P_0c05f422: /* original 3ecc, guest PC 0x0c05f422 */
if(!s->budget--) { s->failed_pc=0x0c05f422u; return 0; }
r[14]+=r[12];
goto P_0c05f424;
P_0c05f424: /* original d22c, guest PC 0x0c05f424 */
if(!s->budget--) { s->failed_pc=0x0c05f424u; return 0; }
r[2]=read(ram,0x0c05f4d8u,4);
goto P_0c05f426;
P_0c05f426: /* original 66a3, guest PC 0x0c05f426 */
if(!s->budget--) { s->failed_pc=0x0c05f426u; return 0; }
r[6]=r[10];
goto P_0c05f428;
P_0c05f428: /* original 934b, guest PC 0x0c05f428 */
if(!s->budget--) { s->failed_pc=0x0c05f428u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f4c2u,2);
goto P_0c05f42a;
P_0c05f42a: /* original 7f08, guest PC 0x0c05f42a */
if(!s->budget--) { s->failed_pc=0x0c05f42au; return 0; }
r[15]+=0x00000008u;
goto P_0c05f42c;
P_0c05f42c: /* original 4f26, guest PC 0x0c05f42c */
if(!s->budget--) { s->failed_pc=0x0c05f42cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05f42e;
P_0c05f42e: /* original 3d3c, guest PC 0x0c05f42e */
if(!s->budget--) { s->failed_pc=0x0c05f42eu; return 0; }
r[13]+=r[3];
goto P_0c05f430;
P_0c05f430: /* original 6af6, guest PC 0x0c05f430 */
if(!s->budget--) { s->failed_pc=0x0c05f430u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05f432;
P_0c05f432: /* original 64e3, guest PC 0x0c05f432 */
if(!s->budget--) { s->failed_pc=0x0c05f432u; return 0; }
r[4]=r[14];
goto P_0c05f434;
P_0c05f434: /* original 6cf6, guest PC 0x0c05f434 */
if(!s->budget--) { s->failed_pc=0x0c05f434u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05f436;
P_0c05f436: /* original 65d3, guest PC 0x0c05f436 */
if(!s->budget--) { s->failed_pc=0x0c05f436u; return 0; }
r[5]=r[13];
goto P_0c05f438;
P_0c05f438: /* original 6df6, guest PC 0x0c05f438 */
if(!s->budget--) { s->failed_pc=0x0c05f438u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05f43a;
P_0c05f43a: /* original 422b, guest PC 0x0c05f43a */
if(!s->budget--) { s->failed_pc=0x0c05f43au; return 0; }
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
P_0c05f43c: /* original 6ef6, guest PC 0x0c05f43c */
if(!s->budget--) { s->failed_pc=0x0c05f43cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c05f43eu,s,ram);
P_0c05ff82: /* original 4f22, guest PC 0x0c05ff82 */
if(!s->budget--) { s->failed_pc=0x0c05ff82u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05ff84;
P_0c05ff84: /* original 7ffc, guest PC 0x0c05ff84 */
if(!s->budget--) { s->failed_pc=0x0c05ff84u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05ff86;
P_0c05ff86: /* original 2f42, guest PC 0x0c05ff86 */
if(!s->budget--) { s->failed_pc=0x0c05ff86u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05ff88;
P_0c05ff88: /* original 6053, guest PC 0x0c05ff88 */
if(!s->budget--) { s->failed_pc=0x0c05ff88u; return 0; }
r[0]=r[5];
goto P_0c05ff8a;
P_0c05ff8a: /* original 0009, guest PC 0x0c05ff8a */
if(!s->budget--) { s->failed_pc=0x0c05ff8au; return 0; }
goto P_0c05ff8c;
P_0c05ff8c: /* original 8803, guest PC 0x0c05ff8c */
if(!s->budget--) { s->failed_pc=0x0c05ff8cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05ff8e;
P_0c05ff8e: /* original 8f01, guest PC 0x0c05ff8e */
if(!s->budget--) { s->failed_pc=0x0c05ff8eu; return 0; }
cond=r[17]&1u;
r[1]=0x00000000u;
if(!cond) { goto P_0c05ff94; }
goto P_0c05ff92;
P_0c05ff90: /* original e100, guest PC 0x0c05ff90 */
if(!s->budget--) { s->failed_pc=0x0c05ff90u; return 0; }
r[1]=0x00000000u;
goto P_0c05ff92;
P_0c05ff92: /* original d11d, guest PC 0x0c05ff92 */
if(!s->budget--) { s->failed_pc=0x0c05ff92u; return 0; }
r[1]=read(ram,0x0c060008u,4);
goto P_0c05ff94;
P_0c05ff94: /* original 54f2, guest PC 0x0c05ff94 */
if(!s->budget--) { s->failed_pc=0x0c05ff94u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c05ff96;
P_0c05ff96: /* original 77ff, guest PC 0x0c05ff96 */
if(!s->budget--) { s->failed_pc=0x0c05ff96u; return 0; }
r[7]+=0xffffffffu;
goto P_0c05ff98;
P_0c05ff98: /* original e53f, guest PC 0x0c05ff98 */
if(!s->budget--) { s->failed_pc=0x0c05ff98u; return 0; }
r[5]=0x0000003fu;
goto P_0c05ff9a;
P_0c05ff9a: /* original 74ff, guest PC 0x0c05ff9a */
if(!s->budget--) { s->failed_pc=0x0c05ff9au; return 0; }
r[4]+=0xffffffffu;
goto P_0c05ff9c;
P_0c05ff9c: /* original 2459, guest PC 0x0c05ff9c */
if(!s->budget--) { s->failed_pc=0x0c05ff9cu; return 0; }
r[4]&=r[5];
goto P_0c05ff9e;
P_0c05ff9e: /* original 4418, guest PC 0x0c05ff9e */
if(!s->budget--) { s->failed_pc=0x0c05ff9eu; return 0; }
r[4]<<=8;
goto P_0c05ffa0;
P_0c05ffa0: /* original 2759, guest PC 0x0c05ffa0 */
if(!s->budget--) { s->failed_pc=0x0c05ffa0u; return 0; }
r[7]&=r[5];
goto P_0c05ffa2;
P_0c05ffa2: /* original 247b, guest PC 0x0c05ffa2 */
if(!s->budget--) { s->failed_pc=0x0c05ffa2u; return 0; }
r[4]|=r[7];
goto P_0c05ffa4;
P_0c05ffa4: /* original 2668, guest PC 0x0c05ffa4 */
if(!s->budget--) { s->failed_pc=0x0c05ffa4u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c05ffa6;
P_0c05ffa6: /* original 8f02, guest PC 0x0c05ffa6 */
if(!s->budget--) { s->failed_pc=0x0c05ffa6u; return 0; }
cond=r[17]&1u;
r[4]|=r[1];
if(!cond) { goto P_0c05ffae; }
goto P_0c05ffaa;
P_0c05ffa8: /* original 241b, guest PC 0x0c05ffa8 */
if(!s->budget--) { s->failed_pc=0x0c05ffa8u; return 0; }
r[4]|=r[1];
goto P_0c05ffaa;
P_0c05ffaa: /* original a002, guest PC 0x0c05ffaa */
if(!s->budget--) { s->failed_pc=0x0c05ffaau; return 0; }
r[5]=r[4];
goto P_0c05ffb2;
P_0c05ffac: /* original 6543, guest PC 0x0c05ffac */
if(!s->budget--) { s->failed_pc=0x0c05ffacu; return 0; }
r[5]=r[4];
goto P_0c05ffae;
P_0c05ffae: /* original d517, guest PC 0x0c05ffae */
if(!s->budget--) { s->failed_pc=0x0c05ffaeu; return 0; }
r[5]=read(ram,0x0c06000cu,4);
goto P_0c05ffb0;
P_0c05ffb0: /* original 254b, guest PC 0x0c05ffb0 */
if(!s->budget--) { s->failed_pc=0x0c05ffb0u; return 0; }
r[5]|=r[4];
goto P_0c05ffb2;
P_0c05ffb2: /* original 941f, guest PC 0x0c05ffb2 */
if(!s->budget--) { s->failed_pc=0x0c05ffb2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05fff4u,2);
goto P_0c05ffb4;
P_0c05ffb4: /* original d316, guest PC 0x0c05ffb4 */
if(!s->budget--) { s->failed_pc=0x0c05ffb4u; return 0; }
r[3]=read(ram,0x0c060010u,4);
goto P_0c05ffb6;
P_0c05ffb6: /* original 430b, guest PC 0x0c05ffb6 */
if(!s->budget--) { s->failed_pc=0x0c05ffb6u; return 0; }
target=r[3];
r[16]=code_base|0x0c05ffbau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05ffbau) { target=s->pc; goto dispatch; }
goto P_0c05ffba;
P_0c05ffb8: /* original 0009, guest PC 0x0c05ffb8 */
if(!s->budget--) { s->failed_pc=0x0c05ffb8u; return 0; }
goto P_0c05ffba;
P_0c05ffba: /* original 65f2, guest PC 0x0c05ffba */
if(!s->budget--) { s->failed_pc=0x0c05ffbau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c05ffbc;
P_0c05ffbc: /* original 941b, guest PC 0x0c05ffbc */
if(!s->budget--) { s->failed_pc=0x0c05ffbcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05fff6u,2);
goto P_0c05ffbe;
P_0c05ffbe: /* original d314, guest PC 0x0c05ffbe */
if(!s->budget--) { s->failed_pc=0x0c05ffbeu; return 0; }
r[3]=read(ram,0x0c060010u,4);
goto P_0c05ffc0;
P_0c05ffc0: /* original 430b, guest PC 0x0c05ffc0 */
if(!s->budget--) { s->failed_pc=0x0c05ffc0u; return 0; }
target=r[3];
r[16]=code_base|0x0c05ffc4u;
r[5]=read(ram,r[5]+28,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05ffc4u) { target=s->pc; goto dispatch; }
goto P_0c05ffc4;
P_0c05ffc2: /* original 5557, guest PC 0x0c05ffc2 */
if(!s->budget--) { s->failed_pc=0x0c05ffc2u; return 0; }
r[5]=read(ram,r[5]+28,4);
goto P_0c05ffc4;
P_0c05ffc4: /* original 7f04, guest PC 0x0c05ffc4 */
if(!s->budget--) { s->failed_pc=0x0c05ffc4u; return 0; }
r[15]+=0x00000004u;
goto P_0c05ffc6;
P_0c05ffc6: /* original 4f26, guest PC 0x0c05ffc6 */
if(!s->budget--) { s->failed_pc=0x0c05ffc6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05ffc8;
P_0c05ffc8: /* original 000b, guest PC 0x0c05ffc8 */
if(!s->budget--) { s->failed_pc=0x0c05ffc8u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05ffca: /* original e000, guest PC 0x0c05ffca */
if(!s->budget--) { s->failed_pc=0x0c05ffcau; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c05ffccu,s,ram);
P_0c062e60: /* original 6043, guest PC 0x0c062e60 */
if(!s->budget--) { s->failed_pc=0x0c062e60u; return 0; }
r[0]=r[4];
goto P_0c062e62;
P_0c062e62: /* original 205b, guest PC 0x0c062e62 */
if(!s->budget--) { s->failed_pc=0x0c062e62u; return 0; }
r[0]|=r[5];
goto P_0c062e64;
P_0c062e64: /* original 206b, guest PC 0x0c062e64 */
if(!s->budget--) { s->failed_pc=0x0c062e64u; return 0; }
r[0]|=r[6];
goto P_0c062e66;
P_0c062e66: /* original c807, guest PC 0x0c062e66 */
if(!s->budget--) { s->failed_pc=0x0c062e66u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&7u)==0)!=0);
goto P_0c062e68;
P_0c062e68: /* original 8b09, guest PC 0x0c062e68 */
if(!s->budget--) { s->failed_pc=0x0c062e68u; return 0; }
cond=r[17]&1u;
if(!cond) { return vf3_matrix_family(0x0c062e7eu,s,ram); }
goto P_0c062e6a;
P_0c062e6a: /* original f3fd, guest PC 0x0c062e6a */
if(!s->budget--) { s->failed_pc=0x0c062e6au; return 0; }
r[18]^=0x100000u;
goto P_0c062e6c;
P_0c062e6c: /* original 4609, guest PC 0x0c062e6c */
if(!s->budget--) { s->failed_pc=0x0c062e6cu; return 0; }
r[6]>>=2;
goto P_0c062e6e;
P_0c062e6e: /* original 4601, guest PC 0x0c062e6e */
if(!s->budget--) { s->failed_pc=0x0c062e6eu; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c062e70;
P_0c062e70: /* original f059, guest PC 0x0c062e70 */
if(!s->budget--) { s->failed_pc=0x0c062e70u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c062e72;
P_0c062e72: /* original 4610, guest PC 0x0c062e72 */
if(!s->budget--) { s->failed_pc=0x0c062e72u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c062e74;
P_0c062e74: /* original f40a, guest PC 0x0c062e74 */
if(!s->budget--) { s->failed_pc=0x0c062e74u; return 0; }
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c062e76;
P_0c062e76: /* original 8ffb, guest PC 0x0c062e76 */
if(!s->budget--) { s->failed_pc=0x0c062e76u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000008u;
if(!cond) { goto P_0c062e70; }
goto P_0c062e7a;
P_0c062e78: /* original 7408, guest PC 0x0c062e78 */
if(!s->budget--) { s->failed_pc=0x0c062e78u; return 0; }
r[4]+=0x00000008u;
goto P_0c062e7a;
P_0c062e7a: /* original 000b, guest PC 0x0c062e7a */
if(!s->budget--) { s->failed_pc=0x0c062e7au; return 0; }
target=r[16];
r[18]^=0x100000u;
s->pc=target; return ram->oob==0;
P_0c062e7c: /* original f3fd, guest PC 0x0c062e7c */
if(!s->budget--) { s->failed_pc=0x0c062e7cu; return 0; }
r[18]^=0x100000u;
return vf3_matrix_family(0x0c062e7eu,s,ram);
P_0c063418: /* original 2fe6, guest PC 0x0c063418 */
if(!s->budget--) { s->failed_pc=0x0c063418u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06341a;
P_0c06341a: /* original e503, guest PC 0x0c06341a */
if(!s->budget--) { s->failed_pc=0x0c06341au; return 0; }
r[5]=0x00000003u;
goto P_0c06341c;
P_0c06341c: /* original 4f22, guest PC 0x0c06341c */
if(!s->budget--) { s->failed_pc=0x0c06341cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06341e;
P_0c06341e: /* original de34, guest PC 0x0c06341e */
if(!s->budget--) { s->failed_pc=0x0c06341eu; return 0; }
r[14]=read(ram,0x0c0634f0u,4);
goto P_0c063420;
P_0c063420: /* original 4e0b, guest PC 0x0c063420 */
if(!s->budget--) { s->failed_pc=0x0c063420u; return 0; }
target=r[14];
r[16]=code_base|0x0c063424u;
r[4]=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063424u) { target=s->pc; goto dispatch; }
goto P_0c063424;
P_0c063422: /* original e408, guest PC 0x0c063422 */
if(!s->budget--) { s->failed_pc=0x0c063422u; return 0; }
r[4]=0x00000008u;
goto P_0c063424;
P_0c063424: /* original e500, guest PC 0x0c063424 */
if(!s->budget--) { s->failed_pc=0x0c063424u; return 0; }
r[5]=0x00000000u;
goto P_0c063426;
P_0c063426: /* original 4e0b, guest PC 0x0c063426 */
if(!s->budget--) { s->failed_pc=0x0c063426u; return 0; }
target=r[14];
r[16]=code_base|0x0c06342au;
r[4]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06342au) { target=s->pc; goto dispatch; }
goto P_0c06342a;
P_0c063428: /* original 6453, guest PC 0x0c063428 */
if(!s->budget--) { s->failed_pc=0x0c063428u; return 0; }
r[4]=r[5];
goto P_0c06342a;
P_0c06342a: /* original e500, guest PC 0x0c06342a */
if(!s->budget--) { s->failed_pc=0x0c06342au; return 0; }
r[5]=0x00000000u;
goto P_0c06342c;
P_0c06342c: /* original 4e0b, guest PC 0x0c06342c */
if(!s->budget--) { s->failed_pc=0x0c06342cu; return 0; }
target=r[14];
r[16]=code_base|0x0c063430u;
r[4]=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063430u) { target=s->pc; goto dispatch; }
goto P_0c063430;
P_0c06342e: /* original e408, guest PC 0x0c06342e */
if(!s->budget--) { s->failed_pc=0x0c06342eu; return 0; }
r[4]=0x00000008u;
goto P_0c063430;
P_0c063430: /* original 4f26, guest PC 0x0c063430 */
if(!s->budget--) { s->failed_pc=0x0c063430u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c063432;
P_0c063432: /* original 000b, guest PC 0x0c063432 */
if(!s->budget--) { s->failed_pc=0x0c063432u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c063434: /* original 6ef6, guest PC 0x0c063434 */
if(!s->budget--) { s->failed_pc=0x0c063434u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c063436u,s,ram);
P_0c0641f4: /* original 4f22, guest PC 0x0c0641f4 */
if(!s->budget--) { s->failed_pc=0x0c0641f4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0641f6;
P_0c0641f6: /* original e308, guest PC 0x0c0641f6 */
if(!s->budget--) { s->failed_pc=0x0c0641f6u; return 0; }
r[3]=0x00000008u;
goto P_0c0641f8;
P_0c0641f8: /* original d234, guest PC 0x0c0641f8 */
if(!s->budget--) { s->failed_pc=0x0c0641f8u; return 0; }
r[2]=read(ram,0x0c0642ccu,4);
goto P_0c0641fa;
P_0c0641fa: /* original 2232, guest PC 0x0c0641fa */
if(!s->budget--) { s->failed_pc=0x0c0641fau; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0641fc;
P_0c0641fc: /* original d434, guest PC 0x0c0641fc */
if(!s->budget--) { s->failed_pc=0x0c0641fcu; return 0; }
r[4]=read(ram,0x0c0642d0u,4);
goto P_0c0641fe;
P_0c0641fe: /* original 5347, guest PC 0x0c0641fe */
if(!s->budget--) { s->failed_pc=0x0c0641feu; return 0; }
r[3]=read(ram,r[4]+28,4);
goto P_0c064200;
P_0c064200: /* original d135, guest PC 0x0c064200 */
if(!s->budget--) { s->failed_pc=0x0c064200u; return 0; }
r[1]=read(ram,0x0c0642d8u,4);
goto P_0c064202;
P_0c064202: /* original 7301, guest PC 0x0c064202 */
if(!s->budget--) { s->failed_pc=0x0c064202u; return 0; }
r[3]+=0x00000001u;
goto P_0c064204;
P_0c064204: /* original 1437, guest PC 0x0c064204 */
if(!s->budget--) { s->failed_pc=0x0c064204u; return 0; }
write(ram,r[4]+28,r[3],4);
goto P_0c064206;
P_0c064206: /* original 6012, guest PC 0x0c064206 */
if(!s->budget--) { s->failed_pc=0x0c064206u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c064208;
P_0c064208: /* original 8801, guest PC 0x0c064208 */
if(!s->budget--) { s->failed_pc=0x0c064208u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06420a;
P_0c06420a: /* original 8b04, guest PC 0x0c06420a */
if(!s->budget--) { s->failed_pc=0x0c06420au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c064216; }
goto P_0c06420c;
P_0c06420c: /* original 5044, guest PC 0x0c06420c */
if(!s->budget--) { s->failed_pc=0x0c06420cu; return 0; }
r[0]=read(ram,r[4]+16,4);
goto P_0c06420e;
P_0c06420e: /* original 7001, guest PC 0x0c06420e */
if(!s->budget--) { s->failed_pc=0x0c06420eu; return 0; }
r[0]+=0x00000001u;
goto P_0c064210;
P_0c064210: /* original 1404, guest PC 0x0c064210 */
if(!s->budget--) { s->failed_pc=0x0c064210u; return 0; }
write(ram,r[4]+16,r[0],4);
goto P_0c064212;
P_0c064212: /* original bf41, guest PC 0x0c064212 */
if(!s->budget--) { s->failed_pc=0x0c064212u; return 0; }
target=0x0c064098u; r[16]=code_base|0x0c064216u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064216u) { target=s->pc; goto dispatch; }
goto P_0c064216;
P_0c064214: /* original e401, guest PC 0x0c064214 */
if(!s->budget--) { s->failed_pc=0x0c064214u; return 0; }
r[4]=0x00000001u;
goto P_0c064216;
P_0c064216: /* original 4f26, guest PC 0x0c064216 */
if(!s->budget--) { s->failed_pc=0x0c064216u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c064218;
P_0c064218: /* original 000b, guest PC 0x0c064218 */
if(!s->budget--) { s->failed_pc=0x0c064218u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c06421a: /* original e000, guest PC 0x0c06421a */
if(!s->budget--) { s->failed_pc=0x0c06421au; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c06421cu,s,ram);
P_0c066cd8: /* original 4f22, guest PC 0x0c066cd8 */
if(!s->budget--) { s->failed_pc=0x0c066cd8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c066cda;
P_0c066cda: /* original e501, guest PC 0x0c066cda */
if(!s->budget--) { s->failed_pc=0x0c066cdau; return 0; }
r[5]=0x00000001u;
goto P_0c066cdc;
P_0c066cdc: /* original d30d, guest PC 0x0c066cdc */
if(!s->budget--) { s->failed_pc=0x0c066cdcu; return 0; }
r[3]=read(ram,0x0c066d14u,4);
goto P_0c066cde;
P_0c066cde: /* original 430b, guest PC 0x0c066cde */
if(!s->budget--) { s->failed_pc=0x0c066cdeu; return 0; }
target=r[3];
r[16]=code_base|0x0c066ce2u;
r[4]=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c066ce2u) { target=s->pc; goto dispatch; }
goto P_0c066ce2;
P_0c066ce0: /* original e408, guest PC 0x0c066ce0 */
if(!s->budget--) { s->failed_pc=0x0c066ce0u; return 0; }
r[4]=0x00000008u;
goto P_0c066ce2;
P_0c066ce2: /* original e500, guest PC 0x0c066ce2 */
if(!s->budget--) { s->failed_pc=0x0c066ce2u; return 0; }
r[5]=0x00000000u;
goto P_0c066ce4;
P_0c066ce4: /* original d20b, guest PC 0x0c066ce4 */
if(!s->budget--) { s->failed_pc=0x0c066ce4u; return 0; }
r[2]=read(ram,0x0c066d14u,4);
goto P_0c066ce6;
P_0c066ce6: /* original e408, guest PC 0x0c066ce6 */
if(!s->budget--) { s->failed_pc=0x0c066ce6u; return 0; }
r[4]=0x00000008u;
goto P_0c066ce8;
P_0c066ce8: /* original 422b, guest PC 0x0c066ce8 */
if(!s->budget--) { s->failed_pc=0x0c066ce8u; return 0; }
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
P_0c066cea: /* original 4f26, guest PC 0x0c066cea */
if(!s->budget--) { s->failed_pc=0x0c066ceau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c066cecu,s,ram);
P_0c066d48: /* original 2fe6, guest PC 0x0c066d48 */
if(!s->budget--) { s->failed_pc=0x0c066d48u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
return vf3_matrix_family(0x0c066d4au,s,ram);
P_0c06c406: /* original 4f22, guest PC 0x0c06c406 */
if(!s->budget--) { s->failed_pc=0x0c06c406u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c408;
P_0c06c408: /* original 53f1, guest PC 0x0c06c408 */
if(!s->budget--) { s->failed_pc=0x0c06c408u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06c40a;
P_0c06c40a: /* original 2f36, guest PC 0x0c06c40a */
if(!s->budget--) { s->failed_pc=0x0c06c40au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c40c;
P_0c06c40c: /* original 2f76, guest PC 0x0c06c40c */
if(!s->budget--) { s->failed_pc=0x0c06c40cu; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c40e;
P_0c06c40e: /* original 2f66, guest PC 0x0c06c40e */
if(!s->budget--) { s->failed_pc=0x0c06c40eu; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c410;
P_0c06c410: /* original 2f56, guest PC 0x0c06c410 */
if(!s->budget--) { s->failed_pc=0x0c06c410u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c412;
P_0c06c412: /* original d31e, guest PC 0x0c06c412 */
if(!s->budget--) { s->failed_pc=0x0c06c412u; return 0; }
r[3]=read(ram,0x0c06c48cu,4);
goto P_0c06c414;
P_0c06c414: /* original d21e, guest PC 0x0c06c414 */
if(!s->budget--) { s->failed_pc=0x0c06c414u; return 0; }
r[2]=read(ram,0x0c06c490u,4);
goto P_0c06c416;
P_0c06c416: /* original 420b, guest PC 0x0c06c416 */
if(!s->budget--) { s->failed_pc=0x0c06c416u; return 0; }
target=r[2];
r[16]=code_base|0x0c06c41au;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06c41au) { target=s->pc; goto dispatch; }
goto P_0c06c41a;
P_0c06c418: /* original 2f36, guest PC 0x0c06c418 */
if(!s->budget--) { s->failed_pc=0x0c06c418u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c41a;
P_0c06c41a: /* original 7f14, guest PC 0x0c06c41a */
if(!s->budget--) { s->failed_pc=0x0c06c41au; return 0; }
r[15]+=0x00000014u;
goto P_0c06c41c;
P_0c06c41c: /* original 4f26, guest PC 0x0c06c41c */
if(!s->budget--) { s->failed_pc=0x0c06c41cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c41e;
P_0c06c41e: /* original 000b, guest PC 0x0c06c41e */
if(!s->budget--) { s->failed_pc=0x0c06c41eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06c420: /* original 0009, guest PC 0x0c06c420 */
if(!s->budget--) { s->failed_pc=0x0c06c420u; return 0; }
return vf3_matrix_family(0x0c06c422u,s,ram);
P_0c06dae8: /* original 4f22, guest PC 0x0c06dae8 */
if(!s->budget--) { s->failed_pc=0x0c06dae8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06daea;
P_0c06daea: /* original e307, guest PC 0x0c06daea */
if(!s->budget--) { s->failed_pc=0x0c06daeau; return 0; }
r[3]=0x00000007u;
goto P_0c06daec;
P_0c06daec: /* original 7ffc, guest PC 0x0c06daec */
if(!s->budget--) { s->failed_pc=0x0c06daecu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06daee;
P_0c06daee: /* original 2f51, guest PC 0x0c06daee */
if(!s->budget--) { s->failed_pc=0x0c06daeeu; return 0; }
write(ram,r[15],r[5],2);
goto P_0c06daf0;
P_0c06daf0: /* original 64e0, guest PC 0x0c06daf0 */
if(!s->budget--) { s->failed_pc=0x0c06daf0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[4]=tmp;
goto P_0c06daf2;
P_0c06daf2: /* original 84e1, guest PC 0x0c06daf2 */
if(!s->budget--) { s->failed_pc=0x0c06daf2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+1,1);
goto P_0c06daf4;
P_0c06daf4: /* original 55e1, guest PC 0x0c06daf4 */
if(!s->budget--) { s->failed_pc=0x0c06daf4u; return 0; }
r[5]=read(ram,r[14]+4,4);
goto P_0c06daf6;
P_0c06daf6: /* original 644c, guest PC 0x0c06daf6 */
if(!s->budget--) { s->failed_pc=0x0c06daf6u; return 0; }
r[4]=r[4]&255u;
goto P_0c06daf8;
P_0c06daf8: /* original 660c, guest PC 0x0c06daf8 */
if(!s->budget--) { s->failed_pc=0x0c06daf8u; return 0; }
r[6]=r[0]&255u;
goto P_0c06dafa;
P_0c06dafa: /* original 463d, guest PC 0x0c06dafa */
if(!s->budget--) { s->failed_pc=0x0c06dafau; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?r[6]>>((-r[3])&31u):0):r[6]<<(r[3]&31u);
goto P_0c06dafc;
P_0c06dafc: /* original 2f56, guest PC 0x0c06dafc */
if(!s->budget--) { s->failed_pc=0x0c06dafcu; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06dafe;
P_0c06dafe: /* original d233, guest PC 0x0c06dafe */
if(!s->budget--) { s->failed_pc=0x0c06dafeu; return 0; }
r[2]=read(ram,0x0c06dbccu,4);
goto P_0c06db00;
P_0c06db00: /* original 4400, guest PC 0x0c06db00 */
if(!s->budget--) { s->failed_pc=0x0c06db00u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06db02;
P_0c06db02: /* original d12f, guest PC 0x0c06db02 */
if(!s->budget--) { s->failed_pc=0x0c06db02u; return 0; }
r[1]=read(ram,0x0c06dbc0u,4);
goto P_0c06db04;
P_0c06db04: /* original 246b, guest PC 0x0c06db04 */
if(!s->budget--) { s->failed_pc=0x0c06db04u; return 0; }
r[4]|=r[6];
goto P_0c06db06;
P_0c06db06: /* original 410b, guest PC 0x0c06db06 */
if(!s->budget--) { s->failed_pc=0x0c06db06u; return 0; }
target=r[1];
r[16]=code_base|0x0c06db0au;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06db0au) { target=s->pc; goto dispatch; }
goto P_0c06db0a;
P_0c06db08: /* original 2f26, guest PC 0x0c06db08 */
if(!s->budget--) { s->failed_pc=0x0c06db08u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06db0a;
P_0c06db0a: /* original 7f08, guest PC 0x0c06db0a */
if(!s->budget--) { s->failed_pc=0x0c06db0au; return 0; }
r[15]+=0x00000008u;
goto P_0c06db0c;
P_0c06db0c: /* original 6403, guest PC 0x0c06db0c */
if(!s->budget--) { s->failed_pc=0x0c06db0cu; return 0; }
r[4]=r[0];
goto P_0c06db0e;
P_0c06db0e: /* original 63f1, guest PC 0x0c06db0e */
if(!s->budget--) { s->failed_pc=0x0c06db0eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c06db10;
P_0c06db10: /* original 2338, guest PC 0x0c06db10 */
if(!s->budget--) { s->failed_pc=0x0c06db10u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06db12;
P_0c06db12: /* original 8902, guest PC 0x0c06db12 */
if(!s->budget--) { s->failed_pc=0x0c06db12u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06db1a; }
goto P_0c06db14;
P_0c06db14: /* original d12e, guest PC 0x0c06db14 */
if(!s->budget--) { s->failed_pc=0x0c06db14u; return 0; }
r[1]=read(ram,0x0c06dbd0u,4);
goto P_0c06db16;
P_0c06db16: /* original a002, guest PC 0x0c06db16 */
if(!s->budget--) { s->failed_pc=0x0c06db16u; return 0; }
tmp=read(ram,r[1],4);
r[6]=tmp;
goto P_0c06db1e;
P_0c06db18: /* original 6612, guest PC 0x0c06db18 */
if(!s->budget--) { s->failed_pc=0x0c06db18u; return 0; }
tmp=read(ram,r[1],4);
r[6]=tmp;
goto P_0c06db1a;
P_0c06db1a: /* original d22e, guest PC 0x0c06db1a */
if(!s->budget--) { s->failed_pc=0x0c06db1au; return 0; }
r[2]=read(ram,0x0c06dbd4u,4);
goto P_0c06db1c;
P_0c06db1c: /* original 6622, guest PC 0x0c06db1c */
if(!s->budget--) { s->failed_pc=0x0c06db1cu; return 0; }
tmp=read(ram,r[2],4);
r[6]=tmp;
goto P_0c06db1e;
P_0c06db1e: /* original 2f66, guest PC 0x0c06db1e */
if(!s->budget--) { s->failed_pc=0x0c06db1eu; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06db20;
P_0c06db20: /* original e300, guest PC 0x0c06db20 */
if(!s->budget--) { s->failed_pc=0x0c06db20u; return 0; }
r[3]=0x00000000u;
goto P_0c06db22;
P_0c06db22: /* original 2f36, guest PC 0x0c06db22 */
if(!s->budget--) { s->failed_pc=0x0c06db22u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06db24;
P_0c06db24: /* original d126, guest PC 0x0c06db24 */
if(!s->budget--) { s->failed_pc=0x0c06db24u; return 0; }
r[1]=read(ram,0x0c06dbc0u,4);
goto P_0c06db26;
P_0c06db26: /* original d22c, guest PC 0x0c06db26 */
if(!s->budget--) { s->failed_pc=0x0c06db26u; return 0; }
r[2]=read(ram,0x0c06dbd8u,4);
goto P_0c06db28;
P_0c06db28: /* original 410b, guest PC 0x0c06db28 */
if(!s->budget--) { s->failed_pc=0x0c06db28u; return 0; }
target=r[1];
r[16]=code_base|0x0c06db2cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06db2cu) { target=s->pc; goto dispatch; }
goto P_0c06db2c;
P_0c06db2a: /* original 2f26, guest PC 0x0c06db2a */
if(!s->budget--) { s->failed_pc=0x0c06db2au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06db2c;
P_0c06db2c: /* original 7f10, guest PC 0x0c06db2c */
if(!s->budget--) { s->failed_pc=0x0c06db2cu; return 0; }
r[15]+=0x00000010u;
goto P_0c06db2e;
P_0c06db2e: /* original 4f26, guest PC 0x0c06db2e */
if(!s->budget--) { s->failed_pc=0x0c06db2eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06db30;
P_0c06db30: /* original 000b, guest PC 0x0c06db30 */
if(!s->budget--) { s->failed_pc=0x0c06db30u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06db32: /* original 6ef6, guest PC 0x0c06db32 */
if(!s->budget--) { s->failed_pc=0x0c06db32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06db34u,s,ram);
P_0c07023a: /* original f40b, guest PC 0x0c07023a */
if(!s->budget--) { s->failed_pc=0x0c07023au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07023c;
P_0c07023c: /* original 02ec, guest PC 0x0c07023c */
if(!s->budget--) { s->failed_pc=0x0c07023cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07023e;
P_0c07023e: /* original 0c07, guest PC 0x0c07023e */
if(!s->budget--) { s->failed_pc=0x0c07023eu; return 0; }
r[19]=r[12]*r[0];
goto P_0c070240;
P_0c070240: /* original f059, guest PC 0x0c070240 */
if(!s->budget--) { s->failed_pc=0x0c070240u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070242;
P_0c070242: /* original f159, guest PC 0x0c070242 */
if(!s->budget--) { s->failed_pc=0x0c070242u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070244;
P_0c070244: /* original f259, guest PC 0x0c070244 */
if(!s->budget--) { s->failed_pc=0x0c070244u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070246;
P_0c070246: /* original 740c, guest PC 0x0c070246 */
if(!s->budget--) { s->failed_pc=0x0c070246u; return 0; }
r[4]+=0x0000000cu;
goto P_0c070248;
P_0c070248: /* original f242, guest PC 0x0c070248 */
if(!s->budget--) { s->failed_pc=0x0c070248u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c07024a;
P_0c07024a: /* original f142, guest PC 0x0c07024a */
if(!s->budget--) { s->failed_pc=0x0c07024au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c07024c;
P_0c07024c: /* original f042, guest PC 0x0c07024c */
if(!s->budget--) { s->failed_pc=0x0c07024cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c07024e;
P_0c07024e: /* original f42b, guest PC 0x0c07024e */
if(!s->budget--) { s->failed_pc=0x0c07024eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070250;
P_0c070250: /* original f41b, guest PC 0x0c070250 */
if(!s->budget--) { s->failed_pc=0x0c070250u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070252;
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
P_0c070fba: /* original f40b, guest PC 0x0c070fba */
if(!s->budget--) { s->failed_pc=0x0c070fbau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070fbc;
P_0c070fbc: /* original 104c, guest PC 0x0c070fbc */
if(!s->budget--) { s->failed_pc=0x0c070fbcu; return 0; }
write(ram,r[0]+48,r[4],4);
goto P_0c070fbe;
P_0c070fbe: /* original 0c07, guest PC 0x0c070fbe */
if(!s->budget--) { s->failed_pc=0x0c070fbeu; return 0; }
r[19]=r[12]*r[0];
goto P_0c070fc0;
P_0c070fc0: /* original 1070, guest PC 0x0c070fc0 */
if(!s->budget--) { s->failed_pc=0x0c070fc0u; return 0; }
write(ram,r[0]+0,r[7],4);
goto P_0c070fc2;
P_0c070fc2: /* original 0c07, guest PC 0x0c070fc2 */
if(!s->budget--) { s->failed_pc=0x0c070fc2u; return 0; }
r[19]=r[12]*r[0];
goto P_0c070fc4;
P_0c070fc4: /* original f059, guest PC 0x0c070fc4 */
if(!s->budget--) { s->failed_pc=0x0c070fc4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070fc6;
P_0c070fc6: /* original f159, guest PC 0x0c070fc6 */
if(!s->budget--) { s->failed_pc=0x0c070fc6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070fc8;
P_0c070fc8: /* original f259, guest PC 0x0c070fc8 */
if(!s->budget--) { s->failed_pc=0x0c070fc8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070fca;
P_0c070fca: /* original 740c, guest PC 0x0c070fca */
if(!s->budget--) { s->failed_pc=0x0c070fcau; return 0; }
r[4]+=0x0000000cu;
goto P_0c070fcc;
P_0c070fcc: /* original f242, guest PC 0x0c070fcc */
if(!s->budget--) { s->failed_pc=0x0c070fccu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c070fce;
P_0c070fce: /* original f142, guest PC 0x0c070fce */
if(!s->budget--) { s->failed_pc=0x0c070fceu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c070fd0;
P_0c070fd0: /* original f042, guest PC 0x0c070fd0 */
if(!s->budget--) { s->failed_pc=0x0c070fd0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c070fd2;
P_0c070fd2: /* original f42b, guest PC 0x0c070fd2 */
if(!s->budget--) { s->failed_pc=0x0c070fd2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070fd4;
P_0c070fd4: /* original f41b, guest PC 0x0c070fd4 */
if(!s->budget--) { s->failed_pc=0x0c070fd4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070fd6;
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
P_0c073098: /* original 4f22, guest PC 0x0c073098 */
if(!s->budget--) { s->failed_pc=0x0c073098u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07309a;
P_0c07309a: /* original 7ff8, guest PC 0x0c07309a */
if(!s->budget--) { s->failed_pc=0x0c07309au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07309c;
P_0c07309c: /* original 2f52, guest PC 0x0c07309c */
if(!s->budget--) { s->failed_pc=0x0c07309cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c07309e;
P_0c07309e: /* original d33f, guest PC 0x0c07309e */
if(!s->budget--) { s->failed_pc=0x0c07309eu; return 0; }
r[3]=read(ram,0x0c07319cu,4);
goto P_0c0730a0;
P_0c0730a0: /* original 430b, guest PC 0x0c0730a0 */
if(!s->budget--) { s->failed_pc=0x0c0730a0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0730a4u;
r[4]+=0x00000017u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0730a4u) { target=s->pc; goto dispatch; }
goto P_0c0730a4;
P_0c0730a2: /* original 7417, guest PC 0x0c0730a2 */
if(!s->budget--) { s->failed_pc=0x0c0730a2u; return 0; }
r[4]+=0x00000017u;
goto P_0c0730a4;
P_0c0730a4: /* original e201, guest PC 0x0c0730a4 */
if(!s->budget--) { s->failed_pc=0x0c0730a4u; return 0; }
r[2]=0x00000001u;
goto P_0c0730a6;
P_0c0730a6: /* original e700, guest PC 0x0c0730a6 */
if(!s->budget--) { s->failed_pc=0x0c0730a6u; return 0; }
r[7]=0x00000000u;
goto P_0c0730a8;
P_0c0730a8: /* original 6623, guest PC 0x0c0730a8 */
if(!s->budget--) { s->failed_pc=0x0c0730a8u; return 0; }
r[6]=r[2];
goto P_0c0730aa;
P_0c0730aa: /* original 640c, guest PC 0x0c0730aa */
if(!s->budget--) { s->failed_pc=0x0c0730aau; return 0; }
r[4]=r[0]&255u;
goto P_0c0730ac;
P_0c0730ac: /* original 2f26, guest PC 0x0c0730ac */
if(!s->budget--) { s->failed_pc=0x0c0730acu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0730ae;
P_0c0730ae: /* original bf08, guest PC 0x0c0730ae */
if(!s->budget--) { s->failed_pc=0x0c0730aeu; return 0; }
target=0x0c072ec2u; r[16]=code_base|0x0c0730b2u;
r[5]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0730b2u) { target=s->pc; goto dispatch; }
goto P_0c0730b2;
P_0c0730b0: /* original 55f1, guest PC 0x0c0730b0 */
if(!s->budget--) { s->failed_pc=0x0c0730b0u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0730b2;
P_0c0730b2: /* original 7f04, guest PC 0x0c0730b2 */
if(!s->budget--) { s->failed_pc=0x0c0730b2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0730b4;
P_0c0730b4: /* original 64e3, guest PC 0x0c0730b4 */
if(!s->budget--) { s->failed_pc=0x0c0730b4u; return 0; }
r[4]=r[14];
goto P_0c0730b6;
P_0c0730b6: /* original 1f01, guest PC 0x0c0730b6 */
if(!s->budget--) { s->failed_pc=0x0c0730b6u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0730b8;
P_0c0730b8: /* original 6503, guest PC 0x0c0730b8 */
if(!s->budget--) { s->failed_pc=0x0c0730b8u; return 0; }
r[5]=r[0];
goto P_0c0730ba;
P_0c0730ba: /* original d339, guest PC 0x0c0730ba */
if(!s->budget--) { s->failed_pc=0x0c0730bau; return 0; }
r[3]=read(ram,0x0c0731a0u,4);
goto P_0c0730bc;
P_0c0730bc: /* original 430b, guest PC 0x0c0730bc */
if(!s->budget--) { s->failed_pc=0x0c0730bcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0730c0u;
r[4]+=0x00000017u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0730c0u) { target=s->pc; goto dispatch; }
goto P_0c0730c0;
P_0c0730be: /* original 7417, guest PC 0x0c0730be */
if(!s->budget--) { s->failed_pc=0x0c0730beu; return 0; }
r[4]+=0x00000017u;
goto P_0c0730c0;
P_0c0730c0: /* original d236, guest PC 0x0c0730c0 */
if(!s->budget--) { s->failed_pc=0x0c0730c0u; return 0; }
r[2]=read(ram,0x0c07319cu,4);
goto P_0c0730c2;
P_0c0730c2: /* original 64e3, guest PC 0x0c0730c2 */
if(!s->budget--) { s->failed_pc=0x0c0730c2u; return 0; }
r[4]=r[14];
goto P_0c0730c4;
P_0c0730c4: /* original 420b, guest PC 0x0c0730c4 */
if(!s->budget--) { s->failed_pc=0x0c0730c4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0730c8u;
r[4]+=0x00000017u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0730c8u) { target=s->pc; goto dispatch; }
goto P_0c0730c8;
P_0c0730c6: /* original 7417, guest PC 0x0c0730c6 */
if(!s->budget--) { s->failed_pc=0x0c0730c6u; return 0; }
r[4]+=0x00000017u;
goto P_0c0730c8;
P_0c0730c8: /* original 6d0c, guest PC 0x0c0730c8 */
if(!s->budget--) { s->failed_pc=0x0c0730c8u; return 0; }
r[13]=r[0]&255u;
goto P_0c0730ca;
P_0c0730ca: /* original 2dd8, guest PC 0x0c0730ca */
if(!s->budget--) { s->failed_pc=0x0c0730cau; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0730cc;
P_0c0730cc: /* original 8907, guest PC 0x0c0730cc */
if(!s->budget--) { s->failed_pc=0x0c0730ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0730de; }
goto P_0c0730ce;
P_0c0730ce: /* original d236, guest PC 0x0c0730ce */
if(!s->budget--) { s->failed_pc=0x0c0730ceu; return 0; }
r[2]=read(ram,0x0c0731a8u,4);
goto P_0c0730d0;
P_0c0730d0: /* original d434, guest PC 0x0c0730d0 */
if(!s->budget--) { s->failed_pc=0x0c0730d0u; return 0; }
r[4]=read(ram,0x0c0731a4u,4);
goto P_0c0730d2;
P_0c0730d2: /* original 420b, guest PC 0x0c0730d2 */
if(!s->budget--) { s->failed_pc=0x0c0730d2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0730d6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0730d6u) { target=s->pc; goto dispatch; }
goto P_0c0730d6;
P_0c0730d4: /* original 0009, guest PC 0x0c0730d4 */
if(!s->budget--) { s->failed_pc=0x0c0730d4u; return 0; }
goto P_0c0730d6;
P_0c0730d6: /* original 65f2, guest PC 0x0c0730d6 */
if(!s->budget--) { s->failed_pc=0x0c0730d6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0730d8;
P_0c0730d8: /* original 66d3, guest PC 0x0c0730d8 */
if(!s->budget--) { s->failed_pc=0x0c0730d8u; return 0; }
r[6]=r[13];
goto P_0c0730da;
P_0c0730da: /* original b0f5, guest PC 0x0c0730da */
if(!s->budget--) { s->failed_pc=0x0c0730dau; return 0; }
target=0x0c0732c8u; r[16]=code_base|0x0c0730deu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0730deu) { target=s->pc; goto dispatch; }
goto P_0c0730de;
P_0c0730dc: /* original 64e3, guest PC 0x0c0730dc */
if(!s->budget--) { s->failed_pc=0x0c0730dcu; return 0; }
r[4]=r[14];
goto P_0c0730de;
P_0c0730de: /* original 7f08, guest PC 0x0c0730de */
if(!s->budget--) { s->failed_pc=0x0c0730deu; return 0; }
r[15]+=0x00000008u;
goto P_0c0730e0;
P_0c0730e0: /* original d231, guest PC 0x0c0730e0 */
if(!s->budget--) { s->failed_pc=0x0c0730e0u; return 0; }
r[2]=read(ram,0x0c0731a8u,4);
goto P_0c0730e2;
P_0c0730e2: /* original 4f26, guest PC 0x0c0730e2 */
if(!s->budget--) { s->failed_pc=0x0c0730e2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0730e4;
P_0c0730e4: /* original d431, guest PC 0x0c0730e4 */
if(!s->budget--) { s->failed_pc=0x0c0730e4u; return 0; }
r[4]=read(ram,0x0c0731acu,4);
goto P_0c0730e6;
P_0c0730e6: /* original 6df6, guest PC 0x0c0730e6 */
if(!s->budget--) { s->failed_pc=0x0c0730e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0730e8;
P_0c0730e8: /* original 422b, guest PC 0x0c0730e8 */
if(!s->budget--) { s->failed_pc=0x0c0730e8u; return 0; }
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
P_0c0730ea: /* original 6ef6, guest PC 0x0c0730ea */
if(!s->budget--) { s->failed_pc=0x0c0730eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0730ecu,s,ram);
P_0c0734fe: /* original 4f22, guest PC 0x0c0734fe */
if(!s->budget--) { s->failed_pc=0x0c0734feu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c073500;
P_0c073500: /* original 66b8, guest PC 0x0c073500 */
if(!s->budget--) { s->failed_pc=0x0c073500u; return 0; }
r[6]=(r[11]&0xffff0000u)|((r[11]&255u)<<8)|((r[11]>>8)&255u);
goto P_0c073502;
P_0c073502: /* original 0c0c, guest PC 0x0c073502 */
if(!s->budget--) { s->failed_pc=0x0c073502u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c073504;
P_0c073504: /* original 11f4, guest PC 0x0c073504 */
if(!s->budget--) { s->failed_pc=0x0c073504u; return 0; }
write(ram,r[1]+16,r[15],4);
goto P_0c073506;
P_0c073506: /* original 0c0c, guest PC 0x0c073506 */
if(!s->budget--) { s->failed_pc=0x0c073506u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[0]+r[0],1);
goto P_0c073508;
P_0c073508: /* original 3252, guest PC 0x0c073508 */
if(!s->budget--) { s->failed_pc=0x0c073508u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[5])!=0);
goto P_0c07350a;
P_0c07350a: /* original 0c0f, guest PC 0x0c07350a */
if(!s->budget--) { s->failed_pc=0x0c07350au; return 0; }
s->failed_pc=0x0c07350au; return 0;
goto P_0c07350c;
P_0c07350c: /* original 3368, guest PC 0x0c07350c */
if(!s->budget--) { s->failed_pc=0x0c07350cu; return 0; }
r[3]-=r[6];
goto P_0c07350e;
P_0c07350e: /* original 0c0f, guest PC 0x0c07350e */
if(!s->budget--) { s->failed_pc=0x0c07350eu; return 0; }
s->failed_pc=0x0c07350eu; return 0;
goto P_0c073510;
P_0c073510: /* original 33bc, guest PC 0x0c073510 */
if(!s->budget--) { s->failed_pc=0x0c073510u; return 0; }
r[3]+=r[11];
goto P_0c073512;
P_0c073512: /* original 0c0f, guest PC 0x0c073512 */
if(!s->budget--) { s->failed_pc=0x0c073512u; return 0; }
s->failed_pc=0x0c073512u; return 0;
goto P_0c073514;
P_0c073514: /* original 4f22, guest PC 0x0c073514 */
if(!s->budget--) { s->failed_pc=0x0c073514u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c073516;
P_0c073516: /* original 7ffc, guest PC 0x0c073516 */
if(!s->budget--) { s->failed_pc=0x0c073516u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c073518;
P_0c073518: /* original 2f42, guest PC 0x0c073518 */
if(!s->budget--) { s->failed_pc=0x0c073518u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07351a;
P_0c07351a: /* original d33a, guest PC 0x0c07351a */
if(!s->budget--) { s->failed_pc=0x0c07351au; return 0; }
r[3]=read(ram,0x0c073604u,4);
goto P_0c07351c;
P_0c07351c: /* original d438, guest PC 0x0c07351c */
if(!s->budget--) { s->failed_pc=0x0c07351cu; return 0; }
r[4]=read(ram,0x0c073600u,4);
goto P_0c07351e;
P_0c07351e: /* original 430b, guest PC 0x0c07351e */
if(!s->budget--) { s->failed_pc=0x0c07351eu; return 0; }
target=r[3];
r[16]=code_base|0x0c073522u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073522u) { target=s->pc; goto dispatch; }
goto P_0c073522;
P_0c073520: /* original 0009, guest PC 0x0c073520 */
if(!s->budget--) { s->failed_pc=0x0c073520u; return 0; }
goto P_0c073522;
P_0c073522: /* original d339, guest PC 0x0c073522 */
if(!s->budget--) { s->failed_pc=0x0c073522u; return 0; }
r[3]=read(ram,0x0c073608u,4);
goto P_0c073524;
P_0c073524: /* original 64f2, guest PC 0x0c073524 */
if(!s->budget--) { s->failed_pc=0x0c073524u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c073526;
P_0c073526: /* original 430b, guest PC 0x0c073526 */
if(!s->budget--) { s->failed_pc=0x0c073526u; return 0; }
target=r[3];
r[16]=code_base|0x0c07352au;
r[4]+=0x00000017u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07352au) { target=s->pc; goto dispatch; }
goto P_0c07352a;
P_0c073528: /* original 7417, guest PC 0x0c073528 */
if(!s->budget--) { s->failed_pc=0x0c073528u; return 0; }
r[4]+=0x00000017u;
goto P_0c07352a;
P_0c07352a: /* original 640c, guest PC 0x0c07352a */
if(!s->budget--) { s->failed_pc=0x0c07352au; return 0; }
r[4]=r[0]&255u;
goto P_0c07352c;
P_0c07352c: /* original 6043, guest PC 0x0c07352c */
if(!s->budget--) { s->failed_pc=0x0c07352cu; return 0; }
r[0]=r[4];
goto P_0c07352e;
P_0c07352e: /* original 8801, guest PC 0x0c07352e */
if(!s->budget--) { s->failed_pc=0x0c07352eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c073530;
P_0c073530: /* original 8903, guest PC 0x0c073530 */
if(!s->budget--) { s->failed_pc=0x0c073530u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07353a; }
goto P_0c073532;
P_0c073532: /* original d234, guest PC 0x0c073532 */
if(!s->budget--) { s->failed_pc=0x0c073532u; return 0; }
r[2]=read(ram,0x0c073604u,4);
goto P_0c073534;
P_0c073534: /* original d435, guest PC 0x0c073534 */
if(!s->budget--) { s->failed_pc=0x0c073534u; return 0; }
r[4]=read(ram,0x0c07360cu,4);
goto P_0c073536;
P_0c073536: /* original 420b, guest PC 0x0c073536 */
if(!s->budget--) { s->failed_pc=0x0c073536u; return 0; }
target=r[2];
r[16]=code_base|0x0c07353au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07353au) { target=s->pc; goto dispatch; }
goto P_0c07353a;
P_0c073538: /* original 0009, guest PC 0x0c073538 */
if(!s->budget--) { s->failed_pc=0x0c073538u; return 0; }
goto P_0c07353a;
P_0c07353a: /* original 7f04, guest PC 0x0c07353a */
if(!s->budget--) { s->failed_pc=0x0c07353au; return 0; }
r[15]+=0x00000004u;
goto P_0c07353c;
P_0c07353c: /* original 4f26, guest PC 0x0c07353c */
if(!s->budget--) { s->failed_pc=0x0c07353cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07353e;
P_0c07353e: /* original 000b, guest PC 0x0c07353e */
if(!s->budget--) { s->failed_pc=0x0c07353eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c073540: /* original 0009, guest PC 0x0c073540 */
if(!s->budget--) { s->failed_pc=0x0c073540u; return 0; }
return vf3_matrix_family(0x0c073542u,s,ram);
P_0c07ba28: /* original 2fe6, guest PC 0x0c07ba28 */
if(!s->budget--) { s->failed_pc=0x0c07ba28u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba2a;
P_0c07ba2a: /* original 2fd6, guest PC 0x0c07ba2a */
if(!s->budget--) { s->failed_pc=0x0c07ba2au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba2c;
P_0c07ba2c: /* original 2fc6, guest PC 0x0c07ba2c */
if(!s->budget--) { s->failed_pc=0x0c07ba2cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba2e;
P_0c07ba2e: /* original 2fb6, guest PC 0x0c07ba2e */
if(!s->budget--) { s->failed_pc=0x0c07ba2eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba30;
P_0c07ba30: /* original 2fa6, guest PC 0x0c07ba30 */
if(!s->budget--) { s->failed_pc=0x0c07ba30u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba32;
P_0c07ba32: /* original 2f96, guest PC 0x0c07ba32 */
if(!s->budget--) { s->failed_pc=0x0c07ba32u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba34;
P_0c07ba34: /* original 2f86, guest PC 0x0c07ba34 */
if(!s->budget--) { s->failed_pc=0x0c07ba34u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba36;
P_0c07ba36: /* original fffb, guest PC 0x0c07ba36 */
if(!s->budget--) { s->failed_pc=0x0c07ba36u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c07ba38;
P_0c07ba38: /* original ffeb, guest PC 0x0c07ba38 */
if(!s->budget--) { s->failed_pc=0x0c07ba38u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c07ba3a;
P_0c07ba3a: /* original 4f22, guest PC 0x0c07ba3a */
if(!s->budget--) { s->failed_pc=0x0c07ba3au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ba3c;
P_0c07ba3c: /* original d24b, guest PC 0x0c07ba3c */
if(!s->budget--) { s->failed_pc=0x0c07ba3cu; return 0; }
r[2]=read(ram,0x0c07bb6cu,4);
goto P_0c07ba3e;
P_0c07ba3e: /* original 9083, guest PC 0x0c07ba3e */
if(!s->budget--) { s->failed_pc=0x0c07ba3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb48u,2);
goto P_0c07ba40;
P_0c07ba40: /* original 4f12, guest PC 0x0c07ba40 */
if(!s->budget--) { s->failed_pc=0x0c07ba40u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c07ba42;
P_0c07ba42: /* original 6322, guest PC 0x0c07ba42 */
if(!s->budget--) { s->failed_pc=0x0c07ba42u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c07ba44;
P_0c07ba44: /* original dd48, guest PC 0x0c07ba44 */
if(!s->budget--) { s->failed_pc=0x0c07ba44u; return 0; }
r[13]=read(ram,0x0c07bb68u,4);
goto P_0c07ba46;
P_0c07ba46: /* original 3f0c, guest PC 0x0c07ba46 */
if(!s->budget--) { s->failed_pc=0x0c07ba46u; return 0; }
r[15]+=r[0];
goto P_0c07ba48;
P_0c07ba48: /* original 1f3d, guest PC 0x0c07ba48 */
if(!s->budget--) { s->failed_pc=0x0c07ba48u; return 0; }
write(ram,r[15]+52,r[3],4);
goto P_0c07ba4a;
P_0c07ba4a: /* original d349, guest PC 0x0c07ba4a */
if(!s->budget--) { s->failed_pc=0x0c07ba4au; return 0; }
r[3]=read(ram,0x0c07bb70u,4);
goto P_0c07ba4c;
P_0c07ba4c: /* original 6132, guest PC 0x0c07ba4c */
if(!s->budget--) { s->failed_pc=0x0c07ba4cu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c07ba4e;
P_0c07ba4e: /* original 1f1c, guest PC 0x0c07ba4e */
if(!s->budget--) { s->failed_pc=0x0c07ba4eu; return 0; }
write(ram,r[15]+48,r[1],4);
goto P_0c07ba50;
P_0c07ba50: /* original 50d2, guest PC 0x0c07ba50 */
if(!s->budget--) { s->failed_pc=0x0c07ba50u; return 0; }
r[0]=read(ram,r[13]+8,4);
goto P_0c07ba52;
P_0c07ba52: /* original d148, guest PC 0x0c07ba52 */
if(!s->budget--) { s->failed_pc=0x0c07ba52u; return 0; }
r[1]=read(ram,0x0c07bb74u,4);
goto P_0c07ba54;
P_0c07ba54: /* original 2018, guest PC 0x0c07ba54 */
if(!s->budget--) { s->failed_pc=0x0c07ba54u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c07ba56;
P_0c07ba56: /* original 8f1a, guest PC 0x0c07ba56 */
if(!s->budget--) { s->failed_pc=0x0c07ba56u; return 0; }
cond=r[17]&1u;
r[11]=0x00000020u;
if(!cond) { goto P_0c07ba8e; }
goto P_0c07ba5a;
P_0c07ba58: /* original eb20, guest PC 0x0c07ba58 */
if(!s->budget--) { s->failed_pc=0x0c07ba58u; return 0; }
r[11]=0x00000020u;
goto P_0c07ba5a;
P_0c07ba5a: /* original 53fd, guest PC 0x0c07ba5a */
if(!s->budget--) { s->failed_pc=0x0c07ba5au; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c07ba5c;
P_0c07ba5c: /* original 23b8, guest PC 0x0c07ba5c */
if(!s->budget--) { s->failed_pc=0x0c07ba5cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c07ba5e;
P_0c07ba5e: /* original 8902, guest PC 0x0c07ba5e */
if(!s->budget--) { s->failed_pc=0x0c07ba5eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ba66; }
goto P_0c07ba60;
P_0c07ba60: /* original d145, guest PC 0x0c07ba60 */
if(!s->budget--) { s->failed_pc=0x0c07ba60u; return 0; }
r[1]=read(ram,0x0c07bb78u,4);
goto P_0c07ba62;
P_0c07ba62: /* original 410b, guest PC 0x0c07ba62 */
if(!s->budget--) { s->failed_pc=0x0c07ba62u; return 0; }
target=r[1];
r[16]=code_base|0x0c07ba66u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ba66u) { target=s->pc; goto dispatch; }
goto P_0c07ba66;
P_0c07ba64: /* original 0009, guest PC 0x0c07ba64 */
if(!s->budget--) { s->failed_pc=0x0c07ba64u; return 0; }
goto P_0c07ba66;
P_0c07ba66: /* original 50fd, guest PC 0x0c07ba66 */
if(!s->budget--) { s->failed_pc=0x0c07ba66u; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c07ba68;
P_0c07ba68: /* original c880, guest PC 0x0c07ba68 */
if(!s->budget--) { s->failed_pc=0x0c07ba68u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c07ba6a;
P_0c07ba6a: /* original 8902, guest PC 0x0c07ba6a */
if(!s->budget--) { s->failed_pc=0x0c07ba6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ba72; }
goto P_0c07ba6c;
P_0c07ba6c: /* original d243, guest PC 0x0c07ba6c */
if(!s->budget--) { s->failed_pc=0x0c07ba6cu; return 0; }
r[2]=read(ram,0x0c07bb7cu,4);
goto P_0c07ba6e;
P_0c07ba6e: /* original 420b, guest PC 0x0c07ba6e */
if(!s->budget--) { s->failed_pc=0x0c07ba6eu; return 0; }
target=r[2];
r[16]=code_base|0x0c07ba72u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ba72u) { target=s->pc; goto dispatch; }
goto P_0c07ba72;
P_0c07ba70: /* original 0009, guest PC 0x0c07ba70 */
if(!s->budget--) { s->failed_pc=0x0c07ba70u; return 0; }
goto P_0c07ba72;
P_0c07ba72: /* original 52fd, guest PC 0x0c07ba72 */
if(!s->budget--) { s->failed_pc=0x0c07ba72u; return 0; }
r[2]=read(ram,r[15]+52,4);
goto P_0c07ba74;
P_0c07ba74: /* original 9369, guest PC 0x0c07ba74 */
if(!s->budget--) { s->failed_pc=0x0c07ba74u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb4au,2);
goto P_0c07ba76;
P_0c07ba76: /* original 2238, guest PC 0x0c07ba76 */
if(!s->budget--) { s->failed_pc=0x0c07ba76u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07ba78;
P_0c07ba78: /* original 8902, guest PC 0x0c07ba78 */
if(!s->budget--) { s->failed_pc=0x0c07ba78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ba80; }
goto P_0c07ba7a;
P_0c07ba7a: /* original d241, guest PC 0x0c07ba7a */
if(!s->budget--) { s->failed_pc=0x0c07ba7au; return 0; }
r[2]=read(ram,0x0c07bb80u,4);
goto P_0c07ba7c;
P_0c07ba7c: /* original 420b, guest PC 0x0c07ba7c */
if(!s->budget--) { s->failed_pc=0x0c07ba7cu; return 0; }
target=r[2];
r[16]=code_base|0x0c07ba80u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ba80u) { target=s->pc; goto dispatch; }
goto P_0c07ba80;
P_0c07ba7e: /* original 0009, guest PC 0x0c07ba7e */
if(!s->budget--) { s->failed_pc=0x0c07ba7eu; return 0; }
goto P_0c07ba80;
P_0c07ba80: /* original 51fd, guest PC 0x0c07ba80 */
if(!s->budget--) { s->failed_pc=0x0c07ba80u; return 0; }
r[1]=read(ram,r[15]+52,4);
goto P_0c07ba82;
P_0c07ba82: /* original 9363, guest PC 0x0c07ba82 */
if(!s->budget--) { s->failed_pc=0x0c07ba82u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb4cu,2);
goto P_0c07ba84;
P_0c07ba84: /* original 2138, guest PC 0x0c07ba84 */
if(!s->budget--) { s->failed_pc=0x0c07ba84u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c07ba86;
P_0c07ba86: /* original 8902, guest PC 0x0c07ba86 */
if(!s->budget--) { s->failed_pc=0x0c07ba86u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ba8e; }
goto P_0c07ba88;
P_0c07ba88: /* original d23e, guest PC 0x0c07ba88 */
if(!s->budget--) { s->failed_pc=0x0c07ba88u; return 0; }
r[2]=read(ram,0x0c07bb84u,4);
goto P_0c07ba8a;
P_0c07ba8a: /* original 420b, guest PC 0x0c07ba8a */
if(!s->budget--) { s->failed_pc=0x0c07ba8au; return 0; }
target=r[2];
r[16]=code_base|0x0c07ba8eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ba8eu) { target=s->pc; goto dispatch; }
goto P_0c07ba8e;
P_0c07ba8c: /* original 0009, guest PC 0x0c07ba8c */
if(!s->budget--) { s->failed_pc=0x0c07ba8cu; return 0; }
goto P_0c07ba8e;
P_0c07ba8e: /* original 50fd, guest PC 0x0c07ba8e */
if(!s->budget--) { s->failed_pc=0x0c07ba8eu; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c07ba90;
P_0c07ba90: /* original c801, guest PC 0x0c07ba90 */
if(!s->budget--) { s->failed_pc=0x0c07ba90u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c07ba92;
P_0c07ba92: /* original 8905, guest PC 0x0c07ba92 */
if(!s->budget--) { s->failed_pc=0x0c07ba92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07baa0; }
goto P_0c07ba94;
P_0c07ba94: /* original d13c, guest PC 0x0c07ba94 */
if(!s->budget--) { s->failed_pc=0x0c07ba94u; return 0; }
r[1]=read(ram,0x0c07bb88u,4);
goto P_0c07ba96;
P_0c07ba96: /* original 410b, guest PC 0x0c07ba96 */
if(!s->budget--) { s->failed_pc=0x0c07ba96u; return 0; }
target=r[1];
r[16]=code_base|0x0c07ba9au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ba9au) { target=s->pc; goto dispatch; }
goto P_0c07ba9a;
P_0c07ba98: /* original 0009, guest PC 0x0c07ba98 */
if(!s->budget--) { s->failed_pc=0x0c07ba98u; return 0; }
goto P_0c07ba9a;
P_0c07ba9a: /* original 53fc, guest PC 0x0c07ba9a */
if(!s->budget--) { s->failed_pc=0x0c07ba9au; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c07ba9c;
P_0c07ba9c: /* original 230b, guest PC 0x0c07ba9c */
if(!s->budget--) { s->failed_pc=0x0c07ba9cu; return 0; }
r[3]|=r[0];
goto P_0c07ba9e;
P_0c07ba9e: /* original 1f3c, guest PC 0x0c07ba9e */
if(!s->budget--) { s->failed_pc=0x0c07ba9eu; return 0; }
write(ram,r[15]+48,r[3],4);
goto P_0c07baa0;
P_0c07baa0: /* original 53fd, guest PC 0x0c07baa0 */
if(!s->budget--) { s->failed_pc=0x0c07baa0u; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c07baa2;
P_0c07baa2: /* original ee00, guest PC 0x0c07baa2 */
if(!s->budget--) { s->failed_pc=0x0c07baa2u; return 0; }
r[14]=0x00000000u;
goto P_0c07baa4;
P_0c07baa4: /* original 9453, guest PC 0x0c07baa4 */
if(!s->budget--) { s->failed_pc=0x0c07baa4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb4eu,2);
goto P_0c07baa6;
P_0c07baa6: /* original 52fc, guest PC 0x0c07baa6 */
if(!s->budget--) { s->failed_pc=0x0c07baa6u; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c07baa8;
P_0c07baa8: /* original 2439, guest PC 0x0c07baa8 */
if(!s->budget--) { s->failed_pc=0x0c07baa8u; return 0; }
r[4]&=r[3];
goto P_0c07baaa;
P_0c07baaa: /* original 242b, guest PC 0x0c07baaa */
if(!s->budget--) { s->failed_pc=0x0c07baaau; return 0; }
r[4]|=r[2];
goto P_0c07baac;
P_0c07baac: /* original 6043, guest PC 0x0c07baac */
if(!s->budget--) { s->failed_pc=0x0c07baacu; return 0; }
r[0]=r[4];
goto P_0c07baae;
P_0c07baae: /* original 1f4c, guest PC 0x0c07baae */
if(!s->budget--) { s->failed_pc=0x0c07baaeu; return 0; }
write(ram,r[15]+48,r[4],4);
goto P_0c07bab0;
P_0c07bab0: /* original d330, guest PC 0x0c07bab0 */
if(!s->budget--) { s->failed_pc=0x0c07bab0u; return 0; }
r[3]=read(ram,0x0c07bb74u,4);
goto P_0c07bab2;
P_0c07bab2: /* original c904, guest PC 0x0c07bab2 */
if(!s->budget--) { s->failed_pc=0x0c07bab2u; return 0; }
r[0]&=4u;
goto P_0c07bab4;
P_0c07bab4: /* original 52d2, guest PC 0x0c07bab4 */
if(!s->budget--) { s->failed_pc=0x0c07bab4u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c07bab6;
P_0c07bab6: /* original 2238, guest PC 0x0c07bab6 */
if(!s->budget--) { s->failed_pc=0x0c07bab6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07bab8;
P_0c07bab8: /* original 8f02, guest PC 0x0c07bab8 */
if(!s->budget--) { s->failed_pc=0x0c07bab8u; return 0; }
cond=r[17]&1u;
r[12]=r[0];
if(!cond) { goto P_0c07bac0; }
goto P_0c07babc;
P_0c07baba: /* original 6c03, guest PC 0x0c07baba */
if(!s->budget--) { s->failed_pc=0x0c07babau; return 0; }
r[12]=r[0];
goto P_0c07babc;
P_0c07babc: /* original a408, guest PC 0x0c07babc */
if(!s->budget--) { s->failed_pc=0x0c07babcu; return 0; }
goto P_0c07c2d0;
P_0c07babe: /* original 0009, guest PC 0x0c07babe */
if(!s->budget--) { s->failed_pc=0x0c07babeu; return 0; }
goto P_0c07bac0;
P_0c07bac0: /* original 2cc8, guest PC 0x0c07bac0 */
if(!s->budget--) { s->failed_pc=0x0c07bac0u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c07bac2;
P_0c07bac2: /* original 8b01, guest PC 0x0c07bac2 */
if(!s->budget--) { s->failed_pc=0x0c07bac2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bac8; }
goto P_0c07bac4;
P_0c07bac4: /* original a415, guest PC 0x0c07bac4 */
if(!s->budget--) { s->failed_pc=0x0c07bac4u; return 0; }
goto P_0c07c2f2;
P_0c07bac6: /* original 0009, guest PC 0x0c07bac6 */
if(!s->budget--) { s->failed_pc=0x0c07bac6u; return 0; }
goto P_0c07bac8;
P_0c07bac8: /* original d231, guest PC 0x0c07bac8 */
if(!s->budget--) { s->failed_pc=0x0c07bac8u; return 0; }
r[2]=read(ram,0x0c07bb90u,4);
goto P_0c07baca;
P_0c07baca: /* original e026, guest PC 0x0c07baca */
if(!s->budget--) { s->failed_pc=0x0c07bacau; return 0; }
r[0]=0x00000026u;
goto P_0c07bacc;
P_0c07bacc: /* original dd2f, guest PC 0x0c07bacc */
if(!s->budget--) { s->failed_pc=0x0c07baccu; return 0; }
r[13]=read(ram,0x0c07bb8cu,4);
goto P_0c07bace;
P_0c07bace: /* original e553, guest PC 0x0c07bace */
if(!s->budget--) { s->failed_pc=0x0c07baceu; return 0; }
r[5]=0x00000053u;
goto P_0c07bad0;
P_0c07bad0: /* original 2f22, guest PC 0x0c07bad0 */
if(!s->budget--) { s->failed_pc=0x0c07bad0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c07bad2;
P_0c07bad2: /* original e209, guest PC 0x0c07bad2 */
if(!s->budget--) { s->failed_pc=0x0c07bad2u; return 0; }
r[2]=0x00000009u;
goto P_0c07bad4;
P_0c07bad4: /* original 7d2c, guest PC 0x0c07bad4 */
if(!s->budget--) { s->failed_pc=0x0c07bad4u; return 0; }
r[13]+=0x0000002cu;
goto P_0c07bad6;
P_0c07bad6: /* original 0d25, guest PC 0x0c07bad6 */
if(!s->budget--) { s->failed_pc=0x0c07bad6u; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c07bad8;
P_0c07bad8: /* original e022, guest PC 0x0c07bad8 */
if(!s->budget--) { s->failed_pc=0x0c07bad8u; return 0; }
r[0]=0x00000022u;
goto P_0c07bada;
P_0c07bada: /* original 01dd, guest PC 0x0c07bada */
if(!s->budget--) { s->failed_pc=0x0c07badau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c07badc;
P_0c07badc: /* original e202, guest PC 0x0c07badc */
if(!s->budget--) { s->failed_pc=0x0c07badcu; return 0; }
r[2]=0x00000002u;
goto P_0c07bade;
P_0c07bade: /* original 212b, guest PC 0x0c07bade */
if(!s->budget--) { s->failed_pc=0x0c07badeu; return 0; }
r[1]|=r[2];
goto P_0c07bae0;
P_0c07bae0: /* original 0d15, guest PC 0x0c07bae0 */
if(!s->budget--) { s->failed_pc=0x0c07bae0u; return 0; }
write(ram,r[13]+r[0],r[1],2);
goto P_0c07bae2;
P_0c07bae2: /* original d12c, guest PC 0x0c07bae2 */
if(!s->budget--) { s->failed_pc=0x0c07bae2u; return 0; }
r[1]=read(ram,0x0c07bb94u,4);
goto P_0c07bae4;
P_0c07bae4: /* original 410b, guest PC 0x0c07bae4 */
if(!s->budget--) { s->failed_pc=0x0c07bae4u; return 0; }
target=r[1];
r[16]=code_base|0x0c07bae8u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bae8u) { target=s->pc; goto dispatch; }
goto P_0c07bae8;
P_0c07bae6: /* original 64d3, guest PC 0x0c07bae6 */
if(!s->budget--) { s->failed_pc=0x0c07bae6u; return 0; }
r[4]=r[13];
goto P_0c07bae8;
P_0c07bae8: /* original 9332, guest PC 0x0c07bae8 */
if(!s->budget--) { s->failed_pc=0x0c07bae8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb50u,2);
goto P_0c07baea;
P_0c07baea: /* original 33fc, guest PC 0x0c07baea */
if(!s->budget--) { s->failed_pc=0x0c07baeau; return 0; }
r[3]+=r[15];
goto P_0c07baec;
P_0c07baec: /* original 1f31, guest PC 0x0c07baec */
if(!s->budget--) { s->failed_pc=0x0c07baecu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07baee;
P_0c07baee: /* original 62f2, guest PC 0x0c07baee */
if(!s->budget--) { s->failed_pc=0x0c07baeeu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07baf0;
P_0c07baf0: /* original 902f, guest PC 0x0c07baf0 */
if(!s->budget--) { s->failed_pc=0x0c07baf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb52u,2);
goto P_0c07baf2;
P_0c07baf2: /* original 012d, guest PC 0x0c07baf2 */
if(!s->budget--) { s->failed_pc=0x0c07baf2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c07baf4;
P_0c07baf4: /* original 611d, guest PC 0x0c07baf4 */
if(!s->budget--) { s->failed_pc=0x0c07baf4u; return 0; }
r[1]=r[1]&65535u;
goto P_0c07baf6;
P_0c07baf6: /* original 2312, guest PC 0x0c07baf6 */
if(!s->budget--) { s->failed_pc=0x0c07baf6u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c07baf8;
P_0c07baf8: /* original 902c, guest PC 0x0c07baf8 */
if(!s->budget--) { s->failed_pc=0x0c07baf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb54u,2);
goto P_0c07bafa;
P_0c07bafa: /* original 63f2, guest PC 0x0c07bafa */
if(!s->budget--) { s->failed_pc=0x0c07bafau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07bafc;
P_0c07bafc: /* original 54f1, guest PC 0x0c07bafc */
if(!s->budget--) { s->failed_pc=0x0c07bafcu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07bafe;
P_0c07bafe: /* original 023d, guest PC 0x0c07bafe */
if(!s->budget--) { s->failed_pc=0x0c07bafeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07bb00;
P_0c07bb00: /* original 7408, guest PC 0x0c07bb00 */
if(!s->budget--) { s->failed_pc=0x0c07bb00u; return 0; }
r[4]+=0x00000008u;
goto P_0c07bb02;
P_0c07bb02: /* original 622d, guest PC 0x0c07bb02 */
if(!s->budget--) { s->failed_pc=0x0c07bb02u; return 0; }
r[2]=r[2]&65535u;
goto P_0c07bb04;
P_0c07bb04: /* original 2422, guest PC 0x0c07bb04 */
if(!s->budget--) { s->failed_pc=0x0c07bb04u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c07bb06;
P_0c07bb06: /* original 9026, guest PC 0x0c07bb06 */
if(!s->budget--) { s->failed_pc=0x0c07bb06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb56u,2);
goto P_0c07bb08;
P_0c07bb08: /* original 62f2, guest PC 0x0c07bb08 */
if(!s->budget--) { s->failed_pc=0x0c07bb08u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07bb0a;
P_0c07bb0a: /* original 53f1, guest PC 0x0c07bb0a */
if(!s->budget--) { s->failed_pc=0x0c07bb0au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07bb0c;
P_0c07bb0c: /* original 012d, guest PC 0x0c07bb0c */
if(!s->budget--) { s->failed_pc=0x0c07bb0cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c07bb0e;
P_0c07bb0e: /* original 611d, guest PC 0x0c07bb0e */
if(!s->budget--) { s->failed_pc=0x0c07bb0eu; return 0; }
r[1]=r[1]&65535u;
goto P_0c07bb10;
P_0c07bb10: /* original 1311, guest PC 0x0c07bb10 */
if(!s->budget--) { s->failed_pc=0x0c07bb10u; return 0; }
write(ram,r[3]+4,r[1],4);
goto P_0c07bb12;
P_0c07bb12: /* original 9021, guest PC 0x0c07bb12 */
if(!s->budget--) { s->failed_pc=0x0c07bb12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb58u,2);
goto P_0c07bb14;
P_0c07bb14: /* original 63f2, guest PC 0x0c07bb14 */
if(!s->budget--) { s->failed_pc=0x0c07bb14u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07bb16;
P_0c07bb16: /* original 023d, guest PC 0x0c07bb16 */
if(!s->budget--) { s->failed_pc=0x0c07bb16u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07bb18;
P_0c07bb18: /* original 622d, guest PC 0x0c07bb18 */
if(!s->budget--) { s->failed_pc=0x0c07bb18u; return 0; }
r[2]=r[2]&65535u;
goto P_0c07bb1a;
P_0c07bb1a: /* original 1421, guest PC 0x0c07bb1a */
if(!s->budget--) { s->failed_pc=0x0c07bb1au; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c07bb1c;
P_0c07bb1c: /* original 63f2, guest PC 0x0c07bb1c */
if(!s->budget--) { s->failed_pc=0x0c07bb1cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07bb1e;
P_0c07bb1e: /* original 901c, guest PC 0x0c07bb1e */
if(!s->budget--) { s->failed_pc=0x0c07bb1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb5au,2);
goto P_0c07bb20;
P_0c07bb20: /* original 023d, guest PC 0x0c07bb20 */
if(!s->budget--) { s->failed_pc=0x0c07bb20u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07bb22;
P_0c07bb22: /* original e07c, guest PC 0x0c07bb22 */
if(!s->budget--) { s->failed_pc=0x0c07bb22u; return 0; }
r[0]=0x0000007cu;
goto P_0c07bb24;
P_0c07bb24: /* original 622d, guest PC 0x0c07bb24 */
if(!s->budget--) { s->failed_pc=0x0c07bb24u; return 0; }
r[2]=r[2]&65535u;
goto P_0c07bb26;
P_0c07bb26: /* original 0f26, guest PC 0x0c07bb26 */
if(!s->budget--) { s->failed_pc=0x0c07bb26u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07bb28;
P_0c07bb28: /* original 9018, guest PC 0x0c07bb28 */
if(!s->budget--) { s->failed_pc=0x0c07bb28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb5cu,2);
goto P_0c07bb2a;
P_0c07bb2a: /* original 63f2, guest PC 0x0c07bb2a */
if(!s->budget--) { s->failed_pc=0x0c07bb2au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07bb2c;
P_0c07bb2c: /* original 023d, guest PC 0x0c07bb2c */
if(!s->budget--) { s->failed_pc=0x0c07bb2cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07bb2e;
P_0c07bb2e: /* original 9016, guest PC 0x0c07bb2e */
if(!s->budget--) { s->failed_pc=0x0c07bb2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb5eu,2);
goto P_0c07bb30;
P_0c07bb30: /* original 622d, guest PC 0x0c07bb30 */
if(!s->budget--) { s->failed_pc=0x0c07bb30u; return 0; }
r[2]=r[2]&65535u;
goto P_0c07bb32;
P_0c07bb32: /* original 0f26, guest PC 0x0c07bb32 */
if(!s->budget--) { s->failed_pc=0x0c07bb32u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07bb34;
P_0c07bb34: /* original 9116, guest PC 0x0c07bb34 */
if(!s->budget--) { s->failed_pc=0x0c07bb34u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb64u,2);
goto P_0c07bb36;
P_0c07bb36: /* original 60f2, guest PC 0x0c07bb36 */
if(!s->budget--) { s->failed_pc=0x0c07bb36u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c07bb38;
P_0c07bb38: /* original d918, guest PC 0x0c07bb38 */
if(!s->budget--) { s->failed_pc=0x0c07bb38u; return 0; }
r[9]=read(ram,0x0c07bb9cu,4);
goto P_0c07bb3a;
P_0c07bb3a: /* original 001c, guest PC 0x0c07bb3a */
if(!s->budget--) { s->failed_pc=0x0c07bb3au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c07bb3c;
P_0c07bb3c: /* original 9a10, guest PC 0x0c07bb3c */
if(!s->budget--) { s->failed_pc=0x0c07bb3cu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb60u,2);
goto P_0c07bb3e;
P_0c07bb3e: /* original 9c10, guest PC 0x0c07bb3e */
if(!s->budget--) { s->failed_pc=0x0c07bb3eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb62u,2);
goto P_0c07bb40;
P_0c07bb40: /* original 8802, guest PC 0x0c07bb40 */
if(!s->budget--) { s->failed_pc=0x0c07bb40u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c07bb42;
P_0c07bb42: /* original d815, guest PC 0x0c07bb42 */
if(!s->budget--) { s->failed_pc=0x0c07bb42u; return 0; }
r[8]=read(ram,0x0c07bb98u,4);
goto P_0c07bb44;
P_0c07bb44: /* original a02c, guest PC 0x0c07bb44 */
if(!s->budget--) { s->failed_pc=0x0c07bb44u; return 0; }
goto P_0c07bba0;
P_0c07bb46: /* original 0009, guest PC 0x0c07bb46 */
if(!s->budget--) { s->failed_pc=0x0c07bb46u; return 0; }
return vf3_matrix_family(0x0c07bb48u,s,ram);
P_0c07bba0: /* original 8b3a, guest PC 0x0c07bba0 */
if(!s->budget--) { s->failed_pc=0x0c07bba0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bc18; }
goto P_0c07bba2;
P_0c07bba2: /* original 94aa, guest PC 0x0c07bba2 */
if(!s->budget--) { s->failed_pc=0x0c07bba2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfau,2);
goto P_0c07bba4;
P_0c07bba4: /* original 66d3, guest PC 0x0c07bba4 */
if(!s->budget--) { s->failed_pc=0x0c07bba4u; return 0; }
r[6]=r[13];
goto P_0c07bba6;
P_0c07bba6: /* original 2fe6, guest PC 0x0c07bba6 */
if(!s->budget--) { s->failed_pc=0x0c07bba6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bba8;
P_0c07bba8: /* original e700, guest PC 0x0c07bba8 */
if(!s->budget--) { s->failed_pc=0x0c07bba8u; return 0; }
r[7]=0x00000000u;
goto P_0c07bbaa;
P_0c07bbaa: /* original d258, guest PC 0x0c07bbaa */
if(!s->budget--) { s->failed_pc=0x0c07bbaau; return 0; }
r[2]=read(ram,0x0c07bd0cu,4);
goto P_0c07bbac;
P_0c07bbac: /* original 420b, guest PC 0x0c07bbac */
if(!s->budget--) { s->failed_pc=0x0c07bbacu; return 0; }
target=r[2];
r[16]=code_base|0x0c07bbb0u;
r[5]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bbb0u) { target=s->pc; goto dispatch; }
goto P_0c07bbb0;
P_0c07bbae: /* original 65c3, guest PC 0x0c07bbae */
if(!s->budget--) { s->failed_pc=0x0c07bbaeu; return 0; }
r[5]=r[12];
goto P_0c07bbb0;
P_0c07bbb0: /* original 7f04, guest PC 0x0c07bbb0 */
if(!s->budget--) { s->failed_pc=0x0c07bbb0u; return 0; }
r[15]+=0x00000004u;
goto P_0c07bbb2;
P_0c07bbb2: /* original 90a3, guest PC 0x0c07bbb2 */
if(!s->budget--) { s->failed_pc=0x0c07bbb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfcu,2);
goto P_0c07bbb4;
P_0c07bbb4: /* original 63f2, guest PC 0x0c07bbb4 */
if(!s->budget--) { s->failed_pc=0x0c07bbb4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07bbb6;
P_0c07bbb6: /* original 023c, guest PC 0x0c07bbb6 */
if(!s->budget--) { s->failed_pc=0x0c07bbb6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c07bbb8;
P_0c07bbb8: /* original 7001, guest PC 0x0c07bbb8 */
if(!s->budget--) { s->failed_pc=0x0c07bbb8u; return 0; }
r[0]+=0x00000001u;
goto P_0c07bbba;
P_0c07bbba: /* original 013c, guest PC 0x0c07bbba */
if(!s->budget--) { s->failed_pc=0x0c07bbbau; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c07bbbc;
P_0c07bbbc: /* original 3210, guest PC 0x0c07bbbc */
if(!s->budget--) { s->failed_pc=0x0c07bbbcu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c07bbbe;
P_0c07bbbe: /* original 8d0f, guest PC 0x0c07bbbe */
if(!s->budget--) { s->failed_pc=0x0c07bbbeu; return 0; }
cond=r[17]&1u;
r[4]=r[10];
if(cond) { goto P_0c07bbe0; }
goto P_0c07bbc2;
P_0c07bbc0: /* original 64a3, guest PC 0x0c07bbc0 */
if(!s->budget--) { s->failed_pc=0x0c07bbc0u; return 0; }
r[4]=r[10];
goto P_0c07bbc2;
P_0c07bbc2: /* original 2fe6, guest PC 0x0c07bbc2 */
if(!s->budget--) { s->failed_pc=0x0c07bbc2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bbc4;
P_0c07bbc4: /* original e700, guest PC 0x0c07bbc4 */
if(!s->budget--) { s->failed_pc=0x0c07bbc4u; return 0; }
r[7]=0x00000000u;
goto P_0c07bbc6;
P_0c07bbc6: /* original 5af1, guest PC 0x0c07bbc6 */
if(!s->budget--) { s->failed_pc=0x0c07bbc6u; return 0; }
r[10]=read(ram,r[15]+4,4);
goto P_0c07bbc8;
P_0c07bbc8: /* original 66d3, guest PC 0x0c07bbc8 */
if(!s->budget--) { s->failed_pc=0x0c07bbc8u; return 0; }
r[6]=r[13];
goto P_0c07bbca;
P_0c07bbca: /* original 9098, guest PC 0x0c07bbca */
if(!s->budget--) { s->failed_pc=0x0c07bbcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfeu,2);
goto P_0c07bbcc;
P_0c07bbcc: /* original d34f, guest PC 0x0c07bbcc */
if(!s->budget--) { s->failed_pc=0x0c07bbccu; return 0; }
r[3]=read(ram,0x0c07bd0cu,4);
goto P_0c07bbce;
P_0c07bbce: /* original 00ac, guest PC 0x0c07bbce */
if(!s->budget--) { s->failed_pc=0x0c07bbceu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c07bbd0;
P_0c07bbd0: /* original 4008, guest PC 0x0c07bbd0 */
if(!s->budget--) { s->failed_pc=0x0c07bbd0u; return 0; }
r[0]<<=2;
goto P_0c07bbd2;
P_0c07bbd2: /* original 430b, guest PC 0x0c07bbd2 */
if(!s->budget--) { s->failed_pc=0x0c07bbd2u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bbd6u;
r[5]=read(ram,r[9]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bbd6u) { target=s->pc; goto dispatch; }
goto P_0c07bbd6;
P_0c07bbd4: /* original 059e, guest PC 0x0c07bbd4 */
if(!s->budget--) { s->failed_pc=0x0c07bbd4u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bbd6;
P_0c07bbd6: /* original 9091, guest PC 0x0c07bbd6 */
if(!s->budget--) { s->failed_pc=0x0c07bbd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfcu,2);
goto P_0c07bbd8;
P_0c07bbd8: /* original 7f04, guest PC 0x0c07bbd8 */
if(!s->budget--) { s->failed_pc=0x0c07bbd8u; return 0; }
r[15]+=0x00000004u;
goto P_0c07bbda;
P_0c07bbda: /* original 02ac, guest PC 0x0c07bbda */
if(!s->budget--) { s->failed_pc=0x0c07bbdau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c07bbdc;
P_0c07bbdc: /* original 7001, guest PC 0x0c07bbdc */
if(!s->budget--) { s->failed_pc=0x0c07bbdcu; return 0; }
r[0]+=0x00000001u;
goto P_0c07bbde;
P_0c07bbde: /* original 0a24, guest PC 0x0c07bbde */
if(!s->budget--) { s->failed_pc=0x0c07bbdeu; return 0; }
write(ram,r[10]+r[0],r[2],1);
goto P_0c07bbe0;
P_0c07bbe0: /* original 2fb6, guest PC 0x0c07bbe0 */
if(!s->budget--) { s->failed_pc=0x0c07bbe0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bbe2;
P_0c07bbe2: /* original 66d3, guest PC 0x0c07bbe2 */
if(!s->budget--) { s->failed_pc=0x0c07bbe2u; return 0; }
r[6]=r[13];
goto P_0c07bbe4;
P_0c07bbe4: /* original 2fe6, guest PC 0x0c07bbe4 */
if(!s->budget--) { s->failed_pc=0x0c07bbe4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bbe6;
P_0c07bbe6: /* original e700, guest PC 0x0c07bbe6 */
if(!s->budget--) { s->failed_pc=0x0c07bbe6u; return 0; }
r[7]=0x00000000u;
goto P_0c07bbe8;
P_0c07bbe8: /* original 948a, guest PC 0x0c07bbe8 */
if(!s->budget--) { s->failed_pc=0x0c07bbe8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd00u,2);
goto P_0c07bbea;
P_0c07bbea: /* original 480b, guest PC 0x0c07bbea */
if(!s->budget--) { s->failed_pc=0x0c07bbeau; return 0; }
target=r[8];
r[16]=code_base|0x0c07bbeeu;
r[5]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bbeeu) { target=s->pc; goto dispatch; }
goto P_0c07bbee;
P_0c07bbec: /* original 65c3, guest PC 0x0c07bbec */
if(!s->budget--) { s->failed_pc=0x0c07bbecu; return 0; }
r[5]=r[12];
goto P_0c07bbee;
P_0c07bbee: /* original 2fb6, guest PC 0x0c07bbee */
if(!s->budget--) { s->failed_pc=0x0c07bbeeu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bbf0;
P_0c07bbf0: /* original 66d3, guest PC 0x0c07bbf0 */
if(!s->budget--) { s->failed_pc=0x0c07bbf0u; return 0; }
r[6]=r[13];
goto P_0c07bbf2;
P_0c07bbf2: /* original 2fe6, guest PC 0x0c07bbf2 */
if(!s->budget--) { s->failed_pc=0x0c07bbf2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bbf4;
P_0c07bbf4: /* original e700, guest PC 0x0c07bbf4 */
if(!s->budget--) { s->failed_pc=0x0c07bbf4u; return 0; }
r[7]=0x00000000u;
goto P_0c07bbf6;
P_0c07bbf6: /* original 9484, guest PC 0x0c07bbf6 */
if(!s->budget--) { s->failed_pc=0x0c07bbf6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd02u,2);
goto P_0c07bbf8;
P_0c07bbf8: /* original 480b, guest PC 0x0c07bbf8 */
if(!s->budget--) { s->failed_pc=0x0c07bbf8u; return 0; }
target=r[8];
r[16]=code_base|0x0c07bbfcu;
r[5]=read(ram,r[9]+40,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bbfcu) { target=s->pc; goto dispatch; }
goto P_0c07bbfc;
P_0c07bbfa: /* original 559a, guest PC 0x0c07bbfa */
if(!s->budget--) { s->failed_pc=0x0c07bbfau; return 0; }
r[5]=read(ram,r[9]+40,4);
goto P_0c07bbfc;
P_0c07bbfc: /* original 2fb6, guest PC 0x0c07bbfc */
if(!s->budget--) { s->failed_pc=0x0c07bbfcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bbfe;
P_0c07bbfe: /* original e700, guest PC 0x0c07bbfe */
if(!s->budget--) { s->failed_pc=0x0c07bbfeu; return 0; }
r[7]=0x00000000u;
goto P_0c07bc00;
P_0c07bc00: /* original 2fe6, guest PC 0x0c07bc00 */
if(!s->budget--) { s->failed_pc=0x0c07bc00u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc02;
P_0c07bc02: /* original 66d3, guest PC 0x0c07bc02 */
if(!s->budget--) { s->failed_pc=0x0c07bc02u; return 0; }
r[6]=r[13];
goto P_0c07bc04;
P_0c07bc04: /* original 55f6, guest PC 0x0c07bc04 */
if(!s->budget--) { s->failed_pc=0x0c07bc04u; return 0; }
r[5]=read(ram,r[15]+24,4);
goto P_0c07bc06;
P_0c07bc06: /* original 907d, guest PC 0x0c07bc06 */
if(!s->budget--) { s->failed_pc=0x0c07bc06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd04u,2);
goto P_0c07bc08;
P_0c07bc08: /* original 947d, guest PC 0x0c07bc08 */
if(!s->budget--) { s->failed_pc=0x0c07bc08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd06u,2);
goto P_0c07bc0a;
P_0c07bc0a: /* original 055c, guest PC 0x0c07bc0a */
if(!s->budget--) { s->failed_pc=0x0c07bc0au; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07bc0c;
P_0c07bc0c: /* original 4508, guest PC 0x0c07bc0c */
if(!s->budget--) { s->failed_pc=0x0c07bc0cu; return 0; }
r[5]<<=2;
goto P_0c07bc0e;
P_0c07bc0e: /* original 359c, guest PC 0x0c07bc0e */
if(!s->budget--) { s->failed_pc=0x0c07bc0eu; return 0; }
r[5]+=r[9];
goto P_0c07bc10;
P_0c07bc10: /* original 480b, guest PC 0x0c07bc10 */
if(!s->budget--) { s->failed_pc=0x0c07bc10u; return 0; }
target=r[8];
r[16]=code_base|0x0c07bc14u;
r[5]=read(ram,r[5]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bc14u) { target=s->pc; goto dispatch; }
goto P_0c07bc14;
P_0c07bc12: /* original 5551, guest PC 0x0c07bc12 */
if(!s->budget--) { s->failed_pc=0x0c07bc12u; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c07bc14;
P_0c07bc14: /* original a045, guest PC 0x0c07bc14 */
if(!s->budget--) { s->failed_pc=0x0c07bc14u; return 0; }
r[15]+=0x00000018u;
goto P_0c07bca2;
P_0c07bc16: /* original 7f18, guest PC 0x0c07bc16 */
if(!s->budget--) { s->failed_pc=0x0c07bc16u; return 0; }
r[15]+=0x00000018u;
goto P_0c07bc18;
P_0c07bc18: /* original 9472, guest PC 0x0c07bc18 */
if(!s->budget--) { s->failed_pc=0x0c07bc18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd00u,2);
goto P_0c07bc1a;
P_0c07bc1a: /* original 66d3, guest PC 0x0c07bc1a */
if(!s->budget--) { s->failed_pc=0x0c07bc1au; return 0; }
r[6]=r[13];
goto P_0c07bc1c;
P_0c07bc1c: /* original 2fe6, guest PC 0x0c07bc1c */
if(!s->budget--) { s->failed_pc=0x0c07bc1cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc1e;
P_0c07bc1e: /* original e700, guest PC 0x0c07bc1e */
if(!s->budget--) { s->failed_pc=0x0c07bc1eu; return 0; }
r[7]=0x00000000u;
goto P_0c07bc20;
P_0c07bc20: /* original d23a, guest PC 0x0c07bc20 */
if(!s->budget--) { s->failed_pc=0x0c07bc20u; return 0; }
r[2]=read(ram,0x0c07bd0cu,4);
goto P_0c07bc22;
P_0c07bc22: /* original 420b, guest PC 0x0c07bc22 */
if(!s->budget--) { s->failed_pc=0x0c07bc22u; return 0; }
target=r[2];
r[16]=code_base|0x0c07bc26u;
r[5]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bc26u) { target=s->pc; goto dispatch; }
goto P_0c07bc26;
P_0c07bc24: /* original 65c3, guest PC 0x0c07bc24 */
if(!s->budget--) { s->failed_pc=0x0c07bc24u; return 0; }
r[5]=r[12];
goto P_0c07bc26;
P_0c07bc26: /* original 946c, guest PC 0x0c07bc26 */
if(!s->budget--) { s->failed_pc=0x0c07bc26u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd02u,2);
goto P_0c07bc28;
P_0c07bc28: /* original 66d3, guest PC 0x0c07bc28 */
if(!s->budget--) { s->failed_pc=0x0c07bc28u; return 0; }
r[6]=r[13];
goto P_0c07bc2a;
P_0c07bc2a: /* original 2fe6, guest PC 0x0c07bc2a */
if(!s->budget--) { s->failed_pc=0x0c07bc2au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc2c;
P_0c07bc2c: /* original e700, guest PC 0x0c07bc2c */
if(!s->budget--) { s->failed_pc=0x0c07bc2cu; return 0; }
r[7]=0x00000000u;
goto P_0c07bc2e;
P_0c07bc2e: /* original d337, guest PC 0x0c07bc2e */
if(!s->budget--) { s->failed_pc=0x0c07bc2eu; return 0; }
r[3]=read(ram,0x0c07bd0cu,4);
goto P_0c07bc30;
P_0c07bc30: /* original 430b, guest PC 0x0c07bc30 */
if(!s->budget--) { s->failed_pc=0x0c07bc30u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bc34u;
r[5]=read(ram,r[9]+40,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bc34u) { target=s->pc; goto dispatch; }
goto P_0c07bc34;
P_0c07bc32: /* original 559a, guest PC 0x0c07bc32 */
if(!s->budget--) { s->failed_pc=0x0c07bc32u; return 0; }
r[5]=read(ram,r[9]+40,4);
goto P_0c07bc34;
P_0c07bc34: /* original 9467, guest PC 0x0c07bc34 */
if(!s->budget--) { s->failed_pc=0x0c07bc34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd06u,2);
goto P_0c07bc36;
P_0c07bc36: /* original e700, guest PC 0x0c07bc36 */
if(!s->budget--) { s->failed_pc=0x0c07bc36u; return 0; }
r[7]=0x00000000u;
goto P_0c07bc38;
P_0c07bc38: /* original 2fe6, guest PC 0x0c07bc38 */
if(!s->budget--) { s->failed_pc=0x0c07bc38u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc3a;
P_0c07bc3a: /* original 66d3, guest PC 0x0c07bc3a */
if(!s->budget--) { s->failed_pc=0x0c07bc3au; return 0; }
r[6]=r[13];
goto P_0c07bc3c;
P_0c07bc3c: /* original 55f3, guest PC 0x0c07bc3c */
if(!s->budget--) { s->failed_pc=0x0c07bc3cu; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c07bc3e;
P_0c07bc3e: /* original 9061, guest PC 0x0c07bc3e */
if(!s->budget--) { s->failed_pc=0x0c07bc3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd04u,2);
goto P_0c07bc40;
P_0c07bc40: /* original d332, guest PC 0x0c07bc40 */
if(!s->budget--) { s->failed_pc=0x0c07bc40u; return 0; }
r[3]=read(ram,0x0c07bd0cu,4);
goto P_0c07bc42;
P_0c07bc42: /* original 055c, guest PC 0x0c07bc42 */
if(!s->budget--) { s->failed_pc=0x0c07bc42u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07bc44;
P_0c07bc44: /* original 4508, guest PC 0x0c07bc44 */
if(!s->budget--) { s->failed_pc=0x0c07bc44u; return 0; }
r[5]<<=2;
goto P_0c07bc46;
P_0c07bc46: /* original 359c, guest PC 0x0c07bc46 */
if(!s->budget--) { s->failed_pc=0x0c07bc46u; return 0; }
r[5]+=r[9];
goto P_0c07bc48;
P_0c07bc48: /* original 430b, guest PC 0x0c07bc48 */
if(!s->budget--) { s->failed_pc=0x0c07bc48u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bc4cu;
r[5]=read(ram,r[5]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bc4cu) { target=s->pc; goto dispatch; }
goto P_0c07bc4c;
P_0c07bc4a: /* original 5551, guest PC 0x0c07bc4a */
if(!s->budget--) { s->failed_pc=0x0c07bc4au; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c07bc4c;
P_0c07bc4c: /* original 2fb6, guest PC 0x0c07bc4c */
if(!s->budget--) { s->failed_pc=0x0c07bc4cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc4e;
P_0c07bc4e: /* original 66d3, guest PC 0x0c07bc4e */
if(!s->budget--) { s->failed_pc=0x0c07bc4eu; return 0; }
r[6]=r[13];
goto P_0c07bc50;
P_0c07bc50: /* original 2fe6, guest PC 0x0c07bc50 */
if(!s->budget--) { s->failed_pc=0x0c07bc50u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc52;
P_0c07bc52: /* original e700, guest PC 0x0c07bc52 */
if(!s->budget--) { s->failed_pc=0x0c07bc52u; return 0; }
r[7]=0x00000000u;
goto P_0c07bc54;
P_0c07bc54: /* original 9451, guest PC 0x0c07bc54 */
if(!s->budget--) { s->failed_pc=0x0c07bc54u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfau,2);
goto P_0c07bc56;
P_0c07bc56: /* original 480b, guest PC 0x0c07bc56 */
if(!s->budget--) { s->failed_pc=0x0c07bc56u; return 0; }
target=r[8];
r[16]=code_base|0x0c07bc5au;
r[5]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bc5au) { target=s->pc; goto dispatch; }
goto P_0c07bc5a;
P_0c07bc58: /* original 65c3, guest PC 0x0c07bc58 */
if(!s->budget--) { s->failed_pc=0x0c07bc58u; return 0; }
r[5]=r[12];
goto P_0c07bc5a;
P_0c07bc5a: /* original 7f14, guest PC 0x0c07bc5a */
if(!s->budget--) { s->failed_pc=0x0c07bc5au; return 0; }
r[15]+=0x00000014u;
goto P_0c07bc5c;
P_0c07bc5c: /* original 904e, guest PC 0x0c07bc5c */
if(!s->budget--) { s->failed_pc=0x0c07bc5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfcu,2);
goto P_0c07bc5e;
P_0c07bc5e: /* original 62f2, guest PC 0x0c07bc5e */
if(!s->budget--) { s->failed_pc=0x0c07bc5eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07bc60;
P_0c07bc60: /* original 032c, guest PC 0x0c07bc60 */
if(!s->budget--) { s->failed_pc=0x0c07bc60u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c07bc62;
P_0c07bc62: /* original 7001, guest PC 0x0c07bc62 */
if(!s->budget--) { s->failed_pc=0x0c07bc62u; return 0; }
r[0]+=0x00000001u;
goto P_0c07bc64;
P_0c07bc64: /* original 012c, guest PC 0x0c07bc64 */
if(!s->budget--) { s->failed_pc=0x0c07bc64u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c07bc66;
P_0c07bc66: /* original 3310, guest PC 0x0c07bc66 */
if(!s->budget--) { s->failed_pc=0x0c07bc66u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c07bc68;
P_0c07bc68: /* original 8d0f, guest PC 0x0c07bc68 */
if(!s->budget--) { s->failed_pc=0x0c07bc68u; return 0; }
cond=r[17]&1u;
r[4]=r[10];
if(cond) { goto P_0c07bc8a; }
goto P_0c07bc6c;
P_0c07bc6a: /* original 64a3, guest PC 0x0c07bc6a */
if(!s->budget--) { s->failed_pc=0x0c07bc6au; return 0; }
r[4]=r[10];
goto P_0c07bc6c;
P_0c07bc6c: /* original 2fe6, guest PC 0x0c07bc6c */
if(!s->budget--) { s->failed_pc=0x0c07bc6cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc6e;
P_0c07bc6e: /* original e700, guest PC 0x0c07bc6e */
if(!s->budget--) { s->failed_pc=0x0c07bc6eu; return 0; }
r[7]=0x00000000u;
goto P_0c07bc70;
P_0c07bc70: /* original 5cf1, guest PC 0x0c07bc70 */
if(!s->budget--) { s->failed_pc=0x0c07bc70u; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c07bc72;
P_0c07bc72: /* original 66d3, guest PC 0x0c07bc72 */
if(!s->budget--) { s->failed_pc=0x0c07bc72u; return 0; }
r[6]=r[13];
goto P_0c07bc74;
P_0c07bc74: /* original 9043, guest PC 0x0c07bc74 */
if(!s->budget--) { s->failed_pc=0x0c07bc74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfeu,2);
goto P_0c07bc76;
P_0c07bc76: /* original d325, guest PC 0x0c07bc76 */
if(!s->budget--) { s->failed_pc=0x0c07bc76u; return 0; }
r[3]=read(ram,0x0c07bd0cu,4);
goto P_0c07bc78;
P_0c07bc78: /* original 00cc, guest PC 0x0c07bc78 */
if(!s->budget--) { s->failed_pc=0x0c07bc78u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c07bc7a;
P_0c07bc7a: /* original 4008, guest PC 0x0c07bc7a */
if(!s->budget--) { s->failed_pc=0x0c07bc7au; return 0; }
r[0]<<=2;
goto P_0c07bc7c;
P_0c07bc7c: /* original 430b, guest PC 0x0c07bc7c */
if(!s->budget--) { s->failed_pc=0x0c07bc7cu; return 0; }
target=r[3];
r[16]=code_base|0x0c07bc80u;
r[5]=read(ram,r[9]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bc80u) { target=s->pc; goto dispatch; }
goto P_0c07bc80;
P_0c07bc7e: /* original 059e, guest PC 0x0c07bc7e */
if(!s->budget--) { s->failed_pc=0x0c07bc7eu; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bc80;
P_0c07bc80: /* original 903c, guest PC 0x0c07bc80 */
if(!s->budget--) { s->failed_pc=0x0c07bc80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfcu,2);
goto P_0c07bc82;
P_0c07bc82: /* original 7f04, guest PC 0x0c07bc82 */
if(!s->budget--) { s->failed_pc=0x0c07bc82u; return 0; }
r[15]+=0x00000004u;
goto P_0c07bc84;
P_0c07bc84: /* original 02cc, guest PC 0x0c07bc84 */
if(!s->budget--) { s->failed_pc=0x0c07bc84u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c07bc86;
P_0c07bc86: /* original 7001, guest PC 0x0c07bc86 */
if(!s->budget--) { s->failed_pc=0x0c07bc86u; return 0; }
r[0]+=0x00000001u;
goto P_0c07bc88;
P_0c07bc88: /* original 0c24, guest PC 0x0c07bc88 */
if(!s->budget--) { s->failed_pc=0x0c07bc88u; return 0; }
write(ram,r[12]+r[0],r[2],1);
goto P_0c07bc8a;
P_0c07bc8a: /* original 2fb6, guest PC 0x0c07bc8a */
if(!s->budget--) { s->failed_pc=0x0c07bc8au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc8c;
P_0c07bc8c: /* original e700, guest PC 0x0c07bc8c */
if(!s->budget--) { s->failed_pc=0x0c07bc8cu; return 0; }
r[7]=0x00000000u;
goto P_0c07bc8e;
P_0c07bc8e: /* original 2fe6, guest PC 0x0c07bc8e */
if(!s->budget--) { s->failed_pc=0x0c07bc8eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc90;
P_0c07bc90: /* original 66d3, guest PC 0x0c07bc90 */
if(!s->budget--) { s->failed_pc=0x0c07bc90u; return 0; }
r[6]=r[13];
goto P_0c07bc92;
P_0c07bc92: /* original 50f2, guest PC 0x0c07bc92 */
if(!s->budget--) { s->failed_pc=0x0c07bc92u; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c07bc94;
P_0c07bc94: /* original 9132, guest PC 0x0c07bc94 */
if(!s->budget--) { s->failed_pc=0x0c07bc94u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfcu,2);
goto P_0c07bc96;
P_0c07bc96: /* original 001c, guest PC 0x0c07bc96 */
if(!s->budget--) { s->failed_pc=0x0c07bc96u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c07bc98;
P_0c07bc98: /* original 4008, guest PC 0x0c07bc98 */
if(!s->budget--) { s->failed_pc=0x0c07bc98u; return 0; }
r[0]<<=2;
goto P_0c07bc9a;
P_0c07bc9a: /* original 059e, guest PC 0x0c07bc9a */
if(!s->budget--) { s->failed_pc=0x0c07bc9au; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bc9c;
P_0c07bc9c: /* original 480b, guest PC 0x0c07bc9c */
if(!s->budget--) { s->failed_pc=0x0c07bc9cu; return 0; }
target=r[8];
r[16]=code_base|0x0c07bca0u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bca0u) { target=s->pc; goto dispatch; }
goto P_0c07bca0;
P_0c07bc9e: /* original 64a3, guest PC 0x0c07bc9e */
if(!s->budget--) { s->failed_pc=0x0c07bc9eu; return 0; }
r[4]=r[10];
goto P_0c07bca0;
P_0c07bca0: /* original 7f08, guest PC 0x0c07bca0 */
if(!s->budget--) { s->failed_pc=0x0c07bca0u; return 0; }
r[15]+=0x00000008u;
goto P_0c07bca2;
P_0c07bca2: /* original d31b, guest PC 0x0c07bca2 */
if(!s->budget--) { s->failed_pc=0x0c07bca2u; return 0; }
r[3]=read(ram,0x0c07bd10u,4);
goto P_0c07bca4;
P_0c07bca4: /* original fe8d, guest PC 0x0c07bca4 */
if(!s->budget--) { s->failed_pc=0x0c07bca4u; return 0; }
fr[14]=0;
goto P_0c07bca6;
P_0c07bca6: /* original 6032, guest PC 0x0c07bca6 */
if(!s->budget--) { s->failed_pc=0x0c07bca6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07bca8;
P_0c07bca8: /* original c801, guest PC 0x0c07bca8 */
if(!s->budget--) { s->failed_pc=0x0c07bca8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c07bcaa;
P_0c07bcaa: /* original 8d02, guest PC 0x0c07bcaa */
if(!s->budget--) { s->failed_pc=0x0c07bcaau; return 0; }
cond=r[17]&1u;
r[10]=0x00000064u;
if(cond) { goto P_0c07bcb2; }
goto P_0c07bcae;
P_0c07bcac: /* original ea64, guest PC 0x0c07bcac */
if(!s->budget--) { s->failed_pc=0x0c07bcacu; return 0; }
r[10]=0x00000064u;
goto P_0c07bcae;
P_0c07bcae: /* original a212, guest PC 0x0c07bcae */
if(!s->budget--) { s->failed_pc=0x0c07bcaeu; return 0; }
goto P_0c07c0d6;
P_0c07bcb0: /* original 0009, guest PC 0x0c07bcb0 */
if(!s->budget--) { s->failed_pc=0x0c07bcb0u; return 0; }
goto P_0c07bcb2;
P_0c07bcb2: /* original 6193, guest PC 0x0c07bcb2 */
if(!s->budget--) { s->failed_pc=0x0c07bcb2u; return 0; }
r[1]=r[9];
goto P_0c07bcb4;
P_0c07bcb4: /* original 1fe8, guest PC 0x0c07bcb4 */
if(!s->budget--) { s->failed_pc=0x0c07bcb4u; return 0; }
write(ram,r[15]+32,r[14],4);
goto P_0c07bcb6;
P_0c07bcb6: /* original 9227, guest PC 0x0c07bcb6 */
if(!s->budget--) { s->failed_pc=0x0c07bcb6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd08u,2);
goto P_0c07bcb8;
P_0c07bcb8: /* original 32fc, guest PC 0x0c07bcb8 */
if(!s->budget--) { s->failed_pc=0x0c07bcb8u; return 0; }
r[2]+=r[15];
goto P_0c07bcba;
P_0c07bcba: /* original 1f2f, guest PC 0x0c07bcba */
if(!s->budget--) { s->failed_pc=0x0c07bcbau; return 0; }
write(ram,r[15]+60,r[2],4);
goto P_0c07bcbc;
P_0c07bcbc: /* original 1f1a, guest PC 0x0c07bcbc */
if(!s->budget--) { s->failed_pc=0x0c07bcbcu; return 0; }
write(ram,r[15]+40,r[1],4);
goto P_0c07bcbe;
P_0c07bcbe: /* original a196, guest PC 0x0c07bcbe */
if(!s->budget--) { s->failed_pc=0x0c07bcbeu; return 0; }
fr[15]=0x3f800000u;
goto P_0c07bfee;
P_0c07bcc0: /* original ff9d, guest PC 0x0c07bcc0 */
if(!s->budget--) { s->failed_pc=0x0c07bcc0u; return 0; }
fr[15]=0x3f800000u;
goto P_0c07bcc2;
P_0c07bcc2: /* original e122, guest PC 0x0c07bcc2 */
if(!s->budget--) { s->failed_pc=0x0c07bcc2u; return 0; }
r[1]=0x00000022u;
goto P_0c07bcc4;
P_0c07bcc4: /* original 53f8, guest PC 0x0c07bcc4 */
if(!s->budget--) { s->failed_pc=0x0c07bcc4u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c07bcc6;
P_0c07bcc6: /* original e007, guest PC 0x0c07bcc6 */
if(!s->budget--) { s->failed_pc=0x0c07bcc6u; return 0; }
r[0]=0x00000007u;
goto P_0c07bcc8;
P_0c07bcc8: /* original 6ce3, guest PC 0x0c07bcc8 */
if(!s->budget--) { s->failed_pc=0x0c07bcc8u; return 0; }
r[12]=r[14];
goto P_0c07bcca;
P_0c07bcca: /* original 4308, guest PC 0x0c07bcca */
if(!s->budget--) { s->failed_pc=0x0c07bccau; return 0; }
r[3]<<=2;
goto P_0c07bccc;
P_0c07bccc: /* original 4300, guest PC 0x0c07bccc */
if(!s->budget--) { s->failed_pc=0x0c07bcccu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07bcce;
P_0c07bcce: /* original 1f32, guest PC 0x0c07bcce */
if(!s->budget--) { s->failed_pc=0x0c07bcceu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07bcd0;
P_0c07bcd0: /* original 921a, guest PC 0x0c07bcd0 */
if(!s->budget--) { s->failed_pc=0x0c07bcd0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd08u,2);
goto P_0c07bcd2;
P_0c07bcd2: /* original 32fc, guest PC 0x0c07bcd2 */
if(!s->budget--) { s->failed_pc=0x0c07bcd2u; return 0; }
r[2]+=r[15];
goto P_0c07bcd4;
P_0c07bcd4: /* original 332c, guest PC 0x0c07bcd4 */
if(!s->budget--) { s->failed_pc=0x0c07bcd4u; return 0; }
r[3]+=r[2];
goto P_0c07bcd6;
P_0c07bcd6: /* original 1f34, guest PC 0x0c07bcd6 */
if(!s->budget--) { s->failed_pc=0x0c07bcd6u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c07bcd8;
P_0c07bcd8: /* original 1f39, guest PC 0x0c07bcd8 */
if(!s->budget--) { s->failed_pc=0x0c07bcd8u; return 0; }
write(ram,r[15]+36,r[3],4);
goto P_0c07bcda;
P_0c07bcda: /* original 1f1b, guest PC 0x0c07bcda */
if(!s->budget--) { s->failed_pc=0x0c07bcdau; return 0; }
write(ram,r[15]+44,r[1],4);
goto P_0c07bcdc;
P_0c07bcdc: /* original e11e, guest PC 0x0c07bcdc */
if(!s->budget--) { s->failed_pc=0x0c07bcdcu; return 0; }
r[1]=0x0000001eu;
goto P_0c07bcde;
P_0c07bcde: /* original 1f17, guest PC 0x0c07bcde */
if(!s->budget--) { s->failed_pc=0x0c07bcdeu; return 0; }
write(ram,r[15]+28,r[1],4);
goto P_0c07bce0;
P_0c07bce0: /* original 55f4, guest PC 0x0c07bce0 */
if(!s->budget--) { s->failed_pc=0x0c07bce0u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c07bce2;
P_0c07bce2: /* original 1f54, guest PC 0x0c07bce2 */
if(!s->budget--) { s->failed_pc=0x0c07bce2u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c07bce4;
P_0c07bce4: /* original 51f8, guest PC 0x0c07bce4 */
if(!s->budget--) { s->failed_pc=0x0c07bce4u; return 0; }
r[1]=read(ram,r[15]+32,4);
goto P_0c07bce6;
P_0c07bce6: /* original 4100, guest PC 0x0c07bce6 */
if(!s->budget--) { s->failed_pc=0x0c07bce6u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c07bce8;
P_0c07bce8: /* original 7102, guest PC 0x0c07bce8 */
if(!s->budget--) { s->failed_pc=0x0c07bce8u; return 0; }
r[1]+=0x00000002u;
goto P_0c07bcea;
P_0c07bcea: /* original 410c, guest PC 0x0c07bcea */
if(!s->budget--) { s->failed_pc=0x0c07bceau; return 0; }
r[1]=(r[0]&0x80000000u)?((r[0]&31u)?(uint32_t)((int32_t)r[1]>>((-r[0])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[0]&31u);
goto P_0c07bcec;
P_0c07bcec: /* original 1f11, guest PC 0x0c07bcec */
if(!s->budget--) { s->failed_pc=0x0c07bcecu; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c07bcee;
P_0c07bcee: /* original 1f54, guest PC 0x0c07bcee */
if(!s->budget--) { s->failed_pc=0x0c07bceeu; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c07bcf0;
P_0c07bcf0: /* original 54f1, guest PC 0x0c07bcf0 */
if(!s->budget--) { s->failed_pc=0x0c07bcf0u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07bcf2;
P_0c07bcf2: /* original 1f41, guest PC 0x0c07bcf2 */
if(!s->budget--) { s->failed_pc=0x0c07bcf2u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c07bcf4;
P_0c07bcf4: /* original 1f54, guest PC 0x0c07bcf4 */
if(!s->budget--) { s->failed_pc=0x0c07bcf4u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c07bcf6;
P_0c07bcf6: /* original a172, guest PC 0x0c07bcf6 */
if(!s->budget--) { s->failed_pc=0x0c07bcf6u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c07bfde;
P_0c07bcf8: /* original 1f41, guest PC 0x0c07bcf8 */
if(!s->budget--) { s->failed_pc=0x0c07bcf8u; return 0; }
write(ram,r[15]+4,r[4],4);
return vf3_matrix_family(0x0c07bcfau,s,ram);
P_0c07bd14: /* original 63c3, guest PC 0x0c07bd14 */
if(!s->budget--) { s->failed_pc=0x0c07bd14u; return 0; }
r[3]=r[12];
goto P_0c07bd16;
P_0c07bd16: /* original 4308, guest PC 0x0c07bd16 */
if(!s->budget--) { s->failed_pc=0x0c07bd16u; return 0; }
r[3]<<=2;
goto P_0c07bd18;
P_0c07bd18: /* original 62c3, guest PC 0x0c07bd18 */
if(!s->budget--) { s->failed_pc=0x0c07bd18u; return 0; }
r[2]=r[12];
goto P_0c07bd1a;
P_0c07bd1a: /* original 332c, guest PC 0x0c07bd1a */
if(!s->budget--) { s->failed_pc=0x0c07bd1au; return 0; }
r[3]+=r[2];
goto P_0c07bd1c;
P_0c07bd1c: /* original 64c3, guest PC 0x0c07bd1c */
if(!s->budget--) { s->failed_pc=0x0c07bd1cu; return 0; }
r[4]=r[12];
goto P_0c07bd1e;
P_0c07bd1e: /* original 61f3, guest PC 0x0c07bd1e */
if(!s->budget--) { s->failed_pc=0x0c07bd1eu; return 0; }
r[1]=r[15];
goto P_0c07bd20;
P_0c07bd20: /* original 4308, guest PC 0x0c07bd20 */
if(!s->budget--) { s->failed_pc=0x0c07bd20u; return 0; }
r[3]<<=2;
goto P_0c07bd22;
P_0c07bd22: /* original 4408, guest PC 0x0c07bd22 */
if(!s->budget--) { s->failed_pc=0x0c07bd22u; return 0; }
r[4]<<=2;
goto P_0c07bd24;
P_0c07bd24: /* original 717c, guest PC 0x0c07bd24 */
if(!s->budget--) { s->failed_pc=0x0c07bd24u; return 0; }
r[1]+=0x0000007cu;
goto P_0c07bd26;
P_0c07bd26: /* original 314c, guest PC 0x0c07bd26 */
if(!s->budget--) { s->failed_pc=0x0c07bd26u; return 0; }
r[1]+=r[4];
goto P_0c07bd28;
P_0c07bd28: /* original 4300, guest PC 0x0c07bd28 */
if(!s->budget--) { s->failed_pc=0x0c07bd28u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07bd2a;
P_0c07bd2a: /* original 730f, guest PC 0x0c07bd2a */
if(!s->budget--) { s->failed_pc=0x0c07bd2au; return 0; }
r[3]+=0x0000000fu;
goto P_0c07bd2c;
P_0c07bd2c: /* original 4300, guest PC 0x0c07bd2c */
if(!s->budget--) { s->failed_pc=0x0c07bd2cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07bd2e;
P_0c07bd2e: /* original 1f33, guest PC 0x0c07bd2e */
if(!s->budget--) { s->failed_pc=0x0c07bd2eu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c07bd30;
P_0c07bd30: /* original 52ff, guest PC 0x0c07bd30 */
if(!s->budget--) { s->failed_pc=0x0c07bd30u; return 0; }
r[2]=read(ram,r[15]+60,4);
goto P_0c07bd32;
P_0c07bd32: /* original 6112, guest PC 0x0c07bd32 */
if(!s->budget--) { s->failed_pc=0x0c07bd32u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07bd34;
P_0c07bd34: /* original 324c, guest PC 0x0c07bd34 */
if(!s->budget--) { s->failed_pc=0x0c07bd34u; return 0; }
r[2]+=r[4];
goto P_0c07bd36;
P_0c07bd36: /* original 5222, guest PC 0x0c07bd36 */
if(!s->budget--) { s->failed_pc=0x0c07bd36u; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c07bd38;
P_0c07bd38: /* original 3210, guest PC 0x0c07bd38 */
if(!s->budget--) { s->failed_pc=0x0c07bd38u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c07bd3a;
P_0c07bd3a: /* original 8b01, guest PC 0x0c07bd3a */
if(!s->budget--) { s->failed_pc=0x0c07bd3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bd40; }
goto P_0c07bd3c;
P_0c07bd3c: /* original a0a0, guest PC 0x0c07bd3c */
if(!s->budget--) { s->failed_pc=0x0c07bd3cu; return 0; }
goto P_0c07be80;
P_0c07bd3e: /* original 0009, guest PC 0x0c07bd3e */
if(!s->budget--) { s->failed_pc=0x0c07bd3eu; return 0; }
goto P_0c07bd40;
P_0c07bd40: /* original 50f8, guest PC 0x0c07bd40 */
if(!s->budget--) { s->failed_pc=0x0c07bd40u; return 0; }
r[0]=read(ram,r[15]+32,4);
goto P_0c07bd42;
P_0c07bd42: /* original 8801, guest PC 0x0c07bd42 */
if(!s->budget--) { s->failed_pc=0x0c07bd42u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07bd44;
P_0c07bd44: /* original 8901, guest PC 0x0c07bd44 */
if(!s->budget--) { s->failed_pc=0x0c07bd44u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07bd4a; }
goto P_0c07bd46;
P_0c07bd46: /* original a09b, guest PC 0x0c07bd46 */
if(!s->budget--) { s->failed_pc=0x0c07bd46u; return 0; }
goto P_0c07be80;
P_0c07bd48: /* original 0009, guest PC 0x0c07bd48 */
if(!s->budget--) { s->failed_pc=0x0c07bd48u; return 0; }
goto P_0c07bd4a;
P_0c07bd4a: /* original 62f3, guest PC 0x0c07bd4a */
if(!s->budget--) { s->failed_pc=0x0c07bd4au; return 0; }
r[2]=r[15];
goto P_0c07bd4c;
P_0c07bd4c: /* original 63c3, guest PC 0x0c07bd4c */
if(!s->budget--) { s->failed_pc=0x0c07bd4cu; return 0; }
r[3]=r[12];
goto P_0c07bd4e;
P_0c07bd4e: /* original 727c, guest PC 0x0c07bd4e */
if(!s->budget--) { s->failed_pc=0x0c07bd4eu; return 0; }
r[2]+=0x0000007cu;
goto P_0c07bd50;
P_0c07bd50: /* original 4308, guest PC 0x0c07bd50 */
if(!s->budget--) { s->failed_pc=0x0c07bd50u; return 0; }
r[3]<<=2;
goto P_0c07bd52;
P_0c07bd52: /* original 332c, guest PC 0x0c07bd52 */
if(!s->budget--) { s->failed_pc=0x0c07bd52u; return 0; }
r[3]+=r[2];
goto P_0c07bd54;
P_0c07bd54: /* original 6132, guest PC 0x0c07bd54 */
if(!s->budget--) { s->failed_pc=0x0c07bd54u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c07bd56;
P_0c07bd56: /* original 31a3, guest PC 0x0c07bd56 */
if(!s->budget--) { s->failed_pc=0x0c07bd56u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[10])!=0);
goto P_0c07bd58;
P_0c07bd58: /* original 8b3f, guest PC 0x0c07bd58 */
if(!s->budget--) { s->failed_pc=0x0c07bd58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bdda; }
goto P_0c07bd5a;
P_0c07bd5a: /* original 60c3, guest PC 0x0c07bd5a */
if(!s->budget--) { s->failed_pc=0x0c07bd5au; return 0; }
r[0]=r[12];
goto P_0c07bd5c;
P_0c07bd5c: /* original 63f3, guest PC 0x0c07bd5c */
if(!s->budget--) { s->failed_pc=0x0c07bd5cu; return 0; }
r[3]=r[15];
goto P_0c07bd5e;
P_0c07bd5e: /* original 4008, guest PC 0x0c07bd5e */
if(!s->budget--) { s->failed_pc=0x0c07bd5eu; return 0; }
r[0]<<=2;
goto P_0c07bd60;
P_0c07bd60: /* original 7374, guest PC 0x0c07bd60 */
if(!s->budget--) { s->failed_pc=0x0c07bd60u; return 0; }
r[3]+=0x00000074u;
goto P_0c07bd62;
P_0c07bd62: /* original 1f06, guest PC 0x0c07bd62 */
if(!s->budget--) { s->failed_pc=0x0c07bd62u; return 0; }
write(ram,r[15]+24,r[0],4);
goto P_0c07bd64;
P_0c07bd64: /* original 303c, guest PC 0x0c07bd64 */
if(!s->budget--) { s->failed_pc=0x0c07bd64u; return 0; }
r[0]+=r[3];
goto P_0c07bd66;
P_0c07bd66: /* original 1f05, guest PC 0x0c07bd66 */
if(!s->budget--) { s->failed_pc=0x0c07bd66u; return 0; }
write(ram,r[15]+20,r[0],4);
goto P_0c07bd68;
P_0c07bd68: /* original 2f06, guest PC 0x0c07bd68 */
if(!s->budget--) { s->failed_pc=0x0c07bd68u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bd6a;
P_0c07bd6a: /* original 9297, guest PC 0x0c07bd6a */
if(!s->budget--) { s->failed_pc=0x0c07bd6au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07be9cu,2);
goto P_0c07bd6c;
P_0c07bd6c: /* original 51f7, guest PC 0x0c07bd6c */
if(!s->budget--) { s->failed_pc=0x0c07bd6cu; return 0; }
r[1]=read(ram,r[15]+28,4);
goto P_0c07bd6e;
P_0c07bd6e: /* original 32fc, guest PC 0x0c07bd6e */
if(!s->budget--) { s->failed_pc=0x0c07bd6eu; return 0; }
r[2]+=r[15];
goto P_0c07bd70;
P_0c07bd70: /* original 312c, guest PC 0x0c07bd70 */
if(!s->budget--) { s->failed_pc=0x0c07bd70u; return 0; }
r[1]+=r[2];
goto P_0c07bd72;
P_0c07bd72: /* original 1f1f, guest PC 0x0c07bd72 */
if(!s->budget--) { s->failed_pc=0x0c07bd72u; return 0; }
write(ram,r[15]+60,r[1],4);
goto P_0c07bd74;
P_0c07bd74: /* original d34c, guest PC 0x0c07bd74 */
if(!s->budget--) { s->failed_pc=0x0c07bd74u; return 0; }
r[3]=read(ram,0x0c07bea8u,4);
goto P_0c07bd76;
P_0c07bd76: /* original 6112, guest PC 0x0c07bd76 */
if(!s->budget--) { s->failed_pc=0x0c07bd76u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07bd78;
P_0c07bd78: /* original 430b, guest PC 0x0c07bd78 */
if(!s->budget--) { s->failed_pc=0x0c07bd78u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bd7cu;
r[0]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bd7cu) { target=s->pc; goto dispatch; }
goto P_0c07bd7c;
P_0c07bd7a: /* original 60a3, guest PC 0x0c07bd7a */
if(!s->budget--) { s->failed_pc=0x0c07bd7au; return 0; }
r[0]=r[10];
goto P_0c07bd7c;
P_0c07bd7c: /* original 64c3, guest PC 0x0c07bd7c */
if(!s->budget--) { s->failed_pc=0x0c07bd7cu; return 0; }
r[4]=r[12];
goto P_0c07bd7e;
P_0c07bd7e: /* original 61f6, guest PC 0x0c07bd7e */
if(!s->budget--) { s->failed_pc=0x0c07bd7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c07bd80;
P_0c07bd80: /* original 4408, guest PC 0x0c07bd80 */
if(!s->budget--) { s->failed_pc=0x0c07bd80u; return 0; }
r[4]<<=2;
goto P_0c07bd82;
P_0c07bd82: /* original 63c3, guest PC 0x0c07bd82 */
if(!s->budget--) { s->failed_pc=0x0c07bd82u; return 0; }
r[3]=r[12];
goto P_0c07bd84;
P_0c07bd84: /* original 343c, guest PC 0x0c07bd84 */
if(!s->budget--) { s->failed_pc=0x0c07bd84u; return 0; }
r[4]+=r[3];
goto P_0c07bd86;
P_0c07bd86: /* original 2102, guest PC 0x0c07bd86 */
if(!s->budget--) { s->failed_pc=0x0c07bd86u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c07bd88;
P_0c07bd88: /* original 4408, guest PC 0x0c07bd88 */
if(!s->budget--) { s->failed_pc=0x0c07bd88u; return 0; }
r[4]<<=2;
goto P_0c07bd8a;
P_0c07bd8a: /* original 9188, guest PC 0x0c07bd8a */
if(!s->budget--) { s->failed_pc=0x0c07bd8au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07be9eu,2);
goto P_0c07bd8c;
P_0c07bd8c: /* original 2fe6, guest PC 0x0c07bd8c */
if(!s->budget--) { s->failed_pc=0x0c07bd8cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bd8e;
P_0c07bd8e: /* original 4400, guest PC 0x0c07bd8e */
if(!s->budget--) { s->failed_pc=0x0c07bd8eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07bd90;
P_0c07bd90: /* original 50f6, guest PC 0x0c07bd90 */
if(!s->budget--) { s->failed_pc=0x0c07bd90u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c07bd92;
P_0c07bd92: /* original 740d, guest PC 0x0c07bd92 */
if(!s->budget--) { s->failed_pc=0x0c07bd92u; return 0; }
r[4]+=0x0000000du;
goto P_0c07bd94;
P_0c07bd94: /* original d345, guest PC 0x0c07bd94 */
if(!s->budget--) { s->failed_pc=0x0c07bd94u; return 0; }
r[3]=read(ram,0x0c07beacu,4);
goto P_0c07bd96;
P_0c07bd96: /* original 4400, guest PC 0x0c07bd96 */
if(!s->budget--) { s->failed_pc=0x0c07bd96u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07bd98;
P_0c07bd98: /* original 6002, guest PC 0x0c07bd98 */
if(!s->budget--) { s->failed_pc=0x0c07bd98u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07bd9a;
P_0c07bd9a: /* original 241b, guest PC 0x0c07bd9a */
if(!s->budget--) { s->failed_pc=0x0c07bd9au; return 0; }
r[4]|=r[1];
goto P_0c07bd9c;
P_0c07bd9c: /* original 66d3, guest PC 0x0c07bd9c */
if(!s->budget--) { s->failed_pc=0x0c07bd9cu; return 0; }
r[6]=r[13];
goto P_0c07bd9e;
P_0c07bd9e: /* original e700, guest PC 0x0c07bd9e */
if(!s->budget--) { s->failed_pc=0x0c07bd9eu; return 0; }
r[7]=0x00000000u;
goto P_0c07bda0;
P_0c07bda0: /* original 4008, guest PC 0x0c07bda0 */
if(!s->budget--) { s->failed_pc=0x0c07bda0u; return 0; }
r[0]<<=2;
goto P_0c07bda2;
P_0c07bda2: /* original 430b, guest PC 0x0c07bda2 */
if(!s->budget--) { s->failed_pc=0x0c07bda2u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bda6u;
r[5]=read(ram,r[9]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bda6u) { target=s->pc; goto dispatch; }
goto P_0c07bda6;
P_0c07bda4: /* original 059e, guest PC 0x0c07bda4 */
if(!s->budget--) { s->failed_pc=0x0c07bda4u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bda6;
P_0c07bda6: /* original 7f04, guest PC 0x0c07bda6 */
if(!s->budget--) { s->failed_pc=0x0c07bda6u; return 0; }
r[15]+=0x00000004u;
goto P_0c07bda8;
P_0c07bda8: /* original 53f5, guest PC 0x0c07bda8 */
if(!s->budget--) { s->failed_pc=0x0c07bda8u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c07bdaa;
P_0c07bdaa: /* original 52fe, guest PC 0x0c07bdaa */
if(!s->budget--) { s->failed_pc=0x0c07bdaau; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c07bdac;
P_0c07bdac: /* original 6132, guest PC 0x0c07bdac */
if(!s->budget--) { s->failed_pc=0x0c07bdacu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c07bdae;
P_0c07bdae: /* original 6322, guest PC 0x0c07bdae */
if(!s->budget--) { s->failed_pc=0x0c07bdaeu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c07bdb0;
P_0c07bdb0: /* original 01a7, guest PC 0x0c07bdb0 */
if(!s->budget--) { s->failed_pc=0x0c07bdb0u; return 0; }
r[19]=r[1]*r[10];
goto P_0c07bdb2;
P_0c07bdb2: /* original 011a, guest PC 0x0c07bdb2 */
if(!s->budget--) { s->failed_pc=0x0c07bdb2u; return 0; }
r[1]=r[19];
goto P_0c07bdb4;
P_0c07bdb4: /* original 3318, guest PC 0x0c07bdb4 */
if(!s->budget--) { s->failed_pc=0x0c07bdb4u; return 0; }
r[3]-=r[1];
goto P_0c07bdb6;
P_0c07bdb6: /* original 2232, guest PC 0x0c07bdb6 */
if(!s->budget--) { s->failed_pc=0x0c07bdb6u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c07bdb8;
P_0c07bdb8: /* original e10a, guest PC 0x0c07bdb8 */
if(!s->budget--) { s->failed_pc=0x0c07bdb8u; return 0; }
r[1]=0x0000000au;
goto P_0c07bdba;
P_0c07bdba: /* original 50f4, guest PC 0x0c07bdba */
if(!s->budget--) { s->failed_pc=0x0c07bdbau; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c07bdbc;
P_0c07bdbc: /* original 52f6, guest PC 0x0c07bdbc */
if(!s->budget--) { s->failed_pc=0x0c07bdbcu; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c07bdbe;
P_0c07bdbe: /* original 032e, guest PC 0x0c07bdbe */
if(!s->budget--) { s->failed_pc=0x0c07bdbeu; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c07bdc0;
P_0c07bdc0: /* original 3313, guest PC 0x0c07bdc0 */
if(!s->budget--) { s->failed_pc=0x0c07bdc0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[1])!=0);
goto P_0c07bdc2;
P_0c07bdc2: /* original 890a, guest PC 0x0c07bdc2 */
if(!s->budget--) { s->failed_pc=0x0c07bdc2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07bdda; }
goto P_0c07bdc4;
P_0c07bdc4: /* original 54f3, guest PC 0x0c07bdc4 */
if(!s->budget--) { s->failed_pc=0x0c07bdc4u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c07bdc6;
P_0c07bdc6: /* original 66d3, guest PC 0x0c07bdc6 */
if(!s->budget--) { s->failed_pc=0x0c07bdc6u; return 0; }
r[6]=r[13];
goto P_0c07bdc8;
P_0c07bdc8: /* original 53f1, guest PC 0x0c07bdc8 */
if(!s->budget--) { s->failed_pc=0x0c07bdc8u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07bdca;
P_0c07bdca: /* original e700, guest PC 0x0c07bdca */
if(!s->budget--) { s->failed_pc=0x0c07bdcau; return 0; }
r[7]=0x00000000u;
goto P_0c07bdcc;
P_0c07bdcc: /* original 2fe6, guest PC 0x0c07bdcc */
if(!s->budget--) { s->failed_pc=0x0c07bdccu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bdce;
P_0c07bdce: /* original 55fb, guest PC 0x0c07bdce */
if(!s->budget--) { s->failed_pc=0x0c07bdceu; return 0; }
r[5]=read(ram,r[15]+44,4);
goto P_0c07bdd0;
P_0c07bdd0: /* original 243b, guest PC 0x0c07bdd0 */
if(!s->budget--) { s->failed_pc=0x0c07bdd0u; return 0; }
r[4]|=r[3];
goto P_0c07bdd2;
P_0c07bdd2: /* original d236, guest PC 0x0c07bdd2 */
if(!s->budget--) { s->failed_pc=0x0c07bdd2u; return 0; }
r[2]=read(ram,0x0c07beacu,4);
goto P_0c07bdd4;
P_0c07bdd4: /* original 420b, guest PC 0x0c07bdd4 */
if(!s->budget--) { s->failed_pc=0x0c07bdd4u; return 0; }
target=r[2];
r[16]=code_base|0x0c07bdd8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bdd8u) { target=s->pc; goto dispatch; }
goto P_0c07bdd8;
P_0c07bdd6: /* original 6552, guest PC 0x0c07bdd6 */
if(!s->budget--) { s->failed_pc=0x0c07bdd6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c07bdd8;
P_0c07bdd8: /* original 7f04, guest PC 0x0c07bdd8 */
if(!s->budget--) { s->failed_pc=0x0c07bdd8u; return 0; }
r[15]+=0x00000004u;
goto P_0c07bdda;
P_0c07bdda: /* original 62f3, guest PC 0x0c07bdda */
if(!s->budget--) { s->failed_pc=0x0c07bddau; return 0; }
r[2]=r[15];
goto P_0c07bddc;
P_0c07bddc: /* original 63c3, guest PC 0x0c07bddc */
if(!s->budget--) { s->failed_pc=0x0c07bddcu; return 0; }
r[3]=r[12];
goto P_0c07bdde;
P_0c07bdde: /* original 727c, guest PC 0x0c07bdde */
if(!s->budget--) { s->failed_pc=0x0c07bddeu; return 0; }
r[2]+=0x0000007cu;
goto P_0c07bde0;
P_0c07bde0: /* original 4308, guest PC 0x0c07bde0 */
if(!s->budget--) { s->failed_pc=0x0c07bde0u; return 0; }
r[3]<<=2;
goto P_0c07bde2;
P_0c07bde2: /* original 332c, guest PC 0x0c07bde2 */
if(!s->budget--) { s->failed_pc=0x0c07bde2u; return 0; }
r[3]+=r[2];
goto P_0c07bde4;
P_0c07bde4: /* original 6032, guest PC 0x0c07bde4 */
if(!s->budget--) { s->failed_pc=0x0c07bde4u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07bde6;
P_0c07bde6: /* original e10a, guest PC 0x0c07bde6 */
if(!s->budget--) { s->failed_pc=0x0c07bde6u; return 0; }
r[1]=0x0000000au;
goto P_0c07bde8;
P_0c07bde8: /* original 3013, guest PC 0x0c07bde8 */
if(!s->budget--) { s->failed_pc=0x0c07bde8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[1])!=0);
goto P_0c07bdea;
P_0c07bdea: /* original 8b26, guest PC 0x0c07bdea */
if(!s->budget--) { s->failed_pc=0x0c07bdeau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07be3a; }
goto P_0c07bdec;
P_0c07bdec: /* original 61f3, guest PC 0x0c07bdec */
if(!s->budget--) { s->failed_pc=0x0c07bdecu; return 0; }
r[1]=r[15];
goto P_0c07bdee;
P_0c07bdee: /* original 64c3, guest PC 0x0c07bdee */
if(!s->budget--) { s->failed_pc=0x0c07bdeeu; return 0; }
r[4]=r[12];
goto P_0c07bdf0;
P_0c07bdf0: /* original 717c, guest PC 0x0c07bdf0 */
if(!s->budget--) { s->failed_pc=0x0c07bdf0u; return 0; }
r[1]+=0x0000007cu;
goto P_0c07bdf2;
P_0c07bdf2: /* original 60f3, guest PC 0x0c07bdf2 */
if(!s->budget--) { s->failed_pc=0x0c07bdf2u; return 0; }
r[0]=r[15];
goto P_0c07bdf4;
P_0c07bdf4: /* original 4408, guest PC 0x0c07bdf4 */
if(!s->budget--) { s->failed_pc=0x0c07bdf4u; return 0; }
r[4]<<=2;
goto P_0c07bdf6;
P_0c07bdf6: /* original 314c, guest PC 0x0c07bdf6 */
if(!s->budget--) { s->failed_pc=0x0c07bdf6u; return 0; }
r[1]+=r[4];
goto P_0c07bdf8;
P_0c07bdf8: /* original 7074, guest PC 0x0c07bdf8 */
if(!s->budget--) { s->failed_pc=0x0c07bdf8u; return 0; }
r[0]+=0x00000074u;
goto P_0c07bdfa;
P_0c07bdfa: /* original 304c, guest PC 0x0c07bdfa */
if(!s->budget--) { s->failed_pc=0x0c07bdfau; return 0; }
r[0]+=r[4];
goto P_0c07bdfc;
P_0c07bdfc: /* original 1f05, guest PC 0x0c07bdfc */
if(!s->budget--) { s->failed_pc=0x0c07bdfcu; return 0; }
write(ram,r[15]+20,r[0],4);
goto P_0c07bdfe;
P_0c07bdfe: /* original 6203, guest PC 0x0c07bdfe */
if(!s->budget--) { s->failed_pc=0x0c07bdfeu; return 0; }
r[2]=r[0];
goto P_0c07be00;
P_0c07be00: /* original 1f16, guest PC 0x0c07be00 */
if(!s->budget--) { s->failed_pc=0x0c07be00u; return 0; }
write(ram,r[15]+24,r[1],4);
goto P_0c07be02;
P_0c07be02: /* original d329, guest PC 0x0c07be02 */
if(!s->budget--) { s->failed_pc=0x0c07be02u; return 0; }
r[3]=read(ram,0x0c07bea8u,4);
goto P_0c07be04;
P_0c07be04: /* original 6112, guest PC 0x0c07be04 */
if(!s->budget--) { s->failed_pc=0x0c07be04u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07be06;
P_0c07be06: /* original 430b, guest PC 0x0c07be06 */
if(!s->budget--) { s->failed_pc=0x0c07be06u; return 0; }
target=r[3];
r[16]=code_base|0x0c07be0au;
r[0]=0x0000000au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07be0au) { target=s->pc; goto dispatch; }
goto P_0c07be0a;
P_0c07be08: /* original e00a, guest PC 0x0c07be08 */
if(!s->budget--) { s->failed_pc=0x0c07be08u; return 0; }
r[0]=0x0000000au;
goto P_0c07be0a;
P_0c07be0a: /* original 2202, guest PC 0x0c07be0a */
if(!s->budget--) { s->failed_pc=0x0c07be0au; return 0; }
write(ram,r[2],r[0],4);
goto P_0c07be0c;
P_0c07be0c: /* original e700, guest PC 0x0c07be0c */
if(!s->budget--) { s->failed_pc=0x0c07be0cu; return 0; }
r[7]=0x00000000u;
goto P_0c07be0e;
P_0c07be0e: /* original 54f3, guest PC 0x0c07be0e */
if(!s->budget--) { s->failed_pc=0x0c07be0eu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c07be10;
P_0c07be10: /* original 66d3, guest PC 0x0c07be10 */
if(!s->budget--) { s->failed_pc=0x0c07be10u; return 0; }
r[6]=r[13];
goto P_0c07be12;
P_0c07be12: /* original 9344, guest PC 0x0c07be12 */
if(!s->budget--) { s->failed_pc=0x0c07be12u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07be9eu,2);
goto P_0c07be14;
P_0c07be14: /* original 2fe6, guest PC 0x0c07be14 */
if(!s->budget--) { s->failed_pc=0x0c07be14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07be16;
P_0c07be16: /* original 50f6, guest PC 0x0c07be16 */
if(!s->budget--) { s->failed_pc=0x0c07be16u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c07be18;
P_0c07be18: /* original 243b, guest PC 0x0c07be18 */
if(!s->budget--) { s->failed_pc=0x0c07be18u; return 0; }
r[4]|=r[3];
goto P_0c07be1a;
P_0c07be1a: /* original d224, guest PC 0x0c07be1a */
if(!s->budget--) { s->failed_pc=0x0c07be1au; return 0; }
r[2]=read(ram,0x0c07beacu,4);
goto P_0c07be1c;
P_0c07be1c: /* original 6002, guest PC 0x0c07be1c */
if(!s->budget--) { s->failed_pc=0x0c07be1cu; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07be1e;
P_0c07be1e: /* original 4008, guest PC 0x0c07be1e */
if(!s->budget--) { s->failed_pc=0x0c07be1eu; return 0; }
r[0]<<=2;
goto P_0c07be20;
P_0c07be20: /* original 420b, guest PC 0x0c07be20 */
if(!s->budget--) { s->failed_pc=0x0c07be20u; return 0; }
target=r[2];
r[16]=code_base|0x0c07be24u;
r[5]=read(ram,r[9]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07be24u) { target=s->pc; goto dispatch; }
goto P_0c07be24;
P_0c07be22: /* original 059e, guest PC 0x0c07be22 */
if(!s->budget--) { s->failed_pc=0x0c07be22u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07be24;
P_0c07be24: /* original 7f04, guest PC 0x0c07be24 */
if(!s->budget--) { s->failed_pc=0x0c07be24u; return 0; }
r[15]+=0x00000004u;
goto P_0c07be26;
P_0c07be26: /* original 52f5, guest PC 0x0c07be26 */
if(!s->budget--) { s->failed_pc=0x0c07be26u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c07be28;
P_0c07be28: /* original 53f6, guest PC 0x0c07be28 */
if(!s->budget--) { s->failed_pc=0x0c07be28u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c07be2a;
P_0c07be2a: /* original 6222, guest PC 0x0c07be2a */
if(!s->budget--) { s->failed_pc=0x0c07be2au; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c07be2c;
P_0c07be2c: /* original 6032, guest PC 0x0c07be2c */
if(!s->budget--) { s->failed_pc=0x0c07be2cu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07be2e;
P_0c07be2e: /* original 6123, guest PC 0x0c07be2e */
if(!s->budget--) { s->failed_pc=0x0c07be2eu; return 0; }
r[1]=r[2];
goto P_0c07be30;
P_0c07be30: /* original 4208, guest PC 0x0c07be30 */
if(!s->budget--) { s->failed_pc=0x0c07be30u; return 0; }
r[2]<<=2;
goto P_0c07be32;
P_0c07be32: /* original 321c, guest PC 0x0c07be32 */
if(!s->budget--) { s->failed_pc=0x0c07be32u; return 0; }
r[2]+=r[1];
goto P_0c07be34;
P_0c07be34: /* original 4200, guest PC 0x0c07be34 */
if(!s->budget--) { s->failed_pc=0x0c07be34u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07be36;
P_0c07be36: /* original 3028, guest PC 0x0c07be36 */
if(!s->budget--) { s->failed_pc=0x0c07be36u; return 0; }
r[0]-=r[2];
goto P_0c07be38;
P_0c07be38: /* original 2302, guest PC 0x0c07be38 */
if(!s->budget--) { s->failed_pc=0x0c07be38u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07be3a;
P_0c07be3a: /* original 64c3, guest PC 0x0c07be3a */
if(!s->budget--) { s->failed_pc=0x0c07be3au; return 0; }
r[4]=r[12];
goto P_0c07be3c;
P_0c07be3c: /* original 4408, guest PC 0x0c07be3c */
if(!s->budget--) { s->failed_pc=0x0c07be3cu; return 0; }
r[4]<<=2;
goto P_0c07be3e;
P_0c07be3e: /* original 63c3, guest PC 0x0c07be3e */
if(!s->budget--) { s->failed_pc=0x0c07be3eu; return 0; }
r[3]=r[12];
goto P_0c07be40;
P_0c07be40: /* original 343c, guest PC 0x0c07be40 */
if(!s->budget--) { s->failed_pc=0x0c07be40u; return 0; }
r[4]+=r[3];
goto P_0c07be42;
P_0c07be42: /* original 60c3, guest PC 0x0c07be42 */
if(!s->budget--) { s->failed_pc=0x0c07be42u; return 0; }
r[0]=r[12];
goto P_0c07be44;
P_0c07be44: /* original 4408, guest PC 0x0c07be44 */
if(!s->budget--) { s->failed_pc=0x0c07be44u; return 0; }
r[4]<<=2;
goto P_0c07be46;
P_0c07be46: /* original 4008, guest PC 0x0c07be46 */
if(!s->budget--) { s->failed_pc=0x0c07be46u; return 0; }
r[0]<<=2;
goto P_0c07be48;
P_0c07be48: /* original 9229, guest PC 0x0c07be48 */
if(!s->budget--) { s->failed_pc=0x0c07be48u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07be9eu,2);
goto P_0c07be4a;
P_0c07be4a: /* original 2fe6, guest PC 0x0c07be4a */
if(!s->budget--) { s->failed_pc=0x0c07be4au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07be4c;
P_0c07be4c: /* original 4400, guest PC 0x0c07be4c */
if(!s->budget--) { s->failed_pc=0x0c07be4cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07be4e;
P_0c07be4e: /* original 9325, guest PC 0x0c07be4e */
if(!s->budget--) { s->failed_pc=0x0c07be4eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07be9cu,2);
goto P_0c07be50;
P_0c07be50: /* original 7411, guest PC 0x0c07be50 */
if(!s->budget--) { s->failed_pc=0x0c07be50u; return 0; }
r[4]+=0x00000011u;
goto P_0c07be52;
P_0c07be52: /* original 4400, guest PC 0x0c07be52 */
if(!s->budget--) { s->failed_pc=0x0c07be52u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07be54;
P_0c07be54: /* original d115, guest PC 0x0c07be54 */
if(!s->budget--) { s->failed_pc=0x0c07be54u; return 0; }
r[1]=read(ram,0x0c07beacu,4);
goto P_0c07be56;
P_0c07be56: /* original 33fc, guest PC 0x0c07be56 */
if(!s->budget--) { s->failed_pc=0x0c07be56u; return 0; }
r[3]+=r[15];
goto P_0c07be58;
P_0c07be58: /* original 66d3, guest PC 0x0c07be58 */
if(!s->budget--) { s->failed_pc=0x0c07be58u; return 0; }
r[6]=r[13];
goto P_0c07be5a;
P_0c07be5a: /* original 003e, guest PC 0x0c07be5a */
if(!s->budget--) { s->failed_pc=0x0c07be5au; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c07be5c;
P_0c07be5c: /* original 242b, guest PC 0x0c07be5c */
if(!s->budget--) { s->failed_pc=0x0c07be5cu; return 0; }
r[4]|=r[2];
goto P_0c07be5e;
P_0c07be5e: /* original e700, guest PC 0x0c07be5e */
if(!s->budget--) { s->failed_pc=0x0c07be5eu; return 0; }
r[7]=0x00000000u;
goto P_0c07be60;
P_0c07be60: /* original 4008, guest PC 0x0c07be60 */
if(!s->budget--) { s->failed_pc=0x0c07be60u; return 0; }
r[0]<<=2;
goto P_0c07be62;
P_0c07be62: /* original 410b, guest PC 0x0c07be62 */
if(!s->budget--) { s->failed_pc=0x0c07be62u; return 0; }
target=r[1];
r[16]=code_base|0x0c07be66u;
r[5]=read(ram,r[9]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07be66u) { target=s->pc; goto dispatch; }
goto P_0c07be66;
P_0c07be64: /* original 059e, guest PC 0x0c07be64 */
if(!s->budget--) { s->failed_pc=0x0c07be64u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07be66;
P_0c07be66: /* original 7f04, guest PC 0x0c07be66 */
if(!s->budget--) { s->failed_pc=0x0c07be66u; return 0; }
r[15]+=0x00000004u;
goto P_0c07be68;
P_0c07be68: /* original 931a, guest PC 0x0c07be68 */
if(!s->budget--) { s->failed_pc=0x0c07be68u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bea0u,2);
goto P_0c07be6a;
P_0c07be6a: /* original 60f2, guest PC 0x0c07be6a */
if(!s->budget--) { s->failed_pc=0x0c07be6au; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c07be6c;
P_0c07be6c: /* original 64c3, guest PC 0x0c07be6c */
if(!s->budget--) { s->failed_pc=0x0c07be6cu; return 0; }
r[4]=r[12];
goto P_0c07be6e;
P_0c07be6e: /* original 9218, guest PC 0x0c07be6e */
if(!s->budget--) { s->failed_pc=0x0c07be6eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bea2u,2);
goto P_0c07be70;
P_0c07be70: /* original 4400, guest PC 0x0c07be70 */
if(!s->budget--) { s->failed_pc=0x0c07be70u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07be72;
P_0c07be72: /* original 330c, guest PC 0x0c07be72 */
if(!s->budget--) { s->failed_pc=0x0c07be72u; return 0; }
r[3]+=r[0];
goto P_0c07be74;
P_0c07be74: /* original 60f2, guest PC 0x0c07be74 */
if(!s->budget--) { s->failed_pc=0x0c07be74u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c07be76;
P_0c07be76: /* original 334c, guest PC 0x0c07be76 */
if(!s->budget--) { s->failed_pc=0x0c07be76u; return 0; }
r[3]+=r[4];
goto P_0c07be78;
P_0c07be78: /* original 320c, guest PC 0x0c07be78 */
if(!s->budget--) { s->failed_pc=0x0c07be78u; return 0; }
r[2]+=r[0];
goto P_0c07be7a;
P_0c07be7a: /* original 324c, guest PC 0x0c07be7a */
if(!s->budget--) { s->failed_pc=0x0c07be7au; return 0; }
r[2]+=r[4];
goto P_0c07be7c;
P_0c07be7c: /* original 6121, guest PC 0x0c07be7c */
if(!s->budget--) { s->failed_pc=0x0c07be7cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[1]=tmp;
goto P_0c07be7e;
P_0c07be7e: /* original 2311, guest PC 0x0c07be7e */
if(!s->budget--) { s->failed_pc=0x0c07be7eu; return 0; }
write(ram,r[3],r[1],2);
goto P_0c07be80;
P_0c07be80: /* original 50f4, guest PC 0x0c07be80 */
if(!s->budget--) { s->failed_pc=0x0c07be80u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c07be82;
P_0c07be82: /* original 63c3, guest PC 0x0c07be82 */
if(!s->budget--) { s->failed_pc=0x0c07be82u; return 0; }
r[3]=r[12];
goto P_0c07be84;
P_0c07be84: /* original 4308, guest PC 0x0c07be84 */
if(!s->budget--) { s->failed_pc=0x0c07be84u; return 0; }
r[3]<<=2;
goto P_0c07be86;
P_0c07be86: /* original 033e, guest PC 0x0c07be86 */
if(!s->budget--) { s->failed_pc=0x0c07be86u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c07be88;
P_0c07be88: /* original 33a3, guest PC 0x0c07be88 */
if(!s->budget--) { s->failed_pc=0x0c07be88u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[10])!=0);
goto P_0c07be8a;
P_0c07be8a: /* original 8b54, guest PC 0x0c07be8a */
if(!s->budget--) { s->failed_pc=0x0c07be8au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bf36; }
goto P_0c07be8c;
P_0c07be8c: /* original 930a, guest PC 0x0c07be8c */
if(!s->budget--) { s->failed_pc=0x0c07be8cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bea4u,2);
goto P_0c07be8e;
P_0c07be8e: /* original 64c3, guest PC 0x0c07be8e */
if(!s->budget--) { s->failed_pc=0x0c07be8eu; return 0; }
r[4]=r[12];
goto P_0c07be90;
P_0c07be90: /* original 52f2, guest PC 0x0c07be90 */
if(!s->budget--) { s->failed_pc=0x0c07be90u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07be92;
P_0c07be92: /* original 4408, guest PC 0x0c07be92 */
if(!s->budget--) { s->failed_pc=0x0c07be92u; return 0; }
r[4]<<=2;
goto P_0c07be94;
P_0c07be94: /* original 33fc, guest PC 0x0c07be94 */
if(!s->budget--) { s->failed_pc=0x0c07be94u; return 0; }
r[3]+=r[15];
goto P_0c07be96;
P_0c07be96: /* original 323c, guest PC 0x0c07be96 */
if(!s->budget--) { s->failed_pc=0x0c07be96u; return 0; }
r[2]+=r[3];
goto P_0c07be98;
P_0c07be98: /* original a00a, guest PC 0x0c07be98 */
if(!s->budget--) { s->failed_pc=0x0c07be98u; return 0; }
goto P_0c07beb0;
P_0c07be9a: /* original 0009, guest PC 0x0c07be9a */
if(!s->budget--) { s->failed_pc=0x0c07be9au; return 0; }
return vf3_matrix_family(0x0c07be9cu,s,ram);
P_0c07beb0: /* original 324c, guest PC 0x0c07beb0 */
if(!s->budget--) { s->failed_pc=0x0c07beb0u; return 0; }
r[2]+=r[4];
goto P_0c07beb2;
P_0c07beb2: /* original 1f25, guest PC 0x0c07beb2 */
if(!s->budget--) { s->failed_pc=0x0c07beb2u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c07beb4;
P_0c07beb4: /* original 90c6, guest PC 0x0c07beb4 */
if(!s->budget--) { s->failed_pc=0x0c07beb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c044u,2);
goto P_0c07beb6;
P_0c07beb6: /* original 51f2, guest PC 0x0c07beb6 */
if(!s->budget--) { s->failed_pc=0x0c07beb6u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c07beb8;
P_0c07beb8: /* original 30fc, guest PC 0x0c07beb8 */
if(!s->budget--) { s->failed_pc=0x0c07beb8u; return 0; }
r[0]+=r[15];
goto P_0c07beba;
P_0c07beba: /* original 310c, guest PC 0x0c07beba */
if(!s->budget--) { s->failed_pc=0x0c07bebau; return 0; }
r[1]+=r[0];
goto P_0c07bebc;
P_0c07bebc: /* original 314c, guest PC 0x0c07bebc */
if(!s->budget--) { s->failed_pc=0x0c07bebcu; return 0; }
r[1]+=r[4];
goto P_0c07bebe;
P_0c07bebe: /* original 1f16, guest PC 0x0c07bebe */
if(!s->budget--) { s->failed_pc=0x0c07bebeu; return 0; }
write(ram,r[15]+24,r[1],4);
goto P_0c07bec0;
P_0c07bec0: /* original 6112, guest PC 0x0c07bec0 */
if(!s->budget--) { s->failed_pc=0x0c07bec0u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07bec2;
P_0c07bec2: /* original d365, guest PC 0x0c07bec2 */
if(!s->budget--) { s->failed_pc=0x0c07bec2u; return 0; }
r[3]=read(ram,0x0c07c058u,4);
goto P_0c07bec4;
P_0c07bec4: /* original 430b, guest PC 0x0c07bec4 */
if(!s->budget--) { s->failed_pc=0x0c07bec4u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bec8u;
r[0]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bec8u) { target=s->pc; goto dispatch; }
goto P_0c07bec8;
P_0c07bec6: /* original 60a3, guest PC 0x0c07bec6 */
if(!s->budget--) { s->failed_pc=0x0c07bec6u; return 0; }
r[0]=r[10];
goto P_0c07bec8;
P_0c07bec8: /* original 2202, guest PC 0x0c07bec8 */
if(!s->budget--) { s->failed_pc=0x0c07bec8u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c07beca;
P_0c07beca: /* original 62c3, guest PC 0x0c07beca */
if(!s->budget--) { s->failed_pc=0x0c07becau; return 0; }
r[2]=r[12];
goto P_0c07becc;
P_0c07becc: /* original 4208, guest PC 0x0c07becc */
if(!s->budget--) { s->failed_pc=0x0c07beccu; return 0; }
r[2]<<=2;
goto P_0c07bece;
P_0c07bece: /* original 63c3, guest PC 0x0c07bece */
if(!s->budget--) { s->failed_pc=0x0c07beceu; return 0; }
r[3]=r[12];
goto P_0c07bed0;
P_0c07bed0: /* original 323c, guest PC 0x0c07bed0 */
if(!s->budget--) { s->failed_pc=0x0c07bed0u; return 0; }
r[2]+=r[3];
goto P_0c07bed2;
P_0c07bed2: /* original 51f1, guest PC 0x0c07bed2 */
if(!s->budget--) { s->failed_pc=0x0c07bed2u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c07bed4;
P_0c07bed4: /* original 4208, guest PC 0x0c07bed4 */
if(!s->budget--) { s->failed_pc=0x0c07bed4u; return 0; }
r[2]<<=2;
goto P_0c07bed6;
P_0c07bed6: /* original 66d3, guest PC 0x0c07bed6 */
if(!s->budget--) { s->failed_pc=0x0c07bed6u; return 0; }
r[6]=r[13];
goto P_0c07bed8;
P_0c07bed8: /* original 4200, guest PC 0x0c07bed8 */
if(!s->budget--) { s->failed_pc=0x0c07bed8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07beda;
P_0c07beda: /* original 720d, guest PC 0x0c07beda */
if(!s->budget--) { s->failed_pc=0x0c07bedau; return 0; }
r[2]+=0x0000000du;
goto P_0c07bedc;
P_0c07bedc: /* original 4200, guest PC 0x0c07bedc */
if(!s->budget--) { s->failed_pc=0x0c07bedcu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07bede;
P_0c07bede: /* original 221b, guest PC 0x0c07bede */
if(!s->budget--) { s->failed_pc=0x0c07bedeu; return 0; }
r[2]|=r[1];
goto P_0c07bee0;
P_0c07bee0: /* original 1f2e, guest PC 0x0c07bee0 */
if(!s->budget--) { s->failed_pc=0x0c07bee0u; return 0; }
write(ram,r[15]+56,r[2],4);
goto P_0c07bee2;
P_0c07bee2: /* original e700, guest PC 0x0c07bee2 */
if(!s->budget--) { s->failed_pc=0x0c07bee2u; return 0; }
r[7]=0x00000000u;
goto P_0c07bee4;
P_0c07bee4: /* original 2fb6, guest PC 0x0c07bee4 */
if(!s->budget--) { s->failed_pc=0x0c07bee4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bee6;
P_0c07bee6: /* original 2fe6, guest PC 0x0c07bee6 */
if(!s->budget--) { s->failed_pc=0x0c07bee6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bee8;
P_0c07bee8: /* original 50f7, guest PC 0x0c07bee8 */
if(!s->budget--) { s->failed_pc=0x0c07bee8u; return 0; }
r[0]=read(ram,r[15]+28,4);
goto P_0c07beea;
P_0c07beea: /* original 6002, guest PC 0x0c07beea */
if(!s->budget--) { s->failed_pc=0x0c07beeau; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07beec;
P_0c07beec: /* original 4008, guest PC 0x0c07beec */
if(!s->budget--) { s->failed_pc=0x0c07beecu; return 0; }
r[0]<<=2;
goto P_0c07beee;
P_0c07beee: /* original 059e, guest PC 0x0c07beee */
if(!s->budget--) { s->failed_pc=0x0c07beeeu; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bef0;
P_0c07bef0: /* original 480b, guest PC 0x0c07bef0 */
if(!s->budget--) { s->failed_pc=0x0c07bef0u; return 0; }
target=r[8];
r[16]=code_base|0x0c07bef4u;
r[4]=r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bef4u) { target=s->pc; goto dispatch; }
goto P_0c07bef4;
P_0c07bef2: /* original 6423, guest PC 0x0c07bef2 */
if(!s->budget--) { s->failed_pc=0x0c07bef2u; return 0; }
r[4]=r[2];
goto P_0c07bef4;
P_0c07bef4: /* original 7f08, guest PC 0x0c07bef4 */
if(!s->budget--) { s->failed_pc=0x0c07bef4u; return 0; }
r[15]+=0x00000008u;
goto P_0c07bef6;
P_0c07bef6: /* original 6403, guest PC 0x0c07bef6 */
if(!s->budget--) { s->failed_pc=0x0c07bef6u; return 0; }
r[4]=r[0];
goto P_0c07bef8;
P_0c07bef8: /* original e030, guest PC 0x0c07bef8 */
if(!s->budget--) { s->failed_pc=0x0c07bef8u; return 0; }
r[0]=0x00000030u;
goto P_0c07befa;
P_0c07befa: /* original f4f7, guest PC 0x0c07befa */
if(!s->budget--) { s->failed_pc=0x0c07befau; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07befc;
P_0c07befc: /* original 52f5, guest PC 0x0c07befc */
if(!s->budget--) { s->failed_pc=0x0c07befcu; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c07befe;
P_0c07befe: /* original 53f6, guest PC 0x0c07befe */
if(!s->budget--) { s->failed_pc=0x0c07befeu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c07bf00;
P_0c07bf00: /* original 6122, guest PC 0x0c07bf00 */
if(!s->budget--) { s->failed_pc=0x0c07bf00u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c07bf02;
P_0c07bf02: /* original 6232, guest PC 0x0c07bf02 */
if(!s->budget--) { s->failed_pc=0x0c07bf02u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c07bf04;
P_0c07bf04: /* original 01a7, guest PC 0x0c07bf04 */
if(!s->budget--) { s->failed_pc=0x0c07bf04u; return 0; }
r[19]=r[1]*r[10];
goto P_0c07bf06;
P_0c07bf06: /* original 011a, guest PC 0x0c07bf06 */
if(!s->budget--) { s->failed_pc=0x0c07bf06u; return 0; }
r[1]=r[19];
goto P_0c07bf08;
P_0c07bf08: /* original 3218, guest PC 0x0c07bf08 */
if(!s->budget--) { s->failed_pc=0x0c07bf08u; return 0; }
r[2]-=r[1];
goto P_0c07bf0a;
P_0c07bf0a: /* original 2322, guest PC 0x0c07bf0a */
if(!s->budget--) { s->failed_pc=0x0c07bf0au; return 0; }
write(ram,r[3],r[2],4);
goto P_0c07bf0c;
P_0c07bf0c: /* original e20a, guest PC 0x0c07bf0c */
if(!s->budget--) { s->failed_pc=0x0c07bf0cu; return 0; }
r[2]=0x0000000au;
goto P_0c07bf0e;
P_0c07bf0e: /* original 53f6, guest PC 0x0c07bf0e */
if(!s->budget--) { s->failed_pc=0x0c07bf0eu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c07bf10;
P_0c07bf10: /* original 6132, guest PC 0x0c07bf10 */
if(!s->budget--) { s->failed_pc=0x0c07bf10u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c07bf12;
P_0c07bf12: /* original 3123, guest PC 0x0c07bf12 */
if(!s->budget--) { s->failed_pc=0x0c07bf12u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c07bf14;
P_0c07bf14: /* original 890f, guest PC 0x0c07bf14 */
if(!s->budget--) { s->failed_pc=0x0c07bf14u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07bf36; }
goto P_0c07bf16;
P_0c07bf16: /* original 50f3, guest PC 0x0c07bf16 */
if(!s->budget--) { s->failed_pc=0x0c07bf16u; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c07bf18;
P_0c07bf18: /* original e700, guest PC 0x0c07bf18 */
if(!s->budget--) { s->failed_pc=0x0c07bf18u; return 0; }
r[7]=0x00000000u;
goto P_0c07bf1a;
P_0c07bf1a: /* original 53f1, guest PC 0x0c07bf1a */
if(!s->budget--) { s->failed_pc=0x0c07bf1au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07bf1c;
P_0c07bf1c: /* original 66d3, guest PC 0x0c07bf1c */
if(!s->budget--) { s->failed_pc=0x0c07bf1cu; return 0; }
r[6]=r[13];
goto P_0c07bf1e;
P_0c07bf1e: /* original 203b, guest PC 0x0c07bf1e */
if(!s->budget--) { s->failed_pc=0x0c07bf1eu; return 0; }
r[0]|=r[3];
goto P_0c07bf20;
P_0c07bf20: /* original 1f03, guest PC 0x0c07bf20 */
if(!s->budget--) { s->failed_pc=0x0c07bf20u; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c07bf22;
P_0c07bf22: /* original 2fb6, guest PC 0x0c07bf22 */
if(!s->budget--) { s->failed_pc=0x0c07bf22u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bf24;
P_0c07bf24: /* original 2fe6, guest PC 0x0c07bf24 */
if(!s->budget--) { s->failed_pc=0x0c07bf24u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bf26;
P_0c07bf26: /* original 55fc, guest PC 0x0c07bf26 */
if(!s->budget--) { s->failed_pc=0x0c07bf26u; return 0; }
r[5]=read(ram,r[15]+48,4);
goto P_0c07bf28;
P_0c07bf28: /* original 6552, guest PC 0x0c07bf28 */
if(!s->budget--) { s->failed_pc=0x0c07bf28u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c07bf2a;
P_0c07bf2a: /* original 480b, guest PC 0x0c07bf2a */
if(!s->budget--) { s->failed_pc=0x0c07bf2au; return 0; }
target=r[8];
r[16]=code_base|0x0c07bf2eu;
r[4]=read(ram,r[15]+20,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bf2eu) { target=s->pc; goto dispatch; }
goto P_0c07bf2e;
P_0c07bf2c: /* original 54f5, guest PC 0x0c07bf2c */
if(!s->budget--) { s->failed_pc=0x0c07bf2cu; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c07bf2e;
P_0c07bf2e: /* original 6403, guest PC 0x0c07bf2e */
if(!s->budget--) { s->failed_pc=0x0c07bf2eu; return 0; }
r[4]=r[0];
goto P_0c07bf30;
P_0c07bf30: /* original e030, guest PC 0x0c07bf30 */
if(!s->budget--) { s->failed_pc=0x0c07bf30u; return 0; }
r[0]=0x00000030u;
goto P_0c07bf32;
P_0c07bf32: /* original f4f7, guest PC 0x0c07bf32 */
if(!s->budget--) { s->failed_pc=0x0c07bf32u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07bf34;
P_0c07bf34: /* original 7f08, guest PC 0x0c07bf34 */
if(!s->budget--) { s->failed_pc=0x0c07bf34u; return 0; }
r[15]+=0x00000008u;
goto P_0c07bf36;
P_0c07bf36: /* original 50f4, guest PC 0x0c07bf36 */
if(!s->budget--) { s->failed_pc=0x0c07bf36u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c07bf38;
P_0c07bf38: /* original 63c3, guest PC 0x0c07bf38 */
if(!s->budget--) { s->failed_pc=0x0c07bf38u; return 0; }
r[3]=r[12];
goto P_0c07bf3a;
P_0c07bf3a: /* original 4308, guest PC 0x0c07bf3a */
if(!s->budget--) { s->failed_pc=0x0c07bf3au; return 0; }
r[3]<<=2;
goto P_0c07bf3c;
P_0c07bf3c: /* original 033e, guest PC 0x0c07bf3c */
if(!s->budget--) { s->failed_pc=0x0c07bf3cu; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c07bf3e;
P_0c07bf3e: /* original e20a, guest PC 0x0c07bf3e */
if(!s->budget--) { s->failed_pc=0x0c07bf3eu; return 0; }
r[2]=0x0000000au;
goto P_0c07bf40;
P_0c07bf40: /* original 3323, guest PC 0x0c07bf40 */
if(!s->budget--) { s->failed_pc=0x0c07bf40u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c07bf42;
P_0c07bf42: /* original 8b30, guest PC 0x0c07bf42 */
if(!s->budget--) { s->failed_pc=0x0c07bf42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bfa6; }
goto P_0c07bf44;
P_0c07bf44: /* original 937f, guest PC 0x0c07bf44 */
if(!s->budget--) { s->failed_pc=0x0c07bf44u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c046u,2);
goto P_0c07bf46;
P_0c07bf46: /* original 64c3, guest PC 0x0c07bf46 */
if(!s->budget--) { s->failed_pc=0x0c07bf46u; return 0; }
r[4]=r[12];
goto P_0c07bf48;
P_0c07bf48: /* original 51f2, guest PC 0x0c07bf48 */
if(!s->budget--) { s->failed_pc=0x0c07bf48u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c07bf4a;
P_0c07bf4a: /* original 4408, guest PC 0x0c07bf4a */
if(!s->budget--) { s->failed_pc=0x0c07bf4au; return 0; }
r[4]<<=2;
goto P_0c07bf4c;
P_0c07bf4c: /* original 33fc, guest PC 0x0c07bf4c */
if(!s->budget--) { s->failed_pc=0x0c07bf4cu; return 0; }
r[3]+=r[15];
goto P_0c07bf4e;
P_0c07bf4e: /* original 313c, guest PC 0x0c07bf4e */
if(!s->budget--) { s->failed_pc=0x0c07bf4eu; return 0; }
r[1]+=r[3];
goto P_0c07bf50;
P_0c07bf50: /* original 314c, guest PC 0x0c07bf50 */
if(!s->budget--) { s->failed_pc=0x0c07bf50u; return 0; }
r[1]+=r[4];
goto P_0c07bf52;
P_0c07bf52: /* original 1f13, guest PC 0x0c07bf52 */
if(!s->budget--) { s->failed_pc=0x0c07bf52u; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c07bf54;
P_0c07bf54: /* original 2f16, guest PC 0x0c07bf54 */
if(!s->budget--) { s->failed_pc=0x0c07bf54u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bf56;
P_0c07bf56: /* original 9277, guest PC 0x0c07bf56 */
if(!s->budget--) { s->failed_pc=0x0c07bf56u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c048u,2);
goto P_0c07bf58;
P_0c07bf58: /* original 51f3, guest PC 0x0c07bf58 */
if(!s->budget--) { s->failed_pc=0x0c07bf58u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c07bf5a;
P_0c07bf5a: /* original 32fc, guest PC 0x0c07bf5a */
if(!s->budget--) { s->failed_pc=0x0c07bf5au; return 0; }
r[2]+=r[15];
goto P_0c07bf5c;
P_0c07bf5c: /* original 312c, guest PC 0x0c07bf5c */
if(!s->budget--) { s->failed_pc=0x0c07bf5cu; return 0; }
r[1]+=r[2];
goto P_0c07bf5e;
P_0c07bf5e: /* original 314c, guest PC 0x0c07bf5e */
if(!s->budget--) { s->failed_pc=0x0c07bf5eu; return 0; }
r[1]+=r[4];
goto P_0c07bf60;
P_0c07bf60: /* original 1f16, guest PC 0x0c07bf60 */
if(!s->budget--) { s->failed_pc=0x0c07bf60u; return 0; }
write(ram,r[15]+24,r[1],4);
goto P_0c07bf62;
P_0c07bf62: /* original d33d, guest PC 0x0c07bf62 */
if(!s->budget--) { s->failed_pc=0x0c07bf62u; return 0; }
r[3]=read(ram,0x0c07c058u,4);
goto P_0c07bf64;
P_0c07bf64: /* original 6112, guest PC 0x0c07bf64 */
if(!s->budget--) { s->failed_pc=0x0c07bf64u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07bf66;
P_0c07bf66: /* original 430b, guest PC 0x0c07bf66 */
if(!s->budget--) { s->failed_pc=0x0c07bf66u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bf6au;
r[0]=0x0000000au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bf6au) { target=s->pc; goto dispatch; }
goto P_0c07bf6a;
P_0c07bf68: /* original e00a, guest PC 0x0c07bf68 */
if(!s->budget--) { s->failed_pc=0x0c07bf68u; return 0; }
r[0]=0x0000000au;
goto P_0c07bf6a;
P_0c07bf6a: /* original 63f6, guest PC 0x0c07bf6a */
if(!s->budget--) { s->failed_pc=0x0c07bf6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c07bf6c;
P_0c07bf6c: /* original e700, guest PC 0x0c07bf6c */
if(!s->budget--) { s->failed_pc=0x0c07bf6cu; return 0; }
r[7]=0x00000000u;
goto P_0c07bf6e;
P_0c07bf6e: /* original 66d3, guest PC 0x0c07bf6e */
if(!s->budget--) { s->failed_pc=0x0c07bf6eu; return 0; }
r[6]=r[13];
goto P_0c07bf70;
P_0c07bf70: /* original 2302, guest PC 0x0c07bf70 */
if(!s->budget--) { s->failed_pc=0x0c07bf70u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07bf72;
P_0c07bf72: /* original 51f1, guest PC 0x0c07bf72 */
if(!s->budget--) { s->failed_pc=0x0c07bf72u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c07bf74;
P_0c07bf74: /* original 53f7, guest PC 0x0c07bf74 */
if(!s->budget--) { s->failed_pc=0x0c07bf74u; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c07bf76;
P_0c07bf76: /* original 213b, guest PC 0x0c07bf76 */
if(!s->budget--) { s->failed_pc=0x0c07bf76u; return 0; }
r[1]|=r[3];
goto P_0c07bf78;
P_0c07bf78: /* original 1f16, guest PC 0x0c07bf78 */
if(!s->budget--) { s->failed_pc=0x0c07bf78u; return 0; }
write(ram,r[15]+24,r[1],4);
goto P_0c07bf7a;
P_0c07bf7a: /* original 2fb6, guest PC 0x0c07bf7a */
if(!s->budget--) { s->failed_pc=0x0c07bf7au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bf7c;
P_0c07bf7c: /* original 2fe6, guest PC 0x0c07bf7c */
if(!s->budget--) { s->failed_pc=0x0c07bf7cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bf7e;
P_0c07bf7e: /* original 50f5, guest PC 0x0c07bf7e */
if(!s->budget--) { s->failed_pc=0x0c07bf7eu; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c07bf80;
P_0c07bf80: /* original 6002, guest PC 0x0c07bf80 */
if(!s->budget--) { s->failed_pc=0x0c07bf80u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07bf82;
P_0c07bf82: /* original 4008, guest PC 0x0c07bf82 */
if(!s->budget--) { s->failed_pc=0x0c07bf82u; return 0; }
r[0]<<=2;
goto P_0c07bf84;
P_0c07bf84: /* original 059e, guest PC 0x0c07bf84 */
if(!s->budget--) { s->failed_pc=0x0c07bf84u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bf86;
P_0c07bf86: /* original 480b, guest PC 0x0c07bf86 */
if(!s->budget--) { s->failed_pc=0x0c07bf86u; return 0; }
target=r[8];
r[16]=code_base|0x0c07bf8au;
r[4]=r[1];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bf8au) { target=s->pc; goto dispatch; }
goto P_0c07bf8a;
P_0c07bf88: /* original 6413, guest PC 0x0c07bf88 */
if(!s->budget--) { s->failed_pc=0x0c07bf88u; return 0; }
r[4]=r[1];
goto P_0c07bf8a;
P_0c07bf8a: /* original 7f08, guest PC 0x0c07bf8a */
if(!s->budget--) { s->failed_pc=0x0c07bf8au; return 0; }
r[15]+=0x00000008u;
goto P_0c07bf8c;
P_0c07bf8c: /* original 6403, guest PC 0x0c07bf8c */
if(!s->budget--) { s->failed_pc=0x0c07bf8cu; return 0; }
r[4]=r[0];
goto P_0c07bf8e;
P_0c07bf8e: /* original e030, guest PC 0x0c07bf8e */
if(!s->budget--) { s->failed_pc=0x0c07bf8eu; return 0; }
r[0]=0x00000030u;
goto P_0c07bf90;
P_0c07bf90: /* original f4f7, guest PC 0x0c07bf90 */
if(!s->budget--) { s->failed_pc=0x0c07bf90u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07bf92;
P_0c07bf92: /* original 52f3, guest PC 0x0c07bf92 */
if(!s->budget--) { s->failed_pc=0x0c07bf92u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c07bf94;
P_0c07bf94: /* original 53f5, guest PC 0x0c07bf94 */
if(!s->budget--) { s->failed_pc=0x0c07bf94u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c07bf96;
P_0c07bf96: /* original 6222, guest PC 0x0c07bf96 */
if(!s->budget--) { s->failed_pc=0x0c07bf96u; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c07bf98;
P_0c07bf98: /* original 6032, guest PC 0x0c07bf98 */
if(!s->budget--) { s->failed_pc=0x0c07bf98u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07bf9a;
P_0c07bf9a: /* original 6123, guest PC 0x0c07bf9a */
if(!s->budget--) { s->failed_pc=0x0c07bf9au; return 0; }
r[1]=r[2];
goto P_0c07bf9c;
P_0c07bf9c: /* original 4208, guest PC 0x0c07bf9c */
if(!s->budget--) { s->failed_pc=0x0c07bf9cu; return 0; }
r[2]<<=2;
goto P_0c07bf9e;
P_0c07bf9e: /* original 321c, guest PC 0x0c07bf9e */
if(!s->budget--) { s->failed_pc=0x0c07bf9eu; return 0; }
r[2]+=r[1];
goto P_0c07bfa0;
P_0c07bfa0: /* original 4200, guest PC 0x0c07bfa0 */
if(!s->budget--) { s->failed_pc=0x0c07bfa0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07bfa2;
P_0c07bfa2: /* original 3028, guest PC 0x0c07bfa2 */
if(!s->budget--) { s->failed_pc=0x0c07bfa2u; return 0; }
r[0]-=r[2];
goto P_0c07bfa4;
P_0c07bfa4: /* original 2302, guest PC 0x0c07bfa4 */
if(!s->budget--) { s->failed_pc=0x0c07bfa4u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07bfa6;
P_0c07bfa6: /* original 52f1, guest PC 0x0c07bfa6 */
if(!s->budget--) { s->failed_pc=0x0c07bfa6u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07bfa8;
P_0c07bfa8: /* original e700, guest PC 0x0c07bfa8 */
if(!s->budget--) { s->failed_pc=0x0c07bfa8u; return 0; }
r[7]=0x00000000u;
goto P_0c07bfaa;
P_0c07bfaa: /* original 53fb, guest PC 0x0c07bfaa */
if(!s->budget--) { s->failed_pc=0x0c07bfaau; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c07bfac;
P_0c07bfac: /* original 66d3, guest PC 0x0c07bfac */
if(!s->budget--) { s->failed_pc=0x0c07bfacu; return 0; }
r[6]=r[13];
goto P_0c07bfae;
P_0c07bfae: /* original 223b, guest PC 0x0c07bfae */
if(!s->budget--) { s->failed_pc=0x0c07bfaeu; return 0; }
r[2]|=r[3];
goto P_0c07bfb0;
P_0c07bfb0: /* original 1f23, guest PC 0x0c07bfb0 */
if(!s->budget--) { s->failed_pc=0x0c07bfb0u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c07bfb2;
P_0c07bfb2: /* original 2fb6, guest PC 0x0c07bfb2 */
if(!s->budget--) { s->failed_pc=0x0c07bfb2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bfb4;
P_0c07bfb4: /* original 2fe6, guest PC 0x0c07bfb4 */
if(!s->budget--) { s->failed_pc=0x0c07bfb4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bfb6;
P_0c07bfb6: /* original 50fb, guest PC 0x0c07bfb6 */
if(!s->budget--) { s->failed_pc=0x0c07bfb6u; return 0; }
r[0]=read(ram,r[15]+44,4);
goto P_0c07bfb8;
P_0c07bfb8: /* original 6002, guest PC 0x0c07bfb8 */
if(!s->budget--) { s->failed_pc=0x0c07bfb8u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07bfba;
P_0c07bfba: /* original 4008, guest PC 0x0c07bfba */
if(!s->budget--) { s->failed_pc=0x0c07bfbau; return 0; }
r[0]<<=2;
goto P_0c07bfbc;
P_0c07bfbc: /* original 059e, guest PC 0x0c07bfbc */
if(!s->budget--) { s->failed_pc=0x0c07bfbcu; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bfbe;
P_0c07bfbe: /* original 480b, guest PC 0x0c07bfbe */
if(!s->budget--) { s->failed_pc=0x0c07bfbeu; return 0; }
target=r[8];
r[16]=code_base|0x0c07bfc2u;
r[4]=r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07bfc2u) { target=s->pc; goto dispatch; }
goto P_0c07bfc2;
P_0c07bfc0: /* original 6423, guest PC 0x0c07bfc0 */
if(!s->budget--) { s->failed_pc=0x0c07bfc0u; return 0; }
r[4]=r[2];
goto P_0c07bfc2;
P_0c07bfc2: /* original 7f08, guest PC 0x0c07bfc2 */
if(!s->budget--) { s->failed_pc=0x0c07bfc2u; return 0; }
r[15]+=0x00000008u;
goto P_0c07bfc4;
P_0c07bfc4: /* original 6403, guest PC 0x0c07bfc4 */
if(!s->budget--) { s->failed_pc=0x0c07bfc4u; return 0; }
r[4]=r[0];
goto P_0c07bfc6;
P_0c07bfc6: /* original e030, guest PC 0x0c07bfc6 */
if(!s->budget--) { s->failed_pc=0x0c07bfc6u; return 0; }
r[0]=0x00000030u;
goto P_0c07bfc8;
P_0c07bfc8: /* original f4f7, guest PC 0x0c07bfc8 */
if(!s->budget--) { s->failed_pc=0x0c07bfc8u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07bfca;
P_0c07bfca: /* original 7c01, guest PC 0x0c07bfca */
if(!s->budget--) { s->failed_pc=0x0c07bfcau; return 0; }
r[12]+=0x00000001u;
goto P_0c07bfcc;
P_0c07bfcc: /* original 53f9, guest PC 0x0c07bfcc */
if(!s->budget--) { s->failed_pc=0x0c07bfccu; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c07bfce;
P_0c07bfce: /* original 7304, guest PC 0x0c07bfce */
if(!s->budget--) { s->failed_pc=0x0c07bfceu; return 0; }
r[3]+=0x00000004u;
goto P_0c07bfd0;
P_0c07bfd0: /* original 1f39, guest PC 0x0c07bfd0 */
if(!s->budget--) { s->failed_pc=0x0c07bfd0u; return 0; }
write(ram,r[15]+36,r[3],4);
goto P_0c07bfd2;
P_0c07bfd2: /* original 52fb, guest PC 0x0c07bfd2 */
if(!s->budget--) { s->failed_pc=0x0c07bfd2u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c07bfd4;
P_0c07bfd4: /* original 7250, guest PC 0x0c07bfd4 */
if(!s->budget--) { s->failed_pc=0x0c07bfd4u; return 0; }
r[2]+=0x00000050u;
goto P_0c07bfd6;
P_0c07bfd6: /* original 1f2b, guest PC 0x0c07bfd6 */
if(!s->budget--) { s->failed_pc=0x0c07bfd6u; return 0; }
write(ram,r[15]+44,r[2],4);
goto P_0c07bfd8;
P_0c07bfd8: /* original 51f7, guest PC 0x0c07bfd8 */
if(!s->budget--) { s->failed_pc=0x0c07bfd8u; return 0; }
r[1]=read(ram,r[15]+28,4);
goto P_0c07bfda;
P_0c07bfda: /* original 7150, guest PC 0x0c07bfda */
if(!s->budget--) { s->failed_pc=0x0c07bfdau; return 0; }
r[1]+=0x00000050u;
goto P_0c07bfdc;
P_0c07bfdc: /* original 1f17, guest PC 0x0c07bfdc */
if(!s->budget--) { s->failed_pc=0x0c07bfdcu; return 0; }
write(ram,r[15]+28,r[1],4);
goto P_0c07bfde;
P_0c07bfde: /* original e302, guest PC 0x0c07bfde */
if(!s->budget--) { s->failed_pc=0x0c07bfdeu; return 0; }
r[3]=0x00000002u;
goto P_0c07bfe0;
P_0c07bfe0: /* original 3c33, guest PC 0x0c07bfe0 */
if(!s->budget--) { s->failed_pc=0x0c07bfe0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[3])!=0);
goto P_0c07bfe2;
P_0c07bfe2: /* original 8901, guest PC 0x0c07bfe2 */
if(!s->budget--) { s->failed_pc=0x0c07bfe2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07bfe8; }
goto P_0c07bfe4;
P_0c07bfe4: /* original ae96, guest PC 0x0c07bfe4 */
if(!s->budget--) { s->failed_pc=0x0c07bfe4u; return 0; }
goto P_0c07bd14;
P_0c07bfe6: /* original 0009, guest PC 0x0c07bfe6 */
if(!s->budget--) { s->failed_pc=0x0c07bfe6u; return 0; }
goto P_0c07bfe8;
P_0c07bfe8: /* original 51f8, guest PC 0x0c07bfe8 */
if(!s->budget--) { s->failed_pc=0x0c07bfe8u; return 0; }
r[1]=read(ram,r[15]+32,4);
goto P_0c07bfea;
P_0c07bfea: /* original 7101, guest PC 0x0c07bfea */
if(!s->budget--) { s->failed_pc=0x0c07bfeau; return 0; }
r[1]+=0x00000001u;
goto P_0c07bfec;
P_0c07bfec: /* original 1f18, guest PC 0x0c07bfec */
if(!s->budget--) { s->failed_pc=0x0c07bfecu; return 0; }
write(ram,r[15]+32,r[1],4);
goto P_0c07bfee;
P_0c07bfee: /* original 52f8, guest PC 0x0c07bfee */
if(!s->budget--) { s->failed_pc=0x0c07bfeeu; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c07bff0;
P_0c07bff0: /* original e302, guest PC 0x0c07bff0 */
if(!s->budget--) { s->failed_pc=0x0c07bff0u; return 0; }
r[3]=0x00000002u;
goto P_0c07bff2;
P_0c07bff2: /* original 3233, guest PC 0x0c07bff2 */
if(!s->budget--) { s->failed_pc=0x0c07bff2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c07bff4;
P_0c07bff4: /* original 8901, guest PC 0x0c07bff4 */
if(!s->budget--) { s->failed_pc=0x0c07bff4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07bffa; }
goto P_0c07bff6;
P_0c07bff6: /* original ae64, guest PC 0x0c07bff6 */
if(!s->budget--) { s->failed_pc=0x0c07bff6u; return 0; }
goto P_0c07bcc2;
P_0c07bff8: /* original 0009, guest PC 0x0c07bff8 */
if(!s->budget--) { s->failed_pc=0x0c07bff8u; return 0; }
goto P_0c07bffa;
P_0c07bffa: /* original 2fb6, guest PC 0x0c07bffa */
if(!s->budget--) { s->failed_pc=0x0c07bffau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bffc;
P_0c07bffc: /* original e700, guest PC 0x0c07bffc */
if(!s->budget--) { s->failed_pc=0x0c07bffcu; return 0; }
r[7]=0x00000000u;
goto P_0c07bffe;
P_0c07bffe: /* original 2fe6, guest PC 0x0c07bffe */
if(!s->budget--) { s->failed_pc=0x0c07bffeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c000;
P_0c07c000: /* original 9523, guest PC 0x0c07c000 */
if(!s->budget--) { s->failed_pc=0x0c07c000u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c04au,2);
goto P_0c07c002;
P_0c07c002: /* original 9423, guest PC 0x0c07c002 */
if(!s->budget--) { s->failed_pc=0x0c07c002u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c04cu,2);
goto P_0c07c004;
P_0c07c004: /* original 480b, guest PC 0x0c07c004 */
if(!s->budget--) { s->failed_pc=0x0c07c004u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c008u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c008u) { target=s->pc; goto dispatch; }
goto P_0c07c008;
P_0c07c006: /* original 66d3, guest PC 0x0c07c006 */
if(!s->budget--) { s->failed_pc=0x0c07c006u; return 0; }
r[6]=r[13];
goto P_0c07c008;
P_0c07c008: /* original 6403, guest PC 0x0c07c008 */
if(!s->budget--) { s->failed_pc=0x0c07c008u; return 0; }
r[4]=r[0];
goto P_0c07c00a;
P_0c07c00a: /* original e030, guest PC 0x0c07c00a */
if(!s->budget--) { s->failed_pc=0x0c07c00au; return 0; }
r[0]=0x00000030u;
goto P_0c07c00c;
P_0c07c00c: /* original f4f7, guest PC 0x0c07c00c */
if(!s->budget--) { s->failed_pc=0x0c07c00cu; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07c00e;
P_0c07c00e: /* original e700, guest PC 0x0c07c00e */
if(!s->budget--) { s->failed_pc=0x0c07c00eu; return 0; }
r[7]=0x00000000u;
goto P_0c07c010;
P_0c07c010: /* original 2fb6, guest PC 0x0c07c010 */
if(!s->budget--) { s->failed_pc=0x0c07c010u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c012;
P_0c07c012: /* original 2fe6, guest PC 0x0c07c012 */
if(!s->budget--) { s->failed_pc=0x0c07c012u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c014;
P_0c07c014: /* original 951b, guest PC 0x0c07c014 */
if(!s->budget--) { s->failed_pc=0x0c07c014u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c04eu,2);
goto P_0c07c016;
P_0c07c016: /* original 941b, guest PC 0x0c07c016 */
if(!s->budget--) { s->failed_pc=0x0c07c016u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c050u,2);
goto P_0c07c018;
P_0c07c018: /* original 480b, guest PC 0x0c07c018 */
if(!s->budget--) { s->failed_pc=0x0c07c018u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c01cu;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c01cu) { target=s->pc; goto dispatch; }
goto P_0c07c01c;
P_0c07c01a: /* original 66d3, guest PC 0x0c07c01a */
if(!s->budget--) { s->failed_pc=0x0c07c01au; return 0; }
r[6]=r[13];
goto P_0c07c01c;
P_0c07c01c: /* original 6403, guest PC 0x0c07c01c */
if(!s->budget--) { s->failed_pc=0x0c07c01cu; return 0; }
r[4]=r[0];
goto P_0c07c01e;
P_0c07c01e: /* original e030, guest PC 0x0c07c01e */
if(!s->budget--) { s->failed_pc=0x0c07c01eu; return 0; }
r[0]=0x00000030u;
goto P_0c07c020;
P_0c07c020: /* original f4f7, guest PC 0x0c07c020 */
if(!s->budget--) { s->failed_pc=0x0c07c020u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07c022;
P_0c07c022: /* original e700, guest PC 0x0c07c022 */
if(!s->budget--) { s->failed_pc=0x0c07c022u; return 0; }
r[7]=0x00000000u;
goto P_0c07c024;
P_0c07c024: /* original 2fb6, guest PC 0x0c07c024 */
if(!s->budget--) { s->failed_pc=0x0c07c024u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c026;
P_0c07c026: /* original 2fe6, guest PC 0x0c07c026 */
if(!s->budget--) { s->failed_pc=0x0c07c026u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c028;
P_0c07c028: /* original 950f, guest PC 0x0c07c028 */
if(!s->budget--) { s->failed_pc=0x0c07c028u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c04au,2);
goto P_0c07c02a;
P_0c07c02a: /* original 9412, guest PC 0x0c07c02a */
if(!s->budget--) { s->failed_pc=0x0c07c02au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c052u,2);
goto P_0c07c02c;
P_0c07c02c: /* original 480b, guest PC 0x0c07c02c */
if(!s->budget--) { s->failed_pc=0x0c07c02cu; return 0; }
target=r[8];
r[16]=code_base|0x0c07c030u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c030u) { target=s->pc; goto dispatch; }
goto P_0c07c030;
P_0c07c02e: /* original 66d3, guest PC 0x0c07c02e */
if(!s->budget--) { s->failed_pc=0x0c07c02eu; return 0; }
r[6]=r[13];
goto P_0c07c030;
P_0c07c030: /* original 6403, guest PC 0x0c07c030 */
if(!s->budget--) { s->failed_pc=0x0c07c030u; return 0; }
r[4]=r[0];
goto P_0c07c032;
P_0c07c032: /* original e030, guest PC 0x0c07c032 */
if(!s->budget--) { s->failed_pc=0x0c07c032u; return 0; }
r[0]=0x00000030u;
goto P_0c07c034;
P_0c07c034: /* original f4f7, guest PC 0x0c07c034 */
if(!s->budget--) { s->failed_pc=0x0c07c034u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07c036;
P_0c07c036: /* original e700, guest PC 0x0c07c036 */
if(!s->budget--) { s->failed_pc=0x0c07c036u; return 0; }
r[7]=0x00000000u;
goto P_0c07c038;
P_0c07c038: /* original 2fb6, guest PC 0x0c07c038 */
if(!s->budget--) { s->failed_pc=0x0c07c038u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c03a;
P_0c07c03a: /* original 2fe6, guest PC 0x0c07c03a */
if(!s->budget--) { s->failed_pc=0x0c07c03au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c03c;
P_0c07c03c: /* original 9507, guest PC 0x0c07c03c */
if(!s->budget--) { s->failed_pc=0x0c07c03cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c04eu,2);
goto P_0c07c03e;
P_0c07c03e: /* original 9409, guest PC 0x0c07c03e */
if(!s->budget--) { s->failed_pc=0x0c07c03eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c054u,2);
goto P_0c07c040;
P_0c07c040: /* original a00c, guest PC 0x0c07c040 */
if(!s->budget--) { s->failed_pc=0x0c07c040u; return 0; }
r[6]=r[13];
goto P_0c07c05c;
P_0c07c042: /* original 66d3, guest PC 0x0c07c042 */
if(!s->budget--) { s->failed_pc=0x0c07c042u; return 0; }
r[6]=r[13];
return vf3_matrix_family(0x0c07c044u,s,ram);
P_0c07c05c: /* original 480b, guest PC 0x0c07c05c */
if(!s->budget--) { s->failed_pc=0x0c07c05cu; return 0; }
target=r[8];
r[16]=code_base|0x0c07c060u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c060u) { target=s->pc; goto dispatch; }
goto P_0c07c060;
P_0c07c05e: /* original 0009, guest PC 0x0c07c05e */
if(!s->budget--) { s->failed_pc=0x0c07c05eu; return 0; }
goto P_0c07c060;
P_0c07c060: /* original 6403, guest PC 0x0c07c060 */
if(!s->budget--) { s->failed_pc=0x0c07c060u; return 0; }
r[4]=r[0];
goto P_0c07c062;
P_0c07c062: /* original e030, guest PC 0x0c07c062 */
if(!s->budget--) { s->failed_pc=0x0c07c062u; return 0; }
r[0]=0x00000030u;
goto P_0c07c064;
P_0c07c064: /* original f4f7, guest PC 0x0c07c064 */
if(!s->budget--) { s->failed_pc=0x0c07c064u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07c066;
P_0c07c066: /* original d329, guest PC 0x0c07c066 */
if(!s->budget--) { s->failed_pc=0x0c07c066u; return 0; }
r[3]=read(ram,0x0c07c10cu,4);
goto P_0c07c068;
P_0c07c068: /* original 944c, guest PC 0x0c07c068 */
if(!s->budget--) { s->failed_pc=0x0c07c068u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c104u,2);
goto P_0c07c06a;
P_0c07c06a: /* original 430b, guest PC 0x0c07c06a */
if(!s->budget--) { s->failed_pc=0x0c07c06au; return 0; }
target=r[3];
r[16]=code_base|0x0c07c06eu;
r[15]+=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c06eu) { target=s->pc; goto dispatch; }
goto P_0c07c06e;
P_0c07c06c: /* original 7f20, guest PC 0x0c07c06c */
if(!s->budget--) { s->failed_pc=0x0c07c06cu; return 0; }
r[15]+=0x00000020u;
goto P_0c07c06e;
P_0c07c06e: /* original 6d03, guest PC 0x0c07c06e */
if(!s->budget--) { s->failed_pc=0x0c07c06eu; return 0; }
r[13]=r[0];
goto P_0c07c070;
P_0c07c070: /* original 52d8, guest PC 0x0c07c070 */
if(!s->budget--) { s->failed_pc=0x0c07c070u; return 0; }
r[2]=read(ram,r[13]+32,4);
goto P_0c07c072;
P_0c07c072: /* original e040, guest PC 0x0c07c072 */
if(!s->budget--) { s->failed_pc=0x0c07c072u; return 0; }
r[0]=0x00000040u;
goto P_0c07c074;
P_0c07c074: /* original 64f3, guest PC 0x0c07c074 */
if(!s->budget--) { s->failed_pc=0x0c07c074u; return 0; }
r[4]=r[15];
goto P_0c07c076;
P_0c07c076: /* original 0f26, guest PC 0x0c07c076 */
if(!s->budget--) { s->failed_pc=0x0c07c076u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07c078;
P_0c07c078: /* original c725, guest PC 0x0c07c078 */
if(!s->budget--) { s->failed_pc=0x0c07c078u; return 0; }
r[0]=0x0c07c110u;
goto P_0c07c07a;
P_0c07c07a: /* original f308, guest PC 0x0c07c07a */
if(!s->budget--) { s->failed_pc=0x0c07c07au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07c07c;
P_0c07c07c: /* original e018, guest PC 0x0c07c07c */
if(!s->budget--) { s->failed_pc=0x0c07c07cu; return 0; }
r[0]=0x00000018u;
goto P_0c07c07e;
P_0c07c07e: /* original f6d6, guest PC 0x0c07c07e */
if(!s->budget--) { s->failed_pc=0x0c07c07eu; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c07c080;
P_0c07c080: /* original c724, guest PC 0x0c07c080 */
if(!s->budget--) { s->failed_pc=0x0c07c080u; return 0; }
r[0]=0x0c07c114u;
goto P_0c07c082;
P_0c07c082: /* original f208, guest PC 0x0c07c082 */
if(!s->budget--) { s->failed_pc=0x0c07c082u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07c084;
P_0c07c084: /* original e01c, guest PC 0x0c07c084 */
if(!s->budget--) { s->failed_pc=0x0c07c084u; return 0; }
r[0]=0x0000001cu;
goto P_0c07c086;
P_0c07c086: /* original f7d6, guest PC 0x0c07c086 */
if(!s->budget--) { s->failed_pc=0x0c07c086u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c07c088;
P_0c07c088: /* original f632, guest PC 0x0c07c088 */
if(!s->budget--) { s->failed_pc=0x0c07c088u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c07c08a;
P_0c07c08a: /* original c723, guest PC 0x0c07c08a */
if(!s->budget--) { s->failed_pc=0x0c07c08au; return 0; }
r[0]=0x0c07c118u;
goto P_0c07c08c;
P_0c07c08c: /* original d323, guest PC 0x0c07c08c */
if(!s->budget--) { s->failed_pc=0x0c07c08cu; return 0; }
r[3]=read(ram,0x0c07c11cu,4);
goto P_0c07c08e;
P_0c07c08e: /* original f722, guest PC 0x0c07c08e */
if(!s->budget--) { s->failed_pc=0x0c07c08eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'*');
goto P_0c07c090;
P_0c07c090: /* original f808, guest PC 0x0c07c090 */
if(!s->budget--) { s->failed_pc=0x0c07c090u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c07c092;
P_0c07c092: /* original f5ec, guest PC 0x0c07c092 */
if(!s->budget--) { s->failed_pc=0x0c07c092u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c07c094;
P_0c07c094: /* original f4ec, guest PC 0x0c07c094 */
if(!s->budget--) { s->failed_pc=0x0c07c094u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c07c096;
P_0c07c096: /* original 430b, guest PC 0x0c07c096 */
if(!s->budget--) { s->failed_pc=0x0c07c096u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c09au;
r[4]+=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c09au) { target=s->pc; goto dispatch; }
goto P_0c07c09a;
P_0c07c098: /* original 7440, guest PC 0x0c07c098 */
if(!s->budget--) { s->failed_pc=0x0c07c098u; return 0; }
r[4]+=0x00000040u;
goto P_0c07c09a;
P_0c07c09a: /* original e014, guest PC 0x0c07c09a */
if(!s->budget--) { s->failed_pc=0x0c07c09au; return 0; }
r[0]=0x00000014u;
goto P_0c07c09c;
P_0c07c09c: /* original d320, guest PC 0x0c07c09c */
if(!s->budget--) { s->failed_pc=0x0c07c09cu; return 0; }
r[3]=read(ram,0x0c07c120u,4);
goto P_0c07c09e;
P_0c07c09e: /* original f9d6, guest PC 0x0c07c09e */
if(!s->budget--) { s->failed_pc=0x0c07c09eu; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c07c0a0;
P_0c07c0a0: /* original e010, guest PC 0x0c07c0a0 */
if(!s->budget--) { s->failed_pc=0x0c07c0a0u; return 0; }
r[0]=0x00000010u;
goto P_0c07c0a2;
P_0c07c0a2: /* original f8d6, guest PC 0x0c07c0a2 */
if(!s->budget--) { s->failed_pc=0x0c07c0a2u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c07c0a4;
P_0c07c0a4: /* original e00c, guest PC 0x0c07c0a4 */
if(!s->budget--) { s->failed_pc=0x0c07c0a4u; return 0; }
r[0]=0x0000000cu;
goto P_0c07c0a6;
P_0c07c0a6: /* original f7d6, guest PC 0x0c07c0a6 */
if(!s->budget--) { s->failed_pc=0x0c07c0a6u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c07c0a8;
P_0c07c0a8: /* original e008, guest PC 0x0c07c0a8 */
if(!s->budget--) { s->failed_pc=0x0c07c0a8u; return 0; }
r[0]=0x00000008u;
goto P_0c07c0aa;
P_0c07c0aa: /* original f6d6, guest PC 0x0c07c0aa */
if(!s->budget--) { s->failed_pc=0x0c07c0aau; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c07c0ac;
P_0c07c0ac: /* original e004, guest PC 0x0c07c0ac */
if(!s->budget--) { s->failed_pc=0x0c07c0acu; return 0; }
r[0]=0x00000004u;
goto P_0c07c0ae;
P_0c07c0ae: /* original f4d8, guest PC 0x0c07c0ae */
if(!s->budget--) { s->failed_pc=0x0c07c0aeu; return 0; }
vf3_matrix_load(s,ram,4,r[13]);
goto P_0c07c0b0;
P_0c07c0b0: /* original 64f3, guest PC 0x0c07c0b0 */
if(!s->budget--) { s->failed_pc=0x0c07c0b0u; return 0; }
r[4]=r[15];
goto P_0c07c0b2;
P_0c07c0b2: /* original f5d6, guest PC 0x0c07c0b2 */
if(!s->budget--) { s->failed_pc=0x0c07c0b2u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c07c0b4;
P_0c07c0b4: /* original 430b, guest PC 0x0c07c0b4 */
if(!s->budget--) { s->failed_pc=0x0c07c0b4u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c0b8u;
r[4]+=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c0b8u) { target=s->pc; goto dispatch; }
goto P_0c07c0b8;
P_0c07c0b6: /* original 7440, guest PC 0x0c07c0b6 */
if(!s->budget--) { s->failed_pc=0x0c07c0b6u; return 0; }
r[4]+=0x00000040u;
goto P_0c07c0b8;
P_0c07c0b8: /* original e068, guest PC 0x0c07c0b8 */
if(!s->budget--) { s->failed_pc=0x0c07c0b8u; return 0; }
r[0]=0x00000068u;
goto P_0c07c0ba;
P_0c07c0ba: /* original 64f3, guest PC 0x0c07c0ba */
if(!s->budget--) { s->failed_pc=0x0c07c0bau; return 0; }
r[4]=r[15];
goto P_0c07c0bc;
P_0c07c0bc: /* original 0fe6, guest PC 0x0c07c0bc */
if(!s->budget--) { s->failed_pc=0x0c07c0bcu; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c07c0be;
P_0c07c0be: /* original e06c, guest PC 0x0c07c0be */
if(!s->budget--) { s->failed_pc=0x0c07c0beu; return 0; }
r[0]=0x0000006cu;
goto P_0c07c0c0;
P_0c07c0c0: /* original 9321, guest PC 0x0c07c0c0 */
if(!s->budget--) { s->failed_pc=0x0c07c0c0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c106u,2);
goto P_0c07c0c2;
P_0c07c0c2: /* original 0f36, guest PC 0x0c07c0c2 */
if(!s->budget--) { s->failed_pc=0x0c07c0c2u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c07c0c4;
P_0c07c0c4: /* original c717, guest PC 0x0c07c0c4 */
if(!s->budget--) { s->failed_pc=0x0c07c0c4u; return 0; }
r[0]=0x0c07c124u;
goto P_0c07c0c6;
P_0c07c0c6: /* original f308, guest PC 0x0c07c0c6 */
if(!s->budget--) { s->failed_pc=0x0c07c0c6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07c0c8;
P_0c07c0c8: /* original e070, guest PC 0x0c07c0c8 */
if(!s->budget--) { s->failed_pc=0x0c07c0c8u; return 0; }
r[0]=0x00000070u;
goto P_0c07c0ca;
P_0c07c0ca: /* original ff37, guest PC 0x0c07c0ca */
if(!s->budget--) { s->failed_pc=0x0c07c0cau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c07c0cc;
P_0c07c0cc: /* original d316, guest PC 0x0c07c0cc */
if(!s->budget--) { s->failed_pc=0x0c07c0ccu; return 0; }
r[3]=read(ram,0x0c07c128u,4);
goto P_0c07c0ce;
P_0c07c0ce: /* original 430b, guest PC 0x0c07c0ce */
if(!s->budget--) { s->failed_pc=0x0c07c0ceu; return 0; }
target=r[3];
r[16]=code_base|0x0c07c0d2u;
r[4]+=0x00000040u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c0d2u) { target=s->pc; goto dispatch; }
goto P_0c07c0d2;
P_0c07c0d0: /* original 7440, guest PC 0x0c07c0d0 */
if(!s->budget--) { s->failed_pc=0x0c07c0d0u; return 0; }
r[4]+=0x00000040u;
goto P_0c07c0d2;
P_0c07c0d2: /* original a0eb, guest PC 0x0c07c0d2 */
if(!s->budget--) { s->failed_pc=0x0c07c0d2u; return 0; }
goto P_0c07c2ac;
P_0c07c0d4: /* original 0009, guest PC 0x0c07c0d4 */
if(!s->budget--) { s->failed_pc=0x0c07c0d4u; return 0; }
goto P_0c07c0d6;
P_0c07c0d6: /* original a0ba, guest PC 0x0c07c0d6 */
if(!s->budget--) { s->failed_pc=0x0c07c0d6u; return 0; }
write(ram,r[15]+36,r[14],4);
goto P_0c07c24e;
P_0c07c0d8: /* original 1fe9, guest PC 0x0c07c0d8 */
if(!s->budget--) { s->failed_pc=0x0c07c0d8u; return 0; }
write(ram,r[15]+36,r[14],4);
goto P_0c07c0da;
P_0c07c0da: /* original e122, guest PC 0x0c07c0da */
if(!s->budget--) { s->failed_pc=0x0c07c0dau; return 0; }
r[1]=0x00000022u;
goto P_0c07c0dc;
P_0c07c0dc: /* original 1fe2, guest PC 0x0c07c0dc */
if(!s->budget--) { s->failed_pc=0x0c07c0dcu; return 0; }
write(ram,r[15]+8,r[14],4);
goto P_0c07c0de;
P_0c07c0de: /* original 53f9, guest PC 0x0c07c0de */
if(!s->budget--) { s->failed_pc=0x0c07c0deu; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c07c0e0;
P_0c07c0e0: /* original e007, guest PC 0x0c07c0e0 */
if(!s->budget--) { s->failed_pc=0x0c07c0e0u; return 0; }
r[0]=0x00000007u;
goto P_0c07c0e2;
P_0c07c0e2: /* original 4308, guest PC 0x0c07c0e2 */
if(!s->budget--) { s->failed_pc=0x0c07c0e2u; return 0; }
r[3]<<=2;
goto P_0c07c0e4;
P_0c07c0e4: /* original 4300, guest PC 0x0c07c0e4 */
if(!s->budget--) { s->failed_pc=0x0c07c0e4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07c0e6;
P_0c07c0e6: /* original 2f32, guest PC 0x0c07c0e6 */
if(!s->budget--) { s->failed_pc=0x0c07c0e6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07c0e8;
P_0c07c0e8: /* original 920e, guest PC 0x0c07c0e8 */
if(!s->budget--) { s->failed_pc=0x0c07c0e8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c108u,2);
goto P_0c07c0ea;
P_0c07c0ea: /* original 32fc, guest PC 0x0c07c0ea */
if(!s->budget--) { s->failed_pc=0x0c07c0eau; return 0; }
r[2]+=r[15];
goto P_0c07c0ec;
P_0c07c0ec: /* original 332c, guest PC 0x0c07c0ec */
if(!s->budget--) { s->failed_pc=0x0c07c0ecu; return 0; }
r[3]+=r[2];
goto P_0c07c0ee;
P_0c07c0ee: /* original 1f34, guest PC 0x0c07c0ee */
if(!s->budget--) { s->failed_pc=0x0c07c0eeu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c07c0f0;
P_0c07c0f0: /* original 1f3b, guest PC 0x0c07c0f0 */
if(!s->budget--) { s->failed_pc=0x0c07c0f0u; return 0; }
write(ram,r[15]+44,r[3],4);
goto P_0c07c0f2;
P_0c07c0f2: /* original 1f13, guest PC 0x0c07c0f2 */
if(!s->budget--) { s->failed_pc=0x0c07c0f2u; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c07c0f4;
P_0c07c0f4: /* original e11e, guest PC 0x0c07c0f4 */
if(!s->budget--) { s->failed_pc=0x0c07c0f4u; return 0; }
r[1]=0x0000001eu;
goto P_0c07c0f6;
P_0c07c0f6: /* original 1f18, guest PC 0x0c07c0f6 */
if(!s->budget--) { s->failed_pc=0x0c07c0f6u; return 0; }
write(ram,r[15]+32,r[1],4);
goto P_0c07c0f8;
P_0c07c0f8: /* original 51f9, guest PC 0x0c07c0f8 */
if(!s->budget--) { s->failed_pc=0x0c07c0f8u; return 0; }
r[1]=read(ram,r[15]+36,4);
goto P_0c07c0fa;
P_0c07c0fa: /* original 4100, guest PC 0x0c07c0fa */
if(!s->budget--) { s->failed_pc=0x0c07c0fau; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c07c0fc;
P_0c07c0fc: /* original 7102, guest PC 0x0c07c0fc */
if(!s->budget--) { s->failed_pc=0x0c07c0fcu; return 0; }
r[1]+=0x00000002u;
goto P_0c07c0fe;
P_0c07c0fe: /* original 410c, guest PC 0x0c07c0fe */
if(!s->budget--) { s->failed_pc=0x0c07c0feu; return 0; }
r[1]=(r[0]&0x80000000u)?((r[0]&31u)?(uint32_t)((int32_t)r[1]>>((-r[0])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[0]&31u);
goto P_0c07c100;
P_0c07c100: /* original a09c, guest PC 0x0c07c100 */
if(!s->budget--) { s->failed_pc=0x0c07c100u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c07c23c;
P_0c07c102: /* original 1f11, guest PC 0x0c07c102 */
if(!s->budget--) { s->failed_pc=0x0c07c102u; return 0; }
write(ram,r[15]+4,r[1],4);
return vf3_matrix_family(0x0c07c104u,s,ram);
P_0c07c12c: /* original 5cf2, guest PC 0x0c07c12c */
if(!s->budget--) { s->failed_pc=0x0c07c12cu; return 0; }
r[12]=read(ram,r[15]+8,4);
goto P_0c07c12e;
P_0c07c12e: /* original 50f4, guest PC 0x0c07c12e */
if(!s->budget--) { s->failed_pc=0x0c07c12eu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c07c130;
P_0c07c130: /* original 4c08, guest PC 0x0c07c130 */
if(!s->budget--) { s->failed_pc=0x0c07c130u; return 0; }
r[12]<<=2;
goto P_0c07c132;
P_0c07c132: /* original 03ce, guest PC 0x0c07c132 */
if(!s->budget--) { s->failed_pc=0x0c07c132u; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c07c134;
P_0c07c134: /* original 33a3, guest PC 0x0c07c134 */
if(!s->budget--) { s->failed_pc=0x0c07c134u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[10])!=0);
goto P_0c07c136;
P_0c07c136: /* original 8b31, guest PC 0x0c07c136 */
if(!s->budget--) { s->failed_pc=0x0c07c136u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07c19c; }
goto P_0c07c138;
P_0c07c138: /* original 93bd, guest PC 0x0c07c138 */
if(!s->budget--) { s->failed_pc=0x0c07c138u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2b6u,2);
goto P_0c07c13a;
P_0c07c13a: /* original 62f2, guest PC 0x0c07c13a */
if(!s->budget--) { s->failed_pc=0x0c07c13au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07c13c;
P_0c07c13c: /* original 33fc, guest PC 0x0c07c13c */
if(!s->budget--) { s->failed_pc=0x0c07c13cu; return 0; }
r[3]+=r[15];
goto P_0c07c13e;
P_0c07c13e: /* original 323c, guest PC 0x0c07c13e */
if(!s->budget--) { s->failed_pc=0x0c07c13eu; return 0; }
r[2]+=r[3];
goto P_0c07c140;
P_0c07c140: /* original 32cc, guest PC 0x0c07c140 */
if(!s->budget--) { s->failed_pc=0x0c07c140u; return 0; }
r[2]+=r[12];
goto P_0c07c142;
P_0c07c142: /* original 1f27, guest PC 0x0c07c142 */
if(!s->budget--) { s->failed_pc=0x0c07c142u; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c07c144;
P_0c07c144: /* original 90b8, guest PC 0x0c07c144 */
if(!s->budget--) { s->failed_pc=0x0c07c144u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2b8u,2);
goto P_0c07c146;
P_0c07c146: /* original 61f2, guest PC 0x0c07c146 */
if(!s->budget--) { s->failed_pc=0x0c07c146u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c07c148;
P_0c07c148: /* original 30fc, guest PC 0x0c07c148 */
if(!s->budget--) { s->failed_pc=0x0c07c148u; return 0; }
r[0]+=r[15];
goto P_0c07c14a;
P_0c07c14a: /* original 310c, guest PC 0x0c07c14a */
if(!s->budget--) { s->failed_pc=0x0c07c14au; return 0; }
r[1]+=r[0];
goto P_0c07c14c;
P_0c07c14c: /* original 31cc, guest PC 0x0c07c14c */
if(!s->budget--) { s->failed_pc=0x0c07c14cu; return 0; }
r[1]+=r[12];
goto P_0c07c14e;
P_0c07c14e: /* original 1f1a, guest PC 0x0c07c14e */
if(!s->budget--) { s->failed_pc=0x0c07c14eu; return 0; }
write(ram,r[15]+40,r[1],4);
goto P_0c07c150;
P_0c07c150: /* original 6112, guest PC 0x0c07c150 */
if(!s->budget--) { s->failed_pc=0x0c07c150u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07c152;
P_0c07c152: /* original d35d, guest PC 0x0c07c152 */
if(!s->budget--) { s->failed_pc=0x0c07c152u; return 0; }
r[3]=read(ram,0x0c07c2c8u,4);
goto P_0c07c154;
P_0c07c154: /* original 430b, guest PC 0x0c07c154 */
if(!s->budget--) { s->failed_pc=0x0c07c154u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c158u;
r[0]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c158u) { target=s->pc; goto dispatch; }
goto P_0c07c158;
P_0c07c156: /* original 60a3, guest PC 0x0c07c156 */
if(!s->budget--) { s->failed_pc=0x0c07c156u; return 0; }
r[0]=r[10];
goto P_0c07c158;
P_0c07c158: /* original 2202, guest PC 0x0c07c158 */
if(!s->budget--) { s->failed_pc=0x0c07c158u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c07c15a;
P_0c07c15a: /* original e700, guest PC 0x0c07c15a */
if(!s->budget--) { s->failed_pc=0x0c07c15au; return 0; }
r[7]=0x00000000u;
goto P_0c07c15c;
P_0c07c15c: /* original 52f2, guest PC 0x0c07c15c */
if(!s->budget--) { s->failed_pc=0x0c07c15cu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07c15e;
P_0c07c15e: /* original 66d3, guest PC 0x0c07c15e */
if(!s->budget--) { s->failed_pc=0x0c07c15eu; return 0; }
r[6]=r[13];
goto P_0c07c160;
P_0c07c160: /* original 6323, guest PC 0x0c07c160 */
if(!s->budget--) { s->failed_pc=0x0c07c160u; return 0; }
r[3]=r[2];
goto P_0c07c162;
P_0c07c162: /* original 4208, guest PC 0x0c07c162 */
if(!s->budget--) { s->failed_pc=0x0c07c162u; return 0; }
r[2]<<=2;
goto P_0c07c164;
P_0c07c164: /* original 323c, guest PC 0x0c07c164 */
if(!s->budget--) { s->failed_pc=0x0c07c164u; return 0; }
r[2]+=r[3];
goto P_0c07c166;
P_0c07c166: /* original 53f1, guest PC 0x0c07c166 */
if(!s->budget--) { s->failed_pc=0x0c07c166u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07c168;
P_0c07c168: /* original 4208, guest PC 0x0c07c168 */
if(!s->budget--) { s->failed_pc=0x0c07c168u; return 0; }
r[2]<<=2;
goto P_0c07c16a;
P_0c07c16a: /* original 4200, guest PC 0x0c07c16a */
if(!s->budget--) { s->failed_pc=0x0c07c16au; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07c16c;
P_0c07c16c: /* original 720d, guest PC 0x0c07c16c */
if(!s->budget--) { s->failed_pc=0x0c07c16cu; return 0; }
r[2]+=0x0000000du;
goto P_0c07c16e;
P_0c07c16e: /* original 4200, guest PC 0x0c07c16e */
if(!s->budget--) { s->failed_pc=0x0c07c16eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07c170;
P_0c07c170: /* original 223b, guest PC 0x0c07c170 */
if(!s->budget--) { s->failed_pc=0x0c07c170u; return 0; }
r[2]|=r[3];
goto P_0c07c172;
P_0c07c172: /* original 1f25, guest PC 0x0c07c172 */
if(!s->budget--) { s->failed_pc=0x0c07c172u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c07c174;
P_0c07c174: /* original 2fb6, guest PC 0x0c07c174 */
if(!s->budget--) { s->failed_pc=0x0c07c174u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c176;
P_0c07c176: /* original 2fe6, guest PC 0x0c07c176 */
if(!s->budget--) { s->failed_pc=0x0c07c176u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c178;
P_0c07c178: /* original 50f9, guest PC 0x0c07c178 */
if(!s->budget--) { s->failed_pc=0x0c07c178u; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c07c17a;
P_0c07c17a: /* original 6002, guest PC 0x0c07c17a */
if(!s->budget--) { s->failed_pc=0x0c07c17au; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07c17c;
P_0c07c17c: /* original 4008, guest PC 0x0c07c17c */
if(!s->budget--) { s->failed_pc=0x0c07c17cu; return 0; }
r[0]<<=2;
goto P_0c07c17e;
P_0c07c17e: /* original 059e, guest PC 0x0c07c17e */
if(!s->budget--) { s->failed_pc=0x0c07c17eu; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07c180;
P_0c07c180: /* original 480b, guest PC 0x0c07c180 */
if(!s->budget--) { s->failed_pc=0x0c07c180u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c184u;
r[4]=r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c184u) { target=s->pc; goto dispatch; }
goto P_0c07c184;
P_0c07c182: /* original 6423, guest PC 0x0c07c182 */
if(!s->budget--) { s->failed_pc=0x0c07c182u; return 0; }
r[4]=r[2];
goto P_0c07c184;
P_0c07c184: /* original 7f08, guest PC 0x0c07c184 */
if(!s->budget--) { s->failed_pc=0x0c07c184u; return 0; }
r[15]+=0x00000008u;
goto P_0c07c186;
P_0c07c186: /* original 6403, guest PC 0x0c07c186 */
if(!s->budget--) { s->failed_pc=0x0c07c186u; return 0; }
r[4]=r[0];
goto P_0c07c188;
P_0c07c188: /* original e030, guest PC 0x0c07c188 */
if(!s->budget--) { s->failed_pc=0x0c07c188u; return 0; }
r[0]=0x00000030u;
goto P_0c07c18a;
P_0c07c18a: /* original f4e7, guest PC 0x0c07c18a */
if(!s->budget--) { s->failed_pc=0x0c07c18au; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c18c;
P_0c07c18c: /* original 52f7, guest PC 0x0c07c18c */
if(!s->budget--) { s->failed_pc=0x0c07c18cu; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c07c18e;
P_0c07c18e: /* original 53fa, guest PC 0x0c07c18e */
if(!s->budget--) { s->failed_pc=0x0c07c18eu; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c07c190;
P_0c07c190: /* original 6122, guest PC 0x0c07c190 */
if(!s->budget--) { s->failed_pc=0x0c07c190u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c07c192;
P_0c07c192: /* original 6232, guest PC 0x0c07c192 */
if(!s->budget--) { s->failed_pc=0x0c07c192u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c07c194;
P_0c07c194: /* original 01a7, guest PC 0x0c07c194 */
if(!s->budget--) { s->failed_pc=0x0c07c194u; return 0; }
r[19]=r[1]*r[10];
goto P_0c07c196;
P_0c07c196: /* original 011a, guest PC 0x0c07c196 */
if(!s->budget--) { s->failed_pc=0x0c07c196u; return 0; }
r[1]=r[19];
goto P_0c07c198;
P_0c07c198: /* original 3218, guest PC 0x0c07c198 */
if(!s->budget--) { s->failed_pc=0x0c07c198u; return 0; }
r[2]-=r[1];
goto P_0c07c19a;
P_0c07c19a: /* original 2322, guest PC 0x0c07c19a */
if(!s->budget--) { s->failed_pc=0x0c07c19au; return 0; }
write(ram,r[3],r[2],4);
goto P_0c07c19c;
P_0c07c19c: /* original 50f4, guest PC 0x0c07c19c */
if(!s->budget--) { s->failed_pc=0x0c07c19cu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c07c19e;
P_0c07c19e: /* original e20a, guest PC 0x0c07c19e */
if(!s->budget--) { s->failed_pc=0x0c07c19eu; return 0; }
r[2]=0x0000000au;
goto P_0c07c1a0;
P_0c07c1a0: /* original 03ce, guest PC 0x0c07c1a0 */
if(!s->budget--) { s->failed_pc=0x0c07c1a0u; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c07c1a2;
P_0c07c1a2: /* original 3323, guest PC 0x0c07c1a2 */
if(!s->budget--) { s->failed_pc=0x0c07c1a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c07c1a4;
P_0c07c1a4: /* original 8b2d, guest PC 0x0c07c1a4 */
if(!s->budget--) { s->failed_pc=0x0c07c1a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07c202; }
goto P_0c07c1a6;
P_0c07c1a6: /* original 9386, guest PC 0x0c07c1a6 */
if(!s->budget--) { s->failed_pc=0x0c07c1a6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2b6u,2);
goto P_0c07c1a8;
P_0c07c1a8: /* original 61f2, guest PC 0x0c07c1a8 */
if(!s->budget--) { s->failed_pc=0x0c07c1a8u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c07c1aa;
P_0c07c1aa: /* original 33fc, guest PC 0x0c07c1aa */
if(!s->budget--) { s->failed_pc=0x0c07c1aau; return 0; }
r[3]+=r[15];
goto P_0c07c1ac;
P_0c07c1ac: /* original 313c, guest PC 0x0c07c1ac */
if(!s->budget--) { s->failed_pc=0x0c07c1acu; return 0; }
r[1]+=r[3];
goto P_0c07c1ae;
P_0c07c1ae: /* original 31cc, guest PC 0x0c07c1ae */
if(!s->budget--) { s->failed_pc=0x0c07c1aeu; return 0; }
r[1]+=r[12];
goto P_0c07c1b0;
P_0c07c1b0: /* original 1f17, guest PC 0x0c07c1b0 */
if(!s->budget--) { s->failed_pc=0x0c07c1b0u; return 0; }
write(ram,r[15]+28,r[1],4);
goto P_0c07c1b2;
P_0c07c1b2: /* original 2f16, guest PC 0x0c07c1b2 */
if(!s->budget--) { s->failed_pc=0x0c07c1b2u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c1b4;
P_0c07c1b4: /* original 9281, guest PC 0x0c07c1b4 */
if(!s->budget--) { s->failed_pc=0x0c07c1b4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2bau,2);
goto P_0c07c1b6;
P_0c07c1b6: /* original 51f1, guest PC 0x0c07c1b6 */
if(!s->budget--) { s->failed_pc=0x0c07c1b6u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c07c1b8;
P_0c07c1b8: /* original 32fc, guest PC 0x0c07c1b8 */
if(!s->budget--) { s->failed_pc=0x0c07c1b8u; return 0; }
r[2]+=r[15];
goto P_0c07c1ba;
P_0c07c1ba: /* original 312c, guest PC 0x0c07c1ba */
if(!s->budget--) { s->failed_pc=0x0c07c1bau; return 0; }
r[1]+=r[2];
goto P_0c07c1bc;
P_0c07c1bc: /* original 31cc, guest PC 0x0c07c1bc */
if(!s->budget--) { s->failed_pc=0x0c07c1bcu; return 0; }
r[1]+=r[12];
goto P_0c07c1be;
P_0c07c1be: /* original 1f1b, guest PC 0x0c07c1be */
if(!s->budget--) { s->failed_pc=0x0c07c1beu; return 0; }
write(ram,r[15]+44,r[1],4);
goto P_0c07c1c0;
P_0c07c1c0: /* original d341, guest PC 0x0c07c1c0 */
if(!s->budget--) { s->failed_pc=0x0c07c1c0u; return 0; }
r[3]=read(ram,0x0c07c2c8u,4);
goto P_0c07c1c2;
P_0c07c1c2: /* original 6112, guest PC 0x0c07c1c2 */
if(!s->budget--) { s->failed_pc=0x0c07c1c2u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07c1c4;
P_0c07c1c4: /* original 430b, guest PC 0x0c07c1c4 */
if(!s->budget--) { s->failed_pc=0x0c07c1c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c1c8u;
r[0]=0x0000000au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c1c8u) { target=s->pc; goto dispatch; }
goto P_0c07c1c8;
P_0c07c1c6: /* original e00a, guest PC 0x0c07c1c6 */
if(!s->budget--) { s->failed_pc=0x0c07c1c6u; return 0; }
r[0]=0x0000000au;
goto P_0c07c1c8;
P_0c07c1c8: /* original 63f6, guest PC 0x0c07c1c8 */
if(!s->budget--) { s->failed_pc=0x0c07c1c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c07c1ca;
P_0c07c1ca: /* original e700, guest PC 0x0c07c1ca */
if(!s->budget--) { s->failed_pc=0x0c07c1cau; return 0; }
r[7]=0x00000000u;
goto P_0c07c1cc;
P_0c07c1cc: /* original 66d3, guest PC 0x0c07c1cc */
if(!s->budget--) { s->failed_pc=0x0c07c1ccu; return 0; }
r[6]=r[13];
goto P_0c07c1ce;
P_0c07c1ce: /* original 2302, guest PC 0x0c07c1ce */
if(!s->budget--) { s->failed_pc=0x0c07c1ceu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07c1d0;
P_0c07c1d0: /* original 5cf1, guest PC 0x0c07c1d0 */
if(!s->budget--) { s->failed_pc=0x0c07c1d0u; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c07c1d2;
P_0c07c1d2: /* original 53f8, guest PC 0x0c07c1d2 */
if(!s->budget--) { s->failed_pc=0x0c07c1d2u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c07c1d4;
P_0c07c1d4: /* original 2fb6, guest PC 0x0c07c1d4 */
if(!s->budget--) { s->failed_pc=0x0c07c1d4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c1d6;
P_0c07c1d6: /* original 2fe6, guest PC 0x0c07c1d6 */
if(!s->budget--) { s->failed_pc=0x0c07c1d6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c1d8;
P_0c07c1d8: /* original 2c3b, guest PC 0x0c07c1d8 */
if(!s->budget--) { s->failed_pc=0x0c07c1d8u; return 0; }
r[12]|=r[3];
goto P_0c07c1da;
P_0c07c1da: /* original 50f9, guest PC 0x0c07c1da */
if(!s->budget--) { s->failed_pc=0x0c07c1dau; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c07c1dc;
P_0c07c1dc: /* original 6002, guest PC 0x0c07c1dc */
if(!s->budget--) { s->failed_pc=0x0c07c1dcu; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07c1de;
P_0c07c1de: /* original 4008, guest PC 0x0c07c1de */
if(!s->budget--) { s->failed_pc=0x0c07c1deu; return 0; }
r[0]<<=2;
goto P_0c07c1e0;
P_0c07c1e0: /* original 059e, guest PC 0x0c07c1e0 */
if(!s->budget--) { s->failed_pc=0x0c07c1e0u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07c1e2;
P_0c07c1e2: /* original 480b, guest PC 0x0c07c1e2 */
if(!s->budget--) { s->failed_pc=0x0c07c1e2u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c1e6u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c1e6u) { target=s->pc; goto dispatch; }
goto P_0c07c1e6;
P_0c07c1e4: /* original 64c3, guest PC 0x0c07c1e4 */
if(!s->budget--) { s->failed_pc=0x0c07c1e4u; return 0; }
r[4]=r[12];
goto P_0c07c1e6;
P_0c07c1e6: /* original 7f08, guest PC 0x0c07c1e6 */
if(!s->budget--) { s->failed_pc=0x0c07c1e6u; return 0; }
r[15]+=0x00000008u;
goto P_0c07c1e8;
P_0c07c1e8: /* original 6403, guest PC 0x0c07c1e8 */
if(!s->budget--) { s->failed_pc=0x0c07c1e8u; return 0; }
r[4]=r[0];
goto P_0c07c1ea;
P_0c07c1ea: /* original e030, guest PC 0x0c07c1ea */
if(!s->budget--) { s->failed_pc=0x0c07c1eau; return 0; }
r[0]=0x00000030u;
goto P_0c07c1ec;
P_0c07c1ec: /* original f4e7, guest PC 0x0c07c1ec */
if(!s->budget--) { s->failed_pc=0x0c07c1ecu; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c1ee;
P_0c07c1ee: /* original 52f7, guest PC 0x0c07c1ee */
if(!s->budget--) { s->failed_pc=0x0c07c1eeu; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c07c1f0;
P_0c07c1f0: /* original 53fa, guest PC 0x0c07c1f0 */
if(!s->budget--) { s->failed_pc=0x0c07c1f0u; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c07c1f2;
P_0c07c1f2: /* original 6222, guest PC 0x0c07c1f2 */
if(!s->budget--) { s->failed_pc=0x0c07c1f2u; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c07c1f4;
P_0c07c1f4: /* original 6032, guest PC 0x0c07c1f4 */
if(!s->budget--) { s->failed_pc=0x0c07c1f4u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07c1f6;
P_0c07c1f6: /* original 6123, guest PC 0x0c07c1f6 */
if(!s->budget--) { s->failed_pc=0x0c07c1f6u; return 0; }
r[1]=r[2];
goto P_0c07c1f8;
P_0c07c1f8: /* original 4208, guest PC 0x0c07c1f8 */
if(!s->budget--) { s->failed_pc=0x0c07c1f8u; return 0; }
r[2]<<=2;
goto P_0c07c1fa;
P_0c07c1fa: /* original 321c, guest PC 0x0c07c1fa */
if(!s->budget--) { s->failed_pc=0x0c07c1fau; return 0; }
r[2]+=r[1];
goto P_0c07c1fc;
P_0c07c1fc: /* original 4200, guest PC 0x0c07c1fc */
if(!s->budget--) { s->failed_pc=0x0c07c1fcu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07c1fe;
P_0c07c1fe: /* original 3028, guest PC 0x0c07c1fe */
if(!s->budget--) { s->failed_pc=0x0c07c1feu; return 0; }
r[0]-=r[2];
goto P_0c07c200;
P_0c07c200: /* original 2302, guest PC 0x0c07c200 */
if(!s->budget--) { s->failed_pc=0x0c07c200u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07c202;
P_0c07c202: /* original 5cf1, guest PC 0x0c07c202 */
if(!s->budget--) { s->failed_pc=0x0c07c202u; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c07c204;
P_0c07c204: /* original e700, guest PC 0x0c07c204 */
if(!s->budget--) { s->failed_pc=0x0c07c204u; return 0; }
r[7]=0x00000000u;
goto P_0c07c206;
P_0c07c206: /* original 53f3, guest PC 0x0c07c206 */
if(!s->budget--) { s->failed_pc=0x0c07c206u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c07c208;
P_0c07c208: /* original 66d3, guest PC 0x0c07c208 */
if(!s->budget--) { s->failed_pc=0x0c07c208u; return 0; }
r[6]=r[13];
goto P_0c07c20a;
P_0c07c20a: /* original 2fb6, guest PC 0x0c07c20a */
if(!s->budget--) { s->failed_pc=0x0c07c20au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c20c;
P_0c07c20c: /* original 2fe6, guest PC 0x0c07c20c */
if(!s->budget--) { s->failed_pc=0x0c07c20cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c20e;
P_0c07c20e: /* original 2c3b, guest PC 0x0c07c20e */
if(!s->budget--) { s->failed_pc=0x0c07c20eu; return 0; }
r[12]|=r[3];
goto P_0c07c210;
P_0c07c210: /* original 50fd, guest PC 0x0c07c210 */
if(!s->budget--) { s->failed_pc=0x0c07c210u; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c07c212;
P_0c07c212: /* original 6002, guest PC 0x0c07c212 */
if(!s->budget--) { s->failed_pc=0x0c07c212u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07c214;
P_0c07c214: /* original 4008, guest PC 0x0c07c214 */
if(!s->budget--) { s->failed_pc=0x0c07c214u; return 0; }
r[0]<<=2;
goto P_0c07c216;
P_0c07c216: /* original 059e, guest PC 0x0c07c216 */
if(!s->budget--) { s->failed_pc=0x0c07c216u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07c218;
P_0c07c218: /* original 480b, guest PC 0x0c07c218 */
if(!s->budget--) { s->failed_pc=0x0c07c218u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c21cu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c21cu) { target=s->pc; goto dispatch; }
goto P_0c07c21c;
P_0c07c21a: /* original 64c3, guest PC 0x0c07c21a */
if(!s->budget--) { s->failed_pc=0x0c07c21au; return 0; }
r[4]=r[12];
goto P_0c07c21c;
P_0c07c21c: /* original 7f08, guest PC 0x0c07c21c */
if(!s->budget--) { s->failed_pc=0x0c07c21cu; return 0; }
r[15]+=0x00000008u;
goto P_0c07c21e;
P_0c07c21e: /* original 6403, guest PC 0x0c07c21e */
if(!s->budget--) { s->failed_pc=0x0c07c21eu; return 0; }
r[4]=r[0];
goto P_0c07c220;
P_0c07c220: /* original e030, guest PC 0x0c07c220 */
if(!s->budget--) { s->failed_pc=0x0c07c220u; return 0; }
r[0]=0x00000030u;
goto P_0c07c222;
P_0c07c222: /* original f4e7, guest PC 0x0c07c222 */
if(!s->budget--) { s->failed_pc=0x0c07c222u; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c224;
P_0c07c224: /* original 53f2, guest PC 0x0c07c224 */
if(!s->budget--) { s->failed_pc=0x0c07c224u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07c226;
P_0c07c226: /* original 7301, guest PC 0x0c07c226 */
if(!s->budget--) { s->failed_pc=0x0c07c226u; return 0; }
r[3]+=0x00000001u;
goto P_0c07c228;
P_0c07c228: /* original 1f32, guest PC 0x0c07c228 */
if(!s->budget--) { s->failed_pc=0x0c07c228u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07c22a;
P_0c07c22a: /* original 52fb, guest PC 0x0c07c22a */
if(!s->budget--) { s->failed_pc=0x0c07c22au; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c07c22c;
P_0c07c22c: /* original 7204, guest PC 0x0c07c22c */
if(!s->budget--) { s->failed_pc=0x0c07c22cu; return 0; }
r[2]+=0x00000004u;
goto P_0c07c22e;
P_0c07c22e: /* original 1f2b, guest PC 0x0c07c22e */
if(!s->budget--) { s->failed_pc=0x0c07c22eu; return 0; }
write(ram,r[15]+44,r[2],4);
goto P_0c07c230;
P_0c07c230: /* original 51f3, guest PC 0x0c07c230 */
if(!s->budget--) { s->failed_pc=0x0c07c230u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c07c232;
P_0c07c232: /* original 7150, guest PC 0x0c07c232 */
if(!s->budget--) { s->failed_pc=0x0c07c232u; return 0; }
r[1]+=0x00000050u;
goto P_0c07c234;
P_0c07c234: /* original 1f13, guest PC 0x0c07c234 */
if(!s->budget--) { s->failed_pc=0x0c07c234u; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c07c236;
P_0c07c236: /* original 53f8, guest PC 0x0c07c236 */
if(!s->budget--) { s->failed_pc=0x0c07c236u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c07c238;
P_0c07c238: /* original 7350, guest PC 0x0c07c238 */
if(!s->budget--) { s->failed_pc=0x0c07c238u; return 0; }
r[3]+=0x00000050u;
goto P_0c07c23a;
P_0c07c23a: /* original 1f38, guest PC 0x0c07c23a */
if(!s->budget--) { s->failed_pc=0x0c07c23au; return 0; }
write(ram,r[15]+32,r[3],4);
goto P_0c07c23c;
P_0c07c23c: /* original 51f2, guest PC 0x0c07c23c */
if(!s->budget--) { s->failed_pc=0x0c07c23cu; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c07c23e;
P_0c07c23e: /* original e202, guest PC 0x0c07c23e */
if(!s->budget--) { s->failed_pc=0x0c07c23eu; return 0; }
r[2]=0x00000002u;
goto P_0c07c240;
P_0c07c240: /* original 3123, guest PC 0x0c07c240 */
if(!s->budget--) { s->failed_pc=0x0c07c240u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c07c242;
P_0c07c242: /* original 8901, guest PC 0x0c07c242 */
if(!s->budget--) { s->failed_pc=0x0c07c242u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c248; }
goto P_0c07c244;
P_0c07c244: /* original af72, guest PC 0x0c07c244 */
if(!s->budget--) { s->failed_pc=0x0c07c244u; return 0; }
goto P_0c07c12c;
P_0c07c246: /* original 0009, guest PC 0x0c07c246 */
if(!s->budget--) { s->failed_pc=0x0c07c246u; return 0; }
goto P_0c07c248;
P_0c07c248: /* original 53f9, guest PC 0x0c07c248 */
if(!s->budget--) { s->failed_pc=0x0c07c248u; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c07c24a;
P_0c07c24a: /* original 7301, guest PC 0x0c07c24a */
if(!s->budget--) { s->failed_pc=0x0c07c24au; return 0; }
r[3]+=0x00000001u;
goto P_0c07c24c;
P_0c07c24c: /* original 1f39, guest PC 0x0c07c24c */
if(!s->budget--) { s->failed_pc=0x0c07c24cu; return 0; }
write(ram,r[15]+36,r[3],4);
goto P_0c07c24e;
P_0c07c24e: /* original 51f9, guest PC 0x0c07c24e */
if(!s->budget--) { s->failed_pc=0x0c07c24eu; return 0; }
r[1]=read(ram,r[15]+36,4);
goto P_0c07c250;
P_0c07c250: /* original e202, guest PC 0x0c07c250 */
if(!s->budget--) { s->failed_pc=0x0c07c250u; return 0; }
r[2]=0x00000002u;
goto P_0c07c252;
P_0c07c252: /* original 3123, guest PC 0x0c07c252 */
if(!s->budget--) { s->failed_pc=0x0c07c252u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c07c254;
P_0c07c254: /* original 8901, guest PC 0x0c07c254 */
if(!s->budget--) { s->failed_pc=0x0c07c254u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c25a; }
goto P_0c07c256;
P_0c07c256: /* original af40, guest PC 0x0c07c256 */
if(!s->budget--) { s->failed_pc=0x0c07c256u; return 0; }
goto P_0c07c0da;
P_0c07c258: /* original 0009, guest PC 0x0c07c258 */
if(!s->budget--) { s->failed_pc=0x0c07c258u; return 0; }
goto P_0c07c25a;
P_0c07c25a: /* original 2fb6, guest PC 0x0c07c25a */
if(!s->budget--) { s->failed_pc=0x0c07c25au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c25c;
P_0c07c25c: /* original e700, guest PC 0x0c07c25c */
if(!s->budget--) { s->failed_pc=0x0c07c25cu; return 0; }
r[7]=0x00000000u;
goto P_0c07c25e;
P_0c07c25e: /* original 2fe6, guest PC 0x0c07c25e */
if(!s->budget--) { s->failed_pc=0x0c07c25eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c260;
P_0c07c260: /* original 952c, guest PC 0x0c07c260 */
if(!s->budget--) { s->failed_pc=0x0c07c260u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2bcu,2);
goto P_0c07c262;
P_0c07c262: /* original 942c, guest PC 0x0c07c262 */
if(!s->budget--) { s->failed_pc=0x0c07c262u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2beu,2);
goto P_0c07c264;
P_0c07c264: /* original 480b, guest PC 0x0c07c264 */
if(!s->budget--) { s->failed_pc=0x0c07c264u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c268u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c268u) { target=s->pc; goto dispatch; }
goto P_0c07c268;
P_0c07c266: /* original 66d3, guest PC 0x0c07c266 */
if(!s->budget--) { s->failed_pc=0x0c07c266u; return 0; }
r[6]=r[13];
goto P_0c07c268;
P_0c07c268: /* original 6403, guest PC 0x0c07c268 */
if(!s->budget--) { s->failed_pc=0x0c07c268u; return 0; }
r[4]=r[0];
goto P_0c07c26a;
P_0c07c26a: /* original e030, guest PC 0x0c07c26a */
if(!s->budget--) { s->failed_pc=0x0c07c26au; return 0; }
r[0]=0x00000030u;
goto P_0c07c26c;
P_0c07c26c: /* original f4e7, guest PC 0x0c07c26c */
if(!s->budget--) { s->failed_pc=0x0c07c26cu; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c26e;
P_0c07c26e: /* original e700, guest PC 0x0c07c26e */
if(!s->budget--) { s->failed_pc=0x0c07c26eu; return 0; }
r[7]=0x00000000u;
goto P_0c07c270;
P_0c07c270: /* original 2fb6, guest PC 0x0c07c270 */
if(!s->budget--) { s->failed_pc=0x0c07c270u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c272;
P_0c07c272: /* original 2fe6, guest PC 0x0c07c272 */
if(!s->budget--) { s->failed_pc=0x0c07c272u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c274;
P_0c07c274: /* original 9524, guest PC 0x0c07c274 */
if(!s->budget--) { s->failed_pc=0x0c07c274u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2c0u,2);
goto P_0c07c276;
P_0c07c276: /* original 9424, guest PC 0x0c07c276 */
if(!s->budget--) { s->failed_pc=0x0c07c276u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2c2u,2);
goto P_0c07c278;
P_0c07c278: /* original 480b, guest PC 0x0c07c278 */
if(!s->budget--) { s->failed_pc=0x0c07c278u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c27cu;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c27cu) { target=s->pc; goto dispatch; }
goto P_0c07c27c;
P_0c07c27a: /* original 66d3, guest PC 0x0c07c27a */
if(!s->budget--) { s->failed_pc=0x0c07c27au; return 0; }
r[6]=r[13];
goto P_0c07c27c;
P_0c07c27c: /* original 6403, guest PC 0x0c07c27c */
if(!s->budget--) { s->failed_pc=0x0c07c27cu; return 0; }
r[4]=r[0];
goto P_0c07c27e;
P_0c07c27e: /* original e030, guest PC 0x0c07c27e */
if(!s->budget--) { s->failed_pc=0x0c07c27eu; return 0; }
r[0]=0x00000030u;
goto P_0c07c280;
P_0c07c280: /* original f4e7, guest PC 0x0c07c280 */
if(!s->budget--) { s->failed_pc=0x0c07c280u; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c282;
P_0c07c282: /* original e700, guest PC 0x0c07c282 */
if(!s->budget--) { s->failed_pc=0x0c07c282u; return 0; }
r[7]=0x00000000u;
goto P_0c07c284;
P_0c07c284: /* original 2fb6, guest PC 0x0c07c284 */
if(!s->budget--) { s->failed_pc=0x0c07c284u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c286;
P_0c07c286: /* original 2fe6, guest PC 0x0c07c286 */
if(!s->budget--) { s->failed_pc=0x0c07c286u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c288;
P_0c07c288: /* original 9518, guest PC 0x0c07c288 */
if(!s->budget--) { s->failed_pc=0x0c07c288u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2bcu,2);
goto P_0c07c28a;
P_0c07c28a: /* original 941b, guest PC 0x0c07c28a */
if(!s->budget--) { s->failed_pc=0x0c07c28au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2c4u,2);
goto P_0c07c28c;
P_0c07c28c: /* original 480b, guest PC 0x0c07c28c */
if(!s->budget--) { s->failed_pc=0x0c07c28cu; return 0; }
target=r[8];
r[16]=code_base|0x0c07c290u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c290u) { target=s->pc; goto dispatch; }
goto P_0c07c290;
P_0c07c28e: /* original 66d3, guest PC 0x0c07c28e */
if(!s->budget--) { s->failed_pc=0x0c07c28eu; return 0; }
r[6]=r[13];
goto P_0c07c290;
P_0c07c290: /* original 6403, guest PC 0x0c07c290 */
if(!s->budget--) { s->failed_pc=0x0c07c290u; return 0; }
r[4]=r[0];
goto P_0c07c292;
P_0c07c292: /* original e030, guest PC 0x0c07c292 */
if(!s->budget--) { s->failed_pc=0x0c07c292u; return 0; }
r[0]=0x00000030u;
goto P_0c07c294;
P_0c07c294: /* original f4e7, guest PC 0x0c07c294 */
if(!s->budget--) { s->failed_pc=0x0c07c294u; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c296;
P_0c07c296: /* original e700, guest PC 0x0c07c296 */
if(!s->budget--) { s->failed_pc=0x0c07c296u; return 0; }
r[7]=0x00000000u;
goto P_0c07c298;
P_0c07c298: /* original 2fb6, guest PC 0x0c07c298 */
if(!s->budget--) { s->failed_pc=0x0c07c298u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c29a;
P_0c07c29a: /* original 2fe6, guest PC 0x0c07c29a */
if(!s->budget--) { s->failed_pc=0x0c07c29au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c29c;
P_0c07c29c: /* original 9510, guest PC 0x0c07c29c */
if(!s->budget--) { s->failed_pc=0x0c07c29cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2c0u,2);
goto P_0c07c29e;
P_0c07c29e: /* original 9412, guest PC 0x0c07c29e */
if(!s->budget--) { s->failed_pc=0x0c07c29eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2c6u,2);
goto P_0c07c2a0;
P_0c07c2a0: /* original 480b, guest PC 0x0c07c2a0 */
if(!s->budget--) { s->failed_pc=0x0c07c2a0u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c2a4u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c2a4u) { target=s->pc; goto dispatch; }
goto P_0c07c2a4;
P_0c07c2a2: /* original 66d3, guest PC 0x0c07c2a2 */
if(!s->budget--) { s->failed_pc=0x0c07c2a2u; return 0; }
r[6]=r[13];
goto P_0c07c2a4;
P_0c07c2a4: /* original 6403, guest PC 0x0c07c2a4 */
if(!s->budget--) { s->failed_pc=0x0c07c2a4u; return 0; }
r[4]=r[0];
goto P_0c07c2a6;
P_0c07c2a6: /* original e030, guest PC 0x0c07c2a6 */
if(!s->budget--) { s->failed_pc=0x0c07c2a6u; return 0; }
r[0]=0x00000030u;
goto P_0c07c2a8;
P_0c07c2a8: /* original f4e7, guest PC 0x0c07c2a8 */
if(!s->budget--) { s->failed_pc=0x0c07c2a8u; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c2aa;
P_0c07c2aa: /* original 7f20, guest PC 0x0c07c2aa */
if(!s->budget--) { s->failed_pc=0x0c07c2aau; return 0; }
r[15]+=0x00000020u;
goto P_0c07c2ac;
P_0c07c2ac: /* original d307, guest PC 0x0c07c2ac */
if(!s->budget--) { s->failed_pc=0x0c07c2acu; return 0; }
r[3]=read(ram,0x0c07c2ccu,4);
goto P_0c07c2ae;
P_0c07c2ae: /* original 430b, guest PC 0x0c07c2ae */
if(!s->budget--) { s->failed_pc=0x0c07c2aeu; return 0; }
target=r[3];
r[16]=code_base|0x0c07c2b2u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c2b2u) { target=s->pc; goto dispatch; }
goto P_0c07c2b2;
P_0c07c2b0: /* original e400, guest PC 0x0c07c2b0 */
if(!s->budget--) { s->failed_pc=0x0c07c2b0u; return 0; }
r[4]=0x00000000u;
goto P_0c07c2b2;
P_0c07c2b2: /* original a01e, guest PC 0x0c07c2b2 */
if(!s->budget--) { s->failed_pc=0x0c07c2b2u; return 0; }
goto P_0c07c2f2;
P_0c07c2b4: /* original 0009, guest PC 0x0c07c2b4 */
if(!s->budget--) { s->failed_pc=0x0c07c2b4u; return 0; }
return vf3_matrix_family(0x0c07c2b6u,s,ram);
P_0c07c2d0: /* original 50fc, guest PC 0x0c07c2d0 */
if(!s->budget--) { s->failed_pc=0x0c07c2d0u; return 0; }
r[0]=read(ram,r[15]+48,4);
goto P_0c07c2d2;
P_0c07c2d2: /* original c802, guest PC 0x0c07c2d2 */
if(!s->budget--) { s->failed_pc=0x0c07c2d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c07c2d4;
P_0c07c2d4: /* original 8902, guest PC 0x0c07c2d4 */
if(!s->budget--) { s->failed_pc=0x0c07c2d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c2dc; }
goto P_0c07c2d6;
P_0c07c2d6: /* original d243, guest PC 0x0c07c2d6 */
if(!s->budget--) { s->failed_pc=0x0c07c2d6u; return 0; }
r[2]=read(ram,0x0c07c3e4u,4);
goto P_0c07c2d8;
P_0c07c2d8: /* original 420b, guest PC 0x0c07c2d8 */
if(!s->budget--) { s->failed_pc=0x0c07c2d8u; return 0; }
target=r[2];
r[16]=code_base|0x0c07c2dcu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c2dcu) { target=s->pc; goto dispatch; }
goto P_0c07c2dc;
P_0c07c2da: /* original 0009, guest PC 0x0c07c2da */
if(!s->budget--) { s->failed_pc=0x0c07c2dau; return 0; }
goto P_0c07c2dc;
P_0c07c2dc: /* original 2cc8, guest PC 0x0c07c2dc */
if(!s->budget--) { s->failed_pc=0x0c07c2dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c07c2de;
P_0c07c2de: /* original 8902, guest PC 0x0c07c2de */
if(!s->budget--) { s->failed_pc=0x0c07c2deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c2e6; }
goto P_0c07c2e0;
P_0c07c2e0: /* original d241, guest PC 0x0c07c2e0 */
if(!s->budget--) { s->failed_pc=0x0c07c2e0u; return 0; }
r[2]=read(ram,0x0c07c3e8u,4);
goto P_0c07c2e2;
P_0c07c2e2: /* original 420b, guest PC 0x0c07c2e2 */
if(!s->budget--) { s->failed_pc=0x0c07c2e2u; return 0; }
target=r[2];
r[16]=code_base|0x0c07c2e6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c2e6u) { target=s->pc; goto dispatch; }
goto P_0c07c2e6;
P_0c07c2e4: /* original 0009, guest PC 0x0c07c2e4 */
if(!s->budget--) { s->failed_pc=0x0c07c2e4u; return 0; }
goto P_0c07c2e6;
P_0c07c2e6: /* original 50fc, guest PC 0x0c07c2e6 */
if(!s->budget--) { s->failed_pc=0x0c07c2e6u; return 0; }
r[0]=read(ram,r[15]+48,4);
goto P_0c07c2e8;
P_0c07c2e8: /* original c808, guest PC 0x0c07c2e8 */
if(!s->budget--) { s->failed_pc=0x0c07c2e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c07c2ea;
P_0c07c2ea: /* original 8902, guest PC 0x0c07c2ea */
if(!s->budget--) { s->failed_pc=0x0c07c2eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c2f2; }
goto P_0c07c2ec;
P_0c07c2ec: /* original d13f, guest PC 0x0c07c2ec */
if(!s->budget--) { s->failed_pc=0x0c07c2ecu; return 0; }
r[1]=read(ram,0x0c07c3ecu,4);
goto P_0c07c2ee;
P_0c07c2ee: /* original 410b, guest PC 0x0c07c2ee */
if(!s->budget--) { s->failed_pc=0x0c07c2eeu; return 0; }
target=r[1];
r[16]=code_base|0x0c07c2f2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c2f2u) { target=s->pc; goto dispatch; }
goto P_0c07c2f2;
P_0c07c2f0: /* original 0009, guest PC 0x0c07c2f0 */
if(!s->budget--) { s->failed_pc=0x0c07c2f0u; return 0; }
goto P_0c07c2f2;
P_0c07c2f2: /* original 51fc, guest PC 0x0c07c2f2 */
if(!s->budget--) { s->failed_pc=0x0c07c2f2u; return 0; }
r[1]=read(ram,r[15]+48,4);
goto P_0c07c2f4;
P_0c07c2f4: /* original 9370, guest PC 0x0c07c2f4 */
if(!s->budget--) { s->failed_pc=0x0c07c2f4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c3d8u,2);
goto P_0c07c2f6;
P_0c07c2f6: /* original 2138, guest PC 0x0c07c2f6 */
if(!s->budget--) { s->failed_pc=0x0c07c2f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c07c2f8;
P_0c07c2f8: /* original 8902, guest PC 0x0c07c2f8 */
if(!s->budget--) { s->failed_pc=0x0c07c2f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c300; }
goto P_0c07c2fa;
P_0c07c2fa: /* original d23d, guest PC 0x0c07c2fa */
if(!s->budget--) { s->failed_pc=0x0c07c2fau; return 0; }
r[2]=read(ram,0x0c07c3f0u,4);
goto P_0c07c2fc;
P_0c07c2fc: /* original 420b, guest PC 0x0c07c2fc */
if(!s->budget--) { s->failed_pc=0x0c07c2fcu; return 0; }
target=r[2];
r[16]=code_base|0x0c07c300u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c300u) { target=s->pc; goto dispatch; }
goto P_0c07c300;
P_0c07c2fe: /* original 0009, guest PC 0x0c07c2fe */
if(!s->budget--) { s->failed_pc=0x0c07c2feu; return 0; }
goto P_0c07c300;
P_0c07c300: /* original 52fd, guest PC 0x0c07c300 */
if(!s->budget--) { s->failed_pc=0x0c07c300u; return 0; }
r[2]=read(ram,r[15]+52,4);
goto P_0c07c302;
P_0c07c302: /* original 64e3, guest PC 0x0c07c302 */
if(!s->budget--) { s->failed_pc=0x0c07c302u; return 0; }
r[4]=r[14];
goto P_0c07c304;
P_0c07c304: /* original 53fc, guest PC 0x0c07c304 */
if(!s->budget--) { s->failed_pc=0x0c07c304u; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c07c306;
P_0c07c306: /* original 223b, guest PC 0x0c07c306 */
if(!s->budget--) { s->failed_pc=0x0c07c306u; return 0; }
r[2]|=r[3];
goto P_0c07c308;
P_0c07c308: /* original 1f2c, guest PC 0x0c07c308 */
if(!s->budget--) { s->failed_pc=0x0c07c308u; return 0; }
write(ram,r[15]+48,r[2],4);
goto P_0c07c30a;
P_0c07c30a: /* original d33a, guest PC 0x0c07c30a */
if(!s->budget--) { s->failed_pc=0x0c07c30au; return 0; }
r[3]=read(ram,0x0c07c3f4u,4);
goto P_0c07c30c;
P_0c07c30c: /* original 2322, guest PC 0x0c07c30c */
if(!s->budget--) { s->failed_pc=0x0c07c30cu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c07c30e;
P_0c07c30e: /* original d23a, guest PC 0x0c07c30e */
if(!s->budget--) { s->failed_pc=0x0c07c30eu; return 0; }
r[2]=read(ram,0x0c07c3f8u,4);
goto P_0c07c310;
P_0c07c310: /* original 22e2, guest PC 0x0c07c310 */
if(!s->budget--) { s->failed_pc=0x0c07c310u; return 0; }
write(ram,r[2],r[14],4);
goto P_0c07c312;
P_0c07c312: /* original d13a, guest PC 0x0c07c312 */
if(!s->budget--) { s->failed_pc=0x0c07c312u; return 0; }
r[1]=read(ram,0x0c07c3fcu,4);
goto P_0c07c314;
P_0c07c314: /* original 53fc, guest PC 0x0c07c314 */
if(!s->budget--) { s->failed_pc=0x0c07c314u; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c07c316;
P_0c07c316: /* original 2132, guest PC 0x0c07c316 */
if(!s->budget--) { s->failed_pc=0x0c07c316u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c07c318;
P_0c07c318: /* original 915f, guest PC 0x0c07c318 */
if(!s->budget--) { s->failed_pc=0x0c07c318u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c3dau,2);
goto P_0c07c31a;
P_0c07c31a: /* original 3f1c, guest PC 0x0c07c31a */
if(!s->budget--) { s->failed_pc=0x0c07c31au; return 0; }
r[15]+=r[1];
goto P_0c07c31c;
P_0c07c31c: /* original 4f16, guest PC 0x0c07c31c */
if(!s->budget--) { s->failed_pc=0x0c07c31cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c07c31e;
P_0c07c31e: /* original 4f26, guest PC 0x0c07c31e */
if(!s->budget--) { s->failed_pc=0x0c07c31eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07c320;
P_0c07c320: /* original fef9, guest PC 0x0c07c320 */
if(!s->budget--) { s->failed_pc=0x0c07c320u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07c322;
P_0c07c322: /* original fff9, guest PC 0x0c07c322 */
if(!s->budget--) { s->failed_pc=0x0c07c322u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07c324;
P_0c07c324: /* original 68f6, guest PC 0x0c07c324 */
if(!s->budget--) { s->failed_pc=0x0c07c324u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07c326;
P_0c07c326: /* original 69f6, guest PC 0x0c07c326 */
if(!s->budget--) { s->failed_pc=0x0c07c326u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07c328;
P_0c07c328: /* original 6af6, guest PC 0x0c07c328 */
if(!s->budget--) { s->failed_pc=0x0c07c328u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07c32a;
P_0c07c32a: /* original 6bf6, guest PC 0x0c07c32a */
if(!s->budget--) { s->failed_pc=0x0c07c32au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07c32c;
P_0c07c32c: /* original 6cf6, guest PC 0x0c07c32c */
if(!s->budget--) { s->failed_pc=0x0c07c32cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07c32e;
P_0c07c32e: /* original 6df6, guest PC 0x0c07c32e */
if(!s->budget--) { s->failed_pc=0x0c07c32eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07c330;
P_0c07c330: /* original 000b, guest PC 0x0c07c330 */
if(!s->budget--) { s->failed_pc=0x0c07c330u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07c332: /* original 6ef6, guest PC 0x0c07c332 */
if(!s->budget--) { s->failed_pc=0x0c07c332u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07c334u,s,ram);
P_0c07c722: /* original 4f22, guest PC 0x0c07c722 */
if(!s->budget--) { s->failed_pc=0x0c07c722u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07c724;
P_0c07c724: /* original 7ff4, guest PC 0x0c07c724 */
if(!s->budget--) { s->failed_pc=0x0c07c724u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c07c726;
P_0c07c726: /* original 2f42, guest PC 0x0c07c726 */
if(!s->budget--) { s->failed_pc=0x0c07c726u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07c728;
P_0c07c728: /* original 1f51, guest PC 0x0c07c728 */
if(!s->budget--) { s->failed_pc=0x0c07c728u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c07c72a;
P_0c07c72a: /* original d336, guest PC 0x0c07c72a */
if(!s->budget--) { s->failed_pc=0x0c07c72au; return 0; }
r[3]=read(ram,0x0c07c804u,4);
goto P_0c07c72c;
P_0c07c72c: /* original 1f32, guest PC 0x0c07c72c */
if(!s->budget--) { s->failed_pc=0x0c07c72cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07c72e;
P_0c07c72e: /* original 6ef2, guest PC 0x0c07c72e */
if(!s->budget--) { s->failed_pc=0x0c07c72eu; return 0; }
tmp=read(ram,r[15],4);
r[14]=tmp;
goto P_0c07c730;
P_0c07c730: /* original 9053, guest PC 0x0c07c730 */
if(!s->budget--) { s->failed_pc=0x0c07c730u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c7dau,2);
goto P_0c07c732;
P_0c07c732: /* original 03ee, guest PC 0x0c07c732 */
if(!s->budget--) { s->failed_pc=0x0c07c732u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c07c734;
P_0c07c734: /* original 2338, guest PC 0x0c07c734 */
if(!s->budget--) { s->failed_pc=0x0c07c734u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07c736;
P_0c07c736: /* original 8913, guest PC 0x0c07c736 */
if(!s->budget--) { s->failed_pc=0x0c07c736u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c760; }
goto P_0c07c738;
P_0c07c738: /* original 03ee, guest PC 0x0c07c738 */
if(!s->budget--) { s->failed_pc=0x0c07c738u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c07c73a;
P_0c07c73a: /* original 73ff, guest PC 0x0c07c73a */
if(!s->budget--) { s->failed_pc=0x0c07c73au; return 0; }
r[3]+=0xffffffffu;
goto P_0c07c73c;
P_0c07c73c: /* original 0e36, guest PC 0x0c07c73c */
if(!s->budget--) { s->failed_pc=0x0c07c73cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c07c73e;
P_0c07c73e: /* original 02ee, guest PC 0x0c07c73e */
if(!s->budget--) { s->failed_pc=0x0c07c73eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c07c740;
P_0c07c740: /* original 2228, guest PC 0x0c07c740 */
if(!s->budget--) { s->failed_pc=0x0c07c740u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07c742;
P_0c07c742: /* original 8b0d, guest PC 0x0c07c742 */
if(!s->budget--) { s->failed_pc=0x0c07c742u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07c760; }
goto P_0c07c744;
P_0c07c744: /* original d330, guest PC 0x0c07c744 */
if(!s->budget--) { s->failed_pc=0x0c07c744u; return 0; }
r[3]=read(ram,0x0c07c808u,4);
goto P_0c07c746;
P_0c07c746: /* original 54f2, guest PC 0x0c07c746 */
if(!s->budget--) { s->failed_pc=0x0c07c746u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07c748;
P_0c07c748: /* original 430b, guest PC 0x0c07c748 */
if(!s->budget--) { s->failed_pc=0x0c07c748u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c74cu;
r[4]+=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c74cu) { target=s->pc; goto dispatch; }
goto P_0c07c74c;
P_0c07c74a: /* original 7412, guest PC 0x0c07c74a */
if(!s->budget--) { s->failed_pc=0x0c07c74au; return 0; }
r[4]+=0x00000012u;
goto P_0c07c74c;
P_0c07c74c: /* original 600c, guest PC 0x0c07c74c */
if(!s->budget--) { s->failed_pc=0x0c07c74cu; return 0; }
r[0]=r[0]&255u;
goto P_0c07c74e;
P_0c07c74e: /* original 2008, guest PC 0x0c07c74e */
if(!s->budget--) { s->failed_pc=0x0c07c74eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c07c750;
P_0c07c750: /* original 8b01, guest PC 0x0c07c750 */
if(!s->budget--) { s->failed_pc=0x0c07c750u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07c756; }
goto P_0c07c752;
P_0c07c752: /* original a001, guest PC 0x0c07c752 */
if(!s->budget--) { s->failed_pc=0x0c07c752u; return 0; }
r[5]=0x0000000bu;
goto P_0c07c758;
P_0c07c754: /* original e50b, guest PC 0x0c07c754 */
if(!s->budget--) { s->failed_pc=0x0c07c754u; return 0; }
r[5]=0x0000000bu;
goto P_0c07c756;
P_0c07c756: /* original e50a, guest PC 0x0c07c756 */
if(!s->budget--) { s->failed_pc=0x0c07c756u; return 0; }
r[5]=0x0000000au;
goto P_0c07c758;
P_0c07c758: /* original d32c, guest PC 0x0c07c758 */
if(!s->budget--) { s->failed_pc=0x0c07c758u; return 0; }
r[3]=read(ram,0x0c07c80cu,4);
goto P_0c07c75a;
P_0c07c75a: /* original 943f, guest PC 0x0c07c75a */
if(!s->budget--) { s->failed_pc=0x0c07c75au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c7dcu,2);
goto P_0c07c75c;
P_0c07c75c: /* original 430b, guest PC 0x0c07c75c */
if(!s->budget--) { s->failed_pc=0x0c07c75cu; return 0; }
target=r[3];
r[16]=code_base|0x0c07c760u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c760u) { target=s->pc; goto dispatch; }
goto P_0c07c760;
P_0c07c75e: /* original 34ec, guest PC 0x0c07c75e */
if(!s->budget--) { s->failed_pc=0x0c07c75eu; return 0; }
r[4]+=r[14];
goto P_0c07c760;
P_0c07c760: /* original d22b, guest PC 0x0c07c760 */
if(!s->budget--) { s->failed_pc=0x0c07c760u; return 0; }
r[2]=read(ram,0x0c07c810u,4);
goto P_0c07c762;
P_0c07c762: /* original 420b, guest PC 0x0c07c762 */
if(!s->budget--) { s->failed_pc=0x0c07c762u; return 0; }
target=r[2];
r[16]=code_base|0x0c07c766u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c766u) { target=s->pc; goto dispatch; }
goto P_0c07c766;
P_0c07c764: /* original 0009, guest PC 0x0c07c764 */
if(!s->budget--) { s->failed_pc=0x0c07c764u; return 0; }
goto P_0c07c766;
P_0c07c766: /* original 64f2, guest PC 0x0c07c766 */
if(!s->budget--) { s->failed_pc=0x0c07c766u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07c768;
P_0c07c768: /* original 55f1, guest PC 0x0c07c768 */
if(!s->budget--) { s->failed_pc=0x0c07c768u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07c76a;
P_0c07c76a: /* original 7f0c, guest PC 0x0c07c76a */
if(!s->budget--) { s->failed_pc=0x0c07c76au; return 0; }
r[15]+=0x0000000cu;
goto P_0c07c76c;
P_0c07c76c: /* original 4f26, guest PC 0x0c07c76c */
if(!s->budget--) { s->failed_pc=0x0c07c76cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07c76e;
P_0c07c76e: /* original a95b, guest PC 0x0c07c76e */
if(!s->budget--) { s->failed_pc=0x0c07c76eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ba28;
P_0c07c770: /* original 6ef6, guest PC 0x0c07c770 */
if(!s->budget--) { s->failed_pc=0x0c07c770u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07c772u,s,ram);
P_0c07ca2a: /* original 4f22, guest PC 0x0c07ca2a */
if(!s->budget--) { s->failed_pc=0x0c07ca2au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ca2c;
P_0c07ca2c: /* original e210, guest PC 0x0c07ca2c */
if(!s->budget--) { s->failed_pc=0x0c07ca2cu; return 0; }
r[2]=0x00000010u;
goto P_0c07ca2e;
P_0c07ca2e: /* original 6023, guest PC 0x0c07ca2e */
if(!s->budget--) { s->failed_pc=0x0c07ca2eu; return 0; }
r[0]=r[2];
goto P_0c07ca30;
P_0c07ca30: /* original 7ff4, guest PC 0x0c07ca30 */
if(!s->budget--) { s->failed_pc=0x0c07ca30u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c07ca32;
P_0c07ca32: /* original 2f42, guest PC 0x0c07ca32 */
if(!s->budget--) { s->failed_pc=0x0c07ca32u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07ca34;
P_0c07ca34: /* original 1f51, guest PC 0x0c07ca34 */
if(!s->budget--) { s->failed_pc=0x0c07ca34u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c07ca36;
P_0c07ca36: /* original 63f2, guest PC 0x0c07ca36 */
if(!s->budget--) { s->failed_pc=0x0c07ca36u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07ca38;
P_0c07ca38: /* original 1f32, guest PC 0x0c07ca38 */
if(!s->budget--) { s->failed_pc=0x0c07ca38u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07ca3a;
P_0c07ca3a: /* original e300, guest PC 0x0c07ca3a */
if(!s->budget--) { s->failed_pc=0x0c07ca3au; return 0; }
r[3]=0x00000000u;
goto P_0c07ca3c;
P_0c07ca3c: /* original d415, guest PC 0x0c07ca3c */
if(!s->budget--) { s->failed_pc=0x0c07ca3cu; return 0; }
r[4]=read(ram,0x0c07ca94u,4);
goto P_0c07ca3e;
P_0c07ca3e: /* original 1436, guest PC 0x0c07ca3e */
if(!s->budget--) { s->failed_pc=0x0c07ca3eu; return 0; }
write(ram,r[4]+24,r[3],4);
goto P_0c07ca40;
P_0c07ca40: /* original 1425, guest PC 0x0c07ca40 */
if(!s->budget--) { s->failed_pc=0x0c07ca40u; return 0; }
write(ram,r[4]+20,r[2],4);
goto P_0c07ca42;
P_0c07ca42: /* original 034c, guest PC 0x0c07ca42 */
if(!s->budget--) { s->failed_pc=0x0c07ca42u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c07ca44;
P_0c07ca44: /* original 7301, guest PC 0x0c07ca44 */
if(!s->budget--) { s->failed_pc=0x0c07ca44u; return 0; }
r[3]+=0x00000001u;
goto P_0c07ca46;
P_0c07ca46: /* original 0434, guest PC 0x0c07ca46 */
if(!s->budget--) { s->failed_pc=0x0c07ca46u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c07ca48;
P_0c07ca48: /* original 9314, guest PC 0x0c07ca48 */
if(!s->budget--) { s->failed_pc=0x0c07ca48u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ca74u,2);
goto P_0c07ca4a;
P_0c07ca4a: /* original d213, guest PC 0x0c07ca4a */
if(!s->budget--) { s->failed_pc=0x0c07ca4au; return 0; }
r[2]=read(ram,0x0c07ca98u,4);
goto P_0c07ca4c;
P_0c07ca4c: /* original 9511, guest PC 0x0c07ca4c */
if(!s->budget--) { s->failed_pc=0x0c07ca4cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ca72u,2);
goto P_0c07ca4e;
P_0c07ca4e: /* original 54f2, guest PC 0x0c07ca4e */
if(!s->budget--) { s->failed_pc=0x0c07ca4eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07ca50;
P_0c07ca50: /* original 420b, guest PC 0x0c07ca50 */
if(!s->budget--) { s->failed_pc=0x0c07ca50u; return 0; }
target=r[2];
r[16]=code_base|0x0c07ca54u;
r[4]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ca54u) { target=s->pc; goto dispatch; }
goto P_0c07ca54;
P_0c07ca52: /* original 343c, guest PC 0x0c07ca52 */
if(!s->budget--) { s->failed_pc=0x0c07ca52u; return 0; }
r[4]+=r[3];
goto P_0c07ca54;
P_0c07ca54: /* original d311, guest PC 0x0c07ca54 */
if(!s->budget--) { s->failed_pc=0x0c07ca54u; return 0; }
r[3]=read(ram,0x0c07ca9cu,4);
goto P_0c07ca56;
P_0c07ca56: /* original 64f2, guest PC 0x0c07ca56 */
if(!s->budget--) { s->failed_pc=0x0c07ca56u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07ca58;
P_0c07ca58: /* original 55f1, guest PC 0x0c07ca58 */
if(!s->budget--) { s->failed_pc=0x0c07ca58u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07ca5a;
P_0c07ca5a: /* original 7f0c, guest PC 0x0c07ca5a */
if(!s->budget--) { s->failed_pc=0x0c07ca5au; return 0; }
r[15]+=0x0000000cu;
goto P_0c07ca5c;
P_0c07ca5c: /* original 432b, guest PC 0x0c07ca5c */
if(!s->budget--) { s->failed_pc=0x0c07ca5cu; return 0; }
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
P_0c07ca5e: /* original 4f26, guest PC 0x0c07ca5e */
if(!s->budget--) { s->failed_pc=0x0c07ca5eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c07ca60u,s,ram);
P_0c07e1ca: /* original 4f22, guest PC 0x0c07e1ca */
if(!s->budget--) { s->failed_pc=0x0c07e1cau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07e1cc;
P_0c07e1cc: /* original 7ff8, guest PC 0x0c07e1cc */
if(!s->budget--) { s->failed_pc=0x0c07e1ccu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07e1ce;
P_0c07e1ce: /* original 1f41, guest PC 0x0c07e1ce */
if(!s->budget--) { s->failed_pc=0x0c07e1ceu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c07e1d0;
P_0c07e1d0: /* original 2f52, guest PC 0x0c07e1d0 */
if(!s->budget--) { s->failed_pc=0x0c07e1d0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c07e1d2;
P_0c07e1d2: /* original 9439, guest PC 0x0c07e1d2 */
if(!s->budget--) { s->failed_pc=0x0c07e1d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e248u,2);
goto P_0c07e1d4;
P_0c07e1d4: /* original de1f, guest PC 0x0c07e1d4 */
if(!s->budget--) { s->failed_pc=0x0c07e1d4u; return 0; }
r[14]=read(ram,0x0c07e254u,4);
goto P_0c07e1d6;
P_0c07e1d6: /* original 1e45, guest PC 0x0c07e1d6 */
if(!s->budget--) { s->failed_pc=0x0c07e1d6u; return 0; }
write(ram,r[14]+20,r[4],4);
goto P_0c07e1d8;
P_0c07e1d8: /* original d120, guest PC 0x0c07e1d8 */
if(!s->budget--) { s->failed_pc=0x0c07e1d8u; return 0; }
r[1]=read(ram,0x0c07e25cu,4);
goto P_0c07e1da;
P_0c07e1da: /* original d31f, guest PC 0x0c07e1da */
if(!s->budget--) { s->failed_pc=0x0c07e1dau; return 0; }
r[3]=read(ram,0x0c07e258u,4);
goto P_0c07e1dc;
P_0c07e1dc: /* original 6212, guest PC 0x0c07e1dc */
if(!s->budget--) { s->failed_pc=0x0c07e1dcu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c07e1de;
P_0c07e1de: /* original 2238, guest PC 0x0c07e1de */
if(!s->budget--) { s->failed_pc=0x0c07e1deu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07e1e0;
P_0c07e1e0: /* original 8d04, guest PC 0x0c07e1e0 */
if(!s->budget--) { s->failed_pc=0x0c07e1e0u; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(cond) { goto P_0c07e1ec; }
goto P_0c07e1e4;
P_0c07e1e2: /* original e600, guest PC 0x0c07e1e2 */
if(!s->budget--) { s->failed_pc=0x0c07e1e2u; return 0; }
r[6]=0x00000000u;
goto P_0c07e1e4;
P_0c07e1e4: /* original 50e5, guest PC 0x0c07e1e4 */
if(!s->budget--) { s->failed_pc=0x0c07e1e4u; return 0; }
r[0]=read(ram,r[14]+20,4);
goto P_0c07e1e6;
P_0c07e1e6: /* original 9230, guest PC 0x0c07e1e6 */
if(!s->budget--) { s->failed_pc=0x0c07e1e6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e24au,2);
goto P_0c07e1e8;
P_0c07e1e8: /* original 2029, guest PC 0x0c07e1e8 */
if(!s->budget--) { s->failed_pc=0x0c07e1e8u; return 0; }
r[0]&=r[2];
goto P_0c07e1ea;
P_0c07e1ea: /* original 1e05, guest PC 0x0c07e1ea */
if(!s->budget--) { s->failed_pc=0x0c07e1eau; return 0; }
write(ram,r[14]+20,r[0],4);
goto P_0c07e1ec;
P_0c07e1ec: /* original d31c, guest PC 0x0c07e1ec */
if(!s->budget--) { s->failed_pc=0x0c07e1ecu; return 0; }
r[3]=read(ram,0x0c07e260u,4);
goto P_0c07e1ee;
P_0c07e1ee: /* original 942d, guest PC 0x0c07e1ee */
if(!s->budget--) { s->failed_pc=0x0c07e1eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e24cu,2);
goto P_0c07e1f0;
P_0c07e1f0: /* original 430b, guest PC 0x0c07e1f0 */
if(!s->budget--) { s->failed_pc=0x0c07e1f0u; return 0; }
target=r[3];
r[16]=code_base|0x0c07e1f4u;
r[5]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07e1f4u) { target=s->pc; goto dispatch; }
goto P_0c07e1f4;
P_0c07e1f2: /* original e501, guest PC 0x0c07e1f2 */
if(!s->budget--) { s->failed_pc=0x0c07e1f2u; return 0; }
r[5]=0x00000001u;
goto P_0c07e1f4;
P_0c07e1f4: /* original c71b, guest PC 0x0c07e1f4 */
if(!s->budget--) { s->failed_pc=0x0c07e1f4u; return 0; }
r[0]=0x0c07e264u;
goto P_0c07e1f6;
P_0c07e1f6: /* original e200, guest PC 0x0c07e1f6 */
if(!s->budget--) { s->failed_pc=0x0c07e1f6u; return 0; }
r[2]=0x00000000u;
goto P_0c07e1f8;
P_0c07e1f8: /* original 2f26, guest PC 0x0c07e1f8 */
if(!s->budget--) { s->failed_pc=0x0c07e1f8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e1fa;
P_0c07e1fa: /* original 9728, guest PC 0x0c07e1fa */
if(!s->budget--) { s->failed_pc=0x0c07e1fau; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e24eu,2);
goto P_0c07e1fc;
P_0c07e1fc: /* original d51c, guest PC 0x0c07e1fc */
if(!s->budget--) { s->failed_pc=0x0c07e1fcu; return 0; }
r[5]=read(ram,0x0c07e270u,4);
goto P_0c07e1fe;
P_0c07e1fe: /* original d61b, guest PC 0x0c07e1fe */
if(!s->budget--) { s->failed_pc=0x0c07e1feu; return 0; }
r[6]=read(ram,0x0c07e26cu,4);
goto P_0c07e200;
P_0c07e200: /* original 9424, guest PC 0x0c07e200 */
if(!s->budget--) { s->failed_pc=0x0c07e200u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e24cu,2);
goto P_0c07e202;
P_0c07e202: /* original d31c, guest PC 0x0c07e202 */
if(!s->budget--) { s->failed_pc=0x0c07e202u; return 0; }
r[3]=read(ram,0x0c07e274u,4);
goto P_0c07e204;
P_0c07e204: /* original f508, guest PC 0x0c07e204 */
if(!s->budget--) { s->failed_pc=0x0c07e204u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c07e206;
P_0c07e206: /* original c718, guest PC 0x0c07e206 */
if(!s->budget--) { s->failed_pc=0x0c07e206u; return 0; }
r[0]=0x0c07e268u;
goto P_0c07e208;
P_0c07e208: /* original 430b, guest PC 0x0c07e208 */
if(!s->budget--) { s->failed_pc=0x0c07e208u; return 0; }
target=r[3];
r[16]=code_base|0x0c07e20cu;
vf3_matrix_load(s,ram,4,r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07e20cu) { target=s->pc; goto dispatch; }
goto P_0c07e20c;
P_0c07e20a: /* original f408, guest PC 0x0c07e20a */
if(!s->budget--) { s->failed_pc=0x0c07e20au; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c07e20c;
P_0c07e20c: /* original e010, guest PC 0x0c07e20c */
if(!s->budget--) { s->failed_pc=0x0c07e20cu; return 0; }
r[0]=0x00000010u;
goto P_0c07e20e;
P_0c07e20e: /* original 02ec, guest PC 0x0c07e20e */
if(!s->budget--) { s->failed_pc=0x0c07e20eu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e210;
P_0c07e210: /* original 7201, guest PC 0x0c07e210 */
if(!s->budget--) { s->failed_pc=0x0c07e210u; return 0; }
r[2]+=0x00000001u;
goto P_0c07e212;
P_0c07e212: /* original 0e24, guest PC 0x0c07e212 */
if(!s->budget--) { s->failed_pc=0x0c07e212u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c07e214;
P_0c07e214: /* original 55f1, guest PC 0x0c07e214 */
if(!s->budget--) { s->failed_pc=0x0c07e214u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07e216;
P_0c07e216: /* original 54f2, guest PC 0x0c07e216 */
if(!s->budget--) { s->failed_pc=0x0c07e216u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07e218;
P_0c07e218: /* original 7f0c, guest PC 0x0c07e218 */
if(!s->budget--) { s->failed_pc=0x0c07e218u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07e21a;
P_0c07e21a: /* original 4f26, guest PC 0x0c07e21a */
if(!s->budget--) { s->failed_pc=0x0c07e21au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07e21c;
P_0c07e21c: /* original d316, guest PC 0x0c07e21c */
if(!s->budget--) { s->failed_pc=0x0c07e21cu; return 0; }
r[3]=read(ram,0x0c07e278u,4);
goto P_0c07e21e;
P_0c07e21e: /* original 432b, guest PC 0x0c07e21e */
if(!s->budget--) { s->failed_pc=0x0c07e21eu; return 0; }
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
P_0c07e220: /* original 6ef6, guest PC 0x0c07e220 */
if(!s->budget--) { s->failed_pc=0x0c07e220u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07e222u,s,ram);
P_0c07eba8: /* original 4f22, guest PC 0x0c07eba8 */
if(!s->budget--) { s->failed_pc=0x0c07eba8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ebaa;
P_0c07ebaa: /* original 7ffc, guest PC 0x0c07ebaa */
if(!s->budget--) { s->failed_pc=0x0c07ebaau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07ebac;
P_0c07ebac: /* original 2f42, guest PC 0x0c07ebac */
if(!s->budget--) { s->failed_pc=0x0c07ebacu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07ebae;
P_0c07ebae: /* original d31a, guest PC 0x0c07ebae */
if(!s->budget--) { s->failed_pc=0x0c07ebaeu; return 0; }
r[3]=read(ram,0x0c07ec18u,4);
goto P_0c07ebb0;
P_0c07ebb0: /* original de17, guest PC 0x0c07ebb0 */
if(!s->budget--) { s->failed_pc=0x0c07ebb0u; return 0; }
r[14]=read(ram,0x0c07ec10u,4);
goto P_0c07ebb2;
P_0c07ebb2: /* original 6230, guest PC 0x0c07ebb2 */
if(!s->budget--) { s->failed_pc=0x0c07ebb2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c07ebb4;
P_0c07ebb4: /* original 7201, guest PC 0x0c07ebb4 */
if(!s->budget--) { s->failed_pc=0x0c07ebb4u; return 0; }
r[2]+=0x00000001u;
goto P_0c07ebb6;
P_0c07ebb6: /* original 2320, guest PC 0x0c07ebb6 */
if(!s->budget--) { s->failed_pc=0x0c07ebb6u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c07ebb8;
P_0c07ebb8: /* original d31f, guest PC 0x0c07ebb8 */
if(!s->budget--) { s->failed_pc=0x0c07ebb8u; return 0; }
r[3]=read(ram,0x0c07ec38u,4);
goto P_0c07ebba;
P_0c07ebba: /* original 1c34, guest PC 0x0c07ebba */
if(!s->budget--) { s->failed_pc=0x0c07ebbau; return 0; }
write(ram,r[12]+16,r[3],4);
goto P_0c07ebbc;
P_0c07ebbc: /* original d21f, guest PC 0x0c07ebbc */
if(!s->budget--) { s->failed_pc=0x0c07ebbcu; return 0; }
r[2]=read(ram,0x0c07ec3cu,4);
goto P_0c07ebbe;
P_0c07ebbe: /* original 420b, guest PC 0x0c07ebbe */
if(!s->budget--) { s->failed_pc=0x0c07ebbeu; return 0; }
target=r[2];
r[16]=code_base|0x0c07ebc2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ebc2u) { target=s->pc; goto dispatch; }
goto P_0c07ebc2;
P_0c07ebc0: /* original 64e3, guest PC 0x0c07ebc0 */
if(!s->budget--) { s->failed_pc=0x0c07ebc0u; return 0; }
r[4]=r[14];
goto P_0c07ebc2;
P_0c07ebc2: /* original e320, guest PC 0x0c07ebc2 */
if(!s->budget--) { s->failed_pc=0x0c07ebc2u; return 0; }
r[3]=0x00000020u;
goto P_0c07ebc4;
P_0c07ebc4: /* original 9520, guest PC 0x0c07ebc4 */
if(!s->budget--) { s->failed_pc=0x0c07ebc4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ec08u,2);
goto P_0c07ebc6;
P_0c07ebc6: /* original e618, guest PC 0x0c07ebc6 */
if(!s->budget--) { s->failed_pc=0x0c07ebc6u; return 0; }
r[6]=0x00000018u;
goto P_0c07ebc8;
P_0c07ebc8: /* original 2f36, guest PC 0x0c07ebc8 */
if(!s->budget--) { s->failed_pc=0x0c07ebc8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ebca;
P_0c07ebca: /* original d216, guest PC 0x0c07ebca */
if(!s->budget--) { s->failed_pc=0x0c07ebcau; return 0; }
r[2]=read(ram,0x0c07ec24u,4);
goto P_0c07ebcc;
P_0c07ebcc: /* original e701, guest PC 0x0c07ebcc */
if(!s->budget--) { s->failed_pc=0x0c07ebccu; return 0; }
r[7]=0x00000001u;
goto P_0c07ebce;
P_0c07ebce: /* original 420b, guest PC 0x0c07ebce */
if(!s->budget--) { s->failed_pc=0x0c07ebceu; return 0; }
target=r[2];
r[16]=code_base|0x0c07ebd2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ebd2u) { target=s->pc; goto dispatch; }
goto P_0c07ebd2;
P_0c07ebd0: /* original 64e3, guest PC 0x0c07ebd0 */
if(!s->budget--) { s->failed_pc=0x0c07ebd0u; return 0; }
r[4]=r[14];
goto P_0c07ebd2;
P_0c07ebd2: /* original 9d1a, guest PC 0x0c07ebd2 */
if(!s->budget--) { s->failed_pc=0x0c07ebd2u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ec0au,2);
goto P_0c07ebd4;
P_0c07ebd4: /* original e320, guest PC 0x0c07ebd4 */
if(!s->budget--) { s->failed_pc=0x0c07ebd4u; return 0; }
r[3]=0x00000020u;
goto P_0c07ebd6;
P_0c07ebd6: /* original e618, guest PC 0x0c07ebd6 */
if(!s->budget--) { s->failed_pc=0x0c07ebd6u; return 0; }
r[6]=0x00000018u;
goto P_0c07ebd8;
P_0c07ebd8: /* original 2f36, guest PC 0x0c07ebd8 */
if(!s->budget--) { s->failed_pc=0x0c07ebd8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ebda;
P_0c07ebda: /* original d212, guest PC 0x0c07ebda */
if(!s->budget--) { s->failed_pc=0x0c07ebdau; return 0; }
r[2]=read(ram,0x0c07ec24u,4);
goto P_0c07ebdc;
P_0c07ebdc: /* original 65d3, guest PC 0x0c07ebdc */
if(!s->budget--) { s->failed_pc=0x0c07ebdcu; return 0; }
r[5]=r[13];
goto P_0c07ebde;
P_0c07ebde: /* original e701, guest PC 0x0c07ebde */
if(!s->budget--) { s->failed_pc=0x0c07ebdeu; return 0; }
r[7]=0x00000001u;
goto P_0c07ebe0;
P_0c07ebe0: /* original 420b, guest PC 0x0c07ebe0 */
if(!s->budget--) { s->failed_pc=0x0c07ebe0u; return 0; }
target=r[2];
r[16]=code_base|0x0c07ebe4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ebe4u) { target=s->pc; goto dispatch; }
goto P_0c07ebe4;
P_0c07ebe2: /* original 64e3, guest PC 0x0c07ebe2 */
if(!s->budget--) { s->failed_pc=0x0c07ebe2u; return 0; }
r[4]=r[14];
goto P_0c07ebe4;
P_0c07ebe4: /* original d315, guest PC 0x0c07ebe4 */
if(!s->budget--) { s->failed_pc=0x0c07ebe4u; return 0; }
r[3]=read(ram,0x0c07ec3cu,4);
goto P_0c07ebe6;
P_0c07ebe6: /* original 9511, guest PC 0x0c07ebe6 */
if(!s->budget--) { s->failed_pc=0x0c07ebe6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ec0cu,2);
goto P_0c07ebe8;
P_0c07ebe8: /* original 430b, guest PC 0x0c07ebe8 */
if(!s->budget--) { s->failed_pc=0x0c07ebe8u; return 0; }
target=r[3];
r[16]=code_base|0x0c07ebecu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ebecu) { target=s->pc; goto dispatch; }
goto P_0c07ebec;
P_0c07ebea: /* original 64e3, guest PC 0x0c07ebea */
if(!s->budget--) { s->failed_pc=0x0c07ebeau; return 0; }
r[4]=r[14];
goto P_0c07ebec;
P_0c07ebec: /* original 900f, guest PC 0x0c07ebec */
if(!s->budget--) { s->failed_pc=0x0c07ebecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ec0eu,2);
goto P_0c07ebee;
P_0c07ebee: /* original e202, guest PC 0x0c07ebee */
if(!s->budget--) { s->failed_pc=0x0c07ebeeu; return 0; }
r[2]=0x00000002u;
goto P_0c07ebf0;
P_0c07ebf0: /* original 65d3, guest PC 0x0c07ebf0 */
if(!s->budget--) { s->failed_pc=0x0c07ebf0u; return 0; }
r[5]=r[13];
goto P_0c07ebf2;
P_0c07ebf2: /* original 0c26, guest PC 0x0c07ebf2 */
if(!s->budget--) { s->failed_pc=0x0c07ebf2u; return 0; }
write(ram,r[12]+r[0],r[2],4);
goto P_0c07ebf4;
P_0c07ebf4: /* original 54f2, guest PC 0x0c07ebf4 */
if(!s->budget--) { s->failed_pc=0x0c07ebf4u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07ebf6;
P_0c07ebf6: /* original 7f0c, guest PC 0x0c07ebf6 */
if(!s->budget--) { s->failed_pc=0x0c07ebf6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07ebf8;
P_0c07ebf8: /* original 4f26, guest PC 0x0c07ebf8 */
if(!s->budget--) { s->failed_pc=0x0c07ebf8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ebfa;
P_0c07ebfa: /* original 6cf6, guest PC 0x0c07ebfa */
if(!s->budget--) { s->failed_pc=0x0c07ebfau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07ebfc;
P_0c07ebfc: /* original 6df6, guest PC 0x0c07ebfc */
if(!s->budget--) { s->failed_pc=0x0c07ebfcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ebfe;
P_0c07ebfe: /* original a01f, guest PC 0x0c07ebfe */
if(!s->budget--) { s->failed_pc=0x0c07ebfeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ec40;
P_0c07ec00: /* original 6ef6, guest PC 0x0c07ec00 */
if(!s->budget--) { s->failed_pc=0x0c07ec00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07ec02u,s,ram);
P_0c07ec40: /* original 2fe6, guest PC 0x0c07ec40 */
if(!s->budget--) { s->failed_pc=0x0c07ec40u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ec42;
P_0c07ec42: /* original 6e43, guest PC 0x0c07ec42 */
if(!s->budget--) { s->failed_pc=0x0c07ec42u; return 0; }
r[14]=r[4];
goto P_0c07ec44;
P_0c07ec44: /* original 2fd6, guest PC 0x0c07ec44 */
if(!s->budget--) { s->failed_pc=0x0c07ec44u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ec46;
P_0c07ec46: /* original 66e3, guest PC 0x0c07ec46 */
if(!s->budget--) { s->failed_pc=0x0c07ec46u; return 0; }
r[6]=r[14];
goto P_0c07ec48;
P_0c07ec48: /* original 2fc6, guest PC 0x0c07ec48 */
if(!s->budget--) { s->failed_pc=0x0c07ec48u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ec4a;
P_0c07ec4a: /* original 4f22, guest PC 0x0c07ec4a */
if(!s->budget--) { s->failed_pc=0x0c07ec4au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ec4c;
P_0c07ec4c: /* original d33b, guest PC 0x0c07ec4c */
if(!s->budget--) { s->failed_pc=0x0c07ec4cu; return 0; }
r[3]=read(ram,0x0c07ed3cu,4);
goto P_0c07ec4e;
P_0c07ec4e: /* original 7ff4, guest PC 0x0c07ec4e */
if(!s->budget--) { s->failed_pc=0x0c07ec4eu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c07ec50;
P_0c07ec50: /* original 1f32, guest PC 0x0c07ec50 */
if(!s->budget--) { s->failed_pc=0x0c07ec50u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07ec52;
P_0c07ec52: /* original d53b, guest PC 0x0c07ec52 */
if(!s->budget--) { s->failed_pc=0x0c07ec52u; return 0; }
r[5]=read(ram,0x0c07ed40u,4);
goto P_0c07ec54;
P_0c07ec54: /* original 6453, guest PC 0x0c07ec54 */
if(!s->budget--) { s->failed_pc=0x0c07ec54u; return 0; }
r[4]=r[5];
goto P_0c07ec56;
P_0c07ec56: /* original 1f51, guest PC 0x0c07ec56 */
if(!s->budget--) { s->failed_pc=0x0c07ec56u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c07ec58;
P_0c07ec58: /* original 9363, guest PC 0x0c07ec58 */
if(!s->budget--) { s->failed_pc=0x0c07ec58u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed22u,2);
goto P_0c07ec5a;
P_0c07ec5a: /* original 7458, guest PC 0x0c07ec5a */
if(!s->budget--) { s->failed_pc=0x0c07ec5au; return 0; }
r[4]+=0x00000058u;
goto P_0c07ec5c;
P_0c07ec5c: /* original 335c, guest PC 0x0c07ec5c */
if(!s->budget--) { s->failed_pc=0x0c07ec5cu; return 0; }
r[3]+=r[5];
goto P_0c07ec5e;
P_0c07ec5e: /* original 2f32, guest PC 0x0c07ec5e */
if(!s->budget--) { s->failed_pc=0x0c07ec5eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07ec60;
P_0c07ec60: /* original 9060, guest PC 0x0c07ec60 */
if(!s->budget--) { s->failed_pc=0x0c07ec60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed24u,2);
goto P_0c07ec62;
P_0c07ec62: /* original 006e, guest PC 0x0c07ec62 */
if(!s->budget--) { s->failed_pc=0x0c07ec62u; return 0; }
r[0]=read(ram,r[6]+r[0],4);
goto P_0c07ec64;
P_0c07ec64: /* original 8801, guest PC 0x0c07ec64 */
if(!s->budget--) { s->failed_pc=0x0c07ec64u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07ec66;
P_0c07ec66: /* original 8f08, guest PC 0x0c07ec66 */
if(!s->budget--) { s->failed_pc=0x0c07ec66u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(!cond) { goto P_0c07ec7a; }
goto P_0c07ec6a;
P_0c07ec68: /* original 6503, guest PC 0x0c07ec68 */
if(!s->budget--) { s->failed_pc=0x0c07ec68u; return 0; }
r[5]=r[0];
goto P_0c07ec6a;
P_0c07ec6a: /* original d236, guest PC 0x0c07ec6a */
if(!s->budget--) { s->failed_pc=0x0c07ec6au; return 0; }
r[2]=read(ram,0x0c07ed44u,4);
goto P_0c07ec6c;
P_0c07ec6c: /* original 420b, guest PC 0x0c07ec6c */
if(!s->budget--) { s->failed_pc=0x0c07ec6cu; return 0; }
target=r[2];
r[16]=code_base|0x0c07ec70u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ec70u) { target=s->pc; goto dispatch; }
goto P_0c07ec70;
P_0c07ec6e: /* original 0009, guest PC 0x0c07ec6e */
if(!s->budget--) { s->failed_pc=0x0c07ec6eu; return 0; }
goto P_0c07ec70;
P_0c07ec70: /* original d335, guest PC 0x0c07ec70 */
if(!s->budget--) { s->failed_pc=0x0c07ec70u; return 0; }
r[3]=read(ram,0x0c07ed48u,4);
goto P_0c07ec72;
P_0c07ec72: /* original 9458, guest PC 0x0c07ec72 */
if(!s->budget--) { s->failed_pc=0x0c07ec72u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed26u,2);
goto P_0c07ec74;
P_0c07ec74: /* original 66f2, guest PC 0x0c07ec74 */
if(!s->budget--) { s->failed_pc=0x0c07ec74u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c07ec76;
P_0c07ec76: /* original 430b, guest PC 0x0c07ec76 */
if(!s->budget--) { s->failed_pc=0x0c07ec76u; return 0; }
target=r[3];
r[16]=code_base|0x0c07ec7au;
r[5]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ec7au) { target=s->pc; goto dispatch; }
goto P_0c07ec7a;
P_0c07ec78: /* original 55f1, guest PC 0x0c07ec78 */
if(!s->budget--) { s->failed_pc=0x0c07ec78u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07ec7a;
P_0c07ec7a: /* original dd34, guest PC 0x0c07ec7a */
if(!s->budget--) { s->failed_pc=0x0c07ec7au; return 0; }
r[13]=read(ram,0x0c07ed4cu,4);
goto P_0c07ec7c;
P_0c07ec7c: /* original d234, guest PC 0x0c07ec7c */
if(!s->budget--) { s->failed_pc=0x0c07ec7cu; return 0; }
r[2]=read(ram,0x0c07ed50u,4);
goto P_0c07ec7e;
P_0c07ec7e: /* original 54d2, guest PC 0x0c07ec7e */
if(!s->budget--) { s->failed_pc=0x0c07ec7eu; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c07ec80;
P_0c07ec80: /* original 2428, guest PC 0x0c07ec80 */
if(!s->budget--) { s->failed_pc=0x0c07ec80u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c07ec82;
P_0c07ec82: /* original 8906, guest PC 0x0c07ec82 */
if(!s->budget--) { s->failed_pc=0x0c07ec82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ec92; }
goto P_0c07ec84;
P_0c07ec84: /* original 7f0c, guest PC 0x0c07ec84 */
if(!s->budget--) { s->failed_pc=0x0c07ec84u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07ec86;
P_0c07ec86: /* original 64e3, guest PC 0x0c07ec86 */
if(!s->budget--) { s->failed_pc=0x0c07ec86u; return 0; }
r[4]=r[14];
goto P_0c07ec88;
P_0c07ec88: /* original 4f26, guest PC 0x0c07ec88 */
if(!s->budget--) { s->failed_pc=0x0c07ec88u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ec8a;
P_0c07ec8a: /* original 6cf6, guest PC 0x0c07ec8a */
if(!s->budget--) { s->failed_pc=0x0c07ec8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07ec8c;
P_0c07ec8c: /* original 6df6, guest PC 0x0c07ec8c */
if(!s->budget--) { s->failed_pc=0x0c07ec8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ec8e;
P_0c07ec8e: /* original a033, guest PC 0x0c07ec8e */
if(!s->budget--) { s->failed_pc=0x0c07ec8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ecf8;
P_0c07ec90: /* original 6ef6, guest PC 0x0c07ec90 */
if(!s->budget--) { s->failed_pc=0x0c07ec90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ec92;
P_0c07ec92: /* original d330, guest PC 0x0c07ec92 */
if(!s->budget--) { s->failed_pc=0x0c07ec92u; return 0; }
r[3]=read(ram,0x0c07ed54u,4);
goto P_0c07ec94;
P_0c07ec94: /* original 54f2, guest PC 0x0c07ec94 */
if(!s->budget--) { s->failed_pc=0x0c07ec94u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07ec96;
P_0c07ec96: /* original 430b, guest PC 0x0c07ec96 */
if(!s->budget--) { s->failed_pc=0x0c07ec96u; return 0; }
target=r[3];
r[16]=code_base|0x0c07ec9au;
r[4]+=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ec9au) { target=s->pc; goto dispatch; }
goto P_0c07ec9a;
P_0c07ec98: /* original 7412, guest PC 0x0c07ec98 */
if(!s->budget--) { s->failed_pc=0x0c07ec98u; return 0; }
r[4]+=0x00000012u;
goto P_0c07ec9a;
P_0c07ec9a: /* original 6c0c, guest PC 0x0c07ec9a */
if(!s->budget--) { s->failed_pc=0x0c07ec9au; return 0; }
r[12]=r[0]&255u;
goto P_0c07ec9c;
P_0c07ec9c: /* original e018, guest PC 0x0c07ec9c */
if(!s->budget--) { s->failed_pc=0x0c07ec9cu; return 0; }
r[0]=0x00000018u;
goto P_0c07ec9e;
P_0c07ec9e: /* original 05dc, guest PC 0x0c07ec9e */
if(!s->budget--) { s->failed_pc=0x0c07ec9eu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07eca0;
P_0c07eca0: /* original 9042, guest PC 0x0c07eca0 */
if(!s->budget--) { s->failed_pc=0x0c07eca0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed28u,2);
goto P_0c07eca2;
P_0c07eca2: /* original 04de, guest PC 0x0c07eca2 */
if(!s->budget--) { s->failed_pc=0x0c07eca2u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c07eca4;
P_0c07eca4: /* original e046, guest PC 0x0c07eca4 */
if(!s->budget--) { s->failed_pc=0x0c07eca4u; return 0; }
r[0]=0x00000046u;
goto P_0c07eca6;
P_0c07eca6: /* original 064d, guest PC 0x0c07eca6 */
if(!s->budget--) { s->failed_pc=0x0c07eca6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07eca8;
P_0c07eca8: /* original 903f, guest PC 0x0c07eca8 */
if(!s->budget--) { s->failed_pc=0x0c07eca8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed2au,2);
goto P_0c07ecaa;
P_0c07ecaa: /* original 074d, guest PC 0x0c07ecaa */
if(!s->budget--) { s->failed_pc=0x0c07ecaau; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07ecac;
P_0c07ecac: /* original 645e, guest PC 0x0c07ecac */
if(!s->budget--) { s->failed_pc=0x0c07ecacu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c07ecae;
P_0c07ecae: /* original 2448, guest PC 0x0c07ecae */
if(!s->budget--) { s->failed_pc=0x0c07ecaeu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07ecb0;
P_0c07ecb0: /* original 8b0b, guest PC 0x0c07ecb0 */
if(!s->budget--) { s->failed_pc=0x0c07ecb0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ecca; }
goto P_0c07ecb2;
P_0c07ecb2: /* original 677f, guest PC 0x0c07ecb2 */
if(!s->budget--) { s->failed_pc=0x0c07ecb2u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c07ecb4;
P_0c07ecb4: /* original 666f, guest PC 0x0c07ecb4 */
if(!s->budget--) { s->failed_pc=0x0c07ecb4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c07ecb6;
P_0c07ecb6: /* original 3670, guest PC 0x0c07ecb6 */
if(!s->budget--) { s->failed_pc=0x0c07ecb6u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[7])!=0);
goto P_0c07ecb8;
P_0c07ecb8: /* original 8b03, guest PC 0x0c07ecb8 */
if(!s->budget--) { s->failed_pc=0x0c07ecb8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ecc2; }
goto P_0c07ecba;
P_0c07ecba: /* original 9737, guest PC 0x0c07ecba */
if(!s->budget--) { s->failed_pc=0x0c07ecbau; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed2cu,2);
goto P_0c07ecbc;
P_0c07ecbc: /* original e510, guest PC 0x0c07ecbc */
if(!s->budget--) { s->failed_pc=0x0c07ecbcu; return 0; }
r[5]=0x00000010u;
goto P_0c07ecbe;
P_0c07ecbe: /* original a014, guest PC 0x0c07ecbe */
if(!s->budget--) { s->failed_pc=0x0c07ecbeu; return 0; }
r[6]=0x0000001eu;
goto P_0c07ecea;
P_0c07ecc0: /* original e61e, guest PC 0x0c07ecc0 */
if(!s->budget--) { s->failed_pc=0x0c07ecc0u; return 0; }
r[6]=0x0000001eu;
goto P_0c07ecc2;
P_0c07ecc2: /* original 9734, guest PC 0x0c07ecc2 */
if(!s->budget--) { s->failed_pc=0x0c07ecc2u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed2eu,2);
goto P_0c07ecc4;
P_0c07ecc4: /* original e51a, guest PC 0x0c07ecc4 */
if(!s->budget--) { s->failed_pc=0x0c07ecc4u; return 0; }
r[5]=0x0000001au;
goto P_0c07ecc6;
P_0c07ecc6: /* original a010, guest PC 0x0c07ecc6 */
if(!s->budget--) { s->failed_pc=0x0c07ecc6u; return 0; }
r[6]=0x00000018u;
goto P_0c07ecea;
P_0c07ecc8: /* original e618, guest PC 0x0c07ecc8 */
if(!s->budget--) { s->failed_pc=0x0c07ecc8u; return 0; }
r[6]=0x00000018u;
goto P_0c07ecca;
P_0c07ecca: /* original 6043, guest PC 0x0c07ecca */
if(!s->budget--) { s->failed_pc=0x0c07eccau; return 0; }
r[0]=r[4];
goto P_0c07eccc;
P_0c07eccc: /* original 8801, guest PC 0x0c07eccc */
if(!s->budget--) { s->failed_pc=0x0c07ecccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07ecce;
P_0c07ecce: /* original 8f07, guest PC 0x0c07ecce */
if(!s->budget--) { s->failed_pc=0x0c07ecceu; return 0; }
cond=r[17]&1u;
r[6]=0x00000014u;
if(!cond) { goto P_0c07ece0; }
goto P_0c07ecd2;
P_0c07ecd0: /* original e614, guest PC 0x0c07ecd0 */
if(!s->budget--) { s->failed_pc=0x0c07ecd0u; return 0; }
r[6]=0x00000014u;
goto P_0c07ecd2;
P_0c07ecd2: /* original 972d, guest PC 0x0c07ecd2 */
if(!s->budget--) { s->failed_pc=0x0c07ecd2u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed30u,2);
goto P_0c07ecd4;
P_0c07ecd4: /* original 2cc8, guest PC 0x0c07ecd4 */
if(!s->budget--) { s->failed_pc=0x0c07ecd4u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c07ecd6;
P_0c07ecd6: /* original 8d08, guest PC 0x0c07ecd6 */
if(!s->budget--) { s->failed_pc=0x0c07ecd6u; return 0; }
cond=r[17]&1u;
r[5]=0x00000015u;
if(cond) { goto P_0c07ecea; }
goto P_0c07ecda;
P_0c07ecd8: /* original e515, guest PC 0x0c07ecd8 */
if(!s->budget--) { s->failed_pc=0x0c07ecd8u; return 0; }
r[5]=0x00000015u;
goto P_0c07ecda;
P_0c07ecda: /* original 972a, guest PC 0x0c07ecda */
if(!s->budget--) { s->failed_pc=0x0c07ecdau; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed32u,2);
goto P_0c07ecdc;
P_0c07ecdc: /* original a005, guest PC 0x0c07ecdc */
if(!s->budget--) { s->failed_pc=0x0c07ecdcu; return 0; }
r[5]=0x0000000cu;
goto P_0c07ecea;
P_0c07ecde: /* original e50c, guest PC 0x0c07ecde */
if(!s->budget--) { s->failed_pc=0x0c07ecdeu; return 0; }
r[5]=0x0000000cu;
goto P_0c07ece0;
P_0c07ece0: /* original 9728, guest PC 0x0c07ece0 */
if(!s->budget--) { s->failed_pc=0x0c07ece0u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed34u,2);
goto P_0c07ece2;
P_0c07ece2: /* original 2cc8, guest PC 0x0c07ece2 */
if(!s->budget--) { s->failed_pc=0x0c07ece2u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c07ece4;
P_0c07ece4: /* original 8d01, guest PC 0x0c07ece4 */
if(!s->budget--) { s->failed_pc=0x0c07ece4u; return 0; }
cond=r[17]&1u;
r[5]=0x00000012u;
if(cond) { goto P_0c07ecea; }
goto P_0c07ece8;
P_0c07ece6: /* original e512, guest PC 0x0c07ece6 */
if(!s->budget--) { s->failed_pc=0x0c07ece6u; return 0; }
r[5]=0x00000012u;
goto P_0c07ece8;
P_0c07ece8: /* original 9725, guest PC 0x0c07ece8 */
if(!s->budget--) { s->failed_pc=0x0c07ece8u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed36u,2);
goto P_0c07ecea;
P_0c07ecea: /* original 7f0c, guest PC 0x0c07ecea */
if(!s->budget--) { s->failed_pc=0x0c07eceau; return 0; }
r[15]+=0x0000000cu;
goto P_0c07ecec;
P_0c07ecec: /* original 64e3, guest PC 0x0c07ecec */
if(!s->budget--) { s->failed_pc=0x0c07ececu; return 0; }
r[4]=r[14];
goto P_0c07ecee;
P_0c07ecee: /* original 4f26, guest PC 0x0c07ecee */
if(!s->budget--) { s->failed_pc=0x0c07eceeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ecf0;
P_0c07ecf0: /* original 6cf6, guest PC 0x0c07ecf0 */
if(!s->budget--) { s->failed_pc=0x0c07ecf0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07ecf2;
P_0c07ecf2: /* original 6df6, guest PC 0x0c07ecf2 */
if(!s->budget--) { s->failed_pc=0x0c07ecf2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ecf4;
P_0c07ecf4: /* original a030, guest PC 0x0c07ecf4 */
if(!s->budget--) { s->failed_pc=0x0c07ecf4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ed58;
P_0c07ecf6: /* original 6ef6, guest PC 0x0c07ecf6 */
if(!s->budget--) { s->failed_pc=0x0c07ecf6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ecf8;
P_0c07ecf8: /* original d514, guest PC 0x0c07ecf8 */
if(!s->budget--) { s->failed_pc=0x0c07ecf8u; return 0; }
r[5]=read(ram,0x0c07ed4cu,4);
goto P_0c07ecfa;
P_0c07ecfa: /* original e029, guest PC 0x0c07ecfa */
if(!s->budget--) { s->failed_pc=0x0c07ecfau; return 0; }
r[0]=0x00000029u;
goto P_0c07ecfc;
P_0c07ecfc: /* original 075c, guest PC 0x0c07ecfc */
if(!s->budget--) { s->failed_pc=0x0c07ecfcu; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07ecfe;
P_0c07ecfe: /* original e01d, guest PC 0x0c07ecfe */
if(!s->budget--) { s->failed_pc=0x0c07ecfeu; return 0; }
r[0]=0x0000001du;
goto P_0c07ed00;
P_0c07ed00: /* original 055c, guest PC 0x0c07ed00 */
if(!s->budget--) { s->failed_pc=0x0c07ed00u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07ed02;
P_0c07ed02: /* original 667e, guest PC 0x0c07ed02 */
if(!s->budget--) { s->failed_pc=0x0c07ed02u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c07ed04;
P_0c07ed04: /* original 6063, guest PC 0x0c07ed04 */
if(!s->budget--) { s->failed_pc=0x0c07ed04u; return 0; }
r[0]=r[6];
goto P_0c07ed06;
P_0c07ed06: /* original 8803, guest PC 0x0c07ed06 */
if(!s->budget--) { s->failed_pc=0x0c07ed06u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c07ed08;
P_0c07ed08: /* original 8d03, guest PC 0x0c07ed08 */
if(!s->budget--) { s->failed_pc=0x0c07ed08u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(cond) { goto P_0c07ed12; }
goto P_0c07ed0c;
P_0c07ed0a: /* original 7501, guest PC 0x0c07ed0a */
if(!s->budget--) { s->failed_pc=0x0c07ed0au; return 0; }
r[5]+=0x00000001u;
goto P_0c07ed0c;
P_0c07ed0c: /* original 655e, guest PC 0x0c07ed0c */
if(!s->budget--) { s->failed_pc=0x0c07ed0cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c07ed0e;
P_0c07ed0e: /* original 3650, guest PC 0x0c07ed0e */
if(!s->budget--) { s->failed_pc=0x0c07ed0eu; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[5])!=0);
goto P_0c07ed10;
P_0c07ed10: /* original 8b03, guest PC 0x0c07ed10 */
if(!s->budget--) { s->failed_pc=0x0c07ed10u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ed1a; }
goto P_0c07ed12;
P_0c07ed12: /* original 9711, guest PC 0x0c07ed12 */
if(!s->budget--) { s->failed_pc=0x0c07ed12u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed38u,2);
goto P_0c07ed14;
P_0c07ed14: /* original e61e, guest PC 0x0c07ed14 */
if(!s->budget--) { s->failed_pc=0x0c07ed14u; return 0; }
r[6]=0x0000001eu;
goto P_0c07ed16;
P_0c07ed16: /* original a01f, guest PC 0x0c07ed16 */
if(!s->budget--) { s->failed_pc=0x0c07ed16u; return 0; }
r[5]=0x00000014u;
goto P_0c07ed58;
P_0c07ed18: /* original e514, guest PC 0x0c07ed18 */
if(!s->budget--) { s->failed_pc=0x0c07ed18u; return 0; }
r[5]=0x00000014u;
goto P_0c07ed1a;
P_0c07ed1a: /* original 970e, guest PC 0x0c07ed1a */
if(!s->budget--) { s->failed_pc=0x0c07ed1au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ed3au,2);
goto P_0c07ed1c;
P_0c07ed1c: /* original e61e, guest PC 0x0c07ed1c */
if(!s->budget--) { s->failed_pc=0x0c07ed1cu; return 0; }
r[6]=0x0000001eu;
goto P_0c07ed1e;
P_0c07ed1e: /* original a01b, guest PC 0x0c07ed1e */
if(!s->budget--) { s->failed_pc=0x0c07ed1eu; return 0; }
r[5]=0x00000014u;
goto P_0c07ed58;
P_0c07ed20: /* original e514, guest PC 0x0c07ed20 */
if(!s->budget--) { s->failed_pc=0x0c07ed20u; return 0; }
r[5]=0x00000014u;
return vf3_matrix_family(0x0c07ed22u,s,ram);
P_0c07ed58: /* original 2fe6, guest PC 0x0c07ed58 */
if(!s->budget--) { s->failed_pc=0x0c07ed58u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ed5a;
P_0c07ed5a: /* original 6053, guest PC 0x0c07ed5a */
if(!s->budget--) { s->failed_pc=0x0c07ed5au; return 0; }
r[0]=r[5];
goto P_0c07ed5c;
P_0c07ed5c: /* original 2fd6, guest PC 0x0c07ed5c */
if(!s->budget--) { s->failed_pc=0x0c07ed5cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ed5e;
P_0c07ed5e: /* original e307, guest PC 0x0c07ed5e */
if(!s->budget--) { s->failed_pc=0x0c07ed5eu; return 0; }
r[3]=0x00000007u;
goto P_0c07ed60;
P_0c07ed60: /* original 2fc6, guest PC 0x0c07ed60 */
if(!s->budget--) { s->failed_pc=0x0c07ed60u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ed62;
P_0c07ed62: /* original 6c6f, guest PC 0x0c07ed62 */
if(!s->budget--) { s->failed_pc=0x0c07ed62u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c07ed64;
P_0c07ed64: /* original 2fb6, guest PC 0x0c07ed64 */
if(!s->budget--) { s->failed_pc=0x0c07ed64u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ed66;
P_0c07ed66: /* original 6b5f, guest PC 0x0c07ed66 */
if(!s->budget--) { s->failed_pc=0x0c07ed66u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c07ed68;
P_0c07ed68: /* original 2fa6, guest PC 0x0c07ed68 */
if(!s->budget--) { s->failed_pc=0x0c07ed68u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ed6a;
P_0c07ed6a: /* original 6eb3, guest PC 0x0c07ed6a */
if(!s->budget--) { s->failed_pc=0x0c07ed6au; return 0; }
r[14]=r[11];
goto P_0c07ed6c;
P_0c07ed6c: /* original 2f96, guest PC 0x0c07ed6c */
if(!s->budget--) { s->failed_pc=0x0c07ed6cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ed6e;
P_0c07ed6e: /* original 6973, guest PC 0x0c07ed6e */
if(!s->budget--) { s->failed_pc=0x0c07ed6eu; return 0; }
r[9]=r[7];
goto P_0c07ed70;
P_0c07ed70: /* original 2f86, guest PC 0x0c07ed70 */
if(!s->budget--) { s->failed_pc=0x0c07ed70u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ed72;
P_0c07ed72: /* original e200, guest PC 0x0c07ed72 */
if(!s->budget--) { s->failed_pc=0x0c07ed72u; return 0; }
r[2]=0x00000000u;
goto P_0c07ed74;
P_0c07ed74: /* original 4f22, guest PC 0x0c07ed74 */
if(!s->budget--) { s->failed_pc=0x0c07ed74u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ed76;
P_0c07ed76: /* original 4c3c, guest PC 0x0c07ed76 */
if(!s->budget--) { s->failed_pc=0x0c07ed76u; return 0; }
r[12]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[12]>>((-r[3])&31u)):((int32_t)r[12]<0?0xffffffffu:0)):r[12]<<(r[3]&31u);
goto P_0c07ed78;
P_0c07ed78: /* original 6723, guest PC 0x0c07ed78 */
if(!s->budget--) { s->failed_pc=0x0c07ed78u; return 0; }
r[7]=r[2];
goto P_0c07ed7a;
P_0c07ed7a: /* original 4e00, guest PC 0x0c07ed7a */
if(!s->budget--) { s->failed_pc=0x0c07ed7au; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07ed7c;
P_0c07ed7c: /* original 7ffc, guest PC 0x0c07ed7c */
if(!s->budget--) { s->failed_pc=0x0c07ed7cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07ed7e;
P_0c07ed7e: /* original 2f42, guest PC 0x0c07ed7e */
if(!s->budget--) { s->failed_pc=0x0c07ed7eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07ed80;
P_0c07ed80: /* original 659d, guest PC 0x0c07ed80 */
if(!s->budget--) { s->failed_pc=0x0c07ed80u; return 0; }
r[5]=r[9]&65535u;
goto P_0c07ed82;
P_0c07ed82: /* original 814a, guest PC 0x0c07ed82 */
if(!s->budget--) { s->failed_pc=0x0c07ed82u; return 0; }
write(ram,r[4]+20,r[0],2);
goto P_0c07ed84;
P_0c07ed84: /* original 6063, guest PC 0x0c07ed84 */
if(!s->budget--) { s->failed_pc=0x0c07ed84u; return 0; }
r[0]=r[6];
goto P_0c07ed86;
P_0c07ed86: /* original 814b, guest PC 0x0c07ed86 */
if(!s->budget--) { s->failed_pc=0x0c07ed86u; return 0; }
write(ram,r[4]+22,r[0],2);
goto P_0c07ed88;
P_0c07ed88: /* original 6093, guest PC 0x0c07ed88 */
if(!s->budget--) { s->failed_pc=0x0c07ed88u; return 0; }
r[0]=r[9];
goto P_0c07ed8a;
P_0c07ed8a: /* original 814c, guest PC 0x0c07ed8a */
if(!s->budget--) { s->failed_pc=0x0c07ed8au; return 0; }
write(ram,r[4]+24,r[0],2);
goto P_0c07ed8c;
P_0c07ed8c: /* original 2ecb, guest PC 0x0c07ed8c */
if(!s->budget--) { s->failed_pc=0x0c07ed8cu; return 0; }
r[14]|=r[12];
goto P_0c07ed8e;
P_0c07ed8e: /* original da39, guest PC 0x0c07ed8e */
if(!s->budget--) { s->failed_pc=0x0c07ed8eu; return 0; }
r[10]=read(ram,0x0c07ee74u,4);
goto P_0c07ed90;
P_0c07ed90: /* original d837, guest PC 0x0c07ed90 */
if(!s->budget--) { s->failed_pc=0x0c07ed90u; return 0; }
r[8]=read(ram,0x0c07ee70u,4);
goto P_0c07ed92;
P_0c07ed92: /* original 66a3, guest PC 0x0c07ed92 */
if(!s->budget--) { s->failed_pc=0x0c07ed92u; return 0; }
r[6]=r[10];
goto P_0c07ed94;
P_0c07ed94: /* original 2f26, guest PC 0x0c07ed94 */
if(!s->budget--) { s->failed_pc=0x0c07ed94u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ed96;
P_0c07ed96: /* original 480b, guest PC 0x0c07ed96 */
if(!s->budget--) { s->failed_pc=0x0c07ed96u; return 0; }
target=r[8];
r[16]=code_base|0x0c07ed9au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ed9au) { target=s->pc; goto dispatch; }
goto P_0c07ed9a;
P_0c07ed98: /* original 64e3, guest PC 0x0c07ed98 */
if(!s->budget--) { s->failed_pc=0x0c07ed98u; return 0; }
r[4]=r[14];
goto P_0c07ed9a;
P_0c07ed9a: /* original 9361, guest PC 0x0c07ed9a */
if(!s->budget--) { s->failed_pc=0x0c07ed9au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee60u,2);
goto P_0c07ed9c;
P_0c07ed9c: /* original 6d9f, guest PC 0x0c07ed9c */
if(!s->budget--) { s->failed_pc=0x0c07ed9cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[9];
goto P_0c07ed9e;
P_0c07ed9e: /* original 3d30, guest PC 0x0c07ed9e */
if(!s->budget--) { s->failed_pc=0x0c07ed9eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c07eda0;
P_0c07eda0: /* original 8f0a, guest PC 0x0c07eda0 */
if(!s->budget--) { s->failed_pc=0x0c07eda0u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(!cond) { goto P_0c07edb8; }
goto P_0c07eda4;
P_0c07eda2: /* original 7f04, guest PC 0x0c07eda2 */
if(!s->budget--) { s->failed_pc=0x0c07eda2u; return 0; }
r[15]+=0x00000004u;
goto P_0c07eda4;
P_0c07eda4: /* original 6eb3, guest PC 0x0c07eda4 */
if(!s->budget--) { s->failed_pc=0x0c07eda4u; return 0; }
r[14]=r[11];
goto P_0c07eda6;
P_0c07eda6: /* original 7e0d, guest PC 0x0c07eda6 */
if(!s->budget--) { s->failed_pc=0x0c07eda6u; return 0; }
r[14]+=0x0000000du;
goto P_0c07eda8;
P_0c07eda8: /* original e200, guest PC 0x0c07eda8 */
if(!s->budget--) { s->failed_pc=0x0c07eda8u; return 0; }
r[2]=0x00000000u;
goto P_0c07edaa;
P_0c07edaa: /* original 4e00, guest PC 0x0c07edaa */
if(!s->budget--) { s->failed_pc=0x0c07edaau; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07edac;
P_0c07edac: /* original 6723, guest PC 0x0c07edac */
if(!s->budget--) { s->failed_pc=0x0c07edacu; return 0; }
r[7]=r[2];
goto P_0c07edae;
P_0c07edae: /* original 2ecb, guest PC 0x0c07edae */
if(!s->budget--) { s->failed_pc=0x0c07edaeu; return 0; }
r[14]|=r[12];
goto P_0c07edb0;
P_0c07edb0: /* original 2f26, guest PC 0x0c07edb0 */
if(!s->budget--) { s->failed_pc=0x0c07edb0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07edb2;
P_0c07edb2: /* original 9556, guest PC 0x0c07edb2 */
if(!s->budget--) { s->failed_pc=0x0c07edb2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee62u,2);
goto P_0c07edb4;
P_0c07edb4: /* original a00c, guest PC 0x0c07edb4 */
if(!s->budget--) { s->failed_pc=0x0c07edb4u; return 0; }
r[6]=r[10];
goto P_0c07edd0;
P_0c07edb6: /* original 66a3, guest PC 0x0c07edb6 */
if(!s->budget--) { s->failed_pc=0x0c07edb6u; return 0; }
r[6]=r[10];
goto P_0c07edb8;
P_0c07edb8: /* original 9254, guest PC 0x0c07edb8 */
if(!s->budget--) { s->failed_pc=0x0c07edb8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee64u,2);
goto P_0c07edba;
P_0c07edba: /* original 3d20, guest PC 0x0c07edba */
if(!s->budget--) { s->failed_pc=0x0c07edbau; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c07edbc;
P_0c07edbc: /* original 8b0c, guest PC 0x0c07edbc */
if(!s->budget--) { s->failed_pc=0x0c07edbcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07edd8; }
goto P_0c07edbe;
P_0c07edbe: /* original 6eb3, guest PC 0x0c07edbe */
if(!s->budget--) { s->failed_pc=0x0c07edbeu; return 0; }
r[14]=r[11];
goto P_0c07edc0;
P_0c07edc0: /* original 7e0c, guest PC 0x0c07edc0 */
if(!s->budget--) { s->failed_pc=0x0c07edc0u; return 0; }
r[14]+=0x0000000cu;
goto P_0c07edc2;
P_0c07edc2: /* original e100, guest PC 0x0c07edc2 */
if(!s->budget--) { s->failed_pc=0x0c07edc2u; return 0; }
r[1]=0x00000000u;
goto P_0c07edc4;
P_0c07edc4: /* original 66a3, guest PC 0x0c07edc4 */
if(!s->budget--) { s->failed_pc=0x0c07edc4u; return 0; }
r[6]=r[10];
goto P_0c07edc6;
P_0c07edc6: /* original 4e00, guest PC 0x0c07edc6 */
if(!s->budget--) { s->failed_pc=0x0c07edc6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07edc8;
P_0c07edc8: /* original 6713, guest PC 0x0c07edc8 */
if(!s->budget--) { s->failed_pc=0x0c07edc8u; return 0; }
r[7]=r[1];
goto P_0c07edca;
P_0c07edca: /* original 2ecb, guest PC 0x0c07edca */
if(!s->budget--) { s->failed_pc=0x0c07edcau; return 0; }
r[14]|=r[12];
goto P_0c07edcc;
P_0c07edcc: /* original 2f16, guest PC 0x0c07edcc */
if(!s->budget--) { s->failed_pc=0x0c07edccu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07edce;
P_0c07edce: /* original 954a, guest PC 0x0c07edce */
if(!s->budget--) { s->failed_pc=0x0c07edceu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee66u,2);
goto P_0c07edd0;
P_0c07edd0: /* original 480b, guest PC 0x0c07edd0 */
if(!s->budget--) { s->failed_pc=0x0c07edd0u; return 0; }
target=r[8];
r[16]=code_base|0x0c07edd4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07edd4u) { target=s->pc; goto dispatch; }
goto P_0c07edd4;
P_0c07edd2: /* original 64e3, guest PC 0x0c07edd2 */
if(!s->budget--) { s->failed_pc=0x0c07edd2u; return 0; }
r[4]=r[14];
goto P_0c07edd4;
P_0c07edd4: /* original a00f, guest PC 0x0c07edd4 */
if(!s->budget--) { s->failed_pc=0x0c07edd4u; return 0; }
r[15]+=0x00000004u;
goto P_0c07edf6;
P_0c07edd6: /* original 7f04, guest PC 0x0c07edd6 */
if(!s->budget--) { s->failed_pc=0x0c07edd6u; return 0; }
r[15]+=0x00000004u;
goto P_0c07edd8;
P_0c07edd8: /* original 9146, guest PC 0x0c07edd8 */
if(!s->budget--) { s->failed_pc=0x0c07edd8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee68u,2);
goto P_0c07edda;
P_0c07edda: /* original 3d10, guest PC 0x0c07edda */
if(!s->budget--) { s->failed_pc=0x0c07eddau; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c07eddc;
P_0c07eddc: /* original 8b0b, guest PC 0x0c07eddc */
if(!s->budget--) { s->failed_pc=0x0c07eddcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07edf6; }
goto P_0c07edde;
P_0c07edde: /* original 6eb3, guest PC 0x0c07edde */
if(!s->budget--) { s->failed_pc=0x0c07eddeu; return 0; }
r[14]=r[11];
goto P_0c07ede0;
P_0c07ede0: /* original 7e0c, guest PC 0x0c07ede0 */
if(!s->budget--) { s->failed_pc=0x0c07ede0u; return 0; }
r[14]+=0x0000000cu;
goto P_0c07ede2;
P_0c07ede2: /* original e300, guest PC 0x0c07ede2 */
if(!s->budget--) { s->failed_pc=0x0c07ede2u; return 0; }
r[3]=0x00000000u;
goto P_0c07ede4;
P_0c07ede4: /* original 66a3, guest PC 0x0c07ede4 */
if(!s->budget--) { s->failed_pc=0x0c07ede4u; return 0; }
r[6]=r[10];
goto P_0c07ede6;
P_0c07ede6: /* original 4e00, guest PC 0x0c07ede6 */
if(!s->budget--) { s->failed_pc=0x0c07ede6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07ede8;
P_0c07ede8: /* original 6733, guest PC 0x0c07ede8 */
if(!s->budget--) { s->failed_pc=0x0c07ede8u; return 0; }
r[7]=r[3];
goto P_0c07edea;
P_0c07edea: /* original 2ecb, guest PC 0x0c07edea */
if(!s->budget--) { s->failed_pc=0x0c07edeau; return 0; }
r[14]|=r[12];
goto P_0c07edec;
P_0c07edec: /* original 2f36, guest PC 0x0c07edec */
if(!s->budget--) { s->failed_pc=0x0c07edecu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07edee;
P_0c07edee: /* original 953c, guest PC 0x0c07edee */
if(!s->budget--) { s->failed_pc=0x0c07edeeu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee6au,2);
goto P_0c07edf0;
P_0c07edf0: /* original 480b, guest PC 0x0c07edf0 */
if(!s->budget--) { s->failed_pc=0x0c07edf0u; return 0; }
target=r[8];
r[16]=code_base|0x0c07edf4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07edf4u) { target=s->pc; goto dispatch; }
goto P_0c07edf4;
P_0c07edf2: /* original 64e3, guest PC 0x0c07edf2 */
if(!s->budget--) { s->failed_pc=0x0c07edf2u; return 0; }
r[4]=r[14];
goto P_0c07edf4;
P_0c07edf4: /* original 7f04, guest PC 0x0c07edf4 */
if(!s->budget--) { s->failed_pc=0x0c07edf4u; return 0; }
r[15]+=0x00000004u;
goto P_0c07edf6;
P_0c07edf6: /* original d420, guest PC 0x0c07edf6 */
if(!s->budget--) { s->failed_pc=0x0c07edf6u; return 0; }
r[4]=read(ram,0x0c07ee78u,4);
goto P_0c07edf8;
P_0c07edf8: /* original e20f, guest PC 0x0c07edf8 */
if(!s->budget--) { s->failed_pc=0x0c07edf8u; return 0; }
r[2]=0x0000000fu;
goto P_0c07edfa;
P_0c07edfa: /* original 1425, guest PC 0x0c07edfa */
if(!s->budget--) { s->failed_pc=0x0c07edfau; return 0; }
write(ram,r[4]+20,r[2],4);
goto P_0c07edfc;
P_0c07edfc: /* original 9330, guest PC 0x0c07edfc */
if(!s->budget--) { s->failed_pc=0x0c07edfcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee60u,2);
goto P_0c07edfe;
P_0c07edfe: /* original 3d30, guest PC 0x0c07edfe */
if(!s->budget--) { s->failed_pc=0x0c07edfeu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c07ee00;
P_0c07ee00: /* original 8908, guest PC 0x0c07ee00 */
if(!s->budget--) { s->failed_pc=0x0c07ee00u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ee14; }
goto P_0c07ee02;
P_0c07ee02: /* original 9133, guest PC 0x0c07ee02 */
if(!s->budget--) { s->failed_pc=0x0c07ee02u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee6cu,2);
goto P_0c07ee04;
P_0c07ee04: /* original 3d10, guest PC 0x0c07ee04 */
if(!s->budget--) { s->failed_pc=0x0c07ee04u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c07ee06;
P_0c07ee06: /* original 8905, guest PC 0x0c07ee06 */
if(!s->budget--) { s->failed_pc=0x0c07ee06u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ee14; }
goto P_0c07ee08;
P_0c07ee08: /* original 902e, guest PC 0x0c07ee08 */
if(!s->budget--) { s->failed_pc=0x0c07ee08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee68u,2);
goto P_0c07ee0a;
P_0c07ee0a: /* original 3d00, guest PC 0x0c07ee0a */
if(!s->budget--) { s->failed_pc=0x0c07ee0au; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[0])!=0);
goto P_0c07ee0c;
P_0c07ee0c: /* original 8902, guest PC 0x0c07ee0c */
if(!s->budget--) { s->failed_pc=0x0c07ee0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ee14; }
goto P_0c07ee0e;
P_0c07ee0e: /* original 922e, guest PC 0x0c07ee0e */
if(!s->budget--) { s->failed_pc=0x0c07ee0eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ee6eu,2);
goto P_0c07ee10;
P_0c07ee10: /* original 3d20, guest PC 0x0c07ee10 */
if(!s->budget--) { s->failed_pc=0x0c07ee10u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[2])!=0);
goto P_0c07ee12;
P_0c07ee12: /* original 8b02, guest PC 0x0c07ee12 */
if(!s->budget--) { s->failed_pc=0x0c07ee12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ee1a; }
goto P_0c07ee14;
P_0c07ee14: /* original 5045, guest PC 0x0c07ee14 */
if(!s->budget--) { s->failed_pc=0x0c07ee14u; return 0; }
r[0]=read(ram,r[4]+20,4);
goto P_0c07ee16;
P_0c07ee16: /* original cb80, guest PC 0x0c07ee16 */
if(!s->budget--) { s->failed_pc=0x0c07ee16u; return 0; }
r[0]|=128u;
goto P_0c07ee18;
P_0c07ee18: /* original 1405, guest PC 0x0c07ee18 */
if(!s->budget--) { s->failed_pc=0x0c07ee18u; return 0; }
write(ram,r[4]+20,r[0],4);
goto P_0c07ee1a;
P_0c07ee1a: /* original 64f2, guest PC 0x0c07ee1a */
if(!s->budget--) { s->failed_pc=0x0c07ee1au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07ee1c;
P_0c07ee1c: /* original 7f04, guest PC 0x0c07ee1c */
if(!s->budget--) { s->failed_pc=0x0c07ee1cu; return 0; }
r[15]+=0x00000004u;
goto P_0c07ee1e;
P_0c07ee1e: /* original 4f26, guest PC 0x0c07ee1e */
if(!s->budget--) { s->failed_pc=0x0c07ee1eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ee20;
P_0c07ee20: /* original d316, guest PC 0x0c07ee20 */
if(!s->budget--) { s->failed_pc=0x0c07ee20u; return 0; }
r[3]=read(ram,0x0c07ee7cu,4);
goto P_0c07ee22;
P_0c07ee22: /* original 65e3, guest PC 0x0c07ee22 */
if(!s->budget--) { s->failed_pc=0x0c07ee22u; return 0; }
r[5]=r[14];
goto P_0c07ee24;
P_0c07ee24: /* original 68f6, guest PC 0x0c07ee24 */
if(!s->budget--) { s->failed_pc=0x0c07ee24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07ee26;
P_0c07ee26: /* original 69f6, guest PC 0x0c07ee26 */
if(!s->budget--) { s->failed_pc=0x0c07ee26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07ee28;
P_0c07ee28: /* original 6af6, guest PC 0x0c07ee28 */
if(!s->budget--) { s->failed_pc=0x0c07ee28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07ee2a;
P_0c07ee2a: /* original 6bf6, guest PC 0x0c07ee2a */
if(!s->budget--) { s->failed_pc=0x0c07ee2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07ee2c;
P_0c07ee2c: /* original 6cf6, guest PC 0x0c07ee2c */
if(!s->budget--) { s->failed_pc=0x0c07ee2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07ee2e;
P_0c07ee2e: /* original 6df6, guest PC 0x0c07ee2e */
if(!s->budget--) { s->failed_pc=0x0c07ee2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ee30;
P_0c07ee30: /* original 432b, guest PC 0x0c07ee30 */
if(!s->budget--) { s->failed_pc=0x0c07ee30u; return 0; }
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
P_0c07ee32: /* original 6ef6, guest PC 0x0c07ee32 */
if(!s->budget--) { s->failed_pc=0x0c07ee32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07ee34u,s,ram);
P_0c080266: /* original 4f22, guest PC 0x0c080266 */
if(!s->budget--) { s->failed_pc=0x0c080266u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c080268;
P_0c080268: /* original 7ffc, guest PC 0x0c080268 */
if(!s->budget--) { s->failed_pc=0x0c080268u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08026a;
P_0c08026a: /* original 2f42, guest PC 0x0c08026a */
if(!s->budget--) { s->failed_pc=0x0c08026au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c08026c;
P_0c08026c: /* original de42, guest PC 0x0c08026c */
if(!s->budget--) { s->failed_pc=0x0c08026cu; return 0; }
r[14]=read(ram,0x0c080378u,4);
goto P_0c08026e;
P_0c08026e: /* original 9474, guest PC 0x0c08026e */
if(!s->budget--) { s->failed_pc=0x0c08026eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08035au,2);
goto P_0c080270;
P_0c080270: /* original 4e0b, guest PC 0x0c080270 */
if(!s->budget--) { s->failed_pc=0x0c080270u; return 0; }
target=r[14];
r[16]=code_base|0x0c080274u;
tmp=read(ram,r[15],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080274u) { target=s->pc; goto dispatch; }
goto P_0c080274;
P_0c080272: /* original 65f2, guest PC 0x0c080272 */
if(!s->budget--) { s->failed_pc=0x0c080272u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c080274;
P_0c080274: /* original d541, guest PC 0x0c080274 */
if(!s->budget--) { s->failed_pc=0x0c080274u; return 0; }
r[5]=read(ram,0x0c08037cu,4);
goto P_0c080276;
P_0c080276: /* original 9471, guest PC 0x0c080276 */
if(!s->budget--) { s->failed_pc=0x0c080276u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08035cu,2);
goto P_0c080278;
P_0c080278: /* original 4e0b, guest PC 0x0c080278 */
if(!s->budget--) { s->failed_pc=0x0c080278u; return 0; }
target=r[14];
r[16]=code_base|0x0c08027cu;
r[6]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08027cu) { target=s->pc; goto dispatch; }
goto P_0c08027c;
P_0c08027a: /* original e601, guest PC 0x0c08027a */
if(!s->budget--) { s->failed_pc=0x0c08027au; return 0; }
r[6]=0x00000001u;
goto P_0c08027c;
P_0c08027c: /* original d540, guest PC 0x0c08027c */
if(!s->budget--) { s->failed_pc=0x0c08027cu; return 0; }
r[5]=read(ram,0x0c080380u,4);
goto P_0c08027e;
P_0c08027e: /* original 946e, guest PC 0x0c08027e */
if(!s->budget--) { s->failed_pc=0x0c08027eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08035eu,2);
goto P_0c080280;
P_0c080280: /* original 4e0b, guest PC 0x0c080280 */
if(!s->budget--) { s->failed_pc=0x0c080280u; return 0; }
target=r[14];
r[16]=code_base|0x0c080284u;
r[6]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c080284u) { target=s->pc; goto dispatch; }
goto P_0c080284;
P_0c080282: /* original e601, guest PC 0x0c080282 */
if(!s->budget--) { s->failed_pc=0x0c080282u; return 0; }
r[6]=0x00000001u;
goto P_0c080284;
P_0c080284: /* original 7f04, guest PC 0x0c080284 */
if(!s->budget--) { s->failed_pc=0x0c080284u; return 0; }
r[15]+=0x00000004u;
goto P_0c080286;
P_0c080286: /* original 4f26, guest PC 0x0c080286 */
if(!s->budget--) { s->failed_pc=0x0c080286u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c080288;
P_0c080288: /* original 000b, guest PC 0x0c080288 */
if(!s->budget--) { s->failed_pc=0x0c080288u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08028a: /* original 6ef6, guest PC 0x0c08028a */
if(!s->budget--) { s->failed_pc=0x0c08028au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08028cu,s,ram);
P_0c08439e: /* original 4f22, guest PC 0x0c08439e */
if(!s->budget--) { s->failed_pc=0x0c08439eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0843a0;
P_0c0843a0: /* original d31f, guest PC 0x0c0843a0 */
if(!s->budget--) { s->failed_pc=0x0c0843a0u; return 0; }
r[3]=read(ram,0x0c084420u,4);
goto P_0c0843a2;
P_0c0843a2: /* original de10, guest PC 0x0c0843a2 */
if(!s->budget--) { s->failed_pc=0x0c0843a2u; return 0; }
r[14]=read(ram,0x0c0843e4u,4);
goto P_0c0843a4;
P_0c0843a4: /* original 430b, guest PC 0x0c0843a4 */
if(!s->budget--) { s->failed_pc=0x0c0843a4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0843a8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0843a8u) { target=s->pc; goto dispatch; }
goto P_0c0843a8;
P_0c0843a6: /* original 0009, guest PC 0x0c0843a6 */
if(!s->budget--) { s->failed_pc=0x0c0843a6u; return 0; }
goto P_0c0843a8;
P_0c0843a8: /* original d41e, guest PC 0x0c0843a8 */
if(!s->budget--) { s->failed_pc=0x0c0843a8u; return 0; }
r[4]=read(ram,0x0c084424u,4);
goto P_0c0843aa;
P_0c0843aa: /* original 9219, guest PC 0x0c0843aa */
if(!s->budget--) { s->failed_pc=0x0c0843aau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0843e0u,2);
goto P_0c0843ac;
P_0c0843ac: /* original 8543, guest PC 0x0c0843ac */
if(!s->budget--) { s->failed_pc=0x0c0843acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+6,2);
goto P_0c0843ae;
P_0c0843ae: /* original 630d, guest PC 0x0c0843ae */
if(!s->budget--) { s->failed_pc=0x0c0843aeu; return 0; }
r[3]=r[0]&65535u;
goto P_0c0843b0;
P_0c0843b0: /* original 854b, guest PC 0x0c0843b0 */
if(!s->budget--) { s->failed_pc=0x0c0843b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+22,2);
goto P_0c0843b2;
P_0c0843b2: /* original 600d, guest PC 0x0c0843b2 */
if(!s->budget--) { s->failed_pc=0x0c0843b2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0843b4;
P_0c0843b4: /* original 230b, guest PC 0x0c0843b4 */
if(!s->budget--) { s->failed_pc=0x0c0843b4u; return 0; }
r[3]|=r[0];
goto P_0c0843b6;
P_0c0843b6: /* original 2328, guest PC 0x0c0843b6 */
if(!s->budget--) { s->failed_pc=0x0c0843b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c0843b8;
P_0c0843b8: /* original 8907, guest PC 0x0c0843b8 */
if(!s->budget--) { s->failed_pc=0x0c0843b8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0843ca; }
goto P_0c0843ba;
P_0c0843ba: /* original d31b, guest PC 0x0c0843ba */
if(!s->budget--) { s->failed_pc=0x0c0843bau; return 0; }
r[3]=read(ram,0x0c084428u,4);
goto P_0c0843bc;
P_0c0843bc: /* original 9411, guest PC 0x0c0843bc */
if(!s->budget--) { s->failed_pc=0x0c0843bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0843e2u,2);
goto P_0c0843be;
P_0c0843be: /* original 430b, guest PC 0x0c0843be */
if(!s->budget--) { s->failed_pc=0x0c0843beu; return 0; }
target=r[3];
r[16]=code_base|0x0c0843c2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0843c2u) { target=s->pc; goto dispatch; }
goto P_0c0843c2;
P_0c0843c0: /* original 0009, guest PC 0x0c0843c0 */
if(!s->budget--) { s->failed_pc=0x0c0843c0u; return 0; }
goto P_0c0843c2;
P_0c0843c2: /* original 900c, guest PC 0x0c0843c2 */
if(!s->budget--) { s->failed_pc=0x0c0843c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0843deu,2);
goto P_0c0843c4;
P_0c0843c4: /* original e202, guest PC 0x0c0843c4 */
if(!s->budget--) { s->failed_pc=0x0c0843c4u; return 0; }
r[2]=0x00000002u;
goto P_0c0843c6;
P_0c0843c6: /* original a003, guest PC 0x0c0843c6 */
if(!s->budget--) { s->failed_pc=0x0c0843c6u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0843d0;
P_0c0843c8: /* original 0e26, guest PC 0x0c0843c8 */
if(!s->budget--) { s->failed_pc=0x0c0843c8u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0843ca;
P_0c0843ca: /* original 9008, guest PC 0x0c0843ca */
if(!s->budget--) { s->failed_pc=0x0c0843cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0843deu,2);
goto P_0c0843cc;
P_0c0843cc: /* original e104, guest PC 0x0c0843cc */
if(!s->budget--) { s->failed_pc=0x0c0843ccu; return 0; }
r[1]=0x00000004u;
goto P_0c0843ce;
P_0c0843ce: /* original 0e16, guest PC 0x0c0843ce */
if(!s->budget--) { s->failed_pc=0x0c0843ceu; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c0843d0;
P_0c0843d0: /* original 4f26, guest PC 0x0c0843d0 */
if(!s->budget--) { s->failed_pc=0x0c0843d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0843d2;
P_0c0843d2: /* original 000b, guest PC 0x0c0843d2 */
if(!s->budget--) { s->failed_pc=0x0c0843d2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0843d4: /* original 6ef6, guest PC 0x0c0843d4 */
if(!s->budget--) { s->failed_pc=0x0c0843d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0843d6u,s,ram);
P_0c0968d0: /* original d418, guest PC 0x0c0968d0 */
if(!s->budget--) { s->failed_pc=0x0c0968d0u; return 0; }
r[4]=read(ram,0x0c096934u,4);
goto P_0c0968d2;
P_0c0968d2: /* original 7ffc, guest PC 0x0c0968d2 */
if(!s->budget--) { s->failed_pc=0x0c0968d2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0968d4;
P_0c0968d4: /* original 5343, guest PC 0x0c0968d4 */
if(!s->budget--) { s->failed_pc=0x0c0968d4u; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c0968d6;
P_0c0968d6: /* original 73ff, guest PC 0x0c0968d6 */
if(!s->budget--) { s->failed_pc=0x0c0968d6u; return 0; }
r[3]+=0xffffffffu;
goto P_0c0968d8;
P_0c0968d8: /* original 1433, guest PC 0x0c0968d8 */
if(!s->budget--) { s->failed_pc=0x0c0968d8u; return 0; }
write(ram,r[4]+12,r[3],4);
goto P_0c0968da;
P_0c0968da: /* original 844a, guest PC 0x0c0968da */
if(!s->budget--) { s->failed_pc=0x0c0968dau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+10,1);
goto P_0c0968dc;
P_0c0968dc: /* original 650c, guest PC 0x0c0968dc */
if(!s->budget--) { s->failed_pc=0x0c0968dcu; return 0; }
r[5]=r[0]&255u;
goto P_0c0968de;
P_0c0968de: /* original 6053, guest PC 0x0c0968de */
if(!s->budget--) { s->failed_pc=0x0c0968deu; return 0; }
r[0]=r[5];
goto P_0c0968e0;
P_0c0968e0: /* original 8048, guest PC 0x0c0968e0 */
if(!s->budget--) { s->failed_pc=0x0c0968e0u; return 0; }
write(ram,r[4]+8,r[0],1);
goto P_0c0968e2;
P_0c0968e2: /* original d215, guest PC 0x0c0968e2 */
if(!s->budget--) { s->failed_pc=0x0c0968e2u; return 0; }
r[2]=read(ram,0x0c096938u,4);
goto P_0c0968e4;
P_0c0968e4: /* original 635b, guest PC 0x0c0968e4 */
if(!s->budget--) { s->failed_pc=0x0c0968e4u; return 0; }
r[3]=0u-r[5];
goto P_0c0968e6;
P_0c0968e6: /* original 4508, guest PC 0x0c0968e6 */
if(!s->budget--) { s->failed_pc=0x0c0968e6u; return 0; }
r[5]<<=2;
goto P_0c0968e8;
P_0c0968e8: /* original 423d, guest PC 0x0c0968e8 */
if(!s->budget--) { s->failed_pc=0x0c0968e8u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c0968ea;
P_0c0968ea: /* original 2422, guest PC 0x0c0968ea */
if(!s->budget--) { s->failed_pc=0x0c0968eau; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0968ec;
P_0c0968ec: /* original d013, guest PC 0x0c0968ec */
if(!s->budget--) { s->failed_pc=0x0c0968ecu; return 0; }
r[0]=read(ram,0x0c09693cu,4);
goto P_0c0968ee;
P_0c0968ee: /* original 035e, guest PC 0x0c0968ee */
if(!s->budget--) { s->failed_pc=0x0c0968eeu; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c0968f0;
P_0c0968f0: /* original 6233, guest PC 0x0c0968f0 */
if(!s->budget--) { s->failed_pc=0x0c0968f0u; return 0; }
r[2]=r[3];
goto P_0c0968f2;
P_0c0968f2: /* original 2f32, guest PC 0x0c0968f2 */
if(!s->budget--) { s->failed_pc=0x0c0968f2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0968f4;
P_0c0968f4: /* original 422b, guest PC 0x0c0968f4 */
if(!s->budget--) { s->failed_pc=0x0c0968f4u; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c0968f6: /* original 7f04, guest PC 0x0c0968f6 */
if(!s->budget--) { s->failed_pc=0x0c0968f6u; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c0968f8u,s,ram);
P_0c096d5e: /* original 2fe6, guest PC 0x0c096d5e */
if(!s->budget--) { s->failed_pc=0x0c096d5eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096d60;
P_0c096d60: /* original 2fd6, guest PC 0x0c096d60 */
if(!s->budget--) { s->failed_pc=0x0c096d60u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096d62;
P_0c096d62: /* original 4f22, guest PC 0x0c096d62 */
if(!s->budget--) { s->failed_pc=0x0c096d62u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c096d64;
P_0c096d64: /* original d327, guest PC 0x0c096d64 */
if(!s->budget--) { s->failed_pc=0x0c096d64u; return 0; }
r[3]=read(ram,0x0c096e04u,4);
goto P_0c096d66;
P_0c096d66: /* original dd2a, guest PC 0x0c096d66 */
if(!s->budget--) { s->failed_pc=0x0c096d66u; return 0; }
r[13]=read(ram,0x0c096e10u,4);
goto P_0c096d68;
P_0c096d68: /* original 7ffc, guest PC 0x0c096d68 */
if(!s->budget--) { s->failed_pc=0x0c096d68u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c096d6a;
P_0c096d6a: /* original 2f32, guest PC 0x0c096d6a */
if(!s->budget--) { s->failed_pc=0x0c096d6au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c096d6c;
P_0c096d6c: /* original 52d2, guest PC 0x0c096d6c */
if(!s->budget--) { s->failed_pc=0x0c096d6cu; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c096d6e;
P_0c096d6e: /* original d329, guest PC 0x0c096d6e */
if(!s->budget--) { s->failed_pc=0x0c096d6eu; return 0; }
r[3]=read(ram,0x0c096e14u,4);
goto P_0c096d70;
P_0c096d70: /* original 2238, guest PC 0x0c096d70 */
if(!s->budget--) { s->failed_pc=0x0c096d70u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c096d72;
P_0c096d72: /* original 8920, guest PC 0x0c096d72 */
if(!s->budget--) { s->failed_pc=0x0c096d72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096db6; }
goto P_0c096d74;
P_0c096d74: /* original de28, guest PC 0x0c096d74 */
if(!s->budget--) { s->failed_pc=0x0c096d74u; return 0; }
r[14]=read(ram,0x0c096e18u,4);
goto P_0c096d76;
P_0c096d76: /* original bdc4, guest PC 0x0c096d76 */
if(!s->budget--) { s->failed_pc=0x0c096d76u; return 0; }
target=0x0c096902u; r[16]=code_base|0x0c096d7au;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096d7au) { target=s->pc; goto dispatch; }
goto P_0c096d7a;
P_0c096d78: /* original 54e8, guest PC 0x0c096d78 */
if(!s->budget--) { s->failed_pc=0x0c096d78u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c096d7a;
P_0c096d7a: /* original e044, guest PC 0x0c096d7a */
if(!s->budget--) { s->failed_pc=0x0c096d7au; return 0; }
r[0]=0x00000044u;
goto P_0c096d7c;
P_0c096d7c: /* original bdc1, guest PC 0x0c096d7c */
if(!s->budget--) { s->failed_pc=0x0c096d7cu; return 0; }
target=0x0c096902u; r[16]=code_base|0x0c096d80u;
r[4]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096d80u) { target=s->pc; goto dispatch; }
goto P_0c096d80;
P_0c096d7e: /* original 04ee, guest PC 0x0c096d7e */
if(!s->budget--) { s->failed_pc=0x0c096d7eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c096d80;
P_0c096d80: /* original 52d2, guest PC 0x0c096d80 */
if(!s->budget--) { s->failed_pc=0x0c096d80u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c096d82;
P_0c096d82: /* original e044, guest PC 0x0c096d82 */
if(!s->budget--) { s->failed_pc=0x0c096d82u; return 0; }
r[0]=0x00000044u;
goto P_0c096d84;
P_0c096d84: /* original d325, guest PC 0x0c096d84 */
if(!s->budget--) { s->failed_pc=0x0c096d84u; return 0; }
r[3]=read(ram,0x0c096e1cu,4);
goto P_0c096d86;
P_0c096d86: /* original 223b, guest PC 0x0c096d86 */
if(!s->budget--) { s->failed_pc=0x0c096d86u; return 0; }
r[2]|=r[3];
goto P_0c096d88;
P_0c096d88: /* original 1d22, guest PC 0x0c096d88 */
if(!s->budget--) { s->failed_pc=0x0c096d88u; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c096d8a;
P_0c096d8a: /* original e201, guest PC 0x0c096d8a */
if(!s->budget--) { s->failed_pc=0x0c096d8au; return 0; }
r[2]=0x00000001u;
goto P_0c096d8c;
P_0c096d8c: /* original d124, guest PC 0x0c096d8c */
if(!s->budget--) { s->failed_pc=0x0c096d8cu; return 0; }
r[1]=read(ram,0x0c096e20u,4);
goto P_0c096d8e;
P_0c096d8e: /* original 04ee, guest PC 0x0c096d8e */
if(!s->budget--) { s->failed_pc=0x0c096d8eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c096d90;
P_0c096d90: /* original 410b, guest PC 0x0c096d90 */
if(!s->budget--) { s->failed_pc=0x0c096d90u; return 0; }
target=r[1];
r[16]=code_base|0x0c096d94u;
write(ram,r[4],r[2],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096d94u) { target=s->pc; goto dispatch; }
goto P_0c096d94;
P_0c096d92: /* original 2422, guest PC 0x0c096d92 */
if(!s->budget--) { s->failed_pc=0x0c096d92u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c096d94;
P_0c096d94: /* original 55e5, guest PC 0x0c096d94 */
if(!s->budget--) { s->failed_pc=0x0c096d94u; return 0; }
r[5]=read(ram,r[14]+20,4);
goto P_0c096d96;
P_0c096d96: /* original e400, guest PC 0x0c096d96 */
if(!s->budget--) { s->failed_pc=0x0c096d96u; return 0; }
r[4]=0x00000000u;
goto P_0c096d98;
P_0c096d98: /* original 56e4, guest PC 0x0c096d98 */
if(!s->budget--) { s->failed_pc=0x0c096d98u; return 0; }
r[6]=read(ram,r[14]+16,4);
goto P_0c096d9a;
P_0c096d9a: /* original e061, guest PC 0x0c096d9a */
if(!s->budget--) { s->failed_pc=0x0c096d9au; return 0; }
r[0]=0x00000061u;
goto P_0c096d9c;
P_0c096d9c: /* original 0644, guest PC 0x0c096d9c */
if(!s->budget--) { s->failed_pc=0x0c096d9cu; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c096d9e;
P_0c096d9e: /* original 0544, guest PC 0x0c096d9e */
if(!s->budget--) { s->failed_pc=0x0c096d9eu; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c096da0;
P_0c096da0: /* original e060, guest PC 0x0c096da0 */
if(!s->budget--) { s->failed_pc=0x0c096da0u; return 0; }
r[0]=0x00000060u;
goto P_0c096da2;
P_0c096da2: /* original 0644, guest PC 0x0c096da2 */
if(!s->budget--) { s->failed_pc=0x0c096da2u; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c096da4;
P_0c096da4: /* original 0544, guest PC 0x0c096da4 */
if(!s->budget--) { s->failed_pc=0x0c096da4u; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c096da6;
P_0c096da6: /* original e016, guest PC 0x0c096da6 */
if(!s->budget--) { s->failed_pc=0x0c096da6u; return 0; }
r[0]=0x00000016u;
goto P_0c096da8;
P_0c096da8: /* original 63f2, guest PC 0x0c096da8 */
if(!s->budget--) { s->failed_pc=0x0c096da8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c096daa;
P_0c096daa: /* original 7f04, guest PC 0x0c096daa */
if(!s->budget--) { s->failed_pc=0x0c096daau; return 0; }
r[15]+=0x00000004u;
goto P_0c096dac;
P_0c096dac: /* original 4f26, guest PC 0x0c096dac */
if(!s->budget--) { s->failed_pc=0x0c096dacu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096dae;
P_0c096dae: /* original 803a, guest PC 0x0c096dae */
if(!s->budget--) { s->failed_pc=0x0c096daeu; return 0; }
write(ram,r[3]+10,r[0],1);
goto P_0c096db0;
P_0c096db0: /* original 6df6, guest PC 0x0c096db0 */
if(!s->budget--) { s->failed_pc=0x0c096db0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096db2;
P_0c096db2: /* original ad8d, guest PC 0x0c096db2 */
if(!s->budget--) { s->failed_pc=0x0c096db2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0968d0;
P_0c096db4: /* original 6ef6, guest PC 0x0c096db4 */
if(!s->budget--) { s->failed_pc=0x0c096db4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c096db6;
P_0c096db6: /* original 7f04, guest PC 0x0c096db6 */
if(!s->budget--) { s->failed_pc=0x0c096db6u; return 0; }
r[15]+=0x00000004u;
goto P_0c096db8;
P_0c096db8: /* original 4f26, guest PC 0x0c096db8 */
if(!s->budget--) { s->failed_pc=0x0c096db8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096dba;
P_0c096dba: /* original 6df6, guest PC 0x0c096dba */
if(!s->budget--) { s->failed_pc=0x0c096dbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096dbc;
P_0c096dbc: /* original 000b, guest PC 0x0c096dbc */
if(!s->budget--) { s->failed_pc=0x0c096dbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c096dbe: /* original 6ef6, guest PC 0x0c096dbe */
if(!s->budget--) { s->failed_pc=0x0c096dbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c096dc0u,s,ram);
P_0c096f9a: /* original 4f22, guest PC 0x0c096f9a */
if(!s->budget--) { s->failed_pc=0x0c096f9au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c096f9c;
P_0c096f9c: /* original d322, guest PC 0x0c096f9c */
if(!s->budget--) { s->failed_pc=0x0c096f9cu; return 0; }
r[3]=read(ram,0x0c097028u,4);
goto P_0c096f9e;
P_0c096f9e: /* original de20, guest PC 0x0c096f9e */
if(!s->budget--) { s->failed_pc=0x0c096f9eu; return 0; }
r[14]=read(ram,0x0c097020u,4);
goto P_0c096fa0;
P_0c096fa0: /* original 7ffc, guest PC 0x0c096fa0 */
if(!s->budget--) { s->failed_pc=0x0c096fa0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c096fa2;
P_0c096fa2: /* original 2f32, guest PC 0x0c096fa2 */
if(!s->budget--) { s->failed_pc=0x0c096fa2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c096fa4;
P_0c096fa4: /* original d322, guest PC 0x0c096fa4 */
if(!s->budget--) { s->failed_pc=0x0c096fa4u; return 0; }
r[3]=read(ram,0x0c097030u,4);
goto P_0c096fa6;
P_0c096fa6: /* original d421, guest PC 0x0c096fa6 */
if(!s->budget--) { s->failed_pc=0x0c096fa6u; return 0; }
r[4]=read(ram,0x0c09702cu,4);
goto P_0c096fa8;
P_0c096fa8: /* original 430b, guest PC 0x0c096fa8 */
if(!s->budget--) { s->failed_pc=0x0c096fa8u; return 0; }
target=r[3];
r[16]=code_base|0x0c096facu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096facu) { target=s->pc; goto dispatch; }
goto P_0c096fac;
P_0c096faa: /* original 0009, guest PC 0x0c096faa */
if(!s->budget--) { s->failed_pc=0x0c096faau; return 0; }
goto P_0c096fac;
P_0c096fac: /* original d222, guest PC 0x0c096fac */
if(!s->budget--) { s->failed_pc=0x0c096facu; return 0; }
r[2]=read(ram,0x0c097038u,4);
goto P_0c096fae;
P_0c096fae: /* original d521, guest PC 0x0c096fae */
if(!s->budget--) { s->failed_pc=0x0c096faeu; return 0; }
r[5]=read(ram,0x0c097034u,4);
goto P_0c096fb0;
P_0c096fb0: /* original bcab, guest PC 0x0c096fb0 */
if(!s->budget--) { s->failed_pc=0x0c096fb0u; return 0; }
target=0x0c09690au; r[16]=code_base|0x0c096fb4u;
tmp=read(ram,r[2],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096fb4u) { target=s->pc; goto dispatch; }
goto P_0c096fb4;
P_0c096fb2: /* original 6422, guest PC 0x0c096fb2 */
if(!s->budget--) { s->failed_pc=0x0c096fb2u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c096fb4;
P_0c096fb4: /* original e005, guest PC 0x0c096fb4 */
if(!s->budget--) { s->failed_pc=0x0c096fb4u; return 0; }
r[0]=0x00000005u;
goto P_0c096fb6;
P_0c096fb6: /* original 80eb, guest PC 0x0c096fb6 */
if(!s->budget--) { s->failed_pc=0x0c096fb6u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c096fb8;
P_0c096fb8: /* original e010, guest PC 0x0c096fb8 */
if(!s->budget--) { s->failed_pc=0x0c096fb8u; return 0; }
r[0]=0x00000010u;
goto P_0c096fba;
P_0c096fba: /* original 9319, guest PC 0x0c096fba */
if(!s->budget--) { s->failed_pc=0x0c096fbau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096ff0u,2);
goto P_0c096fbc;
P_0c096fbc: /* original e209, guest PC 0x0c096fbc */
if(!s->budget--) { s->failed_pc=0x0c096fbcu; return 0; }
r[2]=0x00000009u;
goto P_0c096fbe;
P_0c096fbe: /* original e630, guest PC 0x0c096fbe */
if(!s->budget--) { s->failed_pc=0x0c096fbeu; return 0; }
r[6]=0x00000030u;
goto P_0c096fc0;
P_0c096fc0: /* original 1e33, guest PC 0x0c096fc0 */
if(!s->budget--) { s->failed_pc=0x0c096fc0u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c096fc2;
P_0c096fc2: /* original 0e24, guest PC 0x0c096fc2 */
if(!s->budget--) { s->failed_pc=0x0c096fc2u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c096fc4;
P_0c096fc4: /* original e000, guest PC 0x0c096fc4 */
if(!s->budget--) { s->failed_pc=0x0c096fc4u; return 0; }
r[0]=0x00000000u;
goto P_0c096fc6;
P_0c096fc6: /* original 63f2, guest PC 0x0c096fc6 */
if(!s->budget--) { s->failed_pc=0x0c096fc6u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c096fc8;
P_0c096fc8: /* original 8031, guest PC 0x0c096fc8 */
if(!s->budget--) { s->failed_pc=0x0c096fc8u; return 0; }
write(ram,r[3]+1,r[0],1);
goto P_0c096fca;
P_0c096fca: /* original 9012, guest PC 0x0c096fca */
if(!s->budget--) { s->failed_pc=0x0c096fcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096ff2u,2);
goto P_0c096fcc;
P_0c096fcc: /* original 05ee, guest PC 0x0c096fcc */
if(!s->budget--) { s->failed_pc=0x0c096fccu; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c096fce;
P_0c096fce: /* original 6053, guest PC 0x0c096fce */
if(!s->budget--) { s->failed_pc=0x0c096fceu; return 0; }
r[0]=r[5];
goto P_0c096fd0;
P_0c096fd0: /* original 2069, guest PC 0x0c096fd0 */
if(!s->budget--) { s->failed_pc=0x0c096fd0u; return 0; }
r[0]&=r[6];
goto P_0c096fd2;
P_0c096fd2: /* original 8830, guest PC 0x0c096fd2 */
if(!s->budget--) { s->failed_pc=0x0c096fd2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000030u)!=0);
goto P_0c096fd4;
P_0c096fd4: /* original 8f01, guest PC 0x0c096fd4 */
if(!s->budget--) { s->failed_pc=0x0c096fd4u; return 0; }
cond=r[17]&1u;
r[4]=0x0000001cu;
if(!cond) { goto P_0c096fda; }
goto P_0c096fd8;
P_0c096fd6: /* original e41c, guest PC 0x0c096fd6 */
if(!s->budget--) { s->failed_pc=0x0c096fd6u; return 0; }
r[4]=0x0000001cu;
goto P_0c096fd8;
P_0c096fd8: /* original e418, guest PC 0x0c096fd8 */
if(!s->budget--) { s->failed_pc=0x0c096fd8u; return 0; }
r[4]=0x00000018u;
goto P_0c096fda;
P_0c096fda: /* original d318, guest PC 0x0c096fda */
if(!s->budget--) { s->failed_pc=0x0c096fdau; return 0; }
r[3]=read(ram,0x0c09703cu,4);
goto P_0c096fdc;
P_0c096fdc: /* original 430b, guest PC 0x0c096fdc */
if(!s->budget--) { s->failed_pc=0x0c096fdcu; return 0; }
target=r[3];
r[16]=code_base|0x0c096fe0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096fe0u) { target=s->pc; goto dispatch; }
goto P_0c096fe0;
P_0c096fde: /* original 0009, guest PC 0x0c096fde */
if(!s->budget--) { s->failed_pc=0x0c096fdeu; return 0; }
goto P_0c096fe0;
P_0c096fe0: /* original 7f04, guest PC 0x0c096fe0 */
if(!s->budget--) { s->failed_pc=0x0c096fe0u; return 0; }
r[15]+=0x00000004u;
goto P_0c096fe2;
P_0c096fe2: /* original 4f26, guest PC 0x0c096fe2 */
if(!s->budget--) { s->failed_pc=0x0c096fe2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096fe4;
P_0c096fe4: /* original aebb, guest PC 0x0c096fe4 */
if(!s->budget--) { s->failed_pc=0x0c096fe4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c096d5e;
P_0c096fe6: /* original 6ef6, guest PC 0x0c096fe6 */
if(!s->budget--) { s->failed_pc=0x0c096fe6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c096fe8u,s,ram);
P_0c097942: /* original 4f22, guest PC 0x0c097942 */
if(!s->budget--) { s->failed_pc=0x0c097942u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c097944;
P_0c097944: /* original d33f, guest PC 0x0c097944 */
if(!s->budget--) { s->failed_pc=0x0c097944u; return 0; }
r[3]=read(ram,0x0c097a44u,4);
goto P_0c097946;
P_0c097946: /* original dc3e, guest PC 0x0c097946 */
if(!s->budget--) { s->failed_pc=0x0c097946u; return 0; }
r[12]=read(ram,0x0c097a40u,4);
goto P_0c097948;
P_0c097948: /* original 7ffc, guest PC 0x0c097948 */
if(!s->budget--) { s->failed_pc=0x0c097948u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09794a;
P_0c09794a: /* original 2f32, guest PC 0x0c09794a */
if(!s->budget--) { s->failed_pc=0x0c09794au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09794c;
P_0c09794c: /* original dd3e, guest PC 0x0c09794c */
if(!s->budget--) { s->failed_pc=0x0c09794cu; return 0; }
r[13]=read(ram,0x0c097a48u,4);
goto P_0c09794e;
P_0c09794e: /* original de3f, guest PC 0x0c09794e */
if(!s->budget--) { s->failed_pc=0x0c09794eu; return 0; }
r[14]=read(ram,0x0c097a4cu,4);
goto P_0c097950;
P_0c097950: /* original 4e0b, guest PC 0x0c097950 */
if(!s->budget--) { s->failed_pc=0x0c097950u; return 0; }
target=r[14];
r[16]=code_base|0x0c097954u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097954u) { target=s->pc; goto dispatch; }
goto P_0c097954;
P_0c097952: /* original 64d3, guest PC 0x0c097952 */
if(!s->budget--) { s->failed_pc=0x0c097952u; return 0; }
r[4]=r[13];
goto P_0c097954;
P_0c097954: /* original 64d3, guest PC 0x0c097954 */
if(!s->budget--) { s->failed_pc=0x0c097954u; return 0; }
r[4]=r[13];
goto P_0c097956;
P_0c097956: /* original 4e0b, guest PC 0x0c097956 */
if(!s->budget--) { s->failed_pc=0x0c097956u; return 0; }
target=r[14];
r[16]=code_base|0x0c09795au;
r[4]+=0x00000058u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09795au) { target=s->pc; goto dispatch; }
goto P_0c09795a;
P_0c097958: /* original 7458, guest PC 0x0c097958 */
if(!s->budget--) { s->failed_pc=0x0c097958u; return 0; }
r[4]+=0x00000058u;
goto P_0c09795a;
P_0c09795a: /* original 64d3, guest PC 0x0c09795a */
if(!s->budget--) { s->failed_pc=0x0c09795au; return 0; }
r[4]=r[13];
goto P_0c09795c;
P_0c09795c: /* original 4e0b, guest PC 0x0c09795c */
if(!s->budget--) { s->failed_pc=0x0c09795cu; return 0; }
target=r[14];
r[16]=code_base|0x0c097960u;
r[4]+=0x0000002cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097960u) { target=s->pc; goto dispatch; }
goto P_0c097960;
P_0c09795e: /* original 742c, guest PC 0x0c09795e */
if(!s->budget--) { s->failed_pc=0x0c09795eu; return 0; }
r[4]+=0x0000002cu;
goto P_0c097960;
P_0c097960: /* original 946a, guest PC 0x0c097960 */
if(!s->budget--) { s->failed_pc=0x0c097960u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c097a38u,2);
goto P_0c097962;
P_0c097962: /* original 4e0b, guest PC 0x0c097962 */
if(!s->budget--) { s->failed_pc=0x0c097962u; return 0; }
target=r[14];
r[16]=code_base|0x0c097966u;
r[4]+=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097966u) { target=s->pc; goto dispatch; }
goto P_0c097966;
P_0c097964: /* original 34dc, guest PC 0x0c097964 */
if(!s->budget--) { s->failed_pc=0x0c097964u; return 0; }
r[4]+=r[13];
goto P_0c097966;
P_0c097966: /* original d23b, guest PC 0x0c097966 */
if(!s->budget--) { s->failed_pc=0x0c097966u; return 0; }
r[2]=read(ram,0x0c097a54u,4);
goto P_0c097968;
P_0c097968: /* original d339, guest PC 0x0c097968 */
if(!s->budget--) { s->failed_pc=0x0c097968u; return 0; }
r[3]=read(ram,0x0c097a50u,4);
goto P_0c09796a;
P_0c09796a: /* original 420b, guest PC 0x0c09796a */
if(!s->budget--) { s->failed_pc=0x0c09796au; return 0; }
target=r[2];
r[16]=code_base|0x0c09796eu;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09796eu) { target=s->pc; goto dispatch; }
goto P_0c09796e;
P_0c09796c: /* original 6432, guest PC 0x0c09796c */
if(!s->budget--) { s->failed_pc=0x0c09796cu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c09796e;
P_0c09796e: /* original d339, guest PC 0x0c09796e */
if(!s->budget--) { s->failed_pc=0x0c09796eu; return 0; }
r[3]=read(ram,0x0c097a54u,4);
goto P_0c097970;
P_0c097970: /* original d139, guest PC 0x0c097970 */
if(!s->budget--) { s->failed_pc=0x0c097970u; return 0; }
r[1]=read(ram,0x0c097a58u,4);
goto P_0c097972;
P_0c097972: /* original 430b, guest PC 0x0c097972 */
if(!s->budget--) { s->failed_pc=0x0c097972u; return 0; }
target=r[3];
r[16]=code_base|0x0c097976u;
tmp=read(ram,r[1],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097976u) { target=s->pc; goto dispatch; }
goto P_0c097976;
P_0c097974: /* original 6412, guest PC 0x0c097974 */
if(!s->budget--) { s->failed_pc=0x0c097974u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c097976;
P_0c097976: /* original d23a, guest PC 0x0c097976 */
if(!s->budget--) { s->failed_pc=0x0c097976u; return 0; }
r[2]=read(ram,0x0c097a60u,4);
goto P_0c097978;
P_0c097978: /* original d438, guest PC 0x0c097978 */
if(!s->budget--) { s->failed_pc=0x0c097978u; return 0; }
r[4]=read(ram,0x0c097a5cu,4);
goto P_0c09797a;
P_0c09797a: /* original 420b, guest PC 0x0c09797a */
if(!s->budget--) { s->failed_pc=0x0c09797au; return 0; }
target=r[2];
r[16]=code_base|0x0c09797eu;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09797eu) { target=s->pc; goto dispatch; }
goto P_0c09797e;
P_0c09797c: /* original e500, guest PC 0x0c09797c */
if(!s->budget--) { s->failed_pc=0x0c09797cu; return 0; }
r[5]=0x00000000u;
goto P_0c09797e;
P_0c09797e: /* original d339, guest PC 0x0c09797e */
if(!s->budget--) { s->failed_pc=0x0c09797eu; return 0; }
r[3]=read(ram,0x0c097a64u,4);
goto P_0c097980;
P_0c097980: /* original 54c2, guest PC 0x0c097980 */
if(!s->budget--) { s->failed_pc=0x0c097980u; return 0; }
r[4]=read(ram,r[12]+8,4);
goto P_0c097982;
P_0c097982: /* original 2348, guest PC 0x0c097982 */
if(!s->budget--) { s->failed_pc=0x0c097982u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c097984;
P_0c097984: /* original 890a, guest PC 0x0c097984 */
if(!s->budget--) { s->failed_pc=0x0c097984u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09799c; }
goto P_0c097986;
P_0c097986: /* original d238, guest PC 0x0c097986 */
if(!s->budget--) { s->failed_pc=0x0c097986u; return 0; }
r[2]=read(ram,0x0c097a68u,4);
goto P_0c097988;
P_0c097988: /* original d338, guest PC 0x0c097988 */
if(!s->budget--) { s->failed_pc=0x0c097988u; return 0; }
r[3]=read(ram,0x0c097a6cu,4);
goto P_0c09798a;
P_0c09798a: /* original 2429, guest PC 0x0c09798a */
if(!s->budget--) { s->failed_pc=0x0c09798au; return 0; }
r[4]&=r[2];
goto P_0c09798c;
P_0c09798c: /* original 430b, guest PC 0x0c09798c */
if(!s->budget--) { s->failed_pc=0x0c09798cu; return 0; }
target=r[3];
r[16]=code_base|0x0c097990u;
write(ram,r[12]+8,r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097990u) { target=s->pc; goto dispatch; }
goto P_0c097990;
P_0c09798e: /* original 1c42, guest PC 0x0c09798e */
if(!s->budget--) { s->failed_pc=0x0c09798eu; return 0; }
write(ram,r[12]+8,r[4],4);
goto P_0c097990;
P_0c097990: /* original d237, guest PC 0x0c097990 */
if(!s->budget--) { s->failed_pc=0x0c097990u; return 0; }
r[2]=read(ram,0x0c097a70u,4);
goto P_0c097992;
P_0c097992: /* original 420b, guest PC 0x0c097992 */
if(!s->budget--) { s->failed_pc=0x0c097992u; return 0; }
target=r[2];
r[16]=code_base|0x0c097996u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097996u) { target=s->pc; goto dispatch; }
goto P_0c097996;
P_0c097994: /* original 0009, guest PC 0x0c097994 */
if(!s->budget--) { s->failed_pc=0x0c097994u; return 0; }
goto P_0c097996;
P_0c097996: /* original d337, guest PC 0x0c097996 */
if(!s->budget--) { s->failed_pc=0x0c097996u; return 0; }
r[3]=read(ram,0x0c097a74u,4);
goto P_0c097998;
P_0c097998: /* original 430b, guest PC 0x0c097998 */
if(!s->budget--) { s->failed_pc=0x0c097998u; return 0; }
target=r[3];
r[16]=code_base|0x0c09799cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09799cu) { target=s->pc; goto dispatch; }
goto P_0c09799c;
P_0c09799a: /* original 0009, guest PC 0x0c09799a */
if(!s->budget--) { s->failed_pc=0x0c09799au; return 0; }
goto P_0c09799c;
P_0c09799c: /* original 62f2, guest PC 0x0c09799c */
if(!s->budget--) { s->failed_pc=0x0c09799cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09799e;
P_0c09799e: /* original 7f04, guest PC 0x0c09799e */
if(!s->budget--) { s->failed_pc=0x0c09799eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0979a0;
P_0c0979a0: /* original 4f26, guest PC 0x0c0979a0 */
if(!s->budget--) { s->failed_pc=0x0c0979a0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0979a2;
P_0c0979a2: /* original e006, guest PC 0x0c0979a2 */
if(!s->budget--) { s->failed_pc=0x0c0979a2u; return 0; }
r[0]=0x00000006u;
goto P_0c0979a4;
P_0c0979a4: /* original 802a, guest PC 0x0c0979a4 */
if(!s->budget--) { s->failed_pc=0x0c0979a4u; return 0; }
write(ram,r[2]+10,r[0],1);
goto P_0c0979a6;
P_0c0979a6: /* original 6cf6, guest PC 0x0c0979a6 */
if(!s->budget--) { s->failed_pc=0x0c0979a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0979a8;
P_0c0979a8: /* original 6df6, guest PC 0x0c0979a8 */
if(!s->budget--) { s->failed_pc=0x0c0979a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0979aa;
P_0c0979aa: /* original 000b, guest PC 0x0c0979aa */
if(!s->budget--) { s->failed_pc=0x0c0979aau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0979ac: /* original 6ef6, guest PC 0x0c0979ac */
if(!s->budget--) { s->failed_pc=0x0c0979acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0979aeu,s,ram);
P_0c0a12d2: /* original 4f22, guest PC 0x0c0a12d2 */
if(!s->budget--) { s->failed_pc=0x0c0a12d2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a12d4;
P_0c0a12d4: /* original d213, guest PC 0x0c0a12d4 */
if(!s->budget--) { s->failed_pc=0x0c0a12d4u; return 0; }
r[2]=read(ram,0x0c0a1324u,4);
goto P_0c0a12d6;
P_0c0a12d6: /* original 9007, guest PC 0x0c0a12d6 */
if(!s->budget--) { s->failed_pc=0x0c0a12d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a12e8u,2);
goto P_0c0a12d8;
P_0c0a12d8: /* original d311, guest PC 0x0c0a12d8 */
if(!s->budget--) { s->failed_pc=0x0c0a12d8u; return 0; }
r[3]=read(ram,0x0c0a1320u,4);
goto P_0c0a12da;
P_0c0a12da: /* original 420b, guest PC 0x0c0a12da */
if(!s->budget--) { s->failed_pc=0x0c0a12dau; return 0; }
target=r[2];
r[16]=code_base|0x0c0a12deu;
tmp=read(ram,r[3],4);
r[1]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a12deu) { target=s->pc; goto dispatch; }
goto P_0c0a12de;
P_0c0a12dc: /* original 6132, guest PC 0x0c0a12dc */
if(!s->budget--) { s->failed_pc=0x0c0a12dcu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0a12de;
P_0c0a12de: /* original 4f26, guest PC 0x0c0a12de */
if(!s->budget--) { s->failed_pc=0x0c0a12deu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a12e0;
P_0c0a12e0: /* original 000b, guest PC 0x0c0a12e0 */
if(!s->budget--) { s->failed_pc=0x0c0a12e0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a12e2: /* original 0009, guest PC 0x0c0a12e2 */
if(!s->budget--) { s->failed_pc=0x0c0a12e2u; return 0; }
return vf3_matrix_family(0x0c0a12e4u,s,ram);
P_0c0a293a: /* original 4f22, guest PC 0x0c0a293a */
if(!s->budget--) { s->failed_pc=0x0c0a293au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a293c;
P_0c0a293c: /* original 3433, guest PC 0x0c0a293c */
if(!s->budget--) { s->failed_pc=0x0c0a293cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0a293e;
P_0c0a293e: /* original 8f02, guest PC 0x0c0a293e */
if(!s->budget--) { s->failed_pc=0x0c0a293eu; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(!cond) { goto P_0c0a2946; }
goto P_0c0a2942;
P_0c0a2940: /* original 6d53, guest PC 0x0c0a2940 */
if(!s->budget--) { s->failed_pc=0x0c0a2940u; return 0; }
r[13]=r[5];
goto P_0c0a2942;
P_0c0a2942: /* original a008, guest PC 0x0c0a2942 */
if(!s->budget--) { s->failed_pc=0x0c0a2942u; return 0; }
r[0]=0x00000000u;
goto P_0c0a2956;
P_0c0a2944: /* original e000, guest PC 0x0c0a2944 */
if(!s->budget--) { s->failed_pc=0x0c0a2944u; return 0; }
r[0]=0x00000000u;
goto P_0c0a2946;
P_0c0a2946: /* original d30d, guest PC 0x0c0a2946 */
if(!s->budget--) { s->failed_pc=0x0c0a2946u; return 0; }
r[3]=read(ram,0x0c0a297cu,4);
goto P_0c0a2948;
P_0c0a2948: /* original 430b, guest PC 0x0c0a2948 */
if(!s->budget--) { s->failed_pc=0x0c0a2948u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a294cu;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a294cu) { target=s->pc; goto dispatch; }
goto P_0c0a294c;
P_0c0a294a: /* original 65e3, guest PC 0x0c0a294a */
if(!s->budget--) { s->failed_pc=0x0c0a294au; return 0; }
r[5]=r[14];
goto P_0c0a294c;
P_0c0a294c: /* original b173, guest PC 0x0c0a294c */
if(!s->budget--) { s->failed_pc=0x0c0a294cu; return 0; }
target=0x0c0a2c36u; r[16]=code_base|0x0c0a2950u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2950u) { target=s->pc; goto dispatch; }
goto P_0c0a2950;
P_0c0a294e: /* original 64d3, guest PC 0x0c0a294e */
if(!s->budget--) { s->failed_pc=0x0c0a294eu; return 0; }
r[4]=r[13];
goto P_0c0a2950;
P_0c0a2950: /* original 54d6, guest PC 0x0c0a2950 */
if(!s->budget--) { s->failed_pc=0x0c0a2950u; return 0; }
r[4]=read(ram,r[13]+24,4);
goto P_0c0a2952;
P_0c0a2952: /* original 34ec, guest PC 0x0c0a2952 */
if(!s->budget--) { s->failed_pc=0x0c0a2952u; return 0; }
r[4]+=r[14];
goto P_0c0a2954;
P_0c0a2954: /* original 6043, guest PC 0x0c0a2954 */
if(!s->budget--) { s->failed_pc=0x0c0a2954u; return 0; }
r[0]=r[4];
goto P_0c0a2956;
P_0c0a2956: /* original 4f26, guest PC 0x0c0a2956 */
if(!s->budget--) { s->failed_pc=0x0c0a2956u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2958;
P_0c0a2958: /* original 6df6, guest PC 0x0c0a2958 */
if(!s->budget--) { s->failed_pc=0x0c0a2958u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a295a;
P_0c0a295a: /* original 000b, guest PC 0x0c0a295a */
if(!s->budget--) { s->failed_pc=0x0c0a295au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a295c: /* original 6ef6, guest PC 0x0c0a295c */
if(!s->budget--) { s->failed_pc=0x0c0a295cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a295eu,s,ram);
P_0c0a7ba8: /* original 902d, guest PC 0x0c0a7ba8 */
if(!s->budget--) { s->failed_pc=0x0c0a7ba8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7c06u,2);
goto P_0c0a7baa;
P_0c0a7baa: /* original e300, guest PC 0x0c0a7baa */
if(!s->budget--) { s->failed_pc=0x0c0a7baau; return 0; }
r[3]=0x00000000u;
goto P_0c0a7bac;
P_0c0a7bac: /* original d417, guest PC 0x0c0a7bac */
if(!s->budget--) { s->failed_pc=0x0c0a7bacu; return 0; }
r[4]=read(ram,0x0c0a7c0cu,4);
goto P_0c0a7bae;
P_0c0a7bae: /* original 6233, guest PC 0x0c0a7bae */
if(!s->budget--) { s->failed_pc=0x0c0a7baeu; return 0; }
r[2]=r[3];
goto P_0c0a7bb0;
P_0c0a7bb0: /* original 0435, guest PC 0x0c0a7bb0 */
if(!s->budget--) { s->failed_pc=0x0c0a7bb0u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0a7bb2;
P_0c0a7bb2: /* original 70ff, guest PC 0x0c0a7bb2 */
if(!s->budget--) { s->failed_pc=0x0c0a7bb2u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0a7bb4;
P_0c0a7bb4: /* original 0424, guest PC 0x0c0a7bb4 */
if(!s->budget--) { s->failed_pc=0x0c0a7bb4u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0a7bb6;
P_0c0a7bb6: /* original 70ff, guest PC 0x0c0a7bb6 */
if(!s->budget--) { s->failed_pc=0x0c0a7bb6u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0a7bb8;
P_0c0a7bb8: /* original 0424, guest PC 0x0c0a7bb8 */
if(!s->budget--) { s->failed_pc=0x0c0a7bb8u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0a7bba;
P_0c0a7bba: /* original 70f4, guest PC 0x0c0a7bba */
if(!s->budget--) { s->failed_pc=0x0c0a7bbau; return 0; }
r[0]+=0xfffffff4u;
goto P_0c0a7bbc;
P_0c0a7bbc: /* original 622e, guest PC 0x0c0a7bbc */
if(!s->budget--) { s->failed_pc=0x0c0a7bbcu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[2];
goto P_0c0a7bbe;
P_0c0a7bbe: /* original 0425, guest PC 0x0c0a7bbe */
if(!s->budget--) { s->failed_pc=0x0c0a7bbeu; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0a7bc0;
P_0c0a7bc0: /* original 70fe, guest PC 0x0c0a7bc0 */
if(!s->budget--) { s->failed_pc=0x0c0a7bc0u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0a7bc2;
P_0c0a7bc2: /* original 0425, guest PC 0x0c0a7bc2 */
if(!s->budget--) { s->failed_pc=0x0c0a7bc2u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0a7bc4;
P_0c0a7bc4: /* original 70fe, guest PC 0x0c0a7bc4 */
if(!s->budget--) { s->failed_pc=0x0c0a7bc4u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0a7bc6;
P_0c0a7bc6: /* original 0425, guest PC 0x0c0a7bc6 */
if(!s->budget--) { s->failed_pc=0x0c0a7bc6u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0a7bc8;
P_0c0a7bc8: /* original 901e, guest PC 0x0c0a7bc8 */
if(!s->budget--) { s->failed_pc=0x0c0a7bc8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7c08u,2);
goto P_0c0a7bca;
P_0c0a7bca: /* original d611, guest PC 0x0c0a7bca */
if(!s->budget--) { s->failed_pc=0x0c0a7bcau; return 0; }
r[6]=read(ram,0x0c0a7c10u,4);
goto P_0c0a7bcc;
P_0c0a7bcc: /* original 004c, guest PC 0x0c0a7bcc */
if(!s->budget--) { s->failed_pc=0x0c0a7bccu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a7bce;
P_0c0a7bce: /* original 8801, guest PC 0x0c0a7bce */
if(!s->budget--) { s->failed_pc=0x0c0a7bceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a7bd0;
P_0c0a7bd0: /* original 8f02, guest PC 0x0c0a7bd0 */
if(!s->budget--) { s->failed_pc=0x0c0a7bd0u; return 0; }
cond=r[17]&1u;
r[0]=0x00000061u;
if(!cond) { goto P_0c0a7bd8; }
goto P_0c0a7bd4;
P_0c0a7bd2: /* original e061, guest PC 0x0c0a7bd2 */
if(!s->budget--) { s->failed_pc=0x0c0a7bd2u; return 0; }
r[0]=0x00000061u;
goto P_0c0a7bd4;
P_0c0a7bd4: /* original a001, guest PC 0x0c0a7bd4 */
if(!s->budget--) { s->failed_pc=0x0c0a7bd4u; return 0; }
r[5]=read(ram,r[6]+16,4);
goto P_0c0a7bda;
P_0c0a7bd6: /* original 5564, guest PC 0x0c0a7bd6 */
if(!s->budget--) { s->failed_pc=0x0c0a7bd6u; return 0; }
r[5]=read(ram,r[6]+16,4);
goto P_0c0a7bd8;
P_0c0a7bd8: /* original 5565, guest PC 0x0c0a7bd8 */
if(!s->budget--) { s->failed_pc=0x0c0a7bd8u; return 0; }
r[5]=read(ram,r[6]+20,4);
goto P_0c0a7bda;
P_0c0a7bda: /* original 035c, guest PC 0x0c0a7bda */
if(!s->budget--) { s->failed_pc=0x0c0a7bdau; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0a7bdc;
P_0c0a7bdc: /* original 9015, guest PC 0x0c0a7bdc */
if(!s->budget--) { s->failed_pc=0x0c0a7bdcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7c0au,2);
goto P_0c0a7bde;
P_0c0a7bde: /* original 000b, guest PC 0x0c0a7bde */
if(!s->budget--) { s->failed_pc=0x0c0a7bdeu; return 0; }
target=r[16];
write(ram,r[4]+r[0],r[3],1);
s->pc=target; return ram->oob==0;
P_0c0a7be0: /* original 0434, guest PC 0x0c0a7be0 */
if(!s->budget--) { s->failed_pc=0x0c0a7be0u; return 0; }
write(ram,r[4]+r[0],r[3],1);
return vf3_matrix_family(0x0c0a7be2u,s,ram);
P_0c0a87aa: /* original 901e, guest PC 0x0c0a87aa */
if(!s->budget--) { s->failed_pc=0x0c0a87aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a87eau,2);
goto P_0c0a87ac;
P_0c0a87ac: /* original e400, guest PC 0x0c0a87ac */
if(!s->budget--) { s->failed_pc=0x0c0a87acu; return 0; }
r[4]=0x00000000u;
goto P_0c0a87ae;
P_0c0a87ae: /* original d511, guest PC 0x0c0a87ae */
if(!s->budget--) { s->failed_pc=0x0c0a87aeu; return 0; }
r[5]=read(ram,0x0c0a87f4u,4);
goto P_0c0a87b0;
P_0c0a87b0: /* original 0546, guest PC 0x0c0a87b0 */
if(!s->budget--) { s->failed_pc=0x0c0a87b0u; return 0; }
write(ram,r[5]+r[0],r[4],4);
goto P_0c0a87b2;
P_0c0a87b2: /* original 7004, guest PC 0x0c0a87b2 */
if(!s->budget--) { s->failed_pc=0x0c0a87b2u; return 0; }
r[0]+=0x00000004u;
goto P_0c0a87b4;
P_0c0a87b4: /* original 0546, guest PC 0x0c0a87b4 */
if(!s->budget--) { s->failed_pc=0x0c0a87b4u; return 0; }
write(ram,r[5]+r[0],r[4],4);
goto P_0c0a87b6;
P_0c0a87b6: /* original 7004, guest PC 0x0c0a87b6 */
if(!s->budget--) { s->failed_pc=0x0c0a87b6u; return 0; }
r[0]+=0x00000004u;
goto P_0c0a87b8;
P_0c0a87b8: /* original 0544, guest PC 0x0c0a87b8 */
if(!s->budget--) { s->failed_pc=0x0c0a87b8u; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c0a87ba;
P_0c0a87ba: /* original 9617, guest PC 0x0c0a87ba */
if(!s->budget--) { s->failed_pc=0x0c0a87bau; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a87ecu,2);
goto P_0c0a87bc;
P_0c0a87bc: /* original d50e, guest PC 0x0c0a87bc */
if(!s->budget--) { s->failed_pc=0x0c0a87bcu; return 0; }
r[5]=read(ram,0x0c0a87f8u,4);
goto P_0c0a87be;
P_0c0a87be: /* original 2542, guest PC 0x0c0a87be */
if(!s->budget--) { s->failed_pc=0x0c0a87beu; return 0; }
write(ram,r[5],r[4],4);
goto P_0c0a87c0;
P_0c0a87c0: /* original 7504, guest PC 0x0c0a87c0 */
if(!s->budget--) { s->failed_pc=0x0c0a87c0u; return 0; }
r[5]+=0x00000004u;
goto P_0c0a87c2;
P_0c0a87c2: /* original 2542, guest PC 0x0c0a87c2 */
if(!s->budget--) { s->failed_pc=0x0c0a87c2u; return 0; }
write(ram,r[5],r[4],4);
goto P_0c0a87c4;
P_0c0a87c4: /* original 7504, guest PC 0x0c0a87c4 */
if(!s->budget--) { s->failed_pc=0x0c0a87c4u; return 0; }
r[5]+=0x00000004u;
goto P_0c0a87c6;
P_0c0a87c6: /* original 2542, guest PC 0x0c0a87c6 */
if(!s->budget--) { s->failed_pc=0x0c0a87c6u; return 0; }
write(ram,r[5],r[4],4);
goto P_0c0a87c8;
P_0c0a87c8: /* original 7504, guest PC 0x0c0a87c8 */
if(!s->budget--) { s->failed_pc=0x0c0a87c8u; return 0; }
r[5]+=0x00000004u;
goto P_0c0a87ca;
P_0c0a87ca: /* original 2542, guest PC 0x0c0a87ca */
if(!s->budget--) { s->failed_pc=0x0c0a87cau; return 0; }
write(ram,r[5],r[4],4);
goto P_0c0a87cc;
P_0c0a87cc: /* original 7504, guest PC 0x0c0a87cc */
if(!s->budget--) { s->failed_pc=0x0c0a87ccu; return 0; }
r[5]+=0x00000004u;
goto P_0c0a87ce;
P_0c0a87ce: /* original 2542, guest PC 0x0c0a87ce */
if(!s->budget--) { s->failed_pc=0x0c0a87ceu; return 0; }
write(ram,r[5],r[4],4);
goto P_0c0a87d0;
P_0c0a87d0: /* original 7504, guest PC 0x0c0a87d0 */
if(!s->budget--) { s->failed_pc=0x0c0a87d0u; return 0; }
r[5]+=0x00000004u;
goto P_0c0a87d2;
P_0c0a87d2: /* original 2542, guest PC 0x0c0a87d2 */
if(!s->budget--) { s->failed_pc=0x0c0a87d2u; return 0; }
write(ram,r[5],r[4],4);
goto P_0c0a87d4;
P_0c0a87d4: /* original 7504, guest PC 0x0c0a87d4 */
if(!s->budget--) { s->failed_pc=0x0c0a87d4u; return 0; }
r[5]+=0x00000004u;
goto P_0c0a87d6;
P_0c0a87d6: /* original 2542, guest PC 0x0c0a87d6 */
if(!s->budget--) { s->failed_pc=0x0c0a87d6u; return 0; }
write(ram,r[5],r[4],4);
goto P_0c0a87d8;
P_0c0a87d8: /* original 76ff, guest PC 0x0c0a87d8 */
if(!s->budget--) { s->failed_pc=0x0c0a87d8u; return 0; }
r[6]+=0xffffffffu;
goto P_0c0a87da;
P_0c0a87da: /* original e300, guest PC 0x0c0a87da */
if(!s->budget--) { s->failed_pc=0x0c0a87dau; return 0; }
r[3]=0x00000000u;
goto P_0c0a87dc;
P_0c0a87dc: /* original 7504, guest PC 0x0c0a87dc */
if(!s->budget--) { s->failed_pc=0x0c0a87dcu; return 0; }
r[5]+=0x00000004u;
goto P_0c0a87de;
P_0c0a87de: /* original 3636, guest PC 0x0c0a87de */
if(!s->budget--) { s->failed_pc=0x0c0a87deu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>r[3])!=0);
goto P_0c0a87e0;
P_0c0a87e0: /* original 2542, guest PC 0x0c0a87e0 */
if(!s->budget--) { s->failed_pc=0x0c0a87e0u; return 0; }
write(ram,r[5],r[4],4);
goto P_0c0a87e2;
P_0c0a87e2: /* original 8dec, guest PC 0x0c0a87e2 */
if(!s->budget--) { s->failed_pc=0x0c0a87e2u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(cond) { goto P_0c0a87be; }
goto P_0c0a87e6;
P_0c0a87e4: /* original 7504, guest PC 0x0c0a87e4 */
if(!s->budget--) { s->failed_pc=0x0c0a87e4u; return 0; }
r[5]+=0x00000004u;
goto P_0c0a87e6;
P_0c0a87e6: /* original 000b, guest PC 0x0c0a87e6 */
if(!s->budget--) { s->failed_pc=0x0c0a87e6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a87e8: /* original 0009, guest PC 0x0c0a87e8 */
if(!s->budget--) { s->failed_pc=0x0c0a87e8u; return 0; }
return vf3_matrix_family(0x0c0a87eau,s,ram);
P_0c0c1a66: /* original 4f22, guest PC 0x0c0c1a66 */
if(!s->budget--) { s->failed_pc=0x0c0c1a66u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c1a68;
P_0c0c1a68: /* original 7ff8, guest PC 0x0c0c1a68 */
if(!s->budget--) { s->failed_pc=0x0c0c1a68u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c1a6a;
P_0c0c1a6a: /* original 2f62, guest PC 0x0c0c1a6a */
if(!s->budget--) { s->failed_pc=0x0c0c1a6au; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0c1a6c;
P_0c0c1a6c: /* original 1f71, guest PC 0x0c0c1a6c */
if(!s->budget--) { s->failed_pc=0x0c0c1a6cu; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c0c1a6e;
P_0c0c1a6e: /* original 53f4, guest PC 0x0c0c1a6e */
if(!s->budget--) { s->failed_pc=0x0c0c1a6eu; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c0c1a70;
P_0c0c1a70: /* original 2f36, guest PC 0x0c0c1a70 */
if(!s->budget--) { s->failed_pc=0x0c0c1a70u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1a72;
P_0c0c1a72: /* original 52f4, guest PC 0x0c0c1a72 */
if(!s->budget--) { s->failed_pc=0x0c0c1a72u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0c1a74;
P_0c0c1a74: /* original 2f26, guest PC 0x0c0c1a74 */
if(!s->budget--) { s->failed_pc=0x0c0c1a74u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1a76;
P_0c0c1a76: /* original 53f3, guest PC 0x0c0c1a76 */
if(!s->budget--) { s->failed_pc=0x0c0c1a76u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0c1a78;
P_0c0c1a78: /* original 2f36, guest PC 0x0c0c1a78 */
if(!s->budget--) { s->failed_pc=0x0c0c1a78u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c1a7a;
P_0c0c1a7a: /* original 9608, guest PC 0x0c0c1a7a */
if(!s->budget--) { s->failed_pc=0x0c0c1a7au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1a8eu,2);
goto P_0c0c1a7c;
P_0c0c1a7c: /* original bbe7, guest PC 0x0c0c1a7c */
if(!s->budget--) { s->failed_pc=0x0c0c1a7cu; return 0; }
target=0x0c0c124eu; r[16]=code_base|0x0c0c1a80u;
r[7]=read(ram,r[15]+12,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1a80u) { target=s->pc; goto dispatch; }
goto P_0c0c1a80;
P_0c0c1a7e: /* original 57f3, guest PC 0x0c0c1a7e */
if(!s->budget--) { s->failed_pc=0x0c0c1a7eu; return 0; }
r[7]=read(ram,r[15]+12,4);
goto P_0c0c1a80;
P_0c0c1a80: /* original 7f14, guest PC 0x0c0c1a80 */
if(!s->budget--) { s->failed_pc=0x0c0c1a80u; return 0; }
r[15]+=0x00000014u;
goto P_0c0c1a82;
P_0c0c1a82: /* original 4f26, guest PC 0x0c0c1a82 */
if(!s->budget--) { s->failed_pc=0x0c0c1a82u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c1a84;
P_0c0c1a84: /* original 000b, guest PC 0x0c0c1a84 */
if(!s->budget--) { s->failed_pc=0x0c0c1a84u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c1a86: /* original 0009, guest PC 0x0c0c1a86 */
if(!s->budget--) { s->failed_pc=0x0c0c1a86u; return 0; }
return vf3_matrix_family(0x0c0c1a88u,s,ram);
P_0c0c2d06: /* original 2fe6, guest PC 0x0c0c2d06 */
if(!s->budget--) { s->failed_pc=0x0c0c2d06u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2d08;
P_0c0c2d08: /* original 2fd6, guest PC 0x0c0c2d08 */
if(!s->budget--) { s->failed_pc=0x0c0c2d08u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2d0a;
P_0c0c2d0a: /* original 2fc6, guest PC 0x0c0c2d0a */
if(!s->budget--) { s->failed_pc=0x0c0c2d0au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2d0c;
P_0c0c2d0c: /* original 2fb6, guest PC 0x0c0c2d0c */
if(!s->budget--) { s->failed_pc=0x0c0c2d0cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2d0e;
P_0c0c2d0e: /* original fffb, guest PC 0x0c0c2d0e */
if(!s->budget--) { s->failed_pc=0x0c0c2d0eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
return vf3_matrix_family(0x0c0c2d10u,s,ram);
P_0c0c74bc: /* original 4f22, guest PC 0x0c0c74bc */
if(!s->budget--) { s->failed_pc=0x0c0c74bcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c74be;
P_0c0c74be: /* original dd22, guest PC 0x0c0c74be */
if(!s->budget--) { s->failed_pc=0x0c0c74beu; return 0; }
r[13]=read(ram,0x0c0c7548u,4);
goto P_0c0c74c0;
P_0c0c74c0: /* original d320, guest PC 0x0c0c74c0 */
if(!s->budget--) { s->failed_pc=0x0c0c74c0u; return 0; }
r[3]=read(ram,0x0c0c7544u,4);
goto P_0c0c74c2;
P_0c0c74c2: /* original 4f12, guest PC 0x0c0c74c2 */
if(!s->budget--) { s->failed_pc=0x0c0c74c2u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c74c4;
P_0c0c74c4: /* original 7ff8, guest PC 0x0c0c74c4 */
if(!s->budget--) { s->failed_pc=0x0c0c74c4u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c74c6;
P_0c0c74c6: /* original 4d0b, guest PC 0x0c0c74c6 */
if(!s->budget--) { s->failed_pc=0x0c0c74c6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c74cau;
write(ram,r[15]+4,r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c74cau) { target=s->pc; goto dispatch; }
goto P_0c0c74ca;
P_0c0c74c8: /* original 1f31, guest PC 0x0c0c74c8 */
if(!s->budget--) { s->failed_pc=0x0c0c74c8u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c74ca;
P_0c0c74ca: /* original 6403, guest PC 0x0c0c74ca */
if(!s->budget--) { s->failed_pc=0x0c0c74cau; return 0; }
r[4]=r[0];
goto P_0c0c74cc;
P_0c0c74cc: /* original e20f, guest PC 0x0c0c74cc */
if(!s->budget--) { s->failed_pc=0x0c0c74ccu; return 0; }
r[2]=0x0000000fu;
goto P_0c0c74ce;
P_0c0c74ce: /* original d01f, guest PC 0x0c0c74ce */
if(!s->budget--) { s->failed_pc=0x0c0c74ceu; return 0; }
r[0]=read(ram,0x0c0c754cu,4);
goto P_0c0c74d0;
P_0c0c74d0: /* original 2429, guest PC 0x0c0c74d0 */
if(!s->budget--) { s->failed_pc=0x0c0c74d0u; return 0; }
r[4]&=r[2];
goto P_0c0c74d2;
P_0c0c74d2: /* original 53f1, guest PC 0x0c0c74d2 */
if(!s->budget--) { s->failed_pc=0x0c0c74d2u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c74d4;
P_0c0c74d4: /* original 014c, guest PC 0x0c0c74d4 */
if(!s->budget--) { s->failed_pc=0x0c0c74d4u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c74d6;
P_0c0c74d6: /* original e01c, guest PC 0x0c0c74d6 */
if(!s->budget--) { s->failed_pc=0x0c0c74d6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c74d8;
P_0c0c74d8: /* original 4d0b, guest PC 0x0c0c74d8 */
if(!s->budget--) { s->failed_pc=0x0c0c74d8u; return 0; }
target=r[13];
r[16]=code_base|0x0c0c74dcu;
write(ram,r[3]+r[0],r[1],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c74dcu) { target=s->pc; goto dispatch; }
goto P_0c0c74dc;
P_0c0c74da: /* original 0314, guest PC 0x0c0c74da */
if(!s->budget--) { s->failed_pc=0x0c0c74dau; return 0; }
write(ram,r[3]+r[0],r[1],1);
goto P_0c0c74dc;
P_0c0c74dc: /* original 4d0b, guest PC 0x0c0c74dc */
if(!s->budget--) { s->failed_pc=0x0c0c74dcu; return 0; }
target=r[13];
r[16]=code_base|0x0c0c74e0u;
r[14]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c74e0u) { target=s->pc; goto dispatch; }
goto P_0c0c74e0;
P_0c0c74de: /* original 6e03, guest PC 0x0c0c74de */
if(!s->budget--) { s->failed_pc=0x0c0c74deu; return 0; }
r[14]=r[0];
goto P_0c0c74e0;
P_0c0c74e0: /* original e60b, guest PC 0x0c0c74e0 */
if(!s->budget--) { s->failed_pc=0x0c0c74e0u; return 0; }
r[6]=0x0000000bu;
goto P_0c0c74e2;
P_0c0c74e2: /* original d31b, guest PC 0x0c0c74e2 */
if(!s->budget--) { s->failed_pc=0x0c0c74e2u; return 0; }
r[3]=read(ram,0x0c0c7550u,4);
goto P_0c0c74e4;
P_0c0c74e4: /* original 6103, guest PC 0x0c0c74e4 */
if(!s->budget--) { s->failed_pc=0x0c0c74e4u; return 0; }
r[1]=r[0];
goto P_0c0c74e6;
P_0c0c74e6: /* original e70c, guest PC 0x0c0c74e6 */
if(!s->budget--) { s->failed_pc=0x0c0c74e6u; return 0; }
r[7]=0x0000000cu;
goto P_0c0c74e8;
P_0c0c74e8: /* original 6403, guest PC 0x0c0c74e8 */
if(!s->budget--) { s->failed_pc=0x0c0c74e8u; return 0; }
r[4]=r[0];
goto P_0c0c74ea;
P_0c0c74ea: /* original 6563, guest PC 0x0c0c74ea */
if(!s->budget--) { s->failed_pc=0x0c0c74eau; return 0; }
r[5]=r[6];
goto P_0c0c74ec;
P_0c0c74ec: /* original 430b, guest PC 0x0c0c74ec */
if(!s->budget--) { s->failed_pc=0x0c0c74ecu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c74f0u;
r[0]=r[7];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c74f0u) { target=s->pc; goto dispatch; }
goto P_0c0c74f0;
P_0c0c74ee: /* original 6073, guest PC 0x0c0c74ee */
if(!s->budget--) { s->failed_pc=0x0c0c74eeu; return 0; }
r[0]=r[7];
goto P_0c0c74f0;
P_0c0c74f0: /* original 61e3, guest PC 0x0c0c74f0 */
if(!s->budget--) { s->failed_pc=0x0c0c74f0u; return 0; }
r[1]=r[14];
goto P_0c0c74f2;
P_0c0c74f2: /* original 2f02, guest PC 0x0c0c74f2 */
if(!s->budget--) { s->failed_pc=0x0c0c74f2u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0c74f4;
P_0c0c74f4: /* original d316, guest PC 0x0c0c74f4 */
if(!s->budget--) { s->failed_pc=0x0c0c74f4u; return 0; }
r[3]=read(ram,0x0c0c7550u,4);
goto P_0c0c74f6;
P_0c0c74f6: /* original 430b, guest PC 0x0c0c74f6 */
if(!s->budget--) { s->failed_pc=0x0c0c74f6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c74fau;
r[0]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c74fau) { target=s->pc; goto dispatch; }
goto P_0c0c74fa;
P_0c0c74f8: /* original 6053, guest PC 0x0c0c74f8 */
if(!s->budget--) { s->failed_pc=0x0c0c74f8u; return 0; }
r[0]=r[5];
goto P_0c0c74fa;
P_0c0c74fa: /* original 1f01, guest PC 0x0c0c74fa */
if(!s->budget--) { s->failed_pc=0x0c0c74fau; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0c74fc;
P_0c0c74fc: /* original 63f2, guest PC 0x0c0c74fc */
if(!s->budget--) { s->failed_pc=0x0c0c74fcu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c74fe;
P_0c0c74fe: /* original 6233, guest PC 0x0c0c74fe */
if(!s->budget--) { s->failed_pc=0x0c0c74feu; return 0; }
r[2]=r[3];
goto P_0c0c7500;
P_0c0c7500: /* original 4300, guest PC 0x0c0c7500 */
if(!s->budget--) { s->failed_pc=0x0c0c7500u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c7502;
P_0c0c7502: /* original 332c, guest PC 0x0c0c7502 */
if(!s->budget--) { s->failed_pc=0x0c0c7502u; return 0; }
r[3]+=r[2];
goto P_0c0c7504;
P_0c0c7504: /* original 4308, guest PC 0x0c0c7504 */
if(!s->budget--) { s->failed_pc=0x0c0c7504u; return 0; }
r[3]<<=2;
goto P_0c0c7506;
P_0c0c7506: /* original 3438, guest PC 0x0c0c7506 */
if(!s->budget--) { s->failed_pc=0x0c0c7506u; return 0; }
r[4]-=r[3];
goto P_0c0c7508;
P_0c0c7508: /* original 2f32, guest PC 0x0c0c7508 */
if(!s->budget--) { s->failed_pc=0x0c0c7508u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c750a;
P_0c0c750a: /* original 52f1, guest PC 0x0c0c750a */
if(!s->budget--) { s->failed_pc=0x0c0c750au; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0c750c;
P_0c0c750c: /* original 6043, guest PC 0x0c0c750c */
if(!s->budget--) { s->failed_pc=0x0c0c750cu; return 0; }
r[0]=r[4];
goto P_0c0c750e;
P_0c0c750e: /* original 8809, guest PC 0x0c0c750e */
if(!s->budget--) { s->failed_pc=0x0c0c750eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0c7510;
P_0c0c7510: /* original 0527, guest PC 0x0c0c7510 */
if(!s->budget--) { s->failed_pc=0x0c0c7510u; return 0; }
r[19]=r[5]*r[2];
goto P_0c0c7512;
P_0c0c7512: /* original 051a, guest PC 0x0c0c7512 */
if(!s->budget--) { s->failed_pc=0x0c0c7512u; return 0; }
r[5]=r[19];
goto P_0c0c7514;
P_0c0c7514: /* original 8f01, guest PC 0x0c0c7514 */
if(!s->budget--) { s->failed_pc=0x0c0c7514u; return 0; }
cond=r[17]&1u;
r[14]-=r[5];
if(!cond) { goto P_0c0c751a; }
goto P_0c0c7518;
P_0c0c7516: /* original 3e58, guest PC 0x0c0c7516 */
if(!s->budget--) { s->failed_pc=0x0c0c7516u; return 0; }
r[14]-=r[5];
goto P_0c0c7518;
P_0c0c7518: /* original 6473, guest PC 0x0c0c7518 */
if(!s->budget--) { s->failed_pc=0x0c0c7518u; return 0; }
r[4]=r[7];
goto P_0c0c751a;
P_0c0c751a: /* original 60e3, guest PC 0x0c0c751a */
if(!s->budget--) { s->failed_pc=0x0c0c751au; return 0; }
r[0]=r[14];
goto P_0c0c751c;
P_0c0c751c: /* original 8809, guest PC 0x0c0c751c */
if(!s->budget--) { s->failed_pc=0x0c0c751cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0c751e;
P_0c0c751e: /* original 8b00, guest PC 0x0c0c751e */
if(!s->budget--) { s->failed_pc=0x0c0c751eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7522; }
goto P_0c0c7520;
P_0c0c7520: /* original 6e63, guest PC 0x0c0c7520 */
if(!s->budget--) { s->failed_pc=0x0c0c7520u; return 0; }
r[14]=r[6];
goto P_0c0c7522;
P_0c0c7522: /* original 34e0, guest PC 0x0c0c7522 */
if(!s->budget--) { s->failed_pc=0x0c0c7522u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[14])!=0);
goto P_0c0c7524;
P_0c0c7524: /* original 8b00, guest PC 0x0c0c7524 */
if(!s->budget--) { s->failed_pc=0x0c0c7524u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7528; }
goto P_0c0c7526;
P_0c0c7526: /* original 6e73, guest PC 0x0c0c7526 */
if(!s->budget--) { s->failed_pc=0x0c0c7526u; return 0; }
r[14]=r[7];
goto P_0c0c7528;
P_0c0c7528: /* original d60a, guest PC 0x0c0c7528 */
if(!s->budget--) { s->failed_pc=0x0c0c7528u; return 0; }
r[6]=read(ram,0x0c0c7554u,4);
goto P_0c0c752a;
P_0c0c752a: /* original e060, guest PC 0x0c0c752a */
if(!s->budget--) { s->failed_pc=0x0c0c752au; return 0; }
r[0]=0x00000060u;
goto P_0c0c752c;
P_0c0c752c: /* original 7e0d, guest PC 0x0c0c752c */
if(!s->budget--) { s->failed_pc=0x0c0c752cu; return 0; }
r[14]+=0x0000000du;
goto P_0c0c752e;
P_0c0c752e: /* original 5565, guest PC 0x0c0c752e */
if(!s->budget--) { s->failed_pc=0x0c0c752eu; return 0; }
r[5]=read(ram,r[6]+20,4);
goto P_0c0c7530;
P_0c0c7530: /* original 5664, guest PC 0x0c0c7530 */
if(!s->budget--) { s->failed_pc=0x0c0c7530u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0c7532;
P_0c0c7532: /* original 0544, guest PC 0x0c0c7532 */
if(!s->budget--) { s->failed_pc=0x0c0c7532u; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c0c7534;
P_0c0c7534: /* original b38c, guest PC 0x0c0c7534 */
if(!s->budget--) { s->failed_pc=0x0c0c7534u; return 0; }
target=0x0c0c7c50u; r[16]=code_base|0x0c0c7538u;
write(ram,r[6]+r[0],r[14],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7538u) { target=s->pc; goto dispatch; }
goto P_0c0c7538;
P_0c0c7536: /* original 06e4, guest PC 0x0c0c7536 */
if(!s->budget--) { s->failed_pc=0x0c0c7536u; return 0; }
write(ram,r[6]+r[0],r[14],1);
goto P_0c0c7538;
P_0c0c7538: /* original 7f08, guest PC 0x0c0c7538 */
if(!s->budget--) { s->failed_pc=0x0c0c7538u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c753a;
P_0c0c753a: /* original 4f16, guest PC 0x0c0c753a */
if(!s->budget--) { s->failed_pc=0x0c0c753au; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c753c;
P_0c0c753c: /* original 4f26, guest PC 0x0c0c753c */
if(!s->budget--) { s->failed_pc=0x0c0c753cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c753e;
P_0c0c753e: /* original 6df6, guest PC 0x0c0c753e */
if(!s->budget--) { s->failed_pc=0x0c0c753eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c7540;
P_0c0c7540: /* original a8ce, guest PC 0x0c0c7540 */
if(!s->budget--) { s->failed_pc=0x0c0c7540u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c66e0u,s,ram);
P_0c0c7542: /* original 6ef6, guest PC 0x0c0c7542 */
if(!s->budget--) { s->failed_pc=0x0c0c7542u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c7544u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c02eed8u,0x0c02eedau,0x0c02eedcu,0x0c02eedeu,0x0c02eee0u,0x0c02eee2u,0x0c02eee4u,0x0c02eee6u,0x0c02eee8u,0x0c0364b8u,0x0c0364bau,0x0c0364bcu,0x0c0364beu,0x0c0364c0u,0x0c0364c2u,0x0c036dd4u,
0x0c036dd6u,0x0c036dd8u,0x0c036ddau,0x0c036ddcu,0x0c036ddeu,0x0c036de0u,0x0c036de2u,0x0c036de4u,0x0c036de6u,0x0c036de8u,0x0c036deau,0x0c036decu,0x0c036deeu,0x0c036df0u,0x0c036df2u,0x0c036df4u,
0x0c036df6u,0x0c036df8u,0x0c036dfau,0x0c036dfcu,0x0c036dfeu,0x0c036e00u,0x0c036e02u,0x0c036e04u,0x0c036e06u,0x0c036e08u,0x0c036e0au,0x0c036e0cu,0x0c036e0eu,0x0c036e10u,0x0c036e12u,0x0c036e14u,
0x0c036e16u,0x0c036e18u,0x0c036e1au,0x0c036e1cu,0x0c036e1eu,0x0c036e20u,0x0c03750au,0x0c03750cu,0x0c03750eu,0x0c037510u,0x0c037512u,0x0c037514u,0x0c037516u,0x0c037518u,0x0c03751au,0x0c03751cu,
0x0c03751eu,0x0c037520u,0x0c037522u,0x0c037524u,0x0c037526u,0x0c037528u,0x0c03752au,0x0c03752cu,0x0c03752eu,0x0c037530u,0x0c037532u,0x0c037534u,0x0c037536u,0x0c037538u,0x0c03753au,0x0c03753cu,
0x0c03753eu,0x0c037540u,0x0c037542u,0x0c037544u,0x0c037546u,0x0c037548u,0x0c037578u,0x0c03757au,0x0c037864u,0x0c037866u,0x0c037868u,0x0c03786au,0x0c03786cu,0x0c03786eu,0x0c037870u,0x0c037872u,
0x0c037874u,0x0c037876u,0x0c037878u,0x0c039080u,0x0c039082u,0x0c039084u,0x0c039086u,0x0c039088u,0x0c03908au,0x0c03908cu,0x0c03908eu,0x0c039090u,0x0c039092u,0x0c039094u,0x0c039096u,0x0c039098u,
0x0c03909au,0x0c03909cu,0x0c03909eu,0x0c0390a0u,0x0c0390a2u,0x0c0390a4u,0x0c0390a6u,0x0c0390a8u,0x0c0390aau,0x0c0390acu,0x0c0390aeu,0x0c0390b0u,0x0c0390b2u,0x0c0390b4u,0x0c0390b6u,0x0c0390b8u,
0x0c0390bau,0x0c0390bcu,0x0c0390beu,0x0c0390c0u,0x0c0390c2u,0x0c0390c4u,0x0c0390c6u,0x0c0390c8u,0x0c0390cau,0x0c0390ccu,0x0c0390ceu,0x0c0390d0u,0x0c0390d2u,0x0c0390d4u,0x0c0390d6u,0x0c0390d8u,
0x0c0390dau,0x0c0393c0u,0x0c0393c2u,0x0c0393c4u,0x0c0393c6u,0x0c0393c8u,0x0c0393cau,0x0c0393ccu,0x0c0393ceu,0x0c0393d0u,0x0c0393d2u,0x0c0393d4u,0x0c0393e0u,0x0c0393e2u,0x0c0393e4u,0x0c0393e6u,
0x0c0393e8u,0x0c0393eau,0x0c0393ecu,0x0c0393eeu,0x0c0393f0u,0x0c0393f2u,0x0c0393f4u,0x0c0394e0u,0x0c0394e2u,0x0c0394e4u,0x0c0394e6u,0x0c0394e8u,0x0c0394eau,0x0c0394ecu,0x0c0394eeu,0x0c0394f0u,
0x0c0394f2u,0x0c0394f4u,0x0c0394f6u,0x0c0394f8u,0x0c0397a0u,0x0c0397a2u,0x0c0397a4u,0x0c0397a6u,0x0c0397a8u,0x0c0397aau,0x0c0397acu,0x0c0397aeu,0x0c0397b0u,0x0c0397b2u,0x0c039c90u,0x0c039c92u,
0x0c039c94u,0x0c039c96u,0x0c039c98u,0x0c039c9au,0x0c039c9cu,0x0c039c9eu,0x0c039ca0u,0x0c039ca2u,0x0c039ca4u,0x0c039ca6u,0x0c039ca8u,0x0c039caau,0x0c03b2d0u,0x0c03b2d2u,0x0c03b2d4u,0x0c03b2d6u,
0x0c03b2d8u,0x0c03b2dau,0x0c03b2dcu,0x0c03b2deu,0x0c03b2e0u,0x0c03b2e2u,0x0c03b2e4u,0x0c03b2e6u,0x0c03b2e8u,0x0c03b2eau,0x0c03b2ecu,0x0c03b2eeu,0x0c03b2f0u,0x0c03b2f2u,0x0c03b2f4u,0x0c03d0c0u,
0x0c03d0c2u,0x0c03d0c4u,0x0c03d0c6u,0x0c03d0c8u,0x0c03d0cau,0x0c03d0ccu,0x0c03d0ceu,0x0c03d0d0u,0x0c03d0d2u,0x0c03d0d4u,0x0c03d0d6u,0x0c03d0d8u,0x0c03d0dau,0x0c03d280u,0x0c03d282u,0x0c03d284u,
0x0c03d286u,0x0c03d288u,0x0c03d28au,0x0c03d28cu,0x0c03d28eu,0x0c03d290u,0x0c03d292u,0x0c03d294u,0x0c03d296u,0x0c03d298u,0x0c03d29au,0x0c03d29cu,0x0c03d29eu,0x0c03d2a0u,0x0c03d2a2u,0x0c03d2a4u,
0x0c03d2a6u,0x0c03da30u,0x0c03da32u,0x0c03da34u,0x0c03da36u,0x0c03da38u,0x0c03da3au,0x0c03da3cu,0x0c03da3eu,0x0c03da40u,0x0c03da42u,0x0c03da44u,0x0c03da46u,0x0c03da48u,0x0c03da4au,0x0c03da4cu,
0x0c03da4eu,0x0c03ecd0u,0x0c03ecd2u,0x0c03ecd4u,0x0c03ecd6u,0x0c03ecd8u,0x0c03ecdau,0x0c03ecdcu,0x0c03ecdeu,0x0c03ece0u,0x0c03ece2u,0x0c03ece4u,0x0c03ece6u,0x0c03ece8u,0x0c03eceau,0x0c03ececu,
0x0c03ed20u,0x0c03ed22u,0x0c03ed24u,0x0c03ed26u,0x0c03ed28u,0x0c03ed2au,0x0c03ed2cu,0x0c03ed2eu,0x0c03ed30u,0x0c03ed32u,0x0c03ed34u,0x0c03ed36u,0x0c03ed38u,0x0c03ed3au,0x0c03ed3cu,0x0c03ed3eu,
0x0c03ed40u,0x0c03ed42u,0x0c03ed44u,0x0c03ef10u,0x0c03ef12u,0x0c03ef14u,0x0c03ef16u,0x0c03ef18u,0x0c03ef1au,0x0c03ef1cu,0x0c03ef1eu,0x0c03ef20u,0x0c03ef22u,0x0c03ef24u,0x0c03ef26u,0x0c03ef28u,
0x0c03ef2au,0x0c03ef2cu,0x0c03ef2eu,0x0c03ef30u,0x0c03ef32u,0x0c03ef34u,0x0c03ef36u,0x0c03ef38u,0x0c03ef3au,0x0c03ef3cu,0x0c03ef3eu,0x0c03ef40u,0x0c03ef42u,0x0c03ef44u,0x0c03ef46u,0x0c03ef48u,
0x0c03ef4au,0x0c03ef4cu,0x0c03ef4eu,0x0c03ef50u,0x0c03ef52u,0x0c03ef54u,0x0c03ef56u,0x0c03ef58u,0x0c03ef5au,0x0c03ef5cu,0x0c03ef5eu,0x0c03ef60u,0x0c03ef62u,0x0c03ef64u,0x0c03ef66u,0x0c03ef68u,
0x0c03ef6au,0x0c03ef6cu,0x0c03ef6eu,0x0c03ef70u,0x0c03ef72u,0x0c03ef74u,0x0c03ef76u,0x0c03ef78u,0x0c03ef7au,0x0c03ef7cu,0x0c03ef7eu,0x0c03ef80u,0x0c03ef82u,0x0c03ef84u,0x0c03ef86u,0x0c03ef88u,
0x0c03ef8au,0x0c03ef8cu,0x0c03ef8eu,0x0c03ef90u,0x0c03ffb0u,0x0c03ffb2u,0x0c03ffb4u,0x0c03ffb6u,0x0c03ffb8u,0x0c03ffbau,0x0c03ffbcu,0x0c03ffbeu,0x0c043e52u,0x0c043e54u,0x0c043e56u,0x0c043e58u,
0x0c043e5au,0x0c043e5cu,0x0c043e5eu,0x0c043e60u,0x0c043e62u,0x0c043e64u,0x0c043e66u,0x0c043e68u,0x0c043e6au,0x0c043e6cu,0x0c043e6eu,0x0c043e70u,0x0c043e72u,0x0c043e74u,0x0c043e76u,0x0c043e78u,
0x0c043e7au,0x0c043e7cu,0x0c043e7eu,0x0c043e80u,0x0c043e82u,0x0c043e84u,0x0c043e86u,0x0c043e88u,0x0c043e8au,0x0c043e8cu,0x0c043e8eu,0x0c043e90u,0x0c043e92u,0x0c043e94u,0x0c043e96u,0x0c043e98u,
0x0c043e9au,0x0c043e9cu,0x0c043e9eu,0x0c043ea0u,0x0c043ea2u,0x0c043ea4u,0x0c043ea6u,0x0c043ea8u,0x0c043eaau,0x0c043eacu,0x0c043eaeu,0x0c043eb0u,0x0c043eb2u,0x0c043eb4u,0x0c043eb6u,0x0c0459bcu,
0x0c0459beu,0x0c0459c0u,0x0c0459c2u,0x0c0459c4u,0x0c0459c6u,0x0c0459c8u,0x0c0459cau,0x0c0459ccu,0x0c0459ceu,0x0c0459d0u,0x0c0459d2u,0x0c0459d4u,0x0c0459d6u,0x0c0459d8u,0x0c0459dau,0x0c0459dcu,
0x0c0459deu,0x0c0459e0u,0x0c0459e2u,0x0c0459e4u,0x0c045a34u,0x0c045a36u,0x0c045a38u,0x0c045a3au,0x0c045a3cu,0x0c045a3eu,0x0c045a40u,0x0c045a42u,0x0c045a44u,0x0c045a46u,0x0c045a48u,0x0c045a4au,
0x0c045a4cu,0x0c045a4eu,0x0c045a50u,0x0c045a52u,0x0c045a54u,0x0c045a56u,0x0c045a58u,0x0c045a5au,0x0c045a5cu,0x0c045a8au,0x0c045a8cu,0x0c045a8eu,0x0c045a90u,0x0c045a92u,0x0c045a94u,0x0c045a96u,
0x0c045a98u,0x0c045a9au,0x0c045a9cu,0x0c045a9eu,0x0c045aa0u,0x0c045aa2u,0x0c045aa4u,0x0c045aa6u,0x0c045aa8u,0x0c045aaau,0x0c045aacu,0x0c045aaeu,0x0c045ab0u,0x0c045ab2u,0x0c045ae0u,0x0c045ae2u,
0x0c045ae4u,0x0c045ae6u,0x0c045ae8u,0x0c045aeau,0x0c045aecu,0x0c045aeeu,0x0c045af0u,0x0c045af2u,0x0c045af4u,0x0c045af6u,0x0c045af8u,0x0c045afau,0x0c045afcu,0x0c045afeu,0x0c045b00u,0x0c045b02u,
0x0c045b04u,0x0c045b06u,0x0c045b08u,0x0c045b36u,0x0c045b38u,0x0c045b3au,0x0c045b3cu,0x0c045b3eu,0x0c045b40u,0x0c045b42u,0x0c045b44u,0x0c045b46u,0x0c045b48u,0x0c045b4au,0x0c045b4cu,0x0c045b4eu,
0x0c045b50u,0x0c045b52u,0x0c045b54u,0x0c045b56u,0x0c045b58u,0x0c045b5au,0x0c045b5cu,0x0c045b5eu,0x0c045d14u,0x0c045d16u,0x0c045d18u,0x0c045d1au,0x0c045d1cu,0x0c045d1eu,0x0c045d20u,0x0c045d22u,
0x0c045d24u,0x0c045d26u,0x0c045d28u,0x0c045d2au,0x0c045d2cu,0x0c045d2eu,0x0c045d30u,0x0c045d32u,0x0c045d34u,0x0c045d36u,0x0c045d38u,0x0c045d3au,0x0c045d3cu,0x0c045d5au,0x0c045d5cu,0x0c045d5eu,
0x0c045d60u,0x0c045d62u,0x0c045d64u,0x0c045d66u,0x0c045d68u,0x0c045d6au,0x0c045d6cu,0x0c045d6eu,0x0c045d70u,0x0c045d72u,0x0c045d74u,0x0c045d76u,0x0c045d78u,0x0c045d7au,0x0c045d7cu,0x0c045d7eu,
0x0c045d80u,0x0c045d82u,0x0c045e94u,0x0c045e96u,0x0c045e98u,0x0c045e9au,0x0c045e9cu,0x0c045e9eu,0x0c045ea0u,0x0c045ea2u,0x0c045ea4u,0x0c045ea6u,0x0c045ea8u,0x0c045eaau,0x0c045eacu,0x0c045eaeu,
0x0c045eb0u,0x0c045eb2u,0x0c045eb4u,0x0c045eb6u,0x0c045eb8u,0x0c045ebau,0x0c045ebcu,0x0c050bfeu,0x0c050c00u,0x0c050c02u,0x0c050c04u,0x0c050c06u,0x0c050c08u,0x0c050c0au,0x0c050c0cu,0x0c050c0eu,
0x0c050c10u,0x0c050c12u,0x0c050c14u,0x0c050c16u,0x0c050c18u,0x0c050c1au,0x0c050c1cu,0x0c050c1eu,0x0c050c20u,0x0c050c22u,0x0c050c24u,0x0c050c26u,0x0c050c28u,0x0c050c2au,0x0c050c2cu,0x0c050c2eu,
0x0c050c30u,0x0c050c32u,0x0c051324u,0x0c051326u,0x0c051328u,0x0c05132au,0x0c05132cu,0x0c05132eu,0x0c051330u,0x0c051332u,0x0c051334u,0x0c051336u,0x0c051338u,0x0c05133au,0x0c05133cu,0x0c051340u,
0x0c051342u,0x0c051344u,0x0c051346u,0x0c051348u,0x0c051350u,0x0c051352u,0x0c051354u,0x0c051356u,0x0c051358u,0x0c05135au,0x0c05135cu,0x0c05135eu,0x0c051360u,0x0c051362u,0x0c051364u,0x0c051366u,
0x0c051368u,0x0c05136au,0x0c05136cu,0x0c05136eu,0x0c051370u,0x0c051372u,0x0c051374u,0x0c051376u,0x0c051378u,0x0c05137au,0x0c05137cu,0x0c05137eu,0x0c051380u,0x0c051382u,0x0c051384u,0x0c051386u,
0x0c051388u,0x0c05138au,0x0c05138cu,0x0c05138eu,0x0c051390u,0x0c051392u,0x0c051394u,0x0c051396u,0x0c051398u,0x0c05139au,0x0c05139cu,0x0c05139eu,0x0c0513a0u,0x0c0513a2u,0x0c0513a4u,0x0c0513a6u,
0x0c0513a8u,0x0c0513aau,0x0c0513acu,0x0c0513aeu,0x0c0513b0u,0x0c0513b2u,0x0c0513b4u,0x0c0513b6u,0x0c0513b8u,0x0c0513bau,0x0c0513bcu,0x0c0513beu,0x0c0513c0u,0x0c0513c2u,0x0c0513c4u,0x0c0513c6u,
0x0c0513c8u,0x0c0513cau,0x0c0513ccu,0x0c0513ceu,0x0c0513d0u,0x0c0513d2u,0x0c0513d4u,0x0c0513d6u,0x0c0513d8u,0x0c0513dau,0x0c0513dcu,0x0c0513deu,0x0c0513e0u,0x0c0513e2u,0x0c0513e4u,0x0c0513e6u,
0x0c0513e8u,0x0c0513eau,0x0c0513ecu,0x0c051400u,0x0c051402u,0x0c051404u,0x0c051406u,0x0c051408u,0x0c05140au,0x0c05140cu,0x0c05140eu,0x0c051410u,0x0c051412u,0x0c051414u,0x0c054530u,0x0c054532u,
0x0c054534u,0x0c054536u,0x0c054538u,0x0c05453au,0x0c05453cu,0x0c058780u,0x0c058782u,0x0c058784u,0x0c058788u,0x0c05878au,0x0c05878cu,0x0c0587d8u,0x0c0587dau,0x0c0587dcu,0x0c0587deu,0x0c0587e0u,
0x0c0587e2u,0x0c0587e4u,0x0c0587e6u,0x0c0587e8u,0x0c0587eau,0x0c0587ecu,0x0c0587eeu,0x0c0587f0u,0x0c0587f2u,0x0c0587f4u,0x0c0587f6u,0x0c0587f8u,0x0c0587fau,0x0c0587fcu,0x0c0587feu,0x0c058800u,
0x0c058802u,0x0c058804u,0x0c058806u,0x0c058808u,0x0c05880au,0x0c05880cu,0x0c05880eu,0x0c058810u,0x0c058812u,0x0c058814u,0x0c058816u,0x0c058818u,0x0c05881au,0x0c05881cu,0x0c05881eu,0x0c058820u,
0x0c058822u,0x0c058824u,0x0c058826u,0x0c058828u,0x0c05882au,0x0c05882cu,0x0c05882eu,0x0c058830u,0x0c058832u,0x0c058834u,0x0c058836u,0x0c058838u,0x0c05883au,0x0c05883cu,0x0c05883eu,0x0c058840u,
0x0c058842u,0x0c058844u,0x0c058846u,0x0c058848u,0x0c05884au,0x0c05884cu,0x0c05884eu,0x0c058850u,0x0c058852u,0x0c058854u,0x0c058856u,0x0c058858u,0x0c05885au,0x0c05885cu,0x0c05885eu,0x0c058860u,
0x0c058862u,0x0c058864u,0x0c058866u,0x0c058868u,0x0c05886au,0x0c05886cu,0x0c05886eu,0x0c058870u,0x0c058872u,0x0c058874u,0x0c058876u,0x0c058878u,0x0c05887au,0x0c05887cu,0x0c05887eu,0x0c058880u,
0x0c058882u,0x0c058884u,0x0c058886u,0x0c058888u,0x0c05888au,0x0c05888cu,0x0c05888eu,0x0c058890u,0x0c058892u,0x0c058894u,0x0c058896u,0x0c058898u,0x0c05889au,0x0c05889cu,0x0c05889eu,0x0c0588a0u,
0x0c0588a2u,0x0c0588a4u,0x0c0588a6u,0x0c0588a8u,0x0c0588aau,0x0c0588acu,0x0c0588aeu,0x0c0588b0u,0x0c0588b2u,0x0c0588b4u,0x0c0588b6u,0x0c0588b8u,0x0c0588bau,0x0c0588bcu,0x0c0588beu,0x0c0588c0u,
0x0c0588c2u,0x0c0588c4u,0x0c0588c6u,0x0c0588c8u,0x0c0588cau,0x0c0588ccu,0x0c0588ceu,0x0c0588d0u,0x0c0588d2u,0x0c0588d4u,0x0c0588d6u,0x0c0588d8u,0x0c0588dau,0x0c0588dcu,0x0c0588deu,0x0c0588e0u,
0x0c0588e2u,0x0c0588e4u,0x0c0588e6u,0x0c0588e8u,0x0c0588eau,0x0c0588ecu,0x0c0588eeu,0x0c05961cu,0x0c05c4a2u,0x0c05c4a4u,0x0c05c4a6u,0x0c05c4a8u,0x0c05c4aau,0x0c05c4acu,0x0c05c4aeu,0x0c05c4b0u,
0x0c05c4b2u,0x0c05c4b4u,0x0c05c4b6u,0x0c05c4b8u,0x0c05c4bau,0x0c05c8a6u,0x0c05c8a8u,0x0c05c8aau,0x0c05c8acu,0x0c05c8aeu,0x0c05c8b0u,0x0c05c8b2u,0x0c05c8b4u,0x0c05c8b6u,0x0c05c8b8u,0x0c05c8bau,
0x0c05c8bcu,0x0c05c8beu,0x0c05c8c0u,0x0c05c8c2u,0x0c05c8c4u,0x0c05c8c6u,0x0c05c8c8u,0x0c05c8cau,0x0c05c8ccu,0x0c05c8ceu,0x0c05c8d0u,0x0c05c8d2u,0x0c05c8d4u,0x0c05c8d6u,0x0c05c8d8u,0x0c05c8dau,
0x0c05c8dcu,0x0c05c8deu,0x0c05c8e0u,0x0c05c8e2u,0x0c05c8e4u,0x0c05c8e6u,0x0c05c8e8u,0x0c05c8eau,0x0c05c8ecu,0x0c05c8eeu,0x0c05c8f0u,0x0c05c8f2u,0x0c05c8f4u,0x0c05c8f6u,0x0c05c8f8u,0x0c05c8fau,
0x0c05c8fcu,0x0c05c8feu,0x0c05c900u,0x0c05c902u,0x0c05c904u,0x0c05c906u,0x0c05c908u,0x0c05c90au,0x0c05c90cu,0x0c05cbeeu,0x0c05cbf0u,0x0c05cbf2u,0x0c05cbf4u,0x0c05cbf6u,0x0c05cbf8u,0x0c05cbfau,
0x0c05cbfcu,0x0c05cbfeu,0x0c05cc00u,0x0c05cc02u,0x0c05cc04u,0x0c05cc06u,0x0c05cc08u,0x0c05cc0au,0x0c05cc0cu,0x0c05cc0eu,0x0c05cc10u,0x0c05cc12u,0x0c05cc14u,0x0c05cc16u,0x0c05cc18u,0x0c05cc1au,
0x0c05cc1cu,0x0c05cc1eu,0x0c05ddaau,0x0c05ddacu,0x0c05ddaeu,0x0c05ddb0u,0x0c05ddb2u,0x0c05ddb4u,0x0c05ddb6u,0x0c05ddb8u,0x0c05ddbau,0x0c05ddbcu,0x0c05ddbeu,0x0c05ddc0u,0x0c05ddc2u,0x0c05ddc4u,
0x0c05ddc6u,0x0c05ddc8u,0x0c05ddcau,0x0c05ddccu,0x0c05ddceu,0x0c05ddd0u,0x0c05ddd2u,0x0c05ddd4u,0x0c05ddd6u,0x0c05ddd8u,0x0c05dddau,0x0c05dddcu,0x0c05dddeu,0x0c05dde0u,0x0c05dde2u,0x0c05dde4u,
0x0c05dde6u,0x0c05dde8u,0x0c05ddeau,0x0c05ddecu,0x0c05ddeeu,0x0c05ddf0u,0x0c05e12eu,0x0c05e130u,0x0c05e132u,0x0c05e134u,0x0c05e136u,0x0c05e138u,0x0c05e13au,0x0c05e13cu,0x0c05e13eu,0x0c05e140u,
0x0c05e142u,0x0c05e144u,0x0c05e146u,0x0c05e148u,0x0c05e14au,0x0c05e14cu,0x0c05e14eu,0x0c05e150u,0x0c05e152u,0x0c05e154u,0x0c05e156u,0x0c05e158u,0x0c05e15au,0x0c05e15cu,0x0c05e15eu,0x0c05e160u,
0x0c05e162u,0x0c05e164u,0x0c05e166u,0x0c05e168u,0x0c05e16au,0x0c05e16cu,0x0c05e16eu,0x0c05e170u,0x0c05e172u,0x0c05e174u,0x0c05e176u,0x0c05e178u,0x0c05e17au,0x0c05e17cu,0x0c05e17eu,0x0c05e180u,
0x0c05e182u,0x0c05e184u,0x0c05e186u,0x0c05e188u,0x0c05e18au,0x0c05e18cu,0x0c05e18eu,0x0c05e190u,0x0c05e192u,0x0c05e194u,0x0c05e196u,0x0c05e198u,0x0c05e19au,0x0c05e19cu,0x0c05e19eu,0x0c05e1a0u,
0x0c05e1a2u,0x0c05e1a4u,0x0c05e1a6u,0x0c05e1a8u,0x0c05e1aau,0x0c05e1acu,0x0c05e1aeu,0x0c05e1b0u,0x0c05e1c2u,0x0c05e1c4u,0x0c05e1c6u,0x0c05e1c8u,0x0c05e1cau,0x0c05e1ccu,0x0c05e1ceu,0x0c05e1d0u,
0x0c05e332u,0x0c05e334u,0x0c05e336u,0x0c05e338u,0x0c05e33au,0x0c05e33cu,0x0c05e33eu,0x0c05e340u,0x0c05e634u,0x0c05e636u,0x0c05e638u,0x0c05e63au,0x0c05e63cu,0x0c05e63eu,0x0c05e640u,0x0c05e642u,
0x0c05e644u,0x0c05e646u,0x0c05e684u,0x0c05e686u,0x0c05e688u,0x0c05e68au,0x0c05e68cu,0x0c05e68eu,0x0c05e690u,0x0c05e692u,0x0c05e694u,0x0c05e696u,0x0c05e698u,0x0c05e69au,0x0c05e69cu,0x0c05e69eu,
0x0c05e6a0u,0x0c05e6a2u,0x0c05e6a4u,0x0c05e6a6u,0x0c05e6a8u,0x0c05e6b4u,0x0c05e6b6u,0x0c05e6b8u,0x0c05e6bau,0x0c05e6bcu,0x0c05e6beu,0x0c05e6c0u,0x0c05e6c2u,0x0c05e6c4u,0x0c05e6c6u,0x0c05e6c8u,
0x0c05e6cau,0x0c05e6ccu,0x0c05e6ceu,0x0c05e6d0u,0x0c05e6d2u,0x0c05e6d4u,0x0c05e6d6u,0x0c05e6d8u,0x0c05e6dau,0x0c05e6dcu,0x0c05e728u,0x0c05e72au,0x0c05e72cu,0x0c05e72eu,0x0c05e730u,0x0c05e732u,
0x0c05e734u,0x0c05e736u,0x0c05e738u,0x0c05e73au,0x0c05e73cu,0x0c05e73eu,0x0c05e740u,0x0c05e742u,0x0c05e744u,0x0c05e746u,0x0c05e748u,0x0c05e74au,0x0c05e74cu,0x0c05e74eu,0x0c05e750u,0x0c05e752u,
0x0c05f33cu,0x0c05f33eu,0x0c05f340u,0x0c05f342u,0x0c05f344u,0x0c05f346u,0x0c05f348u,0x0c05f34au,0x0c05f34cu,0x0c05f34eu,0x0c05f350u,0x0c05f352u,0x0c05f354u,0x0c05f356u,0x0c05f358u,0x0c05f35au,
0x0c05f35cu,0x0c05f35eu,0x0c05f360u,0x0c05f3eau,0x0c05f3ecu,0x0c05f3eeu,0x0c05f3f0u,0x0c05f3f2u,0x0c05f3f4u,0x0c05f3f6u,0x0c05f3f8u,0x0c05f3fau,0x0c05f3fcu,0x0c05f3feu,0x0c05f400u,0x0c05f402u,
0x0c05f404u,0x0c05f406u,0x0c05f408u,0x0c05f40au,0x0c05f40cu,0x0c05f40eu,0x0c05f410u,0x0c05f412u,0x0c05f414u,0x0c05f416u,0x0c05f418u,0x0c05f41au,0x0c05f41cu,0x0c05f41eu,0x0c05f420u,0x0c05f422u,
0x0c05f424u,0x0c05f426u,0x0c05f428u,0x0c05f42au,0x0c05f42cu,0x0c05f42eu,0x0c05f430u,0x0c05f432u,0x0c05f434u,0x0c05f436u,0x0c05f438u,0x0c05f43au,0x0c05f43cu,0x0c05ff82u,0x0c05ff84u,0x0c05ff86u,
0x0c05ff88u,0x0c05ff8au,0x0c05ff8cu,0x0c05ff8eu,0x0c05ff90u,0x0c05ff92u,0x0c05ff94u,0x0c05ff96u,0x0c05ff98u,0x0c05ff9au,0x0c05ff9cu,0x0c05ff9eu,0x0c05ffa0u,0x0c05ffa2u,0x0c05ffa4u,0x0c05ffa6u,
0x0c05ffa8u,0x0c05ffaau,0x0c05ffacu,0x0c05ffaeu,0x0c05ffb0u,0x0c05ffb2u,0x0c05ffb4u,0x0c05ffb6u,0x0c05ffb8u,0x0c05ffbau,0x0c05ffbcu,0x0c05ffbeu,0x0c05ffc0u,0x0c05ffc2u,0x0c05ffc4u,0x0c05ffc6u,
0x0c05ffc8u,0x0c05ffcau,0x0c062e60u,0x0c062e62u,0x0c062e64u,0x0c062e66u,0x0c062e68u,0x0c062e6au,0x0c062e6cu,0x0c062e6eu,0x0c062e70u,0x0c062e72u,0x0c062e74u,0x0c062e76u,0x0c062e78u,0x0c062e7au,
0x0c062e7cu,0x0c063418u,0x0c06341au,0x0c06341cu,0x0c06341eu,0x0c063420u,0x0c063422u,0x0c063424u,0x0c063426u,0x0c063428u,0x0c06342au,0x0c06342cu,0x0c06342eu,0x0c063430u,0x0c063432u,0x0c063434u,
0x0c0641f4u,0x0c0641f6u,0x0c0641f8u,0x0c0641fau,0x0c0641fcu,0x0c0641feu,0x0c064200u,0x0c064202u,0x0c064204u,0x0c064206u,0x0c064208u,0x0c06420au,0x0c06420cu,0x0c06420eu,0x0c064210u,0x0c064212u,
0x0c064214u,0x0c064216u,0x0c064218u,0x0c06421au,0x0c066cd8u,0x0c066cdau,0x0c066cdcu,0x0c066cdeu,0x0c066ce0u,0x0c066ce2u,0x0c066ce4u,0x0c066ce6u,0x0c066ce8u,0x0c066ceau,0x0c066d48u,0x0c06c406u,
0x0c06c408u,0x0c06c40au,0x0c06c40cu,0x0c06c40eu,0x0c06c410u,0x0c06c412u,0x0c06c414u,0x0c06c416u,0x0c06c418u,0x0c06c41au,0x0c06c41cu,0x0c06c41eu,0x0c06c420u,0x0c06dae8u,0x0c06daeau,0x0c06daecu,
0x0c06daeeu,0x0c06daf0u,0x0c06daf2u,0x0c06daf4u,0x0c06daf6u,0x0c06daf8u,0x0c06dafau,0x0c06dafcu,0x0c06dafeu,0x0c06db00u,0x0c06db02u,0x0c06db04u,0x0c06db06u,0x0c06db08u,0x0c06db0au,0x0c06db0cu,
0x0c06db0eu,0x0c06db10u,0x0c06db12u,0x0c06db14u,0x0c06db16u,0x0c06db18u,0x0c06db1au,0x0c06db1cu,0x0c06db1eu,0x0c06db20u,0x0c06db22u,0x0c06db24u,0x0c06db26u,0x0c06db28u,0x0c06db2au,0x0c06db2cu,
0x0c06db2eu,0x0c06db30u,0x0c06db32u,0x0c07023au,0x0c07023cu,0x0c07023eu,0x0c070240u,0x0c070242u,0x0c070244u,0x0c070246u,0x0c070248u,0x0c07024au,0x0c07024cu,0x0c07024eu,0x0c070250u,0x0c070252u,
0x0c070254u,0x0c070256u,0x0c070258u,0x0c07025au,0x0c07025cu,0x0c07025eu,0x0c070260u,0x0c070262u,0x0c070264u,0x0c070266u,0x0c070268u,0x0c07026au,0x0c07026cu,0x0c07026eu,0x0c070270u,0x0c070272u,
0x0c070274u,0x0c070276u,0x0c070278u,0x0c07027au,0x0c07027cu,0x0c07027eu,0x0c070280u,0x0c070282u,0x0c070284u,0x0c070286u,0x0c070288u,0x0c07028au,0x0c07028cu,0x0c07028eu,0x0c070290u,0x0c070292u,
0x0c070294u,0x0c070296u,0x0c070298u,0x0c07029au,0x0c07029cu,0x0c07029eu,0x0c0702a0u,0x0c0702a2u,0x0c0702a4u,0x0c0702a6u,0x0c0702a8u,0x0c0702aau,0x0c0702acu,0x0c0702aeu,0x0c0702b0u,0x0c0702b2u,
0x0c0702b4u,0x0c0702b6u,0x0c0702b8u,0x0c0702bau,0x0c0702bcu,0x0c0702beu,0x0c0702c0u,0x0c0702c2u,0x0c0702c4u,0x0c0702c6u,0x0c0702c8u,0x0c0702cau,0x0c0702ccu,0x0c0702ceu,0x0c0702d0u,0x0c0702d2u,
0x0c0702d4u,0x0c0702d6u,0x0c0702d8u,0x0c0702dau,0x0c0702dcu,0x0c0702deu,0x0c0702e0u,0x0c0702e2u,0x0c0702e4u,0x0c0702e6u,0x0c0702e8u,0x0c0702eau,0x0c0702ecu,0x0c0702eeu,0x0c0702f0u,0x0c0702f2u,
0x0c0702f4u,0x0c0702f6u,0x0c0702f8u,0x0c0702fau,0x0c0702fcu,0x0c0702feu,0x0c070300u,0x0c070302u,0x0c070304u,0x0c070306u,0x0c070308u,0x0c07030au,0x0c07030cu,0x0c07030eu,0x0c070310u,0x0c070312u,
0x0c070314u,0x0c070316u,0x0c070318u,0x0c07031au,0x0c07031cu,0x0c07031eu,0x0c070320u,0x0c070322u,0x0c070324u,0x0c070326u,0x0c070328u,0x0c07032au,0x0c07032cu,0x0c07032eu,0x0c070330u,0x0c070332u,
0x0c070334u,0x0c070336u,0x0c070338u,0x0c07033au,0x0c07033cu,0x0c070344u,0x0c070346u,0x0c070348u,0x0c07034au,0x0c07034cu,0x0c07034eu,0x0c070350u,0x0c070352u,0x0c070354u,0x0c070356u,0x0c070358u,
0x0c07035au,0x0c07035cu,0x0c07035eu,0x0c070360u,0x0c070362u,0x0c070364u,0x0c070366u,0x0c070368u,0x0c07036au,0x0c07036cu,0x0c07036eu,0x0c070370u,0x0c070372u,0x0c070374u,0x0c070376u,0x0c070378u,
0x0c07037au,0x0c07037cu,0x0c07037eu,0x0c070380u,0x0c070382u,0x0c070384u,0x0c070386u,0x0c070388u,0x0c070390u,0x0c070392u,0x0c070394u,0x0c070396u,0x0c070398u,0x0c07039au,0x0c07039cu,0x0c07039eu,
0x0c0703a0u,0x0c0703a2u,0x0c0703a4u,0x0c0703a6u,0x0c0703a8u,0x0c0703aau,0x0c0703acu,0x0c0703aeu,0x0c0703b0u,0x0c0703b2u,0x0c0703b4u,0x0c0703b6u,0x0c0703b8u,0x0c0703bau,0x0c0703bcu,0x0c0703beu,
0x0c0703c0u,0x0c0703c2u,0x0c0703c4u,0x0c0703c6u,0x0c0703c8u,0x0c0703cau,0x0c0703ccu,0x0c0703d8u,0x0c0703dau,0x0c0703dcu,0x0c0703deu,0x0c0703e0u,0x0c0703e2u,0x0c0703e4u,0x0c0703e6u,0x0c0703e8u,
0x0c0703eau,0x0c0703ecu,0x0c0703eeu,0x0c0703f0u,0x0c0703f2u,0x0c0703f4u,0x0c0703f6u,0x0c0703f8u,0x0c070fbau,0x0c070fbcu,0x0c070fbeu,0x0c070fc0u,0x0c070fc2u,0x0c070fc4u,0x0c070fc6u,0x0c070fc8u,
0x0c070fcau,0x0c070fccu,0x0c070fceu,0x0c070fd0u,0x0c070fd2u,0x0c070fd4u,0x0c070fd6u,0x0c070fd8u,0x0c070fdau,0x0c070fdcu,0x0c070fdeu,0x0c070fe0u,0x0c070fe2u,0x0c070fe4u,0x0c070fe6u,0x0c070fe8u,
0x0c070feau,0x0c070fecu,0x0c070feeu,0x0c070ff0u,0x0c070ff2u,0x0c070ff4u,0x0c070ff6u,0x0c070ff8u,0x0c070ffau,0x0c070ffcu,0x0c070ffeu,0x0c071000u,0x0c071002u,0x0c071004u,0x0c071006u,0x0c071008u,
0x0c07100au,0x0c07100cu,0x0c07100eu,0x0c071010u,0x0c071012u,0x0c071014u,0x0c071016u,0x0c071018u,0x0c07101au,0x0c07101cu,0x0c07101eu,0x0c071020u,0x0c071022u,0x0c071024u,0x0c071026u,0x0c071028u,
0x0c07102au,0x0c07102cu,0x0c07102eu,0x0c071030u,0x0c071032u,0x0c071034u,0x0c071036u,0x0c071038u,0x0c07103au,0x0c07103cu,0x0c07103eu,0x0c071040u,0x0c071042u,0x0c071044u,0x0c071046u,0x0c071048u,
0x0c07104au,0x0c07104cu,0x0c07104eu,0x0c071050u,0x0c071052u,0x0c071054u,0x0c071056u,0x0c071058u,0x0c07105au,0x0c07105cu,0x0c07105eu,0x0c071060u,0x0c071062u,0x0c071064u,0x0c071066u,0x0c071068u,
0x0c07106au,0x0c07106cu,0x0c07106eu,0x0c071070u,0x0c071072u,0x0c071074u,0x0c071076u,0x0c071078u,0x0c07107au,0x0c07107cu,0x0c07107eu,0x0c071080u,0x0c071082u,0x0c071084u,0x0c071086u,0x0c071088u,
0x0c07108au,0x0c07108cu,0x0c07108eu,0x0c071090u,0x0c071092u,0x0c071094u,0x0c071096u,0x0c071098u,0x0c07109au,0x0c07109cu,0x0c07109eu,0x0c0710a0u,0x0c0710a2u,0x0c0710a4u,0x0c0710a6u,0x0c0710a8u,
0x0c0710aau,0x0c0710acu,0x0c0710aeu,0x0c0710b0u,0x0c0710b2u,0x0c0710b4u,0x0c0710b6u,0x0c0710b8u,0x0c0710bau,0x0c0710bcu,0x0c0710beu,0x0c0710c0u,0x0c0710c8u,0x0c0710cau,0x0c0710ccu,0x0c0710ceu,
0x0c0710d0u,0x0c0710d2u,0x0c0710d4u,0x0c0710d6u,0x0c0710d8u,0x0c0710dau,0x0c0710dcu,0x0c0710deu,0x0c0710e0u,0x0c0710e2u,0x0c0710e4u,0x0c0710e6u,0x0c0710e8u,0x0c0710eau,0x0c0710ecu,0x0c0710eeu,
0x0c0710f0u,0x0c0710f2u,0x0c0710f4u,0x0c0710f6u,0x0c0710f8u,0x0c0710fau,0x0c0710fcu,0x0c0710feu,0x0c071100u,0x0c071102u,0x0c071104u,0x0c071106u,0x0c071108u,0x0c07110au,0x0c07110cu,0x0c07110eu,
0x0c071110u,0x0c071112u,0x0c071114u,0x0c071116u,0x0c071118u,0x0c07111au,0x0c07111cu,0x0c07111eu,0x0c071120u,0x0c071122u,0x0c071124u,0x0c071126u,0x0c071128u,0x0c07112au,0x0c07112cu,0x0c07112eu,
0x0c071130u,0x0c071132u,0x0c071134u,0x0c071136u,0x0c071138u,0x0c07113au,0x0c07113cu,0x0c07113eu,0x0c073098u,0x0c07309au,0x0c07309cu,0x0c07309eu,0x0c0730a0u,0x0c0730a2u,0x0c0730a4u,0x0c0730a6u,
0x0c0730a8u,0x0c0730aau,0x0c0730acu,0x0c0730aeu,0x0c0730b0u,0x0c0730b2u,0x0c0730b4u,0x0c0730b6u,0x0c0730b8u,0x0c0730bau,0x0c0730bcu,0x0c0730beu,0x0c0730c0u,0x0c0730c2u,0x0c0730c4u,0x0c0730c6u,
0x0c0730c8u,0x0c0730cau,0x0c0730ccu,0x0c0730ceu,0x0c0730d0u,0x0c0730d2u,0x0c0730d4u,0x0c0730d6u,0x0c0730d8u,0x0c0730dau,0x0c0730dcu,0x0c0730deu,0x0c0730e0u,0x0c0730e2u,0x0c0730e4u,0x0c0730e6u,
0x0c0730e8u,0x0c0730eau,0x0c0734feu,0x0c073500u,0x0c073502u,0x0c073504u,0x0c073506u,0x0c073508u,0x0c07350au,0x0c07350cu,0x0c07350eu,0x0c073510u,0x0c073512u,0x0c073514u,0x0c073516u,0x0c073518u,
0x0c07351au,0x0c07351cu,0x0c07351eu,0x0c073520u,0x0c073522u,0x0c073524u,0x0c073526u,0x0c073528u,0x0c07352au,0x0c07352cu,0x0c07352eu,0x0c073530u,0x0c073532u,0x0c073534u,0x0c073536u,0x0c073538u,
0x0c07353au,0x0c07353cu,0x0c07353eu,0x0c073540u,0x0c07ba28u,0x0c07ba2au,0x0c07ba2cu,0x0c07ba2eu,0x0c07ba30u,0x0c07ba32u,0x0c07ba34u,0x0c07ba36u,0x0c07ba38u,0x0c07ba3au,0x0c07ba3cu,0x0c07ba3eu,
0x0c07ba40u,0x0c07ba42u,0x0c07ba44u,0x0c07ba46u,0x0c07ba48u,0x0c07ba4au,0x0c07ba4cu,0x0c07ba4eu,0x0c07ba50u,0x0c07ba52u,0x0c07ba54u,0x0c07ba56u,0x0c07ba58u,0x0c07ba5au,0x0c07ba5cu,0x0c07ba5eu,
0x0c07ba60u,0x0c07ba62u,0x0c07ba64u,0x0c07ba66u,0x0c07ba68u,0x0c07ba6au,0x0c07ba6cu,0x0c07ba6eu,0x0c07ba70u,0x0c07ba72u,0x0c07ba74u,0x0c07ba76u,0x0c07ba78u,0x0c07ba7au,0x0c07ba7cu,0x0c07ba7eu,
0x0c07ba80u,0x0c07ba82u,0x0c07ba84u,0x0c07ba86u,0x0c07ba88u,0x0c07ba8au,0x0c07ba8cu,0x0c07ba8eu,0x0c07ba90u,0x0c07ba92u,0x0c07ba94u,0x0c07ba96u,0x0c07ba98u,0x0c07ba9au,0x0c07ba9cu,0x0c07ba9eu,
0x0c07baa0u,0x0c07baa2u,0x0c07baa4u,0x0c07baa6u,0x0c07baa8u,0x0c07baaau,0x0c07baacu,0x0c07baaeu,0x0c07bab0u,0x0c07bab2u,0x0c07bab4u,0x0c07bab6u,0x0c07bab8u,0x0c07babau,0x0c07babcu,0x0c07babeu,
0x0c07bac0u,0x0c07bac2u,0x0c07bac4u,0x0c07bac6u,0x0c07bac8u,0x0c07bacau,0x0c07baccu,0x0c07baceu,0x0c07bad0u,0x0c07bad2u,0x0c07bad4u,0x0c07bad6u,0x0c07bad8u,0x0c07badau,0x0c07badcu,0x0c07badeu,
0x0c07bae0u,0x0c07bae2u,0x0c07bae4u,0x0c07bae6u,0x0c07bae8u,0x0c07baeau,0x0c07baecu,0x0c07baeeu,0x0c07baf0u,0x0c07baf2u,0x0c07baf4u,0x0c07baf6u,0x0c07baf8u,0x0c07bafau,0x0c07bafcu,0x0c07bafeu,
0x0c07bb00u,0x0c07bb02u,0x0c07bb04u,0x0c07bb06u,0x0c07bb08u,0x0c07bb0au,0x0c07bb0cu,0x0c07bb0eu,0x0c07bb10u,0x0c07bb12u,0x0c07bb14u,0x0c07bb16u,0x0c07bb18u,0x0c07bb1au,0x0c07bb1cu,0x0c07bb1eu,
0x0c07bb20u,0x0c07bb22u,0x0c07bb24u,0x0c07bb26u,0x0c07bb28u,0x0c07bb2au,0x0c07bb2cu,0x0c07bb2eu,0x0c07bb30u,0x0c07bb32u,0x0c07bb34u,0x0c07bb36u,0x0c07bb38u,0x0c07bb3au,0x0c07bb3cu,0x0c07bb3eu,
0x0c07bb40u,0x0c07bb42u,0x0c07bb44u,0x0c07bb46u,0x0c07bba0u,0x0c07bba2u,0x0c07bba4u,0x0c07bba6u,0x0c07bba8u,0x0c07bbaau,0x0c07bbacu,0x0c07bbaeu,0x0c07bbb0u,0x0c07bbb2u,0x0c07bbb4u,0x0c07bbb6u,
0x0c07bbb8u,0x0c07bbbau,0x0c07bbbcu,0x0c07bbbeu,0x0c07bbc0u,0x0c07bbc2u,0x0c07bbc4u,0x0c07bbc6u,0x0c07bbc8u,0x0c07bbcau,0x0c07bbccu,0x0c07bbceu,0x0c07bbd0u,0x0c07bbd2u,0x0c07bbd4u,0x0c07bbd6u,
0x0c07bbd8u,0x0c07bbdau,0x0c07bbdcu,0x0c07bbdeu,0x0c07bbe0u,0x0c07bbe2u,0x0c07bbe4u,0x0c07bbe6u,0x0c07bbe8u,0x0c07bbeau,0x0c07bbecu,0x0c07bbeeu,0x0c07bbf0u,0x0c07bbf2u,0x0c07bbf4u,0x0c07bbf6u,
0x0c07bbf8u,0x0c07bbfau,0x0c07bbfcu,0x0c07bbfeu,0x0c07bc00u,0x0c07bc02u,0x0c07bc04u,0x0c07bc06u,0x0c07bc08u,0x0c07bc0au,0x0c07bc0cu,0x0c07bc0eu,0x0c07bc10u,0x0c07bc12u,0x0c07bc14u,0x0c07bc16u,
0x0c07bc18u,0x0c07bc1au,0x0c07bc1cu,0x0c07bc1eu,0x0c07bc20u,0x0c07bc22u,0x0c07bc24u,0x0c07bc26u,0x0c07bc28u,0x0c07bc2au,0x0c07bc2cu,0x0c07bc2eu,0x0c07bc30u,0x0c07bc32u,0x0c07bc34u,0x0c07bc36u,
0x0c07bc38u,0x0c07bc3au,0x0c07bc3cu,0x0c07bc3eu,0x0c07bc40u,0x0c07bc42u,0x0c07bc44u,0x0c07bc46u,0x0c07bc48u,0x0c07bc4au,0x0c07bc4cu,0x0c07bc4eu,0x0c07bc50u,0x0c07bc52u,0x0c07bc54u,0x0c07bc56u,
0x0c07bc58u,0x0c07bc5au,0x0c07bc5cu,0x0c07bc5eu,0x0c07bc60u,0x0c07bc62u,0x0c07bc64u,0x0c07bc66u,0x0c07bc68u,0x0c07bc6au,0x0c07bc6cu,0x0c07bc6eu,0x0c07bc70u,0x0c07bc72u,0x0c07bc74u,0x0c07bc76u,
0x0c07bc78u,0x0c07bc7au,0x0c07bc7cu,0x0c07bc7eu,0x0c07bc80u,0x0c07bc82u,0x0c07bc84u,0x0c07bc86u,0x0c07bc88u,0x0c07bc8au,0x0c07bc8cu,0x0c07bc8eu,0x0c07bc90u,0x0c07bc92u,0x0c07bc94u,0x0c07bc96u,
0x0c07bc98u,0x0c07bc9au,0x0c07bc9cu,0x0c07bc9eu,0x0c07bca0u,0x0c07bca2u,0x0c07bca4u,0x0c07bca6u,0x0c07bca8u,0x0c07bcaau,0x0c07bcacu,0x0c07bcaeu,0x0c07bcb0u,0x0c07bcb2u,0x0c07bcb4u,0x0c07bcb6u,
0x0c07bcb8u,0x0c07bcbau,0x0c07bcbcu,0x0c07bcbeu,0x0c07bcc0u,0x0c07bcc2u,0x0c07bcc4u,0x0c07bcc6u,0x0c07bcc8u,0x0c07bccau,0x0c07bcccu,0x0c07bcceu,0x0c07bcd0u,0x0c07bcd2u,0x0c07bcd4u,0x0c07bcd6u,
0x0c07bcd8u,0x0c07bcdau,0x0c07bcdcu,0x0c07bcdeu,0x0c07bce0u,0x0c07bce2u,0x0c07bce4u,0x0c07bce6u,0x0c07bce8u,0x0c07bceau,0x0c07bcecu,0x0c07bceeu,0x0c07bcf0u,0x0c07bcf2u,0x0c07bcf4u,0x0c07bcf6u,
0x0c07bcf8u,0x0c07bd14u,0x0c07bd16u,0x0c07bd18u,0x0c07bd1au,0x0c07bd1cu,0x0c07bd1eu,0x0c07bd20u,0x0c07bd22u,0x0c07bd24u,0x0c07bd26u,0x0c07bd28u,0x0c07bd2au,0x0c07bd2cu,0x0c07bd2eu,0x0c07bd30u,
0x0c07bd32u,0x0c07bd34u,0x0c07bd36u,0x0c07bd38u,0x0c07bd3au,0x0c07bd3cu,0x0c07bd3eu,0x0c07bd40u,0x0c07bd42u,0x0c07bd44u,0x0c07bd46u,0x0c07bd48u,0x0c07bd4au,0x0c07bd4cu,0x0c07bd4eu,0x0c07bd50u,
0x0c07bd52u,0x0c07bd54u,0x0c07bd56u,0x0c07bd58u,0x0c07bd5au,0x0c07bd5cu,0x0c07bd5eu,0x0c07bd60u,0x0c07bd62u,0x0c07bd64u,0x0c07bd66u,0x0c07bd68u,0x0c07bd6au,0x0c07bd6cu,0x0c07bd6eu,0x0c07bd70u,
0x0c07bd72u,0x0c07bd74u,0x0c07bd76u,0x0c07bd78u,0x0c07bd7au,0x0c07bd7cu,0x0c07bd7eu,0x0c07bd80u,0x0c07bd82u,0x0c07bd84u,0x0c07bd86u,0x0c07bd88u,0x0c07bd8au,0x0c07bd8cu,0x0c07bd8eu,0x0c07bd90u,
0x0c07bd92u,0x0c07bd94u,0x0c07bd96u,0x0c07bd98u,0x0c07bd9au,0x0c07bd9cu,0x0c07bd9eu,0x0c07bda0u,0x0c07bda2u,0x0c07bda4u,0x0c07bda6u,0x0c07bda8u,0x0c07bdaau,0x0c07bdacu,0x0c07bdaeu,0x0c07bdb0u,
0x0c07bdb2u,0x0c07bdb4u,0x0c07bdb6u,0x0c07bdb8u,0x0c07bdbau,0x0c07bdbcu,0x0c07bdbeu,0x0c07bdc0u,0x0c07bdc2u,0x0c07bdc4u,0x0c07bdc6u,0x0c07bdc8u,0x0c07bdcau,0x0c07bdccu,0x0c07bdceu,0x0c07bdd0u,
0x0c07bdd2u,0x0c07bdd4u,0x0c07bdd6u,0x0c07bdd8u,0x0c07bddau,0x0c07bddcu,0x0c07bddeu,0x0c07bde0u,0x0c07bde2u,0x0c07bde4u,0x0c07bde6u,0x0c07bde8u,0x0c07bdeau,0x0c07bdecu,0x0c07bdeeu,0x0c07bdf0u,
0x0c07bdf2u,0x0c07bdf4u,0x0c07bdf6u,0x0c07bdf8u,0x0c07bdfau,0x0c07bdfcu,0x0c07bdfeu,0x0c07be00u,0x0c07be02u,0x0c07be04u,0x0c07be06u,0x0c07be08u,0x0c07be0au,0x0c07be0cu,0x0c07be0eu,0x0c07be10u,
0x0c07be12u,0x0c07be14u,0x0c07be16u,0x0c07be18u,0x0c07be1au,0x0c07be1cu,0x0c07be1eu,0x0c07be20u,0x0c07be22u,0x0c07be24u,0x0c07be26u,0x0c07be28u,0x0c07be2au,0x0c07be2cu,0x0c07be2eu,0x0c07be30u,
0x0c07be32u,0x0c07be34u,0x0c07be36u,0x0c07be38u,0x0c07be3au,0x0c07be3cu,0x0c07be3eu,0x0c07be40u,0x0c07be42u,0x0c07be44u,0x0c07be46u,0x0c07be48u,0x0c07be4au,0x0c07be4cu,0x0c07be4eu,0x0c07be50u,
0x0c07be52u,0x0c07be54u,0x0c07be56u,0x0c07be58u,0x0c07be5au,0x0c07be5cu,0x0c07be5eu,0x0c07be60u,0x0c07be62u,0x0c07be64u,0x0c07be66u,0x0c07be68u,0x0c07be6au,0x0c07be6cu,0x0c07be6eu,0x0c07be70u,
0x0c07be72u,0x0c07be74u,0x0c07be76u,0x0c07be78u,0x0c07be7au,0x0c07be7cu,0x0c07be7eu,0x0c07be80u,0x0c07be82u,0x0c07be84u,0x0c07be86u,0x0c07be88u,0x0c07be8au,0x0c07be8cu,0x0c07be8eu,0x0c07be90u,
0x0c07be92u,0x0c07be94u,0x0c07be96u,0x0c07be98u,0x0c07be9au,0x0c07beb0u,0x0c07beb2u,0x0c07beb4u,0x0c07beb6u,0x0c07beb8u,0x0c07bebau,0x0c07bebcu,0x0c07bebeu,0x0c07bec0u,0x0c07bec2u,0x0c07bec4u,
0x0c07bec6u,0x0c07bec8u,0x0c07becau,0x0c07beccu,0x0c07beceu,0x0c07bed0u,0x0c07bed2u,0x0c07bed4u,0x0c07bed6u,0x0c07bed8u,0x0c07bedau,0x0c07bedcu,0x0c07bedeu,0x0c07bee0u,0x0c07bee2u,0x0c07bee4u,
0x0c07bee6u,0x0c07bee8u,0x0c07beeau,0x0c07beecu,0x0c07beeeu,0x0c07bef0u,0x0c07bef2u,0x0c07bef4u,0x0c07bef6u,0x0c07bef8u,0x0c07befau,0x0c07befcu,0x0c07befeu,0x0c07bf00u,0x0c07bf02u,0x0c07bf04u,
0x0c07bf06u,0x0c07bf08u,0x0c07bf0au,0x0c07bf0cu,0x0c07bf0eu,0x0c07bf10u,0x0c07bf12u,0x0c07bf14u,0x0c07bf16u,0x0c07bf18u,0x0c07bf1au,0x0c07bf1cu,0x0c07bf1eu,0x0c07bf20u,0x0c07bf22u,0x0c07bf24u,
0x0c07bf26u,0x0c07bf28u,0x0c07bf2au,0x0c07bf2cu,0x0c07bf2eu,0x0c07bf30u,0x0c07bf32u,0x0c07bf34u,0x0c07bf36u,0x0c07bf38u,0x0c07bf3au,0x0c07bf3cu,0x0c07bf3eu,0x0c07bf40u,0x0c07bf42u,0x0c07bf44u,
0x0c07bf46u,0x0c07bf48u,0x0c07bf4au,0x0c07bf4cu,0x0c07bf4eu,0x0c07bf50u,0x0c07bf52u,0x0c07bf54u,0x0c07bf56u,0x0c07bf58u,0x0c07bf5au,0x0c07bf5cu,0x0c07bf5eu,0x0c07bf60u,0x0c07bf62u,0x0c07bf64u,
0x0c07bf66u,0x0c07bf68u,0x0c07bf6au,0x0c07bf6cu,0x0c07bf6eu,0x0c07bf70u,0x0c07bf72u,0x0c07bf74u,0x0c07bf76u,0x0c07bf78u,0x0c07bf7au,0x0c07bf7cu,0x0c07bf7eu,0x0c07bf80u,0x0c07bf82u,0x0c07bf84u,
0x0c07bf86u,0x0c07bf88u,0x0c07bf8au,0x0c07bf8cu,0x0c07bf8eu,0x0c07bf90u,0x0c07bf92u,0x0c07bf94u,0x0c07bf96u,0x0c07bf98u,0x0c07bf9au,0x0c07bf9cu,0x0c07bf9eu,0x0c07bfa0u,0x0c07bfa2u,0x0c07bfa4u,
0x0c07bfa6u,0x0c07bfa8u,0x0c07bfaau,0x0c07bfacu,0x0c07bfaeu,0x0c07bfb0u,0x0c07bfb2u,0x0c07bfb4u,0x0c07bfb6u,0x0c07bfb8u,0x0c07bfbau,0x0c07bfbcu,0x0c07bfbeu,0x0c07bfc0u,0x0c07bfc2u,0x0c07bfc4u,
0x0c07bfc6u,0x0c07bfc8u,0x0c07bfcau,0x0c07bfccu,0x0c07bfceu,0x0c07bfd0u,0x0c07bfd2u,0x0c07bfd4u,0x0c07bfd6u,0x0c07bfd8u,0x0c07bfdau,0x0c07bfdcu,0x0c07bfdeu,0x0c07bfe0u,0x0c07bfe2u,0x0c07bfe4u,
0x0c07bfe6u,0x0c07bfe8u,0x0c07bfeau,0x0c07bfecu,0x0c07bfeeu,0x0c07bff0u,0x0c07bff2u,0x0c07bff4u,0x0c07bff6u,0x0c07bff8u,0x0c07bffau,0x0c07bffcu,0x0c07bffeu,0x0c07c000u,0x0c07c002u,0x0c07c004u,
0x0c07c006u,0x0c07c008u,0x0c07c00au,0x0c07c00cu,0x0c07c00eu,0x0c07c010u,0x0c07c012u,0x0c07c014u,0x0c07c016u,0x0c07c018u,0x0c07c01au,0x0c07c01cu,0x0c07c01eu,0x0c07c020u,0x0c07c022u,0x0c07c024u,
0x0c07c026u,0x0c07c028u,0x0c07c02au,0x0c07c02cu,0x0c07c02eu,0x0c07c030u,0x0c07c032u,0x0c07c034u,0x0c07c036u,0x0c07c038u,0x0c07c03au,0x0c07c03cu,0x0c07c03eu,0x0c07c040u,0x0c07c042u,0x0c07c05cu,
0x0c07c05eu,0x0c07c060u,0x0c07c062u,0x0c07c064u,0x0c07c066u,0x0c07c068u,0x0c07c06au,0x0c07c06cu,0x0c07c06eu,0x0c07c070u,0x0c07c072u,0x0c07c074u,0x0c07c076u,0x0c07c078u,0x0c07c07au,0x0c07c07cu,
0x0c07c07eu,0x0c07c080u,0x0c07c082u,0x0c07c084u,0x0c07c086u,0x0c07c088u,0x0c07c08au,0x0c07c08cu,0x0c07c08eu,0x0c07c090u,0x0c07c092u,0x0c07c094u,0x0c07c096u,0x0c07c098u,0x0c07c09au,0x0c07c09cu,
0x0c07c09eu,0x0c07c0a0u,0x0c07c0a2u,0x0c07c0a4u,0x0c07c0a6u,0x0c07c0a8u,0x0c07c0aau,0x0c07c0acu,0x0c07c0aeu,0x0c07c0b0u,0x0c07c0b2u,0x0c07c0b4u,0x0c07c0b6u,0x0c07c0b8u,0x0c07c0bau,0x0c07c0bcu,
0x0c07c0beu,0x0c07c0c0u,0x0c07c0c2u,0x0c07c0c4u,0x0c07c0c6u,0x0c07c0c8u,0x0c07c0cau,0x0c07c0ccu,0x0c07c0ceu,0x0c07c0d0u,0x0c07c0d2u,0x0c07c0d4u,0x0c07c0d6u,0x0c07c0d8u,0x0c07c0dau,0x0c07c0dcu,
0x0c07c0deu,0x0c07c0e0u,0x0c07c0e2u,0x0c07c0e4u,0x0c07c0e6u,0x0c07c0e8u,0x0c07c0eau,0x0c07c0ecu,0x0c07c0eeu,0x0c07c0f0u,0x0c07c0f2u,0x0c07c0f4u,0x0c07c0f6u,0x0c07c0f8u,0x0c07c0fau,0x0c07c0fcu,
0x0c07c0feu,0x0c07c100u,0x0c07c102u,0x0c07c12cu,0x0c07c12eu,0x0c07c130u,0x0c07c132u,0x0c07c134u,0x0c07c136u,0x0c07c138u,0x0c07c13au,0x0c07c13cu,0x0c07c13eu,0x0c07c140u,0x0c07c142u,0x0c07c144u,
0x0c07c146u,0x0c07c148u,0x0c07c14au,0x0c07c14cu,0x0c07c14eu,0x0c07c150u,0x0c07c152u,0x0c07c154u,0x0c07c156u,0x0c07c158u,0x0c07c15au,0x0c07c15cu,0x0c07c15eu,0x0c07c160u,0x0c07c162u,0x0c07c164u,
0x0c07c166u,0x0c07c168u,0x0c07c16au,0x0c07c16cu,0x0c07c16eu,0x0c07c170u,0x0c07c172u,0x0c07c174u,0x0c07c176u,0x0c07c178u,0x0c07c17au,0x0c07c17cu,0x0c07c17eu,0x0c07c180u,0x0c07c182u,0x0c07c184u,
0x0c07c186u,0x0c07c188u,0x0c07c18au,0x0c07c18cu,0x0c07c18eu,0x0c07c190u,0x0c07c192u,0x0c07c194u,0x0c07c196u,0x0c07c198u,0x0c07c19au,0x0c07c19cu,0x0c07c19eu,0x0c07c1a0u,0x0c07c1a2u,0x0c07c1a4u,
0x0c07c1a6u,0x0c07c1a8u,0x0c07c1aau,0x0c07c1acu,0x0c07c1aeu,0x0c07c1b0u,0x0c07c1b2u,0x0c07c1b4u,0x0c07c1b6u,0x0c07c1b8u,0x0c07c1bau,0x0c07c1bcu,0x0c07c1beu,0x0c07c1c0u,0x0c07c1c2u,0x0c07c1c4u,
0x0c07c1c6u,0x0c07c1c8u,0x0c07c1cau,0x0c07c1ccu,0x0c07c1ceu,0x0c07c1d0u,0x0c07c1d2u,0x0c07c1d4u,0x0c07c1d6u,0x0c07c1d8u,0x0c07c1dau,0x0c07c1dcu,0x0c07c1deu,0x0c07c1e0u,0x0c07c1e2u,0x0c07c1e4u,
0x0c07c1e6u,0x0c07c1e8u,0x0c07c1eau,0x0c07c1ecu,0x0c07c1eeu,0x0c07c1f0u,0x0c07c1f2u,0x0c07c1f4u,0x0c07c1f6u,0x0c07c1f8u,0x0c07c1fau,0x0c07c1fcu,0x0c07c1feu,0x0c07c200u,0x0c07c202u,0x0c07c204u,
0x0c07c206u,0x0c07c208u,0x0c07c20au,0x0c07c20cu,0x0c07c20eu,0x0c07c210u,0x0c07c212u,0x0c07c214u,0x0c07c216u,0x0c07c218u,0x0c07c21au,0x0c07c21cu,0x0c07c21eu,0x0c07c220u,0x0c07c222u,0x0c07c224u,
0x0c07c226u,0x0c07c228u,0x0c07c22au,0x0c07c22cu,0x0c07c22eu,0x0c07c230u,0x0c07c232u,0x0c07c234u,0x0c07c236u,0x0c07c238u,0x0c07c23au,0x0c07c23cu,0x0c07c23eu,0x0c07c240u,0x0c07c242u,0x0c07c244u,
0x0c07c246u,0x0c07c248u,0x0c07c24au,0x0c07c24cu,0x0c07c24eu,0x0c07c250u,0x0c07c252u,0x0c07c254u,0x0c07c256u,0x0c07c258u,0x0c07c25au,0x0c07c25cu,0x0c07c25eu,0x0c07c260u,0x0c07c262u,0x0c07c264u,
0x0c07c266u,0x0c07c268u,0x0c07c26au,0x0c07c26cu,0x0c07c26eu,0x0c07c270u,0x0c07c272u,0x0c07c274u,0x0c07c276u,0x0c07c278u,0x0c07c27au,0x0c07c27cu,0x0c07c27eu,0x0c07c280u,0x0c07c282u,0x0c07c284u,
0x0c07c286u,0x0c07c288u,0x0c07c28au,0x0c07c28cu,0x0c07c28eu,0x0c07c290u,0x0c07c292u,0x0c07c294u,0x0c07c296u,0x0c07c298u,0x0c07c29au,0x0c07c29cu,0x0c07c29eu,0x0c07c2a0u,0x0c07c2a2u,0x0c07c2a4u,
0x0c07c2a6u,0x0c07c2a8u,0x0c07c2aau,0x0c07c2acu,0x0c07c2aeu,0x0c07c2b0u,0x0c07c2b2u,0x0c07c2b4u,0x0c07c2d0u,0x0c07c2d2u,0x0c07c2d4u,0x0c07c2d6u,0x0c07c2d8u,0x0c07c2dau,0x0c07c2dcu,0x0c07c2deu,
0x0c07c2e0u,0x0c07c2e2u,0x0c07c2e4u,0x0c07c2e6u,0x0c07c2e8u,0x0c07c2eau,0x0c07c2ecu,0x0c07c2eeu,0x0c07c2f0u,0x0c07c2f2u,0x0c07c2f4u,0x0c07c2f6u,0x0c07c2f8u,0x0c07c2fau,0x0c07c2fcu,0x0c07c2feu,
0x0c07c300u,0x0c07c302u,0x0c07c304u,0x0c07c306u,0x0c07c308u,0x0c07c30au,0x0c07c30cu,0x0c07c30eu,0x0c07c310u,0x0c07c312u,0x0c07c314u,0x0c07c316u,0x0c07c318u,0x0c07c31au,0x0c07c31cu,0x0c07c31eu,
0x0c07c320u,0x0c07c322u,0x0c07c324u,0x0c07c326u,0x0c07c328u,0x0c07c32au,0x0c07c32cu,0x0c07c32eu,0x0c07c330u,0x0c07c332u,0x0c07c722u,0x0c07c724u,0x0c07c726u,0x0c07c728u,0x0c07c72au,0x0c07c72cu,
0x0c07c72eu,0x0c07c730u,0x0c07c732u,0x0c07c734u,0x0c07c736u,0x0c07c738u,0x0c07c73au,0x0c07c73cu,0x0c07c73eu,0x0c07c740u,0x0c07c742u,0x0c07c744u,0x0c07c746u,0x0c07c748u,0x0c07c74au,0x0c07c74cu,
0x0c07c74eu,0x0c07c750u,0x0c07c752u,0x0c07c754u,0x0c07c756u,0x0c07c758u,0x0c07c75au,0x0c07c75cu,0x0c07c75eu,0x0c07c760u,0x0c07c762u,0x0c07c764u,0x0c07c766u,0x0c07c768u,0x0c07c76au,0x0c07c76cu,
0x0c07c76eu,0x0c07c770u,0x0c07ca2au,0x0c07ca2cu,0x0c07ca2eu,0x0c07ca30u,0x0c07ca32u,0x0c07ca34u,0x0c07ca36u,0x0c07ca38u,0x0c07ca3au,0x0c07ca3cu,0x0c07ca3eu,0x0c07ca40u,0x0c07ca42u,0x0c07ca44u,
0x0c07ca46u,0x0c07ca48u,0x0c07ca4au,0x0c07ca4cu,0x0c07ca4eu,0x0c07ca50u,0x0c07ca52u,0x0c07ca54u,0x0c07ca56u,0x0c07ca58u,0x0c07ca5au,0x0c07ca5cu,0x0c07ca5eu,0x0c07e1cau,0x0c07e1ccu,0x0c07e1ceu,
0x0c07e1d0u,0x0c07e1d2u,0x0c07e1d4u,0x0c07e1d6u,0x0c07e1d8u,0x0c07e1dau,0x0c07e1dcu,0x0c07e1deu,0x0c07e1e0u,0x0c07e1e2u,0x0c07e1e4u,0x0c07e1e6u,0x0c07e1e8u,0x0c07e1eau,0x0c07e1ecu,0x0c07e1eeu,
0x0c07e1f0u,0x0c07e1f2u,0x0c07e1f4u,0x0c07e1f6u,0x0c07e1f8u,0x0c07e1fau,0x0c07e1fcu,0x0c07e1feu,0x0c07e200u,0x0c07e202u,0x0c07e204u,0x0c07e206u,0x0c07e208u,0x0c07e20au,0x0c07e20cu,0x0c07e20eu,
0x0c07e210u,0x0c07e212u,0x0c07e214u,0x0c07e216u,0x0c07e218u,0x0c07e21au,0x0c07e21cu,0x0c07e21eu,0x0c07e220u,0x0c07eba8u,0x0c07ebaau,0x0c07ebacu,0x0c07ebaeu,0x0c07ebb0u,0x0c07ebb2u,0x0c07ebb4u,
0x0c07ebb6u,0x0c07ebb8u,0x0c07ebbau,0x0c07ebbcu,0x0c07ebbeu,0x0c07ebc0u,0x0c07ebc2u,0x0c07ebc4u,0x0c07ebc6u,0x0c07ebc8u,0x0c07ebcau,0x0c07ebccu,0x0c07ebceu,0x0c07ebd0u,0x0c07ebd2u,0x0c07ebd4u,
0x0c07ebd6u,0x0c07ebd8u,0x0c07ebdau,0x0c07ebdcu,0x0c07ebdeu,0x0c07ebe0u,0x0c07ebe2u,0x0c07ebe4u,0x0c07ebe6u,0x0c07ebe8u,0x0c07ebeau,0x0c07ebecu,0x0c07ebeeu,0x0c07ebf0u,0x0c07ebf2u,0x0c07ebf4u,
0x0c07ebf6u,0x0c07ebf8u,0x0c07ebfau,0x0c07ebfcu,0x0c07ebfeu,0x0c07ec00u,0x0c07ec40u,0x0c07ec42u,0x0c07ec44u,0x0c07ec46u,0x0c07ec48u,0x0c07ec4au,0x0c07ec4cu,0x0c07ec4eu,0x0c07ec50u,0x0c07ec52u,
0x0c07ec54u,0x0c07ec56u,0x0c07ec58u,0x0c07ec5au,0x0c07ec5cu,0x0c07ec5eu,0x0c07ec60u,0x0c07ec62u,0x0c07ec64u,0x0c07ec66u,0x0c07ec68u,0x0c07ec6au,0x0c07ec6cu,0x0c07ec6eu,0x0c07ec70u,0x0c07ec72u,
0x0c07ec74u,0x0c07ec76u,0x0c07ec78u,0x0c07ec7au,0x0c07ec7cu,0x0c07ec7eu,0x0c07ec80u,0x0c07ec82u,0x0c07ec84u,0x0c07ec86u,0x0c07ec88u,0x0c07ec8au,0x0c07ec8cu,0x0c07ec8eu,0x0c07ec90u,0x0c07ec92u,
0x0c07ec94u,0x0c07ec96u,0x0c07ec98u,0x0c07ec9au,0x0c07ec9cu,0x0c07ec9eu,0x0c07eca0u,0x0c07eca2u,0x0c07eca4u,0x0c07eca6u,0x0c07eca8u,0x0c07ecaau,0x0c07ecacu,0x0c07ecaeu,0x0c07ecb0u,0x0c07ecb2u,
0x0c07ecb4u,0x0c07ecb6u,0x0c07ecb8u,0x0c07ecbau,0x0c07ecbcu,0x0c07ecbeu,0x0c07ecc0u,0x0c07ecc2u,0x0c07ecc4u,0x0c07ecc6u,0x0c07ecc8u,0x0c07eccau,0x0c07ecccu,0x0c07ecceu,0x0c07ecd0u,0x0c07ecd2u,
0x0c07ecd4u,0x0c07ecd6u,0x0c07ecd8u,0x0c07ecdau,0x0c07ecdcu,0x0c07ecdeu,0x0c07ece0u,0x0c07ece2u,0x0c07ece4u,0x0c07ece6u,0x0c07ece8u,0x0c07eceau,0x0c07ececu,0x0c07eceeu,0x0c07ecf0u,0x0c07ecf2u,
0x0c07ecf4u,0x0c07ecf6u,0x0c07ecf8u,0x0c07ecfau,0x0c07ecfcu,0x0c07ecfeu,0x0c07ed00u,0x0c07ed02u,0x0c07ed04u,0x0c07ed06u,0x0c07ed08u,0x0c07ed0au,0x0c07ed0cu,0x0c07ed0eu,0x0c07ed10u,0x0c07ed12u,
0x0c07ed14u,0x0c07ed16u,0x0c07ed18u,0x0c07ed1au,0x0c07ed1cu,0x0c07ed1eu,0x0c07ed20u,0x0c07ed58u,0x0c07ed5au,0x0c07ed5cu,0x0c07ed5eu,0x0c07ed60u,0x0c07ed62u,0x0c07ed64u,0x0c07ed66u,0x0c07ed68u,
0x0c07ed6au,0x0c07ed6cu,0x0c07ed6eu,0x0c07ed70u,0x0c07ed72u,0x0c07ed74u,0x0c07ed76u,0x0c07ed78u,0x0c07ed7au,0x0c07ed7cu,0x0c07ed7eu,0x0c07ed80u,0x0c07ed82u,0x0c07ed84u,0x0c07ed86u,0x0c07ed88u,
0x0c07ed8au,0x0c07ed8cu,0x0c07ed8eu,0x0c07ed90u,0x0c07ed92u,0x0c07ed94u,0x0c07ed96u,0x0c07ed98u,0x0c07ed9au,0x0c07ed9cu,0x0c07ed9eu,0x0c07eda0u,0x0c07eda2u,0x0c07eda4u,0x0c07eda6u,0x0c07eda8u,
0x0c07edaau,0x0c07edacu,0x0c07edaeu,0x0c07edb0u,0x0c07edb2u,0x0c07edb4u,0x0c07edb6u,0x0c07edb8u,0x0c07edbau,0x0c07edbcu,0x0c07edbeu,0x0c07edc0u,0x0c07edc2u,0x0c07edc4u,0x0c07edc6u,0x0c07edc8u,
0x0c07edcau,0x0c07edccu,0x0c07edceu,0x0c07edd0u,0x0c07edd2u,0x0c07edd4u,0x0c07edd6u,0x0c07edd8u,0x0c07eddau,0x0c07eddcu,0x0c07eddeu,0x0c07ede0u,0x0c07ede2u,0x0c07ede4u,0x0c07ede6u,0x0c07ede8u,
0x0c07edeau,0x0c07edecu,0x0c07edeeu,0x0c07edf0u,0x0c07edf2u,0x0c07edf4u,0x0c07edf6u,0x0c07edf8u,0x0c07edfau,0x0c07edfcu,0x0c07edfeu,0x0c07ee00u,0x0c07ee02u,0x0c07ee04u,0x0c07ee06u,0x0c07ee08u,
0x0c07ee0au,0x0c07ee0cu,0x0c07ee0eu,0x0c07ee10u,0x0c07ee12u,0x0c07ee14u,0x0c07ee16u,0x0c07ee18u,0x0c07ee1au,0x0c07ee1cu,0x0c07ee1eu,0x0c07ee20u,0x0c07ee22u,0x0c07ee24u,0x0c07ee26u,0x0c07ee28u,
0x0c07ee2au,0x0c07ee2cu,0x0c07ee2eu,0x0c07ee30u,0x0c07ee32u,0x0c080266u,0x0c080268u,0x0c08026au,0x0c08026cu,0x0c08026eu,0x0c080270u,0x0c080272u,0x0c080274u,0x0c080276u,0x0c080278u,0x0c08027au,
0x0c08027cu,0x0c08027eu,0x0c080280u,0x0c080282u,0x0c080284u,0x0c080286u,0x0c080288u,0x0c08028au,0x0c08439eu,0x0c0843a0u,0x0c0843a2u,0x0c0843a4u,0x0c0843a6u,0x0c0843a8u,0x0c0843aau,0x0c0843acu,
0x0c0843aeu,0x0c0843b0u,0x0c0843b2u,0x0c0843b4u,0x0c0843b6u,0x0c0843b8u,0x0c0843bau,0x0c0843bcu,0x0c0843beu,0x0c0843c0u,0x0c0843c2u,0x0c0843c4u,0x0c0843c6u,0x0c0843c8u,0x0c0843cau,0x0c0843ccu,
0x0c0843ceu,0x0c0843d0u,0x0c0843d2u,0x0c0843d4u,0x0c0968d0u,0x0c0968d2u,0x0c0968d4u,0x0c0968d6u,0x0c0968d8u,0x0c0968dau,0x0c0968dcu,0x0c0968deu,0x0c0968e0u,0x0c0968e2u,0x0c0968e4u,0x0c0968e6u,
0x0c0968e8u,0x0c0968eau,0x0c0968ecu,0x0c0968eeu,0x0c0968f0u,0x0c0968f2u,0x0c0968f4u,0x0c0968f6u,0x0c096d5eu,0x0c096d60u,0x0c096d62u,0x0c096d64u,0x0c096d66u,0x0c096d68u,0x0c096d6au,0x0c096d6cu,
0x0c096d6eu,0x0c096d70u,0x0c096d72u,0x0c096d74u,0x0c096d76u,0x0c096d78u,0x0c096d7au,0x0c096d7cu,0x0c096d7eu,0x0c096d80u,0x0c096d82u,0x0c096d84u,0x0c096d86u,0x0c096d88u,0x0c096d8au,0x0c096d8cu,
0x0c096d8eu,0x0c096d90u,0x0c096d92u,0x0c096d94u,0x0c096d96u,0x0c096d98u,0x0c096d9au,0x0c096d9cu,0x0c096d9eu,0x0c096da0u,0x0c096da2u,0x0c096da4u,0x0c096da6u,0x0c096da8u,0x0c096daau,0x0c096dacu,
0x0c096daeu,0x0c096db0u,0x0c096db2u,0x0c096db4u,0x0c096db6u,0x0c096db8u,0x0c096dbau,0x0c096dbcu,0x0c096dbeu,0x0c096f9au,0x0c096f9cu,0x0c096f9eu,0x0c096fa0u,0x0c096fa2u,0x0c096fa4u,0x0c096fa6u,
0x0c096fa8u,0x0c096faau,0x0c096facu,0x0c096faeu,0x0c096fb0u,0x0c096fb2u,0x0c096fb4u,0x0c096fb6u,0x0c096fb8u,0x0c096fbau,0x0c096fbcu,0x0c096fbeu,0x0c096fc0u,0x0c096fc2u,0x0c096fc4u,0x0c096fc6u,
0x0c096fc8u,0x0c096fcau,0x0c096fccu,0x0c096fceu,0x0c096fd0u,0x0c096fd2u,0x0c096fd4u,0x0c096fd6u,0x0c096fd8u,0x0c096fdau,0x0c096fdcu,0x0c096fdeu,0x0c096fe0u,0x0c096fe2u,0x0c096fe4u,0x0c096fe6u,
0x0c097942u,0x0c097944u,0x0c097946u,0x0c097948u,0x0c09794au,0x0c09794cu,0x0c09794eu,0x0c097950u,0x0c097952u,0x0c097954u,0x0c097956u,0x0c097958u,0x0c09795au,0x0c09795cu,0x0c09795eu,0x0c097960u,
0x0c097962u,0x0c097964u,0x0c097966u,0x0c097968u,0x0c09796au,0x0c09796cu,0x0c09796eu,0x0c097970u,0x0c097972u,0x0c097974u,0x0c097976u,0x0c097978u,0x0c09797au,0x0c09797cu,0x0c09797eu,0x0c097980u,
0x0c097982u,0x0c097984u,0x0c097986u,0x0c097988u,0x0c09798au,0x0c09798cu,0x0c09798eu,0x0c097990u,0x0c097992u,0x0c097994u,0x0c097996u,0x0c097998u,0x0c09799au,0x0c09799cu,0x0c09799eu,0x0c0979a0u,
0x0c0979a2u,0x0c0979a4u,0x0c0979a6u,0x0c0979a8u,0x0c0979aau,0x0c0979acu,0x0c0a12d2u,0x0c0a12d4u,0x0c0a12d6u,0x0c0a12d8u,0x0c0a12dau,0x0c0a12dcu,0x0c0a12deu,0x0c0a12e0u,0x0c0a12e2u,0x0c0a293au,
0x0c0a293cu,0x0c0a293eu,0x0c0a2940u,0x0c0a2942u,0x0c0a2944u,0x0c0a2946u,0x0c0a2948u,0x0c0a294au,0x0c0a294cu,0x0c0a294eu,0x0c0a2950u,0x0c0a2952u,0x0c0a2954u,0x0c0a2956u,0x0c0a2958u,0x0c0a295au,
0x0c0a295cu,0x0c0a7ba8u,0x0c0a7baau,0x0c0a7bacu,0x0c0a7baeu,0x0c0a7bb0u,0x0c0a7bb2u,0x0c0a7bb4u,0x0c0a7bb6u,0x0c0a7bb8u,0x0c0a7bbau,0x0c0a7bbcu,0x0c0a7bbeu,0x0c0a7bc0u,0x0c0a7bc2u,0x0c0a7bc4u,
0x0c0a7bc6u,0x0c0a7bc8u,0x0c0a7bcau,0x0c0a7bccu,0x0c0a7bceu,0x0c0a7bd0u,0x0c0a7bd2u,0x0c0a7bd4u,0x0c0a7bd6u,0x0c0a7bd8u,0x0c0a7bdau,0x0c0a7bdcu,0x0c0a7bdeu,0x0c0a7be0u,0x0c0a87aau,0x0c0a87acu,
0x0c0a87aeu,0x0c0a87b0u,0x0c0a87b2u,0x0c0a87b4u,0x0c0a87b6u,0x0c0a87b8u,0x0c0a87bau,0x0c0a87bcu,0x0c0a87beu,0x0c0a87c0u,0x0c0a87c2u,0x0c0a87c4u,0x0c0a87c6u,0x0c0a87c8u,0x0c0a87cau,0x0c0a87ccu,
0x0c0a87ceu,0x0c0a87d0u,0x0c0a87d2u,0x0c0a87d4u,0x0c0a87d6u,0x0c0a87d8u,0x0c0a87dau,0x0c0a87dcu,0x0c0a87deu,0x0c0a87e0u,0x0c0a87e2u,0x0c0a87e4u,0x0c0a87e6u,0x0c0a87e8u,0x0c0c1a66u,0x0c0c1a68u,
0x0c0c1a6au,0x0c0c1a6cu,0x0c0c1a6eu,0x0c0c1a70u,0x0c0c1a72u,0x0c0c1a74u,0x0c0c1a76u,0x0c0c1a78u,0x0c0c1a7au,0x0c0c1a7cu,0x0c0c1a7eu,0x0c0c1a80u,0x0c0c1a82u,0x0c0c1a84u,0x0c0c1a86u,0x0c0c2d06u,
0x0c0c2d08u,0x0c0c2d0au,0x0c0c2d0cu,0x0c0c2d0eu,0x0c0c74bcu,0x0c0c74beu,0x0c0c74c0u,0x0c0c74c2u,0x0c0c74c4u,0x0c0c74c6u,0x0c0c74c8u,0x0c0c74cau,0x0c0c74ccu,0x0c0c74ceu,0x0c0c74d0u,0x0c0c74d2u,
0x0c0c74d4u,0x0c0c74d6u,0x0c0c74d8u,0x0c0c74dau,0x0c0c74dcu,0x0c0c74deu,0x0c0c74e0u,0x0c0c74e2u,0x0c0c74e4u,0x0c0c74e6u,0x0c0c74e8u,0x0c0c74eau,0x0c0c74ecu,0x0c0c74eeu,0x0c0c74f0u,0x0c0c74f2u,
0x0c0c74f4u,0x0c0c74f6u,0x0c0c74f8u,0x0c0c74fau,0x0c0c74fcu,0x0c0c74feu,0x0c0c7500u,0x0c0c7502u,0x0c0c7504u,0x0c0c7506u,0x0c0c7508u,0x0c0c750au,0x0c0c750cu,0x0c0c750eu,0x0c0c7510u,0x0c0c7512u,
0x0c0c7514u,0x0c0c7516u,0x0c0c7518u,0x0c0c751au,0x0c0c751cu,0x0c0c751eu,0x0c0c7520u,0x0c0c7522u,0x0c0c7524u,0x0c0c7526u,0x0c0c7528u,0x0c0c752au,0x0c0c752cu,0x0c0c752eu,0x0c0c7530u,0x0c0c7532u,
0x0c0c7534u,0x0c0c7536u,0x0c0c7538u,0x0c0c753au,0x0c0c753cu,0x0c0c753eu,0x0c0c7540u,0x0c0c7542u,
};
int vf3_c94_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
