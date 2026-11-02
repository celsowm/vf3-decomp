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
int vf3_away_batch111_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0940c8u: goto P_0c0940c8;
case 0x0c0940cau: goto P_0c0940ca;
case 0x0c0940ccu: goto P_0c0940cc;
case 0x0c0940ceu: goto P_0c0940ce;
case 0x0c0940d0u: goto P_0c0940d0;
case 0x0c0940d2u: goto P_0c0940d2;
case 0x0c0940d4u: goto P_0c0940d4;
case 0x0c0940d6u: goto P_0c0940d6;
case 0x0c0940d8u: goto P_0c0940d8;
case 0x0c0940dau: goto P_0c0940da;
case 0x0c0940dcu: goto P_0c0940dc;
case 0x0c0940deu: goto P_0c0940de;
case 0x0c0940e0u: goto P_0c0940e0;
case 0x0c0940e2u: goto P_0c0940e2;
case 0x0c0940e4u: goto P_0c0940e4;
case 0x0c0940e6u: goto P_0c0940e6;
case 0x0c0940e8u: goto P_0c0940e8;
case 0x0c0940eau: goto P_0c0940ea;
case 0x0c0940ecu: goto P_0c0940ec;
case 0x0c0940eeu: goto P_0c0940ee;
case 0x0c0940f0u: goto P_0c0940f0;
case 0x0c0940f2u: goto P_0c0940f2;
case 0x0c0940f4u: goto P_0c0940f4;
case 0x0c0940f6u: goto P_0c0940f6;
case 0x0c0940f8u: goto P_0c0940f8;
case 0x0c0940fau: goto P_0c0940fa;
case 0x0c0940fcu: goto P_0c0940fc;
case 0x0c0940feu: goto P_0c0940fe;
case 0x0c094100u: goto P_0c094100;
case 0x0c094102u: goto P_0c094102;
case 0x0c094104u: goto P_0c094104;
case 0x0c094106u: goto P_0c094106;
case 0x0c094108u: goto P_0c094108;
case 0x0c09410au: goto P_0c09410a;
case 0x0c09410cu: goto P_0c09410c;
case 0x0c09410eu: goto P_0c09410e;
case 0x0c094110u: goto P_0c094110;
case 0x0c094112u: goto P_0c094112;
case 0x0c094114u: goto P_0c094114;
case 0x0c094116u: goto P_0c094116;
case 0x0c094118u: goto P_0c094118;
case 0x0c09411au: goto P_0c09411a;
case 0x0c09411cu: goto P_0c09411c;
case 0x0c09411eu: goto P_0c09411e;
case 0x0c094120u: goto P_0c094120;
case 0x0c094122u: goto P_0c094122;
case 0x0c094124u: goto P_0c094124;
case 0x0c094126u: goto P_0c094126;
case 0x0c094128u: goto P_0c094128;
case 0x0c09412au: goto P_0c09412a;
case 0x0c09412cu: goto P_0c09412c;
case 0x0c09412eu: goto P_0c09412e;
case 0x0c094130u: goto P_0c094130;
case 0x0c094132u: goto P_0c094132;
case 0x0c094134u: goto P_0c094134;
case 0x0c094136u: goto P_0c094136;
case 0x0c094138u: goto P_0c094138;
case 0x0c09413au: goto P_0c09413a;
case 0x0c09413cu: goto P_0c09413c;
case 0x0c09413eu: goto P_0c09413e;
case 0x0c094140u: goto P_0c094140;
case 0x0c094142u: goto P_0c094142;
case 0x0c094144u: goto P_0c094144;
case 0x0c094146u: goto P_0c094146;
case 0x0c094148u: goto P_0c094148;
case 0x0c09414au: goto P_0c09414a;
case 0x0c09414cu: goto P_0c09414c;
case 0x0c09414eu: goto P_0c09414e;
case 0x0c094150u: goto P_0c094150;
case 0x0c094152u: goto P_0c094152;
case 0x0c094154u: goto P_0c094154;
case 0x0c094156u: goto P_0c094156;
case 0x0c094158u: goto P_0c094158;
case 0x0c09415au: goto P_0c09415a;
case 0x0c09415cu: goto P_0c09415c;
case 0x0c09415eu: goto P_0c09415e;
case 0x0c094160u: goto P_0c094160;
case 0x0c094162u: goto P_0c094162;
case 0x0c094164u: goto P_0c094164;
case 0x0c094166u: goto P_0c094166;
case 0x0c094168u: goto P_0c094168;
case 0x0c09416au: goto P_0c09416a;
case 0x0c09416cu: goto P_0c09416c;
case 0x0c09416eu: goto P_0c09416e;
case 0x0c094170u: goto P_0c094170;
case 0x0c094172u: goto P_0c094172;
case 0x0c094174u: goto P_0c094174;
case 0x0c094176u: goto P_0c094176;
case 0x0c094178u: goto P_0c094178;
case 0x0c09417au: goto P_0c09417a;
case 0x0c09417cu: goto P_0c09417c;
case 0x0c09417eu: goto P_0c09417e;
case 0x0c094180u: goto P_0c094180;
case 0x0c094182u: goto P_0c094182;
case 0x0c094184u: goto P_0c094184;
case 0x0c094186u: goto P_0c094186;
case 0x0c094188u: goto P_0c094188;
case 0x0c09418au: goto P_0c09418a;
case 0x0c09418cu: goto P_0c09418c;
case 0x0c09418eu: goto P_0c09418e;
case 0x0c094190u: goto P_0c094190;
case 0x0c094192u: goto P_0c094192;
case 0x0c094194u: goto P_0c094194;
case 0x0c094196u: goto P_0c094196;
case 0x0c094198u: goto P_0c094198;
case 0x0c09419au: goto P_0c09419a;
case 0x0c09419cu: goto P_0c09419c;
case 0x0c09419eu: goto P_0c09419e;
case 0x0c0941a0u: goto P_0c0941a0;
case 0x0c0941a2u: goto P_0c0941a2;
case 0x0c0941a4u: goto P_0c0941a4;
case 0x0c0941a6u: goto P_0c0941a6;
case 0x0c0941a8u: goto P_0c0941a8;
case 0x0c0941aau: goto P_0c0941aa;
case 0x0c0941acu: goto P_0c0941ac;
case 0x0c0941aeu: goto P_0c0941ae;
case 0x0c0941b0u: goto P_0c0941b0;
case 0x0c0941b2u: goto P_0c0941b2;
case 0x0c0941b4u: goto P_0c0941b4;
case 0x0c0941b6u: goto P_0c0941b6;
case 0x0c0941b8u: goto P_0c0941b8;
case 0x0c0941bau: goto P_0c0941ba;
case 0x0c0941bcu: goto P_0c0941bc;
case 0x0c0941beu: goto P_0c0941be;
case 0x0c0941c0u: goto P_0c0941c0;
case 0x0c0941c2u: goto P_0c0941c2;
case 0x0c0941c4u: goto P_0c0941c4;
case 0x0c0941c6u: goto P_0c0941c6;
case 0x0c0941c8u: goto P_0c0941c8;
case 0x0c0941cau: goto P_0c0941ca;
case 0x0c0941f8u: goto P_0c0941f8;
case 0x0c0941fau: goto P_0c0941fa;
case 0x0c0941fcu: goto P_0c0941fc;
case 0x0c0941feu: goto P_0c0941fe;
case 0x0c094200u: goto P_0c094200;
case 0x0c094202u: goto P_0c094202;
case 0x0c094204u: goto P_0c094204;
case 0x0c094206u: goto P_0c094206;
case 0x0c094208u: goto P_0c094208;
case 0x0c09420au: goto P_0c09420a;
case 0x0c09420cu: goto P_0c09420c;
case 0x0c09420eu: goto P_0c09420e;
case 0x0c094210u: goto P_0c094210;
case 0x0c094212u: goto P_0c094212;
case 0x0c094214u: goto P_0c094214;
case 0x0c094216u: goto P_0c094216;
case 0x0c094218u: goto P_0c094218;
case 0x0c09421au: goto P_0c09421a;
case 0x0c09421cu: goto P_0c09421c;
case 0x0c09421eu: goto P_0c09421e;
case 0x0c094220u: goto P_0c094220;
case 0x0c094222u: goto P_0c094222;
case 0x0c094224u: goto P_0c094224;
case 0x0c094226u: goto P_0c094226;
case 0x0c094228u: goto P_0c094228;
case 0x0c09422au: goto P_0c09422a;
case 0x0c09422cu: goto P_0c09422c;
case 0x0c09422eu: goto P_0c09422e;
case 0x0c094230u: goto P_0c094230;
case 0x0c094232u: goto P_0c094232;
case 0x0c094234u: goto P_0c094234;
case 0x0c094236u: goto P_0c094236;
case 0x0c094238u: goto P_0c094238;
case 0x0c09423au: goto P_0c09423a;
case 0x0c09423cu: goto P_0c09423c;
case 0x0c09423eu: goto P_0c09423e;
case 0x0c094240u: goto P_0c094240;
case 0x0c094242u: goto P_0c094242;
case 0x0c094244u: goto P_0c094244;
case 0x0c094246u: goto P_0c094246;
case 0x0c094248u: goto P_0c094248;
case 0x0c09424au: goto P_0c09424a;
case 0x0c09424cu: goto P_0c09424c;
case 0x0c09424eu: goto P_0c09424e;
case 0x0c094250u: goto P_0c094250;
case 0x0c094252u: goto P_0c094252;
case 0x0c094254u: goto P_0c094254;
case 0x0c094256u: goto P_0c094256;
case 0x0c094258u: goto P_0c094258;
case 0x0c09425au: goto P_0c09425a;
case 0x0c09425cu: goto P_0c09425c;
case 0x0c09425eu: goto P_0c09425e;
case 0x0c094260u: goto P_0c094260;
case 0x0c094262u: goto P_0c094262;
case 0x0c094264u: goto P_0c094264;
case 0x0c094266u: goto P_0c094266;
case 0x0c094268u: goto P_0c094268;
case 0x0c09426au: goto P_0c09426a;
case 0x0c09426cu: goto P_0c09426c;
case 0x0c09426eu: goto P_0c09426e;
case 0x0c094270u: goto P_0c094270;
case 0x0c094272u: goto P_0c094272;
case 0x0c094274u: goto P_0c094274;
case 0x0c094276u: goto P_0c094276;
case 0x0c094278u: goto P_0c094278;
case 0x0c09427au: goto P_0c09427a;
case 0x0c09427cu: goto P_0c09427c;
case 0x0c09427eu: goto P_0c09427e;
case 0x0c094280u: goto P_0c094280;
case 0x0c094282u: goto P_0c094282;
case 0x0c094284u: goto P_0c094284;
case 0x0c094286u: goto P_0c094286;
case 0x0c094288u: goto P_0c094288;
case 0x0c09428au: goto P_0c09428a;
case 0x0c09428cu: goto P_0c09428c;
case 0x0c09428eu: goto P_0c09428e;
case 0x0c094290u: goto P_0c094290;
case 0x0c094292u: goto P_0c094292;
case 0x0c094294u: goto P_0c094294;
case 0x0c094296u: goto P_0c094296;
case 0x0c094298u: goto P_0c094298;
case 0x0c09429au: goto P_0c09429a;
case 0x0c09429cu: goto P_0c09429c;
case 0x0c09429eu: goto P_0c09429e;
case 0x0c0942a0u: goto P_0c0942a0;
case 0x0c0942a2u: goto P_0c0942a2;
case 0x0c0942a4u: goto P_0c0942a4;
case 0x0c0942a6u: goto P_0c0942a6;
case 0x0c0942a8u: goto P_0c0942a8;
case 0x0c0942aau: goto P_0c0942aa;
case 0x0c0942acu: goto P_0c0942ac;
case 0x0c0942aeu: goto P_0c0942ae;
case 0x0c0942b0u: goto P_0c0942b0;
case 0x0c0942b2u: goto P_0c0942b2;
case 0x0c0942b4u: goto P_0c0942b4;
case 0x0c0942b6u: goto P_0c0942b6;
case 0x0c0942b8u: goto P_0c0942b8;
case 0x0c0942bau: goto P_0c0942ba;
case 0x0c0942bcu: goto P_0c0942bc;
case 0x0c0942beu: goto P_0c0942be;
case 0x0c0942c0u: goto P_0c0942c0;
case 0x0c0942c2u: goto P_0c0942c2;
case 0x0c0942c4u: goto P_0c0942c4;
case 0x0c0942c6u: goto P_0c0942c6;
case 0x0c0942c8u: goto P_0c0942c8;
case 0x0c0942cau: goto P_0c0942ca;
case 0x0c0942ccu: goto P_0c0942cc;
case 0x0c0942ceu: goto P_0c0942ce;
case 0x0c0942d0u: goto P_0c0942d0;
case 0x0c0942fcu: goto P_0c0942fc;
case 0x0c0942feu: goto P_0c0942fe;
case 0x0c094300u: goto P_0c094300;
case 0x0c094302u: goto P_0c094302;
case 0x0c094304u: goto P_0c094304;
case 0x0c094306u: goto P_0c094306;
case 0x0c094308u: goto P_0c094308;
case 0x0c09430au: goto P_0c09430a;
case 0x0c09430cu: goto P_0c09430c;
case 0x0c09430eu: goto P_0c09430e;
case 0x0c094310u: goto P_0c094310;
case 0x0c094312u: goto P_0c094312;
case 0x0c094314u: goto P_0c094314;
case 0x0c094316u: goto P_0c094316;
case 0x0c094318u: goto P_0c094318;
case 0x0c09431au: goto P_0c09431a;
case 0x0c09431cu: goto P_0c09431c;
case 0x0c09431eu: goto P_0c09431e;
case 0x0c094320u: goto P_0c094320;
case 0x0c094322u: goto P_0c094322;
case 0x0c094324u: goto P_0c094324;
case 0x0c094326u: goto P_0c094326;
case 0x0c094328u: goto P_0c094328;
case 0x0c09432au: goto P_0c09432a;
case 0x0c09432cu: goto P_0c09432c;
case 0x0c09432eu: goto P_0c09432e;
case 0x0c094330u: goto P_0c094330;
case 0x0c094332u: goto P_0c094332;
case 0x0c094334u: goto P_0c094334;
case 0x0c094336u: goto P_0c094336;
case 0x0c094338u: goto P_0c094338;
case 0x0c09433au: goto P_0c09433a;
case 0x0c09433cu: goto P_0c09433c;
case 0x0c09433eu: goto P_0c09433e;
case 0x0c094340u: goto P_0c094340;
case 0x0c094342u: goto P_0c094342;
case 0x0c094344u: goto P_0c094344;
case 0x0c094346u: goto P_0c094346;
case 0x0c094348u: goto P_0c094348;
case 0x0c09434au: goto P_0c09434a;
case 0x0c09434cu: goto P_0c09434c;
case 0x0c09434eu: goto P_0c09434e;
case 0x0c094350u: goto P_0c094350;
case 0x0c094352u: goto P_0c094352;
case 0x0c094354u: goto P_0c094354;
case 0x0c094356u: goto P_0c094356;
case 0x0c094358u: goto P_0c094358;
case 0x0c09435au: goto P_0c09435a;
case 0x0c09435cu: goto P_0c09435c;
case 0x0c09435eu: goto P_0c09435e;
case 0x0c094360u: goto P_0c094360;
case 0x0c094362u: goto P_0c094362;
case 0x0c094364u: goto P_0c094364;
case 0x0c094366u: goto P_0c094366;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0940c8: /* original 2fe6, guest PC 0x0c0940c8 */
if(!s->budget--) { s->failed_pc=0x0c0940c8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0940ca;
P_0c0940ca: /* original e140, guest PC 0x0c0940ca */
if(!s->budget--) { s->failed_pc=0x0c0940cau; return 0; }
r[1]=0x00000040u;
goto P_0c0940cc;
P_0c0940cc: /* original 2fd6, guest PC 0x0c0940cc */
if(!s->budget--) { s->failed_pc=0x0c0940ccu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0940ce;
P_0c0940ce: /* original 6d43, guest PC 0x0c0940ce */
if(!s->budget--) { s->failed_pc=0x0c0940ceu; return 0; }
r[13]=r[4];
goto P_0c0940d0;
P_0c0940d0: /* original 2fc6, guest PC 0x0c0940d0 */
if(!s->budget--) { s->failed_pc=0x0c0940d0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0940d2;
P_0c0940d2: /* original d243, guest PC 0x0c0940d2 */
if(!s->budget--) { s->failed_pc=0x0c0940d2u; return 0; }
r[2]=read(ram,0x0c0941e0u,4);
goto P_0c0940d4;
P_0c0940d4: /* original d341, guest PC 0x0c0940d4 */
if(!s->budget--) { s->failed_pc=0x0c0940d4u; return 0; }
r[3]=read(ram,0x0c0941dcu,4);
goto P_0c0940d6;
P_0c0940d6: /* original 6422, guest PC 0x0c0940d6 */
if(!s->budget--) { s->failed_pc=0x0c0940d6u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0940d8;
P_0c0940d8: /* original 4f22, guest PC 0x0c0940d8 */
if(!s->budget--) { s->failed_pc=0x0c0940d8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0940da;
P_0c0940da: /* original 6e32, guest PC 0x0c0940da */
if(!s->budget--) { s->failed_pc=0x0c0940dau; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c0940dc;
P_0c0940dc: /* original 2148, guest PC 0x0c0940dc */
if(!s->budget--) { s->failed_pc=0x0c0940dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c0940de;
P_0c0940de: /* original 8b34, guest PC 0x0c0940de */
if(!s->budget--) { s->failed_pc=0x0c0940deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09414a; }
goto P_0c0940e0;
P_0c0940e0: /* original 65e2, guest PC 0x0c0940e0 */
if(!s->budget--) { s->failed_pc=0x0c0940e0u; return 0; }
tmp=read(ram,r[14],4);
r[5]=tmp;
goto P_0c0940e2;
P_0c0940e2: /* original e201, guest PC 0x0c0940e2 */
if(!s->budget--) { s->failed_pc=0x0c0940e2u; return 0; }
r[2]=0x00000001u;
goto P_0c0940e4;
P_0c0940e4: /* original 2528, guest PC 0x0c0940e4 */
if(!s->budget--) { s->failed_pc=0x0c0940e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0940e6;
P_0c0940e6: /* original 8930, guest PC 0x0c0940e6 */
if(!s->budget--) { s->failed_pc=0x0c0940e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09414a; }
goto P_0c0940e8;
P_0c0940e8: /* original 9370, guest PC 0x0c0940e8 */
if(!s->budget--) { s->failed_pc=0x0c0940e8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0941ccu,2);
goto P_0c0940ea;
P_0c0940ea: /* original 2438, guest PC 0x0c0940ea */
if(!s->budget--) { s->failed_pc=0x0c0940eau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0940ec;
P_0c0940ec: /* original 8b10, guest PC 0x0c0940ec */
if(!s->budget--) { s->failed_pc=0x0c0940ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094110; }
goto P_0c0940ee;
P_0c0940ee: /* original e060, guest PC 0x0c0940ee */
if(!s->budget--) { s->failed_pc=0x0c0940eeu; return 0; }
r[0]=0x00000060u;
goto P_0c0940f0;
P_0c0940f0: /* original 00dc, guest PC 0x0c0940f0 */
if(!s->budget--) { s->failed_pc=0x0c0940f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c0940f2;
P_0c0940f2: /* original 600c, guest PC 0x0c0940f2 */
if(!s->budget--) { s->failed_pc=0x0c0940f2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0940f4;
P_0c0940f4: /* original 880f, guest PC 0x0c0940f4 */
if(!s->budget--) { s->failed_pc=0x0c0940f4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c0940f6;
P_0c0940f6: /* original 8b0b, guest PC 0x0c0940f6 */
if(!s->budget--) { s->failed_pc=0x0c0940f6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094110; }
goto P_0c0940f8;
P_0c0940f8: /* original 85e8, guest PC 0x0c0940f8 */
if(!s->budget--) { s->failed_pc=0x0c0940f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+16,2);
goto P_0c0940fa;
P_0c0940fa: /* original 600d, guest PC 0x0c0940fa */
if(!s->budget--) { s->failed_pc=0x0c0940fau; return 0; }
r[0]=r[0]&65535u;
goto P_0c0940fc;
P_0c0940fc: /* original c801, guest PC 0x0c0940fc */
if(!s->budget--) { s->failed_pc=0x0c0940fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0940fe;
P_0c0940fe: /* original 8b07, guest PC 0x0c0940fe */
if(!s->budget--) { s->failed_pc=0x0c0940feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094110; }
goto P_0c094100;
P_0c094100: /* original 9c65, guest PC 0x0c094100 */
if(!s->budget--) { s->failed_pc=0x0c094100u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0941ceu,2);
goto P_0c094102;
P_0c094102: /* original 3cec, guest PC 0x0c094102 */
if(!s->budget--) { s->failed_pc=0x0c094102u; return 0; }
r[12]+=r[14];
goto P_0c094104;
P_0c094104: /* original 0c83, guest PC 0x0c094104 */
if(!s->budget--) { s->failed_pc=0x0c094104u; return 0; }
if((r[12]&0xFC000000u)==0xE0000000u) pref(ram,r[12]);
goto P_0c094106;
P_0c094106: /* original d337, guest PC 0x0c094106 */
if(!s->budget--) { s->failed_pc=0x0c094106u; return 0; }
r[3]=read(ram,0x0c0941e4u,4);
goto P_0c094108;
P_0c094108: /* original 65c3, guest PC 0x0c094108 */
if(!s->budget--) { s->failed_pc=0x0c094108u; return 0; }
r[5]=r[12];
goto P_0c09410a;
P_0c09410a: /* original 9461, guest PC 0x0c09410a */
if(!s->budget--) { s->failed_pc=0x0c09410au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0941d0u,2);
goto P_0c09410c;
P_0c09410c: /* original 430b, guest PC 0x0c09410c */
if(!s->budget--) { s->failed_pc=0x0c09410cu; return 0; }
target=r[3];
r[16]=code_base|0x0c094110u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c094110u) { target=s->pc; goto dispatch; }
goto P_0c094110;
P_0c09410e: /* original 34dc, guest PC 0x0c09410e */
if(!s->budget--) { s->failed_pc=0x0c09410eu; return 0; }
r[4]+=r[13];
goto P_0c094110;
P_0c094110: /* original 84d4, guest PC 0x0c094110 */
if(!s->budget--) { s->failed_pc=0x0c094110u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+4,1);
goto P_0c094112;
P_0c094112: /* original 67c3, guest PC 0x0c094112 */
if(!s->budget--) { s->failed_pc=0x0c094112u; return 0; }
r[7]=r[12];
goto P_0c094114;
P_0c094114: /* original 925d, guest PC 0x0c094114 */
if(!s->budget--) { s->failed_pc=0x0c094114u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0941d2u,2);
goto P_0c094116;
P_0c094116: /* original 65d3, guest PC 0x0c094116 */
if(!s->budget--) { s->failed_pc=0x0c094116u; return 0; }
r[5]=r[13];
goto P_0c094118;
P_0c094118: /* original 6403, guest PC 0x0c094118 */
if(!s->budget--) { s->failed_pc=0x0c094118u; return 0; }
r[4]=r[0];
goto P_0c09411a;
P_0c09411a: /* original 664c, guest PC 0x0c09411a */
if(!s->budget--) { s->failed_pc=0x0c09411au; return 0; }
r[6]=r[4]&255u;
goto P_0c09411c;
P_0c09411c: /* original 6363, guest PC 0x0c09411c */
if(!s->budget--) { s->failed_pc=0x0c09411cu; return 0; }
r[3]=r[6];
goto P_0c09411e;
P_0c09411e: /* original 4600, guest PC 0x0c09411e */
if(!s->budget--) { s->failed_pc=0x0c09411eu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c094120;
P_0c094120: /* original 363c, guest PC 0x0c094120 */
if(!s->budget--) { s->failed_pc=0x0c094120u; return 0; }
r[6]+=r[3];
goto P_0c094122;
P_0c094122: /* original 6303, guest PC 0x0c094122 */
if(!s->budget--) { s->failed_pc=0x0c094122u; return 0; }
r[3]=r[0];
goto P_0c094124;
P_0c094124: /* original 4618, guest PC 0x0c094124 */
if(!s->budget--) { s->failed_pc=0x0c094124u; return 0; }
r[6]<<=8;
goto P_0c094126;
P_0c094126: /* original 4608, guest PC 0x0c094126 */
if(!s->budget--) { s->failed_pc=0x0c094126u; return 0; }
r[6]<<=2;
goto P_0c094128;
P_0c094128: /* original 4608, guest PC 0x0c094128 */
if(!s->budget--) { s->failed_pc=0x0c094128u; return 0; }
r[6]<<=2;
goto P_0c09412a;
P_0c09412a: /* original 32ec, guest PC 0x0c09412a */
if(!s->budget--) { s->failed_pc=0x0c09412au; return 0; }
r[2]+=r[14];
goto P_0c09412c;
P_0c09412c: /* original 666f, guest PC 0x0c09412c */
if(!s->budget--) { s->failed_pc=0x0c09412cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c09412e;
P_0c09412e: /* original 4408, guest PC 0x0c09412e */
if(!s->budget--) { s->failed_pc=0x0c09412eu; return 0; }
r[4]<<=2;
goto P_0c094130;
P_0c094130: /* original 362c, guest PC 0x0c094130 */
if(!s->budget--) { s->failed_pc=0x0c094130u; return 0; }
r[6]+=r[2];
goto P_0c094132;
P_0c094132: /* original 924f, guest PC 0x0c094132 */
if(!s->budget--) { s->failed_pc=0x0c094132u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0941d4u,2);
goto P_0c094134;
P_0c094134: /* original 343c, guest PC 0x0c094134 */
if(!s->budget--) { s->failed_pc=0x0c094134u; return 0; }
r[4]+=r[3];
goto P_0c094136;
P_0c094136: /* original 4408, guest PC 0x0c094136 */
if(!s->budget--) { s->failed_pc=0x0c094136u; return 0; }
r[4]<<=2;
goto P_0c094138;
P_0c094138: /* original 32ec, guest PC 0x0c094138 */
if(!s->budget--) { s->failed_pc=0x0c094138u; return 0; }
r[2]+=r[14];
goto P_0c09413a;
P_0c09413a: /* original 644e, guest PC 0x0c09413a */
if(!s->budget--) { s->failed_pc=0x0c09413au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c09413c;
P_0c09413c: /* original 342c, guest PC 0x0c09413c */
if(!s->budget--) { s->failed_pc=0x0c09413cu; return 0; }
r[4]+=r[2];
goto P_0c09413e;
P_0c09413e: /* original 8541, guest PC 0x0c09413e */
if(!s->budget--) { s->failed_pc=0x0c09413eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c094140;
P_0c094140: /* original 6403, guest PC 0x0c094140 */
if(!s->budget--) { s->failed_pc=0x0c094140u; return 0; }
r[4]=r[0];
goto P_0c094142;
P_0c094142: /* original 2f06, guest PC 0x0c094142 */
if(!s->budget--) { s->failed_pc=0x0c094142u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094144;
P_0c094144: /* original b006, guest PC 0x0c094144 */
if(!s->budget--) { s->failed_pc=0x0c094144u; return 0; }
target=code_base|0x0c094154u; r[16]=code_base|0x0c094148u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c094148u) { target=s->pc; goto dispatch; }
goto P_0c094148;
P_0c094146: /* original 64e3, guest PC 0x0c094146 */
if(!s->budget--) { s->failed_pc=0x0c094146u; return 0; }
r[4]=r[14];
goto P_0c094148;
P_0c094148: /* original 7f04, guest PC 0x0c094148 */
if(!s->budget--) { s->failed_pc=0x0c094148u; return 0; }
r[15]+=0x00000004u;
goto P_0c09414a;
P_0c09414a: /* original 4f26, guest PC 0x0c09414a */
if(!s->budget--) { s->failed_pc=0x0c09414au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09414c;
P_0c09414c: /* original 6cf6, guest PC 0x0c09414c */
if(!s->budget--) { s->failed_pc=0x0c09414cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09414e;
P_0c09414e: /* original 6df6, guest PC 0x0c09414e */
if(!s->budget--) { s->failed_pc=0x0c09414eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c094150;
P_0c094150: /* original 000b, guest PC 0x0c094150 */
if(!s->budget--) { s->failed_pc=0x0c094150u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c094152: /* original 6ef6, guest PC 0x0c094152 */
if(!s->budget--) { s->failed_pc=0x0c094152u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c094154;
P_0c094154: /* original 2fe6, guest PC 0x0c094154 */
if(!s->budget--) { s->failed_pc=0x0c094154u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094156;
P_0c094156: /* original 6e63, guest PC 0x0c094156 */
if(!s->budget--) { s->failed_pc=0x0c094156u; return 0; }
r[14]=r[6];
goto P_0c094158;
P_0c094158: /* original 2fd6, guest PC 0x0c094158 */
if(!s->budget--) { s->failed_pc=0x0c094158u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09415a;
P_0c09415a: /* original 2fc6, guest PC 0x0c09415a */
if(!s->budget--) { s->failed_pc=0x0c09415au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09415c;
P_0c09415c: /* original 2fb6, guest PC 0x0c09415c */
if(!s->budget--) { s->failed_pc=0x0c09415cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09415e;
P_0c09415e: /* original 2fa6, guest PC 0x0c09415e */
if(!s->budget--) { s->failed_pc=0x0c09415eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094160;
P_0c094160: /* original 6a73, guest PC 0x0c094160 */
if(!s->budget--) { s->failed_pc=0x0c094160u; return 0; }
r[10]=r[7];
goto P_0c094162;
P_0c094162: /* original 4f22, guest PC 0x0c094162 */
if(!s->budget--) { s->failed_pc=0x0c094162u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c094164;
P_0c094164: /* original 7ff0, guest PC 0x0c094164 */
if(!s->budget--) { s->failed_pc=0x0c094164u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c094166;
P_0c094166: /* original 2f52, guest PC 0x0c094166 */
if(!s->budget--) { s->failed_pc=0x0c094166u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c094168;
P_0c094168: /* original e034, guest PC 0x0c094168 */
if(!s->budget--) { s->failed_pc=0x0c094168u; return 0; }
r[0]=0x00000034u;
goto P_0c09416a;
P_0c09416a: /* original 04ed, guest PC 0x0c09416a */
if(!s->budget--) { s->failed_pc=0x0c09416au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09416c;
P_0c09416c: /* original e302, guest PC 0x0c09416c */
if(!s->budget--) { s->failed_pc=0x0c09416cu; return 0; }
r[3]=0x00000002u;
goto P_0c09416e;
P_0c09416e: /* original 6d4d, guest PC 0x0c09416e */
if(!s->budget--) { s->failed_pc=0x0c09416eu; return 0; }
r[13]=r[4]&65535u;
goto P_0c094170;
P_0c094170: /* original 23d8, guest PC 0x0c094170 */
if(!s->budget--) { s->failed_pc=0x0c094170u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c094172;
P_0c094172: /* original 890b, guest PC 0x0c094172 */
if(!s->budget--) { s->failed_pc=0x0c094172u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09418c; }
goto P_0c094174;
P_0c094174: /* original 53fa, guest PC 0x0c094174 */
if(!s->budget--) { s->failed_pc=0x0c094174u; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c094176;
P_0c094176: /* original 6be3, guest PC 0x0c094176 */
if(!s->budget--) { s->failed_pc=0x0c094176u; return 0; }
r[11]=r[14];
goto P_0c094178;
P_0c094178: /* original 4315, guest PC 0x0c094178 */
if(!s->budget--) { s->failed_pc=0x0c094178u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c09417a;
P_0c09417a: /* original 8d03, guest PC 0x0c09417a */
if(!s->budget--) { s->failed_pc=0x0c09417au; return 0; }
cond=r[17]&1u;
r[11]+=0x00000058u;
if(cond) { goto P_0c094184; }
goto P_0c09417e;
P_0c09417c: /* original 7b58, guest PC 0x0c09417c */
if(!s->budget--) { s->failed_pc=0x0c09417cu; return 0; }
r[11]+=0x00000058u;
goto P_0c09417e;
P_0c09417e: /* original d21a, guest PC 0x0c09417e */
if(!s->budget--) { s->failed_pc=0x0c09417eu; return 0; }
r[2]=read(ram,0x0c0941e8u,4);
goto P_0c094180;
P_0c094180: /* original 422b, guest PC 0x0c094180 */
if(!s->budget--) { s->failed_pc=0x0c094180u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c094358u: goto P_0c094358;
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
P_0c094182: /* original 0009, guest PC 0x0c094182 */
if(!s->budget--) { s->failed_pc=0x0c094182u; return 0; }
goto P_0c094184;
P_0c094184: /* original 52fa, guest PC 0x0c094184 */
if(!s->budget--) { s->failed_pc=0x0c094184u; return 0; }
r[2]=read(ram,r[15]+40,4);
goto P_0c094186;
P_0c094186: /* original 72ff, guest PC 0x0c094186 */
if(!s->budget--) { s->failed_pc=0x0c094186u; return 0; }
r[2]+=0xffffffffu;
goto P_0c094188;
P_0c094188: /* original a002, guest PC 0x0c094188 */
if(!s->budget--) { s->failed_pc=0x0c094188u; return 0; }
write(ram,r[15]+40,r[2],4);
goto P_0c094190;
P_0c09418a: /* original 1f2a, guest PC 0x0c09418a */
if(!s->budget--) { s->failed_pc=0x0c09418au; return 0; }
write(ram,r[15]+40,r[2],4);
goto P_0c09418c;
P_0c09418c: /* original 6be3, guest PC 0x0c09418c */
if(!s->budget--) { s->failed_pc=0x0c09418cu; return 0; }
r[11]=r[14];
goto P_0c09418e;
P_0c09418e: /* original 7b38, guest PC 0x0c09418e */
if(!s->budget--) { s->failed_pc=0x0c09418eu; return 0; }
r[11]+=0x00000038u;
goto P_0c094190;
P_0c094190: /* original e201, guest PC 0x0c094190 */
if(!s->budget--) { s->failed_pc=0x0c094190u; return 0; }
r[2]=0x00000001u;
goto P_0c094192;
P_0c094192: /* original 22d8, guest PC 0x0c094192 */
if(!s->budget--) { s->failed_pc=0x0c094192u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c094194;
P_0c094194: /* original 8b02, guest PC 0x0c094194 */
if(!s->budget--) { s->failed_pc=0x0c094194u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09419c; }
goto P_0c094196;
P_0c094196: /* original d314, guest PC 0x0c094196 */
if(!s->budget--) { s->failed_pc=0x0c094196u; return 0; }
r[3]=read(ram,0x0c0941e8u,4);
goto P_0c094198;
P_0c094198: /* original 432b, guest PC 0x0c094198 */
if(!s->budget--) { s->failed_pc=0x0c094198u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c094358u: goto P_0c094358;
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
P_0c09419a: /* original 0009, guest PC 0x0c09419a */
if(!s->budget--) { s->failed_pc=0x0c09419au; return 0; }
goto P_0c09419c;
P_0c09419c: /* original e314, guest PC 0x0c09419c */
if(!s->budget--) { s->failed_pc=0x0c09419cu; return 0; }
r[3]=0x00000014u;
goto P_0c09419e;
P_0c09419e: /* original 23d8, guest PC 0x0c09419e */
if(!s->budget--) { s->failed_pc=0x0c09419eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0941a0;
P_0c0941a0: /* original 8906, guest PC 0x0c0941a0 */
if(!s->budget--) { s->failed_pc=0x0c0941a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0941b0; }
goto P_0c0941a2;
P_0c0941a2: /* original d312, guest PC 0x0c0941a2 */
if(!s->budget--) { s->failed_pc=0x0c0941a2u; return 0; }
r[3]=read(ram,0x0c0941ecu,4);
goto P_0c0941a4;
P_0c0941a4: /* original 65e3, guest PC 0x0c0941a4 */
if(!s->budget--) { s->failed_pc=0x0c0941a4u; return 0; }
r[5]=r[14];
goto P_0c0941a6;
P_0c0941a6: /* original 430b, guest PC 0x0c0941a6 */
if(!s->budget--) { s->failed_pc=0x0c0941a6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0941aau;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0941aau) { target=s->pc; goto dispatch; }
goto P_0c0941aa;
P_0c0941a8: /* original 64f2, guest PC 0x0c0941a8 */
if(!s->budget--) { s->failed_pc=0x0c0941a8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0941aa;
P_0c0941aa: /* original d211, guest PC 0x0c0941aa */
if(!s->budget--) { s->failed_pc=0x0c0941aau; return 0; }
r[2]=read(ram,0x0c0941f0u,4);
goto P_0c0941ac;
P_0c0941ac: /* original 422b, guest PC 0x0c0941ac */
if(!s->budget--) { s->failed_pc=0x0c0941acu; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c094352u: goto P_0c094352;
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
P_0c0941ae: /* original 0009, guest PC 0x0c0941ae */
if(!s->budget--) { s->failed_pc=0x0c0941aeu; return 0; }
goto P_0c0941b0;
P_0c0941b0: /* original 9311, guest PC 0x0c0941b0 */
if(!s->budget--) { s->failed_pc=0x0c0941b0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0941d6u,2);
goto P_0c0941b2;
P_0c0941b2: /* original 23d8, guest PC 0x0c0941b2 */
if(!s->budget--) { s->failed_pc=0x0c0941b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0941b4;
P_0c0941b4: /* original 8902, guest PC 0x0c0941b4 */
if(!s->budget--) { s->failed_pc=0x0c0941b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0941bc; }
goto P_0c0941b6;
P_0c0941b6: /* original d20e, guest PC 0x0c0941b6 */
if(!s->budget--) { s->failed_pc=0x0c0941b6u; return 0; }
r[2]=read(ram,0x0c0941f0u,4);
goto P_0c0941b8;
P_0c0941b8: /* original 422b, guest PC 0x0c0941b8 */
if(!s->budget--) { s->failed_pc=0x0c0941b8u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c094352u: goto P_0c094352;
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
P_0c0941ba: /* original 0009, guest PC 0x0c0941ba */
if(!s->budget--) { s->failed_pc=0x0c0941bau; return 0; }
goto P_0c0941bc;
P_0c0941bc: /* original 920c, guest PC 0x0c0941bc */
if(!s->budget--) { s->failed_pc=0x0c0941bcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0941d8u,2);
goto P_0c0941be;
P_0c0941be: /* original 22d8, guest PC 0x0c0941be */
if(!s->budget--) { s->failed_pc=0x0c0941beu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0941c0;
P_0c0941c0: /* original 8902, guest PC 0x0c0941c0 */
if(!s->budget--) { s->failed_pc=0x0c0941c0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0941c8; }
goto P_0c0941c2;
P_0c0941c2: /* original d30c, guest PC 0x0c0941c2 */
if(!s->budget--) { s->failed_pc=0x0c0941c2u; return 0; }
r[3]=read(ram,0x0c0941f4u,4);
goto P_0c0941c4;
P_0c0941c4: /* original 432b, guest PC 0x0c0941c4 */
if(!s->budget--) { s->failed_pc=0x0c0941c4u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09429au: goto P_0c09429a;
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
P_0c0941c6: /* original 0009, guest PC 0x0c0941c6 */
if(!s->budget--) { s->failed_pc=0x0c0941c6u; return 0; }
goto P_0c0941c8;
P_0c0941c8: /* original a016, guest PC 0x0c0941c8 */
if(!s->budget--) { s->failed_pc=0x0c0941c8u; return 0; }
goto P_0c0941f8;
P_0c0941ca: /* original 0009, guest PC 0x0c0941ca */
if(!s->budget--) { s->failed_pc=0x0c0941cau; return 0; }
if(!vf3_matrix_family(0x0c0941ccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0941ccu; return 0; } return 1;
P_0c0941f8: /* original fbfd, guest PC 0x0c0941f8 */
if(!s->budget--) { s->failed_pc=0x0c0941f8u; return 0; }
vf3_matrix_swap(s);
goto P_0c0941fa;
P_0c0941fa: /* original f09d, guest PC 0x0c0941fa */
if(!s->budget--) { s->failed_pc=0x0c0941fau; return 0; }
fr[0]=0x3f800000u;
goto P_0c0941fc;
P_0c0941fc: /* original f18d, guest PC 0x0c0941fc */
if(!s->budget--) { s->failed_pc=0x0c0941fcu; return 0; }
fr[1]=0;
goto P_0c0941fe;
P_0c0941fe: /* original f28d, guest PC 0x0c0941fe */
if(!s->budget--) { s->failed_pc=0x0c0941feu; return 0; }
fr[2]=0;
goto P_0c094200;
P_0c094200: /* original f48d, guest PC 0x0c094200 */
if(!s->budget--) { s->failed_pc=0x0c094200u; return 0; }
fr[4]=0;
goto P_0c094202;
P_0c094202: /* original f59d, guest PC 0x0c094202 */
if(!s->budget--) { s->failed_pc=0x0c094202u; return 0; }
fr[5]=0x3f800000u;
goto P_0c094204;
P_0c094204: /* original f68d, guest PC 0x0c094204 */
if(!s->budget--) { s->failed_pc=0x0c094204u; return 0; }
fr[6]=0;
goto P_0c094206;
P_0c094206: /* original f88d, guest PC 0x0c094206 */
if(!s->budget--) { s->failed_pc=0x0c094206u; return 0; }
fr[8]=0;
goto P_0c094208;
P_0c094208: /* original f98d, guest PC 0x0c094208 */
if(!s->budget--) { s->failed_pc=0x0c094208u; return 0; }
fr[9]=0;
goto P_0c09420a;
P_0c09420a: /* original fa9d, guest PC 0x0c09420a */
if(!s->budget--) { s->failed_pc=0x0c09420au; return 0; }
fr[10]=0x3f800000u;
goto P_0c09420c;
P_0c09420c: /* original fbfd, guest PC 0x0c09420c */
if(!s->budget--) { s->failed_pc=0x0c09420cu; return 0; }
vf3_matrix_swap(s);
goto P_0c09420e;
P_0c09420e: /* original 0009, guest PC 0x0c09420e */
if(!s->budget--) { s->failed_pc=0x0c09420eu; return 0; }
goto P_0c094210;
P_0c094210: /* original 64e3, guest PC 0x0c094210 */
if(!s->budget--) { s->failed_pc=0x0c094210u; return 0; }
r[4]=r[14];
goto P_0c094212;
P_0c094212: /* original 740c, guest PC 0x0c094212 */
if(!s->budget--) { s->failed_pc=0x0c094212u; return 0; }
r[4]+=0x0000000cu;
goto P_0c094214;
P_0c094214: /* original fbfd, guest PC 0x0c094214 */
if(!s->budget--) { s->failed_pc=0x0c094214u; return 0; }
vf3_matrix_swap(s);
goto P_0c094216;
P_0c094216: /* original fc49, guest PC 0x0c094216 */
if(!s->budget--) { s->failed_pc=0x0c094216u; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094218;
P_0c094218: /* original fd49, guest PC 0x0c094218 */
if(!s->budget--) { s->failed_pc=0x0c094218u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09421a;
P_0c09421a: /* original fe49, guest PC 0x0c09421a */
if(!s->budget--) { s->failed_pc=0x0c09421au; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09421c;
P_0c09421c: /* original fbfd, guest PC 0x0c09421c */
if(!s->budget--) { s->failed_pc=0x0c09421cu; return 0; }
vf3_matrix_swap(s);
goto P_0c09421e;
P_0c09421e: /* original 0009, guest PC 0x0c09421e */
if(!s->budget--) { s->failed_pc=0x0c09421eu; return 0; }
goto P_0c094220;
P_0c094220: /* original 64f3, guest PC 0x0c094220 */
if(!s->budget--) { s->failed_pc=0x0c094220u; return 0; }
r[4]=r[15];
goto P_0c094222;
P_0c094222: /* original 66e3, guest PC 0x0c094222 */
if(!s->budget--) { s->failed_pc=0x0c094222u; return 0; }
r[6]=r[14];
goto P_0c094224;
P_0c094224: /* original 7404, guest PC 0x0c094224 */
if(!s->budget--) { s->failed_pc=0x0c094224u; return 0; }
r[4]+=0x00000004u;
goto P_0c094226;
P_0c094226: /* original 65e3, guest PC 0x0c094226 */
if(!s->budget--) { s->failed_pc=0x0c094226u; return 0; }
r[5]=r[14];
goto P_0c094228;
P_0c094228: /* original 760c, guest PC 0x0c094228 */
if(!s->budget--) { s->failed_pc=0x0c094228u; return 0; }
r[6]+=0x0000000cu;
goto P_0c09422a;
P_0c09422a: /* original f059, guest PC 0x0c09422a */
if(!s->budget--) { s->failed_pc=0x0c09422au; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c09422c;
P_0c09422c: /* original f369, guest PC 0x0c09422c */
if(!s->budget--) { s->failed_pc=0x0c09422cu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c09422e;
P_0c09422e: /* original f159, guest PC 0x0c09422e */
if(!s->budget--) { s->failed_pc=0x0c09422eu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c094230;
P_0c094230: /* original f469, guest PC 0x0c094230 */
if(!s->budget--) { s->failed_pc=0x0c094230u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c094232;
P_0c094232: /* original f031, guest PC 0x0c094232 */
if(!s->budget--) { s->failed_pc=0x0c094232u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c094234;
P_0c094234: /* original f258, guest PC 0x0c094234 */
if(!s->budget--) { s->failed_pc=0x0c094234u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c094236;
P_0c094236: /* original f568, guest PC 0x0c094236 */
if(!s->budget--) { s->failed_pc=0x0c094236u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c094238;
P_0c094238: /* original f141, guest PC 0x0c094238 */
if(!s->budget--) { s->failed_pc=0x0c094238u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c09423a;
P_0c09423a: /* original f251, guest PC 0x0c09423a */
if(!s->budget--) { s->failed_pc=0x0c09423au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c09423c;
P_0c09423c: /* original 7408, guest PC 0x0c09423c */
if(!s->budget--) { s->failed_pc=0x0c09423cu; return 0; }
r[4]+=0x00000008u;
goto P_0c09423e;
P_0c09423e: /* original f42a, guest PC 0x0c09423e */
if(!s->budget--) { s->failed_pc=0x0c09423eu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c094240;
P_0c094240: /* original f41b, guest PC 0x0c094240 */
if(!s->budget--) { s->failed_pc=0x0c094240u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c094242;
P_0c094242: /* original f40b, guest PC 0x0c094242 */
if(!s->budget--) { s->failed_pc=0x0c094242u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c094244;
P_0c094244: /* original 64f3, guest PC 0x0c094244 */
if(!s->budget--) { s->failed_pc=0x0c094244u; return 0; }
r[4]=r[15];
goto P_0c094246;
P_0c094246: /* original 7404, guest PC 0x0c094246 */
if(!s->budget--) { s->failed_pc=0x0c094246u; return 0; }
r[4]+=0x00000004u;
goto P_0c094248;
P_0c094248: /* original f049, guest PC 0x0c094248 */
if(!s->budget--) { s->failed_pc=0x0c094248u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09424a;
P_0c09424a: /* original f149, guest PC 0x0c09424a */
if(!s->budget--) { s->failed_pc=0x0c09424au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09424c;
P_0c09424c: /* original f249, guest PC 0x0c09424c */
if(!s->budget--) { s->failed_pc=0x0c09424cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09424e;
P_0c09424e: /* original f38d, guest PC 0x0c09424e */
if(!s->budget--) { s->failed_pc=0x0c09424eu; return 0; }
fr[3]=0;
goto P_0c094250;
P_0c094250: /* original f0ed, guest PC 0x0c094250 */
if(!s->budget--) { s->failed_pc=0x0c094250u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c094252;
P_0c094252: /* original f37d, guest PC 0x0c094252 */
if(!s->budget--) { s->failed_pc=0x0c094252u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c094254;
P_0c094254: /* original f232, guest PC 0x0c094254 */
if(!s->budget--) { s->failed_pc=0x0c094254u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c094256;
P_0c094256: /* original f132, guest PC 0x0c094256 */
if(!s->budget--) { s->failed_pc=0x0c094256u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c094258;
P_0c094258: /* original f032, guest PC 0x0c094258 */
if(!s->budget--) { s->failed_pc=0x0c094258u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c09425a;
P_0c09425a: /* original f42b, guest PC 0x0c09425a */
if(!s->budget--) { s->failed_pc=0x0c09425au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c09425c;
P_0c09425c: /* original f41b, guest PC 0x0c09425c */
if(!s->budget--) { s->failed_pc=0x0c09425cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c09425e;
P_0c09425e: /* original f40b, guest PC 0x0c09425e */
if(!s->budget--) { s->failed_pc=0x0c09425eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c094260;
P_0c094260: /* original d31f, guest PC 0x0c094260 */
if(!s->budget--) { s->failed_pc=0x0c094260u; return 0; }
r[3]=read(ram,0x0c0942e0u,4);
goto P_0c094262;
P_0c094262: /* original 65f3, guest PC 0x0c094262 */
if(!s->budget--) { s->failed_pc=0x0c094262u; return 0; }
r[5]=r[15];
goto P_0c094264;
P_0c094264: /* original d41d, guest PC 0x0c094264 */
if(!s->budget--) { s->failed_pc=0x0c094264u; return 0; }
r[4]=read(ram,0x0c0942dcu,4);
goto P_0c094266;
P_0c094266: /* original 430b, guest PC 0x0c094266 */
if(!s->budget--) { s->failed_pc=0x0c094266u; return 0; }
target=r[3];
r[16]=code_base|0x0c09426au;
r[5]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09426au) { target=s->pc; goto dispatch; }
goto P_0c09426a;
P_0c094268: /* original 7504, guest PC 0x0c094268 */
if(!s->budget--) { s->failed_pc=0x0c094268u; return 0; }
r[5]+=0x00000004u;
goto P_0c09426a;
P_0c09426a: /* original d21e, guest PC 0x0c09426a */
if(!s->budget--) { s->failed_pc=0x0c09426au; return 0; }
r[2]=read(ram,0x0c0942e4u,4);
goto P_0c09426c;
P_0c09426c: /* original 22d8, guest PC 0x0c09426c */
if(!s->budget--) { s->failed_pc=0x0c09426cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c09426e;
P_0c09426e: /* original 8906, guest PC 0x0c09426e */
if(!s->budget--) { s->failed_pc=0x0c09426eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09427e; }
goto P_0c094270;
P_0c094270: /* original d21e, guest PC 0x0c094270 */
if(!s->budget--) { s->failed_pc=0x0c094270u; return 0; }
r[2]=read(ram,0x0c0942ecu,4);
goto P_0c094272;
P_0c094272: /* original d41d, guest PC 0x0c094272 */
if(!s->budget--) { s->failed_pc=0x0c094272u; return 0; }
r[4]=read(ram,0x0c0942e8u,4);
goto P_0c094274;
P_0c094274: /* original 420b, guest PC 0x0c094274 */
if(!s->budget--) { s->failed_pc=0x0c094274u; return 0; }
target=r[2];
r[16]=code_base|0x0c094278u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c094278u) { target=s->pc; goto dispatch; }
goto P_0c094278;
P_0c094276: /* original 0009, guest PC 0x0c094276 */
if(!s->budget--) { s->failed_pc=0x0c094276u; return 0; }
goto P_0c094278;
P_0c094278: /* original d31d, guest PC 0x0c094278 */
if(!s->budget--) { s->failed_pc=0x0c094278u; return 0; }
r[3]=read(ram,0x0c0942f0u,4);
goto P_0c09427a;
P_0c09427a: /* original 432b, guest PC 0x0c09427a */
if(!s->budget--) { s->failed_pc=0x0c09427au; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c094348u: goto P_0c094348;
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
P_0c09427c: /* original 0009, guest PC 0x0c09427c */
if(!s->budget--) { s->failed_pc=0x0c09427cu; return 0; }
goto P_0c09427e;
P_0c09427e: /* original 9328, guest PC 0x0c09427e */
if(!s->budget--) { s->failed_pc=0x0c09427eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0942d2u,2);
goto P_0c094280;
P_0c094280: /* original 2d38, guest PC 0x0c094280 */
if(!s->budget--) { s->failed_pc=0x0c094280u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[3])==0)!=0);
goto P_0c094282;
P_0c094282: /* original 8b02, guest PC 0x0c094282 */
if(!s->budget--) { s->failed_pc=0x0c094282u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09428a; }
goto P_0c094284;
P_0c094284: /* original d21a, guest PC 0x0c094284 */
if(!s->budget--) { s->failed_pc=0x0c094284u; return 0; }
r[2]=read(ram,0x0c0942f0u,4);
goto P_0c094286;
P_0c094286: /* original 422b, guest PC 0x0c094286 */
if(!s->budget--) { s->failed_pc=0x0c094286u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c094348u: goto P_0c094348;
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
P_0c094288: /* original 0009, guest PC 0x0c094288 */
if(!s->budget--) { s->failed_pc=0x0c094288u; return 0; }
goto P_0c09428a;
P_0c09428a: /* original d31a, guest PC 0x0c09428a */
if(!s->budget--) { s->failed_pc=0x0c09428au; return 0; }
r[3]=read(ram,0x0c0942f4u,4);
goto P_0c09428c;
P_0c09428c: /* original 430b, guest PC 0x0c09428c */
if(!s->budget--) { s->failed_pc=0x0c09428cu; return 0; }
target=r[3];
r[16]=code_base|0x0c094290u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c094290u) { target=s->pc; goto dispatch; }
goto P_0c094290;
P_0c09428e: /* original 64a3, guest PC 0x0c09428e */
if(!s->budget--) { s->failed_pc=0x0c09428eu; return 0; }
r[4]=r[10];
goto P_0c094290;
P_0c094290: /* original 7a24, guest PC 0x0c094290 */
if(!s->budget--) { s->failed_pc=0x0c094290u; return 0; }
r[10]+=0x00000024u;
goto P_0c094292;
P_0c094292: /* original 0a83, guest PC 0x0c094292 */
if(!s->budget--) { s->failed_pc=0x0c094292u; return 0; }
if((r[10]&0xFC000000u)==0xE0000000u) pref(ram,r[10]);
goto P_0c094294;
P_0c094294: /* original d216, guest PC 0x0c094294 */
if(!s->budget--) { s->failed_pc=0x0c094294u; return 0; }
r[2]=read(ram,0x0c0942f0u,4);
goto P_0c094296;
P_0c094296: /* original 422b, guest PC 0x0c094296 */
if(!s->budget--) { s->failed_pc=0x0c094296u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c094348u: goto P_0c094348;
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
P_0c094298: /* original 0009, guest PC 0x0c094298 */
if(!s->budget--) { s->failed_pc=0x0c094298u; return 0; }
goto P_0c09429a;
P_0c09429a: /* original 931a, guest PC 0x0c09429a */
if(!s->budget--) { s->failed_pc=0x0c09429au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0942d2u,2);
goto P_0c09429c;
P_0c09429c: /* original 23d8, guest PC 0x0c09429c */
if(!s->budget--) { s->failed_pc=0x0c09429cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09429e;
P_0c09429e: /* original 8906, guest PC 0x0c09429e */
if(!s->budget--) { s->failed_pc=0x0c09429eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0942ae; }
goto P_0c0942a0;
P_0c0942a0: /* original 60f2, guest PC 0x0c0942a0 */
if(!s->budget--) { s->failed_pc=0x0c0942a0u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0942a2;
P_0c0942a2: /* original 6002, guest PC 0x0c0942a2 */
if(!s->budget--) { s->failed_pc=0x0c0942a2u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c0942a4;
P_0c0942a4: /* original c810, guest PC 0x0c0942a4 */
if(!s->budget--) { s->failed_pc=0x0c0942a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0942a6;
P_0c0942a6: /* original 8902, guest PC 0x0c0942a6 */
if(!s->budget--) { s->failed_pc=0x0c0942a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0942ae; }
goto P_0c0942a8;
P_0c0942a8: /* original d313, guest PC 0x0c0942a8 */
if(!s->budget--) { s->failed_pc=0x0c0942a8u; return 0; }
r[3]=read(ram,0x0c0942f8u,4);
goto P_0c0942aa;
P_0c0942aa: /* original 432b, guest PC 0x0c0942aa */
if(!s->budget--) { s->failed_pc=0x0c0942aau; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c094352u: goto P_0c094352;
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
P_0c0942ac: /* original 0009, guest PC 0x0c0942ac */
if(!s->budget--) { s->failed_pc=0x0c0942acu; return 0; }
goto P_0c0942ae;
P_0c0942ae: /* original 9311, guest PC 0x0c0942ae */
if(!s->budget--) { s->failed_pc=0x0c0942aeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0942d4u,2);
goto P_0c0942b0;
P_0c0942b0: /* original e030, guest PC 0x0c0942b0 */
if(!s->budget--) { s->failed_pc=0x0c0942b0u; return 0; }
r[0]=0x00000030u;
goto P_0c0942b2;
P_0c0942b2: /* original 23d8, guest PC 0x0c0942b2 */
if(!s->budget--) { s->failed_pc=0x0c0942b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0942b4;
P_0c0942b4: /* original 8d03, guest PC 0x0c0942b4 */
if(!s->budget--) { s->failed_pc=0x0c0942b4u; return 0; }
cond=r[17]&1u;
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(cond) { goto P_0c0942be; }
goto P_0c0942b8;
P_0c0942b6: /* original 0ced, guest PC 0x0c0942b6 */
if(!s->budget--) { s->failed_pc=0x0c0942b6u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0942b8;
P_0c0942b8: /* original e02e, guest PC 0x0c0942b8 */
if(!s->budget--) { s->failed_pc=0x0c0942b8u; return 0; }
r[0]=0x0000002eu;
goto P_0c0942ba;
P_0c0942ba: /* original 01ed, guest PC 0x0c0942ba */
if(!s->budget--) { s->failed_pc=0x0c0942bau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0942bc;
P_0c0942bc: /* original 3c1c, guest PC 0x0c0942bc */
if(!s->budget--) { s->failed_pc=0x0c0942bcu; return 0; }
r[12]+=r[1];
goto P_0c0942be;
P_0c0942be: /* original 930a, guest PC 0x0c0942be */
if(!s->budget--) { s->failed_pc=0x0c0942beu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0942d6u,2);
goto P_0c0942c0;
P_0c0942c0: /* original 23d8, guest PC 0x0c0942c0 */
if(!s->budget--) { s->failed_pc=0x0c0942c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0942c2;
P_0c0942c2: /* original 8904, guest PC 0x0c0942c2 */
if(!s->budget--) { s->failed_pc=0x0c0942c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0942ce; }
goto P_0c0942c4;
P_0c0942c4: /* original e02e, guest PC 0x0c0942c4 */
if(!s->budget--) { s->failed_pc=0x0c0942c4u; return 0; }
r[0]=0x0000002eu;
goto P_0c0942c6;
P_0c0942c6: /* original 01ed, guest PC 0x0c0942c6 */
if(!s->budget--) { s->failed_pc=0x0c0942c6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0942c8;
P_0c0942c8: /* original 31cc, guest PC 0x0c0942c8 */
if(!s->budget--) { s->failed_pc=0x0c0942c8u; return 0; }
r[1]+=r[12];
goto P_0c0942ca;
P_0c0942ca: /* original 9c05, guest PC 0x0c0942ca */
if(!s->budget--) { s->failed_pc=0x0c0942cau; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0942d8u,2);
goto P_0c0942cc;
P_0c0942cc: /* original 3c1c, guest PC 0x0c0942cc */
if(!s->budget--) { s->failed_pc=0x0c0942ccu; return 0; }
r[12]+=r[1];
goto P_0c0942ce;
P_0c0942ce: /* original a015, guest PC 0x0c0942ce */
if(!s->budget--) { s->failed_pc=0x0c0942ceu; return 0; }
goto P_0c0942fc;
P_0c0942d0: /* original 0009, guest PC 0x0c0942d0 */
if(!s->budget--) { s->failed_pc=0x0c0942d0u; return 0; }
if(!vf3_matrix_family(0x0c0942d2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0942d2u; return 0; } return 1;
P_0c0942fc: /* original fbfd, guest PC 0x0c0942fc */
if(!s->budget--) { s->failed_pc=0x0c0942fcu; return 0; }
vf3_matrix_swap(s);
goto P_0c0942fe;
P_0c0942fe: /* original f09d, guest PC 0x0c0942fe */
if(!s->budget--) { s->failed_pc=0x0c0942feu; return 0; }
fr[0]=0x3f800000u;
goto P_0c094300;
P_0c094300: /* original f18d, guest PC 0x0c094300 */
if(!s->budget--) { s->failed_pc=0x0c094300u; return 0; }
fr[1]=0;
goto P_0c094302;
P_0c094302: /* original f28d, guest PC 0x0c094302 */
if(!s->budget--) { s->failed_pc=0x0c094302u; return 0; }
fr[2]=0;
goto P_0c094304;
P_0c094304: /* original f48d, guest PC 0x0c094304 */
if(!s->budget--) { s->failed_pc=0x0c094304u; return 0; }
fr[4]=0;
goto P_0c094306;
P_0c094306: /* original f59d, guest PC 0x0c094306 */
if(!s->budget--) { s->failed_pc=0x0c094306u; return 0; }
fr[5]=0x3f800000u;
goto P_0c094308;
P_0c094308: /* original f68d, guest PC 0x0c094308 */
if(!s->budget--) { s->failed_pc=0x0c094308u; return 0; }
fr[6]=0;
goto P_0c09430a;
P_0c09430a: /* original f88d, guest PC 0x0c09430a */
if(!s->budget--) { s->failed_pc=0x0c09430au; return 0; }
fr[8]=0;
goto P_0c09430c;
P_0c09430c: /* original f98d, guest PC 0x0c09430c */
if(!s->budget--) { s->failed_pc=0x0c09430cu; return 0; }
fr[9]=0;
goto P_0c09430e;
P_0c09430e: /* original fa9d, guest PC 0x0c09430e */
if(!s->budget--) { s->failed_pc=0x0c09430eu; return 0; }
fr[10]=0x3f800000u;
goto P_0c094310;
P_0c094310: /* original fbfd, guest PC 0x0c094310 */
if(!s->budget--) { s->failed_pc=0x0c094310u; return 0; }
vf3_matrix_swap(s);
goto P_0c094312;
P_0c094312: /* original 0009, guest PC 0x0c094312 */
if(!s->budget--) { s->failed_pc=0x0c094312u; return 0; }
goto P_0c094314;
P_0c094314: /* original 64e3, guest PC 0x0c094314 */
if(!s->budget--) { s->failed_pc=0x0c094314u; return 0; }
r[4]=r[14];
goto P_0c094316;
P_0c094316: /* original 740c, guest PC 0x0c094316 */
if(!s->budget--) { s->failed_pc=0x0c094316u; return 0; }
r[4]+=0x0000000cu;
goto P_0c094318;
P_0c094318: /* original fbfd, guest PC 0x0c094318 */
if(!s->budget--) { s->failed_pc=0x0c094318u; return 0; }
vf3_matrix_swap(s);
goto P_0c09431a;
P_0c09431a: /* original fc49, guest PC 0x0c09431a */
if(!s->budget--) { s->failed_pc=0x0c09431au; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09431c;
P_0c09431c: /* original fd49, guest PC 0x0c09431c */
if(!s->budget--) { s->failed_pc=0x0c09431cu; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09431e;
P_0c09431e: /* original fe49, guest PC 0x0c09431e */
if(!s->budget--) { s->failed_pc=0x0c09431eu; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c094320;
P_0c094320: /* original fbfd, guest PC 0x0c094320 */
if(!s->budget--) { s->failed_pc=0x0c094320u; return 0; }
vf3_matrix_swap(s);
goto P_0c094322;
P_0c094322: /* original 0009, guest PC 0x0c094322 */
if(!s->budget--) { s->failed_pc=0x0c094322u; return 0; }
goto P_0c094324;
P_0c094324: /* original d326, guest PC 0x0c094324 */
if(!s->budget--) { s->failed_pc=0x0c094324u; return 0; }
r[3]=read(ram,0x0c0943c0u,4);
goto P_0c094326;
P_0c094326: /* original e030, guest PC 0x0c094326 */
if(!s->budget--) { s->failed_pc=0x0c094326u; return 0; }
r[0]=0x00000030u;
goto P_0c094328;
P_0c094328: /* original 430b, guest PC 0x0c094328 */
if(!s->budget--) { s->failed_pc=0x0c094328u; return 0; }
target=r[3];
r[16]=code_base|0x0c09432cu;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09432cu) { target=s->pc; goto dispatch; }
goto P_0c09432c;
P_0c09432a: /* original 04ed, guest PC 0x0c09432a */
if(!s->budget--) { s->failed_pc=0x0c09432au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09432c;
P_0c09432c: /* original d325, guest PC 0x0c09432c */
if(!s->budget--) { s->failed_pc=0x0c09432cu; return 0; }
r[3]=read(ram,0x0c0943c4u,4);
goto P_0c09432e;
P_0c09432e: /* original e032, guest PC 0x0c09432e */
if(!s->budget--) { s->failed_pc=0x0c09432eu; return 0; }
r[0]=0x00000032u;
goto P_0c094330;
P_0c094330: /* original 430b, guest PC 0x0c094330 */
if(!s->budget--) { s->failed_pc=0x0c094330u; return 0; }
target=r[3];
r[16]=code_base|0x0c094334u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c094334u) { target=s->pc; goto dispatch; }
goto P_0c094334;
P_0c094332: /* original 04ed, guest PC 0x0c094332 */
if(!s->budget--) { s->failed_pc=0x0c094332u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c094334;
P_0c094334: /* original d224, guest PC 0x0c094334 */
if(!s->budget--) { s->failed_pc=0x0c094334u; return 0; }
r[2]=read(ram,0x0c0943c8u,4);
goto P_0c094336;
P_0c094336: /* original 2d28, guest PC 0x0c094336 */
if(!s->budget--) { s->failed_pc=0x0c094336u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[2])==0)!=0);
goto P_0c094338;
P_0c094338: /* original 8903, guest PC 0x0c094338 */
if(!s->budget--) { s->failed_pc=0x0c094338u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094342; }
goto P_0c09433a;
P_0c09433a: /* original d125, guest PC 0x0c09433a */
if(!s->budget--) { s->failed_pc=0x0c09433au; return 0; }
r[1]=read(ram,0x0c0943d0u,4);
goto P_0c09433c;
P_0c09433c: /* original d423, guest PC 0x0c09433c */
if(!s->budget--) { s->failed_pc=0x0c09433cu; return 0; }
r[4]=read(ram,0x0c0943ccu,4);
goto P_0c09433e;
P_0c09433e: /* original 410b, guest PC 0x0c09433e */
if(!s->budget--) { s->failed_pc=0x0c09433eu; return 0; }
target=r[1];
r[16]=code_base|0x0c094342u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c094342u) { target=s->pc; goto dispatch; }
goto P_0c094342;
P_0c094340: /* original 0009, guest PC 0x0c094340 */
if(!s->budget--) { s->failed_pc=0x0c094340u; return 0; }
goto P_0c094342;
P_0c094342: /* original d324, guest PC 0x0c094342 */
if(!s->budget--) { s->failed_pc=0x0c094342u; return 0; }
r[3]=read(ram,0x0c0943d4u,4);
goto P_0c094344;
P_0c094344: /* original 430b, guest PC 0x0c094344 */
if(!s->budget--) { s->failed_pc=0x0c094344u; return 0; }
target=r[3];
r[16]=code_base|0x0c094348u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c094348u) { target=s->pc; goto dispatch; }
goto P_0c094348;
P_0c094346: /* original 64c3, guest PC 0x0c094346 */
if(!s->budget--) { s->failed_pc=0x0c094346u; return 0; }
r[4]=r[12];
goto P_0c094348;
P_0c094348: /* original e02c, guest PC 0x0c094348 */
if(!s->budget--) { s->failed_pc=0x0c094348u; return 0; }
r[0]=0x0000002cu;
goto P_0c09434a;
P_0c09434a: /* original d323, guest PC 0x0c09434a */
if(!s->budget--) { s->failed_pc=0x0c09434au; return 0; }
r[3]=read(ram,0x0c0943d8u,4);
goto P_0c09434c;
P_0c09434c: /* original 04ed, guest PC 0x0c09434c */
if(!s->budget--) { s->failed_pc=0x0c09434cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09434e;
P_0c09434e: /* original 430b, guest PC 0x0c09434e */
if(!s->budget--) { s->failed_pc=0x0c09434eu; return 0; }
target=r[3];
r[16]=code_base|0x0c094352u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c094352u) { target=s->pc; goto dispatch; }
goto P_0c094352;
P_0c094350: /* original 644d, guest PC 0x0c094350 */
if(!s->budget--) { s->failed_pc=0x0c094350u; return 0; }
r[4]=r[4]&65535u;
goto P_0c094352;
P_0c094352: /* original d222, guest PC 0x0c094352 */
if(!s->budget--) { s->failed_pc=0x0c094352u; return 0; }
r[2]=read(ram,0x0c0943dcu,4);
goto P_0c094354;
P_0c094354: /* original 422b, guest PC 0x0c094354 */
if(!s->budget--) { s->failed_pc=0x0c094354u; return 0; }
target=r[2];
r[14]=r[11];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c094168u: goto P_0c094168;
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
P_0c094356: /* original 6eb3, guest PC 0x0c094356 */
if(!s->budget--) { s->failed_pc=0x0c094356u; return 0; }
r[14]=r[11];
goto P_0c094358;
P_0c094358: /* original 7f10, guest PC 0x0c094358 */
if(!s->budget--) { s->failed_pc=0x0c094358u; return 0; }
r[15]+=0x00000010u;
goto P_0c09435a;
P_0c09435a: /* original 4f26, guest PC 0x0c09435a */
if(!s->budget--) { s->failed_pc=0x0c09435au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09435c;
P_0c09435c: /* original 6af6, guest PC 0x0c09435c */
if(!s->budget--) { s->failed_pc=0x0c09435cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09435e;
P_0c09435e: /* original 6bf6, guest PC 0x0c09435e */
if(!s->budget--) { s->failed_pc=0x0c09435eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c094360;
P_0c094360: /* original 6cf6, guest PC 0x0c094360 */
if(!s->budget--) { s->failed_pc=0x0c094360u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c094362;
P_0c094362: /* original 6df6, guest PC 0x0c094362 */
if(!s->budget--) { s->failed_pc=0x0c094362u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c094364;
P_0c094364: /* original 000b, guest PC 0x0c094364 */
if(!s->budget--) { s->failed_pc=0x0c094364u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c094366: /* original 6ef6, guest PC 0x0c094366 */
if(!s->budget--) { s->failed_pc=0x0c094366u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c094368u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
