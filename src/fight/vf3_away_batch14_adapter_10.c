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
int vf3_away_batch14_adapter_10(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0871e6u: goto P_0c0871e6;
case 0x0c0871e8u: goto P_0c0871e8;
case 0x0c0871eau: goto P_0c0871ea;
case 0x0c0871ecu: goto P_0c0871ec;
case 0x0c0871eeu: goto P_0c0871ee;
case 0x0c0871f0u: goto P_0c0871f0;
case 0x0c0871f2u: goto P_0c0871f2;
case 0x0c0871f4u: goto P_0c0871f4;
case 0x0c0871f6u: goto P_0c0871f6;
case 0x0c0871f8u: goto P_0c0871f8;
case 0x0c0871fau: goto P_0c0871fa;
case 0x0c0871fcu: goto P_0c0871fc;
case 0x0c0871feu: goto P_0c0871fe;
case 0x0c087200u: goto P_0c087200;
case 0x0c087202u: goto P_0c087202;
case 0x0c087204u: goto P_0c087204;
case 0x0c087206u: goto P_0c087206;
case 0x0c087208u: goto P_0c087208;
case 0x0c08720au: goto P_0c08720a;
case 0x0c08720cu: goto P_0c08720c;
case 0x0c08720eu: goto P_0c08720e;
case 0x0c087210u: goto P_0c087210;
case 0x0c087212u: goto P_0c087212;
case 0x0c087214u: goto P_0c087214;
case 0x0c087216u: goto P_0c087216;
case 0x0c087218u: goto P_0c087218;
case 0x0c08721au: goto P_0c08721a;
case 0x0c08721cu: goto P_0c08721c;
case 0x0c08721eu: goto P_0c08721e;
case 0x0c087220u: goto P_0c087220;
case 0x0c087222u: goto P_0c087222;
case 0x0c087224u: goto P_0c087224;
case 0x0c087226u: goto P_0c087226;
case 0x0c087228u: goto P_0c087228;
case 0x0c08722au: goto P_0c08722a;
case 0x0c08722cu: goto P_0c08722c;
case 0x0c08722eu: goto P_0c08722e;
case 0x0c087230u: goto P_0c087230;
case 0x0c087232u: goto P_0c087232;
case 0x0c087234u: goto P_0c087234;
case 0x0c087236u: goto P_0c087236;
case 0x0c087238u: goto P_0c087238;
case 0x0c08723au: goto P_0c08723a;
case 0x0c08723cu: goto P_0c08723c;
case 0x0c08723eu: goto P_0c08723e;
case 0x0c087240u: goto P_0c087240;
case 0x0c087242u: goto P_0c087242;
case 0x0c087244u: goto P_0c087244;
case 0x0c087246u: goto P_0c087246;
case 0x0c087248u: goto P_0c087248;
case 0x0c08724au: goto P_0c08724a;
case 0x0c08724cu: goto P_0c08724c;
case 0x0c08724eu: goto P_0c08724e;
case 0x0c087250u: goto P_0c087250;
case 0x0c087252u: goto P_0c087252;
case 0x0c087254u: goto P_0c087254;
case 0x0c087256u: goto P_0c087256;
case 0x0c087258u: goto P_0c087258;
case 0x0c08725au: goto P_0c08725a;
case 0x0c08725cu: goto P_0c08725c;
case 0x0c08725eu: goto P_0c08725e;
case 0x0c087260u: goto P_0c087260;
case 0x0c087262u: goto P_0c087262;
case 0x0c087264u: goto P_0c087264;
case 0x0c087266u: goto P_0c087266;
case 0x0c087268u: goto P_0c087268;
case 0x0c08726au: goto P_0c08726a;
case 0x0c08726cu: goto P_0c08726c;
case 0x0c08726eu: goto P_0c08726e;
case 0x0c087270u: goto P_0c087270;
case 0x0c087272u: goto P_0c087272;
case 0x0c087274u: goto P_0c087274;
case 0x0c087276u: goto P_0c087276;
case 0x0c087278u: goto P_0c087278;
case 0x0c08727au: goto P_0c08727a;
case 0x0c08727cu: goto P_0c08727c;
case 0x0c0872b4u: goto P_0c0872b4;
case 0x0c0872b6u: goto P_0c0872b6;
case 0x0c0872b8u: goto P_0c0872b8;
case 0x0c0872bau: goto P_0c0872ba;
case 0x0c0872bcu: goto P_0c0872bc;
case 0x0c0872beu: goto P_0c0872be;
case 0x0c0872c0u: goto P_0c0872c0;
case 0x0c0872c2u: goto P_0c0872c2;
case 0x0c0872c4u: goto P_0c0872c4;
case 0x0c0872c6u: goto P_0c0872c6;
case 0x0c0872c8u: goto P_0c0872c8;
case 0x0c0872cau: goto P_0c0872ca;
case 0x0c0872ccu: goto P_0c0872cc;
case 0x0c0872ceu: goto P_0c0872ce;
case 0x0c0872d0u: goto P_0c0872d0;
case 0x0c0872d2u: goto P_0c0872d2;
case 0x0c0872d4u: goto P_0c0872d4;
case 0x0c0872d6u: goto P_0c0872d6;
case 0x0c0872d8u: goto P_0c0872d8;
case 0x0c0872dau: goto P_0c0872da;
case 0x0c0872dcu: goto P_0c0872dc;
case 0x0c0872deu: goto P_0c0872de;
case 0x0c0872e0u: goto P_0c0872e0;
case 0x0c0872e2u: goto P_0c0872e2;
case 0x0c0872e4u: goto P_0c0872e4;
case 0x0c0872e6u: goto P_0c0872e6;
case 0x0c0872e8u: goto P_0c0872e8;
case 0x0c0872eau: goto P_0c0872ea;
case 0x0c0872ecu: goto P_0c0872ec;
case 0x0c0872eeu: goto P_0c0872ee;
case 0x0c0872f0u: goto P_0c0872f0;
case 0x0c0872f2u: goto P_0c0872f2;
case 0x0c0872f4u: goto P_0c0872f4;
case 0x0c0872f6u: goto P_0c0872f6;
case 0x0c0872f8u: goto P_0c0872f8;
case 0x0c0872fau: goto P_0c0872fa;
case 0x0c0872fcu: goto P_0c0872fc;
case 0x0c0872feu: goto P_0c0872fe;
case 0x0c087300u: goto P_0c087300;
case 0x0c087302u: goto P_0c087302;
case 0x0c087304u: goto P_0c087304;
case 0x0c087306u: goto P_0c087306;
case 0x0c087308u: goto P_0c087308;
case 0x0c08730au: goto P_0c08730a;
case 0x0c08730cu: goto P_0c08730c;
case 0x0c08730eu: goto P_0c08730e;
case 0x0c087310u: goto P_0c087310;
case 0x0c087312u: goto P_0c087312;
case 0x0c087314u: goto P_0c087314;
case 0x0c087316u: goto P_0c087316;
case 0x0c087318u: goto P_0c087318;
case 0x0c08731au: goto P_0c08731a;
case 0x0c08731cu: goto P_0c08731c;
case 0x0c08731eu: goto P_0c08731e;
case 0x0c087320u: goto P_0c087320;
case 0x0c087322u: goto P_0c087322;
case 0x0c087324u: goto P_0c087324;
case 0x0c087326u: goto P_0c087326;
case 0x0c087328u: goto P_0c087328;
case 0x0c08732au: goto P_0c08732a;
case 0x0c08732cu: goto P_0c08732c;
case 0x0c08732eu: goto P_0c08732e;
case 0x0c087330u: goto P_0c087330;
case 0x0c087332u: goto P_0c087332;
case 0x0c087334u: goto P_0c087334;
case 0x0c087336u: goto P_0c087336;
case 0x0c087338u: goto P_0c087338;
case 0x0c08733au: goto P_0c08733a;
case 0x0c08733cu: goto P_0c08733c;
case 0x0c08733eu: goto P_0c08733e;
case 0x0c087340u: goto P_0c087340;
case 0x0c087342u: goto P_0c087342;
case 0x0c087344u: goto P_0c087344;
case 0x0c087346u: goto P_0c087346;
case 0x0c087348u: goto P_0c087348;
case 0x0c087542u: goto P_0c087542;
case 0x0c087544u: goto P_0c087544;
case 0x0c087546u: goto P_0c087546;
case 0x0c087548u: goto P_0c087548;
case 0x0c08754au: goto P_0c08754a;
case 0x0c08754cu: goto P_0c08754c;
case 0x0c08754eu: goto P_0c08754e;
case 0x0c087550u: goto P_0c087550;
case 0x0c087552u: goto P_0c087552;
case 0x0c087554u: goto P_0c087554;
case 0x0c087556u: goto P_0c087556;
case 0x0c087558u: goto P_0c087558;
case 0x0c08755au: goto P_0c08755a;
case 0x0c08755cu: goto P_0c08755c;
case 0x0c08755eu: goto P_0c08755e;
case 0x0c087560u: goto P_0c087560;
case 0x0c087562u: goto P_0c087562;
case 0x0c087564u: goto P_0c087564;
case 0x0c087566u: goto P_0c087566;
case 0x0c087568u: goto P_0c087568;
case 0x0c08756au: goto P_0c08756a;
case 0x0c08756cu: goto P_0c08756c;
case 0x0c08756eu: goto P_0c08756e;
case 0x0c087570u: goto P_0c087570;
case 0x0c087572u: goto P_0c087572;
case 0x0c087574u: goto P_0c087574;
case 0x0c087576u: goto P_0c087576;
case 0x0c087578u: goto P_0c087578;
case 0x0c08757au: goto P_0c08757a;
case 0x0c08757cu: goto P_0c08757c;
case 0x0c08757eu: goto P_0c08757e;
case 0x0c087580u: goto P_0c087580;
case 0x0c087582u: goto P_0c087582;
case 0x0c087584u: goto P_0c087584;
case 0x0c087586u: goto P_0c087586;
case 0x0c087588u: goto P_0c087588;
case 0x0c08758au: goto P_0c08758a;
case 0x0c08758cu: goto P_0c08758c;
case 0x0c08758eu: goto P_0c08758e;
case 0x0c087590u: goto P_0c087590;
case 0x0c087592u: goto P_0c087592;
case 0x0c087594u: goto P_0c087594;
case 0x0c087596u: goto P_0c087596;
case 0x0c087598u: goto P_0c087598;
case 0x0c08759au: goto P_0c08759a;
case 0x0c08759cu: goto P_0c08759c;
case 0x0c08759eu: goto P_0c08759e;
case 0x0c0875a0u: goto P_0c0875a0;
case 0x0c0875a2u: goto P_0c0875a2;
case 0x0c0875a4u: goto P_0c0875a4;
case 0x0c0875a6u: goto P_0c0875a6;
case 0x0c0875a8u: goto P_0c0875a8;
case 0x0c0875aau: goto P_0c0875aa;
case 0x0c0875acu: goto P_0c0875ac;
case 0x0c0875aeu: goto P_0c0875ae;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0871e6: /* original 2fe6, guest PC 0x0c0871e6 */
if(!s->budget--) { s->failed_pc=0x0c0871e6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0871e8;
P_0c0871e8: /* original 2fd6, guest PC 0x0c0871e8 */
if(!s->budget--) { s->failed_pc=0x0c0871e8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0871ea;
P_0c0871ea: /* original 2fc6, guest PC 0x0c0871ea */
if(!s->budget--) { s->failed_pc=0x0c0871eau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0871ec;
P_0c0871ec: /* original d126, guest PC 0x0c0871ec */
if(!s->budget--) { s->failed_pc=0x0c0871ecu; return 0; }
r[1]=read(ram,0x0c087288u,4);
goto P_0c0871ee;
P_0c0871ee: /* original 4f22, guest PC 0x0c0871ee */
if(!s->budget--) { s->failed_pc=0x0c0871eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0871f0;
P_0c0871f0: /* original 6212, guest PC 0x0c0871f0 */
if(!s->budget--) { s->failed_pc=0x0c0871f0u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0871f2;
P_0c0871f2: /* original d324, guest PC 0x0c0871f2 */
if(!s->budget--) { s->failed_pc=0x0c0871f2u; return 0; }
r[3]=read(ram,0x0c087284u,4);
goto P_0c0871f4;
P_0c0871f4: /* original 7ff8, guest PC 0x0c0871f4 */
if(!s->budget--) { s->failed_pc=0x0c0871f4u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0871f6;
P_0c0871f6: /* original 2238, guest PC 0x0c0871f6 */
if(!s->budget--) { s->failed_pc=0x0c0871f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0871f8;
P_0c0871f8: /* original 8d02, guest PC 0x0c0871f8 */
if(!s->budget--) { s->failed_pc=0x0c0871f8u; return 0; }
cond=r[17]&1u;
r[12]=r[4];
if(cond) { goto P_0c087200; }
goto P_0c0871fc;
P_0c0871fa: /* original 6c43, guest PC 0x0c0871fa */
if(!s->budget--) { s->failed_pc=0x0c0871fau; return 0; }
r[12]=r[4];
goto P_0c0871fc;
P_0c0871fc: /* original a09f, guest PC 0x0c0871fc */
if(!s->budget--) { s->failed_pc=0x0c0871fcu; return 0; }
goto P_0c08733e;
P_0c0871fe: /* original 0009, guest PC 0x0c0871fe */
if(!s->budget--) { s->failed_pc=0x0c0871feu; return 0; }
goto P_0c087200;
P_0c087200: /* original dd27, guest PC 0x0c087200 */
if(!s->budget--) { s->failed_pc=0x0c087200u; return 0; }
r[13]=read(ram,0x0c0872a0u,4);
goto P_0c087202;
P_0c087202: /* original d328, guest PC 0x0c087202 */
if(!s->budget--) { s->failed_pc=0x0c087202u; return 0; }
r[3]=read(ram,0x0c0872a4u,4);
goto P_0c087204;
P_0c087204: /* original 62d2, guest PC 0x0c087204 */
if(!s->budget--) { s->failed_pc=0x0c087204u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c087206;
P_0c087206: /* original 2238, guest PC 0x0c087206 */
if(!s->budget--) { s->failed_pc=0x0c087206u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c087208;
P_0c087208: /* original 8901, guest PC 0x0c087208 */
if(!s->budget--) { s->failed_pc=0x0c087208u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08720e; }
goto P_0c08720a;
P_0c08720a: /* original a098, guest PC 0x0c08720a */
if(!s->budget--) { s->failed_pc=0x0c08720au; return 0; }
goto P_0c08733e;
P_0c08720c: /* original 0009, guest PC 0x0c08720c */
if(!s->budget--) { s->failed_pc=0x0c08720cu; return 0; }
goto P_0c08720e;
P_0c08720e: /* original 9e36, guest PC 0x0c08720e */
if(!s->budget--) { s->failed_pc=0x0c08720eu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08727eu,2);
goto P_0c087210;
P_0c087210: /* original 3ecc, guest PC 0x0c087210 */
if(!s->budget--) { s->failed_pc=0x0c087210u; return 0; }
r[14]+=r[12];
goto P_0c087212;
P_0c087212: /* original bdf6, guest PC 0x0c087212 */
if(!s->budget--) { s->failed_pc=0x0c087212u; return 0; }
target=code_base|0x0c086e02u; r[16]=code_base|0x0c087216u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087216u) { target=s->pc; goto dispatch; }
goto P_0c087216;
P_0c087214: /* original 64c3, guest PC 0x0c087214 */
if(!s->budget--) { s->failed_pc=0x0c087214u; return 0; }
r[4]=r[12];
goto P_0c087216;
P_0c087216: /* original 65f3, guest PC 0x0c087216 */
if(!s->budget--) { s->failed_pc=0x0c087216u; return 0; }
r[5]=r[15];
goto P_0c087218;
P_0c087218: /* original 7504, guest PC 0x0c087218 */
if(!s->budget--) { s->failed_pc=0x0c087218u; return 0; }
r[5]+=0x00000004u;
goto P_0c08721a;
P_0c08721a: /* original bde3, guest PC 0x0c08721a */
if(!s->budget--) { s->failed_pc=0x0c08721au; return 0; }
target=code_base|0x0c086de4u; r[16]=code_base|0x0c08721eu;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08721eu) { target=s->pc; goto dispatch; }
goto P_0c08721e;
P_0c08721c: /* original 64f3, guest PC 0x0c08721c */
if(!s->budget--) { s->failed_pc=0x0c08721cu; return 0; }
r[4]=r[15];
goto P_0c08721e;
P_0c08721e: /* original 66f2, guest PC 0x0c08721e */
if(!s->budget--) { s->failed_pc=0x0c08721eu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c087220;
P_0c087220: /* original 65e3, guest PC 0x0c087220 */
if(!s->budget--) { s->failed_pc=0x0c087220u; return 0; }
r[5]=r[14];
goto P_0c087222;
P_0c087222: /* original 57f1, guest PC 0x0c087222 */
if(!s->budget--) { s->failed_pc=0x0c087222u; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c087224;
P_0c087224: /* original bdc5, guest PC 0x0c087224 */
if(!s->budget--) { s->failed_pc=0x0c087224u; return 0; }
target=code_base|0x0c086db2u; r[16]=code_base|0x0c087228u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087228u) { target=s->pc; goto dispatch; }
goto P_0c087228;
P_0c087226: /* original 64c3, guest PC 0x0c087226 */
if(!s->budget--) { s->failed_pc=0x0c087226u; return 0; }
r[4]=r[12];
goto P_0c087228;
P_0c087228: /* original 65e3, guest PC 0x0c087228 */
if(!s->budget--) { s->failed_pc=0x0c087228u; return 0; }
r[5]=r[14];
goto P_0c08722a;
P_0c08722a: /* original bea9, guest PC 0x0c08722a */
if(!s->budget--) { s->failed_pc=0x0c08722au; return 0; }
target=code_base|0x0c086f80u; r[16]=code_base|0x0c08722eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08722eu) { target=s->pc; goto dispatch; }
goto P_0c08722e;
P_0c08722c: /* original 64c3, guest PC 0x0c08722c */
if(!s->budget--) { s->failed_pc=0x0c08722cu; return 0; }
r[4]=r[12];
goto P_0c08722e;
P_0c08722e: /* original d31e, guest PC 0x0c08722e */
if(!s->budget--) { s->failed_pc=0x0c08722eu; return 0; }
r[3]=read(ram,0x0c0872a8u,4);
goto P_0c087230;
P_0c087230: /* original 5cd1, guest PC 0x0c087230 */
if(!s->budget--) { s->failed_pc=0x0c087230u; return 0; }
r[12]=read(ram,r[13]+4,4);
goto P_0c087232;
P_0c087232: /* original 23c8, guest PC 0x0c087232 */
if(!s->budget--) { s->failed_pc=0x0c087232u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c087234;
P_0c087234: /* original 8910, guest PC 0x0c087234 */
if(!s->budget--) { s->failed_pc=0x0c087234u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087258; }
goto P_0c087236;
P_0c087236: /* original d11d, guest PC 0x0c087236 */
if(!s->budget--) { s->failed_pc=0x0c087236u; return 0; }
r[1]=read(ram,0x0c0872acu,4);
goto P_0c087238;
P_0c087238: /* original 21c8, guest PC 0x0c087238 */
if(!s->budget--) { s->failed_pc=0x0c087238u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[12])==0)!=0);
goto P_0c08723a;
P_0c08723a: /* original 8901, guest PC 0x0c08723a */
if(!s->budget--) { s->failed_pc=0x0c08723au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087240; }
goto P_0c08723c;
P_0c08723c: /* original be1c, guest PC 0x0c08723c */
if(!s->budget--) { s->failed_pc=0x0c08723cu; return 0; }
target=code_base|0x0c086e78u; r[16]=code_base|0x0c087240u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087240u) { target=s->pc; goto dispatch; }
goto P_0c087240;
P_0c08723e: /* original 64e3, guest PC 0x0c08723e */
if(!s->budget--) { s->failed_pc=0x0c08723eu; return 0; }
r[4]=r[14];
goto P_0c087240;
P_0c087240: /* original 901f, guest PC 0x0c087240 */
if(!s->budget--) { s->failed_pc=0x0c087240u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087282u,2);
goto P_0c087242;
P_0c087242: /* original 04de, guest PC 0x0c087242 */
if(!s->budget--) { s->failed_pc=0x0c087242u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c087244;
P_0c087244: /* original 2448, guest PC 0x0c087244 */
if(!s->budget--) { s->failed_pc=0x0c087244u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c087246;
P_0c087246: /* original 8963, guest PC 0x0c087246 */
if(!s->budget--) { s->failed_pc=0x0c087246u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087310; }
goto P_0c087248;
P_0c087248: /* original e02a, guest PC 0x0c087248 */
if(!s->budget--) { s->failed_pc=0x0c087248u; return 0; }
r[0]=0x0000002au;
goto P_0c08724a;
P_0c08724a: /* original 054d, guest PC 0x0c08724a */
if(!s->budget--) { s->failed_pc=0x0c08724au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08724c;
P_0c08724c: /* original 7440, guest PC 0x0c08724c */
if(!s->budget--) { s->failed_pc=0x0c08724cu; return 0; }
r[4]+=0x00000040u;
goto P_0c08724e;
P_0c08724e: /* original 2558, guest PC 0x0c08724e */
if(!s->budget--) { s->failed_pc=0x0c08724eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c087250;
P_0c087250: /* original 8d02, guest PC 0x0c087250 */
if(!s->budget--) { s->failed_pc=0x0c087250u; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
if(cond) { goto P_0c087258; }
goto P_0c087254;
P_0c087252: /* original 044d, guest PC 0x0c087252 */
if(!s->budget--) { s->failed_pc=0x0c087252u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c087254;
P_0c087254: /* original 2448, guest PC 0x0c087254 */
if(!s->budget--) { s->failed_pc=0x0c087254u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c087256;
P_0c087256: /* original 8b5b, guest PC 0x0c087256 */
if(!s->budget--) { s->failed_pc=0x0c087256u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087310; }
goto P_0c087258;
P_0c087258: /* original d215, guest PC 0x0c087258 */
if(!s->budget--) { s->failed_pc=0x0c087258u; return 0; }
r[2]=read(ram,0x0c0872b0u,4);
goto P_0c08725a;
P_0c08725a: /* original 2c28, guest PC 0x0c08725a */
if(!s->budget--) { s->failed_pc=0x0c08725au; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[2])==0)!=0);
goto P_0c08725c;
P_0c08725c: /* original 8905, guest PC 0x0c08725c */
if(!s->budget--) { s->failed_pc=0x0c08725cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08726a; }
goto P_0c08725e;
P_0c08725e: /* original e048, guest PC 0x0c08725e */
if(!s->budget--) { s->failed_pc=0x0c08725eu; return 0; }
r[0]=0x00000048u;
goto P_0c087260;
P_0c087260: /* original 04ed, guest PC 0x0c087260 */
if(!s->budget--) { s->failed_pc=0x0c087260u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c087262;
P_0c087262: /* original 74ff, guest PC 0x0c087262 */
if(!s->budget--) { s->failed_pc=0x0c087262u; return 0; }
r[4]+=0xffffffffu;
goto P_0c087264;
P_0c087264: /* original 4411, guest PC 0x0c087264 */
if(!s->budget--) { s->failed_pc=0x0c087264u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c087266;
P_0c087266: /* original 8b53, guest PC 0x0c087266 */
if(!s->budget--) { s->failed_pc=0x0c087266u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087310; }
goto P_0c087268;
P_0c087268: /* original 0e45, guest PC 0x0c087268 */
if(!s->budget--) { s->failed_pc=0x0c087268u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08726a;
P_0c08726a: /* original 85e4, guest PC 0x0c08726a */
if(!s->budget--) { s->failed_pc=0x0c08726au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+8,2);
goto P_0c08726c;
P_0c08726c: /* original 6403, guest PC 0x0c08726c */
if(!s->budget--) { s->failed_pc=0x0c08726cu; return 0; }
r[4]=r[0];
goto P_0c08726e;
P_0c08726e: /* original 4410, guest PC 0x0c08726e */
if(!s->budget--) { s->failed_pc=0x0c08726eu; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c087270;
P_0c087270: /* original 8920, guest PC 0x0c087270 */
if(!s->budget--) { s->failed_pc=0x0c087270u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0872b4; }
goto P_0c087272;
P_0c087272: /* original 6043, guest PC 0x0c087272 */
if(!s->budget--) { s->failed_pc=0x0c087272u; return 0; }
r[0]=r[4];
goto P_0c087274;
P_0c087274: /* original 81e4, guest PC 0x0c087274 */
if(!s->budget--) { s->failed_pc=0x0c087274u; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c087276;
P_0c087276: /* original e07e, guest PC 0x0c087276 */
if(!s->budget--) { s->failed_pc=0x0c087276u; return 0; }
r[0]=0x0000007eu;
goto P_0c087278;
P_0c087278: /* original e300, guest PC 0x0c087278 */
if(!s->budget--) { s->failed_pc=0x0c087278u; return 0; }
r[3]=0x00000000u;
goto P_0c08727a;
P_0c08727a: /* original a060, guest PC 0x0c08727a */
if(!s->budget--) { s->failed_pc=0x0c08727au; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08733e;
P_0c08727c: /* original 0d34, guest PC 0x0c08727c */
if(!s->budget--) { s->failed_pc=0x0c08727cu; return 0; }
write(ram,r[13]+r[0],r[3],1);
if(!vf3_matrix_family(0x0c08727eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08727eu; return 0; } return 1;
P_0c0872b4: /* original 85e5, guest PC 0x0c0872b4 */
if(!s->budget--) { s->failed_pc=0x0c0872b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+10,2);
goto P_0c0872b6;
P_0c0872b6: /* original 6403, guest PC 0x0c0872b6 */
if(!s->budget--) { s->failed_pc=0x0c0872b6u; return 0; }
r[4]=r[0];
goto P_0c0872b8;
P_0c0872b8: /* original 4410, guest PC 0x0c0872b8 */
if(!s->budget--) { s->failed_pc=0x0c0872b8u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c0872ba;
P_0c0872ba: /* original 8929, guest PC 0x0c0872ba */
if(!s->budget--) { s->failed_pc=0x0c0872bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087310; }
goto P_0c0872bc;
P_0c0872bc: /* original 6043, guest PC 0x0c0872bc */
if(!s->budget--) { s->failed_pc=0x0c0872bcu; return 0; }
r[0]=r[4];
goto P_0c0872be;
P_0c0872be: /* original 81e5, guest PC 0x0c0872be */
if(!s->budget--) { s->failed_pc=0x0c0872beu; return 0; }
write(ram,r[14]+10,r[0],2);
goto P_0c0872c0;
P_0c0872c0: /* original e03a, guest PC 0x0c0872c0 */
if(!s->budget--) { s->failed_pc=0x0c0872c0u; return 0; }
r[0]=0x0000003au;
goto P_0c0872c2;
P_0c0872c2: /* original 04ec, guest PC 0x0c0872c2 */
if(!s->budget--) { s->failed_pc=0x0c0872c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0872c4;
P_0c0872c4: /* original 4410, guest PC 0x0c0872c4 */
if(!s->budget--) { s->failed_pc=0x0c0872c4u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c0872c6;
P_0c0872c6: /* original 8b0c, guest PC 0x0c0872c6 */
if(!s->budget--) { s->failed_pc=0x0c0872c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0872e2; }
goto P_0c0872c8;
P_0c0872c8: /* original d245, guest PC 0x0c0872c8 */
if(!s->budget--) { s->failed_pc=0x0c0872c8u; return 0; }
r[2]=read(ram,0x0c0873e0u,4);
goto P_0c0872ca;
P_0c0872ca: /* original 420b, guest PC 0x0c0872ca */
if(!s->budget--) { s->failed_pc=0x0c0872cau; return 0; }
target=r[2];
r[16]=code_base|0x0c0872ceu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0872ceu) { target=s->pc; goto dispatch; }
goto P_0c0872ce;
P_0c0872cc: /* original 0009, guest PC 0x0c0872cc */
if(!s->budget--) { s->failed_pc=0x0c0872ccu; return 0; }
goto P_0c0872ce;
P_0c0872ce: /* original e40f, guest PC 0x0c0872ce */
if(!s->budget--) { s->failed_pc=0x0c0872ceu; return 0; }
r[4]=0x0000000fu;
goto P_0c0872d0;
P_0c0872d0: /* original 6503, guest PC 0x0c0872d0 */
if(!s->budget--) { s->failed_pc=0x0c0872d0u; return 0; }
r[5]=r[0];
goto P_0c0872d2;
P_0c0872d2: /* original e3fb, guest PC 0x0c0872d2 */
if(!s->budget--) { s->failed_pc=0x0c0872d2u; return 0; }
r[3]=0xfffffffbu;
goto P_0c0872d4;
P_0c0872d4: /* original 2459, guest PC 0x0c0872d4 */
if(!s->budget--) { s->failed_pc=0x0c0872d4u; return 0; }
r[4]&=r[5];
goto P_0c0872d6;
P_0c0872d6: /* original e207, guest PC 0x0c0872d6 */
if(!s->budget--) { s->failed_pc=0x0c0872d6u; return 0; }
r[2]=0x00000007u;
goto P_0c0872d8;
P_0c0872d8: /* original 453c, guest PC 0x0c0872d8 */
if(!s->budget--) { s->failed_pc=0x0c0872d8u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c0872da;
P_0c0872da: /* original e039, guest PC 0x0c0872da */
if(!s->budget--) { s->failed_pc=0x0c0872dau; return 0; }
r[0]=0x00000039u;
goto P_0c0872dc;
P_0c0872dc: /* original 2529, guest PC 0x0c0872dc */
if(!s->budget--) { s->failed_pc=0x0c0872dcu; return 0; }
r[5]&=r[2];
goto P_0c0872de;
P_0c0872de: /* original 0e54, guest PC 0x0c0872de */
if(!s->budget--) { s->failed_pc=0x0c0872deu; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0872e0;
P_0c0872e0: /* original 7401, guest PC 0x0c0872e0 */
if(!s->budget--) { s->failed_pc=0x0c0872e0u; return 0; }
r[4]+=0x00000001u;
goto P_0c0872e2;
P_0c0872e2: /* original e03a, guest PC 0x0c0872e2 */
if(!s->budget--) { s->failed_pc=0x0c0872e2u; return 0; }
r[0]=0x0000003au;
goto P_0c0872e4;
P_0c0872e4: /* original 0e44, guest PC 0x0c0872e4 */
if(!s->budget--) { s->failed_pc=0x0c0872e4u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0872e6;
P_0c0872e6: /* original e039, guest PC 0x0c0872e6 */
if(!s->budget--) { s->failed_pc=0x0c0872e6u; return 0; }
r[0]=0x00000039u;
goto P_0c0872e8;
P_0c0872e8: /* original 05ec, guest PC 0x0c0872e8 */
if(!s->budget--) { s->failed_pc=0x0c0872e8u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0872ea;
P_0c0872ea: /* original d63e, guest PC 0x0c0872ea */
if(!s->budget--) { s->failed_pc=0x0c0872eau; return 0; }
r[6]=read(ram,0x0c0873e4u,4);
goto P_0c0872ec;
P_0c0872ec: /* original 4500, guest PC 0x0c0872ec */
if(!s->budget--) { s->failed_pc=0x0c0872ecu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0872ee;
P_0c0872ee: /* original 6053, guest PC 0x0c0872ee */
if(!s->budget--) { s->failed_pc=0x0c0872eeu; return 0; }
r[0]=r[5];
goto P_0c0872f0;
P_0c0872f0: /* original 4008, guest PC 0x0c0872f0 */
if(!s->budget--) { s->failed_pc=0x0c0872f0u; return 0; }
r[0]<<=2;
goto P_0c0872f2;
P_0c0872f2: /* original f366, guest PC 0x0c0872f2 */
if(!s->budget--) { s->failed_pc=0x0c0872f2u; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c0872f4;
P_0c0872f4: /* original e03c, guest PC 0x0c0872f4 */
if(!s->budget--) { s->failed_pc=0x0c0872f4u; return 0; }
r[0]=0x0000003cu;
goto P_0c0872f6;
P_0c0872f6: /* original fe37, guest PC 0x0c0872f6 */
if(!s->budget--) { s->failed_pc=0x0c0872f6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0872f8;
P_0c0872f8: /* original 6053, guest PC 0x0c0872f8 */
if(!s->budget--) { s->failed_pc=0x0c0872f8u; return 0; }
r[0]=r[5];
goto P_0c0872fa;
P_0c0872fa: /* original 7001, guest PC 0x0c0872fa */
if(!s->budget--) { s->failed_pc=0x0c0872fau; return 0; }
r[0]+=0x00000001u;
goto P_0c0872fc;
P_0c0872fc: /* original 4008, guest PC 0x0c0872fc */
if(!s->budget--) { s->failed_pc=0x0c0872fcu; return 0; }
r[0]<<=2;
goto P_0c0872fe;
P_0c0872fe: /* original f366, guest PC 0x0c0872fe */
if(!s->budget--) { s->failed_pc=0x0c0872feu; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c087300;
P_0c087300: /* original e040, guest PC 0x0c087300 */
if(!s->budget--) { s->failed_pc=0x0c087300u; return 0; }
r[0]=0x00000040u;
goto P_0c087302;
P_0c087302: /* original fe37, guest PC 0x0c087302 */
if(!s->budget--) { s->failed_pc=0x0c087302u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c087304;
P_0c087304: /* original bc0c, guest PC 0x0c087304 */
if(!s->budget--) { s->failed_pc=0x0c087304u; return 0; }
target=code_base|0x0c086b20u; r[16]=code_base|0x0c087308u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087308u) { target=s->pc; goto dispatch; }
goto P_0c087308;
P_0c087306: /* original 64e3, guest PC 0x0c087306 */
if(!s->budget--) { s->failed_pc=0x0c087306u; return 0; }
r[4]=r[14];
goto P_0c087308;
P_0c087308: /* original e07e, guest PC 0x0c087308 */
if(!s->budget--) { s->failed_pc=0x0c087308u; return 0; }
r[0]=0x0000007eu;
goto P_0c08730a;
P_0c08730a: /* original e201, guest PC 0x0c08730a */
if(!s->budget--) { s->failed_pc=0x0c08730au; return 0; }
r[2]=0x00000001u;
goto P_0c08730c;
P_0c08730c: /* original a017, guest PC 0x0c08730c */
if(!s->budget--) { s->failed_pc=0x0c08730cu; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c08733e;
P_0c08730e: /* original 0d24, guest PC 0x0c08730e */
if(!s->budget--) { s->failed_pc=0x0c08730eu; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c087310;
P_0c087310: /* original d333, guest PC 0x0c087310 */
if(!s->budget--) { s->failed_pc=0x0c087310u; return 0; }
r[3]=read(ram,0x0c0873e0u,4);
goto P_0c087312;
P_0c087312: /* original 430b, guest PC 0x0c087312 */
if(!s->budget--) { s->failed_pc=0x0c087312u; return 0; }
target=r[3];
r[16]=code_base|0x0c087316u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087316u) { target=s->pc; goto dispatch; }
goto P_0c087316;
P_0c087314: /* original 0009, guest PC 0x0c087314 */
if(!s->budget--) { s->failed_pc=0x0c087314u; return 0; }
goto P_0c087316;
P_0c087316: /* original d134, guest PC 0x0c087316 */
if(!s->budget--) { s->failed_pc=0x0c087316u; return 0; }
r[1]=read(ram,0x0c0873e8u,4);
goto P_0c087318;
P_0c087318: /* original e503, guest PC 0x0c087318 */
if(!s->budget--) { s->failed_pc=0x0c087318u; return 0; }
r[5]=0x00000003u;
goto P_0c08731a;
P_0c08731a: /* original 6403, guest PC 0x0c08731a */
if(!s->budget--) { s->failed_pc=0x0c08731au; return 0; }
r[4]=r[0];
goto P_0c08731c;
P_0c08731c: /* original 2059, guest PC 0x0c08731c */
if(!s->budget--) { s->failed_pc=0x0c08731cu; return 0; }
r[0]&=r[5];
goto P_0c08731e;
P_0c08731e: /* original e3f8, guest PC 0x0c08731e */
if(!s->budget--) { s->failed_pc=0x0c08731eu; return 0; }
r[3]=0xfffffff8u;
goto P_0c087320;
P_0c087320: /* original 001c, guest PC 0x0c087320 */
if(!s->budget--) { s->failed_pc=0x0c087320u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c087322;
P_0c087322: /* original 443c, guest PC 0x0c087322 */
if(!s->budget--) { s->failed_pc=0x0c087322u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c087324;
P_0c087324: /* original 2459, guest PC 0x0c087324 */
if(!s->budget--) { s->failed_pc=0x0c087324u; return 0; }
r[4]&=r[5];
goto P_0c087326;
P_0c087326: /* original 81e4, guest PC 0x0c087326 */
if(!s->budget--) { s->failed_pc=0x0c087326u; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c087328;
P_0c087328: /* original 6043, guest PC 0x0c087328 */
if(!s->budget--) { s->failed_pc=0x0c087328u; return 0; }
r[0]=r[4];
goto P_0c08732a;
P_0c08732a: /* original e501, guest PC 0x0c08732a */
if(!s->budget--) { s->failed_pc=0x0c08732au; return 0; }
r[5]=0x00000001u;
goto P_0c08732c;
P_0c08732c: /* original 4021, guest PC 0x0c08732c */
if(!s->budget--) { s->failed_pc=0x0c08732cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c08732e;
P_0c08732e: /* original 2509, guest PC 0x0c08732e */
if(!s->budget--) { s->failed_pc=0x0c08732eu; return 0; }
r[5]&=r[0];
goto P_0c087330;
P_0c087330: /* original e038, guest PC 0x0c087330 */
if(!s->budget--) { s->failed_pc=0x0c087330u; return 0; }
r[0]=0x00000038u;
goto P_0c087332;
P_0c087332: /* original 0e54, guest PC 0x0c087332 */
if(!s->budget--) { s->failed_pc=0x0c087332u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c087334;
P_0c087334: /* original e20a, guest PC 0x0c087334 */
if(!s->budget--) { s->failed_pc=0x0c087334u; return 0; }
r[2]=0x0000000au;
goto P_0c087336;
P_0c087336: /* original d02d, guest PC 0x0c087336 */
if(!s->budget--) { s->failed_pc=0x0c087336u; return 0; }
r[0]=read(ram,0x0c0873ecu,4);
goto P_0c087338;
P_0c087338: /* original 32ec, guest PC 0x0c087338 */
if(!s->budget--) { s->failed_pc=0x0c087338u; return 0; }
r[2]+=r[14];
goto P_0c08733a;
P_0c08733a: /* original 034c, guest PC 0x0c08733a */
if(!s->budget--) { s->failed_pc=0x0c08733au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c08733c;
P_0c08733c: /* original 2231, guest PC 0x0c08733c */
if(!s->budget--) { s->failed_pc=0x0c08733cu; return 0; }
write(ram,r[2],r[3],2);
goto P_0c08733e;
P_0c08733e: /* original 7f08, guest PC 0x0c08733e */
if(!s->budget--) { s->failed_pc=0x0c08733eu; return 0; }
r[15]+=0x00000008u;
goto P_0c087340;
P_0c087340: /* original 4f26, guest PC 0x0c087340 */
if(!s->budget--) { s->failed_pc=0x0c087340u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c087342;
P_0c087342: /* original 6cf6, guest PC 0x0c087342 */
if(!s->budget--) { s->failed_pc=0x0c087342u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c087344;
P_0c087344: /* original 6df6, guest PC 0x0c087344 */
if(!s->budget--) { s->failed_pc=0x0c087344u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c087346;
P_0c087346: /* original 000b, guest PC 0x0c087346 */
if(!s->budget--) { s->failed_pc=0x0c087346u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c087348: /* original 6ef6, guest PC 0x0c087348 */
if(!s->budget--) { s->failed_pc=0x0c087348u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08734au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08734au; return 0; } return 1;
P_0c087542: /* original 5041, guest PC 0x0c087542 */
if(!s->budget--) { s->failed_pc=0x0c087542u; return 0; }
r[0]=read(ram,r[4]+4,4);
goto P_0c087544;
P_0c087544: /* original 88ff, guest PC 0x0c087544 */
if(!s->budget--) { s->failed_pc=0x0c087544u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c087546;
P_0c087546: /* original 8d0a, guest PC 0x0c087546 */
if(!s->budget--) { s->failed_pc=0x0c087546u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c08755e; }
goto P_0c08754a;
P_0c087548: /* original 6503, guest PC 0x0c087548 */
if(!s->budget--) { s->failed_pc=0x0c087548u; return 0; }
r[5]=r[0];
goto P_0c08754a;
P_0c08754a: /* original 6252, guest PC 0x0c08754a */
if(!s->budget--) { s->failed_pc=0x0c08754au; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c08754c;
P_0c08754c: /* original 1421, guest PC 0x0c08754c */
if(!s->budget--) { s->failed_pc=0x0c08754cu; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c08754e;
P_0c08754e: /* original 6642, guest PC 0x0c08754e */
if(!s->budget--) { s->failed_pc=0x0c08754eu; return 0; }
tmp=read(ram,r[4],4);
r[6]=tmp;
goto P_0c087550;
P_0c087550: /* original 6063, guest PC 0x0c087550 */
if(!s->budget--) { s->failed_pc=0x0c087550u; return 0; }
r[0]=r[6];
goto P_0c087552;
P_0c087552: /* original 88ff, guest PC 0x0c087552 */
if(!s->budget--) { s->failed_pc=0x0c087552u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c087554;
P_0c087554: /* original 2562, guest PC 0x0c087554 */
if(!s->budget--) { s->failed_pc=0x0c087554u; return 0; }
write(ram,r[5],r[6],4);
goto P_0c087556;
P_0c087556: /* original 2452, guest PC 0x0c087556 */
if(!s->budget--) { s->failed_pc=0x0c087556u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c087558;
P_0c087558: /* original 8d01, guest PC 0x0c087558 */
if(!s->budget--) { s->failed_pc=0x0c087558u; return 0; }
cond=r[17]&1u;
write(ram,r[5]+4,r[4],4);
if(cond) { goto P_0c08755e; }
goto P_0c08755c;
P_0c08755a: /* original 1541, guest PC 0x0c08755a */
if(!s->budget--) { s->failed_pc=0x0c08755au; return 0; }
write(ram,r[5]+4,r[4],4);
goto P_0c08755c;
P_0c08755c: /* original 1651, guest PC 0x0c08755c */
if(!s->budget--) { s->failed_pc=0x0c08755cu; return 0; }
write(ram,r[6]+4,r[5],4);
goto P_0c08755e;
P_0c08755e: /* original 000b, guest PC 0x0c08755e */
if(!s->budget--) { s->failed_pc=0x0c08755eu; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c087560: /* original 6053, guest PC 0x0c087560 */
if(!s->budget--) { s->failed_pc=0x0c087560u; return 0; }
r[0]=r[5];
goto P_0c087562;
P_0c087562: /* original 8448, guest PC 0x0c087562 */
if(!s->budget--) { s->failed_pc=0x0c087562u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c087564;
P_0c087564: /* original 6603, guest PC 0x0c087564 */
if(!s->budget--) { s->failed_pc=0x0c087564u; return 0; }
r[6]=r[0];
goto P_0c087566;
P_0c087566: /* original 606e, guest PC 0x0c087566 */
if(!s->budget--) { s->failed_pc=0x0c087566u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[6];
goto P_0c087568;
P_0c087568: /* original 88ff, guest PC 0x0c087568 */
if(!s->budget--) { s->failed_pc=0x0c087568u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c08756a;
P_0c08756a: /* original 891f, guest PC 0x0c08756a */
if(!s->budget--) { s->failed_pc=0x0c08756au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0875ac; }
goto P_0c08756c;
P_0c08756c: /* original 76ff, guest PC 0x0c08756c */
if(!s->budget--) { s->failed_pc=0x0c08756cu; return 0; }
r[6]+=0xffffffffu;
goto P_0c08756e;
P_0c08756e: /* original 6063, guest PC 0x0c08756e */
if(!s->budget--) { s->failed_pc=0x0c08756eu; return 0; }
r[0]=r[6];
goto P_0c087570;
P_0c087570: /* original 666e, guest PC 0x0c087570 */
if(!s->budget--) { s->failed_pc=0x0c087570u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)r[6];
goto P_0c087572;
P_0c087572: /* original 2668, guest PC 0x0c087572 */
if(!s->budget--) { s->failed_pc=0x0c087572u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c087574;
P_0c087574: /* original 8f1a, guest PC 0x0c087574 */
if(!s->budget--) { s->failed_pc=0x0c087574u; return 0; }
cond=r[17]&1u;
write(ram,r[4]+8,r[0],1);
if(!cond) { goto P_0c0875ac; }
goto P_0c087578;
P_0c087576: /* original 8048, guest PC 0x0c087576 */
if(!s->budget--) { s->failed_pc=0x0c087576u; return 0; }
write(ram,r[4]+8,r[0],1);
goto P_0c087578;
P_0c087578: /* original 8449, guest PC 0x0c087578 */
if(!s->budget--) { s->failed_pc=0x0c087578u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+9,1);
goto P_0c08757a;
P_0c08757a: /* original 6703, guest PC 0x0c08757a */
if(!s->budget--) { s->failed_pc=0x0c08757au; return 0; }
r[7]=r[0];
goto P_0c08757c;
P_0c08757c: /* original 4708, guest PC 0x0c08757c */
if(!s->budget--) { s->failed_pc=0x0c08757cu; return 0; }
r[7]<<=2;
goto P_0c08757e;
P_0c08757e: /* original 375c, guest PC 0x0c08757e */
if(!s->budget--) { s->failed_pc=0x0c08757eu; return 0; }
r[7]+=r[5];
goto P_0c087580;
P_0c087580: /* original 6603, guest PC 0x0c087580 */
if(!s->budget--) { s->failed_pc=0x0c087580u; return 0; }
r[6]=r[0];
goto P_0c087582;
P_0c087582: /* original 8471, guest PC 0x0c087582 */
if(!s->budget--) { s->failed_pc=0x0c087582u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+1,1);
goto P_0c087584;
P_0c087584: /* original 6703, guest PC 0x0c087584 */
if(!s->budget--) { s->failed_pc=0x0c087584u; return 0; }
r[7]=r[0];
goto P_0c087586;
P_0c087586: /* original 617e, guest PC 0x0c087586 */
if(!s->budget--) { s->failed_pc=0x0c087586u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c087588;
P_0c087588: /* original 6013, guest PC 0x0c087588 */
if(!s->budget--) { s->failed_pc=0x0c087588u; return 0; }
r[0]=r[1];
goto P_0c08758a;
P_0c08758a: /* original 88ff, guest PC 0x0c08758a */
if(!s->budget--) { s->failed_pc=0x0c08758au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c08758c;
P_0c08758c: /* original 8f03, guest PC 0x0c08758c */
if(!s->budget--) { s->failed_pc=0x0c08758cu; return 0; }
cond=r[17]&1u;
r[6]+=0x00000001u;
if(!cond) { goto P_0c087596; }
goto P_0c087590;
P_0c08758e: /* original 7601, guest PC 0x0c08758e */
if(!s->budget--) { s->failed_pc=0x0c08758eu; return 0; }
r[6]+=0x00000001u;
goto P_0c087590;
P_0c087590: /* original 6073, guest PC 0x0c087590 */
if(!s->budget--) { s->failed_pc=0x0c087590u; return 0; }
r[0]=r[7];
goto P_0c087592;
P_0c087592: /* original 000b, guest PC 0x0c087592 */
if(!s->budget--) { s->failed_pc=0x0c087592u; return 0; }
target=r[16];
write(ram,r[4]+8,r[0],1);
s->pc=target; return ram->oob==0;
P_0c087594: /* original 8048, guest PC 0x0c087594 */
if(!s->budget--) { s->failed_pc=0x0c087594u; return 0; }
write(ram,r[4]+8,r[0],1);
goto P_0c087596;
P_0c087596: /* original 2118, guest PC 0x0c087596 */
if(!s->budget--) { s->failed_pc=0x0c087596u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c087598;
P_0c087598: /* original 8900, guest PC 0x0c087598 */
if(!s->budget--) { s->failed_pc=0x0c087598u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08759c; }
goto P_0c08759a;
P_0c08759a: /* original e600, guest PC 0x0c08759a */
if(!s->budget--) { s->failed_pc=0x0c08759au; return 0; }
r[6]=0x00000000u;
goto P_0c08759c;
P_0c08759c: /* original 6063, guest PC 0x0c08759c */
if(!s->budget--) { s->failed_pc=0x0c08759cu; return 0; }
r[0]=r[6];
goto P_0c08759e;
P_0c08759e: /* original 4608, guest PC 0x0c08759e */
if(!s->budget--) { s->failed_pc=0x0c08759eu; return 0; }
r[6]<<=2;
goto P_0c0875a0;
P_0c0875a0: /* original 356c, guest PC 0x0c0875a0 */
if(!s->budget--) { s->failed_pc=0x0c0875a0u; return 0; }
r[5]+=r[6];
goto P_0c0875a2;
P_0c0875a2: /* original 8049, guest PC 0x0c0875a2 */
if(!s->budget--) { s->failed_pc=0x0c0875a2u; return 0; }
write(ram,r[4]+9,r[0],1);
goto P_0c0875a4;
P_0c0875a4: /* original 6050, guest PC 0x0c0875a4 */
if(!s->budget--) { s->failed_pc=0x0c0875a4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[0]=tmp;
goto P_0c0875a6;
P_0c0875a6: /* original 8048, guest PC 0x0c0875a6 */
if(!s->budget--) { s->failed_pc=0x0c0875a6u; return 0; }
write(ram,r[4]+8,r[0],1);
goto P_0c0875a8;
P_0c0875a8: /* original 8551, guest PC 0x0c0875a8 */
if(!s->budget--) { s->failed_pc=0x0c0875a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c0875aa;
P_0c0875aa: /* original 8145, guest PC 0x0c0875aa */
if(!s->budget--) { s->failed_pc=0x0c0875aau; return 0; }
write(ram,r[4]+10,r[0],2);
goto P_0c0875ac;
P_0c0875ac: /* original 000b, guest PC 0x0c0875ac */
if(!s->budget--) { s->failed_pc=0x0c0875acu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0875ae: /* original 0009, guest PC 0x0c0875ae */
if(!s->budget--) { s->failed_pc=0x0c0875aeu; return 0; }
return vf3_matrix_family(0x0c0875b0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
