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
int vf3_away_batch11_adapter_25(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c072ec2u: goto P_0c072ec2;
case 0x0c072ec4u: goto P_0c072ec4;
case 0x0c072ec6u: goto P_0c072ec6;
case 0x0c072ec8u: goto P_0c072ec8;
case 0x0c072ecau: goto P_0c072eca;
case 0x0c072eccu: goto P_0c072ecc;
case 0x0c072eceu: goto P_0c072ece;
case 0x0c072ed0u: goto P_0c072ed0;
case 0x0c072ed2u: goto P_0c072ed2;
case 0x0c072ed4u: goto P_0c072ed4;
case 0x0c072ed6u: goto P_0c072ed6;
case 0x0c072ed8u: goto P_0c072ed8;
case 0x0c072edau: goto P_0c072eda;
case 0x0c072edcu: goto P_0c072edc;
case 0x0c072edeu: goto P_0c072ede;
case 0x0c072ee0u: goto P_0c072ee0;
case 0x0c072ee2u: goto P_0c072ee2;
case 0x0c072ee4u: goto P_0c072ee4;
case 0x0c072ee6u: goto P_0c072ee6;
case 0x0c072ee8u: goto P_0c072ee8;
case 0x0c0730ecu: goto P_0c0730ec;
case 0x0c0730eeu: goto P_0c0730ee;
case 0x0c0730f0u: goto P_0c0730f0;
case 0x0c0730f2u: goto P_0c0730f2;
case 0x0c0730f4u: goto P_0c0730f4;
case 0x0c0730f6u: goto P_0c0730f6;
case 0x0c0730f8u: goto P_0c0730f8;
case 0x0c0730fau: goto P_0c0730fa;
case 0x0c0730fcu: goto P_0c0730fc;
case 0x0c0730feu: goto P_0c0730fe;
case 0x0c073100u: goto P_0c073100;
case 0x0c073102u: goto P_0c073102;
case 0x0c073104u: goto P_0c073104;
case 0x0c073106u: goto P_0c073106;
case 0x0c073108u: goto P_0c073108;
case 0x0c07310au: goto P_0c07310a;
case 0x0c07310cu: goto P_0c07310c;
case 0x0c07310eu: goto P_0c07310e;
case 0x0c073110u: goto P_0c073110;
case 0x0c073112u: goto P_0c073112;
case 0x0c073114u: goto P_0c073114;
case 0x0c073116u: goto P_0c073116;
case 0x0c073118u: goto P_0c073118;
case 0x0c07311au: goto P_0c07311a;
case 0x0c07311cu: goto P_0c07311c;
case 0x0c07311eu: goto P_0c07311e;
case 0x0c073120u: goto P_0c073120;
case 0x0c073122u: goto P_0c073122;
case 0x0c073124u: goto P_0c073124;
case 0x0c073126u: goto P_0c073126;
case 0x0c073128u: goto P_0c073128;
case 0x0c07312au: goto P_0c07312a;
case 0x0c07312cu: goto P_0c07312c;
case 0x0c07312eu: goto P_0c07312e;
case 0x0c073130u: goto P_0c073130;
case 0x0c073132u: goto P_0c073132;
case 0x0c073134u: goto P_0c073134;
case 0x0c073136u: goto P_0c073136;
case 0x0c073138u: goto P_0c073138;
case 0x0c07313au: goto P_0c07313a;
case 0x0c07313cu: goto P_0c07313c;
case 0x0c07313eu: goto P_0c07313e;
case 0x0c073140u: goto P_0c073140;
case 0x0c073142u: goto P_0c073142;
case 0x0c073144u: goto P_0c073144;
case 0x0c073146u: goto P_0c073146;
case 0x0c073148u: goto P_0c073148;
case 0x0c07314au: goto P_0c07314a;
case 0x0c07314cu: goto P_0c07314c;
case 0x0c07314eu: goto P_0c07314e;
case 0x0c073150u: goto P_0c073150;
case 0x0c073152u: goto P_0c073152;
case 0x0c073154u: goto P_0c073154;
case 0x0c073156u: goto P_0c073156;
case 0x0c073158u: goto P_0c073158;
case 0x0c07315au: goto P_0c07315a;
case 0x0c07315cu: goto P_0c07315c;
case 0x0c07315eu: goto P_0c07315e;
case 0x0c073160u: goto P_0c073160;
case 0x0c073162u: goto P_0c073162;
case 0x0c073164u: goto P_0c073164;
case 0x0c073166u: goto P_0c073166;
case 0x0c073168u: goto P_0c073168;
case 0x0c07316au: goto P_0c07316a;
case 0x0c07316cu: goto P_0c07316c;
case 0x0c07316eu: goto P_0c07316e;
case 0x0c073170u: goto P_0c073170;
case 0x0c073172u: goto P_0c073172;
case 0x0c073174u: goto P_0c073174;
case 0x0c073176u: goto P_0c073176;
case 0x0c073178u: goto P_0c073178;
case 0x0c07317au: goto P_0c07317a;
case 0x0c07317cu: goto P_0c07317c;
case 0x0c07317eu: goto P_0c07317e;
case 0x0c073180u: goto P_0c073180;
case 0x0c073182u: goto P_0c073182;
case 0x0c073184u: goto P_0c073184;
case 0x0c073186u: goto P_0c073186;
case 0x0c073188u: goto P_0c073188;
case 0x0c07318au: goto P_0c07318a;
case 0x0c07318cu: goto P_0c07318c;
case 0x0c07318eu: goto P_0c07318e;
case 0x0c073190u: goto P_0c073190;
case 0x0c073192u: goto P_0c073192;
case 0x0c073194u: goto P_0c073194;
case 0x0c073196u: goto P_0c073196;
case 0x0c073198u: goto P_0c073198;
case 0x0c0731b4u: goto P_0c0731b4;
case 0x0c0731b6u: goto P_0c0731b6;
case 0x0c0731b8u: goto P_0c0731b8;
case 0x0c0731bau: goto P_0c0731ba;
case 0x0c0731bcu: goto P_0c0731bc;
case 0x0c0731beu: goto P_0c0731be;
case 0x0c0731c0u: goto P_0c0731c0;
case 0x0c0731c2u: goto P_0c0731c2;
case 0x0c0731c4u: goto P_0c0731c4;
case 0x0c0731c6u: goto P_0c0731c6;
case 0x0c0731c8u: goto P_0c0731c8;
case 0x0c0731cau: goto P_0c0731ca;
case 0x0c0731ccu: goto P_0c0731cc;
case 0x0c0731ceu: goto P_0c0731ce;
case 0x0c0731d0u: goto P_0c0731d0;
case 0x0c0731d2u: goto P_0c0731d2;
case 0x0c0731d4u: goto P_0c0731d4;
case 0x0c0731d6u: goto P_0c0731d6;
case 0x0c0731d8u: goto P_0c0731d8;
case 0x0c0731dau: goto P_0c0731da;
case 0x0c0731dcu: goto P_0c0731dc;
case 0x0c0731deu: goto P_0c0731de;
case 0x0c0731e0u: goto P_0c0731e0;
case 0x0c0731e2u: goto P_0c0731e2;
case 0x0c0731e4u: goto P_0c0731e4;
case 0x0c0731e6u: goto P_0c0731e6;
case 0x0c0731e8u: goto P_0c0731e8;
case 0x0c0731eau: goto P_0c0731ea;
case 0x0c0731ecu: goto P_0c0731ec;
case 0x0c0731eeu: goto P_0c0731ee;
case 0x0c0731f0u: goto P_0c0731f0;
case 0x0c0731f2u: goto P_0c0731f2;
case 0x0c0731f4u: goto P_0c0731f4;
case 0x0c0731f6u: goto P_0c0731f6;
case 0x0c0731f8u: goto P_0c0731f8;
case 0x0c0731fau: goto P_0c0731fa;
case 0x0c0731fcu: goto P_0c0731fc;
case 0x0c0731feu: goto P_0c0731fe;
case 0x0c073200u: goto P_0c073200;
case 0x0c073202u: goto P_0c073202;
case 0x0c073204u: goto P_0c073204;
case 0x0c073206u: goto P_0c073206;
case 0x0c073208u: goto P_0c073208;
case 0x0c07320au: goto P_0c07320a;
case 0x0c07320cu: goto P_0c07320c;
case 0x0c07320eu: goto P_0c07320e;
case 0x0c073210u: goto P_0c073210;
case 0x0c073212u: goto P_0c073212;
case 0x0c073214u: goto P_0c073214;
case 0x0c073216u: goto P_0c073216;
case 0x0c073218u: goto P_0c073218;
case 0x0c07321au: goto P_0c07321a;
case 0x0c07321cu: goto P_0c07321c;
case 0x0c07321eu: goto P_0c07321e;
case 0x0c073220u: goto P_0c073220;
case 0x0c073222u: goto P_0c073222;
case 0x0c073224u: goto P_0c073224;
case 0x0c073226u: goto P_0c073226;
case 0x0c073228u: goto P_0c073228;
case 0x0c07322au: goto P_0c07322a;
case 0x0c07322cu: goto P_0c07322c;
case 0x0c07322eu: goto P_0c07322e;
case 0x0c073230u: goto P_0c073230;
case 0x0c073232u: goto P_0c073232;
case 0x0c073234u: goto P_0c073234;
case 0x0c073236u: goto P_0c073236;
case 0x0c073238u: goto P_0c073238;
case 0x0c07323au: goto P_0c07323a;
case 0x0c07323cu: goto P_0c07323c;
case 0x0c07323eu: goto P_0c07323e;
case 0x0c073240u: goto P_0c073240;
case 0x0c073242u: goto P_0c073242;
case 0x0c073244u: goto P_0c073244;
case 0x0c073246u: goto P_0c073246;
case 0x0c073248u: goto P_0c073248;
case 0x0c07324au: goto P_0c07324a;
case 0x0c07324cu: goto P_0c07324c;
case 0x0c07324eu: goto P_0c07324e;
case 0x0c073250u: goto P_0c073250;
case 0x0c073252u: goto P_0c073252;
case 0x0c073254u: goto P_0c073254;
case 0x0c073256u: goto P_0c073256;
case 0x0c073258u: goto P_0c073258;
case 0x0c07325au: goto P_0c07325a;
case 0x0c07325cu: goto P_0c07325c;
case 0x0c07325eu: goto P_0c07325e;
case 0x0c073260u: goto P_0c073260;
case 0x0c073262u: goto P_0c073262;
case 0x0c0736d2u: goto P_0c0736d2;
case 0x0c0736d4u: goto P_0c0736d4;
case 0x0c0736d6u: goto P_0c0736d6;
case 0x0c0736d8u: goto P_0c0736d8;
case 0x0c0736dau: goto P_0c0736da;
case 0x0c0736dcu: goto P_0c0736dc;
case 0x0c0736deu: goto P_0c0736de;
case 0x0c0736e0u: goto P_0c0736e0;
case 0x0c0736e2u: goto P_0c0736e2;
case 0x0c0736e4u: goto P_0c0736e4;
case 0x0c0736e6u: goto P_0c0736e6;
case 0x0c0736e8u: goto P_0c0736e8;
case 0x0c0736eau: goto P_0c0736ea;
case 0x0c0736ecu: goto P_0c0736ec;
case 0x0c0736eeu: goto P_0c0736ee;
case 0x0c0736f0u: goto P_0c0736f0;
case 0x0c0736f2u: goto P_0c0736f2;
case 0x0c0736f4u: goto P_0c0736f4;
case 0x0c0736f6u: goto P_0c0736f6;
case 0x0c0736f8u: goto P_0c0736f8;
case 0x0c0736fau: goto P_0c0736fa;
case 0x0c0736fcu: goto P_0c0736fc;
case 0x0c0736feu: goto P_0c0736fe;
case 0x0c073700u: goto P_0c073700;
case 0x0c073702u: goto P_0c073702;
case 0x0c073704u: goto P_0c073704;
case 0x0c073706u: goto P_0c073706;
case 0x0c073708u: goto P_0c073708;
case 0x0c07370au: goto P_0c07370a;
case 0x0c07370cu: goto P_0c07370c;
case 0x0c07370eu: goto P_0c07370e;
case 0x0c073710u: goto P_0c073710;
case 0x0c073712u: goto P_0c073712;
case 0x0c073714u: goto P_0c073714;
case 0x0c073716u: goto P_0c073716;
case 0x0c073718u: goto P_0c073718;
case 0x0c07371au: goto P_0c07371a;
case 0x0c07371cu: goto P_0c07371c;
case 0x0c07371eu: goto P_0c07371e;
case 0x0c073720u: goto P_0c073720;
case 0x0c073722u: goto P_0c073722;
case 0x0c073724u: goto P_0c073724;
case 0x0c073726u: goto P_0c073726;
case 0x0c073728u: goto P_0c073728;
case 0x0c07372au: goto P_0c07372a;
case 0x0c07372cu: goto P_0c07372c;
case 0x0c07372eu: goto P_0c07372e;
case 0x0c073730u: goto P_0c073730;
case 0x0c073732u: goto P_0c073732;
case 0x0c073734u: goto P_0c073734;
case 0x0c073736u: goto P_0c073736;
case 0x0c073738u: goto P_0c073738;
case 0x0c07373au: goto P_0c07373a;
case 0x0c07373cu: goto P_0c07373c;
case 0x0c07373eu: goto P_0c07373e;
case 0x0c073740u: goto P_0c073740;
case 0x0c073742u: goto P_0c073742;
case 0x0c073744u: goto P_0c073744;
case 0x0c073746u: goto P_0c073746;
case 0x0c073748u: goto P_0c073748;
case 0x0c07374au: goto P_0c07374a;
case 0x0c07374cu: goto P_0c07374c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c072ec2: /* original 3473, guest PC 0x0c072ec2 */
if(!s->budget--) { s->failed_pc=0x0c072ec2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[7])!=0);
goto P_0c072ec4;
P_0c072ec4: /* original 8d01, guest PC 0x0c072ec4 */
if(!s->budget--) { s->failed_pc=0x0c072ec4u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[15],4);
r[1]=tmp;
if(cond) { goto P_0c072eca; }
goto P_0c072ec8;
P_0c072ec6: /* original 61f2, guest PC 0x0c072ec6 */
if(!s->budget--) { s->failed_pc=0x0c072ec6u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c072ec8;
P_0c072ec8: /* original 6473, guest PC 0x0c072ec8 */
if(!s->budget--) { s->failed_pc=0x0c072ec8u; return 0; }
r[4]=r[7];
goto P_0c072eca;
P_0c072eca: /* original 3417, guest PC 0x0c072eca */
if(!s->budget--) { s->failed_pc=0x0c072ecau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[1])!=0);
goto P_0c072ecc;
P_0c072ecc: /* original 8b00, guest PC 0x0c072ecc */
if(!s->budget--) { s->failed_pc=0x0c072eccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072ed0; }
goto P_0c072ece;
P_0c072ece: /* original 6413, guest PC 0x0c072ece */
if(!s->budget--) { s->failed_pc=0x0c072eceu; return 0; }
r[4]=r[1];
goto P_0c072ed0;
P_0c072ed0: /* original 2558, guest PC 0x0c072ed0 */
if(!s->budget--) { s->failed_pc=0x0c072ed0u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c072ed2;
P_0c072ed2: /* original 8b04, guest PC 0x0c072ed2 */
if(!s->budget--) { s->failed_pc=0x0c072ed2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072ede; }
goto P_0c072ed4;
P_0c072ed4: /* original 346c, guest PC 0x0c072ed4 */
if(!s->budget--) { s->failed_pc=0x0c072ed4u; return 0; }
r[4]+=r[6];
goto P_0c072ed6;
P_0c072ed6: /* original 3417, guest PC 0x0c072ed6 */
if(!s->budget--) { s->failed_pc=0x0c072ed6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[1])!=0);
goto P_0c072ed8;
P_0c072ed8: /* original 8b05, guest PC 0x0c072ed8 */
if(!s->budget--) { s->failed_pc=0x0c072ed8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c072ee6; }
goto P_0c072eda;
P_0c072eda: /* original a004, guest PC 0x0c072eda */
if(!s->budget--) { s->failed_pc=0x0c072edau; return 0; }
r[4]=r[7];
goto P_0c072ee6;
P_0c072edc: /* original 6473, guest PC 0x0c072edc */
if(!s->budget--) { s->failed_pc=0x0c072edcu; return 0; }
r[4]=r[7];
goto P_0c072ede;
P_0c072ede: /* original 3468, guest PC 0x0c072ede */
if(!s->budget--) { s->failed_pc=0x0c072edeu; return 0; }
r[4]-=r[6];
goto P_0c072ee0;
P_0c072ee0: /* original 3473, guest PC 0x0c072ee0 */
if(!s->budget--) { s->failed_pc=0x0c072ee0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[7])!=0);
goto P_0c072ee2;
P_0c072ee2: /* original 8900, guest PC 0x0c072ee2 */
if(!s->budget--) { s->failed_pc=0x0c072ee2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c072ee6; }
goto P_0c072ee4;
P_0c072ee4: /* original 6413, guest PC 0x0c072ee4 */
if(!s->budget--) { s->failed_pc=0x0c072ee4u; return 0; }
r[4]=r[1];
goto P_0c072ee6;
P_0c072ee6: /* original 000b, guest PC 0x0c072ee6 */
if(!s->budget--) { s->failed_pc=0x0c072ee6u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c072ee8: /* original 6043, guest PC 0x0c072ee8 */
if(!s->budget--) { s->failed_pc=0x0c072ee8u; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c072eeau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c072eeau; return 0; } return 1;
P_0c0730ec: /* original 2fe6, guest PC 0x0c0730ec */
if(!s->budget--) { s->failed_pc=0x0c0730ecu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0730ee;
P_0c0730ee: /* original 6e43, guest PC 0x0c0730ee */
if(!s->budget--) { s->failed_pc=0x0c0730eeu; return 0; }
r[14]=r[4];
goto P_0c0730f0;
P_0c0730f0: /* original 2fd6, guest PC 0x0c0730f0 */
if(!s->budget--) { s->failed_pc=0x0c0730f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0730f2;
P_0c0730f2: /* original 2fc6, guest PC 0x0c0730f2 */
if(!s->budget--) { s->failed_pc=0x0c0730f2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0730f4;
P_0c0730f4: /* original 6c53, guest PC 0x0c0730f4 */
if(!s->budget--) { s->failed_pc=0x0c0730f4u; return 0; }
r[12]=r[5];
goto P_0c0730f6;
P_0c0730f6: /* original 2fb6, guest PC 0x0c0730f6 */
if(!s->budget--) { s->failed_pc=0x0c0730f6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0730f8;
P_0c0730f8: /* original 2fa6, guest PC 0x0c0730f8 */
if(!s->budget--) { s->failed_pc=0x0c0730f8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0730fa;
P_0c0730fa: /* original 4f22, guest PC 0x0c0730fa */
if(!s->budget--) { s->failed_pc=0x0c0730fau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0730fc;
P_0c0730fc: /* original dd27, guest PC 0x0c0730fc */
if(!s->budget--) { s->failed_pc=0x0c0730fcu; return 0; }
r[13]=read(ram,0x0c07319cu,4);
goto P_0c0730fe;
P_0c0730fe: /* original 7ffc, guest PC 0x0c0730fe */
if(!s->budget--) { s->failed_pc=0x0c0730feu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c073100;
P_0c073100: /* original 4d0b, guest PC 0x0c073100 */
if(!s->budget--) { s->failed_pc=0x0c073100u; return 0; }
target=r[13];
r[16]=code_base|0x0c073104u;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073104u) { target=s->pc; goto dispatch; }
goto P_0c073104;
P_0c073102: /* original 7418, guest PC 0x0c073102 */
if(!s->budget--) { s->failed_pc=0x0c073102u; return 0; }
r[4]+=0x00000018u;
goto P_0c073104;
P_0c073104: /* original 64e3, guest PC 0x0c073104 */
if(!s->budget--) { s->failed_pc=0x0c073104u; return 0; }
r[4]=r[14];
goto P_0c073106;
P_0c073106: /* original 6a0c, guest PC 0x0c073106 */
if(!s->budget--) { s->failed_pc=0x0c073106u; return 0; }
r[10]=r[0]&255u;
goto P_0c073108;
P_0c073108: /* original 4d0b, guest PC 0x0c073108 */
if(!s->budget--) { s->failed_pc=0x0c073108u; return 0; }
target=r[13];
r[16]=code_base|0x0c07310cu;
r[4]+=0x0000001au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07310cu) { target=s->pc; goto dispatch; }
goto P_0c07310c;
P_0c07310a: /* original 741a, guest PC 0x0c07310a */
if(!s->budget--) { s->failed_pc=0x0c07310au; return 0; }
r[4]+=0x0000001au;
goto P_0c07310c;
P_0c07310c: /* original db24, guest PC 0x0c07310c */
if(!s->budget--) { s->failed_pc=0x0c07310cu; return 0; }
r[11]=read(ram,0x0c0731a0u,4);
goto P_0c07310e;
P_0c07310e: /* original 2cc8, guest PC 0x0c07310e */
if(!s->budget--) { s->failed_pc=0x0c07310eu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c073110;
P_0c073110: /* original 8d04, guest PC 0x0c073110 */
if(!s->budget--) { s->failed_pc=0x0c073110u; return 0; }
cond=r[17]&1u;
r[4]=r[0]&255u;
if(cond) { goto P_0c07311c; }
goto P_0c073114;
P_0c073112: /* original 640c, guest PC 0x0c073112 */
if(!s->budget--) { s->failed_pc=0x0c073112u; return 0; }
r[4]=r[0]&255u;
goto P_0c073114;
P_0c073114: /* original 2448, guest PC 0x0c073114 */
if(!s->budget--) { s->failed_pc=0x0c073114u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c073116;
P_0c073116: /* original 8903, guest PC 0x0c073116 */
if(!s->budget--) { s->failed_pc=0x0c073116u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c073120; }
goto P_0c073118;
P_0c073118: /* original a026, guest PC 0x0c073118 */
if(!s->budget--) { s->failed_pc=0x0c073118u; return 0; }
goto P_0c073168;
P_0c07311a: /* original 0009, guest PC 0x0c07311a */
if(!s->budget--) { s->failed_pc=0x0c07311au; return 0; }
goto P_0c07311c;
P_0c07311c: /* original 3a40, guest PC 0x0c07311c */
if(!s->budget--) { s->failed_pc=0x0c07311cu; return 0; }
r[17]=(r[17]&~1u)|((r[10]==r[4])!=0);
goto P_0c07311e;
P_0c07311e: /* original 8b23, guest PC 0x0c07311e */
if(!s->budget--) { s->failed_pc=0x0c07311eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073168; }
goto P_0c073120;
P_0c073120: /* original 64e3, guest PC 0x0c073120 */
if(!s->budget--) { s->failed_pc=0x0c073120u; return 0; }
r[4]=r[14];
goto P_0c073122;
P_0c073122: /* original 4d0b, guest PC 0x0c073122 */
if(!s->budget--) { s->failed_pc=0x0c073122u; return 0; }
target=r[13];
r[16]=code_base|0x0c073126u;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073126u) { target=s->pc; goto dispatch; }
goto P_0c073126;
P_0c073124: /* original 7418, guest PC 0x0c073124 */
if(!s->budget--) { s->failed_pc=0x0c073124u; return 0; }
r[4]+=0x00000018u;
goto P_0c073126;
P_0c073126: /* original 600c, guest PC 0x0c073126 */
if(!s->budget--) { s->failed_pc=0x0c073126u; return 0; }
r[0]=r[0]&255u;
goto P_0c073128;
P_0c073128: /* original 65c3, guest PC 0x0c073128 */
if(!s->budget--) { s->failed_pc=0x0c073128u; return 0; }
r[5]=r[12];
goto P_0c07312a;
P_0c07312a: /* original e701, guest PC 0x0c07312a */
if(!s->budget--) { s->failed_pc=0x0c07312au; return 0; }
r[7]=0x00000001u;
goto P_0c07312c;
P_0c07312c: /* original 2f02, guest PC 0x0c07312c */
if(!s->budget--) { s->failed_pc=0x0c07312cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c07312e;
P_0c07312e: /* original e305, guest PC 0x0c07312e */
if(!s->budget--) { s->failed_pc=0x0c07312eu; return 0; }
r[3]=0x00000005u;
goto P_0c073130;
P_0c073130: /* original 6673, guest PC 0x0c073130 */
if(!s->budget--) { s->failed_pc=0x0c073130u; return 0; }
r[6]=r[7];
goto P_0c073132;
P_0c073132: /* original 2f36, guest PC 0x0c073132 */
if(!s->budget--) { s->failed_pc=0x0c073132u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c073134;
P_0c073134: /* original bec5, guest PC 0x0c073134 */
if(!s->budget--) { s->failed_pc=0x0c073134u; return 0; }
target=code_base|0x0c072ec2u; r[16]=code_base|0x0c073138u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073138u) { target=s->pc; goto dispatch; }
goto P_0c073138;
P_0c073136: /* original 6403, guest PC 0x0c073136 */
if(!s->budget--) { s->failed_pc=0x0c073136u; return 0; }
r[4]=r[0];
goto P_0c073138;
P_0c073138: /* original 7f04, guest PC 0x0c073138 */
if(!s->budget--) { s->failed_pc=0x0c073138u; return 0; }
r[15]+=0x00000004u;
goto P_0c07313a;
P_0c07313a: /* original 64e3, guest PC 0x0c07313a */
if(!s->budget--) { s->failed_pc=0x0c07313au; return 0; }
r[4]=r[14];
goto P_0c07313c;
P_0c07313c: /* original 6503, guest PC 0x0c07313c */
if(!s->budget--) { s->failed_pc=0x0c07313cu; return 0; }
r[5]=r[0];
goto P_0c07313e;
P_0c07313e: /* original 2f02, guest PC 0x0c07313e */
if(!s->budget--) { s->failed_pc=0x0c07313eu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c073140;
P_0c073140: /* original 4b0b, guest PC 0x0c073140 */
if(!s->budget--) { s->failed_pc=0x0c073140u; return 0; }
target=r[11];
r[16]=code_base|0x0c073144u;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073144u) { target=s->pc; goto dispatch; }
goto P_0c073144;
P_0c073142: /* original 7418, guest PC 0x0c073142 */
if(!s->budget--) { s->failed_pc=0x0c073142u; return 0; }
r[4]+=0x00000018u;
goto P_0c073144;
P_0c073144: /* original 2cc8, guest PC 0x0c073144 */
if(!s->budget--) { s->failed_pc=0x0c073144u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c073146;
P_0c073146: /* original 8b01, guest PC 0x0c073146 */
if(!s->budget--) { s->failed_pc=0x0c073146u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07314c; }
goto P_0c073148;
P_0c073148: /* original a01c, guest PC 0x0c073148 */
if(!s->budget--) { s->failed_pc=0x0c073148u; return 0; }
r[5]=0x00000001u;
goto P_0c073184;
P_0c07314a: /* original e501, guest PC 0x0c07314a */
if(!s->budget--) { s->failed_pc=0x0c07314au; return 0; }
r[5]=0x00000001u;
goto P_0c07314c;
P_0c07314c: /* original 64e3, guest PC 0x0c07314c */
if(!s->budget--) { s->failed_pc=0x0c07314cu; return 0; }
r[4]=r[14];
goto P_0c07314e;
P_0c07314e: /* original 4d0b, guest PC 0x0c07314e */
if(!s->budget--) { s->failed_pc=0x0c07314eu; return 0; }
target=r[13];
r[16]=code_base|0x0c073152u;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073152u) { target=s->pc; goto dispatch; }
goto P_0c073152;
P_0c073150: /* original 7418, guest PC 0x0c073150 */
if(!s->budget--) { s->failed_pc=0x0c073150u; return 0; }
r[4]+=0x00000018u;
goto P_0c073152;
P_0c073152: /* original 6d0c, guest PC 0x0c073152 */
if(!s->budget--) { s->failed_pc=0x0c073152u; return 0; }
r[13]=r[0]&255u;
goto P_0c073154;
P_0c073154: /* original 64e3, guest PC 0x0c073154 */
if(!s->budget--) { s->failed_pc=0x0c073154u; return 0; }
r[4]=r[14];
goto P_0c073156;
P_0c073156: /* original 65d3, guest PC 0x0c073156 */
if(!s->budget--) { s->failed_pc=0x0c073156u; return 0; }
r[5]=r[13];
goto P_0c073158;
P_0c073158: /* original 4b0b, guest PC 0x0c073158 */
if(!s->budget--) { s->failed_pc=0x0c073158u; return 0; }
target=r[11];
r[16]=code_base|0x0c07315cu;
r[4]+=0x0000001au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07315cu) { target=s->pc; goto dispatch; }
goto P_0c07315c;
P_0c07315a: /* original 741a, guest PC 0x0c07315a */
if(!s->budget--) { s->failed_pc=0x0c07315au; return 0; }
r[4]+=0x0000001au;
goto P_0c07315c;
P_0c07315c: /* original 901d, guest PC 0x0c07315c */
if(!s->budget--) { s->failed_pc=0x0c07315cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07319au,2);
goto P_0c07315e;
P_0c07315e: /* original d414, guest PC 0x0c07315e */
if(!s->budget--) { s->failed_pc=0x0c07315eu; return 0; }
r[4]=read(ram,0x0c0731b0u,4);
goto P_0c073160;
P_0c073160: /* original 04d4, guest PC 0x0c073160 */
if(!s->budget--) { s->failed_pc=0x0c073160u; return 0; }
write(ram,r[4]+r[0],r[13],1);
goto P_0c073162;
P_0c073162: /* original 7002, guest PC 0x0c073162 */
if(!s->budget--) { s->failed_pc=0x0c073162u; return 0; }
r[0]+=0x00000002u;
goto P_0c073164;
P_0c073164: /* original a011, guest PC 0x0c073164 */
if(!s->budget--) { s->failed_pc=0x0c073164u; return 0; }
write(ram,r[4]+r[0],r[13],1);
goto P_0c07318a;
P_0c073166: /* original 04d4, guest PC 0x0c073166 */
if(!s->budget--) { s->failed_pc=0x0c073166u; return 0; }
write(ram,r[4]+r[0],r[13],1);
goto P_0c073168;
P_0c073168: /* original 64e3, guest PC 0x0c073168 */
if(!s->budget--) { s->failed_pc=0x0c073168u; return 0; }
r[4]=r[14];
goto P_0c07316a;
P_0c07316a: /* original 4d0b, guest PC 0x0c07316a */
if(!s->budget--) { s->failed_pc=0x0c07316au; return 0; }
target=r[13];
r[16]=code_base|0x0c07316eu;
r[4]+=0x0000001au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07316eu) { target=s->pc; goto dispatch; }
goto P_0c07316e;
P_0c07316c: /* original 741a, guest PC 0x0c07316c */
if(!s->budget--) { s->failed_pc=0x0c07316cu; return 0; }
r[4]+=0x0000001au;
goto P_0c07316e;
P_0c07316e: /* original 600c, guest PC 0x0c07316e */
if(!s->budget--) { s->failed_pc=0x0c07316eu; return 0; }
r[0]=r[0]&255u;
goto P_0c073170;
P_0c073170: /* original 65c3, guest PC 0x0c073170 */
if(!s->budget--) { s->failed_pc=0x0c073170u; return 0; }
r[5]=r[12];
goto P_0c073172;
P_0c073172: /* original e701, guest PC 0x0c073172 */
if(!s->budget--) { s->failed_pc=0x0c073172u; return 0; }
r[7]=0x00000001u;
goto P_0c073174;
P_0c073174: /* original 2f02, guest PC 0x0c073174 */
if(!s->budget--) { s->failed_pc=0x0c073174u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c073176;
P_0c073176: /* original 6673, guest PC 0x0c073176 */
if(!s->budget--) { s->failed_pc=0x0c073176u; return 0; }
r[6]=r[7];
goto P_0c073178;
P_0c073178: /* original 2fa6, guest PC 0x0c073178 */
if(!s->budget--) { s->failed_pc=0x0c073178u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07317a;
P_0c07317a: /* original bea2, guest PC 0x0c07317a */
if(!s->budget--) { s->failed_pc=0x0c07317au; return 0; }
target=code_base|0x0c072ec2u; r[16]=code_base|0x0c07317eu;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07317eu) { target=s->pc; goto dispatch; }
goto P_0c07317e;
P_0c07317c: /* original 6403, guest PC 0x0c07317c */
if(!s->budget--) { s->failed_pc=0x0c07317cu; return 0; }
r[4]=r[0];
goto P_0c07317e;
P_0c07317e: /* original 7f04, guest PC 0x0c07317e */
if(!s->budget--) { s->failed_pc=0x0c07317eu; return 0; }
r[15]+=0x00000004u;
goto P_0c073180;
P_0c073180: /* original 6503, guest PC 0x0c073180 */
if(!s->budget--) { s->failed_pc=0x0c073180u; return 0; }
r[5]=r[0];
goto P_0c073182;
P_0c073182: /* original 2f02, guest PC 0x0c073182 */
if(!s->budget--) { s->failed_pc=0x0c073182u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c073184;
P_0c073184: /* original 64e3, guest PC 0x0c073184 */
if(!s->budget--) { s->failed_pc=0x0c073184u; return 0; }
r[4]=r[14];
goto P_0c073186;
P_0c073186: /* original 4b0b, guest PC 0x0c073186 */
if(!s->budget--) { s->failed_pc=0x0c073186u; return 0; }
target=r[11];
r[16]=code_base|0x0c07318au;
r[4]+=0x0000001au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07318au) { target=s->pc; goto dispatch; }
goto P_0c07318a;
P_0c073188: /* original 741a, guest PC 0x0c073188 */
if(!s->budget--) { s->failed_pc=0x0c073188u; return 0; }
r[4]+=0x0000001au;
goto P_0c07318a;
P_0c07318a: /* original 7f04, guest PC 0x0c07318a */
if(!s->budget--) { s->failed_pc=0x0c07318au; return 0; }
r[15]+=0x00000004u;
goto P_0c07318c;
P_0c07318c: /* original 4f26, guest PC 0x0c07318c */
if(!s->budget--) { s->failed_pc=0x0c07318cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07318e;
P_0c07318e: /* original 6af6, guest PC 0x0c07318e */
if(!s->budget--) { s->failed_pc=0x0c07318eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c073190;
P_0c073190: /* original 6bf6, guest PC 0x0c073190 */
if(!s->budget--) { s->failed_pc=0x0c073190u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c073192;
P_0c073192: /* original 6cf6, guest PC 0x0c073192 */
if(!s->budget--) { s->failed_pc=0x0c073192u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c073194;
P_0c073194: /* original 6df6, guest PC 0x0c073194 */
if(!s->budget--) { s->failed_pc=0x0c073194u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c073196;
P_0c073196: /* original 000b, guest PC 0x0c073196 */
if(!s->budget--) { s->failed_pc=0x0c073196u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c073198: /* original 6ef6, guest PC 0x0c073198 */
if(!s->budget--) { s->failed_pc=0x0c073198u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07319au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07319au; return 0; } return 1;
P_0c0731b4: /* original 2fe6, guest PC 0x0c0731b4 */
if(!s->budget--) { s->failed_pc=0x0c0731b4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0731b6;
P_0c0731b6: /* original 6e43, guest PC 0x0c0731b6 */
if(!s->budget--) { s->failed_pc=0x0c0731b6u; return 0; }
r[14]=r[4];
goto P_0c0731b8;
P_0c0731b8: /* original 2fd6, guest PC 0x0c0731b8 */
if(!s->budget--) { s->failed_pc=0x0c0731b8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0731ba;
P_0c0731ba: /* original 2fc6, guest PC 0x0c0731ba */
if(!s->budget--) { s->failed_pc=0x0c0731bau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0731bc;
P_0c0731bc: /* original 6c53, guest PC 0x0c0731bc */
if(!s->budget--) { s->failed_pc=0x0c0731bcu; return 0; }
r[12]=r[5];
goto P_0c0731be;
P_0c0731be: /* original 2fb6, guest PC 0x0c0731be */
if(!s->budget--) { s->failed_pc=0x0c0731beu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0731c0;
P_0c0731c0: /* original 2fa6, guest PC 0x0c0731c0 */
if(!s->budget--) { s->failed_pc=0x0c0731c0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0731c2;
P_0c0731c2: /* original 4f22, guest PC 0x0c0731c2 */
if(!s->budget--) { s->failed_pc=0x0c0731c2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0731c4;
P_0c0731c4: /* original dd3d, guest PC 0x0c0731c4 */
if(!s->budget--) { s->failed_pc=0x0c0731c4u; return 0; }
r[13]=read(ram,0x0c0732bcu,4);
goto P_0c0731c6;
P_0c0731c6: /* original 7ffc, guest PC 0x0c0731c6 */
if(!s->budget--) { s->failed_pc=0x0c0731c6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0731c8;
P_0c0731c8: /* original 4d0b, guest PC 0x0c0731c8 */
if(!s->budget--) { s->failed_pc=0x0c0731c8u; return 0; }
target=r[13];
r[16]=code_base|0x0c0731ccu;
r[4]+=0x00000019u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0731ccu) { target=s->pc; goto dispatch; }
goto P_0c0731cc;
P_0c0731ca: /* original 7419, guest PC 0x0c0731ca */
if(!s->budget--) { s->failed_pc=0x0c0731cau; return 0; }
r[4]+=0x00000019u;
goto P_0c0731cc;
P_0c0731cc: /* original 64e3, guest PC 0x0c0731cc */
if(!s->budget--) { s->failed_pc=0x0c0731ccu; return 0; }
r[4]=r[14];
goto P_0c0731ce;
P_0c0731ce: /* original 6a0c, guest PC 0x0c0731ce */
if(!s->budget--) { s->failed_pc=0x0c0731ceu; return 0; }
r[10]=r[0]&255u;
goto P_0c0731d0;
P_0c0731d0: /* original 4d0b, guest PC 0x0c0731d0 */
if(!s->budget--) { s->failed_pc=0x0c0731d0u; return 0; }
target=r[13];
r[16]=code_base|0x0c0731d4u;
r[4]+=0x0000001bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0731d4u) { target=s->pc; goto dispatch; }
goto P_0c0731d4;
P_0c0731d2: /* original 741b, guest PC 0x0c0731d2 */
if(!s->budget--) { s->failed_pc=0x0c0731d2u; return 0; }
r[4]+=0x0000001bu;
goto P_0c0731d4;
P_0c0731d4: /* original db3a, guest PC 0x0c0731d4 */
if(!s->budget--) { s->failed_pc=0x0c0731d4u; return 0; }
r[11]=read(ram,0x0c0732c0u,4);
goto P_0c0731d6;
P_0c0731d6: /* original 2cc8, guest PC 0x0c0731d6 */
if(!s->budget--) { s->failed_pc=0x0c0731d6u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0731d8;
P_0c0731d8: /* original 8d05, guest PC 0x0c0731d8 */
if(!s->budget--) { s->failed_pc=0x0c0731d8u; return 0; }
cond=r[17]&1u;
r[4]=r[0]&255u;
if(cond) { goto P_0c0731e6; }
goto P_0c0731dc;
P_0c0731da: /* original 640c, guest PC 0x0c0731da */
if(!s->budget--) { s->failed_pc=0x0c0731dau; return 0; }
r[4]=r[0]&255u;
goto P_0c0731dc;
P_0c0731dc: /* original 6043, guest PC 0x0c0731dc */
if(!s->budget--) { s->failed_pc=0x0c0731dcu; return 0; }
r[0]=r[4];
goto P_0c0731de;
P_0c0731de: /* original 8801, guest PC 0x0c0731de */
if(!s->budget--) { s->failed_pc=0x0c0731deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0731e0;
P_0c0731e0: /* original 8903, guest PC 0x0c0731e0 */
if(!s->budget--) { s->failed_pc=0x0c0731e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0731ea; }
goto P_0c0731e2;
P_0c0731e2: /* original a026, guest PC 0x0c0731e2 */
if(!s->budget--) { s->failed_pc=0x0c0731e2u; return 0; }
goto P_0c073232;
P_0c0731e4: /* original 0009, guest PC 0x0c0731e4 */
if(!s->budget--) { s->failed_pc=0x0c0731e4u; return 0; }
goto P_0c0731e6;
P_0c0731e6: /* original 3a40, guest PC 0x0c0731e6 */
if(!s->budget--) { s->failed_pc=0x0c0731e6u; return 0; }
r[17]=(r[17]&~1u)|((r[10]==r[4])!=0);
goto P_0c0731e8;
P_0c0731e8: /* original 8b23, guest PC 0x0c0731e8 */
if(!s->budget--) { s->failed_pc=0x0c0731e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073232; }
goto P_0c0731ea;
P_0c0731ea: /* original 64e3, guest PC 0x0c0731ea */
if(!s->budget--) { s->failed_pc=0x0c0731eau; return 0; }
r[4]=r[14];
goto P_0c0731ec;
P_0c0731ec: /* original 4d0b, guest PC 0x0c0731ec */
if(!s->budget--) { s->failed_pc=0x0c0731ecu; return 0; }
target=r[13];
r[16]=code_base|0x0c0731f0u;
r[4]+=0x00000019u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0731f0u) { target=s->pc; goto dispatch; }
goto P_0c0731f0;
P_0c0731ee: /* original 7419, guest PC 0x0c0731ee */
if(!s->budget--) { s->failed_pc=0x0c0731eeu; return 0; }
r[4]+=0x00000019u;
goto P_0c0731f0;
P_0c0731f0: /* original 600c, guest PC 0x0c0731f0 */
if(!s->budget--) { s->failed_pc=0x0c0731f0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0731f2;
P_0c0731f2: /* original 65c3, guest PC 0x0c0731f2 */
if(!s->budget--) { s->failed_pc=0x0c0731f2u; return 0; }
r[5]=r[12];
goto P_0c0731f4;
P_0c0731f4: /* original e701, guest PC 0x0c0731f4 */
if(!s->budget--) { s->failed_pc=0x0c0731f4u; return 0; }
r[7]=0x00000001u;
goto P_0c0731f6;
P_0c0731f6: /* original 2f02, guest PC 0x0c0731f6 */
if(!s->budget--) { s->failed_pc=0x0c0731f6u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0731f8;
P_0c0731f8: /* original e305, guest PC 0x0c0731f8 */
if(!s->budget--) { s->failed_pc=0x0c0731f8u; return 0; }
r[3]=0x00000005u;
goto P_0c0731fa;
P_0c0731fa: /* original 6673, guest PC 0x0c0731fa */
if(!s->budget--) { s->failed_pc=0x0c0731fau; return 0; }
r[6]=r[7];
goto P_0c0731fc;
P_0c0731fc: /* original 2f36, guest PC 0x0c0731fc */
if(!s->budget--) { s->failed_pc=0x0c0731fcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0731fe;
P_0c0731fe: /* original be60, guest PC 0x0c0731fe */
if(!s->budget--) { s->failed_pc=0x0c0731feu; return 0; }
target=code_base|0x0c072ec2u; r[16]=code_base|0x0c073202u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073202u) { target=s->pc; goto dispatch; }
goto P_0c073202;
P_0c073200: /* original 6403, guest PC 0x0c073200 */
if(!s->budget--) { s->failed_pc=0x0c073200u; return 0; }
r[4]=r[0];
goto P_0c073202;
P_0c073202: /* original 7f04, guest PC 0x0c073202 */
if(!s->budget--) { s->failed_pc=0x0c073202u; return 0; }
r[15]+=0x00000004u;
goto P_0c073204;
P_0c073204: /* original 64e3, guest PC 0x0c073204 */
if(!s->budget--) { s->failed_pc=0x0c073204u; return 0; }
r[4]=r[14];
goto P_0c073206;
P_0c073206: /* original 6503, guest PC 0x0c073206 */
if(!s->budget--) { s->failed_pc=0x0c073206u; return 0; }
r[5]=r[0];
goto P_0c073208;
P_0c073208: /* original 2f02, guest PC 0x0c073208 */
if(!s->budget--) { s->failed_pc=0x0c073208u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c07320a;
P_0c07320a: /* original 4b0b, guest PC 0x0c07320a */
if(!s->budget--) { s->failed_pc=0x0c07320au; return 0; }
target=r[11];
r[16]=code_base|0x0c07320eu;
r[4]+=0x00000019u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07320eu) { target=s->pc; goto dispatch; }
goto P_0c07320e;
P_0c07320c: /* original 7419, guest PC 0x0c07320c */
if(!s->budget--) { s->failed_pc=0x0c07320cu; return 0; }
r[4]+=0x00000019u;
goto P_0c07320e;
P_0c07320e: /* original 2cc8, guest PC 0x0c07320e */
if(!s->budget--) { s->failed_pc=0x0c07320eu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c073210;
P_0c073210: /* original 8b01, guest PC 0x0c073210 */
if(!s->budget--) { s->failed_pc=0x0c073210u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073216; }
goto P_0c073212;
P_0c073212: /* original a01c, guest PC 0x0c073212 */
if(!s->budget--) { s->failed_pc=0x0c073212u; return 0; }
r[5]=0x00000001u;
goto P_0c07324e;
P_0c073214: /* original e501, guest PC 0x0c073214 */
if(!s->budget--) { s->failed_pc=0x0c073214u; return 0; }
r[5]=0x00000001u;
goto P_0c073216;
P_0c073216: /* original 64e3, guest PC 0x0c073216 */
if(!s->budget--) { s->failed_pc=0x0c073216u; return 0; }
r[4]=r[14];
goto P_0c073218;
P_0c073218: /* original 4d0b, guest PC 0x0c073218 */
if(!s->budget--) { s->failed_pc=0x0c073218u; return 0; }
target=r[13];
r[16]=code_base|0x0c07321cu;
r[4]+=0x00000019u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07321cu) { target=s->pc; goto dispatch; }
goto P_0c07321c;
P_0c07321a: /* original 7419, guest PC 0x0c07321a */
if(!s->budget--) { s->failed_pc=0x0c07321au; return 0; }
r[4]+=0x00000019u;
goto P_0c07321c;
P_0c07321c: /* original 6d0c, guest PC 0x0c07321c */
if(!s->budget--) { s->failed_pc=0x0c07321cu; return 0; }
r[13]=r[0]&255u;
goto P_0c07321e;
P_0c07321e: /* original 64e3, guest PC 0x0c07321e */
if(!s->budget--) { s->failed_pc=0x0c07321eu; return 0; }
r[4]=r[14];
goto P_0c073220;
P_0c073220: /* original 65d3, guest PC 0x0c073220 */
if(!s->budget--) { s->failed_pc=0x0c073220u; return 0; }
r[5]=r[13];
goto P_0c073222;
P_0c073222: /* original 4b0b, guest PC 0x0c073222 */
if(!s->budget--) { s->failed_pc=0x0c073222u; return 0; }
target=r[11];
r[16]=code_base|0x0c073226u;
r[4]+=0x0000001bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073226u) { target=s->pc; goto dispatch; }
goto P_0c073226;
P_0c073224: /* original 741b, guest PC 0x0c073224 */
if(!s->budget--) { s->failed_pc=0x0c073224u; return 0; }
r[4]+=0x0000001bu;
goto P_0c073226;
P_0c073226: /* original 9047, guest PC 0x0c073226 */
if(!s->budget--) { s->failed_pc=0x0c073226u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0732b8u,2);
goto P_0c073228;
P_0c073228: /* original d426, guest PC 0x0c073228 */
if(!s->budget--) { s->failed_pc=0x0c073228u; return 0; }
r[4]=read(ram,0x0c0732c4u,4);
goto P_0c07322a;
P_0c07322a: /* original 04d4, guest PC 0x0c07322a */
if(!s->budget--) { s->failed_pc=0x0c07322au; return 0; }
write(ram,r[4]+r[0],r[13],1);
goto P_0c07322c;
P_0c07322c: /* original 7002, guest PC 0x0c07322c */
if(!s->budget--) { s->failed_pc=0x0c07322cu; return 0; }
r[0]+=0x00000002u;
goto P_0c07322e;
P_0c07322e: /* original a011, guest PC 0x0c07322e */
if(!s->budget--) { s->failed_pc=0x0c07322eu; return 0; }
write(ram,r[4]+r[0],r[13],1);
goto P_0c073254;
P_0c073230: /* original 04d4, guest PC 0x0c073230 */
if(!s->budget--) { s->failed_pc=0x0c073230u; return 0; }
write(ram,r[4]+r[0],r[13],1);
goto P_0c073232;
P_0c073232: /* original 64e3, guest PC 0x0c073232 */
if(!s->budget--) { s->failed_pc=0x0c073232u; return 0; }
r[4]=r[14];
goto P_0c073234;
P_0c073234: /* original 4d0b, guest PC 0x0c073234 */
if(!s->budget--) { s->failed_pc=0x0c073234u; return 0; }
target=r[13];
r[16]=code_base|0x0c073238u;
r[4]+=0x0000001bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073238u) { target=s->pc; goto dispatch; }
goto P_0c073238;
P_0c073236: /* original 741b, guest PC 0x0c073236 */
if(!s->budget--) { s->failed_pc=0x0c073236u; return 0; }
r[4]+=0x0000001bu;
goto P_0c073238;
P_0c073238: /* original 600c, guest PC 0x0c073238 */
if(!s->budget--) { s->failed_pc=0x0c073238u; return 0; }
r[0]=r[0]&255u;
goto P_0c07323a;
P_0c07323a: /* original 65c3, guest PC 0x0c07323a */
if(!s->budget--) { s->failed_pc=0x0c07323au; return 0; }
r[5]=r[12];
goto P_0c07323c;
P_0c07323c: /* original e701, guest PC 0x0c07323c */
if(!s->budget--) { s->failed_pc=0x0c07323cu; return 0; }
r[7]=0x00000001u;
goto P_0c07323e;
P_0c07323e: /* original 2f02, guest PC 0x0c07323e */
if(!s->budget--) { s->failed_pc=0x0c07323eu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c073240;
P_0c073240: /* original 6673, guest PC 0x0c073240 */
if(!s->budget--) { s->failed_pc=0x0c073240u; return 0; }
r[6]=r[7];
goto P_0c073242;
P_0c073242: /* original 2fa6, guest PC 0x0c073242 */
if(!s->budget--) { s->failed_pc=0x0c073242u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c073244;
P_0c073244: /* original be3d, guest PC 0x0c073244 */
if(!s->budget--) { s->failed_pc=0x0c073244u; return 0; }
target=code_base|0x0c072ec2u; r[16]=code_base|0x0c073248u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073248u) { target=s->pc; goto dispatch; }
goto P_0c073248;
P_0c073246: /* original 6403, guest PC 0x0c073246 */
if(!s->budget--) { s->failed_pc=0x0c073246u; return 0; }
r[4]=r[0];
goto P_0c073248;
P_0c073248: /* original 7f04, guest PC 0x0c073248 */
if(!s->budget--) { s->failed_pc=0x0c073248u; return 0; }
r[15]+=0x00000004u;
goto P_0c07324a;
P_0c07324a: /* original 6503, guest PC 0x0c07324a */
if(!s->budget--) { s->failed_pc=0x0c07324au; return 0; }
r[5]=r[0];
goto P_0c07324c;
P_0c07324c: /* original 2f02, guest PC 0x0c07324c */
if(!s->budget--) { s->failed_pc=0x0c07324cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c07324e;
P_0c07324e: /* original 64e3, guest PC 0x0c07324e */
if(!s->budget--) { s->failed_pc=0x0c07324eu; return 0; }
r[4]=r[14];
goto P_0c073250;
P_0c073250: /* original 4b0b, guest PC 0x0c073250 */
if(!s->budget--) { s->failed_pc=0x0c073250u; return 0; }
target=r[11];
r[16]=code_base|0x0c073254u;
r[4]+=0x0000001bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073254u) { target=s->pc; goto dispatch; }
goto P_0c073254;
P_0c073252: /* original 741b, guest PC 0x0c073252 */
if(!s->budget--) { s->failed_pc=0x0c073252u; return 0; }
r[4]+=0x0000001bu;
goto P_0c073254;
P_0c073254: /* original 7f04, guest PC 0x0c073254 */
if(!s->budget--) { s->failed_pc=0x0c073254u; return 0; }
r[15]+=0x00000004u;
goto P_0c073256;
P_0c073256: /* original 4f26, guest PC 0x0c073256 */
if(!s->budget--) { s->failed_pc=0x0c073256u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c073258;
P_0c073258: /* original 6af6, guest PC 0x0c073258 */
if(!s->budget--) { s->failed_pc=0x0c073258u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07325a;
P_0c07325a: /* original 6bf6, guest PC 0x0c07325a */
if(!s->budget--) { s->failed_pc=0x0c07325au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07325c;
P_0c07325c: /* original 6cf6, guest PC 0x0c07325c */
if(!s->budget--) { s->failed_pc=0x0c07325cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07325e;
P_0c07325e: /* original 6df6, guest PC 0x0c07325e */
if(!s->budget--) { s->failed_pc=0x0c07325eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c073260;
P_0c073260: /* original 000b, guest PC 0x0c073260 */
if(!s->budget--) { s->failed_pc=0x0c073260u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c073262: /* original 6ef6, guest PC 0x0c073262 */
if(!s->budget--) { s->failed_pc=0x0c073262u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c073264u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c073264u; return 0; } return 1;
P_0c0736d2: /* original 2fe6, guest PC 0x0c0736d2 */
if(!s->budget--) { s->failed_pc=0x0c0736d2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0736d4;
P_0c0736d4: /* original 6e43, guest PC 0x0c0736d4 */
if(!s->budget--) { s->failed_pc=0x0c0736d4u; return 0; }
r[14]=r[4];
goto P_0c0736d6;
P_0c0736d6: /* original 2fd6, guest PC 0x0c0736d6 */
if(!s->budget--) { s->failed_pc=0x0c0736d6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0736d8;
P_0c0736d8: /* original 64e3, guest PC 0x0c0736d8 */
if(!s->budget--) { s->failed_pc=0x0c0736d8u; return 0; }
r[4]=r[14];
goto P_0c0736da;
P_0c0736da: /* original 2fc6, guest PC 0x0c0736da */
if(!s->budget--) { s->failed_pc=0x0c0736dau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0736dc;
P_0c0736dc: /* original 4f22, guest PC 0x0c0736dc */
if(!s->budget--) { s->failed_pc=0x0c0736dcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0736de;
P_0c0736de: /* original 7ff8, guest PC 0x0c0736de */
if(!s->budget--) { s->failed_pc=0x0c0736deu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0736e0;
P_0c0736e0: /* original 2f52, guest PC 0x0c0736e0 */
if(!s->budget--) { s->failed_pc=0x0c0736e0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0736e2;
P_0c0736e2: /* original dd1b, guest PC 0x0c0736e2 */
if(!s->budget--) { s->failed_pc=0x0c0736e2u; return 0; }
r[13]=read(ram,0x0c073750u,4);
goto P_0c0736e4;
P_0c0736e4: /* original 4d0b, guest PC 0x0c0736e4 */
if(!s->budget--) { s->failed_pc=0x0c0736e4u; return 0; }
target=r[13];
r[16]=code_base|0x0c0736e8u;
r[4]+=0x00000025u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0736e8u) { target=s->pc; goto dispatch; }
goto P_0c0736e8;
P_0c0736e6: /* original 7425, guest PC 0x0c0736e6 */
if(!s->budget--) { s->failed_pc=0x0c0736e6u; return 0; }
r[4]+=0x00000025u;
goto P_0c0736e8;
P_0c0736e8: /* original 600c, guest PC 0x0c0736e8 */
if(!s->budget--) { s->failed_pc=0x0c0736e8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0736ea;
P_0c0736ea: /* original e309, guest PC 0x0c0736ea */
if(!s->budget--) { s->failed_pc=0x0c0736eau; return 0; }
r[3]=0x00000009u;
goto P_0c0736ec;
P_0c0736ec: /* original 1f01, guest PC 0x0c0736ec */
if(!s->budget--) { s->failed_pc=0x0c0736ecu; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0736ee;
P_0c0736ee: /* original 2f36, guest PC 0x0c0736ee */
if(!s->budget--) { s->failed_pc=0x0c0736eeu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0736f0;
P_0c0736f0: /* original e601, guest PC 0x0c0736f0 */
if(!s->budget--) { s->failed_pc=0x0c0736f0u; return 0; }
r[6]=0x00000001u;
goto P_0c0736f2;
P_0c0736f2: /* original 55f1, guest PC 0x0c0736f2 */
if(!s->budget--) { s->failed_pc=0x0c0736f2u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0736f4;
P_0c0736f4: /* original e700, guest PC 0x0c0736f4 */
if(!s->budget--) { s->failed_pc=0x0c0736f4u; return 0; }
r[7]=0x00000000u;
goto P_0c0736f6;
P_0c0736f6: /* original bbe4, guest PC 0x0c0736f6 */
if(!s->budget--) { s->failed_pc=0x0c0736f6u; return 0; }
target=code_base|0x0c072ec2u; r[16]=code_base|0x0c0736fau;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0736fau) { target=s->pc; goto dispatch; }
goto P_0c0736fa;
P_0c0736f8: /* original 54f2, guest PC 0x0c0736f8 */
if(!s->budget--) { s->failed_pc=0x0c0736f8u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0736fa;
P_0c0736fa: /* original 7f04, guest PC 0x0c0736fa */
if(!s->budget--) { s->failed_pc=0x0c0736fau; return 0; }
r[15]+=0x00000004u;
goto P_0c0736fc;
P_0c0736fc: /* original 64e3, guest PC 0x0c0736fc */
if(!s->budget--) { s->failed_pc=0x0c0736fcu; return 0; }
r[4]=r[14];
goto P_0c0736fe;
P_0c0736fe: /* original 6503, guest PC 0x0c0736fe */
if(!s->budget--) { s->failed_pc=0x0c0736feu; return 0; }
r[5]=r[0];
goto P_0c073700;
P_0c073700: /* original 1f01, guest PC 0x0c073700 */
if(!s->budget--) { s->failed_pc=0x0c073700u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c073702;
P_0c073702: /* original dc18, guest PC 0x0c073702 */
if(!s->budget--) { s->failed_pc=0x0c073702u; return 0; }
r[12]=read(ram,0x0c073764u,4);
goto P_0c073704;
P_0c073704: /* original 4c0b, guest PC 0x0c073704 */
if(!s->budget--) { s->failed_pc=0x0c073704u; return 0; }
target=r[12];
r[16]=code_base|0x0c073708u;
r[4]+=0x00000025u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073708u) { target=s->pc; goto dispatch; }
goto P_0c073708;
P_0c073706: /* original 7425, guest PC 0x0c073706 */
if(!s->budget--) { s->failed_pc=0x0c073706u; return 0; }
r[4]+=0x00000025u;
goto P_0c073708;
P_0c073708: /* original 64e3, guest PC 0x0c073708 */
if(!s->budget--) { s->failed_pc=0x0c073708u; return 0; }
r[4]=r[14];
goto P_0c07370a;
P_0c07370a: /* original 4d0b, guest PC 0x0c07370a */
if(!s->budget--) { s->failed_pc=0x0c07370au; return 0; }
target=r[13];
r[16]=code_base|0x0c07370eu;
r[4]+=0x00000025u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07370eu) { target=s->pc; goto dispatch; }
goto P_0c07370e;
P_0c07370c: /* original 7425, guest PC 0x0c07370c */
if(!s->budget--) { s->failed_pc=0x0c07370cu; return 0; }
r[4]+=0x00000025u;
goto P_0c07370e;
P_0c07370e: /* original 640c, guest PC 0x0c07370e */
if(!s->budget--) { s->failed_pc=0x0c07370eu; return 0; }
r[4]=r[0]&255u;
goto P_0c073710;
P_0c073710: /* original 6043, guest PC 0x0c073710 */
if(!s->budget--) { s->failed_pc=0x0c073710u; return 0; }
r[0]=r[4];
goto P_0c073712;
P_0c073712: /* original 8801, guest PC 0x0c073712 */
if(!s->budget--) { s->failed_pc=0x0c073712u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c073714;
P_0c073714: /* original 8b11, guest PC 0x0c073714 */
if(!s->budget--) { s->failed_pc=0x0c073714u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07373a; }
goto P_0c073716;
P_0c073716: /* original 64e3, guest PC 0x0c073716 */
if(!s->budget--) { s->failed_pc=0x0c073716u; return 0; }
r[4]=r[14];
goto P_0c073718;
P_0c073718: /* original 4d0b, guest PC 0x0c073718 */
if(!s->budget--) { s->failed_pc=0x0c073718u; return 0; }
target=r[13];
r[16]=code_base|0x0c07371cu;
r[4]+=0x00000025u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07371cu) { target=s->pc; goto dispatch; }
goto P_0c07371c;
P_0c07371a: /* original 7425, guest PC 0x0c07371a */
if(!s->budget--) { s->failed_pc=0x0c07371au; return 0; }
r[4]+=0x00000025u;
goto P_0c07371c;
P_0c07371c: /* original 600c, guest PC 0x0c07371c */
if(!s->budget--) { s->failed_pc=0x0c07371cu; return 0; }
r[0]=r[0]&255u;
goto P_0c07371e;
P_0c07371e: /* original e309, guest PC 0x0c07371e */
if(!s->budget--) { s->failed_pc=0x0c07371eu; return 0; }
r[3]=0x00000009u;
goto P_0c073720;
P_0c073720: /* original 1f01, guest PC 0x0c073720 */
if(!s->budget--) { s->failed_pc=0x0c073720u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c073722;
P_0c073722: /* original 2f36, guest PC 0x0c073722 */
if(!s->budget--) { s->failed_pc=0x0c073722u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c073724;
P_0c073724: /* original e601, guest PC 0x0c073724 */
if(!s->budget--) { s->failed_pc=0x0c073724u; return 0; }
r[6]=0x00000001u;
goto P_0c073726;
P_0c073726: /* original 55f1, guest PC 0x0c073726 */
if(!s->budget--) { s->failed_pc=0x0c073726u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c073728;
P_0c073728: /* original e700, guest PC 0x0c073728 */
if(!s->budget--) { s->failed_pc=0x0c073728u; return 0; }
r[7]=0x00000000u;
goto P_0c07372a;
P_0c07372a: /* original bbca, guest PC 0x0c07372a */
if(!s->budget--) { s->failed_pc=0x0c07372au; return 0; }
target=code_base|0x0c072ec2u; r[16]=code_base|0x0c07372eu;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07372eu) { target=s->pc; goto dispatch; }
goto P_0c07372e;
P_0c07372c: /* original 54f2, guest PC 0x0c07372c */
if(!s->budget--) { s->failed_pc=0x0c07372cu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07372e;
P_0c07372e: /* original 7f04, guest PC 0x0c07372e */
if(!s->budget--) { s->failed_pc=0x0c07372eu; return 0; }
r[15]+=0x00000004u;
goto P_0c073730;
P_0c073730: /* original 64e3, guest PC 0x0c073730 */
if(!s->budget--) { s->failed_pc=0x0c073730u; return 0; }
r[4]=r[14];
goto P_0c073732;
P_0c073732: /* original 6503, guest PC 0x0c073732 */
if(!s->budget--) { s->failed_pc=0x0c073732u; return 0; }
r[5]=r[0];
goto P_0c073734;
P_0c073734: /* original 2f02, guest PC 0x0c073734 */
if(!s->budget--) { s->failed_pc=0x0c073734u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c073736;
P_0c073736: /* original 4c0b, guest PC 0x0c073736 */
if(!s->budget--) { s->failed_pc=0x0c073736u; return 0; }
target=r[12];
r[16]=code_base|0x0c07373au;
r[4]+=0x00000025u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07373au) { target=s->pc; goto dispatch; }
goto P_0c07373a;
P_0c073738: /* original 7425, guest PC 0x0c073738 */
if(!s->budget--) { s->failed_pc=0x0c073738u; return 0; }
r[4]+=0x00000025u;
goto P_0c07373a;
P_0c07373a: /* original 64e3, guest PC 0x0c07373a */
if(!s->budget--) { s->failed_pc=0x0c07373au; return 0; }
r[4]=r[14];
goto P_0c07373c;
P_0c07373c: /* original e501, guest PC 0x0c07373c */
if(!s->budget--) { s->failed_pc=0x0c07373cu; return 0; }
r[5]=0x00000001u;
goto P_0c07373e;
P_0c07373e: /* original 4c0b, guest PC 0x0c07373e */
if(!s->budget--) { s->failed_pc=0x0c07373eu; return 0; }
target=r[12];
r[16]=code_base|0x0c073742u;
r[4]+=0x0000001cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c073742u) { target=s->pc; goto dispatch; }
goto P_0c073742;
P_0c073740: /* original 741c, guest PC 0x0c073740 */
if(!s->budget--) { s->failed_pc=0x0c073740u; return 0; }
r[4]+=0x0000001cu;
goto P_0c073742;
P_0c073742: /* original 7f08, guest PC 0x0c073742 */
if(!s->budget--) { s->failed_pc=0x0c073742u; return 0; }
r[15]+=0x00000008u;
goto P_0c073744;
P_0c073744: /* original 4f26, guest PC 0x0c073744 */
if(!s->budget--) { s->failed_pc=0x0c073744u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c073746;
P_0c073746: /* original 6cf6, guest PC 0x0c073746 */
if(!s->budget--) { s->failed_pc=0x0c073746u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c073748;
P_0c073748: /* original 6df6, guest PC 0x0c073748 */
if(!s->budget--) { s->failed_pc=0x0c073748u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07374a;
P_0c07374a: /* original 000b, guest PC 0x0c07374a */
if(!s->budget--) { s->failed_pc=0x0c07374au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07374c: /* original 6ef6, guest PC 0x0c07374c */
if(!s->budget--) { s->failed_pc=0x0c07374cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07374eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07374eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
