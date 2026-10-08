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
int vf3_record_pool_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c046598u: goto P_0c046598;
case 0x0c04659au: goto P_0c04659a;
case 0x0c04659cu: goto P_0c04659c;
case 0x0c04659eu: goto P_0c04659e;
case 0x0c0465a0u: goto P_0c0465a0;
case 0x0c0465a2u: goto P_0c0465a2;
case 0x0c0465a4u: goto P_0c0465a4;
case 0x0c0465a6u: goto P_0c0465a6;
case 0x0c0465a8u: goto P_0c0465a8;
case 0x0c0465aau: goto P_0c0465aa;
case 0x0c0465acu: goto P_0c0465ac;
case 0x0c0465aeu: goto P_0c0465ae;
case 0x0c0465b0u: goto P_0c0465b0;
case 0x0c0465b2u: goto P_0c0465b2;
case 0x0c0465b4u: goto P_0c0465b4;
case 0x0c0465b6u: goto P_0c0465b6;
case 0x0c0465b8u: goto P_0c0465b8;
case 0x0c0465bau: goto P_0c0465ba;
case 0x0c0465bcu: goto P_0c0465bc;
case 0x0c0465beu: goto P_0c0465be;
case 0x0c0465c0u: goto P_0c0465c0;
case 0x0c0465c2u: goto P_0c0465c2;
case 0x0c0465c4u: goto P_0c0465c4;
case 0x0c0465c6u: goto P_0c0465c6;
case 0x0c0465c8u: goto P_0c0465c8;
case 0x0c0465cau: goto P_0c0465ca;
case 0x0c0465ccu: goto P_0c0465cc;
case 0x0c0465ceu: goto P_0c0465ce;
case 0x0c0465d4u: goto P_0c0465d4;
case 0x0c0465d6u: goto P_0c0465d6;
case 0x0c0465d8u: goto P_0c0465d8;
case 0x0c0465dau: goto P_0c0465da;
case 0x0c0465dcu: goto P_0c0465dc;
case 0x0c0465deu: goto P_0c0465de;
case 0x0c0465e0u: goto P_0c0465e0;
case 0x0c0465e2u: goto P_0c0465e2;
case 0x0c0465e4u: goto P_0c0465e4;
case 0x0c0465e6u: goto P_0c0465e6;
case 0x0c0465e8u: goto P_0c0465e8;
case 0x0c0465eau: goto P_0c0465ea;
case 0x0c0465ecu: goto P_0c0465ec;
case 0x0c0465eeu: goto P_0c0465ee;
case 0x0c0465f0u: goto P_0c0465f0;
case 0x0c0465f2u: goto P_0c0465f2;
case 0x0c0465f4u: goto P_0c0465f4;
case 0x0c0465f6u: goto P_0c0465f6;
case 0x0c0465f8u: goto P_0c0465f8;
case 0x0c0465fau: goto P_0c0465fa;
case 0x0c0465fcu: goto P_0c0465fc;
case 0x0c0465feu: goto P_0c0465fe;
case 0x0c046600u: goto P_0c046600;
case 0x0c046602u: goto P_0c046602;
case 0x0c046604u: goto P_0c046604;
case 0x0c046606u: goto P_0c046606;
case 0x0c046608u: goto P_0c046608;
case 0x0c04660au: goto P_0c04660a;
case 0x0c046620u: goto P_0c046620;
case 0x0c046622u: goto P_0c046622;
case 0x0c046624u: goto P_0c046624;
case 0x0c046626u: goto P_0c046626;
case 0x0c046628u: goto P_0c046628;
case 0x0c04662au: goto P_0c04662a;
case 0x0c04662cu: goto P_0c04662c;
case 0x0c04662eu: goto P_0c04662e;
case 0x0c046630u: goto P_0c046630;
case 0x0c046632u: goto P_0c046632;
case 0x0c046634u: goto P_0c046634;
case 0x0c046636u: goto P_0c046636;
case 0x0c046638u: goto P_0c046638;
case 0x0c04663au: goto P_0c04663a;
case 0x0c04663cu: goto P_0c04663c;
case 0x0c04663eu: goto P_0c04663e;
case 0x0c046640u: goto P_0c046640;
case 0x0c046642u: goto P_0c046642;
case 0x0c046644u: goto P_0c046644;
case 0x0c046646u: goto P_0c046646;
case 0x0c046648u: goto P_0c046648;
case 0x0c04664au: goto P_0c04664a;
case 0x0c04664cu: goto P_0c04664c;
case 0x0c04664eu: goto P_0c04664e;
case 0x0c046650u: goto P_0c046650;
case 0x0c046652u: goto P_0c046652;
case 0x0c046654u: goto P_0c046654;
case 0x0c046656u: goto P_0c046656;
case 0x0c046658u: goto P_0c046658;
case 0x0c04665au: goto P_0c04665a;
case 0x0c04665cu: goto P_0c04665c;
case 0x0c04665eu: goto P_0c04665e;
case 0x0c046660u: goto P_0c046660;
case 0x0c046662u: goto P_0c046662;
case 0x0c046664u: goto P_0c046664;
case 0x0c046666u: goto P_0c046666;
case 0x0c046668u: goto P_0c046668;
case 0x0c04666au: goto P_0c04666a;
case 0x0c04666cu: goto P_0c04666c;
case 0x0c04666eu: goto P_0c04666e;
case 0x0c046670u: goto P_0c046670;
case 0x0c046672u: goto P_0c046672;
case 0x0c046674u: goto P_0c046674;
case 0x0c046676u: goto P_0c046676;
case 0x0c046678u: goto P_0c046678;
case 0x0c0467bau: goto P_0c0467ba;
case 0x0c0467bcu: goto P_0c0467bc;
case 0x0c0467beu: goto P_0c0467be;
case 0x0c0467c0u: goto P_0c0467c0;
case 0x0c0467c2u: goto P_0c0467c2;
case 0x0c0467c4u: goto P_0c0467c4;
case 0x0c0467c6u: goto P_0c0467c6;
case 0x0c0467c8u: goto P_0c0467c8;
case 0x0c0467cau: goto P_0c0467ca;
case 0x0c0467ccu: goto P_0c0467cc;
case 0x0c0467ceu: goto P_0c0467ce;
case 0x0c0467d0u: goto P_0c0467d0;
case 0x0c0467d2u: goto P_0c0467d2;
case 0x0c0467d4u: goto P_0c0467d4;
case 0x0c0467d6u: goto P_0c0467d6;
case 0x0c0467d8u: goto P_0c0467d8;
case 0x0c0467dau: goto P_0c0467da;
case 0x0c0467dcu: goto P_0c0467dc;
case 0x0c0467deu: goto P_0c0467de;
case 0x0c0467e0u: goto P_0c0467e0;
case 0x0c0467e2u: goto P_0c0467e2;
case 0x0c0467ecu: goto P_0c0467ec;
case 0x0c0467eeu: goto P_0c0467ee;
case 0x0c0467f0u: goto P_0c0467f0;
case 0x0c0467f2u: goto P_0c0467f2;
case 0x0c0467f4u: goto P_0c0467f4;
case 0x0c0467f6u: goto P_0c0467f6;
case 0x0c0467f8u: goto P_0c0467f8;
case 0x0c0467fau: goto P_0c0467fa;
case 0x0c0467fcu: goto P_0c0467fc;
case 0x0c0467feu: goto P_0c0467fe;
case 0x0c046800u: goto P_0c046800;
case 0x0c046802u: goto P_0c046802;
case 0x0c046804u: goto P_0c046804;
case 0x0c046806u: goto P_0c046806;
case 0x0c046808u: goto P_0c046808;
case 0x0c04680au: goto P_0c04680a;
case 0x0c04680cu: goto P_0c04680c;
case 0x0c04680eu: goto P_0c04680e;
case 0x0c046810u: goto P_0c046810;
case 0x0c046812u: goto P_0c046812;
case 0x0c046814u: goto P_0c046814;
case 0x0c046816u: goto P_0c046816;
case 0x0c046818u: goto P_0c046818;
case 0x0c046822u: goto P_0c046822;
case 0x0c046824u: goto P_0c046824;
case 0x0c046826u: goto P_0c046826;
case 0x0c046828u: goto P_0c046828;
case 0x0c04682au: goto P_0c04682a;
case 0x0c04682cu: goto P_0c04682c;
case 0x0c04682eu: goto P_0c04682e;
case 0x0c046830u: goto P_0c046830;
case 0x0c046832u: goto P_0c046832;
case 0x0c046834u: goto P_0c046834;
case 0x0c046836u: goto P_0c046836;
case 0x0c046838u: goto P_0c046838;
case 0x0c04683au: goto P_0c04683a;
case 0x0c04683cu: goto P_0c04683c;
case 0x0c04683eu: goto P_0c04683e;
case 0x0c046840u: goto P_0c046840;
case 0x0c046842u: goto P_0c046842;
case 0x0c046844u: goto P_0c046844;
case 0x0c046846u: goto P_0c046846;
case 0x0c046848u: goto P_0c046848;
case 0x0c04684au: goto P_0c04684a;
case 0x0c04684cu: goto P_0c04684c;
case 0x0c04684eu: goto P_0c04684e;
case 0x0c046976u: goto P_0c046976;
case 0x0c046978u: goto P_0c046978;
case 0x0c04697au: goto P_0c04697a;
case 0x0c04697cu: goto P_0c04697c;
case 0x0c04697eu: goto P_0c04697e;
case 0x0c046980u: goto P_0c046980;
case 0x0c046982u: goto P_0c046982;
case 0x0c046984u: goto P_0c046984;
case 0x0c046986u: goto P_0c046986;
case 0x0c046988u: goto P_0c046988;
case 0x0c04698au: goto P_0c04698a;
case 0x0c04698cu: goto P_0c04698c;
case 0x0c04698eu: goto P_0c04698e;
case 0x0c046990u: goto P_0c046990;
case 0x0c046992u: goto P_0c046992;
case 0x0c046994u: goto P_0c046994;
case 0x0c046996u: goto P_0c046996;
case 0x0c046998u: goto P_0c046998;
case 0x0c04699au: goto P_0c04699a;
case 0x0c04699cu: goto P_0c04699c;
case 0x0c04699eu: goto P_0c04699e;
case 0x0c0469a0u: goto P_0c0469a0;
case 0x0c0469a2u: goto P_0c0469a2;
case 0x0c0469a4u: goto P_0c0469a4;
case 0x0c0469a6u: goto P_0c0469a6;
case 0x0c0469a8u: goto P_0c0469a8;
case 0x0c0469aau: goto P_0c0469aa;
case 0x0c0469acu: goto P_0c0469ac;
case 0x0c0469aeu: goto P_0c0469ae;
case 0x0c0469b0u: goto P_0c0469b0;
case 0x0c0469b2u: goto P_0c0469b2;
case 0x0c0469b4u: goto P_0c0469b4;
case 0x0c0469b6u: goto P_0c0469b6;
case 0x0c0469b8u: goto P_0c0469b8;
case 0x0c046a3au: goto P_0c046a3a;
case 0x0c046a3cu: goto P_0c046a3c;
case 0x0c046a3eu: goto P_0c046a3e;
case 0x0c046a40u: goto P_0c046a40;
case 0x0c046a42u: goto P_0c046a42;
case 0x0c046a44u: goto P_0c046a44;
case 0x0c046a46u: goto P_0c046a46;
case 0x0c046a48u: goto P_0c046a48;
case 0x0c046a4au: goto P_0c046a4a;
case 0x0c046a4cu: goto P_0c046a4c;
case 0x0c046a4eu: goto P_0c046a4e;
case 0x0c046a50u: goto P_0c046a50;
case 0x0c046a52u: goto P_0c046a52;
case 0x0c046a54u: goto P_0c046a54;
case 0x0c046a56u: goto P_0c046a56;
case 0x0c046a58u: goto P_0c046a58;
case 0x0c046a5au: goto P_0c046a5a;
case 0x0c046a5cu: goto P_0c046a5c;
case 0x0c046a5eu: goto P_0c046a5e;
case 0x0c046a60u: goto P_0c046a60;
case 0x0c046a62u: goto P_0c046a62;
case 0x0c046a64u: goto P_0c046a64;
case 0x0c046a66u: goto P_0c046a66;
case 0x0c046a68u: goto P_0c046a68;
case 0x0c046a6au: goto P_0c046a6a;
case 0x0c046a6cu: goto P_0c046a6c;
case 0x0c046a6eu: goto P_0c046a6e;
case 0x0c046a70u: goto P_0c046a70;
case 0x0c046a72u: goto P_0c046a72;
case 0x0c046a74u: goto P_0c046a74;
case 0x0c046a76u: goto P_0c046a76;
case 0x0c046a78u: goto P_0c046a78;
case 0x0c046a7au: goto P_0c046a7a;
case 0x0c046a7cu: goto P_0c046a7c;
case 0x0c046a7eu: goto P_0c046a7e;
case 0x0c046a80u: goto P_0c046a80;
case 0x0c046a82u: goto P_0c046a82;
case 0x0c046a84u: goto P_0c046a84;
case 0x0c046a86u: goto P_0c046a86;
case 0x0c046a88u: goto P_0c046a88;
case 0x0c046a8au: goto P_0c046a8a;
case 0x0c046a8cu: goto P_0c046a8c;
case 0x0c046a8eu: goto P_0c046a8e;
case 0x0c046a90u: goto P_0c046a90;
case 0x0c046a92u: goto P_0c046a92;
case 0x0c046a94u: goto P_0c046a94;
case 0x0c046a96u: goto P_0c046a96;
case 0x0c046a98u: goto P_0c046a98;
case 0x0c046a9au: goto P_0c046a9a;
case 0x0c046a9cu: goto P_0c046a9c;
case 0x0c046a9eu: goto P_0c046a9e;
case 0x0c046aa0u: goto P_0c046aa0;
case 0x0c046aa2u: goto P_0c046aa2;
case 0x0c046aa4u: goto P_0c046aa4;
case 0x0c046aa6u: goto P_0c046aa6;
case 0x0c046aa8u: goto P_0c046aa8;
case 0x0c046aaau: goto P_0c046aaa;
case 0x0c046aacu: goto P_0c046aac;
case 0x0c046aaeu: goto P_0c046aae;
case 0x0c046ab0u: goto P_0c046ab0;
case 0x0c046ab2u: goto P_0c046ab2;
case 0x0c046abcu: goto P_0c046abc;
case 0x0c046abeu: goto P_0c046abe;
case 0x0c046ac0u: goto P_0c046ac0;
case 0x0c046ac2u: goto P_0c046ac2;
case 0x0c046ac4u: goto P_0c046ac4;
case 0x0c046ac6u: goto P_0c046ac6;
case 0x0c046ac8u: goto P_0c046ac8;
case 0x0c046acau: goto P_0c046aca;
case 0x0c046accu: goto P_0c046acc;
case 0x0c046aceu: goto P_0c046ace;
case 0x0c046ad0u: goto P_0c046ad0;
case 0x0c046ad2u: goto P_0c046ad2;
case 0x0c046ad4u: goto P_0c046ad4;
case 0x0c046ad6u: goto P_0c046ad6;
case 0x0c046ad8u: goto P_0c046ad8;
case 0x0c046adau: goto P_0c046ada;
case 0x0c046adcu: goto P_0c046adc;
case 0x0c046adeu: goto P_0c046ade;
case 0x0c046ae0u: goto P_0c046ae0;
case 0x0c046ae2u: goto P_0c046ae2;
case 0x0c046ae4u: goto P_0c046ae4;
case 0x0c046b34u: goto P_0c046b34;
case 0x0c046b36u: goto P_0c046b36;
case 0x0c046b38u: goto P_0c046b38;
case 0x0c046b3au: goto P_0c046b3a;
case 0x0c046b3cu: goto P_0c046b3c;
case 0x0c046b3eu: goto P_0c046b3e;
case 0x0c046b40u: goto P_0c046b40;
case 0x0c046b42u: goto P_0c046b42;
case 0x0c046b44u: goto P_0c046b44;
case 0x0c046b46u: goto P_0c046b46;
case 0x0c046b48u: goto P_0c046b48;
case 0x0c046b4au: goto P_0c046b4a;
case 0x0c046b4cu: goto P_0c046b4c;
case 0x0c046b4eu: goto P_0c046b4e;
case 0x0c046b50u: goto P_0c046b50;
case 0x0c046b52u: goto P_0c046b52;
case 0x0c046b54u: goto P_0c046b54;
case 0x0c046b56u: goto P_0c046b56;
case 0x0c046b58u: goto P_0c046b58;
case 0x0c046b5au: goto P_0c046b5a;
case 0x0c046b5cu: goto P_0c046b5c;
case 0x0c046b5eu: goto P_0c046b5e;
case 0x0c046b60u: goto P_0c046b60;
case 0x0c046b62u: goto P_0c046b62;
case 0x0c046b64u: goto P_0c046b64;
case 0x0c046b66u: goto P_0c046b66;
case 0x0c046b68u: goto P_0c046b68;
case 0x0c046b6au: goto P_0c046b6a;
case 0x0c046b6cu: goto P_0c046b6c;
case 0x0c046b6eu: goto P_0c046b6e;
case 0x0c046b70u: goto P_0c046b70;
case 0x0c046b72u: goto P_0c046b72;
case 0x0c046b74u: goto P_0c046b74;
case 0x0c046b76u: goto P_0c046b76;
case 0x0c046b78u: goto P_0c046b78;
case 0x0c046b7au: goto P_0c046b7a;
case 0x0c046b7cu: goto P_0c046b7c;
case 0x0c046b7eu: goto P_0c046b7e;
case 0x0c046b80u: goto P_0c046b80;
case 0x0c046b82u: goto P_0c046b82;
case 0x0c046b84u: goto P_0c046b84;
case 0x0c046b86u: goto P_0c046b86;
case 0x0c046b88u: goto P_0c046b88;
case 0x0c046b8au: goto P_0c046b8a;
case 0x0c046b8cu: goto P_0c046b8c;
case 0x0c046b8eu: goto P_0c046b8e;
case 0x0c046b90u: goto P_0c046b90;
case 0x0c046b92u: goto P_0c046b92;
case 0x0c046b94u: goto P_0c046b94;
case 0x0c046b96u: goto P_0c046b96;
case 0x0c046b98u: goto P_0c046b98;
case 0x0c046b9au: goto P_0c046b9a;
case 0x0c046b9cu: goto P_0c046b9c;
case 0x0c046b9eu: goto P_0c046b9e;
case 0x0c046ba0u: goto P_0c046ba0;
case 0x0c046ba2u: goto P_0c046ba2;
case 0x0c046bb2u: goto P_0c046bb2;
case 0x0c046bb4u: goto P_0c046bb4;
case 0x0c046bb6u: goto P_0c046bb6;
case 0x0c046bb8u: goto P_0c046bb8;
case 0x0c046bbau: goto P_0c046bba;
case 0x0c046bbcu: goto P_0c046bbc;
case 0x0c046bbeu: goto P_0c046bbe;
case 0x0c046bc0u: goto P_0c046bc0;
case 0x0c046bc2u: goto P_0c046bc2;
case 0x0c046bc4u: goto P_0c046bc4;
case 0x0c046bc6u: goto P_0c046bc6;
case 0x0c046bc8u: goto P_0c046bc8;
case 0x0c046bcau: goto P_0c046bca;
case 0x0c046bccu: goto P_0c046bcc;
case 0x0c046bceu: goto P_0c046bce;
case 0x0c046bd0u: goto P_0c046bd0;
case 0x0c046bd2u: goto P_0c046bd2;
case 0x0c046bd4u: goto P_0c046bd4;
case 0x0c046bd6u: goto P_0c046bd6;
case 0x0c046bd8u: goto P_0c046bd8;
case 0x0c046bdau: goto P_0c046bda;
case 0x0c046bdcu: goto P_0c046bdc;
case 0x0c046bdeu: goto P_0c046bde;
case 0x0c046be0u: goto P_0c046be0;
case 0x0c046be2u: goto P_0c046be2;
case 0x0c046be4u: goto P_0c046be4;
case 0x0c046be6u: goto P_0c046be6;
case 0x0c046be8u: goto P_0c046be8;
case 0x0c046beau: goto P_0c046bea;
case 0x0c046becu: goto P_0c046bec;
case 0x0c046beeu: goto P_0c046bee;
case 0x0c046bfau: goto P_0c046bfa;
case 0x0c046bfcu: goto P_0c046bfc;
case 0x0c046bfeu: goto P_0c046bfe;
case 0x0c046c00u: goto P_0c046c00;
case 0x0c046c02u: goto P_0c046c02;
case 0x0c046c04u: goto P_0c046c04;
case 0x0c046c06u: goto P_0c046c06;
case 0x0c046c08u: goto P_0c046c08;
case 0x0c046c0au: goto P_0c046c0a;
case 0x0c046c0cu: goto P_0c046c0c;
case 0x0c046c0eu: goto P_0c046c0e;
case 0x0c046c10u: goto P_0c046c10;
case 0x0c046c12u: goto P_0c046c12;
case 0x0c046c14u: goto P_0c046c14;
case 0x0c046c16u: goto P_0c046c16;
case 0x0c046c18u: goto P_0c046c18;
case 0x0c046c1au: goto P_0c046c1a;
case 0x0c046c1cu: goto P_0c046c1c;
case 0x0c046c1eu: goto P_0c046c1e;
case 0x0c046c20u: goto P_0c046c20;
case 0x0c046c22u: goto P_0c046c22;
case 0x0c046c24u: goto P_0c046c24;
case 0x0c046c26u: goto P_0c046c26;
case 0x0c046c28u: goto P_0c046c28;
case 0x0c046c2au: goto P_0c046c2a;
case 0x0c046c2cu: goto P_0c046c2c;
case 0x0c046c2eu: goto P_0c046c2e;
case 0x0c046c30u: goto P_0c046c30;
case 0x0c046c32u: goto P_0c046c32;
case 0x0c046c34u: goto P_0c046c34;
case 0x0c046c36u: goto P_0c046c36;
case 0x0c046c38u: goto P_0c046c38;
case 0x0c046c3au: goto P_0c046c3a;
case 0x0c046c3cu: goto P_0c046c3c;
case 0x0c046c3eu: goto P_0c046c3e;
case 0x0c046c40u: goto P_0c046c40;
case 0x0c046c42u: goto P_0c046c42;
case 0x0c046c44u: goto P_0c046c44;
case 0x0c046c46u: goto P_0c046c46;
case 0x0c046c50u: goto P_0c046c50;
case 0x0c046c52u: goto P_0c046c52;
case 0x0c046c54u: goto P_0c046c54;
case 0x0c046c56u: goto P_0c046c56;
case 0x0c046c58u: goto P_0c046c58;
case 0x0c046c5au: goto P_0c046c5a;
case 0x0c046c5cu: goto P_0c046c5c;
case 0x0c046c5eu: goto P_0c046c5e;
case 0x0c046c60u: goto P_0c046c60;
case 0x0c046c62u: goto P_0c046c62;
case 0x0c046c64u: goto P_0c046c64;
case 0x0c046c66u: goto P_0c046c66;
case 0x0c046c68u: goto P_0c046c68;
case 0x0c046c6au: goto P_0c046c6a;
case 0x0c046c6cu: goto P_0c046c6c;
case 0x0c046c6eu: goto P_0c046c6e;
case 0x0c046c70u: goto P_0c046c70;
case 0x0c046c72u: goto P_0c046c72;
case 0x0c046c74u: goto P_0c046c74;
case 0x0c046c76u: goto P_0c046c76;
case 0x0c046c78u: goto P_0c046c78;
case 0x0c046c7au: goto P_0c046c7a;
case 0x0c046c7cu: goto P_0c046c7c;
case 0x0c046c7eu: goto P_0c046c7e;
case 0x0c046c80u: goto P_0c046c80;
case 0x0c046c82u: goto P_0c046c82;
case 0x0c046c84u: goto P_0c046c84;
case 0x0c046c86u: goto P_0c046c86;
case 0x0c046c88u: goto P_0c046c88;
case 0x0c046c8au: goto P_0c046c8a;
case 0x0c046c8cu: goto P_0c046c8c;
case 0x0c046c8eu: goto P_0c046c8e;
case 0x0c046c90u: goto P_0c046c90;
case 0x0c046c92u: goto P_0c046c92;
case 0x0c046c94u: goto P_0c046c94;
case 0x0c046c96u: goto P_0c046c96;
case 0x0c046c98u: goto P_0c046c98;
case 0x0c046c9au: goto P_0c046c9a;
case 0x0c046c9cu: goto P_0c046c9c;
case 0x0c046c9eu: goto P_0c046c9e;
case 0x0c046ca0u: goto P_0c046ca0;
case 0x0c046ca2u: goto P_0c046ca2;
case 0x0c046ca4u: goto P_0c046ca4;
case 0x0c046cd4u: goto P_0c046cd4;
case 0x0c046cd6u: goto P_0c046cd6;
case 0x0c046cd8u: goto P_0c046cd8;
case 0x0c046cdau: goto P_0c046cda;
case 0x0c046cdcu: goto P_0c046cdc;
case 0x0c046cdeu: goto P_0c046cde;
case 0x0c046ce0u: goto P_0c046ce0;
case 0x0c046ce2u: goto P_0c046ce2;
case 0x0c046ce4u: goto P_0c046ce4;
case 0x0c046ce6u: goto P_0c046ce6;
case 0x0c046ce8u: goto P_0c046ce8;
case 0x0c046ceau: goto P_0c046cea;
case 0x0c046cecu: goto P_0c046cec;
case 0x0c046ceeu: goto P_0c046cee;
case 0x0c046cf0u: goto P_0c046cf0;
case 0x0c046cf2u: goto P_0c046cf2;
case 0x0c046cf4u: goto P_0c046cf4;
case 0x0c046cf6u: goto P_0c046cf6;
case 0x0c046cf8u: goto P_0c046cf8;
case 0x0c046cfau: goto P_0c046cfa;
case 0x0c046cfcu: goto P_0c046cfc;
case 0x0c046cfeu: goto P_0c046cfe;
case 0x0c046d00u: goto P_0c046d00;
case 0x0c046d02u: goto P_0c046d02;
case 0x0c046d04u: goto P_0c046d04;
case 0x0c046d06u: goto P_0c046d06;
case 0x0c046d08u: goto P_0c046d08;
case 0x0c046d0au: goto P_0c046d0a;
case 0x0c046d0cu: goto P_0c046d0c;
case 0x0c046d0eu: goto P_0c046d0e;
case 0x0c046d10u: goto P_0c046d10;
case 0x0c046d12u: goto P_0c046d12;
case 0x0c046d14u: goto P_0c046d14;
case 0x0c046d16u: goto P_0c046d16;
case 0x0c046d18u: goto P_0c046d18;
case 0x0c046d1au: goto P_0c046d1a;
case 0x0c046d1cu: goto P_0c046d1c;
case 0x0c046d1eu: goto P_0c046d1e;
case 0x0c046d20u: goto P_0c046d20;
case 0x0c046d22u: goto P_0c046d22;
case 0x0c046d24u: goto P_0c046d24;
case 0x0c046d26u: goto P_0c046d26;
case 0x0c046d28u: goto P_0c046d28;
case 0x0c046d32u: goto P_0c046d32;
case 0x0c046d34u: goto P_0c046d34;
case 0x0c046d36u: goto P_0c046d36;
case 0x0c046d38u: goto P_0c046d38;
case 0x0c046d3au: goto P_0c046d3a;
case 0x0c046d3cu: goto P_0c046d3c;
case 0x0c046d3eu: goto P_0c046d3e;
case 0x0c046d40u: goto P_0c046d40;
case 0x0c046d42u: goto P_0c046d42;
case 0x0c046d44u: goto P_0c046d44;
case 0x0c046d46u: goto P_0c046d46;
case 0x0c046d48u: goto P_0c046d48;
case 0x0c046d4au: goto P_0c046d4a;
case 0x0c046d4cu: goto P_0c046d4c;
case 0x0c046d4eu: goto P_0c046d4e;
case 0x0c046d50u: goto P_0c046d50;
case 0x0c046d52u: goto P_0c046d52;
case 0x0c046d54u: goto P_0c046d54;
case 0x0c046d56u: goto P_0c046d56;
case 0x0c046d58u: goto P_0c046d58;
case 0x0c046d5au: goto P_0c046d5a;
case 0x0c046d5cu: goto P_0c046d5c;
case 0x0c046d5eu: goto P_0c046d5e;
case 0x0c046d60u: goto P_0c046d60;
case 0x0c046d62u: goto P_0c046d62;
case 0x0c046d64u: goto P_0c046d64;
case 0x0c046d66u: goto P_0c046d66;
case 0x0c046d68u: goto P_0c046d68;
case 0x0c046d6au: goto P_0c046d6a;
case 0x0c046d6cu: goto P_0c046d6c;
case 0x0c046d6eu: goto P_0c046d6e;
case 0x0c046d70u: goto P_0c046d70;
case 0x0c046d72u: goto P_0c046d72;
case 0x0c046d74u: goto P_0c046d74;
case 0x0c046d76u: goto P_0c046d76;
case 0x0c046d78u: goto P_0c046d78;
case 0x0c046d7au: goto P_0c046d7a;
case 0x0c046d7cu: goto P_0c046d7c;
case 0x0c046d7eu: goto P_0c046d7e;
case 0x0c046d86u: goto P_0c046d86;
case 0x0c046d88u: goto P_0c046d88;
case 0x0c046d8au: goto P_0c046d8a;
case 0x0c046d8cu: goto P_0c046d8c;
case 0x0c046d8eu: goto P_0c046d8e;
case 0x0c046d90u: goto P_0c046d90;
case 0x0c046d92u: goto P_0c046d92;
case 0x0c046d94u: goto P_0c046d94;
case 0x0c046d96u: goto P_0c046d96;
case 0x0c046d98u: goto P_0c046d98;
case 0x0c046d9au: goto P_0c046d9a;
case 0x0c046d9cu: goto P_0c046d9c;
case 0x0c046d9eu: goto P_0c046d9e;
case 0x0c046da0u: goto P_0c046da0;
case 0x0c046da2u: goto P_0c046da2;
case 0x0c046da4u: goto P_0c046da4;
case 0x0c046da6u: goto P_0c046da6;
case 0x0c046da8u: goto P_0c046da8;
case 0x0c046daau: goto P_0c046daa;
case 0x0c046dacu: goto P_0c046dac;
case 0x0c046daeu: goto P_0c046dae;
case 0x0c046db0u: goto P_0c046db0;
case 0x0c046db2u: goto P_0c046db2;
case 0x0c046db4u: goto P_0c046db4;
case 0x0c046db6u: goto P_0c046db6;
case 0x0c046db8u: goto P_0c046db8;
case 0x0c046dbau: goto P_0c046dba;
case 0x0c046dbcu: goto P_0c046dbc;
case 0x0c046dbeu: goto P_0c046dbe;
case 0x0c046dc0u: goto P_0c046dc0;
case 0x0c046dc2u: goto P_0c046dc2;
case 0x0c046dcau: goto P_0c046dca;
case 0x0c046dccu: goto P_0c046dcc;
case 0x0c046dceu: goto P_0c046dce;
case 0x0c046dd0u: goto P_0c046dd0;
case 0x0c046dd2u: goto P_0c046dd2;
case 0x0c046dd4u: goto P_0c046dd4;
case 0x0c046dd6u: goto P_0c046dd6;
case 0x0c046dd8u: goto P_0c046dd8;
case 0x0c046ddau: goto P_0c046dda;
case 0x0c046ddcu: goto P_0c046ddc;
case 0x0c046ddeu: goto P_0c046dde;
case 0x0c046de0u: goto P_0c046de0;
case 0x0c046de2u: goto P_0c046de2;
case 0x0c046de4u: goto P_0c046de4;
case 0x0c046de6u: goto P_0c046de6;
case 0x0c046de8u: goto P_0c046de8;
case 0x0c046deau: goto P_0c046dea;
case 0x0c046decu: goto P_0c046dec;
case 0x0c046deeu: goto P_0c046dee;
case 0x0c046df0u: goto P_0c046df0;
case 0x0c046df2u: goto P_0c046df2;
case 0x0c046df4u: goto P_0c046df4;
case 0x0c046df6u: goto P_0c046df6;
case 0x0c046df8u: goto P_0c046df8;
case 0x0c046dfau: goto P_0c046dfa;
case 0x0c046dfcu: goto P_0c046dfc;
case 0x0c046dfeu: goto P_0c046dfe;
case 0x0c046e00u: goto P_0c046e00;
case 0x0c046e02u: goto P_0c046e02;
case 0x0c046e04u: goto P_0c046e04;
case 0x0c046e06u: goto P_0c046e06;
case 0x0c04c4c0u: goto P_0c04c4c0;
case 0x0c04c4c2u: goto P_0c04c4c2;
case 0x0c04c4c4u: goto P_0c04c4c4;
case 0x0c04c4c6u: goto P_0c04c4c6;
case 0x0c04c4c8u: goto P_0c04c4c8;
case 0x0c04c4cau: goto P_0c04c4ca;
case 0x0c04c4ccu: goto P_0c04c4cc;
case 0x0c04c4ceu: goto P_0c04c4ce;
case 0x0c04c4d0u: goto P_0c04c4d0;
case 0x0c04c4d2u: goto P_0c04c4d2;
case 0x0c04c4d4u: goto P_0c04c4d4;
case 0x0c04c4d6u: goto P_0c04c4d6;
case 0x0c04c4d8u: goto P_0c04c4d8;
case 0x0c04c4dau: goto P_0c04c4da;
case 0x0c04c4dcu: goto P_0c04c4dc;
case 0x0c04c4deu: goto P_0c04c4de;
case 0x0c04c4e0u: goto P_0c04c4e0;
case 0x0c04c4e2u: goto P_0c04c4e2;
case 0x0c04c4e4u: goto P_0c04c4e4;
case 0x0c04c4e6u: goto P_0c04c4e6;
case 0x0c04c4e8u: goto P_0c04c4e8;
case 0x0c04c4f0u: goto P_0c04c4f0;
case 0x0c04c4f2u: goto P_0c04c4f2;
case 0x0c04c4f4u: goto P_0c04c4f4;
case 0x0c04c4f6u: goto P_0c04c4f6;
case 0x0c04c4f8u: goto P_0c04c4f8;
case 0x0c04c4fau: goto P_0c04c4fa;
case 0x0c04c4fcu: goto P_0c04c4fc;
case 0x0c04c4feu: goto P_0c04c4fe;
case 0x0c04c500u: goto P_0c04c500;
case 0x0c04c502u: goto P_0c04c502;
case 0x0c04c504u: goto P_0c04c504;
case 0x0c04c506u: goto P_0c04c506;
case 0x0c04c508u: goto P_0c04c508;
case 0x0c04c50au: goto P_0c04c50a;
case 0x0c04c50cu: goto P_0c04c50c;
case 0x0c04c50eu: goto P_0c04c50e;
case 0x0c04c510u: goto P_0c04c510;
case 0x0c04c512u: goto P_0c04c512;
case 0x0c04c514u: goto P_0c04c514;
case 0x0c04c516u: goto P_0c04c516;
case 0x0c04c518u: goto P_0c04c518;
case 0x0c04c51au: goto P_0c04c51a;
case 0x0c04c51cu: goto P_0c04c51c;
case 0x0c04c51eu: goto P_0c04c51e;
case 0x0c04c520u: goto P_0c04c520;
case 0x0c04c522u: goto P_0c04c522;
case 0x0c04c524u: goto P_0c04c524;
case 0x0c04c526u: goto P_0c04c526;
case 0x0c04c528u: goto P_0c04c528;
case 0x0c04c52au: goto P_0c04c52a;
case 0x0c04c52cu: goto P_0c04c52c;
case 0x0c04c52eu: goto P_0c04c52e;
case 0x0c04c530u: goto P_0c04c530;
case 0x0c04c532u: goto P_0c04c532;
case 0x0c04c534u: goto P_0c04c534;
case 0x0c04c536u: goto P_0c04c536;
case 0x0c04c538u: goto P_0c04c538;
case 0x0c04c53au: goto P_0c04c53a;
case 0x0c04c53cu: goto P_0c04c53c;
case 0x0c04c53eu: goto P_0c04c53e;
case 0x0c04c540u: goto P_0c04c540;
case 0x0c04c542u: goto P_0c04c542;
case 0x0c04c544u: goto P_0c04c544;
case 0x0c04c546u: goto P_0c04c546;
case 0x0c04c548u: goto P_0c04c548;
case 0x0c04c54au: goto P_0c04c54a;
case 0x0c04c54cu: goto P_0c04c54c;
case 0x0c04c54eu: goto P_0c04c54e;
case 0x0c04c550u: goto P_0c04c550;
case 0x0c04c552u: goto P_0c04c552;
case 0x0c04c554u: goto P_0c04c554;
case 0x0c04c556u: goto P_0c04c556;
case 0x0c04c558u: goto P_0c04c558;
case 0x0c04c55au: goto P_0c04c55a;
case 0x0c04c55cu: goto P_0c04c55c;
case 0x0c04c55eu: goto P_0c04c55e;
case 0x0c04c560u: goto P_0c04c560;
case 0x0c04c562u: goto P_0c04c562;
case 0x0c04c564u: goto P_0c04c564;
case 0x0c04c566u: goto P_0c04c566;
case 0x0c04c568u: goto P_0c04c568;
case 0x0c04c56au: goto P_0c04c56a;
case 0x0c04c56cu: goto P_0c04c56c;
case 0x0c04c56eu: goto P_0c04c56e;
case 0x0c04c570u: goto P_0c04c570;
case 0x0c04c572u: goto P_0c04c572;
case 0x0c04c574u: goto P_0c04c574;
case 0x0c04c576u: goto P_0c04c576;
case 0x0c04c578u: goto P_0c04c578;
case 0x0c04c57au: goto P_0c04c57a;
case 0x0c04c57cu: goto P_0c04c57c;
case 0x0c04c57eu: goto P_0c04c57e;
case 0x0c04c580u: goto P_0c04c580;
case 0x0c04c582u: goto P_0c04c582;
case 0x0c04c584u: goto P_0c04c584;
case 0x0c04c586u: goto P_0c04c586;
case 0x0c04c588u: goto P_0c04c588;
case 0x0c04c58au: goto P_0c04c58a;
case 0x0c04c58cu: goto P_0c04c58c;
case 0x0c04c58eu: goto P_0c04c58e;
case 0x0c04c590u: goto P_0c04c590;
case 0x0c04c592u: goto P_0c04c592;
case 0x0c04c594u: goto P_0c04c594;
case 0x0c04cf0eu: goto P_0c04cf0e;
case 0x0c04cf10u: goto P_0c04cf10;
case 0x0c04cf12u: goto P_0c04cf12;
case 0x0c04cf14u: goto P_0c04cf14;
case 0x0c04cf16u: goto P_0c04cf16;
case 0x0c04cf18u: goto P_0c04cf18;
case 0x0c04cf1au: goto P_0c04cf1a;
case 0x0c04cf1cu: goto P_0c04cf1c;
case 0x0c04cf1eu: goto P_0c04cf1e;
case 0x0c04cf20u: goto P_0c04cf20;
case 0x0c04cf22u: goto P_0c04cf22;
case 0x0c04cf24u: goto P_0c04cf24;
case 0x0c04cf26u: goto P_0c04cf26;
case 0x0c04cf28u: goto P_0c04cf28;
case 0x0c04cf2au: goto P_0c04cf2a;
case 0x0c04cf2cu: goto P_0c04cf2c;
case 0x0c04cf2eu: goto P_0c04cf2e;
case 0x0c04cf30u: goto P_0c04cf30;
case 0x0c04cf32u: goto P_0c04cf32;
case 0x0c04cf34u: goto P_0c04cf34;
case 0x0c04cf36u: goto P_0c04cf36;
case 0x0c04cf38u: goto P_0c04cf38;
case 0x0c04cf3au: goto P_0c04cf3a;
case 0x0c04cf3cu: goto P_0c04cf3c;
case 0x0c04cf3eu: goto P_0c04cf3e;
case 0x0c04cf40u: goto P_0c04cf40;
case 0x0c04cf42u: goto P_0c04cf42;
case 0x0c04cf44u: goto P_0c04cf44;
case 0x0c04cf46u: goto P_0c04cf46;
case 0x0c04cf48u: goto P_0c04cf48;
case 0x0c04cf4au: goto P_0c04cf4a;
case 0x0c04cf4cu: goto P_0c04cf4c;
case 0x0c04cf4eu: goto P_0c04cf4e;
case 0x0c04cf50u: goto P_0c04cf50;
case 0x0c04cf52u: goto P_0c04cf52;
case 0x0c04cf54u: goto P_0c04cf54;
case 0x0c04cf56u: goto P_0c04cf56;
case 0x0c04cf80u: goto P_0c04cf80;
case 0x0c04cf82u: goto P_0c04cf82;
case 0x0c04cf84u: goto P_0c04cf84;
case 0x0c04cf86u: goto P_0c04cf86;
case 0x0c04cf88u: goto P_0c04cf88;
case 0x0c04cf8au: goto P_0c04cf8a;
case 0x0c04cf8cu: goto P_0c04cf8c;
case 0x0c04cf8eu: goto P_0c04cf8e;
case 0x0c04cf90u: goto P_0c04cf90;
case 0x0c04cf92u: goto P_0c04cf92;
case 0x0c04cf94u: goto P_0c04cf94;
case 0x0c04cf96u: goto P_0c04cf96;
case 0x0c04cf98u: goto P_0c04cf98;
case 0x0c04cf9au: goto P_0c04cf9a;
case 0x0c04cf9cu: goto P_0c04cf9c;
case 0x0c04cf9eu: goto P_0c04cf9e;
case 0x0c04cfa0u: goto P_0c04cfa0;
case 0x0c04cfa2u: goto P_0c04cfa2;
case 0x0c04cfa4u: goto P_0c04cfa4;
case 0x0c04cfa6u: goto P_0c04cfa6;
case 0x0c04cfa8u: goto P_0c04cfa8;
case 0x0c04cfaau: goto P_0c04cfaa;
case 0x0c04cfacu: goto P_0c04cfac;
case 0x0c04cfaeu: goto P_0c04cfae;
case 0x0c04cfb0u: goto P_0c04cfb0;
case 0x0c04cfb2u: goto P_0c04cfb2;
case 0x0c04cfb4u: goto P_0c04cfb4;
case 0x0c04cfb6u: goto P_0c04cfb6;
case 0x0c04cfb8u: goto P_0c04cfb8;
case 0x0c04cfbau: goto P_0c04cfba;
case 0x0c04cfbcu: goto P_0c04cfbc;
case 0x0c04cfbeu: goto P_0c04cfbe;
case 0x0c04cfc0u: goto P_0c04cfc0;
case 0x0c04cfc2u: goto P_0c04cfc2;
case 0x0c04cfc4u: goto P_0c04cfc4;
case 0x0c04cfc6u: goto P_0c04cfc6;
case 0x0c04cfc8u: goto P_0c04cfc8;
case 0x0c04cfcau: goto P_0c04cfca;
case 0x0c04cfccu: goto P_0c04cfcc;
case 0x0c04cfceu: goto P_0c04cfce;
case 0x0c04cfd0u: goto P_0c04cfd0;
case 0x0c04cfd2u: goto P_0c04cfd2;
case 0x0c04cfd4u: goto P_0c04cfd4;
case 0x0c04cfd6u: goto P_0c04cfd6;
case 0x0c04cfd8u: goto P_0c04cfd8;
case 0x0c04cfdau: goto P_0c04cfda;
case 0x0c04cfdcu: goto P_0c04cfdc;
case 0x0c04cfdeu: goto P_0c04cfde;
case 0x0c04cfe0u: goto P_0c04cfe0;
case 0x0c04cfe2u: goto P_0c04cfe2;
case 0x0c04cfe4u: goto P_0c04cfe4;
case 0x0c04cfe6u: goto P_0c04cfe6;
case 0x0c04cfe8u: goto P_0c04cfe8;
case 0x0c04cfeau: goto P_0c04cfea;
case 0x0c04cfecu: goto P_0c04cfec;
case 0x0c04cfeeu: goto P_0c04cfee;
case 0x0c04cff0u: goto P_0c04cff0;
case 0x0c04cff2u: goto P_0c04cff2;
case 0x0c04cff4u: goto P_0c04cff4;
case 0x0c04cff6u: goto P_0c04cff6;
case 0x0c04cff8u: goto P_0c04cff8;
case 0x0c04cffau: goto P_0c04cffa;
case 0x0c04cffcu: goto P_0c04cffc;
case 0x0c04cffeu: goto P_0c04cffe;
case 0x0c04d000u: goto P_0c04d000;
case 0x0c04d002u: goto P_0c04d002;
case 0x0c04d004u: goto P_0c04d004;
case 0x0c04d006u: goto P_0c04d006;
case 0x0c04d008u: goto P_0c04d008;
case 0x0c04d00au: goto P_0c04d00a;
case 0x0c04d00cu: goto P_0c04d00c;
case 0x0c04d00eu: goto P_0c04d00e;
case 0x0c04d800u: goto P_0c04d800;
case 0x0c04d802u: goto P_0c04d802;
case 0x0c04d804u: goto P_0c04d804;
case 0x0c04d806u: goto P_0c04d806;
case 0x0c04d808u: goto P_0c04d808;
case 0x0c04d80au: goto P_0c04d80a;
case 0x0c04d80cu: goto P_0c04d80c;
case 0x0c04d80eu: goto P_0c04d80e;
case 0x0c04d810u: goto P_0c04d810;
case 0x0c04d812u: goto P_0c04d812;
case 0x0c04d814u: goto P_0c04d814;
case 0x0c04d816u: goto P_0c04d816;
case 0x0c04d818u: goto P_0c04d818;
case 0x0c04d81au: goto P_0c04d81a;
case 0x0c04d81cu: goto P_0c04d81c;
case 0x0c04d81eu: goto P_0c04d81e;
case 0x0c04d820u: goto P_0c04d820;
case 0x0c04d822u: goto P_0c04d822;
case 0x0c04d824u: goto P_0c04d824;
case 0x0c04d826u: goto P_0c04d826;
case 0x0c04d828u: goto P_0c04d828;
case 0x0c04d82au: goto P_0c04d82a;
case 0x0c04d82cu: goto P_0c04d82c;
case 0x0c04d82eu: goto P_0c04d82e;
case 0x0c04d830u: goto P_0c04d830;
case 0x0c04d832u: goto P_0c04d832;
case 0x0c04d834u: goto P_0c04d834;
case 0x0c04d836u: goto P_0c04d836;
case 0x0c04d838u: goto P_0c04d838;
case 0x0c04d83au: goto P_0c04d83a;
case 0x0c04d83cu: goto P_0c04d83c;
case 0x0c04d83eu: goto P_0c04d83e;
case 0x0c04d840u: goto P_0c04d840;
case 0x0c04d842u: goto P_0c04d842;
case 0x0c04d844u: goto P_0c04d844;
case 0x0c04d846u: goto P_0c04d846;
case 0x0c04d848u: goto P_0c04d848;
case 0x0c04d84au: goto P_0c04d84a;
case 0x0c04d84cu: goto P_0c04d84c;
case 0x0c04d84eu: goto P_0c04d84e;
case 0x0c04d850u: goto P_0c04d850;
case 0x0c04d852u: goto P_0c04d852;
case 0x0c04d854u: goto P_0c04d854;
case 0x0c04d856u: goto P_0c04d856;
case 0x0c04d858u: goto P_0c04d858;
case 0x0c04d85au: goto P_0c04d85a;
case 0x0c04d85cu: goto P_0c04d85c;
case 0x0c04d85eu: goto P_0c04d85e;
case 0x0c04d860u: goto P_0c04d860;
case 0x0c04d862u: goto P_0c04d862;
case 0x0c04d864u: goto P_0c04d864;
case 0x0c04d866u: goto P_0c04d866;
case 0x0c04d868u: goto P_0c04d868;
case 0x0c04d86au: goto P_0c04d86a;
case 0x0c04d86cu: goto P_0c04d86c;
case 0x0c04d86eu: goto P_0c04d86e;
case 0x0c04d870u: goto P_0c04d870;
case 0x0c04d872u: goto P_0c04d872;
case 0x0c04d874u: goto P_0c04d874;
case 0x0c04d876u: goto P_0c04d876;
case 0x0c04d878u: goto P_0c04d878;
case 0x0c04d87au: goto P_0c04d87a;
case 0x0c04d8acu: goto P_0c04d8ac;
case 0x0c04d8aeu: goto P_0c04d8ae;
case 0x0c04d8b0u: goto P_0c04d8b0;
case 0x0c04d8b2u: goto P_0c04d8b2;
case 0x0c04d8b4u: goto P_0c04d8b4;
case 0x0c04d8b6u: goto P_0c04d8b6;
case 0x0c04d8b8u: goto P_0c04d8b8;
case 0x0c04d8bau: goto P_0c04d8ba;
case 0x0c04d8bcu: goto P_0c04d8bc;
case 0x0c04d8beu: goto P_0c04d8be;
case 0x0c04d8c0u: goto P_0c04d8c0;
case 0x0c04d8c2u: goto P_0c04d8c2;
case 0x0c04d8c4u: goto P_0c04d8c4;
case 0x0c04d8c6u: goto P_0c04d8c6;
case 0x0c04d8c8u: goto P_0c04d8c8;
case 0x0c04d8cau: goto P_0c04d8ca;
case 0x0c04d8ccu: goto P_0c04d8cc;
case 0x0c04d8ceu: goto P_0c04d8ce;
case 0x0c04d8d0u: goto P_0c04d8d0;
case 0x0c04d8d2u: goto P_0c04d8d2;
case 0x0c04d8d4u: goto P_0c04d8d4;
case 0x0c04d8d6u: goto P_0c04d8d6;
case 0x0c04d8d8u: goto P_0c04d8d8;
case 0x0c04d8dau: goto P_0c04d8da;
case 0x0c04d8dcu: goto P_0c04d8dc;
case 0x0c04d8deu: goto P_0c04d8de;
case 0x0c04d8e0u: goto P_0c04d8e0;
case 0x0c04d8e2u: goto P_0c04d8e2;
case 0x0c04d8e4u: goto P_0c04d8e4;
case 0x0c04d8e6u: goto P_0c04d8e6;
case 0x0c04d8e8u: goto P_0c04d8e8;
case 0x0c04d8eau: goto P_0c04d8ea;
case 0x0c04d8ecu: goto P_0c04d8ec;
case 0x0c04d8eeu: goto P_0c04d8ee;
case 0x0c04d8f0u: goto P_0c04d8f0;
case 0x0c04d8f2u: goto P_0c04d8f2;
case 0x0c04d8f4u: goto P_0c04d8f4;
case 0x0c04d8f6u: goto P_0c04d8f6;
case 0x0c04d8f8u: goto P_0c04d8f8;
case 0x0c04d8fau: goto P_0c04d8fa;
case 0x0c04d8fcu: goto P_0c04d8fc;
case 0x0c04d8feu: goto P_0c04d8fe;
case 0x0c04d900u: goto P_0c04d900;
case 0x0c04d902u: goto P_0c04d902;
case 0x0c04d904u: goto P_0c04d904;
case 0x0c04d906u: goto P_0c04d906;
case 0x0c04d908u: goto P_0c04d908;
case 0x0c04d90au: goto P_0c04d90a;
case 0x0c04d90cu: goto P_0c04d90c;
case 0x0c04d90eu: goto P_0c04d90e;
case 0x0c04d910u: goto P_0c04d910;
case 0x0c04d912u: goto P_0c04d912;
case 0x0c04d914u: goto P_0c04d914;
case 0x0c04d916u: goto P_0c04d916;
case 0x0c04d918u: goto P_0c04d918;
case 0x0c04d91au: goto P_0c04d91a;
case 0x0c04d91cu: goto P_0c04d91c;
case 0x0c04d91eu: goto P_0c04d91e;
case 0x0c04d920u: goto P_0c04d920;
case 0x0c04d922u: goto P_0c04d922;
case 0x0c04d924u: goto P_0c04d924;
case 0x0c04d926u: goto P_0c04d926;
case 0x0c04d928u: goto P_0c04d928;
case 0x0c04d92au: goto P_0c04d92a;
case 0x0c04d92cu: goto P_0c04d92c;
case 0x0c04d92eu: goto P_0c04d92e;
case 0x0c04d930u: goto P_0c04d930;
case 0x0c04d932u: goto P_0c04d932;
case 0x0c04d934u: goto P_0c04d934;
case 0x0c04d936u: goto P_0c04d936;
case 0x0c04d938u: goto P_0c04d938;
case 0x0c04d93au: goto P_0c04d93a;
case 0x0c04d93cu: goto P_0c04d93c;
case 0x0c04d93eu: goto P_0c04d93e;
case 0x0c04d940u: goto P_0c04d940;
case 0x0c04d942u: goto P_0c04d942;
case 0x0c04d944u: goto P_0c04d944;
case 0x0c04d946u: goto P_0c04d946;
case 0x0c04d948u: goto P_0c04d948;
case 0x0c04d94au: goto P_0c04d94a;
case 0x0c04d94cu: goto P_0c04d94c;
case 0x0c04d94eu: goto P_0c04d94e;
case 0x0c04d950u: goto P_0c04d950;
case 0x0c04d952u: goto P_0c04d952;
case 0x0c04d954u: goto P_0c04d954;
case 0x0c04d956u: goto P_0c04d956;
case 0x0c04d958u: goto P_0c04d958;
case 0x0c04d95au: goto P_0c04d95a;
case 0x0c04d95cu: goto P_0c04d95c;
case 0x0c04d95eu: goto P_0c04d95e;
case 0x0c04d960u: goto P_0c04d960;
case 0x0c04d962u: goto P_0c04d962;
case 0x0c04d964u: goto P_0c04d964;
case 0x0c04d966u: goto P_0c04d966;
case 0x0c04d968u: goto P_0c04d968;
case 0x0c04d96au: goto P_0c04d96a;
case 0x0c04d96cu: goto P_0c04d96c;
case 0x0c04d96eu: goto P_0c04d96e;
case 0x0c04d970u: goto P_0c04d970;
case 0x0c04d972u: goto P_0c04d972;
case 0x0c04d974u: goto P_0c04d974;
case 0x0c04d976u: goto P_0c04d976;
case 0x0c04d978u: goto P_0c04d978;
case 0x0c04d97au: goto P_0c04d97a;
case 0x0c04d97cu: goto P_0c04d97c;
case 0x0c04d97eu: goto P_0c04d97e;
case 0x0c04d980u: goto P_0c04d980;
case 0x0c04d982u: goto P_0c04d982;
case 0x0c04d984u: goto P_0c04d984;
case 0x0c04d986u: goto P_0c04d986;
case 0x0c04d988u: goto P_0c04d988;
case 0x0c04d98au: goto P_0c04d98a;
case 0x0c04d98cu: goto P_0c04d98c;
case 0x0c04d98eu: goto P_0c04d98e;
case 0x0c04d990u: goto P_0c04d990;
case 0x0c04d992u: goto P_0c04d992;
case 0x0c04d994u: goto P_0c04d994;
case 0x0c04d996u: goto P_0c04d996;
case 0x0c04d998u: goto P_0c04d998;
case 0x0c04d99au: goto P_0c04d99a;
case 0x0c04d99cu: goto P_0c04d99c;
case 0x0c04d99eu: goto P_0c04d99e;
case 0x0c04d9a0u: goto P_0c04d9a0;
case 0x0c04d9a2u: goto P_0c04d9a2;
case 0x0c04d9a4u: goto P_0c04d9a4;
case 0x0c04d9a6u: goto P_0c04d9a6;
case 0x0c04d9a8u: goto P_0c04d9a8;
case 0x0c04d9aau: goto P_0c04d9aa;
case 0x0c04d9acu: goto P_0c04d9ac;
case 0x0c04d9aeu: goto P_0c04d9ae;
case 0x0c04d9b0u: goto P_0c04d9b0;
case 0x0c04d9b2u: goto P_0c04d9b2;
case 0x0c04d9b4u: goto P_0c04d9b4;
case 0x0c04d9b6u: goto P_0c04d9b6;
case 0x0c04d9b8u: goto P_0c04d9b8;
case 0x0c04d9fcu: goto P_0c04d9fc;
case 0x0c04d9feu: goto P_0c04d9fe;
case 0x0c04da00u: goto P_0c04da00;
case 0x0c04da02u: goto P_0c04da02;
case 0x0c04da04u: goto P_0c04da04;
case 0x0c04da06u: goto P_0c04da06;
case 0x0c04da08u: goto P_0c04da08;
case 0x0c04da0au: goto P_0c04da0a;
case 0x0c04da0cu: goto P_0c04da0c;
case 0x0c04da0eu: goto P_0c04da0e;
case 0x0c04da10u: goto P_0c04da10;
case 0x0c04da12u: goto P_0c04da12;
case 0x0c04da14u: goto P_0c04da14;
case 0x0c04da16u: goto P_0c04da16;
case 0x0c04da18u: goto P_0c04da18;
case 0x0c04da1au: goto P_0c04da1a;
case 0x0c04da1cu: goto P_0c04da1c;
case 0x0c04da1eu: goto P_0c04da1e;
case 0x0c04da20u: goto P_0c04da20;
case 0x0c04da22u: goto P_0c04da22;
case 0x0c04da24u: goto P_0c04da24;
case 0x0c04da26u: goto P_0c04da26;
case 0x0c04da28u: goto P_0c04da28;
case 0x0c04da2au: goto P_0c04da2a;
case 0x0c04da2cu: goto P_0c04da2c;
case 0x0c04da2eu: goto P_0c04da2e;
case 0x0c04da30u: goto P_0c04da30;
case 0x0c04da32u: goto P_0c04da32;
case 0x0c04da34u: goto P_0c04da34;
case 0x0c04da36u: goto P_0c04da36;
case 0x0c04da38u: goto P_0c04da38;
case 0x0c04da3au: goto P_0c04da3a;
case 0x0c04da3cu: goto P_0c04da3c;
case 0x0c04da3eu: goto P_0c04da3e;
case 0x0c04da40u: goto P_0c04da40;
case 0x0c04da42u: goto P_0c04da42;
case 0x0c04da44u: goto P_0c04da44;
case 0x0c04da46u: goto P_0c04da46;
case 0x0c04da48u: goto P_0c04da48;
case 0x0c04da4au: goto P_0c04da4a;
case 0x0c04da4cu: goto P_0c04da4c;
case 0x0c04da4eu: goto P_0c04da4e;
case 0x0c04da50u: goto P_0c04da50;
case 0x0c04da52u: goto P_0c04da52;
case 0x0c04da54u: goto P_0c04da54;
case 0x0c04da56u: goto P_0c04da56;
case 0x0c04da58u: goto P_0c04da58;
case 0x0c04da5au: goto P_0c04da5a;
case 0x0c04da5cu: goto P_0c04da5c;
case 0x0c04da5eu: goto P_0c04da5e;
case 0x0c04da60u: goto P_0c04da60;
case 0x0c04da62u: goto P_0c04da62;
case 0x0c04da64u: goto P_0c04da64;
case 0x0c04da66u: goto P_0c04da66;
case 0x0c04da68u: goto P_0c04da68;
case 0x0c04da6au: goto P_0c04da6a;
case 0x0c04da6cu: goto P_0c04da6c;
case 0x0c04da6eu: goto P_0c04da6e;
case 0x0c04da70u: goto P_0c04da70;
case 0x0c04da72u: goto P_0c04da72;
case 0x0c04da74u: goto P_0c04da74;
case 0x0c04da76u: goto P_0c04da76;
case 0x0c04da78u: goto P_0c04da78;
case 0x0c04da7au: goto P_0c04da7a;
case 0x0c04da7cu: goto P_0c04da7c;
case 0x0c04da7eu: goto P_0c04da7e;
case 0x0c04da80u: goto P_0c04da80;
case 0x0c04da82u: goto P_0c04da82;
case 0x0c04da84u: goto P_0c04da84;
case 0x0c04da86u: goto P_0c04da86;
case 0x0c04da88u: goto P_0c04da88;
case 0x0c04da8au: goto P_0c04da8a;
case 0x0c04da8cu: goto P_0c04da8c;
case 0x0c04da8eu: goto P_0c04da8e;
case 0x0c04da90u: goto P_0c04da90;
case 0x0c04da92u: goto P_0c04da92;
case 0x0c04da94u: goto P_0c04da94;
case 0x0c04da96u: goto P_0c04da96;
case 0x0c04da98u: goto P_0c04da98;
case 0x0c04da9au: goto P_0c04da9a;
case 0x0c04da9cu: goto P_0c04da9c;
case 0x0c04da9eu: goto P_0c04da9e;
case 0x0c04daa0u: goto P_0c04daa0;
case 0x0c04daa2u: goto P_0c04daa2;
case 0x0c04daa4u: goto P_0c04daa4;
case 0x0c04daa6u: goto P_0c04daa6;
case 0x0c04daa8u: goto P_0c04daa8;
case 0x0c04daaau: goto P_0c04daaa;
case 0x0c04daacu: goto P_0c04daac;
case 0x0c04daaeu: goto P_0c04daae;
case 0x0c04dab0u: goto P_0c04dab0;
case 0x0c04dab2u: goto P_0c04dab2;
case 0x0c04dab4u: goto P_0c04dab4;
case 0x0c04dab6u: goto P_0c04dab6;
case 0x0c04dab8u: goto P_0c04dab8;
case 0x0c04dabau: goto P_0c04daba;
case 0x0c04dabcu: goto P_0c04dabc;
case 0x0c04dabeu: goto P_0c04dabe;
case 0x0c04dac0u: goto P_0c04dac0;
case 0x0c04dac2u: goto P_0c04dac2;
case 0x0c04dac4u: goto P_0c04dac4;
case 0x0c04dac6u: goto P_0c04dac6;
case 0x0c04dac8u: goto P_0c04dac8;
case 0x0c04dacau: goto P_0c04daca;
case 0x0c04daccu: goto P_0c04dacc;
case 0x0c04daceu: goto P_0c04dace;
case 0x0c04dad0u: goto P_0c04dad0;
case 0x0c04dad2u: goto P_0c04dad2;
case 0x0c04dad4u: goto P_0c04dad4;
case 0x0c04dad6u: goto P_0c04dad6;
case 0x0c04dad8u: goto P_0c04dad8;
case 0x0c04dadau: goto P_0c04dada;
case 0x0c04dadcu: goto P_0c04dadc;
case 0x0c04db28u: goto P_0c04db28;
case 0x0c04db2au: goto P_0c04db2a;
case 0x0c04db2cu: goto P_0c04db2c;
case 0x0c04db2eu: goto P_0c04db2e;
case 0x0c04db30u: goto P_0c04db30;
case 0x0c04db32u: goto P_0c04db32;
case 0x0c04db34u: goto P_0c04db34;
case 0x0c04db36u: goto P_0c04db36;
case 0x0c04db38u: goto P_0c04db38;
case 0x0c04db3au: goto P_0c04db3a;
case 0x0c04db3cu: goto P_0c04db3c;
case 0x0c04db3eu: goto P_0c04db3e;
case 0x0c04db40u: goto P_0c04db40;
case 0x0c04db42u: goto P_0c04db42;
case 0x0c04db44u: goto P_0c04db44;
case 0x0c04db46u: goto P_0c04db46;
case 0x0c04db48u: goto P_0c04db48;
case 0x0c04db4au: goto P_0c04db4a;
case 0x0c04db4cu: goto P_0c04db4c;
case 0x0c04db4eu: goto P_0c04db4e;
case 0x0c04db50u: goto P_0c04db50;
case 0x0c04db52u: goto P_0c04db52;
case 0x0c04db54u: goto P_0c04db54;
case 0x0c04db56u: goto P_0c04db56;
case 0x0c04db58u: goto P_0c04db58;
case 0x0c04db5au: goto P_0c04db5a;
case 0x0c04db5cu: goto P_0c04db5c;
case 0x0c04db5eu: goto P_0c04db5e;
case 0x0c04db60u: goto P_0c04db60;
case 0x0c04db62u: goto P_0c04db62;
case 0x0c04db64u: goto P_0c04db64;
case 0x0c04db66u: goto P_0c04db66;
case 0x0c04db68u: goto P_0c04db68;
case 0x0c04db6au: goto P_0c04db6a;
case 0x0c04db6cu: goto P_0c04db6c;
case 0x0c04db6eu: goto P_0c04db6e;
case 0x0c04db70u: goto P_0c04db70;
case 0x0c04db72u: goto P_0c04db72;
case 0x0c04db74u: goto P_0c04db74;
case 0x0c04db76u: goto P_0c04db76;
case 0x0c04db78u: goto P_0c04db78;
case 0x0c04db7au: goto P_0c04db7a;
case 0x0c04db7cu: goto P_0c04db7c;
case 0x0c04db7eu: goto P_0c04db7e;
case 0x0c04db80u: goto P_0c04db80;
case 0x0c04db82u: goto P_0c04db82;
case 0x0c04db84u: goto P_0c04db84;
case 0x0c04db86u: goto P_0c04db86;
case 0x0c04db88u: goto P_0c04db88;
case 0x0c04db8au: goto P_0c04db8a;
case 0x0c04db8cu: goto P_0c04db8c;
case 0x0c04db8eu: goto P_0c04db8e;
case 0x0c04db90u: goto P_0c04db90;
case 0x0c04db92u: goto P_0c04db92;
case 0x0c04db94u: goto P_0c04db94;
case 0x0c04db96u: goto P_0c04db96;
case 0x0c04db98u: goto P_0c04db98;
case 0x0c04db9au: goto P_0c04db9a;
case 0x0c04db9cu: goto P_0c04db9c;
case 0x0c04db9eu: goto P_0c04db9e;
case 0x0c04dba0u: goto P_0c04dba0;
case 0x0c04dba2u: goto P_0c04dba2;
case 0x0c04dba4u: goto P_0c04dba4;
case 0x0c04dba6u: goto P_0c04dba6;
case 0x0c04dba8u: goto P_0c04dba8;
case 0x0c04dbaau: goto P_0c04dbaa;
case 0x0c04dbacu: goto P_0c04dbac;
case 0x0c04dbaeu: goto P_0c04dbae;
case 0x0c04dbb0u: goto P_0c04dbb0;
case 0x0c04dbb2u: goto P_0c04dbb2;
case 0x0c04dbb4u: goto P_0c04dbb4;
case 0x0c04dbb6u: goto P_0c04dbb6;
case 0x0c04dbb8u: goto P_0c04dbb8;
case 0x0c04dbbau: goto P_0c04dbba;
case 0x0c04dbbcu: goto P_0c04dbbc;
case 0x0c04dbbeu: goto P_0c04dbbe;
case 0x0c04dbc0u: goto P_0c04dbc0;
case 0x0c04dbc2u: goto P_0c04dbc2;
case 0x0c04dbc4u: goto P_0c04dbc4;
case 0x0c04dbc6u: goto P_0c04dbc6;
case 0x0c04dbc8u: goto P_0c04dbc8;
case 0x0c04dbcau: goto P_0c04dbca;
case 0x0c04dbccu: goto P_0c04dbcc;
case 0x0c04dbceu: goto P_0c04dbce;
case 0x0c04dbd0u: goto P_0c04dbd0;
case 0x0c04dbd2u: goto P_0c04dbd2;
case 0x0c04dbd4u: goto P_0c04dbd4;
case 0x0c04dbd6u: goto P_0c04dbd6;
case 0x0c04dbd8u: goto P_0c04dbd8;
case 0x0c04dbdau: goto P_0c04dbda;
case 0x0c04dbdcu: goto P_0c04dbdc;
case 0x0c04dbdeu: goto P_0c04dbde;
case 0x0c04dbe0u: goto P_0c04dbe0;
case 0x0c04dbe2u: goto P_0c04dbe2;
case 0x0c04dbe4u: goto P_0c04dbe4;
case 0x0c04dbe6u: goto P_0c04dbe6;
case 0x0c04dbe8u: goto P_0c04dbe8;
case 0x0c04dbeau: goto P_0c04dbea;
case 0x0c04dbecu: goto P_0c04dbec;
case 0x0c04dbeeu: goto P_0c04dbee;
case 0x0c04dbf0u: goto P_0c04dbf0;
case 0x0c04dbf2u: goto P_0c04dbf2;
case 0x0c04dbf4u: goto P_0c04dbf4;
case 0x0c04dbf6u: goto P_0c04dbf6;
case 0x0c04dbf8u: goto P_0c04dbf8;
case 0x0c04dbfau: goto P_0c04dbfa;
case 0x0c04dbfcu: goto P_0c04dbfc;
case 0x0c04dbfeu: goto P_0c04dbfe;
case 0x0c04dc00u: goto P_0c04dc00;
case 0x0c04dc02u: goto P_0c04dc02;
case 0x0c04dc04u: goto P_0c04dc04;
case 0x0c04dc06u: goto P_0c04dc06;
case 0x0c04dc08u: goto P_0c04dc08;
case 0x0c04dc0au: goto P_0c04dc0a;
case 0x0c04dc0cu: goto P_0c04dc0c;
case 0x0c04dc0eu: goto P_0c04dc0e;
case 0x0c04dc10u: goto P_0c04dc10;
case 0x0c04dc12u: goto P_0c04dc12;
case 0x0c04dc14u: goto P_0c04dc14;
case 0x0c04dc16u: goto P_0c04dc16;
case 0x0c04dc18u: goto P_0c04dc18;
case 0x0c04dc50u: goto P_0c04dc50;
case 0x0c04dc52u: goto P_0c04dc52;
case 0x0c04dc54u: goto P_0c04dc54;
case 0x0c04dc56u: goto P_0c04dc56;
case 0x0c04dc58u: goto P_0c04dc58;
case 0x0c04dc5au: goto P_0c04dc5a;
case 0x0c04dc5cu: goto P_0c04dc5c;
case 0x0c04dc5eu: goto P_0c04dc5e;
case 0x0c04dc60u: goto P_0c04dc60;
case 0x0c04dc62u: goto P_0c04dc62;
case 0x0c04dc64u: goto P_0c04dc64;
case 0x0c04dc66u: goto P_0c04dc66;
case 0x0c04dc68u: goto P_0c04dc68;
case 0x0c04dc6au: goto P_0c04dc6a;
case 0x0c04dc6cu: goto P_0c04dc6c;
case 0x0c04dc6eu: goto P_0c04dc6e;
case 0x0c04dc70u: goto P_0c04dc70;
case 0x0c04dc72u: goto P_0c04dc72;
case 0x0c04dc74u: goto P_0c04dc74;
case 0x0c04dc76u: goto P_0c04dc76;
case 0x0c04dc78u: goto P_0c04dc78;
case 0x0c04dc7au: goto P_0c04dc7a;
case 0x0c04dc7cu: goto P_0c04dc7c;
case 0x0c04dc7eu: goto P_0c04dc7e;
case 0x0c04dc80u: goto P_0c04dc80;
case 0x0c04dc82u: goto P_0c04dc82;
case 0x0c04dc84u: goto P_0c04dc84;
case 0x0c04dc86u: goto P_0c04dc86;
case 0x0c04dc88u: goto P_0c04dc88;
case 0x0c04dc8au: goto P_0c04dc8a;
case 0x0c04dc8cu: goto P_0c04dc8c;
case 0x0c04dc8eu: goto P_0c04dc8e;
case 0x0c04dc90u: goto P_0c04dc90;
case 0x0c04dc92u: goto P_0c04dc92;
case 0x0c04dc94u: goto P_0c04dc94;
case 0x0c04dc96u: goto P_0c04dc96;
case 0x0c04dc98u: goto P_0c04dc98;
case 0x0c04dc9au: goto P_0c04dc9a;
case 0x0c04dc9cu: goto P_0c04dc9c;
case 0x0c04dc9eu: goto P_0c04dc9e;
case 0x0c04dca0u: goto P_0c04dca0;
case 0x0c04dca2u: goto P_0c04dca2;
case 0x0c04dca4u: goto P_0c04dca4;
case 0x0c04dca6u: goto P_0c04dca6;
case 0x0c04dca8u: goto P_0c04dca8;
case 0x0c04dcaau: goto P_0c04dcaa;
case 0x0c04dcacu: goto P_0c04dcac;
case 0x0c04dcaeu: goto P_0c04dcae;
case 0x0c04dcb0u: goto P_0c04dcb0;
case 0x0c04dcb2u: goto P_0c04dcb2;
case 0x0c04dcb4u: goto P_0c04dcb4;
case 0x0c04dcb6u: goto P_0c04dcb6;
case 0x0c04dcb8u: goto P_0c04dcb8;
case 0x0c04dcbau: goto P_0c04dcba;
case 0x0c04dcbcu: goto P_0c04dcbc;
case 0x0c04dcbeu: goto P_0c04dcbe;
case 0x0c04dcc0u: goto P_0c04dcc0;
case 0x0c04dcc2u: goto P_0c04dcc2;
case 0x0c04dcc4u: goto P_0c04dcc4;
case 0x0c04dcc6u: goto P_0c04dcc6;
case 0x0c04dcc8u: goto P_0c04dcc8;
case 0x0c04dccau: goto P_0c04dcca;
case 0x0c04dcccu: goto P_0c04dccc;
case 0x0c04dcceu: goto P_0c04dcce;
case 0x0c04e40eu: goto P_0c04e40e;
case 0x0c04e410u: goto P_0c04e410;
case 0x0c04e712u: goto P_0c04e712;
case 0x0c04e714u: goto P_0c04e714;
case 0x0c04e716u: goto P_0c04e716;
case 0x0c04e718u: goto P_0c04e718;
case 0x0c04e71au: goto P_0c04e71a;
case 0x0c04e71cu: goto P_0c04e71c;
case 0x0c04e71eu: goto P_0c04e71e;
case 0x0c04e720u: goto P_0c04e720;
case 0x0c04e722u: goto P_0c04e722;
case 0x0c04e724u: goto P_0c04e724;
case 0x0c04e726u: goto P_0c04e726;
case 0x0c04e728u: goto P_0c04e728;
case 0x0c04e72au: goto P_0c04e72a;
case 0x0c04e72cu: goto P_0c04e72c;
case 0x0c04e72eu: goto P_0c04e72e;
case 0x0c04e730u: goto P_0c04e730;
case 0x0c04e732u: goto P_0c04e732;
case 0x0c04e734u: goto P_0c04e734;
case 0x0c04e736u: goto P_0c04e736;
case 0x0c04e738u: goto P_0c04e738;
case 0x0c04e73au: goto P_0c04e73a;
case 0x0c04e73cu: goto P_0c04e73c;
case 0x0c04e73eu: goto P_0c04e73e;
case 0x0c04e740u: goto P_0c04e740;
case 0x0c04e742u: goto P_0c04e742;
case 0x0c04e744u: goto P_0c04e744;
case 0x0c04e746u: goto P_0c04e746;
case 0x0c04e748u: goto P_0c04e748;
case 0x0c04e74au: goto P_0c04e74a;
case 0x0c04e74cu: goto P_0c04e74c;
case 0x0c04e74eu: goto P_0c04e74e;
case 0x0c04e750u: goto P_0c04e750;
case 0x0c04e752u: goto P_0c04e752;
case 0x0c04e754u: goto P_0c04e754;
case 0x0c04e756u: goto P_0c04e756;
case 0x0c04e758u: goto P_0c04e758;
case 0x0c04e75au: goto P_0c04e75a;
case 0x0c04e75cu: goto P_0c04e75c;
case 0x0c04e75eu: goto P_0c04e75e;
case 0x0c04e760u: goto P_0c04e760;
case 0x0c04e762u: goto P_0c04e762;
case 0x0c04e764u: goto P_0c04e764;
case 0x0c04e766u: goto P_0c04e766;
case 0x0c04e768u: goto P_0c04e768;
case 0x0c04e76au: goto P_0c04e76a;
case 0x0c04e76cu: goto P_0c04e76c;
case 0x0c04e76eu: goto P_0c04e76e;
case 0x0c04e770u: goto P_0c04e770;
case 0x0c04e772u: goto P_0c04e772;
case 0x0c04e774u: goto P_0c04e774;
case 0x0c04e776u: goto P_0c04e776;
case 0x0c04e778u: goto P_0c04e778;
case 0x0c04e77au: goto P_0c04e77a;
case 0x0c04e77cu: goto P_0c04e77c;
case 0x0c04e77eu: goto P_0c04e77e;
case 0x0c04e780u: goto P_0c04e780;
case 0x0c04e782u: goto P_0c04e782;
case 0x0c04e784u: goto P_0c04e784;
case 0x0c04e786u: goto P_0c04e786;
case 0x0c04e788u: goto P_0c04e788;
case 0x0c04e78au: goto P_0c04e78a;
case 0x0c04e78cu: goto P_0c04e78c;
case 0x0c04e78eu: goto P_0c04e78e;
case 0x0c04e790u: goto P_0c04e790;
case 0x0c04e792u: goto P_0c04e792;
case 0x0c04e794u: goto P_0c04e794;
case 0x0c04e796u: goto P_0c04e796;
case 0x0c04e798u: goto P_0c04e798;
case 0x0c04e79au: goto P_0c04e79a;
case 0x0c04e79cu: goto P_0c04e79c;
case 0x0c04e79eu: goto P_0c04e79e;
case 0x0c04e7a0u: goto P_0c04e7a0;
case 0x0c04e7a2u: goto P_0c04e7a2;
case 0x0c04e7a4u: goto P_0c04e7a4;
case 0x0c04e7a6u: goto P_0c04e7a6;
case 0x0c04e7a8u: goto P_0c04e7a8;
case 0x0c04e7aau: goto P_0c04e7aa;
case 0x0c04e7acu: goto P_0c04e7ac;
case 0x0c04eebeu: goto P_0c04eebe;
case 0x0c04eec0u: goto P_0c04eec0;
case 0x0c04eec2u: goto P_0c04eec2;
case 0x0c04eec4u: goto P_0c04eec4;
case 0x0c04eec6u: goto P_0c04eec6;
case 0x0c04eec8u: goto P_0c04eec8;
case 0x0c04eecau: goto P_0c04eeca;
case 0x0c04eeccu: goto P_0c04eecc;
case 0x0c04eeceu: goto P_0c04eece;
case 0x0c04eed0u: goto P_0c04eed0;
case 0x0c04eed2u: goto P_0c04eed2;
case 0x0c04eed4u: goto P_0c04eed4;
case 0x0c04eed6u: goto P_0c04eed6;
case 0x0c04eed8u: goto P_0c04eed8;
case 0x0c04eedau: goto P_0c04eeda;
case 0x0c04eedcu: goto P_0c04eedc;
case 0x0c04eedeu: goto P_0c04eede;
case 0x0c04eee0u: goto P_0c04eee0;
case 0x0c04eee2u: goto P_0c04eee2;
case 0x0c04eee4u: goto P_0c04eee4;
case 0x0c04eee6u: goto P_0c04eee6;
case 0x0c04eee8u: goto P_0c04eee8;
case 0x0c04eeeau: goto P_0c04eeea;
case 0x0c04eeecu: goto P_0c04eeec;
case 0x0c04eeeeu: goto P_0c04eeee;
case 0x0c04eef0u: goto P_0c04eef0;
case 0x0c04eef2u: goto P_0c04eef2;
case 0x0c04eef4u: goto P_0c04eef4;
case 0x0c04eef6u: goto P_0c04eef6;
case 0x0c04eef8u: goto P_0c04eef8;
case 0x0c04eefau: goto P_0c04eefa;
case 0x0c04eefcu: goto P_0c04eefc;
case 0x0c04eefeu: goto P_0c04eefe;
case 0x0c04ef00u: goto P_0c04ef00;
case 0x0c04ef02u: goto P_0c04ef02;
case 0x0c04ef04u: goto P_0c04ef04;
case 0x0c04ef06u: goto P_0c04ef06;
case 0x0c04ef08u: goto P_0c04ef08;
case 0x0c04ef0au: goto P_0c04ef0a;
case 0x0c04ef0cu: goto P_0c04ef0c;
case 0x0c04ef48u: goto P_0c04ef48;
case 0x0c04ef4au: goto P_0c04ef4a;
case 0x0c04ef4cu: goto P_0c04ef4c;
case 0x0c04ef4eu: goto P_0c04ef4e;
case 0x0c04ef50u: goto P_0c04ef50;
case 0x0c04ef52u: goto P_0c04ef52;
case 0x0c04ef54u: goto P_0c04ef54;
case 0x0c04ef56u: goto P_0c04ef56;
case 0x0c04ef58u: goto P_0c04ef58;
case 0x0c04ef5au: goto P_0c04ef5a;
case 0x0c04ef5cu: goto P_0c04ef5c;
case 0x0c04ef5eu: goto P_0c04ef5e;
case 0x0c04ef60u: goto P_0c04ef60;
case 0x0c04ef62u: goto P_0c04ef62;
case 0x0c04ef64u: goto P_0c04ef64;
case 0x0c04ef66u: goto P_0c04ef66;
case 0x0c04ef68u: goto P_0c04ef68;
case 0x0c04ef6au: goto P_0c04ef6a;
case 0x0c04ef6cu: goto P_0c04ef6c;
case 0x0c04ef6eu: goto P_0c04ef6e;
case 0x0c04ef70u: goto P_0c04ef70;
case 0x0c04ef72u: goto P_0c04ef72;
case 0x0c04ef74u: goto P_0c04ef74;
case 0x0c04ef76u: goto P_0c04ef76;
case 0x0c04ef78u: goto P_0c04ef78;
case 0x0c04ef7au: goto P_0c04ef7a;
case 0x0c04ef7cu: goto P_0c04ef7c;
case 0x0c04ef7eu: goto P_0c04ef7e;
case 0x0c04ef80u: goto P_0c04ef80;
case 0x0c04ef82u: goto P_0c04ef82;
case 0x0c04ef84u: goto P_0c04ef84;
case 0x0c04ef86u: goto P_0c04ef86;
case 0x0c04ef88u: goto P_0c04ef88;
case 0x0c04ef8au: goto P_0c04ef8a;
case 0x0c04fa7cu: goto P_0c04fa7c;
case 0x0c04fa7eu: goto P_0c04fa7e;
case 0x0c04fa80u: goto P_0c04fa80;
case 0x0c04fa82u: goto P_0c04fa82;
case 0x0c04fa84u: goto P_0c04fa84;
case 0x0c04fa86u: goto P_0c04fa86;
case 0x0c04fa88u: goto P_0c04fa88;
case 0x0c04fa8au: goto P_0c04fa8a;
case 0x0c04fa8cu: goto P_0c04fa8c;
case 0x0c04fa8eu: goto P_0c04fa8e;
case 0x0c04fa90u: goto P_0c04fa90;
case 0x0c04fa92u: goto P_0c04fa92;
case 0x0c04fa94u: goto P_0c04fa94;
case 0x0c04fa96u: goto P_0c04fa96;
case 0x0c04fa98u: goto P_0c04fa98;
case 0x0c04fa9au: goto P_0c04fa9a;
case 0x0c04fa9cu: goto P_0c04fa9c;
case 0x0c04fa9eu: goto P_0c04fa9e;
case 0x0c04faa0u: goto P_0c04faa0;
case 0x0c04faa2u: goto P_0c04faa2;
case 0x0c04faa4u: goto P_0c04faa4;
case 0x0c04faa6u: goto P_0c04faa6;
case 0x0c04faa8u: goto P_0c04faa8;
case 0x0c04faaau: goto P_0c04faaa;
case 0x0c04faacu: goto P_0c04faac;
case 0x0c04faaeu: goto P_0c04faae;
case 0x0c04fe40u: goto P_0c04fe40;
case 0x0c04fe42u: goto P_0c04fe42;
case 0x0c04fe44u: goto P_0c04fe44;
case 0x0c04ff62u: goto P_0c04ff62;
case 0x0c04ff64u: goto P_0c04ff64;
case 0x0c04ff66u: goto P_0c04ff66;
case 0x0c04ff68u: goto P_0c04ff68;
case 0x0c04ff6au: goto P_0c04ff6a;
case 0x0c04ff6cu: goto P_0c04ff6c;
case 0x0c04ff6eu: goto P_0c04ff6e;
case 0x0c04ff70u: goto P_0c04ff70;
case 0x0c04ff72u: goto P_0c04ff72;
case 0x0c04ff74u: goto P_0c04ff74;
case 0x0c04ff76u: goto P_0c04ff76;
case 0x0c04ff78u: goto P_0c04ff78;
case 0x0c04ff7au: goto P_0c04ff7a;
case 0x0c04ff7cu: goto P_0c04ff7c;
case 0x0c04ff7eu: goto P_0c04ff7e;
case 0x0c04ff80u: goto P_0c04ff80;
case 0x0c04ff82u: goto P_0c04ff82;
case 0x0c04ff84u: goto P_0c04ff84;
case 0x0c04ff86u: goto P_0c04ff86;
case 0x0c04ff88u: goto P_0c04ff88;
case 0x0c04ff8au: goto P_0c04ff8a;
case 0x0c04ff8cu: goto P_0c04ff8c;
case 0x0c04ff8eu: goto P_0c04ff8e;
case 0x0c04ff90u: goto P_0c04ff90;
case 0x0c04ff92u: goto P_0c04ff92;
case 0x0c04ff94u: goto P_0c04ff94;
case 0x0c04ff96u: goto P_0c04ff96;
case 0x0c04ff98u: goto P_0c04ff98;
case 0x0c04ff9au: goto P_0c04ff9a;
case 0x0c04ff9cu: goto P_0c04ff9c;
case 0x0c04ff9eu: goto P_0c04ff9e;
case 0x0c04ffa0u: goto P_0c04ffa0;
case 0x0c04ffa2u: goto P_0c04ffa2;
case 0x0c04ffa4u: goto P_0c04ffa4;
case 0x0c04ffa6u: goto P_0c04ffa6;
case 0x0c04ffa8u: goto P_0c04ffa8;
case 0x0c04ffaau: goto P_0c04ffaa;
case 0x0c04ffacu: goto P_0c04ffac;
case 0x0c04ffaeu: goto P_0c04ffae;
case 0x0c04ffb0u: goto P_0c04ffb0;
case 0x0c04ffb2u: goto P_0c04ffb2;
case 0x0c04ffb4u: goto P_0c04ffb4;
case 0x0c04ffb6u: goto P_0c04ffb6;
case 0x0c04ffb8u: goto P_0c04ffb8;
case 0x0c04ffbau: goto P_0c04ffba;
case 0x0c04ffbcu: goto P_0c04ffbc;
case 0x0c04ffbeu: goto P_0c04ffbe;
case 0x0c04ffc0u: goto P_0c04ffc0;
case 0x0c04ffc2u: goto P_0c04ffc2;
case 0x0c04ffc4u: goto P_0c04ffc4;
case 0x0c04ffc6u: goto P_0c04ffc6;
case 0x0c04ffc8u: goto P_0c04ffc8;
case 0x0c04ffcau: goto P_0c04ffca;
case 0x0c04ffccu: goto P_0c04ffcc;
case 0x0c04ffceu: goto P_0c04ffce;
case 0x0c04ffd0u: goto P_0c04ffd0;
case 0x0c04ffd2u: goto P_0c04ffd2;
case 0x0c04ffd4u: goto P_0c04ffd4;
case 0x0c04ffd6u: goto P_0c04ffd6;
case 0x0c04ffd8u: goto P_0c04ffd8;
case 0x0c04fffcu: goto P_0c04fffc;
case 0x0c04fffeu: goto P_0c04fffe;
case 0x0c050000u: goto P_0c050000;
case 0x0c050002u: goto P_0c050002;
case 0x0c050004u: goto P_0c050004;
case 0x0c050006u: goto P_0c050006;
case 0x0c050008u: goto P_0c050008;
case 0x0c05000au: goto P_0c05000a;
case 0x0c05000cu: goto P_0c05000c;
case 0x0c05000eu: goto P_0c05000e;
case 0x0c050010u: goto P_0c050010;
case 0x0c050012u: goto P_0c050012;
case 0x0c050014u: goto P_0c050014;
case 0x0c050016u: goto P_0c050016;
case 0x0c050018u: goto P_0c050018;
case 0x0c05001au: goto P_0c05001a;
case 0x0c05001cu: goto P_0c05001c;
case 0x0c05001eu: goto P_0c05001e;
case 0x0c050020u: goto P_0c050020;
case 0x0c050022u: goto P_0c050022;
case 0x0c050024u: goto P_0c050024;
case 0x0c050026u: goto P_0c050026;
case 0x0c050028u: goto P_0c050028;
case 0x0c05002au: goto P_0c05002a;
case 0x0c05002cu: goto P_0c05002c;
case 0x0c05002eu: goto P_0c05002e;
case 0x0c050030u: goto P_0c050030;
case 0x0c050032u: goto P_0c050032;
case 0x0c050034u: goto P_0c050034;
case 0x0c050036u: goto P_0c050036;
case 0x0c050038u: goto P_0c050038;
case 0x0c05003au: goto P_0c05003a;
case 0x0c05003cu: goto P_0c05003c;
case 0x0c05003eu: goto P_0c05003e;
case 0x0c050040u: goto P_0c050040;
case 0x0c050042u: goto P_0c050042;
case 0x0c050044u: goto P_0c050044;
case 0x0c050046u: goto P_0c050046;
case 0x0c050048u: goto P_0c050048;
case 0x0c05004au: goto P_0c05004a;
case 0x0c05004cu: goto P_0c05004c;
case 0x0c05004eu: goto P_0c05004e;
case 0x0c050050u: goto P_0c050050;
case 0x0c050052u: goto P_0c050052;
case 0x0c050054u: goto P_0c050054;
case 0x0c050056u: goto P_0c050056;
case 0x0c050058u: goto P_0c050058;
case 0x0c05005au: goto P_0c05005a;
case 0x0c05005cu: goto P_0c05005c;
case 0x0c05005eu: goto P_0c05005e;
case 0x0c050060u: goto P_0c050060;
case 0x0c050062u: goto P_0c050062;
case 0x0c050064u: goto P_0c050064;
case 0x0c050066u: goto P_0c050066;
case 0x0c050068u: goto P_0c050068;
case 0x0c05006au: goto P_0c05006a;
case 0x0c05006cu: goto P_0c05006c;
case 0x0c05006eu: goto P_0c05006e;
case 0x0c050070u: goto P_0c050070;
case 0x0c050072u: goto P_0c050072;
case 0x0c050074u: goto P_0c050074;
case 0x0c050076u: goto P_0c050076;
case 0x0c050078u: goto P_0c050078;
case 0x0c05007au: goto P_0c05007a;
case 0x0c05007cu: goto P_0c05007c;
case 0x0c05007eu: goto P_0c05007e;
case 0x0c050080u: goto P_0c050080;
case 0x0c050082u: goto P_0c050082;
case 0x0c050084u: goto P_0c050084;
case 0x0c050086u: goto P_0c050086;
case 0x0c050088u: goto P_0c050088;
case 0x0c05008au: goto P_0c05008a;
case 0x0c05008cu: goto P_0c05008c;
case 0x0c05008eu: goto P_0c05008e;
case 0x0c050090u: goto P_0c050090;
case 0x0c050092u: goto P_0c050092;
case 0x0c050094u: goto P_0c050094;
case 0x0c050096u: goto P_0c050096;
case 0x0c050098u: goto P_0c050098;
case 0x0c05009au: goto P_0c05009a;
case 0x0c05009cu: goto P_0c05009c;
case 0x0c05009eu: goto P_0c05009e;
case 0x0c0500a0u: goto P_0c0500a0;
case 0x0c0500a2u: goto P_0c0500a2;
case 0x0c0500a4u: goto P_0c0500a4;
case 0x0c0500a6u: goto P_0c0500a6;
case 0x0c0500a8u: goto P_0c0500a8;
case 0x0c0500aau: goto P_0c0500aa;
case 0x0c0500acu: goto P_0c0500ac;
case 0x0c0500aeu: goto P_0c0500ae;
case 0x0c0500b0u: goto P_0c0500b0;
case 0x0c0500b2u: goto P_0c0500b2;
case 0x0c0500b4u: goto P_0c0500b4;
case 0x0c0500b6u: goto P_0c0500b6;
case 0x0c0500b8u: goto P_0c0500b8;
case 0x0c0500bau: goto P_0c0500ba;
case 0x0c0500bcu: goto P_0c0500bc;
case 0x0c0500beu: goto P_0c0500be;
case 0x0c0500f0u: goto P_0c0500f0;
case 0x0c0500f2u: goto P_0c0500f2;
case 0x0c0500f4u: goto P_0c0500f4;
case 0x0c0500f6u: goto P_0c0500f6;
case 0x0c0500f8u: goto P_0c0500f8;
case 0x0c0500fau: goto P_0c0500fa;
case 0x0c0500fcu: goto P_0c0500fc;
case 0x0c0500feu: goto P_0c0500fe;
case 0x0c050100u: goto P_0c050100;
case 0x0c050102u: goto P_0c050102;
case 0x0c050104u: goto P_0c050104;
case 0x0c050106u: goto P_0c050106;
case 0x0c050108u: goto P_0c050108;
case 0x0c05010au: goto P_0c05010a;
case 0x0c05010cu: goto P_0c05010c;
case 0x0c05010eu: goto P_0c05010e;
case 0x0c050110u: goto P_0c050110;
case 0x0c050112u: goto P_0c050112;
case 0x0c050114u: goto P_0c050114;
case 0x0c050116u: goto P_0c050116;
case 0x0c050118u: goto P_0c050118;
case 0x0c05011au: goto P_0c05011a;
case 0x0c05011cu: goto P_0c05011c;
case 0x0c05011eu: goto P_0c05011e;
case 0x0c050120u: goto P_0c050120;
case 0x0c050122u: goto P_0c050122;
case 0x0c050124u: goto P_0c050124;
case 0x0c050126u: goto P_0c050126;
case 0x0c050164u: goto P_0c050164;
case 0x0c050166u: goto P_0c050166;
case 0x0c050168u: goto P_0c050168;
case 0x0c05016au: goto P_0c05016a;
case 0x0c05016cu: goto P_0c05016c;
case 0x0c05016eu: goto P_0c05016e;
case 0x0c050170u: goto P_0c050170;
case 0x0c050172u: goto P_0c050172;
default: return vf3_matrix_family(target,s,ram);
}
P_0c046598: /* original 4f22, guest PC 0x0c046598 */
if(!s->budget--) { s->failed_pc=0x0c046598u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04659a;
P_0c04659a: /* original d35c, guest PC 0x0c04659a */
if(!s->budget--) { s->failed_pc=0x0c04659au; return 0; }
r[3]=read(ram,0x0c04670cu,4);
goto P_0c04659c;
P_0c04659c: /* original 430b, guest PC 0x0c04659c */
if(!s->budget--) { s->failed_pc=0x0c04659cu; return 0; }
target=r[3];
r[16]=0x0c0465a0u;
r[14]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0465a0u) { target=s->pc; goto dispatch; }
goto P_0c0465a0;
P_0c04659e: /* original 6e43, guest PC 0x0c04659e */
if(!s->budget--) { s->failed_pc=0x0c04659eu; return 0; }
r[14]=r[4];
goto P_0c0465a0;
P_0c0465a0: /* original 2008, guest PC 0x0c0465a0 */
if(!s->budget--) { s->failed_pc=0x0c0465a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0465a2;
P_0c0465a2: /* original 8901, guest PC 0x0c0465a2 */
if(!s->budget--) { s->failed_pc=0x0c0465a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0465a8; }
goto P_0c0465a4;
P_0c0465a4: /* original a010, guest PC 0x0c0465a4 */
if(!s->budget--) { s->failed_pc=0x0c0465a4u; return 0; }
r[0]=0xffffffffu;
goto P_0c0465c8;
P_0c0465a6: /* original e0ff, guest PC 0x0c0465a6 */
if(!s->budget--) { s->failed_pc=0x0c0465a6u; return 0; }
r[0]=0xffffffffu;
goto P_0c0465a8;
P_0c0465a8: /* original d359, guest PC 0x0c0465a8 */
if(!s->budget--) { s->failed_pc=0x0c0465a8u; return 0; }
r[3]=read(ram,0x0c046710u,4);
goto P_0c0465aa;
P_0c0465aa: /* original e501, guest PC 0x0c0465aa */
if(!s->budget--) { s->failed_pc=0x0c0465aau; return 0; }
r[5]=0x00000001u;
goto P_0c0465ac;
P_0c0465ac: /* original 430b, guest PC 0x0c0465ac */
if(!s->budget--) { s->failed_pc=0x0c0465acu; return 0; }
target=r[3];
r[16]=0x0c0465b0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0465b0u) { target=s->pc; goto dispatch; }
goto P_0c0465b0;
P_0c0465ae: /* original 64e3, guest PC 0x0c0465ae */
if(!s->budget--) { s->failed_pc=0x0c0465aeu; return 0; }
r[4]=r[14];
goto P_0c0465b0;
P_0c0465b0: /* original ed00, guest PC 0x0c0465b0 */
if(!s->budget--) { s->failed_pc=0x0c0465b0u; return 0; }
r[13]=0x00000000u;
goto P_0c0465b2;
P_0c0465b2: /* original 65e3, guest PC 0x0c0465b2 */
if(!s->budget--) { s->failed_pc=0x0c0465b2u; return 0; }
r[5]=r[14];
goto P_0c0465b4;
P_0c0465b4: /* original 2fd6, guest PC 0x0c0465b4 */
if(!s->budget--) { s->failed_pc=0x0c0465b4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0465b6;
P_0c0465b6: /* original 66d3, guest PC 0x0c0465b6 */
if(!s->budget--) { s->failed_pc=0x0c0465b6u; return 0; }
r[6]=r[13];
goto P_0c0465b8;
P_0c0465b8: /* original 2fd6, guest PC 0x0c0465b8 */
if(!s->budget--) { s->failed_pc=0x0c0465b8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0465ba;
P_0c0465ba: /* original 67d3, guest PC 0x0c0465ba */
if(!s->budget--) { s->failed_pc=0x0c0465bau; return 0; }
r[7]=r[13];
goto P_0c0465bc;
P_0c0465bc: /* original 2fd6, guest PC 0x0c0465bc */
if(!s->budget--) { s->failed_pc=0x0c0465bcu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0465be;
P_0c0465be: /* original d255, guest PC 0x0c0465be */
if(!s->budget--) { s->failed_pc=0x0c0465beu; return 0; }
r[2]=read(ram,0x0c046714u,4);
goto P_0c0465c0;
P_0c0465c0: /* original 420b, guest PC 0x0c0465c0 */
if(!s->budget--) { s->failed_pc=0x0c0465c0u; return 0; }
target=r[2];
r[16]=0x0c0465c4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0465c4u) { target=s->pc; goto dispatch; }
goto P_0c0465c4;
P_0c0465c2: /* original 64e3, guest PC 0x0c0465c2 */
if(!s->budget--) { s->failed_pc=0x0c0465c2u; return 0; }
r[4]=r[14];
goto P_0c0465c4;
P_0c0465c4: /* original 60d3, guest PC 0x0c0465c4 */
if(!s->budget--) { s->failed_pc=0x0c0465c4u; return 0; }
r[0]=r[13];
goto P_0c0465c6;
P_0c0465c6: /* original 7f0c, guest PC 0x0c0465c6 */
if(!s->budget--) { s->failed_pc=0x0c0465c6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0465c8;
P_0c0465c8: /* original 4f26, guest PC 0x0c0465c8 */
if(!s->budget--) { s->failed_pc=0x0c0465c8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0465ca;
P_0c0465ca: /* original 6df6, guest PC 0x0c0465ca */
if(!s->budget--) { s->failed_pc=0x0c0465cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0465cc;
P_0c0465cc: /* original 000b, guest PC 0x0c0465cc */
if(!s->budget--) { s->failed_pc=0x0c0465ccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0465ce: /* original 6ef6, guest PC 0x0c0465ce */
if(!s->budget--) { s->failed_pc=0x0c0465ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0465d0u,s,ram);
P_0c0465d4: /* original 4f22, guest PC 0x0c0465d4 */
if(!s->budget--) { s->failed_pc=0x0c0465d4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0465d6;
P_0c0465d6: /* original d34d, guest PC 0x0c0465d6 */
if(!s->budget--) { s->failed_pc=0x0c0465d6u; return 0; }
r[3]=read(ram,0x0c04670cu,4);
goto P_0c0465d8;
P_0c0465d8: /* original 430b, guest PC 0x0c0465d8 */
if(!s->budget--) { s->failed_pc=0x0c0465d8u; return 0; }
target=r[3];
r[16]=0x0c0465dcu;
r[14]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0465dcu) { target=s->pc; goto dispatch; }
goto P_0c0465dc;
P_0c0465da: /* original 6e43, guest PC 0x0c0465da */
if(!s->budget--) { s->failed_pc=0x0c0465dau; return 0; }
r[14]=r[4];
goto P_0c0465dc;
P_0c0465dc: /* original 2008, guest PC 0x0c0465dc */
if(!s->budget--) { s->failed_pc=0x0c0465dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0465de;
P_0c0465de: /* original 8901, guest PC 0x0c0465de */
if(!s->budget--) { s->failed_pc=0x0c0465deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0465e4; }
goto P_0c0465e0;
P_0c0465e0: /* original a010, guest PC 0x0c0465e0 */
if(!s->budget--) { s->failed_pc=0x0c0465e0u; return 0; }
r[0]=0xffffffffu;
goto P_0c046604;
P_0c0465e2: /* original e0ff, guest PC 0x0c0465e2 */
if(!s->budget--) { s->failed_pc=0x0c0465e2u; return 0; }
r[0]=0xffffffffu;
goto P_0c0465e4;
P_0c0465e4: /* original d34a, guest PC 0x0c0465e4 */
if(!s->budget--) { s->failed_pc=0x0c0465e4u; return 0; }
r[3]=read(ram,0x0c046710u,4);
goto P_0c0465e6;
P_0c0465e6: /* original e512, guest PC 0x0c0465e6 */
if(!s->budget--) { s->failed_pc=0x0c0465e6u; return 0; }
r[5]=0x00000012u;
goto P_0c0465e8;
P_0c0465e8: /* original 430b, guest PC 0x0c0465e8 */
if(!s->budget--) { s->failed_pc=0x0c0465e8u; return 0; }
target=r[3];
r[16]=0x0c0465ecu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0465ecu) { target=s->pc; goto dispatch; }
goto P_0c0465ec;
P_0c0465ea: /* original 64e3, guest PC 0x0c0465ea */
if(!s->budget--) { s->failed_pc=0x0c0465eau; return 0; }
r[4]=r[14];
goto P_0c0465ec;
P_0c0465ec: /* original ed00, guest PC 0x0c0465ec */
if(!s->budget--) { s->failed_pc=0x0c0465ecu; return 0; }
r[13]=0x00000000u;
goto P_0c0465ee;
P_0c0465ee: /* original 65e3, guest PC 0x0c0465ee */
if(!s->budget--) { s->failed_pc=0x0c0465eeu; return 0; }
r[5]=r[14];
goto P_0c0465f0;
P_0c0465f0: /* original 2fd6, guest PC 0x0c0465f0 */
if(!s->budget--) { s->failed_pc=0x0c0465f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0465f2;
P_0c0465f2: /* original 66d3, guest PC 0x0c0465f2 */
if(!s->budget--) { s->failed_pc=0x0c0465f2u; return 0; }
r[6]=r[13];
goto P_0c0465f4;
P_0c0465f4: /* original 2fd6, guest PC 0x0c0465f4 */
if(!s->budget--) { s->failed_pc=0x0c0465f4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0465f6;
P_0c0465f6: /* original 67d3, guest PC 0x0c0465f6 */
if(!s->budget--) { s->failed_pc=0x0c0465f6u; return 0; }
r[7]=r[13];
goto P_0c0465f8;
P_0c0465f8: /* original 2fd6, guest PC 0x0c0465f8 */
if(!s->budget--) { s->failed_pc=0x0c0465f8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0465fa;
P_0c0465fa: /* original d246, guest PC 0x0c0465fa */
if(!s->budget--) { s->failed_pc=0x0c0465fau; return 0; }
r[2]=read(ram,0x0c046714u,4);
goto P_0c0465fc;
P_0c0465fc: /* original 420b, guest PC 0x0c0465fc */
if(!s->budget--) { s->failed_pc=0x0c0465fcu; return 0; }
target=r[2];
r[16]=0x0c046600u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046600u) { target=s->pc; goto dispatch; }
goto P_0c046600;
P_0c0465fe: /* original 64e3, guest PC 0x0c0465fe */
if(!s->budget--) { s->failed_pc=0x0c0465feu; return 0; }
r[4]=r[14];
goto P_0c046600;
P_0c046600: /* original 60d3, guest PC 0x0c046600 */
if(!s->budget--) { s->failed_pc=0x0c046600u; return 0; }
r[0]=r[13];
goto P_0c046602;
P_0c046602: /* original 7f0c, guest PC 0x0c046602 */
if(!s->budget--) { s->failed_pc=0x0c046602u; return 0; }
r[15]+=0x0000000cu;
goto P_0c046604;
P_0c046604: /* original 4f26, guest PC 0x0c046604 */
if(!s->budget--) { s->failed_pc=0x0c046604u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046606;
P_0c046606: /* original 6df6, guest PC 0x0c046606 */
if(!s->budget--) { s->failed_pc=0x0c046606u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c046608;
P_0c046608: /* original 000b, guest PC 0x0c046608 */
if(!s->budget--) { s->failed_pc=0x0c046608u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04660a: /* original 6ef6, guest PC 0x0c04660a */
if(!s->budget--) { s->failed_pc=0x0c04660au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04660cu,s,ram);
P_0c046620: /* original 4f22, guest PC 0x0c046620 */
if(!s->budget--) { s->failed_pc=0x0c046620u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046622;
P_0c046622: /* original 7ff4, guest PC 0x0c046622 */
if(!s->budget--) { s->failed_pc=0x0c046622u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c046624;
P_0c046624: /* original 2f52, guest PC 0x0c046624 */
if(!s->budget--) { s->failed_pc=0x0c046624u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c046626;
P_0c046626: /* original 1f62, guest PC 0x0c046626 */
if(!s->budget--) { s->failed_pc=0x0c046626u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c046628;
P_0c046628: /* original 1f71, guest PC 0x0c046628 */
if(!s->budget--) { s->failed_pc=0x0c046628u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c04662a;
P_0c04662a: /* original d338, guest PC 0x0c04662a */
if(!s->budget--) { s->failed_pc=0x0c04662au; return 0; }
r[3]=read(ram,0x0c04670cu,4);
goto P_0c04662c;
P_0c04662c: /* original 430b, guest PC 0x0c04662c */
if(!s->budget--) { s->failed_pc=0x0c04662cu; return 0; }
target=r[3];
r[16]=0x0c046630u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046630u) { target=s->pc; goto dispatch; }
goto P_0c046630;
P_0c04662e: /* original 64e3, guest PC 0x0c04662e */
if(!s->budget--) { s->failed_pc=0x0c04662eu; return 0; }
r[4]=r[14];
goto P_0c046630;
P_0c046630: /* original 2008, guest PC 0x0c046630 */
if(!s->budget--) { s->failed_pc=0x0c046630u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c046632;
P_0c046632: /* original 8904, guest PC 0x0c046632 */
if(!s->budget--) { s->failed_pc=0x0c046632u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04663e; }
goto P_0c046634;
P_0c046634: /* original 7f0c, guest PC 0x0c046634 */
if(!s->budget--) { s->failed_pc=0x0c046634u; return 0; }
r[15]+=0x0000000cu;
goto P_0c046636;
P_0c046636: /* original 4f26, guest PC 0x0c046636 */
if(!s->budget--) { s->failed_pc=0x0c046636u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046638;
P_0c046638: /* original e0ff, guest PC 0x0c046638 */
if(!s->budget--) { s->failed_pc=0x0c046638u; return 0; }
r[0]=0xffffffffu;
goto P_0c04663a;
P_0c04663a: /* original 000b, guest PC 0x0c04663a */
if(!s->budget--) { s->failed_pc=0x0c04663au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04663c: /* original 6ef6, guest PC 0x0c04663c */
if(!s->budget--) { s->failed_pc=0x0c04663cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04663e;
P_0c04663e: /* original d334, guest PC 0x0c04663e */
if(!s->budget--) { s->failed_pc=0x0c04663eu; return 0; }
r[3]=read(ram,0x0c046710u,4);
goto P_0c046640;
P_0c046640: /* original e503, guest PC 0x0c046640 */
if(!s->budget--) { s->failed_pc=0x0c046640u; return 0; }
r[5]=0x00000003u;
goto P_0c046642;
P_0c046642: /* original 430b, guest PC 0x0c046642 */
if(!s->budget--) { s->failed_pc=0x0c046642u; return 0; }
target=r[3];
r[16]=0x0c046646u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046646u) { target=s->pc; goto dispatch; }
goto P_0c046646;
P_0c046644: /* original 64e3, guest PC 0x0c046644 */
if(!s->budget--) { s->failed_pc=0x0c046644u; return 0; }
r[4]=r[14];
goto P_0c046646;
P_0c046646: /* original e200, guest PC 0x0c046646 */
if(!s->budget--) { s->failed_pc=0x0c046646u; return 0; }
r[2]=0x00000000u;
goto P_0c046648;
P_0c046648: /* original 65e3, guest PC 0x0c046648 */
if(!s->budget--) { s->failed_pc=0x0c046648u; return 0; }
r[5]=r[14];
goto P_0c04664a;
P_0c04664a: /* original 2f26, guest PC 0x0c04664a */
if(!s->budget--) { s->failed_pc=0x0c04664au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04664c;
P_0c04664c: /* original 53f6, guest PC 0x0c04664c */
if(!s->budget--) { s->failed_pc=0x0c04664cu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c04664e;
P_0c04664e: /* original 2f36, guest PC 0x0c04664e */
if(!s->budget--) { s->failed_pc=0x0c04664eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046650;
P_0c046650: /* original 51f3, guest PC 0x0c046650 */
if(!s->budget--) { s->failed_pc=0x0c046650u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c046652;
P_0c046652: /* original 2f16, guest PC 0x0c046652 */
if(!s->budget--) { s->failed_pc=0x0c046652u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046654;
P_0c046654: /* original d32f, guest PC 0x0c046654 */
if(!s->budget--) { s->failed_pc=0x0c046654u; return 0; }
r[3]=read(ram,0x0c046714u,4);
goto P_0c046656;
P_0c046656: /* original 56f3, guest PC 0x0c046656 */
if(!s->budget--) { s->failed_pc=0x0c046656u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c046658;
P_0c046658: /* original 57f5, guest PC 0x0c046658 */
if(!s->budget--) { s->failed_pc=0x0c046658u; return 0; }
r[7]=read(ram,r[15]+20,4);
goto P_0c04665a;
P_0c04665a: /* original 430b, guest PC 0x0c04665a */
if(!s->budget--) { s->failed_pc=0x0c04665au; return 0; }
target=r[3];
r[16]=0x0c04665eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04665eu) { target=s->pc; goto dispatch; }
goto P_0c04665e;
P_0c04665c: /* original 64e3, guest PC 0x0c04665c */
if(!s->budget--) { s->failed_pc=0x0c04665cu; return 0; }
r[4]=r[14];
goto P_0c04665e;
P_0c04665e: /* original 7f0c, guest PC 0x0c04665e */
if(!s->budget--) { s->failed_pc=0x0c04665eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c046660;
P_0c046660: /* original d32f, guest PC 0x0c046660 */
if(!s->budget--) { s->failed_pc=0x0c046660u; return 0; }
r[3]=read(ram,0x0c046720u,4);
goto P_0c046662;
P_0c046662: /* original 65f2, guest PC 0x0c046662 */
if(!s->budget--) { s->failed_pc=0x0c046662u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c046664;
P_0c046664: /* original 430b, guest PC 0x0c046664 */
if(!s->budget--) { s->failed_pc=0x0c046664u; return 0; }
target=r[3];
r[16]=0x0c046668u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046668u) { target=s->pc; goto dispatch; }
goto P_0c046668;
P_0c046666: /* original 64e3, guest PC 0x0c046666 */
if(!s->budget--) { s->failed_pc=0x0c046666u; return 0; }
r[4]=r[14];
goto P_0c046668;
P_0c046668: /* original d32e, guest PC 0x0c046668 */
if(!s->budget--) { s->failed_pc=0x0c046668u; return 0; }
r[3]=read(ram,0x0c046724u,4);
goto P_0c04666a;
P_0c04666a: /* original 55f1, guest PC 0x0c04666a */
if(!s->budget--) { s->failed_pc=0x0c04666au; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c04666c;
P_0c04666c: /* original 430b, guest PC 0x0c04666c */
if(!s->budget--) { s->failed_pc=0x0c04666cu; return 0; }
target=r[3];
r[16]=0x0c046670u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046670u) { target=s->pc; goto dispatch; }
goto P_0c046670;
P_0c04666e: /* original 64e3, guest PC 0x0c04666e */
if(!s->budget--) { s->failed_pc=0x0c04666eu; return 0; }
r[4]=r[14];
goto P_0c046670;
P_0c046670: /* original e000, guest PC 0x0c046670 */
if(!s->budget--) { s->failed_pc=0x0c046670u; return 0; }
r[0]=0x00000000u;
goto P_0c046672;
P_0c046672: /* original 7f0c, guest PC 0x0c046672 */
if(!s->budget--) { s->failed_pc=0x0c046672u; return 0; }
r[15]+=0x0000000cu;
goto P_0c046674;
P_0c046674: /* original 4f26, guest PC 0x0c046674 */
if(!s->budget--) { s->failed_pc=0x0c046674u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046676;
P_0c046676: /* original 000b, guest PC 0x0c046676 */
if(!s->budget--) { s->failed_pc=0x0c046676u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c046678: /* original 6ef6, guest PC 0x0c046678 */
if(!s->budget--) { s->failed_pc=0x0c046678u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04667au,s,ram);
P_0c0467ba: /* original 4f22, guest PC 0x0c0467ba */
if(!s->budget--) { s->failed_pc=0x0c0467bau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0467bc;
P_0c0467bc: /* original 7ff4, guest PC 0x0c0467bc */
if(!s->budget--) { s->failed_pc=0x0c0467bcu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0467be;
P_0c0467be: /* original 2f42, guest PC 0x0c0467be */
if(!s->budget--) { s->failed_pc=0x0c0467beu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0467c0;
P_0c0467c0: /* original 1f51, guest PC 0x0c0467c0 */
if(!s->budget--) { s->failed_pc=0x0c0467c0u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0467c2;
P_0c0467c2: /* original 1f62, guest PC 0x0c0467c2 */
if(!s->budget--) { s->failed_pc=0x0c0467c2u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c0467c4;
P_0c0467c4: /* original d384, guest PC 0x0c0467c4 */
if(!s->budget--) { s->failed_pc=0x0c0467c4u; return 0; }
r[3]=read(ram,0x0c0469d8u,4);
goto P_0c0467c6;
P_0c0467c6: /* original 430b, guest PC 0x0c0467c6 */
if(!s->budget--) { s->failed_pc=0x0c0467c6u; return 0; }
target=r[3];
r[16]=0x0c0467cau;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0467cau) { target=s->pc; goto dispatch; }
goto P_0c0467ca;
P_0c0467c8: /* original 64f2, guest PC 0x0c0467c8 */
if(!s->budget--) { s->failed_pc=0x0c0467c8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0467ca;
P_0c0467ca: /* original 2008, guest PC 0x0c0467ca */
if(!s->budget--) { s->failed_pc=0x0c0467cau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0467cc;
P_0c0467cc: /* original 8903, guest PC 0x0c0467cc */
if(!s->budget--) { s->failed_pc=0x0c0467ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0467d6; }
goto P_0c0467ce;
P_0c0467ce: /* original 7f0c, guest PC 0x0c0467ce */
if(!s->budget--) { s->failed_pc=0x0c0467ceu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0467d0;
P_0c0467d0: /* original 4f26, guest PC 0x0c0467d0 */
if(!s->budget--) { s->failed_pc=0x0c0467d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0467d2;
P_0c0467d2: /* original 000b, guest PC 0x0c0467d2 */
if(!s->budget--) { s->failed_pc=0x0c0467d2u; return 0; }
target=r[16];
r[0]=0xffffffffu;
s->pc=target; return ram->oob==0;
P_0c0467d4: /* original e0ff, guest PC 0x0c0467d4 */
if(!s->budget--) { s->failed_pc=0x0c0467d4u; return 0; }
r[0]=0xffffffffu;
goto P_0c0467d6;
P_0c0467d6: /* original 64f2, guest PC 0x0c0467d6 */
if(!s->budget--) { s->failed_pc=0x0c0467d6u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0467d8;
P_0c0467d8: /* original d383, guest PC 0x0c0467d8 */
if(!s->budget--) { s->failed_pc=0x0c0467d8u; return 0; }
r[3]=read(ram,0x0c0469e8u,4);
goto P_0c0467da;
P_0c0467da: /* original 56f2, guest PC 0x0c0467da */
if(!s->budget--) { s->failed_pc=0x0c0467dau; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c0467dc;
P_0c0467dc: /* original 55f1, guest PC 0x0c0467dc */
if(!s->budget--) { s->failed_pc=0x0c0467dcu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0467de;
P_0c0467de: /* original 7f0c, guest PC 0x0c0467de */
if(!s->budget--) { s->failed_pc=0x0c0467deu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0467e0;
P_0c0467e0: /* original 432b, guest PC 0x0c0467e0 */
if(!s->budget--) { s->failed_pc=0x0c0467e0u; return 0; }
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
P_0c0467e2: /* original 4f26, guest PC 0x0c0467e2 */
if(!s->budget--) { s->failed_pc=0x0c0467e2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0467e4u,s,ram);
P_0c0467ec: /* original 4f22, guest PC 0x0c0467ec */
if(!s->budget--) { s->failed_pc=0x0c0467ecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0467ee;
P_0c0467ee: /* original 7ff0, guest PC 0x0c0467ee */
if(!s->budget--) { s->failed_pc=0x0c0467eeu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0467f0;
P_0c0467f0: /* original 2f42, guest PC 0x0c0467f0 */
if(!s->budget--) { s->failed_pc=0x0c0467f0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0467f2;
P_0c0467f2: /* original 1f51, guest PC 0x0c0467f2 */
if(!s->budget--) { s->failed_pc=0x0c0467f2u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0467f4;
P_0c0467f4: /* original 1f62, guest PC 0x0c0467f4 */
if(!s->budget--) { s->failed_pc=0x0c0467f4u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c0467f6;
P_0c0467f6: /* original 1f73, guest PC 0x0c0467f6 */
if(!s->budget--) { s->failed_pc=0x0c0467f6u; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c0467f8;
P_0c0467f8: /* original d377, guest PC 0x0c0467f8 */
if(!s->budget--) { s->failed_pc=0x0c0467f8u; return 0; }
r[3]=read(ram,0x0c0469d8u,4);
goto P_0c0467fa;
P_0c0467fa: /* original 430b, guest PC 0x0c0467fa */
if(!s->budget--) { s->failed_pc=0x0c0467fau; return 0; }
target=r[3];
r[16]=0x0c0467feu;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0467feu) { target=s->pc; goto dispatch; }
goto P_0c0467fe;
P_0c0467fc: /* original 64f2, guest PC 0x0c0467fc */
if(!s->budget--) { s->failed_pc=0x0c0467fcu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0467fe;
P_0c0467fe: /* original 2008, guest PC 0x0c0467fe */
if(!s->budget--) { s->failed_pc=0x0c0467feu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c046800;
P_0c046800: /* original 8903, guest PC 0x0c046800 */
if(!s->budget--) { s->failed_pc=0x0c046800u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04680a; }
goto P_0c046802;
P_0c046802: /* original 7f10, guest PC 0x0c046802 */
if(!s->budget--) { s->failed_pc=0x0c046802u; return 0; }
r[15]+=0x00000010u;
goto P_0c046804;
P_0c046804: /* original 4f26, guest PC 0x0c046804 */
if(!s->budget--) { s->failed_pc=0x0c046804u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046806;
P_0c046806: /* original 000b, guest PC 0x0c046806 */
if(!s->budget--) { s->failed_pc=0x0c046806u; return 0; }
target=r[16];
r[0]=0xffffffffu;
s->pc=target; return ram->oob==0;
P_0c046808: /* original e0ff, guest PC 0x0c046808 */
if(!s->budget--) { s->failed_pc=0x0c046808u; return 0; }
r[0]=0xffffffffu;
goto P_0c04680a;
P_0c04680a: /* original 64f2, guest PC 0x0c04680a */
if(!s->budget--) { s->failed_pc=0x0c04680au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c04680c;
P_0c04680c: /* original d377, guest PC 0x0c04680c */
if(!s->budget--) { s->failed_pc=0x0c04680cu; return 0; }
r[3]=read(ram,0x0c0469ecu,4);
goto P_0c04680e;
P_0c04680e: /* original 55f1, guest PC 0x0c04680e */
if(!s->budget--) { s->failed_pc=0x0c04680eu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c046810;
P_0c046810: /* original 57f3, guest PC 0x0c046810 */
if(!s->budget--) { s->failed_pc=0x0c046810u; return 0; }
r[7]=read(ram,r[15]+12,4);
goto P_0c046812;
P_0c046812: /* original 56f2, guest PC 0x0c046812 */
if(!s->budget--) { s->failed_pc=0x0c046812u; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c046814;
P_0c046814: /* original 7f10, guest PC 0x0c046814 */
if(!s->budget--) { s->failed_pc=0x0c046814u; return 0; }
r[15]+=0x00000010u;
goto P_0c046816;
P_0c046816: /* original 432b, guest PC 0x0c046816 */
if(!s->budget--) { s->failed_pc=0x0c046816u; return 0; }
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
P_0c046818: /* original 4f26, guest PC 0x0c046818 */
if(!s->budget--) { s->failed_pc=0x0c046818u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c04681au,s,ram);
P_0c046822: /* original 4f22, guest PC 0x0c046822 */
if(!s->budget--) { s->failed_pc=0x0c046822u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046824;
P_0c046824: /* original 7ff0, guest PC 0x0c046824 */
if(!s->budget--) { s->failed_pc=0x0c046824u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c046826;
P_0c046826: /* original 2f42, guest PC 0x0c046826 */
if(!s->budget--) { s->failed_pc=0x0c046826u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c046828;
P_0c046828: /* original 1f51, guest PC 0x0c046828 */
if(!s->budget--) { s->failed_pc=0x0c046828u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c04682a;
P_0c04682a: /* original 1f62, guest PC 0x0c04682a */
if(!s->budget--) { s->failed_pc=0x0c04682au; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c04682c;
P_0c04682c: /* original 1f73, guest PC 0x0c04682c */
if(!s->budget--) { s->failed_pc=0x0c04682cu; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c04682e;
P_0c04682e: /* original d36a, guest PC 0x0c04682e */
if(!s->budget--) { s->failed_pc=0x0c04682eu; return 0; }
r[3]=read(ram,0x0c0469d8u,4);
goto P_0c046830;
P_0c046830: /* original 430b, guest PC 0x0c046830 */
if(!s->budget--) { s->failed_pc=0x0c046830u; return 0; }
target=r[3];
r[16]=0x0c046834u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046834u) { target=s->pc; goto dispatch; }
goto P_0c046834;
P_0c046832: /* original 64f2, guest PC 0x0c046832 */
if(!s->budget--) { s->failed_pc=0x0c046832u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c046834;
P_0c046834: /* original 2008, guest PC 0x0c046834 */
if(!s->budget--) { s->failed_pc=0x0c046834u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c046836;
P_0c046836: /* original 8903, guest PC 0x0c046836 */
if(!s->budget--) { s->failed_pc=0x0c046836u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046840; }
goto P_0c046838;
P_0c046838: /* original 7f10, guest PC 0x0c046838 */
if(!s->budget--) { s->failed_pc=0x0c046838u; return 0; }
r[15]+=0x00000010u;
goto P_0c04683a;
P_0c04683a: /* original 4f26, guest PC 0x0c04683a */
if(!s->budget--) { s->failed_pc=0x0c04683au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04683c;
P_0c04683c: /* original 000b, guest PC 0x0c04683c */
if(!s->budget--) { s->failed_pc=0x0c04683cu; return 0; }
target=r[16];
r[0]=0xffffffffu;
s->pc=target; return ram->oob==0;
P_0c04683e: /* original e0ff, guest PC 0x0c04683e */
if(!s->budget--) { s->failed_pc=0x0c04683eu; return 0; }
r[0]=0xffffffffu;
goto P_0c046840;
P_0c046840: /* original 64f2, guest PC 0x0c046840 */
if(!s->budget--) { s->failed_pc=0x0c046840u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c046842;
P_0c046842: /* original d36b, guest PC 0x0c046842 */
if(!s->budget--) { s->failed_pc=0x0c046842u; return 0; }
r[3]=read(ram,0x0c0469f0u,4);
goto P_0c046844;
P_0c046844: /* original 55f1, guest PC 0x0c046844 */
if(!s->budget--) { s->failed_pc=0x0c046844u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c046846;
P_0c046846: /* original 57f3, guest PC 0x0c046846 */
if(!s->budget--) { s->failed_pc=0x0c046846u; return 0; }
r[7]=read(ram,r[15]+12,4);
goto P_0c046848;
P_0c046848: /* original 56f2, guest PC 0x0c046848 */
if(!s->budget--) { s->failed_pc=0x0c046848u; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c04684a;
P_0c04684a: /* original 7f10, guest PC 0x0c04684a */
if(!s->budget--) { s->failed_pc=0x0c04684au; return 0; }
r[15]+=0x00000010u;
goto P_0c04684c;
P_0c04684c: /* original 432b, guest PC 0x0c04684c */
if(!s->budget--) { s->failed_pc=0x0c04684cu; return 0; }
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
P_0c04684e: /* original 4f26, guest PC 0x0c04684e */
if(!s->budget--) { s->failed_pc=0x0c04684eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c046850u,s,ram);
P_0c046976: /* original 4f22, guest PC 0x0c046976 */
if(!s->budget--) { s->failed_pc=0x0c046976u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046978;
P_0c046978: /* original d317, guest PC 0x0c046978 */
if(!s->budget--) { s->failed_pc=0x0c046978u; return 0; }
r[3]=read(ram,0x0c0469d8u,4);
goto P_0c04697a;
P_0c04697a: /* original 430b, guest PC 0x0c04697a */
if(!s->budget--) { s->failed_pc=0x0c04697au; return 0; }
target=r[3];
r[16]=0x0c04697eu;
r[12]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04697eu) { target=s->pc; goto dispatch; }
goto P_0c04697e;
P_0c04697c: /* original 6c53, guest PC 0x0c04697c */
if(!s->budget--) { s->failed_pc=0x0c04697cu; return 0; }
r[12]=r[5];
goto P_0c04697e;
P_0c04697e: /* original 2008, guest PC 0x0c04697e */
if(!s->budget--) { s->failed_pc=0x0c04697eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c046980;
P_0c046980: /* original 8901, guest PC 0x0c046980 */
if(!s->budget--) { s->failed_pc=0x0c046980u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046986; }
goto P_0c046982;
P_0c046982: /* original a015, guest PC 0x0c046982 */
if(!s->budget--) { s->failed_pc=0x0c046982u; return 0; }
r[0]=0xffffffffu;
goto P_0c0469b0;
P_0c046984: /* original e0ff, guest PC 0x0c046984 */
if(!s->budget--) { s->failed_pc=0x0c046984u; return 0; }
r[0]=0xffffffffu;
goto P_0c046986;
P_0c046986: /* original d31c, guest PC 0x0c046986 */
if(!s->budget--) { s->failed_pc=0x0c046986u; return 0; }
r[3]=read(ram,0x0c0469f8u,4);
goto P_0c046988;
P_0c046988: /* original e507, guest PC 0x0c046988 */
if(!s->budget--) { s->failed_pc=0x0c046988u; return 0; }
r[5]=0x00000007u;
goto P_0c04698a;
P_0c04698a: /* original 430b, guest PC 0x0c04698a */
if(!s->budget--) { s->failed_pc=0x0c04698au; return 0; }
target=r[3];
r[16]=0x0c04698eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04698eu) { target=s->pc; goto dispatch; }
goto P_0c04698e;
P_0c04698c: /* original 64e3, guest PC 0x0c04698c */
if(!s->budget--) { s->failed_pc=0x0c04698cu; return 0; }
r[4]=r[14];
goto P_0c04698e;
P_0c04698e: /* original ed00, guest PC 0x0c04698e */
if(!s->budget--) { s->failed_pc=0x0c04698eu; return 0; }
r[13]=0x00000000u;
goto P_0c046990;
P_0c046990: /* original 65e3, guest PC 0x0c046990 */
if(!s->budget--) { s->failed_pc=0x0c046990u; return 0; }
r[5]=r[14];
goto P_0c046992;
P_0c046992: /* original 2fd6, guest PC 0x0c046992 */
if(!s->budget--) { s->failed_pc=0x0c046992u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046994;
P_0c046994: /* original 66c3, guest PC 0x0c046994 */
if(!s->budget--) { s->failed_pc=0x0c046994u; return 0; }
r[6]=r[12];
goto P_0c046996;
P_0c046996: /* original 2fd6, guest PC 0x0c046996 */
if(!s->budget--) { s->failed_pc=0x0c046996u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046998;
P_0c046998: /* original 67d3, guest PC 0x0c046998 */
if(!s->budget--) { s->failed_pc=0x0c046998u; return 0; }
r[7]=r[13];
goto P_0c04699a;
P_0c04699a: /* original 2fd6, guest PC 0x0c04699a */
if(!s->budget--) { s->failed_pc=0x0c04699au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04699c;
P_0c04699c: /* original d217, guest PC 0x0c04699c */
if(!s->budget--) { s->failed_pc=0x0c04699cu; return 0; }
r[2]=read(ram,0x0c0469fcu,4);
goto P_0c04699e;
P_0c04699e: /* original 420b, guest PC 0x0c04699e */
if(!s->budget--) { s->failed_pc=0x0c04699eu; return 0; }
target=r[2];
r[16]=0x0c0469a2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0469a2u) { target=s->pc; goto dispatch; }
goto P_0c0469a2;
P_0c0469a0: /* original 64e3, guest PC 0x0c0469a0 */
if(!s->budget--) { s->failed_pc=0x0c0469a0u; return 0; }
r[4]=r[14];
goto P_0c0469a2;
P_0c0469a2: /* original d317, guest PC 0x0c0469a2 */
if(!s->budget--) { s->failed_pc=0x0c0469a2u; return 0; }
r[3]=read(ram,0x0c046a00u,4);
goto P_0c0469a4;
P_0c0469a4: /* original 65c3, guest PC 0x0c0469a4 */
if(!s->budget--) { s->failed_pc=0x0c0469a4u; return 0; }
r[5]=r[12];
goto P_0c0469a6;
P_0c0469a6: /* original 7f0c, guest PC 0x0c0469a6 */
if(!s->budget--) { s->failed_pc=0x0c0469a6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0469a8;
P_0c0469a8: /* original 66c3, guest PC 0x0c0469a8 */
if(!s->budget--) { s->failed_pc=0x0c0469a8u; return 0; }
r[6]=r[12];
goto P_0c0469aa;
P_0c0469aa: /* original 430b, guest PC 0x0c0469aa */
if(!s->budget--) { s->failed_pc=0x0c0469aau; return 0; }
target=r[3];
r[16]=0x0c0469aeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0469aeu) { target=s->pc; goto dispatch; }
goto P_0c0469ae;
P_0c0469ac: /* original 64e3, guest PC 0x0c0469ac */
if(!s->budget--) { s->failed_pc=0x0c0469acu; return 0; }
r[4]=r[14];
goto P_0c0469ae;
P_0c0469ae: /* original 60d3, guest PC 0x0c0469ae */
if(!s->budget--) { s->failed_pc=0x0c0469aeu; return 0; }
r[0]=r[13];
goto P_0c0469b0;
P_0c0469b0: /* original 4f26, guest PC 0x0c0469b0 */
if(!s->budget--) { s->failed_pc=0x0c0469b0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0469b2;
P_0c0469b2: /* original 6cf6, guest PC 0x0c0469b2 */
if(!s->budget--) { s->failed_pc=0x0c0469b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0469b4;
P_0c0469b4: /* original 6df6, guest PC 0x0c0469b4 */
if(!s->budget--) { s->failed_pc=0x0c0469b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0469b6;
P_0c0469b6: /* original 000b, guest PC 0x0c0469b6 */
if(!s->budget--) { s->failed_pc=0x0c0469b6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0469b8: /* original 6ef6, guest PC 0x0c0469b8 */
if(!s->budget--) { s->failed_pc=0x0c0469b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0469bau,s,ram);
P_0c046a3a: /* original 4f22, guest PC 0x0c046a3a */
if(!s->budget--) { s->failed_pc=0x0c046a3au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046a3c;
P_0c046a3c: /* original 7ff8, guest PC 0x0c046a3c */
if(!s->budget--) { s->failed_pc=0x0c046a3cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c046a3e;
P_0c046a3e: /* original 2f61, guest PC 0x0c046a3e */
if(!s->budget--) { s->failed_pc=0x0c046a3eu; return 0; }
write(ram,r[15],r[6],2);
goto P_0c046a40;
P_0c046a40: /* original 80f4, guest PC 0x0c046a40 */
if(!s->budget--) { s->failed_pc=0x0c046a40u; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c046a42;
P_0c046a42: /* original d39b, guest PC 0x0c046a42 */
if(!s->budget--) { s->failed_pc=0x0c046a42u; return 0; }
r[3]=read(ram,0x0c046cb0u,4);
goto P_0c046a44;
P_0c046a44: /* original 430b, guest PC 0x0c046a44 */
if(!s->budget--) { s->failed_pc=0x0c046a44u; return 0; }
target=r[3];
r[16]=0x0c046a48u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046a48u) { target=s->pc; goto dispatch; }
goto P_0c046a48;
P_0c046a46: /* original 64e3, guest PC 0x0c046a46 */
if(!s->budget--) { s->failed_pc=0x0c046a46u; return 0; }
r[4]=r[14];
goto P_0c046a48;
P_0c046a48: /* original 2008, guest PC 0x0c046a48 */
if(!s->budget--) { s->failed_pc=0x0c046a48u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c046a4a;
P_0c046a4a: /* original 8901, guest PC 0x0c046a4a */
if(!s->budget--) { s->failed_pc=0x0c046a4au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046a50; }
goto P_0c046a4c;
P_0c046a4c: /* original a019, guest PC 0x0c046a4c */
if(!s->budget--) { s->failed_pc=0x0c046a4cu; return 0; }
r[0]=0xffffffffu;
goto P_0c046a82;
P_0c046a4e: /* original e0ff, guest PC 0x0c046a4e */
if(!s->budget--) { s->failed_pc=0x0c046a4eu; return 0; }
r[0]=0xffffffffu;
goto P_0c046a50;
P_0c046a50: /* original d395, guest PC 0x0c046a50 */
if(!s->budget--) { s->failed_pc=0x0c046a50u; return 0; }
r[3]=read(ram,0x0c046ca8u,4);
goto P_0c046a52;
P_0c046a52: /* original e50a, guest PC 0x0c046a52 */
if(!s->budget--) { s->failed_pc=0x0c046a52u; return 0; }
r[5]=0x0000000au;
goto P_0c046a54;
P_0c046a54: /* original 430b, guest PC 0x0c046a54 */
if(!s->budget--) { s->failed_pc=0x0c046a54u; return 0; }
target=r[3];
r[16]=0x0c046a58u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046a58u) { target=s->pc; goto dispatch; }
goto P_0c046a58;
P_0c046a56: /* original 64e3, guest PC 0x0c046a56 */
if(!s->budget--) { s->failed_pc=0x0c046a56u; return 0; }
r[4]=r[14];
goto P_0c046a58;
P_0c046a58: /* original ec00, guest PC 0x0c046a58 */
if(!s->budget--) { s->failed_pc=0x0c046a58u; return 0; }
r[12]=0x00000000u;
goto P_0c046a5a;
P_0c046a5a: /* original 65e3, guest PC 0x0c046a5a */
if(!s->budget--) { s->failed_pc=0x0c046a5au; return 0; }
r[5]=r[14];
goto P_0c046a5c;
P_0c046a5c: /* original 2fc6, guest PC 0x0c046a5c */
if(!s->budget--) { s->failed_pc=0x0c046a5cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046a5e;
P_0c046a5e: /* original 66d3, guest PC 0x0c046a5e */
if(!s->budget--) { s->failed_pc=0x0c046a5eu; return 0; }
r[6]=r[13];
goto P_0c046a60;
P_0c046a60: /* original 2fc6, guest PC 0x0c046a60 */
if(!s->budget--) { s->failed_pc=0x0c046a60u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046a62;
P_0c046a62: /* original 84fc, guest PC 0x0c046a62 */
if(!s->budget--) { s->failed_pc=0x0c046a62u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+12,1);
goto P_0c046a64;
P_0c046a64: /* original 600c, guest PC 0x0c046a64 */
if(!s->budget--) { s->failed_pc=0x0c046a64u; return 0; }
r[0]=r[0]&255u;
goto P_0c046a66;
P_0c046a66: /* original 2f06, guest PC 0x0c046a66 */
if(!s->budget--) { s->failed_pc=0x0c046a66u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046a68;
P_0c046a68: /* original 85f6, guest PC 0x0c046a68 */
if(!s->budget--) { s->failed_pc=0x0c046a68u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c046a6a;
P_0c046a6a: /* original d390, guest PC 0x0c046a6a */
if(!s->budget--) { s->failed_pc=0x0c046a6au; return 0; }
r[3]=read(ram,0x0c046cacu,4);
goto P_0c046a6c;
P_0c046a6c: /* original 6703, guest PC 0x0c046a6c */
if(!s->budget--) { s->failed_pc=0x0c046a6cu; return 0; }
r[7]=r[0];
goto P_0c046a6e;
P_0c046a6e: /* original 677d, guest PC 0x0c046a6e */
if(!s->budget--) { s->failed_pc=0x0c046a6eu; return 0; }
r[7]=r[7]&65535u;
goto P_0c046a70;
P_0c046a70: /* original 430b, guest PC 0x0c046a70 */
if(!s->budget--) { s->failed_pc=0x0c046a70u; return 0; }
target=r[3];
r[16]=0x0c046a74u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046a74u) { target=s->pc; goto dispatch; }
goto P_0c046a74;
P_0c046a72: /* original 64e3, guest PC 0x0c046a72 */
if(!s->budget--) { s->failed_pc=0x0c046a72u; return 0; }
r[4]=r[14];
goto P_0c046a74;
P_0c046a74: /* original d28f, guest PC 0x0c046a74 */
if(!s->budget--) { s->failed_pc=0x0c046a74u; return 0; }
r[2]=read(ram,0x0c046cb4u,4);
goto P_0c046a76;
P_0c046a76: /* original 65d3, guest PC 0x0c046a76 */
if(!s->budget--) { s->failed_pc=0x0c046a76u; return 0; }
r[5]=r[13];
goto P_0c046a78;
P_0c046a78: /* original 7f0c, guest PC 0x0c046a78 */
if(!s->budget--) { s->failed_pc=0x0c046a78u; return 0; }
r[15]+=0x0000000cu;
goto P_0c046a7a;
P_0c046a7a: /* original 66d3, guest PC 0x0c046a7a */
if(!s->budget--) { s->failed_pc=0x0c046a7au; return 0; }
r[6]=r[13];
goto P_0c046a7c;
P_0c046a7c: /* original 420b, guest PC 0x0c046a7c */
if(!s->budget--) { s->failed_pc=0x0c046a7cu; return 0; }
target=r[2];
r[16]=0x0c046a80u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046a80u) { target=s->pc; goto dispatch; }
goto P_0c046a80;
P_0c046a7e: /* original 64e3, guest PC 0x0c046a7e */
if(!s->budget--) { s->failed_pc=0x0c046a7eu; return 0; }
r[4]=r[14];
goto P_0c046a80;
P_0c046a80: /* original 60c3, guest PC 0x0c046a80 */
if(!s->budget--) { s->failed_pc=0x0c046a80u; return 0; }
r[0]=r[12];
goto P_0c046a82;
P_0c046a82: /* original 7f08, guest PC 0x0c046a82 */
if(!s->budget--) { s->failed_pc=0x0c046a82u; return 0; }
r[15]+=0x00000008u;
goto P_0c046a84;
P_0c046a84: /* original 4f26, guest PC 0x0c046a84 */
if(!s->budget--) { s->failed_pc=0x0c046a84u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046a86;
P_0c046a86: /* original 6cf6, guest PC 0x0c046a86 */
if(!s->budget--) { s->failed_pc=0x0c046a86u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c046a88;
P_0c046a88: /* original 6df6, guest PC 0x0c046a88 */
if(!s->budget--) { s->failed_pc=0x0c046a88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c046a8a;
P_0c046a8a: /* original 000b, guest PC 0x0c046a8a */
if(!s->budget--) { s->failed_pc=0x0c046a8au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c046a8c: /* original 6ef6, guest PC 0x0c046a8c */
if(!s->budget--) { s->failed_pc=0x0c046a8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c046a8e;
P_0c046a8e: /* original 4f22, guest PC 0x0c046a8e */
if(!s->budget--) { s->failed_pc=0x0c046a8eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046a90;
P_0c046a90: /* original 7ff8, guest PC 0x0c046a90 */
if(!s->budget--) { s->failed_pc=0x0c046a90u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c046a92;
P_0c046a92: /* original 2f42, guest PC 0x0c046a92 */
if(!s->budget--) { s->failed_pc=0x0c046a92u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c046a94;
P_0c046a94: /* original 1f51, guest PC 0x0c046a94 */
if(!s->budget--) { s->failed_pc=0x0c046a94u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c046a96;
P_0c046a96: /* original d386, guest PC 0x0c046a96 */
if(!s->budget--) { s->failed_pc=0x0c046a96u; return 0; }
r[3]=read(ram,0x0c046cb0u,4);
goto P_0c046a98;
P_0c046a98: /* original 430b, guest PC 0x0c046a98 */
if(!s->budget--) { s->failed_pc=0x0c046a98u; return 0; }
target=r[3];
r[16]=0x0c046a9cu;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046a9cu) { target=s->pc; goto dispatch; }
goto P_0c046a9c;
P_0c046a9a: /* original 64f2, guest PC 0x0c046a9a */
if(!s->budget--) { s->failed_pc=0x0c046a9au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c046a9c;
P_0c046a9c: /* original 2008, guest PC 0x0c046a9c */
if(!s->budget--) { s->failed_pc=0x0c046a9cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c046a9e;
P_0c046a9e: /* original 8903, guest PC 0x0c046a9e */
if(!s->budget--) { s->failed_pc=0x0c046a9eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046aa8; }
goto P_0c046aa0;
P_0c046aa0: /* original 7f08, guest PC 0x0c046aa0 */
if(!s->budget--) { s->failed_pc=0x0c046aa0u; return 0; }
r[15]+=0x00000008u;
goto P_0c046aa2;
P_0c046aa2: /* original 4f26, guest PC 0x0c046aa2 */
if(!s->budget--) { s->failed_pc=0x0c046aa2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046aa4;
P_0c046aa4: /* original 000b, guest PC 0x0c046aa4 */
if(!s->budget--) { s->failed_pc=0x0c046aa4u; return 0; }
target=r[16];
r[0]=0xffffffffu;
s->pc=target; return ram->oob==0;
P_0c046aa6: /* original e0ff, guest PC 0x0c046aa6 */
if(!s->budget--) { s->failed_pc=0x0c046aa6u; return 0; }
r[0]=0xffffffffu;
goto P_0c046aa8;
P_0c046aa8: /* original d383, guest PC 0x0c046aa8 */
if(!s->budget--) { s->failed_pc=0x0c046aa8u; return 0; }
r[3]=read(ram,0x0c046cb8u,4);
goto P_0c046aaa;
P_0c046aaa: /* original 64f2, guest PC 0x0c046aaa */
if(!s->budget--) { s->failed_pc=0x0c046aaau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c046aac;
P_0c046aac: /* original 55f1, guest PC 0x0c046aac */
if(!s->budget--) { s->failed_pc=0x0c046aacu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c046aae;
P_0c046aae: /* original 7f08, guest PC 0x0c046aae */
if(!s->budget--) { s->failed_pc=0x0c046aaeu; return 0; }
r[15]+=0x00000008u;
goto P_0c046ab0;
P_0c046ab0: /* original 432b, guest PC 0x0c046ab0 */
if(!s->budget--) { s->failed_pc=0x0c046ab0u; return 0; }
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
P_0c046ab2: /* original 4f26, guest PC 0x0c046ab2 */
if(!s->budget--) { s->failed_pc=0x0c046ab2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c046ab4u,s,ram);
P_0c046abc: /* original 4f22, guest PC 0x0c046abc */
if(!s->budget--) { s->failed_pc=0x0c046abcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046abe;
P_0c046abe: /* original 7ff4, guest PC 0x0c046abe */
if(!s->budget--) { s->failed_pc=0x0c046abeu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c046ac0;
P_0c046ac0: /* original 2f42, guest PC 0x0c046ac0 */
if(!s->budget--) { s->failed_pc=0x0c046ac0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c046ac2;
P_0c046ac2: /* original 1f51, guest PC 0x0c046ac2 */
if(!s->budget--) { s->failed_pc=0x0c046ac2u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c046ac4;
P_0c046ac4: /* original 1f62, guest PC 0x0c046ac4 */
if(!s->budget--) { s->failed_pc=0x0c046ac4u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c046ac6;
P_0c046ac6: /* original d37a, guest PC 0x0c046ac6 */
if(!s->budget--) { s->failed_pc=0x0c046ac6u; return 0; }
r[3]=read(ram,0x0c046cb0u,4);
goto P_0c046ac8;
P_0c046ac8: /* original 430b, guest PC 0x0c046ac8 */
if(!s->budget--) { s->failed_pc=0x0c046ac8u; return 0; }
target=r[3];
r[16]=0x0c046accu;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046accu) { target=s->pc; goto dispatch; }
goto P_0c046acc;
P_0c046aca: /* original 64f2, guest PC 0x0c046aca */
if(!s->budget--) { s->failed_pc=0x0c046acau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c046acc;
P_0c046acc: /* original 2008, guest PC 0x0c046acc */
if(!s->budget--) { s->failed_pc=0x0c046accu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c046ace;
P_0c046ace: /* original 8903, guest PC 0x0c046ace */
if(!s->budget--) { s->failed_pc=0x0c046aceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046ad8; }
goto P_0c046ad0;
P_0c046ad0: /* original 7f0c, guest PC 0x0c046ad0 */
if(!s->budget--) { s->failed_pc=0x0c046ad0u; return 0; }
r[15]+=0x0000000cu;
goto P_0c046ad2;
P_0c046ad2: /* original 4f26, guest PC 0x0c046ad2 */
if(!s->budget--) { s->failed_pc=0x0c046ad2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046ad4;
P_0c046ad4: /* original 000b, guest PC 0x0c046ad4 */
if(!s->budget--) { s->failed_pc=0x0c046ad4u; return 0; }
target=r[16];
r[0]=0xffffffffu;
s->pc=target; return ram->oob==0;
P_0c046ad6: /* original e0ff, guest PC 0x0c046ad6 */
if(!s->budget--) { s->failed_pc=0x0c046ad6u; return 0; }
r[0]=0xffffffffu;
goto P_0c046ad8;
P_0c046ad8: /* original 64f2, guest PC 0x0c046ad8 */
if(!s->budget--) { s->failed_pc=0x0c046ad8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c046ada;
P_0c046ada: /* original d378, guest PC 0x0c046ada */
if(!s->budget--) { s->failed_pc=0x0c046adau; return 0; }
r[3]=read(ram,0x0c046cbcu,4);
goto P_0c046adc;
P_0c046adc: /* original 56f2, guest PC 0x0c046adc */
if(!s->budget--) { s->failed_pc=0x0c046adcu; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c046ade;
P_0c046ade: /* original 55f1, guest PC 0x0c046ade */
if(!s->budget--) { s->failed_pc=0x0c046adeu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c046ae0;
P_0c046ae0: /* original 7f0c, guest PC 0x0c046ae0 */
if(!s->budget--) { s->failed_pc=0x0c046ae0u; return 0; }
r[15]+=0x0000000cu;
goto P_0c046ae2;
P_0c046ae2: /* original 432b, guest PC 0x0c046ae2 */
if(!s->budget--) { s->failed_pc=0x0c046ae2u; return 0; }
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
P_0c046ae4: /* original 4f26, guest PC 0x0c046ae4 */
if(!s->budget--) { s->failed_pc=0x0c046ae4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c046ae6u,s,ram);
P_0c046b34: /* original 4f22, guest PC 0x0c046b34 */
if(!s->budget--) { s->failed_pc=0x0c046b34u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046b36;
P_0c046b36: /* original 7ff8, guest PC 0x0c046b36 */
if(!s->budget--) { s->failed_pc=0x0c046b36u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c046b38;
P_0c046b38: /* original 2f52, guest PC 0x0c046b38 */
if(!s->budget--) { s->failed_pc=0x0c046b38u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c046b3a;
P_0c046b3a: /* original 1f61, guest PC 0x0c046b3a */
if(!s->budget--) { s->failed_pc=0x0c046b3au; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c046b3c;
P_0c046b3c: /* original d35c, guest PC 0x0c046b3c */
if(!s->budget--) { s->failed_pc=0x0c046b3cu; return 0; }
r[3]=read(ram,0x0c046cb0u,4);
goto P_0c046b3e;
P_0c046b3e: /* original 430b, guest PC 0x0c046b3e */
if(!s->budget--) { s->failed_pc=0x0c046b3eu; return 0; }
target=r[3];
r[16]=0x0c046b42u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046b42u) { target=s->pc; goto dispatch; }
goto P_0c046b42;
P_0c046b40: /* original 64e3, guest PC 0x0c046b40 */
if(!s->budget--) { s->failed_pc=0x0c046b40u; return 0; }
r[4]=r[14];
goto P_0c046b42;
P_0c046b42: /* original 2008, guest PC 0x0c046b42 */
if(!s->budget--) { s->failed_pc=0x0c046b42u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c046b44;
P_0c046b44: /* original 8901, guest PC 0x0c046b44 */
if(!s->budget--) { s->failed_pc=0x0c046b44u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046b4a; }
goto P_0c046b46;
P_0c046b46: /* original a015, guest PC 0x0c046b46 */
if(!s->budget--) { s->failed_pc=0x0c046b46u; return 0; }
r[0]=0xffffffffu;
goto P_0c046b74;
P_0c046b48: /* original e0ff, guest PC 0x0c046b48 */
if(!s->budget--) { s->failed_pc=0x0c046b48u; return 0; }
r[0]=0xffffffffu;
goto P_0c046b4a;
P_0c046b4a: /* original d357, guest PC 0x0c046b4a */
if(!s->budget--) { s->failed_pc=0x0c046b4au; return 0; }
r[3]=read(ram,0x0c046ca8u,4);
goto P_0c046b4c;
P_0c046b4c: /* original e508, guest PC 0x0c046b4c */
if(!s->budget--) { s->failed_pc=0x0c046b4cu; return 0; }
r[5]=0x00000008u;
goto P_0c046b4e;
P_0c046b4e: /* original 430b, guest PC 0x0c046b4e */
if(!s->budget--) { s->failed_pc=0x0c046b4eu; return 0; }
target=r[3];
r[16]=0x0c046b52u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046b52u) { target=s->pc; goto dispatch; }
goto P_0c046b52;
P_0c046b50: /* original 64e3, guest PC 0x0c046b50 */
if(!s->budget--) { s->failed_pc=0x0c046b50u; return 0; }
r[4]=r[14];
goto P_0c046b52;
P_0c046b52: /* original ed00, guest PC 0x0c046b52 */
if(!s->budget--) { s->failed_pc=0x0c046b52u; return 0; }
r[13]=0x00000000u;
goto P_0c046b54;
P_0c046b54: /* original 65e3, guest PC 0x0c046b54 */
if(!s->budget--) { s->failed_pc=0x0c046b54u; return 0; }
r[5]=r[14];
goto P_0c046b56;
P_0c046b56: /* original 2fd6, guest PC 0x0c046b56 */
if(!s->budget--) { s->failed_pc=0x0c046b56u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046b58;
P_0c046b58: /* original 2fd6, guest PC 0x0c046b58 */
if(!s->budget--) { s->failed_pc=0x0c046b58u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046b5a;
P_0c046b5a: /* original 2fd6, guest PC 0x0c046b5a */
if(!s->budget--) { s->failed_pc=0x0c046b5au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046b5c;
P_0c046b5c: /* original d353, guest PC 0x0c046b5c */
if(!s->budget--) { s->failed_pc=0x0c046b5cu; return 0; }
r[3]=read(ram,0x0c046cacu,4);
goto P_0c046b5e;
P_0c046b5e: /* original 56f3, guest PC 0x0c046b5e */
if(!s->budget--) { s->failed_pc=0x0c046b5eu; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c046b60;
P_0c046b60: /* original 57f4, guest PC 0x0c046b60 */
if(!s->budget--) { s->failed_pc=0x0c046b60u; return 0; }
r[7]=read(ram,r[15]+16,4);
goto P_0c046b62;
P_0c046b62: /* original 430b, guest PC 0x0c046b62 */
if(!s->budget--) { s->failed_pc=0x0c046b62u; return 0; }
target=r[3];
r[16]=0x0c046b66u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046b66u) { target=s->pc; goto dispatch; }
goto P_0c046b66;
P_0c046b64: /* original 64e3, guest PC 0x0c046b64 */
if(!s->budget--) { s->failed_pc=0x0c046b64u; return 0; }
r[4]=r[14];
goto P_0c046b66;
P_0c046b66: /* original 7f0c, guest PC 0x0c046b66 */
if(!s->budget--) { s->failed_pc=0x0c046b66u; return 0; }
r[15]+=0x0000000cu;
goto P_0c046b68;
P_0c046b68: /* original d352, guest PC 0x0c046b68 */
if(!s->budget--) { s->failed_pc=0x0c046b68u; return 0; }
r[3]=read(ram,0x0c046cb4u,4);
goto P_0c046b6a;
P_0c046b6a: /* original 65f2, guest PC 0x0c046b6a */
if(!s->budget--) { s->failed_pc=0x0c046b6au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c046b6c;
P_0c046b6c: /* original 56f1, guest PC 0x0c046b6c */
if(!s->budget--) { s->failed_pc=0x0c046b6cu; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c046b6e;
P_0c046b6e: /* original 430b, guest PC 0x0c046b6e */
if(!s->budget--) { s->failed_pc=0x0c046b6eu; return 0; }
target=r[3];
r[16]=0x0c046b72u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046b72u) { target=s->pc; goto dispatch; }
goto P_0c046b72;
P_0c046b70: /* original 64e3, guest PC 0x0c046b70 */
if(!s->budget--) { s->failed_pc=0x0c046b70u; return 0; }
r[4]=r[14];
goto P_0c046b72;
P_0c046b72: /* original 60d3, guest PC 0x0c046b72 */
if(!s->budget--) { s->failed_pc=0x0c046b72u; return 0; }
r[0]=r[13];
goto P_0c046b74;
P_0c046b74: /* original 7f08, guest PC 0x0c046b74 */
if(!s->budget--) { s->failed_pc=0x0c046b74u; return 0; }
r[15]+=0x00000008u;
goto P_0c046b76;
P_0c046b76: /* original 4f26, guest PC 0x0c046b76 */
if(!s->budget--) { s->failed_pc=0x0c046b76u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046b78;
P_0c046b78: /* original 6df6, guest PC 0x0c046b78 */
if(!s->budget--) { s->failed_pc=0x0c046b78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c046b7a;
P_0c046b7a: /* original 000b, guest PC 0x0c046b7a */
if(!s->budget--) { s->failed_pc=0x0c046b7au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c046b7c: /* original 6ef6, guest PC 0x0c046b7c */
if(!s->budget--) { s->failed_pc=0x0c046b7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c046b7e;
P_0c046b7e: /* original 4f22, guest PC 0x0c046b7e */
if(!s->budget--) { s->failed_pc=0x0c046b7eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046b80;
P_0c046b80: /* original 7ff8, guest PC 0x0c046b80 */
if(!s->budget--) { s->failed_pc=0x0c046b80u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c046b82;
P_0c046b82: /* original 2f42, guest PC 0x0c046b82 */
if(!s->budget--) { s->failed_pc=0x0c046b82u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c046b84;
P_0c046b84: /* original 1f51, guest PC 0x0c046b84 */
if(!s->budget--) { s->failed_pc=0x0c046b84u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c046b86;
P_0c046b86: /* original d34a, guest PC 0x0c046b86 */
if(!s->budget--) { s->failed_pc=0x0c046b86u; return 0; }
r[3]=read(ram,0x0c046cb0u,4);
goto P_0c046b88;
P_0c046b88: /* original 430b, guest PC 0x0c046b88 */
if(!s->budget--) { s->failed_pc=0x0c046b88u; return 0; }
target=r[3];
r[16]=0x0c046b8cu;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046b8cu) { target=s->pc; goto dispatch; }
goto P_0c046b8c;
P_0c046b8a: /* original 64f2, guest PC 0x0c046b8a */
if(!s->budget--) { s->failed_pc=0x0c046b8au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c046b8c;
P_0c046b8c: /* original 2008, guest PC 0x0c046b8c */
if(!s->budget--) { s->failed_pc=0x0c046b8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c046b8e;
P_0c046b8e: /* original 8903, guest PC 0x0c046b8e */
if(!s->budget--) { s->failed_pc=0x0c046b8eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046b98; }
goto P_0c046b90;
P_0c046b90: /* original 7f08, guest PC 0x0c046b90 */
if(!s->budget--) { s->failed_pc=0x0c046b90u; return 0; }
r[15]+=0x00000008u;
goto P_0c046b92;
P_0c046b92: /* original 4f26, guest PC 0x0c046b92 */
if(!s->budget--) { s->failed_pc=0x0c046b92u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046b94;
P_0c046b94: /* original 000b, guest PC 0x0c046b94 */
if(!s->budget--) { s->failed_pc=0x0c046b94u; return 0; }
target=r[16];
r[0]=0xffffffffu;
s->pc=target; return ram->oob==0;
P_0c046b96: /* original e0ff, guest PC 0x0c046b96 */
if(!s->budget--) { s->failed_pc=0x0c046b96u; return 0; }
r[0]=0xffffffffu;
goto P_0c046b98;
P_0c046b98: /* original d34a, guest PC 0x0c046b98 */
if(!s->budget--) { s->failed_pc=0x0c046b98u; return 0; }
r[3]=read(ram,0x0c046cc4u,4);
goto P_0c046b9a;
P_0c046b9a: /* original 64f2, guest PC 0x0c046b9a */
if(!s->budget--) { s->failed_pc=0x0c046b9au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c046b9c;
P_0c046b9c: /* original 55f1, guest PC 0x0c046b9c */
if(!s->budget--) { s->failed_pc=0x0c046b9cu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c046b9e;
P_0c046b9e: /* original 7f08, guest PC 0x0c046b9e */
if(!s->budget--) { s->failed_pc=0x0c046b9eu; return 0; }
r[15]+=0x00000008u;
goto P_0c046ba0;
P_0c046ba0: /* original 432b, guest PC 0x0c046ba0 */
if(!s->budget--) { s->failed_pc=0x0c046ba0u; return 0; }
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
P_0c046ba2: /* original 4f26, guest PC 0x0c046ba2 */
if(!s->budget--) { s->failed_pc=0x0c046ba2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c046ba4u,s,ram);
P_0c046bb2: /* original 4f22, guest PC 0x0c046bb2 */
if(!s->budget--) { s->failed_pc=0x0c046bb2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046bb4;
P_0c046bb4: /* original 7ffc, guest PC 0x0c046bb4 */
if(!s->budget--) { s->failed_pc=0x0c046bb4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c046bb6;
P_0c046bb6: /* original 2f52, guest PC 0x0c046bb6 */
if(!s->budget--) { s->failed_pc=0x0c046bb6u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c046bb8;
P_0c046bb8: /* original d33d, guest PC 0x0c046bb8 */
if(!s->budget--) { s->failed_pc=0x0c046bb8u; return 0; }
r[3]=read(ram,0x0c046cb0u,4);
goto P_0c046bba;
P_0c046bba: /* original 430b, guest PC 0x0c046bba */
if(!s->budget--) { s->failed_pc=0x0c046bbau; return 0; }
target=r[3];
r[16]=0x0c046bbeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046bbeu) { target=s->pc; goto dispatch; }
goto P_0c046bbe;
P_0c046bbc: /* original 64e3, guest PC 0x0c046bbc */
if(!s->budget--) { s->failed_pc=0x0c046bbcu; return 0; }
r[4]=r[14];
goto P_0c046bbe;
P_0c046bbe: /* original 2008, guest PC 0x0c046bbe */
if(!s->budget--) { s->failed_pc=0x0c046bbeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c046bc0;
P_0c046bc0: /* original 8901, guest PC 0x0c046bc0 */
if(!s->budget--) { s->failed_pc=0x0c046bc0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046bc6; }
goto P_0c046bc2;
P_0c046bc2: /* original a010, guest PC 0x0c046bc2 */
if(!s->budget--) { s->failed_pc=0x0c046bc2u; return 0; }
r[0]=0xffffffffu;
goto P_0c046be6;
P_0c046bc4: /* original e0ff, guest PC 0x0c046bc4 */
if(!s->budget--) { s->failed_pc=0x0c046bc4u; return 0; }
r[0]=0xffffffffu;
goto P_0c046bc6;
P_0c046bc6: /* original d338, guest PC 0x0c046bc6 */
if(!s->budget--) { s->failed_pc=0x0c046bc6u; return 0; }
r[3]=read(ram,0x0c046ca8u,4);
goto P_0c046bc8;
P_0c046bc8: /* original e509, guest PC 0x0c046bc8 */
if(!s->budget--) { s->failed_pc=0x0c046bc8u; return 0; }
r[5]=0x00000009u;
goto P_0c046bca;
P_0c046bca: /* original 430b, guest PC 0x0c046bca */
if(!s->budget--) { s->failed_pc=0x0c046bcau; return 0; }
target=r[3];
r[16]=0x0c046bceu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046bceu) { target=s->pc; goto dispatch; }
goto P_0c046bce;
P_0c046bcc: /* original 64e3, guest PC 0x0c046bcc */
if(!s->budget--) { s->failed_pc=0x0c046bccu; return 0; }
r[4]=r[14];
goto P_0c046bce;
P_0c046bce: /* original ed00, guest PC 0x0c046bce */
if(!s->budget--) { s->failed_pc=0x0c046bceu; return 0; }
r[13]=0x00000000u;
goto P_0c046bd0;
P_0c046bd0: /* original 65e3, guest PC 0x0c046bd0 */
if(!s->budget--) { s->failed_pc=0x0c046bd0u; return 0; }
r[5]=r[14];
goto P_0c046bd2;
P_0c046bd2: /* original 2fd6, guest PC 0x0c046bd2 */
if(!s->budget--) { s->failed_pc=0x0c046bd2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046bd4;
P_0c046bd4: /* original 67d3, guest PC 0x0c046bd4 */
if(!s->budget--) { s->failed_pc=0x0c046bd4u; return 0; }
r[7]=r[13];
goto P_0c046bd6;
P_0c046bd6: /* original 2fd6, guest PC 0x0c046bd6 */
if(!s->budget--) { s->failed_pc=0x0c046bd6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046bd8;
P_0c046bd8: /* original 2fd6, guest PC 0x0c046bd8 */
if(!s->budget--) { s->failed_pc=0x0c046bd8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046bda;
P_0c046bda: /* original d334, guest PC 0x0c046bda */
if(!s->budget--) { s->failed_pc=0x0c046bdau; return 0; }
r[3]=read(ram,0x0c046cacu,4);
goto P_0c046bdc;
P_0c046bdc: /* original 56f3, guest PC 0x0c046bdc */
if(!s->budget--) { s->failed_pc=0x0c046bdcu; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c046bde;
P_0c046bde: /* original 430b, guest PC 0x0c046bde */
if(!s->budget--) { s->failed_pc=0x0c046bdeu; return 0; }
target=r[3];
r[16]=0x0c046be2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046be2u) { target=s->pc; goto dispatch; }
goto P_0c046be2;
P_0c046be0: /* original 64e3, guest PC 0x0c046be0 */
if(!s->budget--) { s->failed_pc=0x0c046be0u; return 0; }
r[4]=r[14];
goto P_0c046be2;
P_0c046be2: /* original 60d3, guest PC 0x0c046be2 */
if(!s->budget--) { s->failed_pc=0x0c046be2u; return 0; }
r[0]=r[13];
goto P_0c046be4;
P_0c046be4: /* original 7f0c, guest PC 0x0c046be4 */
if(!s->budget--) { s->failed_pc=0x0c046be4u; return 0; }
r[15]+=0x0000000cu;
goto P_0c046be6;
P_0c046be6: /* original 7f04, guest PC 0x0c046be6 */
if(!s->budget--) { s->failed_pc=0x0c046be6u; return 0; }
r[15]+=0x00000004u;
goto P_0c046be8;
P_0c046be8: /* original 4f26, guest PC 0x0c046be8 */
if(!s->budget--) { s->failed_pc=0x0c046be8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046bea;
P_0c046bea: /* original 6df6, guest PC 0x0c046bea */
if(!s->budget--) { s->failed_pc=0x0c046beau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c046bec;
P_0c046bec: /* original 000b, guest PC 0x0c046bec */
if(!s->budget--) { s->failed_pc=0x0c046becu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c046bee: /* original 6ef6, guest PC 0x0c046bee */
if(!s->budget--) { s->failed_pc=0x0c046beeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c046bf0u,s,ram);
P_0c046bfa: /* original 4f22, guest PC 0x0c046bfa */
if(!s->budget--) { s->failed_pc=0x0c046bfau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046bfc;
P_0c046bfc: /* original 7ff8, guest PC 0x0c046bfc */
if(!s->budget--) { s->failed_pc=0x0c046bfcu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c046bfe;
P_0c046bfe: /* original 2f62, guest PC 0x0c046bfe */
if(!s->budget--) { s->failed_pc=0x0c046bfeu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c046c00;
P_0c046c00: /* original 1f71, guest PC 0x0c046c00 */
if(!s->budget--) { s->failed_pc=0x0c046c00u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c046c02;
P_0c046c02: /* original d32b, guest PC 0x0c046c02 */
if(!s->budget--) { s->failed_pc=0x0c046c02u; return 0; }
r[3]=read(ram,0x0c046cb0u,4);
goto P_0c046c04;
P_0c046c04: /* original 430b, guest PC 0x0c046c04 */
if(!s->budget--) { s->failed_pc=0x0c046c04u; return 0; }
target=r[3];
r[16]=0x0c046c08u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046c08u) { target=s->pc; goto dispatch; }
goto P_0c046c08;
P_0c046c06: /* original 64e3, guest PC 0x0c046c06 */
if(!s->budget--) { s->failed_pc=0x0c046c06u; return 0; }
r[4]=r[14];
goto P_0c046c08;
P_0c046c08: /* original 2008, guest PC 0x0c046c08 */
if(!s->budget--) { s->failed_pc=0x0c046c08u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c046c0a;
P_0c046c0a: /* original 8901, guest PC 0x0c046c0a */
if(!s->budget--) { s->failed_pc=0x0c046c0au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046c10; }
goto P_0c046c0c;
P_0c046c0c: /* original a016, guest PC 0x0c046c0c */
if(!s->budget--) { s->failed_pc=0x0c046c0cu; return 0; }
r[0]=0xffffffffu;
goto P_0c046c3c;
P_0c046c0e: /* original e0ff, guest PC 0x0c046c0e */
if(!s->budget--) { s->failed_pc=0x0c046c0eu; return 0; }
r[0]=0xffffffffu;
goto P_0c046c10;
P_0c046c10: /* original d325, guest PC 0x0c046c10 */
if(!s->budget--) { s->failed_pc=0x0c046c10u; return 0; }
r[3]=read(ram,0x0c046ca8u,4);
goto P_0c046c12;
P_0c046c12: /* original e50b, guest PC 0x0c046c12 */
if(!s->budget--) { s->failed_pc=0x0c046c12u; return 0; }
r[5]=0x0000000bu;
goto P_0c046c14;
P_0c046c14: /* original 430b, guest PC 0x0c046c14 */
if(!s->budget--) { s->failed_pc=0x0c046c14u; return 0; }
target=r[3];
r[16]=0x0c046c18u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046c18u) { target=s->pc; goto dispatch; }
goto P_0c046c18;
P_0c046c16: /* original 64e3, guest PC 0x0c046c16 */
if(!s->budget--) { s->failed_pc=0x0c046c16u; return 0; }
r[4]=r[14];
goto P_0c046c18;
P_0c046c18: /* original ec00, guest PC 0x0c046c18 */
if(!s->budget--) { s->failed_pc=0x0c046c18u; return 0; }
r[12]=0x00000000u;
goto P_0c046c1a;
P_0c046c1a: /* original 65e3, guest PC 0x0c046c1a */
if(!s->budget--) { s->failed_pc=0x0c046c1au; return 0; }
r[5]=r[14];
goto P_0c046c1c;
P_0c046c1c: /* original 2fc6, guest PC 0x0c046c1c */
if(!s->budget--) { s->failed_pc=0x0c046c1cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046c1e;
P_0c046c1e: /* original 66d3, guest PC 0x0c046c1e */
if(!s->budget--) { s->failed_pc=0x0c046c1eu; return 0; }
r[6]=r[13];
goto P_0c046c20;
P_0c046c20: /* original 2fc6, guest PC 0x0c046c20 */
if(!s->budget--) { s->failed_pc=0x0c046c20u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046c22;
P_0c046c22: /* original 52f3, guest PC 0x0c046c22 */
if(!s->budget--) { s->failed_pc=0x0c046c22u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c046c24;
P_0c046c24: /* original 2f26, guest PC 0x0c046c24 */
if(!s->budget--) { s->failed_pc=0x0c046c24u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046c26;
P_0c046c26: /* original d321, guest PC 0x0c046c26 */
if(!s->budget--) { s->failed_pc=0x0c046c26u; return 0; }
r[3]=read(ram,0x0c046cacu,4);
goto P_0c046c28;
P_0c046c28: /* original 57f3, guest PC 0x0c046c28 */
if(!s->budget--) { s->failed_pc=0x0c046c28u; return 0; }
r[7]=read(ram,r[15]+12,4);
goto P_0c046c2a;
P_0c046c2a: /* original 430b, guest PC 0x0c046c2a */
if(!s->budget--) { s->failed_pc=0x0c046c2au; return 0; }
target=r[3];
r[16]=0x0c046c2eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046c2eu) { target=s->pc; goto dispatch; }
goto P_0c046c2e;
P_0c046c2c: /* original 64e3, guest PC 0x0c046c2c */
if(!s->budget--) { s->failed_pc=0x0c046c2cu; return 0; }
r[4]=r[14];
goto P_0c046c2e;
P_0c046c2e: /* original d221, guest PC 0x0c046c2e */
if(!s->budget--) { s->failed_pc=0x0c046c2eu; return 0; }
r[2]=read(ram,0x0c046cb4u,4);
goto P_0c046c30;
P_0c046c30: /* original 65d3, guest PC 0x0c046c30 */
if(!s->budget--) { s->failed_pc=0x0c046c30u; return 0; }
r[5]=r[13];
goto P_0c046c32;
P_0c046c32: /* original 7f0c, guest PC 0x0c046c32 */
if(!s->budget--) { s->failed_pc=0x0c046c32u; return 0; }
r[15]+=0x0000000cu;
goto P_0c046c34;
P_0c046c34: /* original 66d3, guest PC 0x0c046c34 */
if(!s->budget--) { s->failed_pc=0x0c046c34u; return 0; }
r[6]=r[13];
goto P_0c046c36;
P_0c046c36: /* original 420b, guest PC 0x0c046c36 */
if(!s->budget--) { s->failed_pc=0x0c046c36u; return 0; }
target=r[2];
r[16]=0x0c046c3au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046c3au) { target=s->pc; goto dispatch; }
goto P_0c046c3a;
P_0c046c38: /* original 64e3, guest PC 0x0c046c38 */
if(!s->budget--) { s->failed_pc=0x0c046c38u; return 0; }
r[4]=r[14];
goto P_0c046c3a;
P_0c046c3a: /* original 60c3, guest PC 0x0c046c3a */
if(!s->budget--) { s->failed_pc=0x0c046c3au; return 0; }
r[0]=r[12];
goto P_0c046c3c;
P_0c046c3c: /* original 7f08, guest PC 0x0c046c3c */
if(!s->budget--) { s->failed_pc=0x0c046c3cu; return 0; }
r[15]+=0x00000008u;
goto P_0c046c3e;
P_0c046c3e: /* original 4f26, guest PC 0x0c046c3e */
if(!s->budget--) { s->failed_pc=0x0c046c3eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046c40;
P_0c046c40: /* original 6cf6, guest PC 0x0c046c40 */
if(!s->budget--) { s->failed_pc=0x0c046c40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c046c42;
P_0c046c42: /* original 6df6, guest PC 0x0c046c42 */
if(!s->budget--) { s->failed_pc=0x0c046c42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c046c44;
P_0c046c44: /* original 000b, guest PC 0x0c046c44 */
if(!s->budget--) { s->failed_pc=0x0c046c44u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c046c46: /* original 6ef6, guest PC 0x0c046c46 */
if(!s->budget--) { s->failed_pc=0x0c046c46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c046c48u,s,ram);
P_0c046c50: /* original 4f22, guest PC 0x0c046c50 */
if(!s->budget--) { s->failed_pc=0x0c046c50u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046c52;
P_0c046c52: /* original 7ff8, guest PC 0x0c046c52 */
if(!s->budget--) { s->failed_pc=0x0c046c52u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c046c54;
P_0c046c54: /* original 2f62, guest PC 0x0c046c54 */
if(!s->budget--) { s->failed_pc=0x0c046c54u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c046c56;
P_0c046c56: /* original 1f71, guest PC 0x0c046c56 */
if(!s->budget--) { s->failed_pc=0x0c046c56u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c046c58;
P_0c046c58: /* original d315, guest PC 0x0c046c58 */
if(!s->budget--) { s->failed_pc=0x0c046c58u; return 0; }
r[3]=read(ram,0x0c046cb0u,4);
goto P_0c046c5a;
P_0c046c5a: /* original 430b, guest PC 0x0c046c5a */
if(!s->budget--) { s->failed_pc=0x0c046c5au; return 0; }
target=r[3];
r[16]=0x0c046c5eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046c5eu) { target=s->pc; goto dispatch; }
goto P_0c046c5e;
P_0c046c5c: /* original 64e3, guest PC 0x0c046c5c */
if(!s->budget--) { s->failed_pc=0x0c046c5cu; return 0; }
r[4]=r[14];
goto P_0c046c5e;
P_0c046c5e: /* original 2008, guest PC 0x0c046c5e */
if(!s->budget--) { s->failed_pc=0x0c046c5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c046c60;
P_0c046c60: /* original 8901, guest PC 0x0c046c60 */
if(!s->budget--) { s->failed_pc=0x0c046c60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046c66; }
goto P_0c046c62;
P_0c046c62: /* original a01b, guest PC 0x0c046c62 */
if(!s->budget--) { s->failed_pc=0x0c046c62u; return 0; }
r[0]=0xffffffffu;
goto P_0c046c9c;
P_0c046c64: /* original e0ff, guest PC 0x0c046c64 */
if(!s->budget--) { s->failed_pc=0x0c046c64u; return 0; }
r[0]=0xffffffffu;
goto P_0c046c66;
P_0c046c66: /* original d310, guest PC 0x0c046c66 */
if(!s->budget--) { s->failed_pc=0x0c046c66u; return 0; }
r[3]=read(ram,0x0c046ca8u,4);
goto P_0c046c68;
P_0c046c68: /* original e50c, guest PC 0x0c046c68 */
if(!s->budget--) { s->failed_pc=0x0c046c68u; return 0; }
r[5]=0x0000000cu;
goto P_0c046c6a;
P_0c046c6a: /* original 430b, guest PC 0x0c046c6a */
if(!s->budget--) { s->failed_pc=0x0c046c6au; return 0; }
target=r[3];
r[16]=0x0c046c6eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046c6eu) { target=s->pc; goto dispatch; }
goto P_0c046c6e;
P_0c046c6c: /* original 64e3, guest PC 0x0c046c6c */
if(!s->budget--) { s->failed_pc=0x0c046c6cu; return 0; }
r[4]=r[14];
goto P_0c046c6e;
P_0c046c6e: /* original 52f6, guest PC 0x0c046c6e */
if(!s->budget--) { s->failed_pc=0x0c046c6eu; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c046c70;
P_0c046c70: /* original 65e3, guest PC 0x0c046c70 */
if(!s->budget--) { s->failed_pc=0x0c046c70u; return 0; }
r[5]=r[14];
goto P_0c046c72;
P_0c046c72: /* original 66d3, guest PC 0x0c046c72 */
if(!s->budget--) { s->failed_pc=0x0c046c72u; return 0; }
r[6]=r[13];
goto P_0c046c74;
P_0c046c74: /* original 2f26, guest PC 0x0c046c74 */
if(!s->budget--) { s->failed_pc=0x0c046c74u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046c76;
P_0c046c76: /* original 53f6, guest PC 0x0c046c76 */
if(!s->budget--) { s->failed_pc=0x0c046c76u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c046c78;
P_0c046c78: /* original 2f36, guest PC 0x0c046c78 */
if(!s->budget--) { s->failed_pc=0x0c046c78u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046c7a;
P_0c046c7a: /* original 52f3, guest PC 0x0c046c7a */
if(!s->budget--) { s->failed_pc=0x0c046c7au; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c046c7c;
P_0c046c7c: /* original 2f26, guest PC 0x0c046c7c */
if(!s->budget--) { s->failed_pc=0x0c046c7cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046c7e;
P_0c046c7e: /* original d30b, guest PC 0x0c046c7e */
if(!s->budget--) { s->failed_pc=0x0c046c7eu; return 0; }
r[3]=read(ram,0x0c046cacu,4);
goto P_0c046c80;
P_0c046c80: /* original 57f3, guest PC 0x0c046c80 */
if(!s->budget--) { s->failed_pc=0x0c046c80u; return 0; }
r[7]=read(ram,r[15]+12,4);
goto P_0c046c82;
P_0c046c82: /* original 430b, guest PC 0x0c046c82 */
if(!s->budget--) { s->failed_pc=0x0c046c82u; return 0; }
target=r[3];
r[16]=0x0c046c86u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046c86u) { target=s->pc; goto dispatch; }
goto P_0c046c86;
P_0c046c84: /* original 64e3, guest PC 0x0c046c84 */
if(!s->budget--) { s->failed_pc=0x0c046c84u; return 0; }
r[4]=r[14];
goto P_0c046c86;
P_0c046c86: /* original d20b, guest PC 0x0c046c86 */
if(!s->budget--) { s->failed_pc=0x0c046c86u; return 0; }
r[2]=read(ram,0x0c046cb4u,4);
goto P_0c046c88;
P_0c046c88: /* original 65d3, guest PC 0x0c046c88 */
if(!s->budget--) { s->failed_pc=0x0c046c88u; return 0; }
r[5]=r[13];
goto P_0c046c8a;
P_0c046c8a: /* original 7f0c, guest PC 0x0c046c8a */
if(!s->budget--) { s->failed_pc=0x0c046c8au; return 0; }
r[15]+=0x0000000cu;
goto P_0c046c8c;
P_0c046c8c: /* original 66d3, guest PC 0x0c046c8c */
if(!s->budget--) { s->failed_pc=0x0c046c8cu; return 0; }
r[6]=r[13];
goto P_0c046c8e;
P_0c046c8e: /* original 420b, guest PC 0x0c046c8e */
if(!s->budget--) { s->failed_pc=0x0c046c8eu; return 0; }
target=r[2];
r[16]=0x0c046c92u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046c92u) { target=s->pc; goto dispatch; }
goto P_0c046c92;
P_0c046c90: /* original 64e3, guest PC 0x0c046c90 */
if(!s->budget--) { s->failed_pc=0x0c046c90u; return 0; }
r[4]=r[14];
goto P_0c046c92;
P_0c046c92: /* original d30d, guest PC 0x0c046c92 */
if(!s->budget--) { s->failed_pc=0x0c046c92u; return 0; }
r[3]=read(ram,0x0c046cc8u,4);
goto P_0c046c94;
P_0c046c94: /* original 55f5, guest PC 0x0c046c94 */
if(!s->budget--) { s->failed_pc=0x0c046c94u; return 0; }
r[5]=read(ram,r[15]+20,4);
goto P_0c046c96;
P_0c046c96: /* original 430b, guest PC 0x0c046c96 */
if(!s->budget--) { s->failed_pc=0x0c046c96u; return 0; }
target=r[3];
r[16]=0x0c046c9au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046c9au) { target=s->pc; goto dispatch; }
goto P_0c046c9a;
P_0c046c98: /* original 64e3, guest PC 0x0c046c98 */
if(!s->budget--) { s->failed_pc=0x0c046c98u; return 0; }
r[4]=r[14];
goto P_0c046c9a;
P_0c046c9a: /* original e000, guest PC 0x0c046c9a */
if(!s->budget--) { s->failed_pc=0x0c046c9au; return 0; }
r[0]=0x00000000u;
goto P_0c046c9c;
P_0c046c9c: /* original 7f08, guest PC 0x0c046c9c */
if(!s->budget--) { s->failed_pc=0x0c046c9cu; return 0; }
r[15]+=0x00000008u;
goto P_0c046c9e;
P_0c046c9e: /* original 4f26, guest PC 0x0c046c9e */
if(!s->budget--) { s->failed_pc=0x0c046c9eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046ca0;
P_0c046ca0: /* original 6df6, guest PC 0x0c046ca0 */
if(!s->budget--) { s->failed_pc=0x0c046ca0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c046ca2;
P_0c046ca2: /* original 000b, guest PC 0x0c046ca2 */
if(!s->budget--) { s->failed_pc=0x0c046ca2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c046ca4: /* original 6ef6, guest PC 0x0c046ca4 */
if(!s->budget--) { s->failed_pc=0x0c046ca4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c046ca6u,s,ram);
P_0c046cd4: /* original 4f22, guest PC 0x0c046cd4 */
if(!s->budget--) { s->failed_pc=0x0c046cd4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046cd6;
P_0c046cd6: /* original 7ff8, guest PC 0x0c046cd6 */
if(!s->budget--) { s->failed_pc=0x0c046cd6u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c046cd8;
P_0c046cd8: /* original 2f62, guest PC 0x0c046cd8 */
if(!s->budget--) { s->failed_pc=0x0c046cd8u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c046cda;
P_0c046cda: /* original 1f71, guest PC 0x0c046cda */
if(!s->budget--) { s->failed_pc=0x0c046cdau; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c046cdc;
P_0c046cdc: /* original d355, guest PC 0x0c046cdc */
if(!s->budget--) { s->failed_pc=0x0c046cdcu; return 0; }
r[3]=read(ram,0x0c046e34u,4);
goto P_0c046cde;
P_0c046cde: /* original 430b, guest PC 0x0c046cde */
if(!s->budget--) { s->failed_pc=0x0c046cdeu; return 0; }
target=r[3];
r[16]=0x0c046ce2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046ce2u) { target=s->pc; goto dispatch; }
goto P_0c046ce2;
P_0c046ce0: /* original 64e3, guest PC 0x0c046ce0 */
if(!s->budget--) { s->failed_pc=0x0c046ce0u; return 0; }
r[4]=r[14];
goto P_0c046ce2;
P_0c046ce2: /* original 2008, guest PC 0x0c046ce2 */
if(!s->budget--) { s->failed_pc=0x0c046ce2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c046ce4;
P_0c046ce4: /* original 8901, guest PC 0x0c046ce4 */
if(!s->budget--) { s->failed_pc=0x0c046ce4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046cea; }
goto P_0c046ce6;
P_0c046ce6: /* original a01b, guest PC 0x0c046ce6 */
if(!s->budget--) { s->failed_pc=0x0c046ce6u; return 0; }
r[0]=0xffffffffu;
goto P_0c046d20;
P_0c046ce8: /* original e0ff, guest PC 0x0c046ce8 */
if(!s->budget--) { s->failed_pc=0x0c046ce8u; return 0; }
r[0]=0xffffffffu;
goto P_0c046cea;
P_0c046cea: /* original d353, guest PC 0x0c046cea */
if(!s->budget--) { s->failed_pc=0x0c046ceau; return 0; }
r[3]=read(ram,0x0c046e38u,4);
goto P_0c046cec;
P_0c046cec: /* original e50d, guest PC 0x0c046cec */
if(!s->budget--) { s->failed_pc=0x0c046cecu; return 0; }
r[5]=0x0000000du;
goto P_0c046cee;
P_0c046cee: /* original 430b, guest PC 0x0c046cee */
if(!s->budget--) { s->failed_pc=0x0c046ceeu; return 0; }
target=r[3];
r[16]=0x0c046cf2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046cf2u) { target=s->pc; goto dispatch; }
goto P_0c046cf2;
P_0c046cf0: /* original 64e3, guest PC 0x0c046cf0 */
if(!s->budget--) { s->failed_pc=0x0c046cf0u; return 0; }
r[4]=r[14];
goto P_0c046cf2;
P_0c046cf2: /* original 52f6, guest PC 0x0c046cf2 */
if(!s->budget--) { s->failed_pc=0x0c046cf2u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c046cf4;
P_0c046cf4: /* original 65e3, guest PC 0x0c046cf4 */
if(!s->budget--) { s->failed_pc=0x0c046cf4u; return 0; }
r[5]=r[14];
goto P_0c046cf6;
P_0c046cf6: /* original 66d3, guest PC 0x0c046cf6 */
if(!s->budget--) { s->failed_pc=0x0c046cf6u; return 0; }
r[6]=r[13];
goto P_0c046cf8;
P_0c046cf8: /* original 2f26, guest PC 0x0c046cf8 */
if(!s->budget--) { s->failed_pc=0x0c046cf8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046cfa;
P_0c046cfa: /* original 53f6, guest PC 0x0c046cfa */
if(!s->budget--) { s->failed_pc=0x0c046cfau; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c046cfc;
P_0c046cfc: /* original 2f36, guest PC 0x0c046cfc */
if(!s->budget--) { s->failed_pc=0x0c046cfcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046cfe;
P_0c046cfe: /* original 52f3, guest PC 0x0c046cfe */
if(!s->budget--) { s->failed_pc=0x0c046cfeu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c046d00;
P_0c046d00: /* original 2f26, guest PC 0x0c046d00 */
if(!s->budget--) { s->failed_pc=0x0c046d00u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046d02;
P_0c046d02: /* original d34e, guest PC 0x0c046d02 */
if(!s->budget--) { s->failed_pc=0x0c046d02u; return 0; }
r[3]=read(ram,0x0c046e3cu,4);
goto P_0c046d04;
P_0c046d04: /* original 57f3, guest PC 0x0c046d04 */
if(!s->budget--) { s->failed_pc=0x0c046d04u; return 0; }
r[7]=read(ram,r[15]+12,4);
goto P_0c046d06;
P_0c046d06: /* original 430b, guest PC 0x0c046d06 */
if(!s->budget--) { s->failed_pc=0x0c046d06u; return 0; }
target=r[3];
r[16]=0x0c046d0au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046d0au) { target=s->pc; goto dispatch; }
goto P_0c046d0a;
P_0c046d08: /* original 64e3, guest PC 0x0c046d08 */
if(!s->budget--) { s->failed_pc=0x0c046d08u; return 0; }
r[4]=r[14];
goto P_0c046d0a;
P_0c046d0a: /* original d24d, guest PC 0x0c046d0a */
if(!s->budget--) { s->failed_pc=0x0c046d0au; return 0; }
r[2]=read(ram,0x0c046e40u,4);
goto P_0c046d0c;
P_0c046d0c: /* original 65d3, guest PC 0x0c046d0c */
if(!s->budget--) { s->failed_pc=0x0c046d0cu; return 0; }
r[5]=r[13];
goto P_0c046d0e;
P_0c046d0e: /* original 7f0c, guest PC 0x0c046d0e */
if(!s->budget--) { s->failed_pc=0x0c046d0eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c046d10;
P_0c046d10: /* original 66d3, guest PC 0x0c046d10 */
if(!s->budget--) { s->failed_pc=0x0c046d10u; return 0; }
r[6]=r[13];
goto P_0c046d12;
P_0c046d12: /* original 420b, guest PC 0x0c046d12 */
if(!s->budget--) { s->failed_pc=0x0c046d12u; return 0; }
target=r[2];
r[16]=0x0c046d16u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046d16u) { target=s->pc; goto dispatch; }
goto P_0c046d16;
P_0c046d14: /* original 64e3, guest PC 0x0c046d14 */
if(!s->budget--) { s->failed_pc=0x0c046d14u; return 0; }
r[4]=r[14];
goto P_0c046d16;
P_0c046d16: /* original d34b, guest PC 0x0c046d16 */
if(!s->budget--) { s->failed_pc=0x0c046d16u; return 0; }
r[3]=read(ram,0x0c046e44u,4);
goto P_0c046d18;
P_0c046d18: /* original 55f5, guest PC 0x0c046d18 */
if(!s->budget--) { s->failed_pc=0x0c046d18u; return 0; }
r[5]=read(ram,r[15]+20,4);
goto P_0c046d1a;
P_0c046d1a: /* original 430b, guest PC 0x0c046d1a */
if(!s->budget--) { s->failed_pc=0x0c046d1au; return 0; }
target=r[3];
r[16]=0x0c046d1eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046d1eu) { target=s->pc; goto dispatch; }
goto P_0c046d1e;
P_0c046d1c: /* original 64e3, guest PC 0x0c046d1c */
if(!s->budget--) { s->failed_pc=0x0c046d1cu; return 0; }
r[4]=r[14];
goto P_0c046d1e;
P_0c046d1e: /* original e000, guest PC 0x0c046d1e */
if(!s->budget--) { s->failed_pc=0x0c046d1eu; return 0; }
r[0]=0x00000000u;
goto P_0c046d20;
P_0c046d20: /* original 7f08, guest PC 0x0c046d20 */
if(!s->budget--) { s->failed_pc=0x0c046d20u; return 0; }
r[15]+=0x00000008u;
goto P_0c046d22;
P_0c046d22: /* original 4f26, guest PC 0x0c046d22 */
if(!s->budget--) { s->failed_pc=0x0c046d22u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046d24;
P_0c046d24: /* original 6df6, guest PC 0x0c046d24 */
if(!s->budget--) { s->failed_pc=0x0c046d24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c046d26;
P_0c046d26: /* original 000b, guest PC 0x0c046d26 */
if(!s->budget--) { s->failed_pc=0x0c046d26u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c046d28: /* original 6ef6, guest PC 0x0c046d28 */
if(!s->budget--) { s->failed_pc=0x0c046d28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c046d2au,s,ram);
P_0c046d32: /* original 4f22, guest PC 0x0c046d32 */
if(!s->budget--) { s->failed_pc=0x0c046d32u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046d34;
P_0c046d34: /* original 7ff8, guest PC 0x0c046d34 */
if(!s->budget--) { s->failed_pc=0x0c046d34u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c046d36;
P_0c046d36: /* original 1f61, guest PC 0x0c046d36 */
if(!s->budget--) { s->failed_pc=0x0c046d36u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c046d38;
P_0c046d38: /* original 2f72, guest PC 0x0c046d38 */
if(!s->budget--) { s->failed_pc=0x0c046d38u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c046d3a;
P_0c046d3a: /* original d33e, guest PC 0x0c046d3a */
if(!s->budget--) { s->failed_pc=0x0c046d3au; return 0; }
r[3]=read(ram,0x0c046e34u,4);
goto P_0c046d3c;
P_0c046d3c: /* original 430b, guest PC 0x0c046d3c */
if(!s->budget--) { s->failed_pc=0x0c046d3cu; return 0; }
target=r[3];
r[16]=0x0c046d40u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046d40u) { target=s->pc; goto dispatch; }
goto P_0c046d40;
P_0c046d3e: /* original 64e3, guest PC 0x0c046d3e */
if(!s->budget--) { s->failed_pc=0x0c046d3eu; return 0; }
r[4]=r[14];
goto P_0c046d40;
P_0c046d40: /* original 2008, guest PC 0x0c046d40 */
if(!s->budget--) { s->failed_pc=0x0c046d40u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c046d42;
P_0c046d42: /* original 8901, guest PC 0x0c046d42 */
if(!s->budget--) { s->failed_pc=0x0c046d42u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046d48; }
goto P_0c046d44;
P_0c046d44: /* original a017, guest PC 0x0c046d44 */
if(!s->budget--) { s->failed_pc=0x0c046d44u; return 0; }
r[0]=0xffffffffu;
goto P_0c046d76;
P_0c046d46: /* original e0ff, guest PC 0x0c046d46 */
if(!s->budget--) { s->failed_pc=0x0c046d46u; return 0; }
r[0]=0xffffffffu;
goto P_0c046d48;
P_0c046d48: /* original d33b, guest PC 0x0c046d48 */
if(!s->budget--) { s->failed_pc=0x0c046d48u; return 0; }
r[3]=read(ram,0x0c046e38u,4);
goto P_0c046d4a;
P_0c046d4a: /* original e50e, guest PC 0x0c046d4a */
if(!s->budget--) { s->failed_pc=0x0c046d4au; return 0; }
r[5]=0x0000000eu;
goto P_0c046d4c;
P_0c046d4c: /* original 430b, guest PC 0x0c046d4c */
if(!s->budget--) { s->failed_pc=0x0c046d4cu; return 0; }
target=r[3];
r[16]=0x0c046d50u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046d50u) { target=s->pc; goto dispatch; }
goto P_0c046d50;
P_0c046d4e: /* original 64e3, guest PC 0x0c046d4e */
if(!s->budget--) { s->failed_pc=0x0c046d4eu; return 0; }
r[4]=r[14];
goto P_0c046d50;
P_0c046d50: /* original e200, guest PC 0x0c046d50 */
if(!s->budget--) { s->failed_pc=0x0c046d50u; return 0; }
r[2]=0x00000000u;
goto P_0c046d52;
P_0c046d52: /* original 65e3, guest PC 0x0c046d52 */
if(!s->budget--) { s->failed_pc=0x0c046d52u; return 0; }
r[5]=r[14];
goto P_0c046d54;
P_0c046d54: /* original 2f26, guest PC 0x0c046d54 */
if(!s->budget--) { s->failed_pc=0x0c046d54u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046d56;
P_0c046d56: /* original 66d3, guest PC 0x0c046d56 */
if(!s->budget--) { s->failed_pc=0x0c046d56u; return 0; }
r[6]=r[13];
goto P_0c046d58;
P_0c046d58: /* original 53f6, guest PC 0x0c046d58 */
if(!s->budget--) { s->failed_pc=0x0c046d58u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c046d5a;
P_0c046d5a: /* original 2f36, guest PC 0x0c046d5a */
if(!s->budget--) { s->failed_pc=0x0c046d5au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046d5c;
P_0c046d5c: /* original 51f2, guest PC 0x0c046d5c */
if(!s->budget--) { s->failed_pc=0x0c046d5cu; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c046d5e;
P_0c046d5e: /* original 2f16, guest PC 0x0c046d5e */
if(!s->budget--) { s->failed_pc=0x0c046d5eu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046d60;
P_0c046d60: /* original d336, guest PC 0x0c046d60 */
if(!s->budget--) { s->failed_pc=0x0c046d60u; return 0; }
r[3]=read(ram,0x0c046e3cu,4);
goto P_0c046d62;
P_0c046d62: /* original 57f4, guest PC 0x0c046d62 */
if(!s->budget--) { s->failed_pc=0x0c046d62u; return 0; }
r[7]=read(ram,r[15]+16,4);
goto P_0c046d64;
P_0c046d64: /* original 430b, guest PC 0x0c046d64 */
if(!s->budget--) { s->failed_pc=0x0c046d64u; return 0; }
target=r[3];
r[16]=0x0c046d68u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046d68u) { target=s->pc; goto dispatch; }
goto P_0c046d68;
P_0c046d66: /* original 64e3, guest PC 0x0c046d66 */
if(!s->budget--) { s->failed_pc=0x0c046d66u; return 0; }
r[4]=r[14];
goto P_0c046d68;
P_0c046d68: /* original d235, guest PC 0x0c046d68 */
if(!s->budget--) { s->failed_pc=0x0c046d68u; return 0; }
r[2]=read(ram,0x0c046e40u,4);
goto P_0c046d6a;
P_0c046d6a: /* original 65d3, guest PC 0x0c046d6a */
if(!s->budget--) { s->failed_pc=0x0c046d6au; return 0; }
r[5]=r[13];
goto P_0c046d6c;
P_0c046d6c: /* original 7f0c, guest PC 0x0c046d6c */
if(!s->budget--) { s->failed_pc=0x0c046d6cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c046d6e;
P_0c046d6e: /* original 66d3, guest PC 0x0c046d6e */
if(!s->budget--) { s->failed_pc=0x0c046d6eu; return 0; }
r[6]=r[13];
goto P_0c046d70;
P_0c046d70: /* original 420b, guest PC 0x0c046d70 */
if(!s->budget--) { s->failed_pc=0x0c046d70u; return 0; }
target=r[2];
r[16]=0x0c046d74u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046d74u) { target=s->pc; goto dispatch; }
goto P_0c046d74;
P_0c046d72: /* original 64e3, guest PC 0x0c046d72 */
if(!s->budget--) { s->failed_pc=0x0c046d72u; return 0; }
r[4]=r[14];
goto P_0c046d74;
P_0c046d74: /* original e000, guest PC 0x0c046d74 */
if(!s->budget--) { s->failed_pc=0x0c046d74u; return 0; }
r[0]=0x00000000u;
goto P_0c046d76;
P_0c046d76: /* original 7f08, guest PC 0x0c046d76 */
if(!s->budget--) { s->failed_pc=0x0c046d76u; return 0; }
r[15]+=0x00000008u;
goto P_0c046d78;
P_0c046d78: /* original 4f26, guest PC 0x0c046d78 */
if(!s->budget--) { s->failed_pc=0x0c046d78u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046d7a;
P_0c046d7a: /* original 6df6, guest PC 0x0c046d7a */
if(!s->budget--) { s->failed_pc=0x0c046d7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c046d7c;
P_0c046d7c: /* original 000b, guest PC 0x0c046d7c */
if(!s->budget--) { s->failed_pc=0x0c046d7cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c046d7e: /* original 6ef6, guest PC 0x0c046d7e */
if(!s->budget--) { s->failed_pc=0x0c046d7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c046d80u,s,ram);
P_0c046d86: /* original 4f22, guest PC 0x0c046d86 */
if(!s->budget--) { s->failed_pc=0x0c046d86u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046d88;
P_0c046d88: /* original 7ffc, guest PC 0x0c046d88 */
if(!s->budget--) { s->failed_pc=0x0c046d88u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c046d8a;
P_0c046d8a: /* original 2f52, guest PC 0x0c046d8a */
if(!s->budget--) { s->failed_pc=0x0c046d8au; return 0; }
write(ram,r[15],r[5],4);
goto P_0c046d8c;
P_0c046d8c: /* original d329, guest PC 0x0c046d8c */
if(!s->budget--) { s->failed_pc=0x0c046d8cu; return 0; }
r[3]=read(ram,0x0c046e34u,4);
goto P_0c046d8e;
P_0c046d8e: /* original 430b, guest PC 0x0c046d8e */
if(!s->budget--) { s->failed_pc=0x0c046d8eu; return 0; }
target=r[3];
r[16]=0x0c046d92u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046d92u) { target=s->pc; goto dispatch; }
goto P_0c046d92;
P_0c046d90: /* original 64e3, guest PC 0x0c046d90 */
if(!s->budget--) { s->failed_pc=0x0c046d90u; return 0; }
r[4]=r[14];
goto P_0c046d92;
P_0c046d92: /* original 2008, guest PC 0x0c046d92 */
if(!s->budget--) { s->failed_pc=0x0c046d92u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c046d94;
P_0c046d94: /* original 8901, guest PC 0x0c046d94 */
if(!s->budget--) { s->failed_pc=0x0c046d94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046d9a; }
goto P_0c046d96;
P_0c046d96: /* original a010, guest PC 0x0c046d96 */
if(!s->budget--) { s->failed_pc=0x0c046d96u; return 0; }
r[0]=0xffffffffu;
goto P_0c046dba;
P_0c046d98: /* original e0ff, guest PC 0x0c046d98 */
if(!s->budget--) { s->failed_pc=0x0c046d98u; return 0; }
r[0]=0xffffffffu;
goto P_0c046d9a;
P_0c046d9a: /* original d327, guest PC 0x0c046d9a */
if(!s->budget--) { s->failed_pc=0x0c046d9au; return 0; }
r[3]=read(ram,0x0c046e38u,4);
goto P_0c046d9c;
P_0c046d9c: /* original e50f, guest PC 0x0c046d9c */
if(!s->budget--) { s->failed_pc=0x0c046d9cu; return 0; }
r[5]=0x0000000fu;
goto P_0c046d9e;
P_0c046d9e: /* original 430b, guest PC 0x0c046d9e */
if(!s->budget--) { s->failed_pc=0x0c046d9eu; return 0; }
target=r[3];
r[16]=0x0c046da2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046da2u) { target=s->pc; goto dispatch; }
goto P_0c046da2;
P_0c046da0: /* original 64e3, guest PC 0x0c046da0 */
if(!s->budget--) { s->failed_pc=0x0c046da0u; return 0; }
r[4]=r[14];
goto P_0c046da2;
P_0c046da2: /* original ed00, guest PC 0x0c046da2 */
if(!s->budget--) { s->failed_pc=0x0c046da2u; return 0; }
r[13]=0x00000000u;
goto P_0c046da4;
P_0c046da4: /* original 65e3, guest PC 0x0c046da4 */
if(!s->budget--) { s->failed_pc=0x0c046da4u; return 0; }
r[5]=r[14];
goto P_0c046da6;
P_0c046da6: /* original 2fd6, guest PC 0x0c046da6 */
if(!s->budget--) { s->failed_pc=0x0c046da6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046da8;
P_0c046da8: /* original 67d3, guest PC 0x0c046da8 */
if(!s->budget--) { s->failed_pc=0x0c046da8u; return 0; }
r[7]=r[13];
goto P_0c046daa;
P_0c046daa: /* original 2fd6, guest PC 0x0c046daa */
if(!s->budget--) { s->failed_pc=0x0c046daau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046dac;
P_0c046dac: /* original 2fd6, guest PC 0x0c046dac */
if(!s->budget--) { s->failed_pc=0x0c046dacu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046dae;
P_0c046dae: /* original d323, guest PC 0x0c046dae */
if(!s->budget--) { s->failed_pc=0x0c046daeu; return 0; }
r[3]=read(ram,0x0c046e3cu,4);
goto P_0c046db0;
P_0c046db0: /* original 56f3, guest PC 0x0c046db0 */
if(!s->budget--) { s->failed_pc=0x0c046db0u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c046db2;
P_0c046db2: /* original 430b, guest PC 0x0c046db2 */
if(!s->budget--) { s->failed_pc=0x0c046db2u; return 0; }
target=r[3];
r[16]=0x0c046db6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046db6u) { target=s->pc; goto dispatch; }
goto P_0c046db6;
P_0c046db4: /* original 64e3, guest PC 0x0c046db4 */
if(!s->budget--) { s->failed_pc=0x0c046db4u; return 0; }
r[4]=r[14];
goto P_0c046db6;
P_0c046db6: /* original 60d3, guest PC 0x0c046db6 */
if(!s->budget--) { s->failed_pc=0x0c046db6u; return 0; }
r[0]=r[13];
goto P_0c046db8;
P_0c046db8: /* original 7f0c, guest PC 0x0c046db8 */
if(!s->budget--) { s->failed_pc=0x0c046db8u; return 0; }
r[15]+=0x0000000cu;
goto P_0c046dba;
P_0c046dba: /* original 7f04, guest PC 0x0c046dba */
if(!s->budget--) { s->failed_pc=0x0c046dbau; return 0; }
r[15]+=0x00000004u;
goto P_0c046dbc;
P_0c046dbc: /* original 4f26, guest PC 0x0c046dbc */
if(!s->budget--) { s->failed_pc=0x0c046dbcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046dbe;
P_0c046dbe: /* original 6df6, guest PC 0x0c046dbe */
if(!s->budget--) { s->failed_pc=0x0c046dbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c046dc0;
P_0c046dc0: /* original 000b, guest PC 0x0c046dc0 */
if(!s->budget--) { s->failed_pc=0x0c046dc0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c046dc2: /* original 6ef6, guest PC 0x0c046dc2 */
if(!s->budget--) { s->failed_pc=0x0c046dc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c046dc4u,s,ram);
P_0c046dca: /* original 4f22, guest PC 0x0c046dca */
if(!s->budget--) { s->failed_pc=0x0c046dcau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c046dcc;
P_0c046dcc: /* original 7ffc, guest PC 0x0c046dcc */
if(!s->budget--) { s->failed_pc=0x0c046dccu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c046dce;
P_0c046dce: /* original 2f52, guest PC 0x0c046dce */
if(!s->budget--) { s->failed_pc=0x0c046dceu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c046dd0;
P_0c046dd0: /* original d318, guest PC 0x0c046dd0 */
if(!s->budget--) { s->failed_pc=0x0c046dd0u; return 0; }
r[3]=read(ram,0x0c046e34u,4);
goto P_0c046dd2;
P_0c046dd2: /* original 430b, guest PC 0x0c046dd2 */
if(!s->budget--) { s->failed_pc=0x0c046dd2u; return 0; }
target=r[3];
r[16]=0x0c046dd6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046dd6u) { target=s->pc; goto dispatch; }
goto P_0c046dd6;
P_0c046dd4: /* original 64e3, guest PC 0x0c046dd4 */
if(!s->budget--) { s->failed_pc=0x0c046dd4u; return 0; }
r[4]=r[14];
goto P_0c046dd6;
P_0c046dd6: /* original 2008, guest PC 0x0c046dd6 */
if(!s->budget--) { s->failed_pc=0x0c046dd6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c046dd8;
P_0c046dd8: /* original 8901, guest PC 0x0c046dd8 */
if(!s->budget--) { s->failed_pc=0x0c046dd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c046dde; }
goto P_0c046dda;
P_0c046dda: /* original a010, guest PC 0x0c046dda */
if(!s->budget--) { s->failed_pc=0x0c046ddau; return 0; }
r[0]=0xffffffffu;
goto P_0c046dfe;
P_0c046ddc: /* original e0ff, guest PC 0x0c046ddc */
if(!s->budget--) { s->failed_pc=0x0c046ddcu; return 0; }
r[0]=0xffffffffu;
goto P_0c046dde;
P_0c046dde: /* original d316, guest PC 0x0c046dde */
if(!s->budget--) { s->failed_pc=0x0c046ddeu; return 0; }
r[3]=read(ram,0x0c046e38u,4);
goto P_0c046de0;
P_0c046de0: /* original e510, guest PC 0x0c046de0 */
if(!s->budget--) { s->failed_pc=0x0c046de0u; return 0; }
r[5]=0x00000010u;
goto P_0c046de2;
P_0c046de2: /* original 430b, guest PC 0x0c046de2 */
if(!s->budget--) { s->failed_pc=0x0c046de2u; return 0; }
target=r[3];
r[16]=0x0c046de6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046de6u) { target=s->pc; goto dispatch; }
goto P_0c046de6;
P_0c046de4: /* original 64e3, guest PC 0x0c046de4 */
if(!s->budget--) { s->failed_pc=0x0c046de4u; return 0; }
r[4]=r[14];
goto P_0c046de6;
P_0c046de6: /* original ed00, guest PC 0x0c046de6 */
if(!s->budget--) { s->failed_pc=0x0c046de6u; return 0; }
r[13]=0x00000000u;
goto P_0c046de8;
P_0c046de8: /* original 65e3, guest PC 0x0c046de8 */
if(!s->budget--) { s->failed_pc=0x0c046de8u; return 0; }
r[5]=r[14];
goto P_0c046dea;
P_0c046dea: /* original 2fd6, guest PC 0x0c046dea */
if(!s->budget--) { s->failed_pc=0x0c046deau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046dec;
P_0c046dec: /* original 67d3, guest PC 0x0c046dec */
if(!s->budget--) { s->failed_pc=0x0c046decu; return 0; }
r[7]=r[13];
goto P_0c046dee;
P_0c046dee: /* original 2fd6, guest PC 0x0c046dee */
if(!s->budget--) { s->failed_pc=0x0c046deeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046df0;
P_0c046df0: /* original 2fd6, guest PC 0x0c046df0 */
if(!s->budget--) { s->failed_pc=0x0c046df0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c046df2;
P_0c046df2: /* original d312, guest PC 0x0c046df2 */
if(!s->budget--) { s->failed_pc=0x0c046df2u; return 0; }
r[3]=read(ram,0x0c046e3cu,4);
goto P_0c046df4;
P_0c046df4: /* original 56f3, guest PC 0x0c046df4 */
if(!s->budget--) { s->failed_pc=0x0c046df4u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c046df6;
P_0c046df6: /* original 430b, guest PC 0x0c046df6 */
if(!s->budget--) { s->failed_pc=0x0c046df6u; return 0; }
target=r[3];
r[16]=0x0c046dfau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c046dfau) { target=s->pc; goto dispatch; }
goto P_0c046dfa;
P_0c046df8: /* original 64e3, guest PC 0x0c046df8 */
if(!s->budget--) { s->failed_pc=0x0c046df8u; return 0; }
r[4]=r[14];
goto P_0c046dfa;
P_0c046dfa: /* original 60d3, guest PC 0x0c046dfa */
if(!s->budget--) { s->failed_pc=0x0c046dfau; return 0; }
r[0]=r[13];
goto P_0c046dfc;
P_0c046dfc: /* original 7f0c, guest PC 0x0c046dfc */
if(!s->budget--) { s->failed_pc=0x0c046dfcu; return 0; }
r[15]+=0x0000000cu;
goto P_0c046dfe;
P_0c046dfe: /* original 7f04, guest PC 0x0c046dfe */
if(!s->budget--) { s->failed_pc=0x0c046dfeu; return 0; }
r[15]+=0x00000004u;
goto P_0c046e00;
P_0c046e00: /* original 4f26, guest PC 0x0c046e00 */
if(!s->budget--) { s->failed_pc=0x0c046e00u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c046e02;
P_0c046e02: /* original 6df6, guest PC 0x0c046e02 */
if(!s->budget--) { s->failed_pc=0x0c046e02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c046e04;
P_0c046e04: /* original 000b, guest PC 0x0c046e04 */
if(!s->budget--) { s->failed_pc=0x0c046e04u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c046e06: /* original 6ef6, guest PC 0x0c046e06 */
if(!s->budget--) { s->failed_pc=0x0c046e06u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c046e08u,s,ram);
P_0c04c4c0: /* original 6743, guest PC 0x0c04c4c0 */
if(!s->budget--) { s->failed_pc=0x0c04c4c0u; return 0; }
r[7]=r[4];
goto P_0c04c4c2;
P_0c04c4c2: /* original 4708, guest PC 0x0c04c4c2 */
if(!s->budget--) { s->failed_pc=0x0c04c4c2u; return 0; }
r[7]<<=2;
goto P_0c04c4c4;
P_0c04c4c4: /* original 4708, guest PC 0x0c04c4c4 */
if(!s->budget--) { s->failed_pc=0x0c04c4c4u; return 0; }
r[7]<<=2;
goto P_0c04c4c6;
P_0c04c4c6: /* original d309, guest PC 0x0c04c4c6 */
if(!s->budget--) { s->failed_pc=0x0c04c4c6u; return 0; }
r[3]=read(ram,0x0c04c4ecu,4);
goto P_0c04c4c8;
P_0c04c4c8: /* original 4708, guest PC 0x0c04c4c8 */
if(!s->budget--) { s->failed_pc=0x0c04c4c8u; return 0; }
r[7]<<=2;
goto P_0c04c4ca;
P_0c04c4ca: /* original 4700, guest PC 0x0c04c4ca */
if(!s->budget--) { s->failed_pc=0x0c04c4cau; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c04c4cc;
P_0c04c4cc: /* original e000, guest PC 0x0c04c4cc */
if(!s->budget--) { s->failed_pc=0x0c04c4ccu; return 0; }
r[0]=0x00000000u;
goto P_0c04c4ce;
P_0c04c4ce: /* original 373c, guest PC 0x0c04c4ce */
if(!s->budget--) { s->failed_pc=0x0c04c4ceu; return 0; }
r[7]+=r[3];
goto P_0c04c4d0;
P_0c04c4d0: /* original 6473, guest PC 0x0c04c4d0 */
if(!s->budget--) { s->failed_pc=0x0c04c4d0u; return 0; }
r[4]=r[7];
goto P_0c04c4d2;
P_0c04c4d2: /* original 305c, guest PC 0x0c04c4d2 */
if(!s->budget--) { s->failed_pc=0x0c04c4d2u; return 0; }
r[0]+=r[5];
goto P_0c04c4d4;
P_0c04c4d4: /* original 744c, guest PC 0x0c04c4d4 */
if(!s->budget--) { s->failed_pc=0x0c04c4d4u; return 0; }
r[4]+=0x0000004cu;
goto P_0c04c4d6;
P_0c04c4d6: /* original e600, guest PC 0x0c04c4d6 */
if(!s->budget--) { s->failed_pc=0x0c04c4d6u; return 0; }
r[6]=0x00000000u;
goto P_0c04c4d8;
P_0c04c4d8: /* original e520, guest PC 0x0c04c4d8 */
if(!s->budget--) { s->failed_pc=0x0c04c4d8u; return 0; }
r[5]=0x00000020u;
goto P_0c04c4da;
P_0c04c4da: /* original 6304, guest PC 0x0c04c4da */
if(!s->budget--) { s->failed_pc=0x0c04c4dau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[0],1);
r[0]+=1;
r[3]=tmp;
goto P_0c04c4dc;
P_0c04c4dc: /* original 7601, guest PC 0x0c04c4dc */
if(!s->budget--) { s->failed_pc=0x0c04c4dcu; return 0; }
r[6]+=0x00000001u;
goto P_0c04c4de;
P_0c04c4de: /* original 3653, guest PC 0x0c04c4de */
if(!s->budget--) { s->failed_pc=0x0c04c4deu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[5])!=0);
goto P_0c04c4e0;
P_0c04c4e0: /* original 2430, guest PC 0x0c04c4e0 */
if(!s->budget--) { s->failed_pc=0x0c04c4e0u; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04c4e2;
P_0c04c4e2: /* original 8ffa, guest PC 0x0c04c4e2 */
if(!s->budget--) { s->failed_pc=0x0c04c4e2u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c04c4da; }
goto P_0c04c4e6;
P_0c04c4e4: /* original 7401, guest PC 0x0c04c4e4 */
if(!s->budget--) { s->failed_pc=0x0c04c4e4u; return 0; }
r[4]+=0x00000001u;
goto P_0c04c4e6;
P_0c04c4e6: /* original 000b, guest PC 0x0c04c4e6 */
if(!s->budget--) { s->failed_pc=0x0c04c4e6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c04c4e8: /* original 0009, guest PC 0x0c04c4e8 */
if(!s->budget--) { s->failed_pc=0x0c04c4e8u; return 0; }
return vf3_matrix_family(0x0c04c4eau,s,ram);
P_0c04c4f0: /* original 2fe6, guest PC 0x0c04c4f0 */
if(!s->budget--) { s->failed_pc=0x0c04c4f0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c4f2;
P_0c04c4f2: /* original e70d, guest PC 0x0c04c4f2 */
if(!s->budget--) { s->failed_pc=0x0c04c4f2u; return 0; }
r[7]=0x0000000du;
goto P_0c04c4f4;
P_0c04c4f4: /* original 2fd6, guest PC 0x0c04c4f4 */
if(!s->budget--) { s->failed_pc=0x0c04c4f4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c4f6;
P_0c04c4f6: /* original 6d43, guest PC 0x0c04c4f6 */
if(!s->budget--) { s->failed_pc=0x0c04c4f6u; return 0; }
r[13]=r[4];
goto P_0c04c4f8;
P_0c04c4f8: /* original 4d08, guest PC 0x0c04c4f8 */
if(!s->budget--) { s->failed_pc=0x0c04c4f8u; return 0; }
r[13]<<=2;
goto P_0c04c4fa;
P_0c04c4fa: /* original 2fc6, guest PC 0x0c04c4fa */
if(!s->budget--) { s->failed_pc=0x0c04c4fau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c4fc;
P_0c04c4fc: /* original 4d08, guest PC 0x0c04c4fc */
if(!s->budget--) { s->failed_pc=0x0c04c4fcu; return 0; }
r[13]<<=2;
goto P_0c04c4fe;
P_0c04c4fe: /* original 2fb6, guest PC 0x0c04c4fe */
if(!s->budget--) { s->failed_pc=0x0c04c4feu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c500;
P_0c04c500: /* original d325, guest PC 0x0c04c500 */
if(!s->budget--) { s->failed_pc=0x0c04c500u; return 0; }
r[3]=read(ram,0x0c04c598u,4);
goto P_0c04c502;
P_0c04c502: /* original 4d08, guest PC 0x0c04c502 */
if(!s->budget--) { s->failed_pc=0x0c04c502u; return 0; }
r[13]<<=2;
goto P_0c04c504;
P_0c04c504: /* original 4d00, guest PC 0x0c04c504 */
if(!s->budget--) { s->failed_pc=0x0c04c504u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c04c506;
P_0c04c506: /* original 3d3c, guest PC 0x0c04c506 */
if(!s->budget--) { s->failed_pc=0x0c04c506u; return 0; }
r[13]+=r[3];
goto P_0c04c508;
P_0c04c508: /* original e400, guest PC 0x0c04c508 */
if(!s->budget--) { s->failed_pc=0x0c04c508u; return 0; }
r[4]=0x00000000u;
goto P_0c04c50a;
P_0c04c50a: /* original 6ed3, guest PC 0x0c04c50a */
if(!s->budget--) { s->failed_pc=0x0c04c50au; return 0; }
r[14]=r[13];
goto P_0c04c50c;
P_0c04c50c: /* original 7e2c, guest PC 0x0c04c50c */
if(!s->budget--) { s->failed_pc=0x0c04c50cu; return 0; }
r[14]+=0x0000002cu;
goto P_0c04c50e;
P_0c04c50e: /* original 6c43, guest PC 0x0c04c50e */
if(!s->budget--) { s->failed_pc=0x0c04c50eu; return 0; }
r[12]=r[4];
goto P_0c04c510;
P_0c04c510: /* original 7ffc, guest PC 0x0c04c510 */
if(!s->budget--) { s->failed_pc=0x0c04c510u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04c512;
P_0c04c512: /* original 7c01, guest PC 0x0c04c512 */
if(!s->budget--) { s->failed_pc=0x0c04c512u; return 0; }
r[12]+=0x00000001u;
goto P_0c04c514;
P_0c04c514: /* original 2e40, guest PC 0x0c04c514 */
if(!s->budget--) { s->failed_pc=0x0c04c514u; return 0; }
write(ram,r[14],r[4],1);
goto P_0c04c516;
P_0c04c516: /* original 3c73, guest PC 0x0c04c516 */
if(!s->budget--) { s->failed_pc=0x0c04c516u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[7])!=0);
goto P_0c04c518;
P_0c04c518: /* original 8ffb, guest PC 0x0c04c518 */
if(!s->budget--) { s->failed_pc=0x0c04c518u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000001u;
if(!cond) { goto P_0c04c512; }
goto P_0c04c51c;
P_0c04c51a: /* original 7e01, guest PC 0x0c04c51a */
if(!s->budget--) { s->failed_pc=0x0c04c51au; return 0; }
r[14]+=0x00000001u;
goto P_0c04c51c;
P_0c04c51c: /* original 6ed3, guest PC 0x0c04c51c */
if(!s->budget--) { s->failed_pc=0x0c04c51cu; return 0; }
r[14]=r[13];
goto P_0c04c51e;
P_0c04c51e: /* original 7e3c, guest PC 0x0c04c51e */
if(!s->budget--) { s->failed_pc=0x0c04c51eu; return 0; }
r[14]+=0x0000003cu;
goto P_0c04c520;
P_0c04c520: /* original 6c43, guest PC 0x0c04c520 */
if(!s->budget--) { s->failed_pc=0x0c04c520u; return 0; }
r[12]=r[4];
goto P_0c04c522;
P_0c04c522: /* original 7c01, guest PC 0x0c04c522 */
if(!s->budget--) { s->failed_pc=0x0c04c522u; return 0; }
r[12]+=0x00000001u;
goto P_0c04c524;
P_0c04c524: /* original 2e40, guest PC 0x0c04c524 */
if(!s->budget--) { s->failed_pc=0x0c04c524u; return 0; }
write(ram,r[14],r[4],1);
goto P_0c04c526;
P_0c04c526: /* original 3c73, guest PC 0x0c04c526 */
if(!s->budget--) { s->failed_pc=0x0c04c526u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[7])!=0);
goto P_0c04c528;
P_0c04c528: /* original 8ffb, guest PC 0x0c04c528 */
if(!s->budget--) { s->failed_pc=0x0c04c528u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000001u;
if(!cond) { goto P_0c04c522; }
goto P_0c04c52c;
P_0c04c52a: /* original 7e01, guest PC 0x0c04c52a */
if(!s->budget--) { s->failed_pc=0x0c04c52au; return 0; }
r[14]+=0x00000001u;
goto P_0c04c52c;
P_0c04c52c: /* original eb00, guest PC 0x0c04c52c */
if(!s->budget--) { s->failed_pc=0x0c04c52cu; return 0; }
r[11]=0x00000000u;
goto P_0c04c52e;
P_0c04c52e: /* original 67d3, guest PC 0x0c04c52e */
if(!s->budget--) { s->failed_pc=0x0c04c52eu; return 0; }
r[7]=r[13];
goto P_0c04c530;
P_0c04c530: /* original 3b5c, guest PC 0x0c04c530 */
if(!s->budget--) { s->failed_pc=0x0c04c530u; return 0; }
r[11]+=r[5];
goto P_0c04c532;
P_0c04c532: /* original 6c43, guest PC 0x0c04c532 */
if(!s->budget--) { s->failed_pc=0x0c04c532u; return 0; }
r[12]=r[4];
goto P_0c04c534;
P_0c04c534: /* original e50c, guest PC 0x0c04c534 */
if(!s->budget--) { s->failed_pc=0x0c04c534u; return 0; }
r[5]=0x0000000cu;
goto P_0c04c536;
P_0c04c536: /* original 6eb3, guest PC 0x0c04c536 */
if(!s->budget--) { s->failed_pc=0x0c04c536u; return 0; }
r[14]=r[11];
goto P_0c04c538;
P_0c04c538: /* original 772c, guest PC 0x0c04c538 */
if(!s->budget--) { s->failed_pc=0x0c04c538u; return 0; }
r[7]+=0x0000002cu;
goto P_0c04c53a;
P_0c04c53a: /* original 2fb2, guest PC 0x0c04c53a */
if(!s->budget--) { s->failed_pc=0x0c04c53au; return 0; }
write(ram,r[15],r[11],4);
goto P_0c04c53c;
P_0c04c53c: /* original 63e0, guest PC 0x0c04c53c */
if(!s->budget--) { s->failed_pc=0x0c04c53cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[3]=tmp;
goto P_0c04c53e;
P_0c04c53e: /* original 2338, guest PC 0x0c04c53e */
if(!s->budget--) { s->failed_pc=0x0c04c53eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04c540;
P_0c04c540: /* original 8906, guest PC 0x0c04c540 */
if(!s->budget--) { s->failed_pc=0x0c04c540u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c550; }
goto P_0c04c542;
P_0c04c542: /* original 63b4, guest PC 0x0c04c542 */
if(!s->budget--) { s->failed_pc=0x0c04c542u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[11]+=1;
r[3]=tmp;
goto P_0c04c544;
P_0c04c544: /* original 7c01, guest PC 0x0c04c544 */
if(!s->budget--) { s->failed_pc=0x0c04c544u; return 0; }
r[12]+=0x00000001u;
goto P_0c04c546;
P_0c04c546: /* original 3c53, guest PC 0x0c04c546 */
if(!s->budget--) { s->failed_pc=0x0c04c546u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[5])!=0);
goto P_0c04c548;
P_0c04c548: /* original 2730, guest PC 0x0c04c548 */
if(!s->budget--) { s->failed_pc=0x0c04c548u; return 0; }
write(ram,r[7],r[3],1);
goto P_0c04c54a;
P_0c04c54a: /* original 7701, guest PC 0x0c04c54a */
if(!s->budget--) { s->failed_pc=0x0c04c54au; return 0; }
r[7]+=0x00000001u;
goto P_0c04c54c;
P_0c04c54c: /* original 8ff6, guest PC 0x0c04c54c */
if(!s->budget--) { s->failed_pc=0x0c04c54cu; return 0; }
cond=r[17]&1u;
r[14]+=0x00000001u;
if(!cond) { goto P_0c04c53c; }
goto P_0c04c550;
P_0c04c54e: /* original 7e01, guest PC 0x0c04c54e */
if(!s->budget--) { s->failed_pc=0x0c04c54eu; return 0; }
r[14]+=0x00000001u;
goto P_0c04c550;
P_0c04c550: /* original 6743, guest PC 0x0c04c550 */
if(!s->budget--) { s->failed_pc=0x0c04c550u; return 0; }
r[7]=r[4];
goto P_0c04c552;
P_0c04c552: /* original e400, guest PC 0x0c04c552 */
if(!s->budget--) { s->failed_pc=0x0c04c552u; return 0; }
r[4]=0x00000000u;
goto P_0c04c554;
P_0c04c554: /* original 346c, guest PC 0x0c04c554 */
if(!s->budget--) { s->failed_pc=0x0c04c554u; return 0; }
r[4]+=r[6];
goto P_0c04c556;
P_0c04c556: /* original 66d3, guest PC 0x0c04c556 */
if(!s->budget--) { s->failed_pc=0x0c04c556u; return 0; }
r[6]=r[13];
goto P_0c04c558;
P_0c04c558: /* original 763c, guest PC 0x0c04c558 */
if(!s->budget--) { s->failed_pc=0x0c04c558u; return 0; }
r[6]+=0x0000003cu;
goto P_0c04c55a;
P_0c04c55a: /* original 6e43, guest PC 0x0c04c55a */
if(!s->budget--) { s->failed_pc=0x0c04c55au; return 0; }
r[14]=r[4];
goto P_0c04c55c;
P_0c04c55c: /* original 6340, guest PC 0x0c04c55c */
if(!s->budget--) { s->failed_pc=0x0c04c55cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c04c55e;
P_0c04c55e: /* original 2338, guest PC 0x0c04c55e */
if(!s->budget--) { s->failed_pc=0x0c04c55eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04c560;
P_0c04c560: /* original 8906, guest PC 0x0c04c560 */
if(!s->budget--) { s->failed_pc=0x0c04c560u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c570; }
goto P_0c04c562;
P_0c04c562: /* original 63e4, guest PC 0x0c04c562 */
if(!s->budget--) { s->failed_pc=0x0c04c562u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]+=1;
r[3]=tmp;
goto P_0c04c564;
P_0c04c564: /* original 7701, guest PC 0x0c04c564 */
if(!s->budget--) { s->failed_pc=0x0c04c564u; return 0; }
r[7]+=0x00000001u;
goto P_0c04c566;
P_0c04c566: /* original 3753, guest PC 0x0c04c566 */
if(!s->budget--) { s->failed_pc=0x0c04c566u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[5])!=0);
goto P_0c04c568;
P_0c04c568: /* original 2630, guest PC 0x0c04c568 */
if(!s->budget--) { s->failed_pc=0x0c04c568u; return 0; }
write(ram,r[6],r[3],1);
goto P_0c04c56a;
P_0c04c56a: /* original 7601, guest PC 0x0c04c56a */
if(!s->budget--) { s->failed_pc=0x0c04c56au; return 0; }
r[6]+=0x00000001u;
goto P_0c04c56c;
P_0c04c56c: /* original 8ff6, guest PC 0x0c04c56c */
if(!s->budget--) { s->failed_pc=0x0c04c56cu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c04c55c; }
goto P_0c04c570;
P_0c04c56e: /* original 7401, guest PC 0x0c04c56e */
if(!s->budget--) { s->failed_pc=0x0c04c56eu; return 0; }
r[4]+=0x00000001u;
goto P_0c04c570;
P_0c04c570: /* original 7f04, guest PC 0x0c04c570 */
if(!s->budget--) { s->failed_pc=0x0c04c570u; return 0; }
r[15]+=0x00000004u;
goto P_0c04c572;
P_0c04c572: /* original 6bf6, guest PC 0x0c04c572 */
if(!s->budget--) { s->failed_pc=0x0c04c572u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04c574;
P_0c04c574: /* original 6cf6, guest PC 0x0c04c574 */
if(!s->budget--) { s->failed_pc=0x0c04c574u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04c576;
P_0c04c576: /* original 6df6, guest PC 0x0c04c576 */
if(!s->budget--) { s->failed_pc=0x0c04c576u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04c578;
P_0c04c578: /* original 000b, guest PC 0x0c04c578 */
if(!s->budget--) { s->failed_pc=0x0c04c578u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04c57a: /* original 6ef6, guest PC 0x0c04c57a */
if(!s->budget--) { s->failed_pc=0x0c04c57au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04c57c;
P_0c04c57c: /* original 4408, guest PC 0x0c04c57c */
if(!s->budget--) { s->failed_pc=0x0c04c57cu; return 0; }
r[4]<<=2;
goto P_0c04c57e;
P_0c04c57e: /* original d306, guest PC 0x0c04c57e */
if(!s->budget--) { s->failed_pc=0x0c04c57eu; return 0; }
r[3]=read(ram,0x0c04c598u,4);
goto P_0c04c580;
P_0c04c580: /* original 4408, guest PC 0x0c04c580 */
if(!s->budget--) { s->failed_pc=0x0c04c580u; return 0; }
r[4]<<=2;
goto P_0c04c582;
P_0c04c582: /* original 4408, guest PC 0x0c04c582 */
if(!s->budget--) { s->failed_pc=0x0c04c582u; return 0; }
r[4]<<=2;
goto P_0c04c584;
P_0c04c584: /* original 4400, guest PC 0x0c04c584 */
if(!s->budget--) { s->failed_pc=0x0c04c584u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c04c586;
P_0c04c586: /* original 343c, guest PC 0x0c04c586 */
if(!s->budget--) { s->failed_pc=0x0c04c586u; return 0; }
r[4]+=r[3];
goto P_0c04c588;
P_0c04c588: /* original 7ffc, guest PC 0x0c04c588 */
if(!s->budget--) { s->failed_pc=0x0c04c588u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04c58a;
P_0c04c58a: /* original 2f42, guest PC 0x0c04c58a */
if(!s->budget--) { s->failed_pc=0x0c04c58au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c04c58c;
P_0c04c58c: /* original 746c, guest PC 0x0c04c58c */
if(!s->budget--) { s->failed_pc=0x0c04c58cu; return 0; }
r[4]+=0x0000006cu;
goto P_0c04c58e;
P_0c04c58e: /* original d203, guest PC 0x0c04c58e */
if(!s->budget--) { s->failed_pc=0x0c04c58eu; return 0; }
r[2]=read(ram,0x0c04c59cu,4);
goto P_0c04c590;
P_0c04c590: /* original e608, guest PC 0x0c04c590 */
if(!s->budget--) { s->failed_pc=0x0c04c590u; return 0; }
r[6]=0x00000008u;
goto P_0c04c592;
P_0c04c592: /* original 422b, guest PC 0x0c04c592 */
if(!s->budget--) { s->failed_pc=0x0c04c592u; return 0; }
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
P_0c04c594: /* original 7f04, guest PC 0x0c04c594 */
if(!s->budget--) { s->failed_pc=0x0c04c594u; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c04c596u,s,ram);
P_0c04cf0e: /* original 2fe6, guest PC 0x0c04cf0e */
if(!s->budget--) { s->failed_pc=0x0c04cf0eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cf10;
P_0c04cf10: /* original 6e63, guest PC 0x0c04cf10 */
if(!s->budget--) { s->failed_pc=0x0c04cf10u; return 0; }
r[14]=r[6];
goto P_0c04cf12;
P_0c04cf12: /* original 2fd6, guest PC 0x0c04cf12 */
if(!s->budget--) { s->failed_pc=0x0c04cf12u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cf14;
P_0c04cf14: /* original 6d43, guest PC 0x0c04cf14 */
if(!s->budget--) { s->failed_pc=0x0c04cf14u; return 0; }
r[13]=r[4];
goto P_0c04cf16;
P_0c04cf16: /* original 4f22, guest PC 0x0c04cf16 */
if(!s->budget--) { s->failed_pc=0x0c04cf16u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04cf18;
P_0c04cf18: /* original 4f12, guest PC 0x0c04cf18 */
if(!s->budget--) { s->failed_pc=0x0c04cf18u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04cf1a;
P_0c04cf1a: /* original 7fc8, guest PC 0x0c04cf1a */
if(!s->budget--) { s->failed_pc=0x0c04cf1au; return 0; }
r[15]+=0xffffffc8u;
goto P_0c04cf1c;
P_0c04cf1c: /* original 1f51, guest PC 0x0c04cf1c */
if(!s->budget--) { s->failed_pc=0x0c04cf1cu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c04cf1e;
P_0c04cf1e: /* original 931b, guest PC 0x0c04cf1e */
if(!s->budget--) { s->failed_pc=0x0c04cf1eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04cf58u,2);
goto P_0c04cf20;
P_0c04cf20: /* original 2d3f, guest PC 0x0c04cf20 */
if(!s->budget--) { s->failed_pc=0x0c04cf20u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[3]);
goto P_0c04cf22;
P_0c04cf22: /* original 031a, guest PC 0x0c04cf22 */
if(!s->budget--) { s->failed_pc=0x0c04cf22u; return 0; }
r[3]=r[19];
goto P_0c04cf24;
P_0c04cf24: /* original 633f, guest PC 0x0c04cf24 */
if(!s->budget--) { s->failed_pc=0x0c04cf24u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04cf26;
P_0c04cf26: /* original 1f32, guest PC 0x0c04cf26 */
if(!s->budget--) { s->failed_pc=0x0c04cf26u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c04cf28;
P_0c04cf28: /* original d20c, guest PC 0x0c04cf28 */
if(!s->budget--) { s->failed_pc=0x0c04cf28u; return 0; }
r[2]=read(ram,0x0c04cf5cu,4);
goto P_0c04cf2a;
P_0c04cf2a: /* original 332c, guest PC 0x0c04cf2a */
if(!s->budget--) { s->failed_pc=0x0c04cf2au; return 0; }
r[3]+=r[2];
goto P_0c04cf2c;
P_0c04cf2c: /* original 2f32, guest PC 0x0c04cf2c */
if(!s->budget--) { s->failed_pc=0x0c04cf2cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c04cf2e;
P_0c04cf2e: /* original 2fe6, guest PC 0x0c04cf2e */
if(!s->budget--) { s->failed_pc=0x0c04cf2eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cf30;
P_0c04cf30: /* original 51f2, guest PC 0x0c04cf30 */
if(!s->budget--) { s->failed_pc=0x0c04cf30u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c04cf32;
P_0c04cf32: /* original 2f16, guest PC 0x0c04cf32 */
if(!s->budget--) { s->failed_pc=0x0c04cf32u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cf34;
P_0c04cf34: /* original 2fd6, guest PC 0x0c04cf34 */
if(!s->budget--) { s->failed_pc=0x0c04cf34u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cf36;
P_0c04cf36: /* original d110, guest PC 0x0c04cf36 */
if(!s->budget--) { s->failed_pc=0x0c04cf36u; return 0; }
r[1]=read(ram,0x0c04cf78u,4);
goto P_0c04cf38;
P_0c04cf38: /* original bb32, guest PC 0x0c04cf38 */
if(!s->budget--) { s->failed_pc=0x0c04cf38u; return 0; }
target=0x0c04c5a0u; r[16]=0x0c04cf3cu;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04cf3cu) { target=s->pc; goto dispatch; }
goto P_0c04cf3c;
P_0c04cf3a: /* original 2f16, guest PC 0x0c04cf3a */
if(!s->budget--) { s->failed_pc=0x0c04cf3au; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04cf3c;
P_0c04cf3c: /* original 7f10, guest PC 0x0c04cf3c */
if(!s->budget--) { s->failed_pc=0x0c04cf3cu; return 0; }
r[15]+=0x00000010u;
goto P_0c04cf3e;
P_0c04cf3e: /* original 62f2, guest PC 0x0c04cf3e */
if(!s->budget--) { s->failed_pc=0x0c04cf3eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04cf40;
P_0c04cf40: /* original 8422, guest PC 0x0c04cf40 */
if(!s->budget--) { s->failed_pc=0x0c04cf40u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+2,1);
goto P_0c04cf42;
P_0c04cf42: /* original 2008, guest PC 0x0c04cf42 */
if(!s->budget--) { s->failed_pc=0x0c04cf42u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04cf44;
P_0c04cf44: /* original 8927, guest PC 0x0c04cf44 */
if(!s->budget--) { s->failed_pc=0x0c04cf44u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04cf96; }
goto P_0c04cf46;
P_0c04cf46: /* original d20d, guest PC 0x0c04cf46 */
if(!s->budget--) { s->failed_pc=0x0c04cf46u; return 0; }
r[2]=read(ram,0x0c04cf7cu,4);
goto P_0c04cf48;
P_0c04cf48: /* original 420b, guest PC 0x0c04cf48 */
if(!s->budget--) { s->failed_pc=0x0c04cf48u; return 0; }
target=r[2];
r[16]=0x0c04cf4cu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04cf4cu) { target=s->pc; goto dispatch; }
goto P_0c04cf4c;
P_0c04cf4a: /* original 64d3, guest PC 0x0c04cf4a */
if(!s->budget--) { s->failed_pc=0x0c04cf4au; return 0; }
r[4]=r[13];
goto P_0c04cf4c;
P_0c04cf4c: /* original 2008, guest PC 0x0c04cf4c */
if(!s->budget--) { s->failed_pc=0x0c04cf4cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04cf4e;
P_0c04cf4e: /* original 8b17, guest PC 0x0c04cf4e */
if(!s->budget--) { s->failed_pc=0x0c04cf4eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04cf80; }
goto P_0c04cf50;
P_0c04cf50: /* original bfbd, guest PC 0x0c04cf50 */
if(!s->budget--) { s->failed_pc=0x0c04cf50u; return 0; }
target=0x0c04ceceu; r[16]=0x0c04cf54u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04cf54u) { target=s->pc; goto dispatch; }
goto P_0c04cf54;
P_0c04cf52: /* original 64d3, guest PC 0x0c04cf52 */
if(!s->budget--) { s->failed_pc=0x0c04cf52u; return 0; }
r[4]=r[13];
goto P_0c04cf54;
P_0c04cf54: /* original a01f, guest PC 0x0c04cf54 */
if(!s->budget--) { s->failed_pc=0x0c04cf54u; return 0; }
goto P_0c04cf96;
P_0c04cf56: /* original 0009, guest PC 0x0c04cf56 */
if(!s->budget--) { s->failed_pc=0x0c04cf56u; return 0; }
return vf3_matrix_family(0x0c04cf58u,s,ram);
P_0c04cf80: /* original d33f, guest PC 0x0c04cf80 */
if(!s->budget--) { s->failed_pc=0x0c04cf80u; return 0; }
r[3]=read(ram,0x0c04d080u,4);
goto P_0c04cf82;
P_0c04cf82: /* original 430b, guest PC 0x0c04cf82 */
if(!s->budget--) { s->failed_pc=0x0c04cf82u; return 0; }
target=r[3];
r[16]=0x0c04cf86u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04cf86u) { target=s->pc; goto dispatch; }
goto P_0c04cf86;
P_0c04cf84: /* original 64d3, guest PC 0x0c04cf84 */
if(!s->budget--) { s->failed_pc=0x0c04cf84u; return 0; }
r[4]=r[13];
goto P_0c04cf86;
P_0c04cf86: /* original 2008, guest PC 0x0c04cf86 */
if(!s->budget--) { s->failed_pc=0x0c04cf86u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04cf88;
P_0c04cf88: /* original 8905, guest PC 0x0c04cf88 */
if(!s->budget--) { s->failed_pc=0x0c04cf88u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04cf96; }
goto P_0c04cf8a;
P_0c04cf8a: /* original 52f2, guest PC 0x0c04cf8a */
if(!s->budget--) { s->failed_pc=0x0c04cf8au; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c04cf8c;
P_0c04cf8c: /* original d33d, guest PC 0x0c04cf8c */
if(!s->budget--) { s->failed_pc=0x0c04cf8cu; return 0; }
r[3]=read(ram,0x0c04d084u,4);
goto P_0c04cf8e;
P_0c04cf8e: /* original 323c, guest PC 0x0c04cf8e */
if(!s->budget--) { s->failed_pc=0x0c04cf8eu; return 0; }
r[2]+=r[3];
goto P_0c04cf90;
P_0c04cf90: /* original 8428, guest PC 0x0c04cf90 */
if(!s->budget--) { s->failed_pc=0x0c04cf90u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04cf92;
P_0c04cf92: /* original 2008, guest PC 0x0c04cf92 */
if(!s->budget--) { s->failed_pc=0x0c04cf92u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04cf94;
P_0c04cf94: /* original 8b02, guest PC 0x0c04cf94 */
if(!s->budget--) { s->failed_pc=0x0c04cf94u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04cf9c; }
goto P_0c04cf96;
P_0c04cf96: /* original 906d, guest PC 0x0c04cf96 */
if(!s->budget--) { s->failed_pc=0x0c04cf96u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d074u,2);
goto P_0c04cf98;
P_0c04cf98: /* original a034, guest PC 0x0c04cf98 */
if(!s->budget--) { s->failed_pc=0x0c04cf98u; return 0; }
goto P_0c04d004;
P_0c04cf9a: /* original 0009, guest PC 0x0c04cf9a */
if(!s->budget--) { s->failed_pc=0x0c04cf9au; return 0; }
goto P_0c04cf9c;
P_0c04cf9c: /* original d33a, guest PC 0x0c04cf9c */
if(!s->budget--) { s->failed_pc=0x0c04cf9cu; return 0; }
r[3]=read(ram,0x0c04d088u,4);
goto P_0c04cf9e;
P_0c04cf9e: /* original 430b, guest PC 0x0c04cf9e */
if(!s->budget--) { s->failed_pc=0x0c04cf9eu; return 0; }
target=r[3];
r[16]=0x0c04cfa2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04cfa2u) { target=s->pc; goto dispatch; }
goto P_0c04cfa2;
P_0c04cfa0: /* original 64d3, guest PC 0x0c04cfa0 */
if(!s->budget--) { s->failed_pc=0x0c04cfa0u; return 0; }
r[4]=r[13];
goto P_0c04cfa2;
P_0c04cfa2: /* original 4011, guest PC 0x0c04cfa2 */
if(!s->budget--) { s->failed_pc=0x0c04cfa2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04cfa4;
P_0c04cfa4: /* original 8902, guest PC 0x0c04cfa4 */
if(!s->budget--) { s->failed_pc=0x0c04cfa4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04cfac; }
goto P_0c04cfa6;
P_0c04cfa6: /* original 9066, guest PC 0x0c04cfa6 */
if(!s->budget--) { s->failed_pc=0x0c04cfa6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d076u,2);
goto P_0c04cfa8;
P_0c04cfa8: /* original a02c, guest PC 0x0c04cfa8 */
if(!s->budget--) { s->failed_pc=0x0c04cfa8u; return 0; }
goto P_0c04d004;
P_0c04cfaa: /* original 0009, guest PC 0x0c04cfaa */
if(!s->budget--) { s->failed_pc=0x0c04cfaau; return 0; }
goto P_0c04cfac;
P_0c04cfac: /* original 55f1, guest PC 0x0c04cfac */
if(!s->budget--) { s->failed_pc=0x0c04cfacu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c04cfae;
P_0c04cfae: /* original 66f3, guest PC 0x0c04cfae */
if(!s->budget--) { s->failed_pc=0x0c04cfaeu; return 0; }
r[6]=r[15];
goto P_0c04cfb0;
P_0c04cfb0: /* original d336, guest PC 0x0c04cfb0 */
if(!s->budget--) { s->failed_pc=0x0c04cfb0u; return 0; }
r[3]=read(ram,0x0c04d08cu,4);
goto P_0c04cfb2;
P_0c04cfb2: /* original 760c, guest PC 0x0c04cfb2 */
if(!s->budget--) { s->failed_pc=0x0c04cfb2u; return 0; }
r[6]+=0x0000000cu;
goto P_0c04cfb4;
P_0c04cfb4: /* original 430b, guest PC 0x0c04cfb4 */
if(!s->budget--) { s->failed_pc=0x0c04cfb4u; return 0; }
target=r[3];
r[16]=0x0c04cfb8u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04cfb8u) { target=s->pc; goto dispatch; }
goto P_0c04cfb8;
P_0c04cfb6: /* original 64d3, guest PC 0x0c04cfb6 */
if(!s->budget--) { s->failed_pc=0x0c04cfb6u; return 0; }
r[4]=r[13];
goto P_0c04cfb8;
P_0c04cfb8: /* original 6403, guest PC 0x0c04cfb8 */
if(!s->budget--) { s->failed_pc=0x0c04cfb8u; return 0; }
r[4]=r[0];
goto P_0c04cfba;
P_0c04cfba: /* original 4411, guest PC 0x0c04cfba */
if(!s->budget--) { s->failed_pc=0x0c04cfbau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c04cfbc;
P_0c04cfbc: /* original 8902, guest PC 0x0c04cfbc */
if(!s->budget--) { s->failed_pc=0x0c04cfbcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04cfc4; }
goto P_0c04cfbe;
P_0c04cfbe: /* original 905b, guest PC 0x0c04cfbe */
if(!s->budget--) { s->failed_pc=0x0c04cfbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d078u,2);
goto P_0c04cfc0;
P_0c04cfc0: /* original a020, guest PC 0x0c04cfc0 */
if(!s->budget--) { s->failed_pc=0x0c04cfc0u; return 0; }
goto P_0c04d004;
P_0c04cfc2: /* original 0009, guest PC 0x0c04cfc2 */
if(!s->budget--) { s->failed_pc=0x0c04cfc2u; return 0; }
goto P_0c04cfc4;
P_0c04cfc4: /* original 63f2, guest PC 0x0c04cfc4 */
if(!s->budget--) { s->failed_pc=0x0c04cfc4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c04cfc6;
P_0c04cfc6: /* original 5237, guest PC 0x0c04cfc6 */
if(!s->budget--) { s->failed_pc=0x0c04cfc6u; return 0; }
r[2]=read(ram,r[3]+28,4);
goto P_0c04cfc8;
P_0c04cfc8: /* original 53fd, guest PC 0x0c04cfc8 */
if(!s->budget--) { s->failed_pc=0x0c04cfc8u; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c04cfca;
P_0c04cfca: /* original 512b, guest PC 0x0c04cfca */
if(!s->budget--) { s->failed_pc=0x0c04cfcau; return 0; }
r[1]=read(ram,r[2]+44,4);
goto P_0c04cfcc;
P_0c04cfcc: /* original 7101, guest PC 0x0c04cfcc */
if(!s->budget--) { s->failed_pc=0x0c04cfccu; return 0; }
r[1]+=0x00000001u;
goto P_0c04cfce;
P_0c04cfce: /* original 0317, guest PC 0x0c04cfce */
if(!s->budget--) { s->failed_pc=0x0c04cfceu; return 0; }
r[19]=r[3]*r[1];
goto P_0c04cfd0;
P_0c04cfd0: /* original 011a, guest PC 0x0c04cfd0 */
if(!s->budget--) { s->failed_pc=0x0c04cfd0u; return 0; }
r[1]=r[19];
goto P_0c04cfd2;
P_0c04cfd2: /* original 2e12, guest PC 0x0c04cfd2 */
if(!s->budget--) { s->failed_pc=0x0c04cfd2u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c04cfd4;
P_0c04cfd4: /* original 50fd, guest PC 0x0c04cfd4 */
if(!s->budget--) { s->failed_pc=0x0c04cfd4u; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c04cfd6;
P_0c04cfd6: /* original 81e2, guest PC 0x0c04cfd6 */
if(!s->budget--) { s->failed_pc=0x0c04cfd6u; return 0; }
write(ram,r[14]+4,r[0],2);
goto P_0c04cfd8;
P_0c04cfd8: /* original 50f4, guest PC 0x0c04cfd8 */
if(!s->budget--) { s->failed_pc=0x0c04cfd8u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c04cfda;
P_0c04cfda: /* original 80e6, guest PC 0x0c04cfda */
if(!s->budget--) { s->failed_pc=0x0c04cfdau; return 0; }
write(ram,r[14]+6,r[0],1);
goto P_0c04cfdc;
P_0c04cfdc: /* original e016, guest PC 0x0c04cfdc */
if(!s->budget--) { s->failed_pc=0x0c04cfdcu; return 0; }
r[0]=0x00000016u;
goto P_0c04cfde;
P_0c04cfde: /* original 00fc, guest PC 0x0c04cfde */
if(!s->budget--) { s->failed_pc=0x0c04cfdeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c04cfe0;
P_0c04cfe0: /* original 80e7, guest PC 0x0c04cfe0 */
if(!s->budget--) { s->failed_pc=0x0c04cfe0u; return 0; }
write(ram,r[14]+7,r[0],1);
goto P_0c04cfe2;
P_0c04cfe2: /* original 85fa, guest PC 0x0c04cfe2 */
if(!s->budget--) { s->failed_pc=0x0c04cfe2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+20,2);
goto P_0c04cfe4;
P_0c04cfe4: /* original 81e4, guest PC 0x0c04cfe4 */
if(!s->budget--) { s->failed_pc=0x0c04cfe4u; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c04cfe6;
P_0c04cfe6: /* original 52f4, guest PC 0x0c04cfe6 */
if(!s->budget--) { s->failed_pc=0x0c04cfe6u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c04cfe8;
P_0c04cfe8: /* original 9347, guest PC 0x0c04cfe8 */
if(!s->budget--) { s->failed_pc=0x0c04cfe8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d07au,2);
goto P_0c04cfea;
P_0c04cfea: /* original 3230, guest PC 0x0c04cfea */
if(!s->budget--) { s->failed_pc=0x0c04cfeau; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c04cfec;
P_0c04cfec: /* original 8b01, guest PC 0x0c04cfec */
if(!s->budget--) { s->failed_pc=0x0c04cfecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04cff2; }
goto P_0c04cfee;
P_0c04cfee: /* original a001, guest PC 0x0c04cfee */
if(!s->budget--) { s->failed_pc=0x0c04cfeeu; return 0; }
r[0]=0x00000001u;
goto P_0c04cff4;
P_0c04cff0: /* original e001, guest PC 0x0c04cff0 */
if(!s->budget--) { s->failed_pc=0x0c04cff0u; return 0; }
r[0]=0x00000001u;
goto P_0c04cff2;
P_0c04cff2: /* original e000, guest PC 0x0c04cff2 */
if(!s->budget--) { s->failed_pc=0x0c04cff2u; return 0; }
r[0]=0x00000000u;
goto P_0c04cff4;
P_0c04cff4: /* original 65f3, guest PC 0x0c04cff4 */
if(!s->budget--) { s->failed_pc=0x0c04cff4u; return 0; }
r[5]=r[15];
goto P_0c04cff6;
P_0c04cff6: /* original 64e3, guest PC 0x0c04cff6 */
if(!s->budget--) { s->failed_pc=0x0c04cff6u; return 0; }
r[4]=r[14];
goto P_0c04cff8;
P_0c04cff8: /* original 80e6, guest PC 0x0c04cff8 */
if(!s->budget--) { s->failed_pc=0x0c04cff8u; return 0; }
write(ram,r[14]+6,r[0],1);
goto P_0c04cffa;
P_0c04cffa: /* original 752c, guest PC 0x0c04cffa */
if(!s->budget--) { s->failed_pc=0x0c04cffau; return 0; }
r[5]+=0x0000002cu;
goto P_0c04cffc;
P_0c04cffc: /* original d324, guest PC 0x0c04cffc */
if(!s->budget--) { s->failed_pc=0x0c04cffcu; return 0; }
r[3]=read(ram,0x0c04d090u,4);
goto P_0c04cffe;
P_0c04cffe: /* original 430b, guest PC 0x0c04cffe */
if(!s->budget--) { s->failed_pc=0x0c04cffeu; return 0; }
target=r[3];
r[16]=0x0c04d002u;
r[4]+=0x0000000au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d002u) { target=s->pc; goto dispatch; }
goto P_0c04d002;
P_0c04d000: /* original 740a, guest PC 0x0c04d000 */
if(!s->budget--) { s->failed_pc=0x0c04d000u; return 0; }
r[4]+=0x0000000au;
goto P_0c04d002;
P_0c04d002: /* original e000, guest PC 0x0c04d002 */
if(!s->budget--) { s->failed_pc=0x0c04d002u; return 0; }
r[0]=0x00000000u;
goto P_0c04d004;
P_0c04d004: /* original 7f38, guest PC 0x0c04d004 */
if(!s->budget--) { s->failed_pc=0x0c04d004u; return 0; }
r[15]+=0x00000038u;
goto P_0c04d006;
P_0c04d006: /* original 4f16, guest PC 0x0c04d006 */
if(!s->budget--) { s->failed_pc=0x0c04d006u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d008;
P_0c04d008: /* original 4f26, guest PC 0x0c04d008 */
if(!s->budget--) { s->failed_pc=0x0c04d008u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d00a;
P_0c04d00a: /* original 6df6, guest PC 0x0c04d00a */
if(!s->budget--) { s->failed_pc=0x0c04d00au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04d00c;
P_0c04d00c: /* original 000b, guest PC 0x0c04d00c */
if(!s->budget--) { s->failed_pc=0x0c04d00cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04d00e: /* original 6ef6, guest PC 0x0c04d00e */
if(!s->budget--) { s->failed_pc=0x0c04d00eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04d010u,s,ram);
P_0c04d800: /* original 2fe6, guest PC 0x0c04d800 */
if(!s->budget--) { s->failed_pc=0x0c04d800u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d802;
P_0c04d802: /* original 2fd6, guest PC 0x0c04d802 */
if(!s->budget--) { s->failed_pc=0x0c04d802u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d804;
P_0c04d804: /* original 6d43, guest PC 0x0c04d804 */
if(!s->budget--) { s->failed_pc=0x0c04d804u; return 0; }
r[13]=r[4];
goto P_0c04d806;
P_0c04d806: /* original 2fc6, guest PC 0x0c04d806 */
if(!s->budget--) { s->failed_pc=0x0c04d806u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d808;
P_0c04d808: /* original 6c53, guest PC 0x0c04d808 */
if(!s->budget--) { s->failed_pc=0x0c04d808u; return 0; }
r[12]=r[5];
goto P_0c04d80a;
P_0c04d80a: /* original 2fb6, guest PC 0x0c04d80a */
if(!s->budget--) { s->failed_pc=0x0c04d80au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d80c;
P_0c04d80c: /* original 6b63, guest PC 0x0c04d80c */
if(!s->budget--) { s->failed_pc=0x0c04d80cu; return 0; }
r[11]=r[6];
goto P_0c04d80e;
P_0c04d80e: /* original 2fa6, guest PC 0x0c04d80e */
if(!s->budget--) { s->failed_pc=0x0c04d80eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d810;
P_0c04d810: /* original ea00, guest PC 0x0c04d810 */
if(!s->budget--) { s->failed_pc=0x0c04d810u; return 0; }
r[10]=0x00000000u;
goto P_0c04d812;
P_0c04d812: /* original 4f22, guest PC 0x0c04d812 */
if(!s->budget--) { s->failed_pc=0x0c04d812u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04d814;
P_0c04d814: /* original 2ba2, guest PC 0x0c04d814 */
if(!s->budget--) { s->failed_pc=0x0c04d814u; return 0; }
write(ram,r[11],r[10],4);
goto P_0c04d816;
P_0c04d816: /* original 4f12, guest PC 0x0c04d816 */
if(!s->budget--) { s->failed_pc=0x0c04d816u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04d818;
P_0c04d818: /* original 7fd4, guest PC 0x0c04d818 */
if(!s->budget--) { s->failed_pc=0x0c04d818u; return 0; }
r[15]+=0xffffffd4u;
goto P_0c04d81a;
P_0c04d81a: /* original 2fb6, guest PC 0x0c04d81a */
if(!s->budget--) { s->failed_pc=0x0c04d81au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d81c;
P_0c04d81c: /* original 2fc6, guest PC 0x0c04d81c */
if(!s->budget--) { s->failed_pc=0x0c04d81cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d81e;
P_0c04d81e: /* original 2fd6, guest PC 0x0c04d81e */
if(!s->budget--) { s->failed_pc=0x0c04d81eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d820;
P_0c04d820: /* original d21e, guest PC 0x0c04d820 */
if(!s->budget--) { s->failed_pc=0x0c04d820u; return 0; }
r[2]=read(ram,0x0c04d89cu,4);
goto P_0c04d822;
P_0c04d822: /* original d31d, guest PC 0x0c04d822 */
if(!s->budget--) { s->failed_pc=0x0c04d822u; return 0; }
r[3]=read(ram,0x0c04d898u,4);
goto P_0c04d824;
P_0c04d824: /* original 420b, guest PC 0x0c04d824 */
if(!s->budget--) { s->failed_pc=0x0c04d824u; return 0; }
target=r[2];
r[16]=0x0c04d828u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d828u) { target=s->pc; goto dispatch; }
goto P_0c04d828;
P_0c04d826: /* original 2f36, guest PC 0x0c04d826 */
if(!s->budget--) { s->failed_pc=0x0c04d826u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d828;
P_0c04d828: /* original 912a, guest PC 0x0c04d828 */
if(!s->budget--) { s->failed_pc=0x0c04d828u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d880u,2);
goto P_0c04d82a;
P_0c04d82a: /* original d01d, guest PC 0x0c04d82a */
if(!s->budget--) { s->failed_pc=0x0c04d82au; return 0; }
r[0]=read(ram,0x0c04d8a0u,4);
goto P_0c04d82c;
P_0c04d82c: /* original 2d1f, guest PC 0x0c04d82c */
if(!s->budget--) { s->failed_pc=0x0c04d82cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[1]);
goto P_0c04d82e;
P_0c04d82e: /* original 011a, guest PC 0x0c04d82e */
if(!s->budget--) { s->failed_pc=0x0c04d82eu; return 0; }
r[1]=r[19];
goto P_0c04d830;
P_0c04d830: /* original 611f, guest PC 0x0c04d830 */
if(!s->budget--) { s->failed_pc=0x0c04d830u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[1];
goto P_0c04d832;
P_0c04d832: /* original 031c, guest PC 0x0c04d832 */
if(!s->budget--) { s->failed_pc=0x0c04d832u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c04d834;
P_0c04d834: /* original 2338, guest PC 0x0c04d834 */
if(!s->budget--) { s->failed_pc=0x0c04d834u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04d836;
P_0c04d836: /* original 8d16, guest PC 0x0c04d836 */
if(!s->budget--) { s->failed_pc=0x0c04d836u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000010u;
if(cond) { goto P_0c04d866; }
goto P_0c04d83a;
P_0c04d838: /* original 7f10, guest PC 0x0c04d838 */
if(!s->budget--) { s->failed_pc=0x0c04d838u; return 0; }
r[15]+=0x00000010u;
goto P_0c04d83a;
P_0c04d83a: /* original d21a, guest PC 0x0c04d83a */
if(!s->budget--) { s->failed_pc=0x0c04d83au; return 0; }
r[2]=read(ram,0x0c04d8a4u,4);
goto P_0c04d83c;
P_0c04d83c: /* original 420b, guest PC 0x0c04d83c */
if(!s->budget--) { s->failed_pc=0x0c04d83cu; return 0; }
target=r[2];
r[16]=0x0c04d840u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d840u) { target=s->pc; goto dispatch; }
goto P_0c04d840;
P_0c04d83e: /* original 64d3, guest PC 0x0c04d83e */
if(!s->budget--) { s->failed_pc=0x0c04d83eu; return 0; }
r[4]=r[13];
goto P_0c04d840;
P_0c04d840: /* original 2008, guest PC 0x0c04d840 */
if(!s->budget--) { s->failed_pc=0x0c04d840u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d842;
P_0c04d842: /* original 8b03, guest PC 0x0c04d842 */
if(!s->budget--) { s->failed_pc=0x0c04d842u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d84c; }
goto P_0c04d844;
P_0c04d844: /* original bb43, guest PC 0x0c04d844 */
if(!s->budget--) { s->failed_pc=0x0c04d844u; return 0; }
target=0x0c04ceceu; r[16]=0x0c04d848u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d848u) { target=s->pc; goto dispatch; }
goto P_0c04d848;
P_0c04d846: /* original 64d3, guest PC 0x0c04d846 */
if(!s->budget--) { s->failed_pc=0x0c04d846u; return 0; }
r[4]=r[13];
goto P_0c04d848;
P_0c04d848: /* original a00d, guest PC 0x0c04d848 */
if(!s->budget--) { s->failed_pc=0x0c04d848u; return 0; }
goto P_0c04d866;
P_0c04d84a: /* original 0009, guest PC 0x0c04d84a */
if(!s->budget--) { s->failed_pc=0x0c04d84au; return 0; }
goto P_0c04d84c;
P_0c04d84c: /* original d30d, guest PC 0x0c04d84c */
if(!s->budget--) { s->failed_pc=0x0c04d84cu; return 0; }
r[3]=read(ram,0x0c04d884u,4);
goto P_0c04d84e;
P_0c04d84e: /* original 430b, guest PC 0x0c04d84e */
if(!s->budget--) { s->failed_pc=0x0c04d84eu; return 0; }
target=r[3];
r[16]=0x0c04d852u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d852u) { target=s->pc; goto dispatch; }
goto P_0c04d852;
P_0c04d850: /* original 64d3, guest PC 0x0c04d850 */
if(!s->budget--) { s->failed_pc=0x0c04d850u; return 0; }
r[4]=r[13];
goto P_0c04d852;
P_0c04d852: /* original 2008, guest PC 0x0c04d852 */
if(!s->budget--) { s->failed_pc=0x0c04d852u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d854;
P_0c04d854: /* original 8907, guest PC 0x0c04d854 */
if(!s->budget--) { s->failed_pc=0x0c04d854u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d866; }
goto P_0c04d856;
P_0c04d856: /* original 9213, guest PC 0x0c04d856 */
if(!s->budget--) { s->failed_pc=0x0c04d856u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d880u,2);
goto P_0c04d858;
P_0c04d858: /* original d013, guest PC 0x0c04d858 */
if(!s->budget--) { s->failed_pc=0x0c04d858u; return 0; }
r[0]=read(ram,0x0c04d8a8u,4);
goto P_0c04d85a;
P_0c04d85a: /* original 2d2f, guest PC 0x0c04d85a */
if(!s->budget--) { s->failed_pc=0x0c04d85au; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[2]);
goto P_0c04d85c;
P_0c04d85c: /* original 021a, guest PC 0x0c04d85c */
if(!s->budget--) { s->failed_pc=0x0c04d85cu; return 0; }
r[2]=r[19];
goto P_0c04d85e;
P_0c04d85e: /* original 622f, guest PC 0x0c04d85e */
if(!s->budget--) { s->failed_pc=0x0c04d85eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c04d860;
P_0c04d860: /* original 032c, guest PC 0x0c04d860 */
if(!s->budget--) { s->failed_pc=0x0c04d860u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c04d862;
P_0c04d862: /* original 2338, guest PC 0x0c04d862 */
if(!s->budget--) { s->failed_pc=0x0c04d862u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04d864;
P_0c04d864: /* original 8b02, guest PC 0x0c04d864 */
if(!s->budget--) { s->failed_pc=0x0c04d864u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d86c; }
goto P_0c04d866;
P_0c04d866: /* original 9009, guest PC 0x0c04d866 */
if(!s->budget--) { s->failed_pc=0x0c04d866u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d87cu,2);
goto P_0c04d868;
P_0c04d868: /* original a070, guest PC 0x0c04d868 */
if(!s->budget--) { s->failed_pc=0x0c04d868u; return 0; }
goto P_0c04d94c;
P_0c04d86a: /* original 0009, guest PC 0x0c04d86a */
if(!s->budget--) { s->failed_pc=0x0c04d86au; return 0; }
goto P_0c04d86c;
P_0c04d86c: /* original d307, guest PC 0x0c04d86c */
if(!s->budget--) { s->failed_pc=0x0c04d86cu; return 0; }
r[3]=read(ram,0x0c04d88cu,4);
goto P_0c04d86e;
P_0c04d86e: /* original 430b, guest PC 0x0c04d86e */
if(!s->budget--) { s->failed_pc=0x0c04d86eu; return 0; }
target=r[3];
r[16]=0x0c04d872u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d872u) { target=s->pc; goto dispatch; }
goto P_0c04d872;
P_0c04d870: /* original 64d3, guest PC 0x0c04d870 */
if(!s->budget--) { s->failed_pc=0x0c04d870u; return 0; }
r[4]=r[13];
goto P_0c04d872;
P_0c04d872: /* original 4011, guest PC 0x0c04d872 */
if(!s->budget--) { s->failed_pc=0x0c04d872u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d874;
P_0c04d874: /* original 891a, guest PC 0x0c04d874 */
if(!s->budget--) { s->failed_pc=0x0c04d874u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d8ac; }
goto P_0c04d876;
P_0c04d876: /* original 9002, guest PC 0x0c04d876 */
if(!s->budget--) { s->failed_pc=0x0c04d876u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d87eu,2);
goto P_0c04d878;
P_0c04d878: /* original a068, guest PC 0x0c04d878 */
if(!s->budget--) { s->failed_pc=0x0c04d878u; return 0; }
goto P_0c04d94c;
P_0c04d87a: /* original 0009, guest PC 0x0c04d87a */
if(!s->budget--) { s->failed_pc=0x0c04d87au; return 0; }
return vf3_matrix_family(0x0c04d87cu,s,ram);
P_0c04d8ac: /* original d345, guest PC 0x0c04d8ac */
if(!s->budget--) { s->failed_pc=0x0c04d8acu; return 0; }
r[3]=read(ram,0x0c04d9c4u,4);
goto P_0c04d8ae;
P_0c04d8ae: /* original 65c3, guest PC 0x0c04d8ae */
if(!s->budget--) { s->failed_pc=0x0c04d8aeu; return 0; }
r[5]=r[12];
goto P_0c04d8b0;
P_0c04d8b0: /* original 430b, guest PC 0x0c04d8b0 */
if(!s->budget--) { s->failed_pc=0x0c04d8b0u; return 0; }
target=r[3];
r[16]=0x0c04d8b4u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d8b4u) { target=s->pc; goto dispatch; }
goto P_0c04d8b4;
P_0c04d8b2: /* original 64d3, guest PC 0x0c04d8b2 */
if(!s->budget--) { s->failed_pc=0x0c04d8b2u; return 0; }
r[4]=r[13];
goto P_0c04d8b4;
P_0c04d8b4: /* original 4011, guest PC 0x0c04d8b4 */
if(!s->budget--) { s->failed_pc=0x0c04d8b4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d8b6;
P_0c04d8b6: /* original 8b0e, guest PC 0x0c04d8b6 */
if(!s->budget--) { s->failed_pc=0x0c04d8b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d8d6; }
goto P_0c04d8b8;
P_0c04d8b8: /* original d243, guest PC 0x0c04d8b8 */
if(!s->budget--) { s->failed_pc=0x0c04d8b8u; return 0; }
r[2]=read(ram,0x0c04d9c8u,4);
goto P_0c04d8ba;
P_0c04d8ba: /* original 65c3, guest PC 0x0c04d8ba */
if(!s->budget--) { s->failed_pc=0x0c04d8bau; return 0; }
r[5]=r[12];
goto P_0c04d8bc;
P_0c04d8bc: /* original 420b, guest PC 0x0c04d8bc */
if(!s->budget--) { s->failed_pc=0x0c04d8bcu; return 0; }
target=r[2];
r[16]=0x0c04d8c0u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d8c0u) { target=s->pc; goto dispatch; }
goto P_0c04d8c0;
P_0c04d8be: /* original 64d3, guest PC 0x0c04d8be */
if(!s->budget--) { s->failed_pc=0x0c04d8beu; return 0; }
r[4]=r[13];
goto P_0c04d8c0;
P_0c04d8c0: /* original 4011, guest PC 0x0c04d8c0 */
if(!s->budget--) { s->failed_pc=0x0c04d8c0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d8c2;
P_0c04d8c2: /* original 8902, guest PC 0x0c04d8c2 */
if(!s->budget--) { s->failed_pc=0x0c04d8c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d8ca; }
goto P_0c04d8c4;
P_0c04d8c4: /* original 9079, guest PC 0x0c04d8c4 */
if(!s->budget--) { s->failed_pc=0x0c04d8c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d9bau,2);
goto P_0c04d8c6;
P_0c04d8c6: /* original a041, guest PC 0x0c04d8c6 */
if(!s->budget--) { s->failed_pc=0x0c04d8c6u; return 0; }
goto P_0c04d94c;
P_0c04d8c8: /* original 0009, guest PC 0x0c04d8c8 */
if(!s->budget--) { s->failed_pc=0x0c04d8c8u; return 0; }
goto P_0c04d8ca;
P_0c04d8ca: /* original d240, guest PC 0x0c04d8ca */
if(!s->budget--) { s->failed_pc=0x0c04d8cau; return 0; }
r[2]=read(ram,0x0c04d9ccu,4);
goto P_0c04d8cc;
P_0c04d8cc: /* original 420b, guest PC 0x0c04d8cc */
if(!s->budget--) { s->failed_pc=0x0c04d8ccu; return 0; }
target=r[2];
r[16]=0x0c04d8d0u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d8d0u) { target=s->pc; goto dispatch; }
goto P_0c04d8d0;
P_0c04d8ce: /* original 64d3, guest PC 0x0c04d8ce */
if(!s->budget--) { s->failed_pc=0x0c04d8ceu; return 0; }
r[4]=r[13];
goto P_0c04d8d0;
P_0c04d8d0: /* original 6e03, guest PC 0x0c04d8d0 */
if(!s->budget--) { s->failed_pc=0x0c04d8d0u; return 0; }
r[14]=r[0];
goto P_0c04d8d2;
P_0c04d8d2: /* original 2ee8, guest PC 0x0c04d8d2 */
if(!s->budget--) { s->failed_pc=0x0c04d8d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c04d8d4;
P_0c04d8d4: /* original 8b02, guest PC 0x0c04d8d4 */
if(!s->budget--) { s->failed_pc=0x0c04d8d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d8dc; }
goto P_0c04d8d6;
P_0c04d8d6: /* original 9071, guest PC 0x0c04d8d6 */
if(!s->budget--) { s->failed_pc=0x0c04d8d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d9bcu,2);
goto P_0c04d8d8;
P_0c04d8d8: /* original a038, guest PC 0x0c04d8d8 */
if(!s->budget--) { s->failed_pc=0x0c04d8d8u; return 0; }
goto P_0c04d94c;
P_0c04d8da: /* original 0009, guest PC 0x0c04d8da */
if(!s->budget--) { s->failed_pc=0x0c04d8dau; return 0; }
goto P_0c04d8dc;
P_0c04d8dc: /* original d23c, guest PC 0x0c04d8dc */
if(!s->budget--) { s->failed_pc=0x0c04d8dcu; return 0; }
r[2]=read(ram,0x0c04d9d0u,4);
goto P_0c04d8de;
P_0c04d8de: /* original 65c3, guest PC 0x0c04d8de */
if(!s->budget--) { s->failed_pc=0x0c04d8deu; return 0; }
r[5]=r[12];
goto P_0c04d8e0;
P_0c04d8e0: /* original 66f3, guest PC 0x0c04d8e0 */
if(!s->budget--) { s->failed_pc=0x0c04d8e0u; return 0; }
r[6]=r[15];
goto P_0c04d8e2;
P_0c04d8e2: /* original 420b, guest PC 0x0c04d8e2 */
if(!s->budget--) { s->failed_pc=0x0c04d8e2u; return 0; }
target=r[2];
r[16]=0x0c04d8e6u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d8e6u) { target=s->pc; goto dispatch; }
goto P_0c04d8e6;
P_0c04d8e4: /* original 64d3, guest PC 0x0c04d8e4 */
if(!s->budget--) { s->failed_pc=0x0c04d8e4u; return 0; }
r[4]=r[13];
goto P_0c04d8e6;
P_0c04d8e6: /* original d33b, guest PC 0x0c04d8e6 */
if(!s->budget--) { s->failed_pc=0x0c04d8e6u; return 0; }
r[3]=read(ram,0x0c04d9d4u,4);
goto P_0c04d8e8;
P_0c04d8e8: /* original 4011, guest PC 0x0c04d8e8 */
if(!s->budget--) { s->failed_pc=0x0c04d8e8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d8ea;
P_0c04d8ea: /* original 8d06, guest PC 0x0c04d8ea */
if(!s->budget--) { s->failed_pc=0x0c04d8eau; return 0; }
cond=r[17]&1u;
write(ram,r[3],r[0],4);
if(cond) { goto P_0c04d8fa; }
goto P_0c04d8ee;
P_0c04d8ec: /* original 2302, guest PC 0x0c04d8ec */
if(!s->budget--) { s->failed_pc=0x0c04d8ecu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c04d8ee;
P_0c04d8ee: /* original d13a, guest PC 0x0c04d8ee */
if(!s->budget--) { s->failed_pc=0x0c04d8eeu; return 0; }
r[1]=read(ram,0x0c04d9d8u,4);
goto P_0c04d8f0;
P_0c04d8f0: /* original 410b, guest PC 0x0c04d8f0 */
if(!s->budget--) { s->failed_pc=0x0c04d8f0u; return 0; }
target=r[1];
r[16]=0x0c04d8f4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d8f4u) { target=s->pc; goto dispatch; }
goto P_0c04d8f4;
P_0c04d8f2: /* original 64e3, guest PC 0x0c04d8f2 */
if(!s->budget--) { s->failed_pc=0x0c04d8f2u; return 0; }
r[4]=r[14];
goto P_0c04d8f4;
P_0c04d8f4: /* original 9063, guest PC 0x0c04d8f4 */
if(!s->budget--) { s->failed_pc=0x0c04d8f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d9beu,2);
goto P_0c04d8f6;
P_0c04d8f6: /* original a029, guest PC 0x0c04d8f6 */
if(!s->budget--) { s->failed_pc=0x0c04d8f6u; return 0; }
goto P_0c04d94c;
P_0c04d8f8: /* original 0009, guest PC 0x0c04d8f8 */
if(!s->budget--) { s->failed_pc=0x0c04d8f8u; return 0; }
goto P_0c04d8fa;
P_0c04d8fa: /* original e040, guest PC 0x0c04d8fa */
if(!s->budget--) { s->failed_pc=0x0c04d8fau; return 0; }
r[0]=0x00000040u;
goto P_0c04d8fc;
P_0c04d8fc: /* original 1ea1, guest PC 0x0c04d8fc */
if(!s->budget--) { s->failed_pc=0x0c04d8fcu; return 0; }
write(ram,r[14]+4,r[10],4);
goto P_0c04d8fe;
P_0c04d8fe: /* original 53fa, guest PC 0x0c04d8fe */
if(!s->budget--) { s->failed_pc=0x0c04d8feu; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c04d900;
P_0c04d900: /* original 1e3d, guest PC 0x0c04d900 */
if(!s->budget--) { s->failed_pc=0x0c04d900u; return 0; }
write(ram,r[14]+52,r[3],4);
goto P_0c04d902;
P_0c04d902: /* original 52f3, guest PC 0x0c04d902 */
if(!s->budget--) { s->failed_pc=0x0c04d902u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c04d904;
P_0c04d904: /* original 1e2e, guest PC 0x0c04d904 */
if(!s->budget--) { s->failed_pc=0x0c04d904u; return 0; }
write(ram,r[14]+56,r[2],4);
goto P_0c04d906;
P_0c04d906: /* original 6323, guest PC 0x0c04d906 */
if(!s->budget--) { s->failed_pc=0x0c04d906u; return 0; }
r[3]=r[2];
goto P_0c04d908;
P_0c04d908: /* original 0e26, guest PC 0x0c04d908 */
if(!s->budget--) { s->failed_pc=0x0c04d908u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c04d90a;
P_0c04d90a: /* original 1eda, guest PC 0x0c04d90a */
if(!s->budget--) { s->failed_pc=0x0c04d90au; return 0; }
write(ram,r[14]+40,r[13],4);
goto P_0c04d90c;
P_0c04d90c: /* original 85f4, guest PC 0x0c04d90c */
if(!s->budget--) { s->failed_pc=0x0c04d90cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c04d90e;
P_0c04d90e: /* original 81e1, guest PC 0x0c04d90e */
if(!s->budget--) { s->failed_pc=0x0c04d90eu; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c04d910;
P_0c04d910: /* original 84fa, guest PC 0x0c04d910 */
if(!s->budget--) { s->failed_pc=0x0c04d910u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+10,1);
goto P_0c04d912;
P_0c04d912: /* original 80e1, guest PC 0x0c04d912 */
if(!s->budget--) { s->failed_pc=0x0c04d912u; return 0; }
write(ram,r[14]+1,r[0],1);
goto P_0c04d914;
P_0c04d914: /* original 53e1, guest PC 0x0c04d914 */
if(!s->budget--) { s->failed_pc=0x0c04d914u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c04d916;
P_0c04d916: /* original 2f36, guest PC 0x0c04d916 */
if(!s->budget--) { s->failed_pc=0x0c04d916u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d918;
P_0c04d918: /* original d331, guest PC 0x0c04d918 */
if(!s->budget--) { s->failed_pc=0x0c04d918u; return 0; }
r[3]=read(ram,0x0c04d9e0u,4);
goto P_0c04d91a;
P_0c04d91a: /* original d230, guest PC 0x0c04d91a */
if(!s->budget--) { s->failed_pc=0x0c04d91au; return 0; }
r[2]=read(ram,0x0c04d9dcu,4);
goto P_0c04d91c;
P_0c04d91c: /* original 430b, guest PC 0x0c04d91c */
if(!s->budget--) { s->failed_pc=0x0c04d91cu; return 0; }
target=r[3];
r[16]=0x0c04d920u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d920u) { target=s->pc; goto dispatch; }
goto P_0c04d920;
P_0c04d91e: /* original 2f26, guest PC 0x0c04d91e */
if(!s->budget--) { s->failed_pc=0x0c04d91eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d920;
P_0c04d920: /* original 51ed, guest PC 0x0c04d920 */
if(!s->budget--) { s->failed_pc=0x0c04d920u; return 0; }
r[1]=read(ram,r[14]+52,4);
goto P_0c04d922;
P_0c04d922: /* original 2f16, guest PC 0x0c04d922 */
if(!s->budget--) { s->failed_pc=0x0c04d922u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d924;
P_0c04d924: /* original d32f, guest PC 0x0c04d924 */
if(!s->budget--) { s->failed_pc=0x0c04d924u; return 0; }
r[3]=read(ram,0x0c04d9e4u,4);
goto P_0c04d926;
P_0c04d926: /* original d22e, guest PC 0x0c04d926 */
if(!s->budget--) { s->failed_pc=0x0c04d926u; return 0; }
r[2]=read(ram,0x0c04d9e0u,4);
goto P_0c04d928;
P_0c04d928: /* original 420b, guest PC 0x0c04d928 */
if(!s->budget--) { s->failed_pc=0x0c04d928u; return 0; }
target=r[2];
r[16]=0x0c04d92cu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d92cu) { target=s->pc; goto dispatch; }
goto P_0c04d92c;
P_0c04d92a: /* original 2f36, guest PC 0x0c04d92a */
if(!s->budget--) { s->failed_pc=0x0c04d92au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d92c;
P_0c04d92c: /* original 51ee, guest PC 0x0c04d92c */
if(!s->budget--) { s->failed_pc=0x0c04d92cu; return 0; }
r[1]=read(ram,r[14]+56,4);
goto P_0c04d92e;
P_0c04d92e: /* original 2f16, guest PC 0x0c04d92e */
if(!s->budget--) { s->failed_pc=0x0c04d92eu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d930;
P_0c04d930: /* original d32d, guest PC 0x0c04d930 */
if(!s->budget--) { s->failed_pc=0x0c04d930u; return 0; }
r[3]=read(ram,0x0c04d9e8u,4);
goto P_0c04d932;
P_0c04d932: /* original d22b, guest PC 0x0c04d932 */
if(!s->budget--) { s->failed_pc=0x0c04d932u; return 0; }
r[2]=read(ram,0x0c04d9e0u,4);
goto P_0c04d934;
P_0c04d934: /* original 420b, guest PC 0x0c04d934 */
if(!s->budget--) { s->failed_pc=0x0c04d934u; return 0; }
target=r[2];
r[16]=0x0c04d938u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d938u) { target=s->pc; goto dispatch; }
goto P_0c04d938;
P_0c04d936: /* original 2f36, guest PC 0x0c04d936 */
if(!s->budget--) { s->failed_pc=0x0c04d936u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d938;
P_0c04d938: /* original e040, guest PC 0x0c04d938 */
if(!s->budget--) { s->failed_pc=0x0c04d938u; return 0; }
r[0]=0x00000040u;
goto P_0c04d93a;
P_0c04d93a: /* original 01ee, guest PC 0x0c04d93a */
if(!s->budget--) { s->failed_pc=0x0c04d93au; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c04d93c;
P_0c04d93c: /* original 2f16, guest PC 0x0c04d93c */
if(!s->budget--) { s->failed_pc=0x0c04d93cu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d93e;
P_0c04d93e: /* original d32b, guest PC 0x0c04d93e */
if(!s->budget--) { s->failed_pc=0x0c04d93eu; return 0; }
r[3]=read(ram,0x0c04d9ecu,4);
goto P_0c04d940;
P_0c04d940: /* original d227, guest PC 0x0c04d940 */
if(!s->budget--) { s->failed_pc=0x0c04d940u; return 0; }
r[2]=read(ram,0x0c04d9e0u,4);
goto P_0c04d942;
P_0c04d942: /* original 420b, guest PC 0x0c04d942 */
if(!s->budget--) { s->failed_pc=0x0c04d942u; return 0; }
target=r[2];
r[16]=0x0c04d946u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d946u) { target=s->pc; goto dispatch; }
goto P_0c04d946;
P_0c04d944: /* original 2f36, guest PC 0x0c04d944 */
if(!s->budget--) { s->failed_pc=0x0c04d944u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d946;
P_0c04d946: /* original 60a3, guest PC 0x0c04d946 */
if(!s->budget--) { s->failed_pc=0x0c04d946u; return 0; }
r[0]=r[10];
goto P_0c04d948;
P_0c04d948: /* original 2be2, guest PC 0x0c04d948 */
if(!s->budget--) { s->failed_pc=0x0c04d948u; return 0; }
write(ram,r[11],r[14],4);
goto P_0c04d94a;
P_0c04d94a: /* original 7f20, guest PC 0x0c04d94a */
if(!s->budget--) { s->failed_pc=0x0c04d94au; return 0; }
r[15]+=0x00000020u;
goto P_0c04d94c;
P_0c04d94c: /* original 7f2c, guest PC 0x0c04d94c */
if(!s->budget--) { s->failed_pc=0x0c04d94cu; return 0; }
r[15]+=0x0000002cu;
goto P_0c04d94e;
P_0c04d94e: /* original 4f16, guest PC 0x0c04d94e */
if(!s->budget--) { s->failed_pc=0x0c04d94eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d950;
P_0c04d950: /* original 4f26, guest PC 0x0c04d950 */
if(!s->budget--) { s->failed_pc=0x0c04d950u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d952;
P_0c04d952: /* original 6af6, guest PC 0x0c04d952 */
if(!s->budget--) { s->failed_pc=0x0c04d952u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04d954;
P_0c04d954: /* original 6bf6, guest PC 0x0c04d954 */
if(!s->budget--) { s->failed_pc=0x0c04d954u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04d956;
P_0c04d956: /* original 6cf6, guest PC 0x0c04d956 */
if(!s->budget--) { s->failed_pc=0x0c04d956u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04d958;
P_0c04d958: /* original 6df6, guest PC 0x0c04d958 */
if(!s->budget--) { s->failed_pc=0x0c04d958u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04d95a;
P_0c04d95a: /* original 000b, guest PC 0x0c04d95a */
if(!s->budget--) { s->failed_pc=0x0c04d95au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04d95c: /* original 6ef6, guest PC 0x0c04d95c */
if(!s->budget--) { s->failed_pc=0x0c04d95cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04d95e;
P_0c04d95e: /* original 2fe6, guest PC 0x0c04d95e */
if(!s->budget--) { s->failed_pc=0x0c04d95eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d960;
P_0c04d960: /* original 6e43, guest PC 0x0c04d960 */
if(!s->budget--) { s->failed_pc=0x0c04d960u; return 0; }
r[14]=r[4];
goto P_0c04d962;
P_0c04d962: /* original 2fd6, guest PC 0x0c04d962 */
if(!s->budget--) { s->failed_pc=0x0c04d962u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d964;
P_0c04d964: /* original 2fc6, guest PC 0x0c04d964 */
if(!s->budget--) { s->failed_pc=0x0c04d964u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d966;
P_0c04d966: /* original 6c53, guest PC 0x0c04d966 */
if(!s->budget--) { s->failed_pc=0x0c04d966u; return 0; }
r[12]=r[5];
goto P_0c04d968;
P_0c04d968: /* original 2fb6, guest PC 0x0c04d968 */
if(!s->budget--) { s->failed_pc=0x0c04d968u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d96a;
P_0c04d96a: /* original 2fa6, guest PC 0x0c04d96a */
if(!s->budget--) { s->failed_pc=0x0c04d96au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d96c;
P_0c04d96c: /* original 6a73, guest PC 0x0c04d96c */
if(!s->budget--) { s->failed_pc=0x0c04d96cu; return 0; }
r[10]=r[7];
goto P_0c04d96e;
P_0c04d96e: /* original 2f96, guest PC 0x0c04d96e */
if(!s->budget--) { s->failed_pc=0x0c04d96eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d970;
P_0c04d970: /* original 4f22, guest PC 0x0c04d970 */
if(!s->budget--) { s->failed_pc=0x0c04d970u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04d972;
P_0c04d972: /* original 4f12, guest PC 0x0c04d972 */
if(!s->budget--) { s->failed_pc=0x0c04d972u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04d974;
P_0c04d974: /* original 7fc8, guest PC 0x0c04d974 */
if(!s->budget--) { s->failed_pc=0x0c04d974u; return 0; }
r[15]+=0xffffffc8u;
goto P_0c04d976;
P_0c04d976: /* original 2f62, guest PC 0x0c04d976 */
if(!s->budget--) { s->failed_pc=0x0c04d976u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c04d978;
P_0c04d978: /* original 9322, guest PC 0x0c04d978 */
if(!s->budget--) { s->failed_pc=0x0c04d978u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d9c0u,2);
goto P_0c04d97a;
P_0c04d97a: /* original 2e3f, guest PC 0x0c04d97a */
if(!s->budget--) { s->failed_pc=0x0c04d97au; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c04d97c;
P_0c04d97c: /* original 031a, guest PC 0x0c04d97c */
if(!s->budget--) { s->failed_pc=0x0c04d97cu; return 0; }
r[3]=r[19];
goto P_0c04d97e;
P_0c04d97e: /* original 633f, guest PC 0x0c04d97e */
if(!s->budget--) { s->failed_pc=0x0c04d97eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04d980;
P_0c04d980: /* original 1f32, guest PC 0x0c04d980 */
if(!s->budget--) { s->failed_pc=0x0c04d980u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c04d982;
P_0c04d982: /* original d21b, guest PC 0x0c04d982 */
if(!s->budget--) { s->failed_pc=0x0c04d982u; return 0; }
r[2]=read(ram,0x0c04d9f0u,4);
goto P_0c04d984;
P_0c04d984: /* original 332c, guest PC 0x0c04d984 */
if(!s->budget--) { s->failed_pc=0x0c04d984u; return 0; }
r[3]+=r[2];
goto P_0c04d986;
P_0c04d986: /* original 1f31, guest PC 0x0c04d986 */
if(!s->budget--) { s->failed_pc=0x0c04d986u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c04d988;
P_0c04d988: /* original 2fa6, guest PC 0x0c04d988 */
if(!s->budget--) { s->failed_pc=0x0c04d988u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d98a;
P_0c04d98a: /* original 51f1, guest PC 0x0c04d98a */
if(!s->budget--) { s->failed_pc=0x0c04d98au; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c04d98c;
P_0c04d98c: /* original 2f16, guest PC 0x0c04d98c */
if(!s->budget--) { s->failed_pc=0x0c04d98cu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d98e;
P_0c04d98e: /* original 2fc6, guest PC 0x0c04d98e */
if(!s->budget--) { s->failed_pc=0x0c04d98eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d990;
P_0c04d990: /* original 2fe6, guest PC 0x0c04d990 */
if(!s->budget--) { s->failed_pc=0x0c04d990u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d992;
P_0c04d992: /* original d118, guest PC 0x0c04d992 */
if(!s->budget--) { s->failed_pc=0x0c04d992u; return 0; }
r[1]=read(ram,0x0c04d9f4u,4);
goto P_0c04d994;
P_0c04d994: /* original d312, guest PC 0x0c04d994 */
if(!s->budget--) { s->failed_pc=0x0c04d994u; return 0; }
r[3]=read(ram,0x0c04d9e0u,4);
goto P_0c04d996;
P_0c04d996: /* original 430b, guest PC 0x0c04d996 */
if(!s->budget--) { s->failed_pc=0x0c04d996u; return 0; }
target=r[3];
r[16]=0x0c04d99au;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d99au) { target=s->pc; goto dispatch; }
goto P_0c04d99a;
P_0c04d998: /* original 2f16, guest PC 0x0c04d998 */
if(!s->budget--) { s->failed_pc=0x0c04d998u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d99a;
P_0c04d99a: /* original 7f14, guest PC 0x0c04d99a */
if(!s->budget--) { s->failed_pc=0x0c04d99au; return 0; }
r[15]+=0x00000014u;
goto P_0c04d99c;
P_0c04d99c: /* original eb00, guest PC 0x0c04d99c */
if(!s->budget--) { s->failed_pc=0x0c04d99cu; return 0; }
r[11]=0x00000000u;
goto P_0c04d99e;
P_0c04d99e: /* original 2ab2, guest PC 0x0c04d99e */
if(!s->budget--) { s->failed_pc=0x0c04d99eu; return 0; }
write(ram,r[10],r[11],4);
goto P_0c04d9a0;
P_0c04d9a0: /* original 52f1, guest PC 0x0c04d9a0 */
if(!s->budget--) { s->failed_pc=0x0c04d9a0u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c04d9a2;
P_0c04d9a2: /* original 8422, guest PC 0x0c04d9a2 */
if(!s->budget--) { s->failed_pc=0x0c04d9a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+2,1);
goto P_0c04d9a4;
P_0c04d9a4: /* original 2008, guest PC 0x0c04d9a4 */
if(!s->budget--) { s->failed_pc=0x0c04d9a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d9a6;
P_0c04d9a6: /* original 8934, guest PC 0x0c04d9a6 */
if(!s->budget--) { s->failed_pc=0x0c04d9a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04da12; }
goto P_0c04d9a8;
P_0c04d9a8: /* original d213, guest PC 0x0c04d9a8 */
if(!s->budget--) { s->failed_pc=0x0c04d9a8u; return 0; }
r[2]=read(ram,0x0c04d9f8u,4);
goto P_0c04d9aa;
P_0c04d9aa: /* original 420b, guest PC 0x0c04d9aa */
if(!s->budget--) { s->failed_pc=0x0c04d9aau; return 0; }
target=r[2];
r[16]=0x0c04d9aeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d9aeu) { target=s->pc; goto dispatch; }
goto P_0c04d9ae;
P_0c04d9ac: /* original 64e3, guest PC 0x0c04d9ac */
if(!s->budget--) { s->failed_pc=0x0c04d9acu; return 0; }
r[4]=r[14];
goto P_0c04d9ae;
P_0c04d9ae: /* original 2008, guest PC 0x0c04d9ae */
if(!s->budget--) { s->failed_pc=0x0c04d9aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d9b0;
P_0c04d9b0: /* original 8b24, guest PC 0x0c04d9b0 */
if(!s->budget--) { s->failed_pc=0x0c04d9b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d9fc; }
goto P_0c04d9b2;
P_0c04d9b2: /* original ba8c, guest PC 0x0c04d9b2 */
if(!s->budget--) { s->failed_pc=0x0c04d9b2u; return 0; }
target=0x0c04ceceu; r[16]=0x0c04d9b6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04d9b6u) { target=s->pc; goto dispatch; }
goto P_0c04d9b6;
P_0c04d9b4: /* original 64e3, guest PC 0x0c04d9b4 */
if(!s->budget--) { s->failed_pc=0x0c04d9b4u; return 0; }
r[4]=r[14];
goto P_0c04d9b6;
P_0c04d9b6: /* original a02c, guest PC 0x0c04d9b6 */
if(!s->budget--) { s->failed_pc=0x0c04d9b6u; return 0; }
goto P_0c04da12;
P_0c04d9b8: /* original 0009, guest PC 0x0c04d9b8 */
if(!s->budget--) { s->failed_pc=0x0c04d9b8u; return 0; }
return vf3_matrix_family(0x0c04d9bau,s,ram);
P_0c04d9fc: /* original d33b, guest PC 0x0c04d9fc */
if(!s->budget--) { s->failed_pc=0x0c04d9fcu; return 0; }
r[3]=read(ram,0x0c04daecu,4);
goto P_0c04d9fe;
P_0c04d9fe: /* original 430b, guest PC 0x0c04d9fe */
if(!s->budget--) { s->failed_pc=0x0c04d9feu; return 0; }
target=r[3];
r[16]=0x0c04da02u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04da02u) { target=s->pc; goto dispatch; }
goto P_0c04da02;
P_0c04da00: /* original 64e3, guest PC 0x0c04da00 */
if(!s->budget--) { s->failed_pc=0x0c04da00u; return 0; }
r[4]=r[14];
goto P_0c04da02;
P_0c04da02: /* original 2008, guest PC 0x0c04da02 */
if(!s->budget--) { s->failed_pc=0x0c04da02u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04da04;
P_0c04da04: /* original 8905, guest PC 0x0c04da04 */
if(!s->budget--) { s->failed_pc=0x0c04da04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04da12; }
goto P_0c04da06;
P_0c04da06: /* original 52f2, guest PC 0x0c04da06 */
if(!s->budget--) { s->failed_pc=0x0c04da06u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c04da08;
P_0c04da08: /* original d339, guest PC 0x0c04da08 */
if(!s->budget--) { s->failed_pc=0x0c04da08u; return 0; }
r[3]=read(ram,0x0c04daf0u,4);
goto P_0c04da0a;
P_0c04da0a: /* original 323c, guest PC 0x0c04da0a */
if(!s->budget--) { s->failed_pc=0x0c04da0au; return 0; }
r[2]+=r[3];
goto P_0c04da0c;
P_0c04da0c: /* original 8428, guest PC 0x0c04da0c */
if(!s->budget--) { s->failed_pc=0x0c04da0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04da0e;
P_0c04da0e: /* original 2008, guest PC 0x0c04da0e */
if(!s->budget--) { s->failed_pc=0x0c04da0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04da10;
P_0c04da10: /* original 8b02, guest PC 0x0c04da10 */
if(!s->budget--) { s->failed_pc=0x0c04da10u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04da18; }
goto P_0c04da12;
P_0c04da12: /* original 9064, guest PC 0x0c04da12 */
if(!s->budget--) { s->failed_pc=0x0c04da12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dadeu,2);
goto P_0c04da14;
P_0c04da14: /* original a096, guest PC 0x0c04da14 */
if(!s->budget--) { s->failed_pc=0x0c04da14u; return 0; }
goto P_0c04db44;
P_0c04da16: /* original 0009, guest PC 0x0c04da16 */
if(!s->budget--) { s->failed_pc=0x0c04da16u; return 0; }
goto P_0c04da18;
P_0c04da18: /* original d336, guest PC 0x0c04da18 */
if(!s->budget--) { s->failed_pc=0x0c04da18u; return 0; }
r[3]=read(ram,0x0c04daf4u,4);
goto P_0c04da1a;
P_0c04da1a: /* original 430b, guest PC 0x0c04da1a */
if(!s->budget--) { s->failed_pc=0x0c04da1au; return 0; }
target=r[3];
r[16]=0x0c04da1eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04da1eu) { target=s->pc; goto dispatch; }
goto P_0c04da1e;
P_0c04da1c: /* original 64e3, guest PC 0x0c04da1c */
if(!s->budget--) { s->failed_pc=0x0c04da1cu; return 0; }
r[4]=r[14];
goto P_0c04da1e;
P_0c04da1e: /* original 4011, guest PC 0x0c04da1e */
if(!s->budget--) { s->failed_pc=0x0c04da1eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04da20;
P_0c04da20: /* original 8902, guest PC 0x0c04da20 */
if(!s->budget--) { s->failed_pc=0x0c04da20u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04da28; }
goto P_0c04da22;
P_0c04da22: /* original 905d, guest PC 0x0c04da22 */
if(!s->budget--) { s->failed_pc=0x0c04da22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dae0u,2);
goto P_0c04da24;
P_0c04da24: /* original a08e, guest PC 0x0c04da24 */
if(!s->budget--) { s->failed_pc=0x0c04da24u; return 0; }
goto P_0c04db44;
P_0c04da26: /* original 0009, guest PC 0x0c04da26 */
if(!s->budget--) { s->failed_pc=0x0c04da26u; return 0; }
goto P_0c04da28;
P_0c04da28: /* original 53f1, guest PC 0x0c04da28 */
if(!s->budget--) { s->failed_pc=0x0c04da28u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c04da2a;
P_0c04da2a: /* original 5237, guest PC 0x0c04da2a */
if(!s->budget--) { s->failed_pc=0x0c04da2au; return 0; }
r[2]=read(ram,r[3]+28,4);
goto P_0c04da2c;
P_0c04da2c: /* original 512e, guest PC 0x0c04da2c */
if(!s->budget--) { s->failed_pc=0x0c04da2cu; return 0; }
r[1]=read(ram,r[2]+56,4);
goto P_0c04da2e;
P_0c04da2e: /* original 2118, guest PC 0x0c04da2e */
if(!s->budget--) { s->failed_pc=0x0c04da2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c04da30;
P_0c04da30: /* original 8928, guest PC 0x0c04da30 */
if(!s->budget--) { s->failed_pc=0x0c04da30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04da84; }
goto P_0c04da32;
P_0c04da32: /* original d331, guest PC 0x0c04da32 */
if(!s->budget--) { s->failed_pc=0x0c04da32u; return 0; }
r[3]=read(ram,0x0c04daf8u,4);
goto P_0c04da34;
P_0c04da34: /* original 65c3, guest PC 0x0c04da34 */
if(!s->budget--) { s->failed_pc=0x0c04da34u; return 0; }
r[5]=r[12];
goto P_0c04da36;
P_0c04da36: /* original 430b, guest PC 0x0c04da36 */
if(!s->budget--) { s->failed_pc=0x0c04da36u; return 0; }
target=r[3];
r[16]=0x0c04da3au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04da3au) { target=s->pc; goto dispatch; }
goto P_0c04da3a;
P_0c04da38: /* original 64e3, guest PC 0x0c04da38 */
if(!s->budget--) { s->failed_pc=0x0c04da38u; return 0; }
r[4]=r[14];
goto P_0c04da3a;
P_0c04da3a: /* original 4011, guest PC 0x0c04da3a */
if(!s->budget--) { s->failed_pc=0x0c04da3au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04da3c;
P_0c04da3c: /* original 8b22, guest PC 0x0c04da3c */
if(!s->budget--) { s->failed_pc=0x0c04da3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04da84; }
goto P_0c04da3e;
P_0c04da3e: /* original d32f, guest PC 0x0c04da3e */
if(!s->budget--) { s->failed_pc=0x0c04da3eu; return 0; }
r[3]=read(ram,0x0c04dafcu,4);
goto P_0c04da40;
P_0c04da40: /* original 66f3, guest PC 0x0c04da40 */
if(!s->budget--) { s->failed_pc=0x0c04da40u; return 0; }
r[6]=r[15];
goto P_0c04da42;
P_0c04da42: /* original 65c3, guest PC 0x0c04da42 */
if(!s->budget--) { s->failed_pc=0x0c04da42u; return 0; }
r[5]=r[12];
goto P_0c04da44;
P_0c04da44: /* original 760c, guest PC 0x0c04da44 */
if(!s->budget--) { s->failed_pc=0x0c04da44u; return 0; }
r[6]+=0x0000000cu;
goto P_0c04da46;
P_0c04da46: /* original 430b, guest PC 0x0c04da46 */
if(!s->budget--) { s->failed_pc=0x0c04da46u; return 0; }
target=r[3];
r[16]=0x0c04da4au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04da4au) { target=s->pc; goto dispatch; }
goto P_0c04da4a;
P_0c04da48: /* original 64e3, guest PC 0x0c04da48 */
if(!s->budget--) { s->failed_pc=0x0c04da48u; return 0; }
r[4]=r[14];
goto P_0c04da4a;
P_0c04da4a: /* original 4011, guest PC 0x0c04da4a */
if(!s->budget--) { s->failed_pc=0x0c04da4au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04da4c;
P_0c04da4c: /* original 8b02, guest PC 0x0c04da4c */
if(!s->budget--) { s->failed_pc=0x0c04da4cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04da54; }
goto P_0c04da4e;
P_0c04da4e: /* original 9048, guest PC 0x0c04da4e */
if(!s->budget--) { s->failed_pc=0x0c04da4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dae2u,2);
goto P_0c04da50;
P_0c04da50: /* original a078, guest PC 0x0c04da50 */
if(!s->budget--) { s->failed_pc=0x0c04da50u; return 0; }
goto P_0c04db44;
P_0c04da52: /* original 0009, guest PC 0x0c04da52 */
if(!s->budget--) { s->failed_pc=0x0c04da52u; return 0; }
goto P_0c04da54;
P_0c04da54: /* original d32a, guest PC 0x0c04da54 */
if(!s->budget--) { s->failed_pc=0x0c04da54u; return 0; }
r[3]=read(ram,0x0c04db00u,4);
goto P_0c04da56;
P_0c04da56: /* original 65f3, guest PC 0x0c04da56 */
if(!s->budget--) { s->failed_pc=0x0c04da56u; return 0; }
r[5]=r[15];
goto P_0c04da58;
P_0c04da58: /* original 750c, guest PC 0x0c04da58 */
if(!s->budget--) { s->failed_pc=0x0c04da58u; return 0; }
r[5]+=0x0000000cu;
goto P_0c04da5a;
P_0c04da5a: /* original 430b, guest PC 0x0c04da5a */
if(!s->budget--) { s->failed_pc=0x0c04da5au; return 0; }
target=r[3];
r[16]=0x0c04da5eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04da5eu) { target=s->pc; goto dispatch; }
goto P_0c04da5e;
P_0c04da5c: /* original 64e3, guest PC 0x0c04da5c */
if(!s->budget--) { s->failed_pc=0x0c04da5cu; return 0; }
r[4]=r[14];
goto P_0c04da5e;
P_0c04da5e: /* original 4011, guest PC 0x0c04da5e */
if(!s->budget--) { s->failed_pc=0x0c04da5eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04da60;
P_0c04da60: /* original 8b02, guest PC 0x0c04da60 */
if(!s->budget--) { s->failed_pc=0x0c04da60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04da68; }
goto P_0c04da62;
P_0c04da62: /* original 903f, guest PC 0x0c04da62 */
if(!s->budget--) { s->failed_pc=0x0c04da62u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dae4u,2);
goto P_0c04da64;
P_0c04da64: /* original a06e, guest PC 0x0c04da64 */
if(!s->budget--) { s->failed_pc=0x0c04da64u; return 0; }
goto P_0c04db44;
P_0c04da66: /* original 0009, guest PC 0x0c04da66 */
if(!s->budget--) { s->failed_pc=0x0c04da66u; return 0; }
goto P_0c04da68;
P_0c04da68: /* original d326, guest PC 0x0c04da68 */
if(!s->budget--) { s->failed_pc=0x0c04da68u; return 0; }
r[3]=read(ram,0x0c04db04u,4);
goto P_0c04da6a;
P_0c04da6a: /* original e500, guest PC 0x0c04da6a */
if(!s->budget--) { s->failed_pc=0x0c04da6au; return 0; }
r[5]=0x00000000u;
goto P_0c04da6c;
P_0c04da6c: /* original 430b, guest PC 0x0c04da6c */
if(!s->budget--) { s->failed_pc=0x0c04da6cu; return 0; }
target=r[3];
r[16]=0x0c04da70u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04da70u) { target=s->pc; goto dispatch; }
goto P_0c04da70;
P_0c04da6e: /* original 64e3, guest PC 0x0c04da6e */
if(!s->budget--) { s->failed_pc=0x0c04da6eu; return 0; }
r[4]=r[14];
goto P_0c04da70;
P_0c04da70: /* original d225, guest PC 0x0c04da70 */
if(!s->budget--) { s->failed_pc=0x0c04da70u; return 0; }
r[2]=read(ram,0x0c04db08u,4);
goto P_0c04da72;
P_0c04da72: /* original 600d, guest PC 0x0c04da72 */
if(!s->budget--) { s->failed_pc=0x0c04da72u; return 0; }
r[0]=r[0]&65535u;
goto P_0c04da74;
P_0c04da74: /* original 3020, guest PC 0x0c04da74 */
if(!s->budget--) { s->failed_pc=0x0c04da74u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[2])!=0);
goto P_0c04da76;
P_0c04da76: /* original 8b05, guest PC 0x0c04da76 */
if(!s->budget--) { s->failed_pc=0x0c04da76u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04da84; }
goto P_0c04da78;
P_0c04da78: /* original d324, guest PC 0x0c04da78 */
if(!s->budget--) { s->failed_pc=0x0c04da78u; return 0; }
r[3]=read(ram,0x0c04db0cu,4);
goto P_0c04da7a;
P_0c04da7a: /* original 430b, guest PC 0x0c04da7a */
if(!s->budget--) { s->failed_pc=0x0c04da7au; return 0; }
target=r[3];
r[16]=0x0c04da7eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04da7eu) { target=s->pc; goto dispatch; }
goto P_0c04da7e;
P_0c04da7c: /* original 64e3, guest PC 0x0c04da7c */
if(!s->budget--) { s->failed_pc=0x0c04da7cu; return 0; }
r[4]=r[14];
goto P_0c04da7e;
P_0c04da7e: /* original 6903, guest PC 0x0c04da7e */
if(!s->budget--) { s->failed_pc=0x0c04da7eu; return 0; }
r[9]=r[0];
goto P_0c04da80;
P_0c04da80: /* original 4911, guest PC 0x0c04da80 */
if(!s->budget--) { s->failed_pc=0x0c04da80u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=0)!=0);
goto P_0c04da82;
P_0c04da82: /* original 8902, guest PC 0x0c04da82 */
if(!s->budget--) { s->failed_pc=0x0c04da82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04da8a; }
goto P_0c04da84;
P_0c04da84: /* original 902f, guest PC 0x0c04da84 */
if(!s->budget--) { s->failed_pc=0x0c04da84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dae6u,2);
goto P_0c04da86;
P_0c04da86: /* original a05d, guest PC 0x0c04da86 */
if(!s->budget--) { s->failed_pc=0x0c04da86u; return 0; }
goto P_0c04db44;
P_0c04da88: /* original 0009, guest PC 0x0c04da88 */
if(!s->budget--) { s->failed_pc=0x0c04da88u; return 0; }
goto P_0c04da8a;
P_0c04da8a: /* original d321, guest PC 0x0c04da8a */
if(!s->budget--) { s->failed_pc=0x0c04da8au; return 0; }
r[3]=read(ram,0x0c04db10u,4);
goto P_0c04da8c;
P_0c04da8c: /* original 6593, guest PC 0x0c04da8c */
if(!s->budget--) { s->failed_pc=0x0c04da8cu; return 0; }
r[5]=r[9];
goto P_0c04da8e;
P_0c04da8e: /* original 430b, guest PC 0x0c04da8e */
if(!s->budget--) { s->failed_pc=0x0c04da8eu; return 0; }
target=r[3];
r[16]=0x0c04da92u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04da92u) { target=s->pc; goto dispatch; }
goto P_0c04da92;
P_0c04da90: /* original 64e3, guest PC 0x0c04da90 */
if(!s->budget--) { s->failed_pc=0x0c04da90u; return 0; }
r[4]=r[14];
goto P_0c04da92;
P_0c04da92: /* original d220, guest PC 0x0c04da92 */
if(!s->budget--) { s->failed_pc=0x0c04da92u; return 0; }
r[2]=read(ram,0x0c04db14u,4);
goto P_0c04da94;
P_0c04da94: /* original 420b, guest PC 0x0c04da94 */
if(!s->budget--) { s->failed_pc=0x0c04da94u; return 0; }
target=r[2];
r[16]=0x0c04da98u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04da98u) { target=s->pc; goto dispatch; }
goto P_0c04da98;
P_0c04da96: /* original 64e3, guest PC 0x0c04da96 */
if(!s->budget--) { s->failed_pc=0x0c04da96u; return 0; }
r[4]=r[14];
goto P_0c04da98;
P_0c04da98: /* original 6d03, guest PC 0x0c04da98 */
if(!s->budget--) { s->failed_pc=0x0c04da98u; return 0; }
r[13]=r[0];
goto P_0c04da9a;
P_0c04da9a: /* original 2dd8, guest PC 0x0c04da9a */
if(!s->budget--) { s->failed_pc=0x0c04da9au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c04da9c;
P_0c04da9c: /* original 8b02, guest PC 0x0c04da9c */
if(!s->budget--) { s->failed_pc=0x0c04da9cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04daa4; }
goto P_0c04da9e;
P_0c04da9e: /* original 9023, guest PC 0x0c04da9e */
if(!s->budget--) { s->failed_pc=0x0c04da9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dae8u,2);
goto P_0c04daa0;
P_0c04daa0: /* original a050, guest PC 0x0c04daa0 */
if(!s->budget--) { s->failed_pc=0x0c04daa0u; return 0; }
goto P_0c04db44;
P_0c04daa2: /* original 0009, guest PC 0x0c04daa2 */
if(!s->budget--) { s->failed_pc=0x0c04daa2u; return 0; }
goto P_0c04daa4;
P_0c04daa4: /* original e401, guest PC 0x0c04daa4 */
if(!s->budget--) { s->failed_pc=0x0c04daa4u; return 0; }
r[4]=0x00000001u;
goto P_0c04daa6;
P_0c04daa6: /* original e202, guest PC 0x0c04daa6 */
if(!s->budget--) { s->failed_pc=0x0c04daa6u; return 0; }
r[2]=0x00000002u;
goto P_0c04daa8;
P_0c04daa8: /* original 6043, guest PC 0x0c04daa8 */
if(!s->budget--) { s->failed_pc=0x0c04daa8u; return 0; }
r[0]=r[4];
goto P_0c04daaa;
P_0c04daaa: /* original 1d42, guest PC 0x0c04daaa */
if(!s->budget--) { s->failed_pc=0x0c04daaau; return 0; }
write(ram,r[13]+8,r[4],4);
goto P_0c04daac;
P_0c04daac: /* original 1d21, guest PC 0x0c04daac */
if(!s->budget--) { s->failed_pc=0x0c04daacu; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c04daae;
P_0c04daae: /* original 1d9b, guest PC 0x0c04daae */
if(!s->budget--) { s->failed_pc=0x0c04daaeu; return 0; }
write(ram,r[13]+44,r[9],4);
goto P_0c04dab0;
P_0c04dab0: /* original d319, guest PC 0x0c04dab0 */
if(!s->budget--) { s->failed_pc=0x0c04dab0u; return 0; }
r[3]=read(ram,0x0c04db18u,4);
goto P_0c04dab2;
P_0c04dab2: /* original 1d3e, guest PC 0x0c04dab2 */
if(!s->budget--) { s->failed_pc=0x0c04dab2u; return 0; }
write(ram,r[13]+56,r[3],4);
goto P_0c04dab4;
P_0c04dab4: /* original 1dbc, guest PC 0x0c04dab4 */
if(!s->budget--) { s->failed_pc=0x0c04dab4u; return 0; }
write(ram,r[13]+48,r[11],4);
goto P_0c04dab6;
P_0c04dab6: /* original 1dea, guest PC 0x0c04dab6 */
if(!s->budget--) { s->failed_pc=0x0c04dab6u; return 0; }
write(ram,r[13]+40,r[14],4);
goto P_0c04dab8;
P_0c04dab8: /* original 81d1, guest PC 0x0c04dab8 */
if(!s->budget--) { s->failed_pc=0x0c04dab8u; return 0; }
write(ram,r[13]+2,r[0],2);
goto P_0c04daba;
P_0c04daba: /* original 60b3, guest PC 0x0c04daba */
if(!s->budget--) { s->failed_pc=0x0c04dabau; return 0; }
r[0]=r[11];
goto P_0c04dabc;
P_0c04dabc: /* original 80d1, guest PC 0x0c04dabc */
if(!s->budget--) { s->failed_pc=0x0c04dabcu; return 0; }
write(ram,r[13]+1,r[0],1);
goto P_0c04dabe;
P_0c04dabe: /* original 53d1, guest PC 0x0c04dabe */
if(!s->budget--) { s->failed_pc=0x0c04dabeu; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c04dac0;
P_0c04dac0: /* original 2f36, guest PC 0x0c04dac0 */
if(!s->budget--) { s->failed_pc=0x0c04dac0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dac2;
P_0c04dac2: /* original d216, guest PC 0x0c04dac2 */
if(!s->budget--) { s->failed_pc=0x0c04dac2u; return 0; }
r[2]=read(ram,0x0c04db1cu,4);
goto P_0c04dac4;
P_0c04dac4: /* original d316, guest PC 0x0c04dac4 */
if(!s->budget--) { s->failed_pc=0x0c04dac4u; return 0; }
r[3]=read(ram,0x0c04db20u,4);
goto P_0c04dac6;
P_0c04dac6: /* original 430b, guest PC 0x0c04dac6 */
if(!s->budget--) { s->failed_pc=0x0c04dac6u; return 0; }
target=r[3];
r[16]=0x0c04dacau;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04dacau) { target=s->pc; goto dispatch; }
goto P_0c04daca;
P_0c04dac8: /* original 2f26, guest PC 0x0c04dac8 */
if(!s->budget--) { s->failed_pc=0x0c04dac8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04daca;
P_0c04daca: /* original 51db, guest PC 0x0c04daca */
if(!s->budget--) { s->failed_pc=0x0c04dacau; return 0; }
r[1]=read(ram,r[13]+44,4);
goto P_0c04dacc;
P_0c04dacc: /* original 2f16, guest PC 0x0c04dacc */
if(!s->budget--) { s->failed_pc=0x0c04daccu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dace;
P_0c04dace: /* original d315, guest PC 0x0c04dace */
if(!s->budget--) { s->failed_pc=0x0c04daceu; return 0; }
r[3]=read(ram,0x0c04db24u,4);
goto P_0c04dad0;
P_0c04dad0: /* original d213, guest PC 0x0c04dad0 */
if(!s->budget--) { s->failed_pc=0x0c04dad0u; return 0; }
r[2]=read(ram,0x0c04db20u,4);
goto P_0c04dad2;
P_0c04dad2: /* original 420b, guest PC 0x0c04dad2 */
if(!s->budget--) { s->failed_pc=0x0c04dad2u; return 0; }
target=r[2];
r[16]=0x0c04dad6u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04dad6u) { target=s->pc; goto dispatch; }
goto P_0c04dad6;
P_0c04dad4: /* original 2f36, guest PC 0x0c04dad4 */
if(!s->budget--) { s->failed_pc=0x0c04dad4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dad6;
P_0c04dad6: /* original 64d3, guest PC 0x0c04dad6 */
if(!s->budget--) { s->failed_pc=0x0c04dad6u; return 0; }
r[4]=r[13];
goto P_0c04dad8;
P_0c04dad8: /* original 7f10, guest PC 0x0c04dad8 */
if(!s->budget--) { s->failed_pc=0x0c04dad8u; return 0; }
r[15]+=0x00000010u;
goto P_0c04dada;
P_0c04dada: /* original a028, guest PC 0x0c04dada */
if(!s->budget--) { s->failed_pc=0x0c04dadau; return 0; }
r[4]+=0x00000010u;
goto P_0c04db2e;
P_0c04dadc: /* original 7410, guest PC 0x0c04dadc */
if(!s->budget--) { s->failed_pc=0x0c04dadcu; return 0; }
r[4]+=0x00000010u;
return vf3_matrix_family(0x0c04dadeu,s,ram);
P_0c04db28: /* original 63c4, guest PC 0x0c04db28 */
if(!s->budget--) { s->failed_pc=0x0c04db28u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[12]+=1;
r[3]=tmp;
goto P_0c04db2a;
P_0c04db2a: /* original 2430, guest PC 0x0c04db2a */
if(!s->budget--) { s->failed_pc=0x0c04db2au; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04db2c;
P_0c04db2c: /* original 7401, guest PC 0x0c04db2c */
if(!s->budget--) { s->failed_pc=0x0c04db2cu; return 0; }
r[4]+=0x00000001u;
goto P_0c04db2e;
P_0c04db2e: /* original 62c0, guest PC 0x0c04db2e */
if(!s->budget--) { s->failed_pc=0x0c04db2eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[2]=tmp;
goto P_0c04db30;
P_0c04db30: /* original 2228, guest PC 0x0c04db30 */
if(!s->budget--) { s->failed_pc=0x0c04db30u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04db32;
P_0c04db32: /* original 8bf9, guest PC 0x0c04db32 */
if(!s->budget--) { s->failed_pc=0x0c04db32u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04db28; }
goto P_0c04db34;
P_0c04db34: /* original 24b0, guest PC 0x0c04db34 */
if(!s->budget--) { s->failed_pc=0x0c04db34u; return 0; }
write(ram,r[4],r[11],1);
goto P_0c04db36;
P_0c04db36: /* original 64d3, guest PC 0x0c04db36 */
if(!s->budget--) { s->failed_pc=0x0c04db36u; return 0; }
r[4]=r[13];
goto P_0c04db38;
P_0c04db38: /* original d33a, guest PC 0x0c04db38 */
if(!s->budget--) { s->failed_pc=0x0c04db38u; return 0; }
r[3]=read(ram,0x0c04dc24u,4);
goto P_0c04db3a;
P_0c04db3a: /* original 65f2, guest PC 0x0c04db3a */
if(!s->budget--) { s->failed_pc=0x0c04db3au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04db3c;
P_0c04db3c: /* original 430b, guest PC 0x0c04db3c */
if(!s->budget--) { s->failed_pc=0x0c04db3cu; return 0; }
target=r[3];
r[16]=0x0c04db40u;
r[4]+=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04db40u) { target=s->pc; goto dispatch; }
goto P_0c04db40;
P_0c04db3e: /* original 7420, guest PC 0x0c04db3e */
if(!s->budget--) { s->failed_pc=0x0c04db3eu; return 0; }
r[4]+=0x00000020u;
goto P_0c04db40;
P_0c04db40: /* original e000, guest PC 0x0c04db40 */
if(!s->budget--) { s->failed_pc=0x0c04db40u; return 0; }
r[0]=0x00000000u;
goto P_0c04db42;
P_0c04db42: /* original 2ad2, guest PC 0x0c04db42 */
if(!s->budget--) { s->failed_pc=0x0c04db42u; return 0; }
write(ram,r[10],r[13],4);
goto P_0c04db44;
P_0c04db44: /* original 7f38, guest PC 0x0c04db44 */
if(!s->budget--) { s->failed_pc=0x0c04db44u; return 0; }
r[15]+=0x00000038u;
goto P_0c04db46;
P_0c04db46: /* original 4f16, guest PC 0x0c04db46 */
if(!s->budget--) { s->failed_pc=0x0c04db46u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04db48;
P_0c04db48: /* original 4f26, guest PC 0x0c04db48 */
if(!s->budget--) { s->failed_pc=0x0c04db48u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04db4a;
P_0c04db4a: /* original 69f6, guest PC 0x0c04db4a */
if(!s->budget--) { s->failed_pc=0x0c04db4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04db4c;
P_0c04db4c: /* original 6af6, guest PC 0x0c04db4c */
if(!s->budget--) { s->failed_pc=0x0c04db4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04db4e;
P_0c04db4e: /* original 6bf6, guest PC 0x0c04db4e */
if(!s->budget--) { s->failed_pc=0x0c04db4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04db50;
P_0c04db50: /* original 6cf6, guest PC 0x0c04db50 */
if(!s->budget--) { s->failed_pc=0x0c04db50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04db52;
P_0c04db52: /* original 6df6, guest PC 0x0c04db52 */
if(!s->budget--) { s->failed_pc=0x0c04db52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04db54;
P_0c04db54: /* original 000b, guest PC 0x0c04db54 */
if(!s->budget--) { s->failed_pc=0x0c04db54u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04db56: /* original 6ef6, guest PC 0x0c04db56 */
if(!s->budget--) { s->failed_pc=0x0c04db56u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04db58;
P_0c04db58: /* original 2fe6, guest PC 0x0c04db58 */
if(!s->budget--) { s->failed_pc=0x0c04db58u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db5a;
P_0c04db5a: /* original 2fd6, guest PC 0x0c04db5a */
if(!s->budget--) { s->failed_pc=0x0c04db5au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db5c;
P_0c04db5c: /* original 6d43, guest PC 0x0c04db5c */
if(!s->budget--) { s->failed_pc=0x0c04db5cu; return 0; }
r[13]=r[4];
goto P_0c04db5e;
P_0c04db5e: /* original 2fc6, guest PC 0x0c04db5e */
if(!s->budget--) { s->failed_pc=0x0c04db5eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db60;
P_0c04db60: /* original 6c53, guest PC 0x0c04db60 */
if(!s->budget--) { s->failed_pc=0x0c04db60u; return 0; }
r[12]=r[5];
goto P_0c04db62;
P_0c04db62: /* original 2fb6, guest PC 0x0c04db62 */
if(!s->budget--) { s->failed_pc=0x0c04db62u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db64;
P_0c04db64: /* original 2fa6, guest PC 0x0c04db64 */
if(!s->budget--) { s->failed_pc=0x0c04db64u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db66;
P_0c04db66: /* original 6a73, guest PC 0x0c04db66 */
if(!s->budget--) { s->failed_pc=0x0c04db66u; return 0; }
r[10]=r[7];
goto P_0c04db68;
P_0c04db68: /* original 2f96, guest PC 0x0c04db68 */
if(!s->budget--) { s->failed_pc=0x0c04db68u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db6a;
P_0c04db6a: /* original 4f22, guest PC 0x0c04db6a */
if(!s->budget--) { s->failed_pc=0x0c04db6au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04db6c;
P_0c04db6c: /* original 4f12, guest PC 0x0c04db6c */
if(!s->budget--) { s->failed_pc=0x0c04db6cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04db6e;
P_0c04db6e: /* original 7fd0, guest PC 0x0c04db6e */
if(!s->budget--) { s->failed_pc=0x0c04db6eu; return 0; }
r[15]+=0xffffffd0u;
goto P_0c04db70;
P_0c04db70: /* original 2f62, guest PC 0x0c04db70 */
if(!s->budget--) { s->failed_pc=0x0c04db70u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c04db72;
P_0c04db72: /* original 2f76, guest PC 0x0c04db72 */
if(!s->budget--) { s->failed_pc=0x0c04db72u; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db74;
P_0c04db74: /* original 53f1, guest PC 0x0c04db74 */
if(!s->budget--) { s->failed_pc=0x0c04db74u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c04db76;
P_0c04db76: /* original 2f36, guest PC 0x0c04db76 */
if(!s->budget--) { s->failed_pc=0x0c04db76u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db78;
P_0c04db78: /* original 2fc6, guest PC 0x0c04db78 */
if(!s->budget--) { s->failed_pc=0x0c04db78u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db7a;
P_0c04db7a: /* original 2fd6, guest PC 0x0c04db7a */
if(!s->budget--) { s->failed_pc=0x0c04db7au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db7c;
P_0c04db7c: /* original d22b, guest PC 0x0c04db7c */
if(!s->budget--) { s->failed_pc=0x0c04db7cu; return 0; }
r[2]=read(ram,0x0c04dc2cu,4);
goto P_0c04db7e;
P_0c04db7e: /* original d32a, guest PC 0x0c04db7e */
if(!s->budget--) { s->failed_pc=0x0c04db7eu; return 0; }
r[3]=read(ram,0x0c04dc28u,4);
goto P_0c04db80;
P_0c04db80: /* original 420b, guest PC 0x0c04db80 */
if(!s->budget--) { s->failed_pc=0x0c04db80u; return 0; }
target=r[2];
r[16]=0x0c04db84u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04db84u) { target=s->pc; goto dispatch; }
goto P_0c04db84;
P_0c04db82: /* original 2f36, guest PC 0x0c04db82 */
if(!s->budget--) { s->failed_pc=0x0c04db82u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04db84;
P_0c04db84: /* original eb00, guest PC 0x0c04db84 */
if(!s->budget--) { s->failed_pc=0x0c04db84u; return 0; }
r[11]=0x00000000u;
goto P_0c04db86;
P_0c04db86: /* original 2ab2, guest PC 0x0c04db86 */
if(!s->budget--) { s->failed_pc=0x0c04db86u; return 0; }
write(ram,r[10],r[11],4);
goto P_0c04db88;
P_0c04db88: /* original 9347, guest PC 0x0c04db88 */
if(!s->budget--) { s->failed_pc=0x0c04db88u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dc1au,2);
goto P_0c04db8a;
P_0c04db8a: /* original d029, guest PC 0x0c04db8a */
if(!s->budget--) { s->failed_pc=0x0c04db8au; return 0; }
r[0]=read(ram,0x0c04dc30u,4);
goto P_0c04db8c;
P_0c04db8c: /* original 2d3f, guest PC 0x0c04db8c */
if(!s->budget--) { s->failed_pc=0x0c04db8cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[3]);
goto P_0c04db8e;
P_0c04db8e: /* original 031a, guest PC 0x0c04db8e */
if(!s->budget--) { s->failed_pc=0x0c04db8eu; return 0; }
r[3]=r[19];
goto P_0c04db90;
P_0c04db90: /* original 633f, guest PC 0x0c04db90 */
if(!s->budget--) { s->failed_pc=0x0c04db90u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04db92;
P_0c04db92: /* original 023c, guest PC 0x0c04db92 */
if(!s->budget--) { s->failed_pc=0x0c04db92u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04db94;
P_0c04db94: /* original 2228, guest PC 0x0c04db94 */
if(!s->budget--) { s->failed_pc=0x0c04db94u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04db96;
P_0c04db96: /* original 8d16, guest PC 0x0c04db96 */
if(!s->budget--) { s->failed_pc=0x0c04db96u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000014u;
if(cond) { goto P_0c04dbc6; }
goto P_0c04db9a;
P_0c04db98: /* original 7f14, guest PC 0x0c04db98 */
if(!s->budget--) { s->failed_pc=0x0c04db98u; return 0; }
r[15]+=0x00000014u;
goto P_0c04db9a;
P_0c04db9a: /* original d326, guest PC 0x0c04db9a */
if(!s->budget--) { s->failed_pc=0x0c04db9au; return 0; }
r[3]=read(ram,0x0c04dc34u,4);
goto P_0c04db9c;
P_0c04db9c: /* original 430b, guest PC 0x0c04db9c */
if(!s->budget--) { s->failed_pc=0x0c04db9cu; return 0; }
target=r[3];
r[16]=0x0c04dba0u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04dba0u) { target=s->pc; goto dispatch; }
goto P_0c04dba0;
P_0c04db9e: /* original 64d3, guest PC 0x0c04db9e */
if(!s->budget--) { s->failed_pc=0x0c04db9eu; return 0; }
r[4]=r[13];
goto P_0c04dba0;
P_0c04dba0: /* original 2008, guest PC 0x0c04dba0 */
if(!s->budget--) { s->failed_pc=0x0c04dba0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04dba2;
P_0c04dba2: /* original 8b03, guest PC 0x0c04dba2 */
if(!s->budget--) { s->failed_pc=0x0c04dba2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04dbac; }
goto P_0c04dba4;
P_0c04dba4: /* original b993, guest PC 0x0c04dba4 */
if(!s->budget--) { s->failed_pc=0x0c04dba4u; return 0; }
target=0x0c04ceceu; r[16]=0x0c04dba8u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04dba8u) { target=s->pc; goto dispatch; }
goto P_0c04dba8;
P_0c04dba6: /* original 64d3, guest PC 0x0c04dba6 */
if(!s->budget--) { s->failed_pc=0x0c04dba6u; return 0; }
r[4]=r[13];
goto P_0c04dba8;
P_0c04dba8: /* original a00d, guest PC 0x0c04dba8 */
if(!s->budget--) { s->failed_pc=0x0c04dba8u; return 0; }
goto P_0c04dbc6;
P_0c04dbaa: /* original 0009, guest PC 0x0c04dbaa */
if(!s->budget--) { s->failed_pc=0x0c04dbaau; return 0; }
goto P_0c04dbac;
P_0c04dbac: /* original d222, guest PC 0x0c04dbac */
if(!s->budget--) { s->failed_pc=0x0c04dbacu; return 0; }
r[2]=read(ram,0x0c04dc38u,4);
goto P_0c04dbae;
P_0c04dbae: /* original 420b, guest PC 0x0c04dbae */
if(!s->budget--) { s->failed_pc=0x0c04dbaeu; return 0; }
target=r[2];
r[16]=0x0c04dbb2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04dbb2u) { target=s->pc; goto dispatch; }
goto P_0c04dbb2;
P_0c04dbb0: /* original 64d3, guest PC 0x0c04dbb0 */
if(!s->budget--) { s->failed_pc=0x0c04dbb0u; return 0; }
r[4]=r[13];
goto P_0c04dbb2;
P_0c04dbb2: /* original 2008, guest PC 0x0c04dbb2 */
if(!s->budget--) { s->failed_pc=0x0c04dbb2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04dbb4;
P_0c04dbb4: /* original 8907, guest PC 0x0c04dbb4 */
if(!s->budget--) { s->failed_pc=0x0c04dbb4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04dbc6; }
goto P_0c04dbb6;
P_0c04dbb6: /* original 9330, guest PC 0x0c04dbb6 */
if(!s->budget--) { s->failed_pc=0x0c04dbb6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dc1au,2);
goto P_0c04dbb8;
P_0c04dbb8: /* original d020, guest PC 0x0c04dbb8 */
if(!s->budget--) { s->failed_pc=0x0c04dbb8u; return 0; }
r[0]=read(ram,0x0c04dc3cu,4);
goto P_0c04dbba;
P_0c04dbba: /* original 2d3f, guest PC 0x0c04dbba */
if(!s->budget--) { s->failed_pc=0x0c04dbbau; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[3]);
goto P_0c04dbbc;
P_0c04dbbc: /* original 031a, guest PC 0x0c04dbbc */
if(!s->budget--) { s->failed_pc=0x0c04dbbcu; return 0; }
r[3]=r[19];
goto P_0c04dbbe;
P_0c04dbbe: /* original 633f, guest PC 0x0c04dbbe */
if(!s->budget--) { s->failed_pc=0x0c04dbbeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04dbc0;
P_0c04dbc0: /* original 023c, guest PC 0x0c04dbc0 */
if(!s->budget--) { s->failed_pc=0x0c04dbc0u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04dbc2;
P_0c04dbc2: /* original 2228, guest PC 0x0c04dbc2 */
if(!s->budget--) { s->failed_pc=0x0c04dbc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04dbc4;
P_0c04dbc4: /* original 8b02, guest PC 0x0c04dbc4 */
if(!s->budget--) { s->failed_pc=0x0c04dbc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04dbcc; }
goto P_0c04dbc6;
P_0c04dbc6: /* original 9029, guest PC 0x0c04dbc6 */
if(!s->budget--) { s->failed_pc=0x0c04dbc6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dc1cu,2);
goto P_0c04dbc8;
P_0c04dbc8: /* original a078, guest PC 0x0c04dbc8 */
if(!s->budget--) { s->failed_pc=0x0c04dbc8u; return 0; }
goto P_0c04dcbc;
P_0c04dbca: /* original 0009, guest PC 0x0c04dbca */
if(!s->budget--) { s->failed_pc=0x0c04dbcau; return 0; }
goto P_0c04dbcc;
P_0c04dbcc: /* original d31c, guest PC 0x0c04dbcc */
if(!s->budget--) { s->failed_pc=0x0c04dbccu; return 0; }
r[3]=read(ram,0x0c04dc40u,4);
goto P_0c04dbce;
P_0c04dbce: /* original 430b, guest PC 0x0c04dbce */
if(!s->budget--) { s->failed_pc=0x0c04dbceu; return 0; }
target=r[3];
r[16]=0x0c04dbd2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04dbd2u) { target=s->pc; goto dispatch; }
goto P_0c04dbd2;
P_0c04dbd0: /* original 64d3, guest PC 0x0c04dbd0 */
if(!s->budget--) { s->failed_pc=0x0c04dbd0u; return 0; }
r[4]=r[13];
goto P_0c04dbd2;
P_0c04dbd2: /* original 4011, guest PC 0x0c04dbd2 */
if(!s->budget--) { s->failed_pc=0x0c04dbd2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04dbd4;
P_0c04dbd4: /* original 8902, guest PC 0x0c04dbd4 */
if(!s->budget--) { s->failed_pc=0x0c04dbd4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04dbdc; }
goto P_0c04dbd6;
P_0c04dbd6: /* original 9022, guest PC 0x0c04dbd6 */
if(!s->budget--) { s->failed_pc=0x0c04dbd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dc1eu,2);
goto P_0c04dbd8;
P_0c04dbd8: /* original a070, guest PC 0x0c04dbd8 */
if(!s->budget--) { s->failed_pc=0x0c04dbd8u; return 0; }
goto P_0c04dcbc;
P_0c04dbda: /* original 0009, guest PC 0x0c04dbda */
if(!s->budget--) { s->failed_pc=0x0c04dbdau; return 0; }
goto P_0c04dbdc;
P_0c04dbdc: /* original d319, guest PC 0x0c04dbdc */
if(!s->budget--) { s->failed_pc=0x0c04dbdcu; return 0; }
r[3]=read(ram,0x0c04dc44u,4);
goto P_0c04dbde;
P_0c04dbde: /* original 65c3, guest PC 0x0c04dbde */
if(!s->budget--) { s->failed_pc=0x0c04dbdeu; return 0; }
r[5]=r[12];
goto P_0c04dbe0;
P_0c04dbe0: /* original 430b, guest PC 0x0c04dbe0 */
if(!s->budget--) { s->failed_pc=0x0c04dbe0u; return 0; }
target=r[3];
r[16]=0x0c04dbe4u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04dbe4u) { target=s->pc; goto dispatch; }
goto P_0c04dbe4;
P_0c04dbe2: /* original 64d3, guest PC 0x0c04dbe2 */
if(!s->budget--) { s->failed_pc=0x0c04dbe2u; return 0; }
r[4]=r[13];
goto P_0c04dbe4;
P_0c04dbe4: /* original 4011, guest PC 0x0c04dbe4 */
if(!s->budget--) { s->failed_pc=0x0c04dbe4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04dbe6;
P_0c04dbe6: /* original 8b15, guest PC 0x0c04dbe6 */
if(!s->budget--) { s->failed_pc=0x0c04dbe6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04dc14; }
goto P_0c04dbe8;
P_0c04dbe8: /* original d217, guest PC 0x0c04dbe8 */
if(!s->budget--) { s->failed_pc=0x0c04dbe8u; return 0; }
r[2]=read(ram,0x0c04dc48u,4);
goto P_0c04dbea;
P_0c04dbea: /* original 66f3, guest PC 0x0c04dbea */
if(!s->budget--) { s->failed_pc=0x0c04dbeau; return 0; }
r[6]=r[15];
goto P_0c04dbec;
P_0c04dbec: /* original 65c3, guest PC 0x0c04dbec */
if(!s->budget--) { s->failed_pc=0x0c04dbecu; return 0; }
r[5]=r[12];
goto P_0c04dbee;
P_0c04dbee: /* original 7604, guest PC 0x0c04dbee */
if(!s->budget--) { s->failed_pc=0x0c04dbeeu; return 0; }
r[6]+=0x00000004u;
goto P_0c04dbf0;
P_0c04dbf0: /* original 420b, guest PC 0x0c04dbf0 */
if(!s->budget--) { s->failed_pc=0x0c04dbf0u; return 0; }
target=r[2];
r[16]=0x0c04dbf4u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04dbf4u) { target=s->pc; goto dispatch; }
goto P_0c04dbf4;
P_0c04dbf2: /* original 64d3, guest PC 0x0c04dbf2 */
if(!s->budget--) { s->failed_pc=0x0c04dbf2u; return 0; }
r[4]=r[13];
goto P_0c04dbf4;
P_0c04dbf4: /* original 4011, guest PC 0x0c04dbf4 */
if(!s->budget--) { s->failed_pc=0x0c04dbf4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04dbf6;
P_0c04dbf6: /* original 8b07, guest PC 0x0c04dbf6 */
if(!s->budget--) { s->failed_pc=0x0c04dbf6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04dc08; }
goto P_0c04dbf8;
P_0c04dbf8: /* original 65c3, guest PC 0x0c04dbf8 */
if(!s->budget--) { s->failed_pc=0x0c04dbf8u; return 0; }
r[5]=r[12];
goto P_0c04dbfa;
P_0c04dbfa: /* original b58a, guest PC 0x0c04dbfa */
if(!s->budget--) { s->failed_pc=0x0c04dbfau; return 0; }
target=0x0c04e712u; r[16]=0x0c04dbfeu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04dbfeu) { target=s->pc; goto dispatch; }
goto P_0c04dbfe;
P_0c04dbfc: /* original 64d3, guest PC 0x0c04dbfc */
if(!s->budget--) { s->failed_pc=0x0c04dbfcu; return 0; }
r[4]=r[13];
goto P_0c04dbfe;
P_0c04dbfe: /* original 4011, guest PC 0x0c04dbfe */
if(!s->budget--) { s->failed_pc=0x0c04dbfeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04dc00;
P_0c04dc00: /* original 8d02, guest PC 0x0c04dc00 */
if(!s->budget--) { s->failed_pc=0x0c04dc00u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c04dc08; }
goto P_0c04dc04;
P_0c04dc02: /* original 6403, guest PC 0x0c04dc02 */
if(!s->budget--) { s->failed_pc=0x0c04dc02u; return 0; }
r[4]=r[0];
goto P_0c04dc04;
P_0c04dc04: /* original a05a, guest PC 0x0c04dc04 */
if(!s->budget--) { s->failed_pc=0x0c04dc04u; return 0; }
r[0]=r[4];
goto P_0c04dcbc;
P_0c04dc06: /* original 6043, guest PC 0x0c04dc06 */
if(!s->budget--) { s->failed_pc=0x0c04dc06u; return 0; }
r[0]=r[4];
goto P_0c04dc08;
P_0c04dc08: /* original d210, guest PC 0x0c04dc08 */
if(!s->budget--) { s->failed_pc=0x0c04dc08u; return 0; }
r[2]=read(ram,0x0c04dc4cu,4);
goto P_0c04dc0a;
P_0c04dc0a: /* original 420b, guest PC 0x0c04dc0a */
if(!s->budget--) { s->failed_pc=0x0c04dc0au; return 0; }
target=r[2];
r[16]=0x0c04dc0eu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04dc0eu) { target=s->pc; goto dispatch; }
goto P_0c04dc0e;
P_0c04dc0c: /* original 64d3, guest PC 0x0c04dc0c */
if(!s->budget--) { s->failed_pc=0x0c04dc0cu; return 0; }
r[4]=r[13];
goto P_0c04dc0e;
P_0c04dc0e: /* original 6903, guest PC 0x0c04dc0e */
if(!s->budget--) { s->failed_pc=0x0c04dc0eu; return 0; }
r[9]=r[0];
goto P_0c04dc10;
P_0c04dc10: /* original 4911, guest PC 0x0c04dc10 */
if(!s->budget--) { s->failed_pc=0x0c04dc10u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=0)!=0);
goto P_0c04dc12;
P_0c04dc12: /* original 891d, guest PC 0x0c04dc12 */
if(!s->budget--) { s->failed_pc=0x0c04dc12u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04dc50; }
goto P_0c04dc14;
P_0c04dc14: /* original 9004, guest PC 0x0c04dc14 */
if(!s->budget--) { s->failed_pc=0x0c04dc14u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dc20u,2);
goto P_0c04dc16;
P_0c04dc16: /* original a051, guest PC 0x0c04dc16 */
if(!s->budget--) { s->failed_pc=0x0c04dc16u; return 0; }
goto P_0c04dcbc;
P_0c04dc18: /* original 0009, guest PC 0x0c04dc18 */
if(!s->budget--) { s->failed_pc=0x0c04dc18u; return 0; }
return vf3_matrix_family(0x0c04dc1au,s,ram);
P_0c04dc50: /* original d240, guest PC 0x0c04dc50 */
if(!s->budget--) { s->failed_pc=0x0c04dc50u; return 0; }
r[2]=read(ram,0x0c04dd54u,4);
goto P_0c04dc52;
P_0c04dc52: /* original 6593, guest PC 0x0c04dc52 */
if(!s->budget--) { s->failed_pc=0x0c04dc52u; return 0; }
r[5]=r[9];
goto P_0c04dc54;
P_0c04dc54: /* original 420b, guest PC 0x0c04dc54 */
if(!s->budget--) { s->failed_pc=0x0c04dc54u; return 0; }
target=r[2];
r[16]=0x0c04dc58u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04dc58u) { target=s->pc; goto dispatch; }
goto P_0c04dc58;
P_0c04dc56: /* original 64d3, guest PC 0x0c04dc56 */
if(!s->budget--) { s->failed_pc=0x0c04dc56u; return 0; }
r[4]=r[13];
goto P_0c04dc58;
P_0c04dc58: /* original d33f, guest PC 0x0c04dc58 */
if(!s->budget--) { s->failed_pc=0x0c04dc58u; return 0; }
r[3]=read(ram,0x0c04dd58u,4);
goto P_0c04dc5a;
P_0c04dc5a: /* original 430b, guest PC 0x0c04dc5a */
if(!s->budget--) { s->failed_pc=0x0c04dc5au; return 0; }
target=r[3];
r[16]=0x0c04dc5eu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04dc5eu) { target=s->pc; goto dispatch; }
goto P_0c04dc5e;
P_0c04dc5c: /* original 64d3, guest PC 0x0c04dc5c */
if(!s->budget--) { s->failed_pc=0x0c04dc5cu; return 0; }
r[4]=r[13];
goto P_0c04dc5e;
P_0c04dc5e: /* original 6e03, guest PC 0x0c04dc5e */
if(!s->budget--) { s->failed_pc=0x0c04dc5eu; return 0; }
r[14]=r[0];
goto P_0c04dc60;
P_0c04dc60: /* original 2ee8, guest PC 0x0c04dc60 */
if(!s->budget--) { s->failed_pc=0x0c04dc60u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c04dc62;
P_0c04dc62: /* original 8b02, guest PC 0x0c04dc62 */
if(!s->budget--) { s->failed_pc=0x0c04dc62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04dc6a; }
goto P_0c04dc64;
P_0c04dc64: /* original 9071, guest PC 0x0c04dc64 */
if(!s->budget--) { s->failed_pc=0x0c04dc64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dd4au,2);
goto P_0c04dc66;
P_0c04dc66: /* original a029, guest PC 0x0c04dc66 */
if(!s->budget--) { s->failed_pc=0x0c04dc66u; return 0; }
goto P_0c04dcbc;
P_0c04dc68: /* original 0009, guest PC 0x0c04dc68 */
if(!s->budget--) { s->failed_pc=0x0c04dc68u; return 0; }
goto P_0c04dc6a;
P_0c04dc6a: /* original e301, guest PC 0x0c04dc6a */
if(!s->budget--) { s->failed_pc=0x0c04dc6au; return 0; }
r[3]=0x00000001u;
goto P_0c04dc6c;
P_0c04dc6c: /* original 60b3, guest PC 0x0c04dc6c */
if(!s->budget--) { s->failed_pc=0x0c04dc6cu; return 0; }
r[0]=r[11];
goto P_0c04dc6e;
P_0c04dc6e: /* original 1eb2, guest PC 0x0c04dc6e */
if(!s->budget--) { s->failed_pc=0x0c04dc6eu; return 0; }
write(ram,r[14]+8,r[11],4);
goto P_0c04dc70;
P_0c04dc70: /* original 1e31, guest PC 0x0c04dc70 */
if(!s->budget--) { s->failed_pc=0x0c04dc70u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c04dc72;
P_0c04dc72: /* original 1e9b, guest PC 0x0c04dc72 */
if(!s->budget--) { s->failed_pc=0x0c04dc72u; return 0; }
write(ram,r[14]+44,r[9],4);
goto P_0c04dc74;
P_0c04dc74: /* original d239, guest PC 0x0c04dc74 */
if(!s->budget--) { s->failed_pc=0x0c04dc74u; return 0; }
r[2]=read(ram,0x0c04dd5cu,4);
goto P_0c04dc76;
P_0c04dc76: /* original 1e2e, guest PC 0x0c04dc76 */
if(!s->budget--) { s->failed_pc=0x0c04dc76u; return 0; }
write(ram,r[14]+56,r[2],4);
goto P_0c04dc78;
P_0c04dc78: /* original 1ebc, guest PC 0x0c04dc78 */
if(!s->budget--) { s->failed_pc=0x0c04dc78u; return 0; }
write(ram,r[14]+48,r[11],4);
goto P_0c04dc7a;
P_0c04dc7a: /* original 1eda, guest PC 0x0c04dc7a */
if(!s->budget--) { s->failed_pc=0x0c04dc7au; return 0; }
write(ram,r[14]+40,r[13],4);
goto P_0c04dc7c;
P_0c04dc7c: /* original 81e1, guest PC 0x0c04dc7c */
if(!s->budget--) { s->failed_pc=0x0c04dc7cu; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c04dc7e;
P_0c04dc7e: /* original 80e1, guest PC 0x0c04dc7e */
if(!s->budget--) { s->failed_pc=0x0c04dc7eu; return 0; }
write(ram,r[14]+1,r[0],1);
goto P_0c04dc80;
P_0c04dc80: /* original 53e1, guest PC 0x0c04dc80 */
if(!s->budget--) { s->failed_pc=0x0c04dc80u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c04dc82;
P_0c04dc82: /* original 2f36, guest PC 0x0c04dc82 */
if(!s->budget--) { s->failed_pc=0x0c04dc82u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dc84;
P_0c04dc84: /* original d337, guest PC 0x0c04dc84 */
if(!s->budget--) { s->failed_pc=0x0c04dc84u; return 0; }
r[3]=read(ram,0x0c04dd64u,4);
goto P_0c04dc86;
P_0c04dc86: /* original d236, guest PC 0x0c04dc86 */
if(!s->budget--) { s->failed_pc=0x0c04dc86u; return 0; }
r[2]=read(ram,0x0c04dd60u,4);
goto P_0c04dc88;
P_0c04dc88: /* original 430b, guest PC 0x0c04dc88 */
if(!s->budget--) { s->failed_pc=0x0c04dc88u; return 0; }
target=r[3];
r[16]=0x0c04dc8cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04dc8cu) { target=s->pc; goto dispatch; }
goto P_0c04dc8c;
P_0c04dc8a: /* original 2f26, guest PC 0x0c04dc8a */
if(!s->budget--) { s->failed_pc=0x0c04dc8au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dc8c;
P_0c04dc8c: /* original 51eb, guest PC 0x0c04dc8c */
if(!s->budget--) { s->failed_pc=0x0c04dc8cu; return 0; }
r[1]=read(ram,r[14]+44,4);
goto P_0c04dc8e;
P_0c04dc8e: /* original 2f16, guest PC 0x0c04dc8e */
if(!s->budget--) { s->failed_pc=0x0c04dc8eu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dc90;
P_0c04dc90: /* original d335, guest PC 0x0c04dc90 */
if(!s->budget--) { s->failed_pc=0x0c04dc90u; return 0; }
r[3]=read(ram,0x0c04dd68u,4);
goto P_0c04dc92;
P_0c04dc92: /* original d234, guest PC 0x0c04dc92 */
if(!s->budget--) { s->failed_pc=0x0c04dc92u; return 0; }
r[2]=read(ram,0x0c04dd64u,4);
goto P_0c04dc94;
P_0c04dc94: /* original 420b, guest PC 0x0c04dc94 */
if(!s->budget--) { s->failed_pc=0x0c04dc94u; return 0; }
target=r[2];
r[16]=0x0c04dc98u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04dc98u) { target=s->pc; goto dispatch; }
goto P_0c04dc98;
P_0c04dc96: /* original 2f36, guest PC 0x0c04dc96 */
if(!s->budget--) { s->failed_pc=0x0c04dc96u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04dc98;
P_0c04dc98: /* original 64e3, guest PC 0x0c04dc98 */
if(!s->budget--) { s->failed_pc=0x0c04dc98u; return 0; }
r[4]=r[14];
goto P_0c04dc9a;
P_0c04dc9a: /* original 7f10, guest PC 0x0c04dc9a */
if(!s->budget--) { s->failed_pc=0x0c04dc9au; return 0; }
r[15]+=0x00000010u;
goto P_0c04dc9c;
P_0c04dc9c: /* original a003, guest PC 0x0c04dc9c */
if(!s->budget--) { s->failed_pc=0x0c04dc9cu; return 0; }
r[4]+=0x00000010u;
goto P_0c04dca6;
P_0c04dc9e: /* original 7410, guest PC 0x0c04dc9e */
if(!s->budget--) { s->failed_pc=0x0c04dc9eu; return 0; }
r[4]+=0x00000010u;
goto P_0c04dca0;
P_0c04dca0: /* original 63c4, guest PC 0x0c04dca0 */
if(!s->budget--) { s->failed_pc=0x0c04dca0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[12]+=1;
r[3]=tmp;
goto P_0c04dca2;
P_0c04dca2: /* original 2430, guest PC 0x0c04dca2 */
if(!s->budget--) { s->failed_pc=0x0c04dca2u; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04dca4;
P_0c04dca4: /* original 7401, guest PC 0x0c04dca4 */
if(!s->budget--) { s->failed_pc=0x0c04dca4u; return 0; }
r[4]+=0x00000001u;
goto P_0c04dca6;
P_0c04dca6: /* original 62c0, guest PC 0x0c04dca6 */
if(!s->budget--) { s->failed_pc=0x0c04dca6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[2]=tmp;
goto P_0c04dca8;
P_0c04dca8: /* original 2228, guest PC 0x0c04dca8 */
if(!s->budget--) { s->failed_pc=0x0c04dca8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04dcaa;
P_0c04dcaa: /* original 8bf9, guest PC 0x0c04dcaa */
if(!s->budget--) { s->failed_pc=0x0c04dcaau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04dca0; }
goto P_0c04dcac;
P_0c04dcac: /* original 24b0, guest PC 0x0c04dcac */
if(!s->budget--) { s->failed_pc=0x0c04dcacu; return 0; }
write(ram,r[4],r[11],1);
goto P_0c04dcae;
P_0c04dcae: /* original 64e3, guest PC 0x0c04dcae */
if(!s->budget--) { s->failed_pc=0x0c04dcaeu; return 0; }
r[4]=r[14];
goto P_0c04dcb0;
P_0c04dcb0: /* original d32e, guest PC 0x0c04dcb0 */
if(!s->budget--) { s->failed_pc=0x0c04dcb0u; return 0; }
r[3]=read(ram,0x0c04dd6cu,4);
goto P_0c04dcb2;
P_0c04dcb2: /* original 65f2, guest PC 0x0c04dcb2 */
if(!s->budget--) { s->failed_pc=0x0c04dcb2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04dcb4;
P_0c04dcb4: /* original 430b, guest PC 0x0c04dcb4 */
if(!s->budget--) { s->failed_pc=0x0c04dcb4u; return 0; }
target=r[3];
r[16]=0x0c04dcb8u;
r[4]+=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04dcb8u) { target=s->pc; goto dispatch; }
goto P_0c04dcb8;
P_0c04dcb6: /* original 7420, guest PC 0x0c04dcb6 */
if(!s->budget--) { s->failed_pc=0x0c04dcb6u; return 0; }
r[4]+=0x00000020u;
goto P_0c04dcb8;
P_0c04dcb8: /* original e000, guest PC 0x0c04dcb8 */
if(!s->budget--) { s->failed_pc=0x0c04dcb8u; return 0; }
r[0]=0x00000000u;
goto P_0c04dcba;
P_0c04dcba: /* original 2ae2, guest PC 0x0c04dcba */
if(!s->budget--) { s->failed_pc=0x0c04dcbau; return 0; }
write(ram,r[10],r[14],4);
goto P_0c04dcbc;
P_0c04dcbc: /* original 7f30, guest PC 0x0c04dcbc */
if(!s->budget--) { s->failed_pc=0x0c04dcbcu; return 0; }
r[15]+=0x00000030u;
goto P_0c04dcbe;
P_0c04dcbe: /* original 4f16, guest PC 0x0c04dcbe */
if(!s->budget--) { s->failed_pc=0x0c04dcbeu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04dcc0;
P_0c04dcc0: /* original 4f26, guest PC 0x0c04dcc0 */
if(!s->budget--) { s->failed_pc=0x0c04dcc0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04dcc2;
P_0c04dcc2: /* original 69f6, guest PC 0x0c04dcc2 */
if(!s->budget--) { s->failed_pc=0x0c04dcc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04dcc4;
P_0c04dcc4: /* original 6af6, guest PC 0x0c04dcc4 */
if(!s->budget--) { s->failed_pc=0x0c04dcc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04dcc6;
P_0c04dcc6: /* original 6bf6, guest PC 0x0c04dcc6 */
if(!s->budget--) { s->failed_pc=0x0c04dcc6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04dcc8;
P_0c04dcc8: /* original 6cf6, guest PC 0x0c04dcc8 */
if(!s->budget--) { s->failed_pc=0x0c04dcc8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04dcca;
P_0c04dcca: /* original 6df6, guest PC 0x0c04dcca */
if(!s->budget--) { s->failed_pc=0x0c04dccau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04dccc;
P_0c04dccc: /* original 000b, guest PC 0x0c04dccc */
if(!s->budget--) { s->failed_pc=0x0c04dcccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04dcce: /* original 6ef6, guest PC 0x0c04dcce */
if(!s->budget--) { s->failed_pc=0x0c04dcceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04dcd0u,s,ram);
P_0c04e40e: /* original 2fe6, guest PC 0x0c04e40e */
if(!s->budget--) { s->failed_pc=0x0c04e40eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e410;
P_0c04e410: /* original 6e43, guest PC 0x0c04e410 */
if(!s->budget--) { s->failed_pc=0x0c04e410u; return 0; }
r[14]=r[4];
return vf3_matrix_family(0x0c04e412u,s,ram);
P_0c04e712: /* original 2fe6, guest PC 0x0c04e712 */
if(!s->budget--) { s->failed_pc=0x0c04e712u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e714;
P_0c04e714: /* original 6e43, guest PC 0x0c04e714 */
if(!s->budget--) { s->failed_pc=0x0c04e714u; return 0; }
r[14]=r[4];
goto P_0c04e716;
P_0c04e716: /* original 2fd6, guest PC 0x0c04e716 */
if(!s->budget--) { s->failed_pc=0x0c04e716u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e718;
P_0c04e718: /* original 6d53, guest PC 0x0c04e718 */
if(!s->budget--) { s->failed_pc=0x0c04e718u; return 0; }
r[13]=r[5];
goto P_0c04e71a;
P_0c04e71a: /* original 2fc6, guest PC 0x0c04e71a */
if(!s->budget--) { s->failed_pc=0x0c04e71au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e71c;
P_0c04e71c: /* original 2fb6, guest PC 0x0c04e71c */
if(!s->budget--) { s->failed_pc=0x0c04e71cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e71e;
P_0c04e71e: /* original 2fa6, guest PC 0x0c04e71e */
if(!s->budget--) { s->failed_pc=0x0c04e71eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e720;
P_0c04e720: /* original 2f96, guest PC 0x0c04e720 */
if(!s->budget--) { s->failed_pc=0x0c04e720u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e722;
P_0c04e722: /* original 4f22, guest PC 0x0c04e722 */
if(!s->budget--) { s->failed_pc=0x0c04e722u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04e724;
P_0c04e724: /* original 7fd0, guest PC 0x0c04e724 */
if(!s->budget--) { s->failed_pc=0x0c04e724u; return 0; }
r[15]+=0xffffffd0u;
goto P_0c04e726;
P_0c04e726: /* original 2f56, guest PC 0x0c04e726 */
if(!s->budget--) { s->failed_pc=0x0c04e726u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e728;
P_0c04e728: /* original 2fe6, guest PC 0x0c04e728 */
if(!s->budget--) { s->failed_pc=0x0c04e728u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e72a;
P_0c04e72a: /* original d322, guest PC 0x0c04e72a */
if(!s->budget--) { s->failed_pc=0x0c04e72au; return 0; }
r[3]=read(ram,0x0c04e7b4u,4);
goto P_0c04e72c;
P_0c04e72c: /* original d222, guest PC 0x0c04e72c */
if(!s->budget--) { s->failed_pc=0x0c04e72cu; return 0; }
r[2]=read(ram,0x0c04e7b8u,4);
goto P_0c04e72e;
P_0c04e72e: /* original 420b, guest PC 0x0c04e72e */
if(!s->budget--) { s->failed_pc=0x0c04e72eu; return 0; }
target=r[2];
r[16]=0x0c04e732u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e732u) { target=s->pc; goto dispatch; }
goto P_0c04e732;
P_0c04e730: /* original 2f36, guest PC 0x0c04e730 */
if(!s->budget--) { s->failed_pc=0x0c04e730u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e732;
P_0c04e732: /* original 7f0c, guest PC 0x0c04e732 */
if(!s->budget--) { s->failed_pc=0x0c04e732u; return 0; }
r[15]+=0x0000000cu;
goto P_0c04e734;
P_0c04e734: /* original d321, guest PC 0x0c04e734 */
if(!s->budget--) { s->failed_pc=0x0c04e734u; return 0; }
r[3]=read(ram,0x0c04e7bcu,4);
goto P_0c04e736;
P_0c04e736: /* original 66f3, guest PC 0x0c04e736 */
if(!s->budget--) { s->failed_pc=0x0c04e736u; return 0; }
r[6]=r[15];
goto P_0c04e738;
P_0c04e738: /* original 65d3, guest PC 0x0c04e738 */
if(!s->budget--) { s->failed_pc=0x0c04e738u; return 0; }
r[5]=r[13];
goto P_0c04e73a;
P_0c04e73a: /* original 7604, guest PC 0x0c04e73a */
if(!s->budget--) { s->failed_pc=0x0c04e73au; return 0; }
r[6]+=0x00000004u;
goto P_0c04e73c;
P_0c04e73c: /* original 430b, guest PC 0x0c04e73c */
if(!s->budget--) { s->failed_pc=0x0c04e73cu; return 0; }
target=r[3];
r[16]=0x0c04e740u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e740u) { target=s->pc; goto dispatch; }
goto P_0c04e740;
P_0c04e73e: /* original 64e3, guest PC 0x0c04e73e */
if(!s->budget--) { s->failed_pc=0x0c04e73eu; return 0; }
r[4]=r[14];
goto P_0c04e740;
P_0c04e740: /* original 6c03, guest PC 0x0c04e740 */
if(!s->budget--) { s->failed_pc=0x0c04e740u; return 0; }
r[12]=r[0];
goto P_0c04e742;
P_0c04e742: /* original 4c11, guest PC 0x0c04e742 */
if(!s->budget--) { s->failed_pc=0x0c04e742u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=0)!=0);
goto P_0c04e744;
P_0c04e744: /* original 8902, guest PC 0x0c04e744 */
if(!s->budget--) { s->failed_pc=0x0c04e744u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e74c; }
goto P_0c04e746;
P_0c04e746: /* original 9033, guest PC 0x0c04e746 */
if(!s->budget--) { s->failed_pc=0x0c04e746u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e7b0u,2);
goto P_0c04e748;
P_0c04e748: /* original a028, guest PC 0x0c04e748 */
if(!s->budget--) { s->failed_pc=0x0c04e748u; return 0; }
goto P_0c04e79c;
P_0c04e74a: /* original 0009, guest PC 0x0c04e74a */
if(!s->budget--) { s->failed_pc=0x0c04e74au; return 0; }
goto P_0c04e74c;
P_0c04e74c: /* original d31c, guest PC 0x0c04e74c */
if(!s->budget--) { s->failed_pc=0x0c04e74cu; return 0; }
r[3]=read(ram,0x0c04e7c0u,4);
goto P_0c04e74e;
P_0c04e74e: /* original 65c3, guest PC 0x0c04e74e */
if(!s->budget--) { s->failed_pc=0x0c04e74eu; return 0; }
r[5]=r[12];
goto P_0c04e750;
P_0c04e750: /* original 430b, guest PC 0x0c04e750 */
if(!s->budget--) { s->failed_pc=0x0c04e750u; return 0; }
target=r[3];
r[16]=0x0c04e754u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e754u) { target=s->pc; goto dispatch; }
goto P_0c04e754;
P_0c04e752: /* original 64e3, guest PC 0x0c04e752 */
if(!s->budget--) { s->failed_pc=0x0c04e752u; return 0; }
r[4]=r[14];
goto P_0c04e754;
P_0c04e754: /* original 65d3, guest PC 0x0c04e754 */
if(!s->budget--) { s->failed_pc=0x0c04e754u; return 0; }
r[5]=r[13];
goto P_0c04e756;
P_0c04e756: /* original 2f02, guest PC 0x0c04e756 */
if(!s->budget--) { s->failed_pc=0x0c04e756u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c04e758;
P_0c04e758: /* original d31a, guest PC 0x0c04e758 */
if(!s->budget--) { s->failed_pc=0x0c04e758u; return 0; }
r[3]=read(ram,0x0c04e7c4u,4);
goto P_0c04e75a;
P_0c04e75a: /* original 430b, guest PC 0x0c04e75a */
if(!s->budget--) { s->failed_pc=0x0c04e75au; return 0; }
target=r[3];
r[16]=0x0c04e75eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e75eu) { target=s->pc; goto dispatch; }
goto P_0c04e75e;
P_0c04e75c: /* original 64e3, guest PC 0x0c04e75c */
if(!s->budget--) { s->failed_pc=0x0c04e75cu; return 0; }
r[4]=r[14];
goto P_0c04e75e;
P_0c04e75e: /* original 2008, guest PC 0x0c04e75e */
if(!s->budget--) { s->failed_pc=0x0c04e75eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e760;
P_0c04e760: /* original 8b12, guest PC 0x0c04e760 */
if(!s->budget--) { s->failed_pc=0x0c04e760u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e788; }
goto P_0c04e762;
P_0c04e762: /* original da19, guest PC 0x0c04e762 */
if(!s->budget--) { s->failed_pc=0x0c04e762u; return 0; }
r[10]=read(ram,0x0c04e7c8u,4);
goto P_0c04e764;
P_0c04e764: /* original 5df4, guest PC 0x0c04e764 */
if(!s->budget--) { s->failed_pc=0x0c04e764u; return 0; }
r[13]=read(ram,r[15]+16,4);
goto P_0c04e766;
P_0c04e766: /* original a00c, guest PC 0x0c04e766 */
if(!s->budget--) { s->failed_pc=0x0c04e766u; return 0; }
r[11]=0x00000000u;
goto P_0c04e782;
P_0c04e768: /* original eb00, guest PC 0x0c04e768 */
if(!s->budget--) { s->failed_pc=0x0c04e768u; return 0; }
r[11]=0x00000000u;
goto P_0c04e76a;
P_0c04e76a: /* original d218, guest PC 0x0c04e76a */
if(!s->budget--) { s->failed_pc=0x0c04e76au; return 0; }
r[2]=read(ram,0x0c04e7ccu,4);
goto P_0c04e76c;
P_0c04e76c: /* original 65d3, guest PC 0x0c04e76c */
if(!s->budget--) { s->failed_pc=0x0c04e76cu; return 0; }
r[5]=r[13];
goto P_0c04e76e;
P_0c04e76e: /* original 420b, guest PC 0x0c04e76e */
if(!s->budget--) { s->failed_pc=0x0c04e76eu; return 0; }
target=r[2];
r[16]=0x0c04e772u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e772u) { target=s->pc; goto dispatch; }
goto P_0c04e772;
P_0c04e770: /* original 64e3, guest PC 0x0c04e770 */
if(!s->budget--) { s->failed_pc=0x0c04e770u; return 0; }
r[4]=r[14];
goto P_0c04e772;
P_0c04e772: /* original d317, guest PC 0x0c04e772 */
if(!s->budget--) { s->failed_pc=0x0c04e772u; return 0; }
r[3]=read(ram,0x0c04e7d0u,4);
goto P_0c04e774;
P_0c04e774: /* original 65d3, guest PC 0x0c04e774 */
if(!s->budget--) { s->failed_pc=0x0c04e774u; return 0; }
r[5]=r[13];
goto P_0c04e776;
P_0c04e776: /* original 690d, guest PC 0x0c04e776 */
if(!s->budget--) { s->failed_pc=0x0c04e776u; return 0; }
r[9]=r[0]&65535u;
goto P_0c04e778;
P_0c04e778: /* original 66a3, guest PC 0x0c04e778 */
if(!s->budget--) { s->failed_pc=0x0c04e778u; return 0; }
r[6]=r[10];
goto P_0c04e77a;
P_0c04e77a: /* original 430b, guest PC 0x0c04e77a */
if(!s->budget--) { s->failed_pc=0x0c04e77au; return 0; }
target=r[3];
r[16]=0x0c04e77eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e77eu) { target=s->pc; goto dispatch; }
goto P_0c04e77e;
P_0c04e77c: /* original 64e3, guest PC 0x0c04e77c */
if(!s->budget--) { s->failed_pc=0x0c04e77cu; return 0; }
r[4]=r[14];
goto P_0c04e77e;
P_0c04e77e: /* original 7b01, guest PC 0x0c04e77e */
if(!s->budget--) { s->failed_pc=0x0c04e77eu; return 0; }
r[11]+=0x00000001u;
goto P_0c04e780;
P_0c04e780: /* original 6d93, guest PC 0x0c04e780 */
if(!s->budget--) { s->failed_pc=0x0c04e780u; return 0; }
r[13]=r[9];
goto P_0c04e782;
P_0c04e782: /* original 52fb, guest PC 0x0c04e782 */
if(!s->budget--) { s->failed_pc=0x0c04e782u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c04e784;
P_0c04e784: /* original 3b23, guest PC 0x0c04e784 */
if(!s->budget--) { s->failed_pc=0x0c04e784u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[2])!=0);
goto P_0c04e786;
P_0c04e786: /* original 8bf0, guest PC 0x0c04e786 */
if(!s->budget--) { s->failed_pc=0x0c04e786u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e76a; }
goto P_0c04e788;
P_0c04e788: /* original d312, guest PC 0x0c04e788 */
if(!s->budget--) { s->failed_pc=0x0c04e788u; return 0; }
r[3]=read(ram,0x0c04e7d4u,4);
goto P_0c04e78a;
P_0c04e78a: /* original e500, guest PC 0x0c04e78a */
if(!s->budget--) { s->failed_pc=0x0c04e78au; return 0; }
r[5]=0x00000000u;
goto P_0c04e78c;
P_0c04e78c: /* original e620, guest PC 0x0c04e78c */
if(!s->budget--) { s->failed_pc=0x0c04e78cu; return 0; }
r[6]=0x00000020u;
goto P_0c04e78e;
P_0c04e78e: /* original 430b, guest PC 0x0c04e78e */
if(!s->budget--) { s->failed_pc=0x0c04e78eu; return 0; }
target=r[3];
r[16]=0x0c04e792u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e792u) { target=s->pc; goto dispatch; }
goto P_0c04e792;
P_0c04e790: /* original 64f2, guest PC 0x0c04e790 */
if(!s->budget--) { s->failed_pc=0x0c04e790u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c04e792;
P_0c04e792: /* original d211, guest PC 0x0c04e792 */
if(!s->budget--) { s->failed_pc=0x0c04e792u; return 0; }
r[2]=read(ram,0x0c04e7d8u,4);
goto P_0c04e794;
P_0c04e794: /* original 65c3, guest PC 0x0c04e794 */
if(!s->budget--) { s->failed_pc=0x0c04e794u; return 0; }
r[5]=r[12];
goto P_0c04e796;
P_0c04e796: /* original 420b, guest PC 0x0c04e796 */
if(!s->budget--) { s->failed_pc=0x0c04e796u; return 0; }
target=r[2];
r[16]=0x0c04e79au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04e79au) { target=s->pc; goto dispatch; }
goto P_0c04e79a;
P_0c04e798: /* original 64e3, guest PC 0x0c04e798 */
if(!s->budget--) { s->failed_pc=0x0c04e798u; return 0; }
r[4]=r[14];
goto P_0c04e79a;
P_0c04e79a: /* original e000, guest PC 0x0c04e79a */
if(!s->budget--) { s->failed_pc=0x0c04e79au; return 0; }
r[0]=0x00000000u;
goto P_0c04e79c;
P_0c04e79c: /* original 7f30, guest PC 0x0c04e79c */
if(!s->budget--) { s->failed_pc=0x0c04e79cu; return 0; }
r[15]+=0x00000030u;
goto P_0c04e79e;
P_0c04e79e: /* original 4f26, guest PC 0x0c04e79e */
if(!s->budget--) { s->failed_pc=0x0c04e79eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e7a0;
P_0c04e7a0: /* original 69f6, guest PC 0x0c04e7a0 */
if(!s->budget--) { s->failed_pc=0x0c04e7a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04e7a2;
P_0c04e7a2: /* original 6af6, guest PC 0x0c04e7a2 */
if(!s->budget--) { s->failed_pc=0x0c04e7a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04e7a4;
P_0c04e7a4: /* original 6bf6, guest PC 0x0c04e7a4 */
if(!s->budget--) { s->failed_pc=0x0c04e7a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04e7a6;
P_0c04e7a6: /* original 6cf6, guest PC 0x0c04e7a6 */
if(!s->budget--) { s->failed_pc=0x0c04e7a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04e7a8;
P_0c04e7a8: /* original 6df6, guest PC 0x0c04e7a8 */
if(!s->budget--) { s->failed_pc=0x0c04e7a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04e7aa;
P_0c04e7aa: /* original 000b, guest PC 0x0c04e7aa */
if(!s->budget--) { s->failed_pc=0x0c04e7aau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04e7ac: /* original 6ef6, guest PC 0x0c04e7ac */
if(!s->budget--) { s->failed_pc=0x0c04e7acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04e7aeu,s,ram);
P_0c04eebe: /* original 2fe6, guest PC 0x0c04eebe */
if(!s->budget--) { s->failed_pc=0x0c04eebeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04eec0;
P_0c04eec0: /* original 6e43, guest PC 0x0c04eec0 */
if(!s->budget--) { s->failed_pc=0x0c04eec0u; return 0; }
r[14]=r[4];
goto P_0c04eec2;
P_0c04eec2: /* original 4f22, guest PC 0x0c04eec2 */
if(!s->budget--) { s->failed_pc=0x0c04eec2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04eec4;
P_0c04eec4: /* original 4f12, guest PC 0x0c04eec4 */
if(!s->budget--) { s->failed_pc=0x0c04eec4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04eec6;
P_0c04eec6: /* original 7fd0, guest PC 0x0c04eec6 */
if(!s->budget--) { s->failed_pc=0x0c04eec6u; return 0; }
r[15]+=0xffffffd0u;
goto P_0c04eec8;
P_0c04eec8: /* original 2f52, guest PC 0x0c04eec8 */
if(!s->budget--) { s->failed_pc=0x0c04eec8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c04eeca;
P_0c04eeca: /* original 9324, guest PC 0x0c04eeca */
if(!s->budget--) { s->failed_pc=0x0c04eecau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ef16u,2);
goto P_0c04eecc;
P_0c04eecc: /* original d01a, guest PC 0x0c04eecc */
if(!s->budget--) { s->failed_pc=0x0c04eeccu; return 0; }
r[0]=read(ram,0x0c04ef38u,4);
goto P_0c04eece;
P_0c04eece: /* original 2e3f, guest PC 0x0c04eece */
if(!s->budget--) { s->failed_pc=0x0c04eeceu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c04eed0;
P_0c04eed0: /* original 031a, guest PC 0x0c04eed0 */
if(!s->budget--) { s->failed_pc=0x0c04eed0u; return 0; }
r[3]=r[19];
goto P_0c04eed2;
P_0c04eed2: /* original 633f, guest PC 0x0c04eed2 */
if(!s->budget--) { s->failed_pc=0x0c04eed2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04eed4;
P_0c04eed4: /* original 023c, guest PC 0x0c04eed4 */
if(!s->budget--) { s->failed_pc=0x0c04eed4u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04eed6;
P_0c04eed6: /* original 2228, guest PC 0x0c04eed6 */
if(!s->budget--) { s->failed_pc=0x0c04eed6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04eed8;
P_0c04eed8: /* original 8916, guest PC 0x0c04eed8 */
if(!s->budget--) { s->failed_pc=0x0c04eed8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ef08; }
goto P_0c04eeda;
P_0c04eeda: /* original d318, guest PC 0x0c04eeda */
if(!s->budget--) { s->failed_pc=0x0c04eedau; return 0; }
r[3]=read(ram,0x0c04ef3cu,4);
goto P_0c04eedc;
P_0c04eedc: /* original 430b, guest PC 0x0c04eedc */
if(!s->budget--) { s->failed_pc=0x0c04eedcu; return 0; }
target=r[3];
r[16]=0x0c04eee0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04eee0u) { target=s->pc; goto dispatch; }
goto P_0c04eee0;
P_0c04eede: /* original 64e3, guest PC 0x0c04eede */
if(!s->budget--) { s->failed_pc=0x0c04eedeu; return 0; }
r[4]=r[14];
goto P_0c04eee0;
P_0c04eee0: /* original 2008, guest PC 0x0c04eee0 */
if(!s->budget--) { s->failed_pc=0x0c04eee0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04eee2;
P_0c04eee2: /* original 8b04, guest PC 0x0c04eee2 */
if(!s->budget--) { s->failed_pc=0x0c04eee2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04eeee; }
goto P_0c04eee4;
P_0c04eee4: /* original d316, guest PC 0x0c04eee4 */
if(!s->budget--) { s->failed_pc=0x0c04eee4u; return 0; }
r[3]=read(ram,0x0c04ef40u,4);
goto P_0c04eee6;
P_0c04eee6: /* original 430b, guest PC 0x0c04eee6 */
if(!s->budget--) { s->failed_pc=0x0c04eee6u; return 0; }
target=r[3];
r[16]=0x0c04eeeau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04eeeau) { target=s->pc; goto dispatch; }
goto P_0c04eeea;
P_0c04eee8: /* original 64e3, guest PC 0x0c04eee8 */
if(!s->budget--) { s->failed_pc=0x0c04eee8u; return 0; }
r[4]=r[14];
goto P_0c04eeea;
P_0c04eeea: /* original a00d, guest PC 0x0c04eeea */
if(!s->budget--) { s->failed_pc=0x0c04eeeau; return 0; }
goto P_0c04ef08;
P_0c04eeec: /* original 0009, guest PC 0x0c04eeec */
if(!s->budget--) { s->failed_pc=0x0c04eeecu; return 0; }
goto P_0c04eeee;
P_0c04eeee: /* original d20a, guest PC 0x0c04eeee */
if(!s->budget--) { s->failed_pc=0x0c04eeeeu; return 0; }
r[2]=read(ram,0x0c04ef18u,4);
goto P_0c04eef0;
P_0c04eef0: /* original 420b, guest PC 0x0c04eef0 */
if(!s->budget--) { s->failed_pc=0x0c04eef0u; return 0; }
target=r[2];
r[16]=0x0c04eef4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04eef4u) { target=s->pc; goto dispatch; }
goto P_0c04eef4;
P_0c04eef2: /* original 64e3, guest PC 0x0c04eef2 */
if(!s->budget--) { s->failed_pc=0x0c04eef2u; return 0; }
r[4]=r[14];
goto P_0c04eef4;
P_0c04eef4: /* original 2008, guest PC 0x0c04eef4 */
if(!s->budget--) { s->failed_pc=0x0c04eef4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04eef6;
P_0c04eef6: /* original 8907, guest PC 0x0c04eef6 */
if(!s->budget--) { s->failed_pc=0x0c04eef6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ef08; }
goto P_0c04eef8;
P_0c04eef8: /* original 930d, guest PC 0x0c04eef8 */
if(!s->budget--) { s->failed_pc=0x0c04eef8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ef16u,2);
goto P_0c04eefa;
P_0c04eefa: /* original d012, guest PC 0x0c04eefa */
if(!s->budget--) { s->failed_pc=0x0c04eefau; return 0; }
r[0]=read(ram,0x0c04ef44u,4);
goto P_0c04eefc;
P_0c04eefc: /* original 2e3f, guest PC 0x0c04eefc */
if(!s->budget--) { s->failed_pc=0x0c04eefcu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[3]);
goto P_0c04eefe;
P_0c04eefe: /* original 031a, guest PC 0x0c04eefe */
if(!s->budget--) { s->failed_pc=0x0c04eefeu; return 0; }
r[3]=r[19];
goto P_0c04ef00;
P_0c04ef00: /* original 633f, guest PC 0x0c04ef00 */
if(!s->budget--) { s->failed_pc=0x0c04ef00u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04ef02;
P_0c04ef02: /* original 023c, guest PC 0x0c04ef02 */
if(!s->budget--) { s->failed_pc=0x0c04ef02u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04ef04;
P_0c04ef04: /* original 2228, guest PC 0x0c04ef04 */
if(!s->budget--) { s->failed_pc=0x0c04ef04u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04ef06;
P_0c04ef06: /* original 8b1f, guest PC 0x0c04ef06 */
if(!s->budget--) { s->failed_pc=0x0c04ef06u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ef48; }
goto P_0c04ef08;
P_0c04ef08: /* original 9001, guest PC 0x0c04ef08 */
if(!s->budget--) { s->failed_pc=0x0c04ef08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ef0eu,2);
goto P_0c04ef0a;
P_0c04ef0a: /* original a03a, guest PC 0x0c04ef0a */
if(!s->budget--) { s->failed_pc=0x0c04ef0au; return 0; }
goto P_0c04ef82;
P_0c04ef0c: /* original 0009, guest PC 0x0c04ef0c */
if(!s->budget--) { s->failed_pc=0x0c04ef0cu; return 0; }
return vf3_matrix_family(0x0c04ef0eu,s,ram);
P_0c04ef48: /* original d33a, guest PC 0x0c04ef48 */
if(!s->budget--) { s->failed_pc=0x0c04ef48u; return 0; }
r[3]=read(ram,0x0c04f034u,4);
goto P_0c04ef4a;
P_0c04ef4a: /* original 430b, guest PC 0x0c04ef4a */
if(!s->budget--) { s->failed_pc=0x0c04ef4au; return 0; }
target=r[3];
r[16]=0x0c04ef4eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ef4eu) { target=s->pc; goto dispatch; }
goto P_0c04ef4e;
P_0c04ef4c: /* original 64e3, guest PC 0x0c04ef4c */
if(!s->budget--) { s->failed_pc=0x0c04ef4cu; return 0; }
r[4]=r[14];
goto P_0c04ef4e;
P_0c04ef4e: /* original 4011, guest PC 0x0c04ef4e */
if(!s->budget--) { s->failed_pc=0x0c04ef4eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04ef50;
P_0c04ef50: /* original 8902, guest PC 0x0c04ef50 */
if(!s->budget--) { s->failed_pc=0x0c04ef50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ef58; }
goto P_0c04ef52;
P_0c04ef52: /* original 906a, guest PC 0x0c04ef52 */
if(!s->budget--) { s->failed_pc=0x0c04ef52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f02au,2);
goto P_0c04ef54;
P_0c04ef54: /* original a015, guest PC 0x0c04ef54 */
if(!s->budget--) { s->failed_pc=0x0c04ef54u; return 0; }
goto P_0c04ef82;
P_0c04ef56: /* original 0009, guest PC 0x0c04ef56 */
if(!s->budget--) { s->failed_pc=0x0c04ef56u; return 0; }
goto P_0c04ef58;
P_0c04ef58: /* original d337, guest PC 0x0c04ef58 */
if(!s->budget--) { s->failed_pc=0x0c04ef58u; return 0; }
r[3]=read(ram,0x0c04f038u,4);
goto P_0c04ef5a;
P_0c04ef5a: /* original 65f2, guest PC 0x0c04ef5a */
if(!s->budget--) { s->failed_pc=0x0c04ef5au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04ef5c;
P_0c04ef5c: /* original 430b, guest PC 0x0c04ef5c */
if(!s->budget--) { s->failed_pc=0x0c04ef5cu; return 0; }
target=r[3];
r[16]=0x0c04ef60u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ef60u) { target=s->pc; goto dispatch; }
goto P_0c04ef60;
P_0c04ef5e: /* original 64e3, guest PC 0x0c04ef5e */
if(!s->budget--) { s->failed_pc=0x0c04ef5eu; return 0; }
r[4]=r[14];
goto P_0c04ef60;
P_0c04ef60: /* original 4011, guest PC 0x0c04ef60 */
if(!s->budget--) { s->failed_pc=0x0c04ef60u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04ef62;
P_0c04ef62: /* original 8902, guest PC 0x0c04ef62 */
if(!s->budget--) { s->failed_pc=0x0c04ef62u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ef6a; }
goto P_0c04ef64;
P_0c04ef64: /* original 9062, guest PC 0x0c04ef64 */
if(!s->budget--) { s->failed_pc=0x0c04ef64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f02cu,2);
goto P_0c04ef66;
P_0c04ef66: /* original a00c, guest PC 0x0c04ef66 */
if(!s->budget--) { s->failed_pc=0x0c04ef66u; return 0; }
goto P_0c04ef82;
P_0c04ef68: /* original 0009, guest PC 0x0c04ef68 */
if(!s->budget--) { s->failed_pc=0x0c04ef68u; return 0; }
goto P_0c04ef6a;
P_0c04ef6a: /* original 65f2, guest PC 0x0c04ef6a */
if(!s->budget--) { s->failed_pc=0x0c04ef6au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04ef6c;
P_0c04ef6c: /* original 66f3, guest PC 0x0c04ef6c */
if(!s->budget--) { s->failed_pc=0x0c04ef6cu; return 0; }
r[6]=r[15];
goto P_0c04ef6e;
P_0c04ef6e: /* original 7604, guest PC 0x0c04ef6e */
if(!s->budget--) { s->failed_pc=0x0c04ef6eu; return 0; }
r[6]+=0x00000004u;
goto P_0c04ef70;
P_0c04ef70: /* original b50d, guest PC 0x0c04ef70 */
if(!s->budget--) { s->failed_pc=0x0c04ef70u; return 0; }
target=0x0c04f98eu; r[16]=0x0c04ef74u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04ef74u) { target=s->pc; goto dispatch; }
goto P_0c04ef74;
P_0c04ef72: /* original 64e3, guest PC 0x0c04ef72 */
if(!s->budget--) { s->failed_pc=0x0c04ef72u; return 0; }
r[4]=r[14];
goto P_0c04ef74;
P_0c04ef74: /* original 6403, guest PC 0x0c04ef74 */
if(!s->budget--) { s->failed_pc=0x0c04ef74u; return 0; }
r[4]=r[0];
goto P_0c04ef76;
P_0c04ef76: /* original 4411, guest PC 0x0c04ef76 */
if(!s->budget--) { s->failed_pc=0x0c04ef76u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c04ef78;
P_0c04ef78: /* original 8902, guest PC 0x0c04ef78 */
if(!s->budget--) { s->failed_pc=0x0c04ef78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04ef80; }
goto P_0c04ef7a;
P_0c04ef7a: /* original 9058, guest PC 0x0c04ef7a */
if(!s->budget--) { s->failed_pc=0x0c04ef7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f02eu,2);
goto P_0c04ef7c;
P_0c04ef7c: /* original a001, guest PC 0x0c04ef7c */
if(!s->budget--) { s->failed_pc=0x0c04ef7cu; return 0; }
goto P_0c04ef82;
P_0c04ef7e: /* original 0009, guest PC 0x0c04ef7e */
if(!s->budget--) { s->failed_pc=0x0c04ef7eu; return 0; }
goto P_0c04ef80;
P_0c04ef80: /* original 50fb, guest PC 0x0c04ef80 */
if(!s->budget--) { s->failed_pc=0x0c04ef80u; return 0; }
r[0]=read(ram,r[15]+44,4);
goto P_0c04ef82;
P_0c04ef82: /* original 7f30, guest PC 0x0c04ef82 */
if(!s->budget--) { s->failed_pc=0x0c04ef82u; return 0; }
r[15]+=0x00000030u;
goto P_0c04ef84;
P_0c04ef84: /* original 4f16, guest PC 0x0c04ef84 */
if(!s->budget--) { s->failed_pc=0x0c04ef84u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ef86;
P_0c04ef86: /* original 4f26, guest PC 0x0c04ef86 */
if(!s->budget--) { s->failed_pc=0x0c04ef86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ef88;
P_0c04ef88: /* original 000b, guest PC 0x0c04ef88 */
if(!s->budget--) { s->failed_pc=0x0c04ef88u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04ef8a: /* original 6ef6, guest PC 0x0c04ef8a */
if(!s->budget--) { s->failed_pc=0x0c04ef8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04ef8cu,s,ram);
P_0c04fa7c: /* original 9632, guest PC 0x0c04fa7c */
if(!s->budget--) { s->failed_pc=0x0c04fa7cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fae4u,2);
goto P_0c04fa7e;
P_0c04fa7e: /* original 4f12, guest PC 0x0c04fa7e */
if(!s->budget--) { s->failed_pc=0x0c04fa7eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fa80;
P_0c04fa80: /* original 246f, guest PC 0x0c04fa80 */
if(!s->budget--) { s->failed_pc=0x0c04fa80u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[6]);
goto P_0c04fa82;
P_0c04fa82: /* original d31b, guest PC 0x0c04fa82 */
if(!s->budget--) { s->failed_pc=0x0c04fa82u; return 0; }
r[3]=read(ram,0x0c04faf0u,4);
goto P_0c04fa84;
P_0c04fa84: /* original 061a, guest PC 0x0c04fa84 */
if(!s->budget--) { s->failed_pc=0x0c04fa84u; return 0; }
r[6]=r[19];
goto P_0c04fa86;
P_0c04fa86: /* original 666f, guest PC 0x0c04fa86 */
if(!s->budget--) { s->failed_pc=0x0c04fa86u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c04fa88;
P_0c04fa88: /* original 363c, guest PC 0x0c04fa88 */
if(!s->budget--) { s->failed_pc=0x0c04fa88u; return 0; }
r[6]+=r[3];
goto P_0c04fa8a;
P_0c04fa8a: /* original 556a, guest PC 0x0c04fa8a */
if(!s->budget--) { s->failed_pc=0x0c04fa8au; return 0; }
r[5]=read(ram,r[6]+40,4);
goto P_0c04fa8c;
P_0c04fa8c: /* original a009, guest PC 0x0c04fa8c */
if(!s->budget--) { s->failed_pc=0x0c04fa8cu; return 0; }
r[4]=0x00000000u;
goto P_0c04faa2;
P_0c04fa8e: /* original e400, guest PC 0x0c04fa8e */
if(!s->budget--) { s->failed_pc=0x0c04fa8eu; return 0; }
r[4]=0x00000000u;
goto P_0c04fa90;
P_0c04fa90: /* original 6750, guest PC 0x0c04fa90 */
if(!s->budget--) { s->failed_pc=0x0c04fa90u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[7]=tmp;
goto P_0c04fa92;
P_0c04fa92: /* original 677c, guest PC 0x0c04fa92 */
if(!s->budget--) { s->failed_pc=0x0c04fa92u; return 0; }
r[7]=r[7]&255u;
goto P_0c04fa94;
P_0c04fa94: /* original 2778, guest PC 0x0c04fa94 */
if(!s->budget--) { s->failed_pc=0x0c04fa94u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c04fa96;
P_0c04fa96: /* original 8b02, guest PC 0x0c04fa96 */
if(!s->budget--) { s->failed_pc=0x0c04fa96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fa9e; }
goto P_0c04fa98;
P_0c04fa98: /* original 6043, guest PC 0x0c04fa98 */
if(!s->budget--) { s->failed_pc=0x0c04fa98u; return 0; }
r[0]=r[4];
goto P_0c04fa9a;
P_0c04fa9a: /* original 000b, guest PC 0x0c04fa9a */
if(!s->budget--) { s->failed_pc=0x0c04fa9au; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c04fa9c: /* original 4f16, guest PC 0x0c04fa9c */
if(!s->budget--) { s->failed_pc=0x0c04fa9cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fa9e;
P_0c04fa9e: /* original 7520, guest PC 0x0c04fa9e */
if(!s->budget--) { s->failed_pc=0x0c04fa9eu; return 0; }
r[5]+=0x00000020u;
goto P_0c04faa0;
P_0c04faa0: /* original 7401, guest PC 0x0c04faa0 */
if(!s->budget--) { s->failed_pc=0x0c04faa0u; return 0; }
r[4]+=0x00000001u;
goto P_0c04faa2;
P_0c04faa2: /* original 5267, guest PC 0x0c04faa2 */
if(!s->budget--) { s->failed_pc=0x0c04faa2u; return 0; }
r[2]=read(ram,r[6]+28,4);
goto P_0c04faa4;
P_0c04faa4: /* original 532c, guest PC 0x0c04faa4 */
if(!s->budget--) { s->failed_pc=0x0c04faa4u; return 0; }
r[3]=read(ram,r[2]+48,4);
goto P_0c04faa6;
P_0c04faa6: /* original 3433, guest PC 0x0c04faa6 */
if(!s->budget--) { s->failed_pc=0x0c04faa6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c04faa8;
P_0c04faa8: /* original 8bf2, guest PC 0x0c04faa8 */
if(!s->budget--) { s->failed_pc=0x0c04faa8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04fa90; }
goto P_0c04faaa;
P_0c04faaa: /* original e0ff, guest PC 0x0c04faaa */
if(!s->budget--) { s->failed_pc=0x0c04faaau; return 0; }
r[0]=0xffffffffu;
goto P_0c04faac;
P_0c04faac: /* original 000b, guest PC 0x0c04faac */
if(!s->budget--) { s->failed_pc=0x0c04faacu; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c04faae: /* original 4f16, guest PC 0x0c04faae */
if(!s->budget--) { s->failed_pc=0x0c04faaeu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c04fab0u,s,ram);
P_0c04fe40: /* original 2fe6, guest PC 0x0c04fe40 */
if(!s->budget--) { s->failed_pc=0x0c04fe40u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe42;
P_0c04fe42: /* original 2fd6, guest PC 0x0c04fe42 */
if(!s->budget--) { s->failed_pc=0x0c04fe42u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fe44;
P_0c04fe44: /* original 6d53, guest PC 0x0c04fe44 */
if(!s->budget--) { s->failed_pc=0x0c04fe44u; return 0; }
r[13]=r[5];
return vf3_matrix_family(0x0c04fe46u,s,ram);
P_0c04ff62: /* original 933a, guest PC 0x0c04ff62 */
if(!s->budget--) { s->failed_pc=0x0c04ff62u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ffdau,2);
goto P_0c04ff64;
P_0c04ff64: /* original 6053, guest PC 0x0c04ff64 */
if(!s->budget--) { s->failed_pc=0x0c04ff64u; return 0; }
r[0]=r[5];
goto P_0c04ff66;
P_0c04ff66: /* original 4f12, guest PC 0x0c04ff66 */
if(!s->budget--) { s->failed_pc=0x0c04ff66u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04ff68;
P_0c04ff68: /* original 243f, guest PC 0x0c04ff68 */
if(!s->budget--) { s->failed_pc=0x0c04ff68u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c04ff6a;
P_0c04ff6a: /* original d21d, guest PC 0x0c04ff6a */
if(!s->budget--) { s->failed_pc=0x0c04ff6au; return 0; }
r[2]=read(ram,0x0c04ffe0u,4);
goto P_0c04ff6c;
P_0c04ff6c: /* original 4008, guest PC 0x0c04ff6c */
if(!s->budget--) { s->failed_pc=0x0c04ff6cu; return 0; }
r[0]<<=2;
goto P_0c04ff6e;
P_0c04ff6e: /* original 4008, guest PC 0x0c04ff6e */
if(!s->budget--) { s->failed_pc=0x0c04ff6eu; return 0; }
r[0]<<=2;
goto P_0c04ff70;
P_0c04ff70: /* original 4000, guest PC 0x0c04ff70 */
if(!s->budget--) { s->failed_pc=0x0c04ff70u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c04ff72;
P_0c04ff72: /* original 041a, guest PC 0x0c04ff72 */
if(!s->budget--) { s->failed_pc=0x0c04ff72u; return 0; }
r[4]=r[19];
goto P_0c04ff74;
P_0c04ff74: /* original 644f, guest PC 0x0c04ff74 */
if(!s->budget--) { s->failed_pc=0x0c04ff74u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c04ff76;
P_0c04ff76: /* original 342c, guest PC 0x0c04ff76 */
if(!s->budget--) { s->failed_pc=0x0c04ff76u; return 0; }
r[4]+=r[2];
goto P_0c04ff78;
P_0c04ff78: /* original 514a, guest PC 0x0c04ff78 */
if(!s->budget--) { s->failed_pc=0x0c04ff78u; return 0; }
r[1]=read(ram,r[4]+40,4);
goto P_0c04ff7a;
P_0c04ff7a: /* original 301c, guest PC 0x0c04ff7a */
if(!s->budget--) { s->failed_pc=0x0c04ff7au; return 0; }
r[0]+=r[1];
goto P_0c04ff7c;
P_0c04ff7c: /* original 000b, guest PC 0x0c04ff7c */
if(!s->budget--) { s->failed_pc=0x0c04ff7cu; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c04ff7e: /* original 4f16, guest PC 0x0c04ff7e */
if(!s->budget--) { s->failed_pc=0x0c04ff7eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ff80;
P_0c04ff80: /* original 932b, guest PC 0x0c04ff80 */
if(!s->budget--) { s->failed_pc=0x0c04ff80u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ffdau,2);
goto P_0c04ff82;
P_0c04ff82: /* original e1fc, guest PC 0x0c04ff82 */
if(!s->budget--) { s->failed_pc=0x0c04ff82u; return 0; }
r[1]=0xfffffffcu;
goto P_0c04ff84;
P_0c04ff84: /* original 4f12, guest PC 0x0c04ff84 */
if(!s->budget--) { s->failed_pc=0x0c04ff84u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04ff86;
P_0c04ff86: /* original 243f, guest PC 0x0c04ff86 */
if(!s->budget--) { s->failed_pc=0x0c04ff86u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c04ff88;
P_0c04ff88: /* original d215, guest PC 0x0c04ff88 */
if(!s->budget--) { s->failed_pc=0x0c04ff88u; return 0; }
r[2]=read(ram,0x0c04ffe0u,4);
goto P_0c04ff8a;
P_0c04ff8a: /* original 451c, guest PC 0x0c04ff8a */
if(!s->budget--) { s->failed_pc=0x0c04ff8au; return 0; }
r[5]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[5]>>((-r[1])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[1]&31u);
goto P_0c04ff8c;
P_0c04ff8c: /* original e101, guest PC 0x0c04ff8c */
if(!s->budget--) { s->failed_pc=0x0c04ff8cu; return 0; }
r[1]=0x00000001u;
goto P_0c04ff8e;
P_0c04ff8e: /* original 041a, guest PC 0x0c04ff8e */
if(!s->budget--) { s->failed_pc=0x0c04ff8eu; return 0; }
r[4]=r[19];
goto P_0c04ff90;
P_0c04ff90: /* original 644f, guest PC 0x0c04ff90 */
if(!s->budget--) { s->failed_pc=0x0c04ff90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c04ff92;
P_0c04ff92: /* original 342c, guest PC 0x0c04ff92 */
if(!s->budget--) { s->failed_pc=0x0c04ff92u; return 0; }
r[4]+=r[2];
goto P_0c04ff94;
P_0c04ff94: /* original 6043, guest PC 0x0c04ff94 */
if(!s->budget--) { s->failed_pc=0x0c04ff94u; return 0; }
r[0]=r[4];
goto P_0c04ff96;
P_0c04ff96: /* original 7048, guest PC 0x0c04ff96 */
if(!s->budget--) { s->failed_pc=0x0c04ff96u; return 0; }
r[0]+=0x00000048u;
goto P_0c04ff98;
P_0c04ff98: /* original 350c, guest PC 0x0c04ff98 */
if(!s->budget--) { s->failed_pc=0x0c04ff98u; return 0; }
r[5]+=r[0];
goto P_0c04ff9a;
P_0c04ff9a: /* original 2510, guest PC 0x0c04ff9a */
if(!s->budget--) { s->failed_pc=0x0c04ff9au; return 0; }
write(ram,r[5],r[1],1);
goto P_0c04ff9c;
P_0c04ff9c: /* original 000b, guest PC 0x0c04ff9c */
if(!s->budget--) { s->failed_pc=0x0c04ff9cu; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c04ff9e: /* original 4f16, guest PC 0x0c04ff9e */
if(!s->budget--) { s->failed_pc=0x0c04ff9eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04ffa0;
P_0c04ffa0: /* original d713, guest PC 0x0c04ffa0 */
if(!s->budget--) { s->failed_pc=0x0c04ffa0u; return 0; }
r[7]=read(ram,0x0c04fff0u,4);
goto P_0c04ffa2;
P_0c04ffa2: /* original e601, guest PC 0x0c04ffa2 */
if(!s->budget--) { s->failed_pc=0x0c04ffa2u; return 0; }
r[6]=0x00000001u;
goto P_0c04ffa4;
P_0c04ffa4: /* original d411, guest PC 0x0c04ffa4 */
if(!s->budget--) { s->failed_pc=0x0c04ffa4u; return 0; }
r[4]=read(ram,0x0c04ffecu,4);
goto P_0c04ffa6;
P_0c04ffa6: /* original a009, guest PC 0x0c04ffa6 */
if(!s->budget--) { s->failed_pc=0x0c04ffa6u; return 0; }
r[5]=0x00000000u;
goto P_0c04ffbc;
P_0c04ffa8: /* original e500, guest PC 0x0c04ffa8 */
if(!s->budget--) { s->failed_pc=0x0c04ffa8u; return 0; }
r[5]=0x00000000u;
goto P_0c04ffaa;
P_0c04ffaa: /* original 6240, guest PC 0x0c04ffaa */
if(!s->budget--) { s->failed_pc=0x0c04ffaau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c04ffac;
P_0c04ffac: /* original 2228, guest PC 0x0c04ffac */
if(!s->budget--) { s->failed_pc=0x0c04ffacu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04ffae;
P_0c04ffae: /* original 8b03, guest PC 0x0c04ffae */
if(!s->budget--) { s->failed_pc=0x0c04ffaeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ffb8; }
goto P_0c04ffb0;
P_0c04ffb0: /* original 2460, guest PC 0x0c04ffb0 */
if(!s->budget--) { s->failed_pc=0x0c04ffb0u; return 0; }
write(ram,r[4],r[6],1);
goto P_0c04ffb2;
P_0c04ffb2: /* original 1453, guest PC 0x0c04ffb2 */
if(!s->budget--) { s->failed_pc=0x0c04ffb2u; return 0; }
write(ram,r[4]+12,r[5],4);
goto P_0c04ffb4;
P_0c04ffb4: /* original 000b, guest PC 0x0c04ffb4 */
if(!s->budget--) { s->failed_pc=0x0c04ffb4u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c04ffb6: /* original 6043, guest PC 0x0c04ffb6 */
if(!s->budget--) { s->failed_pc=0x0c04ffb6u; return 0; }
r[0]=r[4];
goto P_0c04ffb8;
P_0c04ffb8: /* original 7448, guest PC 0x0c04ffb8 */
if(!s->budget--) { s->failed_pc=0x0c04ffb8u; return 0; }
r[4]+=0x00000048u;
goto P_0c04ffba;
P_0c04ffba: /* original 7501, guest PC 0x0c04ffba */
if(!s->budget--) { s->failed_pc=0x0c04ffbau; return 0; }
r[5]+=0x00000001u;
goto P_0c04ffbc;
P_0c04ffbc: /* original 6372, guest PC 0x0c04ffbc */
if(!s->budget--) { s->failed_pc=0x0c04ffbcu; return 0; }
tmp=read(ram,r[7],4);
r[3]=tmp;
goto P_0c04ffbe;
P_0c04ffbe: /* original 3533, guest PC 0x0c04ffbe */
if(!s->budget--) { s->failed_pc=0x0c04ffbeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[3])!=0);
goto P_0c04ffc0;
P_0c04ffc0: /* original 8bf3, guest PC 0x0c04ffc0 */
if(!s->budget--) { s->failed_pc=0x0c04ffc0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04ffaa; }
goto P_0c04ffc2;
P_0c04ffc2: /* original d20c, guest PC 0x0c04ffc2 */
if(!s->budget--) { s->failed_pc=0x0c04ffc2u; return 0; }
r[2]=read(ram,0x0c04fff4u,4);
goto P_0c04ffc4;
P_0c04ffc4: /* original e000, guest PC 0x0c04ffc4 */
if(!s->budget--) { s->failed_pc=0x0c04ffc4u; return 0; }
r[0]=0x00000000u;
goto P_0c04ffc6;
P_0c04ffc6: /* original 9109, guest PC 0x0c04ffc6 */
if(!s->budget--) { s->failed_pc=0x0c04ffc6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04ffdcu,2);
goto P_0c04ffc8;
P_0c04ffc8: /* original 2212, guest PC 0x0c04ffc8 */
if(!s->budget--) { s->failed_pc=0x0c04ffc8u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c04ffca;
P_0c04ffca: /* original 000b, guest PC 0x0c04ffca */
if(!s->budget--) { s->failed_pc=0x0c04ffcau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c04ffcc: /* original 0009, guest PC 0x0c04ffcc */
if(!s->budget--) { s->failed_pc=0x0c04ffccu; return 0; }
goto P_0c04ffce;
P_0c04ffce: /* original d30a, guest PC 0x0c04ffce */
if(!s->budget--) { s->failed_pc=0x0c04ffceu; return 0; }
r[3]=read(ram,0x0c04fff8u,4);
goto P_0c04ffd0;
P_0c04ffd0: /* original e648, guest PC 0x0c04ffd0 */
if(!s->budget--) { s->failed_pc=0x0c04ffd0u; return 0; }
r[6]=0x00000048u;
goto P_0c04ffd2;
P_0c04ffd2: /* original 432b, guest PC 0x0c04ffd2 */
if(!s->budget--) { s->failed_pc=0x0c04ffd2u; return 0; }
target=r[3];
r[5]=0x00000000u;
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
P_0c04ffd4: /* original e500, guest PC 0x0c04ffd4 */
if(!s->budget--) { s->failed_pc=0x0c04ffd4u; return 0; }
r[5]=0x00000000u;
goto P_0c04ffd6;
P_0c04ffd6: /* original 000b, guest PC 0x0c04ffd6 */
if(!s->budget--) { s->failed_pc=0x0c04ffd6u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c04ffd8: /* original e000, guest PC 0x0c04ffd8 */
if(!s->budget--) { s->failed_pc=0x0c04ffd8u; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c04ffdau,s,ram);
P_0c04fffc: /* original 2fe6, guest PC 0x0c04fffc */
if(!s->budget--) { s->failed_pc=0x0c04fffcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fffe;
P_0c04fffe: /* original 6253, guest PC 0x0c04fffe */
if(!s->budget--) { s->failed_pc=0x0c04fffeu; return 0; }
r[2]=r[5];
goto P_0c050000;
P_0c050000: /* original 2fd6, guest PC 0x0c050000 */
if(!s->budget--) { s->failed_pc=0x0c050000u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050002;
P_0c050002: /* original 6d43, guest PC 0x0c050002 */
if(!s->budget--) { s->failed_pc=0x0c050002u; return 0; }
r[13]=r[4];
goto P_0c050004;
P_0c050004: /* original 2fc6, guest PC 0x0c050004 */
if(!s->budget--) { s->failed_pc=0x0c050004u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050006;
P_0c050006: /* original 2fb6, guest PC 0x0c050006 */
if(!s->budget--) { s->failed_pc=0x0c050006u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050008;
P_0c050008: /* original 4f22, guest PC 0x0c050008 */
if(!s->budget--) { s->failed_pc=0x0c050008u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05000a;
P_0c05000a: /* original 4f12, guest PC 0x0c05000a */
if(!s->budget--) { s->failed_pc=0x0c05000au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c05000c;
P_0c05000c: /* original 7fd0, guest PC 0x0c05000c */
if(!s->budget--) { s->failed_pc=0x0c05000cu; return 0; }
r[15]+=0xffffffd0u;
goto P_0c05000e;
P_0c05000e: /* original 2f52, guest PC 0x0c05000e */
if(!s->budget--) { s->failed_pc=0x0c05000eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c050010;
P_0c050010: /* original 9b56, guest PC 0x0c050010 */
if(!s->budget--) { s->failed_pc=0x0c050010u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0500c0u,2);
goto P_0c050012;
P_0c050012: /* original d32c, guest PC 0x0c050012 */
if(!s->budget--) { s->failed_pc=0x0c050012u; return 0; }
r[3]=read(ram,0x0c0500c4u,4);
goto P_0c050014;
P_0c050014: /* original 2dbf, guest PC 0x0c050014 */
if(!s->budget--) { s->failed_pc=0x0c050014u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[11]);
goto P_0c050016;
P_0c050016: /* original 2f56, guest PC 0x0c050016 */
if(!s->budget--) { s->failed_pc=0x0c050016u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050018;
P_0c050018: /* original 2fd6, guest PC 0x0c050018 */
if(!s->budget--) { s->failed_pc=0x0c050018u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05001a;
P_0c05001a: /* original d22b, guest PC 0x0c05001a */
if(!s->budget--) { s->failed_pc=0x0c05001au; return 0; }
r[2]=read(ram,0x0c0500c8u,4);
goto P_0c05001c;
P_0c05001c: /* original 0b1a, guest PC 0x0c05001c */
if(!s->budget--) { s->failed_pc=0x0c05001cu; return 0; }
r[11]=r[19];
goto P_0c05001e;
P_0c05001e: /* original d12b, guest PC 0x0c05001e */
if(!s->budget--) { s->failed_pc=0x0c05001eu; return 0; }
r[1]=read(ram,0x0c0500ccu,4);
goto P_0c050020;
P_0c050020: /* original 6bbf, guest PC 0x0c050020 */
if(!s->budget--) { s->failed_pc=0x0c050020u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c050022;
P_0c050022: /* original 3b3c, guest PC 0x0c050022 */
if(!s->budget--) { s->failed_pc=0x0c050022u; return 0; }
r[11]+=r[3];
goto P_0c050024;
P_0c050024: /* original 410b, guest PC 0x0c050024 */
if(!s->budget--) { s->failed_pc=0x0c050024u; return 0; }
target=r[1];
r[16]=0x0c050028u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050028u) { target=s->pc; goto dispatch; }
goto P_0c050028;
P_0c050026: /* original 2f26, guest PC 0x0c050026 */
if(!s->budget--) { s->failed_pc=0x0c050026u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050028;
P_0c050028: /* original 7f0c, guest PC 0x0c050028 */
if(!s->budget--) { s->failed_pc=0x0c050028u; return 0; }
r[15]+=0x0000000cu;
goto P_0c05002a;
P_0c05002a: /* original 65f2, guest PC 0x0c05002a */
if(!s->budget--) { s->failed_pc=0x0c05002au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c05002c;
P_0c05002c: /* original 66f3, guest PC 0x0c05002c */
if(!s->budget--) { s->failed_pc=0x0c05002cu; return 0; }
r[6]=r[15];
goto P_0c05002e;
P_0c05002e: /* original 7604, guest PC 0x0c05002e */
if(!s->budget--) { s->failed_pc=0x0c05002eu; return 0; }
r[6]+=0x00000004u;
goto P_0c050030;
P_0c050030: /* original bcad, guest PC 0x0c050030 */
if(!s->budget--) { s->failed_pc=0x0c050030u; return 0; }
target=0x0c04f98eu; r[16]=0x0c050034u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050034u) { target=s->pc; goto dispatch; }
goto P_0c050034;
P_0c050032: /* original 64d3, guest PC 0x0c050032 */
if(!s->budget--) { s->failed_pc=0x0c050032u; return 0; }
r[4]=r[13];
goto P_0c050034;
P_0c050034: /* original 6503, guest PC 0x0c050034 */
if(!s->budget--) { s->failed_pc=0x0c050034u; return 0; }
r[5]=r[0];
goto P_0c050036;
P_0c050036: /* original 4511, guest PC 0x0c050036 */
if(!s->budget--) { s->failed_pc=0x0c050036u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c050038;
P_0c050038: /* original 8902, guest PC 0x0c050038 */
if(!s->budget--) { s->failed_pc=0x0c050038u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c050040; }
goto P_0c05003a;
P_0c05003a: /* original 9042, guest PC 0x0c05003a */
if(!s->budget--) { s->failed_pc=0x0c05003au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0500c2u,2);
goto P_0c05003c;
P_0c05003c: /* original a06c, guest PC 0x0c05003c */
if(!s->budget--) { s->failed_pc=0x0c05003cu; return 0; }
goto P_0c050118;
P_0c05003e: /* original 0009, guest PC 0x0c05003e */
if(!s->budget--) { s->failed_pc=0x0c05003eu; return 0; }
goto P_0c050040;
P_0c050040: /* original bf8f, guest PC 0x0c050040 */
if(!s->budget--) { s->failed_pc=0x0c050040u; return 0; }
target=0x0c04ff62u; r[16]=0x0c050044u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050044u) { target=s->pc; goto dispatch; }
goto P_0c050044;
P_0c050042: /* original 64d3, guest PC 0x0c050042 */
if(!s->budget--) { s->failed_pc=0x0c050042u; return 0; }
r[4]=r[13];
goto P_0c050044;
P_0c050044: /* original 53b7, guest PC 0x0c050044 */
if(!s->budget--) { s->failed_pc=0x0c050044u; return 0; }
r[3]=read(ram,r[11]+28,4);
goto P_0c050046;
P_0c050046: /* original 5ef4, guest PC 0x0c050046 */
if(!s->budget--) { s->failed_pc=0x0c050046u; return 0; }
r[14]=read(ram,r[15]+16,4);
goto P_0c050048;
P_0c050048: /* original 523c, guest PC 0x0c050048 */
if(!s->budget--) { s->failed_pc=0x0c050048u; return 0; }
r[2]=read(ram,r[3]+48,4);
goto P_0c05004a;
P_0c05004a: /* original 3e23, guest PC 0x0c05004a */
if(!s->budget--) { s->failed_pc=0x0c05004au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c05004c;
P_0c05004c: /* original 890c, guest PC 0x0c05004c */
if(!s->budget--) { s->failed_pc=0x0c05004cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c050068; }
goto P_0c05004e;
P_0c05004e: /* original a05f, guest PC 0x0c05004e */
if(!s->budget--) { s->failed_pc=0x0c05004eu; return 0; }
r[12]=0x00000000u;
goto P_0c050110;
P_0c050050: /* original ec00, guest PC 0x0c050050 */
if(!s->budget--) { s->failed_pc=0x0c050050u; return 0; }
r[12]=0x00000000u;
goto P_0c050052;
P_0c050052: /* original 65e3, guest PC 0x0c050052 */
if(!s->budget--) { s->failed_pc=0x0c050052u; return 0; }
r[5]=r[14];
goto P_0c050054;
P_0c050054: /* original bf23, guest PC 0x0c050054 */
if(!s->budget--) { s->failed_pc=0x0c050054u; return 0; }
target=0x0c04fe9eu; r[16]=0x0c050058u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050058u) { target=s->pc; goto dispatch; }
goto P_0c050058;
P_0c050056: /* original 64d3, guest PC 0x0c050056 */
if(!s->budget--) { s->failed_pc=0x0c050056u; return 0; }
r[4]=r[13];
goto P_0c050058;
P_0c050058: /* original 52fb, guest PC 0x0c050058 */
if(!s->budget--) { s->failed_pc=0x0c050058u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c05005a;
P_0c05005a: /* original 640d, guest PC 0x0c05005a */
if(!s->budget--) { s->failed_pc=0x0c05005au; return 0; }
r[4]=r[0]&65535u;
goto P_0c05005c;
P_0c05005c: /* original d51c, guest PC 0x0c05005c */
if(!s->budget--) { s->failed_pc=0x0c05005cu; return 0; }
r[5]=read(ram,0x0c0500d0u,4);
goto P_0c05005e;
P_0c05005e: /* original 72ff, guest PC 0x0c05005e */
if(!s->budget--) { s->failed_pc=0x0c05005eu; return 0; }
r[2]+=0xffffffffu;
goto P_0c050060;
P_0c050060: /* original 3c20, guest PC 0x0c050060 */
if(!s->budget--) { s->failed_pc=0x0c050060u; return 0; }
r[17]=(r[17]&~1u)|((r[12]==r[2])!=0);
goto P_0c050062;
P_0c050062: /* original 8b08, guest PC 0x0c050062 */
if(!s->budget--) { s->failed_pc=0x0c050062u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050076; }
goto P_0c050064;
P_0c050064: /* original 3450, guest PC 0x0c050064 */
if(!s->budget--) { s->failed_pc=0x0c050064u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c050066;
P_0c050066: /* original 8951, guest PC 0x0c050066 */
if(!s->budget--) { s->failed_pc=0x0c050066u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05010c; }
goto P_0c050068;
P_0c050068: /* original dd1a, guest PC 0x0c050068 */
if(!s->budget--) { s->failed_pc=0x0c050068u; return 0; }
r[13]=read(ram,0x0c0500d4u,4);
goto P_0c05006a;
P_0c05006a: /* original 2fe6, guest PC 0x0c05006a */
if(!s->budget--) { s->failed_pc=0x0c05006au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05006c;
P_0c05006c: /* original d317, guest PC 0x0c05006c */
if(!s->budget--) { s->failed_pc=0x0c05006cu; return 0; }
r[3]=read(ram,0x0c0500ccu,4);
goto P_0c05006e;
P_0c05006e: /* original 430b, guest PC 0x0c05006e */
if(!s->budget--) { s->failed_pc=0x0c05006eu; return 0; }
target=r[3];
r[16]=0x0c050072u;
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050072u) { target=s->pc; goto dispatch; }
goto P_0c050072;
P_0c050070: /* original 2fd6, guest PC 0x0c050070 */
if(!s->budget--) { s->failed_pc=0x0c050070u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050072;
P_0c050072: /* original a048, guest PC 0x0c050072 */
if(!s->budget--) { s->failed_pc=0x0c050072u; return 0; }
r[15]+=0x00000008u;
goto P_0c050106;
P_0c050074: /* original 7f08, guest PC 0x0c050074 */
if(!s->budget--) { s->failed_pc=0x0c050074u; return 0; }
r[15]+=0x00000008u;
goto P_0c050076;
P_0c050076: /* original 34e0, guest PC 0x0c050076 */
if(!s->budget--) { s->failed_pc=0x0c050076u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[14])!=0);
goto P_0c050078;
P_0c050078: /* original 8b07, guest PC 0x0c050078 */
if(!s->budget--) { s->failed_pc=0x0c050078u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05008a; }
goto P_0c05007a;
P_0c05007a: /* original dd17, guest PC 0x0c05007a */
if(!s->budget--) { s->failed_pc=0x0c05007au; return 0; }
r[13]=read(ram,0x0c0500d8u,4);
goto P_0c05007c;
P_0c05007c: /* original 2fe6, guest PC 0x0c05007c */
if(!s->budget--) { s->failed_pc=0x0c05007cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05007e;
P_0c05007e: /* original 2f46, guest PC 0x0c05007e */
if(!s->budget--) { s->failed_pc=0x0c05007eu; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050080;
P_0c050080: /* original d312, guest PC 0x0c050080 */
if(!s->budget--) { s->failed_pc=0x0c050080u; return 0; }
r[3]=read(ram,0x0c0500ccu,4);
goto P_0c050082;
P_0c050082: /* original 430b, guest PC 0x0c050082 */
if(!s->budget--) { s->failed_pc=0x0c050082u; return 0; }
target=r[3];
r[16]=0x0c050086u;
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050086u) { target=s->pc; goto dispatch; }
goto P_0c050086;
P_0c050084: /* original 2fd6, guest PC 0x0c050084 */
if(!s->budget--) { s->failed_pc=0x0c050084u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050086;
P_0c050086: /* original a03e, guest PC 0x0c050086 */
if(!s->budget--) { s->failed_pc=0x0c050086u; return 0; }
r[15]+=0x0000000cu;
goto P_0c050106;
P_0c050088: /* original 7f0c, guest PC 0x0c050088 */
if(!s->budget--) { s->failed_pc=0x0c050088u; return 0; }
r[15]+=0x0000000cu;
goto P_0c05008a;
P_0c05008a: /* original 3450, guest PC 0x0c05008a */
if(!s->budget--) { s->failed_pc=0x0c05008au; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c05008c;
P_0c05008c: /* original 8b02, guest PC 0x0c05008c */
if(!s->budget--) { s->failed_pc=0x0c05008cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050094; }
goto P_0c05008e;
P_0c05008e: /* original dd13, guest PC 0x0c05008e */
if(!s->budget--) { s->failed_pc=0x0c05008eu; return 0; }
r[13]=read(ram,0x0c0500dcu,4);
goto P_0c050090;
P_0c050090: /* original aff4, guest PC 0x0c050090 */
if(!s->budget--) { s->failed_pc=0x0c050090u; return 0; }
goto P_0c05007c;
P_0c050092: /* original 0009, guest PC 0x0c050092 */
if(!s->budget--) { s->failed_pc=0x0c050092u; return 0; }
goto P_0c050094;
P_0c050094: /* original d512, guest PC 0x0c050094 */
if(!s->budget--) { s->failed_pc=0x0c050094u; return 0; }
r[5]=read(ram,0x0c0500e0u,4);
goto P_0c050096;
P_0c050096: /* original 3450, guest PC 0x0c050096 */
if(!s->budget--) { s->failed_pc=0x0c050096u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c050098;
P_0c050098: /* original 8b07, guest PC 0x0c050098 */
if(!s->budget--) { s->failed_pc=0x0c050098u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0500aa; }
goto P_0c05009a;
P_0c05009a: /* original dd12, guest PC 0x0c05009a */
if(!s->budget--) { s->failed_pc=0x0c05009au; return 0; }
r[13]=read(ram,0x0c0500e4u,4);
goto P_0c05009c;
P_0c05009c: /* original 2fe6, guest PC 0x0c05009c */
if(!s->budget--) { s->failed_pc=0x0c05009cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05009e;
P_0c05009e: /* original 2f46, guest PC 0x0c05009e */
if(!s->budget--) { s->failed_pc=0x0c05009eu; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500a0;
P_0c0500a0: /* original d20a, guest PC 0x0c0500a0 */
if(!s->budget--) { s->failed_pc=0x0c0500a0u; return 0; }
r[2]=read(ram,0x0c0500ccu,4);
goto P_0c0500a2;
P_0c0500a2: /* original 420b, guest PC 0x0c0500a2 */
if(!s->budget--) { s->failed_pc=0x0c0500a2u; return 0; }
target=r[2];
r[16]=0x0c0500a6u;
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0500a6u) { target=s->pc; goto dispatch; }
goto P_0c0500a6;
P_0c0500a4: /* original 2fd6, guest PC 0x0c0500a4 */
if(!s->budget--) { s->failed_pc=0x0c0500a4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500a6;
P_0c0500a6: /* original a02e, guest PC 0x0c0500a6 */
if(!s->budget--) { s->failed_pc=0x0c0500a6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c050106;
P_0c0500a8: /* original 7f0c, guest PC 0x0c0500a8 */
if(!s->budget--) { s->failed_pc=0x0c0500a8u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0500aa;
P_0c0500aa: /* original d50f, guest PC 0x0c0500aa */
if(!s->budget--) { s->failed_pc=0x0c0500aau; return 0; }
r[5]=read(ram,0x0c0500e8u,4);
goto P_0c0500ac;
P_0c0500ac: /* original 3450, guest PC 0x0c0500ac */
if(!s->budget--) { s->failed_pc=0x0c0500acu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c0500ae;
P_0c0500ae: /* original 8b1f, guest PC 0x0c0500ae */
if(!s->budget--) { s->failed_pc=0x0c0500aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0500f0; }
goto P_0c0500b0;
P_0c0500b0: /* original dd0e, guest PC 0x0c0500b0 */
if(!s->budget--) { s->failed_pc=0x0c0500b0u; return 0; }
r[13]=read(ram,0x0c0500ecu,4);
goto P_0c0500b2;
P_0c0500b2: /* original 2fe6, guest PC 0x0c0500b2 */
if(!s->budget--) { s->failed_pc=0x0c0500b2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500b4;
P_0c0500b4: /* original 2f46, guest PC 0x0c0500b4 */
if(!s->budget--) { s->failed_pc=0x0c0500b4u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500b6;
P_0c0500b6: /* original d205, guest PC 0x0c0500b6 */
if(!s->budget--) { s->failed_pc=0x0c0500b6u; return 0; }
r[2]=read(ram,0x0c0500ccu,4);
goto P_0c0500b8;
P_0c0500b8: /* original 420b, guest PC 0x0c0500b8 */
if(!s->budget--) { s->failed_pc=0x0c0500b8u; return 0; }
target=r[2];
r[16]=0x0c0500bcu;
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0500bcu) { target=s->pc; goto dispatch; }
goto P_0c0500bc;
P_0c0500ba: /* original 2fd6, guest PC 0x0c0500ba */
if(!s->budget--) { s->failed_pc=0x0c0500bau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500bc;
P_0c0500bc: /* original a023, guest PC 0x0c0500bc */
if(!s->budget--) { s->failed_pc=0x0c0500bcu; return 0; }
r[15]+=0x0000000cu;
goto P_0c050106;
P_0c0500be: /* original 7f0c, guest PC 0x0c0500be */
if(!s->budget--) { s->failed_pc=0x0c0500beu; return 0; }
r[15]+=0x0000000cu;
return vf3_matrix_family(0x0c0500c0u,s,ram);
P_0c0500f0: /* original 52b7, guest PC 0x0c0500f0 */
if(!s->budget--) { s->failed_pc=0x0c0500f0u; return 0; }
r[2]=read(ram,r[11]+28,4);
goto P_0c0500f2;
P_0c0500f2: /* original 532c, guest PC 0x0c0500f2 */
if(!s->budget--) { s->failed_pc=0x0c0500f2u; return 0; }
r[3]=read(ram,r[2]+48,4);
goto P_0c0500f4;
P_0c0500f4: /* original 3433, guest PC 0x0c0500f4 */
if(!s->budget--) { s->failed_pc=0x0c0500f4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0500f6;
P_0c0500f6: /* original 8b09, guest PC 0x0c0500f6 */
if(!s->budget--) { s->failed_pc=0x0c0500f6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05010c; }
goto P_0c0500f8;
P_0c0500f8: /* original dd56, guest PC 0x0c0500f8 */
if(!s->budget--) { s->failed_pc=0x0c0500f8u; return 0; }
r[13]=read(ram,0x0c050254u,4);
goto P_0c0500fa;
P_0c0500fa: /* original 2fe6, guest PC 0x0c0500fa */
if(!s->budget--) { s->failed_pc=0x0c0500fau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500fc;
P_0c0500fc: /* original 2f46, guest PC 0x0c0500fc */
if(!s->budget--) { s->failed_pc=0x0c0500fcu; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0500fe;
P_0c0500fe: /* original d356, guest PC 0x0c0500fe */
if(!s->budget--) { s->failed_pc=0x0c0500feu; return 0; }
r[3]=read(ram,0x0c050258u,4);
goto P_0c050100;
P_0c050100: /* original 430b, guest PC 0x0c050100 */
if(!s->budget--) { s->failed_pc=0x0c050100u; return 0; }
target=r[3];
r[16]=0x0c050104u;
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c050104u) { target=s->pc; goto dispatch; }
goto P_0c050104;
P_0c050102: /* original 2fd6, guest PC 0x0c050102 */
if(!s->budget--) { s->failed_pc=0x0c050102u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050104;
P_0c050104: /* original 7f0c, guest PC 0x0c050104 */
if(!s->budget--) { s->failed_pc=0x0c050104u; return 0; }
r[15]+=0x0000000cu;
goto P_0c050106;
P_0c050106: /* original 90a3, guest PC 0x0c050106 */
if(!s->budget--) { s->failed_pc=0x0c050106u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c050250u,2);
goto P_0c050108;
P_0c050108: /* original a006, guest PC 0x0c050108 */
if(!s->budget--) { s->failed_pc=0x0c050108u; return 0; }
goto P_0c050118;
P_0c05010a: /* original 0009, guest PC 0x0c05010a */
if(!s->budget--) { s->failed_pc=0x0c05010au; return 0; }
goto P_0c05010c;
P_0c05010c: /* original 7c01, guest PC 0x0c05010c */
if(!s->budget--) { s->failed_pc=0x0c05010cu; return 0; }
r[12]+=0x00000001u;
goto P_0c05010e;
P_0c05010e: /* original 6e43, guest PC 0x0c05010e */
if(!s->budget--) { s->failed_pc=0x0c05010eu; return 0; }
r[14]=r[4];
goto P_0c050110;
P_0c050110: /* original 52fb, guest PC 0x0c050110 */
if(!s->budget--) { s->failed_pc=0x0c050110u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c050112;
P_0c050112: /* original 3c23, guest PC 0x0c050112 */
if(!s->budget--) { s->failed_pc=0x0c050112u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[2])!=0);
goto P_0c050114;
P_0c050114: /* original 8b9d, guest PC 0x0c050114 */
if(!s->budget--) { s->failed_pc=0x0c050114u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050052; }
goto P_0c050116;
P_0c050116: /* original e000, guest PC 0x0c050116 */
if(!s->budget--) { s->failed_pc=0x0c050116u; return 0; }
r[0]=0x00000000u;
goto P_0c050118;
P_0c050118: /* original 7f30, guest PC 0x0c050118 */
if(!s->budget--) { s->failed_pc=0x0c050118u; return 0; }
r[15]+=0x00000030u;
goto P_0c05011a;
P_0c05011a: /* original 4f16, guest PC 0x0c05011a */
if(!s->budget--) { s->failed_pc=0x0c05011au; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c05011c;
P_0c05011c: /* original 4f26, guest PC 0x0c05011c */
if(!s->budget--) { s->failed_pc=0x0c05011cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05011e;
P_0c05011e: /* original 6bf6, guest PC 0x0c05011e */
if(!s->budget--) { s->failed_pc=0x0c05011eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c050120;
P_0c050120: /* original 6cf6, guest PC 0x0c050120 */
if(!s->budget--) { s->failed_pc=0x0c050120u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c050122;
P_0c050122: /* original 6df6, guest PC 0x0c050122 */
if(!s->budget--) { s->failed_pc=0x0c050122u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c050124;
P_0c050124: /* original 000b, guest PC 0x0c050124 */
if(!s->budget--) { s->failed_pc=0x0c050124u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c050126: /* original 6ef6, guest PC 0x0c050126 */
if(!s->budget--) { s->failed_pc=0x0c050126u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c050128u,s,ram);
P_0c050164: /* original 2fe6, guest PC 0x0c050164 */
if(!s->budget--) { s->failed_pc=0x0c050164u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050166;
P_0c050166: /* original e064, guest PC 0x0c050166 */
if(!s->budget--) { s->failed_pc=0x0c050166u; return 0; }
r[0]=0x00000064u;
goto P_0c050168;
P_0c050168: /* original 2fd6, guest PC 0x0c050168 */
if(!s->budget--) { s->failed_pc=0x0c050168u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05016a;
P_0c05016a: /* original 6d53, guest PC 0x0c05016a */
if(!s->budget--) { s->failed_pc=0x0c05016au; return 0; }
r[13]=r[5];
goto P_0c05016c;
P_0c05016c: /* original 2f86, guest PC 0x0c05016c */
if(!s->budget--) { s->failed_pc=0x0c05016cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05016e;
P_0c05016e: /* original 6e43, guest PC 0x0c05016e */
if(!s->budget--) { s->failed_pc=0x0c05016eu; return 0; }
r[14]=r[4];
goto P_0c050170;
P_0c050170: /* original 61d1, guest PC 0x0c050170 */
if(!s->budget--) { s->failed_pc=0x0c050170u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[1]=tmp;
goto P_0c050172;
P_0c050172: /* original 6843, guest PC 0x0c050172 */
if(!s->budget--) { s->failed_pc=0x0c050172u; return 0; }
r[8]=r[4];
return vf3_matrix_family(0x0c050174u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c046598u,0x0c04659au,0x0c04659cu,0x0c04659eu,0x0c0465a0u,0x0c0465a2u,0x0c0465a4u,0x0c0465a6u,0x0c0465a8u,0x0c0465aau,0x0c0465acu,0x0c0465aeu,0x0c0465b0u,0x0c0465b2u,0x0c0465b4u,0x0c0465b6u,
0x0c0465b8u,0x0c0465bau,0x0c0465bcu,0x0c0465beu,0x0c0465c0u,0x0c0465c2u,0x0c0465c4u,0x0c0465c6u,0x0c0465c8u,0x0c0465cau,0x0c0465ccu,0x0c0465ceu,0x0c0465d4u,0x0c0465d6u,0x0c0465d8u,0x0c0465dau,
0x0c0465dcu,0x0c0465deu,0x0c0465e0u,0x0c0465e2u,0x0c0465e4u,0x0c0465e6u,0x0c0465e8u,0x0c0465eau,0x0c0465ecu,0x0c0465eeu,0x0c0465f0u,0x0c0465f2u,0x0c0465f4u,0x0c0465f6u,0x0c0465f8u,0x0c0465fau,
0x0c0465fcu,0x0c0465feu,0x0c046600u,0x0c046602u,0x0c046604u,0x0c046606u,0x0c046608u,0x0c04660au,0x0c046620u,0x0c046622u,0x0c046624u,0x0c046626u,0x0c046628u,0x0c04662au,0x0c04662cu,0x0c04662eu,
0x0c046630u,0x0c046632u,0x0c046634u,0x0c046636u,0x0c046638u,0x0c04663au,0x0c04663cu,0x0c04663eu,0x0c046640u,0x0c046642u,0x0c046644u,0x0c046646u,0x0c046648u,0x0c04664au,0x0c04664cu,0x0c04664eu,
0x0c046650u,0x0c046652u,0x0c046654u,0x0c046656u,0x0c046658u,0x0c04665au,0x0c04665cu,0x0c04665eu,0x0c046660u,0x0c046662u,0x0c046664u,0x0c046666u,0x0c046668u,0x0c04666au,0x0c04666cu,0x0c04666eu,
0x0c046670u,0x0c046672u,0x0c046674u,0x0c046676u,0x0c046678u,0x0c0467bau,0x0c0467bcu,0x0c0467beu,0x0c0467c0u,0x0c0467c2u,0x0c0467c4u,0x0c0467c6u,0x0c0467c8u,0x0c0467cau,0x0c0467ccu,0x0c0467ceu,
0x0c0467d0u,0x0c0467d2u,0x0c0467d4u,0x0c0467d6u,0x0c0467d8u,0x0c0467dau,0x0c0467dcu,0x0c0467deu,0x0c0467e0u,0x0c0467e2u,0x0c0467ecu,0x0c0467eeu,0x0c0467f0u,0x0c0467f2u,0x0c0467f4u,0x0c0467f6u,
0x0c0467f8u,0x0c0467fau,0x0c0467fcu,0x0c0467feu,0x0c046800u,0x0c046802u,0x0c046804u,0x0c046806u,0x0c046808u,0x0c04680au,0x0c04680cu,0x0c04680eu,0x0c046810u,0x0c046812u,0x0c046814u,0x0c046816u,
0x0c046818u,0x0c046822u,0x0c046824u,0x0c046826u,0x0c046828u,0x0c04682au,0x0c04682cu,0x0c04682eu,0x0c046830u,0x0c046832u,0x0c046834u,0x0c046836u,0x0c046838u,0x0c04683au,0x0c04683cu,0x0c04683eu,
0x0c046840u,0x0c046842u,0x0c046844u,0x0c046846u,0x0c046848u,0x0c04684au,0x0c04684cu,0x0c04684eu,0x0c046976u,0x0c046978u,0x0c04697au,0x0c04697cu,0x0c04697eu,0x0c046980u,0x0c046982u,0x0c046984u,
0x0c046986u,0x0c046988u,0x0c04698au,0x0c04698cu,0x0c04698eu,0x0c046990u,0x0c046992u,0x0c046994u,0x0c046996u,0x0c046998u,0x0c04699au,0x0c04699cu,0x0c04699eu,0x0c0469a0u,0x0c0469a2u,0x0c0469a4u,
0x0c0469a6u,0x0c0469a8u,0x0c0469aau,0x0c0469acu,0x0c0469aeu,0x0c0469b0u,0x0c0469b2u,0x0c0469b4u,0x0c0469b6u,0x0c0469b8u,0x0c046a3au,0x0c046a3cu,0x0c046a3eu,0x0c046a40u,0x0c046a42u,0x0c046a44u,
0x0c046a46u,0x0c046a48u,0x0c046a4au,0x0c046a4cu,0x0c046a4eu,0x0c046a50u,0x0c046a52u,0x0c046a54u,0x0c046a56u,0x0c046a58u,0x0c046a5au,0x0c046a5cu,0x0c046a5eu,0x0c046a60u,0x0c046a62u,0x0c046a64u,
0x0c046a66u,0x0c046a68u,0x0c046a6au,0x0c046a6cu,0x0c046a6eu,0x0c046a70u,0x0c046a72u,0x0c046a74u,0x0c046a76u,0x0c046a78u,0x0c046a7au,0x0c046a7cu,0x0c046a7eu,0x0c046a80u,0x0c046a82u,0x0c046a84u,
0x0c046a86u,0x0c046a88u,0x0c046a8au,0x0c046a8cu,0x0c046a8eu,0x0c046a90u,0x0c046a92u,0x0c046a94u,0x0c046a96u,0x0c046a98u,0x0c046a9au,0x0c046a9cu,0x0c046a9eu,0x0c046aa0u,0x0c046aa2u,0x0c046aa4u,
0x0c046aa6u,0x0c046aa8u,0x0c046aaau,0x0c046aacu,0x0c046aaeu,0x0c046ab0u,0x0c046ab2u,0x0c046abcu,0x0c046abeu,0x0c046ac0u,0x0c046ac2u,0x0c046ac4u,0x0c046ac6u,0x0c046ac8u,0x0c046acau,0x0c046accu,
0x0c046aceu,0x0c046ad0u,0x0c046ad2u,0x0c046ad4u,0x0c046ad6u,0x0c046ad8u,0x0c046adau,0x0c046adcu,0x0c046adeu,0x0c046ae0u,0x0c046ae2u,0x0c046ae4u,0x0c046b34u,0x0c046b36u,0x0c046b38u,0x0c046b3au,
0x0c046b3cu,0x0c046b3eu,0x0c046b40u,0x0c046b42u,0x0c046b44u,0x0c046b46u,0x0c046b48u,0x0c046b4au,0x0c046b4cu,0x0c046b4eu,0x0c046b50u,0x0c046b52u,0x0c046b54u,0x0c046b56u,0x0c046b58u,0x0c046b5au,
0x0c046b5cu,0x0c046b5eu,0x0c046b60u,0x0c046b62u,0x0c046b64u,0x0c046b66u,0x0c046b68u,0x0c046b6au,0x0c046b6cu,0x0c046b6eu,0x0c046b70u,0x0c046b72u,0x0c046b74u,0x0c046b76u,0x0c046b78u,0x0c046b7au,
0x0c046b7cu,0x0c046b7eu,0x0c046b80u,0x0c046b82u,0x0c046b84u,0x0c046b86u,0x0c046b88u,0x0c046b8au,0x0c046b8cu,0x0c046b8eu,0x0c046b90u,0x0c046b92u,0x0c046b94u,0x0c046b96u,0x0c046b98u,0x0c046b9au,
0x0c046b9cu,0x0c046b9eu,0x0c046ba0u,0x0c046ba2u,0x0c046bb2u,0x0c046bb4u,0x0c046bb6u,0x0c046bb8u,0x0c046bbau,0x0c046bbcu,0x0c046bbeu,0x0c046bc0u,0x0c046bc2u,0x0c046bc4u,0x0c046bc6u,0x0c046bc8u,
0x0c046bcau,0x0c046bccu,0x0c046bceu,0x0c046bd0u,0x0c046bd2u,0x0c046bd4u,0x0c046bd6u,0x0c046bd8u,0x0c046bdau,0x0c046bdcu,0x0c046bdeu,0x0c046be0u,0x0c046be2u,0x0c046be4u,0x0c046be6u,0x0c046be8u,
0x0c046beau,0x0c046becu,0x0c046beeu,0x0c046bfau,0x0c046bfcu,0x0c046bfeu,0x0c046c00u,0x0c046c02u,0x0c046c04u,0x0c046c06u,0x0c046c08u,0x0c046c0au,0x0c046c0cu,0x0c046c0eu,0x0c046c10u,0x0c046c12u,
0x0c046c14u,0x0c046c16u,0x0c046c18u,0x0c046c1au,0x0c046c1cu,0x0c046c1eu,0x0c046c20u,0x0c046c22u,0x0c046c24u,0x0c046c26u,0x0c046c28u,0x0c046c2au,0x0c046c2cu,0x0c046c2eu,0x0c046c30u,0x0c046c32u,
0x0c046c34u,0x0c046c36u,0x0c046c38u,0x0c046c3au,0x0c046c3cu,0x0c046c3eu,0x0c046c40u,0x0c046c42u,0x0c046c44u,0x0c046c46u,0x0c046c50u,0x0c046c52u,0x0c046c54u,0x0c046c56u,0x0c046c58u,0x0c046c5au,
0x0c046c5cu,0x0c046c5eu,0x0c046c60u,0x0c046c62u,0x0c046c64u,0x0c046c66u,0x0c046c68u,0x0c046c6au,0x0c046c6cu,0x0c046c6eu,0x0c046c70u,0x0c046c72u,0x0c046c74u,0x0c046c76u,0x0c046c78u,0x0c046c7au,
0x0c046c7cu,0x0c046c7eu,0x0c046c80u,0x0c046c82u,0x0c046c84u,0x0c046c86u,0x0c046c88u,0x0c046c8au,0x0c046c8cu,0x0c046c8eu,0x0c046c90u,0x0c046c92u,0x0c046c94u,0x0c046c96u,0x0c046c98u,0x0c046c9au,
0x0c046c9cu,0x0c046c9eu,0x0c046ca0u,0x0c046ca2u,0x0c046ca4u,0x0c046cd4u,0x0c046cd6u,0x0c046cd8u,0x0c046cdau,0x0c046cdcu,0x0c046cdeu,0x0c046ce0u,0x0c046ce2u,0x0c046ce4u,0x0c046ce6u,0x0c046ce8u,
0x0c046ceau,0x0c046cecu,0x0c046ceeu,0x0c046cf0u,0x0c046cf2u,0x0c046cf4u,0x0c046cf6u,0x0c046cf8u,0x0c046cfau,0x0c046cfcu,0x0c046cfeu,0x0c046d00u,0x0c046d02u,0x0c046d04u,0x0c046d06u,0x0c046d08u,
0x0c046d0au,0x0c046d0cu,0x0c046d0eu,0x0c046d10u,0x0c046d12u,0x0c046d14u,0x0c046d16u,0x0c046d18u,0x0c046d1au,0x0c046d1cu,0x0c046d1eu,0x0c046d20u,0x0c046d22u,0x0c046d24u,0x0c046d26u,0x0c046d28u,
0x0c046d32u,0x0c046d34u,0x0c046d36u,0x0c046d38u,0x0c046d3au,0x0c046d3cu,0x0c046d3eu,0x0c046d40u,0x0c046d42u,0x0c046d44u,0x0c046d46u,0x0c046d48u,0x0c046d4au,0x0c046d4cu,0x0c046d4eu,0x0c046d50u,
0x0c046d52u,0x0c046d54u,0x0c046d56u,0x0c046d58u,0x0c046d5au,0x0c046d5cu,0x0c046d5eu,0x0c046d60u,0x0c046d62u,0x0c046d64u,0x0c046d66u,0x0c046d68u,0x0c046d6au,0x0c046d6cu,0x0c046d6eu,0x0c046d70u,
0x0c046d72u,0x0c046d74u,0x0c046d76u,0x0c046d78u,0x0c046d7au,0x0c046d7cu,0x0c046d7eu,0x0c046d86u,0x0c046d88u,0x0c046d8au,0x0c046d8cu,0x0c046d8eu,0x0c046d90u,0x0c046d92u,0x0c046d94u,0x0c046d96u,
0x0c046d98u,0x0c046d9au,0x0c046d9cu,0x0c046d9eu,0x0c046da0u,0x0c046da2u,0x0c046da4u,0x0c046da6u,0x0c046da8u,0x0c046daau,0x0c046dacu,0x0c046daeu,0x0c046db0u,0x0c046db2u,0x0c046db4u,0x0c046db6u,
0x0c046db8u,0x0c046dbau,0x0c046dbcu,0x0c046dbeu,0x0c046dc0u,0x0c046dc2u,0x0c046dcau,0x0c046dccu,0x0c046dceu,0x0c046dd0u,0x0c046dd2u,0x0c046dd4u,0x0c046dd6u,0x0c046dd8u,0x0c046ddau,0x0c046ddcu,
0x0c046ddeu,0x0c046de0u,0x0c046de2u,0x0c046de4u,0x0c046de6u,0x0c046de8u,0x0c046deau,0x0c046decu,0x0c046deeu,0x0c046df0u,0x0c046df2u,0x0c046df4u,0x0c046df6u,0x0c046df8u,0x0c046dfau,0x0c046dfcu,
0x0c046dfeu,0x0c046e00u,0x0c046e02u,0x0c046e04u,0x0c046e06u,0x0c04c4c0u,0x0c04c4c2u,0x0c04c4c4u,0x0c04c4c6u,0x0c04c4c8u,0x0c04c4cau,0x0c04c4ccu,0x0c04c4ceu,0x0c04c4d0u,0x0c04c4d2u,0x0c04c4d4u,
0x0c04c4d6u,0x0c04c4d8u,0x0c04c4dau,0x0c04c4dcu,0x0c04c4deu,0x0c04c4e0u,0x0c04c4e2u,0x0c04c4e4u,0x0c04c4e6u,0x0c04c4e8u,0x0c04c4f0u,0x0c04c4f2u,0x0c04c4f4u,0x0c04c4f6u,0x0c04c4f8u,0x0c04c4fau,
0x0c04c4fcu,0x0c04c4feu,0x0c04c500u,0x0c04c502u,0x0c04c504u,0x0c04c506u,0x0c04c508u,0x0c04c50au,0x0c04c50cu,0x0c04c50eu,0x0c04c510u,0x0c04c512u,0x0c04c514u,0x0c04c516u,0x0c04c518u,0x0c04c51au,
0x0c04c51cu,0x0c04c51eu,0x0c04c520u,0x0c04c522u,0x0c04c524u,0x0c04c526u,0x0c04c528u,0x0c04c52au,0x0c04c52cu,0x0c04c52eu,0x0c04c530u,0x0c04c532u,0x0c04c534u,0x0c04c536u,0x0c04c538u,0x0c04c53au,
0x0c04c53cu,0x0c04c53eu,0x0c04c540u,0x0c04c542u,0x0c04c544u,0x0c04c546u,0x0c04c548u,0x0c04c54au,0x0c04c54cu,0x0c04c54eu,0x0c04c550u,0x0c04c552u,0x0c04c554u,0x0c04c556u,0x0c04c558u,0x0c04c55au,
0x0c04c55cu,0x0c04c55eu,0x0c04c560u,0x0c04c562u,0x0c04c564u,0x0c04c566u,0x0c04c568u,0x0c04c56au,0x0c04c56cu,0x0c04c56eu,0x0c04c570u,0x0c04c572u,0x0c04c574u,0x0c04c576u,0x0c04c578u,0x0c04c57au,
0x0c04c57cu,0x0c04c57eu,0x0c04c580u,0x0c04c582u,0x0c04c584u,0x0c04c586u,0x0c04c588u,0x0c04c58au,0x0c04c58cu,0x0c04c58eu,0x0c04c590u,0x0c04c592u,0x0c04c594u,0x0c04cf0eu,0x0c04cf10u,0x0c04cf12u,
0x0c04cf14u,0x0c04cf16u,0x0c04cf18u,0x0c04cf1au,0x0c04cf1cu,0x0c04cf1eu,0x0c04cf20u,0x0c04cf22u,0x0c04cf24u,0x0c04cf26u,0x0c04cf28u,0x0c04cf2au,0x0c04cf2cu,0x0c04cf2eu,0x0c04cf30u,0x0c04cf32u,
0x0c04cf34u,0x0c04cf36u,0x0c04cf38u,0x0c04cf3au,0x0c04cf3cu,0x0c04cf3eu,0x0c04cf40u,0x0c04cf42u,0x0c04cf44u,0x0c04cf46u,0x0c04cf48u,0x0c04cf4au,0x0c04cf4cu,0x0c04cf4eu,0x0c04cf50u,0x0c04cf52u,
0x0c04cf54u,0x0c04cf56u,0x0c04cf80u,0x0c04cf82u,0x0c04cf84u,0x0c04cf86u,0x0c04cf88u,0x0c04cf8au,0x0c04cf8cu,0x0c04cf8eu,0x0c04cf90u,0x0c04cf92u,0x0c04cf94u,0x0c04cf96u,0x0c04cf98u,0x0c04cf9au,
0x0c04cf9cu,0x0c04cf9eu,0x0c04cfa0u,0x0c04cfa2u,0x0c04cfa4u,0x0c04cfa6u,0x0c04cfa8u,0x0c04cfaau,0x0c04cfacu,0x0c04cfaeu,0x0c04cfb0u,0x0c04cfb2u,0x0c04cfb4u,0x0c04cfb6u,0x0c04cfb8u,0x0c04cfbau,
0x0c04cfbcu,0x0c04cfbeu,0x0c04cfc0u,0x0c04cfc2u,0x0c04cfc4u,0x0c04cfc6u,0x0c04cfc8u,0x0c04cfcau,0x0c04cfccu,0x0c04cfceu,0x0c04cfd0u,0x0c04cfd2u,0x0c04cfd4u,0x0c04cfd6u,0x0c04cfd8u,0x0c04cfdau,
0x0c04cfdcu,0x0c04cfdeu,0x0c04cfe0u,0x0c04cfe2u,0x0c04cfe4u,0x0c04cfe6u,0x0c04cfe8u,0x0c04cfeau,0x0c04cfecu,0x0c04cfeeu,0x0c04cff0u,0x0c04cff2u,0x0c04cff4u,0x0c04cff6u,0x0c04cff8u,0x0c04cffau,
0x0c04cffcu,0x0c04cffeu,0x0c04d000u,0x0c04d002u,0x0c04d004u,0x0c04d006u,0x0c04d008u,0x0c04d00au,0x0c04d00cu,0x0c04d00eu,0x0c04d800u,0x0c04d802u,0x0c04d804u,0x0c04d806u,0x0c04d808u,0x0c04d80au,
0x0c04d80cu,0x0c04d80eu,0x0c04d810u,0x0c04d812u,0x0c04d814u,0x0c04d816u,0x0c04d818u,0x0c04d81au,0x0c04d81cu,0x0c04d81eu,0x0c04d820u,0x0c04d822u,0x0c04d824u,0x0c04d826u,0x0c04d828u,0x0c04d82au,
0x0c04d82cu,0x0c04d82eu,0x0c04d830u,0x0c04d832u,0x0c04d834u,0x0c04d836u,0x0c04d838u,0x0c04d83au,0x0c04d83cu,0x0c04d83eu,0x0c04d840u,0x0c04d842u,0x0c04d844u,0x0c04d846u,0x0c04d848u,0x0c04d84au,
0x0c04d84cu,0x0c04d84eu,0x0c04d850u,0x0c04d852u,0x0c04d854u,0x0c04d856u,0x0c04d858u,0x0c04d85au,0x0c04d85cu,0x0c04d85eu,0x0c04d860u,0x0c04d862u,0x0c04d864u,0x0c04d866u,0x0c04d868u,0x0c04d86au,
0x0c04d86cu,0x0c04d86eu,0x0c04d870u,0x0c04d872u,0x0c04d874u,0x0c04d876u,0x0c04d878u,0x0c04d87au,0x0c04d8acu,0x0c04d8aeu,0x0c04d8b0u,0x0c04d8b2u,0x0c04d8b4u,0x0c04d8b6u,0x0c04d8b8u,0x0c04d8bau,
0x0c04d8bcu,0x0c04d8beu,0x0c04d8c0u,0x0c04d8c2u,0x0c04d8c4u,0x0c04d8c6u,0x0c04d8c8u,0x0c04d8cau,0x0c04d8ccu,0x0c04d8ceu,0x0c04d8d0u,0x0c04d8d2u,0x0c04d8d4u,0x0c04d8d6u,0x0c04d8d8u,0x0c04d8dau,
0x0c04d8dcu,0x0c04d8deu,0x0c04d8e0u,0x0c04d8e2u,0x0c04d8e4u,0x0c04d8e6u,0x0c04d8e8u,0x0c04d8eau,0x0c04d8ecu,0x0c04d8eeu,0x0c04d8f0u,0x0c04d8f2u,0x0c04d8f4u,0x0c04d8f6u,0x0c04d8f8u,0x0c04d8fau,
0x0c04d8fcu,0x0c04d8feu,0x0c04d900u,0x0c04d902u,0x0c04d904u,0x0c04d906u,0x0c04d908u,0x0c04d90au,0x0c04d90cu,0x0c04d90eu,0x0c04d910u,0x0c04d912u,0x0c04d914u,0x0c04d916u,0x0c04d918u,0x0c04d91au,
0x0c04d91cu,0x0c04d91eu,0x0c04d920u,0x0c04d922u,0x0c04d924u,0x0c04d926u,0x0c04d928u,0x0c04d92au,0x0c04d92cu,0x0c04d92eu,0x0c04d930u,0x0c04d932u,0x0c04d934u,0x0c04d936u,0x0c04d938u,0x0c04d93au,
0x0c04d93cu,0x0c04d93eu,0x0c04d940u,0x0c04d942u,0x0c04d944u,0x0c04d946u,0x0c04d948u,0x0c04d94au,0x0c04d94cu,0x0c04d94eu,0x0c04d950u,0x0c04d952u,0x0c04d954u,0x0c04d956u,0x0c04d958u,0x0c04d95au,
0x0c04d95cu,0x0c04d95eu,0x0c04d960u,0x0c04d962u,0x0c04d964u,0x0c04d966u,0x0c04d968u,0x0c04d96au,0x0c04d96cu,0x0c04d96eu,0x0c04d970u,0x0c04d972u,0x0c04d974u,0x0c04d976u,0x0c04d978u,0x0c04d97au,
0x0c04d97cu,0x0c04d97eu,0x0c04d980u,0x0c04d982u,0x0c04d984u,0x0c04d986u,0x0c04d988u,0x0c04d98au,0x0c04d98cu,0x0c04d98eu,0x0c04d990u,0x0c04d992u,0x0c04d994u,0x0c04d996u,0x0c04d998u,0x0c04d99au,
0x0c04d99cu,0x0c04d99eu,0x0c04d9a0u,0x0c04d9a2u,0x0c04d9a4u,0x0c04d9a6u,0x0c04d9a8u,0x0c04d9aau,0x0c04d9acu,0x0c04d9aeu,0x0c04d9b0u,0x0c04d9b2u,0x0c04d9b4u,0x0c04d9b6u,0x0c04d9b8u,0x0c04d9fcu,
0x0c04d9feu,0x0c04da00u,0x0c04da02u,0x0c04da04u,0x0c04da06u,0x0c04da08u,0x0c04da0au,0x0c04da0cu,0x0c04da0eu,0x0c04da10u,0x0c04da12u,0x0c04da14u,0x0c04da16u,0x0c04da18u,0x0c04da1au,0x0c04da1cu,
0x0c04da1eu,0x0c04da20u,0x0c04da22u,0x0c04da24u,0x0c04da26u,0x0c04da28u,0x0c04da2au,0x0c04da2cu,0x0c04da2eu,0x0c04da30u,0x0c04da32u,0x0c04da34u,0x0c04da36u,0x0c04da38u,0x0c04da3au,0x0c04da3cu,
0x0c04da3eu,0x0c04da40u,0x0c04da42u,0x0c04da44u,0x0c04da46u,0x0c04da48u,0x0c04da4au,0x0c04da4cu,0x0c04da4eu,0x0c04da50u,0x0c04da52u,0x0c04da54u,0x0c04da56u,0x0c04da58u,0x0c04da5au,0x0c04da5cu,
0x0c04da5eu,0x0c04da60u,0x0c04da62u,0x0c04da64u,0x0c04da66u,0x0c04da68u,0x0c04da6au,0x0c04da6cu,0x0c04da6eu,0x0c04da70u,0x0c04da72u,0x0c04da74u,0x0c04da76u,0x0c04da78u,0x0c04da7au,0x0c04da7cu,
0x0c04da7eu,0x0c04da80u,0x0c04da82u,0x0c04da84u,0x0c04da86u,0x0c04da88u,0x0c04da8au,0x0c04da8cu,0x0c04da8eu,0x0c04da90u,0x0c04da92u,0x0c04da94u,0x0c04da96u,0x0c04da98u,0x0c04da9au,0x0c04da9cu,
0x0c04da9eu,0x0c04daa0u,0x0c04daa2u,0x0c04daa4u,0x0c04daa6u,0x0c04daa8u,0x0c04daaau,0x0c04daacu,0x0c04daaeu,0x0c04dab0u,0x0c04dab2u,0x0c04dab4u,0x0c04dab6u,0x0c04dab8u,0x0c04dabau,0x0c04dabcu,
0x0c04dabeu,0x0c04dac0u,0x0c04dac2u,0x0c04dac4u,0x0c04dac6u,0x0c04dac8u,0x0c04dacau,0x0c04daccu,0x0c04daceu,0x0c04dad0u,0x0c04dad2u,0x0c04dad4u,0x0c04dad6u,0x0c04dad8u,0x0c04dadau,0x0c04dadcu,
0x0c04db28u,0x0c04db2au,0x0c04db2cu,0x0c04db2eu,0x0c04db30u,0x0c04db32u,0x0c04db34u,0x0c04db36u,0x0c04db38u,0x0c04db3au,0x0c04db3cu,0x0c04db3eu,0x0c04db40u,0x0c04db42u,0x0c04db44u,0x0c04db46u,
0x0c04db48u,0x0c04db4au,0x0c04db4cu,0x0c04db4eu,0x0c04db50u,0x0c04db52u,0x0c04db54u,0x0c04db56u,0x0c04db58u,0x0c04db5au,0x0c04db5cu,0x0c04db5eu,0x0c04db60u,0x0c04db62u,0x0c04db64u,0x0c04db66u,
0x0c04db68u,0x0c04db6au,0x0c04db6cu,0x0c04db6eu,0x0c04db70u,0x0c04db72u,0x0c04db74u,0x0c04db76u,0x0c04db78u,0x0c04db7au,0x0c04db7cu,0x0c04db7eu,0x0c04db80u,0x0c04db82u,0x0c04db84u,0x0c04db86u,
0x0c04db88u,0x0c04db8au,0x0c04db8cu,0x0c04db8eu,0x0c04db90u,0x0c04db92u,0x0c04db94u,0x0c04db96u,0x0c04db98u,0x0c04db9au,0x0c04db9cu,0x0c04db9eu,0x0c04dba0u,0x0c04dba2u,0x0c04dba4u,0x0c04dba6u,
0x0c04dba8u,0x0c04dbaau,0x0c04dbacu,0x0c04dbaeu,0x0c04dbb0u,0x0c04dbb2u,0x0c04dbb4u,0x0c04dbb6u,0x0c04dbb8u,0x0c04dbbau,0x0c04dbbcu,0x0c04dbbeu,0x0c04dbc0u,0x0c04dbc2u,0x0c04dbc4u,0x0c04dbc6u,
0x0c04dbc8u,0x0c04dbcau,0x0c04dbccu,0x0c04dbceu,0x0c04dbd0u,0x0c04dbd2u,0x0c04dbd4u,0x0c04dbd6u,0x0c04dbd8u,0x0c04dbdau,0x0c04dbdcu,0x0c04dbdeu,0x0c04dbe0u,0x0c04dbe2u,0x0c04dbe4u,0x0c04dbe6u,
0x0c04dbe8u,0x0c04dbeau,0x0c04dbecu,0x0c04dbeeu,0x0c04dbf0u,0x0c04dbf2u,0x0c04dbf4u,0x0c04dbf6u,0x0c04dbf8u,0x0c04dbfau,0x0c04dbfcu,0x0c04dbfeu,0x0c04dc00u,0x0c04dc02u,0x0c04dc04u,0x0c04dc06u,
0x0c04dc08u,0x0c04dc0au,0x0c04dc0cu,0x0c04dc0eu,0x0c04dc10u,0x0c04dc12u,0x0c04dc14u,0x0c04dc16u,0x0c04dc18u,0x0c04dc50u,0x0c04dc52u,0x0c04dc54u,0x0c04dc56u,0x0c04dc58u,0x0c04dc5au,0x0c04dc5cu,
0x0c04dc5eu,0x0c04dc60u,0x0c04dc62u,0x0c04dc64u,0x0c04dc66u,0x0c04dc68u,0x0c04dc6au,0x0c04dc6cu,0x0c04dc6eu,0x0c04dc70u,0x0c04dc72u,0x0c04dc74u,0x0c04dc76u,0x0c04dc78u,0x0c04dc7au,0x0c04dc7cu,
0x0c04dc7eu,0x0c04dc80u,0x0c04dc82u,0x0c04dc84u,0x0c04dc86u,0x0c04dc88u,0x0c04dc8au,0x0c04dc8cu,0x0c04dc8eu,0x0c04dc90u,0x0c04dc92u,0x0c04dc94u,0x0c04dc96u,0x0c04dc98u,0x0c04dc9au,0x0c04dc9cu,
0x0c04dc9eu,0x0c04dca0u,0x0c04dca2u,0x0c04dca4u,0x0c04dca6u,0x0c04dca8u,0x0c04dcaau,0x0c04dcacu,0x0c04dcaeu,0x0c04dcb0u,0x0c04dcb2u,0x0c04dcb4u,0x0c04dcb6u,0x0c04dcb8u,0x0c04dcbau,0x0c04dcbcu,
0x0c04dcbeu,0x0c04dcc0u,0x0c04dcc2u,0x0c04dcc4u,0x0c04dcc6u,0x0c04dcc8u,0x0c04dccau,0x0c04dcccu,0x0c04dcceu,0x0c04e40eu,0x0c04e410u,0x0c04e712u,0x0c04e714u,0x0c04e716u,0x0c04e718u,0x0c04e71au,
0x0c04e71cu,0x0c04e71eu,0x0c04e720u,0x0c04e722u,0x0c04e724u,0x0c04e726u,0x0c04e728u,0x0c04e72au,0x0c04e72cu,0x0c04e72eu,0x0c04e730u,0x0c04e732u,0x0c04e734u,0x0c04e736u,0x0c04e738u,0x0c04e73au,
0x0c04e73cu,0x0c04e73eu,0x0c04e740u,0x0c04e742u,0x0c04e744u,0x0c04e746u,0x0c04e748u,0x0c04e74au,0x0c04e74cu,0x0c04e74eu,0x0c04e750u,0x0c04e752u,0x0c04e754u,0x0c04e756u,0x0c04e758u,0x0c04e75au,
0x0c04e75cu,0x0c04e75eu,0x0c04e760u,0x0c04e762u,0x0c04e764u,0x0c04e766u,0x0c04e768u,0x0c04e76au,0x0c04e76cu,0x0c04e76eu,0x0c04e770u,0x0c04e772u,0x0c04e774u,0x0c04e776u,0x0c04e778u,0x0c04e77au,
0x0c04e77cu,0x0c04e77eu,0x0c04e780u,0x0c04e782u,0x0c04e784u,0x0c04e786u,0x0c04e788u,0x0c04e78au,0x0c04e78cu,0x0c04e78eu,0x0c04e790u,0x0c04e792u,0x0c04e794u,0x0c04e796u,0x0c04e798u,0x0c04e79au,
0x0c04e79cu,0x0c04e79eu,0x0c04e7a0u,0x0c04e7a2u,0x0c04e7a4u,0x0c04e7a6u,0x0c04e7a8u,0x0c04e7aau,0x0c04e7acu,0x0c04eebeu,0x0c04eec0u,0x0c04eec2u,0x0c04eec4u,0x0c04eec6u,0x0c04eec8u,0x0c04eecau,
0x0c04eeccu,0x0c04eeceu,0x0c04eed0u,0x0c04eed2u,0x0c04eed4u,0x0c04eed6u,0x0c04eed8u,0x0c04eedau,0x0c04eedcu,0x0c04eedeu,0x0c04eee0u,0x0c04eee2u,0x0c04eee4u,0x0c04eee6u,0x0c04eee8u,0x0c04eeeau,
0x0c04eeecu,0x0c04eeeeu,0x0c04eef0u,0x0c04eef2u,0x0c04eef4u,0x0c04eef6u,0x0c04eef8u,0x0c04eefau,0x0c04eefcu,0x0c04eefeu,0x0c04ef00u,0x0c04ef02u,0x0c04ef04u,0x0c04ef06u,0x0c04ef08u,0x0c04ef0au,
0x0c04ef0cu,0x0c04ef48u,0x0c04ef4au,0x0c04ef4cu,0x0c04ef4eu,0x0c04ef50u,0x0c04ef52u,0x0c04ef54u,0x0c04ef56u,0x0c04ef58u,0x0c04ef5au,0x0c04ef5cu,0x0c04ef5eu,0x0c04ef60u,0x0c04ef62u,0x0c04ef64u,
0x0c04ef66u,0x0c04ef68u,0x0c04ef6au,0x0c04ef6cu,0x0c04ef6eu,0x0c04ef70u,0x0c04ef72u,0x0c04ef74u,0x0c04ef76u,0x0c04ef78u,0x0c04ef7au,0x0c04ef7cu,0x0c04ef7eu,0x0c04ef80u,0x0c04ef82u,0x0c04ef84u,
0x0c04ef86u,0x0c04ef88u,0x0c04ef8au,0x0c04fa7cu,0x0c04fa7eu,0x0c04fa80u,0x0c04fa82u,0x0c04fa84u,0x0c04fa86u,0x0c04fa88u,0x0c04fa8au,0x0c04fa8cu,0x0c04fa8eu,0x0c04fa90u,0x0c04fa92u,0x0c04fa94u,
0x0c04fa96u,0x0c04fa98u,0x0c04fa9au,0x0c04fa9cu,0x0c04fa9eu,0x0c04faa0u,0x0c04faa2u,0x0c04faa4u,0x0c04faa6u,0x0c04faa8u,0x0c04faaau,0x0c04faacu,0x0c04faaeu,0x0c04fe40u,0x0c04fe42u,0x0c04fe44u,
0x0c04ff62u,0x0c04ff64u,0x0c04ff66u,0x0c04ff68u,0x0c04ff6au,0x0c04ff6cu,0x0c04ff6eu,0x0c04ff70u,0x0c04ff72u,0x0c04ff74u,0x0c04ff76u,0x0c04ff78u,0x0c04ff7au,0x0c04ff7cu,0x0c04ff7eu,0x0c04ff80u,
0x0c04ff82u,0x0c04ff84u,0x0c04ff86u,0x0c04ff88u,0x0c04ff8au,0x0c04ff8cu,0x0c04ff8eu,0x0c04ff90u,0x0c04ff92u,0x0c04ff94u,0x0c04ff96u,0x0c04ff98u,0x0c04ff9au,0x0c04ff9cu,0x0c04ff9eu,0x0c04ffa0u,
0x0c04ffa2u,0x0c04ffa4u,0x0c04ffa6u,0x0c04ffa8u,0x0c04ffaau,0x0c04ffacu,0x0c04ffaeu,0x0c04ffb0u,0x0c04ffb2u,0x0c04ffb4u,0x0c04ffb6u,0x0c04ffb8u,0x0c04ffbau,0x0c04ffbcu,0x0c04ffbeu,0x0c04ffc0u,
0x0c04ffc2u,0x0c04ffc4u,0x0c04ffc6u,0x0c04ffc8u,0x0c04ffcau,0x0c04ffccu,0x0c04ffceu,0x0c04ffd0u,0x0c04ffd2u,0x0c04ffd4u,0x0c04ffd6u,0x0c04ffd8u,0x0c04fffcu,0x0c04fffeu,0x0c050000u,0x0c050002u,
0x0c050004u,0x0c050006u,0x0c050008u,0x0c05000au,0x0c05000cu,0x0c05000eu,0x0c050010u,0x0c050012u,0x0c050014u,0x0c050016u,0x0c050018u,0x0c05001au,0x0c05001cu,0x0c05001eu,0x0c050020u,0x0c050022u,
0x0c050024u,0x0c050026u,0x0c050028u,0x0c05002au,0x0c05002cu,0x0c05002eu,0x0c050030u,0x0c050032u,0x0c050034u,0x0c050036u,0x0c050038u,0x0c05003au,0x0c05003cu,0x0c05003eu,0x0c050040u,0x0c050042u,
0x0c050044u,0x0c050046u,0x0c050048u,0x0c05004au,0x0c05004cu,0x0c05004eu,0x0c050050u,0x0c050052u,0x0c050054u,0x0c050056u,0x0c050058u,0x0c05005au,0x0c05005cu,0x0c05005eu,0x0c050060u,0x0c050062u,
0x0c050064u,0x0c050066u,0x0c050068u,0x0c05006au,0x0c05006cu,0x0c05006eu,0x0c050070u,0x0c050072u,0x0c050074u,0x0c050076u,0x0c050078u,0x0c05007au,0x0c05007cu,0x0c05007eu,0x0c050080u,0x0c050082u,
0x0c050084u,0x0c050086u,0x0c050088u,0x0c05008au,0x0c05008cu,0x0c05008eu,0x0c050090u,0x0c050092u,0x0c050094u,0x0c050096u,0x0c050098u,0x0c05009au,0x0c05009cu,0x0c05009eu,0x0c0500a0u,0x0c0500a2u,
0x0c0500a4u,0x0c0500a6u,0x0c0500a8u,0x0c0500aau,0x0c0500acu,0x0c0500aeu,0x0c0500b0u,0x0c0500b2u,0x0c0500b4u,0x0c0500b6u,0x0c0500b8u,0x0c0500bau,0x0c0500bcu,0x0c0500beu,0x0c0500f0u,0x0c0500f2u,
0x0c0500f4u,0x0c0500f6u,0x0c0500f8u,0x0c0500fau,0x0c0500fcu,0x0c0500feu,0x0c050100u,0x0c050102u,0x0c050104u,0x0c050106u,0x0c050108u,0x0c05010au,0x0c05010cu,0x0c05010eu,0x0c050110u,0x0c050112u,
0x0c050114u,0x0c050116u,0x0c050118u,0x0c05011au,0x0c05011cu,0x0c05011eu,0x0c050120u,0x0c050122u,0x0c050124u,0x0c050126u,0x0c050164u,0x0c050166u,0x0c050168u,0x0c05016au,0x0c05016cu,0x0c05016eu,
0x0c050170u,0x0c050172u,
};
int vf3_record_pool_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
