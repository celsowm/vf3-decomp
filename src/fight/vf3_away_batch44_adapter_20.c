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
int vf3_away_batch44_adapter_20(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07c534u: goto P_0c07c534;
case 0x0c07c536u: goto P_0c07c536;
case 0x0c07c538u: goto P_0c07c538;
case 0x0c07c53au: goto P_0c07c53a;
case 0x0c07c53cu: goto P_0c07c53c;
case 0x0c07c53eu: goto P_0c07c53e;
case 0x0c07c540u: goto P_0c07c540;
case 0x0c07c542u: goto P_0c07c542;
case 0x0c07c544u: goto P_0c07c544;
case 0x0c07c546u: goto P_0c07c546;
case 0x0c07c548u: goto P_0c07c548;
case 0x0c07c54au: goto P_0c07c54a;
case 0x0c07c54cu: goto P_0c07c54c;
case 0x0c07c54eu: goto P_0c07c54e;
case 0x0c07c550u: goto P_0c07c550;
case 0x0c07c552u: goto P_0c07c552;
case 0x0c07c554u: goto P_0c07c554;
case 0x0c07c556u: goto P_0c07c556;
case 0x0c07c558u: goto P_0c07c558;
case 0x0c07c55au: goto P_0c07c55a;
case 0x0c07c55cu: goto P_0c07c55c;
case 0x0c07c55eu: goto P_0c07c55e;
case 0x0c07c560u: goto P_0c07c560;
case 0x0c07c562u: goto P_0c07c562;
case 0x0c07c564u: goto P_0c07c564;
case 0x0c07c566u: goto P_0c07c566;
case 0x0c07c568u: goto P_0c07c568;
case 0x0c07c56au: goto P_0c07c56a;
case 0x0c07c56cu: goto P_0c07c56c;
case 0x0c07c56eu: goto P_0c07c56e;
case 0x0c07c570u: goto P_0c07c570;
case 0x0c07c572u: goto P_0c07c572;
case 0x0c07c574u: goto P_0c07c574;
case 0x0c07c576u: goto P_0c07c576;
case 0x0c07c578u: goto P_0c07c578;
case 0x0c07c57au: goto P_0c07c57a;
case 0x0c07c57cu: goto P_0c07c57c;
case 0x0c07c57eu: goto P_0c07c57e;
case 0x0c07c580u: goto P_0c07c580;
case 0x0c07c582u: goto P_0c07c582;
case 0x0c07c584u: goto P_0c07c584;
case 0x0c07c586u: goto P_0c07c586;
case 0x0c07c588u: goto P_0c07c588;
case 0x0c07c58au: goto P_0c07c58a;
case 0x0c07c58cu: goto P_0c07c58c;
case 0x0c07c58eu: goto P_0c07c58e;
case 0x0c07c590u: goto P_0c07c590;
case 0x0c07c592u: goto P_0c07c592;
case 0x0c07c594u: goto P_0c07c594;
case 0x0c07c596u: goto P_0c07c596;
case 0x0c07c598u: goto P_0c07c598;
case 0x0c07c59au: goto P_0c07c59a;
case 0x0c07c59cu: goto P_0c07c59c;
case 0x0c07c59eu: goto P_0c07c59e;
case 0x0c07c5a0u: goto P_0c07c5a0;
case 0x0c07c5a2u: goto P_0c07c5a2;
case 0x0c07c5a4u: goto P_0c07c5a4;
case 0x0c07c5a6u: goto P_0c07c5a6;
case 0x0c07c5a8u: goto P_0c07c5a8;
case 0x0c07c5aau: goto P_0c07c5aa;
case 0x0c07c5acu: goto P_0c07c5ac;
case 0x0c07c5aeu: goto P_0c07c5ae;
case 0x0c07c5b0u: goto P_0c07c5b0;
case 0x0c07c5b2u: goto P_0c07c5b2;
case 0x0c07c5b4u: goto P_0c07c5b4;
case 0x0c07c5b6u: goto P_0c07c5b6;
case 0x0c07c5b8u: goto P_0c07c5b8;
case 0x0c07c5bau: goto P_0c07c5ba;
case 0x0c07c5bcu: goto P_0c07c5bc;
case 0x0c07c5beu: goto P_0c07c5be;
case 0x0c07c5c0u: goto P_0c07c5c0;
case 0x0c07c5c2u: goto P_0c07c5c2;
case 0x0c07c5c4u: goto P_0c07c5c4;
case 0x0c07c5c6u: goto P_0c07c5c6;
case 0x0c07c5c8u: goto P_0c07c5c8;
case 0x0c07c5cau: goto P_0c07c5ca;
case 0x0c07c5ccu: goto P_0c07c5cc;
case 0x0c07c5ceu: goto P_0c07c5ce;
case 0x0c07c5d0u: goto P_0c07c5d0;
case 0x0c07c5d2u: goto P_0c07c5d2;
case 0x0c07c5d4u: goto P_0c07c5d4;
case 0x0c07c5d6u: goto P_0c07c5d6;
case 0x0c07c5d8u: goto P_0c07c5d8;
case 0x0c07c5dau: goto P_0c07c5da;
case 0x0c07c5dcu: goto P_0c07c5dc;
case 0x0c07c5deu: goto P_0c07c5de;
case 0x0c07c5e0u: goto P_0c07c5e0;
case 0x0c07c5e2u: goto P_0c07c5e2;
case 0x0c07c5e4u: goto P_0c07c5e4;
case 0x0c07c5e6u: goto P_0c07c5e6;
case 0x0c07c6acu: goto P_0c07c6ac;
case 0x0c07c6aeu: goto P_0c07c6ae;
case 0x0c07c6b0u: goto P_0c07c6b0;
case 0x0c07c6b2u: goto P_0c07c6b2;
case 0x0c07c6b4u: goto P_0c07c6b4;
case 0x0c07c6b6u: goto P_0c07c6b6;
case 0x0c07c6b8u: goto P_0c07c6b8;
case 0x0c07c6bau: goto P_0c07c6ba;
case 0x0c07c6bcu: goto P_0c07c6bc;
case 0x0c07c6beu: goto P_0c07c6be;
case 0x0c07c6c0u: goto P_0c07c6c0;
case 0x0c07c6c2u: goto P_0c07c6c2;
case 0x0c07c6c4u: goto P_0c07c6c4;
case 0x0c07c6c6u: goto P_0c07c6c6;
case 0x0c07c6c8u: goto P_0c07c6c8;
case 0x0c07c6cau: goto P_0c07c6ca;
case 0x0c07c6ccu: goto P_0c07c6cc;
case 0x0c07c6ceu: goto P_0c07c6ce;
case 0x0c07c6d0u: goto P_0c07c6d0;
case 0x0c07c6d2u: goto P_0c07c6d2;
case 0x0c07c6d4u: goto P_0c07c6d4;
case 0x0c07c6d6u: goto P_0c07c6d6;
case 0x0c07c6d8u: goto P_0c07c6d8;
case 0x0c07c6dau: goto P_0c07c6da;
case 0x0c07c6dcu: goto P_0c07c6dc;
case 0x0c07c6deu: goto P_0c07c6de;
case 0x0c07c6e0u: goto P_0c07c6e0;
case 0x0c07c6e2u: goto P_0c07c6e2;
case 0x0c07c6e4u: goto P_0c07c6e4;
case 0x0c07c6e6u: goto P_0c07c6e6;
case 0x0c07c6e8u: goto P_0c07c6e8;
case 0x0c07c6eau: goto P_0c07c6ea;
case 0x0c07c6ecu: goto P_0c07c6ec;
case 0x0c07c6eeu: goto P_0c07c6ee;
case 0x0c07c6f0u: goto P_0c07c6f0;
case 0x0c07c6f2u: goto P_0c07c6f2;
case 0x0c07c6f4u: goto P_0c07c6f4;
case 0x0c07c6f6u: goto P_0c07c6f6;
case 0x0c07c6f8u: goto P_0c07c6f8;
case 0x0c07c6fau: goto P_0c07c6fa;
case 0x0c07c6fcu: goto P_0c07c6fc;
case 0x0c07c6feu: goto P_0c07c6fe;
case 0x0c07c700u: goto P_0c07c700;
case 0x0c07c702u: goto P_0c07c702;
case 0x0c07c704u: goto P_0c07c704;
case 0x0c07c706u: goto P_0c07c706;
case 0x0c07c708u: goto P_0c07c708;
case 0x0c07c70au: goto P_0c07c70a;
case 0x0c07c70cu: goto P_0c07c70c;
case 0x0c07c70eu: goto P_0c07c70e;
case 0x0c07c710u: goto P_0c07c710;
case 0x0c07c712u: goto P_0c07c712;
case 0x0c07c714u: goto P_0c07c714;
case 0x0c07c716u: goto P_0c07c716;
case 0x0c07c718u: goto P_0c07c718;
case 0x0c07c71au: goto P_0c07c71a;
case 0x0c07c71cu: goto P_0c07c71c;
case 0x0c07c71eu: goto P_0c07c71e;
case 0x0c07c720u: goto P_0c07c720;
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
case 0x0c07d948u: goto P_0c07d948;
case 0x0c07d94au: goto P_0c07d94a;
case 0x0c07d94cu: goto P_0c07d94c;
case 0x0c07d94eu: goto P_0c07d94e;
case 0x0c07d950u: goto P_0c07d950;
case 0x0c07d952u: goto P_0c07d952;
case 0x0c07d954u: goto P_0c07d954;
case 0x0c07d956u: goto P_0c07d956;
case 0x0c07d958u: goto P_0c07d958;
case 0x0c07d95au: goto P_0c07d95a;
case 0x0c07d95cu: goto P_0c07d95c;
case 0x0c07d95eu: goto P_0c07d95e;
case 0x0c07d960u: goto P_0c07d960;
case 0x0c07d962u: goto P_0c07d962;
case 0x0c07d964u: goto P_0c07d964;
case 0x0c07d966u: goto P_0c07d966;
case 0x0c07d968u: goto P_0c07d968;
case 0x0c07d96au: goto P_0c07d96a;
case 0x0c07d96cu: goto P_0c07d96c;
case 0x0c07d96eu: goto P_0c07d96e;
case 0x0c07d970u: goto P_0c07d970;
case 0x0c07d972u: goto P_0c07d972;
case 0x0c07d974u: goto P_0c07d974;
case 0x0c07d976u: goto P_0c07d976;
case 0x0c07d978u: goto P_0c07d978;
case 0x0c07d97au: goto P_0c07d97a;
case 0x0c07d97cu: goto P_0c07d97c;
case 0x0c07d97eu: goto P_0c07d97e;
case 0x0c07d980u: goto P_0c07d980;
case 0x0c07d982u: goto P_0c07d982;
case 0x0c07d984u: goto P_0c07d984;
case 0x0c07d986u: goto P_0c07d986;
case 0x0c07d988u: goto P_0c07d988;
case 0x0c07d98au: goto P_0c07d98a;
case 0x0c07d98cu: goto P_0c07d98c;
case 0x0c07d98eu: goto P_0c07d98e;
case 0x0c07d990u: goto P_0c07d990;
case 0x0c07d992u: goto P_0c07d992;
case 0x0c07d994u: goto P_0c07d994;
case 0x0c07d996u: goto P_0c07d996;
case 0x0c07d998u: goto P_0c07d998;
case 0x0c07d99au: goto P_0c07d99a;
case 0x0c07d99cu: goto P_0c07d99c;
case 0x0c07d99eu: goto P_0c07d99e;
case 0x0c07d9a0u: goto P_0c07d9a0;
case 0x0c07d9a2u: goto P_0c07d9a2;
case 0x0c07d9a4u: goto P_0c07d9a4;
case 0x0c07d9a6u: goto P_0c07d9a6;
case 0x0c07d9a8u: goto P_0c07d9a8;
case 0x0c07d9aau: goto P_0c07d9aa;
case 0x0c07d9acu: goto P_0c07d9ac;
case 0x0c07d9aeu: goto P_0c07d9ae;
case 0x0c07d9b0u: goto P_0c07d9b0;
case 0x0c07d9b2u: goto P_0c07d9b2;
case 0x0c07d9b4u: goto P_0c07d9b4;
case 0x0c07d9b6u: goto P_0c07d9b6;
case 0x0c07d9b8u: goto P_0c07d9b8;
case 0x0c07d9bau: goto P_0c07d9ba;
case 0x0c07d9bcu: goto P_0c07d9bc;
case 0x0c07d9beu: goto P_0c07d9be;
case 0x0c07d9c0u: goto P_0c07d9c0;
case 0x0c07d9c2u: goto P_0c07d9c2;
case 0x0c07d9c4u: goto P_0c07d9c4;
case 0x0c07d9c6u: goto P_0c07d9c6;
case 0x0c07d9c8u: goto P_0c07d9c8;
case 0x0c07d9cau: goto P_0c07d9ca;
case 0x0c07d9ccu: goto P_0c07d9cc;
case 0x0c07d9ceu: goto P_0c07d9ce;
case 0x0c07d9d0u: goto P_0c07d9d0;
case 0x0c07d9d2u: goto P_0c07d9d2;
case 0x0c07d9d4u: goto P_0c07d9d4;
case 0x0c07d9d6u: goto P_0c07d9d6;
case 0x0c07d9d8u: goto P_0c07d9d8;
case 0x0c07d9dau: goto P_0c07d9da;
case 0x0c07da00u: goto P_0c07da00;
case 0x0c07da02u: goto P_0c07da02;
case 0x0c07da04u: goto P_0c07da04;
case 0x0c07da06u: goto P_0c07da06;
case 0x0c07da08u: goto P_0c07da08;
case 0x0c07da0au: goto P_0c07da0a;
case 0x0c07da0cu: goto P_0c07da0c;
case 0x0c07da0eu: goto P_0c07da0e;
case 0x0c07da10u: goto P_0c07da10;
case 0x0c07da12u: goto P_0c07da12;
case 0x0c07da14u: goto P_0c07da14;
case 0x0c07da16u: goto P_0c07da16;
case 0x0c07da18u: goto P_0c07da18;
case 0x0c07da1au: goto P_0c07da1a;
case 0x0c07da1cu: goto P_0c07da1c;
case 0x0c07da1eu: goto P_0c07da1e;
case 0x0c07da20u: goto P_0c07da20;
case 0x0c07da22u: goto P_0c07da22;
case 0x0c07da24u: goto P_0c07da24;
case 0x0c07da26u: goto P_0c07da26;
case 0x0c07da28u: goto P_0c07da28;
case 0x0c07da2au: goto P_0c07da2a;
case 0x0c07da2cu: goto P_0c07da2c;
case 0x0c07da2eu: goto P_0c07da2e;
case 0x0c07da30u: goto P_0c07da30;
case 0x0c07da32u: goto P_0c07da32;
case 0x0c07da34u: goto P_0c07da34;
case 0x0c07da36u: goto P_0c07da36;
case 0x0c07da38u: goto P_0c07da38;
case 0x0c07da3au: goto P_0c07da3a;
case 0x0c07da3cu: goto P_0c07da3c;
case 0x0c07da3eu: goto P_0c07da3e;
case 0x0c07da40u: goto P_0c07da40;
case 0x0c07da42u: goto P_0c07da42;
case 0x0c07da44u: goto P_0c07da44;
case 0x0c07da46u: goto P_0c07da46;
case 0x0c07da48u: goto P_0c07da48;
case 0x0c07da4au: goto P_0c07da4a;
case 0x0c07da4cu: goto P_0c07da4c;
case 0x0c07da4eu: goto P_0c07da4e;
case 0x0c07da50u: goto P_0c07da50;
case 0x0c07da52u: goto P_0c07da52;
case 0x0c07da54u: goto P_0c07da54;
case 0x0c07da56u: goto P_0c07da56;
case 0x0c07da58u: goto P_0c07da58;
case 0x0c07da5au: goto P_0c07da5a;
case 0x0c07da5cu: goto P_0c07da5c;
case 0x0c07da5eu: goto P_0c07da5e;
case 0x0c07da60u: goto P_0c07da60;
case 0x0c07da62u: goto P_0c07da62;
case 0x0c07da64u: goto P_0c07da64;
case 0x0c07da66u: goto P_0c07da66;
case 0x0c07da68u: goto P_0c07da68;
case 0x0c07da6au: goto P_0c07da6a;
case 0x0c07da6cu: goto P_0c07da6c;
case 0x0c07da6eu: goto P_0c07da6e;
case 0x0c07da70u: goto P_0c07da70;
case 0x0c07da72u: goto P_0c07da72;
case 0x0c07da74u: goto P_0c07da74;
case 0x0c07da76u: goto P_0c07da76;
case 0x0c07da78u: goto P_0c07da78;
case 0x0c07da7au: goto P_0c07da7a;
case 0x0c07da7cu: goto P_0c07da7c;
case 0x0c07da7eu: goto P_0c07da7e;
case 0x0c07da80u: goto P_0c07da80;
case 0x0c07da82u: goto P_0c07da82;
case 0x0c07da84u: goto P_0c07da84;
case 0x0c07da86u: goto P_0c07da86;
case 0x0c07da88u: goto P_0c07da88;
case 0x0c07da8au: goto P_0c07da8a;
case 0x0c07da8cu: goto P_0c07da8c;
case 0x0c07da8eu: goto P_0c07da8e;
case 0x0c07da90u: goto P_0c07da90;
case 0x0c07da92u: goto P_0c07da92;
case 0x0c07da94u: goto P_0c07da94;
case 0x0c07da96u: goto P_0c07da96;
case 0x0c07da98u: goto P_0c07da98;
case 0x0c07da9au: goto P_0c07da9a;
case 0x0c07da9cu: goto P_0c07da9c;
case 0x0c07da9eu: goto P_0c07da9e;
case 0x0c07daa0u: goto P_0c07daa0;
case 0x0c07daa2u: goto P_0c07daa2;
case 0x0c07daa4u: goto P_0c07daa4;
case 0x0c07daa6u: goto P_0c07daa6;
case 0x0c07daa8u: goto P_0c07daa8;
case 0x0c07daaau: goto P_0c07daaa;
case 0x0c07daacu: goto P_0c07daac;
case 0x0c07daaeu: goto P_0c07daae;
case 0x0c07dab0u: goto P_0c07dab0;
case 0x0c07dab2u: goto P_0c07dab2;
case 0x0c07dab4u: goto P_0c07dab4;
case 0x0c07dab6u: goto P_0c07dab6;
case 0x0c07dab8u: goto P_0c07dab8;
case 0x0c07dabau: goto P_0c07daba;
case 0x0c07dabcu: goto P_0c07dabc;
case 0x0c07dabeu: goto P_0c07dabe;
case 0x0c07dac0u: goto P_0c07dac0;
case 0x0c07dac2u: goto P_0c07dac2;
case 0x0c07dac4u: goto P_0c07dac4;
case 0x0c07dac6u: goto P_0c07dac6;
case 0x0c07dac8u: goto P_0c07dac8;
case 0x0c07dacau: goto P_0c07daca;
case 0x0c07daccu: goto P_0c07dacc;
case 0x0c07daceu: goto P_0c07dace;
case 0x0c07dad0u: goto P_0c07dad0;
case 0x0c07dad2u: goto P_0c07dad2;
case 0x0c07dad4u: goto P_0c07dad4;
case 0x0c07dad6u: goto P_0c07dad6;
case 0x0c07dad8u: goto P_0c07dad8;
case 0x0c07dadau: goto P_0c07dada;
case 0x0c07dadcu: goto P_0c07dadc;
case 0x0c07dadeu: goto P_0c07dade;
case 0x0c07dae0u: goto P_0c07dae0;
case 0x0c07daf0u: goto P_0c07daf0;
case 0x0c07daf2u: goto P_0c07daf2;
case 0x0c07daf4u: goto P_0c07daf4;
case 0x0c07daf6u: goto P_0c07daf6;
case 0x0c07daf8u: goto P_0c07daf8;
case 0x0c07dafau: goto P_0c07dafa;
case 0x0c07dafcu: goto P_0c07dafc;
case 0x0c07dafeu: goto P_0c07dafe;
case 0x0c07db00u: goto P_0c07db00;
case 0x0c07db02u: goto P_0c07db02;
case 0x0c07db04u: goto P_0c07db04;
case 0x0c07db06u: goto P_0c07db06;
case 0x0c07db08u: goto P_0c07db08;
case 0x0c07db0au: goto P_0c07db0a;
case 0x0c07db0cu: goto P_0c07db0c;
case 0x0c07db0eu: goto P_0c07db0e;
case 0x0c07db10u: goto P_0c07db10;
case 0x0c07db12u: goto P_0c07db12;
case 0x0c07db14u: goto P_0c07db14;
case 0x0c07db16u: goto P_0c07db16;
case 0x0c07db18u: goto P_0c07db18;
case 0x0c07db1au: goto P_0c07db1a;
case 0x0c07db1cu: goto P_0c07db1c;
case 0x0c07db1eu: goto P_0c07db1e;
case 0x0c07db20u: goto P_0c07db20;
case 0x0c07db22u: goto P_0c07db22;
case 0x0c07db24u: goto P_0c07db24;
case 0x0c07db26u: goto P_0c07db26;
case 0x0c07db28u: goto P_0c07db28;
case 0x0c07db2au: goto P_0c07db2a;
case 0x0c07db2cu: goto P_0c07db2c;
case 0x0c07db2eu: goto P_0c07db2e;
case 0x0c07db30u: goto P_0c07db30;
case 0x0c07db32u: goto P_0c07db32;
case 0x0c07db34u: goto P_0c07db34;
case 0x0c07db36u: goto P_0c07db36;
case 0x0c07db38u: goto P_0c07db38;
case 0x0c07db3au: goto P_0c07db3a;
case 0x0c07db3cu: goto P_0c07db3c;
case 0x0c07db3eu: goto P_0c07db3e;
case 0x0c07db40u: goto P_0c07db40;
case 0x0c07db42u: goto P_0c07db42;
case 0x0c07db44u: goto P_0c07db44;
case 0x0c07db46u: goto P_0c07db46;
case 0x0c07db48u: goto P_0c07db48;
case 0x0c07db4au: goto P_0c07db4a;
case 0x0c07db4cu: goto P_0c07db4c;
case 0x0c07db4eu: goto P_0c07db4e;
case 0x0c07db50u: goto P_0c07db50;
case 0x0c07db52u: goto P_0c07db52;
case 0x0c07db54u: goto P_0c07db54;
case 0x0c07db56u: goto P_0c07db56;
case 0x0c07db58u: goto P_0c07db58;
case 0x0c07db5au: goto P_0c07db5a;
case 0x0c07db5cu: goto P_0c07db5c;
case 0x0c07db5eu: goto P_0c07db5e;
case 0x0c07db60u: goto P_0c07db60;
case 0x0c07db62u: goto P_0c07db62;
case 0x0c07db64u: goto P_0c07db64;
case 0x0c07db66u: goto P_0c07db66;
case 0x0c07db68u: goto P_0c07db68;
case 0x0c07db6au: goto P_0c07db6a;
case 0x0c07db6cu: goto P_0c07db6c;
case 0x0c07db6eu: goto P_0c07db6e;
case 0x0c07db70u: goto P_0c07db70;
case 0x0c07db72u: goto P_0c07db72;
case 0x0c07db74u: goto P_0c07db74;
case 0x0c07db76u: goto P_0c07db76;
case 0x0c07db78u: goto P_0c07db78;
case 0x0c07db7au: goto P_0c07db7a;
case 0x0c07db7cu: goto P_0c07db7c;
case 0x0c07db7eu: goto P_0c07db7e;
case 0x0c07db80u: goto P_0c07db80;
case 0x0c07db82u: goto P_0c07db82;
case 0x0c07db84u: goto P_0c07db84;
case 0x0c07db86u: goto P_0c07db86;
case 0x0c07db88u: goto P_0c07db88;
case 0x0c07db8au: goto P_0c07db8a;
case 0x0c07db8cu: goto P_0c07db8c;
case 0x0c07db8eu: goto P_0c07db8e;
case 0x0c07db90u: goto P_0c07db90;
case 0x0c07db92u: goto P_0c07db92;
case 0x0c07db94u: goto P_0c07db94;
case 0x0c07db96u: goto P_0c07db96;
case 0x0c07db98u: goto P_0c07db98;
case 0x0c07db9au: goto P_0c07db9a;
case 0x0c07db9cu: goto P_0c07db9c;
case 0x0c07db9eu: goto P_0c07db9e;
case 0x0c07dba0u: goto P_0c07dba0;
case 0x0c07dba2u: goto P_0c07dba2;
case 0x0c07dba4u: goto P_0c07dba4;
case 0x0c07dba6u: goto P_0c07dba6;
case 0x0c07dba8u: goto P_0c07dba8;
case 0x0c07dbaau: goto P_0c07dbaa;
case 0x0c07dbacu: goto P_0c07dbac;
case 0x0c07dbaeu: goto P_0c07dbae;
case 0x0c07dbb0u: goto P_0c07dbb0;
case 0x0c07dbb2u: goto P_0c07dbb2;
case 0x0c07dbb4u: goto P_0c07dbb4;
case 0x0c07dbb6u: goto P_0c07dbb6;
case 0x0c07dbb8u: goto P_0c07dbb8;
case 0x0c07dbbau: goto P_0c07dbba;
case 0x0c07dbbcu: goto P_0c07dbbc;
case 0x0c07dbbeu: goto P_0c07dbbe;
case 0x0c07dbc0u: goto P_0c07dbc0;
case 0x0c07dbc2u: goto P_0c07dbc2;
case 0x0c07dbc4u: goto P_0c07dbc4;
case 0x0c07dbc6u: goto P_0c07dbc6;
case 0x0c07dbc8u: goto P_0c07dbc8;
case 0x0c07dbcau: goto P_0c07dbca;
case 0x0c07dbccu: goto P_0c07dbcc;
case 0x0c07dbceu: goto P_0c07dbce;
case 0x0c07dbd0u: goto P_0c07dbd0;
case 0x0c07dbd2u: goto P_0c07dbd2;
case 0x0c07dbd4u: goto P_0c07dbd4;
case 0x0c07dbd6u: goto P_0c07dbd6;
case 0x0c07dbd8u: goto P_0c07dbd8;
case 0x0c07dbdau: goto P_0c07dbda;
case 0x0c07dbdcu: goto P_0c07dbdc;
case 0x0c07dbdeu: goto P_0c07dbde;
case 0x0c07dbe0u: goto P_0c07dbe0;
case 0x0c07dbe2u: goto P_0c07dbe2;
case 0x0c07dbf0u: goto P_0c07dbf0;
case 0x0c07dbf2u: goto P_0c07dbf2;
case 0x0c07dbf4u: goto P_0c07dbf4;
case 0x0c07dbf6u: goto P_0c07dbf6;
case 0x0c07dbf8u: goto P_0c07dbf8;
case 0x0c07dbfau: goto P_0c07dbfa;
case 0x0c07dbfcu: goto P_0c07dbfc;
case 0x0c07dbfeu: goto P_0c07dbfe;
case 0x0c07dc00u: goto P_0c07dc00;
case 0x0c07dc02u: goto P_0c07dc02;
case 0x0c07dc04u: goto P_0c07dc04;
case 0x0c07dc06u: goto P_0c07dc06;
case 0x0c07dc08u: goto P_0c07dc08;
case 0x0c07dc0au: goto P_0c07dc0a;
case 0x0c07dc0cu: goto P_0c07dc0c;
case 0x0c07dc0eu: goto P_0c07dc0e;
case 0x0c07dc10u: goto P_0c07dc10;
case 0x0c07dc12u: goto P_0c07dc12;
case 0x0c07dc14u: goto P_0c07dc14;
case 0x0c07dc16u: goto P_0c07dc16;
case 0x0c07dc18u: goto P_0c07dc18;
case 0x0c07dc1au: goto P_0c07dc1a;
case 0x0c07dc1cu: goto P_0c07dc1c;
case 0x0c07dc1eu: goto P_0c07dc1e;
case 0x0c07dc20u: goto P_0c07dc20;
case 0x0c07dc22u: goto P_0c07dc22;
case 0x0c07dc24u: goto P_0c07dc24;
case 0x0c07dc26u: goto P_0c07dc26;
case 0x0c07dc28u: goto P_0c07dc28;
case 0x0c07dc2au: goto P_0c07dc2a;
case 0x0c07dc2cu: goto P_0c07dc2c;
case 0x0c07dc2eu: goto P_0c07dc2e;
case 0x0c07dc30u: goto P_0c07dc30;
case 0x0c07dc32u: goto P_0c07dc32;
case 0x0c07dc34u: goto P_0c07dc34;
case 0x0c07dc36u: goto P_0c07dc36;
case 0x0c07dc38u: goto P_0c07dc38;
case 0x0c07dc3au: goto P_0c07dc3a;
case 0x0c07dc3cu: goto P_0c07dc3c;
case 0x0c07dc3eu: goto P_0c07dc3e;
case 0x0c07dc40u: goto P_0c07dc40;
case 0x0c07dc42u: goto P_0c07dc42;
case 0x0c07dc44u: goto P_0c07dc44;
case 0x0c07dc46u: goto P_0c07dc46;
case 0x0c07dc48u: goto P_0c07dc48;
case 0x0c07dc4au: goto P_0c07dc4a;
case 0x0c07dc4cu: goto P_0c07dc4c;
case 0x0c07dc4eu: goto P_0c07dc4e;
case 0x0c07dc50u: goto P_0c07dc50;
case 0x0c07dc52u: goto P_0c07dc52;
case 0x0c07dc54u: goto P_0c07dc54;
case 0x0c07dc56u: goto P_0c07dc56;
case 0x0c07dc58u: goto P_0c07dc58;
case 0x0c07dc5au: goto P_0c07dc5a;
case 0x0c07dc5cu: goto P_0c07dc5c;
case 0x0c07dc5eu: goto P_0c07dc5e;
case 0x0c07dc60u: goto P_0c07dc60;
case 0x0c07dc62u: goto P_0c07dc62;
case 0x0c07dc64u: goto P_0c07dc64;
case 0x0c07dc66u: goto P_0c07dc66;
case 0x0c07dc68u: goto P_0c07dc68;
case 0x0c07dc6au: goto P_0c07dc6a;
case 0x0c07dc6cu: goto P_0c07dc6c;
case 0x0c07dc6eu: goto P_0c07dc6e;
case 0x0c07dc70u: goto P_0c07dc70;
case 0x0c07dc72u: goto P_0c07dc72;
case 0x0c07dc74u: goto P_0c07dc74;
case 0x0c07dc76u: goto P_0c07dc76;
case 0x0c07dc78u: goto P_0c07dc78;
case 0x0c07dc7au: goto P_0c07dc7a;
case 0x0c07dc7cu: goto P_0c07dc7c;
case 0x0c07dc7eu: goto P_0c07dc7e;
case 0x0c07dc80u: goto P_0c07dc80;
case 0x0c07dc82u: goto P_0c07dc82;
case 0x0c07dc84u: goto P_0c07dc84;
case 0x0c07dc86u: goto P_0c07dc86;
case 0x0c07dc88u: goto P_0c07dc88;
case 0x0c07dc8au: goto P_0c07dc8a;
case 0x0c07dc8cu: goto P_0c07dc8c;
case 0x0c07dc8eu: goto P_0c07dc8e;
case 0x0c07dc90u: goto P_0c07dc90;
case 0x0c07dc92u: goto P_0c07dc92;
case 0x0c07dc94u: goto P_0c07dc94;
case 0x0c07dc96u: goto P_0c07dc96;
case 0x0c07dc98u: goto P_0c07dc98;
case 0x0c07dc9au: goto P_0c07dc9a;
case 0x0c07dc9cu: goto P_0c07dc9c;
case 0x0c07dc9eu: goto P_0c07dc9e;
case 0x0c07dca0u: goto P_0c07dca0;
case 0x0c07dca2u: goto P_0c07dca2;
case 0x0c07dca4u: goto P_0c07dca4;
case 0x0c07dca6u: goto P_0c07dca6;
case 0x0c07dca8u: goto P_0c07dca8;
case 0x0c07dcaau: goto P_0c07dcaa;
case 0x0c07dcacu: goto P_0c07dcac;
case 0x0c07dcaeu: goto P_0c07dcae;
case 0x0c07dcb0u: goto P_0c07dcb0;
case 0x0c07dcb2u: goto P_0c07dcb2;
case 0x0c07dcb4u: goto P_0c07dcb4;
case 0x0c07dcb6u: goto P_0c07dcb6;
case 0x0c07dcb8u: goto P_0c07dcb8;
case 0x0c07dcbau: goto P_0c07dcba;
case 0x0c07dcbcu: goto P_0c07dcbc;
case 0x0c07dcbeu: goto P_0c07dcbe;
case 0x0c07dcc0u: goto P_0c07dcc0;
case 0x0c07dcc2u: goto P_0c07dcc2;
case 0x0c07dcc4u: goto P_0c07dcc4;
case 0x0c07dcc6u: goto P_0c07dcc6;
case 0x0c07dcc8u: goto P_0c07dcc8;
case 0x0c07dccau: goto P_0c07dcca;
case 0x0c07dcccu: goto P_0c07dccc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07c534: /* original 2fe6, guest PC 0x0c07c534 */
if(!s->budget--) { s->failed_pc=0x0c07c534u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c536;
P_0c07c536: /* original 2fd6, guest PC 0x0c07c536 */
if(!s->budget--) { s->failed_pc=0x0c07c536u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c538;
P_0c07c538: /* original 2fc6, guest PC 0x0c07c538 */
if(!s->budget--) { s->failed_pc=0x0c07c538u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c53a;
P_0c07c53a: /* original 2fb6, guest PC 0x0c07c53a */
if(!s->budget--) { s->failed_pc=0x0c07c53au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c53c;
P_0c07c53c: /* original 2fa6, guest PC 0x0c07c53c */
if(!s->budget--) { s->failed_pc=0x0c07c53cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c53e;
P_0c07c53e: /* original 2f96, guest PC 0x0c07c53e */
if(!s->budget--) { s->failed_pc=0x0c07c53eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c540;
P_0c07c540: /* original 4f22, guest PC 0x0c07c540 */
if(!s->budget--) { s->failed_pc=0x0c07c540u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07c542;
P_0c07c542: /* original 7ff0, guest PC 0x0c07c542 */
if(!s->budget--) { s->failed_pc=0x0c07c542u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c07c544;
P_0c07c544: /* original 2f42, guest PC 0x0c07c544 */
if(!s->budget--) { s->failed_pc=0x0c07c544u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07c546;
P_0c07c546: /* original 1f53, guest PC 0x0c07c546 */
if(!s->budget--) { s->failed_pc=0x0c07c546u; return 0; }
write(ram,r[15]+12,r[5],4);
goto P_0c07c548;
P_0c07c548: /* original d34a, guest PC 0x0c07c548 */
if(!s->budget--) { s->failed_pc=0x0c07c548u; return 0; }
r[3]=read(ram,0x0c07c674u,4);
goto P_0c07c54a;
P_0c07c54a: /* original 1f32, guest PC 0x0c07c54a */
if(!s->budget--) { s->failed_pc=0x0c07c54au; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07c54c;
P_0c07c54c: /* original 62f2, guest PC 0x0c07c54c */
if(!s->budget--) { s->failed_pc=0x0c07c54cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07c54e;
P_0c07c54e: /* original 1f21, guest PC 0x0c07c54e */
if(!s->budget--) { s->failed_pc=0x0c07c54eu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c07c550;
P_0c07c550: /* original d349, guest PC 0x0c07c550 */
if(!s->budget--) { s->failed_pc=0x0c07c550u; return 0; }
r[3]=read(ram,0x0c07c678u,4);
goto P_0c07c552;
P_0c07c552: /* original 430b, guest PC 0x0c07c552 */
if(!s->budget--) { s->failed_pc=0x0c07c552u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c556u;
r[4]=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c556u) { target=s->pc; goto dispatch; }
goto P_0c07c556;
P_0c07c554: /* original e40a, guest PC 0x0c07c554 */
if(!s->budget--) { s->failed_pc=0x0c07c554u; return 0; }
r[4]=0x0000000au;
goto P_0c07c556;
P_0c07c556: /* original d248, guest PC 0x0c07c556 */
if(!s->budget--) { s->failed_pc=0x0c07c556u; return 0; }
r[2]=read(ram,0x0c07c678u,4);
goto P_0c07c558;
P_0c07c558: /* original 420b, guest PC 0x0c07c558 */
if(!s->budget--) { s->failed_pc=0x0c07c558u; return 0; }
target=r[2];
r[16]=code_base|0x0c07c55cu;
r[4]=0x0000000bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c55cu) { target=s->pc; goto dispatch; }
goto P_0c07c55c;
P_0c07c55a: /* original e40b, guest PC 0x0c07c55a */
if(!s->budget--) { s->failed_pc=0x0c07c55au; return 0; }
r[4]=0x0000000bu;
goto P_0c07c55c;
P_0c07c55c: /* original de47, guest PC 0x0c07c55c */
if(!s->budget--) { s->failed_pc=0x0c07c55cu; return 0; }
r[14]=read(ram,0x0c07c67cu,4);
goto P_0c07c55e;
P_0c07c55e: /* original 54f2, guest PC 0x0c07c55e */
if(!s->budget--) { s->failed_pc=0x0c07c55eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07c560;
P_0c07c560: /* original d347, guest PC 0x0c07c560 */
if(!s->budget--) { s->failed_pc=0x0c07c560u; return 0; }
r[3]=read(ram,0x0c07c680u,4);
goto P_0c07c562;
P_0c07c562: /* original 6de3, guest PC 0x0c07c562 */
if(!s->budget--) { s->failed_pc=0x0c07c562u; return 0; }
r[13]=r[14];
goto P_0c07c564;
P_0c07c564: /* original 6ae3, guest PC 0x0c07c564 */
if(!s->budget--) { s->failed_pc=0x0c07c564u; return 0; }
r[10]=r[14];
goto P_0c07c566;
P_0c07c566: /* original 7d58, guest PC 0x0c07c566 */
if(!s->budget--) { s->failed_pc=0x0c07c566u; return 0; }
r[13]+=0x00000058u;
goto P_0c07c568;
P_0c07c568: /* original 430b, guest PC 0x0c07c568 */
if(!s->budget--) { s->failed_pc=0x0c07c568u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c56cu;
r[4]+=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c56cu) { target=s->pc; goto dispatch; }
goto P_0c07c56c;
P_0c07c56a: /* original 7412, guest PC 0x0c07c56a */
if(!s->budget--) { s->failed_pc=0x0c07c56au; return 0; }
r[4]+=0x00000012u;
goto P_0c07c56c;
P_0c07c56c: /* original dc45, guest PC 0x0c07c56c */
if(!s->budget--) { s->failed_pc=0x0c07c56cu; return 0; }
r[12]=read(ram,0x0c07c684u,4);
goto P_0c07c56e;
P_0c07c56e: /* original 84c9, guest PC 0x0c07c56e */
if(!s->budget--) { s->failed_pc=0x0c07c56eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+9,1);
goto P_0c07c570;
P_0c07c570: /* original 600c, guest PC 0x0c07c570 */
if(!s->budget--) { s->failed_pc=0x0c07c570u; return 0; }
r[0]=r[0]&255u;
goto P_0c07c572;
P_0c07c572: /* original 8802, guest PC 0x0c07c572 */
if(!s->budget--) { s->failed_pc=0x0c07c572u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c07c574;
P_0c07c574: /* original 8f26, guest PC 0x0c07c574 */
if(!s->budget--) { s->failed_pc=0x0c07c574u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c07c5c4; }
goto P_0c07c578;
P_0c07c576: /* original 6403, guest PC 0x0c07c576 */
if(!s->budget--) { s->failed_pc=0x0c07c576u; return 0; }
r[4]=r[0];
goto P_0c07c578;
P_0c07c578: /* original e900, guest PC 0x0c07c578 */
if(!s->budget--) { s->failed_pc=0x0c07c578u; return 0; }
r[9]=0x00000000u;
goto P_0c07c57a;
P_0c07c57a: /* original 66d3, guest PC 0x0c07c57a */
if(!s->budget--) { s->failed_pc=0x0c07c57au; return 0; }
r[6]=r[13];
goto P_0c07c57c;
P_0c07c57c: /* original e23f, guest PC 0x0c07c57c */
if(!s->budget--) { s->failed_pc=0x0c07c57cu; return 0; }
r[2]=0x0000003fu;
goto P_0c07c57e;
P_0c07c57e: /* original 1c96, guest PC 0x0c07c57e */
if(!s->budget--) { s->failed_pc=0x0c07c57eu; return 0; }
write(ram,r[12]+24,r[9],4);
goto P_0c07c580;
P_0c07c580: /* original 9070, guest PC 0x0c07c580 */
if(!s->budget--) { s->failed_pc=0x0c07c580u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c664u,2);
goto P_0c07c582;
P_0c07c582: /* original 0e26, guest PC 0x0c07c582 */
if(!s->budget--) { s->failed_pc=0x0c07c582u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c07c584;
P_0c07c584: /* original 946f, guest PC 0x0c07c584 */
if(!s->budget--) { s->failed_pc=0x0c07c584u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c666u,2);
goto P_0c07c586;
P_0c07c586: /* original d340, guest PC 0x0c07c586 */
if(!s->budget--) { s->failed_pc=0x0c07c586u; return 0; }
r[3]=read(ram,0x0c07c688u,4);
goto P_0c07c588;
P_0c07c588: /* original 430b, guest PC 0x0c07c588 */
if(!s->budget--) { s->failed_pc=0x0c07c588u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c58cu;
r[5]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c58cu) { target=s->pc; goto dispatch; }
goto P_0c07c58c;
P_0c07c58a: /* original 65a3, guest PC 0x0c07c58a */
if(!s->budget--) { s->failed_pc=0x0c07c58au; return 0; }
r[5]=r[10];
goto P_0c07c58c;
P_0c07c58c: /* original db3f, guest PC 0x0c07c58c */
if(!s->budget--) { s->failed_pc=0x0c07c58cu; return 0; }
r[11]=read(ram,0x0c07c68cu,4);
goto P_0c07c58e;
P_0c07c58e: /* original 4b0b, guest PC 0x0c07c58e */
if(!s->budget--) { s->failed_pc=0x0c07c58eu; return 0; }
target=r[11];
r[16]=code_base|0x0c07c592u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c592u) { target=s->pc; goto dispatch; }
goto P_0c07c592;
P_0c07c590: /* original 64a3, guest PC 0x0c07c590 */
if(!s->budget--) { s->failed_pc=0x0c07c590u; return 0; }
r[4]=r[10];
goto P_0c07c592;
P_0c07c592: /* original 4b0b, guest PC 0x0c07c592 */
if(!s->budget--) { s->failed_pc=0x0c07c592u; return 0; }
target=r[11];
r[16]=code_base|0x0c07c596u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c596u) { target=s->pc; goto dispatch; }
goto P_0c07c596;
P_0c07c594: /* original 64d3, guest PC 0x0c07c594 */
if(!s->budget--) { s->failed_pc=0x0c07c594u; return 0; }
r[4]=r[13];
goto P_0c07c596;
P_0c07c596: /* original 64e3, guest PC 0x0c07c596 */
if(!s->budget--) { s->failed_pc=0x0c07c596u; return 0; }
r[4]=r[14];
goto P_0c07c598;
P_0c07c598: /* original 4b0b, guest PC 0x0c07c598 */
if(!s->budget--) { s->failed_pc=0x0c07c598u; return 0; }
target=r[11];
r[16]=code_base|0x0c07c59cu;
r[4]+=0x0000002cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c59cu) { target=s->pc; goto dispatch; }
goto P_0c07c59c;
P_0c07c59a: /* original 742c, guest PC 0x0c07c59a */
if(!s->budget--) { s->failed_pc=0x0c07c59au; return 0; }
r[4]+=0x0000002cu;
goto P_0c07c59c;
P_0c07c59c: /* original 9464, guest PC 0x0c07c59c */
if(!s->budget--) { s->failed_pc=0x0c07c59cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c668u,2);
goto P_0c07c59e;
P_0c07c59e: /* original 4b0b, guest PC 0x0c07c59e */
if(!s->budget--) { s->failed_pc=0x0c07c59eu; return 0; }
target=r[11];
r[16]=code_base|0x0c07c5a2u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c5a2u) { target=s->pc; goto dispatch; }
goto P_0c07c5a2;
P_0c07c5a0: /* original 34ec, guest PC 0x0c07c5a0 */
if(!s->budget--) { s->failed_pc=0x0c07c5a0u; return 0; }
r[4]+=r[14];
goto P_0c07c5a2;
P_0c07c5a2: /* original de3b, guest PC 0x0c07c5a2 */
if(!s->budget--) { s->failed_pc=0x0c07c5a2u; return 0; }
r[14]=read(ram,0x0c07c690u,4);
goto P_0c07c5a4;
P_0c07c5a4: /* original d23b, guest PC 0x0c07c5a4 */
if(!s->budget--) { s->failed_pc=0x0c07c5a4u; return 0; }
r[2]=read(ram,0x0c07c694u,4);
goto P_0c07c5a6;
P_0c07c5a6: /* original 65e3, guest PC 0x0c07c5a6 */
if(!s->budget--) { s->failed_pc=0x0c07c5a6u; return 0; }
r[5]=r[14];
goto P_0c07c5a8;
P_0c07c5a8: /* original 66e3, guest PC 0x0c07c5a8 */
if(!s->budget--) { s->failed_pc=0x0c07c5a8u; return 0; }
r[6]=r[14];
goto P_0c07c5aa;
P_0c07c5aa: /* original 420b, guest PC 0x0c07c5aa */
if(!s->budget--) { s->failed_pc=0x0c07c5aau; return 0; }
target=r[2];
r[16]=code_base|0x0c07c5aeu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c5aeu) { target=s->pc; goto dispatch; }
goto P_0c07c5ae;
P_0c07c5ac: /* original 64e3, guest PC 0x0c07c5ac */
if(!s->budget--) { s->failed_pc=0x0c07c5acu; return 0; }
r[4]=r[14];
goto P_0c07c5ae;
P_0c07c5ae: /* original 1f93, guest PC 0x0c07c5ae */
if(!s->budget--) { s->failed_pc=0x0c07c5aeu; return 0; }
write(ram,r[15]+12,r[9],4);
goto P_0c07c5b0;
P_0c07c5b0: /* original e301, guest PC 0x0c07c5b0 */
if(!s->budget--) { s->failed_pc=0x0c07c5b0u; return 0; }
r[3]=0x00000001u;
goto P_0c07c5b2;
P_0c07c5b2: /* original 66d3, guest PC 0x0c07c5b2 */
if(!s->budget--) { s->failed_pc=0x0c07c5b2u; return 0; }
r[6]=r[13];
goto P_0c07c5b4;
P_0c07c5b4: /* original 2f36, guest PC 0x0c07c5b4 */
if(!s->budget--) { s->failed_pc=0x0c07c5b4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c5b6;
P_0c07c5b6: /* original d238, guest PC 0x0c07c5b6 */
if(!s->budget--) { s->failed_pc=0x0c07c5b6u; return 0; }
r[2]=read(ram,0x0c07c698u,4);
goto P_0c07c5b8;
P_0c07c5b8: /* original 6793, guest PC 0x0c07c5b8 */
if(!s->budget--) { s->failed_pc=0x0c07c5b8u; return 0; }
r[7]=r[9];
goto P_0c07c5ba;
P_0c07c5ba: /* original 9556, guest PC 0x0c07c5ba */
if(!s->budget--) { s->failed_pc=0x0c07c5bau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c66au,2);
goto P_0c07c5bc;
P_0c07c5bc: /* original 420b, guest PC 0x0c07c5bc */
if(!s->budget--) { s->failed_pc=0x0c07c5bcu; return 0; }
target=r[2];
r[16]=code_base|0x0c07c5c0u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c5c0u) { target=s->pc; goto dispatch; }
goto P_0c07c5c0;
P_0c07c5be: /* original 6493, guest PC 0x0c07c5be */
if(!s->budget--) { s->failed_pc=0x0c07c5beu; return 0; }
r[4]=r[9];
goto P_0c07c5c0;
P_0c07c5c0: /* original 1c95, guest PC 0x0c07c5c0 */
if(!s->budget--) { s->failed_pc=0x0c07c5c0u; return 0; }
write(ram,r[12]+20,r[9],4);
goto P_0c07c5c2;
P_0c07c5c2: /* original 7f04, guest PC 0x0c07c5c2 */
if(!s->budget--) { s->failed_pc=0x0c07c5c2u; return 0; }
r[15]+=0x00000004u;
goto P_0c07c5c4;
P_0c07c5c4: /* original 53f1, guest PC 0x0c07c5c4 */
if(!s->budget--) { s->failed_pc=0x0c07c5c4u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07c5c6;
P_0c07c5c6: /* original e010, guest PC 0x0c07c5c6 */
if(!s->budget--) { s->failed_pc=0x0c07c5c6u; return 0; }
r[0]=0x00000010u;
goto P_0c07c5c8;
P_0c07c5c8: /* original d234, guest PC 0x0c07c5c8 */
if(!s->budget--) { s->failed_pc=0x0c07c5c8u; return 0; }
r[2]=read(ram,0x0c07c69cu,4);
goto P_0c07c5ca;
P_0c07c5ca: /* original 1324, guest PC 0x0c07c5ca */
if(!s->budget--) { s->failed_pc=0x0c07c5cau; return 0; }
write(ram,r[3]+16,r[2],4);
goto P_0c07c5cc;
P_0c07c5cc: /* original 03cc, guest PC 0x0c07c5cc */
if(!s->budget--) { s->failed_pc=0x0c07c5ccu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c07c5ce;
P_0c07c5ce: /* original 7301, guest PC 0x0c07c5ce */
if(!s->budget--) { s->failed_pc=0x0c07c5ceu; return 0; }
r[3]+=0x00000001u;
goto P_0c07c5d0;
P_0c07c5d0: /* original 0c34, guest PC 0x0c07c5d0 */
if(!s->budget--) { s->failed_pc=0x0c07c5d0u; return 0; }
write(ram,r[12]+r[0],r[3],1);
goto P_0c07c5d2;
P_0c07c5d2: /* original 55f3, guest PC 0x0c07c5d2 */
if(!s->budget--) { s->failed_pc=0x0c07c5d2u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c07c5d4;
P_0c07c5d4: /* original 64f2, guest PC 0x0c07c5d4 */
if(!s->budget--) { s->failed_pc=0x0c07c5d4u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07c5d6;
P_0c07c5d6: /* original 7f10, guest PC 0x0c07c5d6 */
if(!s->budget--) { s->failed_pc=0x0c07c5d6u; return 0; }
r[15]+=0x00000010u;
goto P_0c07c5d8;
P_0c07c5d8: /* original 4f26, guest PC 0x0c07c5d8 */
if(!s->budget--) { s->failed_pc=0x0c07c5d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07c5da;
P_0c07c5da: /* original 69f6, guest PC 0x0c07c5da */
if(!s->budget--) { s->failed_pc=0x0c07c5dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07c5dc;
P_0c07c5dc: /* original 6af6, guest PC 0x0c07c5dc */
if(!s->budget--) { s->failed_pc=0x0c07c5dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07c5de;
P_0c07c5de: /* original 6bf6, guest PC 0x0c07c5de */
if(!s->budget--) { s->failed_pc=0x0c07c5deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07c5e0;
P_0c07c5e0: /* original 6cf6, guest PC 0x0c07c5e0 */
if(!s->budget--) { s->failed_pc=0x0c07c5e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07c5e2;
P_0c07c5e2: /* original 6df6, guest PC 0x0c07c5e2 */
if(!s->budget--) { s->failed_pc=0x0c07c5e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07c5e4;
P_0c07c5e4: /* original aa20, guest PC 0x0c07c5e4 */
if(!s->budget--) { s->failed_pc=0x0c07c5e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07ba28u,s,ram);
P_0c07c5e6: /* original 6ef6, guest PC 0x0c07c5e6 */
if(!s->budget--) { s->failed_pc=0x0c07c5e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07c5e8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07c5e8u; return 0; } return 1;
P_0c07c6ac: /* original 2fe6, guest PC 0x0c07c6ac */
if(!s->budget--) { s->failed_pc=0x0c07c6acu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c6ae;
P_0c07c6ae: /* original 2fd6, guest PC 0x0c07c6ae */
if(!s->budget--) { s->failed_pc=0x0c07c6aeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c6b0;
P_0c07c6b0: /* original 6d43, guest PC 0x0c07c6b0 */
if(!s->budget--) { s->failed_pc=0x0c07c6b0u; return 0; }
r[13]=r[4];
goto P_0c07c6b2;
P_0c07c6b2: /* original 2fc6, guest PC 0x0c07c6b2 */
if(!s->budget--) { s->failed_pc=0x0c07c6b2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c6b4;
P_0c07c6b4: /* original 2fb6, guest PC 0x0c07c6b4 */
if(!s->budget--) { s->failed_pc=0x0c07c6b4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c6b6;
P_0c07c6b6: /* original 4f22, guest PC 0x0c07c6b6 */
if(!s->budget--) { s->failed_pc=0x0c07c6b6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07c6b8;
P_0c07c6b8: /* original 7ffc, guest PC 0x0c07c6b8 */
if(!s->budget--) { s->failed_pc=0x0c07c6b8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07c6ba;
P_0c07c6ba: /* original 2f42, guest PC 0x0c07c6ba */
if(!s->budget--) { s->failed_pc=0x0c07c6bau; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07c6bc;
P_0c07c6bc: /* original d349, guest PC 0x0c07c6bc */
if(!s->budget--) { s->failed_pc=0x0c07c6bcu; return 0; }
r[3]=read(ram,0x0c07c7e4u,4);
goto P_0c07c6be;
P_0c07c6be: /* original 9488, guest PC 0x0c07c6be */
if(!s->budget--) { s->failed_pc=0x0c07c6beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c7d2u,2);
goto P_0c07c6c0;
P_0c07c6c0: /* original 430b, guest PC 0x0c07c6c0 */
if(!s->budget--) { s->failed_pc=0x0c07c6c0u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c6c4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c6c4u) { target=s->pc; goto dispatch; }
goto P_0c07c6c4;
P_0c07c6c2: /* original 0009, guest PC 0x0c07c6c2 */
if(!s->budget--) { s->failed_pc=0x0c07c6c2u; return 0; }
goto P_0c07c6c4;
P_0c07c6c4: /* original de48, guest PC 0x0c07c6c4 */
if(!s->budget--) { s->failed_pc=0x0c07c6c4u; return 0; }
r[14]=read(ram,0x0c07c7e8u,4);
goto P_0c07c6c6;
P_0c07c6c6: /* original e200, guest PC 0x0c07c6c6 */
if(!s->budget--) { s->failed_pc=0x0c07c6c6u; return 0; }
r[2]=0x00000000u;
goto P_0c07c6c8;
P_0c07c6c8: /* original 1e26, guest PC 0x0c07c6c8 */
if(!s->budget--) { s->failed_pc=0x0c07c6c8u; return 0; }
write(ram,r[14]+24,r[2],4);
goto P_0c07c6ca;
P_0c07c6ca: /* original d249, guest PC 0x0c07c6ca */
if(!s->budget--) { s->failed_pc=0x0c07c6cau; return 0; }
r[2]=read(ram,0x0c07c7f0u,4);
goto P_0c07c6cc;
P_0c07c6cc: /* original 9482, guest PC 0x0c07c6cc */
if(!s->budget--) { s->failed_pc=0x0c07c6ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c7d4u,2);
goto P_0c07c6ce;
P_0c07c6ce: /* original d347, guest PC 0x0c07c6ce */
if(!s->budget--) { s->failed_pc=0x0c07c6ceu; return 0; }
r[3]=read(ram,0x0c07c7ecu,4);
goto P_0c07c6d0;
P_0c07c6d0: /* original 420b, guest PC 0x0c07c6d0 */
if(!s->budget--) { s->failed_pc=0x0c07c6d0u; return 0; }
target=r[2];
r[16]=code_base|0x0c07c6d4u;
write(ram,r[13]+16,r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c6d4u) { target=s->pc; goto dispatch; }
goto P_0c07c6d4;
P_0c07c6d2: /* original 1d34, guest PC 0x0c07c6d2 */
if(!s->budget--) { s->failed_pc=0x0c07c6d2u; return 0; }
write(ram,r[13]+16,r[3],4);
goto P_0c07c6d4;
P_0c07c6d4: /* original d348, guest PC 0x0c07c6d4 */
if(!s->budget--) { s->failed_pc=0x0c07c6d4u; return 0; }
r[3]=read(ram,0x0c07c7f8u,4);
goto P_0c07c6d6;
P_0c07c6d6: /* original db47, guest PC 0x0c07c6d6 */
if(!s->budget--) { s->failed_pc=0x0c07c6d6u; return 0; }
r[11]=read(ram,0x0c07c7f4u,4);
goto P_0c07c6d8;
P_0c07c6d8: /* original 430b, guest PC 0x0c07c6d8 */
if(!s->budget--) { s->failed_pc=0x0c07c6d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c6dcu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c6dcu) { target=s->pc; goto dispatch; }
goto P_0c07c6dc;
P_0c07c6da: /* original 64b3, guest PC 0x0c07c6da */
if(!s->budget--) { s->failed_pc=0x0c07c6dau; return 0; }
r[4]=r[11];
goto P_0c07c6dc;
P_0c07c6dc: /* original d246, guest PC 0x0c07c6dc */
if(!s->budget--) { s->failed_pc=0x0c07c6dcu; return 0; }
r[2]=read(ram,0x0c07c7f8u,4);
goto P_0c07c6de;
P_0c07c6de: /* original 64b3, guest PC 0x0c07c6de */
if(!s->budget--) { s->failed_pc=0x0c07c6deu; return 0; }
r[4]=r[11];
goto P_0c07c6e0;
P_0c07c6e0: /* original 420b, guest PC 0x0c07c6e0 */
if(!s->budget--) { s->failed_pc=0x0c07c6e0u; return 0; }
target=r[2];
r[16]=code_base|0x0c07c6e4u;
r[4]+=0x00000058u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c6e4u) { target=s->pc; goto dispatch; }
goto P_0c07c6e4;
P_0c07c6e2: /* original 7458, guest PC 0x0c07c6e2 */
if(!s->budget--) { s->failed_pc=0x0c07c6e2u; return 0; }
r[4]+=0x00000058u;
goto P_0c07c6e4;
P_0c07c6e4: /* original d345, guest PC 0x0c07c6e4 */
if(!s->budget--) { s->failed_pc=0x0c07c6e4u; return 0; }
r[3]=read(ram,0x0c07c7fcu,4);
goto P_0c07c6e6;
P_0c07c6e6: /* original 430b, guest PC 0x0c07c6e6 */
if(!s->budget--) { s->failed_pc=0x0c07c6e6u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c6eau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c6eau) { target=s->pc; goto dispatch; }
goto P_0c07c6ea;
P_0c07c6e8: /* original 0009, guest PC 0x0c07c6e8 */
if(!s->budget--) { s->failed_pc=0x0c07c6e8u; return 0; }
goto P_0c07c6ea;
P_0c07c6ea: /* original e210, guest PC 0x0c07c6ea */
if(!s->budget--) { s->failed_pc=0x0c07c6eau; return 0; }
r[2]=0x00000010u;
goto P_0c07c6ec;
P_0c07c6ec: /* original 66b3, guest PC 0x0c07c6ec */
if(!s->budget--) { s->failed_pc=0x0c07c6ecu; return 0; }
r[6]=r[11];
goto P_0c07c6ee;
P_0c07c6ee: /* original 1e25, guest PC 0x0c07c6ee */
if(!s->budget--) { s->failed_pc=0x0c07c6eeu; return 0; }
write(ram,r[14]+20,r[2],4);
goto P_0c07c6f0;
P_0c07c6f0: /* original e300, guest PC 0x0c07c6f0 */
if(!s->budget--) { s->failed_pc=0x0c07c6f0u; return 0; }
r[3]=0x00000000u;
goto P_0c07c6f2;
P_0c07c6f2: /* original 9c70, guest PC 0x0c07c6f2 */
if(!s->budget--) { s->failed_pc=0x0c07c6f2u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c7d6u,2);
goto P_0c07c6f4;
P_0c07c6f4: /* original 6733, guest PC 0x0c07c6f4 */
if(!s->budget--) { s->failed_pc=0x0c07c6f4u; return 0; }
r[7]=r[3];
goto P_0c07c6f6;
P_0c07c6f6: /* original 2f36, guest PC 0x0c07c6f6 */
if(!s->budget--) { s->failed_pc=0x0c07c6f6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c6f8;
P_0c07c6f8: /* original d241, guest PC 0x0c07c6f8 */
if(!s->budget--) { s->failed_pc=0x0c07c6f8u; return 0; }
r[2]=read(ram,0x0c07c800u,4);
goto P_0c07c6fa;
P_0c07c6fa: /* original 956d, guest PC 0x0c07c6fa */
if(!s->budget--) { s->failed_pc=0x0c07c6fau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c7d8u,2);
goto P_0c07c6fc;
P_0c07c6fc: /* original 420b, guest PC 0x0c07c6fc */
if(!s->budget--) { s->failed_pc=0x0c07c6fcu; return 0; }
target=r[2];
r[16]=code_base|0x0c07c700u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c700u) { target=s->pc; goto dispatch; }
goto P_0c07c700;
P_0c07c6fe: /* original 64c3, guest PC 0x0c07c6fe */
if(!s->budget--) { s->failed_pc=0x0c07c6feu; return 0; }
r[4]=r[12];
goto P_0c07c700;
P_0c07c700: /* original e010, guest PC 0x0c07c700 */
if(!s->budget--) { s->failed_pc=0x0c07c700u; return 0; }
r[0]=0x00000010u;
goto P_0c07c702;
P_0c07c702: /* original 65c3, guest PC 0x0c07c702 */
if(!s->budget--) { s->failed_pc=0x0c07c702u; return 0; }
r[5]=r[12];
goto P_0c07c704;
P_0c07c704: /* original 03ec, guest PC 0x0c07c704 */
if(!s->budget--) { s->failed_pc=0x0c07c704u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07c706;
P_0c07c706: /* original e240, guest PC 0x0c07c706 */
if(!s->budget--) { s->failed_pc=0x0c07c706u; return 0; }
r[2]=0x00000040u;
goto P_0c07c708;
P_0c07c708: /* original 7301, guest PC 0x0c07c708 */
if(!s->budget--) { s->failed_pc=0x0c07c708u; return 0; }
r[3]+=0x00000001u;
goto P_0c07c70a;
P_0c07c70a: /* original 0e34, guest PC 0x0c07c70a */
if(!s->budget--) { s->failed_pc=0x0c07c70au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c07c70c;
P_0c07c70c: /* original 9065, guest PC 0x0c07c70c */
if(!s->budget--) { s->failed_pc=0x0c07c70cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c7dau,2);
goto P_0c07c70e;
P_0c07c70e: /* original 0d26, guest PC 0x0c07c70e */
if(!s->budget--) { s->failed_pc=0x0c07c70eu; return 0; }
write(ram,r[13]+r[0],r[2],4);
goto P_0c07c710;
P_0c07c710: /* original 54f1, guest PC 0x0c07c710 */
if(!s->budget--) { s->failed_pc=0x0c07c710u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07c712;
P_0c07c712: /* original 7f08, guest PC 0x0c07c712 */
if(!s->budget--) { s->failed_pc=0x0c07c712u; return 0; }
r[15]+=0x00000008u;
goto P_0c07c714;
P_0c07c714: /* original 4f26, guest PC 0x0c07c714 */
if(!s->budget--) { s->failed_pc=0x0c07c714u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07c716;
P_0c07c716: /* original 6bf6, guest PC 0x0c07c716 */
if(!s->budget--) { s->failed_pc=0x0c07c716u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07c718;
P_0c07c718: /* original 6cf6, guest PC 0x0c07c718 */
if(!s->budget--) { s->failed_pc=0x0c07c718u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07c71a;
P_0c07c71a: /* original 6df6, guest PC 0x0c07c71a */
if(!s->budget--) { s->failed_pc=0x0c07c71au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07c71c;
P_0c07c71c: /* original a000, guest PC 0x0c07c71c */
if(!s->budget--) { s->failed_pc=0x0c07c71cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07c720;
P_0c07c71e: /* original 6ef6, guest PC 0x0c07c71e */
if(!s->budget--) { s->failed_pc=0x0c07c71eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07c720;
P_0c07c720: /* original 2fe6, guest PC 0x0c07c720 */
if(!s->budget--) { s->failed_pc=0x0c07c720u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c722;
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c74cu) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c760u) { target=s->pc; goto dispatch; }
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
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c766u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c07ba28u,s,ram);
P_0c07c770: /* original 6ef6, guest PC 0x0c07c770 */
if(!s->budget--) { s->failed_pc=0x0c07c770u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07c772u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07c772u; return 0; } return 1;
P_0c07d948: /* original 2fe6, guest PC 0x0c07d948 */
if(!s->budget--) { s->failed_pc=0x0c07d948u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07d94a;
P_0c07d94a: /* original 2fd6, guest PC 0x0c07d94a */
if(!s->budget--) { s->failed_pc=0x0c07d94au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07d94c;
P_0c07d94c: /* original 2fc6, guest PC 0x0c07d94c */
if(!s->budget--) { s->failed_pc=0x0c07d94cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07d94e;
P_0c07d94e: /* original 2fb6, guest PC 0x0c07d94e */
if(!s->budget--) { s->failed_pc=0x0c07d94eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07d950;
P_0c07d950: /* original 2fa6, guest PC 0x0c07d950 */
if(!s->budget--) { s->failed_pc=0x0c07d950u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07d952;
P_0c07d952: /* original ea00, guest PC 0x0c07d952 */
if(!s->budget--) { s->failed_pc=0x0c07d952u; return 0; }
r[10]=0x00000000u;
goto P_0c07d954;
P_0c07d954: /* original 2f96, guest PC 0x0c07d954 */
if(!s->budget--) { s->failed_pc=0x0c07d954u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07d956;
P_0c07d956: /* original 66a3, guest PC 0x0c07d956 */
if(!s->budget--) { s->failed_pc=0x0c07d956u; return 0; }
r[6]=r[10];
goto P_0c07d958;
P_0c07d958: /* original 2f86, guest PC 0x0c07d958 */
if(!s->budget--) { s->failed_pc=0x0c07d958u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07d95a;
P_0c07d95a: /* original 4f22, guest PC 0x0c07d95a */
if(!s->budget--) { s->failed_pc=0x0c07d95au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07d95c;
P_0c07d95c: /* original dd21, guest PC 0x0c07d95c */
if(!s->budget--) { s->failed_pc=0x0c07d95cu; return 0; }
r[13]=read(ram,0x0c07d9e4u,4);
goto P_0c07d95e;
P_0c07d95e: /* original 7fd8, guest PC 0x0c07d95e */
if(!s->budget--) { s->failed_pc=0x0c07d95eu; return 0; }
r[15]+=0xffffffd8u;
goto P_0c07d960;
P_0c07d960: /* original 69f3, guest PC 0x0c07d960 */
if(!s->budget--) { s->failed_pc=0x0c07d960u; return 0; }
r[9]=r[15];
goto P_0c07d962;
P_0c07d962: /* original 791c, guest PC 0x0c07d962 */
if(!s->budget--) { s->failed_pc=0x0c07d962u; return 0; }
r[9]+=0x0000001cu;
goto P_0c07d964;
P_0c07d964: /* original 1f44, guest PC 0x0c07d964 */
if(!s->budget--) { s->failed_pc=0x0c07d964u; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c07d966;
P_0c07d966: /* original 1f56, guest PC 0x0c07d966 */
if(!s->budget--) { s->failed_pc=0x0c07d966u; return 0; }
write(ram,r[15]+24,r[5],4);
goto P_0c07d968;
P_0c07d968: /* original 65a3, guest PC 0x0c07d968 */
if(!s->budget--) { s->failed_pc=0x0c07d968u; return 0; }
r[5]=r[10];
goto P_0c07d96a;
P_0c07d96a: /* original d31f, guest PC 0x0c07d96a */
if(!s->budget--) { s->failed_pc=0x0c07d96au; return 0; }
r[3]=read(ram,0x0c07d9e8u,4);
goto P_0c07d96c;
P_0c07d96c: /* original 430b, guest PC 0x0c07d96c */
if(!s->budget--) { s->failed_pc=0x0c07d96cu; return 0; }
target=r[3];
r[16]=code_base|0x0c07d970u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07d970u) { target=s->pc; goto dispatch; }
goto P_0c07d970;
P_0c07d96e: /* original 64a3, guest PC 0x0c07d96e */
if(!s->budget--) { s->failed_pc=0x0c07d96eu; return 0; }
r[4]=r[10];
goto P_0c07d970;
P_0c07d970: /* original dc1e, guest PC 0x0c07d970 */
if(!s->budget--) { s->failed_pc=0x0c07d970u; return 0; }
r[12]=read(ram,0x0c07d9ecu,4);
goto P_0c07d972;
P_0c07d972: /* original d31f, guest PC 0x0c07d972 */
if(!s->budget--) { s->failed_pc=0x0c07d972u; return 0; }
r[3]=read(ram,0x0c07d9f0u,4);
goto P_0c07d974;
P_0c07d974: /* original 68c3, guest PC 0x0c07d974 */
if(!s->budget--) { s->failed_pc=0x0c07d974u; return 0; }
r[8]=r[12];
goto P_0c07d976;
P_0c07d976: /* original 5ef4, guest PC 0x0c07d976 */
if(!s->budget--) { s->failed_pc=0x0c07d976u; return 0; }
r[14]=read(ram,r[15]+16,4);
goto P_0c07d978;
P_0c07d978: /* original 7858, guest PC 0x0c07d978 */
if(!s->budget--) { s->failed_pc=0x0c07d978u; return 0; }
r[8]+=0x00000058u;
goto P_0c07d97a;
P_0c07d97a: /* original 6bc3, guest PC 0x0c07d97a */
if(!s->budget--) { s->failed_pc=0x0c07d97au; return 0; }
r[11]=r[12];
goto P_0c07d97c;
P_0c07d97c: /* original 23a2, guest PC 0x0c07d97c */
if(!s->budget--) { s->failed_pc=0x0c07d97cu; return 0; }
write(ram,r[3],r[10],4);
goto P_0c07d97e;
P_0c07d97e: /* original 6683, guest PC 0x0c07d97e */
if(!s->budget--) { s->failed_pc=0x0c07d97eu; return 0; }
r[6]=r[8];
goto P_0c07d980;
P_0c07d980: /* original d21c, guest PC 0x0c07d980 */
if(!s->budget--) { s->failed_pc=0x0c07d980u; return 0; }
r[2]=read(ram,0x0c07d9f4u,4);
goto P_0c07d982;
P_0c07d982: /* original 942b, guest PC 0x0c07d982 */
if(!s->budget--) { s->failed_pc=0x0c07d982u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07d9dcu,2);
goto P_0c07d984;
P_0c07d984: /* original 420b, guest PC 0x0c07d984 */
if(!s->budget--) { s->failed_pc=0x0c07d984u; return 0; }
target=r[2];
r[16]=code_base|0x0c07d988u;
r[5]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07d988u) { target=s->pc; goto dispatch; }
goto P_0c07d988;
P_0c07d986: /* original 65b3, guest PC 0x0c07d986 */
if(!s->budget--) { s->failed_pc=0x0c07d986u; return 0; }
r[5]=r[11];
goto P_0c07d988;
P_0c07d988: /* original d31b, guest PC 0x0c07d988 */
if(!s->budget--) { s->failed_pc=0x0c07d988u; return 0; }
r[3]=read(ram,0x0c07d9f8u,4);
goto P_0c07d98a;
P_0c07d98a: /* original 430b, guest PC 0x0c07d98a */
if(!s->budget--) { s->failed_pc=0x0c07d98au; return 0; }
target=r[3];
r[16]=code_base|0x0c07d98eu;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07d98eu) { target=s->pc; goto dispatch; }
goto P_0c07d98e;
P_0c07d98c: /* original 6483, guest PC 0x0c07d98c */
if(!s->budget--) { s->failed_pc=0x0c07d98cu; return 0; }
r[4]=r[8];
goto P_0c07d98e;
P_0c07d98e: /* original d21a, guest PC 0x0c07d98e */
if(!s->budget--) { s->failed_pc=0x0c07d98eu; return 0; }
r[2]=read(ram,0x0c07d9f8u,4);
goto P_0c07d990;
P_0c07d990: /* original 420b, guest PC 0x0c07d990 */
if(!s->budget--) { s->failed_pc=0x0c07d990u; return 0; }
target=r[2];
r[16]=code_base|0x0c07d994u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07d994u) { target=s->pc; goto dispatch; }
goto P_0c07d994;
P_0c07d992: /* original 64b3, guest PC 0x0c07d992 */
if(!s->budget--) { s->failed_pc=0x0c07d992u; return 0; }
r[4]=r[11];
goto P_0c07d994;
P_0c07d994: /* original 9423, guest PC 0x0c07d994 */
if(!s->budget--) { s->failed_pc=0x0c07d994u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07d9deu,2);
goto P_0c07d996;
P_0c07d996: /* original 65a3, guest PC 0x0c07d996 */
if(!s->budget--) { s->failed_pc=0x0c07d996u; return 0; }
r[5]=r[10];
goto P_0c07d998;
P_0c07d998: /* original d318, guest PC 0x0c07d998 */
if(!s->budget--) { s->failed_pc=0x0c07d998u; return 0; }
r[3]=read(ram,0x0c07d9fcu,4);
goto P_0c07d99a;
P_0c07d99a: /* original 67a3, guest PC 0x0c07d99a */
if(!s->budget--) { s->failed_pc=0x0c07d99au; return 0; }
r[7]=r[10];
goto P_0c07d99c;
P_0c07d99c: /* original 66a3, guest PC 0x0c07d99c */
if(!s->budget--) { s->failed_pc=0x0c07d99cu; return 0; }
r[6]=r[10];
goto P_0c07d99e;
P_0c07d99e: /* original 430b, guest PC 0x0c07d99e */
if(!s->budget--) { s->failed_pc=0x0c07d99eu; return 0; }
target=r[3];
r[16]=code_base|0x0c07d9a2u;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07d9a2u) { target=s->pc; goto dispatch; }
goto P_0c07d9a2;
P_0c07d9a0: /* original 34cc, guest PC 0x0c07d9a0 */
if(!s->budget--) { s->failed_pc=0x0c07d9a0u; return 0; }
r[4]+=r[12];
goto P_0c07d9a2;
P_0c07d9a2: /* original 941d, guest PC 0x0c07d9a2 */
if(!s->budget--) { s->failed_pc=0x0c07d9a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07d9e0u,2);
goto P_0c07d9a4;
P_0c07d9a4: /* original 65a3, guest PC 0x0c07d9a4 */
if(!s->budget--) { s->failed_pc=0x0c07d9a4u; return 0; }
r[5]=r[10];
goto P_0c07d9a6;
P_0c07d9a6: /* original d215, guest PC 0x0c07d9a6 */
if(!s->budget--) { s->failed_pc=0x0c07d9a6u; return 0; }
r[2]=read(ram,0x0c07d9fcu,4);
goto P_0c07d9a8;
P_0c07d9a8: /* original 67a3, guest PC 0x0c07d9a8 */
if(!s->budget--) { s->failed_pc=0x0c07d9a8u; return 0; }
r[7]=r[10];
goto P_0c07d9aa;
P_0c07d9aa: /* original 66a3, guest PC 0x0c07d9aa */
if(!s->budget--) { s->failed_pc=0x0c07d9aau; return 0; }
r[6]=r[10];
goto P_0c07d9ac;
P_0c07d9ac: /* original 420b, guest PC 0x0c07d9ac */
if(!s->budget--) { s->failed_pc=0x0c07d9acu; return 0; }
target=r[2];
r[16]=code_base|0x0c07d9b0u;
r[4]+=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07d9b0u) { target=s->pc; goto dispatch; }
goto P_0c07d9b0;
P_0c07d9ae: /* original 34cc, guest PC 0x0c07d9ae */
if(!s->budget--) { s->failed_pc=0x0c07d9aeu; return 0; }
r[4]+=r[12];
goto P_0c07d9b0;
P_0c07d9b0: /* original 9017, guest PC 0x0c07d9b0 */
if(!s->budget--) { s->failed_pc=0x0c07d9b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07d9e2u,2);
goto P_0c07d9b2;
P_0c07d9b2: /* original 6ca3, guest PC 0x0c07d9b2 */
if(!s->budget--) { s->failed_pc=0x0c07d9b2u; return 0; }
r[12]=r[10];
goto P_0c07d9b4;
P_0c07d9b4: /* original 00dc, guest PC 0x0c07d9b4 */
if(!s->budget--) { s->failed_pc=0x0c07d9b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07d9b6;
P_0c07d9b6: /* original 8802, guest PC 0x0c07d9b6 */
if(!s->budget--) { s->failed_pc=0x0c07d9b6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c07d9b8;
P_0c07d9b8: /* original 8d01, guest PC 0x0c07d9b8 */
if(!s->budget--) { s->failed_pc=0x0c07d9b8u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c07d9be; }
goto P_0c07d9bc;
P_0c07d9ba: /* original 6403, guest PC 0x0c07d9ba */
if(!s->budget--) { s->failed_pc=0x0c07d9bau; return 0; }
r[4]=r[0];
goto P_0c07d9bc;
P_0c07d9bc: /* original ec01, guest PC 0x0c07d9bc */
if(!s->budget--) { s->failed_pc=0x0c07d9bcu; return 0; }
r[12]=0x00000001u;
goto P_0c07d9be;
P_0c07d9be: /* original 54d2, guest PC 0x0c07d9be */
if(!s->budget--) { s->failed_pc=0x0c07d9beu; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c07d9c0;
P_0c07d9c0: /* original e204, guest PC 0x0c07d9c0 */
if(!s->budget--) { s->failed_pc=0x0c07d9c0u; return 0; }
r[2]=0x00000004u;
goto P_0c07d9c2;
P_0c07d9c2: /* original 2428, guest PC 0x0c07d9c2 */
if(!s->budget--) { s->failed_pc=0x0c07d9c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c07d9c4;
P_0c07d9c4: /* original 8925, guest PC 0x0c07d9c4 */
if(!s->budget--) { s->failed_pc=0x0c07d9c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07da12; }
goto P_0c07d9c6;
P_0c07d9c6: /* original e01c, guest PC 0x0c07d9c6 */
if(!s->budget--) { s->failed_pc=0x0c07d9c6u; return 0; }
r[0]=0x0000001cu;
goto P_0c07d9c8;
P_0c07d9c8: /* original 04dc, guest PC 0x0c07d9c8 */
if(!s->budget--) { s->failed_pc=0x0c07d9c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07d9ca;
P_0c07d9ca: /* original e102, guest PC 0x0c07d9ca */
if(!s->budget--) { s->failed_pc=0x0c07d9cau; return 0; }
r[1]=0x00000002u;
goto P_0c07d9cc;
P_0c07d9cc: /* original 2c1b, guest PC 0x0c07d9cc */
if(!s->budget--) { s->failed_pc=0x0c07d9ccu; return 0; }
r[12]|=r[1];
goto P_0c07d9ce;
P_0c07d9ce: /* original 604c, guest PC 0x0c07d9ce */
if(!s->budget--) { s->failed_pc=0x0c07d9ceu; return 0; }
r[0]=r[4]&255u;
goto P_0c07d9d0;
P_0c07d9d0: /* original 8801, guest PC 0x0c07d9d0 */
if(!s->budget--) { s->failed_pc=0x0c07d9d0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07d9d2;
P_0c07d9d2: /* original 8f15, guest PC 0x0c07d9d2 */
if(!s->budget--) { s->failed_pc=0x0c07d9d2u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c07da00; }
goto P_0c07d9d6;
P_0c07d9d4: /* original 6403, guest PC 0x0c07d9d4 */
if(!s->budget--) { s->failed_pc=0x0c07d9d4u; return 0; }
r[4]=r[0];
goto P_0c07d9d6;
P_0c07d9d6: /* original e204, guest PC 0x0c07d9d6 */
if(!s->budget--) { s->failed_pc=0x0c07d9d6u; return 0; }
r[2]=0x00000004u;
goto P_0c07d9d8;
P_0c07d9d8: /* original a01b, guest PC 0x0c07d9d8 */
if(!s->budget--) { s->failed_pc=0x0c07d9d8u; return 0; }
r[12]|=r[2];
goto P_0c07da12;
P_0c07d9da: /* original 2c2b, guest PC 0x0c07d9da */
if(!s->budget--) { s->failed_pc=0x0c07d9dau; return 0; }
r[12]|=r[2];
if(!vf3_matrix_family(0x0c07d9dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07d9dcu; return 0; } return 1;
P_0c07da00: /* original e019, guest PC 0x0c07da00 */
if(!s->budget--) { s->failed_pc=0x0c07da00u; return 0; }
r[0]=0x00000019u;
goto P_0c07da02;
P_0c07da02: /* original 04dc, guest PC 0x0c07da02 */
if(!s->budget--) { s->failed_pc=0x0c07da02u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07da04;
P_0c07da04: /* original e3fe, guest PC 0x0c07da04 */
if(!s->budget--) { s->failed_pc=0x0c07da04u; return 0; }
r[3]=0xfffffffeu;
goto P_0c07da06;
P_0c07da06: /* original 644c, guest PC 0x0c07da06 */
if(!s->budget--) { s->failed_pc=0x0c07da06u; return 0; }
r[4]=r[4]&255u;
goto P_0c07da08;
P_0c07da08: /* original 2448, guest PC 0x0c07da08 */
if(!s->budget--) { s->failed_pc=0x0c07da08u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07da0a;
P_0c07da0a: /* original 8f02, guest PC 0x0c07da0a */
if(!s->budget--) { s->failed_pc=0x0c07da0au; return 0; }
cond=r[17]&1u;
r[12]&=r[3];
if(!cond) { goto P_0c07da12; }
goto P_0c07da0e;
P_0c07da0c: /* original 2c39, guest PC 0x0c07da0c */
if(!s->budget--) { s->failed_pc=0x0c07da0cu; return 0; }
r[12]&=r[3];
goto P_0c07da0e;
P_0c07da0e: /* original e101, guest PC 0x0c07da0e */
if(!s->budget--) { s->failed_pc=0x0c07da0eu; return 0; }
r[1]=0x00000001u;
goto P_0c07da10;
P_0c07da10: /* original 2c1b, guest PC 0x0c07da10 */
if(!s->budget--) { s->failed_pc=0x0c07da10u; return 0; }
r[12]|=r[1];
goto P_0c07da12;
P_0c07da12: /* original e029, guest PC 0x0c07da12 */
if(!s->budget--) { s->failed_pc=0x0c07da12u; return 0; }
r[0]=0x00000029u;
goto P_0c07da14;
P_0c07da14: /* original 04dc, guest PC 0x0c07da14 */
if(!s->budget--) { s->failed_pc=0x0c07da14u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07da16;
P_0c07da16: /* original 644c, guest PC 0x0c07da16 */
if(!s->budget--) { s->failed_pc=0x0c07da16u; return 0; }
r[4]=r[4]&255u;
goto P_0c07da18;
P_0c07da18: /* original 6043, guest PC 0x0c07da18 */
if(!s->budget--) { s->failed_pc=0x0c07da18u; return 0; }
r[0]=r[4];
goto P_0c07da1a;
P_0c07da1a: /* original 8803, guest PC 0x0c07da1a */
if(!s->budget--) { s->failed_pc=0x0c07da1au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c07da1c;
P_0c07da1c: /* original 8f01, guest PC 0x0c07da1c */
if(!s->budget--) { s->failed_pc=0x0c07da1cu; return 0; }
cond=r[17]&1u;
r[7]=0x00000008u;
if(!cond) { goto P_0c07da22; }
goto P_0c07da20;
P_0c07da1e: /* original e708, guest PC 0x0c07da1e */
if(!s->budget--) { s->failed_pc=0x0c07da1eu; return 0; }
r[7]=0x00000008u;
goto P_0c07da20;
P_0c07da20: /* original 2c7b, guest PC 0x0c07da20 */
if(!s->budget--) { s->failed_pc=0x0c07da20u; return 0; }
r[12]|=r[7];
goto P_0c07da22;
P_0c07da22: /* original e201, guest PC 0x0c07da22 */
if(!s->budget--) { s->failed_pc=0x0c07da22u; return 0; }
r[2]=0x00000001u;
goto P_0c07da24;
P_0c07da24: /* original 1ec9, guest PC 0x0c07da24 */
if(!s->budget--) { s->failed_pc=0x0c07da24u; return 0; }
write(ram,r[14]+36,r[12],4);
goto P_0c07da26;
P_0c07da26: /* original d530, guest PC 0x0c07da26 */
if(!s->budget--) { s->failed_pc=0x0c07da26u; return 0; }
r[5]=read(ram,0x0c07dae8u,4);
goto P_0c07da28;
P_0c07da28: /* original 22c8, guest PC 0x0c07da28 */
if(!s->budget--) { s->failed_pc=0x0c07da28u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c07da2a;
P_0c07da2a: /* original 8d01, guest PC 0x0c07da2a */
if(!s->budget--) { s->failed_pc=0x0c07da2au; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[5]+16,4);
if(cond) { goto P_0c07da30; }
goto P_0c07da2e;
P_0c07da2c: /* original 5454, guest PC 0x0c07da2c */
if(!s->budget--) { s->failed_pc=0x0c07da2cu; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c07da2e;
P_0c07da2e: /* original 5455, guest PC 0x0c07da2e */
if(!s->budget--) { s->failed_pc=0x0c07da2eu; return 0; }
r[4]=read(ram,r[5]+20,4);
goto P_0c07da30;
P_0c07da30: /* original e061, guest PC 0x0c07da30 */
if(!s->budget--) { s->failed_pc=0x0c07da30u; return 0; }
r[0]=0x00000061u;
goto P_0c07da32;
P_0c07da32: /* original 054c, guest PC 0x0c07da32 */
if(!s->budget--) { s->failed_pc=0x0c07da32u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c07da34;
P_0c07da34: /* original d02d, guest PC 0x0c07da34 */
if(!s->budget--) { s->failed_pc=0x0c07da34u; return 0; }
r[0]=read(ram,0x0c07daecu,4);
goto P_0c07da36;
P_0c07da36: /* original 655c, guest PC 0x0c07da36 */
if(!s->budget--) { s->failed_pc=0x0c07da36u; return 0; }
r[5]=r[5]&255u;
goto P_0c07da38;
P_0c07da38: /* original 6453, guest PC 0x0c07da38 */
if(!s->budget--) { s->failed_pc=0x0c07da38u; return 0; }
r[4]=r[5];
goto P_0c07da3a;
P_0c07da3a: /* original 4408, guest PC 0x0c07da3a */
if(!s->budget--) { s->failed_pc=0x0c07da3au; return 0; }
r[4]<<=2;
goto P_0c07da3c;
P_0c07da3c: /* original 6343, guest PC 0x0c07da3c */
if(!s->budget--) { s->failed_pc=0x0c07da3cu; return 0; }
r[3]=r[4];
goto P_0c07da3e;
P_0c07da3e: /* original 7301, guest PC 0x0c07da3e */
if(!s->budget--) { s->failed_pc=0x0c07da3eu; return 0; }
r[3]+=0x00000001u;
goto P_0c07da40;
P_0c07da40: /* original 7402, guest PC 0x0c07da40 */
if(!s->budget--) { s->failed_pc=0x0c07da40u; return 0; }
r[4]+=0x00000002u;
goto P_0c07da42;
P_0c07da42: /* original 6b53, guest PC 0x0c07da42 */
if(!s->budget--) { s->failed_pc=0x0c07da42u; return 0; }
r[11]=r[5];
goto P_0c07da44;
P_0c07da44: /* original 4b08, guest PC 0x0c07da44 */
if(!s->budget--) { s->failed_pc=0x0c07da44u; return 0; }
r[11]<<=2;
goto P_0c07da46;
P_0c07da46: /* original 4b00, guest PC 0x0c07da46 */
if(!s->budget--) { s->failed_pc=0x0c07da46u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c07da48;
P_0c07da48: /* original 4300, guest PC 0x0c07da48 */
if(!s->budget--) { s->failed_pc=0x0c07da48u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07da4a;
P_0c07da4a: /* original 0bbd, guest PC 0x0c07da4a */
if(!s->budget--) { s->failed_pc=0x0c07da4au; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c07da4c;
P_0c07da4c: /* original 023d, guest PC 0x0c07da4c */
if(!s->budget--) { s->failed_pc=0x0c07da4cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07da4e;
P_0c07da4e: /* original 4400, guest PC 0x0c07da4e */
if(!s->budget--) { s->failed_pc=0x0c07da4eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07da50;
P_0c07da50: /* original 034d, guest PC 0x0c07da50 */
if(!s->budget--) { s->failed_pc=0x0c07da50u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07da52;
P_0c07da52: /* original e036, guest PC 0x0c07da52 */
if(!s->budget--) { s->failed_pc=0x0c07da52u; return 0; }
r[0]=0x00000036u;
goto P_0c07da54;
P_0c07da54: /* original 652d, guest PC 0x0c07da54 */
if(!s->budget--) { s->failed_pc=0x0c07da54u; return 0; }
r[5]=r[2]&65535u;
goto P_0c07da56;
P_0c07da56: /* original 6293, guest PC 0x0c07da56 */
if(!s->budget--) { s->failed_pc=0x0c07da56u; return 0; }
r[2]=r[9];
goto P_0c07da58;
P_0c07da58: /* original 643d, guest PC 0x0c07da58 */
if(!s->budget--) { s->failed_pc=0x0c07da58u; return 0; }
r[4]=r[3]&65535u;
goto P_0c07da5a;
P_0c07da5a: /* original 63e3, guest PC 0x0c07da5a */
if(!s->budget--) { s->failed_pc=0x0c07da5au; return 0; }
r[3]=r[14];
goto P_0c07da5c;
P_0c07da5c: /* original 7328, guest PC 0x0c07da5c */
if(!s->budget--) { s->failed_pc=0x0c07da5cu; return 0; }
r[3]+=0x00000028u;
goto P_0c07da5e;
P_0c07da5e: /* original 2f22, guest PC 0x0c07da5e */
if(!s->budget--) { s->failed_pc=0x0c07da5eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c07da60;
P_0c07da60: /* original 6bbd, guest PC 0x0c07da60 */
if(!s->budget--) { s->failed_pc=0x0c07da60u; return 0; }
r[11]=r[11]&65535u;
goto P_0c07da62;
P_0c07da62: /* original 22b1, guest PC 0x0c07da62 */
if(!s->budget--) { s->failed_pc=0x0c07da62u; return 0; }
write(ram,r[2],r[11],2);
goto P_0c07da64;
P_0c07da64: /* original e201, guest PC 0x0c07da64 */
if(!s->budget--) { s->failed_pc=0x0c07da64u; return 0; }
r[2]=0x00000001u;
goto P_0c07da66;
P_0c07da66: /* original 23b1, guest PC 0x0c07da66 */
if(!s->budget--) { s->failed_pc=0x0c07da66u; return 0; }
write(ram,r[3],r[11],2);
goto P_0c07da68;
P_0c07da68: /* original e33e, guest PC 0x0c07da68 */
if(!s->budget--) { s->failed_pc=0x0c07da68u; return 0; }
r[3]=0x0000003eu;
goto P_0c07da6a;
P_0c07da6a: /* original 0e55, guest PC 0x0c07da6a */
if(!s->budget--) { s->failed_pc=0x0c07da6au; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c07da6c;
P_0c07da6c: /* original e038, guest PC 0x0c07da6c */
if(!s->budget--) { s->failed_pc=0x0c07da6cu; return 0; }
r[0]=0x00000038u;
goto P_0c07da6e;
P_0c07da6e: /* original 0e35, guest PC 0x0c07da6e */
if(!s->budget--) { s->failed_pc=0x0c07da6eu; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c07da70;
P_0c07da70: /* original e03a, guest PC 0x0c07da70 */
if(!s->budget--) { s->failed_pc=0x0c07da70u; return 0; }
r[0]=0x0000003au;
goto P_0c07da72;
P_0c07da72: /* original e334, guest PC 0x0c07da72 */
if(!s->budget--) { s->failed_pc=0x0c07da72u; return 0; }
r[3]=0x00000034u;
goto P_0c07da74;
P_0c07da74: /* original 0e25, guest PC 0x0c07da74 */
if(!s->budget--) { s->failed_pc=0x0c07da74u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c07da76;
P_0c07da76: /* original e040, guest PC 0x0c07da76 */
if(!s->budget--) { s->failed_pc=0x0c07da76u; return 0; }
r[0]=0x00000040u;
goto P_0c07da78;
P_0c07da78: /* original 3348, guest PC 0x0c07da78 */
if(!s->budget--) { s->failed_pc=0x0c07da78u; return 0; }
r[3]-=r[4];
goto P_0c07da7a;
P_0c07da7a: /* original 0e35, guest PC 0x0c07da7a */
if(!s->budget--) { s->failed_pc=0x0c07da7au; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c07da7c;
P_0c07da7c: /* original e042, guest PC 0x0c07da7c */
if(!s->budget--) { s->failed_pc=0x0c07da7cu; return 0; }
r[0]=0x00000042u;
goto P_0c07da7e;
P_0c07da7e: /* original e2fc, guest PC 0x0c07da7e */
if(!s->budget--) { s->failed_pc=0x0c07da7eu; return 0; }
r[2]=0xfffffffcu;
goto P_0c07da80;
P_0c07da80: /* original e302, guest PC 0x0c07da80 */
if(!s->budget--) { s->failed_pc=0x0c07da80u; return 0; }
r[3]=0x00000002u;
goto P_0c07da82;
P_0c07da82: /* original 0e25, guest PC 0x0c07da82 */
if(!s->budget--) { s->failed_pc=0x0c07da82u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c07da84;
P_0c07da84: /* original 962d, guest PC 0x0c07da84 */
if(!s->budget--) { s->failed_pc=0x0c07da84u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07dae2u,2);
goto P_0c07da86;
P_0c07da86: /* original 23c8, guest PC 0x0c07da86 */
if(!s->budget--) { s->failed_pc=0x0c07da86u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c07da88;
P_0c07da88: /* original e02b, guest PC 0x0c07da88 */
if(!s->budget--) { s->failed_pc=0x0c07da88u; return 0; }
r[0]=0x0000002bu;
goto P_0c07da8a;
P_0c07da8a: /* original 8f0a, guest PC 0x0c07da8a */
if(!s->budget--) { s->failed_pc=0x0c07da8au; return 0; }
cond=r[17]&1u;
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
if(!cond) { goto P_0c07daa2; }
goto P_0c07da8e;
P_0c07da8c: /* original 05dc, guest PC 0x0c07da8c */
if(!s->budget--) { s->failed_pc=0x0c07da8cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07da8e;
P_0c07da8e: /* original 27c8, guest PC 0x0c07da8e */
if(!s->budget--) { s->failed_pc=0x0c07da8eu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[12])==0)!=0);
goto P_0c07da90;
P_0c07da90: /* original 8b31, guest PC 0x0c07da90 */
if(!s->budget--) { s->failed_pc=0x0c07da90u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07daf6; }
goto P_0c07da92;
P_0c07da92: /* original 6053, guest PC 0x0c07da92 */
if(!s->budget--) { s->failed_pc=0x0c07da92u; return 0; }
r[0]=r[5];
goto P_0c07da94;
P_0c07da94: /* original 8801, guest PC 0x0c07da94 */
if(!s->budget--) { s->failed_pc=0x0c07da94u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07da96;
P_0c07da96: /* original 8921, guest PC 0x0c07da96 */
if(!s->budget--) { s->failed_pc=0x0c07da96u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07dadc; }
goto P_0c07da98;
P_0c07da98: /* original 6053, guest PC 0x0c07da98 */
if(!s->budget--) { s->failed_pc=0x0c07da98u; return 0; }
r[0]=r[5];
goto P_0c07da9a;
P_0c07da9a: /* original 8809, guest PC 0x0c07da9a */
if(!s->budget--) { s->failed_pc=0x0c07da9au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c07da9c;
P_0c07da9c: /* original 892a, guest PC 0x0c07da9c */
if(!s->budget--) { s->failed_pc=0x0c07da9cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07daf4; }
goto P_0c07da9e;
P_0c07da9e: /* original a02a, guest PC 0x0c07da9e */
if(!s->budget--) { s->failed_pc=0x0c07da9eu; return 0; }
goto P_0c07daf6;
P_0c07daa0: /* original 0009, guest PC 0x0c07daa0 */
if(!s->budget--) { s->failed_pc=0x0c07daa0u; return 0; }
goto P_0c07daa2;
P_0c07daa2: /* original e01c, guest PC 0x0c07daa2 */
if(!s->budget--) { s->failed_pc=0x0c07daa2u; return 0; }
r[0]=0x0000001cu;
goto P_0c07daa4;
P_0c07daa4: /* original 0bdc, guest PC 0x0c07daa4 */
if(!s->budget--) { s->failed_pc=0x0c07daa4u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07daa6;
P_0c07daa6: /* original 901d, guest PC 0x0c07daa6 */
if(!s->budget--) { s->failed_pc=0x0c07daa6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07dae4u,2);
goto P_0c07daa8;
P_0c07daa8: /* original 6bbc, guest PC 0x0c07daa8 */
if(!s->budget--) { s->failed_pc=0x0c07daa8u; return 0; }
r[11]=r[11]&255u;
goto P_0c07daaa;
P_0c07daaa: /* original 04dc, guest PC 0x0c07daaa */
if(!s->budget--) { s->failed_pc=0x0c07daaau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07daac;
P_0c07daac: /* original 4400, guest PC 0x0c07daac */
if(!s->budget--) { s->failed_pc=0x0c07daacu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07daae;
P_0c07daae: /* original 27c8, guest PC 0x0c07daae */
if(!s->budget--) { s->failed_pc=0x0c07daaeu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[12])==0)!=0);
goto P_0c07dab0;
P_0c07dab0: /* original 8f0f, guest PC 0x0c07dab0 */
if(!s->budget--) { s->failed_pc=0x0c07dab0u; return 0; }
cond=r[17]&1u;
r[4]+=0xffffffffu;
if(!cond) { goto P_0c07dad2; }
goto P_0c07dab4;
P_0c07dab2: /* original 74ff, guest PC 0x0c07dab2 */
if(!s->budget--) { s->failed_pc=0x0c07dab2u; return 0; }
r[4]+=0xffffffffu;
goto P_0c07dab4;
P_0c07dab4: /* original 6053, guest PC 0x0c07dab4 */
if(!s->budget--) { s->failed_pc=0x0c07dab4u; return 0; }
r[0]=r[5];
goto P_0c07dab6;
P_0c07dab6: /* original 8801, guest PC 0x0c07dab6 */
if(!s->budget--) { s->failed_pc=0x0c07dab6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07dab8;
P_0c07dab8: /* original 8b04, guest PC 0x0c07dab8 */
if(!s->budget--) { s->failed_pc=0x0c07dab8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07dac4; }
goto P_0c07daba;
P_0c07daba: /* original 60b3, guest PC 0x0c07daba */
if(!s->budget--) { s->failed_pc=0x0c07dabau; return 0; }
r[0]=r[11];
goto P_0c07dabc;
P_0c07dabc: /* original 8801, guest PC 0x0c07dabc */
if(!s->budget--) { s->failed_pc=0x0c07dabcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07dabe;
P_0c07dabe: /* original 890d, guest PC 0x0c07dabe */
if(!s->budget--) { s->failed_pc=0x0c07dabeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07dadc; }
goto P_0c07dac0;
P_0c07dac0: /* original 2bb8, guest PC 0x0c07dac0 */
if(!s->budget--) { s->failed_pc=0x0c07dac0u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c07dac2;
P_0c07dac2: /* original 890b, guest PC 0x0c07dac2 */
if(!s->budget--) { s->failed_pc=0x0c07dac2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07dadc; }
goto P_0c07dac4;
P_0c07dac4: /* original 6053, guest PC 0x0c07dac4 */
if(!s->budget--) { s->failed_pc=0x0c07dac4u; return 0; }
r[0]=r[5];
goto P_0c07dac6;
P_0c07dac6: /* original 8809, guest PC 0x0c07dac6 */
if(!s->budget--) { s->failed_pc=0x0c07dac6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c07dac8;
P_0c07dac8: /* original 8b15, guest PC 0x0c07dac8 */
if(!s->budget--) { s->failed_pc=0x0c07dac8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07daf6; }
goto P_0c07daca;
P_0c07daca: /* original 3b40, guest PC 0x0c07daca */
if(!s->budget--) { s->failed_pc=0x0c07dacau; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[4])!=0);
goto P_0c07dacc;
P_0c07dacc: /* original 8b13, guest PC 0x0c07dacc */
if(!s->budget--) { s->failed_pc=0x0c07daccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07daf6; }
goto P_0c07dace;
P_0c07dace: /* original a011, guest PC 0x0c07dace */
if(!s->budget--) { s->failed_pc=0x0c07daceu; return 0; }
goto P_0c07daf4;
P_0c07dad0: /* original 0009, guest PC 0x0c07dad0 */
if(!s->budget--) { s->failed_pc=0x0c07dad0u; return 0; }
goto P_0c07dad2;
P_0c07dad2: /* original 60b3, guest PC 0x0c07dad2 */
if(!s->budget--) { s->failed_pc=0x0c07dad2u; return 0; }
r[0]=r[11];
goto P_0c07dad4;
P_0c07dad4: /* original 8801, guest PC 0x0c07dad4 */
if(!s->budget--) { s->failed_pc=0x0c07dad4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07dad6;
P_0c07dad6: /* original 8901, guest PC 0x0c07dad6 */
if(!s->budget--) { s->failed_pc=0x0c07dad6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07dadc; }
goto P_0c07dad8;
P_0c07dad8: /* original 2bb8, guest PC 0x0c07dad8 */
if(!s->budget--) { s->failed_pc=0x0c07dad8u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c07dada;
P_0c07dada: /* original 8b09, guest PC 0x0c07dada */
if(!s->budget--) { s->failed_pc=0x0c07dadau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07daf0; }
goto P_0c07dadc;
P_0c07dadc: /* original 9603, guest PC 0x0c07dadc */
if(!s->budget--) { s->failed_pc=0x0c07dadcu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07dae6u,2);
goto P_0c07dade;
P_0c07dade: /* original a00a, guest PC 0x0c07dade */
if(!s->budget--) { s->failed_pc=0x0c07dadeu; return 0; }
goto P_0c07daf6;
P_0c07dae0: /* original 0009, guest PC 0x0c07dae0 */
if(!s->budget--) { s->failed_pc=0x0c07dae0u; return 0; }
if(!vf3_matrix_family(0x0c07dae2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07dae2u; return 0; } return 1;
P_0c07daf0: /* original 3b40, guest PC 0x0c07daf0 */
if(!s->budget--) { s->failed_pc=0x0c07daf0u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[4])!=0);
goto P_0c07daf2;
P_0c07daf2: /* original 8b00, guest PC 0x0c07daf2 */
if(!s->budget--) { s->failed_pc=0x0c07daf2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07daf6; }
goto P_0c07daf4;
P_0c07daf4: /* original 9676, guest PC 0x0c07daf4 */
if(!s->budget--) { s->failed_pc=0x0c07daf4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07dbe4u,2);
goto P_0c07daf6;
P_0c07daf6: /* original e204, guest PC 0x0c07daf6 */
if(!s->budget--) { s->failed_pc=0x0c07daf6u; return 0; }
r[2]=0x00000004u;
goto P_0c07daf8;
P_0c07daf8: /* original 22c9, guest PC 0x0c07daf8 */
if(!s->budget--) { s->failed_pc=0x0c07daf8u; return 0; }
r[2]&=r[12];
goto P_0c07dafa;
P_0c07dafa: /* original e319, guest PC 0x0c07dafa */
if(!s->budget--) { s->failed_pc=0x0c07dafau; return 0; }
r[3]=0x00000019u;
goto P_0c07dafc;
P_0c07dafc: /* original e034, guest PC 0x0c07dafc */
if(!s->budget--) { s->failed_pc=0x0c07dafcu; return 0; }
r[0]=0x00000034u;
goto P_0c07dafe;
P_0c07dafe: /* original 2228, guest PC 0x0c07dafe */
if(!s->budget--) { s->failed_pc=0x0c07dafeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07db00;
P_0c07db00: /* original 0e65, guest PC 0x0c07db00 */
if(!s->budget--) { s->failed_pc=0x0c07db00u; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c07db02;
P_0c07db02: /* original 1f35, guest PC 0x0c07db02 */
if(!s->budget--) { s->failed_pc=0x0c07db02u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c07db04;
P_0c07db04: /* original 8d02, guest PC 0x0c07db04 */
if(!s->budget--) { s->failed_pc=0x0c07db04u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+12,r[2],4);
if(cond) { goto P_0c07db0c; }
goto P_0c07db08;
P_0c07db06: /* original 1f23, guest PC 0x0c07db06 */
if(!s->budget--) { s->failed_pc=0x0c07db06u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c07db08;
P_0c07db08: /* original e114, guest PC 0x0c07db08 */
if(!s->budget--) { s->failed_pc=0x0c07db08u; return 0; }
r[1]=0x00000014u;
goto P_0c07db0a;
P_0c07db0a: /* original 1f15, guest PC 0x0c07db0a */
if(!s->budget--) { s->failed_pc=0x0c07db0au; return 0; }
write(ram,r[15]+20,r[1],4);
goto P_0c07db0c;
P_0c07db0c: /* original 56f5, guest PC 0x0c07db0c */
if(!s->budget--) { s->failed_pc=0x0c07db0cu; return 0; }
r[6]=read(ram,r[15]+20,4);
goto P_0c07db0e;
P_0c07db0e: /* original 65c3, guest PC 0x0c07db0e */
if(!s->budget--) { s->failed_pc=0x0c07db0eu; return 0; }
r[5]=r[12];
goto P_0c07db10;
P_0c07db10: /* original b27b, guest PC 0x0c07db10 */
if(!s->budget--) { s->failed_pc=0x0c07db10u; return 0; }
target=code_base|0x0c07e00au; r[16]=code_base|0x0c07db14u;
r[4]=read(ram,r[15]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07db14u) { target=s->pc; goto dispatch; }
goto P_0c07db14;
P_0c07db12: /* original 54f4, guest PC 0x0c07db12 */
if(!s->budget--) { s->failed_pc=0x0c07db12u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c07db14;
P_0c07db14: /* original e032, guest PC 0x0c07db14 */
if(!s->budget--) { s->failed_pc=0x0c07db14u; return 0; }
r[0]=0x00000032u;
goto P_0c07db16;
P_0c07db16: /* original 0ea4, guest PC 0x0c07db16 */
if(!s->budget--) { s->failed_pc=0x0c07db16u; return 0; }
write(ram,r[14]+r[0],r[10],1);
goto P_0c07db18;
P_0c07db18: /* original 53f3, guest PC 0x0c07db18 */
if(!s->budget--) { s->failed_pc=0x0c07db18u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c07db1a;
P_0c07db1a: /* original 2338, guest PC 0x0c07db1a */
if(!s->budget--) { s->failed_pc=0x0c07db1au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07db1c;
P_0c07db1c: /* original 8b01, guest PC 0x0c07db1c */
if(!s->budget--) { s->failed_pc=0x0c07db1cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07db22; }
goto P_0c07db1e;
P_0c07db1e: /* original a09d, guest PC 0x0c07db1e */
if(!s->budget--) { s->failed_pc=0x0c07db1eu; return 0; }
goto P_0c07dc5c;
P_0c07db20: /* original 0009, guest PC 0x0c07db20 */
if(!s->budget--) { s->failed_pc=0x0c07db20u; return 0; }
goto P_0c07db22;
P_0c07db22: /* original 9060, guest PC 0x0c07db22 */
if(!s->budget--) { s->failed_pc=0x0c07db22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07dbe6u,2);
goto P_0c07db24;
P_0c07db24: /* original e30a, guest PC 0x0c07db24 */
if(!s->budget--) { s->failed_pc=0x0c07db24u; return 0; }
r[3]=0x0000000au;
goto P_0c07db26;
P_0c07db26: /* original 04dc, guest PC 0x0c07db26 */
if(!s->budget--) { s->failed_pc=0x0c07db26u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07db28;
P_0c07db28: /* original e032, guest PC 0x0c07db28 */
if(!s->budget--) { s->failed_pc=0x0c07db28u; return 0; }
r[0]=0x00000032u;
goto P_0c07db2a;
P_0c07db2a: /* original 74ff, guest PC 0x0c07db2a */
if(!s->budget--) { s->failed_pc=0x0c07db2au; return 0; }
r[4]+=0xffffffffu;
goto P_0c07db2c;
P_0c07db2c: /* original 0e44, guest PC 0x0c07db2c */
if(!s->budget--) { s->failed_pc=0x0c07db2cu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c07db2e;
P_0c07db2e: /* original e033, guest PC 0x0c07db2e */
if(!s->budget--) { s->failed_pc=0x0c07db2eu; return 0; }
r[0]=0x00000033u;
goto P_0c07db30;
P_0c07db30: /* original 6243, guest PC 0x0c07db30 */
if(!s->budget--) { s->failed_pc=0x0c07db30u; return 0; }
r[2]=r[4];
goto P_0c07db32;
P_0c07db32: /* original 0e34, guest PC 0x0c07db32 */
if(!s->budget--) { s->failed_pc=0x0c07db32u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c07db34;
P_0c07db34: /* original 4208, guest PC 0x0c07db34 */
if(!s->budget--) { s->failed_pc=0x0c07db34u; return 0; }
r[2]<<=2;
goto P_0c07db36;
P_0c07db36: /* original 6343, guest PC 0x0c07db36 */
if(!s->budget--) { s->failed_pc=0x0c07db36u; return 0; }
r[3]=r[4];
goto P_0c07db38;
P_0c07db38: /* original 51f5, guest PC 0x0c07db38 */
if(!s->budget--) { s->failed_pc=0x0c07db38u; return 0; }
r[1]=read(ram,r[15]+20,4);
goto P_0c07db3a;
P_0c07db3a: /* original 323c, guest PC 0x0c07db3a */
if(!s->budget--) { s->failed_pc=0x0c07db3au; return 0; }
r[2]+=r[3];
goto P_0c07db3c;
P_0c07db3c: /* original 4200, guest PC 0x0c07db3c */
if(!s->budget--) { s->failed_pc=0x0c07db3cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07db3e;
P_0c07db3e: /* original e301, guest PC 0x0c07db3e */
if(!s->budget--) { s->failed_pc=0x0c07db3eu; return 0; }
r[3]=0x00000001u;
goto P_0c07db40;
P_0c07db40: /* original 321c, guest PC 0x0c07db40 */
if(!s->budget--) { s->failed_pc=0x0c07db40u; return 0; }
r[2]+=r[1];
goto P_0c07db42;
P_0c07db42: /* original 23c8, guest PC 0x0c07db42 */
if(!s->budget--) { s->failed_pc=0x0c07db42u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c07db44;
P_0c07db44: /* original 1f25, guest PC 0x0c07db44 */
if(!s->budget--) { s->failed_pc=0x0c07db44u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c07db46;
P_0c07db46: /* original 964f, guest PC 0x0c07db46 */
if(!s->budget--) { s->failed_pc=0x0c07db46u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07dbe8u,2);
goto P_0c07db48;
P_0c07db48: /* original 8d02, guest PC 0x0c07db48 */
if(!s->budget--) { s->failed_pc=0x0c07db48u; return 0; }
cond=r[17]&1u;
r[6]+=r[13];
if(cond) { goto P_0c07db50; }
goto P_0c07db4c;
P_0c07db4a: /* original 36dc, guest PC 0x0c07db4a */
if(!s->budget--) { s->failed_pc=0x0c07db4au; return 0; }
r[6]+=r[13];
goto P_0c07db4c;
P_0c07db4c: /* original 964d, guest PC 0x0c07db4c */
if(!s->budget--) { s->failed_pc=0x0c07db4cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07dbeau,2);
goto P_0c07db4e;
P_0c07db4e: /* original 36dc, guest PC 0x0c07db4e */
if(!s->budget--) { s->failed_pc=0x0c07db4eu; return 0; }
r[6]+=r[13];
goto P_0c07db50;
P_0c07db50: /* original e300, guest PC 0x0c07db50 */
if(!s->budget--) { s->failed_pc=0x0c07db50u; return 0; }
r[3]=0x00000000u;
goto P_0c07db52;
P_0c07db52: /* original 6be3, guest PC 0x0c07db52 */
if(!s->budget--) { s->failed_pc=0x0c07db52u; return 0; }
r[11]=r[14];
goto P_0c07db54;
P_0c07db54: /* original 3436, guest PC 0x0c07db54 */
if(!s->budget--) { s->failed_pc=0x0c07db54u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[3])!=0);
goto P_0c07db56;
P_0c07db56: /* original 8f12, guest PC 0x0c07db56 */
if(!s->budget--) { s->failed_pc=0x0c07db56u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000028u;
if(!cond) { goto P_0c07db7e; }
goto P_0c07db5a;
P_0c07db58: /* original 7b28, guest PC 0x0c07db58 */
if(!s->budget--) { s->failed_pc=0x0c07db58u; return 0; }
r[11]+=0x00000028u;
goto P_0c07db5a;
P_0c07db5a: /* original e70d, guest PC 0x0c07db5a */
if(!s->budget--) { s->failed_pc=0x0c07db5au; return 0; }
r[7]=0x0000000du;
goto P_0c07db5c;
P_0c07db5c: /* original 7601, guest PC 0x0c07db5c */
if(!s->budget--) { s->failed_pc=0x0c07db5cu; return 0; }
r[6]+=0x00000001u;
goto P_0c07db5e;
P_0c07db5e: /* original 6560, guest PC 0x0c07db5e */
if(!s->budget--) { s->failed_pc=0x0c07db5eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[5]=tmp;
goto P_0c07db60;
P_0c07db60: /* original 655c, guest PC 0x0c07db60 */
if(!s->budget--) { s->failed_pc=0x0c07db60u; return 0; }
r[5]=r[5]&255u;
goto P_0c07db62;
P_0c07db62: /* original 3572, guest PC 0x0c07db62 */
if(!s->budget--) { s->failed_pc=0x0c07db62u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[7])!=0);
goto P_0c07db64;
P_0c07db64: /* original 8b00, guest PC 0x0c07db64 */
if(!s->budget--) { s->failed_pc=0x0c07db64u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07db68; }
goto P_0c07db66;
P_0c07db66: /* original 75f3, guest PC 0x0c07db66 */
if(!s->budget--) { s->failed_pc=0x0c07db66u; return 0; }
r[5]+=0xfffffff3u;
goto P_0c07db68;
P_0c07db68: /* original d020, guest PC 0x0c07db68 */
if(!s->budget--) { s->failed_pc=0x0c07db68u; return 0; }
r[0]=read(ram,0x0c07dbecu,4);
goto P_0c07db6a;
P_0c07db6a: /* original 4508, guest PC 0x0c07db6a */
if(!s->budget--) { s->failed_pc=0x0c07db6au; return 0; }
r[5]<<=2;
goto P_0c07db6c;
P_0c07db6c: /* original 4500, guest PC 0x0c07db6c */
if(!s->budget--) { s->failed_pc=0x0c07db6cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07db6e;
P_0c07db6e: /* original 025d, guest PC 0x0c07db6e */
if(!s->budget--) { s->failed_pc=0x0c07db6eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c07db70;
P_0c07db70: /* original 74ff, guest PC 0x0c07db70 */
if(!s->budget--) { s->failed_pc=0x0c07db70u; return 0; }
r[4]+=0xffffffffu;
goto P_0c07db72;
P_0c07db72: /* original e300, guest PC 0x0c07db72 */
if(!s->budget--) { s->failed_pc=0x0c07db72u; return 0; }
r[3]=0x00000000u;
goto P_0c07db74;
P_0c07db74: /* original 3436, guest PC 0x0c07db74 */
if(!s->budget--) { s->failed_pc=0x0c07db74u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[3])!=0);
goto P_0c07db76;
P_0c07db76: /* original 652d, guest PC 0x0c07db76 */
if(!s->budget--) { s->failed_pc=0x0c07db76u; return 0; }
r[5]=r[2]&65535u;
goto P_0c07db78;
P_0c07db78: /* original 7b02, guest PC 0x0c07db78 */
if(!s->budget--) { s->failed_pc=0x0c07db78u; return 0; }
r[11]+=0x00000002u;
goto P_0c07db7a;
P_0c07db7a: /* original 8def, guest PC 0x0c07db7a */
if(!s->budget--) { s->failed_pc=0x0c07db7au; return 0; }
cond=r[17]&1u;
write(ram,r[11],r[5],2);
if(cond) { goto P_0c07db5c; }
goto P_0c07db7e;
P_0c07db7c: /* original 2b51, guest PC 0x0c07db7c */
if(!s->budget--) { s->failed_pc=0x0c07db7cu; return 0; }
write(ram,r[11],r[5],2);
goto P_0c07db7e;
P_0c07db7e: /* original 9032, guest PC 0x0c07db7e */
if(!s->budget--) { s->failed_pc=0x0c07db7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07dbe6u,2);
goto P_0c07db80;
P_0c07db80: /* original e302, guest PC 0x0c07db80 */
if(!s->budget--) { s->failed_pc=0x0c07db80u; return 0; }
r[3]=0x00000002u;
goto P_0c07db82;
P_0c07db82: /* original 0bdc, guest PC 0x0c07db82 */
if(!s->budget--) { s->failed_pc=0x0c07db82u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07db84;
P_0c07db84: /* original 3b37, guest PC 0x0c07db84 */
if(!s->budget--) { s->failed_pc=0x0c07db84u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>(int32_t)r[3])!=0);
goto P_0c07db86;
P_0c07db86: /* original 8f01, guest PC 0x0c07db86 */
if(!s->budget--) { s->failed_pc=0x0c07db86u; return 0; }
cond=r[17]&1u;
r[6]=0x00000003u;
if(!cond) { goto P_0c07db8c; }
goto P_0c07db8a;
P_0c07db88: /* original e603, guest PC 0x0c07db88 */
if(!s->budget--) { s->failed_pc=0x0c07db88u; return 0; }
r[6]=0x00000003u;
goto P_0c07db8a;
P_0c07db8a: /* original 6b63, guest PC 0x0c07db8a */
if(!s->budget--) { s->failed_pc=0x0c07db8au; return 0; }
r[11]=r[6];
goto P_0c07db8c;
P_0c07db8c: /* original e300, guest PC 0x0c07db8c */
if(!s->budget--) { s->failed_pc=0x0c07db8cu; return 0; }
r[3]=0x00000000u;
goto P_0c07db8e;
P_0c07db8e: /* original 65a3, guest PC 0x0c07db8e */
if(!s->budget--) { s->failed_pc=0x0c07db8eu; return 0; }
r[5]=r[10];
goto P_0c07db90;
P_0c07db90: /* original 3b36, guest PC 0x0c07db90 */
if(!s->budget--) { s->failed_pc=0x0c07db90u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>r[3])!=0);
goto P_0c07db92;
P_0c07db92: /* original 8f0a, guest PC 0x0c07db92 */
if(!s->budget--) { s->failed_pc=0x0c07db92u; return 0; }
cond=r[17]&1u;
r[4]=r[10];
if(!cond) { goto P_0c07dbaa; }
goto P_0c07db96;
P_0c07db94: /* original 64a3, guest PC 0x0c07db94 */
if(!s->budget--) { s->failed_pc=0x0c07db94u; return 0; }
r[4]=r[10];
goto P_0c07db96;
P_0c07db96: /* original 63e3, guest PC 0x0c07db96 */
if(!s->budget--) { s->failed_pc=0x0c07db96u; return 0; }
r[3]=r[14];
goto P_0c07db98;
P_0c07db98: /* original 7328, guest PC 0x0c07db98 */
if(!s->budget--) { s->failed_pc=0x0c07db98u; return 0; }
r[3]+=0x00000028u;
goto P_0c07db9a;
P_0c07db9a: /* original 334c, guest PC 0x0c07db9a */
if(!s->budget--) { s->failed_pc=0x0c07db9au; return 0; }
r[3]+=r[4];
goto P_0c07db9c;
P_0c07db9c: /* original 6043, guest PC 0x0c07db9c */
if(!s->budget--) { s->failed_pc=0x0c07db9cu; return 0; }
r[0]=r[4];
goto P_0c07db9e;
P_0c07db9e: /* original 6331, guest PC 0x0c07db9e */
if(!s->budget--) { s->failed_pc=0x0c07db9eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c07dba0;
P_0c07dba0: /* original 7501, guest PC 0x0c07dba0 */
if(!s->budget--) { s->failed_pc=0x0c07dba0u; return 0; }
r[5]+=0x00000001u;
goto P_0c07dba2;
P_0c07dba2: /* original 35b2, guest PC 0x0c07dba2 */
if(!s->budget--) { s->failed_pc=0x0c07dba2u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[11])!=0);
goto P_0c07dba4;
P_0c07dba4: /* original 0935, guest PC 0x0c07dba4 */
if(!s->budget--) { s->failed_pc=0x0c07dba4u; return 0; }
write(ram,r[9]+r[0],r[3],2);
goto P_0c07dba6;
P_0c07dba6: /* original 8ff6, guest PC 0x0c07dba6 */
if(!s->budget--) { s->failed_pc=0x0c07dba6u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000002u;
if(!cond) { goto P_0c07db96; }
goto P_0c07dbaa;
P_0c07dba8: /* original 7402, guest PC 0x0c07dba8 */
if(!s->budget--) { s->failed_pc=0x0c07dba8u; return 0; }
r[4]+=0x00000002u;
goto P_0c07dbaa;
P_0c07dbaa: /* original 901c, guest PC 0x0c07dbaa */
if(!s->budget--) { s->failed_pc=0x0c07dbaau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07dbe6u,2);
goto P_0c07dbac;
P_0c07dbac: /* original e202, guest PC 0x0c07dbac */
if(!s->budget--) { s->failed_pc=0x0c07dbacu; return 0; }
r[2]=0x00000002u;
goto P_0c07dbae;
P_0c07dbae: /* original 03dc, guest PC 0x0c07dbae */
if(!s->budget--) { s->failed_pc=0x0c07dbaeu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07dbb0;
P_0c07dbb0: /* original 3327, guest PC 0x0c07dbb0 */
if(!s->budget--) { s->failed_pc=0x0c07dbb0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c07dbb2;
P_0c07dbb2: /* original 8b15, guest PC 0x0c07dbb2 */
if(!s->budget--) { s->failed_pc=0x0c07dbb2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07dbe0; }
goto P_0c07dbb4;
P_0c07dbb4: /* original 6793, guest PC 0x0c07dbb4 */
if(!s->budget--) { s->failed_pc=0x0c07dbb4u; return 0; }
r[7]=r[9];
goto P_0c07dbb6;
P_0c07dbb6: /* original 6463, guest PC 0x0c07dbb6 */
if(!s->budget--) { s->failed_pc=0x0c07dbb6u; return 0; }
r[4]=r[6];
goto P_0c07dbb8;
P_0c07dbb8: /* original a00e, guest PC 0x0c07dbb8 */
if(!s->budget--) { s->failed_pc=0x0c07dbb8u; return 0; }
r[7]+=0x00000004u;
goto P_0c07dbd8;
P_0c07dbba: /* original 7704, guest PC 0x0c07dbba */
if(!s->budget--) { s->failed_pc=0x0c07dbbau; return 0; }
r[7]+=0x00000004u;
goto P_0c07dbbc;
P_0c07dbbc: /* original 6643, guest PC 0x0c07dbbc */
if(!s->budget--) { s->failed_pc=0x0c07dbbcu; return 0; }
r[6]=r[4];
goto P_0c07dbbe;
P_0c07dbbe: /* original 6371, guest PC 0x0c07dbbe */
if(!s->budget--) { s->failed_pc=0x0c07dbbeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[3]=tmp;
goto P_0c07dbc0;
P_0c07dbc0: /* original 4600, guest PC 0x0c07dbc0 */
if(!s->budget--) { s->failed_pc=0x0c07dbc0u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c07dbc2;
P_0c07dbc2: /* original 65e3, guest PC 0x0c07dbc2 */
if(!s->budget--) { s->failed_pc=0x0c07dbc2u; return 0; }
r[5]=r[14];
goto P_0c07dbc4;
P_0c07dbc4: /* original 6063, guest PC 0x0c07dbc4 */
if(!s->budget--) { s->failed_pc=0x0c07dbc4u; return 0; }
r[0]=r[6];
goto P_0c07dbc6;
P_0c07dbc6: /* original 7528, guest PC 0x0c07dbc6 */
if(!s->budget--) { s->failed_pc=0x0c07dbc6u; return 0; }
r[5]+=0x00000028u;
goto P_0c07dbc8;
P_0c07dbc8: /* original 0935, guest PC 0x0c07dbc8 */
if(!s->budget--) { s->failed_pc=0x0c07dbc8u; return 0; }
write(ram,r[9]+r[0],r[3],2);
goto P_0c07dbca;
P_0c07dbca: /* original e204, guest PC 0x0c07dbca */
if(!s->budget--) { s->failed_pc=0x0c07dbcau; return 0; }
r[2]=0x00000004u;
goto P_0c07dbcc;
P_0c07dbcc: /* original 6053, guest PC 0x0c07dbcc */
if(!s->budget--) { s->failed_pc=0x0c07dbccu; return 0; }
r[0]=r[5];
goto P_0c07dbce;
P_0c07dbce: /* original 022d, guest PC 0x0c07dbce */
if(!s->budget--) { s->failed_pc=0x0c07dbceu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c07dbd0;
P_0c07dbd0: /* original 6353, guest PC 0x0c07dbd0 */
if(!s->budget--) { s->failed_pc=0x0c07dbd0u; return 0; }
r[3]=r[5];
goto P_0c07dbd2;
P_0c07dbd2: /* original 336c, guest PC 0x0c07dbd2 */
if(!s->budget--) { s->failed_pc=0x0c07dbd2u; return 0; }
r[3]+=r[6];
goto P_0c07dbd4;
P_0c07dbd4: /* original 7401, guest PC 0x0c07dbd4 */
if(!s->budget--) { s->failed_pc=0x0c07dbd4u; return 0; }
r[4]+=0x00000001u;
goto P_0c07dbd6;
P_0c07dbd6: /* original 2321, guest PC 0x0c07dbd6 */
if(!s->budget--) { s->failed_pc=0x0c07dbd6u; return 0; }
write(ram,r[3],r[2],2);
goto P_0c07dbd8;
P_0c07dbd8: /* original 9005, guest PC 0x0c07dbd8 */
if(!s->budget--) { s->failed_pc=0x0c07dbd8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07dbe6u,2);
goto P_0c07dbda;
P_0c07dbda: /* original 03dc, guest PC 0x0c07dbda */
if(!s->budget--) { s->failed_pc=0x0c07dbdau; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c07dbdc;
P_0c07dbdc: /* original 3432, guest PC 0x0c07dbdc */
if(!s->budget--) { s->failed_pc=0x0c07dbdcu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[3])!=0);
goto P_0c07dbde;
P_0c07dbde: /* original 8bed, guest PC 0x0c07dbde */
if(!s->budget--) { s->failed_pc=0x0c07dbdeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07dbbc; }
goto P_0c07dbe0;
P_0c07dbe0: /* original a01c, guest PC 0x0c07dbe0 */
if(!s->budget--) { s->failed_pc=0x0c07dbe0u; return 0; }
r[6]=r[10];
goto P_0c07dc1c;
P_0c07dbe2: /* original 66a3, guest PC 0x0c07dbe2 */
if(!s->budget--) { s->failed_pc=0x0c07dbe2u; return 0; }
r[6]=r[10];
if(!vf3_matrix_family(0x0c07dbe4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07dbe4u; return 0; } return 1;
P_0c07dbf0: /* original 6463, guest PC 0x0c07dbf0 */
if(!s->budget--) { s->failed_pc=0x0c07dbf0u; return 0; }
r[4]=r[6];
goto P_0c07dbf2;
P_0c07dbf2: /* original 7401, guest PC 0x0c07dbf2 */
if(!s->budget--) { s->failed_pc=0x0c07dbf2u; return 0; }
r[4]+=0x00000001u;
goto P_0c07dbf4;
P_0c07dbf4: /* original 63e3, guest PC 0x0c07dbf4 */
if(!s->budget--) { s->failed_pc=0x0c07dbf4u; return 0; }
r[3]=r[14];
goto P_0c07dbf6;
P_0c07dbf6: /* original 6543, guest PC 0x0c07dbf6 */
if(!s->budget--) { s->failed_pc=0x0c07dbf6u; return 0; }
r[5]=r[4];
goto P_0c07dbf8;
P_0c07dbf8: /* original 6863, guest PC 0x0c07dbf8 */
if(!s->budget--) { s->failed_pc=0x0c07dbf8u; return 0; }
r[8]=r[6];
goto P_0c07dbfa;
P_0c07dbfa: /* original 7328, guest PC 0x0c07dbfa */
if(!s->budget--) { s->failed_pc=0x0c07dbfau; return 0; }
r[3]+=0x00000028u;
goto P_0c07dbfc;
P_0c07dbfc: /* original 4500, guest PC 0x0c07dbfc */
if(!s->budget--) { s->failed_pc=0x0c07dbfcu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07dbfe;
P_0c07dbfe: /* original 4800, guest PC 0x0c07dbfe */
if(!s->budget--) { s->failed_pc=0x0c07dbfeu; return 0; }
r[17]=(r[17]&~1u)|((r[8]>>31)!=0);
r[8]<<=1;
goto P_0c07dc00;
P_0c07dc00: /* original 34b2, guest PC 0x0c07dc00 */
if(!s->budget--) { s->failed_pc=0x0c07dc00u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[11])!=0);
goto P_0c07dc02;
P_0c07dc02: /* original 353c, guest PC 0x0c07dc02 */
if(!s->budget--) { s->failed_pc=0x0c07dc02u; return 0; }
r[5]+=r[3];
goto P_0c07dc04;
P_0c07dc04: /* original 8d09, guest PC 0x0c07dc04 */
if(!s->budget--) { s->failed_pc=0x0c07dc04u; return 0; }
cond=r[17]&1u;
r[8]+=r[9];
if(cond) { goto P_0c07dc1a; }
goto P_0c07dc08;
P_0c07dc06: /* original 389c, guest PC 0x0c07dc06 */
if(!s->budget--) { s->failed_pc=0x0c07dc06u; return 0; }
r[8]+=r[9];
goto P_0c07dc08;
P_0c07dc08: /* original 6351, guest PC 0x0c07dc08 */
if(!s->budget--) { s->failed_pc=0x0c07dc08u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[3]=tmp;
goto P_0c07dc0a;
P_0c07dc0a: /* original 6281, guest PC 0x0c07dc0a */
if(!s->budget--) { s->failed_pc=0x0c07dc0au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[2]=tmp;
goto P_0c07dc0c;
P_0c07dc0c: /* original 3230, guest PC 0x0c07dc0c */
if(!s->budget--) { s->failed_pc=0x0c07dc0cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c07dc0e;
P_0c07dc0e: /* original 8f01, guest PC 0x0c07dc0e */
if(!s->budget--) { s->failed_pc=0x0c07dc0eu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c07dc14; }
goto P_0c07dc12;
P_0c07dc10: /* original 7401, guest PC 0x0c07dc10 */
if(!s->budget--) { s->failed_pc=0x0c07dc10u; return 0; }
r[4]+=0x00000001u;
goto P_0c07dc12;
P_0c07dc12: /* original 28a1, guest PC 0x0c07dc12 */
if(!s->budget--) { s->failed_pc=0x0c07dc12u; return 0; }
write(ram,r[8],r[10],2);
goto P_0c07dc14;
P_0c07dc14: /* original 34b2, guest PC 0x0c07dc14 */
if(!s->budget--) { s->failed_pc=0x0c07dc14u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[11])!=0);
goto P_0c07dc16;
P_0c07dc16: /* original 8ff7, guest PC 0x0c07dc16 */
if(!s->budget--) { s->failed_pc=0x0c07dc16u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000002u;
if(!cond) { goto P_0c07dc08; }
goto P_0c07dc1a;
P_0c07dc18: /* original 7502, guest PC 0x0c07dc18 */
if(!s->budget--) { s->failed_pc=0x0c07dc18u; return 0; }
r[5]+=0x00000002u;
goto P_0c07dc1a;
P_0c07dc1a: /* original 7601, guest PC 0x0c07dc1a */
if(!s->budget--) { s->failed_pc=0x0c07dc1au; return 0; }
r[6]+=0x00000001u;
goto P_0c07dc1c;
P_0c07dc1c: /* original 36b2, guest PC 0x0c07dc1c */
if(!s->budget--) { s->failed_pc=0x0c07dc1cu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[11])!=0);
goto P_0c07dc1e;
P_0c07dc1e: /* original 8be7, guest PC 0x0c07dc1e */
if(!s->budget--) { s->failed_pc=0x0c07dc1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07dbf0; }
goto P_0c07dc20;
P_0c07dc20: /* original e200, guest PC 0x0c07dc20 */
if(!s->budget--) { s->failed_pc=0x0c07dc20u; return 0; }
r[2]=0x00000000u;
goto P_0c07dc22;
P_0c07dc22: /* original 1fa1, guest PC 0x0c07dc22 */
if(!s->budget--) { s->failed_pc=0x0c07dc22u; return 0; }
write(ram,r[15]+4,r[10],4);
goto P_0c07dc24;
P_0c07dc24: /* original 9353, guest PC 0x0c07dc24 */
if(!s->budget--) { s->failed_pc=0x0c07dc24u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07dcceu,2);
goto P_0c07dc26;
P_0c07dc26: /* original 3b26, guest PC 0x0c07dc26 */
if(!s->budget--) { s->failed_pc=0x0c07dc26u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>r[2])!=0);
goto P_0c07dc28;
P_0c07dc28: /* original 33ec, guest PC 0x0c07dc28 */
if(!s->budget--) { s->failed_pc=0x0c07dc28u; return 0; }
r[3]+=r[14];
goto P_0c07dc2a;
P_0c07dc2a: /* original 1f32, guest PC 0x0c07dc2a */
if(!s->budget--) { s->failed_pc=0x0c07dc2au; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07dc2c;
P_0c07dc2c: /* original 8f20, guest PC 0x0c07dc2c */
if(!s->budget--) { s->failed_pc=0x0c07dc2cu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[15],4);
r[8]=tmp;
if(!cond) { goto P_0c07dc70; }
goto P_0c07dc30;
P_0c07dc2e: /* original 68f2, guest PC 0x0c07dc2e */
if(!s->budget--) { s->failed_pc=0x0c07dc2eu; return 0; }
tmp=read(ram,r[15],4);
r[8]=tmp;
goto P_0c07dc30;
P_0c07dc30: /* original 63f2, guest PC 0x0c07dc30 */
if(!s->budget--) { s->failed_pc=0x0c07dc30u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07dc32;
P_0c07dc32: /* original 6231, guest PC 0x0c07dc32 */
if(!s->budget--) { s->failed_pc=0x0c07dc32u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[2]=tmp;
goto P_0c07dc34;
P_0c07dc34: /* original 2228, guest PC 0x0c07dc34 */
if(!s->budget--) { s->failed_pc=0x0c07dc34u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07dc36;
P_0c07dc36: /* original 8903, guest PC 0x0c07dc36 */
if(!s->budget--) { s->failed_pc=0x0c07dc36u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07dc40; }
goto P_0c07dc38;
P_0c07dc38: /* original d326, guest PC 0x0c07dc38 */
if(!s->budget--) { s->failed_pc=0x0c07dc38u; return 0; }
r[3]=read(ram,0x0c07dcd4u,4);
goto P_0c07dc3a;
P_0c07dc3a: /* original 6581, guest PC 0x0c07dc3a */
if(!s->budget--) { s->failed_pc=0x0c07dc3au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[5]=tmp;
goto P_0c07dc3c;
P_0c07dc3c: /* original 430b, guest PC 0x0c07dc3c */
if(!s->budget--) { s->failed_pc=0x0c07dc3cu; return 0; }
target=r[3];
r[16]=code_base|0x0c07dc40u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07dc40u) { target=s->pc; goto dispatch; }
goto P_0c07dc40;
P_0c07dc3e: /* original 54f2, guest PC 0x0c07dc3e */
if(!s->budget--) { s->failed_pc=0x0c07dc3eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07dc40;
P_0c07dc40: /* original 52f1, guest PC 0x0c07dc40 */
if(!s->budget--) { s->failed_pc=0x0c07dc40u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07dc42;
P_0c07dc42: /* original 7802, guest PC 0x0c07dc42 */
if(!s->budget--) { s->failed_pc=0x0c07dc42u; return 0; }
r[8]+=0x00000002u;
goto P_0c07dc44;
P_0c07dc44: /* original 7201, guest PC 0x0c07dc44 */
if(!s->budget--) { s->failed_pc=0x0c07dc44u; return 0; }
r[2]+=0x00000001u;
goto P_0c07dc46;
P_0c07dc46: /* original 32b2, guest PC 0x0c07dc46 */
if(!s->budget--) { s->failed_pc=0x0c07dc46u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[11])!=0);
goto P_0c07dc48;
P_0c07dc48: /* original 1f21, guest PC 0x0c07dc48 */
if(!s->budget--) { s->failed_pc=0x0c07dc48u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c07dc4a;
P_0c07dc4a: /* original 53f2, guest PC 0x0c07dc4a */
if(!s->budget--) { s->failed_pc=0x0c07dc4au; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07dc4c;
P_0c07dc4c: /* original 7304, guest PC 0x0c07dc4c */
if(!s->budget--) { s->failed_pc=0x0c07dc4cu; return 0; }
r[3]+=0x00000004u;
goto P_0c07dc4e;
P_0c07dc4e: /* original 1f32, guest PC 0x0c07dc4e */
if(!s->budget--) { s->failed_pc=0x0c07dc4eu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07dc50;
P_0c07dc50: /* original 61f2, guest PC 0x0c07dc50 */
if(!s->budget--) { s->failed_pc=0x0c07dc50u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c07dc52;
P_0c07dc52: /* original 7102, guest PC 0x0c07dc52 */
if(!s->budget--) { s->failed_pc=0x0c07dc52u; return 0; }
r[1]+=0x00000002u;
goto P_0c07dc54;
P_0c07dc54: /* original 8fec, guest PC 0x0c07dc54 */
if(!s->budget--) { s->failed_pc=0x0c07dc54u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[1],4);
if(!cond) { goto P_0c07dc30; }
goto P_0c07dc58;
P_0c07dc56: /* original 2f12, guest PC 0x0c07dc56 */
if(!s->budget--) { s->failed_pc=0x0c07dc56u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c07dc58;
P_0c07dc58: /* original a00a, guest PC 0x0c07dc58 */
if(!s->budget--) { s->failed_pc=0x0c07dc58u; return 0; }
goto P_0c07dc70;
P_0c07dc5a: /* original 0009, guest PC 0x0c07dc5a */
if(!s->budget--) { s->failed_pc=0x0c07dc5au; return 0; }
goto P_0c07dc5c;
P_0c07dc5c: /* original 65e3, guest PC 0x0c07dc5c */
if(!s->budget--) { s->failed_pc=0x0c07dc5cu; return 0; }
r[5]=r[14];
goto P_0c07dc5e;
P_0c07dc5e: /* original 9336, guest PC 0x0c07dc5e */
if(!s->budget--) { s->failed_pc=0x0c07dc5eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07dcceu,2);
goto P_0c07dc60;
P_0c07dc60: /* original 7528, guest PC 0x0c07dc60 */
if(!s->budget--) { s->failed_pc=0x0c07dc60u; return 0; }
r[5]+=0x00000028u;
goto P_0c07dc62;
P_0c07dc62: /* original d21c, guest PC 0x0c07dc62 */
if(!s->budget--) { s->failed_pc=0x0c07dc62u; return 0; }
r[2]=read(ram,0x0c07dcd4u,4);
goto P_0c07dc64;
P_0c07dc64: /* original 6551, guest PC 0x0c07dc64 */
if(!s->budget--) { s->failed_pc=0x0c07dc64u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c07dc66;
P_0c07dc66: /* original 64b3, guest PC 0x0c07dc66 */
if(!s->budget--) { s->failed_pc=0x0c07dc66u; return 0; }
r[4]=r[11];
goto P_0c07dc68;
P_0c07dc68: /* original 4408, guest PC 0x0c07dc68 */
if(!s->budget--) { s->failed_pc=0x0c07dc68u; return 0; }
r[4]<<=2;
goto P_0c07dc6a;
P_0c07dc6a: /* original 33ec, guest PC 0x0c07dc6a */
if(!s->budget--) { s->failed_pc=0x0c07dc6au; return 0; }
r[3]+=r[14];
goto P_0c07dc6c;
P_0c07dc6c: /* original 420b, guest PC 0x0c07dc6c */
if(!s->budget--) { s->failed_pc=0x0c07dc6cu; return 0; }
target=r[2];
r[16]=code_base|0x0c07dc70u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07dc70u) { target=s->pc; goto dispatch; }
goto P_0c07dc70;
P_0c07dc6e: /* original 343c, guest PC 0x0c07dc6e */
if(!s->budget--) { s->failed_pc=0x0c07dc6eu; return 0; }
r[4]+=r[3];
goto P_0c07dc70;
P_0c07dc70: /* original e302, guest PC 0x0c07dc70 */
if(!s->budget--) { s->failed_pc=0x0c07dc70u; return 0; }
r[3]=0x00000002u;
goto P_0c07dc72;
P_0c07dc72: /* original 52f3, guest PC 0x0c07dc72 */
if(!s->budget--) { s->failed_pc=0x0c07dc72u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c07dc74;
P_0c07dc74: /* original 2c39, guest PC 0x0c07dc74 */
if(!s->budget--) { s->failed_pc=0x0c07dc74u; return 0; }
r[12]&=r[3];
goto P_0c07dc76;
P_0c07dc76: /* original 2cc8, guest PC 0x0c07dc76 */
if(!s->budget--) { s->failed_pc=0x0c07dc76u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c07dc78;
P_0c07dc78: /* original 0029, guest PC 0x0c07dc78 */
if(!s->budget--) { s->failed_pc=0x0c07dc78u; return 0; }
r[0]=r[17]&1u;
goto P_0c07dc7a;
P_0c07dc7a: /* original 202b, guest PC 0x0c07dc7a */
if(!s->budget--) { s->failed_pc=0x0c07dc7au; return 0; }
r[0]|=r[2];
goto P_0c07dc7c;
P_0c07dc7c: /* original 2008, guest PC 0x0c07dc7c */
if(!s->budget--) { s->failed_pc=0x0c07dc7cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c07dc7e;
P_0c07dc7e: /* original 8906, guest PC 0x0c07dc7e */
if(!s->budget--) { s->failed_pc=0x0c07dc7eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07dc8e; }
goto P_0c07dc80;
P_0c07dc80: /* original d116, guest PC 0x0c07dc80 */
if(!s->budget--) { s->failed_pc=0x0c07dc80u; return 0; }
r[1]=read(ram,0x0c07dcdcu,4);
goto P_0c07dc82;
P_0c07dc82: /* original d415, guest PC 0x0c07dc82 */
if(!s->budget--) { s->failed_pc=0x0c07dc82u; return 0; }
r[4]=read(ram,0x0c07dcd8u,4);
goto P_0c07dc84;
P_0c07dc84: /* original 410b, guest PC 0x0c07dc84 */
if(!s->budget--) { s->failed_pc=0x0c07dc84u; return 0; }
target=r[1];
r[16]=code_base|0x0c07dc88u;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07dc88u) { target=s->pc; goto dispatch; }
goto P_0c07dc88;
P_0c07dc86: /* original e500, guest PC 0x0c07dc86 */
if(!s->budget--) { s->failed_pc=0x0c07dc86u; return 0; }
r[5]=0x00000000u;
goto P_0c07dc88;
P_0c07dc88: /* original d315, guest PC 0x0c07dc88 */
if(!s->budget--) { s->failed_pc=0x0c07dc88u; return 0; }
r[3]=read(ram,0x0c07dce0u,4);
goto P_0c07dc8a;
P_0c07dc8a: /* original 430b, guest PC 0x0c07dc8a */
if(!s->budget--) { s->failed_pc=0x0c07dc8au; return 0; }
target=r[3];
r[16]=code_base|0x0c07dc8eu;
r[4]=0x0000001bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07dc8eu) { target=s->pc; goto dispatch; }
goto P_0c07dc8e;
P_0c07dc8c: /* original e41b, guest PC 0x0c07dc8c */
if(!s->budget--) { s->failed_pc=0x0c07dc8cu; return 0; }
r[4]=0x0000001bu;
goto P_0c07dc8e;
P_0c07dc8e: /* original 901f, guest PC 0x0c07dc8e */
if(!s->budget--) { s->failed_pc=0x0c07dc8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07dcd0u,2);
goto P_0c07dc90;
P_0c07dc90: /* original 52f5, guest PC 0x0c07dc90 */
if(!s->budget--) { s->failed_pc=0x0c07dc90u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c07dc92;
P_0c07dc92: /* original 0e26, guest PC 0x0c07dc92 */
if(!s->budget--) { s->failed_pc=0x0c07dc92u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c07dc94;
P_0c07dc94: /* original 7004, guest PC 0x0c07dc94 */
if(!s->budget--) { s->failed_pc=0x0c07dc94u; return 0; }
r[0]+=0x00000004u;
goto P_0c07dc96;
P_0c07dc96: /* original d313, guest PC 0x0c07dc96 */
if(!s->budget--) { s->failed_pc=0x0c07dc96u; return 0; }
r[3]=read(ram,0x0c07dce4u,4);
goto P_0c07dc98;
P_0c07dc98: /* original 0e36, guest PC 0x0c07dc98 */
if(!s->budget--) { s->failed_pc=0x0c07dc98u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c07dc9a;
P_0c07dc9a: /* original 70f8, guest PC 0x0c07dc9a */
if(!s->budget--) { s->failed_pc=0x0c07dc9au; return 0; }
r[0]+=0xfffffff8u;
goto P_0c07dc9c;
P_0c07dc9c: /* original 0ea6, guest PC 0x0c07dc9c */
if(!s->budget--) { s->failed_pc=0x0c07dc9cu; return 0; }
write(ram,r[14]+r[0],r[10],4);
goto P_0c07dc9e;
P_0c07dc9e: /* original d312, guest PC 0x0c07dc9e */
if(!s->budget--) { s->failed_pc=0x0c07dc9eu; return 0; }
r[3]=read(ram,0x0c07dce8u,4);
goto P_0c07dca0;
P_0c07dca0: /* original 6230, guest PC 0x0c07dca0 */
if(!s->budget--) { s->failed_pc=0x0c07dca0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c07dca2;
P_0c07dca2: /* original 7201, guest PC 0x0c07dca2 */
if(!s->budget--) { s->failed_pc=0x0c07dca2u; return 0; }
r[2]+=0x00000001u;
goto P_0c07dca4;
P_0c07dca4: /* original 2320, guest PC 0x0c07dca4 */
if(!s->budget--) { s->failed_pc=0x0c07dca4u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c07dca6;
P_0c07dca6: /* original d311, guest PC 0x0c07dca6 */
if(!s->budget--) { s->failed_pc=0x0c07dca6u; return 0; }
r[3]=read(ram,0x0c07dcecu,4);
goto P_0c07dca8;
P_0c07dca8: /* original 6233, guest PC 0x0c07dca8 */
if(!s->budget--) { s->failed_pc=0x0c07dca8u; return 0; }
r[2]=r[3];
goto P_0c07dcaa;
P_0c07dcaa: /* original 1e34, guest PC 0x0c07dcaa */
if(!s->budget--) { s->failed_pc=0x0c07dcaau; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c07dcac;
P_0c07dcac: /* original 9011, guest PC 0x0c07dcac */
if(!s->budget--) { s->failed_pc=0x0c07dcacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07dcd2u,2);
goto P_0c07dcae;
P_0c07dcae: /* original 0d24, guest PC 0x0c07dcae */
if(!s->budget--) { s->failed_pc=0x0c07dcaeu; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c07dcb0;
P_0c07dcb0: /* original 70ff, guest PC 0x0c07dcb0 */
if(!s->budget--) { s->failed_pc=0x0c07dcb0u; return 0; }
r[0]+=0xffffffffu;
goto P_0c07dcb2;
P_0c07dcb2: /* original 0d34, guest PC 0x0c07dcb2 */
if(!s->budget--) { s->failed_pc=0x0c07dcb2u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c07dcb4;
P_0c07dcb4: /* original 55f6, guest PC 0x0c07dcb4 */
if(!s->budget--) { s->failed_pc=0x0c07dcb4u; return 0; }
r[5]=read(ram,r[15]+24,4);
goto P_0c07dcb6;
P_0c07dcb6: /* original b01b, guest PC 0x0c07dcb6 */
if(!s->budget--) { s->failed_pc=0x0c07dcb6u; return 0; }
target=code_base|0x0c07dcf0u; r[16]=code_base|0x0c07dcbau;
r[4]=read(ram,r[15]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07dcbau) { target=s->pc; goto dispatch; }
goto P_0c07dcba;
P_0c07dcb8: /* original 54f4, guest PC 0x0c07dcb8 */
if(!s->budget--) { s->failed_pc=0x0c07dcb8u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c07dcba;
P_0c07dcba: /* original 7f28, guest PC 0x0c07dcba */
if(!s->budget--) { s->failed_pc=0x0c07dcbau; return 0; }
r[15]+=0x00000028u;
goto P_0c07dcbc;
P_0c07dcbc: /* original 4f26, guest PC 0x0c07dcbc */
if(!s->budget--) { s->failed_pc=0x0c07dcbcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07dcbe;
P_0c07dcbe: /* original 68f6, guest PC 0x0c07dcbe */
if(!s->budget--) { s->failed_pc=0x0c07dcbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07dcc0;
P_0c07dcc0: /* original 69f6, guest PC 0x0c07dcc0 */
if(!s->budget--) { s->failed_pc=0x0c07dcc0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07dcc2;
P_0c07dcc2: /* original 6af6, guest PC 0x0c07dcc2 */
if(!s->budget--) { s->failed_pc=0x0c07dcc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07dcc4;
P_0c07dcc4: /* original 6bf6, guest PC 0x0c07dcc4 */
if(!s->budget--) { s->failed_pc=0x0c07dcc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07dcc6;
P_0c07dcc6: /* original 6cf6, guest PC 0x0c07dcc6 */
if(!s->budget--) { s->failed_pc=0x0c07dcc6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07dcc8;
P_0c07dcc8: /* original 6df6, guest PC 0x0c07dcc8 */
if(!s->budget--) { s->failed_pc=0x0c07dcc8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07dcca;
P_0c07dcca: /* original 000b, guest PC 0x0c07dcca */
if(!s->budget--) { s->failed_pc=0x0c07dccau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07dccc: /* original 6ef6, guest PC 0x0c07dccc */
if(!s->budget--) { s->failed_pc=0x0c07dcccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07dcceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07dcceu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
