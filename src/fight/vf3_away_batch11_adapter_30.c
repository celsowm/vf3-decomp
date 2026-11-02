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
int vf3_away_batch11_adapter_30(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c074592u: goto P_0c074592;
case 0x0c074594u: goto P_0c074594;
case 0x0c074596u: goto P_0c074596;
case 0x0c074598u: goto P_0c074598;
case 0x0c07459au: goto P_0c07459a;
case 0x0c07459cu: goto P_0c07459c;
case 0x0c07459eu: goto P_0c07459e;
case 0x0c0745a0u: goto P_0c0745a0;
case 0x0c0745a2u: goto P_0c0745a2;
case 0x0c0745a4u: goto P_0c0745a4;
case 0x0c0745a6u: goto P_0c0745a6;
case 0x0c0745a8u: goto P_0c0745a8;
case 0x0c0745aau: goto P_0c0745aa;
case 0x0c0745acu: goto P_0c0745ac;
case 0x0c0745aeu: goto P_0c0745ae;
case 0x0c0745b0u: goto P_0c0745b0;
case 0x0c0745b2u: goto P_0c0745b2;
case 0x0c0745b4u: goto P_0c0745b4;
case 0x0c0745b6u: goto P_0c0745b6;
case 0x0c0745b8u: goto P_0c0745b8;
case 0x0c0745bau: goto P_0c0745ba;
case 0x0c0745bcu: goto P_0c0745bc;
case 0x0c0745beu: goto P_0c0745be;
case 0x0c0745c0u: goto P_0c0745c0;
case 0x0c0745c2u: goto P_0c0745c2;
case 0x0c0745c4u: goto P_0c0745c4;
case 0x0c0745c6u: goto P_0c0745c6;
case 0x0c0745c8u: goto P_0c0745c8;
case 0x0c0745cau: goto P_0c0745ca;
case 0x0c0745ccu: goto P_0c0745cc;
case 0x0c0745ceu: goto P_0c0745ce;
case 0x0c0745d0u: goto P_0c0745d0;
case 0x0c0745d2u: goto P_0c0745d2;
case 0x0c0745d4u: goto P_0c0745d4;
case 0x0c0745d6u: goto P_0c0745d6;
case 0x0c0745d8u: goto P_0c0745d8;
case 0x0c0745dau: goto P_0c0745da;
case 0x0c0745dcu: goto P_0c0745dc;
case 0x0c0745deu: goto P_0c0745de;
case 0x0c0745e0u: goto P_0c0745e0;
case 0x0c0745e2u: goto P_0c0745e2;
case 0x0c0745e4u: goto P_0c0745e4;
case 0x0c0745e6u: goto P_0c0745e6;
case 0x0c0745e8u: goto P_0c0745e8;
case 0x0c0745eau: goto P_0c0745ea;
case 0x0c0745ecu: goto P_0c0745ec;
case 0x0c0745eeu: goto P_0c0745ee;
case 0x0c0745f0u: goto P_0c0745f0;
case 0x0c0745f2u: goto P_0c0745f2;
case 0x0c0745f4u: goto P_0c0745f4;
case 0x0c0745f6u: goto P_0c0745f6;
case 0x0c0745f8u: goto P_0c0745f8;
case 0x0c0745fau: goto P_0c0745fa;
case 0x0c0745fcu: goto P_0c0745fc;
case 0x0c0745feu: goto P_0c0745fe;
case 0x0c074600u: goto P_0c074600;
case 0x0c074602u: goto P_0c074602;
case 0x0c074604u: goto P_0c074604;
case 0x0c074606u: goto P_0c074606;
case 0x0c074608u: goto P_0c074608;
case 0x0c07460au: goto P_0c07460a;
case 0x0c07460cu: goto P_0c07460c;
case 0x0c07460eu: goto P_0c07460e;
case 0x0c074610u: goto P_0c074610;
case 0x0c074612u: goto P_0c074612;
case 0x0c074614u: goto P_0c074614;
case 0x0c074616u: goto P_0c074616;
case 0x0c074618u: goto P_0c074618;
case 0x0c07461au: goto P_0c07461a;
case 0x0c07461cu: goto P_0c07461c;
case 0x0c07461eu: goto P_0c07461e;
case 0x0c074634u: goto P_0c074634;
case 0x0c074636u: goto P_0c074636;
case 0x0c074638u: goto P_0c074638;
case 0x0c07463au: goto P_0c07463a;
case 0x0c07463cu: goto P_0c07463c;
case 0x0c07463eu: goto P_0c07463e;
case 0x0c074640u: goto P_0c074640;
case 0x0c074642u: goto P_0c074642;
case 0x0c074644u: goto P_0c074644;
case 0x0c074646u: goto P_0c074646;
case 0x0c074648u: goto P_0c074648;
case 0x0c07464au: goto P_0c07464a;
case 0x0c07464cu: goto P_0c07464c;
case 0x0c07464eu: goto P_0c07464e;
case 0x0c074650u: goto P_0c074650;
case 0x0c074652u: goto P_0c074652;
case 0x0c074654u: goto P_0c074654;
case 0x0c074656u: goto P_0c074656;
case 0x0c074658u: goto P_0c074658;
case 0x0c07465au: goto P_0c07465a;
case 0x0c07465cu: goto P_0c07465c;
case 0x0c07465eu: goto P_0c07465e;
case 0x0c074660u: goto P_0c074660;
case 0x0c074662u: goto P_0c074662;
case 0x0c074664u: goto P_0c074664;
case 0x0c074666u: goto P_0c074666;
case 0x0c074668u: goto P_0c074668;
case 0x0c07466au: goto P_0c07466a;
case 0x0c07466cu: goto P_0c07466c;
case 0x0c07466eu: goto P_0c07466e;
case 0x0c074670u: goto P_0c074670;
case 0x0c074672u: goto P_0c074672;
case 0x0c074674u: goto P_0c074674;
case 0x0c074676u: goto P_0c074676;
case 0x0c074678u: goto P_0c074678;
case 0x0c07467au: goto P_0c07467a;
case 0x0c07467cu: goto P_0c07467c;
case 0x0c07467eu: goto P_0c07467e;
case 0x0c074680u: goto P_0c074680;
case 0x0c074682u: goto P_0c074682;
case 0x0c074684u: goto P_0c074684;
case 0x0c074686u: goto P_0c074686;
case 0x0c074688u: goto P_0c074688;
case 0x0c07468au: goto P_0c07468a;
case 0x0c07468cu: goto P_0c07468c;
case 0x0c07468eu: goto P_0c07468e;
case 0x0c074690u: goto P_0c074690;
case 0x0c074692u: goto P_0c074692;
case 0x0c074694u: goto P_0c074694;
case 0x0c074696u: goto P_0c074696;
case 0x0c074698u: goto P_0c074698;
case 0x0c07469au: goto P_0c07469a;
case 0x0c07469cu: goto P_0c07469c;
case 0x0c07469eu: goto P_0c07469e;
case 0x0c0746a0u: goto P_0c0746a0;
case 0x0c0746a2u: goto P_0c0746a2;
case 0x0c0746a4u: goto P_0c0746a4;
case 0x0c0746a6u: goto P_0c0746a6;
case 0x0c0746a8u: goto P_0c0746a8;
case 0x0c0746aau: goto P_0c0746aa;
case 0x0c0746acu: goto P_0c0746ac;
case 0x0c0746aeu: goto P_0c0746ae;
case 0x0c0746b0u: goto P_0c0746b0;
case 0x0c0746b2u: goto P_0c0746b2;
case 0x0c0746b4u: goto P_0c0746b4;
case 0x0c0746b6u: goto P_0c0746b6;
case 0x0c0746b8u: goto P_0c0746b8;
case 0x0c0746bau: goto P_0c0746ba;
case 0x0c0746bcu: goto P_0c0746bc;
case 0x0c0746beu: goto P_0c0746be;
case 0x0c0746c0u: goto P_0c0746c0;
case 0x0c0746c2u: goto P_0c0746c2;
case 0x0c0746c4u: goto P_0c0746c4;
case 0x0c0746c6u: goto P_0c0746c6;
case 0x0c0746c8u: goto P_0c0746c8;
case 0x0c0746cau: goto P_0c0746ca;
case 0x0c0746ccu: goto P_0c0746cc;
case 0x0c0746ceu: goto P_0c0746ce;
case 0x0c0746d0u: goto P_0c0746d0;
case 0x0c0746d2u: goto P_0c0746d2;
case 0x0c0746d4u: goto P_0c0746d4;
case 0x0c0746d6u: goto P_0c0746d6;
case 0x0c0746d8u: goto P_0c0746d8;
case 0x0c0746dau: goto P_0c0746da;
case 0x0c074702u: goto P_0c074702;
case 0x0c074704u: goto P_0c074704;
case 0x0c074706u: goto P_0c074706;
case 0x0c074708u: goto P_0c074708;
case 0x0c07470au: goto P_0c07470a;
case 0x0c07470cu: goto P_0c07470c;
case 0x0c07470eu: goto P_0c07470e;
case 0x0c074710u: goto P_0c074710;
case 0x0c074712u: goto P_0c074712;
case 0x0c074714u: goto P_0c074714;
case 0x0c074716u: goto P_0c074716;
case 0x0c074718u: goto P_0c074718;
case 0x0c07471au: goto P_0c07471a;
case 0x0c07471cu: goto P_0c07471c;
case 0x0c07471eu: goto P_0c07471e;
case 0x0c074720u: goto P_0c074720;
case 0x0c074722u: goto P_0c074722;
case 0x0c074724u: goto P_0c074724;
case 0x0c074726u: goto P_0c074726;
case 0x0c074728u: goto P_0c074728;
case 0x0c07472au: goto P_0c07472a;
case 0x0c07472cu: goto P_0c07472c;
case 0x0c07472eu: goto P_0c07472e;
case 0x0c074730u: goto P_0c074730;
case 0x0c074732u: goto P_0c074732;
case 0x0c074734u: goto P_0c074734;
case 0x0c074736u: goto P_0c074736;
case 0x0c074738u: goto P_0c074738;
case 0x0c07473au: goto P_0c07473a;
case 0x0c07473cu: goto P_0c07473c;
case 0x0c0747b2u: goto P_0c0747b2;
case 0x0c0747b4u: goto P_0c0747b4;
case 0x0c0747b6u: goto P_0c0747b6;
case 0x0c0747b8u: goto P_0c0747b8;
case 0x0c0747bau: goto P_0c0747ba;
case 0x0c0747bcu: goto P_0c0747bc;
case 0x0c0747beu: goto P_0c0747be;
case 0x0c0747c0u: goto P_0c0747c0;
case 0x0c0747c2u: goto P_0c0747c2;
case 0x0c0747c4u: goto P_0c0747c4;
case 0x0c0747c6u: goto P_0c0747c6;
case 0x0c0747c8u: goto P_0c0747c8;
case 0x0c0747cau: goto P_0c0747ca;
case 0x0c0747ccu: goto P_0c0747cc;
case 0x0c0747ceu: goto P_0c0747ce;
case 0x0c0747d0u: goto P_0c0747d0;
case 0x0c0747d2u: goto P_0c0747d2;
case 0x0c0747d4u: goto P_0c0747d4;
case 0x0c0747d6u: goto P_0c0747d6;
default: return vf3_matrix_family(target,s,ram);
}
P_0c074592: /* original 2fe6, guest PC 0x0c074592 */
if(!s->budget--) { s->failed_pc=0x0c074592u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c074594;
P_0c074594: /* original 6e53, guest PC 0x0c074594 */
if(!s->budget--) { s->failed_pc=0x0c074594u; return 0; }
r[14]=r[5];
goto P_0c074596;
P_0c074596: /* original 2fd6, guest PC 0x0c074596 */
if(!s->budget--) { s->failed_pc=0x0c074596u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c074598;
P_0c074598: /* original 6d63, guest PC 0x0c074598 */
if(!s->budget--) { s->failed_pc=0x0c074598u; return 0; }
r[13]=r[6];
goto P_0c07459a;
P_0c07459a: /* original fffb, guest PC 0x0c07459a */
if(!s->budget--) { s->failed_pc=0x0c07459au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c07459c;
P_0c07459c: /* original ffeb, guest PC 0x0c07459c */
if(!s->budget--) { s->failed_pc=0x0c07459cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c07459e;
P_0c07459e: /* original 4f22, guest PC 0x0c07459e */
if(!s->budget--) { s->failed_pc=0x0c07459eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0745a0;
P_0c0745a0: /* original 7ffc, guest PC 0x0c0745a0 */
if(!s->budget--) { s->failed_pc=0x0c0745a0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0745a2;
P_0c0745a2: /* original 2f42, guest PC 0x0c0745a2 */
if(!s->budget--) { s->failed_pc=0x0c0745a2u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0745a4;
P_0c0745a4: /* original 903e, guest PC 0x0c0745a4 */
if(!s->budget--) { s->failed_pc=0x0c0745a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074624u,2);
goto P_0c0745a6;
P_0c0745a6: /* original f28d, guest PC 0x0c0745a6 */
if(!s->budget--) { s->failed_pc=0x0c0745a6u; return 0; }
fr[2]=0;
goto P_0c0745a8;
P_0c0745a8: /* original f5e6, guest PC 0x0c0745a8 */
if(!s->budget--) { s->failed_pc=0x0c0745a8u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0745aa;
P_0c0745aa: /* original f3d6, guest PC 0x0c0745aa */
if(!s->budget--) { s->failed_pc=0x0c0745aau; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0745ac;
P_0c0745ac: /* original 7008, guest PC 0x0c0745ac */
if(!s->budget--) { s->failed_pc=0x0c0745acu; return 0; }
r[0]+=0x00000008u;
goto P_0c0745ae;
P_0c0745ae: /* original f6e6, guest PC 0x0c0745ae */
if(!s->budget--) { s->failed_pc=0x0c0745aeu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0745b0;
P_0c0745b0: /* original f531, guest PC 0x0c0745b0 */
if(!s->budget--) { s->failed_pc=0x0c0745b0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c0745b2;
P_0c0745b2: /* original f3d6, guest PC 0x0c0745b2 */
if(!s->budget--) { s->failed_pc=0x0c0745b2u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0745b4;
P_0c0745b4: /* original f631, guest PC 0x0c0745b4 */
if(!s->budget--) { s->failed_pc=0x0c0745b4u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c0745b6;
P_0c0745b6: /* original f05c, guest PC 0x0c0745b6 */
if(!s->budget--) { s->failed_pc=0x0c0745b6u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0745b8;
P_0c0745b8: /* original f36c, guest PC 0x0c0745b8 */
if(!s->budget--) { s->failed_pc=0x0c0745b8u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c0745ba;
P_0c0745ba: /* original f362, guest PC 0x0c0745ba */
if(!s->budget--) { s->failed_pc=0x0c0745bau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c0745bc;
P_0c0745bc: /* original f35e, guest PC 0x0c0745bc */
if(!s->budget--) { s->failed_pc=0x0c0745bcu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c0745be;
P_0c0745be: /* original f43c, guest PC 0x0c0745be */
if(!s->budget--) { s->failed_pc=0x0c0745beu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0745c0;
P_0c0745c0: /* original f424, guest PC 0x0c0745c0 */
if(!s->budget--) { s->failed_pc=0x0c0745c0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[2]))!=0);
goto P_0c0745c2;
P_0c0745c2: /* original 890b, guest PC 0x0c0745c2 */
if(!s->budget--) { s->failed_pc=0x0c0745c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0745dc; }
goto P_0c0745c4;
P_0c0745c4: /* original c719, guest PC 0x0c0745c4 */
if(!s->budget--) { s->failed_pc=0x0c0745c4u; return 0; }
r[0]=code_base|0x0007462cu;
goto P_0c0745c6;
P_0c0745c6: /* original f308, guest PC 0x0c0745c6 */
if(!s->budget--) { s->failed_pc=0x0c0745c6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0745c8;
P_0c0745c8: /* original f345, guest PC 0x0c0745c8 */
if(!s->budget--) { s->failed_pc=0x0c0745c8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0745ca;
P_0c0745ca: /* original 8f02, guest PC 0x0c0745ca */
if(!s->budget--) { s->failed_pc=0x0c0745cau; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,15,5);
if(!cond) { goto P_0c0745d2; }
goto P_0c0745ce;
P_0c0745cc: /* original ff5c, guest PC 0x0c0745cc */
if(!s->budget--) { s->failed_pc=0x0c0745ccu; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c0745ce;
P_0c0745ce: /* original a001, guest PC 0x0c0745ce */
if(!s->budget--) { s->failed_pc=0x0c0745ceu; return 0; }
fr[4]=0;
goto P_0c0745d4;
P_0c0745d0: /* original f48d, guest PC 0x0c0745d0 */
if(!s->budget--) { s->failed_pc=0x0c0745d0u; return 0; }
fr[4]=0;
goto P_0c0745d2;
P_0c0745d2: /* original f47d, guest PC 0x0c0745d2 */
if(!s->budget--) { s->failed_pc=0x0c0745d2u; return 0; }
if(!vf3_fpu_fsrra(fr[4],r[18],&fr[4])) goto unsupported;
goto P_0c0745d4;
P_0c0745d4: /* original ff42, guest PC 0x0c0745d4 */
if(!s->budget--) { s->failed_pc=0x0c0745d4u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[4],r[18],'*');
goto P_0c0745d6;
P_0c0745d6: /* original fe6c, guest PC 0x0c0745d6 */
if(!s->budget--) { s->failed_pc=0x0c0745d6u; return 0; }
vf3_matrix_move(s,14,6);
goto P_0c0745d8;
P_0c0745d8: /* original a002, guest PC 0x0c0745d8 */
if(!s->budget--) { s->failed_pc=0x0c0745d8u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'*');
goto P_0c0745e0;
P_0c0745da: /* original fe42, guest PC 0x0c0745da */
if(!s->budget--) { s->failed_pc=0x0c0745dau; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'*');
goto P_0c0745dc;
P_0c0745dc: /* original fe4c, guest PC 0x0c0745dc */
if(!s->budget--) { s->failed_pc=0x0c0745dcu; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c0745de;
P_0c0745de: /* original ff4c, guest PC 0x0c0745de */
if(!s->budget--) { s->failed_pc=0x0c0745deu; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c0745e0;
P_0c0745e0: /* original d213, guest PC 0x0c0745e0 */
if(!s->budget--) { s->failed_pc=0x0c0745e0u; return 0; }
r[2]=read(ram,0x0c074630u,4);
goto P_0c0745e2;
P_0c0745e2: /* original f5ec, guest PC 0x0c0745e2 */
if(!s->budget--) { s->failed_pc=0x0c0745e2u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0745e4;
P_0c0745e4: /* original 420b, guest PC 0x0c0745e4 */
if(!s->budget--) { s->failed_pc=0x0c0745e4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0745e8u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0745e8u) { target=s->pc; goto dispatch; }
goto P_0c0745e8;
P_0c0745e6: /* original f4fc, guest PC 0x0c0745e6 */
if(!s->budget--) { s->failed_pc=0x0c0745e6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0745e8;
P_0c0745e8: /* original 63f2, guest PC 0x0c0745e8 */
if(!s->budget--) { s->failed_pc=0x0c0745e8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0745ea;
P_0c0745ea: /* original 640f, guest PC 0x0c0745ea */
if(!s->budget--) { s->failed_pc=0x0c0745eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0745ec;
P_0c0745ec: /* original e038, guest PC 0x0c0745ec */
if(!s->budget--) { s->failed_pc=0x0c0745ecu; return 0; }
r[0]=0x00000038u;
goto P_0c0745ee;
P_0c0745ee: /* original f3f7, guest PC 0x0c0745ee */
if(!s->budget--) { s->failed_pc=0x0c0745eeu; return 0; }
vf3_matrix_store(s,ram,15,r[3]+r[0]);
goto P_0c0745f0;
P_0c0745f0: /* original e03c, guest PC 0x0c0745f0 */
if(!s->budget--) { s->failed_pc=0x0c0745f0u; return 0; }
r[0]=0x0000003cu;
goto P_0c0745f2;
P_0c0745f2: /* original 63f2, guest PC 0x0c0745f2 */
if(!s->budget--) { s->failed_pc=0x0c0745f2u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0745f4;
P_0c0745f4: /* original 7f04, guest PC 0x0c0745f4 */
if(!s->budget--) { s->failed_pc=0x0c0745f4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0745f6;
P_0c0745f6: /* original 4f26, guest PC 0x0c0745f6 */
if(!s->budget--) { s->failed_pc=0x0c0745f6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0745f8;
P_0c0745f8: /* original f3e7, guest PC 0x0c0745f8 */
if(!s->budget--) { s->failed_pc=0x0c0745f8u; return 0; }
vf3_matrix_store(s,ram,14,r[3]+r[0]);
goto P_0c0745fa;
P_0c0745fa: /* original 9014, guest PC 0x0c0745fa */
if(!s->budget--) { s->failed_pc=0x0c0745fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074626u,2);
goto P_0c0745fc;
P_0c0745fc: /* original 0d45, guest PC 0x0c0745fc */
if(!s->budget--) { s->failed_pc=0x0c0745fcu; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c0745fe;
P_0c0745fe: /* original 9313, guest PC 0x0c0745fe */
if(!s->budget--) { s->failed_pc=0x0c0745feu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074628u,2);
goto P_0c074600;
P_0c074600: /* original 343c, guest PC 0x0c074600 */
if(!s->budget--) { s->failed_pc=0x0c074600u; return 0; }
r[4]+=r[3];
goto P_0c074602;
P_0c074602: /* original 0e45, guest PC 0x0c074602 */
if(!s->budget--) { s->failed_pc=0x0c074602u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c074604;
P_0c074604: /* original 900c, guest PC 0x0c074604 */
if(!s->budget--) { s->failed_pc=0x0c074604u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074620u,2);
goto P_0c074606;
P_0c074606: /* original f48d, guest PC 0x0c074606 */
if(!s->budget--) { s->failed_pc=0x0c074606u; return 0; }
fr[4]=0;
goto P_0c074608;
P_0c074608: /* original fe47, guest PC 0x0c074608 */
if(!s->budget--) { s->failed_pc=0x0c074608u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c07460a;
P_0c07460a: /* original 7008, guest PC 0x0c07460a */
if(!s->budget--) { s->failed_pc=0x0c07460au; return 0; }
r[0]+=0x00000008u;
goto P_0c07460c;
P_0c07460c: /* original fe47, guest PC 0x0c07460c */
if(!s->budget--) { s->failed_pc=0x0c07460cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c07460e;
P_0c07460e: /* original 70f8, guest PC 0x0c07460e */
if(!s->budget--) { s->failed_pc=0x0c07460eu; return 0; }
r[0]+=0xfffffff8u;
goto P_0c074610;
P_0c074610: /* original fd47, guest PC 0x0c074610 */
if(!s->budget--) { s->failed_pc=0x0c074610u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c074612;
P_0c074612: /* original 7008, guest PC 0x0c074612 */
if(!s->budget--) { s->failed_pc=0x0c074612u; return 0; }
r[0]+=0x00000008u;
goto P_0c074614;
P_0c074614: /* original fd47, guest PC 0x0c074614 */
if(!s->budget--) { s->failed_pc=0x0c074614u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c074616;
P_0c074616: /* original fef9, guest PC 0x0c074616 */
if(!s->budget--) { s->failed_pc=0x0c074616u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c074618;
P_0c074618: /* original fff9, guest PC 0x0c074618 */
if(!s->budget--) { s->failed_pc=0x0c074618u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07461a;
P_0c07461a: /* original 6df6, guest PC 0x0c07461a */
if(!s->budget--) { s->failed_pc=0x0c07461au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07461c;
P_0c07461c: /* original 000b, guest PC 0x0c07461c */
if(!s->budget--) { s->failed_pc=0x0c07461cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07461e: /* original 6ef6, guest PC 0x0c07461e */
if(!s->budget--) { s->failed_pc=0x0c07461eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c074620u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c074620u; return 0; } return 1;
P_0c074634: /* original 2fe6, guest PC 0x0c074634 */
if(!s->budget--) { s->failed_pc=0x0c074634u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c074636;
P_0c074636: /* original 6e43, guest PC 0x0c074636 */
if(!s->budget--) { s->failed_pc=0x0c074636u; return 0; }
r[14]=r[4];
goto P_0c074638;
P_0c074638: /* original e05c, guest PC 0x0c074638 */
if(!s->budget--) { s->failed_pc=0x0c074638u; return 0; }
r[0]=0x0000005cu;
goto P_0c07463a;
P_0c07463a: /* original 2fd6, guest PC 0x0c07463a */
if(!s->budget--) { s->failed_pc=0x0c07463au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07463c;
P_0c07463c: /* original f4e6, guest PC 0x0c07463c */
if(!s->budget--) { s->failed_pc=0x0c07463cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c07463e;
P_0c07463e: /* original c74b, guest PC 0x0c07463e */
if(!s->budget--) { s->failed_pc=0x0c07463eu; return 0; }
r[0]=code_base|0x0007476cu;
goto P_0c074640;
P_0c074640: /* original 6d53, guest PC 0x0c074640 */
if(!s->budget--) { s->failed_pc=0x0c074640u; return 0; }
r[13]=r[5];
goto P_0c074642;
P_0c074642: /* original d54b, guest PC 0x0c074642 */
if(!s->budget--) { s->failed_pc=0x0c074642u; return 0; }
r[5]=read(ram,0x0c074770u,4);
goto P_0c074644;
P_0c074644: /* original f508, guest PC 0x0c074644 */
if(!s->budget--) { s->failed_pc=0x0c074644u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c074646;
P_0c074646: /* original e01c, guest PC 0x0c074646 */
if(!s->budget--) { s->failed_pc=0x0c074646u; return 0; }
r[0]=0x0000001cu;
goto P_0c074648;
P_0c074648: /* original 005c, guest PC 0x0c074648 */
if(!s->budget--) { s->failed_pc=0x0c074648u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07464a;
P_0c07464a: /* original e40f, guest PC 0x0c07464a */
if(!s->budget--) { s->failed_pc=0x0c07464au; return 0; }
r[4]=0x0000000fu;
goto P_0c07464c;
P_0c07464c: /* original 4f22, guest PC 0x0c07464c */
if(!s->budget--) { s->failed_pc=0x0c07464cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07464e;
P_0c07464e: /* original 600c, guest PC 0x0c07464e */
if(!s->budget--) { s->failed_pc=0x0c07464eu; return 0; }
r[0]=r[0]&255u;
goto P_0c074650;
P_0c074650: /* original 2409, guest PC 0x0c074650 */
if(!s->budget--) { s->failed_pc=0x0c074650u; return 0; }
r[4]&=r[0];
goto P_0c074652;
P_0c074652: /* original 6043, guest PC 0x0c074652 */
if(!s->budget--) { s->failed_pc=0x0c074652u; return 0; }
r[0]=r[4];
goto P_0c074654;
P_0c074654: /* original 880d, guest PC 0x0c074654 */
if(!s->budget--) { s->failed_pc=0x0c074654u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c074656;
P_0c074656: /* original 7ff4, guest PC 0x0c074656 */
if(!s->budget--) { s->failed_pc=0x0c074656u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c074658;
P_0c074658: /* original 8f3b, guest PC 0x0c074658 */
if(!s->budget--) { s->failed_pc=0x0c074658u; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[5]+4,4);
if(!cond) { goto P_0c0746d2; }
goto P_0c07465c;
P_0c07465a: /* original 5551, guest PC 0x0c07465a */
if(!s->budget--) { s->failed_pc=0x0c07465au; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c07465c;
P_0c07465c: /* original f545, guest PC 0x0c07465c */
if(!s->budget--) { s->failed_pc=0x0c07465cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c07465e;
P_0c07465e: /* original 8938, guest PC 0x0c07465e */
if(!s->budget--) { s->failed_pc=0x0c07465eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0746d2; }
goto P_0c074660;
P_0c074660: /* original d344, guest PC 0x0c074660 */
if(!s->budget--) { s->failed_pc=0x0c074660u; return 0; }
r[3]=read(ram,0x0c074774u,4);
goto P_0c074662;
P_0c074662: /* original 2538, guest PC 0x0c074662 */
if(!s->budget--) { s->failed_pc=0x0c074662u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c074664;
P_0c074664: /* original 8b35, guest PC 0x0c074664 */
if(!s->budget--) { s->failed_pc=0x0c074664u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0746d2; }
goto P_0c074666;
P_0c074666: /* original f451, guest PC 0x0c074666 */
if(!s->budget--) { s->failed_pc=0x0c074666u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c074668;
P_0c074668: /* original e008, guest PC 0x0c074668 */
if(!s->budget--) { s->failed_pc=0x0c074668u; return 0; }
r[0]=0x00000008u;
goto P_0c07466a;
P_0c07466a: /* original ff47, guest PC 0x0c07466a */
if(!s->budget--) { s->failed_pc=0x0c07466au; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c07466c;
P_0c07466c: /* original e010, guest PC 0x0c07466c */
if(!s->budget--) { s->failed_pc=0x0c07466cu; return 0; }
r[0]=0x00000010u;
goto P_0c07466e;
P_0c07466e: /* original f5d6, guest PC 0x0c07466e */
if(!s->budget--) { s->failed_pc=0x0c07466eu; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c074670;
P_0c074670: /* original f3e6, guest PC 0x0c074670 */
if(!s->budget--) { s->failed_pc=0x0c074670u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c074672;
P_0c074672: /* original e018, guest PC 0x0c074672 */
if(!s->budget--) { s->failed_pc=0x0c074672u; return 0; }
r[0]=0x00000018u;
goto P_0c074674;
P_0c074674: /* original d340, guest PC 0x0c074674 */
if(!s->budget--) { s->failed_pc=0x0c074674u; return 0; }
r[3]=read(ram,0x0c074778u,4);
goto P_0c074676;
P_0c074676: /* original f531, guest PC 0x0c074676 */
if(!s->budget--) { s->failed_pc=0x0c074676u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c074678;
P_0c074678: /* original f4d6, guest PC 0x0c074678 */
if(!s->budget--) { s->failed_pc=0x0c074678u; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c07467a;
P_0c07467a: /* original f3e6, guest PC 0x0c07467a */
if(!s->budget--) { s->failed_pc=0x0c07467au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c07467c;
P_0c07467c: /* original 430b, guest PC 0x0c07467c */
if(!s->budget--) { s->failed_pc=0x0c07467cu; return 0; }
target=r[3];
r[16]=code_base|0x0c074680u;
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c074680u) { target=s->pc; goto dispatch; }
goto P_0c074680;
P_0c07467e: /* original f431, guest PC 0x0c07467e */
if(!s->budget--) { s->failed_pc=0x0c07467eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c074680;
P_0c074680: /* original 640f, guest PC 0x0c074680 */
if(!s->budget--) { s->failed_pc=0x0c074680u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c074682;
P_0c074682: /* original 62f3, guest PC 0x0c074682 */
if(!s->budget--) { s->failed_pc=0x0c074682u; return 0; }
r[2]=r[15];
goto P_0c074684;
P_0c074684: /* original c73d, guest PC 0x0c074684 */
if(!s->budget--) { s->failed_pc=0x0c074684u; return 0; }
r[0]=code_base|0x0007477cu;
goto P_0c074686;
P_0c074686: /* original 445a, guest PC 0x0c074686 */
if(!s->budget--) { s->failed_pc=0x0c074686u; return 0; }
r[53]=r[4];
goto P_0c074688;
P_0c074688: /* original 7204, guest PC 0x0c074688 */
if(!s->budget--) { s->failed_pc=0x0c074688u; return 0; }
r[2]+=0x00000004u;
goto P_0c07468a;
P_0c07468a: /* original 63f3, guest PC 0x0c07468a */
if(!s->budget--) { s->failed_pc=0x0c07468au; return 0; }
r[3]=r[15];
goto P_0c07468c;
P_0c07468c: /* original f0fd, guest PC 0x0c07468c */
if(!s->budget--) { s->failed_pc=0x0c07468cu; return 0; }
vf3_fpu_fsca(r[53],fr+0);
goto P_0c07468e;
P_0c07468e: /* original f30a, guest PC 0x0c07468e */
if(!s->budget--) { s->failed_pc=0x0c07468eu; return 0; }
vf3_matrix_store(s,ram,0,r[3]);
goto P_0c074690;
P_0c074690: /* original f21a, guest PC 0x0c074690 */
if(!s->budget--) { s->failed_pc=0x0c074690u; return 0; }
vf3_matrix_store(s,ram,1,r[2]);
goto P_0c074692;
P_0c074692: /* original f308, guest PC 0x0c074692 */
if(!s->budget--) { s->failed_pc=0x0c074692u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c074694;
P_0c074694: /* original e008, guest PC 0x0c074694 */
if(!s->budget--) { s->failed_pc=0x0c074694u; return 0; }
r[0]=0x00000008u;
goto P_0c074696;
P_0c074696: /* original f4f6, guest PC 0x0c074696 */
if(!s->budget--) { s->failed_pc=0x0c074696u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c074698;
P_0c074698: /* original e004, guest PC 0x0c074698 */
if(!s->budget--) { s->failed_pc=0x0c074698u; return 0; }
r[0]=0x00000004u;
goto P_0c07469a;
P_0c07469a: /* original f2f8, guest PC 0x0c07469a */
if(!s->budget--) { s->failed_pc=0x0c07469au; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c07469c;
P_0c07469c: /* original f432, guest PC 0x0c07469c */
if(!s->budget--) { s->failed_pc=0x0c07469cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c07469e;
P_0c07469e: /* original f14c, guest PC 0x0c07469e */
if(!s->budget--) { s->failed_pc=0x0c07469eu; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c0746a0;
P_0c0746a0: /* original f122, guest PC 0x0c0746a0 */
if(!s->budget--) { s->failed_pc=0x0c0746a0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[2],r[18],'*');
goto P_0c0746a2;
P_0c0746a2: /* original ff1a, guest PC 0x0c0746a2 */
if(!s->budget--) { s->failed_pc=0x0c0746a2u; return 0; }
vf3_matrix_store(s,ram,1,r[15]);
goto P_0c0746a4;
P_0c0746a4: /* original f2f6, guest PC 0x0c0746a4 */
if(!s->budget--) { s->failed_pc=0x0c0746a4u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0746a6;
P_0c0746a6: /* original e004, guest PC 0x0c0746a6 */
if(!s->budget--) { s->failed_pc=0x0c0746a6u; return 0; }
r[0]=0x00000004u;
goto P_0c0746a8;
P_0c0746a8: /* original f422, guest PC 0x0c0746a8 */
if(!s->budget--) { s->failed_pc=0x0c0746a8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'*');
goto P_0c0746aa;
P_0c0746aa: /* original ff47, guest PC 0x0c0746aa */
if(!s->budget--) { s->failed_pc=0x0c0746aau; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0746ac;
P_0c0746ac: /* original 905a, guest PC 0x0c0746ac */
if(!s->budget--) { s->failed_pc=0x0c0746acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074764u,2);
goto P_0c0746ae;
P_0c0746ae: /* original f3f8, guest PC 0x0c0746ae */
if(!s->budget--) { s->failed_pc=0x0c0746aeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0746b0;
P_0c0746b0: /* original fe37, guest PC 0x0c0746b0 */
if(!s->budget--) { s->failed_pc=0x0c0746b0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0746b2;
P_0c0746b2: /* original e004, guest PC 0x0c0746b2 */
if(!s->budget--) { s->failed_pc=0x0c0746b2u; return 0; }
r[0]=0x00000004u;
goto P_0c0746b4;
P_0c0746b4: /* original f3f6, guest PC 0x0c0746b4 */
if(!s->budget--) { s->failed_pc=0x0c0746b4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0746b6;
P_0c0746b6: /* original 9056, guest PC 0x0c0746b6 */
if(!s->budget--) { s->failed_pc=0x0c0746b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074766u,2);
goto P_0c0746b8;
P_0c0746b8: /* original fe37, guest PC 0x0c0746b8 */
if(!s->budget--) { s->failed_pc=0x0c0746b8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0746ba;
P_0c0746ba: /* original f3f8, guest PC 0x0c0746ba */
if(!s->budget--) { s->failed_pc=0x0c0746bau; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0746bc;
P_0c0746bc: /* original 9052, guest PC 0x0c0746bc */
if(!s->budget--) { s->failed_pc=0x0c0746bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074764u,2);
goto P_0c0746be;
P_0c0746be: /* original f34d, guest PC 0x0c0746be */
if(!s->budget--) { s->failed_pc=0x0c0746beu; return 0; }
fr[3]^=0x80000000u;
goto P_0c0746c0;
P_0c0746c0: /* original fd37, guest PC 0x0c0746c0 */
if(!s->budget--) { s->failed_pc=0x0c0746c0u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0746c2;
P_0c0746c2: /* original e004, guest PC 0x0c0746c2 */
if(!s->budget--) { s->failed_pc=0x0c0746c2u; return 0; }
r[0]=0x00000004u;
goto P_0c0746c4;
P_0c0746c4: /* original f3f6, guest PC 0x0c0746c4 */
if(!s->budget--) { s->failed_pc=0x0c0746c4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0746c6;
P_0c0746c6: /* original 65d3, guest PC 0x0c0746c6 */
if(!s->budget--) { s->failed_pc=0x0c0746c6u; return 0; }
r[5]=r[13];
goto P_0c0746c8;
P_0c0746c8: /* original 904d, guest PC 0x0c0746c8 */
if(!s->budget--) { s->failed_pc=0x0c0746c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074766u,2);
goto P_0c0746ca;
P_0c0746ca: /* original f34d, guest PC 0x0c0746ca */
if(!s->budget--) { s->failed_pc=0x0c0746cau; return 0; }
fr[3]^=0x80000000u;
goto P_0c0746cc;
P_0c0746cc: /* original fd37, guest PC 0x0c0746cc */
if(!s->budget--) { s->failed_pc=0x0c0746ccu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0746ce;
P_0c0746ce: /* original b0f7, guest PC 0x0c0746ce */
if(!s->budget--) { s->failed_pc=0x0c0746ceu; return 0; }
target=code_base|0x0c0748c0u; r[16]=code_base|0x0c0746d2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0746d2u) { target=s->pc; goto dispatch; }
goto P_0c0746d2;
P_0c0746d0: /* original 64e3, guest PC 0x0c0746d0 */
if(!s->budget--) { s->failed_pc=0x0c0746d0u; return 0; }
r[4]=r[14];
goto P_0c0746d2;
P_0c0746d2: /* original 7f0c, guest PC 0x0c0746d2 */
if(!s->budget--) { s->failed_pc=0x0c0746d2u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0746d4;
P_0c0746d4: /* original 4f26, guest PC 0x0c0746d4 */
if(!s->budget--) { s->failed_pc=0x0c0746d4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0746d6;
P_0c0746d6: /* original 6df6, guest PC 0x0c0746d6 */
if(!s->budget--) { s->failed_pc=0x0c0746d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0746d8;
P_0c0746d8: /* original 000b, guest PC 0x0c0746d8 */
if(!s->budget--) { s->failed_pc=0x0c0746d8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0746da: /* original 6ef6, guest PC 0x0c0746da */
if(!s->budget--) { s->failed_pc=0x0c0746dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0746dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0746dcu; return 0; } return 1;
P_0c074702: /* original 9030, guest PC 0x0c074702 */
if(!s->budget--) { s->failed_pc=0x0c074702u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074766u,2);
goto P_0c074704;
P_0c074704: /* original 9630, guest PC 0x0c074704 */
if(!s->budget--) { s->failed_pc=0x0c074704u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074768u,2);
goto P_0c074706;
P_0c074706: /* original f446, guest PC 0x0c074706 */
if(!s->budget--) { s->failed_pc=0x0c074706u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c074708;
P_0c074708: /* original 7008, guest PC 0x0c074708 */
if(!s->budget--) { s->failed_pc=0x0c074708u; return 0; }
r[0]+=0x00000008u;
goto P_0c07470a;
P_0c07470a: /* original f546, guest PC 0x0c07470a */
if(!s->budget--) { s->failed_pc=0x0c07470au; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c07470c;
P_0c07470c: /* original 70dc, guest PC 0x0c07470c */
if(!s->budget--) { s->failed_pc=0x0c07470cu; return 0; }
r[0]+=0xffffffdcu;
goto P_0c07470e;
P_0c07470e: /* original 054e, guest PC 0x0c07470e */
if(!s->budget--) { s->failed_pc=0x0c07470eu; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c074710;
P_0c074710: /* original 902b, guest PC 0x0c074710 */
if(!s->budget--) { s->failed_pc=0x0c074710u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07476au,2);
goto P_0c074712;
P_0c074712: /* original 365c, guest PC 0x0c074712 */
if(!s->budget--) { s->failed_pc=0x0c074712u; return 0; }
r[6]+=r[5];
goto P_0c074714;
P_0c074714: /* original f346, guest PC 0x0c074714 */
if(!s->budget--) { s->failed_pc=0x0c074714u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c074716;
P_0c074716: /* original 3560, guest PC 0x0c074716 */
if(!s->budget--) { s->failed_pc=0x0c074716u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c074718;
P_0c074718: /* original f340, guest PC 0x0c074718 */
if(!s->budget--) { s->failed_pc=0x0c074718u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c07471a;
P_0c07471a: /* original f437, guest PC 0x0c07471a */
if(!s->budget--) { s->failed_pc=0x0c07471au; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07471c;
P_0c07471c: /* original 7008, guest PC 0x0c07471c */
if(!s->budget--) { s->failed_pc=0x0c07471cu; return 0; }
r[0]+=0x00000008u;
goto P_0c07471e;
P_0c07471e: /* original f246, guest PC 0x0c07471e */
if(!s->budget--) { s->failed_pc=0x0c07471eu; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c074720;
P_0c074720: /* original f250, guest PC 0x0c074720 */
if(!s->budget--) { s->failed_pc=0x0c074720u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c074722;
P_0c074722: /* original 8d0a, guest PC 0x0c074722 */
if(!s->budget--) { s->failed_pc=0x0c074722u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,2,r[4]+r[0]);
if(cond) { goto P_0c07473a; }
goto P_0c074726;
P_0c074724: /* original f427, guest PC 0x0c074724 */
if(!s->budget--) { s->failed_pc=0x0c074724u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c074726;
P_0c074726: /* original e008, guest PC 0x0c074726 */
if(!s->budget--) { s->failed_pc=0x0c074726u; return 0; }
r[0]=0x00000008u;
goto P_0c074728;
P_0c074728: /* original f358, guest PC 0x0c074728 */
if(!s->budget--) { s->failed_pc=0x0c074728u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c07472a;
P_0c07472a: /* original f340, guest PC 0x0c07472a */
if(!s->budget--) { s->failed_pc=0x0c07472au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c07472c;
P_0c07472c: /* original f53a, guest PC 0x0c07472c */
if(!s->budget--) { s->failed_pc=0x0c07472cu; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c07472e;
P_0c07472e: /* original f256, guest PC 0x0c07472e */
if(!s->budget--) { s->failed_pc=0x0c07472eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c074730;
P_0c074730: /* original f250, guest PC 0x0c074730 */
if(!s->budget--) { s->failed_pc=0x0c074730u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c074732;
P_0c074732: /* original f527, guest PC 0x0c074732 */
if(!s->budget--) { s->failed_pc=0x0c074732u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c074734;
P_0c074734: /* original 750c, guest PC 0x0c074734 */
if(!s->budget--) { s->failed_pc=0x0c074734u; return 0; }
r[5]+=0x0000000cu;
goto P_0c074736;
P_0c074736: /* original 3560, guest PC 0x0c074736 */
if(!s->budget--) { s->failed_pc=0x0c074736u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c074738;
P_0c074738: /* original 8bf5, guest PC 0x0c074738 */
if(!s->budget--) { s->failed_pc=0x0c074738u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074726; }
goto P_0c07473a;
P_0c07473a: /* original 000b, guest PC 0x0c07473a */
if(!s->budget--) { s->failed_pc=0x0c07473au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07473c: /* original 0009, guest PC 0x0c07473c */
if(!s->budget--) { s->failed_pc=0x0c07473cu; return 0; }
if(!vf3_matrix_family(0x0c07473eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07473eu; return 0; } return 1;
P_0c0747b2: /* original 4f22, guest PC 0x0c0747b2 */
if(!s->budget--) { s->failed_pc=0x0c0747b2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0747b4;
P_0c0747b4: /* original 7ff8, guest PC 0x0c0747b4 */
if(!s->budget--) { s->failed_pc=0x0c0747b4u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0747b6;
P_0c0747b6: /* original 2f42, guest PC 0x0c0747b6 */
if(!s->budget--) { s->failed_pc=0x0c0747b6u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0747b8;
P_0c0747b8: /* original 1f51, guest PC 0x0c0747b8 */
if(!s->budget--) { s->failed_pc=0x0c0747b8u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0747ba;
P_0c0747ba: /* original d140, guest PC 0x0c0747ba */
if(!s->budget--) { s->failed_pc=0x0c0747bau; return 0; }
r[1]=read(ram,0x0c0748bcu,4);
goto P_0c0747bc;
P_0c0747bc: /* original d33e, guest PC 0x0c0747bc */
if(!s->budget--) { s->failed_pc=0x0c0747bcu; return 0; }
r[3]=read(ram,0x0c0748b8u,4);
goto P_0c0747be;
P_0c0747be: /* original 6212, guest PC 0x0c0747be */
if(!s->budget--) { s->failed_pc=0x0c0747beu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0747c0;
P_0c0747c0: /* original 2238, guest PC 0x0c0747c0 */
if(!s->budget--) { s->failed_pc=0x0c0747c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0747c2;
P_0c0747c2: /* original 8b05, guest PC 0x0c0747c2 */
if(!s->budget--) { s->failed_pc=0x0c0747c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0747d0; }
goto P_0c0747c4;
P_0c0747c4: /* original 55f1, guest PC 0x0c0747c4 */
if(!s->budget--) { s->failed_pc=0x0c0747c4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0747c6;
P_0c0747c6: /* original b007, guest PC 0x0c0747c6 */
if(!s->budget--) { s->failed_pc=0x0c0747c6u; return 0; }
target=code_base|0x0c0747d8u; r[16]=code_base|0x0c0747cau;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0747cau) { target=s->pc; goto dispatch; }
goto P_0c0747ca;
P_0c0747c8: /* original 64f2, guest PC 0x0c0747c8 */
if(!s->budget--) { s->failed_pc=0x0c0747c8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0747ca;
P_0c0747ca: /* original 65f2, guest PC 0x0c0747ca */
if(!s->budget--) { s->failed_pc=0x0c0747cau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0747cc;
P_0c0747cc: /* original b004, guest PC 0x0c0747cc */
if(!s->budget--) { s->failed_pc=0x0c0747ccu; return 0; }
target=code_base|0x0c0747d8u; r[16]=code_base|0x0c0747d0u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0747d0u) { target=s->pc; goto dispatch; }
goto P_0c0747d0;
P_0c0747ce: /* original 54f1, guest PC 0x0c0747ce */
if(!s->budget--) { s->failed_pc=0x0c0747ceu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0747d0;
P_0c0747d0: /* original 7f08, guest PC 0x0c0747d0 */
if(!s->budget--) { s->failed_pc=0x0c0747d0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0747d2;
P_0c0747d2: /* original 4f26, guest PC 0x0c0747d2 */
if(!s->budget--) { s->failed_pc=0x0c0747d2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0747d4;
P_0c0747d4: /* original 000b, guest PC 0x0c0747d4 */
if(!s->budget--) { s->failed_pc=0x0c0747d4u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0747d6: /* original 0009, guest PC 0x0c0747d6 */
if(!s->budget--) { s->failed_pc=0x0c0747d6u; return 0; }
return vf3_matrix_family(0x0c0747d8u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
