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
int vf3_fifth_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07695au: goto P_0c07695a;
case 0x0c07695cu: goto P_0c07695c;
case 0x0c07695eu: goto P_0c07695e;
case 0x0c076960u: goto P_0c076960;
case 0x0c076962u: goto P_0c076962;
case 0x0c076964u: goto P_0c076964;
case 0x0c076966u: goto P_0c076966;
case 0x0c076968u: goto P_0c076968;
case 0x0c07696au: goto P_0c07696a;
case 0x0c07696cu: goto P_0c07696c;
case 0x0c07696eu: goto P_0c07696e;
case 0x0c076970u: goto P_0c076970;
case 0x0c076972u: goto P_0c076972;
case 0x0c076974u: goto P_0c076974;
case 0x0c076976u: goto P_0c076976;
case 0x0c076978u: goto P_0c076978;
case 0x0c07697au: goto P_0c07697a;
case 0x0c07697cu: goto P_0c07697c;
case 0x0c07697eu: goto P_0c07697e;
case 0x0c076980u: goto P_0c076980;
case 0x0c076982u: goto P_0c076982;
case 0x0c076984u: goto P_0c076984;
case 0x0c076986u: goto P_0c076986;
case 0x0c076988u: goto P_0c076988;
case 0x0c07698au: goto P_0c07698a;
case 0x0c07698cu: goto P_0c07698c;
case 0x0c07698eu: goto P_0c07698e;
case 0x0c076990u: goto P_0c076990;
case 0x0c076992u: goto P_0c076992;
case 0x0c076994u: goto P_0c076994;
case 0x0c076996u: goto P_0c076996;
case 0x0c076998u: goto P_0c076998;
case 0x0c07699au: goto P_0c07699a;
case 0x0c07699cu: goto P_0c07699c;
case 0x0c07699eu: goto P_0c07699e;
case 0x0c0769a0u: goto P_0c0769a0;
case 0x0c0769a2u: goto P_0c0769a2;
case 0x0c0769a4u: goto P_0c0769a4;
case 0x0c0769a6u: goto P_0c0769a6;
case 0x0c0769a8u: goto P_0c0769a8;
case 0x0c0769aau: goto P_0c0769aa;
case 0x0c0769acu: goto P_0c0769ac;
case 0x0c0769aeu: goto P_0c0769ae;
case 0x0c0769b0u: goto P_0c0769b0;
case 0x0c0769b2u: goto P_0c0769b2;
case 0x0c0769b4u: goto P_0c0769b4;
case 0x0c0769b6u: goto P_0c0769b6;
case 0x0c0769b8u: goto P_0c0769b8;
case 0x0c0769bau: goto P_0c0769ba;
case 0x0c0769bcu: goto P_0c0769bc;
case 0x0c0769beu: goto P_0c0769be;
case 0x0c0769c0u: goto P_0c0769c0;
case 0x0c0769c2u: goto P_0c0769c2;
case 0x0c0769c4u: goto P_0c0769c4;
case 0x0c0781c2u: goto P_0c0781c2;
case 0x0c0781c4u: goto P_0c0781c4;
case 0x0c0781c6u: goto P_0c0781c6;
case 0x0c0781c8u: goto P_0c0781c8;
case 0x0c0781cau: goto P_0c0781ca;
case 0x0c0781ccu: goto P_0c0781cc;
case 0x0c0781ceu: goto P_0c0781ce;
case 0x0c0781d0u: goto P_0c0781d0;
case 0x0c0781d2u: goto P_0c0781d2;
case 0x0c0781d4u: goto P_0c0781d4;
case 0x0c0781d6u: goto P_0c0781d6;
case 0x0c0781d8u: goto P_0c0781d8;
case 0x0c0781dau: goto P_0c0781da;
case 0x0c0781dcu: goto P_0c0781dc;
case 0x0c0781deu: goto P_0c0781de;
case 0x0c0781e0u: goto P_0c0781e0;
case 0x0c0781e2u: goto P_0c0781e2;
case 0x0c0781e4u: goto P_0c0781e4;
case 0x0c0781e6u: goto P_0c0781e6;
case 0x0c0781e8u: goto P_0c0781e8;
case 0x0c0781eau: goto P_0c0781ea;
case 0x0c0781ecu: goto P_0c0781ec;
case 0x0c0781eeu: goto P_0c0781ee;
case 0x0c0781f0u: goto P_0c0781f0;
case 0x0c0781f2u: goto P_0c0781f2;
case 0x0c0781f4u: goto P_0c0781f4;
case 0x0c0781f6u: goto P_0c0781f6;
case 0x0c0781f8u: goto P_0c0781f8;
case 0x0c0781fau: goto P_0c0781fa;
case 0x0c0781fcu: goto P_0c0781fc;
case 0x0c0781feu: goto P_0c0781fe;
case 0x0c078200u: goto P_0c078200;
case 0x0c078202u: goto P_0c078202;
case 0x0c078204u: goto P_0c078204;
case 0x0c078206u: goto P_0c078206;
case 0x0c078208u: goto P_0c078208;
case 0x0c07820au: goto P_0c07820a;
case 0x0c07820cu: goto P_0c07820c;
case 0x0c07820eu: goto P_0c07820e;
case 0x0c078210u: goto P_0c078210;
case 0x0c078212u: goto P_0c078212;
case 0x0c078214u: goto P_0c078214;
case 0x0c078216u: goto P_0c078216;
case 0x0c078218u: goto P_0c078218;
case 0x0c07821au: goto P_0c07821a;
case 0x0c07821cu: goto P_0c07821c;
case 0x0c07821eu: goto P_0c07821e;
case 0x0c078220u: goto P_0c078220;
case 0x0c078222u: goto P_0c078222;
case 0x0c078224u: goto P_0c078224;
case 0x0c078226u: goto P_0c078226;
case 0x0c078228u: goto P_0c078228;
case 0x0c07822au: goto P_0c07822a;
case 0x0c07822cu: goto P_0c07822c;
case 0x0c07822eu: goto P_0c07822e;
case 0x0c078230u: goto P_0c078230;
case 0x0c078232u: goto P_0c078232;
case 0x0c078234u: goto P_0c078234;
case 0x0c078236u: goto P_0c078236;
case 0x0c078238u: goto P_0c078238;
case 0x0c07823au: goto P_0c07823a;
case 0x0c07823cu: goto P_0c07823c;
case 0x0c07823eu: goto P_0c07823e;
case 0x0c078240u: goto P_0c078240;
case 0x0c078242u: goto P_0c078242;
case 0x0c078244u: goto P_0c078244;
case 0x0c078246u: goto P_0c078246;
case 0x0c078248u: goto P_0c078248;
case 0x0c07824au: goto P_0c07824a;
case 0x0c07824cu: goto P_0c07824c;
case 0x0c07824eu: goto P_0c07824e;
case 0x0c078250u: goto P_0c078250;
case 0x0c078252u: goto P_0c078252;
case 0x0c078254u: goto P_0c078254;
case 0x0c078256u: goto P_0c078256;
case 0x0c078258u: goto P_0c078258;
case 0x0c07825au: goto P_0c07825a;
case 0x0c07825cu: goto P_0c07825c;
case 0x0c0786d8u: goto P_0c0786d8;
case 0x0c0786dau: goto P_0c0786da;
case 0x0c078e3cu: goto P_0c078e3c;
case 0x0c078e3eu: goto P_0c078e3e;
case 0x0c078e40u: goto P_0c078e40;
case 0x0c078e42u: goto P_0c078e42;
case 0x0c078e44u: goto P_0c078e44;
case 0x0c078e46u: goto P_0c078e46;
case 0x0c078e48u: goto P_0c078e48;
case 0x0c078e4au: goto P_0c078e4a;
case 0x0c078e4cu: goto P_0c078e4c;
case 0x0c078e4eu: goto P_0c078e4e;
case 0x0c078e50u: goto P_0c078e50;
case 0x0c078e52u: goto P_0c078e52;
case 0x0c078e54u: goto P_0c078e54;
case 0x0c078e56u: goto P_0c078e56;
case 0x0c078e58u: goto P_0c078e58;
case 0x0c078e5au: goto P_0c078e5a;
case 0x0c078e5cu: goto P_0c078e5c;
case 0x0c078e5eu: goto P_0c078e5e;
case 0x0c078e60u: goto P_0c078e60;
case 0x0c078e62u: goto P_0c078e62;
case 0x0c078e64u: goto P_0c078e64;
case 0x0c078e66u: goto P_0c078e66;
case 0x0c078e68u: goto P_0c078e68;
case 0x0c078e6au: goto P_0c078e6a;
case 0x0c078e6cu: goto P_0c078e6c;
case 0x0c078e6eu: goto P_0c078e6e;
case 0x0c078e70u: goto P_0c078e70;
case 0x0c078e72u: goto P_0c078e72;
case 0x0c078e74u: goto P_0c078e74;
case 0x0c078e76u: goto P_0c078e76;
case 0x0c078e78u: goto P_0c078e78;
case 0x0c078e7au: goto P_0c078e7a;
case 0x0c078e7cu: goto P_0c078e7c;
case 0x0c078e7eu: goto P_0c078e7e;
case 0x0c078e80u: goto P_0c078e80;
case 0x0c078e82u: goto P_0c078e82;
case 0x0c078e84u: goto P_0c078e84;
case 0x0c07ab14u: goto P_0c07ab14;
case 0x0c07ab16u: goto P_0c07ab16;
case 0x0c07ab18u: goto P_0c07ab18;
case 0x0c07ab1au: goto P_0c07ab1a;
case 0x0c07ab1cu: goto P_0c07ab1c;
case 0x0c07ab1eu: goto P_0c07ab1e;
case 0x0c07ab20u: goto P_0c07ab20;
case 0x0c07ab22u: goto P_0c07ab22;
case 0x0c07ab24u: goto P_0c07ab24;
case 0x0c07ab26u: goto P_0c07ab26;
case 0x0c07ab28u: goto P_0c07ab28;
case 0x0c07ab2au: goto P_0c07ab2a;
case 0x0c07ab2cu: goto P_0c07ab2c;
case 0x0c07ab2eu: goto P_0c07ab2e;
case 0x0c07ab30u: goto P_0c07ab30;
case 0x0c07ab32u: goto P_0c07ab32;
case 0x0c07ab34u: goto P_0c07ab34;
case 0x0c07ab36u: goto P_0c07ab36;
case 0x0c07ab38u: goto P_0c07ab38;
case 0x0c07ab3au: goto P_0c07ab3a;
case 0x0c07ab3cu: goto P_0c07ab3c;
case 0x0c07ab3eu: goto P_0c07ab3e;
case 0x0c07ab40u: goto P_0c07ab40;
case 0x0c07ab42u: goto P_0c07ab42;
case 0x0c07ab44u: goto P_0c07ab44;
case 0x0c07ab46u: goto P_0c07ab46;
case 0x0c07ab48u: goto P_0c07ab48;
case 0x0c07ab4au: goto P_0c07ab4a;
case 0x0c07ab4cu: goto P_0c07ab4c;
case 0x0c07ab4eu: goto P_0c07ab4e;
case 0x0c07ab50u: goto P_0c07ab50;
case 0x0c07ab52u: goto P_0c07ab52;
case 0x0c07ab54u: goto P_0c07ab54;
case 0x0c07ab56u: goto P_0c07ab56;
case 0x0c07ab58u: goto P_0c07ab58;
case 0x0c07ab5au: goto P_0c07ab5a;
case 0x0c07ab5cu: goto P_0c07ab5c;
case 0x0c07ab5eu: goto P_0c07ab5e;
case 0x0c07ab60u: goto P_0c07ab60;
case 0x0c07ab62u: goto P_0c07ab62;
case 0x0c07ab64u: goto P_0c07ab64;
case 0x0c07ab66u: goto P_0c07ab66;
case 0x0c07ab68u: goto P_0c07ab68;
case 0x0c07ab6au: goto P_0c07ab6a;
case 0x0c07ab6cu: goto P_0c07ab6c;
case 0x0c07ab6eu: goto P_0c07ab6e;
case 0x0c07ab70u: goto P_0c07ab70;
case 0x0c07ab72u: goto P_0c07ab72;
case 0x0c07ab74u: goto P_0c07ab74;
case 0x0c07ab76u: goto P_0c07ab76;
case 0x0c07ab78u: goto P_0c07ab78;
case 0x0c07ab7au: goto P_0c07ab7a;
case 0x0c07ab7cu: goto P_0c07ab7c;
case 0x0c07ab7eu: goto P_0c07ab7e;
case 0x0c07ab80u: goto P_0c07ab80;
case 0x0c07ab82u: goto P_0c07ab82;
case 0x0c07ab84u: goto P_0c07ab84;
case 0x0c07b5f0u: goto P_0c07b5f0;
case 0x0c07b5f2u: goto P_0c07b5f2;
case 0x0c07b5f4u: goto P_0c07b5f4;
case 0x0c07b5f6u: goto P_0c07b5f6;
case 0x0c07b5f8u: goto P_0c07b5f8;
case 0x0c07b5fau: goto P_0c07b5fa;
case 0x0c07b5fcu: goto P_0c07b5fc;
case 0x0c07b5feu: goto P_0c07b5fe;
case 0x0c07b600u: goto P_0c07b600;
case 0x0c07b602u: goto P_0c07b602;
case 0x0c07b604u: goto P_0c07b604;
case 0x0c07b606u: goto P_0c07b606;
case 0x0c07b608u: goto P_0c07b608;
case 0x0c07b60au: goto P_0c07b60a;
case 0x0c07b60cu: goto P_0c07b60c;
case 0x0c07b60eu: goto P_0c07b60e;
case 0x0c07b610u: goto P_0c07b610;
case 0x0c07b612u: goto P_0c07b612;
case 0x0c07b614u: goto P_0c07b614;
case 0x0c07b616u: goto P_0c07b616;
case 0x0c07b618u: goto P_0c07b618;
case 0x0c07b61au: goto P_0c07b61a;
case 0x0c07b61cu: goto P_0c07b61c;
case 0x0c07b61eu: goto P_0c07b61e;
case 0x0c07b620u: goto P_0c07b620;
case 0x0c07b622u: goto P_0c07b622;
case 0x0c07b624u: goto P_0c07b624;
case 0x0c07b626u: goto P_0c07b626;
case 0x0c07b628u: goto P_0c07b628;
case 0x0c07b62au: goto P_0c07b62a;
case 0x0c07b62cu: goto P_0c07b62c;
case 0x0c07b62eu: goto P_0c07b62e;
case 0x0c07b630u: goto P_0c07b630;
case 0x0c07b632u: goto P_0c07b632;
case 0x0c07b634u: goto P_0c07b634;
case 0x0c07b636u: goto P_0c07b636;
case 0x0c07b638u: goto P_0c07b638;
case 0x0c07b63au: goto P_0c07b63a;
case 0x0c07b63cu: goto P_0c07b63c;
case 0x0c07b63eu: goto P_0c07b63e;
case 0x0c07b640u: goto P_0c07b640;
case 0x0c07b642u: goto P_0c07b642;
case 0x0c07b644u: goto P_0c07b644;
case 0x0c07b646u: goto P_0c07b646;
case 0x0c07b648u: goto P_0c07b648;
case 0x0c07b64au: goto P_0c07b64a;
case 0x0c07b64cu: goto P_0c07b64c;
case 0x0c07b64eu: goto P_0c07b64e;
case 0x0c07b650u: goto P_0c07b650;
case 0x0c07b652u: goto P_0c07b652;
case 0x0c07b654u: goto P_0c07b654;
case 0x0c07b656u: goto P_0c07b656;
case 0x0c07b658u: goto P_0c07b658;
case 0x0c07b65au: goto P_0c07b65a;
case 0x0c07b65cu: goto P_0c07b65c;
case 0x0c07b65eu: goto P_0c07b65e;
case 0x0c07b660u: goto P_0c07b660;
case 0x0c07b662u: goto P_0c07b662;
case 0x0c07b664u: goto P_0c07b664;
case 0x0c07b666u: goto P_0c07b666;
case 0x0c07b668u: goto P_0c07b668;
case 0x0c07b66au: goto P_0c07b66a;
case 0x0c07b66cu: goto P_0c07b66c;
case 0x0c0865d6u: goto P_0c0865d6;
case 0x0c0865d8u: goto P_0c0865d8;
case 0x0c0865dau: goto P_0c0865da;
case 0x0c0865dcu: goto P_0c0865dc;
case 0x0c0865deu: goto P_0c0865de;
case 0x0c0865e0u: goto P_0c0865e0;
case 0x0c0865e2u: goto P_0c0865e2;
case 0x0c0865e4u: goto P_0c0865e4;
case 0x0c0865e6u: goto P_0c0865e6;
case 0x0c0865e8u: goto P_0c0865e8;
case 0x0c0865eau: goto P_0c0865ea;
case 0x0c0865ecu: goto P_0c0865ec;
case 0x0c0865eeu: goto P_0c0865ee;
case 0x0c0865f0u: goto P_0c0865f0;
case 0x0c086618u: goto P_0c086618;
case 0x0c08661au: goto P_0c08661a;
case 0x0c08661cu: goto P_0c08661c;
case 0x0c08661eu: goto P_0c08661e;
case 0x0c086620u: goto P_0c086620;
case 0x0c086622u: goto P_0c086622;
case 0x0c086624u: goto P_0c086624;
case 0x0c086626u: goto P_0c086626;
case 0x0c086628u: goto P_0c086628;
case 0x0c08662au: goto P_0c08662a;
case 0x0c08662cu: goto P_0c08662c;
case 0x0c08662eu: goto P_0c08662e;
case 0x0c086630u: goto P_0c086630;
case 0x0c086632u: goto P_0c086632;
case 0x0c086634u: goto P_0c086634;
case 0x0c086636u: goto P_0c086636;
case 0x0c086638u: goto P_0c086638;
case 0x0c08663au: goto P_0c08663a;
case 0x0c08663cu: goto P_0c08663c;
case 0x0c08663eu: goto P_0c08663e;
case 0x0c086640u: goto P_0c086640;
case 0x0c086642u: goto P_0c086642;
case 0x0c086644u: goto P_0c086644;
case 0x0c086646u: goto P_0c086646;
case 0x0c086648u: goto P_0c086648;
case 0x0c08664au: goto P_0c08664a;
case 0x0c08664cu: goto P_0c08664c;
case 0x0c08664eu: goto P_0c08664e;
case 0x0c086650u: goto P_0c086650;
case 0x0c086652u: goto P_0c086652;
case 0x0c086654u: goto P_0c086654;
case 0x0c086656u: goto P_0c086656;
case 0x0c086658u: goto P_0c086658;
case 0x0c08665au: goto P_0c08665a;
case 0x0c08665cu: goto P_0c08665c;
case 0x0c08665eu: goto P_0c08665e;
case 0x0c086660u: goto P_0c086660;
case 0x0c086662u: goto P_0c086662;
case 0x0c086664u: goto P_0c086664;
case 0x0c086666u: goto P_0c086666;
case 0x0c086668u: goto P_0c086668;
case 0x0c08666au: goto P_0c08666a;
case 0x0c08666cu: goto P_0c08666c;
case 0x0c08666eu: goto P_0c08666e;
case 0x0c086670u: goto P_0c086670;
case 0x0c086672u: goto P_0c086672;
case 0x0c086674u: goto P_0c086674;
case 0x0c086676u: goto P_0c086676;
case 0x0c086678u: goto P_0c086678;
case 0x0c08667au: goto P_0c08667a;
case 0x0c08667cu: goto P_0c08667c;
case 0x0c08667eu: goto P_0c08667e;
case 0x0c086680u: goto P_0c086680;
case 0x0c0866a0u: goto P_0c0866a0;
case 0x0c0866a2u: goto P_0c0866a2;
case 0x0c0866a4u: goto P_0c0866a4;
case 0x0c0866a6u: goto P_0c0866a6;
case 0x0c0866a8u: goto P_0c0866a8;
case 0x0c0866aau: goto P_0c0866aa;
case 0x0c0866acu: goto P_0c0866ac;
case 0x0c0866aeu: goto P_0c0866ae;
case 0x0c0866b0u: goto P_0c0866b0;
case 0x0c0866b2u: goto P_0c0866b2;
case 0x0c0866b4u: goto P_0c0866b4;
case 0x0c0866b6u: goto P_0c0866b6;
case 0x0c0866b8u: goto P_0c0866b8;
case 0x0c0866bau: goto P_0c0866ba;
case 0x0c0866bcu: goto P_0c0866bc;
case 0x0c0866beu: goto P_0c0866be;
case 0x0c0866c0u: goto P_0c0866c0;
case 0x0c0866c2u: goto P_0c0866c2;
case 0x0c0866c4u: goto P_0c0866c4;
case 0x0c0866c6u: goto P_0c0866c6;
case 0x0c0866c8u: goto P_0c0866c8;
case 0x0c0866cau: goto P_0c0866ca;
case 0x0c0866ccu: goto P_0c0866cc;
case 0x0c0866ceu: goto P_0c0866ce;
case 0x0c0866d0u: goto P_0c0866d0;
case 0x0c0866d2u: goto P_0c0866d2;
case 0x0c0866d4u: goto P_0c0866d4;
case 0x0c0866d6u: goto P_0c0866d6;
case 0x0c0866d8u: goto P_0c0866d8;
case 0x0c0866dau: goto P_0c0866da;
case 0x0c0866dcu: goto P_0c0866dc;
case 0x0c0866deu: goto P_0c0866de;
case 0x0c0866e0u: goto P_0c0866e0;
case 0x0c0866e2u: goto P_0c0866e2;
case 0x0c0866e4u: goto P_0c0866e4;
case 0x0c0866e6u: goto P_0c0866e6;
case 0x0c0866e8u: goto P_0c0866e8;
case 0x0c0866eau: goto P_0c0866ea;
case 0x0c0866ecu: goto P_0c0866ec;
case 0x0c0866eeu: goto P_0c0866ee;
case 0x0c0866f0u: goto P_0c0866f0;
case 0x0c0866f2u: goto P_0c0866f2;
case 0x0c0866f4u: goto P_0c0866f4;
case 0x0c0866f6u: goto P_0c0866f6;
case 0x0c0866f8u: goto P_0c0866f8;
case 0x0c0866fau: goto P_0c0866fa;
case 0x0c0866fcu: goto P_0c0866fc;
case 0x0c0866feu: goto P_0c0866fe;
case 0x0c086700u: goto P_0c086700;
case 0x0c086702u: goto P_0c086702;
case 0x0c086704u: goto P_0c086704;
case 0x0c086706u: goto P_0c086706;
case 0x0c086708u: goto P_0c086708;
case 0x0c08670au: goto P_0c08670a;
case 0x0c08670cu: goto P_0c08670c;
case 0x0c08670eu: goto P_0c08670e;
case 0x0c086710u: goto P_0c086710;
case 0x0c086712u: goto P_0c086712;
case 0x0c086714u: goto P_0c086714;
case 0x0c086716u: goto P_0c086716;
case 0x0c086718u: goto P_0c086718;
case 0x0c08671au: goto P_0c08671a;
case 0x0c08671cu: goto P_0c08671c;
case 0x0c08671eu: goto P_0c08671e;
case 0x0c086720u: goto P_0c086720;
case 0x0c086722u: goto P_0c086722;
case 0x0c086724u: goto P_0c086724;
case 0x0c086726u: goto P_0c086726;
case 0x0c086728u: goto P_0c086728;
case 0x0c08672au: goto P_0c08672a;
case 0x0c08672cu: goto P_0c08672c;
case 0x0c08672eu: goto P_0c08672e;
case 0x0c086730u: goto P_0c086730;
case 0x0c086732u: goto P_0c086732;
case 0x0c086734u: goto P_0c086734;
case 0x0c086736u: goto P_0c086736;
case 0x0c086738u: goto P_0c086738;
case 0x0c08673au: goto P_0c08673a;
case 0x0c08673cu: goto P_0c08673c;
case 0x0c08673eu: goto P_0c08673e;
case 0x0c086740u: goto P_0c086740;
case 0x0c086742u: goto P_0c086742;
case 0x0c086744u: goto P_0c086744;
case 0x0c086746u: goto P_0c086746;
case 0x0c086748u: goto P_0c086748;
case 0x0c08674au: goto P_0c08674a;
case 0x0c08674cu: goto P_0c08674c;
case 0x0c08674eu: goto P_0c08674e;
case 0x0c086750u: goto P_0c086750;
case 0x0c086752u: goto P_0c086752;
case 0x0c086754u: goto P_0c086754;
case 0x0c086756u: goto P_0c086756;
case 0x0c086758u: goto P_0c086758;
case 0x0c08675au: goto P_0c08675a;
case 0x0c08675cu: goto P_0c08675c;
case 0x0c08675eu: goto P_0c08675e;
case 0x0c086760u: goto P_0c086760;
case 0x0c086762u: goto P_0c086762;
case 0x0c086764u: goto P_0c086764;
case 0x0c086766u: goto P_0c086766;
case 0x0c086768u: goto P_0c086768;
case 0x0c08676au: goto P_0c08676a;
case 0x0c08676cu: goto P_0c08676c;
case 0x0c08676eu: goto P_0c08676e;
case 0x0c086770u: goto P_0c086770;
case 0x0c086772u: goto P_0c086772;
case 0x0c086774u: goto P_0c086774;
case 0x0c086776u: goto P_0c086776;
case 0x0c086778u: goto P_0c086778;
case 0x0c08677au: goto P_0c08677a;
case 0x0c08677cu: goto P_0c08677c;
case 0x0c08677eu: goto P_0c08677e;
case 0x0c086780u: goto P_0c086780;
case 0x0c086782u: goto P_0c086782;
case 0x0c086784u: goto P_0c086784;
case 0x0c086786u: goto P_0c086786;
case 0x0c086788u: goto P_0c086788;
case 0x0c08678au: goto P_0c08678a;
case 0x0c08678cu: goto P_0c08678c;
case 0x0c08678eu: goto P_0c08678e;
case 0x0c086790u: goto P_0c086790;
case 0x0c086792u: goto P_0c086792;
case 0x0c086794u: goto P_0c086794;
case 0x0c086796u: goto P_0c086796;
case 0x0c086798u: goto P_0c086798;
case 0x0c08679au: goto P_0c08679a;
case 0x0c08679cu: goto P_0c08679c;
case 0x0c08679eu: goto P_0c08679e;
case 0x0c0867a0u: goto P_0c0867a0;
case 0x0c0867a2u: goto P_0c0867a2;
case 0x0c0867a4u: goto P_0c0867a4;
case 0x0c0867a6u: goto P_0c0867a6;
case 0x0c0867a8u: goto P_0c0867a8;
case 0x0c0867aau: goto P_0c0867aa;
case 0x0c0867acu: goto P_0c0867ac;
case 0x0c0867aeu: goto P_0c0867ae;
case 0x0c0867b0u: goto P_0c0867b0;
case 0x0c0867b2u: goto P_0c0867b2;
case 0x0c0867b4u: goto P_0c0867b4;
case 0x0c0867b6u: goto P_0c0867b6;
case 0x0c0867b8u: goto P_0c0867b8;
case 0x0c0867d0u: goto P_0c0867d0;
case 0x0c0867d2u: goto P_0c0867d2;
case 0x0c0867d4u: goto P_0c0867d4;
case 0x0c0867d6u: goto P_0c0867d6;
case 0x0c0867d8u: goto P_0c0867d8;
case 0x0c0867dau: goto P_0c0867da;
case 0x0c0867dcu: goto P_0c0867dc;
case 0x0c0867deu: goto P_0c0867de;
case 0x0c0867e0u: goto P_0c0867e0;
case 0x0c0867e2u: goto P_0c0867e2;
case 0x0c0867e4u: goto P_0c0867e4;
case 0x0c0867e6u: goto P_0c0867e6;
case 0x0c0867e8u: goto P_0c0867e8;
case 0x0c0867eau: goto P_0c0867ea;
case 0x0c0867ecu: goto P_0c0867ec;
case 0x0c0867eeu: goto P_0c0867ee;
case 0x0c0867f0u: goto P_0c0867f0;
case 0x0c0867f2u: goto P_0c0867f2;
case 0x0c0867f4u: goto P_0c0867f4;
case 0x0c0867f6u: goto P_0c0867f6;
case 0x0c0867f8u: goto P_0c0867f8;
case 0x0c0867fau: goto P_0c0867fa;
case 0x0c0867fcu: goto P_0c0867fc;
case 0x0c0867feu: goto P_0c0867fe;
case 0x0c086800u: goto P_0c086800;
case 0x0c086802u: goto P_0c086802;
case 0x0c086804u: goto P_0c086804;
case 0x0c086806u: goto P_0c086806;
case 0x0c086808u: goto P_0c086808;
case 0x0c08b204u: goto P_0c08b204;
case 0x0c08b206u: goto P_0c08b206;
case 0x0c08b208u: goto P_0c08b208;
case 0x0c08b20au: goto P_0c08b20a;
case 0x0c08b20cu: goto P_0c08b20c;
case 0x0c08b20eu: goto P_0c08b20e;
case 0x0c08b210u: goto P_0c08b210;
case 0x0c08b212u: goto P_0c08b212;
case 0x0c08b214u: goto P_0c08b214;
case 0x0c08b216u: goto P_0c08b216;
case 0x0c08b218u: goto P_0c08b218;
case 0x0c08b21au: goto P_0c08b21a;
case 0x0c08b21cu: goto P_0c08b21c;
case 0x0c08b21eu: goto P_0c08b21e;
case 0x0c08b220u: goto P_0c08b220;
case 0x0c08b222u: goto P_0c08b222;
case 0x0c08b224u: goto P_0c08b224;
case 0x0c08b226u: goto P_0c08b226;
case 0x0c08b228u: goto P_0c08b228;
case 0x0c08b22au: goto P_0c08b22a;
case 0x0c08b22cu: goto P_0c08b22c;
case 0x0c08b22eu: goto P_0c08b22e;
case 0x0c08b230u: goto P_0c08b230;
case 0x0c08b232u: goto P_0c08b232;
case 0x0c08b234u: goto P_0c08b234;
case 0x0c08b236u: goto P_0c08b236;
case 0x0c08b238u: goto P_0c08b238;
case 0x0c08b23au: goto P_0c08b23a;
case 0x0c08b23cu: goto P_0c08b23c;
case 0x0c08b23eu: goto P_0c08b23e;
case 0x0c08b240u: goto P_0c08b240;
case 0x0c08b242u: goto P_0c08b242;
case 0x0c08b244u: goto P_0c08b244;
case 0x0c08b246u: goto P_0c08b246;
case 0x0c08b248u: goto P_0c08b248;
case 0x0c08b24au: goto P_0c08b24a;
case 0x0c08b24cu: goto P_0c08b24c;
case 0x0c08b24eu: goto P_0c08b24e;
case 0x0c08b250u: goto P_0c08b250;
case 0x0c08b252u: goto P_0c08b252;
case 0x0c08b254u: goto P_0c08b254;
case 0x0c08b256u: goto P_0c08b256;
case 0x0c08b258u: goto P_0c08b258;
case 0x0c08b25au: goto P_0c08b25a;
case 0x0c08b25cu: goto P_0c08b25c;
case 0x0c08b25eu: goto P_0c08b25e;
case 0x0c08b260u: goto P_0c08b260;
case 0x0c08b262u: goto P_0c08b262;
case 0x0c08b264u: goto P_0c08b264;
case 0x0c08b266u: goto P_0c08b266;
case 0x0c08b268u: goto P_0c08b268;
case 0x0c08b26au: goto P_0c08b26a;
case 0x0c08b26cu: goto P_0c08b26c;
case 0x0c08b26eu: goto P_0c08b26e;
case 0x0c08b270u: goto P_0c08b270;
case 0x0c08b272u: goto P_0c08b272;
case 0x0c08b274u: goto P_0c08b274;
case 0x0c08b276u: goto P_0c08b276;
case 0x0c08b278u: goto P_0c08b278;
case 0x0c08b27au: goto P_0c08b27a;
case 0x0c08b27cu: goto P_0c08b27c;
case 0x0c08b27eu: goto P_0c08b27e;
case 0x0c08b280u: goto P_0c08b280;
case 0x0c08b282u: goto P_0c08b282;
case 0x0c08b284u: goto P_0c08b284;
case 0x0c08b286u: goto P_0c08b286;
case 0x0c08b288u: goto P_0c08b288;
case 0x0c08b28au: goto P_0c08b28a;
case 0x0c08b28cu: goto P_0c08b28c;
case 0x0c08b28eu: goto P_0c08b28e;
case 0x0c08b290u: goto P_0c08b290;
case 0x0c08b292u: goto P_0c08b292;
case 0x0c08b294u: goto P_0c08b294;
case 0x0c08b296u: goto P_0c08b296;
case 0x0c08b298u: goto P_0c08b298;
case 0x0c08b29au: goto P_0c08b29a;
case 0x0c08b29cu: goto P_0c08b29c;
case 0x0c08b29eu: goto P_0c08b29e;
case 0x0c08b2a0u: goto P_0c08b2a0;
case 0x0c08b2a2u: goto P_0c08b2a2;
case 0x0c08b2a4u: goto P_0c08b2a4;
case 0x0c08b2a6u: goto P_0c08b2a6;
case 0x0c08b2a8u: goto P_0c08b2a8;
case 0x0c08b2aau: goto P_0c08b2aa;
case 0x0c08b2acu: goto P_0c08b2ac;
case 0x0c08b2aeu: goto P_0c08b2ae;
case 0x0c08b2b0u: goto P_0c08b2b0;
case 0x0c08b2b2u: goto P_0c08b2b2;
case 0x0c08b2b4u: goto P_0c08b2b4;
case 0x0c08b2b6u: goto P_0c08b2b6;
case 0x0c08b2b8u: goto P_0c08b2b8;
case 0x0c08b2bau: goto P_0c08b2ba;
case 0x0c08b2bcu: goto P_0c08b2bc;
case 0x0c08b2beu: goto P_0c08b2be;
case 0x0c08b2c0u: goto P_0c08b2c0;
case 0x0c08b2c2u: goto P_0c08b2c2;
case 0x0c08b2c4u: goto P_0c08b2c4;
case 0x0c08b2c6u: goto P_0c08b2c6;
case 0x0c08b2c8u: goto P_0c08b2c8;
case 0x0c08b2cau: goto P_0c08b2ca;
case 0x0c08b2ccu: goto P_0c08b2cc;
case 0x0c08b2ceu: goto P_0c08b2ce;
case 0x0c08b2d0u: goto P_0c08b2d0;
case 0x0c08b2d2u: goto P_0c08b2d2;
case 0x0c08b2d4u: goto P_0c08b2d4;
case 0x0c08b2d6u: goto P_0c08b2d6;
case 0x0c08b2d8u: goto P_0c08b2d8;
case 0x0c08b2dau: goto P_0c08b2da;
case 0x0c08b2dcu: goto P_0c08b2dc;
case 0x0c08b2deu: goto P_0c08b2de;
case 0x0c08b2e0u: goto P_0c08b2e0;
case 0x0c08b2e2u: goto P_0c08b2e2;
case 0x0c08b2e4u: goto P_0c08b2e4;
case 0x0c08b2e6u: goto P_0c08b2e6;
case 0x0c08b2e8u: goto P_0c08b2e8;
case 0x0c08b2eau: goto P_0c08b2ea;
case 0x0c08b2ecu: goto P_0c08b2ec;
case 0x0c08b2eeu: goto P_0c08b2ee;
case 0x0c08b2f0u: goto P_0c08b2f0;
case 0x0c08b2f2u: goto P_0c08b2f2;
case 0x0c08b2f4u: goto P_0c08b2f4;
case 0x0c08b2f6u: goto P_0c08b2f6;
case 0x0c08b2f8u: goto P_0c08b2f8;
case 0x0c08b448u: goto P_0c08b448;
case 0x0c08b44au: goto P_0c08b44a;
case 0x0c08b44cu: goto P_0c08b44c;
case 0x0c08b44eu: goto P_0c08b44e;
case 0x0c08b450u: goto P_0c08b450;
case 0x0c08b452u: goto P_0c08b452;
case 0x0c08b454u: goto P_0c08b454;
case 0x0c08b456u: goto P_0c08b456;
case 0x0c08b458u: goto P_0c08b458;
case 0x0c08b45au: goto P_0c08b45a;
case 0x0c08b45cu: goto P_0c08b45c;
case 0x0c08b45eu: goto P_0c08b45e;
case 0x0c08b460u: goto P_0c08b460;
case 0x0c08b462u: goto P_0c08b462;
case 0x0c08b464u: goto P_0c08b464;
case 0x0c08b466u: goto P_0c08b466;
case 0x0c08b468u: goto P_0c08b468;
case 0x0c08b46au: goto P_0c08b46a;
case 0x0c08b46cu: goto P_0c08b46c;
case 0x0c08b46eu: goto P_0c08b46e;
case 0x0c08b470u: goto P_0c08b470;
case 0x0c08b472u: goto P_0c08b472;
case 0x0c08b474u: goto P_0c08b474;
case 0x0c08b476u: goto P_0c08b476;
case 0x0c08b478u: goto P_0c08b478;
case 0x0c08b47au: goto P_0c08b47a;
case 0x0c08b47cu: goto P_0c08b47c;
case 0x0c08b47eu: goto P_0c08b47e;
case 0x0c08b480u: goto P_0c08b480;
case 0x0c08b482u: goto P_0c08b482;
case 0x0c08b484u: goto P_0c08b484;
case 0x0c08b486u: goto P_0c08b486;
case 0x0c08b488u: goto P_0c08b488;
case 0x0c08b48au: goto P_0c08b48a;
case 0x0c08b48cu: goto P_0c08b48c;
case 0x0c08b48eu: goto P_0c08b48e;
case 0x0c08b490u: goto P_0c08b490;
case 0x0c08b492u: goto P_0c08b492;
case 0x0c08b494u: goto P_0c08b494;
case 0x0c08b496u: goto P_0c08b496;
case 0x0c08b498u: goto P_0c08b498;
case 0x0c08b49au: goto P_0c08b49a;
case 0x0c08b49cu: goto P_0c08b49c;
case 0x0c08b49eu: goto P_0c08b49e;
case 0x0c08b4a0u: goto P_0c08b4a0;
case 0x0c08b4a2u: goto P_0c08b4a2;
case 0x0c08b4a4u: goto P_0c08b4a4;
case 0x0c08b4a6u: goto P_0c08b4a6;
case 0x0c08b4a8u: goto P_0c08b4a8;
case 0x0c08b4aau: goto P_0c08b4aa;
case 0x0c08b4acu: goto P_0c08b4ac;
case 0x0c08b4aeu: goto P_0c08b4ae;
case 0x0c08b4b0u: goto P_0c08b4b0;
case 0x0c08b4b2u: goto P_0c08b4b2;
case 0x0c08b4b4u: goto P_0c08b4b4;
case 0x0c08b4b6u: goto P_0c08b4b6;
case 0x0c08b4b8u: goto P_0c08b4b8;
case 0x0c08b4bau: goto P_0c08b4ba;
case 0x0c08b4bcu: goto P_0c08b4bc;
case 0x0c08b4beu: goto P_0c08b4be;
case 0x0c08b4c0u: goto P_0c08b4c0;
case 0x0c08b4c2u: goto P_0c08b4c2;
case 0x0c08b4c4u: goto P_0c08b4c4;
case 0x0c08b4c6u: goto P_0c08b4c6;
case 0x0c08b4c8u: goto P_0c08b4c8;
case 0x0c08b4cau: goto P_0c08b4ca;
case 0x0c08b4ccu: goto P_0c08b4cc;
case 0x0c08b4ceu: goto P_0c08b4ce;
case 0x0c08b4d0u: goto P_0c08b4d0;
case 0x0c08b4d2u: goto P_0c08b4d2;
case 0x0c08b4d4u: goto P_0c08b4d4;
case 0x0c08b4d6u: goto P_0c08b4d6;
case 0x0c08b4d8u: goto P_0c08b4d8;
case 0x0c08b4dau: goto P_0c08b4da;
case 0x0c08b4dcu: goto P_0c08b4dc;
case 0x0c08c83au: goto P_0c08c83a;
case 0x0c08c83cu: goto P_0c08c83c;
case 0x0c08c83eu: goto P_0c08c83e;
case 0x0c08c840u: goto P_0c08c840;
case 0x0c08c842u: goto P_0c08c842;
case 0x0c08c844u: goto P_0c08c844;
case 0x0c08c846u: goto P_0c08c846;
case 0x0c08c848u: goto P_0c08c848;
case 0x0c08c84au: goto P_0c08c84a;
case 0x0c08c84cu: goto P_0c08c84c;
case 0x0c08c84eu: goto P_0c08c84e;
case 0x0c08c850u: goto P_0c08c850;
case 0x0c08c852u: goto P_0c08c852;
case 0x0c08c854u: goto P_0c08c854;
case 0x0c08c856u: goto P_0c08c856;
case 0x0c08c858u: goto P_0c08c858;
case 0x0c08c85au: goto P_0c08c85a;
case 0x0c08c85cu: goto P_0c08c85c;
case 0x0c08c87cu: goto P_0c08c87c;
case 0x0c08c87eu: goto P_0c08c87e;
case 0x0c08c880u: goto P_0c08c880;
case 0x0c08c882u: goto P_0c08c882;
case 0x0c08c884u: goto P_0c08c884;
case 0x0c08c886u: goto P_0c08c886;
case 0x0c08c888u: goto P_0c08c888;
case 0x0c08c88au: goto P_0c08c88a;
case 0x0c08c88cu: goto P_0c08c88c;
case 0x0c08c88eu: goto P_0c08c88e;
case 0x0c08c890u: goto P_0c08c890;
case 0x0c08c892u: goto P_0c08c892;
case 0x0c08c894u: goto P_0c08c894;
case 0x0c08c896u: goto P_0c08c896;
case 0x0c08c898u: goto P_0c08c898;
case 0x0c08c89au: goto P_0c08c89a;
case 0x0c08c89cu: goto P_0c08c89c;
case 0x0c08c89eu: goto P_0c08c89e;
case 0x0c08c8a0u: goto P_0c08c8a0;
case 0x0c08c8a2u: goto P_0c08c8a2;
case 0x0c08c8a4u: goto P_0c08c8a4;
case 0x0c08c8a6u: goto P_0c08c8a6;
case 0x0c08c8a8u: goto P_0c08c8a8;
case 0x0c08c8aau: goto P_0c08c8aa;
case 0x0c08c8acu: goto P_0c08c8ac;
case 0x0c08c8aeu: goto P_0c08c8ae;
case 0x0c08c8b0u: goto P_0c08c8b0;
case 0x0c08c8b2u: goto P_0c08c8b2;
case 0x0c08c8b4u: goto P_0c08c8b4;
case 0x0c08c8b6u: goto P_0c08c8b6;
case 0x0c08c8b8u: goto P_0c08c8b8;
case 0x0c08c8bau: goto P_0c08c8ba;
case 0x0c08c8bcu: goto P_0c08c8bc;
case 0x0c08c8beu: goto P_0c08c8be;
case 0x0c08c8c0u: goto P_0c08c8c0;
case 0x0c08c8c2u: goto P_0c08c8c2;
case 0x0c08c8c4u: goto P_0c08c8c4;
case 0x0c08c8c6u: goto P_0c08c8c6;
case 0x0c08c8c8u: goto P_0c08c8c8;
case 0x0c08c8cau: goto P_0c08c8ca;
case 0x0c08c8ccu: goto P_0c08c8cc;
case 0x0c08c8ceu: goto P_0c08c8ce;
case 0x0c08c8d0u: goto P_0c08c8d0;
case 0x0c08c8d2u: goto P_0c08c8d2;
case 0x0c08c8d4u: goto P_0c08c8d4;
case 0x0c08c8d6u: goto P_0c08c8d6;
case 0x0c08c8d8u: goto P_0c08c8d8;
case 0x0c08c8dau: goto P_0c08c8da;
case 0x0c08c8dcu: goto P_0c08c8dc;
case 0x0c08c8deu: goto P_0c08c8de;
case 0x0c08c8e0u: goto P_0c08c8e0;
case 0x0c08c8e2u: goto P_0c08c8e2;
case 0x0c08c8e4u: goto P_0c08c8e4;
case 0x0c08c8e6u: goto P_0c08c8e6;
case 0x0c08c8e8u: goto P_0c08c8e8;
case 0x0c08c8eau: goto P_0c08c8ea;
case 0x0c08c8ecu: goto P_0c08c8ec;
case 0x0c08c8eeu: goto P_0c08c8ee;
case 0x0c08c8f0u: goto P_0c08c8f0;
case 0x0c08c8f2u: goto P_0c08c8f2;
case 0x0c08c8f4u: goto P_0c08c8f4;
case 0x0c08c8f6u: goto P_0c08c8f6;
case 0x0c08c8f8u: goto P_0c08c8f8;
case 0x0c08c8fau: goto P_0c08c8fa;
case 0x0c08c8fcu: goto P_0c08c8fc;
case 0x0c08c8feu: goto P_0c08c8fe;
case 0x0c08c900u: goto P_0c08c900;
case 0x0c08cdc4u: goto P_0c08cdc4;
case 0x0c08cdc6u: goto P_0c08cdc6;
case 0x0c08cdc8u: goto P_0c08cdc8;
case 0x0c08cdcau: goto P_0c08cdca;
case 0x0c08cdccu: goto P_0c08cdcc;
case 0x0c08cdceu: goto P_0c08cdce;
case 0x0c08cdd0u: goto P_0c08cdd0;
case 0x0c08cdd2u: goto P_0c08cdd2;
case 0x0c08cdd4u: goto P_0c08cdd4;
case 0x0c08cdd6u: goto P_0c08cdd6;
case 0x0c08cdd8u: goto P_0c08cdd8;
case 0x0c08cddau: goto P_0c08cdda;
case 0x0c08cddcu: goto P_0c08cddc;
case 0x0c08cddeu: goto P_0c08cdde;
case 0x0c08cde0u: goto P_0c08cde0;
case 0x0c08cde2u: goto P_0c08cde2;
case 0x0c08cde4u: goto P_0c08cde4;
case 0x0c08cde6u: goto P_0c08cde6;
case 0x0c08cde8u: goto P_0c08cde8;
case 0x0c08cdeau: goto P_0c08cdea;
case 0x0c08cdecu: goto P_0c08cdec;
case 0x0c08cdeeu: goto P_0c08cdee;
case 0x0c08cdf0u: goto P_0c08cdf0;
case 0x0c08cdf2u: goto P_0c08cdf2;
case 0x0c08cdf4u: goto P_0c08cdf4;
case 0x0c08cdf6u: goto P_0c08cdf6;
case 0x0c08cdf8u: goto P_0c08cdf8;
case 0x0c08cdfau: goto P_0c08cdfa;
case 0x0c08cdfcu: goto P_0c08cdfc;
case 0x0c08cdfeu: goto P_0c08cdfe;
case 0x0c08ce00u: goto P_0c08ce00;
case 0x0c08ce02u: goto P_0c08ce02;
case 0x0c08ce04u: goto P_0c08ce04;
case 0x0c08ce06u: goto P_0c08ce06;
case 0x0c08ce08u: goto P_0c08ce08;
case 0x0c08ce0au: goto P_0c08ce0a;
case 0x0c08ce0cu: goto P_0c08ce0c;
case 0x0c08ce0eu: goto P_0c08ce0e;
case 0x0c08ce10u: goto P_0c08ce10;
case 0x0c08ce12u: goto P_0c08ce12;
case 0x0c08ce14u: goto P_0c08ce14;
case 0x0c08ce16u: goto P_0c08ce16;
case 0x0c08ce18u: goto P_0c08ce18;
case 0x0c08ce1au: goto P_0c08ce1a;
case 0x0c08ce1cu: goto P_0c08ce1c;
case 0x0c08ce1eu: goto P_0c08ce1e;
case 0x0c08ce20u: goto P_0c08ce20;
case 0x0c08ce22u: goto P_0c08ce22;
case 0x0c08ce24u: goto P_0c08ce24;
case 0x0c08ce26u: goto P_0c08ce26;
case 0x0c08ce28u: goto P_0c08ce28;
case 0x0c08ce2au: goto P_0c08ce2a;
case 0x0c08ce2cu: goto P_0c08ce2c;
case 0x0c08ce2eu: goto P_0c08ce2e;
case 0x0c08ce30u: goto P_0c08ce30;
case 0x0c08ce32u: goto P_0c08ce32;
case 0x0c08ce34u: goto P_0c08ce34;
case 0x0c08ce36u: goto P_0c08ce36;
case 0x0c08ce38u: goto P_0c08ce38;
case 0x0c08ce3au: goto P_0c08ce3a;
case 0x0c08ce3cu: goto P_0c08ce3c;
case 0x0c08ce3eu: goto P_0c08ce3e;
case 0x0c08ce40u: goto P_0c08ce40;
case 0x0c08ce42u: goto P_0c08ce42;
case 0x0c08ce44u: goto P_0c08ce44;
case 0x0c08ce46u: goto P_0c08ce46;
case 0x0c08ce48u: goto P_0c08ce48;
case 0x0c08ce4au: goto P_0c08ce4a;
case 0x0c08ce4cu: goto P_0c08ce4c;
case 0x0c08ce4eu: goto P_0c08ce4e;
case 0x0c08ce50u: goto P_0c08ce50;
case 0x0c08ce52u: goto P_0c08ce52;
case 0x0c08ce54u: goto P_0c08ce54;
case 0x0c08ce56u: goto P_0c08ce56;
case 0x0c08ce58u: goto P_0c08ce58;
case 0x0c08ce5au: goto P_0c08ce5a;
case 0x0c08ce5cu: goto P_0c08ce5c;
case 0x0c08ce5eu: goto P_0c08ce5e;
case 0x0c08ce60u: goto P_0c08ce60;
case 0x0c08ce62u: goto P_0c08ce62;
case 0x0c08ce64u: goto P_0c08ce64;
case 0x0c08db78u: goto P_0c08db78;
case 0x0c08db7au: goto P_0c08db7a;
case 0x0c08db7cu: goto P_0c08db7c;
case 0x0c08db7eu: goto P_0c08db7e;
case 0x0c08db80u: goto P_0c08db80;
case 0x0c08db82u: goto P_0c08db82;
case 0x0c08db84u: goto P_0c08db84;
case 0x0c08db86u: goto P_0c08db86;
case 0x0c08db88u: goto P_0c08db88;
case 0x0c08db8au: goto P_0c08db8a;
case 0x0c08db8cu: goto P_0c08db8c;
case 0x0c08db8eu: goto P_0c08db8e;
case 0x0c08db90u: goto P_0c08db90;
case 0x0c08db92u: goto P_0c08db92;
case 0x0c08db94u: goto P_0c08db94;
case 0x0c08db96u: goto P_0c08db96;
case 0x0c08db98u: goto P_0c08db98;
case 0x0c08db9au: goto P_0c08db9a;
case 0x0c08db9cu: goto P_0c08db9c;
case 0x0c08db9eu: goto P_0c08db9e;
case 0x0c08dba0u: goto P_0c08dba0;
case 0x0c08dba2u: goto P_0c08dba2;
case 0x0c08dba4u: goto P_0c08dba4;
case 0x0c08dba6u: goto P_0c08dba6;
case 0x0c08dba8u: goto P_0c08dba8;
case 0x0c08dbaau: goto P_0c08dbaa;
case 0x0c08dbacu: goto P_0c08dbac;
case 0x0c08dbaeu: goto P_0c08dbae;
case 0x0c08dbb0u: goto P_0c08dbb0;
case 0x0c08dbb2u: goto P_0c08dbb2;
case 0x0c08dbb4u: goto P_0c08dbb4;
case 0x0c08dbb6u: goto P_0c08dbb6;
case 0x0c08dbb8u: goto P_0c08dbb8;
case 0x0c08dbbau: goto P_0c08dbba;
case 0x0c08dbbcu: goto P_0c08dbbc;
case 0x0c08dbbeu: goto P_0c08dbbe;
case 0x0c08dbc0u: goto P_0c08dbc0;
case 0x0c08dbc2u: goto P_0c08dbc2;
case 0x0c08dbc4u: goto P_0c08dbc4;
case 0x0c08dbc6u: goto P_0c08dbc6;
case 0x0c08dbc8u: goto P_0c08dbc8;
case 0x0c08dbcau: goto P_0c08dbca;
case 0x0c08dbccu: goto P_0c08dbcc;
case 0x0c08dbceu: goto P_0c08dbce;
case 0x0c08dbd0u: goto P_0c08dbd0;
case 0x0c08dbd2u: goto P_0c08dbd2;
case 0x0c08dbd4u: goto P_0c08dbd4;
case 0x0c08dbd6u: goto P_0c08dbd6;
case 0x0c08dbd8u: goto P_0c08dbd8;
case 0x0c08dbdau: goto P_0c08dbda;
case 0x0c08dbdcu: goto P_0c08dbdc;
case 0x0c08dbdeu: goto P_0c08dbde;
case 0x0c08dbe0u: goto P_0c08dbe0;
case 0x0c08dbe2u: goto P_0c08dbe2;
case 0x0c09183au: goto P_0c09183a;
case 0x0c09183cu: goto P_0c09183c;
case 0x0c09183eu: goto P_0c09183e;
case 0x0c091840u: goto P_0c091840;
case 0x0c091842u: goto P_0c091842;
case 0x0c091844u: goto P_0c091844;
case 0x0c091846u: goto P_0c091846;
case 0x0c091848u: goto P_0c091848;
case 0x0c09184au: goto P_0c09184a;
case 0x0c09184cu: goto P_0c09184c;
case 0x0c09184eu: goto P_0c09184e;
case 0x0c091850u: goto P_0c091850;
case 0x0c091852u: goto P_0c091852;
case 0x0c091854u: goto P_0c091854;
case 0x0c091856u: goto P_0c091856;
case 0x0c091858u: goto P_0c091858;
case 0x0c09185au: goto P_0c09185a;
case 0x0c09185cu: goto P_0c09185c;
case 0x0c09185eu: goto P_0c09185e;
case 0x0c091860u: goto P_0c091860;
case 0x0c091862u: goto P_0c091862;
case 0x0c091864u: goto P_0c091864;
case 0x0c091866u: goto P_0c091866;
case 0x0c091868u: goto P_0c091868;
case 0x0c09186au: goto P_0c09186a;
case 0x0c09186cu: goto P_0c09186c;
case 0x0c09186eu: goto P_0c09186e;
case 0x0c091870u: goto P_0c091870;
case 0x0c091872u: goto P_0c091872;
case 0x0c091874u: goto P_0c091874;
case 0x0c091876u: goto P_0c091876;
case 0x0c091878u: goto P_0c091878;
case 0x0c09187au: goto P_0c09187a;
case 0x0c09187cu: goto P_0c09187c;
case 0x0c09187eu: goto P_0c09187e;
case 0x0c091880u: goto P_0c091880;
case 0x0c091882u: goto P_0c091882;
case 0x0c091884u: goto P_0c091884;
case 0x0c091886u: goto P_0c091886;
case 0x0c091888u: goto P_0c091888;
case 0x0c09188au: goto P_0c09188a;
case 0x0c09188cu: goto P_0c09188c;
case 0x0c09188eu: goto P_0c09188e;
case 0x0c091890u: goto P_0c091890;
case 0x0c091892u: goto P_0c091892;
case 0x0c091894u: goto P_0c091894;
case 0x0c091896u: goto P_0c091896;
case 0x0c091898u: goto P_0c091898;
case 0x0c09189au: goto P_0c09189a;
case 0x0c09189cu: goto P_0c09189c;
case 0x0c09189eu: goto P_0c09189e;
case 0x0c0918a0u: goto P_0c0918a0;
case 0x0c0918a2u: goto P_0c0918a2;
case 0x0c0918a4u: goto P_0c0918a4;
case 0x0c0918a6u: goto P_0c0918a6;
case 0x0c0918a8u: goto P_0c0918a8;
case 0x0c0918aau: goto P_0c0918aa;
case 0x0c0918acu: goto P_0c0918ac;
case 0x0c0918aeu: goto P_0c0918ae;
case 0x0c0918b0u: goto P_0c0918b0;
case 0x0c0918b2u: goto P_0c0918b2;
case 0x0c0918b4u: goto P_0c0918b4;
case 0x0c0918b6u: goto P_0c0918b6;
case 0x0c0918b8u: goto P_0c0918b8;
case 0x0c0918bau: goto P_0c0918ba;
case 0x0c0918bcu: goto P_0c0918bc;
case 0x0c0918beu: goto P_0c0918be;
case 0x0c0918c0u: goto P_0c0918c0;
case 0x0c0918c2u: goto P_0c0918c2;
case 0x0c0918c4u: goto P_0c0918c4;
case 0x0c0918c6u: goto P_0c0918c6;
case 0x0c0918c8u: goto P_0c0918c8;
case 0x0c0918cau: goto P_0c0918ca;
case 0x0c0918ccu: goto P_0c0918cc;
case 0x0c0918ceu: goto P_0c0918ce;
case 0x0c0918d0u: goto P_0c0918d0;
case 0x0c0918d2u: goto P_0c0918d2;
case 0x0c0918d4u: goto P_0c0918d4;
case 0x0c0918d6u: goto P_0c0918d6;
case 0x0c0918d8u: goto P_0c0918d8;
case 0x0c0918dau: goto P_0c0918da;
case 0x0c0918dcu: goto P_0c0918dc;
case 0x0c0918deu: goto P_0c0918de;
case 0x0c0918e0u: goto P_0c0918e0;
case 0x0c0918e2u: goto P_0c0918e2;
case 0x0c0918e4u: goto P_0c0918e4;
case 0x0c0918e6u: goto P_0c0918e6;
case 0x0c0918e8u: goto P_0c0918e8;
case 0x0c0918eau: goto P_0c0918ea;
case 0x0c0918ecu: goto P_0c0918ec;
case 0x0c0918eeu: goto P_0c0918ee;
case 0x0c0918f0u: goto P_0c0918f0;
case 0x0c0918f2u: goto P_0c0918f2;
case 0x0c0918f4u: goto P_0c0918f4;
case 0x0c0918f6u: goto P_0c0918f6;
case 0x0c0918f8u: goto P_0c0918f8;
case 0x0c0918fau: goto P_0c0918fa;
case 0x0c0918fcu: goto P_0c0918fc;
case 0x0c0918feu: goto P_0c0918fe;
case 0x0c091900u: goto P_0c091900;
case 0x0c091902u: goto P_0c091902;
case 0x0c091904u: goto P_0c091904;
case 0x0c091906u: goto P_0c091906;
case 0x0c091908u: goto P_0c091908;
case 0x0c09190au: goto P_0c09190a;
case 0x0c09190cu: goto P_0c09190c;
case 0x0c09190eu: goto P_0c09190e;
case 0x0c091910u: goto P_0c091910;
case 0x0c091912u: goto P_0c091912;
case 0x0c091914u: goto P_0c091914;
case 0x0c091916u: goto P_0c091916;
case 0x0c091918u: goto P_0c091918;
case 0x0c09191au: goto P_0c09191a;
case 0x0c09191cu: goto P_0c09191c;
case 0x0c09191eu: goto P_0c09191e;
case 0x0c091920u: goto P_0c091920;
case 0x0c091922u: goto P_0c091922;
case 0x0c091924u: goto P_0c091924;
case 0x0c091926u: goto P_0c091926;
case 0x0c091928u: goto P_0c091928;
case 0x0c09192au: goto P_0c09192a;
case 0x0c09192cu: goto P_0c09192c;
case 0x0c09192eu: goto P_0c09192e;
case 0x0c091930u: goto P_0c091930;
case 0x0c091932u: goto P_0c091932;
case 0x0c091934u: goto P_0c091934;
case 0x0c091936u: goto P_0c091936;
case 0x0c091938u: goto P_0c091938;
case 0x0c09193au: goto P_0c09193a;
case 0x0c09193cu: goto P_0c09193c;
case 0x0c09193eu: goto P_0c09193e;
case 0x0c091940u: goto P_0c091940;
case 0x0c091942u: goto P_0c091942;
case 0x0c091944u: goto P_0c091944;
case 0x0c091946u: goto P_0c091946;
case 0x0c091948u: goto P_0c091948;
case 0x0c09194au: goto P_0c09194a;
case 0x0c09194cu: goto P_0c09194c;
case 0x0c09194eu: goto P_0c09194e;
case 0x0c091950u: goto P_0c091950;
case 0x0c091952u: goto P_0c091952;
case 0x0c091954u: goto P_0c091954;
case 0x0c091956u: goto P_0c091956;
case 0x0c091958u: goto P_0c091958;
case 0x0c09195au: goto P_0c09195a;
case 0x0c09195cu: goto P_0c09195c;
case 0x0c09195eu: goto P_0c09195e;
case 0x0c091960u: goto P_0c091960;
case 0x0c091962u: goto P_0c091962;
case 0x0c094372u: goto P_0c094372;
case 0x0c094374u: goto P_0c094374;
case 0x0c094376u: goto P_0c094376;
case 0x0c094378u: goto P_0c094378;
case 0x0c09437au: goto P_0c09437a;
case 0x0c09437cu: goto P_0c09437c;
case 0x0c09437eu: goto P_0c09437e;
case 0x0c094380u: goto P_0c094380;
case 0x0c094382u: goto P_0c094382;
case 0x0c094384u: goto P_0c094384;
case 0x0c094386u: goto P_0c094386;
case 0x0c094388u: goto P_0c094388;
case 0x0c09438au: goto P_0c09438a;
case 0x0c09438cu: goto P_0c09438c;
case 0x0c09438eu: goto P_0c09438e;
case 0x0c094390u: goto P_0c094390;
case 0x0c094392u: goto P_0c094392;
case 0x0c094394u: goto P_0c094394;
case 0x0c094396u: goto P_0c094396;
case 0x0c094398u: goto P_0c094398;
case 0x0c09439au: goto P_0c09439a;
case 0x0c09439cu: goto P_0c09439c;
case 0x0c09439eu: goto P_0c09439e;
case 0x0c0943a0u: goto P_0c0943a0;
case 0x0c0943a2u: goto P_0c0943a2;
case 0x0c0943a4u: goto P_0c0943a4;
case 0x0c0943a6u: goto P_0c0943a6;
case 0x0c0943a8u: goto P_0c0943a8;
case 0x0c0943aau: goto P_0c0943aa;
case 0x0c0943acu: goto P_0c0943ac;
case 0x0c0943aeu: goto P_0c0943ae;
case 0x0c0943b0u: goto P_0c0943b0;
case 0x0c0943b2u: goto P_0c0943b2;
case 0x0c0943b4u: goto P_0c0943b4;
case 0x0c0943b6u: goto P_0c0943b6;
case 0x0c0943b8u: goto P_0c0943b8;
case 0x0c0943bau: goto P_0c0943ba;
case 0x0c0943f8u: goto P_0c0943f8;
case 0x0c0943fau: goto P_0c0943fa;
case 0x0c0943fcu: goto P_0c0943fc;
case 0x0c0943feu: goto P_0c0943fe;
case 0x0c094400u: goto P_0c094400;
case 0x0c094402u: goto P_0c094402;
case 0x0c094404u: goto P_0c094404;
case 0x0c094406u: goto P_0c094406;
case 0x0c094408u: goto P_0c094408;
case 0x0c09440au: goto P_0c09440a;
case 0x0c09440cu: goto P_0c09440c;
case 0x0c09440eu: goto P_0c09440e;
case 0x0c094410u: goto P_0c094410;
case 0x0c094412u: goto P_0c094412;
case 0x0c094414u: goto P_0c094414;
case 0x0c094416u: goto P_0c094416;
case 0x0c094418u: goto P_0c094418;
case 0x0c09441au: goto P_0c09441a;
case 0x0c094420u: goto P_0c094420;
case 0x0c094422u: goto P_0c094422;
case 0x0c094424u: goto P_0c094424;
case 0x0c094426u: goto P_0c094426;
case 0x0c094428u: goto P_0c094428;
case 0x0c09442au: goto P_0c09442a;
case 0x0c09442cu: goto P_0c09442c;
case 0x0c09442eu: goto P_0c09442e;
case 0x0c094430u: goto P_0c094430;
case 0x0c094432u: goto P_0c094432;
case 0x0c094434u: goto P_0c094434;
case 0x0c094436u: goto P_0c094436;
case 0x0c094438u: goto P_0c094438;
case 0x0c09443au: goto P_0c09443a;
case 0x0c09443cu: goto P_0c09443c;
case 0x0c09443eu: goto P_0c09443e;
case 0x0c094440u: goto P_0c094440;
case 0x0c094442u: goto P_0c094442;
case 0x0c094444u: goto P_0c094444;
case 0x0c094446u: goto P_0c094446;
case 0x0c094448u: goto P_0c094448;
case 0x0c09444au: goto P_0c09444a;
case 0x0c09444cu: goto P_0c09444c;
case 0x0c09444eu: goto P_0c09444e;
case 0x0c094450u: goto P_0c094450;
case 0x0c094452u: goto P_0c094452;
case 0x0c094454u: goto P_0c094454;
case 0x0c094456u: goto P_0c094456;
case 0x0c094458u: goto P_0c094458;
case 0x0c09445au: goto P_0c09445a;
case 0x0c09445cu: goto P_0c09445c;
case 0x0c09445eu: goto P_0c09445e;
case 0x0c094460u: goto P_0c094460;
case 0x0c094462u: goto P_0c094462;
case 0x0c094464u: goto P_0c094464;
case 0x0c094466u: goto P_0c094466;
case 0x0c094468u: goto P_0c094468;
case 0x0c094470u: goto P_0c094470;
case 0x0c094472u: goto P_0c094472;
case 0x0c094474u: goto P_0c094474;
case 0x0c094476u: goto P_0c094476;
case 0x0c094478u: goto P_0c094478;
case 0x0c09447au: goto P_0c09447a;
case 0x0c09447cu: goto P_0c09447c;
case 0x0c09447eu: goto P_0c09447e;
case 0x0c094480u: goto P_0c094480;
case 0x0c094482u: goto P_0c094482;
case 0x0c094484u: goto P_0c094484;
case 0x0c094486u: goto P_0c094486;
case 0x0c094488u: goto P_0c094488;
case 0x0c09448au: goto P_0c09448a;
case 0x0c09448cu: goto P_0c09448c;
case 0x0c09448eu: goto P_0c09448e;
case 0x0c094490u: goto P_0c094490;
case 0x0c094492u: goto P_0c094492;
case 0x0c094494u: goto P_0c094494;
case 0x0c094496u: goto P_0c094496;
case 0x0c094498u: goto P_0c094498;
case 0x0c09449au: goto P_0c09449a;
case 0x0c09635au: goto P_0c09635a;
case 0x0c09635cu: goto P_0c09635c;
case 0x0c09635eu: goto P_0c09635e;
case 0x0c096360u: goto P_0c096360;
case 0x0c096362u: goto P_0c096362;
case 0x0c096364u: goto P_0c096364;
case 0x0c096366u: goto P_0c096366;
case 0x0c096368u: goto P_0c096368;
case 0x0c09636au: goto P_0c09636a;
case 0x0c09636cu: goto P_0c09636c;
case 0x0c09636eu: goto P_0c09636e;
case 0x0c096370u: goto P_0c096370;
case 0x0c096372u: goto P_0c096372;
case 0x0c096374u: goto P_0c096374;
case 0x0c096376u: goto P_0c096376;
case 0x0c096378u: goto P_0c096378;
case 0x0c09637au: goto P_0c09637a;
case 0x0c09637cu: goto P_0c09637c;
case 0x0c09637eu: goto P_0c09637e;
case 0x0c096380u: goto P_0c096380;
case 0x0c096382u: goto P_0c096382;
case 0x0c096384u: goto P_0c096384;
case 0x0c096386u: goto P_0c096386;
case 0x0c096388u: goto P_0c096388;
case 0x0c09638au: goto P_0c09638a;
case 0x0c09638cu: goto P_0c09638c;
case 0x0c09638eu: goto P_0c09638e;
case 0x0c096390u: goto P_0c096390;
case 0x0c096392u: goto P_0c096392;
case 0x0c096394u: goto P_0c096394;
case 0x0c096396u: goto P_0c096396;
case 0x0c096398u: goto P_0c096398;
case 0x0c09639au: goto P_0c09639a;
case 0x0c09639cu: goto P_0c09639c;
case 0x0c09639eu: goto P_0c09639e;
case 0x0c0963a0u: goto P_0c0963a0;
case 0x0c0963a2u: goto P_0c0963a2;
case 0x0c0963a4u: goto P_0c0963a4;
case 0x0c0963a6u: goto P_0c0963a6;
case 0x0c0963a8u: goto P_0c0963a8;
case 0x0c0963aau: goto P_0c0963aa;
case 0x0c0963d0u: goto P_0c0963d0;
case 0x0c0963d2u: goto P_0c0963d2;
case 0x0c0963d4u: goto P_0c0963d4;
case 0x0c0963d6u: goto P_0c0963d6;
case 0x0c0963d8u: goto P_0c0963d8;
case 0x0c0963dau: goto P_0c0963da;
case 0x0c0963dcu: goto P_0c0963dc;
case 0x0c0963deu: goto P_0c0963de;
case 0x0c0963e0u: goto P_0c0963e0;
case 0x0c0963e2u: goto P_0c0963e2;
case 0x0c0963e4u: goto P_0c0963e4;
case 0x0c0963e6u: goto P_0c0963e6;
case 0x0c0963e8u: goto P_0c0963e8;
case 0x0c0963eau: goto P_0c0963ea;
case 0x0c0963ecu: goto P_0c0963ec;
case 0x0c0963eeu: goto P_0c0963ee;
case 0x0c0963f0u: goto P_0c0963f0;
case 0x0c0963f2u: goto P_0c0963f2;
case 0x0c0963f4u: goto P_0c0963f4;
case 0x0c0963f6u: goto P_0c0963f6;
case 0x0c0963f8u: goto P_0c0963f8;
case 0x0c0963fau: goto P_0c0963fa;
case 0x0c0963fcu: goto P_0c0963fc;
case 0x0c0963feu: goto P_0c0963fe;
case 0x0c096400u: goto P_0c096400;
case 0x0c096402u: goto P_0c096402;
case 0x0c096404u: goto P_0c096404;
case 0x0c096406u: goto P_0c096406;
case 0x0c096408u: goto P_0c096408;
case 0x0c09640au: goto P_0c09640a;
case 0x0c09640cu: goto P_0c09640c;
case 0x0c09640eu: goto P_0c09640e;
case 0x0c096410u: goto P_0c096410;
case 0x0c096412u: goto P_0c096412;
case 0x0c096414u: goto P_0c096414;
case 0x0c096416u: goto P_0c096416;
case 0x0c096418u: goto P_0c096418;
case 0x0c09641au: goto P_0c09641a;
case 0x0c09641cu: goto P_0c09641c;
case 0x0c09641eu: goto P_0c09641e;
case 0x0c096420u: goto P_0c096420;
case 0x0c096422u: goto P_0c096422;
case 0x0c096424u: goto P_0c096424;
case 0x0c096426u: goto P_0c096426;
case 0x0c096428u: goto P_0c096428;
case 0x0c09642au: goto P_0c09642a;
case 0x0c09642cu: goto P_0c09642c;
case 0x0c09642eu: goto P_0c09642e;
case 0x0c096430u: goto P_0c096430;
case 0x0c096432u: goto P_0c096432;
case 0x0c096434u: goto P_0c096434;
case 0x0c096436u: goto P_0c096436;
case 0x0c096438u: goto P_0c096438;
case 0x0c09643au: goto P_0c09643a;
case 0x0c09643cu: goto P_0c09643c;
case 0x0c09643eu: goto P_0c09643e;
case 0x0c096440u: goto P_0c096440;
case 0x0c096442u: goto P_0c096442;
case 0x0c096444u: goto P_0c096444;
case 0x0c096446u: goto P_0c096446;
case 0x0c096448u: goto P_0c096448;
case 0x0c09644au: goto P_0c09644a;
case 0x0c09644cu: goto P_0c09644c;
case 0x0c09644eu: goto P_0c09644e;
case 0x0c096450u: goto P_0c096450;
case 0x0c096452u: goto P_0c096452;
case 0x0c096454u: goto P_0c096454;
case 0x0c096456u: goto P_0c096456;
case 0x0c096458u: goto P_0c096458;
case 0x0c09645au: goto P_0c09645a;
case 0x0c09645cu: goto P_0c09645c;
case 0x0c09645eu: goto P_0c09645e;
case 0x0c096460u: goto P_0c096460;
case 0x0c096462u: goto P_0c096462;
case 0x0c096464u: goto P_0c096464;
case 0x0c096466u: goto P_0c096466;
case 0x0c096468u: goto P_0c096468;
case 0x0c09646au: goto P_0c09646a;
case 0x0c09646cu: goto P_0c09646c;
case 0x0c09646eu: goto P_0c09646e;
case 0x0c096470u: goto P_0c096470;
case 0x0c096472u: goto P_0c096472;
case 0x0c096474u: goto P_0c096474;
case 0x0c096476u: goto P_0c096476;
case 0x0c096478u: goto P_0c096478;
case 0x0c09647au: goto P_0c09647a;
case 0x0c09647cu: goto P_0c09647c;
case 0x0c09647eu: goto P_0c09647e;
case 0x0c096480u: goto P_0c096480;
case 0x0c096482u: goto P_0c096482;
case 0x0c096484u: goto P_0c096484;
case 0x0c096486u: goto P_0c096486;
case 0x0c096488u: goto P_0c096488;
case 0x0c09648au: goto P_0c09648a;
case 0x0c09648cu: goto P_0c09648c;
case 0x0c09648eu: goto P_0c09648e;
case 0x0c096490u: goto P_0c096490;
case 0x0c096492u: goto P_0c096492;
case 0x0c096494u: goto P_0c096494;
case 0x0c096496u: goto P_0c096496;
case 0x0c096498u: goto P_0c096498;
case 0x0c09649au: goto P_0c09649a;
case 0x0c09649cu: goto P_0c09649c;
case 0x0c09649eu: goto P_0c09649e;
case 0x0c0964a0u: goto P_0c0964a0;
case 0x0c0964a2u: goto P_0c0964a2;
case 0x0c0964a4u: goto P_0c0964a4;
case 0x0c0964a6u: goto P_0c0964a6;
case 0x0c0964a8u: goto P_0c0964a8;
case 0x0c0964aau: goto P_0c0964aa;
case 0x0c0964acu: goto P_0c0964ac;
case 0x0c0964aeu: goto P_0c0964ae;
case 0x0c0964b0u: goto P_0c0964b0;
case 0x0c0964b2u: goto P_0c0964b2;
case 0x0c0964b4u: goto P_0c0964b4;
case 0x0c0964b6u: goto P_0c0964b6;
case 0x0c0964b8u: goto P_0c0964b8;
case 0x0c0964bau: goto P_0c0964ba;
case 0x0c0964bcu: goto P_0c0964bc;
case 0x0c0964beu: goto P_0c0964be;
case 0x0c0964c0u: goto P_0c0964c0;
case 0x0c0964c2u: goto P_0c0964c2;
case 0x0c09650cu: goto P_0c09650c;
case 0x0c09650eu: goto P_0c09650e;
case 0x0c096510u: goto P_0c096510;
case 0x0c096512u: goto P_0c096512;
case 0x0c096514u: goto P_0c096514;
case 0x0c096516u: goto P_0c096516;
case 0x0c096518u: goto P_0c096518;
case 0x0c09651au: goto P_0c09651a;
case 0x0c09651cu: goto P_0c09651c;
case 0x0c09651eu: goto P_0c09651e;
case 0x0c096520u: goto P_0c096520;
case 0x0c096522u: goto P_0c096522;
case 0x0c096524u: goto P_0c096524;
case 0x0c096526u: goto P_0c096526;
case 0x0c096528u: goto P_0c096528;
case 0x0c09652au: goto P_0c09652a;
case 0x0c09652cu: goto P_0c09652c;
case 0x0c09652eu: goto P_0c09652e;
case 0x0c096530u: goto P_0c096530;
case 0x0c096532u: goto P_0c096532;
case 0x0c096534u: goto P_0c096534;
case 0x0c096536u: goto P_0c096536;
case 0x0c096538u: goto P_0c096538;
case 0x0c09653au: goto P_0c09653a;
case 0x0c09653cu: goto P_0c09653c;
case 0x0c09653eu: goto P_0c09653e;
case 0x0c096540u: goto P_0c096540;
case 0x0c096542u: goto P_0c096542;
case 0x0c096544u: goto P_0c096544;
case 0x0c096546u: goto P_0c096546;
case 0x0c096548u: goto P_0c096548;
case 0x0c09654au: goto P_0c09654a;
case 0x0c09654cu: goto P_0c09654c;
case 0x0c09654eu: goto P_0c09654e;
case 0x0c096550u: goto P_0c096550;
case 0x0c096552u: goto P_0c096552;
case 0x0c096554u: goto P_0c096554;
case 0x0c096556u: goto P_0c096556;
case 0x0c096558u: goto P_0c096558;
case 0x0c09655au: goto P_0c09655a;
case 0x0c09655cu: goto P_0c09655c;
case 0x0c09655eu: goto P_0c09655e;
case 0x0c096560u: goto P_0c096560;
case 0x0c096562u: goto P_0c096562;
case 0x0c096564u: goto P_0c096564;
case 0x0c096566u: goto P_0c096566;
case 0x0c096568u: goto P_0c096568;
case 0x0c09656au: goto P_0c09656a;
case 0x0c09656cu: goto P_0c09656c;
case 0x0c09656eu: goto P_0c09656e;
case 0x0c096570u: goto P_0c096570;
case 0x0c096572u: goto P_0c096572;
case 0x0c096574u: goto P_0c096574;
case 0x0c096576u: goto P_0c096576;
case 0x0c096578u: goto P_0c096578;
case 0x0c09657au: goto P_0c09657a;
case 0x0c09657cu: goto P_0c09657c;
case 0x0c09657eu: goto P_0c09657e;
case 0x0c096580u: goto P_0c096580;
case 0x0c096582u: goto P_0c096582;
case 0x0c096584u: goto P_0c096584;
case 0x0c096586u: goto P_0c096586;
case 0x0c096588u: goto P_0c096588;
case 0x0c09658au: goto P_0c09658a;
case 0x0c09658cu: goto P_0c09658c;
case 0x0c09658eu: goto P_0c09658e;
case 0x0c096590u: goto P_0c096590;
case 0x0c096592u: goto P_0c096592;
case 0x0c096594u: goto P_0c096594;
case 0x0c096596u: goto P_0c096596;
case 0x0c096598u: goto P_0c096598;
case 0x0c09659au: goto P_0c09659a;
case 0x0c09659cu: goto P_0c09659c;
case 0x0c09659eu: goto P_0c09659e;
case 0x0c0965a0u: goto P_0c0965a0;
case 0x0c0965a2u: goto P_0c0965a2;
case 0x0c0965a4u: goto P_0c0965a4;
case 0x0c0965a6u: goto P_0c0965a6;
case 0x0c0965a8u: goto P_0c0965a8;
case 0x0c0965aau: goto P_0c0965aa;
case 0x0c0965acu: goto P_0c0965ac;
case 0x0c0965aeu: goto P_0c0965ae;
case 0x0c0965b0u: goto P_0c0965b0;
case 0x0c0965b2u: goto P_0c0965b2;
case 0x0c0965b4u: goto P_0c0965b4;
case 0x0c0965b6u: goto P_0c0965b6;
case 0x0c0965b8u: goto P_0c0965b8;
case 0x0c0965bau: goto P_0c0965ba;
case 0x0c0965bcu: goto P_0c0965bc;
case 0x0c0965beu: goto P_0c0965be;
case 0x0c0965c0u: goto P_0c0965c0;
case 0x0c0965c2u: goto P_0c0965c2;
case 0x0c0965c4u: goto P_0c0965c4;
case 0x0c0965c6u: goto P_0c0965c6;
case 0x0c0965c8u: goto P_0c0965c8;
case 0x0c0965cau: goto P_0c0965ca;
case 0x0c0965ccu: goto P_0c0965cc;
case 0x0c0965ecu: goto P_0c0965ec;
case 0x0c0965eeu: goto P_0c0965ee;
case 0x0c0965f0u: goto P_0c0965f0;
case 0x0c0965f2u: goto P_0c0965f2;
case 0x0c0965f4u: goto P_0c0965f4;
case 0x0c0965f6u: goto P_0c0965f6;
case 0x0c0965f8u: goto P_0c0965f8;
case 0x0c0965fau: goto P_0c0965fa;
case 0x0c0965fcu: goto P_0c0965fc;
case 0x0c0965feu: goto P_0c0965fe;
case 0x0c096600u: goto P_0c096600;
case 0x0c096602u: goto P_0c096602;
case 0x0c096604u: goto P_0c096604;
case 0x0c096606u: goto P_0c096606;
case 0x0c096608u: goto P_0c096608;
case 0x0c09660au: goto P_0c09660a;
case 0x0c09660cu: goto P_0c09660c;
case 0x0c09660eu: goto P_0c09660e;
case 0x0c096610u: goto P_0c096610;
case 0x0c096612u: goto P_0c096612;
case 0x0c096614u: goto P_0c096614;
case 0x0c096616u: goto P_0c096616;
case 0x0c096618u: goto P_0c096618;
case 0x0c09661au: goto P_0c09661a;
case 0x0c09661cu: goto P_0c09661c;
case 0x0c09661eu: goto P_0c09661e;
case 0x0c096620u: goto P_0c096620;
case 0x0c096622u: goto P_0c096622;
case 0x0c096624u: goto P_0c096624;
case 0x0c096626u: goto P_0c096626;
case 0x0c096628u: goto P_0c096628;
case 0x0c09662au: goto P_0c09662a;
case 0x0c09662cu: goto P_0c09662c;
case 0x0c09662eu: goto P_0c09662e;
case 0x0c096630u: goto P_0c096630;
case 0x0c096632u: goto P_0c096632;
case 0x0c096634u: goto P_0c096634;
case 0x0c096636u: goto P_0c096636;
case 0x0c096638u: goto P_0c096638;
case 0x0c09663au: goto P_0c09663a;
case 0x0c09663cu: goto P_0c09663c;
case 0x0c09663eu: goto P_0c09663e;
case 0x0c096640u: goto P_0c096640;
case 0x0c096642u: goto P_0c096642;
case 0x0c096644u: goto P_0c096644;
case 0x0c096646u: goto P_0c096646;
case 0x0c096648u: goto P_0c096648;
case 0x0c09664au: goto P_0c09664a;
case 0x0c0a037cu: goto P_0c0a037c;
case 0x0c0a037eu: goto P_0c0a037e;
case 0x0c0a0380u: goto P_0c0a0380;
case 0x0c0a0382u: goto P_0c0a0382;
case 0x0c0a0384u: goto P_0c0a0384;
case 0x0c0a0386u: goto P_0c0a0386;
case 0x0c0a0388u: goto P_0c0a0388;
case 0x0c0a038au: goto P_0c0a038a;
case 0x0c0a038cu: goto P_0c0a038c;
case 0x0c0a038eu: goto P_0c0a038e;
case 0x0c0a0390u: goto P_0c0a0390;
case 0x0c0a0392u: goto P_0c0a0392;
case 0x0c0a0394u: goto P_0c0a0394;
case 0x0c0a0396u: goto P_0c0a0396;
case 0x0c0a0398u: goto P_0c0a0398;
case 0x0c0a039au: goto P_0c0a039a;
case 0x0c0a039cu: goto P_0c0a039c;
case 0x0c0a039eu: goto P_0c0a039e;
case 0x0c0a03a0u: goto P_0c0a03a0;
case 0x0c0a03a2u: goto P_0c0a03a2;
case 0x0c0a03a4u: goto P_0c0a03a4;
case 0x0c0a03a6u: goto P_0c0a03a6;
case 0x0c0a03a8u: goto P_0c0a03a8;
case 0x0c0a03aau: goto P_0c0a03aa;
case 0x0c0a03acu: goto P_0c0a03ac;
case 0x0c0a03aeu: goto P_0c0a03ae;
case 0x0c0a03b0u: goto P_0c0a03b0;
case 0x0c0a03b2u: goto P_0c0a03b2;
case 0x0c0a03b4u: goto P_0c0a03b4;
case 0x0c0a03b6u: goto P_0c0a03b6;
case 0x0c0a03b8u: goto P_0c0a03b8;
case 0x0c0a03bau: goto P_0c0a03ba;
case 0x0c0a03bcu: goto P_0c0a03bc;
case 0x0c0a03beu: goto P_0c0a03be;
case 0x0c0a03c0u: goto P_0c0a03c0;
case 0x0c0a03c2u: goto P_0c0a03c2;
case 0x0c0a03c4u: goto P_0c0a03c4;
case 0x0c0a03c6u: goto P_0c0a03c6;
case 0x0c0a03c8u: goto P_0c0a03c8;
case 0x0c0a03cau: goto P_0c0a03ca;
case 0x0c0a03ccu: goto P_0c0a03cc;
case 0x0c0a03ceu: goto P_0c0a03ce;
case 0x0c0a03d0u: goto P_0c0a03d0;
case 0x0c0a03d2u: goto P_0c0a03d2;
case 0x0c0a03d4u: goto P_0c0a03d4;
case 0x0c0a03d6u: goto P_0c0a03d6;
case 0x0c0a03d8u: goto P_0c0a03d8;
case 0x0c0a03dau: goto P_0c0a03da;
case 0x0c0a03dcu: goto P_0c0a03dc;
case 0x0c0a041eu: goto P_0c0a041e;
case 0x0c0a0420u: goto P_0c0a0420;
case 0x0c0a0422u: goto P_0c0a0422;
case 0x0c0a0424u: goto P_0c0a0424;
case 0x0c0a0426u: goto P_0c0a0426;
case 0x0c0a0428u: goto P_0c0a0428;
case 0x0c0a042au: goto P_0c0a042a;
case 0x0c0a042cu: goto P_0c0a042c;
case 0x0c0a042eu: goto P_0c0a042e;
case 0x0c0a0430u: goto P_0c0a0430;
case 0x0c0a0432u: goto P_0c0a0432;
case 0x0c0a0434u: goto P_0c0a0434;
case 0x0c0a0436u: goto P_0c0a0436;
case 0x0c0a0438u: goto P_0c0a0438;
case 0x0c0a043au: goto P_0c0a043a;
case 0x0c0a043cu: goto P_0c0a043c;
case 0x0c0a043eu: goto P_0c0a043e;
case 0x0c0a0440u: goto P_0c0a0440;
case 0x0c0a0442u: goto P_0c0a0442;
case 0x0c0a045cu: goto P_0c0a045c;
case 0x0c0a045eu: goto P_0c0a045e;
case 0x0c0a0460u: goto P_0c0a0460;
case 0x0c0a0462u: goto P_0c0a0462;
case 0x0c0a04dcu: goto P_0c0a04dc;
case 0x0c0a04deu: goto P_0c0a04de;
case 0x0c0a04e0u: goto P_0c0a04e0;
case 0x0c0a058cu: goto P_0c0a058c;
case 0x0c0a058eu: goto P_0c0a058e;
case 0x0c0a0590u: goto P_0c0a0590;
case 0x0c0a0592u: goto P_0c0a0592;
case 0x0c0a0594u: goto P_0c0a0594;
case 0x0c0a0596u: goto P_0c0a0596;
case 0x0c0a0598u: goto P_0c0a0598;
case 0x0c0a059au: goto P_0c0a059a;
case 0x0c0a059cu: goto P_0c0a059c;
case 0x0c0a059eu: goto P_0c0a059e;
case 0x0c0a05a0u: goto P_0c0a05a0;
case 0x0c0a05a2u: goto P_0c0a05a2;
case 0x0c0a05a4u: goto P_0c0a05a4;
case 0x0c0a05a6u: goto P_0c0a05a6;
case 0x0c0a05a8u: goto P_0c0a05a8;
case 0x0c0a05aau: goto P_0c0a05aa;
case 0x0c0a05acu: goto P_0c0a05ac;
case 0x0c0a05aeu: goto P_0c0a05ae;
case 0x0c0a05b0u: goto P_0c0a05b0;
case 0x0c0a05b2u: goto P_0c0a05b2;
case 0x0c0a05b4u: goto P_0c0a05b4;
case 0x0c0a05b6u: goto P_0c0a05b6;
case 0x0c0a05b8u: goto P_0c0a05b8;
case 0x0c0a05bau: goto P_0c0a05ba;
case 0x0c0a05bcu: goto P_0c0a05bc;
case 0x0c0a05beu: goto P_0c0a05be;
case 0x0c0a05c0u: goto P_0c0a05c0;
case 0x0c0a05c2u: goto P_0c0a05c2;
case 0x0c0a05c4u: goto P_0c0a05c4;
case 0x0c0a05c6u: goto P_0c0a05c6;
case 0x0c0a05c8u: goto P_0c0a05c8;
case 0x0c0a05cau: goto P_0c0a05ca;
case 0x0c0a05ccu: goto P_0c0a05cc;
case 0x0c0a05fcu: goto P_0c0a05fc;
case 0x0c0a05feu: goto P_0c0a05fe;
case 0x0c0a0600u: goto P_0c0a0600;
case 0x0c0a0602u: goto P_0c0a0602;
case 0x0c0a0604u: goto P_0c0a0604;
case 0x0c0a0606u: goto P_0c0a0606;
case 0x0c0a0608u: goto P_0c0a0608;
case 0x0c0a060au: goto P_0c0a060a;
case 0x0c0a060cu: goto P_0c0a060c;
case 0x0c0a060eu: goto P_0c0a060e;
case 0x0c0a0610u: goto P_0c0a0610;
case 0x0c0a0612u: goto P_0c0a0612;
case 0x0c0a062cu: goto P_0c0a062c;
case 0x0c0a062eu: goto P_0c0a062e;
case 0x0c0a0630u: goto P_0c0a0630;
case 0x0c0a0632u: goto P_0c0a0632;
case 0x0c0a0634u: goto P_0c0a0634;
case 0x0c0a0636u: goto P_0c0a0636;
case 0x0c0a0638u: goto P_0c0a0638;
case 0x0c0a063au: goto P_0c0a063a;
case 0x0c0a063cu: goto P_0c0a063c;
case 0x0c0a063eu: goto P_0c0a063e;
case 0x0c0a0640u: goto P_0c0a0640;
case 0x0c0a0642u: goto P_0c0a0642;
case 0x0c0a0644u: goto P_0c0a0644;
case 0x0c0a0646u: goto P_0c0a0646;
case 0x0c0a0648u: goto P_0c0a0648;
case 0x0c0a064au: goto P_0c0a064a;
case 0x0c0a064cu: goto P_0c0a064c;
case 0x0c0a064eu: goto P_0c0a064e;
case 0x0c0a0650u: goto P_0c0a0650;
case 0x0c0a0652u: goto P_0c0a0652;
case 0x0c0a0654u: goto P_0c0a0654;
case 0x0c0a0656u: goto P_0c0a0656;
case 0x0c0a0658u: goto P_0c0a0658;
case 0x0c0a065au: goto P_0c0a065a;
case 0x0c0a065cu: goto P_0c0a065c;
case 0x0c0a065eu: goto P_0c0a065e;
case 0x0c0a0660u: goto P_0c0a0660;
case 0x0c0a0662u: goto P_0c0a0662;
case 0x0c0a0664u: goto P_0c0a0664;
case 0x0c0a0666u: goto P_0c0a0666;
case 0x0c0a0668u: goto P_0c0a0668;
case 0x0c0a066au: goto P_0c0a066a;
case 0x0c0a066cu: goto P_0c0a066c;
case 0x0c0a066eu: goto P_0c0a066e;
case 0x0c0a0670u: goto P_0c0a0670;
case 0x0c0a0672u: goto P_0c0a0672;
case 0x0c0a0674u: goto P_0c0a0674;
case 0x0c0a0676u: goto P_0c0a0676;
case 0x0c0a0678u: goto P_0c0a0678;
case 0x0c0a067au: goto P_0c0a067a;
case 0x0c0a067cu: goto P_0c0a067c;
case 0x0c0a067eu: goto P_0c0a067e;
case 0x0c0a0680u: goto P_0c0a0680;
case 0x0c0a0682u: goto P_0c0a0682;
case 0x0c0a0684u: goto P_0c0a0684;
case 0x0c0a0686u: goto P_0c0a0686;
case 0x0c0a0688u: goto P_0c0a0688;
case 0x0c0a068au: goto P_0c0a068a;
case 0x0c0a068cu: goto P_0c0a068c;
case 0x0c0a068eu: goto P_0c0a068e;
case 0x0c0a0690u: goto P_0c0a0690;
case 0x0c0a0692u: goto P_0c0a0692;
case 0x0c0a0694u: goto P_0c0a0694;
case 0x0c0a0696u: goto P_0c0a0696;
case 0x0c0a0698u: goto P_0c0a0698;
case 0x0c0a069au: goto P_0c0a069a;
case 0x0c0a069cu: goto P_0c0a069c;
case 0x0c0a069eu: goto P_0c0a069e;
case 0x0c0a06a0u: goto P_0c0a06a0;
case 0x0c0a06a2u: goto P_0c0a06a2;
case 0x0c0a06a4u: goto P_0c0a06a4;
case 0x0c0a06a6u: goto P_0c0a06a6;
case 0x0c0a06a8u: goto P_0c0a06a8;
case 0x0c0a06aau: goto P_0c0a06aa;
case 0x0c0a06acu: goto P_0c0a06ac;
case 0x0c0a06aeu: goto P_0c0a06ae;
case 0x0c0a06b0u: goto P_0c0a06b0;
case 0x0c0a06b2u: goto P_0c0a06b2;
case 0x0c0a06b4u: goto P_0c0a06b4;
case 0x0c0a06b6u: goto P_0c0a06b6;
case 0x0c0a06b8u: goto P_0c0a06b8;
case 0x0c0a06bau: goto P_0c0a06ba;
case 0x0c0a06bcu: goto P_0c0a06bc;
case 0x0c0a06beu: goto P_0c0a06be;
case 0x0c0a06c0u: goto P_0c0a06c0;
case 0x0c0a06c2u: goto P_0c0a06c2;
case 0x0c0a06c4u: goto P_0c0a06c4;
case 0x0c0a06c6u: goto P_0c0a06c6;
case 0x0c0a06c8u: goto P_0c0a06c8;
case 0x0c0a06cau: goto P_0c0a06ca;
case 0x0c0a06ccu: goto P_0c0a06cc;
case 0x0c0a06ceu: goto P_0c0a06ce;
case 0x0c0a06d0u: goto P_0c0a06d0;
case 0x0c0a06d2u: goto P_0c0a06d2;
case 0x0c0a06d4u: goto P_0c0a06d4;
case 0x0c0a06d6u: goto P_0c0a06d6;
case 0x0c0a06d8u: goto P_0c0a06d8;
case 0x0c0a06dau: goto P_0c0a06da;
case 0x0c0a06dcu: goto P_0c0a06dc;
case 0x0c0a06deu: goto P_0c0a06de;
case 0x0c0a06e0u: goto P_0c0a06e0;
case 0x0c0a06e2u: goto P_0c0a06e2;
case 0x0c0a06e4u: goto P_0c0a06e4;
case 0x0c0a06e6u: goto P_0c0a06e6;
case 0x0c0a06e8u: goto P_0c0a06e8;
case 0x0c0a06eau: goto P_0c0a06ea;
case 0x0c0a06ecu: goto P_0c0a06ec;
case 0x0c0a06eeu: goto P_0c0a06ee;
case 0x0c0a06f0u: goto P_0c0a06f0;
case 0x0c0a06f2u: goto P_0c0a06f2;
case 0x0c0a2994u: goto P_0c0a2994;
case 0x0c0a2996u: goto P_0c0a2996;
case 0x0c0a2998u: goto P_0c0a2998;
case 0x0c0a299au: goto P_0c0a299a;
case 0x0c0a299cu: goto P_0c0a299c;
case 0x0c0a299eu: goto P_0c0a299e;
case 0x0c0a29a0u: goto P_0c0a29a0;
case 0x0c0a29a2u: goto P_0c0a29a2;
case 0x0c0a29a4u: goto P_0c0a29a4;
case 0x0c0a29a6u: goto P_0c0a29a6;
case 0x0c0a29a8u: goto P_0c0a29a8;
case 0x0c0a29aau: goto P_0c0a29aa;
case 0x0c0a29acu: goto P_0c0a29ac;
case 0x0c0a29aeu: goto P_0c0a29ae;
case 0x0c0a29b0u: goto P_0c0a29b0;
case 0x0c0a29b2u: goto P_0c0a29b2;
case 0x0c0a29b4u: goto P_0c0a29b4;
case 0x0c0a29b6u: goto P_0c0a29b6;
case 0x0c0a29b8u: goto P_0c0a29b8;
case 0x0c0a29bau: goto P_0c0a29ba;
case 0x0c0a29bcu: goto P_0c0a29bc;
case 0x0c0a29beu: goto P_0c0a29be;
case 0x0c0a29c0u: goto P_0c0a29c0;
case 0x0c0a29c2u: goto P_0c0a29c2;
case 0x0c0a29c4u: goto P_0c0a29c4;
case 0x0c0a29c6u: goto P_0c0a29c6;
case 0x0c0a29c8u: goto P_0c0a29c8;
case 0x0c0a29cau: goto P_0c0a29ca;
case 0x0c0a29ccu: goto P_0c0a29cc;
case 0x0c0a29ceu: goto P_0c0a29ce;
case 0x0c0a29d0u: goto P_0c0a29d0;
case 0x0c0a29d2u: goto P_0c0a29d2;
case 0x0c0a29d4u: goto P_0c0a29d4;
case 0x0c0a29d6u: goto P_0c0a29d6;
case 0x0c0a29d8u: goto P_0c0a29d8;
case 0x0c0a29dau: goto P_0c0a29da;
case 0x0c0a29dcu: goto P_0c0a29dc;
case 0x0c0a29deu: goto P_0c0a29de;
case 0x0c0a29e0u: goto P_0c0a29e0;
case 0x0c0a29e2u: goto P_0c0a29e2;
case 0x0c0a29e4u: goto P_0c0a29e4;
case 0x0c0a29e6u: goto P_0c0a29e6;
case 0x0c0a29e8u: goto P_0c0a29e8;
case 0x0c0a29eau: goto P_0c0a29ea;
case 0x0c0a29ecu: goto P_0c0a29ec;
case 0x0c0a29eeu: goto P_0c0a29ee;
case 0x0c0a29f0u: goto P_0c0a29f0;
case 0x0c0a29f2u: goto P_0c0a29f2;
case 0x0c0a29f4u: goto P_0c0a29f4;
case 0x0c0a29f6u: goto P_0c0a29f6;
case 0x0c0a29f8u: goto P_0c0a29f8;
case 0x0c0a29fau: goto P_0c0a29fa;
case 0x0c0a29fcu: goto P_0c0a29fc;
case 0x0c0a29feu: goto P_0c0a29fe;
case 0x0c0a2a00u: goto P_0c0a2a00;
case 0x0c0a2a02u: goto P_0c0a2a02;
case 0x0c0a2a04u: goto P_0c0a2a04;
case 0x0c0a2a06u: goto P_0c0a2a06;
case 0x0c0a2a08u: goto P_0c0a2a08;
case 0x0c0a2a0au: goto P_0c0a2a0a;
case 0x0c0a2a0cu: goto P_0c0a2a0c;
case 0x0c0a2a0eu: goto P_0c0a2a0e;
case 0x0c0a2a10u: goto P_0c0a2a10;
case 0x0c0a2a12u: goto P_0c0a2a12;
case 0x0c0a2a14u: goto P_0c0a2a14;
case 0x0c0a2a16u: goto P_0c0a2a16;
case 0x0c0a2a18u: goto P_0c0a2a18;
case 0x0c0a2a1au: goto P_0c0a2a1a;
case 0x0c0a2a1cu: goto P_0c0a2a1c;
case 0x0c0a2a1eu: goto P_0c0a2a1e;
case 0x0c0a2a20u: goto P_0c0a2a20;
case 0x0c0a2a22u: goto P_0c0a2a22;
case 0x0c0a2a24u: goto P_0c0a2a24;
case 0x0c0a2a26u: goto P_0c0a2a26;
case 0x0c0a2a28u: goto P_0c0a2a28;
case 0x0c0a2a2au: goto P_0c0a2a2a;
case 0x0c0a2a2cu: goto P_0c0a2a2c;
case 0x0c0a2a2eu: goto P_0c0a2a2e;
case 0x0c0a2a30u: goto P_0c0a2a30;
case 0x0c0a2a32u: goto P_0c0a2a32;
case 0x0c0a2a34u: goto P_0c0a2a34;
case 0x0c0a2a36u: goto P_0c0a2a36;
case 0x0c0a2a38u: goto P_0c0a2a38;
case 0x0c0a2a3au: goto P_0c0a2a3a;
case 0x0c0a2a3cu: goto P_0c0a2a3c;
case 0x0c0a2a3eu: goto P_0c0a2a3e;
case 0x0c0a2a40u: goto P_0c0a2a40;
case 0x0c0a2a42u: goto P_0c0a2a42;
case 0x0c0a2a44u: goto P_0c0a2a44;
case 0x0c0a2a46u: goto P_0c0a2a46;
case 0x0c0a2a48u: goto P_0c0a2a48;
case 0x0c0a2a4au: goto P_0c0a2a4a;
case 0x0c0a2a4cu: goto P_0c0a2a4c;
case 0x0c0a2a4eu: goto P_0c0a2a4e;
case 0x0c0a2a50u: goto P_0c0a2a50;
case 0x0c0a2a52u: goto P_0c0a2a52;
case 0x0c0a2a54u: goto P_0c0a2a54;
case 0x0c0a2a56u: goto P_0c0a2a56;
case 0x0c0a2a58u: goto P_0c0a2a58;
case 0x0c0a2a5au: goto P_0c0a2a5a;
case 0x0c0a2a5cu: goto P_0c0a2a5c;
case 0x0c0a2a5eu: goto P_0c0a2a5e;
case 0x0c0a2a60u: goto P_0c0a2a60;
case 0x0c0a2a62u: goto P_0c0a2a62;
case 0x0c0a2a64u: goto P_0c0a2a64;
case 0x0c0a2a66u: goto P_0c0a2a66;
case 0x0c0a2a68u: goto P_0c0a2a68;
case 0x0c0a2a6au: goto P_0c0a2a6a;
case 0x0c0a2a6cu: goto P_0c0a2a6c;
case 0x0c0a2a6eu: goto P_0c0a2a6e;
case 0x0c0a2a70u: goto P_0c0a2a70;
case 0x0c0a2a72u: goto P_0c0a2a72;
case 0x0c0a2c48u: goto P_0c0a2c48;
case 0x0c0a2c4au: goto P_0c0a2c4a;
case 0x0c0a2c4cu: goto P_0c0a2c4c;
case 0x0c0a2c4eu: goto P_0c0a2c4e;
case 0x0c0a2c50u: goto P_0c0a2c50;
case 0x0c0a2c52u: goto P_0c0a2c52;
case 0x0c0a2c54u: goto P_0c0a2c54;
case 0x0c0a2c56u: goto P_0c0a2c56;
case 0x0c0a2c58u: goto P_0c0a2c58;
case 0x0c0a2c5au: goto P_0c0a2c5a;
case 0x0c0a2c5cu: goto P_0c0a2c5c;
case 0x0c0a2c5eu: goto P_0c0a2c5e;
case 0x0c0a2c60u: goto P_0c0a2c60;
case 0x0c0a2c62u: goto P_0c0a2c62;
case 0x0c0a2c64u: goto P_0c0a2c64;
case 0x0c0a2c66u: goto P_0c0a2c66;
case 0x0c0a2c68u: goto P_0c0a2c68;
case 0x0c0a2c6au: goto P_0c0a2c6a;
case 0x0c0a2c6cu: goto P_0c0a2c6c;
case 0x0c0a2c6eu: goto P_0c0a2c6e;
case 0x0c0a2c70u: goto P_0c0a2c70;
case 0x0c0a2c72u: goto P_0c0a2c72;
case 0x0c0a2c74u: goto P_0c0a2c74;
case 0x0c0a2c76u: goto P_0c0a2c76;
case 0x0c0a2c78u: goto P_0c0a2c78;
case 0x0c0a2c7au: goto P_0c0a2c7a;
case 0x0c0a2c7cu: goto P_0c0a2c7c;
case 0x0c0a2c7eu: goto P_0c0a2c7e;
case 0x0c0a2c80u: goto P_0c0a2c80;
case 0x0c0a2c82u: goto P_0c0a2c82;
case 0x0c0a2c84u: goto P_0c0a2c84;
case 0x0c0a2c86u: goto P_0c0a2c86;
case 0x0c0a2c88u: goto P_0c0a2c88;
case 0x0c0a2c8au: goto P_0c0a2c8a;
case 0x0c0a2c8cu: goto P_0c0a2c8c;
case 0x0c0a2c8eu: goto P_0c0a2c8e;
case 0x0c0a2c90u: goto P_0c0a2c90;
case 0x0c0a2c92u: goto P_0c0a2c92;
case 0x0c0a2c94u: goto P_0c0a2c94;
case 0x0c0a2c96u: goto P_0c0a2c96;
case 0x0c0a2c98u: goto P_0c0a2c98;
case 0x0c0a2c9au: goto P_0c0a2c9a;
case 0x0c0a2c9cu: goto P_0c0a2c9c;
case 0x0c0a2cb8u: goto P_0c0a2cb8;
case 0x0c0a2cbau: goto P_0c0a2cba;
case 0x0c0a2cbcu: goto P_0c0a2cbc;
case 0x0c0a2cbeu: goto P_0c0a2cbe;
case 0x0c0a2cc0u: goto P_0c0a2cc0;
case 0x0c0a2cc2u: goto P_0c0a2cc2;
case 0x0c0a2cc4u: goto P_0c0a2cc4;
case 0x0c0a2cc6u: goto P_0c0a2cc6;
case 0x0c0a2cc8u: goto P_0c0a2cc8;
case 0x0c0a2ccau: goto P_0c0a2cca;
case 0x0c0a2cccu: goto P_0c0a2ccc;
case 0x0c0a2cceu: goto P_0c0a2cce;
case 0x0c0a2cd0u: goto P_0c0a2cd0;
case 0x0c0a2cd2u: goto P_0c0a2cd2;
case 0x0c0a2cd4u: goto P_0c0a2cd4;
case 0x0c0a2cd6u: goto P_0c0a2cd6;
case 0x0c0a2cd8u: goto P_0c0a2cd8;
case 0x0c0a2cdau: goto P_0c0a2cda;
case 0x0c0a2cdcu: goto P_0c0a2cdc;
case 0x0c0a2cdeu: goto P_0c0a2cde;
case 0x0c0a2ce0u: goto P_0c0a2ce0;
case 0x0c0a2ce2u: goto P_0c0a2ce2;
case 0x0c0a2ce4u: goto P_0c0a2ce4;
case 0x0c0a2ce6u: goto P_0c0a2ce6;
case 0x0c0a2ce8u: goto P_0c0a2ce8;
case 0x0c0a2ceau: goto P_0c0a2cea;
case 0x0c0a2cecu: goto P_0c0a2cec;
case 0x0c0a2ceeu: goto P_0c0a2cee;
case 0x0c0a2cf0u: goto P_0c0a2cf0;
case 0x0c0a2cf2u: goto P_0c0a2cf2;
case 0x0c0a2cf4u: goto P_0c0a2cf4;
case 0x0c0a2cf6u: goto P_0c0a2cf6;
case 0x0c0a2cf8u: goto P_0c0a2cf8;
case 0x0c0a2cfau: goto P_0c0a2cfa;
case 0x0c0a2cfcu: goto P_0c0a2cfc;
case 0x0c0a2cfeu: goto P_0c0a2cfe;
case 0x0c0a2d00u: goto P_0c0a2d00;
case 0x0c0a2d02u: goto P_0c0a2d02;
case 0x0c0a2d04u: goto P_0c0a2d04;
case 0x0c0a2d06u: goto P_0c0a2d06;
case 0x0c0a2d08u: goto P_0c0a2d08;
case 0x0c0a2d0au: goto P_0c0a2d0a;
case 0x0c0a2d0cu: goto P_0c0a2d0c;
case 0x0c0a2d0eu: goto P_0c0a2d0e;
case 0x0c0a2d10u: goto P_0c0a2d10;
case 0x0c0a2d12u: goto P_0c0a2d12;
case 0x0c0a2d14u: goto P_0c0a2d14;
case 0x0c0a2d16u: goto P_0c0a2d16;
case 0x0c0a2d18u: goto P_0c0a2d18;
case 0x0c0a2d1au: goto P_0c0a2d1a;
case 0x0c0a2d1cu: goto P_0c0a2d1c;
case 0x0c0a2d1eu: goto P_0c0a2d1e;
case 0x0c0a2d20u: goto P_0c0a2d20;
case 0x0c0a2d22u: goto P_0c0a2d22;
case 0x0c0a2d24u: goto P_0c0a2d24;
case 0x0c0a2d26u: goto P_0c0a2d26;
case 0x0c0a2d28u: goto P_0c0a2d28;
case 0x0c0a2d2au: goto P_0c0a2d2a;
case 0x0c0a2d2cu: goto P_0c0a2d2c;
case 0x0c0a2d2eu: goto P_0c0a2d2e;
case 0x0c0a2d30u: goto P_0c0a2d30;
case 0x0c0a2d32u: goto P_0c0a2d32;
case 0x0c0a2d34u: goto P_0c0a2d34;
case 0x0c0a2d36u: goto P_0c0a2d36;
case 0x0c0a2d38u: goto P_0c0a2d38;
case 0x0c0a2d3au: goto P_0c0a2d3a;
case 0x0c0a2d3cu: goto P_0c0a2d3c;
case 0x0c0a2d3eu: goto P_0c0a2d3e;
case 0x0c0a2d40u: goto P_0c0a2d40;
case 0x0c0a2d42u: goto P_0c0a2d42;
case 0x0c0a2d44u: goto P_0c0a2d44;
case 0x0c0a2d46u: goto P_0c0a2d46;
case 0x0c0a7602u: goto P_0c0a7602;
case 0x0c0a7604u: goto P_0c0a7604;
case 0x0c0a7606u: goto P_0c0a7606;
case 0x0c0a7608u: goto P_0c0a7608;
case 0x0c0a760au: goto P_0c0a760a;
case 0x0c0a760cu: goto P_0c0a760c;
case 0x0c0a760eu: goto P_0c0a760e;
case 0x0c0a7610u: goto P_0c0a7610;
case 0x0c0a7612u: goto P_0c0a7612;
case 0x0c0a7614u: goto P_0c0a7614;
case 0x0c0a7616u: goto P_0c0a7616;
case 0x0c0a7618u: goto P_0c0a7618;
case 0x0c0a761au: goto P_0c0a761a;
case 0x0c0a761cu: goto P_0c0a761c;
case 0x0c0a761eu: goto P_0c0a761e;
case 0x0c0a7620u: goto P_0c0a7620;
case 0x0c0a7622u: goto P_0c0a7622;
case 0x0c0a7624u: goto P_0c0a7624;
case 0x0c0a7626u: goto P_0c0a7626;
case 0x0c0a7628u: goto P_0c0a7628;
case 0x0c0a762au: goto P_0c0a762a;
case 0x0c0a762cu: goto P_0c0a762c;
case 0x0c0a762eu: goto P_0c0a762e;
case 0x0c0a7630u: goto P_0c0a7630;
case 0x0c0a7632u: goto P_0c0a7632;
case 0x0c0a7634u: goto P_0c0a7634;
case 0x0c0a7636u: goto P_0c0a7636;
case 0x0c0a7638u: goto P_0c0a7638;
case 0x0c0a763au: goto P_0c0a763a;
case 0x0c0a763cu: goto P_0c0a763c;
case 0x0c0a763eu: goto P_0c0a763e;
case 0x0c0a7640u: goto P_0c0a7640;
case 0x0c0a7642u: goto P_0c0a7642;
case 0x0c0a7644u: goto P_0c0a7644;
case 0x0c0a7646u: goto P_0c0a7646;
case 0x0c0a7648u: goto P_0c0a7648;
case 0x0c0a764au: goto P_0c0a764a;
case 0x0c0a764cu: goto P_0c0a764c;
case 0x0c0a764eu: goto P_0c0a764e;
case 0x0c0a7650u: goto P_0c0a7650;
case 0x0c0a7652u: goto P_0c0a7652;
case 0x0c0a7654u: goto P_0c0a7654;
case 0x0c0a7656u: goto P_0c0a7656;
case 0x0c0a7658u: goto P_0c0a7658;
case 0x0c0a765au: goto P_0c0a765a;
case 0x0c0a765cu: goto P_0c0a765c;
case 0x0c0a765eu: goto P_0c0a765e;
case 0x0c0a7660u: goto P_0c0a7660;
case 0x0c0a7a1cu: goto P_0c0a7a1c;
case 0x0c0a7a1eu: goto P_0c0a7a1e;
case 0x0c0a7a20u: goto P_0c0a7a20;
case 0x0c0a7a22u: goto P_0c0a7a22;
case 0x0c0a7a24u: goto P_0c0a7a24;
case 0x0c0a7a26u: goto P_0c0a7a26;
case 0x0c0a7a28u: goto P_0c0a7a28;
case 0x0c0a7a2au: goto P_0c0a7a2a;
case 0x0c0a7a2cu: goto P_0c0a7a2c;
case 0x0c0a7a2eu: goto P_0c0a7a2e;
case 0x0c0a7a30u: goto P_0c0a7a30;
case 0x0c0a7a32u: goto P_0c0a7a32;
case 0x0c0a7a34u: goto P_0c0a7a34;
case 0x0c0a7a36u: goto P_0c0a7a36;
case 0x0c0a7a38u: goto P_0c0a7a38;
case 0x0c0a7a3au: goto P_0c0a7a3a;
case 0x0c0a7a3cu: goto P_0c0a7a3c;
case 0x0c0a7a3eu: goto P_0c0a7a3e;
case 0x0c0a7a40u: goto P_0c0a7a40;
case 0x0c0a7a42u: goto P_0c0a7a42;
case 0x0c0a7a44u: goto P_0c0a7a44;
case 0x0c0a7a46u: goto P_0c0a7a46;
case 0x0c0a7a48u: goto P_0c0a7a48;
case 0x0c0a7a4au: goto P_0c0a7a4a;
case 0x0c0a7a4cu: goto P_0c0a7a4c;
case 0x0c0a7a4eu: goto P_0c0a7a4e;
case 0x0c0a7a50u: goto P_0c0a7a50;
case 0x0c0a7a52u: goto P_0c0a7a52;
case 0x0c0a7a54u: goto P_0c0a7a54;
case 0x0c0a7a56u: goto P_0c0a7a56;
case 0x0c0a7a58u: goto P_0c0a7a58;
case 0x0c0a7a5au: goto P_0c0a7a5a;
case 0x0c0a7a5cu: goto P_0c0a7a5c;
case 0x0c0a7a5eu: goto P_0c0a7a5e;
case 0x0c0a7a60u: goto P_0c0a7a60;
case 0x0c0a7a62u: goto P_0c0a7a62;
case 0x0c0a7a64u: goto P_0c0a7a64;
case 0x0c0a7a66u: goto P_0c0a7a66;
case 0x0c0a7a68u: goto P_0c0a7a68;
case 0x0c0a7a6au: goto P_0c0a7a6a;
case 0x0c0a7a6cu: goto P_0c0a7a6c;
case 0x0c0a7a6eu: goto P_0c0a7a6e;
case 0x0c0a7a70u: goto P_0c0a7a70;
case 0x0c0a7a72u: goto P_0c0a7a72;
case 0x0c0a7a74u: goto P_0c0a7a74;
case 0x0c0a7a76u: goto P_0c0a7a76;
case 0x0c0a7a78u: goto P_0c0a7a78;
case 0x0c0a7a7au: goto P_0c0a7a7a;
case 0x0c0a7a7cu: goto P_0c0a7a7c;
case 0x0c0a7a7eu: goto P_0c0a7a7e;
case 0x0c0a7a80u: goto P_0c0a7a80;
case 0x0c0a7a82u: goto P_0c0a7a82;
case 0x0c0a7a84u: goto P_0c0a7a84;
case 0x0c0a7a86u: goto P_0c0a7a86;
case 0x0c0a7a88u: goto P_0c0a7a88;
case 0x0c0a7a8au: goto P_0c0a7a8a;
case 0x0c0a7a8cu: goto P_0c0a7a8c;
case 0x0c0a7a8eu: goto P_0c0a7a8e;
case 0x0c0a7a90u: goto P_0c0a7a90;
case 0x0c0a7a92u: goto P_0c0a7a92;
case 0x0c0a7a94u: goto P_0c0a7a94;
case 0x0c0a7a96u: goto P_0c0a7a96;
case 0x0c0a7a98u: goto P_0c0a7a98;
case 0x0c0a7a9au: goto P_0c0a7a9a;
case 0x0c0a7a9cu: goto P_0c0a7a9c;
case 0x0c0a7a9eu: goto P_0c0a7a9e;
case 0x0c0a7aa0u: goto P_0c0a7aa0;
case 0x0c0a7aa2u: goto P_0c0a7aa2;
case 0x0c0a7ae0u: goto P_0c0a7ae0;
case 0x0c0a7ae2u: goto P_0c0a7ae2;
case 0x0c0a7ae4u: goto P_0c0a7ae4;
case 0x0c0a7ae6u: goto P_0c0a7ae6;
case 0x0c0a7ae8u: goto P_0c0a7ae8;
case 0x0c0a7aeau: goto P_0c0a7aea;
case 0x0c0a7aecu: goto P_0c0a7aec;
case 0x0c0a7aeeu: goto P_0c0a7aee;
case 0x0c0a7af0u: goto P_0c0a7af0;
case 0x0c0a7af2u: goto P_0c0a7af2;
case 0x0c0a7af4u: goto P_0c0a7af4;
case 0x0c0a7af6u: goto P_0c0a7af6;
case 0x0c0a7af8u: goto P_0c0a7af8;
case 0x0c0a7afau: goto P_0c0a7afa;
case 0x0c0a7afcu: goto P_0c0a7afc;
case 0x0c0a7afeu: goto P_0c0a7afe;
case 0x0c0a7b00u: goto P_0c0a7b00;
case 0x0c0a7b02u: goto P_0c0a7b02;
case 0x0c0a7b04u: goto P_0c0a7b04;
case 0x0c0a7b06u: goto P_0c0a7b06;
case 0x0c0a7b08u: goto P_0c0a7b08;
case 0x0c0a7b0au: goto P_0c0a7b0a;
case 0x0c0a7b0cu: goto P_0c0a7b0c;
case 0x0c0a7b0eu: goto P_0c0a7b0e;
case 0x0c0a7b10u: goto P_0c0a7b10;
case 0x0c0a7b12u: goto P_0c0a7b12;
case 0x0c0a7b14u: goto P_0c0a7b14;
case 0x0c0a7b16u: goto P_0c0a7b16;
case 0x0c0a7b18u: goto P_0c0a7b18;
case 0x0c0a7f68u: goto P_0c0a7f68;
case 0x0c0a7f6au: goto P_0c0a7f6a;
case 0x0c0a7f6cu: goto P_0c0a7f6c;
case 0x0c0a7f6eu: goto P_0c0a7f6e;
case 0x0c0a7f70u: goto P_0c0a7f70;
case 0x0c0a7f72u: goto P_0c0a7f72;
case 0x0c0a7f74u: goto P_0c0a7f74;
case 0x0c0a7f76u: goto P_0c0a7f76;
case 0x0c0a7f78u: goto P_0c0a7f78;
case 0x0c0a7f7au: goto P_0c0a7f7a;
case 0x0c0a7f7cu: goto P_0c0a7f7c;
case 0x0c0a7f7eu: goto P_0c0a7f7e;
case 0x0c0a7f80u: goto P_0c0a7f80;
case 0x0c0a7f82u: goto P_0c0a7f82;
case 0x0c0a7f84u: goto P_0c0a7f84;
case 0x0c0a7f86u: goto P_0c0a7f86;
case 0x0c0a7f88u: goto P_0c0a7f88;
case 0x0c0a7f8au: goto P_0c0a7f8a;
case 0x0c0a7f8cu: goto P_0c0a7f8c;
case 0x0c0a7f8eu: goto P_0c0a7f8e;
case 0x0c0a7f90u: goto P_0c0a7f90;
case 0x0c0a7f92u: goto P_0c0a7f92;
case 0x0c0a7f94u: goto P_0c0a7f94;
case 0x0c0a7f96u: goto P_0c0a7f96;
case 0x0c0a7f98u: goto P_0c0a7f98;
case 0x0c0a7f9au: goto P_0c0a7f9a;
case 0x0c0a7f9cu: goto P_0c0a7f9c;
case 0x0c0a7f9eu: goto P_0c0a7f9e;
case 0x0c0a7fa0u: goto P_0c0a7fa0;
case 0x0c0a7fa2u: goto P_0c0a7fa2;
case 0x0c0a7fa4u: goto P_0c0a7fa4;
case 0x0c0a7fc0u: goto P_0c0a7fc0;
case 0x0c0a7fc2u: goto P_0c0a7fc2;
case 0x0c0a7fc4u: goto P_0c0a7fc4;
case 0x0c0a7fc6u: goto P_0c0a7fc6;
case 0x0c0a7fc8u: goto P_0c0a7fc8;
case 0x0c0a7fcau: goto P_0c0a7fca;
case 0x0c0a7fccu: goto P_0c0a7fcc;
case 0x0c0a7fceu: goto P_0c0a7fce;
case 0x0c0a7fd0u: goto P_0c0a7fd0;
case 0x0c0a7fd2u: goto P_0c0a7fd2;
case 0x0c0a7fd4u: goto P_0c0a7fd4;
case 0x0c0a7fd6u: goto P_0c0a7fd6;
case 0x0c0a7fd8u: goto P_0c0a7fd8;
case 0x0c0a7fdau: goto P_0c0a7fda;
case 0x0c0a7fdcu: goto P_0c0a7fdc;
case 0x0c0a7fdeu: goto P_0c0a7fde;
case 0x0c0a7fe0u: goto P_0c0a7fe0;
case 0x0c0a7fe2u: goto P_0c0a7fe2;
case 0x0c0a7fe4u: goto P_0c0a7fe4;
case 0x0c0a7fe6u: goto P_0c0a7fe6;
case 0x0c0a7fe8u: goto P_0c0a7fe8;
case 0x0c0a7feau: goto P_0c0a7fea;
case 0x0c0a7fecu: goto P_0c0a7fec;
case 0x0c0a7feeu: goto P_0c0a7fee;
case 0x0c0a7ff0u: goto P_0c0a7ff0;
case 0x0c0a7ff2u: goto P_0c0a7ff2;
case 0x0c0a7ff4u: goto P_0c0a7ff4;
case 0x0c0a7ff6u: goto P_0c0a7ff6;
case 0x0c0a7ff8u: goto P_0c0a7ff8;
case 0x0c0a7ffau: goto P_0c0a7ffa;
case 0x0c0a7ffcu: goto P_0c0a7ffc;
case 0x0c0a7ffeu: goto P_0c0a7ffe;
case 0x0c0a8000u: goto P_0c0a8000;
case 0x0c0a8002u: goto P_0c0a8002;
case 0x0c0a8004u: goto P_0c0a8004;
case 0x0c0a8006u: goto P_0c0a8006;
case 0x0c0a8008u: goto P_0c0a8008;
case 0x0c0a800au: goto P_0c0a800a;
case 0x0c0a800cu: goto P_0c0a800c;
case 0x0c0a800eu: goto P_0c0a800e;
case 0x0c0a8010u: goto P_0c0a8010;
case 0x0c0a8012u: goto P_0c0a8012;
case 0x0c0a8014u: goto P_0c0a8014;
case 0x0c0a8016u: goto P_0c0a8016;
case 0x0c0a8018u: goto P_0c0a8018;
case 0x0c0a801au: goto P_0c0a801a;
case 0x0c0a801cu: goto P_0c0a801c;
case 0x0c0a801eu: goto P_0c0a801e;
case 0x0c0a8020u: goto P_0c0a8020;
case 0x0c0a8022u: goto P_0c0a8022;
case 0x0c0a8024u: goto P_0c0a8024;
case 0x0c0a8026u: goto P_0c0a8026;
case 0x0c0a8028u: goto P_0c0a8028;
case 0x0c0a802au: goto P_0c0a802a;
case 0x0c0a802cu: goto P_0c0a802c;
case 0x0c0a802eu: goto P_0c0a802e;
case 0x0c0a8030u: goto P_0c0a8030;
case 0x0c0a8032u: goto P_0c0a8032;
case 0x0c0a8034u: goto P_0c0a8034;
case 0x0c0a8036u: goto P_0c0a8036;
case 0x0c0a8038u: goto P_0c0a8038;
case 0x0c0a803au: goto P_0c0a803a;
case 0x0c0aa638u: goto P_0c0aa638;
case 0x0c0aa63au: goto P_0c0aa63a;
case 0x0c0aa63cu: goto P_0c0aa63c;
case 0x0c0aa63eu: goto P_0c0aa63e;
case 0x0c0aa640u: goto P_0c0aa640;
case 0x0c0aa642u: goto P_0c0aa642;
case 0x0c0aa644u: goto P_0c0aa644;
case 0x0c0aa646u: goto P_0c0aa646;
case 0x0c0aa648u: goto P_0c0aa648;
case 0x0c0aa64au: goto P_0c0aa64a;
case 0x0c0aa64cu: goto P_0c0aa64c;
case 0x0c0aa64eu: goto P_0c0aa64e;
case 0x0c0aa650u: goto P_0c0aa650;
case 0x0c0aa652u: goto P_0c0aa652;
case 0x0c0aa654u: goto P_0c0aa654;
case 0x0c0aa656u: goto P_0c0aa656;
case 0x0c0aa658u: goto P_0c0aa658;
case 0x0c0aa65au: goto P_0c0aa65a;
case 0x0c0aa65cu: goto P_0c0aa65c;
case 0x0c0aa65eu: goto P_0c0aa65e;
case 0x0c0aa660u: goto P_0c0aa660;
case 0x0c0aa662u: goto P_0c0aa662;
case 0x0c0aa664u: goto P_0c0aa664;
case 0x0c0aa666u: goto P_0c0aa666;
case 0x0c0aa668u: goto P_0c0aa668;
case 0x0c0aa66au: goto P_0c0aa66a;
case 0x0c0aa66cu: goto P_0c0aa66c;
case 0x0c0aa66eu: goto P_0c0aa66e;
case 0x0c0aa670u: goto P_0c0aa670;
case 0x0c0aa672u: goto P_0c0aa672;
case 0x0c0aa674u: goto P_0c0aa674;
case 0x0c0aa676u: goto P_0c0aa676;
case 0x0c0aa678u: goto P_0c0aa678;
case 0x0c0aa67au: goto P_0c0aa67a;
case 0x0c0aa67cu: goto P_0c0aa67c;
case 0x0c0aa67eu: goto P_0c0aa67e;
case 0x0c0aa680u: goto P_0c0aa680;
case 0x0c0aa682u: goto P_0c0aa682;
case 0x0c0aa684u: goto P_0c0aa684;
case 0x0c0aa686u: goto P_0c0aa686;
case 0x0c0aa688u: goto P_0c0aa688;
case 0x0c0aa68au: goto P_0c0aa68a;
case 0x0c0aa68cu: goto P_0c0aa68c;
case 0x0c0aa68eu: goto P_0c0aa68e;
case 0x0c0aa690u: goto P_0c0aa690;
case 0x0c0aa692u: goto P_0c0aa692;
case 0x0c0aa694u: goto P_0c0aa694;
case 0x0c0aa696u: goto P_0c0aa696;
case 0x0c0aa698u: goto P_0c0aa698;
case 0x0c0aa69au: goto P_0c0aa69a;
case 0x0c0aa69cu: goto P_0c0aa69c;
case 0x0c0aa69eu: goto P_0c0aa69e;
case 0x0c0aa6a0u: goto P_0c0aa6a0;
case 0x0c0aa6a2u: goto P_0c0aa6a2;
case 0x0c0aa6a4u: goto P_0c0aa6a4;
case 0x0c0aa6a6u: goto P_0c0aa6a6;
case 0x0c0aa6a8u: goto P_0c0aa6a8;
case 0x0c0aa6aau: goto P_0c0aa6aa;
case 0x0c0aa6acu: goto P_0c0aa6ac;
case 0x0c0aa6aeu: goto P_0c0aa6ae;
case 0x0c0aa6b0u: goto P_0c0aa6b0;
case 0x0c0aa6b2u: goto P_0c0aa6b2;
case 0x0c0aa6b4u: goto P_0c0aa6b4;
case 0x0c0aa6b6u: goto P_0c0aa6b6;
case 0x0c0aa6b8u: goto P_0c0aa6b8;
case 0x0c0aa6bau: goto P_0c0aa6ba;
case 0x0c0aa6bcu: goto P_0c0aa6bc;
case 0x0c0aa6beu: goto P_0c0aa6be;
case 0x0c0aa6c0u: goto P_0c0aa6c0;
case 0x0c0aa6c2u: goto P_0c0aa6c2;
case 0x0c0aa6c4u: goto P_0c0aa6c4;
case 0x0c0aa6c6u: goto P_0c0aa6c6;
case 0x0c0aa6c8u: goto P_0c0aa6c8;
case 0x0c0aa6cau: goto P_0c0aa6ca;
case 0x0c0aa6ccu: goto P_0c0aa6cc;
case 0x0c0aa6ceu: goto P_0c0aa6ce;
case 0x0c0aa704u: goto P_0c0aa704;
case 0x0c0aa706u: goto P_0c0aa706;
case 0x0c0aa708u: goto P_0c0aa708;
case 0x0c0aa70au: goto P_0c0aa70a;
case 0x0c0aa70cu: goto P_0c0aa70c;
case 0x0c0aa70eu: goto P_0c0aa70e;
case 0x0c0aa710u: goto P_0c0aa710;
case 0x0c0aa712u: goto P_0c0aa712;
case 0x0c0aa714u: goto P_0c0aa714;
case 0x0c0aa716u: goto P_0c0aa716;
case 0x0c0aa718u: goto P_0c0aa718;
case 0x0c0aa71au: goto P_0c0aa71a;
case 0x0c0aa71cu: goto P_0c0aa71c;
case 0x0c0aa71eu: goto P_0c0aa71e;
case 0x0c0aa720u: goto P_0c0aa720;
case 0x0c0aa722u: goto P_0c0aa722;
case 0x0c0aa724u: goto P_0c0aa724;
case 0x0c0aa726u: goto P_0c0aa726;
case 0x0c0aa728u: goto P_0c0aa728;
case 0x0c0aa72au: goto P_0c0aa72a;
case 0x0c0aa72cu: goto P_0c0aa72c;
case 0x0c0aa7a2u: goto P_0c0aa7a2;
case 0x0c0aa7a4u: goto P_0c0aa7a4;
case 0x0c0aa7a6u: goto P_0c0aa7a6;
case 0x0c0aa7a8u: goto P_0c0aa7a8;
case 0x0c0aa7aau: goto P_0c0aa7aa;
case 0x0c0aa7acu: goto P_0c0aa7ac;
case 0x0c0aa7aeu: goto P_0c0aa7ae;
case 0x0c0aa7b0u: goto P_0c0aa7b0;
case 0x0c0aa7b2u: goto P_0c0aa7b2;
case 0x0c0aa7b4u: goto P_0c0aa7b4;
case 0x0c0aa7b6u: goto P_0c0aa7b6;
case 0x0c0aa7b8u: goto P_0c0aa7b8;
case 0x0c0aa7bau: goto P_0c0aa7ba;
case 0x0c0aa7bcu: goto P_0c0aa7bc;
case 0x0c0aa7beu: goto P_0c0aa7be;
case 0x0c0aa7c0u: goto P_0c0aa7c0;
case 0x0c0aa7c2u: goto P_0c0aa7c2;
case 0x0c0aa7c4u: goto P_0c0aa7c4;
case 0x0c0aa7c6u: goto P_0c0aa7c6;
case 0x0c0aa7c8u: goto P_0c0aa7c8;
case 0x0c0aa7cau: goto P_0c0aa7ca;
case 0x0c0aa7ccu: goto P_0c0aa7cc;
case 0x0c0aa7ceu: goto P_0c0aa7ce;
case 0x0c0aa7d0u: goto P_0c0aa7d0;
case 0x0c0aa7d2u: goto P_0c0aa7d2;
case 0x0c0aa7d4u: goto P_0c0aa7d4;
case 0x0c0aa7d6u: goto P_0c0aa7d6;
case 0x0c0aa7d8u: goto P_0c0aa7d8;
case 0x0c0aa7dau: goto P_0c0aa7da;
case 0x0c0aa7dcu: goto P_0c0aa7dc;
case 0x0c0aa7deu: goto P_0c0aa7de;
case 0x0c0aa7e0u: goto P_0c0aa7e0;
case 0x0c0aa7e2u: goto P_0c0aa7e2;
case 0x0c0aa7e4u: goto P_0c0aa7e4;
case 0x0c0aa7e6u: goto P_0c0aa7e6;
case 0x0c0aa7e8u: goto P_0c0aa7e8;
case 0x0c0aa7eau: goto P_0c0aa7ea;
case 0x0c0aa9f0u: goto P_0c0aa9f0;
case 0x0c0aa9f2u: goto P_0c0aa9f2;
case 0x0c0aa9f4u: goto P_0c0aa9f4;
case 0x0c0aa9f6u: goto P_0c0aa9f6;
case 0x0c0aa9f8u: goto P_0c0aa9f8;
case 0x0c0aa9fau: goto P_0c0aa9fa;
case 0x0c0aa9fcu: goto P_0c0aa9fc;
case 0x0c0aa9feu: goto P_0c0aa9fe;
case 0x0c0aaa00u: goto P_0c0aaa00;
case 0x0c0aaa02u: goto P_0c0aaa02;
case 0x0c0aaa04u: goto P_0c0aaa04;
case 0x0c0aaa06u: goto P_0c0aaa06;
case 0x0c0aaa08u: goto P_0c0aaa08;
case 0x0c0aaa0au: goto P_0c0aaa0a;
case 0x0c0aaa0cu: goto P_0c0aaa0c;
case 0x0c0aaa0eu: goto P_0c0aaa0e;
case 0x0c0aaa10u: goto P_0c0aaa10;
case 0x0c0aaa12u: goto P_0c0aaa12;
case 0x0c0aaa14u: goto P_0c0aaa14;
case 0x0c0aaa16u: goto P_0c0aaa16;
case 0x0c0aaa40u: goto P_0c0aaa40;
case 0x0c0aaa42u: goto P_0c0aaa42;
case 0x0c0aaa44u: goto P_0c0aaa44;
case 0x0c0aaa46u: goto P_0c0aaa46;
case 0x0c0aaa48u: goto P_0c0aaa48;
case 0x0c0aaa4au: goto P_0c0aaa4a;
case 0x0c0aaa4cu: goto P_0c0aaa4c;
case 0x0c0aaa4eu: goto P_0c0aaa4e;
case 0x0c0aaa50u: goto P_0c0aaa50;
case 0x0c0aaa52u: goto P_0c0aaa52;
case 0x0c0aaa54u: goto P_0c0aaa54;
case 0x0c0aaa56u: goto P_0c0aaa56;
case 0x0c0aaa58u: goto P_0c0aaa58;
case 0x0c0aaa5au: goto P_0c0aaa5a;
case 0x0c0aaa5cu: goto P_0c0aaa5c;
case 0x0c0aaa5eu: goto P_0c0aaa5e;
case 0x0c0aaa60u: goto P_0c0aaa60;
case 0x0c0aaa62u: goto P_0c0aaa62;
case 0x0c0aaa64u: goto P_0c0aaa64;
case 0x0c0aaa66u: goto P_0c0aaa66;
case 0x0c0aaa68u: goto P_0c0aaa68;
case 0x0c0aaa6au: goto P_0c0aaa6a;
case 0x0c0aaa6cu: goto P_0c0aaa6c;
case 0x0c0aaa6eu: goto P_0c0aaa6e;
case 0x0c0aaa70u: goto P_0c0aaa70;
case 0x0c0aaa72u: goto P_0c0aaa72;
case 0x0c0aaa74u: goto P_0c0aaa74;
case 0x0c0aaa76u: goto P_0c0aaa76;
case 0x0c0aaa78u: goto P_0c0aaa78;
case 0x0c0aaa7au: goto P_0c0aaa7a;
case 0x0c0aaa7cu: goto P_0c0aaa7c;
case 0x0c0aaa7eu: goto P_0c0aaa7e;
case 0x0c0aaa80u: goto P_0c0aaa80;
case 0x0c0aaa82u: goto P_0c0aaa82;
case 0x0c0aaa84u: goto P_0c0aaa84;
case 0x0c0aaa86u: goto P_0c0aaa86;
case 0x0c0aaa88u: goto P_0c0aaa88;
case 0x0c0aaa8au: goto P_0c0aaa8a;
case 0x0c0aaa8cu: goto P_0c0aaa8c;
case 0x0c0aaa8eu: goto P_0c0aaa8e;
case 0x0c0aaa90u: goto P_0c0aaa90;
case 0x0c0aaa92u: goto P_0c0aaa92;
case 0x0c0aaa94u: goto P_0c0aaa94;
case 0x0c0aaa96u: goto P_0c0aaa96;
case 0x0c0aaa98u: goto P_0c0aaa98;
case 0x0c0aaa9au: goto P_0c0aaa9a;
case 0x0c0aaa9cu: goto P_0c0aaa9c;
case 0x0c0aaa9eu: goto P_0c0aaa9e;
case 0x0c0aaaa0u: goto P_0c0aaaa0;
case 0x0c0aaaa2u: goto P_0c0aaaa2;
case 0x0c0aaaa4u: goto P_0c0aaaa4;
case 0x0c0aaaa6u: goto P_0c0aaaa6;
case 0x0c0aaaa8u: goto P_0c0aaaa8;
case 0x0c0aaaaau: goto P_0c0aaaaa;
case 0x0c0aaaacu: goto P_0c0aaaac;
case 0x0c0aaaaeu: goto P_0c0aaaae;
case 0x0c0aaab0u: goto P_0c0aaab0;
case 0x0c0aaab2u: goto P_0c0aaab2;
case 0x0c0aaab4u: goto P_0c0aaab4;
case 0x0c0aaab6u: goto P_0c0aaab6;
case 0x0c0aaab8u: goto P_0c0aaab8;
case 0x0c0aaabau: goto P_0c0aaaba;
case 0x0c0aaabcu: goto P_0c0aaabc;
case 0x0c0aaabeu: goto P_0c0aaabe;
case 0x0c0aaac0u: goto P_0c0aaac0;
case 0x0c0aaac2u: goto P_0c0aaac2;
case 0x0c0aaac4u: goto P_0c0aaac4;
case 0x0c0aaac6u: goto P_0c0aaac6;
case 0x0c0aaac8u: goto P_0c0aaac8;
case 0x0c0aaacau: goto P_0c0aaaca;
case 0x0c0aaaccu: goto P_0c0aaacc;
case 0x0c0aaaceu: goto P_0c0aaace;
case 0x0c0aaad0u: goto P_0c0aaad0;
case 0x0c0aaad2u: goto P_0c0aaad2;
case 0x0c0aaad4u: goto P_0c0aaad4;
case 0x0c0aaad6u: goto P_0c0aaad6;
case 0x0c0aaad8u: goto P_0c0aaad8;
case 0x0c0aaadau: goto P_0c0aaada;
case 0x0c0aaadcu: goto P_0c0aaadc;
case 0x0c0aaadeu: goto P_0c0aaade;
case 0x0c0aaae0u: goto P_0c0aaae0;
case 0x0c0aaae2u: goto P_0c0aaae2;
case 0x0c0aaae4u: goto P_0c0aaae4;
case 0x0c0aaae6u: goto P_0c0aaae6;
case 0x0c0aaae8u: goto P_0c0aaae8;
case 0x0c0aaaeau: goto P_0c0aaaea;
case 0x0c0aaaecu: goto P_0c0aaaec;
case 0x0c0aadaeu: goto P_0c0aadae;
case 0x0c0aadb0u: goto P_0c0aadb0;
case 0x0c0aadb2u: goto P_0c0aadb2;
case 0x0c0aadb4u: goto P_0c0aadb4;
case 0x0c0aadb6u: goto P_0c0aadb6;
case 0x0c0aadb8u: goto P_0c0aadb8;
case 0x0c0aadbau: goto P_0c0aadba;
case 0x0c0aadbcu: goto P_0c0aadbc;
case 0x0c0aadbeu: goto P_0c0aadbe;
case 0x0c0aadc0u: goto P_0c0aadc0;
case 0x0c0aadc2u: goto P_0c0aadc2;
case 0x0c0aadc4u: goto P_0c0aadc4;
case 0x0c0aadc6u: goto P_0c0aadc6;
case 0x0c0aadc8u: goto P_0c0aadc8;
case 0x0c0aadcau: goto P_0c0aadca;
case 0x0c0aadccu: goto P_0c0aadcc;
case 0x0c0aadceu: goto P_0c0aadce;
case 0x0c0aadd0u: goto P_0c0aadd0;
case 0x0c0aadd2u: goto P_0c0aadd2;
case 0x0c0aadd4u: goto P_0c0aadd4;
case 0x0c0aadd6u: goto P_0c0aadd6;
case 0x0c0aadd8u: goto P_0c0aadd8;
case 0x0c0aaddau: goto P_0c0aadda;
case 0x0c0aaddcu: goto P_0c0aaddc;
case 0x0c0aaddeu: goto P_0c0aadde;
case 0x0c0aade0u: goto P_0c0aade0;
case 0x0c0aade2u: goto P_0c0aade2;
case 0x0c0aade4u: goto P_0c0aade4;
case 0x0c0aade6u: goto P_0c0aade6;
case 0x0c0aade8u: goto P_0c0aade8;
case 0x0c0aadeau: goto P_0c0aadea;
case 0x0c0aadecu: goto P_0c0aadec;
case 0x0c0aadeeu: goto P_0c0aadee;
case 0x0c0aadf0u: goto P_0c0aadf0;
case 0x0c0aadf2u: goto P_0c0aadf2;
case 0x0c0aadf4u: goto P_0c0aadf4;
case 0x0c0aadf6u: goto P_0c0aadf6;
case 0x0c0aadf8u: goto P_0c0aadf8;
case 0x0c0aadfau: goto P_0c0aadfa;
case 0x0c0aadfcu: goto P_0c0aadfc;
case 0x0c0aadfeu: goto P_0c0aadfe;
case 0x0c0aae00u: goto P_0c0aae00;
case 0x0c0aae02u: goto P_0c0aae02;
case 0x0c0aae04u: goto P_0c0aae04;
case 0x0c0aae06u: goto P_0c0aae06;
case 0x0c0aae08u: goto P_0c0aae08;
case 0x0c0aae0au: goto P_0c0aae0a;
case 0x0c0aae0cu: goto P_0c0aae0c;
case 0x0c0aae0eu: goto P_0c0aae0e;
case 0x0c0aae10u: goto P_0c0aae10;
case 0x0c0aae12u: goto P_0c0aae12;
case 0x0c0aae14u: goto P_0c0aae14;
case 0x0c0aae16u: goto P_0c0aae16;
case 0x0c0aae18u: goto P_0c0aae18;
case 0x0c0aae1au: goto P_0c0aae1a;
case 0x0c0aae1cu: goto P_0c0aae1c;
case 0x0c0aae1eu: goto P_0c0aae1e;
case 0x0c0aae20u: goto P_0c0aae20;
case 0x0c0aae22u: goto P_0c0aae22;
case 0x0c0aae24u: goto P_0c0aae24;
case 0x0c0aae26u: goto P_0c0aae26;
case 0x0c0aae28u: goto P_0c0aae28;
case 0x0c0aae2au: goto P_0c0aae2a;
case 0x0c0aae2cu: goto P_0c0aae2c;
case 0x0c0aae2eu: goto P_0c0aae2e;
case 0x0c0aae30u: goto P_0c0aae30;
case 0x0c0aae32u: goto P_0c0aae32;
case 0x0c0aae34u: goto P_0c0aae34;
case 0x0c0aae36u: goto P_0c0aae36;
case 0x0c0aae38u: goto P_0c0aae38;
case 0x0c0aae3au: goto P_0c0aae3a;
case 0x0c0aae74u: goto P_0c0aae74;
case 0x0c0aae76u: goto P_0c0aae76;
case 0x0c0aae78u: goto P_0c0aae78;
case 0x0c0aae7au: goto P_0c0aae7a;
case 0x0c0aae7cu: goto P_0c0aae7c;
case 0x0c0aae7eu: goto P_0c0aae7e;
case 0x0c0aae80u: goto P_0c0aae80;
case 0x0c0aae82u: goto P_0c0aae82;
case 0x0c0aae84u: goto P_0c0aae84;
case 0x0c0aae86u: goto P_0c0aae86;
case 0x0c0aae88u: goto P_0c0aae88;
case 0x0c0aae8au: goto P_0c0aae8a;
case 0x0c0aae8cu: goto P_0c0aae8c;
case 0x0c0aae8eu: goto P_0c0aae8e;
case 0x0c0aae90u: goto P_0c0aae90;
case 0x0c0aae92u: goto P_0c0aae92;
case 0x0c0aae94u: goto P_0c0aae94;
case 0x0c0aae96u: goto P_0c0aae96;
case 0x0c0aae98u: goto P_0c0aae98;
case 0x0c0aae9au: goto P_0c0aae9a;
case 0x0c0aae9cu: goto P_0c0aae9c;
case 0x0c0aae9eu: goto P_0c0aae9e;
case 0x0c0aaea0u: goto P_0c0aaea0;
case 0x0c0aaea2u: goto P_0c0aaea2;
case 0x0c0aaea4u: goto P_0c0aaea4;
case 0x0c0aaea6u: goto P_0c0aaea6;
case 0x0c0aaea8u: goto P_0c0aaea8;
case 0x0c0aaeaau: goto P_0c0aaeaa;
case 0x0c0aaeacu: goto P_0c0aaeac;
case 0x0c0aaeaeu: goto P_0c0aaeae;
case 0x0c0aaeb0u: goto P_0c0aaeb0;
case 0x0c0aaeb2u: goto P_0c0aaeb2;
case 0x0c0aaeb4u: goto P_0c0aaeb4;
case 0x0c0aaeb6u: goto P_0c0aaeb6;
case 0x0c0aaeb8u: goto P_0c0aaeb8;
case 0x0c0aaebeu: goto P_0c0aaebe;
case 0x0c0aaec0u: goto P_0c0aaec0;
case 0x0c0aaec2u: goto P_0c0aaec2;
case 0x0c0aaec4u: goto P_0c0aaec4;
case 0x0c0aaec6u: goto P_0c0aaec6;
case 0x0c0aaec8u: goto P_0c0aaec8;
case 0x0c0aaecau: goto P_0c0aaeca;
case 0x0c0aaeccu: goto P_0c0aaecc;
case 0x0c0aaeceu: goto P_0c0aaece;
case 0x0c0aaed0u: goto P_0c0aaed0;
case 0x0c0aaed2u: goto P_0c0aaed2;
case 0x0c0aaed4u: goto P_0c0aaed4;
case 0x0c0aaed6u: goto P_0c0aaed6;
case 0x0c0aaed8u: goto P_0c0aaed8;
case 0x0c0aaedau: goto P_0c0aaeda;
case 0x0c0aaedcu: goto P_0c0aaedc;
case 0x0c0aaedeu: goto P_0c0aaede;
case 0x0c0aaee0u: goto P_0c0aaee0;
case 0x0c0aaee2u: goto P_0c0aaee2;
case 0x0c0aaee4u: goto P_0c0aaee4;
case 0x0c0aaee6u: goto P_0c0aaee6;
case 0x0c0aaee8u: goto P_0c0aaee8;
case 0x0c0aaeeau: goto P_0c0aaeea;
case 0x0c0aaeecu: goto P_0c0aaeec;
case 0x0c0aaeeeu: goto P_0c0aaeee;
case 0x0c0aaef0u: goto P_0c0aaef0;
case 0x0c0aaef2u: goto P_0c0aaef2;
case 0x0c0aaef4u: goto P_0c0aaef4;
case 0x0c0aaef6u: goto P_0c0aaef6;
case 0x0c0aaef8u: goto P_0c0aaef8;
case 0x0c0aaefau: goto P_0c0aaefa;
case 0x0c0aaefcu: goto P_0c0aaefc;
case 0x0c0aaefeu: goto P_0c0aaefe;
case 0x0c0aaf00u: goto P_0c0aaf00;
case 0x0c0aaf02u: goto P_0c0aaf02;
case 0x0c0aaf04u: goto P_0c0aaf04;
case 0x0c0aaf06u: goto P_0c0aaf06;
case 0x0c0aaf08u: goto P_0c0aaf08;
case 0x0c0aaf0au: goto P_0c0aaf0a;
case 0x0c0aaf0cu: goto P_0c0aaf0c;
case 0x0c0aaf0eu: goto P_0c0aaf0e;
case 0x0c0aaf10u: goto P_0c0aaf10;
case 0x0c0aaf12u: goto P_0c0aaf12;
case 0x0c0aaf14u: goto P_0c0aaf14;
case 0x0c0aaf16u: goto P_0c0aaf16;
case 0x0c0aaf18u: goto P_0c0aaf18;
case 0x0c0aaf1au: goto P_0c0aaf1a;
case 0x0c0aaf1cu: goto P_0c0aaf1c;
case 0x0c0aaf1eu: goto P_0c0aaf1e;
case 0x0c0aaf20u: goto P_0c0aaf20;
case 0x0c0aaf22u: goto P_0c0aaf22;
case 0x0c0aaf24u: goto P_0c0aaf24;
case 0x0c0aaf26u: goto P_0c0aaf26;
case 0x0c0aaf28u: goto P_0c0aaf28;
case 0x0c0aaf2au: goto P_0c0aaf2a;
case 0x0c0aaf2cu: goto P_0c0aaf2c;
case 0x0c0aaf2eu: goto P_0c0aaf2e;
case 0x0c0aaf30u: goto P_0c0aaf30;
case 0x0c0aaf32u: goto P_0c0aaf32;
case 0x0c0aaf34u: goto P_0c0aaf34;
case 0x0c0aaf36u: goto P_0c0aaf36;
case 0x0c0aaf38u: goto P_0c0aaf38;
case 0x0c0aaf3au: goto P_0c0aaf3a;
case 0x0c0aaf3cu: goto P_0c0aaf3c;
case 0x0c0aaf3eu: goto P_0c0aaf3e;
case 0x0c0aaf40u: goto P_0c0aaf40;
case 0x0c0aaf42u: goto P_0c0aaf42;
case 0x0c0aaf44u: goto P_0c0aaf44;
case 0x0c0aaf46u: goto P_0c0aaf46;
case 0x0c0aaf48u: goto P_0c0aaf48;
case 0x0c0aaf4au: goto P_0c0aaf4a;
case 0x0c0aaf4cu: goto P_0c0aaf4c;
case 0x0c0aaf4eu: goto P_0c0aaf4e;
case 0x0c0aaf50u: goto P_0c0aaf50;
case 0x0c0aaf52u: goto P_0c0aaf52;
case 0x0c0aaf54u: goto P_0c0aaf54;
case 0x0c0aaf56u: goto P_0c0aaf56;
case 0x0c0aaf58u: goto P_0c0aaf58;
case 0x0c0aaf5au: goto P_0c0aaf5a;
case 0x0c0aaf5cu: goto P_0c0aaf5c;
case 0x0c0aaf5eu: goto P_0c0aaf5e;
case 0x0c0aaf60u: goto P_0c0aaf60;
case 0x0c0aaf62u: goto P_0c0aaf62;
case 0x0c0aaf64u: goto P_0c0aaf64;
case 0x0c0aaf66u: goto P_0c0aaf66;
case 0x0c0aaf68u: goto P_0c0aaf68;
case 0x0c0aaf6au: goto P_0c0aaf6a;
case 0x0c0aaf6cu: goto P_0c0aaf6c;
case 0x0c0aaf6eu: goto P_0c0aaf6e;
case 0x0c0aaf70u: goto P_0c0aaf70;
case 0x0c0aafb0u: goto P_0c0aafb0;
case 0x0c0aafb2u: goto P_0c0aafb2;
case 0x0c0aafb4u: goto P_0c0aafb4;
case 0x0c0aafb6u: goto P_0c0aafb6;
case 0x0c0aafb8u: goto P_0c0aafb8;
case 0x0c0aafbau: goto P_0c0aafba;
case 0x0c0aafbcu: goto P_0c0aafbc;
case 0x0c0aafbeu: goto P_0c0aafbe;
case 0x0c0aafc0u: goto P_0c0aafc0;
case 0x0c0aafc2u: goto P_0c0aafc2;
case 0x0c0aafc4u: goto P_0c0aafc4;
case 0x0c0aafc6u: goto P_0c0aafc6;
case 0x0c0aafc8u: goto P_0c0aafc8;
case 0x0c0aafcau: goto P_0c0aafca;
case 0x0c0aafccu: goto P_0c0aafcc;
case 0x0c0aafceu: goto P_0c0aafce;
case 0x0c0aafd0u: goto P_0c0aafd0;
case 0x0c0aafd2u: goto P_0c0aafd2;
case 0x0c0aafd4u: goto P_0c0aafd4;
case 0x0c0aafd6u: goto P_0c0aafd6;
case 0x0c0aafd8u: goto P_0c0aafd8;
case 0x0c0aafdau: goto P_0c0aafda;
case 0x0c0aafdcu: goto P_0c0aafdc;
case 0x0c0aafdeu: goto P_0c0aafde;
case 0x0c0aafe0u: goto P_0c0aafe0;
case 0x0c0aafe2u: goto P_0c0aafe2;
case 0x0c0aafe4u: goto P_0c0aafe4;
case 0x0c0aafe6u: goto P_0c0aafe6;
case 0x0c0aafe8u: goto P_0c0aafe8;
case 0x0c0aafeau: goto P_0c0aafea;
case 0x0c0aafecu: goto P_0c0aafec;
case 0x0c0aafeeu: goto P_0c0aafee;
case 0x0c0aaff0u: goto P_0c0aaff0;
case 0x0c0aaff2u: goto P_0c0aaff2;
case 0x0c0aaff4u: goto P_0c0aaff4;
case 0x0c0aaff6u: goto P_0c0aaff6;
case 0x0c0aaff8u: goto P_0c0aaff8;
case 0x0c0aaffau: goto P_0c0aaffa;
case 0x0c0aaffcu: goto P_0c0aaffc;
case 0x0c0aaffeu: goto P_0c0aaffe;
case 0x0c0ab000u: goto P_0c0ab000;
case 0x0c0ab002u: goto P_0c0ab002;
case 0x0c0ab004u: goto P_0c0ab004;
case 0x0c0ab006u: goto P_0c0ab006;
case 0x0c0ab008u: goto P_0c0ab008;
case 0x0c0ab00au: goto P_0c0ab00a;
case 0x0c0ab00cu: goto P_0c0ab00c;
case 0x0c0ab00eu: goto P_0c0ab00e;
case 0x0c0ab010u: goto P_0c0ab010;
case 0x0c0ab012u: goto P_0c0ab012;
case 0x0c0ab014u: goto P_0c0ab014;
case 0x0c0ab016u: goto P_0c0ab016;
case 0x0c0ab018u: goto P_0c0ab018;
case 0x0c0ab01au: goto P_0c0ab01a;
case 0x0c0ab01cu: goto P_0c0ab01c;
case 0x0c0ab01eu: goto P_0c0ab01e;
case 0x0c0ab020u: goto P_0c0ab020;
case 0x0c0ab022u: goto P_0c0ab022;
case 0x0c0ab024u: goto P_0c0ab024;
case 0x0c0ab026u: goto P_0c0ab026;
case 0x0c0ab028u: goto P_0c0ab028;
case 0x0c0ab02au: goto P_0c0ab02a;
case 0x0c0ab02cu: goto P_0c0ab02c;
case 0x0c0ab02eu: goto P_0c0ab02e;
case 0x0c0ab030u: goto P_0c0ab030;
case 0x0c0ab032u: goto P_0c0ab032;
case 0x0c0ab034u: goto P_0c0ab034;
case 0x0c0ab036u: goto P_0c0ab036;
case 0x0c0ab038u: goto P_0c0ab038;
case 0x0c0ab03au: goto P_0c0ab03a;
case 0x0c0ab03cu: goto P_0c0ab03c;
case 0x0c0ab03eu: goto P_0c0ab03e;
case 0x0c0ab040u: goto P_0c0ab040;
case 0x0c0ab042u: goto P_0c0ab042;
case 0x0c0ab044u: goto P_0c0ab044;
case 0x0c0ab046u: goto P_0c0ab046;
case 0x0c0ab048u: goto P_0c0ab048;
case 0x0c0ab04au: goto P_0c0ab04a;
case 0x0c0ab04cu: goto P_0c0ab04c;
case 0x0c0ab04eu: goto P_0c0ab04e;
case 0x0c0ab050u: goto P_0c0ab050;
case 0x0c0ab052u: goto P_0c0ab052;
case 0x0c0ab054u: goto P_0c0ab054;
case 0x0c0ab056u: goto P_0c0ab056;
case 0x0c0ab058u: goto P_0c0ab058;
case 0x0c0ab05au: goto P_0c0ab05a;
case 0x0c0ab05cu: goto P_0c0ab05c;
case 0x0c0ab05eu: goto P_0c0ab05e;
case 0x0c0ab060u: goto P_0c0ab060;
case 0x0c0ab062u: goto P_0c0ab062;
case 0x0c0ab064u: goto P_0c0ab064;
case 0x0c0ab066u: goto P_0c0ab066;
case 0x0c0ab068u: goto P_0c0ab068;
case 0x0c0ab06au: goto P_0c0ab06a;
case 0x0c0ab06cu: goto P_0c0ab06c;
case 0x0c0ab06eu: goto P_0c0ab06e;
case 0x0c0ab070u: goto P_0c0ab070;
case 0x0c0ab072u: goto P_0c0ab072;
case 0x0c0ab074u: goto P_0c0ab074;
case 0x0c0ab076u: goto P_0c0ab076;
case 0x0c0ab078u: goto P_0c0ab078;
case 0x0c0ab07au: goto P_0c0ab07a;
case 0x0c0ab07cu: goto P_0c0ab07c;
case 0x0c0ab07eu: goto P_0c0ab07e;
case 0x0c0ab080u: goto P_0c0ab080;
case 0x0c0ab082u: goto P_0c0ab082;
case 0x0c0ab084u: goto P_0c0ab084;
case 0x0c0ab086u: goto P_0c0ab086;
case 0x0c0ab088u: goto P_0c0ab088;
case 0x0c0ab08au: goto P_0c0ab08a;
case 0x0c0ab08cu: goto P_0c0ab08c;
case 0x0c0ab08eu: goto P_0c0ab08e;
case 0x0c0ab090u: goto P_0c0ab090;
case 0x0c0ab092u: goto P_0c0ab092;
case 0x0c0ab094u: goto P_0c0ab094;
case 0x0c0ab096u: goto P_0c0ab096;
case 0x0c0ab098u: goto P_0c0ab098;
case 0x0c0ab09au: goto P_0c0ab09a;
case 0x0c0ab09cu: goto P_0c0ab09c;
case 0x0c0ab09eu: goto P_0c0ab09e;
case 0x0c0ab0a0u: goto P_0c0ab0a0;
case 0x0c0ab0a2u: goto P_0c0ab0a2;
case 0x0c0ab0a4u: goto P_0c0ab0a4;
case 0x0c0ab0a6u: goto P_0c0ab0a6;
case 0x0c0ab0a8u: goto P_0c0ab0a8;
case 0x0c0ab0aau: goto P_0c0ab0aa;
case 0x0c0ab0acu: goto P_0c0ab0ac;
case 0x0c0ab0aeu: goto P_0c0ab0ae;
case 0x0c0ab0b0u: goto P_0c0ab0b0;
case 0x0c0ab0b2u: goto P_0c0ab0b2;
case 0x0c0ab0b4u: goto P_0c0ab0b4;
case 0x0c0ab0b6u: goto P_0c0ab0b6;
case 0x0c0ab0b8u: goto P_0c0ab0b8;
case 0x0c0ab0bau: goto P_0c0ab0ba;
case 0x0c0ab0bcu: goto P_0c0ab0bc;
case 0x0c0ab0e4u: goto P_0c0ab0e4;
case 0x0c0ab0e6u: goto P_0c0ab0e6;
case 0x0c0ab0e8u: goto P_0c0ab0e8;
case 0x0c0ab0eau: goto P_0c0ab0ea;
case 0x0c0ab0ecu: goto P_0c0ab0ec;
case 0x0c0ab0eeu: goto P_0c0ab0ee;
case 0x0c0ab0f0u: goto P_0c0ab0f0;
case 0x0c0ab0f2u: goto P_0c0ab0f2;
case 0x0c0ab0f4u: goto P_0c0ab0f4;
case 0x0c0ab0f6u: goto P_0c0ab0f6;
case 0x0c0ab0f8u: goto P_0c0ab0f8;
case 0x0c0ab0fau: goto P_0c0ab0fa;
case 0x0c0ab0fcu: goto P_0c0ab0fc;
case 0x0c0ab0feu: goto P_0c0ab0fe;
case 0x0c0ab100u: goto P_0c0ab100;
case 0x0c0ab102u: goto P_0c0ab102;
case 0x0c0ab104u: goto P_0c0ab104;
case 0x0c0ab106u: goto P_0c0ab106;
case 0x0c0ab108u: goto P_0c0ab108;
case 0x0c0ab10au: goto P_0c0ab10a;
case 0x0c0ab10cu: goto P_0c0ab10c;
case 0x0c0ab10eu: goto P_0c0ab10e;
case 0x0c0ab110u: goto P_0c0ab110;
case 0x0c0ab112u: goto P_0c0ab112;
case 0x0c0ab114u: goto P_0c0ab114;
case 0x0c0ab116u: goto P_0c0ab116;
case 0x0c0ab118u: goto P_0c0ab118;
case 0x0c0ab11au: goto P_0c0ab11a;
case 0x0c0ab11cu: goto P_0c0ab11c;
case 0x0c0ab11eu: goto P_0c0ab11e;
case 0x0c0ab120u: goto P_0c0ab120;
case 0x0c0ab122u: goto P_0c0ab122;
case 0x0c0ab124u: goto P_0c0ab124;
case 0x0c0ab126u: goto P_0c0ab126;
case 0x0c0ab128u: goto P_0c0ab128;
case 0x0c0ab12au: goto P_0c0ab12a;
case 0x0c0ab12cu: goto P_0c0ab12c;
case 0x0c0ab12eu: goto P_0c0ab12e;
case 0x0c0ab130u: goto P_0c0ab130;
case 0x0c0ab132u: goto P_0c0ab132;
case 0x0c0ab134u: goto P_0c0ab134;
case 0x0c0ab136u: goto P_0c0ab136;
case 0x0c0ab138u: goto P_0c0ab138;
case 0x0c0ab13au: goto P_0c0ab13a;
case 0x0c0ab13cu: goto P_0c0ab13c;
case 0x0c0ab13eu: goto P_0c0ab13e;
case 0x0c0ab140u: goto P_0c0ab140;
case 0x0c0ab142u: goto P_0c0ab142;
case 0x0c0ab144u: goto P_0c0ab144;
case 0x0c0ab146u: goto P_0c0ab146;
case 0x0c0ab148u: goto P_0c0ab148;
case 0x0c0ab14au: goto P_0c0ab14a;
case 0x0c0ab14cu: goto P_0c0ab14c;
case 0x0c0ab14eu: goto P_0c0ab14e;
case 0x0c0ab150u: goto P_0c0ab150;
case 0x0c0ab152u: goto P_0c0ab152;
case 0x0c0ab154u: goto P_0c0ab154;
case 0x0c0ab156u: goto P_0c0ab156;
case 0x0c0ab158u: goto P_0c0ab158;
case 0x0c0ab15au: goto P_0c0ab15a;
case 0x0c0ab15cu: goto P_0c0ab15c;
case 0x0c0ab15eu: goto P_0c0ab15e;
case 0x0c0ab160u: goto P_0c0ab160;
case 0x0c0ab162u: goto P_0c0ab162;
case 0x0c0ab164u: goto P_0c0ab164;
case 0x0c0ab166u: goto P_0c0ab166;
case 0x0c0ab168u: goto P_0c0ab168;
case 0x0c0ab35au: goto P_0c0ab35a;
case 0x0c0ab35cu: goto P_0c0ab35c;
case 0x0c0ab35eu: goto P_0c0ab35e;
case 0x0c0ab360u: goto P_0c0ab360;
case 0x0c0ab362u: goto P_0c0ab362;
case 0x0c0ab364u: goto P_0c0ab364;
case 0x0c0ab366u: goto P_0c0ab366;
case 0x0c0ab368u: goto P_0c0ab368;
case 0x0c0ab36au: goto P_0c0ab36a;
case 0x0c0ab36cu: goto P_0c0ab36c;
case 0x0c0ab36eu: goto P_0c0ab36e;
case 0x0c0ab370u: goto P_0c0ab370;
case 0x0c0ab372u: goto P_0c0ab372;
case 0x0c0ab374u: goto P_0c0ab374;
case 0x0c0ab376u: goto P_0c0ab376;
case 0x0c0ab378u: goto P_0c0ab378;
case 0x0c0ab37au: goto P_0c0ab37a;
case 0x0c0ab37cu: goto P_0c0ab37c;
case 0x0c0ab37eu: goto P_0c0ab37e;
case 0x0c0ab380u: goto P_0c0ab380;
case 0x0c0ab382u: goto P_0c0ab382;
case 0x0c0ab384u: goto P_0c0ab384;
case 0x0c0ab386u: goto P_0c0ab386;
case 0x0c0ab388u: goto P_0c0ab388;
case 0x0c0ab38au: goto P_0c0ab38a;
case 0x0c0ab38cu: goto P_0c0ab38c;
case 0x0c0ab38eu: goto P_0c0ab38e;
case 0x0c0ab390u: goto P_0c0ab390;
case 0x0c0ab392u: goto P_0c0ab392;
case 0x0c0ab394u: goto P_0c0ab394;
case 0x0c0ab396u: goto P_0c0ab396;
case 0x0c0ab398u: goto P_0c0ab398;
case 0x0c0ab39au: goto P_0c0ab39a;
case 0x0c0ab39cu: goto P_0c0ab39c;
case 0x0c0ab39eu: goto P_0c0ab39e;
case 0x0c0ab3a0u: goto P_0c0ab3a0;
case 0x0c0ab3a2u: goto P_0c0ab3a2;
case 0x0c0ab3a4u: goto P_0c0ab3a4;
case 0x0c0ab3a6u: goto P_0c0ab3a6;
case 0x0c0ab3a8u: goto P_0c0ab3a8;
case 0x0c0ab3aau: goto P_0c0ab3aa;
case 0x0c0ab3acu: goto P_0c0ab3ac;
case 0x0c0ab3aeu: goto P_0c0ab3ae;
case 0x0c0ab3b0u: goto P_0c0ab3b0;
case 0x0c0ab3b2u: goto P_0c0ab3b2;
case 0x0c0ab3b4u: goto P_0c0ab3b4;
case 0x0c0ab3b6u: goto P_0c0ab3b6;
case 0x0c0ab3b8u: goto P_0c0ab3b8;
case 0x0c0ab3bau: goto P_0c0ab3ba;
case 0x0c0ab3bcu: goto P_0c0ab3bc;
case 0x0c0ab3beu: goto P_0c0ab3be;
case 0x0c0ab3c0u: goto P_0c0ab3c0;
case 0x0c0ab3c2u: goto P_0c0ab3c2;
case 0x0c0ab3c4u: goto P_0c0ab3c4;
case 0x0c0ab3c6u: goto P_0c0ab3c6;
case 0x0c0ab3c8u: goto P_0c0ab3c8;
case 0x0c0ab3cau: goto P_0c0ab3ca;
case 0x0c0ab3ccu: goto P_0c0ab3cc;
case 0x0c0ab3ceu: goto P_0c0ab3ce;
case 0x0c0ab3d0u: goto P_0c0ab3d0;
case 0x0c0ab3d2u: goto P_0c0ab3d2;
case 0x0c0ab3d4u: goto P_0c0ab3d4;
case 0x0c0ab3d6u: goto P_0c0ab3d6;
case 0x0c0ab3d8u: goto P_0c0ab3d8;
case 0x0c0ab3dau: goto P_0c0ab3da;
case 0x0c0ab3dcu: goto P_0c0ab3dc;
case 0x0c0ab3deu: goto P_0c0ab3de;
case 0x0c0ab3e0u: goto P_0c0ab3e0;
case 0x0c0ab3e2u: goto P_0c0ab3e2;
case 0x0c0ab3e4u: goto P_0c0ab3e4;
case 0x0c0ab3e6u: goto P_0c0ab3e6;
case 0x0c0ab3e8u: goto P_0c0ab3e8;
case 0x0c0ab3eau: goto P_0c0ab3ea;
case 0x0c0ab3ecu: goto P_0c0ab3ec;
case 0x0c0ab3eeu: goto P_0c0ab3ee;
case 0x0c0ab3f0u: goto P_0c0ab3f0;
case 0x0c0ab3f2u: goto P_0c0ab3f2;
case 0x0c0ab3f4u: goto P_0c0ab3f4;
case 0x0c0ab3f6u: goto P_0c0ab3f6;
case 0x0c0ab3f8u: goto P_0c0ab3f8;
case 0x0c0ab3fau: goto P_0c0ab3fa;
case 0x0c0ab3fcu: goto P_0c0ab3fc;
case 0x0c0ab3feu: goto P_0c0ab3fe;
case 0x0c0ab400u: goto P_0c0ab400;
case 0x0c0ab402u: goto P_0c0ab402;
case 0x0c0ab404u: goto P_0c0ab404;
case 0x0c0ab406u: goto P_0c0ab406;
case 0x0c0ab408u: goto P_0c0ab408;
case 0x0c0ab40au: goto P_0c0ab40a;
case 0x0c0ab40cu: goto P_0c0ab40c;
case 0x0c0ab40eu: goto P_0c0ab40e;
case 0x0c0ab410u: goto P_0c0ab410;
case 0x0c0ab412u: goto P_0c0ab412;
case 0x0c0ab414u: goto P_0c0ab414;
case 0x0c0ab416u: goto P_0c0ab416;
case 0x0c0ab418u: goto P_0c0ab418;
case 0x0c0ab41au: goto P_0c0ab41a;
case 0x0c0ab41cu: goto P_0c0ab41c;
case 0x0c0ab41eu: goto P_0c0ab41e;
case 0x0c0ab420u: goto P_0c0ab420;
case 0x0c0ab422u: goto P_0c0ab422;
case 0x0c0ab424u: goto P_0c0ab424;
case 0x0c0ab426u: goto P_0c0ab426;
case 0x0c0ab428u: goto P_0c0ab428;
case 0x0c0ab42au: goto P_0c0ab42a;
case 0x0c0ab42cu: goto P_0c0ab42c;
case 0x0c0ab42eu: goto P_0c0ab42e;
case 0x0c0ab430u: goto P_0c0ab430;
case 0x0c0ab432u: goto P_0c0ab432;
case 0x0c0ab434u: goto P_0c0ab434;
case 0x0c0ab436u: goto P_0c0ab436;
case 0x0c0ab438u: goto P_0c0ab438;
case 0x0c0ab43au: goto P_0c0ab43a;
case 0x0c0ab43cu: goto P_0c0ab43c;
case 0x0c0ab43eu: goto P_0c0ab43e;
case 0x0c0ab440u: goto P_0c0ab440;
case 0x0c0ab442u: goto P_0c0ab442;
case 0x0c0ab444u: goto P_0c0ab444;
case 0x0c0ab446u: goto P_0c0ab446;
case 0x0c0ab448u: goto P_0c0ab448;
case 0x0c0ab44au: goto P_0c0ab44a;
case 0x0c0ab44cu: goto P_0c0ab44c;
case 0x0c0ab44eu: goto P_0c0ab44e;
case 0x0c0ab450u: goto P_0c0ab450;
case 0x0c0ab452u: goto P_0c0ab452;
case 0x0c0ab454u: goto P_0c0ab454;
case 0x0c0ab456u: goto P_0c0ab456;
case 0x0c0ab458u: goto P_0c0ab458;
case 0x0c0ab45au: goto P_0c0ab45a;
case 0x0c0ab45cu: goto P_0c0ab45c;
case 0x0c0ab45eu: goto P_0c0ab45e;
case 0x0c0ab460u: goto P_0c0ab460;
case 0x0c0ab462u: goto P_0c0ab462;
case 0x0c0ab464u: goto P_0c0ab464;
case 0x0c0ab466u: goto P_0c0ab466;
case 0x0c0ab468u: goto P_0c0ab468;
case 0x0c0ab46au: goto P_0c0ab46a;
case 0x0c0ab46cu: goto P_0c0ab46c;
case 0x0c0ab46eu: goto P_0c0ab46e;
case 0x0c0ab470u: goto P_0c0ab470;
case 0x0c0ab472u: goto P_0c0ab472;
case 0x0c0ab474u: goto P_0c0ab474;
case 0x0c0ab4b4u: goto P_0c0ab4b4;
case 0x0c0ab4b6u: goto P_0c0ab4b6;
case 0x0c0ab4b8u: goto P_0c0ab4b8;
case 0x0c0ab4bau: goto P_0c0ab4ba;
case 0x0c0ab4bcu: goto P_0c0ab4bc;
case 0x0c0ab4beu: goto P_0c0ab4be;
case 0x0c0ab4c0u: goto P_0c0ab4c0;
case 0x0c0ab4c2u: goto P_0c0ab4c2;
case 0x0c0ab4c4u: goto P_0c0ab4c4;
case 0x0c0ab4c6u: goto P_0c0ab4c6;
case 0x0c0ab4c8u: goto P_0c0ab4c8;
case 0x0c0ab4cau: goto P_0c0ab4ca;
case 0x0c0ab4ccu: goto P_0c0ab4cc;
case 0x0c0ab4ceu: goto P_0c0ab4ce;
case 0x0c0ab4d0u: goto P_0c0ab4d0;
case 0x0c0ab4d2u: goto P_0c0ab4d2;
case 0x0c0ab4d4u: goto P_0c0ab4d4;
case 0x0c0ab4d6u: goto P_0c0ab4d6;
case 0x0c0ab4d8u: goto P_0c0ab4d8;
case 0x0c0ab4dau: goto P_0c0ab4da;
case 0x0c0ab4dcu: goto P_0c0ab4dc;
case 0x0c0ab4deu: goto P_0c0ab4de;
case 0x0c0ab4e0u: goto P_0c0ab4e0;
case 0x0c0ab4e2u: goto P_0c0ab4e2;
case 0x0c0ab4e4u: goto P_0c0ab4e4;
case 0x0c0ab4e6u: goto P_0c0ab4e6;
case 0x0c0ab4e8u: goto P_0c0ab4e8;
case 0x0c0ab4eau: goto P_0c0ab4ea;
case 0x0c0ab4ecu: goto P_0c0ab4ec;
case 0x0c0ab4eeu: goto P_0c0ab4ee;
case 0x0c0ab4f0u: goto P_0c0ab4f0;
case 0x0c0ab4f2u: goto P_0c0ab4f2;
case 0x0c0ab4f4u: goto P_0c0ab4f4;
case 0x0c0ab4f6u: goto P_0c0ab4f6;
case 0x0c0ab4f8u: goto P_0c0ab4f8;
case 0x0c0ab4fau: goto P_0c0ab4fa;
case 0x0c0ab4fcu: goto P_0c0ab4fc;
case 0x0c0ab4feu: goto P_0c0ab4fe;
case 0x0c0ab500u: goto P_0c0ab500;
case 0x0c0ab502u: goto P_0c0ab502;
case 0x0c0ab504u: goto P_0c0ab504;
case 0x0c0ab506u: goto P_0c0ab506;
case 0x0c0ab508u: goto P_0c0ab508;
case 0x0c0ab50au: goto P_0c0ab50a;
case 0x0c0ab50cu: goto P_0c0ab50c;
case 0x0c0ab50eu: goto P_0c0ab50e;
case 0x0c0ab510u: goto P_0c0ab510;
case 0x0c0ab512u: goto P_0c0ab512;
case 0x0c0ab514u: goto P_0c0ab514;
case 0x0c0ab516u: goto P_0c0ab516;
case 0x0c0ab518u: goto P_0c0ab518;
case 0x0c0ab51au: goto P_0c0ab51a;
case 0x0c0ab51cu: goto P_0c0ab51c;
case 0x0c0ab51eu: goto P_0c0ab51e;
case 0x0c0ab520u: goto P_0c0ab520;
case 0x0c0ab522u: goto P_0c0ab522;
case 0x0c0ab524u: goto P_0c0ab524;
case 0x0c0ab526u: goto P_0c0ab526;
case 0x0c0ab528u: goto P_0c0ab528;
case 0x0c0ab52au: goto P_0c0ab52a;
case 0x0c0ab52cu: goto P_0c0ab52c;
case 0x0c0ab52eu: goto P_0c0ab52e;
case 0x0c0ab530u: goto P_0c0ab530;
case 0x0c0ab532u: goto P_0c0ab532;
case 0x0c0ab534u: goto P_0c0ab534;
case 0x0c0ab536u: goto P_0c0ab536;
case 0x0c0ab538u: goto P_0c0ab538;
case 0x0c0ab53au: goto P_0c0ab53a;
case 0x0c0ab53cu: goto P_0c0ab53c;
case 0x0c0ab53eu: goto P_0c0ab53e;
case 0x0c0ab540u: goto P_0c0ab540;
case 0x0c0ab542u: goto P_0c0ab542;
case 0x0c0ab544u: goto P_0c0ab544;
case 0x0c0ab546u: goto P_0c0ab546;
case 0x0c0ab548u: goto P_0c0ab548;
case 0x0c0ab54au: goto P_0c0ab54a;
case 0x0c0ab54cu: goto P_0c0ab54c;
case 0x0c0ab54eu: goto P_0c0ab54e;
case 0x0c0ab550u: goto P_0c0ab550;
case 0x0c0ab552u: goto P_0c0ab552;
case 0x0c0ab554u: goto P_0c0ab554;
case 0x0c0ab556u: goto P_0c0ab556;
case 0x0c0ab558u: goto P_0c0ab558;
case 0x0c0ab55au: goto P_0c0ab55a;
case 0x0c0ab55cu: goto P_0c0ab55c;
case 0x0c0ab55eu: goto P_0c0ab55e;
case 0x0c0ab560u: goto P_0c0ab560;
case 0x0c0ab562u: goto P_0c0ab562;
case 0x0c0ab564u: goto P_0c0ab564;
case 0x0c0ab566u: goto P_0c0ab566;
case 0x0c0ab568u: goto P_0c0ab568;
case 0x0c0ab56au: goto P_0c0ab56a;
case 0x0c0ab56cu: goto P_0c0ab56c;
case 0x0c0ab56eu: goto P_0c0ab56e;
case 0x0c0ab570u: goto P_0c0ab570;
case 0x0c0ab572u: goto P_0c0ab572;
case 0x0c0ab574u: goto P_0c0ab574;
case 0x0c0ab576u: goto P_0c0ab576;
case 0x0c0ab578u: goto P_0c0ab578;
case 0x0c0ab57au: goto P_0c0ab57a;
case 0x0c0ab57cu: goto P_0c0ab57c;
case 0x0c0ab57eu: goto P_0c0ab57e;
case 0x0c0ab580u: goto P_0c0ab580;
case 0x0c0ab582u: goto P_0c0ab582;
case 0x0c0ab584u: goto P_0c0ab584;
case 0x0c0ab586u: goto P_0c0ab586;
case 0x0c0ab588u: goto P_0c0ab588;
case 0x0c0ab58au: goto P_0c0ab58a;
case 0x0c0ab58cu: goto P_0c0ab58c;
case 0x0c0ab58eu: goto P_0c0ab58e;
case 0x0c0ab590u: goto P_0c0ab590;
case 0x0c0ab592u: goto P_0c0ab592;
case 0x0c0ab594u: goto P_0c0ab594;
case 0x0c0ab596u: goto P_0c0ab596;
case 0x0c0ab598u: goto P_0c0ab598;
case 0x0c0ab59au: goto P_0c0ab59a;
case 0x0c0ab59cu: goto P_0c0ab59c;
case 0x0c0ab59eu: goto P_0c0ab59e;
case 0x0c0ab5a0u: goto P_0c0ab5a0;
case 0x0c0ab5a2u: goto P_0c0ab5a2;
case 0x0c0ab5a4u: goto P_0c0ab5a4;
case 0x0c0ab5a6u: goto P_0c0ab5a6;
case 0x0c0ab5a8u: goto P_0c0ab5a8;
case 0x0c0ab5aau: goto P_0c0ab5aa;
case 0x0c0ab5acu: goto P_0c0ab5ac;
case 0x0c0ab5aeu: goto P_0c0ab5ae;
case 0x0c0ab5b0u: goto P_0c0ab5b0;
case 0x0c0ab5b2u: goto P_0c0ab5b2;
case 0x0c0ab5b4u: goto P_0c0ab5b4;
case 0x0c0ab5b6u: goto P_0c0ab5b6;
case 0x0c0ab5b8u: goto P_0c0ab5b8;
case 0x0c0ab5bau: goto P_0c0ab5ba;
case 0x0c0ab5bcu: goto P_0c0ab5bc;
case 0x0c0ab5beu: goto P_0c0ab5be;
case 0x0c0ab5c0u: goto P_0c0ab5c0;
case 0x0c0ab5e4u: goto P_0c0ab5e4;
case 0x0c0ab5e6u: goto P_0c0ab5e6;
case 0x0c0ab5e8u: goto P_0c0ab5e8;
case 0x0c0ab5eau: goto P_0c0ab5ea;
case 0x0c0ab5ecu: goto P_0c0ab5ec;
case 0x0c0ab5eeu: goto P_0c0ab5ee;
case 0x0c0ab5f0u: goto P_0c0ab5f0;
case 0x0c0ab5f2u: goto P_0c0ab5f2;
case 0x0c0ab5f4u: goto P_0c0ab5f4;
case 0x0c0ab5f6u: goto P_0c0ab5f6;
case 0x0c0ab5f8u: goto P_0c0ab5f8;
case 0x0c0ab5fau: goto P_0c0ab5fa;
case 0x0c0ab5fcu: goto P_0c0ab5fc;
case 0x0c0ab5feu: goto P_0c0ab5fe;
case 0x0c0ab600u: goto P_0c0ab600;
case 0x0c0ab602u: goto P_0c0ab602;
case 0x0c0ab604u: goto P_0c0ab604;
case 0x0c0ab606u: goto P_0c0ab606;
case 0x0c0ab608u: goto P_0c0ab608;
case 0x0c0ab60au: goto P_0c0ab60a;
case 0x0c0ab60cu: goto P_0c0ab60c;
case 0x0c0ab60eu: goto P_0c0ab60e;
case 0x0c0ab610u: goto P_0c0ab610;
case 0x0c0ab612u: goto P_0c0ab612;
case 0x0c0ab614u: goto P_0c0ab614;
case 0x0c0ab616u: goto P_0c0ab616;
case 0x0c0ab618u: goto P_0c0ab618;
case 0x0c0ab61au: goto P_0c0ab61a;
case 0x0c0ab61cu: goto P_0c0ab61c;
case 0x0c0ab61eu: goto P_0c0ab61e;
case 0x0c0ab620u: goto P_0c0ab620;
case 0x0c0ab622u: goto P_0c0ab622;
case 0x0c0ab624u: goto P_0c0ab624;
case 0x0c0ab626u: goto P_0c0ab626;
case 0x0c0ab628u: goto P_0c0ab628;
case 0x0c0ab62au: goto P_0c0ab62a;
case 0x0c0ab62cu: goto P_0c0ab62c;
case 0x0c0ab62eu: goto P_0c0ab62e;
case 0x0c0ab630u: goto P_0c0ab630;
case 0x0c0ab632u: goto P_0c0ab632;
case 0x0c0ab634u: goto P_0c0ab634;
case 0x0c0ab636u: goto P_0c0ab636;
case 0x0c0ab638u: goto P_0c0ab638;
case 0x0c0ab63au: goto P_0c0ab63a;
case 0x0c0ab63cu: goto P_0c0ab63c;
case 0x0c0ab63eu: goto P_0c0ab63e;
case 0x0c0ab640u: goto P_0c0ab640;
case 0x0c0ab642u: goto P_0c0ab642;
case 0x0c0ab644u: goto P_0c0ab644;
case 0x0c0ab646u: goto P_0c0ab646;
case 0x0c0ab648u: goto P_0c0ab648;
case 0x0c0ab64au: goto P_0c0ab64a;
case 0x0c0ab64cu: goto P_0c0ab64c;
case 0x0c0ab64eu: goto P_0c0ab64e;
case 0x0c0ab650u: goto P_0c0ab650;
case 0x0c0ab652u: goto P_0c0ab652;
case 0x0c0ab654u: goto P_0c0ab654;
case 0x0c0ab656u: goto P_0c0ab656;
case 0x0c0ab658u: goto P_0c0ab658;
case 0x0c0ab65au: goto P_0c0ab65a;
case 0x0c0ab65cu: goto P_0c0ab65c;
case 0x0c0ab65eu: goto P_0c0ab65e;
case 0x0c0ab660u: goto P_0c0ab660;
case 0x0c0ab662u: goto P_0c0ab662;
case 0x0c0ab664u: goto P_0c0ab664;
case 0x0c0ab666u: goto P_0c0ab666;
case 0x0c0ab668u: goto P_0c0ab668;
case 0x0c0ab66au: goto P_0c0ab66a;
case 0x0c0ab66cu: goto P_0c0ab66c;
case 0x0c0ab66eu: goto P_0c0ab66e;
case 0x0c0ab670u: goto P_0c0ab670;
case 0x0c0ab672u: goto P_0c0ab672;
case 0x0c0ab674u: goto P_0c0ab674;
case 0x0c0ab676u: goto P_0c0ab676;
case 0x0c0ab678u: goto P_0c0ab678;
case 0x0c0ab67au: goto P_0c0ab67a;
case 0x0c0ab67cu: goto P_0c0ab67c;
case 0x0c0ab67eu: goto P_0c0ab67e;
case 0x0c0ab680u: goto P_0c0ab680;
case 0x0c0ab682u: goto P_0c0ab682;
case 0x0c0ab684u: goto P_0c0ab684;
case 0x0c0ab686u: goto P_0c0ab686;
case 0x0c0ab688u: goto P_0c0ab688;
case 0x0c0ab68au: goto P_0c0ab68a;
case 0x0c0ab68cu: goto P_0c0ab68c;
case 0x0c0ab68eu: goto P_0c0ab68e;
case 0x0c0ab690u: goto P_0c0ab690;
case 0x0c0ab692u: goto P_0c0ab692;
case 0x0c0ab694u: goto P_0c0ab694;
case 0x0c0ab696u: goto P_0c0ab696;
case 0x0c0ab698u: goto P_0c0ab698;
case 0x0c0ab69au: goto P_0c0ab69a;
case 0x0c0ab69cu: goto P_0c0ab69c;
case 0x0c0ab69eu: goto P_0c0ab69e;
case 0x0c0ab6a0u: goto P_0c0ab6a0;
case 0x0c0ab6a2u: goto P_0c0ab6a2;
case 0x0c0ab6a4u: goto P_0c0ab6a4;
case 0x0c0ab6a6u: goto P_0c0ab6a6;
case 0x0c0ab6a8u: goto P_0c0ab6a8;
case 0x0c0ab6aau: goto P_0c0ab6aa;
case 0x0c0ab6acu: goto P_0c0ab6ac;
case 0x0c0ab6aeu: goto P_0c0ab6ae;
case 0x0c0ab6b0u: goto P_0c0ab6b0;
case 0x0c0ab6b2u: goto P_0c0ab6b2;
case 0x0c0ab6b4u: goto P_0c0ab6b4;
case 0x0c0ab6b6u: goto P_0c0ab6b6;
case 0x0c0ab6b8u: goto P_0c0ab6b8;
case 0x0c0ab6bau: goto P_0c0ab6ba;
case 0x0c0ab6bcu: goto P_0c0ab6bc;
case 0x0c0ab6beu: goto P_0c0ab6be;
case 0x0c0ab6c0u: goto P_0c0ab6c0;
case 0x0c0ab6c2u: goto P_0c0ab6c2;
case 0x0c0ab6c4u: goto P_0c0ab6c4;
case 0x0c0ab6c6u: goto P_0c0ab6c6;
case 0x0c0ab6c8u: goto P_0c0ab6c8;
case 0x0c0ab6cau: goto P_0c0ab6ca;
case 0x0c0ab6ccu: goto P_0c0ab6cc;
case 0x0c0ab6ceu: goto P_0c0ab6ce;
case 0x0c0ab6d0u: goto P_0c0ab6d0;
case 0x0c0ab6d2u: goto P_0c0ab6d2;
case 0x0c0ab6d4u: goto P_0c0ab6d4;
case 0x0c0ab6d6u: goto P_0c0ab6d6;
case 0x0c0ab6d8u: goto P_0c0ab6d8;
case 0x0c0ab6dau: goto P_0c0ab6da;
case 0x0c0ab6dcu: goto P_0c0ab6dc;
case 0x0c0ab6deu: goto P_0c0ab6de;
case 0x0c0ab6e0u: goto P_0c0ab6e0;
case 0x0c0ab6e2u: goto P_0c0ab6e2;
case 0x0c0ab6e4u: goto P_0c0ab6e4;
case 0x0c0ab6e6u: goto P_0c0ab6e6;
case 0x0c0ab6e8u: goto P_0c0ab6e8;
case 0x0c0ab6eau: goto P_0c0ab6ea;
case 0x0c0ab6ecu: goto P_0c0ab6ec;
case 0x0c0ab6eeu: goto P_0c0ab6ee;
case 0x0c0ab6f0u: goto P_0c0ab6f0;
case 0x0c0ab6f2u: goto P_0c0ab6f2;
case 0x0c0ab71cu: goto P_0c0ab71c;
case 0x0c0ab71eu: goto P_0c0ab71e;
case 0x0c0ab720u: goto P_0c0ab720;
case 0x0c0ab722u: goto P_0c0ab722;
case 0x0c0ab724u: goto P_0c0ab724;
case 0x0c0ab726u: goto P_0c0ab726;
case 0x0c0ab728u: goto P_0c0ab728;
case 0x0c0ab72au: goto P_0c0ab72a;
case 0x0c0ab72cu: goto P_0c0ab72c;
case 0x0c0ab72eu: goto P_0c0ab72e;
case 0x0c0ab730u: goto P_0c0ab730;
case 0x0c0ab732u: goto P_0c0ab732;
case 0x0c0ab734u: goto P_0c0ab734;
case 0x0c0ab736u: goto P_0c0ab736;
case 0x0c0ab738u: goto P_0c0ab738;
case 0x0c0ab73au: goto P_0c0ab73a;
case 0x0c0ab73cu: goto P_0c0ab73c;
case 0x0c0ab73eu: goto P_0c0ab73e;
case 0x0c0ab740u: goto P_0c0ab740;
case 0x0c0ab742u: goto P_0c0ab742;
case 0x0c0ab744u: goto P_0c0ab744;
case 0x0c0ab746u: goto P_0c0ab746;
case 0x0c0ab748u: goto P_0c0ab748;
case 0x0c0ab74au: goto P_0c0ab74a;
case 0x0c0ab74cu: goto P_0c0ab74c;
case 0x0c0ab74eu: goto P_0c0ab74e;
case 0x0c0ab750u: goto P_0c0ab750;
case 0x0c0ab752u: goto P_0c0ab752;
case 0x0c0ab754u: goto P_0c0ab754;
case 0x0c0ab756u: goto P_0c0ab756;
case 0x0c0ab758u: goto P_0c0ab758;
case 0x0c0ab75au: goto P_0c0ab75a;
case 0x0c0ab75cu: goto P_0c0ab75c;
case 0x0c0ab75eu: goto P_0c0ab75e;
case 0x0c0ab760u: goto P_0c0ab760;
case 0x0c0ab762u: goto P_0c0ab762;
case 0x0c0ab764u: goto P_0c0ab764;
case 0x0c0ab766u: goto P_0c0ab766;
case 0x0c0ab768u: goto P_0c0ab768;
case 0x0c0ab76au: goto P_0c0ab76a;
case 0x0c0ab76cu: goto P_0c0ab76c;
case 0x0c0ab76eu: goto P_0c0ab76e;
case 0x0c0ab770u: goto P_0c0ab770;
case 0x0c0ab772u: goto P_0c0ab772;
case 0x0c0ab774u: goto P_0c0ab774;
case 0x0c0ab776u: goto P_0c0ab776;
case 0x0c0ab778u: goto P_0c0ab778;
case 0x0c0ab77au: goto P_0c0ab77a;
case 0x0c0ab77cu: goto P_0c0ab77c;
case 0x0c0ab77eu: goto P_0c0ab77e;
case 0x0c0ab780u: goto P_0c0ab780;
case 0x0c0ab782u: goto P_0c0ab782;
case 0x0c0ab784u: goto P_0c0ab784;
case 0x0c0ab786u: goto P_0c0ab786;
case 0x0c0ab788u: goto P_0c0ab788;
case 0x0c0ab78au: goto P_0c0ab78a;
case 0x0c0ab78cu: goto P_0c0ab78c;
case 0x0c0ab78eu: goto P_0c0ab78e;
case 0x0c0ab790u: goto P_0c0ab790;
case 0x0c0ab792u: goto P_0c0ab792;
case 0x0c0ab794u: goto P_0c0ab794;
case 0x0c0ab796u: goto P_0c0ab796;
case 0x0c0ab798u: goto P_0c0ab798;
case 0x0c0ab79au: goto P_0c0ab79a;
case 0x0c0ab79cu: goto P_0c0ab79c;
case 0x0c0ab79eu: goto P_0c0ab79e;
case 0x0c0ab7a0u: goto P_0c0ab7a0;
case 0x0c0ab7a2u: goto P_0c0ab7a2;
case 0x0c0ab7a4u: goto P_0c0ab7a4;
case 0x0c0ab7a6u: goto P_0c0ab7a6;
case 0x0c0ab7a8u: goto P_0c0ab7a8;
case 0x0c0ab7aau: goto P_0c0ab7aa;
case 0x0c0ab7acu: goto P_0c0ab7ac;
case 0x0c0ab7aeu: goto P_0c0ab7ae;
case 0x0c0ab7b0u: goto P_0c0ab7b0;
case 0x0c0ab7b2u: goto P_0c0ab7b2;
case 0x0c0ab7b4u: goto P_0c0ab7b4;
case 0x0c0ab7b6u: goto P_0c0ab7b6;
case 0x0c0ab7b8u: goto P_0c0ab7b8;
case 0x0c0ab7bau: goto P_0c0ab7ba;
case 0x0c0ab7bcu: goto P_0c0ab7bc;
case 0x0c0ab7beu: goto P_0c0ab7be;
case 0x0c0ab7c0u: goto P_0c0ab7c0;
case 0x0c0ab7c2u: goto P_0c0ab7c2;
case 0x0c0ab7c4u: goto P_0c0ab7c4;
case 0x0c0ab7c6u: goto P_0c0ab7c6;
case 0x0c0ab7c8u: goto P_0c0ab7c8;
case 0x0c0ab7cau: goto P_0c0ab7ca;
case 0x0c0ab7ccu: goto P_0c0ab7cc;
case 0x0c0ab7ceu: goto P_0c0ab7ce;
case 0x0c0ab7d0u: goto P_0c0ab7d0;
case 0x0c0ab7d2u: goto P_0c0ab7d2;
case 0x0c0ab7d4u: goto P_0c0ab7d4;
case 0x0c0ab7d6u: goto P_0c0ab7d6;
case 0x0c0ab7d8u: goto P_0c0ab7d8;
case 0x0c0ab7dau: goto P_0c0ab7da;
case 0x0c0ab7dcu: goto P_0c0ab7dc;
case 0x0c0ab7deu: goto P_0c0ab7de;
case 0x0c0ab7e0u: goto P_0c0ab7e0;
case 0x0c0ab7e2u: goto P_0c0ab7e2;
case 0x0c0ab7e4u: goto P_0c0ab7e4;
case 0x0c0ab7e6u: goto P_0c0ab7e6;
case 0x0c0ab7e8u: goto P_0c0ab7e8;
case 0x0c0ab7eau: goto P_0c0ab7ea;
case 0x0c0ab7ecu: goto P_0c0ab7ec;
case 0x0c0ab7eeu: goto P_0c0ab7ee;
case 0x0c0ab7f0u: goto P_0c0ab7f0;
case 0x0c0ab7f2u: goto P_0c0ab7f2;
case 0x0c0ab7f4u: goto P_0c0ab7f4;
case 0x0c0ab7f6u: goto P_0c0ab7f6;
case 0x0c0ab7f8u: goto P_0c0ab7f8;
case 0x0c0ab7fau: goto P_0c0ab7fa;
case 0x0c0ab7fcu: goto P_0c0ab7fc;
case 0x0c0ab7feu: goto P_0c0ab7fe;
case 0x0c0ab800u: goto P_0c0ab800;
case 0x0c0ab802u: goto P_0c0ab802;
case 0x0c0ab804u: goto P_0c0ab804;
case 0x0c0ab806u: goto P_0c0ab806;
case 0x0c0ab808u: goto P_0c0ab808;
case 0x0c0ab80au: goto P_0c0ab80a;
case 0x0c0ab80cu: goto P_0c0ab80c;
case 0x0c0ab80eu: goto P_0c0ab80e;
case 0x0c0ab810u: goto P_0c0ab810;
case 0x0c0ab812u: goto P_0c0ab812;
case 0x0c0ab814u: goto P_0c0ab814;
case 0x0c0ab816u: goto P_0c0ab816;
case 0x0c0ab818u: goto P_0c0ab818;
case 0x0c0ab81au: goto P_0c0ab81a;
case 0x0c0ab81cu: goto P_0c0ab81c;
case 0x0c0ab81eu: goto P_0c0ab81e;
case 0x0c0ab820u: goto P_0c0ab820;
case 0x0c0ab822u: goto P_0c0ab822;
case 0x0c0ab824u: goto P_0c0ab824;
case 0x0c0ab826u: goto P_0c0ab826;
case 0x0c0ab828u: goto P_0c0ab828;
case 0x0c0ab82au: goto P_0c0ab82a;
case 0x0c0ab82cu: goto P_0c0ab82c;
case 0x0c0ab82eu: goto P_0c0ab82e;
case 0x0c0ab830u: goto P_0c0ab830;
case 0x0c0ab832u: goto P_0c0ab832;
case 0x0c0ab834u: goto P_0c0ab834;
case 0x0c0ab836u: goto P_0c0ab836;
case 0x0c0ab838u: goto P_0c0ab838;
case 0x0c0ab83au: goto P_0c0ab83a;
case 0x0c0ab83cu: goto P_0c0ab83c;
case 0x0c0ab83eu: goto P_0c0ab83e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07695a: /* original 9044, guest PC 0x0c07695a */
if(!s->budget--) { s->failed_pc=0x0c07695au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0769e6u,2);
goto P_0c07695c;
P_0c07695c: /* original 03fe, guest PC 0x0c07695c */
if(!s->budget--) { s->failed_pc=0x0c07695cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07695e;
P_0c07695e: /* original 9046, guest PC 0x0c07695e */
if(!s->budget--) { s->failed_pc=0x0c07695eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0769eeu,2);
goto P_0c076960;
P_0c076960: /* original 023c, guest PC 0x0c076960 */
if(!s->budget--) { s->failed_pc=0x0c076960u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c076962;
P_0c076962: /* original 622c, guest PC 0x0c076962 */
if(!s->budget--) { s->failed_pc=0x0c076962u; return 0; }
r[2]=r[2]&255u;
goto P_0c076964;
P_0c076964: /* original 6023, guest PC 0x0c076964 */
if(!s->budget--) { s->failed_pc=0x0c076964u; return 0; }
r[0]=r[2];
goto P_0c076966;
P_0c076966: /* original 8805, guest PC 0x0c076966 */
if(!s->budget--) { s->failed_pc=0x0c076966u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c076968;
P_0c076968: /* original 1f25, guest PC 0x0c076968 */
if(!s->budget--) { s->failed_pc=0x0c076968u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c07696a;
P_0c07696a: /* original 8910, guest PC 0x0c07696a */
if(!s->budget--) { s->failed_pc=0x0c07696au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07698e; }
goto P_0c07696c;
P_0c07696c: /* original 6023, guest PC 0x0c07696c */
if(!s->budget--) { s->failed_pc=0x0c07696cu; return 0; }
r[0]=r[2];
goto P_0c07696e;
P_0c07696e: /* original 8806, guest PC 0x0c07696e */
if(!s->budget--) { s->failed_pc=0x0c07696eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c076970;
P_0c076970: /* original 890d, guest PC 0x0c076970 */
if(!s->budget--) { s->failed_pc=0x0c076970u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07698e; }
goto P_0c076972;
P_0c076972: /* original 6023, guest PC 0x0c076972 */
if(!s->budget--) { s->failed_pc=0x0c076972u; return 0; }
r[0]=r[2];
goto P_0c076974;
P_0c076974: /* original 8803, guest PC 0x0c076974 */
if(!s->budget--) { s->failed_pc=0x0c076974u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c076976;
P_0c076976: /* original 890a, guest PC 0x0c076976 */
if(!s->budget--) { s->failed_pc=0x0c076976u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07698e; }
goto P_0c076978;
P_0c076978: /* original 6023, guest PC 0x0c076978 */
if(!s->budget--) { s->failed_pc=0x0c076978u; return 0; }
r[0]=r[2];
goto P_0c07697a;
P_0c07697a: /* original 8804, guest PC 0x0c07697a */
if(!s->budget--) { s->failed_pc=0x0c07697au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c07697c;
P_0c07697c: /* original 8907, guest PC 0x0c07697c */
if(!s->budget--) { s->failed_pc=0x0c07697cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07698e; }
goto P_0c07697e;
P_0c07697e: /* original 6023, guest PC 0x0c07697e */
if(!s->budget--) { s->failed_pc=0x0c07697eu; return 0; }
r[0]=r[2];
goto P_0c076980;
P_0c076980: /* original 881a, guest PC 0x0c076980 */
if(!s->budget--) { s->failed_pc=0x0c076980u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001au)!=0);
goto P_0c076982;
P_0c076982: /* original 8904, guest PC 0x0c076982 */
if(!s->budget--) { s->failed_pc=0x0c076982u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07698e; }
goto P_0c076984;
P_0c076984: /* original 6023, guest PC 0x0c076984 */
if(!s->budget--) { s->failed_pc=0x0c076984u; return 0; }
r[0]=r[2];
goto P_0c076986;
P_0c076986: /* original 881b, guest PC 0x0c076986 */
if(!s->budget--) { s->failed_pc=0x0c076986u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001bu)!=0);
goto P_0c076988;
P_0c076988: /* original 8901, guest PC 0x0c076988 */
if(!s->budget--) { s->failed_pc=0x0c076988u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07698e; }
goto P_0c07698a;
P_0c07698a: /* original abc5, guest PC 0x0c07698a */
if(!s->budget--) { s->failed_pc=0x0c07698au; return 0; }
return vf3_matrix_family(0x0c076118u,s,ram);
P_0c07698c: /* original 0009, guest PC 0x0c07698c */
if(!s->budget--) { s->failed_pc=0x0c07698cu; return 0; }
goto P_0c07698e;
P_0c07698e: /* original e054, guest PC 0x0c07698e */
if(!s->budget--) { s->failed_pc=0x0c07698eu; return 0; }
r[0]=0x00000054u;
goto P_0c076990;
P_0c076990: /* original 02fe, guest PC 0x0c076990 */
if(!s->budget--) { s->failed_pc=0x0c076990u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076992;
P_0c076992: /* original e316, guest PC 0x0c076992 */
if(!s->budget--) { s->failed_pc=0x0c076992u; return 0; }
r[3]=0x00000016u;
goto P_0c076994;
P_0c076994: /* original 3232, guest PC 0x0c076994 */
if(!s->budget--) { s->failed_pc=0x0c076994u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c076996;
P_0c076996: /* original 8b01, guest PC 0x0c076996 */
if(!s->budget--) { s->failed_pc=0x0c076996u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07699c; }
goto P_0c076998;
P_0c076998: /* original abbe, guest PC 0x0c076998 */
if(!s->budget--) { s->failed_pc=0x0c076998u; return 0; }
return vf3_matrix_family(0x0c076118u,s,ram);
P_0c07699a: /* original 0009, guest PC 0x0c07699a */
if(!s->budget--) { s->failed_pc=0x0c07699au; return 0; }
goto P_0c07699c;
P_0c07699c: /* original 9022, guest PC 0x0c07699c */
if(!s->budget--) { s->failed_pc=0x0c07699cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0769e4u,2);
goto P_0c07699e;
P_0c07699e: /* original 02fe, guest PC 0x0c07699e */
if(!s->budget--) { s->failed_pc=0x0c07699eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0769a0;
P_0c0769a0: /* original e046, guest PC 0x0c0769a0 */
if(!s->budget--) { s->failed_pc=0x0c0769a0u; return 0; }
r[0]=0x00000046u;
goto P_0c0769a2;
P_0c0769a2: /* original 012d, guest PC 0x0c0769a2 */
if(!s->budget--) { s->failed_pc=0x0c0769a2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c0769a4;
P_0c0769a4: /* original e054, guest PC 0x0c0769a4 */
if(!s->budget--) { s->failed_pc=0x0c0769a4u; return 0; }
r[0]=0x00000054u;
goto P_0c0769a6;
P_0c0769a6: /* original 02fe, guest PC 0x0c0769a6 */
if(!s->budget--) { s->failed_pc=0x0c0769a6u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0769a8;
P_0c0769a8: /* original e000, guest PC 0x0c0769a8 */
if(!s->budget--) { s->failed_pc=0x0c0769a8u; return 0; }
r[0]=0x00000000u;
goto P_0c0769aa;
P_0c0769aa: /* original 611d, guest PC 0x0c0769aa */
if(!s->budget--) { s->failed_pc=0x0c0769aau; return 0; }
r[1]=r[1]&65535u;
goto P_0c0769ac;
P_0c0769ac: /* original 3128, guest PC 0x0c0769ac */
if(!s->budget--) { s->failed_pc=0x0c0769acu; return 0; }
r[1]-=r[2];
goto P_0c0769ae;
P_0c0769ae: /* original 3106, guest PC 0x0c0769ae */
if(!s->budget--) { s->failed_pc=0x0c0769aeu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[0])!=0);
goto P_0c0769b0;
P_0c0769b0: /* original 8b01, guest PC 0x0c0769b0 */
if(!s->budget--) { s->failed_pc=0x0c0769b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0769b6; }
goto P_0c0769b2;
P_0c0769b2: /* original aef4, guest PC 0x0c0769b2 */
if(!s->budget--) { s->failed_pc=0x0c0769b2u; return 0; }
return vf3_matrix_family(0x0c07679eu,s,ram);
P_0c0769b4: /* original 0009, guest PC 0x0c0769b4 */
if(!s->budget--) { s->failed_pc=0x0c0769b4u; return 0; }
goto P_0c0769b6;
P_0c0769b6: /* original abaf, guest PC 0x0c0769b6 */
if(!s->budget--) { s->failed_pc=0x0c0769b6u; return 0; }
return vf3_matrix_family(0x0c076118u,s,ram);
P_0c0769b8: /* original 0009, guest PC 0x0c0769b8 */
if(!s->budget--) { s->failed_pc=0x0c0769b8u; return 0; }
goto P_0c0769ba;
P_0c0769ba: /* original 9116, guest PC 0x0c0769ba */
if(!s->budget--) { s->failed_pc=0x0c0769bau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0769eau,2);
goto P_0c0769bc;
P_0c0769bc: /* original 3f1c, guest PC 0x0c0769bc */
if(!s->budget--) { s->failed_pc=0x0c0769bcu; return 0; }
r[15]+=r[1];
goto P_0c0769be;
P_0c0769be: /* original 4f16, guest PC 0x0c0769be */
if(!s->budget--) { s->failed_pc=0x0c0769beu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0769c0;
P_0c0769c0: /* original 4f26, guest PC 0x0c0769c0 */
if(!s->budget--) { s->failed_pc=0x0c0769c0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0769c2;
P_0c0769c2: /* original 000b, guest PC 0x0c0769c2 */
if(!s->budget--) { s->failed_pc=0x0c0769c2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0769c4: /* original 0009, guest PC 0x0c0769c4 */
if(!s->budget--) { s->failed_pc=0x0c0769c4u; return 0; }
return vf3_matrix_family(0x0c0769c6u,s,ram);
P_0c0781c2: /* original 4f22, guest PC 0x0c0781c2 */
if(!s->budget--) { s->failed_pc=0x0c0781c2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0781c4;
P_0c0781c4: /* original 6d53, guest PC 0x0c0781c4 */
if(!s->budget--) { s->failed_pc=0x0c0781c4u; return 0; }
r[13]=r[5];
goto P_0c0781c6;
P_0c0781c6: /* original 7ff8, guest PC 0x0c0781c6 */
if(!s->budget--) { s->failed_pc=0x0c0781c6u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0781c8;
P_0c0781c8: /* original 2f62, guest PC 0x0c0781c8 */
if(!s->budget--) { s->failed_pc=0x0c0781c8u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0781ca;
P_0c0781ca: /* original 1f71, guest PC 0x0c0781ca */
if(!s->budget--) { s->failed_pc=0x0c0781cau; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c0781cc;
P_0c0781cc: /* original 9385, guest PC 0x0c0781cc */
if(!s->budget--) { s->failed_pc=0x0c0781ccu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0782dau,2);
goto P_0c0781ce;
P_0c0781ce: /* original 0e34, guest PC 0x0c0781ce */
if(!s->budget--) { s->failed_pc=0x0c0781ceu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0781d0;
P_0c0781d0: /* original e01a, guest PC 0x0c0781d0 */
if(!s->budget--) { s->failed_pc=0x0c0781d0u; return 0; }
r[0]=0x0000001au;
goto P_0c0781d2;
P_0c0781d2: /* original 9283, guest PC 0x0c0781d2 */
if(!s->budget--) { s->failed_pc=0x0c0781d2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0782dcu,2);
goto P_0c0781d4;
P_0c0781d4: /* original 0e24, guest PC 0x0c0781d4 */
if(!s->budget--) { s->failed_pc=0x0c0781d4u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0781d6;
P_0c0781d6: /* original 9082, guest PC 0x0c0781d6 */
if(!s->budget--) { s->failed_pc=0x0c0781d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0782deu,2);
goto P_0c0781d8;
P_0c0781d8: /* original 04de, guest PC 0x0c0781d8 */
if(!s->budget--) { s->failed_pc=0x0c0781d8u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c0781da;
P_0c0781da: /* original 2448, guest PC 0x0c0781da */
if(!s->budget--) { s->failed_pc=0x0c0781dau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0781dc;
P_0c0781dc: /* original 8920, guest PC 0x0c0781dc */
if(!s->budget--) { s->failed_pc=0x0c0781dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c078220; }
goto P_0c0781de;
P_0c0781de: /* original 53fe, guest PC 0x0c0781de */
if(!s->budget--) { s->failed_pc=0x0c0781deu; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c0781e0;
P_0c0781e0: /* original 65d3, guest PC 0x0c0781e0 */
if(!s->budget--) { s->failed_pc=0x0c0781e0u; return 0; }
r[5]=r[13];
goto P_0c0781e2;
P_0c0781e2: /* original 2f36, guest PC 0x0c0781e2 */
if(!s->budget--) { s->failed_pc=0x0c0781e2u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0781e4;
P_0c0781e4: /* original 52fe, guest PC 0x0c0781e4 */
if(!s->budget--) { s->failed_pc=0x0c0781e4u; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c0781e6;
P_0c0781e6: /* original 2f26, guest PC 0x0c0781e6 */
if(!s->budget--) { s->failed_pc=0x0c0781e6u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c0781e8;
P_0c0781e8: /* original 53fe, guest PC 0x0c0781e8 */
if(!s->budget--) { s->failed_pc=0x0c0781e8u; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c0781ea;
P_0c0781ea: /* original 2f36, guest PC 0x0c0781ea */
if(!s->budget--) { s->failed_pc=0x0c0781eau; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0781ec;
P_0c0781ec: /* original 52fe, guest PC 0x0c0781ec */
if(!s->budget--) { s->failed_pc=0x0c0781ecu; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c0781ee;
P_0c0781ee: /* original 2f26, guest PC 0x0c0781ee */
if(!s->budget--) { s->failed_pc=0x0c0781eeu; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c0781f0;
P_0c0781f0: /* original 53fe, guest PC 0x0c0781f0 */
if(!s->budget--) { s->failed_pc=0x0c0781f0u; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c0781f2;
P_0c0781f2: /* original 2f36, guest PC 0x0c0781f2 */
if(!s->budget--) { s->failed_pc=0x0c0781f2u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0781f4;
P_0c0781f4: /* original 52fe, guest PC 0x0c0781f4 */
if(!s->budget--) { s->failed_pc=0x0c0781f4u; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c0781f6;
P_0c0781f6: /* original 2f26, guest PC 0x0c0781f6 */
if(!s->budget--) { s->failed_pc=0x0c0781f6u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c0781f8;
P_0c0781f8: /* original 53fe, guest PC 0x0c0781f8 */
if(!s->budget--) { s->failed_pc=0x0c0781f8u; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c0781fa;
P_0c0781fa: /* original 2f36, guest PC 0x0c0781fa */
if(!s->budget--) { s->failed_pc=0x0c0781fau; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0781fc;
P_0c0781fc: /* original 52fe, guest PC 0x0c0781fc */
if(!s->budget--) { s->failed_pc=0x0c0781fcu; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c0781fe;
P_0c0781fe: /* original 2f26, guest PC 0x0c0781fe */
if(!s->budget--) { s->failed_pc=0x0c0781feu; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c078200;
P_0c078200: /* original 2f46, guest PC 0x0c078200 */
if(!s->budget--) { s->failed_pc=0x0c078200u; return 0; }
r[15]-=4; write(ram,r[15],r[4],4);
goto P_0c078202;
P_0c078202: /* original 53fe, guest PC 0x0c078202 */
if(!s->budget--) { s->failed_pc=0x0c078202u; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c078204;
P_0c078204: /* original 2f36, guest PC 0x0c078204 */
if(!s->budget--) { s->failed_pc=0x0c078204u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c078206;
P_0c078206: /* original 56fa, guest PC 0x0c078206 */
if(!s->budget--) { s->failed_pc=0x0c078206u; return 0; }
r[6]=read(ram,r[15]+40,4);
goto P_0c078208;
P_0c078208: /* original 57fb, guest PC 0x0c078208 */
if(!s->budget--) { s->failed_pc=0x0c078208u; return 0; }
r[7]=read(ram,r[15]+44,4);
goto P_0c07820a;
P_0c07820a: /* original b046, guest PC 0x0c07820a */
if(!s->budget--) { s->failed_pc=0x0c07820au; return 0; }
target=0x0c07829au; r[16]=0x0c07820eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07820eu) { target=s->pc; goto dispatch; }
goto P_0c07820e;
P_0c07820c: /* original 64e3, guest PC 0x0c07820c */
if(!s->budget--) { s->failed_pc=0x0c07820cu; return 0; }
r[4]=r[14];
goto P_0c07820e;
P_0c07820e: /* original 6403, guest PC 0x0c07820e */
if(!s->budget--) { s->failed_pc=0x0c07820eu; return 0; }
r[4]=r[0];
goto P_0c078210;
P_0c078210: /* original 2448, guest PC 0x0c078210 */
if(!s->budget--) { s->failed_pc=0x0c078210u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c078212;
P_0c078212: /* original 8f03, guest PC 0x0c078212 */
if(!s->budget--) { s->failed_pc=0x0c078212u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000028u;
if(!cond) { goto P_0c07821c; }
goto P_0c078216;
P_0c078214: /* original 7f28, guest PC 0x0c078214 */
if(!s->budget--) { s->failed_pc=0x0c078214u; return 0; }
r[15]+=0x00000028u;
goto P_0c078216;
P_0c078216: /* original 52f6, guest PC 0x0c078216 */
if(!s->budget--) { s->failed_pc=0x0c078216u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c078218;
P_0c078218: /* original 2228, guest PC 0x0c078218 */
if(!s->budget--) { s->failed_pc=0x0c078218u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07821a;
P_0c07821a: /* original 8b01, guest PC 0x0c07821a */
if(!s->budget--) { s->failed_pc=0x0c07821au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c078220; }
goto P_0c07821c;
P_0c07821c: /* original a01a, guest PC 0x0c07821c */
if(!s->budget--) { s->failed_pc=0x0c07821cu; return 0; }
r[0]=r[4];
goto P_0c078254;
P_0c07821e: /* original 6043, guest PC 0x0c07821e */
if(!s->budget--) { s->failed_pc=0x0c07821eu; return 0; }
r[0]=r[4];
goto P_0c078220;
P_0c078220: /* original 53fe, guest PC 0x0c078220 */
if(!s->budget--) { s->failed_pc=0x0c078220u; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c078222;
P_0c078222: /* original 65d3, guest PC 0x0c078222 */
if(!s->budget--) { s->failed_pc=0x0c078222u; return 0; }
r[5]=r[13];
goto P_0c078224;
P_0c078224: /* original 2f36, guest PC 0x0c078224 */
if(!s->budget--) { s->failed_pc=0x0c078224u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c078226;
P_0c078226: /* original 52fe, guest PC 0x0c078226 */
if(!s->budget--) { s->failed_pc=0x0c078226u; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c078228;
P_0c078228: /* original 2f26, guest PC 0x0c078228 */
if(!s->budget--) { s->failed_pc=0x0c078228u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c07822a;
P_0c07822a: /* original 53fe, guest PC 0x0c07822a */
if(!s->budget--) { s->failed_pc=0x0c07822au; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c07822c;
P_0c07822c: /* original 2f36, guest PC 0x0c07822c */
if(!s->budget--) { s->failed_pc=0x0c07822cu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c07822e;
P_0c07822e: /* original 52fe, guest PC 0x0c07822e */
if(!s->budget--) { s->failed_pc=0x0c07822eu; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c078230;
P_0c078230: /* original 2f26, guest PC 0x0c078230 */
if(!s->budget--) { s->failed_pc=0x0c078230u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c078232;
P_0c078232: /* original 53fe, guest PC 0x0c078232 */
if(!s->budget--) { s->failed_pc=0x0c078232u; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c078234;
P_0c078234: /* original 2f36, guest PC 0x0c078234 */
if(!s->budget--) { s->failed_pc=0x0c078234u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c078236;
P_0c078236: /* original 52fe, guest PC 0x0c078236 */
if(!s->budget--) { s->failed_pc=0x0c078236u; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c078238;
P_0c078238: /* original 2f26, guest PC 0x0c078238 */
if(!s->budget--) { s->failed_pc=0x0c078238u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c07823a;
P_0c07823a: /* original 53fe, guest PC 0x0c07823a */
if(!s->budget--) { s->failed_pc=0x0c07823au; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c07823c;
P_0c07823c: /* original 2f36, guest PC 0x0c07823c */
if(!s->budget--) { s->failed_pc=0x0c07823cu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c07823e;
P_0c07823e: /* original 52fe, guest PC 0x0c07823e */
if(!s->budget--) { s->failed_pc=0x0c07823eu; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c078240;
P_0c078240: /* original 2f26, guest PC 0x0c078240 */
if(!s->budget--) { s->failed_pc=0x0c078240u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c078242;
P_0c078242: /* original 53fe, guest PC 0x0c078242 */
if(!s->budget--) { s->failed_pc=0x0c078242u; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c078244;
P_0c078244: /* original 2f36, guest PC 0x0c078244 */
if(!s->budget--) { s->failed_pc=0x0c078244u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c078246;
P_0c078246: /* original 52fe, guest PC 0x0c078246 */
if(!s->budget--) { s->failed_pc=0x0c078246u; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c078248;
P_0c078248: /* original 2f26, guest PC 0x0c078248 */
if(!s->budget--) { s->failed_pc=0x0c078248u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c07824a;
P_0c07824a: /* original 56fa, guest PC 0x0c07824a */
if(!s->budget--) { s->failed_pc=0x0c07824au; return 0; }
r[6]=read(ram,r[15]+40,4);
goto P_0c07824c;
P_0c07824c: /* original 57fb, guest PC 0x0c07824c */
if(!s->budget--) { s->failed_pc=0x0c07824cu; return 0; }
r[7]=read(ram,r[15]+44,4);
goto P_0c07824e;
P_0c07824e: /* original b006, guest PC 0x0c07824e */
if(!s->budget--) { s->failed_pc=0x0c07824eu; return 0; }
target=0x0c07825eu; r[16]=0x0c078252u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c078252u) { target=s->pc; goto dispatch; }
goto P_0c078252;
P_0c078250: /* original 64e3, guest PC 0x0c078250 */
if(!s->budget--) { s->failed_pc=0x0c078250u; return 0; }
r[4]=r[14];
goto P_0c078252;
P_0c078252: /* original 7f28, guest PC 0x0c078252 */
if(!s->budget--) { s->failed_pc=0x0c078252u; return 0; }
r[15]+=0x00000028u;
goto P_0c078254;
P_0c078254: /* original 7f08, guest PC 0x0c078254 */
if(!s->budget--) { s->failed_pc=0x0c078254u; return 0; }
r[15]+=0x00000008u;
goto P_0c078256;
P_0c078256: /* original 4f26, guest PC 0x0c078256 */
if(!s->budget--) { s->failed_pc=0x0c078256u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c078258;
P_0c078258: /* original 6df6, guest PC 0x0c078258 */
if(!s->budget--) { s->failed_pc=0x0c078258u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07825a;
P_0c07825a: /* original 000b, guest PC 0x0c07825a */
if(!s->budget--) { s->failed_pc=0x0c07825au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07825c: /* original 6ef6, guest PC 0x0c07825c */
if(!s->budget--) { s->failed_pc=0x0c07825cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07825eu,s,ram);
P_0c0786d8: /* original a3b0, guest PC 0x0c0786d8 */
if(!s->budget--) { s->failed_pc=0x0c0786d8u; return 0; }
goto P_0c078e3c;
P_0c0786da: /* original 0009, guest PC 0x0c0786da */
if(!s->budget--) { s->failed_pc=0x0c0786dau; return 0; }
return vf3_matrix_family(0x0c0786dcu,s,ram);
P_0c078e3c: /* original 90b3, guest PC 0x0c078e3c */
if(!s->budget--) { s->failed_pc=0x0c078e3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c078fa6u,2);
goto P_0c078e3e;
P_0c078e3e: /* original 02fe, guest PC 0x0c078e3e */
if(!s->budget--) { s->failed_pc=0x0c078e3eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c078e40;
P_0c078e40: /* original 90b1, guest PC 0x0c078e40 */
if(!s->budget--) { s->failed_pc=0x0c078e40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c078fa6u,2);
goto P_0c078e42;
P_0c078e42: /* original 7202, guest PC 0x0c078e42 */
if(!s->budget--) { s->failed_pc=0x0c078e42u; return 0; }
r[2]+=0x00000002u;
goto P_0c078e44;
P_0c078e44: /* original 01fe, guest PC 0x0c078e44 */
if(!s->budget--) { s->failed_pc=0x0c078e44u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c078e46;
P_0c078e46: /* original 6320, guest PC 0x0c078e46 */
if(!s->budget--) { s->failed_pc=0x0c078e46u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c078e48;
P_0c078e48: /* original 7101, guest PC 0x0c078e48 */
if(!s->budget--) { s->failed_pc=0x0c078e48u; return 0; }
r[1]+=0x00000001u;
goto P_0c078e4a;
P_0c078e4a: /* original d258, guest PC 0x0c078e4a */
if(!s->budget--) { s->failed_pc=0x0c078e4au; return 0; }
r[2]=read(ram,0x0c078facu,4);
goto P_0c078e4c;
P_0c078e4c: /* original 633c, guest PC 0x0c078e4c */
if(!s->budget--) { s->failed_pc=0x0c078e4cu; return 0; }
r[3]=r[3]&255u;
goto P_0c078e4e;
P_0c078e4e: /* original 6110, guest PC 0x0c078e4e */
if(!s->budget--) { s->failed_pc=0x0c078e4eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[1]=tmp;
goto P_0c078e50;
P_0c078e50: /* original 4318, guest PC 0x0c078e50 */
if(!s->budget--) { s->failed_pc=0x0c078e50u; return 0; }
r[3]<<=8;
goto P_0c078e52;
P_0c078e52: /* original 611c, guest PC 0x0c078e52 */
if(!s->budget--) { s->failed_pc=0x0c078e52u; return 0; }
r[1]=r[1]&255u;
goto P_0c078e54;
P_0c078e54: /* original 2329, guest PC 0x0c078e54 */
if(!s->budget--) { s->failed_pc=0x0c078e54u; return 0; }
r[3]&=r[2];
goto P_0c078e56;
P_0c078e56: /* original 231b, guest PC 0x0c078e56 */
if(!s->budget--) { s->failed_pc=0x0c078e56u; return 0; }
r[3]|=r[1];
goto P_0c078e58;
P_0c078e58: /* original 1f33, guest PC 0x0c078e58 */
if(!s->budget--) { s->failed_pc=0x0c078e58u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c078e5a;
P_0c078e5a: /* original 90a5, guest PC 0x0c078e5a */
if(!s->budget--) { s->failed_pc=0x0c078e5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c078fa8u,2);
goto P_0c078e5c;
P_0c078e5c: /* original 01fe, guest PC 0x0c078e5c */
if(!s->budget--) { s->failed_pc=0x0c078e5cu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c078e5e;
P_0c078e5e: /* original 3130, guest PC 0x0c078e5e */
if(!s->budget--) { s->failed_pc=0x0c078e5eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[3])!=0);
goto P_0c078e60;
P_0c078e60: /* original 8902, guest PC 0x0c078e60 */
if(!s->budget--) { s->failed_pc=0x0c078e60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c078e68; }
goto P_0c078e62;
P_0c078e62: /* original d153, guest PC 0x0c078e62 */
if(!s->budget--) { s->failed_pc=0x0c078e62u; return 0; }
r[1]=read(ram,0x0c078fb0u,4);
goto P_0c078e64;
P_0c078e64: /* original 412b, guest PC 0x0c078e64 */
if(!s->budget--) { s->failed_pc=0x0c078e64u; return 0; }
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
P_0c078e66: /* original 0009, guest PC 0x0c078e66 */
if(!s->budget--) { s->failed_pc=0x0c078e66u; return 0; }
goto P_0c078e68;
P_0c078e68: /* original e01b, guest PC 0x0c078e68 */
if(!s->budget--) { s->failed_pc=0x0c078e68u; return 0; }
r[0]=0x0000001bu;
goto P_0c078e6a;
P_0c078e6a: /* original 03cc, guest PC 0x0c078e6a */
if(!s->budget--) { s->failed_pc=0x0c078e6au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c078e6c;
P_0c078e6c: /* original e050, guest PC 0x0c078e6c */
if(!s->budget--) { s->failed_pc=0x0c078e6cu; return 0; }
r[0]=0x00000050u;
goto P_0c078e6e;
P_0c078e6e: /* original 633c, guest PC 0x0c078e6e */
if(!s->budget--) { s->failed_pc=0x0c078e6eu; return 0; }
r[3]=r[3]&255u;
goto P_0c078e70;
P_0c078e70: /* original 2338, guest PC 0x0c078e70 */
if(!s->budget--) { s->failed_pc=0x0c078e70u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c078e72;
P_0c078e72: /* original 8d03, guest PC 0x0c078e72 */
if(!s->budget--) { s->failed_pc=0x0c078e72u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+r[0],r[3],4);
if(cond) { goto P_0c078e7c; }
goto P_0c078e76;
P_0c078e74: /* original 0f36, guest PC 0x0c078e74 */
if(!s->budget--) { s->failed_pc=0x0c078e74u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c078e76;
P_0c078e76: /* original d24e, guest PC 0x0c078e76 */
if(!s->budget--) { s->failed_pc=0x0c078e76u; return 0; }
r[2]=read(ram,0x0c078fb0u,4);
goto P_0c078e78;
P_0c078e78: /* original 422b, guest PC 0x0c078e78 */
if(!s->budget--) { s->failed_pc=0x0c078e78u; return 0; }
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
P_0c078e7a: /* original 0009, guest PC 0x0c078e7a */
if(!s->budget--) { s->failed_pc=0x0c078e7au; return 0; }
goto P_0c078e7c;
P_0c078e7c: /* original 9093, guest PC 0x0c078e7c */
if(!s->budget--) { s->failed_pc=0x0c078e7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c078fa6u,2);
goto P_0c078e7e;
P_0c078e7e: /* original d34d, guest PC 0x0c078e7e */
if(!s->budget--) { s->failed_pc=0x0c078e7eu; return 0; }
r[3]=read(ram,0x0c078fb4u,4);
goto P_0c078e80;
P_0c078e80: /* original 02fe, guest PC 0x0c078e80 */
if(!s->budget--) { s->failed_pc=0x0c078e80u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c078e82;
P_0c078e82: /* original 432b, guest PC 0x0c078e82 */
if(!s->budget--) { s->failed_pc=0x0c078e82u; return 0; }
target=r[3];
r[2]+=0x00000003u;
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
P_0c078e84: /* original 7203, guest PC 0x0c078e84 */
if(!s->budget--) { s->failed_pc=0x0c078e84u; return 0; }
r[2]+=0x00000003u;
return vf3_matrix_family(0x0c078e86u,s,ram);
P_0c07ab14: /* original 4f22, guest PC 0x0c07ab14 */
if(!s->budget--) { s->failed_pc=0x0c07ab14u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ab16;
P_0c07ab16: /* original b54b, guest PC 0x0c07ab16 */
if(!s->budget--) { s->failed_pc=0x0c07ab16u; return 0; }
target=0x0c07b5b0u; r[16]=0x0c07ab1au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ab1au) { target=s->pc; goto dispatch; }
goto P_0c07ab1a;
P_0c07ab18: /* original 0009, guest PC 0x0c07ab18 */
if(!s->budget--) { s->failed_pc=0x0c07ab18u; return 0; }
goto P_0c07ab1a;
P_0c07ab1a: /* original 6403, guest PC 0x0c07ab1a */
if(!s->budget--) { s->failed_pc=0x0c07ab1au; return 0; }
r[4]=r[0];
goto P_0c07ab1c;
P_0c07ab1c: /* original 614d, guest PC 0x0c07ab1c */
if(!s->budget--) { s->failed_pc=0x0c07ab1cu; return 0; }
r[1]=r[4]&65535u;
goto P_0c07ab1e;
P_0c07ab1e: /* original 6013, guest PC 0x0c07ab1e */
if(!s->budget--) { s->failed_pc=0x0c07ab1eu; return 0; }
r[0]=r[1];
goto P_0c07ab20;
P_0c07ab20: /* original 880f, guest PC 0x0c07ab20 */
if(!s->budget--) { s->failed_pc=0x0c07ab20u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c07ab22;
P_0c07ab22: /* original 8b03, guest PC 0x0c07ab22 */
if(!s->budget--) { s->failed_pc=0x0c07ab22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ab2c; }
goto P_0c07ab24;
P_0c07ab24: /* original b564, guest PC 0x0c07ab24 */
if(!s->budget--) { s->failed_pc=0x0c07ab24u; return 0; }
target=0x0c07b5f0u; r[16]=0x0c07ab28u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ab28u) { target=s->pc; goto dispatch; }
goto P_0c07ab28;
P_0c07ab26: /* original 0009, guest PC 0x0c07ab26 */
if(!s->budget--) { s->failed_pc=0x0c07ab26u; return 0; }
goto P_0c07ab28;
P_0c07ab28: /* original a024, guest PC 0x0c07ab28 */
if(!s->budget--) { s->failed_pc=0x0c07ab28u; return 0; }
r[4]=0x00000024u;
goto P_0c07ab74;
P_0c07ab2a: /* original e424, guest PC 0x0c07ab2a */
if(!s->budget--) { s->failed_pc=0x0c07ab2au; return 0; }
r[4]=0x00000024u;
goto P_0c07ab2c;
P_0c07ab2c: /* original 8808, guest PC 0x0c07ab2c */
if(!s->budget--) { s->failed_pc=0x0c07ab2cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c07ab2e;
P_0c07ab2e: /* original 8902, guest PC 0x0c07ab2e */
if(!s->budget--) { s->failed_pc=0x0c07ab2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ab36; }
goto P_0c07ab30;
P_0c07ab30: /* original 6013, guest PC 0x0c07ab30 */
if(!s->budget--) { s->failed_pc=0x0c07ab30u; return 0; }
r[0]=r[1];
goto P_0c07ab32;
P_0c07ab32: /* original 8809, guest PC 0x0c07ab32 */
if(!s->budget--) { s->failed_pc=0x0c07ab32u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c07ab34;
P_0c07ab34: /* original 8b03, guest PC 0x0c07ab34 */
if(!s->budget--) { s->failed_pc=0x0c07ab34u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ab3e; }
goto P_0c07ab36;
P_0c07ab36: /* original b55b, guest PC 0x0c07ab36 */
if(!s->budget--) { s->failed_pc=0x0c07ab36u; return 0; }
target=0x0c07b5f0u; r[16]=0x0c07ab3au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ab3au) { target=s->pc; goto dispatch; }
goto P_0c07ab3a;
P_0c07ab38: /* original 0009, guest PC 0x0c07ab38 */
if(!s->budget--) { s->failed_pc=0x0c07ab38u; return 0; }
goto P_0c07ab3a;
P_0c07ab3a: /* original a011, guest PC 0x0c07ab3a */
if(!s->budget--) { s->failed_pc=0x0c07ab3au; return 0; }
r[4]=0x00000005u;
goto P_0c07ab60;
P_0c07ab3c: /* original e405, guest PC 0x0c07ab3c */
if(!s->budget--) { s->failed_pc=0x0c07ab3cu; return 0; }
r[4]=0x00000005u;
goto P_0c07ab3e;
P_0c07ab3e: /* original 880a, guest PC 0x0c07ab3e */
if(!s->budget--) { s->failed_pc=0x0c07ab3eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c07ab40;
P_0c07ab40: /* original 8902, guest PC 0x0c07ab40 */
if(!s->budget--) { s->failed_pc=0x0c07ab40u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ab48; }
goto P_0c07ab42;
P_0c07ab42: /* original 6013, guest PC 0x0c07ab42 */
if(!s->budget--) { s->failed_pc=0x0c07ab42u; return 0; }
r[0]=r[1];
goto P_0c07ab44;
P_0c07ab44: /* original 880b, guest PC 0x0c07ab44 */
if(!s->budget--) { s->failed_pc=0x0c07ab44u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c07ab46;
P_0c07ab46: /* original 8b04, guest PC 0x0c07ab46 */
if(!s->budget--) { s->failed_pc=0x0c07ab46u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ab52; }
goto P_0c07ab48;
P_0c07ab48: /* original b552, guest PC 0x0c07ab48 */
if(!s->budget--) { s->failed_pc=0x0c07ab48u; return 0; }
target=0x0c07b5f0u; r[16]=0x0c07ab4cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ab4cu) { target=s->pc; goto dispatch; }
goto P_0c07ab4c;
P_0c07ab4a: /* original 0009, guest PC 0x0c07ab4a */
if(!s->budget--) { s->failed_pc=0x0c07ab4au; return 0; }
goto P_0c07ab4c;
P_0c07ab4c: /* original e406, guest PC 0x0c07ab4c */
if(!s->budget--) { s->failed_pc=0x0c07ab4cu; return 0; }
r[4]=0x00000006u;
goto P_0c07ab4e;
P_0c07ab4e: /* original a011, guest PC 0x0c07ab4e */
if(!s->budget--) { s->failed_pc=0x0c07ab4eu; return 0; }
goto P_0c07ab74;
P_0c07ab50: /* original 0009, guest PC 0x0c07ab50 */
if(!s->budget--) { s->failed_pc=0x0c07ab50u; return 0; }
goto P_0c07ab52;
P_0c07ab52: /* original 8812, guest PC 0x0c07ab52 */
if(!s->budget--) { s->failed_pc=0x0c07ab52u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c07ab54;
P_0c07ab54: /* original 8b06, guest PC 0x0c07ab54 */
if(!s->budget--) { s->failed_pc=0x0c07ab54u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ab64; }
goto P_0c07ab56;
P_0c07ab56: /* original b54b, guest PC 0x0c07ab56 */
if(!s->budget--) { s->failed_pc=0x0c07ab56u; return 0; }
target=0x0c07b5f0u; r[16]=0x0c07ab5au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ab5au) { target=s->pc; goto dispatch; }
goto P_0c07ab5a;
P_0c07ab58: /* original 0009, guest PC 0x0c07ab58 */
if(!s->budget--) { s->failed_pc=0x0c07ab58u; return 0; }
goto P_0c07ab5a;
P_0c07ab5a: /* original b549, guest PC 0x0c07ab5a */
if(!s->budget--) { s->failed_pc=0x0c07ab5au; return 0; }
target=0x0c07b5f0u; r[16]=0x0c07ab5eu;
r[4]=0x00000023u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ab5eu) { target=s->pc; goto dispatch; }
goto P_0c07ab5e;
P_0c07ab5c: /* original e423, guest PC 0x0c07ab5c */
if(!s->budget--) { s->failed_pc=0x0c07ab5cu; return 0; }
r[4]=0x00000023u;
goto P_0c07ab5e;
P_0c07ab5e: /* original 943d, guest PC 0x0c07ab5e */
if(!s->budget--) { s->failed_pc=0x0c07ab5eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07abdcu,2);
goto P_0c07ab60;
P_0c07ab60: /* original a546, guest PC 0x0c07ab60 */
if(!s->budget--) { s->failed_pc=0x0c07ab60u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b5f0;
P_0c07ab62: /* original 4f26, guest PC 0x0c07ab62 */
if(!s->budget--) { s->failed_pc=0x0c07ab62u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ab64;
P_0c07ab64: /* original 6013, guest PC 0x0c07ab64 */
if(!s->budget--) { s->failed_pc=0x0c07ab64u; return 0; }
r[0]=r[1];
goto P_0c07ab66;
P_0c07ab66: /* original 8813, guest PC 0x0c07ab66 */
if(!s->budget--) { s->failed_pc=0x0c07ab66u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000013u)!=0);
goto P_0c07ab68;
P_0c07ab68: /* original 8b06, guest PC 0x0c07ab68 */
if(!s->budget--) { s->failed_pc=0x0c07ab68u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ab78; }
goto P_0c07ab6a;
P_0c07ab6a: /* original b541, guest PC 0x0c07ab6a */
if(!s->budget--) { s->failed_pc=0x0c07ab6au; return 0; }
target=0x0c07b5f0u; r[16]=0x0c07ab6eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ab6eu) { target=s->pc; goto dispatch; }
goto P_0c07ab6e;
P_0c07ab6c: /* original 0009, guest PC 0x0c07ab6c */
if(!s->budget--) { s->failed_pc=0x0c07ab6cu; return 0; }
goto P_0c07ab6e;
P_0c07ab6e: /* original b53f, guest PC 0x0c07ab6e */
if(!s->budget--) { s->failed_pc=0x0c07ab6eu; return 0; }
target=0x0c07b5f0u; r[16]=0x0c07ab72u;
r[4]=0x00000023u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ab72u) { target=s->pc; goto dispatch; }
goto P_0c07ab72;
P_0c07ab70: /* original e423, guest PC 0x0c07ab70 */
if(!s->budget--) { s->failed_pc=0x0c07ab70u; return 0; }
r[4]=0x00000023u;
goto P_0c07ab72;
P_0c07ab72: /* original e418, guest PC 0x0c07ab72 */
if(!s->budget--) { s->failed_pc=0x0c07ab72u; return 0; }
r[4]=0x00000018u;
goto P_0c07ab74;
P_0c07ab74: /* original a53c, guest PC 0x0c07ab74 */
if(!s->budget--) { s->failed_pc=0x0c07ab74u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b5f0;
P_0c07ab76: /* original 4f26, guest PC 0x0c07ab76 */
if(!s->budget--) { s->failed_pc=0x0c07ab76u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ab78;
P_0c07ab78: /* original 8814, guest PC 0x0c07ab78 */
if(!s->budget--) { s->failed_pc=0x0c07ab78u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000014u)!=0);
goto P_0c07ab7a;
P_0c07ab7a: /* original 8b02, guest PC 0x0c07ab7a */
if(!s->budget--) { s->failed_pc=0x0c07ab7au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ab82; }
goto P_0c07ab7c;
P_0c07ab7c: /* original b538, guest PC 0x0c07ab7c */
if(!s->budget--) { s->failed_pc=0x0c07ab7cu; return 0; }
target=0x0c07b5f0u; r[16]=0x0c07ab80u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ab80u) { target=s->pc; goto dispatch; }
goto P_0c07ab80;
P_0c07ab7e: /* original 0009, guest PC 0x0c07ab7e */
if(!s->budget--) { s->failed_pc=0x0c07ab7eu; return 0; }
goto P_0c07ab80;
P_0c07ab80: /* original e422, guest PC 0x0c07ab80 */
if(!s->budget--) { s->failed_pc=0x0c07ab80u; return 0; }
r[4]=0x00000022u;
goto P_0c07ab82;
P_0c07ab82: /* original a535, guest PC 0x0c07ab82 */
if(!s->budget--) { s->failed_pc=0x0c07ab82u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b5f0;
P_0c07ab84: /* original 4f26, guest PC 0x0c07ab84 */
if(!s->budget--) { s->failed_pc=0x0c07ab84u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c07ab86u,s,ram);
P_0c07b5f0: /* original 2fe6, guest PC 0x0c07b5f0 */
if(!s->budget--) { s->failed_pc=0x0c07b5f0u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07b5f2;
P_0c07b5f2: /* original 2fd6, guest PC 0x0c07b5f2 */
if(!s->budget--) { s->failed_pc=0x0c07b5f2u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c07b5f4;
P_0c07b5f4: /* original 6d43, guest PC 0x0c07b5f4 */
if(!s->budget--) { s->failed_pc=0x0c07b5f4u; return 0; }
r[13]=r[4];
goto P_0c07b5f6;
P_0c07b5f6: /* original 2fc6, guest PC 0x0c07b5f6 */
if(!s->budget--) { s->failed_pc=0x0c07b5f6u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c07b5f8;
P_0c07b5f8: /* original 4f22, guest PC 0x0c07b5f8 */
if(!s->budget--) { s->failed_pc=0x0c07b5f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b5fa;
P_0c07b5fa: /* original d22a, guest PC 0x0c07b5fa */
if(!s->budget--) { s->failed_pc=0x0c07b5fau; return 0; }
r[2]=read(ram,0x0c07b6a4u,4);
goto P_0c07b5fc;
P_0c07b5fc: /* original d32a, guest PC 0x0c07b5fc */
if(!s->budget--) { s->failed_pc=0x0c07b5fcu; return 0; }
r[3]=read(ram,0x0c07b6a8u,4);
goto P_0c07b5fe;
P_0c07b5fe: /* original 7fe0, guest PC 0x0c07b5fe */
if(!s->budget--) { s->failed_pc=0x0c07b5feu; return 0; }
r[15]+=0xffffffe0u;
goto P_0c07b600;
P_0c07b600: /* original 61f3, guest PC 0x0c07b600 */
if(!s->budget--) { s->failed_pc=0x0c07b600u; return 0; }
r[1]=r[15];
goto P_0c07b602;
P_0c07b602: /* original 430b, guest PC 0x0c07b602 */
if(!s->budget--) { s->failed_pc=0x0c07b602u; return 0; }
target=r[3];
r[16]=0x0c07b606u;
r[0]=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b606u) { target=s->pc; goto dispatch; }
goto P_0c07b606;
P_0c07b604: /* original e020, guest PC 0x0c07b604 */
if(!s->budget--) { s->failed_pc=0x0c07b604u; return 0; }
r[0]=0x00000020u;
goto P_0c07b606;
P_0c07b606: /* original 9149, guest PC 0x0c07b606 */
if(!s->budget--) { s->failed_pc=0x0c07b606u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69cu,2);
goto P_0c07b608;
P_0c07b608: /* original 6edd, guest PC 0x0c07b608 */
if(!s->budget--) { s->failed_pc=0x0c07b608u; return 0; }
r[14]=r[13]&65535u;
goto P_0c07b60a;
P_0c07b60a: /* original 21e8, guest PC 0x0c07b60a */
if(!s->budget--) { s->failed_pc=0x0c07b60au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[14])==0)!=0);
goto P_0c07b60c;
P_0c07b60c: /* original 8b29, guest PC 0x0c07b60c */
if(!s->budget--) { s->failed_pc=0x0c07b60cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b662; }
goto P_0c07b60e;
P_0c07b60e: /* original d227, guest PC 0x0c07b60e */
if(!s->budget--) { s->failed_pc=0x0c07b60eu; return 0; }
r[2]=read(ram,0x0c07b6acu,4);
goto P_0c07b610;
P_0c07b610: /* original 22e8, guest PC 0x0c07b610 */
if(!s->budget--) { s->failed_pc=0x0c07b610u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c07b612;
P_0c07b612: /* original 8b26, guest PC 0x0c07b612 */
if(!s->budget--) { s->failed_pc=0x0c07b612u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b662; }
goto P_0c07b614;
P_0c07b614: /* original 60e3, guest PC 0x0c07b614 */
if(!s->budget--) { s->failed_pc=0x0c07b614u; return 0; }
r[0]=r[14];
goto P_0c07b616;
P_0c07b616: /* original dc26, guest PC 0x0c07b616 */
if(!s->budget--) { s->failed_pc=0x0c07b616u; return 0; }
r[12]=read(ram,0x0c07b6b0u,4);
goto P_0c07b618;
P_0c07b618: /* original 8807, guest PC 0x0c07b618 */
if(!s->budget--) { s->failed_pc=0x0c07b618u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c07b61a;
P_0c07b61a: /* original 8b02, guest PC 0x0c07b61a */
if(!s->budget--) { s->failed_pc=0x0c07b61au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b622; }
goto P_0c07b61c;
P_0c07b61c: /* original 953f, guest PC 0x0c07b61c */
if(!s->budget--) { s->failed_pc=0x0c07b61cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69eu,2);
goto P_0c07b61e;
P_0c07b61e: /* original 4c0b, guest PC 0x0c07b61e */
if(!s->budget--) { s->failed_pc=0x0c07b61eu; return 0; }
target=r[12];
r[16]=0x0c07b622u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b622u) { target=s->pc; goto dispatch; }
goto P_0c07b622;
P_0c07b620: /* original e401, guest PC 0x0c07b620 */
if(!s->budget--) { s->failed_pc=0x0c07b620u; return 0; }
r[4]=0x00000001u;
goto P_0c07b622;
P_0c07b622: /* original 60e3, guest PC 0x0c07b622 */
if(!s->budget--) { s->failed_pc=0x0c07b622u; return 0; }
r[0]=r[14];
goto P_0c07b624;
P_0c07b624: /* original 8805, guest PC 0x0c07b624 */
if(!s->budget--) { s->failed_pc=0x0c07b624u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c07b626;
P_0c07b626: /* original 8b02, guest PC 0x0c07b626 */
if(!s->budget--) { s->failed_pc=0x0c07b626u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b62e; }
goto P_0c07b628;
P_0c07b628: /* original 953a, guest PC 0x0c07b628 */
if(!s->budget--) { s->failed_pc=0x0c07b628u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b6a0u,2);
goto P_0c07b62a;
P_0c07b62a: /* original 4c0b, guest PC 0x0c07b62a */
if(!s->budget--) { s->failed_pc=0x0c07b62au; return 0; }
target=r[12];
r[16]=0x0c07b62eu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b62eu) { target=s->pc; goto dispatch; }
goto P_0c07b62e;
P_0c07b62c: /* original e401, guest PC 0x0c07b62c */
if(!s->budget--) { s->failed_pc=0x0c07b62cu; return 0; }
r[4]=0x00000001u;
goto P_0c07b62e;
P_0c07b62e: /* original d021, guest PC 0x0c07b62e */
if(!s->budget--) { s->failed_pc=0x0c07b62eu; return 0; }
r[0]=read(ram,0x0c07b6b4u,4);
goto P_0c07b630;
P_0c07b630: /* original 64dd, guest PC 0x0c07b630 */
if(!s->budget--) { s->failed_pc=0x0c07b630u; return 0; }
r[4]=r[13]&65535u;
goto P_0c07b632;
P_0c07b632: /* original 4400, guest PC 0x0c07b632 */
if(!s->budget--) { s->failed_pc=0x0c07b632u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07b634;
P_0c07b634: /* original 044d, guest PC 0x0c07b634 */
if(!s->budget--) { s->failed_pc=0x0c07b634u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07b636;
P_0c07b636: /* original 644d, guest PC 0x0c07b636 */
if(!s->budget--) { s->failed_pc=0x0c07b636u; return 0; }
r[4]=r[4]&65535u;
goto P_0c07b638;
P_0c07b638: /* original 2448, guest PC 0x0c07b638 */
if(!s->budget--) { s->failed_pc=0x0c07b638u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07b63a;
P_0c07b63a: /* original 8912, guest PC 0x0c07b63a */
if(!s->budget--) { s->failed_pc=0x0c07b63au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b662; }
goto P_0c07b63c;
P_0c07b63c: /* original d21e, guest PC 0x0c07b63c */
if(!s->budget--) { s->failed_pc=0x0c07b63cu; return 0; }
r[2]=read(ram,0x0c07b6b8u,4);
goto P_0c07b63e;
P_0c07b63e: /* original 3420, guest PC 0x0c07b63e */
if(!s->budget--) { s->failed_pc=0x0c07b63eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c07b640;
P_0c07b640: /* original 890f, guest PC 0x0c07b640 */
if(!s->budget--) { s->failed_pc=0x0c07b640u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b662; }
goto P_0c07b642;
P_0c07b642: /* original d21e, guest PC 0x0c07b642 */
if(!s->budget--) { s->failed_pc=0x0c07b642u; return 0; }
r[2]=read(ram,0x0c07b6bcu,4);
goto P_0c07b644;
P_0c07b644: /* original 420b, guest PC 0x0c07b644 */
if(!s->budget--) { s->failed_pc=0x0c07b644u; return 0; }
target=r[2];
r[16]=0x0c07b648u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b648u) { target=s->pc; goto dispatch; }
goto P_0c07b648;
P_0c07b646: /* original 0009, guest PC 0x0c07b646 */
if(!s->budget--) { s->failed_pc=0x0c07b646u; return 0; }
goto P_0c07b648;
P_0c07b648: /* original d31d, guest PC 0x0c07b648 */
if(!s->budget--) { s->failed_pc=0x0c07b648u; return 0; }
r[3]=read(ram,0x0c07b6c0u,4);
goto P_0c07b64a;
P_0c07b64a: /* original 430b, guest PC 0x0c07b64a */
if(!s->budget--) { s->failed_pc=0x0c07b64au; return 0; }
target=r[3];
r[16]=0x0c07b64eu;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b64eu) { target=s->pc; goto dispatch; }
goto P_0c07b64e;
P_0c07b64c: /* original 64f3, guest PC 0x0c07b64c */
if(!s->budget--) { s->failed_pc=0x0c07b64cu; return 0; }
r[4]=r[15];
goto P_0c07b64e;
P_0c07b64e: /* original 2008, guest PC 0x0c07b64e */
if(!s->budget--) { s->failed_pc=0x0c07b64eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c07b650;
P_0c07b650: /* original 8902, guest PC 0x0c07b650 */
if(!s->budget--) { s->failed_pc=0x0c07b650u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b658; }
goto P_0c07b652;
P_0c07b652: /* original 9524, guest PC 0x0c07b652 */
if(!s->budget--) { s->failed_pc=0x0c07b652u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69eu,2);
goto P_0c07b654;
P_0c07b654: /* original 4c0b, guest PC 0x0c07b654 */
if(!s->budget--) { s->failed_pc=0x0c07b654u; return 0; }
target=r[12];
r[16]=0x0c07b658u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b658u) { target=s->pc; goto dispatch; }
goto P_0c07b658;
P_0c07b656: /* original e401, guest PC 0x0c07b656 */
if(!s->budget--) { s->failed_pc=0x0c07b656u; return 0; }
r[4]=0x00000001u;
goto P_0c07b658;
P_0c07b658: /* original d016, guest PC 0x0c07b658 */
if(!s->budget--) { s->failed_pc=0x0c07b658u; return 0; }
r[0]=read(ram,0x0c07b6b4u,4);
goto P_0c07b65a;
P_0c07b65a: /* original 6ddd, guest PC 0x0c07b65a */
if(!s->budget--) { s->failed_pc=0x0c07b65au; return 0; }
r[13]=r[13]&65535u;
goto P_0c07b65c;
P_0c07b65c: /* original e300, guest PC 0x0c07b65c */
if(!s->budget--) { s->failed_pc=0x0c07b65cu; return 0; }
r[3]=0x00000000u;
goto P_0c07b65e;
P_0c07b65e: /* original 4d00, guest PC 0x0c07b65e */
if(!s->budget--) { s->failed_pc=0x0c07b65eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07b660;
P_0c07b660: /* original 0d35, guest PC 0x0c07b660 */
if(!s->budget--) { s->failed_pc=0x0c07b660u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07b662;
P_0c07b662: /* original 7f20, guest PC 0x0c07b662 */
if(!s->budget--) { s->failed_pc=0x0c07b662u; return 0; }
r[15]+=0x00000020u;
goto P_0c07b664;
P_0c07b664: /* original 4f26, guest PC 0x0c07b664 */
if(!s->budget--) { s->failed_pc=0x0c07b664u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b666;
P_0c07b666: /* original 6cf6, guest PC 0x0c07b666 */
if(!s->budget--) { s->failed_pc=0x0c07b666u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07b668;
P_0c07b668: /* original 6df6, guest PC 0x0c07b668 */
if(!s->budget--) { s->failed_pc=0x0c07b668u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b66a;
P_0c07b66a: /* original 000b, guest PC 0x0c07b66a */
if(!s->budget--) { s->failed_pc=0x0c07b66au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b66c: /* original 6ef6, guest PC 0x0c07b66c */
if(!s->budget--) { s->failed_pc=0x0c07b66cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07b66eu,s,ram);
P_0c0865d6: /* original 4f22, guest PC 0x0c0865d6 */
if(!s->budget--) { s->failed_pc=0x0c0865d6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0865d8;
P_0c0865d8: /* original 7ff8, guest PC 0x0c0865d8 */
if(!s->budget--) { s->failed_pc=0x0c0865d8u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0865da;
P_0c0865da: /* original 1f41, guest PC 0x0c0865da */
if(!s->budget--) { s->failed_pc=0x0c0865dau; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0865dc;
P_0c0865dc: /* original 2f62, guest PC 0x0c0865dc */
if(!s->budget--) { s->failed_pc=0x0c0865dcu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0865de;
P_0c0865de: /* original d32c, guest PC 0x0c0865de */
if(!s->budget--) { s->failed_pc=0x0c0865deu; return 0; }
r[3]=read(ram,0x0c086690u,4);
goto P_0c0865e0;
P_0c0865e0: /* original 430b, guest PC 0x0c0865e0 */
if(!s->budget--) { s->failed_pc=0x0c0865e0u; return 0; }
target=r[3];
r[16]=0x0c0865e4u;
r[4]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0865e4u) { target=s->pc; goto dispatch; }
goto P_0c0865e4;
P_0c0865e2: /* original 6453, guest PC 0x0c0865e2 */
if(!s->budget--) { s->failed_pc=0x0c0865e2u; return 0; }
r[4]=r[5];
goto P_0c0865e4;
P_0c0865e4: /* original 54f1, guest PC 0x0c0865e4 */
if(!s->budget--) { s->failed_pc=0x0c0865e4u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0865e6;
P_0c0865e6: /* original 65e3, guest PC 0x0c0865e6 */
if(!s->budget--) { s->failed_pc=0x0c0865e6u; return 0; }
r[5]=r[14];
goto P_0c0865e8;
P_0c0865e8: /* original 66f2, guest PC 0x0c0865e8 */
if(!s->budget--) { s->failed_pc=0x0c0865e8u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c0865ea;
P_0c0865ea: /* original 7f08, guest PC 0x0c0865ea */
if(!s->budget--) { s->failed_pc=0x0c0865eau; return 0; }
r[15]+=0x00000008u;
goto P_0c0865ec;
P_0c0865ec: /* original 4f26, guest PC 0x0c0865ec */
if(!s->budget--) { s->failed_pc=0x0c0865ecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0865ee;
P_0c0865ee: /* original a0b6, guest PC 0x0c0865ee */
if(!s->budget--) { s->failed_pc=0x0c0865eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08675e;
P_0c0865f0: /* original 6ef6, guest PC 0x0c0865f0 */
if(!s->budget--) { s->failed_pc=0x0c0865f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0865f2u,s,ram);
P_0c086618: /* original 4f22, guest PC 0x0c086618 */
if(!s->budget--) { s->failed_pc=0x0c086618u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08661a;
P_0c08661a: /* original f231, guest PC 0x0c08661a */
if(!s->budget--) { s->failed_pc=0x0c08661au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c08661c;
P_0c08661c: /* original fe27, guest PC 0x0c08661c */
if(!s->budget--) { s->failed_pc=0x0c08661cu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c08661e;
P_0c08661e: /* original e044, guest PC 0x0c08661e */
if(!s->budget--) { s->failed_pc=0x0c08661eu; return 0; }
r[0]=0x00000044u;
goto P_0c086620;
P_0c086620: /* original f3e6, guest PC 0x0c086620 */
if(!s->budget--) { s->failed_pc=0x0c086620u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c086622;
P_0c086622: /* original e04c, guest PC 0x0c086622 */
if(!s->budget--) { s->failed_pc=0x0c086622u; return 0; }
r[0]=0x0000004cu;
goto P_0c086624;
P_0c086624: /* original ff30, guest PC 0x0c086624 */
if(!s->budget--) { s->failed_pc=0x0c086624u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c086626;
P_0c086626: /* original f3e6, guest PC 0x0c086626 */
if(!s->budget--) { s->failed_pc=0x0c086626u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c086628;
P_0c086628: /* original e048, guest PC 0x0c086628 */
if(!s->budget--) { s->failed_pc=0x0c086628u; return 0; }
r[0]=0x00000048u;
goto P_0c08662a;
P_0c08662a: /* original fe30, guest PC 0x0c08662a */
if(!s->budget--) { s->failed_pc=0x0c08662au; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'+');
goto P_0c08662c;
P_0c08662c: /* original f3e6, guest PC 0x0c08662c */
if(!s->budget--) { s->failed_pc=0x0c08662cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08662e;
P_0c08662e: /* original fd30, guest PC 0x0c08662e */
if(!s->budget--) { s->failed_pc=0x0c08662eu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'+');
goto P_0c086630;
P_0c086630: /* original f5ec, guest PC 0x0c086630 */
if(!s->budget--) { s->failed_pc=0x0c086630u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c086632;
P_0c086632: /* original d319, guest PC 0x0c086632 */
if(!s->budget--) { s->failed_pc=0x0c086632u; return 0; }
r[3]=read(ram,0x0c086698u,4);
goto P_0c086634;
P_0c086634: /* original f54d, guest PC 0x0c086634 */
if(!s->budget--) { s->failed_pc=0x0c086634u; return 0; }
fr[5]^=0x80000000u;
goto P_0c086636;
P_0c086636: /* original 430b, guest PC 0x0c086636 */
if(!s->budget--) { s->failed_pc=0x0c086636u; return 0; }
target=r[3];
r[16]=0x0c08663au;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08663au) { target=s->pc; goto dispatch; }
goto P_0c08663a;
P_0c086638: /* original f4fc, guest PC 0x0c086638 */
if(!s->budget--) { s->failed_pc=0x0c086638u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08663a;
P_0c08663a: /* original e060, guest PC 0x0c08663a */
if(!s->budget--) { s->failed_pc=0x0c08663au; return 0; }
r[0]=0x00000060u;
goto P_0c08663c;
P_0c08663c: /* original d517, guest PC 0x0c08663c */
if(!s->budget--) { s->failed_pc=0x0c08663cu; return 0; }
r[5]=read(ram,0x0c08669cu,4);
goto P_0c08663e;
P_0c08663e: /* original 00dc, guest PC 0x0c08663e */
if(!s->budget--) { s->failed_pc=0x0c08663eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c086640;
P_0c086640: /* original f40c, guest PC 0x0c086640 */
if(!s->budget--) { s->failed_pc=0x0c086640u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c086642;
P_0c086642: /* original 600c, guest PC 0x0c086642 */
if(!s->budget--) { s->failed_pc=0x0c086642u; return 0; }
r[0]=r[0]&255u;
goto P_0c086644;
P_0c086644: /* original 4008, guest PC 0x0c086644 */
if(!s->budget--) { s->failed_pc=0x0c086644u; return 0; }
r[0]<<=2;
goto P_0c086646;
P_0c086646: /* original f356, guest PC 0x0c086646 */
if(!s->budget--) { s->failed_pc=0x0c086646u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c086648;
P_0c086648: /* original f430, guest PC 0x0c086648 */
if(!s->budget--) { s->failed_pc=0x0c086648u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c08664a;
P_0c08664a: /* original fd45, guest PC 0x0c08664a */
if(!s->budget--) { s->failed_pc=0x0c08664au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[4]))!=0);
goto P_0c08664c;
P_0c08664c: /* original 8f28, guest PC 0x0c08664c */
if(!s->budget--) { s->failed_pc=0x0c08664cu; return 0; }
cond=r[17]&1u;
r[4]=0x00000001u;
if(!cond) { goto P_0c0866a0; }
goto P_0c086650;
P_0c08664e: /* original e401, guest PC 0x0c08664e */
if(!s->budget--) { s->failed_pc=0x0c08664eu; return 0; }
r[4]=0x00000001u;
goto P_0c086650;
P_0c086650: /* original 53ee, guest PC 0x0c086650 */
if(!s->budget--) { s->failed_pc=0x0c086650u; return 0; }
r[3]=read(ram,r[14]+56,4);
goto P_0c086652;
P_0c086652: /* original 2438, guest PC 0x0c086652 */
if(!s->budget--) { s->failed_pc=0x0c086652u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c086654;
P_0c086654: /* original 8b71, guest PC 0x0c086654 */
if(!s->budget--) { s->failed_pc=0x0c086654u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08673a; }
goto P_0c086656;
P_0c086656: /* original e32a, guest PC 0x0c086656 */
if(!s->budget--) { s->failed_pc=0x0c086656u; return 0; }
r[3]=0x0000002au;
goto P_0c086658;
P_0c086658: /* original 33ec, guest PC 0x0c086658 */
if(!s->budget--) { s->failed_pc=0x0c086658u; return 0; }
r[3]+=r[14];
goto P_0c08665a;
P_0c08665a: /* original e024, guest PC 0x0c08665a */
if(!s->budget--) { s->failed_pc=0x0c08665au; return 0; }
r[0]=0x00000024u;
goto P_0c08665c;
P_0c08665c: /* original 6331, guest PC 0x0c08665c */
if(!s->budget--) { s->failed_pc=0x0c08665cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c08665e;
P_0c08665e: /* original 02ed, guest PC 0x0c08665e */
if(!s->budget--) { s->failed_pc=0x0c08665eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c086660;
P_0c086660: /* original 323c, guest PC 0x0c086660 */
if(!s->budget--) { s->failed_pc=0x0c086660u; return 0; }
r[2]+=r[3];
goto P_0c086662;
P_0c086662: /* original e32c, guest PC 0x0c086662 */
if(!s->budget--) { s->failed_pc=0x0c086662u; return 0; }
r[3]=0x0000002cu;
goto P_0c086664;
P_0c086664: /* original 0e25, guest PC 0x0c086664 */
if(!s->budget--) { s->failed_pc=0x0c086664u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c086666;
P_0c086666: /* original 33ec, guest PC 0x0c086666 */
if(!s->budget--) { s->failed_pc=0x0c086666u; return 0; }
r[3]+=r[14];
goto P_0c086668;
P_0c086668: /* original e026, guest PC 0x0c086668 */
if(!s->budget--) { s->failed_pc=0x0c086668u; return 0; }
r[0]=0x00000026u;
goto P_0c08666a;
P_0c08666a: /* original 6331, guest PC 0x0c08666a */
if(!s->budget--) { s->failed_pc=0x0c08666au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c08666c;
P_0c08666c: /* original 02ed, guest PC 0x0c08666c */
if(!s->budget--) { s->failed_pc=0x0c08666cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08666e;
P_0c08666e: /* original 323c, guest PC 0x0c08666e */
if(!s->budget--) { s->failed_pc=0x0c08666eu; return 0; }
r[2]+=r[3];
goto P_0c086670;
P_0c086670: /* original e32e, guest PC 0x0c086670 */
if(!s->budget--) { s->failed_pc=0x0c086670u; return 0; }
r[3]=0x0000002eu;
goto P_0c086672;
P_0c086672: /* original 0e25, guest PC 0x0c086672 */
if(!s->budget--) { s->failed_pc=0x0c086672u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c086674;
P_0c086674: /* original 33ec, guest PC 0x0c086674 */
if(!s->budget--) { s->failed_pc=0x0c086674u; return 0; }
r[3]+=r[14];
goto P_0c086676;
P_0c086676: /* original e028, guest PC 0x0c086676 */
if(!s->budget--) { s->failed_pc=0x0c086676u; return 0; }
r[0]=0x00000028u;
goto P_0c086678;
P_0c086678: /* original 6331, guest PC 0x0c086678 */
if(!s->budget--) { s->failed_pc=0x0c086678u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c08667a;
P_0c08667a: /* original 02ed, guest PC 0x0c08667a */
if(!s->budget--) { s->failed_pc=0x0c08667au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08667c;
P_0c08667c: /* original 323c, guest PC 0x0c08667c */
if(!s->budget--) { s->failed_pc=0x0c08667cu; return 0; }
r[2]+=r[3];
goto P_0c08667e;
P_0c08667e: /* original a060, guest PC 0x0c08667e */
if(!s->budget--) { s->failed_pc=0x0c08667eu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c086742;
P_0c086680: /* original 0e25, guest PC 0x0c086680 */
if(!s->budget--) { s->failed_pc=0x0c086680u; return 0; }
write(ram,r[14]+r[0],r[2],2);
return vf3_matrix_family(0x0c086682u,s,ram);
P_0c0866a0: /* original e114, guest PC 0x0c0866a0 */
if(!s->budget--) { s->failed_pc=0x0c0866a0u; return 0; }
r[1]=0x00000014u;
goto P_0c0866a2;
P_0c0866a2: /* original fd4c, guest PC 0x0c0866a2 */
if(!s->budget--) { s->failed_pc=0x0c0866a2u; return 0; }
vf3_matrix_move(s,13,4);
goto P_0c0866a4;
P_0c0866a4: /* original 31cc, guest PC 0x0c0866a4 */
if(!s->budget--) { s->failed_pc=0x0c0866a4u; return 0; }
r[1]+=r[12];
goto P_0c0866a6;
P_0c0866a6: /* original e044, guest PC 0x0c0866a6 */
if(!s->budget--) { s->failed_pc=0x0c0866a6u; return 0; }
r[0]=0x00000044u;
goto P_0c0866a8;
P_0c0866a8: /* original f318, guest PC 0x0c0866a8 */
if(!s->budget--) { s->failed_pc=0x0c0866a8u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0866aa;
P_0c0866aa: /* original f2e6, guest PC 0x0c0866aa */
if(!s->budget--) { s->failed_pc=0x0c0866aau; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0866ac;
P_0c0866ac: /* original e110, guest PC 0x0c0866ac */
if(!s->budget--) { s->failed_pc=0x0c0866acu; return 0; }
r[1]=0x00000010u;
goto P_0c0866ae;
P_0c0866ae: /* original 31cc, guest PC 0x0c0866ae */
if(!s->budget--) { s->failed_pc=0x0c0866aeu; return 0; }
r[1]+=r[12];
goto P_0c0866b0;
P_0c0866b0: /* original f232, guest PC 0x0c0866b0 */
if(!s->budget--) { s->failed_pc=0x0c0866b0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0866b2;
P_0c0866b2: /* original fe27, guest PC 0x0c0866b2 */
if(!s->budget--) { s->failed_pc=0x0c0866b2u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0866b4;
P_0c0866b4: /* original e048, guest PC 0x0c0866b4 */
if(!s->budget--) { s->failed_pc=0x0c0866b4u; return 0; }
r[0]=0x00000048u;
goto P_0c0866b6;
P_0c0866b6: /* original f2e6, guest PC 0x0c0866b6 */
if(!s->budget--) { s->failed_pc=0x0c0866b6u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0866b8;
P_0c0866b8: /* original f318, guest PC 0x0c0866b8 */
if(!s->budget--) { s->failed_pc=0x0c0866b8u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0866ba;
P_0c0866ba: /* original f232, guest PC 0x0c0866ba */
if(!s->budget--) { s->failed_pc=0x0c0866bau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0866bc;
P_0c0866bc: /* original fe27, guest PC 0x0c0866bc */
if(!s->budget--) { s->failed_pc=0x0c0866bcu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0866be;
P_0c0866be: /* original d140, guest PC 0x0c0866be */
if(!s->budget--) { s->failed_pc=0x0c0866beu; return 0; }
r[1]=read(ram,0x0c0867c0u,4);
goto P_0c0866c0;
P_0c0866c0: /* original 415a, guest PC 0x0c0866c0 */
if(!s->budget--) { s->failed_pc=0x0c0866c0u; return 0; }
r[53]=r[1];
goto P_0c0866c2;
P_0c0866c2: /* original e114, guest PC 0x0c0866c2 */
if(!s->budget--) { s->failed_pc=0x0c0866c2u; return 0; }
r[1]=0x00000014u;
goto P_0c0866c4;
P_0c0866c4: /* original 31cc, guest PC 0x0c0866c4 */
if(!s->budget--) { s->failed_pc=0x0c0866c4u; return 0; }
r[1]+=r[12];
goto P_0c0866c6;
P_0c0866c6: /* original f30d, guest PC 0x0c0866c6 */
if(!s->budget--) { s->failed_pc=0x0c0866c6u; return 0; }
fr[3]=r[53];
goto P_0c0866c8;
P_0c0866c8: /* original f232, guest PC 0x0c0866c8 */
if(!s->budget--) { s->failed_pc=0x0c0866c8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0866ca;
P_0c0866ca: /* original fe27, guest PC 0x0c0866ca */
if(!s->budget--) { s->failed_pc=0x0c0866cau; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0866cc;
P_0c0866cc: /* original e04c, guest PC 0x0c0866cc */
if(!s->budget--) { s->failed_pc=0x0c0866ccu; return 0; }
r[0]=0x0000004cu;
goto P_0c0866ce;
P_0c0866ce: /* original f1e6, guest PC 0x0c0866ce */
if(!s->budget--) { s->failed_pc=0x0c0866ceu; return 0; }
vf3_matrix_load(s,ram,1,r[14]+r[0]);
goto P_0c0866d0;
P_0c0866d0: /* original f218, guest PC 0x0c0866d0 */
if(!s->budget--) { s->failed_pc=0x0c0866d0u; return 0; }
vf3_matrix_load(s,ram,2,r[1]);
goto P_0c0866d2;
P_0c0866d2: /* original f122, guest PC 0x0c0866d2 */
if(!s->budget--) { s->failed_pc=0x0c0866d2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0866d4;
P_0c0866d4: /* original fe17, guest PC 0x0c0866d4 */
if(!s->budget--) { s->failed_pc=0x0c0866d4u; return 0; }
vf3_matrix_store(s,ram,1,r[14]+r[0]);
goto P_0c0866d6;
P_0c0866d6: /* original c73b, guest PC 0x0c0866d6 */
if(!s->budget--) { s->failed_pc=0x0c0866d6u; return 0; }
r[0]=0x0c0867c4u;
goto P_0c0866d8;
P_0c0866d8: /* original f408, guest PC 0x0c0866d8 */
if(!s->budget--) { s->failed_pc=0x0c0866d8u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0866da;
P_0c0866da: /* original e044, guest PC 0x0c0866da */
if(!s->budget--) { s->failed_pc=0x0c0866dau; return 0; }
r[0]=0x00000044u;
goto P_0c0866dc;
P_0c0866dc: /* original f2e6, guest PC 0x0c0866dc */
if(!s->budget--) { s->failed_pc=0x0c0866dcu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0866de;
P_0c0866de: /* original f245, guest PC 0x0c0866de */
if(!s->budget--) { s->failed_pc=0x0c0866deu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c0866e0;
P_0c0866e0: /* original 8921, guest PC 0x0c0866e0 */
if(!s->budget--) { s->failed_pc=0x0c0866e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086726; }
goto P_0c0866e2;
P_0c0866e2: /* original e048, guest PC 0x0c0866e2 */
if(!s->budget--) { s->failed_pc=0x0c0866e2u; return 0; }
r[0]=0x00000048u;
goto P_0c0866e4;
P_0c0866e4: /* original f3e6, guest PC 0x0c0866e4 */
if(!s->budget--) { s->failed_pc=0x0c0866e4u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0866e6;
P_0c0866e6: /* original f345, guest PC 0x0c0866e6 */
if(!s->budget--) { s->failed_pc=0x0c0866e6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0866e8;
P_0c0866e8: /* original 891d, guest PC 0x0c0866e8 */
if(!s->budget--) { s->failed_pc=0x0c0866e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086726; }
goto P_0c0866ea;
P_0c0866ea: /* original e04c, guest PC 0x0c0866ea */
if(!s->budget--) { s->failed_pc=0x0c0866eau; return 0; }
r[0]=0x0000004cu;
goto P_0c0866ec;
P_0c0866ec: /* original f3e6, guest PC 0x0c0866ec */
if(!s->budget--) { s->failed_pc=0x0c0866ecu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0866ee;
P_0c0866ee: /* original f345, guest PC 0x0c0866ee */
if(!s->budget--) { s->failed_pc=0x0c0866eeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0866f0;
P_0c0866f0: /* original 8919, guest PC 0x0c0866f0 */
if(!s->budget--) { s->failed_pc=0x0c0866f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086726; }
goto P_0c0866f2;
P_0c0866f2: /* original 9062, guest PC 0x0c0866f2 */
if(!s->budget--) { s->failed_pc=0x0c0866f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0867bau,2);
goto P_0c0866f4;
P_0c0866f4: /* original e3fc, guest PC 0x0c0866f4 */
if(!s->budget--) { s->failed_pc=0x0c0866f4u; return 0; }
r[3]=0xfffffffcu;
goto P_0c0866f6;
P_0c0866f6: /* original 02de, guest PC 0x0c0866f6 */
if(!s->budget--) { s->failed_pc=0x0c0866f6u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c0866f8;
P_0c0866f8: /* original 2239, guest PC 0x0c0866f8 */
if(!s->budget--) { s->failed_pc=0x0c0866f8u; return 0; }
r[2]&=r[3];
goto P_0c0866fa;
P_0c0866fa: /* original 0d26, guest PC 0x0c0866fa */
if(!s->budget--) { s->failed_pc=0x0c0866fau; return 0; }
write(ram,r[13]+r[0],r[2],4);
goto P_0c0866fc;
P_0c0866fc: /* original e204, guest PC 0x0c0866fc */
if(!s->budget--) { s->failed_pc=0x0c0866fcu; return 0; }
r[2]=0x00000004u;
goto P_0c0866fe;
P_0c0866fe: /* original 01de, guest PC 0x0c0866fe */
if(!s->budget--) { s->failed_pc=0x0c0866feu; return 0; }
r[1]=read(ram,r[13]+r[0],4);
goto P_0c086700;
P_0c086700: /* original 212b, guest PC 0x0c086700 */
if(!s->budget--) { s->failed_pc=0x0c086700u; return 0; }
r[1]|=r[2];
goto P_0c086702;
P_0c086702: /* original 0d16, guest PC 0x0c086702 */
if(!s->budget--) { s->failed_pc=0x0c086702u; return 0; }
write(ram,r[13]+r[0],r[1],4);
goto P_0c086704;
P_0c086704: /* original e060, guest PC 0x0c086704 */
if(!s->budget--) { s->failed_pc=0x0c086704u; return 0; }
r[0]=0x00000060u;
goto P_0c086706;
P_0c086706: /* original 00dc, guest PC 0x0c086706 */
if(!s->budget--) { s->failed_pc=0x0c086706u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c086708;
P_0c086708: /* original 600c, guest PC 0x0c086708 */
if(!s->budget--) { s->failed_pc=0x0c086708u; return 0; }
r[0]=r[0]&255u;
goto P_0c08670a;
P_0c08670a: /* original 4008, guest PC 0x0c08670a */
if(!s->budget--) { s->failed_pc=0x0c08670au; return 0; }
r[0]<<=2;
goto P_0c08670c;
P_0c08670c: /* original f356, guest PC 0x0c08670c */
if(!s->budget--) { s->failed_pc=0x0c08670cu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c08670e;
P_0c08670e: /* original e014, guest PC 0x0c08670e */
if(!s->budget--) { s->failed_pc=0x0c08670eu; return 0; }
r[0]=0x00000014u;
goto P_0c086710;
P_0c086710: /* original f34d, guest PC 0x0c086710 */
if(!s->budget--) { s->failed_pc=0x0c086710u; return 0; }
fr[3]^=0x80000000u;
goto P_0c086712;
P_0c086712: /* original fe37, guest PC 0x0c086712 */
if(!s->budget--) { s->failed_pc=0x0c086712u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c086714;
P_0c086714: /* original c72c, guest PC 0x0c086714 */
if(!s->budget--) { s->failed_pc=0x0c086714u; return 0; }
r[0]=0x0c0867c8u;
goto P_0c086716;
P_0c086716: /* original f308, guest PC 0x0c086716 */
if(!s->budget--) { s->failed_pc=0x0c086716u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c086718;
P_0c086718: /* original e01c, guest PC 0x0c086718 */
if(!s->budget--) { s->failed_pc=0x0c086718u; return 0; }
r[0]=0x0000001cu;
goto P_0c08671a;
P_0c08671a: /* original fe37, guest PC 0x0c08671a */
if(!s->budget--) { s->failed_pc=0x0c08671au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08671c;
P_0c08671c: /* original d32b, guest PC 0x0c08671c */
if(!s->budget--) { s->failed_pc=0x0c08671cu; return 0; }
r[3]=read(ram,0x0c0867ccu,4);
goto P_0c08671e;
P_0c08671e: /* original 430b, guest PC 0x0c08671e */
if(!s->budget--) { s->failed_pc=0x0c08671eu; return 0; }
target=r[3];
r[16]=0x0c086722u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c086722u) { target=s->pc; goto dispatch; }
goto P_0c086722;
P_0c086720: /* original 64e3, guest PC 0x0c086720 */
if(!s->budget--) { s->failed_pc=0x0c086720u; return 0; }
r[4]=r[14];
goto P_0c086722;
P_0c086722: /* original a00a, guest PC 0x0c086722 */
if(!s->budget--) { s->failed_pc=0x0c086722u; return 0; }
goto P_0c08673a;
P_0c086724: /* original 0009, guest PC 0x0c086724 */
if(!s->budget--) { s->failed_pc=0x0c086724u; return 0; }
goto P_0c086726;
P_0c086726: /* original 53ee, guest PC 0x0c086726 */
if(!s->budget--) { s->failed_pc=0x0c086726u; return 0; }
r[3]=read(ram,r[14]+56,4);
goto P_0c086728;
P_0c086728: /* original 2348, guest PC 0x0c086728 */
if(!s->budget--) { s->failed_pc=0x0c086728u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c08672a;
P_0c08672a: /* original 8b06, guest PC 0x0c08672a */
if(!s->budget--) { s->failed_pc=0x0c08672au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08673a; }
goto P_0c08672c;
P_0c08672c: /* original 52ee, guest PC 0x0c08672c */
if(!s->budget--) { s->failed_pc=0x0c08672cu; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c08672e;
P_0c08672e: /* original 65e3, guest PC 0x0c08672e */
if(!s->budget--) { s->failed_pc=0x0c08672eu; return 0; }
r[5]=r[14];
goto P_0c086730;
P_0c086730: /* original 66d3, guest PC 0x0c086730 */
if(!s->budget--) { s->failed_pc=0x0c086730u; return 0; }
r[6]=r[13];
goto P_0c086732;
P_0c086732: /* original 224b, guest PC 0x0c086732 */
if(!s->budget--) { s->failed_pc=0x0c086732u; return 0; }
r[2]|=r[4];
goto P_0c086734;
P_0c086734: /* original 1e2e, guest PC 0x0c086734 */
if(!s->budget--) { s->failed_pc=0x0c086734u; return 0; }
write(ram,r[14]+56,r[2],4);
goto P_0c086736;
P_0c086736: /* original b09b, guest PC 0x0c086736 */
if(!s->budget--) { s->failed_pc=0x0c086736u; return 0; }
target=0x0c086870u; r[16]=0x0c08673au;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08673au) { target=s->pc; goto dispatch; }
goto P_0c08673a;
P_0c086738: /* original 64c3, guest PC 0x0c086738 */
if(!s->budget--) { s->failed_pc=0x0c086738u; return 0; }
r[4]=r[12];
goto P_0c08673a;
P_0c08673a: /* original 65e3, guest PC 0x0c08673a */
if(!s->budget--) { s->failed_pc=0x0c08673au; return 0; }
r[5]=r[14];
goto P_0c08673c;
P_0c08673c: /* original 66d3, guest PC 0x0c08673c */
if(!s->budget--) { s->failed_pc=0x0c08673cu; return 0; }
r[6]=r[13];
goto P_0c08673e;
P_0c08673e: /* original b00e, guest PC 0x0c08673e */
if(!s->budget--) { s->failed_pc=0x0c08673eu; return 0; }
target=0x0c08675eu; r[16]=0x0c086742u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c086742u) { target=s->pc; goto dispatch; }
goto P_0c086742;
P_0c086740: /* original 64c3, guest PC 0x0c086740 */
if(!s->budget--) { s->failed_pc=0x0c086740u; return 0; }
r[4]=r[12];
goto P_0c086742;
P_0c086742: /* original e004, guest PC 0x0c086742 */
if(!s->budget--) { s->failed_pc=0x0c086742u; return 0; }
r[0]=0x00000004u;
goto P_0c086744;
P_0c086744: /* original 4f26, guest PC 0x0c086744 */
if(!s->budget--) { s->failed_pc=0x0c086744u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c086746;
P_0c086746: /* original fef7, guest PC 0x0c086746 */
if(!s->budget--) { s->failed_pc=0x0c086746u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c086748;
P_0c086748: /* original e008, guest PC 0x0c086748 */
if(!s->budget--) { s->failed_pc=0x0c086748u; return 0; }
r[0]=0x00000008u;
goto P_0c08674a;
P_0c08674a: /* original fed7, guest PC 0x0c08674a */
if(!s->budget--) { s->failed_pc=0x0c08674au; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c08674c;
P_0c08674c: /* original e00c, guest PC 0x0c08674c */
if(!s->budget--) { s->failed_pc=0x0c08674cu; return 0; }
r[0]=0x0000000cu;
goto P_0c08674e;
P_0c08674e: /* original fee7, guest PC 0x0c08674e */
if(!s->budget--) { s->failed_pc=0x0c08674eu; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c086750;
P_0c086750: /* original fdf9, guest PC 0x0c086750 */
if(!s->budget--) { s->failed_pc=0x0c086750u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086752;
P_0c086752: /* original fef9, guest PC 0x0c086752 */
if(!s->budget--) { s->failed_pc=0x0c086752u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086754;
P_0c086754: /* original fff9, guest PC 0x0c086754 */
if(!s->budget--) { s->failed_pc=0x0c086754u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086756;
P_0c086756: /* original 6cf6, guest PC 0x0c086756 */
if(!s->budget--) { s->failed_pc=0x0c086756u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c086758;
P_0c086758: /* original 6df6, guest PC 0x0c086758 */
if(!s->budget--) { s->failed_pc=0x0c086758u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08675a;
P_0c08675a: /* original 000b, guest PC 0x0c08675a */
if(!s->budget--) { s->failed_pc=0x0c08675au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08675c: /* original 6ef6, guest PC 0x0c08675c */
if(!s->budget--) { s->failed_pc=0x0c08675cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08675e;
P_0c08675e: /* original e028, guest PC 0x0c08675e */
if(!s->budget--) { s->failed_pc=0x0c08675eu; return 0; }
r[0]=0x00000028u;
goto P_0c086760;
P_0c086760: /* original 6453, guest PC 0x0c086760 */
if(!s->budget--) { s->failed_pc=0x0c086760u; return 0; }
r[4]=r[5];
goto P_0c086762;
P_0c086762: /* original 034d, guest PC 0x0c086762 */
if(!s->budget--) { s->failed_pc=0x0c086762u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c086764;
P_0c086764: /* original e034, guest PC 0x0c086764 */
if(!s->budget--) { s->failed_pc=0x0c086764u; return 0; }
r[0]=0x00000034u;
goto P_0c086766;
P_0c086766: /* original 064d, guest PC 0x0c086766 */
if(!s->budget--) { s->failed_pc=0x0c086766u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c086768;
P_0c086768: /* original 3638, guest PC 0x0c086768 */
if(!s->budget--) { s->failed_pc=0x0c086768u; return 0; }
r[6]-=r[3];
goto P_0c08676a;
P_0c08676a: /* original 626f, guest PC 0x0c08676a */
if(!s->budget--) { s->failed_pc=0x0c08676au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c08676c;
P_0c08676c: /* original 4211, guest PC 0x0c08676c */
if(!s->budget--) { s->failed_pc=0x0c08676cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c08676e;
P_0c08676e: /* original 8900, guest PC 0x0c08676e */
if(!s->budget--) { s->failed_pc=0x0c08676eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086772; }
goto P_0c086770;
P_0c086770: /* original 666b, guest PC 0x0c086770 */
if(!s->budget--) { s->failed_pc=0x0c086770u; return 0; }
r[6]=0u-r[6];
goto P_0c086772;
P_0c086772: /* original 9523, guest PC 0x0c086772 */
if(!s->budget--) { s->failed_pc=0x0c086772u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0867bcu,2);
goto P_0c086774;
P_0c086774: /* original 666f, guest PC 0x0c086774 */
if(!s->budget--) { s->failed_pc=0x0c086774u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c086776;
P_0c086776: /* original 3653, guest PC 0x0c086776 */
if(!s->budget--) { s->failed_pc=0x0c086776u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[5])!=0);
goto P_0c086778;
P_0c086778: /* original 8b07, guest PC 0x0c086778 */
if(!s->budget--) { s->failed_pc=0x0c086778u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08678a; }
goto P_0c08677a;
P_0c08677a: /* original e32e, guest PC 0x0c08677a */
if(!s->budget--) { s->failed_pc=0x0c08677au; return 0; }
r[3]=0x0000002eu;
goto P_0c08677c;
P_0c08677c: /* original 334c, guest PC 0x0c08677c */
if(!s->budget--) { s->failed_pc=0x0c08677cu; return 0; }
r[3]+=r[4];
goto P_0c08677e;
P_0c08677e: /* original e028, guest PC 0x0c08677e */
if(!s->budget--) { s->failed_pc=0x0c08677eu; return 0; }
r[0]=0x00000028u;
goto P_0c086780;
P_0c086780: /* original 6331, guest PC 0x0c086780 */
if(!s->budget--) { s->failed_pc=0x0c086780u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c086782;
P_0c086782: /* original 024d, guest PC 0x0c086782 */
if(!s->budget--) { s->failed_pc=0x0c086782u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c086784;
P_0c086784: /* original 323c, guest PC 0x0c086784 */
if(!s->budget--) { s->failed_pc=0x0c086784u; return 0; }
r[2]+=r[3];
goto P_0c086786;
P_0c086786: /* original a004, guest PC 0x0c086786 */
if(!s->budget--) { s->failed_pc=0x0c086786u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c086792;
P_0c086788: /* original 0425, guest PC 0x0c086788 */
if(!s->budget--) { s->failed_pc=0x0c086788u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c08678a;
P_0c08678a: /* original e128, guest PC 0x0c08678a */
if(!s->budget--) { s->failed_pc=0x0c08678au; return 0; }
r[1]=0x00000028u;
goto P_0c08678c;
P_0c08678c: /* original 004d, guest PC 0x0c08678c */
if(!s->budget--) { s->failed_pc=0x0c08678cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08678e;
P_0c08678e: /* original 314c, guest PC 0x0c08678e */
if(!s->budget--) { s->failed_pc=0x0c08678eu; return 0; }
r[1]+=r[4];
goto P_0c086790;
P_0c086790: /* original 2101, guest PC 0x0c086790 */
if(!s->budget--) { s->failed_pc=0x0c086790u; return 0; }
write(ram,r[1],r[0],2);
goto P_0c086792;
P_0c086792: /* original e026, guest PC 0x0c086792 */
if(!s->budget--) { s->failed_pc=0x0c086792u; return 0; }
r[0]=0x00000026u;
goto P_0c086794;
P_0c086794: /* original 034d, guest PC 0x0c086794 */
if(!s->budget--) { s->failed_pc=0x0c086794u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c086796;
P_0c086796: /* original e032, guest PC 0x0c086796 */
if(!s->budget--) { s->failed_pc=0x0c086796u; return 0; }
r[0]=0x00000032u;
goto P_0c086798;
P_0c086798: /* original 064d, guest PC 0x0c086798 */
if(!s->budget--) { s->failed_pc=0x0c086798u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08679a;
P_0c08679a: /* original 3638, guest PC 0x0c08679a */
if(!s->budget--) { s->failed_pc=0x0c08679au; return 0; }
r[6]-=r[3];
goto P_0c08679c;
P_0c08679c: /* original 626f, guest PC 0x0c08679c */
if(!s->budget--) { s->failed_pc=0x0c08679cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c08679e;
P_0c08679e: /* original 4211, guest PC 0x0c08679e */
if(!s->budget--) { s->failed_pc=0x0c08679eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c0867a0;
P_0c0867a0: /* original 8900, guest PC 0x0c0867a0 */
if(!s->budget--) { s->failed_pc=0x0c0867a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0867a4; }
goto P_0c0867a2;
P_0c0867a2: /* original 666b, guest PC 0x0c0867a2 */
if(!s->budget--) { s->failed_pc=0x0c0867a2u; return 0; }
r[6]=0u-r[6];
goto P_0c0867a4;
P_0c0867a4: /* original 666f, guest PC 0x0c0867a4 */
if(!s->budget--) { s->failed_pc=0x0c0867a4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c0867a6;
P_0c0867a6: /* original 3653, guest PC 0x0c0867a6 */
if(!s->budget--) { s->failed_pc=0x0c0867a6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[5])!=0);
goto P_0c0867a8;
P_0c0867a8: /* original 8b12, guest PC 0x0c0867a8 */
if(!s->budget--) { s->failed_pc=0x0c0867a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0867d0; }
goto P_0c0867aa;
P_0c0867aa: /* original e32c, guest PC 0x0c0867aa */
if(!s->budget--) { s->failed_pc=0x0c0867aau; return 0; }
r[3]=0x0000002cu;
goto P_0c0867ac;
P_0c0867ac: /* original 334c, guest PC 0x0c0867ac */
if(!s->budget--) { s->failed_pc=0x0c0867acu; return 0; }
r[3]+=r[4];
goto P_0c0867ae;
P_0c0867ae: /* original e026, guest PC 0x0c0867ae */
if(!s->budget--) { s->failed_pc=0x0c0867aeu; return 0; }
r[0]=0x00000026u;
goto P_0c0867b0;
P_0c0867b0: /* original 6331, guest PC 0x0c0867b0 */
if(!s->budget--) { s->failed_pc=0x0c0867b0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c0867b2;
P_0c0867b2: /* original 024d, guest PC 0x0c0867b2 */
if(!s->budget--) { s->failed_pc=0x0c0867b2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0867b4;
P_0c0867b4: /* original 323c, guest PC 0x0c0867b4 */
if(!s->budget--) { s->failed_pc=0x0c0867b4u; return 0; }
r[2]+=r[3];
goto P_0c0867b6;
P_0c0867b6: /* original a00f, guest PC 0x0c0867b6 */
if(!s->budget--) { s->failed_pc=0x0c0867b6u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0867d8;
P_0c0867b8: /* original 0425, guest PC 0x0c0867b8 */
if(!s->budget--) { s->failed_pc=0x0c0867b8u; return 0; }
write(ram,r[4]+r[0],r[2],2);
return vf3_matrix_family(0x0c0867bau,s,ram);
P_0c0867d0: /* original e126, guest PC 0x0c0867d0 */
if(!s->budget--) { s->failed_pc=0x0c0867d0u; return 0; }
r[1]=0x00000026u;
goto P_0c0867d2;
P_0c0867d2: /* original 004d, guest PC 0x0c0867d2 */
if(!s->budget--) { s->failed_pc=0x0c0867d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0867d4;
P_0c0867d4: /* original 314c, guest PC 0x0c0867d4 */
if(!s->budget--) { s->failed_pc=0x0c0867d4u; return 0; }
r[1]+=r[4];
goto P_0c0867d6;
P_0c0867d6: /* original 2101, guest PC 0x0c0867d6 */
if(!s->budget--) { s->failed_pc=0x0c0867d6u; return 0; }
write(ram,r[1],r[0],2);
goto P_0c0867d8;
P_0c0867d8: /* original e024, guest PC 0x0c0867d8 */
if(!s->budget--) { s->failed_pc=0x0c0867d8u; return 0; }
r[0]=0x00000024u;
goto P_0c0867da;
P_0c0867da: /* original 034d, guest PC 0x0c0867da */
if(!s->budget--) { s->failed_pc=0x0c0867dau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0867dc;
P_0c0867dc: /* original e030, guest PC 0x0c0867dc */
if(!s->budget--) { s->failed_pc=0x0c0867dcu; return 0; }
r[0]=0x00000030u;
goto P_0c0867de;
P_0c0867de: /* original 064d, guest PC 0x0c0867de */
if(!s->budget--) { s->failed_pc=0x0c0867deu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0867e0;
P_0c0867e0: /* original 3638, guest PC 0x0c0867e0 */
if(!s->budget--) { s->failed_pc=0x0c0867e0u; return 0; }
r[6]-=r[3];
goto P_0c0867e2;
P_0c0867e2: /* original 626f, guest PC 0x0c0867e2 */
if(!s->budget--) { s->failed_pc=0x0c0867e2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c0867e4;
P_0c0867e4: /* original 4211, guest PC 0x0c0867e4 */
if(!s->budget--) { s->failed_pc=0x0c0867e4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c0867e6;
P_0c0867e6: /* original 8900, guest PC 0x0c0867e6 */
if(!s->budget--) { s->failed_pc=0x0c0867e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0867ea; }
goto P_0c0867e8;
P_0c0867e8: /* original 666b, guest PC 0x0c0867e8 */
if(!s->budget--) { s->failed_pc=0x0c0867e8u; return 0; }
r[6]=0u-r[6];
goto P_0c0867ea;
P_0c0867ea: /* original 666f, guest PC 0x0c0867ea */
if(!s->budget--) { s->failed_pc=0x0c0867eau; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c0867ec;
P_0c0867ec: /* original 3653, guest PC 0x0c0867ec */
if(!s->budget--) { s->failed_pc=0x0c0867ecu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[5])!=0);
goto P_0c0867ee;
P_0c0867ee: /* original 8b07, guest PC 0x0c0867ee */
if(!s->budget--) { s->failed_pc=0x0c0867eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086800; }
goto P_0c0867f0;
P_0c0867f0: /* original e32a, guest PC 0x0c0867f0 */
if(!s->budget--) { s->failed_pc=0x0c0867f0u; return 0; }
r[3]=0x0000002au;
goto P_0c0867f2;
P_0c0867f2: /* original 334c, guest PC 0x0c0867f2 */
if(!s->budget--) { s->failed_pc=0x0c0867f2u; return 0; }
r[3]+=r[4];
goto P_0c0867f4;
P_0c0867f4: /* original e024, guest PC 0x0c0867f4 */
if(!s->budget--) { s->failed_pc=0x0c0867f4u; return 0; }
r[0]=0x00000024u;
goto P_0c0867f6;
P_0c0867f6: /* original 6331, guest PC 0x0c0867f6 */
if(!s->budget--) { s->failed_pc=0x0c0867f6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[3]=tmp;
goto P_0c0867f8;
P_0c0867f8: /* original 024d, guest PC 0x0c0867f8 */
if(!s->budget--) { s->failed_pc=0x0c0867f8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0867fa;
P_0c0867fa: /* original 323c, guest PC 0x0c0867fa */
if(!s->budget--) { s->failed_pc=0x0c0867fau; return 0; }
r[2]+=r[3];
goto P_0c0867fc;
P_0c0867fc: /* original 000b, guest PC 0x0c0867fc */
if(!s->budget--) { s->failed_pc=0x0c0867fcu; return 0; }
target=r[16];
write(ram,r[4]+r[0],r[2],2);
s->pc=target; return ram->oob==0;
P_0c0867fe: /* original 0425, guest PC 0x0c0867fe */
if(!s->budget--) { s->failed_pc=0x0c0867feu; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c086800;
P_0c086800: /* original 014d, guest PC 0x0c086800 */
if(!s->budget--) { s->failed_pc=0x0c086800u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c086802;
P_0c086802: /* original e024, guest PC 0x0c086802 */
if(!s->budget--) { s->failed_pc=0x0c086802u; return 0; }
r[0]=0x00000024u;
goto P_0c086804;
P_0c086804: /* original 0415, guest PC 0x0c086804 */
if(!s->budget--) { s->failed_pc=0x0c086804u; return 0; }
write(ram,r[4]+r[0],r[1],2);
goto P_0c086806;
P_0c086806: /* original 000b, guest PC 0x0c086806 */
if(!s->budget--) { s->failed_pc=0x0c086806u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c086808: /* original 0009, guest PC 0x0c086808 */
if(!s->budget--) { s->failed_pc=0x0c086808u; return 0; }
return vf3_matrix_family(0x0c08680au,s,ram);
P_0c08b204: /* original 4f22, guest PC 0x0c08b204 */
if(!s->budget--) { s->failed_pc=0x0c08b204u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b206;
P_0c08b206: /* original 6030, guest PC 0x0c08b206 */
if(!s->budget--) { s->failed_pc=0x0c08b206u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c08b208;
P_0c08b208: /* original 600c, guest PC 0x0c08b208 */
if(!s->budget--) { s->failed_pc=0x0c08b208u; return 0; }
r[0]=r[0]&255u;
goto P_0c08b20a;
P_0c08b20a: /* original 2909, guest PC 0x0c08b20a */
if(!s->budget--) { s->failed_pc=0x0c08b20au; return 0; }
r[9]&=r[0];
goto P_0c08b20c;
P_0c08b20c: /* original 6a93, guest PC 0x0c08b20c */
if(!s->budget--) { s->failed_pc=0x0c08b20cu; return 0; }
r[10]=r[9];
goto P_0c08b20e;
P_0c08b20e: /* original 4a08, guest PC 0x0c08b20e */
if(!s->budget--) { s->failed_pc=0x0c08b20eu; return 0; }
r[10]<<=2;
goto P_0c08b210;
P_0c08b210: /* original 4a00, guest PC 0x0c08b210 */
if(!s->budget--) { s->failed_pc=0x0c08b210u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c08b212;
P_0c08b212: /* original 7ffc, guest PC 0x0c08b212 */
if(!s->budget--) { s->failed_pc=0x0c08b212u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08b214;
P_0c08b214: /* original 2fa2, guest PC 0x0c08b214 */
if(!s->budget--) { s->failed_pc=0x0c08b214u; return 0; }
write(ram,r[15],r[10],4);
goto P_0c08b216;
P_0c08b216: /* original d03e, guest PC 0x0c08b216 */
if(!s->budget--) { s->failed_pc=0x0c08b216u; return 0; }
r[0]=read(ram,0x0c08b310u,4);
goto P_0c08b218;
P_0c08b218: /* original 0aae, guest PC 0x0c08b218 */
if(!s->budget--) { s->failed_pc=0x0c08b218u; return 0; }
r[10]=read(ram,r[10]+r[0],4);
goto P_0c08b21a;
P_0c08b21a: /* original 2aa8, guest PC 0x0c08b21a */
if(!s->budget--) { s->failed_pc=0x0c08b21au; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c08b21c;
P_0c08b21c: /* original 895f, guest PC 0x0c08b21c */
if(!s->budget--) { s->failed_pc=0x0c08b21cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b2de; }
goto P_0c08b21e;
P_0c08b21e: /* original d13d, guest PC 0x0c08b21e */
if(!s->budget--) { s->failed_pc=0x0c08b21eu; return 0; }
r[1]=read(ram,0x0c08b314u,4);
goto P_0c08b220;
P_0c08b220: /* original 410b, guest PC 0x0c08b220 */
if(!s->budget--) { s->failed_pc=0x0c08b220u; return 0; }
target=r[1];
r[16]=0x0c08b224u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b224u) { target=s->pc; goto dispatch; }
goto P_0c08b224;
P_0c08b222: /* original e400, guest PC 0x0c08b222 */
if(!s->budget--) { s->failed_pc=0x0c08b222u; return 0; }
r[4]=0x00000000u;
goto P_0c08b224;
P_0c08b224: /* original 6cf2, guest PC 0x0c08b224 */
if(!s->budget--) { s->failed_pc=0x0c08b224u; return 0; }
tmp=read(ram,r[15],4);
r[12]=tmp;
goto P_0c08b226;
P_0c08b226: /* original d33a, guest PC 0x0c08b226 */
if(!s->budget--) { s->failed_pc=0x0c08b226u; return 0; }
r[3]=read(ram,0x0c08b310u,4);
goto P_0c08b228;
P_0c08b228: /* original d23b, guest PC 0x0c08b228 */
if(!s->budget--) { s->failed_pc=0x0c08b228u; return 0; }
r[2]=read(ram,0x0c08b318u,4);
goto P_0c08b22a;
P_0c08b22a: /* original 3c3c, guest PC 0x0c08b22a */
if(!s->budget--) { s->failed_pc=0x0c08b22au; return 0; }
r[12]+=r[3];
goto P_0c08b22c;
P_0c08b22c: /* original 420b, guest PC 0x0c08b22c */
if(!s->budget--) { s->failed_pc=0x0c08b22cu; return 0; }
target=r[2];
r[16]=0x0c08b230u;
r[12]=read(ram,r[12]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b230u) { target=s->pc; goto dispatch; }
goto P_0c08b230;
P_0c08b22e: /* original 5cc1, guest PC 0x0c08b22e */
if(!s->budget--) { s->failed_pc=0x0c08b22eu; return 0; }
r[12]=read(ram,r[12]+4,4);
goto P_0c08b230;
P_0c08b230: /* original c73a, guest PC 0x0c08b230 */
if(!s->budget--) { s->failed_pc=0x0c08b230u; return 0; }
r[0]=0x0c08b31cu;
goto P_0c08b232;
P_0c08b232: /* original db3d, guest PC 0x0c08b232 */
if(!s->budget--) { s->failed_pc=0x0c08b232u; return 0; }
r[11]=read(ram,0x0c08b328u,4);
goto P_0c08b234;
P_0c08b234: /* original fc08, guest PC 0x0c08b234 */
if(!s->budget--) { s->failed_pc=0x0c08b234u; return 0; }
vf3_matrix_load(s,ram,12,r[0]);
goto P_0c08b236;
P_0c08b236: /* original c73a, guest PC 0x0c08b236 */
if(!s->budget--) { s->failed_pc=0x0c08b236u; return 0; }
r[0]=0x0c08b320u;
goto P_0c08b238;
P_0c08b238: /* original fd08, guest PC 0x0c08b238 */
if(!s->budget--) { s->failed_pc=0x0c08b238u; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c08b23a;
P_0c08b23a: /* original c73a, guest PC 0x0c08b23a */
if(!s->budget--) { s->failed_pc=0x0c08b23au; return 0; }
r[0]=0x0c08b324u;
goto P_0c08b23c;
P_0c08b23c: /* original dd3b, guest PC 0x0c08b23c */
if(!s->budget--) { s->failed_pc=0x0c08b23cu; return 0; }
r[13]=read(ram,0x0c08b32cu,4);
goto P_0c08b23e;
P_0c08b23e: /* original 4a15, guest PC 0x0c08b23e */
if(!s->budget--) { s->failed_pc=0x0c08b23eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>0)!=0);
goto P_0c08b240;
P_0c08b240: /* original fe08, guest PC 0x0c08b240 */
if(!s->budget--) { s->failed_pc=0x0c08b240u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c08b242;
P_0c08b242: /* original ee00, guest PC 0x0c08b242 */
if(!s->budget--) { s->failed_pc=0x0c08b242u; return 0; }
r[14]=0x00000000u;
goto P_0c08b244;
P_0c08b244: /* original 8f3b, guest PC 0x0c08b244 */
if(!s->budget--) { s->failed_pc=0x0c08b244u; return 0; }
cond=r[17]&1u;
fr[15]=0x3f800000u;
if(!cond) { goto P_0c08b2be; }
goto P_0c08b248;
P_0c08b246: /* original ff9d, guest PC 0x0c08b246 */
if(!s->budget--) { s->failed_pc=0x0c08b246u; return 0; }
fr[15]=0x3f800000u;
goto P_0c08b248;
P_0c08b248: /* original 65e3, guest PC 0x0c08b248 */
if(!s->budget--) { s->failed_pc=0x0c08b248u; return 0; }
r[5]=r[14];
goto P_0c08b24a;
P_0c08b24a: /* original bf8d, guest PC 0x0c08b24a */
if(!s->budget--) { s->failed_pc=0x0c08b24au; return 0; }
target=0x0c08b168u; r[16]=0x0c08b24eu;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b24eu) { target=s->pc; goto dispatch; }
goto P_0c08b24e;
P_0c08b24c: /* original 6493, guest PC 0x0c08b24c */
if(!s->budget--) { s->failed_pc=0x0c08b24cu; return 0; }
r[4]=r[9];
goto P_0c08b24e;
P_0c08b24e: /* original 6403, guest PC 0x0c08b24e */
if(!s->budget--) { s->failed_pc=0x0c08b24eu; return 0; }
r[4]=r[0];
goto P_0c08b250;
P_0c08b250: /* original 604f, guest PC 0x0c08b250 */
if(!s->budget--) { s->failed_pc=0x0c08b250u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c08b252;
P_0c08b252: /* original 8800, guest PC 0x0c08b252 */
if(!s->budget--) { s->failed_pc=0x0c08b252u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c08b254;
P_0c08b254: /* original 8905, guest PC 0x0c08b254 */
if(!s->budget--) { s->failed_pc=0x0c08b254u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b262; }
goto P_0c08b256;
P_0c08b256: /* original 8801, guest PC 0x0c08b256 */
if(!s->budget--) { s->failed_pc=0x0c08b256u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08b258;
P_0c08b258: /* original 890a, guest PC 0x0c08b258 */
if(!s->budget--) { s->failed_pc=0x0c08b258u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b270; }
goto P_0c08b25a;
P_0c08b25a: /* original 8802, guest PC 0x0c08b25a */
if(!s->budget--) { s->failed_pc=0x0c08b25au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c08b25c;
P_0c08b25c: /* original 891d, guest PC 0x0c08b25c */
if(!s->budget--) { s->failed_pc=0x0c08b25cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b29a; }
goto P_0c08b25e;
P_0c08b25e: /* original a02a, guest PC 0x0c08b25e */
if(!s->budget--) { s->failed_pc=0x0c08b25eu; return 0; }
goto P_0c08b2b6;
P_0c08b260: /* original 0009, guest PC 0x0c08b260 */
if(!s->budget--) { s->failed_pc=0x0c08b260u; return 0; }
goto P_0c08b262;
P_0c08b262: /* original 60e3, guest PC 0x0c08b262 */
if(!s->budget--) { s->failed_pc=0x0c08b262u; return 0; }
r[0]=r[14];
goto P_0c08b264;
P_0c08b264: /* original 4008, guest PC 0x0c08b264 */
if(!s->budget--) { s->failed_pc=0x0c08b264u; return 0; }
r[0]<<=2;
goto P_0c08b266;
P_0c08b266: /* original f4d6, guest PC 0x0c08b266 */
if(!s->budget--) { s->failed_pc=0x0c08b266u; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c08b268;
P_0c08b268: /* original 4b0b, guest PC 0x0c08b268 */
if(!s->budget--) { s->failed_pc=0x0c08b268u; return 0; }
target=r[11];
r[16]=0x0c08b26cu;
tmp=read(ram,r[12],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b26cu) { target=s->pc; goto dispatch; }
goto P_0c08b26c;
P_0c08b26a: /* original 64c2, guest PC 0x0c08b26a */
if(!s->budget--) { s->failed_pc=0x0c08b26au; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c08b26c;
P_0c08b26c: /* original a023, guest PC 0x0c08b26c */
if(!s->budget--) { s->failed_pc=0x0c08b26cu; return 0; }
goto P_0c08b2b6;
P_0c08b26e: /* original 0009, guest PC 0x0c08b26e */
if(!s->budget--) { s->failed_pc=0x0c08b26eu; return 0; }
goto P_0c08b270;
P_0c08b270: /* original 68e3, guest PC 0x0c08b270 */
if(!s->budget--) { s->failed_pc=0x0c08b270u; return 0; }
r[8]=r[14];
goto P_0c08b272;
P_0c08b272: /* original 4808, guest PC 0x0c08b272 */
if(!s->budget--) { s->failed_pc=0x0c08b272u; return 0; }
r[8]<<=2;
goto P_0c08b274;
P_0c08b274: /* original 38dc, guest PC 0x0c08b274 */
if(!s->budget--) { s->failed_pc=0x0c08b274u; return 0; }
r[8]+=r[13];
goto P_0c08b276;
P_0c08b276: /* original f488, guest PC 0x0c08b276 */
if(!s->budget--) { s->failed_pc=0x0c08b276u; return 0; }
vf3_matrix_load(s,ram,4,r[8]);
goto P_0c08b278;
P_0c08b278: /* original 4b0b, guest PC 0x0c08b278 */
if(!s->budget--) { s->failed_pc=0x0c08b278u; return 0; }
target=r[11];
r[16]=0x0c08b27cu;
tmp=read(ram,r[12],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b27cu) { target=s->pc; goto dispatch; }
goto P_0c08b27c;
P_0c08b27a: /* original 64c2, guest PC 0x0c08b27a */
if(!s->budget--) { s->failed_pc=0x0c08b27au; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c08b27c;
P_0c08b27c: /* original c72c, guest PC 0x0c08b27c */
if(!s->budget--) { s->failed_pc=0x0c08b27cu; return 0; }
r[0]=0x0c08b330u;
goto P_0c08b27e;
P_0c08b27e: /* original f288, guest PC 0x0c08b27e */
if(!s->budget--) { s->failed_pc=0x0c08b27eu; return 0; }
vf3_matrix_load(s,ram,2,r[8]);
goto P_0c08b280;
P_0c08b280: /* original f308, guest PC 0x0c08b280 */
if(!s->budget--) { s->failed_pc=0x0c08b280u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08b282;
P_0c08b282: /* original f325, guest PC 0x0c08b282 */
if(!s->budget--) { s->failed_pc=0x0c08b282u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c08b284;
P_0c08b284: /* original 8b05, guest PC 0x0c08b284 */
if(!s->budget--) { s->failed_pc=0x0c08b284u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b292; }
goto P_0c08b286;
P_0c08b286: /* original 60e3, guest PC 0x0c08b286 */
if(!s->budget--) { s->failed_pc=0x0c08b286u; return 0; }
r[0]=r[14];
goto P_0c08b288;
P_0c08b288: /* original 4008, guest PC 0x0c08b288 */
if(!s->budget--) { s->failed_pc=0x0c08b288u; return 0; }
r[0]<<=2;
goto P_0c08b28a;
P_0c08b28a: /* original f3d6, guest PC 0x0c08b28a */
if(!s->budget--) { s->failed_pc=0x0c08b28au; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c08b28c;
P_0c08b28c: /* original f3e2, guest PC 0x0c08b28c */
if(!s->budget--) { s->failed_pc=0x0c08b28cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'*');
goto P_0c08b28e;
P_0c08b28e: /* original a012, guest PC 0x0c08b28e */
if(!s->budget--) { s->failed_pc=0x0c08b28eu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c08b2b6;
P_0c08b290: /* original fd37, guest PC 0x0c08b290 */
if(!s->budget--) { s->failed_pc=0x0c08b290u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c08b292;
P_0c08b292: /* original 60e3, guest PC 0x0c08b292 */
if(!s->budget--) { s->failed_pc=0x0c08b292u; return 0; }
r[0]=r[14];
goto P_0c08b294;
P_0c08b294: /* original 4008, guest PC 0x0c08b294 */
if(!s->budget--) { s->failed_pc=0x0c08b294u; return 0; }
r[0]<<=2;
goto P_0c08b296;
P_0c08b296: /* original a00e, guest PC 0x0c08b296 */
if(!s->budget--) { s->failed_pc=0x0c08b296u; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c08b2b6;
P_0c08b298: /* original fdf7, guest PC 0x0c08b298 */
if(!s->budget--) { s->failed_pc=0x0c08b298u; return 0; }
vf3_matrix_store(s,ram,15,r[13]+r[0]);
goto P_0c08b29a;
P_0c08b29a: /* original 68e3, guest PC 0x0c08b29a */
if(!s->budget--) { s->failed_pc=0x0c08b29au; return 0; }
r[8]=r[14];
goto P_0c08b29c;
P_0c08b29c: /* original 4808, guest PC 0x0c08b29c */
if(!s->budget--) { s->failed_pc=0x0c08b29cu; return 0; }
r[8]<<=2;
goto P_0c08b29e;
P_0c08b29e: /* original 38dc, guest PC 0x0c08b29e */
if(!s->budget--) { s->failed_pc=0x0c08b29eu; return 0; }
r[8]+=r[13];
goto P_0c08b2a0;
P_0c08b2a0: /* original f488, guest PC 0x0c08b2a0 */
if(!s->budget--) { s->failed_pc=0x0c08b2a0u; return 0; }
vf3_matrix_load(s,ram,4,r[8]);
goto P_0c08b2a2;
P_0c08b2a2: /* original 4b0b, guest PC 0x0c08b2a2 */
if(!s->budget--) { s->failed_pc=0x0c08b2a2u; return 0; }
target=r[11];
r[16]=0x0c08b2a6u;
tmp=read(ram,r[12],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b2a6u) { target=s->pc; goto dispatch; }
goto P_0c08b2a6;
P_0c08b2a4: /* original 64c2, guest PC 0x0c08b2a4 */
if(!s->budget--) { s->failed_pc=0x0c08b2a4u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c08b2a6;
P_0c08b2a6: /* original f388, guest PC 0x0c08b2a6 */
if(!s->budget--) { s->failed_pc=0x0c08b2a6u; return 0; }
vf3_matrix_load(s,ram,3,r[8]);
goto P_0c08b2a8;
P_0c08b2a8: /* original f3d5, guest PC 0x0c08b2a8 */
if(!s->budget--) { s->failed_pc=0x0c08b2a8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[13]))!=0);
goto P_0c08b2aa;
P_0c08b2aa: /* original 8b04, guest PC 0x0c08b2aa */
if(!s->budget--) { s->failed_pc=0x0c08b2aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b2b6; }
goto P_0c08b2ac;
P_0c08b2ac: /* original 60e3, guest PC 0x0c08b2ac */
if(!s->budget--) { s->failed_pc=0x0c08b2acu; return 0; }
r[0]=r[14];
goto P_0c08b2ae;
P_0c08b2ae: /* original 4008, guest PC 0x0c08b2ae */
if(!s->budget--) { s->failed_pc=0x0c08b2aeu; return 0; }
r[0]<<=2;
goto P_0c08b2b0;
P_0c08b2b0: /* original f3d6, guest PC 0x0c08b2b0 */
if(!s->budget--) { s->failed_pc=0x0c08b2b0u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c08b2b2;
P_0c08b2b2: /* original f3c2, guest PC 0x0c08b2b2 */
if(!s->budget--) { s->failed_pc=0x0c08b2b2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'*');
goto P_0c08b2b4;
P_0c08b2b4: /* original fd37, guest PC 0x0c08b2b4 */
if(!s->budget--) { s->failed_pc=0x0c08b2b4u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c08b2b6;
P_0c08b2b6: /* original 7e01, guest PC 0x0c08b2b6 */
if(!s->budget--) { s->failed_pc=0x0c08b2b6u; return 0; }
r[14]+=0x00000001u;
goto P_0c08b2b8;
P_0c08b2b8: /* original 3ea3, guest PC 0x0c08b2b8 */
if(!s->budget--) { s->failed_pc=0x0c08b2b8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[10])!=0);
goto P_0c08b2ba;
P_0c08b2ba: /* original 8fc5, guest PC 0x0c08b2ba */
if(!s->budget--) { s->failed_pc=0x0c08b2bau; return 0; }
cond=r[17]&1u;
r[12]+=0x00000004u;
if(!cond) { goto P_0c08b248; }
goto P_0c08b2be;
P_0c08b2bc: /* original 7c04, guest PC 0x0c08b2bc */
if(!s->budget--) { s->failed_pc=0x0c08b2bcu; return 0; }
r[12]+=0x00000004u;
goto P_0c08b2be;
P_0c08b2be: /* original 7f04, guest PC 0x0c08b2be */
if(!s->budget--) { s->failed_pc=0x0c08b2beu; return 0; }
r[15]+=0x00000004u;
goto P_0c08b2c0;
P_0c08b2c0: /* original d31c, guest PC 0x0c08b2c0 */
if(!s->budget--) { s->failed_pc=0x0c08b2c0u; return 0; }
r[3]=read(ram,0x0c08b334u,4);
goto P_0c08b2c2;
P_0c08b2c2: /* original 4f26, guest PC 0x0c08b2c2 */
if(!s->budget--) { s->failed_pc=0x0c08b2c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b2c4;
P_0c08b2c4: /* original e401, guest PC 0x0c08b2c4 */
if(!s->budget--) { s->failed_pc=0x0c08b2c4u; return 0; }
r[4]=0x00000001u;
goto P_0c08b2c6;
P_0c08b2c6: /* original fcf9, guest PC 0x0c08b2c6 */
if(!s->budget--) { s->failed_pc=0x0c08b2c6u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b2c8;
P_0c08b2c8: /* original fdf9, guest PC 0x0c08b2c8 */
if(!s->budget--) { s->failed_pc=0x0c08b2c8u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b2ca;
P_0c08b2ca: /* original fef9, guest PC 0x0c08b2ca */
if(!s->budget--) { s->failed_pc=0x0c08b2cau; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b2cc;
P_0c08b2cc: /* original fff9, guest PC 0x0c08b2cc */
if(!s->budget--) { s->failed_pc=0x0c08b2ccu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b2ce;
P_0c08b2ce: /* original 68f6, guest PC 0x0c08b2ce */
if(!s->budget--) { s->failed_pc=0x0c08b2ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08b2d0;
P_0c08b2d0: /* original 69f6, guest PC 0x0c08b2d0 */
if(!s->budget--) { s->failed_pc=0x0c08b2d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08b2d2;
P_0c08b2d2: /* original 6af6, guest PC 0x0c08b2d2 */
if(!s->budget--) { s->failed_pc=0x0c08b2d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08b2d4;
P_0c08b2d4: /* original 6bf6, guest PC 0x0c08b2d4 */
if(!s->budget--) { s->failed_pc=0x0c08b2d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08b2d6;
P_0c08b2d6: /* original 6cf6, guest PC 0x0c08b2d6 */
if(!s->budget--) { s->failed_pc=0x0c08b2d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08b2d8;
P_0c08b2d8: /* original 6df6, guest PC 0x0c08b2d8 */
if(!s->budget--) { s->failed_pc=0x0c08b2d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08b2da;
P_0c08b2da: /* original 432b, guest PC 0x0c08b2da */
if(!s->budget--) { s->failed_pc=0x0c08b2dau; return 0; }
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
P_0c08b2dc: /* original 6ef6, guest PC 0x0c08b2dc */
if(!s->budget--) { s->failed_pc=0x0c08b2dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08b2de;
P_0c08b2de: /* original 7f04, guest PC 0x0c08b2de */
if(!s->budget--) { s->failed_pc=0x0c08b2deu; return 0; }
r[15]+=0x00000004u;
goto P_0c08b2e0;
P_0c08b2e0: /* original 4f26, guest PC 0x0c08b2e0 */
if(!s->budget--) { s->failed_pc=0x0c08b2e0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b2e2;
P_0c08b2e2: /* original fcf9, guest PC 0x0c08b2e2 */
if(!s->budget--) { s->failed_pc=0x0c08b2e2u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b2e4;
P_0c08b2e4: /* original fdf9, guest PC 0x0c08b2e4 */
if(!s->budget--) { s->failed_pc=0x0c08b2e4u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b2e6;
P_0c08b2e6: /* original fef9, guest PC 0x0c08b2e6 */
if(!s->budget--) { s->failed_pc=0x0c08b2e6u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b2e8;
P_0c08b2e8: /* original fff9, guest PC 0x0c08b2e8 */
if(!s->budget--) { s->failed_pc=0x0c08b2e8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b2ea;
P_0c08b2ea: /* original 68f6, guest PC 0x0c08b2ea */
if(!s->budget--) { s->failed_pc=0x0c08b2eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08b2ec;
P_0c08b2ec: /* original 69f6, guest PC 0x0c08b2ec */
if(!s->budget--) { s->failed_pc=0x0c08b2ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08b2ee;
P_0c08b2ee: /* original 6af6, guest PC 0x0c08b2ee */
if(!s->budget--) { s->failed_pc=0x0c08b2eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08b2f0;
P_0c08b2f0: /* original 6bf6, guest PC 0x0c08b2f0 */
if(!s->budget--) { s->failed_pc=0x0c08b2f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08b2f2;
P_0c08b2f2: /* original 6cf6, guest PC 0x0c08b2f2 */
if(!s->budget--) { s->failed_pc=0x0c08b2f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08b2f4;
P_0c08b2f4: /* original 6df6, guest PC 0x0c08b2f4 */
if(!s->budget--) { s->failed_pc=0x0c08b2f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08b2f6;
P_0c08b2f6: /* original 000b, guest PC 0x0c08b2f6 */
if(!s->budget--) { s->failed_pc=0x0c08b2f6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b2f8: /* original 6ef6, guest PC 0x0c08b2f8 */
if(!s->budget--) { s->failed_pc=0x0c08b2f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08b2fau,s,ram);
P_0c08b448: /* original 4f22, guest PC 0x0c08b448 */
if(!s->budget--) { s->failed_pc=0x0c08b448u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b44a;
P_0c08b44a: /* original 4f12, guest PC 0x0c08b44a */
if(!s->budget--) { s->failed_pc=0x0c08b44au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c08b44c;
P_0c08b44c: /* original 7ff8, guest PC 0x0c08b44c */
if(!s->budget--) { s->failed_pc=0x0c08b44cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c08b44e;
P_0c08b44e: /* original 1f61, guest PC 0x0c08b44e */
if(!s->budget--) { s->failed_pc=0x0c08b44eu; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c08b450;
P_0c08b450: /* original 2f72, guest PC 0x0c08b450 */
if(!s->budget--) { s->failed_pc=0x0c08b450u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c08b452;
P_0c08b452: /* original d22d, guest PC 0x0c08b452 */
if(!s->budget--) { s->failed_pc=0x0c08b452u; return 0; }
r[2]=read(ram,0x0c08b508u,4);
goto P_0c08b454;
P_0c08b454: /* original 9353, guest PC 0x0c08b454 */
if(!s->budget--) { s->failed_pc=0x0c08b454u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b4feu,2);
goto P_0c08b456;
P_0c08b456: /* original 6822, guest PC 0x0c08b456 */
if(!s->budget--) { s->failed_pc=0x0c08b456u; return 0; }
tmp=read(ram,r[2],4);
r[8]=tmp;
goto P_0c08b458;
P_0c08b458: /* original 9d50, guest PC 0x0c08b458 */
if(!s->budget--) { s->failed_pc=0x0c08b458u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08b4fcu,2);
goto P_0c08b45a;
P_0c08b45a: /* original 2838, guest PC 0x0c08b45a */
if(!s->budget--) { s->failed_pc=0x0c08b45au; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c08b45c;
P_0c08b45c: /* original 3d4c, guest PC 0x0c08b45c */
if(!s->budget--) { s->failed_pc=0x0c08b45cu; return 0; }
r[13]+=r[4];
goto P_0c08b45e;
P_0c08b45e: /* original 8d05, guest PC 0x0c08b45e */
if(!s->budget--) { s->failed_pc=0x0c08b45eu; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]=tmp;
if(cond) { goto P_0c08b46c; }
goto P_0c08b462;
P_0c08b460: /* original 6ee0, guest PC 0x0c08b460 */
if(!s->budget--) { s->failed_pc=0x0c08b460u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]=tmp;
goto P_0c08b462;
P_0c08b462: /* original 60c3, guest PC 0x0c08b462 */
if(!s->budget--) { s->failed_pc=0x0c08b462u; return 0; }
r[0]=r[12];
goto P_0c08b464;
P_0c08b464: /* original 8810, guest PC 0x0c08b464 */
if(!s->budget--) { s->failed_pc=0x0c08b464u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c08b466;
P_0c08b466: /* original 8b01, guest PC 0x0c08b466 */
if(!s->budget--) { s->failed_pc=0x0c08b466u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b46c; }
goto P_0c08b468;
P_0c08b468: /* original a001, guest PC 0x0c08b468 */
if(!s->budget--) { s->failed_pc=0x0c08b468u; return 0; }
r[8]=0x00000001u;
goto P_0c08b46e;
P_0c08b46a: /* original e801, guest PC 0x0c08b46a */
if(!s->budget--) { s->failed_pc=0x0c08b46au; return 0; }
r[8]=0x00000001u;
goto P_0c08b46c;
P_0c08b46c: /* original e800, guest PC 0x0c08b46c */
if(!s->budget--) { s->failed_pc=0x0c08b46cu; return 0; }
r[8]=0x00000000u;
goto P_0c08b46e;
P_0c08b46e: /* original da27, guest PC 0x0c08b46e */
if(!s->budget--) { s->failed_pc=0x0c08b46eu; return 0; }
r[10]=read(ram,0x0c08b50cu,4);
goto P_0c08b470;
P_0c08b470: /* original c727, guest PC 0x0c08b470 */
if(!s->budget--) { s->failed_pc=0x0c08b470u; return 0; }
r[0]=0x0c08b510u;
goto P_0c08b472;
P_0c08b472: /* original a024, guest PC 0x0c08b472 */
if(!s->budget--) { s->failed_pc=0x0c08b472u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08b4be;
P_0c08b474: /* original ff08, guest PC 0x0c08b474 */
if(!s->budget--) { s->failed_pc=0x0c08b474u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c08b476;
P_0c08b476: /* original 2888, guest PC 0x0c08b476 */
if(!s->budget--) { s->failed_pc=0x0c08b476u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c08b478;
P_0c08b478: /* original 8905, guest PC 0x0c08b478 */
if(!s->budget--) { s->failed_pc=0x0c08b478u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b486; }
goto P_0c08b47a;
P_0c08b47a: /* original d326, guest PC 0x0c08b47a */
if(!s->budget--) { s->failed_pc=0x0c08b47au; return 0; }
r[3]=read(ram,0x0c08b514u,4);
goto P_0c08b47c;
P_0c08b47c: /* original 430b, guest PC 0x0c08b47c */
if(!s->budget--) { s->failed_pc=0x0c08b47cu; return 0; }
target=r[3];
r[16]=0x0c08b480u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b480u) { target=s->pc; goto dispatch; }
goto P_0c08b480;
P_0c08b47e: /* original 0009, guest PC 0x0c08b47e */
if(!s->budget--) { s->failed_pc=0x0c08b47eu; return 0; }
goto P_0c08b480;
P_0c08b480: /* original f40c, guest PC 0x0c08b480 */
if(!s->budget--) { s->failed_pc=0x0c08b480u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c08b482;
P_0c08b482: /* original f4f5, guest PC 0x0c08b482 */
if(!s->budget--) { s->failed_pc=0x0c08b482u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[15]))!=0);
goto P_0c08b484;
P_0c08b484: /* original 891e, guest PC 0x0c08b484 */
if(!s->budget--) { s->failed_pc=0x0c08b484u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b4c4; }
goto P_0c08b486;
P_0c08b486: /* original 60ee, guest PC 0x0c08b486 */
if(!s->budget--) { s->failed_pc=0x0c08b486u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c08b488;
P_0c08b488: /* original 7eff, guest PC 0x0c08b488 */
if(!s->budget--) { s->failed_pc=0x0c08b488u; return 0; }
r[14]+=0xffffffffu;
goto P_0c08b48a;
P_0c08b48a: /* original 6eee, guest PC 0x0c08b48a */
if(!s->budget--) { s->failed_pc=0x0c08b48au; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c08b48c;
P_0c08b48c: /* original e31c, guest PC 0x0c08b48c */
if(!s->budget--) { s->failed_pc=0x0c08b48cu; return 0; }
r[3]=0x0000001cu;
goto P_0c08b48e;
P_0c08b48e: /* original 2e3f, guest PC 0x0c08b48e */
if(!s->budget--) { s->failed_pc=0x0c08b48eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c08b490;
P_0c08b490: /* original 4008, guest PC 0x0c08b490 */
if(!s->budget--) { s->failed_pc=0x0c08b490u; return 0; }
r[0]<<=2;
goto P_0c08b492;
P_0c08b492: /* original 09d6, guest PC 0x0c08b492 */
if(!s->budget--) { s->failed_pc=0x0c08b492u; return 0; }
write(ram,r[9]+r[0],r[13],4);
goto P_0c08b494;
P_0c08b494: /* original 52f1, guest PC 0x0c08b494 */
if(!s->budget--) { s->failed_pc=0x0c08b494u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c08b496;
P_0c08b496: /* original 0e1a, guest PC 0x0c08b496 */
if(!s->budget--) { s->failed_pc=0x0c08b496u; return 0; }
r[14]=r[19];
goto P_0c08b498;
P_0c08b498: /* original 6eef, guest PC 0x0c08b498 */
if(!s->budget--) { s->failed_pc=0x0c08b498u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c08b49a;
P_0c08b49a: /* original 3eac, guest PC 0x0c08b49a */
if(!s->budget--) { s->failed_pc=0x0c08b49au; return 0; }
r[14]+=r[10];
goto P_0c08b49c;
P_0c08b49c: /* original 85ec, guest PC 0x0c08b49c */
if(!s->budget--) { s->failed_pc=0x0c08b49cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+24,2);
goto P_0c08b49e;
P_0c08b49e: /* original 6403, guest PC 0x0c08b49e */
if(!s->budget--) { s->failed_pc=0x0c08b49eu; return 0; }
r[4]=r[0];
goto P_0c08b4a0;
P_0c08b4a0: /* original 2428, guest PC 0x0c08b4a0 */
if(!s->budget--) { s->failed_pc=0x0c08b4a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c08b4a2;
P_0c08b4a2: /* original 8b02, guest PC 0x0c08b4a2 */
if(!s->budget--) { s->failed_pc=0x0c08b4a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b4aa; }
goto P_0c08b4a4;
P_0c08b4a4: /* original 60c3, guest PC 0x0c08b4a4 */
if(!s->budget--) { s->failed_pc=0x0c08b4a4u; return 0; }
r[0]=r[12];
goto P_0c08b4a6;
P_0c08b4a6: /* original 8810, guest PC 0x0c08b4a6 */
if(!s->budget--) { s->failed_pc=0x0c08b4a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c08b4a8;
P_0c08b4a8: /* original 8903, guest PC 0x0c08b4a8 */
if(!s->budget--) { s->failed_pc=0x0c08b4a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08b4b2; }
goto P_0c08b4aa;
P_0c08b4aa: /* original 60c3, guest PC 0x0c08b4aa */
if(!s->budget--) { s->failed_pc=0x0c08b4aau; return 0; }
r[0]=r[12];
goto P_0c08b4ac;
P_0c08b4ac: /* original 0bee, guest PC 0x0c08b4ac */
if(!s->budget--) { s->failed_pc=0x0c08b4acu; return 0; }
r[11]=read(ram,r[14]+r[0],4);
goto P_0c08b4ae;
P_0c08b4ae: /* original 4b0b, guest PC 0x0c08b4ae */
if(!s->budget--) { s->failed_pc=0x0c08b4aeu; return 0; }
target=r[11];
r[16]=0x0c08b4b2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b4b2u) { target=s->pc; goto dispatch; }
goto P_0c08b4b2;
P_0c08b4b0: /* original 64d3, guest PC 0x0c08b4b0 */
if(!s->budget--) { s->failed_pc=0x0c08b4b0u; return 0; }
r[4]=r[13];
goto P_0c08b4b2;
P_0c08b4b2: /* original 52e5, guest PC 0x0c08b4b2 */
if(!s->budget--) { s->failed_pc=0x0c08b4b2u; return 0; }
r[2]=read(ram,r[14]+20,4);
goto P_0c08b4b4;
P_0c08b4b4: /* original 6ef2, guest PC 0x0c08b4b4 */
if(!s->budget--) { s->failed_pc=0x0c08b4b4u; return 0; }
tmp=read(ram,r[15],4);
r[14]=tmp;
goto P_0c08b4b6;
P_0c08b4b6: /* original 3d2c, guest PC 0x0c08b4b6 */
if(!s->budget--) { s->failed_pc=0x0c08b4b6u; return 0; }
r[13]+=r[2];
goto P_0c08b4b8;
P_0c08b4b8: /* original 7e01, guest PC 0x0c08b4b8 */
if(!s->budget--) { s->failed_pc=0x0c08b4b8u; return 0; }
r[14]+=0x00000001u;
goto P_0c08b4ba;
P_0c08b4ba: /* original 2fe2, guest PC 0x0c08b4ba */
if(!s->budget--) { s->failed_pc=0x0c08b4bau; return 0; }
write(ram,r[15],r[14],4);
goto P_0c08b4bc;
P_0c08b4bc: /* original 6ee0, guest PC 0x0c08b4bc */
if(!s->budget--) { s->failed_pc=0x0c08b4bcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]=tmp;
goto P_0c08b4be;
P_0c08b4be: /* original 63ee, guest PC 0x0c08b4be */
if(!s->budget--) { s->failed_pc=0x0c08b4beu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[14];
goto P_0c08b4c0;
P_0c08b4c0: /* original 2338, guest PC 0x0c08b4c0 */
if(!s->budget--) { s->failed_pc=0x0c08b4c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c08b4c2;
P_0c08b4c2: /* original 8bd8, guest PC 0x0c08b4c2 */
if(!s->budget--) { s->failed_pc=0x0c08b4c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08b476; }
goto P_0c08b4c4;
P_0c08b4c4: /* original 7f08, guest PC 0x0c08b4c4 */
if(!s->budget--) { s->failed_pc=0x0c08b4c4u; return 0; }
r[15]+=0x00000008u;
goto P_0c08b4c6;
P_0c08b4c6: /* original 60d3, guest PC 0x0c08b4c6 */
if(!s->budget--) { s->failed_pc=0x0c08b4c6u; return 0; }
r[0]=r[13];
goto P_0c08b4c8;
P_0c08b4c8: /* original 4f16, guest PC 0x0c08b4c8 */
if(!s->budget--) { s->failed_pc=0x0c08b4c8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b4ca;
P_0c08b4ca: /* original 4f26, guest PC 0x0c08b4ca */
if(!s->budget--) { s->failed_pc=0x0c08b4cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b4cc;
P_0c08b4cc: /* original fff9, guest PC 0x0c08b4cc */
if(!s->budget--) { s->failed_pc=0x0c08b4ccu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08b4ce;
P_0c08b4ce: /* original 68f6, guest PC 0x0c08b4ce */
if(!s->budget--) { s->failed_pc=0x0c08b4ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08b4d0;
P_0c08b4d0: /* original 69f6, guest PC 0x0c08b4d0 */
if(!s->budget--) { s->failed_pc=0x0c08b4d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08b4d2;
P_0c08b4d2: /* original 6af6, guest PC 0x0c08b4d2 */
if(!s->budget--) { s->failed_pc=0x0c08b4d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08b4d4;
P_0c08b4d4: /* original 6bf6, guest PC 0x0c08b4d4 */
if(!s->budget--) { s->failed_pc=0x0c08b4d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08b4d6;
P_0c08b4d6: /* original 6cf6, guest PC 0x0c08b4d6 */
if(!s->budget--) { s->failed_pc=0x0c08b4d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08b4d8;
P_0c08b4d8: /* original 6df6, guest PC 0x0c08b4d8 */
if(!s->budget--) { s->failed_pc=0x0c08b4d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08b4da;
P_0c08b4da: /* original 000b, guest PC 0x0c08b4da */
if(!s->budget--) { s->failed_pc=0x0c08b4dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b4dc: /* original 6ef6, guest PC 0x0c08b4dc */
if(!s->budget--) { s->failed_pc=0x0c08b4dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08b4deu,s,ram);
P_0c08c83a: /* original 4f22, guest PC 0x0c08c83a */
if(!s->budget--) { s->failed_pc=0x0c08c83au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08c83c;
P_0c08c83c: /* original 03ec, guest PC 0x0c08c83c */
if(!s->budget--) { s->failed_pc=0x0c08c83cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08c83e;
P_0c08c83e: /* original d20d, guest PC 0x0c08c83e */
if(!s->budget--) { s->failed_pc=0x0c08c83eu; return 0; }
r[2]=read(ram,0x0c08c874u,4);
goto P_0c08c840;
P_0c08c840: /* original 633c, guest PC 0x0c08c840 */
if(!s->budget--) { s->failed_pc=0x0c08c840u; return 0; }
r[3]=r[3]&255u;
goto P_0c08c842;
P_0c08c842: /* original 7ffc, guest PC 0x0c08c842 */
if(!s->budget--) { s->failed_pc=0x0c08c842u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08c844;
P_0c08c844: /* original 420b, guest PC 0x0c08c844 */
if(!s->budget--) { s->failed_pc=0x0c08c844u; return 0; }
target=r[2];
r[16]=0x0c08c848u;
write(ram,r[15],r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08c848u) { target=s->pc; goto dispatch; }
goto P_0c08c848;
P_0c08c846: /* original 2f32, guest PC 0x0c08c846 */
if(!s->budget--) { s->failed_pc=0x0c08c846u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08c848;
P_0c08c848: /* original d30b, guest PC 0x0c08c848 */
if(!s->budget--) { s->failed_pc=0x0c08c848u; return 0; }
r[3]=read(ram,0x0c08c878u,4);
goto P_0c08c84a;
P_0c08c84a: /* original 6103, guest PC 0x0c08c84a */
if(!s->budget--) { s->failed_pc=0x0c08c84au; return 0; }
r[1]=r[0];
goto P_0c08c84c;
P_0c08c84c: /* original 430b, guest PC 0x0c08c84c */
if(!s->budget--) { s->failed_pc=0x0c08c84cu; return 0; }
target=r[3];
r[16]=0x0c08c850u;
tmp=read(ram,r[15],4);
r[0]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08c850u) { target=s->pc; goto dispatch; }
goto P_0c08c850;
P_0c08c84e: /* original 60f2, guest PC 0x0c08c84e */
if(!s->budget--) { s->failed_pc=0x0c08c84eu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c08c850;
P_0c08c850: /* original 6403, guest PC 0x0c08c850 */
if(!s->budget--) { s->failed_pc=0x0c08c850u; return 0; }
r[4]=r[0];
goto P_0c08c852;
P_0c08c852: /* original 2448, guest PC 0x0c08c852 */
if(!s->budget--) { s->failed_pc=0x0c08c852u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08c854;
P_0c08c854: /* original 8912, guest PC 0x0c08c854 */
if(!s->budget--) { s->failed_pc=0x0c08c854u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08c87c; }
goto P_0c08c856;
P_0c08c856: /* original e04a, guest PC 0x0c08c856 */
if(!s->budget--) { s->failed_pc=0x0c08c856u; return 0; }
r[0]=0x0000004au;
goto P_0c08c858;
P_0c08c858: /* original 0ded, guest PC 0x0c08c858 */
if(!s->budget--) { s->failed_pc=0x0c08c858u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08c85a;
P_0c08c85a: /* original a031, guest PC 0x0c08c85a */
if(!s->budget--) { s->failed_pc=0x0c08c85au; return 0; }
r[13]=r[13]&65535u;
goto P_0c08c8c0;
P_0c08c85c: /* original 6ddd, guest PC 0x0c08c85c */
if(!s->budget--) { s->failed_pc=0x0c08c85cu; return 0; }
r[13]=r[13]&65535u;
return vf3_matrix_family(0x0c08c85eu,s,ram);
P_0c08c87c: /* original e04c, guest PC 0x0c08c87c */
if(!s->budget--) { s->failed_pc=0x0c08c87cu; return 0; }
r[0]=0x0000004cu;
goto P_0c08c87e;
P_0c08c87e: /* original 957b, guest PC 0x0c08c87e */
if(!s->budget--) { s->failed_pc=0x0c08c87eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08c978u,2);
goto P_0c08c880;
P_0c08c880: /* original 04ce, guest PC 0x0c08c880 */
if(!s->budget--) { s->failed_pc=0x0c08c880u; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c08c882;
P_0c08c882: /* original 907a, guest PC 0x0c08c882 */
if(!s->budget--) { s->failed_pc=0x0c08c882u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08c97au,2);
goto P_0c08c884;
P_0c08c884: /* original 044c, guest PC 0x0c08c884 */
if(!s->budget--) { s->failed_pc=0x0c08c884u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c08c886;
P_0c08c886: /* original 644c, guest PC 0x0c08c886 */
if(!s->budget--) { s->failed_pc=0x0c08c886u; return 0; }
r[4]=r[4]&255u;
goto P_0c08c888;
P_0c08c888: /* original 6043, guest PC 0x0c08c888 */
if(!s->budget--) { s->failed_pc=0x0c08c888u; return 0; }
r[0]=r[4];
goto P_0c08c88a;
P_0c08c88a: /* original 8802, guest PC 0x0c08c88a */
if(!s->budget--) { s->failed_pc=0x0c08c88au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c08c88c;
P_0c08c88c: /* original 8d18, guest PC 0x0c08c88c */
if(!s->budget--) { s->failed_pc=0x0c08c88cu; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c08c8c0; }
goto P_0c08c890;
P_0c08c88e: /* original 6d53, guest PC 0x0c08c88e */
if(!s->budget--) { s->failed_pc=0x0c08c88eu; return 0; }
r[13]=r[5];
goto P_0c08c890;
P_0c08c890: /* original 6043, guest PC 0x0c08c890 */
if(!s->budget--) { s->failed_pc=0x0c08c890u; return 0; }
r[0]=r[4];
goto P_0c08c892;
P_0c08c892: /* original 8806, guest PC 0x0c08c892 */
if(!s->budget--) { s->failed_pc=0x0c08c892u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c08c894;
P_0c08c894: /* original 8914, guest PC 0x0c08c894 */
if(!s->budget--) { s->failed_pc=0x0c08c894u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08c8c0; }
goto P_0c08c896;
P_0c08c896: /* original 6043, guest PC 0x0c08c896 */
if(!s->budget--) { s->failed_pc=0x0c08c896u; return 0; }
r[0]=r[4];
goto P_0c08c898;
P_0c08c898: /* original 8805, guest PC 0x0c08c898 */
if(!s->budget--) { s->failed_pc=0x0c08c898u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c08c89a;
P_0c08c89a: /* original 8911, guest PC 0x0c08c89a */
if(!s->budget--) { s->failed_pc=0x0c08c89au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08c8c0; }
goto P_0c08c89c;
P_0c08c89c: /* original 2448, guest PC 0x0c08c89c */
if(!s->budget--) { s->failed_pc=0x0c08c89cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08c89e;
P_0c08c89e: /* original 8b0e, guest PC 0x0c08c89e */
if(!s->budget--) { s->failed_pc=0x0c08c89eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08c8be; }
goto P_0c08c8a0;
P_0c08c8a0: /* original e04a, guest PC 0x0c08c8a0 */
if(!s->budget--) { s->failed_pc=0x0c08c8a0u; return 0; }
r[0]=0x0000004au;
goto P_0c08c8a2;
P_0c08c8a2: /* original 04ed, guest PC 0x0c08c8a2 */
if(!s->budget--) { s->failed_pc=0x0c08c8a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08c8a4;
P_0c08c8a4: /* original 644d, guest PC 0x0c08c8a4 */
if(!s->budget--) { s->failed_pc=0x0c08c8a4u; return 0; }
r[4]=r[4]&65535u;
goto P_0c08c8a6;
P_0c08c8a6: /* original 3450, guest PC 0x0c08c8a6 */
if(!s->budget--) { s->failed_pc=0x0c08c8a6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c08c8a8;
P_0c08c8a8: /* original 890a, guest PC 0x0c08c8a8 */
if(!s->budget--) { s->failed_pc=0x0c08c8a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08c8c0; }
goto P_0c08c8aa;
P_0c08c8aa: /* original d335, guest PC 0x0c08c8aa */
if(!s->budget--) { s->failed_pc=0x0c08c8aau; return 0; }
r[3]=read(ram,0x0c08c980u,4);
goto P_0c08c8ac;
P_0c08c8ac: /* original 430b, guest PC 0x0c08c8ac */
if(!s->budget--) { s->failed_pc=0x0c08c8acu; return 0; }
target=r[3];
r[16]=0x0c08c8b0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08c8b0u) { target=s->pc; goto dispatch; }
goto P_0c08c8b0;
P_0c08c8ae: /* original 0009, guest PC 0x0c08c8ae */
if(!s->budget--) { s->failed_pc=0x0c08c8aeu; return 0; }
goto P_0c08c8b0;
P_0c08c8b0: /* original d234, guest PC 0x0c08c8b0 */
if(!s->budget--) { s->failed_pc=0x0c08c8b0u; return 0; }
r[2]=read(ram,0x0c08c984u,4);
goto P_0c08c8b2;
P_0c08c8b2: /* original 6103, guest PC 0x0c08c8b2 */
if(!s->budget--) { s->failed_pc=0x0c08c8b2u; return 0; }
r[1]=r[0];
goto P_0c08c8b4;
P_0c08c8b4: /* original 420b, guest PC 0x0c08c8b4 */
if(!s->budget--) { s->failed_pc=0x0c08c8b4u; return 0; }
target=r[2];
r[16]=0x0c08c8b8u;
r[0]=0x00000003u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08c8b8u) { target=s->pc; goto dispatch; }
goto P_0c08c8b8;
P_0c08c8b6: /* original e003, guest PC 0x0c08c8b6 */
if(!s->budget--) { s->failed_pc=0x0c08c8b6u; return 0; }
r[0]=0x00000003u;
goto P_0c08c8b8;
P_0c08c8b8: /* original 6403, guest PC 0x0c08c8b8 */
if(!s->budget--) { s->failed_pc=0x0c08c8b8u; return 0; }
r[4]=r[0];
goto P_0c08c8ba;
P_0c08c8ba: /* original 2448, guest PC 0x0c08c8ba */
if(!s->budget--) { s->failed_pc=0x0c08c8bau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08c8bc;
P_0c08c8bc: /* original 8900, guest PC 0x0c08c8bc */
if(!s->budget--) { s->failed_pc=0x0c08c8bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08c8c0; }
goto P_0c08c8be;
P_0c08c8be: /* original 9d5d, guest PC 0x0c08c8be */
if(!s->budget--) { s->failed_pc=0x0c08c8beu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08c97cu,2);
goto P_0c08c8c0;
P_0c08c8c0: /* original e04a, guest PC 0x0c08c8c0 */
if(!s->budget--) { s->failed_pc=0x0c08c8c0u; return 0; }
r[0]=0x0000004au;
goto P_0c08c8c2;
P_0c08c8c2: /* original 0ed5, guest PC 0x0c08c8c2 */
if(!s->budget--) { s->failed_pc=0x0c08c8c2u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c08c8c4;
P_0c08c8c4: /* original e028, guest PC 0x0c08c8c4 */
if(!s->budget--) { s->failed_pc=0x0c08c8c4u; return 0; }
r[0]=0x00000028u;
goto P_0c08c8c6;
P_0c08c8c6: /* original 0ed5, guest PC 0x0c08c8c6 */
if(!s->budget--) { s->failed_pc=0x0c08c8c6u; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c08c8c8;
P_0c08c8c8: /* original e040, guest PC 0x0c08c8c8 */
if(!s->budget--) { s->failed_pc=0x0c08c8c8u; return 0; }
r[0]=0x00000040u;
goto P_0c08c8ca;
P_0c08c8ca: /* original e400, guest PC 0x0c08c8ca */
if(!s->budget--) { s->failed_pc=0x0c08c8cau; return 0; }
r[4]=0x00000000u;
goto P_0c08c8cc;
P_0c08c8cc: /* original 1cdd, guest PC 0x0c08c8cc */
if(!s->budget--) { s->failed_pc=0x0c08c8ccu; return 0; }
write(ram,r[12]+52,r[13],4);
goto P_0c08c8ce;
P_0c08c8ce: /* original 0c46, guest PC 0x0c08c8ce */
if(!s->budget--) { s->failed_pc=0x0c08c8ceu; return 0; }
write(ram,r[12]+r[0],r[4],4);
goto P_0c08c8d0;
P_0c08c8d0: /* original b442, guest PC 0x0c08c8d0 */
if(!s->budget--) { s->failed_pc=0x0c08c8d0u; return 0; }
target=0x0c08d158u; r[16]=0x0c08c8d4u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08c8d4u) { target=s->pc; goto dispatch; }
goto P_0c08c8d4;
P_0c08c8d2: /* original 64c3, guest PC 0x0c08c8d2 */
if(!s->budget--) { s->failed_pc=0x0c08c8d2u; return 0; }
r[4]=r[12];
goto P_0c08c8d4;
P_0c08c8d4: /* original e200, guest PC 0x0c08c8d4 */
if(!s->budget--) { s->failed_pc=0x0c08c8d4u; return 0; }
r[2]=0x00000000u;
goto P_0c08c8d6;
P_0c08c8d6: /* original 55ce, guest PC 0x0c08c8d6 */
if(!s->budget--) { s->failed_pc=0x0c08c8d6u; return 0; }
r[5]=read(ram,r[12]+56,4);
goto P_0c08c8d8;
P_0c08c8d8: /* original e02c, guest PC 0x0c08c8d8 */
if(!s->budget--) { s->failed_pc=0x0c08c8d8u; return 0; }
r[0]=0x0000002cu;
goto P_0c08c8da;
P_0c08c8da: /* original 54cf, guest PC 0x0c08c8da */
if(!s->budget--) { s->failed_pc=0x0c08c8dau; return 0; }
r[4]=read(ram,r[12]+60,4);
goto P_0c08c8dc;
P_0c08c8dc: /* original 0e24, guest PC 0x0c08c8dc */
if(!s->budget--) { s->failed_pc=0x0c08c8dcu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c08c8de;
P_0c08c8de: /* original e02d, guest PC 0x0c08c8de */
if(!s->budget--) { s->failed_pc=0x0c08c8deu; return 0; }
r[0]=0x0000002du;
goto P_0c08c8e0;
P_0c08c8e0: /* original 0e54, guest PC 0x0c08c8e0 */
if(!s->budget--) { s->failed_pc=0x0c08c8e0u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c08c8e2;
P_0c08c8e2: /* original e048, guest PC 0x0c08c8e2 */
if(!s->budget--) { s->failed_pc=0x0c08c8e2u; return 0; }
r[0]=0x00000048u;
goto P_0c08c8e4;
P_0c08c8e4: /* original 00ec, guest PC 0x0c08c8e4 */
if(!s->budget--) { s->failed_pc=0x0c08c8e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08c8e6;
P_0c08c8e6: /* original 8801, guest PC 0x0c08c8e6 */
if(!s->budget--) { s->failed_pc=0x0c08c8e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08c8e8;
P_0c08c8e8: /* original 8905, guest PC 0x0c08c8e8 */
if(!s->budget--) { s->failed_pc=0x0c08c8e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08c8f6; }
goto P_0c08c8ea;
P_0c08c8ea: /* original 6043, guest PC 0x0c08c8ea */
if(!s->budget--) { s->failed_pc=0x0c08c8eau; return 0; }
r[0]=r[4];
goto P_0c08c8ec;
P_0c08c8ec: /* original 81ea, guest PC 0x0c08c8ec */
if(!s->budget--) { s->failed_pc=0x0c08c8ecu; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c08c8ee;
P_0c08c8ee: /* original e048, guest PC 0x0c08c8ee */
if(!s->budget--) { s->failed_pc=0x0c08c8eeu; return 0; }
r[0]=0x00000048u;
goto P_0c08c8f0;
P_0c08c8f0: /* original 03ec, guest PC 0x0c08c8f0 */
if(!s->budget--) { s->failed_pc=0x0c08c8f0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08c8f2;
P_0c08c8f2: /* original 7301, guest PC 0x0c08c8f2 */
if(!s->budget--) { s->failed_pc=0x0c08c8f2u; return 0; }
r[3]+=0x00000001u;
goto P_0c08c8f4;
P_0c08c8f4: /* original 0e34, guest PC 0x0c08c8f4 */
if(!s->budget--) { s->failed_pc=0x0c08c8f4u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08c8f6;
P_0c08c8f6: /* original 7f04, guest PC 0x0c08c8f6 */
if(!s->budget--) { s->failed_pc=0x0c08c8f6u; return 0; }
r[15]+=0x00000004u;
goto P_0c08c8f8;
P_0c08c8f8: /* original 4f26, guest PC 0x0c08c8f8 */
if(!s->budget--) { s->failed_pc=0x0c08c8f8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08c8fa;
P_0c08c8fa: /* original 6cf6, guest PC 0x0c08c8fa */
if(!s->budget--) { s->failed_pc=0x0c08c8fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08c8fc;
P_0c08c8fc: /* original 6df6, guest PC 0x0c08c8fc */
if(!s->budget--) { s->failed_pc=0x0c08c8fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08c8fe;
P_0c08c8fe: /* original 000b, guest PC 0x0c08c8fe */
if(!s->budget--) { s->failed_pc=0x0c08c8feu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08c900: /* original 6ef6, guest PC 0x0c08c900 */
if(!s->budget--) { s->failed_pc=0x0c08c900u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08c902u,s,ram);
P_0c08cdc4: /* original 4f22, guest PC 0x0c08cdc4 */
if(!s->budget--) { s->failed_pc=0x0c08cdc4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08cdc6;
P_0c08cdc6: /* original 6043, guest PC 0x0c08cdc6 */
if(!s->budget--) { s->failed_pc=0x0c08cdc6u; return 0; }
r[0]=r[4];
goto P_0c08cdc8;
P_0c08cdc8: /* original 8801, guest PC 0x0c08cdc8 */
if(!s->budget--) { s->failed_pc=0x0c08cdc8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08cdca;
P_0c08cdca: /* original 8d25, guest PC 0x0c08cdca */
if(!s->budget--) { s->failed_pc=0x0c08cdcau; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(cond) { goto P_0c08ce18; }
goto P_0c08cdce;
P_0c08cdcc: /* original ec00, guest PC 0x0c08cdcc */
if(!s->budget--) { s->failed_pc=0x0c08cdccu; return 0; }
r[12]=0x00000000u;
goto P_0c08cdce;
P_0c08cdce: /* original 6043, guest PC 0x0c08cdce */
if(!s->budget--) { s->failed_pc=0x0c08cdceu; return 0; }
r[0]=r[4];
goto P_0c08cdd0;
P_0c08cdd0: /* original 8802, guest PC 0x0c08cdd0 */
if(!s->budget--) { s->failed_pc=0x0c08cdd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c08cdd2;
P_0c08cdd2: /* original 8942, guest PC 0x0c08cdd2 */
if(!s->budget--) { s->failed_pc=0x0c08cdd2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ce5a; }
goto P_0c08cdd4;
P_0c08cdd4: /* original 60d2, guest PC 0x0c08cdd4 */
if(!s->budget--) { s->failed_pc=0x0c08cdd4u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c08cdd6;
P_0c08cdd6: /* original d235, guest PC 0x0c08cdd6 */
if(!s->budget--) { s->failed_pc=0x0c08cdd6u; return 0; }
r[2]=read(ram,0x0c08ceacu,4);
goto P_0c08cdd8;
P_0c08cdd8: /* original cb01, guest PC 0x0c08cdd8 */
if(!s->budget--) { s->failed_pc=0x0c08cdd8u; return 0; }
r[0]|=1u;
goto P_0c08cdda;
P_0c08cdda: /* original 420b, guest PC 0x0c08cdda */
if(!s->budget--) { s->failed_pc=0x0c08cddau; return 0; }
target=r[2];
r[16]=0x0c08cddeu;
write(ram,r[13],r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08cddeu) { target=s->pc; goto dispatch; }
goto P_0c08cdde;
P_0c08cddc: /* original 2d02, guest PC 0x0c08cddc */
if(!s->budget--) { s->failed_pc=0x0c08cddcu; return 0; }
write(ram,r[13],r[0],4);
goto P_0c08cdde;
P_0c08cdde: /* original d334, guest PC 0x0c08cdde */
if(!s->budget--) { s->failed_pc=0x0c08cddeu; return 0; }
r[3]=read(ram,0x0c08ceb0u,4);
goto P_0c08cde0;
P_0c08cde0: /* original 6103, guest PC 0x0c08cde0 */
if(!s->budget--) { s->failed_pc=0x0c08cde0u; return 0; }
r[1]=r[0];
goto P_0c08cde2;
P_0c08cde2: /* original 430b, guest PC 0x0c08cde2 */
if(!s->budget--) { s->failed_pc=0x0c08cde2u; return 0; }
target=r[3];
r[16]=0x0c08cde6u;
r[0]=0x00000009u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08cde6u) { target=s->pc; goto dispatch; }
goto P_0c08cde6;
P_0c08cde4: /* original e009, guest PC 0x0c08cde4 */
if(!s->budget--) { s->failed_pc=0x0c08cde4u; return 0; }
r[0]=0x00000009u;
goto P_0c08cde6;
P_0c08cde6: /* original 6503, guest PC 0x0c08cde6 */
if(!s->budget--) { s->failed_pc=0x0c08cde6u; return 0; }
r[5]=r[0];
goto P_0c08cde8;
P_0c08cde8: /* original e04c, guest PC 0x0c08cde8 */
if(!s->budget--) { s->failed_pc=0x0c08cde8u; return 0; }
r[0]=0x0000004cu;
goto P_0c08cdea;
P_0c08cdea: /* original 0e55, guest PC 0x0c08cdea */
if(!s->budget--) { s->failed_pc=0x0c08cdeau; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c08cdec;
P_0c08cdec: /* original e028, guest PC 0x0c08cdec */
if(!s->budget--) { s->failed_pc=0x0c08cdecu; return 0; }
r[0]=0x00000028u;
goto P_0c08cdee;
P_0c08cdee: /* original 9459, guest PC 0x0c08cdee */
if(!s->budget--) { s->failed_pc=0x0c08cdeeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08cea4u,2);
goto P_0c08cdf0;
P_0c08cdf0: /* original 345c, guest PC 0x0c08cdf0 */
if(!s->budget--) { s->failed_pc=0x0c08cdf0u; return 0; }
r[4]+=r[5];
goto P_0c08cdf2;
P_0c08cdf2: /* original 65c3, guest PC 0x0c08cdf2 */
if(!s->budget--) { s->failed_pc=0x0c08cdf2u; return 0; }
r[5]=r[12];
goto P_0c08cdf4;
P_0c08cdf4: /* original 0e45, guest PC 0x0c08cdf4 */
if(!s->budget--) { s->failed_pc=0x0c08cdf4u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08cdf6;
P_0c08cdf6: /* original e040, guest PC 0x0c08cdf6 */
if(!s->budget--) { s->failed_pc=0x0c08cdf6u; return 0; }
r[0]=0x00000040u;
goto P_0c08cdf8;
P_0c08cdf8: /* original 1d4d, guest PC 0x0c08cdf8 */
if(!s->budget--) { s->failed_pc=0x0c08cdf8u; return 0; }
write(ram,r[13]+52,r[4],4);
goto P_0c08cdfa;
P_0c08cdfa: /* original 0d56, guest PC 0x0c08cdfa */
if(!s->budget--) { s->failed_pc=0x0c08cdfau; return 0; }
write(ram,r[13]+r[0],r[5],4);
goto P_0c08cdfc;
P_0c08cdfc: /* original b1ac, guest PC 0x0c08cdfc */
if(!s->budget--) { s->failed_pc=0x0c08cdfcu; return 0; }
target=0x0c08d158u; r[16]=0x0c08ce00u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ce00u) { target=s->pc; goto dispatch; }
goto P_0c08ce00;
P_0c08cdfe: /* original 64d3, guest PC 0x0c08cdfe */
if(!s->budget--) { s->failed_pc=0x0c08cdfeu; return 0; }
r[4]=r[13];
goto P_0c08ce00;
P_0c08ce00: /* original e02c, guest PC 0x0c08ce00 */
if(!s->budget--) { s->failed_pc=0x0c08ce00u; return 0; }
r[0]=0x0000002cu;
goto P_0c08ce02;
P_0c08ce02: /* original 54de, guest PC 0x0c08ce02 */
if(!s->budget--) { s->failed_pc=0x0c08ce02u; return 0; }
r[4]=read(ram,r[13]+56,4);
goto P_0c08ce04;
P_0c08ce04: /* original 55df, guest PC 0x0c08ce04 */
if(!s->budget--) { s->failed_pc=0x0c08ce04u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c08ce06;
P_0c08ce06: /* original 0ec4, guest PC 0x0c08ce06 */
if(!s->budget--) { s->failed_pc=0x0c08ce06u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c08ce08;
P_0c08ce08: /* original e02d, guest PC 0x0c08ce08 */
if(!s->budget--) { s->failed_pc=0x0c08ce08u; return 0; }
r[0]=0x0000002du;
goto P_0c08ce0a;
P_0c08ce0a: /* original 0e44, guest PC 0x0c08ce0a */
if(!s->budget--) { s->failed_pc=0x0c08ce0au; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c08ce0c;
P_0c08ce0c: /* original 6053, guest PC 0x0c08ce0c */
if(!s->budget--) { s->failed_pc=0x0c08ce0cu; return 0; }
r[0]=r[5];
goto P_0c08ce0e;
P_0c08ce0e: /* original 81ea, guest PC 0x0c08ce0e */
if(!s->budget--) { s->failed_pc=0x0c08ce0eu; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c08ce10;
P_0c08ce10: /* original e048, guest PC 0x0c08ce10 */
if(!s->budget--) { s->failed_pc=0x0c08ce10u; return 0; }
r[0]=0x00000048u;
goto P_0c08ce12;
P_0c08ce12: /* original 03ec, guest PC 0x0c08ce12 */
if(!s->budget--) { s->failed_pc=0x0c08ce12u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08ce14;
P_0c08ce14: /* original 7301, guest PC 0x0c08ce14 */
if(!s->budget--) { s->failed_pc=0x0c08ce14u; return 0; }
r[3]+=0x00000001u;
goto P_0c08ce16;
P_0c08ce16: /* original 0e34, guest PC 0x0c08ce16 */
if(!s->budget--) { s->failed_pc=0x0c08ce16u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08ce18;
P_0c08ce18: /* original 50d5, guest PC 0x0c08ce18 */
if(!s->budget--) { s->failed_pc=0x0c08ce18u; return 0; }
r[0]=read(ram,r[13]+20,4);
goto P_0c08ce1a;
P_0c08ce1a: /* original c808, guest PC 0x0c08ce1a */
if(!s->budget--) { s->failed_pc=0x0c08ce1au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c08ce1c;
P_0c08ce1c: /* original 891d, guest PC 0x0c08ce1c */
if(!s->budget--) { s->failed_pc=0x0c08ce1cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ce5a; }
goto P_0c08ce1e;
P_0c08ce1e: /* original d223, guest PC 0x0c08ce1e */
if(!s->budget--) { s->failed_pc=0x0c08ce1eu; return 0; }
r[2]=read(ram,0x0c08ceacu,4);
goto P_0c08ce20;
P_0c08ce20: /* original 9b41, guest PC 0x0c08ce20 */
if(!s->budget--) { s->failed_pc=0x0c08ce20u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08cea6u,2);
goto P_0c08ce22;
P_0c08ce22: /* original 420b, guest PC 0x0c08ce22 */
if(!s->budget--) { s->failed_pc=0x0c08ce22u; return 0; }
target=r[2];
r[16]=0x0c08ce26u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ce26u) { target=s->pc; goto dispatch; }
goto P_0c08ce26;
P_0c08ce24: /* original 0009, guest PC 0x0c08ce24 */
if(!s->budget--) { s->failed_pc=0x0c08ce24u; return 0; }
goto P_0c08ce26;
P_0c08ce26: /* original e301, guest PC 0x0c08ce26 */
if(!s->budget--) { s->failed_pc=0x0c08ce26u; return 0; }
r[3]=0x00000001u;
goto P_0c08ce28;
P_0c08ce28: /* original 6403, guest PC 0x0c08ce28 */
if(!s->budget--) { s->failed_pc=0x0c08ce28u; return 0; }
r[4]=r[0];
goto P_0c08ce2a;
P_0c08ce2a: /* original 2439, guest PC 0x0c08ce2a */
if(!s->budget--) { s->failed_pc=0x0c08ce2au; return 0; }
r[4]&=r[3];
goto P_0c08ce2c;
P_0c08ce2c: /* original 2448, guest PC 0x0c08ce2c */
if(!s->budget--) { s->failed_pc=0x0c08ce2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08ce2e;
P_0c08ce2e: /* original 8d01, guest PC 0x0c08ce2e */
if(!s->budget--) { s->failed_pc=0x0c08ce2eu; return 0; }
cond=r[17]&1u;
r[4]=r[12];
if(cond) { goto P_0c08ce34; }
goto P_0c08ce32;
P_0c08ce30: /* original 64c3, guest PC 0x0c08ce30 */
if(!s->budget--) { s->failed_pc=0x0c08ce30u; return 0; }
r[4]=r[12];
goto P_0c08ce32;
P_0c08ce32: /* original 9b39, guest PC 0x0c08ce32 */
if(!s->budget--) { s->failed_pc=0x0c08ce32u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08cea8u,2);
goto P_0c08ce34;
P_0c08ce34: /* original e028, guest PC 0x0c08ce34 */
if(!s->budget--) { s->failed_pc=0x0c08ce34u; return 0; }
r[0]=0x00000028u;
goto P_0c08ce36;
P_0c08ce36: /* original 0eb5, guest PC 0x0c08ce36 */
if(!s->budget--) { s->failed_pc=0x0c08ce36u; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c08ce38;
P_0c08ce38: /* original e040, guest PC 0x0c08ce38 */
if(!s->budget--) { s->failed_pc=0x0c08ce38u; return 0; }
r[0]=0x00000040u;
goto P_0c08ce3a;
P_0c08ce3a: /* original 1dbd, guest PC 0x0c08ce3a */
if(!s->budget--) { s->failed_pc=0x0c08ce3au; return 0; }
write(ram,r[13]+52,r[11],4);
goto P_0c08ce3c;
P_0c08ce3c: /* original 0d46, guest PC 0x0c08ce3c */
if(!s->budget--) { s->failed_pc=0x0c08ce3cu; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c08ce3e;
P_0c08ce3e: /* original b18b, guest PC 0x0c08ce3e */
if(!s->budget--) { s->failed_pc=0x0c08ce3eu; return 0; }
target=0x0c08d158u; r[16]=0x0c08ce42u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08ce42u) { target=s->pc; goto dispatch; }
goto P_0c08ce42;
P_0c08ce40: /* original 64d3, guest PC 0x0c08ce40 */
if(!s->budget--) { s->failed_pc=0x0c08ce40u; return 0; }
r[4]=r[13];
goto P_0c08ce42;
P_0c08ce42: /* original e02c, guest PC 0x0c08ce42 */
if(!s->budget--) { s->failed_pc=0x0c08ce42u; return 0; }
r[0]=0x0000002cu;
goto P_0c08ce44;
P_0c08ce44: /* original 55de, guest PC 0x0c08ce44 */
if(!s->budget--) { s->failed_pc=0x0c08ce44u; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c08ce46;
P_0c08ce46: /* original 54df, guest PC 0x0c08ce46 */
if(!s->budget--) { s->failed_pc=0x0c08ce46u; return 0; }
r[4]=read(ram,r[13]+60,4);
goto P_0c08ce48;
P_0c08ce48: /* original 0ec4, guest PC 0x0c08ce48 */
if(!s->budget--) { s->failed_pc=0x0c08ce48u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c08ce4a;
P_0c08ce4a: /* original e02d, guest PC 0x0c08ce4a */
if(!s->budget--) { s->failed_pc=0x0c08ce4au; return 0; }
r[0]=0x0000002du;
goto P_0c08ce4c;
P_0c08ce4c: /* original 0e54, guest PC 0x0c08ce4c */
if(!s->budget--) { s->failed_pc=0x0c08ce4cu; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c08ce4e;
P_0c08ce4e: /* original 6043, guest PC 0x0c08ce4e */
if(!s->budget--) { s->failed_pc=0x0c08ce4eu; return 0; }
r[0]=r[4];
goto P_0c08ce50;
P_0c08ce50: /* original 81ea, guest PC 0x0c08ce50 */
if(!s->budget--) { s->failed_pc=0x0c08ce50u; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c08ce52;
P_0c08ce52: /* original e048, guest PC 0x0c08ce52 */
if(!s->budget--) { s->failed_pc=0x0c08ce52u; return 0; }
r[0]=0x00000048u;
goto P_0c08ce54;
P_0c08ce54: /* original 03ec, guest PC 0x0c08ce54 */
if(!s->budget--) { s->failed_pc=0x0c08ce54u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08ce56;
P_0c08ce56: /* original 7301, guest PC 0x0c08ce56 */
if(!s->budget--) { s->failed_pc=0x0c08ce56u; return 0; }
r[3]+=0x00000001u;
goto P_0c08ce58;
P_0c08ce58: /* original 0e34, guest PC 0x0c08ce58 */
if(!s->budget--) { s->failed_pc=0x0c08ce58u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08ce5a;
P_0c08ce5a: /* original 4f26, guest PC 0x0c08ce5a */
if(!s->budget--) { s->failed_pc=0x0c08ce5au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08ce5c;
P_0c08ce5c: /* original 6bf6, guest PC 0x0c08ce5c */
if(!s->budget--) { s->failed_pc=0x0c08ce5cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08ce5e;
P_0c08ce5e: /* original 6cf6, guest PC 0x0c08ce5e */
if(!s->budget--) { s->failed_pc=0x0c08ce5eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08ce60;
P_0c08ce60: /* original 6df6, guest PC 0x0c08ce60 */
if(!s->budget--) { s->failed_pc=0x0c08ce60u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08ce62;
P_0c08ce62: /* original 000b, guest PC 0x0c08ce62 */
if(!s->budget--) { s->failed_pc=0x0c08ce62u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08ce64: /* original 6ef6, guest PC 0x0c08ce64 */
if(!s->budget--) { s->failed_pc=0x0c08ce64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08ce66u,s,ram);
P_0c08db78: /* original 4f22, guest PC 0x0c08db78 */
if(!s->budget--) { s->failed_pc=0x0c08db78u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08db7a;
P_0c08db7a: /* original 6432, guest PC 0x0c08db7a */
if(!s->budget--) { s->failed_pc=0x0c08db7au; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c08db7c;
P_0c08db7c: /* original f446, guest PC 0x0c08db7c */
if(!s->budget--) { s->failed_pc=0x0c08db7cu; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c08db7e;
P_0c08db7e: /* original e014, guest PC 0x0c08db7e */
if(!s->budget--) { s->failed_pc=0x0c08db7eu; return 0; }
r[0]=0x00000014u;
goto P_0c08db80;
P_0c08db80: /* original f546, guest PC 0x0c08db80 */
if(!s->budget--) { s->failed_pc=0x0c08db80u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c08db82;
P_0c08db82: /* original e018, guest PC 0x0c08db82 */
if(!s->budget--) { s->failed_pc=0x0c08db82u; return 0; }
r[0]=0x00000018u;
goto P_0c08db84;
P_0c08db84: /* original f646, guest PC 0x0c08db84 */
if(!s->budget--) { s->failed_pc=0x0c08db84u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c08db86;
P_0c08db86: /* original 7fe8, guest PC 0x0c08db86 */
if(!s->budget--) { s->failed_pc=0x0c08db86u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c08db88;
P_0c08db88: /* original 65f3, guest PC 0x0c08db88 */
if(!s->budget--) { s->failed_pc=0x0c08db88u; return 0; }
r[5]=r[15];
goto P_0c08db8a;
P_0c08db8a: /* original 66f3, guest PC 0x0c08db8a */
if(!s->budget--) { s->failed_pc=0x0c08db8au; return 0; }
r[6]=r[15];
goto P_0c08db8c;
P_0c08db8c: /* original 7510, guest PC 0x0c08db8c */
if(!s->budget--) { s->failed_pc=0x0c08db8cu; return 0; }
r[5]+=0x00000010u;
goto P_0c08db8e;
P_0c08db8e: /* original f64d, guest PC 0x0c08db8e */
if(!s->budget--) { s->failed_pc=0x0c08db8eu; return 0; }
fr[6]^=0x80000000u;
goto P_0c08db90;
P_0c08db90: /* original 7614, guest PC 0x0c08db90 */
if(!s->budget--) { s->failed_pc=0x0c08db90u; return 0; }
r[6]+=0x00000014u;
goto P_0c08db92;
P_0c08db92: /* original b11d, guest PC 0x0c08db92 */
if(!s->budget--) { s->failed_pc=0x0c08db92u; return 0; }
target=0x0c08ddd0u; r[16]=0x0c08db96u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08db96u) { target=s->pc; goto dispatch; }
goto P_0c08db96;
P_0c08db94: /* original 64e3, guest PC 0x0c08db94 */
if(!s->budget--) { s->failed_pc=0x0c08db94u; return 0; }
r[4]=r[14];
goto P_0c08db96;
P_0c08db96: /* original 63f3, guest PC 0x0c08db96 */
if(!s->budget--) { s->failed_pc=0x0c08db96u; return 0; }
r[3]=r[15];
goto P_0c08db98;
P_0c08db98: /* original 730c, guest PC 0x0c08db98 */
if(!s->budget--) { s->failed_pc=0x0c08db98u; return 0; }
r[3]+=0x0000000cu;
goto P_0c08db9a;
P_0c08db9a: /* original 2f36, guest PC 0x0c08db9a */
if(!s->budget--) { s->failed_pc=0x0c08db9au; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c08db9c;
P_0c08db9c: /* original 62f3, guest PC 0x0c08db9c */
if(!s->budget--) { s->failed_pc=0x0c08db9cu; return 0; }
r[2]=r[15];
goto P_0c08db9e;
P_0c08db9e: /* original 720c, guest PC 0x0c08db9e */
if(!s->budget--) { s->failed_pc=0x0c08db9eu; return 0; }
r[2]+=0x0000000cu;
goto P_0c08dba0;
P_0c08dba0: /* original 2f26, guest PC 0x0c08dba0 */
if(!s->budget--) { s->failed_pc=0x0c08dba0u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c08dba2;
P_0c08dba2: /* original 66f3, guest PC 0x0c08dba2 */
if(!s->budget--) { s->failed_pc=0x0c08dba2u; return 0; }
r[6]=r[15];
goto P_0c08dba4;
P_0c08dba4: /* original 55f7, guest PC 0x0c08dba4 */
if(!s->budget--) { s->failed_pc=0x0c08dba4u; return 0; }
r[5]=read(ram,r[15]+28,4);
goto P_0c08dba6;
P_0c08dba6: /* original 67f3, guest PC 0x0c08dba6 */
if(!s->budget--) { s->failed_pc=0x0c08dba6u; return 0; }
r[7]=r[15];
goto P_0c08dba8;
P_0c08dba8: /* original 7608, guest PC 0x0c08dba8 */
if(!s->budget--) { s->failed_pc=0x0c08dba8u; return 0; }
r[6]+=0x00000008u;
goto P_0c08dbaa;
P_0c08dbaa: /* original 770c, guest PC 0x0c08dbaa */
if(!s->budget--) { s->failed_pc=0x0c08dbaau; return 0; }
r[7]+=0x0000000cu;
goto P_0c08dbac;
P_0c08dbac: /* original b080, guest PC 0x0c08dbac */
if(!s->budget--) { s->failed_pc=0x0c08dbacu; return 0; }
target=0x0c08dcb0u; r[16]=0x0c08dbb0u;
r[4]=read(ram,r[15]+24,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08dbb0u) { target=s->pc; goto dispatch; }
goto P_0c08dbb0;
P_0c08dbae: /* original 54f6, guest PC 0x0c08dbae */
if(!s->budget--) { s->failed_pc=0x0c08dbaeu; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c08dbb0;
P_0c08dbb0: /* original 62f3, guest PC 0x0c08dbb0 */
if(!s->budget--) { s->failed_pc=0x0c08dbb0u; return 0; }
r[2]=r[15];
goto P_0c08dbb2;
P_0c08dbb2: /* original 7214, guest PC 0x0c08dbb2 */
if(!s->budget--) { s->failed_pc=0x0c08dbb2u; return 0; }
r[2]+=0x00000014u;
goto P_0c08dbb4;
P_0c08dbb4: /* original 2f26, guest PC 0x0c08dbb4 */
if(!s->budget--) { s->failed_pc=0x0c08dbb4u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c08dbb6;
P_0c08dbb6: /* original 66f3, guest PC 0x0c08dbb6 */
if(!s->budget--) { s->failed_pc=0x0c08dbb6u; return 0; }
r[6]=r[15];
goto P_0c08dbb8;
P_0c08dbb8: /* original 65f3, guest PC 0x0c08dbb8 */
if(!s->budget--) { s->failed_pc=0x0c08dbb8u; return 0; }
r[5]=r[15];
goto P_0c08dbba;
P_0c08dbba: /* original 67f3, guest PC 0x0c08dbba */
if(!s->budget--) { s->failed_pc=0x0c08dbbau; return 0; }
r[7]=r[15];
goto P_0c08dbbc;
P_0c08dbbc: /* original 750c, guest PC 0x0c08dbbc */
if(!s->budget--) { s->failed_pc=0x0c08dbbcu; return 0; }
r[5]+=0x0000000cu;
goto P_0c08dbbe;
P_0c08dbbe: /* original 7714, guest PC 0x0c08dbbe */
if(!s->budget--) { s->failed_pc=0x0c08dbbeu; return 0; }
r[7]+=0x00000014u;
goto P_0c08dbc0;
P_0c08dbc0: /* original 7610, guest PC 0x0c08dbc0 */
if(!s->budget--) { s->failed_pc=0x0c08dbc0u; return 0; }
r[6]+=0x00000010u;
goto P_0c08dbc2;
P_0c08dbc2: /* original b0a8, guest PC 0x0c08dbc2 */
if(!s->budget--) { s->failed_pc=0x0c08dbc2u; return 0; }
target=0x0c08dd16u; r[16]=0x0c08dbc6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08dbc6u) { target=s->pc; goto dispatch; }
goto P_0c08dbc6;
P_0c08dbc4: /* original 64e3, guest PC 0x0c08dbc4 */
if(!s->budget--) { s->failed_pc=0x0c08dbc4u; return 0; }
r[4]=r[14];
goto P_0c08dbc6;
P_0c08dbc6: /* original 52f6, guest PC 0x0c08dbc6 */
if(!s->budget--) { s->failed_pc=0x0c08dbc6u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c08dbc8;
P_0c08dbc8: /* original 2f26, guest PC 0x0c08dbc8 */
if(!s->budget--) { s->failed_pc=0x0c08dbc8u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c08dbca;
P_0c08dbca: /* original 53f6, guest PC 0x0c08dbca */
if(!s->budget--) { s->failed_pc=0x0c08dbcau; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c08dbcc;
P_0c08dbcc: /* original 2f36, guest PC 0x0c08dbcc */
if(!s->budget--) { s->failed_pc=0x0c08dbccu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c08dbce;
P_0c08dbce: /* original 52f6, guest PC 0x0c08dbce */
if(!s->budget--) { s->failed_pc=0x0c08dbceu; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c08dbd0;
P_0c08dbd0: /* original 2f26, guest PC 0x0c08dbd0 */
if(!s->budget--) { s->failed_pc=0x0c08dbd0u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c08dbd2;
P_0c08dbd2: /* original 55fa, guest PC 0x0c08dbd2 */
if(!s->budget--) { s->failed_pc=0x0c08dbd2u; return 0; }
r[5]=read(ram,r[15]+40,4);
goto P_0c08dbd4;
P_0c08dbd4: /* original 56fb, guest PC 0x0c08dbd4 */
if(!s->budget--) { s->failed_pc=0x0c08dbd4u; return 0; }
r[6]=read(ram,r[15]+44,4);
goto P_0c08dbd6;
P_0c08dbd6: /* original 57f6, guest PC 0x0c08dbd6 */
if(!s->budget--) { s->failed_pc=0x0c08dbd6u; return 0; }
r[7]=read(ram,r[15]+24,4);
goto P_0c08dbd8;
P_0c08dbd8: /* original b185, guest PC 0x0c08dbd8 */
if(!s->budget--) { s->failed_pc=0x0c08dbd8u; return 0; }
target=0x0c08dee6u; r[16]=0x0c08dbdcu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08dbdcu) { target=s->pc; goto dispatch; }
goto P_0c08dbdc;
P_0c08dbda: /* original 64e3, guest PC 0x0c08dbda */
if(!s->budget--) { s->failed_pc=0x0c08dbdau; return 0; }
r[4]=r[14];
goto P_0c08dbdc;
P_0c08dbdc: /* original 7f30, guest PC 0x0c08dbdc */
if(!s->budget--) { s->failed_pc=0x0c08dbdcu; return 0; }
r[15]+=0x00000030u;
goto P_0c08dbde;
P_0c08dbde: /* original 4f26, guest PC 0x0c08dbde */
if(!s->budget--) { s->failed_pc=0x0c08dbdeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08dbe0;
P_0c08dbe0: /* original 000b, guest PC 0x0c08dbe0 */
if(!s->budget--) { s->failed_pc=0x0c08dbe0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08dbe2: /* original 6ef6, guest PC 0x0c08dbe2 */
if(!s->budget--) { s->failed_pc=0x0c08dbe2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08dbe4u,s,ram);
P_0c09183a: /* original 4f22, guest PC 0x0c09183a */
if(!s->budget--) { s->failed_pc=0x0c09183au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09183c;
P_0c09183c: /* original 04de, guest PC 0x0c09183c */
if(!s->budget--) { s->failed_pc=0x0c09183cu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c09183e;
P_0c09183e: /* original 60e2, guest PC 0x0c09183e */
if(!s->budget--) { s->failed_pc=0x0c09183eu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c091840;
P_0c091840: /* original 7ff4, guest PC 0x0c091840 */
if(!s->budget--) { s->failed_pc=0x0c091840u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c091842;
P_0c091842: /* original 6543, guest PC 0x0c091842 */
if(!s->budget--) { s->failed_pc=0x0c091842u; return 0; }
r[5]=r[4];
goto P_0c091844;
P_0c091844: /* original 8864, guest PC 0x0c091844 */
if(!s->budget--) { s->failed_pc=0x0c091844u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000064u)!=0);
goto P_0c091846;
P_0c091846: /* original 8d02, guest PC 0x0c091846 */
if(!s->budget--) { s->failed_pc=0x0c091846u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000014u;
if(cond) { goto P_0c09184e; }
goto P_0c09184a;
P_0c091848: /* original 7514, guest PC 0x0c091848 */
if(!s->budget--) { s->failed_pc=0x0c091848u; return 0; }
r[5]+=0x00000014u;
goto P_0c09184a;
P_0c09184a: /* original a082, guest PC 0x0c09184a */
if(!s->budget--) { s->failed_pc=0x0c09184au; return 0; }
goto P_0c091952;
P_0c09184c: /* original 0009, guest PC 0x0c09184c */
if(!s->budget--) { s->failed_pc=0x0c09184cu; return 0; }
goto P_0c09184e;
P_0c09184e: /* original 6452, guest PC 0x0c09184e */
if(!s->budget--) { s->failed_pc=0x0c09184eu; return 0; }
tmp=read(ram,r[5],4);
r[4]=tmp;
goto P_0c091850;
P_0c091850: /* original 4411, guest PC 0x0c091850 */
if(!s->budget--) { s->failed_pc=0x0c091850u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c091852;
P_0c091852: /* original 8b0d, guest PC 0x0c091852 */
if(!s->budget--) { s->failed_pc=0x0c091852u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091870; }
goto P_0c091854;
P_0c091854: /* original e30c, guest PC 0x0c091854 */
if(!s->budget--) { s->failed_pc=0x0c091854u; return 0; }
r[3]=0x0000000cu;
goto P_0c091856;
P_0c091856: /* original 3437, guest PC 0x0c091856 */
if(!s->budget--) { s->failed_pc=0x0c091856u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c091858;
P_0c091858: /* original 890a, guest PC 0x0c091858 */
if(!s->budget--) { s->failed_pc=0x0c091858u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091870; }
goto P_0c09185a;
P_0c09185a: /* original 7504, guest PC 0x0c09185a */
if(!s->budget--) { s->failed_pc=0x0c09185au; return 0; }
r[5]+=0x00000004u;
goto P_0c09185c;
P_0c09185c: /* original 6643, guest PC 0x0c09185c */
if(!s->budget--) { s->failed_pc=0x0c09185cu; return 0; }
r[6]=r[4];
goto P_0c09185e;
P_0c09185e: /* original 6753, guest PC 0x0c09185e */
if(!s->budget--) { s->failed_pc=0x0c09185eu; return 0; }
r[7]=r[5];
goto P_0c091860;
P_0c091860: /* original 6352, guest PC 0x0c091860 */
if(!s->budget--) { s->failed_pc=0x0c091860u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c091862;
P_0c091862: /* original 6233, guest PC 0x0c091862 */
if(!s->budget--) { s->failed_pc=0x0c091862u; return 0; }
r[2]=r[3];
goto P_0c091864;
P_0c091864: /* original 32e0, guest PC 0x0c091864 */
if(!s->budget--) { s->failed_pc=0x0c091864u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[14])!=0);
goto P_0c091866;
P_0c091866: /* original 1f32, guest PC 0x0c091866 */
if(!s->budget--) { s->failed_pc=0x0c091866u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c091868;
P_0c091868: /* original 8904, guest PC 0x0c091868 */
if(!s->budget--) { s->failed_pc=0x0c091868u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091874; }
goto P_0c09186a;
P_0c09186a: /* original 4410, guest PC 0x0c09186a */
if(!s->budget--) { s->failed_pc=0x0c09186au; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c09186c;
P_0c09186c: /* original 8ff8, guest PC 0x0c09186c */
if(!s->budget--) { s->failed_pc=0x0c09186cu; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(!cond) { goto P_0c091860; }
goto P_0c091870;
P_0c09186e: /* original 7504, guest PC 0x0c09186e */
if(!s->budget--) { s->failed_pc=0x0c09186eu; return 0; }
r[5]+=0x00000004u;
goto P_0c091870;
P_0c091870: /* original a070, guest PC 0x0c091870 */
if(!s->budget--) { s->failed_pc=0x0c091870u; return 0; }
r[4]=0x00000001u;
goto P_0c091954;
P_0c091872: /* original e401, guest PC 0x0c091872 */
if(!s->budget--) { s->failed_pc=0x0c091872u; return 0; }
r[4]=0x00000001u;
goto P_0c091874;
P_0c091874: /* original e004, guest PC 0x0c091874 */
if(!s->budget--) { s->failed_pc=0x0c091874u; return 0; }
r[0]=0x00000004u;
goto P_0c091876;
P_0c091876: /* original f3e6, guest PC 0x0c091876 */
if(!s->budget--) { s->failed_pc=0x0c091876u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c091878;
P_0c091878: /* original e004, guest PC 0x0c091878 */
if(!s->budget--) { s->failed_pc=0x0c091878u; return 0; }
r[0]=0x00000004u;
goto P_0c09187a;
P_0c09187a: /* original ff37, guest PC 0x0c09187a */
if(!s->budget--) { s->failed_pc=0x0c09187au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09187c;
P_0c09187c: /* original e00c, guest PC 0x0c09187c */
if(!s->budget--) { s->failed_pc=0x0c09187cu; return 0; }
r[0]=0x0000000cu;
goto P_0c09187e;
P_0c09187e: /* original f3e6, guest PC 0x0c09187e */
if(!s->budget--) { s->failed_pc=0x0c09187eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c091880;
P_0c091880: /* original e01c, guest PC 0x0c091880 */
if(!s->budget--) { s->failed_pc=0x0c091880u; return 0; }
r[0]=0x0000001cu;
goto P_0c091882;
P_0c091882: /* original ff3a, guest PC 0x0c091882 */
if(!s->budget--) { s->failed_pc=0x0c091882u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c091884;
P_0c091884: /* original fee6, guest PC 0x0c091884 */
if(!s->budget--) { s->failed_pc=0x0c091884u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c091886;
P_0c091886: /* original 6472, guest PC 0x0c091886 */
if(!s->budget--) { s->failed_pc=0x0c091886u; return 0; }
tmp=read(ram,r[7],4);
r[4]=tmp;
goto P_0c091888;
P_0c091888: /* original 34e0, guest PC 0x0c091888 */
if(!s->budget--) { s->failed_pc=0x0c091888u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[14])!=0);
goto P_0c09188a;
P_0c09188a: /* original 8938, guest PC 0x0c09188a */
if(!s->budget--) { s->failed_pc=0x0c09188au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0918fe; }
goto P_0c09188c;
P_0c09188c: /* original e004, guest PC 0x0c09188c */
if(!s->budget--) { s->failed_pc=0x0c09188cu; return 0; }
r[0]=0x00000004u;
goto P_0c09188e;
P_0c09188e: /* original f546, guest PC 0x0c09188e */
if(!s->budget--) { s->failed_pc=0x0c09188eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c091890;
P_0c091890: /* original e00c, guest PC 0x0c091890 */
if(!s->budget--) { s->failed_pc=0x0c091890u; return 0; }
r[0]=0x0000000cu;
goto P_0c091892;
P_0c091892: /* original f646, guest PC 0x0c091892 */
if(!s->budget--) { s->failed_pc=0x0c091892u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c091894;
P_0c091894: /* original e01c, guest PC 0x0c091894 */
if(!s->budget--) { s->failed_pc=0x0c091894u; return 0; }
r[0]=0x0000001cu;
goto P_0c091896;
P_0c091896: /* original f746, guest PC 0x0c091896 */
if(!s->budget--) { s->failed_pc=0x0c091896u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c091898;
P_0c091898: /* original e004, guest PC 0x0c091898 */
if(!s->budget--) { s->failed_pc=0x0c091898u; return 0; }
r[0]=0x00000004u;
goto P_0c09189a;
P_0c09189a: /* original f3f6, guest PC 0x0c09189a */
if(!s->budget--) { s->failed_pc=0x0c09189au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09189c;
P_0c09189c: /* original f354, guest PC 0x0c09189c */
if(!s->budget--) { s->failed_pc=0x0c09189cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[5]))!=0);
goto P_0c09189e;
P_0c09189e: /* original 8b06, guest PC 0x0c09189e */
if(!s->budget--) { s->failed_pc=0x0c09189eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0918ae; }
goto P_0c0918a0;
P_0c0918a0: /* original f3f8, guest PC 0x0c0918a0 */
if(!s->budget--) { s->failed_pc=0x0c0918a0u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0918a2;
P_0c0918a2: /* original f364, guest PC 0x0c0918a2 */
if(!s->budget--) { s->failed_pc=0x0c0918a2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[6]))!=0);
goto P_0c0918a4;
P_0c0918a4: /* original 8b03, guest PC 0x0c0918a4 */
if(!s->budget--) { s->failed_pc=0x0c0918a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0918ae; }
goto P_0c0918a6;
P_0c0918a6: /* original c732, guest PC 0x0c0918a6 */
if(!s->budget--) { s->failed_pc=0x0c0918a6u; return 0; }
r[0]=0x0c091970u;
goto P_0c0918a8;
P_0c0918a8: /* original f408, guest PC 0x0c0918a8 */
if(!s->budget--) { s->failed_pc=0x0c0918a8u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0918aa;
P_0c0918aa: /* original f640, guest PC 0x0c0918aa */
if(!s->budget--) { s->failed_pc=0x0c0918aau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'+');
goto P_0c0918ac;
P_0c0918ac: /* original f540, guest PC 0x0c0918ac */
if(!s->budget--) { s->failed_pc=0x0c0918acu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'+');
goto P_0c0918ae;
P_0c0918ae: /* original e004, guest PC 0x0c0918ae */
if(!s->budget--) { s->failed_pc=0x0c0918aeu; return 0; }
r[0]=0x00000004u;
goto P_0c0918b0;
P_0c0918b0: /* original fff8, guest PC 0x0c0918b0 */
if(!s->budget--) { s->failed_pc=0x0c0918b0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
goto P_0c0918b2;
P_0c0918b2: /* original f4f6, guest PC 0x0c0918b2 */
if(!s->budget--) { s->failed_pc=0x0c0918b2u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0918b4;
P_0c0918b4: /* original ff61, guest PC 0x0c0918b4 */
if(!s->budget--) { s->failed_pc=0x0c0918b4u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[6],r[18],'-');
goto P_0c0918b6;
P_0c0918b6: /* original f67c, guest PC 0x0c0918b6 */
if(!s->budget--) { s->failed_pc=0x0c0918b6u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c0918b8;
P_0c0918b8: /* original f451, guest PC 0x0c0918b8 */
if(!s->budget--) { s->failed_pc=0x0c0918b8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c0918ba;
P_0c0918ba: /* original f672, guest PC 0x0c0918ba */
if(!s->budget--) { s->failed_pc=0x0c0918bau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c0918bc;
P_0c0918bc: /* original f0fc, guest PC 0x0c0918bc */
if(!s->budget--) { s->failed_pc=0x0c0918bcu; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c0918be;
P_0c0918be: /* original f34c, guest PC 0x0c0918be */
if(!s->budget--) { s->failed_pc=0x0c0918beu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0918c0;
P_0c0918c0: /* original f432, guest PC 0x0c0918c0 */
if(!s->budget--) { s->failed_pc=0x0c0918c0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0918c2;
P_0c0918c2: /* original f36c, guest PC 0x0c0918c2 */
if(!s->budget--) { s->failed_pc=0x0c0918c2u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c0918c4;
P_0c0918c4: /* original f24c, guest PC 0x0c0918c4 */
if(!s->budget--) { s->failed_pc=0x0c0918c4u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0918c6;
P_0c0918c6: /* original f2fe, guest PC 0x0c0918c6 */
if(!s->budget--) { s->failed_pc=0x0c0918c6u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[15],fr[2],r[18]);
goto P_0c0918c8;
P_0c0918c8: /* original f0ec, guest PC 0x0c0918c8 */
if(!s->budget--) { s->failed_pc=0x0c0918c8u; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c0918ca;
P_0c0918ca: /* original f3ee, guest PC 0x0c0918ca */
if(!s->budget--) { s->failed_pc=0x0c0918cau; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[14],fr[3],r[18]);
goto P_0c0918cc;
P_0c0918cc: /* original f42c, guest PC 0x0c0918cc */
if(!s->budget--) { s->failed_pc=0x0c0918ccu; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0918ce;
P_0c0918ce: /* original f63c, guest PC 0x0c0918ce */
if(!s->budget--) { s->failed_pc=0x0c0918ceu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c0918d0;
P_0c0918d0: /* original f465, guest PC 0x0c0918d0 */
if(!s->budget--) { s->failed_pc=0x0c0918d0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c0918d2;
P_0c0918d2: /* original 8914, guest PC 0x0c0918d2 */
if(!s->budget--) { s->failed_pc=0x0c0918d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0918fe; }
goto P_0c0918d4;
P_0c0918d4: /* original c727, guest PC 0x0c0918d4 */
if(!s->budget--) { s->failed_pc=0x0c0918d4u; return 0; }
r[0]=0x0c091974u;
goto P_0c0918d6;
P_0c0918d6: /* original f308, guest PC 0x0c0918d6 */
if(!s->budget--) { s->failed_pc=0x0c0918d6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0918d8;
P_0c0918d8: /* original f345, guest PC 0x0c0918d8 */
if(!s->budget--) { s->failed_pc=0x0c0918d8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0918da;
P_0c0918da: /* original 8f02, guest PC 0x0c0918da */
if(!s->budget--) { s->failed_pc=0x0c0918dau; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,6,15);
if(!cond) { goto P_0c0918e2; }
goto P_0c0918de;
P_0c0918dc: /* original f6fc, guest PC 0x0c0918dc */
if(!s->budget--) { s->failed_pc=0x0c0918dcu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0918de;
P_0c0918de: /* original a001, guest PC 0x0c0918de */
if(!s->budget--) { s->failed_pc=0x0c0918deu; return 0; }
fr[4]=0;
goto P_0c0918e4;
P_0c0918e0: /* original f48d, guest PC 0x0c0918e0 */
if(!s->budget--) { s->failed_pc=0x0c0918e0u; return 0; }
fr[4]=0;
goto P_0c0918e2;
P_0c0918e2: /* original f47d, guest PC 0x0c0918e2 */
if(!s->budget--) { s->failed_pc=0x0c0918e2u; return 0; }
if(!vf3_fpu_fsrra(fr[4],r[18],&fr[4])) goto unsupported;
goto P_0c0918e4;
P_0c0918e4: /* original c724, guest PC 0x0c0918e4 */
if(!s->budget--) { s->failed_pc=0x0c0918e4u; return 0; }
r[0]=0x0c091978u;
goto P_0c0918e6;
P_0c0918e6: /* original f642, guest PC 0x0c0918e6 */
if(!s->budget--) { s->failed_pc=0x0c0918e6u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c0918e8;
P_0c0918e8: /* original f542, guest PC 0x0c0918e8 */
if(!s->budget--) { s->failed_pc=0x0c0918e8u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c0918ea;
P_0c0918ea: /* original f408, guest PC 0x0c0918ea */
if(!s->budget--) { s->failed_pc=0x0c0918eau; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0918ec;
P_0c0918ec: /* original e004, guest PC 0x0c0918ec */
if(!s->budget--) { s->failed_pc=0x0c0918ecu; return 0; }
r[0]=0x00000004u;
goto P_0c0918ee;
P_0c0918ee: /* original f3f6, guest PC 0x0c0918ee */
if(!s->budget--) { s->failed_pc=0x0c0918eeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0918f0;
P_0c0918f0: /* original e004, guest PC 0x0c0918f0 */
if(!s->budget--) { s->failed_pc=0x0c0918f0u; return 0; }
r[0]=0x00000004u;
goto P_0c0918f2;
P_0c0918f2: /* original f04c, guest PC 0x0c0918f2 */
if(!s->budget--) { s->failed_pc=0x0c0918f2u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0918f4;
P_0c0918f4: /* original f35e, guest PC 0x0c0918f4 */
if(!s->budget--) { s->failed_pc=0x0c0918f4u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c0918f6;
P_0c0918f6: /* original ff37, guest PC 0x0c0918f6 */
if(!s->budget--) { s->failed_pc=0x0c0918f6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0918f8;
P_0c0918f8: /* original f2f8, guest PC 0x0c0918f8 */
if(!s->budget--) { s->failed_pc=0x0c0918f8u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0918fa;
P_0c0918fa: /* original f26e, guest PC 0x0c0918fa */
if(!s->budget--) { s->failed_pc=0x0c0918fau; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[6],fr[2],r[18]);
goto P_0c0918fc;
P_0c0918fc: /* original ff2a, guest PC 0x0c0918fc */
if(!s->budget--) { s->failed_pc=0x0c0918fcu; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0918fe;
P_0c0918fe: /* original 4610, guest PC 0x0c0918fe */
if(!s->budget--) { s->failed_pc=0x0c0918feu; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c091900;
P_0c091900: /* original 8fc1, guest PC 0x0c091900 */
if(!s->budget--) { s->failed_pc=0x0c091900u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000004u;
if(!cond) { goto P_0c091886; }
goto P_0c091904;
P_0c091902: /* original 7704, guest PC 0x0c091902 */
if(!s->budget--) { s->failed_pc=0x0c091902u; return 0; }
r[7]+=0x00000004u;
goto P_0c091904;
P_0c091904: /* original e008, guest PC 0x0c091904 */
if(!s->budget--) { s->failed_pc=0x0c091904u; return 0; }
r[0]=0x00000008u;
goto P_0c091906;
P_0c091906: /* original 54d4, guest PC 0x0c091906 */
if(!s->budget--) { s->failed_pc=0x0c091906u; return 0; }
r[4]=read(ram,r[13]+16,4);
goto P_0c091908;
P_0c091908: /* original ffe6, guest PC 0x0c091908 */
if(!s->budget--) { s->failed_pc=0x0c091908u; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c09190a;
P_0c09190a: /* original e014, guest PC 0x0c09190a */
if(!s->budget--) { s->failed_pc=0x0c09190au; return 0; }
r[0]=0x00000014u;
goto P_0c09190c;
P_0c09190c: /* original f4e6, guest PC 0x0c09190c */
if(!s->budget--) { s->failed_pc=0x0c09190cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c09190e;
P_0c09190e: /* original 65f3, guest PC 0x0c09190e */
if(!s->budget--) { s->failed_pc=0x0c09190eu; return 0; }
r[5]=r[15];
goto P_0c091910;
P_0c091910: /* original f5ec, guest PC 0x0c091910 */
if(!s->budget--) { s->failed_pc=0x0c091910u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c091912;
P_0c091912: /* original 66f3, guest PC 0x0c091912 */
if(!s->budget--) { s->failed_pc=0x0c091912u; return 0; }
r[6]=r[15];
goto P_0c091914;
P_0c091914: /* original ff41, guest PC 0x0c091914 */
if(!s->budget--) { s->failed_pc=0x0c091914u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'-');
goto P_0c091916;
P_0c091916: /* original ff41, guest PC 0x0c091916 */
if(!s->budget--) { s->failed_pc=0x0c091916u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'-');
goto P_0c091918;
P_0c091918: /* original f4fc, guest PC 0x0c091918 */
if(!s->budget--) { s->failed_pc=0x0c091918u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09191a;
P_0c09191a: /* original b031, guest PC 0x0c09191a */
if(!s->budget--) { s->failed_pc=0x0c09191au; return 0; }
target=0x0c091980u; r[16]=0x0c09191eu;
r[5]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09191eu) { target=s->pc; goto dispatch; }
goto P_0c09191e;
P_0c09191c: /* original 7504, guest PC 0x0c09191c */
if(!s->budget--) { s->failed_pc=0x0c09191cu; return 0; }
r[5]+=0x00000004u;
goto P_0c09191e;
P_0c09191e: /* original 54d5, guest PC 0x0c09191e */
if(!s->budget--) { s->failed_pc=0x0c09191eu; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c091920;
P_0c091920: /* original 65f3, guest PC 0x0c091920 */
if(!s->budget--) { s->failed_pc=0x0c091920u; return 0; }
r[5]=r[15];
goto P_0c091922;
P_0c091922: /* original f4fc, guest PC 0x0c091922 */
if(!s->budget--) { s->failed_pc=0x0c091922u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c091924;
P_0c091924: /* original 66f3, guest PC 0x0c091924 */
if(!s->budget--) { s->failed_pc=0x0c091924u; return 0; }
r[6]=r[15];
goto P_0c091926;
P_0c091926: /* original f5ec, guest PC 0x0c091926 */
if(!s->budget--) { s->failed_pc=0x0c091926u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c091928;
P_0c091928: /* original b02a, guest PC 0x0c091928 */
if(!s->budget--) { s->failed_pc=0x0c091928u; return 0; }
target=0x0c091980u; r[16]=0x0c09192cu;
r[5]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09192cu) { target=s->pc; goto dispatch; }
goto P_0c09192c;
P_0c09192a: /* original 7504, guest PC 0x0c09192a */
if(!s->budget--) { s->failed_pc=0x0c09192au; return 0; }
r[5]+=0x00000004u;
goto P_0c09192c;
P_0c09192c: /* original f5f8, guest PC 0x0c09192c */
if(!s->budget--) { s->failed_pc=0x0c09192cu; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09192e;
P_0c09192e: /* original e004, guest PC 0x0c09192e */
if(!s->budget--) { s->failed_pc=0x0c09192eu; return 0; }
r[0]=0x00000004u;
goto P_0c091930;
P_0c091930: /* original d312, guest PC 0x0c091930 */
if(!s->budget--) { s->failed_pc=0x0c091930u; return 0; }
r[3]=read(ram,0x0c09197cu,4);
goto P_0c091932;
P_0c091932: /* original f54d, guest PC 0x0c091932 */
if(!s->budget--) { s->failed_pc=0x0c091932u; return 0; }
fr[5]^=0x80000000u;
goto P_0c091934;
P_0c091934: /* original 430b, guest PC 0x0c091934 */
if(!s->budget--) { s->failed_pc=0x0c091934u; return 0; }
target=r[3];
r[16]=0x0c091938u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091938u) { target=s->pc; goto dispatch; }
goto P_0c091938;
P_0c091936: /* original f4f6, guest PC 0x0c091936 */
if(!s->budget--) { s->failed_pc=0x0c091936u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c091938;
P_0c091938: /* original e014, guest PC 0x0c091938 */
if(!s->budget--) { s->failed_pc=0x0c091938u; return 0; }
r[0]=0x00000014u;
goto P_0c09193a;
P_0c09193a: /* original f40c, guest PC 0x0c09193a */
if(!s->budget--) { s->failed_pc=0x0c09193au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c09193c;
P_0c09193c: /* original f5e6, guest PC 0x0c09193c */
if(!s->budget--) { s->failed_pc=0x0c09193cu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c09193e;
P_0c09193e: /* original e004, guest PC 0x0c09193e */
if(!s->budget--) { s->failed_pc=0x0c09193eu; return 0; }
r[0]=0x00000004u;
goto P_0c091940;
P_0c091940: /* original f3f6, guest PC 0x0c091940 */
if(!s->budget--) { s->failed_pc=0x0c091940u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c091942;
P_0c091942: /* original e004, guest PC 0x0c091942 */
if(!s->budget--) { s->failed_pc=0x0c091942u; return 0; }
r[0]=0x00000004u;
goto P_0c091944;
P_0c091944: /* original f451, guest PC 0x0c091944 */
if(!s->budget--) { s->failed_pc=0x0c091944u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c091946;
P_0c091946: /* original fe37, guest PC 0x0c091946 */
if(!s->budget--) { s->failed_pc=0x0c091946u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c091948;
P_0c091948: /* original e008, guest PC 0x0c091948 */
if(!s->budget--) { s->failed_pc=0x0c091948u; return 0; }
r[0]=0x00000008u;
goto P_0c09194a;
P_0c09194a: /* original fe47, guest PC 0x0c09194a */
if(!s->budget--) { s->failed_pc=0x0c09194au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c09194c;
P_0c09194c: /* original e00c, guest PC 0x0c09194c */
if(!s->budget--) { s->failed_pc=0x0c09194cu; return 0; }
r[0]=0x0000000cu;
goto P_0c09194e;
P_0c09194e: /* original f3f8, guest PC 0x0c09194e */
if(!s->budget--) { s->failed_pc=0x0c09194eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c091950;
P_0c091950: /* original fe37, guest PC 0x0c091950 */
if(!s->budget--) { s->failed_pc=0x0c091950u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c091952;
P_0c091952: /* original e400, guest PC 0x0c091952 */
if(!s->budget--) { s->failed_pc=0x0c091952u; return 0; }
r[4]=0x00000000u;
goto P_0c091954;
P_0c091954: /* original 7f0c, guest PC 0x0c091954 */
if(!s->budget--) { s->failed_pc=0x0c091954u; return 0; }
r[15]+=0x0000000cu;
goto P_0c091956;
P_0c091956: /* original 6043, guest PC 0x0c091956 */
if(!s->budget--) { s->failed_pc=0x0c091956u; return 0; }
r[0]=r[4];
goto P_0c091958;
P_0c091958: /* original 4f26, guest PC 0x0c091958 */
if(!s->budget--) { s->failed_pc=0x0c091958u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09195a;
P_0c09195a: /* original fef9, guest PC 0x0c09195a */
if(!s->budget--) { s->failed_pc=0x0c09195au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09195c;
P_0c09195c: /* original fff9, guest PC 0x0c09195c */
if(!s->budget--) { s->failed_pc=0x0c09195cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09195e;
P_0c09195e: /* original 6df6, guest PC 0x0c09195e */
if(!s->budget--) { s->failed_pc=0x0c09195eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c091960;
P_0c091960: /* original 000b, guest PC 0x0c091960 */
if(!s->budget--) { s->failed_pc=0x0c091960u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c091962: /* original 6ef6, guest PC 0x0c091962 */
if(!s->budget--) { s->failed_pc=0x0c091962u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c091964u,s,ram);
P_0c094372: /* original 4f22, guest PC 0x0c094372 */
if(!s->budget--) { s->failed_pc=0x0c094372u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c094374;
P_0c094374: /* original 7fd8, guest PC 0x0c094374 */
if(!s->budget--) { s->failed_pc=0x0c094374u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c094376;
P_0c094376: /* original 2f42, guest PC 0x0c094376 */
if(!s->budget--) { s->failed_pc=0x0c094376u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c094378;
P_0c094378: /* original 1f51, guest PC 0x0c094378 */
if(!s->budget--) { s->failed_pc=0x0c094378u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c09437a;
P_0c09437a: /* original d41a, guest PC 0x0c09437a */
if(!s->budget--) { s->failed_pc=0x0c09437au; return 0; }
r[4]=read(ram,0x0c0943e4u,4);
goto P_0c09437c;
P_0c09437c: /* original 901e, guest PC 0x0c09437c */
if(!s->budget--) { s->failed_pc=0x0c09437cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0943bcu,2);
goto P_0c09437e;
P_0c09437e: /* original dd18, guest PC 0x0c09437e */
if(!s->budget--) { s->failed_pc=0x0c09437eu; return 0; }
r[13]=read(ram,0x0c0943e0u,4);
goto P_0c094380;
P_0c094380: /* original 034e, guest PC 0x0c094380 */
if(!s->budget--) { s->failed_pc=0x0c094380u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c094382;
P_0c094382: /* original 2338, guest PC 0x0c094382 */
if(!s->budget--) { s->failed_pc=0x0c094382u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c094384;
P_0c094384: /* original 8900, guest PC 0x0c094384 */
if(!s->budget--) { s->failed_pc=0x0c094384u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094388; }
goto P_0c094386;
P_0c094386: /* original dd18, guest PC 0x0c094386 */
if(!s->budget--) { s->failed_pc=0x0c094386u; return 0; }
r[13]=read(ram,0x0c0943e8u,4);
goto P_0c094388;
P_0c094388: /* original c718, guest PC 0x0c094388 */
if(!s->budget--) { s->failed_pc=0x0c094388u; return 0; }
r[0]=0x0c0943ecu;
goto P_0c09438a;
P_0c09438a: /* original ff08, guest PC 0x0c09438a */
if(!s->budget--) { s->failed_pc=0x0c09438au; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c09438c;
P_0c09438c: /* original 6cd1, guest PC 0x0c09438c */
if(!s->budget--) { s->failed_pc=0x0c09438cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[12]=tmp;
goto P_0c09438e;
P_0c09438e: /* original 2cc8, guest PC 0x0c09438e */
if(!s->budget--) { s->failed_pc=0x0c09438eu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c094390;
P_0c094390: /* original 8b02, guest PC 0x0c094390 */
if(!s->budget--) { s->failed_pc=0x0c094390u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094398; }
goto P_0c094392;
P_0c094392: /* original d317, guest PC 0x0c094392 */
if(!s->budget--) { s->failed_pc=0x0c094392u; return 0; }
r[3]=read(ram,0x0c0943f0u,4);
goto P_0c094394;
P_0c094394: /* original 432b, guest PC 0x0c094394 */
if(!s->budget--) { s->failed_pc=0x0c094394u; return 0; }
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
P_0c094396: /* original 0009, guest PC 0x0c094396 */
if(!s->budget--) { s->failed_pc=0x0c094396u; return 0; }
goto P_0c094398;
P_0c094398: /* original 85d1, guest PC 0x0c094398 */
if(!s->budget--) { s->failed_pc=0x0c094398u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+2,2);
goto P_0c09439a;
P_0c09439a: /* original 5ef1, guest PC 0x0c09439a */
if(!s->budget--) { s->failed_pc=0x0c09439au; return 0; }
r[14]=read(ram,r[15]+4,4);
goto P_0c09439c;
P_0c09439c: /* original 6403, guest PC 0x0c09439c */
if(!s->budget--) { s->failed_pc=0x0c09439cu; return 0; }
r[4]=r[0];
goto P_0c09439e;
P_0c09439e: /* original 3e4c, guest PC 0x0c09439e */
if(!s->budget--) { s->failed_pc=0x0c09439eu; return 0; }
r[14]+=r[4];
goto P_0c0943a0;
P_0c0943a0: /* original 0e83, guest PC 0x0c0943a0 */
if(!s->budget--) { s->failed_pc=0x0c0943a0u; return 0; }
goto P_0c0943a2;
P_0c0943a2: /* original 53d1, guest PC 0x0c0943a2 */
if(!s->budget--) { s->failed_pc=0x0c0943a2u; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0943a4;
P_0c0943a4: /* original 1f32, guest PC 0x0c0943a4 */
if(!s->budget--) { s->failed_pc=0x0c0943a4u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0943a6;
P_0c0943a6: /* original 52d2, guest PC 0x0c0943a6 */
if(!s->budget--) { s->failed_pc=0x0c0943a6u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0943a8;
P_0c0943a8: /* original 1f23, guest PC 0x0c0943a8 */
if(!s->budget--) { s->failed_pc=0x0c0943a8u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c0943aa;
P_0c0943aa: /* original d312, guest PC 0x0c0943aa */
if(!s->budget--) { s->failed_pc=0x0c0943aau; return 0; }
r[3]=read(ram,0x0c0943f4u,4);
goto P_0c0943ac;
P_0c0943ac: /* original 430b, guest PC 0x0c0943ac */
if(!s->budget--) { s->failed_pc=0x0c0943acu; return 0; }
target=r[3];
r[16]=0x0c0943b0u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0943b0u) { target=s->pc; goto dispatch; }
goto P_0c0943b0;
P_0c0943ae: /* original 64f2, guest PC 0x0c0943ae */
if(!s->budget--) { s->failed_pc=0x0c0943aeu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0943b0;
P_0c0943b0: /* original 64d3, guest PC 0x0c0943b0 */
if(!s->budget--) { s->failed_pc=0x0c0943b0u; return 0; }
r[4]=r[13];
goto P_0c0943b2;
P_0c0943b2: /* original 65f3, guest PC 0x0c0943b2 */
if(!s->budget--) { s->failed_pc=0x0c0943b2u; return 0; }
r[5]=r[15];
goto P_0c0943b4;
P_0c0943b4: /* original 740c, guest PC 0x0c0943b4 */
if(!s->budget--) { s->failed_pc=0x0c0943b4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0943b6;
P_0c0943b6: /* original 751c, guest PC 0x0c0943b6 */
if(!s->budget--) { s->failed_pc=0x0c0943b6u; return 0; }
r[5]+=0x0000001cu;
goto P_0c0943b8;
P_0c0943b8: /* original a01e, guest PC 0x0c0943b8 */
if(!s->budget--) { s->failed_pc=0x0c0943b8u; return 0; }
goto P_0c0943f8;
P_0c0943ba: /* original 0009, guest PC 0x0c0943ba */
if(!s->budget--) { s->failed_pc=0x0c0943bau; return 0; }
return vf3_matrix_family(0x0c0943bcu,s,ram);
P_0c0943f8: /* original f449, guest PC 0x0c0943f8 */
if(!s->budget--) { s->failed_pc=0x0c0943f8u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0943fa;
P_0c0943fa: /* original f549, guest PC 0x0c0943fa */
if(!s->budget--) { s->failed_pc=0x0c0943fau; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c0943fc;
P_0c0943fc: /* original f648, guest PC 0x0c0943fc */
if(!s->budget--) { s->failed_pc=0x0c0943fcu; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0943fe;
P_0c0943fe: /* original f79d, guest PC 0x0c0943fe */
if(!s->budget--) { s->failed_pc=0x0c0943feu; return 0; }
fr[7]=0x3f800000u;
goto P_0c094400;
P_0c094400: /* original f5fd, guest PC 0x0c094400 */
if(!s->budget--) { s->failed_pc=0x0c094400u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c094402;
P_0c094402: /* original 750c, guest PC 0x0c094402 */
if(!s->budget--) { s->failed_pc=0x0c094402u; return 0; }
r[5]+=0x0000000cu;
goto P_0c094404;
P_0c094404: /* original f56b, guest PC 0x0c094404 */
if(!s->budget--) { s->failed_pc=0x0c094404u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c094406;
P_0c094406: /* original f55b, guest PC 0x0c094406 */
if(!s->budget--) { s->failed_pc=0x0c094406u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c094408;
P_0c094408: /* original f54b, guest PC 0x0c094408 */
if(!s->budget--) { s->failed_pc=0x0c094408u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c09440a;
P_0c09440a: /* original 0009, guest PC 0x0c09440a */
if(!s->budget--) { s->failed_pc=0x0c09440au; return 0; }
goto P_0c09440c;
P_0c09440c: /* original 7d18, guest PC 0x0c09440c */
if(!s->budget--) { s->failed_pc=0x0c09440cu; return 0; }
r[13]+=0x00000018u;
goto P_0c09440e;
P_0c09440e: /* original d303, guest PC 0x0c09440e */
if(!s->budget--) { s->failed_pc=0x0c09440eu; return 0; }
r[3]=read(ram,0x0c09441cu,4);
goto P_0c094410;
P_0c094410: /* original 430b, guest PC 0x0c094410 */
if(!s->budget--) { s->failed_pc=0x0c094410u; return 0; }
target=r[3];
r[16]=0x0c094414u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094414u) { target=s->pc; goto dispatch; }
goto P_0c094414;
P_0c094412: /* original 64e3, guest PC 0x0c094412 */
if(!s->budget--) { s->failed_pc=0x0c094412u; return 0; }
r[4]=r[14];
goto P_0c094414;
P_0c094414: /* original 64f3, guest PC 0x0c094414 */
if(!s->budget--) { s->failed_pc=0x0c094414u; return 0; }
r[4]=r[15];
goto P_0c094416;
P_0c094416: /* original 741c, guest PC 0x0c094416 */
if(!s->budget--) { s->failed_pc=0x0c094416u; return 0; }
r[4]+=0x0000001cu;
goto P_0c094418;
P_0c094418: /* original a002, guest PC 0x0c094418 */
if(!s->budget--) { s->failed_pc=0x0c094418u; return 0; }
goto P_0c094420;
P_0c09441a: /* original 0009, guest PC 0x0c09441a */
if(!s->budget--) { s->failed_pc=0x0c09441au; return 0; }
return vf3_matrix_family(0x0c09441cu,s,ram);
P_0c094420: /* original fbfd, guest PC 0x0c094420 */
if(!s->budget--) { s->failed_pc=0x0c094420u; return 0; }
vf3_matrix_swap(s);
goto P_0c094422;
P_0c094422: /* original fc49, guest PC 0x0c094422 */
if(!s->budget--) { s->failed_pc=0x0c094422u; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094424;
P_0c094424: /* original fd49, guest PC 0x0c094424 */
if(!s->budget--) { s->failed_pc=0x0c094424u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094426;
P_0c094426: /* original fe49, guest PC 0x0c094426 */
if(!s->budget--) { s->failed_pc=0x0c094426u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094428;
P_0c094428: /* original fbfd, guest PC 0x0c094428 */
if(!s->budget--) { s->failed_pc=0x0c094428u; return 0; }
vf3_matrix_swap(s);
goto P_0c09442a;
P_0c09442a: /* original 0009, guest PC 0x0c09442a */
if(!s->budget--) { s->failed_pc=0x0c09442au; return 0; }
goto P_0c09442c;
P_0c09442c: /* original 4c10, guest PC 0x0c09442c */
if(!s->budget--) { s->failed_pc=0x0c09442cu; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c09442e;
P_0c09442e: /* original 8d15, guest PC 0x0c09442e */
if(!s->budget--) { s->failed_pc=0x0c09442eu; return 0; }
cond=r[17]&1u;
r[11]=read(ram,r[15]+12,4);
if(cond) { goto P_0c09445c; }
goto P_0c094432;
P_0c094430: /* original 5bf3, guest PC 0x0c094430 */
if(!s->budget--) { s->failed_pc=0x0c094430u; return 0; }
r[11]=read(ram,r[15]+12,4);
goto P_0c094432;
P_0c094432: /* original e01c, guest PC 0x0c094432 */
if(!s->budget--) { s->failed_pc=0x0c094432u; return 0; }
r[0]=0x0000001cu;
goto P_0c094434;
P_0c094434: /* original f2e9, guest PC 0x0c094434 */
if(!s->budget--) { s->failed_pc=0x0c094434u; return 0; }
vf3_matrix_load(s,ram,2,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c094436;
P_0c094436: /* original f3f6, guest PC 0x0c094436 */
if(!s->budget--) { s->failed_pc=0x0c094436u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c094438;
P_0c094438: /* original e01c, guest PC 0x0c094438 */
if(!s->budget--) { s->failed_pc=0x0c094438u; return 0; }
r[0]=0x0000001cu;
goto P_0c09443a;
P_0c09443a: /* original f0fc, guest PC 0x0c09443a */
if(!s->budget--) { s->failed_pc=0x0c09443au; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c09443c;
P_0c09443c: /* original f32e, guest PC 0x0c09443c */
if(!s->budget--) { s->failed_pc=0x0c09443cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09443e;
P_0c09443e: /* original 5bf2, guest PC 0x0c09443e */
if(!s->budget--) { s->failed_pc=0x0c09443eu; return 0; }
r[11]=read(ram,r[15]+8,4);
goto P_0c094440;
P_0c094440: /* original ff37, guest PC 0x0c094440 */
if(!s->budget--) { s->failed_pc=0x0c094440u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c094442;
P_0c094442: /* original e020, guest PC 0x0c094442 */
if(!s->budget--) { s->failed_pc=0x0c094442u; return 0; }
r[0]=0x00000020u;
goto P_0c094444;
P_0c094444: /* original f2e9, guest PC 0x0c094444 */
if(!s->budget--) { s->failed_pc=0x0c094444u; return 0; }
vf3_matrix_load(s,ram,2,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c094446;
P_0c094446: /* original f3f6, guest PC 0x0c094446 */
if(!s->budget--) { s->failed_pc=0x0c094446u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c094448;
P_0c094448: /* original e020, guest PC 0x0c094448 */
if(!s->budget--) { s->failed_pc=0x0c094448u; return 0; }
r[0]=0x00000020u;
goto P_0c09444a;
P_0c09444a: /* original f32e, guest PC 0x0c09444a */
if(!s->budget--) { s->failed_pc=0x0c09444au; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09444c;
P_0c09444c: /* original ff37, guest PC 0x0c09444c */
if(!s->budget--) { s->failed_pc=0x0c09444cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09444e;
P_0c09444e: /* original e024, guest PC 0x0c09444e */
if(!s->budget--) { s->failed_pc=0x0c09444eu; return 0; }
r[0]=0x00000024u;
goto P_0c094450;
P_0c094450: /* original f2e9, guest PC 0x0c094450 */
if(!s->budget--) { s->failed_pc=0x0c094450u; return 0; }
vf3_matrix_load(s,ram,2,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c094452;
P_0c094452: /* original f3f6, guest PC 0x0c094452 */
if(!s->budget--) { s->failed_pc=0x0c094452u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c094454;
P_0c094454: /* original e024, guest PC 0x0c094454 */
if(!s->budget--) { s->failed_pc=0x0c094454u; return 0; }
r[0]=0x00000024u;
goto P_0c094456;
P_0c094456: /* original 7e18, guest PC 0x0c094456 */
if(!s->budget--) { s->failed_pc=0x0c094456u; return 0; }
r[14]+=0x00000018u;
goto P_0c094458;
P_0c094458: /* original f32e, guest PC 0x0c094458 */
if(!s->budget--) { s->failed_pc=0x0c094458u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09445a;
P_0c09445a: /* original ff37, guest PC 0x0c09445a */
if(!s->budget--) { s->failed_pc=0x0c09445au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09445c;
P_0c09445c: /* original d303, guest PC 0x0c09445c */
if(!s->budget--) { s->failed_pc=0x0c09445cu; return 0; }
r[3]=read(ram,0x0c09446cu,4);
goto P_0c09445e;
P_0c09445e: /* original 430b, guest PC 0x0c09445e */
if(!s->budget--) { s->failed_pc=0x0c09445eu; return 0; }
target=r[3];
r[16]=0x0c094462u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094462u) { target=s->pc; goto dispatch; }
goto P_0c094462;
P_0c094460: /* original 64b3, guest PC 0x0c094460 */
if(!s->budget--) { s->failed_pc=0x0c094460u; return 0; }
r[4]=r[11];
goto P_0c094462;
P_0c094462: /* original 64f3, guest PC 0x0c094462 */
if(!s->budget--) { s->failed_pc=0x0c094462u; return 0; }
r[4]=r[15];
goto P_0c094464;
P_0c094464: /* original 741c, guest PC 0x0c094464 */
if(!s->budget--) { s->failed_pc=0x0c094464u; return 0; }
r[4]+=0x0000001cu;
goto P_0c094466;
P_0c094466: /* original a003, guest PC 0x0c094466 */
if(!s->budget--) { s->failed_pc=0x0c094466u; return 0; }
goto P_0c094470;
P_0c094468: /* original 0009, guest PC 0x0c094468 */
if(!s->budget--) { s->failed_pc=0x0c094468u; return 0; }
return vf3_matrix_family(0x0c09446au,s,ram);
P_0c094470: /* original fbfd, guest PC 0x0c094470 */
if(!s->budget--) { s->failed_pc=0x0c094470u; return 0; }
vf3_matrix_swap(s);
goto P_0c094472;
P_0c094472: /* original fc49, guest PC 0x0c094472 */
if(!s->budget--) { s->failed_pc=0x0c094472u; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094474;
P_0c094474: /* original fd49, guest PC 0x0c094474 */
if(!s->budget--) { s->failed_pc=0x0c094474u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094476;
P_0c094476: /* original fe49, guest PC 0x0c094476 */
if(!s->budget--) { s->failed_pc=0x0c094476u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094478;
P_0c094478: /* original fbfd, guest PC 0x0c094478 */
if(!s->budget--) { s->failed_pc=0x0c094478u; return 0; }
vf3_matrix_swap(s);
goto P_0c09447a;
P_0c09447a: /* original 0009, guest PC 0x0c09447a */
if(!s->budget--) { s->failed_pc=0x0c09447au; return 0; }
goto P_0c09447c;
P_0c09447c: /* original 2cc8, guest PC 0x0c09447c */
if(!s->budget--) { s->failed_pc=0x0c09447cu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c09447e;
P_0c09447e: /* original 8902, guest PC 0x0c09447e */
if(!s->budget--) { s->failed_pc=0x0c09447eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094486; }
goto P_0c094480;
P_0c094480: /* original d32a, guest PC 0x0c094480 */
if(!s->budget--) { s->failed_pc=0x0c094480u; return 0; }
r[3]=read(ram,0x0c09452cu,4);
goto P_0c094482;
P_0c094482: /* original 432b, guest PC 0x0c094482 */
if(!s->budget--) { s->failed_pc=0x0c094482u; return 0; }
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
P_0c094484: /* original 0009, guest PC 0x0c094484 */
if(!s->budget--) { s->failed_pc=0x0c094484u; return 0; }
goto P_0c094486;
P_0c094486: /* original d32a, guest PC 0x0c094486 */
if(!s->budget--) { s->failed_pc=0x0c094486u; return 0; }
r[3]=read(ram,0x0c094530u,4);
goto P_0c094488;
P_0c094488: /* original 432b, guest PC 0x0c094488 */
if(!s->budget--) { s->failed_pc=0x0c094488u; return 0; }
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
P_0c09448a: /* original 0009, guest PC 0x0c09448a */
if(!s->budget--) { s->failed_pc=0x0c09448au; return 0; }
goto P_0c09448c;
P_0c09448c: /* original 7f28, guest PC 0x0c09448c */
if(!s->budget--) { s->failed_pc=0x0c09448cu; return 0; }
r[15]+=0x00000028u;
goto P_0c09448e;
P_0c09448e: /* original 4f26, guest PC 0x0c09448e */
if(!s->budget--) { s->failed_pc=0x0c09448eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c094490;
P_0c094490: /* original fff9, guest PC 0x0c094490 */
if(!s->budget--) { s->failed_pc=0x0c094490u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c094492;
P_0c094492: /* original 6bf6, guest PC 0x0c094492 */
if(!s->budget--) { s->failed_pc=0x0c094492u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c094494;
P_0c094494: /* original 6cf6, guest PC 0x0c094494 */
if(!s->budget--) { s->failed_pc=0x0c094494u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c094496;
P_0c094496: /* original 6df6, guest PC 0x0c094496 */
if(!s->budget--) { s->failed_pc=0x0c094496u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c094498;
P_0c094498: /* original 000b, guest PC 0x0c094498 */
if(!s->budget--) { s->failed_pc=0x0c094498u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09449a: /* original 6ef6, guest PC 0x0c09449a */
if(!s->budget--) { s->failed_pc=0x0c09449au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09449cu,s,ram);
P_0c09635a: /* original 4f22, guest PC 0x0c09635a */
if(!s->budget--) { s->failed_pc=0x0c09635au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09635c;
P_0c09635c: /* original dc16, guest PC 0x0c09635c */
if(!s->budget--) { s->failed_pc=0x0c09635cu; return 0; }
r[12]=read(ram,0x0c0963b8u,4);
goto P_0c09635e;
P_0c09635e: /* original de17, guest PC 0x0c09635e */
if(!s->budget--) { s->failed_pc=0x0c09635eu; return 0; }
r[14]=read(ram,0x0c0963bcu,4);
goto P_0c096360;
P_0c096360: /* original 0436, guest PC 0x0c096360 */
if(!s->budget--) { s->failed_pc=0x0c096360u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c096362;
P_0c096362: /* original 70fc, guest PC 0x0c096362 */
if(!s->budget--) { s->failed_pc=0x0c096362u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c096364;
P_0c096364: /* original 0436, guest PC 0x0c096364 */
if(!s->budget--) { s->failed_pc=0x0c096364u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c096366;
P_0c096366: /* original 70fc, guest PC 0x0c096366 */
if(!s->budget--) { s->failed_pc=0x0c096366u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c096368;
P_0c096368: /* original 0436, guest PC 0x0c096368 */
if(!s->budget--) { s->failed_pc=0x0c096368u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c09636a;
P_0c09636a: /* original 6433, guest PC 0x0c09636a */
if(!s->budget--) { s->failed_pc=0x0c09636au; return 0; }
r[4]=r[3];
goto P_0c09636c;
P_0c09636c: /* original d614, guest PC 0x0c09636c */
if(!s->budget--) { s->failed_pc=0x0c09636cu; return 0; }
r[6]=read(ram,0x0c0963c0u,4);
goto P_0c09636e;
P_0c09636e: /* original 7ffc, guest PC 0x0c09636e */
if(!s->budget--) { s->failed_pc=0x0c09636eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c096370;
P_0c096370: /* original bf6a, guest PC 0x0c096370 */
if(!s->budget--) { s->failed_pc=0x0c096370u; return 0; }
target=0x0c096248u; r[16]=0x0c096374u;
r[13]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096374u) { target=s->pc; goto dispatch; }
goto P_0c096374;
P_0c096372: /* original ed01, guest PC 0x0c096372 */
if(!s->budget--) { s->failed_pc=0x0c096372u; return 0; }
r[13]=0x00000001u;
goto P_0c096374;
P_0c096374: /* original d613, guest PC 0x0c096374 */
if(!s->budget--) { s->failed_pc=0x0c096374u; return 0; }
r[6]=read(ram,0x0c0963c4u,4);
goto P_0c096376;
P_0c096376: /* original 65d3, guest PC 0x0c096376 */
if(!s->budget--) { s->failed_pc=0x0c096376u; return 0; }
r[5]=r[13];
goto P_0c096378;
P_0c096378: /* original bf66, guest PC 0x0c096378 */
if(!s->budget--) { s->failed_pc=0x0c096378u; return 0; }
target=0x0c096248u; r[16]=0x0c09637cu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09637cu) { target=s->pc; goto dispatch; }
goto P_0c09637c;
P_0c09637a: /* original 64d3, guest PC 0x0c09637a */
if(!s->budget--) { s->failed_pc=0x0c09637au; return 0; }
r[4]=r[13];
goto P_0c09637c;
P_0c09637c: /* original 9b19, guest PC 0x0c09637c */
if(!s->budget--) { s->failed_pc=0x0c09637cu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0963b2u,2);
goto P_0c09637e;
P_0c09637e: /* original d912, guest PC 0x0c09637e */
if(!s->budget--) { s->failed_pc=0x0c09637eu; return 0; }
r[9]=read(ram,0x0c0963c8u,4);
goto P_0c096380;
P_0c096380: /* original a059, guest PC 0x0c096380 */
if(!s->budget--) { s->failed_pc=0x0c096380u; return 0; }
r[8]=0x00000000u;
goto P_0c096436;
P_0c096382: /* original e800, guest PC 0x0c096382 */
if(!s->budget--) { s->failed_pc=0x0c096382u; return 0; }
r[8]=0x00000000u;
goto P_0c096384;
P_0c096384: /* original 4c0b, guest PC 0x0c096384 */
if(!s->budget--) { s->failed_pc=0x0c096384u; return 0; }
target=r[12];
r[16]=0x0c096388u;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096388u) { target=s->pc; goto dispatch; }
goto P_0c096388;
P_0c096386: /* original 6483, guest PC 0x0c096386 */
if(!s->budget--) { s->failed_pc=0x0c096386u; return 0; }
r[4]=r[8];
goto P_0c096388;
P_0c096388: /* original 6403, guest PC 0x0c096388 */
if(!s->budget--) { s->failed_pc=0x0c096388u; return 0; }
r[4]=r[0];
goto P_0c09638a;
P_0c09638a: /* original 5244, guest PC 0x0c09638a */
if(!s->budget--) { s->failed_pc=0x0c09638au; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c09638c;
P_0c09638c: /* original 22b9, guest PC 0x0c09638c */
if(!s->budget--) { s->failed_pc=0x0c09638cu; return 0; }
r[2]&=r[11];
goto P_0c09638e;
P_0c09638e: /* original 32b0, guest PC 0x0c09638e */
if(!s->budget--) { s->failed_pc=0x0c09638eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c096390;
P_0c096390: /* original 8b50, guest PC 0x0c096390 */
if(!s->budget--) { s->failed_pc=0x0c096390u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096434; }
goto P_0c096392;
P_0c096392: /* original 5242, guest PC 0x0c096392 */
if(!s->budget--) { s->failed_pc=0x0c096392u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c096394;
P_0c096394: /* original 22a8, guest PC 0x0c096394 */
if(!s->budget--) { s->failed_pc=0x0c096394u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[10])==0)!=0);
goto P_0c096396;
P_0c096396: /* original 894d, guest PC 0x0c096396 */
if(!s->budget--) { s->failed_pc=0x0c096396u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096434; }
goto P_0c096398;
P_0c096398: /* original d106, guest PC 0x0c096398 */
if(!s->budget--) { s->failed_pc=0x0c096398u; return 0; }
r[1]=read(ram,0x0c0963b4u,4);
goto P_0c09639a;
P_0c09639a: /* original d30c, guest PC 0x0c09639a */
if(!s->budget--) { s->failed_pc=0x0c09639au; return 0; }
r[3]=read(ram,0x0c0963ccu,4);
goto P_0c09639c;
P_0c09639c: /* original 6412, guest PC 0x0c09639c */
if(!s->budget--) { s->failed_pc=0x0c09639cu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c09639e;
P_0c09639e: /* original 2348, guest PC 0x0c09639e */
if(!s->budget--) { s->failed_pc=0x0c09639eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0963a0;
P_0c0963a0: /* original 8916, guest PC 0x0c0963a0 */
if(!s->budget--) { s->failed_pc=0x0c0963a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0963d0; }
goto P_0c0963a2;
P_0c0963a2: /* original e500, guest PC 0x0c0963a2 */
if(!s->budget--) { s->failed_pc=0x0c0963a2u; return 0; }
r[5]=0x00000000u;
goto P_0c0963a4;
P_0c0963a4: /* original b25e, guest PC 0x0c0963a4 */
if(!s->budget--) { s->failed_pc=0x0c0963a4u; return 0; }
target=0x0c096864u; r[16]=0x0c0963a8u;
r[4]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0963a8u) { target=s->pc; goto dispatch; }
goto P_0c0963a8;
P_0c0963a6: /* original 6453, guest PC 0x0c0963a6 */
if(!s->budget--) { s->failed_pc=0x0c0963a6u; return 0; }
r[4]=r[5];
goto P_0c0963a8;
P_0c0963a8: /* original a044, guest PC 0x0c0963a8 */
if(!s->budget--) { s->failed_pc=0x0c0963a8u; return 0; }
goto P_0c096434;
P_0c0963aa: /* original 0009, guest PC 0x0c0963aa */
if(!s->budget--) { s->failed_pc=0x0c0963aau; return 0; }
return vf3_matrix_family(0x0c0963acu,s,ram);
P_0c0963d0: /* original d33d, guest PC 0x0c0963d0 */
if(!s->budget--) { s->failed_pc=0x0c0963d0u; return 0; }
r[3]=read(ram,0x0c0964c8u,4);
goto P_0c0963d2;
P_0c0963d2: /* original 2438, guest PC 0x0c0963d2 */
if(!s->budget--) { s->failed_pc=0x0c0963d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0963d4;
P_0c0963d4: /* original 8b2e, guest PC 0x0c0963d4 */
if(!s->budget--) { s->failed_pc=0x0c0963d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096434; }
goto P_0c0963d6;
P_0c0963d6: /* original d23d, guest PC 0x0c0963d6 */
if(!s->budget--) { s->failed_pc=0x0c0963d6u; return 0; }
r[2]=read(ram,0x0c0964ccu,4);
goto P_0c0963d8;
P_0c0963d8: /* original e600, guest PC 0x0c0963d8 */
if(!s->budget--) { s->failed_pc=0x0c0963d8u; return 0; }
r[6]=0x00000000u;
goto P_0c0963da;
P_0c0963da: /* original 6563, guest PC 0x0c0963da */
if(!s->budget--) { s->failed_pc=0x0c0963dau; return 0; }
r[5]=r[6];
goto P_0c0963dc;
P_0c0963dc: /* original 22d2, guest PC 0x0c0963dc */
if(!s->budget--) { s->failed_pc=0x0c0963dcu; return 0; }
write(ram,r[2],r[13],4);
goto P_0c0963de;
P_0c0963de: /* original d13c, guest PC 0x0c0963de */
if(!s->budget--) { s->failed_pc=0x0c0963deu; return 0; }
r[1]=read(ram,0x0c0964d0u,4);
goto P_0c0963e0;
P_0c0963e0: /* original 410b, guest PC 0x0c0963e0 */
if(!s->budget--) { s->failed_pc=0x0c0963e0u; return 0; }
target=r[1];
r[16]=0x0c0963e4u;
r[4]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0963e4u) { target=s->pc; goto dispatch; }
goto P_0c0963e4;
P_0c0963e2: /* original 6463, guest PC 0x0c0963e2 */
if(!s->budget--) { s->failed_pc=0x0c0963e2u; return 0; }
r[4]=r[6];
goto P_0c0963e4;
P_0c0963e4: /* original d33b, guest PC 0x0c0963e4 */
if(!s->budget--) { s->failed_pc=0x0c0963e4u; return 0; }
r[3]=read(ram,0x0c0964d4u,4);
goto P_0c0963e6;
P_0c0963e6: /* original 430b, guest PC 0x0c0963e6 */
if(!s->budget--) { s->failed_pc=0x0c0963e6u; return 0; }
target=r[3];
r[16]=0x0c0963eau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0963eau) { target=s->pc; goto dispatch; }
goto P_0c0963ea;
P_0c0963e8: /* original 0009, guest PC 0x0c0963e8 */
if(!s->budget--) { s->failed_pc=0x0c0963e8u; return 0; }
goto P_0c0963ea;
P_0c0963ea: /* original 0002, guest PC 0x0c0963ea */
if(!s->budget--) { s->failed_pc=0x0c0963eau; return 0; }
r[0]=r[17];
goto P_0c0963ec;
P_0c0963ec: /* original 926a, guest PC 0x0c0963ec */
if(!s->budget--) { s->failed_pc=0x0c0963ecu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0964c4u,2);
goto P_0c0963ee;
P_0c0963ee: /* original 2029, guest PC 0x0c0963ee */
if(!s->budget--) { s->failed_pc=0x0c0963eeu; return 0; }
r[0]&=r[2];
goto P_0c0963f0;
P_0c0963f0: /* original cbe0, guest PC 0x0c0963f0 */
if(!s->budget--) { s->failed_pc=0x0c0963f0u; return 0; }
r[0]|=224u;
goto P_0c0963f2;
P_0c0963f2: /* original 400e, guest PC 0x0c0963f2 */
if(!s->budget--) { s->failed_pc=0x0c0963f2u; return 0; }
r[17]=r[0];
goto P_0c0963f4;
P_0c0963f4: /* original d338, guest PC 0x0c0963f4 */
if(!s->budget--) { s->failed_pc=0x0c0963f4u; return 0; }
r[3]=read(ram,0x0c0964d8u,4);
goto P_0c0963f6;
P_0c0963f6: /* original 430b, guest PC 0x0c0963f6 */
if(!s->budget--) { s->failed_pc=0x0c0963f6u; return 0; }
target=r[3];
r[16]=0x0c0963fau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0963fau) { target=s->pc; goto dispatch; }
goto P_0c0963fa;
P_0c0963f8: /* original 0009, guest PC 0x0c0963f8 */
if(!s->budget--) { s->failed_pc=0x0c0963f8u; return 0; }
goto P_0c0963fa;
P_0c0963fa: /* original d138, guest PC 0x0c0963fa */
if(!s->budget--) { s->failed_pc=0x0c0963fau; return 0; }
r[1]=read(ram,0x0c0964dcu,4);
goto P_0c0963fc;
P_0c0963fc: /* original 410b, guest PC 0x0c0963fc */
if(!s->budget--) { s->failed_pc=0x0c0963fcu; return 0; }
target=r[1];
r[16]=0x0c096400u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096400u) { target=s->pc; goto dispatch; }
goto P_0c096400;
P_0c0963fe: /* original 0009, guest PC 0x0c0963fe */
if(!s->budget--) { s->failed_pc=0x0c0963feu; return 0; }
goto P_0c096400;
P_0c096400: /* original 0002, guest PC 0x0c096400 */
if(!s->budget--) { s->failed_pc=0x0c096400u; return 0; }
r[0]=r[17];
goto P_0c096402;
P_0c096402: /* original 935f, guest PC 0x0c096402 */
if(!s->budget--) { s->failed_pc=0x0c096402u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0964c4u,2);
goto P_0c096404;
P_0c096404: /* original 2039, guest PC 0x0c096404 */
if(!s->budget--) { s->failed_pc=0x0c096404u; return 0; }
r[0]&=r[3];
goto P_0c096406;
P_0c096406: /* original 400e, guest PC 0x0c096406 */
if(!s->budget--) { s->failed_pc=0x0c096406u; return 0; }
r[17]=r[0];
goto P_0c096408;
P_0c096408: /* original d235, guest PC 0x0c096408 */
if(!s->budget--) { s->failed_pc=0x0c096408u; return 0; }
r[2]=read(ram,0x0c0964e0u,4);
goto P_0c09640a;
P_0c09640a: /* original 420b, guest PC 0x0c09640a */
if(!s->budget--) { s->failed_pc=0x0c09640au; return 0; }
target=r[2];
r[16]=0x0c09640eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09640eu) { target=s->pc; goto dispatch; }
goto P_0c09640e;
P_0c09640c: /* original 0009, guest PC 0x0c09640c */
if(!s->budget--) { s->failed_pc=0x0c09640cu; return 0; }
goto P_0c09640e;
P_0c09640e: /* original d134, guest PC 0x0c09640e */
if(!s->budget--) { s->failed_pc=0x0c09640eu; return 0; }
r[1]=read(ram,0x0c0964e0u,4);
goto P_0c096410;
P_0c096410: /* original 410b, guest PC 0x0c096410 */
if(!s->budget--) { s->failed_pc=0x0c096410u; return 0; }
target=r[1];
r[16]=0x0c096414u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096414u) { target=s->pc; goto dispatch; }
goto P_0c096414;
P_0c096412: /* original 0009, guest PC 0x0c096412 */
if(!s->budget--) { s->failed_pc=0x0c096412u; return 0; }
goto P_0c096414;
P_0c096414: /* original d233, guest PC 0x0c096414 */
if(!s->budget--) { s->failed_pc=0x0c096414u; return 0; }
r[2]=read(ram,0x0c0964e4u,4);
goto P_0c096416;
P_0c096416: /* original 229b, guest PC 0x0c096416 */
if(!s->budget--) { s->failed_pc=0x0c096416u; return 0; }
r[2]|=r[9];
goto P_0c096418;
P_0c096418: /* original 420b, guest PC 0x0c096418 */
if(!s->budget--) { s->failed_pc=0x0c096418u; return 0; }
target=r[2];
r[16]=0x0c09641cu;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09641cu) { target=s->pc; goto dispatch; }
goto P_0c09641c;
P_0c09641a: /* original e400, guest PC 0x0c09641a */
if(!s->budget--) { s->failed_pc=0x0c09641au; return 0; }
r[4]=0x00000000u;
goto P_0c09641c;
P_0c09641c: /* original d332, guest PC 0x0c09641c */
if(!s->budget--) { s->failed_pc=0x0c09641cu; return 0; }
r[3]=read(ram,0x0c0964e8u,4);
goto P_0c09641e;
P_0c09641e: /* original 239b, guest PC 0x0c09641e */
if(!s->budget--) { s->failed_pc=0x0c09641eu; return 0; }
r[3]|=r[9];
goto P_0c096420;
P_0c096420: /* original 430b, guest PC 0x0c096420 */
if(!s->budget--) { s->failed_pc=0x0c096420u; return 0; }
target=r[3];
r[16]=0x0c096424u;
r[4]=0x0000003fu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096424u) { target=s->pc; goto dispatch; }
goto P_0c096424;
P_0c096422: /* original e43f, guest PC 0x0c096422 */
if(!s->budget--) { s->failed_pc=0x0c096422u; return 0; }
r[4]=0x0000003fu;
goto P_0c096424;
P_0c096424: /* original 0002, guest PC 0x0c096424 */
if(!s->budget--) { s->failed_pc=0x0c096424u; return 0; }
r[0]=r[17];
goto P_0c096426;
P_0c096426: /* original 924d, guest PC 0x0c096426 */
if(!s->budget--) { s->failed_pc=0x0c096426u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0964c4u,2);
goto P_0c096428;
P_0c096428: /* original 2029, guest PC 0x0c096428 */
if(!s->budget--) { s->failed_pc=0x0c096428u; return 0; }
r[0]&=r[2];
goto P_0c09642a;
P_0c09642a: /* original cbe0, guest PC 0x0c09642a */
if(!s->budget--) { s->failed_pc=0x0c09642au; return 0; }
r[0]|=224u;
goto P_0c09642c;
P_0c09642c: /* original 400e, guest PC 0x0c09642c */
if(!s->budget--) { s->failed_pc=0x0c09642cu; return 0; }
r[17]=r[0];
goto P_0c09642e;
P_0c09642e: /* original d32f, guest PC 0x0c09642e */
if(!s->budget--) { s->failed_pc=0x0c09642eu; return 0; }
r[3]=read(ram,0x0c0964ecu,4);
goto P_0c096430;
P_0c096430: /* original 430b, guest PC 0x0c096430 */
if(!s->budget--) { s->failed_pc=0x0c096430u; return 0; }
target=r[3];
r[16]=0x0c096434u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096434u) { target=s->pc; goto dispatch; }
goto P_0c096434;
P_0c096432: /* original 0009, guest PC 0x0c096432 */
if(!s->budget--) { s->failed_pc=0x0c096432u; return 0; }
goto P_0c096434;
P_0c096434: /* original 7801, guest PC 0x0c096434 */
if(!s->budget--) { s->failed_pc=0x0c096434u; return 0; }
r[8]+=0x00000001u;
goto P_0c096436;
P_0c096436: /* original e202, guest PC 0x0c096436 */
if(!s->budget--) { s->failed_pc=0x0c096436u; return 0; }
r[2]=0x00000002u;
goto P_0c096438;
P_0c096438: /* original 3823, guest PC 0x0c096438 */
if(!s->budget--) { s->failed_pc=0x0c096438u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[2])!=0);
goto P_0c09643a;
P_0c09643a: /* original 8ba3, guest PC 0x0c09643a */
if(!s->budget--) { s->failed_pc=0x0c09643au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096384; }
goto P_0c09643c;
P_0c09643c: /* original d12c, guest PC 0x0c09643c */
if(!s->budget--) { s->failed_pc=0x0c09643cu; return 0; }
r[1]=read(ram,0x0c0964f0u,4);
goto P_0c09643e;
P_0c09643e: /* original 410b, guest PC 0x0c09643e */
if(!s->budget--) { s->failed_pc=0x0c09643eu; return 0; }
target=r[1];
r[16]=0x0c096442u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096442u) { target=s->pc; goto dispatch; }
goto P_0c096442;
P_0c096440: /* original 0009, guest PC 0x0c096440 */
if(!s->budget--) { s->failed_pc=0x0c096440u; return 0; }
goto P_0c096442;
P_0c096442: /* original 8806, guest PC 0x0c096442 */
if(!s->budget--) { s->failed_pc=0x0c096442u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c096444;
P_0c096444: /* original 8f03, guest PC 0x0c096444 */
if(!s->budget--) { s->failed_pc=0x0c096444u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c09644e; }
goto P_0c096448;
P_0c096446: /* original 6403, guest PC 0x0c096446 */
if(!s->budget--) { s->failed_pc=0x0c096446u; return 0; }
r[4]=r[0];
goto P_0c096448;
P_0c096448: /* original e500, guest PC 0x0c096448 */
if(!s->budget--) { s->failed_pc=0x0c096448u; return 0; }
r[5]=0x00000000u;
goto P_0c09644a;
P_0c09644a: /* original b20b, guest PC 0x0c09644a */
if(!s->budget--) { s->failed_pc=0x0c09644au; return 0; }
target=0x0c096864u; r[16]=0x0c09644eu;
r[4]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09644eu) { target=s->pc; goto dispatch; }
goto P_0c09644e;
P_0c09644c: /* original 6453, guest PC 0x0c09644c */
if(!s->budget--) { s->failed_pc=0x0c09644cu; return 0; }
r[4]=r[5];
goto P_0c09644e;
P_0c09644e: /* original d429, guest PC 0x0c09644e */
if(!s->budget--) { s->failed_pc=0x0c09644eu; return 0; }
r[4]=read(ram,0x0c0964f4u,4);
goto P_0c096450;
P_0c096450: /* original d32b, guest PC 0x0c096450 */
if(!s->budget--) { s->failed_pc=0x0c096450u; return 0; }
r[3]=read(ram,0x0c096500u,4);
goto P_0c096452;
P_0c096452: /* original 6242, guest PC 0x0c096452 */
if(!s->budget--) { s->failed_pc=0x0c096452u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c096454;
P_0c096454: /* original db28, guest PC 0x0c096454 */
if(!s->budget--) { s->failed_pc=0x0c096454u; return 0; }
r[11]=read(ram,0x0c0964f8u,4);
goto P_0c096456;
P_0c096456: /* original d529, guest PC 0x0c096456 */
if(!s->budget--) { s->failed_pc=0x0c096456u; return 0; }
r[5]=read(ram,0x0c0964fcu,4);
goto P_0c096458;
P_0c096458: /* original 2238, guest PC 0x0c096458 */
if(!s->budget--) { s->failed_pc=0x0c096458u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09645a;
P_0c09645a: /* original 8b01, guest PC 0x0c09645a */
if(!s->budget--) { s->failed_pc=0x0c09645au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096460; }
goto P_0c09645c;
P_0c09645c: /* original a0d4, guest PC 0x0c09645c */
if(!s->budget--) { s->failed_pc=0x0c09645cu; return 0; }
goto P_0c096608;
P_0c09645e: /* original 0009, guest PC 0x0c09645e */
if(!s->budget--) { s->failed_pc=0x0c09645eu; return 0; }
goto P_0c096460;
P_0c096460: /* original 5141, guest PC 0x0c096460 */
if(!s->budget--) { s->failed_pc=0x0c096460u; return 0; }
r[1]=read(ram,r[4]+4,4);
goto P_0c096462;
P_0c096462: /* original d228, guest PC 0x0c096462 */
if(!s->budget--) { s->failed_pc=0x0c096462u; return 0; }
r[2]=read(ram,0x0c096504u,4);
goto P_0c096464;
P_0c096464: /* original 2128, guest PC 0x0c096464 */
if(!s->budget--) { s->failed_pc=0x0c096464u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c096466;
P_0c096466: /* original 8b01, guest PC 0x0c096466 */
if(!s->budget--) { s->failed_pc=0x0c096466u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09646c; }
goto P_0c096468;
P_0c096468: /* original a0c7, guest PC 0x0c096468 */
if(!s->budget--) { s->failed_pc=0x0c096468u; return 0; }
goto P_0c0965fa;
P_0c09646a: /* original 0009, guest PC 0x0c09646a */
if(!s->budget--) { s->failed_pc=0x0c09646au; return 0; }
goto P_0c09646c;
P_0c09646c: /* original e800, guest PC 0x0c09646c */
if(!s->budget--) { s->failed_pc=0x0c09646cu; return 0; }
r[8]=0x00000000u;
goto P_0c09646e;
P_0c09646e: /* original 6183, guest PC 0x0c09646e */
if(!s->budget--) { s->failed_pc=0x0c09646eu; return 0; }
r[1]=r[8];
goto P_0c096470;
P_0c096470: /* original 6913, guest PC 0x0c096470 */
if(!s->budget--) { s->failed_pc=0x0c096470u; return 0; }
r[9]=r[1];
goto P_0c096472;
P_0c096472: /* original 2f12, guest PC 0x0c096472 */
if(!s->budget--) { s->failed_pc=0x0c096472u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c096474;
P_0c096474: /* original 50b2, guest PC 0x0c096474 */
if(!s->budget--) { s->failed_pc=0x0c096474u; return 0; }
r[0]=read(ram,r[11]+8,4);
goto P_0c096476;
P_0c096476: /* original d124, guest PC 0x0c096476 */
if(!s->budget--) { s->failed_pc=0x0c096476u; return 0; }
r[1]=read(ram,0x0c096508u,4);
goto P_0c096478;
P_0c096478: /* original 2018, guest PC 0x0c096478 */
if(!s->budget--) { s->failed_pc=0x0c096478u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c09647a;
P_0c09647a: /* original 8904, guest PC 0x0c09647a */
if(!s->budget--) { s->failed_pc=0x0c09647au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096486; }
goto P_0c09647c;
P_0c09647c: /* original e029, guest PC 0x0c09647c */
if(!s->budget--) { s->failed_pc=0x0c09647cu; return 0; }
r[0]=0x00000029u;
goto P_0c09647e;
P_0c09647e: /* original 00bc, guest PC 0x0c09647e */
if(!s->budget--) { s->failed_pc=0x0c09647eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c096480;
P_0c096480: /* original 600c, guest PC 0x0c096480 */
if(!s->budget--) { s->failed_pc=0x0c096480u; return 0; }
r[0]=r[0]&255u;
goto P_0c096482;
P_0c096482: /* original 8802, guest PC 0x0c096482 */
if(!s->budget--) { s->failed_pc=0x0c096482u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c096484;
P_0c096484: /* original 8903, guest PC 0x0c096484 */
if(!s->budget--) { s->failed_pc=0x0c096484u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09648e; }
goto P_0c096486;
P_0c096486: /* original 4c0b, guest PC 0x0c096486 */
if(!s->budget--) { s->failed_pc=0x0c096486u; return 0; }
target=r[12];
r[16]=0x0c09648au;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09648au) { target=s->pc; goto dispatch; }
goto P_0c09648a;
P_0c096488: /* original e400, guest PC 0x0c096488 */
if(!s->budget--) { s->failed_pc=0x0c096488u; return 0; }
r[4]=0x00000000u;
goto P_0c09648a;
P_0c09648a: /* original 6403, guest PC 0x0c09648a */
if(!s->budget--) { s->failed_pc=0x0c09648au; return 0; }
r[4]=r[0];
goto P_0c09648c;
P_0c09648c: /* original 5842, guest PC 0x0c09648c */
if(!s->budget--) { s->failed_pc=0x0c09648cu; return 0; }
r[8]=read(ram,r[4]+8,4);
goto P_0c09648e;
P_0c09648e: /* original 52b2, guest PC 0x0c09648e */
if(!s->budget--) { s->failed_pc=0x0c09648eu; return 0; }
r[2]=read(ram,r[11]+8,4);
goto P_0c096490;
P_0c096490: /* original d31d, guest PC 0x0c096490 */
if(!s->budget--) { s->failed_pc=0x0c096490u; return 0; }
r[3]=read(ram,0x0c096508u,4);
goto P_0c096492;
P_0c096492: /* original 2238, guest PC 0x0c096492 */
if(!s->budget--) { s->failed_pc=0x0c096492u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c096494;
P_0c096494: /* original 8904, guest PC 0x0c096494 */
if(!s->budget--) { s->failed_pc=0x0c096494u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0964a0; }
goto P_0c096496;
P_0c096496: /* original e029, guest PC 0x0c096496 */
if(!s->budget--) { s->failed_pc=0x0c096496u; return 0; }
r[0]=0x00000029u;
goto P_0c096498;
P_0c096498: /* original 00bc, guest PC 0x0c096498 */
if(!s->budget--) { s->failed_pc=0x0c096498u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c09649a;
P_0c09649a: /* original 600c, guest PC 0x0c09649a */
if(!s->budget--) { s->failed_pc=0x0c09649au; return 0; }
r[0]=r[0]&255u;
goto P_0c09649c;
P_0c09649c: /* original 8801, guest PC 0x0c09649c */
if(!s->budget--) { s->failed_pc=0x0c09649cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09649e;
P_0c09649e: /* original 8904, guest PC 0x0c09649e */
if(!s->budget--) { s->failed_pc=0x0c09649eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0964aa; }
goto P_0c0964a0;
P_0c0964a0: /* original 4c0b, guest PC 0x0c0964a0 */
if(!s->budget--) { s->failed_pc=0x0c0964a0u; return 0; }
target=r[12];
r[16]=0x0c0964a4u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0964a4u) { target=s->pc; goto dispatch; }
goto P_0c0964a4;
P_0c0964a2: /* original e401, guest PC 0x0c0964a2 */
if(!s->budget--) { s->failed_pc=0x0c0964a2u; return 0; }
r[4]=0x00000001u;
goto P_0c0964a4;
P_0c0964a4: /* original 6403, guest PC 0x0c0964a4 */
if(!s->budget--) { s->failed_pc=0x0c0964a4u; return 0; }
r[4]=r[0];
goto P_0c0964a6;
P_0c0964a6: /* original 5342, guest PC 0x0c0964a6 */
if(!s->budget--) { s->failed_pc=0x0c0964a6u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c0964a8;
P_0c0964a8: /* original 2f32, guest PC 0x0c0964a8 */
if(!s->budget--) { s->failed_pc=0x0c0964a8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0964aa;
P_0c0964aa: /* original e029, guest PC 0x0c0964aa */
if(!s->budget--) { s->failed_pc=0x0c0964aau; return 0; }
r[0]=0x00000029u;
goto P_0c0964ac;
P_0c0964ac: /* original 00bc, guest PC 0x0c0964ac */
if(!s->budget--) { s->failed_pc=0x0c0964acu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0964ae;
P_0c0964ae: /* original 600c, guest PC 0x0c0964ae */
if(!s->budget--) { s->failed_pc=0x0c0964aeu; return 0; }
r[0]=r[0]&255u;
goto P_0c0964b0;
P_0c0964b0: /* original 8801, guest PC 0x0c0964b0 */
if(!s->budget--) { s->failed_pc=0x0c0964b0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0964b2;
P_0c0964b2: /* original 8b2b, guest PC 0x0c0964b2 */
if(!s->budget--) { s->failed_pc=0x0c0964b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09650c; }
goto P_0c0964b4;
P_0c0964b4: /* original 4c0b, guest PC 0x0c0964b4 */
if(!s->budget--) { s->failed_pc=0x0c0964b4u; return 0; }
target=r[12];
r[16]=0x0c0964b8u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0964b8u) { target=s->pc; goto dispatch; }
goto P_0c0964b8;
P_0c0964b6: /* original e400, guest PC 0x0c0964b6 */
if(!s->budget--) { s->failed_pc=0x0c0964b6u; return 0; }
r[4]=0x00000000u;
goto P_0c0964b8;
P_0c0964b8: /* original 6403, guest PC 0x0c0964b8 */
if(!s->budget--) { s->failed_pc=0x0c0964b8u; return 0; }
r[4]=r[0];
goto P_0c0964ba;
P_0c0964ba: /* original 6042, guest PC 0x0c0964ba */
if(!s->budget--) { s->failed_pc=0x0c0964bau; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c0964bc;
P_0c0964bc: /* original 88fe, guest PC 0x0c0964bc */
if(!s->budget--) { s->failed_pc=0x0c0964bcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c0964be;
P_0c0964be: /* original 892d, guest PC 0x0c0964be */
if(!s->budget--) { s->failed_pc=0x0c0964beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09651c; }
goto P_0c0964c0;
P_0c0964c0: /* original a03d, guest PC 0x0c0964c0 */
if(!s->budget--) { s->failed_pc=0x0c0964c0u; return 0; }
goto P_0c09653e;
P_0c0964c2: /* original 0009, guest PC 0x0c0964c2 */
if(!s->budget--) { s->failed_pc=0x0c0964c2u; return 0; }
return vf3_matrix_family(0x0c0964c4u,s,ram);
P_0c09650c: /* original 8802, guest PC 0x0c09650c */
if(!s->budget--) { s->failed_pc=0x0c09650cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09650e;
P_0c09650e: /* original 8b07, guest PC 0x0c09650e */
if(!s->budget--) { s->failed_pc=0x0c09650eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096520; }
goto P_0c096510;
P_0c096510: /* original 4c0b, guest PC 0x0c096510 */
if(!s->budget--) { s->failed_pc=0x0c096510u; return 0; }
target=r[12];
r[16]=0x0c096514u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096514u) { target=s->pc; goto dispatch; }
goto P_0c096514;
P_0c096512: /* original e401, guest PC 0x0c096512 */
if(!s->budget--) { s->failed_pc=0x0c096512u; return 0; }
r[4]=0x00000001u;
goto P_0c096514;
P_0c096514: /* original 6403, guest PC 0x0c096514 */
if(!s->budget--) { s->failed_pc=0x0c096514u; return 0; }
r[4]=r[0];
goto P_0c096516;
P_0c096516: /* original 6042, guest PC 0x0c096516 */
if(!s->budget--) { s->failed_pc=0x0c096516u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c096518;
P_0c096518: /* original 88fe, guest PC 0x0c096518 */
if(!s->budget--) { s->failed_pc=0x0c096518u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c09651a;
P_0c09651a: /* original 8b10, guest PC 0x0c09651a */
if(!s->budget--) { s->failed_pc=0x0c09651au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09653e; }
goto P_0c09651c;
P_0c09651c: /* original a00f, guest PC 0x0c09651c */
if(!s->budget--) { s->failed_pc=0x0c09651cu; return 0; }
r[9]=r[13];
goto P_0c09653e;
P_0c09651e: /* original 69d3, guest PC 0x0c09651e */
if(!s->budget--) { s->failed_pc=0x0c09651eu; return 0; }
r[9]=r[13];
goto P_0c096520;
P_0c096520: /* original 4c0b, guest PC 0x0c096520 */
if(!s->budget--) { s->failed_pc=0x0c096520u; return 0; }
target=r[12];
r[16]=0x0c096524u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096524u) { target=s->pc; goto dispatch; }
goto P_0c096524;
P_0c096522: /* original e400, guest PC 0x0c096522 */
if(!s->budget--) { s->failed_pc=0x0c096522u; return 0; }
r[4]=0x00000000u;
goto P_0c096524;
P_0c096524: /* original 6403, guest PC 0x0c096524 */
if(!s->budget--) { s->failed_pc=0x0c096524u; return 0; }
r[4]=r[0];
goto P_0c096526;
P_0c096526: /* original 6042, guest PC 0x0c096526 */
if(!s->budget--) { s->failed_pc=0x0c096526u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c096528;
P_0c096528: /* original 88fe, guest PC 0x0c096528 */
if(!s->budget--) { s->failed_pc=0x0c096528u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c09652a;
P_0c09652a: /* original 8f01, guest PC 0x0c09652a */
if(!s->budget--) { s->failed_pc=0x0c09652au; return 0; }
cond=r[17]&1u;
r[4]=0x00000001u;
if(!cond) { goto P_0c096530; }
goto P_0c09652e;
P_0c09652c: /* original e401, guest PC 0x0c09652c */
if(!s->budget--) { s->failed_pc=0x0c09652cu; return 0; }
r[4]=0x00000001u;
goto P_0c09652e;
P_0c09652e: /* original 69d3, guest PC 0x0c09652e */
if(!s->budget--) { s->failed_pc=0x0c09652eu; return 0; }
r[9]=r[13];
goto P_0c096530;
P_0c096530: /* original 4c0b, guest PC 0x0c096530 */
if(!s->budget--) { s->failed_pc=0x0c096530u; return 0; }
target=r[12];
r[16]=0x0c096534u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096534u) { target=s->pc; goto dispatch; }
goto P_0c096534;
P_0c096532: /* original 0009, guest PC 0x0c096532 */
if(!s->budget--) { s->failed_pc=0x0c096532u; return 0; }
goto P_0c096534;
P_0c096534: /* original 6403, guest PC 0x0c096534 */
if(!s->budget--) { s->failed_pc=0x0c096534u; return 0; }
r[4]=r[0];
goto P_0c096536;
P_0c096536: /* original 6042, guest PC 0x0c096536 */
if(!s->budget--) { s->failed_pc=0x0c096536u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c096538;
P_0c096538: /* original 88fe, guest PC 0x0c096538 */
if(!s->budget--) { s->failed_pc=0x0c096538u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c09653a;
P_0c09653a: /* original 8b00, guest PC 0x0c09653a */
if(!s->budget--) { s->failed_pc=0x0c09653au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09653e; }
goto P_0c09653c;
P_0c09653c: /* original 29db, guest PC 0x0c09653c */
if(!s->budget--) { s->failed_pc=0x0c09653cu; return 0; }
r[9]|=r[13];
goto P_0c09653e;
P_0c09653e: /* original 64e2, guest PC 0x0c09653e */
if(!s->budget--) { s->failed_pc=0x0c09653eu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c096540;
P_0c096540: /* original 2998, guest PC 0x0c096540 */
if(!s->budget--) { s->failed_pc=0x0c096540u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c096542;
P_0c096542: /* original d523, guest PC 0x0c096542 */
if(!s->budget--) { s->failed_pc=0x0c096542u; return 0; }
r[5]=read(ram,0x0c0965d0u,4);
goto P_0c096544;
P_0c096544: /* original 8d06, guest PC 0x0c096544 */
if(!s->budget--) { s->failed_pc=0x0c096544u; return 0; }
cond=r[17]&1u;
r[4]&=r[5];
if(cond) { goto P_0c096554; }
goto P_0c096548;
P_0c096546: /* original 2459, guest PC 0x0c096546 */
if(!s->budget--) { s->failed_pc=0x0c096546u; return 0; }
r[4]&=r[5];
goto P_0c096548;
P_0c096548: /* original 2448, guest PC 0x0c096548 */
if(!s->budget--) { s->failed_pc=0x0c096548u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c09654a;
P_0c09654a: /* original 8b6a, guest PC 0x0c09654a */
if(!s->budget--) { s->failed_pc=0x0c09654au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096622; }
goto P_0c09654c;
P_0c09654c: /* original 63e2, guest PC 0x0c09654c */
if(!s->budget--) { s->failed_pc=0x0c09654cu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c09654e;
P_0c09654e: /* original 235b, guest PC 0x0c09654e */
if(!s->budget--) { s->failed_pc=0x0c09654eu; return 0; }
r[3]|=r[5];
goto P_0c096550;
P_0c096550: /* original a037, guest PC 0x0c096550 */
if(!s->budget--) { s->failed_pc=0x0c096550u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c0965c2;
P_0c096552: /* original 2e32, guest PC 0x0c096552 */
if(!s->budget--) { s->failed_pc=0x0c096552u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c096554;
P_0c096554: /* original 2448, guest PC 0x0c096554 */
if(!s->budget--) { s->failed_pc=0x0c096554u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c096556;
P_0c096556: /* original 8904, guest PC 0x0c096556 */
if(!s->budget--) { s->failed_pc=0x0c096556u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096562; }
goto P_0c096558;
P_0c096558: /* original 62e2, guest PC 0x0c096558 */
if(!s->budget--) { s->failed_pc=0x0c096558u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c09655a;
P_0c09655a: /* original d31e, guest PC 0x0c09655a */
if(!s->budget--) { s->failed_pc=0x0c09655au; return 0; }
r[3]=read(ram,0x0c0965d4u,4);
goto P_0c09655c;
P_0c09655c: /* original 2239, guest PC 0x0c09655c */
if(!s->budget--) { s->failed_pc=0x0c09655cu; return 0; }
r[2]&=r[3];
goto P_0c09655e;
P_0c09655e: /* original a030, guest PC 0x0c09655e */
if(!s->budget--) { s->failed_pc=0x0c09655eu; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0965c2;
P_0c096560: /* original 2e22, guest PC 0x0c096560 */
if(!s->budget--) { s->failed_pc=0x0c096560u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c096562;
P_0c096562: /* original 60f2, guest PC 0x0c096562 */
if(!s->budget--) { s->failed_pc=0x0c096562u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c096564;
P_0c096564: /* original 208b, guest PC 0x0c096564 */
if(!s->budget--) { s->failed_pc=0x0c096564u; return 0; }
r[0]|=r[8];
goto P_0c096566;
P_0c096566: /* original 20a8, guest PC 0x0c096566 */
if(!s->budget--) { s->failed_pc=0x0c096566u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[10])==0)!=0);
goto P_0c096568;
P_0c096568: /* original 895b, guest PC 0x0c096568 */
if(!s->budget--) { s->failed_pc=0x0c096568u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096622; }
goto P_0c09656a;
P_0c09656a: /* original 62e2, guest PC 0x0c09656a */
if(!s->budget--) { s->failed_pc=0x0c09656au; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c09656c;
P_0c09656c: /* original 6483, guest PC 0x0c09656c */
if(!s->budget--) { s->failed_pc=0x0c09656cu; return 0; }
r[4]=r[8];
goto P_0c09656e;
P_0c09656e: /* original 22d8, guest PC 0x0c09656e */
if(!s->budget--) { s->failed_pc=0x0c09656eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c096570;
P_0c096570: /* original 8d19, guest PC 0x0c096570 */
if(!s->budget--) { s->failed_pc=0x0c096570u; return 0; }
cond=r[17]&1u;
r[4]&=r[10];
if(cond) { goto P_0c0965a6; }
goto P_0c096574;
P_0c096572: /* original 24a9, guest PC 0x0c096572 */
if(!s->budget--) { s->failed_pc=0x0c096572u; return 0; }
r[4]&=r[10];
goto P_0c096574;
P_0c096574: /* original 2448, guest PC 0x0c096574 */
if(!s->budget--) { s->failed_pc=0x0c096574u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c096576;
P_0c096576: /* original 8909, guest PC 0x0c096576 */
if(!s->budget--) { s->failed_pc=0x0c096576u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09658c; }
goto P_0c096578;
P_0c096578: /* original d018, guest PC 0x0c096578 */
if(!s->budget--) { s->failed_pc=0x0c096578u; return 0; }
r[0]=read(ram,0x0c0965dcu,4);
goto P_0c09657a;
P_0c09657a: /* original d317, guest PC 0x0c09657a */
if(!s->budget--) { s->failed_pc=0x0c09657au; return 0; }
r[3]=read(ram,0x0c0965d8u,4);
goto P_0c09657c;
P_0c09657c: /* original 6102, guest PC 0x0c09657c */
if(!s->budget--) { s->failed_pc=0x0c09657cu; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c09657e;
P_0c09657e: /* original 2138, guest PC 0x0c09657e */
if(!s->budget--) { s->failed_pc=0x0c09657eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c096580;
P_0c096580: /* original 8904, guest PC 0x0c096580 */
if(!s->budget--) { s->failed_pc=0x0c096580u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09658c; }
goto P_0c096582;
P_0c096582: /* original 62e2, guest PC 0x0c096582 */
if(!s->budget--) { s->failed_pc=0x0c096582u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c096584;
P_0c096584: /* original d316, guest PC 0x0c096584 */
if(!s->budget--) { s->failed_pc=0x0c096584u; return 0; }
r[3]=read(ram,0x0c0965e0u,4);
goto P_0c096586;
P_0c096586: /* original 223a, guest PC 0x0c096586 */
if(!s->budget--) { s->failed_pc=0x0c096586u; return 0; }
r[2]^=r[3];
goto P_0c096588;
P_0c096588: /* original a01b, guest PC 0x0c096588 */
if(!s->budget--) { s->failed_pc=0x0c096588u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0965c2;
P_0c09658a: /* original 2e22, guest PC 0x0c09658a */
if(!s->budget--) { s->failed_pc=0x0c09658au; return 0; }
write(ram,r[14],r[2],4);
goto P_0c09658c;
P_0c09658c: /* original 61f2, guest PC 0x0c09658c */
if(!s->budget--) { s->failed_pc=0x0c09658cu; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c09658e;
P_0c09658e: /* original 21a8, guest PC 0x0c09658e */
if(!s->budget--) { s->failed_pc=0x0c09658eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[10])==0)!=0);
goto P_0c096590;
P_0c096590: /* original 8947, guest PC 0x0c096590 */
if(!s->budget--) { s->failed_pc=0x0c096590u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096622; }
goto P_0c096592;
P_0c096592: /* original d112, guest PC 0x0c096592 */
if(!s->budget--) { s->failed_pc=0x0c096592u; return 0; }
r[1]=read(ram,0x0c0965dcu,4);
goto P_0c096594;
P_0c096594: /* original d313, guest PC 0x0c096594 */
if(!s->budget--) { s->failed_pc=0x0c096594u; return 0; }
r[3]=read(ram,0x0c0965e4u,4);
goto P_0c096596;
P_0c096596: /* original 6212, guest PC 0x0c096596 */
if(!s->budget--) { s->failed_pc=0x0c096596u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c096598;
P_0c096598: /* original 2238, guest PC 0x0c096598 */
if(!s->budget--) { s->failed_pc=0x0c096598u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09659a;
P_0c09659a: /* original 8942, guest PC 0x0c09659a */
if(!s->budget--) { s->failed_pc=0x0c09659au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096622; }
goto P_0c09659c;
P_0c09659c: /* original 60e2, guest PC 0x0c09659c */
if(!s->budget--) { s->failed_pc=0x0c09659cu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c09659e;
P_0c09659e: /* original d312, guest PC 0x0c09659e */
if(!s->budget--) { s->failed_pc=0x0c09659eu; return 0; }
r[3]=read(ram,0x0c0965e8u,4);
goto P_0c0965a0;
P_0c0965a0: /* original 203a, guest PC 0x0c0965a0 */
if(!s->budget--) { s->failed_pc=0x0c0965a0u; return 0; }
r[0]^=r[3];
goto P_0c0965a2;
P_0c0965a2: /* original a00e, guest PC 0x0c0965a2 */
if(!s->budget--) { s->failed_pc=0x0c0965a2u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c0965c2;
P_0c0965a4: /* original 2e02, guest PC 0x0c0965a4 */
if(!s->budget--) { s->failed_pc=0x0c0965a4u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c0965a6;
P_0c0965a6: /* original 61e2, guest PC 0x0c0965a6 */
if(!s->budget--) { s->failed_pc=0x0c0965a6u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0965a8;
P_0c0965a8: /* original 2448, guest PC 0x0c0965a8 */
if(!s->budget--) { s->failed_pc=0x0c0965a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0965aa;
P_0c0965aa: /* original 21da, guest PC 0x0c0965aa */
if(!s->budget--) { s->failed_pc=0x0c0965aau; return 0; }
r[1]^=r[13];
goto P_0c0965ac;
P_0c0965ac: /* original 8d05, guest PC 0x0c0965ac */
if(!s->budget--) { s->failed_pc=0x0c0965acu; return 0; }
cond=r[17]&1u;
write(ram,r[14],r[1],4);
if(cond) { goto P_0c0965ba; }
goto P_0c0965b0;
P_0c0965ae: /* original 2e12, guest PC 0x0c0965ae */
if(!s->budget--) { s->failed_pc=0x0c0965aeu; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0965b0;
P_0c0965b0: /* original 62e2, guest PC 0x0c0965b0 */
if(!s->budget--) { s->failed_pc=0x0c0965b0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0965b2;
P_0c0965b2: /* original d309, guest PC 0x0c0965b2 */
if(!s->budget--) { s->failed_pc=0x0c0965b2u; return 0; }
r[3]=read(ram,0x0c0965d8u,4);
goto P_0c0965b4;
P_0c0965b4: /* original 223b, guest PC 0x0c0965b4 */
if(!s->budget--) { s->failed_pc=0x0c0965b4u; return 0; }
r[2]|=r[3];
goto P_0c0965b6;
P_0c0965b6: /* original a004, guest PC 0x0c0965b6 */
if(!s->budget--) { s->failed_pc=0x0c0965b6u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0965c2;
P_0c0965b8: /* original 2e22, guest PC 0x0c0965b8 */
if(!s->budget--) { s->failed_pc=0x0c0965b8u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0965ba;
P_0c0965ba: /* original 61e2, guest PC 0x0c0965ba */
if(!s->budget--) { s->failed_pc=0x0c0965bau; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0965bc;
P_0c0965bc: /* original d309, guest PC 0x0c0965bc */
if(!s->budget--) { s->failed_pc=0x0c0965bcu; return 0; }
r[3]=read(ram,0x0c0965e4u,4);
goto P_0c0965be;
P_0c0965be: /* original 213b, guest PC 0x0c0965be */
if(!s->budget--) { s->failed_pc=0x0c0965beu; return 0; }
r[1]|=r[3];
goto P_0c0965c0;
P_0c0965c0: /* original 2e12, guest PC 0x0c0965c0 */
if(!s->budget--) { s->failed_pc=0x0c0965c0u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0965c2;
P_0c0965c2: /* original 62e2, guest PC 0x0c0965c2 */
if(!s->budget--) { s->failed_pc=0x0c0965c2u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0965c4;
P_0c0965c4: /* original 22d8, guest PC 0x0c0965c4 */
if(!s->budget--) { s->failed_pc=0x0c0965c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0965c6;
P_0c0965c6: /* original 8911, guest PC 0x0c0965c6 */
if(!s->budget--) { s->failed_pc=0x0c0965c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0965ec; }
goto P_0c0965c8;
P_0c0965c8: /* original 9401, guest PC 0x0c0965c8 */
if(!s->budget--) { s->failed_pc=0x0c0965c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0965ceu,2);
goto P_0c0965ca;
P_0c0965ca: /* original a011, guest PC 0x0c0965ca */
if(!s->budget--) { s->failed_pc=0x0c0965cau; return 0; }
r[5]=0x00000000u;
goto P_0c0965f0;
P_0c0965cc: /* original e500, guest PC 0x0c0965cc */
if(!s->budget--) { s->failed_pc=0x0c0965ccu; return 0; }
r[5]=0x00000000u;
return vf3_matrix_family(0x0c0965ceu,s,ram);
P_0c0965ec: /* original 947c, guest PC 0x0c0965ec */
if(!s->budget--) { s->failed_pc=0x0c0965ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0966e8u,2);
goto P_0c0965ee;
P_0c0965ee: /* original e500, guest PC 0x0c0965ee */
if(!s->budget--) { s->failed_pc=0x0c0965eeu; return 0; }
r[5]=0x00000000u;
goto P_0c0965f0;
P_0c0965f0: /* original d23f, guest PC 0x0c0965f0 */
if(!s->budget--) { s->failed_pc=0x0c0965f0u; return 0; }
r[2]=read(ram,0x0c0966f0u,4);
goto P_0c0965f2;
P_0c0965f2: /* original 420b, guest PC 0x0c0965f2 */
if(!s->budget--) { s->failed_pc=0x0c0965f2u; return 0; }
target=r[2];
r[16]=0x0c0965f6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0965f6u) { target=s->pc; goto dispatch; }
goto P_0c0965f6;
P_0c0965f4: /* original 0009, guest PC 0x0c0965f4 */
if(!s->budget--) { s->failed_pc=0x0c0965f4u; return 0; }
goto P_0c0965f6;
P_0c0965f6: /* original a014, guest PC 0x0c0965f6 */
if(!s->budget--) { s->failed_pc=0x0c0965f6u; return 0; }
goto P_0c096622;
P_0c0965f8: /* original 0009, guest PC 0x0c0965f8 */
if(!s->budget--) { s->failed_pc=0x0c0965f8u; return 0; }
goto P_0c0965fa;
P_0c0965fa: /* original 2518, guest PC 0x0c0965fa */
if(!s->budget--) { s->failed_pc=0x0c0965fau; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[1])==0)!=0);
goto P_0c0965fc;
P_0c0965fc: /* original 8911, guest PC 0x0c0965fc */
if(!s->budget--) { s->failed_pc=0x0c0965fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096622; }
goto P_0c0965fe;
P_0c0965fe: /* original 61e2, guest PC 0x0c0965fe */
if(!s->budget--) { s->failed_pc=0x0c0965feu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c096600;
P_0c096600: /* original 21d8, guest PC 0x0c096600 */
if(!s->budget--) { s->failed_pc=0x0c096600u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[13])==0)!=0);
goto P_0c096602;
P_0c096602: /* original 8b06, guest PC 0x0c096602 */
if(!s->budget--) { s->failed_pc=0x0c096602u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096612; }
goto P_0c096604;
P_0c096604: /* original a00d, guest PC 0x0c096604 */
if(!s->budget--) { s->failed_pc=0x0c096604u; return 0; }
goto P_0c096622;
P_0c096606: /* original 0009, guest PC 0x0c096606 */
if(!s->budget--) { s->failed_pc=0x0c096606u; return 0; }
goto P_0c096608;
P_0c096608: /* original 2528, guest PC 0x0c096608 */
if(!s->budget--) { s->failed_pc=0x0c096608u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c09660a;
P_0c09660a: /* original 890a, guest PC 0x0c09660a */
if(!s->budget--) { s->failed_pc=0x0c09660au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096622; }
goto P_0c09660c;
P_0c09660c: /* original 60e2, guest PC 0x0c09660c */
if(!s->budget--) { s->failed_pc=0x0c09660cu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c09660e;
P_0c09660e: /* original 20d8, guest PC 0x0c09660e */
if(!s->budget--) { s->failed_pc=0x0c09660eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[13])==0)!=0);
goto P_0c096610;
P_0c096610: /* original 8907, guest PC 0x0c096610 */
if(!s->budget--) { s->failed_pc=0x0c096610u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096622; }
goto P_0c096612;
P_0c096612: /* original d337, guest PC 0x0c096612 */
if(!s->budget--) { s->failed_pc=0x0c096612u; return 0; }
r[3]=read(ram,0x0c0966f0u,4);
goto P_0c096614;
P_0c096614: /* original 9469, guest PC 0x0c096614 */
if(!s->budget--) { s->failed_pc=0x0c096614u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0966eau,2);
goto P_0c096616;
P_0c096616: /* original 430b, guest PC 0x0c096616 */
if(!s->budget--) { s->failed_pc=0x0c096616u; return 0; }
target=r[3];
r[16]=0x0c09661au;
r[5]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09661au) { target=s->pc; goto dispatch; }
goto P_0c09661a;
P_0c096618: /* original e500, guest PC 0x0c096618 */
if(!s->budget--) { s->failed_pc=0x0c096618u; return 0; }
r[5]=0x00000000u;
goto P_0c09661a;
P_0c09661a: /* original 62e2, guest PC 0x0c09661a */
if(!s->budget--) { s->failed_pc=0x0c09661au; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c09661c;
P_0c09661c: /* original e3fe, guest PC 0x0c09661c */
if(!s->budget--) { s->failed_pc=0x0c09661cu; return 0; }
r[3]=0xfffffffeu;
goto P_0c09661e;
P_0c09661e: /* original 2239, guest PC 0x0c09661e */
if(!s->budget--) { s->failed_pc=0x0c09661eu; return 0; }
r[2]&=r[3];
goto P_0c096620;
P_0c096620: /* original 2e22, guest PC 0x0c096620 */
if(!s->budget--) { s->failed_pc=0x0c096620u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c096622;
P_0c096622: /* original 4c0b, guest PC 0x0c096622 */
if(!s->budget--) { s->failed_pc=0x0c096622u; return 0; }
target=r[12];
r[16]=0x0c096626u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096626u) { target=s->pc; goto dispatch; }
goto P_0c096626;
P_0c096624: /* original e401, guest PC 0x0c096624 */
if(!s->budget--) { s->failed_pc=0x0c096624u; return 0; }
r[4]=0x00000001u;
goto P_0c096626;
P_0c096626: /* original 6403, guest PC 0x0c096626 */
if(!s->budget--) { s->failed_pc=0x0c096626u; return 0; }
r[4]=r[0];
goto P_0c096628;
P_0c096628: /* original 5242, guest PC 0x0c096628 */
if(!s->budget--) { s->failed_pc=0x0c096628u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c09662a;
P_0c09662a: /* original d332, guest PC 0x0c09662a */
if(!s->budget--) { s->failed_pc=0x0c09662au; return 0; }
r[3]=read(ram,0x0c0966f4u,4);
goto P_0c09662c;
P_0c09662c: /* original 2238, guest PC 0x0c09662c */
if(!s->budget--) { s->failed_pc=0x0c09662cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09662e;
P_0c09662e: /* original 8b03, guest PC 0x0c09662e */
if(!s->budget--) { s->failed_pc=0x0c09662eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c096638; }
goto P_0c096630;
P_0c096630: /* original 5242, guest PC 0x0c096630 */
if(!s->budget--) { s->failed_pc=0x0c096630u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c096632;
P_0c096632: /* original 955b, guest PC 0x0c096632 */
if(!s->budget--) { s->failed_pc=0x0c096632u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0966ecu,2);
goto P_0c096634;
P_0c096634: /* original 2259, guest PC 0x0c096634 */
if(!s->budget--) { s->failed_pc=0x0c096634u; return 0; }
r[2]&=r[5];
goto P_0c096636;
P_0c096636: /* original 3250, guest PC 0x0c096636 */
if(!s->budget--) { s->failed_pc=0x0c096636u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[5])!=0);
goto P_0c096638;
P_0c096638: /* original 7f04, guest PC 0x0c096638 */
if(!s->budget--) { s->failed_pc=0x0c096638u; return 0; }
r[15]+=0x00000004u;
goto P_0c09663a;
P_0c09663a: /* original 4f26, guest PC 0x0c09663a */
if(!s->budget--) { s->failed_pc=0x0c09663au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09663c;
P_0c09663c: /* original 68f6, guest PC 0x0c09663c */
if(!s->budget--) { s->failed_pc=0x0c09663cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09663e;
P_0c09663e: /* original 69f6, guest PC 0x0c09663e */
if(!s->budget--) { s->failed_pc=0x0c09663eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c096640;
P_0c096640: /* original 6af6, guest PC 0x0c096640 */
if(!s->budget--) { s->failed_pc=0x0c096640u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c096642;
P_0c096642: /* original 6bf6, guest PC 0x0c096642 */
if(!s->budget--) { s->failed_pc=0x0c096642u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c096644;
P_0c096644: /* original 6cf6, guest PC 0x0c096644 */
if(!s->budget--) { s->failed_pc=0x0c096644u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c096646;
P_0c096646: /* original 6df6, guest PC 0x0c096646 */
if(!s->budget--) { s->failed_pc=0x0c096646u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096648;
P_0c096648: /* original 000b, guest PC 0x0c096648 */
if(!s->budget--) { s->failed_pc=0x0c096648u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09664a: /* original 6ef6, guest PC 0x0c09664a */
if(!s->budget--) { s->failed_pc=0x0c09664au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09664cu,s,ram);
P_0c0a037c: /* original 4f22, guest PC 0x0c0a037c */
if(!s->budget--) { s->failed_pc=0x0c0a037cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a037e;
P_0c0a037e: /* original 054c, guest PC 0x0c0a037e */
if(!s->budget--) { s->failed_pc=0x0c0a037eu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a0380;
P_0c0a0380: /* original dc32, guest PC 0x0c0a0380 */
if(!s->budget--) { s->failed_pc=0x0c0a0380u; return 0; }
r[12]=read(ram,0x0c0a044cu,4);
goto P_0c0a0382;
P_0c0a0382: /* original 3563, guest PC 0x0c0a0382 */
if(!s->budget--) { s->failed_pc=0x0c0a0382u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c0a0384;
P_0c0a0384: /* original 8f08, guest PC 0x0c0a0384 */
if(!s->budget--) { s->failed_pc=0x0c0a0384u; return 0; }
cond=r[17]&1u;
r[14]=r[7];
if(!cond) { goto P_0c0a0398; }
goto P_0c0a0388;
P_0c0a0386: /* original 6e73, guest PC 0x0c0a0386 */
if(!s->budget--) { s->failed_pc=0x0c0a0386u; return 0; }
r[14]=r[7];
goto P_0c0a0388;
P_0c0a0388: /* original e50c, guest PC 0x0c0a0388 */
if(!s->budget--) { s->failed_pc=0x0c0a0388u; return 0; }
r[5]=0x0000000cu;
goto P_0c0a038a;
P_0c0a038a: /* original 6053, guest PC 0x0c0a038a */
if(!s->budget--) { s->failed_pc=0x0c0a038au; return 0; }
r[0]=r[5];
goto P_0c0a038c;
P_0c0a038c: /* original 707c, guest PC 0x0c0a038c */
if(!s->budget--) { s->failed_pc=0x0c0a038cu; return 0; }
r[0]+=0x0000007cu;
goto P_0c0a038e;
P_0c0a038e: /* original 034c, guest PC 0x0c0a038e */
if(!s->budget--) { s->failed_pc=0x0c0a038eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a0390;
P_0c0a0390: /* original 3353, guest PC 0x0c0a0390 */
if(!s->budget--) { s->failed_pc=0x0c0a0390u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[5])!=0);
goto P_0c0a0392;
P_0c0a0392: /* original 8f01, guest PC 0x0c0a0392 */
if(!s->budget--) { s->failed_pc=0x0c0a0392u; return 0; }
cond=r[17]&1u;
r[14]=r[6];
if(!cond) { goto P_0c0a0398; }
goto P_0c0a0396;
P_0c0a0394: /* original 6e63, guest PC 0x0c0a0394 */
if(!s->budget--) { s->failed_pc=0x0c0a0394u; return 0; }
r[14]=r[6];
goto P_0c0a0396;
P_0c0a0396: /* original 6e53, guest PC 0x0c0a0396 */
if(!s->budget--) { s->failed_pc=0x0c0a0396u; return 0; }
r[14]=r[5];
goto P_0c0a0398;
P_0c0a0398: /* original eb18, guest PC 0x0c0a0398 */
if(!s->budget--) { s->failed_pc=0x0c0a0398u; return 0; }
r[11]=0x00000018u;
goto P_0c0a039a;
P_0c0a039a: /* original a018, guest PC 0x0c0a039a */
if(!s->budget--) { s->failed_pc=0x0c0a039au; return 0; }
r[13]=r[7];
goto P_0c0a03ce;
P_0c0a039c: /* original 6d73, guest PC 0x0c0a039c */
if(!s->budget--) { s->failed_pc=0x0c0a039cu; return 0; }
r[13]=r[7];
goto P_0c0a039e;
P_0c0a039e: /* original 65e3, guest PC 0x0c0a039e */
if(!s->budget--) { s->failed_pc=0x0c0a039eu; return 0; }
r[5]=r[14];
goto P_0c0a03a0;
P_0c0a03a0: /* original b03d, guest PC 0x0c0a03a0 */
if(!s->budget--) { s->failed_pc=0x0c0a03a0u; return 0; }
target=0x0c0a041eu; r[16]=0x0c0a03a4u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a03a4u) { target=s->pc; goto dispatch; }
goto P_0c0a03a4;
P_0c0a03a2: /* original 64d3, guest PC 0x0c0a03a2 */
if(!s->budget--) { s->failed_pc=0x0c0a03a2u; return 0; }
r[4]=r[13];
goto P_0c0a03a4;
P_0c0a03a4: /* original 65e3, guest PC 0x0c0a03a4 */
if(!s->budget--) { s->failed_pc=0x0c0a03a4u; return 0; }
r[5]=r[14];
goto P_0c0a03a6;
P_0c0a03a6: /* original 63c3, guest PC 0x0c0a03a6 */
if(!s->budget--) { s->failed_pc=0x0c0a03a6u; return 0; }
r[3]=r[12];
goto P_0c0a03a8;
P_0c0a03a8: /* original 4508, guest PC 0x0c0a03a8 */
if(!s->budget--) { s->failed_pc=0x0c0a03a8u; return 0; }
r[5]<<=2;
goto P_0c0a03aa;
P_0c0a03aa: /* original 353c, guest PC 0x0c0a03aa */
if(!s->budget--) { s->failed_pc=0x0c0a03aau; return 0; }
r[5]+=r[3];
goto P_0c0a03ac;
P_0c0a03ac: /* original b056, guest PC 0x0c0a03ac */
if(!s->budget--) { s->failed_pc=0x0c0a03acu; return 0; }
target=0x0c0a045cu; r[16]=0x0c0a03b0u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a03b0u) { target=s->pc; goto dispatch; }
goto P_0c0a03b0;
P_0c0a03ae: /* original 64d3, guest PC 0x0c0a03ae */
if(!s->budget--) { s->failed_pc=0x0c0a03aeu; return 0; }
r[4]=r[13];
goto P_0c0a03b0;
P_0c0a03b0: /* original 63c3, guest PC 0x0c0a03b0 */
if(!s->budget--) { s->failed_pc=0x0c0a03b0u; return 0; }
r[3]=r[12];
goto P_0c0a03b2;
P_0c0a03b2: /* original 65e3, guest PC 0x0c0a03b2 */
if(!s->budget--) { s->failed_pc=0x0c0a03b2u; return 0; }
r[5]=r[14];
goto P_0c0a03b4;
P_0c0a03b4: /* original 7348, guest PC 0x0c0a03b4 */
if(!s->budget--) { s->failed_pc=0x0c0a03b4u; return 0; }
r[3]+=0x00000048u;
goto P_0c0a03b6;
P_0c0a03b6: /* original 4508, guest PC 0x0c0a03b6 */
if(!s->budget--) { s->failed_pc=0x0c0a03b6u; return 0; }
r[5]<<=2;
goto P_0c0a03b8;
P_0c0a03b8: /* original 353c, guest PC 0x0c0a03b8 */
if(!s->budget--) { s->failed_pc=0x0c0a03b8u; return 0; }
r[5]+=r[3];
goto P_0c0a03ba;
P_0c0a03ba: /* original b08f, guest PC 0x0c0a03ba */
if(!s->budget--) { s->failed_pc=0x0c0a03bau; return 0; }
target=0x0c0a04dcu; r[16]=0x0c0a03beu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a03beu) { target=s->pc; goto dispatch; }
goto P_0c0a03be;
P_0c0a03bc: /* original 64d3, guest PC 0x0c0a03bc */
if(!s->budget--) { s->failed_pc=0x0c0a03bcu; return 0; }
r[4]=r[13];
goto P_0c0a03be;
P_0c0a03be: /* original 9642, guest PC 0x0c0a03be */
if(!s->budget--) { s->failed_pc=0x0c0a03beu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0446u,2);
goto P_0c0a03c0;
P_0c0a03c0: /* original 65e3, guest PC 0x0c0a03c0 */
if(!s->budget--) { s->failed_pc=0x0c0a03c0u; return 0; }
r[5]=r[14];
goto P_0c0a03c2;
P_0c0a03c2: /* original 36cc, guest PC 0x0c0a03c2 */
if(!s->budget--) { s->failed_pc=0x0c0a03c2u; return 0; }
r[6]+=r[12];
goto P_0c0a03c4;
P_0c0a03c4: /* original 36ec, guest PC 0x0c0a03c4 */
if(!s->budget--) { s->failed_pc=0x0c0a03c4u; return 0; }
r[6]+=r[14];
goto P_0c0a03c6;
P_0c0a03c6: /* original b0e1, guest PC 0x0c0a03c6 */
if(!s->budget--) { s->failed_pc=0x0c0a03c6u; return 0; }
target=0x0c0a058cu; r[16]=0x0c0a03cau;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a03cau) { target=s->pc; goto dispatch; }
goto P_0c0a03ca;
P_0c0a03c8: /* original 64d3, guest PC 0x0c0a03c8 */
if(!s->budget--) { s->failed_pc=0x0c0a03c8u; return 0; }
r[4]=r[13];
goto P_0c0a03ca;
P_0c0a03ca: /* original 7e01, guest PC 0x0c0a03ca */
if(!s->budget--) { s->failed_pc=0x0c0a03cau; return 0; }
r[14]+=0x00000001u;
goto P_0c0a03cc;
P_0c0a03cc: /* original 7d04, guest PC 0x0c0a03cc */
if(!s->budget--) { s->failed_pc=0x0c0a03ccu; return 0; }
r[13]+=0x00000004u;
goto P_0c0a03ce;
P_0c0a03ce: /* original 3db3, guest PC 0x0c0a03ce */
if(!s->budget--) { s->failed_pc=0x0c0a03ceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[11])!=0);
goto P_0c0a03d0;
P_0c0a03d0: /* original 8be5, guest PC 0x0c0a03d0 */
if(!s->budget--) { s->failed_pc=0x0c0a03d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a039e; }
goto P_0c0a03d2;
P_0c0a03d2: /* original 4f26, guest PC 0x0c0a03d2 */
if(!s->budget--) { s->failed_pc=0x0c0a03d2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a03d4;
P_0c0a03d4: /* original 6bf6, guest PC 0x0c0a03d4 */
if(!s->budget--) { s->failed_pc=0x0c0a03d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a03d6;
P_0c0a03d6: /* original 6cf6, guest PC 0x0c0a03d6 */
if(!s->budget--) { s->failed_pc=0x0c0a03d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a03d8;
P_0c0a03d8: /* original 6df6, guest PC 0x0c0a03d8 */
if(!s->budget--) { s->failed_pc=0x0c0a03d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a03da;
P_0c0a03da: /* original 000b, guest PC 0x0c0a03da */
if(!s->budget--) { s->failed_pc=0x0c0a03dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a03dc: /* original 6ef6, guest PC 0x0c0a03dc */
if(!s->budget--) { s->failed_pc=0x0c0a03dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a03deu,s,ram);
P_0c0a041e: /* original 4f22, guest PC 0x0c0a041e */
if(!s->budget--) { s->failed_pc=0x0c0a041eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a0420;
P_0c0a0420: /* original 6153, guest PC 0x0c0a0420 */
if(!s->budget--) { s->failed_pc=0x0c0a0420u; return 0; }
r[1]=r[5];
goto P_0c0a0422;
P_0c0a0422: /* original 7101, guest PC 0x0c0a0422 */
if(!s->budget--) { s->failed_pc=0x0c0a0422u; return 0; }
r[1]+=0x00000001u;
goto P_0c0a0424;
P_0c0a0424: /* original e307, guest PC 0x0c0a0424 */
if(!s->budget--) { s->failed_pc=0x0c0a0424u; return 0; }
r[3]=0x00000007u;
goto P_0c0a0426;
P_0c0a0426: /* original 7ffc, guest PC 0x0c0a0426 */
if(!s->budget--) { s->failed_pc=0x0c0a0426u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a0428;
P_0c0a0428: /* original 2f52, guest PC 0x0c0a0428 */
if(!s->budget--) { s->failed_pc=0x0c0a0428u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0a042a;
P_0c0a042a: /* original 740c, guest PC 0x0c0a042a */
if(!s->budget--) { s->failed_pc=0x0c0a042au; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a042c;
P_0c0a042c: /* original 2f16, guest PC 0x0c0a042c */
if(!s->budget--) { s->failed_pc=0x0c0a042cu; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c0a042e;
P_0c0a042e: /* original 443c, guest PC 0x0c0a042e */
if(!s->budget--) { s->failed_pc=0x0c0a042eu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c0a0430;
P_0c0a0430: /* original d309, guest PC 0x0c0a0430 */
if(!s->budget--) { s->failed_pc=0x0c0a0430u; return 0; }
r[3]=read(ram,0x0c0a0458u,4);
goto P_0c0a0432;
P_0c0a0432: /* original e20e, guest PC 0x0c0a0432 */
if(!s->budget--) { s->failed_pc=0x0c0a0432u; return 0; }
r[2]=0x0000000eu;
goto P_0c0a0434;
P_0c0a0434: /* original d107, guest PC 0x0c0a0434 */
if(!s->budget--) { s->failed_pc=0x0c0a0434u; return 0; }
r[1]=read(ram,0x0c0a0454u,4);
goto P_0c0a0436;
P_0c0a0436: /* original 242b, guest PC 0x0c0a0436 */
if(!s->budget--) { s->failed_pc=0x0c0a0436u; return 0; }
r[4]|=r[2];
goto P_0c0a0438;
P_0c0a0438: /* original 430b, guest PC 0x0c0a0438 */
if(!s->budget--) { s->failed_pc=0x0c0a0438u; return 0; }
target=r[3];
r[16]=0x0c0a043cu;
r[15]-=4; write(ram,r[15],r[1],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a043cu) { target=s->pc; goto dispatch; }
goto P_0c0a043c;
P_0c0a043a: /* original 2f16, guest PC 0x0c0a043a */
if(!s->budget--) { s->failed_pc=0x0c0a043au; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c0a043c;
P_0c0a043c: /* original 7f0c, guest PC 0x0c0a043c */
if(!s->budget--) { s->failed_pc=0x0c0a043cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a043e;
P_0c0a043e: /* original 4f26, guest PC 0x0c0a043e */
if(!s->budget--) { s->failed_pc=0x0c0a043eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0440;
P_0c0a0440: /* original 000b, guest PC 0x0c0a0440 */
if(!s->budget--) { s->failed_pc=0x0c0a0440u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a0442: /* original 0009, guest PC 0x0c0a0442 */
if(!s->budget--) { s->failed_pc=0x0c0a0442u; return 0; }
return vf3_matrix_family(0x0c0a0444u,s,ram);
P_0c0a045c: /* original 2fe6, guest PC 0x0c0a045c */
if(!s->budget--) { s->failed_pc=0x0c0a045cu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0a045e;
P_0c0a045e: /* original 2fd6, guest PC 0x0c0a045e */
if(!s->budget--) { s->failed_pc=0x0c0a045eu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0a0460;
P_0c0a0460: /* original 6d53, guest PC 0x0c0a0460 */
if(!s->budget--) { s->failed_pc=0x0c0a0460u; return 0; }
r[13]=r[5];
goto P_0c0a0462;
P_0c0a0462: /* original 2fc6, guest PC 0x0c0a0462 */
if(!s->budget--) { s->failed_pc=0x0c0a0462u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
return vf3_matrix_family(0x0c0a0464u,s,ram);
P_0c0a04dc: /* original 2fe6, guest PC 0x0c0a04dc */
if(!s->budget--) { s->failed_pc=0x0c0a04dcu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0a04de;
P_0c0a04de: /* original 2fd6, guest PC 0x0c0a04de */
if(!s->budget--) { s->failed_pc=0x0c0a04deu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0a04e0;
P_0c0a04e0: /* original 2fc6, guest PC 0x0c0a04e0 */
if(!s->budget--) { s->failed_pc=0x0c0a04e0u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
return vf3_matrix_family(0x0c0a04e2u,s,ram);
P_0c0a058c: /* original 2fe6, guest PC 0x0c0a058c */
if(!s->budget--) { s->failed_pc=0x0c0a058cu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0a058e;
P_0c0a058e: /* original 4f22, guest PC 0x0c0a058e */
if(!s->budget--) { s->failed_pc=0x0c0a058eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a0590;
P_0c0a0590: /* original 7ff8, guest PC 0x0c0a0590 */
if(!s->budget--) { s->failed_pc=0x0c0a0590u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a0592;
P_0c0a0592: /* original 2f42, guest PC 0x0c0a0592 */
if(!s->budget--) { s->failed_pc=0x0c0a0592u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a0594;
P_0c0a0594: /* original 1f61, guest PC 0x0c0a0594 */
if(!s->budget--) { s->failed_pc=0x0c0a0594u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0a0596;
P_0c0a0596: /* original d312, guest PC 0x0c0a0596 */
if(!s->budget--) { s->failed_pc=0x0c0a0596u; return 0; }
r[3]=read(ram,0x0c0a05e0u,4);
goto P_0c0a0598;
P_0c0a0598: /* original 430b, guest PC 0x0c0a0598 */
if(!s->budget--) { s->failed_pc=0x0c0a0598u; return 0; }
target=r[3];
r[16]=0x0c0a059cu;
r[4]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a059cu) { target=s->pc; goto dispatch; }
goto P_0c0a059c;
P_0c0a059a: /* original 6463, guest PC 0x0c0a059a */
if(!s->budget--) { s->failed_pc=0x0c0a059au; return 0; }
r[4]=r[6];
goto P_0c0a059c;
P_0c0a059c: /* original d215, guest PC 0x0c0a059c */
if(!s->budget--) { s->failed_pc=0x0c0a059cu; return 0; }
r[2]=read(ram,0x0c0a05f4u,4);
goto P_0c0a059e;
P_0c0a059e: /* original e40d, guest PC 0x0c0a059e */
if(!s->budget--) { s->failed_pc=0x0c0a059eu; return 0; }
r[4]=0x0000000du;
goto P_0c0a05a0;
P_0c0a05a0: /* original 610c, guest PC 0x0c0a05a0 */
if(!s->budget--) { s->failed_pc=0x0c0a05a0u; return 0; }
r[1]=r[0]&255u;
goto P_0c0a05a2;
P_0c0a05a2: /* original 420b, guest PC 0x0c0a05a2 */
if(!s->budget--) { s->failed_pc=0x0c0a05a2u; return 0; }
target=r[2];
r[16]=0x0c0a05a6u;
r[0]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a05a6u) { target=s->pc; goto dispatch; }
goto P_0c0a05a6;
P_0c0a05a4: /* original 6043, guest PC 0x0c0a05a4 */
if(!s->budget--) { s->failed_pc=0x0c0a05a4u; return 0; }
r[0]=r[4];
goto P_0c0a05a6;
P_0c0a05a6: /* original 64f2, guest PC 0x0c0a05a6 */
if(!s->budget--) { s->failed_pc=0x0c0a05a6u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a05a8;
P_0c0a05a8: /* original e307, guest PC 0x0c0a05a8 */
if(!s->budget--) { s->failed_pc=0x0c0a05a8u; return 0; }
r[3]=0x00000007u;
goto P_0c0a05aa;
P_0c0a05aa: /* original 6503, guest PC 0x0c0a05aa */
if(!s->budget--) { s->failed_pc=0x0c0a05aau; return 0; }
r[5]=r[0];
goto P_0c0a05ac;
P_0c0a05ac: /* original 6053, guest PC 0x0c0a05ac */
if(!s->budget--) { s->failed_pc=0x0c0a05acu; return 0; }
r[0]=r[5];
goto P_0c0a05ae;
P_0c0a05ae: /* original 740c, guest PC 0x0c0a05ae */
if(!s->budget--) { s->failed_pc=0x0c0a05aeu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0a05b0;
P_0c0a05b0: /* original 8809, guest PC 0x0c0a05b0 */
if(!s->budget--) { s->failed_pc=0x0c0a05b0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0a05b2;
P_0c0a05b2: /* original e254, guest PC 0x0c0a05b2 */
if(!s->budget--) { s->failed_pc=0x0c0a05b2u; return 0; }
r[2]=0x00000054u;
goto P_0c0a05b4;
P_0c0a05b4: /* original 6e53, guest PC 0x0c0a05b4 */
if(!s->budget--) { s->failed_pc=0x0c0a05b4u; return 0; }
r[14]=r[5];
goto P_0c0a05b6;
P_0c0a05b6: /* original 443c, guest PC 0x0c0a05b6 */
if(!s->budget--) { s->failed_pc=0x0c0a05b6u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c0a05b8;
P_0c0a05b8: /* original 242b, guest PC 0x0c0a05b8 */
if(!s->budget--) { s->failed_pc=0x0c0a05b8u; return 0; }
r[4]|=r[2];
goto P_0c0a05ba;
P_0c0a05ba: /* original 8f1f, guest PC 0x0c0a05ba */
if(!s->budget--) { s->failed_pc=0x0c0a05bau; return 0; }
cond=r[17]&1u;
r[14]<<=2;
if(!cond) { goto P_0c0a05fc; }
goto P_0c0a05be;
P_0c0a05bc: /* original 4e08, guest PC 0x0c0a05bc */
if(!s->budget--) { s->failed_pc=0x0c0a05bcu; return 0; }
r[14]<<=2;
goto P_0c0a05be;
P_0c0a05be: /* original 7f08, guest PC 0x0c0a05be */
if(!s->budget--) { s->failed_pc=0x0c0a05beu; return 0; }
r[15]+=0x00000008u;
goto P_0c0a05c0;
P_0c0a05c0: /* original d00d, guest PC 0x0c0a05c0 */
if(!s->budget--) { s->failed_pc=0x0c0a05c0u; return 0; }
r[0]=read(ram,0x0c0a05f8u,4);
goto P_0c0a05c2;
P_0c0a05c2: /* original 4f26, guest PC 0x0c0a05c2 */
if(!s->budget--) { s->failed_pc=0x0c0a05c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a05c4;
P_0c0a05c4: /* original d307, guest PC 0x0c0a05c4 */
if(!s->budget--) { s->failed_pc=0x0c0a05c4u; return 0; }
r[3]=read(ram,0x0c0a05e4u,4);
goto P_0c0a05c6;
P_0c0a05c6: /* original e601, guest PC 0x0c0a05c6 */
if(!s->budget--) { s->failed_pc=0x0c0a05c6u; return 0; }
r[6]=0x00000001u;
goto P_0c0a05c8;
P_0c0a05c8: /* original 05ee, guest PC 0x0c0a05c8 */
if(!s->budget--) { s->failed_pc=0x0c0a05c8u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0a05ca;
P_0c0a05ca: /* original 432b, guest PC 0x0c0a05ca */
if(!s->budget--) { s->failed_pc=0x0c0a05cau; return 0; }
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
P_0c0a05cc: /* original 6ef6, guest PC 0x0c0a05cc */
if(!s->budget--) { s->failed_pc=0x0c0a05ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a05ceu,s,ram);
P_0c0a05fc: /* original d63f, guest PC 0x0c0a05fc */
if(!s->budget--) { s->failed_pc=0x0c0a05fcu; return 0; }
r[6]=read(ram,0x0c0a06fcu,4);
goto P_0c0a05fe;
P_0c0a05fe: /* original e100, guest PC 0x0c0a05fe */
if(!s->budget--) { s->failed_pc=0x0c0a05feu; return 0; }
r[1]=0x00000000u;
goto P_0c0a0600;
P_0c0a0600: /* original 2f16, guest PC 0x0c0a0600 */
if(!s->budget--) { s->failed_pc=0x0c0a0600u; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c0a0602;
P_0c0a0602: /* original 6713, guest PC 0x0c0a0602 */
if(!s->budget--) { s->failed_pc=0x0c0a0602u; return 0; }
r[7]=r[1];
goto P_0c0a0604;
P_0c0a0604: /* original d33f, guest PC 0x0c0a0604 */
if(!s->budget--) { s->failed_pc=0x0c0a0604u; return 0; }
r[3]=read(ram,0x0c0a0704u,4);
goto P_0c0a0606;
P_0c0a0606: /* original d03e, guest PC 0x0c0a0606 */
if(!s->budget--) { s->failed_pc=0x0c0a0606u; return 0; }
r[0]=read(ram,0x0c0a0700u,4);
goto P_0c0a0608;
P_0c0a0608: /* original 430b, guest PC 0x0c0a0608 */
if(!s->budget--) { s->failed_pc=0x0c0a0608u; return 0; }
target=r[3];
r[16]=0x0c0a060cu;
r[5]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a060cu) { target=s->pc; goto dispatch; }
goto P_0c0a060c;
P_0c0a060a: /* original 05ee, guest PC 0x0c0a060a */
if(!s->budget--) { s->failed_pc=0x0c0a060au; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0a060c;
P_0c0a060c: /* original 7f0c, guest PC 0x0c0a060c */
if(!s->budget--) { s->failed_pc=0x0c0a060cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a060e;
P_0c0a060e: /* original 4f26, guest PC 0x0c0a060e */
if(!s->budget--) { s->failed_pc=0x0c0a060eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a0610;
P_0c0a0610: /* original 000b, guest PC 0x0c0a0610 */
if(!s->budget--) { s->failed_pc=0x0c0a0610u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a0612: /* original 6ef6, guest PC 0x0c0a0612 */
if(!s->budget--) { s->failed_pc=0x0c0a0612u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a0614u,s,ram);
P_0c0a062c: /* original 4f22, guest PC 0x0c0a062c */
if(!s->budget--) { s->failed_pc=0x0c0a062cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a062e;
P_0c0a062e: /* original d336, guest PC 0x0c0a062e */
if(!s->budget--) { s->failed_pc=0x0c0a062eu; return 0; }
r[3]=read(ram,0x0c0a0708u,4);
goto P_0c0a0630;
P_0c0a0630: /* original e904, guest PC 0x0c0a0630 */
if(!s->budget--) { s->failed_pc=0x0c0a0630u; return 0; }
r[9]=0x00000004u;
goto P_0c0a0632;
P_0c0a0632: /* original 7ff0, guest PC 0x0c0a0632 */
if(!s->budget--) { s->failed_pc=0x0c0a0632u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a0634;
P_0c0a0634: /* original 1f33, guest PC 0x0c0a0634 */
if(!s->budget--) { s->failed_pc=0x0c0a0634u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0a0636;
P_0c0a0636: /* original d332, guest PC 0x0c0a0636 */
if(!s->budget--) { s->failed_pc=0x0c0a0636u; return 0; }
r[3]=read(ram,0x0c0a0700u,4);
goto P_0c0a0638;
P_0c0a0638: /* original dc30, guest PC 0x0c0a0638 */
if(!s->budget--) { s->failed_pc=0x0c0a0638u; return 0; }
r[12]=read(ram,0x0c0a06fcu,4);
goto P_0c0a063a;
P_0c0a063a: /* original 1f31, guest PC 0x0c0a063a */
if(!s->budget--) { s->failed_pc=0x0c0a063au; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0a063c;
P_0c0a063c: /* original e30d, guest PC 0x0c0a063c */
if(!s->budget--) { s->failed_pc=0x0c0a063cu; return 0; }
r[3]=0x0000000du;
goto P_0c0a063e;
P_0c0a063e: /* original 3e33, guest PC 0x0c0a063e */
if(!s->budget--) { s->failed_pc=0x0c0a063eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c0a0640;
P_0c0a0640: /* original 894e, guest PC 0x0c0a0640 */
if(!s->budget--) { s->failed_pc=0x0c0a0640u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a06e0; }
goto P_0c0a0642;
P_0c0a0642: /* original e206, guest PC 0x0c0a0642 */
if(!s->budget--) { s->failed_pc=0x0c0a0642u; return 0; }
r[2]=0x00000006u;
goto P_0c0a0644;
P_0c0a0644: /* original 3e23, guest PC 0x0c0a0644 */
if(!s->budget--) { s->failed_pc=0x0c0a0644u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c0a0646;
P_0c0a0646: /* original 8b09, guest PC 0x0c0a0646 */
if(!s->budget--) { s->failed_pc=0x0c0a0646u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a065c; }
goto P_0c0a0648;
P_0c0a0648: /* original 60e3, guest PC 0x0c0a0648 */
if(!s->budget--) { s->failed_pc=0x0c0a0648u; return 0; }
r[0]=r[14];
goto P_0c0a064a;
P_0c0a064a: /* original 8806, guest PC 0x0c0a064a */
if(!s->budget--) { s->failed_pc=0x0c0a064au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0a064c;
P_0c0a064c: /* original 8f04, guest PC 0x0c0a064c */
if(!s->budget--) { s->failed_pc=0x0c0a064cu; return 0; }
cond=r[17]&1u;
r[0]=r[14];
if(!cond) { goto P_0c0a0658; }
goto P_0c0a0650;
P_0c0a064e: /* original 60e3, guest PC 0x0c0a064e */
if(!s->budget--) { s->failed_pc=0x0c0a064eu; return 0; }
r[0]=r[14];
goto P_0c0a0650;
P_0c0a0650: /* original ea32, guest PC 0x0c0a0650 */
if(!s->budget--) { s->failed_pc=0x0c0a0650u; return 0; }
r[10]=0x00000032u;
goto P_0c0a0652;
P_0c0a0652: /* original ed08, guest PC 0x0c0a0652 */
if(!s->budget--) { s->failed_pc=0x0c0a0652u; return 0; }
r[13]=0x00000008u;
goto P_0c0a0654;
P_0c0a0654: /* original e922, guest PC 0x0c0a0654 */
if(!s->budget--) { s->failed_pc=0x0c0a0654u; return 0; }
r[9]=0x00000022u;
goto P_0c0a0656;
P_0c0a0656: /* original e82b, guest PC 0x0c0a0656 */
if(!s->budget--) { s->failed_pc=0x0c0a0656u; return 0; }
r[8]=0x0000002bu;
goto P_0c0a0658;
P_0c0a0658: /* original 8809, guest PC 0x0c0a0658 */
if(!s->budget--) { s->failed_pc=0x0c0a0658u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0a065a;
P_0c0a065a: /* original 893c, guest PC 0x0c0a065a */
if(!s->budget--) { s->failed_pc=0x0c0a065au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a06d6; }
goto P_0c0a065c;
P_0c0a065c: /* original 7d04, guest PC 0x0c0a065c */
if(!s->budget--) { s->failed_pc=0x0c0a065cu; return 0; }
r[13]+=0x00000004u;
goto P_0c0a065e;
P_0c0a065e: /* original 6493, guest PC 0x0c0a065e */
if(!s->budget--) { s->failed_pc=0x0c0a065eu; return 0; }
r[4]=r[9];
goto P_0c0a0660;
P_0c0a0660: /* original e307, guest PC 0x0c0a0660 */
if(!s->budget--) { s->failed_pc=0x0c0a0660u; return 0; }
r[3]=0x00000007u;
goto P_0c0a0662;
P_0c0a0662: /* original 62d3, guest PC 0x0c0a0662 */
if(!s->budget--) { s->failed_pc=0x0c0a0662u; return 0; }
r[2]=r[13];
goto P_0c0a0664;
P_0c0a0664: /* original 423c, guest PC 0x0c0a0664 */
if(!s->budget--) { s->failed_pc=0x0c0a0664u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[2]>>((-r[3])&31u)):((int32_t)r[2]<0?0xffffffffu:0)):r[2]<<(r[3]&31u);
goto P_0c0a0666;
P_0c0a0666: /* original 66c3, guest PC 0x0c0a0666 */
if(!s->budget--) { s->failed_pc=0x0c0a0666u; return 0; }
r[6]=r[12];
goto P_0c0a0668;
P_0c0a0668: /* original 2f22, guest PC 0x0c0a0668 */
if(!s->budget--) { s->failed_pc=0x0c0a0668u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a066a;
P_0c0a066a: /* original 4400, guest PC 0x0c0a066a */
if(!s->budget--) { s->failed_pc=0x0c0a066au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a066c;
P_0c0a066c: /* original 2fb6, guest PC 0x0c0a066c */
if(!s->budget--) { s->failed_pc=0x0c0a066cu; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0a066e;
P_0c0a066e: /* original 242b, guest PC 0x0c0a066e */
if(!s->budget--) { s->failed_pc=0x0c0a066eu; return 0; }
r[4]|=r[2];
goto P_0c0a0670;
P_0c0a0670: /* original 55f2, guest PC 0x0c0a0670 */
if(!s->budget--) { s->failed_pc=0x0c0a0670u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0a0672;
P_0c0a0672: /* original e700, guest PC 0x0c0a0672 */
if(!s->budget--) { s->failed_pc=0x0c0a0672u; return 0; }
r[7]=0x00000000u;
goto P_0c0a0674;
P_0c0a0674: /* original d123, guest PC 0x0c0a0674 */
if(!s->budget--) { s->failed_pc=0x0c0a0674u; return 0; }
r[1]=read(ram,0x0c0a0704u,4);
goto P_0c0a0676;
P_0c0a0676: /* original 410b, guest PC 0x0c0a0676 */
if(!s->budget--) { s->failed_pc=0x0c0a0676u; return 0; }
target=r[1];
r[16]=0x0c0a067au;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a067au) { target=s->pc; goto dispatch; }
goto P_0c0a067a;
P_0c0a0678: /* original 6552, guest PC 0x0c0a0678 */
if(!s->budget--) { s->failed_pc=0x0c0a0678u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0a067a;
P_0c0a067a: /* original 923b, guest PC 0x0c0a067a */
if(!s->budget--) { s->failed_pc=0x0c0a067au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a06f4u,2);
goto P_0c0a067c;
P_0c0a067c: /* original 63e3, guest PC 0x0c0a067c */
if(!s->budget--) { s->failed_pc=0x0c0a067cu; return 0; }
r[3]=r[14];
goto P_0c0a067e;
P_0c0a067e: /* original 54f4, guest PC 0x0c0a067e */
if(!s->budget--) { s->failed_pc=0x0c0a067eu; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c0a0680;
P_0c0a0680: /* original 4308, guest PC 0x0c0a0680 */
if(!s->budget--) { s->failed_pc=0x0c0a0680u; return 0; }
r[3]<<=2;
goto P_0c0a0682;
P_0c0a0682: /* original 342c, guest PC 0x0c0a0682 */
if(!s->budget--) { s->failed_pc=0x0c0a0682u; return 0; }
r[4]+=r[2];
goto P_0c0a0684;
P_0c0a0684: /* original 343c, guest PC 0x0c0a0684 */
if(!s->budget--) { s->failed_pc=0x0c0a0684u; return 0; }
r[4]+=r[3];
goto P_0c0a0686;
P_0c0a0686: /* original d321, guest PC 0x0c0a0686 */
if(!s->budget--) { s->failed_pc=0x0c0a0686u; return 0; }
r[3]=read(ram,0x0c0a070cu,4);
goto P_0c0a0688;
P_0c0a0688: /* original 430b, guest PC 0x0c0a0688 */
if(!s->budget--) { s->failed_pc=0x0c0a0688u; return 0; }
target=r[3];
r[16]=0x0c0a068cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a068cu) { target=s->pc; goto dispatch; }
goto P_0c0a068c;
P_0c0a068a: /* original 0009, guest PC 0x0c0a068a */
if(!s->budget--) { s->failed_pc=0x0c0a068au; return 0; }
goto P_0c0a068c;
P_0c0a068c: /* original 1f03, guest PC 0x0c0a068c */
if(!s->budget--) { s->failed_pc=0x0c0a068cu; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c0a068e;
P_0c0a068e: /* original 6483, guest PC 0x0c0a068e */
if(!s->budget--) { s->failed_pc=0x0c0a068eu; return 0; }
r[4]=r[8];
goto P_0c0a0690;
P_0c0a0690: /* original 52f3, guest PC 0x0c0a0690 */
if(!s->budget--) { s->failed_pc=0x0c0a0690u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0a0692;
P_0c0a0692: /* original 4400, guest PC 0x0c0a0692 */
if(!s->budget--) { s->failed_pc=0x0c0a0692u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a0694;
P_0c0a0694: /* original 53f1, guest PC 0x0c0a0694 */
if(!s->budget--) { s->failed_pc=0x0c0a0694u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a0696;
P_0c0a0696: /* original 2f26, guest PC 0x0c0a0696 */
if(!s->budget--) { s->failed_pc=0x0c0a0696u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c0a0698;
P_0c0a0698: /* original d11d, guest PC 0x0c0a0698 */
if(!s->budget--) { s->failed_pc=0x0c0a0698u; return 0; }
r[1]=read(ram,0x0c0a0710u,4);
goto P_0c0a069a;
P_0c0a069a: /* original 243b, guest PC 0x0c0a069a */
if(!s->budget--) { s->failed_pc=0x0c0a069au; return 0; }
r[4]|=r[3];
goto P_0c0a069c;
P_0c0a069c: /* original d21d, guest PC 0x0c0a069c */
if(!s->budget--) { s->failed_pc=0x0c0a069cu; return 0; }
r[2]=read(ram,0x0c0a0714u,4);
goto P_0c0a069e;
P_0c0a069e: /* original 420b, guest PC 0x0c0a069e */
if(!s->budget--) { s->failed_pc=0x0c0a069eu; return 0; }
target=r[2];
r[16]=0x0c0a06a2u;
r[15]-=4; write(ram,r[15],r[1],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a06a2u) { target=s->pc; goto dispatch; }
goto P_0c0a06a2;
P_0c0a06a0: /* original 2f16, guest PC 0x0c0a06a0 */
if(!s->budget--) { s->failed_pc=0x0c0a06a0u; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c0a06a2;
P_0c0a06a2: /* original 7f0c, guest PC 0x0c0a06a2 */
if(!s->budget--) { s->failed_pc=0x0c0a06a2u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a06a4;
P_0c0a06a4: /* original 52f2, guest PC 0x0c0a06a4 */
if(!s->budget--) { s->failed_pc=0x0c0a06a4u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0a06a6;
P_0c0a06a6: /* original e301, guest PC 0x0c0a06a6 */
if(!s->budget--) { s->failed_pc=0x0c0a06a6u; return 0; }
r[3]=0x00000001u;
goto P_0c0a06a8;
P_0c0a06a8: /* original 3237, guest PC 0x0c0a06a8 */
if(!s->budget--) { s->failed_pc=0x0c0a06a8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c0a06aa;
P_0c0a06aa: /* original 8b08, guest PC 0x0c0a06aa */
if(!s->budget--) { s->failed_pc=0x0c0a06aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a06be; }
goto P_0c0a06ac;
P_0c0a06ac: /* original 63f2, guest PC 0x0c0a06ac */
if(!s->budget--) { s->failed_pc=0x0c0a06acu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a06ae;
P_0c0a06ae: /* original 64a3, guest PC 0x0c0a06ae */
if(!s->budget--) { s->failed_pc=0x0c0a06aeu; return 0; }
r[4]=r[10];
goto P_0c0a06b0;
P_0c0a06b0: /* original 4400, guest PC 0x0c0a06b0 */
if(!s->budget--) { s->failed_pc=0x0c0a06b0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a06b2;
P_0c0a06b2: /* original 2fb6, guest PC 0x0c0a06b2 */
if(!s->budget--) { s->failed_pc=0x0c0a06b2u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0a06b4;
P_0c0a06b4: /* original 951f, guest PC 0x0c0a06b4 */
if(!s->budget--) { s->failed_pc=0x0c0a06b4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a06f6u,2);
goto P_0c0a06b6;
P_0c0a06b6: /* original e700, guest PC 0x0c0a06b6 */
if(!s->budget--) { s->failed_pc=0x0c0a06b6u; return 0; }
r[7]=0x00000000u;
goto P_0c0a06b8;
P_0c0a06b8: /* original 243b, guest PC 0x0c0a06b8 */
if(!s->budget--) { s->failed_pc=0x0c0a06b8u; return 0; }
r[4]|=r[3];
goto P_0c0a06ba;
P_0c0a06ba: /* original a008, guest PC 0x0c0a06ba */
if(!s->budget--) { s->failed_pc=0x0c0a06bau; return 0; }
r[6]=r[12];
goto P_0c0a06ce;
P_0c0a06bc: /* original 66c3, guest PC 0x0c0a06bc */
if(!s->budget--) { s->failed_pc=0x0c0a06bcu; return 0; }
r[6]=r[12];
goto P_0c0a06be;
P_0c0a06be: /* original 63f2, guest PC 0x0c0a06be */
if(!s->budget--) { s->failed_pc=0x0c0a06beu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a06c0;
P_0c0a06c0: /* original 64a3, guest PC 0x0c0a06c0 */
if(!s->budget--) { s->failed_pc=0x0c0a06c0u; return 0; }
r[4]=r[10];
goto P_0c0a06c2;
P_0c0a06c2: /* original 4400, guest PC 0x0c0a06c2 */
if(!s->budget--) { s->failed_pc=0x0c0a06c2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0a06c4;
P_0c0a06c4: /* original 66c3, guest PC 0x0c0a06c4 */
if(!s->budget--) { s->failed_pc=0x0c0a06c4u; return 0; }
r[6]=r[12];
goto P_0c0a06c6;
P_0c0a06c6: /* original e700, guest PC 0x0c0a06c6 */
if(!s->budget--) { s->failed_pc=0x0c0a06c6u; return 0; }
r[7]=0x00000000u;
goto P_0c0a06c8;
P_0c0a06c8: /* original 2fb6, guest PC 0x0c0a06c8 */
if(!s->budget--) { s->failed_pc=0x0c0a06c8u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0a06ca;
P_0c0a06ca: /* original 9515, guest PC 0x0c0a06ca */
if(!s->budget--) { s->failed_pc=0x0c0a06cau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a06f8u,2);
goto P_0c0a06cc;
P_0c0a06cc: /* original 243b, guest PC 0x0c0a06cc */
if(!s->budget--) { s->failed_pc=0x0c0a06ccu; return 0; }
r[4]|=r[3];
goto P_0c0a06ce;
P_0c0a06ce: /* original d20d, guest PC 0x0c0a06ce */
if(!s->budget--) { s->failed_pc=0x0c0a06ceu; return 0; }
r[2]=read(ram,0x0c0a0704u,4);
goto P_0c0a06d0;
P_0c0a06d0: /* original 420b, guest PC 0x0c0a06d0 */
if(!s->budget--) { s->failed_pc=0x0c0a06d0u; return 0; }
target=r[2];
r[16]=0x0c0a06d4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a06d4u) { target=s->pc; goto dispatch; }
goto P_0c0a06d4;
P_0c0a06d2: /* original 0009, guest PC 0x0c0a06d2 */
if(!s->budget--) { s->failed_pc=0x0c0a06d2u; return 0; }
goto P_0c0a06d4;
P_0c0a06d4: /* original 7f04, guest PC 0x0c0a06d4 */
if(!s->budget--) { s->failed_pc=0x0c0a06d4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a06d6;
P_0c0a06d6: /* original 53f1, guest PC 0x0c0a06d6 */
if(!s->budget--) { s->failed_pc=0x0c0a06d6u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a06d8;
P_0c0a06d8: /* original 7304, guest PC 0x0c0a06d8 */
if(!s->budget--) { s->failed_pc=0x0c0a06d8u; return 0; }
r[3]+=0x00000004u;
goto P_0c0a06da;
P_0c0a06da: /* original 1f31, guest PC 0x0c0a06da */
if(!s->budget--) { s->failed_pc=0x0c0a06dau; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0a06dc;
P_0c0a06dc: /* original afae, guest PC 0x0c0a06dc */
if(!s->budget--) { s->failed_pc=0x0c0a06dcu; return 0; }
r[14]+=0x00000001u;
goto P_0c0a063c;
P_0c0a06de: /* original 7e01, guest PC 0x0c0a06de */
if(!s->budget--) { s->failed_pc=0x0c0a06deu; return 0; }
r[14]+=0x00000001u;
goto P_0c0a06e0;
P_0c0a06e0: /* original 7f10, guest PC 0x0c0a06e0 */
if(!s->budget--) { s->failed_pc=0x0c0a06e0u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a06e2;
P_0c0a06e2: /* original 4f26, guest PC 0x0c0a06e2 */
if(!s->budget--) { s->failed_pc=0x0c0a06e2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a06e4;
P_0c0a06e4: /* original 68f6, guest PC 0x0c0a06e4 */
if(!s->budget--) { s->failed_pc=0x0c0a06e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a06e6;
P_0c0a06e6: /* original 69f6, guest PC 0x0c0a06e6 */
if(!s->budget--) { s->failed_pc=0x0c0a06e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a06e8;
P_0c0a06e8: /* original 6af6, guest PC 0x0c0a06e8 */
if(!s->budget--) { s->failed_pc=0x0c0a06e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a06ea;
P_0c0a06ea: /* original 6bf6, guest PC 0x0c0a06ea */
if(!s->budget--) { s->failed_pc=0x0c0a06eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a06ec;
P_0c0a06ec: /* original 6cf6, guest PC 0x0c0a06ec */
if(!s->budget--) { s->failed_pc=0x0c0a06ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a06ee;
P_0c0a06ee: /* original 6df6, guest PC 0x0c0a06ee */
if(!s->budget--) { s->failed_pc=0x0c0a06eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a06f0;
P_0c0a06f0: /* original 000b, guest PC 0x0c0a06f0 */
if(!s->budget--) { s->failed_pc=0x0c0a06f0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a06f2: /* original 6ef6, guest PC 0x0c0a06f2 */
if(!s->budget--) { s->failed_pc=0x0c0a06f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a06f4u,s,ram);
P_0c0a2994: /* original 4f22, guest PC 0x0c0a2994 */
if(!s->budget--) { s->failed_pc=0x0c0a2994u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2996;
P_0c0a2996: /* original 7ff8, guest PC 0x0c0a2996 */
if(!s->budget--) { s->failed_pc=0x0c0a2996u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a2998;
P_0c0a2998: /* original 2f61, guest PC 0x0c0a2998 */
if(!s->budget--) { s->failed_pc=0x0c0a2998u; return 0; }
write(ram,r[15],r[6],2);
goto P_0c0a299a;
P_0c0a299a: /* original b14c, guest PC 0x0c0a299a */
if(!s->budget--) { s->failed_pc=0x0c0a299au; return 0; }
target=0x0c0a2c36u; r[16]=0x0c0a299eu;
r[10]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a299eu) { target=s->pc; goto dispatch; }
goto P_0c0a299e;
P_0c0a299c: /* original 6a53, guest PC 0x0c0a299c */
if(!s->budget--) { s->failed_pc=0x0c0a299cu; return 0; }
r[10]=r[5];
goto P_0c0a299e;
P_0c0a299e: /* original 6403, guest PC 0x0c0a299e */
if(!s->budget--) { s->failed_pc=0x0c0a299eu; return 0; }
r[4]=r[0];
goto P_0c0a29a0;
P_0c0a29a0: /* original 2448, guest PC 0x0c0a29a0 */
if(!s->budget--) { s->failed_pc=0x0c0a29a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a29a2;
P_0c0a29a2: /* original 8902, guest PC 0x0c0a29a2 */
if(!s->budget--) { s->failed_pc=0x0c0a29a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a29aa; }
goto P_0c0a29a4;
P_0c0a29a4: /* original d375, guest PC 0x0c0a29a4 */
if(!s->budget--) { s->failed_pc=0x0c0a29a4u; return 0; }
r[3]=read(ram,0x0c0a2b7cu,4);
goto P_0c0a29a6;
P_0c0a29a6: /* original 3430, guest PC 0x0c0a29a6 */
if(!s->budget--) { s->failed_pc=0x0c0a29a6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c0a29a8;
P_0c0a29a8: /* original 8b59, guest PC 0x0c0a29a8 */
if(!s->budget--) { s->failed_pc=0x0c0a29a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2a5e; }
goto P_0c0a29aa;
P_0c0a29aa: /* original e020, guest PC 0x0c0a29aa */
if(!s->budget--) { s->failed_pc=0x0c0a29aau; return 0; }
r[0]=0x00000020u;
goto P_0c0a29ac;
P_0c0a29ac: /* original 01ed, guest PC 0x0c0a29ac */
if(!s->budget--) { s->failed_pc=0x0c0a29acu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a29ae;
P_0c0a29ae: /* original e022, guest PC 0x0c0a29ae */
if(!s->budget--) { s->failed_pc=0x0c0a29aeu; return 0; }
r[0]=0x00000022u;
goto P_0c0a29b0;
P_0c0a29b0: /* original 03ed, guest PC 0x0c0a29b0 */
if(!s->budget--) { s->failed_pc=0x0c0a29b0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a29b2;
P_0c0a29b2: /* original 611d, guest PC 0x0c0a29b2 */
if(!s->budget--) { s->failed_pc=0x0c0a29b2u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0a29b4;
P_0c0a29b4: /* original 633d, guest PC 0x0c0a29b4 */
if(!s->budget--) { s->failed_pc=0x0c0a29b4u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a29b6;
P_0c0a29b6: /* original 213b, guest PC 0x0c0a29b6 */
if(!s->budget--) { s->failed_pc=0x0c0a29b6u; return 0; }
r[1]|=r[3];
goto P_0c0a29b8;
P_0c0a29b8: /* original 2118, guest PC 0x0c0a29b8 */
if(!s->budget--) { s->failed_pc=0x0c0a29b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0a29ba;
P_0c0a29ba: /* original 8b50, guest PC 0x0c0a29ba */
if(!s->budget--) { s->failed_pc=0x0c0a29bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2a5e; }
goto P_0c0a29bc;
P_0c0a29bc: /* original e020, guest PC 0x0c0a29bc */
if(!s->budget--) { s->failed_pc=0x0c0a29bcu; return 0; }
r[0]=0x00000020u;
goto P_0c0a29be;
P_0c0a29be: /* original 52e4, guest PC 0x0c0a29be */
if(!s->budget--) { s->failed_pc=0x0c0a29beu; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c0a29c0;
P_0c0a29c0: /* original 1f21, guest PC 0x0c0a29c0 */
if(!s->budget--) { s->failed_pc=0x0c0a29c0u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a29c2;
P_0c0a29c2: /* original 63f1, guest PC 0x0c0a29c2 */
if(!s->budget--) { s->failed_pc=0x0c0a29c2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0a29c4;
P_0c0a29c4: /* original 5ce5, guest PC 0x0c0a29c4 */
if(!s->budget--) { s->failed_pc=0x0c0a29c4u; return 0; }
r[12]=read(ram,r[14]+20,4);
goto P_0c0a29c6;
P_0c0a29c6: /* original 0e35, guest PC 0x0c0a29c6 */
if(!s->budget--) { s->failed_pc=0x0c0a29c6u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0a29c8;
P_0c0a29c8: /* original 04ed, guest PC 0x0c0a29c8 */
if(!s->budget--) { s->failed_pc=0x0c0a29c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a29ca;
P_0c0a29ca: /* original d36d, guest PC 0x0c0a29ca */
if(!s->budget--) { s->failed_pc=0x0c0a29cau; return 0; }
r[3]=read(ram,0x0c0a2b80u,4);
goto P_0c0a29cc;
P_0c0a29cc: /* original 430b, guest PC 0x0c0a29cc */
if(!s->budget--) { s->failed_pc=0x0c0a29ccu; return 0; }
target=r[3];
r[16]=0x0c0a29d0u;
r[4]=r[4]&65535u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a29d0u) { target=s->pc; goto dispatch; }
goto P_0c0a29d0;
P_0c0a29ce: /* original 644d, guest PC 0x0c0a29ce */
if(!s->budget--) { s->failed_pc=0x0c0a29ceu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a29d0;
P_0c0a29d0: /* original eb00, guest PC 0x0c0a29d0 */
if(!s->budget--) { s->failed_pc=0x0c0a29d0u; return 0; }
r[11]=0x00000000u;
goto P_0c0a29d2;
P_0c0a29d2: /* original a039, guest PC 0x0c0a29d2 */
if(!s->budget--) { s->failed_pc=0x0c0a29d2u; return 0; }
r[8]=r[11];
goto P_0c0a2a48;
P_0c0a29d4: /* original 68b3, guest PC 0x0c0a29d4 */
if(!s->budget--) { s->failed_pc=0x0c0a29d4u; return 0; }
r[8]=r[11];
goto P_0c0a29d6;
P_0c0a29d6: /* original 53f1, guest PC 0x0c0a29d6 */
if(!s->budget--) { s->failed_pc=0x0c0a29d6u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a29d8;
P_0c0a29d8: /* original 6d83, guest PC 0x0c0a29d8 */
if(!s->budget--) { s->failed_pc=0x0c0a29d8u; return 0; }
r[13]=r[8];
goto P_0c0a29da;
P_0c0a29da: /* original 4d08, guest PC 0x0c0a29da */
if(!s->budget--) { s->failed_pc=0x0c0a29dau; return 0; }
r[13]<<=2;
goto P_0c0a29dc;
P_0c0a29dc: /* original 3d3c, guest PC 0x0c0a29dc */
if(!s->budget--) { s->failed_pc=0x0c0a29dcu; return 0; }
r[13]+=r[3];
goto P_0c0a29de;
P_0c0a29de: /* original 60d2, guest PC 0x0c0a29de */
if(!s->budget--) { s->failed_pc=0x0c0a29deu; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0a29e0;
P_0c0a29e0: /* original 5001, guest PC 0x0c0a29e0 */
if(!s->budget--) { s->failed_pc=0x0c0a29e0u; return 0; }
r[0]=read(ram,r[0]+4,4);
goto P_0c0a29e2;
P_0c0a29e2: /* original c801, guest PC 0x0c0a29e2 */
if(!s->budget--) { s->failed_pc=0x0c0a29e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a29e4;
P_0c0a29e4: /* original 8922, guest PC 0x0c0a29e4 */
if(!s->budget--) { s->failed_pc=0x0c0a29e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2a2c; }
goto P_0c0a29e6;
P_0c0a29e6: /* original a008, guest PC 0x0c0a29e6 */
if(!s->budget--) { s->failed_pc=0x0c0a29e6u; return 0; }
r[4]=r[11];
goto P_0c0a29fa;
P_0c0a29e8: /* original 64b3, guest PC 0x0c0a29e8 */
if(!s->budget--) { s->failed_pc=0x0c0a29e8u; return 0; }
r[4]=r[11];
goto P_0c0a29ea;
P_0c0a29ea: /* original 6343, guest PC 0x0c0a29ea */
if(!s->budget--) { s->failed_pc=0x0c0a29eau; return 0; }
r[3]=r[4];
goto P_0c0a29ec;
P_0c0a29ec: /* original 4308, guest PC 0x0c0a29ec */
if(!s->budget--) { s->failed_pc=0x0c0a29ecu; return 0; }
r[3]<<=2;
goto P_0c0a29ee;
P_0c0a29ee: /* original 4308, guest PC 0x0c0a29ee */
if(!s->budget--) { s->failed_pc=0x0c0a29eeu; return 0; }
r[3]<<=2;
goto P_0c0a29f0;
P_0c0a29f0: /* original 33cc, guest PC 0x0c0a29f0 */
if(!s->budget--) { s->failed_pc=0x0c0a29f0u; return 0; }
r[3]+=r[12];
goto P_0c0a29f2;
P_0c0a29f2: /* original 5232, guest PC 0x0c0a29f2 */
if(!s->budget--) { s->failed_pc=0x0c0a29f2u; return 0; }
r[2]=read(ram,r[3]+8,4);
goto P_0c0a29f4;
P_0c0a29f4: /* original 7401, guest PC 0x0c0a29f4 */
if(!s->budget--) { s->failed_pc=0x0c0a29f4u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a29f6;
P_0c0a29f6: /* original 32ac, guest PC 0x0c0a29f6 */
if(!s->budget--) { s->failed_pc=0x0c0a29f6u; return 0; }
r[2]+=r[10];
goto P_0c0a29f8;
P_0c0a29f8: /* original 1322, guest PC 0x0c0a29f8 */
if(!s->budget--) { s->failed_pc=0x0c0a29f8u; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c0a29fa;
P_0c0a29fa: /* original 85e7, guest PC 0x0c0a29fa */
if(!s->budget--) { s->failed_pc=0x0c0a29fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a29fc;
P_0c0a29fc: /* original 600d, guest PC 0x0c0a29fc */
if(!s->budget--) { s->failed_pc=0x0c0a29fcu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a29fe;
P_0c0a29fe: /* original 3403, guest PC 0x0c0a29fe */
if(!s->budget--) { s->failed_pc=0x0c0a29feu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c0a2a00;
P_0c0a2a00: /* original 8bf3, guest PC 0x0c0a2a00 */
if(!s->budget--) { s->failed_pc=0x0c0a2a00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a29ea; }
goto P_0c0a2a02;
P_0c0a2a02: /* original d260, guest PC 0x0c0a2a02 */
if(!s->budget--) { s->failed_pc=0x0c0a2a02u; return 0; }
r[2]=read(ram,0x0c0a2b84u,4);
goto P_0c0a2a04;
P_0c0a2a04: /* original 65c3, guest PC 0x0c0a2a04 */
if(!s->budget--) { s->failed_pc=0x0c0a2a04u; return 0; }
r[5]=r[12];
goto P_0c0a2a06;
P_0c0a2a06: /* original 420b, guest PC 0x0c0a2a06 */
if(!s->budget--) { s->failed_pc=0x0c0a2a06u; return 0; }
target=r[2];
r[16]=0x0c0a2a0au;
tmp=read(ram,r[13],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2a0au) { target=s->pc; goto dispatch; }
goto P_0c0a2a0a;
P_0c0a2a08: /* original 64d2, guest PC 0x0c0a2a08 */
if(!s->budget--) { s->failed_pc=0x0c0a2a08u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2a0a;
P_0c0a2a0a: /* original 2008, guest PC 0x0c0a2a0a */
if(!s->budget--) { s->failed_pc=0x0c0a2a0au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2a0c;
P_0c0a2a0c: /* original a008, guest PC 0x0c0a2a0c */
if(!s->budget--) { s->failed_pc=0x0c0a2a0cu; return 0; }
r[4]=r[11];
goto P_0c0a2a20;
P_0c0a2a0e: /* original 64b3, guest PC 0x0c0a2a0e */
if(!s->budget--) { s->failed_pc=0x0c0a2a0eu; return 0; }
r[4]=r[11];
goto P_0c0a2a10;
P_0c0a2a10: /* original 6343, guest PC 0x0c0a2a10 */
if(!s->budget--) { s->failed_pc=0x0c0a2a10u; return 0; }
r[3]=r[4];
goto P_0c0a2a12;
P_0c0a2a12: /* original 4308, guest PC 0x0c0a2a12 */
if(!s->budget--) { s->failed_pc=0x0c0a2a12u; return 0; }
r[3]<<=2;
goto P_0c0a2a14;
P_0c0a2a14: /* original 4308, guest PC 0x0c0a2a14 */
if(!s->budget--) { s->failed_pc=0x0c0a2a14u; return 0; }
r[3]<<=2;
goto P_0c0a2a16;
P_0c0a2a16: /* original 33cc, guest PC 0x0c0a2a16 */
if(!s->budget--) { s->failed_pc=0x0c0a2a16u; return 0; }
r[3]+=r[12];
goto P_0c0a2a18;
P_0c0a2a18: /* original 5232, guest PC 0x0c0a2a18 */
if(!s->budget--) { s->failed_pc=0x0c0a2a18u; return 0; }
r[2]=read(ram,r[3]+8,4);
goto P_0c0a2a1a;
P_0c0a2a1a: /* original 7401, guest PC 0x0c0a2a1a */
if(!s->budget--) { s->failed_pc=0x0c0a2a1au; return 0; }
r[4]+=0x00000001u;
goto P_0c0a2a1c;
P_0c0a2a1c: /* original 32a8, guest PC 0x0c0a2a1c */
if(!s->budget--) { s->failed_pc=0x0c0a2a1cu; return 0; }
r[2]-=r[10];
goto P_0c0a2a1e;
P_0c0a2a1e: /* original 1322, guest PC 0x0c0a2a1e */
if(!s->budget--) { s->failed_pc=0x0c0a2a1eu; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c0a2a20;
P_0c0a2a20: /* original 85e7, guest PC 0x0c0a2a20 */
if(!s->budget--) { s->failed_pc=0x0c0a2a20u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2a22;
P_0c0a2a22: /* original 600d, guest PC 0x0c0a2a22 */
if(!s->budget--) { s->failed_pc=0x0c0a2a22u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2a24;
P_0c0a2a24: /* original 3403, guest PC 0x0c0a2a24 */
if(!s->budget--) { s->failed_pc=0x0c0a2a24u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c0a2a26;
P_0c0a2a26: /* original 8bf3, guest PC 0x0c0a2a26 */
if(!s->budget--) { s->failed_pc=0x0c0a2a26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2a10; }
goto P_0c0a2a28;
P_0c0a2a28: /* original a00d, guest PC 0x0c0a2a28 */
if(!s->budget--) { s->failed_pc=0x0c0a2a28u; return 0; }
goto P_0c0a2a46;
P_0c0a2a2a: /* original 0009, guest PC 0x0c0a2a2a */
if(!s->budget--) { s->failed_pc=0x0c0a2a2au; return 0; }
goto P_0c0a2a2c;
P_0c0a2a2c: /* original 64d2, guest PC 0x0c0a2a2c */
if(!s->budget--) { s->failed_pc=0x0c0a2a2cu; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2a2e;
P_0c0a2a2e: /* original 66a3, guest PC 0x0c0a2a2e */
if(!s->budget--) { s->failed_pc=0x0c0a2a2eu; return 0; }
r[6]=r[10];
goto P_0c0a2a30;
P_0c0a2a30: /* original d355, guest PC 0x0c0a2a30 */
if(!s->budget--) { s->failed_pc=0x0c0a2a30u; return 0; }
r[3]=read(ram,0x0c0a2b88u,4);
goto P_0c0a2a32;
P_0c0a2a32: /* original 65c3, guest PC 0x0c0a2a32 */
if(!s->budget--) { s->failed_pc=0x0c0a2a32u; return 0; }
r[5]=r[12];
goto P_0c0a2a34;
P_0c0a2a34: /* original 430b, guest PC 0x0c0a2a34 */
if(!s->budget--) { s->failed_pc=0x0c0a2a34u; return 0; }
target=r[3];
r[16]=0x0c0a2a38u;
r[4]=read(ram,r[4]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2a38u) { target=s->pc; goto dispatch; }
goto P_0c0a2a38;
P_0c0a2a36: /* original 5441, guest PC 0x0c0a2a36 */
if(!s->budget--) { s->failed_pc=0x0c0a2a36u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0a2a38;
P_0c0a2a38: /* original 69d2, guest PC 0x0c0a2a38 */
if(!s->budget--) { s->failed_pc=0x0c0a2a38u; return 0; }
tmp=read(ram,r[13],4);
r[9]=tmp;
goto P_0c0a2a3a;
P_0c0a2a3a: /* original 2008, guest PC 0x0c0a2a3a */
if(!s->budget--) { s->failed_pc=0x0c0a2a3au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2a3c;
P_0c0a2a3c: /* original d353, guest PC 0x0c0a2a3c */
if(!s->budget--) { s->failed_pc=0x0c0a2a3cu; return 0; }
r[3]=read(ram,0x0c0a2b8cu,4);
goto P_0c0a2a3e;
P_0c0a2a3e: /* original 5591, guest PC 0x0c0a2a3e */
if(!s->budget--) { s->failed_pc=0x0c0a2a3eu; return 0; }
r[5]=read(ram,r[9]+4,4);
goto P_0c0a2a40;
P_0c0a2a40: /* original 5692, guest PC 0x0c0a2a40 */
if(!s->budget--) { s->failed_pc=0x0c0a2a40u; return 0; }
r[6]=read(ram,r[9]+8,4);
goto P_0c0a2a42;
P_0c0a2a42: /* original 430b, guest PC 0x0c0a2a42 */
if(!s->budget--) { s->failed_pc=0x0c0a2a42u; return 0; }
target=r[3];
r[16]=0x0c0a2a46u;
tmp=read(ram,r[9],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2a46u) { target=s->pc; goto dispatch; }
goto P_0c0a2a46;
P_0c0a2a44: /* original 6492, guest PC 0x0c0a2a44 */
if(!s->budget--) { s->failed_pc=0x0c0a2a44u; return 0; }
tmp=read(ram,r[9],4);
r[4]=tmp;
goto P_0c0a2a46;
P_0c0a2a46: /* original 7801, guest PC 0x0c0a2a46 */
if(!s->budget--) { s->failed_pc=0x0c0a2a46u; return 0; }
r[8]+=0x00000001u;
goto P_0c0a2a48;
P_0c0a2a48: /* original 85e6, guest PC 0x0c0a2a48 */
if(!s->budget--) { s->failed_pc=0x0c0a2a48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0a2a4a;
P_0c0a2a4a: /* original 600d, guest PC 0x0c0a2a4a */
if(!s->budget--) { s->failed_pc=0x0c0a2a4au; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2a4c;
P_0c0a2a4c: /* original 3803, guest PC 0x0c0a2a4c */
if(!s->budget--) { s->failed_pc=0x0c0a2a4cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[0])!=0);
goto P_0c0a2a4e;
P_0c0a2a4e: /* original 8bc2, guest PC 0x0c0a2a4e */
if(!s->budget--) { s->failed_pc=0x0c0a2a4eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a29d6; }
goto P_0c0a2a50;
P_0c0a2a50: /* original 63f1, guest PC 0x0c0a2a50 */
if(!s->budget--) { s->failed_pc=0x0c0a2a50u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0a2a52;
P_0c0a2a52: /* original e222, guest PC 0x0c0a2a52 */
if(!s->budget--) { s->failed_pc=0x0c0a2a52u; return 0; }
r[2]=0x00000022u;
goto P_0c0a2a54;
P_0c0a2a54: /* original 85e7, guest PC 0x0c0a2a54 */
if(!s->budget--) { s->failed_pc=0x0c0a2a54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2a56;
P_0c0a2a56: /* original 32ec, guest PC 0x0c0a2a56 */
if(!s->budget--) { s->failed_pc=0x0c0a2a56u; return 0; }
r[2]+=r[14];
goto P_0c0a2a58;
P_0c0a2a58: /* original 64b3, guest PC 0x0c0a2a58 */
if(!s->budget--) { s->failed_pc=0x0c0a2a58u; return 0; }
r[4]=r[11];
goto P_0c0a2a5a;
P_0c0a2a5a: /* original 303c, guest PC 0x0c0a2a5a */
if(!s->budget--) { s->failed_pc=0x0c0a2a5au; return 0; }
r[0]+=r[3];
goto P_0c0a2a5c;
P_0c0a2a5c: /* original 2201, guest PC 0x0c0a2a5c */
if(!s->budget--) { s->failed_pc=0x0c0a2a5cu; return 0; }
write(ram,r[2],r[0],2);
goto P_0c0a2a5e;
P_0c0a2a5e: /* original 7f08, guest PC 0x0c0a2a5e */
if(!s->budget--) { s->failed_pc=0x0c0a2a5eu; return 0; }
r[15]+=0x00000008u;
goto P_0c0a2a60;
P_0c0a2a60: /* original 6043, guest PC 0x0c0a2a60 */
if(!s->budget--) { s->failed_pc=0x0c0a2a60u; return 0; }
r[0]=r[4];
goto P_0c0a2a62;
P_0c0a2a62: /* original 4f26, guest PC 0x0c0a2a62 */
if(!s->budget--) { s->failed_pc=0x0c0a2a62u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2a64;
P_0c0a2a64: /* original 68f6, guest PC 0x0c0a2a64 */
if(!s->budget--) { s->failed_pc=0x0c0a2a64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2a66;
P_0c0a2a66: /* original 69f6, guest PC 0x0c0a2a66 */
if(!s->budget--) { s->failed_pc=0x0c0a2a66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a2a68;
P_0c0a2a68: /* original 6af6, guest PC 0x0c0a2a68 */
if(!s->budget--) { s->failed_pc=0x0c0a2a68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a2a6a;
P_0c0a2a6a: /* original 6bf6, guest PC 0x0c0a2a6a */
if(!s->budget--) { s->failed_pc=0x0c0a2a6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a2a6c;
P_0c0a2a6c: /* original 6cf6, guest PC 0x0c0a2a6c */
if(!s->budget--) { s->failed_pc=0x0c0a2a6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a2a6e;
P_0c0a2a6e: /* original 6df6, guest PC 0x0c0a2a6e */
if(!s->budget--) { s->failed_pc=0x0c0a2a6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2a70;
P_0c0a2a70: /* original 000b, guest PC 0x0c0a2a70 */
if(!s->budget--) { s->failed_pc=0x0c0a2a70u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2a72: /* original 6ef6, guest PC 0x0c0a2a72 */
if(!s->budget--) { s->failed_pc=0x0c0a2a72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a2a74u,s,ram);
P_0c0a2c48: /* original 4f22, guest PC 0x0c0a2c48 */
if(!s->budget--) { s->failed_pc=0x0c0a2c48u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2c4a;
P_0c0a2c4a: /* original 7ff8, guest PC 0x0c0a2c4a */
if(!s->budget--) { s->failed_pc=0x0c0a2c4au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a2c4c;
P_0c0a2c4c: /* original 1f41, guest PC 0x0c0a2c4c */
if(!s->budget--) { s->failed_pc=0x0c0a2c4cu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0a2c4e;
P_0c0a2c4e: /* original 60b2, guest PC 0x0c0a2c4e */
if(!s->budget--) { s->failed_pc=0x0c0a2c4eu; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c0a2c50;
P_0c0a2c50: /* original c880, guest PC 0x0c0a2c50 */
if(!s->budget--) { s->failed_pc=0x0c0a2c50u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0a2c52;
P_0c0a2c52: /* original 8d03, guest PC 0x0c0a2c52 */
if(!s->budget--) { s->failed_pc=0x0c0a2c52u; return 0; }
cond=r[17]&1u;
r[13]=r[11];
if(cond) { goto P_0c0a2c5c; }
goto P_0c0a2c56;
P_0c0a2c54: /* original 6db3, guest PC 0x0c0a2c54 */
if(!s->budget--) { s->failed_pc=0x0c0a2c54u; return 0; }
r[13]=r[11];
goto P_0c0a2c56;
P_0c0a2c56: /* original d217, guest PC 0x0c0a2c56 */
if(!s->budget--) { s->failed_pc=0x0c0a2c56u; return 0; }
r[2]=read(ram,0x0c0a2cb4u,4);
goto P_0c0a2c58;
P_0c0a2c58: /* original a06b, guest PC 0x0c0a2c58 */
if(!s->budget--) { s->failed_pc=0x0c0a2c58u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a2d32;
P_0c0a2c5a: /* original 1f21, guest PC 0x0c0a2c5a */
if(!s->budget--) { s->failed_pc=0x0c0a2c5au; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a2c5c;
P_0c0a2c5c: /* original 51b4, guest PC 0x0c0a2c5c */
if(!s->budget--) { s->failed_pc=0x0c0a2c5cu; return 0; }
r[1]=read(ram,r[11]+16,4);
goto P_0c0a2c5e;
P_0c0a2c5e: /* original e8fe, guest PC 0x0c0a2c5e */
if(!s->budget--) { s->failed_pc=0x0c0a2c5eu; return 0; }
r[8]=0xfffffffeu;
goto P_0c0a2c60;
P_0c0a2c60: /* original ea01, guest PC 0x0c0a2c60 */
if(!s->budget--) { s->failed_pc=0x0c0a2c60u; return 0; }
r[10]=0x00000001u;
goto P_0c0a2c62;
P_0c0a2c62: /* original 31bc, guest PC 0x0c0a2c62 */
if(!s->budget--) { s->failed_pc=0x0c0a2c62u; return 0; }
r[1]+=r[11];
goto P_0c0a2c64;
P_0c0a2c64: /* original 1b14, guest PC 0x0c0a2c64 */
if(!s->budget--) { s->failed_pc=0x0c0a2c64u; return 0; }
write(ram,r[11]+16,r[1],4);
goto P_0c0a2c66;
P_0c0a2c66: /* original 53b5, guest PC 0x0c0a2c66 */
if(!s->budget--) { s->failed_pc=0x0c0a2c66u; return 0; }
r[3]=read(ram,r[11]+20,4);
goto P_0c0a2c68;
P_0c0a2c68: /* original 33bc, guest PC 0x0c0a2c68 */
if(!s->budget--) { s->failed_pc=0x0c0a2c68u; return 0; }
r[3]+=r[11];
goto P_0c0a2c6a;
P_0c0a2c6a: /* original 1b35, guest PC 0x0c0a2c6a */
if(!s->budget--) { s->failed_pc=0x0c0a2c6au; return 0; }
write(ram,r[11]+20,r[3],4);
goto P_0c0a2c6c;
P_0c0a2c6c: /* original 52b4, guest PC 0x0c0a2c6c */
if(!s->budget--) { s->failed_pc=0x0c0a2c6cu; return 0; }
r[2]=read(ram,r[11]+16,4);
goto P_0c0a2c6e;
P_0c0a2c6e: /* original 2f22, guest PC 0x0c0a2c6e */
if(!s->budget--) { s->failed_pc=0x0c0a2c6eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a2c70;
P_0c0a2c70: /* original a058, guest PC 0x0c0a2c70 */
if(!s->budget--) { s->failed_pc=0x0c0a2c70u; return 0; }
r[9]=r[4];
goto P_0c0a2d24;
P_0c0a2c72: /* original 6943, guest PC 0x0c0a2c72 */
if(!s->budget--) { s->failed_pc=0x0c0a2c72u; return 0; }
r[9]=r[4];
goto P_0c0a2c74;
P_0c0a2c74: /* original 63f2, guest PC 0x0c0a2c74 */
if(!s->budget--) { s->failed_pc=0x0c0a2c74u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a2c76;
P_0c0a2c76: /* original 6c93, guest PC 0x0c0a2c76 */
if(!s->budget--) { s->failed_pc=0x0c0a2c76u; return 0; }
r[12]=r[9];
goto P_0c0a2c78;
P_0c0a2c78: /* original 4c08, guest PC 0x0c0a2c78 */
if(!s->budget--) { s->failed_pc=0x0c0a2c78u; return 0; }
r[12]<<=2;
goto P_0c0a2c7a;
P_0c0a2c7a: /* original 3c3c, guest PC 0x0c0a2c7a */
if(!s->budget--) { s->failed_pc=0x0c0a2c7au; return 0; }
r[12]+=r[3];
goto P_0c0a2c7c;
P_0c0a2c7c: /* original 62c2, guest PC 0x0c0a2c7c */
if(!s->budget--) { s->failed_pc=0x0c0a2c7cu; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c0a2c7e;
P_0c0a2c7e: /* original 2228, guest PC 0x0c0a2c7e */
if(!s->budget--) { s->failed_pc=0x0c0a2c7eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2c80;
P_0c0a2c80: /* original 894f, guest PC 0x0c0a2c80 */
if(!s->budget--) { s->failed_pc=0x0c0a2c80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d22; }
goto P_0c0a2c82;
P_0c0a2c82: /* original 62c2, guest PC 0x0c0a2c82 */
if(!s->budget--) { s->failed_pc=0x0c0a2c82u; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c0a2c84;
P_0c0a2c84: /* original 32dc, guest PC 0x0c0a2c84 */
if(!s->budget--) { s->failed_pc=0x0c0a2c84u; return 0; }
r[2]+=r[13];
goto P_0c0a2c86;
P_0c0a2c86: /* original 2c22, guest PC 0x0c0a2c86 */
if(!s->budget--) { s->failed_pc=0x0c0a2c86u; return 0; }
write(ram,r[12],r[2],4);
goto P_0c0a2c88;
P_0c0a2c88: /* original 63c2, guest PC 0x0c0a2c88 */
if(!s->budget--) { s->failed_pc=0x0c0a2c88u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c0a2c8a;
P_0c0a2c8a: /* original 23a8, guest PC 0x0c0a2c8a */
if(!s->budget--) { s->failed_pc=0x0c0a2c8au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[10])==0)!=0);
goto P_0c0a2c8c;
P_0c0a2c8c: /* original 8914, guest PC 0x0c0a2c8c */
if(!s->budget--) { s->failed_pc=0x0c0a2c8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2cb8; }
goto P_0c0a2c8e;
P_0c0a2c8e: /* original 61c2, guest PC 0x0c0a2c8e */
if(!s->budget--) { s->failed_pc=0x0c0a2c8eu; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c0a2c90;
P_0c0a2c90: /* original 2189, guest PC 0x0c0a2c90 */
if(!s->budget--) { s->failed_pc=0x0c0a2c90u; return 0; }
r[1]&=r[8];
goto P_0c0a2c92;
P_0c0a2c92: /* original 6413, guest PC 0x0c0a2c92 */
if(!s->budget--) { s->failed_pc=0x0c0a2c92u; return 0; }
r[4]=r[1];
goto P_0c0a2c94;
P_0c0a2c94: /* original 2c12, guest PC 0x0c0a2c94 */
if(!s->budget--) { s->failed_pc=0x0c0a2c94u; return 0; }
write(ram,r[12],r[1],4);
goto P_0c0a2c96;
P_0c0a2c96: /* original 5341, guest PC 0x0c0a2c96 */
if(!s->budget--) { s->failed_pc=0x0c0a2c96u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0a2c98;
P_0c0a2c98: /* original 23ab, guest PC 0x0c0a2c98 */
if(!s->budget--) { s->failed_pc=0x0c0a2c98u; return 0; }
r[3]|=r[10];
goto P_0c0a2c9a;
P_0c0a2c9a: /* original a042, guest PC 0x0c0a2c9a */
if(!s->budget--) { s->failed_pc=0x0c0a2c9au; return 0; }
write(ram,r[4]+4,r[3],4);
goto P_0c0a2d22;
P_0c0a2c9c: /* original 1431, guest PC 0x0c0a2c9c */
if(!s->budget--) { s->failed_pc=0x0c0a2c9cu; return 0; }
write(ram,r[4]+4,r[3],4);
return vf3_matrix_family(0x0c0a2c9eu,s,ram);
P_0c0a2cb8: /* original 6ec2, guest PC 0x0c0a2cb8 */
if(!s->budget--) { s->failed_pc=0x0c0a2cb8u; return 0; }
tmp=read(ram,r[12],4);
r[14]=tmp;
goto P_0c0a2cba;
P_0c0a2cba: /* original 63e2, guest PC 0x0c0a2cba */
if(!s->budget--) { s->failed_pc=0x0c0a2cbau; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0a2cbc;
P_0c0a2cbc: /* original 2338, guest PC 0x0c0a2cbc */
if(!s->budget--) { s->failed_pc=0x0c0a2cbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2cbe;
P_0c0a2cbe: /* original 8908, guest PC 0x0c0a2cbe */
if(!s->budget--) { s->failed_pc=0x0c0a2cbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2cd2; }
goto P_0c0a2cc0;
P_0c0a2cc0: /* original 63e2, guest PC 0x0c0a2cc0 */
if(!s->budget--) { s->failed_pc=0x0c0a2cc0u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0a2cc2;
P_0c0a2cc2: /* original 33d2, guest PC 0x0c0a2cc2 */
if(!s->budget--) { s->failed_pc=0x0c0a2cc2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2cc4;
P_0c0a2cc4: /* original 8905, guest PC 0x0c0a2cc4 */
if(!s->budget--) { s->failed_pc=0x0c0a2cc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2cd2; }
goto P_0c0a2cc6;
P_0c0a2cc6: /* original 61e2, guest PC 0x0c0a2cc6 */
if(!s->budget--) { s->failed_pc=0x0c0a2cc6u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0a2cc8;
P_0c0a2cc8: /* original 65d3, guest PC 0x0c0a2cc8 */
if(!s->budget--) { s->failed_pc=0x0c0a2cc8u; return 0; }
r[5]=r[13];
goto P_0c0a2cca;
P_0c0a2cca: /* original 31dc, guest PC 0x0c0a2cca */
if(!s->budget--) { s->failed_pc=0x0c0a2ccau; return 0; }
r[1]+=r[13];
goto P_0c0a2ccc;
P_0c0a2ccc: /* original 2e12, guest PC 0x0c0a2ccc */
if(!s->budget--) { s->failed_pc=0x0c0a2cccu; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0a2cce;
P_0c0a2cce: /* original b03b, guest PC 0x0c0a2cce */
if(!s->budget--) { s->failed_pc=0x0c0a2cceu; return 0; }
target=0x0c0a2d48u; r[16]=0x0c0a2cd2u;
r[4]=r[1];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2cd2u) { target=s->pc; goto dispatch; }
goto P_0c0a2cd2;
P_0c0a2cd0: /* original 6413, guest PC 0x0c0a2cd0 */
if(!s->budget--) { s->failed_pc=0x0c0a2cd0u; return 0; }
r[4]=r[1];
goto P_0c0a2cd2;
P_0c0a2cd2: /* original 52e1, guest PC 0x0c0a2cd2 */
if(!s->budget--) { s->failed_pc=0x0c0a2cd2u; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0a2cd4;
P_0c0a2cd4: /* original 2228, guest PC 0x0c0a2cd4 */
if(!s->budget--) { s->failed_pc=0x0c0a2cd4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2cd6;
P_0c0a2cd6: /* original 8913, guest PC 0x0c0a2cd6 */
if(!s->budget--) { s->failed_pc=0x0c0a2cd6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d00; }
goto P_0c0a2cd8;
P_0c0a2cd8: /* original 53e1, guest PC 0x0c0a2cd8 */
if(!s->budget--) { s->failed_pc=0x0c0a2cd8u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2cda;
P_0c0a2cda: /* original 33d2, guest PC 0x0c0a2cda */
if(!s->budget--) { s->failed_pc=0x0c0a2cdau; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2cdc;
P_0c0a2cdc: /* original 8910, guest PC 0x0c0a2cdc */
if(!s->budget--) { s->failed_pc=0x0c0a2cdcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d00; }
goto P_0c0a2cde;
P_0c0a2cde: /* original 51e1, guest PC 0x0c0a2cde */
if(!s->budget--) { s->failed_pc=0x0c0a2cdeu; return 0; }
r[1]=read(ram,r[14]+4,4);
goto P_0c0a2ce0;
P_0c0a2ce0: /* original 31dc, guest PC 0x0c0a2ce0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ce0u; return 0; }
r[1]+=r[13];
goto P_0c0a2ce2;
P_0c0a2ce2: /* original 6313, guest PC 0x0c0a2ce2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ce2u; return 0; }
r[3]=r[1];
goto P_0c0a2ce4;
P_0c0a2ce4: /* original 1e11, guest PC 0x0c0a2ce4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ce4u; return 0; }
write(ram,r[14]+4,r[1],4);
goto P_0c0a2ce6;
P_0c0a2ce6: /* original 6232, guest PC 0x0c0a2ce6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ce6u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0a2ce8;
P_0c0a2ce8: /* original 2228, guest PC 0x0c0a2ce8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ce8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2cea;
P_0c0a2cea: /* original 8909, guest PC 0x0c0a2cea */
if(!s->budget--) { s->failed_pc=0x0c0a2ceau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d00; }
goto P_0c0a2cec;
P_0c0a2cec: /* original 52e1, guest PC 0x0c0a2cec */
if(!s->budget--) { s->failed_pc=0x0c0a2cecu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0a2cee;
P_0c0a2cee: /* original 6322, guest PC 0x0c0a2cee */
if(!s->budget--) { s->failed_pc=0x0c0a2ceeu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0a2cf0;
P_0c0a2cf0: /* original 33d2, guest PC 0x0c0a2cf0 */
if(!s->budget--) { s->failed_pc=0x0c0a2cf0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2cf2;
P_0c0a2cf2: /* original 8905, guest PC 0x0c0a2cf2 */
if(!s->budget--) { s->failed_pc=0x0c0a2cf2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d00; }
goto P_0c0a2cf4;
P_0c0a2cf4: /* original 61c2, guest PC 0x0c0a2cf4 */
if(!s->budget--) { s->failed_pc=0x0c0a2cf4u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c0a2cf6;
P_0c0a2cf6: /* original 52e1, guest PC 0x0c0a2cf6 */
if(!s->budget--) { s->failed_pc=0x0c0a2cf6u; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0a2cf8;
P_0c0a2cf8: /* original 5311, guest PC 0x0c0a2cf8 */
if(!s->budget--) { s->failed_pc=0x0c0a2cf8u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c0a2cfa;
P_0c0a2cfa: /* original 6122, guest PC 0x0c0a2cfa */
if(!s->budget--) { s->failed_pc=0x0c0a2cfau; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0a2cfc;
P_0c0a2cfc: /* original 31dc, guest PC 0x0c0a2cfc */
if(!s->budget--) { s->failed_pc=0x0c0a2cfcu; return 0; }
r[1]+=r[13];
goto P_0c0a2cfe;
P_0c0a2cfe: /* original 2312, guest PC 0x0c0a2cfe */
if(!s->budget--) { s->failed_pc=0x0c0a2cfeu; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0a2d00;
P_0c0a2d00: /* original 53e2, guest PC 0x0c0a2d00 */
if(!s->budget--) { s->failed_pc=0x0c0a2d00u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c0a2d02;
P_0c0a2d02: /* original 2338, guest PC 0x0c0a2d02 */
if(!s->budget--) { s->failed_pc=0x0c0a2d02u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2d04;
P_0c0a2d04: /* original 890d, guest PC 0x0c0a2d04 */
if(!s->budget--) { s->failed_pc=0x0c0a2d04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d22; }
goto P_0c0a2d06;
P_0c0a2d06: /* original 53e2, guest PC 0x0c0a2d06 */
if(!s->budget--) { s->failed_pc=0x0c0a2d06u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c0a2d08;
P_0c0a2d08: /* original 33d2, guest PC 0x0c0a2d08 */
if(!s->budget--) { s->failed_pc=0x0c0a2d08u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2d0a;
P_0c0a2d0a: /* original 890a, guest PC 0x0c0a2d0a */
if(!s->budget--) { s->failed_pc=0x0c0a2d0au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d22; }
goto P_0c0a2d0c;
P_0c0a2d0c: /* original 51e2, guest PC 0x0c0a2d0c */
if(!s->budget--) { s->failed_pc=0x0c0a2d0cu; return 0; }
r[1]=read(ram,r[14]+8,4);
goto P_0c0a2d0e;
P_0c0a2d0e: /* original 31dc, guest PC 0x0c0a2d0e */
if(!s->budget--) { s->failed_pc=0x0c0a2d0eu; return 0; }
r[1]+=r[13];
goto P_0c0a2d10;
P_0c0a2d10: /* original 6313, guest PC 0x0c0a2d10 */
if(!s->budget--) { s->failed_pc=0x0c0a2d10u; return 0; }
r[3]=r[1];
goto P_0c0a2d12;
P_0c0a2d12: /* original 1e12, guest PC 0x0c0a2d12 */
if(!s->budget--) { s->failed_pc=0x0c0a2d12u; return 0; }
write(ram,r[14]+8,r[1],4);
goto P_0c0a2d14;
P_0c0a2d14: /* original 6232, guest PC 0x0c0a2d14 */
if(!s->budget--) { s->failed_pc=0x0c0a2d14u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0a2d16;
P_0c0a2d16: /* original 2228, guest PC 0x0c0a2d16 */
if(!s->budget--) { s->failed_pc=0x0c0a2d16u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2d18;
P_0c0a2d18: /* original 8903, guest PC 0x0c0a2d18 */
if(!s->budget--) { s->failed_pc=0x0c0a2d18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d22; }
goto P_0c0a2d1a;
P_0c0a2d1a: /* original 54e2, guest PC 0x0c0a2d1a */
if(!s->budget--) { s->failed_pc=0x0c0a2d1au; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c0a2d1c;
P_0c0a2d1c: /* original 6342, guest PC 0x0c0a2d1c */
if(!s->budget--) { s->failed_pc=0x0c0a2d1cu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0a2d1e;
P_0c0a2d1e: /* original 33dc, guest PC 0x0c0a2d1e */
if(!s->budget--) { s->failed_pc=0x0c0a2d1eu; return 0; }
r[3]+=r[13];
goto P_0c0a2d20;
P_0c0a2d20: /* original 2432, guest PC 0x0c0a2d20 */
if(!s->budget--) { s->failed_pc=0x0c0a2d20u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c0a2d22;
P_0c0a2d22: /* original 7901, guest PC 0x0c0a2d22 */
if(!s->budget--) { s->failed_pc=0x0c0a2d22u; return 0; }
r[9]+=0x00000001u;
goto P_0c0a2d24;
P_0c0a2d24: /* original 85b6, guest PC 0x0c0a2d24 */
if(!s->budget--) { s->failed_pc=0x0c0a2d24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+12,2);
goto P_0c0a2d26;
P_0c0a2d26: /* original 600d, guest PC 0x0c0a2d26 */
if(!s->budget--) { s->failed_pc=0x0c0a2d26u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2d28;
P_0c0a2d28: /* original 3903, guest PC 0x0c0a2d28 */
if(!s->budget--) { s->failed_pc=0x0c0a2d28u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[0])!=0);
goto P_0c0a2d2a;
P_0c0a2d2a: /* original 8ba3, guest PC 0x0c0a2d2a */
if(!s->budget--) { s->failed_pc=0x0c0a2d2au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2c74; }
goto P_0c0a2d2c;
P_0c0a2d2c: /* original 60b2, guest PC 0x0c0a2d2c */
if(!s->budget--) { s->failed_pc=0x0c0a2d2cu; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c0a2d2e;
P_0c0a2d2e: /* original cb80, guest PC 0x0c0a2d2e */
if(!s->budget--) { s->failed_pc=0x0c0a2d2eu; return 0; }
r[0]|=128u;
goto P_0c0a2d30;
P_0c0a2d30: /* original 2b02, guest PC 0x0c0a2d30 */
if(!s->budget--) { s->failed_pc=0x0c0a2d30u; return 0; }
write(ram,r[11],r[0],4);
goto P_0c0a2d32;
P_0c0a2d32: /* original 50f1, guest PC 0x0c0a2d32 */
if(!s->budget--) { s->failed_pc=0x0c0a2d32u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0a2d34;
P_0c0a2d34: /* original 7f08, guest PC 0x0c0a2d34 */
if(!s->budget--) { s->failed_pc=0x0c0a2d34u; return 0; }
r[15]+=0x00000008u;
goto P_0c0a2d36;
P_0c0a2d36: /* original 4f26, guest PC 0x0c0a2d36 */
if(!s->budget--) { s->failed_pc=0x0c0a2d36u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2d38;
P_0c0a2d38: /* original 68f6, guest PC 0x0c0a2d38 */
if(!s->budget--) { s->failed_pc=0x0c0a2d38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2d3a;
P_0c0a2d3a: /* original 69f6, guest PC 0x0c0a2d3a */
if(!s->budget--) { s->failed_pc=0x0c0a2d3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a2d3c;
P_0c0a2d3c: /* original 6af6, guest PC 0x0c0a2d3c */
if(!s->budget--) { s->failed_pc=0x0c0a2d3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a2d3e;
P_0c0a2d3e: /* original 6bf6, guest PC 0x0c0a2d3e */
if(!s->budget--) { s->failed_pc=0x0c0a2d3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a2d40;
P_0c0a2d40: /* original 6cf6, guest PC 0x0c0a2d40 */
if(!s->budget--) { s->failed_pc=0x0c0a2d40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a2d42;
P_0c0a2d42: /* original 6df6, guest PC 0x0c0a2d42 */
if(!s->budget--) { s->failed_pc=0x0c0a2d42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2d44;
P_0c0a2d44: /* original 000b, guest PC 0x0c0a2d44 */
if(!s->budget--) { s->failed_pc=0x0c0a2d44u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2d46: /* original 6ef6, guest PC 0x0c0a2d46 */
if(!s->budget--) { s->failed_pc=0x0c0a2d46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a2d48u,s,ram);
P_0c0a7602: /* original 4f22, guest PC 0x0c0a7602 */
if(!s->budget--) { s->failed_pc=0x0c0a7602u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7604;
P_0c0a7604: /* original 935b, guest PC 0x0c0a7604 */
if(!s->budget--) { s->failed_pc=0x0c0a7604u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a76beu,2);
goto P_0c0a7606;
P_0c0a7606: /* original 3433, guest PC 0x0c0a7606 */
if(!s->budget--) { s->failed_pc=0x0c0a7606u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0a7608;
P_0c0a7608: /* original 7ffc, guest PC 0x0c0a7608 */
if(!s->budget--) { s->failed_pc=0x0c0a7608u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a760a;
P_0c0a760a: /* original 8d26, guest PC 0x0c0a760a */
if(!s->budget--) { s->failed_pc=0x0c0a760au; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,4,r[15]);
if(cond) { goto P_0c0a765a; }
goto P_0c0a760e;
P_0c0a760c: /* original ff4a, guest PC 0x0c0a760c */
if(!s->budget--) { s->failed_pc=0x0c0a760cu; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c0a760e;
P_0c0a760e: /* original d02c, guest PC 0x0c0a760e */
if(!s->budget--) { s->failed_pc=0x0c0a760eu; return 0; }
r[0]=read(ram,0x0c0a76c0u,4);
goto P_0c0a7610;
P_0c0a7610: /* original 6e43, guest PC 0x0c0a7610 */
if(!s->budget--) { s->failed_pc=0x0c0a7610u; return 0; }
r[14]=r[4];
goto P_0c0a7612;
P_0c0a7612: /* original 4e08, guest PC 0x0c0a7612 */
if(!s->budget--) { s->failed_pc=0x0c0a7612u; return 0; }
r[14]<<=2;
goto P_0c0a7614;
P_0c0a7614: /* original 0eee, guest PC 0x0c0a7614 */
if(!s->budget--) { s->failed_pc=0x0c0a7614u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c0a7616;
P_0c0a7616: /* original 2ee8, guest PC 0x0c0a7616 */
if(!s->budget--) { s->failed_pc=0x0c0a7616u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a7618;
P_0c0a7618: /* original 891f, guest PC 0x0c0a7618 */
if(!s->budget--) { s->failed_pc=0x0c0a7618u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a765a; }
goto P_0c0a761a;
P_0c0a761a: /* original 60e3, guest PC 0x0c0a761a */
if(!s->budget--) { s->failed_pc=0x0c0a761au; return 0; }
r[0]=r[14];
goto P_0c0a761c;
P_0c0a761c: /* original 88ff, guest PC 0x0c0a761c */
if(!s->budget--) { s->failed_pc=0x0c0a761cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0a761e;
P_0c0a761e: /* original 891c, guest PC 0x0c0a761e */
if(!s->budget--) { s->failed_pc=0x0c0a761eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a765a; }
goto P_0c0a7620;
P_0c0a7620: /* original d328, guest PC 0x0c0a7620 */
if(!s->budget--) { s->failed_pc=0x0c0a7620u; return 0; }
r[3]=read(ram,0x0c0a76c4u,4);
goto P_0c0a7622;
P_0c0a7622: /* original 430b, guest PC 0x0c0a7622 */
if(!s->budget--) { s->failed_pc=0x0c0a7622u; return 0; }
target=r[3];
r[16]=0x0c0a7626u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7626u) { target=s->pc; goto dispatch; }
goto P_0c0a7626;
P_0c0a7624: /* original e400, guest PC 0x0c0a7624 */
if(!s->budget--) { s->failed_pc=0x0c0a7624u; return 0; }
r[4]=0x00000000u;
goto P_0c0a7626;
P_0c0a7626: /* original d229, guest PC 0x0c0a7626 */
if(!s->budget--) { s->failed_pc=0x0c0a7626u; return 0; }
r[2]=read(ram,0x0c0a76ccu,4);
goto P_0c0a7628;
P_0c0a7628: /* original d427, guest PC 0x0c0a7628 */
if(!s->budget--) { s->failed_pc=0x0c0a7628u; return 0; }
r[4]=read(ram,0x0c0a76c8u,4);
goto P_0c0a762a;
P_0c0a762a: /* original 420b, guest PC 0x0c0a762a */
if(!s->budget--) { s->failed_pc=0x0c0a762au; return 0; }
target=r[2];
r[16]=0x0c0a762eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a762eu) { target=s->pc; goto dispatch; }
goto P_0c0a762e;
P_0c0a762c: /* original 0009, guest PC 0x0c0a762c */
if(!s->budget--) { s->failed_pc=0x0c0a762cu; return 0; }
goto P_0c0a762e;
P_0c0a762e: /* original 50e1, guest PC 0x0c0a762e */
if(!s->budget--) { s->failed_pc=0x0c0a762eu; return 0; }
r[0]=read(ram,r[14]+4,4);
goto P_0c0a7630;
P_0c0a7630: /* original c801, guest PC 0x0c0a7630 */
if(!s->budget--) { s->failed_pc=0x0c0a7630u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a7632;
P_0c0a7632: /* original 8905, guest PC 0x0c0a7632 */
if(!s->budget--) { s->failed_pc=0x0c0a7632u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7640; }
goto P_0c0a7634;
P_0c0a7634: /* original d326, guest PC 0x0c0a7634 */
if(!s->budget--) { s->failed_pc=0x0c0a7634u; return 0; }
r[3]=read(ram,0x0c0a76d0u,4);
goto P_0c0a7636;
P_0c0a7636: /* original f4f8, guest PC 0x0c0a7636 */
if(!s->budget--) { s->failed_pc=0x0c0a7636u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0a7638;
P_0c0a7638: /* original 430b, guest PC 0x0c0a7638 */
if(!s->budget--) { s->failed_pc=0x0c0a7638u; return 0; }
target=r[3];
r[16]=0x0c0a763cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a763cu) { target=s->pc; goto dispatch; }
goto P_0c0a763c;
P_0c0a763a: /* original 64e3, guest PC 0x0c0a763a */
if(!s->budget--) { s->failed_pc=0x0c0a763au; return 0; }
r[4]=r[14];
goto P_0c0a763c;
P_0c0a763c: /* original a007, guest PC 0x0c0a763c */
if(!s->budget--) { s->failed_pc=0x0c0a763cu; return 0; }
goto P_0c0a764e;
P_0c0a763e: /* original 0009, guest PC 0x0c0a763e */
if(!s->budget--) { s->failed_pc=0x0c0a763eu; return 0; }
goto P_0c0a7640;
P_0c0a7640: /* original d324, guest PC 0x0c0a7640 */
if(!s->budget--) { s->failed_pc=0x0c0a7640u; return 0; }
r[3]=read(ram,0x0c0a76d4u,4);
goto P_0c0a7642;
P_0c0a7642: /* original 430b, guest PC 0x0c0a7642 */
if(!s->budget--) { s->failed_pc=0x0c0a7642u; return 0; }
target=r[3];
r[16]=0x0c0a7646u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7646u) { target=s->pc; goto dispatch; }
goto P_0c0a7646;
P_0c0a7644: /* original 0009, guest PC 0x0c0a7644 */
if(!s->budget--) { s->failed_pc=0x0c0a7644u; return 0; }
goto P_0c0a7646;
P_0c0a7646: /* original d324, guest PC 0x0c0a7646 */
if(!s->budget--) { s->failed_pc=0x0c0a7646u; return 0; }
r[3]=read(ram,0x0c0a76d8u,4);
goto P_0c0a7648;
P_0c0a7648: /* original f4f8, guest PC 0x0c0a7648 */
if(!s->budget--) { s->failed_pc=0x0c0a7648u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0a764a;
P_0c0a764a: /* original 430b, guest PC 0x0c0a764a */
if(!s->budget--) { s->failed_pc=0x0c0a764au; return 0; }
target=r[3];
r[16]=0x0c0a764eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a764eu) { target=s->pc; goto dispatch; }
goto P_0c0a764e;
P_0c0a764c: /* original 64e3, guest PC 0x0c0a764c */
if(!s->budget--) { s->failed_pc=0x0c0a764cu; return 0; }
r[4]=r[14];
goto P_0c0a764e;
P_0c0a764e: /* original 7f04, guest PC 0x0c0a764e */
if(!s->budget--) { s->failed_pc=0x0c0a764eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0a7650;
P_0c0a7650: /* original d222, guest PC 0x0c0a7650 */
if(!s->budget--) { s->failed_pc=0x0c0a7650u; return 0; }
r[2]=read(ram,0x0c0a76dcu,4);
goto P_0c0a7652;
P_0c0a7652: /* original 4f26, guest PC 0x0c0a7652 */
if(!s->budget--) { s->failed_pc=0x0c0a7652u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7654;
P_0c0a7654: /* original e401, guest PC 0x0c0a7654 */
if(!s->budget--) { s->failed_pc=0x0c0a7654u; return 0; }
r[4]=0x00000001u;
goto P_0c0a7656;
P_0c0a7656: /* original 422b, guest PC 0x0c0a7656 */
if(!s->budget--) { s->failed_pc=0x0c0a7656u; return 0; }
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
P_0c0a7658: /* original 6ef6, guest PC 0x0c0a7658 */
if(!s->budget--) { s->failed_pc=0x0c0a7658u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a765a;
P_0c0a765a: /* original 7f04, guest PC 0x0c0a765a */
if(!s->budget--) { s->failed_pc=0x0c0a765au; return 0; }
r[15]+=0x00000004u;
goto P_0c0a765c;
P_0c0a765c: /* original 4f26, guest PC 0x0c0a765c */
if(!s->budget--) { s->failed_pc=0x0c0a765cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a765e;
P_0c0a765e: /* original 000b, guest PC 0x0c0a765e */
if(!s->budget--) { s->failed_pc=0x0c0a765eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a7660: /* original 6ef6, guest PC 0x0c0a7660 */
if(!s->budget--) { s->failed_pc=0x0c0a7660u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a7662u,s,ram);
P_0c0a7a1c: /* original 4f22, guest PC 0x0c0a7a1c */
if(!s->budget--) { s->failed_pc=0x0c0a7a1cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7a1e;
P_0c0a7a1e: /* original 2e5b, guest PC 0x0c0a7a1e */
if(!s->budget--) { s->failed_pc=0x0c0a7a1eu; return 0; }
r[14]|=r[5];
goto P_0c0a7a20;
P_0c0a7a20: /* original 2e4b, guest PC 0x0c0a7a20 */
if(!s->budget--) { s->failed_pc=0x0c0a7a20u; return 0; }
r[14]|=r[4];
goto P_0c0a7a22;
P_0c0a7a22: /* original 7ffc, guest PC 0x0c0a7a22 */
if(!s->budget--) { s->failed_pc=0x0c0a7a22u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a7a24;
P_0c0a7a24: /* original ff4a, guest PC 0x0c0a7a24 */
if(!s->budget--) { s->failed_pc=0x0c0a7a24u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c0a7a26;
P_0c0a7a26: /* original d327, guest PC 0x0c0a7a26 */
if(!s->budget--) { s->failed_pc=0x0c0a7a26u; return 0; }
r[3]=read(ram,0x0c0a7ac4u,4);
goto P_0c0a7a28;
P_0c0a7a28: /* original 903c, guest PC 0x0c0a7a28 */
if(!s->budget--) { s->failed_pc=0x0c0a7a28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aa4u,2);
goto P_0c0a7a2a;
P_0c0a7a2a: /* original dd27, guest PC 0x0c0a7a2a */
if(!s->budget--) { s->failed_pc=0x0c0a7a2au; return 0; }
r[13]=read(ram,0x0c0a7ac8u,4);
goto P_0c0a7a2c;
P_0c0a7a2c: /* original 2e3b, guest PC 0x0c0a7a2c */
if(!s->budget--) { s->failed_pc=0x0c0a7a2cu; return 0; }
r[14]|=r[3];
goto P_0c0a7a2e;
P_0c0a7a2e: /* original ff5c, guest PC 0x0c0a7a2e */
if(!s->budget--) { s->failed_pc=0x0c0a7a2eu; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c0a7a30;
P_0c0a7a30: /* original 0de6, guest PC 0x0c0a7a30 */
if(!s->budget--) { s->failed_pc=0x0c0a7a30u; return 0; }
write(ram,r[13]+r[0],r[14],4);
goto P_0c0a7a32;
P_0c0a7a32: /* original d226, guest PC 0x0c0a7a32 */
if(!s->budget--) { s->failed_pc=0x0c0a7a32u; return 0; }
r[2]=read(ram,0x0c0a7accu,4);
goto P_0c0a7a34;
P_0c0a7a34: /* original 420b, guest PC 0x0c0a7a34 */
if(!s->budget--) { s->failed_pc=0x0c0a7a34u; return 0; }
target=r[2];
r[16]=0x0c0a7a38u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7a38u) { target=s->pc; goto dispatch; }
goto P_0c0a7a38;
P_0c0a7a36: /* original 64e3, guest PC 0x0c0a7a36 */
if(!s->budget--) { s->failed_pc=0x0c0a7a36u; return 0; }
r[4]=r[14];
goto P_0c0a7a38;
P_0c0a7a38: /* original d325, guest PC 0x0c0a7a38 */
if(!s->budget--) { s->failed_pc=0x0c0a7a38u; return 0; }
r[3]=read(ram,0x0c0a7ad0u,4);
goto P_0c0a7a3a;
P_0c0a7a3a: /* original 65e3, guest PC 0x0c0a7a3a */
if(!s->budget--) { s->failed_pc=0x0c0a7a3au; return 0; }
r[5]=r[14];
goto P_0c0a7a3c;
P_0c0a7a3c: /* original 66e3, guest PC 0x0c0a7a3c */
if(!s->budget--) { s->failed_pc=0x0c0a7a3cu; return 0; }
r[6]=r[14];
goto P_0c0a7a3e;
P_0c0a7a3e: /* original 430b, guest PC 0x0c0a7a3e */
if(!s->budget--) { s->failed_pc=0x0c0a7a3eu; return 0; }
target=r[3];
r[16]=0x0c0a7a42u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7a42u) { target=s->pc; goto dispatch; }
goto P_0c0a7a42;
P_0c0a7a40: /* original 64e3, guest PC 0x0c0a7a40 */
if(!s->budget--) { s->failed_pc=0x0c0a7a40u; return 0; }
r[4]=r[14];
goto P_0c0a7a42;
P_0c0a7a42: /* original f2f8, guest PC 0x0c0a7a42 */
if(!s->budget--) { s->failed_pc=0x0c0a7a42u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0a7a44;
P_0c0a7a44: /* original e500, guest PC 0x0c0a7a44 */
if(!s->budget--) { s->failed_pc=0x0c0a7a44u; return 0; }
r[5]=0x00000000u;
goto P_0c0a7a46;
P_0c0a7a46: /* original f38d, guest PC 0x0c0a7a46 */
if(!s->budget--) { s->failed_pc=0x0c0a7a46u; return 0; }
fr[3]=0;
goto P_0c0a7a48;
P_0c0a7a48: /* original e100, guest PC 0x0c0a7a48 */
if(!s->budget--) { s->failed_pc=0x0c0a7a48u; return 0; }
r[1]=0x00000000u;
goto P_0c0a7a4a;
P_0c0a7a4a: /* original f235, guest PC 0x0c0a7a4a */
if(!s->budget--) { s->failed_pc=0x0c0a7a4au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0a7a4c;
P_0c0a7a4c: /* original 9e2b, guest PC 0x0c0a7a4c */
if(!s->budget--) { s->failed_pc=0x0c0a7a4cu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aa6u,2);
goto P_0c0a7a4e;
P_0c0a7a4e: /* original 942b, guest PC 0x0c0a7a4e */
if(!s->budget--) { s->failed_pc=0x0c0a7a4eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aa8u,2);
goto P_0c0a7a50;
P_0c0a7a50: /* original 3edc, guest PC 0x0c0a7a50 */
if(!s->budget--) { s->failed_pc=0x0c0a7a50u; return 0; }
r[14]+=r[13];
goto P_0c0a7a52;
P_0c0a7a52: /* original f68d, guest PC 0x0c0a7a52 */
if(!s->budget--) { s->failed_pc=0x0c0a7a52u; return 0; }
fr[6]=0;
goto P_0c0a7a54;
P_0c0a7a54: /* original 8d0c, guest PC 0x0c0a7a54 */
if(!s->budget--) { s->failed_pc=0x0c0a7a54u; return 0; }
cond=r[17]&1u;
r[1]+=r[14];
if(cond) { goto P_0c0a7a70; }
goto P_0c0a7a58;
P_0c0a7a56: /* original 31ec, guest PC 0x0c0a7a56 */
if(!s->budget--) { s->failed_pc=0x0c0a7a56u; return 0; }
r[1]+=r[14];
goto P_0c0a7a58;
P_0c0a7a58: /* original 6653, guest PC 0x0c0a7a58 */
if(!s->budget--) { s->failed_pc=0x0c0a7a58u; return 0; }
r[6]=r[5];
goto P_0c0a7a5a;
P_0c0a7a5a: /* original 6513, guest PC 0x0c0a7a5a */
if(!s->budget--) { s->failed_pc=0x0c0a7a5au; return 0; }
r[5]=r[1];
goto P_0c0a7a5c;
P_0c0a7a5c: /* original 7601, guest PC 0x0c0a7a5c */
if(!s->budget--) { s->failed_pc=0x0c0a7a5cu; return 0; }
r[6]+=0x00000001u;
goto P_0c0a7a5e;
P_0c0a7a5e: /* original f56a, guest PC 0x0c0a7a5e */
if(!s->budget--) { s->failed_pc=0x0c0a7a5eu; return 0; }
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c0a7a60;
P_0c0a7a60: /* original 3647, guest PC 0x0c0a7a60 */
if(!s->budget--) { s->failed_pc=0x0c0a7a60u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[4])!=0);
goto P_0c0a7a62;
P_0c0a7a62: /* original 8ffb, guest PC 0x0c0a7a62 */
if(!s->budget--) { s->failed_pc=0x0c0a7a62u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(!cond) { goto P_0c0a7a5c; }
goto P_0c0a7a66;
P_0c0a7a64: /* original 7504, guest PC 0x0c0a7a64 */
if(!s->budget--) { s->failed_pc=0x0c0a7a64u; return 0; }
r[5]+=0x00000004u;
goto P_0c0a7a66;
P_0c0a7a66: /* original c71b, guest PC 0x0c0a7a66 */
if(!s->budget--) { s->failed_pc=0x0c0a7a66u; return 0; }
r[0]=0x0c0a7ad4u;
goto P_0c0a7a68;
P_0c0a7a68: /* original f308, guest PC 0x0c0a7a68 */
if(!s->budget--) { s->failed_pc=0x0c0a7a68u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a7a6a;
P_0c0a7a6a: /* original 901e, guest PC 0x0c0a7a6a */
if(!s->budget--) { s->failed_pc=0x0c0a7a6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aaau,2);
goto P_0c0a7a6c;
P_0c0a7a6c: /* original a049, guest PC 0x0c0a7a6c */
if(!s->budget--) { s->failed_pc=0x0c0a7a6cu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0a7b02;
P_0c0a7a6e: /* original fd37, guest PC 0x0c0a7a6e */
if(!s->budget--) { s->failed_pc=0x0c0a7a6eu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0a7a70;
P_0c0a7a70: /* original c719, guest PC 0x0c0a7a70 */
if(!s->budget--) { s->failed_pc=0x0c0a7a70u; return 0; }
r[0]=0x0c0a7ad8u;
goto P_0c0a7a72;
P_0c0a7a72: /* original f59d, guest PC 0x0c0a7a72 */
if(!s->budget--) { s->failed_pc=0x0c0a7a72u; return 0; }
fr[5]=0x3f800000u;
goto P_0c0a7a74;
P_0c0a7a74: /* original f308, guest PC 0x0c0a7a74 */
if(!s->budget--) { s->failed_pc=0x0c0a7a74u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a7a76;
P_0c0a7a76: /* original 6753, guest PC 0x0c0a7a76 */
if(!s->budget--) { s->failed_pc=0x0c0a7a76u; return 0; }
r[7]=r[5];
goto P_0c0a7a78;
P_0c0a7a78: /* original f75c, guest PC 0x0c0a7a78 */
if(!s->budget--) { s->failed_pc=0x0c0a7a78u; return 0; }
vf3_matrix_move(s,7,5);
goto P_0c0a7a7a;
P_0c0a7a7a: /* original f7f1, guest PC 0x0c0a7a7a */
if(!s->budget--) { s->failed_pc=0x0c0a7a7au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[15],r[18],'-');
goto P_0c0a7a7c;
P_0c0a7a7c: /* original f232, guest PC 0x0c0a7a7c */
if(!s->budget--) { s->failed_pc=0x0c0a7a7cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0a7a7e;
P_0c0a7a7e: /* original 9014, guest PC 0x0c0a7a7e */
if(!s->budget--) { s->failed_pc=0x0c0a7a7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aaau,2);
goto P_0c0a7a80;
P_0c0a7a80: /* original 6543, guest PC 0x0c0a7a80 */
if(!s->budget--) { s->failed_pc=0x0c0a7a80u; return 0; }
r[5]=r[4];
goto P_0c0a7a82;
P_0c0a7a82: /* original 6613, guest PC 0x0c0a7a82 */
if(!s->budget--) { s->failed_pc=0x0c0a7a82u; return 0; }
r[6]=r[1];
goto P_0c0a7a84;
P_0c0a7a84: /* original f47c, guest PC 0x0c0a7a84 */
if(!s->budget--) { s->failed_pc=0x0c0a7a84u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0a7a86;
P_0c0a7a86: /* original f423, guest PC 0x0c0a7a86 */
if(!s->budget--) { s->failed_pc=0x0c0a7a86u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'/');
goto P_0c0a7a88;
P_0c0a7a88: /* original fd47, guest PC 0x0c0a7a88 */
if(!s->budget--) { s->failed_pc=0x0c0a7a88u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0a7a8a;
P_0c0a7a8a: /* original c714, guest PC 0x0c0a7a8a */
if(!s->budget--) { s->failed_pc=0x0c0a7a8au; return 0; }
r[0]=0x0c0a7adcu;
goto P_0c0a7a8c;
P_0c0a7a8c: /* original f808, guest PC 0x0c0a7a8c */
if(!s->budget--) { s->failed_pc=0x0c0a7a8cu; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c0a7a8e;
P_0c0a7a8e: /* original 455a, guest PC 0x0c0a7a8e */
if(!s->budget--) { s->failed_pc=0x0c0a7a8eu; return 0; }
r[53]=r[5];
goto P_0c0a7a90;
P_0c0a7a90: /* original f28d, guest PC 0x0c0a7a90 */
if(!s->budget--) { s->failed_pc=0x0c0a7a90u; return 0; }
fr[2]=0;
goto P_0c0a7a92;
P_0c0a7a92: /* original f32d, guest PC 0x0c0a7a92 */
if(!s->budget--) { s->failed_pc=0x0c0a7a92u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0a7a94;
P_0c0a7a94: /* original f372, guest PC 0x0c0a7a94 */
if(!s->budget--) { s->failed_pc=0x0c0a7a94u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c0a7a96;
P_0c0a7a96: /* original f383, guest PC 0x0c0a7a96 */
if(!s->budget--) { s->failed_pc=0x0c0a7a96u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'/');
goto P_0c0a7a98;
P_0c0a7a98: /* original f43c, guest PC 0x0c0a7a98 */
if(!s->budget--) { s->failed_pc=0x0c0a7a98u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0a7a9a;
P_0c0a7a9a: /* original f4f0, guest PC 0x0c0a7a9a */
if(!s->budget--) { s->failed_pc=0x0c0a7a9au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'+');
goto P_0c0a7a9c;
P_0c0a7a9c: /* original f245, guest PC 0x0c0a7a9c */
if(!s->budget--) { s->failed_pc=0x0c0a7a9cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c0a7a9e;
P_0c0a7a9e: /* original 8b1f, guest PC 0x0c0a7a9e */
if(!s->budget--) { s->failed_pc=0x0c0a7a9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7ae0; }
goto P_0c0a7aa0;
P_0c0a7aa0: /* original a021, guest PC 0x0c0a7aa0 */
if(!s->budget--) { s->failed_pc=0x0c0a7aa0u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0a7ae6;
P_0c0a7aa2: /* original f46c, guest PC 0x0c0a7aa2 */
if(!s->budget--) { s->failed_pc=0x0c0a7aa2u; return 0; }
vf3_matrix_move(s,4,6);
return vf3_matrix_family(0x0c0a7aa4u,s,ram);
P_0c0a7ae0: /* original f455, guest PC 0x0c0a7ae0 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0a7ae2;
P_0c0a7ae2: /* original 8b00, guest PC 0x0c0a7ae2 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7ae6; }
goto P_0c0a7ae4;
P_0c0a7ae4: /* original f45c, guest PC 0x0c0a7ae4 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae4u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0a7ae6;
P_0c0a7ae6: /* original 7701, guest PC 0x0c0a7ae6 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae6u; return 0; }
r[7]+=0x00000001u;
goto P_0c0a7ae8;
P_0c0a7ae8: /* original f64a, guest PC 0x0c0a7ae8 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae8u; return 0; }
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c0a7aea;
P_0c0a7aea: /* original 3743, guest PC 0x0c0a7aea */
if(!s->budget--) { s->failed_pc=0x0c0a7aeau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[4])!=0);
goto P_0c0a7aec;
P_0c0a7aec: /* original 7604, guest PC 0x0c0a7aec */
if(!s->budget--) { s->failed_pc=0x0c0a7aecu; return 0; }
r[6]+=0x00000004u;
goto P_0c0a7aee;
P_0c0a7aee: /* original 8fce, guest PC 0x0c0a7aee */
if(!s->budget--) { s->failed_pc=0x0c0a7aeeu; return 0; }
cond=r[17]&1u;
r[5]+=0xffffffffu;
if(!cond) { goto P_0c0a7a8e; }
goto P_0c0a7af2;
P_0c0a7af0: /* original 75ff, guest PC 0x0c0a7af0 */
if(!s->budget--) { s->failed_pc=0x0c0a7af0u; return 0; }
r[5]+=0xffffffffu;
goto P_0c0a7af2;
P_0c0a7af2: /* original f28d, guest PC 0x0c0a7af2 */
if(!s->budget--) { s->failed_pc=0x0c0a7af2u; return 0; }
fr[2]=0;
goto P_0c0a7af4;
P_0c0a7af4: /* original f2f5, guest PC 0x0c0a7af4 */
if(!s->budget--) { s->failed_pc=0x0c0a7af4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[15]))!=0);
goto P_0c0a7af6;
P_0c0a7af6: /* original 8b01, guest PC 0x0c0a7af6 */
if(!s->budget--) { s->failed_pc=0x0c0a7af6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7afc; }
goto P_0c0a7af8;
P_0c0a7af8: /* original a001, guest PC 0x0c0a7af8 */
if(!s->budget--) { s->failed_pc=0x0c0a7af8u; return 0; }
fr[3]=0;
goto P_0c0a7afe;
P_0c0a7afa: /* original f38d, guest PC 0x0c0a7afa */
if(!s->budget--) { s->failed_pc=0x0c0a7afau; return 0; }
fr[3]=0;
goto P_0c0a7afc;
P_0c0a7afc: /* original f3fc, guest PC 0x0c0a7afc */
if(!s->budget--) { s->failed_pc=0x0c0a7afcu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0a7afe;
P_0c0a7afe: /* original 9042, guest PC 0x0c0a7afe */
if(!s->budget--) { s->failed_pc=0x0c0a7afeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7b86u,2);
goto P_0c0a7b00;
P_0c0a7b00: /* original fe37, guest PC 0x0c0a7b00 */
if(!s->budget--) { s->failed_pc=0x0c0a7b00u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a7b02;
P_0c0a7b02: /* original 7f04, guest PC 0x0c0a7b02 */
if(!s->budget--) { s->failed_pc=0x0c0a7b02u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a7b04;
P_0c0a7b04: /* original 60d2, guest PC 0x0c0a7b04 */
if(!s->budget--) { s->failed_pc=0x0c0a7b04u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0a7b06;
P_0c0a7b06: /* original 4f26, guest PC 0x0c0a7b06 */
if(!s->budget--) { s->failed_pc=0x0c0a7b06u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7b08;
P_0c0a7b08: /* original cb01, guest PC 0x0c0a7b08 */
if(!s->budget--) { s->failed_pc=0x0c0a7b08u; return 0; }
r[0]|=1u;
goto P_0c0a7b0a;
P_0c0a7b0a: /* original 2d02, guest PC 0x0c0a7b0a */
if(!s->budget--) { s->failed_pc=0x0c0a7b0au; return 0; }
write(ram,r[13],r[0],4);
goto P_0c0a7b0c;
P_0c0a7b0c: /* original e500, guest PC 0x0c0a7b0c */
if(!s->budget--) { s->failed_pc=0x0c0a7b0cu; return 0; }
r[5]=0x00000000u;
goto P_0c0a7b0e;
P_0c0a7b0e: /* original fff9, guest PC 0x0c0a7b0e */
if(!s->budget--) { s->failed_pc=0x0c0a7b0eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a7b10;
P_0c0a7b10: /* original d320, guest PC 0x0c0a7b10 */
if(!s->budget--) { s->failed_pc=0x0c0a7b10u; return 0; }
r[3]=read(ram,0x0c0a7b94u,4);
goto P_0c0a7b12;
P_0c0a7b12: /* original 6df6, guest PC 0x0c0a7b12 */
if(!s->budget--) { s->failed_pc=0x0c0a7b12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a7b14;
P_0c0a7b14: /* original d41e, guest PC 0x0c0a7b14 */
if(!s->budget--) { s->failed_pc=0x0c0a7b14u; return 0; }
r[4]=read(ram,0x0c0a7b90u,4);
goto P_0c0a7b16;
P_0c0a7b16: /* original 432b, guest PC 0x0c0a7b16 */
if(!s->budget--) { s->failed_pc=0x0c0a7b16u; return 0; }
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
P_0c0a7b18: /* original 6ef6, guest PC 0x0c0a7b18 */
if(!s->budget--) { s->failed_pc=0x0c0a7b18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a7b1au,s,ram);
P_0c0a7f68: /* original 4f22, guest PC 0x0c0a7f68 */
if(!s->budget--) { s->failed_pc=0x0c0a7f68u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7f6a;
P_0c0a7f6a: /* original 6e43, guest PC 0x0c0a7f6a */
if(!s->budget--) { s->failed_pc=0x0c0a7f6au; return 0; }
r[14]=r[4];
goto P_0c0a7f6c;
P_0c0a7f6c: /* original 7ff4, guest PC 0x0c0a7f6c */
if(!s->budget--) { s->failed_pc=0x0c0a7f6cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a7f6e;
P_0c0a7f6e: /* original 1f52, guest PC 0x0c0a7f6e */
if(!s->budget--) { s->failed_pc=0x0c0a7f6eu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0a7f70;
P_0c0a7f70: /* original 9319, guest PC 0x0c0a7f70 */
if(!s->budget--) { s->failed_pc=0x0c0a7f70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7fa6u,2);
goto P_0c0a7f72;
P_0c0a7f72: /* original 3b33, guest PC 0x0c0a7f72 */
if(!s->budget--) { s->failed_pc=0x0c0a7f72u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[3])!=0);
goto P_0c0a7f74;
P_0c0a7f74: /* original 8f03, guest PC 0x0c0a7f74 */
if(!s->budget--) { s->failed_pc=0x0c0a7f74u; return 0; }
cond=r[17]&1u;
r[10]=r[14];
if(!cond) { goto P_0c0a7f7e; }
goto P_0c0a7f78;
P_0c0a7f76: /* original 6ae3, guest PC 0x0c0a7f76 */
if(!s->budget--) { s->failed_pc=0x0c0a7f76u; return 0; }
r[10]=r[14];
goto P_0c0a7f78;
P_0c0a7f78: /* original de0d, guest PC 0x0c0a7f78 */
if(!s->budget--) { s->failed_pc=0x0c0a7f78u; return 0; }
r[14]=read(ram,0x0c0a7fb0u,4);
goto P_0c0a7f7a;
P_0c0a7f7a: /* original a056, guest PC 0x0c0a7f7a */
if(!s->budget--) { s->failed_pc=0x0c0a7f7au; return 0; }
goto P_0c0a802a;
P_0c0a7f7c: /* original 0009, guest PC 0x0c0a7f7c */
if(!s->budget--) { s->failed_pc=0x0c0a7f7cu; return 0; }
goto P_0c0a7f7e;
P_0c0a7f7e: /* original d00d, guest PC 0x0c0a7f7e */
if(!s->budget--) { s->failed_pc=0x0c0a7f7eu; return 0; }
r[0]=read(ram,0x0c0a7fb4u,4);
goto P_0c0a7f80;
P_0c0a7f80: /* original 63b3, guest PC 0x0c0a7f80 */
if(!s->budget--) { s->failed_pc=0x0c0a7f80u; return 0; }
r[3]=r[11];
goto P_0c0a7f82;
P_0c0a7f82: /* original 4308, guest PC 0x0c0a7f82 */
if(!s->budget--) { s->failed_pc=0x0c0a7f82u; return 0; }
r[3]<<=2;
goto P_0c0a7f84;
P_0c0a7f84: /* original 023e, guest PC 0x0c0a7f84 */
if(!s->budget--) { s->failed_pc=0x0c0a7f84u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0a7f86;
P_0c0a7f86: /* original 1f21, guest PC 0x0c0a7f86 */
if(!s->budget--) { s->failed_pc=0x0c0a7f86u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a7f88;
P_0c0a7f88: /* original d30b, guest PC 0x0c0a7f88 */
if(!s->budget--) { s->failed_pc=0x0c0a7f88u; return 0; }
r[3]=read(ram,0x0c0a7fb8u,4);
goto P_0c0a7f8a;
P_0c0a7f8a: /* original e500, guest PC 0x0c0a7f8a */
if(!s->budget--) { s->failed_pc=0x0c0a7f8au; return 0; }
r[5]=0x00000000u;
goto P_0c0a7f8c;
P_0c0a7f8c: /* original 430b, guest PC 0x0c0a7f8c */
if(!s->budget--) { s->failed_pc=0x0c0a7f8cu; return 0; }
target=r[3];
r[16]=0x0c0a7f90u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7f90u) { target=s->pc; goto dispatch; }
goto P_0c0a7f90;
P_0c0a7f8e: /* original 54f1, guest PC 0x0c0a7f8e */
if(!s->budget--) { s->failed_pc=0x0c0a7f8eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0a7f90;
P_0c0a7f90: /* original dc0a, guest PC 0x0c0a7f90 */
if(!s->budget--) { s->failed_pc=0x0c0a7f90u; return 0; }
r[12]=read(ram,0x0c0a7fbcu,4);
goto P_0c0a7f92;
P_0c0a7f92: /* original 6d03, guest PC 0x0c0a7f92 */
if(!s->budget--) { s->failed_pc=0x0c0a7f92u; return 0; }
r[13]=r[0];
goto P_0c0a7f94;
P_0c0a7f94: /* original 2dd8, guest PC 0x0c0a7f94 */
if(!s->budget--) { s->failed_pc=0x0c0a7f94u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0a7f96;
P_0c0a7f96: /* original 8b13, guest PC 0x0c0a7f96 */
if(!s->budget--) { s->failed_pc=0x0c0a7f96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7fc0; }
goto P_0c0a7f98;
P_0c0a7f98: /* original 64b3, guest PC 0x0c0a7f98 */
if(!s->budget--) { s->failed_pc=0x0c0a7f98u; return 0; }
r[4]=r[11];
goto P_0c0a7f9a;
P_0c0a7f9a: /* original d306, guest PC 0x0c0a7f9a */
if(!s->budget--) { s->failed_pc=0x0c0a7f9au; return 0; }
r[3]=read(ram,0x0c0a7fb4u,4);
goto P_0c0a7f9c;
P_0c0a7f9c: /* original eeff, guest PC 0x0c0a7f9c */
if(!s->budget--) { s->failed_pc=0x0c0a7f9cu; return 0; }
r[14]=0xffffffffu;
goto P_0c0a7f9e;
P_0c0a7f9e: /* original 4408, guest PC 0x0c0a7f9e */
if(!s->budget--) { s->failed_pc=0x0c0a7f9eu; return 0; }
r[4]<<=2;
goto P_0c0a7fa0;
P_0c0a7fa0: /* original e570, guest PC 0x0c0a7fa0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa0u; return 0; }
r[5]=0x00000070u;
goto P_0c0a7fa2;
P_0c0a7fa2: /* original a016, guest PC 0x0c0a7fa2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa2u; return 0; }
r[4]+=r[3];
goto P_0c0a7fd2;
P_0c0a7fa4: /* original 343c, guest PC 0x0c0a7fa4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa4u; return 0; }
r[4]+=r[3];
return vf3_matrix_family(0x0c0a7fa6u,s,ram);
P_0c0a7fc0: /* original d234, guest PC 0x0c0a7fc0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc0u; return 0; }
r[2]=read(ram,0x0c0a8094u,4);
goto P_0c0a7fc2;
P_0c0a7fc2: /* original 65f3, guest PC 0x0c0a7fc2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc2u; return 0; }
r[5]=r[15];
goto P_0c0a7fc4;
P_0c0a7fc4: /* original 420b, guest PC 0x0c0a7fc4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc4u; return 0; }
target=r[2];
r[16]=0x0c0a7fc8u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7fc8u) { target=s->pc; goto dispatch; }
goto P_0c0a7fc8;
P_0c0a7fc6: /* original 64d3, guest PC 0x0c0a7fc6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc6u; return 0; }
r[4]=r[13];
goto P_0c0a7fc8;
P_0c0a7fc8: /* original 63f2, guest PC 0x0c0a7fc8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a7fca;
P_0c0a7fca: /* original 2338, guest PC 0x0c0a7fca */
if(!s->budget--) { s->failed_pc=0x0c0a7fcau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a7fcc;
P_0c0a7fcc: /* original 8b05, guest PC 0x0c0a7fcc */
if(!s->budget--) { s->failed_pc=0x0c0a7fccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7fda; }
goto P_0c0a7fce;
P_0c0a7fce: /* original e400, guest PC 0x0c0a7fce */
if(!s->budget--) { s->failed_pc=0x0c0a7fceu; return 0; }
r[4]=0x00000000u;
goto P_0c0a7fd0;
P_0c0a7fd0: /* original e571, guest PC 0x0c0a7fd0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd0u; return 0; }
r[5]=0x00000071u;
goto P_0c0a7fd2;
P_0c0a7fd2: /* original 4c0b, guest PC 0x0c0a7fd2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd2u; return 0; }
target=r[12];
r[16]=0x0c0a7fd6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7fd6u) { target=s->pc; goto dispatch; }
goto P_0c0a7fd6;
P_0c0a7fd4: /* original 0009, guest PC 0x0c0a7fd4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd4u; return 0; }
goto P_0c0a7fd6;
P_0c0a7fd6: /* original a028, guest PC 0x0c0a7fd6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd6u; return 0; }
goto P_0c0a802a;
P_0c0a7fd8: /* original 0009, guest PC 0x0c0a7fd8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd8u; return 0; }
goto P_0c0a7fda;
P_0c0a7fda: /* original 62f2, guest PC 0x0c0a7fda */
if(!s->budget--) { s->failed_pc=0x0c0a7fdau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a7fdc;
P_0c0a7fdc: /* original 9356, guest PC 0x0c0a7fdc */
if(!s->budget--) { s->failed_pc=0x0c0a7fdcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a808cu,2);
goto P_0c0a7fde;
P_0c0a7fde: /* original 9156, guest PC 0x0c0a7fde */
if(!s->budget--) { s->failed_pc=0x0c0a7fdeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a808eu,2);
goto P_0c0a7fe0;
P_0c0a7fe0: /* original 323c, guest PC 0x0c0a7fe0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe0u; return 0; }
r[2]+=r[3];
goto P_0c0a7fe2;
P_0c0a7fe2: /* original 2219, guest PC 0x0c0a7fe2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe2u; return 0; }
r[2]&=r[1];
goto P_0c0a7fe4;
P_0c0a7fe4: /* original 6523, guest PC 0x0c0a7fe4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe4u; return 0; }
r[5]=r[2];
goto P_0c0a7fe6;
P_0c0a7fe6: /* original 4519, guest PC 0x0c0a7fe6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe6u; return 0; }
r[5]>>=8;
goto P_0c0a7fe8;
P_0c0a7fe8: /* original 4509, guest PC 0x0c0a7fe8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe8u; return 0; }
r[5]>>=2;
goto P_0c0a7fea;
P_0c0a7fea: /* original 2f22, guest PC 0x0c0a7fea */
if(!s->budget--) { s->failed_pc=0x0c0a7feau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a7fec;
P_0c0a7fec: /* original 56f2, guest PC 0x0c0a7fec */
if(!s->budget--) { s->failed_pc=0x0c0a7fecu; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c0a7fee;
P_0c0a7fee: /* original 4501, guest PC 0x0c0a7fee */
if(!s->budget--) { s->failed_pc=0x0c0a7feeu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c0a7ff0;
P_0c0a7ff0: /* original d329, guest PC 0x0c0a7ff0 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff0u; return 0; }
r[3]=read(ram,0x0c0a8098u,4);
goto P_0c0a7ff2;
P_0c0a7ff2: /* original 430b, guest PC 0x0c0a7ff2 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff2u; return 0; }
target=r[3];
r[16]=0x0c0a7ff6u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7ff6u) { target=s->pc; goto dispatch; }
goto P_0c0a7ff6;
P_0c0a7ff4: /* original 64d3, guest PC 0x0c0a7ff4 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff4u; return 0; }
r[4]=r[13];
goto P_0c0a7ff6;
P_0c0a7ff6: /* original 6403, guest PC 0x0c0a7ff6 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff6u; return 0; }
r[4]=r[0];
goto P_0c0a7ff8;
P_0c0a7ff8: /* original 4415, guest PC 0x0c0a7ff8 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0a7ffa;
P_0c0a7ffa: /* original 8901, guest PC 0x0c0a7ffa */
if(!s->budget--) { s->failed_pc=0x0c0a7ffau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8000; }
goto P_0c0a7ffc;
P_0c0a7ffc: /* original 4c0b, guest PC 0x0c0a7ffc */
if(!s->budget--) { s->failed_pc=0x0c0a7ffcu; return 0; }
target=r[12];
r[16]=0x0c0a8000u;
r[5]=0x00000072u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8000u) { target=s->pc; goto dispatch; }
goto P_0c0a8000;
P_0c0a7ffe: /* original e572, guest PC 0x0c0a7ffe */
if(!s->budget--) { s->failed_pc=0x0c0a7ffeu; return 0; }
r[5]=0x00000072u;
goto P_0c0a8000;
P_0c0a8000: /* original d326, guest PC 0x0c0a8000 */
if(!s->budget--) { s->failed_pc=0x0c0a8000u; return 0; }
r[3]=read(ram,0x0c0a809cu,4);
goto P_0c0a8002;
P_0c0a8002: /* original 430b, guest PC 0x0c0a8002 */
if(!s->budget--) { s->failed_pc=0x0c0a8002u; return 0; }
target=r[3];
r[16]=0x0c0a8006u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8006u) { target=s->pc; goto dispatch; }
goto P_0c0a8006;
P_0c0a8004: /* original 64d3, guest PC 0x0c0a8004 */
if(!s->budget--) { s->failed_pc=0x0c0a8004u; return 0; }
r[4]=r[13];
goto P_0c0a8006;
P_0c0a8006: /* original 6e03, guest PC 0x0c0a8006 */
if(!s->budget--) { s->failed_pc=0x0c0a8006u; return 0; }
r[14]=r[0];
goto P_0c0a8008;
P_0c0a8008: /* original 2ee8, guest PC 0x0c0a8008 */
if(!s->budget--) { s->failed_pc=0x0c0a8008u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a800a;
P_0c0a800a: /* original 890b, guest PC 0x0c0a800a */
if(!s->budget--) { s->failed_pc=0x0c0a800au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8024; }
goto P_0c0a800c;
P_0c0a800c: /* original e30a, guest PC 0x0c0a800c */
if(!s->budget--) { s->failed_pc=0x0c0a800cu; return 0; }
r[3]=0x0000000au;
goto P_0c0a800e;
P_0c0a800e: /* original 3a33, guest PC 0x0c0a800e */
if(!s->budget--) { s->failed_pc=0x0c0a800eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c0a8010;
P_0c0a8010: /* original 8905, guest PC 0x0c0a8010 */
if(!s->budget--) { s->failed_pc=0x0c0a8010u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a801e; }
goto P_0c0a8012;
P_0c0a8012: /* original d123, guest PC 0x0c0a8012 */
if(!s->budget--) { s->failed_pc=0x0c0a8012u; return 0; }
r[1]=read(ram,0x0c0a80a0u,4);
goto P_0c0a8014;
P_0c0a8014: /* original 7a01, guest PC 0x0c0a8014 */
if(!s->budget--) { s->failed_pc=0x0c0a8014u; return 0; }
r[10]+=0x00000001u;
goto P_0c0a8016;
P_0c0a8016: /* original 410b, guest PC 0x0c0a8016 */
if(!s->budget--) { s->failed_pc=0x0c0a8016u; return 0; }
target=r[1];
r[16]=0x0c0a801au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a801au) { target=s->pc; goto dispatch; }
goto P_0c0a801a;
P_0c0a8018: /* original 64d3, guest PC 0x0c0a8018 */
if(!s->budget--) { s->failed_pc=0x0c0a8018u; return 0; }
r[4]=r[13];
goto P_0c0a801a;
P_0c0a801a: /* original afb5, guest PC 0x0c0a801a */
if(!s->budget--) { s->failed_pc=0x0c0a801au; return 0; }
goto P_0c0a7f88;
P_0c0a801c: /* original 0009, guest PC 0x0c0a801c */
if(!s->budget--) { s->failed_pc=0x0c0a801cu; return 0; }
goto P_0c0a801e;
P_0c0a801e: /* original e573, guest PC 0x0c0a801e */
if(!s->budget--) { s->failed_pc=0x0c0a801eu; return 0; }
r[5]=0x00000073u;
goto P_0c0a8020;
P_0c0a8020: /* original 4c0b, guest PC 0x0c0a8020 */
if(!s->budget--) { s->failed_pc=0x0c0a8020u; return 0; }
target=r[12];
r[16]=0x0c0a8024u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a8024u) { target=s->pc; goto dispatch; }
goto P_0c0a8024;
P_0c0a8022: /* original 64e3, guest PC 0x0c0a8022 */
if(!s->budget--) { s->failed_pc=0x0c0a8022u; return 0; }
r[4]=r[14];
goto P_0c0a8024;
P_0c0a8024: /* original d21e, guest PC 0x0c0a8024 */
if(!s->budget--) { s->failed_pc=0x0c0a8024u; return 0; }
r[2]=read(ram,0x0c0a80a0u,4);
goto P_0c0a8026;
P_0c0a8026: /* original 420b, guest PC 0x0c0a8026 */
if(!s->budget--) { s->failed_pc=0x0c0a8026u; return 0; }
target=r[2];
r[16]=0x0c0a802au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a802au) { target=s->pc; goto dispatch; }
goto P_0c0a802a;
P_0c0a8028: /* original 64d3, guest PC 0x0c0a8028 */
if(!s->budget--) { s->failed_pc=0x0c0a8028u; return 0; }
r[4]=r[13];
goto P_0c0a802a;
P_0c0a802a: /* original 7f0c, guest PC 0x0c0a802a */
if(!s->budget--) { s->failed_pc=0x0c0a802au; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a802c;
P_0c0a802c: /* original 60e3, guest PC 0x0c0a802c */
if(!s->budget--) { s->failed_pc=0x0c0a802cu; return 0; }
r[0]=r[14];
goto P_0c0a802e;
P_0c0a802e: /* original 4f26, guest PC 0x0c0a802e */
if(!s->budget--) { s->failed_pc=0x0c0a802eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8030;
P_0c0a8030: /* original 6af6, guest PC 0x0c0a8030 */
if(!s->budget--) { s->failed_pc=0x0c0a8030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8032;
P_0c0a8032: /* original 6bf6, guest PC 0x0c0a8032 */
if(!s->budget--) { s->failed_pc=0x0c0a8032u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8034;
P_0c0a8034: /* original 6cf6, guest PC 0x0c0a8034 */
if(!s->budget--) { s->failed_pc=0x0c0a8034u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8036;
P_0c0a8036: /* original 6df6, guest PC 0x0c0a8036 */
if(!s->budget--) { s->failed_pc=0x0c0a8036u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8038;
P_0c0a8038: /* original 000b, guest PC 0x0c0a8038 */
if(!s->budget--) { s->failed_pc=0x0c0a8038u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a803a: /* original 6ef6, guest PC 0x0c0a803a */
if(!s->budget--) { s->failed_pc=0x0c0a803au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a803cu,s,ram);
P_0c0aa638: /* original 4f22, guest PC 0x0c0aa638 */
if(!s->budget--) { s->failed_pc=0x0c0aa638u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aa63a;
P_0c0aa63a: /* original 7ffc, guest PC 0x0c0aa63a */
if(!s->budget--) { s->failed_pc=0x0c0aa63au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0aa63c;
P_0c0aa63c: /* original 2f52, guest PC 0x0c0aa63c */
if(!s->budget--) { s->failed_pc=0x0c0aa63cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0aa63e;
P_0c0aa63e: /* original 04ee, guest PC 0x0c0aa63e */
if(!s->budget--) { s->failed_pc=0x0c0aa63eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0aa640;
P_0c0aa640: /* original e048, guest PC 0x0c0aa640 */
if(!s->budget--) { s->failed_pc=0x0c0aa640u; return 0; }
r[0]=0x00000048u;
goto P_0c0aa642;
P_0c0aa642: /* original 06ee, guest PC 0x0c0aa642 */
if(!s->budget--) { s->failed_pc=0x0c0aa642u; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c0aa644;
P_0c0aa644: /* original d327, guest PC 0x0c0aa644 */
if(!s->budget--) { s->failed_pc=0x0c0aa644u; return 0; }
r[3]=read(ram,0x0c0aa6e4u,4);
goto P_0c0aa646;
P_0c0aa646: /* original 9743, guest PC 0x0c0aa646 */
if(!s->budget--) { s->failed_pc=0x0c0aa646u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa6d0u,2);
goto P_0c0aa648;
P_0c0aa648: /* original 2368, guest PC 0x0c0aa648 */
if(!s->budget--) { s->failed_pc=0x0c0aa648u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0aa64a;
P_0c0aa64a: /* original 8d35, guest PC 0x0c0aa64a */
if(!s->budget--) { s->failed_pc=0x0c0aa64au; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[14],4);
r[5]=tmp;
if(cond) { goto P_0c0aa6b8; }
goto P_0c0aa64e;
P_0c0aa64c: /* original 65e2, guest PC 0x0c0aa64c */
if(!s->budget--) { s->failed_pc=0x0c0aa64cu; return 0; }
tmp=read(ram,r[14],4);
r[5]=tmp;
goto P_0c0aa64e;
P_0c0aa64e: /* original d226, guest PC 0x0c0aa64e */
if(!s->budget--) { s->failed_pc=0x0c0aa64eu; return 0; }
r[2]=read(ram,0x0c0aa6e8u,4);
goto P_0c0aa650;
P_0c0aa650: /* original 2268, guest PC 0x0c0aa650 */
if(!s->budget--) { s->failed_pc=0x0c0aa650u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[6])==0)!=0);
goto P_0c0aa652;
P_0c0aa652: /* original 8b68, guest PC 0x0c0aa652 */
if(!s->budget--) { s->failed_pc=0x0c0aa652u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa726; }
goto P_0c0aa654;
P_0c0aa654: /* original 913d, guest PC 0x0c0aa654 */
if(!s->budget--) { s->failed_pc=0x0c0aa654u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa6d2u,2);
goto P_0c0aa656;
P_0c0aa656: /* original 2518, guest PC 0x0c0aa656 */
if(!s->budget--) { s->failed_pc=0x0c0aa656u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[1])==0)!=0);
goto P_0c0aa658;
P_0c0aa658: /* original 8b5d, guest PC 0x0c0aa658 */
if(!s->budget--) { s->failed_pc=0x0c0aa658u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa716; }
goto P_0c0aa65a;
P_0c0aa65a: /* original 8545, guest PC 0x0c0aa65a */
if(!s->budget--) { s->failed_pc=0x0c0aa65au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+10,2);
goto P_0c0aa65c;
P_0c0aa65c: /* original 650d, guest PC 0x0c0aa65c */
if(!s->budget--) { s->failed_pc=0x0c0aa65cu; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aa65e;
P_0c0aa65e: /* original e03c, guest PC 0x0c0aa65e */
if(!s->budget--) { s->failed_pc=0x0c0aa65eu; return 0; }
r[0]=0x0000003cu;
goto P_0c0aa660;
P_0c0aa660: /* original 03ed, guest PC 0x0c0aa660 */
if(!s->budget--) { s->failed_pc=0x0c0aa660u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aa662;
P_0c0aa662: /* original 633d, guest PC 0x0c0aa662 */
if(!s->budget--) { s->failed_pc=0x0c0aa662u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0aa664;
P_0c0aa664: /* original 3350, guest PC 0x0c0aa664 */
if(!s->budget--) { s->failed_pc=0x0c0aa664u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[5])!=0);
goto P_0c0aa666;
P_0c0aa666: /* original 8950, guest PC 0x0c0aa666 */
if(!s->budget--) { s->failed_pc=0x0c0aa666u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa70a; }
goto P_0c0aa668;
P_0c0aa668: /* original 9034, guest PC 0x0c0aa668 */
if(!s->budget--) { s->failed_pc=0x0c0aa668u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa6d4u,2);
goto P_0c0aa66a;
P_0c0aa66a: /* original 03ed, guest PC 0x0c0aa66a */
if(!s->budget--) { s->failed_pc=0x0c0aa66au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aa66c;
P_0c0aa66c: /* original 633d, guest PC 0x0c0aa66c */
if(!s->budget--) { s->failed_pc=0x0c0aa66cu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0aa66e;
P_0c0aa66e: /* original 2378, guest PC 0x0c0aa66e */
if(!s->budget--) { s->failed_pc=0x0c0aa66eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c0aa670;
P_0c0aa670: /* original 8b0d, guest PC 0x0c0aa670 */
if(!s->budget--) { s->failed_pc=0x0c0aa670u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa68e; }
goto P_0c0aa672;
P_0c0aa672: /* original 8545, guest PC 0x0c0aa672 */
if(!s->budget--) { s->failed_pc=0x0c0aa672u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+10,2);
goto P_0c0aa674;
P_0c0aa674: /* original d31d, guest PC 0x0c0aa674 */
if(!s->budget--) { s->failed_pc=0x0c0aa674u; return 0; }
r[3]=read(ram,0x0c0aa6ecu,4);
goto P_0c0aa676;
P_0c0aa676: /* original 650d, guest PC 0x0c0aa676 */
if(!s->budget--) { s->failed_pc=0x0c0aa676u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aa678;
P_0c0aa678: /* original 902d, guest PC 0x0c0aa678 */
if(!s->budget--) { s->failed_pc=0x0c0aa678u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa6d6u,2);
goto P_0c0aa67a;
P_0c0aa67a: /* original 02ee, guest PC 0x0c0aa67a */
if(!s->budget--) { s->failed_pc=0x0c0aa67au; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0aa67c;
P_0c0aa67c: /* original 2238, guest PC 0x0c0aa67c */
if(!s->budget--) { s->failed_pc=0x0c0aa67cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aa67e;
P_0c0aa67e: /* original 8901, guest PC 0x0c0aa67e */
if(!s->budget--) { s->failed_pc=0x0c0aa67eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa684; }
goto P_0c0aa680;
P_0c0aa680: /* original 8541, guest PC 0x0c0aa680 */
if(!s->budget--) { s->failed_pc=0x0c0aa680u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c0aa682;
P_0c0aa682: /* original 650d, guest PC 0x0c0aa682 */
if(!s->budget--) { s->failed_pc=0x0c0aa682u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aa684;
P_0c0aa684: /* original d31a, guest PC 0x0c0aa684 */
if(!s->budget--) { s->failed_pc=0x0c0aa684u; return 0; }
r[3]=read(ram,0x0c0aa6f0u,4);
goto P_0c0aa686;
P_0c0aa686: /* original 430b, guest PC 0x0c0aa686 */
if(!s->budget--) { s->failed_pc=0x0c0aa686u; return 0; }
target=r[3];
r[16]=0x0c0aa68au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aa68au) { target=s->pc; goto dispatch; }
goto P_0c0aa68a;
P_0c0aa688: /* original 64e3, guest PC 0x0c0aa688 */
if(!s->budget--) { s->failed_pc=0x0c0aa688u; return 0; }
r[4]=r[14];
goto P_0c0aa68a;
P_0c0aa68a: /* original a03e, guest PC 0x0c0aa68a */
if(!s->budget--) { s->failed_pc=0x0c0aa68au; return 0; }
goto P_0c0aa70a;
P_0c0aa68c: /* original 0009, guest PC 0x0c0aa68c */
if(!s->budget--) { s->failed_pc=0x0c0aa68cu; return 0; }
goto P_0c0aa68e;
P_0c0aa68e: /* original 9022, guest PC 0x0c0aa68e */
if(!s->budget--) { s->failed_pc=0x0c0aa68eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa6d6u,2);
goto P_0c0aa690;
P_0c0aa690: /* original d318, guest PC 0x0c0aa690 */
if(!s->budget--) { s->failed_pc=0x0c0aa690u; return 0; }
r[3]=read(ram,0x0c0aa6f4u,4);
goto P_0c0aa692;
P_0c0aa692: /* original 02ee, guest PC 0x0c0aa692 */
if(!s->budget--) { s->failed_pc=0x0c0aa692u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0aa694;
P_0c0aa694: /* original 2238, guest PC 0x0c0aa694 */
if(!s->budget--) { s->failed_pc=0x0c0aa694u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aa696;
P_0c0aa696: /* original 8b04, guest PC 0x0c0aa696 */
if(!s->budget--) { s->failed_pc=0x0c0aa696u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa6a2; }
goto P_0c0aa698;
P_0c0aa698: /* original d117, guest PC 0x0c0aa698 */
if(!s->budget--) { s->failed_pc=0x0c0aa698u; return 0; }
r[1]=read(ram,0x0c0aa6f8u,4);
goto P_0c0aa69a;
P_0c0aa69a: /* original 2618, guest PC 0x0c0aa69a */
if(!s->budget--) { s->failed_pc=0x0c0aa69au; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[1])==0)!=0);
goto P_0c0aa69c;
P_0c0aa69c: /* original 8b43, guest PC 0x0c0aa69c */
if(!s->budget--) { s->failed_pc=0x0c0aa69cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa726; }
goto P_0c0aa69e;
P_0c0aa69e: /* original a03a, guest PC 0x0c0aa69e */
if(!s->budget--) { s->failed_pc=0x0c0aa69eu; return 0; }
goto P_0c0aa716;
P_0c0aa6a0: /* original 0009, guest PC 0x0c0aa6a0 */
if(!s->budget--) { s->failed_pc=0x0c0aa6a0u; return 0; }
goto P_0c0aa6a2;
P_0c0aa6a2: /* original d316, guest PC 0x0c0aa6a2 */
if(!s->budget--) { s->failed_pc=0x0c0aa6a2u; return 0; }
r[3]=read(ram,0x0c0aa6fcu,4);
goto P_0c0aa6a4;
P_0c0aa6a4: /* original 854f, guest PC 0x0c0aa6a4 */
if(!s->budget--) { s->failed_pc=0x0c0aa6a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c0aa6a6;
P_0c0aa6a6: /* original 2638, guest PC 0x0c0aa6a6 */
if(!s->budget--) { s->failed_pc=0x0c0aa6a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0aa6a8;
P_0c0aa6a8: /* original 8d37, guest PC 0x0c0aa6a8 */
if(!s->budget--) { s->failed_pc=0x0c0aa6a8u; return 0; }
cond=r[17]&1u;
r[5]=r[0]&65535u;
if(cond) { goto P_0c0aa71a; }
goto P_0c0aa6ac;
P_0c0aa6aa: /* original 650d, guest PC 0x0c0aa6aa */
if(!s->budget--) { s->failed_pc=0x0c0aa6aau; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aa6ac;
P_0c0aa6ac: /* original 7f04, guest PC 0x0c0aa6ac */
if(!s->budget--) { s->failed_pc=0x0c0aa6acu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aa6ae;
P_0c0aa6ae: /* original d314, guest PC 0x0c0aa6ae */
if(!s->budget--) { s->failed_pc=0x0c0aa6aeu; return 0; }
r[3]=read(ram,0x0c0aa700u,4);
goto P_0c0aa6b0;
P_0c0aa6b0: /* original 4f26, guest PC 0x0c0aa6b0 */
if(!s->budget--) { s->failed_pc=0x0c0aa6b0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aa6b2;
P_0c0aa6b2: /* original 64e3, guest PC 0x0c0aa6b2 */
if(!s->budget--) { s->failed_pc=0x0c0aa6b2u; return 0; }
r[4]=r[14];
goto P_0c0aa6b4;
P_0c0aa6b4: /* original 432b, guest PC 0x0c0aa6b4 */
if(!s->budget--) { s->failed_pc=0x0c0aa6b4u; return 0; }
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
P_0c0aa6b6: /* original 6ef6, guest PC 0x0c0aa6b6 */
if(!s->budget--) { s->failed_pc=0x0c0aa6b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa6b8;
P_0c0aa6b8: /* original 8545, guest PC 0x0c0aa6b8 */
if(!s->budget--) { s->failed_pc=0x0c0aa6b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+10,2);
goto P_0c0aa6ba;
P_0c0aa6ba: /* original 650d, guest PC 0x0c0aa6ba */
if(!s->budget--) { s->failed_pc=0x0c0aa6bau; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aa6bc;
P_0c0aa6bc: /* original 900a, guest PC 0x0c0aa6bc */
if(!s->budget--) { s->failed_pc=0x0c0aa6bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa6d4u,2);
goto P_0c0aa6be;
P_0c0aa6be: /* original 04ed, guest PC 0x0c0aa6be */
if(!s->budget--) { s->failed_pc=0x0c0aa6beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aa6c0;
P_0c0aa6c0: /* original 644d, guest PC 0x0c0aa6c0 */
if(!s->budget--) { s->failed_pc=0x0c0aa6c0u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0aa6c2;
P_0c0aa6c2: /* original 2478, guest PC 0x0c0aa6c2 */
if(!s->budget--) { s->failed_pc=0x0c0aa6c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[7])==0)!=0);
goto P_0c0aa6c4;
P_0c0aa6c4: /* original 891e, guest PC 0x0c0aa6c4 */
if(!s->budget--) { s->failed_pc=0x0c0aa6c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa704; }
goto P_0c0aa6c6;
P_0c0aa6c6: /* original d20e, guest PC 0x0c0aa6c6 */
if(!s->budget--) { s->failed_pc=0x0c0aa6c6u; return 0; }
r[2]=read(ram,0x0c0aa700u,4);
goto P_0c0aa6c8;
P_0c0aa6c8: /* original 420b, guest PC 0x0c0aa6c8 */
if(!s->budget--) { s->failed_pc=0x0c0aa6c8u; return 0; }
target=r[2];
r[16]=0x0c0aa6ccu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aa6ccu) { target=s->pc; goto dispatch; }
goto P_0c0aa6cc;
P_0c0aa6ca: /* original 64e3, guest PC 0x0c0aa6ca */
if(!s->budget--) { s->failed_pc=0x0c0aa6cau; return 0; }
r[4]=r[14];
goto P_0c0aa6cc;
P_0c0aa6cc: /* original a01d, guest PC 0x0c0aa6cc */
if(!s->budget--) { s->failed_pc=0x0c0aa6ccu; return 0; }
goto P_0c0aa70a;
P_0c0aa6ce: /* original 0009, guest PC 0x0c0aa6ce */
if(!s->budget--) { s->failed_pc=0x0c0aa6ceu; return 0; }
return vf3_matrix_family(0x0c0aa6d0u,s,ram);
P_0c0aa704: /* original d246, guest PC 0x0c0aa704 */
if(!s->budget--) { s->failed_pc=0x0c0aa704u; return 0; }
r[2]=read(ram,0x0c0aa820u,4);
goto P_0c0aa706;
P_0c0aa706: /* original 420b, guest PC 0x0c0aa706 */
if(!s->budget--) { s->failed_pc=0x0c0aa706u; return 0; }
target=r[2];
r[16]=0x0c0aa70au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aa70au) { target=s->pc; goto dispatch; }
goto P_0c0aa70a;
P_0c0aa708: /* original 64e3, guest PC 0x0c0aa708 */
if(!s->budget--) { s->failed_pc=0x0c0aa708u; return 0; }
r[4]=r[14];
goto P_0c0aa70a;
P_0c0aa70a: /* original 65f2, guest PC 0x0c0aa70a */
if(!s->budget--) { s->failed_pc=0x0c0aa70au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0aa70c;
P_0c0aa70c: /* original 7f04, guest PC 0x0c0aa70c */
if(!s->budget--) { s->failed_pc=0x0c0aa70cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aa70e;
P_0c0aa70e: /* original 4f26, guest PC 0x0c0aa70e */
if(!s->budget--) { s->failed_pc=0x0c0aa70eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aa710;
P_0c0aa710: /* original 64e3, guest PC 0x0c0aa710 */
if(!s->budget--) { s->failed_pc=0x0c0aa710u; return 0; }
r[4]=r[14];
goto P_0c0aa712;
P_0c0aa712: /* original a046, guest PC 0x0c0aa712 */
if(!s->budget--) { s->failed_pc=0x0c0aa712u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa7a2;
P_0c0aa714: /* original 6ef6, guest PC 0x0c0aa714 */
if(!s->budget--) { s->failed_pc=0x0c0aa714u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa716;
P_0c0aa716: /* original 8541, guest PC 0x0c0aa716 */
if(!s->budget--) { s->failed_pc=0x0c0aa716u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c0aa718;
P_0c0aa718: /* original 650d, guest PC 0x0c0aa718 */
if(!s->budget--) { s->failed_pc=0x0c0aa718u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aa71a;
P_0c0aa71a: /* original 7f04, guest PC 0x0c0aa71a */
if(!s->budget--) { s->failed_pc=0x0c0aa71au; return 0; }
r[15]+=0x00000004u;
goto P_0c0aa71c;
P_0c0aa71c: /* original d340, guest PC 0x0c0aa71c */
if(!s->budget--) { s->failed_pc=0x0c0aa71cu; return 0; }
r[3]=read(ram,0x0c0aa820u,4);
goto P_0c0aa71e;
P_0c0aa71e: /* original 4f26, guest PC 0x0c0aa71e */
if(!s->budget--) { s->failed_pc=0x0c0aa71eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aa720;
P_0c0aa720: /* original 64e3, guest PC 0x0c0aa720 */
if(!s->budget--) { s->failed_pc=0x0c0aa720u; return 0; }
r[4]=r[14];
goto P_0c0aa722;
P_0c0aa722: /* original 432b, guest PC 0x0c0aa722 */
if(!s->budget--) { s->failed_pc=0x0c0aa722u; return 0; }
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
P_0c0aa724: /* original 6ef6, guest PC 0x0c0aa724 */
if(!s->budget--) { s->failed_pc=0x0c0aa724u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa726;
P_0c0aa726: /* original 7f04, guest PC 0x0c0aa726 */
if(!s->budget--) { s->failed_pc=0x0c0aa726u; return 0; }
r[15]+=0x00000004u;
goto P_0c0aa728;
P_0c0aa728: /* original 4f26, guest PC 0x0c0aa728 */
if(!s->budget--) { s->failed_pc=0x0c0aa728u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aa72a;
P_0c0aa72a: /* original 000b, guest PC 0x0c0aa72a */
if(!s->budget--) { s->failed_pc=0x0c0aa72au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0aa72c: /* original 6ef6, guest PC 0x0c0aa72c */
if(!s->budget--) { s->failed_pc=0x0c0aa72cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0aa72eu,s,ram);
P_0c0aa7a2: /* original e048, guest PC 0x0c0aa7a2 */
if(!s->budget--) { s->failed_pc=0x0c0aa7a2u; return 0; }
r[0]=0x00000048u;
goto P_0c0aa7a4;
P_0c0aa7a4: /* original d324, guest PC 0x0c0aa7a4 */
if(!s->budget--) { s->failed_pc=0x0c0aa7a4u; return 0; }
r[3]=read(ram,0x0c0aa838u,4);
goto P_0c0aa7a6;
P_0c0aa7a6: /* original 025e, guest PC 0x0c0aa7a6 */
if(!s->budget--) { s->failed_pc=0x0c0aa7a6u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c0aa7a8;
P_0c0aa7a8: /* original 4f22, guest PC 0x0c0aa7a8 */
if(!s->budget--) { s->failed_pc=0x0c0aa7a8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aa7aa;
P_0c0aa7aa: /* original 2238, guest PC 0x0c0aa7aa */
if(!s->budget--) { s->failed_pc=0x0c0aa7aau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aa7ac;
P_0c0aa7ac: /* original 891b, guest PC 0x0c0aa7ac */
if(!s->budget--) { s->failed_pc=0x0c0aa7acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa7e6; }
goto P_0c0aa7ae;
P_0c0aa7ae: /* original 9034, guest PC 0x0c0aa7ae */
if(!s->budget--) { s->failed_pc=0x0c0aa7aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa81au,2);
goto P_0c0aa7b0;
P_0c0aa7b0: /* original 065d, guest PC 0x0c0aa7b0 */
if(!s->budget--) { s->failed_pc=0x0c0aa7b0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aa7b2;
P_0c0aa7b2: /* original e03e, guest PC 0x0c0aa7b2 */
if(!s->budget--) { s->failed_pc=0x0c0aa7b2u; return 0; }
r[0]=0x0000003eu;
goto P_0c0aa7b4;
P_0c0aa7b4: /* original 035d, guest PC 0x0c0aa7b4 */
if(!s->budget--) { s->failed_pc=0x0c0aa7b4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aa7b6;
P_0c0aa7b6: /* original 8444, guest PC 0x0c0aa7b6 */
if(!s->budget--) { s->failed_pc=0x0c0aa7b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+4,1);
goto P_0c0aa7b8;
P_0c0aa7b8: /* original 666d, guest PC 0x0c0aa7b8 */
if(!s->budget--) { s->failed_pc=0x0c0aa7b8u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0aa7ba;
P_0c0aa7ba: /* original 633d, guest PC 0x0c0aa7ba */
if(!s->budget--) { s->failed_pc=0x0c0aa7bau; return 0; }
r[3]=r[3]&65535u;
goto P_0c0aa7bc;
P_0c0aa7bc: /* original 600c, guest PC 0x0c0aa7bc */
if(!s->budget--) { s->failed_pc=0x0c0aa7bcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0aa7be;
P_0c0aa7be: /* original 3638, guest PC 0x0c0aa7be */
if(!s->budget--) { s->failed_pc=0x0c0aa7beu; return 0; }
r[6]-=r[3];
goto P_0c0aa7c0;
P_0c0aa7c0: /* original 360c, guest PC 0x0c0aa7c0 */
if(!s->budget--) { s->failed_pc=0x0c0aa7c0u; return 0; }
r[6]+=r[0];
goto P_0c0aa7c2;
P_0c0aa7c2: /* original 902b, guest PC 0x0c0aa7c2 */
if(!s->budget--) { s->failed_pc=0x0c0aa7c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa81cu,2);
goto P_0c0aa7c4;
P_0c0aa7c4: /* original e301, guest PC 0x0c0aa7c4 */
if(!s->budget--) { s->failed_pc=0x0c0aa7c4u; return 0; }
r[3]=0x00000001u;
goto P_0c0aa7c6;
P_0c0aa7c6: /* original 054d, guest PC 0x0c0aa7c6 */
if(!s->budget--) { s->failed_pc=0x0c0aa7c6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0aa7c8;
P_0c0aa7c8: /* original 3637, guest PC 0x0c0aa7c8 */
if(!s->budget--) { s->failed_pc=0x0c0aa7c8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[3])!=0);
goto P_0c0aa7ca;
P_0c0aa7ca: /* original 8f0a, guest PC 0x0c0aa7ca */
if(!s->budget--) { s->failed_pc=0x0c0aa7cau; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(!cond) { goto P_0c0aa7e2; }
goto P_0c0aa7ce;
P_0c0aa7cc: /* original 655d, guest PC 0x0c0aa7cc */
if(!s->budget--) { s->failed_pc=0x0c0aa7ccu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0aa7ce;
P_0c0aa7ce: /* original e03e, guest PC 0x0c0aa7ce */
if(!s->budget--) { s->failed_pc=0x0c0aa7ceu; return 0; }
r[0]=0x0000003eu;
goto P_0c0aa7d0;
P_0c0aa7d0: /* original d31a, guest PC 0x0c0aa7d0 */
if(!s->budget--) { s->failed_pc=0x0c0aa7d0u; return 0; }
r[3]=read(ram,0x0c0aa83cu,4);
goto P_0c0aa7d2;
P_0c0aa7d2: /* original 074d, guest PC 0x0c0aa7d2 */
if(!s->budget--) { s->failed_pc=0x0c0aa7d2u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0aa7d4;
P_0c0aa7d4: /* original 677d, guest PC 0x0c0aa7d4 */
if(!s->budget--) { s->failed_pc=0x0c0aa7d4u; return 0; }
r[7]=r[7]&65535u;
goto P_0c0aa7d6;
P_0c0aa7d6: /* original 3578, guest PC 0x0c0aa7d6 */
if(!s->budget--) { s->failed_pc=0x0c0aa7d6u; return 0; }
r[5]-=r[7];
goto P_0c0aa7d8;
P_0c0aa7d8: /* original 6153, guest PC 0x0c0aa7d8 */
if(!s->budget--) { s->failed_pc=0x0c0aa7d8u; return 0; }
r[1]=r[5];
goto P_0c0aa7da;
P_0c0aa7da: /* original 430b, guest PC 0x0c0aa7da */
if(!s->budget--) { s->failed_pc=0x0c0aa7dau; return 0; }
target=r[3];
r[16]=0x0c0aa7deu;
r[0]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aa7deu) { target=s->pc; goto dispatch; }
goto P_0c0aa7de;
P_0c0aa7dc: /* original 6063, guest PC 0x0c0aa7dc */
if(!s->budget--) { s->failed_pc=0x0c0aa7dcu; return 0; }
r[0]=r[6];
goto P_0c0aa7de;
P_0c0aa7de: /* original 6503, guest PC 0x0c0aa7de */
if(!s->budget--) { s->failed_pc=0x0c0aa7deu; return 0; }
r[5]=r[0];
goto P_0c0aa7e0;
P_0c0aa7e0: /* original 357c, guest PC 0x0c0aa7e0 */
if(!s->budget--) { s->failed_pc=0x0c0aa7e0u; return 0; }
r[5]+=r[7];
goto P_0c0aa7e2;
P_0c0aa7e2: /* original e03e, guest PC 0x0c0aa7e2 */
if(!s->budget--) { s->failed_pc=0x0c0aa7e2u; return 0; }
r[0]=0x0000003eu;
goto P_0c0aa7e4;
P_0c0aa7e4: /* original 0455, guest PC 0x0c0aa7e4 */
if(!s->budget--) { s->failed_pc=0x0c0aa7e4u; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c0aa7e6;
P_0c0aa7e6: /* original 4f26, guest PC 0x0c0aa7e6 */
if(!s->budget--) { s->failed_pc=0x0c0aa7e6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aa7e8;
P_0c0aa7e8: /* original 000b, guest PC 0x0c0aa7e8 */
if(!s->budget--) { s->failed_pc=0x0c0aa7e8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0aa7ea: /* original 0009, guest PC 0x0c0aa7ea */
if(!s->budget--) { s->failed_pc=0x0c0aa7eau; return 0; }
return vf3_matrix_family(0x0c0aa7ecu,s,ram);
P_0c0aa9f0: /* original 4f22, guest PC 0x0c0aa9f0 */
if(!s->budget--) { s->failed_pc=0x0c0aa9f0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aa9f2;
P_0c0aa9f2: /* original 7ffc, guest PC 0x0c0aa9f2 */
if(!s->budget--) { s->failed_pc=0x0c0aa9f2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0aa9f4;
P_0c0aa9f4: /* original 2f52, guest PC 0x0c0aa9f4 */
if(!s->budget--) { s->failed_pc=0x0c0aa9f4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0aa9f6;
P_0c0aa9f6: /* original 04ee, guest PC 0x0c0aa9f6 */
if(!s->budget--) { s->failed_pc=0x0c0aa9f6u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0aa9f8;
P_0c0aa9f8: /* original e048, guest PC 0x0c0aa9f8 */
if(!s->budget--) { s->failed_pc=0x0c0aa9f8u; return 0; }
r[0]=0x00000048u;
goto P_0c0aa9fa;
P_0c0aa9fa: /* original 06ee, guest PC 0x0c0aa9fa */
if(!s->budget--) { s->failed_pc=0x0c0aa9fau; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c0aa9fc;
P_0c0aa9fc: /* original d30d, guest PC 0x0c0aa9fc */
if(!s->budget--) { s->failed_pc=0x0c0aa9fcu; return 0; }
r[3]=read(ram,0x0c0aaa34u,4);
goto P_0c0aa9fe;
P_0c0aa9fe: /* original 2368, guest PC 0x0c0aa9fe */
if(!s->budget--) { s->failed_pc=0x0c0aa9feu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0aaa00;
P_0c0aaa00: /* original 8d1e, guest PC 0x0c0aaa00 */
if(!s->budget--) { s->failed_pc=0x0c0aaa00u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[14],4);
r[7]=tmp;
if(cond) { goto P_0c0aaa40; }
goto P_0c0aaa04;
P_0c0aaa02: /* original 67e2, guest PC 0x0c0aaa02 */
if(!s->budget--) { s->failed_pc=0x0c0aaa02u; return 0; }
tmp=read(ram,r[14],4);
r[7]=tmp;
goto P_0c0aaa04;
P_0c0aaa04: /* original d305, guest PC 0x0c0aaa04 */
if(!s->budget--) { s->failed_pc=0x0c0aaa04u; return 0; }
r[3]=read(ram,0x0c0aaa1cu,4);
goto P_0c0aaa06;
P_0c0aaa06: /* original d50c, guest PC 0x0c0aaa06 */
if(!s->budget--) { s->failed_pc=0x0c0aaa06u; return 0; }
r[5]=read(ram,0x0c0aaa38u,4);
goto P_0c0aaa08;
P_0c0aaa08: /* original 2368, guest PC 0x0c0aaa08 */
if(!s->budget--) { s->failed_pc=0x0c0aaa08u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0aaa0a;
P_0c0aaa0a: /* original 8d36, guest PC 0x0c0aaa0a */
if(!s->budget--) { s->failed_pc=0x0c0aaa0au; return 0; }
cond=r[17]&1u;
r[5]&=r[7];
if(cond) { goto P_0c0aaa7a; }
goto P_0c0aaa0e;
P_0c0aaa0c: /* original 2579, guest PC 0x0c0aaa0c */
if(!s->budget--) { s->failed_pc=0x0c0aaa0cu; return 0; }
r[5]&=r[7];
goto P_0c0aaa0e;
P_0c0aaa0e: /* original d10b, guest PC 0x0c0aaa0e */
if(!s->budget--) { s->failed_pc=0x0c0aaa0eu; return 0; }
r[1]=read(ram,0x0c0aaa3cu,4);
goto P_0c0aaa10;
P_0c0aaa10: /* original 2168, guest PC 0x0c0aaa10 */
if(!s->budget--) { s->failed_pc=0x0c0aaa10u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[6])==0)!=0);
goto P_0c0aaa12;
P_0c0aaa12: /* original 894a, guest PC 0x0c0aaa12 */
if(!s->budget--) { s->failed_pc=0x0c0aaa12u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aaaaa; }
goto P_0c0aaa14;
P_0c0aaa14: /* original a031, guest PC 0x0c0aaa14 */
if(!s->budget--) { s->failed_pc=0x0c0aaa14u; return 0; }
goto P_0c0aaa7a;
P_0c0aaa16: /* original 0009, guest PC 0x0c0aaa16 */
if(!s->budget--) { s->failed_pc=0x0c0aaa16u; return 0; }
return vf3_matrix_family(0x0c0aaa18u,s,ram);
P_0c0aaa40: /* original 8546, guest PC 0x0c0aaa40 */
if(!s->budget--) { s->failed_pc=0x0c0aaa40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+12,2);
goto P_0c0aaa42;
P_0c0aaa42: /* original 650d, guest PC 0x0c0aaa42 */
if(!s->budget--) { s->failed_pc=0x0c0aaa42u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aaa44;
P_0c0aaa44: /* original e061, guest PC 0x0c0aaa44 */
if(!s->budget--) { s->failed_pc=0x0c0aaa44u; return 0; }
r[0]=0x00000061u;
goto P_0c0aaa46;
P_0c0aaa46: /* original 00ec, guest PC 0x0c0aaa46 */
if(!s->budget--) { s->failed_pc=0x0c0aaa46u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0aaa48;
P_0c0aaa48: /* original 600c, guest PC 0x0c0aaa48 */
if(!s->budget--) { s->failed_pc=0x0c0aaa48u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aaa4a;
P_0c0aaa4a: /* original 8801, guest PC 0x0c0aaa4a */
if(!s->budget--) { s->failed_pc=0x0c0aaa4au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0aaa4c;
P_0c0aaa4c: /* original 8904, guest PC 0x0c0aaa4c */
if(!s->budget--) { s->failed_pc=0x0c0aaa4cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aaa58; }
goto P_0c0aaa4e;
P_0c0aaa4e: /* original d236, guest PC 0x0c0aaa4e */
if(!s->budget--) { s->failed_pc=0x0c0aaa4eu; return 0; }
r[2]=read(ram,0x0c0aab28u,4);
goto P_0c0aaa50;
P_0c0aaa50: /* original 2728, guest PC 0x0c0aaa50 */
if(!s->budget--) { s->failed_pc=0x0c0aaa50u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[2])==0)!=0);
goto P_0c0aaa52;
P_0c0aaa52: /* original 8901, guest PC 0x0c0aaa52 */
if(!s->budget--) { s->failed_pc=0x0c0aaa52u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aaa58; }
goto P_0c0aaa54;
P_0c0aaa54: /* original 854a, guest PC 0x0c0aaa54 */
if(!s->budget--) { s->failed_pc=0x0c0aaa54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+20,2);
goto P_0c0aaa56;
P_0c0aaa56: /* original 650d, guest PC 0x0c0aaa56 */
if(!s->budget--) { s->failed_pc=0x0c0aaa56u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aaa58;
P_0c0aaa58: /* original 9062, guest PC 0x0c0aaa58 */
if(!s->budget--) { s->failed_pc=0x0c0aaa58u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aab20u,2);
goto P_0c0aaa5a;
P_0c0aaa5a: /* original 00ed, guest PC 0x0c0aaa5a */
if(!s->budget--) { s->failed_pc=0x0c0aaa5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aaa5c;
P_0c0aaa5c: /* original 600d, guest PC 0x0c0aaa5c */
if(!s->budget--) { s->failed_pc=0x0c0aaa5cu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0aaa5e;
P_0c0aaa5e: /* original c880, guest PC 0x0c0aaa5e */
if(!s->budget--) { s->failed_pc=0x0c0aaa5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0aaa60;
P_0c0aaa60: /* original 8b04, guest PC 0x0c0aaa60 */
if(!s->budget--) { s->failed_pc=0x0c0aaa60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aaa6c; }
goto P_0c0aaa62;
P_0c0aaa62: /* original d332, guest PC 0x0c0aaa62 */
if(!s->budget--) { s->failed_pc=0x0c0aaa62u; return 0; }
r[3]=read(ram,0x0c0aab2cu,4);
goto P_0c0aaa64;
P_0c0aaa64: /* original 430b, guest PC 0x0c0aaa64 */
if(!s->budget--) { s->failed_pc=0x0c0aaa64u; return 0; }
target=r[3];
r[16]=0x0c0aaa68u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aaa68u) { target=s->pc; goto dispatch; }
goto P_0c0aaa68;
P_0c0aaa66: /* original 64e3, guest PC 0x0c0aaa66 */
if(!s->budget--) { s->failed_pc=0x0c0aaa66u; return 0; }
r[4]=r[14];
goto P_0c0aaa68;
P_0c0aaa68: /* original a026, guest PC 0x0c0aaa68 */
if(!s->budget--) { s->failed_pc=0x0c0aaa68u; return 0; }
goto P_0c0aaab8;
P_0c0aaa6a: /* original 0009, guest PC 0x0c0aaa6a */
if(!s->budget--) { s->failed_pc=0x0c0aaa6au; return 0; }
goto P_0c0aaa6c;
P_0c0aaa6c: /* original 8546, guest PC 0x0c0aaa6c */
if(!s->budget--) { s->failed_pc=0x0c0aaa6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+12,2);
goto P_0c0aaa6e;
P_0c0aaa6e: /* original d330, guest PC 0x0c0aaa6e */
if(!s->budget--) { s->failed_pc=0x0c0aaa6eu; return 0; }
r[3]=read(ram,0x0c0aab30u,4);
goto P_0c0aaa70;
P_0c0aaa70: /* original 650d, guest PC 0x0c0aaa70 */
if(!s->budget--) { s->failed_pc=0x0c0aaa70u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aaa72;
P_0c0aaa72: /* original 430b, guest PC 0x0c0aaa72 */
if(!s->budget--) { s->failed_pc=0x0c0aaa72u; return 0; }
target=r[3];
r[16]=0x0c0aaa76u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aaa76u) { target=s->pc; goto dispatch; }
goto P_0c0aaa76;
P_0c0aaa74: /* original 64e3, guest PC 0x0c0aaa74 */
if(!s->budget--) { s->failed_pc=0x0c0aaa74u; return 0; }
r[4]=r[14];
goto P_0c0aaa76;
P_0c0aaa76: /* original a01f, guest PC 0x0c0aaa76 */
if(!s->budget--) { s->failed_pc=0x0c0aaa76u; return 0; }
goto P_0c0aaab8;
P_0c0aaa78: /* original 0009, guest PC 0x0c0aaa78 */
if(!s->budget--) { s->failed_pc=0x0c0aaa78u; return 0; }
goto P_0c0aaa7a;
P_0c0aaa7a: /* original 2558, guest PC 0x0c0aaa7a */
if(!s->budget--) { s->failed_pc=0x0c0aaa7au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0aaa7c;
P_0c0aaa7c: /* original 8b04, guest PC 0x0c0aaa7c */
if(!s->budget--) { s->failed_pc=0x0c0aaa7cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aaa88; }
goto P_0c0aaa7e;
P_0c0aaa7e: /* original 904f, guest PC 0x0c0aaa7e */
if(!s->budget--) { s->failed_pc=0x0c0aaa7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aab20u,2);
goto P_0c0aaa80;
P_0c0aaa80: /* original 00ed, guest PC 0x0c0aaa80 */
if(!s->budget--) { s->failed_pc=0x0c0aaa80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aaa82;
P_0c0aaa82: /* original 600d, guest PC 0x0c0aaa82 */
if(!s->budget--) { s->failed_pc=0x0c0aaa82u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0aaa84;
P_0c0aaa84: /* original c880, guest PC 0x0c0aaa84 */
if(!s->budget--) { s->failed_pc=0x0c0aaa84u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0aaa86;
P_0c0aaa86: /* original 8904, guest PC 0x0c0aaa86 */
if(!s->budget--) { s->failed_pc=0x0c0aaa86u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aaa92; }
goto P_0c0aaa88;
P_0c0aaa88: /* original 6543, guest PC 0x0c0aaa88 */
if(!s->budget--) { s->failed_pc=0x0c0aaa88u; return 0; }
r[5]=r[4];
goto P_0c0aaa8a;
P_0c0aaa8a: /* original 7540, guest PC 0x0c0aaa8a */
if(!s->budget--) { s->failed_pc=0x0c0aaa8au; return 0; }
r[5]+=0x00000040u;
goto P_0c0aaa8c;
P_0c0aaa8c: /* original 6551, guest PC 0x0c0aaa8c */
if(!s->budget--) { s->failed_pc=0x0c0aaa8cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0aaa8e;
P_0c0aaa8e: /* original a024, guest PC 0x0c0aaa8e */
if(!s->budget--) { s->failed_pc=0x0c0aaa8eu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0aaada;
P_0c0aaa90: /* original 655d, guest PC 0x0c0aaa90 */
if(!s->budget--) { s->failed_pc=0x0c0aaa90u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0aaa92;
P_0c0aaa92: /* original 8546, guest PC 0x0c0aaa92 */
if(!s->budget--) { s->failed_pc=0x0c0aaa92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+12,2);
goto P_0c0aaa94;
P_0c0aaa94: /* original d327, guest PC 0x0c0aaa94 */
if(!s->budget--) { s->failed_pc=0x0c0aaa94u; return 0; }
r[3]=read(ram,0x0c0aab34u,4);
goto P_0c0aaa96;
P_0c0aaa96: /* original 650d, guest PC 0x0c0aaa96 */
if(!s->budget--) { s->failed_pc=0x0c0aaa96u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aaa98;
P_0c0aaa98: /* original 9043, guest PC 0x0c0aaa98 */
if(!s->budget--) { s->failed_pc=0x0c0aaa98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aab22u,2);
goto P_0c0aaa9a;
P_0c0aaa9a: /* original 02ee, guest PC 0x0c0aaa9a */
if(!s->budget--) { s->failed_pc=0x0c0aaa9au; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0aaa9c;
P_0c0aaa9c: /* original 2238, guest PC 0x0c0aaa9c */
if(!s->budget--) { s->failed_pc=0x0c0aaa9cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aaa9e;
P_0c0aaa9e: /* original 8bf3, guest PC 0x0c0aaa9e */
if(!s->budget--) { s->failed_pc=0x0c0aaa9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aaa88; }
goto P_0c0aaaa0;
P_0c0aaaa0: /* original d325, guest PC 0x0c0aaaa0 */
if(!s->budget--) { s->failed_pc=0x0c0aaaa0u; return 0; }
r[3]=read(ram,0x0c0aab38u,4);
goto P_0c0aaaa2;
P_0c0aaaa2: /* original 430b, guest PC 0x0c0aaaa2 */
if(!s->budget--) { s->failed_pc=0x0c0aaaa2u; return 0; }
target=r[3];
r[16]=0x0c0aaaa6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aaaa6u) { target=s->pc; goto dispatch; }
goto P_0c0aaaa6;
P_0c0aaaa4: /* original 64e3, guest PC 0x0c0aaaa4 */
if(!s->budget--) { s->failed_pc=0x0c0aaaa4u; return 0; }
r[4]=r[14];
goto P_0c0aaaa6;
P_0c0aaaa6: /* original a007, guest PC 0x0c0aaaa6 */
if(!s->budget--) { s->failed_pc=0x0c0aaaa6u; return 0; }
goto P_0c0aaab8;
P_0c0aaaa8: /* original 0009, guest PC 0x0c0aaaa8 */
if(!s->budget--) { s->failed_pc=0x0c0aaaa8u; return 0; }
goto P_0c0aaaaa;
P_0c0aaaaa: /* original 2558, guest PC 0x0c0aaaaa */
if(!s->budget--) { s->failed_pc=0x0c0aaaaau; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0aaaac;
P_0c0aaaac: /* original 8b0a, guest PC 0x0c0aaaac */
if(!s->budget--) { s->failed_pc=0x0c0aaaacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aaac4; }
goto P_0c0aaaae;
P_0c0aaaae: /* original 9037, guest PC 0x0c0aaaae */
if(!s->budget--) { s->failed_pc=0x0c0aaaaeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aab20u,2);
goto P_0c0aaab0;
P_0c0aaab0: /* original 00ed, guest PC 0x0c0aaab0 */
if(!s->budget--) { s->failed_pc=0x0c0aaab0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aaab2;
P_0c0aaab2: /* original 600d, guest PC 0x0c0aaab2 */
if(!s->budget--) { s->failed_pc=0x0c0aaab2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0aaab4;
P_0c0aaab4: /* original c880, guest PC 0x0c0aaab4 */
if(!s->budget--) { s->failed_pc=0x0c0aaab4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0aaab6;
P_0c0aaab6: /* original 8b16, guest PC 0x0c0aaab6 */
if(!s->budget--) { s->failed_pc=0x0c0aaab6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aaae6; }
goto P_0c0aaab8;
P_0c0aaab8: /* original 65f2, guest PC 0x0c0aaab8 */
if(!s->budget--) { s->failed_pc=0x0c0aaab8u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0aaaba;
P_0c0aaaba: /* original 7f04, guest PC 0x0c0aaaba */
if(!s->budget--) { s->failed_pc=0x0c0aaabau; return 0; }
r[15]+=0x00000004u;
goto P_0c0aaabc;
P_0c0aaabc: /* original 4f26, guest PC 0x0c0aaabc */
if(!s->budget--) { s->failed_pc=0x0c0aaabcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aaabe;
P_0c0aaabe: /* original 64e3, guest PC 0x0c0aaabe */
if(!s->budget--) { s->failed_pc=0x0c0aaabeu; return 0; }
r[4]=r[14];
goto P_0c0aaac0;
P_0c0aaac0: /* original ae6f, guest PC 0x0c0aaac0 */
if(!s->budget--) { s->failed_pc=0x0c0aaac0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa7a2;
P_0c0aaac2: /* original 6ef6, guest PC 0x0c0aaac2 */
if(!s->budget--) { s->failed_pc=0x0c0aaac2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aaac4;
P_0c0aaac4: /* original 6543, guest PC 0x0c0aaac4 */
if(!s->budget--) { s->failed_pc=0x0c0aaac4u; return 0; }
r[5]=r[4];
goto P_0c0aaac6;
P_0c0aaac6: /* original d31d, guest PC 0x0c0aaac6 */
if(!s->budget--) { s->failed_pc=0x0c0aaac6u; return 0; }
r[3]=read(ram,0x0c0aab3cu,4);
goto P_0c0aaac8;
P_0c0aaac8: /* original 7542, guest PC 0x0c0aaac8 */
if(!s->budget--) { s->failed_pc=0x0c0aaac8u; return 0; }
r[5]+=0x00000042u;
goto P_0c0aaaca;
P_0c0aaaca: /* original 6551, guest PC 0x0c0aaaca */
if(!s->budget--) { s->failed_pc=0x0c0aaacau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0aaacc;
P_0c0aaacc: /* original 2638, guest PC 0x0c0aaacc */
if(!s->budget--) { s->failed_pc=0x0c0aaaccu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0aaace;
P_0c0aaace: /* original 8d04, guest PC 0x0c0aaace */
if(!s->budget--) { s->failed_pc=0x0c0aaaceu; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(cond) { goto P_0c0aaada; }
goto P_0c0aaad2;
P_0c0aaad0: /* original 655d, guest PC 0x0c0aaad0 */
if(!s->budget--) { s->failed_pc=0x0c0aaad0u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0aaad2;
P_0c0aaad2: /* original 6543, guest PC 0x0c0aaad2 */
if(!s->budget--) { s->failed_pc=0x0c0aaad2u; return 0; }
r[5]=r[4];
goto P_0c0aaad4;
P_0c0aaad4: /* original 7540, guest PC 0x0c0aaad4 */
if(!s->budget--) { s->failed_pc=0x0c0aaad4u; return 0; }
r[5]+=0x00000040u;
goto P_0c0aaad6;
P_0c0aaad6: /* original 6551, guest PC 0x0c0aaad6 */
if(!s->budget--) { s->failed_pc=0x0c0aaad6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0aaad8;
P_0c0aaad8: /* original 655d, guest PC 0x0c0aaad8 */
if(!s->budget--) { s->failed_pc=0x0c0aaad8u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0aaada;
P_0c0aaada: /* original 7f04, guest PC 0x0c0aaada */
if(!s->budget--) { s->failed_pc=0x0c0aaadau; return 0; }
r[15]+=0x00000004u;
goto P_0c0aaadc;
P_0c0aaadc: /* original d313, guest PC 0x0c0aaadc */
if(!s->budget--) { s->failed_pc=0x0c0aaadcu; return 0; }
r[3]=read(ram,0x0c0aab2cu,4);
goto P_0c0aaade;
P_0c0aaade: /* original 4f26, guest PC 0x0c0aaade */
if(!s->budget--) { s->failed_pc=0x0c0aaadeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aaae0;
P_0c0aaae0: /* original 64e3, guest PC 0x0c0aaae0 */
if(!s->budget--) { s->failed_pc=0x0c0aaae0u; return 0; }
r[4]=r[14];
goto P_0c0aaae2;
P_0c0aaae2: /* original 432b, guest PC 0x0c0aaae2 */
if(!s->budget--) { s->failed_pc=0x0c0aaae2u; return 0; }
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
P_0c0aaae4: /* original 6ef6, guest PC 0x0c0aaae4 */
if(!s->budget--) { s->failed_pc=0x0c0aaae4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aaae6;
P_0c0aaae6: /* original 7f04, guest PC 0x0c0aaae6 */
if(!s->budget--) { s->failed_pc=0x0c0aaae6u; return 0; }
r[15]+=0x00000004u;
goto P_0c0aaae8;
P_0c0aaae8: /* original 4f26, guest PC 0x0c0aaae8 */
if(!s->budget--) { s->failed_pc=0x0c0aaae8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aaaea;
P_0c0aaaea: /* original 000b, guest PC 0x0c0aaaea */
if(!s->budget--) { s->failed_pc=0x0c0aaaeau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0aaaec: /* original 6ef6, guest PC 0x0c0aaaec */
if(!s->budget--) { s->failed_pc=0x0c0aaaecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0aaaeeu,s,ram);
P_0c0aadae: /* original 4f22, guest PC 0x0c0aadae */
if(!s->budget--) { s->failed_pc=0x0c0aadaeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aadb0;
P_0c0aadb0: /* original 03ee, guest PC 0x0c0aadb0 */
if(!s->budget--) { s->failed_pc=0x0c0aadb0u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0aadb2;
P_0c0aadb2: /* original 7ffc, guest PC 0x0c0aadb2 */
if(!s->budget--) { s->failed_pc=0x0c0aadb2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0aadb4;
P_0c0aadb4: /* original 2f32, guest PC 0x0c0aadb4 */
if(!s->budget--) { s->failed_pc=0x0c0aadb4u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0aadb6;
P_0c0aadb6: /* original 9044, guest PC 0x0c0aadb6 */
if(!s->budget--) { s->failed_pc=0x0c0aadb6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aae42u,2);
goto P_0c0aadb8;
P_0c0aadb8: /* original d327, guest PC 0x0c0aadb8 */
if(!s->budget--) { s->failed_pc=0x0c0aadb8u; return 0; }
r[3]=read(ram,0x0c0aae58u,4);
goto P_0c0aadba;
P_0c0aadba: /* original 025e, guest PC 0x0c0aadba */
if(!s->budget--) { s->failed_pc=0x0c0aadbau; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c0aadbc;
P_0c0aadbc: /* original 2238, guest PC 0x0c0aadbc */
if(!s->budget--) { s->failed_pc=0x0c0aadbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aadbe;
P_0c0aadbe: /* original 8d0b, guest PC 0x0c0aadbe */
if(!s->budget--) { s->failed_pc=0x0c0aadbeu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[14],4);
r[12]=tmp;
if(cond) { goto P_0c0aadd8; }
goto P_0c0aadc2;
P_0c0aadc0: /* original 6ce2, guest PC 0x0c0aadc0 */
if(!s->budget--) { s->failed_pc=0x0c0aadc0u; return 0; }
tmp=read(ram,r[14],4);
r[12]=tmp;
goto P_0c0aadc2;
P_0c0aadc2: /* original d226, guest PC 0x0c0aadc2 */
if(!s->budget--) { s->failed_pc=0x0c0aadc2u; return 0; }
r[2]=read(ram,0x0c0aae5cu,4);
goto P_0c0aadc4;
P_0c0aadc4: /* original 420b, guest PC 0x0c0aadc4 */
if(!s->budget--) { s->failed_pc=0x0c0aadc4u; return 0; }
target=r[2];
r[16]=0x0c0aadc8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aadc8u) { target=s->pc; goto dispatch; }
goto P_0c0aadc8;
P_0c0aadc6: /* original 64e3, guest PC 0x0c0aadc6 */
if(!s->budget--) { s->failed_pc=0x0c0aadc6u; return 0; }
r[4]=r[14];
goto P_0c0aadc8;
P_0c0aadc8: /* original 6403, guest PC 0x0c0aadc8 */
if(!s->budget--) { s->failed_pc=0x0c0aadc8u; return 0; }
r[4]=r[0];
goto P_0c0aadca;
P_0c0aadca: /* original e048, guest PC 0x0c0aadca */
if(!s->budget--) { s->failed_pc=0x0c0aadcau; return 0; }
r[0]=0x00000048u;
goto P_0c0aadcc;
P_0c0aadcc: /* original 02ee, guest PC 0x0c0aadcc */
if(!s->budget--) { s->failed_pc=0x0c0aadccu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0aadce;
P_0c0aadce: /* original 2448, guest PC 0x0c0aadce */
if(!s->budget--) { s->failed_pc=0x0c0aadceu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0aadd0;
P_0c0aadd0: /* original d323, guest PC 0x0c0aadd0 */
if(!s->budget--) { s->failed_pc=0x0c0aadd0u; return 0; }
r[3]=read(ram,0x0c0aae60u,4);
goto P_0c0aadd2;
P_0c0aadd2: /* original 2239, guest PC 0x0c0aadd2 */
if(!s->budget--) { s->failed_pc=0x0c0aadd2u; return 0; }
r[2]&=r[3];
goto P_0c0aadd4;
P_0c0aadd4: /* original 8f6b, guest PC 0x0c0aadd4 */
if(!s->budget--) { s->failed_pc=0x0c0aadd4u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[2],4);
if(!cond) { goto P_0c0aaeae; }
goto P_0c0aadd8;
P_0c0aadd6: /* original 0e26, guest PC 0x0c0aadd6 */
if(!s->budget--) { s->failed_pc=0x0c0aadd6u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0aadd8;
P_0c0aadd8: /* original 61f2, guest PC 0x0c0aadd8 */
if(!s->budget--) { s->failed_pc=0x0c0aadd8u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0aadda;
P_0c0aadda: /* original d322, guest PC 0x0c0aadda */
if(!s->budget--) { s->failed_pc=0x0c0aaddau; return 0; }
r[3]=read(ram,0x0c0aae64u,4);
goto P_0c0aaddc;
P_0c0aaddc: /* original 2138, guest PC 0x0c0aaddc */
if(!s->budget--) { s->failed_pc=0x0c0aaddcu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0aadde;
P_0c0aadde: /* original 8b49, guest PC 0x0c0aadde */
if(!s->budget--) { s->failed_pc=0x0c0aaddeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aae74; }
goto P_0c0aade0;
P_0c0aade0: /* original 9330, guest PC 0x0c0aade0 */
if(!s->budget--) { s->failed_pc=0x0c0aade0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aae44u,2);
goto P_0c0aade2;
P_0c0aade2: /* original 85dc, guest PC 0x0c0aade2 */
if(!s->budget--) { s->failed_pc=0x0c0aade2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+24,2);
goto P_0c0aade4;
P_0c0aade4: /* original 2c38, guest PC 0x0c0aade4 */
if(!s->budget--) { s->failed_pc=0x0c0aade4u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[3])==0)!=0);
goto P_0c0aade6;
P_0c0aade6: /* original 8f5a, guest PC 0x0c0aade6 */
if(!s->budget--) { s->failed_pc=0x0c0aade6u; return 0; }
cond=r[17]&1u;
r[5]=r[0]&65535u;
if(!cond) { goto P_0c0aae9e; }
goto P_0c0aadea;
P_0c0aade8: /* original 650d, guest PC 0x0c0aade8 */
if(!s->budget--) { s->failed_pc=0x0c0aade8u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aadea;
P_0c0aadea: /* original 64d3, guest PC 0x0c0aadea */
if(!s->budget--) { s->failed_pc=0x0c0aadeau; return 0; }
r[4]=r[13];
goto P_0c0aadec;
P_0c0aadec: /* original e03c, guest PC 0x0c0aadec */
if(!s->budget--) { s->failed_pc=0x0c0aadecu; return 0; }
r[0]=0x0000003cu;
goto P_0c0aadee;
P_0c0aadee: /* original 7420, guest PC 0x0c0aadee */
if(!s->budget--) { s->failed_pc=0x0c0aadeeu; return 0; }
r[4]+=0x00000020u;
goto P_0c0aadf0;
P_0c0aadf0: /* original 03ed, guest PC 0x0c0aadf0 */
if(!s->budget--) { s->failed_pc=0x0c0aadf0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aadf2;
P_0c0aadf2: /* original 6441, guest PC 0x0c0aadf2 */
if(!s->budget--) { s->failed_pc=0x0c0aadf2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]=tmp;
goto P_0c0aadf4;
P_0c0aadf4: /* original 633d, guest PC 0x0c0aadf4 */
if(!s->budget--) { s->failed_pc=0x0c0aadf4u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0aadf6;
P_0c0aadf6: /* original 644d, guest PC 0x0c0aadf6 */
if(!s->budget--) { s->failed_pc=0x0c0aadf6u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0aadf8;
P_0c0aadf8: /* original 3340, guest PC 0x0c0aadf8 */
if(!s->budget--) { s->failed_pc=0x0c0aadf8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[4])!=0);
goto P_0c0aadfa;
P_0c0aadfa: /* original 8958, guest PC 0x0c0aadfa */
if(!s->budget--) { s->failed_pc=0x0c0aadfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aaeae; }
goto P_0c0aadfc;
P_0c0aadfc: /* original 9023, guest PC 0x0c0aadfc */
if(!s->budget--) { s->failed_pc=0x0c0aadfcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aae46u,2);
goto P_0c0aadfe;
P_0c0aadfe: /* original 9323, guest PC 0x0c0aadfe */
if(!s->budget--) { s->failed_pc=0x0c0aadfeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aae48u,2);
goto P_0c0aae00;
P_0c0aae00: /* original 04ed, guest PC 0x0c0aae00 */
if(!s->budget--) { s->failed_pc=0x0c0aae00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aae02;
P_0c0aae02: /* original 644d, guest PC 0x0c0aae02 */
if(!s->budget--) { s->failed_pc=0x0c0aae02u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0aae04;
P_0c0aae04: /* original 2438, guest PC 0x0c0aae04 */
if(!s->budget--) { s->failed_pc=0x0c0aae04u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0aae06;
P_0c0aae06: /* original 8912, guest PC 0x0c0aae06 */
if(!s->budget--) { s->failed_pc=0x0c0aae06u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aae2e; }
goto P_0c0aae08;
P_0c0aae08: /* original 901f, guest PC 0x0c0aae08 */
if(!s->budget--) { s->failed_pc=0x0c0aae08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aae4au,2);
goto P_0c0aae0a;
P_0c0aae0a: /* original 65d3, guest PC 0x0c0aae0a */
if(!s->budget--) { s->failed_pc=0x0c0aae0au; return 0; }
r[5]=r[13];
goto P_0c0aae0c;
P_0c0aae0c: /* original d216, guest PC 0x0c0aae0c */
if(!s->budget--) { s->failed_pc=0x0c0aae0cu; return 0; }
r[2]=read(ram,0x0c0aae68u,4);
goto P_0c0aae0e;
P_0c0aae0e: /* original 7520, guest PC 0x0c0aae0e */
if(!s->budget--) { s->failed_pc=0x0c0aae0eu; return 0; }
r[5]+=0x00000020u;
goto P_0c0aae10;
P_0c0aae10: /* original 01ee, guest PC 0x0c0aae10 */
if(!s->budget--) { s->failed_pc=0x0c0aae10u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0aae12;
P_0c0aae12: /* original 6551, guest PC 0x0c0aae12 */
if(!s->budget--) { s->failed_pc=0x0c0aae12u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0aae14;
P_0c0aae14: /* original 2128, guest PC 0x0c0aae14 */
if(!s->budget--) { s->failed_pc=0x0c0aae14u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0aae16;
P_0c0aae16: /* original 8d02, guest PC 0x0c0aae16 */
if(!s->budget--) { s->failed_pc=0x0c0aae16u; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(cond) { goto P_0c0aae1e; }
goto P_0c0aae1a;
P_0c0aae18: /* original 655d, guest PC 0x0c0aae18 */
if(!s->budget--) { s->failed_pc=0x0c0aae18u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0aae1a;
P_0c0aae1a: /* original 85dc, guest PC 0x0c0aae1a */
if(!s->budget--) { s->failed_pc=0x0c0aae1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+24,2);
goto P_0c0aae1c;
P_0c0aae1c: /* original 650d, guest PC 0x0c0aae1c */
if(!s->budget--) { s->failed_pc=0x0c0aae1cu; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aae1e;
P_0c0aae1e: /* original 7f04, guest PC 0x0c0aae1e */
if(!s->budget--) { s->failed_pc=0x0c0aae1eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aae20;
P_0c0aae20: /* original d312, guest PC 0x0c0aae20 */
if(!s->budget--) { s->failed_pc=0x0c0aae20u; return 0; }
r[3]=read(ram,0x0c0aae6cu,4);
goto P_0c0aae22;
P_0c0aae22: /* original 4f26, guest PC 0x0c0aae22 */
if(!s->budget--) { s->failed_pc=0x0c0aae22u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aae24;
P_0c0aae24: /* original 64e3, guest PC 0x0c0aae24 */
if(!s->budget--) { s->failed_pc=0x0c0aae24u; return 0; }
r[4]=r[14];
goto P_0c0aae26;
P_0c0aae26: /* original 6cf6, guest PC 0x0c0aae26 */
if(!s->budget--) { s->failed_pc=0x0c0aae26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0aae28;
P_0c0aae28: /* original 6df6, guest PC 0x0c0aae28 */
if(!s->budget--) { s->failed_pc=0x0c0aae28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aae2a;
P_0c0aae2a: /* original 432b, guest PC 0x0c0aae2a */
if(!s->budget--) { s->failed_pc=0x0c0aae2au; return 0; }
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
P_0c0aae2c: /* original 6ef6, guest PC 0x0c0aae2c */
if(!s->budget--) { s->failed_pc=0x0c0aae2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aae2e;
P_0c0aae2e: /* original 900c, guest PC 0x0c0aae2e */
if(!s->budget--) { s->failed_pc=0x0c0aae2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aae4au,2);
goto P_0c0aae30;
P_0c0aae30: /* original d30f, guest PC 0x0c0aae30 */
if(!s->budget--) { s->failed_pc=0x0c0aae30u; return 0; }
r[3]=read(ram,0x0c0aae70u,4);
goto P_0c0aae32;
P_0c0aae32: /* original 02ee, guest PC 0x0c0aae32 */
if(!s->budget--) { s->failed_pc=0x0c0aae32u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0aae34;
P_0c0aae34: /* original 2238, guest PC 0x0c0aae34 */
if(!s->budget--) { s->failed_pc=0x0c0aae34u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aae36;
P_0c0aae36: /* original 8b3a, guest PC 0x0c0aae36 */
if(!s->budget--) { s->failed_pc=0x0c0aae36u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aaeae; }
goto P_0c0aae38;
P_0c0aae38: /* original a031, guest PC 0x0c0aae38 */
if(!s->budget--) { s->failed_pc=0x0c0aae38u; return 0; }
goto P_0c0aae9e;
P_0c0aae3a: /* original 0009, guest PC 0x0c0aae3a */
if(!s->budget--) { s->failed_pc=0x0c0aae3au; return 0; }
return vf3_matrix_family(0x0c0aae3cu,s,ram);
P_0c0aae74: /* original 65d3, guest PC 0x0c0aae74 */
if(!s->budget--) { s->failed_pc=0x0c0aae74u; return 0; }
r[5]=r[13];
goto P_0c0aae76;
P_0c0aae76: /* original 907c, guest PC 0x0c0aae76 */
if(!s->budget--) { s->failed_pc=0x0c0aae76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aaf72u,2);
goto P_0c0aae78;
P_0c0aae78: /* original 7520, guest PC 0x0c0aae78 */
if(!s->budget--) { s->failed_pc=0x0c0aae78u; return 0; }
r[5]+=0x00000020u;
goto P_0c0aae7a;
P_0c0aae7a: /* original d340, guest PC 0x0c0aae7a */
if(!s->budget--) { s->failed_pc=0x0c0aae7au; return 0; }
r[3]=read(ram,0x0c0aaf7cu,4);
goto P_0c0aae7c;
P_0c0aae7c: /* original 6551, guest PC 0x0c0aae7c */
if(!s->budget--) { s->failed_pc=0x0c0aae7cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0aae7e;
P_0c0aae7e: /* original 04ed, guest PC 0x0c0aae7e */
if(!s->budget--) { s->failed_pc=0x0c0aae7eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aae80;
P_0c0aae80: /* original 2c38, guest PC 0x0c0aae80 */
if(!s->budget--) { s->failed_pc=0x0c0aae80u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[3])==0)!=0);
goto P_0c0aae82;
P_0c0aae82: /* original 655d, guest PC 0x0c0aae82 */
if(!s->budget--) { s->failed_pc=0x0c0aae82u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0aae84;
P_0c0aae84: /* original 8f0b, guest PC 0x0c0aae84 */
if(!s->budget--) { s->failed_pc=0x0c0aae84u; return 0; }
cond=r[17]&1u;
r[4]=r[4]&65535u;
if(!cond) { goto P_0c0aae9e; }
goto P_0c0aae88;
P_0c0aae86: /* original 644d, guest PC 0x0c0aae86 */
if(!s->budget--) { s->failed_pc=0x0c0aae86u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0aae88;
P_0c0aae88: /* original 9174, guest PC 0x0c0aae88 */
if(!s->budget--) { s->failed_pc=0x0c0aae88u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aaf74u,2);
goto P_0c0aae8a;
P_0c0aae8a: /* original 2418, guest PC 0x0c0aae8a */
if(!s->budget--) { s->failed_pc=0x0c0aae8au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[1])==0)!=0);
goto P_0c0aae8c;
P_0c0aae8c: /* original 8b07, guest PC 0x0c0aae8c */
if(!s->budget--) { s->failed_pc=0x0c0aae8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aae9e; }
goto P_0c0aae8e;
P_0c0aae8e: /* original 7f04, guest PC 0x0c0aae8e */
if(!s->budget--) { s->failed_pc=0x0c0aae8eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aae90;
P_0c0aae90: /* original d23b, guest PC 0x0c0aae90 */
if(!s->budget--) { s->failed_pc=0x0c0aae90u; return 0; }
r[2]=read(ram,0x0c0aaf80u,4);
goto P_0c0aae92;
P_0c0aae92: /* original 4f26, guest PC 0x0c0aae92 */
if(!s->budget--) { s->failed_pc=0x0c0aae92u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aae94;
P_0c0aae94: /* original 64e3, guest PC 0x0c0aae94 */
if(!s->budget--) { s->failed_pc=0x0c0aae94u; return 0; }
r[4]=r[14];
goto P_0c0aae96;
P_0c0aae96: /* original 6cf6, guest PC 0x0c0aae96 */
if(!s->budget--) { s->failed_pc=0x0c0aae96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0aae98;
P_0c0aae98: /* original 6df6, guest PC 0x0c0aae98 */
if(!s->budget--) { s->failed_pc=0x0c0aae98u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aae9a;
P_0c0aae9a: /* original 422b, guest PC 0x0c0aae9a */
if(!s->budget--) { s->failed_pc=0x0c0aae9au; return 0; }
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
P_0c0aae9c: /* original 6ef6, guest PC 0x0c0aae9c */
if(!s->budget--) { s->failed_pc=0x0c0aae9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aae9e;
P_0c0aae9e: /* original 7f04, guest PC 0x0c0aae9e */
if(!s->budget--) { s->failed_pc=0x0c0aae9eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aaea0;
P_0c0aaea0: /* original d338, guest PC 0x0c0aaea0 */
if(!s->budget--) { s->failed_pc=0x0c0aaea0u; return 0; }
r[3]=read(ram,0x0c0aaf84u,4);
goto P_0c0aaea2;
P_0c0aaea2: /* original 4f26, guest PC 0x0c0aaea2 */
if(!s->budget--) { s->failed_pc=0x0c0aaea2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aaea4;
P_0c0aaea4: /* original 64e3, guest PC 0x0c0aaea4 */
if(!s->budget--) { s->failed_pc=0x0c0aaea4u; return 0; }
r[4]=r[14];
goto P_0c0aaea6;
P_0c0aaea6: /* original 6cf6, guest PC 0x0c0aaea6 */
if(!s->budget--) { s->failed_pc=0x0c0aaea6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0aaea8;
P_0c0aaea8: /* original 6df6, guest PC 0x0c0aaea8 */
if(!s->budget--) { s->failed_pc=0x0c0aaea8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aaeaa;
P_0c0aaeaa: /* original 432b, guest PC 0x0c0aaeaa */
if(!s->budget--) { s->failed_pc=0x0c0aaeaau; return 0; }
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
P_0c0aaeac: /* original 6ef6, guest PC 0x0c0aaeac */
if(!s->budget--) { s->failed_pc=0x0c0aaeacu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aaeae;
P_0c0aaeae: /* original 7f04, guest PC 0x0c0aaeae */
if(!s->budget--) { s->failed_pc=0x0c0aaeaeu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aaeb0;
P_0c0aaeb0: /* original 4f26, guest PC 0x0c0aaeb0 */
if(!s->budget--) { s->failed_pc=0x0c0aaeb0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aaeb2;
P_0c0aaeb2: /* original 6cf6, guest PC 0x0c0aaeb2 */
if(!s->budget--) { s->failed_pc=0x0c0aaeb2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0aaeb4;
P_0c0aaeb4: /* original 6df6, guest PC 0x0c0aaeb4 */
if(!s->budget--) { s->failed_pc=0x0c0aaeb4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aaeb6;
P_0c0aaeb6: /* original 000b, guest PC 0x0c0aaeb6 */
if(!s->budget--) { s->failed_pc=0x0c0aaeb6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0aaeb8: /* original 6ef6, guest PC 0x0c0aaeb8 */
if(!s->budget--) { s->failed_pc=0x0c0aaeb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0aaebau,s,ram);
P_0c0aaebe: /* original 4f22, guest PC 0x0c0aaebe */
if(!s->budget--) { s->failed_pc=0x0c0aaebeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aaec0;
P_0c0aaec0: /* original 6e43, guest PC 0x0c0aaec0 */
if(!s->budget--) { s->failed_pc=0x0c0aaec0u; return 0; }
r[14]=r[4];
goto P_0c0aaec2;
P_0c0aaec2: /* original 7ffc, guest PC 0x0c0aaec2 */
if(!s->budget--) { s->failed_pc=0x0c0aaec2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0aaec4;
P_0c0aaec4: /* original 2f52, guest PC 0x0c0aaec4 */
if(!s->budget--) { s->failed_pc=0x0c0aaec4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0aaec6;
P_0c0aaec6: /* original 04ee, guest PC 0x0c0aaec6 */
if(!s->budget--) { s->failed_pc=0x0c0aaec6u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0aaec8;
P_0c0aaec8: /* original e048, guest PC 0x0c0aaec8 */
if(!s->budget--) { s->failed_pc=0x0c0aaec8u; return 0; }
r[0]=0x00000048u;
goto P_0c0aaeca;
P_0c0aaeca: /* original d32f, guest PC 0x0c0aaeca */
if(!s->budget--) { s->failed_pc=0x0c0aaecau; return 0; }
r[3]=read(ram,0x0c0aaf88u,4);
goto P_0c0aaecc;
P_0c0aaecc: /* original 05ee, guest PC 0x0c0aaecc */
if(!s->budget--) { s->failed_pc=0x0c0aaeccu; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0aaece;
P_0c0aaece: /* original 9751, guest PC 0x0c0aaece */
if(!s->budget--) { s->failed_pc=0x0c0aaeceu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aaf74u,2);
goto P_0c0aaed0;
P_0c0aaed0: /* original 2538, guest PC 0x0c0aaed0 */
if(!s->budget--) { s->failed_pc=0x0c0aaed0u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0aaed2;
P_0c0aaed2: /* original 8d2a, guest PC 0x0c0aaed2 */
if(!s->budget--) { s->failed_pc=0x0c0aaed2u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[14],4);
r[6]=tmp;
if(cond) { goto P_0c0aaf2a; }
goto P_0c0aaed6;
P_0c0aaed4: /* original 66e2, guest PC 0x0c0aaed4 */
if(!s->budget--) { s->failed_pc=0x0c0aaed4u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c0aaed6;
P_0c0aaed6: /* original 934e, guest PC 0x0c0aaed6 */
if(!s->budget--) { s->failed_pc=0x0c0aaed6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aaf76u,2);
goto P_0c0aaed8;
P_0c0aaed8: /* original 854e, guest PC 0x0c0aaed8 */
if(!s->budget--) { s->failed_pc=0x0c0aaed8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+28,2);
goto P_0c0aaeda;
P_0c0aaeda: /* original 2638, guest PC 0x0c0aaeda */
if(!s->budget--) { s->failed_pc=0x0c0aaedau; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0aaedc;
P_0c0aaedc: /* original 8f3f, guest PC 0x0c0aaedc */
if(!s->budget--) { s->failed_pc=0x0c0aaedcu; return 0; }
cond=r[17]&1u;
r[5]=r[0]&65535u;
if(!cond) { goto P_0c0aaf5e; }
goto P_0c0aaee0;
P_0c0aaede: /* original 650d, guest PC 0x0c0aaede */
if(!s->budget--) { s->failed_pc=0x0c0aaedeu; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aaee0;
P_0c0aaee0: /* original 6643, guest PC 0x0c0aaee0 */
if(!s->budget--) { s->failed_pc=0x0c0aaee0u; return 0; }
r[6]=r[4];
goto P_0c0aaee2;
P_0c0aaee2: /* original e03c, guest PC 0x0c0aaee2 */
if(!s->budget--) { s->failed_pc=0x0c0aaee2u; return 0; }
r[0]=0x0000003cu;
goto P_0c0aaee4;
P_0c0aaee4: /* original 7622, guest PC 0x0c0aaee4 */
if(!s->budget--) { s->failed_pc=0x0c0aaee4u; return 0; }
r[6]+=0x00000022u;
goto P_0c0aaee6;
P_0c0aaee6: /* original 03ed, guest PC 0x0c0aaee6 */
if(!s->budget--) { s->failed_pc=0x0c0aaee6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aaee8;
P_0c0aaee8: /* original 6661, guest PC 0x0c0aaee8 */
if(!s->budget--) { s->failed_pc=0x0c0aaee8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[6]=tmp;
goto P_0c0aaeea;
P_0c0aaeea: /* original 633d, guest PC 0x0c0aaeea */
if(!s->budget--) { s->failed_pc=0x0c0aaeeau; return 0; }
r[3]=r[3]&65535u;
goto P_0c0aaeec;
P_0c0aaeec: /* original 666d, guest PC 0x0c0aaeec */
if(!s->budget--) { s->failed_pc=0x0c0aaeecu; return 0; }
r[6]=r[6]&65535u;
goto P_0c0aaeee;
P_0c0aaeee: /* original 3360, guest PC 0x0c0aaeee */
if(!s->budget--) { s->failed_pc=0x0c0aaeeeu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[6])!=0);
goto P_0c0aaef0;
P_0c0aaef0: /* original 892f, guest PC 0x0c0aaef0 */
if(!s->budget--) { s->failed_pc=0x0c0aaef0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aaf52; }
goto P_0c0aaef2;
P_0c0aaef2: /* original 903e, guest PC 0x0c0aaef2 */
if(!s->budget--) { s->failed_pc=0x0c0aaef2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aaf72u,2);
goto P_0c0aaef4;
P_0c0aaef4: /* original 06ed, guest PC 0x0c0aaef4 */
if(!s->budget--) { s->failed_pc=0x0c0aaef4u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aaef6;
P_0c0aaef6: /* original 666d, guest PC 0x0c0aaef6 */
if(!s->budget--) { s->failed_pc=0x0c0aaef6u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0aaef8;
P_0c0aaef8: /* original 2678, guest PC 0x0c0aaef8 */
if(!s->budget--) { s->failed_pc=0x0c0aaef8u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[7])==0)!=0);
goto P_0c0aaefa;
P_0c0aaefa: /* original 8b0f, guest PC 0x0c0aaefa */
if(!s->budget--) { s->failed_pc=0x0c0aaefau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aaf1c; }
goto P_0c0aaefc;
P_0c0aaefc: /* original 903c, guest PC 0x0c0aaefc */
if(!s->budget--) { s->failed_pc=0x0c0aaefcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aaf78u,2);
goto P_0c0aaefe;
P_0c0aaefe: /* original 6543, guest PC 0x0c0aaefe */
if(!s->budget--) { s->failed_pc=0x0c0aaefeu; return 0; }
r[5]=r[4];
goto P_0c0aaf00;
P_0c0aaf00: /* original d322, guest PC 0x0c0aaf00 */
if(!s->budget--) { s->failed_pc=0x0c0aaf00u; return 0; }
r[3]=read(ram,0x0c0aaf8cu,4);
goto P_0c0aaf02;
P_0c0aaf02: /* original 7522, guest PC 0x0c0aaf02 */
if(!s->budget--) { s->failed_pc=0x0c0aaf02u; return 0; }
r[5]+=0x00000022u;
goto P_0c0aaf04;
P_0c0aaf04: /* original 02ee, guest PC 0x0c0aaf04 */
if(!s->budget--) { s->failed_pc=0x0c0aaf04u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0aaf06;
P_0c0aaf06: /* original 6551, guest PC 0x0c0aaf06 */
if(!s->budget--) { s->failed_pc=0x0c0aaf06u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0aaf08;
P_0c0aaf08: /* original 2238, guest PC 0x0c0aaf08 */
if(!s->budget--) { s->failed_pc=0x0c0aaf08u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aaf0a;
P_0c0aaf0a: /* original 8d02, guest PC 0x0c0aaf0a */
if(!s->budget--) { s->failed_pc=0x0c0aaf0au; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(cond) { goto P_0c0aaf12; }
goto P_0c0aaf0e;
P_0c0aaf0c: /* original 655d, guest PC 0x0c0aaf0c */
if(!s->budget--) { s->failed_pc=0x0c0aaf0cu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0aaf0e;
P_0c0aaf0e: /* original 854e, guest PC 0x0c0aaf0e */
if(!s->budget--) { s->failed_pc=0x0c0aaf0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+28,2);
goto P_0c0aaf10;
P_0c0aaf10: /* original 650d, guest PC 0x0c0aaf10 */
if(!s->budget--) { s->failed_pc=0x0c0aaf10u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0aaf12;
P_0c0aaf12: /* original d31f, guest PC 0x0c0aaf12 */
if(!s->budget--) { s->failed_pc=0x0c0aaf12u; return 0; }
r[3]=read(ram,0x0c0aaf90u,4);
goto P_0c0aaf14;
P_0c0aaf14: /* original 430b, guest PC 0x0c0aaf14 */
if(!s->budget--) { s->failed_pc=0x0c0aaf14u; return 0; }
target=r[3];
r[16]=0x0c0aaf18u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aaf18u) { target=s->pc; goto dispatch; }
goto P_0c0aaf18;
P_0c0aaf16: /* original 64e3, guest PC 0x0c0aaf16 */
if(!s->budget--) { s->failed_pc=0x0c0aaf16u; return 0; }
r[4]=r[14];
goto P_0c0aaf18;
P_0c0aaf18: /* original a01b, guest PC 0x0c0aaf18 */
if(!s->budget--) { s->failed_pc=0x0c0aaf18u; return 0; }
goto P_0c0aaf52;
P_0c0aaf1a: /* original 0009, guest PC 0x0c0aaf1a */
if(!s->budget--) { s->failed_pc=0x0c0aaf1au; return 0; }
goto P_0c0aaf1c;
P_0c0aaf1c: /* original 902c, guest PC 0x0c0aaf1c */
if(!s->budget--) { s->failed_pc=0x0c0aaf1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aaf78u,2);
goto P_0c0aaf1e;
P_0c0aaf1e: /* original d31d, guest PC 0x0c0aaf1e */
if(!s->budget--) { s->failed_pc=0x0c0aaf1eu; return 0; }
r[3]=read(ram,0x0c0aaf94u,4);
goto P_0c0aaf20;
P_0c0aaf20: /* original 02ee, guest PC 0x0c0aaf20 */
if(!s->budget--) { s->failed_pc=0x0c0aaf20u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0aaf22;
P_0c0aaf22: /* original 2238, guest PC 0x0c0aaf22 */
if(!s->budget--) { s->failed_pc=0x0c0aaf22u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aaf24;
P_0c0aaf24: /* original 8b21, guest PC 0x0c0aaf24 */
if(!s->budget--) { s->failed_pc=0x0c0aaf24u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aaf6a; }
goto P_0c0aaf26;
P_0c0aaf26: /* original a01a, guest PC 0x0c0aaf26 */
if(!s->budget--) { s->failed_pc=0x0c0aaf26u; return 0; }
goto P_0c0aaf5e;
P_0c0aaf28: /* original 0009, guest PC 0x0c0aaf28 */
if(!s->budget--) { s->failed_pc=0x0c0aaf28u; return 0; }
goto P_0c0aaf2a;
P_0c0aaf2a: /* original 6543, guest PC 0x0c0aaf2a */
if(!s->budget--) { s->failed_pc=0x0c0aaf2au; return 0; }
r[5]=r[4];
goto P_0c0aaf2c;
P_0c0aaf2c: /* original d313, guest PC 0x0c0aaf2c */
if(!s->budget--) { s->failed_pc=0x0c0aaf2cu; return 0; }
r[3]=read(ram,0x0c0aaf7cu,4);
goto P_0c0aaf2e;
P_0c0aaf2e: /* original 7522, guest PC 0x0c0aaf2e */
if(!s->budget--) { s->failed_pc=0x0c0aaf2eu; return 0; }
r[5]+=0x00000022u;
goto P_0c0aaf30;
P_0c0aaf30: /* original 6551, guest PC 0x0c0aaf30 */
if(!s->budget--) { s->failed_pc=0x0c0aaf30u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[5]=tmp;
goto P_0c0aaf32;
P_0c0aaf32: /* original 2638, guest PC 0x0c0aaf32 */
if(!s->budget--) { s->failed_pc=0x0c0aaf32u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0aaf34;
P_0c0aaf34: /* original 8f13, guest PC 0x0c0aaf34 */
if(!s->budget--) { s->failed_pc=0x0c0aaf34u; return 0; }
cond=r[17]&1u;
r[5]=r[5]&65535u;
if(!cond) { goto P_0c0aaf5e; }
goto P_0c0aaf38;
P_0c0aaf36: /* original 655d, guest PC 0x0c0aaf36 */
if(!s->budget--) { s->failed_pc=0x0c0aaf36u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0aaf38;
P_0c0aaf38: /* original 901b, guest PC 0x0c0aaf38 */
if(!s->budget--) { s->failed_pc=0x0c0aaf38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aaf72u,2);
goto P_0c0aaf3a;
P_0c0aaf3a: /* original 04ed, guest PC 0x0c0aaf3a */
if(!s->budget--) { s->failed_pc=0x0c0aaf3au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aaf3c;
P_0c0aaf3c: /* original 644d, guest PC 0x0c0aaf3c */
if(!s->budget--) { s->failed_pc=0x0c0aaf3cu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0aaf3e;
P_0c0aaf3e: /* original 2478, guest PC 0x0c0aaf3e */
if(!s->budget--) { s->failed_pc=0x0c0aaf3eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[7])==0)!=0);
goto P_0c0aaf40;
P_0c0aaf40: /* original 8b04, guest PC 0x0c0aaf40 */
if(!s->budget--) { s->failed_pc=0x0c0aaf40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aaf4c; }
goto P_0c0aaf42;
P_0c0aaf42: /* original d310, guest PC 0x0c0aaf42 */
if(!s->budget--) { s->failed_pc=0x0c0aaf42u; return 0; }
r[3]=read(ram,0x0c0aaf84u,4);
goto P_0c0aaf44;
P_0c0aaf44: /* original 430b, guest PC 0x0c0aaf44 */
if(!s->budget--) { s->failed_pc=0x0c0aaf44u; return 0; }
target=r[3];
r[16]=0x0c0aaf48u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aaf48u) { target=s->pc; goto dispatch; }
goto P_0c0aaf48;
P_0c0aaf46: /* original 64e3, guest PC 0x0c0aaf46 */
if(!s->budget--) { s->failed_pc=0x0c0aaf46u; return 0; }
r[4]=r[14];
goto P_0c0aaf48;
P_0c0aaf48: /* original a003, guest PC 0x0c0aaf48 */
if(!s->budget--) { s->failed_pc=0x0c0aaf48u; return 0; }
goto P_0c0aaf52;
P_0c0aaf4a: /* original 0009, guest PC 0x0c0aaf4a */
if(!s->budget--) { s->failed_pc=0x0c0aaf4au; return 0; }
goto P_0c0aaf4c;
P_0c0aaf4c: /* original d30c, guest PC 0x0c0aaf4c */
if(!s->budget--) { s->failed_pc=0x0c0aaf4cu; return 0; }
r[3]=read(ram,0x0c0aaf80u,4);
goto P_0c0aaf4e;
P_0c0aaf4e: /* original 430b, guest PC 0x0c0aaf4e */
if(!s->budget--) { s->failed_pc=0x0c0aaf4eu; return 0; }
target=r[3];
r[16]=0x0c0aaf52u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aaf52u) { target=s->pc; goto dispatch; }
goto P_0c0aaf52;
P_0c0aaf50: /* original 64e3, guest PC 0x0c0aaf50 */
if(!s->budget--) { s->failed_pc=0x0c0aaf50u; return 0; }
r[4]=r[14];
goto P_0c0aaf52;
P_0c0aaf52: /* original 65f2, guest PC 0x0c0aaf52 */
if(!s->budget--) { s->failed_pc=0x0c0aaf52u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0aaf54;
P_0c0aaf54: /* original 7f04, guest PC 0x0c0aaf54 */
if(!s->budget--) { s->failed_pc=0x0c0aaf54u; return 0; }
r[15]+=0x00000004u;
goto P_0c0aaf56;
P_0c0aaf56: /* original 4f26, guest PC 0x0c0aaf56 */
if(!s->budget--) { s->failed_pc=0x0c0aaf56u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aaf58;
P_0c0aaf58: /* original 64e3, guest PC 0x0c0aaf58 */
if(!s->budget--) { s->failed_pc=0x0c0aaf58u; return 0; }
r[4]=r[14];
goto P_0c0aaf5a;
P_0c0aaf5a: /* original ac22, guest PC 0x0c0aaf5a */
if(!s->budget--) { s->failed_pc=0x0c0aaf5au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa7a2;
P_0c0aaf5c: /* original 6ef6, guest PC 0x0c0aaf5c */
if(!s->budget--) { s->failed_pc=0x0c0aaf5cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aaf5e;
P_0c0aaf5e: /* original 7f04, guest PC 0x0c0aaf5e */
if(!s->budget--) { s->failed_pc=0x0c0aaf5eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aaf60;
P_0c0aaf60: /* original d208, guest PC 0x0c0aaf60 */
if(!s->budget--) { s->failed_pc=0x0c0aaf60u; return 0; }
r[2]=read(ram,0x0c0aaf84u,4);
goto P_0c0aaf62;
P_0c0aaf62: /* original 4f26, guest PC 0x0c0aaf62 */
if(!s->budget--) { s->failed_pc=0x0c0aaf62u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aaf64;
P_0c0aaf64: /* original 64e3, guest PC 0x0c0aaf64 */
if(!s->budget--) { s->failed_pc=0x0c0aaf64u; return 0; }
r[4]=r[14];
goto P_0c0aaf66;
P_0c0aaf66: /* original 422b, guest PC 0x0c0aaf66 */
if(!s->budget--) { s->failed_pc=0x0c0aaf66u; return 0; }
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
P_0c0aaf68: /* original 6ef6, guest PC 0x0c0aaf68 */
if(!s->budget--) { s->failed_pc=0x0c0aaf68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aaf6a;
P_0c0aaf6a: /* original 7f04, guest PC 0x0c0aaf6a */
if(!s->budget--) { s->failed_pc=0x0c0aaf6au; return 0; }
r[15]+=0x00000004u;
goto P_0c0aaf6c;
P_0c0aaf6c: /* original 4f26, guest PC 0x0c0aaf6c */
if(!s->budget--) { s->failed_pc=0x0c0aaf6cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aaf6e;
P_0c0aaf6e: /* original 000b, guest PC 0x0c0aaf6e */
if(!s->budget--) { s->failed_pc=0x0c0aaf6eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0aaf70: /* original 6ef6, guest PC 0x0c0aaf70 */
if(!s->budget--) { s->failed_pc=0x0c0aaf70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0aaf72u,s,ram);
P_0c0aafb0: /* original 4f22, guest PC 0x0c0aafb0 */
if(!s->budget--) { s->failed_pc=0x0c0aafb0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aafb2;
P_0c0aafb2: /* original f230, guest PC 0x0c0aafb2 */
if(!s->budget--) { s->failed_pc=0x0c0aafb2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0aafb4;
P_0c0aafb4: /* original 7ff0, guest PC 0x0c0aafb4 */
if(!s->budget--) { s->failed_pc=0x0c0aafb4u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0aafb6;
P_0c0aafb6: /* original fe27, guest PC 0x0c0aafb6 */
if(!s->budget--) { s->failed_pc=0x0c0aafb6u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0aafb8;
P_0c0aafb8: /* original e066, guest PC 0x0c0aafb8 */
if(!s->budget--) { s->failed_pc=0x0c0aafb8u; return 0; }
r[0]=0x00000066u;
goto P_0c0aafba;
P_0c0aafba: /* original 0ced, guest PC 0x0c0aafba */
if(!s->budget--) { s->failed_pc=0x0c0aafbau; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aafbc;
P_0c0aafbc: /* original 7cff, guest PC 0x0c0aafbc */
if(!s->budget--) { s->failed_pc=0x0c0aafbcu; return 0; }
r[12]+=0xffffffffu;
goto P_0c0aafbe;
P_0c0aafbe: /* original 4c11, guest PC 0x0c0aafbe */
if(!s->budget--) { s->failed_pc=0x0c0aafbeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=0)!=0);
goto P_0c0aafc0;
P_0c0aafc0: /* original 8d01, guest PC 0x0c0aafc0 */
if(!s->budget--) { s->failed_pc=0x0c0aafc0u; return 0; }
cond=r[17]&1u;
r[13]=r[6];
if(cond) { goto P_0c0aafc6; }
goto P_0c0aafc4;
P_0c0aafc2: /* original 6d63, guest PC 0x0c0aafc2 */
if(!s->budget--) { s->failed_pc=0x0c0aafc2u; return 0; }
r[13]=r[6];
goto P_0c0aafc4;
P_0c0aafc4: /* original ec00, guest PC 0x0c0aafc4 */
if(!s->budget--) { s->failed_pc=0x0c0aafc4u; return 0; }
r[12]=0x00000000u;
goto P_0c0aafc6;
P_0c0aafc6: /* original 0ec5, guest PC 0x0c0aafc6 */
if(!s->budget--) { s->failed_pc=0x0c0aafc6u; return 0; }
write(ram,r[14]+r[0],r[12],2);
goto P_0c0aafc8;
P_0c0aafc8: /* original 64d2, guest PC 0x0c0aafc8 */
if(!s->budget--) { s->failed_pc=0x0c0aafc8u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0aafca;
P_0c0aafca: /* original 4429, guest PC 0x0c0aafca */
if(!s->budget--) { s->failed_pc=0x0c0aafcau; return 0; }
r[4]>>=16;
goto P_0c0aafcc;
P_0c0aafcc: /* original 644c, guest PC 0x0c0aafcc */
if(!s->budget--) { s->failed_pc=0x0c0aafccu; return 0; }
r[4]=r[4]&255u;
goto P_0c0aafce;
P_0c0aafce: /* original 6043, guest PC 0x0c0aafce */
if(!s->budget--) { s->failed_pc=0x0c0aafceu; return 0; }
r[0]=r[4];
goto P_0c0aafd0;
P_0c0aafd0: /* original 8801, guest PC 0x0c0aafd0 */
if(!s->budget--) { s->failed_pc=0x0c0aafd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0aafd2;
P_0c0aafd2: /* original 8b03, guest PC 0x0c0aafd2 */
if(!s->budget--) { s->failed_pc=0x0c0aafd2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aafdc; }
goto P_0c0aafd4;
P_0c0aafd4: /* original d23d, guest PC 0x0c0aafd4 */
if(!s->budget--) { s->failed_pc=0x0c0aafd4u; return 0; }
r[2]=read(ram,0x0c0ab0ccu,4);
goto P_0c0aafd6;
P_0c0aafd6: /* original 65b3, guest PC 0x0c0aafd6 */
if(!s->budget--) { s->failed_pc=0x0c0aafd6u; return 0; }
r[5]=r[11];
goto P_0c0aafd8;
P_0c0aafd8: /* original 420b, guest PC 0x0c0aafd8 */
if(!s->budget--) { s->failed_pc=0x0c0aafd8u; return 0; }
target=r[2];
r[16]=0x0c0aafdcu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aafdcu) { target=s->pc; goto dispatch; }
goto P_0c0aafdc;
P_0c0aafda: /* original 64e3, guest PC 0x0c0aafda */
if(!s->budget--) { s->failed_pc=0x0c0aafdau; return 0; }
r[4]=r[14];
goto P_0c0aafdc;
P_0c0aafdc: /* original 50d1, guest PC 0x0c0aafdc */
if(!s->budget--) { s->failed_pc=0x0c0aafdcu; return 0; }
r[0]=read(ram,r[13]+4,4);
goto P_0c0aafde;
P_0c0aafde: /* original 8800, guest PC 0x0c0aafde */
if(!s->budget--) { s->failed_pc=0x0c0aafdeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0aafe0;
P_0c0aafe0: /* original 8907, guest PC 0x0c0aafe0 */
if(!s->budget--) { s->failed_pc=0x0c0aafe0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aaff2; }
goto P_0c0aafe2;
P_0c0aafe2: /* original 8801, guest PC 0x0c0aafe2 */
if(!s->budget--) { s->failed_pc=0x0c0aafe2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0aafe4;
P_0c0aafe4: /* original 894f, guest PC 0x0c0aafe4 */
if(!s->budget--) { s->failed_pc=0x0c0aafe4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab086; }
goto P_0c0aafe6;
P_0c0aafe6: /* original 8802, guest PC 0x0c0aafe6 */
if(!s->budget--) { s->failed_pc=0x0c0aafe6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0aafe8;
P_0c0aafe8: /* original 895c, guest PC 0x0c0aafe8 */
if(!s->budget--) { s->failed_pc=0x0c0aafe8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab0a4; }
goto P_0c0aafea;
P_0c0aafea: /* original 8803, guest PC 0x0c0aafea */
if(!s->budget--) { s->failed_pc=0x0c0aafeau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0aafec;
P_0c0aafec: /* original 8b01, guest PC 0x0c0aafec */
if(!s->budget--) { s->failed_pc=0x0c0aafecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aaff2; }
goto P_0c0aafee;
P_0c0aafee: /* original a083, guest PC 0x0c0aafee */
if(!s->budget--) { s->failed_pc=0x0c0aafeeu; return 0; }
goto P_0c0ab0f8;
P_0c0aaff0: /* original 0009, guest PC 0x0c0aaff0 */
if(!s->budget--) { s->failed_pc=0x0c0aaff0u; return 0; }
goto P_0c0aaff2;
P_0c0aaff2: /* original c738, guest PC 0x0c0aaff2 */
if(!s->budget--) { s->failed_pc=0x0c0aaff2u; return 0; }
r[0]=0x0c0ab0d4u;
goto P_0c0aaff4;
P_0c0aaff4: /* original d336, guest PC 0x0c0aaff4 */
if(!s->budget--) { s->failed_pc=0x0c0aaff4u; return 0; }
r[3]=read(ram,0x0c0ab0d0u,4);
goto P_0c0aaff6;
P_0c0aaff6: /* original 62e2, guest PC 0x0c0aaff6 */
if(!s->budget--) { s->failed_pc=0x0c0aaff6u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0aaff8;
P_0c0aaff8: /* original 65f3, guest PC 0x0c0aaff8 */
if(!s->budget--) { s->failed_pc=0x0c0aaff8u; return 0; }
r[5]=r[15];
goto P_0c0aaffa;
P_0c0aaffa: /* original 64f3, guest PC 0x0c0aaffa */
if(!s->budget--) { s->failed_pc=0x0c0aaffau; return 0; }
r[4]=r[15];
goto P_0c0aaffc;
P_0c0aaffc: /* original 223b, guest PC 0x0c0aaffc */
if(!s->budget--) { s->failed_pc=0x0c0aaffcu; return 0; }
r[2]|=r[3];
goto P_0c0aaffe;
P_0c0aaffe: /* original 2e22, guest PC 0x0c0aaffe */
if(!s->budget--) { s->failed_pc=0x0c0aaffeu; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0ab000;
P_0c0ab000: /* original f708, guest PC 0x0c0ab000 */
if(!s->budget--) { s->failed_pc=0x0c0ab000u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0ab002;
P_0c0ab002: /* original 905d, guest PC 0x0c0ab002 */
if(!s->budget--) { s->failed_pc=0x0c0ab002u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab0c0u,2);
goto P_0c0ab004;
P_0c0ab004: /* original f49d, guest PC 0x0c0ab004 */
if(!s->budget--) { s->failed_pc=0x0c0ab004u; return 0; }
fr[4]=0x3f800000u;
goto P_0c0ab006;
P_0c0ab006: /* original f5e6, guest PC 0x0c0ab006 */
if(!s->budget--) { s->failed_pc=0x0c0ab006u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0ab008;
P_0c0ab008: /* original 7008, guest PC 0x0c0ab008 */
if(!s->budget--) { s->failed_pc=0x0c0ab008u; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab00a;
P_0c0ab00a: /* original f34c, guest PC 0x0c0ab00a */
if(!s->budget--) { s->failed_pc=0x0c0ab00au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0ab00c;
P_0c0ab00c: /* original f352, guest PC 0x0c0ab00c */
if(!s->budget--) { s->failed_pc=0x0c0ab00cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c0ab00e;
P_0c0ab00e: /* original f6e6, guest PC 0x0c0ab00e */
if(!s->budget--) { s->failed_pc=0x0c0ab00eu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0ab010;
P_0c0ab010: /* original e00c, guest PC 0x0c0ab010 */
if(!s->budget--) { s->failed_pc=0x0c0ab010u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab012;
P_0c0ab012: /* original f462, guest PC 0x0c0ab012 */
if(!s->budget--) { s->failed_pc=0x0c0ab012u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0ab014;
P_0c0ab014: /* original ff37, guest PC 0x0c0ab014 */
if(!s->budget--) { s->failed_pc=0x0c0ab014u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab016;
P_0c0ab016: /* original e008, guest PC 0x0c0ab016 */
if(!s->budget--) { s->failed_pc=0x0c0ab016u; return 0; }
r[0]=0x00000008u;
goto P_0c0ab018;
P_0c0ab018: /* original ff47, guest PC 0x0c0ab018 */
if(!s->budget--) { s->failed_pc=0x0c0ab018u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0ab01a;
P_0c0ab01a: /* original e004, guest PC 0x0c0ab01a */
if(!s->budget--) { s->failed_pc=0x0c0ab01au; return 0; }
r[0]=0x00000004u;
goto P_0c0ab01c;
P_0c0ab01c: /* original f27c, guest PC 0x0c0ab01c */
if(!s->budget--) { s->failed_pc=0x0c0ab01cu; return 0; }
vf3_matrix_move(s,2,7);
goto P_0c0ab01e;
P_0c0ab01e: /* original f252, guest PC 0x0c0ab01e */
if(!s->budget--) { s->failed_pc=0x0c0ab01eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'*');
goto P_0c0ab020;
P_0c0ab020: /* original f762, guest PC 0x0c0ab020 */
if(!s->budget--) { s->failed_pc=0x0c0ab020u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'*');
goto P_0c0ab022;
P_0c0ab022: /* original ff27, guest PC 0x0c0ab022 */
if(!s->budget--) { s->failed_pc=0x0c0ab022u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0ab024;
P_0c0ab024: /* original ff7a, guest PC 0x0c0ab024 */
if(!s->budget--) { s->failed_pc=0x0c0ab024u; return 0; }
vf3_matrix_store(s,ram,7,r[15]);
goto P_0c0ab026;
P_0c0ab026: /* original bb82, guest PC 0x0c0ab026 */
if(!s->budget--) { s->failed_pc=0x0c0ab026u; return 0; }
target=0x0c0aa72eu; r[16]=0x0c0ab02au;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ab02au) { target=s->pc; goto dispatch; }
goto P_0c0ab02a;
P_0c0ab028: /* original 7404, guest PC 0x0c0ab028 */
if(!s->budget--) { s->failed_pc=0x0c0ab028u; return 0; }
r[4]+=0x00000004u;
goto P_0c0ab02a;
P_0c0ab02a: /* original e00c, guest PC 0x0c0ab02a */
if(!s->budget--) { s->failed_pc=0x0c0ab02au; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab02c;
P_0c0ab02c: /* original f3f6, guest PC 0x0c0ab02c */
if(!s->budget--) { s->failed_pc=0x0c0ab02cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab02e;
P_0c0ab02e: /* original e024, guest PC 0x0c0ab02e */
if(!s->budget--) { s->failed_pc=0x0c0ab02eu; return 0; }
r[0]=0x00000024u;
goto P_0c0ab030;
P_0c0ab030: /* original fe37, guest PC 0x0c0ab030 */
if(!s->budget--) { s->failed_pc=0x0c0ab030u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab032;
P_0c0ab032: /* original e008, guest PC 0x0c0ab032 */
if(!s->budget--) { s->failed_pc=0x0c0ab032u; return 0; }
r[0]=0x00000008u;
goto P_0c0ab034;
P_0c0ab034: /* original f3f6, guest PC 0x0c0ab034 */
if(!s->budget--) { s->failed_pc=0x0c0ab034u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab036;
P_0c0ab036: /* original e02c, guest PC 0x0c0ab036 */
if(!s->budget--) { s->failed_pc=0x0c0ab036u; return 0; }
r[0]=0x0000002cu;
goto P_0c0ab038;
P_0c0ab038: /* original fe37, guest PC 0x0c0ab038 */
if(!s->budget--) { s->failed_pc=0x0c0ab038u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab03a;
P_0c0ab03a: /* original e004, guest PC 0x0c0ab03a */
if(!s->budget--) { s->failed_pc=0x0c0ab03au; return 0; }
r[0]=0x00000004u;
goto P_0c0ab03c;
P_0c0ab03c: /* original f3f6, guest PC 0x0c0ab03c */
if(!s->budget--) { s->failed_pc=0x0c0ab03cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab03e;
P_0c0ab03e: /* original 9040, guest PC 0x0c0ab03e */
if(!s->budget--) { s->failed_pc=0x0c0ab03eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab0c2u,2);
goto P_0c0ab040;
P_0c0ab040: /* original fe37, guest PC 0x0c0ab040 */
if(!s->budget--) { s->failed_pc=0x0c0ab040u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab042;
P_0c0ab042: /* original 903f, guest PC 0x0c0ab042 */
if(!s->budget--) { s->failed_pc=0x0c0ab042u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab0c4u,2);
goto P_0c0ab044;
P_0c0ab044: /* original f3f8, guest PC 0x0c0ab044 */
if(!s->budget--) { s->failed_pc=0x0c0ab044u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0ab046;
P_0c0ab046: /* original fe37, guest PC 0x0c0ab046 */
if(!s->budget--) { s->failed_pc=0x0c0ab046u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab048;
P_0c0ab048: /* original 65d2, guest PC 0x0c0ab048 */
if(!s->budget--) { s->failed_pc=0x0c0ab048u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0ab04a;
P_0c0ab04a: /* original 655d, guest PC 0x0c0ab04a */
if(!s->budget--) { s->failed_pc=0x0c0ab04au; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ab04c;
P_0c0ab04c: /* original 2558, guest PC 0x0c0ab04c */
if(!s->budget--) { s->failed_pc=0x0c0ab04cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0ab04e;
P_0c0ab04e: /* original 8b08, guest PC 0x0c0ab04e */
if(!s->budget--) { s->failed_pc=0x0c0ab04eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab062; }
goto P_0c0ab050;
P_0c0ab050: /* original 85ae, guest PC 0x0c0ab050 */
if(!s->budget--) { s->failed_pc=0x0c0ab050u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+28,2);
goto P_0c0ab052;
P_0c0ab052: /* original d321, guest PC 0x0c0ab052 */
if(!s->budget--) { s->failed_pc=0x0c0ab052u; return 0; }
r[3]=read(ram,0x0c0ab0d8u,4);
goto P_0c0ab054;
P_0c0ab054: /* original 650d, guest PC 0x0c0ab054 */
if(!s->budget--) { s->failed_pc=0x0c0ab054u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0ab056;
P_0c0ab056: /* original e048, guest PC 0x0c0ab056 */
if(!s->budget--) { s->failed_pc=0x0c0ab056u; return 0; }
r[0]=0x00000048u;
goto P_0c0ab058;
P_0c0ab058: /* original 02ee, guest PC 0x0c0ab058 */
if(!s->budget--) { s->failed_pc=0x0c0ab058u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ab05a;
P_0c0ab05a: /* original 2238, guest PC 0x0c0ab05a */
if(!s->budget--) { s->failed_pc=0x0c0ab05au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab05c;
P_0c0ab05c: /* original 8b01, guest PC 0x0c0ab05c */
if(!s->budget--) { s->failed_pc=0x0c0ab05cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab062; }
goto P_0c0ab05e;
P_0c0ab05e: /* original 85ac, guest PC 0x0c0ab05e */
if(!s->budget--) { s->failed_pc=0x0c0ab05eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+24,2);
goto P_0c0ab060;
P_0c0ab060: /* original 650d, guest PC 0x0c0ab060 */
if(!s->budget--) { s->failed_pc=0x0c0ab060u; return 0; }
r[5]=r[0]&65535u;
goto P_0c0ab062;
P_0c0ab062: /* original d31e, guest PC 0x0c0ab062 */
if(!s->budget--) { s->failed_pc=0x0c0ab062u; return 0; }
r[3]=read(ram,0x0c0ab0dcu,4);
goto P_0c0ab064;
P_0c0ab064: /* original 430b, guest PC 0x0c0ab064 */
if(!s->budget--) { s->failed_pc=0x0c0ab064u; return 0; }
target=r[3];
r[16]=0x0c0ab068u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ab068u) { target=s->pc; goto dispatch; }
goto P_0c0ab068;
P_0c0ab066: /* original 64e3, guest PC 0x0c0ab066 */
if(!s->budget--) { s->failed_pc=0x0c0ab066u; return 0; }
r[4]=r[14];
goto P_0c0ab068;
P_0c0ab068: /* original e048, guest PC 0x0c0ab068 */
if(!s->budget--) { s->failed_pc=0x0c0ab068u; return 0; }
r[0]=0x00000048u;
goto P_0c0ab06a;
P_0c0ab06a: /* original d31d, guest PC 0x0c0ab06a */
if(!s->budget--) { s->failed_pc=0x0c0ab06au; return 0; }
r[3]=read(ram,0x0c0ab0e0u,4);
goto P_0c0ab06c;
P_0c0ab06c: /* original 02ee, guest PC 0x0c0ab06c */
if(!s->budget--) { s->failed_pc=0x0c0ab06cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ab06e;
P_0c0ab06e: /* original 223b, guest PC 0x0c0ab06e */
if(!s->budget--) { s->failed_pc=0x0c0ab06eu; return 0; }
r[2]|=r[3];
goto P_0c0ab070;
P_0c0ab070: /* original 0e26, guest PC 0x0c0ab070 */
if(!s->budget--) { s->failed_pc=0x0c0ab070u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0ab072;
P_0c0ab072: /* original 9028, guest PC 0x0c0ab072 */
if(!s->budget--) { s->failed_pc=0x0c0ab072u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab0c6u,2);
goto P_0c0ab074;
P_0c0ab074: /* original 01ed, guest PC 0x0c0ab074 */
if(!s->budget--) { s->failed_pc=0x0c0ab074u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab076;
P_0c0ab076: /* original e03e, guest PC 0x0c0ab076 */
if(!s->budget--) { s->failed_pc=0x0c0ab076u; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab078;
P_0c0ab078: /* original 0e15, guest PC 0x0c0ab078 */
if(!s->budget--) { s->failed_pc=0x0c0ab078u; return 0; }
write(ram,r[14]+r[0],r[1],2);
goto P_0c0ab07a;
P_0c0ab07a: /* original e062, guest PC 0x0c0ab07a */
if(!s->budget--) { s->failed_pc=0x0c0ab07au; return 0; }
r[0]=0x00000062u;
goto P_0c0ab07c;
P_0c0ab07c: /* original 52d1, guest PC 0x0c0ab07c */
if(!s->budget--) { s->failed_pc=0x0c0ab07cu; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0ab07e;
P_0c0ab07e: /* original 7201, guest PC 0x0c0ab07e */
if(!s->budget--) { s->failed_pc=0x0c0ab07eu; return 0; }
r[2]+=0x00000001u;
goto P_0c0ab080;
P_0c0ab080: /* original 6123, guest PC 0x0c0ab080 */
if(!s->budget--) { s->failed_pc=0x0c0ab080u; return 0; }
r[1]=r[2];
goto P_0c0ab082;
P_0c0ab082: /* original 1d21, guest PC 0x0c0ab082 */
if(!s->budget--) { s->failed_pc=0x0c0ab082u; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0ab084;
P_0c0ab084: /* original 0e14, guest PC 0x0c0ab084 */
if(!s->budget--) { s->failed_pc=0x0c0ab084u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c0ab086;
P_0c0ab086: /* original e03e, guest PC 0x0c0ab086 */
if(!s->budget--) { s->failed_pc=0x0c0ab086u; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab088;
P_0c0ab088: /* original 05ed, guest PC 0x0c0ab088 */
if(!s->budget--) { s->failed_pc=0x0c0ab088u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab08a;
P_0c0ab08a: /* original 901d, guest PC 0x0c0ab08a */
if(!s->budget--) { s->failed_pc=0x0c0ab08au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab0c8u,2);
goto P_0c0ab08c;
P_0c0ab08c: /* original 655d, guest PC 0x0c0ab08c */
if(!s->budget--) { s->failed_pc=0x0c0ab08cu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ab08e;
P_0c0ab08e: /* original 04ed, guest PC 0x0c0ab08e */
if(!s->budget--) { s->failed_pc=0x0c0ab08eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab090;
P_0c0ab090: /* original 644d, guest PC 0x0c0ab090 */
if(!s->budget--) { s->failed_pc=0x0c0ab090u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0ab092;
P_0c0ab092: /* original 74ff, guest PC 0x0c0ab092 */
if(!s->budget--) { s->failed_pc=0x0c0ab092u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0ab094;
P_0c0ab094: /* original 3542, guest PC 0x0c0ab094 */
if(!s->budget--) { s->failed_pc=0x0c0ab094u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[4])!=0);
goto P_0c0ab096;
P_0c0ab096: /* original 8b60, guest PC 0x0c0ab096 */
if(!s->budget--) { s->failed_pc=0x0c0ab096u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab15a; }
goto P_0c0ab098;
P_0c0ab098: /* original 52d1, guest PC 0x0c0ab098 */
if(!s->budget--) { s->failed_pc=0x0c0ab098u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0ab09a;
P_0c0ab09a: /* original e062, guest PC 0x0c0ab09a */
if(!s->budget--) { s->failed_pc=0x0c0ab09au; return 0; }
r[0]=0x00000062u;
goto P_0c0ab09c;
P_0c0ab09c: /* original 7201, guest PC 0x0c0ab09c */
if(!s->budget--) { s->failed_pc=0x0c0ab09cu; return 0; }
r[2]+=0x00000001u;
goto P_0c0ab09e;
P_0c0ab09e: /* original 6323, guest PC 0x0c0ab09e */
if(!s->budget--) { s->failed_pc=0x0c0ab09eu; return 0; }
r[3]=r[2];
goto P_0c0ab0a0;
P_0c0ab0a0: /* original 1d21, guest PC 0x0c0ab0a0 */
if(!s->budget--) { s->failed_pc=0x0c0ab0a0u; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0ab0a2;
P_0c0ab0a2: /* original 0e34, guest PC 0x0c0ab0a2 */
if(!s->budget--) { s->failed_pc=0x0c0ab0a2u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ab0a4;
P_0c0ab0a4: /* original 9010, guest PC 0x0c0ab0a4 */
if(!s->budget--) { s->failed_pc=0x0c0ab0a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab0c8u,2);
goto P_0c0ab0a6;
P_0c0ab0a6: /* original 04ed, guest PC 0x0c0ab0a6 */
if(!s->budget--) { s->failed_pc=0x0c0ab0a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab0a8;
P_0c0ab0a8: /* original 7002, guest PC 0x0c0ab0a8 */
if(!s->budget--) { s->failed_pc=0x0c0ab0a8u; return 0; }
r[0]+=0x00000002u;
goto P_0c0ab0aa;
P_0c0ab0aa: /* original 05ed, guest PC 0x0c0ab0aa */
if(!s->budget--) { s->failed_pc=0x0c0ab0aau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab0ac;
P_0c0ab0ac: /* original 644d, guest PC 0x0c0ab0ac */
if(!s->budget--) { s->failed_pc=0x0c0ab0acu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0ab0ae;
P_0c0ab0ae: /* original 655d, guest PC 0x0c0ab0ae */
if(!s->budget--) { s->failed_pc=0x0c0ab0aeu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ab0b0;
P_0c0ab0b0: /* original 35c8, guest PC 0x0c0ab0b0 */
if(!s->budget--) { s->failed_pc=0x0c0ab0b0u; return 0; }
r[5]-=r[12];
goto P_0c0ab0b2;
P_0c0ab0b2: /* original 74ff, guest PC 0x0c0ab0b2 */
if(!s->budget--) { s->failed_pc=0x0c0ab0b2u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0ab0b4;
P_0c0ab0b4: /* original 3453, guest PC 0x0c0ab0b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab0b4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c0ab0b6;
P_0c0ab0b6: /* original 8b15, guest PC 0x0c0ab0b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab0b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab0e4; }
goto P_0c0ab0b8;
P_0c0ab0b8: /* original e03e, guest PC 0x0c0ab0b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab0b8u; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab0ba;
P_0c0ab0ba: /* original a02a, guest PC 0x0c0ab0ba */
if(!s->budget--) { s->failed_pc=0x0c0ab0bau; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0ab112;
P_0c0ab0bc: /* original 0e45, guest PC 0x0c0ab0bc */
if(!s->budget--) { s->failed_pc=0x0c0ab0bcu; return 0; }
write(ram,r[14]+r[0],r[4],2);
return vf3_matrix_family(0x0c0ab0beu,s,ram);
P_0c0ab0e4: /* original 62e2, guest PC 0x0c0ab0e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab0e4u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0ab0e6;
P_0c0ab0e6: /* original e062, guest PC 0x0c0ab0e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab0e6u; return 0; }
r[0]=0x00000062u;
goto P_0c0ab0e8;
P_0c0ab0e8: /* original d321, guest PC 0x0c0ab0e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab0e8u; return 0; }
r[3]=read(ram,0x0c0ab170u,4);
goto P_0c0ab0ea;
P_0c0ab0ea: /* original 2239, guest PC 0x0c0ab0ea */
if(!s->budget--) { s->failed_pc=0x0c0ab0eau; return 0; }
r[2]&=r[3];
goto P_0c0ab0ec;
P_0c0ab0ec: /* original 2e22, guest PC 0x0c0ab0ec */
if(!s->budget--) { s->failed_pc=0x0c0ab0ecu; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0ab0ee;
P_0c0ab0ee: /* original 51d1, guest PC 0x0c0ab0ee */
if(!s->budget--) { s->failed_pc=0x0c0ab0eeu; return 0; }
r[1]=read(ram,r[13]+4,4);
goto P_0c0ab0f0;
P_0c0ab0f0: /* original 7101, guest PC 0x0c0ab0f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab0f0u; return 0; }
r[1]+=0x00000001u;
goto P_0c0ab0f2;
P_0c0ab0f2: /* original 6213, guest PC 0x0c0ab0f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab0f2u; return 0; }
r[2]=r[1];
goto P_0c0ab0f4;
P_0c0ab0f4: /* original 1d11, guest PC 0x0c0ab0f4 */
if(!s->budget--) { s->failed_pc=0x0c0ab0f4u; return 0; }
write(ram,r[13]+4,r[1],4);
goto P_0c0ab0f6;
P_0c0ab0f6: /* original 0e24, guest PC 0x0c0ab0f6 */
if(!s->budget--) { s->failed_pc=0x0c0ab0f6u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0ab0f8;
P_0c0ab0f8: /* original 4c15, guest PC 0x0c0ab0f8 */
if(!s->budget--) { s->failed_pc=0x0c0ab0f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c0ab0fa;
P_0c0ab0fa: /* original 890a, guest PC 0x0c0ab0fa */
if(!s->budget--) { s->failed_pc=0x0c0ab0fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab112; }
goto P_0c0ab0fc;
P_0c0ab0fc: /* original e300, guest PC 0x0c0ab0fc */
if(!s->budget--) { s->failed_pc=0x0c0ab0fcu; return 0; }
r[3]=0x00000000u;
goto P_0c0ab0fe;
P_0c0ab0fe: /* original e048, guest PC 0x0c0ab0fe */
if(!s->budget--) { s->failed_pc=0x0c0ab0feu; return 0; }
r[0]=0x00000048u;
goto P_0c0ab100;
P_0c0ab100: /* original 1e3e, guest PC 0x0c0ab100 */
if(!s->budget--) { s->failed_pc=0x0c0ab100u; return 0; }
write(ram,r[14]+56,r[3],4);
goto P_0c0ab102;
P_0c0ab102: /* original 02ee, guest PC 0x0c0ab102 */
if(!s->budget--) { s->failed_pc=0x0c0ab102u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ab104;
P_0c0ab104: /* original d31b, guest PC 0x0c0ab104 */
if(!s->budget--) { s->failed_pc=0x0c0ab104u; return 0; }
r[3]=read(ram,0x0c0ab174u,4);
goto P_0c0ab106;
P_0c0ab106: /* original 2239, guest PC 0x0c0ab106 */
if(!s->budget--) { s->failed_pc=0x0c0ab106u; return 0; }
r[2]&=r[3];
goto P_0c0ab108;
P_0c0ab108: /* original 0e26, guest PC 0x0c0ab108 */
if(!s->budget--) { s->failed_pc=0x0c0ab108u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0ab10a;
P_0c0ab10a: /* original 61e2, guest PC 0x0c0ab10a */
if(!s->budget--) { s->failed_pc=0x0c0ab10au; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0ab10c;
P_0c0ab10c: /* original d218, guest PC 0x0c0ab10c */
if(!s->budget--) { s->failed_pc=0x0c0ab10cu; return 0; }
r[2]=read(ram,0x0c0ab170u,4);
goto P_0c0ab10e;
P_0c0ab10e: /* original 2129, guest PC 0x0c0ab10e */
if(!s->budget--) { s->failed_pc=0x0c0ab10eu; return 0; }
r[1]&=r[2];
goto P_0c0ab110;
P_0c0ab110: /* original 2e12, guest PC 0x0c0ab110 */
if(!s->budget--) { s->failed_pc=0x0c0ab110u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0ab112;
P_0c0ab112: /* original 902a, guest PC 0x0c0ab112 */
if(!s->budget--) { s->failed_pc=0x0c0ab112u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab16au,2);
goto P_0c0ab114;
P_0c0ab114: /* original 03bd, guest PC 0x0c0ab114 */
if(!s->budget--) { s->failed_pc=0x0c0ab114u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+r[0],2);
goto P_0c0ab116;
P_0c0ab116: /* original 7004, guest PC 0x0c0ab116 */
if(!s->budget--) { s->failed_pc=0x0c0ab116u; return 0; }
r[0]+=0x00000004u;
goto P_0c0ab118;
P_0c0ab118: /* original 02ed, guest PC 0x0c0ab118 */
if(!s->budget--) { s->failed_pc=0x0c0ab118u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab11a;
P_0c0ab11a: /* original 3320, guest PC 0x0c0ab11a */
if(!s->budget--) { s->failed_pc=0x0c0ab11au; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0ab11c;
P_0c0ab11c: /* original 891d, guest PC 0x0c0ab11c */
if(!s->budget--) { s->failed_pc=0x0c0ab11cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab15a; }
goto P_0c0ab11e;
P_0c0ab11e: /* original 9025, guest PC 0x0c0ab11e */
if(!s->budget--) { s->failed_pc=0x0c0ab11eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab16cu,2);
goto P_0c0ab120;
P_0c0ab120: /* original d315, guest PC 0x0c0ab120 */
if(!s->budget--) { s->failed_pc=0x0c0ab120u; return 0; }
r[3]=read(ram,0x0c0ab178u,4);
goto P_0c0ab122;
P_0c0ab122: /* original 04be, guest PC 0x0c0ab122 */
if(!s->budget--) { s->failed_pc=0x0c0ab122u; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c0ab124;
P_0c0ab124: /* original 2348, guest PC 0x0c0ab124 */
if(!s->budget--) { s->failed_pc=0x0c0ab124u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0ab126;
P_0c0ab126: /* original 8b02, guest PC 0x0c0ab126 */
if(!s->budget--) { s->failed_pc=0x0c0ab126u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab12e; }
goto P_0c0ab128;
P_0c0ab128: /* original d114, guest PC 0x0c0ab128 */
if(!s->budget--) { s->failed_pc=0x0c0ab128u; return 0; }
r[1]=read(ram,0x0c0ab17cu,4);
goto P_0c0ab12a;
P_0c0ab12a: /* original 2148, guest PC 0x0c0ab12a */
if(!s->budget--) { s->failed_pc=0x0c0ab12au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c0ab12c;
P_0c0ab12c: /* original 8915, guest PC 0x0c0ab12c */
if(!s->budget--) { s->failed_pc=0x0c0ab12cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab15a; }
goto P_0c0ab12e;
P_0c0ab12e: /* original e048, guest PC 0x0c0ab12e */
if(!s->budget--) { s->failed_pc=0x0c0ab12eu; return 0; }
r[0]=0x00000048u;
goto P_0c0ab130;
P_0c0ab130: /* original d313, guest PC 0x0c0ab130 */
if(!s->budget--) { s->failed_pc=0x0c0ab130u; return 0; }
r[3]=read(ram,0x0c0ab180u,4);
goto P_0c0ab132;
P_0c0ab132: /* original 02ee, guest PC 0x0c0ab132 */
if(!s->budget--) { s->failed_pc=0x0c0ab132u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ab134;
P_0c0ab134: /* original 2238, guest PC 0x0c0ab134 */
if(!s->budget--) { s->failed_pc=0x0c0ab134u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab136;
P_0c0ab136: /* original 8902, guest PC 0x0c0ab136 */
if(!s->budget--) { s->failed_pc=0x0c0ab136u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab13e; }
goto P_0c0ab138;
P_0c0ab138: /* original d212, guest PC 0x0c0ab138 */
if(!s->budget--) { s->failed_pc=0x0c0ab138u; return 0; }
r[2]=read(ram,0x0c0ab184u,4);
goto P_0c0ab13a;
P_0c0ab13a: /* original 2428, guest PC 0x0c0ab13a */
if(!s->budget--) { s->failed_pc=0x0c0ab13au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0ab13c;
P_0c0ab13c: /* original 8b0d, guest PC 0x0c0ab13c */
if(!s->budget--) { s->failed_pc=0x0c0ab13cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab15a; }
goto P_0c0ab13e;
P_0c0ab13e: /* original d212, guest PC 0x0c0ab13e */
if(!s->budget--) { s->failed_pc=0x0c0ab13eu; return 0; }
r[2]=read(ram,0x0c0ab188u,4);
goto P_0c0ab140;
P_0c0ab140: /* original 65b3, guest PC 0x0c0ab140 */
if(!s->budget--) { s->failed_pc=0x0c0ab140u; return 0; }
r[5]=r[11];
goto P_0c0ab142;
P_0c0ab142: /* original 420b, guest PC 0x0c0ab142 */
if(!s->budget--) { s->failed_pc=0x0c0ab142u; return 0; }
target=r[2];
r[16]=0x0c0ab146u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ab146u) { target=s->pc; goto dispatch; }
goto P_0c0ab146;
P_0c0ab144: /* original 64e3, guest PC 0x0c0ab144 */
if(!s->budget--) { s->failed_pc=0x0c0ab144u; return 0; }
r[4]=r[14];
goto P_0c0ab146;
P_0c0ab146: /* original 6403, guest PC 0x0c0ab146 */
if(!s->budget--) { s->failed_pc=0x0c0ab146u; return 0; }
r[4]=r[0];
goto P_0c0ab148;
P_0c0ab148: /* original 2448, guest PC 0x0c0ab148 */
if(!s->budget--) { s->failed_pc=0x0c0ab148u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0ab14a;
P_0c0ab14a: /* original 8906, guest PC 0x0c0ab14a */
if(!s->budget--) { s->failed_pc=0x0c0ab14au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab15a; }
goto P_0c0ab14c;
P_0c0ab14c: /* original 62e3, guest PC 0x0c0ab14c */
if(!s->budget--) { s->failed_pc=0x0c0ab14cu; return 0; }
r[2]=r[14];
goto P_0c0ab14e;
P_0c0ab14e: /* original e001, guest PC 0x0c0ab14e */
if(!s->budget--) { s->failed_pc=0x0c0ab14eu; return 0; }
r[0]=0x00000001u;
goto P_0c0ab150;
P_0c0ab150: /* original 7238, guest PC 0x0c0ab150 */
if(!s->budget--) { s->failed_pc=0x0c0ab150u; return 0; }
r[2]+=0x00000038u;
goto P_0c0ab152;
P_0c0ab152: /* original 8022, guest PC 0x0c0ab152 */
if(!s->budget--) { s->failed_pc=0x0c0ab152u; return 0; }
write(ram,r[2]+2,r[0],1);
goto P_0c0ab154;
P_0c0ab154: /* original e062, guest PC 0x0c0ab154 */
if(!s->budget--) { s->failed_pc=0x0c0ab154u; return 0; }
r[0]=0x00000062u;
goto P_0c0ab156;
P_0c0ab156: /* original e303, guest PC 0x0c0ab156 */
if(!s->budget--) { s->failed_pc=0x0c0ab156u; return 0; }
r[3]=0x00000003u;
goto P_0c0ab158;
P_0c0ab158: /* original 0e34, guest PC 0x0c0ab158 */
if(!s->budget--) { s->failed_pc=0x0c0ab158u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ab15a;
P_0c0ab15a: /* original 7f10, guest PC 0x0c0ab15a */
if(!s->budget--) { s->failed_pc=0x0c0ab15au; return 0; }
r[15]+=0x00000010u;
goto P_0c0ab15c;
P_0c0ab15c: /* original 4f26, guest PC 0x0c0ab15c */
if(!s->budget--) { s->failed_pc=0x0c0ab15cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ab15e;
P_0c0ab15e: /* original 6af6, guest PC 0x0c0ab15e */
if(!s->budget--) { s->failed_pc=0x0c0ab15eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ab160;
P_0c0ab160: /* original 6bf6, guest PC 0x0c0ab160 */
if(!s->budget--) { s->failed_pc=0x0c0ab160u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ab162;
P_0c0ab162: /* original 6cf6, guest PC 0x0c0ab162 */
if(!s->budget--) { s->failed_pc=0x0c0ab162u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ab164;
P_0c0ab164: /* original 6df6, guest PC 0x0c0ab164 */
if(!s->budget--) { s->failed_pc=0x0c0ab164u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ab166;
P_0c0ab166: /* original 000b, guest PC 0x0c0ab166 */
if(!s->budget--) { s->failed_pc=0x0c0ab166u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ab168: /* original 6ef6, guest PC 0x0c0ab168 */
if(!s->budget--) { s->failed_pc=0x0c0ab168u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ab16au,s,ram);
P_0c0ab35a: /* original 4f22, guest PC 0x0c0ab35a */
if(!s->budget--) { s->failed_pc=0x0c0ab35au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ab35c;
P_0c0ab35c: /* original d34a, guest PC 0x0c0ab35c */
if(!s->budget--) { s->failed_pc=0x0c0ab35cu; return 0; }
r[3]=read(ram,0x0c0ab488u,4);
goto P_0c0ab35e;
P_0c0ab35e: /* original 7fd8, guest PC 0x0c0ab35e */
if(!s->budget--) { s->failed_pc=0x0c0ab35eu; return 0; }
r[15]+=0xffffffd8u;
goto P_0c0ab360;
P_0c0ab360: /* original 1f39, guest PC 0x0c0ab360 */
if(!s->budget--) { s->failed_pc=0x0c0ab360u; return 0; }
write(ram,r[15]+36,r[3],4);
goto P_0c0ab362;
P_0c0ab362: /* original d24a, guest PC 0x0c0ab362 */
if(!s->budget--) { s->failed_pc=0x0c0ab362u; return 0; }
r[2]=read(ram,0x0c0ab48cu,4);
goto P_0c0ab364;
P_0c0ab364: /* original 1f27, guest PC 0x0c0ab364 */
if(!s->budget--) { s->failed_pc=0x0c0ab364u; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c0ab366;
P_0c0ab366: /* original 63e2, guest PC 0x0c0ab366 */
if(!s->budget--) { s->failed_pc=0x0c0ab366u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0ab368;
P_0c0ab368: /* original 0cee, guest PC 0x0c0ab368 */
if(!s->budget--) { s->failed_pc=0x0c0ab368u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c0ab36a;
P_0c0ab36a: /* original 1f36, guest PC 0x0c0ab36a */
if(!s->budget--) { s->failed_pc=0x0c0ab36au; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0ab36c;
P_0c0ab36c: /* original 53d1, guest PC 0x0c0ab36c */
if(!s->budget--) { s->failed_pc=0x0c0ab36cu; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0ab36e;
P_0c0ab36e: /* original 2338, guest PC 0x0c0ab36e */
if(!s->budget--) { s->failed_pc=0x0c0ab36eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0ab370;
P_0c0ab370: /* original 8d05, guest PC 0x0c0ab370 */
if(!s->budget--) { s->failed_pc=0x0c0ab370u; return 0; }
cond=r[17]&1u;
fr[13]=0x3f800000u;
if(cond) { goto P_0c0ab37e; }
goto P_0c0ab374;
P_0c0ab372: /* original fd9d, guest PC 0x0c0ab372 */
if(!s->budget--) { s->failed_pc=0x0c0ab372u; return 0; }
fr[13]=0x3f800000u;
goto P_0c0ab374;
P_0c0ab374: /* original 50d1, guest PC 0x0c0ab374 */
if(!s->budget--) { s->failed_pc=0x0c0ab374u; return 0; }
r[0]=read(ram,r[13]+4,4);
goto P_0c0ab376;
P_0c0ab376: /* original 8801, guest PC 0x0c0ab376 */
if(!s->budget--) { s->failed_pc=0x0c0ab376u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0ab378;
P_0c0ab378: /* original 8b01, guest PC 0x0c0ab378 */
if(!s->budget--) { s->failed_pc=0x0c0ab378u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab37e; }
goto P_0c0ab37a;
P_0c0ab37a: /* original a1cf, guest PC 0x0c0ab37a */
if(!s->budget--) { s->failed_pc=0x0c0ab37au; return 0; }
goto P_0c0ab71c;
P_0c0ab37c: /* original 0009, guest PC 0x0c0ab37c */
if(!s->budget--) { s->failed_pc=0x0c0ab37cu; return 0; }
goto P_0c0ab37e;
P_0c0ab37e: /* original e03e, guest PC 0x0c0ab37e */
if(!s->budget--) { s->failed_pc=0x0c0ab37eu; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab380;
P_0c0ab380: /* original 03ed, guest PC 0x0c0ab380 */
if(!s->budget--) { s->failed_pc=0x0c0ab380u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab382;
P_0c0ab382: /* original 633d, guest PC 0x0c0ab382 */
if(!s->budget--) { s->failed_pc=0x0c0ab382u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0ab384;
P_0c0ab384: /* original 1f32, guest PC 0x0c0ab384 */
if(!s->budget--) { s->failed_pc=0x0c0ab384u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0ab386;
P_0c0ab386: /* original 9076, guest PC 0x0c0ab386 */
if(!s->budget--) { s->failed_pc=0x0c0ab386u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab476u,2);
goto P_0c0ab388;
P_0c0ab388: /* original 02ed, guest PC 0x0c0ab388 */
if(!s->budget--) { s->failed_pc=0x0c0ab388u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab38a;
P_0c0ab38a: /* original 622d, guest PC 0x0c0ab38a */
if(!s->budget--) { s->failed_pc=0x0c0ab38au; return 0; }
r[2]=r[2]&65535u;
goto P_0c0ab38c;
P_0c0ab38c: /* original 1f24, guest PC 0x0c0ab38c */
if(!s->budget--) { s->failed_pc=0x0c0ab38cu; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0ab38e;
P_0c0ab38e: /* original 53f2, guest PC 0x0c0ab38e */
if(!s->budget--) { s->failed_pc=0x0c0ab38eu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0ab390;
P_0c0ab390: /* original 3322, guest PC 0x0c0ab390 */
if(!s->budget--) { s->failed_pc=0x0c0ab390u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0ab392;
P_0c0ab392: /* original 8901, guest PC 0x0c0ab392 */
if(!s->budget--) { s->failed_pc=0x0c0ab392u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab398; }
goto P_0c0ab394;
P_0c0ab394: /* original a248, guest PC 0x0c0ab394 */
if(!s->budget--) { s->failed_pc=0x0c0ab394u; return 0; }
goto P_0c0ab828;
P_0c0ab396: /* original 0009, guest PC 0x0c0ab396 */
if(!s->budget--) { s->failed_pc=0x0c0ab396u; return 0; }
goto P_0c0ab398;
P_0c0ab398: /* original d23d, guest PC 0x0c0ab398 */
if(!s->budget--) { s->failed_pc=0x0c0ab398u; return 0; }
r[2]=read(ram,0x0c0ab490u,4);
goto P_0c0ab39a;
P_0c0ab39a: /* original e048, guest PC 0x0c0ab39a */
if(!s->budget--) { s->failed_pc=0x0c0ab39au; return 0; }
r[0]=0x00000048u;
goto P_0c0ab39c;
P_0c0ab39c: /* original 2c29, guest PC 0x0c0ab39c */
if(!s->budget--) { s->failed_pc=0x0c0ab39cu; return 0; }
r[12]&=r[2];
goto P_0c0ab39e;
P_0c0ab39e: /* original 0ec6, guest PC 0x0c0ab39e */
if(!s->budget--) { s->failed_pc=0x0c0ab39eu; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c0ab3a0;
P_0c0ab3a0: /* original 63d2, guest PC 0x0c0ab3a0 */
if(!s->budget--) { s->failed_pc=0x0c0ab3a0u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ab3a2;
P_0c0ab3a2: /* original 633d, guest PC 0x0c0ab3a2 */
if(!s->budget--) { s->failed_pc=0x0c0ab3a2u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0ab3a4;
P_0c0ab3a4: /* original 2338, guest PC 0x0c0ab3a4 */
if(!s->budget--) { s->failed_pc=0x0c0ab3a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0ab3a6;
P_0c0ab3a6: /* original 8d09, guest PC 0x0c0ab3a6 */
if(!s->budget--) { s->failed_pc=0x0c0ab3a6u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+16,r[3],4);
if(cond) { goto P_0c0ab3bc; }
goto P_0c0ab3aa;
P_0c0ab3a8: /* original 1f34, guest PC 0x0c0ab3a8 */
if(!s->budget--) { s->failed_pc=0x0c0ab3a8u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0ab3aa;
P_0c0ab3aa: /* original e03c, guest PC 0x0c0ab3aa */
if(!s->budget--) { s->failed_pc=0x0c0ab3aau; return 0; }
r[0]=0x0000003cu;
goto P_0c0ab3ac;
P_0c0ab3ac: /* original 01ed, guest PC 0x0c0ab3ac */
if(!s->budget--) { s->failed_pc=0x0c0ab3acu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab3ae;
P_0c0ab3ae: /* original 611d, guest PC 0x0c0ab3ae */
if(!s->budget--) { s->failed_pc=0x0c0ab3aeu; return 0; }
r[1]=r[1]&65535u;
goto P_0c0ab3b0;
P_0c0ab3b0: /* original 3310, guest PC 0x0c0ab3b0 */
if(!s->budget--) { s->failed_pc=0x0c0ab3b0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c0ab3b2;
P_0c0ab3b2: /* original 8903, guest PC 0x0c0ab3b2 */
if(!s->budget--) { s->failed_pc=0x0c0ab3b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab3bc; }
goto P_0c0ab3b4;
P_0c0ab3b4: /* original d337, guest PC 0x0c0ab3b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab3b4u; return 0; }
r[3]=read(ram,0x0c0ab494u,4);
goto P_0c0ab3b6;
P_0c0ab3b6: /* original 55f4, guest PC 0x0c0ab3b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab3b6u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c0ab3b8;
P_0c0ab3b8: /* original 430b, guest PC 0x0c0ab3b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab3b8u; return 0; }
target=r[3];
r[16]=0x0c0ab3bcu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ab3bcu) { target=s->pc; goto dispatch; }
goto P_0c0ab3bc;
P_0c0ab3ba: /* original 64e3, guest PC 0x0c0ab3ba */
if(!s->budget--) { s->failed_pc=0x0c0ab3bau; return 0; }
r[4]=r[14];
goto P_0c0ab3bc;
P_0c0ab3bc: /* original 905c, guest PC 0x0c0ab3bc */
if(!s->budget--) { s->failed_pc=0x0c0ab3bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab478u,2);
goto P_0c0ab3be;
P_0c0ab3be: /* original 02ec, guest PC 0x0c0ab3be */
if(!s->budget--) { s->failed_pc=0x0c0ab3beu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ab3c0;
P_0c0ab3c0: /* original e064, guest PC 0x0c0ab3c0 */
if(!s->budget--) { s->failed_pc=0x0c0ab3c0u; return 0; }
r[0]=0x00000064u;
goto P_0c0ab3c2;
P_0c0ab3c2: /* original 622c, guest PC 0x0c0ab3c2 */
if(!s->budget--) { s->failed_pc=0x0c0ab3c2u; return 0; }
r[2]=r[2]&255u;
goto P_0c0ab3c4;
P_0c0ab3c4: /* original 6323, guest PC 0x0c0ab3c4 */
if(!s->budget--) { s->failed_pc=0x0c0ab3c4u; return 0; }
r[3]=r[2];
goto P_0c0ab3c6;
P_0c0ab3c6: /* original 1f22, guest PC 0x0c0ab3c6 */
if(!s->budget--) { s->failed_pc=0x0c0ab3c6u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0ab3c8;
P_0c0ab3c8: /* original 0e35, guest PC 0x0c0ab3c8 */
if(!s->budget--) { s->failed_pc=0x0c0ab3c8u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0ab3ca;
P_0c0ab3ca: /* original 52f2, guest PC 0x0c0ab3ca */
if(!s->budget--) { s->failed_pc=0x0c0ab3cau; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0ab3cc;
P_0c0ab3cc: /* original f28d, guest PC 0x0c0ab3cc */
if(!s->budget--) { s->failed_pc=0x0c0ab3ccu; return 0; }
fr[2]=0;
goto P_0c0ab3ce;
P_0c0ab3ce: /* original 425a, guest PC 0x0c0ab3ce */
if(!s->budget--) { s->failed_pc=0x0c0ab3ceu; return 0; }
r[53]=r[2];
goto P_0c0ab3d0;
P_0c0ab3d0: /* original f32d, guest PC 0x0c0ab3d0 */
if(!s->budget--) { s->failed_pc=0x0c0ab3d0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0ab3d2;
P_0c0ab3d2: /* original f235, guest PC 0x0c0ab3d2 */
if(!s->budget--) { s->failed_pc=0x0c0ab3d2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0ab3d4;
P_0c0ab3d4: /* original 8f03, guest PC 0x0c0ab3d4 */
if(!s->budget--) { s->failed_pc=0x0c0ab3d4u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,3);
if(!cond) { goto P_0c0ab3de; }
goto P_0c0ab3d8;
P_0c0ab3d6: /* original f43c, guest PC 0x0c0ab3d6 */
if(!s->budget--) { s->failed_pc=0x0c0ab3d6u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0ab3d8;
P_0c0ab3d8: /* original c72f, guest PC 0x0c0ab3d8 */
if(!s->budget--) { s->failed_pc=0x0c0ab3d8u; return 0; }
r[0]=0x0c0ab498u;
goto P_0c0ab3da;
P_0c0ab3da: /* original f308, guest PC 0x0c0ab3da */
if(!s->budget--) { s->failed_pc=0x0c0ab3dau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0ab3dc;
P_0c0ab3dc: /* original f430, guest PC 0x0c0ab3dc */
if(!s->budget--) { s->failed_pc=0x0c0ab3dcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0ab3de;
P_0c0ab3de: /* original 53f9, guest PC 0x0c0ab3de */
if(!s->budget--) { s->failed_pc=0x0c0ab3deu; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c0ab3e0;
P_0c0ab3e0: /* original 904b, guest PC 0x0c0ab3e0 */
if(!s->budget--) { s->failed_pc=0x0c0ab3e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab47au,2);
goto P_0c0ab3e2;
P_0c0ab3e2: /* original f138, guest PC 0x0c0ab3e2 */
if(!s->budget--) { s->failed_pc=0x0c0ab3e2u; return 0; }
vf3_matrix_load(s,ram,1,r[3]);
goto P_0c0ab3e4;
P_0c0ab3e4: /* original f2e6, guest PC 0x0c0ab3e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab3e4u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ab3e6;
P_0c0ab3e6: /* original c72d, guest PC 0x0c0ab3e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab3e6u; return 0; }
r[0]=0x0c0ab49cu;
goto P_0c0ab3e8;
P_0c0ab3e8: /* original f34c, guest PC 0x0c0ab3e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab3e8u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0ab3ea;
P_0c0ab3ea: /* original f3d0, guest PC 0x0c0ab3ea */
if(!s->budget--) { s->failed_pc=0x0c0ab3eau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[13],r[18],'+');
goto P_0c0ab3ec;
P_0c0ab3ec: /* original f121, guest PC 0x0c0ab3ec */
if(!s->budget--) { s->failed_pc=0x0c0ab3ecu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'-');
goto P_0c0ab3ee;
P_0c0ab3ee: /* original f208, guest PC 0x0c0ab3ee */
if(!s->budget--) { s->failed_pc=0x0c0ab3eeu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0ab3f0;
P_0c0ab3f0: /* original 9044, guest PC 0x0c0ab3f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab3f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab47cu,2);
goto P_0c0ab3f2;
P_0c0ab3f2: /* original f312, guest PC 0x0c0ab3f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab3f2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[1],r[18],'*');
goto P_0c0ab3f4;
P_0c0ab3f4: /* original f53c, guest PC 0x0c0ab3f4 */
if(!s->budget--) { s->failed_pc=0x0c0ab3f4u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0ab3f6;
P_0c0ab3f6: /* original f522, guest PC 0x0c0ab3f6 */
if(!s->budget--) { s->failed_pc=0x0c0ab3f6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'*');
goto P_0c0ab3f8;
P_0c0ab3f8: /* original f3e6, guest PC 0x0c0ab3f8 */
if(!s->budget--) { s->failed_pc=0x0c0ab3f8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab3fa;
P_0c0ab3fa: /* original 9040, guest PC 0x0c0ab3fa */
if(!s->budget--) { s->failed_pc=0x0c0ab3fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab47eu,2);
goto P_0c0ab3fc;
P_0c0ab3fc: /* original f1e6, guest PC 0x0c0ab3fc */
if(!s->budget--) { s->failed_pc=0x0c0ab3fcu; return 0; }
vf3_matrix_load(s,ram,1,r[14]+r[0]);
goto P_0c0ab3fe;
P_0c0ab3fe: /* original 903f, guest PC 0x0c0ab3fe */
if(!s->budget--) { s->failed_pc=0x0c0ab3feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab480u,2);
goto P_0c0ab400;
P_0c0ab400: /* original f130, guest PC 0x0c0ab400 */
if(!s->budget--) { s->failed_pc=0x0c0ab400u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'+');
goto P_0c0ab402;
P_0c0ab402: /* original f3e6, guest PC 0x0c0ab402 */
if(!s->budget--) { s->failed_pc=0x0c0ab402u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab404;
P_0c0ab404: /* original e028, guest PC 0x0c0ab404 */
if(!s->budget--) { s->failed_pc=0x0c0ab404u; return 0; }
r[0]=0x00000028u;
goto P_0c0ab406;
P_0c0ab406: /* original f131, guest PC 0x0c0ab406 */
if(!s->budget--) { s->failed_pc=0x0c0ab406u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'-');
goto P_0c0ab408;
P_0c0ab408: /* original f143, guest PC 0x0c0ab408 */
if(!s->budget--) { s->failed_pc=0x0c0ab408u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'/');
goto P_0c0ab40a;
P_0c0ab40a: /* original f510, guest PC 0x0c0ab40a */
if(!s->budget--) { s->failed_pc=0x0c0ab40au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[1],r[18],'+');
goto P_0c0ab40c;
P_0c0ab40c: /* original fe57, guest PC 0x0c0ab40c */
if(!s->budget--) { s->failed_pc=0x0c0ab40cu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0ab40e;
P_0c0ab40e: /* original d326, guest PC 0x0c0ab40e */
if(!s->budget--) { s->failed_pc=0x0c0ab40eu; return 0; }
r[3]=read(ram,0x0c0ab4a8u,4);
goto P_0c0ab410;
P_0c0ab410: /* original 62d2, guest PC 0x0c0ab410 */
if(!s->budget--) { s->failed_pc=0x0c0ab410u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ab412;
P_0c0ab412: /* original dc24, guest PC 0x0c0ab412 */
if(!s->budget--) { s->failed_pc=0x0c0ab412u; return 0; }
r[12]=read(ram,0x0c0ab4a4u,4);
goto P_0c0ab414;
P_0c0ab414: /* original da22, guest PC 0x0c0ab414 */
if(!s->budget--) { s->failed_pc=0x0c0ab414u; return 0; }
r[10]=read(ram,0x0c0ab4a0u,4);
goto P_0c0ab416;
P_0c0ab416: /* original 2238, guest PC 0x0c0ab416 */
if(!s->budget--) { s->failed_pc=0x0c0ab416u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab418;
P_0c0ab418: /* original 8b51, guest PC 0x0c0ab418 */
if(!s->budget--) { s->failed_pc=0x0c0ab418u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab4be; }
goto P_0c0ab41a;
P_0c0ab41a: /* original 9032, guest PC 0x0c0ab41a */
if(!s->budget--) { s->failed_pc=0x0c0ab41au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab482u,2);
goto P_0c0ab41c;
P_0c0ab41c: /* original f28d, guest PC 0x0c0ab41c */
if(!s->budget--) { s->failed_pc=0x0c0ab41cu; return 0; }
fr[2]=0;
goto P_0c0ab41e;
P_0c0ab41e: /* original ffe6, guest PC 0x0c0ab41e */
if(!s->budget--) { s->failed_pc=0x0c0ab41eu; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0ab420;
P_0c0ab420: /* original c722, guest PC 0x0c0ab420 */
if(!s->budget--) { s->failed_pc=0x0c0ab420u; return 0; }
r[0]=0x0c0ab4acu;
goto P_0c0ab422;
P_0c0ab422: /* original f308, guest PC 0x0c0ab422 */
if(!s->budget--) { s->failed_pc=0x0c0ab422u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0ab424;
P_0c0ab424: /* original ff24, guest PC 0x0c0ab424 */
if(!s->budget--) { s->failed_pc=0x0c0ab424u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])==as_float(fr[2]))!=0);
goto P_0c0ab426;
P_0c0ab426: /* original f54c, guest PC 0x0c0ab426 */
if(!s->budget--) { s->failed_pc=0x0c0ab426u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0ab428;
P_0c0ab428: /* original 8d0d, guest PC 0x0c0ab428 */
if(!s->budget--) { s->failed_pc=0x0c0ab428u; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
if(cond) { goto P_0c0ab446; }
goto P_0c0ab42c;
P_0c0ab42a: /* original f532, guest PC 0x0c0ab42a */
if(!s->budget--) { s->failed_pc=0x0c0ab42au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0ab42c;
P_0c0ab42c: /* original f38d, guest PC 0x0c0ab42c */
if(!s->budget--) { s->failed_pc=0x0c0ab42cu; return 0; }
fr[3]=0;
goto P_0c0ab42e;
P_0c0ab42e: /* original f3f5, guest PC 0x0c0ab42e */
if(!s->budget--) { s->failed_pc=0x0c0ab42eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0ab430;
P_0c0ab430: /* original 9028, guest PC 0x0c0ab430 */
if(!s->budget--) { s->failed_pc=0x0c0ab430u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab484u,2);
goto P_0c0ab432;
P_0c0ab432: /* original 8d02, guest PC 0x0c0ab432 */
if(!s->budget--) { s->failed_pc=0x0c0ab432u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,6,r[14]+r[0]);
if(cond) { goto P_0c0ab43a; }
goto P_0c0ab436;
P_0c0ab434: /* original f6e6, guest PC 0x0c0ab434 */
if(!s->budget--) { s->failed_pc=0x0c0ab434u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0ab436;
P_0c0ab436: /* original 9026, guest PC 0x0c0ab436 */
if(!s->budget--) { s->failed_pc=0x0c0ab436u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab486u,2);
goto P_0c0ab438;
P_0c0ab438: /* original f6e6, guest PC 0x0c0ab438 */
if(!s->budget--) { s->failed_pc=0x0c0ab438u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0ab43a;
P_0c0ab43a: /* original c71d, guest PC 0x0c0ab43a */
if(!s->budget--) { s->failed_pc=0x0c0ab43au; return 0; }
r[0]=0x0c0ab4b0u;
goto P_0c0ab43c;
P_0c0ab43c: /* original f308, guest PC 0x0c0ab43c */
if(!s->budget--) { s->failed_pc=0x0c0ab43cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0ab43e;
P_0c0ab43e: /* original f630, guest PC 0x0c0ab43e */
if(!s->budget--) { s->failed_pc=0x0c0ab43eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
goto P_0c0ab440;
P_0c0ab440: /* original f565, guest PC 0x0c0ab440 */
if(!s->budget--) { s->failed_pc=0x0c0ab440u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[6]))!=0);
goto P_0c0ab442;
P_0c0ab442: /* original 8b00, guest PC 0x0c0ab442 */
if(!s->budget--) { s->failed_pc=0x0c0ab442u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab446; }
goto P_0c0ab444;
P_0c0ab444: /* original f56c, guest PC 0x0c0ab444 */
if(!s->budget--) { s->failed_pc=0x0c0ab444u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c0ab446;
P_0c0ab446: /* original f543, guest PC 0x0c0ab446 */
if(!s->budget--) { s->failed_pc=0x0c0ab446u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'/');
goto P_0c0ab448;
P_0c0ab448: /* original 85ef, guest PC 0x0c0ab448 */
if(!s->budget--) { s->failed_pc=0x0c0ab448u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+30,2);
goto P_0c0ab44a;
P_0c0ab44a: /* original 640f, guest PC 0x0c0ab44a */
if(!s->budget--) { s->failed_pc=0x0c0ab44au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0ab44c;
P_0c0ab44c: /* original 1f06, guest PC 0x0c0ab44c */
if(!s->budget--) { s->failed_pc=0x0c0ab44cu; return 0; }
write(ram,r[15]+24,r[0],4);
goto P_0c0ab44e;
P_0c0ab44e: /* original ff52, guest PC 0x0c0ab44e */
if(!s->budget--) { s->failed_pc=0x0c0ab44eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[5],r[18],'*');
goto P_0c0ab450;
P_0c0ab450: /* original 4a0b, guest PC 0x0c0ab450 */
if(!s->budget--) { s->failed_pc=0x0c0ab450u; return 0; }
target=r[10];
r[16]=0x0c0ab454u;
write(ram,r[15]+28,r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ab454u) { target=s->pc; goto dispatch; }
goto P_0c0ab454;
P_0c0ab452: /* original 1f47, guest PC 0x0c0ab452 */
if(!s->budget--) { s->failed_pc=0x0c0ab452u; return 0; }
write(ram,r[15]+28,r[4],4);
goto P_0c0ab454;
P_0c0ab454: /* original e020, guest PC 0x0c0ab454 */
if(!s->budget--) { s->failed_pc=0x0c0ab454u; return 0; }
r[0]=0x00000020u;
goto P_0c0ab456;
P_0c0ab456: /* original ff0a, guest PC 0x0c0ab456 */
if(!s->budget--) { s->failed_pc=0x0c0ab456u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0ab458;
P_0c0ab458: /* original f2fc, guest PC 0x0c0ab458 */
if(!s->budget--) { s->failed_pc=0x0c0ab458u; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c0ab45a;
P_0c0ab45a: /* original f30c, guest PC 0x0c0ab45a */
if(!s->budget--) { s->failed_pc=0x0c0ab45au; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0ab45c;
P_0c0ab45c: /* original f232, guest PC 0x0c0ab45c */
if(!s->budget--) { s->failed_pc=0x0c0ab45cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0ab45e;
P_0c0ab45e: /* original f24d, guest PC 0x0c0ab45e */
if(!s->budget--) { s->failed_pc=0x0c0ab45eu; return 0; }
fr[2]^=0x80000000u;
goto P_0c0ab460;
P_0c0ab460: /* original ff27, guest PC 0x0c0ab460 */
if(!s->budget--) { s->failed_pc=0x0c0ab460u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0ab462;
P_0c0ab462: /* original 4c0b, guest PC 0x0c0ab462 */
if(!s->budget--) { s->failed_pc=0x0c0ab462u; return 0; }
target=r[12];
r[16]=0x0c0ab466u;
r[4]=read(ram,r[15]+28,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ab466u) { target=s->pc; goto dispatch; }
goto P_0c0ab466;
P_0c0ab464: /* original 54f7, guest PC 0x0c0ab464 */
if(!s->budget--) { s->failed_pc=0x0c0ab464u; return 0; }
r[4]=read(ram,r[15]+28,4);
goto P_0c0ab466;
P_0c0ab466: /* original ff02, guest PC 0x0c0ab466 */
if(!s->budget--) { s->failed_pc=0x0c0ab466u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[0],r[18],'*');
goto P_0c0ab468;
P_0c0ab468: /* original e020, guest PC 0x0c0ab468 */
if(!s->budget--) { s->failed_pc=0x0c0ab468u; return 0; }
r[0]=0x00000020u;
goto P_0c0ab46a;
P_0c0ab46a: /* original ff0a, guest PC 0x0c0ab46a */
if(!s->budget--) { s->failed_pc=0x0c0ab46au; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0ab46c;
P_0c0ab46c: /* original f3f6, guest PC 0x0c0ab46c */
if(!s->budget--) { s->failed_pc=0x0c0ab46cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab46e;
P_0c0ab46e: /* original f4fc, guest PC 0x0c0ab46e */
if(!s->budget--) { s->failed_pc=0x0c0ab46eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0ab470;
P_0c0ab470: /* original f44d, guest PC 0x0c0ab470 */
if(!s->budget--) { s->failed_pc=0x0c0ab470u; return 0; }
fr[4]^=0x80000000u;
goto P_0c0ab472;
P_0c0ab472: /* original a01f, guest PC 0x0c0ab472 */
if(!s->budget--) { s->failed_pc=0x0c0ab472u; return 0; }
goto P_0c0ab4b4;
P_0c0ab474: /* original 0009, guest PC 0x0c0ab474 */
if(!s->budget--) { s->failed_pc=0x0c0ab474u; return 0; }
return vf3_matrix_family(0x0c0ab476u,s,ram);
P_0c0ab4b4: /* original e024, guest PC 0x0c0ab4b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab4b4u; return 0; }
r[0]=0x00000024u;
goto P_0c0ab4b6;
P_0c0ab4b6: /* original fe37, guest PC 0x0c0ab4b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab4b6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab4b8;
P_0c0ab4b8: /* original e02c, guest PC 0x0c0ab4b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab4b8u; return 0; }
r[0]=0x0000002cu;
goto P_0c0ab4ba;
P_0c0ab4ba: /* original a0fd, guest PC 0x0c0ab4ba */
if(!s->budget--) { s->failed_pc=0x0c0ab4bau; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab6b8;
P_0c0ab4bc: /* original fe47, guest PC 0x0c0ab4bc */
if(!s->budget--) { s->failed_pc=0x0c0ab4bcu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab4be;
P_0c0ab4be: /* original 9080, guest PC 0x0c0ab4be */
if(!s->budget--) { s->failed_pc=0x0c0ab4beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab5c2u,2);
goto P_0c0ab4c0;
P_0c0ab4c0: /* original 62b2, guest PC 0x0c0ab4c0 */
if(!s->budget--) { s->failed_pc=0x0c0ab4c0u; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c0ab4c2;
P_0c0ab4c2: /* original d342, guest PC 0x0c0ab4c2 */
if(!s->budget--) { s->failed_pc=0x0c0ab4c2u; return 0; }
r[3]=read(ram,0x0c0ab5ccu,4);
goto P_0c0ab4c4;
P_0c0ab4c4: /* original fee6, guest PC 0x0c0ab4c4 */
if(!s->budget--) { s->failed_pc=0x0c0ab4c4u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c0ab4c6;
P_0c0ab4c6: /* original 7008, guest PC 0x0c0ab4c6 */
if(!s->budget--) { s->failed_pc=0x0c0ab4c6u; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab4c8;
P_0c0ab4c8: /* original 2238, guest PC 0x0c0ab4c8 */
if(!s->budget--) { s->failed_pc=0x0c0ab4c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab4ca;
P_0c0ab4ca: /* original 8f07, guest PC 0x0c0ab4ca */
if(!s->budget--) { s->failed_pc=0x0c0ab4cau; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,15,r[14]+r[0]);
if(!cond) { goto P_0c0ab4dc; }
goto P_0c0ab4ce;
P_0c0ab4cc: /* original ffe6, guest PC 0x0c0ab4cc */
if(!s->budget--) { s->failed_pc=0x0c0ab4ccu; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0ab4ce;
P_0c0ab4ce: /* original 9079, guest PC 0x0c0ab4ce */
if(!s->budget--) { s->failed_pc=0x0c0ab4ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab5c4u,2);
goto P_0c0ab4d0;
P_0c0ab4d0: /* original 00bc, guest PC 0x0c0ab4d0 */
if(!s->budget--) { s->failed_pc=0x0c0ab4d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0ab4d2;
P_0c0ab4d2: /* original 600c, guest PC 0x0c0ab4d2 */
if(!s->budget--) { s->failed_pc=0x0c0ab4d2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ab4d4;
P_0c0ab4d4: /* original c840, guest PC 0x0c0ab4d4 */
if(!s->budget--) { s->failed_pc=0x0c0ab4d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0ab4d6;
P_0c0ab4d6: /* original 8b01, guest PC 0x0c0ab4d6 */
if(!s->budget--) { s->failed_pc=0x0c0ab4d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab4dc; }
goto P_0c0ab4d8;
P_0c0ab4d8: /* original a084, guest PC 0x0c0ab4d8 */
if(!s->budget--) { s->failed_pc=0x0c0ab4d8u; return 0; }
goto P_0c0ab5e4;
P_0c0ab4da: /* original 0009, guest PC 0x0c0ab4da */
if(!s->budget--) { s->failed_pc=0x0c0ab4dau; return 0; }
goto P_0c0ab4dc;
P_0c0ab4dc: /* original 50f7, guest PC 0x0c0ab4dc */
if(!s->budget--) { s->failed_pc=0x0c0ab4dcu; return 0; }
r[0]=read(ram,r[15]+28,4);
goto P_0c0ab4de;
P_0c0ab4de: /* original e11c, guest PC 0x0c0ab4de */
if(!s->budget--) { s->failed_pc=0x0c0ab4deu; return 0; }
r[1]=0x0000001cu;
goto P_0c0ab4e0;
P_0c0ab4e0: /* original 001c, guest PC 0x0c0ab4e0 */
if(!s->budget--) { s->failed_pc=0x0c0ab4e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0ab4e2;
P_0c0ab4e2: /* original 600c, guest PC 0x0c0ab4e2 */
if(!s->budget--) { s->failed_pc=0x0c0ab4e2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ab4e4;
P_0c0ab4e4: /* original c90f, guest PC 0x0c0ab4e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab4e4u; return 0; }
r[0]&=15u;
goto P_0c0ab4e6;
P_0c0ab4e6: /* original 880f, guest PC 0x0c0ab4e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab4e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c0ab4e8;
P_0c0ab4e8: /* original 8b31, guest PC 0x0c0ab4e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab4e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab54e; }
goto P_0c0ab4ea;
P_0c0ab4ea: /* original e06a, guest PC 0x0c0ab4ea */
if(!s->budget--) { s->failed_pc=0x0c0ab4eau; return 0; }
r[0]=0x0000006au;
goto P_0c0ab4ec;
P_0c0ab4ec: /* original 03ed, guest PC 0x0c0ab4ec */
if(!s->budget--) { s->failed_pc=0x0c0ab4ecu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab4ee;
P_0c0ab4ee: /* original 1f32, guest PC 0x0c0ab4ee */
if(!s->budget--) { s->failed_pc=0x0c0ab4eeu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0ab4f0;
P_0c0ab4f0: /* original 4a0b, guest PC 0x0c0ab4f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab4f0u; return 0; }
target=r[10];
r[16]=0x0c0ab4f4u;
r[4]=(uint32_t)(int32_t)(int16_t)r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ab4f4u) { target=s->pc; goto dispatch; }
goto P_0c0ab4f4;
P_0c0ab4f2: /* original 643f, guest PC 0x0c0ab4f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab4f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c0ab4f4;
P_0c0ab4f4: /* original ff0a, guest PC 0x0c0ab4f4 */
if(!s->budget--) { s->failed_pc=0x0c0ab4f4u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0ab4f6;
P_0c0ab4f6: /* original 54f2, guest PC 0x0c0ab4f6 */
if(!s->budget--) { s->failed_pc=0x0c0ab4f6u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0ab4f8;
P_0c0ab4f8: /* original 4c0b, guest PC 0x0c0ab4f8 */
if(!s->budget--) { s->failed_pc=0x0c0ab4f8u; return 0; }
target=r[12];
r[16]=0x0c0ab4fcu;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ab4fcu) { target=s->pc; goto dispatch; }
goto P_0c0ab4fc;
P_0c0ab4fa: /* original 644f, guest PC 0x0c0ab4fa */
if(!s->budget--) { s->failed_pc=0x0c0ab4fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0ab4fc;
P_0c0ab4fc: /* original e004, guest PC 0x0c0ab4fc */
if(!s->budget--) { s->failed_pc=0x0c0ab4fcu; return 0; }
r[0]=0x00000004u;
goto P_0c0ab4fe;
P_0c0ab4fe: /* original ff07, guest PC 0x0c0ab4fe */
if(!s->budget--) { s->failed_pc=0x0c0ab4feu; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0ab500;
P_0c0ab500: /* original e050, guest PC 0x0c0ab500 */
if(!s->budget--) { s->failed_pc=0x0c0ab500u; return 0; }
r[0]=0x00000050u;
goto P_0c0ab502;
P_0c0ab502: /* original 02ee, guest PC 0x0c0ab502 */
if(!s->budget--) { s->failed_pc=0x0c0ab502u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ab504;
P_0c0ab504: /* original d332, guest PC 0x0c0ab504 */
if(!s->budget--) { s->failed_pc=0x0c0ab504u; return 0; }
r[3]=read(ram,0x0c0ab5d0u,4);
goto P_0c0ab506;
P_0c0ab506: /* original 2238, guest PC 0x0c0ab506 */
if(!s->budget--) { s->failed_pc=0x0c0ab506u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab508;
P_0c0ab508: /* original 8902, guest PC 0x0c0ab508 */
if(!s->budget--) { s->failed_pc=0x0c0ab508u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab510; }
goto P_0c0ab50a;
P_0c0ab50a: /* original 905c, guest PC 0x0c0ab50a */
if(!s->budget--) { s->failed_pc=0x0c0ab50au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab5c6u,2);
goto P_0c0ab50c;
P_0c0ab50c: /* original a001, guest PC 0x0c0ab50c */
if(!s->budget--) { s->failed_pc=0x0c0ab50cu; return 0; }
goto P_0c0ab512;
P_0c0ab50e: /* original 0009, guest PC 0x0c0ab50e */
if(!s->budget--) { s->failed_pc=0x0c0ab50eu; return 0; }
goto P_0c0ab510;
P_0c0ab510: /* original 905a, guest PC 0x0c0ab510 */
if(!s->budget--) { s->failed_pc=0x0c0ab510u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab5c8u,2);
goto P_0c0ab512;
P_0c0ab512: /* original f3e6, guest PC 0x0c0ab512 */
if(!s->budget--) { s->failed_pc=0x0c0ab512u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab514;
P_0c0ab514: /* original e00c, guest PC 0x0c0ab514 */
if(!s->budget--) { s->failed_pc=0x0c0ab514u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab516;
P_0c0ab516: /* original ff37, guest PC 0x0c0ab516 */
if(!s->budget--) { s->failed_pc=0x0c0ab516u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab518;
P_0c0ab518: /* original c72e, guest PC 0x0c0ab518 */
if(!s->budget--) { s->failed_pc=0x0c0ab518u; return 0; }
r[0]=0x0c0ab5d4u;
goto P_0c0ab51a;
P_0c0ab51a: /* original f308, guest PC 0x0c0ab51a */
if(!s->budget--) { s->failed_pc=0x0c0ab51au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0ab51c;
P_0c0ab51c: /* original e00c, guest PC 0x0c0ab51c */
if(!s->budget--) { s->failed_pc=0x0c0ab51cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab51e;
P_0c0ab51e: /* original f2f6, guest PC 0x0c0ab51e */
if(!s->budget--) { s->failed_pc=0x0c0ab51eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ab520;
P_0c0ab520: /* original e00c, guest PC 0x0c0ab520 */
if(!s->budget--) { s->failed_pc=0x0c0ab520u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab522;
P_0c0ab522: /* original f231, guest PC 0x0c0ab522 */
if(!s->budget--) { s->failed_pc=0x0c0ab522u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0ab524;
P_0c0ab524: /* original ff27, guest PC 0x0c0ab524 */
if(!s->budget--) { s->failed_pc=0x0c0ab524u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0ab526;
P_0c0ab526: /* original e00c, guest PC 0x0c0ab526 */
if(!s->budget--) { s->failed_pc=0x0c0ab526u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab528;
P_0c0ab528: /* original f1f8, guest PC 0x0c0ab528 */
if(!s->budget--) { s->failed_pc=0x0c0ab528u; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
goto P_0c0ab52a;
P_0c0ab52a: /* original f122, guest PC 0x0c0ab52a */
if(!s->budget--) { s->failed_pc=0x0c0ab52au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0ab52c;
P_0c0ab52c: /* original ff1a, guest PC 0x0c0ab52c */
if(!s->budget--) { s->failed_pc=0x0c0ab52cu; return 0; }
vf3_matrix_store(s,ram,1,r[15]);
goto P_0c0ab52e;
P_0c0ab52e: /* original f2f6, guest PC 0x0c0ab52e */
if(!s->budget--) { s->failed_pc=0x0c0ab52eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ab530;
P_0c0ab530: /* original e004, guest PC 0x0c0ab530 */
if(!s->budget--) { s->failed_pc=0x0c0ab530u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab532;
P_0c0ab532: /* original f1f6, guest PC 0x0c0ab532 */
if(!s->budget--) { s->failed_pc=0x0c0ab532u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0ab534;
P_0c0ab534: /* original e004, guest PC 0x0c0ab534 */
if(!s->budget--) { s->failed_pc=0x0c0ab534u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab536;
P_0c0ab536: /* original f122, guest PC 0x0c0ab536 */
if(!s->budget--) { s->failed_pc=0x0c0ab536u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0ab538;
P_0c0ab538: /* original ff17, guest PC 0x0c0ab538 */
if(!s->budget--) { s->failed_pc=0x0c0ab538u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0ab53a;
P_0c0ab53a: /* original e014, guest PC 0x0c0ab53a */
if(!s->budget--) { s->failed_pc=0x0c0ab53au; return 0; }
r[0]=0x00000014u;
goto P_0c0ab53c;
P_0c0ab53c: /* original f3f8, guest PC 0x0c0ab53c */
if(!s->budget--) { s->failed_pc=0x0c0ab53cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0ab53e;
P_0c0ab53e: /* original f0ec, guest PC 0x0c0ab53e */
if(!s->budget--) { s->failed_pc=0x0c0ab53eu; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c0ab540;
P_0c0ab540: /* original f031, guest PC 0x0c0ab540 */
if(!s->budget--) { s->failed_pc=0x0c0ab540u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c0ab542;
P_0c0ab542: /* original ff07, guest PC 0x0c0ab542 */
if(!s->budget--) { s->failed_pc=0x0c0ab542u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0ab544;
P_0c0ab544: /* original e004, guest PC 0x0c0ab544 */
if(!s->budget--) { s->failed_pc=0x0c0ab544u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab546;
P_0c0ab546: /* original f2f6, guest PC 0x0c0ab546 */
if(!s->budget--) { s->failed_pc=0x0c0ab546u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ab548;
P_0c0ab548: /* original fcfc, guest PC 0x0c0ab548 */
if(!s->budget--) { s->failed_pc=0x0c0ab548u; return 0; }
vf3_matrix_move(s,12,15);
goto P_0c0ab54a;
P_0c0ab54a: /* original a07c, guest PC 0x0c0ab54a */
if(!s->budget--) { s->failed_pc=0x0c0ab54au; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[2],r[18],'-');
goto P_0c0ab646;
P_0c0ab54c: /* original fc21, guest PC 0x0c0ab54c */
if(!s->budget--) { s->failed_pc=0x0c0ab54cu; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[2],r[18],'-');
goto P_0c0ab54e;
P_0c0ab54e: /* original 9038, guest PC 0x0c0ab54e */
if(!s->budget--) { s->failed_pc=0x0c0ab54eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab5c2u,2);
goto P_0c0ab550;
P_0c0ab550: /* original 63f3, guest PC 0x0c0ab550 */
if(!s->budget--) { s->failed_pc=0x0c0ab550u; return 0; }
r[3]=r[15];
goto P_0c0ab552;
P_0c0ab552: /* original 7310, guest PC 0x0c0ab552 */
if(!s->budget--) { s->failed_pc=0x0c0ab552u; return 0; }
r[3]+=0x00000010u;
goto P_0c0ab554;
P_0c0ab554: /* original f4ec, guest PC 0x0c0ab554 */
if(!s->budget--) { s->failed_pc=0x0c0ab554u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0ab556;
P_0c0ab556: /* original f6b6, guest PC 0x0c0ab556 */
if(!s->budget--) { s->failed_pc=0x0c0ab556u; return 0; }
vf3_matrix_load(s,ram,6,r[11]+r[0]);
goto P_0c0ab558;
P_0c0ab558: /* original 7008, guest PC 0x0c0ab558 */
if(!s->budget--) { s->failed_pc=0x0c0ab558u; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab55a;
P_0c0ab55a: /* original f7b6, guest PC 0x0c0ab55a */
if(!s->budget--) { s->failed_pc=0x0c0ab55au; return 0; }
vf3_matrix_load(s,ram,7,r[11]+r[0]);
goto P_0c0ab55c;
P_0c0ab55c: /* original f5fc, guest PC 0x0c0ab55c */
if(!s->budget--) { s->failed_pc=0x0c0ab55cu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0ab55e;
P_0c0ab55e: /* original 2f36, guest PC 0x0c0ab55e */
if(!s->budget--) { s->failed_pc=0x0c0ab55eu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0ab560;
P_0c0ab560: /* original 67f3, guest PC 0x0c0ab560 */
if(!s->budget--) { s->failed_pc=0x0c0ab560u; return 0; }
r[7]=r[15];
goto P_0c0ab562;
P_0c0ab562: /* original 66f3, guest PC 0x0c0ab562 */
if(!s->budget--) { s->failed_pc=0x0c0ab562u; return 0; }
r[6]=r[15];
goto P_0c0ab564;
P_0c0ab564: /* original 65f3, guest PC 0x0c0ab564 */
if(!s->budget--) { s->failed_pc=0x0c0ab564u; return 0; }
r[5]=r[15];
goto P_0c0ab566;
P_0c0ab566: /* original d21c, guest PC 0x0c0ab566 */
if(!s->budget--) { s->failed_pc=0x0c0ab566u; return 0; }
r[2]=read(ram,0x0c0ab5d8u,4);
goto P_0c0ab568;
P_0c0ab568: /* original 64f3, guest PC 0x0c0ab568 */
if(!s->budget--) { s->failed_pc=0x0c0ab568u; return 0; }
r[4]=r[15];
goto P_0c0ab56a;
P_0c0ab56a: /* original 7508, guest PC 0x0c0ab56a */
if(!s->budget--) { s->failed_pc=0x0c0ab56au; return 0; }
r[5]+=0x00000008u;
goto P_0c0ab56c;
P_0c0ab56c: /* original 7610, guest PC 0x0c0ab56c */
if(!s->budget--) { s->failed_pc=0x0c0ab56cu; return 0; }
r[6]+=0x00000010u;
goto P_0c0ab56e;
P_0c0ab56e: /* original 770c, guest PC 0x0c0ab56e */
if(!s->budget--) { s->failed_pc=0x0c0ab56eu; return 0; }
r[7]+=0x0000000cu;
goto P_0c0ab570;
P_0c0ab570: /* original 420b, guest PC 0x0c0ab570 */
if(!s->budget--) { s->failed_pc=0x0c0ab570u; return 0; }
target=r[2];
r[16]=0x0c0ab574u;
r[4]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ab574u) { target=s->pc; goto dispatch; }
goto P_0c0ab574;
P_0c0ab572: /* original 7404, guest PC 0x0c0ab572 */
if(!s->budget--) { s->failed_pc=0x0c0ab572u; return 0; }
r[4]+=0x00000004u;
goto P_0c0ab574;
P_0c0ab574: /* original 9025, guest PC 0x0c0ab574 */
if(!s->budget--) { s->failed_pc=0x0c0ab574u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab5c2u,2);
goto P_0c0ab576;
P_0c0ab576: /* original 7f04, guest PC 0x0c0ab576 */
if(!s->budget--) { s->failed_pc=0x0c0ab576u; return 0; }
r[15]+=0x00000004u;
goto P_0c0ab578;
P_0c0ab578: /* original f5f8, guest PC 0x0c0ab578 */
if(!s->budget--) { s->failed_pc=0x0c0ab578u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c0ab57a;
P_0c0ab57a: /* original fee6, guest PC 0x0c0ab57a */
if(!s->budget--) { s->failed_pc=0x0c0ab57au; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c0ab57c;
P_0c0ab57c: /* original 7008, guest PC 0x0c0ab57c */
if(!s->budget--) { s->failed_pc=0x0c0ab57cu; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab57e;
P_0c0ab57e: /* original ffe6, guest PC 0x0c0ab57e */
if(!s->budget--) { s->failed_pc=0x0c0ab57eu; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c0ab580;
P_0c0ab580: /* original e00c, guest PC 0x0c0ab580 */
if(!s->budget--) { s->failed_pc=0x0c0ab580u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab582;
P_0c0ab582: /* original f5e1, guest PC 0x0c0ab582 */
if(!s->budget--) { s->failed_pc=0x0c0ab582u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'-');
goto P_0c0ab584;
P_0c0ab584: /* original f4f6, guest PC 0x0c0ab584 */
if(!s->budget--) { s->failed_pc=0x0c0ab584u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0ab586;
P_0c0ab586: /* original e004, guest PC 0x0c0ab586 */
if(!s->budget--) { s->failed_pc=0x0c0ab586u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab588;
P_0c0ab588: /* original f4f1, guest PC 0x0c0ab588 */
if(!s->budget--) { s->failed_pc=0x0c0ab588u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c0ab58a;
P_0c0ab58a: /* original f35c, guest PC 0x0c0ab58a */
if(!s->budget--) { s->failed_pc=0x0c0ab58au; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0ab58c;
P_0c0ab58c: /* original f352, guest PC 0x0c0ab58c */
if(!s->budget--) { s->failed_pc=0x0c0ab58cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c0ab58e;
P_0c0ab58e: /* original f04c, guest PC 0x0c0ab58e */
if(!s->budget--) { s->failed_pc=0x0c0ab58eu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0ab590;
P_0c0ab590: /* original f34e, guest PC 0x0c0ab590 */
if(!s->budget--) { s->failed_pc=0x0c0ab590u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c0ab592;
P_0c0ab592: /* original ff37, guest PC 0x0c0ab592 */
if(!s->budget--) { s->failed_pc=0x0c0ab592u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab594;
P_0c0ab594: /* original c711, guest PC 0x0c0ab594 */
if(!s->budget--) { s->failed_pc=0x0c0ab594u; return 0; }
r[0]=0x0c0ab5dcu;
goto P_0c0ab596;
P_0c0ab596: /* original f208, guest PC 0x0c0ab596 */
if(!s->budget--) { s->failed_pc=0x0c0ab596u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0ab598;
P_0c0ab598: /* original f235, guest PC 0x0c0ab598 */
if(!s->budget--) { s->failed_pc=0x0c0ab598u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0ab59a;
P_0c0ab59a: /* original 8b01, guest PC 0x0c0ab59a */
if(!s->budget--) { s->failed_pc=0x0c0ab59au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab5a0; }
goto P_0c0ab59c;
P_0c0ab59c: /* original a001, guest PC 0x0c0ab59c */
if(!s->budget--) { s->failed_pc=0x0c0ab59cu; return 0; }
fr[3]=0;
goto P_0c0ab5a2;
P_0c0ab59e: /* original f38d, guest PC 0x0c0ab59e */
if(!s->budget--) { s->failed_pc=0x0c0ab59eu; return 0; }
fr[3]=0;
goto P_0c0ab5a0;
P_0c0ab5a0: /* original f37d, guest PC 0x0c0ab5a0 */
if(!s->budget--) { s->failed_pc=0x0c0ab5a0u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0ab5a2;
P_0c0ab5a2: /* original e004, guest PC 0x0c0ab5a2 */
if(!s->budget--) { s->failed_pc=0x0c0ab5a2u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab5a4;
P_0c0ab5a4: /* original f532, guest PC 0x0c0ab5a4 */
if(!s->budget--) { s->failed_pc=0x0c0ab5a4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0ab5a6;
P_0c0ab5a6: /* original ff37, guest PC 0x0c0ab5a6 */
if(!s->budget--) { s->failed_pc=0x0c0ab5a6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab5a8;
P_0c0ab5a8: /* original c70d, guest PC 0x0c0ab5a8 */
if(!s->budget--) { s->failed_pc=0x0c0ab5a8u; return 0; }
r[0]=0x0c0ab5e0u;
goto P_0c0ab5aa;
P_0c0ab5aa: /* original f608, guest PC 0x0c0ab5aa */
if(!s->budget--) { s->failed_pc=0x0c0ab5aau; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0ab5ac;
P_0c0ab5ac: /* original f432, guest PC 0x0c0ab5ac */
if(!s->budget--) { s->failed_pc=0x0c0ab5acu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0ab5ae;
P_0c0ab5ae: /* original f3f8, guest PC 0x0c0ab5ae */
if(!s->budget--) { s->failed_pc=0x0c0ab5aeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0ab5b0;
P_0c0ab5b0: /* original e014, guest PC 0x0c0ab5b0 */
if(!s->budget--) { s->failed_pc=0x0c0ab5b0u; return 0; }
r[0]=0x00000014u;
goto P_0c0ab5b2;
P_0c0ab5b2: /* original f562, guest PC 0x0c0ab5b2 */
if(!s->budget--) { s->failed_pc=0x0c0ab5b2u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c0ab5b4;
P_0c0ab5b4: /* original f462, guest PC 0x0c0ab5b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab5b4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0ab5b6;
P_0c0ab5b6: /* original f351, guest PC 0x0c0ab5b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab5b6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c0ab5b8;
P_0c0ab5b8: /* original ff37, guest PC 0x0c0ab5b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab5b8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab5ba;
P_0c0ab5ba: /* original e00c, guest PC 0x0c0ab5ba */
if(!s->budget--) { s->failed_pc=0x0c0ab5bau; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab5bc;
P_0c0ab5bc: /* original fcf6, guest PC 0x0c0ab5bc */
if(!s->budget--) { s->failed_pc=0x0c0ab5bcu; return 0; }
vf3_matrix_load(s,ram,12,r[15]+r[0]);
goto P_0c0ab5be;
P_0c0ab5be: /* original a042, guest PC 0x0c0ab5be */
if(!s->budget--) { s->failed_pc=0x0c0ab5beu; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'-');
goto P_0c0ab646;
P_0c0ab5c0: /* original fc41, guest PC 0x0c0ab5c0 */
if(!s->budget--) { s->failed_pc=0x0c0ab5c0u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'-');
return vf3_matrix_family(0x0c0ab5c2u,s,ram);
P_0c0ab5e4: /* original 9086, guest PC 0x0c0ab5e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab5e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6f4u,2);
goto P_0c0ab5e6;
P_0c0ab5e6: /* original f3e6, guest PC 0x0c0ab5e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab5e6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab5e8;
P_0c0ab5e8: /* original e014, guest PC 0x0c0ab5e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab5e8u; return 0; }
r[0]=0x00000014u;
goto P_0c0ab5ea;
P_0c0ab5ea: /* original ff37, guest PC 0x0c0ab5ea */
if(!s->budget--) { s->failed_pc=0x0c0ab5eau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab5ec;
P_0c0ab5ec: /* original 9083, guest PC 0x0c0ab5ec */
if(!s->budget--) { s->failed_pc=0x0c0ab5ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6f6u,2);
goto P_0c0ab5ee;
P_0c0ab5ee: /* original f38d, guest PC 0x0c0ab5ee */
if(!s->budget--) { s->failed_pc=0x0c0ab5eeu; return 0; }
fr[3]=0;
goto P_0c0ab5f0;
P_0c0ab5f0: /* original fce6, guest PC 0x0c0ab5f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab5f0u; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c0ab5f2;
P_0c0ab5f2: /* original 70f0, guest PC 0x0c0ab5f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab5f2u; return 0; }
r[0]+=0xfffffff0u;
goto P_0c0ab5f4;
P_0c0ab5f4: /* original f2e6, guest PC 0x0c0ab5f4 */
if(!s->budget--) { s->failed_pc=0x0c0ab5f4u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ab5f6;
P_0c0ab5f6: /* original f234, guest PC 0x0c0ab5f6 */
if(!s->budget--) { s->failed_pc=0x0c0ab5f6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])==as_float(fr[3]))!=0);
goto P_0c0ab5f8;
P_0c0ab5f8: /* original 892b, guest PC 0x0c0ab5f8 */
if(!s->budget--) { s->failed_pc=0x0c0ab5f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab652; }
goto P_0c0ab5fa;
P_0c0ab5fa: /* original f5cc, guest PC 0x0c0ab5fa */
if(!s->budget--) { s->failed_pc=0x0c0ab5fau; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c0ab5fc;
P_0c0ab5fc: /* original f5f1, guest PC 0x0c0ab5fc */
if(!s->budget--) { s->failed_pc=0x0c0ab5fcu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'-');
goto P_0c0ab5fe;
P_0c0ab5fe: /* original e014, guest PC 0x0c0ab5fe */
if(!s->budget--) { s->failed_pc=0x0c0ab5feu; return 0; }
r[0]=0x00000014u;
goto P_0c0ab600;
P_0c0ab600: /* original d33f, guest PC 0x0c0ab600 */
if(!s->budget--) { s->failed_pc=0x0c0ab600u; return 0; }
r[3]=read(ram,0x0c0ab700u,4);
goto P_0c0ab602;
P_0c0ab602: /* original f4f6, guest PC 0x0c0ab602 */
if(!s->budget--) { s->failed_pc=0x0c0ab602u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0ab604;
P_0c0ab604: /* original 430b, guest PC 0x0c0ab604 */
if(!s->budget--) { s->failed_pc=0x0c0ab604u; return 0; }
target=r[3];
r[16]=0x0c0ab608u;
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'-');
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ab608u) { target=s->pc; goto dispatch; }
goto P_0c0ab608;
P_0c0ab606: /* original f4e1, guest PC 0x0c0ab606 */
if(!s->budget--) { s->failed_pc=0x0c0ab606u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'-');
goto P_0c0ab608;
P_0c0ab608: /* original 9376, guest PC 0x0c0ab608 */
if(!s->budget--) { s->failed_pc=0x0c0ab608u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6f8u,2);
goto P_0c0ab60a;
P_0c0ab60a: /* original 600f, guest PC 0x0c0ab60a */
if(!s->budget--) { s->failed_pc=0x0c0ab60au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0ab60c;
P_0c0ab60c: /* original 6203, guest PC 0x0c0ab60c */
if(!s->budget--) { s->failed_pc=0x0c0ab60cu; return 0; }
r[2]=r[0];
goto P_0c0ab60e;
P_0c0ab60e: /* original 323c, guest PC 0x0c0ab60e */
if(!s->budget--) { s->failed_pc=0x0c0ab60eu; return 0; }
r[2]+=r[3];
goto P_0c0ab610;
P_0c0ab610: /* original 1f22, guest PC 0x0c0ab610 */
if(!s->budget--) { s->failed_pc=0x0c0ab610u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0ab612;
P_0c0ab612: /* original 4a0b, guest PC 0x0c0ab612 */
if(!s->budget--) { s->failed_pc=0x0c0ab612u; return 0; }
target=r[10];
r[16]=0x0c0ab616u;
r[4]=(uint32_t)(int32_t)(int16_t)r[2];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ab616u) { target=s->pc; goto dispatch; }
goto P_0c0ab616;
P_0c0ab614: /* original 642f, guest PC 0x0c0ab614 */
if(!s->budget--) { s->failed_pc=0x0c0ab614u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c0ab616;
P_0c0ab616: /* original ff0a, guest PC 0x0c0ab616 */
if(!s->budget--) { s->failed_pc=0x0c0ab616u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0ab618;
P_0c0ab618: /* original 54f2, guest PC 0x0c0ab618 */
if(!s->budget--) { s->failed_pc=0x0c0ab618u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0ab61a;
P_0c0ab61a: /* original 4c0b, guest PC 0x0c0ab61a */
if(!s->budget--) { s->failed_pc=0x0c0ab61au; return 0; }
target=r[12];
r[16]=0x0c0ab61eu;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ab61eu) { target=s->pc; goto dispatch; }
goto P_0c0ab61e;
P_0c0ab61c: /* original 644f, guest PC 0x0c0ab61c */
if(!s->budget--) { s->failed_pc=0x0c0ab61cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0ab61e;
P_0c0ab61e: /* original e004, guest PC 0x0c0ab61e */
if(!s->budget--) { s->failed_pc=0x0c0ab61eu; return 0; }
r[0]=0x00000004u;
goto P_0c0ab620;
P_0c0ab620: /* original ff07, guest PC 0x0c0ab620 */
if(!s->budget--) { s->failed_pc=0x0c0ab620u; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0ab622;
P_0c0ab622: /* original 906a, guest PC 0x0c0ab622 */
if(!s->budget--) { s->failed_pc=0x0c0ab622u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6fau,2);
goto P_0c0ab624;
P_0c0ab624: /* original f3e6, guest PC 0x0c0ab624 */
if(!s->budget--) { s->failed_pc=0x0c0ab624u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ab626;
P_0c0ab626: /* original e00c, guest PC 0x0c0ab626 */
if(!s->budget--) { s->failed_pc=0x0c0ab626u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab628;
P_0c0ab628: /* original ff37, guest PC 0x0c0ab628 */
if(!s->budget--) { s->failed_pc=0x0c0ab628u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab62a;
P_0c0ab62a: /* original e014, guest PC 0x0c0ab62a */
if(!s->budget--) { s->failed_pc=0x0c0ab62au; return 0; }
r[0]=0x00000014u;
goto P_0c0ab62c;
P_0c0ab62c: /* original f3f6, guest PC 0x0c0ab62c */
if(!s->budget--) { s->failed_pc=0x0c0ab62cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab62e;
P_0c0ab62e: /* original e00c, guest PC 0x0c0ab62e */
if(!s->budget--) { s->failed_pc=0x0c0ab62eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab630;
P_0c0ab630: /* original f0f6, guest PC 0x0c0ab630 */
if(!s->budget--) { s->failed_pc=0x0c0ab630u; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c0ab632;
P_0c0ab632: /* original e004, guest PC 0x0c0ab632 */
if(!s->budget--) { s->failed_pc=0x0c0ab632u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab634;
P_0c0ab634: /* original f2f6, guest PC 0x0c0ab634 */
if(!s->budget--) { s->failed_pc=0x0c0ab634u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ab636;
P_0c0ab636: /* original e014, guest PC 0x0c0ab636 */
if(!s->budget--) { s->failed_pc=0x0c0ab636u; return 0; }
r[0]=0x00000014u;
goto P_0c0ab638;
P_0c0ab638: /* original f32e, guest PC 0x0c0ab638 */
if(!s->budget--) { s->failed_pc=0x0c0ab638u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0ab63a;
P_0c0ab63a: /* original ff37, guest PC 0x0c0ab63a */
if(!s->budget--) { s->failed_pc=0x0c0ab63au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab63c;
P_0c0ab63c: /* original e00c, guest PC 0x0c0ab63c */
if(!s->budget--) { s->failed_pc=0x0c0ab63cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab63e;
P_0c0ab63e: /* original f1f8, guest PC 0x0c0ab63e */
if(!s->budget--) { s->failed_pc=0x0c0ab63eu; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
goto P_0c0ab640;
P_0c0ab640: /* original f2f6, guest PC 0x0c0ab640 */
if(!s->budget--) { s->failed_pc=0x0c0ab640u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ab642;
P_0c0ab642: /* original f122, guest PC 0x0c0ab642 */
if(!s->budget--) { s->failed_pc=0x0c0ab642u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0ab644;
P_0c0ab644: /* original fc11, guest PC 0x0c0ab644 */
if(!s->budget--) { s->failed_pc=0x0c0ab644u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[1],r[18],'-');
goto P_0c0ab646;
P_0c0ab646: /* original e014, guest PC 0x0c0ab646 */
if(!s->budget--) { s->failed_pc=0x0c0ab646u; return 0; }
r[0]=0x00000014u;
goto P_0c0ab648;
P_0c0ab648: /* original f3f6, guest PC 0x0c0ab648 */
if(!s->budget--) { s->failed_pc=0x0c0ab648u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab64a;
P_0c0ab64a: /* original 9053, guest PC 0x0c0ab64a */
if(!s->budget--) { s->failed_pc=0x0c0ab64au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6f4u,2);
goto P_0c0ab64c;
P_0c0ab64c: /* original fe37, guest PC 0x0c0ab64c */
if(!s->budget--) { s->failed_pc=0x0c0ab64cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab64e;
P_0c0ab64e: /* original 7008, guest PC 0x0c0ab64e */
if(!s->budget--) { s->failed_pc=0x0c0ab64eu; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab650;
P_0c0ab650: /* original fec7, guest PC 0x0c0ab650 */
if(!s->budget--) { s->failed_pc=0x0c0ab650u; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c0ab652;
P_0c0ab652: /* original e014, guest PC 0x0c0ab652 */
if(!s->budget--) { s->failed_pc=0x0c0ab652u; return 0; }
r[0]=0x00000014u;
goto P_0c0ab654;
P_0c0ab654: /* original f3f6, guest PC 0x0c0ab654 */
if(!s->budget--) { s->failed_pc=0x0c0ab654u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ab656;
P_0c0ab656: /* original e00c, guest PC 0x0c0ab656 */
if(!s->budget--) { s->failed_pc=0x0c0ab656u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab658;
P_0c0ab658: /* original f3e1, guest PC 0x0c0ab658 */
if(!s->budget--) { s->failed_pc=0x0c0ab658u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'-');
goto P_0c0ab65a;
P_0c0ab65a: /* original ff37, guest PC 0x0c0ab65a */
if(!s->budget--) { s->failed_pc=0x0c0ab65au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab65c;
P_0c0ab65c: /* original f332, guest PC 0x0c0ab65c */
if(!s->budget--) { s->failed_pc=0x0c0ab65cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[3],r[18],'*');
goto P_0c0ab65e;
P_0c0ab65e: /* original f4cc, guest PC 0x0c0ab65e */
if(!s->budget--) { s->failed_pc=0x0c0ab65eu; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c0ab660;
P_0c0ab660: /* original f4f1, guest PC 0x0c0ab660 */
if(!s->budget--) { s->failed_pc=0x0c0ab660u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c0ab662;
P_0c0ab662: /* original f04c, guest PC 0x0c0ab662 */
if(!s->budget--) { s->failed_pc=0x0c0ab662u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0ab664;
P_0c0ab664: /* original f34e, guest PC 0x0c0ab664 */
if(!s->budget--) { s->failed_pc=0x0c0ab664u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c0ab666;
P_0c0ab666: /* original ff3a, guest PC 0x0c0ab666 */
if(!s->budget--) { s->failed_pc=0x0c0ab666u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0ab668;
P_0c0ab668: /* original 9048, guest PC 0x0c0ab668 */
if(!s->budget--) { s->failed_pc=0x0c0ab668u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6fcu,2);
goto P_0c0ab66a;
P_0c0ab66a: /* original f5e6, guest PC 0x0c0ab66a */
if(!s->budget--) { s->failed_pc=0x0c0ab66au; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0ab66c;
P_0c0ab66c: /* original e004, guest PC 0x0c0ab66c */
if(!s->budget--) { s->failed_pc=0x0c0ab66cu; return 0; }
r[0]=0x00000004u;
goto P_0c0ab66e;
P_0c0ab66e: /* original f35c, guest PC 0x0c0ab66e */
if(!s->budget--) { s->failed_pc=0x0c0ab66eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0ab670;
P_0c0ab670: /* original f352, guest PC 0x0c0ab670 */
if(!s->budget--) { s->failed_pc=0x0c0ab670u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c0ab672;
P_0c0ab672: /* original ff37, guest PC 0x0c0ab672 */
if(!s->budget--) { s->failed_pc=0x0c0ab672u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab674;
P_0c0ab674: /* original f2f8, guest PC 0x0c0ab674 */
if(!s->budget--) { s->failed_pc=0x0c0ab674u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0ab676;
P_0c0ab676: /* original f235, guest PC 0x0c0ab676 */
if(!s->budget--) { s->failed_pc=0x0c0ab676u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0ab678;
P_0c0ab678: /* original 8b1e, guest PC 0x0c0ab678 */
if(!s->budget--) { s->failed_pc=0x0c0ab678u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab6b8; }
goto P_0c0ab67a;
P_0c0ab67a: /* original c722, guest PC 0x0c0ab67a */
if(!s->budget--) { s->failed_pc=0x0c0ab67au; return 0; }
r[0]=0x0c0ab704u;
goto P_0c0ab67c;
P_0c0ab67c: /* original f3f8, guest PC 0x0c0ab67c */
if(!s->budget--) { s->failed_pc=0x0c0ab67cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0ab67e;
P_0c0ab67e: /* original f208, guest PC 0x0c0ab67e */
if(!s->budget--) { s->failed_pc=0x0c0ab67eu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0ab680;
P_0c0ab680: /* original f235, guest PC 0x0c0ab680 */
if(!s->budget--) { s->failed_pc=0x0c0ab680u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0ab682;
P_0c0ab682: /* original 8b01, guest PC 0x0c0ab682 */
if(!s->budget--) { s->failed_pc=0x0c0ab682u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab688; }
goto P_0c0ab684;
P_0c0ab684: /* original a001, guest PC 0x0c0ab684 */
if(!s->budget--) { s->failed_pc=0x0c0ab684u; return 0; }
fr[3]=0;
goto P_0c0ab68a;
P_0c0ab686: /* original f38d, guest PC 0x0c0ab686 */
if(!s->budget--) { s->failed_pc=0x0c0ab686u; return 0; }
fr[3]=0;
goto P_0c0ab688;
P_0c0ab688: /* original f37d, guest PC 0x0c0ab688 */
if(!s->budget--) { s->failed_pc=0x0c0ab688u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0ab68a;
P_0c0ab68a: /* original e004, guest PC 0x0c0ab68a */
if(!s->budget--) { s->failed_pc=0x0c0ab68au; return 0; }
r[0]=0x00000004u;
goto P_0c0ab68c;
P_0c0ab68c: /* original ff37, guest PC 0x0c0ab68c */
if(!s->budget--) { s->failed_pc=0x0c0ab68cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ab68e;
P_0c0ab68e: /* original c71e, guest PC 0x0c0ab68e */
if(!s->budget--) { s->failed_pc=0x0c0ab68eu; return 0; }
r[0]=0x0c0ab708u;
goto P_0c0ab690;
P_0c0ab690: /* original f6f8, guest PC 0x0c0ab690 */
if(!s->budget--) { s->failed_pc=0x0c0ab690u; return 0; }
vf3_matrix_load(s,ram,6,r[15]);
goto P_0c0ab692;
P_0c0ab692: /* original f632, guest PC 0x0c0ab692 */
if(!s->budget--) { s->failed_pc=0x0c0ab692u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0ab694;
P_0c0ab694: /* original f26c, guest PC 0x0c0ab694 */
if(!s->budget--) { s->failed_pc=0x0c0ab694u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c0ab696;
P_0c0ab696: /* original f6dc, guest PC 0x0c0ab696 */
if(!s->budget--) { s->failed_pc=0x0c0ab696u; return 0; }
vf3_matrix_move(s,6,13);
goto P_0c0ab698;
P_0c0ab698: /* original f623, guest PC 0x0c0ab698 */
if(!s->budget--) { s->failed_pc=0x0c0ab698u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'/');
goto P_0c0ab69a;
P_0c0ab69a: /* original f208, guest PC 0x0c0ab69a */
if(!s->budget--) { s->failed_pc=0x0c0ab69au; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0ab69c;
P_0c0ab69c: /* original e00c, guest PC 0x0c0ab69c */
if(!s->budget--) { s->failed_pc=0x0c0ab69cu; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab69e;
P_0c0ab69e: /* original f521, guest PC 0x0c0ab69e */
if(!s->budget--) { s->failed_pc=0x0c0ab69eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'-');
goto P_0c0ab6a0;
P_0c0ab6a0: /* original f562, guest PC 0x0c0ab6a0 */
if(!s->budget--) { s->failed_pc=0x0c0ab6a0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c0ab6a2;
P_0c0ab6a2: /* original ff5a, guest PC 0x0c0ab6a2 */
if(!s->budget--) { s->failed_pc=0x0c0ab6a2u; return 0; }
vf3_matrix_store(s,ram,5,r[15]);
goto P_0c0ab6a4;
P_0c0ab6a4: /* original f1f6, guest PC 0x0c0ab6a4 */
if(!s->budget--) { s->failed_pc=0x0c0ab6a4u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0ab6a6;
P_0c0ab6a6: /* original f05c, guest PC 0x0c0ab6a6 */
if(!s->budget--) { s->failed_pc=0x0c0ab6a6u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0ab6a8;
P_0c0ab6a8: /* original ff4e, guest PC 0x0c0ab6a8 */
if(!s->budget--) { s->failed_pc=0x0c0ab6a8u; return 0; }
fr[15]=vf3_fpu_mac(fr[0],fr[4],fr[15],r[18]);
goto P_0c0ab6aa;
P_0c0ab6aa: /* original fe1e, guest PC 0x0c0ab6aa */
if(!s->budget--) { s->failed_pc=0x0c0ab6aau; return 0; }
fr[14]=vf3_fpu_mac(fr[0],fr[1],fr[14],r[18]);
goto P_0c0ab6ac;
P_0c0ab6ac: /* original 9022, guest PC 0x0c0ab6ac */
if(!s->budget--) { s->failed_pc=0x0c0ab6acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab6f4u,2);
goto P_0c0ab6ae;
P_0c0ab6ae: /* original f4fc, guest PC 0x0c0ab6ae */
if(!s->budget--) { s->failed_pc=0x0c0ab6aeu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0ab6b0;
P_0c0ab6b0: /* original f5ec, guest PC 0x0c0ab6b0 */
if(!s->budget--) { s->failed_pc=0x0c0ab6b0u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0ab6b2;
P_0c0ab6b2: /* original fe57, guest PC 0x0c0ab6b2 */
if(!s->budget--) { s->failed_pc=0x0c0ab6b2u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0ab6b4;
P_0c0ab6b4: /* original 7008, guest PC 0x0c0ab6b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab6b4u; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab6b6;
P_0c0ab6b6: /* original fe47, guest PC 0x0c0ab6b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab6b6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab6b8;
P_0c0ab6b8: /* original d314, guest PC 0x0c0ab6b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab6b8u; return 0; }
r[3]=read(ram,0x0c0ab70cu,4);
goto P_0c0ab6ba;
P_0c0ab6ba: /* original 66e3, guest PC 0x0c0ab6ba */
if(!s->budget--) { s->failed_pc=0x0c0ab6bau; return 0; }
r[6]=r[14];
goto P_0c0ab6bc;
P_0c0ab6bc: /* original 65e3, guest PC 0x0c0ab6bc */
if(!s->budget--) { s->failed_pc=0x0c0ab6bcu; return 0; }
r[5]=r[14];
goto P_0c0ab6be;
P_0c0ab6be: /* original 7648, guest PC 0x0c0ab6be */
if(!s->budget--) { s->failed_pc=0x0c0ab6beu; return 0; }
r[6]+=0x00000048u;
goto P_0c0ab6c0;
P_0c0ab6c0: /* original 430b, guest PC 0x0c0ab6c0 */
if(!s->budget--) { s->failed_pc=0x0c0ab6c0u; return 0; }
target=r[3];
r[16]=0x0c0ab6c4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ab6c4u) { target=s->pc; goto dispatch; }
goto P_0c0ab6c4;
P_0c0ab6c2: /* original 64e3, guest PC 0x0c0ab6c2 */
if(!s->budget--) { s->failed_pc=0x0c0ab6c2u; return 0; }
r[4]=r[14];
goto P_0c0ab6c4;
P_0c0ab6c4: /* original 52d1, guest PC 0x0c0ab6c4 */
if(!s->budget--) { s->failed_pc=0x0c0ab6c4u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0ab6c6;
P_0c0ab6c6: /* original e062, guest PC 0x0c0ab6c6 */
if(!s->budget--) { s->failed_pc=0x0c0ab6c6u; return 0; }
r[0]=0x00000062u;
goto P_0c0ab6c8;
P_0c0ab6c8: /* original 7201, guest PC 0x0c0ab6c8 */
if(!s->budget--) { s->failed_pc=0x0c0ab6c8u; return 0; }
r[2]+=0x00000001u;
goto P_0c0ab6ca;
P_0c0ab6ca: /* original 6323, guest PC 0x0c0ab6ca */
if(!s->budget--) { s->failed_pc=0x0c0ab6cau; return 0; }
r[3]=r[2];
goto P_0c0ab6cc;
P_0c0ab6cc: /* original 1d21, guest PC 0x0c0ab6cc */
if(!s->budget--) { s->failed_pc=0x0c0ab6ccu; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0ab6ce;
P_0c0ab6ce: /* original 0e34, guest PC 0x0c0ab6ce */
if(!s->budget--) { s->failed_pc=0x0c0ab6ceu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ab6d0;
P_0c0ab6d0: /* original e377, guest PC 0x0c0ab6d0 */
if(!s->budget--) { s->failed_pc=0x0c0ab6d0u; return 0; }
r[3]=0x00000077u;
goto P_0c0ab6d2;
P_0c0ab6d2: /* original 52ee, guest PC 0x0c0ab6d2 */
if(!s->budget--) { s->failed_pc=0x0c0ab6d2u; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c0ab6d4;
P_0c0ab6d4: /* original 1f24, guest PC 0x0c0ab6d4 */
if(!s->budget--) { s->failed_pc=0x0c0ab6d4u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c0ab6d6;
P_0c0ab6d6: /* original 1f32, guest PC 0x0c0ab6d6 */
if(!s->budget--) { s->failed_pc=0x0c0ab6d6u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0ab6d8;
P_0c0ab6d8: /* original 52f4, guest PC 0x0c0ab6d8 */
if(!s->budget--) { s->failed_pc=0x0c0ab6d8u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0ab6da;
P_0c0ab6da: /* original d30d, guest PC 0x0c0ab6da */
if(!s->budget--) { s->failed_pc=0x0c0ab6dau; return 0; }
r[3]=read(ram,0x0c0ab710u,4);
goto P_0c0ab6dc;
P_0c0ab6dc: /* original 2238, guest PC 0x0c0ab6dc */
if(!s->budget--) { s->failed_pc=0x0c0ab6dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab6de;
P_0c0ab6de: /* original 8901, guest PC 0x0c0ab6de */
if(!s->budget--) { s->failed_pc=0x0c0ab6deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab6e4; }
goto P_0c0ab6e0;
P_0c0ab6e0: /* original e174, guest PC 0x0c0ab6e0 */
if(!s->budget--) { s->failed_pc=0x0c0ab6e0u; return 0; }
r[1]=0x00000074u;
goto P_0c0ab6e2;
P_0c0ab6e2: /* original 1f12, guest PC 0x0c0ab6e2 */
if(!s->budget--) { s->failed_pc=0x0c0ab6e2u; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c0ab6e4;
P_0c0ab6e4: /* original d30b, guest PC 0x0c0ab6e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab6e4u; return 0; }
r[3]=read(ram,0x0c0ab714u,4);
goto P_0c0ab6e6;
P_0c0ab6e6: /* original 430b, guest PC 0x0c0ab6e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab6e6u; return 0; }
target=r[3];
r[16]=0x0c0ab6eau;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ab6eau) { target=s->pc; goto dispatch; }
goto P_0c0ab6ea;
P_0c0ab6e8: /* original 54f2, guest PC 0x0c0ab6e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab6e8u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0ab6ea;
P_0c0ab6ea: /* original d30b, guest PC 0x0c0ab6ea */
if(!s->budget--) { s->failed_pc=0x0c0ab6eau; return 0; }
r[3]=read(ram,0x0c0ab718u,4);
goto P_0c0ab6ec;
P_0c0ab6ec: /* original 430b, guest PC 0x0c0ab6ec */
if(!s->budget--) { s->failed_pc=0x0c0ab6ecu; return 0; }
target=r[3];
r[16]=0x0c0ab6f0u;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ab6f0u) { target=s->pc; goto dispatch; }
goto P_0c0ab6f0;
P_0c0ab6ee: /* original 54f2, guest PC 0x0c0ab6ee */
if(!s->budget--) { s->failed_pc=0x0c0ab6eeu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0ab6f0;
P_0c0ab6f0: /* original a09a, guest PC 0x0c0ab6f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab6f0u; return 0; }
goto P_0c0ab828;
P_0c0ab6f2: /* original 0009, guest PC 0x0c0ab6f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab6f2u; return 0; }
return vf3_matrix_family(0x0c0ab6f4u,s,ram);
P_0c0ab71c: /* original 62d2, guest PC 0x0c0ab71c */
if(!s->budget--) { s->failed_pc=0x0c0ab71cu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ab71e;
P_0c0ab71e: /* original d34c, guest PC 0x0c0ab71e */
if(!s->budget--) { s->failed_pc=0x0c0ab71eu; return 0; }
r[3]=read(ram,0x0c0ab850u,4);
goto P_0c0ab720;
P_0c0ab720: /* original 2238, guest PC 0x0c0ab720 */
if(!s->budget--) { s->failed_pc=0x0c0ab720u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab722;
P_0c0ab722: /* original 8916, guest PC 0x0c0ab722 */
if(!s->budget--) { s->failed_pc=0x0c0ab722u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab752; }
goto P_0c0ab724;
P_0c0ab724: /* original e064, guest PC 0x0c0ab724 */
if(!s->budget--) { s->failed_pc=0x0c0ab724u; return 0; }
r[0]=0x00000064u;
goto P_0c0ab726;
P_0c0ab726: /* original 01ed, guest PC 0x0c0ab726 */
if(!s->budget--) { s->failed_pc=0x0c0ab726u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab728;
P_0c0ab728: /* original 611d, guest PC 0x0c0ab728 */
if(!s->budget--) { s->failed_pc=0x0c0ab728u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0ab72a;
P_0c0ab72a: /* original 1f12, guest PC 0x0c0ab72a */
if(!s->budget--) { s->failed_pc=0x0c0ab72au; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c0ab72c;
P_0c0ab72c: /* original 9088, guest PC 0x0c0ab72c */
if(!s->budget--) { s->failed_pc=0x0c0ab72cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab840u,2);
goto P_0c0ab72e;
P_0c0ab72e: /* original 03ed, guest PC 0x0c0ab72e */
if(!s->budget--) { s->failed_pc=0x0c0ab72eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab730;
P_0c0ab730: /* original 1f34, guest PC 0x0c0ab730 */
if(!s->budget--) { s->failed_pc=0x0c0ab730u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0ab732;
P_0c0ab732: /* original 52f2, guest PC 0x0c0ab732 */
if(!s->budget--) { s->failed_pc=0x0c0ab732u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0ab734;
P_0c0ab734: /* original 3236, guest PC 0x0c0ab734 */
if(!s->budget--) { s->failed_pc=0x0c0ab734u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[3])!=0);
goto P_0c0ab736;
P_0c0ab736: /* original 890c, guest PC 0x0c0ab736 */
if(!s->budget--) { s->failed_pc=0x0c0ab736u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab752; }
goto P_0c0ab738;
P_0c0ab738: /* original 63d2, guest PC 0x0c0ab738 */
if(!s->budget--) { s->failed_pc=0x0c0ab738u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0ab73a;
P_0c0ab73a: /* original 633d, guest PC 0x0c0ab73a */
if(!s->budget--) { s->failed_pc=0x0c0ab73au; return 0; }
r[3]=r[3]&65535u;
goto P_0c0ab73c;
P_0c0ab73c: /* original 6533, guest PC 0x0c0ab73c */
if(!s->budget--) { s->failed_pc=0x0c0ab73cu; return 0; }
r[5]=r[3];
goto P_0c0ab73e;
P_0c0ab73e: /* original 1f34, guest PC 0x0c0ab73e */
if(!s->budget--) { s->failed_pc=0x0c0ab73eu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0ab740;
P_0c0ab740: /* original d244, guest PC 0x0c0ab740 */
if(!s->budget--) { s->failed_pc=0x0c0ab740u; return 0; }
r[2]=read(ram,0x0c0ab854u,4);
goto P_0c0ab742;
P_0c0ab742: /* original 420b, guest PC 0x0c0ab742 */
if(!s->budget--) { s->failed_pc=0x0c0ab742u; return 0; }
target=r[2];
r[16]=0x0c0ab746u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ab746u) { target=s->pc; goto dispatch; }
goto P_0c0ab746;
P_0c0ab744: /* original 64e3, guest PC 0x0c0ab744 */
if(!s->budget--) { s->failed_pc=0x0c0ab744u; return 0; }
r[4]=r[14];
goto P_0c0ab746;
P_0c0ab746: /* original 62d2, guest PC 0x0c0ab746 */
if(!s->budget--) { s->failed_pc=0x0c0ab746u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ab748;
P_0c0ab748: /* original d343, guest PC 0x0c0ab748 */
if(!s->budget--) { s->failed_pc=0x0c0ab748u; return 0; }
r[3]=read(ram,0x0c0ab858u,4);
goto P_0c0ab74a;
P_0c0ab74a: /* original 2239, guest PC 0x0c0ab74a */
if(!s->budget--) { s->failed_pc=0x0c0ab74au; return 0; }
r[2]&=r[3];
goto P_0c0ab74c;
P_0c0ab74c: /* original 6123, guest PC 0x0c0ab74c */
if(!s->budget--) { s->failed_pc=0x0c0ab74cu; return 0; }
r[1]=r[2];
goto P_0c0ab74e;
P_0c0ab74e: /* original 2d22, guest PC 0x0c0ab74e */
if(!s->budget--) { s->failed_pc=0x0c0ab74eu; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0ab750;
P_0c0ab750: /* original 1e2e, guest PC 0x0c0ab750 */
if(!s->budget--) { s->failed_pc=0x0c0ab750u; return 0; }
write(ram,r[14]+56,r[2],4);
goto P_0c0ab752;
P_0c0ab752: /* original 62d2, guest PC 0x0c0ab752 */
if(!s->budget--) { s->failed_pc=0x0c0ab752u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ab754;
P_0c0ab754: /* original d341, guest PC 0x0c0ab754 */
if(!s->budget--) { s->failed_pc=0x0c0ab754u; return 0; }
r[3]=read(ram,0x0c0ab85cu,4);
goto P_0c0ab756;
P_0c0ab756: /* original 2238, guest PC 0x0c0ab756 */
if(!s->budget--) { s->failed_pc=0x0c0ab756u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab758;
P_0c0ab758: /* original 893d, guest PC 0x0c0ab758 */
if(!s->budget--) { s->failed_pc=0x0c0ab758u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab7d6; }
goto P_0c0ab75a;
P_0c0ab75a: /* original e064, guest PC 0x0c0ab75a */
if(!s->budget--) { s->failed_pc=0x0c0ab75au; return 0; }
r[0]=0x00000064u;
goto P_0c0ab75c;
P_0c0ab75c: /* original 04ed, guest PC 0x0c0ab75c */
if(!s->budget--) { s->failed_pc=0x0c0ab75cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab75e;
P_0c0ab75e: /* original e30a, guest PC 0x0c0ab75e */
if(!s->budget--) { s->failed_pc=0x0c0ab75eu; return 0; }
r[3]=0x0000000au;
goto P_0c0ab760;
P_0c0ab760: /* original 644d, guest PC 0x0c0ab760 */
if(!s->budget--) { s->failed_pc=0x0c0ab760u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0ab762;
P_0c0ab762: /* original 3437, guest PC 0x0c0ab762 */
if(!s->budget--) { s->failed_pc=0x0c0ab762u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c0ab764;
P_0c0ab764: /* original 8b02, guest PC 0x0c0ab764 */
if(!s->budget--) { s->failed_pc=0x0c0ab764u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab76c; }
goto P_0c0ab766;
P_0c0ab766: /* original 956c, guest PC 0x0c0ab766 */
if(!s->budget--) { s->failed_pc=0x0c0ab766u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab842u,2);
goto P_0c0ab768;
P_0c0ab768: /* original a009, guest PC 0x0c0ab768 */
if(!s->budget--) { s->failed_pc=0x0c0ab768u; return 0; }
r[5]+=r[14];
goto P_0c0ab77e;
P_0c0ab76a: /* original 35ec, guest PC 0x0c0ab76a */
if(!s->budget--) { s->failed_pc=0x0c0ab76au; return 0; }
r[5]+=r[14];
goto P_0c0ab76c;
P_0c0ab76c: /* original 906b, guest PC 0x0c0ab76c */
if(!s->budget--) { s->failed_pc=0x0c0ab76cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab846u,2);
goto P_0c0ab76e;
P_0c0ab76e: /* original 9569, guest PC 0x0c0ab76e */
if(!s->budget--) { s->failed_pc=0x0c0ab76eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab844u,2);
goto P_0c0ab770;
P_0c0ab770: /* original 03ec, guest PC 0x0c0ab770 */
if(!s->budget--) { s->failed_pc=0x0c0ab770u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ab772;
P_0c0ab772: /* original 35ec, guest PC 0x0c0ab772 */
if(!s->budget--) { s->failed_pc=0x0c0ab772u; return 0; }
r[5]+=r[14];
goto P_0c0ab774;
P_0c0ab774: /* original 633c, guest PC 0x0c0ab774 */
if(!s->budget--) { s->failed_pc=0x0c0ab774u; return 0; }
r[3]=r[3]&255u;
goto P_0c0ab776;
P_0c0ab776: /* original 4308, guest PC 0x0c0ab776 */
if(!s->budget--) { s->failed_pc=0x0c0ab776u; return 0; }
r[3]<<=2;
goto P_0c0ab778;
P_0c0ab778: /* original 4308, guest PC 0x0c0ab778 */
if(!s->budget--) { s->failed_pc=0x0c0ab778u; return 0; }
r[3]<<=2;
goto P_0c0ab77a;
P_0c0ab77a: /* original 4308, guest PC 0x0c0ab77a */
if(!s->budget--) { s->failed_pc=0x0c0ab77au; return 0; }
r[3]<<=2;
goto P_0c0ab77c;
P_0c0ab77c: /* original 353c, guest PC 0x0c0ab77c */
if(!s->budget--) { s->failed_pc=0x0c0ab77cu; return 0; }
r[5]+=r[3];
goto P_0c0ab77e;
P_0c0ab77e: /* original e030, guest PC 0x0c0ab77e */
if(!s->budget--) { s->failed_pc=0x0c0ab77eu; return 0; }
r[0]=0x00000030u;
goto P_0c0ab780;
P_0c0ab780: /* original f656, guest PC 0x0c0ab780 */
if(!s->budget--) { s->failed_pc=0x0c0ab780u; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c0ab782;
P_0c0ab782: /* original e038, guest PC 0x0c0ab782 */
if(!s->budget--) { s->failed_pc=0x0c0ab782u; return 0; }
r[0]=0x00000038u;
goto P_0c0ab784;
P_0c0ab784: /* original f856, guest PC 0x0c0ab784 */
if(!s->budget--) { s->failed_pc=0x0c0ab784u; return 0; }
vf3_matrix_load(s,ram,8,r[5]+r[0]);
goto P_0c0ab786;
P_0c0ab786: /* original 2448, guest PC 0x0c0ab786 */
if(!s->budget--) { s->failed_pc=0x0c0ab786u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0ab788;
P_0c0ab788: /* original 905e, guest PC 0x0c0ab788 */
if(!s->budget--) { s->failed_pc=0x0c0ab788u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab848u,2);
goto P_0c0ab78a;
P_0c0ab78a: /* original f7e6, guest PC 0x0c0ab78a */
if(!s->budget--) { s->failed_pc=0x0c0ab78au; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0ab78c;
P_0c0ab78c: /* original 7008, guest PC 0x0c0ab78c */
if(!s->budget--) { s->failed_pc=0x0c0ab78cu; return 0; }
r[0]+=0x00000008u;
goto P_0c0ab78e;
P_0c0ab78e: /* original 8d22, guest PC 0x0c0ab78e */
if(!s->budget--) { s->failed_pc=0x0c0ab78eu; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,9,r[14]+r[0]);
if(cond) { goto P_0c0ab7d6; }
goto P_0c0ab792;
P_0c0ab790: /* original f9e6, guest PC 0x0c0ab790 */
if(!s->budget--) { s->failed_pc=0x0c0ab790u; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c0ab792;
P_0c0ab792: /* original 445a, guest PC 0x0c0ab792 */
if(!s->budget--) { s->failed_pc=0x0c0ab792u; return 0; }
r[53]=r[4];
goto P_0c0ab794;
P_0c0ab794: /* original e010, guest PC 0x0c0ab794 */
if(!s->budget--) { s->failed_pc=0x0c0ab794u; return 0; }
r[0]=0x00000010u;
goto P_0c0ab796;
P_0c0ab796: /* original f2e6, guest PC 0x0c0ab796 */
if(!s->budget--) { s->failed_pc=0x0c0ab796u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ab798;
P_0c0ab798: /* original e00c, guest PC 0x0c0ab798 */
if(!s->budget--) { s->failed_pc=0x0c0ab798u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab79a;
P_0c0ab79a: /* original f981, guest PC 0x0c0ab79a */
if(!s->budget--) { s->failed_pc=0x0c0ab79au; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[8],r[18],'-');
goto P_0c0ab79c;
P_0c0ab79c: /* original f32d, guest PC 0x0c0ab79c */
if(!s->budget--) { s->failed_pc=0x0c0ab79cu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0ab79e;
P_0c0ab79e: /* original ff27, guest PC 0x0c0ab79e */
if(!s->budget--) { s->failed_pc=0x0c0ab79eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0ab7a0;
P_0c0ab7a0: /* original f4dc, guest PC 0x0c0ab7a0 */
if(!s->budget--) { s->failed_pc=0x0c0ab7a0u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0ab7a2;
P_0c0ab7a2: /* original e018, guest PC 0x0c0ab7a2 */
if(!s->budget--) { s->failed_pc=0x0c0ab7a2u; return 0; }
r[0]=0x00000018u;
goto P_0c0ab7a4;
P_0c0ab7a4: /* original f5e6, guest PC 0x0c0ab7a4 */
if(!s->budget--) { s->failed_pc=0x0c0ab7a4u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0ab7a6;
P_0c0ab7a6: /* original e004, guest PC 0x0c0ab7a6 */
if(!s->budget--) { s->failed_pc=0x0c0ab7a6u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab7a8;
P_0c0ab7a8: /* original f761, guest PC 0x0c0ab7a8 */
if(!s->budget--) { s->failed_pc=0x0c0ab7a8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[6],r[18],'-');
goto P_0c0ab7aa;
P_0c0ab7aa: /* original f433, guest PC 0x0c0ab7aa */
if(!s->budget--) { s->failed_pc=0x0c0ab7aau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c0ab7ac;
P_0c0ab7ac: /* original ff7a, guest PC 0x0c0ab7ac */
if(!s->budget--) { s->failed_pc=0x0c0ab7acu; return 0; }
vf3_matrix_store(s,ram,7,r[15]);
goto P_0c0ab7ae;
P_0c0ab7ae: /* original ff97, guest PC 0x0c0ab7ae */
if(!s->budget--) { s->failed_pc=0x0c0ab7aeu; return 0; }
vf3_matrix_store(s,ram,9,r[15]+r[0]);
goto P_0c0ab7b0;
P_0c0ab7b0: /* original e004, guest PC 0x0c0ab7b0 */
if(!s->budget--) { s->failed_pc=0x0c0ab7b0u; return 0; }
r[0]=0x00000004u;
goto P_0c0ab7b2;
P_0c0ab7b2: /* original f3f8, guest PC 0x0c0ab7b2 */
if(!s->budget--) { s->failed_pc=0x0c0ab7b2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0ab7b4;
P_0c0ab7b4: /* original f342, guest PC 0x0c0ab7b4 */
if(!s->budget--) { s->failed_pc=0x0c0ab7b4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0ab7b6;
P_0c0ab7b6: /* original ff3a, guest PC 0x0c0ab7b6 */
if(!s->budget--) { s->failed_pc=0x0c0ab7b6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0ab7b8;
P_0c0ab7b8: /* original f2f6, guest PC 0x0c0ab7b8 */
if(!s->budget--) { s->failed_pc=0x0c0ab7b8u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ab7ba;
P_0c0ab7ba: /* original e004, guest PC 0x0c0ab7ba */
if(!s->budget--) { s->failed_pc=0x0c0ab7bau; return 0; }
r[0]=0x00000004u;
goto P_0c0ab7bc;
P_0c0ab7bc: /* original f242, guest PC 0x0c0ab7bc */
if(!s->budget--) { s->failed_pc=0x0c0ab7bcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c0ab7be;
P_0c0ab7be: /* original ff27, guest PC 0x0c0ab7be */
if(!s->budget--) { s->failed_pc=0x0c0ab7beu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0ab7c0;
P_0c0ab7c0: /* original e00c, guest PC 0x0c0ab7c0 */
if(!s->budget--) { s->failed_pc=0x0c0ab7c0u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab7c2;
P_0c0ab7c2: /* original f1f6, guest PC 0x0c0ab7c2 */
if(!s->budget--) { s->failed_pc=0x0c0ab7c2u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0ab7c4;
P_0c0ab7c4: /* original f520, guest PC 0x0c0ab7c4 */
if(!s->budget--) { s->failed_pc=0x0c0ab7c4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'+');
goto P_0c0ab7c6;
P_0c0ab7c6: /* original e00c, guest PC 0x0c0ab7c6 */
if(!s->budget--) { s->failed_pc=0x0c0ab7c6u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ab7c8;
P_0c0ab7c8: /* original f130, guest PC 0x0c0ab7c8 */
if(!s->budget--) { s->failed_pc=0x0c0ab7c8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'+');
goto P_0c0ab7ca;
P_0c0ab7ca: /* original ff17, guest PC 0x0c0ab7ca */
if(!s->budget--) { s->failed_pc=0x0c0ab7cau; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0ab7cc;
P_0c0ab7cc: /* original e010, guest PC 0x0c0ab7cc */
if(!s->budget--) { s->failed_pc=0x0c0ab7ccu; return 0; }
r[0]=0x00000010u;
goto P_0c0ab7ce;
P_0c0ab7ce: /* original f31c, guest PC 0x0c0ab7ce */
if(!s->budget--) { s->failed_pc=0x0c0ab7ceu; return 0; }
vf3_matrix_move(s,3,1);
goto P_0c0ab7d0;
P_0c0ab7d0: /* original fe37, guest PC 0x0c0ab7d0 */
if(!s->budget--) { s->failed_pc=0x0c0ab7d0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ab7d2;
P_0c0ab7d2: /* original e018, guest PC 0x0c0ab7d2 */
if(!s->budget--) { s->failed_pc=0x0c0ab7d2u; return 0; }
r[0]=0x00000018u;
goto P_0c0ab7d4;
P_0c0ab7d4: /* original fe57, guest PC 0x0c0ab7d4 */
if(!s->budget--) { s->failed_pc=0x0c0ab7d4u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0ab7d6;
P_0c0ab7d6: /* original 52f6, guest PC 0x0c0ab7d6 */
if(!s->budget--) { s->failed_pc=0x0c0ab7d6u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c0ab7d8;
P_0c0ab7d8: /* original d321, guest PC 0x0c0ab7d8 */
if(!s->budget--) { s->failed_pc=0x0c0ab7d8u; return 0; }
r[3]=read(ram,0x0c0ab860u,4);
goto P_0c0ab7da;
P_0c0ab7da: /* original 2238, guest PC 0x0c0ab7da */
if(!s->budget--) { s->failed_pc=0x0c0ab7dau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ab7dc;
P_0c0ab7dc: /* original 8b24, guest PC 0x0c0ab7dc */
if(!s->budget--) { s->failed_pc=0x0c0ab7dcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab828; }
goto P_0c0ab7de;
P_0c0ab7de: /* original 51ee, guest PC 0x0c0ab7de */
if(!s->budget--) { s->failed_pc=0x0c0ab7deu; return 0; }
r[1]=read(ram,r[14]+56,4);
goto P_0c0ab7e0;
P_0c0ab7e0: /* original d320, guest PC 0x0c0ab7e0 */
if(!s->budget--) { s->failed_pc=0x0c0ab7e0u; return 0; }
r[3]=read(ram,0x0c0ab864u,4);
goto P_0c0ab7e2;
P_0c0ab7e2: /* original 2138, guest PC 0x0c0ab7e2 */
if(!s->budget--) { s->failed_pc=0x0c0ab7e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0ab7e4;
P_0c0ab7e4: /* original 8b02, guest PC 0x0c0ab7e4 */
if(!s->budget--) { s->failed_pc=0x0c0ab7e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ab7ec; }
goto P_0c0ab7e6;
P_0c0ab7e6: /* original 65e3, guest PC 0x0c0ab7e6 */
if(!s->budget--) { s->failed_pc=0x0c0ab7e6u; return 0; }
r[5]=r[14];
goto P_0c0ab7e8;
P_0c0ab7e8: /* original a002, guest PC 0x0c0ab7e8 */
if(!s->budget--) { s->failed_pc=0x0c0ab7e8u; return 0; }
r[4]=0x00000001u;
goto P_0c0ab7f0;
P_0c0ab7ea: /* original e401, guest PC 0x0c0ab7ea */
if(!s->budget--) { s->failed_pc=0x0c0ab7eau; return 0; }
r[4]=0x00000001u;
goto P_0c0ab7ec;
P_0c0ab7ec: /* original e402, guest PC 0x0c0ab7ec */
if(!s->budget--) { s->failed_pc=0x0c0ab7ecu; return 0; }
r[4]=0x00000002u;
goto P_0c0ab7ee;
P_0c0ab7ee: /* original 65e3, guest PC 0x0c0ab7ee */
if(!s->budget--) { s->failed_pc=0x0c0ab7eeu; return 0; }
r[5]=r[14];
goto P_0c0ab7f0;
P_0c0ab7f0: /* original d31d, guest PC 0x0c0ab7f0 */
if(!s->budget--) { s->failed_pc=0x0c0ab7f0u; return 0; }
r[3]=read(ram,0x0c0ab868u,4);
goto P_0c0ab7f2;
P_0c0ab7f2: /* original 430b, guest PC 0x0c0ab7f2 */
if(!s->budget--) { s->failed_pc=0x0c0ab7f2u; return 0; }
target=r[3];
r[16]=0x0c0ab7f6u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ab7f6u) { target=s->pc; goto dispatch; }
goto P_0c0ab7f6;
P_0c0ab7f4: /* original 0009, guest PC 0x0c0ab7f4 */
if(!s->budget--) { s->failed_pc=0x0c0ab7f4u; return 0; }
goto P_0c0ab7f6;
P_0c0ab7f6: /* original e024, guest PC 0x0c0ab7f6 */
if(!s->budget--) { s->failed_pc=0x0c0ab7f6u; return 0; }
r[0]=0x00000024u;
goto P_0c0ab7f8;
P_0c0ab7f8: /* original f48d, guest PC 0x0c0ab7f8 */
if(!s->budget--) { s->failed_pc=0x0c0ab7f8u; return 0; }
fr[4]=0;
goto P_0c0ab7fa;
P_0c0ab7fa: /* original fe47, guest PC 0x0c0ab7fa */
if(!s->budget--) { s->failed_pc=0x0c0ab7fau; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab7fc;
P_0c0ab7fc: /* original e028, guest PC 0x0c0ab7fc */
if(!s->budget--) { s->failed_pc=0x0c0ab7fcu; return 0; }
r[0]=0x00000028u;
goto P_0c0ab7fe;
P_0c0ab7fe: /* original fe47, guest PC 0x0c0ab7fe */
if(!s->budget--) { s->failed_pc=0x0c0ab7feu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab800;
P_0c0ab800: /* original e02c, guest PC 0x0c0ab800 */
if(!s->budget--) { s->failed_pc=0x0c0ab800u; return 0; }
r[0]=0x0000002cu;
goto P_0c0ab802;
P_0c0ab802: /* original fe47, guest PC 0x0c0ab802 */
if(!s->budget--) { s->failed_pc=0x0c0ab802u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab804;
P_0c0ab804: /* original e300, guest PC 0x0c0ab804 */
if(!s->budget--) { s->failed_pc=0x0c0ab804u; return 0; }
r[3]=0x00000000u;
goto P_0c0ab806;
P_0c0ab806: /* original 9020, guest PC 0x0c0ab806 */
if(!s->budget--) { s->failed_pc=0x0c0ab806u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab84au,2);
goto P_0c0ab808;
P_0c0ab808: /* original fe47, guest PC 0x0c0ab808 */
if(!s->budget--) { s->failed_pc=0x0c0ab808u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab80a;
P_0c0ab80a: /* original 7004, guest PC 0x0c0ab80a */
if(!s->budget--) { s->failed_pc=0x0c0ab80au; return 0; }
r[0]+=0x00000004u;
goto P_0c0ab80c;
P_0c0ab80c: /* original fe47, guest PC 0x0c0ab80c */
if(!s->budget--) { s->failed_pc=0x0c0ab80cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab80e;
P_0c0ab80e: /* original 7004, guest PC 0x0c0ab80e */
if(!s->budget--) { s->failed_pc=0x0c0ab80eu; return 0; }
r[0]+=0x00000004u;
goto P_0c0ab810;
P_0c0ab810: /* original fe47, guest PC 0x0c0ab810 */
if(!s->budget--) { s->failed_pc=0x0c0ab810u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ab812;
P_0c0ab812: /* original e03e, guest PC 0x0c0ab812 */
if(!s->budget--) { s->failed_pc=0x0c0ab812u; return 0; }
r[0]=0x0000003eu;
goto P_0c0ab814;
P_0c0ab814: /* original 1e3e, guest PC 0x0c0ab814 */
if(!s->budget--) { s->failed_pc=0x0c0ab814u; return 0; }
write(ram,r[14]+56,r[3],4);
goto P_0c0ab816;
P_0c0ab816: /* original 02ed, guest PC 0x0c0ab816 */
if(!s->budget--) { s->failed_pc=0x0c0ab816u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab818;
P_0c0ab818: /* original 9018, guest PC 0x0c0ab818 */
if(!s->budget--) { s->failed_pc=0x0c0ab818u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ab84cu,2);
goto P_0c0ab81a;
P_0c0ab81a: /* original 03ed, guest PC 0x0c0ab81a */
if(!s->budget--) { s->failed_pc=0x0c0ab81au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ab81c;
P_0c0ab81c: /* original 3232, guest PC 0x0c0ab81c */
if(!s->budget--) { s->failed_pc=0x0c0ab81cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c0ab81e;
P_0c0ab81e: /* original 8903, guest PC 0x0c0ab81e */
if(!s->budget--) { s->failed_pc=0x0c0ab81eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ab828; }
goto P_0c0ab820;
P_0c0ab820: /* original d212, guest PC 0x0c0ab820 */
if(!s->budget--) { s->failed_pc=0x0c0ab820u; return 0; }
r[2]=read(ram,0x0c0ab86cu,4);
goto P_0c0ab822;
P_0c0ab822: /* original e048, guest PC 0x0c0ab822 */
if(!s->budget--) { s->failed_pc=0x0c0ab822u; return 0; }
r[0]=0x00000048u;
goto P_0c0ab824;
P_0c0ab824: /* original 2c2b, guest PC 0x0c0ab824 */
if(!s->budget--) { s->failed_pc=0x0c0ab824u; return 0; }
r[12]|=r[2];
goto P_0c0ab826;
P_0c0ab826: /* original 0ec6, guest PC 0x0c0ab826 */
if(!s->budget--) { s->failed_pc=0x0c0ab826u; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c0ab828;
P_0c0ab828: /* original 7f28, guest PC 0x0c0ab828 */
if(!s->budget--) { s->failed_pc=0x0c0ab828u; return 0; }
r[15]+=0x00000028u;
goto P_0c0ab82a;
P_0c0ab82a: /* original 4f26, guest PC 0x0c0ab82a */
if(!s->budget--) { s->failed_pc=0x0c0ab82au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ab82c;
P_0c0ab82c: /* original fcf9, guest PC 0x0c0ab82c */
if(!s->budget--) { s->failed_pc=0x0c0ab82cu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ab82e;
P_0c0ab82e: /* original fdf9, guest PC 0x0c0ab82e */
if(!s->budget--) { s->failed_pc=0x0c0ab82eu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ab830;
P_0c0ab830: /* original fef9, guest PC 0x0c0ab830 */
if(!s->budget--) { s->failed_pc=0x0c0ab830u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ab832;
P_0c0ab832: /* original fff9, guest PC 0x0c0ab832 */
if(!s->budget--) { s->failed_pc=0x0c0ab832u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ab834;
P_0c0ab834: /* original 6af6, guest PC 0x0c0ab834 */
if(!s->budget--) { s->failed_pc=0x0c0ab834u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ab836;
P_0c0ab836: /* original 6bf6, guest PC 0x0c0ab836 */
if(!s->budget--) { s->failed_pc=0x0c0ab836u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ab838;
P_0c0ab838: /* original 6cf6, guest PC 0x0c0ab838 */
if(!s->budget--) { s->failed_pc=0x0c0ab838u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ab83a;
P_0c0ab83a: /* original 6df6, guest PC 0x0c0ab83a */
if(!s->budget--) { s->failed_pc=0x0c0ab83au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ab83c;
P_0c0ab83c: /* original 000b, guest PC 0x0c0ab83c */
if(!s->budget--) { s->failed_pc=0x0c0ab83cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ab83e: /* original 6ef6, guest PC 0x0c0ab83e */
if(!s->budget--) { s->failed_pc=0x0c0ab83eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ab840u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
