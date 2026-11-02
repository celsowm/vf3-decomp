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
int vf3_away_batch31_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0641c0u: goto P_0c0641c0;
case 0x0c0641c2u: goto P_0c0641c2;
case 0x0c0641c4u: goto P_0c0641c4;
case 0x0c0641c6u: goto P_0c0641c6;
case 0x0c0641c8u: goto P_0c0641c8;
case 0x0c0641cau: goto P_0c0641ca;
case 0x0c0641ccu: goto P_0c0641cc;
case 0x0c0641ceu: goto P_0c0641ce;
case 0x0c0641d0u: goto P_0c0641d0;
case 0x0c0641d2u: goto P_0c0641d2;
case 0x0c0641d4u: goto P_0c0641d4;
case 0x0c0641d6u: goto P_0c0641d6;
case 0x0c0641d8u: goto P_0c0641d8;
case 0x0c0641dau: goto P_0c0641da;
case 0x0c0641dcu: goto P_0c0641dc;
case 0x0c0641deu: goto P_0c0641de;
case 0x0c0641e0u: goto P_0c0641e0;
case 0x0c0641e2u: goto P_0c0641e2;
case 0x0c0641e4u: goto P_0c0641e4;
case 0x0c0641e6u: goto P_0c0641e6;
case 0x0c0641e8u: goto P_0c0641e8;
case 0x0c0641eau: goto P_0c0641ea;
case 0x0c0641ecu: goto P_0c0641ec;
case 0x0c0641eeu: goto P_0c0641ee;
case 0x0c0641f0u: goto P_0c0641f0;
case 0x0c0641f2u: goto P_0c0641f2;
case 0x0c0641f4u: goto P_0c0641f4;
case 0x0c0641f6u: goto P_0c0641f6;
case 0x0c0641f8u: goto P_0c0641f8;
case 0x0c0641fau: goto P_0c0641fa;
case 0x0c0641fcu: goto P_0c0641fc;
case 0x0c0641feu: goto P_0c0641fe;
case 0x0c064200u: goto P_0c064200;
case 0x0c064202u: goto P_0c064202;
case 0x0c064204u: goto P_0c064204;
case 0x0c064206u: goto P_0c064206;
case 0x0c064208u: goto P_0c064208;
case 0x0c06420au: goto P_0c06420a;
case 0x0c06420cu: goto P_0c06420c;
case 0x0c06420eu: goto P_0c06420e;
case 0x0c064210u: goto P_0c064210;
case 0x0c064212u: goto P_0c064212;
case 0x0c064214u: goto P_0c064214;
case 0x0c064216u: goto P_0c064216;
case 0x0c064218u: goto P_0c064218;
case 0x0c06421au: goto P_0c06421a;
case 0x0c06421cu: goto P_0c06421c;
case 0x0c06421eu: goto P_0c06421e;
case 0x0c064220u: goto P_0c064220;
case 0x0c064222u: goto P_0c064222;
case 0x0c064224u: goto P_0c064224;
case 0x0c064226u: goto P_0c064226;
case 0x0c064228u: goto P_0c064228;
case 0x0c06422au: goto P_0c06422a;
case 0x0c06422cu: goto P_0c06422c;
case 0x0c06422eu: goto P_0c06422e;
case 0x0c064230u: goto P_0c064230;
case 0x0c064232u: goto P_0c064232;
case 0x0c064234u: goto P_0c064234;
case 0x0c064236u: goto P_0c064236;
case 0x0c064238u: goto P_0c064238;
case 0x0c06423au: goto P_0c06423a;
case 0x0c06423cu: goto P_0c06423c;
case 0x0c06423eu: goto P_0c06423e;
case 0x0c064240u: goto P_0c064240;
case 0x0c064242u: goto P_0c064242;
case 0x0c064244u: goto P_0c064244;
case 0x0c064246u: goto P_0c064246;
case 0x0c064248u: goto P_0c064248;
case 0x0c06424au: goto P_0c06424a;
case 0x0c06424cu: goto P_0c06424c;
case 0x0c06424eu: goto P_0c06424e;
case 0x0c064250u: goto P_0c064250;
case 0x0c064252u: goto P_0c064252;
case 0x0c064254u: goto P_0c064254;
case 0x0c064256u: goto P_0c064256;
case 0x0c064258u: goto P_0c064258;
case 0x0c06425au: goto P_0c06425a;
case 0x0c06425cu: goto P_0c06425c;
case 0x0c06425eu: goto P_0c06425e;
case 0x0c064260u: goto P_0c064260;
case 0x0c064262u: goto P_0c064262;
case 0x0c064264u: goto P_0c064264;
case 0x0c064266u: goto P_0c064266;
case 0x0c064268u: goto P_0c064268;
case 0x0c06426au: goto P_0c06426a;
case 0x0c06426cu: goto P_0c06426c;
case 0x0c06426eu: goto P_0c06426e;
case 0x0c064270u: goto P_0c064270;
case 0x0c064272u: goto P_0c064272;
case 0x0c064274u: goto P_0c064274;
case 0x0c064276u: goto P_0c064276;
case 0x0c064278u: goto P_0c064278;
case 0x0c06427au: goto P_0c06427a;
case 0x0c06427cu: goto P_0c06427c;
case 0x0c06427eu: goto P_0c06427e;
case 0x0c064280u: goto P_0c064280;
case 0x0c064282u: goto P_0c064282;
case 0x0c064284u: goto P_0c064284;
case 0x0c064286u: goto P_0c064286;
case 0x0c064288u: goto P_0c064288;
case 0x0c06428au: goto P_0c06428a;
case 0x0c06428cu: goto P_0c06428c;
case 0x0c06428eu: goto P_0c06428e;
case 0x0c064290u: goto P_0c064290;
case 0x0c064292u: goto P_0c064292;
case 0x0c064294u: goto P_0c064294;
case 0x0c064296u: goto P_0c064296;
case 0x0c064298u: goto P_0c064298;
case 0x0c06429au: goto P_0c06429a;
case 0x0c06429cu: goto P_0c06429c;
case 0x0c06429eu: goto P_0c06429e;
case 0x0c0642a0u: goto P_0c0642a0;
case 0x0c0642a2u: goto P_0c0642a2;
case 0x0c0642a4u: goto P_0c0642a4;
case 0x0c0642a6u: goto P_0c0642a6;
case 0x0c0642a8u: goto P_0c0642a8;
case 0x0c0642aau: goto P_0c0642aa;
case 0x0c0642acu: goto P_0c0642ac;
case 0x0c0642aeu: goto P_0c0642ae;
case 0x0c0642b0u: goto P_0c0642b0;
case 0x0c0642b2u: goto P_0c0642b2;
case 0x0c0642b4u: goto P_0c0642b4;
case 0x0c0642b6u: goto P_0c0642b6;
case 0x0c0642b8u: goto P_0c0642b8;
case 0x0c0642bau: goto P_0c0642ba;
case 0x0c0642bcu: goto P_0c0642bc;
case 0x0c0642beu: goto P_0c0642be;
case 0x0c0642c0u: goto P_0c0642c0;
case 0x0c0642c2u: goto P_0c0642c2;
case 0x0c0642c4u: goto P_0c0642c4;
case 0x0c0642c6u: goto P_0c0642c6;
case 0x0c0642c8u: goto P_0c0642c8;
case 0x0c0642cau: goto P_0c0642ca;
case 0x0c064314u: goto P_0c064314;
case 0x0c064316u: goto P_0c064316;
case 0x0c064318u: goto P_0c064318;
case 0x0c06431au: goto P_0c06431a;
case 0x0c06431cu: goto P_0c06431c;
case 0x0c06431eu: goto P_0c06431e;
case 0x0c064320u: goto P_0c064320;
case 0x0c064322u: goto P_0c064322;
case 0x0c064324u: goto P_0c064324;
case 0x0c064326u: goto P_0c064326;
case 0x0c064328u: goto P_0c064328;
case 0x0c06432au: goto P_0c06432a;
case 0x0c06432cu: goto P_0c06432c;
case 0x0c06432eu: goto P_0c06432e;
case 0x0c064330u: goto P_0c064330;
case 0x0c064332u: goto P_0c064332;
case 0x0c064334u: goto P_0c064334;
case 0x0c064336u: goto P_0c064336;
case 0x0c064338u: goto P_0c064338;
case 0x0c06433au: goto P_0c06433a;
case 0x0c06433cu: goto P_0c06433c;
case 0x0c06433eu: goto P_0c06433e;
case 0x0c064340u: goto P_0c064340;
case 0x0c064342u: goto P_0c064342;
case 0x0c064344u: goto P_0c064344;
case 0x0c064346u: goto P_0c064346;
case 0x0c064348u: goto P_0c064348;
case 0x0c06434au: goto P_0c06434a;
case 0x0c06434cu: goto P_0c06434c;
case 0x0c06434eu: goto P_0c06434e;
case 0x0c064350u: goto P_0c064350;
case 0x0c064352u: goto P_0c064352;
case 0x0c064354u: goto P_0c064354;
case 0x0c064356u: goto P_0c064356;
case 0x0c064358u: goto P_0c064358;
case 0x0c06435au: goto P_0c06435a;
case 0x0c06435cu: goto P_0c06435c;
case 0x0c06435eu: goto P_0c06435e;
case 0x0c064360u: goto P_0c064360;
case 0x0c064362u: goto P_0c064362;
case 0x0c064364u: goto P_0c064364;
case 0x0c064366u: goto P_0c064366;
case 0x0c064368u: goto P_0c064368;
case 0x0c06436au: goto P_0c06436a;
case 0x0c06436cu: goto P_0c06436c;
case 0x0c06436eu: goto P_0c06436e;
case 0x0c064370u: goto P_0c064370;
case 0x0c064372u: goto P_0c064372;
case 0x0c064374u: goto P_0c064374;
case 0x0c064376u: goto P_0c064376;
case 0x0c064378u: goto P_0c064378;
case 0x0c06437au: goto P_0c06437a;
case 0x0c06437cu: goto P_0c06437c;
case 0x0c06437eu: goto P_0c06437e;
case 0x0c064380u: goto P_0c064380;
case 0x0c064382u: goto P_0c064382;
case 0x0c064384u: goto P_0c064384;
case 0x0c064386u: goto P_0c064386;
case 0x0c064388u: goto P_0c064388;
case 0x0c06438au: goto P_0c06438a;
case 0x0c06438cu: goto P_0c06438c;
case 0x0c06438eu: goto P_0c06438e;
case 0x0c064390u: goto P_0c064390;
case 0x0c064392u: goto P_0c064392;
case 0x0c064394u: goto P_0c064394;
case 0x0c064396u: goto P_0c064396;
case 0x0c064398u: goto P_0c064398;
case 0x0c06439au: goto P_0c06439a;
case 0x0c06439cu: goto P_0c06439c;
case 0x0c06439eu: goto P_0c06439e;
case 0x0c0643a0u: goto P_0c0643a0;
case 0x0c0643a2u: goto P_0c0643a2;
case 0x0c0643a4u: goto P_0c0643a4;
case 0x0c0643a6u: goto P_0c0643a6;
case 0x0c0643a8u: goto P_0c0643a8;
case 0x0c0643aau: goto P_0c0643aa;
case 0x0c0643acu: goto P_0c0643ac;
case 0x0c0643aeu: goto P_0c0643ae;
case 0x0c0643b0u: goto P_0c0643b0;
case 0x0c0643b2u: goto P_0c0643b2;
case 0x0c0643b4u: goto P_0c0643b4;
case 0x0c0643b6u: goto P_0c0643b6;
case 0x0c0643b8u: goto P_0c0643b8;
case 0x0c0643bau: goto P_0c0643ba;
case 0x0c0643bcu: goto P_0c0643bc;
case 0x0c0643beu: goto P_0c0643be;
case 0x0c0643c0u: goto P_0c0643c0;
case 0x0c0643c2u: goto P_0c0643c2;
case 0x0c0643c4u: goto P_0c0643c4;
case 0x0c0643c6u: goto P_0c0643c6;
case 0x0c0643c8u: goto P_0c0643c8;
case 0x0c0643cau: goto P_0c0643ca;
case 0x0c0643ccu: goto P_0c0643cc;
case 0x0c0643ceu: goto P_0c0643ce;
case 0x0c0643d0u: goto P_0c0643d0;
case 0x0c0643d2u: goto P_0c0643d2;
case 0x0c0643d4u: goto P_0c0643d4;
case 0x0c0643d6u: goto P_0c0643d6;
case 0x0c0643d8u: goto P_0c0643d8;
case 0x0c0643dau: goto P_0c0643da;
case 0x0c0643dcu: goto P_0c0643dc;
case 0x0c0643deu: goto P_0c0643de;
case 0x0c0643e0u: goto P_0c0643e0;
case 0x0c0643e2u: goto P_0c0643e2;
case 0x0c0643e4u: goto P_0c0643e4;
case 0x0c0643e6u: goto P_0c0643e6;
case 0x0c0643e8u: goto P_0c0643e8;
case 0x0c0643eau: goto P_0c0643ea;
case 0x0c0643ecu: goto P_0c0643ec;
case 0x0c0643eeu: goto P_0c0643ee;
case 0x0c0643f0u: goto P_0c0643f0;
case 0x0c0643f2u: goto P_0c0643f2;
case 0x0c0643f4u: goto P_0c0643f4;
case 0x0c0643f6u: goto P_0c0643f6;
case 0x0c0643f8u: goto P_0c0643f8;
case 0x0c0643fau: goto P_0c0643fa;
case 0x0c0643fcu: goto P_0c0643fc;
case 0x0c0643feu: goto P_0c0643fe;
case 0x0c064400u: goto P_0c064400;
case 0x0c064402u: goto P_0c064402;
case 0x0c064404u: goto P_0c064404;
case 0x0c064406u: goto P_0c064406;
case 0x0c064408u: goto P_0c064408;
case 0x0c06440au: goto P_0c06440a;
case 0x0c06440cu: goto P_0c06440c;
case 0x0c06440eu: goto P_0c06440e;
case 0x0c064410u: goto P_0c064410;
case 0x0c064412u: goto P_0c064412;
case 0x0c064414u: goto P_0c064414;
case 0x0c064416u: goto P_0c064416;
case 0x0c064418u: goto P_0c064418;
case 0x0c06444cu: goto P_0c06444c;
case 0x0c06444eu: goto P_0c06444e;
case 0x0c064450u: goto P_0c064450;
case 0x0c064452u: goto P_0c064452;
case 0x0c064454u: goto P_0c064454;
case 0x0c064456u: goto P_0c064456;
case 0x0c064458u: goto P_0c064458;
case 0x0c06445au: goto P_0c06445a;
case 0x0c06445cu: goto P_0c06445c;
case 0x0c06445eu: goto P_0c06445e;
case 0x0c064460u: goto P_0c064460;
case 0x0c064462u: goto P_0c064462;
case 0x0c064464u: goto P_0c064464;
case 0x0c064466u: goto P_0c064466;
case 0x0c064468u: goto P_0c064468;
case 0x0c06446au: goto P_0c06446a;
case 0x0c06446cu: goto P_0c06446c;
case 0x0c06446eu: goto P_0c06446e;
case 0x0c064470u: goto P_0c064470;
case 0x0c064472u: goto P_0c064472;
case 0x0c064474u: goto P_0c064474;
case 0x0c064476u: goto P_0c064476;
case 0x0c064478u: goto P_0c064478;
case 0x0c06447au: goto P_0c06447a;
case 0x0c06447cu: goto P_0c06447c;
case 0x0c06447eu: goto P_0c06447e;
case 0x0c064480u: goto P_0c064480;
case 0x0c064482u: goto P_0c064482;
case 0x0c064484u: goto P_0c064484;
case 0x0c064486u: goto P_0c064486;
case 0x0c064488u: goto P_0c064488;
case 0x0c06448au: goto P_0c06448a;
case 0x0c06448cu: goto P_0c06448c;
case 0x0c06448eu: goto P_0c06448e;
case 0x0c064490u: goto P_0c064490;
case 0x0c064492u: goto P_0c064492;
case 0x0c064494u: goto P_0c064494;
case 0x0c064496u: goto P_0c064496;
case 0x0c064498u: goto P_0c064498;
case 0x0c06449au: goto P_0c06449a;
case 0x0c06449cu: goto P_0c06449c;
case 0x0c06449eu: goto P_0c06449e;
case 0x0c0644a0u: goto P_0c0644a0;
case 0x0c0644a2u: goto P_0c0644a2;
case 0x0c0644a4u: goto P_0c0644a4;
case 0x0c0644a6u: goto P_0c0644a6;
case 0x0c0644a8u: goto P_0c0644a8;
case 0x0c0644aau: goto P_0c0644aa;
case 0x0c0644acu: goto P_0c0644ac;
case 0x0c0644aeu: goto P_0c0644ae;
case 0x0c0644b0u: goto P_0c0644b0;
case 0x0c0644b2u: goto P_0c0644b2;
case 0x0c0644b4u: goto P_0c0644b4;
case 0x0c0644b6u: goto P_0c0644b6;
case 0x0c0644b8u: goto P_0c0644b8;
case 0x0c0644bau: goto P_0c0644ba;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0641c0: /* original 4f22, guest PC 0x0c0641c0 */
if(!s->budget--) { s->failed_pc=0x0c0641c0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0641c2;
P_0c0641c2: /* original e304, guest PC 0x0c0641c2 */
if(!s->budget--) { s->failed_pc=0x0c0641c2u; return 0; }
r[3]=0x00000004u;
goto P_0c0641c4;
P_0c0641c4: /* original d241, guest PC 0x0c0641c4 */
if(!s->budget--) { s->failed_pc=0x0c0641c4u; return 0; }
r[2]=read(ram,0x0c0642ccu,4);
goto P_0c0641c6;
P_0c0641c6: /* original 2232, guest PC 0x0c0641c6 */
if(!s->budget--) { s->failed_pc=0x0c0641c6u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0641c8;
P_0c0641c8: /* original d441, guest PC 0x0c0641c8 */
if(!s->budget--) { s->failed_pc=0x0c0641c8u; return 0; }
r[4]=read(ram,0x0c0642d0u,4);
goto P_0c0641ca;
P_0c0641ca: /* original 5348, guest PC 0x0c0641ca */
if(!s->budget--) { s->failed_pc=0x0c0641cau; return 0; }
r[3]=read(ram,r[4]+32,4);
goto P_0c0641cc;
P_0c0641cc: /* original d041, guest PC 0x0c0641cc */
if(!s->budget--) { s->failed_pc=0x0c0641ccu; return 0; }
r[0]=read(ram,0x0c0642d4u,4);
goto P_0c0641ce;
P_0c0641ce: /* original 7301, guest PC 0x0c0641ce */
if(!s->budget--) { s->failed_pc=0x0c0641ceu; return 0; }
r[3]+=0x00000001u;
goto P_0c0641d0;
P_0c0641d0: /* original 1438, guest PC 0x0c0641d0 */
if(!s->budget--) { s->failed_pc=0x0c0641d0u; return 0; }
write(ram,r[4]+32,r[3],4);
goto P_0c0641d2;
P_0c0641d2: /* original e3fd, guest PC 0x0c0641d2 */
if(!s->budget--) { s->failed_pc=0x0c0641d2u; return 0; }
r[3]=0xfffffffdu;
goto P_0c0641d4;
P_0c0641d4: /* original 6102, guest PC 0x0c0641d4 */
if(!s->budget--) { s->failed_pc=0x0c0641d4u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c0641d6;
P_0c0641d6: /* original 70e8, guest PC 0x0c0641d6 */
if(!s->budget--) { s->failed_pc=0x0c0641d6u; return 0; }
r[0]+=0xffffffe8u;
goto P_0c0641d8;
P_0c0641d8: /* original 4108, guest PC 0x0c0641d8 */
if(!s->budget--) { s->failed_pc=0x0c0641d8u; return 0; }
r[1]<<=2;
goto P_0c0641da;
P_0c0641da: /* original 0136, guest PC 0x0c0641da */
if(!s->budget--) { s->failed_pc=0x0c0641dau; return 0; }
write(ram,r[1]+r[0],r[3],4);
goto P_0c0641dc;
P_0c0641dc: /* original d13e, guest PC 0x0c0641dc */
if(!s->budget--) { s->failed_pc=0x0c0641dcu; return 0; }
r[1]=read(ram,0x0c0642d8u,4);
goto P_0c0641de;
P_0c0641de: /* original 6012, guest PC 0x0c0641de */
if(!s->budget--) { s->failed_pc=0x0c0641deu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c0641e0;
P_0c0641e0: /* original 8801, guest PC 0x0c0641e0 */
if(!s->budget--) { s->failed_pc=0x0c0641e0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0641e2;
P_0c0641e2: /* original 8b04, guest PC 0x0c0641e2 */
if(!s->budget--) { s->failed_pc=0x0c0641e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0641ee; }
goto P_0c0641e4;
P_0c0641e4: /* original 5045, guest PC 0x0c0641e4 */
if(!s->budget--) { s->failed_pc=0x0c0641e4u; return 0; }
r[0]=read(ram,r[4]+20,4);
goto P_0c0641e6;
P_0c0641e6: /* original 7001, guest PC 0x0c0641e6 */
if(!s->budget--) { s->failed_pc=0x0c0641e6u; return 0; }
r[0]+=0x00000001u;
goto P_0c0641e8;
P_0c0641e8: /* original 1405, guest PC 0x0c0641e8 */
if(!s->budget--) { s->failed_pc=0x0c0641e8u; return 0; }
write(ram,r[4]+20,r[0],4);
goto P_0c0641ea;
P_0c0641ea: /* original bf55, guest PC 0x0c0641ea */
if(!s->budget--) { s->failed_pc=0x0c0641eau; return 0; }
target=code_base|0x0c064098u; r[16]=code_base|0x0c0641eeu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0641eeu) { target=s->pc; goto dispatch; }
goto P_0c0641ee;
P_0c0641ec: /* original e400, guest PC 0x0c0641ec */
if(!s->budget--) { s->failed_pc=0x0c0641ecu; return 0; }
r[4]=0x00000000u;
goto P_0c0641ee;
P_0c0641ee: /* original 4f26, guest PC 0x0c0641ee */
if(!s->budget--) { s->failed_pc=0x0c0641eeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0641f0;
P_0c0641f0: /* original 000b, guest PC 0x0c0641f0 */
if(!s->budget--) { s->failed_pc=0x0c0641f0u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c0641f2: /* original e000, guest PC 0x0c0641f2 */
if(!s->budget--) { s->failed_pc=0x0c0641f2u; return 0; }
r[0]=0x00000000u;
goto P_0c0641f4;
P_0c0641f4: /* original 4f22, guest PC 0x0c0641f4 */
if(!s->budget--) { s->failed_pc=0x0c0641f4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0641f6;
P_0c0641f6: /* original e308, guest PC 0x0c0641f6 */
if(!s->budget--) { s->failed_pc=0x0c0641f6u; return 0; }
r[3]=0x00000008u;
goto P_0c0641f8;
P_0c0641f8: /* original d234, guest PC 0x0c0641f8 */
if(!s->budget--) { s->failed_pc=0x0c0641f8u; return 0; }
r[2]=read(ram,0x0c0642ccu,4);
goto P_0c0641fa;
P_0c0641fa: /* original 2232, guest PC 0x0c0641fa */
if(!s->budget--) { s->failed_pc=0x0c0641fau; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0641fc;
P_0c0641fc: /* original d434, guest PC 0x0c0641fc */
if(!s->budget--) { s->failed_pc=0x0c0641fcu; return 0; }
r[4]=read(ram,0x0c0642d0u,4);
goto P_0c0641fe;
P_0c0641fe: /* original 5347, guest PC 0x0c0641fe */
if(!s->budget--) { s->failed_pc=0x0c0641feu; return 0; }
r[3]=read(ram,r[4]+28,4);
goto P_0c064200;
P_0c064200: /* original d135, guest PC 0x0c064200 */
if(!s->budget--) { s->failed_pc=0x0c064200u; return 0; }
r[1]=read(ram,0x0c0642d8u,4);
goto P_0c064202;
P_0c064202: /* original 7301, guest PC 0x0c064202 */
if(!s->budget--) { s->failed_pc=0x0c064202u; return 0; }
r[3]+=0x00000001u;
goto P_0c064204;
P_0c064204: /* original 1437, guest PC 0x0c064204 */
if(!s->budget--) { s->failed_pc=0x0c064204u; return 0; }
write(ram,r[4]+28,r[3],4);
goto P_0c064206;
P_0c064206: /* original 6012, guest PC 0x0c064206 */
if(!s->budget--) { s->failed_pc=0x0c064206u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c064208;
P_0c064208: /* original 8801, guest PC 0x0c064208 */
if(!s->budget--) { s->failed_pc=0x0c064208u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06420a;
P_0c06420a: /* original 8b04, guest PC 0x0c06420a */
if(!s->budget--) { s->failed_pc=0x0c06420au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c064216; }
goto P_0c06420c;
P_0c06420c: /* original 5044, guest PC 0x0c06420c */
if(!s->budget--) { s->failed_pc=0x0c06420cu; return 0; }
r[0]=read(ram,r[4]+16,4);
goto P_0c06420e;
P_0c06420e: /* original 7001, guest PC 0x0c06420e */
if(!s->budget--) { s->failed_pc=0x0c06420eu; return 0; }
r[0]+=0x00000001u;
goto P_0c064210;
P_0c064210: /* original 1404, guest PC 0x0c064210 */
if(!s->budget--) { s->failed_pc=0x0c064210u; return 0; }
write(ram,r[4]+16,r[0],4);
goto P_0c064212;
P_0c064212: /* original bf41, guest PC 0x0c064212 */
if(!s->budget--) { s->failed_pc=0x0c064212u; return 0; }
target=code_base|0x0c064098u; r[16]=code_base|0x0c064216u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064216u) { target=s->pc; goto dispatch; }
goto P_0c064216;
P_0c064214: /* original e401, guest PC 0x0c064214 */
if(!s->budget--) { s->failed_pc=0x0c064214u; return 0; }
r[4]=0x00000001u;
goto P_0c064216;
P_0c064216: /* original 4f26, guest PC 0x0c064216 */
if(!s->budget--) { s->failed_pc=0x0c064216u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c064218;
P_0c064218: /* original 000b, guest PC 0x0c064218 */
if(!s->budget--) { s->failed_pc=0x0c064218u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c06421a: /* original e000, guest PC 0x0c06421a */
if(!s->budget--) { s->failed_pc=0x0c06421au; return 0; }
r[0]=0x00000000u;
goto P_0c06421c;
P_0c06421c: /* original d22b, guest PC 0x0c06421c */
if(!s->budget--) { s->failed_pc=0x0c06421cu; return 0; }
r[2]=read(ram,0x0c0642ccu,4);
goto P_0c06421e;
P_0c06421e: /* original e302, guest PC 0x0c06421e */
if(!s->budget--) { s->failed_pc=0x0c06421eu; return 0; }
r[3]=0x00000002u;
goto P_0c064220;
P_0c064220: /* original 2232, guest PC 0x0c064220 */
if(!s->budget--) { s->failed_pc=0x0c064220u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c064222;
P_0c064222: /* original d52e, guest PC 0x0c064222 */
if(!s->budget--) { s->failed_pc=0x0c064222u; return 0; }
r[5]=read(ram,0x0c0642dcu,4);
goto P_0c064224;
P_0c064224: /* original 6352, guest PC 0x0c064224 */
if(!s->budget--) { s->failed_pc=0x0c064224u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c064226;
P_0c064226: /* original 2338, guest PC 0x0c064226 */
if(!s->budget--) { s->failed_pc=0x0c064226u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c064228;
P_0c064228: /* original 8f04, guest PC 0x0c064228 */
if(!s->budget--) { s->failed_pc=0x0c064228u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(!cond) { goto P_0c064234; }
goto P_0c06422c;
P_0c06422a: /* original e400, guest PC 0x0c06422a */
if(!s->budget--) { s->failed_pc=0x0c06422au; return 0; }
r[4]=0x00000000u;
goto P_0c06422c;
P_0c06422c: /* original d32c, guest PC 0x0c06422c */
if(!s->budget--) { s->failed_pc=0x0c06422cu; return 0; }
r[3]=read(ram,0x0c0642e0u,4);
goto P_0c06422e;
P_0c06422e: /* original 6032, guest PC 0x0c06422e */
if(!s->budget--) { s->failed_pc=0x0c06422eu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c064230;
P_0c064230: /* original cb10, guest PC 0x0c064230 */
if(!s->budget--) { s->failed_pc=0x0c064230u; return 0; }
r[0]|=16u;
goto P_0c064232;
P_0c064232: /* original 2302, guest PC 0x0c064232 */
if(!s->budget--) { s->failed_pc=0x0c064232u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c064234;
P_0c064234: /* original 2542, guest PC 0x0c064234 */
if(!s->budget--) { s->failed_pc=0x0c064234u; return 0; }
write(ram,r[5],r[4],4);
goto P_0c064236;
P_0c064236: /* original 000b, guest PC 0x0c064236 */
if(!s->budget--) { s->failed_pc=0x0c064236u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c064238: /* original 6043, guest PC 0x0c064238 */
if(!s->budget--) { s->failed_pc=0x0c064238u; return 0; }
r[0]=r[4];
goto P_0c06423a;
P_0c06423a: /* original 2fe6, guest PC 0x0c06423a */
if(!s->budget--) { s->failed_pc=0x0c06423au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06423c;
P_0c06423c: /* original 2fd6, guest PC 0x0c06423c */
if(!s->budget--) { s->failed_pc=0x0c06423cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06423e;
P_0c06423e: /* original 2fc6, guest PC 0x0c06423e */
if(!s->budget--) { s->failed_pc=0x0c06423eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c064240;
P_0c064240: /* original 2fb6, guest PC 0x0c064240 */
if(!s->budget--) { s->failed_pc=0x0c064240u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c064242;
P_0c064242: /* original 2fa6, guest PC 0x0c064242 */
if(!s->budget--) { s->failed_pc=0x0c064242u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c064244;
P_0c064244: /* original 2f96, guest PC 0x0c064244 */
if(!s->budget--) { s->failed_pc=0x0c064244u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c064246;
P_0c064246: /* original 4f22, guest PC 0x0c064246 */
if(!s->budget--) { s->failed_pc=0x0c064246u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c064248;
P_0c064248: /* original dc26, guest PC 0x0c064248 */
if(!s->budget--) { s->failed_pc=0x0c064248u; return 0; }
r[12]=read(ram,0x0c0642e4u,4);
goto P_0c06424a;
P_0c06424a: /* original 6dc2, guest PC 0x0c06424a */
if(!s->budget--) { s->failed_pc=0x0c06424au; return 0; }
tmp=read(ram,r[12],4);
r[13]=tmp;
goto P_0c06424c;
P_0c06424c: /* original e908, guest PC 0x0c06424c */
if(!s->budget--) { s->failed_pc=0x0c06424cu; return 0; }
r[9]=0x00000008u;
goto P_0c06424e;
P_0c06424e: /* original 63d3, guest PC 0x0c06424e */
if(!s->budget--) { s->failed_pc=0x0c06424eu; return 0; }
r[3]=r[13];
goto P_0c064250;
P_0c064250: /* original de25, guest PC 0x0c064250 */
if(!s->budget--) { s->failed_pc=0x0c064250u; return 0; }
r[14]=read(ram,0x0c0642e8u,4);
goto P_0c064252;
P_0c064252: /* original 2398, guest PC 0x0c064252 */
if(!s->budget--) { s->failed_pc=0x0c064252u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c064254;
P_0c064254: /* original 8906, guest PC 0x0c064254 */
if(!s->budget--) { s->failed_pc=0x0c064254u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064264; }
goto P_0c064256;
P_0c064256: /* original bd62, guest PC 0x0c064256 */
if(!s->budget--) { s->failed_pc=0x0c064256u; return 0; }
target=code_base|0x0c063d1eu; r[16]=code_base|0x0c06425au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06425au) { target=s->pc; goto dispatch; }
goto P_0c06425a;
P_0c064258: /* original 0009, guest PC 0x0c064258 */
if(!s->budget--) { s->failed_pc=0x0c064258u; return 0; }
goto P_0c06425a;
P_0c06425a: /* original 6403, guest PC 0x0c06425a */
if(!s->budget--) { s->failed_pc=0x0c06425au; return 0; }
r[4]=r[0];
goto P_0c06425c;
P_0c06425c: /* original 2448, guest PC 0x0c06425c */
if(!s->budget--) { s->failed_pc=0x0c06425cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06425e;
P_0c06425e: /* original 8901, guest PC 0x0c06425e */
if(!s->budget--) { s->failed_pc=0x0c06425eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064264; }
goto P_0c064260;
P_0c064260: /* original 4e0b, guest PC 0x0c064260 */
if(!s->budget--) { s->failed_pc=0x0c064260u; return 0; }
target=r[14];
r[16]=code_base|0x0c064264u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064264u) { target=s->pc; goto dispatch; }
goto P_0c064264;
P_0c064262: /* original 0009, guest PC 0x0c064262 */
if(!s->budget--) { s->failed_pc=0x0c064262u; return 0; }
goto P_0c064264;
P_0c064264: /* original e420, guest PC 0x0c064264 */
if(!s->budget--) { s->failed_pc=0x0c064264u; return 0; }
r[4]=0x00000020u;
goto P_0c064266;
P_0c064266: /* original 62d3, guest PC 0x0c064266 */
if(!s->budget--) { s->failed_pc=0x0c064266u; return 0; }
r[2]=r[13];
goto P_0c064268;
P_0c064268: /* original 2248, guest PC 0x0c064268 */
if(!s->budget--) { s->failed_pc=0x0c064268u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c06426a;
P_0c06426a: /* original 8d05, guest PC 0x0c06426a */
if(!s->budget--) { s->failed_pc=0x0c06426au; return 0; }
cond=r[17]&1u;
r[10]=0x00000004u;
if(cond) { goto P_0c064278; }
goto P_0c06426e;
P_0c06426c: /* original ea04, guest PC 0x0c06426c */
if(!s->budget--) { s->failed_pc=0x0c06426cu; return 0; }
r[10]=0x00000004u;
goto P_0c06426e;
P_0c06426e: /* original 2c42, guest PC 0x0c06426e */
if(!s->budget--) { s->failed_pc=0x0c06426eu; return 0; }
write(ram,r[12],r[4],4);
goto P_0c064270;
P_0c064270: /* original d31b, guest PC 0x0c064270 */
if(!s->budget--) { s->failed_pc=0x0c064270u; return 0; }
r[3]=read(ram,0x0c0642e0u,4);
goto P_0c064272;
P_0c064272: /* original 6232, guest PC 0x0c064272 */
if(!s->budget--) { s->failed_pc=0x0c064272u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c064274;
P_0c064274: /* original 22ab, guest PC 0x0c064274 */
if(!s->budget--) { s->failed_pc=0x0c064274u; return 0; }
r[2]|=r[10];
goto P_0c064276;
P_0c064276: /* original 2322, guest PC 0x0c064276 */
if(!s->budget--) { s->failed_pc=0x0c064276u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c064278;
P_0c064278: /* original 63d3, guest PC 0x0c064278 */
if(!s->budget--) { s->failed_pc=0x0c064278u; return 0; }
r[3]=r[13];
goto P_0c06427a;
P_0c06427a: /* original 23a8, guest PC 0x0c06427a */
if(!s->budget--) { s->failed_pc=0x0c06427au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[10])==0)!=0);
goto P_0c06427c;
P_0c06427c: /* original 8d57, guest PC 0x0c06427c */
if(!s->budget--) { s->failed_pc=0x0c06427cu; return 0; }
cond=r[17]&1u;
r[11]=0x00000001u;
if(cond) { goto P_0c06432e; }
goto P_0c064280;
P_0c06427e: /* original eb01, guest PC 0x0c06427e */
if(!s->budget--) { s->failed_pc=0x0c06427eu; return 0; }
r[11]=0x00000001u;
goto P_0c064280;
P_0c064280: /* original e107, guest PC 0x0c064280 */
if(!s->budget--) { s->failed_pc=0x0c064280u; return 0; }
r[1]=0x00000007u;
goto P_0c064282;
P_0c064282: /* original 2c12, guest PC 0x0c064282 */
if(!s->budget--) { s->failed_pc=0x0c064282u; return 0; }
write(ram,r[12],r[1],4);
goto P_0c064284;
P_0c064284: /* original d319, guest PC 0x0c064284 */
if(!s->budget--) { s->failed_pc=0x0c064284u; return 0; }
r[3]=read(ram,0x0c0642ecu,4);
goto P_0c064286;
P_0c064286: /* original e400, guest PC 0x0c064286 */
if(!s->budget--) { s->failed_pc=0x0c064286u; return 0; }
r[4]=0x00000000u;
goto P_0c064288;
P_0c064288: /* original 2342, guest PC 0x0c064288 */
if(!s->budget--) { s->failed_pc=0x0c064288u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c06428a;
P_0c06428a: /* original d511, guest PC 0x0c06428a */
if(!s->budget--) { s->failed_pc=0x0c06428au; return 0; }
r[5]=read(ram,0x0c0642d0u,4);
goto P_0c06428c;
P_0c06428c: /* original d018, guest PC 0x0c06428c */
if(!s->budget--) { s->failed_pc=0x0c06428cu; return 0; }
r[0]=read(ram,0x0c0642f0u,4);
goto P_0c06428e;
P_0c06428e: /* original 2542, guest PC 0x0c06428e */
if(!s->budget--) { s->failed_pc=0x0c06428eu; return 0; }
write(ram,r[5],r[4],4);
goto P_0c064290;
P_0c064290: /* original 6202, guest PC 0x0c064290 */
if(!s->budget--) { s->failed_pc=0x0c064290u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c064292;
P_0c064292: /* original e040, guest PC 0x0c064292 */
if(!s->budget--) { s->failed_pc=0x0c064292u; return 0; }
r[0]=0x00000040u;
goto P_0c064294;
P_0c064294: /* original 015e, guest PC 0x0c064294 */
if(!s->budget--) { s->failed_pc=0x0c064294u; return 0; }
r[1]=read(ram,r[5]+r[0],4);
goto P_0c064296;
P_0c064296: /* original e044, guest PC 0x0c064296 */
if(!s->budget--) { s->failed_pc=0x0c064296u; return 0; }
r[0]=0x00000044u;
goto P_0c064298;
P_0c064298: /* original 3128, guest PC 0x0c064298 */
if(!s->budget--) { s->failed_pc=0x0c064298u; return 0; }
r[1]-=r[2];
goto P_0c06429a;
P_0c06429a: /* original 0516, guest PC 0x0c06429a */
if(!s->budget--) { s->failed_pc=0x0c06429au; return 0; }
write(ram,r[5]+r[0],r[1],4);
goto P_0c06429c;
P_0c06429c: /* original d115, guest PC 0x0c06429c */
if(!s->budget--) { s->failed_pc=0x0c06429cu; return 0; }
r[1]=read(ram,0x0c0642f4u,4);
goto P_0c06429e;
P_0c06429e: /* original 6212, guest PC 0x0c06429e */
if(!s->budget--) { s->failed_pc=0x0c06429eu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0642a0;
P_0c0642a0: /* original 2228, guest PC 0x0c0642a0 */
if(!s->budget--) { s->failed_pc=0x0c0642a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0642a2;
P_0c0642a2: /* original 8937, guest PC 0x0c0642a2 */
if(!s->budget--) { s->failed_pc=0x0c0642a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064314; }
goto P_0c0642a4;
P_0c0642a4: /* original d313, guest PC 0x0c0642a4 */
if(!s->budget--) { s->failed_pc=0x0c0642a4u; return 0; }
r[3]=read(ram,0x0c0642f4u,4);
goto P_0c0642a6;
P_0c0642a6: /* original 2342, guest PC 0x0c0642a6 */
if(!s->budget--) { s->failed_pc=0x0c0642a6u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0642a8;
P_0c0642a8: /* original 1546, guest PC 0x0c0642a8 */
if(!s->budget--) { s->failed_pc=0x0c0642a8u; return 0; }
write(ram,r[5]+24,r[4],4);
goto P_0c0642aa;
P_0c0642aa: /* original d013, guest PC 0x0c0642aa */
if(!s->budget--) { s->failed_pc=0x0c0642aau; return 0; }
r[0]=read(ram,0x0c0642f8u,4);
goto P_0c0642ac;
P_0c0642ac: /* original 6202, guest PC 0x0c0642ac */
if(!s->budget--) { s->failed_pc=0x0c0642acu; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c0642ae;
P_0c0642ae: /* original d113, guest PC 0x0c0642ae */
if(!s->budget--) { s->failed_pc=0x0c0642aeu; return 0; }
r[1]=read(ram,0x0c0642fcu,4);
goto P_0c0642b0;
P_0c0642b0: /* original 2122, guest PC 0x0c0642b0 */
if(!s->budget--) { s->failed_pc=0x0c0642b0u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c0642b2;
P_0c0642b2: /* original d213, guest PC 0x0c0642b2 */
if(!s->budget--) { s->failed_pc=0x0c0642b2u; return 0; }
r[2]=read(ram,0x0c064300u,4);
goto P_0c0642b4;
P_0c0642b4: /* original 6322, guest PC 0x0c0642b4 */
if(!s->budget--) { s->failed_pc=0x0c0642b4u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0642b6;
P_0c0642b6: /* original 7104, guest PC 0x0c0642b6 */
if(!s->budget--) { s->failed_pc=0x0c0642b6u; return 0; }
r[1]+=0x00000004u;
goto P_0c0642b8;
P_0c0642b8: /* original 2132, guest PC 0x0c0642b8 */
if(!s->budget--) { s->failed_pc=0x0c0642b8u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c0642ba;
P_0c0642ba: /* original d312, guest PC 0x0c0642ba */
if(!s->budget--) { s->failed_pc=0x0c0642bau; return 0; }
r[3]=read(ram,0x0c064304u,4);
goto P_0c0642bc;
P_0c0642bc: /* original 6032, guest PC 0x0c0642bc */
if(!s->budget--) { s->failed_pc=0x0c0642bcu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0642be;
P_0c0642be: /* original d212, guest PC 0x0c0642be */
if(!s->budget--) { s->failed_pc=0x0c0642beu; return 0; }
r[2]=read(ram,0x0c064308u,4);
goto P_0c0642c0;
P_0c0642c0: /* original 2202, guest PC 0x0c0642c0 */
if(!s->budget--) { s->failed_pc=0x0c0642c0u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c0642c2;
P_0c0642c2: /* original d012, guest PC 0x0c0642c2 */
if(!s->budget--) { s->failed_pc=0x0c0642c2u; return 0; }
r[0]=read(ram,0x0c06430cu,4);
goto P_0c0642c4;
P_0c0642c4: /* original 6102, guest PC 0x0c0642c4 */
if(!s->budget--) { s->failed_pc=0x0c0642c4u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c0642c6;
P_0c0642c6: /* original d312, guest PC 0x0c0642c6 */
if(!s->budget--) { s->failed_pc=0x0c0642c6u; return 0; }
r[3]=read(ram,0x0c064310u,4);
goto P_0c0642c8;
P_0c0642c8: /* original a02b, guest PC 0x0c0642c8 */
if(!s->budget--) { s->failed_pc=0x0c0642c8u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c064322;
P_0c0642ca: /* original 2312, guest PC 0x0c0642ca */
if(!s->budget--) { s->failed_pc=0x0c0642cau; return 0; }
write(ram,r[3],r[1],4);
if(!vf3_matrix_family(0x0c0642ccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0642ccu; return 0; } return 1;
P_0c064314: /* original d043, guest PC 0x0c064314 */
if(!s->budget--) { s->failed_pc=0x0c064314u; return 0; }
r[0]=read(ram,0x0c064424u,4);
goto P_0c064316;
P_0c064316: /* original e105, guest PC 0x0c064316 */
if(!s->budget--) { s->failed_pc=0x0c064316u; return 0; }
r[1]=0x00000005u;
goto P_0c064318;
P_0c064318: /* original 6203, guest PC 0x0c064318 */
if(!s->budget--) { s->failed_pc=0x0c064318u; return 0; }
r[2]=r[0];
goto P_0c06431a;
P_0c06431a: /* original 7214, guest PC 0x0c06431a */
if(!s->budget--) { s->failed_pc=0x0c06431au; return 0; }
r[2]+=0x00000014u;
goto P_0c06431c;
P_0c06431c: /* original 6322, guest PC 0x0c06431c */
if(!s->budget--) { s->failed_pc=0x0c06431cu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c06431e;
P_0c06431e: /* original 4308, guest PC 0x0c06431e */
if(!s->budget--) { s->failed_pc=0x0c06431eu; return 0; }
r[3]<<=2;
goto P_0c064320;
P_0c064320: /* original 0316, guest PC 0x0c064320 */
if(!s->budget--) { s->failed_pc=0x0c064320u; return 0; }
write(ram,r[3]+r[0],r[1],4);
goto P_0c064322;
P_0c064322: /* original d341, guest PC 0x0c064322 */
if(!s->budget--) { s->failed_pc=0x0c064322u; return 0; }
r[3]=read(ram,0x0c064428u,4);
goto P_0c064324;
P_0c064324: /* original 6232, guest PC 0x0c064324 */
if(!s->budget--) { s->failed_pc=0x0c064324u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c064326;
P_0c064326: /* original 22bb, guest PC 0x0c064326 */
if(!s->budget--) { s->failed_pc=0x0c064326u; return 0; }
r[2]|=r[11];
goto P_0c064328;
P_0c064328: /* original 2322, guest PC 0x0c064328 */
if(!s->budget--) { s->failed_pc=0x0c064328u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c06432a;
P_0c06432a: /* original d340, guest PC 0x0c06432a */
if(!s->budget--) { s->failed_pc=0x0c06432au; return 0; }
r[3]=read(ram,0x0c06442cu,4);
goto P_0c06432c;
P_0c06432c: /* original 2342, guest PC 0x0c06432c */
if(!s->budget--) { s->failed_pc=0x0c06432cu; return 0; }
write(ram,r[3],r[4],4);
goto P_0c06432e;
P_0c06432e: /* original 63d3, guest PC 0x0c06432e */
if(!s->budget--) { s->failed_pc=0x0c06432eu; return 0; }
r[3]=r[13];
goto P_0c064330;
P_0c064330: /* original d53f, guest PC 0x0c064330 */
if(!s->budget--) { s->failed_pc=0x0c064330u; return 0; }
r[5]=read(ram,0x0c064430u,4);
goto P_0c064332;
P_0c064332: /* original 2358, guest PC 0x0c064332 */
if(!s->budget--) { s->failed_pc=0x0c064332u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c064334;
P_0c064334: /* original 8907, guest PC 0x0c064334 */
if(!s->budget--) { s->failed_pc=0x0c064334u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064346; }
goto P_0c064336;
P_0c064336: /* original e3fc, guest PC 0x0c064336 */
if(!s->budget--) { s->failed_pc=0x0c064336u; return 0; }
r[3]=0xfffffffcu;
goto P_0c064338;
P_0c064338: /* original d63e, guest PC 0x0c064338 */
if(!s->budget--) { s->failed_pc=0x0c064338u; return 0; }
r[6]=read(ram,0x0c064434u,4);
goto P_0c06433a;
P_0c06433a: /* original 6462, guest PC 0x0c06433a */
if(!s->budget--) { s->failed_pc=0x0c06433au; return 0; }
tmp=read(ram,r[6],4);
r[4]=tmp;
goto P_0c06433c;
P_0c06433c: /* original 2439, guest PC 0x0c06433c */
if(!s->budget--) { s->failed_pc=0x0c06433cu; return 0; }
r[4]&=r[3];
goto P_0c06433e;
P_0c06433e: /* original 2642, guest PC 0x0c06433e */
if(!s->budget--) { s->failed_pc=0x0c06433eu; return 0; }
write(ram,r[6],r[4],4);
goto P_0c064340;
P_0c064340: /* original d23d, guest PC 0x0c064340 */
if(!s->budget--) { s->failed_pc=0x0c064340u; return 0; }
r[2]=read(ram,0x0c064438u,4);
goto P_0c064342;
P_0c064342: /* original 420b, guest PC 0x0c064342 */
if(!s->budget--) { s->failed_pc=0x0c064342u; return 0; }
target=r[2];
r[16]=code_base|0x0c064346u;
write(ram,r[12],r[5],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064346u) { target=s->pc; goto dispatch; }
goto P_0c064346;
P_0c064344: /* original 2c52, guest PC 0x0c064344 */
if(!s->budget--) { s->failed_pc=0x0c064344u; return 0; }
write(ram,r[12],r[5],4);
goto P_0c064346;
P_0c064346: /* original e440, guest PC 0x0c064346 */
if(!s->budget--) { s->failed_pc=0x0c064346u; return 0; }
r[4]=0x00000040u;
goto P_0c064348;
P_0c064348: /* original 63d3, guest PC 0x0c064348 */
if(!s->budget--) { s->failed_pc=0x0c064348u; return 0; }
r[3]=r[13];
goto P_0c06434a;
P_0c06434a: /* original 2348, guest PC 0x0c06434a */
if(!s->budget--) { s->failed_pc=0x0c06434au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c06434c;
P_0c06434c: /* original 8904, guest PC 0x0c06434c */
if(!s->budget--) { s->failed_pc=0x0c06434cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064358; }
goto P_0c06434e;
P_0c06434e: /* original 2c42, guest PC 0x0c06434e */
if(!s->budget--) { s->failed_pc=0x0c06434eu; return 0; }
write(ram,r[12],r[4],4);
goto P_0c064350;
P_0c064350: /* original d335, guest PC 0x0c064350 */
if(!s->budget--) { s->failed_pc=0x0c064350u; return 0; }
r[3]=read(ram,0x0c064428u,4);
goto P_0c064352;
P_0c064352: /* original 6232, guest PC 0x0c064352 */
if(!s->budget--) { s->failed_pc=0x0c064352u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c064354;
P_0c064354: /* original 224b, guest PC 0x0c064354 */
if(!s->budget--) { s->failed_pc=0x0c064354u; return 0; }
r[2]|=r[4];
goto P_0c064356;
P_0c064356: /* original 2322, guest PC 0x0c064356 */
if(!s->budget--) { s->failed_pc=0x0c064356u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c064358;
P_0c064358: /* original 945f, guest PC 0x0c064358 */
if(!s->budget--) { s->failed_pc=0x0c064358u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06441au,2);
goto P_0c06435a;
P_0c06435a: /* original 63d3, guest PC 0x0c06435a */
if(!s->budget--) { s->failed_pc=0x0c06435au; return 0; }
r[3]=r[13];
goto P_0c06435c;
P_0c06435c: /* original 2348, guest PC 0x0c06435c */
if(!s->budget--) { s->failed_pc=0x0c06435cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c06435e;
P_0c06435e: /* original 890d, guest PC 0x0c06435e */
if(!s->budget--) { s->failed_pc=0x0c06435eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06437c; }
goto P_0c064360;
P_0c064360: /* original 2c42, guest PC 0x0c064360 */
if(!s->budget--) { s->failed_pc=0x0c064360u; return 0; }
write(ram,r[12],r[4],4);
goto P_0c064362;
P_0c064362: /* original d336, guest PC 0x0c064362 */
if(!s->budget--) { s->failed_pc=0x0c064362u; return 0; }
r[3]=read(ram,0x0c06443cu,4);
goto P_0c064364;
P_0c064364: /* original 6232, guest PC 0x0c064364 */
if(!s->budget--) { s->failed_pc=0x0c064364u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c064366;
P_0c064366: /* original 22bb, guest PC 0x0c064366 */
if(!s->budget--) { s->failed_pc=0x0c064366u; return 0; }
r[2]|=r[11];
goto P_0c064368;
P_0c064368: /* original 2322, guest PC 0x0c064368 */
if(!s->budget--) { s->failed_pc=0x0c064368u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c06436a;
P_0c06436a: /* original 6033, guest PC 0x0c06436a */
if(!s->budget--) { s->failed_pc=0x0c06436au; return 0; }
r[0]=r[3];
goto P_0c06436c;
P_0c06436c: /* original 0009, guest PC 0x0c06436c */
if(!s->budget--) { s->failed_pc=0x0c06436cu; return 0; }
goto P_0c06436e;
P_0c06436e: /* original 6302, guest PC 0x0c06436e */
if(!s->budget--) { s->failed_pc=0x0c06436eu; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c064370;
P_0c064370: /* original d233, guest PC 0x0c064370 */
if(!s->budget--) { s->failed_pc=0x0c064370u; return 0; }
r[2]=read(ram,0x0c064440u,4);
goto P_0c064372;
P_0c064372: /* original 6122, guest PC 0x0c064372 */
if(!s->budget--) { s->failed_pc=0x0c064372u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c064374;
P_0c064374: /* original 3130, guest PC 0x0c064374 */
if(!s->budget--) { s->failed_pc=0x0c064374u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[3])!=0);
goto P_0c064376;
P_0c064376: /* original 8b01, guest PC 0x0c064376 */
if(!s->budget--) { s->failed_pc=0x0c064376u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06437c; }
goto P_0c064378;
P_0c064378: /* original be05, guest PC 0x0c064378 */
if(!s->budget--) { s->failed_pc=0x0c064378u; return 0; }
target=code_base|0x0c063f86u; r[16]=code_base|0x0c06437cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06437cu) { target=s->pc; goto dispatch; }
goto P_0c06437c;
P_0c06437a: /* original 0009, guest PC 0x0c06437a */
if(!s->budget--) { s->failed_pc=0x0c06437au; return 0; }
goto P_0c06437c;
P_0c06437c: /* original 944e, guest PC 0x0c06437c */
if(!s->budget--) { s->failed_pc=0x0c06437cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06441cu,2);
goto P_0c06437e;
P_0c06437e: /* original 63d3, guest PC 0x0c06437e */
if(!s->budget--) { s->failed_pc=0x0c06437eu; return 0; }
r[3]=r[13];
goto P_0c064380;
P_0c064380: /* original 2348, guest PC 0x0c064380 */
if(!s->budget--) { s->failed_pc=0x0c064380u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c064382;
P_0c064382: /* original 890c, guest PC 0x0c064382 */
if(!s->budget--) { s->failed_pc=0x0c064382u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06439e; }
goto P_0c064384;
P_0c064384: /* original 2c42, guest PC 0x0c064384 */
if(!s->budget--) { s->failed_pc=0x0c064384u; return 0; }
write(ram,r[12],r[4],4);
goto P_0c064386;
P_0c064386: /* original d32d, guest PC 0x0c064386 */
if(!s->budget--) { s->failed_pc=0x0c064386u; return 0; }
r[3]=read(ram,0x0c06443cu,4);
goto P_0c064388;
P_0c064388: /* original 6032, guest PC 0x0c064388 */
if(!s->budget--) { s->failed_pc=0x0c064388u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c06438a;
P_0c06438a: /* original cb02, guest PC 0x0c06438a */
if(!s->budget--) { s->failed_pc=0x0c06438au; return 0; }
r[0]|=2u;
goto P_0c06438c;
P_0c06438c: /* original 2302, guest PC 0x0c06438c */
if(!s->budget--) { s->failed_pc=0x0c06438cu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c06438e;
P_0c06438e: /* original 6133, guest PC 0x0c06438e */
if(!s->budget--) { s->failed_pc=0x0c06438eu; return 0; }
r[1]=r[3];
goto P_0c064390;
P_0c064390: /* original 6212, guest PC 0x0c064390 */
if(!s->budget--) { s->failed_pc=0x0c064390u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c064392;
P_0c064392: /* original d02b, guest PC 0x0c064392 */
if(!s->budget--) { s->failed_pc=0x0c064392u; return 0; }
r[0]=read(ram,0x0c064440u,4);
goto P_0c064394;
P_0c064394: /* original 6302, guest PC 0x0c064394 */
if(!s->budget--) { s->failed_pc=0x0c064394u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c064396;
P_0c064396: /* original 3320, guest PC 0x0c064396 */
if(!s->budget--) { s->failed_pc=0x0c064396u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c064398;
P_0c064398: /* original 8b01, guest PC 0x0c064398 */
if(!s->budget--) { s->failed_pc=0x0c064398u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06439e; }
goto P_0c06439a;
P_0c06439a: /* original bdf4, guest PC 0x0c06439a */
if(!s->budget--) { s->failed_pc=0x0c06439au; return 0; }
target=code_base|0x0c063f86u; r[16]=code_base|0x0c06439eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06439eu) { target=s->pc; goto dispatch; }
goto P_0c06439e;
P_0c06439c: /* original 0009, guest PC 0x0c06439c */
if(!s->budget--) { s->failed_pc=0x0c06439cu; return 0; }
goto P_0c06439e;
P_0c06439e: /* original 63d3, guest PC 0x0c06439e */
if(!s->budget--) { s->failed_pc=0x0c06439eu; return 0; }
r[3]=r[13];
goto P_0c0643a0;
P_0c0643a0: /* original 943d, guest PC 0x0c0643a0 */
if(!s->budget--) { s->failed_pc=0x0c0643a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06441eu,2);
goto P_0c0643a2;
P_0c0643a2: /* original 2348, guest PC 0x0c0643a2 */
if(!s->budget--) { s->failed_pc=0x0c0643a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0643a4;
P_0c0643a4: /* original 890d, guest PC 0x0c0643a4 */
if(!s->budget--) { s->failed_pc=0x0c0643a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0643c2; }
goto P_0c0643a6;
P_0c0643a6: /* original 2c42, guest PC 0x0c0643a6 */
if(!s->budget--) { s->failed_pc=0x0c0643a6u; return 0; }
write(ram,r[12],r[4],4);
goto P_0c0643a8;
P_0c0643a8: /* original d324, guest PC 0x0c0643a8 */
if(!s->budget--) { s->failed_pc=0x0c0643a8u; return 0; }
r[3]=read(ram,0x0c06443cu,4);
goto P_0c0643aa;
P_0c0643aa: /* original 6232, guest PC 0x0c0643aa */
if(!s->budget--) { s->failed_pc=0x0c0643aau; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0643ac;
P_0c0643ac: /* original 22ab, guest PC 0x0c0643ac */
if(!s->budget--) { s->failed_pc=0x0c0643acu; return 0; }
r[2]|=r[10];
goto P_0c0643ae;
P_0c0643ae: /* original 2322, guest PC 0x0c0643ae */
if(!s->budget--) { s->failed_pc=0x0c0643aeu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0643b0;
P_0c0643b0: /* original 6033, guest PC 0x0c0643b0 */
if(!s->budget--) { s->failed_pc=0x0c0643b0u; return 0; }
r[0]=r[3];
goto P_0c0643b2;
P_0c0643b2: /* original 0009, guest PC 0x0c0643b2 */
if(!s->budget--) { s->failed_pc=0x0c0643b2u; return 0; }
goto P_0c0643b4;
P_0c0643b4: /* original 6302, guest PC 0x0c0643b4 */
if(!s->budget--) { s->failed_pc=0x0c0643b4u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c0643b6;
P_0c0643b6: /* original d222, guest PC 0x0c0643b6 */
if(!s->budget--) { s->failed_pc=0x0c0643b6u; return 0; }
r[2]=read(ram,0x0c064440u,4);
goto P_0c0643b8;
P_0c0643b8: /* original 6122, guest PC 0x0c0643b8 */
if(!s->budget--) { s->failed_pc=0x0c0643b8u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0643ba;
P_0c0643ba: /* original 3130, guest PC 0x0c0643ba */
if(!s->budget--) { s->failed_pc=0x0c0643bau; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[3])!=0);
goto P_0c0643bc;
P_0c0643bc: /* original 8b01, guest PC 0x0c0643bc */
if(!s->budget--) { s->failed_pc=0x0c0643bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0643c2; }
goto P_0c0643be;
P_0c0643be: /* original bde2, guest PC 0x0c0643be */
if(!s->budget--) { s->failed_pc=0x0c0643beu; return 0; }
target=code_base|0x0c063f86u; r[16]=code_base|0x0c0643c2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0643c2u) { target=s->pc; goto dispatch; }
goto P_0c0643c2;
P_0c0643c0: /* original 0009, guest PC 0x0c0643c0 */
if(!s->budget--) { s->failed_pc=0x0c0643c0u; return 0; }
goto P_0c0643c2;
P_0c0643c2: /* original 63d3, guest PC 0x0c0643c2 */
if(!s->budget--) { s->failed_pc=0x0c0643c2u; return 0; }
r[3]=r[13];
goto P_0c0643c4;
P_0c0643c4: /* original 942c, guest PC 0x0c0643c4 */
if(!s->budget--) { s->failed_pc=0x0c0643c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c064420u,2);
goto P_0c0643c6;
P_0c0643c6: /* original 2348, guest PC 0x0c0643c6 */
if(!s->budget--) { s->failed_pc=0x0c0643c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0643c8;
P_0c0643c8: /* original 890d, guest PC 0x0c0643c8 */
if(!s->budget--) { s->failed_pc=0x0c0643c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0643e6; }
goto P_0c0643ca;
P_0c0643ca: /* original 2c42, guest PC 0x0c0643ca */
if(!s->budget--) { s->failed_pc=0x0c0643cau; return 0; }
write(ram,r[12],r[4],4);
goto P_0c0643cc;
P_0c0643cc: /* original d31b, guest PC 0x0c0643cc */
if(!s->budget--) { s->failed_pc=0x0c0643ccu; return 0; }
r[3]=read(ram,0x0c06443cu,4);
goto P_0c0643ce;
P_0c0643ce: /* original 6232, guest PC 0x0c0643ce */
if(!s->budget--) { s->failed_pc=0x0c0643ceu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0643d0;
P_0c0643d0: /* original 229b, guest PC 0x0c0643d0 */
if(!s->budget--) { s->failed_pc=0x0c0643d0u; return 0; }
r[2]|=r[9];
goto P_0c0643d2;
P_0c0643d2: /* original 2322, guest PC 0x0c0643d2 */
if(!s->budget--) { s->failed_pc=0x0c0643d2u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0643d4;
P_0c0643d4: /* original 6033, guest PC 0x0c0643d4 */
if(!s->budget--) { s->failed_pc=0x0c0643d4u; return 0; }
r[0]=r[3];
goto P_0c0643d6;
P_0c0643d6: /* original 0009, guest PC 0x0c0643d6 */
if(!s->budget--) { s->failed_pc=0x0c0643d6u; return 0; }
goto P_0c0643d8;
P_0c0643d8: /* original 6302, guest PC 0x0c0643d8 */
if(!s->budget--) { s->failed_pc=0x0c0643d8u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c0643da;
P_0c0643da: /* original d219, guest PC 0x0c0643da */
if(!s->budget--) { s->failed_pc=0x0c0643dau; return 0; }
r[2]=read(ram,0x0c064440u,4);
goto P_0c0643dc;
P_0c0643dc: /* original 6122, guest PC 0x0c0643dc */
if(!s->budget--) { s->failed_pc=0x0c0643dcu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0643de;
P_0c0643de: /* original 3130, guest PC 0x0c0643de */
if(!s->budget--) { s->failed_pc=0x0c0643deu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[3])!=0);
goto P_0c0643e0;
P_0c0643e0: /* original 8b01, guest PC 0x0c0643e0 */
if(!s->budget--) { s->failed_pc=0x0c0643e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0643e6; }
goto P_0c0643e2;
P_0c0643e2: /* original bdd0, guest PC 0x0c0643e2 */
if(!s->budget--) { s->failed_pc=0x0c0643e2u; return 0; }
target=code_base|0x0c063f86u; r[16]=code_base|0x0c0643e6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0643e6u) { target=s->pc; goto dispatch; }
goto P_0c0643e6;
P_0c0643e4: /* original 0009, guest PC 0x0c0643e4 */
if(!s->budget--) { s->failed_pc=0x0c0643e4u; return 0; }
goto P_0c0643e6;
P_0c0643e6: /* original d417, guest PC 0x0c0643e6 */
if(!s->budget--) { s->failed_pc=0x0c0643e6u; return 0; }
r[4]=read(ram,0x0c064444u,4);
goto P_0c0643e8;
P_0c0643e8: /* original 2d48, guest PC 0x0c0643e8 */
if(!s->budget--) { s->failed_pc=0x0c0643e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[4])==0)!=0);
goto P_0c0643ea;
P_0c0643ea: /* original 890c, guest PC 0x0c0643ea */
if(!s->budget--) { s->failed_pc=0x0c0643eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064406; }
goto P_0c0643ec;
P_0c0643ec: /* original 2c42, guest PC 0x0c0643ec */
if(!s->budget--) { s->failed_pc=0x0c0643ecu; return 0; }
write(ram,r[12],r[4],4);
goto P_0c0643ee;
P_0c0643ee: /* original d313, guest PC 0x0c0643ee */
if(!s->budget--) { s->failed_pc=0x0c0643eeu; return 0; }
r[3]=read(ram,0x0c06443cu,4);
goto P_0c0643f0;
P_0c0643f0: /* original 6032, guest PC 0x0c0643f0 */
if(!s->budget--) { s->failed_pc=0x0c0643f0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0643f2;
P_0c0643f2: /* original cb10, guest PC 0x0c0643f2 */
if(!s->budget--) { s->failed_pc=0x0c0643f2u; return 0; }
r[0]|=16u;
goto P_0c0643f4;
P_0c0643f4: /* original 2302, guest PC 0x0c0643f4 */
if(!s->budget--) { s->failed_pc=0x0c0643f4u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c0643f6;
P_0c0643f6: /* original 6133, guest PC 0x0c0643f6 */
if(!s->budget--) { s->failed_pc=0x0c0643f6u; return 0; }
r[1]=r[3];
goto P_0c0643f8;
P_0c0643f8: /* original 6212, guest PC 0x0c0643f8 */
if(!s->budget--) { s->failed_pc=0x0c0643f8u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0643fa;
P_0c0643fa: /* original d011, guest PC 0x0c0643fa */
if(!s->budget--) { s->failed_pc=0x0c0643fau; return 0; }
r[0]=read(ram,0x0c064440u,4);
goto P_0c0643fc;
P_0c0643fc: /* original 6302, guest PC 0x0c0643fc */
if(!s->budget--) { s->failed_pc=0x0c0643fcu; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c0643fe;
P_0c0643fe: /* original 3320, guest PC 0x0c0643fe */
if(!s->budget--) { s->failed_pc=0x0c0643feu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c064400;
P_0c064400: /* original 8b01, guest PC 0x0c064400 */
if(!s->budget--) { s->failed_pc=0x0c064400u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c064406; }
goto P_0c064402;
P_0c064402: /* original bdc0, guest PC 0x0c064402 */
if(!s->budget--) { s->failed_pc=0x0c064402u; return 0; }
target=code_base|0x0c063f86u; r[16]=code_base|0x0c064406u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064406u) { target=s->pc; goto dispatch; }
goto P_0c064406;
P_0c064404: /* original 0009, guest PC 0x0c064404 */
if(!s->budget--) { s->failed_pc=0x0c064404u; return 0; }
goto P_0c064406;
P_0c064406: /* original d310, guest PC 0x0c064406 */
if(!s->budget--) { s->failed_pc=0x0c064406u; return 0; }
r[3]=read(ram,0x0c064448u,4);
goto P_0c064408;
P_0c064408: /* original 6d32, guest PC 0x0c064408 */
if(!s->budget--) { s->failed_pc=0x0c064408u; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c06440a;
P_0c06440a: /* original 2ad8, guest PC 0x0c06440a */
if(!s->budget--) { s->failed_pc=0x0c06440au; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[13])==0)!=0);
goto P_0c06440c;
P_0c06440c: /* original 8921, guest PC 0x0c06440c */
if(!s->budget--) { s->failed_pc=0x0c06440cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064452; }
goto P_0c06440e;
P_0c06440e: /* original bed7, guest PC 0x0c06440e */
if(!s->budget--) { s->failed_pc=0x0c06440eu; return 0; }
target=code_base|0x0c0641c0u; r[16]=code_base|0x0c064412u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064412u) { target=s->pc; goto dispatch; }
goto P_0c064412;
P_0c064410: /* original 0009, guest PC 0x0c064410 */
if(!s->budget--) { s->failed_pc=0x0c064410u; return 0; }
goto P_0c064412;
P_0c064412: /* original 6403, guest PC 0x0c064412 */
if(!s->budget--) { s->failed_pc=0x0c064412u; return 0; }
r[4]=r[0];
goto P_0c064414;
P_0c064414: /* original 2448, guest PC 0x0c064414 */
if(!s->budget--) { s->failed_pc=0x0c064414u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c064416;
P_0c064416: /* original a019, guest PC 0x0c064416 */
if(!s->budget--) { s->failed_pc=0x0c064416u; return 0; }
goto P_0c06444c;
P_0c064418: /* original 0009, guest PC 0x0c064418 */
if(!s->budget--) { s->failed_pc=0x0c064418u; return 0; }
if(!vf3_matrix_family(0x0c06441au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06441au; return 0; } return 1;
P_0c06444c: /* original 8901, guest PC 0x0c06444c */
if(!s->budget--) { s->failed_pc=0x0c06444cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064452; }
goto P_0c06444e;
P_0c06444e: /* original 4e0b, guest PC 0x0c06444e */
if(!s->budget--) { s->failed_pc=0x0c06444eu; return 0; }
target=r[14];
r[16]=code_base|0x0c064452u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064452u) { target=s->pc; goto dispatch; }
goto P_0c064452;
P_0c064450: /* original 0009, guest PC 0x0c064450 */
if(!s->budget--) { s->failed_pc=0x0c064450u; return 0; }
goto P_0c064452;
P_0c064452: /* original 29d8, guest PC 0x0c064452 */
if(!s->budget--) { s->failed_pc=0x0c064452u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[13])==0)!=0);
goto P_0c064454;
P_0c064454: /* original 8906, guest PC 0x0c064454 */
if(!s->budget--) { s->failed_pc=0x0c064454u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064464; }
goto P_0c064456;
P_0c064456: /* original becd, guest PC 0x0c064456 */
if(!s->budget--) { s->failed_pc=0x0c064456u; return 0; }
target=code_base|0x0c0641f4u; r[16]=code_base|0x0c06445au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06445au) { target=s->pc; goto dispatch; }
goto P_0c06445a;
P_0c064458: /* original 0009, guest PC 0x0c064458 */
if(!s->budget--) { s->failed_pc=0x0c064458u; return 0; }
goto P_0c06445a;
P_0c06445a: /* original 6403, guest PC 0x0c06445a */
if(!s->budget--) { s->failed_pc=0x0c06445au; return 0; }
r[4]=r[0];
goto P_0c06445c;
P_0c06445c: /* original 2448, guest PC 0x0c06445c */
if(!s->budget--) { s->failed_pc=0x0c06445cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06445e;
P_0c06445e: /* original 8901, guest PC 0x0c06445e */
if(!s->budget--) { s->failed_pc=0x0c06445eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064464; }
goto P_0c064460;
P_0c064460: /* original 4e0b, guest PC 0x0c064460 */
if(!s->budget--) { s->failed_pc=0x0c064460u; return 0; }
target=r[14];
r[16]=code_base|0x0c064464u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064464u) { target=s->pc; goto dispatch; }
goto P_0c064464;
P_0c064462: /* original 0009, guest PC 0x0c064462 */
if(!s->budget--) { s->failed_pc=0x0c064462u; return 0; }
goto P_0c064464;
P_0c064464: /* original e302, guest PC 0x0c064464 */
if(!s->budget--) { s->failed_pc=0x0c064464u; return 0; }
r[3]=0x00000002u;
goto P_0c064466;
P_0c064466: /* original 2d38, guest PC 0x0c064466 */
if(!s->budget--) { s->failed_pc=0x0c064466u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[3])==0)!=0);
goto P_0c064468;
P_0c064468: /* original 8906, guest PC 0x0c064468 */
if(!s->budget--) { s->failed_pc=0x0c064468u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064478; }
goto P_0c06446a;
P_0c06446a: /* original bed7, guest PC 0x0c06446a */
if(!s->budget--) { s->failed_pc=0x0c06446au; return 0; }
target=code_base|0x0c06421cu; r[16]=code_base|0x0c06446eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06446eu) { target=s->pc; goto dispatch; }
goto P_0c06446e;
P_0c06446c: /* original 0009, guest PC 0x0c06446c */
if(!s->budget--) { s->failed_pc=0x0c06446cu; return 0; }
goto P_0c06446e;
P_0c06446e: /* original 6403, guest PC 0x0c06446e */
if(!s->budget--) { s->failed_pc=0x0c06446eu; return 0; }
r[4]=r[0];
goto P_0c064470;
P_0c064470: /* original 2448, guest PC 0x0c064470 */
if(!s->budget--) { s->failed_pc=0x0c064470u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c064472;
P_0c064472: /* original 8901, guest PC 0x0c064472 */
if(!s->budget--) { s->failed_pc=0x0c064472u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c064478; }
goto P_0c064474;
P_0c064474: /* original 4e0b, guest PC 0x0c064474 */
if(!s->budget--) { s->failed_pc=0x0c064474u; return 0; }
target=r[14];
r[16]=code_base|0x0c064478u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064478u) { target=s->pc; goto dispatch; }
goto P_0c064478;
P_0c064476: /* original 0009, guest PC 0x0c064476 */
if(!s->budget--) { s->failed_pc=0x0c064476u; return 0; }
goto P_0c064478;
P_0c064478: /* original da17, guest PC 0x0c064478 */
if(!s->budget--) { s->failed_pc=0x0c064478u; return 0; }
r[10]=read(ram,0x0c0644d8u,4);
goto P_0c06447a;
P_0c06447a: /* original ec09, guest PC 0x0c06447a */
if(!s->budget--) { s->failed_pc=0x0c06447au; return 0; }
r[12]=0x00000009u;
goto P_0c06447c;
P_0c06447c: /* original a013, guest PC 0x0c06447c */
if(!s->budget--) { s->failed_pc=0x0c06447cu; return 0; }
r[14]=0x00000000u;
goto P_0c0644a6;
P_0c06447e: /* original ee00, guest PC 0x0c06447e */
if(!s->budget--) { s->failed_pc=0x0c06447eu; return 0; }
r[14]=0x00000000u;
goto P_0c064480;
P_0c064480: /* original d216, guest PC 0x0c064480 */
if(!s->budget--) { s->failed_pc=0x0c064480u; return 0; }
r[2]=read(ram,0x0c0644dcu,4);
goto P_0c064482;
P_0c064482: /* original 64b3, guest PC 0x0c064482 */
if(!s->budget--) { s->failed_pc=0x0c064482u; return 0; }
r[4]=r[11];
goto P_0c064484;
P_0c064484: /* original 44ec, guest PC 0x0c064484 */
if(!s->budget--) { s->failed_pc=0x0c064484u; return 0; }
r[4]=(r[14]&0x80000000u)?((r[14]&31u)?(uint32_t)((int32_t)r[4]>>((-r[14])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[14]&31u);
goto P_0c064486;
P_0c064486: /* original 6322, guest PC 0x0c064486 */
if(!s->budget--) { s->failed_pc=0x0c064486u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c064488;
P_0c064488: /* original 2348, guest PC 0x0c064488 */
if(!s->budget--) { s->failed_pc=0x0c064488u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c06448a;
P_0c06448a: /* original 890b, guest PC 0x0c06448a */
if(!s->budget--) { s->failed_pc=0x0c06448au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0644a4; }
goto P_0c06448c;
P_0c06448c: /* original 6447, guest PC 0x0c06448c */
if(!s->budget--) { s->failed_pc=0x0c06448cu; return 0; }
r[4]=~r[4];
goto P_0c06448e;
P_0c06448e: /* original 6322, guest PC 0x0c06448e */
if(!s->budget--) { s->failed_pc=0x0c06448eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c064490;
P_0c064490: /* original 2349, guest PC 0x0c064490 */
if(!s->budget--) { s->failed_pc=0x0c064490u; return 0; }
r[3]&=r[4];
goto P_0c064492;
P_0c064492: /* original 2232, guest PC 0x0c064492 */
if(!s->budget--) { s->failed_pc=0x0c064492u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c064494;
P_0c064494: /* original d012, guest PC 0x0c064494 */
if(!s->budget--) { s->failed_pc=0x0c064494u; return 0; }
r[0]=read(ram,0x0c0644e0u,4);
goto P_0c064496;
P_0c064496: /* original 6de3, guest PC 0x0c064496 */
if(!s->budget--) { s->failed_pc=0x0c064496u; return 0; }
r[13]=r[14];
goto P_0c064498;
P_0c064498: /* original 4d08, guest PC 0x0c064498 */
if(!s->budget--) { s->failed_pc=0x0c064498u; return 0; }
r[13]<<=2;
goto P_0c06449a;
P_0c06449a: /* original 4d00, guest PC 0x0c06449a */
if(!s->budget--) { s->failed_pc=0x0c06449au; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c06449c;
P_0c06449c: /* original 05de, guest PC 0x0c06449c */
if(!s->budget--) { s->failed_pc=0x0c06449cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c06449e;
P_0c06449e: /* original 70fc, guest PC 0x0c06449e */
if(!s->budget--) { s->failed_pc=0x0c06449eu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0644a0;
P_0c0644a0: /* original 4a0b, guest PC 0x0c0644a0 */
if(!s->budget--) { s->failed_pc=0x0c0644a0u; return 0; }
target=r[10];
r[16]=code_base|0x0c0644a4u;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0644a4u) { target=s->pc; goto dispatch; }
goto P_0c0644a4;
P_0c0644a2: /* original 04de, guest PC 0x0c0644a2 */
if(!s->budget--) { s->failed_pc=0x0c0644a2u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c0644a4;
P_0c0644a4: /* original 7e01, guest PC 0x0c0644a4 */
if(!s->budget--) { s->failed_pc=0x0c0644a4u; return 0; }
r[14]+=0x00000001u;
goto P_0c0644a6;
P_0c0644a6: /* original 3ec3, guest PC 0x0c0644a6 */
if(!s->budget--) { s->failed_pc=0x0c0644a6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[12])!=0);
goto P_0c0644a8;
P_0c0644a8: /* original 8bea, guest PC 0x0c0644a8 */
if(!s->budget--) { s->failed_pc=0x0c0644a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c064480; }
goto P_0c0644aa;
P_0c0644aa: /* original e000, guest PC 0x0c0644aa */
if(!s->budget--) { s->failed_pc=0x0c0644aau; return 0; }
r[0]=0x00000000u;
goto P_0c0644ac;
P_0c0644ac: /* original 4f26, guest PC 0x0c0644ac */
if(!s->budget--) { s->failed_pc=0x0c0644acu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0644ae;
P_0c0644ae: /* original 69f6, guest PC 0x0c0644ae */
if(!s->budget--) { s->failed_pc=0x0c0644aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0644b0;
P_0c0644b0: /* original 6af6, guest PC 0x0c0644b0 */
if(!s->budget--) { s->failed_pc=0x0c0644b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0644b2;
P_0c0644b2: /* original 6bf6, guest PC 0x0c0644b2 */
if(!s->budget--) { s->failed_pc=0x0c0644b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0644b4;
P_0c0644b4: /* original 6cf6, guest PC 0x0c0644b4 */
if(!s->budget--) { s->failed_pc=0x0c0644b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0644b6;
P_0c0644b6: /* original 6df6, guest PC 0x0c0644b6 */
if(!s->budget--) { s->failed_pc=0x0c0644b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0644b8;
P_0c0644b8: /* original 000b, guest PC 0x0c0644b8 */
if(!s->budget--) { s->failed_pc=0x0c0644b8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0644ba: /* original 6ef6, guest PC 0x0c0644ba */
if(!s->budget--) { s->failed_pc=0x0c0644bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0644bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0644bcu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
