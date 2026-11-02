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
int vf3_away_batch80_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c068f92u: goto P_0c068f92;
case 0x0c068f94u: goto P_0c068f94;
case 0x0c068f96u: goto P_0c068f96;
case 0x0c068f98u: goto P_0c068f98;
case 0x0c068f9au: goto P_0c068f9a;
case 0x0c068f9cu: goto P_0c068f9c;
case 0x0c068f9eu: goto P_0c068f9e;
case 0x0c068fa0u: goto P_0c068fa0;
case 0x0c068fa2u: goto P_0c068fa2;
case 0x0c068fa4u: goto P_0c068fa4;
case 0x0c068fa6u: goto P_0c068fa6;
case 0x0c068fa8u: goto P_0c068fa8;
case 0x0c068faau: goto P_0c068faa;
case 0x0c068facu: goto P_0c068fac;
case 0x0c068faeu: goto P_0c068fae;
case 0x0c068fb0u: goto P_0c068fb0;
case 0x0c068fb2u: goto P_0c068fb2;
case 0x0c068fb4u: goto P_0c068fb4;
case 0x0c068fb6u: goto P_0c068fb6;
case 0x0c068fb8u: goto P_0c068fb8;
case 0x0c068fbau: goto P_0c068fba;
case 0x0c068fbcu: goto P_0c068fbc;
case 0x0c068fbeu: goto P_0c068fbe;
case 0x0c068fc0u: goto P_0c068fc0;
case 0x0c068fc2u: goto P_0c068fc2;
case 0x0c068fc4u: goto P_0c068fc4;
case 0x0c068fc6u: goto P_0c068fc6;
case 0x0c068fe4u: goto P_0c068fe4;
case 0x0c068fe6u: goto P_0c068fe6;
case 0x0c068fe8u: goto P_0c068fe8;
case 0x0c068feau: goto P_0c068fea;
case 0x0c068fecu: goto P_0c068fec;
case 0x0c068feeu: goto P_0c068fee;
case 0x0c068ff0u: goto P_0c068ff0;
case 0x0c068ff2u: goto P_0c068ff2;
case 0x0c068ff4u: goto P_0c068ff4;
case 0x0c068ff6u: goto P_0c068ff6;
case 0x0c068ff8u: goto P_0c068ff8;
case 0x0c068ffau: goto P_0c068ffa;
case 0x0c068ffcu: goto P_0c068ffc;
case 0x0c068ffeu: goto P_0c068ffe;
case 0x0c069000u: goto P_0c069000;
case 0x0c069002u: goto P_0c069002;
case 0x0c069004u: goto P_0c069004;
case 0x0c069006u: goto P_0c069006;
case 0x0c069008u: goto P_0c069008;
case 0x0c06900au: goto P_0c06900a;
case 0x0c06900cu: goto P_0c06900c;
case 0x0c06900eu: goto P_0c06900e;
case 0x0c069010u: goto P_0c069010;
case 0x0c069012u: goto P_0c069012;
case 0x0c069014u: goto P_0c069014;
case 0x0c069016u: goto P_0c069016;
case 0x0c069018u: goto P_0c069018;
case 0x0c06901au: goto P_0c06901a;
case 0x0c06901cu: goto P_0c06901c;
case 0x0c06901eu: goto P_0c06901e;
case 0x0c069020u: goto P_0c069020;
case 0x0c069022u: goto P_0c069022;
case 0x0c069024u: goto P_0c069024;
case 0x0c069026u: goto P_0c069026;
case 0x0c069028u: goto P_0c069028;
case 0x0c06902au: goto P_0c06902a;
case 0x0c06902cu: goto P_0c06902c;
case 0x0c06902eu: goto P_0c06902e;
case 0x0c069030u: goto P_0c069030;
case 0x0c069032u: goto P_0c069032;
case 0x0c069034u: goto P_0c069034;
case 0x0c069036u: goto P_0c069036;
case 0x0c069038u: goto P_0c069038;
case 0x0c06903au: goto P_0c06903a;
case 0x0c06903cu: goto P_0c06903c;
case 0x0c06903eu: goto P_0c06903e;
case 0x0c069040u: goto P_0c069040;
case 0x0c069042u: goto P_0c069042;
case 0x0c069044u: goto P_0c069044;
case 0x0c069046u: goto P_0c069046;
case 0x0c069048u: goto P_0c069048;
case 0x0c06904au: goto P_0c06904a;
case 0x0c06904cu: goto P_0c06904c;
case 0x0c06904eu: goto P_0c06904e;
case 0x0c069050u: goto P_0c069050;
case 0x0c069052u: goto P_0c069052;
case 0x0c069054u: goto P_0c069054;
case 0x0c069056u: goto P_0c069056;
case 0x0c069058u: goto P_0c069058;
case 0x0c06905au: goto P_0c06905a;
case 0x0c06905cu: goto P_0c06905c;
case 0x0c06905eu: goto P_0c06905e;
case 0x0c069060u: goto P_0c069060;
case 0x0c069062u: goto P_0c069062;
case 0x0c069064u: goto P_0c069064;
case 0x0c069066u: goto P_0c069066;
case 0x0c069068u: goto P_0c069068;
case 0x0c06906au: goto P_0c06906a;
case 0x0c06906cu: goto P_0c06906c;
case 0x0c06906eu: goto P_0c06906e;
case 0x0c069070u: goto P_0c069070;
case 0x0c069072u: goto P_0c069072;
case 0x0c069074u: goto P_0c069074;
case 0x0c069076u: goto P_0c069076;
case 0x0c069078u: goto P_0c069078;
case 0x0c06907au: goto P_0c06907a;
case 0x0c06907cu: goto P_0c06907c;
case 0x0c06907eu: goto P_0c06907e;
case 0x0c069080u: goto P_0c069080;
case 0x0c069082u: goto P_0c069082;
case 0x0c069084u: goto P_0c069084;
case 0x0c069086u: goto P_0c069086;
case 0x0c069088u: goto P_0c069088;
case 0x0c06908au: goto P_0c06908a;
case 0x0c06908cu: goto P_0c06908c;
case 0x0c06908eu: goto P_0c06908e;
case 0x0c069090u: goto P_0c069090;
case 0x0c069092u: goto P_0c069092;
case 0x0c069094u: goto P_0c069094;
case 0x0c069096u: goto P_0c069096;
case 0x0c069098u: goto P_0c069098;
case 0x0c06909au: goto P_0c06909a;
case 0x0c06909cu: goto P_0c06909c;
case 0x0c06909eu: goto P_0c06909e;
case 0x0c0690a0u: goto P_0c0690a0;
case 0x0c0690a2u: goto P_0c0690a2;
case 0x0c0690a4u: goto P_0c0690a4;
case 0x0c0690a6u: goto P_0c0690a6;
case 0x0c0690a8u: goto P_0c0690a8;
case 0x0c0690aau: goto P_0c0690aa;
case 0x0c0690acu: goto P_0c0690ac;
case 0x0c0690aeu: goto P_0c0690ae;
case 0x0c0690b0u: goto P_0c0690b0;
case 0x0c0690b2u: goto P_0c0690b2;
case 0x0c0690b4u: goto P_0c0690b4;
case 0x0c0690b6u: goto P_0c0690b6;
case 0x0c0690b8u: goto P_0c0690b8;
case 0x0c0690bau: goto P_0c0690ba;
case 0x0c0690bcu: goto P_0c0690bc;
case 0x0c0690beu: goto P_0c0690be;
case 0x0c0690c0u: goto P_0c0690c0;
case 0x0c0690c2u: goto P_0c0690c2;
case 0x0c0690c4u: goto P_0c0690c4;
case 0x0c0690c6u: goto P_0c0690c6;
case 0x0c0690c8u: goto P_0c0690c8;
case 0x0c0690cau: goto P_0c0690ca;
case 0x0c0690ccu: goto P_0c0690cc;
case 0x0c0690ceu: goto P_0c0690ce;
case 0x0c0690d0u: goto P_0c0690d0;
case 0x0c0690d2u: goto P_0c0690d2;
case 0x0c0690d4u: goto P_0c0690d4;
case 0x0c0690d6u: goto P_0c0690d6;
case 0x0c0690d8u: goto P_0c0690d8;
case 0x0c0690dau: goto P_0c0690da;
case 0x0c0690dcu: goto P_0c0690dc;
case 0x0c0690deu: goto P_0c0690de;
case 0x0c0690e0u: goto P_0c0690e0;
case 0x0c0690e2u: goto P_0c0690e2;
case 0x0c0690e4u: goto P_0c0690e4;
case 0x0c0690e6u: goto P_0c0690e6;
case 0x0c0690e8u: goto P_0c0690e8;
case 0x0c0690eau: goto P_0c0690ea;
case 0x0c0690ecu: goto P_0c0690ec;
case 0x0c0690eeu: goto P_0c0690ee;
case 0x0c0690f0u: goto P_0c0690f0;
case 0x0c0690f2u: goto P_0c0690f2;
case 0x0c0690f4u: goto P_0c0690f4;
case 0x0c0690f6u: goto P_0c0690f6;
case 0x0c0690f8u: goto P_0c0690f8;
case 0x0c0690fau: goto P_0c0690fa;
case 0x0c0690fcu: goto P_0c0690fc;
case 0x0c0690feu: goto P_0c0690fe;
case 0x0c069100u: goto P_0c069100;
case 0x0c069102u: goto P_0c069102;
case 0x0c069104u: goto P_0c069104;
case 0x0c069106u: goto P_0c069106;
case 0x0c069108u: goto P_0c069108;
case 0x0c06910au: goto P_0c06910a;
case 0x0c06910cu: goto P_0c06910c;
case 0x0c06910eu: goto P_0c06910e;
case 0x0c069110u: goto P_0c069110;
case 0x0c069112u: goto P_0c069112;
case 0x0c069114u: goto P_0c069114;
case 0x0c06911cu: goto P_0c06911c;
case 0x0c06911eu: goto P_0c06911e;
case 0x0c069120u: goto P_0c069120;
case 0x0c069122u: goto P_0c069122;
case 0x0c069124u: goto P_0c069124;
case 0x0c069126u: goto P_0c069126;
case 0x0c069128u: goto P_0c069128;
case 0x0c06912au: goto P_0c06912a;
case 0x0c06912cu: goto P_0c06912c;
case 0x0c06912eu: goto P_0c06912e;
case 0x0c069130u: goto P_0c069130;
case 0x0c069132u: goto P_0c069132;
case 0x0c069134u: goto P_0c069134;
case 0x0c069136u: goto P_0c069136;
case 0x0c069138u: goto P_0c069138;
case 0x0c06913au: goto P_0c06913a;
case 0x0c06913cu: goto P_0c06913c;
case 0x0c06913eu: goto P_0c06913e;
case 0x0c069140u: goto P_0c069140;
case 0x0c069142u: goto P_0c069142;
case 0x0c069144u: goto P_0c069144;
case 0x0c069146u: goto P_0c069146;
case 0x0c069148u: goto P_0c069148;
case 0x0c06914au: goto P_0c06914a;
case 0x0c06914cu: goto P_0c06914c;
case 0x0c06914eu: goto P_0c06914e;
case 0x0c069150u: goto P_0c069150;
case 0x0c069152u: goto P_0c069152;
case 0x0c069154u: goto P_0c069154;
case 0x0c069156u: goto P_0c069156;
case 0x0c069158u: goto P_0c069158;
case 0x0c06915au: goto P_0c06915a;
case 0x0c06915cu: goto P_0c06915c;
case 0x0c06915eu: goto P_0c06915e;
case 0x0c069160u: goto P_0c069160;
case 0x0c069162u: goto P_0c069162;
case 0x0c069164u: goto P_0c069164;
case 0x0c069166u: goto P_0c069166;
case 0x0c069168u: goto P_0c069168;
case 0x0c06916au: goto P_0c06916a;
case 0x0c06916cu: goto P_0c06916c;
case 0x0c06916eu: goto P_0c06916e;
case 0x0c069170u: goto P_0c069170;
case 0x0c069172u: goto P_0c069172;
case 0x0c069174u: goto P_0c069174;
case 0x0c069176u: goto P_0c069176;
case 0x0c069178u: goto P_0c069178;
case 0x0c06917au: goto P_0c06917a;
case 0x0c06917cu: goto P_0c06917c;
case 0x0c06917eu: goto P_0c06917e;
case 0x0c069180u: goto P_0c069180;
case 0x0c069182u: goto P_0c069182;
case 0x0c069184u: goto P_0c069184;
case 0x0c069186u: goto P_0c069186;
case 0x0c069188u: goto P_0c069188;
case 0x0c06918au: goto P_0c06918a;
case 0x0c06918cu: goto P_0c06918c;
case 0x0c06918eu: goto P_0c06918e;
case 0x0c069190u: goto P_0c069190;
case 0x0c069192u: goto P_0c069192;
case 0x0c069194u: goto P_0c069194;
case 0x0c069196u: goto P_0c069196;
case 0x0c069198u: goto P_0c069198;
case 0x0c06919au: goto P_0c06919a;
case 0x0c06919cu: goto P_0c06919c;
case 0x0c06919eu: goto P_0c06919e;
case 0x0c0691a0u: goto P_0c0691a0;
case 0x0c0691a2u: goto P_0c0691a2;
case 0x0c0691a4u: goto P_0c0691a4;
case 0x0c0691a6u: goto P_0c0691a6;
case 0x0c0691a8u: goto P_0c0691a8;
case 0x0c0691aau: goto P_0c0691aa;
case 0x0c0691acu: goto P_0c0691ac;
case 0x0c0691aeu: goto P_0c0691ae;
case 0x0c0691b0u: goto P_0c0691b0;
case 0x0c0691b2u: goto P_0c0691b2;
case 0x0c0691b4u: goto P_0c0691b4;
case 0x0c0691b6u: goto P_0c0691b6;
case 0x0c0691b8u: goto P_0c0691b8;
case 0x0c0691bau: goto P_0c0691ba;
case 0x0c0691bcu: goto P_0c0691bc;
case 0x0c0691beu: goto P_0c0691be;
case 0x0c0691c0u: goto P_0c0691c0;
case 0x0c0691c2u: goto P_0c0691c2;
case 0x0c0691c4u: goto P_0c0691c4;
case 0x0c0691c6u: goto P_0c0691c6;
case 0x0c0691c8u: goto P_0c0691c8;
case 0x0c0691cau: goto P_0c0691ca;
case 0x0c0691ccu: goto P_0c0691cc;
case 0x0c0691ceu: goto P_0c0691ce;
case 0x0c0691d0u: goto P_0c0691d0;
case 0x0c0691d2u: goto P_0c0691d2;
case 0x0c0691d4u: goto P_0c0691d4;
case 0x0c0691d6u: goto P_0c0691d6;
case 0x0c0691d8u: goto P_0c0691d8;
case 0x0c0691dau: goto P_0c0691da;
case 0x0c0691dcu: goto P_0c0691dc;
case 0x0c0691deu: goto P_0c0691de;
case 0x0c0691e0u: goto P_0c0691e0;
case 0x0c0691e2u: goto P_0c0691e2;
case 0x0c0691e4u: goto P_0c0691e4;
case 0x0c0691e6u: goto P_0c0691e6;
case 0x0c0691e8u: goto P_0c0691e8;
case 0x0c0691eau: goto P_0c0691ea;
case 0x0c0691ecu: goto P_0c0691ec;
case 0x0c0691eeu: goto P_0c0691ee;
case 0x0c0691f0u: goto P_0c0691f0;
case 0x0c0691f2u: goto P_0c0691f2;
case 0x0c0691f4u: goto P_0c0691f4;
case 0x0c0691f6u: goto P_0c0691f6;
case 0x0c0691f8u: goto P_0c0691f8;
case 0x0c0691fau: goto P_0c0691fa;
case 0x0c0691fcu: goto P_0c0691fc;
case 0x0c0691feu: goto P_0c0691fe;
case 0x0c069200u: goto P_0c069200;
case 0x0c069202u: goto P_0c069202;
case 0x0c069204u: goto P_0c069204;
case 0x0c069206u: goto P_0c069206;
case 0x0c069208u: goto P_0c069208;
case 0x0c06920au: goto P_0c06920a;
case 0x0c06920cu: goto P_0c06920c;
case 0x0c06920eu: goto P_0c06920e;
case 0x0c069210u: goto P_0c069210;
case 0x0c069212u: goto P_0c069212;
case 0x0c069214u: goto P_0c069214;
case 0x0c069216u: goto P_0c069216;
case 0x0c069218u: goto P_0c069218;
case 0x0c06921au: goto P_0c06921a;
case 0x0c06921cu: goto P_0c06921c;
case 0x0c06923cu: goto P_0c06923c;
case 0x0c06923eu: goto P_0c06923e;
case 0x0c069240u: goto P_0c069240;
case 0x0c069242u: goto P_0c069242;
case 0x0c069244u: goto P_0c069244;
case 0x0c069246u: goto P_0c069246;
case 0x0c069248u: goto P_0c069248;
case 0x0c06924au: goto P_0c06924a;
case 0x0c06924cu: goto P_0c06924c;
case 0x0c06924eu: goto P_0c06924e;
case 0x0c069250u: goto P_0c069250;
case 0x0c069252u: goto P_0c069252;
case 0x0c069254u: goto P_0c069254;
case 0x0c069256u: goto P_0c069256;
case 0x0c069258u: goto P_0c069258;
case 0x0c06925au: goto P_0c06925a;
case 0x0c06925cu: goto P_0c06925c;
case 0x0c06925eu: goto P_0c06925e;
case 0x0c069260u: goto P_0c069260;
case 0x0c069262u: goto P_0c069262;
case 0x0c069264u: goto P_0c069264;
case 0x0c069266u: goto P_0c069266;
case 0x0c069268u: goto P_0c069268;
case 0x0c06926au: goto P_0c06926a;
case 0x0c06926cu: goto P_0c06926c;
case 0x0c06926eu: goto P_0c06926e;
case 0x0c069270u: goto P_0c069270;
case 0x0c069272u: goto P_0c069272;
case 0x0c069274u: goto P_0c069274;
case 0x0c069276u: goto P_0c069276;
case 0x0c069278u: goto P_0c069278;
case 0x0c06927au: goto P_0c06927a;
case 0x0c06927cu: goto P_0c06927c;
case 0x0c06927eu: goto P_0c06927e;
case 0x0c069280u: goto P_0c069280;
case 0x0c069282u: goto P_0c069282;
case 0x0c069284u: goto P_0c069284;
case 0x0c069286u: goto P_0c069286;
case 0x0c069288u: goto P_0c069288;
case 0x0c06928au: goto P_0c06928a;
case 0x0c06928cu: goto P_0c06928c;
case 0x0c06928eu: goto P_0c06928e;
case 0x0c069290u: goto P_0c069290;
case 0x0c069292u: goto P_0c069292;
case 0x0c069294u: goto P_0c069294;
case 0x0c069296u: goto P_0c069296;
case 0x0c069298u: goto P_0c069298;
case 0x0c06929au: goto P_0c06929a;
case 0x0c06929cu: goto P_0c06929c;
case 0x0c06929eu: goto P_0c06929e;
case 0x0c0692a0u: goto P_0c0692a0;
case 0x0c0692a2u: goto P_0c0692a2;
case 0x0c0692a4u: goto P_0c0692a4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c068f92: /* original f35c, guest PC 0x0c068f92 */
if(!s->budget--) { s->failed_pc=0x0c068f92u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c068f94;
P_0c068f94: /* original f861, guest PC 0x0c068f94 */
if(!s->budget--) { s->failed_pc=0x0c068f94u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'-');
goto P_0c068f96;
P_0c068f96: /* original f57c, guest PC 0x0c068f96 */
if(!s->budget--) { s->failed_pc=0x0c068f96u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c068f98;
P_0c068f98: /* original f531, guest PC 0x0c068f98 */
if(!s->budget--) { s->failed_pc=0x0c068f98u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c068f9a;
P_0c068f9a: /* original f34c, guest PC 0x0c068f9a */
if(!s->budget--) { s->failed_pc=0x0c068f9au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c068f9c;
P_0c068f9c: /* original f46c, guest PC 0x0c068f9c */
if(!s->budget--) { s->failed_pc=0x0c068f9cu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c068f9e;
P_0c068f9e: /* original f431, guest PC 0x0c068f9e */
if(!s->budget--) { s->failed_pc=0x0c068f9eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c068fa0;
P_0c068fa0: /* original f69c, guest PC 0x0c068fa0 */
if(!s->budget--) { s->failed_pc=0x0c068fa0u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c068fa2;
P_0c068fa2: /* original f671, guest PC 0x0c068fa2 */
if(!s->budget--) { s->failed_pc=0x0c068fa2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'-');
goto P_0c068fa4;
P_0c068fa4: /* original f582, guest PC 0x0c068fa4 */
if(!s->budget--) { s->failed_pc=0x0c068fa4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'*');
goto P_0c068fa6;
P_0c068fa6: /* original f28d, guest PC 0x0c068fa6 */
if(!s->budget--) { s->failed_pc=0x0c068fa6u; return 0; }
fr[2]=0;
goto P_0c068fa8;
P_0c068fa8: /* original f462, guest PC 0x0c068fa8 */
if(!s->budget--) { s->failed_pc=0x0c068fa8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c068faa;
P_0c068faa: /* original f34c, guest PC 0x0c068faa */
if(!s->budget--) { s->failed_pc=0x0c068faau; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c068fac;
P_0c068fac: /* original f45c, guest PC 0x0c068fac */
if(!s->budget--) { s->failed_pc=0x0c068facu; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c068fae;
P_0c068fae: /* original f431, guest PC 0x0c068fae */
if(!s->budget--) { s->failed_pc=0x0c068faeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c068fb0;
P_0c068fb0: /* original f425, guest PC 0x0c068fb0 */
if(!s->budget--) { s->failed_pc=0x0c068fb0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c068fb2;
P_0c068fb2: /* original 8b01, guest PC 0x0c068fb2 */
if(!s->budget--) { s->failed_pc=0x0c068fb2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068fb8; }
goto P_0c068fb4;
P_0c068fb4: /* original 000b, guest PC 0x0c068fb4 */
if(!s->budget--) { s->failed_pc=0x0c068fb4u; return 0; }
target=r[16];
r[0]=0x00000002u;
s->pc=target; return ram->oob==0;
P_0c068fb6: /* original e002, guest PC 0x0c068fb6 */
if(!s->budget--) { s->failed_pc=0x0c068fb6u; return 0; }
r[0]=0x00000002u;
goto P_0c068fb8;
P_0c068fb8: /* original f38d, guest PC 0x0c068fb8 */
if(!s->budget--) { s->failed_pc=0x0c068fb8u; return 0; }
fr[3]=0;
goto P_0c068fba;
P_0c068fba: /* original f434, guest PC 0x0c068fba */
if(!s->budget--) { s->failed_pc=0x0c068fbau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c068fbc;
P_0c068fbc: /* original 8b01, guest PC 0x0c068fbc */
if(!s->budget--) { s->failed_pc=0x0c068fbcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068fc2; }
goto P_0c068fbe;
P_0c068fbe: /* original 000b, guest PC 0x0c068fbe */
if(!s->budget--) { s->failed_pc=0x0c068fbeu; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c068fc0: /* original e001, guest PC 0x0c068fc0 */
if(!s->budget--) { s->failed_pc=0x0c068fc0u; return 0; }
r[0]=0x00000001u;
goto P_0c068fc2;
P_0c068fc2: /* original e004, guest PC 0x0c068fc2 */
if(!s->budget--) { s->failed_pc=0x0c068fc2u; return 0; }
r[0]=0x00000004u;
goto P_0c068fc4;
P_0c068fc4: /* original 000b, guest PC 0x0c068fc4 */
if(!s->budget--) { s->failed_pc=0x0c068fc4u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c068fc6: /* original 0009, guest PC 0x0c068fc6 */
if(!s->budget--) { s->failed_pc=0x0c068fc6u; return 0; }
if(!vf3_matrix_family(0x0c068fc8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c068fc8u; return 0; } return 1;
P_0c068fe4: /* original 2fe6, guest PC 0x0c068fe4 */
if(!s->budget--) { s->failed_pc=0x0c068fe4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068fe6;
P_0c068fe6: /* original 2fd6, guest PC 0x0c068fe6 */
if(!s->budget--) { s->failed_pc=0x0c068fe6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068fe8;
P_0c068fe8: /* original 2fc6, guest PC 0x0c068fe8 */
if(!s->budget--) { s->failed_pc=0x0c068fe8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068fea;
P_0c068fea: /* original 2fb6, guest PC 0x0c068fea */
if(!s->budget--) { s->failed_pc=0x0c068feau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068fec;
P_0c068fec: /* original 2fa6, guest PC 0x0c068fec */
if(!s->budget--) { s->failed_pc=0x0c068fecu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068fee;
P_0c068fee: /* original 2f96, guest PC 0x0c068fee */
if(!s->budget--) { s->failed_pc=0x0c068feeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068ff0;
P_0c068ff0: /* original fffb, guest PC 0x0c068ff0 */
if(!s->budget--) { s->failed_pc=0x0c068ff0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c068ff2;
P_0c068ff2: /* original ffeb, guest PC 0x0c068ff2 */
if(!s->budget--) { s->failed_pc=0x0c068ff2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c068ff4;
P_0c068ff4: /* original d348, guest PC 0x0c068ff4 */
if(!s->budget--) { s->failed_pc=0x0c068ff4u; return 0; }
r[3]=read(ram,0x0c069118u,4);
goto P_0c068ff6;
P_0c068ff6: /* original 4f22, guest PC 0x0c068ff6 */
if(!s->budget--) { s->failed_pc=0x0c068ff6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c068ff8;
P_0c068ff8: /* original 6742, guest PC 0x0c068ff8 */
if(!s->budget--) { s->failed_pc=0x0c068ff8u; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c068ffa;
P_0c068ffa: /* original 5541, guest PC 0x0c068ffa */
if(!s->budget--) { s->failed_pc=0x0c068ffau; return 0; }
r[5]=read(ram,r[4]+4,4);
goto P_0c068ffc;
P_0c068ffc: /* original e401, guest PC 0x0c068ffc */
if(!s->budget--) { s->failed_pc=0x0c068ffcu; return 0; }
r[4]=0x00000001u;
goto P_0c068ffe;
P_0c068ffe: /* original 6632, guest PC 0x0c068ffe */
if(!s->budget--) { s->failed_pc=0x0c068ffeu; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c069000;
P_0c069000: /* original 2748, guest PC 0x0c069000 */
if(!s->budget--) { s->failed_pc=0x0c069000u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[4])==0)!=0);
goto P_0c069002;
P_0c069002: /* original 7ffc, guest PC 0x0c069002 */
if(!s->budget--) { s->failed_pc=0x0c069002u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c069004;
P_0c069004: /* original 8d02, guest PC 0x0c069004 */
if(!s->budget--) { s->failed_pc=0x0c069004u; return 0; }
cond=r[17]&1u;
r[5]+=r[6];
if(cond) { goto P_0c06900c; }
goto P_0c069008;
P_0c069006: /* original 356c, guest PC 0x0c069006 */
if(!s->budget--) { s->failed_pc=0x0c069006u; return 0; }
r[5]+=r[6];
goto P_0c069008;
P_0c069008: /* original a07a, guest PC 0x0c069008 */
if(!s->budget--) { s->failed_pc=0x0c069008u; return 0; }
r[0]=0x00000001u;
goto P_0c069100;
P_0c06900a: /* original e001, guest PC 0x0c06900a */
if(!s->budget--) { s->failed_pc=0x0c06900au; return 0; }
r[0]=0x00000001u;
goto P_0c06900c;
P_0c06900c: /* original e018, guest PC 0x0c06900c */
if(!s->budget--) { s->failed_pc=0x0c06900cu; return 0; }
r[0]=0x00000018u;
goto P_0c06900e;
P_0c06900e: /* original fe4c, guest PC 0x0c06900e */
if(!s->budget--) { s->failed_pc=0x0c06900eu; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c069010;
P_0c069010: /* original 6752, guest PC 0x0c069010 */
if(!s->budget--) { s->failed_pc=0x0c069010u; return 0; }
tmp=read(ram,r[5],4);
r[7]=tmp;
goto P_0c069012;
P_0c069012: /* original 2749, guest PC 0x0c069012 */
if(!s->budget--) { s->failed_pc=0x0c069012u; return 0; }
r[7]&=r[4];
goto P_0c069014;
P_0c069014: /* original 2f72, guest PC 0x0c069014 */
if(!s->budget--) { s->failed_pc=0x0c069014u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c069016;
P_0c069016: /* original f456, guest PC 0x0c069016 */
if(!s->budget--) { s->failed_pc=0x0c069016u; return 0; }
vf3_matrix_load(s,ram,4,r[5]+r[0]);
goto P_0c069018;
P_0c069018: /* original f38d, guest PC 0x0c069018 */
if(!s->budget--) { s->failed_pc=0x0c069018u; return 0; }
fr[3]=0;
goto P_0c06901a;
P_0c06901a: /* original f434, guest PC 0x0c06901a */
if(!s->budget--) { s->failed_pc=0x0c06901au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c06901c;
P_0c06901c: /* original 8d6f, guest PC 0x0c06901c */
if(!s->budget--) { s->failed_pc=0x0c06901cu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,15,5);
if(cond) { goto P_0c0690fe; }
goto P_0c069020;
P_0c06901e: /* original ff5c, guest PC 0x0c06901e */
if(!s->budget--) { s->failed_pc=0x0c06901eu; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c069020;
P_0c069020: /* original 5451, guest PC 0x0c069020 */
if(!s->budget--) { s->failed_pc=0x0c069020u; return 0; }
r[4]=read(ram,r[5]+4,4);
goto P_0c069022;
P_0c069022: /* original e008, guest PC 0x0c069022 */
if(!s->budget--) { s->failed_pc=0x0c069022u; return 0; }
r[0]=0x00000008u;
goto P_0c069024;
P_0c069024: /* original f5fc, guest PC 0x0c069024 */
if(!s->budget--) { s->failed_pc=0x0c069024u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c069026;
P_0c069026: /* original 346c, guest PC 0x0c069026 */
if(!s->budget--) { s->failed_pc=0x0c069026u; return 0; }
r[4]+=r[6];
goto P_0c069028;
P_0c069028: /* original 6d43, guest PC 0x0c069028 */
if(!s->budget--) { s->failed_pc=0x0c069028u; return 0; }
r[13]=r[4];
goto P_0c06902a;
P_0c06902a: /* original 5452, guest PC 0x0c06902a */
if(!s->budget--) { s->failed_pc=0x0c06902au; return 0; }
r[4]=read(ram,r[5]+8,4);
goto P_0c06902c;
P_0c06902c: /* original f6d8, guest PC 0x0c06902c */
if(!s->budget--) { s->failed_pc=0x0c06902cu; return 0; }
vf3_matrix_load(s,ram,6,r[13]);
goto P_0c06902e;
P_0c06902e: /* original 346c, guest PC 0x0c06902e */
if(!s->budget--) { s->failed_pc=0x0c06902eu; return 0; }
r[4]+=r[6];
goto P_0c069030;
P_0c069030: /* original f7d6, guest PC 0x0c069030 */
if(!s->budget--) { s->failed_pc=0x0c069030u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c069032;
P_0c069032: /* original 6b43, guest PC 0x0c069032 */
if(!s->budget--) { s->failed_pc=0x0c069032u; return 0; }
r[11]=r[4];
goto P_0c069034;
P_0c069034: /* original 5453, guest PC 0x0c069034 */
if(!s->budget--) { s->failed_pc=0x0c069034u; return 0; }
r[4]=read(ram,r[5]+12,4);
goto P_0c069036;
P_0c069036: /* original f8b8, guest PC 0x0c069036 */
if(!s->budget--) { s->failed_pc=0x0c069036u; return 0; }
vf3_matrix_load(s,ram,8,r[11]);
goto P_0c069038;
P_0c069038: /* original 346c, guest PC 0x0c069038 */
if(!s->budget--) { s->failed_pc=0x0c069038u; return 0; }
r[4]+=r[6];
goto P_0c06903a;
P_0c06903a: /* original f9b6, guest PC 0x0c06903a */
if(!s->budget--) { s->failed_pc=0x0c06903au; return 0; }
vf3_matrix_load(s,ram,9,r[11]+r[0]);
goto P_0c06903c;
P_0c06903c: /* original 6c43, guest PC 0x0c06903c */
if(!s->budget--) { s->failed_pc=0x0c06903cu; return 0; }
r[12]=r[4];
goto P_0c06903e;
P_0c06903e: /* original 5454, guest PC 0x0c06903e */
if(!s->budget--) { s->failed_pc=0x0c06903eu; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c069040;
P_0c069040: /* original 346c, guest PC 0x0c069040 */
if(!s->budget--) { s->failed_pc=0x0c069040u; return 0; }
r[4]+=r[6];
goto P_0c069042;
P_0c069042: /* original 6a43, guest PC 0x0c069042 */
if(!s->budget--) { s->failed_pc=0x0c069042u; return 0; }
r[10]=r[4];
goto P_0c069044;
P_0c069044: /* original bfa5, guest PC 0x0c069044 */
if(!s->budget--) { s->failed_pc=0x0c069044u; return 0; }
target=code_base|0x0c068f92u; r[16]=code_base|0x0c069048u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069048u) { target=s->pc; goto dispatch; }
goto P_0c069048;
P_0c069046: /* original f4ec, guest PC 0x0c069046 */
if(!s->budget--) { s->failed_pc=0x0c069046u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c069048;
P_0c069048: /* original 6e03, guest PC 0x0c069048 */
if(!s->budget--) { s->failed_pc=0x0c069048u; return 0; }
r[14]=r[0];
goto P_0c06904a;
P_0c06904a: /* original e008, guest PC 0x0c06904a */
if(!s->budget--) { s->failed_pc=0x0c06904au; return 0; }
r[0]=0x00000008u;
goto P_0c06904c;
P_0c06904c: /* original f7b6, guest PC 0x0c06904c */
if(!s->budget--) { s->failed_pc=0x0c06904cu; return 0; }
vf3_matrix_load(s,ram,7,r[11]+r[0]);
goto P_0c06904e;
P_0c06904e: /* original f6b8, guest PC 0x0c06904e */
if(!s->budget--) { s->failed_pc=0x0c06904eu; return 0; }
vf3_matrix_load(s,ram,6,r[11]);
goto P_0c069050;
P_0c069050: /* original f9c6, guest PC 0x0c069050 */
if(!s->budget--) { s->failed_pc=0x0c069050u; return 0; }
vf3_matrix_load(s,ram,9,r[12]+r[0]);
goto P_0c069052;
P_0c069052: /* original f8c8, guest PC 0x0c069052 */
if(!s->budget--) { s->failed_pc=0x0c069052u; return 0; }
vf3_matrix_load(s,ram,8,r[12]);
goto P_0c069054;
P_0c069054: /* original f5fc, guest PC 0x0c069054 */
if(!s->budget--) { s->failed_pc=0x0c069054u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c069056;
P_0c069056: /* original bf9c, guest PC 0x0c069056 */
if(!s->budget--) { s->failed_pc=0x0c069056u; return 0; }
target=code_base|0x0c068f92u; r[16]=code_base|0x0c06905au;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06905au) { target=s->pc; goto dispatch; }
goto P_0c06905a;
P_0c069058: /* original f4ec, guest PC 0x0c069058 */
if(!s->budget--) { s->failed_pc=0x0c069058u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06905a;
P_0c06905a: /* original 6903, guest PC 0x0c06905a */
if(!s->budget--) { s->failed_pc=0x0c06905au; return 0; }
r[9]=r[0];
goto P_0c06905c;
P_0c06905c: /* original e008, guest PC 0x0c06905c */
if(!s->budget--) { s->failed_pc=0x0c06905cu; return 0; }
r[0]=0x00000008u;
goto P_0c06905e;
P_0c06905e: /* original f7c6, guest PC 0x0c06905e */
if(!s->budget--) { s->failed_pc=0x0c06905eu; return 0; }
vf3_matrix_load(s,ram,7,r[12]+r[0]);
goto P_0c069060;
P_0c069060: /* original f6c8, guest PC 0x0c069060 */
if(!s->budget--) { s->failed_pc=0x0c069060u; return 0; }
vf3_matrix_load(s,ram,6,r[12]);
goto P_0c069062;
P_0c069062: /* original f9d6, guest PC 0x0c069062 */
if(!s->budget--) { s->failed_pc=0x0c069062u; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c069064;
P_0c069064: /* original f8d8, guest PC 0x0c069064 */
if(!s->budget--) { s->failed_pc=0x0c069064u; return 0; }
vf3_matrix_load(s,ram,8,r[13]);
goto P_0c069066;
P_0c069066: /* original f5fc, guest PC 0x0c069066 */
if(!s->budget--) { s->failed_pc=0x0c069066u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c069068;
P_0c069068: /* original bf93, guest PC 0x0c069068 */
if(!s->budget--) { s->failed_pc=0x0c069068u; return 0; }
target=code_base|0x0c068f92u; r[16]=code_base|0x0c06906cu;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06906cu) { target=s->pc; goto dispatch; }
goto P_0c06906c;
P_0c06906a: /* original f4ec, guest PC 0x0c06906a */
if(!s->budget--) { s->failed_pc=0x0c06906au; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06906c;
P_0c06906c: /* original 6b03, guest PC 0x0c06906c */
if(!s->budget--) { s->failed_pc=0x0c06906cu; return 0; }
r[11]=r[0];
goto P_0c06906e;
P_0c06906e: /* original e008, guest PC 0x0c06906e */
if(!s->budget--) { s->failed_pc=0x0c06906eu; return 0; }
r[0]=0x00000008u;
goto P_0c069070;
P_0c069070: /* original f7c6, guest PC 0x0c069070 */
if(!s->budget--) { s->failed_pc=0x0c069070u; return 0; }
vf3_matrix_load(s,ram,7,r[12]+r[0]);
goto P_0c069072;
P_0c069072: /* original f6c8, guest PC 0x0c069072 */
if(!s->budget--) { s->failed_pc=0x0c069072u; return 0; }
vf3_matrix_load(s,ram,6,r[12]);
goto P_0c069074;
P_0c069074: /* original f9a6, guest PC 0x0c069074 */
if(!s->budget--) { s->failed_pc=0x0c069074u; return 0; }
vf3_matrix_load(s,ram,9,r[10]+r[0]);
goto P_0c069076;
P_0c069076: /* original f8a8, guest PC 0x0c069076 */
if(!s->budget--) { s->failed_pc=0x0c069076u; return 0; }
vf3_matrix_load(s,ram,8,r[10]);
goto P_0c069078;
P_0c069078: /* original f5fc, guest PC 0x0c069078 */
if(!s->budget--) { s->failed_pc=0x0c069078u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c06907a;
P_0c06907a: /* original bf8a, guest PC 0x0c06907a */
if(!s->budget--) { s->failed_pc=0x0c06907au; return 0; }
target=code_base|0x0c068f92u; r[16]=code_base|0x0c06907eu;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06907eu) { target=s->pc; goto dispatch; }
goto P_0c06907e;
P_0c06907c: /* original f4ec, guest PC 0x0c06907c */
if(!s->budget--) { s->failed_pc=0x0c06907cu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06907e;
P_0c06907e: /* original 6c03, guest PC 0x0c06907e */
if(!s->budget--) { s->failed_pc=0x0c06907eu; return 0; }
r[12]=r[0];
goto P_0c069080;
P_0c069080: /* original e008, guest PC 0x0c069080 */
if(!s->budget--) { s->failed_pc=0x0c069080u; return 0; }
r[0]=0x00000008u;
goto P_0c069082;
P_0c069082: /* original f7a6, guest PC 0x0c069082 */
if(!s->budget--) { s->failed_pc=0x0c069082u; return 0; }
vf3_matrix_load(s,ram,7,r[10]+r[0]);
goto P_0c069084;
P_0c069084: /* original f6a8, guest PC 0x0c069084 */
if(!s->budget--) { s->failed_pc=0x0c069084u; return 0; }
vf3_matrix_load(s,ram,6,r[10]);
goto P_0c069086;
P_0c069086: /* original f9d6, guest PC 0x0c069086 */
if(!s->budget--) { s->failed_pc=0x0c069086u; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c069088;
P_0c069088: /* original f8d8, guest PC 0x0c069088 */
if(!s->budget--) { s->failed_pc=0x0c069088u; return 0; }
vf3_matrix_load(s,ram,8,r[13]);
goto P_0c06908a;
P_0c06908a: /* original f5fc, guest PC 0x0c06908a */
if(!s->budget--) { s->failed_pc=0x0c06908au; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c06908c;
P_0c06908c: /* original bf81, guest PC 0x0c06908c */
if(!s->budget--) { s->failed_pc=0x0c06908cu; return 0; }
target=code_base|0x0c068f92u; r[16]=code_base|0x0c069090u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069090u) { target=s->pc; goto dispatch; }
goto P_0c069090;
P_0c06908e: /* original f4ec, guest PC 0x0c06908e */
if(!s->budget--) { s->failed_pc=0x0c06908eu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c069090;
P_0c069090: /* original 6293, guest PC 0x0c069090 */
if(!s->budget--) { s->failed_pc=0x0c069090u; return 0; }
r[2]=r[9];
goto P_0c069092;
P_0c069092: /* original e402, guest PC 0x0c069092 */
if(!s->budget--) { s->failed_pc=0x0c069092u; return 0; }
r[4]=0x00000002u;
goto P_0c069094;
P_0c069094: /* original e504, guest PC 0x0c069094 */
if(!s->budget--) { s->failed_pc=0x0c069094u; return 0; }
r[5]=0x00000004u;
goto P_0c069096;
P_0c069096: /* original 6303, guest PC 0x0c069096 */
if(!s->budget--) { s->failed_pc=0x0c069096u; return 0; }
r[3]=r[0];
goto P_0c069098;
P_0c069098: /* original 2249, guest PC 0x0c069098 */
if(!s->budget--) { s->failed_pc=0x0c069098u; return 0; }
r[2]&=r[4];
goto P_0c06909a;
P_0c06909a: /* original 6603, guest PC 0x0c06909a */
if(!s->budget--) { s->failed_pc=0x0c06909au; return 0; }
r[6]=r[0];
goto P_0c06909c;
P_0c06909c: /* original 2959, guest PC 0x0c06909c */
if(!s->budget--) { s->failed_pc=0x0c06909cu; return 0; }
r[9]&=r[5];
goto P_0c06909e;
P_0c06909e: /* original 2e2b, guest PC 0x0c06909e */
if(!s->budget--) { s->failed_pc=0x0c06909eu; return 0; }
r[14]|=r[2];
goto P_0c0690a0;
P_0c0690a0: /* original 2349, guest PC 0x0c0690a0 */
if(!s->budget--) { s->failed_pc=0x0c0690a0u; return 0; }
r[3]&=r[4];
goto P_0c0690a2;
P_0c0690a2: /* original 2e9b, guest PC 0x0c0690a2 */
if(!s->budget--) { s->failed_pc=0x0c0690a2u; return 0; }
r[14]|=r[9];
goto P_0c0690a4;
P_0c0690a4: /* original 62e3, guest PC 0x0c0690a4 */
if(!s->budget--) { s->failed_pc=0x0c0690a4u; return 0; }
r[2]=r[14];
goto P_0c0690a6;
P_0c0690a6: /* original 2c3b, guest PC 0x0c0690a6 */
if(!s->budget--) { s->failed_pc=0x0c0690a6u; return 0; }
r[12]|=r[3];
goto P_0c0690a8;
P_0c0690a8: /* original 2249, guest PC 0x0c0690a8 */
if(!s->budget--) { s->failed_pc=0x0c0690a8u; return 0; }
r[2]&=r[4];
goto P_0c0690aa;
P_0c0690aa: /* original 63e3, guest PC 0x0c0690aa */
if(!s->budget--) { s->failed_pc=0x0c0690aau; return 0; }
r[3]=r[14];
goto P_0c0690ac;
P_0c0690ac: /* original 2659, guest PC 0x0c0690ac */
if(!s->budget--) { s->failed_pc=0x0c0690acu; return 0; }
r[6]&=r[5];
goto P_0c0690ae;
P_0c0690ae: /* original 2359, guest PC 0x0c0690ae */
if(!s->budget--) { s->failed_pc=0x0c0690aeu; return 0; }
r[3]&=r[5];
goto P_0c0690b0;
P_0c0690b0: /* original 2b2b, guest PC 0x0c0690b0 */
if(!s->budget--) { s->failed_pc=0x0c0690b0u; return 0; }
r[11]|=r[2];
goto P_0c0690b2;
P_0c0690b2: /* original 2b3b, guest PC 0x0c0690b2 */
if(!s->budget--) { s->failed_pc=0x0c0690b2u; return 0; }
r[11]|=r[3];
goto P_0c0690b4;
P_0c0690b4: /* original 2c6b, guest PC 0x0c0690b4 */
if(!s->budget--) { s->failed_pc=0x0c0690b4u; return 0; }
r[12]|=r[6];
goto P_0c0690b6;
P_0c0690b6: /* original 66b3, guest PC 0x0c0690b6 */
if(!s->budget--) { s->failed_pc=0x0c0690b6u; return 0; }
r[6]=r[11];
goto P_0c0690b8;
P_0c0690b8: /* original 2659, guest PC 0x0c0690b8 */
if(!s->budget--) { s->failed_pc=0x0c0690b8u; return 0; }
r[6]&=r[5];
goto P_0c0690ba;
P_0c0690ba: /* original 2668, guest PC 0x0c0690ba */
if(!s->budget--) { s->failed_pc=0x0c0690bau; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0690bc;
P_0c0690bc: /* original 8b02, guest PC 0x0c0690bc */
if(!s->budget--) { s->failed_pc=0x0c0690bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690c4; }
goto P_0c0690be;
P_0c0690be: /* original 63b3, guest PC 0x0c0690be */
if(!s->budget--) { s->failed_pc=0x0c0690beu; return 0; }
r[3]=r[11];
goto P_0c0690c0;
P_0c0690c0: /* original 2348, guest PC 0x0c0690c0 */
if(!s->budget--) { s->failed_pc=0x0c0690c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0690c2;
P_0c0690c2: /* original 8b04, guest PC 0x0c0690c2 */
if(!s->budget--) { s->failed_pc=0x0c0690c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690ce; }
goto P_0c0690c4;
P_0c0690c4: /* original 2668, guest PC 0x0c0690c4 */
if(!s->budget--) { s->failed_pc=0x0c0690c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0690c6;
P_0c0690c6: /* original 8904, guest PC 0x0c0690c6 */
if(!s->budget--) { s->failed_pc=0x0c0690c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0690d2; }
goto P_0c0690c8;
P_0c0690c8: /* original 62b3, guest PC 0x0c0690c8 */
if(!s->budget--) { s->failed_pc=0x0c0690c8u; return 0; }
r[2]=r[11];
goto P_0c0690ca;
P_0c0690ca: /* original 2248, guest PC 0x0c0690ca */
if(!s->budget--) { s->failed_pc=0x0c0690cau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0690cc;
P_0c0690cc: /* original 8b01, guest PC 0x0c0690cc */
if(!s->budget--) { s->failed_pc=0x0c0690ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690d2; }
goto P_0c0690ce;
P_0c0690ce: /* original a017, guest PC 0x0c0690ce */
if(!s->budget--) { s->failed_pc=0x0c0690ceu; return 0; }
r[0]=0x00000002u;
goto P_0c069100;
P_0c0690d0: /* original e002, guest PC 0x0c0690d0 */
if(!s->budget--) { s->failed_pc=0x0c0690d0u; return 0; }
r[0]=0x00000002u;
goto P_0c0690d2;
P_0c0690d2: /* original 62f2, guest PC 0x0c0690d2 */
if(!s->budget--) { s->failed_pc=0x0c0690d2u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0690d4;
P_0c0690d4: /* original 2228, guest PC 0x0c0690d4 */
if(!s->budget--) { s->failed_pc=0x0c0690d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0690d6;
P_0c0690d6: /* original 8b12, guest PC 0x0c0690d6 */
if(!s->budget--) { s->failed_pc=0x0c0690d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690fe; }
goto P_0c0690d8;
P_0c0690d8: /* original 62c3, guest PC 0x0c0690d8 */
if(!s->budget--) { s->failed_pc=0x0c0690d8u; return 0; }
r[2]=r[12];
goto P_0c0690da;
P_0c0690da: /* original 2249, guest PC 0x0c0690da */
if(!s->budget--) { s->failed_pc=0x0c0690dau; return 0; }
r[2]&=r[4];
goto P_0c0690dc;
P_0c0690dc: /* original 2c59, guest PC 0x0c0690dc */
if(!s->budget--) { s->failed_pc=0x0c0690dcu; return 0; }
r[12]&=r[5];
goto P_0c0690de;
P_0c0690de: /* original 2e2b, guest PC 0x0c0690de */
if(!s->budget--) { s->failed_pc=0x0c0690deu; return 0; }
r[14]|=r[2];
goto P_0c0690e0;
P_0c0690e0: /* original 2ecb, guest PC 0x0c0690e0 */
if(!s->budget--) { s->failed_pc=0x0c0690e0u; return 0; }
r[14]|=r[12];
goto P_0c0690e2;
P_0c0690e2: /* original 66e3, guest PC 0x0c0690e2 */
if(!s->budget--) { s->failed_pc=0x0c0690e2u; return 0; }
r[6]=r[14];
goto P_0c0690e4;
P_0c0690e4: /* original 2659, guest PC 0x0c0690e4 */
if(!s->budget--) { s->failed_pc=0x0c0690e4u; return 0; }
r[6]&=r[5];
goto P_0c0690e6;
P_0c0690e6: /* original 2668, guest PC 0x0c0690e6 */
if(!s->budget--) { s->failed_pc=0x0c0690e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0690e8;
P_0c0690e8: /* original 8b02, guest PC 0x0c0690e8 */
if(!s->budget--) { s->failed_pc=0x0c0690e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690f0; }
goto P_0c0690ea;
P_0c0690ea: /* original 62e3, guest PC 0x0c0690ea */
if(!s->budget--) { s->failed_pc=0x0c0690eau; return 0; }
r[2]=r[14];
goto P_0c0690ec;
P_0c0690ec: /* original 2248, guest PC 0x0c0690ec */
if(!s->budget--) { s->failed_pc=0x0c0690ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0690ee;
P_0c0690ee: /* original 8b04, guest PC 0x0c0690ee */
if(!s->budget--) { s->failed_pc=0x0c0690eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690fa; }
goto P_0c0690f0;
P_0c0690f0: /* original 2668, guest PC 0x0c0690f0 */
if(!s->budget--) { s->failed_pc=0x0c0690f0u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0690f2;
P_0c0690f2: /* original 8904, guest PC 0x0c0690f2 */
if(!s->budget--) { s->failed_pc=0x0c0690f2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0690fe; }
goto P_0c0690f4;
P_0c0690f4: /* original 63e3, guest PC 0x0c0690f4 */
if(!s->budget--) { s->failed_pc=0x0c0690f4u; return 0; }
r[3]=r[14];
goto P_0c0690f6;
P_0c0690f6: /* original 2348, guest PC 0x0c0690f6 */
if(!s->budget--) { s->failed_pc=0x0c0690f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0690f8;
P_0c0690f8: /* original 8b01, guest PC 0x0c0690f8 */
if(!s->budget--) { s->failed_pc=0x0c0690f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0690fe; }
goto P_0c0690fa;
P_0c0690fa: /* original a001, guest PC 0x0c0690fa */
if(!s->budget--) { s->failed_pc=0x0c0690fau; return 0; }
r[0]=0x00000004u;
goto P_0c069100;
P_0c0690fc: /* original e004, guest PC 0x0c0690fc */
if(!s->budget--) { s->failed_pc=0x0c0690fcu; return 0; }
r[0]=0x00000004u;
goto P_0c0690fe;
P_0c0690fe: /* original e000, guest PC 0x0c0690fe */
if(!s->budget--) { s->failed_pc=0x0c0690feu; return 0; }
r[0]=0x00000000u;
goto P_0c069100;
P_0c069100: /* original 7f04, guest PC 0x0c069100 */
if(!s->budget--) { s->failed_pc=0x0c069100u; return 0; }
r[15]+=0x00000004u;
goto P_0c069102;
P_0c069102: /* original 4f26, guest PC 0x0c069102 */
if(!s->budget--) { s->failed_pc=0x0c069102u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c069104;
P_0c069104: /* original fef9, guest PC 0x0c069104 */
if(!s->budget--) { s->failed_pc=0x0c069104u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c069106;
P_0c069106: /* original fff9, guest PC 0x0c069106 */
if(!s->budget--) { s->failed_pc=0x0c069106u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c069108;
P_0c069108: /* original 69f6, guest PC 0x0c069108 */
if(!s->budget--) { s->failed_pc=0x0c069108u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06910a;
P_0c06910a: /* original 6af6, guest PC 0x0c06910a */
if(!s->budget--) { s->failed_pc=0x0c06910au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06910c;
P_0c06910c: /* original 6bf6, guest PC 0x0c06910c */
if(!s->budget--) { s->failed_pc=0x0c06910cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06910e;
P_0c06910e: /* original 6cf6, guest PC 0x0c06910e */
if(!s->budget--) { s->failed_pc=0x0c06910eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c069110;
P_0c069110: /* original 6df6, guest PC 0x0c069110 */
if(!s->budget--) { s->failed_pc=0x0c069110u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c069112;
P_0c069112: /* original 000b, guest PC 0x0c069112 */
if(!s->budget--) { s->failed_pc=0x0c069112u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c069114: /* original 6ef6, guest PC 0x0c069114 */
if(!s->budget--) { s->failed_pc=0x0c069114u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c069116u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c069116u; return 0; } return 1;
P_0c06911c: /* original 2fe6, guest PC 0x0c06911c */
if(!s->budget--) { s->failed_pc=0x0c06911cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06911e;
P_0c06911e: /* original e004, guest PC 0x0c06911e */
if(!s->budget--) { s->failed_pc=0x0c06911eu; return 0; }
r[0]=0x00000004u;
goto P_0c069120;
P_0c069120: /* original 2fd6, guest PC 0x0c069120 */
if(!s->budget--) { s->failed_pc=0x0c069120u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c069122;
P_0c069122: /* original 6d43, guest PC 0x0c069122 */
if(!s->budget--) { s->failed_pc=0x0c069122u; return 0; }
r[13]=r[4];
goto P_0c069124;
P_0c069124: /* original 2fc6, guest PC 0x0c069124 */
if(!s->budget--) { s->failed_pc=0x0c069124u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c069126;
P_0c069126: /* original ec0f, guest PC 0x0c069126 */
if(!s->budget--) { s->failed_pc=0x0c069126u; return 0; }
r[12]=0x0000000fu;
goto P_0c069128;
P_0c069128: /* original 2fb6, guest PC 0x0c069128 */
if(!s->budget--) { s->failed_pc=0x0c069128u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06912a;
P_0c06912a: /* original 4f22, guest PC 0x0c06912a */
if(!s->budget--) { s->failed_pc=0x0c06912au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06912c;
P_0c06912c: /* original 7fe0, guest PC 0x0c06912c */
if(!s->budget--) { s->failed_pc=0x0c06912cu; return 0; }
r[15]+=0xffffffe0u;
goto P_0c06912e;
P_0c06912e: /* original 66f3, guest PC 0x0c06912e */
if(!s->budget--) { s->failed_pc=0x0c06912eu; return 0; }
r[6]=r[15];
goto P_0c069130;
P_0c069130: /* original 7604, guest PC 0x0c069130 */
if(!s->budget--) { s->failed_pc=0x0c069130u; return 0; }
r[6]+=0x00000004u;
goto P_0c069132;
P_0c069132: /* original 65f3, guest PC 0x0c069132 */
if(!s->budget--) { s->failed_pc=0x0c069132u; return 0; }
r[5]=r[15];
goto P_0c069134;
P_0c069134: /* original ff4a, guest PC 0x0c069134 */
if(!s->budget--) { s->failed_pc=0x0c069134u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c069136;
P_0c069136: /* original f54d, guest PC 0x0c069136 */
if(!s->budget--) { s->failed_pc=0x0c069136u; return 0; }
fr[5]^=0x80000000u;
goto P_0c069138;
P_0c069138: /* original ff57, guest PC 0x0c069138 */
if(!s->budget--) { s->failed_pc=0x0c069138u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c06913a;
P_0c06913a: /* original d339, guest PC 0x0c06913a */
if(!s->budget--) { s->failed_pc=0x0c06913au; return 0; }
r[3]=read(ram,0x0c069220u,4);
goto P_0c06913c;
P_0c06913c: /* original 6030, guest PC 0x0c06913c */
if(!s->budget--) { s->failed_pc=0x0c06913cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c06913e;
P_0c06913e: /* original 600c, guest PC 0x0c06913e */
if(!s->budget--) { s->failed_pc=0x0c06913eu; return 0; }
r[0]=r[0]&255u;
goto P_0c069140;
P_0c069140: /* original 2c09, guest PC 0x0c069140 */
if(!s->budget--) { s->failed_pc=0x0c069140u; return 0; }
r[12]&=r[0];
goto P_0c069142;
P_0c069142: /* original be07, guest PC 0x0c069142 */
if(!s->budget--) { s->failed_pc=0x0c069142u; return 0; }
target=code_base|0x0c068d54u; r[16]=code_base|0x0c069146u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c069146u) { target=s->pc; goto dispatch; }
goto P_0c069146;
P_0c069144: /* original 64c3, guest PC 0x0c069144 */
if(!s->budget--) { s->failed_pc=0x0c069144u; return 0; }
r[4]=r[12];
goto P_0c069146;
P_0c069146: /* original 906a, guest PC 0x0c069146 */
if(!s->budget--) { s->failed_pc=0x0c069146u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06921eu,2);
goto P_0c069148;
P_0c069148: /* original d536, guest PC 0x0c069148 */
if(!s->budget--) { s->failed_pc=0x0c069148u; return 0; }
r[5]=read(ram,0x0c069224u,4);
goto P_0c06914a;
P_0c06914a: /* original 035e, guest PC 0x0c06914a */
if(!s->budget--) { s->failed_pc=0x0c06914au; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c06914c;
P_0c06914c: /* original 2338, guest PC 0x0c06914c */
if(!s->budget--) { s->failed_pc=0x0c06914cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06914e;
P_0c06914e: /* original 8b06, guest PC 0x0c06914e */
if(!s->budget--) { s->failed_pc=0x0c06914eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06915e; }
goto P_0c069150;
P_0c069150: /* original e004, guest PC 0x0c069150 */
if(!s->budget--) { s->failed_pc=0x0c069150u; return 0; }
r[0]=0x00000004u;
goto P_0c069152;
P_0c069152: /* original 64d3, guest PC 0x0c069152 */
if(!s->budget--) { s->failed_pc=0x0c069152u; return 0; }
r[4]=r[13];
goto P_0c069154;
P_0c069154: /* original f5f6, guest PC 0x0c069154 */
if(!s->budget--) { s->failed_pc=0x0c069154u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c069156;
P_0c069156: /* original be45, guest PC 0x0c069156 */
if(!s->budget--) { s->failed_pc=0x0c069156u; return 0; }
target=code_base|0x0c068de4u; r[16]=code_base|0x0c06915au;
vf3_matrix_load(s,ram,4,r[15]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06915au) { target=s->pc; goto dispatch; }
goto P_0c06915a;
P_0c069158: /* original f4f8, guest PC 0x0c069158 */
if(!s->budget--) { s->failed_pc=0x0c069158u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c06915a;
P_0c06915a: /* original a09d, guest PC 0x0c06915a */
if(!s->budget--) { s->failed_pc=0x0c06915au; return 0; }
r[0]=0x00000000u;
goto P_0c069298;
P_0c06915c: /* original e000, guest PC 0x0c06915c */
if(!s->budget--) { s->failed_pc=0x0c06915cu; return 0; }
r[0]=0x00000000u;
goto P_0c06915e;
P_0c06915e: /* original c732, guest PC 0x0c06915e */
if(!s->budget--) { s->failed_pc=0x0c06915eu; return 0; }
r[0]=code_base|0x00069228u;
goto P_0c069160;
P_0c069160: /* original f3f8, guest PC 0x0c069160 */
if(!s->budget--) { s->failed_pc=0x0c069160u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c069162;
P_0c069162: /* original f408, guest PC 0x0c069162 */
if(!s->budget--) { s->failed_pc=0x0c069162u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c069164;
P_0c069164: /* original f435, guest PC 0x0c069164 */
if(!s->budget--) { s->failed_pc=0x0c069164u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c069166;
P_0c069166: /* original 8b0b, guest PC 0x0c069166 */
if(!s->budget--) { s->failed_pc=0x0c069166u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069180; }
goto P_0c069168;
P_0c069168: /* original e004, guest PC 0x0c069168 */
if(!s->budget--) { s->failed_pc=0x0c069168u; return 0; }
r[0]=0x00000004u;
goto P_0c06916a;
P_0c06916a: /* original f2f6, guest PC 0x0c06916a */
if(!s->budget--) { s->failed_pc=0x0c06916au; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c06916c;
P_0c06916c: /* original f425, guest PC 0x0c06916c */
if(!s->budget--) { s->failed_pc=0x0c06916cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c06916e;
P_0c06916e: /* original 8b07, guest PC 0x0c06916e */
if(!s->budget--) { s->failed_pc=0x0c06916eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069180; }
goto P_0c069170;
P_0c069170: /* original c72e, guest PC 0x0c069170 */
if(!s->budget--) { s->failed_pc=0x0c069170u; return 0; }
r[0]=code_base|0x0006922cu;
goto P_0c069172;
P_0c069172: /* original f108, guest PC 0x0c069172 */
if(!s->budget--) { s->failed_pc=0x0c069172u; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c069174;
P_0c069174: /* original f315, guest PC 0x0c069174 */
if(!s->budget--) { s->failed_pc=0x0c069174u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[1]))!=0);
goto P_0c069176;
P_0c069176: /* original 8b03, guest PC 0x0c069176 */
if(!s->budget--) { s->failed_pc=0x0c069176u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069180; }
goto P_0c069178;
P_0c069178: /* original c72c, guest PC 0x0c069178 */
if(!s->budget--) { s->failed_pc=0x0c069178u; return 0; }
r[0]=code_base|0x0006922cu;
goto P_0c06917a;
P_0c06917a: /* original f308, guest PC 0x0c06917a */
if(!s->budget--) { s->failed_pc=0x0c06917au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06917c;
P_0c06917c: /* original f235, guest PC 0x0c06917c */
if(!s->budget--) { s->failed_pc=0x0c06917cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c06917e;
P_0c06917e: /* original 8901, guest PC 0x0c06917e */
if(!s->budget--) { s->failed_pc=0x0c06917eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069184; }
goto P_0c069180;
P_0c069180: /* original a05d, guest PC 0x0c069180 */
if(!s->budget--) { s->failed_pc=0x0c069180u; return 0; }
r[14]=0x00000001u;
goto P_0c06923e;
P_0c069182: /* original ee01, guest PC 0x0c069182 */
if(!s->budget--) { s->failed_pc=0x0c069182u; return 0; }
r[14]=0x00000001u;
goto P_0c069184;
P_0c069184: /* original c72a, guest PC 0x0c069184 */
if(!s->budget--) { s->failed_pc=0x0c069184u; return 0; }
r[0]=code_base|0x00069230u;
goto P_0c069186;
P_0c069186: /* original f3f8, guest PC 0x0c069186 */
if(!s->budget--) { s->failed_pc=0x0c069186u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c069188;
P_0c069188: /* original f408, guest PC 0x0c069188 */
if(!s->budget--) { s->failed_pc=0x0c069188u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c06918a;
P_0c06918a: /* original e018, guest PC 0x0c06918a */
if(!s->budget--) { s->failed_pc=0x0c06918au; return 0; }
r[0]=0x00000018u;
goto P_0c06918c;
P_0c06918c: /* original ff37, guest PC 0x0c06918c */
if(!s->budget--) { s->failed_pc=0x0c06918cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06918e;
P_0c06918e: /* original e004, guest PC 0x0c06918e */
if(!s->budget--) { s->failed_pc=0x0c06918eu; return 0; }
r[0]=0x00000004u;
goto P_0c069190;
P_0c069190: /* original f3f6, guest PC 0x0c069190 */
if(!s->budget--) { s->failed_pc=0x0c069190u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c069192;
P_0c069192: /* original e014, guest PC 0x0c069192 */
if(!s->budget--) { s->failed_pc=0x0c069192u; return 0; }
r[0]=0x00000014u;
goto P_0c069194;
P_0c069194: /* original e71f, guest PC 0x0c069194 */
if(!s->budget--) { s->failed_pc=0x0c069194u; return 0; }
r[7]=0x0000001fu;
goto P_0c069196;
P_0c069196: /* original ff37, guest PC 0x0c069196 */
if(!s->budget--) { s->failed_pc=0x0c069196u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c069198;
P_0c069198: /* original e018, guest PC 0x0c069198 */
if(!s->budget--) { s->failed_pc=0x0c069198u; return 0; }
r[0]=0x00000018u;
goto P_0c06919a;
P_0c06919a: /* original f3f6, guest PC 0x0c06919a */
if(!s->budget--) { s->failed_pc=0x0c06919au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06919c;
P_0c06919c: /* original e014, guest PC 0x0c06919c */
if(!s->budget--) { s->failed_pc=0x0c06919cu; return 0; }
r[0]=0x00000014u;
goto P_0c06919e;
P_0c06919e: /* original f54c, guest PC 0x0c06919e */
if(!s->budget--) { s->failed_pc=0x0c06919eu; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0691a0;
P_0c0691a0: /* original f530, guest PC 0x0c0691a0 */
if(!s->budget--) { s->failed_pc=0x0c0691a0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0691a2;
P_0c0691a2: /* original f2f6, guest PC 0x0c0691a2 */
if(!s->budget--) { s->failed_pc=0x0c0691a2u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0691a4;
P_0c0691a4: /* original e01c, guest PC 0x0c0691a4 */
if(!s->budget--) { s->failed_pc=0x0c0691a4u; return 0; }
r[0]=0x0000001cu;
goto P_0c0691a6;
P_0c0691a6: /* original f420, guest PC 0x0c0691a6 */
if(!s->budget--) { s->failed_pc=0x0c0691a6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'+');
goto P_0c0691a8;
P_0c0691a8: /* original f53d, guest PC 0x0c0691a8 */
if(!s->budget--) { s->failed_pc=0x0c0691a8u; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c0691aa;
P_0c0691aa: /* original ff47, guest PC 0x0c0691aa */
if(!s->budget--) { s->failed_pc=0x0c0691aau; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0691ac;
P_0c0691ac: /* original f14c, guest PC 0x0c0691ac */
if(!s->budget--) { s->failed_pc=0x0c0691acu; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c0691ae;
P_0c0691ae: /* original 045a, guest PC 0x0c0691ae */
if(!s->budget--) { s->failed_pc=0x0c0691aeu; return 0; }
r[4]=r[53];
goto P_0c0691b0;
P_0c0691b0: /* original f13d, guest PC 0x0c0691b0 */
if(!s->budget--) { s->failed_pc=0x0c0691b0u; return 0; }
r[53]=truncate_float(fr[1]);
goto P_0c0691b2;
P_0c0691b2: /* original 9034, guest PC 0x0c0691b2 */
if(!s->budget--) { s->failed_pc=0x0c0691b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06921eu,2);
goto P_0c0691b4;
P_0c0691b4: /* original 2479, guest PC 0x0c0691b4 */
if(!s->budget--) { s->failed_pc=0x0c0691b4u; return 0; }
r[4]&=r[7];
goto P_0c0691b6;
P_0c0691b6: /* original 065a, guest PC 0x0c0691b6 */
if(!s->budget--) { s->failed_pc=0x0c0691b6u; return 0; }
r[6]=r[53];
goto P_0c0691b8;
P_0c0691b8: /* original 2679, guest PC 0x0c0691b8 */
if(!s->budget--) { s->failed_pc=0x0c0691b8u; return 0; }
r[6]&=r[7];
goto P_0c0691ba;
P_0c0691ba: /* original 4608, guest PC 0x0c0691ba */
if(!s->budget--) { s->failed_pc=0x0c0691bau; return 0; }
r[6]<<=2;
goto P_0c0691bc;
P_0c0691bc: /* original 4608, guest PC 0x0c0691bc */
if(!s->budget--) { s->failed_pc=0x0c0691bcu; return 0; }
r[6]<<=2;
goto P_0c0691be;
P_0c0691be: /* original 4600, guest PC 0x0c0691be */
if(!s->budget--) { s->failed_pc=0x0c0691beu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0691c0;
P_0c0691c0: /* original 246b, guest PC 0x0c0691c0 */
if(!s->budget--) { s->failed_pc=0x0c0691c0u; return 0; }
r[4]|=r[6];
goto P_0c0691c2;
P_0c0691c2: /* original 4408, guest PC 0x0c0691c2 */
if(!s->budget--) { s->failed_pc=0x0c0691c2u; return 0; }
r[4]<<=2;
goto P_0c0691c4;
P_0c0691c4: /* original 035e, guest PC 0x0c0691c4 */
if(!s->budget--) { s->failed_pc=0x0c0691c4u; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c0691c6;
P_0c0691c6: /* original 343c, guest PC 0x0c0691c6 */
if(!s->budget--) { s->failed_pc=0x0c0691c6u; return 0; }
r[4]+=r[3];
goto P_0c0691c8;
P_0c0691c8: /* original 6442, guest PC 0x0c0691c8 */
if(!s->budget--) { s->failed_pc=0x0c0691c8u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0691ca;
P_0c0691ca: /* original 6043, guest PC 0x0c0691ca */
if(!s->budget--) { s->failed_pc=0x0c0691cau; return 0; }
r[0]=r[4];
goto P_0c0691cc;
P_0c0691cc: /* original 88ff, guest PC 0x0c0691cc */
if(!s->budget--) { s->failed_pc=0x0c0691ccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0691ce;
P_0c0691ce: /* original 8935, guest PC 0x0c0691ce */
if(!s->budget--) { s->failed_pc=0x0c0691ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06923c; }
goto P_0c0691d0;
P_0c0691d0: /* original db18, guest PC 0x0c0691d0 */
if(!s->budget--) { s->failed_pc=0x0c0691d0u; return 0; }
r[11]=read(ram,0x0c069234u,4);
goto P_0c0691d2;
P_0c0691d2: /* original 63b2, guest PC 0x0c0691d2 */
if(!s->budget--) { s->failed_pc=0x0c0691d2u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c0691d4;
P_0c0691d4: /* original 343c, guest PC 0x0c0691d4 */
if(!s->budget--) { s->failed_pc=0x0c0691d4u; return 0; }
r[4]+=r[3];
goto P_0c0691d6;
P_0c0691d6: /* original 6e43, guest PC 0x0c0691d6 */
if(!s->budget--) { s->failed_pc=0x0c0691d6u; return 0; }
r[14]=r[4];
goto P_0c0691d8;
P_0c0691d8: /* original 60e2, guest PC 0x0c0691d8 */
if(!s->budget--) { s->failed_pc=0x0c0691d8u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0691da;
P_0c0691da: /* original 88ff, guest PC 0x0c0691da */
if(!s->budget--) { s->failed_pc=0x0c0691dau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0691dc;
P_0c0691dc: /* original 892e, guest PC 0x0c0691dc */
if(!s->budget--) { s->failed_pc=0x0c0691dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06923c; }
goto P_0c0691de;
P_0c0691de: /* original e014, guest PC 0x0c0691de */
if(!s->budget--) { s->failed_pc=0x0c0691deu; return 0; }
r[0]=0x00000014u;
goto P_0c0691e0;
P_0c0691e0: /* original f5f6, guest PC 0x0c0691e0 */
if(!s->budget--) { s->failed_pc=0x0c0691e0u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0691e2;
P_0c0691e2: /* original e018, guest PC 0x0c0691e2 */
if(!s->budget--) { s->failed_pc=0x0c0691e2u; return 0; }
r[0]=0x00000018u;
goto P_0c0691e4;
P_0c0691e4: /* original f4f6, guest PC 0x0c0691e4 */
if(!s->budget--) { s->failed_pc=0x0c0691e4u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0691e6;
P_0c0691e6: /* original befd, guest PC 0x0c0691e6 */
if(!s->budget--) { s->failed_pc=0x0c0691e6u; return 0; }
target=code_base|0x0c068fe4u; r[16]=code_base|0x0c0691eau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0691eau) { target=s->pc; goto dispatch; }
goto P_0c0691ea;
P_0c0691e8: /* original 64e3, guest PC 0x0c0691e8 */
if(!s->budget--) { s->failed_pc=0x0c0691e8u; return 0; }
r[4]=r[14];
goto P_0c0691ea;
P_0c0691ea: /* original 6403, guest PC 0x0c0691ea */
if(!s->budget--) { s->failed_pc=0x0c0691eau; return 0; }
r[4]=r[0];
goto P_0c0691ec;
P_0c0691ec: /* original 2448, guest PC 0x0c0691ec */
if(!s->budget--) { s->failed_pc=0x0c0691ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0691ee;
P_0c0691ee: /* original 8914, guest PC 0x0c0691ee */
if(!s->budget--) { s->failed_pc=0x0c0691eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06921a; }
goto P_0c0691f0;
P_0c0691f0: /* original 63b2, guest PC 0x0c0691f0 */
if(!s->budget--) { s->failed_pc=0x0c0691f0u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c0691f2;
P_0c0691f2: /* original e014, guest PC 0x0c0691f2 */
if(!s->budget--) { s->failed_pc=0x0c0691f2u; return 0; }
r[0]=0x00000014u;
goto P_0c0691f4;
P_0c0691f4: /* original 54e1, guest PC 0x0c0691f4 */
if(!s->budget--) { s->failed_pc=0x0c0691f4u; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c0691f6;
P_0c0691f6: /* original d510, guest PC 0x0c0691f6 */
if(!s->budget--) { s->failed_pc=0x0c0691f6u; return 0; }
r[5]=read(ram,0x0c069238u,4);
goto P_0c0691f8;
P_0c0691f8: /* original 343c, guest PC 0x0c0691f8 */
if(!s->budget--) { s->failed_pc=0x0c0691f8u; return 0; }
r[4]+=r[3];
goto P_0c0691fa;
P_0c0691fa: /* original f446, guest PC 0x0c0691fa */
if(!s->budget--) { s->failed_pc=0x0c0691fau; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0691fc;
P_0c0691fc: /* original e018, guest PC 0x0c0691fc */
if(!s->budget--) { s->failed_pc=0x0c0691fcu; return 0; }
r[0]=0x00000018u;
goto P_0c0691fe;
P_0c0691fe: /* original f546, guest PC 0x0c0691fe */
if(!s->budget--) { s->failed_pc=0x0c0691feu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c069200;
P_0c069200: /* original e01c, guest PC 0x0c069200 */
if(!s->budget--) { s->failed_pc=0x0c069200u; return 0; }
r[0]=0x0000001cu;
goto P_0c069202;
P_0c069202: /* original f646, guest PC 0x0c069202 */
if(!s->budget--) { s->failed_pc=0x0c069202u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c069204;
P_0c069204: /* original e00c, guest PC 0x0c069204 */
if(!s->budget--) { s->failed_pc=0x0c069204u; return 0; }
r[0]=0x0000000cu;
goto P_0c069206;
P_0c069206: /* original 6442, guest PC 0x0c069206 */
if(!s->budget--) { s->failed_pc=0x0c069206u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c069208;
P_0c069208: /* original ff47, guest PC 0x0c069208 */
if(!s->budget--) { s->failed_pc=0x0c069208u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c06920a;
P_0c06920a: /* original e010, guest PC 0x0c06920a */
if(!s->budget--) { s->failed_pc=0x0c06920au; return 0; }
r[0]=0x00000010u;
goto P_0c06920c;
P_0c06920c: /* original 4400, guest PC 0x0c06920c */
if(!s->budget--) { s->failed_pc=0x0c06920cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06920e;
P_0c06920e: /* original ff57, guest PC 0x0c06920e */
if(!s->budget--) { s->failed_pc=0x0c06920eu; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c069210;
P_0c069210: /* original 2459, guest PC 0x0c069210 */
if(!s->budget--) { s->failed_pc=0x0c069210u; return 0; }
r[4]&=r[5];
goto P_0c069212;
P_0c069212: /* original e008, guest PC 0x0c069212 */
if(!s->budget--) { s->failed_pc=0x0c069212u; return 0; }
r[0]=0x00000008u;
goto P_0c069214;
P_0c069214: /* original 6e43, guest PC 0x0c069214 */
if(!s->budget--) { s->failed_pc=0x0c069214u; return 0; }
r[14]=r[4];
goto P_0c069216;
P_0c069216: /* original a01a, guest PC 0x0c069216 */
if(!s->budget--) { s->failed_pc=0x0c069216u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c06924e;
P_0c069218: /* original ff67, guest PC 0x0c069218 */
if(!s->budget--) { s->failed_pc=0x0c069218u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c06921a;
P_0c06921a: /* original afdd, guest PC 0x0c06921a */
if(!s->budget--) { s->failed_pc=0x0c06921au; return 0; }
r[14]+=0x00000008u;
goto P_0c0691d8;
P_0c06921c: /* original 7e08, guest PC 0x0c06921c */
if(!s->budget--) { s->failed_pc=0x0c06921cu; return 0; }
r[14]+=0x00000008u;
if(!vf3_matrix_family(0x0c06921eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06921eu; return 0; } return 1;
P_0c06923c: /* original ee02, guest PC 0x0c06923c */
if(!s->budget--) { s->failed_pc=0x0c06923cu; return 0; }
r[14]=0x00000002u;
goto P_0c06923e;
P_0c06923e: /* original e010, guest PC 0x0c06923e */
if(!s->budget--) { s->failed_pc=0x0c06923eu; return 0; }
r[0]=0x00000010u;
goto P_0c069240;
P_0c069240: /* original f39d, guest PC 0x0c069240 */
if(!s->budget--) { s->failed_pc=0x0c069240u; return 0; }
fr[3]=0x3f800000u;
goto P_0c069242;
P_0c069242: /* original ff37, guest PC 0x0c069242 */
if(!s->budget--) { s->failed_pc=0x0c069242u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c069244;
P_0c069244: /* original e008, guest PC 0x0c069244 */
if(!s->budget--) { s->failed_pc=0x0c069244u; return 0; }
r[0]=0x00000008u;
goto P_0c069246;
P_0c069246: /* original f38d, guest PC 0x0c069246 */
if(!s->budget--) { s->failed_pc=0x0c069246u; return 0; }
fr[3]=0;
goto P_0c069248;
P_0c069248: /* original ff37, guest PC 0x0c069248 */
if(!s->budget--) { s->failed_pc=0x0c069248u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06924a;
P_0c06924a: /* original e00c, guest PC 0x0c06924a */
if(!s->budget--) { s->failed_pc=0x0c06924au; return 0; }
r[0]=0x0000000cu;
goto P_0c06924c;
P_0c06924c: /* original ff37, guest PC 0x0c06924c */
if(!s->budget--) { s->failed_pc=0x0c06924cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06924e;
P_0c06924e: /* original 60c3, guest PC 0x0c06924e */
if(!s->budget--) { s->failed_pc=0x0c06924eu; return 0; }
r[0]=r[12];
goto P_0c069250;
P_0c069250: /* original 880d, guest PC 0x0c069250 */
if(!s->budget--) { s->failed_pc=0x0c069250u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c069252;
P_0c069252: /* original 8b02, guest PC 0x0c069252 */
if(!s->budget--) { s->failed_pc=0x0c069252u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06925a; }
goto P_0c069254;
P_0c069254: /* original e204, guest PC 0x0c069254 */
if(!s->budget--) { s->failed_pc=0x0c069254u; return 0; }
r[2]=0x00000004u;
goto P_0c069256;
P_0c069256: /* original a013, guest PC 0x0c069256 */
if(!s->budget--) { s->failed_pc=0x0c069256u; return 0; }
r[14]|=r[2];
goto P_0c069280;
P_0c069258: /* original 2e2b, guest PC 0x0c069258 */
if(!s->budget--) { s->failed_pc=0x0c069258u; return 0; }
r[14]|=r[2];
goto P_0c06925a;
P_0c06925a: /* original 880b, guest PC 0x0c06925a */
if(!s->budget--) { s->failed_pc=0x0c06925au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c06925c;
P_0c06925c: /* original 8b10, guest PC 0x0c06925c */
if(!s->budget--) { s->failed_pc=0x0c06925cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069280; }
goto P_0c06925e;
P_0c06925e: /* original 63f3, guest PC 0x0c06925e */
if(!s->budget--) { s->failed_pc=0x0c06925eu; return 0; }
r[3]=r[15];
goto P_0c069260;
P_0c069260: /* original 7308, guest PC 0x0c069260 */
if(!s->budget--) { s->failed_pc=0x0c069260u; return 0; }
r[3]+=0x00000008u;
goto P_0c069262;
P_0c069262: /* original 2f36, guest PC 0x0c069262 */
if(!s->budget--) { s->failed_pc=0x0c069262u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c069264;
P_0c069264: /* original 62f3, guest PC 0x0c069264 */
if(!s->budget--) { s->failed_pc=0x0c069264u; return 0; }
r[2]=r[15];
goto P_0c069266;
P_0c069266: /* original 7214, guest PC 0x0c069266 */
if(!s->budget--) { s->failed_pc=0x0c069266u; return 0; }
r[2]+=0x00000014u;
goto P_0c069268;
P_0c069268: /* original 2f26, guest PC 0x0c069268 */
if(!s->budget--) { s->failed_pc=0x0c069268u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06926a;
P_0c06926a: /* original 65f3, guest PC 0x0c06926a */
if(!s->budget--) { s->failed_pc=0x0c06926au; return 0; }
r[5]=r[15];
goto P_0c06926c;
P_0c06926c: /* original d344, guest PC 0x0c06926c */
if(!s->budget--) { s->failed_pc=0x0c06926cu; return 0; }
r[3]=read(ram,0x0c069380u,4);
goto P_0c06926e;
P_0c06926e: /* original 66f3, guest PC 0x0c06926e */
if(!s->budget--) { s->failed_pc=0x0c06926eu; return 0; }
r[6]=r[15];
goto P_0c069270;
P_0c069270: /* original 67f3, guest PC 0x0c069270 */
if(!s->budget--) { s->failed_pc=0x0c069270u; return 0; }
r[7]=r[15];
goto P_0c069272;
P_0c069272: /* original 64f3, guest PC 0x0c069272 */
if(!s->budget--) { s->failed_pc=0x0c069272u; return 0; }
r[4]=r[15];
goto P_0c069274;
P_0c069274: /* original 7524, guest PC 0x0c069274 */
if(!s->budget--) { s->failed_pc=0x0c069274u; return 0; }
r[5]+=0x00000024u;
goto P_0c069276;
P_0c069276: /* original 761c, guest PC 0x0c069276 */
if(!s->budget--) { s->failed_pc=0x0c069276u; return 0; }
r[6]+=0x0000001cu;
goto P_0c069278;
P_0c069278: /* original 7714, guest PC 0x0c069278 */
if(!s->budget--) { s->failed_pc=0x0c069278u; return 0; }
r[7]+=0x00000014u;
goto P_0c06927a;
P_0c06927a: /* original 430b, guest PC 0x0c06927a */
if(!s->budget--) { s->failed_pc=0x0c06927au; return 0; }
target=r[3];
r[16]=code_base|0x0c06927eu;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06927eu) { target=s->pc; goto dispatch; }
goto P_0c06927e;
P_0c06927c: /* original 7420, guest PC 0x0c06927c */
if(!s->budget--) { s->failed_pc=0x0c06927cu; return 0; }
r[4]+=0x00000020u;
goto P_0c06927e;
P_0c06927e: /* original 7f08, guest PC 0x0c06927e */
if(!s->budget--) { s->failed_pc=0x0c06927eu; return 0; }
r[15]+=0x00000008u;
goto P_0c069280;
P_0c069280: /* original e00c, guest PC 0x0c069280 */
if(!s->budget--) { s->failed_pc=0x0c069280u; return 0; }
r[0]=0x0000000cu;
goto P_0c069282;
P_0c069282: /* original f3f6, guest PC 0x0c069282 */
if(!s->budget--) { s->failed_pc=0x0c069282u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c069284;
P_0c069284: /* original e010, guest PC 0x0c069284 */
if(!s->budget--) { s->failed_pc=0x0c069284u; return 0; }
r[0]=0x00000010u;
goto P_0c069286;
P_0c069286: /* original fd3a, guest PC 0x0c069286 */
if(!s->budget--) { s->failed_pc=0x0c069286u; return 0; }
vf3_matrix_store(s,ram,3,r[13]);
goto P_0c069288;
P_0c069288: /* original f3f6, guest PC 0x0c069288 */
if(!s->budget--) { s->failed_pc=0x0c069288u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06928a;
P_0c06928a: /* original e004, guest PC 0x0c06928a */
if(!s->budget--) { s->failed_pc=0x0c06928au; return 0; }
r[0]=0x00000004u;
goto P_0c06928c;
P_0c06928c: /* original fd37, guest PC 0x0c06928c */
if(!s->budget--) { s->failed_pc=0x0c06928cu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c06928e;
P_0c06928e: /* original e008, guest PC 0x0c06928e */
if(!s->budget--) { s->failed_pc=0x0c06928eu; return 0; }
r[0]=0x00000008u;
goto P_0c069290;
P_0c069290: /* original f3f6, guest PC 0x0c069290 */
if(!s->budget--) { s->failed_pc=0x0c069290u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c069292;
P_0c069292: /* original e008, guest PC 0x0c069292 */
if(!s->budget--) { s->failed_pc=0x0c069292u; return 0; }
r[0]=0x00000008u;
goto P_0c069294;
P_0c069294: /* original fd37, guest PC 0x0c069294 */
if(!s->budget--) { s->failed_pc=0x0c069294u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c069296;
P_0c069296: /* original 60e3, guest PC 0x0c069296 */
if(!s->budget--) { s->failed_pc=0x0c069296u; return 0; }
r[0]=r[14];
goto P_0c069298;
P_0c069298: /* original 7f20, guest PC 0x0c069298 */
if(!s->budget--) { s->failed_pc=0x0c069298u; return 0; }
r[15]+=0x00000020u;
goto P_0c06929a;
P_0c06929a: /* original 4f26, guest PC 0x0c06929a */
if(!s->budget--) { s->failed_pc=0x0c06929au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06929c;
P_0c06929c: /* original 6bf6, guest PC 0x0c06929c */
if(!s->budget--) { s->failed_pc=0x0c06929cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06929e;
P_0c06929e: /* original 6cf6, guest PC 0x0c06929e */
if(!s->budget--) { s->failed_pc=0x0c06929eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0692a0;
P_0c0692a0: /* original 6df6, guest PC 0x0c0692a0 */
if(!s->budget--) { s->failed_pc=0x0c0692a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0692a2;
P_0c0692a2: /* original 000b, guest PC 0x0c0692a2 */
if(!s->budget--) { s->failed_pc=0x0c0692a2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0692a4: /* original 6ef6, guest PC 0x0c0692a4 */
if(!s->budget--) { s->failed_pc=0x0c0692a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0692a6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0692a6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
