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
int vf3_advance_client_helper_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04d50cu: goto P_0c04d50c;
case 0x0c04d50eu: goto P_0c04d50e;
case 0x0c04d510u: goto P_0c04d510;
case 0x0c04d512u: goto P_0c04d512;
case 0x0c04d514u: goto P_0c04d514;
case 0x0c04d516u: goto P_0c04d516;
case 0x0c04d518u: goto P_0c04d518;
case 0x0c04d51au: goto P_0c04d51a;
case 0x0c04d51cu: goto P_0c04d51c;
case 0x0c04d51eu: goto P_0c04d51e;
case 0x0c04d520u: goto P_0c04d520;
case 0x0c04d522u: goto P_0c04d522;
case 0x0c04d524u: goto P_0c04d524;
case 0x0c04d526u: goto P_0c04d526;
case 0x0c04d528u: goto P_0c04d528;
case 0x0c04d52au: goto P_0c04d52a;
case 0x0c04d52cu: goto P_0c04d52c;
case 0x0c04d52eu: goto P_0c04d52e;
case 0x0c04d530u: goto P_0c04d530;
case 0x0c04d532u: goto P_0c04d532;
case 0x0c04d534u: goto P_0c04d534;
case 0x0c04d536u: goto P_0c04d536;
case 0x0c04d538u: goto P_0c04d538;
case 0x0c04d53au: goto P_0c04d53a;
case 0x0c04d53cu: goto P_0c04d53c;
case 0x0c04d53eu: goto P_0c04d53e;
case 0x0c04d540u: goto P_0c04d540;
case 0x0c04d542u: goto P_0c04d542;
case 0x0c04d544u: goto P_0c04d544;
case 0x0c04d546u: goto P_0c04d546;
case 0x0c04d548u: goto P_0c04d548;
case 0x0c04d54au: goto P_0c04d54a;
case 0x0c04d54cu: goto P_0c04d54c;
case 0x0c04d560u: goto P_0c04d560;
case 0x0c04d562u: goto P_0c04d562;
case 0x0c04d564u: goto P_0c04d564;
case 0x0c04d566u: goto P_0c04d566;
case 0x0c04d568u: goto P_0c04d568;
case 0x0c04d56au: goto P_0c04d56a;
case 0x0c04d56cu: goto P_0c04d56c;
case 0x0c04d56eu: goto P_0c04d56e;
case 0x0c04d570u: goto P_0c04d570;
case 0x0c04d572u: goto P_0c04d572;
case 0x0c04d574u: goto P_0c04d574;
case 0x0c04d576u: goto P_0c04d576;
case 0x0c04d578u: goto P_0c04d578;
case 0x0c04d57au: goto P_0c04d57a;
case 0x0c04d57cu: goto P_0c04d57c;
case 0x0c04d57eu: goto P_0c04d57e;
case 0x0c04d580u: goto P_0c04d580;
case 0x0c04d582u: goto P_0c04d582;
case 0x0c04d584u: goto P_0c04d584;
case 0x0c04d586u: goto P_0c04d586;
case 0x0c04d588u: goto P_0c04d588;
case 0x0c04d58au: goto P_0c04d58a;
case 0x0c04d58cu: goto P_0c04d58c;
case 0x0c04d58eu: goto P_0c04d58e;
case 0x0c04d590u: goto P_0c04d590;
case 0x0c04d592u: goto P_0c04d592;
case 0x0c04d594u: goto P_0c04d594;
case 0x0c04d596u: goto P_0c04d596;
case 0x0c04d598u: goto P_0c04d598;
case 0x0c04d59au: goto P_0c04d59a;
case 0x0c04d59cu: goto P_0c04d59c;
case 0x0c04d59eu: goto P_0c04d59e;
case 0x0c04d5a0u: goto P_0c04d5a0;
case 0x0c04d5a2u: goto P_0c04d5a2;
case 0x0c04d5a4u: goto P_0c04d5a4;
case 0x0c04d5a6u: goto P_0c04d5a6;
case 0x0c04d5a8u: goto P_0c04d5a8;
case 0x0c04d5aau: goto P_0c04d5aa;
case 0x0c04d5acu: goto P_0c04d5ac;
case 0x0c04d5aeu: goto P_0c04d5ae;
case 0x0c04d5b0u: goto P_0c04d5b0;
case 0x0c04d5b2u: goto P_0c04d5b2;
case 0x0c04d5b4u: goto P_0c04d5b4;
case 0x0c04d5b6u: goto P_0c04d5b6;
case 0x0c04d5b8u: goto P_0c04d5b8;
case 0x0c04d5bau: goto P_0c04d5ba;
case 0x0c04d5bcu: goto P_0c04d5bc;
case 0x0c04d5beu: goto P_0c04d5be;
case 0x0c04d5c0u: goto P_0c04d5c0;
case 0x0c04d5c2u: goto P_0c04d5c2;
case 0x0c04d5c4u: goto P_0c04d5c4;
case 0x0c04d5c6u: goto P_0c04d5c6;
case 0x0c04d5c8u: goto P_0c04d5c8;
case 0x0c04d5cau: goto P_0c04d5ca;
case 0x0c04d5ccu: goto P_0c04d5cc;
case 0x0c04d5ceu: goto P_0c04d5ce;
case 0x0c04d5d0u: goto P_0c04d5d0;
case 0x0c04d5d2u: goto P_0c04d5d2;
case 0x0c04d5d4u: goto P_0c04d5d4;
case 0x0c04d5d6u: goto P_0c04d5d6;
case 0x0c04d5d8u: goto P_0c04d5d8;
case 0x0c04d5dau: goto P_0c04d5da;
case 0x0c04d5dcu: goto P_0c04d5dc;
case 0x0c04d5deu: goto P_0c04d5de;
case 0x0c04d5e0u: goto P_0c04d5e0;
case 0x0c04d5e2u: goto P_0c04d5e2;
case 0x0c04d5e4u: goto P_0c04d5e4;
case 0x0c04d5e6u: goto P_0c04d5e6;
case 0x0c04d5e8u: goto P_0c04d5e8;
case 0x0c04d5eau: goto P_0c04d5ea;
case 0x0c04d5ecu: goto P_0c04d5ec;
case 0x0c04d5eeu: goto P_0c04d5ee;
case 0x0c04d5f0u: goto P_0c04d5f0;
case 0x0c04d5f2u: goto P_0c04d5f2;
case 0x0c04d5f4u: goto P_0c04d5f4;
case 0x0c04d5f6u: goto P_0c04d5f6;
case 0x0c04d5f8u: goto P_0c04d5f8;
case 0x0c04d5fau: goto P_0c04d5fa;
case 0x0c04d5fcu: goto P_0c04d5fc;
case 0x0c04d5feu: goto P_0c04d5fe;
case 0x0c04d600u: goto P_0c04d600;
case 0x0c04d602u: goto P_0c04d602;
case 0x0c04d604u: goto P_0c04d604;
case 0x0c04d606u: goto P_0c04d606;
case 0x0c04d608u: goto P_0c04d608;
case 0x0c04d60au: goto P_0c04d60a;
case 0x0c04d60cu: goto P_0c04d60c;
case 0x0c04d60eu: goto P_0c04d60e;
case 0x0c04d610u: goto P_0c04d610;
case 0x0c04d612u: goto P_0c04d612;
case 0x0c04d614u: goto P_0c04d614;
case 0x0c04d616u: goto P_0c04d616;
case 0x0c04d618u: goto P_0c04d618;
case 0x0c04d61au: goto P_0c04d61a;
case 0x0c04d61cu: goto P_0c04d61c;
case 0x0c04d61eu: goto P_0c04d61e;
case 0x0c04d620u: goto P_0c04d620;
case 0x0c04d622u: goto P_0c04d622;
case 0x0c04d624u: goto P_0c04d624;
case 0x0c04d626u: goto P_0c04d626;
case 0x0c04d628u: goto P_0c04d628;
case 0x0c04d62au: goto P_0c04d62a;
case 0x0c04d62cu: goto P_0c04d62c;
case 0x0c04d62eu: goto P_0c04d62e;
case 0x0c04d630u: goto P_0c04d630;
case 0x0c04d632u: goto P_0c04d632;
case 0x0c04d634u: goto P_0c04d634;
case 0x0c04d636u: goto P_0c04d636;
case 0x0c04d638u: goto P_0c04d638;
case 0x0c04d63au: goto P_0c04d63a;
case 0x0c04d63cu: goto P_0c04d63c;
case 0x0c04d63eu: goto P_0c04d63e;
case 0x0c04d640u: goto P_0c04d640;
case 0x0c04d642u: goto P_0c04d642;
case 0x0c04d644u: goto P_0c04d644;
case 0x0c04d646u: goto P_0c04d646;
case 0x0c04d648u: goto P_0c04d648;
case 0x0c04d64au: goto P_0c04d64a;
case 0x0c04d64cu: goto P_0c04d64c;
case 0x0c04d64eu: goto P_0c04d64e;
case 0x0c04d650u: goto P_0c04d650;
case 0x0c04d652u: goto P_0c04d652;
case 0x0c04d654u: goto P_0c04d654;
case 0x0c04d656u: goto P_0c04d656;
case 0x0c04d658u: goto P_0c04d658;
case 0x0c04d65au: goto P_0c04d65a;
case 0x0c04d65cu: goto P_0c04d65c;
case 0x0c04d65eu: goto P_0c04d65e;
case 0x0c04d660u: goto P_0c04d660;
case 0x0c04d662u: goto P_0c04d662;
case 0x0c04d664u: goto P_0c04d664;
case 0x0c04d666u: goto P_0c04d666;
case 0x0c04d668u: goto P_0c04d668;
case 0x0c04d66au: goto P_0c04d66a;
case 0x0c04d66cu: goto P_0c04d66c;
case 0x0c04d66eu: goto P_0c04d66e;
case 0x0c04d670u: goto P_0c04d670;
case 0x0c04d672u: goto P_0c04d672;
case 0x0c04d674u: goto P_0c04d674;
case 0x0c04d698u: goto P_0c04d698;
case 0x0c04d69au: goto P_0c04d69a;
case 0x0c04d69cu: goto P_0c04d69c;
case 0x0c04d69eu: goto P_0c04d69e;
case 0x0c04d6a0u: goto P_0c04d6a0;
case 0x0c04d6a2u: goto P_0c04d6a2;
case 0x0c04d6a4u: goto P_0c04d6a4;
case 0x0c04d6a6u: goto P_0c04d6a6;
case 0x0c04d6a8u: goto P_0c04d6a8;
case 0x0c04d6aau: goto P_0c04d6aa;
case 0x0c04d6acu: goto P_0c04d6ac;
case 0x0c04d6aeu: goto P_0c04d6ae;
case 0x0c04d6b0u: goto P_0c04d6b0;
case 0x0c04d6b2u: goto P_0c04d6b2;
case 0x0c04d6b4u: goto P_0c04d6b4;
case 0x0c04d6b6u: goto P_0c04d6b6;
case 0x0c04d6b8u: goto P_0c04d6b8;
case 0x0c04d6bau: goto P_0c04d6ba;
case 0x0c04d6bcu: goto P_0c04d6bc;
case 0x0c04d6beu: goto P_0c04d6be;
case 0x0c04d6c0u: goto P_0c04d6c0;
case 0x0c04d6c2u: goto P_0c04d6c2;
case 0x0c04d6c4u: goto P_0c04d6c4;
case 0x0c04d6c6u: goto P_0c04d6c6;
case 0x0c04d6c8u: goto P_0c04d6c8;
case 0x0c04d6cau: goto P_0c04d6ca;
case 0x0c04d6ccu: goto P_0c04d6cc;
case 0x0c04d6ceu: goto P_0c04d6ce;
case 0x0c04d6d0u: goto P_0c04d6d0;
case 0x0c04d6d2u: goto P_0c04d6d2;
case 0x0c04d6d4u: goto P_0c04d6d4;
case 0x0c04d6d6u: goto P_0c04d6d6;
case 0x0c04d6d8u: goto P_0c04d6d8;
case 0x0c04d6dau: goto P_0c04d6da;
case 0x0c04d6dcu: goto P_0c04d6dc;
case 0x0c04d6deu: goto P_0c04d6de;
case 0x0c04d6e0u: goto P_0c04d6e0;
case 0x0c04d6e2u: goto P_0c04d6e2;
case 0x0c04d6e4u: goto P_0c04d6e4;
case 0x0c04d6e6u: goto P_0c04d6e6;
case 0x0c04d6e8u: goto P_0c04d6e8;
case 0x0c04d6eau: goto P_0c04d6ea;
case 0x0c04d6ecu: goto P_0c04d6ec;
case 0x0c04d6eeu: goto P_0c04d6ee;
case 0x0c04d6f0u: goto P_0c04d6f0;
case 0x0c04d6f2u: goto P_0c04d6f2;
case 0x0c04d6f4u: goto P_0c04d6f4;
case 0x0c04d6f6u: goto P_0c04d6f6;
case 0x0c04d6f8u: goto P_0c04d6f8;
case 0x0c04d6fau: goto P_0c04d6fa;
case 0x0c04d6fcu: goto P_0c04d6fc;
case 0x0c04d6feu: goto P_0c04d6fe;
case 0x0c04d700u: goto P_0c04d700;
case 0x0c04d702u: goto P_0c04d702;
case 0x0c04d704u: goto P_0c04d704;
case 0x0c04d706u: goto P_0c04d706;
case 0x0c04d708u: goto P_0c04d708;
case 0x0c04d70au: goto P_0c04d70a;
case 0x0c04d70cu: goto P_0c04d70c;
case 0x0c04d70eu: goto P_0c04d70e;
case 0x0c04d710u: goto P_0c04d710;
case 0x0c04d712u: goto P_0c04d712;
case 0x0c04d714u: goto P_0c04d714;
case 0x0c04d716u: goto P_0c04d716;
case 0x0c04d718u: goto P_0c04d718;
case 0x0c04d71au: goto P_0c04d71a;
case 0x0c04d71cu: goto P_0c04d71c;
case 0x0c04d71eu: goto P_0c04d71e;
case 0x0c04d720u: goto P_0c04d720;
case 0x0c04e4e0u: goto P_0c04e4e0;
case 0x0c04e4e2u: goto P_0c04e4e2;
case 0x0c04e4e4u: goto P_0c04e4e4;
case 0x0c04e4e6u: goto P_0c04e4e6;
case 0x0c04e4e8u: goto P_0c04e4e8;
case 0x0c04e4eau: goto P_0c04e4ea;
case 0x0c04e4ecu: goto P_0c04e4ec;
case 0x0c04e4eeu: goto P_0c04e4ee;
case 0x0c04e4f0u: goto P_0c04e4f0;
case 0x0c04e4f2u: goto P_0c04e4f2;
case 0x0c04e4f4u: goto P_0c04e4f4;
case 0x0c04e4f6u: goto P_0c04e4f6;
case 0x0c04e4f8u: goto P_0c04e4f8;
case 0x0c04e4fau: goto P_0c04e4fa;
case 0x0c04e4fcu: goto P_0c04e4fc;
case 0x0c04e4feu: goto P_0c04e4fe;
case 0x0c04e500u: goto P_0c04e500;
case 0x0c04e502u: goto P_0c04e502;
case 0x0c04e504u: goto P_0c04e504;
case 0x0c04e506u: goto P_0c04e506;
case 0x0c04e508u: goto P_0c04e508;
case 0x0c04e50au: goto P_0c04e50a;
case 0x0c04e50cu: goto P_0c04e50c;
case 0x0c04e50eu: goto P_0c04e50e;
case 0x0c04e510u: goto P_0c04e510;
case 0x0c04e512u: goto P_0c04e512;
case 0x0c04e514u: goto P_0c04e514;
case 0x0c04e516u: goto P_0c04e516;
case 0x0c04e518u: goto P_0c04e518;
case 0x0c04e51au: goto P_0c04e51a;
case 0x0c04e51cu: goto P_0c04e51c;
case 0x0c04e51eu: goto P_0c04e51e;
case 0x0c04e520u: goto P_0c04e520;
case 0x0c04e522u: goto P_0c04e522;
case 0x0c04e524u: goto P_0c04e524;
case 0x0c04e526u: goto P_0c04e526;
case 0x0c04e528u: goto P_0c04e528;
case 0x0c04e52au: goto P_0c04e52a;
case 0x0c04e52cu: goto P_0c04e52c;
case 0x0c04e52eu: goto P_0c04e52e;
case 0x0c04e530u: goto P_0c04e530;
case 0x0c04e532u: goto P_0c04e532;
case 0x0c04e534u: goto P_0c04e534;
case 0x0c04e536u: goto P_0c04e536;
case 0x0c04e538u: goto P_0c04e538;
case 0x0c04e53au: goto P_0c04e53a;
case 0x0c04e53cu: goto P_0c04e53c;
case 0x0c04e53eu: goto P_0c04e53e;
case 0x0c04e540u: goto P_0c04e540;
case 0x0c04e542u: goto P_0c04e542;
case 0x0c04e544u: goto P_0c04e544;
case 0x0c04e546u: goto P_0c04e546;
case 0x0c04e548u: goto P_0c04e548;
case 0x0c04e54au: goto P_0c04e54a;
case 0x0c04e54cu: goto P_0c04e54c;
case 0x0c04e54eu: goto P_0c04e54e;
case 0x0c04e550u: goto P_0c04e550;
case 0x0c04e552u: goto P_0c04e552;
case 0x0c04e554u: goto P_0c04e554;
case 0x0c04e556u: goto P_0c04e556;
case 0x0c04e558u: goto P_0c04e558;
case 0x0c04e55au: goto P_0c04e55a;
case 0x0c04e55cu: goto P_0c04e55c;
case 0x0c04e55eu: goto P_0c04e55e;
case 0x0c04e560u: goto P_0c04e560;
case 0x0c04e562u: goto P_0c04e562;
case 0x0c04e564u: goto P_0c04e564;
case 0x0c04e566u: goto P_0c04e566;
case 0x0c04e568u: goto P_0c04e568;
case 0x0c04e59cu: goto P_0c04e59c;
case 0x0c04e59eu: goto P_0c04e59e;
case 0x0c04e5a0u: goto P_0c04e5a0;
case 0x0c04e5a2u: goto P_0c04e5a2;
case 0x0c04e5a4u: goto P_0c04e5a4;
case 0x0c04e5a6u: goto P_0c04e5a6;
case 0x0c04e5a8u: goto P_0c04e5a8;
case 0x0c04e5aau: goto P_0c04e5aa;
case 0x0c04e5acu: goto P_0c04e5ac;
case 0x0c04e5aeu: goto P_0c04e5ae;
case 0x0c04e5b0u: goto P_0c04e5b0;
case 0x0c04e5b2u: goto P_0c04e5b2;
case 0x0c04e5b4u: goto P_0c04e5b4;
case 0x0c04e5b6u: goto P_0c04e5b6;
case 0x0c04e5b8u: goto P_0c04e5b8;
case 0x0c04e5bau: goto P_0c04e5ba;
case 0x0c04e5bcu: goto P_0c04e5bc;
case 0x0c04e5beu: goto P_0c04e5be;
case 0x0c04e5c0u: goto P_0c04e5c0;
case 0x0c04e5c2u: goto P_0c04e5c2;
case 0x0c04e5c4u: goto P_0c04e5c4;
case 0x0c04e5c6u: goto P_0c04e5c6;
case 0x0c04e5c8u: goto P_0c04e5c8;
case 0x0c04e5cau: goto P_0c04e5ca;
case 0x0c04e5ccu: goto P_0c04e5cc;
case 0x0c04e5ceu: goto P_0c04e5ce;
case 0x0c04e5d0u: goto P_0c04e5d0;
case 0x0c04e5d2u: goto P_0c04e5d2;
case 0x0c04e5d4u: goto P_0c04e5d4;
case 0x0c04e5d6u: goto P_0c04e5d6;
case 0x0c04e5d8u: goto P_0c04e5d8;
case 0x0c04e5dau: goto P_0c04e5da;
case 0x0c04e5dcu: goto P_0c04e5dc;
case 0x0c04e5deu: goto P_0c04e5de;
case 0x0c04e5e0u: goto P_0c04e5e0;
case 0x0c04e5e2u: goto P_0c04e5e2;
case 0x0c04e5e4u: goto P_0c04e5e4;
case 0x0c04e5e6u: goto P_0c04e5e6;
case 0x0c04e5e8u: goto P_0c04e5e8;
case 0x0c04e5eau: goto P_0c04e5ea;
case 0x0c04e5ecu: goto P_0c04e5ec;
case 0x0c04e5eeu: goto P_0c04e5ee;
case 0x0c04e5f0u: goto P_0c04e5f0;
case 0x0c04e5f2u: goto P_0c04e5f2;
case 0x0c04e5f4u: goto P_0c04e5f4;
case 0x0c04e5f6u: goto P_0c04e5f6;
case 0x0c04e5f8u: goto P_0c04e5f8;
case 0x0c04e5fau: goto P_0c04e5fa;
case 0x0c04e5fcu: goto P_0c04e5fc;
case 0x0c04e5feu: goto P_0c04e5fe;
case 0x0c04e600u: goto P_0c04e600;
case 0x0c04e602u: goto P_0c04e602;
case 0x0c04e604u: goto P_0c04e604;
case 0x0c04e606u: goto P_0c04e606;
case 0x0c04e608u: goto P_0c04e608;
case 0x0c04e60au: goto P_0c04e60a;
case 0x0c04e60cu: goto P_0c04e60c;
case 0x0c04e60eu: goto P_0c04e60e;
case 0x0c04e610u: goto P_0c04e610;
case 0x0c04e612u: goto P_0c04e612;
case 0x0c04e614u: goto P_0c04e614;
case 0x0c04e616u: goto P_0c04e616;
case 0x0c04e618u: goto P_0c04e618;
case 0x0c04e61au: goto P_0c04e61a;
case 0x0c04e61cu: goto P_0c04e61c;
case 0x0c04e61eu: goto P_0c04e61e;
case 0x0c04e620u: goto P_0c04e620;
case 0x0c04e622u: goto P_0c04e622;
case 0x0c04e624u: goto P_0c04e624;
case 0x0c04e626u: goto P_0c04e626;
case 0x0c04e628u: goto P_0c04e628;
case 0x0c04e62au: goto P_0c04e62a;
case 0x0c04e62cu: goto P_0c04e62c;
case 0x0c04e62eu: goto P_0c04e62e;
case 0x0c04e630u: goto P_0c04e630;
case 0x0c04e632u: goto P_0c04e632;
case 0x0c04e634u: goto P_0c04e634;
case 0x0c04e636u: goto P_0c04e636;
case 0x0c04e638u: goto P_0c04e638;
case 0x0c04e63au: goto P_0c04e63a;
case 0x0c04e63cu: goto P_0c04e63c;
case 0x0c04e63eu: goto P_0c04e63e;
case 0x0c04e640u: goto P_0c04e640;
case 0x0c04e642u: goto P_0c04e642;
case 0x0c04e644u: goto P_0c04e644;
case 0x0c04e646u: goto P_0c04e646;
case 0x0c04e648u: goto P_0c04e648;
case 0x0c04e64au: goto P_0c04e64a;
case 0x0c04e64cu: goto P_0c04e64c;
case 0x0c04e64eu: goto P_0c04e64e;
case 0x0c04e650u: goto P_0c04e650;
case 0x0c04e652u: goto P_0c04e652;
case 0x0c04e654u: goto P_0c04e654;
case 0x0c04e656u: goto P_0c04e656;
case 0x0c04e658u: goto P_0c04e658;
case 0x0c04e65au: goto P_0c04e65a;
case 0x0c04e65cu: goto P_0c04e65c;
case 0x0c04e65eu: goto P_0c04e65e;
case 0x0c04e660u: goto P_0c04e660;
case 0x0c04e662u: goto P_0c04e662;
case 0x0c04e664u: goto P_0c04e664;
case 0x0c04e666u: goto P_0c04e666;
case 0x0c04e668u: goto P_0c04e668;
case 0x0c04e66au: goto P_0c04e66a;
case 0x0c04e66cu: goto P_0c04e66c;
case 0x0c04e66eu: goto P_0c04e66e;
case 0x0c04e670u: goto P_0c04e670;
case 0x0c04e672u: goto P_0c04e672;
case 0x0c04e674u: goto P_0c04e674;
case 0x0c04e676u: goto P_0c04e676;
case 0x0c04e678u: goto P_0c04e678;
case 0x0c04e67au: goto P_0c04e67a;
case 0x0c04e67cu: goto P_0c04e67c;
case 0x0c04e67eu: goto P_0c04e67e;
case 0x0c04e680u: goto P_0c04e680;
case 0x0c04e682u: goto P_0c04e682;
case 0x0c04e684u: goto P_0c04e684;
case 0x0c04e686u: goto P_0c04e686;
case 0x0c04e6b4u: goto P_0c04e6b4;
case 0x0c04e6b6u: goto P_0c04e6b6;
case 0x0c04e6b8u: goto P_0c04e6b8;
case 0x0c04e6bau: goto P_0c04e6ba;
case 0x0c04e6bcu: goto P_0c04e6bc;
case 0x0c04e6beu: goto P_0c04e6be;
case 0x0c04e6c0u: goto P_0c04e6c0;
case 0x0c04e6c2u: goto P_0c04e6c2;
case 0x0c04e6c4u: goto P_0c04e6c4;
case 0x0c04e6c6u: goto P_0c04e6c6;
case 0x0c04e6c8u: goto P_0c04e6c8;
case 0x0c04e6cau: goto P_0c04e6ca;
case 0x0c04e6ccu: goto P_0c04e6cc;
case 0x0c04e6ceu: goto P_0c04e6ce;
case 0x0c04e6d0u: goto P_0c04e6d0;
case 0x0c04e6d2u: goto P_0c04e6d2;
case 0x0c04e6d4u: goto P_0c04e6d4;
case 0x0c04e6d6u: goto P_0c04e6d6;
case 0x0c04e6d8u: goto P_0c04e6d8;
case 0x0c04e6dau: goto P_0c04e6da;
case 0x0c04e6dcu: goto P_0c04e6dc;
case 0x0c04e6deu: goto P_0c04e6de;
case 0x0c04e6e0u: goto P_0c04e6e0;
case 0x0c04e6e2u: goto P_0c04e6e2;
case 0x0c04e6e4u: goto P_0c04e6e4;
case 0x0c04e6e6u: goto P_0c04e6e6;
case 0x0c04e6e8u: goto P_0c04e6e8;
case 0x0c04e6eau: goto P_0c04e6ea;
case 0x0c04e6ecu: goto P_0c04e6ec;
case 0x0c04e6eeu: goto P_0c04e6ee;
case 0x0c04e6f0u: goto P_0c04e6f0;
case 0x0c04e6f2u: goto P_0c04e6f2;
case 0x0c04e6f4u: goto P_0c04e6f4;
case 0x0c04e6f6u: goto P_0c04e6f6;
case 0x0c04e6f8u: goto P_0c04e6f8;
case 0x0c04e6fau: goto P_0c04e6fa;
case 0x0c04e6fcu: goto P_0c04e6fc;
case 0x0c04e6feu: goto P_0c04e6fe;
case 0x0c04e700u: goto P_0c04e700;
case 0x0c04e702u: goto P_0c04e702;
case 0x0c04e704u: goto P_0c04e704;
case 0x0c04e706u: goto P_0c04e706;
case 0x0c04e708u: goto P_0c04e708;
case 0x0c04e70au: goto P_0c04e70a;
case 0x0c04e70cu: goto P_0c04e70c;
case 0x0c04e70eu: goto P_0c04e70e;
case 0x0c04e710u: goto P_0c04e710;
case 0x0c04ef8cu: goto P_0c04ef8c;
case 0x0c04ef8eu: goto P_0c04ef8e;
case 0x0c04ef90u: goto P_0c04ef90;
case 0x0c04ef92u: goto P_0c04ef92;
case 0x0c04ef94u: goto P_0c04ef94;
case 0x0c04ef96u: goto P_0c04ef96;
case 0x0c04ef98u: goto P_0c04ef98;
case 0x0c04ef9au: goto P_0c04ef9a;
case 0x0c04ef9cu: goto P_0c04ef9c;
case 0x0c04ef9eu: goto P_0c04ef9e;
case 0x0c04efa0u: goto P_0c04efa0;
case 0x0c04efa2u: goto P_0c04efa2;
case 0x0c04efa4u: goto P_0c04efa4;
case 0x0c04efa6u: goto P_0c04efa6;
case 0x0c04efa8u: goto P_0c04efa8;
case 0x0c04efaau: goto P_0c04efaa;
case 0x0c04efacu: goto P_0c04efac;
case 0x0c04efaeu: goto P_0c04efae;
case 0x0c04efb0u: goto P_0c04efb0;
case 0x0c04efb2u: goto P_0c04efb2;
case 0x0c04efb4u: goto P_0c04efb4;
case 0x0c04efb6u: goto P_0c04efb6;
case 0x0c04efb8u: goto P_0c04efb8;
case 0x0c04efbau: goto P_0c04efba;
case 0x0c04efbcu: goto P_0c04efbc;
case 0x0c04efbeu: goto P_0c04efbe;
case 0x0c04efc0u: goto P_0c04efc0;
case 0x0c04efc2u: goto P_0c04efc2;
case 0x0c04efc4u: goto P_0c04efc4;
case 0x0c04efc6u: goto P_0c04efc6;
case 0x0c04efc8u: goto P_0c04efc8;
case 0x0c04efcau: goto P_0c04efca;
case 0x0c04efccu: goto P_0c04efcc;
case 0x0c04efceu: goto P_0c04efce;
case 0x0c04efd0u: goto P_0c04efd0;
case 0x0c04efd2u: goto P_0c04efd2;
case 0x0c04efd4u: goto P_0c04efd4;
case 0x0c04efd6u: goto P_0c04efd6;
case 0x0c04efd8u: goto P_0c04efd8;
case 0x0c04efdau: goto P_0c04efda;
case 0x0c04efdcu: goto P_0c04efdc;
case 0x0c04efdeu: goto P_0c04efde;
case 0x0c04efe0u: goto P_0c04efe0;
case 0x0c04efe2u: goto P_0c04efe2;
case 0x0c04efe4u: goto P_0c04efe4;
case 0x0c04efe6u: goto P_0c04efe6;
case 0x0c04efe8u: goto P_0c04efe8;
case 0x0c04efeau: goto P_0c04efea;
case 0x0c04efecu: goto P_0c04efec;
case 0x0c04efeeu: goto P_0c04efee;
case 0x0c04eff0u: goto P_0c04eff0;
case 0x0c04eff2u: goto P_0c04eff2;
case 0x0c04eff4u: goto P_0c04eff4;
case 0x0c04eff6u: goto P_0c04eff6;
case 0x0c04eff8u: goto P_0c04eff8;
case 0x0c04effau: goto P_0c04effa;
case 0x0c04effcu: goto P_0c04effc;
case 0x0c04effeu: goto P_0c04effe;
case 0x0c04f000u: goto P_0c04f000;
case 0x0c04f002u: goto P_0c04f002;
case 0x0c04f004u: goto P_0c04f004;
case 0x0c04f006u: goto P_0c04f006;
case 0x0c04f008u: goto P_0c04f008;
case 0x0c04f00au: goto P_0c04f00a;
case 0x0c04f00cu: goto P_0c04f00c;
case 0x0c04f00eu: goto P_0c04f00e;
case 0x0c04f010u: goto P_0c04f010;
case 0x0c04f012u: goto P_0c04f012;
case 0x0c04f014u: goto P_0c04f014;
case 0x0c04f016u: goto P_0c04f016;
case 0x0c04f018u: goto P_0c04f018;
case 0x0c04f01au: goto P_0c04f01a;
case 0x0c04f01cu: goto P_0c04f01c;
case 0x0c04f01eu: goto P_0c04f01e;
case 0x0c04f020u: goto P_0c04f020;
case 0x0c04f022u: goto P_0c04f022;
case 0x0c04f024u: goto P_0c04f024;
case 0x0c04f026u: goto P_0c04f026;
case 0x0c04f028u: goto P_0c04f028;
case 0x0c04fa38u: goto P_0c04fa38;
case 0x0c04fa3au: goto P_0c04fa3a;
case 0x0c04fa3cu: goto P_0c04fa3c;
case 0x0c04fa3eu: goto P_0c04fa3e;
case 0x0c04fa40u: goto P_0c04fa40;
case 0x0c04fa42u: goto P_0c04fa42;
case 0x0c04fa44u: goto P_0c04fa44;
case 0x0c04fa46u: goto P_0c04fa46;
case 0x0c04fa48u: goto P_0c04fa48;
case 0x0c04fa4au: goto P_0c04fa4a;
case 0x0c04fa4cu: goto P_0c04fa4c;
case 0x0c04fa4eu: goto P_0c04fa4e;
case 0x0c04fa50u: goto P_0c04fa50;
case 0x0c04fa52u: goto P_0c04fa52;
case 0x0c04fa54u: goto P_0c04fa54;
case 0x0c04fa56u: goto P_0c04fa56;
case 0x0c04fa58u: goto P_0c04fa58;
case 0x0c04fa5au: goto P_0c04fa5a;
case 0x0c04fa5cu: goto P_0c04fa5c;
case 0x0c04fa5eu: goto P_0c04fa5e;
case 0x0c04fa60u: goto P_0c04fa60;
case 0x0c04fa62u: goto P_0c04fa62;
case 0x0c04fa64u: goto P_0c04fa64;
case 0x0c04fa66u: goto P_0c04fa66;
case 0x0c04fa68u: goto P_0c04fa68;
case 0x0c04fa6au: goto P_0c04fa6a;
case 0x0c04fa6cu: goto P_0c04fa6c;
case 0x0c04fa6eu: goto P_0c04fa6e;
case 0x0c04fa70u: goto P_0c04fa70;
case 0x0c04fa72u: goto P_0c04fa72;
case 0x0c04fa74u: goto P_0c04fa74;
case 0x0c04fa76u: goto P_0c04fa76;
case 0x0c04fa78u: goto P_0c04fa78;
case 0x0c04fa7au: goto P_0c04fa7a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04d50c: /* original 2fe6, guest PC 0x0c04d50c */
if(!s->budget--) { s->failed_pc=0x0c04d50cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d50e;
P_0c04d50e: /* original 6e53, guest PC 0x0c04d50e */
if(!s->budget--) { s->failed_pc=0x0c04d50eu; return 0; }
r[14]=r[5];
goto P_0c04d510;
P_0c04d510: /* original 2fd6, guest PC 0x0c04d510 */
if(!s->budget--) { s->failed_pc=0x0c04d510u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d512;
P_0c04d512: /* original 2fc6, guest PC 0x0c04d512 */
if(!s->budget--) { s->failed_pc=0x0c04d512u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d514;
P_0c04d514: /* original 6c43, guest PC 0x0c04d514 */
if(!s->budget--) { s->failed_pc=0x0c04d514u; return 0; }
r[12]=r[4];
goto P_0c04d516;
P_0c04d516: /* original 4f22, guest PC 0x0c04d516 */
if(!s->budget--) { s->failed_pc=0x0c04d516u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04d518;
P_0c04d518: /* original 9d19, guest PC 0x0c04d518 */
if(!s->budget--) { s->failed_pc=0x0c04d518u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d54eu,2);
goto P_0c04d51a;
P_0c04d51a: /* original 4f12, guest PC 0x0c04d51a */
if(!s->budget--) { s->failed_pc=0x0c04d51au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04d51c;
P_0c04d51c: /* original 2cdf, guest PC 0x0c04d51c */
if(!s->budget--) { s->failed_pc=0x0c04d51cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[12]*(int32_t)(int16_t)r[13]);
goto P_0c04d51e;
P_0c04d51e: /* original 7ff4, guest PC 0x0c04d51e */
if(!s->budget--) { s->failed_pc=0x0c04d51eu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c04d520;
P_0c04d520: /* original 0d1a, guest PC 0x0c04d520 */
if(!s->budget--) { s->failed_pc=0x0c04d520u; return 0; }
r[13]=r[19];
goto P_0c04d522;
P_0c04d522: /* original 6ddf, guest PC 0x0c04d522 */
if(!s->budget--) { s->failed_pc=0x0c04d522u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04d524;
P_0c04d524: /* original 2fd2, guest PC 0x0c04d524 */
if(!s->budget--) { s->failed_pc=0x0c04d524u; return 0; }
write(ram,r[15],r[13],4);
goto P_0c04d526;
P_0c04d526: /* original d30a, guest PC 0x0c04d526 */
if(!s->budget--) { s->failed_pc=0x0c04d526u; return 0; }
r[3]=read(ram,0x0c04d550u,4);
goto P_0c04d528;
P_0c04d528: /* original 2fe6, guest PC 0x0c04d528 */
if(!s->budget--) { s->failed_pc=0x0c04d528u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d52a;
P_0c04d52a: /* original 3d3c, guest PC 0x0c04d52a */
if(!s->budget--) { s->failed_pc=0x0c04d52au; return 0; }
r[13]+=r[3];
goto P_0c04d52c;
P_0c04d52c: /* original 2fc6, guest PC 0x0c04d52c */
if(!s->budget--) { s->failed_pc=0x0c04d52cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d52e;
P_0c04d52e: /* original d20a, guest PC 0x0c04d52e */
if(!s->budget--) { s->failed_pc=0x0c04d52eu; return 0; }
r[2]=read(ram,0x0c04d558u,4);
goto P_0c04d530;
P_0c04d530: /* original b836, guest PC 0x0c04d530 */
if(!s->budget--) { s->failed_pc=0x0c04d530u; return 0; }
target=0x0c04c5a0u; r[16]=0x0c04d534u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d534u) { target=s->pc; goto dispatch; }
goto P_0c04d534;
P_0c04d532: /* original 2f26, guest PC 0x0c04d532 */
if(!s->budget--) { s->failed_pc=0x0c04d532u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d534;
P_0c04d534: /* original 84d2, guest PC 0x0c04d534 */
if(!s->budget--) { s->failed_pc=0x0c04d534u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+2,1);
goto P_0c04d536;
P_0c04d536: /* original 2008, guest PC 0x0c04d536 */
if(!s->budget--) { s->failed_pc=0x0c04d536u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d538;
P_0c04d538: /* original 8d1d, guest PC 0x0c04d538 */
if(!s->budget--) { s->failed_pc=0x0c04d538u; return 0; }
cond=r[17]&1u;
r[15]+=0x0000000cu;
if(cond) { goto P_0c04d576; }
goto P_0c04d53c;
P_0c04d53a: /* original 7f0c, guest PC 0x0c04d53a */
if(!s->budget--) { s->failed_pc=0x0c04d53au; return 0; }
r[15]+=0x0000000cu;
goto P_0c04d53c;
P_0c04d53c: /* original d207, guest PC 0x0c04d53c */
if(!s->budget--) { s->failed_pc=0x0c04d53cu; return 0; }
r[2]=read(ram,0x0c04d55cu,4);
goto P_0c04d53e;
P_0c04d53e: /* original 420b, guest PC 0x0c04d53e */
if(!s->budget--) { s->failed_pc=0x0c04d53eu; return 0; }
target=r[2];
r[16]=0x0c04d542u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d542u) { target=s->pc; goto dispatch; }
goto P_0c04d542;
P_0c04d540: /* original 64c3, guest PC 0x0c04d540 */
if(!s->budget--) { s->failed_pc=0x0c04d540u; return 0; }
r[4]=r[12];
goto P_0c04d542;
P_0c04d542: /* original 2008, guest PC 0x0c04d542 */
if(!s->budget--) { s->failed_pc=0x0c04d542u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d544;
P_0c04d544: /* original 8b0c, guest PC 0x0c04d544 */
if(!s->budget--) { s->failed_pc=0x0c04d544u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d560; }
goto P_0c04d546;
P_0c04d546: /* original bcc2, guest PC 0x0c04d546 */
if(!s->budget--) { s->failed_pc=0x0c04d546u; return 0; }
target=0x0c04ceceu; r[16]=0x0c04d54au;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d54au) { target=s->pc; goto dispatch; }
goto P_0c04d54a;
P_0c04d548: /* original 64c3, guest PC 0x0c04d548 */
if(!s->budget--) { s->failed_pc=0x0c04d548u; return 0; }
r[4]=r[12];
goto P_0c04d54a;
P_0c04d54a: /* original a014, guest PC 0x0c04d54a */
if(!s->budget--) { s->failed_pc=0x0c04d54au; return 0; }
goto P_0c04d576;
P_0c04d54c: /* original 0009, guest PC 0x0c04d54c */
if(!s->budget--) { s->failed_pc=0x0c04d54cu; return 0; }
return vf3_matrix_family(0x0c04d54eu,s,ram);
P_0c04d560: /* original d346, guest PC 0x0c04d560 */
if(!s->budget--) { s->failed_pc=0x0c04d560u; return 0; }
r[3]=read(ram,0x0c04d67cu,4);
goto P_0c04d562;
P_0c04d562: /* original 430b, guest PC 0x0c04d562 */
if(!s->budget--) { s->failed_pc=0x0c04d562u; return 0; }
target=r[3];
r[16]=0x0c04d566u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d566u) { target=s->pc; goto dispatch; }
goto P_0c04d566;
P_0c04d564: /* original 64c3, guest PC 0x0c04d564 */
if(!s->budget--) { s->failed_pc=0x0c04d564u; return 0; }
r[4]=r[12];
goto P_0c04d566;
P_0c04d566: /* original 2008, guest PC 0x0c04d566 */
if(!s->budget--) { s->failed_pc=0x0c04d566u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d568;
P_0c04d568: /* original 8905, guest PC 0x0c04d568 */
if(!s->budget--) { s->failed_pc=0x0c04d568u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d576; }
goto P_0c04d56a;
P_0c04d56a: /* original 62f2, guest PC 0x0c04d56a */
if(!s->budget--) { s->failed_pc=0x0c04d56au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04d56c;
P_0c04d56c: /* original d344, guest PC 0x0c04d56c */
if(!s->budget--) { s->failed_pc=0x0c04d56cu; return 0; }
r[3]=read(ram,0x0c04d680u,4);
goto P_0c04d56e;
P_0c04d56e: /* original 323c, guest PC 0x0c04d56e */
if(!s->budget--) { s->failed_pc=0x0c04d56eu; return 0; }
r[2]+=r[3];
goto P_0c04d570;
P_0c04d570: /* original 8428, guest PC 0x0c04d570 */
if(!s->budget--) { s->failed_pc=0x0c04d570u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04d572;
P_0c04d572: /* original 2008, guest PC 0x0c04d572 */
if(!s->budget--) { s->failed_pc=0x0c04d572u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d574;
P_0c04d574: /* original 8b02, guest PC 0x0c04d574 */
if(!s->budget--) { s->failed_pc=0x0c04d574u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d57c; }
goto P_0c04d576;
P_0c04d576: /* original 907e, guest PC 0x0c04d576 */
if(!s->budget--) { s->failed_pc=0x0c04d576u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d676u,2);
goto P_0c04d578;
P_0c04d578: /* original a051, guest PC 0x0c04d578 */
if(!s->budget--) { s->failed_pc=0x0c04d578u; return 0; }
goto P_0c04d61e;
P_0c04d57a: /* original 0009, guest PC 0x0c04d57a */
if(!s->budget--) { s->failed_pc=0x0c04d57au; return 0; }
goto P_0c04d57c;
P_0c04d57c: /* original d341, guest PC 0x0c04d57c */
if(!s->budget--) { s->failed_pc=0x0c04d57cu; return 0; }
r[3]=read(ram,0x0c04d684u,4);
goto P_0c04d57e;
P_0c04d57e: /* original 430b, guest PC 0x0c04d57e */
if(!s->budget--) { s->failed_pc=0x0c04d57eu; return 0; }
target=r[3];
r[16]=0x0c04d582u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d582u) { target=s->pc; goto dispatch; }
goto P_0c04d582;
P_0c04d580: /* original 64c3, guest PC 0x0c04d580 */
if(!s->budget--) { s->failed_pc=0x0c04d580u; return 0; }
r[4]=r[12];
goto P_0c04d582;
P_0c04d582: /* original 4011, guest PC 0x0c04d582 */
if(!s->budget--) { s->failed_pc=0x0c04d582u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d584;
P_0c04d584: /* original 8902, guest PC 0x0c04d584 */
if(!s->budget--) { s->failed_pc=0x0c04d584u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d58c; }
goto P_0c04d586;
P_0c04d586: /* original 9077, guest PC 0x0c04d586 */
if(!s->budget--) { s->failed_pc=0x0c04d586u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d678u,2);
goto P_0c04d588;
P_0c04d588: /* original a049, guest PC 0x0c04d588 */
if(!s->budget--) { s->failed_pc=0x0c04d588u; return 0; }
goto P_0c04d61e;
P_0c04d58a: /* original 0009, guest PC 0x0c04d58a */
if(!s->budget--) { s->failed_pc=0x0c04d58au; return 0; }
goto P_0c04d58c;
P_0c04d58c: /* original e600, guest PC 0x0c04d58c */
if(!s->budget--) { s->failed_pc=0x0c04d58cu; return 0; }
r[6]=0x00000000u;
goto P_0c04d58e;
P_0c04d58e: /* original 6463, guest PC 0x0c04d58e */
if(!s->budget--) { s->failed_pc=0x0c04d58eu; return 0; }
r[4]=r[6];
goto P_0c04d590;
P_0c04d590: /* original a008, guest PC 0x0c04d590 */
if(!s->budget--) { s->failed_pc=0x0c04d590u; return 0; }
r[5]=0x00000020u;
goto P_0c04d5a4;
P_0c04d592: /* original e520, guest PC 0x0c04d592 */
if(!s->budget--) { s->failed_pc=0x0c04d592u; return 0; }
r[5]=0x00000020u;
goto P_0c04d594;
P_0c04d594: /* original 6343, guest PC 0x0c04d594 */
if(!s->budget--) { s->failed_pc=0x0c04d594u; return 0; }
r[3]=r[4];
goto P_0c04d596;
P_0c04d596: /* original 50d8, guest PC 0x0c04d596 */
if(!s->budget--) { s->failed_pc=0x0c04d596u; return 0; }
r[0]=read(ram,r[13]+32,4);
goto P_0c04d598;
P_0c04d598: /* original 7310, guest PC 0x0c04d598 */
if(!s->budget--) { s->failed_pc=0x0c04d598u; return 0; }
r[3]+=0x00000010u;
goto P_0c04d59a;
P_0c04d59a: /* original 62e3, guest PC 0x0c04d59a */
if(!s->budget--) { s->failed_pc=0x0c04d59au; return 0; }
r[2]=r[14];
goto P_0c04d59c;
P_0c04d59c: /* original 013c, guest PC 0x0c04d59c */
if(!s->budget--) { s->failed_pc=0x0c04d59cu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04d59e;
P_0c04d59e: /* original 324c, guest PC 0x0c04d59e */
if(!s->budget--) { s->failed_pc=0x0c04d59eu; return 0; }
r[2]+=r[4];
goto P_0c04d5a0;
P_0c04d5a0: /* original 7401, guest PC 0x0c04d5a0 */
if(!s->budget--) { s->failed_pc=0x0c04d5a0u; return 0; }
r[4]+=0x00000001u;
goto P_0c04d5a2;
P_0c04d5a2: /* original 2210, guest PC 0x0c04d5a2 */
if(!s->budget--) { s->failed_pc=0x0c04d5a2u; return 0; }
write(ram,r[2],r[1],1);
goto P_0c04d5a4;
P_0c04d5a4: /* original 3453, guest PC 0x0c04d5a4 */
if(!s->budget--) { s->failed_pc=0x0c04d5a4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c04d5a6;
P_0c04d5a6: /* original 8bf5, guest PC 0x0c04d5a6 */
if(!s->budget--) { s->failed_pc=0x0c04d5a6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d594; }
goto P_0c04d5a8;
P_0c04d5a8: /* original 54d8, guest PC 0x0c04d5a8 */
if(!s->budget--) { s->failed_pc=0x0c04d5a8u; return 0; }
r[4]=read(ram,r[13]+32,4);
goto P_0c04d5aa;
P_0c04d5aa: /* original 65f3, guest PC 0x0c04d5aa */
if(!s->budget--) { s->failed_pc=0x0c04d5aau; return 0; }
r[5]=r[15];
goto P_0c04d5ac;
P_0c04d5ac: /* original 7504, guest PC 0x0c04d5ac */
if(!s->budget--) { s->failed_pc=0x0c04d5acu; return 0; }
r[5]+=0x00000004u;
goto P_0c04d5ae;
P_0c04d5ae: /* original 7430, guest PC 0x0c04d5ae */
if(!s->budget--) { s->failed_pc=0x0c04d5aeu; return 0; }
r[4]+=0x00000030u;
goto P_0c04d5b0;
P_0c04d5b0: /* original a004, guest PC 0x0c04d5b0 */
if(!s->budget--) { s->failed_pc=0x0c04d5b0u; return 0; }
r[7]=0x00000008u;
goto P_0c04d5bc;
P_0c04d5b2: /* original e708, guest PC 0x0c04d5b2 */
if(!s->budget--) { s->failed_pc=0x0c04d5b2u; return 0; }
r[7]=0x00000008u;
goto P_0c04d5b4;
P_0c04d5b4: /* original 6344, guest PC 0x0c04d5b4 */
if(!s->budget--) { s->failed_pc=0x0c04d5b4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[3]=tmp;
goto P_0c04d5b6;
P_0c04d5b6: /* original 7601, guest PC 0x0c04d5b6 */
if(!s->budget--) { s->failed_pc=0x0c04d5b6u; return 0; }
r[6]+=0x00000001u;
goto P_0c04d5b8;
P_0c04d5b8: /* original 2530, guest PC 0x0c04d5b8 */
if(!s->budget--) { s->failed_pc=0x0c04d5b8u; return 0; }
write(ram,r[5],r[3],1);
goto P_0c04d5ba;
P_0c04d5ba: /* original 7501, guest PC 0x0c04d5ba */
if(!s->budget--) { s->failed_pc=0x0c04d5bau; return 0; }
r[5]+=0x00000001u;
goto P_0c04d5bc;
P_0c04d5bc: /* original 3673, guest PC 0x0c04d5bc */
if(!s->budget--) { s->failed_pc=0x0c04d5bcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c04d5be;
P_0c04d5be: /* original 8bf9, guest PC 0x0c04d5be */
if(!s->budget--) { s->failed_pc=0x0c04d5beu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d5b4; }
goto P_0c04d5c0;
P_0c04d5c0: /* original d331, guest PC 0x0c04d5c0 */
if(!s->budget--) { s->failed_pc=0x0c04d5c0u; return 0; }
r[3]=read(ram,0x0c04d688u,4);
goto P_0c04d5c2;
P_0c04d5c2: /* original 65f3, guest PC 0x0c04d5c2 */
if(!s->budget--) { s->failed_pc=0x0c04d5c2u; return 0; }
r[5]=r[15];
goto P_0c04d5c4;
P_0c04d5c4: /* original 64e3, guest PC 0x0c04d5c4 */
if(!s->budget--) { s->failed_pc=0x0c04d5c4u; return 0; }
r[4]=r[14];
goto P_0c04d5c6;
P_0c04d5c6: /* original 7504, guest PC 0x0c04d5c6 */
if(!s->budget--) { s->failed_pc=0x0c04d5c6u; return 0; }
r[5]+=0x00000004u;
goto P_0c04d5c8;
P_0c04d5c8: /* original 430b, guest PC 0x0c04d5c8 */
if(!s->budget--) { s->failed_pc=0x0c04d5c8u; return 0; }
target=r[3];
r[16]=0x0c04d5ccu;
r[4]+=0x00000030u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d5ccu) { target=s->pc; goto dispatch; }
goto P_0c04d5cc;
P_0c04d5ca: /* original 7430, guest PC 0x0c04d5ca */
if(!s->budget--) { s->failed_pc=0x0c04d5cau; return 0; }
r[4]+=0x00000030u;
goto P_0c04d5cc;
P_0c04d5cc: /* original 52d7, guest PC 0x0c04d5cc */
if(!s->budget--) { s->failed_pc=0x0c04d5ccu; return 0; }
r[2]=read(ram,r[13]+28,4);
goto P_0c04d5ce;
P_0c04d5ce: /* original e020, guest PC 0x0c04d5ce */
if(!s->budget--) { s->failed_pc=0x0c04d5ceu; return 0; }
r[0]=0x00000020u;
goto P_0c04d5d0;
P_0c04d5d0: /* original e500, guest PC 0x0c04d5d0 */
if(!s->budget--) { s->failed_pc=0x0c04d5d0u; return 0; }
r[5]=0x00000000u;
goto P_0c04d5d2;
P_0c04d5d2: /* original 6322, guest PC 0x0c04d5d2 */
if(!s->budget--) { s->failed_pc=0x0c04d5d2u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c04d5d4;
P_0c04d5d4: /* original 7301, guest PC 0x0c04d5d4 */
if(!s->budget--) { s->failed_pc=0x0c04d5d4u; return 0; }
r[3]+=0x00000001u;
goto P_0c04d5d6;
P_0c04d5d6: /* original 0e35, guest PC 0x0c04d5d6 */
if(!s->budget--) { s->failed_pc=0x0c04d5d6u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c04d5d8;
P_0c04d5d8: /* original e022, guest PC 0x0c04d5d8 */
if(!s->budget--) { s->failed_pc=0x0c04d5d8u; return 0; }
r[0]=0x00000022u;
goto P_0c04d5da;
P_0c04d5da: /* original 52d7, guest PC 0x0c04d5da */
if(!s->budget--) { s->failed_pc=0x0c04d5dau; return 0; }
r[2]=read(ram,r[13]+28,4);
goto P_0c04d5dc;
P_0c04d5dc: /* original 532c, guest PC 0x0c04d5dc */
if(!s->budget--) { s->failed_pc=0x0c04d5dcu; return 0; }
r[3]=read(ram,r[2]+48,4);
goto P_0c04d5de;
P_0c04d5de: /* original 0e35, guest PC 0x0c04d5de */
if(!s->budget--) { s->failed_pc=0x0c04d5deu; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c04d5e0;
P_0c04d5e0: /* original b024, guest PC 0x0c04d5e0 */
if(!s->budget--) { s->failed_pc=0x0c04d5e0u; return 0; }
target=0x0c04d62cu; r[16]=0x0c04d5e4u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d5e4u) { target=s->pc; goto dispatch; }
goto P_0c04d5e4;
P_0c04d5e2: /* original 64c3, guest PC 0x0c04d5e2 */
if(!s->budget--) { s->failed_pc=0x0c04d5e2u; return 0; }
r[4]=r[12];
goto P_0c04d5e4;
P_0c04d5e4: /* original e126, guest PC 0x0c04d5e4 */
if(!s->budget--) { s->failed_pc=0x0c04d5e4u; return 0; }
r[1]=0x00000026u;
goto P_0c04d5e6;
P_0c04d5e6: /* original 31ec, guest PC 0x0c04d5e6 */
if(!s->budget--) { s->failed_pc=0x0c04d5e6u; return 0; }
r[1]+=r[14];
goto P_0c04d5e8;
P_0c04d5e8: /* original 2101, guest PC 0x0c04d5e8 */
if(!s->budget--) { s->failed_pc=0x0c04d5e8u; return 0; }
write(ram,r[1],r[0],2);
goto P_0c04d5ea;
P_0c04d5ea: /* original e026, guest PC 0x0c04d5ea */
if(!s->budget--) { s->failed_pc=0x0c04d5eau; return 0; }
r[0]=0x00000026u;
goto P_0c04d5ec;
P_0c04d5ec: /* original 03ed, guest PC 0x0c04d5ec */
if(!s->budget--) { s->failed_pc=0x0c04d5ecu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c04d5ee;
P_0c04d5ee: /* original e024, guest PC 0x0c04d5ee */
if(!s->budget--) { s->failed_pc=0x0c04d5eeu; return 0; }
r[0]=0x00000024u;
goto P_0c04d5f0;
P_0c04d5f0: /* original e501, guest PC 0x0c04d5f0 */
if(!s->budget--) { s->failed_pc=0x0c04d5f0u; return 0; }
r[5]=0x00000001u;
goto P_0c04d5f2;
P_0c04d5f2: /* original 0e35, guest PC 0x0c04d5f2 */
if(!s->budget--) { s->failed_pc=0x0c04d5f2u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c04d5f4;
P_0c04d5f4: /* original e028, guest PC 0x0c04d5f4 */
if(!s->budget--) { s->failed_pc=0x0c04d5f4u; return 0; }
r[0]=0x00000028u;
goto P_0c04d5f6;
P_0c04d5f6: /* original 52d7, guest PC 0x0c04d5f6 */
if(!s->budget--) { s->failed_pc=0x0c04d5f6u; return 0; }
r[2]=read(ram,r[13]+28,4);
goto P_0c04d5f8;
P_0c04d5f8: /* original 532e, guest PC 0x0c04d5f8 */
if(!s->budget--) { s->failed_pc=0x0c04d5f8u; return 0; }
r[3]=read(ram,r[2]+56,4);
goto P_0c04d5fa;
P_0c04d5fa: /* original 0e35, guest PC 0x0c04d5fa */
if(!s->budget--) { s->failed_pc=0x0c04d5fau; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c04d5fc;
P_0c04d5fc: /* original b016, guest PC 0x0c04d5fc */
if(!s->budget--) { s->failed_pc=0x0c04d5fcu; return 0; }
target=0x0c04d62cu; r[16]=0x0c04d600u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d600u) { target=s->pc; goto dispatch; }
goto P_0c04d600;
P_0c04d5fe: /* original 64c3, guest PC 0x0c04d5fe */
if(!s->budget--) { s->failed_pc=0x0c04d5feu; return 0; }
r[4]=r[12];
goto P_0c04d600;
P_0c04d600: /* original e12a, guest PC 0x0c04d600 */
if(!s->budget--) { s->failed_pc=0x0c04d600u; return 0; }
r[1]=0x0000002au;
goto P_0c04d602;
P_0c04d602: /* original 31ec, guest PC 0x0c04d602 */
if(!s->budget--) { s->failed_pc=0x0c04d602u; return 0; }
r[1]+=r[14];
goto P_0c04d604;
P_0c04d604: /* original 2101, guest PC 0x0c04d604 */
if(!s->budget--) { s->failed_pc=0x0c04d604u; return 0; }
write(ram,r[1],r[0],2);
goto P_0c04d606;
P_0c04d606: /* original e02c, guest PC 0x0c04d606 */
if(!s->budget--) { s->failed_pc=0x0c04d606u; return 0; }
r[0]=0x0000002cu;
goto P_0c04d608;
P_0c04d608: /* original 53d7, guest PC 0x0c04d608 */
if(!s->budget--) { s->failed_pc=0x0c04d608u; return 0; }
r[3]=read(ram,r[13]+28,4);
goto P_0c04d60a;
P_0c04d60a: /* original 523b, guest PC 0x0c04d60a */
if(!s->budget--) { s->failed_pc=0x0c04d60au; return 0; }
r[2]=read(ram,r[3]+44,4);
goto P_0c04d60c;
P_0c04d60c: /* original 7201, guest PC 0x0c04d60c */
if(!s->budget--) { s->failed_pc=0x0c04d60cu; return 0; }
r[2]+=0x00000001u;
goto P_0c04d60e;
P_0c04d60e: /* original 0e25, guest PC 0x0c04d60e */
if(!s->budget--) { s->failed_pc=0x0c04d60eu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c04d610;
P_0c04d610: /* original e04e, guest PC 0x0c04d610 */
if(!s->budget--) { s->failed_pc=0x0c04d610u; return 0; }
r[0]=0x0000004eu;
goto P_0c04d612;
P_0c04d612: /* original 53d8, guest PC 0x0c04d612 */
if(!s->budget--) { s->failed_pc=0x0c04d612u; return 0; }
r[3]=read(ram,r[13]+32,4);
goto P_0c04d614;
P_0c04d614: /* original 023c, guest PC 0x0c04d614 */
if(!s->budget--) { s->failed_pc=0x0c04d614u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04d616;
P_0c04d616: /* original e02e, guest PC 0x0c04d616 */
if(!s->budget--) { s->failed_pc=0x0c04d616u; return 0; }
r[0]=0x0000002eu;
goto P_0c04d618;
P_0c04d618: /* original 622c, guest PC 0x0c04d618 */
if(!s->budget--) { s->failed_pc=0x0c04d618u; return 0; }
r[2]=r[2]&255u;
goto P_0c04d61a;
P_0c04d61a: /* original 0e25, guest PC 0x0c04d61a */
if(!s->budget--) { s->failed_pc=0x0c04d61au; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c04d61c;
P_0c04d61c: /* original e000, guest PC 0x0c04d61c */
if(!s->budget--) { s->failed_pc=0x0c04d61cu; return 0; }
r[0]=0x00000000u;
goto P_0c04d61e;
P_0c04d61e: /* original 7f0c, guest PC 0x0c04d61e */
if(!s->budget--) { s->failed_pc=0x0c04d61eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c04d620;
P_0c04d620: /* original 4f16, guest PC 0x0c04d620 */
if(!s->budget--) { s->failed_pc=0x0c04d620u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d622;
P_0c04d622: /* original 4f26, guest PC 0x0c04d622 */
if(!s->budget--) { s->failed_pc=0x0c04d622u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d624;
P_0c04d624: /* original 6cf6, guest PC 0x0c04d624 */
if(!s->budget--) { s->failed_pc=0x0c04d624u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04d626;
P_0c04d626: /* original 6df6, guest PC 0x0c04d626 */
if(!s->budget--) { s->failed_pc=0x0c04d626u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04d628;
P_0c04d628: /* original 000b, guest PC 0x0c04d628 */
if(!s->budget--) { s->failed_pc=0x0c04d628u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04d62a: /* original 6ef6, guest PC 0x0c04d62a */
if(!s->budget--) { s->failed_pc=0x0c04d62au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04d62c;
P_0c04d62c: /* original 2fe6, guest PC 0x0c04d62c */
if(!s->budget--) { s->failed_pc=0x0c04d62cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d62e;
P_0c04d62e: /* original 6e43, guest PC 0x0c04d62e */
if(!s->budget--) { s->failed_pc=0x0c04d62eu; return 0; }
r[14]=r[4];
goto P_0c04d630;
P_0c04d630: /* original 2fd6, guest PC 0x0c04d630 */
if(!s->budget--) { s->failed_pc=0x0c04d630u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d632;
P_0c04d632: /* original 2fc6, guest PC 0x0c04d632 */
if(!s->budget--) { s->failed_pc=0x0c04d632u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d634;
P_0c04d634: /* original 2fb6, guest PC 0x0c04d634 */
if(!s->budget--) { s->failed_pc=0x0c04d634u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d636;
P_0c04d636: /* original 2fa6, guest PC 0x0c04d636 */
if(!s->budget--) { s->failed_pc=0x0c04d636u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d638;
P_0c04d638: /* original 4f22, guest PC 0x0c04d638 */
if(!s->budget--) { s->failed_pc=0x0c04d638u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04d63a;
P_0c04d63a: /* original 4f12, guest PC 0x0c04d63a */
if(!s->budget--) { s->failed_pc=0x0c04d63au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04d63c;
P_0c04d63c: /* original 7ff8, guest PC 0x0c04d63c */
if(!s->budget--) { s->failed_pc=0x0c04d63cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c04d63e;
P_0c04d63e: /* original 2f52, guest PC 0x0c04d63e */
if(!s->budget--) { s->failed_pc=0x0c04d63eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c04d640;
P_0c04d640: /* original 9b1b, guest PC 0x0c04d640 */
if(!s->budget--) { s->failed_pc=0x0c04d640u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d67au,2);
goto P_0c04d642;
P_0c04d642: /* original 2ebf, guest PC 0x0c04d642 */
if(!s->budget--) { s->failed_pc=0x0c04d642u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[11]);
goto P_0c04d644;
P_0c04d644: /* original 0b1a, guest PC 0x0c04d644 */
if(!s->budget--) { s->failed_pc=0x0c04d644u; return 0; }
r[11]=r[19];
goto P_0c04d646;
P_0c04d646: /* original 6bbf, guest PC 0x0c04d646 */
if(!s->budget--) { s->failed_pc=0x0c04d646u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c04d648;
P_0c04d648: /* original 1fb1, guest PC 0x0c04d648 */
if(!s->budget--) { s->failed_pc=0x0c04d648u; return 0; }
write(ram,r[15]+4,r[11],4);
goto P_0c04d64a;
P_0c04d64a: /* original 62f2, guest PC 0x0c04d64a */
if(!s->budget--) { s->failed_pc=0x0c04d64au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04d64c;
P_0c04d64c: /* original d30c, guest PC 0x0c04d64c */
if(!s->budget--) { s->failed_pc=0x0c04d64cu; return 0; }
r[3]=read(ram,0x0c04d680u,4);
goto P_0c04d64e;
P_0c04d64e: /* original 2f26, guest PC 0x0c04d64e */
if(!s->budget--) { s->failed_pc=0x0c04d64eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d650;
P_0c04d650: /* original 3b3c, guest PC 0x0c04d650 */
if(!s->budget--) { s->failed_pc=0x0c04d650u; return 0; }
r[11]+=r[3];
goto P_0c04d652;
P_0c04d652: /* original 2fe6, guest PC 0x0c04d652 */
if(!s->budget--) { s->failed_pc=0x0c04d652u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d654;
P_0c04d654: /* original d20d, guest PC 0x0c04d654 */
if(!s->budget--) { s->failed_pc=0x0c04d654u; return 0; }
r[2]=read(ram,0x0c04d68cu,4);
goto P_0c04d656;
P_0c04d656: /* original d10e, guest PC 0x0c04d656 */
if(!s->budget--) { s->failed_pc=0x0c04d656u; return 0; }
r[1]=read(ram,0x0c04d690u,4);
goto P_0c04d658;
P_0c04d658: /* original 410b, guest PC 0x0c04d658 */
if(!s->budget--) { s->failed_pc=0x0c04d658u; return 0; }
target=r[1];
r[16]=0x0c04d65cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d65cu) { target=s->pc; goto dispatch; }
goto P_0c04d65c;
P_0c04d65a: /* original 2f26, guest PC 0x0c04d65a */
if(!s->budget--) { s->failed_pc=0x0c04d65au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d65c;
P_0c04d65c: /* original 84b2, guest PC 0x0c04d65c */
if(!s->budget--) { s->failed_pc=0x0c04d65cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+2,1);
goto P_0c04d65e;
P_0c04d65e: /* original 2008, guest PC 0x0c04d65e */
if(!s->budget--) { s->failed_pc=0x0c04d65eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d660;
P_0c04d660: /* original 8d25, guest PC 0x0c04d660 */
if(!s->budget--) { s->failed_pc=0x0c04d660u; return 0; }
cond=r[17]&1u;
r[15]+=0x0000000cu;
if(cond) { goto P_0c04d6ae; }
goto P_0c04d664;
P_0c04d662: /* original 7f0c, guest PC 0x0c04d662 */
if(!s->budget--) { s->failed_pc=0x0c04d662u; return 0; }
r[15]+=0x0000000cu;
goto P_0c04d664;
P_0c04d664: /* original d20b, guest PC 0x0c04d664 */
if(!s->budget--) { s->failed_pc=0x0c04d664u; return 0; }
r[2]=read(ram,0x0c04d694u,4);
goto P_0c04d666;
P_0c04d666: /* original 420b, guest PC 0x0c04d666 */
if(!s->budget--) { s->failed_pc=0x0c04d666u; return 0; }
target=r[2];
r[16]=0x0c04d66au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d66au) { target=s->pc; goto dispatch; }
goto P_0c04d66a;
P_0c04d668: /* original 64e3, guest PC 0x0c04d668 */
if(!s->budget--) { s->failed_pc=0x0c04d668u; return 0; }
r[4]=r[14];
goto P_0c04d66a;
P_0c04d66a: /* original 2008, guest PC 0x0c04d66a */
if(!s->budget--) { s->failed_pc=0x0c04d66au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d66c;
P_0c04d66c: /* original 8b14, guest PC 0x0c04d66c */
if(!s->budget--) { s->failed_pc=0x0c04d66cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d698; }
goto P_0c04d66e;
P_0c04d66e: /* original bc2e, guest PC 0x0c04d66e */
if(!s->budget--) { s->failed_pc=0x0c04d66eu; return 0; }
target=0x0c04ceceu; r[16]=0x0c04d672u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d672u) { target=s->pc; goto dispatch; }
goto P_0c04d672;
P_0c04d670: /* original 64e3, guest PC 0x0c04d670 */
if(!s->budget--) { s->failed_pc=0x0c04d670u; return 0; }
r[4]=r[14];
goto P_0c04d672;
P_0c04d672: /* original a01c, guest PC 0x0c04d672 */
if(!s->budget--) { s->failed_pc=0x0c04d672u; return 0; }
goto P_0c04d6ae;
P_0c04d674: /* original 0009, guest PC 0x0c04d674 */
if(!s->budget--) { s->failed_pc=0x0c04d674u; return 0; }
return vf3_matrix_family(0x0c04d676u,s,ram);
P_0c04d698: /* original d334, guest PC 0x0c04d698 */
if(!s->budget--) { s->failed_pc=0x0c04d698u; return 0; }
r[3]=read(ram,0x0c04d76cu,4);
goto P_0c04d69a;
P_0c04d69a: /* original 430b, guest PC 0x0c04d69a */
if(!s->budget--) { s->failed_pc=0x0c04d69au; return 0; }
target=r[3];
r[16]=0x0c04d69eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d69eu) { target=s->pc; goto dispatch; }
goto P_0c04d69e;
P_0c04d69c: /* original 64e3, guest PC 0x0c04d69c */
if(!s->budget--) { s->failed_pc=0x0c04d69cu; return 0; }
r[4]=r[14];
goto P_0c04d69e;
P_0c04d69e: /* original 2008, guest PC 0x0c04d69e */
if(!s->budget--) { s->failed_pc=0x0c04d69eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d6a0;
P_0c04d6a0: /* original 8905, guest PC 0x0c04d6a0 */
if(!s->budget--) { s->failed_pc=0x0c04d6a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d6ae; }
goto P_0c04d6a2;
P_0c04d6a2: /* original 52f1, guest PC 0x0c04d6a2 */
if(!s->budget--) { s->failed_pc=0x0c04d6a2u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c04d6a4;
P_0c04d6a4: /* original d332, guest PC 0x0c04d6a4 */
if(!s->budget--) { s->failed_pc=0x0c04d6a4u; return 0; }
r[3]=read(ram,0x0c04d770u,4);
goto P_0c04d6a6;
P_0c04d6a6: /* original 323c, guest PC 0x0c04d6a6 */
if(!s->budget--) { s->failed_pc=0x0c04d6a6u; return 0; }
r[2]+=r[3];
goto P_0c04d6a8;
P_0c04d6a8: /* original 8428, guest PC 0x0c04d6a8 */
if(!s->budget--) { s->failed_pc=0x0c04d6a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04d6aa;
P_0c04d6aa: /* original 2008, guest PC 0x0c04d6aa */
if(!s->budget--) { s->failed_pc=0x0c04d6aau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d6ac;
P_0c04d6ac: /* original 8b02, guest PC 0x0c04d6ac */
if(!s->budget--) { s->failed_pc=0x0c04d6acu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d6b4; }
goto P_0c04d6ae;
P_0c04d6ae: /* original 905a, guest PC 0x0c04d6ae */
if(!s->budget--) { s->failed_pc=0x0c04d6aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d766u,2);
goto P_0c04d6b0;
P_0c04d6b0: /* original a02e, guest PC 0x0c04d6b0 */
if(!s->budget--) { s->failed_pc=0x0c04d6b0u; return 0; }
goto P_0c04d710;
P_0c04d6b2: /* original 0009, guest PC 0x0c04d6b2 */
if(!s->budget--) { s->failed_pc=0x0c04d6b2u; return 0; }
goto P_0c04d6b4;
P_0c04d6b4: /* original d32f, guest PC 0x0c04d6b4 */
if(!s->budget--) { s->failed_pc=0x0c04d6b4u; return 0; }
r[3]=read(ram,0x0c04d774u,4);
goto P_0c04d6b6;
P_0c04d6b6: /* original 430b, guest PC 0x0c04d6b6 */
if(!s->budget--) { s->failed_pc=0x0c04d6b6u; return 0; }
target=r[3];
r[16]=0x0c04d6bau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d6bau) { target=s->pc; goto dispatch; }
goto P_0c04d6ba;
P_0c04d6b8: /* original 64e3, guest PC 0x0c04d6b8 */
if(!s->budget--) { s->failed_pc=0x0c04d6b8u; return 0; }
r[4]=r[14];
goto P_0c04d6ba;
P_0c04d6ba: /* original 4011, guest PC 0x0c04d6ba */
if(!s->budget--) { s->failed_pc=0x0c04d6bau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d6bc;
P_0c04d6bc: /* original 8902, guest PC 0x0c04d6bc */
if(!s->budget--) { s->failed_pc=0x0c04d6bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d6c4; }
goto P_0c04d6be;
P_0c04d6be: /* original 9053, guest PC 0x0c04d6be */
if(!s->budget--) { s->failed_pc=0x0c04d6beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d768u,2);
goto P_0c04d6c0;
P_0c04d6c0: /* original a026, guest PC 0x0c04d6c0 */
if(!s->budget--) { s->failed_pc=0x0c04d6c0u; return 0; }
goto P_0c04d710;
P_0c04d6c2: /* original 0009, guest PC 0x0c04d6c2 */
if(!s->budget--) { s->failed_pc=0x0c04d6c2u; return 0; }
goto P_0c04d6c4;
P_0c04d6c4: /* original 60f2, guest PC 0x0c04d6c4 */
if(!s->budget--) { s->failed_pc=0x0c04d6c4u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c04d6c6;
P_0c04d6c6: /* original e400, guest PC 0x0c04d6c6 */
if(!s->budget--) { s->failed_pc=0x0c04d6c6u; return 0; }
r[4]=0x00000000u;
goto P_0c04d6c8;
P_0c04d6c8: /* original dd2b, guest PC 0x0c04d6c8 */
if(!s->budget--) { s->failed_pc=0x0c04d6c8u; return 0; }
r[13]=read(ram,0x0c04d778u,4);
goto P_0c04d6ca;
P_0c04d6ca: /* original 8801, guest PC 0x0c04d6ca */
if(!s->budget--) { s->failed_pc=0x0c04d6cau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c04d6cc;
P_0c04d6cc: /* original 8f10, guest PC 0x0c04d6cc */
if(!s->budget--) { s->failed_pc=0x0c04d6ccu; return 0; }
cond=r[17]&1u;
r[10]=r[4];
if(!cond) { goto P_0c04d6f0; }
goto P_0c04d6d0;
P_0c04d6ce: /* original 6a43, guest PC 0x0c04d6ce */
if(!s->budget--) { s->failed_pc=0x0c04d6ceu; return 0; }
r[10]=r[4];
goto P_0c04d6d0;
P_0c04d6d0: /* original a008, guest PC 0x0c04d6d0 */
if(!s->budget--) { s->failed_pc=0x0c04d6d0u; return 0; }
r[12]=r[4];
goto P_0c04d6e4;
P_0c04d6d2: /* original 6c43, guest PC 0x0c04d6d2 */
if(!s->budget--) { s->failed_pc=0x0c04d6d2u; return 0; }
r[12]=r[4];
goto P_0c04d6d4;
P_0c04d6d4: /* original d329, guest PC 0x0c04d6d4 */
if(!s->budget--) { s->failed_pc=0x0c04d6d4u; return 0; }
r[3]=read(ram,0x0c04d77cu,4);
goto P_0c04d6d6;
P_0c04d6d6: /* original 65c3, guest PC 0x0c04d6d6 */
if(!s->budget--) { s->failed_pc=0x0c04d6d6u; return 0; }
r[5]=r[12];
goto P_0c04d6d8;
P_0c04d6d8: /* original 430b, guest PC 0x0c04d6d8 */
if(!s->budget--) { s->failed_pc=0x0c04d6d8u; return 0; }
target=r[3];
r[16]=0x0c04d6dcu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d6dcu) { target=s->pc; goto dispatch; }
goto P_0c04d6dc;
P_0c04d6da: /* original 64e3, guest PC 0x0c04d6da */
if(!s->budget--) { s->failed_pc=0x0c04d6dau; return 0; }
r[4]=r[14];
goto P_0c04d6dc;
P_0c04d6dc: /* original 600d, guest PC 0x0c04d6dc */
if(!s->budget--) { s->failed_pc=0x0c04d6dcu; return 0; }
r[0]=r[0]&65535u;
goto P_0c04d6de;
P_0c04d6de: /* original 30d0, guest PC 0x0c04d6de */
if(!s->budget--) { s->failed_pc=0x0c04d6deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[13])!=0);
goto P_0c04d6e0;
P_0c04d6e0: /* original 8b04, guest PC 0x0c04d6e0 */
if(!s->budget--) { s->failed_pc=0x0c04d6e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d6ec; }
goto P_0c04d6e2;
P_0c04d6e2: /* original 7c01, guest PC 0x0c04d6e2 */
if(!s->budget--) { s->failed_pc=0x0c04d6e2u; return 0; }
r[12]+=0x00000001u;
goto P_0c04d6e4;
P_0c04d6e4: /* original 52b7, guest PC 0x0c04d6e4 */
if(!s->budget--) { s->failed_pc=0x0c04d6e4u; return 0; }
r[2]=read(ram,r[11]+28,4);
goto P_0c04d6e6;
P_0c04d6e6: /* original 532e, guest PC 0x0c04d6e6 */
if(!s->budget--) { s->failed_pc=0x0c04d6e6u; return 0; }
r[3]=read(ram,r[2]+56,4);
goto P_0c04d6e8;
P_0c04d6e8: /* original 3c33, guest PC 0x0c04d6e8 */
if(!s->budget--) { s->failed_pc=0x0c04d6e8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[3])!=0);
goto P_0c04d6ea;
P_0c04d6ea: /* original 8bf3, guest PC 0x0c04d6ea */
if(!s->budget--) { s->failed_pc=0x0c04d6eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d6d4; }
goto P_0c04d6ec;
P_0c04d6ec: /* original a00f, guest PC 0x0c04d6ec */
if(!s->budget--) { s->failed_pc=0x0c04d6ecu; return 0; }
r[10]=r[12];
goto P_0c04d70e;
P_0c04d6ee: /* original 6ac3, guest PC 0x0c04d6ee */
if(!s->budget--) { s->failed_pc=0x0c04d6eeu; return 0; }
r[10]=r[12];
goto P_0c04d6f0;
P_0c04d6f0: /* original a009, guest PC 0x0c04d6f0 */
if(!s->budget--) { s->failed_pc=0x0c04d6f0u; return 0; }
r[12]=r[4];
goto P_0c04d706;
P_0c04d6f2: /* original 6c43, guest PC 0x0c04d6f2 */
if(!s->budget--) { s->failed_pc=0x0c04d6f2u; return 0; }
r[12]=r[4];
goto P_0c04d6f4;
P_0c04d6f4: /* original d321, guest PC 0x0c04d6f4 */
if(!s->budget--) { s->failed_pc=0x0c04d6f4u; return 0; }
r[3]=read(ram,0x0c04d77cu,4);
goto P_0c04d6f6;
P_0c04d6f6: /* original 65c3, guest PC 0x0c04d6f6 */
if(!s->budget--) { s->failed_pc=0x0c04d6f6u; return 0; }
r[5]=r[12];
goto P_0c04d6f8;
P_0c04d6f8: /* original 430b, guest PC 0x0c04d6f8 */
if(!s->budget--) { s->failed_pc=0x0c04d6f8u; return 0; }
target=r[3];
r[16]=0x0c04d6fcu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d6fcu) { target=s->pc; goto dispatch; }
goto P_0c04d6fc;
P_0c04d6fa: /* original 64e3, guest PC 0x0c04d6fa */
if(!s->budget--) { s->failed_pc=0x0c04d6fau; return 0; }
r[4]=r[14];
goto P_0c04d6fc;
P_0c04d6fc: /* original 600d, guest PC 0x0c04d6fc */
if(!s->budget--) { s->failed_pc=0x0c04d6fcu; return 0; }
r[0]=r[0]&65535u;
goto P_0c04d6fe;
P_0c04d6fe: /* original 30d0, guest PC 0x0c04d6fe */
if(!s->budget--) { s->failed_pc=0x0c04d6feu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[13])!=0);
goto P_0c04d700;
P_0c04d700: /* original 8f01, guest PC 0x0c04d700 */
if(!s->budget--) { s->failed_pc=0x0c04d700u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c04d706; }
goto P_0c04d704;
P_0c04d702: /* original 7c01, guest PC 0x0c04d702 */
if(!s->budget--) { s->failed_pc=0x0c04d702u; return 0; }
r[12]+=0x00000001u;
goto P_0c04d704;
P_0c04d704: /* original 7a01, guest PC 0x0c04d704 */
if(!s->budget--) { s->failed_pc=0x0c04d704u; return 0; }
r[10]+=0x00000001u;
goto P_0c04d706;
P_0c04d706: /* original 53b7, guest PC 0x0c04d706 */
if(!s->budget--) { s->failed_pc=0x0c04d706u; return 0; }
r[3]=read(ram,r[11]+28,4);
goto P_0c04d708;
P_0c04d708: /* original 523c, guest PC 0x0c04d708 */
if(!s->budget--) { s->failed_pc=0x0c04d708u; return 0; }
r[2]=read(ram,r[3]+48,4);
goto P_0c04d70a;
P_0c04d70a: /* original 3c23, guest PC 0x0c04d70a */
if(!s->budget--) { s->failed_pc=0x0c04d70au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[2])!=0);
goto P_0c04d70c;
P_0c04d70c: /* original 8bf2, guest PC 0x0c04d70c */
if(!s->budget--) { s->failed_pc=0x0c04d70cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d6f4; }
goto P_0c04d70e;
P_0c04d70e: /* original 60a3, guest PC 0x0c04d70e */
if(!s->budget--) { s->failed_pc=0x0c04d70eu; return 0; }
r[0]=r[10];
goto P_0c04d710;
P_0c04d710: /* original 7f08, guest PC 0x0c04d710 */
if(!s->budget--) { s->failed_pc=0x0c04d710u; return 0; }
r[15]+=0x00000008u;
goto P_0c04d712;
P_0c04d712: /* original 4f16, guest PC 0x0c04d712 */
if(!s->budget--) { s->failed_pc=0x0c04d712u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d714;
P_0c04d714: /* original 4f26, guest PC 0x0c04d714 */
if(!s->budget--) { s->failed_pc=0x0c04d714u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d716;
P_0c04d716: /* original 6af6, guest PC 0x0c04d716 */
if(!s->budget--) { s->failed_pc=0x0c04d716u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04d718;
P_0c04d718: /* original 6bf6, guest PC 0x0c04d718 */
if(!s->budget--) { s->failed_pc=0x0c04d718u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04d71a;
P_0c04d71a: /* original 6cf6, guest PC 0x0c04d71a */
if(!s->budget--) { s->failed_pc=0x0c04d71au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04d71c;
P_0c04d71c: /* original 6df6, guest PC 0x0c04d71c */
if(!s->budget--) { s->failed_pc=0x0c04d71cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04d71e;
P_0c04d71e: /* original 000b, guest PC 0x0c04d71e */
if(!s->budget--) { s->failed_pc=0x0c04d71eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04d720: /* original 6ef6, guest PC 0x0c04d720 */
if(!s->budget--) { s->failed_pc=0x0c04d720u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04d722u,s,ram);
P_0c04e4e0: /* original 2fe6, guest PC 0x0c04e4e0 */
if(!s->budget--) { s->failed_pc=0x0c04e4e0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e4e2;
P_0c04e4e2: /* original 2fd6, guest PC 0x0c04e4e2 */
if(!s->budget--) { s->failed_pc=0x0c04e4e2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e4e4;
P_0c04e4e4: /* original 6d43, guest PC 0x0c04e4e4 */
if(!s->budget--) { s->failed_pc=0x0c04e4e4u; return 0; }
r[13]=r[4];
goto P_0c04e4e6;
P_0c04e4e6: /* original 2fc6, guest PC 0x0c04e4e6 */
if(!s->budget--) { s->failed_pc=0x0c04e4e6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e4e8;
P_0c04e4e8: /* original 2fa6, guest PC 0x0c04e4e8 */
if(!s->budget--) { s->failed_pc=0x0c04e4e8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e4ea;
P_0c04e4ea: /* original 6a53, guest PC 0x0c04e4ea */
if(!s->budget--) { s->failed_pc=0x0c04e4eau; return 0; }
r[10]=r[5];
goto P_0c04e4ec;
P_0c04e4ec: /* original 4f22, guest PC 0x0c04e4ec */
if(!s->budget--) { s->failed_pc=0x0c04e4ecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04e4ee;
P_0c04e4ee: /* original 9e3c, guest PC 0x0c04e4ee */
if(!s->budget--) { s->failed_pc=0x0c04e4eeu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e56au,2);
goto P_0c04e4f0;
P_0c04e4f0: /* original 4f12, guest PC 0x0c04e4f0 */
if(!s->budget--) { s->failed_pc=0x0c04e4f0u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04e4f2;
P_0c04e4f2: /* original 2def, guest PC 0x0c04e4f2 */
if(!s->budget--) { s->failed_pc=0x0c04e4f2u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[14]);
goto P_0c04e4f4;
P_0c04e4f4: /* original 7ffc, guest PC 0x0c04e4f4 */
if(!s->budget--) { s->failed_pc=0x0c04e4f4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04e4f6;
P_0c04e4f6: /* original 0e1a, guest PC 0x0c04e4f6 */
if(!s->budget--) { s->failed_pc=0x0c04e4f6u; return 0; }
r[14]=r[19];
goto P_0c04e4f8;
P_0c04e4f8: /* original 6eef, guest PC 0x0c04e4f8 */
if(!s->budget--) { s->failed_pc=0x0c04e4f8u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04e4fa;
P_0c04e4fa: /* original 2fe2, guest PC 0x0c04e4fa */
if(!s->budget--) { s->failed_pc=0x0c04e4fau; return 0; }
write(ram,r[15],r[14],4);
goto P_0c04e4fc;
P_0c04e4fc: /* original d321, guest PC 0x0c04e4fc */
if(!s->budget--) { s->failed_pc=0x0c04e4fcu; return 0; }
r[3]=read(ram,0x0c04e584u,4);
goto P_0c04e4fe;
P_0c04e4fe: /* original 2fa6, guest PC 0x0c04e4fe */
if(!s->budget--) { s->failed_pc=0x0c04e4feu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e500;
P_0c04e500: /* original 3e3c, guest PC 0x0c04e500 */
if(!s->budget--) { s->failed_pc=0x0c04e500u; return 0; }
r[14]+=r[3];
goto P_0c04e502;
P_0c04e502: /* original 2fd6, guest PC 0x0c04e502 */
if(!s->budget--) { s->failed_pc=0x0c04e502u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e504;
P_0c04e504: /* original d220, guest PC 0x0c04e504 */
if(!s->budget--) { s->failed_pc=0x0c04e504u; return 0; }
r[2]=read(ram,0x0c04e588u,4);
goto P_0c04e506;
P_0c04e506: /* original d121, guest PC 0x0c04e506 */
if(!s->budget--) { s->failed_pc=0x0c04e506u; return 0; }
r[1]=read(ram,0x0c04e58cu,4);
goto P_0c04e508;
P_0c04e508: /* original 410b, guest PC 0x0c04e508 */
if(!s->budget--) { s->failed_pc=0x0c04e508u; return 0; }
target=r[1];
r[16]=0x0c04e50cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e50cu) { target=s->pc; goto dispatch; }
goto P_0c04e50c;
P_0c04e50a: /* original 2f26, guest PC 0x0c04e50a */
if(!s->budget--) { s->failed_pc=0x0c04e50au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e50c;
P_0c04e50c: /* original 84e2, guest PC 0x0c04e50c */
if(!s->budget--) { s->failed_pc=0x0c04e50cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c04e50e;
P_0c04e50e: /* original 2008, guest PC 0x0c04e50e */
if(!s->budget--) { s->failed_pc=0x0c04e50eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e510;
P_0c04e510: /* original 8d15, guest PC 0x0c04e510 */
if(!s->budget--) { s->failed_pc=0x0c04e510u; return 0; }
cond=r[17]&1u;
r[15]+=0x0000000cu;
if(cond) { goto P_0c04e53e; }
goto P_0c04e514;
P_0c04e512: /* original 7f0c, guest PC 0x0c04e512 */
if(!s->budget--) { s->failed_pc=0x0c04e512u; return 0; }
r[15]+=0x0000000cu;
goto P_0c04e514;
P_0c04e514: /* original d21e, guest PC 0x0c04e514 */
if(!s->budget--) { s->failed_pc=0x0c04e514u; return 0; }
r[2]=read(ram,0x0c04e590u,4);
goto P_0c04e516;
P_0c04e516: /* original 420b, guest PC 0x0c04e516 */
if(!s->budget--) { s->failed_pc=0x0c04e516u; return 0; }
target=r[2];
r[16]=0x0c04e51au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e51au) { target=s->pc; goto dispatch; }
goto P_0c04e51a;
P_0c04e518: /* original 64d3, guest PC 0x0c04e518 */
if(!s->budget--) { s->failed_pc=0x0c04e518u; return 0; }
r[4]=r[13];
goto P_0c04e51a;
P_0c04e51a: /* original 2008, guest PC 0x0c04e51a */
if(!s->budget--) { s->failed_pc=0x0c04e51au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e51c;
P_0c04e51c: /* original 8b04, guest PC 0x0c04e51c */
if(!s->budget--) { s->failed_pc=0x0c04e51cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e528; }
goto P_0c04e51e;
P_0c04e51e: /* original d21d, guest PC 0x0c04e51e */
if(!s->budget--) { s->failed_pc=0x0c04e51eu; return 0; }
r[2]=read(ram,0x0c04e594u,4);
goto P_0c04e520;
P_0c04e520: /* original 420b, guest PC 0x0c04e520 */
if(!s->budget--) { s->failed_pc=0x0c04e520u; return 0; }
target=r[2];
r[16]=0x0c04e524u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e524u) { target=s->pc; goto dispatch; }
goto P_0c04e524;
P_0c04e522: /* original 64d3, guest PC 0x0c04e522 */
if(!s->budget--) { s->failed_pc=0x0c04e522u; return 0; }
r[4]=r[13];
goto P_0c04e524;
P_0c04e524: /* original a00b, guest PC 0x0c04e524 */
if(!s->budget--) { s->failed_pc=0x0c04e524u; return 0; }
goto P_0c04e53e;
P_0c04e526: /* original 0009, guest PC 0x0c04e526 */
if(!s->budget--) { s->failed_pc=0x0c04e526u; return 0; }
goto P_0c04e528;
P_0c04e528: /* original d312, guest PC 0x0c04e528 */
if(!s->budget--) { s->failed_pc=0x0c04e528u; return 0; }
r[3]=read(ram,0x0c04e574u,4);
goto P_0c04e52a;
P_0c04e52a: /* original 430b, guest PC 0x0c04e52a */
if(!s->budget--) { s->failed_pc=0x0c04e52au; return 0; }
target=r[3];
r[16]=0x0c04e52eu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e52eu) { target=s->pc; goto dispatch; }
goto P_0c04e52e;
P_0c04e52c: /* original 64d3, guest PC 0x0c04e52c */
if(!s->budget--) { s->failed_pc=0x0c04e52cu; return 0; }
r[4]=r[13];
goto P_0c04e52e;
P_0c04e52e: /* original 2008, guest PC 0x0c04e52e */
if(!s->budget--) { s->failed_pc=0x0c04e52eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e530;
P_0c04e530: /* original 8905, guest PC 0x0c04e530 */
if(!s->budget--) { s->failed_pc=0x0c04e530u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e53e; }
goto P_0c04e532;
P_0c04e532: /* original 62f2, guest PC 0x0c04e532 */
if(!s->budget--) { s->failed_pc=0x0c04e532u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04e534;
P_0c04e534: /* original d313, guest PC 0x0c04e534 */
if(!s->budget--) { s->failed_pc=0x0c04e534u; return 0; }
r[3]=read(ram,0x0c04e584u,4);
goto P_0c04e536;
P_0c04e536: /* original 323c, guest PC 0x0c04e536 */
if(!s->budget--) { s->failed_pc=0x0c04e536u; return 0; }
r[2]+=r[3];
goto P_0c04e538;
P_0c04e538: /* original 8428, guest PC 0x0c04e538 */
if(!s->budget--) { s->failed_pc=0x0c04e538u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04e53a;
P_0c04e53a: /* original 2008, guest PC 0x0c04e53a */
if(!s->budget--) { s->failed_pc=0x0c04e53au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e53c;
P_0c04e53c: /* original 8b02, guest PC 0x0c04e53c */
if(!s->budget--) { s->failed_pc=0x0c04e53cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e544; }
goto P_0c04e53e;
P_0c04e53e: /* original 9015, guest PC 0x0c04e53e */
if(!s->budget--) { s->failed_pc=0x0c04e53eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e56cu,2);
goto P_0c04e540;
P_0c04e540: /* original a056, guest PC 0x0c04e540 */
if(!s->budget--) { s->failed_pc=0x0c04e540u; return 0; }
goto P_0c04e5f0;
P_0c04e542: /* original 0009, guest PC 0x0c04e542 */
if(!s->budget--) { s->failed_pc=0x0c04e542u; return 0; }
goto P_0c04e544;
P_0c04e544: /* original d30d, guest PC 0x0c04e544 */
if(!s->budget--) { s->failed_pc=0x0c04e544u; return 0; }
r[3]=read(ram,0x0c04e57cu,4);
goto P_0c04e546;
P_0c04e546: /* original 430b, guest PC 0x0c04e546 */
if(!s->budget--) { s->failed_pc=0x0c04e546u; return 0; }
target=r[3];
r[16]=0x0c04e54au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e54au) { target=s->pc; goto dispatch; }
goto P_0c04e54a;
P_0c04e548: /* original 64d3, guest PC 0x0c04e548 */
if(!s->budget--) { s->failed_pc=0x0c04e548u; return 0; }
r[4]=r[13];
goto P_0c04e54a;
P_0c04e54a: /* original 4011, guest PC 0x0c04e54a */
if(!s->budget--) { s->failed_pc=0x0c04e54au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e54c;
P_0c04e54c: /* original 8902, guest PC 0x0c04e54c */
if(!s->budget--) { s->failed_pc=0x0c04e54cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e554; }
goto P_0c04e54e;
P_0c04e54e: /* original 900e, guest PC 0x0c04e54e */
if(!s->budget--) { s->failed_pc=0x0c04e54eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e56eu,2);
goto P_0c04e550;
P_0c04e550: /* original a04e, guest PC 0x0c04e550 */
if(!s->budget--) { s->failed_pc=0x0c04e550u; return 0; }
goto P_0c04e5f0;
P_0c04e552: /* original 0009, guest PC 0x0c04e552 */
if(!s->budget--) { s->failed_pc=0x0c04e552u; return 0; }
goto P_0c04e554;
P_0c04e554: /* original ec00, guest PC 0x0c04e554 */
if(!s->budget--) { s->failed_pc=0x0c04e554u; return 0; }
r[12]=0x00000000u;
goto P_0c04e556;
P_0c04e556: /* original 65c3, guest PC 0x0c04e556 */
if(!s->budget--) { s->failed_pc=0x0c04e556u; return 0; }
r[5]=r[12];
goto P_0c04e558;
P_0c04e558: /* original 1ec6, guest PC 0x0c04e558 */
if(!s->budget--) { s->failed_pc=0x0c04e558u; return 0; }
write(ram,r[14]+24,r[12],4);
goto P_0c04e55a;
P_0c04e55a: /* original d30f, guest PC 0x0c04e55a */
if(!s->budget--) { s->failed_pc=0x0c04e55au; return 0; }
r[3]=read(ram,0x0c04e598u,4);
goto P_0c04e55c;
P_0c04e55c: /* original 430b, guest PC 0x0c04e55c */
if(!s->budget--) { s->failed_pc=0x0c04e55cu; return 0; }
target=r[3];
r[16]=0x0c04e560u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e560u) { target=s->pc; goto dispatch; }
goto P_0c04e560;
P_0c04e55e: /* original 64d3, guest PC 0x0c04e55e */
if(!s->budget--) { s->failed_pc=0x0c04e55eu; return 0; }
r[4]=r[13];
goto P_0c04e560;
P_0c04e560: /* original 65c3, guest PC 0x0c04e560 */
if(!s->budget--) { s->failed_pc=0x0c04e560u; return 0; }
r[5]=r[12];
goto P_0c04e562;
P_0c04e562: /* original 6dc3, guest PC 0x0c04e562 */
if(!s->budget--) { s->failed_pc=0x0c04e562u; return 0; }
r[13]=r[12];
goto P_0c04e564;
P_0c04e564: /* original 6403, guest PC 0x0c04e564 */
if(!s->budget--) { s->failed_pc=0x0c04e564u; return 0; }
r[4]=r[0];
goto P_0c04e566;
P_0c04e566: /* original a028, guest PC 0x0c04e566 */
if(!s->budget--) { s->failed_pc=0x0c04e566u; return 0; }
r[1]=0x00000001u;
goto P_0c04e5ba;
P_0c04e568: /* original e101, guest PC 0x0c04e568 */
if(!s->budget--) { s->failed_pc=0x0c04e568u; return 0; }
r[1]=0x00000001u;
return vf3_matrix_family(0x0c04e56au,s,ram);
P_0c04e59c: /* original 6640, guest PC 0x0c04e59c */
if(!s->budget--) { s->failed_pc=0x0c04e59cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[6]=tmp;
goto P_0c04e59e;
P_0c04e59e: /* original 676c, guest PC 0x0c04e59e */
if(!s->budget--) { s->failed_pc=0x0c04e59eu; return 0; }
r[7]=r[6]&255u;
goto P_0c04e5a0;
P_0c04e5a0: /* original 6073, guest PC 0x0c04e5a0 */
if(!s->budget--) { s->failed_pc=0x0c04e5a0u; return 0; }
r[0]=r[7];
goto P_0c04e5a2;
P_0c04e5a2: /* original 8833, guest PC 0x0c04e5a2 */
if(!s->budget--) { s->failed_pc=0x0c04e5a2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000033u)!=0);
goto P_0c04e5a4;
P_0c04e5a4: /* original 8902, guest PC 0x0c04e5a4 */
if(!s->budget--) { s->failed_pc=0x0c04e5a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e5ac; }
goto P_0c04e5a6;
P_0c04e5a6: /* original 926f, guest PC 0x0c04e5a6 */
if(!s->budget--) { s->failed_pc=0x0c04e5a6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e688u,2);
goto P_0c04e5a8;
P_0c04e5a8: /* original 3720, guest PC 0x0c04e5a8 */
if(!s->budget--) { s->failed_pc=0x0c04e5a8u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[2])!=0);
goto P_0c04e5aa;
P_0c04e5aa: /* original 8b01, guest PC 0x0c04e5aa */
if(!s->budget--) { s->failed_pc=0x0c04e5aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e5b0; }
goto P_0c04e5ac;
P_0c04e5ac: /* original a009, guest PC 0x0c04e5ac */
if(!s->budget--) { s->failed_pc=0x0c04e5acu; return 0; }
r[13]=r[1];
goto P_0c04e5c2;
P_0c04e5ae: /* original 6d13, guest PC 0x0c04e5ae */
if(!s->budget--) { s->failed_pc=0x0c04e5aeu; return 0; }
r[13]=r[1];
goto P_0c04e5b0;
P_0c04e5b0: /* original 53e6, guest PC 0x0c04e5b0 */
if(!s->budget--) { s->failed_pc=0x0c04e5b0u; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c04e5b2;
P_0c04e5b2: /* original 7420, guest PC 0x0c04e5b2 */
if(!s->budget--) { s->failed_pc=0x0c04e5b2u; return 0; }
r[4]+=0x00000020u;
goto P_0c04e5b4;
P_0c04e5b4: /* original 7501, guest PC 0x0c04e5b4 */
if(!s->budget--) { s->failed_pc=0x0c04e5b4u; return 0; }
r[5]+=0x00000001u;
goto P_0c04e5b6;
P_0c04e5b6: /* original 7301, guest PC 0x0c04e5b6 */
if(!s->budget--) { s->failed_pc=0x0c04e5b6u; return 0; }
r[3]+=0x00000001u;
goto P_0c04e5b8;
P_0c04e5b8: /* original 1e36, guest PC 0x0c04e5b8 */
if(!s->budget--) { s->failed_pc=0x0c04e5b8u; return 0; }
write(ram,r[14]+24,r[3],4);
goto P_0c04e5ba;
P_0c04e5ba: /* original 52e7, guest PC 0x0c04e5ba */
if(!s->budget--) { s->failed_pc=0x0c04e5bau; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c04e5bc;
P_0c04e5bc: /* original 532c, guest PC 0x0c04e5bc */
if(!s->budget--) { s->failed_pc=0x0c04e5bcu; return 0; }
r[3]=read(ram,r[2]+48,4);
goto P_0c04e5be;
P_0c04e5be: /* original 3533, guest PC 0x0c04e5be */
if(!s->budget--) { s->failed_pc=0x0c04e5beu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[3])!=0);
goto P_0c04e5c0;
P_0c04e5c0: /* original 8bec, guest PC 0x0c04e5c0 */
if(!s->budget--) { s->failed_pc=0x0c04e5c0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e59c; }
goto P_0c04e5c2;
P_0c04e5c2: /* original 2dd8, guest PC 0x0c04e5c2 */
if(!s->budget--) { s->failed_pc=0x0c04e5c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c04e5c4;
P_0c04e5c4: /* original 8b02, guest PC 0x0c04e5c4 */
if(!s->budget--) { s->failed_pc=0x0c04e5c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e5cc; }
goto P_0c04e5c6;
P_0c04e5c6: /* original 9060, guest PC 0x0c04e5c6 */
if(!s->budget--) { s->failed_pc=0x0c04e5c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e68au,2);
goto P_0c04e5c8;
P_0c04e5c8: /* original a012, guest PC 0x0c04e5c8 */
if(!s->budget--) { s->failed_pc=0x0c04e5c8u; return 0; }
goto P_0c04e5f0;
P_0c04e5ca: /* original 0009, guest PC 0x0c04e5ca */
if(!s->budget--) { s->failed_pc=0x0c04e5cau; return 0; }
goto P_0c04e5cc;
P_0c04e5cc: /* original 6743, guest PC 0x0c04e5cc */
if(!s->budget--) { s->failed_pc=0x0c04e5ccu; return 0; }
r[7]=r[4];
goto P_0c04e5ce;
P_0c04e5ce: /* original 64a3, guest PC 0x0c04e5ce */
if(!s->budget--) { s->failed_pc=0x0c04e5ceu; return 0; }
r[4]=r[10];
goto P_0c04e5d0;
P_0c04e5d0: /* original 7704, guest PC 0x0c04e5d0 */
if(!s->budget--) { s->failed_pc=0x0c04e5d0u; return 0; }
r[7]+=0x00000004u;
goto P_0c04e5d2;
P_0c04e5d2: /* original 65c3, guest PC 0x0c04e5d2 */
if(!s->budget--) { s->failed_pc=0x0c04e5d2u; return 0; }
r[5]=r[12];
goto P_0c04e5d4;
P_0c04e5d4: /* original a004, guest PC 0x0c04e5d4 */
if(!s->budget--) { s->failed_pc=0x0c04e5d4u; return 0; }
r[6]=0x0000000cu;
goto P_0c04e5e0;
P_0c04e5d6: /* original e60c, guest PC 0x0c04e5d6 */
if(!s->budget--) { s->failed_pc=0x0c04e5d6u; return 0; }
r[6]=0x0000000cu;
goto P_0c04e5d8;
P_0c04e5d8: /* original 6374, guest PC 0x0c04e5d8 */
if(!s->budget--) { s->failed_pc=0x0c04e5d8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[3]=tmp;
goto P_0c04e5da;
P_0c04e5da: /* original 7501, guest PC 0x0c04e5da */
if(!s->budget--) { s->failed_pc=0x0c04e5dau; return 0; }
r[5]+=0x00000001u;
goto P_0c04e5dc;
P_0c04e5dc: /* original 2430, guest PC 0x0c04e5dc */
if(!s->budget--) { s->failed_pc=0x0c04e5dcu; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04e5de;
P_0c04e5de: /* original 7401, guest PC 0x0c04e5de */
if(!s->budget--) { s->failed_pc=0x0c04e5deu; return 0; }
r[4]+=0x00000001u;
goto P_0c04e5e0;
P_0c04e5e0: /* original 3563, guest PC 0x0c04e5e0 */
if(!s->budget--) { s->failed_pc=0x0c04e5e0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c04e5e2;
P_0c04e5e2: /* original 8bf9, guest PC 0x0c04e5e2 */
if(!s->budget--) { s->failed_pc=0x0c04e5e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e5d8; }
goto P_0c04e5e4;
P_0c04e5e4: /* original 60c3, guest PC 0x0c04e5e4 */
if(!s->budget--) { s->failed_pc=0x0c04e5e4u; return 0; }
r[0]=r[12];
goto P_0c04e5e6;
P_0c04e5e6: /* original 80ac, guest PC 0x0c04e5e6 */
if(!s->budget--) { s->failed_pc=0x0c04e5e6u; return 0; }
write(ram,r[10]+12,r[0],1);
goto P_0c04e5e8;
P_0c04e5e8: /* original 53e6, guest PC 0x0c04e5e8 */
if(!s->budget--) { s->failed_pc=0x0c04e5e8u; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c04e5ea;
P_0c04e5ea: /* original e000, guest PC 0x0c04e5ea */
if(!s->budget--) { s->failed_pc=0x0c04e5eau; return 0; }
r[0]=0x00000000u;
goto P_0c04e5ec;
P_0c04e5ec: /* original 7301, guest PC 0x0c04e5ec */
if(!s->budget--) { s->failed_pc=0x0c04e5ecu; return 0; }
r[3]+=0x00000001u;
goto P_0c04e5ee;
P_0c04e5ee: /* original 1e36, guest PC 0x0c04e5ee */
if(!s->budget--) { s->failed_pc=0x0c04e5eeu; return 0; }
write(ram,r[14]+24,r[3],4);
goto P_0c04e5f0;
P_0c04e5f0: /* original 7f04, guest PC 0x0c04e5f0 */
if(!s->budget--) { s->failed_pc=0x0c04e5f0u; return 0; }
r[15]+=0x00000004u;
goto P_0c04e5f2;
P_0c04e5f2: /* original 4f16, guest PC 0x0c04e5f2 */
if(!s->budget--) { s->failed_pc=0x0c04e5f2u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e5f4;
P_0c04e5f4: /* original 4f26, guest PC 0x0c04e5f4 */
if(!s->budget--) { s->failed_pc=0x0c04e5f4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e5f6;
P_0c04e5f6: /* original 6af6, guest PC 0x0c04e5f6 */
if(!s->budget--) { s->failed_pc=0x0c04e5f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04e5f8;
P_0c04e5f8: /* original 6cf6, guest PC 0x0c04e5f8 */
if(!s->budget--) { s->failed_pc=0x0c04e5f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04e5fa;
P_0c04e5fa: /* original 6df6, guest PC 0x0c04e5fa */
if(!s->budget--) { s->failed_pc=0x0c04e5fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04e5fc;
P_0c04e5fc: /* original 000b, guest PC 0x0c04e5fc */
if(!s->budget--) { s->failed_pc=0x0c04e5fcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04e5fe: /* original 6ef6, guest PC 0x0c04e5fe */
if(!s->budget--) { s->failed_pc=0x0c04e5feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04e600;
P_0c04e600: /* original 2fe6, guest PC 0x0c04e600 */
if(!s->budget--) { s->failed_pc=0x0c04e600u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e602;
P_0c04e602: /* original 6e43, guest PC 0x0c04e602 */
if(!s->budget--) { s->failed_pc=0x0c04e602u; return 0; }
r[14]=r[4];
goto P_0c04e604;
P_0c04e604: /* original 2fd6, guest PC 0x0c04e604 */
if(!s->budget--) { s->failed_pc=0x0c04e604u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e606;
P_0c04e606: /* original 2fb6, guest PC 0x0c04e606 */
if(!s->budget--) { s->failed_pc=0x0c04e606u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e608;
P_0c04e608: /* original 6b53, guest PC 0x0c04e608 */
if(!s->budget--) { s->failed_pc=0x0c04e608u; return 0; }
r[11]=r[5];
goto P_0c04e60a;
P_0c04e60a: /* original 2fa6, guest PC 0x0c04e60a */
if(!s->budget--) { s->failed_pc=0x0c04e60au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e60c;
P_0c04e60c: /* original 4f22, guest PC 0x0c04e60c */
if(!s->budget--) { s->failed_pc=0x0c04e60cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04e60e;
P_0c04e60e: /* original 9d3d, guest PC 0x0c04e60e */
if(!s->budget--) { s->failed_pc=0x0c04e60eu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e68cu,2);
goto P_0c04e610;
P_0c04e610: /* original 4f12, guest PC 0x0c04e610 */
if(!s->budget--) { s->failed_pc=0x0c04e610u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04e612;
P_0c04e612: /* original 2edf, guest PC 0x0c04e612 */
if(!s->budget--) { s->failed_pc=0x0c04e612u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[13]);
goto P_0c04e614;
P_0c04e614: /* original 7ffc, guest PC 0x0c04e614 */
if(!s->budget--) { s->failed_pc=0x0c04e614u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04e616;
P_0c04e616: /* original 0d1a, guest PC 0x0c04e616 */
if(!s->budget--) { s->failed_pc=0x0c04e616u; return 0; }
r[13]=r[19];
goto P_0c04e618;
P_0c04e618: /* original 6ddf, guest PC 0x0c04e618 */
if(!s->budget--) { s->failed_pc=0x0c04e618u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c04e61a;
P_0c04e61a: /* original 2fd2, guest PC 0x0c04e61a */
if(!s->budget--) { s->failed_pc=0x0c04e61au; return 0; }
write(ram,r[15],r[13],4);
goto P_0c04e61c;
P_0c04e61c: /* original d31d, guest PC 0x0c04e61c */
if(!s->budget--) { s->failed_pc=0x0c04e61cu; return 0; }
r[3]=read(ram,0x0c04e694u,4);
goto P_0c04e61e;
P_0c04e61e: /* original 2fb6, guest PC 0x0c04e61e */
if(!s->budget--) { s->failed_pc=0x0c04e61eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e620;
P_0c04e620: /* original 3d3c, guest PC 0x0c04e620 */
if(!s->budget--) { s->failed_pc=0x0c04e620u; return 0; }
r[13]+=r[3];
goto P_0c04e622;
P_0c04e622: /* original 2fe6, guest PC 0x0c04e622 */
if(!s->budget--) { s->failed_pc=0x0c04e622u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e624;
P_0c04e624: /* original d21c, guest PC 0x0c04e624 */
if(!s->budget--) { s->failed_pc=0x0c04e624u; return 0; }
r[2]=read(ram,0x0c04e698u,4);
goto P_0c04e626;
P_0c04e626: /* original d11d, guest PC 0x0c04e626 */
if(!s->budget--) { s->failed_pc=0x0c04e626u; return 0; }
r[1]=read(ram,0x0c04e69cu,4);
goto P_0c04e628;
P_0c04e628: /* original 410b, guest PC 0x0c04e628 */
if(!s->budget--) { s->failed_pc=0x0c04e628u; return 0; }
target=r[1];
r[16]=0x0c04e62cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e62cu) { target=s->pc; goto dispatch; }
goto P_0c04e62c;
P_0c04e62a: /* original 2f26, guest PC 0x0c04e62a */
if(!s->budget--) { s->failed_pc=0x0c04e62au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e62c;
P_0c04e62c: /* original 84d2, guest PC 0x0c04e62c */
if(!s->budget--) { s->failed_pc=0x0c04e62cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+2,1);
goto P_0c04e62e;
P_0c04e62e: /* original 2008, guest PC 0x0c04e62e */
if(!s->budget--) { s->failed_pc=0x0c04e62eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e630;
P_0c04e630: /* original 8d15, guest PC 0x0c04e630 */
if(!s->budget--) { s->failed_pc=0x0c04e630u; return 0; }
cond=r[17]&1u;
r[15]+=0x0000000cu;
if(cond) { goto P_0c04e65e; }
goto P_0c04e634;
P_0c04e632: /* original 7f0c, guest PC 0x0c04e632 */
if(!s->budget--) { s->failed_pc=0x0c04e632u; return 0; }
r[15]+=0x0000000cu;
goto P_0c04e634;
P_0c04e634: /* original d21a, guest PC 0x0c04e634 */
if(!s->budget--) { s->failed_pc=0x0c04e634u; return 0; }
r[2]=read(ram,0x0c04e6a0u,4);
goto P_0c04e636;
P_0c04e636: /* original 420b, guest PC 0x0c04e636 */
if(!s->budget--) { s->failed_pc=0x0c04e636u; return 0; }
target=r[2];
r[16]=0x0c04e63au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e63au) { target=s->pc; goto dispatch; }
goto P_0c04e63a;
P_0c04e638: /* original 64e3, guest PC 0x0c04e638 */
if(!s->budget--) { s->failed_pc=0x0c04e638u; return 0; }
r[4]=r[14];
goto P_0c04e63a;
P_0c04e63a: /* original 2008, guest PC 0x0c04e63a */
if(!s->budget--) { s->failed_pc=0x0c04e63au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e63c;
P_0c04e63c: /* original 8b04, guest PC 0x0c04e63c */
if(!s->budget--) { s->failed_pc=0x0c04e63cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e648; }
goto P_0c04e63e;
P_0c04e63e: /* original d219, guest PC 0x0c04e63e */
if(!s->budget--) { s->failed_pc=0x0c04e63eu; return 0; }
r[2]=read(ram,0x0c04e6a4u,4);
goto P_0c04e640;
P_0c04e640: /* original 420b, guest PC 0x0c04e640 */
if(!s->budget--) { s->failed_pc=0x0c04e640u; return 0; }
target=r[2];
r[16]=0x0c04e644u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e644u) { target=s->pc; goto dispatch; }
goto P_0c04e644;
P_0c04e642: /* original 64e3, guest PC 0x0c04e642 */
if(!s->budget--) { s->failed_pc=0x0c04e642u; return 0; }
r[4]=r[14];
goto P_0c04e644;
P_0c04e644: /* original a00b, guest PC 0x0c04e644 */
if(!s->budget--) { s->failed_pc=0x0c04e644u; return 0; }
goto P_0c04e65e;
P_0c04e646: /* original 0009, guest PC 0x0c04e646 */
if(!s->budget--) { s->failed_pc=0x0c04e646u; return 0; }
goto P_0c04e648;
P_0c04e648: /* original d317, guest PC 0x0c04e648 */
if(!s->budget--) { s->failed_pc=0x0c04e648u; return 0; }
r[3]=read(ram,0x0c04e6a8u,4);
goto P_0c04e64a;
P_0c04e64a: /* original 430b, guest PC 0x0c04e64a */
if(!s->budget--) { s->failed_pc=0x0c04e64au; return 0; }
target=r[3];
r[16]=0x0c04e64eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e64eu) { target=s->pc; goto dispatch; }
goto P_0c04e64e;
P_0c04e64c: /* original 64e3, guest PC 0x0c04e64c */
if(!s->budget--) { s->failed_pc=0x0c04e64cu; return 0; }
r[4]=r[14];
goto P_0c04e64e;
P_0c04e64e: /* original 2008, guest PC 0x0c04e64e */
if(!s->budget--) { s->failed_pc=0x0c04e64eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e650;
P_0c04e650: /* original 8905, guest PC 0x0c04e650 */
if(!s->budget--) { s->failed_pc=0x0c04e650u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e65e; }
goto P_0c04e652;
P_0c04e652: /* original 62f2, guest PC 0x0c04e652 */
if(!s->budget--) { s->failed_pc=0x0c04e652u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04e654;
P_0c04e654: /* original d30f, guest PC 0x0c04e654 */
if(!s->budget--) { s->failed_pc=0x0c04e654u; return 0; }
r[3]=read(ram,0x0c04e694u,4);
goto P_0c04e656;
P_0c04e656: /* original 323c, guest PC 0x0c04e656 */
if(!s->budget--) { s->failed_pc=0x0c04e656u; return 0; }
r[2]+=r[3];
goto P_0c04e658;
P_0c04e658: /* original 8428, guest PC 0x0c04e658 */
if(!s->budget--) { s->failed_pc=0x0c04e658u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04e65a;
P_0c04e65a: /* original 2008, guest PC 0x0c04e65a */
if(!s->budget--) { s->failed_pc=0x0c04e65au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e65c;
P_0c04e65c: /* original 8b02, guest PC 0x0c04e65c */
if(!s->budget--) { s->failed_pc=0x0c04e65cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e664; }
goto P_0c04e65e;
P_0c04e65e: /* original 9016, guest PC 0x0c04e65e */
if(!s->budget--) { s->failed_pc=0x0c04e65eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e68eu,2);
goto P_0c04e660;
P_0c04e660: /* original a04f, guest PC 0x0c04e660 */
if(!s->budget--) { s->failed_pc=0x0c04e660u; return 0; }
goto P_0c04e702;
P_0c04e662: /* original 0009, guest PC 0x0c04e662 */
if(!s->budget--) { s->failed_pc=0x0c04e662u; return 0; }
goto P_0c04e664;
P_0c04e664: /* original d311, guest PC 0x0c04e664 */
if(!s->budget--) { s->failed_pc=0x0c04e664u; return 0; }
r[3]=read(ram,0x0c04e6acu,4);
goto P_0c04e666;
P_0c04e666: /* original 430b, guest PC 0x0c04e666 */
if(!s->budget--) { s->failed_pc=0x0c04e666u; return 0; }
target=r[3];
r[16]=0x0c04e66au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e66au) { target=s->pc; goto dispatch; }
goto P_0c04e66a;
P_0c04e668: /* original 64e3, guest PC 0x0c04e668 */
if(!s->budget--) { s->failed_pc=0x0c04e668u; return 0; }
r[4]=r[14];
goto P_0c04e66a;
P_0c04e66a: /* original 4011, guest PC 0x0c04e66a */
if(!s->budget--) { s->failed_pc=0x0c04e66au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e66c;
P_0c04e66c: /* original 8902, guest PC 0x0c04e66c */
if(!s->budget--) { s->failed_pc=0x0c04e66cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e674; }
goto P_0c04e66e;
P_0c04e66e: /* original 900f, guest PC 0x0c04e66e */
if(!s->budget--) { s->failed_pc=0x0c04e66eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e690u,2);
goto P_0c04e670;
P_0c04e670: /* original a047, guest PC 0x0c04e670 */
if(!s->budget--) { s->failed_pc=0x0c04e670u; return 0; }
goto P_0c04e702;
P_0c04e672: /* original 0009, guest PC 0x0c04e672 */
if(!s->budget--) { s->failed_pc=0x0c04e672u; return 0; }
goto P_0c04e674;
P_0c04e674: /* original d30e, guest PC 0x0c04e674 */
if(!s->budget--) { s->failed_pc=0x0c04e674u; return 0; }
r[3]=read(ram,0x0c04e6b0u,4);
goto P_0c04e676;
P_0c04e676: /* original 55d6, guest PC 0x0c04e676 */
if(!s->budget--) { s->failed_pc=0x0c04e676u; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c04e678;
P_0c04e678: /* original 430b, guest PC 0x0c04e678 */
if(!s->budget--) { s->failed_pc=0x0c04e678u; return 0; }
target=r[3];
r[16]=0x0c04e67cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e67cu) { target=s->pc; goto dispatch; }
goto P_0c04e67c;
P_0c04e67a: /* original 64e3, guest PC 0x0c04e67a */
if(!s->budget--) { s->failed_pc=0x0c04e67au; return 0; }
r[4]=r[14];
goto P_0c04e67c;
P_0c04e67c: /* original 55d6, guest PC 0x0c04e67c */
if(!s->budget--) { s->failed_pc=0x0c04e67cu; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c04e67e;
P_0c04e67e: /* original ea00, guest PC 0x0c04e67e */
if(!s->budget--) { s->failed_pc=0x0c04e67eu; return 0; }
r[10]=0x00000000u;
goto P_0c04e680;
P_0c04e680: /* original 6403, guest PC 0x0c04e680 */
if(!s->budget--) { s->failed_pc=0x0c04e680u; return 0; }
r[4]=r[0];
goto P_0c04e682;
P_0c04e682: /* original 6ea3, guest PC 0x0c04e682 */
if(!s->budget--) { s->failed_pc=0x0c04e682u; return 0; }
r[14]=r[10];
goto P_0c04e684;
P_0c04e684: /* original a025, guest PC 0x0c04e684 */
if(!s->budget--) { s->failed_pc=0x0c04e684u; return 0; }
r[6]=0x00000001u;
goto P_0c04e6d2;
P_0c04e686: /* original e601, guest PC 0x0c04e686 */
if(!s->budget--) { s->failed_pc=0x0c04e686u; return 0; }
r[6]=0x00000001u;
return vf3_matrix_family(0x0c04e688u,s,ram);
P_0c04e6b4: /* original 53d6, guest PC 0x0c04e6b4 */
if(!s->budget--) { s->failed_pc=0x0c04e6b4u; return 0; }
r[3]=read(ram,r[13]+24,4);
goto P_0c04e6b6;
P_0c04e6b6: /* original 7301, guest PC 0x0c04e6b6 */
if(!s->budget--) { s->failed_pc=0x0c04e6b6u; return 0; }
r[3]+=0x00000001u;
goto P_0c04e6b8;
P_0c04e6b8: /* original 1d36, guest PC 0x0c04e6b8 */
if(!s->budget--) { s->failed_pc=0x0c04e6b8u; return 0; }
write(ram,r[13]+24,r[3],4);
goto P_0c04e6ba;
P_0c04e6ba: /* original 6140, guest PC 0x0c04e6ba */
if(!s->budget--) { s->failed_pc=0x0c04e6bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[1]=tmp;
goto P_0c04e6bc;
P_0c04e6bc: /* original 671c, guest PC 0x0c04e6bc */
if(!s->budget--) { s->failed_pc=0x0c04e6bcu; return 0; }
r[7]=r[1]&255u;
goto P_0c04e6be;
P_0c04e6be: /* original 6073, guest PC 0x0c04e6be */
if(!s->budget--) { s->failed_pc=0x0c04e6beu; return 0; }
r[0]=r[7];
goto P_0c04e6c0;
P_0c04e6c0: /* original 8833, guest PC 0x0c04e6c0 */
if(!s->budget--) { s->failed_pc=0x0c04e6c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000033u)!=0);
goto P_0c04e6c2;
P_0c04e6c2: /* original 8902, guest PC 0x0c04e6c2 */
if(!s->budget--) { s->failed_pc=0x0c04e6c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e6ca; }
goto P_0c04e6c4;
P_0c04e6c4: /* original 9373, guest PC 0x0c04e6c4 */
if(!s->budget--) { s->failed_pc=0x0c04e6c4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e7aeu,2);
goto P_0c04e6c6;
P_0c04e6c6: /* original 3730, guest PC 0x0c04e6c6 */
if(!s->budget--) { s->failed_pc=0x0c04e6c6u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[3])!=0);
goto P_0c04e6c8;
P_0c04e6c8: /* original 8b01, guest PC 0x0c04e6c8 */
if(!s->budget--) { s->failed_pc=0x0c04e6c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e6ce; }
goto P_0c04e6ca;
P_0c04e6ca: /* original a006, guest PC 0x0c04e6ca */
if(!s->budget--) { s->failed_pc=0x0c04e6cau; return 0; }
r[14]=r[6];
goto P_0c04e6da;
P_0c04e6cc: /* original 6e63, guest PC 0x0c04e6cc */
if(!s->budget--) { s->failed_pc=0x0c04e6ccu; return 0; }
r[14]=r[6];
goto P_0c04e6ce;
P_0c04e6ce: /* original 7420, guest PC 0x0c04e6ce */
if(!s->budget--) { s->failed_pc=0x0c04e6ceu; return 0; }
r[4]+=0x00000020u;
goto P_0c04e6d0;
P_0c04e6d0: /* original 7501, guest PC 0x0c04e6d0 */
if(!s->budget--) { s->failed_pc=0x0c04e6d0u; return 0; }
r[5]+=0x00000001u;
goto P_0c04e6d2;
P_0c04e6d2: /* original 52d7, guest PC 0x0c04e6d2 */
if(!s->budget--) { s->failed_pc=0x0c04e6d2u; return 0; }
r[2]=read(ram,r[13]+28,4);
goto P_0c04e6d4;
P_0c04e6d4: /* original 532c, guest PC 0x0c04e6d4 */
if(!s->budget--) { s->failed_pc=0x0c04e6d4u; return 0; }
r[3]=read(ram,r[2]+48,4);
goto P_0c04e6d6;
P_0c04e6d6: /* original 3533, guest PC 0x0c04e6d6 */
if(!s->budget--) { s->failed_pc=0x0c04e6d6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[3])!=0);
goto P_0c04e6d8;
P_0c04e6d8: /* original 8bec, guest PC 0x0c04e6d8 */
if(!s->budget--) { s->failed_pc=0x0c04e6d8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e6b4; }
goto P_0c04e6da;
P_0c04e6da: /* original 2ee8, guest PC 0x0c04e6da */
if(!s->budget--) { s->failed_pc=0x0c04e6dau; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c04e6dc;
P_0c04e6dc: /* original 8b02, guest PC 0x0c04e6dc */
if(!s->budget--) { s->failed_pc=0x0c04e6dcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e6e4; }
goto P_0c04e6de;
P_0c04e6de: /* original 9067, guest PC 0x0c04e6de */
if(!s->budget--) { s->failed_pc=0x0c04e6deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e7b0u,2);
goto P_0c04e6e0;
P_0c04e6e0: /* original a00f, guest PC 0x0c04e6e0 */
if(!s->budget--) { s->failed_pc=0x0c04e6e0u; return 0; }
goto P_0c04e702;
P_0c04e6e2: /* original 0009, guest PC 0x0c04e6e2 */
if(!s->budget--) { s->failed_pc=0x0c04e6e2u; return 0; }
goto P_0c04e6e4;
P_0c04e6e4: /* original 6743, guest PC 0x0c04e6e4 */
if(!s->budget--) { s->failed_pc=0x0c04e6e4u; return 0; }
r[7]=r[4];
goto P_0c04e6e6;
P_0c04e6e6: /* original 64b3, guest PC 0x0c04e6e6 */
if(!s->budget--) { s->failed_pc=0x0c04e6e6u; return 0; }
r[4]=r[11];
goto P_0c04e6e8;
P_0c04e6e8: /* original 7704, guest PC 0x0c04e6e8 */
if(!s->budget--) { s->failed_pc=0x0c04e6e8u; return 0; }
r[7]+=0x00000004u;
goto P_0c04e6ea;
P_0c04e6ea: /* original 65a3, guest PC 0x0c04e6ea */
if(!s->budget--) { s->failed_pc=0x0c04e6eau; return 0; }
r[5]=r[10];
goto P_0c04e6ec;
P_0c04e6ec: /* original a004, guest PC 0x0c04e6ec */
if(!s->budget--) { s->failed_pc=0x0c04e6ecu; return 0; }
r[6]=0x0000000cu;
goto P_0c04e6f8;
P_0c04e6ee: /* original e60c, guest PC 0x0c04e6ee */
if(!s->budget--) { s->failed_pc=0x0c04e6eeu; return 0; }
r[6]=0x0000000cu;
goto P_0c04e6f0;
P_0c04e6f0: /* original 6374, guest PC 0x0c04e6f0 */
if(!s->budget--) { s->failed_pc=0x0c04e6f0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]+=1;
r[3]=tmp;
goto P_0c04e6f2;
P_0c04e6f2: /* original 7501, guest PC 0x0c04e6f2 */
if(!s->budget--) { s->failed_pc=0x0c04e6f2u; return 0; }
r[5]+=0x00000001u;
goto P_0c04e6f4;
P_0c04e6f4: /* original 2430, guest PC 0x0c04e6f4 */
if(!s->budget--) { s->failed_pc=0x0c04e6f4u; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04e6f6;
P_0c04e6f6: /* original 7401, guest PC 0x0c04e6f6 */
if(!s->budget--) { s->failed_pc=0x0c04e6f6u; return 0; }
r[4]+=0x00000001u;
goto P_0c04e6f8;
P_0c04e6f8: /* original 3563, guest PC 0x0c04e6f8 */
if(!s->budget--) { s->failed_pc=0x0c04e6f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c04e6fa;
P_0c04e6fa: /* original 8bf9, guest PC 0x0c04e6fa */
if(!s->budget--) { s->failed_pc=0x0c04e6fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e6f0; }
goto P_0c04e6fc;
P_0c04e6fc: /* original 60a3, guest PC 0x0c04e6fc */
if(!s->budget--) { s->failed_pc=0x0c04e6fcu; return 0; }
r[0]=r[10];
goto P_0c04e6fe;
P_0c04e6fe: /* original 80bc, guest PC 0x0c04e6fe */
if(!s->budget--) { s->failed_pc=0x0c04e6feu; return 0; }
write(ram,r[11]+12,r[0],1);
goto P_0c04e700;
P_0c04e700: /* original e000, guest PC 0x0c04e700 */
if(!s->budget--) { s->failed_pc=0x0c04e700u; return 0; }
r[0]=0x00000000u;
goto P_0c04e702;
P_0c04e702: /* original 7f04, guest PC 0x0c04e702 */
if(!s->budget--) { s->failed_pc=0x0c04e702u; return 0; }
r[15]+=0x00000004u;
goto P_0c04e704;
P_0c04e704: /* original 4f16, guest PC 0x0c04e704 */
if(!s->budget--) { s->failed_pc=0x0c04e704u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e706;
P_0c04e706: /* original 4f26, guest PC 0x0c04e706 */
if(!s->budget--) { s->failed_pc=0x0c04e706u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e708;
P_0c04e708: /* original 6af6, guest PC 0x0c04e708 */
if(!s->budget--) { s->failed_pc=0x0c04e708u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04e70a;
P_0c04e70a: /* original 6bf6, guest PC 0x0c04e70a */
if(!s->budget--) { s->failed_pc=0x0c04e70au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04e70c;
P_0c04e70c: /* original 6df6, guest PC 0x0c04e70c */
if(!s->budget--) { s->failed_pc=0x0c04e70cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04e70e;
P_0c04e70e: /* original 000b, guest PC 0x0c04e70e */
if(!s->budget--) { s->failed_pc=0x0c04e70eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04e710: /* original 6ef6, guest PC 0x0c04e710 */
if(!s->budget--) { s->failed_pc=0x0c04e710u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04e712u,s,ram);
P_0c04ef8c: /* original 2fe6, guest PC 0x0c04ef8c */
if(!s->budget--) { s->failed_pc=0x0c04ef8cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ef8e;
P_0c04ef8e: /* original 6e43, guest PC 0x0c04ef8e */
if(!s->budget--) { s->failed_pc=0x0c04ef8eu; return 0; }
r[14]=r[4];
goto P_0c04ef90;
P_0c04ef90: /* original 2fd6, guest PC 0x0c04ef90 */
if(!s->budget--) { s->failed_pc=0x0c04ef90u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04ef92;
P_0c04ef92: /* original 4f22, guest PC 0x0c04ef92 */
if(!s->budget--) { s->failed_pc=0x0c04ef92u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04ef94;
P_0c04ef94: /* original 934c, guest PC 0x0c04ef94 */
if(!s->budget--) { s->failed_pc=0x0c04ef94u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f030u,2);
goto P_0c04ef96;
P_0c04ef96: /* original d029, guest PC 0x0c04ef96 */
if(!s->budget--) { s->failed_pc=0x0c04ef96u; return 0; }
r[0]=read(ram,0x0c04f03cu,4);
goto P_0c04ef98;
P_0c04ef98: /* original 4f12, guest PC 0x0c04ef98 */
if(!s->budget--) { s->failed_pc=0x0c04ef98u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04ef9a;
P_0c04ef9a: /* original 2e3f, guest PC 0x0c04ef9a */
if(!s->budget--) { s->failed_pc=0x0c04ef9au; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c04ef9c;
P_0c04ef9c: /* original 7fd4, guest PC 0x0c04ef9c */
if(!s->budget--) { s->failed_pc=0x0c04ef9cu; return 0; }
r[15]+=0xffffffd4u;
goto P_0c04ef9e;
P_0c04ef9e: /* original 031a, guest PC 0x0c04ef9e */
if(!s->budget--) { s->failed_pc=0x0c04ef9eu; return 0; }
r[3]=r[19];
goto P_0c04efa0;
P_0c04efa0: /* original 633f, guest PC 0x0c04efa0 */
if(!s->budget--) { s->failed_pc=0x0c04efa0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04efa2;
P_0c04efa2: /* original 023c, guest PC 0x0c04efa2 */
if(!s->budget--) { s->failed_pc=0x0c04efa2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04efa4;
P_0c04efa4: /* original 2228, guest PC 0x0c04efa4 */
if(!s->budget--) { s->failed_pc=0x0c04efa4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04efa6;
P_0c04efa6: /* original 8d17, guest PC 0x0c04efa6 */
if(!s->budget--) { s->failed_pc=0x0c04efa6u; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c04efd8; }
goto P_0c04efaa;
P_0c04efa8: /* original 6d53, guest PC 0x0c04efa8 */
if(!s->budget--) { s->failed_pc=0x0c04efa8u; return 0; }
r[13]=r[5];
goto P_0c04efaa;
P_0c04efaa: /* original d325, guest PC 0x0c04efaa */
if(!s->budget--) { s->failed_pc=0x0c04efaau; return 0; }
r[3]=read(ram,0x0c04f040u,4);
goto P_0c04efac;
P_0c04efac: /* original 430b, guest PC 0x0c04efac */
if(!s->budget--) { s->failed_pc=0x0c04efacu; return 0; }
target=r[3];
r[16]=0x0c04efb0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04efb0u) { target=s->pc; goto dispatch; }
goto P_0c04efb0;
P_0c04efae: /* original 64e3, guest PC 0x0c04efae */
if(!s->budget--) { s->failed_pc=0x0c04efaeu; return 0; }
r[4]=r[14];
goto P_0c04efb0;
P_0c04efb0: /* original 2008, guest PC 0x0c04efb0 */
if(!s->budget--) { s->failed_pc=0x0c04efb0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04efb2;
P_0c04efb2: /* original 8b04, guest PC 0x0c04efb2 */
if(!s->budget--) { s->failed_pc=0x0c04efb2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04efbe; }
goto P_0c04efb4;
P_0c04efb4: /* original d323, guest PC 0x0c04efb4 */
if(!s->budget--) { s->failed_pc=0x0c04efb4u; return 0; }
r[3]=read(ram,0x0c04f044u,4);
goto P_0c04efb6;
P_0c04efb6: /* original 430b, guest PC 0x0c04efb6 */
if(!s->budget--) { s->failed_pc=0x0c04efb6u; return 0; }
target=r[3];
r[16]=0x0c04efbau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04efbau) { target=s->pc; goto dispatch; }
goto P_0c04efba;
P_0c04efb8: /* original 64e3, guest PC 0x0c04efb8 */
if(!s->budget--) { s->failed_pc=0x0c04efb8u; return 0; }
r[4]=r[14];
goto P_0c04efba;
P_0c04efba: /* original a00d, guest PC 0x0c04efba */
if(!s->budget--) { s->failed_pc=0x0c04efbau; return 0; }
goto P_0c04efd8;
P_0c04efbc: /* original 0009, guest PC 0x0c04efbc */
if(!s->budget--) { s->failed_pc=0x0c04efbcu; return 0; }
goto P_0c04efbe;
P_0c04efbe: /* original d222, guest PC 0x0c04efbe */
if(!s->budget--) { s->failed_pc=0x0c04efbeu; return 0; }
r[2]=read(ram,0x0c04f048u,4);
goto P_0c04efc0;
P_0c04efc0: /* original 420b, guest PC 0x0c04efc0 */
if(!s->budget--) { s->failed_pc=0x0c04efc0u; return 0; }
target=r[2];
r[16]=0x0c04efc4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04efc4u) { target=s->pc; goto dispatch; }
goto P_0c04efc4;
P_0c04efc2: /* original 64e3, guest PC 0x0c04efc2 */
if(!s->budget--) { s->failed_pc=0x0c04efc2u; return 0; }
r[4]=r[14];
goto P_0c04efc4;
P_0c04efc4: /* original 2008, guest PC 0x0c04efc4 */
if(!s->budget--) { s->failed_pc=0x0c04efc4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04efc6;
P_0c04efc6: /* original 8907, guest PC 0x0c04efc6 */
if(!s->budget--) { s->failed_pc=0x0c04efc6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04efd8; }
goto P_0c04efc8;
P_0c04efc8: /* original 9332, guest PC 0x0c04efc8 */
if(!s->budget--) { s->failed_pc=0x0c04efc8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f030u,2);
goto P_0c04efca;
P_0c04efca: /* original d020, guest PC 0x0c04efca */
if(!s->budget--) { s->failed_pc=0x0c04efcau; return 0; }
r[0]=read(ram,0x0c04f04cu,4);
goto P_0c04efcc;
P_0c04efcc: /* original 2e3f, guest PC 0x0c04efcc */
if(!s->budget--) { s->failed_pc=0x0c04efccu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c04efce;
P_0c04efce: /* original 031a, guest PC 0x0c04efce */
if(!s->budget--) { s->failed_pc=0x0c04efceu; return 0; }
r[3]=r[19];
goto P_0c04efd0;
P_0c04efd0: /* original 633f, guest PC 0x0c04efd0 */
if(!s->budget--) { s->failed_pc=0x0c04efd0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04efd2;
P_0c04efd2: /* original 023c, guest PC 0x0c04efd2 */
if(!s->budget--) { s->failed_pc=0x0c04efd2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04efd4;
P_0c04efd4: /* original 2228, guest PC 0x0c04efd4 */
if(!s->budget--) { s->failed_pc=0x0c04efd4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04efd6;
P_0c04efd6: /* original 8b02, guest PC 0x0c04efd6 */
if(!s->budget--) { s->failed_pc=0x0c04efd6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04efde; }
goto P_0c04efd8;
P_0c04efd8: /* original 902b, guest PC 0x0c04efd8 */
if(!s->budget--) { s->failed_pc=0x0c04efd8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f032u,2);
goto P_0c04efda;
P_0c04efda: /* original a020, guest PC 0x0c04efda */
if(!s->budget--) { s->failed_pc=0x0c04efdau; return 0; }
goto P_0c04f01e;
P_0c04efdc: /* original 0009, guest PC 0x0c04efdc */
if(!s->budget--) { s->failed_pc=0x0c04efdcu; return 0; }
goto P_0c04efde;
P_0c04efde: /* original d315, guest PC 0x0c04efde */
if(!s->budget--) { s->failed_pc=0x0c04efdeu; return 0; }
r[3]=read(ram,0x0c04f034u,4);
goto P_0c04efe0;
P_0c04efe0: /* original 430b, guest PC 0x0c04efe0 */
if(!s->budget--) { s->failed_pc=0x0c04efe0u; return 0; }
target=r[3];
r[16]=0x0c04efe4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04efe4u) { target=s->pc; goto dispatch; }
goto P_0c04efe4;
P_0c04efe2: /* original 64e3, guest PC 0x0c04efe2 */
if(!s->budget--) { s->failed_pc=0x0c04efe2u; return 0; }
r[4]=r[14];
goto P_0c04efe4;
P_0c04efe4: /* original 4011, guest PC 0x0c04efe4 */
if(!s->budget--) { s->failed_pc=0x0c04efe4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04efe6;
P_0c04efe6: /* original 8902, guest PC 0x0c04efe6 */
if(!s->budget--) { s->failed_pc=0x0c04efe6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04efee; }
goto P_0c04efe8;
P_0c04efe8: /* original 901f, guest PC 0x0c04efe8 */
if(!s->budget--) { s->failed_pc=0x0c04efe8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f02au,2);
goto P_0c04efea;
P_0c04efea: /* original a018, guest PC 0x0c04efea */
if(!s->budget--) { s->failed_pc=0x0c04efeau; return 0; }
goto P_0c04f01e;
P_0c04efec: /* original 0009, guest PC 0x0c04efec */
if(!s->budget--) { s->failed_pc=0x0c04efecu; return 0; }
goto P_0c04efee;
P_0c04efee: /* original 65f3, guest PC 0x0c04efee */
if(!s->budget--) { s->failed_pc=0x0c04efeeu; return 0; }
r[5]=r[15];
goto P_0c04eff0;
P_0c04eff0: /* original b522, guest PC 0x0c04eff0 */
if(!s->budget--) { s->failed_pc=0x0c04eff0u; return 0; }
target=0x0c04fa38u; r[16]=0x0c04eff4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04eff4u) { target=s->pc; goto dispatch; }
goto P_0c04eff4;
P_0c04eff2: /* original 64e3, guest PC 0x0c04eff2 */
if(!s->budget--) { s->failed_pc=0x0c04eff2u; return 0; }
r[4]=r[14];
goto P_0c04eff4;
P_0c04eff4: /* original 6403, guest PC 0x0c04eff4 */
if(!s->budget--) { s->failed_pc=0x0c04eff4u; return 0; }
r[4]=r[0];
goto P_0c04eff6;
P_0c04eff6: /* original 4411, guest PC 0x0c04eff6 */
if(!s->budget--) { s->failed_pc=0x0c04eff6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c04eff8;
P_0c04eff8: /* original 8902, guest PC 0x0c04eff8 */
if(!s->budget--) { s->failed_pc=0x0c04eff8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f000; }
goto P_0c04effa;
P_0c04effa: /* original 9018, guest PC 0x0c04effa */
if(!s->budget--) { s->failed_pc=0x0c04effau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f02eu,2);
goto P_0c04effc;
P_0c04effc: /* original a00f, guest PC 0x0c04effc */
if(!s->budget--) { s->failed_pc=0x0c04effcu; return 0; }
goto P_0c04f01e;
P_0c04effe: /* original 0009, guest PC 0x0c04effe */
if(!s->budget--) { s->failed_pc=0x0c04effeu; return 0; }
goto P_0c04f000;
P_0c04f000: /* original e600, guest PC 0x0c04f000 */
if(!s->budget--) { s->failed_pc=0x0c04f000u; return 0; }
r[6]=0x00000000u;
goto P_0c04f002;
P_0c04f002: /* original 6463, guest PC 0x0c04f002 */
if(!s->budget--) { s->failed_pc=0x0c04f002u; return 0; }
r[4]=r[6];
goto P_0c04f004;
P_0c04f004: /* original a006, guest PC 0x0c04f004 */
if(!s->budget--) { s->failed_pc=0x0c04f004u; return 0; }
r[5]=0x0000000cu;
goto P_0c04f014;
P_0c04f006: /* original e50c, guest PC 0x0c04f006 */
if(!s->budget--) { s->failed_pc=0x0c04f006u; return 0; }
r[5]=0x0000000cu;
goto P_0c04f008;
P_0c04f008: /* original 63f3, guest PC 0x0c04f008 */
if(!s->budget--) { s->failed_pc=0x0c04f008u; return 0; }
r[3]=r[15];
goto P_0c04f00a;
P_0c04f00a: /* original 7310, guest PC 0x0c04f00a */
if(!s->budget--) { s->failed_pc=0x0c04f00au; return 0; }
r[3]+=0x00000010u;
goto P_0c04f00c;
P_0c04f00c: /* original 6043, guest PC 0x0c04f00c */
if(!s->budget--) { s->failed_pc=0x0c04f00cu; return 0; }
r[0]=r[4];
goto P_0c04f00e;
P_0c04f00e: /* original 033c, guest PC 0x0c04f00e */
if(!s->budget--) { s->failed_pc=0x0c04f00eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04f010;
P_0c04f010: /* original 7401, guest PC 0x0c04f010 */
if(!s->budget--) { s->failed_pc=0x0c04f010u; return 0; }
r[4]+=0x00000001u;
goto P_0c04f012;
P_0c04f012: /* original 0d34, guest PC 0x0c04f012 */
if(!s->budget--) { s->failed_pc=0x0c04f012u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c04f014;
P_0c04f014: /* original 3453, guest PC 0x0c04f014 */
if(!s->budget--) { s->failed_pc=0x0c04f014u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c04f016;
P_0c04f016: /* original 8bf7, guest PC 0x0c04f016 */
if(!s->budget--) { s->failed_pc=0x0c04f016u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f008; }
goto P_0c04f018;
P_0c04f018: /* original 6063, guest PC 0x0c04f018 */
if(!s->budget--) { s->failed_pc=0x0c04f018u; return 0; }
r[0]=r[6];
goto P_0c04f01a;
P_0c04f01a: /* original 80dc, guest PC 0x0c04f01a */
if(!s->budget--) { s->failed_pc=0x0c04f01au; return 0; }
write(ram,r[13]+12,r[0],1);
goto P_0c04f01c;
P_0c04f01c: /* original e000, guest PC 0x0c04f01c */
if(!s->budget--) { s->failed_pc=0x0c04f01cu; return 0; }
r[0]=0x00000000u;
goto P_0c04f01e;
P_0c04f01e: /* original 7f2c, guest PC 0x0c04f01e */
if(!s->budget--) { s->failed_pc=0x0c04f01eu; return 0; }
r[15]+=0x0000002cu;
goto P_0c04f020;
P_0c04f020: /* original 4f16, guest PC 0x0c04f020 */
if(!s->budget--) { s->failed_pc=0x0c04f020u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f022;
P_0c04f022: /* original 4f26, guest PC 0x0c04f022 */
if(!s->budget--) { s->failed_pc=0x0c04f022u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f024;
P_0c04f024: /* original 6df6, guest PC 0x0c04f024 */
if(!s->budget--) { s->failed_pc=0x0c04f024u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04f026;
P_0c04f026: /* original 000b, guest PC 0x0c04f026 */
if(!s->budget--) { s->failed_pc=0x0c04f026u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f028: /* original 6ef6, guest PC 0x0c04f028 */
if(!s->budget--) { s->failed_pc=0x0c04f028u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04f02au,s,ram);
P_0c04fa38: /* original 2fe6, guest PC 0x0c04fa38 */
if(!s->budget--) { s->failed_pc=0x0c04fa38u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fa3a;
P_0c04fa3a: /* original 2fd6, guest PC 0x0c04fa3a */
if(!s->budget--) { s->failed_pc=0x0c04fa3au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fa3c;
P_0c04fa3c: /* original 4f22, guest PC 0x0c04fa3c */
if(!s->budget--) { s->failed_pc=0x0c04fa3cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04fa3e;
P_0c04fa3e: /* original 9651, guest PC 0x0c04fa3e */
if(!s->budget--) { s->failed_pc=0x0c04fa3eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fae4u,2);
goto P_0c04fa40;
P_0c04fa40: /* original d32b, guest PC 0x0c04fa40 */
if(!s->budget--) { s->failed_pc=0x0c04fa40u; return 0; }
r[3]=read(ram,0x0c04faf0u,4);
goto P_0c04fa42;
P_0c04fa42: /* original 4f12, guest PC 0x0c04fa42 */
if(!s->budget--) { s->failed_pc=0x0c04fa42u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fa44;
P_0c04fa44: /* original 246f, guest PC 0x0c04fa44 */
if(!s->budget--) { s->failed_pc=0x0c04fa44u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[6]);
goto P_0c04fa46;
P_0c04fa46: /* original 944e, guest PC 0x0c04fa46 */
if(!s->budget--) { s->failed_pc=0x0c04fa46u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fae6u,2);
goto P_0c04fa48;
P_0c04fa48: /* original 061a, guest PC 0x0c04fa48 */
if(!s->budget--) { s->failed_pc=0x0c04fa48u; return 0; }
r[6]=r[19];
goto P_0c04fa4a;
P_0c04fa4a: /* original 666f, guest PC 0x0c04fa4a */
if(!s->budget--) { s->failed_pc=0x0c04fa4au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c04fa4c;
P_0c04fa4c: /* original 363c, guest PC 0x0c04fa4c */
if(!s->budget--) { s->failed_pc=0x0c04fa4cu; return 0; }
r[6]+=r[3];
goto P_0c04fa4e;
P_0c04fa4e: /* original 5d6a, guest PC 0x0c04fa4e */
if(!s->budget--) { s->failed_pc=0x0c04fa4eu; return 0; }
r[13]=read(ram,r[6]+40,4);
goto P_0c04fa50;
P_0c04fa50: /* original a00a, guest PC 0x0c04fa50 */
if(!s->budget--) { s->failed_pc=0x0c04fa50u; return 0; }
r[14]=0x00000000u;
goto P_0c04fa68;
P_0c04fa52: /* original ee00, guest PC 0x0c04fa52 */
if(!s->budget--) { s->failed_pc=0x0c04fa52u; return 0; }
r[14]=0x00000000u;
goto P_0c04fa54;
P_0c04fa54: /* original 67d0, guest PC 0x0c04fa54 */
if(!s->budget--) { s->failed_pc=0x0c04fa54u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[7]=tmp;
goto P_0c04fa56;
P_0c04fa56: /* original 677c, guest PC 0x0c04fa56 */
if(!s->budget--) { s->failed_pc=0x0c04fa56u; return 0; }
r[7]=r[7]&255u;
goto P_0c04fa58;
P_0c04fa58: /* original 3740, guest PC 0x0c04fa58 */
if(!s->budget--) { s->failed_pc=0x0c04fa58u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[4])!=0);
goto P_0c04fa5a;
P_0c04fa5a: /* original 8b03, guest PC 0x0c04fa5a */
if(!s->budget--) { s->failed_pc=0x0c04fa5au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fa64; }
goto P_0c04fa5c;
P_0c04fa5c: /* original bf53, guest PC 0x0c04fa5c */
if(!s->budget--) { s->failed_pc=0x0c04fa5cu; return 0; }
target=0x0c04f906u; r[16]=0x0c04fa60u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04fa60u) { target=s->pc; goto dispatch; }
goto P_0c04fa60;
P_0c04fa5e: /* original 64d3, guest PC 0x0c04fa5e */
if(!s->budget--) { s->failed_pc=0x0c04fa5eu; return 0; }
r[4]=r[13];
goto P_0c04fa60;
P_0c04fa60: /* original a007, guest PC 0x0c04fa60 */
if(!s->budget--) { s->failed_pc=0x0c04fa60u; return 0; }
r[0]=r[14];
goto P_0c04fa72;
P_0c04fa62: /* original 60e3, guest PC 0x0c04fa62 */
if(!s->budget--) { s->failed_pc=0x0c04fa62u; return 0; }
r[0]=r[14];
goto P_0c04fa64;
P_0c04fa64: /* original 7d20, guest PC 0x0c04fa64 */
if(!s->budget--) { s->failed_pc=0x0c04fa64u; return 0; }
r[13]+=0x00000020u;
goto P_0c04fa66;
P_0c04fa66: /* original 7e01, guest PC 0x0c04fa66 */
if(!s->budget--) { s->failed_pc=0x0c04fa66u; return 0; }
r[14]+=0x00000001u;
goto P_0c04fa68;
P_0c04fa68: /* original 5367, guest PC 0x0c04fa68 */
if(!s->budget--) { s->failed_pc=0x0c04fa68u; return 0; }
r[3]=read(ram,r[6]+28,4);
goto P_0c04fa6a;
P_0c04fa6a: /* original 523c, guest PC 0x0c04fa6a */
if(!s->budget--) { s->failed_pc=0x0c04fa6au; return 0; }
r[2]=read(ram,r[3]+48,4);
goto P_0c04fa6c;
P_0c04fa6c: /* original 3e23, guest PC 0x0c04fa6c */
if(!s->budget--) { s->failed_pc=0x0c04fa6cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c04fa6e;
P_0c04fa6e: /* original 8bf1, guest PC 0x0c04fa6e */
if(!s->budget--) { s->failed_pc=0x0c04fa6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fa54; }
goto P_0c04fa70;
P_0c04fa70: /* original e0ff, guest PC 0x0c04fa70 */
if(!s->budget--) { s->failed_pc=0x0c04fa70u; return 0; }
r[0]=0xffffffffu;
goto P_0c04fa72;
P_0c04fa72: /* original 4f16, guest PC 0x0c04fa72 */
if(!s->budget--) { s->failed_pc=0x0c04fa72u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fa74;
P_0c04fa74: /* original 4f26, guest PC 0x0c04fa74 */
if(!s->budget--) { s->failed_pc=0x0c04fa74u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fa76;
P_0c04fa76: /* original 6df6, guest PC 0x0c04fa76 */
if(!s->budget--) { s->failed_pc=0x0c04fa76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fa78;
P_0c04fa78: /* original 000b, guest PC 0x0c04fa78 */
if(!s->budget--) { s->failed_pc=0x0c04fa78u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04fa7a: /* original 6ef6, guest PC 0x0c04fa7a */
if(!s->budget--) { s->failed_pc=0x0c04fa7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04fa7cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c04d50cu,0x0c04d50eu,0x0c04d510u,0x0c04d512u,0x0c04d514u,0x0c04d516u,0x0c04d518u,0x0c04d51au,0x0c04d51cu,0x0c04d51eu,0x0c04d520u,0x0c04d522u,0x0c04d524u,0x0c04d526u,0x0c04d528u,0x0c04d52au,
0x0c04d52cu,0x0c04d52eu,0x0c04d530u,0x0c04d532u,0x0c04d534u,0x0c04d536u,0x0c04d538u,0x0c04d53au,0x0c04d53cu,0x0c04d53eu,0x0c04d540u,0x0c04d542u,0x0c04d544u,0x0c04d546u,0x0c04d548u,0x0c04d54au,
0x0c04d54cu,0x0c04d560u,0x0c04d562u,0x0c04d564u,0x0c04d566u,0x0c04d568u,0x0c04d56au,0x0c04d56cu,0x0c04d56eu,0x0c04d570u,0x0c04d572u,0x0c04d574u,0x0c04d576u,0x0c04d578u,0x0c04d57au,0x0c04d57cu,
0x0c04d57eu,0x0c04d580u,0x0c04d582u,0x0c04d584u,0x0c04d586u,0x0c04d588u,0x0c04d58au,0x0c04d58cu,0x0c04d58eu,0x0c04d590u,0x0c04d592u,0x0c04d594u,0x0c04d596u,0x0c04d598u,0x0c04d59au,0x0c04d59cu,
0x0c04d59eu,0x0c04d5a0u,0x0c04d5a2u,0x0c04d5a4u,0x0c04d5a6u,0x0c04d5a8u,0x0c04d5aau,0x0c04d5acu,0x0c04d5aeu,0x0c04d5b0u,0x0c04d5b2u,0x0c04d5b4u,0x0c04d5b6u,0x0c04d5b8u,0x0c04d5bau,0x0c04d5bcu,
0x0c04d5beu,0x0c04d5c0u,0x0c04d5c2u,0x0c04d5c4u,0x0c04d5c6u,0x0c04d5c8u,0x0c04d5cau,0x0c04d5ccu,0x0c04d5ceu,0x0c04d5d0u,0x0c04d5d2u,0x0c04d5d4u,0x0c04d5d6u,0x0c04d5d8u,0x0c04d5dau,0x0c04d5dcu,
0x0c04d5deu,0x0c04d5e0u,0x0c04d5e2u,0x0c04d5e4u,0x0c04d5e6u,0x0c04d5e8u,0x0c04d5eau,0x0c04d5ecu,0x0c04d5eeu,0x0c04d5f0u,0x0c04d5f2u,0x0c04d5f4u,0x0c04d5f6u,0x0c04d5f8u,0x0c04d5fau,0x0c04d5fcu,
0x0c04d5feu,0x0c04d600u,0x0c04d602u,0x0c04d604u,0x0c04d606u,0x0c04d608u,0x0c04d60au,0x0c04d60cu,0x0c04d60eu,0x0c04d610u,0x0c04d612u,0x0c04d614u,0x0c04d616u,0x0c04d618u,0x0c04d61au,0x0c04d61cu,
0x0c04d61eu,0x0c04d620u,0x0c04d622u,0x0c04d624u,0x0c04d626u,0x0c04d628u,0x0c04d62au,0x0c04d62cu,0x0c04d62eu,0x0c04d630u,0x0c04d632u,0x0c04d634u,0x0c04d636u,0x0c04d638u,0x0c04d63au,0x0c04d63cu,
0x0c04d63eu,0x0c04d640u,0x0c04d642u,0x0c04d644u,0x0c04d646u,0x0c04d648u,0x0c04d64au,0x0c04d64cu,0x0c04d64eu,0x0c04d650u,0x0c04d652u,0x0c04d654u,0x0c04d656u,0x0c04d658u,0x0c04d65au,0x0c04d65cu,
0x0c04d65eu,0x0c04d660u,0x0c04d662u,0x0c04d664u,0x0c04d666u,0x0c04d668u,0x0c04d66au,0x0c04d66cu,0x0c04d66eu,0x0c04d670u,0x0c04d672u,0x0c04d674u,0x0c04d698u,0x0c04d69au,0x0c04d69cu,0x0c04d69eu,
0x0c04d6a0u,0x0c04d6a2u,0x0c04d6a4u,0x0c04d6a6u,0x0c04d6a8u,0x0c04d6aau,0x0c04d6acu,0x0c04d6aeu,0x0c04d6b0u,0x0c04d6b2u,0x0c04d6b4u,0x0c04d6b6u,0x0c04d6b8u,0x0c04d6bau,0x0c04d6bcu,0x0c04d6beu,
0x0c04d6c0u,0x0c04d6c2u,0x0c04d6c4u,0x0c04d6c6u,0x0c04d6c8u,0x0c04d6cau,0x0c04d6ccu,0x0c04d6ceu,0x0c04d6d0u,0x0c04d6d2u,0x0c04d6d4u,0x0c04d6d6u,0x0c04d6d8u,0x0c04d6dau,0x0c04d6dcu,0x0c04d6deu,
0x0c04d6e0u,0x0c04d6e2u,0x0c04d6e4u,0x0c04d6e6u,0x0c04d6e8u,0x0c04d6eau,0x0c04d6ecu,0x0c04d6eeu,0x0c04d6f0u,0x0c04d6f2u,0x0c04d6f4u,0x0c04d6f6u,0x0c04d6f8u,0x0c04d6fau,0x0c04d6fcu,0x0c04d6feu,
0x0c04d700u,0x0c04d702u,0x0c04d704u,0x0c04d706u,0x0c04d708u,0x0c04d70au,0x0c04d70cu,0x0c04d70eu,0x0c04d710u,0x0c04d712u,0x0c04d714u,0x0c04d716u,0x0c04d718u,0x0c04d71au,0x0c04d71cu,0x0c04d71eu,
0x0c04d720u,0x0c04e4e0u,0x0c04e4e2u,0x0c04e4e4u,0x0c04e4e6u,0x0c04e4e8u,0x0c04e4eau,0x0c04e4ecu,0x0c04e4eeu,0x0c04e4f0u,0x0c04e4f2u,0x0c04e4f4u,0x0c04e4f6u,0x0c04e4f8u,0x0c04e4fau,0x0c04e4fcu,
0x0c04e4feu,0x0c04e500u,0x0c04e502u,0x0c04e504u,0x0c04e506u,0x0c04e508u,0x0c04e50au,0x0c04e50cu,0x0c04e50eu,0x0c04e510u,0x0c04e512u,0x0c04e514u,0x0c04e516u,0x0c04e518u,0x0c04e51au,0x0c04e51cu,
0x0c04e51eu,0x0c04e520u,0x0c04e522u,0x0c04e524u,0x0c04e526u,0x0c04e528u,0x0c04e52au,0x0c04e52cu,0x0c04e52eu,0x0c04e530u,0x0c04e532u,0x0c04e534u,0x0c04e536u,0x0c04e538u,0x0c04e53au,0x0c04e53cu,
0x0c04e53eu,0x0c04e540u,0x0c04e542u,0x0c04e544u,0x0c04e546u,0x0c04e548u,0x0c04e54au,0x0c04e54cu,0x0c04e54eu,0x0c04e550u,0x0c04e552u,0x0c04e554u,0x0c04e556u,0x0c04e558u,0x0c04e55au,0x0c04e55cu,
0x0c04e55eu,0x0c04e560u,0x0c04e562u,0x0c04e564u,0x0c04e566u,0x0c04e568u,0x0c04e59cu,0x0c04e59eu,0x0c04e5a0u,0x0c04e5a2u,0x0c04e5a4u,0x0c04e5a6u,0x0c04e5a8u,0x0c04e5aau,0x0c04e5acu,0x0c04e5aeu,
0x0c04e5b0u,0x0c04e5b2u,0x0c04e5b4u,0x0c04e5b6u,0x0c04e5b8u,0x0c04e5bau,0x0c04e5bcu,0x0c04e5beu,0x0c04e5c0u,0x0c04e5c2u,0x0c04e5c4u,0x0c04e5c6u,0x0c04e5c8u,0x0c04e5cau,0x0c04e5ccu,0x0c04e5ceu,
0x0c04e5d0u,0x0c04e5d2u,0x0c04e5d4u,0x0c04e5d6u,0x0c04e5d8u,0x0c04e5dau,0x0c04e5dcu,0x0c04e5deu,0x0c04e5e0u,0x0c04e5e2u,0x0c04e5e4u,0x0c04e5e6u,0x0c04e5e8u,0x0c04e5eau,0x0c04e5ecu,0x0c04e5eeu,
0x0c04e5f0u,0x0c04e5f2u,0x0c04e5f4u,0x0c04e5f6u,0x0c04e5f8u,0x0c04e5fau,0x0c04e5fcu,0x0c04e5feu,0x0c04e600u,0x0c04e602u,0x0c04e604u,0x0c04e606u,0x0c04e608u,0x0c04e60au,0x0c04e60cu,0x0c04e60eu,
0x0c04e610u,0x0c04e612u,0x0c04e614u,0x0c04e616u,0x0c04e618u,0x0c04e61au,0x0c04e61cu,0x0c04e61eu,0x0c04e620u,0x0c04e622u,0x0c04e624u,0x0c04e626u,0x0c04e628u,0x0c04e62au,0x0c04e62cu,0x0c04e62eu,
0x0c04e630u,0x0c04e632u,0x0c04e634u,0x0c04e636u,0x0c04e638u,0x0c04e63au,0x0c04e63cu,0x0c04e63eu,0x0c04e640u,0x0c04e642u,0x0c04e644u,0x0c04e646u,0x0c04e648u,0x0c04e64au,0x0c04e64cu,0x0c04e64eu,
0x0c04e650u,0x0c04e652u,0x0c04e654u,0x0c04e656u,0x0c04e658u,0x0c04e65au,0x0c04e65cu,0x0c04e65eu,0x0c04e660u,0x0c04e662u,0x0c04e664u,0x0c04e666u,0x0c04e668u,0x0c04e66au,0x0c04e66cu,0x0c04e66eu,
0x0c04e670u,0x0c04e672u,0x0c04e674u,0x0c04e676u,0x0c04e678u,0x0c04e67au,0x0c04e67cu,0x0c04e67eu,0x0c04e680u,0x0c04e682u,0x0c04e684u,0x0c04e686u,0x0c04e6b4u,0x0c04e6b6u,0x0c04e6b8u,0x0c04e6bau,
0x0c04e6bcu,0x0c04e6beu,0x0c04e6c0u,0x0c04e6c2u,0x0c04e6c4u,0x0c04e6c6u,0x0c04e6c8u,0x0c04e6cau,0x0c04e6ccu,0x0c04e6ceu,0x0c04e6d0u,0x0c04e6d2u,0x0c04e6d4u,0x0c04e6d6u,0x0c04e6d8u,0x0c04e6dau,
0x0c04e6dcu,0x0c04e6deu,0x0c04e6e0u,0x0c04e6e2u,0x0c04e6e4u,0x0c04e6e6u,0x0c04e6e8u,0x0c04e6eau,0x0c04e6ecu,0x0c04e6eeu,0x0c04e6f0u,0x0c04e6f2u,0x0c04e6f4u,0x0c04e6f6u,0x0c04e6f8u,0x0c04e6fau,
0x0c04e6fcu,0x0c04e6feu,0x0c04e700u,0x0c04e702u,0x0c04e704u,0x0c04e706u,0x0c04e708u,0x0c04e70au,0x0c04e70cu,0x0c04e70eu,0x0c04e710u,0x0c04ef8cu,0x0c04ef8eu,0x0c04ef90u,0x0c04ef92u,0x0c04ef94u,
0x0c04ef96u,0x0c04ef98u,0x0c04ef9au,0x0c04ef9cu,0x0c04ef9eu,0x0c04efa0u,0x0c04efa2u,0x0c04efa4u,0x0c04efa6u,0x0c04efa8u,0x0c04efaau,0x0c04efacu,0x0c04efaeu,0x0c04efb0u,0x0c04efb2u,0x0c04efb4u,
0x0c04efb6u,0x0c04efb8u,0x0c04efbau,0x0c04efbcu,0x0c04efbeu,0x0c04efc0u,0x0c04efc2u,0x0c04efc4u,0x0c04efc6u,0x0c04efc8u,0x0c04efcau,0x0c04efccu,0x0c04efceu,0x0c04efd0u,0x0c04efd2u,0x0c04efd4u,
0x0c04efd6u,0x0c04efd8u,0x0c04efdau,0x0c04efdcu,0x0c04efdeu,0x0c04efe0u,0x0c04efe2u,0x0c04efe4u,0x0c04efe6u,0x0c04efe8u,0x0c04efeau,0x0c04efecu,0x0c04efeeu,0x0c04eff0u,0x0c04eff2u,0x0c04eff4u,
0x0c04eff6u,0x0c04eff8u,0x0c04effau,0x0c04effcu,0x0c04effeu,0x0c04f000u,0x0c04f002u,0x0c04f004u,0x0c04f006u,0x0c04f008u,0x0c04f00au,0x0c04f00cu,0x0c04f00eu,0x0c04f010u,0x0c04f012u,0x0c04f014u,
0x0c04f016u,0x0c04f018u,0x0c04f01au,0x0c04f01cu,0x0c04f01eu,0x0c04f020u,0x0c04f022u,0x0c04f024u,0x0c04f026u,0x0c04f028u,0x0c04fa38u,0x0c04fa3au,0x0c04fa3cu,0x0c04fa3eu,0x0c04fa40u,0x0c04fa42u,
0x0c04fa44u,0x0c04fa46u,0x0c04fa48u,0x0c04fa4au,0x0c04fa4cu,0x0c04fa4eu,0x0c04fa50u,0x0c04fa52u,0x0c04fa54u,0x0c04fa56u,0x0c04fa58u,0x0c04fa5au,0x0c04fa5cu,0x0c04fa5eu,0x0c04fa60u,0x0c04fa62u,
0x0c04fa64u,0x0c04fa66u,0x0c04fa68u,0x0c04fa6au,0x0c04fa6cu,0x0c04fa6eu,0x0c04fa70u,0x0c04fa72u,0x0c04fa74u,0x0c04fa76u,0x0c04fa78u,0x0c04fa7au,
};
int vf3_advance_client_helper_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
