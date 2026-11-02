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
int vf3_away_batch209_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c069624u: goto P_0c069624;
case 0x0c069626u: goto P_0c069626;
case 0x0c069628u: goto P_0c069628;
case 0x0c06962au: goto P_0c06962a;
case 0x0c06962cu: goto P_0c06962c;
case 0x0c06962eu: goto P_0c06962e;
case 0x0c069630u: goto P_0c069630;
case 0x0c069632u: goto P_0c069632;
case 0x0c069634u: goto P_0c069634;
case 0x0c069636u: goto P_0c069636;
case 0x0c069638u: goto P_0c069638;
case 0x0c06963au: goto P_0c06963a;
case 0x0c06963cu: goto P_0c06963c;
case 0x0c06963eu: goto P_0c06963e;
case 0x0c069640u: goto P_0c069640;
case 0x0c069642u: goto P_0c069642;
case 0x0c069644u: goto P_0c069644;
case 0x0c069646u: goto P_0c069646;
case 0x0c069648u: goto P_0c069648;
case 0x0c06964au: goto P_0c06964a;
case 0x0c06964cu: goto P_0c06964c;
case 0x0c06964eu: goto P_0c06964e;
case 0x0c069650u: goto P_0c069650;
case 0x0c069652u: goto P_0c069652;
case 0x0c069654u: goto P_0c069654;
case 0x0c069656u: goto P_0c069656;
case 0x0c069658u: goto P_0c069658;
case 0x0c06965au: goto P_0c06965a;
case 0x0c06965cu: goto P_0c06965c;
case 0x0c06965eu: goto P_0c06965e;
case 0x0c069660u: goto P_0c069660;
case 0x0c069662u: goto P_0c069662;
case 0x0c069664u: goto P_0c069664;
case 0x0c069666u: goto P_0c069666;
case 0x0c069668u: goto P_0c069668;
case 0x0c06966au: goto P_0c06966a;
case 0x0c06966cu: goto P_0c06966c;
case 0x0c06966eu: goto P_0c06966e;
case 0x0c069670u: goto P_0c069670;
case 0x0c069672u: goto P_0c069672;
case 0x0c069674u: goto P_0c069674;
case 0x0c069676u: goto P_0c069676;
case 0x0c069678u: goto P_0c069678;
case 0x0c06967au: goto P_0c06967a;
case 0x0c06967cu: goto P_0c06967c;
case 0x0c06967eu: goto P_0c06967e;
case 0x0c069680u: goto P_0c069680;
case 0x0c069682u: goto P_0c069682;
case 0x0c069684u: goto P_0c069684;
case 0x0c069686u: goto P_0c069686;
case 0x0c069688u: goto P_0c069688;
case 0x0c06968au: goto P_0c06968a;
case 0x0c06968cu: goto P_0c06968c;
case 0x0c06968eu: goto P_0c06968e;
case 0x0c069690u: goto P_0c069690;
case 0x0c069692u: goto P_0c069692;
case 0x0c069694u: goto P_0c069694;
case 0x0c069696u: goto P_0c069696;
case 0x0c069698u: goto P_0c069698;
case 0x0c06969au: goto P_0c06969a;
case 0x0c06969cu: goto P_0c06969c;
default: return vf3_matrix_family(target,s,ram);
}
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
P_0c069624: /* original f38d, guest PC 0x0c069624 */
if(!s->budget--) { s->failed_pc=0x0c069624u; return 0; }
fr[3]=0;
goto P_0c069626;
P_0c069626: /* original f534, guest PC 0x0c069626 */
if(!s->budget--) { s->failed_pc=0x0c069626u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])==as_float(fr[3]))!=0);
goto P_0c069628;
P_0c069628: /* original 8b03, guest PC 0x0c069628 */
if(!s->budget--) { s->failed_pc=0x0c069628u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069632; }
goto P_0c06962a;
P_0c06962a: /* original f434, guest PC 0x0c06962a */
if(!s->budget--) { s->failed_pc=0x0c06962au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c06962c;
P_0c06962c: /* original 8b01, guest PC 0x0c06962c */
if(!s->budget--) { s->failed_pc=0x0c06962cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069632; }
goto P_0c06962e;
P_0c06962e: /* original 000b, guest PC 0x0c06962e */
if(!s->budget--) { s->failed_pc=0x0c06962eu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c069630: /* original e000, guest PC 0x0c069630 */
if(!s->budget--) { s->failed_pc=0x0c069630u; return 0; }
r[0]=0x00000000u;
goto P_0c069632;
P_0c069632: /* original f38d, guest PC 0x0c069632 */
if(!s->budget--) { s->failed_pc=0x0c069632u; return 0; }
fr[3]=0;
goto P_0c069634;
P_0c069634: /* original f355, guest PC 0x0c069634 */
if(!s->budget--) { s->failed_pc=0x0c069634u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c069636;
P_0c069636: /* original 8f03, guest PC 0x0c069636 */
if(!s->budget--) { s->failed_pc=0x0c069636u; return 0; }
cond=r[17]&1u;
fr[3]=0;
if(!cond) { goto P_0c069640; }
goto P_0c06963a;
P_0c069638: /* original f38d, guest PC 0x0c069638 */
if(!s->budget--) { s->failed_pc=0x0c069638u; return 0; }
fr[3]=0;
goto P_0c06963a;
P_0c06963a: /* original f65c, guest PC 0x0c06963a */
if(!s->budget--) { s->failed_pc=0x0c06963au; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c06963c;
P_0c06963c: /* original a001, guest PC 0x0c06963c */
if(!s->budget--) { s->failed_pc=0x0c06963cu; return 0; }
fr[6]^=0x80000000u;
goto P_0c069642;
P_0c06963e: /* original f64d, guest PC 0x0c06963e */
if(!s->budget--) { s->failed_pc=0x0c06963eu; return 0; }
fr[6]^=0x80000000u;
goto P_0c069640;
P_0c069640: /* original f65c, guest PC 0x0c069640 */
if(!s->budget--) { s->failed_pc=0x0c069640u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c069642;
P_0c069642: /* original f345, guest PC 0x0c069642 */
if(!s->budget--) { s->failed_pc=0x0c069642u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c069644;
P_0c069644: /* original 8b02, guest PC 0x0c069644 */
if(!s->budget--) { s->failed_pc=0x0c069644u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06964c; }
goto P_0c069646;
P_0c069646: /* original f74c, guest PC 0x0c069646 */
if(!s->budget--) { s->failed_pc=0x0c069646u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c069648;
P_0c069648: /* original a001, guest PC 0x0c069648 */
if(!s->budget--) { s->failed_pc=0x0c069648u; return 0; }
fr[7]^=0x80000000u;
goto P_0c06964e;
P_0c06964a: /* original f74d, guest PC 0x0c06964a */
if(!s->budget--) { s->failed_pc=0x0c06964au; return 0; }
fr[7]^=0x80000000u;
goto P_0c06964c;
P_0c06964c: /* original f74c, guest PC 0x0c06964c */
if(!s->budget--) { s->failed_pc=0x0c06964cu; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c06964e;
P_0c06964e: /* original f675, guest PC 0x0c06964e */
if(!s->budget--) { s->failed_pc=0x0c06964eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[7]))!=0);
goto P_0c069650;
P_0c069650: /* original 8b02, guest PC 0x0c069650 */
if(!s->budget--) { s->failed_pc=0x0c069650u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069658; }
goto P_0c069652;
P_0c069652: /* original f87c, guest PC 0x0c069652 */
if(!s->budget--) { s->failed_pc=0x0c069652u; return 0; }
vf3_matrix_move(s,8,7);
goto P_0c069654;
P_0c069654: /* original a002, guest PC 0x0c069654 */
if(!s->budget--) { s->failed_pc=0x0c069654u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'/');
goto P_0c06965c;
P_0c069656: /* original f863, guest PC 0x0c069656 */
if(!s->budget--) { s->failed_pc=0x0c069656u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'/');
goto P_0c069658;
P_0c069658: /* original f86c, guest PC 0x0c069658 */
if(!s->budget--) { s->failed_pc=0x0c069658u; return 0; }
vf3_matrix_move(s,8,6);
goto P_0c06965a;
P_0c06965a: /* original f873, guest PC 0x0c06965a */
if(!s->budget--) { s->failed_pc=0x0c06965au; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[7],r[18],'/');
goto P_0c06965c;
P_0c06965c: /* original c711, guest PC 0x0c06965c */
if(!s->budget--) { s->failed_pc=0x0c06965cu; return 0; }
r[0]=code_base|0x000696a4u;
goto P_0c06965e;
P_0c06965e: /* original f28c, guest PC 0x0c06965e */
if(!s->budget--) { s->failed_pc=0x0c06965eu; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c069660;
P_0c069660: /* original f308, guest PC 0x0c069660 */
if(!s->budget--) { s->failed_pc=0x0c069660u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c069662;
P_0c069662: /* original d011, guest PC 0x0c069662 */
if(!s->budget--) { s->failed_pc=0x0c069662u; return 0; }
r[0]=read(ram,0x0c0696a8u,4);
goto P_0c069664;
P_0c069664: /* original f232, guest PC 0x0c069664 */
if(!s->budget--) { s->failed_pc=0x0c069664u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c069666;
P_0c069666: /* original f23d, guest PC 0x0c069666 */
if(!s->budget--) { s->failed_pc=0x0c069666u; return 0; }
r[53]=truncate_float(fr[2]);
goto P_0c069668;
P_0c069668: /* original 045a, guest PC 0x0c069668 */
if(!s->budget--) { s->failed_pc=0x0c069668u; return 0; }
r[4]=r[53];
goto P_0c06966a;
P_0c06966a: /* original 4400, guest PC 0x0c06966a */
if(!s->budget--) { s->failed_pc=0x0c06966au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06966c;
P_0c06966c: /* original f765, guest PC 0x0c06966c */
if(!s->budget--) { s->failed_pc=0x0c06966cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[6]))!=0);
goto P_0c06966e;
P_0c06966e: /* original 8f03, guest PC 0x0c06966e */
if(!s->budget--) { s->failed_pc=0x0c06966eu; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
if(!cond) { goto P_0c069678; }
goto P_0c069672;
P_0c069670: /* original 044d, guest PC 0x0c069670 */
if(!s->budget--) { s->failed_pc=0x0c069670u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c069672;
P_0c069672: /* original 9214, guest PC 0x0c069672 */
if(!s->budget--) { s->failed_pc=0x0c069672u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06969eu,2);
goto P_0c069674;
P_0c069674: /* original 3248, guest PC 0x0c069674 */
if(!s->budget--) { s->failed_pc=0x0c069674u; return 0; }
r[2]-=r[4];
goto P_0c069676;
P_0c069676: /* original 6423, guest PC 0x0c069676 */
if(!s->budget--) { s->failed_pc=0x0c069676u; return 0; }
r[4]=r[2];
goto P_0c069678;
P_0c069678: /* original f38d, guest PC 0x0c069678 */
if(!s->budget--) { s->failed_pc=0x0c069678u; return 0; }
fr[3]=0;
goto P_0c06967a;
P_0c06967a: /* original f355, guest PC 0x0c06967a */
if(!s->budget--) { s->failed_pc=0x0c06967au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c06967c;
P_0c06967c: /* original 8904, guest PC 0x0c06967c */
if(!s->budget--) { s->failed_pc=0x0c06967cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069688; }
goto P_0c06967e;
P_0c06967e: /* original f38d, guest PC 0x0c06967e */
if(!s->budget--) { s->failed_pc=0x0c06967eu; return 0; }
fr[3]=0;
goto P_0c069680;
P_0c069680: /* original f345, guest PC 0x0c069680 */
if(!s->budget--) { s->failed_pc=0x0c069680u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c069682;
P_0c069682: /* original 8b09, guest PC 0x0c069682 */
if(!s->budget--) { s->failed_pc=0x0c069682u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069698; }
goto P_0c069684;
P_0c069684: /* original a008, guest PC 0x0c069684 */
if(!s->budget--) { s->failed_pc=0x0c069684u; return 0; }
r[4]=0u-r[4];
goto P_0c069698;
P_0c069686: /* original 644b, guest PC 0x0c069686 */
if(!s->budget--) { s->failed_pc=0x0c069686u; return 0; }
r[4]=0u-r[4];
goto P_0c069688;
P_0c069688: /* original f345, guest PC 0x0c069688 */
if(!s->budget--) { s->failed_pc=0x0c069688u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c06968a;
P_0c06968a: /* original 8903, guest PC 0x0c06968a */
if(!s->budget--) { s->failed_pc=0x0c06968au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069694; }
goto P_0c06968c;
P_0c06968c: /* original d207, guest PC 0x0c06968c */
if(!s->budget--) { s->failed_pc=0x0c06968cu; return 0; }
r[2]=read(ram,0x0c0696acu,4);
goto P_0c06968e;
P_0c06968e: /* original 3248, guest PC 0x0c06968e */
if(!s->budget--) { s->failed_pc=0x0c06968eu; return 0; }
r[2]-=r[4];
goto P_0c069690;
P_0c069690: /* original a002, guest PC 0x0c069690 */
if(!s->budget--) { s->failed_pc=0x0c069690u; return 0; }
r[4]=r[2];
goto P_0c069698;
P_0c069692: /* original 6423, guest PC 0x0c069692 */
if(!s->budget--) { s->failed_pc=0x0c069692u; return 0; }
r[4]=r[2];
goto P_0c069694;
P_0c069694: /* original 9104, guest PC 0x0c069694 */
if(!s->budget--) { s->failed_pc=0x0c069694u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0696a0u,2);
goto P_0c069696;
P_0c069696: /* original 341c, guest PC 0x0c069696 */
if(!s->budget--) { s->failed_pc=0x0c069696u; return 0; }
r[4]+=r[1];
goto P_0c069698;
P_0c069698: /* original 6043, guest PC 0x0c069698 */
if(!s->budget--) { s->failed_pc=0x0c069698u; return 0; }
r[0]=r[4];
goto P_0c06969a;
P_0c06969a: /* original 000b, guest PC 0x0c06969a */
if(!s->budget--) { s->failed_pc=0x0c06969au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06969c: /* original 0009, guest PC 0x0c06969c */
if(!s->budget--) { s->failed_pc=0x0c06969cu; return 0; }
if(!vf3_matrix_family(0x0c06969eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06969eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
