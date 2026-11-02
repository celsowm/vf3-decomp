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
int vf3_away_batch16_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c0692a6u: goto P_0c0692a6;
case 0x0c0692a8u: goto P_0c0692a8;
case 0x0c0692aau: goto P_0c0692aa;
case 0x0c0692acu: goto P_0c0692ac;
case 0x0c0692aeu: goto P_0c0692ae;
case 0x0c0692b0u: goto P_0c0692b0;
case 0x0c0692b2u: goto P_0c0692b2;
case 0x0c0692b4u: goto P_0c0692b4;
case 0x0c0692b6u: goto P_0c0692b6;
case 0x0c0692b8u: goto P_0c0692b8;
case 0x0c0692bau: goto P_0c0692ba;
case 0x0c0692bcu: goto P_0c0692bc;
case 0x0c0692beu: goto P_0c0692be;
case 0x0c0692c0u: goto P_0c0692c0;
case 0x0c0692c2u: goto P_0c0692c2;
case 0x0c0692c4u: goto P_0c0692c4;
case 0x0c0692c6u: goto P_0c0692c6;
case 0x0c0692c8u: goto P_0c0692c8;
case 0x0c0692cau: goto P_0c0692ca;
case 0x0c0692ccu: goto P_0c0692cc;
case 0x0c0692ceu: goto P_0c0692ce;
case 0x0c0692d0u: goto P_0c0692d0;
case 0x0c0692d2u: goto P_0c0692d2;
case 0x0c0692d4u: goto P_0c0692d4;
case 0x0c0692d6u: goto P_0c0692d6;
case 0x0c0692d8u: goto P_0c0692d8;
case 0x0c0692dau: goto P_0c0692da;
case 0x0c0692dcu: goto P_0c0692dc;
case 0x0c0692deu: goto P_0c0692de;
case 0x0c0692e0u: goto P_0c0692e0;
case 0x0c0692e2u: goto P_0c0692e2;
case 0x0c0692e4u: goto P_0c0692e4;
case 0x0c0692e6u: goto P_0c0692e6;
case 0x0c0692e8u: goto P_0c0692e8;
case 0x0c0692eau: goto P_0c0692ea;
case 0x0c0692ecu: goto P_0c0692ec;
case 0x0c0692eeu: goto P_0c0692ee;
case 0x0c0692f0u: goto P_0c0692f0;
case 0x0c0692f2u: goto P_0c0692f2;
case 0x0c0692f4u: goto P_0c0692f4;
case 0x0c0692f6u: goto P_0c0692f6;
case 0x0c0692f8u: goto P_0c0692f8;
case 0x0c0692fau: goto P_0c0692fa;
case 0x0c0692fcu: goto P_0c0692fc;
case 0x0c0692feu: goto P_0c0692fe;
case 0x0c069300u: goto P_0c069300;
case 0x0c069302u: goto P_0c069302;
case 0x0c069304u: goto P_0c069304;
case 0x0c069306u: goto P_0c069306;
case 0x0c069308u: goto P_0c069308;
case 0x0c06930au: goto P_0c06930a;
case 0x0c06930cu: goto P_0c06930c;
case 0x0c06930eu: goto P_0c06930e;
case 0x0c069310u: goto P_0c069310;
case 0x0c069312u: goto P_0c069312;
case 0x0c069314u: goto P_0c069314;
case 0x0c069316u: goto P_0c069316;
case 0x0c069318u: goto P_0c069318;
case 0x0c06931au: goto P_0c06931a;
case 0x0c06931cu: goto P_0c06931c;
case 0x0c06931eu: goto P_0c06931e;
case 0x0c069320u: goto P_0c069320;
case 0x0c069322u: goto P_0c069322;
case 0x0c069324u: goto P_0c069324;
case 0x0c069326u: goto P_0c069326;
case 0x0c069328u: goto P_0c069328;
case 0x0c06932au: goto P_0c06932a;
case 0x0c06932cu: goto P_0c06932c;
case 0x0c06932eu: goto P_0c06932e;
case 0x0c069330u: goto P_0c069330;
case 0x0c069332u: goto P_0c069332;
case 0x0c069334u: goto P_0c069334;
case 0x0c069336u: goto P_0c069336;
case 0x0c069338u: goto P_0c069338;
case 0x0c06933au: goto P_0c06933a;
case 0x0c06933cu: goto P_0c06933c;
case 0x0c06933eu: goto P_0c06933e;
case 0x0c069340u: goto P_0c069340;
case 0x0c069342u: goto P_0c069342;
case 0x0c069344u: goto P_0c069344;
case 0x0c069346u: goto P_0c069346;
case 0x0c069348u: goto P_0c069348;
case 0x0c06934au: goto P_0c06934a;
case 0x0c06934cu: goto P_0c06934c;
case 0x0c06934eu: goto P_0c06934e;
case 0x0c069350u: goto P_0c069350;
case 0x0c069352u: goto P_0c069352;
case 0x0c069354u: goto P_0c069354;
case 0x0c069356u: goto P_0c069356;
case 0x0c069358u: goto P_0c069358;
case 0x0c06935au: goto P_0c06935a;
case 0x0c06935cu: goto P_0c06935c;
case 0x0c06935eu: goto P_0c06935e;
case 0x0c069360u: goto P_0c069360;
case 0x0c069362u: goto P_0c069362;
case 0x0c069364u: goto P_0c069364;
case 0x0c069366u: goto P_0c069366;
case 0x0c069368u: goto P_0c069368;
case 0x0c06936au: goto P_0c06936a;
case 0x0c06936cu: goto P_0c06936c;
case 0x0c06936eu: goto P_0c06936e;
case 0x0c069370u: goto P_0c069370;
case 0x0c069372u: goto P_0c069372;
case 0x0c069374u: goto P_0c069374;
case 0x0c069376u: goto P_0c069376;
case 0x0c069378u: goto P_0c069378;
case 0x0c06937au: goto P_0c06937a;
case 0x0c06937cu: goto P_0c06937c;
default: return vf3_matrix_family(target,s,ram);
}
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
P_0c0692a6: /* original 2fe6, guest PC 0x0c0692a6 */
if(!s->budget--) { s->failed_pc=0x0c0692a6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0692a8;
P_0c0692a8: /* original e004, guest PC 0x0c0692a8 */
if(!s->budget--) { s->failed_pc=0x0c0692a8u; return 0; }
r[0]=0x00000004u;
goto P_0c0692aa;
P_0c0692aa: /* original ffeb, guest PC 0x0c0692aa */
if(!s->budget--) { s->failed_pc=0x0c0692aau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0692ac;
P_0c0692ac: /* original d335, guest PC 0x0c0692ac */
if(!s->budget--) { s->failed_pc=0x0c0692acu; return 0; }
r[3]=read(ram,0x0c069384u,4);
goto P_0c0692ae;
P_0c0692ae: /* original 7ff4, guest PC 0x0c0692ae */
if(!s->budget--) { s->failed_pc=0x0c0692aeu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0692b0;
P_0c0692b0: /* original 5441, guest PC 0x0c0692b0 */
if(!s->budget--) { s->failed_pc=0x0c0692b0u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0692b2;
P_0c0692b2: /* original 6e32, guest PC 0x0c0692b2 */
if(!s->budget--) { s->failed_pc=0x0c0692b2u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c0692b4;
P_0c0692b4: /* original ff4a, guest PC 0x0c0692b4 */
if(!s->budget--) { s->failed_pc=0x0c0692b4u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c0692b6;
P_0c0692b6: /* original 34ec, guest PC 0x0c0692b6 */
if(!s->budget--) { s->failed_pc=0x0c0692b6u; return 0; }
r[4]+=r[14];
goto P_0c0692b8;
P_0c0692b8: /* original ff57, guest PC 0x0c0692b8 */
if(!s->budget--) { s->failed_pc=0x0c0692b8u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0692ba;
P_0c0692ba: /* original 5241, guest PC 0x0c0692ba */
if(!s->budget--) { s->failed_pc=0x0c0692bau; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c0692bc;
P_0c0692bc: /* original 6073, guest PC 0x0c0692bc */
if(!s->budget--) { s->failed_pc=0x0c0692bcu; return 0; }
r[0]=r[7];
goto P_0c0692be;
P_0c0692be: /* original 8804, guest PC 0x0c0692be */
if(!s->budget--) { s->failed_pc=0x0c0692beu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0692c0;
P_0c0692c0: /* original 1f22, guest PC 0x0c0692c0 */
if(!s->budget--) { s->failed_pc=0x0c0692c0u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0692c2;
P_0c0692c2: /* original 8902, guest PC 0x0c0692c2 */
if(!s->budget--) { s->failed_pc=0x0c0692c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0692ca; }
goto P_0c0692c4;
P_0c0692c4: /* original 5342, guest PC 0x0c0692c4 */
if(!s->budget--) { s->failed_pc=0x0c0692c4u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c0692c6;
P_0c0692c6: /* original a002, guest PC 0x0c0692c6 */
if(!s->budget--) { s->failed_pc=0x0c0692c6u; return 0; }
r[2]=read(ram,r[4]+12,4);
goto P_0c0692ce;
P_0c0692c8: /* original 5243, guest PC 0x0c0692c8 */
if(!s->budget--) { s->failed_pc=0x0c0692c8u; return 0; }
r[2]=read(ram,r[4]+12,4);
goto P_0c0692ca;
P_0c0692ca: /* original 5244, guest PC 0x0c0692ca */
if(!s->budget--) { s->failed_pc=0x0c0692cau; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c0692cc;
P_0c0692cc: /* original 5343, guest PC 0x0c0692cc */
if(!s->budget--) { s->failed_pc=0x0c0692ccu; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c0692ce;
P_0c0692ce: /* original 57f2, guest PC 0x0c0692ce */
if(!s->budget--) { s->failed_pc=0x0c0692ceu; return 0; }
r[7]=read(ram,r[15]+8,4);
goto P_0c0692d0;
P_0c0692d0: /* original e004, guest PC 0x0c0692d0 */
if(!s->budget--) { s->failed_pc=0x0c0692d0u; return 0; }
r[0]=0x00000004u;
goto P_0c0692d2;
P_0c0692d2: /* original 33ec, guest PC 0x0c0692d2 */
if(!s->budget--) { s->failed_pc=0x0c0692d2u; return 0; }
r[3]+=r[14];
goto P_0c0692d4;
P_0c0692d4: /* original 37ec, guest PC 0x0c0692d4 */
if(!s->budget--) { s->failed_pc=0x0c0692d4u; return 0; }
r[7]+=r[14];
goto P_0c0692d6;
P_0c0692d6: /* original f038, guest PC 0x0c0692d6 */
if(!s->budget--) { s->failed_pc=0x0c0692d6u; return 0; }
vf3_matrix_load(s,ram,0,r[3]);
goto P_0c0692d8;
P_0c0692d8: /* original f276, guest PC 0x0c0692d8 */
if(!s->budget--) { s->failed_pc=0x0c0692d8u; return 0; }
vf3_matrix_load(s,ram,2,r[7]+r[0]);
goto P_0c0692da;
P_0c0692da: /* original e008, guest PC 0x0c0692da */
if(!s->budget--) { s->failed_pc=0x0c0692dau; return 0; }
r[0]=0x00000008u;
goto P_0c0692dc;
P_0c0692dc: /* original f176, guest PC 0x0c0692dc */
if(!s->budget--) { s->failed_pc=0x0c0692dcu; return 0; }
vf3_matrix_load(s,ram,1,r[7]+r[0]);
goto P_0c0692de;
P_0c0692de: /* original e004, guest PC 0x0c0692de */
if(!s->budget--) { s->failed_pc=0x0c0692deu; return 0; }
r[0]=0x00000004u;
goto P_0c0692e0;
P_0c0692e0: /* original f436, guest PC 0x0c0692e0 */
if(!s->budget--) { s->failed_pc=0x0c0692e0u; return 0; }
vf3_matrix_load(s,ram,4,r[3]+r[0]);
goto P_0c0692e2;
P_0c0692e2: /* original e008, guest PC 0x0c0692e2 */
if(!s->budget--) { s->failed_pc=0x0c0692e2u; return 0; }
r[0]=0x00000008u;
goto P_0c0692e4;
P_0c0692e4: /* original 32ec, guest PC 0x0c0692e4 */
if(!s->budget--) { s->failed_pc=0x0c0692e4u; return 0; }
r[2]+=r[14];
goto P_0c0692e6;
P_0c0692e6: /* original fb36, guest PC 0x0c0692e6 */
if(!s->budget--) { s->failed_pc=0x0c0692e6u; return 0; }
vf3_matrix_load(s,ram,11,r[3]+r[0]);
goto P_0c0692e8;
P_0c0692e8: /* original e004, guest PC 0x0c0692e8 */
if(!s->budget--) { s->failed_pc=0x0c0692e8u; return 0; }
r[0]=0x00000004u;
goto P_0c0692ea;
P_0c0692ea: /* original 6e23, guest PC 0x0c0692ea */
if(!s->budget--) { s->failed_pc=0x0c0692eau; return 0; }
r[14]=r[2];
goto P_0c0692ec;
P_0c0692ec: /* original f9e6, guest PC 0x0c0692ec */
if(!s->budget--) { s->failed_pc=0x0c0692ecu; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c0692ee;
P_0c0692ee: /* original e008, guest PC 0x0c0692ee */
if(!s->budget--) { s->failed_pc=0x0c0692eeu; return 0; }
r[0]=0x00000008u;
goto P_0c0692f0;
P_0c0692f0: /* original fe78, guest PC 0x0c0692f0 */
if(!s->budget--) { s->failed_pc=0x0c0692f0u; return 0; }
vf3_matrix_load(s,ram,14,r[7]);
goto P_0c0692f2;
P_0c0692f2: /* original fb11, guest PC 0x0c0692f2 */
if(!s->budget--) { s->failed_pc=0x0c0692f2u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[1],r[18],'-');
goto P_0c0692f4;
P_0c0692f4: /* original f8e6, guest PC 0x0c0692f4 */
if(!s->budget--) { s->failed_pc=0x0c0692f4u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0692f6;
P_0c0692f6: /* original f421, guest PC 0x0c0692f6 */
if(!s->budget--) { s->failed_pc=0x0c0692f6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'-');
goto P_0c0692f8;
P_0c0692f8: /* original fae8, guest PC 0x0c0692f8 */
if(!s->budget--) { s->failed_pc=0x0c0692f8u; return 0; }
vf3_matrix_load(s,ram,10,r[14]);
goto P_0c0692fa;
P_0c0692fa: /* original f0e1, guest PC 0x0c0692fa */
if(!s->budget--) { s->failed_pc=0x0c0692fau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[14],r[18],'-');
goto P_0c0692fc;
P_0c0692fc: /* original f811, guest PC 0x0c0692fc */
if(!s->budget--) { s->failed_pc=0x0c0692fcu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[1],r[18],'-');
goto P_0c0692fe;
P_0c0692fe: /* original f921, guest PC 0x0c0692fe */
if(!s->budget--) { s->failed_pc=0x0c0692feu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[2],r[18],'-');
goto P_0c069300;
P_0c069300: /* original f5bc, guest PC 0x0c069300 */
if(!s->budget--) { s->failed_pc=0x0c069300u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c069302;
P_0c069302: /* original fae1, guest PC 0x0c069302 */
if(!s->budget--) { s->failed_pc=0x0c069302u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[14],r[18],'-');
goto P_0c069304;
P_0c069304: /* original f74c, guest PC 0x0c069304 */
if(!s->budget--) { s->failed_pc=0x0c069304u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c069306;
P_0c069306: /* original f60c, guest PC 0x0c069306 */
if(!s->budget--) { s->failed_pc=0x0c069306u; return 0; }
vf3_matrix_move(s,6,0);
goto P_0c069308;
P_0c069308: /* original f782, guest PC 0x0c069308 */
if(!s->budget--) { s->failed_pc=0x0c069308u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[8],r[18],'*');
goto P_0c06930a;
P_0c06930a: /* original f692, guest PC 0x0c06930a */
if(!s->budget--) { s->failed_pc=0x0c06930au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[9],r[18],'*');
goto P_0c06930c;
P_0c06930c: /* original f5a2, guest PC 0x0c06930c */
if(!s->budget--) { s->failed_pc=0x0c06930cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[10],r[18],'*');
goto P_0c06930e;
P_0c06930e: /* original fb92, guest PC 0x0c06930e */
if(!s->budget--) { s->failed_pc=0x0c06930eu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[9],r[18],'*');
goto P_0c069310;
P_0c069310: /* original f37c, guest PC 0x0c069310 */
if(!s->budget--) { s->failed_pc=0x0c069310u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c069312;
P_0c069312: /* original f082, guest PC 0x0c069312 */
if(!s->budget--) { s->failed_pc=0x0c069312u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[8],r[18],'*');
goto P_0c069314;
P_0c069314: /* original e004, guest PC 0x0c069314 */
if(!s->budget--) { s->failed_pc=0x0c069314u; return 0; }
r[0]=0x00000004u;
goto P_0c069316;
P_0c069316: /* original f4a2, guest PC 0x0c069316 */
if(!s->budget--) { s->failed_pc=0x0c069316u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[10],r[18],'*');
goto P_0c069318;
P_0c069318: /* original f7bc, guest PC 0x0c069318 */
if(!s->budget--) { s->failed_pc=0x0c069318u; return 0; }
vf3_matrix_move(s,7,11);
goto P_0c06931a;
P_0c06931a: /* original f731, guest PC 0x0c06931a */
if(!s->budget--) { s->failed_pc=0x0c06931au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c06931c;
P_0c06931c: /* original f35c, guest PC 0x0c06931c */
if(!s->budget--) { s->failed_pc=0x0c06931cu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c06931e;
P_0c06931e: /* original f50c, guest PC 0x0c06931e */
if(!s->budget--) { s->failed_pc=0x0c06931eu; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c069320;
P_0c069320: /* original f531, guest PC 0x0c069320 */
if(!s->budget--) { s->failed_pc=0x0c069320u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c069322;
P_0c069322: /* original f36c, guest PC 0x0c069322 */
if(!s->budget--) { s->failed_pc=0x0c069322u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c069324;
P_0c069324: /* original f07c, guest PC 0x0c069324 */
if(!s->budget--) { s->failed_pc=0x0c069324u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c069326;
P_0c069326: /* original f64c, guest PC 0x0c069326 */
if(!s->budget--) { s->failed_pc=0x0c069326u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c069328;
P_0c069328: /* original f631, guest PC 0x0c069328 */
if(!s->budget--) { s->failed_pc=0x0c069328u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c06932a;
P_0c06932a: /* original f252, guest PC 0x0c06932a */
if(!s->budget--) { s->failed_pc=0x0c06932au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'*');
goto P_0c06932c;
P_0c06932c: /* original f54d, guest PC 0x0c06932c */
if(!s->budget--) { s->failed_pc=0x0c06932cu; return 0; }
fr[5]^=0x80000000u;
goto P_0c06932e;
P_0c06932e: /* original f2ee, guest PC 0x0c06932e */
if(!s->budget--) { s->failed_pc=0x0c06932eu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[14],fr[2],r[18]);
goto P_0c069330;
P_0c069330: /* original f06c, guest PC 0x0c069330 */
if(!s->budget--) { s->failed_pc=0x0c069330u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c069332;
P_0c069332: /* original f42c, guest PC 0x0c069332 */
if(!s->budget--) { s->failed_pc=0x0c069332u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c069334;
P_0c069334: /* original f41e, guest PC 0x0c069334 */
if(!s->budget--) { s->failed_pc=0x0c069334u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[1],fr[4],r[18]);
goto P_0c069336;
P_0c069336: /* original f2f8, guest PC 0x0c069336 */
if(!s->budget--) { s->failed_pc=0x0c069336u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c069338;
P_0c069338: /* original f272, guest PC 0x0c069338 */
if(!s->budget--) { s->failed_pc=0x0c069338u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[7],r[18],'*');
goto P_0c06933a;
P_0c06933a: /* original f34c, guest PC 0x0c06933a */
if(!s->budget--) { s->failed_pc=0x0c06933au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c06933c;
P_0c06933c: /* original f42c, guest PC 0x0c06933c */
if(!s->budget--) { s->failed_pc=0x0c06933cu; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c06933e;
P_0c06933e: /* original f431, guest PC 0x0c06933e */
if(!s->budget--) { s->failed_pc=0x0c06933eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c069340;
P_0c069340: /* original f3f6, guest PC 0x0c069340 */
if(!s->budget--) { s->failed_pc=0x0c069340u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c069342;
P_0c069342: /* original e014, guest PC 0x0c069342 */
if(!s->budget--) { s->failed_pc=0x0c069342u; return 0; }
r[0]=0x00000014u;
goto P_0c069344;
P_0c069344: /* original f24c, guest PC 0x0c069344 */
if(!s->budget--) { s->failed_pc=0x0c069344u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c069346;
P_0c069346: /* original f23e, guest PC 0x0c069346 */
if(!s->budget--) { s->failed_pc=0x0c069346u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[3],fr[2],r[18]);
goto P_0c069348;
P_0c069348: /* original f42c, guest PC 0x0c069348 */
if(!s->budget--) { s->failed_pc=0x0c069348u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c06934a;
P_0c06934a: /* original f453, guest PC 0x0c06934a */
if(!s->budget--) { s->failed_pc=0x0c06934au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'/');
goto P_0c06934c;
P_0c06934c: /* original f54a, guest PC 0x0c06934c */
if(!s->budget--) { s->failed_pc=0x0c06934cu; return 0; }
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c06934e;
P_0c06934e: /* original f346, guest PC 0x0c06934e */
if(!s->budget--) { s->failed_pc=0x0c06934eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c069350;
P_0c069350: /* original e018, guest PC 0x0c069350 */
if(!s->budget--) { s->failed_pc=0x0c069350u; return 0; }
r[0]=0x00000018u;
goto P_0c069352;
P_0c069352: /* original e103, guest PC 0x0c069352 */
if(!s->budget--) { s->failed_pc=0x0c069352u; return 0; }
r[1]=0x00000003u;
goto P_0c069354;
P_0c069354: /* original f63a, guest PC 0x0c069354 */
if(!s->budget--) { s->failed_pc=0x0c069354u; return 0; }
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c069356;
P_0c069356: /* original 7f0c, guest PC 0x0c069356 */
if(!s->budget--) { s->failed_pc=0x0c069356u; return 0; }
r[15]+=0x0000000cu;
goto P_0c069358;
P_0c069358: /* original f346, guest PC 0x0c069358 */
if(!s->budget--) { s->failed_pc=0x0c069358u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c06935a;
P_0c06935a: /* original e004, guest PC 0x0c06935a */
if(!s->budget--) { s->failed_pc=0x0c06935au; return 0; }
r[0]=0x00000004u;
goto P_0c06935c;
P_0c06935c: /* original f637, guest PC 0x0c06935c */
if(!s->budget--) { s->failed_pc=0x0c06935cu; return 0; }
vf3_matrix_store(s,ram,3,r[6]+r[0]);
goto P_0c06935e;
P_0c06935e: /* original e01c, guest PC 0x0c06935e */
if(!s->budget--) { s->failed_pc=0x0c06935eu; return 0; }
r[0]=0x0000001cu;
goto P_0c069360;
P_0c069360: /* original f346, guest PC 0x0c069360 */
if(!s->budget--) { s->failed_pc=0x0c069360u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c069362;
P_0c069362: /* original e008, guest PC 0x0c069362 */
if(!s->budget--) { s->failed_pc=0x0c069362u; return 0; }
r[0]=0x00000008u;
goto P_0c069364;
P_0c069364: /* original f637, guest PC 0x0c069364 */
if(!s->budget--) { s->failed_pc=0x0c069364u; return 0; }
vf3_matrix_store(s,ram,3,r[6]+r[0]);
goto P_0c069366;
P_0c069366: /* original 6442, guest PC 0x0c069366 */
if(!s->budget--) { s->failed_pc=0x0c069366u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c069368;
P_0c069368: /* original d207, guest PC 0x0c069368 */
if(!s->budget--) { s->failed_pc=0x0c069368u; return 0; }
r[2]=read(ram,0x0c069388u,4);
goto P_0c06936a;
P_0c06936a: /* original 6343, guest PC 0x0c06936a */
if(!s->budget--) { s->failed_pc=0x0c06936au; return 0; }
r[3]=r[4];
goto P_0c06936c;
P_0c06936c: /* original 4300, guest PC 0x0c06936c */
if(!s->budget--) { s->failed_pc=0x0c06936cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c06936e;
P_0c06936e: /* original 2149, guest PC 0x0c06936e */
if(!s->budget--) { s->failed_pc=0x0c06936eu; return 0; }
r[1]&=r[4];
goto P_0c069370;
P_0c069370: /* original fef9, guest PC 0x0c069370 */
if(!s->budget--) { s->failed_pc=0x0c069370u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c069372;
P_0c069372: /* original 2329, guest PC 0x0c069372 */
if(!s->budget--) { s->failed_pc=0x0c069372u; return 0; }
r[3]&=r[2];
goto P_0c069374;
P_0c069374: /* original 6433, guest PC 0x0c069374 */
if(!s->budget--) { s->failed_pc=0x0c069374u; return 0; }
r[4]=r[3];
goto P_0c069376;
P_0c069376: /* original 241b, guest PC 0x0c069376 */
if(!s->budget--) { s->failed_pc=0x0c069376u; return 0; }
r[4]|=r[1];
goto P_0c069378;
P_0c069378: /* original 6043, guest PC 0x0c069378 */
if(!s->budget--) { s->failed_pc=0x0c069378u; return 0; }
r[0]=r[4];
goto P_0c06937a;
P_0c06937a: /* original 000b, guest PC 0x0c06937a */
if(!s->budget--) { s->failed_pc=0x0c06937au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06937c: /* original 6ef6, guest PC 0x0c06937c */
if(!s->budget--) { s->failed_pc=0x0c06937cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06937eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06937eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
