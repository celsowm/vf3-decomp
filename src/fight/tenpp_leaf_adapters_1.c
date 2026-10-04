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
int vf3_tenpp_leaf_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c058790u: goto P_0c058790;
case 0x0c058792u: goto P_0c058792;
case 0x0c058794u: goto P_0c058794;
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
case 0x0c058978u: goto P_0c058978;
case 0x0c05897au: goto P_0c05897a;
case 0x0c05897cu: goto P_0c05897c;
case 0x0c05897eu: goto P_0c05897e;
case 0x0c058980u: goto P_0c058980;
case 0x0c058982u: goto P_0c058982;
case 0x0c058984u: goto P_0c058984;
case 0x0c058986u: goto P_0c058986;
case 0x0c058988u: goto P_0c058988;
case 0x0c05898au: goto P_0c05898a;
case 0x0c05898cu: goto P_0c05898c;
case 0x0c05898eu: goto P_0c05898e;
case 0x0c058990u: goto P_0c058990;
case 0x0c058992u: goto P_0c058992;
case 0x0c058994u: goto P_0c058994;
case 0x0c058996u: goto P_0c058996;
case 0x0c058998u: goto P_0c058998;
case 0x0c05899au: goto P_0c05899a;
case 0x0c05899cu: goto P_0c05899c;
case 0x0c05899eu: goto P_0c05899e;
case 0x0c0589a0u: goto P_0c0589a0;
case 0x0c0589a2u: goto P_0c0589a2;
case 0x0c0589a4u: goto P_0c0589a4;
case 0x0c0589a6u: goto P_0c0589a6;
case 0x0c0589a8u: goto P_0c0589a8;
case 0x0c0589aau: goto P_0c0589aa;
case 0x0c0589acu: goto P_0c0589ac;
case 0x0c0589aeu: goto P_0c0589ae;
case 0x0c0589b0u: goto P_0c0589b0;
case 0x0c0589b2u: goto P_0c0589b2;
case 0x0c0589b4u: goto P_0c0589b4;
case 0x0c0589b6u: goto P_0c0589b6;
case 0x0c0589b8u: goto P_0c0589b8;
case 0x0c0589bau: goto P_0c0589ba;
case 0x0c0589bcu: goto P_0c0589bc;
case 0x0c0589beu: goto P_0c0589be;
case 0x0c0589c0u: goto P_0c0589c0;
case 0x0c0589c2u: goto P_0c0589c2;
case 0x0c0589c4u: goto P_0c0589c4;
case 0x0c0589c6u: goto P_0c0589c6;
case 0x0c0589c8u: goto P_0c0589c8;
case 0x0c0589cau: goto P_0c0589ca;
case 0x0c0589ccu: goto P_0c0589cc;
case 0x0c0589ceu: goto P_0c0589ce;
case 0x0c0589d0u: goto P_0c0589d0;
case 0x0c0589d2u: goto P_0c0589d2;
case 0x0c0589d4u: goto P_0c0589d4;
case 0x0c0589d6u: goto P_0c0589d6;
case 0x0c0589d8u: goto P_0c0589d8;
case 0x0c0589dau: goto P_0c0589da;
case 0x0c0589dcu: goto P_0c0589dc;
case 0x0c0589deu: goto P_0c0589de;
case 0x0c0589e0u: goto P_0c0589e0;
case 0x0c0589e2u: goto P_0c0589e2;
case 0x0c0589e4u: goto P_0c0589e4;
case 0x0c0589e6u: goto P_0c0589e6;
case 0x0c0589e8u: goto P_0c0589e8;
case 0x0c0589eau: goto P_0c0589ea;
case 0x0c0589ecu: goto P_0c0589ec;
case 0x0c0589eeu: goto P_0c0589ee;
case 0x0c0589f0u: goto P_0c0589f0;
case 0x0c0589f2u: goto P_0c0589f2;
case 0x0c0589f4u: goto P_0c0589f4;
case 0x0c0589f6u: goto P_0c0589f6;
case 0x0c0589f8u: goto P_0c0589f8;
case 0x0c0589fau: goto P_0c0589fa;
case 0x0c0589fcu: goto P_0c0589fc;
case 0x0c0589feu: goto P_0c0589fe;
case 0x0c058a00u: goto P_0c058a00;
case 0x0c058a02u: goto P_0c058a02;
case 0x0c058a04u: goto P_0c058a04;
case 0x0c058a06u: goto P_0c058a06;
case 0x0c058a08u: goto P_0c058a08;
case 0x0c058a0au: goto P_0c058a0a;
case 0x0c058a0cu: goto P_0c058a0c;
case 0x0c058a0eu: goto P_0c058a0e;
case 0x0c058a10u: goto P_0c058a10;
case 0x0c058a12u: goto P_0c058a12;
case 0x0c058a14u: goto P_0c058a14;
case 0x0c058a16u: goto P_0c058a16;
case 0x0c058a18u: goto P_0c058a18;
case 0x0c058a1au: goto P_0c058a1a;
case 0x0c058a1cu: goto P_0c058a1c;
case 0x0c058a1eu: goto P_0c058a1e;
case 0x0c058a20u: goto P_0c058a20;
case 0x0c058a22u: goto P_0c058a22;
case 0x0c058a24u: goto P_0c058a24;
case 0x0c058a26u: goto P_0c058a26;
case 0x0c058a28u: goto P_0c058a28;
case 0x0c058a2au: goto P_0c058a2a;
case 0x0c058a2cu: goto P_0c058a2c;
case 0x0c058a2eu: goto P_0c058a2e;
case 0x0c058a30u: goto P_0c058a30;
case 0x0c058a32u: goto P_0c058a32;
case 0x0c058a34u: goto P_0c058a34;
case 0x0c058a36u: goto P_0c058a36;
case 0x0c058a38u: goto P_0c058a38;
case 0x0c058a3au: goto P_0c058a3a;
case 0x0c058a3cu: goto P_0c058a3c;
case 0x0c058a3eu: goto P_0c058a3e;
case 0x0c058a40u: goto P_0c058a40;
case 0x0c058a42u: goto P_0c058a42;
case 0x0c058a44u: goto P_0c058a44;
case 0x0c058a46u: goto P_0c058a46;
case 0x0c058a48u: goto P_0c058a48;
case 0x0c058a4au: goto P_0c058a4a;
case 0x0c058a4cu: goto P_0c058a4c;
case 0x0c058a4eu: goto P_0c058a4e;
case 0x0c058a50u: goto P_0c058a50;
case 0x0c058a52u: goto P_0c058a52;
case 0x0c058a54u: goto P_0c058a54;
case 0x0c058a56u: goto P_0c058a56;
case 0x0c0594b4u: goto P_0c0594b4;
case 0x0c0594b6u: goto P_0c0594b6;
case 0x0c0594b8u: goto P_0c0594b8;
case 0x0c0594bau: goto P_0c0594ba;
case 0x0c0594bcu: goto P_0c0594bc;
case 0x0c0594beu: goto P_0c0594be;
case 0x0c0594c0u: goto P_0c0594c0;
case 0x0c0594c2u: goto P_0c0594c2;
case 0x0c0594c4u: goto P_0c0594c4;
case 0x0c0594c6u: goto P_0c0594c6;
case 0x0c0594c8u: goto P_0c0594c8;
case 0x0c0594cau: goto P_0c0594ca;
case 0x0c0594ccu: goto P_0c0594cc;
case 0x0c0594ceu: goto P_0c0594ce;
case 0x0c0594d0u: goto P_0c0594d0;
case 0x0c0594d2u: goto P_0c0594d2;
case 0x0c0594d4u: goto P_0c0594d4;
case 0x0c0594d6u: goto P_0c0594d6;
case 0x0c0594d8u: goto P_0c0594d8;
case 0x0c0594dau: goto P_0c0594da;
case 0x0c0594dcu: goto P_0c0594dc;
case 0x0c0594deu: goto P_0c0594de;
case 0x0c0594e0u: goto P_0c0594e0;
case 0x0c0594e2u: goto P_0c0594e2;
case 0x0c0594e4u: goto P_0c0594e4;
case 0x0c0594e6u: goto P_0c0594e6;
case 0x0c0594e8u: goto P_0c0594e8;
case 0x0c0594eau: goto P_0c0594ea;
case 0x0c0594ecu: goto P_0c0594ec;
case 0x0c0594eeu: goto P_0c0594ee;
case 0x0c0594f0u: goto P_0c0594f0;
case 0x0c0594f2u: goto P_0c0594f2;
case 0x0c0594f4u: goto P_0c0594f4;
case 0x0c0594f6u: goto P_0c0594f6;
case 0x0c0594f8u: goto P_0c0594f8;
case 0x0c0594fau: goto P_0c0594fa;
case 0x0c0594fcu: goto P_0c0594fc;
case 0x0c0594feu: goto P_0c0594fe;
case 0x0c059500u: goto P_0c059500;
case 0x0c059502u: goto P_0c059502;
case 0x0c059504u: goto P_0c059504;
case 0x0c059506u: goto P_0c059506;
case 0x0c059508u: goto P_0c059508;
case 0x0c05950au: goto P_0c05950a;
case 0x0c05950cu: goto P_0c05950c;
case 0x0c05950eu: goto P_0c05950e;
case 0x0c059510u: goto P_0c059510;
case 0x0c059512u: goto P_0c059512;
case 0x0c059514u: goto P_0c059514;
case 0x0c059516u: goto P_0c059516;
case 0x0c059518u: goto P_0c059518;
case 0x0c05951au: goto P_0c05951a;
case 0x0c05951cu: goto P_0c05951c;
case 0x0c05951eu: goto P_0c05951e;
case 0x0c059520u: goto P_0c059520;
case 0x0c059522u: goto P_0c059522;
case 0x0c059524u: goto P_0c059524;
case 0x0c059526u: goto P_0c059526;
case 0x0c059528u: goto P_0c059528;
case 0x0c05952au: goto P_0c05952a;
case 0x0c05952cu: goto P_0c05952c;
case 0x0c05952eu: goto P_0c05952e;
case 0x0c059530u: goto P_0c059530;
case 0x0c059532u: goto P_0c059532;
case 0x0c059534u: goto P_0c059534;
case 0x0c059536u: goto P_0c059536;
case 0x0c059538u: goto P_0c059538;
case 0x0c05953au: goto P_0c05953a;
case 0x0c05953cu: goto P_0c05953c;
case 0x0c05953eu: goto P_0c05953e;
case 0x0c059540u: goto P_0c059540;
case 0x0c059542u: goto P_0c059542;
case 0x0c059544u: goto P_0c059544;
case 0x0c059546u: goto P_0c059546;
case 0x0c059548u: goto P_0c059548;
case 0x0c05954au: goto P_0c05954a;
case 0x0c05954cu: goto P_0c05954c;
case 0x0c05954eu: goto P_0c05954e;
case 0x0c059550u: goto P_0c059550;
case 0x0c059552u: goto P_0c059552;
case 0x0c059554u: goto P_0c059554;
case 0x0c059556u: goto P_0c059556;
case 0x0c059558u: goto P_0c059558;
case 0x0c05955au: goto P_0c05955a;
case 0x0c05955cu: goto P_0c05955c;
case 0x0c05955eu: goto P_0c05955e;
case 0x0c059560u: goto P_0c059560;
case 0x0c059562u: goto P_0c059562;
case 0x0c059564u: goto P_0c059564;
case 0x0c059566u: goto P_0c059566;
case 0x0c059568u: goto P_0c059568;
case 0x0c05956au: goto P_0c05956a;
case 0x0c05956cu: goto P_0c05956c;
case 0x0c05956eu: goto P_0c05956e;
case 0x0c059708u: goto P_0c059708;
case 0x0c05970au: goto P_0c05970a;
case 0x0c05970cu: goto P_0c05970c;
case 0x0c05970eu: goto P_0c05970e;
case 0x0c059710u: goto P_0c059710;
case 0x0c059712u: goto P_0c059712;
case 0x0c059714u: goto P_0c059714;
case 0x0c059716u: goto P_0c059716;
case 0x0c059718u: goto P_0c059718;
case 0x0c05971au: goto P_0c05971a;
case 0x0c05971cu: goto P_0c05971c;
case 0x0c05971eu: goto P_0c05971e;
case 0x0c059720u: goto P_0c059720;
case 0x0c059722u: goto P_0c059722;
case 0x0c059724u: goto P_0c059724;
case 0x0c059726u: goto P_0c059726;
case 0x0c059728u: goto P_0c059728;
case 0x0c05972au: goto P_0c05972a;
case 0x0c05972cu: goto P_0c05972c;
case 0x0c05972eu: goto P_0c05972e;
case 0x0c059730u: goto P_0c059730;
case 0x0c059732u: goto P_0c059732;
case 0x0c059734u: goto P_0c059734;
case 0x0c059736u: goto P_0c059736;
case 0x0c059738u: goto P_0c059738;
case 0x0c05973au: goto P_0c05973a;
case 0x0c05973cu: goto P_0c05973c;
case 0x0c05973eu: goto P_0c05973e;
case 0x0c059740u: goto P_0c059740;
case 0x0c059742u: goto P_0c059742;
case 0x0c059744u: goto P_0c059744;
case 0x0c059746u: goto P_0c059746;
case 0x0c059748u: goto P_0c059748;
case 0x0c05974au: goto P_0c05974a;
case 0x0c05974cu: goto P_0c05974c;
case 0x0c05974eu: goto P_0c05974e;
case 0x0c059750u: goto P_0c059750;
case 0x0c059752u: goto P_0c059752;
case 0x0c059754u: goto P_0c059754;
case 0x0c059756u: goto P_0c059756;
case 0x0c059758u: goto P_0c059758;
case 0x0c05975au: goto P_0c05975a;
case 0x0c05975cu: goto P_0c05975c;
case 0x0c05975eu: goto P_0c05975e;
case 0x0c059760u: goto P_0c059760;
case 0x0c059762u: goto P_0c059762;
case 0x0c059764u: goto P_0c059764;
case 0x0c059766u: goto P_0c059766;
case 0x0c059768u: goto P_0c059768;
case 0x0c05976au: goto P_0c05976a;
case 0x0c05976cu: goto P_0c05976c;
case 0x0c05976eu: goto P_0c05976e;
case 0x0c059770u: goto P_0c059770;
case 0x0c059772u: goto P_0c059772;
case 0x0c059774u: goto P_0c059774;
case 0x0c059776u: goto P_0c059776;
case 0x0c059778u: goto P_0c059778;
case 0x0c05977au: goto P_0c05977a;
case 0x0c05977cu: goto P_0c05977c;
case 0x0c05977eu: goto P_0c05977e;
case 0x0c059780u: goto P_0c059780;
case 0x0c059782u: goto P_0c059782;
case 0x0c059784u: goto P_0c059784;
case 0x0c059786u: goto P_0c059786;
case 0x0c059788u: goto P_0c059788;
case 0x0c05978au: goto P_0c05978a;
case 0x0c05978cu: goto P_0c05978c;
case 0x0c05978eu: goto P_0c05978e;
case 0x0c059790u: goto P_0c059790;
case 0x0c059792u: goto P_0c059792;
case 0x0c059794u: goto P_0c059794;
case 0x0c059796u: goto P_0c059796;
case 0x0c059798u: goto P_0c059798;
case 0x0c05979au: goto P_0c05979a;
case 0x0c05979cu: goto P_0c05979c;
case 0x0c05979eu: goto P_0c05979e;
case 0x0c0597a0u: goto P_0c0597a0;
case 0x0c0597a2u: goto P_0c0597a2;
case 0x0c0597a4u: goto P_0c0597a4;
case 0x0c0597a6u: goto P_0c0597a6;
case 0x0c0597a8u: goto P_0c0597a8;
case 0x0c0597aau: goto P_0c0597aa;
case 0x0c0597acu: goto P_0c0597ac;
case 0x0c05cb74u: goto P_0c05cb74;
case 0x0c05cb76u: goto P_0c05cb76;
case 0x0c05cb78u: goto P_0c05cb78;
case 0x0c05cb7au: goto P_0c05cb7a;
case 0x0c05cb7cu: goto P_0c05cb7c;
case 0x0c05cb7eu: goto P_0c05cb7e;
case 0x0c05cb80u: goto P_0c05cb80;
case 0x0c05cb82u: goto P_0c05cb82;
case 0x0c05cb84u: goto P_0c05cb84;
case 0x0c05cb86u: goto P_0c05cb86;
case 0x0c05cb88u: goto P_0c05cb88;
case 0x0c05cb8au: goto P_0c05cb8a;
case 0x0c05ed38u: goto P_0c05ed38;
case 0x0c05ed3au: goto P_0c05ed3a;
case 0x0c05ed3cu: goto P_0c05ed3c;
case 0x0c05ed3eu: goto P_0c05ed3e;
case 0x0c05ed40u: goto P_0c05ed40;
case 0x0c05ed42u: goto P_0c05ed42;
case 0x0c05ed44u: goto P_0c05ed44;
case 0x0c05ed46u: goto P_0c05ed46;
case 0x0c05ed48u: goto P_0c05ed48;
case 0x0c05ed4au: goto P_0c05ed4a;
case 0x0c05ed4cu: goto P_0c05ed4c;
case 0x0c05ed4eu: goto P_0c05ed4e;
case 0x0c05ed50u: goto P_0c05ed50;
case 0x0c05ed52u: goto P_0c05ed52;
case 0x0c05ed54u: goto P_0c05ed54;
case 0x0c05ed56u: goto P_0c05ed56;
case 0x0c05ed58u: goto P_0c05ed58;
case 0x0c05ed5au: goto P_0c05ed5a;
case 0x0c05ed5cu: goto P_0c05ed5c;
case 0x0c05ed5eu: goto P_0c05ed5e;
case 0x0c05ed60u: goto P_0c05ed60;
case 0x0c05ed62u: goto P_0c05ed62;
case 0x0c05ed64u: goto P_0c05ed64;
case 0x0c05ed66u: goto P_0c05ed66;
case 0x0c05ed68u: goto P_0c05ed68;
case 0x0c05ed6au: goto P_0c05ed6a;
case 0x0c05ed6cu: goto P_0c05ed6c;
case 0x0c05ed6eu: goto P_0c05ed6e;
case 0x0c05ee34u: goto P_0c05ee34;
case 0x0c05ee36u: goto P_0c05ee36;
case 0x0c05ee38u: goto P_0c05ee38;
case 0x0c05ee3au: goto P_0c05ee3a;
case 0x0c05ee3cu: goto P_0c05ee3c;
case 0x0c05ee3eu: goto P_0c05ee3e;
case 0x0c05ee40u: goto P_0c05ee40;
case 0x0c05ee42u: goto P_0c05ee42;
case 0x0c05ee44u: goto P_0c05ee44;
case 0x0c05ee46u: goto P_0c05ee46;
case 0x0c060cf6u: goto P_0c060cf6;
case 0x0c060cf8u: goto P_0c060cf8;
case 0x0c061998u: goto P_0c061998;
case 0x0c06199au: goto P_0c06199a;
case 0x0c06199cu: goto P_0c06199c;
case 0x0c06199eu: goto P_0c06199e;
case 0x0c0619a0u: goto P_0c0619a0;
case 0x0c0619a2u: goto P_0c0619a2;
case 0x0c0619a4u: goto P_0c0619a4;
case 0x0c0619a6u: goto P_0c0619a6;
case 0x0c0619a8u: goto P_0c0619a8;
case 0x0c0619aau: goto P_0c0619aa;
case 0x0c0619acu: goto P_0c0619ac;
case 0x0c0619aeu: goto P_0c0619ae;
case 0x0c0619b0u: goto P_0c0619b0;
case 0x0c0619b2u: goto P_0c0619b2;
case 0x0c0619b4u: goto P_0c0619b4;
case 0x0c0619b6u: goto P_0c0619b6;
case 0x0c0619b8u: goto P_0c0619b8;
case 0x0c0619bau: goto P_0c0619ba;
case 0x0c0619bcu: goto P_0c0619bc;
case 0x0c0619beu: goto P_0c0619be;
case 0x0c0619c0u: goto P_0c0619c0;
case 0x0c0619c2u: goto P_0c0619c2;
case 0x0c0619c4u: goto P_0c0619c4;
case 0x0c0619c6u: goto P_0c0619c6;
case 0x0c0619c8u: goto P_0c0619c8;
case 0x0c0619cau: goto P_0c0619ca;
case 0x0c0619ccu: goto P_0c0619cc;
case 0x0c0619ceu: goto P_0c0619ce;
case 0x0c0619d0u: goto P_0c0619d0;
case 0x0c0619d2u: goto P_0c0619d2;
case 0x0c0619d4u: goto P_0c0619d4;
case 0x0c0619d6u: goto P_0c0619d6;
case 0x0c0619d8u: goto P_0c0619d8;
case 0x0c0619dau: goto P_0c0619da;
case 0x0c0619dcu: goto P_0c0619dc;
case 0x0c0619deu: goto P_0c0619de;
case 0x0c0619e0u: goto P_0c0619e0;
case 0x0c0619e2u: goto P_0c0619e2;
case 0x0c0619e4u: goto P_0c0619e4;
case 0x0c0619e6u: goto P_0c0619e6;
case 0x0c0619e8u: goto P_0c0619e8;
case 0x0c0619eau: goto P_0c0619ea;
case 0x0c0619ecu: goto P_0c0619ec;
case 0x0c0619eeu: goto P_0c0619ee;
case 0x0c0619f0u: goto P_0c0619f0;
case 0x0c0619f2u: goto P_0c0619f2;
case 0x0c0619f4u: goto P_0c0619f4;
case 0x0c0619f6u: goto P_0c0619f6;
case 0x0c0619f8u: goto P_0c0619f8;
case 0x0c0619fau: goto P_0c0619fa;
case 0x0c0619fcu: goto P_0c0619fc;
case 0x0c0619feu: goto P_0c0619fe;
case 0x0c061a00u: goto P_0c061a00;
case 0x0c061a02u: goto P_0c061a02;
case 0x0c061a04u: goto P_0c061a04;
case 0x0c061a06u: goto P_0c061a06;
case 0x0c061a08u: goto P_0c061a08;
case 0x0c062ec4u: goto P_0c062ec4;
case 0x0c062ec6u: goto P_0c062ec6;
case 0x0c062ec8u: goto P_0c062ec8;
case 0x0c062ecau: goto P_0c062eca;
case 0x0c062eccu: goto P_0c062ecc;
case 0x0c062eceu: goto P_0c062ece;
case 0x0c062ed0u: goto P_0c062ed0;
case 0x0c062ed2u: goto P_0c062ed2;
case 0x0c062ed4u: goto P_0c062ed4;
case 0x0c062ed6u: goto P_0c062ed6;
case 0x0c062ed8u: goto P_0c062ed8;
case 0x0c062edau: goto P_0c062eda;
case 0x0c062edcu: goto P_0c062edc;
case 0x0c062edeu: goto P_0c062ede;
case 0x0c062ee0u: goto P_0c062ee0;
case 0x0c062ee2u: goto P_0c062ee2;
case 0x0c062ee4u: goto P_0c062ee4;
case 0x0c062ee6u: goto P_0c062ee6;
case 0x0c062ee8u: goto P_0c062ee8;
case 0x0c062eeau: goto P_0c062eea;
case 0x0c062eecu: goto P_0c062eec;
case 0x0c062eeeu: goto P_0c062eee;
case 0x0c062ef0u: goto P_0c062ef0;
case 0x0c062ef2u: goto P_0c062ef2;
case 0x0c062ef4u: goto P_0c062ef4;
case 0x0c0645fau: goto P_0c0645fa;
case 0x0c0645fcu: goto P_0c0645fc;
case 0x0c0645feu: goto P_0c0645fe;
case 0x0c064600u: goto P_0c064600;
case 0x0c064602u: goto P_0c064602;
case 0x0c064604u: goto P_0c064604;
case 0x0c064606u: goto P_0c064606;
case 0x0c064608u: goto P_0c064608;
case 0x0c06460au: goto P_0c06460a;
case 0x0c06460cu: goto P_0c06460c;
case 0x0c06460eu: goto P_0c06460e;
case 0x0c064610u: goto P_0c064610;
case 0x0c064612u: goto P_0c064612;
case 0x0c064614u: goto P_0c064614;
case 0x0c064616u: goto P_0c064616;
case 0x0c064618u: goto P_0c064618;
case 0x0c06461au: goto P_0c06461a;
case 0x0c06461cu: goto P_0c06461c;
case 0x0c06461eu: goto P_0c06461e;
case 0x0c064620u: goto P_0c064620;
case 0x0c064622u: goto P_0c064622;
case 0x0c064624u: goto P_0c064624;
case 0x0c064626u: goto P_0c064626;
case 0x0c064628u: goto P_0c064628;
case 0x0c06462au: goto P_0c06462a;
case 0x0c06462cu: goto P_0c06462c;
case 0x0c06462eu: goto P_0c06462e;
case 0x0c064630u: goto P_0c064630;
case 0x0c064632u: goto P_0c064632;
case 0x0c064634u: goto P_0c064634;
case 0x0c064636u: goto P_0c064636;
case 0x0c064638u: goto P_0c064638;
case 0x0c06463au: goto P_0c06463a;
case 0x0c06463cu: goto P_0c06463c;
case 0x0c06463eu: goto P_0c06463e;
case 0x0c064640u: goto P_0c064640;
case 0x0c064642u: goto P_0c064642;
case 0x0c064644u: goto P_0c064644;
case 0x0c064646u: goto P_0c064646;
case 0x0c064648u: goto P_0c064648;
case 0x0c06464au: goto P_0c06464a;
case 0x0c06464cu: goto P_0c06464c;
case 0x0c06464eu: goto P_0c06464e;
case 0x0c064650u: goto P_0c064650;
case 0x0c064652u: goto P_0c064652;
case 0x0c064654u: goto P_0c064654;
case 0x0c064656u: goto P_0c064656;
case 0x0c064658u: goto P_0c064658;
case 0x0c06465au: goto P_0c06465a;
case 0x0c06465cu: goto P_0c06465c;
case 0x0c06465eu: goto P_0c06465e;
case 0x0c064660u: goto P_0c064660;
case 0x0c064662u: goto P_0c064662;
case 0x0c064664u: goto P_0c064664;
case 0x0c064666u: goto P_0c064666;
case 0x0c064668u: goto P_0c064668;
case 0x0c06466au: goto P_0c06466a;
case 0x0c06466cu: goto P_0c06466c;
case 0x0c06466eu: goto P_0c06466e;
case 0x0c064670u: goto P_0c064670;
case 0x0c064672u: goto P_0c064672;
case 0x0c064674u: goto P_0c064674;
case 0x0c064676u: goto P_0c064676;
case 0x0c064678u: goto P_0c064678;
case 0x0c06467au: goto P_0c06467a;
case 0x0c06467cu: goto P_0c06467c;
case 0x0c06467eu: goto P_0c06467e;
case 0x0c064680u: goto P_0c064680;
case 0x0c064682u: goto P_0c064682;
case 0x0c064684u: goto P_0c064684;
case 0x0c064686u: goto P_0c064686;
case 0x0c064688u: goto P_0c064688;
case 0x0c06468au: goto P_0c06468a;
case 0x0c06468cu: goto P_0c06468c;
case 0x0c06468eu: goto P_0c06468e;
case 0x0c064690u: goto P_0c064690;
case 0x0c064692u: goto P_0c064692;
case 0x0c064694u: goto P_0c064694;
case 0x0c064696u: goto P_0c064696;
case 0x0c064698u: goto P_0c064698;
case 0x0c06469au: goto P_0c06469a;
case 0x0c06469cu: goto P_0c06469c;
case 0x0c06469eu: goto P_0c06469e;
case 0x0c0646a0u: goto P_0c0646a0;
case 0x0c0646a2u: goto P_0c0646a2;
case 0x0c0646a4u: goto P_0c0646a4;
case 0x0c0646a6u: goto P_0c0646a6;
case 0x0c0646a8u: goto P_0c0646a8;
case 0x0c0646aau: goto P_0c0646aa;
case 0x0c0646acu: goto P_0c0646ac;
case 0x0c0646aeu: goto P_0c0646ae;
case 0x0c0646b0u: goto P_0c0646b0;
case 0x0c0646b2u: goto P_0c0646b2;
case 0x0c0646b4u: goto P_0c0646b4;
case 0x0c0646b6u: goto P_0c0646b6;
case 0x0c0646b8u: goto P_0c0646b8;
case 0x0c0646bau: goto P_0c0646ba;
case 0x0c0646bcu: goto P_0c0646bc;
case 0x0c0646beu: goto P_0c0646be;
case 0x0c0646c0u: goto P_0c0646c0;
case 0x0c0646c2u: goto P_0c0646c2;
case 0x0c0646c4u: goto P_0c0646c4;
case 0x0c0646c6u: goto P_0c0646c6;
case 0x0c0646c8u: goto P_0c0646c8;
case 0x0c0646cau: goto P_0c0646ca;
case 0x0c0646ccu: goto P_0c0646cc;
case 0x0c0646ceu: goto P_0c0646ce;
case 0x0c0646d0u: goto P_0c0646d0;
case 0x0c0646d2u: goto P_0c0646d2;
case 0x0c0646d4u: goto P_0c0646d4;
case 0x0c0646d6u: goto P_0c0646d6;
case 0x0c0646d8u: goto P_0c0646d8;
case 0x0c0646dau: goto P_0c0646da;
case 0x0c0646dcu: goto P_0c0646dc;
case 0x0c0646deu: goto P_0c0646de;
case 0x0c0646e0u: goto P_0c0646e0;
case 0x0c0646e2u: goto P_0c0646e2;
case 0x0c0646e4u: goto P_0c0646e4;
case 0x0c0646e6u: goto P_0c0646e6;
case 0x0c0646e8u: goto P_0c0646e8;
case 0x0c0646eau: goto P_0c0646ea;
case 0x0c0646ecu: goto P_0c0646ec;
case 0x0c0646eeu: goto P_0c0646ee;
case 0x0c0646f0u: goto P_0c0646f0;
case 0x0c0646f2u: goto P_0c0646f2;
case 0x0c0646f4u: goto P_0c0646f4;
case 0x0c0646f6u: goto P_0c0646f6;
case 0x0c064930u: goto P_0c064930;
case 0x0c064932u: goto P_0c064932;
case 0x0c064934u: goto P_0c064934;
case 0x0c064936u: goto P_0c064936;
case 0x0c064938u: goto P_0c064938;
case 0x0c06493au: goto P_0c06493a;
case 0x0c06493cu: goto P_0c06493c;
case 0x0c06493eu: goto P_0c06493e;
case 0x0c064940u: goto P_0c064940;
case 0x0c064942u: goto P_0c064942;
case 0x0c064944u: goto P_0c064944;
case 0x0c064946u: goto P_0c064946;
case 0x0c064948u: goto P_0c064948;
case 0x0c06494au: goto P_0c06494a;
case 0x0c06494cu: goto P_0c06494c;
case 0x0c06494eu: goto P_0c06494e;
case 0x0c064950u: goto P_0c064950;
case 0x0c064952u: goto P_0c064952;
case 0x0c064954u: goto P_0c064954;
case 0x0c064956u: goto P_0c064956;
case 0x0c064958u: goto P_0c064958;
case 0x0c06495au: goto P_0c06495a;
case 0x0c06495cu: goto P_0c06495c;
case 0x0c06495eu: goto P_0c06495e;
case 0x0c064960u: goto P_0c064960;
case 0x0c064962u: goto P_0c064962;
case 0x0c064964u: goto P_0c064964;
case 0x0c064966u: goto P_0c064966;
case 0x0c064968u: goto P_0c064968;
case 0x0c06496au: goto P_0c06496a;
case 0x0c06496cu: goto P_0c06496c;
case 0x0c06496eu: goto P_0c06496e;
case 0x0c064970u: goto P_0c064970;
case 0x0c064972u: goto P_0c064972;
case 0x0c064974u: goto P_0c064974;
case 0x0c064976u: goto P_0c064976;
case 0x0c064978u: goto P_0c064978;
case 0x0c06497au: goto P_0c06497a;
case 0x0c06497cu: goto P_0c06497c;
case 0x0c06497eu: goto P_0c06497e;
case 0x0c064980u: goto P_0c064980;
case 0x0c064982u: goto P_0c064982;
case 0x0c064984u: goto P_0c064984;
case 0x0c064986u: goto P_0c064986;
case 0x0c064988u: goto P_0c064988;
case 0x0c06498au: goto P_0c06498a;
case 0x0c06498cu: goto P_0c06498c;
case 0x0c06498eu: goto P_0c06498e;
case 0x0c064990u: goto P_0c064990;
case 0x0c064992u: goto P_0c064992;
case 0x0c064994u: goto P_0c064994;
case 0x0c064996u: goto P_0c064996;
case 0x0c064998u: goto P_0c064998;
case 0x0c06499au: goto P_0c06499a;
case 0x0c06499cu: goto P_0c06499c;
case 0x0c06499eu: goto P_0c06499e;
case 0x0c0649a0u: goto P_0c0649a0;
case 0x0c0649a2u: goto P_0c0649a2;
case 0x0c0649a4u: goto P_0c0649a4;
case 0x0c0649a6u: goto P_0c0649a6;
case 0x0c0649a8u: goto P_0c0649a8;
case 0x0c0649aau: goto P_0c0649aa;
case 0x0c0649acu: goto P_0c0649ac;
case 0x0c0649aeu: goto P_0c0649ae;
case 0x0c0649b0u: goto P_0c0649b0;
case 0x0c0649b2u: goto P_0c0649b2;
case 0x0c0649b4u: goto P_0c0649b4;
case 0x0c0649b6u: goto P_0c0649b6;
case 0x0c0649b8u: goto P_0c0649b8;
case 0x0c0649bau: goto P_0c0649ba;
case 0x0c0649bcu: goto P_0c0649bc;
case 0x0c0649beu: goto P_0c0649be;
case 0x0c0649c0u: goto P_0c0649c0;
case 0x0c0649c2u: goto P_0c0649c2;
case 0x0c0649c4u: goto P_0c0649c4;
case 0x0c0649c6u: goto P_0c0649c6;
case 0x0c0649c8u: goto P_0c0649c8;
case 0x0c0649cau: goto P_0c0649ca;
case 0x0c0649ccu: goto P_0c0649cc;
case 0x0c0649ceu: goto P_0c0649ce;
case 0x0c0649d0u: goto P_0c0649d0;
case 0x0c0649d2u: goto P_0c0649d2;
case 0x0c0649d4u: goto P_0c0649d4;
case 0x0c0649d6u: goto P_0c0649d6;
case 0x0c0649d8u: goto P_0c0649d8;
case 0x0c0649dau: goto P_0c0649da;
case 0x0c0649dcu: goto P_0c0649dc;
case 0x0c0649deu: goto P_0c0649de;
case 0x0c0649e0u: goto P_0c0649e0;
case 0x0c0649e2u: goto P_0c0649e2;
case 0x0c0649e4u: goto P_0c0649e4;
case 0x0c0649e6u: goto P_0c0649e6;
case 0x0c0649e8u: goto P_0c0649e8;
case 0x0c0649eau: goto P_0c0649ea;
case 0x0c0649ecu: goto P_0c0649ec;
case 0x0c0649eeu: goto P_0c0649ee;
case 0x0c0649f0u: goto P_0c0649f0;
case 0x0c0649f2u: goto P_0c0649f2;
case 0x0c0649f4u: goto P_0c0649f4;
case 0x0c0649f6u: goto P_0c0649f6;
case 0x0c0649f8u: goto P_0c0649f8;
case 0x0c0649fau: goto P_0c0649fa;
case 0x0c0649fcu: goto P_0c0649fc;
case 0x0c0649feu: goto P_0c0649fe;
case 0x0c064a00u: goto P_0c064a00;
case 0x0c064a02u: goto P_0c064a02;
case 0x0c064a04u: goto P_0c064a04;
case 0x0c064a06u: goto P_0c064a06;
case 0x0c064a08u: goto P_0c064a08;
case 0x0c064a0au: goto P_0c064a0a;
case 0x0c064a0cu: goto P_0c064a0c;
case 0x0c064a0eu: goto P_0c064a0e;
case 0x0c064a10u: goto P_0c064a10;
case 0x0c064a12u: goto P_0c064a12;
case 0x0c064a14u: goto P_0c064a14;
case 0x0c064a16u: goto P_0c064a16;
case 0x0c064a18u: goto P_0c064a18;
case 0x0c064a1au: goto P_0c064a1a;
case 0x0c064a1cu: goto P_0c064a1c;
case 0x0c064a1eu: goto P_0c064a1e;
case 0x0c064a20u: goto P_0c064a20;
case 0x0c064a22u: goto P_0c064a22;
case 0x0c064a24u: goto P_0c064a24;
case 0x0c064a26u: goto P_0c064a26;
case 0x0c064a28u: goto P_0c064a28;
case 0x0c064a2au: goto P_0c064a2a;
case 0x0c064a2cu: goto P_0c064a2c;
case 0x0c064a2eu: goto P_0c064a2e;
case 0x0c064a30u: goto P_0c064a30;
case 0x0c064a32u: goto P_0c064a32;
case 0x0c064a34u: goto P_0c064a34;
case 0x0c064a36u: goto P_0c064a36;
case 0x0c064a38u: goto P_0c064a38;
case 0x0c064a3au: goto P_0c064a3a;
case 0x0c064a3cu: goto P_0c064a3c;
case 0x0c064a3eu: goto P_0c064a3e;
case 0x0c064a40u: goto P_0c064a40;
case 0x0c064a42u: goto P_0c064a42;
case 0x0c064a44u: goto P_0c064a44;
case 0x0c064a46u: goto P_0c064a46;
case 0x0c064a48u: goto P_0c064a48;
case 0x0c064a4au: goto P_0c064a4a;
case 0x0c064a4cu: goto P_0c064a4c;
case 0x0c064a4eu: goto P_0c064a4e;
case 0x0c064a50u: goto P_0c064a50;
case 0x0c064a52u: goto P_0c064a52;
case 0x0c064a54u: goto P_0c064a54;
case 0x0c064a56u: goto P_0c064a56;
case 0x0c064a58u: goto P_0c064a58;
case 0x0c064a5au: goto P_0c064a5a;
case 0x0c064a5cu: goto P_0c064a5c;
case 0x0c064a5eu: goto P_0c064a5e;
case 0x0c064a60u: goto P_0c064a60;
case 0x0c064a62u: goto P_0c064a62;
case 0x0c064a64u: goto P_0c064a64;
case 0x0c064a66u: goto P_0c064a66;
case 0x0c064a68u: goto P_0c064a68;
case 0x0c064a6au: goto P_0c064a6a;
case 0x0c064a6cu: goto P_0c064a6c;
case 0x0c064a6eu: goto P_0c064a6e;
case 0x0c064a70u: goto P_0c064a70;
case 0x0c064a72u: goto P_0c064a72;
case 0x0c064a74u: goto P_0c064a74;
case 0x0c064a76u: goto P_0c064a76;
case 0x0c064a78u: goto P_0c064a78;
case 0x0c064a7au: goto P_0c064a7a;
case 0x0c064a7cu: goto P_0c064a7c;
case 0x0c064a7eu: goto P_0c064a7e;
case 0x0c064a80u: goto P_0c064a80;
case 0x0c064a82u: goto P_0c064a82;
case 0x0c064a84u: goto P_0c064a84;
case 0x0c064a86u: goto P_0c064a86;
case 0x0c064a88u: goto P_0c064a88;
case 0x0c064a8au: goto P_0c064a8a;
case 0x0c064a8cu: goto P_0c064a8c;
case 0x0c0657fcu: goto P_0c0657fc;
case 0x0c0657feu: goto P_0c0657fe;
case 0x0c065800u: goto P_0c065800;
case 0x0c065802u: goto P_0c065802;
case 0x0c065804u: goto P_0c065804;
case 0x0c065806u: goto P_0c065806;
case 0x0c065808u: goto P_0c065808;
case 0x0c06580au: goto P_0c06580a;
case 0x0c06580cu: goto P_0c06580c;
case 0x0c06580eu: goto P_0c06580e;
case 0x0c065810u: goto P_0c065810;
case 0x0c065812u: goto P_0c065812;
case 0x0c065814u: goto P_0c065814;
case 0x0c065816u: goto P_0c065816;
case 0x0c065818u: goto P_0c065818;
case 0x0c06581au: goto P_0c06581a;
case 0x0c06581cu: goto P_0c06581c;
case 0x0c06581eu: goto P_0c06581e;
case 0x0c065820u: goto P_0c065820;
case 0x0c065822u: goto P_0c065822;
case 0x0c065824u: goto P_0c065824;
case 0x0c065826u: goto P_0c065826;
case 0x0c065828u: goto P_0c065828;
case 0x0c06582au: goto P_0c06582a;
case 0x0c06582cu: goto P_0c06582c;
case 0x0c06582eu: goto P_0c06582e;
case 0x0c065830u: goto P_0c065830;
case 0x0c065832u: goto P_0c065832;
case 0x0c065834u: goto P_0c065834;
case 0x0c065836u: goto P_0c065836;
case 0x0c065838u: goto P_0c065838;
case 0x0c06583au: goto P_0c06583a;
case 0x0c06583cu: goto P_0c06583c;
case 0x0c06583eu: goto P_0c06583e;
case 0x0c065840u: goto P_0c065840;
case 0x0c065842u: goto P_0c065842;
case 0x0c065844u: goto P_0c065844;
case 0x0c065846u: goto P_0c065846;
case 0x0c065848u: goto P_0c065848;
case 0x0c06584au: goto P_0c06584a;
case 0x0c06584cu: goto P_0c06584c;
case 0x0c06584eu: goto P_0c06584e;
case 0x0c065850u: goto P_0c065850;
case 0x0c065852u: goto P_0c065852;
case 0x0c065854u: goto P_0c065854;
case 0x0c065856u: goto P_0c065856;
case 0x0c065858u: goto P_0c065858;
case 0x0c06585au: goto P_0c06585a;
case 0x0c06585cu: goto P_0c06585c;
case 0x0c06585eu: goto P_0c06585e;
case 0x0c065860u: goto P_0c065860;
case 0x0c065862u: goto P_0c065862;
case 0x0c065864u: goto P_0c065864;
case 0x0c065866u: goto P_0c065866;
case 0x0c065868u: goto P_0c065868;
case 0x0c06586au: goto P_0c06586a;
case 0x0c06586cu: goto P_0c06586c;
case 0x0c06586eu: goto P_0c06586e;
case 0x0c065870u: goto P_0c065870;
case 0x0c065872u: goto P_0c065872;
case 0x0c065874u: goto P_0c065874;
case 0x0c065876u: goto P_0c065876;
case 0x0c065878u: goto P_0c065878;
case 0x0c06587au: goto P_0c06587a;
case 0x0c06587cu: goto P_0c06587c;
case 0x0c06587eu: goto P_0c06587e;
case 0x0c065880u: goto P_0c065880;
case 0x0c065882u: goto P_0c065882;
case 0x0c065884u: goto P_0c065884;
case 0x0c065886u: goto P_0c065886;
case 0x0c065888u: goto P_0c065888;
case 0x0c06588au: goto P_0c06588a;
case 0x0c06588cu: goto P_0c06588c;
case 0x0c06588eu: goto P_0c06588e;
case 0x0c065890u: goto P_0c065890;
case 0x0c065892u: goto P_0c065892;
case 0x0c065894u: goto P_0c065894;
case 0x0c065896u: goto P_0c065896;
case 0x0c065898u: goto P_0c065898;
case 0x0c06589au: goto P_0c06589a;
case 0x0c06589cu: goto P_0c06589c;
case 0x0c06589eu: goto P_0c06589e;
case 0x0c0658a0u: goto P_0c0658a0;
case 0x0c0658a2u: goto P_0c0658a2;
case 0x0c0658a4u: goto P_0c0658a4;
case 0x0c0658a6u: goto P_0c0658a6;
case 0x0c0658a8u: goto P_0c0658a8;
case 0x0c0658aau: goto P_0c0658aa;
case 0x0c0658acu: goto P_0c0658ac;
case 0x0c0658aeu: goto P_0c0658ae;
case 0x0c0658b0u: goto P_0c0658b0;
case 0x0c0658b2u: goto P_0c0658b2;
case 0x0c0658b4u: goto P_0c0658b4;
case 0x0c0658b6u: goto P_0c0658b6;
case 0x0c0658b8u: goto P_0c0658b8;
case 0x0c0658bau: goto P_0c0658ba;
case 0x0c0658bcu: goto P_0c0658bc;
case 0x0c0658beu: goto P_0c0658be;
case 0x0c0658c0u: goto P_0c0658c0;
case 0x0c0658c2u: goto P_0c0658c2;
case 0x0c0658c4u: goto P_0c0658c4;
case 0x0c0658c6u: goto P_0c0658c6;
case 0x0c0658c8u: goto P_0c0658c8;
case 0x0c0658cau: goto P_0c0658ca;
case 0x0c0658ccu: goto P_0c0658cc;
case 0x0c0658ceu: goto P_0c0658ce;
case 0x0c0658d0u: goto P_0c0658d0;
case 0x0c0658d2u: goto P_0c0658d2;
case 0x0c0658d4u: goto P_0c0658d4;
case 0x0c0658d6u: goto P_0c0658d6;
case 0x0c0658d8u: goto P_0c0658d8;
case 0x0c0658dau: goto P_0c0658da;
case 0x0c0658dcu: goto P_0c0658dc;
case 0x0c0658deu: goto P_0c0658de;
case 0x0c0658e0u: goto P_0c0658e0;
case 0x0c0658e2u: goto P_0c0658e2;
case 0x0c0658e4u: goto P_0c0658e4;
case 0x0c0658e6u: goto P_0c0658e6;
case 0x0c0658e8u: goto P_0c0658e8;
case 0x0c0658eau: goto P_0c0658ea;
case 0x0c0658ecu: goto P_0c0658ec;
case 0x0c0658eeu: goto P_0c0658ee;
case 0x0c0658f0u: goto P_0c0658f0;
case 0x0c0658f2u: goto P_0c0658f2;
case 0x0c0658f4u: goto P_0c0658f4;
case 0x0c0658f6u: goto P_0c0658f6;
case 0x0c0658f8u: goto P_0c0658f8;
case 0x0c0658fau: goto P_0c0658fa;
case 0x0c0658fcu: goto P_0c0658fc;
case 0x0c065932u: goto P_0c065932;
case 0x0c065934u: goto P_0c065934;
case 0x0c065936u: goto P_0c065936;
case 0x0c065938u: goto P_0c065938;
case 0x0c06593au: goto P_0c06593a;
case 0x0c06593cu: goto P_0c06593c;
case 0x0c06593eu: goto P_0c06593e;
case 0x0c065940u: goto P_0c065940;
case 0x0c065942u: goto P_0c065942;
case 0x0c065944u: goto P_0c065944;
case 0x0c065946u: goto P_0c065946;
case 0x0c065948u: goto P_0c065948;
case 0x0c06594au: goto P_0c06594a;
case 0x0c06594cu: goto P_0c06594c;
case 0x0c06594eu: goto P_0c06594e;
case 0x0c065950u: goto P_0c065950;
case 0x0c065952u: goto P_0c065952;
case 0x0c065954u: goto P_0c065954;
case 0x0c065956u: goto P_0c065956;
case 0x0c065958u: goto P_0c065958;
case 0x0c06595au: goto P_0c06595a;
case 0x0c06595cu: goto P_0c06595c;
case 0x0c06595eu: goto P_0c06595e;
case 0x0c065960u: goto P_0c065960;
case 0x0c065962u: goto P_0c065962;
case 0x0c065964u: goto P_0c065964;
case 0x0c065966u: goto P_0c065966;
case 0x0c065968u: goto P_0c065968;
case 0x0c06596au: goto P_0c06596a;
case 0x0c06596cu: goto P_0c06596c;
case 0x0c06596eu: goto P_0c06596e;
case 0x0c065970u: goto P_0c065970;
case 0x0c065972u: goto P_0c065972;
case 0x0c065974u: goto P_0c065974;
case 0x0c065976u: goto P_0c065976;
case 0x0c065978u: goto P_0c065978;
case 0x0c06597au: goto P_0c06597a;
case 0x0c06597cu: goto P_0c06597c;
case 0x0c06597eu: goto P_0c06597e;
case 0x0c065980u: goto P_0c065980;
case 0x0c065982u: goto P_0c065982;
case 0x0c065984u: goto P_0c065984;
case 0x0c065986u: goto P_0c065986;
case 0x0c065988u: goto P_0c065988;
case 0x0c06598au: goto P_0c06598a;
case 0x0c06598cu: goto P_0c06598c;
case 0x0c06598eu: goto P_0c06598e;
case 0x0c065990u: goto P_0c065990;
case 0x0c065992u: goto P_0c065992;
case 0x0c065994u: goto P_0c065994;
case 0x0c065996u: goto P_0c065996;
case 0x0c065998u: goto P_0c065998;
case 0x0c06599au: goto P_0c06599a;
case 0x0c06599cu: goto P_0c06599c;
case 0x0c06599eu: goto P_0c06599e;
case 0x0c0659a0u: goto P_0c0659a0;
case 0x0c0659a2u: goto P_0c0659a2;
case 0x0c0659a4u: goto P_0c0659a4;
case 0x0c0659a6u: goto P_0c0659a6;
case 0x0c0659a8u: goto P_0c0659a8;
case 0x0c0659aau: goto P_0c0659aa;
case 0x0c0659acu: goto P_0c0659ac;
case 0x0c0659aeu: goto P_0c0659ae;
case 0x0c0659b0u: goto P_0c0659b0;
case 0x0c0659b2u: goto P_0c0659b2;
case 0x0c0659b4u: goto P_0c0659b4;
case 0x0c0659b6u: goto P_0c0659b6;
case 0x0c0659b8u: goto P_0c0659b8;
case 0x0c0659bau: goto P_0c0659ba;
case 0x0c0659bcu: goto P_0c0659bc;
case 0x0c0659beu: goto P_0c0659be;
case 0x0c0659c0u: goto P_0c0659c0;
case 0x0c0659c2u: goto P_0c0659c2;
case 0x0c0659c4u: goto P_0c0659c4;
case 0x0c0659c6u: goto P_0c0659c6;
case 0x0c0659c8u: goto P_0c0659c8;
case 0x0c0659cau: goto P_0c0659ca;
case 0x0c0659ccu: goto P_0c0659cc;
case 0x0c0659ceu: goto P_0c0659ce;
case 0x0c0659d0u: goto P_0c0659d0;
case 0x0c0659d2u: goto P_0c0659d2;
case 0x0c0659d4u: goto P_0c0659d4;
case 0x0c0659d6u: goto P_0c0659d6;
case 0x0c0659d8u: goto P_0c0659d8;
case 0x0c0659dau: goto P_0c0659da;
case 0x0c0659dcu: goto P_0c0659dc;
case 0x0c0659deu: goto P_0c0659de;
case 0x0c0659e0u: goto P_0c0659e0;
case 0x0c0659e2u: goto P_0c0659e2;
case 0x0c0659e4u: goto P_0c0659e4;
case 0x0c0659e6u: goto P_0c0659e6;
case 0x0c0659e8u: goto P_0c0659e8;
case 0x0c0659eau: goto P_0c0659ea;
case 0x0c0659ecu: goto P_0c0659ec;
case 0x0c0659eeu: goto P_0c0659ee;
case 0x0c0659f0u: goto P_0c0659f0;
case 0x0c0659f2u: goto P_0c0659f2;
case 0x0c0659f4u: goto P_0c0659f4;
case 0x0c0659f6u: goto P_0c0659f6;
case 0x0c0659f8u: goto P_0c0659f8;
case 0x0c0659fau: goto P_0c0659fa;
case 0x0c0659fcu: goto P_0c0659fc;
case 0x0c0659feu: goto P_0c0659fe;
case 0x0c065a00u: goto P_0c065a00;
case 0x0c065a02u: goto P_0c065a02;
case 0x0c065a04u: goto P_0c065a04;
case 0x0c065a06u: goto P_0c065a06;
case 0x0c065a08u: goto P_0c065a08;
case 0x0c065a0au: goto P_0c065a0a;
case 0x0c065a0cu: goto P_0c065a0c;
case 0x0c065a0eu: goto P_0c065a0e;
case 0x0c065a10u: goto P_0c065a10;
case 0x0c065a12u: goto P_0c065a12;
case 0x0c065a14u: goto P_0c065a14;
case 0x0c065a16u: goto P_0c065a16;
case 0x0c065a18u: goto P_0c065a18;
case 0x0c065a1au: goto P_0c065a1a;
case 0x0c065a1cu: goto P_0c065a1c;
case 0x0c065a1eu: goto P_0c065a1e;
case 0x0c065a20u: goto P_0c065a20;
case 0x0c065a22u: goto P_0c065a22;
case 0x0c065a24u: goto P_0c065a24;
case 0x0c065a26u: goto P_0c065a26;
case 0x0c065a28u: goto P_0c065a28;
case 0x0c065a2au: goto P_0c065a2a;
case 0x0c065a2cu: goto P_0c065a2c;
case 0x0c065a2eu: goto P_0c065a2e;
case 0x0c065a30u: goto P_0c065a30;
case 0x0c065a32u: goto P_0c065a32;
case 0x0c065a34u: goto P_0c065a34;
case 0x0c065a36u: goto P_0c065a36;
case 0x0c065a38u: goto P_0c065a38;
case 0x0c065a3au: goto P_0c065a3a;
case 0x0c065a3cu: goto P_0c065a3c;
case 0x0c065a3eu: goto P_0c065a3e;
case 0x0c065a40u: goto P_0c065a40;
case 0x0c065a42u: goto P_0c065a42;
case 0x0c065a44u: goto P_0c065a44;
case 0x0c065a46u: goto P_0c065a46;
case 0x0c065a48u: goto P_0c065a48;
case 0x0c065a4au: goto P_0c065a4a;
case 0x0c065a4cu: goto P_0c065a4c;
case 0x0c065a4eu: goto P_0c065a4e;
case 0x0c065a50u: goto P_0c065a50;
case 0x0c065a52u: goto P_0c065a52;
case 0x0c065a54u: goto P_0c065a54;
case 0x0c065a56u: goto P_0c065a56;
case 0x0c065a58u: goto P_0c065a58;
case 0x0c065a5au: goto P_0c065a5a;
case 0x0c065a5cu: goto P_0c065a5c;
case 0x0c065a5eu: goto P_0c065a5e;
case 0x0c065a60u: goto P_0c065a60;
case 0x0c065a62u: goto P_0c065a62;
case 0x0c065a64u: goto P_0c065a64;
case 0x0c065a66u: goto P_0c065a66;
case 0x0c065a68u: goto P_0c065a68;
case 0x0c065a6au: goto P_0c065a6a;
case 0x0c065a6cu: goto P_0c065a6c;
case 0x0c065a6eu: goto P_0c065a6e;
case 0x0c065a70u: goto P_0c065a70;
case 0x0c065a72u: goto P_0c065a72;
case 0x0c065a74u: goto P_0c065a74;
case 0x0c065a76u: goto P_0c065a76;
case 0x0c065a78u: goto P_0c065a78;
case 0x0c065a7au: goto P_0c065a7a;
case 0x0c065a7cu: goto P_0c065a7c;
case 0x0c065a7eu: goto P_0c065a7e;
case 0x0c065a80u: goto P_0c065a80;
case 0x0c065a82u: goto P_0c065a82;
case 0x0c065a84u: goto P_0c065a84;
case 0x0c065a86u: goto P_0c065a86;
case 0x0c065a88u: goto P_0c065a88;
case 0x0c065a8au: goto P_0c065a8a;
case 0x0c065a8cu: goto P_0c065a8c;
case 0x0c065a8eu: goto P_0c065a8e;
case 0x0c065a90u: goto P_0c065a90;
case 0x0c065a92u: goto P_0c065a92;
default: return vf3_matrix_family(target,s,ram);
}
P_0c058790: /* original 4f22, guest PC 0x0c058790 */
if(!s->budget--) { s->failed_pc=0x0c058790u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c058792;
P_0c058792: /* original a0f1, guest PC 0x0c058792 */
if(!s->budget--) { s->failed_pc=0x0c058792u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c058978;
P_0c058794: /* original 4f22, guest PC 0x0c058794 */
if(!s->budget--) { s->failed_pc=0x0c058794u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
return vf3_matrix_family(0x0c058796u,s,ram);
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
r[12]-=4; write(ram,r[12],r[0],4);
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
r[12]-=4; write(ram,r[12],r[10],4);
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
r[12]-=4; write(ram,r[12],r[12],4);
goto P_0c0588c2;
P_0c0588c2: /* original 0c83, guest PC 0x0c0588c2 */
if(!s->budget--) { s->failed_pc=0x0c0588c2u; return 0; }
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
P_0c058978: /* original be70, guest PC 0x0c058978 */
if(!s->budget--) { s->failed_pc=0x0c058978u; return 0; }
target=0x0c05865cu; r[16]=0x0c05897cu;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05897cu) { target=s->pc; goto dispatch; }
goto P_0c05897c;
P_0c05897a: /* original 65e3, guest PC 0x0c05897a */
if(!s->budget--) { s->failed_pc=0x0c05897au; return 0; }
r[5]=r[14];
goto P_0c05897c;
P_0c05897c: /* original 2f06, guest PC 0x0c05897c */
if(!s->budget--) { s->failed_pc=0x0c05897cu; return 0; }
r[15]-=4; write(ram,r[15],r[0],4);
goto P_0c05897e;
P_0c05897e: /* original e008, guest PC 0x0c05897e */
if(!s->budget--) { s->failed_pc=0x0c05897eu; return 0; }
r[0]=0x00000008u;
goto P_0c058980;
P_0c058980: /* original f086, guest PC 0x0c058980 */
if(!s->budget--) { s->failed_pc=0x0c058980u; return 0; }
vf3_matrix_load(s,ram,0,r[8]+r[0]);
goto P_0c058982;
P_0c058982: /* original 62e3, guest PC 0x0c058982 */
if(!s->budget--) { s->failed_pc=0x0c058982u; return 0; }
r[2]=r[14];
goto P_0c058984;
P_0c058984: /* original fb9d, guest PC 0x0c058984 */
if(!s->budget--) { s->failed_pc=0x0c058984u; return 0; }
fr[11]=0x3f800000u;
goto P_0c058986;
P_0c058986: /* original 6563, guest PC 0x0c058986 */
if(!s->budget--) { s->failed_pc=0x0c058986u; return 0; }
r[5]=r[6];
goto P_0c058988;
P_0c058988: /* original bdba, guest PC 0x0c058988 */
if(!s->budget--) { s->failed_pc=0x0c058988u; return 0; }
target=0x0c058500u; r[16]=0x0c05898cu;
fr[11]=vf3_fpu_binary(fr[11],fr[0],r[18],'/');
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05898cu) { target=s->pc; goto dispatch; }
goto P_0c05898c;
P_0c05898a: /* original fb03, guest PC 0x0c05898a */
if(!s->budget--) { s->failed_pc=0x0c05898au; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[0],r[18],'/');
goto P_0c05898c;
P_0c05898c: /* original fa9d, guest PC 0x0c05898c */
if(!s->budget--) { s->failed_pc=0x0c05898cu; return 0; }
fr[10]=0x3f800000u;
goto P_0c05898e;
P_0c05898e: /* original f80c, guest PC 0x0c05898e */
if(!s->budget--) { s->failed_pc=0x0c05898eu; return 0; }
vf3_matrix_move(s,8,0);
goto P_0c058990;
P_0c058990: /* original fa23, guest PC 0x0c058990 */
if(!s->budget--) { s->failed_pc=0x0c058990u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[2],r[18],'/');
goto P_0c058992;
P_0c058992: /* original 62e3, guest PC 0x0c058992 */
if(!s->budget--) { s->failed_pc=0x0c058992u; return 0; }
r[2]=r[14];
goto P_0c058994;
P_0c058994: /* original 0c83, guest PC 0x0c058994 */
if(!s->budget--) { s->failed_pc=0x0c058994u; return 0; }
goto P_0c058996;
P_0c058996: /* original 72d0, guest PC 0x0c058996 */
if(!s->budget--) { s->failed_pc=0x0c058996u; return 0; }
r[2]+=0xffffffd0u;
goto P_0c058998;
P_0c058998: /* original 6025, guest PC 0x0c058998 */
if(!s->budget--) { s->failed_pc=0x0c058998u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[0]=tmp;
goto P_0c05899a;
P_0c05899a: /* original 6121, guest PC 0x0c05899a */
if(!s->budget--) { s->failed_pc=0x0c05899au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[1]=tmp;
goto P_0c05899c;
P_0c05899c: /* original f688, guest PC 0x0c05899c */
if(!s->budget--) { s->failed_pc=0x0c05899cu; return 0; }
vf3_matrix_load(s,ram,6,r[8]);
goto P_0c05899e;
P_0c05899e: /* original 7216, guest PC 0x0c05899e */
if(!s->budget--) { s->failed_pc=0x0c05899eu; return 0; }
r[2]+=0x00000016u;
goto P_0c0589a0;
P_0c0589a0: /* original f298, guest PC 0x0c0589a0 */
if(!s->budget--) { s->failed_pc=0x0c0589a0u; return 0; }
vf3_matrix_load(s,ram,2,r[9]);
goto P_0c0589a2;
P_0c0589a2: /* original f3fd, guest PC 0x0c0589a2 */
if(!s->budget--) { s->failed_pc=0x0c0589a2u; return 0; }
r[18]^=0x100000u;
goto P_0c0589a4;
P_0c0589a4: /* original 405a, guest PC 0x0c0589a4 */
if(!s->budget--) { s->failed_pc=0x0c0589a4u; return 0; }
r[53]=r[0];
goto P_0c0589a6;
P_0c0589a6: /* original fc2d, guest PC 0x0c0589a6 */
if(!s->budget--) { s->failed_pc=0x0c0589a6u; return 0; }
fr[12]=vf3_fpu_float(r[53],r[18]);
goto P_0c0589a8;
P_0c0589a8: /* original 415a, guest PC 0x0c0589a8 */
if(!s->budget--) { s->failed_pc=0x0c0589a8u; return 0; }
r[53]=r[1];
goto P_0c0589aa;
P_0c0589aa: /* original fd2d, guest PC 0x0c0589aa */
if(!s->budget--) { s->failed_pc=0x0c0589aau; return 0; }
fr[13]=vf3_fpu_float(r[53],r[18]);
goto P_0c0589ac;
P_0c0589ac: /* original e008, guest PC 0x0c0589ac */
if(!s->budget--) { s->failed_pc=0x0c0589acu; return 0; }
r[0]=0x00000008u;
goto P_0c0589ae;
P_0c0589ae: /* original f6b2, guest PC 0x0c0589ae */
if(!s->budget--) { s->failed_pc=0x0c0589aeu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[11],r[18],'*');
goto P_0c0589b0;
P_0c0589b0: /* original fe96, guest PC 0x0c0589b0 */
if(!s->budget--) { s->failed_pc=0x0c0589b0u; return 0; }
vf3_matrix_load(s,ram,14,r[9]+r[0]);
goto P_0c0589b2;
P_0c0589b2: /* original f7b2, guest PC 0x0c0589b2 */
if(!s->budget--) { s->failed_pc=0x0c0589b2u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[11],r[18],'*');
goto P_0c0589b4;
P_0c0589b4: /* original c607, guest PC 0x0c0589b4 */
if(!s->budget--) { s->failed_pc=0x0c0589b4u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+28,4);
goto P_0c0589b6;
P_0c0589b6: /* original fcf2, guest PC 0x0c0589b6 */
if(!s->budget--) { s->failed_pc=0x0c0589b6u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[15],r[18],'*');
goto P_0c0589b8;
P_0c0589b8: /* original 7c2c, guest PC 0x0c0589b8 */
if(!s->budget--) { s->failed_pc=0x0c0589b8u; return 0; }
r[12]+=0x0000002cu;
goto P_0c0589ba;
P_0c0589ba: /* original fdf2, guest PC 0x0c0589ba */
if(!s->budget--) { s->failed_pc=0x0c0589bau; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[15],r[18],'*');
goto P_0c0589bc;
P_0c0589bc: /* original 405a, guest PC 0x0c0589bc */
if(!s->budget--) { s->failed_pc=0x0c0589bcu; return 0; }
r[53]=r[0];
goto P_0c0589be;
P_0c0589be: /* original fba1, guest PC 0x0c0589be */
if(!s->budget--) { s->failed_pc=0x0c0589beu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[10],r[18],'-');
goto P_0c0589c0;
P_0c0589c0: /* original f00d, guest PC 0x0c0589c0 */
if(!s->budget--) { s->failed_pc=0x0c0589c0u; return 0; }
fr[0]=r[53];
goto P_0c0589c2;
P_0c0589c2: /* original 2ca2, guest PC 0x0c0589c2 */
if(!s->budget--) { s->failed_pc=0x0c0589c2u; return 0; }
write(ram,r[12],r[10],4);
goto P_0c0589c4;
P_0c0589c4: /* original f0a1, guest PC 0x0c0589c4 */
if(!s->budget--) { s->failed_pc=0x0c0589c4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[10],r[18],'-');
goto P_0c0589c6;
P_0c0589c6: /* original 6125, guest PC 0x0c0589c6 */
if(!s->budget--) { s->failed_pc=0x0c0589c6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]+=2;
r[1]=tmp;
goto P_0c0589c8;
P_0c0589c8: /* original 6221, guest PC 0x0c0589c8 */
if(!s->budget--) { s->failed_pc=0x0c0589c8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[2]=tmp;
goto P_0c0589ca;
P_0c0589ca: /* original f9a2, guest PC 0x0c0589ca */
if(!s->budget--) { s->failed_pc=0x0c0589cau; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[10],r[18],'*');
goto P_0c0589cc;
P_0c0589cc: /* original f01d, guest PC 0x0c0589cc */
if(!s->budget--) { s->failed_pc=0x0c0589ccu; return 0; }
r[53]=fr[0];
goto P_0c0589ce;
P_0c0589ce: /* original f0b3, guest PC 0x0c0589ce */
if(!s->budget--) { s->failed_pc=0x0c0589ceu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'/');
goto P_0c0589d0;
P_0c0589d0: /* original f8a2, guest PC 0x0c0589d0 */
if(!s->budget--) { s->failed_pc=0x0c0589d0u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[10],r[18],'*');
goto P_0c0589d2;
P_0c0589d2: /* original f1ec, guest PC 0x0c0589d2 */
if(!s->budget--) { s->failed_pc=0x0c0589d2u; return 0; }
vf3_matrix_move(s,1,14);
goto P_0c0589d4;
P_0c0589d4: /* original fe9d, guest PC 0x0c0589d4 */
if(!s->budget--) { s->failed_pc=0x0c0589d4u; return 0; }
fr[14]=0x3f800000u;
goto P_0c0589d6;
P_0c0589d6: /* original fe13, guest PC 0x0c0589d6 */
if(!s->budget--) { s->failed_pc=0x0c0589d6u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[1],r[18],'/');
goto P_0c0589d8;
P_0c0589d8: /* original 7c08, guest PC 0x0c0589d8 */
if(!s->budget--) { s->failed_pc=0x0c0589d8u; return 0; }
r[12]+=0x00000008u;
goto P_0c0589da;
P_0c0589da: /* original f791, guest PC 0x0c0589da */
if(!s->budget--) { s->failed_pc=0x0c0589dau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[9],r[18],'-');
goto P_0c0589dc;
P_0c0589dc: /* original f681, guest PC 0x0c0589dc */
if(!s->budget--) { s->failed_pc=0x0c0589dcu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[8],r[18],'-');
goto P_0c0589de;
P_0c0589de: /* original fd51, guest PC 0x0c0589de */
if(!s->budget--) { s->failed_pc=0x0c0589deu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[5],r[18],'-');
goto P_0c0589e0;
P_0c0589e0: /* original fc41, guest PC 0x0c0589e0 */
if(!s->budget--) { s->failed_pc=0x0c0589e0u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'-');
goto P_0c0589e2;
P_0c0589e2: /* original f19c, guest PC 0x0c0589e2 */
if(!s->budget--) { s->failed_pc=0x0c0589e2u; return 0; }
vf3_matrix_move(s,1,9);
goto P_0c0589e4;
P_0c0589e4: /* original f17e, guest PC 0x0c0589e4 */
if(!s->budget--) { s->failed_pc=0x0c0589e4u; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[7],fr[1],r[18]);
goto P_0c0589e6;
P_0c0589e6: /* original f78c, guest PC 0x0c0589e6 */
if(!s->budget--) { s->failed_pc=0x0c0589e6u; return 0; }
vf3_matrix_move(s,7,8);
goto P_0c0589e8;
P_0c0589e8: /* original f76e, guest PC 0x0c0589e8 */
if(!s->budget--) { s->failed_pc=0x0c0589e8u; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[6],fr[7],r[18]);
goto P_0c0589ea;
P_0c0589ea: /* original f65c, guest PC 0x0c0589ea */
if(!s->budget--) { s->failed_pc=0x0c0589eau; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c0589ec;
P_0c0589ec: /* original f6de, guest PC 0x0c0589ec */
if(!s->budget--) { s->failed_pc=0x0c0589ecu; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[13],fr[6],r[18]);
goto P_0c0589ee;
P_0c0589ee: /* original fd4c, guest PC 0x0c0589ee */
if(!s->budget--) { s->failed_pc=0x0c0589eeu; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c0589f0;
P_0c0589f0: /* original fdce, guest PC 0x0c0589f0 */
if(!s->budget--) { s->failed_pc=0x0c0589f0u; return 0; }
fr[13]=vf3_fpu_mac(fr[0],fr[12],fr[13],r[18]);
goto P_0c0589f2;
P_0c0589f2: /* original f00d, guest PC 0x0c0589f2 */
if(!s->budget--) { s->failed_pc=0x0c0589f2u; return 0; }
fr[0]=r[53];
goto P_0c0589f4;
P_0c0589f4: /* original f3e2, guest PC 0x0c0589f4 */
if(!s->budget--) { s->failed_pc=0x0c0589f4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'*');
goto P_0c0589f6;
P_0c0589f6: /* original 4a5a, guest PC 0x0c0589f6 */
if(!s->budget--) { s->failed_pc=0x0c0589f6u; return 0; }
r[53]=r[10];
goto P_0c0589f8;
P_0c0589f8: /* original f2e2, guest PC 0x0c0589f8 */
if(!s->budget--) { s->failed_pc=0x0c0589f8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[14],r[18],'*');
goto P_0c0589fa;
P_0c0589fa: /* original fc0d, guest PC 0x0c0589fa */
if(!s->budget--) { s->failed_pc=0x0c0589fau; return 0; }
fr[12]=r[53];
goto P_0c0589fc;
P_0c0589fc: /* original fea1, guest PC 0x0c0589fc */
if(!s->budget--) { s->failed_pc=0x0c0589fcu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[10],r[18],'-');
goto P_0c0589fe;
P_0c0589fe: /* original fc6a, guest PC 0x0c0589fe */
if(!s->budget--) { s->failed_pc=0x0c0589feu; return 0; }
vf3_matrix_store(s,ram,6,r[12]);
goto P_0c058a00;
P_0c058a00: /* original f1c2, guest PC 0x0c058a00 */
if(!s->budget--) { s->failed_pc=0x0c058a00u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[12],r[18],'*');
goto P_0c058a02;
P_0c058a02: /* original fcdb, guest PC 0x0c058a02 */
if(!s->budget--) { s->failed_pc=0x0c058a02u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[12]);
goto P_0c058a04;
P_0c058a04: /* original f7c2, guest PC 0x0c058a04 */
if(!s->budget--) { s->failed_pc=0x0c058a04u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[12],r[18],'*');
goto P_0c058a06;
P_0c058a06: /* original 2ca6, guest PC 0x0c058a06 */
if(!s->budget--) { s->failed_pc=0x0c058a06u; return 0; }
r[12]-=4; write(ram,r[12],r[10],4);
goto P_0c058a08;
P_0c058a08: /* original f0e3, guest PC 0x0c058a08 */
if(!s->budget--) { s->failed_pc=0x0c058a08u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[14],r[18],'/');
goto P_0c058a0a;
P_0c058a0a: /* original 425a, guest PC 0x0c058a0a */
if(!s->budget--) { s->failed_pc=0x0c058a0au; return 0; }
r[53]=r[2];
goto P_0c058a0c;
P_0c058a0c: /* original fe2d, guest PC 0x0c058a0c */
if(!s->budget--) { s->failed_pc=0x0c058a0cu; return 0; }
fr[14]=vf3_fpu_float(r[53],r[18]);
goto P_0c058a0e;
P_0c058a0e: /* original 415a, guest PC 0x0c058a0e */
if(!s->budget--) { s->failed_pc=0x0c058a0eu; return 0; }
r[53]=r[1];
goto P_0c058a10;
P_0c058a10: /* original fd2d, guest PC 0x0c058a10 */
if(!s->budget--) { s->failed_pc=0x0c058a10u; return 0; }
fr[13]=vf3_fpu_float(r[53],r[18]);
goto P_0c058a12;
P_0c058a12: /* original fc1b, guest PC 0x0c058a12 */
if(!s->budget--) { s->failed_pc=0x0c058a12u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[12]);
goto P_0c058a14;
P_0c058a14: /* original f391, guest PC 0x0c058a14 */
if(!s->budget--) { s->failed_pc=0x0c058a14u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[9],r[18],'-');
goto P_0c058a16;
P_0c058a16: /* original fc7b, guest PC 0x0c058a16 */
if(!s->budget--) { s->failed_pc=0x0c058a16u; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,7,r[12]);
goto P_0c058a18;
P_0c058a18: /* original f281, guest PC 0x0c058a18 */
if(!s->budget--) { s->failed_pc=0x0c058a18u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[8],r[18],'-');
goto P_0c058a1a;
P_0c058a1a: /* original 2cc6, guest PC 0x0c058a1a */
if(!s->budget--) { s->failed_pc=0x0c058a1au; return 0; }
r[12]-=4; write(ram,r[12],r[12],4);
goto P_0c058a1c;
P_0c058a1c: /* original 0c83, guest PC 0x0c058a1c */
if(!s->budget--) { s->failed_pc=0x0c058a1cu; return 0; }
goto P_0c058a1e;
P_0c058a1e: /* original fef2, guest PC 0x0c058a1e */
if(!s->budget--) { s->failed_pc=0x0c058a1eu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c058a20;
P_0c058a20: /* original 61f6, guest PC 0x0c058a20 */
if(!s->budget--) { s->failed_pc=0x0c058a20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c058a22;
P_0c058a22: /* original fdf2, guest PC 0x0c058a22 */
if(!s->budget--) { s->failed_pc=0x0c058a22u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[15],r[18],'*');
goto P_0c058a24;
P_0c058a24: /* original 4f26, guest PC 0x0c058a24 */
if(!s->budget--) { s->failed_pc=0x0c058a24u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c058a26;
P_0c058a26: /* original fe51, guest PC 0x0c058a26 */
if(!s->budget--) { s->failed_pc=0x0c058a26u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[5],r[18],'-');
goto P_0c058a28;
P_0c058a28: /* original c618, guest PC 0x0c058a28 */
if(!s->budget--) { s->failed_pc=0x0c058a28u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=read(ram,s->gbr+96,4);
goto P_0c058a2a;
P_0c058a2a: /* original fd41, guest PC 0x0c058a2a */
if(!s->budget--) { s->failed_pc=0x0c058a2au; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[4],r[18],'-');
goto P_0c058a2c;
P_0c058a2c: /* original 7c2c, guest PC 0x0c058a2c */
if(!s->budget--) { s->failed_pc=0x0c058a2cu; return 0; }
r[12]+=0x0000002cu;
goto P_0c058a2e;
P_0c058a2e: /* original f93e, guest PC 0x0c058a2e */
if(!s->budget--) { s->failed_pc=0x0c058a2eu; return 0; }
fr[9]=vf3_fpu_mac(fr[0],fr[3],fr[9],r[18]);
goto P_0c058a30;
P_0c058a30: /* original 1c14, guest PC 0x0c058a30 */
if(!s->budget--) { s->failed_pc=0x0c058a30u; return 0; }
write(ram,r[12]+16,r[1],4);
goto P_0c058a32;
P_0c058a32: /* original f82e, guest PC 0x0c058a32 */
if(!s->budget--) { s->failed_pc=0x0c058a32u; return 0; }
fr[8]=vf3_fpu_mac(fr[0],fr[2],fr[8],r[18]);
goto P_0c058a34;
P_0c058a34: /* original 2ca2, guest PC 0x0c058a34 */
if(!s->budget--) { s->failed_pc=0x0c058a34u; return 0; }
write(ram,r[12],r[10],4);
goto P_0c058a36;
P_0c058a36: /* original f5ee, guest PC 0x0c058a36 */
if(!s->budget--) { s->failed_pc=0x0c058a36u; return 0; }
fr[5]=vf3_fpu_mac(fr[0],fr[14],fr[5],r[18]);
goto P_0c058a38;
P_0c058a38: /* original 1c03, guest PC 0x0c058a38 */
if(!s->budget--) { s->failed_pc=0x0c058a38u; return 0; }
write(ram,r[12]+12,r[0],4);
goto P_0c058a3a;
P_0c058a3a: /* original f4de, guest PC 0x0c058a3a */
if(!s->budget--) { s->failed_pc=0x0c058a3au; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[13],fr[4],r[18]);
goto P_0c058a3c;
P_0c058a3c: /* original f9c2, guest PC 0x0c058a3c */
if(!s->budget--) { s->failed_pc=0x0c058a3cu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[12],r[18],'*');
goto P_0c058a3e;
P_0c058a3e: /* original 7c08, guest PC 0x0c058a3e */
if(!s->budget--) { s->failed_pc=0x0c058a3eu; return 0; }
r[12]+=0x00000008u;
goto P_0c058a40;
P_0c058a40: /* original f8c2, guest PC 0x0c058a40 */
if(!s->budget--) { s->failed_pc=0x0c058a40u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[12],r[18],'*');
goto P_0c058a42;
P_0c058a42: /* original e0fc, guest PC 0x0c058a42 */
if(!s->budget--) { s->failed_pc=0x0c058a42u; return 0; }
r[0]=0xfffffffcu;
goto P_0c058a44;
P_0c058a44: /* original fc5a, guest PC 0x0c058a44 */
if(!s->budget--) { s->failed_pc=0x0c058a44u; return 0; }
vf3_matrix_store(s,ram,5,r[12]);
goto P_0c058a46;
P_0c058a46: /* original fc47, guest PC 0x0c058a46 */
if(!s->budget--) { s->failed_pc=0x0c058a46u; return 0; }
vf3_matrix_store(s,ram,4,r[12]+r[0]);
goto P_0c058a48;
P_0c058a48: /* original 7cf4, guest PC 0x0c058a48 */
if(!s->budget--) { s->failed_pc=0x0c058a48u; return 0; }
r[12]+=0xfffffff4u;
goto P_0c058a4a;
P_0c058a4a: /* original fc9a, guest PC 0x0c058a4a */
if(!s->budget--) { s->failed_pc=0x0c058a4au; return 0; }
vf3_matrix_store(s,ram,9,r[12]);
goto P_0c058a4c;
P_0c058a4c: /* original fc8b, guest PC 0x0c058a4c */
if(!s->budget--) { s->failed_pc=0x0c058a4cu; return 0; }
r[12]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[12]);
goto P_0c058a4e;
P_0c058a4e: /* original f3fd, guest PC 0x0c058a4e */
if(!s->budget--) { s->failed_pc=0x0c058a4eu; return 0; }
r[18]^=0x100000u;
goto P_0c058a50;
P_0c058a50: /* original 7cfc, guest PC 0x0c058a50 */
if(!s->budget--) { s->failed_pc=0x0c058a50u; return 0; }
r[12]+=0xfffffffcu;
goto P_0c058a52;
P_0c058a52: /* original f498, guest PC 0x0c058a52 */
if(!s->budget--) { s->failed_pc=0x0c058a52u; return 0; }
vf3_matrix_load(s,ram,4,r[9]);
goto P_0c058a54;
P_0c058a54: /* original 000b, guest PC 0x0c058a54 */
if(!s->budget--) { s->failed_pc=0x0c058a54u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,8,r[6]);
s->pc=target; return ram->oob==0;
P_0c058a56: /* original f868, guest PC 0x0c058a56 */
if(!s->budget--) { s->failed_pc=0x0c058a56u; return 0; }
vf3_matrix_load(s,ram,8,r[6]);
return vf3_matrix_family(0x0c058a58u,s,ram);
P_0c0594b4: /* original 4f22, guest PC 0x0c0594b4 */
if(!s->budget--) { s->failed_pc=0x0c0594b4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0594b6;
P_0c0594b6: /* original 0002, guest PC 0x0c0594b6 */
if(!s->budget--) { s->failed_pc=0x0c0594b6u; return 0; }
r[0]=r[17];
goto P_0c0594b8;
P_0c0594b8: /* original 9372, guest PC 0x0c0594b8 */
if(!s->budget--) { s->failed_pc=0x0c0594b8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0595a0u,2);
goto P_0c0594ba;
P_0c0594ba: /* original 7ff8, guest PC 0x0c0594ba */
if(!s->budget--) { s->failed_pc=0x0c0594bau; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0594bc;
P_0c0594bc: /* original 4009, guest PC 0x0c0594bc */
if(!s->budget--) { s->failed_pc=0x0c0594bcu; return 0; }
r[0]>>=2;
goto P_0c0594be;
P_0c0594be: /* original 4009, guest PC 0x0c0594be */
if(!s->budget--) { s->failed_pc=0x0c0594beu; return 0; }
r[0]>>=2;
goto P_0c0594c0;
P_0c0594c0: /* original c90f, guest PC 0x0c0594c0 */
if(!s->budget--) { s->failed_pc=0x0c0594c0u; return 0; }
r[0]&=15u;
goto P_0c0594c2;
P_0c0594c2: /* original 2f02, guest PC 0x0c0594c2 */
if(!s->budget--) { s->failed_pc=0x0c0594c2u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0594c4;
P_0c0594c4: /* original 0002, guest PC 0x0c0594c4 */
if(!s->budget--) { s->failed_pc=0x0c0594c4u; return 0; }
r[0]=r[17];
goto P_0c0594c6;
P_0c0594c6: /* original 2039, guest PC 0x0c0594c6 */
if(!s->budget--) { s->failed_pc=0x0c0594c6u; return 0; }
r[0]&=r[3];
goto P_0c0594c8;
P_0c0594c8: /* original cbf0, guest PC 0x0c0594c8 */
if(!s->budget--) { s->failed_pc=0x0c0594c8u; return 0; }
r[0]|=240u;
goto P_0c0594ca;
P_0c0594ca: /* original 400e, guest PC 0x0c0594ca */
if(!s->budget--) { s->failed_pc=0x0c0594cau; return 0; }
r[17]=r[0];
goto P_0c0594cc;
P_0c0594cc: /* original 2668, guest PC 0x0c0594cc */
if(!s->budget--) { s->failed_pc=0x0c0594ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0594ce;
P_0c0594ce: /* original 890c, guest PC 0x0c0594ce */
if(!s->budget--) { s->failed_pc=0x0c0594ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0594ea; }
goto P_0c0594d0;
P_0c0594d0: /* original 9367, guest PC 0x0c0594d0 */
if(!s->budget--) { s->failed_pc=0x0c0594d0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0595a2u,2);
goto P_0c0594d2;
P_0c0594d2: /* original 4508, guest PC 0x0c0594d2 */
if(!s->budget--) { s->failed_pc=0x0c0594d2u; return 0; }
r[5]<<=2;
goto P_0c0594d4;
P_0c0594d4: /* original 9265, guest PC 0x0c0594d4 */
if(!s->budget--) { s->failed_pc=0x0c0594d4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0595a2u,2);
goto P_0c0594d6;
P_0c0594d6: /* original 334c, guest PC 0x0c0594d6 */
if(!s->budget--) { s->failed_pc=0x0c0594d6u; return 0; }
r[3]+=r[4];
goto P_0c0594d8;
P_0c0594d8: /* original 4500, guest PC 0x0c0594d8 */
if(!s->budget--) { s->failed_pc=0x0c0594d8u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0594da;
P_0c0594da: /* original 324c, guest PC 0x0c0594da */
if(!s->budget--) { s->failed_pc=0x0c0594dau; return 0; }
r[2]+=r[4];
goto P_0c0594dc;
P_0c0594dc: /* original 1f51, guest PC 0x0c0594dc */
if(!s->budget--) { s->failed_pc=0x0c0594dcu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0594de;
P_0c0594de: /* original 353c, guest PC 0x0c0594de */
if(!s->budget--) { s->failed_pc=0x0c0594deu; return 0; }
r[5]+=r[3];
goto P_0c0594e0;
P_0c0594e0: /* original 2562, guest PC 0x0c0594e0 */
if(!s->budget--) { s->failed_pc=0x0c0594e0u; return 0; }
write(ram,r[5],r[6],4);
goto P_0c0594e2;
P_0c0594e2: /* original 53f1, guest PC 0x0c0594e2 */
if(!s->budget--) { s->failed_pc=0x0c0594e2u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0594e4;
P_0c0594e4: /* original 323c, guest PC 0x0c0594e4 */
if(!s->budget--) { s->failed_pc=0x0c0594e4u; return 0; }
r[2]+=r[3];
goto P_0c0594e6;
P_0c0594e6: /* original a002, guest PC 0x0c0594e6 */
if(!s->budget--) { s->failed_pc=0x0c0594e6u; return 0; }
write(ram,r[2]+4,r[7],4);
goto P_0c0594ee;
P_0c0594e8: /* original 1271, guest PC 0x0c0594e8 */
if(!s->budget--) { s->failed_pc=0x0c0594e8u; return 0; }
write(ram,r[2]+4,r[7],4);
goto P_0c0594ea;
P_0c0594ea: /* original bf89, guest PC 0x0c0594ea */
if(!s->budget--) { s->failed_pc=0x0c0594eau; return 0; }
target=0x0c059400u; r[16]=0x0c0594eeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0594eeu) { target=s->pc; goto dispatch; }
goto P_0c0594ee;
P_0c0594ec: /* original 0009, guest PC 0x0c0594ec */
if(!s->budget--) { s->failed_pc=0x0c0594ecu; return 0; }
goto P_0c0594ee;
P_0c0594ee: /* original 0302, guest PC 0x0c0594ee */
if(!s->budget--) { s->failed_pc=0x0c0594eeu; return 0; }
r[3]=r[17];
goto P_0c0594f0;
P_0c0594f0: /* original 9256, guest PC 0x0c0594f0 */
if(!s->budget--) { s->failed_pc=0x0c0594f0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0595a0u,2);
goto P_0c0594f2;
P_0c0594f2: /* original 60f2, guest PC 0x0c0594f2 */
if(!s->budget--) { s->failed_pc=0x0c0594f2u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0594f4;
P_0c0594f4: /* original c90f, guest PC 0x0c0594f4 */
if(!s->budget--) { s->failed_pc=0x0c0594f4u; return 0; }
r[0]&=15u;
goto P_0c0594f6;
P_0c0594f6: /* original 4008, guest PC 0x0c0594f6 */
if(!s->budget--) { s->failed_pc=0x0c0594f6u; return 0; }
r[0]<<=2;
goto P_0c0594f8;
P_0c0594f8: /* original 4008, guest PC 0x0c0594f8 */
if(!s->budget--) { s->failed_pc=0x0c0594f8u; return 0; }
r[0]<<=2;
goto P_0c0594fa;
P_0c0594fa: /* original 2329, guest PC 0x0c0594fa */
if(!s->budget--) { s->failed_pc=0x0c0594fau; return 0; }
r[3]&=r[2];
goto P_0c0594fc;
P_0c0594fc: /* original 203b, guest PC 0x0c0594fc */
if(!s->budget--) { s->failed_pc=0x0c0594fcu; return 0; }
r[0]|=r[3];
goto P_0c0594fe;
P_0c0594fe: /* original 400e, guest PC 0x0c0594fe */
if(!s->budget--) { s->failed_pc=0x0c0594feu; return 0; }
r[17]=r[0];
goto P_0c059500;
P_0c059500: /* original 7f08, guest PC 0x0c059500 */
if(!s->budget--) { s->failed_pc=0x0c059500u; return 0; }
r[15]+=0x00000008u;
goto P_0c059502;
P_0c059502: /* original 4f26, guest PC 0x0c059502 */
if(!s->budget--) { s->failed_pc=0x0c059502u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c059504;
P_0c059504: /* original 000b, guest PC 0x0c059504 */
if(!s->budget--) { s->failed_pc=0x0c059504u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c059506: /* original 0009, guest PC 0x0c059506 */
if(!s->budget--) { s->failed_pc=0x0c059506u; return 0; }
goto P_0c059508;
P_0c059508: /* original 4f22, guest PC 0x0c059508 */
if(!s->budget--) { s->failed_pc=0x0c059508u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05950a;
P_0c05950a: /* original 6753, guest PC 0x0c05950a */
if(!s->budget--) { s->failed_pc=0x0c05950au; return 0; }
r[7]=r[5];
goto P_0c05950c;
P_0c05950c: /* original d325, guest PC 0x0c05950c */
if(!s->budget--) { s->failed_pc=0x0c05950cu; return 0; }
r[3]=read(ram,0x0c0595a4u,4);
goto P_0c05950e;
P_0c05950e: /* original 7ff8, guest PC 0x0c05950e */
if(!s->budget--) { s->failed_pc=0x0c05950eu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c059510;
P_0c059510: /* original 2f42, guest PC 0x0c059510 */
if(!s->budget--) { s->failed_pc=0x0c059510u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c059512;
P_0c059512: /* original 1f51, guest PC 0x0c059512 */
if(!s->budget--) { s->failed_pc=0x0c059512u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c059514;
P_0c059514: /* original 66f2, guest PC 0x0c059514 */
if(!s->budget--) { s->failed_pc=0x0c059514u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c059516;
P_0c059516: /* original e500, guest PC 0x0c059516 */
if(!s->budget--) { s->failed_pc=0x0c059516u; return 0; }
r[5]=0x00000000u;
goto P_0c059518;
P_0c059518: /* original bfcc, guest PC 0x0c059518 */
if(!s->budget--) { s->failed_pc=0x0c059518u; return 0; }
target=0x0c0594b4u; r[16]=0x0c05951cu;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05951cu) { target=s->pc; goto dispatch; }
goto P_0c05951c;
P_0c05951a: /* original 6432, guest PC 0x0c05951a */
if(!s->budget--) { s->failed_pc=0x0c05951au; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c05951c;
P_0c05951c: /* original 7f08, guest PC 0x0c05951c */
if(!s->budget--) { s->failed_pc=0x0c05951cu; return 0; }
r[15]+=0x00000008u;
goto P_0c05951e;
P_0c05951e: /* original 4f26, guest PC 0x0c05951e */
if(!s->budget--) { s->failed_pc=0x0c05951eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c059520;
P_0c059520: /* original 000b, guest PC 0x0c059520 */
if(!s->budget--) { s->failed_pc=0x0c059520u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c059522: /* original e000, guest PC 0x0c059522 */
if(!s->budget--) { s->failed_pc=0x0c059522u; return 0; }
r[0]=0x00000000u;
goto P_0c059524;
P_0c059524: /* original 4f22, guest PC 0x0c059524 */
if(!s->budget--) { s->failed_pc=0x0c059524u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c059526;
P_0c059526: /* original 7ff8, guest PC 0x0c059526 */
if(!s->budget--) { s->failed_pc=0x0c059526u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c059528;
P_0c059528: /* original d31f, guest PC 0x0c059528 */
if(!s->budget--) { s->failed_pc=0x0c059528u; return 0; }
r[3]=read(ram,0x0c0595a8u,4);
goto P_0c05952a;
P_0c05952a: /* original 2f42, guest PC 0x0c05952a */
if(!s->budget--) { s->failed_pc=0x0c05952au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05952c;
P_0c05952c: /* original 1f51, guest PC 0x0c05952c */
if(!s->budget--) { s->failed_pc=0x0c05952cu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c05952e;
P_0c05952e: /* original 430b, guest PC 0x0c05952e */
if(!s->budget--) { s->failed_pc=0x0c05952eu; return 0; }
target=r[3];
r[16]=0x0c059532u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059532u) { target=s->pc; goto dispatch; }
goto P_0c059532;
P_0c059530: /* original e401, guest PC 0x0c059530 */
if(!s->budget--) { s->failed_pc=0x0c059530u; return 0; }
r[4]=0x00000001u;
goto P_0c059532;
P_0c059532: /* original e501, guest PC 0x0c059532 */
if(!s->budget--) { s->failed_pc=0x0c059532u; return 0; }
r[5]=0x00000001u;
goto P_0c059534;
P_0c059534: /* original d31b, guest PC 0x0c059534 */
if(!s->budget--) { s->failed_pc=0x0c059534u; return 0; }
r[3]=read(ram,0x0c0595a4u,4);
goto P_0c059536;
P_0c059536: /* original 57f1, guest PC 0x0c059536 */
if(!s->budget--) { s->failed_pc=0x0c059536u; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c059538;
P_0c059538: /* original 66f2, guest PC 0x0c059538 */
if(!s->budget--) { s->failed_pc=0x0c059538u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c05953a;
P_0c05953a: /* original bfbb, guest PC 0x0c05953a */
if(!s->budget--) { s->failed_pc=0x0c05953au; return 0; }
target=0x0c0594b4u; r[16]=0x0c05953eu;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05953eu) { target=s->pc; goto dispatch; }
goto P_0c05953e;
P_0c05953c: /* original 6432, guest PC 0x0c05953c */
if(!s->budget--) { s->failed_pc=0x0c05953cu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c05953e;
P_0c05953e: /* original 7f08, guest PC 0x0c05953e */
if(!s->budget--) { s->failed_pc=0x0c05953eu; return 0; }
r[15]+=0x00000008u;
goto P_0c059540;
P_0c059540: /* original 4f26, guest PC 0x0c059540 */
if(!s->budget--) { s->failed_pc=0x0c059540u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c059542;
P_0c059542: /* original 000b, guest PC 0x0c059542 */
if(!s->budget--) { s->failed_pc=0x0c059542u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c059544: /* original e000, guest PC 0x0c059544 */
if(!s->budget--) { s->failed_pc=0x0c059544u; return 0; }
r[0]=0x00000000u;
goto P_0c059546;
P_0c059546: /* original 4f22, guest PC 0x0c059546 */
if(!s->budget--) { s->failed_pc=0x0c059546u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c059548;
P_0c059548: /* original d318, guest PC 0x0c059548 */
if(!s->budget--) { s->failed_pc=0x0c059548u; return 0; }
r[3]=read(ram,0x0c0595acu,4);
goto P_0c05954a;
P_0c05954a: /* original 7ff8, guest PC 0x0c05954a */
if(!s->budget--) { s->failed_pc=0x0c05954au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c05954c;
P_0c05954c: /* original 2f42, guest PC 0x0c05954c */
if(!s->budget--) { s->failed_pc=0x0c05954cu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05954e;
P_0c05954e: /* original 1f51, guest PC 0x0c05954e */
if(!s->budget--) { s->failed_pc=0x0c05954eu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c059550;
P_0c059550: /* original 64f2, guest PC 0x0c059550 */
if(!s->budget--) { s->failed_pc=0x0c059550u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c059552;
P_0c059552: /* original 2448, guest PC 0x0c059552 */
if(!s->budget--) { s->failed_pc=0x0c059552u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c059554;
P_0c059554: /* original 0429, guest PC 0x0c059554 */
if(!s->budget--) { s->failed_pc=0x0c059554u; return 0; }
r[4]=r[17]&1u;
goto P_0c059556;
P_0c059556: /* original 74ff, guest PC 0x0c059556 */
if(!s->budget--) { s->failed_pc=0x0c059556u; return 0; }
r[4]+=0xffffffffu;
goto P_0c059558;
P_0c059558: /* original 430b, guest PC 0x0c059558 */
if(!s->budget--) { s->failed_pc=0x0c059558u; return 0; }
target=r[3];
r[16]=0x0c05955cu;
r[4]=0u-r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05955cu) { target=s->pc; goto dispatch; }
goto P_0c05955c;
P_0c05955a: /* original 644b, guest PC 0x0c05955a */
if(!s->budget--) { s->failed_pc=0x0c05955au; return 0; }
r[4]=0u-r[4];
goto P_0c05955c;
P_0c05955c: /* original 57f1, guest PC 0x0c05955c */
if(!s->budget--) { s->failed_pc=0x0c05955cu; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c05955e;
P_0c05955e: /* original e502, guest PC 0x0c05955e */
if(!s->budget--) { s->failed_pc=0x0c05955eu; return 0; }
r[5]=0x00000002u;
goto P_0c059560;
P_0c059560: /* original d310, guest PC 0x0c059560 */
if(!s->budget--) { s->failed_pc=0x0c059560u; return 0; }
r[3]=read(ram,0x0c0595a4u,4);
goto P_0c059562;
P_0c059562: /* original 66f2, guest PC 0x0c059562 */
if(!s->budget--) { s->failed_pc=0x0c059562u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c059564;
P_0c059564: /* original bfa6, guest PC 0x0c059564 */
if(!s->budget--) { s->failed_pc=0x0c059564u; return 0; }
target=0x0c0594b4u; r[16]=0x0c059568u;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059568u) { target=s->pc; goto dispatch; }
goto P_0c059568;
P_0c059566: /* original 6432, guest PC 0x0c059566 */
if(!s->budget--) { s->failed_pc=0x0c059566u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c059568;
P_0c059568: /* original 7f08, guest PC 0x0c059568 */
if(!s->budget--) { s->failed_pc=0x0c059568u; return 0; }
r[15]+=0x00000008u;
goto P_0c05956a;
P_0c05956a: /* original 4f26, guest PC 0x0c05956a */
if(!s->budget--) { s->failed_pc=0x0c05956au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05956c;
P_0c05956c: /* original 000b, guest PC 0x0c05956c */
if(!s->budget--) { s->failed_pc=0x0c05956cu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05956e: /* original e000, guest PC 0x0c05956e */
if(!s->budget--) { s->failed_pc=0x0c05956eu; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c059570u,s,ram);
P_0c059708: /* original 4f22, guest PC 0x0c059708 */
if(!s->budget--) { s->failed_pc=0x0c059708u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05970a;
P_0c05970a: /* original 6753, guest PC 0x0c05970a */
if(!s->budget--) { s->failed_pc=0x0c05970au; return 0; }
r[7]=r[5];
goto P_0c05970c;
P_0c05970c: /* original d334, guest PC 0x0c05970c */
if(!s->budget--) { s->failed_pc=0x0c05970cu; return 0; }
r[3]=read(ram,0x0c0597e0u,4);
goto P_0c05970e;
P_0c05970e: /* original 7ff8, guest PC 0x0c05970e */
if(!s->budget--) { s->failed_pc=0x0c05970eu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c059710;
P_0c059710: /* original 2f42, guest PC 0x0c059710 */
if(!s->budget--) { s->failed_pc=0x0c059710u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c059712;
P_0c059712: /* original 1f51, guest PC 0x0c059712 */
if(!s->budget--) { s->failed_pc=0x0c059712u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c059714;
P_0c059714: /* original 66f2, guest PC 0x0c059714 */
if(!s->budget--) { s->failed_pc=0x0c059714u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c059716;
P_0c059716: /* original e503, guest PC 0x0c059716 */
if(!s->budget--) { s->failed_pc=0x0c059716u; return 0; }
r[5]=0x00000003u;
goto P_0c059718;
P_0c059718: /* original becc, guest PC 0x0c059718 */
if(!s->budget--) { s->failed_pc=0x0c059718u; return 0; }
target=0x0c0594b4u; r[16]=0x0c05971cu;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05971cu) { target=s->pc; goto dispatch; }
goto P_0c05971c;
P_0c05971a: /* original 6432, guest PC 0x0c05971a */
if(!s->budget--) { s->failed_pc=0x0c05971au; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c05971c;
P_0c05971c: /* original 7f08, guest PC 0x0c05971c */
if(!s->budget--) { s->failed_pc=0x0c05971cu; return 0; }
r[15]+=0x00000008u;
goto P_0c05971e;
P_0c05971e: /* original 4f26, guest PC 0x0c05971e */
if(!s->budget--) { s->failed_pc=0x0c05971eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c059720;
P_0c059720: /* original 000b, guest PC 0x0c059720 */
if(!s->budget--) { s->failed_pc=0x0c059720u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c059722: /* original e000, guest PC 0x0c059722 */
if(!s->budget--) { s->failed_pc=0x0c059722u; return 0; }
r[0]=0x00000000u;
goto P_0c059724;
P_0c059724: /* original 4f22, guest PC 0x0c059724 */
if(!s->budget--) { s->failed_pc=0x0c059724u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c059726;
P_0c059726: /* original 6753, guest PC 0x0c059726 */
if(!s->budget--) { s->failed_pc=0x0c059726u; return 0; }
r[7]=r[5];
goto P_0c059728;
P_0c059728: /* original d32d, guest PC 0x0c059728 */
if(!s->budget--) { s->failed_pc=0x0c059728u; return 0; }
r[3]=read(ram,0x0c0597e0u,4);
goto P_0c05972a;
P_0c05972a: /* original 7ff8, guest PC 0x0c05972a */
if(!s->budget--) { s->failed_pc=0x0c05972au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c05972c;
P_0c05972c: /* original 2f42, guest PC 0x0c05972c */
if(!s->budget--) { s->failed_pc=0x0c05972cu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05972e;
P_0c05972e: /* original 1f51, guest PC 0x0c05972e */
if(!s->budget--) { s->failed_pc=0x0c05972eu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c059730;
P_0c059730: /* original 66f2, guest PC 0x0c059730 */
if(!s->budget--) { s->failed_pc=0x0c059730u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c059732;
P_0c059732: /* original e504, guest PC 0x0c059732 */
if(!s->budget--) { s->failed_pc=0x0c059732u; return 0; }
r[5]=0x00000004u;
goto P_0c059734;
P_0c059734: /* original bebe, guest PC 0x0c059734 */
if(!s->budget--) { s->failed_pc=0x0c059734u; return 0; }
target=0x0c0594b4u; r[16]=0x0c059738u;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059738u) { target=s->pc; goto dispatch; }
goto P_0c059738;
P_0c059736: /* original 6432, guest PC 0x0c059736 */
if(!s->budget--) { s->failed_pc=0x0c059736u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c059738;
P_0c059738: /* original 7f08, guest PC 0x0c059738 */
if(!s->budget--) { s->failed_pc=0x0c059738u; return 0; }
r[15]+=0x00000008u;
goto P_0c05973a;
P_0c05973a: /* original 4f26, guest PC 0x0c05973a */
if(!s->budget--) { s->failed_pc=0x0c05973au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05973c;
P_0c05973c: /* original 000b, guest PC 0x0c05973c */
if(!s->budget--) { s->failed_pc=0x0c05973cu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05973e: /* original e000, guest PC 0x0c05973e */
if(!s->budget--) { s->failed_pc=0x0c05973eu; return 0; }
r[0]=0x00000000u;
goto P_0c059740;
P_0c059740: /* original 4f22, guest PC 0x0c059740 */
if(!s->budget--) { s->failed_pc=0x0c059740u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c059742;
P_0c059742: /* original 6753, guest PC 0x0c059742 */
if(!s->budget--) { s->failed_pc=0x0c059742u; return 0; }
r[7]=r[5];
goto P_0c059744;
P_0c059744: /* original d326, guest PC 0x0c059744 */
if(!s->budget--) { s->failed_pc=0x0c059744u; return 0; }
r[3]=read(ram,0x0c0597e0u,4);
goto P_0c059746;
P_0c059746: /* original 7ff8, guest PC 0x0c059746 */
if(!s->budget--) { s->failed_pc=0x0c059746u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c059748;
P_0c059748: /* original 2f42, guest PC 0x0c059748 */
if(!s->budget--) { s->failed_pc=0x0c059748u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05974a;
P_0c05974a: /* original 1f51, guest PC 0x0c05974a */
if(!s->budget--) { s->failed_pc=0x0c05974au; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c05974c;
P_0c05974c: /* original 66f2, guest PC 0x0c05974c */
if(!s->budget--) { s->failed_pc=0x0c05974cu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c05974e;
P_0c05974e: /* original e505, guest PC 0x0c05974e */
if(!s->budget--) { s->failed_pc=0x0c05974eu; return 0; }
r[5]=0x00000005u;
goto P_0c059750;
P_0c059750: /* original beb0, guest PC 0x0c059750 */
if(!s->budget--) { s->failed_pc=0x0c059750u; return 0; }
target=0x0c0594b4u; r[16]=0x0c059754u;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059754u) { target=s->pc; goto dispatch; }
goto P_0c059754;
P_0c059752: /* original 6432, guest PC 0x0c059752 */
if(!s->budget--) { s->failed_pc=0x0c059752u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c059754;
P_0c059754: /* original 7f08, guest PC 0x0c059754 */
if(!s->budget--) { s->failed_pc=0x0c059754u; return 0; }
r[15]+=0x00000008u;
goto P_0c059756;
P_0c059756: /* original 4f26, guest PC 0x0c059756 */
if(!s->budget--) { s->failed_pc=0x0c059756u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c059758;
P_0c059758: /* original 000b, guest PC 0x0c059758 */
if(!s->budget--) { s->failed_pc=0x0c059758u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05975a: /* original e000, guest PC 0x0c05975a */
if(!s->budget--) { s->failed_pc=0x0c05975au; return 0; }
r[0]=0x00000000u;
goto P_0c05975c;
P_0c05975c: /* original 4f22, guest PC 0x0c05975c */
if(!s->budget--) { s->failed_pc=0x0c05975cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05975e;
P_0c05975e: /* original 6753, guest PC 0x0c05975e */
if(!s->budget--) { s->failed_pc=0x0c05975eu; return 0; }
r[7]=r[5];
goto P_0c059760;
P_0c059760: /* original d31f, guest PC 0x0c059760 */
if(!s->budget--) { s->failed_pc=0x0c059760u; return 0; }
r[3]=read(ram,0x0c0597e0u,4);
goto P_0c059762;
P_0c059762: /* original 7ff8, guest PC 0x0c059762 */
if(!s->budget--) { s->failed_pc=0x0c059762u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c059764;
P_0c059764: /* original 2f42, guest PC 0x0c059764 */
if(!s->budget--) { s->failed_pc=0x0c059764u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c059766;
P_0c059766: /* original 1f51, guest PC 0x0c059766 */
if(!s->budget--) { s->failed_pc=0x0c059766u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c059768;
P_0c059768: /* original 66f2, guest PC 0x0c059768 */
if(!s->budget--) { s->failed_pc=0x0c059768u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c05976a;
P_0c05976a: /* original e506, guest PC 0x0c05976a */
if(!s->budget--) { s->failed_pc=0x0c05976au; return 0; }
r[5]=0x00000006u;
goto P_0c05976c;
P_0c05976c: /* original bea2, guest PC 0x0c05976c */
if(!s->budget--) { s->failed_pc=0x0c05976cu; return 0; }
target=0x0c0594b4u; r[16]=0x0c059770u;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c059770u) { target=s->pc; goto dispatch; }
goto P_0c059770;
P_0c05976e: /* original 6432, guest PC 0x0c05976e */
if(!s->budget--) { s->failed_pc=0x0c05976eu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c059770;
P_0c059770: /* original 7f08, guest PC 0x0c059770 */
if(!s->budget--) { s->failed_pc=0x0c059770u; return 0; }
r[15]+=0x00000008u;
goto P_0c059772;
P_0c059772: /* original 4f26, guest PC 0x0c059772 */
if(!s->budget--) { s->failed_pc=0x0c059772u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c059774;
P_0c059774: /* original 000b, guest PC 0x0c059774 */
if(!s->budget--) { s->failed_pc=0x0c059774u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c059776: /* original e000, guest PC 0x0c059776 */
if(!s->budget--) { s->failed_pc=0x0c059776u; return 0; }
r[0]=0x00000000u;
goto P_0c059778;
P_0c059778: /* original 4f22, guest PC 0x0c059778 */
if(!s->budget--) { s->failed_pc=0x0c059778u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05977a;
P_0c05977a: /* original 6753, guest PC 0x0c05977a */
if(!s->budget--) { s->failed_pc=0x0c05977au; return 0; }
r[7]=r[5];
goto P_0c05977c;
P_0c05977c: /* original d318, guest PC 0x0c05977c */
if(!s->budget--) { s->failed_pc=0x0c05977cu; return 0; }
r[3]=read(ram,0x0c0597e0u,4);
goto P_0c05977e;
P_0c05977e: /* original 7ff8, guest PC 0x0c05977e */
if(!s->budget--) { s->failed_pc=0x0c05977eu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c059780;
P_0c059780: /* original 2f42, guest PC 0x0c059780 */
if(!s->budget--) { s->failed_pc=0x0c059780u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c059782;
P_0c059782: /* original 1f51, guest PC 0x0c059782 */
if(!s->budget--) { s->failed_pc=0x0c059782u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c059784;
P_0c059784: /* original 66f2, guest PC 0x0c059784 */
if(!s->budget--) { s->failed_pc=0x0c059784u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c059786;
P_0c059786: /* original e507, guest PC 0x0c059786 */
if(!s->budget--) { s->failed_pc=0x0c059786u; return 0; }
r[5]=0x00000007u;
goto P_0c059788;
P_0c059788: /* original be94, guest PC 0x0c059788 */
if(!s->budget--) { s->failed_pc=0x0c059788u; return 0; }
target=0x0c0594b4u; r[16]=0x0c05978cu;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05978cu) { target=s->pc; goto dispatch; }
goto P_0c05978c;
P_0c05978a: /* original 6432, guest PC 0x0c05978a */
if(!s->budget--) { s->failed_pc=0x0c05978au; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c05978c;
P_0c05978c: /* original 7f08, guest PC 0x0c05978c */
if(!s->budget--) { s->failed_pc=0x0c05978cu; return 0; }
r[15]+=0x00000008u;
goto P_0c05978e;
P_0c05978e: /* original 4f26, guest PC 0x0c05978e */
if(!s->budget--) { s->failed_pc=0x0c05978eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c059790;
P_0c059790: /* original 000b, guest PC 0x0c059790 */
if(!s->budget--) { s->failed_pc=0x0c059790u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c059792: /* original e000, guest PC 0x0c059792 */
if(!s->budget--) { s->failed_pc=0x0c059792u; return 0; }
r[0]=0x00000000u;
goto P_0c059794;
P_0c059794: /* original 4f22, guest PC 0x0c059794 */
if(!s->budget--) { s->failed_pc=0x0c059794u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c059796;
P_0c059796: /* original e700, guest PC 0x0c059796 */
if(!s->budget--) { s->failed_pc=0x0c059796u; return 0; }
r[7]=0x00000000u;
goto P_0c059798;
P_0c059798: /* original d311, guest PC 0x0c059798 */
if(!s->budget--) { s->failed_pc=0x0c059798u; return 0; }
r[3]=read(ram,0x0c0597e0u,4);
goto P_0c05979a;
P_0c05979a: /* original 6643, guest PC 0x0c05979a */
if(!s->budget--) { s->failed_pc=0x0c05979au; return 0; }
r[6]=r[4];
goto P_0c05979c;
P_0c05979c: /* original 7ffc, guest PC 0x0c05979c */
if(!s->budget--) { s->failed_pc=0x0c05979cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05979e;
P_0c05979e: /* original e508, guest PC 0x0c05979e */
if(!s->budget--) { s->failed_pc=0x0c05979eu; return 0; }
r[5]=0x00000008u;
goto P_0c0597a0;
P_0c0597a0: /* original 2f42, guest PC 0x0c0597a0 */
if(!s->budget--) { s->failed_pc=0x0c0597a0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0597a2;
P_0c0597a2: /* original be87, guest PC 0x0c0597a2 */
if(!s->budget--) { s->failed_pc=0x0c0597a2u; return 0; }
target=0x0c0594b4u; r[16]=0x0c0597a6u;
tmp=read(ram,r[3],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0597a6u) { target=s->pc; goto dispatch; }
goto P_0c0597a6;
P_0c0597a4: /* original 6432, guest PC 0x0c0597a4 */
if(!s->budget--) { s->failed_pc=0x0c0597a4u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0597a6;
P_0c0597a6: /* original 7f04, guest PC 0x0c0597a6 */
if(!s->budget--) { s->failed_pc=0x0c0597a6u; return 0; }
r[15]+=0x00000004u;
goto P_0c0597a8;
P_0c0597a8: /* original 4f26, guest PC 0x0c0597a8 */
if(!s->budget--) { s->failed_pc=0x0c0597a8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0597aa;
P_0c0597aa: /* original 000b, guest PC 0x0c0597aa */
if(!s->budget--) { s->failed_pc=0x0c0597aau; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c0597ac: /* original e000, guest PC 0x0c0597ac */
if(!s->budget--) { s->failed_pc=0x0c0597acu; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c0597aeu,s,ram);
P_0c05cb74: /* original 4f22, guest PC 0x0c05cb74 */
if(!s->budget--) { s->failed_pc=0x0c05cb74u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05cb76;
P_0c05cb76: /* original 6032, guest PC 0x0c05cb76 */
if(!s->budget--) { s->failed_pc=0x0c05cb76u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05cb78;
P_0c05cb78: /* original 014e, guest PC 0x0c05cb78 */
if(!s->budget--) { s->failed_pc=0x0c05cb78u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c05cb7a;
P_0c05cb7a: /* original d019, guest PC 0x0c05cb7a */
if(!s->budget--) { s->failed_pc=0x0c05cb7au; return 0; }
r[0]=read(ram,0x0c05cbe0u,4);
goto P_0c05cb7c;
P_0c05cb7c: /* original 025e, guest PC 0x0c05cb7c */
if(!s->budget--) { s->failed_pc=0x0c05cb7cu; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c05cb7e;
P_0c05cb7e: /* original 3128, guest PC 0x0c05cb7e */
if(!s->budget--) { s->failed_pc=0x0c05cb7eu; return 0; }
r[1]-=r[2];
goto P_0c05cb80;
P_0c05cb80: /* original d218, guest PC 0x0c05cb80 */
if(!s->budget--) { s->failed_pc=0x0c05cb80u; return 0; }
r[2]=read(ram,0x0c05cbe4u,4);
goto P_0c05cb82;
P_0c05cb82: /* original 420b, guest PC 0x0c05cb82 */
if(!s->budget--) { s->failed_pc=0x0c05cb82u; return 0; }
target=r[2];
r[16]=0x0c05cb86u;
r[0]=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05cb86u) { target=s->pc; goto dispatch; }
goto P_0c05cb86;
P_0c05cb84: /* original e004, guest PC 0x0c05cb84 */
if(!s->budget--) { s->failed_pc=0x0c05cb84u; return 0; }
r[0]=0x00000004u;
goto P_0c05cb86;
P_0c05cb86: /* original 4f26, guest PC 0x0c05cb86 */
if(!s->budget--) { s->failed_pc=0x0c05cb86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05cb88;
P_0c05cb88: /* original 000b, guest PC 0x0c05cb88 */
if(!s->budget--) { s->failed_pc=0x0c05cb88u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05cb8a: /* original 0009, guest PC 0x0c05cb8a */
if(!s->budget--) { s->failed_pc=0x0c05cb8au; return 0; }
return vf3_matrix_family(0x0c05cb8cu,s,ram);
P_0c05ed38: /* original 4f22, guest PC 0x0c05ed38 */
if(!s->budget--) { s->failed_pc=0x0c05ed38u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05ed3a;
P_0c05ed3a: /* original 7fe8, guest PC 0x0c05ed3a */
if(!s->budget--) { s->failed_pc=0x0c05ed3au; return 0; }
r[15]+=0xffffffe8u;
goto P_0c05ed3c;
P_0c05ed3c: /* original d342, guest PC 0x0c05ed3c */
if(!s->budget--) { s->failed_pc=0x0c05ed3cu; return 0; }
r[3]=read(ram,0x0c05ee48u,4);
goto P_0c05ed3e;
P_0c05ed3e: /* original 67f3, guest PC 0x0c05ed3e */
if(!s->budget--) { s->failed_pc=0x0c05ed3eu; return 0; }
r[7]=r[15];
goto P_0c05ed40;
P_0c05ed40: /* original 1f45, guest PC 0x0c05ed40 */
if(!s->budget--) { s->failed_pc=0x0c05ed40u; return 0; }
write(ram,r[15]+20,r[4],4);
goto P_0c05ed42;
P_0c05ed42: /* original 66f3, guest PC 0x0c05ed42 */
if(!s->budget--) { s->failed_pc=0x0c05ed42u; return 0; }
r[6]=r[15];
goto P_0c05ed44;
P_0c05ed44: /* original 1f54, guest PC 0x0c05ed44 */
if(!s->budget--) { s->failed_pc=0x0c05ed44u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c05ed46;
P_0c05ed46: /* original 770c, guest PC 0x0c05ed46 */
if(!s->budget--) { s->failed_pc=0x0c05ed46u; return 0; }
r[7]+=0x0000000cu;
goto P_0c05ed48;
P_0c05ed48: /* original 7608, guest PC 0x0c05ed48 */
if(!s->budget--) { s->failed_pc=0x0c05ed48u; return 0; }
r[6]+=0x00000008u;
goto P_0c05ed4a;
P_0c05ed4a: /* original 65f3, guest PC 0x0c05ed4a */
if(!s->budget--) { s->failed_pc=0x0c05ed4au; return 0; }
r[5]=r[15];
goto P_0c05ed4c;
P_0c05ed4c: /* original 7504, guest PC 0x0c05ed4c */
if(!s->budget--) { s->failed_pc=0x0c05ed4cu; return 0; }
r[5]+=0x00000004u;
goto P_0c05ed4e;
P_0c05ed4e: /* original 430b, guest PC 0x0c05ed4e */
if(!s->budget--) { s->failed_pc=0x0c05ed4eu; return 0; }
target=r[3];
r[16]=0x0c05ed52u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05ed52u) { target=s->pc; goto dispatch; }
goto P_0c05ed52;
P_0c05ed50: /* original 64f3, guest PC 0x0c05ed50 */
if(!s->budget--) { s->failed_pc=0x0c05ed50u; return 0; }
r[4]=r[15];
goto P_0c05ed52;
P_0c05ed52: /* original 6403, guest PC 0x0c05ed52 */
if(!s->budget--) { s->failed_pc=0x0c05ed52u; return 0; }
r[4]=r[0];
goto P_0c05ed54;
P_0c05ed54: /* original 52f5, guest PC 0x0c05ed54 */
if(!s->budget--) { s->failed_pc=0x0c05ed54u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c05ed56;
P_0c05ed56: /* original 53f1, guest PC 0x0c05ed56 */
if(!s->budget--) { s->failed_pc=0x0c05ed56u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c05ed58;
P_0c05ed58: /* original 61f2, guest PC 0x0c05ed58 */
if(!s->budget--) { s->failed_pc=0x0c05ed58u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c05ed5a;
P_0c05ed5a: /* original 313c, guest PC 0x0c05ed5a */
if(!s->budget--) { s->failed_pc=0x0c05ed5au; return 0; }
r[1]+=r[3];
goto P_0c05ed5c;
P_0c05ed5c: /* original 50f2, guest PC 0x0c05ed5c */
if(!s->budget--) { s->failed_pc=0x0c05ed5cu; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c05ed5e;
P_0c05ed5e: /* original 310c, guest PC 0x0c05ed5e */
if(!s->budget--) { s->failed_pc=0x0c05ed5eu; return 0; }
r[1]+=r[0];
goto P_0c05ed60;
P_0c05ed60: /* original 2212, guest PC 0x0c05ed60 */
if(!s->budget--) { s->failed_pc=0x0c05ed60u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c05ed62;
P_0c05ed62: /* original 53f4, guest PC 0x0c05ed62 */
if(!s->budget--) { s->failed_pc=0x0c05ed62u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c05ed64;
P_0c05ed64: /* original 52f3, guest PC 0x0c05ed64 */
if(!s->budget--) { s->failed_pc=0x0c05ed64u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c05ed66;
P_0c05ed66: /* original 2322, guest PC 0x0c05ed66 */
if(!s->budget--) { s->failed_pc=0x0c05ed66u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c05ed68;
P_0c05ed68: /* original 7f18, guest PC 0x0c05ed68 */
if(!s->budget--) { s->failed_pc=0x0c05ed68u; return 0; }
r[15]+=0x00000018u;
goto P_0c05ed6a;
P_0c05ed6a: /* original 4f26, guest PC 0x0c05ed6a */
if(!s->budget--) { s->failed_pc=0x0c05ed6au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05ed6c;
P_0c05ed6c: /* original 000b, guest PC 0x0c05ed6c */
if(!s->budget--) { s->failed_pc=0x0c05ed6cu; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c05ed6e: /* original 6043, guest PC 0x0c05ed6e */
if(!s->budget--) { s->failed_pc=0x0c05ed6eu; return 0; }
r[0]=r[4];
return vf3_matrix_family(0x0c05ed70u,s,ram);
P_0c05ee34: /* original 4f22, guest PC 0x0c05ee34 */
if(!s->budget--) { s->failed_pc=0x0c05ee34u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05ee36;
P_0c05ee36: /* original d309, guest PC 0x0c05ee36 */
if(!s->budget--) { s->failed_pc=0x0c05ee36u; return 0; }
r[3]=read(ram,0x0c05ee5cu,4);
goto P_0c05ee38;
P_0c05ee38: /* original 430b, guest PC 0x0c05ee38 */
if(!s->budget--) { s->failed_pc=0x0c05ee38u; return 0; }
target=r[3];
r[16]=0x0c05ee3cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05ee3cu) { target=s->pc; goto dispatch; }
goto P_0c05ee3c;
P_0c05ee3a: /* original 0009, guest PC 0x0c05ee3a */
if(!s->budget--) { s->failed_pc=0x0c05ee3au; return 0; }
goto P_0c05ee3c;
P_0c05ee3c: /* original d208, guest PC 0x0c05ee3c */
if(!s->budget--) { s->failed_pc=0x0c05ee3cu; return 0; }
r[2]=read(ram,0x0c05ee60u,4);
goto P_0c05ee3e;
P_0c05ee3e: /* original 420b, guest PC 0x0c05ee3e */
if(!s->budget--) { s->failed_pc=0x0c05ee3eu; return 0; }
target=r[2];
r[16]=0x0c05ee42u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05ee42u) { target=s->pc; goto dispatch; }
goto P_0c05ee42;
P_0c05ee40: /* original 0009, guest PC 0x0c05ee40 */
if(!s->budget--) { s->failed_pc=0x0c05ee40u; return 0; }
goto P_0c05ee42;
P_0c05ee42: /* original 4f26, guest PC 0x0c05ee42 */
if(!s->budget--) { s->failed_pc=0x0c05ee42u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05ee44;
P_0c05ee44: /* original 000b, guest PC 0x0c05ee44 */
if(!s->budget--) { s->failed_pc=0x0c05ee44u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05ee46: /* original 0009, guest PC 0x0c05ee46 */
if(!s->budget--) { s->failed_pc=0x0c05ee46u; return 0; }
return vf3_matrix_family(0x0c05ee48u,s,ram);
P_0c060cf6: /* original 000b, guest PC 0x0c060cf6 */
if(!s->budget--) { s->failed_pc=0x0c060cf6u; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c060cf8: /* original e001, guest PC 0x0c060cf8 */
if(!s->budget--) { s->failed_pc=0x0c060cf8u; return 0; }
r[0]=0x00000001u;
return vf3_matrix_family(0x0c060cfau,s,ram);
P_0c061998: /* original 2fe6, guest PC 0x0c061998 */
if(!s->budget--) { s->failed_pc=0x0c061998u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c06199a;
P_0c06199a: /* original 2fd6, guest PC 0x0c06199a */
if(!s->budget--) { s->failed_pc=0x0c06199au; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c06199c;
P_0c06199c: /* original 4f22, guest PC 0x0c06199c */
if(!s->budget--) { s->failed_pc=0x0c06199cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06199e;
P_0c06199e: /* original de1b, guest PC 0x0c06199e */
if(!s->budget--) { s->failed_pc=0x0c06199eu; return 0; }
r[14]=read(ram,0x0c061a0cu,4);
goto P_0c0619a0;
P_0c0619a0: /* original 65e3, guest PC 0x0c0619a0 */
if(!s->budget--) { s->failed_pc=0x0c0619a0u; return 0; }
r[5]=r[14];
goto P_0c0619a2;
P_0c0619a2: /* original 7504, guest PC 0x0c0619a2 */
if(!s->budget--) { s->failed_pc=0x0c0619a2u; return 0; }
r[5]+=0x00000004u;
goto P_0c0619a4;
P_0c0619a4: /* original b62e, guest PC 0x0c0619a4 */
if(!s->budget--) { s->failed_pc=0x0c0619a4u; return 0; }
target=0x0c062604u; r[16]=0x0c0619a8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0619a8u) { target=s->pc; goto dispatch; }
goto P_0c0619a8;
P_0c0619a6: /* original 64e3, guest PC 0x0c0619a6 */
if(!s->budget--) { s->failed_pc=0x0c0619a6u; return 0; }
r[4]=r[14];
goto P_0c0619a8;
P_0c0619a8: /* original dd19, guest PC 0x0c0619a8 */
if(!s->budget--) { s->failed_pc=0x0c0619a8u; return 0; }
r[13]=read(ram,0x0c061a10u,4);
goto P_0c0619aa;
P_0c0619aa: /* original 65d3, guest PC 0x0c0619aa */
if(!s->budget--) { s->failed_pc=0x0c0619aau; return 0; }
r[5]=r[13];
goto P_0c0619ac;
P_0c0619ac: /* original 7504, guest PC 0x0c0619ac */
if(!s->budget--) { s->failed_pc=0x0c0619acu; return 0; }
r[5]+=0x00000004u;
goto P_0c0619ae;
P_0c0619ae: /* original b629, guest PC 0x0c0619ae */
if(!s->budget--) { s->failed_pc=0x0c0619aeu; return 0; }
target=0x0c062604u; r[16]=0x0c0619b2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0619b2u) { target=s->pc; goto dispatch; }
goto P_0c0619b2;
P_0c0619b0: /* original 64d3, guest PC 0x0c0619b0 */
if(!s->budget--) { s->failed_pc=0x0c0619b0u; return 0; }
r[4]=r[13];
goto P_0c0619b2;
P_0c0619b2: /* original 65e3, guest PC 0x0c0619b2 */
if(!s->budget--) { s->failed_pc=0x0c0619b2u; return 0; }
r[5]=r[14];
goto P_0c0619b4;
P_0c0619b4: /* original 750c, guest PC 0x0c0619b4 */
if(!s->budget--) { s->failed_pc=0x0c0619b4u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0619b6;
P_0c0619b6: /* original 64e3, guest PC 0x0c0619b6 */
if(!s->budget--) { s->failed_pc=0x0c0619b6u; return 0; }
r[4]=r[14];
goto P_0c0619b8;
P_0c0619b8: /* original b624, guest PC 0x0c0619b8 */
if(!s->budget--) { s->failed_pc=0x0c0619b8u; return 0; }
target=0x0c062604u; r[16]=0x0c0619bcu;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0619bcu) { target=s->pc; goto dispatch; }
goto P_0c0619bc;
P_0c0619ba: /* original 7408, guest PC 0x0c0619ba */
if(!s->budget--) { s->failed_pc=0x0c0619bau; return 0; }
r[4]+=0x00000008u;
goto P_0c0619bc;
P_0c0619bc: /* original 65d3, guest PC 0x0c0619bc */
if(!s->budget--) { s->failed_pc=0x0c0619bcu; return 0; }
r[5]=r[13];
goto P_0c0619be;
P_0c0619be: /* original 750c, guest PC 0x0c0619be */
if(!s->budget--) { s->failed_pc=0x0c0619beu; return 0; }
r[5]+=0x0000000cu;
goto P_0c0619c0;
P_0c0619c0: /* original 64d3, guest PC 0x0c0619c0 */
if(!s->budget--) { s->failed_pc=0x0c0619c0u; return 0; }
r[4]=r[13];
goto P_0c0619c2;
P_0c0619c2: /* original b61f, guest PC 0x0c0619c2 */
if(!s->budget--) { s->failed_pc=0x0c0619c2u; return 0; }
target=0x0c062604u; r[16]=0x0c0619c6u;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0619c6u) { target=s->pc; goto dispatch; }
goto P_0c0619c6;
P_0c0619c4: /* original 7408, guest PC 0x0c0619c4 */
if(!s->budget--) { s->failed_pc=0x0c0619c4u; return 0; }
r[4]+=0x00000008u;
goto P_0c0619c6;
P_0c0619c6: /* original e000, guest PC 0x0c0619c6 */
if(!s->budget--) { s->failed_pc=0x0c0619c6u; return 0; }
r[0]=0x00000000u;
goto P_0c0619c8;
P_0c0619c8: /* original 4f26, guest PC 0x0c0619c8 */
if(!s->budget--) { s->failed_pc=0x0c0619c8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0619ca;
P_0c0619ca: /* original 6df6, guest PC 0x0c0619ca */
if(!s->budget--) { s->failed_pc=0x0c0619cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0619cc;
P_0c0619cc: /* original 000b, guest PC 0x0c0619cc */
if(!s->budget--) { s->failed_pc=0x0c0619ccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0619ce: /* original 6ef6, guest PC 0x0c0619ce */
if(!s->budget--) { s->failed_pc=0x0c0619ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0619d0;
P_0c0619d0: /* original 2fe6, guest PC 0x0c0619d0 */
if(!s->budget--) { s->failed_pc=0x0c0619d0u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0619d2;
P_0c0619d2: /* original 4f22, guest PC 0x0c0619d2 */
if(!s->budget--) { s->failed_pc=0x0c0619d2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0619d4;
P_0c0619d4: /* original de0d, guest PC 0x0c0619d4 */
if(!s->budget--) { s->failed_pc=0x0c0619d4u; return 0; }
r[14]=read(ram,0x0c061a0cu,4);
goto P_0c0619d6;
P_0c0619d6: /* original 67e3, guest PC 0x0c0619d6 */
if(!s->budget--) { s->failed_pc=0x0c0619d6u; return 0; }
r[7]=r[14];
goto P_0c0619d8;
P_0c0619d8: /* original 7704, guest PC 0x0c0619d8 */
if(!s->budget--) { s->failed_pc=0x0c0619d8u; return 0; }
r[7]+=0x00000004u;
goto P_0c0619da;
P_0c0619da: /* original 66e3, guest PC 0x0c0619da */
if(!s->budget--) { s->failed_pc=0x0c0619dau; return 0; }
r[6]=r[14];
goto P_0c0619dc;
P_0c0619dc: /* original 65e3, guest PC 0x0c0619dc */
if(!s->budget--) { s->failed_pc=0x0c0619dcu; return 0; }
r[5]=r[14];
goto P_0c0619de;
P_0c0619de: /* original 750c, guest PC 0x0c0619de */
if(!s->budget--) { s->failed_pc=0x0c0619deu; return 0; }
r[5]+=0x0000000cu;
goto P_0c0619e0;
P_0c0619e0: /* original 64e3, guest PC 0x0c0619e0 */
if(!s->budget--) { s->failed_pc=0x0c0619e0u; return 0; }
r[4]=r[14];
goto P_0c0619e2;
P_0c0619e2: /* original b665, guest PC 0x0c0619e2 */
if(!s->budget--) { s->failed_pc=0x0c0619e2u; return 0; }
target=0x0c0626b0u; r[16]=0x0c0619e6u;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0619e6u) { target=s->pc; goto dispatch; }
goto P_0c0619e6;
P_0c0619e4: /* original 7408, guest PC 0x0c0619e4 */
if(!s->budget--) { s->failed_pc=0x0c0619e4u; return 0; }
r[4]+=0x00000008u;
goto P_0c0619e6;
P_0c0619e6: /* original 6403, guest PC 0x0c0619e6 */
if(!s->budget--) { s->failed_pc=0x0c0619e6u; return 0; }
r[4]=r[0];
goto P_0c0619e8;
P_0c0619e8: /* original 2448, guest PC 0x0c0619e8 */
if(!s->budget--) { s->failed_pc=0x0c0619e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0619ea;
P_0c0619ea: /* original 8b09, guest PC 0x0c0619ea */
if(!s->budget--) { s->failed_pc=0x0c0619eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061a00; }
goto P_0c0619ec;
P_0c0619ec: /* original de08, guest PC 0x0c0619ec */
if(!s->budget--) { s->failed_pc=0x0c0619ecu; return 0; }
r[14]=read(ram,0x0c061a10u,4);
goto P_0c0619ee;
P_0c0619ee: /* original 67e3, guest PC 0x0c0619ee */
if(!s->budget--) { s->failed_pc=0x0c0619eeu; return 0; }
r[7]=r[14];
goto P_0c0619f0;
P_0c0619f0: /* original 7704, guest PC 0x0c0619f0 */
if(!s->budget--) { s->failed_pc=0x0c0619f0u; return 0; }
r[7]+=0x00000004u;
goto P_0c0619f2;
P_0c0619f2: /* original 66e3, guest PC 0x0c0619f2 */
if(!s->budget--) { s->failed_pc=0x0c0619f2u; return 0; }
r[6]=r[14];
goto P_0c0619f4;
P_0c0619f4: /* original 65e3, guest PC 0x0c0619f4 */
if(!s->budget--) { s->failed_pc=0x0c0619f4u; return 0; }
r[5]=r[14];
goto P_0c0619f6;
P_0c0619f6: /* original 750c, guest PC 0x0c0619f6 */
if(!s->budget--) { s->failed_pc=0x0c0619f6u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0619f8;
P_0c0619f8: /* original 64e3, guest PC 0x0c0619f8 */
if(!s->budget--) { s->failed_pc=0x0c0619f8u; return 0; }
r[4]=r[14];
goto P_0c0619fa;
P_0c0619fa: /* original b659, guest PC 0x0c0619fa */
if(!s->budget--) { s->failed_pc=0x0c0619fau; return 0; }
target=0x0c0626b0u; r[16]=0x0c0619feu;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0619feu) { target=s->pc; goto dispatch; }
goto P_0c0619fe;
P_0c0619fc: /* original 7408, guest PC 0x0c0619fc */
if(!s->budget--) { s->failed_pc=0x0c0619fcu; return 0; }
r[4]+=0x00000008u;
goto P_0c0619fe;
P_0c0619fe: /* original 6403, guest PC 0x0c0619fe */
if(!s->budget--) { s->failed_pc=0x0c0619feu; return 0; }
r[4]=r[0];
goto P_0c061a00;
P_0c061a00: /* original 6043, guest PC 0x0c061a00 */
if(!s->budget--) { s->failed_pc=0x0c061a00u; return 0; }
r[0]=r[4];
goto P_0c061a02;
P_0c061a02: /* original 0009, guest PC 0x0c061a02 */
if(!s->budget--) { s->failed_pc=0x0c061a02u; return 0; }
goto P_0c061a04;
P_0c061a04: /* original 4f26, guest PC 0x0c061a04 */
if(!s->budget--) { s->failed_pc=0x0c061a04u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c061a06;
P_0c061a06: /* original 000b, guest PC 0x0c061a06 */
if(!s->budget--) { s->failed_pc=0x0c061a06u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c061a08: /* original 6ef6, guest PC 0x0c061a08 */
if(!s->budget--) { s->failed_pc=0x0c061a08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c061a0au,s,ram);
P_0c062ec4: /* original 4f22, guest PC 0x0c062ec4 */
if(!s->budget--) { s->failed_pc=0x0c062ec4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c062ec6;
P_0c062ec6: /* original 6343, guest PC 0x0c062ec6 */
if(!s->budget--) { s->failed_pc=0x0c062ec6u; return 0; }
r[3]=r[4];
goto P_0c062ec8;
P_0c062ec8: /* original 430b, guest PC 0x0c062ec8 */
if(!s->budget--) { s->failed_pc=0x0c062ec8u; return 0; }
target=r[3];
r[16]=0x0c062eccu;
r[4]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c062eccu) { target=s->pc; goto dispatch; }
goto P_0c062ecc;
P_0c062eca: /* original 6453, guest PC 0x0c062eca */
if(!s->budget--) { s->failed_pc=0x0c062ecau; return 0; }
r[4]=r[5];
goto P_0c062ecc;
P_0c062ecc: /* original 4f26, guest PC 0x0c062ecc */
if(!s->budget--) { s->failed_pc=0x0c062eccu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c062ece;
P_0c062ece: /* original fff9, guest PC 0x0c062ece */
if(!s->budget--) { s->failed_pc=0x0c062eceu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ed0;
P_0c062ed0: /* original fef9, guest PC 0x0c062ed0 */
if(!s->budget--) { s->failed_pc=0x0c062ed0u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ed2;
P_0c062ed2: /* original fdf9, guest PC 0x0c062ed2 */
if(!s->budget--) { s->failed_pc=0x0c062ed2u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ed4;
P_0c062ed4: /* original fcf9, guest PC 0x0c062ed4 */
if(!s->budget--) { s->failed_pc=0x0c062ed4u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ed6;
P_0c062ed6: /* original fbf9, guest PC 0x0c062ed6 */
if(!s->budget--) { s->failed_pc=0x0c062ed6u; return 0; }
vf3_matrix_load(s,ram,11,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ed8;
P_0c062ed8: /* original faf9, guest PC 0x0c062ed8 */
if(!s->budget--) { s->failed_pc=0x0c062ed8u; return 0; }
vf3_matrix_load(s,ram,10,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062eda;
P_0c062eda: /* original f9f9, guest PC 0x0c062eda */
if(!s->budget--) { s->failed_pc=0x0c062edau; return 0; }
vf3_matrix_load(s,ram,9,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062edc;
P_0c062edc: /* original f8f9, guest PC 0x0c062edc */
if(!s->budget--) { s->failed_pc=0x0c062edcu; return 0; }
vf3_matrix_load(s,ram,8,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ede;
P_0c062ede: /* original f7f9, guest PC 0x0c062ede */
if(!s->budget--) { s->failed_pc=0x0c062edeu; return 0; }
vf3_matrix_load(s,ram,7,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ee0;
P_0c062ee0: /* original f6f9, guest PC 0x0c062ee0 */
if(!s->budget--) { s->failed_pc=0x0c062ee0u; return 0; }
vf3_matrix_load(s,ram,6,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ee2;
P_0c062ee2: /* original f5f9, guest PC 0x0c062ee2 */
if(!s->budget--) { s->failed_pc=0x0c062ee2u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ee4;
P_0c062ee4: /* original f4f9, guest PC 0x0c062ee4 */
if(!s->budget--) { s->failed_pc=0x0c062ee4u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ee6;
P_0c062ee6: /* original f3f9, guest PC 0x0c062ee6 */
if(!s->budget--) { s->failed_pc=0x0c062ee6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ee8;
P_0c062ee8: /* original f2f9, guest PC 0x0c062ee8 */
if(!s->budget--) { s->failed_pc=0x0c062ee8u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062eea;
P_0c062eea: /* original f1f9, guest PC 0x0c062eea */
if(!s->budget--) { s->failed_pc=0x0c062eeau; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062eec;
P_0c062eec: /* original f0f9, guest PC 0x0c062eec */
if(!s->budget--) { s->failed_pc=0x0c062eecu; return 0; }
vf3_matrix_load(s,ram,0,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062eee;
P_0c062eee: /* original 60f6, guest PC 0x0c062eee */
if(!s->budget--) { s->failed_pc=0x0c062eeeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[0]=tmp;
goto P_0c062ef0;
P_0c062ef0: /* original 406a, guest PC 0x0c062ef0 */
if(!s->budget--) { s->failed_pc=0x0c062ef0u; return 0; }
r[18]=r[0];
goto P_0c062ef2;
P_0c062ef2: /* original 000b, guest PC 0x0c062ef2 */
if(!s->budget--) { s->failed_pc=0x0c062ef2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062ef4: /* original 0009, guest PC 0x0c062ef4 */
if(!s->budget--) { s->failed_pc=0x0c062ef4u; return 0; }
return vf3_matrix_family(0x0c062ef6u,s,ram);
P_0c0645fa: /* original 4f22, guest PC 0x0c0645fa */
if(!s->budget--) { s->failed_pc=0x0c0645fau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0645fc;
P_0c0645fc: /* original 7ff0, guest PC 0x0c0645fc */
if(!s->budget--) { s->failed_pc=0x0c0645fcu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0645fe;
P_0c0645fe: /* original 6df3, guest PC 0x0c0645fe */
if(!s->budget--) { s->failed_pc=0x0c0645feu; return 0; }
r[13]=r[15];
goto P_0c064600;
P_0c064600: /* original 6342, guest PC 0x0c064600 */
if(!s->budget--) { s->failed_pc=0x0c064600u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c064602;
P_0c064602: /* original 7d04, guest PC 0x0c064602 */
if(!s->budget--) { s->failed_pc=0x0c064602u; return 0; }
r[13]+=0x00000004u;
goto P_0c064604;
P_0c064604: /* original 6ed3, guest PC 0x0c064604 */
if(!s->budget--) { s->failed_pc=0x0c064604u; return 0; }
r[14]=r[13];
goto P_0c064606;
P_0c064606: /* original 66e3, guest PC 0x0c064606 */
if(!s->budget--) { s->failed_pc=0x0c064606u; return 0; }
r[6]=r[14];
goto P_0c064608;
P_0c064608: /* original 2e32, guest PC 0x0c064608 */
if(!s->budget--) { s->failed_pc=0x0c064608u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c06460a;
P_0c06460a: /* original 67e3, guest PC 0x0c06460a */
if(!s->budget--) { s->failed_pc=0x0c06460au; return 0; }
r[7]=r[14];
goto P_0c06460c;
P_0c06460c: /* original 5241, guest PC 0x0c06460c */
if(!s->budget--) { s->failed_pc=0x0c06460cu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c06460e;
P_0c06460e: /* original 7604, guest PC 0x0c06460e */
if(!s->budget--) { s->failed_pc=0x0c06460eu; return 0; }
r[6]+=0x00000004u;
goto P_0c064610;
P_0c064610: /* original 2622, guest PC 0x0c064610 */
if(!s->budget--) { s->failed_pc=0x0c064610u; return 0; }
write(ram,r[6],r[2],4);
goto P_0c064612;
P_0c064612: /* original 7708, guest PC 0x0c064612 */
if(!s->budget--) { s->failed_pc=0x0c064612u; return 0; }
r[7]+=0x00000008u;
goto P_0c064614;
P_0c064614: /* original 5342, guest PC 0x0c064614 */
if(!s->budget--) { s->failed_pc=0x0c064614u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c064616;
P_0c064616: /* original 2732, guest PC 0x0c064616 */
if(!s->budget--) { s->failed_pc=0x0c064616u; return 0; }
write(ram,r[7],r[3],4);
goto P_0c064618;
P_0c064618: /* original d250, guest PC 0x0c064618 */
if(!s->budget--) { s->failed_pc=0x0c064618u; return 0; }
r[2]=read(ram,0x0c06475cu,4);
goto P_0c06461a;
P_0c06461a: /* original 6d22, guest PC 0x0c06461a */
if(!s->budget--) { s->failed_pc=0x0c06461au; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c06461c;
P_0c06461c: /* original d150, guest PC 0x0c06461c */
if(!s->budget--) { s->failed_pc=0x0c06461cu; return 0; }
r[1]=read(ram,0x0c064760u,4);
goto P_0c06461e;
P_0c06461e: /* original 6312, guest PC 0x0c06461e */
if(!s->budget--) { s->failed_pc=0x0c06461eu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c064620;
P_0c064620: /* original 2f32, guest PC 0x0c064620 */
if(!s->budget--) { s->failed_pc=0x0c064620u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c064622;
P_0c064622: /* original d350, guest PC 0x0c064622 */
if(!s->budget--) { s->failed_pc=0x0c064622u; return 0; }
r[3]=read(ram,0x0c064764u,4);
goto P_0c064624;
P_0c064624: /* original 6432, guest PC 0x0c064624 */
if(!s->budget--) { s->failed_pc=0x0c064624u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c064626;
P_0c064626: /* original d03a, guest PC 0x0c064626 */
if(!s->budget--) { s->failed_pc=0x0c064626u; return 0; }
r[0]=read(ram,0x0c064710u,4);
goto P_0c064628;
P_0c064628: /* original 6253, guest PC 0x0c064628 */
if(!s->budget--) { s->failed_pc=0x0c064628u; return 0; }
r[2]=r[5];
goto P_0c06462a;
P_0c06462a: /* original 7501, guest PC 0x0c06462a */
if(!s->budget--) { s->failed_pc=0x0c06462au; return 0; }
r[5]+=0x00000001u;
goto P_0c06462c;
P_0c06462c: /* original 4208, guest PC 0x0c06462c */
if(!s->budget--) { s->failed_pc=0x0c06462cu; return 0; }
r[2]<<=2;
goto P_0c06462e;
P_0c06462e: /* original 02d6, guest PC 0x0c06462e */
if(!s->budget--) { s->failed_pc=0x0c06462eu; return 0; }
write(ram,r[2]+r[0],r[13],4);
goto P_0c064630;
P_0c064630: /* original 6153, guest PC 0x0c064630 */
if(!s->budget--) { s->failed_pc=0x0c064630u; return 0; }
r[1]=r[5];
goto P_0c064632;
P_0c064632: /* original 7501, guest PC 0x0c064632 */
if(!s->budget--) { s->failed_pc=0x0c064632u; return 0; }
r[5]+=0x00000001u;
goto P_0c064634;
P_0c064634: /* original 62f2, guest PC 0x0c064634 */
if(!s->budget--) { s->failed_pc=0x0c064634u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c064636;
P_0c064636: /* original 4108, guest PC 0x0c064636 */
if(!s->budget--) { s->failed_pc=0x0c064636u; return 0; }
r[1]<<=2;
goto P_0c064638;
P_0c064638: /* original 0126, guest PC 0x0c064638 */
if(!s->budget--) { s->failed_pc=0x0c064638u; return 0; }
write(ram,r[1]+r[0],r[2],4);
goto P_0c06463a;
P_0c06463a: /* original 6153, guest PC 0x0c06463a */
if(!s->budget--) { s->failed_pc=0x0c06463au; return 0; }
r[1]=r[5];
goto P_0c06463c;
P_0c06463c: /* original 7501, guest PC 0x0c06463c */
if(!s->budget--) { s->failed_pc=0x0c06463cu; return 0; }
r[5]+=0x00000001u;
goto P_0c06463e;
P_0c06463e: /* original 4108, guest PC 0x0c06463e */
if(!s->budget--) { s->failed_pc=0x0c06463eu; return 0; }
r[1]<<=2;
goto P_0c064640;
P_0c064640: /* original 0146, guest PC 0x0c064640 */
if(!s->budget--) { s->failed_pc=0x0c064640u; return 0; }
write(ram,r[1]+r[0],r[4],4);
goto P_0c064642;
P_0c064642: /* original 6253, guest PC 0x0c064642 */
if(!s->budget--) { s->failed_pc=0x0c064642u; return 0; }
r[2]=r[5];
goto P_0c064644;
P_0c064644: /* original 61e2, guest PC 0x0c064644 */
if(!s->budget--) { s->failed_pc=0x0c064644u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c064646;
P_0c064646: /* original 7501, guest PC 0x0c064646 */
if(!s->budget--) { s->failed_pc=0x0c064646u; return 0; }
r[5]+=0x00000001u;
goto P_0c064648;
P_0c064648: /* original 5111, guest PC 0x0c064648 */
if(!s->budget--) { s->failed_pc=0x0c064648u; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c06464a;
P_0c06464a: /* original 4208, guest PC 0x0c06464a */
if(!s->budget--) { s->failed_pc=0x0c06464au; return 0; }
r[2]<<=2;
goto P_0c06464c;
P_0c06464c: /* original 0216, guest PC 0x0c06464c */
if(!s->budget--) { s->failed_pc=0x0c06464cu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06464e;
P_0c06464e: /* original 6253, guest PC 0x0c06464e */
if(!s->budget--) { s->failed_pc=0x0c06464eu; return 0; }
r[2]=r[5];
goto P_0c064650;
P_0c064650: /* original 61e2, guest PC 0x0c064650 */
if(!s->budget--) { s->failed_pc=0x0c064650u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c064652;
P_0c064652: /* original 7501, guest PC 0x0c064652 */
if(!s->budget--) { s->failed_pc=0x0c064652u; return 0; }
r[5]+=0x00000001u;
goto P_0c064654;
P_0c064654: /* original 5112, guest PC 0x0c064654 */
if(!s->budget--) { s->failed_pc=0x0c064654u; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c064656;
P_0c064656: /* original 4208, guest PC 0x0c064656 */
if(!s->budget--) { s->failed_pc=0x0c064656u; return 0; }
r[2]<<=2;
goto P_0c064658;
P_0c064658: /* original 0216, guest PC 0x0c064658 */
if(!s->budget--) { s->failed_pc=0x0c064658u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06465a;
P_0c06465a: /* original 6253, guest PC 0x0c06465a */
if(!s->budget--) { s->failed_pc=0x0c06465au; return 0; }
r[2]=r[5];
goto P_0c06465c;
P_0c06465c: /* original 61e2, guest PC 0x0c06465c */
if(!s->budget--) { s->failed_pc=0x0c06465cu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c06465e;
P_0c06465e: /* original 7501, guest PC 0x0c06465e */
if(!s->budget--) { s->failed_pc=0x0c06465eu; return 0; }
r[5]+=0x00000001u;
goto P_0c064660;
P_0c064660: /* original 5113, guest PC 0x0c064660 */
if(!s->budget--) { s->failed_pc=0x0c064660u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c064662;
P_0c064662: /* original 4208, guest PC 0x0c064662 */
if(!s->budget--) { s->failed_pc=0x0c064662u; return 0; }
r[2]<<=2;
goto P_0c064664;
P_0c064664: /* original 0216, guest PC 0x0c064664 */
if(!s->budget--) { s->failed_pc=0x0c064664u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064666;
P_0c064666: /* original 6253, guest PC 0x0c064666 */
if(!s->budget--) { s->failed_pc=0x0c064666u; return 0; }
r[2]=r[5];
goto P_0c064668;
P_0c064668: /* original 61e2, guest PC 0x0c064668 */
if(!s->budget--) { s->failed_pc=0x0c064668u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c06466a;
P_0c06466a: /* original 7501, guest PC 0x0c06466a */
if(!s->budget--) { s->failed_pc=0x0c06466au; return 0; }
r[5]+=0x00000001u;
goto P_0c06466c;
P_0c06466c: /* original 5116, guest PC 0x0c06466c */
if(!s->budget--) { s->failed_pc=0x0c06466cu; return 0; }
r[1]=read(ram,r[1]+24,4);
goto P_0c06466e;
P_0c06466e: /* original 4208, guest PC 0x0c06466e */
if(!s->budget--) { s->failed_pc=0x0c06466eu; return 0; }
r[2]<<=2;
goto P_0c064670;
P_0c064670: /* original 0216, guest PC 0x0c064670 */
if(!s->budget--) { s->failed_pc=0x0c064670u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064672;
P_0c064672: /* original 6253, guest PC 0x0c064672 */
if(!s->budget--) { s->failed_pc=0x0c064672u; return 0; }
r[2]=r[5];
goto P_0c064674;
P_0c064674: /* original 6162, guest PC 0x0c064674 */
if(!s->budget--) { s->failed_pc=0x0c064674u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c064676;
P_0c064676: /* original 7501, guest PC 0x0c064676 */
if(!s->budget--) { s->failed_pc=0x0c064676u; return 0; }
r[5]+=0x00000001u;
goto P_0c064678;
P_0c064678: /* original 5111, guest PC 0x0c064678 */
if(!s->budget--) { s->failed_pc=0x0c064678u; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c06467a;
P_0c06467a: /* original 4208, guest PC 0x0c06467a */
if(!s->budget--) { s->failed_pc=0x0c06467au; return 0; }
r[2]<<=2;
goto P_0c06467c;
P_0c06467c: /* original 0216, guest PC 0x0c06467c */
if(!s->budget--) { s->failed_pc=0x0c06467cu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06467e;
P_0c06467e: /* original 6253, guest PC 0x0c06467e */
if(!s->budget--) { s->failed_pc=0x0c06467eu; return 0; }
r[2]=r[5];
goto P_0c064680;
P_0c064680: /* original 6162, guest PC 0x0c064680 */
if(!s->budget--) { s->failed_pc=0x0c064680u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c064682;
P_0c064682: /* original 7501, guest PC 0x0c064682 */
if(!s->budget--) { s->failed_pc=0x0c064682u; return 0; }
r[5]+=0x00000001u;
goto P_0c064684;
P_0c064684: /* original 5112, guest PC 0x0c064684 */
if(!s->budget--) { s->failed_pc=0x0c064684u; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c064686;
P_0c064686: /* original 4208, guest PC 0x0c064686 */
if(!s->budget--) { s->failed_pc=0x0c064686u; return 0; }
r[2]<<=2;
goto P_0c064688;
P_0c064688: /* original 0216, guest PC 0x0c064688 */
if(!s->budget--) { s->failed_pc=0x0c064688u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06468a;
P_0c06468a: /* original 6253, guest PC 0x0c06468a */
if(!s->budget--) { s->failed_pc=0x0c06468au; return 0; }
r[2]=r[5];
goto P_0c06468c;
P_0c06468c: /* original 6162, guest PC 0x0c06468c */
if(!s->budget--) { s->failed_pc=0x0c06468cu; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c06468e;
P_0c06468e: /* original 7501, guest PC 0x0c06468e */
if(!s->budget--) { s->failed_pc=0x0c06468eu; return 0; }
r[5]+=0x00000001u;
goto P_0c064690;
P_0c064690: /* original 5113, guest PC 0x0c064690 */
if(!s->budget--) { s->failed_pc=0x0c064690u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c064692;
P_0c064692: /* original 4208, guest PC 0x0c064692 */
if(!s->budget--) { s->failed_pc=0x0c064692u; return 0; }
r[2]<<=2;
goto P_0c064694;
P_0c064694: /* original 0216, guest PC 0x0c064694 */
if(!s->budget--) { s->failed_pc=0x0c064694u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064696;
P_0c064696: /* original 6253, guest PC 0x0c064696 */
if(!s->budget--) { s->failed_pc=0x0c064696u; return 0; }
r[2]=r[5];
goto P_0c064698;
P_0c064698: /* original 6162, guest PC 0x0c064698 */
if(!s->budget--) { s->failed_pc=0x0c064698u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c06469a;
P_0c06469a: /* original 7501, guest PC 0x0c06469a */
if(!s->budget--) { s->failed_pc=0x0c06469au; return 0; }
r[5]+=0x00000001u;
goto P_0c06469c;
P_0c06469c: /* original 5116, guest PC 0x0c06469c */
if(!s->budget--) { s->failed_pc=0x0c06469cu; return 0; }
r[1]=read(ram,r[1]+24,4);
goto P_0c06469e;
P_0c06469e: /* original 4208, guest PC 0x0c06469e */
if(!s->budget--) { s->failed_pc=0x0c06469eu; return 0; }
r[2]<<=2;
goto P_0c0646a0;
P_0c0646a0: /* original 0216, guest PC 0x0c0646a0 */
if(!s->budget--) { s->failed_pc=0x0c0646a0u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0646a2;
P_0c0646a2: /* original 6253, guest PC 0x0c0646a2 */
if(!s->budget--) { s->failed_pc=0x0c0646a2u; return 0; }
r[2]=r[5];
goto P_0c0646a4;
P_0c0646a4: /* original 6172, guest PC 0x0c0646a4 */
if(!s->budget--) { s->failed_pc=0x0c0646a4u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0646a6;
P_0c0646a6: /* original 7501, guest PC 0x0c0646a6 */
if(!s->budget--) { s->failed_pc=0x0c0646a6u; return 0; }
r[5]+=0x00000001u;
goto P_0c0646a8;
P_0c0646a8: /* original 5111, guest PC 0x0c0646a8 */
if(!s->budget--) { s->failed_pc=0x0c0646a8u; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c0646aa;
P_0c0646aa: /* original 4208, guest PC 0x0c0646aa */
if(!s->budget--) { s->failed_pc=0x0c0646aau; return 0; }
r[2]<<=2;
goto P_0c0646ac;
P_0c0646ac: /* original 0216, guest PC 0x0c0646ac */
if(!s->budget--) { s->failed_pc=0x0c0646acu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0646ae;
P_0c0646ae: /* original 6253, guest PC 0x0c0646ae */
if(!s->budget--) { s->failed_pc=0x0c0646aeu; return 0; }
r[2]=r[5];
goto P_0c0646b0;
P_0c0646b0: /* original 7501, guest PC 0x0c0646b0 */
if(!s->budget--) { s->failed_pc=0x0c0646b0u; return 0; }
r[5]+=0x00000001u;
goto P_0c0646b2;
P_0c0646b2: /* original 4208, guest PC 0x0c0646b2 */
if(!s->budget--) { s->failed_pc=0x0c0646b2u; return 0; }
r[2]<<=2;
goto P_0c0646b4;
P_0c0646b4: /* original 6172, guest PC 0x0c0646b4 */
if(!s->budget--) { s->failed_pc=0x0c0646b4u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0646b6;
P_0c0646b6: /* original 5112, guest PC 0x0c0646b6 */
if(!s->budget--) { s->failed_pc=0x0c0646b6u; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c0646b8;
P_0c0646b8: /* original 0216, guest PC 0x0c0646b8 */
if(!s->budget--) { s->failed_pc=0x0c0646b8u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0646ba;
P_0c0646ba: /* original 6253, guest PC 0x0c0646ba */
if(!s->budget--) { s->failed_pc=0x0c0646bau; return 0; }
r[2]=r[5];
goto P_0c0646bc;
P_0c0646bc: /* original 6172, guest PC 0x0c0646bc */
if(!s->budget--) { s->failed_pc=0x0c0646bcu; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0646be;
P_0c0646be: /* original 7501, guest PC 0x0c0646be */
if(!s->budget--) { s->failed_pc=0x0c0646beu; return 0; }
r[5]+=0x00000001u;
goto P_0c0646c0;
P_0c0646c0: /* original 5113, guest PC 0x0c0646c0 */
if(!s->budget--) { s->failed_pc=0x0c0646c0u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c0646c2;
P_0c0646c2: /* original 4208, guest PC 0x0c0646c2 */
if(!s->budget--) { s->failed_pc=0x0c0646c2u; return 0; }
r[2]<<=2;
goto P_0c0646c4;
P_0c0646c4: /* original 0216, guest PC 0x0c0646c4 */
if(!s->budget--) { s->failed_pc=0x0c0646c4u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0646c6;
P_0c0646c6: /* original 6253, guest PC 0x0c0646c6 */
if(!s->budget--) { s->failed_pc=0x0c0646c6u; return 0; }
r[2]=r[5];
goto P_0c0646c8;
P_0c0646c8: /* original 6172, guest PC 0x0c0646c8 */
if(!s->budget--) { s->failed_pc=0x0c0646c8u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0646ca;
P_0c0646ca: /* original 7501, guest PC 0x0c0646ca */
if(!s->budget--) { s->failed_pc=0x0c0646cau; return 0; }
r[5]+=0x00000001u;
goto P_0c0646cc;
P_0c0646cc: /* original 5116, guest PC 0x0c0646cc */
if(!s->budget--) { s->failed_pc=0x0c0646ccu; return 0; }
r[1]=read(ram,r[1]+24,4);
goto P_0c0646ce;
P_0c0646ce: /* original 4208, guest PC 0x0c0646ce */
if(!s->budget--) { s->failed_pc=0x0c0646ceu; return 0; }
r[2]<<=2;
goto P_0c0646d0;
P_0c0646d0: /* original 0216, guest PC 0x0c0646d0 */
if(!s->budget--) { s->failed_pc=0x0c0646d0u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0646d2;
P_0c0646d2: /* original 4508, guest PC 0x0c0646d2 */
if(!s->budget--) { s->failed_pc=0x0c0646d2u; return 0; }
r[5]<<=2;
goto P_0c0646d4;
P_0c0646d4: /* original d224, guest PC 0x0c0646d4 */
if(!s->budget--) { s->failed_pc=0x0c0646d4u; return 0; }
r[2]=read(ram,0x0c064768u,4);
goto P_0c0646d6;
P_0c0646d6: /* original 2252, guest PC 0x0c0646d6 */
if(!s->budget--) { s->failed_pc=0x0c0646d6u; return 0; }
write(ram,r[2],r[5],4);
goto P_0c0646d8;
P_0c0646d8: /* original bf1b, guest PC 0x0c0646d8 */
if(!s->budget--) { s->failed_pc=0x0c0646d8u; return 0; }
target=0x0c064512u; r[16]=0x0c0646dcu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0646dcu) { target=s->pc; goto dispatch; }
goto P_0c0646dc;
P_0c0646da: /* original 64d3, guest PC 0x0c0646da */
if(!s->budget--) { s->failed_pc=0x0c0646dau; return 0; }
r[4]=r[13];
goto P_0c0646dc;
P_0c0646dc: /* original 6403, guest PC 0x0c0646dc */
if(!s->budget--) { s->failed_pc=0x0c0646dcu; return 0; }
r[4]=r[0];
goto P_0c0646de;
P_0c0646de: /* original e500, guest PC 0x0c0646de */
if(!s->budget--) { s->failed_pc=0x0c0646deu; return 0; }
r[5]=0x00000000u;
goto P_0c0646e0;
P_0c0646e0: /* original bf02, guest PC 0x0c0646e0 */
if(!s->budget--) { s->failed_pc=0x0c0646e0u; return 0; }
target=0x0c0644e8u; r[16]=0x0c0646e4u;
r[6]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0646e4u) { target=s->pc; goto dispatch; }
goto P_0c0646e4;
P_0c0646e2: /* original 6653, guest PC 0x0c0646e2 */
if(!s->budget--) { s->failed_pc=0x0c0646e2u; return 0; }
r[6]=r[5];
goto P_0c0646e4;
P_0c0646e4: /* original 62e2, guest PC 0x0c0646e4 */
if(!s->budget--) { s->failed_pc=0x0c0646e4u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0646e6;
P_0c0646e6: /* original 5323, guest PC 0x0c0646e6 */
if(!s->budget--) { s->failed_pc=0x0c0646e6u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c0646e8;
P_0c0646e8: /* original d11b, guest PC 0x0c0646e8 */
if(!s->budget--) { s->failed_pc=0x0c0646e8u; return 0; }
r[1]=read(ram,0x0c064758u,4);
goto P_0c0646ea;
P_0c0646ea: /* original 2132, guest PC 0x0c0646ea */
if(!s->budget--) { s->failed_pc=0x0c0646eau; return 0; }
write(ram,r[1],r[3],4);
goto P_0c0646ec;
P_0c0646ec: /* original e000, guest PC 0x0c0646ec */
if(!s->budget--) { s->failed_pc=0x0c0646ecu; return 0; }
r[0]=0x00000000u;
goto P_0c0646ee;
P_0c0646ee: /* original 7f10, guest PC 0x0c0646ee */
if(!s->budget--) { s->failed_pc=0x0c0646eeu; return 0; }
r[15]+=0x00000010u;
goto P_0c0646f0;
P_0c0646f0: /* original 4f26, guest PC 0x0c0646f0 */
if(!s->budget--) { s->failed_pc=0x0c0646f0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0646f2;
P_0c0646f2: /* original 6df6, guest PC 0x0c0646f2 */
if(!s->budget--) { s->failed_pc=0x0c0646f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0646f4;
P_0c0646f4: /* original 000b, guest PC 0x0c0646f4 */
if(!s->budget--) { s->failed_pc=0x0c0646f4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0646f6: /* original 6ef6, guest PC 0x0c0646f6 */
if(!s->budget--) { s->failed_pc=0x0c0646f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0646f8u,s,ram);
P_0c064930: /* original 4f22, guest PC 0x0c064930 */
if(!s->budget--) { s->failed_pc=0x0c064930u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c064932;
P_0c064932: /* original 7ff0, guest PC 0x0c064932 */
if(!s->budget--) { s->failed_pc=0x0c064932u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c064934;
P_0c064934: /* original 6342, guest PC 0x0c064934 */
if(!s->budget--) { s->failed_pc=0x0c064934u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c064936;
P_0c064936: /* original 6df3, guest PC 0x0c064936 */
if(!s->budget--) { s->failed_pc=0x0c064936u; return 0; }
r[13]=r[15];
goto P_0c064938;
P_0c064938: /* original 7d04, guest PC 0x0c064938 */
if(!s->budget--) { s->failed_pc=0x0c064938u; return 0; }
r[13]+=0x00000004u;
goto P_0c06493a;
P_0c06493a: /* original 6ed3, guest PC 0x0c06493a */
if(!s->budget--) { s->failed_pc=0x0c06493au; return 0; }
r[14]=r[13];
goto P_0c06493c;
P_0c06493c: /* original 2e32, guest PC 0x0c06493c */
if(!s->budget--) { s->failed_pc=0x0c06493cu; return 0; }
write(ram,r[14],r[3],4);
goto P_0c06493e;
P_0c06493e: /* original 67e3, guest PC 0x0c06493e */
if(!s->budget--) { s->failed_pc=0x0c06493eu; return 0; }
r[7]=r[14];
goto P_0c064940;
P_0c064940: /* original 5241, guest PC 0x0c064940 */
if(!s->budget--) { s->failed_pc=0x0c064940u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c064942;
P_0c064942: /* original 66e3, guest PC 0x0c064942 */
if(!s->budget--) { s->failed_pc=0x0c064942u; return 0; }
r[6]=r[14];
goto P_0c064944;
P_0c064944: /* original 7704, guest PC 0x0c064944 */
if(!s->budget--) { s->failed_pc=0x0c064944u; return 0; }
r[7]+=0x00000004u;
goto P_0c064946;
P_0c064946: /* original 7608, guest PC 0x0c064946 */
if(!s->budget--) { s->failed_pc=0x0c064946u; return 0; }
r[6]+=0x00000008u;
goto P_0c064948;
P_0c064948: /* original 2722, guest PC 0x0c064948 */
if(!s->budget--) { s->failed_pc=0x0c064948u; return 0; }
write(ram,r[7],r[2],4);
goto P_0c06494a;
P_0c06494a: /* original 5342, guest PC 0x0c06494a */
if(!s->budget--) { s->failed_pc=0x0c06494au; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c06494c;
P_0c06494c: /* original d250, guest PC 0x0c06494c */
if(!s->budget--) { s->failed_pc=0x0c06494cu; return 0; }
r[2]=read(ram,0x0c064a90u,4);
goto P_0c06494e;
P_0c06494e: /* original 2632, guest PC 0x0c06494e */
if(!s->budget--) { s->failed_pc=0x0c06494eu; return 0; }
write(ram,r[6],r[3],4);
goto P_0c064950;
P_0c064950: /* original 6d22, guest PC 0x0c064950 */
if(!s->budget--) { s->failed_pc=0x0c064950u; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c064952;
P_0c064952: /* original d150, guest PC 0x0c064952 */
if(!s->budget--) { s->failed_pc=0x0c064952u; return 0; }
r[1]=read(ram,0x0c064a94u,4);
goto P_0c064954;
P_0c064954: /* original 6312, guest PC 0x0c064954 */
if(!s->budget--) { s->failed_pc=0x0c064954u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c064956;
P_0c064956: /* original 2f32, guest PC 0x0c064956 */
if(!s->budget--) { s->failed_pc=0x0c064956u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c064958;
P_0c064958: /* original d34f, guest PC 0x0c064958 */
if(!s->budget--) { s->failed_pc=0x0c064958u; return 0; }
r[3]=read(ram,0x0c064a98u,4);
goto P_0c06495a;
P_0c06495a: /* original 6432, guest PC 0x0c06495a */
if(!s->budget--) { s->failed_pc=0x0c06495au; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c06495c;
P_0c06495c: /* original d04f, guest PC 0x0c06495c */
if(!s->budget--) { s->failed_pc=0x0c06495cu; return 0; }
r[0]=read(ram,0x0c064a9cu,4);
goto P_0c06495e;
P_0c06495e: /* original 6253, guest PC 0x0c06495e */
if(!s->budget--) { s->failed_pc=0x0c06495eu; return 0; }
r[2]=r[5];
goto P_0c064960;
P_0c064960: /* original 7501, guest PC 0x0c064960 */
if(!s->budget--) { s->failed_pc=0x0c064960u; return 0; }
r[5]+=0x00000001u;
goto P_0c064962;
P_0c064962: /* original 4208, guest PC 0x0c064962 */
if(!s->budget--) { s->failed_pc=0x0c064962u; return 0; }
r[2]<<=2;
goto P_0c064964;
P_0c064964: /* original 02d6, guest PC 0x0c064964 */
if(!s->budget--) { s->failed_pc=0x0c064964u; return 0; }
write(ram,r[2]+r[0],r[13],4);
goto P_0c064966;
P_0c064966: /* original 6153, guest PC 0x0c064966 */
if(!s->budget--) { s->failed_pc=0x0c064966u; return 0; }
r[1]=r[5];
goto P_0c064968;
P_0c064968: /* original 62f2, guest PC 0x0c064968 */
if(!s->budget--) { s->failed_pc=0x0c064968u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c06496a;
P_0c06496a: /* original 7501, guest PC 0x0c06496a */
if(!s->budget--) { s->failed_pc=0x0c06496au; return 0; }
r[5]+=0x00000001u;
goto P_0c06496c;
P_0c06496c: /* original 4108, guest PC 0x0c06496c */
if(!s->budget--) { s->failed_pc=0x0c06496cu; return 0; }
r[1]<<=2;
goto P_0c06496e;
P_0c06496e: /* original 0126, guest PC 0x0c06496e */
if(!s->budget--) { s->failed_pc=0x0c06496eu; return 0; }
write(ram,r[1]+r[0],r[2],4);
goto P_0c064970;
P_0c064970: /* original 6153, guest PC 0x0c064970 */
if(!s->budget--) { s->failed_pc=0x0c064970u; return 0; }
r[1]=r[5];
goto P_0c064972;
P_0c064972: /* original 7501, guest PC 0x0c064972 */
if(!s->budget--) { s->failed_pc=0x0c064972u; return 0; }
r[5]+=0x00000001u;
goto P_0c064974;
P_0c064974: /* original 4108, guest PC 0x0c064974 */
if(!s->budget--) { s->failed_pc=0x0c064974u; return 0; }
r[1]<<=2;
goto P_0c064976;
P_0c064976: /* original 0146, guest PC 0x0c064976 */
if(!s->budget--) { s->failed_pc=0x0c064976u; return 0; }
write(ram,r[1]+r[0],r[4],4);
goto P_0c064978;
P_0c064978: /* original 61e2, guest PC 0x0c064978 */
if(!s->budget--) { s->failed_pc=0x0c064978u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c06497a;
P_0c06497a: /* original 6253, guest PC 0x0c06497a */
if(!s->budget--) { s->failed_pc=0x0c06497au; return 0; }
r[2]=r[5];
goto P_0c06497c;
P_0c06497c: /* original 5111, guest PC 0x0c06497c */
if(!s->budget--) { s->failed_pc=0x0c06497cu; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c06497e;
P_0c06497e: /* original 7501, guest PC 0x0c06497e */
if(!s->budget--) { s->failed_pc=0x0c06497eu; return 0; }
r[5]+=0x00000001u;
goto P_0c064980;
P_0c064980: /* original 4208, guest PC 0x0c064980 */
if(!s->budget--) { s->failed_pc=0x0c064980u; return 0; }
r[2]<<=2;
goto P_0c064982;
P_0c064982: /* original 0216, guest PC 0x0c064982 */
if(!s->budget--) { s->failed_pc=0x0c064982u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064984;
P_0c064984: /* original 61e2, guest PC 0x0c064984 */
if(!s->budget--) { s->failed_pc=0x0c064984u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c064986;
P_0c064986: /* original 6253, guest PC 0x0c064986 */
if(!s->budget--) { s->failed_pc=0x0c064986u; return 0; }
r[2]=r[5];
goto P_0c064988;
P_0c064988: /* original 5112, guest PC 0x0c064988 */
if(!s->budget--) { s->failed_pc=0x0c064988u; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c06498a;
P_0c06498a: /* original 7501, guest PC 0x0c06498a */
if(!s->budget--) { s->failed_pc=0x0c06498au; return 0; }
r[5]+=0x00000001u;
goto P_0c06498c;
P_0c06498c: /* original 4208, guest PC 0x0c06498c */
if(!s->budget--) { s->failed_pc=0x0c06498cu; return 0; }
r[2]<<=2;
goto P_0c06498e;
P_0c06498e: /* original 0216, guest PC 0x0c06498e */
if(!s->budget--) { s->failed_pc=0x0c06498eu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064990;
P_0c064990: /* original 61e2, guest PC 0x0c064990 */
if(!s->budget--) { s->failed_pc=0x0c064990u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c064992;
P_0c064992: /* original 6253, guest PC 0x0c064992 */
if(!s->budget--) { s->failed_pc=0x0c064992u; return 0; }
r[2]=r[5];
goto P_0c064994;
P_0c064994: /* original 5113, guest PC 0x0c064994 */
if(!s->budget--) { s->failed_pc=0x0c064994u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c064996;
P_0c064996: /* original 7501, guest PC 0x0c064996 */
if(!s->budget--) { s->failed_pc=0x0c064996u; return 0; }
r[5]+=0x00000001u;
goto P_0c064998;
P_0c064998: /* original 4208, guest PC 0x0c064998 */
if(!s->budget--) { s->failed_pc=0x0c064998u; return 0; }
r[2]<<=2;
goto P_0c06499a;
P_0c06499a: /* original 0216, guest PC 0x0c06499a */
if(!s->budget--) { s->failed_pc=0x0c06499au; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06499c;
P_0c06499c: /* original c740, guest PC 0x0c06499c */
if(!s->budget--) { s->failed_pc=0x0c06499cu; return 0; }
r[0]=0x0c064aa0u;
goto P_0c06499e;
P_0c06499e: /* original 6253, guest PC 0x0c06499e */
if(!s->budget--) { s->failed_pc=0x0c06499eu; return 0; }
r[2]=r[5];
goto P_0c0649a0;
P_0c0649a0: /* original f408, guest PC 0x0c0649a0 */
if(!s->budget--) { s->failed_pc=0x0c0649a0u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0649a2;
P_0c0649a2: /* original 7501, guest PC 0x0c0649a2 */
if(!s->budget--) { s->failed_pc=0x0c0649a2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0649a4;
P_0c0649a4: /* original d03d, guest PC 0x0c0649a4 */
if(!s->budget--) { s->failed_pc=0x0c0649a4u; return 0; }
r[0]=read(ram,0x0c064a9cu,4);
goto P_0c0649a6;
P_0c0649a6: /* original 4208, guest PC 0x0c0649a6 */
if(!s->budget--) { s->failed_pc=0x0c0649a6u; return 0; }
r[2]<<=2;
goto P_0c0649a8;
P_0c0649a8: /* original 64e2, guest PC 0x0c0649a8 */
if(!s->budget--) { s->failed_pc=0x0c0649a8u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0649aa;
P_0c0649aa: /* original e118, guest PC 0x0c0649aa */
if(!s->budget--) { s->failed_pc=0x0c0649aau; return 0; }
r[1]=0x00000018u;
goto P_0c0649ac;
P_0c0649ac: /* original 314c, guest PC 0x0c0649ac */
if(!s->budget--) { s->failed_pc=0x0c0649acu; return 0; }
r[1]+=r[4];
goto P_0c0649ae;
P_0c0649ae: /* original f318, guest PC 0x0c0649ae */
if(!s->budget--) { s->failed_pc=0x0c0649aeu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0649b0;
P_0c0649b0: /* original f342, guest PC 0x0c0649b0 */
if(!s->budget--) { s->failed_pc=0x0c0649b0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0649b2;
P_0c0649b2: /* original f33d, guest PC 0x0c0649b2 */
if(!s->budget--) { s->failed_pc=0x0c0649b2u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0649b4;
P_0c0649b4: /* original 045a, guest PC 0x0c0649b4 */
if(!s->budget--) { s->failed_pc=0x0c0649b4u; return 0; }
r[4]=r[53];
goto P_0c0649b6;
P_0c0649b6: /* original 6143, guest PC 0x0c0649b6 */
if(!s->budget--) { s->failed_pc=0x0c0649b6u; return 0; }
r[1]=r[4];
goto P_0c0649b8;
P_0c0649b8: /* original 4128, guest PC 0x0c0649b8 */
if(!s->budget--) { s->failed_pc=0x0c0649b8u; return 0; }
r[1]<<=16;
goto P_0c0649ba;
P_0c0649ba: /* original 4118, guest PC 0x0c0649ba */
if(!s->budget--) { s->failed_pc=0x0c0649bau; return 0; }
r[1]<<=8;
goto P_0c0649bc;
P_0c0649bc: /* original 6343, guest PC 0x0c0649bc */
if(!s->budget--) { s->failed_pc=0x0c0649bcu; return 0; }
r[3]=r[4];
goto P_0c0649be;
P_0c0649be: /* original 4328, guest PC 0x0c0649be */
if(!s->budget--) { s->failed_pc=0x0c0649beu; return 0; }
r[3]<<=16;
goto P_0c0649c0;
P_0c0649c0: /* original 213b, guest PC 0x0c0649c0 */
if(!s->budget--) { s->failed_pc=0x0c0649c0u; return 0; }
r[1]|=r[3];
goto P_0c0649c2;
P_0c0649c2: /* original 6343, guest PC 0x0c0649c2 */
if(!s->budget--) { s->failed_pc=0x0c0649c2u; return 0; }
r[3]=r[4];
goto P_0c0649c4;
P_0c0649c4: /* original 4318, guest PC 0x0c0649c4 */
if(!s->budget--) { s->failed_pc=0x0c0649c4u; return 0; }
r[3]<<=8;
goto P_0c0649c6;
P_0c0649c6: /* original 213b, guest PC 0x0c0649c6 */
if(!s->budget--) { s->failed_pc=0x0c0649c6u; return 0; }
r[1]|=r[3];
goto P_0c0649c8;
P_0c0649c8: /* original 214b, guest PC 0x0c0649c8 */
if(!s->budget--) { s->failed_pc=0x0c0649c8u; return 0; }
r[1]|=r[4];
goto P_0c0649ca;
P_0c0649ca: /* original 0216, guest PC 0x0c0649ca */
if(!s->budget--) { s->failed_pc=0x0c0649cau; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0649cc;
P_0c0649cc: /* original 6172, guest PC 0x0c0649cc */
if(!s->budget--) { s->failed_pc=0x0c0649ccu; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0649ce;
P_0c0649ce: /* original 6253, guest PC 0x0c0649ce */
if(!s->budget--) { s->failed_pc=0x0c0649ceu; return 0; }
r[2]=r[5];
goto P_0c0649d0;
P_0c0649d0: /* original 5311, guest PC 0x0c0649d0 */
if(!s->budget--) { s->failed_pc=0x0c0649d0u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c0649d2;
P_0c0649d2: /* original 7501, guest PC 0x0c0649d2 */
if(!s->budget--) { s->failed_pc=0x0c0649d2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0649d4;
P_0c0649d4: /* original 4208, guest PC 0x0c0649d4 */
if(!s->budget--) { s->failed_pc=0x0c0649d4u; return 0; }
r[2]<<=2;
goto P_0c0649d6;
P_0c0649d6: /* original 0236, guest PC 0x0c0649d6 */
if(!s->budget--) { s->failed_pc=0x0c0649d6u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0649d8;
P_0c0649d8: /* original 6172, guest PC 0x0c0649d8 */
if(!s->budget--) { s->failed_pc=0x0c0649d8u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0649da;
P_0c0649da: /* original 6253, guest PC 0x0c0649da */
if(!s->budget--) { s->failed_pc=0x0c0649dau; return 0; }
r[2]=r[5];
goto P_0c0649dc;
P_0c0649dc: /* original 5312, guest PC 0x0c0649dc */
if(!s->budget--) { s->failed_pc=0x0c0649dcu; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c0649de;
P_0c0649de: /* original 7501, guest PC 0x0c0649de */
if(!s->budget--) { s->failed_pc=0x0c0649deu; return 0; }
r[5]+=0x00000001u;
goto P_0c0649e0;
P_0c0649e0: /* original 4208, guest PC 0x0c0649e0 */
if(!s->budget--) { s->failed_pc=0x0c0649e0u; return 0; }
r[2]<<=2;
goto P_0c0649e2;
P_0c0649e2: /* original 0236, guest PC 0x0c0649e2 */
if(!s->budget--) { s->failed_pc=0x0c0649e2u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0649e4;
P_0c0649e4: /* original 6253, guest PC 0x0c0649e4 */
if(!s->budget--) { s->failed_pc=0x0c0649e4u; return 0; }
r[2]=r[5];
goto P_0c0649e6;
P_0c0649e6: /* original 7501, guest PC 0x0c0649e6 */
if(!s->budget--) { s->failed_pc=0x0c0649e6u; return 0; }
r[5]+=0x00000001u;
goto P_0c0649e8;
P_0c0649e8: /* original 6172, guest PC 0x0c0649e8 */
if(!s->budget--) { s->failed_pc=0x0c0649e8u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0649ea;
P_0c0649ea: /* original 4208, guest PC 0x0c0649ea */
if(!s->budget--) { s->failed_pc=0x0c0649eau; return 0; }
r[2]<<=2;
goto P_0c0649ec;
P_0c0649ec: /* original 5313, guest PC 0x0c0649ec */
if(!s->budget--) { s->failed_pc=0x0c0649ecu; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c0649ee;
P_0c0649ee: /* original 0236, guest PC 0x0c0649ee */
if(!s->budget--) { s->failed_pc=0x0c0649eeu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0649f0;
P_0c0649f0: /* original 6472, guest PC 0x0c0649f0 */
if(!s->budget--) { s->failed_pc=0x0c0649f0u; return 0; }
tmp=read(ram,r[7],4);
r[4]=tmp;
goto P_0c0649f2;
P_0c0649f2: /* original e118, guest PC 0x0c0649f2 */
if(!s->budget--) { s->failed_pc=0x0c0649f2u; return 0; }
r[1]=0x00000018u;
goto P_0c0649f4;
P_0c0649f4: /* original 6253, guest PC 0x0c0649f4 */
if(!s->budget--) { s->failed_pc=0x0c0649f4u; return 0; }
r[2]=r[5];
goto P_0c0649f6;
P_0c0649f6: /* original 7501, guest PC 0x0c0649f6 */
if(!s->budget--) { s->failed_pc=0x0c0649f6u; return 0; }
r[5]+=0x00000001u;
goto P_0c0649f8;
P_0c0649f8: /* original 4208, guest PC 0x0c0649f8 */
if(!s->budget--) { s->failed_pc=0x0c0649f8u; return 0; }
r[2]<<=2;
goto P_0c0649fa;
P_0c0649fa: /* original 314c, guest PC 0x0c0649fa */
if(!s->budget--) { s->failed_pc=0x0c0649fau; return 0; }
r[1]+=r[4];
goto P_0c0649fc;
P_0c0649fc: /* original f318, guest PC 0x0c0649fc */
if(!s->budget--) { s->failed_pc=0x0c0649fcu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0649fe;
P_0c0649fe: /* original f342, guest PC 0x0c0649fe */
if(!s->budget--) { s->failed_pc=0x0c0649feu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c064a00;
P_0c064a00: /* original f33d, guest PC 0x0c064a00 */
if(!s->budget--) { s->failed_pc=0x0c064a00u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064a02;
P_0c064a02: /* original 045a, guest PC 0x0c064a02 */
if(!s->budget--) { s->failed_pc=0x0c064a02u; return 0; }
r[4]=r[53];
goto P_0c064a04;
P_0c064a04: /* original 6343, guest PC 0x0c064a04 */
if(!s->budget--) { s->failed_pc=0x0c064a04u; return 0; }
r[3]=r[4];
goto P_0c064a06;
P_0c064a06: /* original 4328, guest PC 0x0c064a06 */
if(!s->budget--) { s->failed_pc=0x0c064a06u; return 0; }
r[3]<<=16;
goto P_0c064a08;
P_0c064a08: /* original 4318, guest PC 0x0c064a08 */
if(!s->budget--) { s->failed_pc=0x0c064a08u; return 0; }
r[3]<<=8;
goto P_0c064a0a;
P_0c064a0a: /* original 6143, guest PC 0x0c064a0a */
if(!s->budget--) { s->failed_pc=0x0c064a0au; return 0; }
r[1]=r[4];
goto P_0c064a0c;
P_0c064a0c: /* original 4128, guest PC 0x0c064a0c */
if(!s->budget--) { s->failed_pc=0x0c064a0cu; return 0; }
r[1]<<=16;
goto P_0c064a0e;
P_0c064a0e: /* original 231b, guest PC 0x0c064a0e */
if(!s->budget--) { s->failed_pc=0x0c064a0eu; return 0; }
r[3]|=r[1];
goto P_0c064a10;
P_0c064a10: /* original 6143, guest PC 0x0c064a10 */
if(!s->budget--) { s->failed_pc=0x0c064a10u; return 0; }
r[1]=r[4];
goto P_0c064a12;
P_0c064a12: /* original 4118, guest PC 0x0c064a12 */
if(!s->budget--) { s->failed_pc=0x0c064a12u; return 0; }
r[1]<<=8;
goto P_0c064a14;
P_0c064a14: /* original 231b, guest PC 0x0c064a14 */
if(!s->budget--) { s->failed_pc=0x0c064a14u; return 0; }
r[3]|=r[1];
goto P_0c064a16;
P_0c064a16: /* original 234b, guest PC 0x0c064a16 */
if(!s->budget--) { s->failed_pc=0x0c064a16u; return 0; }
r[3]|=r[4];
goto P_0c064a18;
P_0c064a18: /* original 0236, guest PC 0x0c064a18 */
if(!s->budget--) { s->failed_pc=0x0c064a18u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064a1a;
P_0c064a1a: /* original 6253, guest PC 0x0c064a1a */
if(!s->budget--) { s->failed_pc=0x0c064a1au; return 0; }
r[2]=r[5];
goto P_0c064a1c;
P_0c064a1c: /* original 6162, guest PC 0x0c064a1c */
if(!s->budget--) { s->failed_pc=0x0c064a1cu; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c064a1e;
P_0c064a1e: /* original 7501, guest PC 0x0c064a1e */
if(!s->budget--) { s->failed_pc=0x0c064a1eu; return 0; }
r[5]+=0x00000001u;
goto P_0c064a20;
P_0c064a20: /* original 5311, guest PC 0x0c064a20 */
if(!s->budget--) { s->failed_pc=0x0c064a20u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c064a22;
P_0c064a22: /* original 4208, guest PC 0x0c064a22 */
if(!s->budget--) { s->failed_pc=0x0c064a22u; return 0; }
r[2]<<=2;
goto P_0c064a24;
P_0c064a24: /* original 0236, guest PC 0x0c064a24 */
if(!s->budget--) { s->failed_pc=0x0c064a24u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064a26;
P_0c064a26: /* original 6253, guest PC 0x0c064a26 */
if(!s->budget--) { s->failed_pc=0x0c064a26u; return 0; }
r[2]=r[5];
goto P_0c064a28;
P_0c064a28: /* original 6162, guest PC 0x0c064a28 */
if(!s->budget--) { s->failed_pc=0x0c064a28u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c064a2a;
P_0c064a2a: /* original 7501, guest PC 0x0c064a2a */
if(!s->budget--) { s->failed_pc=0x0c064a2au; return 0; }
r[5]+=0x00000001u;
goto P_0c064a2c;
P_0c064a2c: /* original 5312, guest PC 0x0c064a2c */
if(!s->budget--) { s->failed_pc=0x0c064a2cu; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c064a2e;
P_0c064a2e: /* original 4208, guest PC 0x0c064a2e */
if(!s->budget--) { s->failed_pc=0x0c064a2eu; return 0; }
r[2]<<=2;
goto P_0c064a30;
P_0c064a30: /* original 0236, guest PC 0x0c064a30 */
if(!s->budget--) { s->failed_pc=0x0c064a30u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064a32;
P_0c064a32: /* original 6253, guest PC 0x0c064a32 */
if(!s->budget--) { s->failed_pc=0x0c064a32u; return 0; }
r[2]=r[5];
goto P_0c064a34;
P_0c064a34: /* original 6162, guest PC 0x0c064a34 */
if(!s->budget--) { s->failed_pc=0x0c064a34u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c064a36;
P_0c064a36: /* original 7501, guest PC 0x0c064a36 */
if(!s->budget--) { s->failed_pc=0x0c064a36u; return 0; }
r[5]+=0x00000001u;
goto P_0c064a38;
P_0c064a38: /* original 5313, guest PC 0x0c064a38 */
if(!s->budget--) { s->failed_pc=0x0c064a38u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c064a3a;
P_0c064a3a: /* original 4208, guest PC 0x0c064a3a */
if(!s->budget--) { s->failed_pc=0x0c064a3au; return 0; }
r[2]<<=2;
goto P_0c064a3c;
P_0c064a3c: /* original 0236, guest PC 0x0c064a3c */
if(!s->budget--) { s->failed_pc=0x0c064a3cu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064a3e;
P_0c064a3e: /* original 6253, guest PC 0x0c064a3e */
if(!s->budget--) { s->failed_pc=0x0c064a3eu; return 0; }
r[2]=r[5];
goto P_0c064a40;
P_0c064a40: /* original 6462, guest PC 0x0c064a40 */
if(!s->budget--) { s->failed_pc=0x0c064a40u; return 0; }
tmp=read(ram,r[6],4);
r[4]=tmp;
goto P_0c064a42;
P_0c064a42: /* original e118, guest PC 0x0c064a42 */
if(!s->budget--) { s->failed_pc=0x0c064a42u; return 0; }
r[1]=0x00000018u;
goto P_0c064a44;
P_0c064a44: /* original 7501, guest PC 0x0c064a44 */
if(!s->budget--) { s->failed_pc=0x0c064a44u; return 0; }
r[5]+=0x00000001u;
goto P_0c064a46;
P_0c064a46: /* original 4208, guest PC 0x0c064a46 */
if(!s->budget--) { s->failed_pc=0x0c064a46u; return 0; }
r[2]<<=2;
goto P_0c064a48;
P_0c064a48: /* original 314c, guest PC 0x0c064a48 */
if(!s->budget--) { s->failed_pc=0x0c064a48u; return 0; }
r[1]+=r[4];
goto P_0c064a4a;
P_0c064a4a: /* original f318, guest PC 0x0c064a4a */
if(!s->budget--) { s->failed_pc=0x0c064a4au; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c064a4c;
P_0c064a4c: /* original f342, guest PC 0x0c064a4c */
if(!s->budget--) { s->failed_pc=0x0c064a4cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c064a4e;
P_0c064a4e: /* original f33d, guest PC 0x0c064a4e */
if(!s->budget--) { s->failed_pc=0x0c064a4eu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c064a50;
P_0c064a50: /* original 045a, guest PC 0x0c064a50 */
if(!s->budget--) { s->failed_pc=0x0c064a50u; return 0; }
r[4]=r[53];
goto P_0c064a52;
P_0c064a52: /* original 6343, guest PC 0x0c064a52 */
if(!s->budget--) { s->failed_pc=0x0c064a52u; return 0; }
r[3]=r[4];
goto P_0c064a54;
P_0c064a54: /* original 4328, guest PC 0x0c064a54 */
if(!s->budget--) { s->failed_pc=0x0c064a54u; return 0; }
r[3]<<=16;
goto P_0c064a56;
P_0c064a56: /* original 4318, guest PC 0x0c064a56 */
if(!s->budget--) { s->failed_pc=0x0c064a56u; return 0; }
r[3]<<=8;
goto P_0c064a58;
P_0c064a58: /* original 6143, guest PC 0x0c064a58 */
if(!s->budget--) { s->failed_pc=0x0c064a58u; return 0; }
r[1]=r[4];
goto P_0c064a5a;
P_0c064a5a: /* original 4128, guest PC 0x0c064a5a */
if(!s->budget--) { s->failed_pc=0x0c064a5au; return 0; }
r[1]<<=16;
goto P_0c064a5c;
P_0c064a5c: /* original 231b, guest PC 0x0c064a5c */
if(!s->budget--) { s->failed_pc=0x0c064a5cu; return 0; }
r[3]|=r[1];
goto P_0c064a5e;
P_0c064a5e: /* original 6143, guest PC 0x0c064a5e */
if(!s->budget--) { s->failed_pc=0x0c064a5eu; return 0; }
r[1]=r[4];
goto P_0c064a60;
P_0c064a60: /* original 4118, guest PC 0x0c064a60 */
if(!s->budget--) { s->failed_pc=0x0c064a60u; return 0; }
r[1]<<=8;
goto P_0c064a62;
P_0c064a62: /* original 231b, guest PC 0x0c064a62 */
if(!s->budget--) { s->failed_pc=0x0c064a62u; return 0; }
r[3]|=r[1];
goto P_0c064a64;
P_0c064a64: /* original 234b, guest PC 0x0c064a64 */
if(!s->budget--) { s->failed_pc=0x0c064a64u; return 0; }
r[3]|=r[4];
goto P_0c064a66;
P_0c064a66: /* original 0236, guest PC 0x0c064a66 */
if(!s->budget--) { s->failed_pc=0x0c064a66u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064a68;
P_0c064a68: /* original d30e, guest PC 0x0c064a68 */
if(!s->budget--) { s->failed_pc=0x0c064a68u; return 0; }
r[3]=read(ram,0x0c064aa4u,4);
goto P_0c064a6a;
P_0c064a6a: /* original 4508, guest PC 0x0c064a6a */
if(!s->budget--) { s->failed_pc=0x0c064a6au; return 0; }
r[5]<<=2;
goto P_0c064a6c;
P_0c064a6c: /* original 2352, guest PC 0x0c064a6c */
if(!s->budget--) { s->failed_pc=0x0c064a6cu; return 0; }
write(ram,r[3],r[5],4);
goto P_0c064a6e;
P_0c064a6e: /* original bd50, guest PC 0x0c064a6e */
if(!s->budget--) { s->failed_pc=0x0c064a6eu; return 0; }
target=0x0c064512u; r[16]=0x0c064a72u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064a72u) { target=s->pc; goto dispatch; }
goto P_0c064a72;
P_0c064a70: /* original 64d3, guest PC 0x0c064a70 */
if(!s->budget--) { s->failed_pc=0x0c064a70u; return 0; }
r[4]=r[13];
goto P_0c064a72;
P_0c064a72: /* original 6403, guest PC 0x0c064a72 */
if(!s->budget--) { s->failed_pc=0x0c064a72u; return 0; }
r[4]=r[0];
goto P_0c064a74;
P_0c064a74: /* original e500, guest PC 0x0c064a74 */
if(!s->budget--) { s->failed_pc=0x0c064a74u; return 0; }
r[5]=0x00000000u;
goto P_0c064a76;
P_0c064a76: /* original bd37, guest PC 0x0c064a76 */
if(!s->budget--) { s->failed_pc=0x0c064a76u; return 0; }
target=0x0c0644e8u; r[16]=0x0c064a7au;
r[6]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c064a7au) { target=s->pc; goto dispatch; }
goto P_0c064a7a;
P_0c064a78: /* original 6653, guest PC 0x0c064a78 */
if(!s->budget--) { s->failed_pc=0x0c064a78u; return 0; }
r[6]=r[5];
goto P_0c064a7a;
P_0c064a7a: /* original 63e2, guest PC 0x0c064a7a */
if(!s->budget--) { s->failed_pc=0x0c064a7au; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c064a7c;
P_0c064a7c: /* original d10a, guest PC 0x0c064a7c */
if(!s->budget--) { s->failed_pc=0x0c064a7cu; return 0; }
r[1]=read(ram,0x0c064aa8u,4);
goto P_0c064a7e;
P_0c064a7e: /* original 5233, guest PC 0x0c064a7e */
if(!s->budget--) { s->failed_pc=0x0c064a7eu; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c064a80;
P_0c064a80: /* original 2122, guest PC 0x0c064a80 */
if(!s->budget--) { s->failed_pc=0x0c064a80u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c064a82;
P_0c064a82: /* original e000, guest PC 0x0c064a82 */
if(!s->budget--) { s->failed_pc=0x0c064a82u; return 0; }
r[0]=0x00000000u;
goto P_0c064a84;
P_0c064a84: /* original 7f10, guest PC 0x0c064a84 */
if(!s->budget--) { s->failed_pc=0x0c064a84u; return 0; }
r[15]+=0x00000010u;
goto P_0c064a86;
P_0c064a86: /* original 4f26, guest PC 0x0c064a86 */
if(!s->budget--) { s->failed_pc=0x0c064a86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c064a88;
P_0c064a88: /* original 6df6, guest PC 0x0c064a88 */
if(!s->budget--) { s->failed_pc=0x0c064a88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c064a8a;
P_0c064a8a: /* original 000b, guest PC 0x0c064a8a */
if(!s->budget--) { s->failed_pc=0x0c064a8au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c064a8c: /* original 6ef6, guest PC 0x0c064a8c */
if(!s->budget--) { s->failed_pc=0x0c064a8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c064a8eu,s,ram);
P_0c0657fc: /* original 4f22, guest PC 0x0c0657fc */
if(!s->budget--) { s->failed_pc=0x0c0657fcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0657fe;
P_0c0657fe: /* original 7ff0, guest PC 0x0c0657fe */
if(!s->budget--) { s->failed_pc=0x0c0657feu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c065800;
P_0c065800: /* original 6342, guest PC 0x0c065800 */
if(!s->budget--) { s->failed_pc=0x0c065800u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c065802;
P_0c065802: /* original 6df3, guest PC 0x0c065802 */
if(!s->budget--) { s->failed_pc=0x0c065802u; return 0; }
r[13]=r[15];
goto P_0c065804;
P_0c065804: /* original 7d04, guest PC 0x0c065804 */
if(!s->budget--) { s->failed_pc=0x0c065804u; return 0; }
r[13]+=0x00000004u;
goto P_0c065806;
P_0c065806: /* original 6ed3, guest PC 0x0c065806 */
if(!s->budget--) { s->failed_pc=0x0c065806u; return 0; }
r[14]=r[13];
goto P_0c065808;
P_0c065808: /* original 2e32, guest PC 0x0c065808 */
if(!s->budget--) { s->failed_pc=0x0c065808u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c06580a;
P_0c06580a: /* original 66e3, guest PC 0x0c06580a */
if(!s->budget--) { s->failed_pc=0x0c06580au; return 0; }
r[6]=r[14];
goto P_0c06580c;
P_0c06580c: /* original 5241, guest PC 0x0c06580c */
if(!s->budget--) { s->failed_pc=0x0c06580cu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c06580e;
P_0c06580e: /* original 67e3, guest PC 0x0c06580e */
if(!s->budget--) { s->failed_pc=0x0c06580eu; return 0; }
r[7]=r[14];
goto P_0c065810;
P_0c065810: /* original 7604, guest PC 0x0c065810 */
if(!s->budget--) { s->failed_pc=0x0c065810u; return 0; }
r[6]+=0x00000004u;
goto P_0c065812;
P_0c065812: /* original 7708, guest PC 0x0c065812 */
if(!s->budget--) { s->failed_pc=0x0c065812u; return 0; }
r[7]+=0x00000008u;
goto P_0c065814;
P_0c065814: /* original 2622, guest PC 0x0c065814 */
if(!s->budget--) { s->failed_pc=0x0c065814u; return 0; }
write(ram,r[6],r[2],4);
goto P_0c065816;
P_0c065816: /* original 5342, guest PC 0x0c065816 */
if(!s->budget--) { s->failed_pc=0x0c065816u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c065818;
P_0c065818: /* original d239, guest PC 0x0c065818 */
if(!s->budget--) { s->failed_pc=0x0c065818u; return 0; }
r[2]=read(ram,0x0c065900u,4);
goto P_0c06581a;
P_0c06581a: /* original 2732, guest PC 0x0c06581a */
if(!s->budget--) { s->failed_pc=0x0c06581au; return 0; }
write(ram,r[7],r[3],4);
goto P_0c06581c;
P_0c06581c: /* original 6d22, guest PC 0x0c06581c */
if(!s->budget--) { s->failed_pc=0x0c06581cu; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c06581e;
P_0c06581e: /* original d139, guest PC 0x0c06581e */
if(!s->budget--) { s->failed_pc=0x0c06581eu; return 0; }
r[1]=read(ram,0x0c065904u,4);
goto P_0c065820;
P_0c065820: /* original 6312, guest PC 0x0c065820 */
if(!s->budget--) { s->failed_pc=0x0c065820u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c065822;
P_0c065822: /* original 2f32, guest PC 0x0c065822 */
if(!s->budget--) { s->failed_pc=0x0c065822u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c065824;
P_0c065824: /* original d338, guest PC 0x0c065824 */
if(!s->budget--) { s->failed_pc=0x0c065824u; return 0; }
r[3]=read(ram,0x0c065908u,4);
goto P_0c065826;
P_0c065826: /* original 6432, guest PC 0x0c065826 */
if(!s->budget--) { s->failed_pc=0x0c065826u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c065828;
P_0c065828: /* original d038, guest PC 0x0c065828 */
if(!s->budget--) { s->failed_pc=0x0c065828u; return 0; }
r[0]=read(ram,0x0c06590cu,4);
goto P_0c06582a;
P_0c06582a: /* original 6253, guest PC 0x0c06582a */
if(!s->budget--) { s->failed_pc=0x0c06582au; return 0; }
r[2]=r[5];
goto P_0c06582c;
P_0c06582c: /* original 7501, guest PC 0x0c06582c */
if(!s->budget--) { s->failed_pc=0x0c06582cu; return 0; }
r[5]+=0x00000001u;
goto P_0c06582e;
P_0c06582e: /* original 4208, guest PC 0x0c06582e */
if(!s->budget--) { s->failed_pc=0x0c06582eu; return 0; }
r[2]<<=2;
goto P_0c065830;
P_0c065830: /* original 02d6, guest PC 0x0c065830 */
if(!s->budget--) { s->failed_pc=0x0c065830u; return 0; }
write(ram,r[2]+r[0],r[13],4);
goto P_0c065832;
P_0c065832: /* original 6153, guest PC 0x0c065832 */
if(!s->budget--) { s->failed_pc=0x0c065832u; return 0; }
r[1]=r[5];
goto P_0c065834;
P_0c065834: /* original 62f2, guest PC 0x0c065834 */
if(!s->budget--) { s->failed_pc=0x0c065834u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c065836;
P_0c065836: /* original 7501, guest PC 0x0c065836 */
if(!s->budget--) { s->failed_pc=0x0c065836u; return 0; }
r[5]+=0x00000001u;
goto P_0c065838;
P_0c065838: /* original 4108, guest PC 0x0c065838 */
if(!s->budget--) { s->failed_pc=0x0c065838u; return 0; }
r[1]<<=2;
goto P_0c06583a;
P_0c06583a: /* original 0126, guest PC 0x0c06583a */
if(!s->budget--) { s->failed_pc=0x0c06583au; return 0; }
write(ram,r[1]+r[0],r[2],4);
goto P_0c06583c;
P_0c06583c: /* original 6153, guest PC 0x0c06583c */
if(!s->budget--) { s->failed_pc=0x0c06583cu; return 0; }
r[1]=r[5];
goto P_0c06583e;
P_0c06583e: /* original 7501, guest PC 0x0c06583e */
if(!s->budget--) { s->failed_pc=0x0c06583eu; return 0; }
r[5]+=0x00000001u;
goto P_0c065840;
P_0c065840: /* original 4108, guest PC 0x0c065840 */
if(!s->budget--) { s->failed_pc=0x0c065840u; return 0; }
r[1]<<=2;
goto P_0c065842;
P_0c065842: /* original 0146, guest PC 0x0c065842 */
if(!s->budget--) { s->failed_pc=0x0c065842u; return 0; }
write(ram,r[1]+r[0],r[4],4);
goto P_0c065844;
P_0c065844: /* original 61e2, guest PC 0x0c065844 */
if(!s->budget--) { s->failed_pc=0x0c065844u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c065846;
P_0c065846: /* original 6253, guest PC 0x0c065846 */
if(!s->budget--) { s->failed_pc=0x0c065846u; return 0; }
r[2]=r[5];
goto P_0c065848;
P_0c065848: /* original 5111, guest PC 0x0c065848 */
if(!s->budget--) { s->failed_pc=0x0c065848u; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c06584a;
P_0c06584a: /* original 7501, guest PC 0x0c06584a */
if(!s->budget--) { s->failed_pc=0x0c06584au; return 0; }
r[5]+=0x00000001u;
goto P_0c06584c;
P_0c06584c: /* original 4208, guest PC 0x0c06584c */
if(!s->budget--) { s->failed_pc=0x0c06584cu; return 0; }
r[2]<<=2;
goto P_0c06584e;
P_0c06584e: /* original 0216, guest PC 0x0c06584e */
if(!s->budget--) { s->failed_pc=0x0c06584eu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065850;
P_0c065850: /* original 61e2, guest PC 0x0c065850 */
if(!s->budget--) { s->failed_pc=0x0c065850u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c065852;
P_0c065852: /* original 6253, guest PC 0x0c065852 */
if(!s->budget--) { s->failed_pc=0x0c065852u; return 0; }
r[2]=r[5];
goto P_0c065854;
P_0c065854: /* original 5112, guest PC 0x0c065854 */
if(!s->budget--) { s->failed_pc=0x0c065854u; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c065856;
P_0c065856: /* original 7501, guest PC 0x0c065856 */
if(!s->budget--) { s->failed_pc=0x0c065856u; return 0; }
r[5]+=0x00000001u;
goto P_0c065858;
P_0c065858: /* original 4208, guest PC 0x0c065858 */
if(!s->budget--) { s->failed_pc=0x0c065858u; return 0; }
r[2]<<=2;
goto P_0c06585a;
P_0c06585a: /* original 0216, guest PC 0x0c06585a */
if(!s->budget--) { s->failed_pc=0x0c06585au; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06585c;
P_0c06585c: /* original 61e2, guest PC 0x0c06585c */
if(!s->budget--) { s->failed_pc=0x0c06585cu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c06585e;
P_0c06585e: /* original 6253, guest PC 0x0c06585e */
if(!s->budget--) { s->failed_pc=0x0c06585eu; return 0; }
r[2]=r[5];
goto P_0c065860;
P_0c065860: /* original 5113, guest PC 0x0c065860 */
if(!s->budget--) { s->failed_pc=0x0c065860u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c065862;
P_0c065862: /* original 7501, guest PC 0x0c065862 */
if(!s->budget--) { s->failed_pc=0x0c065862u; return 0; }
r[5]+=0x00000001u;
goto P_0c065864;
P_0c065864: /* original 4208, guest PC 0x0c065864 */
if(!s->budget--) { s->failed_pc=0x0c065864u; return 0; }
r[2]<<=2;
goto P_0c065866;
P_0c065866: /* original 0216, guest PC 0x0c065866 */
if(!s->budget--) { s->failed_pc=0x0c065866u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065868;
P_0c065868: /* original 61e2, guest PC 0x0c065868 */
if(!s->budget--) { s->failed_pc=0x0c065868u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c06586a;
P_0c06586a: /* original 6253, guest PC 0x0c06586a */
if(!s->budget--) { s->failed_pc=0x0c06586au; return 0; }
r[2]=r[5];
goto P_0c06586c;
P_0c06586c: /* original 5114, guest PC 0x0c06586c */
if(!s->budget--) { s->failed_pc=0x0c06586cu; return 0; }
r[1]=read(ram,r[1]+16,4);
goto P_0c06586e;
P_0c06586e: /* original 7501, guest PC 0x0c06586e */
if(!s->budget--) { s->failed_pc=0x0c06586eu; return 0; }
r[5]+=0x00000001u;
goto P_0c065870;
P_0c065870: /* original 4208, guest PC 0x0c065870 */
if(!s->budget--) { s->failed_pc=0x0c065870u; return 0; }
r[2]<<=2;
goto P_0c065872;
P_0c065872: /* original 0216, guest PC 0x0c065872 */
if(!s->budget--) { s->failed_pc=0x0c065872u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065874;
P_0c065874: /* original 6162, guest PC 0x0c065874 */
if(!s->budget--) { s->failed_pc=0x0c065874u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c065876;
P_0c065876: /* original 6253, guest PC 0x0c065876 */
if(!s->budget--) { s->failed_pc=0x0c065876u; return 0; }
r[2]=r[5];
goto P_0c065878;
P_0c065878: /* original 5111, guest PC 0x0c065878 */
if(!s->budget--) { s->failed_pc=0x0c065878u; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c06587a;
P_0c06587a: /* original 7501, guest PC 0x0c06587a */
if(!s->budget--) { s->failed_pc=0x0c06587au; return 0; }
r[5]+=0x00000001u;
goto P_0c06587c;
P_0c06587c: /* original 4208, guest PC 0x0c06587c */
if(!s->budget--) { s->failed_pc=0x0c06587cu; return 0; }
r[2]<<=2;
goto P_0c06587e;
P_0c06587e: /* original 0216, guest PC 0x0c06587e */
if(!s->budget--) { s->failed_pc=0x0c06587eu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065880;
P_0c065880: /* original 6162, guest PC 0x0c065880 */
if(!s->budget--) { s->failed_pc=0x0c065880u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c065882;
P_0c065882: /* original 6253, guest PC 0x0c065882 */
if(!s->budget--) { s->failed_pc=0x0c065882u; return 0; }
r[2]=r[5];
goto P_0c065884;
P_0c065884: /* original 5112, guest PC 0x0c065884 */
if(!s->budget--) { s->failed_pc=0x0c065884u; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c065886;
P_0c065886: /* original 7501, guest PC 0x0c065886 */
if(!s->budget--) { s->failed_pc=0x0c065886u; return 0; }
r[5]+=0x00000001u;
goto P_0c065888;
P_0c065888: /* original 4208, guest PC 0x0c065888 */
if(!s->budget--) { s->failed_pc=0x0c065888u; return 0; }
r[2]<<=2;
goto P_0c06588a;
P_0c06588a: /* original 0216, guest PC 0x0c06588a */
if(!s->budget--) { s->failed_pc=0x0c06588au; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06588c;
P_0c06588c: /* original 6162, guest PC 0x0c06588c */
if(!s->budget--) { s->failed_pc=0x0c06588cu; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c06588e;
P_0c06588e: /* original 6253, guest PC 0x0c06588e */
if(!s->budget--) { s->failed_pc=0x0c06588eu; return 0; }
r[2]=r[5];
goto P_0c065890;
P_0c065890: /* original 5113, guest PC 0x0c065890 */
if(!s->budget--) { s->failed_pc=0x0c065890u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c065892;
P_0c065892: /* original 7501, guest PC 0x0c065892 */
if(!s->budget--) { s->failed_pc=0x0c065892u; return 0; }
r[5]+=0x00000001u;
goto P_0c065894;
P_0c065894: /* original 4208, guest PC 0x0c065894 */
if(!s->budget--) { s->failed_pc=0x0c065894u; return 0; }
r[2]<<=2;
goto P_0c065896;
P_0c065896: /* original 0216, guest PC 0x0c065896 */
if(!s->budget--) { s->failed_pc=0x0c065896u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065898;
P_0c065898: /* original 6162, guest PC 0x0c065898 */
if(!s->budget--) { s->failed_pc=0x0c065898u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c06589a;
P_0c06589a: /* original 6253, guest PC 0x0c06589a */
if(!s->budget--) { s->failed_pc=0x0c06589au; return 0; }
r[2]=r[5];
goto P_0c06589c;
P_0c06589c: /* original 5114, guest PC 0x0c06589c */
if(!s->budget--) { s->failed_pc=0x0c06589cu; return 0; }
r[1]=read(ram,r[1]+16,4);
goto P_0c06589e;
P_0c06589e: /* original 7501, guest PC 0x0c06589e */
if(!s->budget--) { s->failed_pc=0x0c06589eu; return 0; }
r[5]+=0x00000001u;
goto P_0c0658a0;
P_0c0658a0: /* original 4208, guest PC 0x0c0658a0 */
if(!s->budget--) { s->failed_pc=0x0c0658a0u; return 0; }
r[2]<<=2;
goto P_0c0658a2;
P_0c0658a2: /* original 0216, guest PC 0x0c0658a2 */
if(!s->budget--) { s->failed_pc=0x0c0658a2u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0658a4;
P_0c0658a4: /* original 6172, guest PC 0x0c0658a4 */
if(!s->budget--) { s->failed_pc=0x0c0658a4u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0658a6;
P_0c0658a6: /* original 6253, guest PC 0x0c0658a6 */
if(!s->budget--) { s->failed_pc=0x0c0658a6u; return 0; }
r[2]=r[5];
goto P_0c0658a8;
P_0c0658a8: /* original 5111, guest PC 0x0c0658a8 */
if(!s->budget--) { s->failed_pc=0x0c0658a8u; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c0658aa;
P_0c0658aa: /* original 7501, guest PC 0x0c0658aa */
if(!s->budget--) { s->failed_pc=0x0c0658aau; return 0; }
r[5]+=0x00000001u;
goto P_0c0658ac;
P_0c0658ac: /* original 4208, guest PC 0x0c0658ac */
if(!s->budget--) { s->failed_pc=0x0c0658acu; return 0; }
r[2]<<=2;
goto P_0c0658ae;
P_0c0658ae: /* original 0216, guest PC 0x0c0658ae */
if(!s->budget--) { s->failed_pc=0x0c0658aeu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0658b0;
P_0c0658b0: /* original 6253, guest PC 0x0c0658b0 */
if(!s->budget--) { s->failed_pc=0x0c0658b0u; return 0; }
r[2]=r[5];
goto P_0c0658b2;
P_0c0658b2: /* original 7501, guest PC 0x0c0658b2 */
if(!s->budget--) { s->failed_pc=0x0c0658b2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0658b4;
P_0c0658b4: /* original 6172, guest PC 0x0c0658b4 */
if(!s->budget--) { s->failed_pc=0x0c0658b4u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0658b6;
P_0c0658b6: /* original 4208, guest PC 0x0c0658b6 */
if(!s->budget--) { s->failed_pc=0x0c0658b6u; return 0; }
r[2]<<=2;
goto P_0c0658b8;
P_0c0658b8: /* original 5112, guest PC 0x0c0658b8 */
if(!s->budget--) { s->failed_pc=0x0c0658b8u; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c0658ba;
P_0c0658ba: /* original 0216, guest PC 0x0c0658ba */
if(!s->budget--) { s->failed_pc=0x0c0658bau; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0658bc;
P_0c0658bc: /* original 6172, guest PC 0x0c0658bc */
if(!s->budget--) { s->failed_pc=0x0c0658bcu; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0658be;
P_0c0658be: /* original 6253, guest PC 0x0c0658be */
if(!s->budget--) { s->failed_pc=0x0c0658beu; return 0; }
r[2]=r[5];
goto P_0c0658c0;
P_0c0658c0: /* original 5113, guest PC 0x0c0658c0 */
if(!s->budget--) { s->failed_pc=0x0c0658c0u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c0658c2;
P_0c0658c2: /* original 7501, guest PC 0x0c0658c2 */
if(!s->budget--) { s->failed_pc=0x0c0658c2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0658c4;
P_0c0658c4: /* original 4208, guest PC 0x0c0658c4 */
if(!s->budget--) { s->failed_pc=0x0c0658c4u; return 0; }
r[2]<<=2;
goto P_0c0658c6;
P_0c0658c6: /* original 0216, guest PC 0x0c0658c6 */
if(!s->budget--) { s->failed_pc=0x0c0658c6u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0658c8;
P_0c0658c8: /* original 6172, guest PC 0x0c0658c8 */
if(!s->budget--) { s->failed_pc=0x0c0658c8u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0658ca;
P_0c0658ca: /* original 6253, guest PC 0x0c0658ca */
if(!s->budget--) { s->failed_pc=0x0c0658cau; return 0; }
r[2]=r[5];
goto P_0c0658cc;
P_0c0658cc: /* original 5114, guest PC 0x0c0658cc */
if(!s->budget--) { s->failed_pc=0x0c0658ccu; return 0; }
r[1]=read(ram,r[1]+16,4);
goto P_0c0658ce;
P_0c0658ce: /* original 7501, guest PC 0x0c0658ce */
if(!s->budget--) { s->failed_pc=0x0c0658ceu; return 0; }
r[5]+=0x00000001u;
goto P_0c0658d0;
P_0c0658d0: /* original 4208, guest PC 0x0c0658d0 */
if(!s->budget--) { s->failed_pc=0x0c0658d0u; return 0; }
r[2]<<=2;
goto P_0c0658d2;
P_0c0658d2: /* original 0216, guest PC 0x0c0658d2 */
if(!s->budget--) { s->failed_pc=0x0c0658d2u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0658d4;
P_0c0658d4: /* original d211, guest PC 0x0c0658d4 */
if(!s->budget--) { s->failed_pc=0x0c0658d4u; return 0; }
r[2]=read(ram,0x0c06591cu,4);
goto P_0c0658d6;
P_0c0658d6: /* original 4508, guest PC 0x0c0658d6 */
if(!s->budget--) { s->failed_pc=0x0c0658d6u; return 0; }
r[5]<<=2;
goto P_0c0658d8;
P_0c0658d8: /* original 2252, guest PC 0x0c0658d8 */
if(!s->budget--) { s->failed_pc=0x0c0658d8u; return 0; }
write(ram,r[2],r[5],4);
goto P_0c0658da;
P_0c0658da: /* original d311, guest PC 0x0c0658da */
if(!s->budget--) { s->failed_pc=0x0c0658dau; return 0; }
r[3]=read(ram,0x0c065920u,4);
goto P_0c0658dc;
P_0c0658dc: /* original 430b, guest PC 0x0c0658dc */
if(!s->budget--) { s->failed_pc=0x0c0658dcu; return 0; }
target=r[3];
r[16]=0x0c0658e0u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0658e0u) { target=s->pc; goto dispatch; }
goto P_0c0658e0;
P_0c0658de: /* original 64d3, guest PC 0x0c0658de */
if(!s->budget--) { s->failed_pc=0x0c0658deu; return 0; }
r[4]=r[13];
goto P_0c0658e0;
P_0c0658e0: /* original d210, guest PC 0x0c0658e0 */
if(!s->budget--) { s->failed_pc=0x0c0658e0u; return 0; }
r[2]=read(ram,0x0c065924u,4);
goto P_0c0658e2;
P_0c0658e2: /* original 6403, guest PC 0x0c0658e2 */
if(!s->budget--) { s->failed_pc=0x0c0658e2u; return 0; }
r[4]=r[0];
goto P_0c0658e4;
P_0c0658e4: /* original e500, guest PC 0x0c0658e4 */
if(!s->budget--) { s->failed_pc=0x0c0658e4u; return 0; }
r[5]=0x00000000u;
goto P_0c0658e6;
P_0c0658e6: /* original 420b, guest PC 0x0c0658e6 */
if(!s->budget--) { s->failed_pc=0x0c0658e6u; return 0; }
target=r[2];
r[16]=0x0c0658eau;
r[6]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0658eau) { target=s->pc; goto dispatch; }
goto P_0c0658ea;
P_0c0658e8: /* original 6653, guest PC 0x0c0658e8 */
if(!s->budget--) { s->failed_pc=0x0c0658e8u; return 0; }
r[6]=r[5];
goto P_0c0658ea;
P_0c0658ea: /* original 62e2, guest PC 0x0c0658ea */
if(!s->budget--) { s->failed_pc=0x0c0658eau; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0658ec;
P_0c0658ec: /* original d10e, guest PC 0x0c0658ec */
if(!s->budget--) { s->failed_pc=0x0c0658ecu; return 0; }
r[1]=read(ram,0x0c065928u,4);
goto P_0c0658ee;
P_0c0658ee: /* original 5323, guest PC 0x0c0658ee */
if(!s->budget--) { s->failed_pc=0x0c0658eeu; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c0658f0;
P_0c0658f0: /* original 2132, guest PC 0x0c0658f0 */
if(!s->budget--) { s->failed_pc=0x0c0658f0u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c0658f2;
P_0c0658f2: /* original e000, guest PC 0x0c0658f2 */
if(!s->budget--) { s->failed_pc=0x0c0658f2u; return 0; }
r[0]=0x00000000u;
goto P_0c0658f4;
P_0c0658f4: /* original 7f10, guest PC 0x0c0658f4 */
if(!s->budget--) { s->failed_pc=0x0c0658f4u; return 0; }
r[15]+=0x00000010u;
goto P_0c0658f6;
P_0c0658f6: /* original 4f26, guest PC 0x0c0658f6 */
if(!s->budget--) { s->failed_pc=0x0c0658f6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0658f8;
P_0c0658f8: /* original 6df6, guest PC 0x0c0658f8 */
if(!s->budget--) { s->failed_pc=0x0c0658f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0658fa;
P_0c0658fa: /* original 000b, guest PC 0x0c0658fa */
if(!s->budget--) { s->failed_pc=0x0c0658fau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0658fc: /* original 6ef6, guest PC 0x0c0658fc */
if(!s->budget--) { s->failed_pc=0x0c0658fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0658feu,s,ram);
P_0c065932: /* original 4f22, guest PC 0x0c065932 */
if(!s->budget--) { s->failed_pc=0x0c065932u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c065934;
P_0c065934: /* original 7ff0, guest PC 0x0c065934 */
if(!s->budget--) { s->failed_pc=0x0c065934u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c065936;
P_0c065936: /* original 6df3, guest PC 0x0c065936 */
if(!s->budget--) { s->failed_pc=0x0c065936u; return 0; }
r[13]=r[15];
goto P_0c065938;
P_0c065938: /* original 6342, guest PC 0x0c065938 */
if(!s->budget--) { s->failed_pc=0x0c065938u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c06593a;
P_0c06593a: /* original 7d04, guest PC 0x0c06593a */
if(!s->budget--) { s->failed_pc=0x0c06593au; return 0; }
r[13]+=0x00000004u;
goto P_0c06593c;
P_0c06593c: /* original 6ed3, guest PC 0x0c06593c */
if(!s->budget--) { s->failed_pc=0x0c06593cu; return 0; }
r[14]=r[13];
goto P_0c06593e;
P_0c06593e: /* original 67e3, guest PC 0x0c06593e */
if(!s->budget--) { s->failed_pc=0x0c06593eu; return 0; }
r[7]=r[14];
goto P_0c065940;
P_0c065940: /* original 2e32, guest PC 0x0c065940 */
if(!s->budget--) { s->failed_pc=0x0c065940u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c065942;
P_0c065942: /* original 66e3, guest PC 0x0c065942 */
if(!s->budget--) { s->failed_pc=0x0c065942u; return 0; }
r[6]=r[14];
goto P_0c065944;
P_0c065944: /* original 5241, guest PC 0x0c065944 */
if(!s->budget--) { s->failed_pc=0x0c065944u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c065946;
P_0c065946: /* original 7704, guest PC 0x0c065946 */
if(!s->budget--) { s->failed_pc=0x0c065946u; return 0; }
r[7]+=0x00000004u;
goto P_0c065948;
P_0c065948: /* original 2722, guest PC 0x0c065948 */
if(!s->budget--) { s->failed_pc=0x0c065948u; return 0; }
write(ram,r[7],r[2],4);
goto P_0c06594a;
P_0c06594a: /* original 7608, guest PC 0x0c06594a */
if(!s->budget--) { s->failed_pc=0x0c06594au; return 0; }
r[6]+=0x00000008u;
goto P_0c06594c;
P_0c06594c: /* original 5342, guest PC 0x0c06594c */
if(!s->budget--) { s->failed_pc=0x0c06594cu; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c06594e;
P_0c06594e: /* original 2632, guest PC 0x0c06594e */
if(!s->budget--) { s->failed_pc=0x0c06594eu; return 0; }
write(ram,r[6],r[3],4);
goto P_0c065950;
P_0c065950: /* original d2b0, guest PC 0x0c065950 */
if(!s->budget--) { s->failed_pc=0x0c065950u; return 0; }
r[2]=read(ram,0x0c065c14u,4);
goto P_0c065952;
P_0c065952: /* original 6d22, guest PC 0x0c065952 */
if(!s->budget--) { s->failed_pc=0x0c065952u; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c065954;
P_0c065954: /* original d1b0, guest PC 0x0c065954 */
if(!s->budget--) { s->failed_pc=0x0c065954u; return 0; }
r[1]=read(ram,0x0c065c18u,4);
goto P_0c065956;
P_0c065956: /* original 6312, guest PC 0x0c065956 */
if(!s->budget--) { s->failed_pc=0x0c065956u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c065958;
P_0c065958: /* original 2f32, guest PC 0x0c065958 */
if(!s->budget--) { s->failed_pc=0x0c065958u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06595a;
P_0c06595a: /* original d3b0, guest PC 0x0c06595a */
if(!s->budget--) { s->failed_pc=0x0c06595au; return 0; }
r[3]=read(ram,0x0c065c1cu,4);
goto P_0c06595c;
P_0c06595c: /* original 6432, guest PC 0x0c06595c */
if(!s->budget--) { s->failed_pc=0x0c06595cu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c06595e;
P_0c06595e: /* original d0b0, guest PC 0x0c06595e */
if(!s->budget--) { s->failed_pc=0x0c06595eu; return 0; }
r[0]=read(ram,0x0c065c20u,4);
goto P_0c065960;
P_0c065960: /* original 6253, guest PC 0x0c065960 */
if(!s->budget--) { s->failed_pc=0x0c065960u; return 0; }
r[2]=r[5];
goto P_0c065962;
P_0c065962: /* original 7501, guest PC 0x0c065962 */
if(!s->budget--) { s->failed_pc=0x0c065962u; return 0; }
r[5]+=0x00000001u;
goto P_0c065964;
P_0c065964: /* original 4208, guest PC 0x0c065964 */
if(!s->budget--) { s->failed_pc=0x0c065964u; return 0; }
r[2]<<=2;
goto P_0c065966;
P_0c065966: /* original 02d6, guest PC 0x0c065966 */
if(!s->budget--) { s->failed_pc=0x0c065966u; return 0; }
write(ram,r[2]+r[0],r[13],4);
goto P_0c065968;
P_0c065968: /* original 6153, guest PC 0x0c065968 */
if(!s->budget--) { s->failed_pc=0x0c065968u; return 0; }
r[1]=r[5];
goto P_0c06596a;
P_0c06596a: /* original 7501, guest PC 0x0c06596a */
if(!s->budget--) { s->failed_pc=0x0c06596au; return 0; }
r[5]+=0x00000001u;
goto P_0c06596c;
P_0c06596c: /* original 62f2, guest PC 0x0c06596c */
if(!s->budget--) { s->failed_pc=0x0c06596cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c06596e;
P_0c06596e: /* original 4108, guest PC 0x0c06596e */
if(!s->budget--) { s->failed_pc=0x0c06596eu; return 0; }
r[1]<<=2;
goto P_0c065970;
P_0c065970: /* original 0126, guest PC 0x0c065970 */
if(!s->budget--) { s->failed_pc=0x0c065970u; return 0; }
write(ram,r[1]+r[0],r[2],4);
goto P_0c065972;
P_0c065972: /* original 6153, guest PC 0x0c065972 */
if(!s->budget--) { s->failed_pc=0x0c065972u; return 0; }
r[1]=r[5];
goto P_0c065974;
P_0c065974: /* original 7501, guest PC 0x0c065974 */
if(!s->budget--) { s->failed_pc=0x0c065974u; return 0; }
r[5]+=0x00000001u;
goto P_0c065976;
P_0c065976: /* original 4108, guest PC 0x0c065976 */
if(!s->budget--) { s->failed_pc=0x0c065976u; return 0; }
r[1]<<=2;
goto P_0c065978;
P_0c065978: /* original 0146, guest PC 0x0c065978 */
if(!s->budget--) { s->failed_pc=0x0c065978u; return 0; }
write(ram,r[1]+r[0],r[4],4);
goto P_0c06597a;
P_0c06597a: /* original 6253, guest PC 0x0c06597a */
if(!s->budget--) { s->failed_pc=0x0c06597au; return 0; }
r[2]=r[5];
goto P_0c06597c;
P_0c06597c: /* original 61e2, guest PC 0x0c06597c */
if(!s->budget--) { s->failed_pc=0x0c06597cu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c06597e;
P_0c06597e: /* original 7501, guest PC 0x0c06597e */
if(!s->budget--) { s->failed_pc=0x0c06597eu; return 0; }
r[5]+=0x00000001u;
goto P_0c065980;
P_0c065980: /* original 5111, guest PC 0x0c065980 */
if(!s->budget--) { s->failed_pc=0x0c065980u; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c065982;
P_0c065982: /* original 4208, guest PC 0x0c065982 */
if(!s->budget--) { s->failed_pc=0x0c065982u; return 0; }
r[2]<<=2;
goto P_0c065984;
P_0c065984: /* original 0216, guest PC 0x0c065984 */
if(!s->budget--) { s->failed_pc=0x0c065984u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065986;
P_0c065986: /* original 6253, guest PC 0x0c065986 */
if(!s->budget--) { s->failed_pc=0x0c065986u; return 0; }
r[2]=r[5];
goto P_0c065988;
P_0c065988: /* original 61e2, guest PC 0x0c065988 */
if(!s->budget--) { s->failed_pc=0x0c065988u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c06598a;
P_0c06598a: /* original 7501, guest PC 0x0c06598a */
if(!s->budget--) { s->failed_pc=0x0c06598au; return 0; }
r[5]+=0x00000001u;
goto P_0c06598c;
P_0c06598c: /* original 5112, guest PC 0x0c06598c */
if(!s->budget--) { s->failed_pc=0x0c06598cu; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c06598e;
P_0c06598e: /* original 4208, guest PC 0x0c06598e */
if(!s->budget--) { s->failed_pc=0x0c06598eu; return 0; }
r[2]<<=2;
goto P_0c065990;
P_0c065990: /* original 0216, guest PC 0x0c065990 */
if(!s->budget--) { s->failed_pc=0x0c065990u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065992;
P_0c065992: /* original 6253, guest PC 0x0c065992 */
if(!s->budget--) { s->failed_pc=0x0c065992u; return 0; }
r[2]=r[5];
goto P_0c065994;
P_0c065994: /* original 61e2, guest PC 0x0c065994 */
if(!s->budget--) { s->failed_pc=0x0c065994u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c065996;
P_0c065996: /* original 7501, guest PC 0x0c065996 */
if(!s->budget--) { s->failed_pc=0x0c065996u; return 0; }
r[5]+=0x00000001u;
goto P_0c065998;
P_0c065998: /* original 5113, guest PC 0x0c065998 */
if(!s->budget--) { s->failed_pc=0x0c065998u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c06599a;
P_0c06599a: /* original 4208, guest PC 0x0c06599a */
if(!s->budget--) { s->failed_pc=0x0c06599au; return 0; }
r[2]<<=2;
goto P_0c06599c;
P_0c06599c: /* original 0216, guest PC 0x0c06599c */
if(!s->budget--) { s->failed_pc=0x0c06599cu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06599e;
P_0c06599e: /* original 6253, guest PC 0x0c06599e */
if(!s->budget--) { s->failed_pc=0x0c06599eu; return 0; }
r[2]=r[5];
goto P_0c0659a0;
P_0c0659a0: /* original c7a0, guest PC 0x0c0659a0 */
if(!s->budget--) { s->failed_pc=0x0c0659a0u; return 0; }
r[0]=0x0c065c24u;
goto P_0c0659a2;
P_0c0659a2: /* original 7501, guest PC 0x0c0659a2 */
if(!s->budget--) { s->failed_pc=0x0c0659a2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0659a4;
P_0c0659a4: /* original f408, guest PC 0x0c0659a4 */
if(!s->budget--) { s->failed_pc=0x0c0659a4u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0659a6;
P_0c0659a6: /* original 4208, guest PC 0x0c0659a6 */
if(!s->budget--) { s->failed_pc=0x0c0659a6u; return 0; }
r[2]<<=2;
goto P_0c0659a8;
P_0c0659a8: /* original d09d, guest PC 0x0c0659a8 */
if(!s->budget--) { s->failed_pc=0x0c0659a8u; return 0; }
r[0]=read(ram,0x0c065c20u,4);
goto P_0c0659aa;
P_0c0659aa: /* original e110, guest PC 0x0c0659aa */
if(!s->budget--) { s->failed_pc=0x0c0659aau; return 0; }
r[1]=0x00000010u;
goto P_0c0659ac;
P_0c0659ac: /* original 64e2, guest PC 0x0c0659ac */
if(!s->budget--) { s->failed_pc=0x0c0659acu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0659ae;
P_0c0659ae: /* original 314c, guest PC 0x0c0659ae */
if(!s->budget--) { s->failed_pc=0x0c0659aeu; return 0; }
r[1]+=r[4];
goto P_0c0659b0;
P_0c0659b0: /* original f318, guest PC 0x0c0659b0 */
if(!s->budget--) { s->failed_pc=0x0c0659b0u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0659b2;
P_0c0659b2: /* original f342, guest PC 0x0c0659b2 */
if(!s->budget--) { s->failed_pc=0x0c0659b2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0659b4;
P_0c0659b4: /* original f33d, guest PC 0x0c0659b4 */
if(!s->budget--) { s->failed_pc=0x0c0659b4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0659b6;
P_0c0659b6: /* original 045a, guest PC 0x0c0659b6 */
if(!s->budget--) { s->failed_pc=0x0c0659b6u; return 0; }
r[4]=r[53];
goto P_0c0659b8;
P_0c0659b8: /* original 6143, guest PC 0x0c0659b8 */
if(!s->budget--) { s->failed_pc=0x0c0659b8u; return 0; }
r[1]=r[4];
goto P_0c0659ba;
P_0c0659ba: /* original 4128, guest PC 0x0c0659ba */
if(!s->budget--) { s->failed_pc=0x0c0659bau; return 0; }
r[1]<<=16;
goto P_0c0659bc;
P_0c0659bc: /* original 4118, guest PC 0x0c0659bc */
if(!s->budget--) { s->failed_pc=0x0c0659bcu; return 0; }
r[1]<<=8;
goto P_0c0659be;
P_0c0659be: /* original 6343, guest PC 0x0c0659be */
if(!s->budget--) { s->failed_pc=0x0c0659beu; return 0; }
r[3]=r[4];
goto P_0c0659c0;
P_0c0659c0: /* original 4328, guest PC 0x0c0659c0 */
if(!s->budget--) { s->failed_pc=0x0c0659c0u; return 0; }
r[3]<<=16;
goto P_0c0659c2;
P_0c0659c2: /* original 213b, guest PC 0x0c0659c2 */
if(!s->budget--) { s->failed_pc=0x0c0659c2u; return 0; }
r[1]|=r[3];
goto P_0c0659c4;
P_0c0659c4: /* original 6343, guest PC 0x0c0659c4 */
if(!s->budget--) { s->failed_pc=0x0c0659c4u; return 0; }
r[3]=r[4];
goto P_0c0659c6;
P_0c0659c6: /* original 4318, guest PC 0x0c0659c6 */
if(!s->budget--) { s->failed_pc=0x0c0659c6u; return 0; }
r[3]<<=8;
goto P_0c0659c8;
P_0c0659c8: /* original 213b, guest PC 0x0c0659c8 */
if(!s->budget--) { s->failed_pc=0x0c0659c8u; return 0; }
r[1]|=r[3];
goto P_0c0659ca;
P_0c0659ca: /* original 214b, guest PC 0x0c0659ca */
if(!s->budget--) { s->failed_pc=0x0c0659cau; return 0; }
r[1]|=r[4];
goto P_0c0659cc;
P_0c0659cc: /* original 0216, guest PC 0x0c0659cc */
if(!s->budget--) { s->failed_pc=0x0c0659ccu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0659ce;
P_0c0659ce: /* original 6253, guest PC 0x0c0659ce */
if(!s->budget--) { s->failed_pc=0x0c0659ceu; return 0; }
r[2]=r[5];
goto P_0c0659d0;
P_0c0659d0: /* original 6172, guest PC 0x0c0659d0 */
if(!s->budget--) { s->failed_pc=0x0c0659d0u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0659d2;
P_0c0659d2: /* original 7501, guest PC 0x0c0659d2 */
if(!s->budget--) { s->failed_pc=0x0c0659d2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0659d4;
P_0c0659d4: /* original 5311, guest PC 0x0c0659d4 */
if(!s->budget--) { s->failed_pc=0x0c0659d4u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c0659d6;
P_0c0659d6: /* original 4208, guest PC 0x0c0659d6 */
if(!s->budget--) { s->failed_pc=0x0c0659d6u; return 0; }
r[2]<<=2;
goto P_0c0659d8;
P_0c0659d8: /* original 0236, guest PC 0x0c0659d8 */
if(!s->budget--) { s->failed_pc=0x0c0659d8u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0659da;
P_0c0659da: /* original 6253, guest PC 0x0c0659da */
if(!s->budget--) { s->failed_pc=0x0c0659dau; return 0; }
r[2]=r[5];
goto P_0c0659dc;
P_0c0659dc: /* original 6172, guest PC 0x0c0659dc */
if(!s->budget--) { s->failed_pc=0x0c0659dcu; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0659de;
P_0c0659de: /* original 7501, guest PC 0x0c0659de */
if(!s->budget--) { s->failed_pc=0x0c0659deu; return 0; }
r[5]+=0x00000001u;
goto P_0c0659e0;
P_0c0659e0: /* original 5312, guest PC 0x0c0659e0 */
if(!s->budget--) { s->failed_pc=0x0c0659e0u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c0659e2;
P_0c0659e2: /* original 4208, guest PC 0x0c0659e2 */
if(!s->budget--) { s->failed_pc=0x0c0659e2u; return 0; }
r[2]<<=2;
goto P_0c0659e4;
P_0c0659e4: /* original 0236, guest PC 0x0c0659e4 */
if(!s->budget--) { s->failed_pc=0x0c0659e4u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0659e6;
P_0c0659e6: /* original 6253, guest PC 0x0c0659e6 */
if(!s->budget--) { s->failed_pc=0x0c0659e6u; return 0; }
r[2]=r[5];
goto P_0c0659e8;
P_0c0659e8: /* original 7501, guest PC 0x0c0659e8 */
if(!s->budget--) { s->failed_pc=0x0c0659e8u; return 0; }
r[5]+=0x00000001u;
goto P_0c0659ea;
P_0c0659ea: /* original 4208, guest PC 0x0c0659ea */
if(!s->budget--) { s->failed_pc=0x0c0659eau; return 0; }
r[2]<<=2;
goto P_0c0659ec;
P_0c0659ec: /* original 6172, guest PC 0x0c0659ec */
if(!s->budget--) { s->failed_pc=0x0c0659ecu; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0659ee;
P_0c0659ee: /* original 5313, guest PC 0x0c0659ee */
if(!s->budget--) { s->failed_pc=0x0c0659eeu; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c0659f0;
P_0c0659f0: /* original 0236, guest PC 0x0c0659f0 */
if(!s->budget--) { s->failed_pc=0x0c0659f0u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0659f2;
P_0c0659f2: /* original 6253, guest PC 0x0c0659f2 */
if(!s->budget--) { s->failed_pc=0x0c0659f2u; return 0; }
r[2]=r[5];
goto P_0c0659f4;
P_0c0659f4: /* original 6472, guest PC 0x0c0659f4 */
if(!s->budget--) { s->failed_pc=0x0c0659f4u; return 0; }
tmp=read(ram,r[7],4);
r[4]=tmp;
goto P_0c0659f6;
P_0c0659f6: /* original e110, guest PC 0x0c0659f6 */
if(!s->budget--) { s->failed_pc=0x0c0659f6u; return 0; }
r[1]=0x00000010u;
goto P_0c0659f8;
P_0c0659f8: /* original 7501, guest PC 0x0c0659f8 */
if(!s->budget--) { s->failed_pc=0x0c0659f8u; return 0; }
r[5]+=0x00000001u;
goto P_0c0659fa;
P_0c0659fa: /* original 4208, guest PC 0x0c0659fa */
if(!s->budget--) { s->failed_pc=0x0c0659fau; return 0; }
r[2]<<=2;
goto P_0c0659fc;
P_0c0659fc: /* original 314c, guest PC 0x0c0659fc */
if(!s->budget--) { s->failed_pc=0x0c0659fcu; return 0; }
r[1]+=r[4];
goto P_0c0659fe;
P_0c0659fe: /* original f318, guest PC 0x0c0659fe */
if(!s->budget--) { s->failed_pc=0x0c0659feu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c065a00;
P_0c065a00: /* original f342, guest PC 0x0c065a00 */
if(!s->budget--) { s->failed_pc=0x0c065a00u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c065a02;
P_0c065a02: /* original f33d, guest PC 0x0c065a02 */
if(!s->budget--) { s->failed_pc=0x0c065a02u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065a04;
P_0c065a04: /* original 045a, guest PC 0x0c065a04 */
if(!s->budget--) { s->failed_pc=0x0c065a04u; return 0; }
r[4]=r[53];
goto P_0c065a06;
P_0c065a06: /* original 6343, guest PC 0x0c065a06 */
if(!s->budget--) { s->failed_pc=0x0c065a06u; return 0; }
r[3]=r[4];
goto P_0c065a08;
P_0c065a08: /* original 4328, guest PC 0x0c065a08 */
if(!s->budget--) { s->failed_pc=0x0c065a08u; return 0; }
r[3]<<=16;
goto P_0c065a0a;
P_0c065a0a: /* original 4318, guest PC 0x0c065a0a */
if(!s->budget--) { s->failed_pc=0x0c065a0au; return 0; }
r[3]<<=8;
goto P_0c065a0c;
P_0c065a0c: /* original 6143, guest PC 0x0c065a0c */
if(!s->budget--) { s->failed_pc=0x0c065a0cu; return 0; }
r[1]=r[4];
goto P_0c065a0e;
P_0c065a0e: /* original 4128, guest PC 0x0c065a0e */
if(!s->budget--) { s->failed_pc=0x0c065a0eu; return 0; }
r[1]<<=16;
goto P_0c065a10;
P_0c065a10: /* original 231b, guest PC 0x0c065a10 */
if(!s->budget--) { s->failed_pc=0x0c065a10u; return 0; }
r[3]|=r[1];
goto P_0c065a12;
P_0c065a12: /* original 6143, guest PC 0x0c065a12 */
if(!s->budget--) { s->failed_pc=0x0c065a12u; return 0; }
r[1]=r[4];
goto P_0c065a14;
P_0c065a14: /* original 4118, guest PC 0x0c065a14 */
if(!s->budget--) { s->failed_pc=0x0c065a14u; return 0; }
r[1]<<=8;
goto P_0c065a16;
P_0c065a16: /* original 231b, guest PC 0x0c065a16 */
if(!s->budget--) { s->failed_pc=0x0c065a16u; return 0; }
r[3]|=r[1];
goto P_0c065a18;
P_0c065a18: /* original 234b, guest PC 0x0c065a18 */
if(!s->budget--) { s->failed_pc=0x0c065a18u; return 0; }
r[3]|=r[4];
goto P_0c065a1a;
P_0c065a1a: /* original 0236, guest PC 0x0c065a1a */
if(!s->budget--) { s->failed_pc=0x0c065a1au; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065a1c;
P_0c065a1c: /* original 6162, guest PC 0x0c065a1c */
if(!s->budget--) { s->failed_pc=0x0c065a1cu; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c065a1e;
P_0c065a1e: /* original 6253, guest PC 0x0c065a1e */
if(!s->budget--) { s->failed_pc=0x0c065a1eu; return 0; }
r[2]=r[5];
goto P_0c065a20;
P_0c065a20: /* original 5311, guest PC 0x0c065a20 */
if(!s->budget--) { s->failed_pc=0x0c065a20u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c065a22;
P_0c065a22: /* original 7501, guest PC 0x0c065a22 */
if(!s->budget--) { s->failed_pc=0x0c065a22u; return 0; }
r[5]+=0x00000001u;
goto P_0c065a24;
P_0c065a24: /* original 4208, guest PC 0x0c065a24 */
if(!s->budget--) { s->failed_pc=0x0c065a24u; return 0; }
r[2]<<=2;
goto P_0c065a26;
P_0c065a26: /* original 0236, guest PC 0x0c065a26 */
if(!s->budget--) { s->failed_pc=0x0c065a26u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065a28;
P_0c065a28: /* original 6253, guest PC 0x0c065a28 */
if(!s->budget--) { s->failed_pc=0x0c065a28u; return 0; }
r[2]=r[5];
goto P_0c065a2a;
P_0c065a2a: /* original 7501, guest PC 0x0c065a2a */
if(!s->budget--) { s->failed_pc=0x0c065a2au; return 0; }
r[5]+=0x00000001u;
goto P_0c065a2c;
P_0c065a2c: /* original 6162, guest PC 0x0c065a2c */
if(!s->budget--) { s->failed_pc=0x0c065a2cu; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c065a2e;
P_0c065a2e: /* original 4208, guest PC 0x0c065a2e */
if(!s->budget--) { s->failed_pc=0x0c065a2eu; return 0; }
r[2]<<=2;
goto P_0c065a30;
P_0c065a30: /* original 5312, guest PC 0x0c065a30 */
if(!s->budget--) { s->failed_pc=0x0c065a30u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c065a32;
P_0c065a32: /* original 0236, guest PC 0x0c065a32 */
if(!s->budget--) { s->failed_pc=0x0c065a32u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065a34;
P_0c065a34: /* original 6162, guest PC 0x0c065a34 */
if(!s->budget--) { s->failed_pc=0x0c065a34u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c065a36;
P_0c065a36: /* original 6253, guest PC 0x0c065a36 */
if(!s->budget--) { s->failed_pc=0x0c065a36u; return 0; }
r[2]=r[5];
goto P_0c065a38;
P_0c065a38: /* original 5313, guest PC 0x0c065a38 */
if(!s->budget--) { s->failed_pc=0x0c065a38u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c065a3a;
P_0c065a3a: /* original 7501, guest PC 0x0c065a3a */
if(!s->budget--) { s->failed_pc=0x0c065a3au; return 0; }
r[5]+=0x00000001u;
goto P_0c065a3c;
P_0c065a3c: /* original 4208, guest PC 0x0c065a3c */
if(!s->budget--) { s->failed_pc=0x0c065a3cu; return 0; }
r[2]<<=2;
goto P_0c065a3e;
P_0c065a3e: /* original 0236, guest PC 0x0c065a3e */
if(!s->budget--) { s->failed_pc=0x0c065a3eu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065a40;
P_0c065a40: /* original 6462, guest PC 0x0c065a40 */
if(!s->budget--) { s->failed_pc=0x0c065a40u; return 0; }
tmp=read(ram,r[6],4);
r[4]=tmp;
goto P_0c065a42;
P_0c065a42: /* original e110, guest PC 0x0c065a42 */
if(!s->budget--) { s->failed_pc=0x0c065a42u; return 0; }
r[1]=0x00000010u;
goto P_0c065a44;
P_0c065a44: /* original 6253, guest PC 0x0c065a44 */
if(!s->budget--) { s->failed_pc=0x0c065a44u; return 0; }
r[2]=r[5];
goto P_0c065a46;
P_0c065a46: /* original 7501, guest PC 0x0c065a46 */
if(!s->budget--) { s->failed_pc=0x0c065a46u; return 0; }
r[5]+=0x00000001u;
goto P_0c065a48;
P_0c065a48: /* original 4208, guest PC 0x0c065a48 */
if(!s->budget--) { s->failed_pc=0x0c065a48u; return 0; }
r[2]<<=2;
goto P_0c065a4a;
P_0c065a4a: /* original 314c, guest PC 0x0c065a4a */
if(!s->budget--) { s->failed_pc=0x0c065a4au; return 0; }
r[1]+=r[4];
goto P_0c065a4c;
P_0c065a4c: /* original f318, guest PC 0x0c065a4c */
if(!s->budget--) { s->failed_pc=0x0c065a4cu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c065a4e;
P_0c065a4e: /* original f342, guest PC 0x0c065a4e */
if(!s->budget--) { s->failed_pc=0x0c065a4eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c065a50;
P_0c065a50: /* original f33d, guest PC 0x0c065a50 */
if(!s->budget--) { s->failed_pc=0x0c065a50u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065a52;
P_0c065a52: /* original 045a, guest PC 0x0c065a52 */
if(!s->budget--) { s->failed_pc=0x0c065a52u; return 0; }
r[4]=r[53];
goto P_0c065a54;
P_0c065a54: /* original 6343, guest PC 0x0c065a54 */
if(!s->budget--) { s->failed_pc=0x0c065a54u; return 0; }
r[3]=r[4];
goto P_0c065a56;
P_0c065a56: /* original 4328, guest PC 0x0c065a56 */
if(!s->budget--) { s->failed_pc=0x0c065a56u; return 0; }
r[3]<<=16;
goto P_0c065a58;
P_0c065a58: /* original 4318, guest PC 0x0c065a58 */
if(!s->budget--) { s->failed_pc=0x0c065a58u; return 0; }
r[3]<<=8;
goto P_0c065a5a;
P_0c065a5a: /* original 6143, guest PC 0x0c065a5a */
if(!s->budget--) { s->failed_pc=0x0c065a5au; return 0; }
r[1]=r[4];
goto P_0c065a5c;
P_0c065a5c: /* original 4128, guest PC 0x0c065a5c */
if(!s->budget--) { s->failed_pc=0x0c065a5cu; return 0; }
r[1]<<=16;
goto P_0c065a5e;
P_0c065a5e: /* original 231b, guest PC 0x0c065a5e */
if(!s->budget--) { s->failed_pc=0x0c065a5eu; return 0; }
r[3]|=r[1];
goto P_0c065a60;
P_0c065a60: /* original 6143, guest PC 0x0c065a60 */
if(!s->budget--) { s->failed_pc=0x0c065a60u; return 0; }
r[1]=r[4];
goto P_0c065a62;
P_0c065a62: /* original 4118, guest PC 0x0c065a62 */
if(!s->budget--) { s->failed_pc=0x0c065a62u; return 0; }
r[1]<<=8;
goto P_0c065a64;
P_0c065a64: /* original 231b, guest PC 0x0c065a64 */
if(!s->budget--) { s->failed_pc=0x0c065a64u; return 0; }
r[3]|=r[1];
goto P_0c065a66;
P_0c065a66: /* original 234b, guest PC 0x0c065a66 */
if(!s->budget--) { s->failed_pc=0x0c065a66u; return 0; }
r[3]|=r[4];
goto P_0c065a68;
P_0c065a68: /* original 0236, guest PC 0x0c065a68 */
if(!s->budget--) { s->failed_pc=0x0c065a68u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065a6a;
P_0c065a6a: /* original 4508, guest PC 0x0c065a6a */
if(!s->budget--) { s->failed_pc=0x0c065a6au; return 0; }
r[5]<<=2;
goto P_0c065a6c;
P_0c065a6c: /* original d36e, guest PC 0x0c065a6c */
if(!s->budget--) { s->failed_pc=0x0c065a6cu; return 0; }
r[3]=read(ram,0x0c065c28u,4);
goto P_0c065a6e;
P_0c065a6e: /* original 2352, guest PC 0x0c065a6e */
if(!s->budget--) { s->failed_pc=0x0c065a6eu; return 0; }
write(ram,r[3],r[5],4);
goto P_0c065a70;
P_0c065a70: /* original d26e, guest PC 0x0c065a70 */
if(!s->budget--) { s->failed_pc=0x0c065a70u; return 0; }
r[2]=read(ram,0x0c065c2cu,4);
goto P_0c065a72;
P_0c065a72: /* original 420b, guest PC 0x0c065a72 */
if(!s->budget--) { s->failed_pc=0x0c065a72u; return 0; }
target=r[2];
r[16]=0x0c065a76u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065a76u) { target=s->pc; goto dispatch; }
goto P_0c065a76;
P_0c065a74: /* original 64d3, guest PC 0x0c065a74 */
if(!s->budget--) { s->failed_pc=0x0c065a74u; return 0; }
r[4]=r[13];
goto P_0c065a76;
P_0c065a76: /* original 6403, guest PC 0x0c065a76 */
if(!s->budget--) { s->failed_pc=0x0c065a76u; return 0; }
r[4]=r[0];
goto P_0c065a78;
P_0c065a78: /* original d36d, guest PC 0x0c065a78 */
if(!s->budget--) { s->failed_pc=0x0c065a78u; return 0; }
r[3]=read(ram,0x0c065c30u,4);
goto P_0c065a7a;
P_0c065a7a: /* original e500, guest PC 0x0c065a7a */
if(!s->budget--) { s->failed_pc=0x0c065a7au; return 0; }
r[5]=0x00000000u;
goto P_0c065a7c;
P_0c065a7c: /* original 430b, guest PC 0x0c065a7c */
if(!s->budget--) { s->failed_pc=0x0c065a7cu; return 0; }
target=r[3];
r[16]=0x0c065a80u;
r[6]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c065a80u) { target=s->pc; goto dispatch; }
goto P_0c065a80;
P_0c065a7e: /* original 6653, guest PC 0x0c065a7e */
if(!s->budget--) { s->failed_pc=0x0c065a7eu; return 0; }
r[6]=r[5];
goto P_0c065a80;
P_0c065a80: /* original 63e2, guest PC 0x0c065a80 */
if(!s->budget--) { s->failed_pc=0x0c065a80u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c065a82;
P_0c065a82: /* original 5233, guest PC 0x0c065a82 */
if(!s->budget--) { s->failed_pc=0x0c065a82u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c065a84;
P_0c065a84: /* original d16b, guest PC 0x0c065a84 */
if(!s->budget--) { s->failed_pc=0x0c065a84u; return 0; }
r[1]=read(ram,0x0c065c34u,4);
goto P_0c065a86;
P_0c065a86: /* original 2122, guest PC 0x0c065a86 */
if(!s->budget--) { s->failed_pc=0x0c065a86u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c065a88;
P_0c065a88: /* original e000, guest PC 0x0c065a88 */
if(!s->budget--) { s->failed_pc=0x0c065a88u; return 0; }
r[0]=0x00000000u;
goto P_0c065a8a;
P_0c065a8a: /* original 7f10, guest PC 0x0c065a8a */
if(!s->budget--) { s->failed_pc=0x0c065a8au; return 0; }
r[15]+=0x00000010u;
goto P_0c065a8c;
P_0c065a8c: /* original 4f26, guest PC 0x0c065a8c */
if(!s->budget--) { s->failed_pc=0x0c065a8cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c065a8e;
P_0c065a8e: /* original 6df6, guest PC 0x0c065a8e */
if(!s->budget--) { s->failed_pc=0x0c065a8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c065a90;
P_0c065a90: /* original 000b, guest PC 0x0c065a90 */
if(!s->budget--) { s->failed_pc=0x0c065a90u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c065a92: /* original 6ef6, guest PC 0x0c065a92 */
if(!s->budget--) { s->failed_pc=0x0c065a92u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c065a94u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
