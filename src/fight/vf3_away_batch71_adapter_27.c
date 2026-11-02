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
int vf3_away_batch71_adapter_27(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09690au: goto P_0c09690a;
case 0x0c09690cu: goto P_0c09690c;
case 0x0c09690eu: goto P_0c09690e;
case 0x0c096910u: goto P_0c096910;
case 0x0c096912u: goto P_0c096912;
case 0x0c096944u: goto P_0c096944;
case 0x0c096946u: goto P_0c096946;
case 0x0c096948u: goto P_0c096948;
case 0x0c09694au: goto P_0c09694a;
case 0x0c09694cu: goto P_0c09694c;
case 0x0c09694eu: goto P_0c09694e;
case 0x0c096950u: goto P_0c096950;
case 0x0c096952u: goto P_0c096952;
case 0x0c096954u: goto P_0c096954;
case 0x0c096956u: goto P_0c096956;
case 0x0c096958u: goto P_0c096958;
case 0x0c09695au: goto P_0c09695a;
case 0x0c09695cu: goto P_0c09695c;
case 0x0c09695eu: goto P_0c09695e;
case 0x0c096960u: goto P_0c096960;
case 0x0c096962u: goto P_0c096962;
case 0x0c096964u: goto P_0c096964;
case 0x0c096966u: goto P_0c096966;
case 0x0c096968u: goto P_0c096968;
case 0x0c09696au: goto P_0c09696a;
case 0x0c09696cu: goto P_0c09696c;
case 0x0c09696eu: goto P_0c09696e;
case 0x0c096970u: goto P_0c096970;
case 0x0c096972u: goto P_0c096972;
case 0x0c096974u: goto P_0c096974;
case 0x0c096976u: goto P_0c096976;
case 0x0c096978u: goto P_0c096978;
case 0x0c09697au: goto P_0c09697a;
case 0x0c09697cu: goto P_0c09697c;
case 0x0c09697eu: goto P_0c09697e;
case 0x0c096980u: goto P_0c096980;
case 0x0c096982u: goto P_0c096982;
case 0x0c096984u: goto P_0c096984;
case 0x0c096986u: goto P_0c096986;
case 0x0c096988u: goto P_0c096988;
case 0x0c09698au: goto P_0c09698a;
case 0x0c09698cu: goto P_0c09698c;
case 0x0c09698eu: goto P_0c09698e;
case 0x0c096990u: goto P_0c096990;
case 0x0c096992u: goto P_0c096992;
case 0x0c096994u: goto P_0c096994;
case 0x0c096996u: goto P_0c096996;
case 0x0c096998u: goto P_0c096998;
case 0x0c09699au: goto P_0c09699a;
case 0x0c09699cu: goto P_0c09699c;
case 0x0c09699eu: goto P_0c09699e;
case 0x0c0969a0u: goto P_0c0969a0;
case 0x0c0969a2u: goto P_0c0969a2;
case 0x0c0969a4u: goto P_0c0969a4;
case 0x0c0969a6u: goto P_0c0969a6;
case 0x0c0969a8u: goto P_0c0969a8;
case 0x0c0969aau: goto P_0c0969aa;
case 0x0c0969acu: goto P_0c0969ac;
case 0x0c0969aeu: goto P_0c0969ae;
case 0x0c0969b0u: goto P_0c0969b0;
case 0x0c0969b2u: goto P_0c0969b2;
case 0x0c0969b4u: goto P_0c0969b4;
case 0x0c0969b6u: goto P_0c0969b6;
case 0x0c0969b8u: goto P_0c0969b8;
case 0x0c0969bau: goto P_0c0969ba;
case 0x0c0969bcu: goto P_0c0969bc;
case 0x0c0969beu: goto P_0c0969be;
case 0x0c0969c0u: goto P_0c0969c0;
case 0x0c0969c2u: goto P_0c0969c2;
case 0x0c0969c4u: goto P_0c0969c4;
case 0x0c0969c6u: goto P_0c0969c6;
case 0x0c0969c8u: goto P_0c0969c8;
case 0x0c0969cau: goto P_0c0969ca;
case 0x0c0969ccu: goto P_0c0969cc;
case 0x0c0969ceu: goto P_0c0969ce;
case 0x0c0969d0u: goto P_0c0969d0;
case 0x0c0969d2u: goto P_0c0969d2;
case 0x0c0969d4u: goto P_0c0969d4;
case 0x0c0969d6u: goto P_0c0969d6;
case 0x0c0969d8u: goto P_0c0969d8;
case 0x0c0969dau: goto P_0c0969da;
case 0x0c0969dcu: goto P_0c0969dc;
case 0x0c0969deu: goto P_0c0969de;
case 0x0c0969e0u: goto P_0c0969e0;
case 0x0c0969e2u: goto P_0c0969e2;
case 0x0c0969e4u: goto P_0c0969e4;
case 0x0c0969e6u: goto P_0c0969e6;
case 0x0c0969e8u: goto P_0c0969e8;
case 0x0c0969eau: goto P_0c0969ea;
case 0x0c0969ecu: goto P_0c0969ec;
case 0x0c0969eeu: goto P_0c0969ee;
case 0x0c0969f0u: goto P_0c0969f0;
case 0x0c0969f2u: goto P_0c0969f2;
case 0x0c0969f4u: goto P_0c0969f4;
case 0x0c0969f6u: goto P_0c0969f6;
case 0x0c0969f8u: goto P_0c0969f8;
case 0x0c0969fau: goto P_0c0969fa;
case 0x0c0969fcu: goto P_0c0969fc;
case 0x0c0969feu: goto P_0c0969fe;
case 0x0c096a00u: goto P_0c096a00;
case 0x0c096a02u: goto P_0c096a02;
case 0x0c096a04u: goto P_0c096a04;
case 0x0c096a06u: goto P_0c096a06;
case 0x0c096a08u: goto P_0c096a08;
case 0x0c096a0au: goto P_0c096a0a;
case 0x0c096a0cu: goto P_0c096a0c;
case 0x0c096a0eu: goto P_0c096a0e;
case 0x0c096a10u: goto P_0c096a10;
case 0x0c096a12u: goto P_0c096a12;
case 0x0c096a14u: goto P_0c096a14;
case 0x0c096a16u: goto P_0c096a16;
case 0x0c096a18u: goto P_0c096a18;
case 0x0c096a1au: goto P_0c096a1a;
case 0x0c096a1cu: goto P_0c096a1c;
case 0x0c096a1eu: goto P_0c096a1e;
case 0x0c096a20u: goto P_0c096a20;
case 0x0c096a22u: goto P_0c096a22;
case 0x0c097ff4u: goto P_0c097ff4;
case 0x0c097ff6u: goto P_0c097ff6;
case 0x0c097ff8u: goto P_0c097ff8;
case 0x0c097ffau: goto P_0c097ffa;
case 0x0c097ffcu: goto P_0c097ffc;
case 0x0c097ffeu: goto P_0c097ffe;
case 0x0c098000u: goto P_0c098000;
case 0x0c098002u: goto P_0c098002;
case 0x0c098004u: goto P_0c098004;
case 0x0c098006u: goto P_0c098006;
case 0x0c098008u: goto P_0c098008;
case 0x0c09800au: goto P_0c09800a;
case 0x0c09800cu: goto P_0c09800c;
case 0x0c09800eu: goto P_0c09800e;
case 0x0c098010u: goto P_0c098010;
case 0x0c098012u: goto P_0c098012;
case 0x0c098014u: goto P_0c098014;
case 0x0c098016u: goto P_0c098016;
case 0x0c098018u: goto P_0c098018;
case 0x0c09801au: goto P_0c09801a;
case 0x0c09801cu: goto P_0c09801c;
case 0x0c09801eu: goto P_0c09801e;
case 0x0c098020u: goto P_0c098020;
case 0x0c098022u: goto P_0c098022;
case 0x0c098024u: goto P_0c098024;
case 0x0c098026u: goto P_0c098026;
case 0x0c098028u: goto P_0c098028;
case 0x0c09802au: goto P_0c09802a;
case 0x0c09802cu: goto P_0c09802c;
case 0x0c09802eu: goto P_0c09802e;
case 0x0c098030u: goto P_0c098030;
case 0x0c098032u: goto P_0c098032;
case 0x0c098034u: goto P_0c098034;
case 0x0c098036u: goto P_0c098036;
case 0x0c098038u: goto P_0c098038;
case 0x0c09803au: goto P_0c09803a;
case 0x0c09803cu: goto P_0c09803c;
case 0x0c09803eu: goto P_0c09803e;
case 0x0c098040u: goto P_0c098040;
case 0x0c098042u: goto P_0c098042;
case 0x0c098044u: goto P_0c098044;
case 0x0c098046u: goto P_0c098046;
case 0x0c098048u: goto P_0c098048;
case 0x0c09804au: goto P_0c09804a;
case 0x0c09804cu: goto P_0c09804c;
case 0x0c09804eu: goto P_0c09804e;
case 0x0c098050u: goto P_0c098050;
case 0x0c098052u: goto P_0c098052;
case 0x0c098054u: goto P_0c098054;
case 0x0c098056u: goto P_0c098056;
case 0x0c098058u: goto P_0c098058;
case 0x0c09805au: goto P_0c09805a;
case 0x0c09805cu: goto P_0c09805c;
case 0x0c09805eu: goto P_0c09805e;
case 0x0c098060u: goto P_0c098060;
case 0x0c098062u: goto P_0c098062;
case 0x0c098064u: goto P_0c098064;
case 0x0c098066u: goto P_0c098066;
case 0x0c098068u: goto P_0c098068;
case 0x0c09806au: goto P_0c09806a;
case 0x0c09806cu: goto P_0c09806c;
case 0x0c09806eu: goto P_0c09806e;
case 0x0c098070u: goto P_0c098070;
case 0x0c098072u: goto P_0c098072;
case 0x0c098074u: goto P_0c098074;
case 0x0c098076u: goto P_0c098076;
case 0x0c098078u: goto P_0c098078;
case 0x0c09807au: goto P_0c09807a;
case 0x0c09807cu: goto P_0c09807c;
case 0x0c09807eu: goto P_0c09807e;
case 0x0c098080u: goto P_0c098080;
case 0x0c098082u: goto P_0c098082;
case 0x0c098084u: goto P_0c098084;
case 0x0c098086u: goto P_0c098086;
case 0x0c098088u: goto P_0c098088;
case 0x0c09845cu: goto P_0c09845c;
case 0x0c09845eu: goto P_0c09845e;
case 0x0c098460u: goto P_0c098460;
case 0x0c098462u: goto P_0c098462;
case 0x0c098464u: goto P_0c098464;
case 0x0c098466u: goto P_0c098466;
case 0x0c098468u: goto P_0c098468;
case 0x0c09846au: goto P_0c09846a;
case 0x0c09846cu: goto P_0c09846c;
case 0x0c09846eu: goto P_0c09846e;
case 0x0c098470u: goto P_0c098470;
case 0x0c098472u: goto P_0c098472;
case 0x0c098474u: goto P_0c098474;
case 0x0c098476u: goto P_0c098476;
case 0x0c098478u: goto P_0c098478;
case 0x0c09847au: goto P_0c09847a;
case 0x0c09847cu: goto P_0c09847c;
case 0x0c09847eu: goto P_0c09847e;
case 0x0c098480u: goto P_0c098480;
case 0x0c098482u: goto P_0c098482;
case 0x0c098484u: goto P_0c098484;
case 0x0c098486u: goto P_0c098486;
case 0x0c098488u: goto P_0c098488;
case 0x0c09848au: goto P_0c09848a;
case 0x0c09848cu: goto P_0c09848c;
case 0x0c09848eu: goto P_0c09848e;
case 0x0c098490u: goto P_0c098490;
case 0x0c098492u: goto P_0c098492;
case 0x0c098494u: goto P_0c098494;
case 0x0c098496u: goto P_0c098496;
case 0x0c098498u: goto P_0c098498;
case 0x0c09849au: goto P_0c09849a;
case 0x0c09849cu: goto P_0c09849c;
case 0x0c09849eu: goto P_0c09849e;
case 0x0c0984a0u: goto P_0c0984a0;
case 0x0c0984a2u: goto P_0c0984a2;
case 0x0c0984a4u: goto P_0c0984a4;
case 0x0c0984a6u: goto P_0c0984a6;
case 0x0c0984a8u: goto P_0c0984a8;
case 0x0c0984aau: goto P_0c0984aa;
case 0x0c0984acu: goto P_0c0984ac;
case 0x0c0984aeu: goto P_0c0984ae;
case 0x0c0984b0u: goto P_0c0984b0;
case 0x0c0984b2u: goto P_0c0984b2;
case 0x0c0984b4u: goto P_0c0984b4;
case 0x0c0984b6u: goto P_0c0984b6;
case 0x0c0984b8u: goto P_0c0984b8;
case 0x0c0984bau: goto P_0c0984ba;
case 0x0c0984bcu: goto P_0c0984bc;
case 0x0c0984beu: goto P_0c0984be;
case 0x0c0984c0u: goto P_0c0984c0;
case 0x0c0984c2u: goto P_0c0984c2;
case 0x0c0984c4u: goto P_0c0984c4;
case 0x0c0984c6u: goto P_0c0984c6;
case 0x0c0984c8u: goto P_0c0984c8;
case 0x0c0984cau: goto P_0c0984ca;
case 0x0c0984ccu: goto P_0c0984cc;
case 0x0c0984ceu: goto P_0c0984ce;
case 0x0c0984d0u: goto P_0c0984d0;
case 0x0c0984d2u: goto P_0c0984d2;
case 0x0c0984d4u: goto P_0c0984d4;
case 0x0c0984d6u: goto P_0c0984d6;
case 0x0c0984d8u: goto P_0c0984d8;
case 0x0c0984dau: goto P_0c0984da;
case 0x0c0984dcu: goto P_0c0984dc;
case 0x0c0984deu: goto P_0c0984de;
case 0x0c0984e0u: goto P_0c0984e0;
case 0x0c0984e2u: goto P_0c0984e2;
case 0x0c0984e4u: goto P_0c0984e4;
case 0x0c0984e6u: goto P_0c0984e6;
case 0x0c0984e8u: goto P_0c0984e8;
case 0x0c0984eau: goto P_0c0984ea;
case 0x0c0984ecu: goto P_0c0984ec;
case 0x0c0984eeu: goto P_0c0984ee;
case 0x0c0984f0u: goto P_0c0984f0;
case 0x0c0984f2u: goto P_0c0984f2;
case 0x0c0984f4u: goto P_0c0984f4;
case 0x0c0984f6u: goto P_0c0984f6;
case 0x0c0984f8u: goto P_0c0984f8;
case 0x0c0984fau: goto P_0c0984fa;
case 0x0c0984fcu: goto P_0c0984fc;
case 0x0c0984feu: goto P_0c0984fe;
case 0x0c098500u: goto P_0c098500;
case 0x0c098502u: goto P_0c098502;
case 0x0c098504u: goto P_0c098504;
case 0x0c098506u: goto P_0c098506;
case 0x0c098508u: goto P_0c098508;
case 0x0c09850au: goto P_0c09850a;
case 0x0c09850cu: goto P_0c09850c;
case 0x0c09850eu: goto P_0c09850e;
case 0x0c098510u: goto P_0c098510;
case 0x0c098512u: goto P_0c098512;
case 0x0c098514u: goto P_0c098514;
case 0x0c098516u: goto P_0c098516;
case 0x0c098518u: goto P_0c098518;
case 0x0c09851au: goto P_0c09851a;
case 0x0c09851cu: goto P_0c09851c;
case 0x0c09851eu: goto P_0c09851e;
case 0x0c098520u: goto P_0c098520;
case 0x0c098522u: goto P_0c098522;
case 0x0c098524u: goto P_0c098524;
case 0x0c098526u: goto P_0c098526;
case 0x0c098528u: goto P_0c098528;
case 0x0c09852au: goto P_0c09852a;
case 0x0c09852cu: goto P_0c09852c;
case 0x0c09852eu: goto P_0c09852e;
case 0x0c098530u: goto P_0c098530;
case 0x0c098532u: goto P_0c098532;
case 0x0c098534u: goto P_0c098534;
case 0x0c098536u: goto P_0c098536;
case 0x0c098538u: goto P_0c098538;
case 0x0c09853au: goto P_0c09853a;
case 0x0c09853cu: goto P_0c09853c;
case 0x0c09853eu: goto P_0c09853e;
case 0x0c098540u: goto P_0c098540;
case 0x0c098542u: goto P_0c098542;
case 0x0c098544u: goto P_0c098544;
case 0x0c098546u: goto P_0c098546;
case 0x0c098548u: goto P_0c098548;
case 0x0c09854au: goto P_0c09854a;
case 0x0c09877cu: goto P_0c09877c;
case 0x0c09877eu: goto P_0c09877e;
case 0x0c098780u: goto P_0c098780;
case 0x0c098782u: goto P_0c098782;
case 0x0c098784u: goto P_0c098784;
case 0x0c098786u: goto P_0c098786;
case 0x0c098788u: goto P_0c098788;
case 0x0c09878au: goto P_0c09878a;
case 0x0c09878cu: goto P_0c09878c;
case 0x0c09878eu: goto P_0c09878e;
case 0x0c098790u: goto P_0c098790;
case 0x0c098792u: goto P_0c098792;
case 0x0c098794u: goto P_0c098794;
case 0x0c098796u: goto P_0c098796;
case 0x0c098798u: goto P_0c098798;
case 0x0c09879au: goto P_0c09879a;
case 0x0c09879cu: goto P_0c09879c;
case 0x0c09879eu: goto P_0c09879e;
case 0x0c0987a0u: goto P_0c0987a0;
case 0x0c0987a2u: goto P_0c0987a2;
case 0x0c0987a4u: goto P_0c0987a4;
case 0x0c0987a6u: goto P_0c0987a6;
case 0x0c0987a8u: goto P_0c0987a8;
case 0x0c0987aau: goto P_0c0987aa;
case 0x0c0987acu: goto P_0c0987ac;
case 0x0c0987aeu: goto P_0c0987ae;
case 0x0c0987b0u: goto P_0c0987b0;
case 0x0c0987b2u: goto P_0c0987b2;
case 0x0c0987b4u: goto P_0c0987b4;
case 0x0c0987b6u: goto P_0c0987b6;
case 0x0c0987b8u: goto P_0c0987b8;
case 0x0c0987bau: goto P_0c0987ba;
case 0x0c0987bcu: goto P_0c0987bc;
case 0x0c0987beu: goto P_0c0987be;
case 0x0c0987c0u: goto P_0c0987c0;
case 0x0c0987c2u: goto P_0c0987c2;
case 0x0c0987c4u: goto P_0c0987c4;
case 0x0c0987c6u: goto P_0c0987c6;
case 0x0c0987c8u: goto P_0c0987c8;
case 0x0c0987cau: goto P_0c0987ca;
case 0x0c0987ccu: goto P_0c0987cc;
case 0x0c0987ceu: goto P_0c0987ce;
case 0x0c0987d0u: goto P_0c0987d0;
case 0x0c0987d2u: goto P_0c0987d2;
case 0x0c0987d4u: goto P_0c0987d4;
case 0x0c0987d6u: goto P_0c0987d6;
case 0x0c0987d8u: goto P_0c0987d8;
case 0x0c0987dau: goto P_0c0987da;
case 0x0c0987dcu: goto P_0c0987dc;
case 0x0c0987deu: goto P_0c0987de;
case 0x0c0987e0u: goto P_0c0987e0;
case 0x0c0987e2u: goto P_0c0987e2;
case 0x0c0987e4u: goto P_0c0987e4;
case 0x0c0987e6u: goto P_0c0987e6;
case 0x0c0987e8u: goto P_0c0987e8;
case 0x0c0987eau: goto P_0c0987ea;
case 0x0c0987ecu: goto P_0c0987ec;
case 0x0c0987eeu: goto P_0c0987ee;
case 0x0c0987f0u: goto P_0c0987f0;
case 0x0c0987f2u: goto P_0c0987f2;
case 0x0c0987f4u: goto P_0c0987f4;
case 0x0c0987f6u: goto P_0c0987f6;
case 0x0c0987f8u: goto P_0c0987f8;
case 0x0c0987fau: goto P_0c0987fa;
case 0x0c0987fcu: goto P_0c0987fc;
case 0x0c0987feu: goto P_0c0987fe;
case 0x0c098800u: goto P_0c098800;
case 0x0c098802u: goto P_0c098802;
case 0x0c098804u: goto P_0c098804;
case 0x0c098806u: goto P_0c098806;
case 0x0c098808u: goto P_0c098808;
case 0x0c09880au: goto P_0c09880a;
case 0x0c09880cu: goto P_0c09880c;
case 0x0c09880eu: goto P_0c09880e;
case 0x0c098810u: goto P_0c098810;
case 0x0c098812u: goto P_0c098812;
case 0x0c098814u: goto P_0c098814;
case 0x0c098816u: goto P_0c098816;
case 0x0c098818u: goto P_0c098818;
case 0x0c09881au: goto P_0c09881a;
case 0x0c09881cu: goto P_0c09881c;
case 0x0c09881eu: goto P_0c09881e;
case 0x0c098820u: goto P_0c098820;
case 0x0c098822u: goto P_0c098822;
case 0x0c098824u: goto P_0c098824;
case 0x0c098826u: goto P_0c098826;
case 0x0c098828u: goto P_0c098828;
case 0x0c09882au: goto P_0c09882a;
case 0x0c09882cu: goto P_0c09882c;
case 0x0c09882eu: goto P_0c09882e;
case 0x0c098830u: goto P_0c098830;
case 0x0c098832u: goto P_0c098832;
case 0x0c098834u: goto P_0c098834;
case 0x0c098836u: goto P_0c098836;
case 0x0c098838u: goto P_0c098838;
case 0x0c09883au: goto P_0c09883a;
case 0x0c09883cu: goto P_0c09883c;
case 0x0c09883eu: goto P_0c09883e;
case 0x0c098840u: goto P_0c098840;
case 0x0c098842u: goto P_0c098842;
case 0x0c098844u: goto P_0c098844;
case 0x0c098846u: goto P_0c098846;
case 0x0c098848u: goto P_0c098848;
case 0x0c09884au: goto P_0c09884a;
case 0x0c0988b0u: goto P_0c0988b0;
case 0x0c0988b2u: goto P_0c0988b2;
case 0x0c0988b4u: goto P_0c0988b4;
case 0x0c0988b6u: goto P_0c0988b6;
case 0x0c0988b8u: goto P_0c0988b8;
case 0x0c0988bau: goto P_0c0988ba;
case 0x0c0988bcu: goto P_0c0988bc;
case 0x0c0988beu: goto P_0c0988be;
case 0x0c0988c0u: goto P_0c0988c0;
case 0x0c0988c2u: goto P_0c0988c2;
case 0x0c0988c4u: goto P_0c0988c4;
case 0x0c0988c6u: goto P_0c0988c6;
case 0x0c0988c8u: goto P_0c0988c8;
case 0x0c0988cau: goto P_0c0988ca;
case 0x0c0988ccu: goto P_0c0988cc;
case 0x0c0988ceu: goto P_0c0988ce;
case 0x0c0988d0u: goto P_0c0988d0;
case 0x0c0988d2u: goto P_0c0988d2;
case 0x0c0988d4u: goto P_0c0988d4;
case 0x0c0988d6u: goto P_0c0988d6;
case 0x0c0988d8u: goto P_0c0988d8;
case 0x0c0988dau: goto P_0c0988da;
case 0x0c0988dcu: goto P_0c0988dc;
case 0x0c0988deu: goto P_0c0988de;
case 0x0c0988e0u: goto P_0c0988e0;
case 0x0c0988e2u: goto P_0c0988e2;
case 0x0c0988e4u: goto P_0c0988e4;
case 0x0c0988e6u: goto P_0c0988e6;
case 0x0c0988e8u: goto P_0c0988e8;
case 0x0c0988eau: goto P_0c0988ea;
case 0x0c0988ecu: goto P_0c0988ec;
case 0x0c0988eeu: goto P_0c0988ee;
case 0x0c0988f0u: goto P_0c0988f0;
case 0x0c0988f2u: goto P_0c0988f2;
case 0x0c0988f4u: goto P_0c0988f4;
case 0x0c0988f6u: goto P_0c0988f6;
case 0x0c0988f8u: goto P_0c0988f8;
case 0x0c0988fau: goto P_0c0988fa;
case 0x0c0988fcu: goto P_0c0988fc;
case 0x0c0988feu: goto P_0c0988fe;
case 0x0c098900u: goto P_0c098900;
case 0x0c098902u: goto P_0c098902;
case 0x0c098904u: goto P_0c098904;
case 0x0c098906u: goto P_0c098906;
case 0x0c098908u: goto P_0c098908;
case 0x0c09890au: goto P_0c09890a;
case 0x0c09890cu: goto P_0c09890c;
case 0x0c09890eu: goto P_0c09890e;
case 0x0c098910u: goto P_0c098910;
case 0x0c098912u: goto P_0c098912;
case 0x0c098914u: goto P_0c098914;
case 0x0c098916u: goto P_0c098916;
case 0x0c098918u: goto P_0c098918;
case 0x0c09891au: goto P_0c09891a;
case 0x0c09891cu: goto P_0c09891c;
case 0x0c09891eu: goto P_0c09891e;
case 0x0c098920u: goto P_0c098920;
case 0x0c098922u: goto P_0c098922;
case 0x0c098924u: goto P_0c098924;
case 0x0c098926u: goto P_0c098926;
case 0x0c098928u: goto P_0c098928;
case 0x0c09892au: goto P_0c09892a;
case 0x0c09892cu: goto P_0c09892c;
case 0x0c09892eu: goto P_0c09892e;
case 0x0c098930u: goto P_0c098930;
case 0x0c098932u: goto P_0c098932;
case 0x0c098934u: goto P_0c098934;
case 0x0c098936u: goto P_0c098936;
case 0x0c098938u: goto P_0c098938;
case 0x0c09893au: goto P_0c09893a;
case 0x0c09893cu: goto P_0c09893c;
case 0x0c09893eu: goto P_0c09893e;
case 0x0c098940u: goto P_0c098940;
case 0x0c098942u: goto P_0c098942;
case 0x0c098944u: goto P_0c098944;
case 0x0c098946u: goto P_0c098946;
case 0x0c098948u: goto P_0c098948;
case 0x0c09894au: goto P_0c09894a;
case 0x0c09894cu: goto P_0c09894c;
case 0x0c09894eu: goto P_0c09894e;
case 0x0c098950u: goto P_0c098950;
case 0x0c098952u: goto P_0c098952;
case 0x0c098954u: goto P_0c098954;
case 0x0c098956u: goto P_0c098956;
case 0x0c098958u: goto P_0c098958;
case 0x0c09895au: goto P_0c09895a;
case 0x0c09895cu: goto P_0c09895c;
case 0x0c09895eu: goto P_0c09895e;
case 0x0c098960u: goto P_0c098960;
case 0x0c098962u: goto P_0c098962;
case 0x0c098964u: goto P_0c098964;
case 0x0c098966u: goto P_0c098966;
case 0x0c098968u: goto P_0c098968;
case 0x0c09896au: goto P_0c09896a;
case 0x0c09896cu: goto P_0c09896c;
case 0x0c09896eu: goto P_0c09896e;
case 0x0c098970u: goto P_0c098970;
case 0x0c098972u: goto P_0c098972;
case 0x0c098974u: goto P_0c098974;
case 0x0c098976u: goto P_0c098976;
case 0x0c098978u: goto P_0c098978;
case 0x0c09897au: goto P_0c09897a;
case 0x0c09897cu: goto P_0c09897c;
case 0x0c09897eu: goto P_0c09897e;
case 0x0c098980u: goto P_0c098980;
case 0x0c098982u: goto P_0c098982;
case 0x0c098c62u: goto P_0c098c62;
case 0x0c098c64u: goto P_0c098c64;
case 0x0c098c66u: goto P_0c098c66;
case 0x0c098c68u: goto P_0c098c68;
case 0x0c098c6au: goto P_0c098c6a;
case 0x0c098c6cu: goto P_0c098c6c;
case 0x0c098c6eu: goto P_0c098c6e;
case 0x0c098c70u: goto P_0c098c70;
case 0x0c098c72u: goto P_0c098c72;
case 0x0c098c74u: goto P_0c098c74;
case 0x0c098c76u: goto P_0c098c76;
case 0x0c098c78u: goto P_0c098c78;
case 0x0c098c7au: goto P_0c098c7a;
case 0x0c098c7cu: goto P_0c098c7c;
case 0x0c098c7eu: goto P_0c098c7e;
case 0x0c098c80u: goto P_0c098c80;
case 0x0c098c82u: goto P_0c098c82;
case 0x0c098c84u: goto P_0c098c84;
case 0x0c098c86u: goto P_0c098c86;
case 0x0c098c88u: goto P_0c098c88;
case 0x0c098c8au: goto P_0c098c8a;
case 0x0c098c8cu: goto P_0c098c8c;
case 0x0c098c8eu: goto P_0c098c8e;
case 0x0c098c90u: goto P_0c098c90;
case 0x0c098c92u: goto P_0c098c92;
case 0x0c098c94u: goto P_0c098c94;
case 0x0c098c96u: goto P_0c098c96;
case 0x0c098c98u: goto P_0c098c98;
case 0x0c098c9au: goto P_0c098c9a;
case 0x0c098c9cu: goto P_0c098c9c;
case 0x0c098c9eu: goto P_0c098c9e;
case 0x0c098ca0u: goto P_0c098ca0;
case 0x0c098ca2u: goto P_0c098ca2;
case 0x0c098ca4u: goto P_0c098ca4;
case 0x0c098ca6u: goto P_0c098ca6;
case 0x0c098ca8u: goto P_0c098ca8;
case 0x0c098caau: goto P_0c098caa;
case 0x0c098cacu: goto P_0c098cac;
case 0x0c098caeu: goto P_0c098cae;
case 0x0c098cb0u: goto P_0c098cb0;
case 0x0c098cb2u: goto P_0c098cb2;
case 0x0c098cb4u: goto P_0c098cb4;
case 0x0c098cb6u: goto P_0c098cb6;
case 0x0c098cb8u: goto P_0c098cb8;
case 0x0c098cbau: goto P_0c098cba;
case 0x0c098cbcu: goto P_0c098cbc;
case 0x0c098cbeu: goto P_0c098cbe;
case 0x0c098cc0u: goto P_0c098cc0;
case 0x0c098cc2u: goto P_0c098cc2;
case 0x0c098cc4u: goto P_0c098cc4;
case 0x0c098cc6u: goto P_0c098cc6;
case 0x0c098cc8u: goto P_0c098cc8;
case 0x0c098ccau: goto P_0c098cca;
case 0x0c098cccu: goto P_0c098ccc;
case 0x0c098cceu: goto P_0c098cce;
case 0x0c098cd0u: goto P_0c098cd0;
case 0x0c098cd2u: goto P_0c098cd2;
case 0x0c098cd4u: goto P_0c098cd4;
case 0x0c098cd6u: goto P_0c098cd6;
case 0x0c098cd8u: goto P_0c098cd8;
case 0x0c098cdau: goto P_0c098cda;
case 0x0c098cdcu: goto P_0c098cdc;
case 0x0c098cdeu: goto P_0c098cde;
case 0x0c098ce0u: goto P_0c098ce0;
case 0x0c098ce2u: goto P_0c098ce2;
case 0x0c098ce4u: goto P_0c098ce4;
case 0x0c098ce6u: goto P_0c098ce6;
case 0x0c098ce8u: goto P_0c098ce8;
case 0x0c098ceau: goto P_0c098cea;
case 0x0c098cecu: goto P_0c098cec;
case 0x0c098ceeu: goto P_0c098cee;
case 0x0c098cf0u: goto P_0c098cf0;
case 0x0c098cf2u: goto P_0c098cf2;
case 0x0c098cf4u: goto P_0c098cf4;
case 0x0c098cf6u: goto P_0c098cf6;
case 0x0c098cf8u: goto P_0c098cf8;
case 0x0c098cfau: goto P_0c098cfa;
case 0x0c098cfcu: goto P_0c098cfc;
case 0x0c098cfeu: goto P_0c098cfe;
case 0x0c098d00u: goto P_0c098d00;
case 0x0c098d02u: goto P_0c098d02;
case 0x0c098d04u: goto P_0c098d04;
case 0x0c098d06u: goto P_0c098d06;
case 0x0c098d08u: goto P_0c098d08;
case 0x0c098d0au: goto P_0c098d0a;
case 0x0c098d0cu: goto P_0c098d0c;
case 0x0c098d0eu: goto P_0c098d0e;
case 0x0c098d10u: goto P_0c098d10;
case 0x0c098d12u: goto P_0c098d12;
case 0x0c098d14u: goto P_0c098d14;
case 0x0c098d16u: goto P_0c098d16;
case 0x0c098d18u: goto P_0c098d18;
case 0x0c098d1au: goto P_0c098d1a;
case 0x0c098d1cu: goto P_0c098d1c;
case 0x0c098d1eu: goto P_0c098d1e;
case 0x0c098d20u: goto P_0c098d20;
case 0x0c098d5cu: goto P_0c098d5c;
case 0x0c098d5eu: goto P_0c098d5e;
case 0x0c098d60u: goto P_0c098d60;
case 0x0c098d62u: goto P_0c098d62;
case 0x0c098d64u: goto P_0c098d64;
case 0x0c098d66u: goto P_0c098d66;
case 0x0c098d68u: goto P_0c098d68;
case 0x0c098d6au: goto P_0c098d6a;
case 0x0c098d6cu: goto P_0c098d6c;
case 0x0c098d6eu: goto P_0c098d6e;
case 0x0c098d70u: goto P_0c098d70;
case 0x0c098d72u: goto P_0c098d72;
case 0x0c098d74u: goto P_0c098d74;
case 0x0c098d76u: goto P_0c098d76;
case 0x0c098d78u: goto P_0c098d78;
case 0x0c098d7au: goto P_0c098d7a;
case 0x0c098d7cu: goto P_0c098d7c;
case 0x0c098d7eu: goto P_0c098d7e;
case 0x0c098d80u: goto P_0c098d80;
case 0x0c098d82u: goto P_0c098d82;
case 0x0c098d84u: goto P_0c098d84;
case 0x0c098d86u: goto P_0c098d86;
case 0x0c098d88u: goto P_0c098d88;
case 0x0c098d8au: goto P_0c098d8a;
case 0x0c098d8cu: goto P_0c098d8c;
case 0x0c098d8eu: goto P_0c098d8e;
case 0x0c098d90u: goto P_0c098d90;
case 0x0c098d92u: goto P_0c098d92;
case 0x0c098d94u: goto P_0c098d94;
case 0x0c098d96u: goto P_0c098d96;
case 0x0c098d98u: goto P_0c098d98;
case 0x0c098d9au: goto P_0c098d9a;
case 0x0c098d9cu: goto P_0c098d9c;
case 0x0c098d9eu: goto P_0c098d9e;
case 0x0c098da0u: goto P_0c098da0;
case 0x0c098da2u: goto P_0c098da2;
case 0x0c098da4u: goto P_0c098da4;
case 0x0c098da6u: goto P_0c098da6;
case 0x0c098da8u: goto P_0c098da8;
case 0x0c098daau: goto P_0c098daa;
case 0x0c098dacu: goto P_0c098dac;
case 0x0c098daeu: goto P_0c098dae;
case 0x0c098db0u: goto P_0c098db0;
case 0x0c098db2u: goto P_0c098db2;
case 0x0c098db4u: goto P_0c098db4;
case 0x0c098db6u: goto P_0c098db6;
case 0x0c098db8u: goto P_0c098db8;
case 0x0c098dbau: goto P_0c098dba;
case 0x0c098dbcu: goto P_0c098dbc;
case 0x0c098dbeu: goto P_0c098dbe;
case 0x0c098dc0u: goto P_0c098dc0;
case 0x0c098dc2u: goto P_0c098dc2;
case 0x0c098dc4u: goto P_0c098dc4;
case 0x0c098dc6u: goto P_0c098dc6;
case 0x0c098dc8u: goto P_0c098dc8;
case 0x0c098dcau: goto P_0c098dca;
case 0x0c098dccu: goto P_0c098dcc;
case 0x0c098dceu: goto P_0c098dce;
case 0x0c098dd0u: goto P_0c098dd0;
case 0x0c098dd2u: goto P_0c098dd2;
case 0x0c098dd4u: goto P_0c098dd4;
case 0x0c098dd6u: goto P_0c098dd6;
case 0x0c098dd8u: goto P_0c098dd8;
case 0x0c098ddau: goto P_0c098dda;
case 0x0c098ddcu: goto P_0c098ddc;
case 0x0c098ddeu: goto P_0c098dde;
case 0x0c098de0u: goto P_0c098de0;
case 0x0c098de2u: goto P_0c098de2;
case 0x0c098de4u: goto P_0c098de4;
case 0x0c098de6u: goto P_0c098de6;
case 0x0c098de8u: goto P_0c098de8;
case 0x0c098deau: goto P_0c098dea;
case 0x0c098decu: goto P_0c098dec;
case 0x0c098deeu: goto P_0c098dee;
case 0x0c098df0u: goto P_0c098df0;
case 0x0c098df2u: goto P_0c098df2;
case 0x0c098e00u: goto P_0c098e00;
case 0x0c098e02u: goto P_0c098e02;
case 0x0c098e04u: goto P_0c098e04;
case 0x0c098e06u: goto P_0c098e06;
case 0x0c098e08u: goto P_0c098e08;
case 0x0c098e0au: goto P_0c098e0a;
case 0x0c098e0cu: goto P_0c098e0c;
case 0x0c098e0eu: goto P_0c098e0e;
case 0x0c098e10u: goto P_0c098e10;
case 0x0c098e12u: goto P_0c098e12;
case 0x0c098e14u: goto P_0c098e14;
case 0x0c098e16u: goto P_0c098e16;
case 0x0c098e18u: goto P_0c098e18;
case 0x0c098e1au: goto P_0c098e1a;
case 0x0c098e1cu: goto P_0c098e1c;
case 0x0c098e1eu: goto P_0c098e1e;
case 0x0c098e20u: goto P_0c098e20;
case 0x0c098e22u: goto P_0c098e22;
case 0x0c098e24u: goto P_0c098e24;
case 0x0c098e26u: goto P_0c098e26;
case 0x0c098e28u: goto P_0c098e28;
case 0x0c098e2au: goto P_0c098e2a;
case 0x0c098e2cu: goto P_0c098e2c;
case 0x0c098e2eu: goto P_0c098e2e;
case 0x0c098e30u: goto P_0c098e30;
case 0x0c098e32u: goto P_0c098e32;
case 0x0c098e34u: goto P_0c098e34;
case 0x0c098e36u: goto P_0c098e36;
case 0x0c098e38u: goto P_0c098e38;
case 0x0c098e3au: goto P_0c098e3a;
case 0x0c098e3cu: goto P_0c098e3c;
case 0x0c098e3eu: goto P_0c098e3e;
case 0x0c098e40u: goto P_0c098e40;
case 0x0c098e42u: goto P_0c098e42;
case 0x0c098e44u: goto P_0c098e44;
case 0x0c098e46u: goto P_0c098e46;
case 0x0c098e48u: goto P_0c098e48;
case 0x0c098e4au: goto P_0c098e4a;
case 0x0c098e4cu: goto P_0c098e4c;
case 0x0c098e4eu: goto P_0c098e4e;
case 0x0c098e50u: goto P_0c098e50;
case 0x0c098e52u: goto P_0c098e52;
case 0x0c098e54u: goto P_0c098e54;
case 0x0c098e56u: goto P_0c098e56;
case 0x0c098e58u: goto P_0c098e58;
case 0x0c098e5au: goto P_0c098e5a;
case 0x0c098e5cu: goto P_0c098e5c;
case 0x0c098e5eu: goto P_0c098e5e;
case 0x0c098e60u: goto P_0c098e60;
case 0x0c098e62u: goto P_0c098e62;
case 0x0c098e64u: goto P_0c098e64;
case 0x0c098e66u: goto P_0c098e66;
case 0x0c098e68u: goto P_0c098e68;
case 0x0c098e6au: goto P_0c098e6a;
case 0x0c098e6cu: goto P_0c098e6c;
case 0x0c098e6eu: goto P_0c098e6e;
case 0x0c098e70u: goto P_0c098e70;
case 0x0c098e72u: goto P_0c098e72;
case 0x0c098e74u: goto P_0c098e74;
case 0x0c098e76u: goto P_0c098e76;
case 0x0c098e78u: goto P_0c098e78;
case 0x0c098e7au: goto P_0c098e7a;
case 0x0c098e7cu: goto P_0c098e7c;
case 0x0c098e7eu: goto P_0c098e7e;
case 0x0c098e80u: goto P_0c098e80;
case 0x0c098e82u: goto P_0c098e82;
case 0x0c098e84u: goto P_0c098e84;
case 0x0c098e86u: goto P_0c098e86;
case 0x0c098e88u: goto P_0c098e88;
case 0x0c098e8au: goto P_0c098e8a;
case 0x0c098e8cu: goto P_0c098e8c;
case 0x0c098e8eu: goto P_0c098e8e;
case 0x0c098e90u: goto P_0c098e90;
case 0x0c098e92u: goto P_0c098e92;
case 0x0c098e94u: goto P_0c098e94;
case 0x0c098e96u: goto P_0c098e96;
case 0x0c098e98u: goto P_0c098e98;
case 0x0c098e9au: goto P_0c098e9a;
case 0x0c098e9cu: goto P_0c098e9c;
case 0x0c098e9eu: goto P_0c098e9e;
case 0x0c098ea0u: goto P_0c098ea0;
case 0x0c098ea2u: goto P_0c098ea2;
case 0x0c098ea4u: goto P_0c098ea4;
case 0x0c098ea6u: goto P_0c098ea6;
case 0x0c098ea8u: goto P_0c098ea8;
case 0x0c098eaau: goto P_0c098eaa;
case 0x0c098eacu: goto P_0c098eac;
case 0x0c098eaeu: goto P_0c098eae;
case 0x0c098eb0u: goto P_0c098eb0;
case 0x0c098eb2u: goto P_0c098eb2;
case 0x0c098eb4u: goto P_0c098eb4;
case 0x0c098eb6u: goto P_0c098eb6;
case 0x0c098eb8u: goto P_0c098eb8;
case 0x0c098ebau: goto P_0c098eba;
case 0x0c098ebcu: goto P_0c098ebc;
case 0x0c098ebeu: goto P_0c098ebe;
case 0x0c098ec0u: goto P_0c098ec0;
case 0x0c098ec2u: goto P_0c098ec2;
case 0x0c098ec4u: goto P_0c098ec4;
case 0x0c098ec6u: goto P_0c098ec6;
case 0x0c098ec8u: goto P_0c098ec8;
case 0x0c098ecau: goto P_0c098eca;
case 0x0c098eccu: goto P_0c098ecc;
case 0x0c098eceu: goto P_0c098ece;
case 0x0c098ed0u: goto P_0c098ed0;
case 0x0c098ed2u: goto P_0c098ed2;
case 0x0c098ed4u: goto P_0c098ed4;
case 0x0c098ed6u: goto P_0c098ed6;
case 0x0c098ed8u: goto P_0c098ed8;
case 0x0c098edau: goto P_0c098eda;
case 0x0c098edcu: goto P_0c098edc;
case 0x0c098edeu: goto P_0c098ede;
case 0x0c098ee0u: goto P_0c098ee0;
case 0x0c098ee2u: goto P_0c098ee2;
case 0x0c098ee4u: goto P_0c098ee4;
case 0x0c098ee6u: goto P_0c098ee6;
case 0x0c098ee8u: goto P_0c098ee8;
case 0x0c098eeau: goto P_0c098eea;
case 0x0c098eecu: goto P_0c098eec;
case 0x0c098eeeu: goto P_0c098eee;
case 0x0c098ef0u: goto P_0c098ef0;
case 0x0c098ef2u: goto P_0c098ef2;
case 0x0c098ef4u: goto P_0c098ef4;
case 0x0c098ef6u: goto P_0c098ef6;
case 0x0c098ef8u: goto P_0c098ef8;
case 0x0c098efau: goto P_0c098efa;
case 0x0c098efcu: goto P_0c098efc;
case 0x0c098efeu: goto P_0c098efe;
case 0x0c098f00u: goto P_0c098f00;
case 0x0c098f02u: goto P_0c098f02;
case 0x0c098f04u: goto P_0c098f04;
case 0x0c098f06u: goto P_0c098f06;
case 0x0c098f08u: goto P_0c098f08;
case 0x0c098f0au: goto P_0c098f0a;
case 0x0c098f0cu: goto P_0c098f0c;
case 0x0c098f0eu: goto P_0c098f0e;
case 0x0c098f10u: goto P_0c098f10;
case 0x0c098f12u: goto P_0c098f12;
case 0x0c098f14u: goto P_0c098f14;
case 0x0c098f16u: goto P_0c098f16;
case 0x0c098f18u: goto P_0c098f18;
case 0x0c098f1au: goto P_0c098f1a;
case 0x0c098f1cu: goto P_0c098f1c;
case 0x0c098f1eu: goto P_0c098f1e;
case 0x0c098f3cu: goto P_0c098f3c;
case 0x0c098f3eu: goto P_0c098f3e;
case 0x0c098f40u: goto P_0c098f40;
case 0x0c098f42u: goto P_0c098f42;
case 0x0c098f44u: goto P_0c098f44;
case 0x0c098f46u: goto P_0c098f46;
case 0x0c098f48u: goto P_0c098f48;
case 0x0c098f4au: goto P_0c098f4a;
case 0x0c098f4cu: goto P_0c098f4c;
case 0x0c098f4eu: goto P_0c098f4e;
case 0x0c098f50u: goto P_0c098f50;
case 0x0c098f52u: goto P_0c098f52;
case 0x0c098f54u: goto P_0c098f54;
case 0x0c098f56u: goto P_0c098f56;
case 0x0c098f58u: goto P_0c098f58;
case 0x0c098f5au: goto P_0c098f5a;
case 0x0c098f5cu: goto P_0c098f5c;
case 0x0c098f5eu: goto P_0c098f5e;
case 0x0c098f60u: goto P_0c098f60;
case 0x0c098f62u: goto P_0c098f62;
case 0x0c098f64u: goto P_0c098f64;
case 0x0c098f66u: goto P_0c098f66;
case 0x0c098f68u: goto P_0c098f68;
case 0x0c098f6au: goto P_0c098f6a;
case 0x0c098f6cu: goto P_0c098f6c;
case 0x0c098f6eu: goto P_0c098f6e;
case 0x0c098f70u: goto P_0c098f70;
case 0x0c098f72u: goto P_0c098f72;
case 0x0c098f74u: goto P_0c098f74;
case 0x0c098f76u: goto P_0c098f76;
case 0x0c098f78u: goto P_0c098f78;
case 0x0c098f7au: goto P_0c098f7a;
case 0x0c098f7cu: goto P_0c098f7c;
case 0x0c098f7eu: goto P_0c098f7e;
case 0x0c098f80u: goto P_0c098f80;
case 0x0c098f82u: goto P_0c098f82;
case 0x0c098f84u: goto P_0c098f84;
case 0x0c098f86u: goto P_0c098f86;
case 0x0c098f88u: goto P_0c098f88;
case 0x0c098f8au: goto P_0c098f8a;
case 0x0c098f8cu: goto P_0c098f8c;
case 0x0c098f8eu: goto P_0c098f8e;
case 0x0c098f90u: goto P_0c098f90;
case 0x0c098f92u: goto P_0c098f92;
case 0x0c098f94u: goto P_0c098f94;
case 0x0c098f96u: goto P_0c098f96;
case 0x0c098f98u: goto P_0c098f98;
case 0x0c098f9au: goto P_0c098f9a;
case 0x0c098f9cu: goto P_0c098f9c;
case 0x0c098f9eu: goto P_0c098f9e;
case 0x0c098fa0u: goto P_0c098fa0;
case 0x0c098fa2u: goto P_0c098fa2;
case 0x0c098fa4u: goto P_0c098fa4;
case 0x0c098fa6u: goto P_0c098fa6;
case 0x0c098fa8u: goto P_0c098fa8;
case 0x0c098faau: goto P_0c098faa;
case 0x0c098facu: goto P_0c098fac;
case 0x0c098faeu: goto P_0c098fae;
case 0x0c098fb0u: goto P_0c098fb0;
case 0x0c098fb2u: goto P_0c098fb2;
case 0x0c098fb4u: goto P_0c098fb4;
case 0x0c098fb6u: goto P_0c098fb6;
case 0x0c098fb8u: goto P_0c098fb8;
case 0x0c098fbau: goto P_0c098fba;
case 0x0c098fbcu: goto P_0c098fbc;
case 0x0c098fbeu: goto P_0c098fbe;
case 0x0c098fc0u: goto P_0c098fc0;
case 0x0c098fc2u: goto P_0c098fc2;
case 0x0c098fc4u: goto P_0c098fc4;
case 0x0c098fc6u: goto P_0c098fc6;
case 0x0c098fc8u: goto P_0c098fc8;
case 0x0c098fcau: goto P_0c098fca;
case 0x0c098fccu: goto P_0c098fcc;
case 0x0c098fceu: goto P_0c098fce;
case 0x0c098fd0u: goto P_0c098fd0;
case 0x0c098fd2u: goto P_0c098fd2;
case 0x0c098fd4u: goto P_0c098fd4;
case 0x0c098fd6u: goto P_0c098fd6;
case 0x0c098fd8u: goto P_0c098fd8;
case 0x0c098fdau: goto P_0c098fda;
case 0x0c098fdcu: goto P_0c098fdc;
case 0x0c098fdeu: goto P_0c098fde;
case 0x0c098fe0u: goto P_0c098fe0;
case 0x0c098fe2u: goto P_0c098fe2;
case 0x0c098fe4u: goto P_0c098fe4;
case 0x0c098fe6u: goto P_0c098fe6;
case 0x0c098fe8u: goto P_0c098fe8;
case 0x0c098feau: goto P_0c098fea;
case 0x0c098fecu: goto P_0c098fec;
case 0x0c098feeu: goto P_0c098fee;
case 0x0c098ff0u: goto P_0c098ff0;
case 0x0c098ff2u: goto P_0c098ff2;
case 0x0c098ff4u: goto P_0c098ff4;
case 0x0c098ff6u: goto P_0c098ff6;
case 0x0c098ff8u: goto P_0c098ff8;
case 0x0c098ffau: goto P_0c098ffa;
case 0x0c098ffcu: goto P_0c098ffc;
case 0x0c098ffeu: goto P_0c098ffe;
case 0x0c099000u: goto P_0c099000;
case 0x0c099002u: goto P_0c099002;
case 0x0c099004u: goto P_0c099004;
case 0x0c099006u: goto P_0c099006;
case 0x0c099008u: goto P_0c099008;
case 0x0c09900au: goto P_0c09900a;
case 0x0c09900cu: goto P_0c09900c;
case 0x0c09900eu: goto P_0c09900e;
case 0x0c099010u: goto P_0c099010;
case 0x0c099012u: goto P_0c099012;
case 0x0c099014u: goto P_0c099014;
case 0x0c099016u: goto P_0c099016;
case 0x0c099018u: goto P_0c099018;
case 0x0c09901au: goto P_0c09901a;
case 0x0c09901cu: goto P_0c09901c;
case 0x0c09901eu: goto P_0c09901e;
case 0x0c099020u: goto P_0c099020;
case 0x0c099022u: goto P_0c099022;
case 0x0c099024u: goto P_0c099024;
case 0x0c099026u: goto P_0c099026;
case 0x0c099028u: goto P_0c099028;
case 0x0c09902au: goto P_0c09902a;
case 0x0c09902cu: goto P_0c09902c;
case 0x0c09902eu: goto P_0c09902e;
case 0x0c099030u: goto P_0c099030;
case 0x0c099032u: goto P_0c099032;
case 0x0c099060u: goto P_0c099060;
case 0x0c099062u: goto P_0c099062;
case 0x0c099064u: goto P_0c099064;
case 0x0c099066u: goto P_0c099066;
case 0x0c099068u: goto P_0c099068;
case 0x0c09906au: goto P_0c09906a;
case 0x0c09906cu: goto P_0c09906c;
case 0x0c09906eu: goto P_0c09906e;
case 0x0c099070u: goto P_0c099070;
case 0x0c099072u: goto P_0c099072;
case 0x0c099074u: goto P_0c099074;
case 0x0c099076u: goto P_0c099076;
case 0x0c099078u: goto P_0c099078;
case 0x0c09907au: goto P_0c09907a;
case 0x0c09907cu: goto P_0c09907c;
case 0x0c09907eu: goto P_0c09907e;
case 0x0c099080u: goto P_0c099080;
case 0x0c099082u: goto P_0c099082;
case 0x0c099084u: goto P_0c099084;
case 0x0c099086u: goto P_0c099086;
case 0x0c099088u: goto P_0c099088;
case 0x0c09908au: goto P_0c09908a;
case 0x0c09908cu: goto P_0c09908c;
case 0x0c09908eu: goto P_0c09908e;
case 0x0c099090u: goto P_0c099090;
case 0x0c099092u: goto P_0c099092;
case 0x0c099094u: goto P_0c099094;
case 0x0c099096u: goto P_0c099096;
case 0x0c099098u: goto P_0c099098;
case 0x0c09909au: goto P_0c09909a;
case 0x0c09909cu: goto P_0c09909c;
case 0x0c09909eu: goto P_0c09909e;
case 0x0c0990a0u: goto P_0c0990a0;
case 0x0c0990a2u: goto P_0c0990a2;
case 0x0c0990a4u: goto P_0c0990a4;
case 0x0c0990a6u: goto P_0c0990a6;
case 0x0c0990a8u: goto P_0c0990a8;
case 0x0c0990aau: goto P_0c0990aa;
case 0x0c0990acu: goto P_0c0990ac;
case 0x0c0990aeu: goto P_0c0990ae;
case 0x0c0990b0u: goto P_0c0990b0;
case 0x0c0990b2u: goto P_0c0990b2;
case 0x0c0990b4u: goto P_0c0990b4;
case 0x0c0990b6u: goto P_0c0990b6;
case 0x0c0990b8u: goto P_0c0990b8;
case 0x0c0990bau: goto P_0c0990ba;
case 0x0c0990bcu: goto P_0c0990bc;
case 0x0c0990beu: goto P_0c0990be;
case 0x0c0990c0u: goto P_0c0990c0;
case 0x0c0990c2u: goto P_0c0990c2;
case 0x0c0990c4u: goto P_0c0990c4;
case 0x0c0990c6u: goto P_0c0990c6;
case 0x0c0990c8u: goto P_0c0990c8;
case 0x0c0990cau: goto P_0c0990ca;
case 0x0c0990ccu: goto P_0c0990cc;
case 0x0c0990ceu: goto P_0c0990ce;
case 0x0c0990d0u: goto P_0c0990d0;
case 0x0c0990d2u: goto P_0c0990d2;
case 0x0c0990d4u: goto P_0c0990d4;
case 0x0c0990d6u: goto P_0c0990d6;
case 0x0c0990d8u: goto P_0c0990d8;
case 0x0c0990dau: goto P_0c0990da;
case 0x0c0990dcu: goto P_0c0990dc;
case 0x0c0990deu: goto P_0c0990de;
case 0x0c0990e0u: goto P_0c0990e0;
case 0x0c0990e2u: goto P_0c0990e2;
case 0x0c0990e4u: goto P_0c0990e4;
case 0x0c0990e6u: goto P_0c0990e6;
case 0x0c0990e8u: goto P_0c0990e8;
case 0x0c0990eau: goto P_0c0990ea;
case 0x0c0990ecu: goto P_0c0990ec;
case 0x0c0990eeu: goto P_0c0990ee;
case 0x0c0990f0u: goto P_0c0990f0;
case 0x0c0990f2u: goto P_0c0990f2;
case 0x0c0990f4u: goto P_0c0990f4;
case 0x0c0990f6u: goto P_0c0990f6;
case 0x0c0990f8u: goto P_0c0990f8;
case 0x0c0990fau: goto P_0c0990fa;
case 0x0c0990fcu: goto P_0c0990fc;
case 0x0c0990feu: goto P_0c0990fe;
case 0x0c099100u: goto P_0c099100;
case 0x0c099102u: goto P_0c099102;
case 0x0c099104u: goto P_0c099104;
case 0x0c099106u: goto P_0c099106;
case 0x0c099108u: goto P_0c099108;
case 0x0c09910au: goto P_0c09910a;
case 0x0c09910cu: goto P_0c09910c;
case 0x0c09910eu: goto P_0c09910e;
case 0x0c099110u: goto P_0c099110;
case 0x0c099112u: goto P_0c099112;
case 0x0c099114u: goto P_0c099114;
case 0x0c099116u: goto P_0c099116;
case 0x0c099118u: goto P_0c099118;
case 0x0c09911au: goto P_0c09911a;
case 0x0c09911cu: goto P_0c09911c;
case 0x0c09911eu: goto P_0c09911e;
case 0x0c099120u: goto P_0c099120;
case 0x0c099122u: goto P_0c099122;
case 0x0c099124u: goto P_0c099124;
case 0x0c099126u: goto P_0c099126;
case 0x0c099128u: goto P_0c099128;
case 0x0c09912au: goto P_0c09912a;
case 0x0c09912cu: goto P_0c09912c;
case 0x0c09912eu: goto P_0c09912e;
case 0x0c099130u: goto P_0c099130;
case 0x0c099132u: goto P_0c099132;
case 0x0c099134u: goto P_0c099134;
case 0x0c099136u: goto P_0c099136;
case 0x0c099138u: goto P_0c099138;
case 0x0c09913au: goto P_0c09913a;
case 0x0c09913cu: goto P_0c09913c;
case 0x0c09913eu: goto P_0c09913e;
case 0x0c099140u: goto P_0c099140;
case 0x0c099142u: goto P_0c099142;
case 0x0c099144u: goto P_0c099144;
case 0x0c099146u: goto P_0c099146;
case 0x0c099148u: goto P_0c099148;
case 0x0c09914au: goto P_0c09914a;
case 0x0c09914cu: goto P_0c09914c;
case 0x0c09914eu: goto P_0c09914e;
case 0x0c099150u: goto P_0c099150;
case 0x0c099152u: goto P_0c099152;
case 0x0c099154u: goto P_0c099154;
case 0x0c099156u: goto P_0c099156;
case 0x0c099194u: goto P_0c099194;
case 0x0c099196u: goto P_0c099196;
case 0x0c099198u: goto P_0c099198;
case 0x0c09919au: goto P_0c09919a;
case 0x0c09919cu: goto P_0c09919c;
case 0x0c09919eu: goto P_0c09919e;
case 0x0c0991a0u: goto P_0c0991a0;
case 0x0c0991a2u: goto P_0c0991a2;
case 0x0c0991a4u: goto P_0c0991a4;
case 0x0c0991a6u: goto P_0c0991a6;
case 0x0c0991a8u: goto P_0c0991a8;
case 0x0c0991aau: goto P_0c0991aa;
case 0x0c0991acu: goto P_0c0991ac;
case 0x0c0991aeu: goto P_0c0991ae;
case 0x0c0991b0u: goto P_0c0991b0;
case 0x0c0991b2u: goto P_0c0991b2;
case 0x0c0991b4u: goto P_0c0991b4;
case 0x0c0991b6u: goto P_0c0991b6;
case 0x0c0991b8u: goto P_0c0991b8;
case 0x0c0991bau: goto P_0c0991ba;
case 0x0c0991bcu: goto P_0c0991bc;
case 0x0c0991beu: goto P_0c0991be;
case 0x0c0991c0u: goto P_0c0991c0;
case 0x0c0991c2u: goto P_0c0991c2;
case 0x0c0991c4u: goto P_0c0991c4;
case 0x0c0991c6u: goto P_0c0991c6;
case 0x0c0991c8u: goto P_0c0991c8;
case 0x0c0991cau: goto P_0c0991ca;
case 0x0c0991ccu: goto P_0c0991cc;
case 0x0c0991ceu: goto P_0c0991ce;
case 0x0c0991d0u: goto P_0c0991d0;
case 0x0c0991d2u: goto P_0c0991d2;
case 0x0c0991d4u: goto P_0c0991d4;
case 0x0c0991d6u: goto P_0c0991d6;
case 0x0c0991d8u: goto P_0c0991d8;
case 0x0c0991dau: goto P_0c0991da;
case 0x0c0991dcu: goto P_0c0991dc;
case 0x0c0991deu: goto P_0c0991de;
case 0x0c0991e0u: goto P_0c0991e0;
case 0x0c0991e2u: goto P_0c0991e2;
case 0x0c0991e4u: goto P_0c0991e4;
case 0x0c0991e6u: goto P_0c0991e6;
case 0x0c0991e8u: goto P_0c0991e8;
case 0x0c0991eau: goto P_0c0991ea;
case 0x0c0991ecu: goto P_0c0991ec;
case 0x0c0991eeu: goto P_0c0991ee;
case 0x0c0991f0u: goto P_0c0991f0;
case 0x0c0991f2u: goto P_0c0991f2;
case 0x0c0991f4u: goto P_0c0991f4;
case 0x0c0991f6u: goto P_0c0991f6;
case 0x0c0991f8u: goto P_0c0991f8;
case 0x0c0991fau: goto P_0c0991fa;
case 0x0c0991fcu: goto P_0c0991fc;
case 0x0c0991feu: goto P_0c0991fe;
case 0x0c099200u: goto P_0c099200;
case 0x0c099202u: goto P_0c099202;
case 0x0c099204u: goto P_0c099204;
case 0x0c099206u: goto P_0c099206;
case 0x0c099208u: goto P_0c099208;
case 0x0c09920au: goto P_0c09920a;
case 0x0c09920cu: goto P_0c09920c;
case 0x0c09920eu: goto P_0c09920e;
case 0x0c099210u: goto P_0c099210;
case 0x0c099212u: goto P_0c099212;
case 0x0c099214u: goto P_0c099214;
case 0x0c099216u: goto P_0c099216;
case 0x0c099218u: goto P_0c099218;
case 0x0c09921au: goto P_0c09921a;
case 0x0c09921cu: goto P_0c09921c;
case 0x0c09921eu: goto P_0c09921e;
case 0x0c099220u: goto P_0c099220;
case 0x0c099222u: goto P_0c099222;
case 0x0c099224u: goto P_0c099224;
case 0x0c099226u: goto P_0c099226;
case 0x0c099228u: goto P_0c099228;
case 0x0c09922au: goto P_0c09922a;
case 0x0c09922cu: goto P_0c09922c;
case 0x0c09922eu: goto P_0c09922e;
case 0x0c099230u: goto P_0c099230;
case 0x0c099232u: goto P_0c099232;
case 0x0c099234u: goto P_0c099234;
case 0x0c099236u: goto P_0c099236;
case 0x0c099238u: goto P_0c099238;
case 0x0c09923au: goto P_0c09923a;
case 0x0c09923cu: goto P_0c09923c;
case 0x0c09923eu: goto P_0c09923e;
case 0x0c099240u: goto P_0c099240;
case 0x0c099242u: goto P_0c099242;
case 0x0c099244u: goto P_0c099244;
case 0x0c099278u: goto P_0c099278;
case 0x0c09927au: goto P_0c09927a;
case 0x0c09927cu: goto P_0c09927c;
case 0x0c09927eu: goto P_0c09927e;
case 0x0c099280u: goto P_0c099280;
case 0x0c099282u: goto P_0c099282;
case 0x0c099284u: goto P_0c099284;
case 0x0c099286u: goto P_0c099286;
case 0x0c099288u: goto P_0c099288;
case 0x0c09928au: goto P_0c09928a;
case 0x0c09928cu: goto P_0c09928c;
case 0x0c09928eu: goto P_0c09928e;
case 0x0c099290u: goto P_0c099290;
case 0x0c099292u: goto P_0c099292;
case 0x0c099294u: goto P_0c099294;
case 0x0c099296u: goto P_0c099296;
case 0x0c099298u: goto P_0c099298;
case 0x0c09929au: goto P_0c09929a;
case 0x0c09929cu: goto P_0c09929c;
case 0x0c09929eu: goto P_0c09929e;
case 0x0c0992a0u: goto P_0c0992a0;
case 0x0c0992a2u: goto P_0c0992a2;
case 0x0c0992a4u: goto P_0c0992a4;
case 0x0c0992a6u: goto P_0c0992a6;
case 0x0c0992a8u: goto P_0c0992a8;
case 0x0c0992aau: goto P_0c0992aa;
case 0x0c0992acu: goto P_0c0992ac;
case 0x0c0992aeu: goto P_0c0992ae;
case 0x0c0992b0u: goto P_0c0992b0;
case 0x0c0992b2u: goto P_0c0992b2;
case 0x0c0992b4u: goto P_0c0992b4;
case 0x0c0992b6u: goto P_0c0992b6;
case 0x0c0992b8u: goto P_0c0992b8;
case 0x0c0992bau: goto P_0c0992ba;
case 0x0c0992bcu: goto P_0c0992bc;
case 0x0c0992beu: goto P_0c0992be;
case 0x0c0992c0u: goto P_0c0992c0;
case 0x0c0992c2u: goto P_0c0992c2;
case 0x0c0992c4u: goto P_0c0992c4;
case 0x0c0992c6u: goto P_0c0992c6;
case 0x0c0992c8u: goto P_0c0992c8;
case 0x0c0992cau: goto P_0c0992ca;
case 0x0c0992ccu: goto P_0c0992cc;
case 0x0c0992ceu: goto P_0c0992ce;
case 0x0c0992d0u: goto P_0c0992d0;
case 0x0c0992d2u: goto P_0c0992d2;
case 0x0c0992d4u: goto P_0c0992d4;
case 0x0c0992d6u: goto P_0c0992d6;
case 0x0c0992d8u: goto P_0c0992d8;
case 0x0c0992dau: goto P_0c0992da;
case 0x0c0992dcu: goto P_0c0992dc;
case 0x0c0992deu: goto P_0c0992de;
case 0x0c0992e0u: goto P_0c0992e0;
case 0x0c0992e2u: goto P_0c0992e2;
case 0x0c0992e4u: goto P_0c0992e4;
case 0x0c0992e6u: goto P_0c0992e6;
case 0x0c0992e8u: goto P_0c0992e8;
case 0x0c0992eau: goto P_0c0992ea;
case 0x0c0992ecu: goto P_0c0992ec;
case 0x0c0992eeu: goto P_0c0992ee;
case 0x0c0992f0u: goto P_0c0992f0;
case 0x0c0992f2u: goto P_0c0992f2;
case 0x0c0992f4u: goto P_0c0992f4;
case 0x0c0992f6u: goto P_0c0992f6;
case 0x0c0992f8u: goto P_0c0992f8;
case 0x0c0992fau: goto P_0c0992fa;
case 0x0c0992fcu: goto P_0c0992fc;
case 0x0c0992feu: goto P_0c0992fe;
case 0x0c099300u: goto P_0c099300;
case 0x0c099302u: goto P_0c099302;
case 0x0c099304u: goto P_0c099304;
case 0x0c099306u: goto P_0c099306;
case 0x0c099308u: goto P_0c099308;
case 0x0c09930au: goto P_0c09930a;
case 0x0c09930cu: goto P_0c09930c;
case 0x0c09930eu: goto P_0c09930e;
case 0x0c099310u: goto P_0c099310;
case 0x0c099312u: goto P_0c099312;
case 0x0c099314u: goto P_0c099314;
case 0x0c099316u: goto P_0c099316;
case 0x0c099318u: goto P_0c099318;
case 0x0c09931au: goto P_0c09931a;
case 0x0c09931cu: goto P_0c09931c;
case 0x0c09931eu: goto P_0c09931e;
case 0x0c099320u: goto P_0c099320;
case 0x0c099322u: goto P_0c099322;
case 0x0c099324u: goto P_0c099324;
case 0x0c099326u: goto P_0c099326;
case 0x0c099328u: goto P_0c099328;
case 0x0c09932au: goto P_0c09932a;
case 0x0c09932cu: goto P_0c09932c;
case 0x0c09932eu: goto P_0c09932e;
case 0x0c099330u: goto P_0c099330;
case 0x0c099332u: goto P_0c099332;
case 0x0c099334u: goto P_0c099334;
case 0x0c099336u: goto P_0c099336;
case 0x0c099338u: goto P_0c099338;
case 0x0c09933au: goto P_0c09933a;
case 0x0c09933cu: goto P_0c09933c;
case 0x0c09933eu: goto P_0c09933e;
case 0x0c099340u: goto P_0c099340;
case 0x0c099342u: goto P_0c099342;
case 0x0c099344u: goto P_0c099344;
case 0x0c099346u: goto P_0c099346;
case 0x0c099348u: goto P_0c099348;
case 0x0c09934au: goto P_0c09934a;
case 0x0c09934cu: goto P_0c09934c;
case 0x0c09934eu: goto P_0c09934e;
case 0x0c099350u: goto P_0c099350;
case 0x0c099352u: goto P_0c099352;
case 0x0c099354u: goto P_0c099354;
case 0x0c099356u: goto P_0c099356;
case 0x0c099358u: goto P_0c099358;
case 0x0c09935au: goto P_0c09935a;
case 0x0c09935cu: goto P_0c09935c;
case 0x0c09935eu: goto P_0c09935e;
case 0x0c099360u: goto P_0c099360;
case 0x0c099362u: goto P_0c099362;
case 0x0c099364u: goto P_0c099364;
case 0x0c099366u: goto P_0c099366;
case 0x0c099368u: goto P_0c099368;
case 0x0c09936au: goto P_0c09936a;
case 0x0c09936cu: goto P_0c09936c;
case 0x0c09936eu: goto P_0c09936e;
case 0x0c099370u: goto P_0c099370;
case 0x0c099372u: goto P_0c099372;
case 0x0c099374u: goto P_0c099374;
case 0x0c099376u: goto P_0c099376;
case 0x0c099378u: goto P_0c099378;
case 0x0c09937au: goto P_0c09937a;
case 0x0c09937cu: goto P_0c09937c;
case 0x0c09937eu: goto P_0c09937e;
case 0x0c099380u: goto P_0c099380;
case 0x0c099382u: goto P_0c099382;
case 0x0c099384u: goto P_0c099384;
case 0x0c099386u: goto P_0c099386;
case 0x0c099388u: goto P_0c099388;
case 0x0c09938au: goto P_0c09938a;
case 0x0c09938cu: goto P_0c09938c;
case 0x0c09938eu: goto P_0c09938e;
case 0x0c099390u: goto P_0c099390;
case 0x0c099392u: goto P_0c099392;
case 0x0c099394u: goto P_0c099394;
case 0x0c099396u: goto P_0c099396;
case 0x0c099398u: goto P_0c099398;
case 0x0c09939au: goto P_0c09939a;
case 0x0c09939cu: goto P_0c09939c;
case 0x0c09939eu: goto P_0c09939e;
case 0x0c0993a0u: goto P_0c0993a0;
case 0x0c0993a2u: goto P_0c0993a2;
case 0x0c0993a4u: goto P_0c0993a4;
case 0x0c0993a6u: goto P_0c0993a6;
case 0x0c0993a8u: goto P_0c0993a8;
case 0x0c0993aau: goto P_0c0993aa;
case 0x0c0993acu: goto P_0c0993ac;
case 0x0c0993aeu: goto P_0c0993ae;
case 0x0c0993b0u: goto P_0c0993b0;
case 0x0c0993b2u: goto P_0c0993b2;
case 0x0c0993e0u: goto P_0c0993e0;
case 0x0c0993e2u: goto P_0c0993e2;
case 0x0c0993e4u: goto P_0c0993e4;
case 0x0c0993e6u: goto P_0c0993e6;
case 0x0c0993e8u: goto P_0c0993e8;
case 0x0c0993eau: goto P_0c0993ea;
case 0x0c0993ecu: goto P_0c0993ec;
case 0x0c0993eeu: goto P_0c0993ee;
case 0x0c0993f0u: goto P_0c0993f0;
case 0x0c0993f2u: goto P_0c0993f2;
case 0x0c0993f4u: goto P_0c0993f4;
case 0x0c0993f6u: goto P_0c0993f6;
case 0x0c0993f8u: goto P_0c0993f8;
case 0x0c0993fau: goto P_0c0993fa;
case 0x0c0993fcu: goto P_0c0993fc;
case 0x0c0993feu: goto P_0c0993fe;
case 0x0c099400u: goto P_0c099400;
case 0x0c099402u: goto P_0c099402;
case 0x0c099404u: goto P_0c099404;
case 0x0c099406u: goto P_0c099406;
case 0x0c099408u: goto P_0c099408;
case 0x0c09940au: goto P_0c09940a;
case 0x0c09940cu: goto P_0c09940c;
case 0x0c09940eu: goto P_0c09940e;
case 0x0c099410u: goto P_0c099410;
case 0x0c099412u: goto P_0c099412;
case 0x0c099414u: goto P_0c099414;
case 0x0c099416u: goto P_0c099416;
case 0x0c099418u: goto P_0c099418;
case 0x0c09941au: goto P_0c09941a;
case 0x0c09941cu: goto P_0c09941c;
case 0x0c09941eu: goto P_0c09941e;
case 0x0c099420u: goto P_0c099420;
case 0x0c099422u: goto P_0c099422;
case 0x0c099424u: goto P_0c099424;
case 0x0c099426u: goto P_0c099426;
case 0x0c099428u: goto P_0c099428;
case 0x0c09942au: goto P_0c09942a;
case 0x0c09942cu: goto P_0c09942c;
case 0x0c09942eu: goto P_0c09942e;
case 0x0c099430u: goto P_0c099430;
case 0x0c099432u: goto P_0c099432;
case 0x0c099434u: goto P_0c099434;
case 0x0c099436u: goto P_0c099436;
case 0x0c099438u: goto P_0c099438;
case 0x0c09943au: goto P_0c09943a;
case 0x0c09943cu: goto P_0c09943c;
case 0x0c09943eu: goto P_0c09943e;
case 0x0c099440u: goto P_0c099440;
case 0x0c099442u: goto P_0c099442;
case 0x0c099444u: goto P_0c099444;
case 0x0c099446u: goto P_0c099446;
case 0x0c099448u: goto P_0c099448;
case 0x0c09944au: goto P_0c09944a;
case 0x0c09944cu: goto P_0c09944c;
case 0x0c09944eu: goto P_0c09944e;
case 0x0c099450u: goto P_0c099450;
case 0x0c099452u: goto P_0c099452;
case 0x0c099454u: goto P_0c099454;
case 0x0c099456u: goto P_0c099456;
case 0x0c099458u: goto P_0c099458;
case 0x0c09945au: goto P_0c09945a;
case 0x0c09945cu: goto P_0c09945c;
case 0x0c09945eu: goto P_0c09945e;
case 0x0c099460u: goto P_0c099460;
case 0x0c099462u: goto P_0c099462;
case 0x0c099464u: goto P_0c099464;
case 0x0c099466u: goto P_0c099466;
case 0x0c099468u: goto P_0c099468;
case 0x0c09946au: goto P_0c09946a;
case 0x0c09946cu: goto P_0c09946c;
case 0x0c09946eu: goto P_0c09946e;
case 0x0c099470u: goto P_0c099470;
case 0x0c099472u: goto P_0c099472;
case 0x0c099474u: goto P_0c099474;
case 0x0c099476u: goto P_0c099476;
case 0x0c099478u: goto P_0c099478;
case 0x0c09947au: goto P_0c09947a;
case 0x0c09947cu: goto P_0c09947c;
case 0x0c09947eu: goto P_0c09947e;
case 0x0c099480u: goto P_0c099480;
case 0x0c099482u: goto P_0c099482;
case 0x0c099484u: goto P_0c099484;
case 0x0c099486u: goto P_0c099486;
case 0x0c099488u: goto P_0c099488;
case 0x0c09948au: goto P_0c09948a;
case 0x0c09948cu: goto P_0c09948c;
case 0x0c09948eu: goto P_0c09948e;
case 0x0c099490u: goto P_0c099490;
case 0x0c099492u: goto P_0c099492;
case 0x0c099494u: goto P_0c099494;
case 0x0c099496u: goto P_0c099496;
case 0x0c099498u: goto P_0c099498;
case 0x0c09949au: goto P_0c09949a;
case 0x0c09949cu: goto P_0c09949c;
case 0x0c09949eu: goto P_0c09949e;
case 0x0c0994a0u: goto P_0c0994a0;
case 0x0c0994a2u: goto P_0c0994a2;
case 0x0c0994a4u: goto P_0c0994a4;
case 0x0c0994a6u: goto P_0c0994a6;
case 0x0c0994a8u: goto P_0c0994a8;
case 0x0c0994aau: goto P_0c0994aa;
case 0x0c0994d4u: goto P_0c0994d4;
case 0x0c0994d6u: goto P_0c0994d6;
case 0x0c0994d8u: goto P_0c0994d8;
case 0x0c0994dau: goto P_0c0994da;
case 0x0c0994dcu: goto P_0c0994dc;
case 0x0c0994deu: goto P_0c0994de;
case 0x0c0994e0u: goto P_0c0994e0;
case 0x0c0994e2u: goto P_0c0994e2;
case 0x0c0994e4u: goto P_0c0994e4;
case 0x0c0994e6u: goto P_0c0994e6;
case 0x0c0994e8u: goto P_0c0994e8;
case 0x0c0994eau: goto P_0c0994ea;
case 0x0c0994ecu: goto P_0c0994ec;
case 0x0c0994eeu: goto P_0c0994ee;
case 0x0c0994f0u: goto P_0c0994f0;
case 0x0c0994f2u: goto P_0c0994f2;
case 0x0c0994f4u: goto P_0c0994f4;
case 0x0c0994f6u: goto P_0c0994f6;
case 0x0c0994f8u: goto P_0c0994f8;
case 0x0c0994fau: goto P_0c0994fa;
case 0x0c0994fcu: goto P_0c0994fc;
case 0x0c0994feu: goto P_0c0994fe;
case 0x0c099500u: goto P_0c099500;
case 0x0c099502u: goto P_0c099502;
case 0x0c099504u: goto P_0c099504;
case 0x0c099506u: goto P_0c099506;
case 0x0c099508u: goto P_0c099508;
case 0x0c09950au: goto P_0c09950a;
case 0x0c09950cu: goto P_0c09950c;
case 0x0c09950eu: goto P_0c09950e;
case 0x0c099510u: goto P_0c099510;
case 0x0c099512u: goto P_0c099512;
case 0x0c099514u: goto P_0c099514;
case 0x0c099516u: goto P_0c099516;
case 0x0c099518u: goto P_0c099518;
case 0x0c09951au: goto P_0c09951a;
case 0x0c09951cu: goto P_0c09951c;
case 0x0c09951eu: goto P_0c09951e;
case 0x0c099520u: goto P_0c099520;
case 0x0c099522u: goto P_0c099522;
case 0x0c099524u: goto P_0c099524;
case 0x0c099526u: goto P_0c099526;
case 0x0c099528u: goto P_0c099528;
case 0x0c09952au: goto P_0c09952a;
case 0x0c09952cu: goto P_0c09952c;
case 0x0c09952eu: goto P_0c09952e;
case 0x0c099530u: goto P_0c099530;
case 0x0c099532u: goto P_0c099532;
case 0x0c099534u: goto P_0c099534;
case 0x0c099536u: goto P_0c099536;
case 0x0c099538u: goto P_0c099538;
case 0x0c09953au: goto P_0c09953a;
case 0x0c09953cu: goto P_0c09953c;
case 0x0c09953eu: goto P_0c09953e;
case 0x0c099540u: goto P_0c099540;
case 0x0c099542u: goto P_0c099542;
case 0x0c099544u: goto P_0c099544;
case 0x0c099546u: goto P_0c099546;
case 0x0c099548u: goto P_0c099548;
case 0x0c09954au: goto P_0c09954a;
case 0x0c09954cu: goto P_0c09954c;
case 0x0c09954eu: goto P_0c09954e;
case 0x0c099550u: goto P_0c099550;
case 0x0c099552u: goto P_0c099552;
case 0x0c099554u: goto P_0c099554;
case 0x0c099556u: goto P_0c099556;
case 0x0c099558u: goto P_0c099558;
case 0x0c09955au: goto P_0c09955a;
case 0x0c09955cu: goto P_0c09955c;
case 0x0c09955eu: goto P_0c09955e;
case 0x0c099560u: goto P_0c099560;
case 0x0c099562u: goto P_0c099562;
case 0x0c099564u: goto P_0c099564;
case 0x0c099566u: goto P_0c099566;
case 0x0c099568u: goto P_0c099568;
case 0x0c09956au: goto P_0c09956a;
case 0x0c09956cu: goto P_0c09956c;
case 0x0c09956eu: goto P_0c09956e;
case 0x0c099570u: goto P_0c099570;
case 0x0c099572u: goto P_0c099572;
case 0x0c099574u: goto P_0c099574;
case 0x0c099576u: goto P_0c099576;
case 0x0c099578u: goto P_0c099578;
case 0x0c09957au: goto P_0c09957a;
case 0x0c09957cu: goto P_0c09957c;
case 0x0c09957eu: goto P_0c09957e;
case 0x0c099580u: goto P_0c099580;
case 0x0c099582u: goto P_0c099582;
case 0x0c099584u: goto P_0c099584;
case 0x0c099586u: goto P_0c099586;
case 0x0c099588u: goto P_0c099588;
case 0x0c09958au: goto P_0c09958a;
case 0x0c09958cu: goto P_0c09958c;
case 0x0c09958eu: goto P_0c09958e;
case 0x0c099590u: goto P_0c099590;
case 0x0c099592u: goto P_0c099592;
case 0x0c099594u: goto P_0c099594;
case 0x0c099596u: goto P_0c099596;
case 0x0c099598u: goto P_0c099598;
case 0x0c09959au: goto P_0c09959a;
case 0x0c09959cu: goto P_0c09959c;
case 0x0c09959eu: goto P_0c09959e;
case 0x0c0995a0u: goto P_0c0995a0;
case 0x0c0995dcu: goto P_0c0995dc;
case 0x0c0995deu: goto P_0c0995de;
case 0x0c0995e0u: goto P_0c0995e0;
case 0x0c0995e2u: goto P_0c0995e2;
case 0x0c0995e4u: goto P_0c0995e4;
case 0x0c0995e6u: goto P_0c0995e6;
case 0x0c0995e8u: goto P_0c0995e8;
case 0x0c0995eau: goto P_0c0995ea;
case 0x0c0995ecu: goto P_0c0995ec;
case 0x0c0995eeu: goto P_0c0995ee;
case 0x0c0995f0u: goto P_0c0995f0;
case 0x0c0995f2u: goto P_0c0995f2;
case 0x0c0995f4u: goto P_0c0995f4;
case 0x0c0995f6u: goto P_0c0995f6;
case 0x0c0995f8u: goto P_0c0995f8;
case 0x0c0995fau: goto P_0c0995fa;
case 0x0c0995fcu: goto P_0c0995fc;
case 0x0c0995feu: goto P_0c0995fe;
case 0x0c099600u: goto P_0c099600;
case 0x0c099602u: goto P_0c099602;
case 0x0c099604u: goto P_0c099604;
case 0x0c099606u: goto P_0c099606;
case 0x0c099608u: goto P_0c099608;
case 0x0c09960au: goto P_0c09960a;
case 0x0c09960cu: goto P_0c09960c;
case 0x0c09960eu: goto P_0c09960e;
case 0x0c099610u: goto P_0c099610;
case 0x0c099612u: goto P_0c099612;
case 0x0c099614u: goto P_0c099614;
case 0x0c099616u: goto P_0c099616;
case 0x0c099618u: goto P_0c099618;
case 0x0c09961au: goto P_0c09961a;
case 0x0c09961cu: goto P_0c09961c;
case 0x0c09961eu: goto P_0c09961e;
case 0x0c099620u: goto P_0c099620;
case 0x0c099622u: goto P_0c099622;
case 0x0c099624u: goto P_0c099624;
case 0x0c099626u: goto P_0c099626;
case 0x0c099628u: goto P_0c099628;
case 0x0c09962au: goto P_0c09962a;
case 0x0c09962cu: goto P_0c09962c;
case 0x0c09962eu: goto P_0c09962e;
case 0x0c099630u: goto P_0c099630;
case 0x0c099632u: goto P_0c099632;
case 0x0c099634u: goto P_0c099634;
case 0x0c099636u: goto P_0c099636;
case 0x0c099638u: goto P_0c099638;
case 0x0c09963au: goto P_0c09963a;
case 0x0c09963cu: goto P_0c09963c;
case 0x0c09963eu: goto P_0c09963e;
case 0x0c099640u: goto P_0c099640;
case 0x0c099642u: goto P_0c099642;
case 0x0c099644u: goto P_0c099644;
case 0x0c099646u: goto P_0c099646;
case 0x0c099648u: goto P_0c099648;
case 0x0c09964au: goto P_0c09964a;
case 0x0c09964cu: goto P_0c09964c;
case 0x0c09964eu: goto P_0c09964e;
case 0x0c099650u: goto P_0c099650;
case 0x0c099652u: goto P_0c099652;
case 0x0c099654u: goto P_0c099654;
case 0x0c099656u: goto P_0c099656;
case 0x0c099658u: goto P_0c099658;
case 0x0c09965au: goto P_0c09965a;
case 0x0c09965cu: goto P_0c09965c;
case 0x0c09965eu: goto P_0c09965e;
case 0x0c099660u: goto P_0c099660;
case 0x0c099662u: goto P_0c099662;
case 0x0c099664u: goto P_0c099664;
case 0x0c099666u: goto P_0c099666;
case 0x0c099668u: goto P_0c099668;
case 0x0c09966au: goto P_0c09966a;
case 0x0c09966cu: goto P_0c09966c;
case 0x0c09966eu: goto P_0c09966e;
case 0x0c099670u: goto P_0c099670;
case 0x0c099672u: goto P_0c099672;
case 0x0c099674u: goto P_0c099674;
case 0x0c099676u: goto P_0c099676;
case 0x0c099678u: goto P_0c099678;
case 0x0c09967au: goto P_0c09967a;
case 0x0c09967cu: goto P_0c09967c;
case 0x0c09967eu: goto P_0c09967e;
case 0x0c099680u: goto P_0c099680;
case 0x0c099682u: goto P_0c099682;
case 0x0c099684u: goto P_0c099684;
case 0x0c099686u: goto P_0c099686;
case 0x0c099688u: goto P_0c099688;
case 0x0c09968au: goto P_0c09968a;
case 0x0c09968cu: goto P_0c09968c;
case 0x0c09968eu: goto P_0c09968e;
case 0x0c099690u: goto P_0c099690;
case 0x0c099692u: goto P_0c099692;
case 0x0c099694u: goto P_0c099694;
case 0x0c099696u: goto P_0c099696;
case 0x0c099698u: goto P_0c099698;
case 0x0c09969au: goto P_0c09969a;
case 0x0c09969cu: goto P_0c09969c;
case 0x0c09969eu: goto P_0c09969e;
case 0x0c0996a0u: goto P_0c0996a0;
case 0x0c0996a2u: goto P_0c0996a2;
case 0x0c0996a4u: goto P_0c0996a4;
case 0x0c0996a6u: goto P_0c0996a6;
case 0x0c0996a8u: goto P_0c0996a8;
case 0x0c0996aau: goto P_0c0996aa;
case 0x0c0996acu: goto P_0c0996ac;
case 0x0c0996aeu: goto P_0c0996ae;
case 0x0c0996b0u: goto P_0c0996b0;
case 0x0c0996b2u: goto P_0c0996b2;
case 0x0c0996b4u: goto P_0c0996b4;
case 0x0c0996b6u: goto P_0c0996b6;
case 0x0c0996b8u: goto P_0c0996b8;
case 0x0c0996bau: goto P_0c0996ba;
case 0x0c0996bcu: goto P_0c0996bc;
case 0x0c0996beu: goto P_0c0996be;
case 0x0c0996c0u: goto P_0c0996c0;
case 0x0c0996c2u: goto P_0c0996c2;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09690a: /* original 6042, guest PC 0x0c09690a */
if(!s->budget--) { s->failed_pc=0x0c09690au; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c09690c;
P_0c09690c: /* original cb01, guest PC 0x0c09690c */
if(!s->budget--) { s->failed_pc=0x0c09690cu; return 0; }
r[0]|=1u;
goto P_0c09690e;
P_0c09690e: /* original 2402, guest PC 0x0c09690e */
if(!s->budget--) { s->failed_pc=0x0c09690eu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c096910;
P_0c096910: /* original 000b, guest PC 0x0c096910 */
if(!s->budget--) { s->failed_pc=0x0c096910u; return 0; }
target=r[16];
write(ram,r[4]+12,r[5],4);
s->pc=target; return ram->oob==0;
P_0c096912: /* original 1453, guest PC 0x0c096912 */
if(!s->budget--) { s->failed_pc=0x0c096912u; return 0; }
write(ram,r[4]+12,r[5],4);
if(!vf3_matrix_family(0x0c096914u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096914u; return 0; } return 1;
P_0c096944: /* original 2fe6, guest PC 0x0c096944 */
if(!s->budget--) { s->failed_pc=0x0c096944u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096946;
P_0c096946: /* original e600, guest PC 0x0c096946 */
if(!s->budget--) { s->failed_pc=0x0c096946u; return 0; }
r[6]=0x00000000u;
goto P_0c096948;
P_0c096948: /* original 2fd6, guest PC 0x0c096948 */
if(!s->budget--) { s->failed_pc=0x0c096948u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09694a;
P_0c09694a: /* original 6563, guest PC 0x0c09694a */
if(!s->budget--) { s->failed_pc=0x0c09694au; return 0; }
r[5]=r[6];
goto P_0c09694c;
P_0c09694c: /* original 2fc6, guest PC 0x0c09694c */
if(!s->budget--) { s->failed_pc=0x0c09694cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09694e;
P_0c09694e: /* original 2fb6, guest PC 0x0c09694e */
if(!s->budget--) { s->failed_pc=0x0c09694eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096950;
P_0c096950: /* original 2fa6, guest PC 0x0c096950 */
if(!s->budget--) { s->failed_pc=0x0c096950u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096952;
P_0c096952: /* original 2f96, guest PC 0x0c096952 */
if(!s->budget--) { s->failed_pc=0x0c096952u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096954;
P_0c096954: /* original 2f86, guest PC 0x0c096954 */
if(!s->budget--) { s->failed_pc=0x0c096954u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096956;
P_0c096956: /* original fffb, guest PC 0x0c096956 */
if(!s->budget--) { s->failed_pc=0x0c096956u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c096958;
P_0c096958: /* original 4f22, guest PC 0x0c096958 */
if(!s->budget--) { s->failed_pc=0x0c096958u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09695a;
P_0c09695a: /* original d336, guest PC 0x0c09695a */
if(!s->budget--) { s->failed_pc=0x0c09695au; return 0; }
r[3]=read(ram,0x0c096a34u,4);
goto P_0c09695c;
P_0c09695c: /* original de34, guest PC 0x0c09695c */
if(!s->budget--) { s->failed_pc=0x0c09695cu; return 0; }
r[14]=read(ram,0x0c096a30u,4);
goto P_0c09695e;
P_0c09695e: /* original 430b, guest PC 0x0c09695e */
if(!s->budget--) { s->failed_pc=0x0c09695eu; return 0; }
target=r[3];
r[16]=code_base|0x0c096962u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096962u) { target=s->pc; goto dispatch; }
goto P_0c096962;
P_0c096960: /* original 6463, guest PC 0x0c096960 */
if(!s->budget--) { s->failed_pc=0x0c096960u; return 0; }
r[4]=r[6];
goto P_0c096962;
P_0c096962: /* original e600, guest PC 0x0c096962 */
if(!s->budget--) { s->failed_pc=0x0c096962u; return 0; }
r[6]=0x00000000u;
goto P_0c096964;
P_0c096964: /* original d234, guest PC 0x0c096964 */
if(!s->budget--) { s->failed_pc=0x0c096964u; return 0; }
r[2]=read(ram,0x0c096a38u,4);
goto P_0c096966;
P_0c096966: /* original ff8d, guest PC 0x0c096966 */
if(!s->budget--) { s->failed_pc=0x0c096966u; return 0; }
fr[15]=0;
goto P_0c096968;
P_0c096968: /* original 6563, guest PC 0x0c096968 */
if(!s->budget--) { s->failed_pc=0x0c096968u; return 0; }
r[5]=r[6];
goto P_0c09696a;
P_0c09696a: /* original f5fc, guest PC 0x0c09696a */
if(!s->budget--) { s->failed_pc=0x0c09696au; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09696c;
P_0c09696c: /* original f4fc, guest PC 0x0c09696c */
if(!s->budget--) { s->failed_pc=0x0c09696cu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09696e;
P_0c09696e: /* original 420b, guest PC 0x0c09696e */
if(!s->budget--) { s->failed_pc=0x0c09696eu; return 0; }
target=r[2];
r[16]=code_base|0x0c096972u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096972u) { target=s->pc; goto dispatch; }
goto P_0c096972;
P_0c096970: /* original 6463, guest PC 0x0c096970 */
if(!s->budget--) { s->failed_pc=0x0c096970u; return 0; }
r[4]=r[6];
goto P_0c096972;
P_0c096972: /* original d332, guest PC 0x0c096972 */
if(!s->budget--) { s->failed_pc=0x0c096972u; return 0; }
r[3]=read(ram,0x0c096a3cu,4);
goto P_0c096974;
P_0c096974: /* original 430b, guest PC 0x0c096974 */
if(!s->budget--) { s->failed_pc=0x0c096974u; return 0; }
target=r[3];
r[16]=code_base|0x0c096978u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096978u) { target=s->pc; goto dispatch; }
goto P_0c096978;
P_0c096976: /* original 0009, guest PC 0x0c096976 */
if(!s->budget--) { s->failed_pc=0x0c096976u; return 0; }
goto P_0c096978;
P_0c096978: /* original d22e, guest PC 0x0c096978 */
if(!s->budget--) { s->failed_pc=0x0c096978u; return 0; }
r[2]=read(ram,0x0c096a34u,4);
goto P_0c09697a;
P_0c09697a: /* original e600, guest PC 0x0c09697a */
if(!s->budget--) { s->failed_pc=0x0c09697au; return 0; }
r[6]=0x00000000u;
goto P_0c09697c;
P_0c09697c: /* original 6563, guest PC 0x0c09697c */
if(!s->budget--) { s->failed_pc=0x0c09697cu; return 0; }
r[5]=r[6];
goto P_0c09697e;
P_0c09697e: /* original 420b, guest PC 0x0c09697e */
if(!s->budget--) { s->failed_pc=0x0c09697eu; return 0; }
target=r[2];
r[16]=code_base|0x0c096982u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096982u) { target=s->pc; goto dispatch; }
goto P_0c096982;
P_0c096980: /* original 6463, guest PC 0x0c096980 */
if(!s->budget--) { s->failed_pc=0x0c096980u; return 0; }
r[4]=r[6];
goto P_0c096982;
P_0c096982: /* original e600, guest PC 0x0c096982 */
if(!s->budget--) { s->failed_pc=0x0c096982u; return 0; }
r[6]=0x00000000u;
goto P_0c096984;
P_0c096984: /* original d32c, guest PC 0x0c096984 */
if(!s->budget--) { s->failed_pc=0x0c096984u; return 0; }
r[3]=read(ram,0x0c096a38u,4);
goto P_0c096986;
P_0c096986: /* original f5fc, guest PC 0x0c096986 */
if(!s->budget--) { s->failed_pc=0x0c096986u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c096988;
P_0c096988: /* original 6563, guest PC 0x0c096988 */
if(!s->budget--) { s->failed_pc=0x0c096988u; return 0; }
r[5]=r[6];
goto P_0c09698a;
P_0c09698a: /* original f4fc, guest PC 0x0c09698a */
if(!s->budget--) { s->failed_pc=0x0c09698au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c09698c;
P_0c09698c: /* original 430b, guest PC 0x0c09698c */
if(!s->budget--) { s->failed_pc=0x0c09698cu; return 0; }
target=r[3];
r[16]=code_base|0x0c096990u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096990u) { target=s->pc; goto dispatch; }
goto P_0c096990;
P_0c09698e: /* original 6463, guest PC 0x0c09698e */
if(!s->budget--) { s->failed_pc=0x0c09698eu; return 0; }
r[4]=r[6];
goto P_0c096990;
P_0c096990: /* original d22a, guest PC 0x0c096990 */
if(!s->budget--) { s->failed_pc=0x0c096990u; return 0; }
r[2]=read(ram,0x0c096a3cu,4);
goto P_0c096992;
P_0c096992: /* original 420b, guest PC 0x0c096992 */
if(!s->budget--) { s->failed_pc=0x0c096992u; return 0; }
target=r[2];
r[16]=code_base|0x0c096996u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096996u) { target=s->pc; goto dispatch; }
goto P_0c096996;
P_0c096994: /* original 0009, guest PC 0x0c096994 */
if(!s->budget--) { s->failed_pc=0x0c096994u; return 0; }
goto P_0c096996;
P_0c096996: /* original d32a, guest PC 0x0c096996 */
if(!s->budget--) { s->failed_pc=0x0c096996u; return 0; }
r[3]=read(ram,0x0c096a40u,4);
goto P_0c096998;
P_0c096998: /* original 430b, guest PC 0x0c096998 */
if(!s->budget--) { s->failed_pc=0x0c096998u; return 0; }
target=r[3];
r[16]=code_base|0x0c09699cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09699cu) { target=s->pc; goto dispatch; }
goto P_0c09699c;
P_0c09699a: /* original 0009, guest PC 0x0c09699a */
if(!s->budget--) { s->failed_pc=0x0c09699au; return 0; }
goto P_0c09699c;
P_0c09699c: /* original 9442, guest PC 0x0c09699c */
if(!s->budget--) { s->failed_pc=0x0c09699cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a24u,2);
goto P_0c09699e;
P_0c09699e: /* original e802, guest PC 0x0c09699e */
if(!s->budget--) { s->failed_pc=0x0c09699eu; return 0; }
r[8]=0x00000002u;
goto P_0c0969a0;
P_0c0969a0: /* original 9a41, guest PC 0x0c0969a0 */
if(!s->budget--) { s->failed_pc=0x0c0969a0u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a26u,2);
goto P_0c0969a2;
P_0c0969a2: /* original ec00, guest PC 0x0c0969a2 */
if(!s->budget--) { s->failed_pc=0x0c0969a2u; return 0; }
r[12]=0x00000000u;
goto P_0c0969a4;
P_0c0969a4: /* original dd27, guest PC 0x0c0969a4 */
if(!s->budget--) { s->failed_pc=0x0c0969a4u; return 0; }
r[13]=read(ram,0x0c096a44u,4);
goto P_0c0969a6;
P_0c0969a6: /* original 34ec, guest PC 0x0c0969a6 */
if(!s->budget--) { s->failed_pc=0x0c0969a6u; return 0; }
r[4]+=r[14];
goto P_0c0969a8;
P_0c0969a8: /* original 3aec, guest PC 0x0c0969a8 */
if(!s->budget--) { s->failed_pc=0x0c0969a8u; return 0; }
r[10]+=r[14];
goto P_0c0969aa;
P_0c0969aa: /* original 6b43, guest PC 0x0c0969aa */
if(!s->budget--) { s->failed_pc=0x0c0969aau; return 0; }
r[11]=r[4];
goto P_0c0969ac;
P_0c0969ac: /* original 6943, guest PC 0x0c0969ac */
if(!s->budget--) { s->failed_pc=0x0c0969acu; return 0; }
r[9]=r[4];
goto P_0c0969ae;
P_0c0969ae: /* original 933a, guest PC 0x0c0969ae */
if(!s->budget--) { s->failed_pc=0x0c0969aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a26u,2);
goto P_0c0969b0;
P_0c0969b0: /* original 62c3, guest PC 0x0c0969b0 */
if(!s->budget--) { s->failed_pc=0x0c0969b0u; return 0; }
r[2]=r[12];
goto P_0c0969b2;
P_0c0969b2: /* original 4208, guest PC 0x0c0969b2 */
if(!s->budget--) { s->failed_pc=0x0c0969b2u; return 0; }
r[2]<<=2;
goto P_0c0969b4;
P_0c0969b4: /* original 33ec, guest PC 0x0c0969b4 */
if(!s->budget--) { s->failed_pc=0x0c0969b4u; return 0; }
r[3]+=r[14];
goto P_0c0969b6;
P_0c0969b6: /* original 323c, guest PC 0x0c0969b6 */
if(!s->budget--) { s->failed_pc=0x0c0969b6u; return 0; }
r[2]+=r[3];
goto P_0c0969b8;
P_0c0969b8: /* original 6122, guest PC 0x0c0969b8 */
if(!s->budget--) { s->failed_pc=0x0c0969b8u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0969ba;
P_0c0969ba: /* original 2118, guest PC 0x0c0969ba */
if(!s->budget--) { s->failed_pc=0x0c0969bau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0969bc;
P_0c0969bc: /* original 8901, guest PC 0x0c0969bc */
if(!s->budget--) { s->failed_pc=0x0c0969bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0969c2; }
goto P_0c0969be;
P_0c0969be: /* original 4d0b, guest PC 0x0c0969be */
if(!s->budget--) { s->failed_pc=0x0c0969beu; return 0; }
target=r[13];
r[16]=code_base|0x0c0969c2u;
tmp=read(ram,r[10],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0969c2u) { target=s->pc; goto dispatch; }
goto P_0c0969c2;
P_0c0969c0: /* original 64a2, guest PC 0x0c0969c0 */
if(!s->budget--) { s->failed_pc=0x0c0969c0u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0969c2;
P_0c0969c2: /* original 6392, guest PC 0x0c0969c2 */
if(!s->budget--) { s->failed_pc=0x0c0969c2u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c0969c4;
P_0c0969c4: /* original 2338, guest PC 0x0c0969c4 */
if(!s->budget--) { s->failed_pc=0x0c0969c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0969c6;
P_0c0969c6: /* original 8901, guest PC 0x0c0969c6 */
if(!s->budget--) { s->failed_pc=0x0c0969c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0969cc; }
goto P_0c0969c8;
P_0c0969c8: /* original 4d0b, guest PC 0x0c0969c8 */
if(!s->budget--) { s->failed_pc=0x0c0969c8u; return 0; }
target=r[13];
r[16]=code_base|0x0c0969ccu;
tmp=read(ram,r[11],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0969ccu) { target=s->pc; goto dispatch; }
goto P_0c0969cc;
P_0c0969ca: /* original 64b2, guest PC 0x0c0969ca */
if(!s->budget--) { s->failed_pc=0x0c0969cau; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c0969cc;
P_0c0969cc: /* original 7c01, guest PC 0x0c0969cc */
if(!s->budget--) { s->failed_pc=0x0c0969ccu; return 0; }
r[12]+=0x00000001u;
goto P_0c0969ce;
P_0c0969ce: /* original 3c83, guest PC 0x0c0969ce */
if(!s->budget--) { s->failed_pc=0x0c0969ceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[8])!=0);
goto P_0c0969d0;
P_0c0969d0: /* original 7904, guest PC 0x0c0969d0 */
if(!s->budget--) { s->failed_pc=0x0c0969d0u; return 0; }
r[9]+=0x00000004u;
goto P_0c0969d2;
P_0c0969d2: /* original 7b04, guest PC 0x0c0969d2 */
if(!s->budget--) { s->failed_pc=0x0c0969d2u; return 0; }
r[11]+=0x00000004u;
goto P_0c0969d4;
P_0c0969d4: /* original 8feb, guest PC 0x0c0969d4 */
if(!s->budget--) { s->failed_pc=0x0c0969d4u; return 0; }
cond=r[17]&1u;
r[10]+=0x00000004u;
if(!cond) { goto P_0c0969ae; }
goto P_0c0969d8;
P_0c0969d6: /* original 7a04, guest PC 0x0c0969d6 */
if(!s->budget--) { s->failed_pc=0x0c0969d6u; return 0; }
r[10]+=0x00000004u;
goto P_0c0969d8;
P_0c0969d8: /* original 9026, guest PC 0x0c0969d8 */
if(!s->budget--) { s->failed_pc=0x0c0969d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a28u,2);
goto P_0c0969da;
P_0c0969da: /* original 02ee, guest PC 0x0c0969da */
if(!s->budget--) { s->failed_pc=0x0c0969dau; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0969dc;
P_0c0969dc: /* original 2228, guest PC 0x0c0969dc */
if(!s->budget--) { s->failed_pc=0x0c0969dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0969de;
P_0c0969de: /* original 8901, guest PC 0x0c0969de */
if(!s->budget--) { s->failed_pc=0x0c0969deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0969e4; }
goto P_0c0969e0;
P_0c0969e0: /* original 4d0b, guest PC 0x0c0969e0 */
if(!s->budget--) { s->failed_pc=0x0c0969e0u; return 0; }
target=r[13];
r[16]=code_base|0x0c0969e4u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0969e4u) { target=s->pc; goto dispatch; }
goto P_0c0969e4;
P_0c0969e2: /* original 04ee, guest PC 0x0c0969e2 */
if(!s->budget--) { s->failed_pc=0x0c0969e2u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0969e4;
P_0c0969e4: /* original 9021, guest PC 0x0c0969e4 */
if(!s->budget--) { s->failed_pc=0x0c0969e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a2au,2);
goto P_0c0969e6;
P_0c0969e6: /* original 03ee, guest PC 0x0c0969e6 */
if(!s->budget--) { s->failed_pc=0x0c0969e6u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0969e8;
P_0c0969e8: /* original 2338, guest PC 0x0c0969e8 */
if(!s->budget--) { s->failed_pc=0x0c0969e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0969ea;
P_0c0969ea: /* original 8901, guest PC 0x0c0969ea */
if(!s->budget--) { s->failed_pc=0x0c0969eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0969f0; }
goto P_0c0969ec;
P_0c0969ec: /* original 4d0b, guest PC 0x0c0969ec */
if(!s->budget--) { s->failed_pc=0x0c0969ecu; return 0; }
target=r[13];
r[16]=code_base|0x0c0969f0u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0969f0u) { target=s->pc; goto dispatch; }
goto P_0c0969f0;
P_0c0969ee: /* original 04ee, guest PC 0x0c0969ee */
if(!s->budget--) { s->failed_pc=0x0c0969eeu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0969f0;
P_0c0969f0: /* original 901c, guest PC 0x0c0969f0 */
if(!s->budget--) { s->failed_pc=0x0c0969f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a2cu,2);
goto P_0c0969f2;
P_0c0969f2: /* original 03ee, guest PC 0x0c0969f2 */
if(!s->budget--) { s->failed_pc=0x0c0969f2u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0969f4;
P_0c0969f4: /* original 2338, guest PC 0x0c0969f4 */
if(!s->budget--) { s->failed_pc=0x0c0969f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0969f6;
P_0c0969f6: /* original 8901, guest PC 0x0c0969f6 */
if(!s->budget--) { s->failed_pc=0x0c0969f6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0969fc; }
goto P_0c0969f8;
P_0c0969f8: /* original 4d0b, guest PC 0x0c0969f8 */
if(!s->budget--) { s->failed_pc=0x0c0969f8u; return 0; }
target=r[13];
r[16]=code_base|0x0c0969fcu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0969fcu) { target=s->pc; goto dispatch; }
goto P_0c0969fc;
P_0c0969fa: /* original 04ee, guest PC 0x0c0969fa */
if(!s->budget--) { s->failed_pc=0x0c0969fau; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0969fc;
P_0c0969fc: /* original 9017, guest PC 0x0c0969fc */
if(!s->budget--) { s->failed_pc=0x0c0969fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c096a2eu,2);
goto P_0c0969fe;
P_0c0969fe: /* original 03ee, guest PC 0x0c0969fe */
if(!s->budget--) { s->failed_pc=0x0c0969feu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c096a00;
P_0c096a00: /* original 2338, guest PC 0x0c096a00 */
if(!s->budget--) { s->failed_pc=0x0c096a00u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c096a02;
P_0c096a02: /* original 8901, guest PC 0x0c096a02 */
if(!s->budget--) { s->failed_pc=0x0c096a02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096a08; }
goto P_0c096a04;
P_0c096a04: /* original 4d0b, guest PC 0x0c096a04 */
if(!s->budget--) { s->failed_pc=0x0c096a04u; return 0; }
target=r[13];
r[16]=code_base|0x0c096a08u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096a08u) { target=s->pc; goto dispatch; }
goto P_0c096a08;
P_0c096a06: /* original 04ee, guest PC 0x0c096a06 */
if(!s->budget--) { s->failed_pc=0x0c096a06u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c096a08;
P_0c096a08: /* original d30f, guest PC 0x0c096a08 */
if(!s->budget--) { s->failed_pc=0x0c096a08u; return 0; }
r[3]=read(ram,0x0c096a48u,4);
goto P_0c096a0a;
P_0c096a0a: /* original 430b, guest PC 0x0c096a0a */
if(!s->budget--) { s->failed_pc=0x0c096a0au; return 0; }
target=r[3];
r[16]=code_base|0x0c096a0eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096a0eu) { target=s->pc; goto dispatch; }
goto P_0c096a0e;
P_0c096a0c: /* original 0009, guest PC 0x0c096a0c */
if(!s->budget--) { s->failed_pc=0x0c096a0cu; return 0; }
goto P_0c096a0e;
P_0c096a0e: /* original 4f26, guest PC 0x0c096a0e */
if(!s->budget--) { s->failed_pc=0x0c096a0eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096a10;
P_0c096a10: /* original d20e, guest PC 0x0c096a10 */
if(!s->budget--) { s->failed_pc=0x0c096a10u; return 0; }
r[2]=read(ram,0x0c096a4cu,4);
goto P_0c096a12;
P_0c096a12: /* original fff9, guest PC 0x0c096a12 */
if(!s->budget--) { s->failed_pc=0x0c096a12u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c096a14;
P_0c096a14: /* original 68f6, guest PC 0x0c096a14 */
if(!s->budget--) { s->failed_pc=0x0c096a14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c096a16;
P_0c096a16: /* original 69f6, guest PC 0x0c096a16 */
if(!s->budget--) { s->failed_pc=0x0c096a16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c096a18;
P_0c096a18: /* original 6af6, guest PC 0x0c096a18 */
if(!s->budget--) { s->failed_pc=0x0c096a18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c096a1a;
P_0c096a1a: /* original 6bf6, guest PC 0x0c096a1a */
if(!s->budget--) { s->failed_pc=0x0c096a1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c096a1c;
P_0c096a1c: /* original 6cf6, guest PC 0x0c096a1c */
if(!s->budget--) { s->failed_pc=0x0c096a1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c096a1e;
P_0c096a1e: /* original 6df6, guest PC 0x0c096a1e */
if(!s->budget--) { s->failed_pc=0x0c096a1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096a20;
P_0c096a20: /* original 422b, guest PC 0x0c096a20 */
if(!s->budget--) { s->failed_pc=0x0c096a20u; return 0; }
target=r[2];
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
P_0c096a22: /* original 6ef6, guest PC 0x0c096a22 */
if(!s->budget--) { s->failed_pc=0x0c096a22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c096a24u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096a24u; return 0; } return 1;
P_0c097ff4: /* original d427, guest PC 0x0c097ff4 */
if(!s->budget--) { s->failed_pc=0x0c097ff4u; return 0; }
r[4]=read(ram,0x0c098094u,4);
goto P_0c097ff6;
P_0c097ff6: /* original d329, guest PC 0x0c097ff6 */
if(!s->budget--) { s->failed_pc=0x0c097ff6u; return 0; }
r[3]=read(ram,0x0c09809cu,4);
goto P_0c097ff8;
P_0c097ff8: /* original 5242, guest PC 0x0c097ff8 */
if(!s->budget--) { s->failed_pc=0x0c097ff8u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c097ffa;
P_0c097ffa: /* original d627, guest PC 0x0c097ffa */
if(!s->budget--) { s->failed_pc=0x0c097ffau; return 0; }
r[6]=read(ram,0x0c098098u,4);
goto P_0c097ffc;
P_0c097ffc: /* original 2238, guest PC 0x0c097ffc */
if(!s->budget--) { s->failed_pc=0x0c097ffcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c097ffe;
P_0c097ffe: /* original 8b1d, guest PC 0x0c097ffe */
if(!s->budget--) { s->failed_pc=0x0c097ffeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09803c; }
goto P_0c098000;
P_0c098000: /* original 5142, guest PC 0x0c098000 */
if(!s->budget--) { s->failed_pc=0x0c098000u; return 0; }
r[1]=read(ram,r[4]+8,4);
goto P_0c098002;
P_0c098002: /* original d327, guest PC 0x0c098002 */
if(!s->budget--) { s->failed_pc=0x0c098002u; return 0; }
r[3]=read(ram,0x0c0980a0u,4);
goto P_0c098004;
P_0c098004: /* original 2138, guest PC 0x0c098004 */
if(!s->budget--) { s->failed_pc=0x0c098004u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c098006;
P_0c098006: /* original 8919, guest PC 0x0c098006 */
if(!s->budget--) { s->failed_pc=0x0c098006u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09803c; }
goto P_0c098008;
P_0c098008: /* original 5242, guest PC 0x0c098008 */
if(!s->budget--) { s->failed_pc=0x0c098008u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c09800a;
P_0c09800a: /* original d326, guest PC 0x0c09800a */
if(!s->budget--) { s->failed_pc=0x0c09800au; return 0; }
r[3]=read(ram,0x0c0980a4u,4);
goto P_0c09800c;
P_0c09800c: /* original 2238, guest PC 0x0c09800c */
if(!s->budget--) { s->failed_pc=0x0c09800cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09800e;
P_0c09800e: /* original 8d0f, guest PC 0x0c09800e */
if(!s->budget--) { s->failed_pc=0x0c09800eu; return 0; }
cond=r[17]&1u;
r[7]=0x00000000u;
if(cond) { goto P_0c098030; }
goto P_0c098012;
P_0c098010: /* original e700, guest PC 0x0c098010 */
if(!s->budget--) { s->failed_pc=0x0c098010u; return 0; }
r[7]=0x00000000u;
goto P_0c098012;
P_0c098012: /* original e029, guest PC 0x0c098012 */
if(!s->budget--) { s->failed_pc=0x0c098012u; return 0; }
r[0]=0x00000029u;
goto P_0c098014;
P_0c098014: /* original 004c, guest PC 0x0c098014 */
if(!s->budget--) { s->failed_pc=0x0c098014u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c098016;
P_0c098016: /* original 600c, guest PC 0x0c098016 */
if(!s->budget--) { s->failed_pc=0x0c098016u; return 0; }
r[0]=r[0]&255u;
goto P_0c098018;
P_0c098018: /* original 8803, guest PC 0x0c098018 */
if(!s->budget--) { s->failed_pc=0x0c098018u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09801a;
P_0c09801a: /* original 8909, guest PC 0x0c09801a */
if(!s->budget--) { s->failed_pc=0x0c09801au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098030; }
goto P_0c09801c;
P_0c09801c: /* original e02b, guest PC 0x0c09801c */
if(!s->budget--) { s->failed_pc=0x0c09801cu; return 0; }
r[0]=0x0000002bu;
goto P_0c09801e;
P_0c09801e: /* original 034c, guest PC 0x0c09801e */
if(!s->budget--) { s->failed_pc=0x0c09801eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c098020;
P_0c098020: /* original 7301, guest PC 0x0c098020 */
if(!s->budget--) { s->failed_pc=0x0c098020u; return 0; }
r[3]+=0x00000001u;
goto P_0c098022;
P_0c098022: /* original 0434, guest PC 0x0c098022 */
if(!s->budget--) { s->failed_pc=0x0c098022u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c098024;
P_0c098024: /* original 554d, guest PC 0x0c098024 */
if(!s->budget--) { s->failed_pc=0x0c098024u; return 0; }
r[5]=read(ram,r[4]+52,4);
goto P_0c098026;
P_0c098026: /* original 534e, guest PC 0x0c098026 */
if(!s->budget--) { s->failed_pc=0x0c098026u; return 0; }
r[3]=read(ram,r[4]+56,4);
goto P_0c098028;
P_0c098028: /* original 353c, guest PC 0x0c098028 */
if(!s->budget--) { s->failed_pc=0x0c098028u; return 0; }
r[5]+=r[3];
goto P_0c09802a;
P_0c09802a: /* original 145c, guest PC 0x0c09802a */
if(!s->budget--) { s->failed_pc=0x0c09802au; return 0; }
write(ram,r[4]+48,r[5],4);
goto P_0c09802c;
P_0c09802c: /* original 145d, guest PC 0x0c09802c */
if(!s->budget--) { s->failed_pc=0x0c09802cu; return 0; }
write(ram,r[4]+52,r[5],4);
goto P_0c09802e;
P_0c09802e: /* original 147e, guest PC 0x0c09802e */
if(!s->budget--) { s->failed_pc=0x0c09802eu; return 0; }
write(ram,r[4]+56,r[7],4);
goto P_0c098030;
P_0c098030: /* original e010, guest PC 0x0c098030 */
if(!s->budget--) { s->failed_pc=0x0c098030u; return 0; }
r[0]=0x00000010u;
goto P_0c098032;
P_0c098032: /* original 0674, guest PC 0x0c098032 */
if(!s->budget--) { s->failed_pc=0x0c098032u; return 0; }
write(ram,r[6]+r[0],r[7],1);
goto P_0c098034;
P_0c098034: /* original e00a, guest PC 0x0c098034 */
if(!s->budget--) { s->failed_pc=0x0c098034u; return 0; }
r[0]=0x0000000au;
goto P_0c098036;
P_0c098036: /* original d31c, guest PC 0x0c098036 */
if(!s->budget--) { s->failed_pc=0x0c098036u; return 0; }
r[3]=read(ram,0x0c0980a8u,4);
goto P_0c098038;
P_0c098038: /* original 432b, guest PC 0x0c098038 */
if(!s->budget--) { s->failed_pc=0x0c098038u; return 0; }
target=r[3];
write(ram,r[6]+10,r[0],1);
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0968d0u: return vf3_matrix_family(0x0c0968d0u,s,ram);
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
P_0c09803a: /* original 806a, guest PC 0x0c09803a */
if(!s->budget--) { s->failed_pc=0x0c09803au; return 0; }
write(ram,r[6]+10,r[0],1);
goto P_0c09803c;
P_0c09803c: /* original 000b, guest PC 0x0c09803c */
if(!s->budget--) { s->failed_pc=0x0c09803cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09803e: /* original 0009, guest PC 0x0c09803e */
if(!s->budget--) { s->failed_pc=0x0c09803eu; return 0; }
goto P_0c098040;
P_0c098040: /* original 2fe6, guest PC 0x0c098040 */
if(!s->budget--) { s->failed_pc=0x0c098040u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098042;
P_0c098042: /* original 4f22, guest PC 0x0c098042 */
if(!s->budget--) { s->failed_pc=0x0c098042u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c098044;
P_0c098044: /* original d31a, guest PC 0x0c098044 */
if(!s->budget--) { s->failed_pc=0x0c098044u; return 0; }
r[3]=read(ram,0x0c0980b0u,4);
goto P_0c098046;
P_0c098046: /* original d419, guest PC 0x0c098046 */
if(!s->budget--) { s->failed_pc=0x0c098046u; return 0; }
r[4]=read(ram,0x0c0980acu,4);
goto P_0c098048;
P_0c098048: /* original 430b, guest PC 0x0c098048 */
if(!s->budget--) { s->failed_pc=0x0c098048u; return 0; }
target=r[3];
r[16]=code_base|0x0c09804cu;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09804cu) { target=s->pc; goto dispatch; }
goto P_0c09804c;
P_0c09804a: /* original e500, guest PC 0x0c09804a */
if(!s->budget--) { s->failed_pc=0x0c09804au; return 0; }
r[5]=0x00000000u;
goto P_0c09804c;
P_0c09804c: /* original d21a, guest PC 0x0c09804c */
if(!s->budget--) { s->failed_pc=0x0c09804cu; return 0; }
r[2]=read(ram,0x0c0980b8u,4);
goto P_0c09804e;
P_0c09804e: /* original de19, guest PC 0x0c09804e */
if(!s->budget--) { s->failed_pc=0x0c09804eu; return 0; }
r[14]=read(ram,0x0c0980b4u,4);
goto P_0c098050;
P_0c098050: /* original 420b, guest PC 0x0c098050 */
if(!s->budget--) { s->failed_pc=0x0c098050u; return 0; }
target=r[2];
r[16]=code_base|0x0c098054u;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098054u) { target=s->pc; goto dispatch; }
goto P_0c098054;
P_0c098052: /* original 54e4, guest PC 0x0c098052 */
if(!s->budget--) { s->failed_pc=0x0c098052u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c098054;
P_0c098054: /* original d318, guest PC 0x0c098054 */
if(!s->budget--) { s->failed_pc=0x0c098054u; return 0; }
r[3]=read(ram,0x0c0980b8u,4);
goto P_0c098056;
P_0c098056: /* original 430b, guest PC 0x0c098056 */
if(!s->budget--) { s->failed_pc=0x0c098056u; return 0; }
target=r[3];
r[16]=code_base|0x0c09805au;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09805au) { target=s->pc; goto dispatch; }
goto P_0c09805a;
P_0c098058: /* original 54e5, guest PC 0x0c098058 */
if(!s->budget--) { s->failed_pc=0x0c098058u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c09805a;
P_0c09805a: /* original d218, guest PC 0x0c09805a */
if(!s->budget--) { s->failed_pc=0x0c09805au; return 0; }
r[2]=read(ram,0x0c0980bcu,4);
goto P_0c09805c;
P_0c09805c: /* original 420b, guest PC 0x0c09805c */
if(!s->budget--) { s->failed_pc=0x0c09805cu; return 0; }
target=r[2];
r[16]=code_base|0x0c098060u;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098060u) { target=s->pc; goto dispatch; }
goto P_0c098060;
P_0c09805e: /* original 54e4, guest PC 0x0c09805e */
if(!s->budget--) { s->failed_pc=0x0c09805eu; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c098060;
P_0c098060: /* original d316, guest PC 0x0c098060 */
if(!s->budget--) { s->failed_pc=0x0c098060u; return 0; }
r[3]=read(ram,0x0c0980bcu,4);
goto P_0c098062;
P_0c098062: /* original 430b, guest PC 0x0c098062 */
if(!s->budget--) { s->failed_pc=0x0c098062u; return 0; }
target=r[3];
r[16]=code_base|0x0c098066u;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098066u) { target=s->pc; goto dispatch; }
goto P_0c098066;
P_0c098064: /* original 54e5, guest PC 0x0c098064 */
if(!s->budget--) { s->failed_pc=0x0c098064u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c098066;
P_0c098066: /* original d315, guest PC 0x0c098066 */
if(!s->budget--) { s->failed_pc=0x0c098066u; return 0; }
r[3]=read(ram,0x0c0980bcu,4);
goto P_0c098068;
P_0c098068: /* original e048, guest PC 0x0c098068 */
if(!s->budget--) { s->failed_pc=0x0c098068u; return 0; }
r[0]=0x00000048u;
goto P_0c09806a;
P_0c09806a: /* original 430b, guest PC 0x0c09806a */
if(!s->budget--) { s->failed_pc=0x0c09806au; return 0; }
target=r[3];
r[16]=code_base|0x0c09806eu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09806eu) { target=s->pc; goto dispatch; }
goto P_0c09806e;
P_0c09806c: /* original 04ee, guest PC 0x0c09806c */
if(!s->budget--) { s->failed_pc=0x0c09806cu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09806e;
P_0c09806e: /* original d313, guest PC 0x0c09806e */
if(!s->budget--) { s->failed_pc=0x0c09806eu; return 0; }
r[3]=read(ram,0x0c0980bcu,4);
goto P_0c098070;
P_0c098070: /* original e05c, guest PC 0x0c098070 */
if(!s->budget--) { s->failed_pc=0x0c098070u; return 0; }
r[0]=0x0000005cu;
goto P_0c098072;
P_0c098072: /* original 430b, guest PC 0x0c098072 */
if(!s->budget--) { s->failed_pc=0x0c098072u; return 0; }
target=r[3];
r[16]=code_base|0x0c098076u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098076u) { target=s->pc; goto dispatch; }
goto P_0c098076;
P_0c098074: /* original 04ee, guest PC 0x0c098074 */
if(!s->budget--) { s->failed_pc=0x0c098074u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c098076;
P_0c098076: /* original d311, guest PC 0x0c098076 */
if(!s->budget--) { s->failed_pc=0x0c098076u; return 0; }
r[3]=read(ram,0x0c0980bcu,4);
goto P_0c098078;
P_0c098078: /* original e060, guest PC 0x0c098078 */
if(!s->budget--) { s->failed_pc=0x0c098078u; return 0; }
r[0]=0x00000060u;
goto P_0c09807a;
P_0c09807a: /* original 430b, guest PC 0x0c09807a */
if(!s->budget--) { s->failed_pc=0x0c09807au; return 0; }
target=r[3];
r[16]=code_base|0x0c09807eu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09807eu) { target=s->pc; goto dispatch; }
goto P_0c09807e;
P_0c09807c: /* original 04ee, guest PC 0x0c09807c */
if(!s->budget--) { s->failed_pc=0x0c09807cu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09807e;
P_0c09807e: /* original 4f26, guest PC 0x0c09807e */
if(!s->budget--) { s->failed_pc=0x0c09807eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c098080;
P_0c098080: /* original e064, guest PC 0x0c098080 */
if(!s->budget--) { s->failed_pc=0x0c098080u; return 0; }
r[0]=0x00000064u;
goto P_0c098082;
P_0c098082: /* original d30e, guest PC 0x0c098082 */
if(!s->budget--) { s->failed_pc=0x0c098082u; return 0; }
r[3]=read(ram,0x0c0980bcu,4);
goto P_0c098084;
P_0c098084: /* original 04ee, guest PC 0x0c098084 */
if(!s->budget--) { s->failed_pc=0x0c098084u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c098086;
P_0c098086: /* original 432b, guest PC 0x0c098086 */
if(!s->budget--) { s->failed_pc=0x0c098086u; return 0; }
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
P_0c098088: /* original 6ef6, guest PC 0x0c098088 */
if(!s->budget--) { s->failed_pc=0x0c098088u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09808au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09808au; return 0; } return 1;
P_0c09845c: /* original 2fe6, guest PC 0x0c09845c */
if(!s->budget--) { s->failed_pc=0x0c09845cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09845e;
P_0c09845e: /* original e600, guest PC 0x0c09845e */
if(!s->budget--) { s->failed_pc=0x0c09845eu; return 0; }
r[6]=0x00000000u;
goto P_0c098460;
P_0c098460: /* original 2fd6, guest PC 0x0c098460 */
if(!s->budget--) { s->failed_pc=0x0c098460u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098462;
P_0c098462: /* original 6563, guest PC 0x0c098462 */
if(!s->budget--) { s->failed_pc=0x0c098462u; return 0; }
r[5]=r[6];
goto P_0c098464;
P_0c098464: /* original 2fc6, guest PC 0x0c098464 */
if(!s->budget--) { s->failed_pc=0x0c098464u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098466;
P_0c098466: /* original 2fb6, guest PC 0x0c098466 */
if(!s->budget--) { s->failed_pc=0x0c098466u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098468;
P_0c098468: /* original fffb, guest PC 0x0c098468 */
if(!s->budget--) { s->failed_pc=0x0c098468u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09846a;
P_0c09846a: /* original 4f22, guest PC 0x0c09846a */
if(!s->budget--) { s->failed_pc=0x0c09846au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09846c;
P_0c09846c: /* original d33c, guest PC 0x0c09846c */
if(!s->budget--) { s->failed_pc=0x0c09846cu; return 0; }
r[3]=read(ram,0x0c098560u,4);
goto P_0c09846e;
P_0c09846e: /* original de3a, guest PC 0x0c09846e */
if(!s->budget--) { s->failed_pc=0x0c09846eu; return 0; }
r[14]=read(ram,0x0c098558u,4);
goto P_0c098470;
P_0c098470: /* original dd3a, guest PC 0x0c098470 */
if(!s->budget--) { s->failed_pc=0x0c098470u; return 0; }
r[13]=read(ram,0x0c09855cu,4);
goto P_0c098472;
P_0c098472: /* original 430b, guest PC 0x0c098472 */
if(!s->budget--) { s->failed_pc=0x0c098472u; return 0; }
target=r[3];
r[16]=code_base|0x0c098476u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098476u) { target=s->pc; goto dispatch; }
goto P_0c098476;
P_0c098474: /* original 6463, guest PC 0x0c098474 */
if(!s->budget--) { s->failed_pc=0x0c098474u; return 0; }
r[4]=r[6];
goto P_0c098476;
P_0c098476: /* original e600, guest PC 0x0c098476 */
if(!s->budget--) { s->failed_pc=0x0c098476u; return 0; }
r[6]=0x00000000u;
goto P_0c098478;
P_0c098478: /* original d23a, guest PC 0x0c098478 */
if(!s->budget--) { s->failed_pc=0x0c098478u; return 0; }
r[2]=read(ram,0x0c098564u,4);
goto P_0c09847a;
P_0c09847a: /* original ff8d, guest PC 0x0c09847a */
if(!s->budget--) { s->failed_pc=0x0c09847au; return 0; }
fr[15]=0;
goto P_0c09847c;
P_0c09847c: /* original 6563, guest PC 0x0c09847c */
if(!s->budget--) { s->failed_pc=0x0c09847cu; return 0; }
r[5]=r[6];
goto P_0c09847e;
P_0c09847e: /* original f5fc, guest PC 0x0c09847e */
if(!s->budget--) { s->failed_pc=0x0c09847eu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c098480;
P_0c098480: /* original f4fc, guest PC 0x0c098480 */
if(!s->budget--) { s->failed_pc=0x0c098480u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c098482;
P_0c098482: /* original 420b, guest PC 0x0c098482 */
if(!s->budget--) { s->failed_pc=0x0c098482u; return 0; }
target=r[2];
r[16]=code_base|0x0c098486u;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098486u) { target=s->pc; goto dispatch; }
goto P_0c098486;
P_0c098484: /* original 6463, guest PC 0x0c098484 */
if(!s->budget--) { s->failed_pc=0x0c098484u; return 0; }
r[4]=r[6];
goto P_0c098486;
P_0c098486: /* original d338, guest PC 0x0c098486 */
if(!s->budget--) { s->failed_pc=0x0c098486u; return 0; }
r[3]=read(ram,0x0c098568u,4);
goto P_0c098488;
P_0c098488: /* original 430b, guest PC 0x0c098488 */
if(!s->budget--) { s->failed_pc=0x0c098488u; return 0; }
target=r[3];
r[16]=code_base|0x0c09848cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09848cu) { target=s->pc; goto dispatch; }
goto P_0c09848c;
P_0c09848a: /* original 0009, guest PC 0x0c09848a */
if(!s->budget--) { s->failed_pc=0x0c09848au; return 0; }
goto P_0c09848c;
P_0c09848c: /* original bdd8, guest PC 0x0c09848c */
if(!s->budget--) { s->failed_pc=0x0c09848cu; return 0; }
target=code_base|0x0c098040u; r[16]=code_base|0x0c098490u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098490u) { target=s->pc; goto dispatch; }
goto P_0c098490;
P_0c09848e: /* original 0009, guest PC 0x0c09848e */
if(!s->budget--) { s->failed_pc=0x0c09848eu; return 0; }
goto P_0c098490;
P_0c098490: /* original 905c, guest PC 0x0c098490 */
if(!s->budget--) { s->failed_pc=0x0c098490u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09854cu,2);
goto P_0c098492;
P_0c098492: /* original e201, guest PC 0x0c098492 */
if(!s->budget--) { s->failed_pc=0x0c098492u; return 0; }
r[2]=0x00000001u;
goto P_0c098494;
P_0c098494: /* original 53e5, guest PC 0x0c098494 */
if(!s->budget--) { s->failed_pc=0x0c098494u; return 0; }
r[3]=read(ram,r[14]+20,4);
goto P_0c098496;
P_0c098496: /* original 0e36, guest PC 0x0c098496 */
if(!s->budget--) { s->failed_pc=0x0c098496u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c098498;
P_0c098498: /* original e01b, guest PC 0x0c098498 */
if(!s->budget--) { s->failed_pc=0x0c098498u; return 0; }
r[0]=0x0000001bu;
goto P_0c09849a;
P_0c09849a: /* original 1d23, guest PC 0x0c09849a */
if(!s->budget--) { s->failed_pc=0x0c09849au; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c09849c;
P_0c09849c: /* original e20d, guest PC 0x0c09849c */
if(!s->budget--) { s->failed_pc=0x0c09849cu; return 0; }
r[2]=0x0000000du;
goto P_0c09849e;
P_0c09849e: /* original 9356, guest PC 0x0c09849e */
if(!s->budget--) { s->failed_pc=0x0c09849eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09854eu,2);
goto P_0c0984a0;
P_0c0984a0: /* original 04ec, guest PC 0x0c0984a0 */
if(!s->budget--) { s->failed_pc=0x0c0984a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0984a2;
P_0c0984a2: /* original e01a, guest PC 0x0c0984a2 */
if(!s->budget--) { s->failed_pc=0x0c0984a2u; return 0; }
r[0]=0x0000001au;
goto P_0c0984a4;
P_0c0984a4: /* original 33ec, guest PC 0x0c0984a4 */
if(!s->budget--) { s->failed_pc=0x0c0984a4u; return 0; }
r[3]+=r[14];
goto P_0c0984a6;
P_0c0984a6: /* original 05ec, guest PC 0x0c0984a6 */
if(!s->budget--) { s->failed_pc=0x0c0984a6u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0984a8;
P_0c0984a8: /* original 644c, guest PC 0x0c0984a8 */
if(!s->budget--) { s->failed_pc=0x0c0984a8u; return 0; }
r[4]=r[4]&255u;
goto P_0c0984aa;
P_0c0984aa: /* original dc30, guest PC 0x0c0984aa */
if(!s->budget--) { s->failed_pc=0x0c0984aau; return 0; }
r[12]=read(ram,0x0c09856cu,4);
goto P_0c0984ac;
P_0c0984ac: /* original 343c, guest PC 0x0c0984ac */
if(!s->budget--) { s->failed_pc=0x0c0984acu; return 0; }
r[4]+=r[3];
goto P_0c0984ae;
P_0c0984ae: /* original 934f, guest PC 0x0c0984ae */
if(!s->budget--) { s->failed_pc=0x0c0984aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098550u,2);
goto P_0c0984b0;
P_0c0984b0: /* original 655c, guest PC 0x0c0984b0 */
if(!s->budget--) { s->failed_pc=0x0c0984b0u; return 0; }
r[5]=r[5]&255u;
goto P_0c0984b2;
P_0c0984b2: /* original 6440, guest PC 0x0c0984b2 */
if(!s->budget--) { s->failed_pc=0x0c0984b2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c0984b4;
P_0c0984b4: /* original 33ec, guest PC 0x0c0984b4 */
if(!s->budget--) { s->failed_pc=0x0c0984b4u; return 0; }
r[3]+=r[14];
goto P_0c0984b6;
P_0c0984b6: /* original 56c4, guest PC 0x0c0984b6 */
if(!s->budget--) { s->failed_pc=0x0c0984b6u; return 0; }
r[6]=read(ram,r[12]+16,4);
goto P_0c0984b8;
P_0c0984b8: /* original 353c, guest PC 0x0c0984b8 */
if(!s->budget--) { s->failed_pc=0x0c0984b8u; return 0; }
r[5]+=r[3];
goto P_0c0984ba;
P_0c0984ba: /* original 5bc5, guest PC 0x0c0984ba */
if(!s->budget--) { s->failed_pc=0x0c0984bau; return 0; }
r[11]=read(ram,r[12]+20,4);
goto P_0c0984bc;
P_0c0984bc: /* original 6550, guest PC 0x0c0984bc */
if(!s->budget--) { s->failed_pc=0x0c0984bcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c0984be;
P_0c0984be: /* original 644c, guest PC 0x0c0984be */
if(!s->budget--) { s->failed_pc=0x0c0984beu; return 0; }
r[4]=r[4]&255u;
goto P_0c0984c0;
P_0c0984c0: /* original 3423, guest PC 0x0c0984c0 */
if(!s->budget--) { s->failed_pc=0x0c0984c0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0984c2;
P_0c0984c2: /* original 6143, guest PC 0x0c0984c2 */
if(!s->budget--) { s->failed_pc=0x0c0984c2u; return 0; }
r[1]=r[4];
goto P_0c0984c4;
P_0c0984c4: /* original 655c, guest PC 0x0c0984c4 */
if(!s->budget--) { s->failed_pc=0x0c0984c4u; return 0; }
r[5]=r[5]&255u;
goto P_0c0984c6;
P_0c0984c6: /* original 8f02, guest PC 0x0c0984c6 */
if(!s->budget--) { s->failed_pc=0x0c0984c6u; return 0; }
cond=r[17]&1u;
r[7]=r[5];
if(!cond) { goto P_0c0984ce; }
goto P_0c0984ca;
P_0c0984c8: /* original 6753, guest PC 0x0c0984c8 */
if(!s->budget--) { s->failed_pc=0x0c0984c8u; return 0; }
r[7]=r[5];
goto P_0c0984ca;
P_0c0984ca: /* original 6143, guest PC 0x0c0984ca */
if(!s->budget--) { s->failed_pc=0x0c0984cau; return 0; }
r[1]=r[4];
goto P_0c0984cc;
P_0c0984cc: /* original 71f3, guest PC 0x0c0984cc */
if(!s->budget--) { s->failed_pc=0x0c0984ccu; return 0; }
r[1]+=0xfffffff3u;
goto P_0c0984ce;
P_0c0984ce: /* original e20d, guest PC 0x0c0984ce */
if(!s->budget--) { s->failed_pc=0x0c0984ceu; return 0; }
r[2]=0x0000000du;
goto P_0c0984d0;
P_0c0984d0: /* original 3523, guest PC 0x0c0984d0 */
if(!s->budget--) { s->failed_pc=0x0c0984d0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[2])!=0);
goto P_0c0984d2;
P_0c0984d2: /* original 8f02, guest PC 0x0c0984d2 */
if(!s->budget--) { s->failed_pc=0x0c0984d2u; return 0; }
cond=r[17]&1u;
r[0]=0x00000061u;
if(!cond) { goto P_0c0984da; }
goto P_0c0984d6;
P_0c0984d4: /* original e061, guest PC 0x0c0984d4 */
if(!s->budget--) { s->failed_pc=0x0c0984d4u; return 0; }
r[0]=0x00000061u;
goto P_0c0984d6;
P_0c0984d6: /* original 6753, guest PC 0x0c0984d6 */
if(!s->budget--) { s->failed_pc=0x0c0984d6u; return 0; }
r[7]=r[5];
goto P_0c0984d8;
P_0c0984d8: /* original 77f3, guest PC 0x0c0984d8 */
if(!s->budget--) { s->failed_pc=0x0c0984d8u; return 0; }
r[7]+=0xfffffff3u;
goto P_0c0984da;
P_0c0984da: /* original 0614, guest PC 0x0c0984da */
if(!s->budget--) { s->failed_pc=0x0c0984dau; return 0; }
write(ram,r[6]+r[0],r[1],1);
goto P_0c0984dc;
P_0c0984dc: /* original 0b74, guest PC 0x0c0984dc */
if(!s->budget--) { s->failed_pc=0x0c0984dcu; return 0; }
write(ram,r[11]+r[0],r[7],1);
goto P_0c0984de;
P_0c0984de: /* original e060, guest PC 0x0c0984de */
if(!s->budget--) { s->failed_pc=0x0c0984deu; return 0; }
r[0]=0x00000060u;
goto P_0c0984e0;
P_0c0984e0: /* original 0644, guest PC 0x0c0984e0 */
if(!s->budget--) { s->failed_pc=0x0c0984e0u; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c0984e2;
P_0c0984e2: /* original 0b54, guest PC 0x0c0984e2 */
if(!s->budget--) { s->failed_pc=0x0c0984e2u; return 0; }
write(ram,r[11]+r[0],r[5],1);
goto P_0c0984e4;
P_0c0984e4: /* original 9035, guest PC 0x0c0984e4 */
if(!s->budget--) { s->failed_pc=0x0c0984e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098552u,2);
goto P_0c0984e6;
P_0c0984e6: /* original 04ee, guest PC 0x0c0984e6 */
if(!s->budget--) { s->failed_pc=0x0c0984e6u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0984e8;
P_0c0984e8: /* original e061, guest PC 0x0c0984e8 */
if(!s->budget--) { s->failed_pc=0x0c0984e8u; return 0; }
r[0]=0x00000061u;
goto P_0c0984ea;
P_0c0984ea: /* original 004c, guest PC 0x0c0984ea */
if(!s->budget--) { s->failed_pc=0x0c0984eau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0984ec;
P_0c0984ec: /* original 600c, guest PC 0x0c0984ec */
if(!s->budget--) { s->failed_pc=0x0c0984ecu; return 0; }
r[0]=r[0]&255u;
goto P_0c0984ee;
P_0c0984ee: /* original 8808, guest PC 0x0c0984ee */
if(!s->budget--) { s->failed_pc=0x0c0984eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0984f0;
P_0c0984f0: /* original 8f01, guest PC 0x0c0984f0 */
if(!s->budget--) { s->failed_pc=0x0c0984f0u; return 0; }
cond=r[17]&1u;
r[5]=0x00000000u;
if(!cond) { goto P_0c0984f6; }
goto P_0c0984f4;
P_0c0984f2: /* original e500, guest PC 0x0c0984f2 */
if(!s->budget--) { s->failed_pc=0x0c0984f2u; return 0; }
r[5]=0x00000000u;
goto P_0c0984f4;
P_0c0984f4: /* original e505, guest PC 0x0c0984f4 */
if(!s->budget--) { s->failed_pc=0x0c0984f4u; return 0; }
r[5]=0x00000005u;
goto P_0c0984f6;
P_0c0984f6: /* original d31e, guest PC 0x0c0984f6 */
if(!s->budget--) { s->failed_pc=0x0c0984f6u; return 0; }
r[3]=read(ram,0x0c098570u,4);
goto P_0c0984f8;
P_0c0984f8: /* original 902c, guest PC 0x0c0984f8 */
if(!s->budget--) { s->failed_pc=0x0c0984f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098554u,2);
goto P_0c0984fa;
P_0c0984fa: /* original 430b, guest PC 0x0c0984fa */
if(!s->budget--) { s->failed_pc=0x0c0984fau; return 0; }
target=r[3];
r[16]=code_base|0x0c0984feu;
write(ram,r[4]+r[0],r[5],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0984feu) { target=s->pc; goto dispatch; }
goto P_0c0984fe;
P_0c0984fc: /* original 0454, guest PC 0x0c0984fc */
if(!s->budget--) { s->failed_pc=0x0c0984fcu; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0984fe;
P_0c0984fe: /* original e010, guest PC 0x0c0984fe */
if(!s->budget--) { s->failed_pc=0x0c0984feu; return 0; }
r[0]=0x00000010u;
goto P_0c098500;
P_0c098500: /* original e215, guest PC 0x0c098500 */
if(!s->budget--) { s->failed_pc=0x0c098500u; return 0; }
r[2]=0x00000015u;
goto P_0c098502;
P_0c098502: /* original 0d24, guest PC 0x0c098502 */
if(!s->budget--) { s->failed_pc=0x0c098502u; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c098504;
P_0c098504: /* original 9327, guest PC 0x0c098504 */
if(!s->budget--) { s->failed_pc=0x0c098504u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098556u,2);
goto P_0c098506;
P_0c098506: /* original 1d33, guest PC 0x0c098506 */
if(!s->budget--) { s->failed_pc=0x0c098506u; return 0; }
write(ram,r[13]+12,r[3],4);
goto P_0c098508;
P_0c098508: /* original 84db, guest PC 0x0c098508 */
if(!s->budget--) { s->failed_pc=0x0c098508u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+11,1);
goto P_0c09850a;
P_0c09850a: /* original 7001, guest PC 0x0c09850a */
if(!s->budget--) { s->failed_pc=0x0c09850au; return 0; }
r[0]+=0x00000001u;
goto P_0c09850c;
P_0c09850c: /* original 80db, guest PC 0x0c09850c */
if(!s->budget--) { s->failed_pc=0x0c09850cu; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c09850e;
P_0c09850e: /* original d319, guest PC 0x0c09850e */
if(!s->budget--) { s->failed_pc=0x0c09850eu; return 0; }
r[3]=read(ram,0x0c098574u,4);
goto P_0c098510;
P_0c098510: /* original 430b, guest PC 0x0c098510 */
if(!s->budget--) { s->failed_pc=0x0c098510u; return 0; }
target=r[3];
r[16]=code_base|0x0c098514u;
r[4]=read(ram,r[12]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098514u) { target=s->pc; goto dispatch; }
goto P_0c098514;
P_0c098512: /* original 54c8, guest PC 0x0c098512 */
if(!s->budget--) { s->failed_pc=0x0c098512u; return 0; }
r[4]=read(ram,r[12]+32,4);
goto P_0c098514;
P_0c098514: /* original d317, guest PC 0x0c098514 */
if(!s->budget--) { s->failed_pc=0x0c098514u; return 0; }
r[3]=read(ram,0x0c098574u,4);
goto P_0c098516;
P_0c098516: /* original e044, guest PC 0x0c098516 */
if(!s->budget--) { s->failed_pc=0x0c098516u; return 0; }
r[0]=0x00000044u;
goto P_0c098518;
P_0c098518: /* original 430b, guest PC 0x0c098518 */
if(!s->budget--) { s->failed_pc=0x0c098518u; return 0; }
target=r[3];
r[16]=code_base|0x0c09851cu;
r[4]=read(ram,r[12]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09851cu) { target=s->pc; goto dispatch; }
goto P_0c09851c;
P_0c09851a: /* original 04ce, guest PC 0x0c09851a */
if(!s->budget--) { s->failed_pc=0x0c09851au; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c09851c;
P_0c09851c: /* original d216, guest PC 0x0c09851c */
if(!s->budget--) { s->failed_pc=0x0c09851cu; return 0; }
r[2]=read(ram,0x0c098578u,4);
goto P_0c09851e;
P_0c09851e: /* original 420b, guest PC 0x0c09851e */
if(!s->budget--) { s->failed_pc=0x0c09851eu; return 0; }
target=r[2];
r[16]=code_base|0x0c098522u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098522u) { target=s->pc; goto dispatch; }
goto P_0c098522;
P_0c098520: /* original 0009, guest PC 0x0c098520 */
if(!s->budget--) { s->failed_pc=0x0c098520u; return 0; }
goto P_0c098522;
P_0c098522: /* original d316, guest PC 0x0c098522 */
if(!s->budget--) { s->failed_pc=0x0c098522u; return 0; }
r[3]=read(ram,0x0c09857cu,4);
goto P_0c098524;
P_0c098524: /* original e500, guest PC 0x0c098524 */
if(!s->budget--) { s->failed_pc=0x0c098524u; return 0; }
r[5]=0x00000000u;
goto P_0c098526;
P_0c098526: /* original f4fc, guest PC 0x0c098526 */
if(!s->budget--) { s->failed_pc=0x0c098526u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c098528;
P_0c098528: /* original f5fc, guest PC 0x0c098528 */
if(!s->budget--) { s->failed_pc=0x0c098528u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c09852a;
P_0c09852a: /* original f6fc, guest PC 0x0c09852a */
if(!s->budget--) { s->failed_pc=0x0c09852au; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c09852c;
P_0c09852c: /* original 430b, guest PC 0x0c09852c */
if(!s->budget--) { s->failed_pc=0x0c09852cu; return 0; }
target=r[3];
r[16]=code_base|0x0c098530u;
r[4]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098530u) { target=s->pc; goto dispatch; }
goto P_0c098530;
P_0c09852e: /* original 6453, guest PC 0x0c09852e */
if(!s->budget--) { s->failed_pc=0x0c09852eu; return 0; }
r[4]=r[5];
goto P_0c098530;
P_0c098530: /* original d212, guest PC 0x0c098530 */
if(!s->budget--) { s->failed_pc=0x0c098530u; return 0; }
r[2]=read(ram,0x0c09857cu,4);
goto P_0c098532;
P_0c098532: /* original e500, guest PC 0x0c098532 */
if(!s->budget--) { s->failed_pc=0x0c098532u; return 0; }
r[5]=0x00000000u;
goto P_0c098534;
P_0c098534: /* original f4fc, guest PC 0x0c098534 */
if(!s->budget--) { s->failed_pc=0x0c098534u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c098536;
P_0c098536: /* original f5fc, guest PC 0x0c098536 */
if(!s->budget--) { s->failed_pc=0x0c098536u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c098538;
P_0c098538: /* original f6fc, guest PC 0x0c098538 */
if(!s->budget--) { s->failed_pc=0x0c098538u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c09853a;
P_0c09853a: /* original 420b, guest PC 0x0c09853a */
if(!s->budget--) { s->failed_pc=0x0c09853au; return 0; }
target=r[2];
r[16]=code_base|0x0c09853eu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09853eu) { target=s->pc; goto dispatch; }
goto P_0c09853e;
P_0c09853c: /* original e401, guest PC 0x0c09853c */
if(!s->budget--) { s->failed_pc=0x0c09853cu; return 0; }
r[4]=0x00000001u;
goto P_0c09853e;
P_0c09853e: /* original 4f26, guest PC 0x0c09853e */
if(!s->budget--) { s->failed_pc=0x0c09853eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c098540;
P_0c098540: /* original fff9, guest PC 0x0c098540 */
if(!s->budget--) { s->failed_pc=0x0c098540u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c098542;
P_0c098542: /* original 6bf6, guest PC 0x0c098542 */
if(!s->budget--) { s->failed_pc=0x0c098542u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c098544;
P_0c098544: /* original 6cf6, guest PC 0x0c098544 */
if(!s->budget--) { s->failed_pc=0x0c098544u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c098546;
P_0c098546: /* original 6df6, guest PC 0x0c098546 */
if(!s->budget--) { s->failed_pc=0x0c098546u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c098548;
P_0c098548: /* original ad54, guest PC 0x0c098548 */
if(!s->budget--) { s->failed_pc=0x0c098548u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c097ff4;
P_0c09854a: /* original 6ef6, guest PC 0x0c09854a */
if(!s->budget--) { s->failed_pc=0x0c09854au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09854cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09854cu; return 0; } return 1;
P_0c09877c: /* original 2fe6, guest PC 0x0c09877c */
if(!s->budget--) { s->failed_pc=0x0c09877cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09877e;
P_0c09877e: /* original 2fd6, guest PC 0x0c09877e */
if(!s->budget--) { s->failed_pc=0x0c09877eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098780;
P_0c098780: /* original 2fc6, guest PC 0x0c098780 */
if(!s->budget--) { s->failed_pc=0x0c098780u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098782;
P_0c098782: /* original 2fb6, guest PC 0x0c098782 */
if(!s->budget--) { s->failed_pc=0x0c098782u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098784;
P_0c098784: /* original 2fa6, guest PC 0x0c098784 */
if(!s->budget--) { s->failed_pc=0x0c098784u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098786;
P_0c098786: /* original fffb, guest PC 0x0c098786 */
if(!s->budget--) { s->failed_pc=0x0c098786u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c098788;
P_0c098788: /* original 4f22, guest PC 0x0c098788 */
if(!s->budget--) { s->failed_pc=0x0c098788u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09878a;
P_0c09878a: /* original da35, guest PC 0x0c09878a */
if(!s->budget--) { s->failed_pc=0x0c09878au; return 0; }
r[10]=read(ram,0x0c098860u,4);
goto P_0c09878c;
P_0c09878c: /* original d335, guest PC 0x0c09878c */
if(!s->budget--) { s->failed_pc=0x0c09878cu; return 0; }
r[3]=read(ram,0x0c098864u,4);
goto P_0c09878e;
P_0c09878e: /* original dd32, guest PC 0x0c09878e */
if(!s->budget--) { s->failed_pc=0x0c09878eu; return 0; }
r[13]=read(ram,0x0c098858u,4);
goto P_0c098790;
P_0c098790: /* original dc32, guest PC 0x0c098790 */
if(!s->budget--) { s->failed_pc=0x0c098790u; return 0; }
r[12]=read(ram,0x0c09885cu,4);
goto P_0c098792;
P_0c098792: /* original 430b, guest PC 0x0c098792 */
if(!s->budget--) { s->failed_pc=0x0c098792u; return 0; }
target=r[3];
r[16]=code_base|0x0c098796u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098796u) { target=s->pc; goto dispatch; }
goto P_0c098796;
P_0c098794: /* original 0009, guest PC 0x0c098794 */
if(!s->budget--) { s->failed_pc=0x0c098794u; return 0; }
goto P_0c098796;
P_0c098796: /* original d234, guest PC 0x0c098796 */
if(!s->budget--) { s->failed_pc=0x0c098796u; return 0; }
r[2]=read(ram,0x0c098868u,4);
goto P_0c098798;
P_0c098798: /* original 420b, guest PC 0x0c098798 */
if(!s->budget--) { s->failed_pc=0x0c098798u; return 0; }
target=r[2];
r[16]=code_base|0x0c09879cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09879cu) { target=s->pc; goto dispatch; }
goto P_0c09879c;
P_0c09879a: /* original 0009, guest PC 0x0c09879a */
if(!s->budget--) { s->failed_pc=0x0c09879au; return 0; }
goto P_0c09879c;
P_0c09879c: /* original c733, guest PC 0x0c09879c */
if(!s->budget--) { s->failed_pc=0x0c09879cu; return 0; }
r[0]=code_base|0x0009886cu;
goto P_0c09879e;
P_0c09879e: /* original f308, guest PC 0x0c09879e */
if(!s->budget--) { s->failed_pc=0x0c09879eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0987a0;
P_0c0987a0: /* original e057, guest PC 0x0c0987a0 */
if(!s->budget--) { s->failed_pc=0x0c0987a0u; return 0; }
r[0]=0x00000057u;
goto P_0c0987a2;
P_0c0987a2: /* original eb00, guest PC 0x0c0987a2 */
if(!s->budget--) { s->failed_pc=0x0c0987a2u; return 0; }
r[11]=0x00000000u;
goto P_0c0987a4;
P_0c0987a4: /* original fd3a, guest PC 0x0c0987a4 */
if(!s->budget--) { s->failed_pc=0x0c0987a4u; return 0; }
vf3_matrix_store(s,ram,3,r[13]);
goto P_0c0987a6;
P_0c0987a6: /* original de32, guest PC 0x0c0987a6 */
if(!s->budget--) { s->failed_pc=0x0c0987a6u; return 0; }
r[14]=read(ram,0x0c098870u,4);
goto P_0c0987a8;
P_0c0987a8: /* original 53ea, guest PC 0x0c0987a8 */
if(!s->budget--) { s->failed_pc=0x0c0987a8u; return 0; }
r[3]=read(ram,r[14]+40,4);
goto P_0c0987aa;
P_0c0987aa: /* original 03b4, guest PC 0x0c0987aa */
if(!s->budget--) { s->failed_pc=0x0c0987aau; return 0; }
write(ram,r[3]+r[0],r[11],1);
goto P_0c0987ac;
P_0c0987ac: /* original 53eb, guest PC 0x0c0987ac */
if(!s->budget--) { s->failed_pc=0x0c0987acu; return 0; }
r[3]=read(ram,r[14]+44,4);
goto P_0c0987ae;
P_0c0987ae: /* original 03b4, guest PC 0x0c0987ae */
if(!s->budget--) { s->failed_pc=0x0c0987aeu; return 0; }
write(ram,r[3]+r[0],r[11],1);
goto P_0c0987b0;
P_0c0987b0: /* original 7049, guest PC 0x0c0987b0 */
if(!s->budget--) { s->failed_pc=0x0c0987b0u; return 0; }
r[0]+=0x00000049u;
goto P_0c0987b2;
P_0c0987b2: /* original 0cb6, guest PC 0x0c0987b2 */
if(!s->budget--) { s->failed_pc=0x0c0987b2u; return 0; }
write(ram,r[12]+r[0],r[11],4);
goto P_0c0987b4;
P_0c0987b4: /* original 904a, guest PC 0x0c0987b4 */
if(!s->budget--) { s->failed_pc=0x0c0987b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09884cu,2);
goto P_0c0987b6;
P_0c0987b6: /* original 0cb6, guest PC 0x0c0987b6 */
if(!s->budget--) { s->failed_pc=0x0c0987b6u; return 0; }
write(ram,r[12]+r[0],r[11],4);
goto P_0c0987b8;
P_0c0987b8: /* original 9349, guest PC 0x0c0987b8 */
if(!s->budget--) { s->failed_pc=0x0c0987b8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09884eu,2);
goto P_0c0987ba;
P_0c0987ba: /* original 52d2, guest PC 0x0c0987ba */
if(!s->budget--) { s->failed_pc=0x0c0987bau; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0987bc;
P_0c0987bc: /* original 2239, guest PC 0x0c0987bc */
if(!s->budget--) { s->failed_pc=0x0c0987bcu; return 0; }
r[2]&=r[3];
goto P_0c0987be;
P_0c0987be: /* original 1d22, guest PC 0x0c0987be */
if(!s->budget--) { s->failed_pc=0x0c0987beu; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c0987c0;
P_0c0987c0: /* original d42c, guest PC 0x0c0987c0 */
if(!s->budget--) { s->failed_pc=0x0c0987c0u; return 0; }
r[4]=read(ram,0x0c098874u,4);
goto P_0c0987c2;
P_0c0987c2: /* original d12d, guest PC 0x0c0987c2 */
if(!s->budget--) { s->failed_pc=0x0c0987c2u; return 0; }
r[1]=read(ram,0x0c098878u,4);
goto P_0c0987c4;
P_0c0987c4: /* original 410b, guest PC 0x0c0987c4 */
if(!s->budget--) { s->failed_pc=0x0c0987c4u; return 0; }
target=r[1];
r[16]=code_base|0x0c0987c8u;
r[5]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0987c8u) { target=s->pc; goto dispatch; }
goto P_0c0987c8;
P_0c0987c6: /* original 65b3, guest PC 0x0c0987c6 */
if(!s->budget--) { s->failed_pc=0x0c0987c6u; return 0; }
r[5]=r[11];
goto P_0c0987c8;
P_0c0987c8: /* original d32c, guest PC 0x0c0987c8 */
if(!s->budget--) { s->failed_pc=0x0c0987c8u; return 0; }
r[3]=read(ram,0x0c09887cu,4);
goto P_0c0987ca;
P_0c0987ca: /* original 430b, guest PC 0x0c0987ca */
if(!s->budget--) { s->failed_pc=0x0c0987cau; return 0; }
target=r[3];
r[16]=code_base|0x0c0987ceu;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0987ceu) { target=s->pc; goto dispatch; }
goto P_0c0987ce;
P_0c0987cc: /* original 54e4, guest PC 0x0c0987cc */
if(!s->budget--) { s->failed_pc=0x0c0987ccu; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c0987ce;
P_0c0987ce: /* original d22b, guest PC 0x0c0987ce */
if(!s->budget--) { s->failed_pc=0x0c0987ceu; return 0; }
r[2]=read(ram,0x0c09887cu,4);
goto P_0c0987d0;
P_0c0987d0: /* original 420b, guest PC 0x0c0987d0 */
if(!s->budget--) { s->failed_pc=0x0c0987d0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0987d4u;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0987d4u) { target=s->pc; goto dispatch; }
goto P_0c0987d4;
P_0c0987d2: /* original 54e5, guest PC 0x0c0987d2 */
if(!s->budget--) { s->failed_pc=0x0c0987d2u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c0987d4;
P_0c0987d4: /* original d32b, guest PC 0x0c0987d4 */
if(!s->budget--) { s->failed_pc=0x0c0987d4u; return 0; }
r[3]=read(ram,0x0c098884u,4);
goto P_0c0987d6;
P_0c0987d6: /* original d52a, guest PC 0x0c0987d6 */
if(!s->budget--) { s->failed_pc=0x0c0987d6u; return 0; }
r[5]=read(ram,0x0c098880u,4);
goto P_0c0987d8;
P_0c0987d8: /* original 430b, guest PC 0x0c0987d8 */
if(!s->budget--) { s->failed_pc=0x0c0987d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0987dcu;
r[4]=read(ram,r[14]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0987dcu) { target=s->pc; goto dispatch; }
goto P_0c0987dc;
P_0c0987da: /* original 54e6, guest PC 0x0c0987da */
if(!s->budget--) { s->failed_pc=0x0c0987dau; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c0987dc;
P_0c0987dc: /* original d229, guest PC 0x0c0987dc */
if(!s->budget--) { s->failed_pc=0x0c0987dcu; return 0; }
r[2]=read(ram,0x0c098884u,4);
goto P_0c0987de;
P_0c0987de: /* original d52a, guest PC 0x0c0987de */
if(!s->budget--) { s->failed_pc=0x0c0987deu; return 0; }
r[5]=read(ram,0x0c098888u,4);
goto P_0c0987e0;
P_0c0987e0: /* original 420b, guest PC 0x0c0987e0 */
if(!s->budget--) { s->failed_pc=0x0c0987e0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0987e4u;
r[4]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0987e4u) { target=s->pc; goto dispatch; }
goto P_0c0987e4;
P_0c0987e2: /* original 54e7, guest PC 0x0c0987e2 */
if(!s->budget--) { s->failed_pc=0x0c0987e2u; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c0987e4;
P_0c0987e4: /* original d327, guest PC 0x0c0987e4 */
if(!s->budget--) { s->failed_pc=0x0c0987e4u; return 0; }
r[3]=read(ram,0x0c098884u,4);
goto P_0c0987e6;
P_0c0987e6: /* original d529, guest PC 0x0c0987e6 */
if(!s->budget--) { s->failed_pc=0x0c0987e6u; return 0; }
r[5]=read(ram,0x0c09888cu,4);
goto P_0c0987e8;
P_0c0987e8: /* original 430b, guest PC 0x0c0987e8 */
if(!s->budget--) { s->failed_pc=0x0c0987e8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0987ecu;
r[4]=read(ram,r[14]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0987ecu) { target=s->pc; goto dispatch; }
goto P_0c0987ec;
P_0c0987ea: /* original 54ed, guest PC 0x0c0987ea */
if(!s->budget--) { s->failed_pc=0x0c0987eau; return 0; }
r[4]=read(ram,r[14]+52,4);
goto P_0c0987ec;
P_0c0987ec: /* original d225, guest PC 0x0c0987ec */
if(!s->budget--) { s->failed_pc=0x0c0987ecu; return 0; }
r[2]=read(ram,0x0c098884u,4);
goto P_0c0987ee;
P_0c0987ee: /* original d528, guest PC 0x0c0987ee */
if(!s->budget--) { s->failed_pc=0x0c0987eeu; return 0; }
r[5]=read(ram,0x0c098890u,4);
goto P_0c0987f0;
P_0c0987f0: /* original 420b, guest PC 0x0c0987f0 */
if(!s->budget--) { s->failed_pc=0x0c0987f0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0987f4u;
r[4]=read(ram,r[14]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0987f4u) { target=s->pc; goto dispatch; }
goto P_0c0987f4;
P_0c0987f2: /* original 54ee, guest PC 0x0c0987f2 */
if(!s->budget--) { s->failed_pc=0x0c0987f2u; return 0; }
r[4]=read(ram,r[14]+56,4);
goto P_0c0987f4;
P_0c0987f4: /* original 902c, guest PC 0x0c0987f4 */
if(!s->budget--) { s->failed_pc=0x0c0987f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098850u,2);
goto P_0c0987f6;
P_0c0987f6: /* original d327, guest PC 0x0c0987f6 */
if(!s->budget--) { s->failed_pc=0x0c0987f6u; return 0; }
r[3]=read(ram,0x0c098894u,4);
goto P_0c0987f8;
P_0c0987f8: /* original 54ec, guest PC 0x0c0987f8 */
if(!s->budget--) { s->failed_pc=0x0c0987f8u; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c0987fa;
P_0c0987fa: /* original 0436, guest PC 0x0c0987fa */
if(!s->budget--) { s->failed_pc=0x0c0987fau; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c0987fc;
P_0c0987fc: /* original 7098, guest PC 0x0c0987fc */
if(!s->budget--) { s->failed_pc=0x0c0987fcu; return 0; }
r[0]+=0xffffff98u;
goto P_0c0987fe;
P_0c0987fe: /* original 0cb4, guest PC 0x0c0987fe */
if(!s->budget--) { s->failed_pc=0x0c0987feu; return 0; }
write(ram,r[12]+r[0],r[11],1);
goto P_0c098800;
P_0c098800: /* original 9027, guest PC 0x0c098800 */
if(!s->budget--) { s->failed_pc=0x0c098800u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098852u,2);
goto P_0c098802;
P_0c098802: /* original 0db4, guest PC 0x0c098802 */
if(!s->budget--) { s->failed_pc=0x0c098802u; return 0; }
write(ram,r[13]+r[0],r[11],1);
goto P_0c098804;
P_0c098804: /* original c725, guest PC 0x0c098804 */
if(!s->budget--) { s->failed_pc=0x0c098804u; return 0; }
r[0]=code_base|0x0009889cu;
goto P_0c098806;
P_0c098806: /* original f408, guest PC 0x0c098806 */
if(!s->budget--) { s->failed_pc=0x0c098806u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c098808;
P_0c098808: /* original d325, guest PC 0x0c098808 */
if(!s->budget--) { s->failed_pc=0x0c098808u; return 0; }
r[3]=read(ram,0x0c0988a0u,4);
goto P_0c09880a;
P_0c09880a: /* original ff8d, guest PC 0x0c09880a */
if(!s->budget--) { s->failed_pc=0x0c09880au; return 0; }
fr[15]=0;
goto P_0c09880c;
P_0c09880c: /* original d522, guest PC 0x0c09880c */
if(!s->budget--) { s->failed_pc=0x0c09880cu; return 0; }
r[5]=read(ram,0x0c098898u,4);
goto P_0c09880e;
P_0c09880e: /* original f6fc, guest PC 0x0c09880e */
if(!s->budget--) { s->failed_pc=0x0c09880eu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c098810;
P_0c098810: /* original f5fc, guest PC 0x0c098810 */
if(!s->budget--) { s->failed_pc=0x0c098810u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c098812;
P_0c098812: /* original 430b, guest PC 0x0c098812 */
if(!s->budget--) { s->failed_pc=0x0c098812u; return 0; }
target=r[3];
r[16]=code_base|0x0c098816u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098816u) { target=s->pc; goto dispatch; }
goto P_0c098816;
P_0c098814: /* original 64b3, guest PC 0x0c098814 */
if(!s->budget--) { s->failed_pc=0x0c098814u; return 0; }
r[4]=r[11];
goto P_0c098816;
P_0c098816: /* original d222, guest PC 0x0c098816 */
if(!s->budget--) { s->failed_pc=0x0c098816u; return 0; }
r[2]=read(ram,0x0c0988a0u,4);
goto P_0c098818;
P_0c098818: /* original 951c, guest PC 0x0c098818 */
if(!s->budget--) { s->failed_pc=0x0c098818u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098854u,2);
goto P_0c09881a;
P_0c09881a: /* original f49d, guest PC 0x0c09881a */
if(!s->budget--) { s->failed_pc=0x0c09881au; return 0; }
fr[4]=0x3f800000u;
goto P_0c09881c;
P_0c09881c: /* original f6fc, guest PC 0x0c09881c */
if(!s->budget--) { s->failed_pc=0x0c09881cu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c09881e;
P_0c09881e: /* original f5fc, guest PC 0x0c09881e */
if(!s->budget--) { s->failed_pc=0x0c09881eu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c098820;
P_0c098820: /* original 420b, guest PC 0x0c098820 */
if(!s->budget--) { s->failed_pc=0x0c098820u; return 0; }
target=r[2];
r[16]=code_base|0x0c098824u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098824u) { target=s->pc; goto dispatch; }
goto P_0c098824;
P_0c098822: /* original e401, guest PC 0x0c098822 */
if(!s->budget--) { s->failed_pc=0x0c098822u; return 0; }
r[4]=0x00000001u;
goto P_0c098824;
P_0c098824: /* original 9017, guest PC 0x0c098824 */
if(!s->budget--) { s->failed_pc=0x0c098824u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098856u,2);
goto P_0c098826;
P_0c098826: /* original e319, guest PC 0x0c098826 */
if(!s->budget--) { s->failed_pc=0x0c098826u; return 0; }
r[3]=0x00000019u;
goto P_0c098828;
P_0c098828: /* original 54e8, guest PC 0x0c098828 */
if(!s->budget--) { s->failed_pc=0x0c098828u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c09882a;
P_0c09882a: /* original 04b4, guest PC 0x0c09882a */
if(!s->budget--) { s->failed_pc=0x0c09882au; return 0; }
write(ram,r[4]+r[0],r[11],1);
goto P_0c09882c;
P_0c09882c: /* original e010, guest PC 0x0c09882c */
if(!s->budget--) { s->failed_pc=0x0c09882cu; return 0; }
r[0]=0x00000010u;
goto P_0c09882e;
P_0c09882e: /* original 0c34, guest PC 0x0c09882e */
if(!s->budget--) { s->failed_pc=0x0c09882eu; return 0; }
write(ram,r[12]+r[0],r[3],1);
goto P_0c098830;
P_0c098830: /* original d31c, guest PC 0x0c098830 */
if(!s->budget--) { s->failed_pc=0x0c098830u; return 0; }
r[3]=read(ram,0x0c0988a4u,4);
goto P_0c098832;
P_0c098832: /* original 430b, guest PC 0x0c098832 */
if(!s->budget--) { s->failed_pc=0x0c098832u; return 0; }
target=r[3];
r[16]=code_base|0x0c098836u;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098836u) { target=s->pc; goto dispatch; }
goto P_0c098836;
P_0c098834: /* original 54e4, guest PC 0x0c098834 */
if(!s->budget--) { s->failed_pc=0x0c098834u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c098836;
P_0c098836: /* original d21b, guest PC 0x0c098836 */
if(!s->budget--) { s->failed_pc=0x0c098836u; return 0; }
r[2]=read(ram,0x0c0988a4u,4);
goto P_0c098838;
P_0c098838: /* original 420b, guest PC 0x0c098838 */
if(!s->budget--) { s->failed_pc=0x0c098838u; return 0; }
target=r[2];
r[16]=code_base|0x0c09883cu;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09883cu) { target=s->pc; goto dispatch; }
goto P_0c09883c;
P_0c09883a: /* original 54e5, guest PC 0x0c09883a */
if(!s->budget--) { s->failed_pc=0x0c09883au; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c09883c;
P_0c09883c: /* original 52d2, guest PC 0x0c09883c */
if(!s->budget--) { s->failed_pc=0x0c09883cu; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c09883e;
P_0c09883e: /* original d31b, guest PC 0x0c09883e */
if(!s->budget--) { s->failed_pc=0x0c09883eu; return 0; }
r[3]=read(ram,0x0c0988acu,4);
goto P_0c098840;
P_0c098840: /* original de19, guest PC 0x0c098840 */
if(!s->budget--) { s->failed_pc=0x0c098840u; return 0; }
r[14]=read(ram,0x0c0988a8u,4);
goto P_0c098842;
P_0c098842: /* original 2238, guest PC 0x0c098842 */
if(!s->budget--) { s->failed_pc=0x0c098842u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c098844;
P_0c098844: /* original 8d34, guest PC 0x0c098844 */
if(!s->budget--) { s->failed_pc=0x0c098844u; return 0; }
cond=r[17]&1u;
r[11]=0x0000002fu;
if(cond) { goto P_0c0988b0; }
goto P_0c098848;
P_0c098846: /* original eb2f, guest PC 0x0c098846 */
if(!s->budget--) { s->failed_pc=0x0c098846u; return 0; }
r[11]=0x0000002fu;
goto P_0c098848;
P_0c098848: /* original a03a, guest PC 0x0c098848 */
if(!s->budget--) { s->failed_pc=0x0c098848u; return 0; }
r[4]=read(ram,r[14]+12,4);
goto P_0c0988c0;
P_0c09884a: /* original 54e3, guest PC 0x0c09884a */
if(!s->budget--) { s->failed_pc=0x0c09884au; return 0; }
r[4]=read(ram,r[14]+12,4);
if(!vf3_matrix_family(0x0c09884cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09884cu; return 0; } return 1;
P_0c0988b0: /* original d145, guest PC 0x0c0988b0 */
if(!s->budget--) { s->failed_pc=0x0c0988b0u; return 0; }
r[1]=read(ram,0x0c0989c8u,4);
goto P_0c0988b2;
P_0c0988b2: /* original 64a3, guest PC 0x0c0988b2 */
if(!s->budget--) { s->failed_pc=0x0c0988b2u; return 0; }
r[4]=r[10];
goto P_0c0988b4;
P_0c0988b4: /* original 410b, guest PC 0x0c0988b4 */
if(!s->budget--) { s->failed_pc=0x0c0988b4u; return 0; }
target=r[1];
r[16]=code_base|0x0c0988b8u;
r[4]+=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0988b8u) { target=s->pc; goto dispatch; }
goto P_0c0988b8;
P_0c0988b6: /* original 740a, guest PC 0x0c0988b6 */
if(!s->budget--) { s->failed_pc=0x0c0988b6u; return 0; }
r[4]+=0x0000000au;
goto P_0c0988b8;
P_0c0988b8: /* original 600d, guest PC 0x0c0988b8 */
if(!s->budget--) { s->failed_pc=0x0c0988b8u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0988ba;
P_0c0988ba: /* original 4008, guest PC 0x0c0988ba */
if(!s->budget--) { s->failed_pc=0x0c0988bau; return 0; }
r[0]<<=2;
goto P_0c0988bc;
P_0c0988bc: /* original 03ee, guest PC 0x0c0988bc */
if(!s->budget--) { s->failed_pc=0x0c0988bcu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0988be;
P_0c0988be: /* original 6433, guest PC 0x0c0988be */
if(!s->budget--) { s->failed_pc=0x0c0988beu; return 0; }
r[4]=r[3];
goto P_0c0988c0;
P_0c0988c0: /* original 5ed2, guest PC 0x0c0988c0 */
if(!s->budget--) { s->failed_pc=0x0c0988c0u; return 0; }
r[14]=read(ram,r[13]+8,4);
goto P_0c0988c2;
P_0c0988c2: /* original 4408, guest PC 0x0c0988c2 */
if(!s->budget--) { s->failed_pc=0x0c0988c2u; return 0; }
r[4]<<=2;
goto P_0c0988c4;
P_0c0988c4: /* original d241, guest PC 0x0c0988c4 */
if(!s->budget--) { s->failed_pc=0x0c0988c4u; return 0; }
r[2]=read(ram,0x0c0989ccu,4);
goto P_0c0988c6;
P_0c0988c6: /* original 4408, guest PC 0x0c0988c6 */
if(!s->budget--) { s->failed_pc=0x0c0988c6u; return 0; }
r[4]<<=2;
goto P_0c0988c8;
P_0c0988c8: /* original 22e8, guest PC 0x0c0988c8 */
if(!s->budget--) { s->failed_pc=0x0c0988c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c0988ca;
P_0c0988ca: /* original 8d0e, guest PC 0x0c0988ca */
if(!s->budget--) { s->failed_pc=0x0c0988cau; return 0; }
cond=r[17]&1u;
r[4]<<=2;
if(cond) { goto P_0c0988ea; }
goto P_0c0988ce;
P_0c0988cc: /* original 4408, guest PC 0x0c0988cc */
if(!s->budget--) { s->failed_pc=0x0c0988ccu; return 0; }
r[4]<<=2;
goto P_0c0988ce;
P_0c0988ce: /* original d33e, guest PC 0x0c0988ce */
if(!s->budget--) { s->failed_pc=0x0c0988ceu; return 0; }
r[3]=read(ram,0x0c0989c8u,4);
goto P_0c0988d0;
P_0c0988d0: /* original 64a3, guest PC 0x0c0988d0 */
if(!s->budget--) { s->failed_pc=0x0c0988d0u; return 0; }
r[4]=r[10];
goto P_0c0988d2;
P_0c0988d2: /* original eb36, guest PC 0x0c0988d2 */
if(!s->budget--) { s->failed_pc=0x0c0988d2u; return 0; }
r[11]=0x00000036u;
goto P_0c0988d4;
P_0c0988d4: /* original 430b, guest PC 0x0c0988d4 */
if(!s->budget--) { s->failed_pc=0x0c0988d4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0988d8u;
r[4]+=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0988d8u) { target=s->pc; goto dispatch; }
goto P_0c0988d8;
P_0c0988d6: /* original 740a, guest PC 0x0c0988d6 */
if(!s->budget--) { s->failed_pc=0x0c0988d6u; return 0; }
r[4]+=0x0000000au;
goto P_0c0988d8;
P_0c0988d8: /* original d13d, guest PC 0x0c0988d8 */
if(!s->budget--) { s->failed_pc=0x0c0988d8u; return 0; }
r[1]=read(ram,0x0c0989d0u,4);
goto P_0c0988da;
P_0c0988da: /* original 600d, guest PC 0x0c0988da */
if(!s->budget--) { s->failed_pc=0x0c0988dau; return 0; }
r[0]=r[0]&65535u;
goto P_0c0988dc;
P_0c0988dc: /* original 4008, guest PC 0x0c0988dc */
if(!s->budget--) { s->failed_pc=0x0c0988dcu; return 0; }
r[0]<<=2;
goto P_0c0988de;
P_0c0988de: /* original 021e, guest PC 0x0c0988de */
if(!s->budget--) { s->failed_pc=0x0c0988deu; return 0; }
r[2]=read(ram,r[1]+r[0],4);
goto P_0c0988e0;
P_0c0988e0: /* original 4221, guest PC 0x0c0988e0 */
if(!s->budget--) { s->failed_pc=0x0c0988e0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]=(uint32_t)((int32_t)r[2]>>1);
goto P_0c0988e2;
P_0c0988e2: /* original 6423, guest PC 0x0c0988e2 */
if(!s->budget--) { s->failed_pc=0x0c0988e2u; return 0; }
r[4]=r[2];
goto P_0c0988e4;
P_0c0988e4: /* original 4408, guest PC 0x0c0988e4 */
if(!s->budget--) { s->failed_pc=0x0c0988e4u; return 0; }
r[4]<<=2;
goto P_0c0988e6;
P_0c0988e6: /* original 4408, guest PC 0x0c0988e6 */
if(!s->budget--) { s->failed_pc=0x0c0988e6u; return 0; }
r[4]<<=2;
goto P_0c0988e8;
P_0c0988e8: /* original 4408, guest PC 0x0c0988e8 */
if(!s->budget--) { s->failed_pc=0x0c0988e8u; return 0; }
r[4]<<=2;
goto P_0c0988ea;
P_0c0988ea: /* original e340, guest PC 0x0c0988ea */
if(!s->budget--) { s->failed_pc=0x0c0988eau; return 0; }
r[3]=0x00000040u;
goto P_0c0988ec;
P_0c0988ec: /* original 1d45, guest PC 0x0c0988ec */
if(!s->budget--) { s->failed_pc=0x0c0988ecu; return 0; }
write(ram,r[13]+20,r[4],4);
goto P_0c0988ee;
P_0c0988ee: /* original 1c33, guest PC 0x0c0988ee */
if(!s->budget--) { s->failed_pc=0x0c0988eeu; return 0; }
write(ram,r[12]+12,r[3],4);
goto P_0c0988f0;
P_0c0988f0: /* original d238, guest PC 0x0c0988f0 */
if(!s->budget--) { s->failed_pc=0x0c0988f0u; return 0; }
r[2]=read(ram,0x0c0989d4u,4);
goto P_0c0988f2;
P_0c0988f2: /* original 2e29, guest PC 0x0c0988f2 */
if(!s->budget--) { s->failed_pc=0x0c0988f2u; return 0; }
r[14]&=r[2];
goto P_0c0988f4;
P_0c0988f4: /* original 1de2, guest PC 0x0c0988f4 */
if(!s->budget--) { s->failed_pc=0x0c0988f4u; return 0; }
write(ram,r[13]+8,r[14],4);
goto P_0c0988f6;
P_0c0988f6: /* original d338, guest PC 0x0c0988f6 */
if(!s->budget--) { s->failed_pc=0x0c0988f6u; return 0; }
r[3]=read(ram,0x0c0989d8u,4);
goto P_0c0988f8;
P_0c0988f8: /* original 430b, guest PC 0x0c0988f8 */
if(!s->budget--) { s->failed_pc=0x0c0988f8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0988fcu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0988fcu) { target=s->pc; goto dispatch; }
goto P_0c0988fc;
P_0c0988fa: /* original 64b3, guest PC 0x0c0988fa */
if(!s->budget--) { s->failed_pc=0x0c0988fau; return 0; }
r[4]=r[11];
goto P_0c0988fc;
P_0c0988fc: /* original d237, guest PC 0x0c0988fc */
if(!s->budget--) { s->failed_pc=0x0c0988fcu; return 0; }
r[2]=read(ram,0x0c0989dcu,4);
goto P_0c0988fe;
P_0c0988fe: /* original 420b, guest PC 0x0c0988fe */
if(!s->budget--) { s->failed_pc=0x0c0988feu; return 0; }
target=r[2];
r[16]=code_base|0x0c098902u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098902u) { target=s->pc; goto dispatch; }
goto P_0c098902;
P_0c098900: /* original 0009, guest PC 0x0c098900 */
if(!s->budget--) { s->failed_pc=0x0c098900u; return 0; }
goto P_0c098902;
P_0c098902: /* original 4f26, guest PC 0x0c098902 */
if(!s->budget--) { s->failed_pc=0x0c098902u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c098904;
P_0c098904: /* original 84cb, guest PC 0x0c098904 */
if(!s->budget--) { s->failed_pc=0x0c098904u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+11,1);
goto P_0c098906;
P_0c098906: /* original 7001, guest PC 0x0c098906 */
if(!s->budget--) { s->failed_pc=0x0c098906u; return 0; }
r[0]+=0x00000001u;
goto P_0c098908;
P_0c098908: /* original 80cb, guest PC 0x0c098908 */
if(!s->budget--) { s->failed_pc=0x0c098908u; return 0; }
write(ram,r[12]+11,r[0],1);
goto P_0c09890a;
P_0c09890a: /* original fff9, guest PC 0x0c09890a */
if(!s->budget--) { s->failed_pc=0x0c09890au; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09890c;
P_0c09890c: /* original 6af6, guest PC 0x0c09890c */
if(!s->budget--) { s->failed_pc=0x0c09890cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09890e;
P_0c09890e: /* original 6bf6, guest PC 0x0c09890e */
if(!s->budget--) { s->failed_pc=0x0c09890eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c098910;
P_0c098910: /* original 6cf6, guest PC 0x0c098910 */
if(!s->budget--) { s->failed_pc=0x0c098910u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c098912;
P_0c098912: /* original 6df6, guest PC 0x0c098912 */
if(!s->budget--) { s->failed_pc=0x0c098912u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c098914;
P_0c098914: /* original a000, guest PC 0x0c098914 */
if(!s->budget--) { s->failed_pc=0x0c098914u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c098918;
P_0c098916: /* original 6ef6, guest PC 0x0c098916 */
if(!s->budget--) { s->failed_pc=0x0c098916u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c098918;
P_0c098918: /* original 2fe6, guest PC 0x0c098918 */
if(!s->budget--) { s->failed_pc=0x0c098918u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09891a;
P_0c09891a: /* original 2fd6, guest PC 0x0c09891a */
if(!s->budget--) { s->failed_pc=0x0c09891au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09891c;
P_0c09891c: /* original dd31, guest PC 0x0c09891c */
if(!s->budget--) { s->failed_pc=0x0c09891cu; return 0; }
r[13]=read(ram,0x0c0989e4u,4);
goto P_0c09891e;
P_0c09891e: /* original d430, guest PC 0x0c09891e */
if(!s->budget--) { s->failed_pc=0x0c09891eu; return 0; }
r[4]=read(ram,0x0c0989e0u,4);
goto P_0c098920;
P_0c098920: /* original d331, guest PC 0x0c098920 */
if(!s->budget--) { s->failed_pc=0x0c098920u; return 0; }
r[3]=read(ram,0x0c0989e8u,4);
goto P_0c098922;
P_0c098922: /* original 5242, guest PC 0x0c098922 */
if(!s->budget--) { s->failed_pc=0x0c098922u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c098924;
P_0c098924: /* original 4f22, guest PC 0x0c098924 */
if(!s->budget--) { s->failed_pc=0x0c098924u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c098926;
P_0c098926: /* original 50d3, guest PC 0x0c098926 */
if(!s->budget--) { s->failed_pc=0x0c098926u; return 0; }
r[0]=read(ram,r[13]+12,4);
goto P_0c098928;
P_0c098928: /* original 883e, guest PC 0x0c098928 */
if(!s->budget--) { s->failed_pc=0x0c098928u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000003eu)!=0);
goto P_0c09892a;
P_0c09892a: /* original 2238, guest PC 0x0c09892a */
if(!s->budget--) { s->failed_pc=0x0c09892au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09892c;
P_0c09892c: /* original 8d0a, guest PC 0x0c09892c */
if(!s->budget--) { s->failed_pc=0x0c09892cu; return 0; }
cond=r[17]&1u;
r[14]=r[0];
if(cond) { goto P_0c098944; }
goto P_0c098930;
P_0c09892e: /* original 6e03, guest PC 0x0c09892e */
if(!s->budget--) { s->failed_pc=0x0c09892eu; return 0; }
r[14]=r[0];
goto P_0c098930;
P_0c098930: /* original d02e, guest PC 0x0c098930 */
if(!s->budget--) { s->failed_pc=0x0c098930u; return 0; }
r[0]=read(ram,0x0c0989ecu,4);
goto P_0c098932;
P_0c098932: /* original e300, guest PC 0x0c098932 */
if(!s->budget--) { s->failed_pc=0x0c098932u; return 0; }
r[3]=0x00000000u;
goto P_0c098934;
P_0c098934: /* original d22e, guest PC 0x0c098934 */
if(!s->budget--) { s->failed_pc=0x0c098934u; return 0; }
r[2]=read(ram,0x0c0989f0u,4);
goto P_0c098936;
P_0c098936: /* original 6502, guest PC 0x0c098936 */
if(!s->budget--) { s->failed_pc=0x0c098936u; return 0; }
tmp=read(ram,r[0],4);
r[5]=tmp;
goto P_0c098938;
P_0c098938: /* original e01c, guest PC 0x0c098938 */
if(!s->budget--) { s->failed_pc=0x0c098938u; return 0; }
r[0]=0x0000001cu;
goto P_0c09893a;
P_0c09893a: /* original 6152, guest PC 0x0c09893a */
if(!s->budget--) { s->failed_pc=0x0c09893au; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c09893c;
P_0c09893c: /* original 2129, guest PC 0x0c09893c */
if(!s->budget--) { s->failed_pc=0x0c09893cu; return 0; }
r[1]&=r[2];
goto P_0c09893e;
P_0c09893e: /* original 2512, guest PC 0x0c09893e */
if(!s->budget--) { s->failed_pc=0x0c09893eu; return 0; }
write(ram,r[5],r[1],4);
goto P_0c098940;
P_0c098940: /* original a017, guest PC 0x0c098940 */
if(!s->budget--) { s->failed_pc=0x0c098940u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c098972;
P_0c098942: /* original 0434, guest PC 0x0c098942 */
if(!s->budget--) { s->failed_pc=0x0c098942u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c098944;
P_0c098944: /* original 5242, guest PC 0x0c098944 */
if(!s->budget--) { s->failed_pc=0x0c098944u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c098946;
P_0c098946: /* original d321, guest PC 0x0c098946 */
if(!s->budget--) { s->failed_pc=0x0c098946u; return 0; }
r[3]=read(ram,0x0c0989ccu,4);
goto P_0c098948;
P_0c098948: /* original 2238, guest PC 0x0c098948 */
if(!s->budget--) { s->failed_pc=0x0c098948u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09894a;
P_0c09894a: /* original 8b12, guest PC 0x0c09894a */
if(!s->budget--) { s->failed_pc=0x0c09894au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098972; }
goto P_0c09894c;
P_0c09894c: /* original e01c, guest PC 0x0c09894c */
if(!s->budget--) { s->failed_pc=0x0c09894cu; return 0; }
r[0]=0x0000001cu;
goto P_0c09894e;
P_0c09894e: /* original 044c, guest PC 0x0c09894e */
if(!s->budget--) { s->failed_pc=0x0c09894eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c098950;
P_0c098950: /* original 644c, guest PC 0x0c098950 */
if(!s->budget--) { s->failed_pc=0x0c098950u; return 0; }
r[4]=r[4]&255u;
goto P_0c098952;
P_0c098952: /* original 4410, guest PC 0x0c098952 */
if(!s->budget--) { s->failed_pc=0x0c098952u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c098954;
P_0c098954: /* original 8b04, guest PC 0x0c098954 */
if(!s->budget--) { s->failed_pc=0x0c098954u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098960; }
goto P_0c098956;
P_0c098956: /* original 60e3, guest PC 0x0c098956 */
if(!s->budget--) { s->failed_pc=0x0c098956u; return 0; }
r[0]=r[14];
goto P_0c098958;
P_0c098958: /* original 881b, guest PC 0x0c098958 */
if(!s->budget--) { s->failed_pc=0x0c098958u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001bu)!=0);
goto P_0c09895a;
P_0c09895a: /* original 8b0a, guest PC 0x0c09895a */
if(!s->budget--) { s->failed_pc=0x0c09895au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098972; }
goto P_0c09895c;
P_0c09895c: /* original a003, guest PC 0x0c09895c */
if(!s->budget--) { s->failed_pc=0x0c09895cu; return 0; }
goto P_0c098966;
P_0c09895e: /* original 0009, guest PC 0x0c09895e */
if(!s->budget--) { s->failed_pc=0x0c09895eu; return 0; }
goto P_0c098960;
P_0c098960: /* original 60e3, guest PC 0x0c098960 */
if(!s->budget--) { s->failed_pc=0x0c098960u; return 0; }
r[0]=r[14];
goto P_0c098962;
P_0c098962: /* original 881b, guest PC 0x0c098962 */
if(!s->budget--) { s->failed_pc=0x0c098962u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001bu)!=0);
goto P_0c098964;
P_0c098964: /* original 8b05, guest PC 0x0c098964 */
if(!s->budget--) { s->failed_pc=0x0c098964u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098972; }
goto P_0c098966;
P_0c098966: /* original d023, guest PC 0x0c098966 */
if(!s->budget--) { s->failed_pc=0x0c098966u; return 0; }
r[0]=read(ram,0x0c0989f4u,4);
goto P_0c098968;
P_0c098968: /* original 7401, guest PC 0x0c098968 */
if(!s->budget--) { s->failed_pc=0x0c098968u; return 0; }
r[4]+=0x00000001u;
goto P_0c09896a;
P_0c09896a: /* original d21b, guest PC 0x0c09896a */
if(!s->budget--) { s->failed_pc=0x0c09896au; return 0; }
r[2]=read(ram,0x0c0989d8u,4);
goto P_0c09896c;
P_0c09896c: /* original 4408, guest PC 0x0c09896c */
if(!s->budget--) { s->failed_pc=0x0c09896cu; return 0; }
r[4]<<=2;
goto P_0c09896e;
P_0c09896e: /* original 420b, guest PC 0x0c09896e */
if(!s->budget--) { s->failed_pc=0x0c09896eu; return 0; }
target=r[2];
r[16]=code_base|0x0c098972u;
r[4]=read(ram,r[4]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098972u) { target=s->pc; goto dispatch; }
goto P_0c098972;
P_0c098970: /* original 044e, guest PC 0x0c098970 */
if(!s->budget--) { s->failed_pc=0x0c098970u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c098972;
P_0c098972: /* original 2ee8, guest PC 0x0c098972 */
if(!s->budget--) { s->failed_pc=0x0c098972u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c098974;
P_0c098974: /* original 8b02, guest PC 0x0c098974 */
if(!s->budget--) { s->failed_pc=0x0c098974u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09897c; }
goto P_0c098976;
P_0c098976: /* original 84db, guest PC 0x0c098976 */
if(!s->budget--) { s->failed_pc=0x0c098976u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+11,1);
goto P_0c098978;
P_0c098978: /* original 7001, guest PC 0x0c098978 */
if(!s->budget--) { s->failed_pc=0x0c098978u; return 0; }
r[0]+=0x00000001u;
goto P_0c09897a;
P_0c09897a: /* original 80db, guest PC 0x0c09897a */
if(!s->budget--) { s->failed_pc=0x0c09897au; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c09897c;
P_0c09897c: /* original 4f26, guest PC 0x0c09897c */
if(!s->budget--) { s->failed_pc=0x0c09897cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09897e;
P_0c09897e: /* original 6df6, guest PC 0x0c09897e */
if(!s->budget--) { s->failed_pc=0x0c09897eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c098980;
P_0c098980: /* original ab38, guest PC 0x0c098980 */
if(!s->budget--) { s->failed_pc=0x0c098980u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c097ff4;
P_0c098982: /* original 6ef6, guest PC 0x0c098982 */
if(!s->budget--) { s->failed_pc=0x0c098982u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c098984u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c098984u; return 0; } return 1;
P_0c098c62: /* original 2fe6, guest PC 0x0c098c62 */
if(!s->budget--) { s->failed_pc=0x0c098c62u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098c64;
P_0c098c64: /* original 2fd6, guest PC 0x0c098c64 */
if(!s->budget--) { s->failed_pc=0x0c098c64u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098c66;
P_0c098c66: /* original 2fc6, guest PC 0x0c098c66 */
if(!s->budget--) { s->failed_pc=0x0c098c66u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098c68;
P_0c098c68: /* original 2fb6, guest PC 0x0c098c68 */
if(!s->budget--) { s->failed_pc=0x0c098c68u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098c6a;
P_0c098c6a: /* original 2fa6, guest PC 0x0c098c6a */
if(!s->budget--) { s->failed_pc=0x0c098c6au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098c6c;
P_0c098c6c: /* original 2f96, guest PC 0x0c098c6c */
if(!s->budget--) { s->failed_pc=0x0c098c6cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098c6e;
P_0c098c6e: /* original 2f86, guest PC 0x0c098c6e */
if(!s->budget--) { s->failed_pc=0x0c098c6eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c098c70;
P_0c098c70: /* original 4f22, guest PC 0x0c098c70 */
if(!s->budget--) { s->failed_pc=0x0c098c70u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c098c72;
P_0c098c72: /* original d331, guest PC 0x0c098c72 */
if(!s->budget--) { s->failed_pc=0x0c098c72u; return 0; }
r[3]=read(ram,0x0c098d38u,4);
goto P_0c098c74;
P_0c098c74: /* original de2f, guest PC 0x0c098c74 */
if(!s->budget--) { s->failed_pc=0x0c098c74u; return 0; }
r[14]=read(ram,0x0c098d34u,4);
goto P_0c098c76;
P_0c098c76: /* original 7fe4, guest PC 0x0c098c76 */
if(!s->budget--) { s->failed_pc=0x0c098c76u; return 0; }
r[15]+=0xffffffe4u;
goto P_0c098c78;
P_0c098c78: /* original 1f33, guest PC 0x0c098c78 */
if(!s->budget--) { s->failed_pc=0x0c098c78u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c098c7a;
P_0c098c7a: /* original d230, guest PC 0x0c098c7a */
if(!s->budget--) { s->failed_pc=0x0c098c7au; return 0; }
r[2]=read(ram,0x0c098d3cu,4);
goto P_0c098c7c;
P_0c098c7c: /* original 1f26, guest PC 0x0c098c7c */
if(!s->budget--) { s->failed_pc=0x0c098c7cu; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c098c7e;
P_0c098c7e: /* original d430, guest PC 0x0c098c7e */
if(!s->budget--) { s->failed_pc=0x0c098c7eu; return 0; }
r[4]=read(ram,0x0c098d40u,4);
goto P_0c098c80;
P_0c098c80: /* original 934f, guest PC 0x0c098c80 */
if(!s->budget--) { s->failed_pc=0x0c098c80u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098d22u,2);
goto P_0c098c82;
P_0c098c82: /* original 334c, guest PC 0x0c098c82 */
if(!s->budget--) { s->failed_pc=0x0c098c82u; return 0; }
r[3]+=r[4];
goto P_0c098c84;
P_0c098c84: /* original 1f31, guest PC 0x0c098c84 */
if(!s->budget--) { s->failed_pc=0x0c098c84u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c098c86;
P_0c098c86: /* original 924d, guest PC 0x0c098c86 */
if(!s->budget--) { s->failed_pc=0x0c098c86u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098d24u,2);
goto P_0c098c88;
P_0c098c88: /* original 324c, guest PC 0x0c098c88 */
if(!s->budget--) { s->failed_pc=0x0c098c88u; return 0; }
r[2]+=r[4];
goto P_0c098c8a;
P_0c098c8a: /* original 1f25, guest PC 0x0c098c8a */
if(!s->budget--) { s->failed_pc=0x0c098c8au; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c098c8c;
P_0c098c8c: /* original d32d, guest PC 0x0c098c8c */
if(!s->budget--) { s->failed_pc=0x0c098c8cu; return 0; }
r[3]=read(ram,0x0c098d44u,4);
goto P_0c098c8e;
P_0c098c8e: /* original 1f34, guest PC 0x0c098c8e */
if(!s->budget--) { s->failed_pc=0x0c098c8eu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c098c90;
P_0c098c90: /* original d32e, guest PC 0x0c098c90 */
if(!s->budget--) { s->failed_pc=0x0c098c90u; return 0; }
r[3]=read(ram,0x0c098d4cu,4);
goto P_0c098c92;
P_0c098c92: /* original dc2d, guest PC 0x0c098c92 */
if(!s->budget--) { s->failed_pc=0x0c098c92u; return 0; }
r[12]=read(ram,0x0c098d48u,4);
goto P_0c098c94;
P_0c098c94: /* original 430b, guest PC 0x0c098c94 */
if(!s->budget--) { s->failed_pc=0x0c098c94u; return 0; }
target=r[3];
r[16]=code_base|0x0c098c98u;
r[4]=read(ram,r[12]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098c98u) { target=s->pc; goto dispatch; }
goto P_0c098c98;
P_0c098c96: /* original 54cf, guest PC 0x0c098c96 */
if(!s->budget--) { s->failed_pc=0x0c098c96u; return 0; }
r[4]=read(ram,r[12]+60,4);
goto P_0c098c98;
P_0c098c98: /* original d32c, guest PC 0x0c098c98 */
if(!s->budget--) { s->failed_pc=0x0c098c98u; return 0; }
r[3]=read(ram,0x0c098d4cu,4);
goto P_0c098c9a;
P_0c098c9a: /* original e040, guest PC 0x0c098c9a */
if(!s->budget--) { s->failed_pc=0x0c098c9au; return 0; }
r[0]=0x00000040u;
goto P_0c098c9c;
P_0c098c9c: /* original 430b, guest PC 0x0c098c9c */
if(!s->budget--) { s->failed_pc=0x0c098c9cu; return 0; }
target=r[3];
r[16]=code_base|0x0c098ca0u;
r[4]=read(ram,r[12]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098ca0u) { target=s->pc; goto dispatch; }
goto P_0c098ca0;
P_0c098c9e: /* original 04ce, guest PC 0x0c098c9e */
if(!s->budget--) { s->failed_pc=0x0c098c9eu; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c098ca0;
P_0c098ca0: /* original 52e2, guest PC 0x0c098ca0 */
if(!s->budget--) { s->failed_pc=0x0c098ca0u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c098ca2;
P_0c098ca2: /* original d32b, guest PC 0x0c098ca2 */
if(!s->budget--) { s->failed_pc=0x0c098ca2u; return 0; }
r[3]=read(ram,0x0c098d50u,4);
goto P_0c098ca4;
P_0c098ca4: /* original 55c4, guest PC 0x0c098ca4 */
if(!s->budget--) { s->failed_pc=0x0c098ca4u; return 0; }
r[5]=read(ram,r[12]+16,4);
goto P_0c098ca6;
P_0c098ca6: /* original 2238, guest PC 0x0c098ca6 */
if(!s->budget--) { s->failed_pc=0x0c098ca6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c098ca8;
P_0c098ca8: /* original 8d07, guest PC 0x0c098ca8 */
if(!s->budget--) { s->failed_pc=0x0c098ca8u; return 0; }
cond=r[17]&1u;
r[7]=read(ram,r[12]+20,4);
if(cond) { goto P_0c098cba; }
goto P_0c098cac;
P_0c098caa: /* original 57c5, guest PC 0x0c098caa */
if(!s->budget--) { s->failed_pc=0x0c098caau; return 0; }
r[7]=read(ram,r[12]+20,4);
goto P_0c098cac;
P_0c098cac: /* original 943b, guest PC 0x0c098cac */
if(!s->budget--) { s->failed_pc=0x0c098cacu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098d26u,2);
goto P_0c098cae;
P_0c098cae: /* original e046, guest PC 0x0c098cae */
if(!s->budget--) { s->failed_pc=0x0c098caeu; return 0; }
r[0]=0x00000046u;
goto P_0c098cb0;
P_0c098cb0: /* original 6843, guest PC 0x0c098cb0 */
if(!s->budget--) { s->failed_pc=0x0c098cb0u; return 0; }
r[8]=r[4];
goto P_0c098cb2;
P_0c098cb2: /* original 1f42, guest PC 0x0c098cb2 */
if(!s->budget--) { s->failed_pc=0x0c098cb2u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c098cb4;
P_0c098cb4: /* original 0545, guest PC 0x0c098cb4 */
if(!s->budget--) { s->failed_pc=0x0c098cb4u; return 0; }
write(ram,r[5]+r[0],r[4],2);
goto P_0c098cb6;
P_0c098cb6: /* original a007, guest PC 0x0c098cb6 */
if(!s->budget--) { s->failed_pc=0x0c098cb6u; return 0; }
write(ram,r[7]+r[0],r[8],2);
goto P_0c098cc8;
P_0c098cb8: /* original 0785, guest PC 0x0c098cb8 */
if(!s->budget--) { s->failed_pc=0x0c098cb8u; return 0; }
write(ram,r[7]+r[0],r[8],2);
goto P_0c098cba;
P_0c098cba: /* original e046, guest PC 0x0c098cba */
if(!s->budget--) { s->failed_pc=0x0c098cbau; return 0; }
r[0]=0x00000046u;
goto P_0c098cbc;
P_0c098cbc: /* original 015d, guest PC 0x0c098cbc */
if(!s->budget--) { s->failed_pc=0x0c098cbcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c098cbe;
P_0c098cbe: /* original e046, guest PC 0x0c098cbe */
if(!s->budget--) { s->failed_pc=0x0c098cbeu; return 0; }
r[0]=0x00000046u;
goto P_0c098cc0;
P_0c098cc0: /* original 611d, guest PC 0x0c098cc0 */
if(!s->budget--) { s->failed_pc=0x0c098cc0u; return 0; }
r[1]=r[1]&65535u;
goto P_0c098cc2;
P_0c098cc2: /* original 1f12, guest PC 0x0c098cc2 */
if(!s->budget--) { s->failed_pc=0x0c098cc2u; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c098cc4;
P_0c098cc4: /* original 087d, guest PC 0x0c098cc4 */
if(!s->budget--) { s->failed_pc=0x0c098cc4u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+r[0],2);
goto P_0c098cc6;
P_0c098cc6: /* original 688d, guest PC 0x0c098cc6 */
if(!s->budget--) { s->failed_pc=0x0c098cc6u; return 0; }
r[8]=r[8]&65535u;
goto P_0c098cc8;
P_0c098cc8: /* original e029, guest PC 0x0c098cc8 */
if(!s->budget--) { s->failed_pc=0x0c098cc8u; return 0; }
r[0]=0x00000029u;
goto P_0c098cca;
P_0c098cca: /* original 56ef, guest PC 0x0c098cca */
if(!s->budget--) { s->failed_pc=0x0c098ccau; return 0; }
r[6]=read(ram,r[14]+60,4);
goto P_0c098ccc;
P_0c098ccc: /* original 0bec, guest PC 0x0c098ccc */
if(!s->budget--) { s->failed_pc=0x0c098cccu; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098cce;
P_0c098cce: /* original e02a, guest PC 0x0c098cce */
if(!s->budget--) { s->failed_pc=0x0c098cceu; return 0; }
r[0]=0x0000002au;
goto P_0c098cd0;
P_0c098cd0: /* original 03ec, guest PC 0x0c098cd0 */
if(!s->budget--) { s->failed_pc=0x0c098cd0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098cd2;
P_0c098cd2: /* original 6bbc, guest PC 0x0c098cd2 */
if(!s->budget--) { s->failed_pc=0x0c098cd2u; return 0; }
r[11]=r[11]&255u;
goto P_0c098cd4;
P_0c098cd4: /* original 633c, guest PC 0x0c098cd4 */
if(!s->budget--) { s->failed_pc=0x0c098cd4u; return 0; }
r[3]=r[3]&255u;
goto P_0c098cd6;
P_0c098cd6: /* original 2f32, guest PC 0x0c098cd6 */
if(!s->budget--) { s->failed_pc=0x0c098cd6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c098cd8;
P_0c098cd8: /* original 5de2, guest PC 0x0c098cd8 */
if(!s->budget--) { s->failed_pc=0x0c098cd8u; return 0; }
r[13]=read(ram,r[14]+8,4);
goto P_0c098cda;
P_0c098cda: /* original d314, guest PC 0x0c098cda */
if(!s->budget--) { s->failed_pc=0x0c098cdau; return 0; }
r[3]=read(ram,0x0c098d2cu,4);
goto P_0c098cdc;
P_0c098cdc: /* original da1d, guest PC 0x0c098cdc */
if(!s->budget--) { s->failed_pc=0x0c098cdcu; return 0; }
r[10]=read(ram,0x0c098d54u,4);
goto P_0c098cde;
P_0c098cde: /* original 23d8, guest PC 0x0c098cde */
if(!s->budget--) { s->failed_pc=0x0c098cdeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c098ce0;
P_0c098ce0: /* original 8d0d, guest PC 0x0c098ce0 */
if(!s->budget--) { s->failed_pc=0x0c098ce0u; return 0; }
cond=r[17]&1u;
r[4]=0x00000001u;
if(cond) { goto P_0c098cfe; }
goto P_0c098ce4;
P_0c098ce2: /* original e401, guest PC 0x0c098ce2 */
if(!s->budget--) { s->failed_pc=0x0c098ce2u; return 0; }
r[4]=0x00000001u;
goto P_0c098ce4;
P_0c098ce4: /* original 53f2, guest PC 0x0c098ce4 */
if(!s->budget--) { s->failed_pc=0x0c098ce4u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c098ce6;
P_0c098ce6: /* original 3387, guest PC 0x0c098ce6 */
if(!s->budget--) { s->failed_pc=0x0c098ce6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[8])!=0);
goto P_0c098ce8;
P_0c098ce8: /* original 8f02, guest PC 0x0c098ce8 */
if(!s->budget--) { s->failed_pc=0x0c098ce8u; return 0; }
cond=r[17]&1u;
r[9]=0x00000002u;
if(!cond) { goto P_0c098cf0; }
goto P_0c098cec;
P_0c098cea: /* original e902, guest PC 0x0c098cea */
if(!s->budget--) { s->failed_pc=0x0c098ceau; return 0; }
r[9]=0x00000002u;
goto P_0c098cec;
P_0c098cec: /* original a088, guest PC 0x0c098cec */
if(!s->budget--) { s->failed_pc=0x0c098cecu; return 0; }
goto P_0c098e00;
P_0c098cee: /* original 0009, guest PC 0x0c098cee */
if(!s->budget--) { s->failed_pc=0x0c098ceeu; return 0; }
goto P_0c098cf0;
P_0c098cf0: /* original 52f2, guest PC 0x0c098cf0 */
if(!s->budget--) { s->failed_pc=0x0c098cf0u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c098cf2;
P_0c098cf2: /* original 3283, guest PC 0x0c098cf2 */
if(!s->budget--) { s->failed_pc=0x0c098cf2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[8])!=0);
goto P_0c098cf4;
P_0c098cf4: /* original 8901, guest PC 0x0c098cf4 */
if(!s->budget--) { s->failed_pc=0x0c098cf4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098cfa; }
goto P_0c098cf6;
P_0c098cf6: /* original a0d0, guest PC 0x0c098cf6 */
if(!s->budget--) { s->failed_pc=0x0c098cf6u; return 0; }
goto P_0c098e9a;
P_0c098cf8: /* original 0009, guest PC 0x0c098cf8 */
if(!s->budget--) { s->failed_pc=0x0c098cf8u; return 0; }
goto P_0c098cfa;
P_0c098cfa: /* original a03e, guest PC 0x0c098cfa */
if(!s->budget--) { s->failed_pc=0x0c098cfau; return 0; }
goto P_0c098d7a;
P_0c098cfc: /* original 0009, guest PC 0x0c098cfc */
if(!s->budget--) { s->failed_pc=0x0c098cfcu; return 0; }
goto P_0c098cfe;
P_0c098cfe: /* original 9213, guest PC 0x0c098cfe */
if(!s->budget--) { s->failed_pc=0x0c098cfeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098d28u,2);
goto P_0c098d00;
P_0c098d00: /* original 22d8, guest PC 0x0c098d00 */
if(!s->budget--) { s->failed_pc=0x0c098d00u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c098d02;
P_0c098d02: /* original 8f01, guest PC 0x0c098d02 */
if(!s->budget--) { s->failed_pc=0x0c098d02u; return 0; }
cond=r[17]&1u;
r[9]=r[4];
if(!cond) { goto P_0c098d08; }
goto P_0c098d06;
P_0c098d04: /* original 6943, guest PC 0x0c098d04 */
if(!s->budget--) { s->failed_pc=0x0c098d04u; return 0; }
r[9]=r[4];
goto P_0c098d06;
P_0c098d06: /* original e900, guest PC 0x0c098d06 */
if(!s->budget--) { s->failed_pc=0x0c098d06u; return 0; }
r[9]=0x00000000u;
goto P_0c098d08;
P_0c098d08: /* original 52e2, guest PC 0x0c098d08 */
if(!s->budget--) { s->failed_pc=0x0c098d08u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c098d0a;
P_0c098d0a: /* original d311, guest PC 0x0c098d0a */
if(!s->budget--) { s->failed_pc=0x0c098d0au; return 0; }
r[3]=read(ram,0x0c098d50u,4);
goto P_0c098d0c;
P_0c098d0c: /* original 2238, guest PC 0x0c098d0c */
if(!s->budget--) { s->failed_pc=0x0c098d0cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c098d0e;
P_0c098d0e: /* original 892a, guest PC 0x0c098d0e */
if(!s->budget--) { s->failed_pc=0x0c098d0eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098d66; }
goto P_0c098d10;
P_0c098d10: /* original d211, guest PC 0x0c098d10 */
if(!s->budget--) { s->failed_pc=0x0c098d10u; return 0; }
r[2]=read(ram,0x0c098d58u,4);
goto P_0c098d12;
P_0c098d12: /* original 54f1, guest PC 0x0c098d12 */
if(!s->budget--) { s->failed_pc=0x0c098d12u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c098d14;
P_0c098d14: /* original 420b, guest PC 0x0c098d14 */
if(!s->budget--) { s->failed_pc=0x0c098d14u; return 0; }
target=r[2];
r[16]=code_base|0x0c098d18u;
r[4]+=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098d18u) { target=s->pc; goto dispatch; }
goto P_0c098d18;
P_0c098d16: /* original 7412, guest PC 0x0c098d16 */
if(!s->budget--) { s->failed_pc=0x0c098d16u; return 0; }
r[4]+=0x00000012u;
goto P_0c098d18;
P_0c098d18: /* original 600c, guest PC 0x0c098d18 */
if(!s->budget--) { s->failed_pc=0x0c098d18u; return 0; }
r[0]=r[0]&255u;
goto P_0c098d1a;
P_0c098d1a: /* original 2008, guest PC 0x0c098d1a */
if(!s->budget--) { s->failed_pc=0x0c098d1au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c098d1c;
P_0c098d1c: /* original 8b1e, guest PC 0x0c098d1c */
if(!s->budget--) { s->failed_pc=0x0c098d1cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098d5c; }
goto P_0c098d1e;
P_0c098d1e: /* original a01e, guest PC 0x0c098d1e */
if(!s->budget--) { s->failed_pc=0x0c098d1eu; return 0; }
r[4]=0x00000038u;
goto P_0c098d5e;
P_0c098d20: /* original e438, guest PC 0x0c098d20 */
if(!s->budget--) { s->failed_pc=0x0c098d20u; return 0; }
r[4]=0x00000038u;
if(!vf3_matrix_family(0x0c098d22u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c098d22u; return 0; } return 1;
P_0c098d5c: /* original e435, guest PC 0x0c098d5c */
if(!s->budget--) { s->failed_pc=0x0c098d5cu; return 0; }
r[4]=0x00000035u;
goto P_0c098d5e;
P_0c098d5e: /* original 4a0b, guest PC 0x0c098d5e */
if(!s->budget--) { s->failed_pc=0x0c098d5eu; return 0; }
target=r[10];
r[16]=code_base|0x0c098d62u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098d62u) { target=s->pc; goto dispatch; }
goto P_0c098d62;
P_0c098d60: /* original 0009, guest PC 0x0c098d60 */
if(!s->budget--) { s->failed_pc=0x0c098d60u; return 0; }
goto P_0c098d62;
P_0c098d62: /* original a129, guest PC 0x0c098d62 */
if(!s->budget--) { s->failed_pc=0x0c098d62u; return 0; }
goto P_0c098fb8;
P_0c098d64: /* original 0009, guest PC 0x0c098d64 */
if(!s->budget--) { s->failed_pc=0x0c098d64u; return 0; }
goto P_0c098d66;
P_0c098d66: /* original 6252, guest PC 0x0c098d66 */
if(!s->budget--) { s->failed_pc=0x0c098d66u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c098d68;
P_0c098d68: /* original d322, guest PC 0x0c098d68 */
if(!s->budget--) { s->failed_pc=0x0c098d68u; return 0; }
r[3]=read(ram,0x0c098df4u,4);
goto P_0c098d6a;
P_0c098d6a: /* original 2238, guest PC 0x0c098d6a */
if(!s->budget--) { s->failed_pc=0x0c098d6au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c098d6c;
P_0c098d6c: /* original 8948, guest PC 0x0c098d6c */
if(!s->budget--) { s->failed_pc=0x0c098d6cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098e00; }
goto P_0c098d6e;
P_0c098d6e: /* original 6172, guest PC 0x0c098d6e */
if(!s->budget--) { s->failed_pc=0x0c098d6eu; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c098d70;
P_0c098d70: /* original d320, guest PC 0x0c098d70 */
if(!s->budget--) { s->failed_pc=0x0c098d70u; return 0; }
r[3]=read(ram,0x0c098df4u,4);
goto P_0c098d72;
P_0c098d72: /* original 2138, guest PC 0x0c098d72 */
if(!s->budget--) { s->failed_pc=0x0c098d72u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c098d74;
P_0c098d74: /* original 8b01, guest PC 0x0c098d74 */
if(!s->budget--) { s->failed_pc=0x0c098d74u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098d7a; }
goto P_0c098d76;
P_0c098d76: /* original a090, guest PC 0x0c098d76 */
if(!s->budget--) { s->failed_pc=0x0c098d76u; return 0; }
goto P_0c098e9a;
P_0c098d78: /* original 0009, guest PC 0x0c098d78 */
if(!s->budget--) { s->failed_pc=0x0c098d78u; return 0; }
goto P_0c098d7a;
P_0c098d7a: /* original e01a, guest PC 0x0c098d7a */
if(!s->budget--) { s->failed_pc=0x0c098d7au; return 0; }
r[0]=0x0000001au;
goto P_0c098d7c;
P_0c098d7c: /* original 05ec, guest PC 0x0c098d7c */
if(!s->budget--) { s->failed_pc=0x0c098d7cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098d7e;
P_0c098d7e: /* original e01b, guest PC 0x0c098d7e */
if(!s->budget--) { s->failed_pc=0x0c098d7eu; return 0; }
r[0]=0x0000001bu;
goto P_0c098d80;
P_0c098d80: /* original 07ec, guest PC 0x0c098d80 */
if(!s->budget--) { s->failed_pc=0x0c098d80u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098d82;
P_0c098d82: /* original e01a, guest PC 0x0c098d82 */
if(!s->budget--) { s->failed_pc=0x0c098d82u; return 0; }
r[0]=0x0000001au;
goto P_0c098d84;
P_0c098d84: /* original 655c, guest PC 0x0c098d84 */
if(!s->budget--) { s->failed_pc=0x0c098d84u; return 0; }
r[5]=r[5]&255u;
goto P_0c098d86;
P_0c098d86: /* original 7501, guest PC 0x0c098d86 */
if(!s->budget--) { s->failed_pc=0x0c098d86u; return 0; }
r[5]+=0x00000001u;
goto P_0c098d88;
P_0c098d88: /* original 677c, guest PC 0x0c098d88 */
if(!s->budget--) { s->failed_pc=0x0c098d88u; return 0; }
r[7]=r[7]&255u;
goto P_0c098d8a;
P_0c098d8a: /* original 0e54, guest PC 0x0c098d8a */
if(!s->budget--) { s->failed_pc=0x0c098d8au; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c098d8c;
P_0c098d8c: /* original 7701, guest PC 0x0c098d8c */
if(!s->budget--) { s->failed_pc=0x0c098d8cu; return 0; }
r[7]+=0x00000001u;
goto P_0c098d8e;
P_0c098d8e: /* original 3563, guest PC 0x0c098d8e */
if(!s->budget--) { s->failed_pc=0x0c098d8eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c098d90;
P_0c098d90: /* original 6373, guest PC 0x0c098d90 */
if(!s->budget--) { s->failed_pc=0x0c098d90u; return 0; }
r[3]=r[7];
goto P_0c098d92;
P_0c098d92: /* original e01b, guest PC 0x0c098d92 */
if(!s->budget--) { s->failed_pc=0x0c098d92u; return 0; }
r[0]=0x0000001bu;
goto P_0c098d94;
P_0c098d94: /* original 3368, guest PC 0x0c098d94 */
if(!s->budget--) { s->failed_pc=0x0c098d94u; return 0; }
r[3]-=r[6];
goto P_0c098d96;
P_0c098d96: /* original 0e74, guest PC 0x0c098d96 */
if(!s->budget--) { s->failed_pc=0x0c098d96u; return 0; }
write(ram,r[14]+r[0],r[7],1);
goto P_0c098d98;
P_0c098d98: /* original e802, guest PC 0x0c098d98 */
if(!s->budget--) { s->failed_pc=0x0c098d98u; return 0; }
r[8]=0x00000002u;
goto P_0c098d9a;
P_0c098d9a: /* original 8f26, guest PC 0x0c098d9a */
if(!s->budget--) { s->failed_pc=0x0c098d9au; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[3],4);
if(!cond) { goto P_0c098dea; }
goto P_0c098d9e;
P_0c098d9c: /* original 1f32, guest PC 0x0c098d9c */
if(!s->budget--) { s->failed_pc=0x0c098d9cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c098d9e;
P_0c098d9e: /* original 3763, guest PC 0x0c098d9e */
if(!s->budget--) { s->failed_pc=0x0c098d9eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[6])!=0);
goto P_0c098da0;
P_0c098da0: /* original 8b4a, guest PC 0x0c098da0 */
if(!s->budget--) { s->failed_pc=0x0c098da0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098e38; }
goto P_0c098da2;
P_0c098da2: /* original d315, guest PC 0x0c098da2 */
if(!s->budget--) { s->failed_pc=0x0c098da2u; return 0; }
r[3]=read(ram,0x0c098df8u,4);
goto P_0c098da4;
P_0c098da4: /* original 23d8, guest PC 0x0c098da4 */
if(!s->budget--) { s->failed_pc=0x0c098da4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c098da6;
P_0c098da6: /* original 8b07, guest PC 0x0c098da6 */
if(!s->budget--) { s->failed_pc=0x0c098da6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098db8; }
goto P_0c098da8;
P_0c098da8: /* original 75ff, guest PC 0x0c098da8 */
if(!s->budget--) { s->failed_pc=0x0c098da8u; return 0; }
r[5]+=0xffffffffu;
goto P_0c098daa;
P_0c098daa: /* original d213, guest PC 0x0c098daa */
if(!s->budget--) { s->failed_pc=0x0c098daau; return 0; }
r[2]=read(ram,0x0c098df8u,4);
goto P_0c098dac;
P_0c098dac: /* original e01b, guest PC 0x0c098dac */
if(!s->budget--) { s->failed_pc=0x0c098dacu; return 0; }
r[0]=0x0000001bu;
goto P_0c098dae;
P_0c098dae: /* original 0e54, guest PC 0x0c098dae */
if(!s->budget--) { s->failed_pc=0x0c098daeu; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c098db0;
P_0c098db0: /* original e01a, guest PC 0x0c098db0 */
if(!s->budget--) { s->failed_pc=0x0c098db0u; return 0; }
r[0]=0x0000001au;
goto P_0c098db2;
P_0c098db2: /* original 2d2b, guest PC 0x0c098db2 */
if(!s->budget--) { s->failed_pc=0x0c098db2u; return 0; }
r[13]|=r[2];
goto P_0c098db4;
P_0c098db4: /* original a0d1, guest PC 0x0c098db4 */
if(!s->budget--) { s->failed_pc=0x0c098db4u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c098f5a;
P_0c098db6: /* original 0e54, guest PC 0x0c098db6 */
if(!s->budget--) { s->failed_pc=0x0c098db6u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c098db8;
P_0c098db8: /* original d210, guest PC 0x0c098db8 */
if(!s->budget--) { s->failed_pc=0x0c098db8u; return 0; }
r[2]=read(ram,0x0c098dfcu,4);
goto P_0c098dba;
P_0c098dba: /* original 60b3, guest PC 0x0c098dba */
if(!s->budget--) { s->failed_pc=0x0c098dbau; return 0; }
r[0]=r[11];
goto P_0c098dbc;
P_0c098dbc: /* original 8801, guest PC 0x0c098dbc */
if(!s->budget--) { s->failed_pc=0x0c098dbcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c098dbe;
P_0c098dbe: /* original 2d29, guest PC 0x0c098dbe */
if(!s->budget--) { s->failed_pc=0x0c098dbeu; return 0; }
r[13]&=r[2];
goto P_0c098dc0;
P_0c098dc0: /* original 8d0d, guest PC 0x0c098dc0 */
if(!s->budget--) { s->failed_pc=0x0c098dc0u; return 0; }
cond=r[17]&1u;
r[5]+=0xffffffffu;
if(cond) { goto P_0c098dde; }
goto P_0c098dc4;
P_0c098dc2: /* original 75ff, guest PC 0x0c098dc2 */
if(!s->budget--) { s->failed_pc=0x0c098dc2u; return 0; }
r[5]+=0xffffffffu;
goto P_0c098dc4;
P_0c098dc4: /* original 60b3, guest PC 0x0c098dc4 */
if(!s->budget--) { s->failed_pc=0x0c098dc4u; return 0; }
r[0]=r[11];
goto P_0c098dc6;
P_0c098dc6: /* original 8802, guest PC 0x0c098dc6 */
if(!s->budget--) { s->failed_pc=0x0c098dc6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c098dc8;
P_0c098dc8: /* original 890c, guest PC 0x0c098dc8 */
if(!s->budget--) { s->failed_pc=0x0c098dc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098de4; }
goto P_0c098dca;
P_0c098dca: /* original 60f2, guest PC 0x0c098dca */
if(!s->budget--) { s->failed_pc=0x0c098dcau; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c098dcc;
P_0c098dcc: /* original 8801, guest PC 0x0c098dcc */
if(!s->budget--) { s->failed_pc=0x0c098dccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c098dce;
P_0c098dce: /* original 8906, guest PC 0x0c098dce */
if(!s->budget--) { s->failed_pc=0x0c098dceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098dde; }
goto P_0c098dd0;
P_0c098dd0: /* original 60f2, guest PC 0x0c098dd0 */
if(!s->budget--) { s->failed_pc=0x0c098dd0u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c098dd2;
P_0c098dd2: /* original 8802, guest PC 0x0c098dd2 */
if(!s->budget--) { s->failed_pc=0x0c098dd2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c098dd4;
P_0c098dd4: /* original 8906, guest PC 0x0c098dd4 */
if(!s->budget--) { s->failed_pc=0x0c098dd4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098de4; }
goto P_0c098dd6;
P_0c098dd6: /* original 56f6, guest PC 0x0c098dd6 */
if(!s->budget--) { s->failed_pc=0x0c098dd6u; return 0; }
r[6]=read(ram,r[15]+24,4);
goto P_0c098dd8;
P_0c098dd8: /* original 6662, guest PC 0x0c098dd8 */
if(!s->budget--) { s->failed_pc=0x0c098dd8u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c098dda;
P_0c098dda: /* original 2648, guest PC 0x0c098dda */
if(!s->budget--) { s->failed_pc=0x0c098ddau; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[4])==0)!=0);
goto P_0c098ddc;
P_0c098ddc: /* original 8902, guest PC 0x0c098ddc */
if(!s->budget--) { s->failed_pc=0x0c098ddcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098de4; }
goto P_0c098dde;
P_0c098dde: /* original e01b, guest PC 0x0c098dde */
if(!s->budget--) { s->failed_pc=0x0c098ddeu; return 0; }
r[0]=0x0000001bu;
goto P_0c098de0;
P_0c098de0: /* original a02a, guest PC 0x0c098de0 */
if(!s->budget--) { s->failed_pc=0x0c098de0u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c098e38;
P_0c098de2: /* original 0e54, guest PC 0x0c098de2 */
if(!s->budget--) { s->failed_pc=0x0c098de2u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c098de4;
P_0c098de4: /* original e01a, guest PC 0x0c098de4 */
if(!s->budget--) { s->failed_pc=0x0c098de4u; return 0; }
r[0]=0x0000001au;
goto P_0c098de6;
P_0c098de6: /* original a074, guest PC 0x0c098de6 */
if(!s->budget--) { s->failed_pc=0x0c098de6u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c098ed2;
P_0c098de8: /* original 0e54, guest PC 0x0c098de8 */
if(!s->budget--) { s->failed_pc=0x0c098de8u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c098dea;
P_0c098dea: /* original 52f2, guest PC 0x0c098dea */
if(!s->budget--) { s->failed_pc=0x0c098deau; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c098dec;
P_0c098dec: /* original 4211, guest PC 0x0c098dec */
if(!s->budget--) { s->failed_pc=0x0c098decu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c098dee;
P_0c098dee: /* original 8970, guest PC 0x0c098dee */
if(!s->budget--) { s->failed_pc=0x0c098deeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098ed2; }
goto P_0c098df0;
P_0c098df0: /* original a0b3, guest PC 0x0c098df0 */
if(!s->budget--) { s->failed_pc=0x0c098df0u; return 0; }
goto P_0c098f5a;
P_0c098df2: /* original 0009, guest PC 0x0c098df2 */
if(!s->budget--) { s->failed_pc=0x0c098df2u; return 0; }
if(!vf3_matrix_family(0x0c098df4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c098df4u; return 0; } return 1;
P_0c098e00: /* original e01a, guest PC 0x0c098e00 */
if(!s->budget--) { s->failed_pc=0x0c098e00u; return 0; }
r[0]=0x0000001au;
goto P_0c098e02;
P_0c098e02: /* original 07ec, guest PC 0x0c098e02 */
if(!s->budget--) { s->failed_pc=0x0c098e02u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098e04;
P_0c098e04: /* original 677c, guest PC 0x0c098e04 */
if(!s->budget--) { s->failed_pc=0x0c098e04u; return 0; }
r[7]=r[7]&255u;
goto P_0c098e06;
P_0c098e06: /* original 7701, guest PC 0x0c098e06 */
if(!s->budget--) { s->failed_pc=0x0c098e06u; return 0; }
r[7]+=0x00000001u;
goto P_0c098e08;
P_0c098e08: /* original 0e74, guest PC 0x0c098e08 */
if(!s->budget--) { s->failed_pc=0x0c098e08u; return 0; }
write(ram,r[14]+r[0],r[7],1);
goto P_0c098e0a;
P_0c098e0a: /* original e046, guest PC 0x0c098e0a */
if(!s->budget--) { s->failed_pc=0x0c098e0au; return 0; }
r[0]=0x00000046u;
goto P_0c098e0c;
P_0c098e0c: /* original 005d, guest PC 0x0c098e0c */
if(!s->budget--) { s->failed_pc=0x0c098e0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c098e0e;
P_0c098e0e: /* original 3763, guest PC 0x0c098e0e */
if(!s->budget--) { s->failed_pc=0x0c098e0eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[6])!=0);
goto P_0c098e10;
P_0c098e10: /* original 53f4, guest PC 0x0c098e10 */
if(!s->budget--) { s->failed_pc=0x0c098e10u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c098e12;
P_0c098e12: /* original 8131, guest PC 0x0c098e12 */
if(!s->budget--) { s->failed_pc=0x0c098e12u; return 0; }
write(ram,r[3]+2,r[0],2);
goto P_0c098e14;
P_0c098e14: /* original 8f3d, guest PC 0x0c098e14 */
if(!s->budget--) { s->failed_pc=0x0c098e14u; return 0; }
cond=r[17]&1u;
r[8]=0x00000000u;
if(!cond) { goto P_0c098e92; }
goto P_0c098e18;
P_0c098e16: /* original e800, guest PC 0x0c098e16 */
if(!s->budget--) { s->failed_pc=0x0c098e16u; return 0; }
r[8]=0x00000000u;
goto P_0c098e18;
P_0c098e18: /* original 60b3, guest PC 0x0c098e18 */
if(!s->budget--) { s->failed_pc=0x0c098e18u; return 0; }
r[0]=r[11];
goto P_0c098e1a;
P_0c098e1a: /* original 8803, guest PC 0x0c098e1a */
if(!s->budget--) { s->failed_pc=0x0c098e1au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c098e1c;
P_0c098e1c: /* original 8b0c, guest PC 0x0c098e1c */
if(!s->budget--) { s->failed_pc=0x0c098e1cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098e38; }
goto P_0c098e1e;
P_0c098e1e: /* original e361, guest PC 0x0c098e1e */
if(!s->budget--) { s->failed_pc=0x0c098e1eu; return 0; }
r[3]=0x00000061u;
goto P_0c098e20;
P_0c098e20: /* original 927e, guest PC 0x0c098e20 */
if(!s->budget--) { s->failed_pc=0x0c098e20u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098f20u,2);
goto P_0c098e22;
P_0c098e22: /* original 335c, guest PC 0x0c098e22 */
if(!s->budget--) { s->failed_pc=0x0c098e22u; return 0; }
r[3]+=r[5];
goto P_0c098e24;
P_0c098e24: /* original 50f5, guest PC 0x0c098e24 */
if(!s->budget--) { s->failed_pc=0x0c098e24u; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c098e26;
P_0c098e26: /* original 6330, guest PC 0x0c098e26 */
if(!s->budget--) { s->failed_pc=0x0c098e26u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
goto P_0c098e28;
P_0c098e28: /* original 320c, guest PC 0x0c098e28 */
if(!s->budget--) { s->failed_pc=0x0c098e28u; return 0; }
r[2]+=r[0];
goto P_0c098e2a;
P_0c098e2a: /* original f29d, guest PC 0x0c098e2a */
if(!s->budget--) { s->failed_pc=0x0c098e2au; return 0; }
fr[2]=0x3f800000u;
goto P_0c098e2c;
P_0c098e2c: /* original 633c, guest PC 0x0c098e2c */
if(!s->budget--) { s->failed_pc=0x0c098e2cu; return 0; }
r[3]=r[3]&255u;
goto P_0c098e2e;
P_0c098e2e: /* original 4308, guest PC 0x0c098e2e */
if(!s->budget--) { s->failed_pc=0x0c098e2eu; return 0; }
r[3]<<=2;
goto P_0c098e30;
P_0c098e30: /* original 332c, guest PC 0x0c098e30 */
if(!s->budget--) { s->failed_pc=0x0c098e30u; return 0; }
r[3]+=r[2];
goto P_0c098e32;
P_0c098e32: /* original f338, guest PC 0x0c098e32 */
if(!s->budget--) { s->failed_pc=0x0c098e32u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c098e34;
P_0c098e34: /* original f320, guest PC 0x0c098e34 */
if(!s->budget--) { s->failed_pc=0x0c098e34u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c098e36;
P_0c098e36: /* original f33a, guest PC 0x0c098e36 */
if(!s->budget--) { s->failed_pc=0x0c098e36u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c098e38;
P_0c098e38: /* original e100, guest PC 0x0c098e38 */
if(!s->budget--) { s->failed_pc=0x0c098e38u; return 0; }
r[1]=0x00000000u;
goto P_0c098e3a;
P_0c098e3a: /* original d33e, guest PC 0x0c098e3a */
if(!s->budget--) { s->failed_pc=0x0c098e3au; return 0; }
r[3]=read(ram,0x0c098f34u,4);
goto P_0c098e3c;
P_0c098e3c: /* original e01d, guest PC 0x0c098e3c */
if(!s->budget--) { s->failed_pc=0x0c098e3cu; return 0; }
r[0]=0x0000001du;
goto P_0c098e3e;
P_0c098e3e: /* original d23e, guest PC 0x0c098e3e */
if(!s->budget--) { s->failed_pc=0x0c098e3eu; return 0; }
r[2]=read(ram,0x0c098f38u,4);
goto P_0c098e40;
P_0c098e40: /* original 0e14, guest PC 0x0c098e40 */
if(!s->budget--) { s->failed_pc=0x0c098e40u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c098e42;
P_0c098e42: /* original 7075, guest PC 0x0c098e42 */
if(!s->budget--) { s->failed_pc=0x0c098e42u; return 0; }
r[0]+=0x00000075u;
goto P_0c098e44;
P_0c098e44: /* original 2d3b, guest PC 0x0c098e44 */
if(!s->budget--) { s->failed_pc=0x0c098e44u; return 0; }
r[13]|=r[3];
goto P_0c098e46;
P_0c098e46: /* original 55cb, guest PC 0x0c098e46 */
if(!s->budget--) { s->failed_pc=0x0c098e46u; return 0; }
r[5]=read(ram,r[12]+44,4);
goto P_0c098e48;
P_0c098e48: /* original 2d29, guest PC 0x0c098e48 */
if(!s->budget--) { s->failed_pc=0x0c098e48u; return 0; }
r[13]&=r[2];
goto P_0c098e4a;
P_0c098e4a: /* original 6313, guest PC 0x0c098e4a */
if(!s->budget--) { s->failed_pc=0x0c098e4au; return 0; }
r[3]=r[1];
goto P_0c098e4c;
P_0c098e4c: /* original 2512, guest PC 0x0c098e4c */
if(!s->budget--) { s->failed_pc=0x0c098e4cu; return 0; }
write(ram,r[5],r[1],4);
goto P_0c098e4e;
P_0c098e4e: /* original 03ec, guest PC 0x0c098e4e */
if(!s->budget--) { s->failed_pc=0x0c098e4eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098e50;
P_0c098e50: /* original 9068, guest PC 0x0c098e50 */
if(!s->budget--) { s->failed_pc=0x0c098e50u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098f24u,2);
goto P_0c098e52;
P_0c098e52: /* original 9166, guest PC 0x0c098e52 */
if(!s->budget--) { s->failed_pc=0x0c098e52u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098f22u,2);
goto P_0c098e54;
P_0c098e54: /* original 0e34, guest PC 0x0c098e54 */
if(!s->budget--) { s->failed_pc=0x0c098e54u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c098e56;
P_0c098e56: /* original e02a, guest PC 0x0c098e56 */
if(!s->budget--) { s->failed_pc=0x0c098e56u; return 0; }
r[0]=0x0000002au;
goto P_0c098e58;
P_0c098e58: /* original 02ec, guest PC 0x0c098e58 */
if(!s->budget--) { s->failed_pc=0x0c098e58u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098e5a;
P_0c098e5a: /* original 9064, guest PC 0x0c098e5a */
if(!s->budget--) { s->failed_pc=0x0c098e5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098f26u,2);
goto P_0c098e5c;
P_0c098e5c: /* original 0e24, guest PC 0x0c098e5c */
if(!s->budget--) { s->failed_pc=0x0c098e5cu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c098e5e;
P_0c098e5e: /* original 60b3, guest PC 0x0c098e5e */
if(!s->budget--) { s->failed_pc=0x0c098e5eu; return 0; }
r[0]=r[11];
goto P_0c098e60;
P_0c098e60: /* original 8803, guest PC 0x0c098e60 */
if(!s->budget--) { s->failed_pc=0x0c098e60u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c098e62;
P_0c098e62: /* original 8f16, guest PC 0x0c098e62 */
if(!s->budget--) { s->failed_pc=0x0c098e62u; return 0; }
cond=r[17]&1u;
r[13]&=r[1];
if(!cond) { goto P_0c098e92; }
goto P_0c098e66;
P_0c098e64: /* original 2d19, guest PC 0x0c098e64 */
if(!s->budget--) { s->failed_pc=0x0c098e64u; return 0; }
r[13]&=r[1];
goto P_0c098e66;
P_0c098e66: /* original 905f, guest PC 0x0c098e66 */
if(!s->budget--) { s->failed_pc=0x0c098e66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098f28u,2);
goto P_0c098e68;
P_0c098e68: /* original 00ec, guest PC 0x0c098e68 */
if(!s->budget--) { s->failed_pc=0x0c098e68u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098e6a;
P_0c098e6a: /* original 8801, guest PC 0x0c098e6a */
if(!s->budget--) { s->failed_pc=0x0c098e6au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c098e6c;
P_0c098e6c: /* original 8901, guest PC 0x0c098e6c */
if(!s->budget--) { s->failed_pc=0x0c098e6cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098e72; }
goto P_0c098e6e;
P_0c098e6e: /* original 935c, guest PC 0x0c098e6e */
if(!s->budget--) { s->failed_pc=0x0c098e6eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098f2au,2);
goto P_0c098e70;
P_0c098e70: /* original 2d3b, guest PC 0x0c098e70 */
if(!s->budget--) { s->failed_pc=0x0c098e70u; return 0; }
r[13]|=r[3];
goto P_0c098e72;
P_0c098e72: /* original 60f2, guest PC 0x0c098e72 */
if(!s->budget--) { s->failed_pc=0x0c098e72u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c098e74;
P_0c098e74: /* original 8801, guest PC 0x0c098e74 */
if(!s->budget--) { s->failed_pc=0x0c098e74u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c098e76;
P_0c098e76: /* original 8905, guest PC 0x0c098e76 */
if(!s->budget--) { s->failed_pc=0x0c098e76u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098e84; }
goto P_0c098e78;
P_0c098e78: /* original 9056, guest PC 0x0c098e78 */
if(!s->budget--) { s->failed_pc=0x0c098e78u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098f28u,2);
goto P_0c098e7a;
P_0c098e7a: /* original 0e44, guest PC 0x0c098e7a */
if(!s->budget--) { s->failed_pc=0x0c098e7au; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c098e7c;
P_0c098e7c: /* original e02a, guest PC 0x0c098e7c */
if(!s->budget--) { s->failed_pc=0x0c098e7cu; return 0; }
r[0]=0x0000002au;
goto P_0c098e7e;
P_0c098e7e: /* original 0e44, guest PC 0x0c098e7e */
if(!s->budget--) { s->failed_pc=0x0c098e7eu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c098e80;
P_0c098e80: /* original a006, guest PC 0x0c098e80 */
if(!s->budget--) { s->failed_pc=0x0c098e80u; return 0; }
r[0]+=0x0000005au;
goto P_0c098e90;
P_0c098e82: /* original 705a, guest PC 0x0c098e82 */
if(!s->budget--) { s->failed_pc=0x0c098e82u; return 0; }
r[0]+=0x0000005au;
goto P_0c098e84;
P_0c098e84: /* original 9052, guest PC 0x0c098e84 */
if(!s->budget--) { s->failed_pc=0x0c098e84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098f2cu,2);
goto P_0c098e86;
P_0c098e86: /* original 04ee, guest PC 0x0c098e86 */
if(!s->budget--) { s->failed_pc=0x0c098e86u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c098e88;
P_0c098e88: /* original 9051, guest PC 0x0c098e88 */
if(!s->budget--) { s->failed_pc=0x0c098e88u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098f2eu,2);
goto P_0c098e8a;
P_0c098e8a: /* original 7401, guest PC 0x0c098e8a */
if(!s->budget--) { s->failed_pc=0x0c098e8au; return 0; }
r[4]+=0x00000001u;
goto P_0c098e8c;
P_0c098e8c: /* original 0e46, guest PC 0x0c098e8c */
if(!s->budget--) { s->failed_pc=0x0c098e8cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c098e8e;
P_0c098e8e: /* original 904d, guest PC 0x0c098e8e */
if(!s->budget--) { s->failed_pc=0x0c098e8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098f2cu,2);
goto P_0c098e90;
P_0c098e90: /* original 0e46, guest PC 0x0c098e90 */
if(!s->budget--) { s->failed_pc=0x0c098e90u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c098e92;
P_0c098e92: /* original 53c4, guest PC 0x0c098e92 */
if(!s->budget--) { s->failed_pc=0x0c098e92u; return 0; }
r[3]=read(ram,r[12]+16,4);
goto P_0c098e94;
P_0c098e94: /* original 2f32, guest PC 0x0c098e94 */
if(!s->budget--) { s->failed_pc=0x0c098e94u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c098e96;
P_0c098e96: /* original a05b, guest PC 0x0c098e96 */
if(!s->budget--) { s->failed_pc=0x0c098e96u; return 0; }
r[4]=read(ram,r[12]+20,4);
goto P_0c098f50;
P_0c098e98: /* original 54c5, guest PC 0x0c098e98 */
if(!s->budget--) { s->failed_pc=0x0c098e98u; return 0; }
r[4]=read(ram,r[12]+20,4);
goto P_0c098e9a;
P_0c098e9a: /* original e01b, guest PC 0x0c098e9a */
if(!s->budget--) { s->failed_pc=0x0c098e9au; return 0; }
r[0]=0x0000001bu;
goto P_0c098e9c;
P_0c098e9c: /* original 05ec, guest PC 0x0c098e9c */
if(!s->budget--) { s->failed_pc=0x0c098e9cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098e9e;
P_0c098e9e: /* original 655c, guest PC 0x0c098e9e */
if(!s->budget--) { s->failed_pc=0x0c098e9eu; return 0; }
r[5]=r[5]&255u;
goto P_0c098ea0;
P_0c098ea0: /* original 7501, guest PC 0x0c098ea0 */
if(!s->budget--) { s->failed_pc=0x0c098ea0u; return 0; }
r[5]+=0x00000001u;
goto P_0c098ea2;
P_0c098ea2: /* original 0e54, guest PC 0x0c098ea2 */
if(!s->budget--) { s->failed_pc=0x0c098ea2u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c098ea4;
P_0c098ea4: /* original e046, guest PC 0x0c098ea4 */
if(!s->budget--) { s->failed_pc=0x0c098ea4u; return 0; }
r[0]=0x00000046u;
goto P_0c098ea6;
P_0c098ea6: /* original 007d, guest PC 0x0c098ea6 */
if(!s->budget--) { s->failed_pc=0x0c098ea6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[7]+r[0],2);
goto P_0c098ea8;
P_0c098ea8: /* original 3563, guest PC 0x0c098ea8 */
if(!s->budget--) { s->failed_pc=0x0c098ea8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c098eaa;
P_0c098eaa: /* original 53f4, guest PC 0x0c098eaa */
if(!s->budget--) { s->failed_pc=0x0c098eaau; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c098eac;
P_0c098eac: /* original 8131, guest PC 0x0c098eac */
if(!s->budget--) { s->failed_pc=0x0c098eacu; return 0; }
write(ram,r[3]+2,r[0],2);
goto P_0c098eae;
P_0c098eae: /* original 8f4c, guest PC 0x0c098eae */
if(!s->budget--) { s->failed_pc=0x0c098eaeu; return 0; }
cond=r[17]&1u;
r[8]=r[4];
if(!cond) { goto P_0c098f4a; }
goto P_0c098eb2;
P_0c098eb0: /* original 6843, guest PC 0x0c098eb0 */
if(!s->budget--) { s->failed_pc=0x0c098eb0u; return 0; }
r[8]=r[4];
goto P_0c098eb2;
P_0c098eb2: /* original 60b3, guest PC 0x0c098eb2 */
if(!s->budget--) { s->failed_pc=0x0c098eb2u; return 0; }
r[0]=r[11];
goto P_0c098eb4;
P_0c098eb4: /* original 8803, guest PC 0x0c098eb4 */
if(!s->budget--) { s->failed_pc=0x0c098eb4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c098eb6;
P_0c098eb6: /* original 8b0c, guest PC 0x0c098eb6 */
if(!s->budget--) { s->failed_pc=0x0c098eb6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098ed2; }
goto P_0c098eb8;
P_0c098eb8: /* original e361, guest PC 0x0c098eb8 */
if(!s->budget--) { s->failed_pc=0x0c098eb8u; return 0; }
r[3]=0x00000061u;
goto P_0c098eba;
P_0c098eba: /* original 9231, guest PC 0x0c098eba */
if(!s->budget--) { s->failed_pc=0x0c098ebau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098f20u,2);
goto P_0c098ebc;
P_0c098ebc: /* original 337c, guest PC 0x0c098ebc */
if(!s->budget--) { s->failed_pc=0x0c098ebcu; return 0; }
r[3]+=r[7];
goto P_0c098ebe;
P_0c098ebe: /* original 50f5, guest PC 0x0c098ebe */
if(!s->budget--) { s->failed_pc=0x0c098ebeu; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c098ec0;
P_0c098ec0: /* original 6330, guest PC 0x0c098ec0 */
if(!s->budget--) { s->failed_pc=0x0c098ec0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
goto P_0c098ec2;
P_0c098ec2: /* original 320c, guest PC 0x0c098ec2 */
if(!s->budget--) { s->failed_pc=0x0c098ec2u; return 0; }
r[2]+=r[0];
goto P_0c098ec4;
P_0c098ec4: /* original f29d, guest PC 0x0c098ec4 */
if(!s->budget--) { s->failed_pc=0x0c098ec4u; return 0; }
fr[2]=0x3f800000u;
goto P_0c098ec6;
P_0c098ec6: /* original 633c, guest PC 0x0c098ec6 */
if(!s->budget--) { s->failed_pc=0x0c098ec6u; return 0; }
r[3]=r[3]&255u;
goto P_0c098ec8;
P_0c098ec8: /* original 4308, guest PC 0x0c098ec8 */
if(!s->budget--) { s->failed_pc=0x0c098ec8u; return 0; }
r[3]<<=2;
goto P_0c098eca;
P_0c098eca: /* original 332c, guest PC 0x0c098eca */
if(!s->budget--) { s->failed_pc=0x0c098ecau; return 0; }
r[3]+=r[2];
goto P_0c098ecc;
P_0c098ecc: /* original f338, guest PC 0x0c098ecc */
if(!s->budget--) { s->failed_pc=0x0c098eccu; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c098ece;
P_0c098ece: /* original f320, guest PC 0x0c098ece */
if(!s->budget--) { s->failed_pc=0x0c098eceu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c098ed0;
P_0c098ed0: /* original f33a, guest PC 0x0c098ed0 */
if(!s->budget--) { s->failed_pc=0x0c098ed0u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c098ed2;
P_0c098ed2: /* original d318, guest PC 0x0c098ed2 */
if(!s->budget--) { s->failed_pc=0x0c098ed2u; return 0; }
r[3]=read(ram,0x0c098f34u,4);
goto P_0c098ed4;
P_0c098ed4: /* original e01d, guest PC 0x0c098ed4 */
if(!s->budget--) { s->failed_pc=0x0c098ed4u; return 0; }
r[0]=0x0000001du;
goto P_0c098ed6;
P_0c098ed6: /* original d218, guest PC 0x0c098ed6 */
if(!s->budget--) { s->failed_pc=0x0c098ed6u; return 0; }
r[2]=read(ram,0x0c098f38u,4);
goto P_0c098ed8;
P_0c098ed8: /* original 2d3b, guest PC 0x0c098ed8 */
if(!s->budget--) { s->failed_pc=0x0c098ed8u; return 0; }
r[13]|=r[3];
goto P_0c098eda;
P_0c098eda: /* original 0e44, guest PC 0x0c098eda */
if(!s->budget--) { s->failed_pc=0x0c098edau; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c098edc;
P_0c098edc: /* original 55ca, guest PC 0x0c098edc */
if(!s->budget--) { s->failed_pc=0x0c098edcu; return 0; }
r[5]=read(ram,r[12]+40,4);
goto P_0c098ede;
P_0c098ede: /* original e300, guest PC 0x0c098ede */
if(!s->budget--) { s->failed_pc=0x0c098edeu; return 0; }
r[3]=0x00000000u;
goto P_0c098ee0;
P_0c098ee0: /* original 7075, guest PC 0x0c098ee0 */
if(!s->budget--) { s->failed_pc=0x0c098ee0u; return 0; }
r[0]+=0x00000075u;
goto P_0c098ee2;
P_0c098ee2: /* original 2532, guest PC 0x0c098ee2 */
if(!s->budget--) { s->failed_pc=0x0c098ee2u; return 0; }
write(ram,r[5],r[3],4);
goto P_0c098ee4;
P_0c098ee4: /* original 2d29, guest PC 0x0c098ee4 */
if(!s->budget--) { s->failed_pc=0x0c098ee4u; return 0; }
r[13]&=r[2];
goto P_0c098ee6;
P_0c098ee6: /* original 03ec, guest PC 0x0c098ee6 */
if(!s->budget--) { s->failed_pc=0x0c098ee6u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098ee8;
P_0c098ee8: /* original 901c, guest PC 0x0c098ee8 */
if(!s->budget--) { s->failed_pc=0x0c098ee8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098f24u,2);
goto P_0c098eea;
P_0c098eea: /* original 9121, guest PC 0x0c098eea */
if(!s->budget--) { s->failed_pc=0x0c098eeau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098f30u,2);
goto P_0c098eec;
P_0c098eec: /* original 0e34, guest PC 0x0c098eec */
if(!s->budget--) { s->failed_pc=0x0c098eecu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c098eee;
P_0c098eee: /* original e02a, guest PC 0x0c098eee */
if(!s->budget--) { s->failed_pc=0x0c098eeeu; return 0; }
r[0]=0x0000002au;
goto P_0c098ef0;
P_0c098ef0: /* original 02ec, guest PC 0x0c098ef0 */
if(!s->budget--) { s->failed_pc=0x0c098ef0u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098ef2;
P_0c098ef2: /* original 9018, guest PC 0x0c098ef2 */
if(!s->budget--) { s->failed_pc=0x0c098ef2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098f26u,2);
goto P_0c098ef4;
P_0c098ef4: /* original 0e24, guest PC 0x0c098ef4 */
if(!s->budget--) { s->failed_pc=0x0c098ef4u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c098ef6;
P_0c098ef6: /* original 60b3, guest PC 0x0c098ef6 */
if(!s->budget--) { s->failed_pc=0x0c098ef6u; return 0; }
r[0]=r[11];
goto P_0c098ef8;
P_0c098ef8: /* original 8803, guest PC 0x0c098ef8 */
if(!s->budget--) { s->failed_pc=0x0c098ef8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c098efa;
P_0c098efa: /* original 8f26, guest PC 0x0c098efa */
if(!s->budget--) { s->failed_pc=0x0c098efau; return 0; }
cond=r[17]&1u;
r[13]&=r[1];
if(!cond) { goto P_0c098f4a; }
goto P_0c098efe;
P_0c098efc: /* original 2d19, guest PC 0x0c098efc */
if(!s->budget--) { s->failed_pc=0x0c098efcu; return 0; }
r[13]&=r[1];
goto P_0c098efe;
P_0c098efe: /* original 9013, guest PC 0x0c098efe */
if(!s->budget--) { s->failed_pc=0x0c098efeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098f28u,2);
goto P_0c098f00;
P_0c098f00: /* original 00ec, guest PC 0x0c098f00 */
if(!s->budget--) { s->failed_pc=0x0c098f00u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098f02;
P_0c098f02: /* original 8802, guest PC 0x0c098f02 */
if(!s->budget--) { s->failed_pc=0x0c098f02u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c098f04;
P_0c098f04: /* original 8901, guest PC 0x0c098f04 */
if(!s->budget--) { s->failed_pc=0x0c098f04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098f0a; }
goto P_0c098f06;
P_0c098f06: /* original 9310, guest PC 0x0c098f06 */
if(!s->budget--) { s->failed_pc=0x0c098f06u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098f2au,2);
goto P_0c098f08;
P_0c098f08: /* original 2d3b, guest PC 0x0c098f08 */
if(!s->budget--) { s->failed_pc=0x0c098f08u; return 0; }
r[13]|=r[3];
goto P_0c098f0a;
P_0c098f0a: /* original 60f2, guest PC 0x0c098f0a */
if(!s->budget--) { s->failed_pc=0x0c098f0au; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c098f0c;
P_0c098f0c: /* original 8802, guest PC 0x0c098f0c */
if(!s->budget--) { s->failed_pc=0x0c098f0cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c098f0e;
P_0c098f0e: /* original 8915, guest PC 0x0c098f0e */
if(!s->budget--) { s->failed_pc=0x0c098f0eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098f3c; }
goto P_0c098f10;
P_0c098f10: /* original 900a, guest PC 0x0c098f10 */
if(!s->budget--) { s->failed_pc=0x0c098f10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c098f28u,2);
goto P_0c098f12;
P_0c098f12: /* original e302, guest PC 0x0c098f12 */
if(!s->budget--) { s->failed_pc=0x0c098f12u; return 0; }
r[3]=0x00000002u;
goto P_0c098f14;
P_0c098f14: /* original 6233, guest PC 0x0c098f14 */
if(!s->budget--) { s->failed_pc=0x0c098f14u; return 0; }
r[2]=r[3];
goto P_0c098f16;
P_0c098f16: /* original 0e34, guest PC 0x0c098f16 */
if(!s->budget--) { s->failed_pc=0x0c098f16u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c098f18;
P_0c098f18: /* original e02a, guest PC 0x0c098f18 */
if(!s->budget--) { s->failed_pc=0x0c098f18u; return 0; }
r[0]=0x0000002au;
goto P_0c098f1a;
P_0c098f1a: /* original 0e24, guest PC 0x0c098f1a */
if(!s->budget--) { s->failed_pc=0x0c098f1au; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c098f1c;
P_0c098f1c: /* original a014, guest PC 0x0c098f1c */
if(!s->budget--) { s->failed_pc=0x0c098f1cu; return 0; }
r[0]+=0x0000005au;
goto P_0c098f48;
P_0c098f1e: /* original 705a, guest PC 0x0c098f1e */
if(!s->budget--) { s->failed_pc=0x0c098f1eu; return 0; }
r[0]+=0x0000005au;
if(!vf3_matrix_family(0x0c098f20u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c098f20u; return 0; } return 1;
P_0c098f3c: /* original 907a, guest PC 0x0c098f3c */
if(!s->budget--) { s->failed_pc=0x0c098f3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099034u,2);
goto P_0c098f3e;
P_0c098f3e: /* original 04ee, guest PC 0x0c098f3e */
if(!s->budget--) { s->failed_pc=0x0c098f3eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c098f40;
P_0c098f40: /* original 9079, guest PC 0x0c098f40 */
if(!s->budget--) { s->failed_pc=0x0c098f40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099036u,2);
goto P_0c098f42;
P_0c098f42: /* original 7401, guest PC 0x0c098f42 */
if(!s->budget--) { s->failed_pc=0x0c098f42u; return 0; }
r[4]+=0x00000001u;
goto P_0c098f44;
P_0c098f44: /* original 0e46, guest PC 0x0c098f44 */
if(!s->budget--) { s->failed_pc=0x0c098f44u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c098f46;
P_0c098f46: /* original 9075, guest PC 0x0c098f46 */
if(!s->budget--) { s->failed_pc=0x0c098f46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099034u,2);
goto P_0c098f48;
P_0c098f48: /* original 0e46, guest PC 0x0c098f48 */
if(!s->budget--) { s->failed_pc=0x0c098f48u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c098f4a;
P_0c098f4a: /* original 53c5, guest PC 0x0c098f4a */
if(!s->budget--) { s->failed_pc=0x0c098f4au; return 0; }
r[3]=read(ram,r[12]+20,4);
goto P_0c098f4c;
P_0c098f4c: /* original 2f32, guest PC 0x0c098f4c */
if(!s->budget--) { s->failed_pc=0x0c098f4cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c098f4e;
P_0c098f4e: /* original 54c4, guest PC 0x0c098f4e */
if(!s->budget--) { s->failed_pc=0x0c098f4eu; return 0; }
r[4]=read(ram,r[12]+16,4);
goto P_0c098f50;
P_0c098f50: /* original 9072, guest PC 0x0c098f50 */
if(!s->budget--) { s->failed_pc=0x0c098f50u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099038u,2);
goto P_0c098f52;
P_0c098f52: /* original 63f2, guest PC 0x0c098f52 */
if(!s->budget--) { s->failed_pc=0x0c098f52u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c098f54;
P_0c098f54: /* original 0e36, guest PC 0x0c098f54 */
if(!s->budget--) { s->failed_pc=0x0c098f54u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c098f56;
P_0c098f56: /* original 7004, guest PC 0x0c098f56 */
if(!s->budget--) { s->failed_pc=0x0c098f56u; return 0; }
r[0]+=0x00000004u;
goto P_0c098f58;
P_0c098f58: /* original 0e46, guest PC 0x0c098f58 */
if(!s->budget--) { s->failed_pc=0x0c098f58u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c098f5a;
P_0c098f5a: /* original d339, guest PC 0x0c098f5a */
if(!s->budget--) { s->failed_pc=0x0c098f5au; return 0; }
r[3]=read(ram,0x0c099040u,4);
goto P_0c098f5c;
P_0c098f5c: /* original 54f1, guest PC 0x0c098f5c */
if(!s->budget--) { s->failed_pc=0x0c098f5cu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c098f5e;
P_0c098f5e: /* original 430b, guest PC 0x0c098f5e */
if(!s->budget--) { s->failed_pc=0x0c098f5eu; return 0; }
target=r[3];
r[16]=code_base|0x0c098f62u;
r[4]+=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098f62u) { target=s->pc; goto dispatch; }
goto P_0c098f62;
P_0c098f60: /* original 7412, guest PC 0x0c098f60 */
if(!s->budget--) { s->failed_pc=0x0c098f60u; return 0; }
r[4]+=0x00000012u;
goto P_0c098f62;
P_0c098f62: /* original 600c, guest PC 0x0c098f62 */
if(!s->budget--) { s->failed_pc=0x0c098f62u; return 0; }
r[0]=r[0]&255u;
goto P_0c098f64;
P_0c098f64: /* original 6493, guest PC 0x0c098f64 */
if(!s->budget--) { s->failed_pc=0x0c098f64u; return 0; }
r[4]=r[9];
goto P_0c098f66;
P_0c098f66: /* original 1f01, guest PC 0x0c098f66 */
if(!s->budget--) { s->failed_pc=0x0c098f66u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c098f68;
P_0c098f68: /* original 6083, guest PC 0x0c098f68 */
if(!s->budget--) { s->failed_pc=0x0c098f68u; return 0; }
r[0]=r[8];
goto P_0c098f6a;
P_0c098f6a: /* original 8802, guest PC 0x0c098f6a */
if(!s->budget--) { s->failed_pc=0x0c098f6au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c098f6c;
P_0c098f6c: /* original 6593, guest PC 0x0c098f6c */
if(!s->budget--) { s->failed_pc=0x0c098f6cu; return 0; }
r[5]=r[9];
goto P_0c098f6e;
P_0c098f6e: /* original 8f04, guest PC 0x0c098f6e */
if(!s->budget--) { s->failed_pc=0x0c098f6eu; return 0; }
cond=r[17]&1u;
r[5]+=0xffffffffu;
if(!cond) { goto P_0c098f7a; }
goto P_0c098f72;
P_0c098f70: /* original 75ff, guest PC 0x0c098f70 */
if(!s->budget--) { s->failed_pc=0x0c098f70u; return 0; }
r[5]+=0xffffffffu;
goto P_0c098f72;
P_0c098f72: /* original 52e2, guest PC 0x0c098f72 */
if(!s->budget--) { s->failed_pc=0x0c098f72u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c098f74;
P_0c098f74: /* original d333, guest PC 0x0c098f74 */
if(!s->budget--) { s->failed_pc=0x0c098f74u; return 0; }
r[3]=read(ram,0x0c099044u,4);
goto P_0c098f76;
P_0c098f76: /* original 2238, guest PC 0x0c098f76 */
if(!s->budget--) { s->failed_pc=0x0c098f76u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c098f78;
P_0c098f78: /* original 891b, guest PC 0x0c098f78 */
if(!s->budget--) { s->failed_pc=0x0c098f78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098fb2; }
goto P_0c098f7a;
P_0c098f7a: /* original 2448, guest PC 0x0c098f7a */
if(!s->budget--) { s->failed_pc=0x0c098f7au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c098f7c;
P_0c098f7c: /* original 8b0b, guest PC 0x0c098f7c */
if(!s->budget--) { s->failed_pc=0x0c098f7cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098f96; }
goto P_0c098f7e;
P_0c098f7e: /* original 64f2, guest PC 0x0c098f7e */
if(!s->budget--) { s->failed_pc=0x0c098f7eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c098f80;
P_0c098f80: /* original e046, guest PC 0x0c098f80 */
if(!s->budget--) { s->failed_pc=0x0c098f80u; return 0; }
r[0]=0x00000046u;
goto P_0c098f82;
P_0c098f82: /* original 034d, guest PC 0x0c098f82 */
if(!s->budget--) { s->failed_pc=0x0c098f82u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c098f84;
P_0c098f84: /* original 9059, guest PC 0x0c098f84 */
if(!s->budget--) { s->failed_pc=0x0c098f84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09903au,2);
goto P_0c098f86;
P_0c098f86: /* original 633d, guest PC 0x0c098f86 */
if(!s->budget--) { s->failed_pc=0x0c098f86u; return 0; }
r[3]=r[3]&65535u;
goto P_0c098f88;
P_0c098f88: /* original 024d, guest PC 0x0c098f88 */
if(!s->budget--) { s->failed_pc=0x0c098f88u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c098f8a;
P_0c098f8a: /* original 3320, guest PC 0x0c098f8a */
if(!s->budget--) { s->failed_pc=0x0c098f8au; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c098f8c;
P_0c098f8c: /* original 8b01, guest PC 0x0c098f8c */
if(!s->budget--) { s->failed_pc=0x0c098f8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098f92; }
goto P_0c098f8e;
P_0c098f8e: /* original a011, guest PC 0x0c098f8e */
if(!s->budget--) { s->failed_pc=0x0c098f8eu; return 0; }
r[4]=0x0000002eu;
goto P_0c098fb4;
P_0c098f90: /* original e42e, guest PC 0x0c098f90 */
if(!s->budget--) { s->failed_pc=0x0c098f90u; return 0; }
r[4]=0x0000002eu;
goto P_0c098f92;
P_0c098f92: /* original a00f, guest PC 0x0c098f92 */
if(!s->budget--) { s->failed_pc=0x0c098f92u; return 0; }
r[4]=0x00000032u;
goto P_0c098fb4;
P_0c098f94: /* original e432, guest PC 0x0c098f94 */
if(!s->budget--) { s->failed_pc=0x0c098f94u; return 0; }
r[4]=0x00000032u;
goto P_0c098f96;
P_0c098f96: /* original 2558, guest PC 0x0c098f96 */
if(!s->budget--) { s->failed_pc=0x0c098f96u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c098f98;
P_0c098f98: /* original 8b05, guest PC 0x0c098f98 */
if(!s->budget--) { s->failed_pc=0x0c098f98u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098fa6; }
goto P_0c098f9a;
P_0c098f9a: /* original 52f1, guest PC 0x0c098f9a */
if(!s->budget--) { s->failed_pc=0x0c098f9au; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c098f9c;
P_0c098f9c: /* original 2228, guest PC 0x0c098f9c */
if(!s->budget--) { s->failed_pc=0x0c098f9cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c098f9e;
P_0c098f9e: /* original 8d09, guest PC 0x0c098f9e */
if(!s->budget--) { s->failed_pc=0x0c098f9eu; return 0; }
cond=r[17]&1u;
r[4]=0x00000038u;
if(cond) { goto P_0c098fb4; }
goto P_0c098fa2;
P_0c098fa0: /* original e438, guest PC 0x0c098fa0 */
if(!s->budget--) { s->failed_pc=0x0c098fa0u; return 0; }
r[4]=0x00000038u;
goto P_0c098fa2;
P_0c098fa2: /* original a007, guest PC 0x0c098fa2 */
if(!s->budget--) { s->failed_pc=0x0c098fa2u; return 0; }
r[4]=0x00000035u;
goto P_0c098fb4;
P_0c098fa4: /* original e435, guest PC 0x0c098fa4 */
if(!s->budget--) { s->failed_pc=0x0c098fa4u; return 0; }
r[4]=0x00000035u;
goto P_0c098fa6;
P_0c098fa6: /* original 53f1, guest PC 0x0c098fa6 */
if(!s->budget--) { s->failed_pc=0x0c098fa6u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c098fa8;
P_0c098fa8: /* original 2338, guest PC 0x0c098fa8 */
if(!s->budget--) { s->failed_pc=0x0c098fa8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c098faa;
P_0c098faa: /* original 8d03, guest PC 0x0c098faa */
if(!s->budget--) { s->failed_pc=0x0c098faau; return 0; }
cond=r[17]&1u;
r[4]=0x00000039u;
if(cond) { goto P_0c098fb4; }
goto P_0c098fae;
P_0c098fac: /* original e439, guest PC 0x0c098fac */
if(!s->budget--) { s->failed_pc=0x0c098facu; return 0; }
r[4]=0x00000039u;
goto P_0c098fae;
P_0c098fae: /* original a001, guest PC 0x0c098fae */
if(!s->budget--) { s->failed_pc=0x0c098faeu; return 0; }
r[4]=0x00000037u;
goto P_0c098fb4;
P_0c098fb0: /* original e437, guest PC 0x0c098fb0 */
if(!s->budget--) { s->failed_pc=0x0c098fb0u; return 0; }
r[4]=0x00000037u;
goto P_0c098fb2;
P_0c098fb2: /* original e42d, guest PC 0x0c098fb2 */
if(!s->budget--) { s->failed_pc=0x0c098fb2u; return 0; }
r[4]=0x0000002du;
goto P_0c098fb4;
P_0c098fb4: /* original 4a0b, guest PC 0x0c098fb4 */
if(!s->budget--) { s->failed_pc=0x0c098fb4u; return 0; }
target=r[10];
r[16]=code_base|0x0c098fb8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c098fb8u) { target=s->pc; goto dispatch; }
goto P_0c098fb8;
P_0c098fb6: /* original 0009, guest PC 0x0c098fb6 */
if(!s->budget--) { s->failed_pc=0x0c098fb6u; return 0; }
goto P_0c098fb8;
P_0c098fb8: /* original d324, guest PC 0x0c098fb8 */
if(!s->budget--) { s->failed_pc=0x0c098fb8u; return 0; }
r[3]=read(ram,0x0c09904cu,4);
goto P_0c098fba;
P_0c098fba: /* original 903f, guest PC 0x0c098fba */
if(!s->budget--) { s->failed_pc=0x0c098fbau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09903cu,2);
goto P_0c098fbc;
P_0c098fbc: /* original 54cc, guest PC 0x0c098fbc */
if(!s->budget--) { s->failed_pc=0x0c098fbcu; return 0; }
r[4]=read(ram,r[12]+48,4);
goto P_0c098fbe;
P_0c098fbe: /* original 23d8, guest PC 0x0c098fbe */
if(!s->budget--) { s->failed_pc=0x0c098fbeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c098fc0;
P_0c098fc0: /* original d521, guest PC 0x0c098fc0 */
if(!s->budget--) { s->failed_pc=0x0c098fc0u; return 0; }
r[5]=read(ram,0x0c099048u,4);
goto P_0c098fc2;
P_0c098fc2: /* original 8d1a, guest PC 0x0c098fc2 */
if(!s->budget--) { s->failed_pc=0x0c098fc2u; return 0; }
cond=r[17]&1u;
write(ram,r[4]+r[0],r[5],4);
if(cond) { goto P_0c098ffa; }
goto P_0c098fc6;
P_0c098fc4: /* original 0456, guest PC 0x0c098fc4 */
if(!s->budget--) { s->failed_pc=0x0c098fc4u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c098fc6;
P_0c098fc6: /* original d222, guest PC 0x0c098fc6 */
if(!s->budget--) { s->failed_pc=0x0c098fc6u; return 0; }
r[2]=read(ram,0x0c099050u,4);
goto P_0c098fc8;
P_0c098fc8: /* original 252b, guest PC 0x0c098fc8 */
if(!s->budget--) { s->failed_pc=0x0c098fc8u; return 0; }
r[5]|=r[2];
goto P_0c098fca;
P_0c098fca: /* original 0456, guest PC 0x0c098fca */
if(!s->budget--) { s->failed_pc=0x0c098fcau; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c098fcc;
P_0c098fcc: /* original 51e2, guest PC 0x0c098fcc */
if(!s->budget--) { s->failed_pc=0x0c098fccu; return 0; }
r[1]=read(ram,r[14]+8,4);
goto P_0c098fce;
P_0c098fce: /* original d321, guest PC 0x0c098fce */
if(!s->budget--) { s->failed_pc=0x0c098fceu; return 0; }
r[3]=read(ram,0x0c099054u,4);
goto P_0c098fd0;
P_0c098fd0: /* original 2138, guest PC 0x0c098fd0 */
if(!s->budget--) { s->failed_pc=0x0c098fd0u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c098fd2;
P_0c098fd2: /* original 8b12, guest PC 0x0c098fd2 */
if(!s->budget--) { s->failed_pc=0x0c098fd2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098ffa; }
goto P_0c098fd4;
P_0c098fd4: /* original 60b3, guest PC 0x0c098fd4 */
if(!s->budget--) { s->failed_pc=0x0c098fd4u; return 0; }
r[0]=r[11];
goto P_0c098fd6;
P_0c098fd6: /* original 8803, guest PC 0x0c098fd6 */
if(!s->budget--) { s->failed_pc=0x0c098fd6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c098fd8;
P_0c098fd8: /* original 890f, guest PC 0x0c098fd8 */
if(!s->budget--) { s->failed_pc=0x0c098fd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c098ffa; }
goto P_0c098fda;
P_0c098fda: /* original e02b, guest PC 0x0c098fda */
if(!s->budget--) { s->failed_pc=0x0c098fdau; return 0; }
r[0]=0x0000002bu;
goto P_0c098fdc;
P_0c098fdc: /* original 03ec, guest PC 0x0c098fdc */
if(!s->budget--) { s->failed_pc=0x0c098fdcu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098fde;
P_0c098fde: /* original e209, guest PC 0x0c098fde */
if(!s->budget--) { s->failed_pc=0x0c098fdeu; return 0; }
r[2]=0x00000009u;
goto P_0c098fe0;
P_0c098fe0: /* original 3323, guest PC 0x0c098fe0 */
if(!s->budget--) { s->failed_pc=0x0c098fe0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c098fe2;
P_0c098fe2: /* original 8b0a, guest PC 0x0c098fe2 */
if(!s->budget--) { s->failed_pc=0x0c098fe2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098ffa; }
goto P_0c098fe4;
P_0c098fe4: /* original e029, guest PC 0x0c098fe4 */
if(!s->budget--) { s->failed_pc=0x0c098fe4u; return 0; }
r[0]=0x00000029u;
goto P_0c098fe6;
P_0c098fe6: /* original 03ec, guest PC 0x0c098fe6 */
if(!s->budget--) { s->failed_pc=0x0c098fe6u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098fe8;
P_0c098fe8: /* original e01d, guest PC 0x0c098fe8 */
if(!s->budget--) { s->failed_pc=0x0c098fe8u; return 0; }
r[0]=0x0000001du;
goto P_0c098fea;
P_0c098fea: /* original 02ec, guest PC 0x0c098fea */
if(!s->budget--) { s->failed_pc=0x0c098feau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c098fec;
P_0c098fec: /* original 633c, guest PC 0x0c098fec */
if(!s->budget--) { s->failed_pc=0x0c098fecu; return 0; }
r[3]=r[3]&255u;
goto P_0c098fee;
P_0c098fee: /* original 622c, guest PC 0x0c098fee */
if(!s->budget--) { s->failed_pc=0x0c098feeu; return 0; }
r[2]=r[2]&255u;
goto P_0c098ff0;
P_0c098ff0: /* original 73ff, guest PC 0x0c098ff0 */
if(!s->budget--) { s->failed_pc=0x0c098ff0u; return 0; }
r[3]+=0xffffffffu;
goto P_0c098ff2;
P_0c098ff2: /* original 3320, guest PC 0x0c098ff2 */
if(!s->budget--) { s->failed_pc=0x0c098ff2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c098ff4;
P_0c098ff4: /* original 8b01, guest PC 0x0c098ff4 */
if(!s->budget--) { s->failed_pc=0x0c098ff4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c098ffa; }
goto P_0c098ff6;
P_0c098ff6: /* original e310, guest PC 0x0c098ff6 */
if(!s->budget--) { s->failed_pc=0x0c098ff6u; return 0; }
r[3]=0x00000010u;
goto P_0c098ff8;
P_0c098ff8: /* original 2d3b, guest PC 0x0c098ff8 */
if(!s->budget--) { s->failed_pc=0x0c098ff8u; return 0; }
r[13]|=r[3];
goto P_0c098ffa;
P_0c098ffa: /* original e018, guest PC 0x0c098ffa */
if(!s->budget--) { s->failed_pc=0x0c098ffau; return 0; }
r[0]=0x00000018u;
goto P_0c098ffc;
P_0c098ffc: /* original 1ed2, guest PC 0x0c098ffc */
if(!s->budget--) { s->failed_pc=0x0c098ffcu; return 0; }
write(ram,r[14]+8,r[13],4);
goto P_0c098ffe;
P_0c098ffe: /* original e360, guest PC 0x0c098ffe */
if(!s->budget--) { s->failed_pc=0x0c098ffeu; return 0; }
r[3]=0x00000060u;
goto P_0c099000;
P_0c099000: /* original 0e94, guest PC 0x0c099000 */
if(!s->budget--) { s->failed_pc=0x0c099000u; return 0; }
write(ram,r[14]+r[0],r[9],1);
goto P_0c099002;
P_0c099002: /* original e019, guest PC 0x0c099002 */
if(!s->budget--) { s->failed_pc=0x0c099002u; return 0; }
r[0]=0x00000019u;
goto P_0c099004;
P_0c099004: /* original 0e84, guest PC 0x0c099004 */
if(!s->budget--) { s->failed_pc=0x0c099004u; return 0; }
write(ram,r[14]+r[0],r[8],1);
goto P_0c099006;
P_0c099006: /* original e010, guest PC 0x0c099006 */
if(!s->budget--) { s->failed_pc=0x0c099006u; return 0; }
r[0]=0x00000010u;
goto P_0c099008;
P_0c099008: /* original 5cf3, guest PC 0x0c099008 */
if(!s->budget--) { s->failed_pc=0x0c099008u; return 0; }
r[12]=read(ram,r[15]+12,4);
goto P_0c09900a;
P_0c09900a: /* original e21d, guest PC 0x0c09900a */
if(!s->budget--) { s->failed_pc=0x0c09900au; return 0; }
r[2]=0x0000001du;
goto P_0c09900c;
P_0c09900c: /* original 1c33, guest PC 0x0c09900c */
if(!s->budget--) { s->failed_pc=0x0c09900cu; return 0; }
write(ram,r[12]+12,r[3],4);
goto P_0c09900e;
P_0c09900e: /* original d312, guest PC 0x0c09900e */
if(!s->budget--) { s->failed_pc=0x0c09900eu; return 0; }
r[3]=read(ram,0x0c099058u,4);
goto P_0c099010;
P_0c099010: /* original 430b, guest PC 0x0c099010 */
if(!s->budget--) { s->failed_pc=0x0c099010u; return 0; }
target=r[3];
r[16]=code_base|0x0c099014u;
write(ram,r[12]+r[0],r[2],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099014u) { target=s->pc; goto dispatch; }
goto P_0c099014;
P_0c099012: /* original 0c24, guest PC 0x0c099012 */
if(!s->budget--) { s->failed_pc=0x0c099012u; return 0; }
write(ram,r[12]+r[0],r[2],1);
goto P_0c099014;
P_0c099014: /* original d111, guest PC 0x0c099014 */
if(!s->budget--) { s->failed_pc=0x0c099014u; return 0; }
r[1]=read(ram,0x0c09905cu,4);
goto P_0c099016;
P_0c099016: /* original 410b, guest PC 0x0c099016 */
if(!s->budget--) { s->failed_pc=0x0c099016u; return 0; }
target=r[1];
r[16]=code_base|0x0c09901au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09901au) { target=s->pc; goto dispatch; }
goto P_0c09901a;
P_0c099018: /* original 0009, guest PC 0x0c099018 */
if(!s->budget--) { s->failed_pc=0x0c099018u; return 0; }
goto P_0c09901a;
P_0c09901a: /* original 7f1c, guest PC 0x0c09901a */
if(!s->budget--) { s->failed_pc=0x0c09901au; return 0; }
r[15]+=0x0000001cu;
goto P_0c09901c;
P_0c09901c: /* original 84cb, guest PC 0x0c09901c */
if(!s->budget--) { s->failed_pc=0x0c09901cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+11,1);
goto P_0c09901e;
P_0c09901e: /* original 4f26, guest PC 0x0c09901e */
if(!s->budget--) { s->failed_pc=0x0c09901eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c099020;
P_0c099020: /* original 7001, guest PC 0x0c099020 */
if(!s->budget--) { s->failed_pc=0x0c099020u; return 0; }
r[0]+=0x00000001u;
goto P_0c099022;
P_0c099022: /* original 80cb, guest PC 0x0c099022 */
if(!s->budget--) { s->failed_pc=0x0c099022u; return 0; }
write(ram,r[12]+11,r[0],1);
goto P_0c099024;
P_0c099024: /* original 68f6, guest PC 0x0c099024 */
if(!s->budget--) { s->failed_pc=0x0c099024u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c099026;
P_0c099026: /* original 69f6, guest PC 0x0c099026 */
if(!s->budget--) { s->failed_pc=0x0c099026u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c099028;
P_0c099028: /* original 6af6, guest PC 0x0c099028 */
if(!s->budget--) { s->failed_pc=0x0c099028u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09902a;
P_0c09902a: /* original 6bf6, guest PC 0x0c09902a */
if(!s->budget--) { s->failed_pc=0x0c09902au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09902c;
P_0c09902c: /* original 6cf6, guest PC 0x0c09902c */
if(!s->budget--) { s->failed_pc=0x0c09902cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09902e;
P_0c09902e: /* original 6df6, guest PC 0x0c09902e */
if(!s->budget--) { s->failed_pc=0x0c09902eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c099030;
P_0c099030: /* original a016, guest PC 0x0c099030 */
if(!s->budget--) { s->failed_pc=0x0c099030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099060;
P_0c099032: /* original 6ef6, guest PC 0x0c099032 */
if(!s->budget--) { s->failed_pc=0x0c099032u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c099034u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c099034u; return 0; } return 1;
P_0c099060: /* original 2fe6, guest PC 0x0c099060 */
if(!s->budget--) { s->failed_pc=0x0c099060u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099062;
P_0c099062: /* original 2fd6, guest PC 0x0c099062 */
if(!s->budget--) { s->failed_pc=0x0c099062u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099064;
P_0c099064: /* original dd45, guest PC 0x0c099064 */
if(!s->budget--) { s->failed_pc=0x0c099064u; return 0; }
r[13]=read(ram,0x0c09917cu,4);
goto P_0c099066;
P_0c099066: /* original 9077, guest PC 0x0c099066 */
if(!s->budget--) { s->failed_pc=0x0c099066u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099158u,2);
goto P_0c099068;
P_0c099068: /* original d443, guest PC 0x0c099068 */
if(!s->budget--) { s->failed_pc=0x0c099068u; return 0; }
r[4]=read(ram,0x0c099178u,4);
goto P_0c09906a;
P_0c09906a: /* original 05de, guest PC 0x0c09906a */
if(!s->budget--) { s->failed_pc=0x0c09906au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c09906c;
P_0c09906c: /* original e029, guest PC 0x0c09906c */
if(!s->budget--) { s->failed_pc=0x0c09906cu; return 0; }
r[0]=0x00000029u;
goto P_0c09906e;
P_0c09906e: /* original 004c, guest PC 0x0c09906e */
if(!s->budget--) { s->failed_pc=0x0c09906eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c099070;
P_0c099070: /* original 4f22, guest PC 0x0c099070 */
if(!s->budget--) { s->failed_pc=0x0c099070u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c099072;
P_0c099072: /* original 600c, guest PC 0x0c099072 */
if(!s->budget--) { s->failed_pc=0x0c099072u; return 0; }
r[0]=r[0]&255u;
goto P_0c099074;
P_0c099074: /* original de3f, guest PC 0x0c099074 */
if(!s->budget--) { s->failed_pc=0x0c099074u; return 0; }
r[14]=read(ram,0x0c099174u,4);
goto P_0c099076;
P_0c099076: /* original 8803, guest PC 0x0c099076 */
if(!s->budget--) { s->failed_pc=0x0c099076u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c099078;
P_0c099078: /* original 8b06, guest PC 0x0c099078 */
if(!s->budget--) { s->failed_pc=0x0c099078u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099088; }
goto P_0c09907a;
P_0c09907a: /* original e2f8, guest PC 0x0c09907a */
if(!s->budget--) { s->failed_pc=0x0c09907au; return 0; }
r[2]=0xfffffff8u;
goto P_0c09907c;
P_0c09907c: /* original 6353, guest PC 0x0c09907c */
if(!s->budget--) { s->failed_pc=0x0c09907cu; return 0; }
r[3]=r[5];
goto P_0c09907e;
P_0c09907e: /* original 432c, guest PC 0x0c09907e */
if(!s->budget--) { s->failed_pc=0x0c09907eu; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c099080;
P_0c099080: /* original 235b, guest PC 0x0c099080 */
if(!s->budget--) { s->failed_pc=0x0c099080u; return 0; }
r[3]|=r[5];
goto P_0c099082;
P_0c099082: /* original 653d, guest PC 0x0c099082 */
if(!s->budget--) { s->failed_pc=0x0c099082u; return 0; }
r[5]=r[3]&65535u;
goto P_0c099084;
P_0c099084: /* original a006, guest PC 0x0c099084 */
if(!s->budget--) { s->failed_pc=0x0c099084u; return 0; }
goto P_0c099094;
P_0c099086: /* original 0009, guest PC 0x0c099086 */
if(!s->budget--) { s->failed_pc=0x0c099086u; return 0; }
goto P_0c099088;
P_0c099088: /* original 8801, guest PC 0x0c099088 */
if(!s->budget--) { s->failed_pc=0x0c099088u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09908a;
P_0c09908a: /* original 8903, guest PC 0x0c09908a */
if(!s->budget--) { s->failed_pc=0x0c09908au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099094; }
goto P_0c09908c;
P_0c09908c: /* original e3f8, guest PC 0x0c09908c */
if(!s->budget--) { s->failed_pc=0x0c09908cu; return 0; }
r[3]=0xfffffff8u;
goto P_0c09908e;
P_0c09908e: /* original 6253, guest PC 0x0c09908e */
if(!s->budget--) { s->failed_pc=0x0c09908eu; return 0; }
r[2]=r[5];
goto P_0c099090;
P_0c099090: /* original 423c, guest PC 0x0c099090 */
if(!s->budget--) { s->failed_pc=0x0c099090u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[2]>>((-r[3])&31u)):((int32_t)r[2]<0?0xffffffffu:0)):r[2]<<(r[3]&31u);
goto P_0c099092;
P_0c099092: /* original 652d, guest PC 0x0c099092 */
if(!s->budget--) { s->failed_pc=0x0c099092u; return 0; }
r[5]=r[2]&65535u;
goto P_0c099094;
P_0c099094: /* original 9661, guest PC 0x0c099094 */
if(!s->budget--) { s->failed_pc=0x0c099094u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09915au,2);
goto P_0c099096;
P_0c099096: /* original 2568, guest PC 0x0c099096 */
if(!s->budget--) { s->failed_pc=0x0c099096u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[6])==0)!=0);
goto P_0c099098;
P_0c099098: /* original 8903, guest PC 0x0c099098 */
if(!s->budget--) { s->failed_pc=0x0c099098u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0990a2; }
goto P_0c09909a;
P_0c09909a: /* original 905f, guest PC 0x0c09909a */
if(!s->budget--) { s->failed_pc=0x0c09909au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09915cu,2);
goto P_0c09909c;
P_0c09909c: /* original 024d, guest PC 0x0c09909c */
if(!s->budget--) { s->failed_pc=0x0c09909cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09909e;
P_0c09909e: /* original 7201, guest PC 0x0c09909e */
if(!s->budget--) { s->failed_pc=0x0c09909eu; return 0; }
r[2]+=0x00000001u;
goto P_0c0990a0;
P_0c0990a0: /* original 0425, guest PC 0x0c0990a0 */
if(!s->budget--) { s->failed_pc=0x0c0990a0u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0990a2;
P_0c0990a2: /* original 53d3, guest PC 0x0c0990a2 */
if(!s->budget--) { s->failed_pc=0x0c0990a2u; return 0; }
r[3]=read(ram,r[13]+12,4);
goto P_0c0990a4;
P_0c0990a4: /* original 4315, guest PC 0x0c0990a4 */
if(!s->budget--) { s->failed_pc=0x0c0990a4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c0990a6;
P_0c0990a6: /* original 8952, guest PC 0x0c0990a6 */
if(!s->budget--) { s->failed_pc=0x0c0990a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09914e; }
goto P_0c0990a8;
P_0c0990a8: /* original 9058, guest PC 0x0c0990a8 */
if(!s->budget--) { s->failed_pc=0x0c0990a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09915cu,2);
goto P_0c0990aa;
P_0c0990aa: /* original e310, guest PC 0x0c0990aa */
if(!s->budget--) { s->failed_pc=0x0c0990aau; return 0; }
r[3]=0x00000010u;
goto P_0c0990ac;
P_0c0990ac: /* original 024d, guest PC 0x0c0990ac */
if(!s->budget--) { s->failed_pc=0x0c0990acu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0990ae;
P_0c0990ae: /* original 3237, guest PC 0x0c0990ae */
if(!s->budget--) { s->failed_pc=0x0c0990aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c0990b0;
P_0c0990b0: /* original 8b02, guest PC 0x0c0990b0 */
if(!s->budget--) { s->failed_pc=0x0c0990b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0990b8; }
goto P_0c0990b2;
P_0c0990b2: /* original 5242, guest PC 0x0c0990b2 */
if(!s->budget--) { s->failed_pc=0x0c0990b2u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c0990b4;
P_0c0990b4: /* original 226b, guest PC 0x0c0990b4 */
if(!s->budget--) { s->failed_pc=0x0c0990b4u; return 0; }
r[2]|=r[6];
goto P_0c0990b6;
P_0c0990b6: /* original 1422, guest PC 0x0c0990b6 */
if(!s->budget--) { s->failed_pc=0x0c0990b6u; return 0; }
write(ram,r[4]+8,r[2],4);
goto P_0c0990b8;
P_0c0990b8: /* original 9051, guest PC 0x0c0990b8 */
if(!s->budget--) { s->failed_pc=0x0c0990b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09915eu,2);
goto P_0c0990ba;
P_0c0990ba: /* original 054e, guest PC 0x0c0990ba */
if(!s->budget--) { s->failed_pc=0x0c0990bau; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0990bc;
P_0c0990bc: /* original 9050, guest PC 0x0c0990bc */
if(!s->budget--) { s->failed_pc=0x0c0990bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099160u,2);
goto P_0c0990be;
P_0c0990be: /* original f356, guest PC 0x0c0990be */
if(!s->budget--) { s->failed_pc=0x0c0990beu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0990c0;
P_0c0990c0: /* original 70b4, guest PC 0x0c0990c0 */
if(!s->budget--) { s->failed_pc=0x0c0990c0u; return 0; }
r[0]+=0xffffffb4u;
goto P_0c0990c2;
P_0c0990c2: /* original f437, guest PC 0x0c0990c2 */
if(!s->budget--) { s->failed_pc=0x0c0990c2u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0990c4;
P_0c0990c4: /* original 7054, guest PC 0x0c0990c4 */
if(!s->budget--) { s->failed_pc=0x0c0990c4u; return 0; }
r[0]+=0x00000054u;
goto P_0c0990c6;
P_0c0990c6: /* original f356, guest PC 0x0c0990c6 */
if(!s->budget--) { s->failed_pc=0x0c0990c6u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0990c8;
P_0c0990c8: /* original 70b0, guest PC 0x0c0990c8 */
if(!s->budget--) { s->failed_pc=0x0c0990c8u; return 0; }
r[0]+=0xffffffb0u;
goto P_0c0990ca;
P_0c0990ca: /* original f437, guest PC 0x0c0990ca */
if(!s->budget--) { s->failed_pc=0x0c0990cau; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0990cc;
P_0c0990cc: /* original e029, guest PC 0x0c0990cc */
if(!s->budget--) { s->failed_pc=0x0c0990ccu; return 0; }
r[0]=0x00000029u;
goto P_0c0990ce;
P_0c0990ce: /* original 004c, guest PC 0x0c0990ce */
if(!s->budget--) { s->failed_pc=0x0c0990ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0990d0;
P_0c0990d0: /* original 600c, guest PC 0x0c0990d0 */
if(!s->budget--) { s->failed_pc=0x0c0990d0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0990d2;
P_0c0990d2: /* original 8801, guest PC 0x0c0990d2 */
if(!s->budget--) { s->failed_pc=0x0c0990d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0990d4;
P_0c0990d4: /* original 8b02, guest PC 0x0c0990d4 */
if(!s->budget--) { s->failed_pc=0x0c0990d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0990dc; }
goto P_0c0990d6;
P_0c0990d6: /* original 9644, guest PC 0x0c0990d6 */
if(!s->budget--) { s->failed_pc=0x0c0990d6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099162u,2);
goto P_0c0990d8;
P_0c0990d8: /* original a002, guest PC 0x0c0990d8 */
if(!s->budget--) { s->failed_pc=0x0c0990d8u; return 0; }
r[5]=read(ram,r[14]+16,4);
goto P_0c0990e0;
P_0c0990da: /* original 55e4, guest PC 0x0c0990da */
if(!s->budget--) { s->failed_pc=0x0c0990dau; return 0; }
r[5]=read(ram,r[14]+16,4);
goto P_0c0990dc;
P_0c0990dc: /* original 9642, guest PC 0x0c0990dc */
if(!s->budget--) { s->failed_pc=0x0c0990dcu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099164u,2);
goto P_0c0990de;
P_0c0990de: /* original 55e5, guest PC 0x0c0990de */
if(!s->budget--) { s->failed_pc=0x0c0990deu; return 0; }
r[5]=read(ram,r[14]+20,4);
goto P_0c0990e0;
P_0c0990e0: /* original e060, guest PC 0x0c0990e0 */
if(!s->budget--) { s->failed_pc=0x0c0990e0u; return 0; }
r[0]=0x00000060u;
goto P_0c0990e2;
P_0c0990e2: /* original 055c, guest PC 0x0c0990e2 */
if(!s->budget--) { s->failed_pc=0x0c0990e2u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0990e4;
P_0c0990e4: /* original 364c, guest PC 0x0c0990e4 */
if(!s->budget--) { s->failed_pc=0x0c0990e4u; return 0; }
r[6]+=r[4];
goto P_0c0990e6;
P_0c0990e6: /* original 5042, guest PC 0x0c0990e6 */
if(!s->budget--) { s->failed_pc=0x0c0990e6u; return 0; }
r[0]=read(ram,r[4]+8,4);
goto P_0c0990e8;
P_0c0990e8: /* original c804, guest PC 0x0c0990e8 */
if(!s->budget--) { s->failed_pc=0x0c0990e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0990ea;
P_0c0990ea: /* original 8d02, guest PC 0x0c0990ea */
if(!s->budget--) { s->failed_pc=0x0c0990eau; return 0; }
cond=r[17]&1u;
r[5]=r[5]&255u;
if(cond) { goto P_0c0990f2; }
goto P_0c0990ee;
P_0c0990ec: /* original 655c, guest PC 0x0c0990ec */
if(!s->budget--) { s->failed_pc=0x0c0990ecu; return 0; }
r[5]=r[5]&255u;
goto P_0c0990ee;
P_0c0990ee: /* original 6560, guest PC 0x0c0990ee */
if(!s->budget--) { s->failed_pc=0x0c0990eeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[5]=tmp;
goto P_0c0990f0;
P_0c0990f0: /* original 655c, guest PC 0x0c0990f0 */
if(!s->budget--) { s->failed_pc=0x0c0990f0u; return 0; }
r[5]=r[5]&255u;
goto P_0c0990f2;
P_0c0990f2: /* original e30d, guest PC 0x0c0990f2 */
if(!s->budget--) { s->failed_pc=0x0c0990f2u; return 0; }
r[3]=0x0000000du;
goto P_0c0990f4;
P_0c0990f4: /* original 9037, guest PC 0x0c0990f4 */
if(!s->budget--) { s->failed_pc=0x0c0990f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099166u,2);
goto P_0c0990f6;
P_0c0990f6: /* original 3533, guest PC 0x0c0990f6 */
if(!s->budget--) { s->failed_pc=0x0c0990f6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[3])!=0);
goto P_0c0990f8;
P_0c0990f8: /* original 8f01, guest PC 0x0c0990f8 */
if(!s->budget--) { s->failed_pc=0x0c0990f8u; return 0; }
cond=r[17]&1u;
write(ram,r[4]+r[0],r[5],1);
if(!cond) { goto P_0c0990fe; }
goto P_0c0990fc;
P_0c0990fa: /* original 0454, guest PC 0x0c0990fa */
if(!s->budget--) { s->failed_pc=0x0c0990fau; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0990fc;
P_0c0990fc: /* original 3538, guest PC 0x0c0990fc */
if(!s->budget--) { s->failed_pc=0x0c0990fcu; return 0; }
r[5]-=r[3];
goto P_0c0990fe;
P_0c0990fe: /* original 9033, guest PC 0x0c0990fe */
if(!s->budget--) { s->failed_pc=0x0c0990feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099168u,2);
goto P_0c099100;
P_0c099100: /* original 0454, guest PC 0x0c099100 */
if(!s->budget--) { s->failed_pc=0x0c099100u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c099102;
P_0c099102: /* original 9032, guest PC 0x0c099102 */
if(!s->budget--) { s->failed_pc=0x0c099102u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09916au,2);
goto P_0c099104;
P_0c099104: /* original 55e4, guest PC 0x0c099104 */
if(!s->budget--) { s->failed_pc=0x0c099104u; return 0; }
r[5]=read(ram,r[14]+16,4);
goto P_0c099106;
P_0c099106: /* original 56e5, guest PC 0x0c099106 */
if(!s->budget--) { s->failed_pc=0x0c099106u; return 0; }
r[6]=read(ram,r[14]+20,4);
goto P_0c099108;
P_0c099108: /* original 035c, guest PC 0x0c099108 */
if(!s->budget--) { s->failed_pc=0x0c099108u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c09910a;
P_0c09910a: /* original 902f, guest PC 0x0c09910a */
if(!s->budget--) { s->failed_pc=0x0c09910au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09916cu,2);
goto P_0c09910c;
P_0c09910c: /* original 0434, guest PC 0x0c09910c */
if(!s->budget--) { s->failed_pc=0x0c09910cu; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c09910e;
P_0c09910e: /* original 902c, guest PC 0x0c09910e */
if(!s->budget--) { s->failed_pc=0x0c09910eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09916au,2);
goto P_0c099110;
P_0c099110: /* original 026c, guest PC 0x0c099110 */
if(!s->budget--) { s->failed_pc=0x0c099110u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c099112;
P_0c099112: /* original 902c, guest PC 0x0c099112 */
if(!s->budget--) { s->failed_pc=0x0c099112u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09916eu,2);
goto P_0c099114;
P_0c099114: /* original 0424, guest PC 0x0c099114 */
if(!s->budget--) { s->failed_pc=0x0c099114u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c099116;
P_0c099116: /* original e046, guest PC 0x0c099116 */
if(!s->budget--) { s->failed_pc=0x0c099116u; return 0; }
r[0]=0x00000046u;
goto P_0c099118;
P_0c099118: /* original 035d, guest PC 0x0c099118 */
if(!s->budget--) { s->failed_pc=0x0c099118u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c09911a;
P_0c09911a: /* original 9029, guest PC 0x0c09911a */
if(!s->budget--) { s->failed_pc=0x0c09911au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099170u,2);
goto P_0c09911c;
P_0c09911c: /* original 0435, guest PC 0x0c09911c */
if(!s->budget--) { s->failed_pc=0x0c09911cu; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c09911e;
P_0c09911e: /* original e046, guest PC 0x0c09911e */
if(!s->budget--) { s->failed_pc=0x0c09911eu; return 0; }
r[0]=0x00000046u;
goto P_0c099120;
P_0c099120: /* original 026d, guest PC 0x0c099120 */
if(!s->budget--) { s->failed_pc=0x0c099120u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c099122;
P_0c099122: /* original e300, guest PC 0x0c099122 */
if(!s->budget--) { s->failed_pc=0x0c099122u; return 0; }
r[3]=0x00000000u;
goto P_0c099124;
P_0c099124: /* original 9025, guest PC 0x0c099124 */
if(!s->budget--) { s->failed_pc=0x0c099124u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099172u,2);
goto P_0c099126;
P_0c099126: /* original 0425, guest PC 0x0c099126 */
if(!s->budget--) { s->failed_pc=0x0c099126u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c099128;
P_0c099128: /* original 700c, guest PC 0x0c099128 */
if(!s->budget--) { s->failed_pc=0x0c099128u; return 0; }
r[0]+=0x0000000cu;
goto P_0c09912a;
P_0c09912a: /* original 0435, guest PC 0x0c09912a */
if(!s->budget--) { s->failed_pc=0x0c09912au; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c09912c;
P_0c09912c: /* original e050, guest PC 0x0c09912c */
if(!s->budget--) { s->failed_pc=0x0c09912cu; return 0; }
r[0]=0x00000050u;
goto P_0c09912e;
P_0c09912e: /* original d314, guest PC 0x0c09912e */
if(!s->budget--) { s->failed_pc=0x0c09912eu; return 0; }
r[3]=read(ram,0x0c099180u,4);
goto P_0c099130;
P_0c099130: /* original 430b, guest PC 0x0c099130 */
if(!s->budget--) { s->failed_pc=0x0c099130u; return 0; }
target=r[3];
r[16]=code_base|0x0c099134u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099134u) { target=s->pc; goto dispatch; }
goto P_0c099134;
P_0c099132: /* original 04ee, guest PC 0x0c099132 */
if(!s->budget--) { s->failed_pc=0x0c099132u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c099134;
P_0c099134: /* original d214, guest PC 0x0c099134 */
if(!s->budget--) { s->failed_pc=0x0c099134u; return 0; }
r[2]=read(ram,0x0c099188u,4);
goto P_0c099136;
P_0c099136: /* original d413, guest PC 0x0c099136 */
if(!s->budget--) { s->failed_pc=0x0c099136u; return 0; }
r[4]=read(ram,0x0c099184u,4);
goto P_0c099138;
P_0c099138: /* original 420b, guest PC 0x0c099138 */
if(!s->budget--) { s->failed_pc=0x0c099138u; return 0; }
target=r[2];
r[16]=code_base|0x0c09913cu;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09913cu) { target=s->pc; goto dispatch; }
goto P_0c09913c;
P_0c09913a: /* original e500, guest PC 0x0c09913a */
if(!s->budget--) { s->failed_pc=0x0c09913au; return 0; }
r[5]=0x00000000u;
goto P_0c09913c;
P_0c09913c: /* original d313, guest PC 0x0c09913c */
if(!s->budget--) { s->failed_pc=0x0c09913cu; return 0; }
r[3]=read(ram,0x0c09918cu,4);
goto P_0c09913e;
P_0c09913e: /* original 430b, guest PC 0x0c09913e */
if(!s->budget--) { s->failed_pc=0x0c09913eu; return 0; }
target=r[3];
r[16]=code_base|0x0c099142u;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099142u) { target=s->pc; goto dispatch; }
goto P_0c099142;
P_0c099140: /* original 54e4, guest PC 0x0c099140 */
if(!s->budget--) { s->failed_pc=0x0c099140u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c099142;
P_0c099142: /* original d212, guest PC 0x0c099142 */
if(!s->budget--) { s->failed_pc=0x0c099142u; return 0; }
r[2]=read(ram,0x0c09918cu,4);
goto P_0c099144;
P_0c099144: /* original 420b, guest PC 0x0c099144 */
if(!s->budget--) { s->failed_pc=0x0c099144u; return 0; }
target=r[2];
r[16]=code_base|0x0c099148u;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099148u) { target=s->pc; goto dispatch; }
goto P_0c099148;
P_0c099146: /* original 54e5, guest PC 0x0c099146 */
if(!s->budget--) { s->failed_pc=0x0c099146u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c099148;
P_0c099148: /* original 84db, guest PC 0x0c099148 */
if(!s->budget--) { s->failed_pc=0x0c099148u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+11,1);
goto P_0c09914a;
P_0c09914a: /* original 7001, guest PC 0x0c09914a */
if(!s->budget--) { s->failed_pc=0x0c09914au; return 0; }
r[0]+=0x00000001u;
goto P_0c09914c;
P_0c09914c: /* original 80db, guest PC 0x0c09914c */
if(!s->budget--) { s->failed_pc=0x0c09914cu; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c09914e;
P_0c09914e: /* original 4f26, guest PC 0x0c09914e */
if(!s->budget--) { s->failed_pc=0x0c09914eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c099150;
P_0c099150: /* original d30f, guest PC 0x0c099150 */
if(!s->budget--) { s->failed_pc=0x0c099150u; return 0; }
r[3]=read(ram,0x0c099190u,4);
goto P_0c099152;
P_0c099152: /* original 6df6, guest PC 0x0c099152 */
if(!s->budget--) { s->failed_pc=0x0c099152u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c099154;
P_0c099154: /* original 432b, guest PC 0x0c099154 */
if(!s->budget--) { s->failed_pc=0x0c099154u; return 0; }
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
P_0c099156: /* original 6ef6, guest PC 0x0c099156 */
if(!s->budget--) { s->failed_pc=0x0c099156u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c099158u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c099158u; return 0; } return 1;
P_0c099194: /* original 2fe6, guest PC 0x0c099194 */
if(!s->budget--) { s->failed_pc=0x0c099194u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099196;
P_0c099196: /* original 2fd6, guest PC 0x0c099196 */
if(!s->budget--) { s->failed_pc=0x0c099196u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099198;
P_0c099198: /* original 2fc6, guest PC 0x0c099198 */
if(!s->budget--) { s->failed_pc=0x0c099198u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09919a;
P_0c09919a: /* original 2fb6, guest PC 0x0c09919a */
if(!s->budget--) { s->failed_pc=0x0c09919au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09919c;
P_0c09919c: /* original 2fa6, guest PC 0x0c09919c */
if(!s->budget--) { s->failed_pc=0x0c09919cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09919e;
P_0c09919e: /* original 2f96, guest PC 0x0c09919e */
if(!s->budget--) { s->failed_pc=0x0c09919eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0991a0;
P_0c0991a0: /* original 2f86, guest PC 0x0c0991a0 */
if(!s->budget--) { s->failed_pc=0x0c0991a0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0991a2;
P_0c0991a2: /* original 4f22, guest PC 0x0c0991a2 */
if(!s->budget--) { s->failed_pc=0x0c0991a2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0991a4;
P_0c0991a4: /* original d32c, guest PC 0x0c0991a4 */
if(!s->budget--) { s->failed_pc=0x0c0991a4u; return 0; }
r[3]=read(ram,0x0c099258u,4);
goto P_0c0991a6;
P_0c0991a6: /* original de2a, guest PC 0x0c0991a6 */
if(!s->budget--) { s->failed_pc=0x0c0991a6u; return 0; }
r[14]=read(ram,0x0c099250u,4);
goto P_0c0991a8;
P_0c0991a8: /* original 7ff4, guest PC 0x0c0991a8 */
if(!s->budget--) { s->failed_pc=0x0c0991a8u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0991aa;
P_0c0991aa: /* original db2a, guest PC 0x0c0991aa */
if(!s->budget--) { s->failed_pc=0x0c0991aau; return 0; }
r[11]=read(ram,0x0c099254u,4);
goto P_0c0991ac;
P_0c0991ac: /* original 1f32, guest PC 0x0c0991ac */
if(!s->budget--) { s->failed_pc=0x0c0991acu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0991ae;
P_0c0991ae: /* original d32c, guest PC 0x0c0991ae */
if(!s->budget--) { s->failed_pc=0x0c0991aeu; return 0; }
r[3]=read(ram,0x0c099260u,4);
goto P_0c0991b0;
P_0c0991b0: /* original 52e2, guest PC 0x0c0991b0 */
if(!s->budget--) { s->failed_pc=0x0c0991b0u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c0991b2;
P_0c0991b2: /* original dd2a, guest PC 0x0c0991b2 */
if(!s->budget--) { s->failed_pc=0x0c0991b2u; return 0; }
r[13]=read(ram,0x0c09925cu,4);
goto P_0c0991b4;
P_0c0991b4: /* original 2238, guest PC 0x0c0991b4 */
if(!s->budget--) { s->failed_pc=0x0c0991b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0991b6;
P_0c0991b6: /* original 8b67, guest PC 0x0c0991b6 */
if(!s->budget--) { s->failed_pc=0x0c0991b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099288; }
goto P_0c0991b8;
P_0c0991b8: /* original ec00, guest PC 0x0c0991b8 */
if(!s->budget--) { s->failed_pc=0x0c0991b8u; return 0; }
r[12]=0x00000000u;
goto P_0c0991ba;
P_0c0991ba: /* original 51d4, guest PC 0x0c0991ba */
if(!s->budget--) { s->failed_pc=0x0c0991bau; return 0; }
r[1]=read(ram,r[13]+16,4);
goto P_0c0991bc;
P_0c0991bc: /* original 1f11, guest PC 0x0c0991bc */
if(!s->budget--) { s->failed_pc=0x0c0991bcu; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0991be;
P_0c0991be: /* original 53d5, guest PC 0x0c0991be */
if(!s->budget--) { s->failed_pc=0x0c0991beu; return 0; }
r[3]=read(ram,r[13]+20,4);
goto P_0c0991c0;
P_0c0991c0: /* original 2f32, guest PC 0x0c0991c0 */
if(!s->budget--) { s->failed_pc=0x0c0991c0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0991c2;
P_0c0991c2: /* original 9040, guest PC 0x0c0991c2 */
if(!s->budget--) { s->failed_pc=0x0c0991c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099246u,2);
goto P_0c0991c4;
P_0c0991c4: /* original 0ec4, guest PC 0x0c0991c4 */
if(!s->budget--) { s->failed_pc=0x0c0991c4u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0991c6;
P_0c0991c6: /* original 7003, guest PC 0x0c0991c6 */
if(!s->budget--) { s->failed_pc=0x0c0991c6u; return 0; }
r[0]+=0x00000003u;
goto P_0c0991c8;
P_0c0991c8: /* original 0ec4, guest PC 0x0c0991c8 */
if(!s->budget--) { s->failed_pc=0x0c0991c8u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0991ca;
P_0c0991ca: /* original 70fe, guest PC 0x0c0991ca */
if(!s->budget--) { s->failed_pc=0x0c0991cau; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0991cc;
P_0c0991cc: /* original 0ec4, guest PC 0x0c0991cc */
if(!s->budget--) { s->failed_pc=0x0c0991ccu; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0991ce;
P_0c0991ce: /* original 903b, guest PC 0x0c0991ce */
if(!s->budget--) { s->failed_pc=0x0c0991ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099248u,2);
goto P_0c0991d0;
P_0c0991d0: /* original 0ec4, guest PC 0x0c0991d0 */
if(!s->budget--) { s->failed_pc=0x0c0991d0u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0991d2;
P_0c0991d2: /* original 70f6, guest PC 0x0c0991d2 */
if(!s->budget--) { s->failed_pc=0x0c0991d2u; return 0; }
r[0]+=0xfffffff6u;
goto P_0c0991d4;
P_0c0991d4: /* original 0ec4, guest PC 0x0c0991d4 */
if(!s->budget--) { s->failed_pc=0x0c0991d4u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0991d6;
P_0c0991d6: /* original 5ad8, guest PC 0x0c0991d6 */
if(!s->budget--) { s->failed_pc=0x0c0991d6u; return 0; }
r[10]=read(ram,r[13]+32,4);
goto P_0c0991d8;
P_0c0991d8: /* original 9037, guest PC 0x0c0991d8 */
if(!s->budget--) { s->failed_pc=0x0c0991d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09924au,2);
goto P_0c0991da;
P_0c0991da: /* original 64a2, guest PC 0x0c0991da */
if(!s->budget--) { s->failed_pc=0x0c0991dau; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0991dc;
P_0c0991dc: /* original d321, guest PC 0x0c0991dc */
if(!s->budget--) { s->failed_pc=0x0c0991dcu; return 0; }
r[3]=read(ram,0x0c099264u,4);
goto P_0c0991de;
P_0c0991de: /* original 0ac4, guest PC 0x0c0991de */
if(!s->budget--) { s->failed_pc=0x0c0991deu; return 0; }
write(ram,r[10]+r[0],r[12],1);
goto P_0c0991e0;
P_0c0991e0: /* original e029, guest PC 0x0c0991e0 */
if(!s->budget--) { s->failed_pc=0x0c0991e0u; return 0; }
r[0]=0x00000029u;
goto P_0c0991e2;
P_0c0991e2: /* original 2439, guest PC 0x0c0991e2 */
if(!s->budget--) { s->failed_pc=0x0c0991e2u; return 0; }
r[4]&=r[3];
goto P_0c0991e4;
P_0c0991e4: /* original 2a42, guest PC 0x0c0991e4 */
if(!s->budget--) { s->failed_pc=0x0c0991e4u; return 0; }
write(ram,r[10],r[4],4);
goto P_0c0991e6;
P_0c0991e6: /* original 00ec, guest PC 0x0c0991e6 */
if(!s->budget--) { s->failed_pc=0x0c0991e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0991e8;
P_0c0991e8: /* original d81f, guest PC 0x0c0991e8 */
if(!s->budget--) { s->failed_pc=0x0c0991e8u; return 0; }
r[8]=read(ram,0x0c099268u,4);
goto P_0c0991ea;
P_0c0991ea: /* original 600c, guest PC 0x0c0991ea */
if(!s->budget--) { s->failed_pc=0x0c0991eau; return 0; }
r[0]=r[0]&255u;
goto P_0c0991ec;
P_0c0991ec: /* original 8803, guest PC 0x0c0991ec */
if(!s->budget--) { s->failed_pc=0x0c0991ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0991ee;
P_0c0991ee: /* original 890e, guest PC 0x0c0991ee */
if(!s->budget--) { s->failed_pc=0x0c0991eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09920e; }
goto P_0c0991f0;
P_0c0991f0: /* original e02b, guest PC 0x0c0991f0 */
if(!s->budget--) { s->failed_pc=0x0c0991f0u; return 0; }
r[0]=0x0000002bu;
goto P_0c0991f2;
P_0c0991f2: /* original 03ec, guest PC 0x0c0991f2 */
if(!s->budget--) { s->failed_pc=0x0c0991f2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0991f4;
P_0c0991f4: /* original e209, guest PC 0x0c0991f4 */
if(!s->budget--) { s->failed_pc=0x0c0991f4u; return 0; }
r[2]=0x00000009u;
goto P_0c0991f6;
P_0c0991f6: /* original 3323, guest PC 0x0c0991f6 */
if(!s->budget--) { s->failed_pc=0x0c0991f6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c0991f8;
P_0c0991f8: /* original 8909, guest PC 0x0c0991f8 */
if(!s->budget--) { s->failed_pc=0x0c0991f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09920e; }
goto P_0c0991fa;
P_0c0991fa: /* original 53e2, guest PC 0x0c0991fa */
if(!s->budget--) { s->failed_pc=0x0c0991fau; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c0991fc;
P_0c0991fc: /* original 2388, guest PC 0x0c0991fc */
if(!s->budget--) { s->failed_pc=0x0c0991fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0991fe;
P_0c0991fe: /* original 8906, guest PC 0x0c0991fe */
if(!s->budget--) { s->failed_pc=0x0c0991feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09920e; }
goto P_0c099200;
P_0c099200: /* original d21a, guest PC 0x0c099200 */
if(!s->budget--) { s->failed_pc=0x0c099200u; return 0; }
r[2]=read(ram,0x0c09926cu,4);
goto P_0c099202;
P_0c099202: /* original 420b, guest PC 0x0c099202 */
if(!s->budget--) { s->failed_pc=0x0c099202u; return 0; }
target=r[2];
r[16]=code_base|0x0c099206u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099206u) { target=s->pc; goto dispatch; }
goto P_0c099206;
P_0c099204: /* original 0009, guest PC 0x0c099204 */
if(!s->budget--) { s->failed_pc=0x0c099204u; return 0; }
goto P_0c099206;
P_0c099206: /* original d31a, guest PC 0x0c099206 */
if(!s->budget--) { s->failed_pc=0x0c099206u; return 0; }
r[3]=read(ram,0x0c099270u,4);
goto P_0c099208;
P_0c099208: /* original 65f2, guest PC 0x0c099208 */
if(!s->budget--) { s->failed_pc=0x0c099208u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c09920a;
P_0c09920a: /* original 430b, guest PC 0x0c09920a */
if(!s->budget--) { s->failed_pc=0x0c09920au; return 0; }
target=r[3];
r[16]=code_base|0x0c09920eu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09920eu) { target=s->pc; goto dispatch; }
goto P_0c09920e;
P_0c09920c: /* original 54f1, guest PC 0x0c09920c */
if(!s->budget--) { s->failed_pc=0x0c09920cu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c09920e;
P_0c09920e: /* original d319, guest PC 0x0c09920e */
if(!s->budget--) { s->failed_pc=0x0c09920eu; return 0; }
r[3]=read(ram,0x0c099274u,4);
goto P_0c099210;
P_0c099210: /* original 54f2, guest PC 0x0c099210 */
if(!s->budget--) { s->failed_pc=0x0c099210u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c099212;
P_0c099212: /* original 59e2, guest PC 0x0c099212 */
if(!s->budget--) { s->failed_pc=0x0c099212u; return 0; }
r[9]=read(ram,r[14]+8,4);
goto P_0c099214;
P_0c099214: /* original 430b, guest PC 0x0c099214 */
if(!s->budget--) { s->failed_pc=0x0c099214u; return 0; }
target=r[3];
r[16]=code_base|0x0c099218u;
r[4]+=0x00000013u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099218u) { target=s->pc; goto dispatch; }
goto P_0c099218;
P_0c099216: /* original 7413, guest PC 0x0c099216 */
if(!s->budget--) { s->failed_pc=0x0c099216u; return 0; }
r[4]+=0x00000013u;
goto P_0c099218;
P_0c099218: /* original 640c, guest PC 0x0c099218 */
if(!s->budget--) { s->failed_pc=0x0c099218u; return 0; }
r[4]=r[0]&255u;
goto P_0c09921a;
P_0c09921a: /* original e029, guest PC 0x0c09921a */
if(!s->budget--) { s->failed_pc=0x0c09921au; return 0; }
r[0]=0x00000029u;
goto P_0c09921c;
P_0c09921c: /* original 00ec, guest PC 0x0c09921c */
if(!s->budget--) { s->failed_pc=0x0c09921cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09921e;
P_0c09921e: /* original 600c, guest PC 0x0c09921e */
if(!s->budget--) { s->failed_pc=0x0c09921eu; return 0; }
r[0]=r[0]&255u;
goto P_0c099220;
P_0c099220: /* original 8803, guest PC 0x0c099220 */
if(!s->budget--) { s->failed_pc=0x0c099220u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c099222;
P_0c099222: /* original 8b29, guest PC 0x0c099222 */
if(!s->budget--) { s->failed_pc=0x0c099222u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099278; }
goto P_0c099224;
P_0c099224: /* original 2448, guest PC 0x0c099224 */
if(!s->budget--) { s->failed_pc=0x0c099224u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c099226;
P_0c099226: /* original 8927, guest PC 0x0c099226 */
if(!s->budget--) { s->failed_pc=0x0c099226u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099278; }
goto P_0c099228;
P_0c099228: /* original e304, guest PC 0x0c099228 */
if(!s->budget--) { s->failed_pc=0x0c099228u; return 0; }
r[3]=0x00000004u;
goto P_0c09922a;
P_0c09922a: /* original 2398, guest PC 0x0c09922a */
if(!s->budget--) { s->failed_pc=0x0c09922au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c09922c;
P_0c09922c: /* original 8924, guest PC 0x0c09922c */
if(!s->budget--) { s->failed_pc=0x0c09922cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099278; }
goto P_0c09922e;
P_0c09922e: /* original 6293, guest PC 0x0c09922e */
if(!s->budget--) { s->failed_pc=0x0c09922eu; return 0; }
r[2]=r[9];
goto P_0c099230;
P_0c099230: /* original 2288, guest PC 0x0c099230 */
if(!s->budget--) { s->failed_pc=0x0c099230u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[8])==0)!=0);
goto P_0c099232;
P_0c099232: /* original 8b21, guest PC 0x0c099232 */
if(!s->budget--) { s->failed_pc=0x0c099232u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099278; }
goto P_0c099234;
P_0c099234: /* original e019, guest PC 0x0c099234 */
if(!s->budget--) { s->failed_pc=0x0c099234u; return 0; }
r[0]=0x00000019u;
goto P_0c099236;
P_0c099236: /* original 00ec, guest PC 0x0c099236 */
if(!s->budget--) { s->failed_pc=0x0c099236u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099238;
P_0c099238: /* original 600c, guest PC 0x0c099238 */
if(!s->budget--) { s->failed_pc=0x0c099238u; return 0; }
r[0]=r[0]&255u;
goto P_0c09923a;
P_0c09923a: /* original 8802, guest PC 0x0c09923a */
if(!s->budget--) { s->failed_pc=0x0c09923au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09923c;
P_0c09923c: /* original 8b71, guest PC 0x0c09923c */
if(!s->budget--) { s->failed_pc=0x0c09923cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099322; }
goto P_0c09923e;
P_0c09923e: /* original 9305, guest PC 0x0c09923e */
if(!s->budget--) { s->failed_pc=0x0c09923eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09924cu,2);
goto P_0c099240;
P_0c099240: /* original 293b, guest PC 0x0c099240 */
if(!s->budget--) { s->failed_pc=0x0c099240u; return 0; }
r[9]|=r[3];
goto P_0c099242;
P_0c099242: /* original a06e, guest PC 0x0c099242 */
if(!s->budget--) { s->failed_pc=0x0c099242u; return 0; }
write(ram,r[14]+8,r[9],4);
goto P_0c099322;
P_0c099244: /* original 1e92, guest PC 0x0c099244 */
if(!s->budget--) { s->failed_pc=0x0c099244u; return 0; }
write(ram,r[14]+8,r[9],4);
if(!vf3_matrix_family(0x0c099246u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c099246u; return 0; } return 1;
P_0c099278: /* original e019, guest PC 0x0c099278 */
if(!s->budget--) { s->failed_pc=0x0c099278u; return 0; }
r[0]=0x00000019u;
goto P_0c09927a;
P_0c09927a: /* original 00ec, guest PC 0x0c09927a */
if(!s->budget--) { s->failed_pc=0x0c09927au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09927c;
P_0c09927c: /* original 600c, guest PC 0x0c09927c */
if(!s->budget--) { s->failed_pc=0x0c09927cu; return 0; }
r[0]=r[0]&255u;
goto P_0c09927e;
P_0c09927e: /* original 8802, guest PC 0x0c09927e */
if(!s->budget--) { s->failed_pc=0x0c09927eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c099280;
P_0c099280: /* original 8b3b, guest PC 0x0c099280 */
if(!s->budget--) { s->failed_pc=0x0c099280u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0992fa; }
goto P_0c099282;
P_0c099282: /* original 53e2, guest PC 0x0c099282 */
if(!s->budget--) { s->failed_pc=0x0c099282u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c099284;
P_0c099284: /* original 2838, guest PC 0x0c099284 */
if(!s->budget--) { s->failed_pc=0x0c099284u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c099286;
P_0c099286: /* original 8b3d, guest PC 0x0c099286 */
if(!s->budget--) { s->failed_pc=0x0c099286u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099304; }
goto P_0c099288;
P_0c099288: /* original 54d4, guest PC 0x0c099288 */
if(!s->budget--) { s->failed_pc=0x0c099288u; return 0; }
r[4]=read(ram,r[13]+16,4);
goto P_0c09928a;
P_0c09928a: /* original e010, guest PC 0x0c09928a */
if(!s->budget--) { s->failed_pc=0x0c09928au; return 0; }
r[0]=0x00000010u;
goto P_0c09928c;
P_0c09928c: /* original f48d, guest PC 0x0c09928c */
if(!s->budget--) { s->failed_pc=0x0c09928cu; return 0; }
fr[4]=0;
goto P_0c09928e;
P_0c09928e: /* original f447, guest PC 0x0c09928e */
if(!s->budget--) { s->failed_pc=0x0c09928eu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c099290;
P_0c099290: /* original e018, guest PC 0x0c099290 */
if(!s->budget--) { s->failed_pc=0x0c099290u; return 0; }
r[0]=0x00000018u;
goto P_0c099292;
P_0c099292: /* original f447, guest PC 0x0c099292 */
if(!s->budget--) { s->failed_pc=0x0c099292u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c099294;
P_0c099294: /* original 908e, guest PC 0x0c099294 */
if(!s->budget--) { s->failed_pc=0x0c099294u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0993b4u,2);
goto P_0c099296;
P_0c099296: /* original f447, guest PC 0x0c099296 */
if(!s->budget--) { s->failed_pc=0x0c099296u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c099298;
P_0c099298: /* original 7008, guest PC 0x0c099298 */
if(!s->budget--) { s->failed_pc=0x0c099298u; return 0; }
r[0]+=0x00000008u;
goto P_0c09929a;
P_0c09929a: /* original f447, guest PC 0x0c09929a */
if(!s->budget--) { s->failed_pc=0x0c09929au; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09929c;
P_0c09929c: /* original e010, guest PC 0x0c09929c */
if(!s->budget--) { s->failed_pc=0x0c09929cu; return 0; }
r[0]=0x00000010u;
goto P_0c09929e;
P_0c09929e: /* original 54d5, guest PC 0x0c09929e */
if(!s->budget--) { s->failed_pc=0x0c09929eu; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c0992a0;
P_0c0992a0: /* original f447, guest PC 0x0c0992a0 */
if(!s->budget--) { s->failed_pc=0x0c0992a0u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0992a2;
P_0c0992a2: /* original e018, guest PC 0x0c0992a2 */
if(!s->budget--) { s->failed_pc=0x0c0992a2u; return 0; }
r[0]=0x00000018u;
goto P_0c0992a4;
P_0c0992a4: /* original f447, guest PC 0x0c0992a4 */
if(!s->budget--) { s->failed_pc=0x0c0992a4u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0992a6;
P_0c0992a6: /* original 9085, guest PC 0x0c0992a6 */
if(!s->budget--) { s->failed_pc=0x0c0992a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0993b4u,2);
goto P_0c0992a8;
P_0c0992a8: /* original f447, guest PC 0x0c0992a8 */
if(!s->budget--) { s->failed_pc=0x0c0992a8u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0992aa;
P_0c0992aa: /* original 7008, guest PC 0x0c0992aa */
if(!s->budget--) { s->failed_pc=0x0c0992aau; return 0; }
r[0]+=0x00000008u;
goto P_0c0992ac;
P_0c0992ac: /* original f447, guest PC 0x0c0992ac */
if(!s->budget--) { s->failed_pc=0x0c0992acu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0992ae;
P_0c0992ae: /* original d346, guest PC 0x0c0992ae */
if(!s->budget--) { s->failed_pc=0x0c0992aeu; return 0; }
r[3]=read(ram,0x0c0993c8u,4);
goto P_0c0992b0;
P_0c0992b0: /* original 430b, guest PC 0x0c0992b0 */
if(!s->budget--) { s->failed_pc=0x0c0992b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0992b4u;
r[4]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0992b4u) { target=s->pc; goto dispatch; }
goto P_0c0992b4;
P_0c0992b2: /* original 54d6, guest PC 0x0c0992b2 */
if(!s->budget--) { s->failed_pc=0x0c0992b2u; return 0; }
r[4]=read(ram,r[13]+24,4);
goto P_0c0992b4;
P_0c0992b4: /* original d244, guest PC 0x0c0992b4 */
if(!s->budget--) { s->failed_pc=0x0c0992b4u; return 0; }
r[2]=read(ram,0x0c0993c8u,4);
goto P_0c0992b6;
P_0c0992b6: /* original 420b, guest PC 0x0c0992b6 */
if(!s->budget--) { s->failed_pc=0x0c0992b6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0992bau;
r[4]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0992bau) { target=s->pc; goto dispatch; }
goto P_0c0992ba;
P_0c0992b8: /* original 54d4, guest PC 0x0c0992b8 */
if(!s->budget--) { s->failed_pc=0x0c0992b8u; return 0; }
r[4]=read(ram,r[13]+16,4);
goto P_0c0992ba;
P_0c0992ba: /* original d343, guest PC 0x0c0992ba */
if(!s->budget--) { s->failed_pc=0x0c0992bau; return 0; }
r[3]=read(ram,0x0c0993c8u,4);
goto P_0c0992bc;
P_0c0992bc: /* original 430b, guest PC 0x0c0992bc */
if(!s->budget--) { s->failed_pc=0x0c0992bcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0992c0u;
r[4]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0992c0u) { target=s->pc; goto dispatch; }
goto P_0c0992c0;
P_0c0992be: /* original 54d5, guest PC 0x0c0992be */
if(!s->budget--) { s->failed_pc=0x0c0992beu; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c0992c0;
P_0c0992c0: /* original d241, guest PC 0x0c0992c0 */
if(!s->budget--) { s->failed_pc=0x0c0992c0u; return 0; }
r[2]=read(ram,0x0c0993c8u,4);
goto P_0c0992c2;
P_0c0992c2: /* original 420b, guest PC 0x0c0992c2 */
if(!s->budget--) { s->failed_pc=0x0c0992c2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0992c6u;
r[4]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0992c6u) { target=s->pc; goto dispatch; }
goto P_0c0992c6;
P_0c0992c4: /* original 54df, guest PC 0x0c0992c4 */
if(!s->budget--) { s->failed_pc=0x0c0992c4u; return 0; }
r[4]=read(ram,r[13]+60,4);
goto P_0c0992c6;
P_0c0992c6: /* original d340, guest PC 0x0c0992c6 */
if(!s->budget--) { s->failed_pc=0x0c0992c6u; return 0; }
r[3]=read(ram,0x0c0993c8u,4);
goto P_0c0992c8;
P_0c0992c8: /* original e040, guest PC 0x0c0992c8 */
if(!s->budget--) { s->failed_pc=0x0c0992c8u; return 0; }
r[0]=0x00000040u;
goto P_0c0992ca;
P_0c0992ca: /* original 430b, guest PC 0x0c0992ca */
if(!s->budget--) { s->failed_pc=0x0c0992cau; return 0; }
target=r[3];
r[16]=code_base|0x0c0992ceu;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0992ceu) { target=s->pc; goto dispatch; }
goto P_0c0992ce;
P_0c0992cc: /* original 04de, guest PC 0x0c0992cc */
if(!s->budget--) { s->failed_pc=0x0c0992ccu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c0992ce;
P_0c0992ce: /* original d23e, guest PC 0x0c0992ce */
if(!s->budget--) { s->failed_pc=0x0c0992ceu; return 0; }
r[2]=read(ram,0x0c0993c8u,4);
goto P_0c0992d0;
P_0c0992d0: /* original 420b, guest PC 0x0c0992d0 */
if(!s->budget--) { s->failed_pc=0x0c0992d0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0992d4u;
r[4]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0992d4u) { target=s->pc; goto dispatch; }
goto P_0c0992d4;
P_0c0992d2: /* original 54d7, guest PC 0x0c0992d2 */
if(!s->budget--) { s->failed_pc=0x0c0992d2u; return 0; }
r[4]=read(ram,r[13]+28,4);
goto P_0c0992d4;
P_0c0992d4: /* original d33c, guest PC 0x0c0992d4 */
if(!s->budget--) { s->failed_pc=0x0c0992d4u; return 0; }
r[3]=read(ram,0x0c0993c8u,4);
goto P_0c0992d6;
P_0c0992d6: /* original 430b, guest PC 0x0c0992d6 */
if(!s->budget--) { s->failed_pc=0x0c0992d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0992dau;
r[4]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0992dau) { target=s->pc; goto dispatch; }
goto P_0c0992da;
P_0c0992d8: /* original 54dd, guest PC 0x0c0992d8 */
if(!s->budget--) { s->failed_pc=0x0c0992d8u; return 0; }
r[4]=read(ram,r[13]+52,4);
goto P_0c0992da;
P_0c0992da: /* original d23b, guest PC 0x0c0992da */
if(!s->budget--) { s->failed_pc=0x0c0992dau; return 0; }
r[2]=read(ram,0x0c0993c8u,4);
goto P_0c0992dc;
P_0c0992dc: /* original 420b, guest PC 0x0c0992dc */
if(!s->budget--) { s->failed_pc=0x0c0992dcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0992e0u;
r[4]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0992e0u) { target=s->pc; goto dispatch; }
goto P_0c0992e0;
P_0c0992de: /* original 54de, guest PC 0x0c0992de */
if(!s->budget--) { s->failed_pc=0x0c0992deu; return 0; }
r[4]=read(ram,r[13]+56,4);
goto P_0c0992e0;
P_0c0992e0: /* original 7f0c, guest PC 0x0c0992e0 */
if(!s->budget--) { s->failed_pc=0x0c0992e0u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0992e2;
P_0c0992e2: /* original 4f26, guest PC 0x0c0992e2 */
if(!s->budget--) { s->failed_pc=0x0c0992e2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0992e4;
P_0c0992e4: /* original e010, guest PC 0x0c0992e4 */
if(!s->budget--) { s->failed_pc=0x0c0992e4u; return 0; }
r[0]=0x00000010u;
goto P_0c0992e6;
P_0c0992e6: /* original 80bb, guest PC 0x0c0992e6 */
if(!s->budget--) { s->failed_pc=0x0c0992e6u; return 0; }
write(ram,r[11]+11,r[0],1);
goto P_0c0992e8;
P_0c0992e8: /* original 68f6, guest PC 0x0c0992e8 */
if(!s->budget--) { s->failed_pc=0x0c0992e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0992ea;
P_0c0992ea: /* original d338, guest PC 0x0c0992ea */
if(!s->budget--) { s->failed_pc=0x0c0992eau; return 0; }
r[3]=read(ram,0x0c0993ccu,4);
goto P_0c0992ec;
P_0c0992ec: /* original 69f6, guest PC 0x0c0992ec */
if(!s->budget--) { s->failed_pc=0x0c0992ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0992ee;
P_0c0992ee: /* original 6af6, guest PC 0x0c0992ee */
if(!s->budget--) { s->failed_pc=0x0c0992eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0992f0;
P_0c0992f0: /* original 6bf6, guest PC 0x0c0992f0 */
if(!s->budget--) { s->failed_pc=0x0c0992f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0992f2;
P_0c0992f2: /* original 6cf6, guest PC 0x0c0992f2 */
if(!s->budget--) { s->failed_pc=0x0c0992f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0992f4;
P_0c0992f4: /* original 6df6, guest PC 0x0c0992f4 */
if(!s->budget--) { s->failed_pc=0x0c0992f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0992f6;
P_0c0992f6: /* original 432b, guest PC 0x0c0992f6 */
if(!s->budget--) { s->failed_pc=0x0c0992f6u; return 0; }
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
P_0c0992f8: /* original 6ef6, guest PC 0x0c0992f8 */
if(!s->budget--) { s->failed_pc=0x0c0992f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0992fa;
P_0c0992fa: /* original e018, guest PC 0x0c0992fa */
if(!s->budget--) { s->failed_pc=0x0c0992fau; return 0; }
r[0]=0x00000018u;
goto P_0c0992fc;
P_0c0992fc: /* original 00ec, guest PC 0x0c0992fc */
if(!s->budget--) { s->failed_pc=0x0c0992fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0992fe;
P_0c0992fe: /* original 600c, guest PC 0x0c0992fe */
if(!s->budget--) { s->failed_pc=0x0c0992feu; return 0; }
r[0]=r[0]&255u;
goto P_0c099300;
P_0c099300: /* original 8802, guest PC 0x0c099300 */
if(!s->budget--) { s->failed_pc=0x0c099300u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c099302;
P_0c099302: /* original 8b0e, guest PC 0x0c099302 */
if(!s->budget--) { s->failed_pc=0x0c099302u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099322; }
goto P_0c099304;
P_0c099304: /* original 7f0c, guest PC 0x0c099304 */
if(!s->budget--) { s->failed_pc=0x0c099304u; return 0; }
r[15]+=0x0000000cu;
goto P_0c099306;
P_0c099306: /* original 9056, guest PC 0x0c099306 */
if(!s->budget--) { s->failed_pc=0x0c099306u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0993b6u,2);
goto P_0c099308;
P_0c099308: /* original 4f26, guest PC 0x0c099308 */
if(!s->budget--) { s->failed_pc=0x0c099308u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09930a;
P_0c09930a: /* original e301, guest PC 0x0c09930a */
if(!s->budget--) { s->failed_pc=0x0c09930au; return 0; }
r[3]=0x00000001u;
goto P_0c09930c;
P_0c09930c: /* original 0e34, guest PC 0x0c09930c */
if(!s->budget--) { s->failed_pc=0x0c09930cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09930e;
P_0c09930e: /* original e00d, guest PC 0x0c09930e */
if(!s->budget--) { s->failed_pc=0x0c09930eu; return 0; }
r[0]=0x0000000du;
goto P_0c099310;
P_0c099310: /* original 80bb, guest PC 0x0c099310 */
if(!s->budget--) { s->failed_pc=0x0c099310u; return 0; }
write(ram,r[11]+11,r[0],1);
goto P_0c099312;
P_0c099312: /* original 68f6, guest PC 0x0c099312 */
if(!s->budget--) { s->failed_pc=0x0c099312u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c099314;
P_0c099314: /* original 69f6, guest PC 0x0c099314 */
if(!s->budget--) { s->failed_pc=0x0c099314u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c099316;
P_0c099316: /* original 6af6, guest PC 0x0c099316 */
if(!s->budget--) { s->failed_pc=0x0c099316u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c099318;
P_0c099318: /* original 6bf6, guest PC 0x0c099318 */
if(!s->budget--) { s->failed_pc=0x0c099318u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09931a;
P_0c09931a: /* original 6cf6, guest PC 0x0c09931a */
if(!s->budget--) { s->failed_pc=0x0c09931au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09931c;
P_0c09931c: /* original 6df6, guest PC 0x0c09931c */
if(!s->budget--) { s->failed_pc=0x0c09931cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09931e;
P_0c09931e: /* original a0ec, guest PC 0x0c09931e */
if(!s->budget--) { s->failed_pc=0x0c09931eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0994fa;
P_0c099320: /* original 6ef6, guest PC 0x0c099320 */
if(!s->budget--) { s->failed_pc=0x0c099320u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099322;
P_0c099322: /* original d229, guest PC 0x0c099322 */
if(!s->budget--) { s->failed_pc=0x0c099322u; return 0; }
r[2]=read(ram,0x0c0993c8u,4);
goto P_0c099324;
P_0c099324: /* original 420b, guest PC 0x0c099324 */
if(!s->budget--) { s->failed_pc=0x0c099324u; return 0; }
target=r[2];
r[16]=code_base|0x0c099328u;
r[4]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099328u) { target=s->pc; goto dispatch; }
goto P_0c099328;
P_0c099326: /* original 54d6, guest PC 0x0c099326 */
if(!s->budget--) { s->failed_pc=0x0c099326u; return 0; }
r[4]=read(ram,r[13]+24,4);
goto P_0c099328;
P_0c099328: /* original d327, guest PC 0x0c099328 */
if(!s->budget--) { s->failed_pc=0x0c099328u; return 0; }
r[3]=read(ram,0x0c0993c8u,4);
goto P_0c09932a;
P_0c09932a: /* original 430b, guest PC 0x0c09932a */
if(!s->budget--) { s->failed_pc=0x0c09932au; return 0; }
target=r[3];
r[16]=code_base|0x0c09932eu;
r[4]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09932eu) { target=s->pc; goto dispatch; }
goto P_0c09932e;
P_0c09932c: /* original 54d4, guest PC 0x0c09932c */
if(!s->budget--) { s->failed_pc=0x0c09932cu; return 0; }
r[4]=read(ram,r[13]+16,4);
goto P_0c09932e;
P_0c09932e: /* original d226, guest PC 0x0c09932e */
if(!s->budget--) { s->failed_pc=0x0c09932eu; return 0; }
r[2]=read(ram,0x0c0993c8u,4);
goto P_0c099330;
P_0c099330: /* original 420b, guest PC 0x0c099330 */
if(!s->budget--) { s->failed_pc=0x0c099330u; return 0; }
target=r[2];
r[16]=code_base|0x0c099334u;
r[4]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099334u) { target=s->pc; goto dispatch; }
goto P_0c099334;
P_0c099332: /* original 54d5, guest PC 0x0c099332 */
if(!s->budget--) { s->failed_pc=0x0c099332u; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c099334;
P_0c099334: /* original d324, guest PC 0x0c099334 */
if(!s->budget--) { s->failed_pc=0x0c099334u; return 0; }
r[3]=read(ram,0x0c0993c8u,4);
goto P_0c099336;
P_0c099336: /* original 430b, guest PC 0x0c099336 */
if(!s->budget--) { s->failed_pc=0x0c099336u; return 0; }
target=r[3];
r[16]=code_base|0x0c09933au;
r[4]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09933au) { target=s->pc; goto dispatch; }
goto P_0c09933a;
P_0c099338: /* original 54df, guest PC 0x0c099338 */
if(!s->budget--) { s->failed_pc=0x0c099338u; return 0; }
r[4]=read(ram,r[13]+60,4);
goto P_0c09933a;
P_0c09933a: /* original d323, guest PC 0x0c09933a */
if(!s->budget--) { s->failed_pc=0x0c09933au; return 0; }
r[3]=read(ram,0x0c0993c8u,4);
goto P_0c09933c;
P_0c09933c: /* original e040, guest PC 0x0c09933c */
if(!s->budget--) { s->failed_pc=0x0c09933cu; return 0; }
r[0]=0x00000040u;
goto P_0c09933e;
P_0c09933e: /* original 430b, guest PC 0x0c09933e */
if(!s->budget--) { s->failed_pc=0x0c09933eu; return 0; }
target=r[3];
r[16]=code_base|0x0c099342u;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099342u) { target=s->pc; goto dispatch; }
goto P_0c099342;
P_0c099340: /* original 04de, guest PC 0x0c099340 */
if(!s->budget--) { s->failed_pc=0x0c099340u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099342;
P_0c099342: /* original d221, guest PC 0x0c099342 */
if(!s->budget--) { s->failed_pc=0x0c099342u; return 0; }
r[2]=read(ram,0x0c0993c8u,4);
goto P_0c099344;
P_0c099344: /* original 420b, guest PC 0x0c099344 */
if(!s->budget--) { s->failed_pc=0x0c099344u; return 0; }
target=r[2];
r[16]=code_base|0x0c099348u;
r[4]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099348u) { target=s->pc; goto dispatch; }
goto P_0c099348;
P_0c099346: /* original 54d7, guest PC 0x0c099346 */
if(!s->budget--) { s->failed_pc=0x0c099346u; return 0; }
r[4]=read(ram,r[13]+28,4);
goto P_0c099348;
P_0c099348: /* original d31f, guest PC 0x0c099348 */
if(!s->budget--) { s->failed_pc=0x0c099348u; return 0; }
r[3]=read(ram,0x0c0993c8u,4);
goto P_0c09934a;
P_0c09934a: /* original 430b, guest PC 0x0c09934a */
if(!s->budget--) { s->failed_pc=0x0c09934au; return 0; }
target=r[3];
r[16]=code_base|0x0c09934eu;
r[4]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09934eu) { target=s->pc; goto dispatch; }
goto P_0c09934e;
P_0c09934c: /* original 54dd, guest PC 0x0c09934c */
if(!s->budget--) { s->failed_pc=0x0c09934cu; return 0; }
r[4]=read(ram,r[13]+52,4);
goto P_0c09934e;
P_0c09934e: /* original d21e, guest PC 0x0c09934e */
if(!s->budget--) { s->failed_pc=0x0c09934eu; return 0; }
r[2]=read(ram,0x0c0993c8u,4);
goto P_0c099350;
P_0c099350: /* original 420b, guest PC 0x0c099350 */
if(!s->budget--) { s->failed_pc=0x0c099350u; return 0; }
target=r[2];
r[16]=code_base|0x0c099354u;
r[4]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099354u) { target=s->pc; goto dispatch; }
goto P_0c099354;
P_0c099352: /* original 54de, guest PC 0x0c099352 */
if(!s->budget--) { s->failed_pc=0x0c099352u; return 0; }
r[4]=read(ram,r[13]+56,4);
goto P_0c099354;
P_0c099354: /* original d31f, guest PC 0x0c099354 */
if(!s->budget--) { s->failed_pc=0x0c099354u; return 0; }
r[3]=read(ram,0x0c0993d4u,4);
goto P_0c099356;
P_0c099356: /* original e054, guest PC 0x0c099356 */
if(!s->budget--) { s->failed_pc=0x0c099356u; return 0; }
r[0]=0x00000054u;
goto P_0c099358;
P_0c099358: /* original d51d, guest PC 0x0c099358 */
if(!s->budget--) { s->failed_pc=0x0c099358u; return 0; }
r[5]=read(ram,0x0c0993d0u,4);
goto P_0c09935a;
P_0c09935a: /* original 430b, guest PC 0x0c09935a */
if(!s->budget--) { s->failed_pc=0x0c09935au; return 0; }
target=r[3];
r[16]=code_base|0x0c09935eu;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09935eu) { target=s->pc; goto dispatch; }
goto P_0c09935e;
P_0c09935c: /* original 04de, guest PC 0x0c09935c */
if(!s->budget--) { s->failed_pc=0x0c09935cu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c09935e;
P_0c09935e: /* original 902b, guest PC 0x0c09935e */
if(!s->budget--) { s->failed_pc=0x0c09935eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0993b8u,2);
goto P_0c099360;
P_0c099360: /* original e304, guest PC 0x0c099360 */
if(!s->budget--) { s->failed_pc=0x0c099360u; return 0; }
r[3]=0x00000004u;
goto P_0c099362;
P_0c099362: /* original 0ec4, guest PC 0x0c099362 */
if(!s->budget--) { s->failed_pc=0x0c099362u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c099364;
P_0c099364: /* original 9029, guest PC 0x0c099364 */
if(!s->budget--) { s->failed_pc=0x0c099364u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0993bau,2);
goto P_0c099366;
P_0c099366: /* original 0a34, guest PC 0x0c099366 */
if(!s->budget--) { s->failed_pc=0x0c099366u; return 0; }
write(ram,r[10]+r[0],r[3],1);
goto P_0c099368;
P_0c099368: /* original 9028, guest PC 0x0c099368 */
if(!s->budget--) { s->failed_pc=0x0c099368u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0993bcu,2);
goto P_0c09936a;
P_0c09936a: /* original d31b, guest PC 0x0c09936a */
if(!s->budget--) { s->failed_pc=0x0c09936au; return 0; }
r[3]=read(ram,0x0c0993d8u,4);
goto P_0c09936c;
P_0c09936c: /* original 54dc, guest PC 0x0c09936c */
if(!s->budget--) { s->failed_pc=0x0c09936cu; return 0; }
r[4]=read(ram,r[13]+48,4);
goto P_0c09936e;
P_0c09936e: /* original 0436, guest PC 0x0c09936e */
if(!s->budget--) { s->failed_pc=0x0c09936eu; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c099370;
P_0c099370: /* original 9326, guest PC 0x0c099370 */
if(!s->budget--) { s->failed_pc=0x0c099370u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0993c0u,2);
goto P_0c099372;
P_0c099372: /* original 52e2, guest PC 0x0c099372 */
if(!s->budget--) { s->failed_pc=0x0c099372u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c099374;
P_0c099374: /* original 9423, guest PC 0x0c099374 */
if(!s->budget--) { s->failed_pc=0x0c099374u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0993beu,2);
goto P_0c099376;
P_0c099376: /* original 2238, guest PC 0x0c099376 */
if(!s->budget--) { s->failed_pc=0x0c099376u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c099378;
P_0c099378: /* original 890b, guest PC 0x0c099378 */
if(!s->budget--) { s->failed_pc=0x0c099378u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099392; }
goto P_0c09937a;
P_0c09937a: /* original 63f2, guest PC 0x0c09937a */
if(!s->budget--) { s->failed_pc=0x0c09937au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09937c;
P_0c09937c: /* original e042, guest PC 0x0c09937c */
if(!s->budget--) { s->failed_pc=0x0c09937cu; return 0; }
r[0]=0x00000042u;
goto P_0c09937e;
P_0c09937e: /* original 51f1, guest PC 0x0c09937e */
if(!s->budget--) { s->failed_pc=0x0c09937eu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c099380;
P_0c099380: /* original 03c5, guest PC 0x0c099380 */
if(!s->budget--) { s->failed_pc=0x0c099380u; return 0; }
write(ram,r[3]+r[0],r[12],2);
goto P_0c099382;
P_0c099382: /* original 01c5, guest PC 0x0c099382 */
if(!s->budget--) { s->failed_pc=0x0c099382u; return 0; }
write(ram,r[1]+r[0],r[12],2);
goto P_0c099384;
P_0c099384: /* original 951d, guest PC 0x0c099384 */
if(!s->budget--) { s->failed_pc=0x0c099384u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0993c2u,2);
goto P_0c099386;
P_0c099386: /* original 901d, guest PC 0x0c099386 */
if(!s->budget--) { s->failed_pc=0x0c099386u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0993c4u,2);
goto P_0c099388;
P_0c099388: /* original 6453, guest PC 0x0c099388 */
if(!s->budget--) { s->failed_pc=0x0c099388u; return 0; }
r[4]=r[5];
goto P_0c09938a;
P_0c09938a: /* original 0e45, guest PC 0x0c09938a */
if(!s->budget--) { s->failed_pc=0x0c09938au; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c09938c;
P_0c09938c: /* original c713, guest PC 0x0c09938c */
if(!s->budget--) { s->failed_pc=0x0c09938cu; return 0; }
r[0]=code_base|0x000993dcu;
goto P_0c09938e;
P_0c09938e: /* original f308, guest PC 0x0c09938e */
if(!s->budget--) { s->failed_pc=0x0c09938eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c099390;
P_0c099390: /* original fe3a, guest PC 0x0c099390 */
if(!s->budget--) { s->failed_pc=0x0c099390u; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c099392;
P_0c099392: /* original 7f0c, guest PC 0x0c099392 */
if(!s->budget--) { s->failed_pc=0x0c099392u; return 0; }
r[15]+=0x0000000cu;
goto P_0c099394;
P_0c099394: /* original 1b43, guest PC 0x0c099394 */
if(!s->budget--) { s->failed_pc=0x0c099394u; return 0; }
write(ram,r[11]+12,r[4],4);
goto P_0c099396;
P_0c099396: /* original 4f26, guest PC 0x0c099396 */
if(!s->budget--) { s->failed_pc=0x0c099396u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c099398;
P_0c099398: /* original e31f, guest PC 0x0c099398 */
if(!s->budget--) { s->failed_pc=0x0c099398u; return 0; }
r[3]=0x0000001fu;
goto P_0c09939a;
P_0c09939a: /* original e010, guest PC 0x0c09939a */
if(!s->budget--) { s->failed_pc=0x0c09939au; return 0; }
r[0]=0x00000010u;
goto P_0c09939c;
P_0c09939c: /* original 0b34, guest PC 0x0c09939c */
if(!s->budget--) { s->failed_pc=0x0c09939cu; return 0; }
write(ram,r[11]+r[0],r[3],1);
goto P_0c09939e;
P_0c09939e: /* original 84bb, guest PC 0x0c09939e */
if(!s->budget--) { s->failed_pc=0x0c09939eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+11,1);
goto P_0c0993a0;
P_0c0993a0: /* original 7001, guest PC 0x0c0993a0 */
if(!s->budget--) { s->failed_pc=0x0c0993a0u; return 0; }
r[0]+=0x00000001u;
goto P_0c0993a2;
P_0c0993a2: /* original 80bb, guest PC 0x0c0993a2 */
if(!s->budget--) { s->failed_pc=0x0c0993a2u; return 0; }
write(ram,r[11]+11,r[0],1);
goto P_0c0993a4;
P_0c0993a4: /* original 68f6, guest PC 0x0c0993a4 */
if(!s->budget--) { s->failed_pc=0x0c0993a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0993a6;
P_0c0993a6: /* original 69f6, guest PC 0x0c0993a6 */
if(!s->budget--) { s->failed_pc=0x0c0993a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0993a8;
P_0c0993a8: /* original 6af6, guest PC 0x0c0993a8 */
if(!s->budget--) { s->failed_pc=0x0c0993a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0993aa;
P_0c0993aa: /* original 6bf6, guest PC 0x0c0993aa */
if(!s->budget--) { s->failed_pc=0x0c0993aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0993ac;
P_0c0993ac: /* original 6cf6, guest PC 0x0c0993ac */
if(!s->budget--) { s->failed_pc=0x0c0993acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0993ae;
P_0c0993ae: /* original 6df6, guest PC 0x0c0993ae */
if(!s->budget--) { s->failed_pc=0x0c0993aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0993b0;
P_0c0993b0: /* original a016, guest PC 0x0c0993b0 */
if(!s->budget--) { s->failed_pc=0x0c0993b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0993e0;
P_0c0993b2: /* original 6ef6, guest PC 0x0c0993b2 */
if(!s->budget--) { s->failed_pc=0x0c0993b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0993b4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0993b4u; return 0; } return 1;
P_0c0993e0: /* original 2fe6, guest PC 0x0c0993e0 */
if(!s->budget--) { s->failed_pc=0x0c0993e0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0993e2;
P_0c0993e2: /* original 2fd6, guest PC 0x0c0993e2 */
if(!s->budget--) { s->failed_pc=0x0c0993e2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0993e4;
P_0c0993e4: /* original 2fc6, guest PC 0x0c0993e4 */
if(!s->budget--) { s->failed_pc=0x0c0993e4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0993e6;
P_0c0993e6: /* original 2fb6, guest PC 0x0c0993e6 */
if(!s->budget--) { s->failed_pc=0x0c0993e6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0993e8;
P_0c0993e8: /* original 4f22, guest PC 0x0c0993e8 */
if(!s->budget--) { s->failed_pc=0x0c0993e8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0993ea;
P_0c0993ea: /* original d334, guest PC 0x0c0993ea */
if(!s->budget--) { s->failed_pc=0x0c0993eau; return 0; }
r[3]=read(ram,0x0c0994bcu,4);
goto P_0c0993ec;
P_0c0993ec: /* original de31, guest PC 0x0c0993ec */
if(!s->budget--) { s->failed_pc=0x0c0993ecu; return 0; }
r[14]=read(ram,0x0c0994b4u,4);
goto P_0c0993ee;
P_0c0993ee: /* original 7ffc, guest PC 0x0c0993ee */
if(!s->budget--) { s->failed_pc=0x0c0993eeu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0993f0;
P_0c0993f0: /* original dc31, guest PC 0x0c0993f0 */
if(!s->budget--) { s->failed_pc=0x0c0993f0u; return 0; }
r[12]=read(ram,0x0c0994b8u,4);
goto P_0c0993f2;
P_0c0993f2: /* original 2f32, guest PC 0x0c0993f2 */
if(!s->budget--) { s->failed_pc=0x0c0993f2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0993f4;
P_0c0993f4: /* original d133, guest PC 0x0c0993f4 */
if(!s->budget--) { s->failed_pc=0x0c0993f4u; return 0; }
r[1]=read(ram,0x0c0994c4u,4);
goto P_0c0993f6;
P_0c0993f6: /* original d332, guest PC 0x0c0993f6 */
if(!s->budget--) { s->failed_pc=0x0c0993f6u; return 0; }
r[3]=read(ram,0x0c0994c0u,4);
goto P_0c0993f8;
P_0c0993f8: /* original 6212, guest PC 0x0c0993f8 */
if(!s->budget--) { s->failed_pc=0x0c0993f8u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0993fa;
P_0c0993fa: /* original 2238, guest PC 0x0c0993fa */
if(!s->budget--) { s->failed_pc=0x0c0993fau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0993fc;
P_0c0993fc: /* original 8b44, guest PC 0x0c0993fc */
if(!s->budget--) { s->failed_pc=0x0c0993fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099488; }
goto P_0c0993fe;
P_0c0993fe: /* original 9055, guest PC 0x0c0993fe */
if(!s->budget--) { s->failed_pc=0x0c0993feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0994acu,2);
goto P_0c099400;
P_0c099400: /* original 00ed, guest PC 0x0c099400 */
if(!s->budget--) { s->failed_pc=0x0c099400u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c099402;
P_0c099402: /* original 4015, guest PC 0x0c099402 */
if(!s->budget--) { s->failed_pc=0x0c099402u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c099404;
P_0c099404: /* original 8b03, guest PC 0x0c099404 */
if(!s->budget--) { s->failed_pc=0x0c099404u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09940e; }
goto P_0c099406;
P_0c099406: /* original 9051, guest PC 0x0c099406 */
if(!s->budget--) { s->failed_pc=0x0c099406u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0994acu,2);
goto P_0c099408;
P_0c099408: /* original 03ed, guest PC 0x0c099408 */
if(!s->budget--) { s->failed_pc=0x0c099408u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09940a;
P_0c09940a: /* original 73ff, guest PC 0x0c09940a */
if(!s->budget--) { s->failed_pc=0x0c09940au; return 0; }
r[3]+=0xffffffffu;
goto P_0c09940c;
P_0c09940c: /* original 0e35, guest PC 0x0c09940c */
if(!s->budget--) { s->failed_pc=0x0c09940cu; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c09940e;
P_0c09940e: /* original 904e, guest PC 0x0c09940e */
if(!s->budget--) { s->failed_pc=0x0c09940eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0994aeu,2);
goto P_0c099410;
P_0c099410: /* original e3f8, guest PC 0x0c099410 */
if(!s->budget--) { s->failed_pc=0x0c099410u; return 0; }
r[3]=0xfffffff8u;
goto P_0c099412;
P_0c099412: /* original 04ce, guest PC 0x0c099412 */
if(!s->budget--) { s->failed_pc=0x0c099412u; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c099414;
P_0c099414: /* original 7004, guest PC 0x0c099414 */
if(!s->budget--) { s->failed_pc=0x0c099414u; return 0; }
r[0]+=0x00000004u;
goto P_0c099416;
P_0c099416: /* original 0dce, guest PC 0x0c099416 */
if(!s->budget--) { s->failed_pc=0x0c099416u; return 0; }
r[13]=read(ram,r[12]+r[0],4);
goto P_0c099418;
P_0c099418: /* original e029, guest PC 0x0c099418 */
if(!s->budget--) { s->failed_pc=0x0c099418u; return 0; }
r[0]=0x00000029u;
goto P_0c09941a;
P_0c09941a: /* original 00ec, guest PC 0x0c09941a */
if(!s->budget--) { s->failed_pc=0x0c09941au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09941c;
P_0c09941c: /* original 6143, guest PC 0x0c09941c */
if(!s->budget--) { s->failed_pc=0x0c09941cu; return 0; }
r[1]=r[4];
goto P_0c09941e;
P_0c09941e: /* original 6bd3, guest PC 0x0c09941e */
if(!s->budget--) { s->failed_pc=0x0c09941eu; return 0; }
r[11]=r[13];
goto P_0c099420;
P_0c099420: /* original 413c, guest PC 0x0c099420 */
if(!s->budget--) { s->failed_pc=0x0c099420u; return 0; }
r[1]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[1]>>((-r[3])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[3]&31u);
goto P_0c099422;
P_0c099422: /* original 600c, guest PC 0x0c099422 */
if(!s->budget--) { s->failed_pc=0x0c099422u; return 0; }
r[0]=r[0]&255u;
goto P_0c099424;
P_0c099424: /* original 4b21, guest PC 0x0c099424 */
if(!s->budget--) { s->failed_pc=0x0c099424u; return 0; }
r[17]=(r[17]&~1u)|((r[11]&1)!=0);
r[11]=(uint32_t)((int32_t)r[11]>>1);
goto P_0c099426;
P_0c099426: /* original 8803, guest PC 0x0c099426 */
if(!s->budget--) { s->failed_pc=0x0c099426u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c099428;
P_0c099428: /* original 8b02, guest PC 0x0c099428 */
if(!s->budget--) { s->failed_pc=0x0c099428u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099430; }
goto P_0c09942a;
P_0c09942a: /* original 241b, guest PC 0x0c09942a */
if(!s->budget--) { s->failed_pc=0x0c09942au; return 0; }
r[4]|=r[1];
goto P_0c09942c;
P_0c09942c: /* original a004, guest PC 0x0c09942c */
if(!s->budget--) { s->failed_pc=0x0c09942cu; return 0; }
r[13]|=r[11];
goto P_0c099438;
P_0c09942e: /* original 2dbb, guest PC 0x0c09942e */
if(!s->budget--) { s->failed_pc=0x0c09942eu; return 0; }
r[13]|=r[11];
goto P_0c099430;
P_0c099430: /* original 8801, guest PC 0x0c099430 */
if(!s->budget--) { s->failed_pc=0x0c099430u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c099432;
P_0c099432: /* original 8901, guest PC 0x0c099432 */
if(!s->budget--) { s->failed_pc=0x0c099432u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099438; }
goto P_0c099434;
P_0c099434: /* original 6db3, guest PC 0x0c099434 */
if(!s->budget--) { s->failed_pc=0x0c099434u; return 0; }
r[13]=r[11];
goto P_0c099436;
P_0c099436: /* original 6413, guest PC 0x0c099436 */
if(!s->budget--) { s->failed_pc=0x0c099436u; return 0; }
r[4]=r[1];
goto P_0c099438;
P_0c099438: /* original 933a, guest PC 0x0c099438 */
if(!s->budget--) { s->failed_pc=0x0c099438u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0994b0u,2);
goto P_0c09943a;
P_0c09943a: /* original 2438, guest PC 0x0c09943a */
if(!s->budget--) { s->failed_pc=0x0c09943au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c09943c;
P_0c09943c: /* original 8b15, guest PC 0x0c09943c */
if(!s->budget--) { s->failed_pc=0x0c09943cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09946a; }
goto P_0c09943e;
P_0c09943e: /* original d322, guest PC 0x0c09943e */
if(!s->budget--) { s->failed_pc=0x0c09943eu; return 0; }
r[3]=read(ram,0x0c0994c8u,4);
goto P_0c099440;
P_0c099440: /* original 64f2, guest PC 0x0c099440 */
if(!s->budget--) { s->failed_pc=0x0c099440u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c099442;
P_0c099442: /* original 5be2, guest PC 0x0c099442 */
if(!s->budget--) { s->failed_pc=0x0c099442u; return 0; }
r[11]=read(ram,r[14]+8,4);
goto P_0c099444;
P_0c099444: /* original 430b, guest PC 0x0c099444 */
if(!s->budget--) { s->failed_pc=0x0c099444u; return 0; }
target=r[3];
r[16]=code_base|0x0c099448u;
r[4]+=0x00000013u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099448u) { target=s->pc; goto dispatch; }
goto P_0c099448;
P_0c099446: /* original 7413, guest PC 0x0c099446 */
if(!s->budget--) { s->failed_pc=0x0c099446u; return 0; }
r[4]+=0x00000013u;
goto P_0c099448;
P_0c099448: /* original 640c, guest PC 0x0c099448 */
if(!s->budget--) { s->failed_pc=0x0c099448u; return 0; }
r[4]=r[0]&255u;
goto P_0c09944a;
P_0c09944a: /* original e029, guest PC 0x0c09944a */
if(!s->budget--) { s->failed_pc=0x0c09944au; return 0; }
r[0]=0x00000029u;
goto P_0c09944c;
P_0c09944c: /* original 00ec, guest PC 0x0c09944c */
if(!s->budget--) { s->failed_pc=0x0c09944cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09944e;
P_0c09944e: /* original 600c, guest PC 0x0c09944e */
if(!s->budget--) { s->failed_pc=0x0c09944eu; return 0; }
r[0]=r[0]&255u;
goto P_0c099450;
P_0c099450: /* original 8803, guest PC 0x0c099450 */
if(!s->budget--) { s->failed_pc=0x0c099450u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c099452;
P_0c099452: /* original 8b07, guest PC 0x0c099452 */
if(!s->budget--) { s->failed_pc=0x0c099452u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099464; }
goto P_0c099454;
P_0c099454: /* original 2448, guest PC 0x0c099454 */
if(!s->budget--) { s->failed_pc=0x0c099454u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c099456;
P_0c099456: /* original 8905, guest PC 0x0c099456 */
if(!s->budget--) { s->failed_pc=0x0c099456u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099464; }
goto P_0c099458;
P_0c099458: /* original d31c, guest PC 0x0c099458 */
if(!s->budget--) { s->failed_pc=0x0c099458u; return 0; }
r[3]=read(ram,0x0c0994ccu,4);
goto P_0c09945a;
P_0c09945a: /* original 23b8, guest PC 0x0c09945a */
if(!s->budget--) { s->failed_pc=0x0c09945au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c09945c;
P_0c09945c: /* original 8b02, guest PC 0x0c09945c */
if(!s->budget--) { s->failed_pc=0x0c09945cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099464; }
goto P_0c09945e;
P_0c09945e: /* original e204, guest PC 0x0c09945e */
if(!s->budget--) { s->failed_pc=0x0c09945eu; return 0; }
r[2]=0x00000004u;
goto P_0c099460;
P_0c099460: /* original 2b28, guest PC 0x0c099460 */
if(!s->budget--) { s->failed_pc=0x0c099460u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[2])==0)!=0);
goto P_0c099462;
P_0c099462: /* original 8b02, guest PC 0x0c099462 */
if(!s->budget--) { s->failed_pc=0x0c099462u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09946a; }
goto P_0c099464;
P_0c099464: /* original e310, guest PC 0x0c099464 */
if(!s->budget--) { s->failed_pc=0x0c099464u; return 0; }
r[3]=0x00000010u;
goto P_0c099466;
P_0c099466: /* original 2d38, guest PC 0x0c099466 */
if(!s->budget--) { s->failed_pc=0x0c099466u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[3])==0)!=0);
goto P_0c099468;
P_0c099468: /* original 8b02, guest PC 0x0c099468 */
if(!s->budget--) { s->failed_pc=0x0c099468u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099470; }
goto P_0c09946a;
P_0c09946a: /* original 52c3, guest PC 0x0c09946a */
if(!s->budget--) { s->failed_pc=0x0c09946au; return 0; }
r[2]=read(ram,r[12]+12,4);
goto P_0c09946c;
P_0c09946c: /* original 4215, guest PC 0x0c09946c */
if(!s->budget--) { s->failed_pc=0x0c09946cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c09946e;
P_0c09946e: /* original 8906, guest PC 0x0c09946e */
if(!s->budget--) { s->failed_pc=0x0c09946eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09947e; }
goto P_0c099470;
P_0c099470: /* original 7f04, guest PC 0x0c099470 */
if(!s->budget--) { s->failed_pc=0x0c099470u; return 0; }
r[15]+=0x00000004u;
goto P_0c099472;
P_0c099472: /* original 4f26, guest PC 0x0c099472 */
if(!s->budget--) { s->failed_pc=0x0c099472u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c099474;
P_0c099474: /* original 6bf6, guest PC 0x0c099474 */
if(!s->budget--) { s->failed_pc=0x0c099474u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c099476;
P_0c099476: /* original 6cf6, guest PC 0x0c099476 */
if(!s->budget--) { s->failed_pc=0x0c099476u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c099478;
P_0c099478: /* original 6df6, guest PC 0x0c099478 */
if(!s->budget--) { s->failed_pc=0x0c099478u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09947a;
P_0c09947a: /* original a061, guest PC 0x0c09947a */
if(!s->budget--) { s->failed_pc=0x0c09947au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099540;
P_0c09947c: /* original 6ef6, guest PC 0x0c09947c */
if(!s->budget--) { s->failed_pc=0x0c09947cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09947e;
P_0c09947e: /* original 9018, guest PC 0x0c09947e */
if(!s->budget--) { s->failed_pc=0x0c09947eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0994b2u,2);
goto P_0c099480;
P_0c099480: /* original 04ec, guest PC 0x0c099480 */
if(!s->budget--) { s->failed_pc=0x0c099480u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099482;
P_0c099482: /* original 644c, guest PC 0x0c099482 */
if(!s->budget--) { s->failed_pc=0x0c099482u; return 0; }
r[4]=r[4]&255u;
goto P_0c099484;
P_0c099484: /* original 2448, guest PC 0x0c099484 */
if(!s->budget--) { s->failed_pc=0x0c099484u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c099486;
P_0c099486: /* original 8b07, guest PC 0x0c099486 */
if(!s->budget--) { s->failed_pc=0x0c099486u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099498; }
goto P_0c099488;
P_0c099488: /* original 7f04, guest PC 0x0c099488 */
if(!s->budget--) { s->failed_pc=0x0c099488u; return 0; }
r[15]+=0x00000004u;
goto P_0c09948a;
P_0c09948a: /* original d211, guest PC 0x0c09948a */
if(!s->budget--) { s->failed_pc=0x0c09948au; return 0; }
r[2]=read(ram,0x0c0994d0u,4);
goto P_0c09948c;
P_0c09948c: /* original 4f26, guest PC 0x0c09948c */
if(!s->budget--) { s->failed_pc=0x0c09948cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09948e;
P_0c09948e: /* original 6bf6, guest PC 0x0c09948e */
if(!s->budget--) { s->failed_pc=0x0c09948eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c099490;
P_0c099490: /* original 6cf6, guest PC 0x0c099490 */
if(!s->budget--) { s->failed_pc=0x0c099490u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c099492;
P_0c099492: /* original 6df6, guest PC 0x0c099492 */
if(!s->budget--) { s->failed_pc=0x0c099492u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c099494;
P_0c099494: /* original 422b, guest PC 0x0c099494 */
if(!s->budget--) { s->failed_pc=0x0c099494u; return 0; }
target=r[2];
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
P_0c099496: /* original 6ef6, guest PC 0x0c099496 */
if(!s->budget--) { s->failed_pc=0x0c099496u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099498;
P_0c099498: /* original 6043, guest PC 0x0c099498 */
if(!s->budget--) { s->failed_pc=0x0c099498u; return 0; }
r[0]=r[4];
goto P_0c09949a;
P_0c09949a: /* original 8801, guest PC 0x0c09949a */
if(!s->budget--) { s->failed_pc=0x0c09949au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09949c;
P_0c09949c: /* original 891a, guest PC 0x0c09949c */
if(!s->budget--) { s->failed_pc=0x0c09949cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0994d4; }
goto P_0c09949e;
P_0c09949e: /* original 7f04, guest PC 0x0c09949e */
if(!s->budget--) { s->failed_pc=0x0c09949eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0994a0;
P_0c0994a0: /* original 4f26, guest PC 0x0c0994a0 */
if(!s->budget--) { s->failed_pc=0x0c0994a0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0994a2;
P_0c0994a2: /* original 6bf6, guest PC 0x0c0994a2 */
if(!s->budget--) { s->failed_pc=0x0c0994a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0994a4;
P_0c0994a4: /* original 6cf6, guest PC 0x0c0994a4 */
if(!s->budget--) { s->failed_pc=0x0c0994a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0994a6;
P_0c0994a6: /* original 6df6, guest PC 0x0c0994a6 */
if(!s->budget--) { s->failed_pc=0x0c0994a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0994a8;
P_0c0994a8: /* original a02c, guest PC 0x0c0994a8 */
if(!s->budget--) { s->failed_pc=0x0c0994a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099504;
P_0c0994aa: /* original 6ef6, guest PC 0x0c0994aa */
if(!s->budget--) { s->failed_pc=0x0c0994aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0994acu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0994acu; return 0; } return 1;
P_0c0994d4: /* original d238, guest PC 0x0c0994d4 */
if(!s->budget--) { s->failed_pc=0x0c0994d4u; return 0; }
r[2]=read(ram,0x0c0995b8u,4);
goto P_0c0994d6;
P_0c0994d6: /* original d337, guest PC 0x0c0994d6 */
if(!s->budget--) { s->failed_pc=0x0c0994d6u; return 0; }
r[3]=read(ram,0x0c0995b4u,4);
goto P_0c0994d8;
P_0c0994d8: /* original d535, guest PC 0x0c0994d8 */
if(!s->budget--) { s->failed_pc=0x0c0994d8u; return 0; }
r[5]=read(ram,0x0c0995b0u,4);
goto P_0c0994da;
P_0c0994da: /* original 420b, guest PC 0x0c0994da */
if(!s->budget--) { s->failed_pc=0x0c0994dau; return 0; }
target=r[2];
r[16]=code_base|0x0c0994deu;
tmp=read(ram,r[3],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0994deu) { target=s->pc; goto dispatch; }
goto P_0c0994de;
P_0c0994dc: /* original 6432, guest PC 0x0c0994dc */
if(!s->budget--) { s->failed_pc=0x0c0994dcu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0994de;
P_0c0994de: /* original 9060, guest PC 0x0c0994de */
if(!s->budget--) { s->failed_pc=0x0c0994deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0995a2u,2);
goto P_0c0994e0;
P_0c0994e0: /* original 01ec, guest PC 0x0c0994e0 */
if(!s->budget--) { s->failed_pc=0x0c0994e0u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0994e2;
P_0c0994e2: /* original 2118, guest PC 0x0c0994e2 */
if(!s->budget--) { s->failed_pc=0x0c0994e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0994e4;
P_0c0994e4: /* original 8b02, guest PC 0x0c0994e4 */
if(!s->budget--) { s->failed_pc=0x0c0994e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0994ec; }
goto P_0c0994e6;
P_0c0994e6: /* original d335, guest PC 0x0c0994e6 */
if(!s->budget--) { s->failed_pc=0x0c0994e6u; return 0; }
r[3]=read(ram,0x0c0995bcu,4);
goto P_0c0994e8;
P_0c0994e8: /* original 430b, guest PC 0x0c0994e8 */
if(!s->budget--) { s->failed_pc=0x0c0994e8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0994ecu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0994ecu) { target=s->pc; goto dispatch; }
goto P_0c0994ec;
P_0c0994ea: /* original 0009, guest PC 0x0c0994ea */
if(!s->budget--) { s->failed_pc=0x0c0994eau; return 0; }
goto P_0c0994ec;
P_0c0994ec: /* original 7f04, guest PC 0x0c0994ec */
if(!s->budget--) { s->failed_pc=0x0c0994ecu; return 0; }
r[15]+=0x00000004u;
goto P_0c0994ee;
P_0c0994ee: /* original 4f26, guest PC 0x0c0994ee */
if(!s->budget--) { s->failed_pc=0x0c0994eeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0994f0;
P_0c0994f0: /* original 6bf6, guest PC 0x0c0994f0 */
if(!s->budget--) { s->failed_pc=0x0c0994f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0994f2;
P_0c0994f2: /* original 6cf6, guest PC 0x0c0994f2 */
if(!s->budget--) { s->failed_pc=0x0c0994f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0994f4;
P_0c0994f4: /* original 6df6, guest PC 0x0c0994f4 */
if(!s->budget--) { s->failed_pc=0x0c0994f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0994f6;
P_0c0994f6: /* original a000, guest PC 0x0c0994f6 */
if(!s->budget--) { s->failed_pc=0x0c0994f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0994fa;
P_0c0994f8: /* original 6ef6, guest PC 0x0c0994f8 */
if(!s->budget--) { s->failed_pc=0x0c0994f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0994fa;
P_0c0994fa: /* original 9053, guest PC 0x0c0994fa */
if(!s->budget--) { s->failed_pc=0x0c0994fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0995a4u,2);
goto P_0c0994fc;
P_0c0994fc: /* original e302, guest PC 0x0c0994fc */
if(!s->budget--) { s->failed_pc=0x0c0994fcu; return 0; }
r[3]=0x00000002u;
goto P_0c0994fe;
P_0c0994fe: /* original d430, guest PC 0x0c0994fe */
if(!s->budget--) { s->failed_pc=0x0c0994feu; return 0; }
r[4]=read(ram,0x0c0995c0u,4);
goto P_0c099500;
P_0c099500: /* original a000, guest PC 0x0c099500 */
if(!s->budget--) { s->failed_pc=0x0c099500u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c099504;
P_0c099502: /* original 0434, guest PC 0x0c099502 */
if(!s->budget--) { s->failed_pc=0x0c099502u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c099504;
P_0c099504: /* original 2fe6, guest PC 0x0c099504 */
if(!s->budget--) { s->failed_pc=0x0c099504u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099506;
P_0c099506: /* original 904e, guest PC 0x0c099506 */
if(!s->budget--) { s->failed_pc=0x0c099506u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0995a6u,2);
goto P_0c099508;
P_0c099508: /* original de2d, guest PC 0x0c099508 */
if(!s->budget--) { s->failed_pc=0x0c099508u; return 0; }
r[14]=read(ram,0x0c0995c0u,4);
goto P_0c09950a;
P_0c09950a: /* original 4f22, guest PC 0x0c09950a */
if(!s->budget--) { s->failed_pc=0x0c09950au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09950c;
P_0c09950c: /* original 03ec, guest PC 0x0c09950c */
if(!s->budget--) { s->failed_pc=0x0c09950cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09950e;
P_0c09950e: /* original 2338, guest PC 0x0c09950e */
if(!s->budget--) { s->failed_pc=0x0c09950eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c099510;
P_0c099510: /* original 8b03, guest PC 0x0c099510 */
if(!s->budget--) { s->failed_pc=0x0c099510u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09951a; }
goto P_0c099512;
P_0c099512: /* original d32c, guest PC 0x0c099512 */
if(!s->budget--) { s->failed_pc=0x0c099512u; return 0; }
r[3]=read(ram,0x0c0995c4u,4);
goto P_0c099514;
P_0c099514: /* original 9048, guest PC 0x0c099514 */
if(!s->budget--) { s->failed_pc=0x0c099514u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0995a8u,2);
goto P_0c099516;
P_0c099516: /* original 430b, guest PC 0x0c099516 */
if(!s->budget--) { s->failed_pc=0x0c099516u; return 0; }
target=r[3];
r[16]=code_base|0x0c09951au;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09951au) { target=s->pc; goto dispatch; }
goto P_0c09951a;
P_0c099518: /* original 04ee, guest PC 0x0c099518 */
if(!s->budget--) { s->failed_pc=0x0c099518u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09951a;
P_0c09951a: /* original 9046, guest PC 0x0c09951a */
if(!s->budget--) { s->failed_pc=0x0c09951au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0995aau,2);
goto P_0c09951c;
P_0c09951c: /* original 02ec, guest PC 0x0c09951c */
if(!s->budget--) { s->failed_pc=0x0c09951cu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09951e;
P_0c09951e: /* original 2228, guest PC 0x0c09951e */
if(!s->budget--) { s->failed_pc=0x0c09951eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c099520;
P_0c099520: /* original 8906, guest PC 0x0c099520 */
if(!s->budget--) { s->failed_pc=0x0c099520u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099530; }
goto P_0c099522;
P_0c099522: /* original 9040, guest PC 0x0c099522 */
if(!s->budget--) { s->failed_pc=0x0c099522u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0995a6u,2);
goto P_0c099524;
P_0c099524: /* original 03ec, guest PC 0x0c099524 */
if(!s->budget--) { s->failed_pc=0x0c099524u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c099526;
P_0c099526: /* original 2338, guest PC 0x0c099526 */
if(!s->budget--) { s->failed_pc=0x0c099526u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c099528;
P_0c099528: /* original 8906, guest PC 0x0c099528 */
if(!s->budget--) { s->failed_pc=0x0c099528u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099538; }
goto P_0c09952a;
P_0c09952a: /* original 4f26, guest PC 0x0c09952a */
if(!s->budget--) { s->failed_pc=0x0c09952au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09952c;
P_0c09952c: /* original a018, guest PC 0x0c09952c */
if(!s->budget--) { s->failed_pc=0x0c09952cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099560;
P_0c09952e: /* original 6ef6, guest PC 0x0c09952e */
if(!s->budget--) { s->failed_pc=0x0c09952eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099530;
P_0c099530: /* original d325, guest PC 0x0c099530 */
if(!s->budget--) { s->failed_pc=0x0c099530u; return 0; }
r[3]=read(ram,0x0c0995c8u,4);
goto P_0c099532;
P_0c099532: /* original 903b, guest PC 0x0c099532 */
if(!s->budget--) { s->failed_pc=0x0c099532u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0995acu,2);
goto P_0c099534;
P_0c099534: /* original 430b, guest PC 0x0c099534 */
if(!s->budget--) { s->failed_pc=0x0c099534u; return 0; }
target=r[3];
r[16]=code_base|0x0c099538u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099538u) { target=s->pc; goto dispatch; }
goto P_0c099538;
P_0c099536: /* original 04ee, guest PC 0x0c099536 */
if(!s->budget--) { s->failed_pc=0x0c099536u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c099538;
P_0c099538: /* original 4f26, guest PC 0x0c099538 */
if(!s->budget--) { s->failed_pc=0x0c099538u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09953a;
P_0c09953a: /* original d224, guest PC 0x0c09953a */
if(!s->budget--) { s->failed_pc=0x0c09953au; return 0; }
r[2]=read(ram,0x0c0995ccu,4);
goto P_0c09953c;
P_0c09953c: /* original 422b, guest PC 0x0c09953c */
if(!s->budget--) { s->failed_pc=0x0c09953cu; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c097ff4u: goto P_0c097ff4;
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
P_0c09953e: /* original 6ef6, guest PC 0x0c09953e */
if(!s->budget--) { s->failed_pc=0x0c09953eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099540;
P_0c099540: /* original 902f, guest PC 0x0c099540 */
if(!s->budget--) { s->failed_pc=0x0c099540u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0995a2u,2);
goto P_0c099542;
P_0c099542: /* original d41f, guest PC 0x0c099542 */
if(!s->budget--) { s->failed_pc=0x0c099542u; return 0; }
r[4]=read(ram,0x0c0995c0u,4);
goto P_0c099544;
P_0c099544: /* original 4f22, guest PC 0x0c099544 */
if(!s->budget--) { s->failed_pc=0x0c099544u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c099546;
P_0c099546: /* original 034c, guest PC 0x0c099546 */
if(!s->budget--) { s->failed_pc=0x0c099546u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c099548;
P_0c099548: /* original 2338, guest PC 0x0c099548 */
if(!s->budget--) { s->failed_pc=0x0c099548u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09954a;
P_0c09954a: /* original 8b02, guest PC 0x0c09954a */
if(!s->budget--) { s->failed_pc=0x0c09954au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099552; }
goto P_0c09954c;
P_0c09954c: /* original d21b, guest PC 0x0c09954c */
if(!s->budget--) { s->failed_pc=0x0c09954cu; return 0; }
r[2]=read(ram,0x0c0995bcu,4);
goto P_0c09954e;
P_0c09954e: /* original 420b, guest PC 0x0c09954e */
if(!s->budget--) { s->failed_pc=0x0c09954eu; return 0; }
target=r[2];
r[16]=code_base|0x0c099552u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099552u) { target=s->pc; goto dispatch; }
goto P_0c099552;
P_0c099550: /* original 0009, guest PC 0x0c099550 */
if(!s->budget--) { s->failed_pc=0x0c099550u; return 0; }
goto P_0c099552;
P_0c099552: /* original d219, guest PC 0x0c099552 */
if(!s->budget--) { s->failed_pc=0x0c099552u; return 0; }
r[2]=read(ram,0x0c0995b8u,4);
goto P_0c099554;
P_0c099554: /* original d317, guest PC 0x0c099554 */
if(!s->budget--) { s->failed_pc=0x0c099554u; return 0; }
r[3]=read(ram,0x0c0995b4u,4);
goto P_0c099556;
P_0c099556: /* original d516, guest PC 0x0c099556 */
if(!s->budget--) { s->failed_pc=0x0c099556u; return 0; }
r[5]=read(ram,0x0c0995b0u,4);
goto P_0c099558;
P_0c099558: /* original 420b, guest PC 0x0c099558 */
if(!s->budget--) { s->failed_pc=0x0c099558u; return 0; }
target=r[2];
r[16]=code_base|0x0c09955cu;
tmp=read(ram,r[3],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09955cu) { target=s->pc; goto dispatch; }
goto P_0c09955c;
P_0c09955a: /* original 6432, guest PC 0x0c09955a */
if(!s->budget--) { s->failed_pc=0x0c09955au; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c09955c;
P_0c09955c: /* original a000, guest PC 0x0c09955c */
if(!s->budget--) { s->failed_pc=0x0c09955cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c099560;
P_0c09955e: /* original 4f26, guest PC 0x0c09955e */
if(!s->budget--) { s->failed_pc=0x0c09955eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c099560;
P_0c099560: /* original 2fe6, guest PC 0x0c099560 */
if(!s->budget--) { s->failed_pc=0x0c099560u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099562;
P_0c099562: /* original e054, guest PC 0x0c099562 */
if(!s->budget--) { s->failed_pc=0x0c099562u; return 0; }
r[0]=0x00000054u;
goto P_0c099564;
P_0c099564: /* original 2fd6, guest PC 0x0c099564 */
if(!s->budget--) { s->failed_pc=0x0c099564u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099566;
P_0c099566: /* original 2fc6, guest PC 0x0c099566 */
if(!s->budget--) { s->failed_pc=0x0c099566u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099568;
P_0c099568: /* original 4f22, guest PC 0x0c099568 */
if(!s->budget--) { s->failed_pc=0x0c099568u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09956a;
P_0c09956a: /* original d319, guest PC 0x0c09956a */
if(!s->budget--) { s->failed_pc=0x0c09956au; return 0; }
r[3]=read(ram,0x0c0995d0u,4);
goto P_0c09956c;
P_0c09956c: /* original dd14, guest PC 0x0c09956c */
if(!s->budget--) { s->failed_pc=0x0c09956cu; return 0; }
r[13]=read(ram,0x0c0995c0u,4);
goto P_0c09956e;
P_0c09956e: /* original 7fe8, guest PC 0x0c09956e */
if(!s->budget--) { s->failed_pc=0x0c09956eu; return 0; }
r[15]+=0xffffffe8u;
goto P_0c099570;
P_0c099570: /* original 1f32, guest PC 0x0c099570 */
if(!s->budget--) { s->failed_pc=0x0c099570u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c099572;
P_0c099572: /* original d319, guest PC 0x0c099572 */
if(!s->budget--) { s->failed_pc=0x0c099572u; return 0; }
r[3]=read(ram,0x0c0995d8u,4);
goto P_0c099574;
P_0c099574: /* original dc17, guest PC 0x0c099574 */
if(!s->budget--) { s->failed_pc=0x0c099574u; return 0; }
r[12]=read(ram,0x0c0995d4u,4);
goto P_0c099576;
P_0c099576: /* original 430b, guest PC 0x0c099576 */
if(!s->budget--) { s->failed_pc=0x0c099576u; return 0; }
target=r[3];
r[16]=code_base|0x0c09957au;
r[4]=read(ram,r[12]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09957au) { target=s->pc; goto dispatch; }
goto P_0c09957a;
P_0c099578: /* original 04ce, guest PC 0x0c099578 */
if(!s->budget--) { s->failed_pc=0x0c099578u; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c09957a;
P_0c09957a: /* original 55c4, guest PC 0x0c09957a */
if(!s->budget--) { s->failed_pc=0x0c09957au; return 0; }
r[5]=read(ram,r[12]+16,4);
goto P_0c09957c;
P_0c09957c: /* original e401, guest PC 0x0c09957c */
if(!s->budget--) { s->failed_pc=0x0c09957cu; return 0; }
r[4]=0x00000001u;
goto P_0c09957e;
P_0c09957e: /* original 6252, guest PC 0x0c09957e */
if(!s->budget--) { s->failed_pc=0x0c09957eu; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c099580;
P_0c099580: /* original 224b, guest PC 0x0c099580 */
if(!s->budget--) { s->failed_pc=0x0c099580u; return 0; }
r[2]|=r[4];
goto P_0c099582;
P_0c099582: /* original 2522, guest PC 0x0c099582 */
if(!s->budget--) { s->failed_pc=0x0c099582u; return 0; }
write(ram,r[5],r[2],4);
goto P_0c099584;
P_0c099584: /* original 55c5, guest PC 0x0c099584 */
if(!s->budget--) { s->failed_pc=0x0c099584u; return 0; }
r[5]=read(ram,r[12]+20,4);
goto P_0c099586;
P_0c099586: /* original 6352, guest PC 0x0c099586 */
if(!s->budget--) { s->failed_pc=0x0c099586u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c099588;
P_0c099588: /* original 234b, guest PC 0x0c099588 */
if(!s->budget--) { s->failed_pc=0x0c099588u; return 0; }
r[3]|=r[4];
goto P_0c09958a;
P_0c09958a: /* original 2532, guest PC 0x0c09958a */
if(!s->budget--) { s->failed_pc=0x0c09958au; return 0; }
write(ram,r[5],r[3],4);
goto P_0c09958c;
P_0c09958c: /* original 900e, guest PC 0x0c09958c */
if(!s->budget--) { s->failed_pc=0x0c09958cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0995acu,2);
goto P_0c09958e;
P_0c09958e: /* original 53c4, guest PC 0x0c09958e */
if(!s->budget--) { s->failed_pc=0x0c09958eu; return 0; }
r[3]=read(ram,r[12]+16,4);
goto P_0c099590;
P_0c099590: /* original 0ede, guest PC 0x0c099590 */
if(!s->budget--) { s->failed_pc=0x0c099590u; return 0; }
r[14]=read(ram,r[13]+r[0],4);
goto P_0c099592;
P_0c099592: /* original 33e0, guest PC 0x0c099592 */
if(!s->budget--) { s->failed_pc=0x0c099592u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[14])!=0);
goto P_0c099594;
P_0c099594: /* original 8b22, guest PC 0x0c099594 */
if(!s->budget--) { s->failed_pc=0x0c099594u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0995dc; }
goto P_0c099596;
P_0c099596: /* original 900a, guest PC 0x0c099596 */
if(!s->budget--) { s->failed_pc=0x0c099596u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0995aeu,2);
goto P_0c099598;
P_0c099598: /* original 02dc, guest PC 0x0c099598 */
if(!s->budget--) { s->failed_pc=0x0c099598u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c09959a;
P_0c09959a: /* original 2248, guest PC 0x0c09959a */
if(!s->budget--) { s->failed_pc=0x0c09959au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c09959c;
P_0c09959c: /* original 8b31, guest PC 0x0c09959c */
if(!s->budget--) { s->failed_pc=0x0c09959cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099602; }
goto P_0c09959e;
P_0c09959e: /* original a021, guest PC 0x0c09959e */
if(!s->budget--) { s->failed_pc=0x0c09959eu; return 0; }
goto P_0c0995e4;
P_0c0995a0: /* original 0009, guest PC 0x0c0995a0 */
if(!s->budget--) { s->failed_pc=0x0c0995a0u; return 0; }
if(!vf3_matrix_family(0x0c0995a2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0995a2u; return 0; } return 1;
P_0c0995dc: /* original 9072, guest PC 0x0c0995dc */
if(!s->budget--) { s->failed_pc=0x0c0995dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996c4u,2);
goto P_0c0995de;
P_0c0995de: /* original 00dc, guest PC 0x0c0995de */
if(!s->budget--) { s->failed_pc=0x0c0995deu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0995e0;
P_0c0995e0: /* original c802, guest PC 0x0c0995e0 */
if(!s->budget--) { s->failed_pc=0x0c0995e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0995e2;
P_0c0995e2: /* original 8b0e, guest PC 0x0c0995e2 */
if(!s->budget--) { s->failed_pc=0x0c0995e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099602; }
goto P_0c0995e4;
P_0c0995e4: /* original 906f, guest PC 0x0c0995e4 */
if(!s->budget--) { s->failed_pc=0x0c0995e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996c6u,2);
goto P_0c0995e6;
P_0c0995e6: /* original 00ec, guest PC 0x0c0995e6 */
if(!s->budget--) { s->failed_pc=0x0c0995e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0995e8;
P_0c0995e8: /* original 600c, guest PC 0x0c0995e8 */
if(!s->budget--) { s->failed_pc=0x0c0995e8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0995ea;
P_0c0995ea: /* original c840, guest PC 0x0c0995ea */
if(!s->budget--) { s->failed_pc=0x0c0995eau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0995ec;
P_0c0995ec: /* original 8b09, guest PC 0x0c0995ec */
if(!s->budget--) { s->failed_pc=0x0c0995ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099602; }
goto P_0c0995ee;
P_0c0995ee: /* original e018, guest PC 0x0c0995ee */
if(!s->budget--) { s->failed_pc=0x0c0995eeu; return 0; }
r[0]=0x00000018u;
goto P_0c0995f0;
P_0c0995f0: /* original d338, guest PC 0x0c0995f0 */
if(!s->budget--) { s->failed_pc=0x0c0995f0u; return 0; }
r[3]=read(ram,0x0c0996d4u,4);
goto P_0c0995f2;
P_0c0995f2: /* original f5e6, guest PC 0x0c0995f2 */
if(!s->budget--) { s->failed_pc=0x0c0995f2u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0995f4;
P_0c0995f4: /* original 64f3, guest PC 0x0c0995f4 */
if(!s->budget--) { s->failed_pc=0x0c0995f4u; return 0; }
r[4]=r[15];
goto P_0c0995f6;
P_0c0995f6: /* original 740c, guest PC 0x0c0995f6 */
if(!s->budget--) { s->failed_pc=0x0c0995f6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0995f8;
P_0c0995f8: /* original e010, guest PC 0x0c0995f8 */
if(!s->budget--) { s->failed_pc=0x0c0995f8u; return 0; }
r[0]=0x00000010u;
goto P_0c0995fa;
P_0c0995fa: /* original 430b, guest PC 0x0c0995fa */
if(!s->budget--) { s->failed_pc=0x0c0995fau; return 0; }
target=r[3];
r[16]=code_base|0x0c0995feu;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0995feu) { target=s->pc; goto dispatch; }
goto P_0c0995fe;
P_0c0995fc: /* original f4e6, guest PC 0x0c0995fc */
if(!s->budget--) { s->failed_pc=0x0c0995fcu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0995fe;
P_0c0995fe: /* original c804, guest PC 0x0c0995fe */
if(!s->budget--) { s->failed_pc=0x0c0995feu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c099600;
P_0c099600: /* original 8b2c, guest PC 0x0c099600 */
if(!s->budget--) { s->failed_pc=0x0c099600u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09965c; }
goto P_0c099602;
P_0c099602: /* original e048, guest PC 0x0c099602 */
if(!s->budget--) { s->failed_pc=0x0c099602u; return 0; }
r[0]=0x00000048u;
goto P_0c099604;
P_0c099604: /* original 62e2, guest PC 0x0c099604 */
if(!s->budget--) { s->failed_pc=0x0c099604u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c099606;
P_0c099606: /* original 66f3, guest PC 0x0c099606 */
if(!s->budget--) { s->failed_pc=0x0c099606u; return 0; }
r[6]=r[15];
goto P_0c099608;
P_0c099608: /* original 65f3, guest PC 0x0c099608 */
if(!s->budget--) { s->failed_pc=0x0c099608u; return 0; }
r[5]=r[15];
goto P_0c09960a;
P_0c09960a: /* original 2f22, guest PC 0x0c09960a */
if(!s->budget--) { s->failed_pc=0x0c09960au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c09960c;
P_0c09960c: /* original 7604, guest PC 0x0c09960c */
if(!s->budget--) { s->failed_pc=0x0c09960cu; return 0; }
r[6]+=0x00000004u;
goto P_0c09960e;
P_0c09960e: /* original 03ee, guest PC 0x0c09960e */
if(!s->budget--) { s->failed_pc=0x0c09960eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c099610;
P_0c099610: /* original 1f31, guest PC 0x0c099610 */
if(!s->budget--) { s->failed_pc=0x0c099610u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c099612;
P_0c099612: /* original d331, guest PC 0x0c099612 */
if(!s->budget--) { s->failed_pc=0x0c099612u; return 0; }
r[3]=read(ram,0x0c0996d8u,4);
goto P_0c099614;
P_0c099614: /* original 430b, guest PC 0x0c099614 */
if(!s->budget--) { s->failed_pc=0x0c099614u; return 0; }
target=r[3];
r[16]=code_base|0x0c099618u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099618u) { target=s->pc; goto dispatch; }
goto P_0c099618;
P_0c099616: /* original 64e3, guest PC 0x0c099616 */
if(!s->budget--) { s->failed_pc=0x0c099616u; return 0; }
r[4]=r[14];
goto P_0c099618;
P_0c099618: /* original 62f2, guest PC 0x0c099618 */
if(!s->budget--) { s->failed_pc=0x0c099618u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09961a;
P_0c09961a: /* original e048, guest PC 0x0c09961a */
if(!s->budget--) { s->failed_pc=0x0c09961au; return 0; }
r[0]=0x00000048u;
goto P_0c09961c;
P_0c09961c: /* original d32f, guest PC 0x0c09961c */
if(!s->budget--) { s->failed_pc=0x0c09961cu; return 0; }
r[3]=read(ram,0x0c0996dcu,4);
goto P_0c09961e;
P_0c09961e: /* original 223b, guest PC 0x0c09961e */
if(!s->budget--) { s->failed_pc=0x0c09961eu; return 0; }
r[2]|=r[3];
goto P_0c099620;
P_0c099620: /* original 6123, guest PC 0x0c099620 */
if(!s->budget--) { s->failed_pc=0x0c099620u; return 0; }
r[1]=r[2];
goto P_0c099622;
P_0c099622: /* original 2f22, guest PC 0x0c099622 */
if(!s->budget--) { s->failed_pc=0x0c099622u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c099624;
P_0c099624: /* original 2e22, guest PC 0x0c099624 */
if(!s->budget--) { s->failed_pc=0x0c099624u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c099626;
P_0c099626: /* original 52f1, guest PC 0x0c099626 */
if(!s->budget--) { s->failed_pc=0x0c099626u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c099628;
P_0c099628: /* original 0e26, guest PC 0x0c099628 */
if(!s->budget--) { s->failed_pc=0x0c099628u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09962a;
P_0c09962a: /* original e010, guest PC 0x0c09962a */
if(!s->budget--) { s->failed_pc=0x0c09962au; return 0; }
r[0]=0x00000010u;
goto P_0c09962c;
P_0c09962c: /* original 61e2, guest PC 0x0c09962c */
if(!s->budget--) { s->failed_pc=0x0c09962cu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c09962e;
P_0c09962e: /* original 924b, guest PC 0x0c09962e */
if(!s->budget--) { s->failed_pc=0x0c09962eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996c8u,2);
goto P_0c099630;
P_0c099630: /* original 2129, guest PC 0x0c099630 */
if(!s->budget--) { s->failed_pc=0x0c099630u; return 0; }
r[1]&=r[2];
goto P_0c099632;
P_0c099632: /* original 2e12, guest PC 0x0c099632 */
if(!s->budget--) { s->failed_pc=0x0c099632u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c099634;
P_0c099634: /* original f48d, guest PC 0x0c099634 */
if(!s->budget--) { s->failed_pc=0x0c099634u; return 0; }
fr[4]=0;
goto P_0c099636;
P_0c099636: /* original fe47, guest PC 0x0c099636 */
if(!s->budget--) { s->failed_pc=0x0c099636u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c099638;
P_0c099638: /* original e018, guest PC 0x0c099638 */
if(!s->budget--) { s->failed_pc=0x0c099638u; return 0; }
r[0]=0x00000018u;
goto P_0c09963a;
P_0c09963a: /* original fe47, guest PC 0x0c09963a */
if(!s->budget--) { s->failed_pc=0x0c09963au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c09963c;
P_0c09963c: /* original e024, guest PC 0x0c09963c */
if(!s->budget--) { s->failed_pc=0x0c09963cu; return 0; }
r[0]=0x00000024u;
goto P_0c09963e;
P_0c09963e: /* original fe47, guest PC 0x0c09963e */
if(!s->budget--) { s->failed_pc=0x0c09963eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c099640;
P_0c099640: /* original e02c, guest PC 0x0c099640 */
if(!s->budget--) { s->failed_pc=0x0c099640u; return 0; }
r[0]=0x0000002cu;
goto P_0c099642;
P_0c099642: /* original fe47, guest PC 0x0c099642 */
if(!s->budget--) { s->failed_pc=0x0c099642u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c099644;
P_0c099644: /* original 9041, guest PC 0x0c099644 */
if(!s->budget--) { s->failed_pc=0x0c099644u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996cau,2);
goto P_0c099646;
P_0c099646: /* original fe47, guest PC 0x0c099646 */
if(!s->budget--) { s->failed_pc=0x0c099646u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c099648;
P_0c099648: /* original 7008, guest PC 0x0c099648 */
if(!s->budget--) { s->failed_pc=0x0c099648u; return 0; }
r[0]+=0x00000008u;
goto P_0c09964a;
P_0c09964a: /* original fe47, guest PC 0x0c09964a */
if(!s->budget--) { s->failed_pc=0x0c09964au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c09964c;
P_0c09964c: /* original 903e, guest PC 0x0c09964c */
if(!s->budget--) { s->failed_pc=0x0c09964cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996ccu,2);
goto P_0c09964e;
P_0c09964e: /* original fe47, guest PC 0x0c09964e */
if(!s->budget--) { s->failed_pc=0x0c09964eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c099650;
P_0c099650: /* original 7008, guest PC 0x0c099650 */
if(!s->budget--) { s->failed_pc=0x0c099650u; return 0; }
r[0]+=0x00000008u;
goto P_0c099652;
P_0c099652: /* original fe47, guest PC 0x0c099652 */
if(!s->budget--) { s->failed_pc=0x0c099652u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c099654;
P_0c099654: /* original 9039, guest PC 0x0c099654 */
if(!s->budget--) { s->failed_pc=0x0c099654u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996cau,2);
goto P_0c099656;
P_0c099656: /* original fe47, guest PC 0x0c099656 */
if(!s->budget--) { s->failed_pc=0x0c099656u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c099658;
P_0c099658: /* original 7008, guest PC 0x0c099658 */
if(!s->budget--) { s->failed_pc=0x0c099658u; return 0; }
r[0]+=0x00000008u;
goto P_0c09965a;
P_0c09965a: /* original fe47, guest PC 0x0c09965a */
if(!s->budget--) { s->failed_pc=0x0c09965au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c09965c;
P_0c09965c: /* original 9037, guest PC 0x0c09965c */
if(!s->budget--) { s->failed_pc=0x0c09965cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996ceu,2);
goto P_0c09965e;
P_0c09965e: /* original e500, guest PC 0x0c09965e */
if(!s->budget--) { s->failed_pc=0x0c09965eu; return 0; }
r[5]=0x00000000u;
goto P_0c099660;
P_0c099660: /* original 0e56, guest PC 0x0c099660 */
if(!s->budget--) { s->failed_pc=0x0c099660u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c099662;
P_0c099662: /* original 700c, guest PC 0x0c099662 */
if(!s->budget--) { s->failed_pc=0x0c099662u; return 0; }
r[0]+=0x0000000cu;
goto P_0c099664;
P_0c099664: /* original 0e56, guest PC 0x0c099664 */
if(!s->budget--) { s->failed_pc=0x0c099664u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c099666;
P_0c099666: /* original 9033, guest PC 0x0c099666 */
if(!s->budget--) { s->failed_pc=0x0c099666u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996d0u,2);
goto P_0c099668;
P_0c099668: /* original 04de, guest PC 0x0c099668 */
if(!s->budget--) { s->failed_pc=0x0c099668u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c09966a;
P_0c09966a: /* original e018, guest PC 0x0c09966a */
if(!s->budget--) { s->failed_pc=0x0c09966au; return 0; }
r[0]=0x00000018u;
goto P_0c09966c;
P_0c09966c: /* original 00dc, guest PC 0x0c09966c */
if(!s->budget--) { s->failed_pc=0x0c09966cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c09966e;
P_0c09966e: /* original 600c, guest PC 0x0c09966e */
if(!s->budget--) { s->failed_pc=0x0c09966eu; return 0; }
r[0]=r[0]&255u;
goto P_0c099670;
P_0c099670: /* original 8802, guest PC 0x0c099670 */
if(!s->budget--) { s->failed_pc=0x0c099670u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c099672;
P_0c099672: /* original 8906, guest PC 0x0c099672 */
if(!s->budget--) { s->failed_pc=0x0c099672u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099682; }
goto P_0c099674;
P_0c099674: /* original e046, guest PC 0x0c099674 */
if(!s->budget--) { s->failed_pc=0x0c099674u; return 0; }
r[0]=0x00000046u;
goto P_0c099676;
P_0c099676: /* original 0455, guest PC 0x0c099676 */
if(!s->budget--) { s->failed_pc=0x0c099676u; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c099678;
P_0c099678: /* original 9025, guest PC 0x0c099678 */
if(!s->budget--) { s->failed_pc=0x0c099678u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996c6u,2);
goto P_0c09967a;
P_0c09967a: /* original 004c, guest PC 0x0c09967a */
if(!s->budget--) { s->failed_pc=0x0c09967au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09967c;
P_0c09967c: /* original 600c, guest PC 0x0c09967c */
if(!s->budget--) { s->failed_pc=0x0c09967cu; return 0; }
r[0]=r[0]&255u;
goto P_0c09967e;
P_0c09967e: /* original c840, guest PC 0x0c09967e */
if(!s->budget--) { s->failed_pc=0x0c09967eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c099680;
P_0c099680: /* original 8b07, guest PC 0x0c099680 */
if(!s->budget--) { s->failed_pc=0x0c099680u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099692; }
goto P_0c099682;
P_0c099682: /* original 6242, guest PC 0x0c099682 */
if(!s->budget--) { s->failed_pc=0x0c099682u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c099684;
P_0c099684: /* original d316, guest PC 0x0c099684 */
if(!s->budget--) { s->failed_pc=0x0c099684u; return 0; }
r[3]=read(ram,0x0c0996e0u,4);
goto P_0c099686;
P_0c099686: /* original 2238, guest PC 0x0c099686 */
if(!s->budget--) { s->failed_pc=0x0c099686u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c099688;
P_0c099688: /* original 8b03, guest PC 0x0c099688 */
if(!s->budget--) { s->failed_pc=0x0c099688u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099692; }
goto P_0c09968a;
P_0c09968a: /* original d316, guest PC 0x0c09968a */
if(!s->budget--) { s->failed_pc=0x0c09968au; return 0; }
r[3]=read(ram,0x0c0996e4u,4);
goto P_0c09968c;
P_0c09968c: /* original 9020, guest PC 0x0c09968c */
if(!s->budget--) { s->failed_pc=0x0c09968cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996d0u,2);
goto P_0c09968e;
P_0c09968e: /* original 430b, guest PC 0x0c09968e */
if(!s->budget--) { s->failed_pc=0x0c09968eu; return 0; }
target=r[3];
r[16]=code_base|0x0c099692u;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099692u) { target=s->pc; goto dispatch; }
goto P_0c099692;
P_0c099690: /* original 04de, guest PC 0x0c099690 */
if(!s->budget--) { s->failed_pc=0x0c099690u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c099692;
P_0c099692: /* original 901d, guest PC 0x0c099692 */
if(!s->budget--) { s->failed_pc=0x0c099692u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996d0u,2);
goto P_0c099694;
P_0c099694: /* original d314, guest PC 0x0c099694 */
if(!s->budget--) { s->failed_pc=0x0c099694u; return 0; }
r[3]=read(ram,0x0c0996e8u,4);
goto P_0c099696;
P_0c099696: /* original 05de, guest PC 0x0c099696 */
if(!s->budget--) { s->failed_pc=0x0c099696u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c099698;
P_0c099698: /* original 70fc, guest PC 0x0c099698 */
if(!s->budget--) { s->failed_pc=0x0c099698u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09969a;
P_0c09969a: /* original 430b, guest PC 0x0c09969a */
if(!s->budget--) { s->failed_pc=0x0c09969au; return 0; }
target=r[3];
r[16]=code_base|0x0c09969eu;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09969eu) { target=s->pc; goto dispatch; }
goto P_0c09969e;
P_0c09969c: /* original 04de, guest PC 0x0c09969c */
if(!s->budget--) { s->failed_pc=0x0c09969cu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c09969e;
P_0c09969e: /* original c713, guest PC 0x0c09969e */
if(!s->budget--) { s->failed_pc=0x0c09969eu; return 0; }
r[0]=code_base|0x000996ecu;
goto P_0c0996a0;
P_0c0996a0: /* original f308, guest PC 0x0c0996a0 */
if(!s->budget--) { s->failed_pc=0x0c0996a0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0996a2;
P_0c0996a2: /* original fd3a, guest PC 0x0c0996a2 */
if(!s->budget--) { s->failed_pc=0x0c0996a2u; return 0; }
vf3_matrix_store(s,ram,3,r[13]);
goto P_0c0996a4;
P_0c0996a4: /* original 52d2, guest PC 0x0c0996a4 */
if(!s->budget--) { s->failed_pc=0x0c0996a4u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0996a6;
P_0c0996a6: /* original 930f, guest PC 0x0c0996a6 */
if(!s->budget--) { s->failed_pc=0x0c0996a6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0996c8u,2);
goto P_0c0996a8;
P_0c0996a8: /* original 2239, guest PC 0x0c0996a8 */
if(!s->budget--) { s->failed_pc=0x0c0996a8u; return 0; }
r[2]&=r[3];
goto P_0c0996aa;
P_0c0996aa: /* original 1d22, guest PC 0x0c0996aa */
if(!s->budget--) { s->failed_pc=0x0c0996aau; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c0996ac;
P_0c0996ac: /* original 51f2, guest PC 0x0c0996ac */
if(!s->budget--) { s->failed_pc=0x0c0996acu; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c0996ae;
P_0c0996ae: /* original d210, guest PC 0x0c0996ae */
if(!s->budget--) { s->failed_pc=0x0c0996aeu; return 0; }
r[2]=read(ram,0x0c0996f0u,4);
goto P_0c0996b0;
P_0c0996b0: /* original 841b, guest PC 0x0c0996b0 */
if(!s->budget--) { s->failed_pc=0x0c0996b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+11,1);
goto P_0c0996b2;
P_0c0996b2: /* original 7001, guest PC 0x0c0996b2 */
if(!s->budget--) { s->failed_pc=0x0c0996b2u; return 0; }
r[0]+=0x00000001u;
goto P_0c0996b4;
P_0c0996b4: /* original 420b, guest PC 0x0c0996b4 */
if(!s->budget--) { s->failed_pc=0x0c0996b4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0996b8u;
write(ram,r[1]+11,r[0],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0996b8u) { target=s->pc; goto dispatch; }
goto P_0c0996b8;
P_0c0996b6: /* original 801b, guest PC 0x0c0996b6 */
if(!s->budget--) { s->failed_pc=0x0c0996b6u; return 0; }
write(ram,r[1]+11,r[0],1);
goto P_0c0996b8;
P_0c0996b8: /* original 7f18, guest PC 0x0c0996b8 */
if(!s->budget--) { s->failed_pc=0x0c0996b8u; return 0; }
r[15]+=0x00000018u;
goto P_0c0996ba;
P_0c0996ba: /* original 4f26, guest PC 0x0c0996ba */
if(!s->budget--) { s->failed_pc=0x0c0996bau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0996bc;
P_0c0996bc: /* original 6cf6, guest PC 0x0c0996bc */
if(!s->budget--) { s->failed_pc=0x0c0996bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0996be;
P_0c0996be: /* original 6df6, guest PC 0x0c0996be */
if(!s->budget--) { s->failed_pc=0x0c0996beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0996c0;
P_0c0996c0: /* original 000b, guest PC 0x0c0996c0 */
if(!s->budget--) { s->failed_pc=0x0c0996c0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0996c2: /* original 6ef6, guest PC 0x0c0996c2 */
if(!s->budget--) { s->failed_pc=0x0c0996c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0996c4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0996c4u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
