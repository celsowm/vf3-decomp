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
int vf3_tenpp_survey_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c081128u: goto P_0c081128;
case 0x0c08112au: goto P_0c08112a;
case 0x0c08112cu: goto P_0c08112c;
case 0x0c08112eu: goto P_0c08112e;
case 0x0c081130u: goto P_0c081130;
case 0x0c081132u: goto P_0c081132;
case 0x0c081134u: goto P_0c081134;
case 0x0c081136u: goto P_0c081136;
case 0x0c081138u: goto P_0c081138;
case 0x0c08113au: goto P_0c08113a;
case 0x0c08113cu: goto P_0c08113c;
case 0x0c08113eu: goto P_0c08113e;
case 0x0c081140u: goto P_0c081140;
case 0x0c081142u: goto P_0c081142;
case 0x0c081144u: goto P_0c081144;
case 0x0c081146u: goto P_0c081146;
case 0x0c081148u: goto P_0c081148;
case 0x0c08114au: goto P_0c08114a;
case 0x0c08114cu: goto P_0c08114c;
case 0x0c08114eu: goto P_0c08114e;
case 0x0c084f20u: goto P_0c084f20;
case 0x0c084f22u: goto P_0c084f22;
case 0x0c084f24u: goto P_0c084f24;
case 0x0c084f26u: goto P_0c084f26;
case 0x0c084f28u: goto P_0c084f28;
case 0x0c084f2au: goto P_0c084f2a;
case 0x0c084f2cu: goto P_0c084f2c;
case 0x0c084f2eu: goto P_0c084f2e;
case 0x0c084f30u: goto P_0c084f30;
case 0x0c084f32u: goto P_0c084f32;
case 0x0c084f34u: goto P_0c084f34;
case 0x0c089438u: goto P_0c089438;
case 0x0c08943au: goto P_0c08943a;
case 0x0c08943cu: goto P_0c08943c;
case 0x0c08943eu: goto P_0c08943e;
case 0x0c089440u: goto P_0c089440;
case 0x0c089442u: goto P_0c089442;
case 0x0c089444u: goto P_0c089444;
case 0x0c089446u: goto P_0c089446;
case 0x0c089448u: goto P_0c089448;
case 0x0c08944au: goto P_0c08944a;
case 0x0c08b51cu: goto P_0c08b51c;
case 0x0c08b51eu: goto P_0c08b51e;
case 0x0c08b520u: goto P_0c08b520;
case 0x0c08b522u: goto P_0c08b522;
case 0x0c08b524u: goto P_0c08b524;
case 0x0c08b526u: goto P_0c08b526;
case 0x0c08b528u: goto P_0c08b528;
case 0x0c08b52au: goto P_0c08b52a;
case 0x0c08b52cu: goto P_0c08b52c;
case 0x0c08b52eu: goto P_0c08b52e;
case 0x0c08b530u: goto P_0c08b530;
case 0x0c08b532u: goto P_0c08b532;
case 0x0c08b534u: goto P_0c08b534;
case 0x0c08b536u: goto P_0c08b536;
case 0x0c08b538u: goto P_0c08b538;
case 0x0c08b53au: goto P_0c08b53a;
case 0x0c08b53cu: goto P_0c08b53c;
case 0x0c08b53eu: goto P_0c08b53e;
case 0x0c08b540u: goto P_0c08b540;
case 0x0c08b542u: goto P_0c08b542;
case 0x0c08b620u: goto P_0c08b620;
case 0x0c08b622u: goto P_0c08b622;
case 0x0c092208u: goto P_0c092208;
case 0x0c09220au: goto P_0c09220a;
case 0x0c09220cu: goto P_0c09220c;
case 0x0c09220eu: goto P_0c09220e;
case 0x0c092210u: goto P_0c092210;
case 0x0c092212u: goto P_0c092212;
case 0x0c092214u: goto P_0c092214;
case 0x0c092216u: goto P_0c092216;
case 0x0c092218u: goto P_0c092218;
case 0x0c09221au: goto P_0c09221a;
case 0x0c09221cu: goto P_0c09221c;
case 0x0c09221eu: goto P_0c09221e;
case 0x0c092220u: goto P_0c092220;
case 0x0c092222u: goto P_0c092222;
case 0x0c092224u: goto P_0c092224;
case 0x0c092226u: goto P_0c092226;
case 0x0c092228u: goto P_0c092228;
case 0x0c09222au: goto P_0c09222a;
case 0x0c09222cu: goto P_0c09222c;
case 0x0c09222eu: goto P_0c09222e;
case 0x0c092230u: goto P_0c092230;
case 0x0c092232u: goto P_0c092232;
case 0x0c092234u: goto P_0c092234;
case 0x0c092236u: goto P_0c092236;
case 0x0c092238u: goto P_0c092238;
case 0x0c09223au: goto P_0c09223a;
case 0x0c09223cu: goto P_0c09223c;
case 0x0c09223eu: goto P_0c09223e;
case 0x0c092240u: goto P_0c092240;
case 0x0c092242u: goto P_0c092242;
case 0x0c092244u: goto P_0c092244;
case 0x0c092246u: goto P_0c092246;
case 0x0c092248u: goto P_0c092248;
case 0x0c09224au: goto P_0c09224a;
case 0x0c09224cu: goto P_0c09224c;
case 0x0c09224eu: goto P_0c09224e;
case 0x0c092250u: goto P_0c092250;
case 0x0c092252u: goto P_0c092252;
case 0x0c092254u: goto P_0c092254;
case 0x0c092256u: goto P_0c092256;
case 0x0c092258u: goto P_0c092258;
case 0x0c09225au: goto P_0c09225a;
case 0x0c09225cu: goto P_0c09225c;
case 0x0c09225eu: goto P_0c09225e;
case 0x0c092260u: goto P_0c092260;
case 0x0c092262u: goto P_0c092262;
case 0x0c092264u: goto P_0c092264;
case 0x0c092266u: goto P_0c092266;
case 0x0c094558u: goto P_0c094558;
case 0x0c09455au: goto P_0c09455a;
case 0x0c096174u: goto P_0c096174;
case 0x0c096176u: goto P_0c096176;
case 0x0c096178u: goto P_0c096178;
case 0x0c09617au: goto P_0c09617a;
case 0x0c09617cu: goto P_0c09617c;
case 0x0c09617eu: goto P_0c09617e;
case 0x0c096180u: goto P_0c096180;
case 0x0c096182u: goto P_0c096182;
case 0x0c096184u: goto P_0c096184;
case 0x0c096186u: goto P_0c096186;
case 0x0c096188u: goto P_0c096188;
case 0x0c09618au: goto P_0c09618a;
case 0x0c09618cu: goto P_0c09618c;
case 0x0c09618eu: goto P_0c09618e;
case 0x0c096190u: goto P_0c096190;
case 0x0c096192u: goto P_0c096192;
case 0x0c096194u: goto P_0c096194;
case 0x0c096196u: goto P_0c096196;
case 0x0c096198u: goto P_0c096198;
case 0x0c09619au: goto P_0c09619a;
case 0x0c09619cu: goto P_0c09619c;
case 0x0c09619eu: goto P_0c09619e;
case 0x0c0961a0u: goto P_0c0961a0;
case 0x0c0961a2u: goto P_0c0961a2;
case 0x0c096718u: goto P_0c096718;
case 0x0c09671au: goto P_0c09671a;
case 0x0c09671cu: goto P_0c09671c;
case 0x0c09671eu: goto P_0c09671e;
case 0x0c096720u: goto P_0c096720;
case 0x0c096722u: goto P_0c096722;
case 0x0c096724u: goto P_0c096724;
case 0x0c096726u: goto P_0c096726;
case 0x0c096728u: goto P_0c096728;
case 0x0c09672au: goto P_0c09672a;
case 0x0c09672cu: goto P_0c09672c;
case 0x0c09672eu: goto P_0c09672e;
case 0x0c096730u: goto P_0c096730;
case 0x0c096732u: goto P_0c096732;
case 0x0c096734u: goto P_0c096734;
case 0x0c096736u: goto P_0c096736;
case 0x0c096738u: goto P_0c096738;
case 0x0c09673au: goto P_0c09673a;
case 0x0c09673cu: goto P_0c09673c;
case 0x0c09673eu: goto P_0c09673e;
case 0x0c096740u: goto P_0c096740;
case 0x0c096742u: goto P_0c096742;
case 0x0c096744u: goto P_0c096744;
case 0x0c096746u: goto P_0c096746;
case 0x0c0967e8u: goto P_0c0967e8;
case 0x0c0967eau: goto P_0c0967ea;
case 0x0c0967ecu: goto P_0c0967ec;
case 0x0c0967eeu: goto P_0c0967ee;
case 0x0c0967f0u: goto P_0c0967f0;
case 0x0c0967f2u: goto P_0c0967f2;
case 0x0c0967f4u: goto P_0c0967f4;
case 0x0c0967f6u: goto P_0c0967f6;
case 0x0c0967f8u: goto P_0c0967f8;
case 0x0c0967fau: goto P_0c0967fa;
case 0x0c0967fcu: goto P_0c0967fc;
case 0x0c0967feu: goto P_0c0967fe;
case 0x0c096800u: goto P_0c096800;
case 0x0c096802u: goto P_0c096802;
case 0x0c096804u: goto P_0c096804;
case 0x0c096806u: goto P_0c096806;
case 0x0c096808u: goto P_0c096808;
case 0x0c09680au: goto P_0c09680a;
case 0x0c09680cu: goto P_0c09680c;
case 0x0c09680eu: goto P_0c09680e;
case 0x0c096810u: goto P_0c096810;
case 0x0c096812u: goto P_0c096812;
case 0x0c096814u: goto P_0c096814;
case 0x0c0a2774u: goto P_0c0a2774;
case 0x0c0a2776u: goto P_0c0a2776;
case 0x0c0a2778u: goto P_0c0a2778;
case 0x0c0a277au: goto P_0c0a277a;
case 0x0c0a277cu: goto P_0c0a277c;
case 0x0c0a277eu: goto P_0c0a277e;
case 0x0c0a2780u: goto P_0c0a2780;
case 0x0c0a2782u: goto P_0c0a2782;
case 0x0c0a2784u: goto P_0c0a2784;
case 0x0c0a2786u: goto P_0c0a2786;
case 0x0c0a2788u: goto P_0c0a2788;
case 0x0c0a278au: goto P_0c0a278a;
case 0x0c0a278cu: goto P_0c0a278c;
case 0x0c0a278eu: goto P_0c0a278e;
case 0x0c0a2790u: goto P_0c0a2790;
case 0x0c0a2792u: goto P_0c0a2792;
case 0x0c0a2794u: goto P_0c0a2794;
case 0x0c0a2796u: goto P_0c0a2796;
case 0x0c0a2798u: goto P_0c0a2798;
case 0x0c0a279au: goto P_0c0a279a;
case 0x0c0a279cu: goto P_0c0a279c;
case 0x0c0a279eu: goto P_0c0a279e;
case 0x0c0a27a0u: goto P_0c0a27a0;
case 0x0c0a27a2u: goto P_0c0a27a2;
case 0x0c0a27a4u: goto P_0c0a27a4;
case 0x0c0a27a6u: goto P_0c0a27a6;
case 0x0c0a27a8u: goto P_0c0a27a8;
case 0x0c0a27aau: goto P_0c0a27aa;
case 0x0c0a27acu: goto P_0c0a27ac;
case 0x0c0a27aeu: goto P_0c0a27ae;
case 0x0c0a27b0u: goto P_0c0a27b0;
case 0x0c0a27b2u: goto P_0c0a27b2;
case 0x0c0a27b4u: goto P_0c0a27b4;
case 0x0c0a27b6u: goto P_0c0a27b6;
case 0x0c0a27b8u: goto P_0c0a27b8;
case 0x0c0a27bau: goto P_0c0a27ba;
case 0x0c0a27bcu: goto P_0c0a27bc;
case 0x0c0a27beu: goto P_0c0a27be;
case 0x0c0a27c0u: goto P_0c0a27c0;
case 0x0c0a27c2u: goto P_0c0a27c2;
case 0x0c0a27c4u: goto P_0c0a27c4;
case 0x0c0a27c6u: goto P_0c0a27c6;
case 0x0c0a27c8u: goto P_0c0a27c8;
case 0x0c0a27cau: goto P_0c0a27ca;
case 0x0c0a27ccu: goto P_0c0a27cc;
case 0x0c0a27ceu: goto P_0c0a27ce;
case 0x0c0a27d0u: goto P_0c0a27d0;
case 0x0c0a27d2u: goto P_0c0a27d2;
case 0x0c0a27d4u: goto P_0c0a27d4;
case 0x0c0a27d6u: goto P_0c0a27d6;
case 0x0c0a27d8u: goto P_0c0a27d8;
case 0x0c0a27dau: goto P_0c0a27da;
case 0x0c0a27dcu: goto P_0c0a27dc;
case 0x0c0a27deu: goto P_0c0a27de;
case 0x0c0a27e0u: goto P_0c0a27e0;
case 0x0c0a27e2u: goto P_0c0a27e2;
case 0x0c0a27e4u: goto P_0c0a27e4;
case 0x0c0a27e6u: goto P_0c0a27e6;
case 0x0c0a27e8u: goto P_0c0a27e8;
case 0x0c0a27eau: goto P_0c0a27ea;
case 0x0c0a27ecu: goto P_0c0a27ec;
case 0x0c0a7302u: goto P_0c0a7302;
case 0x0c0a7304u: goto P_0c0a7304;
case 0x0c0a7306u: goto P_0c0a7306;
case 0x0c0a7308u: goto P_0c0a7308;
case 0x0c0a730au: goto P_0c0a730a;
case 0x0c0a730cu: goto P_0c0a730c;
case 0x0c0a730eu: goto P_0c0a730e;
case 0x0c0a7310u: goto P_0c0a7310;
case 0x0c0a7312u: goto P_0c0a7312;
case 0x0c0a7314u: goto P_0c0a7314;
case 0x0c0a7316u: goto P_0c0a7316;
case 0x0c0a7318u: goto P_0c0a7318;
case 0x0c0a731au: goto P_0c0a731a;
case 0x0c0a731cu: goto P_0c0a731c;
case 0x0c0a731eu: goto P_0c0a731e;
case 0x0c0a7320u: goto P_0c0a7320;
case 0x0c0a7322u: goto P_0c0a7322;
case 0x0c0a7324u: goto P_0c0a7324;
case 0x0c0a7326u: goto P_0c0a7326;
case 0x0c0a7328u: goto P_0c0a7328;
case 0x0c0a732au: goto P_0c0a732a;
case 0x0c0a732cu: goto P_0c0a732c;
case 0x0c0a732eu: goto P_0c0a732e;
case 0x0c0a7330u: goto P_0c0a7330;
case 0x0c0a7332u: goto P_0c0a7332;
case 0x0c0a7334u: goto P_0c0a7334;
case 0x0c0a7336u: goto P_0c0a7336;
case 0x0c0a7338u: goto P_0c0a7338;
case 0x0c0a733au: goto P_0c0a733a;
case 0x0c0a733cu: goto P_0c0a733c;
case 0x0c0a733eu: goto P_0c0a733e;
case 0x0c0a7340u: goto P_0c0a7340;
case 0x0c0a7342u: goto P_0c0a7342;
case 0x0c0a7344u: goto P_0c0a7344;
case 0x0c0a7346u: goto P_0c0a7346;
case 0x0c0a7348u: goto P_0c0a7348;
case 0x0c0a734au: goto P_0c0a734a;
case 0x0c0a734cu: goto P_0c0a734c;
case 0x0c0a734eu: goto P_0c0a734e;
case 0x0c0a7350u: goto P_0c0a7350;
case 0x0c0a7352u: goto P_0c0a7352;
case 0x0c0a7354u: goto P_0c0a7354;
case 0x0c0a7356u: goto P_0c0a7356;
case 0x0c0a7358u: goto P_0c0a7358;
case 0x0c0a735au: goto P_0c0a735a;
case 0x0c0a735cu: goto P_0c0a735c;
case 0x0c0a735eu: goto P_0c0a735e;
case 0x0c0a7360u: goto P_0c0a7360;
case 0x0c0a7362u: goto P_0c0a7362;
case 0x0c0a7364u: goto P_0c0a7364;
case 0x0c0a7366u: goto P_0c0a7366;
case 0x0c0a7368u: goto P_0c0a7368;
case 0x0c0a736au: goto P_0c0a736a;
case 0x0c0a736cu: goto P_0c0a736c;
case 0x0c0a736eu: goto P_0c0a736e;
case 0x0c0a7370u: goto P_0c0a7370;
case 0x0c0a7372u: goto P_0c0a7372;
case 0x0c0a7374u: goto P_0c0a7374;
case 0x0c0a7376u: goto P_0c0a7376;
case 0x0c0a7378u: goto P_0c0a7378;
case 0x0c0a737au: goto P_0c0a737a;
case 0x0c0a737cu: goto P_0c0a737c;
case 0x0c0a737eu: goto P_0c0a737e;
case 0x0c0a7380u: goto P_0c0a7380;
case 0x0c0a7382u: goto P_0c0a7382;
case 0x0c0a7384u: goto P_0c0a7384;
case 0x0c0a7386u: goto P_0c0a7386;
case 0x0c0a7388u: goto P_0c0a7388;
case 0x0c0a738au: goto P_0c0a738a;
case 0x0c0a738cu: goto P_0c0a738c;
case 0x0c0a803cu: goto P_0c0a803c;
case 0x0c0a803eu: goto P_0c0a803e;
case 0x0c0a8040u: goto P_0c0a8040;
case 0x0c0a8042u: goto P_0c0a8042;
case 0x0c0a8044u: goto P_0c0a8044;
case 0x0c0a8046u: goto P_0c0a8046;
case 0x0c0a8048u: goto P_0c0a8048;
case 0x0c0a804au: goto P_0c0a804a;
case 0x0c0a804cu: goto P_0c0a804c;
case 0x0c0a804eu: goto P_0c0a804e;
case 0x0c0a8050u: goto P_0c0a8050;
case 0x0c0a8052u: goto P_0c0a8052;
case 0x0c0a8054u: goto P_0c0a8054;
case 0x0c0a8056u: goto P_0c0a8056;
case 0x0c0a8058u: goto P_0c0a8058;
case 0x0c0a805au: goto P_0c0a805a;
case 0x0c0a805cu: goto P_0c0a805c;
case 0x0c0a805eu: goto P_0c0a805e;
case 0x0c0a8060u: goto P_0c0a8060;
case 0x0c0a8062u: goto P_0c0a8062;
case 0x0c0a8064u: goto P_0c0a8064;
case 0x0c0a8066u: goto P_0c0a8066;
case 0x0c0a8068u: goto P_0c0a8068;
case 0x0c0a806au: goto P_0c0a806a;
case 0x0c0a806cu: goto P_0c0a806c;
case 0x0c0a806eu: goto P_0c0a806e;
case 0x0c0a8070u: goto P_0c0a8070;
case 0x0c0a8072u: goto P_0c0a8072;
case 0x0c0a8074u: goto P_0c0a8074;
case 0x0c0a8076u: goto P_0c0a8076;
case 0x0c0a8078u: goto P_0c0a8078;
case 0x0c0a807au: goto P_0c0a807a;
case 0x0c0a807cu: goto P_0c0a807c;
case 0x0c0a807eu: goto P_0c0a807e;
case 0x0c0a8080u: goto P_0c0a8080;
case 0x0c0a8082u: goto P_0c0a8082;
case 0x0c0a8084u: goto P_0c0a8084;
case 0x0c0a8086u: goto P_0c0a8086;
case 0x0c0a8088u: goto P_0c0a8088;
case 0x0c0a808au: goto P_0c0a808a;
case 0x0c0afef4u: goto P_0c0afef4;
case 0x0c0afef6u: goto P_0c0afef6;
case 0x0c0afef8u: goto P_0c0afef8;
case 0x0c0afefau: goto P_0c0afefa;
case 0x0c0afefcu: goto P_0c0afefc;
case 0x0c0afefeu: goto P_0c0afefe;
case 0x0c0aff00u: goto P_0c0aff00;
case 0x0c0aff02u: goto P_0c0aff02;
case 0x0c0c26dcu: goto P_0c0c26dc;
case 0x0c0c26deu: goto P_0c0c26de;
case 0x0c0c26e0u: goto P_0c0c26e0;
case 0x0c0c26e2u: goto P_0c0c26e2;
case 0x0c0c26e4u: goto P_0c0c26e4;
case 0x0c0c26e6u: goto P_0c0c26e6;
case 0x0c0c26e8u: goto P_0c0c26e8;
case 0x0c0c26eau: goto P_0c0c26ea;
case 0x0c0c26ecu: goto P_0c0c26ec;
case 0x0c0c26eeu: goto P_0c0c26ee;
case 0x0c0c26f0u: goto P_0c0c26f0;
case 0x0c0c26f2u: goto P_0c0c26f2;
case 0x0c0c26f4u: goto P_0c0c26f4;
case 0x0c0c26f6u: goto P_0c0c26f6;
case 0x0c0c26f8u: goto P_0c0c26f8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c081128: /* original 9513, guest PC 0x0c081128 */
if(!s->budget--) { s->failed_pc=0x0c081128u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081152u,2);
goto P_0c08112a;
P_0c08112a: /* original e6ff, guest PC 0x0c08112a */
if(!s->budget--) { s->failed_pc=0x0c08112au; return 0; }
r[6]=0xffffffffu;
goto P_0c08112c;
P_0c08112c: /* original 354c, guest PC 0x0c08112c */
if(!s->budget--) { s->failed_pc=0x0c08112cu; return 0; }
r[5]+=r[4];
goto P_0c08112e;
P_0c08112e: /* original 2562, guest PC 0x0c08112e */
if(!s->budget--) { s->failed_pc=0x0c08112eu; return 0; }
write(ram,r[5],r[6],4);
goto P_0c081130;
P_0c081130: /* original 1561, guest PC 0x0c081130 */
if(!s->budget--) { s->failed_pc=0x0c081130u; return 0; }
write(ram,r[5]+4,r[6],4);
goto P_0c081132;
P_0c081132: /* original 1562, guest PC 0x0c081132 */
if(!s->budget--) { s->failed_pc=0x0c081132u; return 0; }
write(ram,r[5]+8,r[6],4);
goto P_0c081134;
P_0c081134: /* original 1563, guest PC 0x0c081134 */
if(!s->budget--) { s->failed_pc=0x0c081134u; return 0; }
write(ram,r[5]+12,r[6],4);
goto P_0c081136;
P_0c081136: /* original e500, guest PC 0x0c081136 */
if(!s->budget--) { s->failed_pc=0x0c081136u; return 0; }
r[5]=0x00000000u;
goto P_0c081138;
P_0c081138: /* original 900c, guest PC 0x0c081138 */
if(!s->budget--) { s->failed_pc=0x0c081138u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081154u,2);
goto P_0c08113a;
P_0c08113a: /* original 0454, guest PC 0x0c08113a */
if(!s->budget--) { s->failed_pc=0x0c08113au; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c08113c;
P_0c08113c: /* original 900b, guest PC 0x0c08113c */
if(!s->budget--) { s->failed_pc=0x0c08113cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081156u,2);
goto P_0c08113e;
P_0c08113e: /* original 0454, guest PC 0x0c08113e */
if(!s->budget--) { s->failed_pc=0x0c08113eu; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c081140;
P_0c081140: /* original 900a, guest PC 0x0c081140 */
if(!s->budget--) { s->failed_pc=0x0c081140u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081158u,2);
goto P_0c081142;
P_0c081142: /* original 0454, guest PC 0x0c081142 */
if(!s->budget--) { s->failed_pc=0x0c081142u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c081144;
P_0c081144: /* original 9009, guest PC 0x0c081144 */
if(!s->budget--) { s->failed_pc=0x0c081144u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08115au,2);
goto P_0c081146;
P_0c081146: /* original 0454, guest PC 0x0c081146 */
if(!s->budget--) { s->failed_pc=0x0c081146u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c081148;
P_0c081148: /* original 9008, guest PC 0x0c081148 */
if(!s->budget--) { s->failed_pc=0x0c081148u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08115cu,2);
goto P_0c08114a;
P_0c08114a: /* original d30d, guest PC 0x0c08114a */
if(!s->budget--) { s->failed_pc=0x0c08114au; return 0; }
r[3]=read(ram,0x0c081180u,4);
goto P_0c08114c;
P_0c08114c: /* original 000b, guest PC 0x0c08114c */
if(!s->budget--) { s->failed_pc=0x0c08114cu; return 0; }
target=r[16];
write(ram,r[4]+r[0],r[3],4);
s->pc=target; return ram->oob==0;
P_0c08114e: /* original 0436, guest PC 0x0c08114e */
if(!s->budget--) { s->failed_pc=0x0c08114eu; return 0; }
write(ram,r[4]+r[0],r[3],4);
return vf3_matrix_family(0x0c081150u,s,ram);
P_0c084f20: /* original 9067, guest PC 0x0c084f20 */
if(!s->budget--) { s->failed_pc=0x0c084f20u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084ff2u,2);
goto P_0c084f22;
P_0c084f22: /* original e400, guest PC 0x0c084f22 */
if(!s->budget--) { s->failed_pc=0x0c084f22u; return 0; }
r[4]=0x00000000u;
goto P_0c084f24;
P_0c084f24: /* original d534, guest PC 0x0c084f24 */
if(!s->budget--) { s->failed_pc=0x0c084f24u; return 0; }
r[5]=read(ram,0x0c084ff8u,4);
goto P_0c084f26;
P_0c084f26: /* original 0544, guest PC 0x0c084f26 */
if(!s->budget--) { s->failed_pc=0x0c084f26u; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c084f28;
P_0c084f28: /* original 7001, guest PC 0x0c084f28 */
if(!s->budget--) { s->failed_pc=0x0c084f28u; return 0; }
r[0]+=0x00000001u;
goto P_0c084f2a;
P_0c084f2a: /* original 0544, guest PC 0x0c084f2a */
if(!s->budget--) { s->failed_pc=0x0c084f2au; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c084f2c;
P_0c084f2c: /* original 7001, guest PC 0x0c084f2c */
if(!s->budget--) { s->failed_pc=0x0c084f2cu; return 0; }
r[0]+=0x00000001u;
goto P_0c084f2e;
P_0c084f2e: /* original 0544, guest PC 0x0c084f2e */
if(!s->budget--) { s->failed_pc=0x0c084f2eu; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c084f30;
P_0c084f30: /* original 7001, guest PC 0x0c084f30 */
if(!s->budget--) { s->failed_pc=0x0c084f30u; return 0; }
r[0]+=0x00000001u;
goto P_0c084f32;
P_0c084f32: /* original 000b, guest PC 0x0c084f32 */
if(!s->budget--) { s->failed_pc=0x0c084f32u; return 0; }
target=r[16];
write(ram,r[5]+r[0],r[4],1);
s->pc=target; return ram->oob==0;
P_0c084f34: /* original 0544, guest PC 0x0c084f34 */
if(!s->budget--) { s->failed_pc=0x0c084f34u; return 0; }
write(ram,r[5]+r[0],r[4],1);
return vf3_matrix_family(0x0c084f36u,s,ram);
P_0c089438: /* original e301, guest PC 0x0c089438 */
if(!s->budget--) { s->failed_pc=0x0c089438u; return 0; }
r[3]=0x00000001u;
goto P_0c08943a;
P_0c08943a: /* original 2432, guest PC 0x0c08943a */
if(!s->budget--) { s->failed_pc=0x0c08943au; return 0; }
write(ram,r[4],r[3],4);
goto P_0c08943c;
P_0c08943c: /* original e010, guest PC 0x0c08943c */
if(!s->budget--) { s->failed_pc=0x0c08943cu; return 0; }
r[0]=0x00000010u;
goto P_0c08943e;
P_0c08943e: /* original e500, guest PC 0x0c08943e */
if(!s->budget--) { s->failed_pc=0x0c08943eu; return 0; }
r[5]=0x00000000u;
goto P_0c089440;
P_0c089440: /* original 0454, guest PC 0x0c089440 */
if(!s->budget--) { s->failed_pc=0x0c089440u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c089442;
P_0c089442: /* original 6053, guest PC 0x0c089442 */
if(!s->budget--) { s->failed_pc=0x0c089442u; return 0; }
r[0]=r[5];
goto P_0c089444;
P_0c089444: /* original d325, guest PC 0x0c089444 */
if(!s->budget--) { s->failed_pc=0x0c089444u; return 0; }
r[3]=read(ram,0x0c0894dcu,4);
goto P_0c089446;
P_0c089446: /* original 1433, guest PC 0x0c089446 */
if(!s->budget--) { s->failed_pc=0x0c089446u; return 0; }
write(ram,r[4]+12,r[3],4);
goto P_0c089448;
P_0c089448: /* original 000b, guest PC 0x0c089448 */
if(!s->budget--) { s->failed_pc=0x0c089448u; return 0; }
target=r[16];
write(ram,r[4]+24,r[0],2);
s->pc=target; return ram->oob==0;
P_0c08944a: /* original 814c, guest PC 0x0c08944a */
if(!s->budget--) { s->failed_pc=0x0c08944au; return 0; }
write(ram,r[4]+24,r[0],2);
return vf3_matrix_family(0x0c08944cu,s,ram);
P_0c08b51c: /* original 2fe6, guest PC 0x0c08b51c */
if(!s->budget--) { s->failed_pc=0x0c08b51cu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c08b51e;
P_0c08b51e: /* original e010, guest PC 0x0c08b51e */
if(!s->budget--) { s->failed_pc=0x0c08b51eu; return 0; }
r[0]=0x00000010u;
goto P_0c08b520;
P_0c08b520: /* original 2fd6, guest PC 0x0c08b520 */
if(!s->budget--) { s->failed_pc=0x0c08b520u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c08b522;
P_0c08b522: /* original e2ff, guest PC 0x0c08b522 */
if(!s->budget--) { s->failed_pc=0x0c08b522u; return 0; }
r[2]=0xffffffffu;
goto P_0c08b524;
P_0c08b524: /* original d342, guest PC 0x0c08b524 */
if(!s->budget--) { s->failed_pc=0x0c08b524u; return 0; }
r[3]=read(ram,0x0c08b630u,4);
goto P_0c08b526;
P_0c08b526: /* original ee17, guest PC 0x0c08b526 */
if(!s->budget--) { s->failed_pc=0x0c08b526u; return 0; }
r[14]=0x00000017u;
goto P_0c08b528;
P_0c08b528: /* original 4f22, guest PC 0x0c08b528 */
if(!s->budget--) { s->failed_pc=0x0c08b528u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08b52a;
P_0c08b52a: /* original 1433, guest PC 0x0c08b52a */
if(!s->budget--) { s->failed_pc=0x0c08b52au; return 0; }
write(ram,r[4]+12,r[3],4);
goto P_0c08b52c;
P_0c08b52c: /* original 0424, guest PC 0x0c08b52c */
if(!s->budget--) { s->failed_pc=0x0c08b52cu; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c08b52e;
P_0c08b52e: /* original dd41, guest PC 0x0c08b52e */
if(!s->budget--) { s->failed_pc=0x0c08b52eu; return 0; }
r[13]=read(ram,0x0c08b634u,4);
goto P_0c08b530;
P_0c08b530: /* original 63d2, guest PC 0x0c08b530 */
if(!s->budget--) { s->failed_pc=0x0c08b530u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c08b532;
P_0c08b532: /* original 430b, guest PC 0x0c08b532 */
if(!s->budget--) { s->failed_pc=0x0c08b532u; return 0; }
target=r[3];
r[16]=0x0c08b536u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08b536u) { target=s->pc; goto dispatch; }
goto P_0c08b536;
P_0c08b534: /* original 0009, guest PC 0x0c08b534 */
if(!s->budget--) { s->failed_pc=0x0c08b534u; return 0; }
goto P_0c08b536;
P_0c08b536: /* original 4e10, guest PC 0x0c08b536 */
if(!s->budget--) { s->failed_pc=0x0c08b536u; return 0; }
--r[14];
r[17]=(r[17]&~1u)|((r[14]==0)!=0);
goto P_0c08b538;
P_0c08b538: /* original 8ffa, guest PC 0x0c08b538 */
if(!s->budget--) { s->failed_pc=0x0c08b538u; return 0; }
cond=r[17]&1u;
r[13]+=0x0000001cu;
if(!cond) { goto P_0c08b530; }
goto P_0c08b53c;
P_0c08b53a: /* original 7d1c, guest PC 0x0c08b53a */
if(!s->budget--) { s->failed_pc=0x0c08b53au; return 0; }
r[13]+=0x0000001cu;
goto P_0c08b53c;
P_0c08b53c: /* original 4f26, guest PC 0x0c08b53c */
if(!s->budget--) { s->failed_pc=0x0c08b53cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08b53e;
P_0c08b53e: /* original 6df6, guest PC 0x0c08b53e */
if(!s->budget--) { s->failed_pc=0x0c08b53eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08b540;
P_0c08b540: /* original 000b, guest PC 0x0c08b540 */
if(!s->budget--) { s->failed_pc=0x0c08b540u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08b542: /* original 6ef6, guest PC 0x0c08b542 */
if(!s->budget--) { s->failed_pc=0x0c08b542u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08b544u,s,ram);
P_0c08b620: /* original 000b, guest PC 0x0c08b620 */
if(!s->budget--) { s->failed_pc=0x0c08b620u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c08b622: /* original 0009, guest PC 0x0c08b622 */
if(!s->budget--) { s->failed_pc=0x0c08b622u; return 0; }
return vf3_matrix_family(0x0c08b624u,s,ram);
P_0c092208: /* original 2fe6, guest PC 0x0c092208 */
if(!s->budget--) { s->failed_pc=0x0c092208u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c09220a;
P_0c09220a: /* original 6e43, guest PC 0x0c09220a */
if(!s->budget--) { s->failed_pc=0x0c09220au; return 0; }
r[14]=r[4];
goto P_0c09220c;
P_0c09220c: /* original e02e, guest PC 0x0c09220c */
if(!s->budget--) { s->failed_pc=0x0c09220cu; return 0; }
r[0]=0x0000002eu;
goto P_0c09220e;
P_0c09220e: /* original e401, guest PC 0x0c09220e */
if(!s->budget--) { s->failed_pc=0x0c09220eu; return 0; }
r[4]=0x00000001u;
goto P_0c092210;
P_0c092210: /* original 4f22, guest PC 0x0c092210 */
if(!s->budget--) { s->failed_pc=0x0c092210u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c092212;
P_0c092212: /* original 1e45, guest PC 0x0c092212 */
if(!s->budget--) { s->failed_pc=0x0c092212u; return 0; }
write(ram,r[14]+20,r[4],4);
goto P_0c092214;
P_0c092214: /* original 0e45, guest PC 0x0c092214 */
if(!s->budget--) { s->failed_pc=0x0c092214u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c092216;
P_0c092216: /* original e02c, guest PC 0x0c092216 */
if(!s->budget--) { s->failed_pc=0x0c092216u; return 0; }
r[0]=0x0000002cu;
goto P_0c092218;
P_0c092218: /* original 0e45, guest PC 0x0c092218 */
if(!s->budget--) { s->failed_pc=0x0c092218u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c09221a;
P_0c09221a: /* original b009, guest PC 0x0c09221a */
if(!s->budget--) { s->failed_pc=0x0c09221au; return 0; }
target=0x0c092230u; r[16]=0x0c09221eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09221eu) { target=s->pc; goto dispatch; }
goto P_0c09221e;
P_0c09221c: /* original 64e3, guest PC 0x0c09221c */
if(!s->budget--) { s->failed_pc=0x0c09221cu; return 0; }
r[4]=r[14];
goto P_0c09221e;
P_0c09221e: /* original 62e2, guest PC 0x0c09221e */
if(!s->budget--) { s->failed_pc=0x0c09221eu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c092220;
P_0c092220: /* original e3fe, guest PC 0x0c092220 */
if(!s->budget--) { s->failed_pc=0x0c092220u; return 0; }
r[3]=0xfffffffeu;
goto P_0c092222;
P_0c092222: /* original 4f26, guest PC 0x0c092222 */
if(!s->budget--) { s->failed_pc=0x0c092222u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c092224;
P_0c092224: /* original 2239, guest PC 0x0c092224 */
if(!s->budget--) { s->failed_pc=0x0c092224u; return 0; }
r[2]&=r[3];
goto P_0c092226;
P_0c092226: /* original 2e22, guest PC 0x0c092226 */
if(!s->budget--) { s->failed_pc=0x0c092226u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c092228;
P_0c092228: /* original d131, guest PC 0x0c092228 */
if(!s->budget--) { s->failed_pc=0x0c092228u; return 0; }
r[1]=read(ram,0x0c0922f0u,4);
goto P_0c09222a;
P_0c09222a: /* original 1e13, guest PC 0x0c09222a */
if(!s->budget--) { s->failed_pc=0x0c09222au; return 0; }
write(ram,r[14]+12,r[1],4);
goto P_0c09222c;
P_0c09222c: /* original 000b, guest PC 0x0c09222c */
if(!s->budget--) { s->failed_pc=0x0c09222cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09222e: /* original 6ef6, guest PC 0x0c09222e */
if(!s->budget--) { s->failed_pc=0x0c09222eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c092230;
P_0c092230: /* original 955b, guest PC 0x0c092230 */
if(!s->budget--) { s->failed_pc=0x0c092230u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0922eau,2);
goto P_0c092232;
P_0c092232: /* original e608, guest PC 0x0c092232 */
if(!s->budget--) { s->failed_pc=0x0c092232u; return 0; }
r[6]=0x00000008u;
goto P_0c092234;
P_0c092234: /* original d72f, guest PC 0x0c092234 */
if(!s->budget--) { s->failed_pc=0x0c092234u; return 0; }
r[7]=read(ram,0x0c0922f4u,4);
goto P_0c092236;
P_0c092236: /* original 354c, guest PC 0x0c092236 */
if(!s->budget--) { s->failed_pc=0x0c092236u; return 0; }
r[5]+=r[4];
goto P_0c092238;
P_0c092238: /* original f48d, guest PC 0x0c092238 */
if(!s->budget--) { s->failed_pc=0x0c092238u; return 0; }
fr[4]=0;
goto P_0c09223a;
P_0c09223a: /* original e400, guest PC 0x0c09223a */
if(!s->budget--) { s->failed_pc=0x0c09223au; return 0; }
r[4]=0x00000000u;
goto P_0c09223c;
P_0c09223c: /* original e004, guest PC 0x0c09223c */
if(!s->budget--) { s->failed_pc=0x0c09223cu; return 0; }
r[0]=0x00000004u;
goto P_0c09223e;
P_0c09223e: /* original 6375, guest PC 0x0c09223e */
if(!s->budget--) { s->failed_pc=0x0c09223eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[7]+=2;
r[3]=tmp;
goto P_0c092240;
P_0c092240: /* original 7401, guest PC 0x0c092240 */
if(!s->budget--) { s->failed_pc=0x0c092240u; return 0; }
r[4]+=0x00000001u;
goto P_0c092242;
P_0c092242: /* original 3463, guest PC 0x0c092242 */
if(!s->budget--) { s->failed_pc=0x0c092242u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c092244;
P_0c092244: /* original 2531, guest PC 0x0c092244 */
if(!s->budget--) { s->failed_pc=0x0c092244u; return 0; }
write(ram,r[5],r[3],2);
goto P_0c092246;
P_0c092246: /* original f547, guest PC 0x0c092246 */
if(!s->budget--) { s->failed_pc=0x0c092246u; return 0; }
vf3_matrix_store(s,ram,4,r[5]+r[0]);
goto P_0c092248;
P_0c092248: /* original e008, guest PC 0x0c092248 */
if(!s->budget--) { s->failed_pc=0x0c092248u; return 0; }
r[0]=0x00000008u;
goto P_0c09224a;
P_0c09224a: /* original f547, guest PC 0x0c09224a */
if(!s->budget--) { s->failed_pc=0x0c09224au; return 0; }
vf3_matrix_store(s,ram,4,r[5]+r[0]);
goto P_0c09224c;
P_0c09224c: /* original e00c, guest PC 0x0c09224c */
if(!s->budget--) { s->failed_pc=0x0c09224cu; return 0; }
r[0]=0x0000000cu;
goto P_0c09224e;
P_0c09224e: /* original f547, guest PC 0x0c09224e */
if(!s->budget--) { s->failed_pc=0x0c09224eu; return 0; }
vf3_matrix_store(s,ram,4,r[5]+r[0]);
goto P_0c092250;
P_0c092250: /* original e010, guest PC 0x0c092250 */
if(!s->budget--) { s->failed_pc=0x0c092250u; return 0; }
r[0]=0x00000010u;
goto P_0c092252;
P_0c092252: /* original f547, guest PC 0x0c092252 */
if(!s->budget--) { s->failed_pc=0x0c092252u; return 0; }
vf3_matrix_store(s,ram,4,r[5]+r[0]);
goto P_0c092254;
P_0c092254: /* original e014, guest PC 0x0c092254 */
if(!s->budget--) { s->failed_pc=0x0c092254u; return 0; }
r[0]=0x00000014u;
goto P_0c092256;
P_0c092256: /* original f547, guest PC 0x0c092256 */
if(!s->budget--) { s->failed_pc=0x0c092256u; return 0; }
vf3_matrix_store(s,ram,4,r[5]+r[0]);
goto P_0c092258;
P_0c092258: /* original e018, guest PC 0x0c092258 */
if(!s->budget--) { s->failed_pc=0x0c092258u; return 0; }
r[0]=0x00000018u;
goto P_0c09225a;
P_0c09225a: /* original f547, guest PC 0x0c09225a */
if(!s->budget--) { s->failed_pc=0x0c09225au; return 0; }
vf3_matrix_store(s,ram,4,r[5]+r[0]);
goto P_0c09225c;
P_0c09225c: /* original e01c, guest PC 0x0c09225c */
if(!s->budget--) { s->failed_pc=0x0c09225cu; return 0; }
r[0]=0x0000001cu;
goto P_0c09225e;
P_0c09225e: /* original f547, guest PC 0x0c09225e */
if(!s->budget--) { s->failed_pc=0x0c09225eu; return 0; }
vf3_matrix_store(s,ram,4,r[5]+r[0]);
goto P_0c092260;
P_0c092260: /* original 8fec, guest PC 0x0c092260 */
if(!s->budget--) { s->failed_pc=0x0c092260u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000024u;
if(!cond) { goto P_0c09223c; }
goto P_0c092264;
P_0c092262: /* original 7524, guest PC 0x0c092262 */
if(!s->budget--) { s->failed_pc=0x0c092262u; return 0; }
r[5]+=0x00000024u;
goto P_0c092264;
P_0c092264: /* original 000b, guest PC 0x0c092264 */
if(!s->budget--) { s->failed_pc=0x0c092264u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c092266: /* original 0009, guest PC 0x0c092266 */
if(!s->budget--) { s->failed_pc=0x0c092266u; return 0; }
return vf3_matrix_family(0x0c092268u,s,ram);
P_0c094558: /* original 000b, guest PC 0x0c094558 */
if(!s->budget--) { s->failed_pc=0x0c094558u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09455a: /* original 0009, guest PC 0x0c09455a */
if(!s->budget--) { s->failed_pc=0x0c09455au; return 0; }
return vf3_matrix_family(0x0c09455cu,s,ram);
P_0c096174: /* original 4f22, guest PC 0x0c096174 */
if(!s->budget--) { s->failed_pc=0x0c096174u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c096176;
P_0c096176: /* original dd1a, guest PC 0x0c096176 */
if(!s->budget--) { s->failed_pc=0x0c096176u; return 0; }
r[13]=read(ram,0x0c0961e0u,4);
goto P_0c096178;
P_0c096178: /* original 2c32, guest PC 0x0c096178 */
if(!s->budget--) { s->failed_pc=0x0c096178u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c09617a;
P_0c09617a: /* original 6ed3, guest PC 0x0c09617a */
if(!s->budget--) { s->failed_pc=0x0c09617au; return 0; }
r[14]=r[13];
goto P_0c09617c;
P_0c09617c: /* original 60e2, guest PC 0x0c09617c */
if(!s->budget--) { s->failed_pc=0x0c09617cu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c09617e;
P_0c09617e: /* original c801, guest PC 0x0c09617e */
if(!s->budget--) { s->failed_pc=0x0c09617eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c096180;
P_0c096180: /* original 8902, guest PC 0x0c096180 */
if(!s->budget--) { s->failed_pc=0x0c096180u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096188; }
goto P_0c096182;
P_0c096182: /* original 53e3, guest PC 0x0c096182 */
if(!s->budget--) { s->failed_pc=0x0c096182u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c096184;
P_0c096184: /* original 430b, guest PC 0x0c096184 */
if(!s->budget--) { s->failed_pc=0x0c096184u; return 0; }
target=r[3];
r[16]=0x0c096188u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096188u) { target=s->pc; goto dispatch; }
goto P_0c096188;
P_0c096186: /* original 64e3, guest PC 0x0c096186 */
if(!s->budget--) { s->failed_pc=0x0c096186u; return 0; }
r[4]=r[14];
goto P_0c096188;
P_0c096188: /* original 63c2, guest PC 0x0c096188 */
if(!s->budget--) { s->failed_pc=0x0c096188u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c09618a;
P_0c09618a: /* original 52e2, guest PC 0x0c09618a */
if(!s->budget--) { s->failed_pc=0x0c09618au; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c09618c;
P_0c09618c: /* original 73ff, guest PC 0x0c09618c */
if(!s->budget--) { s->failed_pc=0x0c09618cu; return 0; }
r[3]+=0xffffffffu;
goto P_0c09618e;
P_0c09618e: /* original 3d2c, guest PC 0x0c09618e */
if(!s->budget--) { s->failed_pc=0x0c09618eu; return 0; }
r[13]+=r[2];
goto P_0c096190;
P_0c096190: /* original 6133, guest PC 0x0c096190 */
if(!s->budget--) { s->failed_pc=0x0c096190u; return 0; }
r[1]=r[3];
goto P_0c096192;
P_0c096192: /* original e200, guest PC 0x0c096192 */
if(!s->budget--) { s->failed_pc=0x0c096192u; return 0; }
r[2]=0x00000000u;
goto P_0c096194;
P_0c096194: /* original 2c32, guest PC 0x0c096194 */
if(!s->budget--) { s->failed_pc=0x0c096194u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c096196;
P_0c096196: /* original 3126, guest PC 0x0c096196 */
if(!s->budget--) { s->failed_pc=0x0c096196u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[2])!=0);
goto P_0c096198;
P_0c096198: /* original 89ef, guest PC 0x0c096198 */
if(!s->budget--) { s->failed_pc=0x0c096198u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09617a; }
goto P_0c09619a;
P_0c09619a: /* original 4f26, guest PC 0x0c09619a */
if(!s->budget--) { s->failed_pc=0x0c09619au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09619c;
P_0c09619c: /* original 6cf6, guest PC 0x0c09619c */
if(!s->budget--) { s->failed_pc=0x0c09619cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09619e;
P_0c09619e: /* original 6df6, guest PC 0x0c09619e */
if(!s->budget--) { s->failed_pc=0x0c09619eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0961a0;
P_0c0961a0: /* original 000b, guest PC 0x0c0961a0 */
if(!s->budget--) { s->failed_pc=0x0c0961a0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0961a2: /* original 6ef6, guest PC 0x0c0961a2 */
if(!s->budget--) { s->failed_pc=0x0c0961a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0961a4u,s,ram);
P_0c096718: /* original 4f22, guest PC 0x0c096718 */
if(!s->budget--) { s->failed_pc=0x0c096718u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09671a;
P_0c09671a: /* original d340, guest PC 0x0c09671a */
if(!s->budget--) { s->failed_pc=0x0c09671au; return 0; }
r[3]=read(ram,0x0c09681cu,4);
goto P_0c09671c;
P_0c09671c: /* original 430b, guest PC 0x0c09671c */
if(!s->budget--) { s->failed_pc=0x0c09671cu; return 0; }
target=r[3];
r[16]=0x0c096720u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096720u) { target=s->pc; goto dispatch; }
goto P_0c096720;
P_0c09671e: /* original 0009, guest PC 0x0c09671e */
if(!s->budget--) { s->failed_pc=0x0c09671eu; return 0; }
goto P_0c096720;
P_0c096720: /* original d23f, guest PC 0x0c096720 */
if(!s->budget--) { s->failed_pc=0x0c096720u; return 0; }
r[2]=read(ram,0x0c096820u,4);
goto P_0c096722;
P_0c096722: /* original 420b, guest PC 0x0c096722 */
if(!s->budget--) { s->failed_pc=0x0c096722u; return 0; }
target=r[2];
r[16]=0x0c096726u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096726u) { target=s->pc; goto dispatch; }
goto P_0c096726;
P_0c096724: /* original 0009, guest PC 0x0c096724 */
if(!s->budget--) { s->failed_pc=0x0c096724u; return 0; }
goto P_0c096726;
P_0c096726: /* original d33f, guest PC 0x0c096726 */
if(!s->budget--) { s->failed_pc=0x0c096726u; return 0; }
r[3]=read(ram,0x0c096824u,4);
goto P_0c096728;
P_0c096728: /* original 430b, guest PC 0x0c096728 */
if(!s->budget--) { s->failed_pc=0x0c096728u; return 0; }
target=r[3];
r[16]=0x0c09672cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09672cu) { target=s->pc; goto dispatch; }
goto P_0c09672c;
P_0c09672a: /* original 0009, guest PC 0x0c09672a */
if(!s->budget--) { s->failed_pc=0x0c09672au; return 0; }
goto P_0c09672c;
P_0c09672c: /* original d23e, guest PC 0x0c09672c */
if(!s->budget--) { s->failed_pc=0x0c09672cu; return 0; }
r[2]=read(ram,0x0c096828u,4);
goto P_0c09672e;
P_0c09672e: /* original 420b, guest PC 0x0c09672e */
if(!s->budget--) { s->failed_pc=0x0c09672eu; return 0; }
target=r[2];
r[16]=0x0c096732u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096732u) { target=s->pc; goto dispatch; }
goto P_0c096732;
P_0c096730: /* original 0009, guest PC 0x0c096730 */
if(!s->budget--) { s->failed_pc=0x0c096730u; return 0; }
goto P_0c096732;
P_0c096732: /* original d33e, guest PC 0x0c096732 */
if(!s->budget--) { s->failed_pc=0x0c096732u; return 0; }
r[3]=read(ram,0x0c09682cu,4);
goto P_0c096734;
P_0c096734: /* original 430b, guest PC 0x0c096734 */
if(!s->budget--) { s->failed_pc=0x0c096734u; return 0; }
target=r[3];
r[16]=0x0c096738u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096738u) { target=s->pc; goto dispatch; }
goto P_0c096738;
P_0c096736: /* original 0009, guest PC 0x0c096736 */
if(!s->budget--) { s->failed_pc=0x0c096736u; return 0; }
goto P_0c096738;
P_0c096738: /* original d23d, guest PC 0x0c096738 */
if(!s->budget--) { s->failed_pc=0x0c096738u; return 0; }
r[2]=read(ram,0x0c096830u,4);
goto P_0c09673a;
P_0c09673a: /* original 420b, guest PC 0x0c09673a */
if(!s->budget--) { s->failed_pc=0x0c09673au; return 0; }
target=r[2];
r[16]=0x0c09673eu;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09673eu) { target=s->pc; goto dispatch; }
goto P_0c09673e;
P_0c09673c: /* original e400, guest PC 0x0c09673c */
if(!s->budget--) { s->failed_pc=0x0c09673cu; return 0; }
r[4]=0x00000000u;
goto P_0c09673e;
P_0c09673e: /* original d33d, guest PC 0x0c09673e */
if(!s->budget--) { s->failed_pc=0x0c09673eu; return 0; }
r[3]=read(ram,0x0c096834u,4);
goto P_0c096740;
P_0c096740: /* original 430b, guest PC 0x0c096740 */
if(!s->budget--) { s->failed_pc=0x0c096740u; return 0; }
target=r[3];
r[16]=0x0c096744u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096744u) { target=s->pc; goto dispatch; }
goto P_0c096744;
P_0c096742: /* original 0009, guest PC 0x0c096742 */
if(!s->budget--) { s->failed_pc=0x0c096742u; return 0; }
goto P_0c096744;
P_0c096744: /* original a050, guest PC 0x0c096744 */
if(!s->budget--) { s->failed_pc=0x0c096744u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0967e8;
P_0c096746: /* original 4f26, guest PC 0x0c096746 */
if(!s->budget--) { s->failed_pc=0x0c096746u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c096748u,s,ram);
P_0c0967e8: /* original 2fe6, guest PC 0x0c0967e8 */
if(!s->budget--) { s->failed_pc=0x0c0967e8u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0967ea;
P_0c0967ea: /* original 2fd6, guest PC 0x0c0967ea */
if(!s->budget--) { s->failed_pc=0x0c0967eau; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0967ec;
P_0c0967ec: /* original de18, guest PC 0x0c0967ec */
if(!s->budget--) { s->failed_pc=0x0c0967ecu; return 0; }
r[14]=read(ram,0x0c096850u,4);
goto P_0c0967ee;
P_0c0967ee: /* original 4f22, guest PC 0x0c0967ee */
if(!s->budget--) { s->failed_pc=0x0c0967eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0967f0;
P_0c0967f0: /* original dd19, guest PC 0x0c0967f0 */
if(!s->budget--) { s->failed_pc=0x0c0967f0u; return 0; }
r[13]=read(ram,0x0c096858u,4);
goto P_0c0967f2;
P_0c0967f2: /* original 64e3, guest PC 0x0c0967f2 */
if(!s->budget--) { s->failed_pc=0x0c0967f2u; return 0; }
r[4]=r[14];
goto P_0c0967f4;
P_0c0967f4: /* original d517, guest PC 0x0c0967f4 */
if(!s->budget--) { s->failed_pc=0x0c0967f4u; return 0; }
r[5]=read(ram,0x0c096854u,4);
goto P_0c0967f6;
P_0c0967f6: /* original 4d0b, guest PC 0x0c0967f6 */
if(!s->budget--) { s->failed_pc=0x0c0967f6u; return 0; }
target=r[13];
r[16]=0x0c0967fau;
r[4]+=0x0000002cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0967fau) { target=s->pc; goto dispatch; }
goto P_0c0967fa;
P_0c0967f8: /* original 742c, guest PC 0x0c0967f8 */
if(!s->budget--) { s->failed_pc=0x0c0967f8u; return 0; }
r[4]+=0x0000002cu;
goto P_0c0967fa;
P_0c0967fa: /* original d518, guest PC 0x0c0967fa */
if(!s->budget--) { s->failed_pc=0x0c0967fau; return 0; }
r[5]=read(ram,0x0c09685cu,4);
goto P_0c0967fc;
P_0c0967fc: /* original 64e3, guest PC 0x0c0967fc */
if(!s->budget--) { s->failed_pc=0x0c0967fcu; return 0; }
r[4]=r[14];
goto P_0c0967fe;
P_0c0967fe: /* original 6552, guest PC 0x0c0967fe */
if(!s->budget--) { s->failed_pc=0x0c0967feu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c096800;
P_0c096800: /* original 4d0b, guest PC 0x0c096800 */
if(!s->budget--) { s->failed_pc=0x0c096800u; return 0; }
target=r[13];
r[16]=0x0c096804u;
r[4]+=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096804u) { target=s->pc; goto dispatch; }
goto P_0c096804;
P_0c096802: /* original 7434, guest PC 0x0c096802 */
if(!s->budget--) { s->failed_pc=0x0c096802u; return 0; }
r[4]+=0x00000034u;
goto P_0c096804;
P_0c096804: /* original d516, guest PC 0x0c096804 */
if(!s->budget--) { s->failed_pc=0x0c096804u; return 0; }
r[5]=read(ram,0x0c096860u,4);
goto P_0c096806;
P_0c096806: /* original 64e3, guest PC 0x0c096806 */
if(!s->budget--) { s->failed_pc=0x0c096806u; return 0; }
r[4]=r[14];
goto P_0c096808;
P_0c096808: /* original 6552, guest PC 0x0c096808 */
if(!s->budget--) { s->failed_pc=0x0c096808u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c09680a;
P_0c09680a: /* original 4d0b, guest PC 0x0c09680a */
if(!s->budget--) { s->failed_pc=0x0c09680au; return 0; }
target=r[13];
r[16]=0x0c09680eu;
r[4]+=0x00000038u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09680eu) { target=s->pc; goto dispatch; }
goto P_0c09680e;
P_0c09680c: /* original 7438, guest PC 0x0c09680c */
if(!s->budget--) { s->failed_pc=0x0c09680cu; return 0; }
r[4]+=0x00000038u;
goto P_0c09680e;
P_0c09680e: /* original 4f26, guest PC 0x0c09680e */
if(!s->budget--) { s->failed_pc=0x0c09680eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096810;
P_0c096810: /* original 6df6, guest PC 0x0c096810 */
if(!s->budget--) { s->failed_pc=0x0c096810u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096812;
P_0c096812: /* original 000b, guest PC 0x0c096812 */
if(!s->budget--) { s->failed_pc=0x0c096812u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c096814: /* original 6ef6, guest PC 0x0c096814 */
if(!s->budget--) { s->failed_pc=0x0c096814u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c096816u,s,ram);
P_0c0a2774: /* original 4f22, guest PC 0x0c0a2774 */
if(!s->budget--) { s->failed_pc=0x0c0a2774u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2776;
P_0c0a2776: /* original c880, guest PC 0x0c0a2776 */
if(!s->budget--) { s->failed_pc=0x0c0a2776u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0a2778;
P_0c0a2778: /* original 8d2f, guest PC 0x0c0a2778 */
if(!s->budget--) { s->failed_pc=0x0c0a2778u; return 0; }
cond=r[17]&1u;
r[5]=r[9];
if(cond) { goto P_0c0a27da; }
goto P_0c0a277c;
P_0c0a277a: /* original 6593, guest PC 0x0c0a277a */
if(!s->budget--) { s->failed_pc=0x0c0a277au; return 0; }
r[5]=r[9];
goto P_0c0a277c;
P_0c0a277c: /* original 6242, guest PC 0x0c0a277c */
if(!s->budget--) { s->failed_pc=0x0c0a277cu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0a277e;
P_0c0a277e: /* original e020, guest PC 0x0c0a277e */
if(!s->budget--) { s->failed_pc=0x0c0a277eu; return 0; }
r[0]=0x00000020u;
goto P_0c0a2780;
P_0c0a2780: /* original d337, guest PC 0x0c0a2780 */
if(!s->budget--) { s->failed_pc=0x0c0a2780u; return 0; }
r[3]=read(ram,0x0c0a2860u,4);
goto P_0c0a2782;
P_0c0a2782: /* original 9169, guest PC 0x0c0a2782 */
if(!s->budget--) { s->failed_pc=0x0c0a2782u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2858u,2);
goto P_0c0a2784;
P_0c0a2784: /* original 2239, guest PC 0x0c0a2784 */
if(!s->budget--) { s->failed_pc=0x0c0a2784u; return 0; }
r[2]&=r[3];
goto P_0c0a2786;
P_0c0a2786: /* original 03dd, guest PC 0x0c0a2786 */
if(!s->budget--) { s->failed_pc=0x0c0a2786u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a2788;
P_0c0a2788: /* original e022, guest PC 0x0c0a2788 */
if(!s->budget--) { s->failed_pc=0x0c0a2788u; return 0; }
r[0]=0x00000022u;
goto P_0c0a278a;
P_0c0a278a: /* original 3210, guest PC 0x0c0a278a */
if(!s->budget--) { s->failed_pc=0x0c0a278au; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c0a278c;
P_0c0a278c: /* original 02dd, guest PC 0x0c0a278c */
if(!s->budget--) { s->failed_pc=0x0c0a278cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a278e;
P_0c0a278e: /* original 633d, guest PC 0x0c0a278e */
if(!s->budget--) { s->failed_pc=0x0c0a278eu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a2790;
P_0c0a2790: /* original 622d, guest PC 0x0c0a2790 */
if(!s->budget--) { s->failed_pc=0x0c0a2790u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0a2792;
P_0c0a2792: /* original 232b, guest PC 0x0c0a2792 */
if(!s->budget--) { s->failed_pc=0x0c0a2792u; return 0; }
r[3]|=r[2];
goto P_0c0a2794;
P_0c0a2794: /* original 2338, guest PC 0x0c0a2794 */
if(!s->budget--) { s->failed_pc=0x0c0a2794u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2796;
P_0c0a2796: /* original 8920, guest PC 0x0c0a2796 */
if(!s->budget--) { s->failed_pc=0x0c0a2796u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a27da; }
goto P_0c0a2798;
P_0c0a2798: /* original e020, guest PC 0x0c0a2798 */
if(!s->budget--) { s->failed_pc=0x0c0a2798u; return 0; }
r[0]=0x00000020u;
goto P_0c0a279a;
P_0c0a279a: /* original d332, guest PC 0x0c0a279a */
if(!s->budget--) { s->failed_pc=0x0c0a279au; return 0; }
r[3]=read(ram,0x0c0a2864u,4);
goto P_0c0a279c;
P_0c0a279c: /* original 04dd, guest PC 0x0c0a279c */
if(!s->budget--) { s->failed_pc=0x0c0a279cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0a279e;
P_0c0a279e: /* original 58d4, guest PC 0x0c0a279e */
if(!s->budget--) { s->failed_pc=0x0c0a279eu; return 0; }
r[8]=read(ram,r[13]+16,4);
goto P_0c0a27a0;
P_0c0a27a0: /* original 430b, guest PC 0x0c0a27a0 */
if(!s->budget--) { s->failed_pc=0x0c0a27a0u; return 0; }
target=r[3];
r[16]=0x0c0a27a4u;
r[4]=r[4]&65535u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a27a4u) { target=s->pc; goto dispatch; }
goto P_0c0a27a4;
P_0c0a27a2: /* original 644d, guest PC 0x0c0a27a2 */
if(!s->budget--) { s->failed_pc=0x0c0a27a2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a27a4;
P_0c0a27a4: /* original ea01, guest PC 0x0c0a27a4 */
if(!s->budget--) { s->failed_pc=0x0c0a27a4u; return 0; }
r[10]=0x00000001u;
goto P_0c0a27a6;
P_0c0a27a6: /* original a013, guest PC 0x0c0a27a6 */
if(!s->budget--) { s->failed_pc=0x0c0a27a6u; return 0; }
r[12]=r[9];
goto P_0c0a27d0;
P_0c0a27a8: /* original 6c93, guest PC 0x0c0a27a8 */
if(!s->budget--) { s->failed_pc=0x0c0a27a8u; return 0; }
r[12]=r[9];
goto P_0c0a27aa;
P_0c0a27aa: /* original 6ec3, guest PC 0x0c0a27aa */
if(!s->budget--) { s->failed_pc=0x0c0a27aau; return 0; }
r[14]=r[12];
goto P_0c0a27ac;
P_0c0a27ac: /* original 4e08, guest PC 0x0c0a27ac */
if(!s->budget--) { s->failed_pc=0x0c0a27acu; return 0; }
r[14]<<=2;
goto P_0c0a27ae;
P_0c0a27ae: /* original 3e8c, guest PC 0x0c0a27ae */
if(!s->budget--) { s->failed_pc=0x0c0a27aeu; return 0; }
r[14]+=r[8];
goto P_0c0a27b0;
P_0c0a27b0: /* original 63e2, guest PC 0x0c0a27b0 */
if(!s->budget--) { s->failed_pc=0x0c0a27b0u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0a27b2;
P_0c0a27b2: /* original 5231, guest PC 0x0c0a27b2 */
if(!s->budget--) { s->failed_pc=0x0c0a27b2u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c0a27b4;
P_0c0a27b4: /* original 22a8, guest PC 0x0c0a27b4 */
if(!s->budget--) { s->failed_pc=0x0c0a27b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[10])==0)!=0);
goto P_0c0a27b6;
P_0c0a27b6: /* original 8904, guest PC 0x0c0a27b6 */
if(!s->budget--) { s->failed_pc=0x0c0a27b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a27c2; }
goto P_0c0a27b8;
P_0c0a27b8: /* original d22b, guest PC 0x0c0a27b8 */
if(!s->budget--) { s->failed_pc=0x0c0a27b8u; return 0; }
r[2]=read(ram,0x0c0a2868u,4);
goto P_0c0a27ba;
P_0c0a27ba: /* original 420b, guest PC 0x0c0a27ba */
if(!s->budget--) { s->failed_pc=0x0c0a27bau; return 0; }
target=r[2];
r[16]=0x0c0a27beu;
tmp=read(ram,r[14],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a27beu) { target=s->pc; goto dispatch; }
goto P_0c0a27be;
P_0c0a27bc: /* original 64e2, guest PC 0x0c0a27bc */
if(!s->budget--) { s->failed_pc=0x0c0a27bcu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0a27be;
P_0c0a27be: /* original a006, guest PC 0x0c0a27be */
if(!s->budget--) { s->failed_pc=0x0c0a27beu; return 0; }
goto P_0c0a27ce;
P_0c0a27c0: /* original 0009, guest PC 0x0c0a27c0 */
if(!s->budget--) { s->failed_pc=0x0c0a27c0u; return 0; }
goto P_0c0a27c2;
P_0c0a27c2: /* original 6be2, guest PC 0x0c0a27c2 */
if(!s->budget--) { s->failed_pc=0x0c0a27c2u; return 0; }
tmp=read(ram,r[14],4);
r[11]=tmp;
goto P_0c0a27c4;
P_0c0a27c4: /* original d229, guest PC 0x0c0a27c4 */
if(!s->budget--) { s->failed_pc=0x0c0a27c4u; return 0; }
r[2]=read(ram,0x0c0a286cu,4);
goto P_0c0a27c6;
P_0c0a27c6: /* original 55b1, guest PC 0x0c0a27c6 */
if(!s->budget--) { s->failed_pc=0x0c0a27c6u; return 0; }
r[5]=read(ram,r[11]+4,4);
goto P_0c0a27c8;
P_0c0a27c8: /* original 56b2, guest PC 0x0c0a27c8 */
if(!s->budget--) { s->failed_pc=0x0c0a27c8u; return 0; }
r[6]=read(ram,r[11]+8,4);
goto P_0c0a27ca;
P_0c0a27ca: /* original 420b, guest PC 0x0c0a27ca */
if(!s->budget--) { s->failed_pc=0x0c0a27cau; return 0; }
target=r[2];
r[16]=0x0c0a27ceu;
tmp=read(ram,r[11],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a27ceu) { target=s->pc; goto dispatch; }
goto P_0c0a27ce;
P_0c0a27cc: /* original 64b2, guest PC 0x0c0a27cc */
if(!s->budget--) { s->failed_pc=0x0c0a27ccu; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c0a27ce;
P_0c0a27ce: /* original 7c01, guest PC 0x0c0a27ce */
if(!s->budget--) { s->failed_pc=0x0c0a27ceu; return 0; }
r[12]+=0x00000001u;
goto P_0c0a27d0;
P_0c0a27d0: /* original 85d6, guest PC 0x0c0a27d0 */
if(!s->budget--) { s->failed_pc=0x0c0a27d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+12,2);
goto P_0c0a27d2;
P_0c0a27d2: /* original 600d, guest PC 0x0c0a27d2 */
if(!s->budget--) { s->failed_pc=0x0c0a27d2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a27d4;
P_0c0a27d4: /* original 3c03, guest PC 0x0c0a27d4 */
if(!s->budget--) { s->failed_pc=0x0c0a27d4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[0])!=0);
goto P_0c0a27d6;
P_0c0a27d6: /* original 8be8, guest PC 0x0c0a27d6 */
if(!s->budget--) { s->failed_pc=0x0c0a27d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a27aa; }
goto P_0c0a27d8;
P_0c0a27d8: /* original 6593, guest PC 0x0c0a27d8 */
if(!s->budget--) { s->failed_pc=0x0c0a27d8u; return 0; }
r[5]=r[9];
goto P_0c0a27da;
P_0c0a27da: /* original 4f26, guest PC 0x0c0a27da */
if(!s->budget--) { s->failed_pc=0x0c0a27dau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a27dc;
P_0c0a27dc: /* original 6053, guest PC 0x0c0a27dc */
if(!s->budget--) { s->failed_pc=0x0c0a27dcu; return 0; }
r[0]=r[5];
goto P_0c0a27de;
P_0c0a27de: /* original 68f6, guest PC 0x0c0a27de */
if(!s->budget--) { s->failed_pc=0x0c0a27deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a27e0;
P_0c0a27e0: /* original 69f6, guest PC 0x0c0a27e0 */
if(!s->budget--) { s->failed_pc=0x0c0a27e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a27e2;
P_0c0a27e2: /* original 6af6, guest PC 0x0c0a27e2 */
if(!s->budget--) { s->failed_pc=0x0c0a27e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a27e4;
P_0c0a27e4: /* original 6bf6, guest PC 0x0c0a27e4 */
if(!s->budget--) { s->failed_pc=0x0c0a27e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a27e6;
P_0c0a27e6: /* original 6cf6, guest PC 0x0c0a27e6 */
if(!s->budget--) { s->failed_pc=0x0c0a27e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a27e8;
P_0c0a27e8: /* original 6df6, guest PC 0x0c0a27e8 */
if(!s->budget--) { s->failed_pc=0x0c0a27e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a27ea;
P_0c0a27ea: /* original 000b, guest PC 0x0c0a27ea */
if(!s->budget--) { s->failed_pc=0x0c0a27eau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a27ec: /* original 6ef6, guest PC 0x0c0a27ec */
if(!s->budget--) { s->failed_pc=0x0c0a27ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a27eeu,s,ram);
P_0c0a7302: /* original 4f22, guest PC 0x0c0a7302 */
if(!s->budget--) { s->failed_pc=0x0c0a7302u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7304;
P_0c0a7304: /* original 223b, guest PC 0x0c0a7304 */
if(!s->budget--) { s->failed_pc=0x0c0a7304u; return 0; }
r[2]|=r[3];
goto P_0c0a7306;
P_0c0a7306: /* original bfcb, guest PC 0x0c0a7306 */
if(!s->budget--) { s->failed_pc=0x0c0a7306u; return 0; }
target=0x0c0a72a0u; r[16]=0x0c0a730au;
write(ram,r[14],r[2],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a730au) { target=s->pc; goto dispatch; }
goto P_0c0a730a;
P_0c0a7308: /* original 2e22, guest PC 0x0c0a7308 */
if(!s->budget--) { s->failed_pc=0x0c0a7308u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a730a;
P_0c0a730a: /* original 61e2, guest PC 0x0c0a730a */
if(!s->budget--) { s->failed_pc=0x0c0a730au; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0a730c;
P_0c0a730c: /* original d331, guest PC 0x0c0a730c */
if(!s->budget--) { s->failed_pc=0x0c0a730cu; return 0; }
r[3]=read(ram,0x0c0a73d4u,4);
goto P_0c0a730e;
P_0c0a730e: /* original 9458, guest PC 0x0c0a730e */
if(!s->budget--) { s->failed_pc=0x0c0a730eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a73c2u,2);
goto P_0c0a7310;
P_0c0a7310: /* original d231, guest PC 0x0c0a7310 */
if(!s->budget--) { s->failed_pc=0x0c0a7310u; return 0; }
r[2]=read(ram,0x0c0a73d8u,4);
goto P_0c0a7312;
P_0c0a7312: /* original 2139, guest PC 0x0c0a7312 */
if(!s->budget--) { s->failed_pc=0x0c0a7312u; return 0; }
r[1]&=r[3];
goto P_0c0a7314;
P_0c0a7314: /* original 420b, guest PC 0x0c0a7314 */
if(!s->budget--) { s->failed_pc=0x0c0a7314u; return 0; }
target=r[2];
r[16]=0x0c0a7318u;
write(ram,r[14],r[1],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7318u) { target=s->pc; goto dispatch; }
goto P_0c0a7318;
P_0c0a7316: /* original 2e12, guest PC 0x0c0a7316 */
if(!s->budget--) { s->failed_pc=0x0c0a7316u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0a7318;
P_0c0a7318: /* original d330, guest PC 0x0c0a7318 */
if(!s->budget--) { s->failed_pc=0x0c0a7318u; return 0; }
r[3]=read(ram,0x0c0a73dcu,4);
goto P_0c0a731a;
P_0c0a731a: /* original 6032, guest PC 0x0c0a731a */
if(!s->budget--) { s->failed_pc=0x0c0a731au; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0a731c;
P_0c0a731c: /* original 8800, guest PC 0x0c0a731c */
if(!s->budget--) { s->failed_pc=0x0c0a731cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c0a731e;
P_0c0a731e: /* original 8912, guest PC 0x0c0a731e */
if(!s->budget--) { s->failed_pc=0x0c0a731eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7346; }
goto P_0c0a7320;
P_0c0a7320: /* original 8801, guest PC 0x0c0a7320 */
if(!s->budget--) { s->failed_pc=0x0c0a7320u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a7322;
P_0c0a7322: /* original 8910, guest PC 0x0c0a7322 */
if(!s->budget--) { s->failed_pc=0x0c0a7322u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7346; }
goto P_0c0a7324;
P_0c0a7324: /* original 8802, guest PC 0x0c0a7324 */
if(!s->budget--) { s->failed_pc=0x0c0a7324u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0a7326;
P_0c0a7326: /* original 890e, guest PC 0x0c0a7326 */
if(!s->budget--) { s->failed_pc=0x0c0a7326u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7346; }
goto P_0c0a7328;
P_0c0a7328: /* original 8803, guest PC 0x0c0a7328 */
if(!s->budget--) { s->failed_pc=0x0c0a7328u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0a732a;
P_0c0a732a: /* original 890c, guest PC 0x0c0a732a */
if(!s->budget--) { s->failed_pc=0x0c0a732au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7346; }
goto P_0c0a732c;
P_0c0a732c: /* original 8804, guest PC 0x0c0a732c */
if(!s->budget--) { s->failed_pc=0x0c0a732cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0a732e;
P_0c0a732e: /* original 890a, guest PC 0x0c0a732e */
if(!s->budget--) { s->failed_pc=0x0c0a732eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7346; }
goto P_0c0a7330;
P_0c0a7330: /* original 880a, guest PC 0x0c0a7330 */
if(!s->budget--) { s->failed_pc=0x0c0a7330u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c0a7332;
P_0c0a7332: /* original 8908, guest PC 0x0c0a7332 */
if(!s->budget--) { s->failed_pc=0x0c0a7332u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7346; }
goto P_0c0a7334;
P_0c0a7334: /* original 880b, guest PC 0x0c0a7334 */
if(!s->budget--) { s->failed_pc=0x0c0a7334u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0a7336;
P_0c0a7336: /* original 8906, guest PC 0x0c0a7336 */
if(!s->budget--) { s->failed_pc=0x0c0a7336u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7346; }
goto P_0c0a7338;
P_0c0a7338: /* original 880c, guest PC 0x0c0a7338 */
if(!s->budget--) { s->failed_pc=0x0c0a7338u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0a733a;
P_0c0a733a: /* original 8904, guest PC 0x0c0a733a */
if(!s->budget--) { s->failed_pc=0x0c0a733au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7346; }
goto P_0c0a733c;
P_0c0a733c: /* original 880d, guest PC 0x0c0a733c */
if(!s->budget--) { s->failed_pc=0x0c0a733cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0a733e;
P_0c0a733e: /* original 8902, guest PC 0x0c0a733e */
if(!s->budget--) { s->failed_pc=0x0c0a733eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7346; }
goto P_0c0a7340;
P_0c0a7340: /* original 880e, guest PC 0x0c0a7340 */
if(!s->budget--) { s->failed_pc=0x0c0a7340u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c0a7342;
P_0c0a7342: /* original 8900, guest PC 0x0c0a7342 */
if(!s->budget--) { s->failed_pc=0x0c0a7342u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7346; }
goto P_0c0a7344;
P_0c0a7344: /* original 8814, guest PC 0x0c0a7344 */
if(!s->budget--) { s->failed_pc=0x0c0a7344u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000014u)!=0);
goto P_0c0a7346;
P_0c0a7346: /* original c726, guest PC 0x0c0a7346 */
if(!s->budget--) { s->failed_pc=0x0c0a7346u; return 0; }
r[0]=0x0c0a73e0u;
goto P_0c0a7348;
P_0c0a7348: /* original f308, guest PC 0x0c0a7348 */
if(!s->budget--) { s->failed_pc=0x0c0a7348u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a734a;
P_0c0a734a: /* original 903b, guest PC 0x0c0a734a */
if(!s->budget--) { s->failed_pc=0x0c0a734au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a73c4u,2);
goto P_0c0a734c;
P_0c0a734c: /* original fe37, guest PC 0x0c0a734c */
if(!s->budget--) { s->failed_pc=0x0c0a734cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a734e;
P_0c0a734e: /* original c725, guest PC 0x0c0a734e */
if(!s->budget--) { s->failed_pc=0x0c0a734eu; return 0; }
r[0]=0x0c0a73e4u;
goto P_0c0a7350;
P_0c0a7350: /* original f308, guest PC 0x0c0a7350 */
if(!s->budget--) { s->failed_pc=0x0c0a7350u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a7352;
P_0c0a7352: /* original 9038, guest PC 0x0c0a7352 */
if(!s->budget--) { s->failed_pc=0x0c0a7352u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a73c6u,2);
goto P_0c0a7354;
P_0c0a7354: /* original fe37, guest PC 0x0c0a7354 */
if(!s->budget--) { s->failed_pc=0x0c0a7354u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a7356;
P_0c0a7356: /* original c724, guest PC 0x0c0a7356 */
if(!s->budget--) { s->failed_pc=0x0c0a7356u; return 0; }
r[0]=0x0c0a73e8u;
goto P_0c0a7358;
P_0c0a7358: /* original f308, guest PC 0x0c0a7358 */
if(!s->budget--) { s->failed_pc=0x0c0a7358u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a735a;
P_0c0a735a: /* original 9035, guest PC 0x0c0a735a */
if(!s->budget--) { s->failed_pc=0x0c0a735au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a73c8u,2);
goto P_0c0a735c;
P_0c0a735c: /* original fe37, guest PC 0x0c0a735c */
if(!s->budget--) { s->failed_pc=0x0c0a735cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a735e;
P_0c0a735e: /* original c723, guest PC 0x0c0a735e */
if(!s->budget--) { s->failed_pc=0x0c0a735eu; return 0; }
r[0]=0x0c0a73ecu;
goto P_0c0a7360;
P_0c0a7360: /* original f308, guest PC 0x0c0a7360 */
if(!s->budget--) { s->failed_pc=0x0c0a7360u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a7362;
P_0c0a7362: /* original 9031, guest PC 0x0c0a7362 */
if(!s->budget--) { s->failed_pc=0x0c0a7362u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a73c8u,2);
goto P_0c0a7364;
P_0c0a7364: /* original fe37, guest PC 0x0c0a7364 */
if(!s->budget--) { s->failed_pc=0x0c0a7364u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a7366;
P_0c0a7366: /* original c722, guest PC 0x0c0a7366 */
if(!s->budget--) { s->failed_pc=0x0c0a7366u; return 0; }
r[0]=0x0c0a73f0u;
goto P_0c0a7368;
P_0c0a7368: /* original f308, guest PC 0x0c0a7368 */
if(!s->budget--) { s->failed_pc=0x0c0a7368u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a736a;
P_0c0a736a: /* original 902d, guest PC 0x0c0a736a */
if(!s->budget--) { s->failed_pc=0x0c0a736au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a73c8u,2);
goto P_0c0a736c;
P_0c0a736c: /* original fe37, guest PC 0x0c0a736c */
if(!s->budget--) { s->failed_pc=0x0c0a736cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a736e;
P_0c0a736e: /* original c721, guest PC 0x0c0a736e */
if(!s->budget--) { s->failed_pc=0x0c0a736eu; return 0; }
r[0]=0x0c0a73f4u;
goto P_0c0a7370;
P_0c0a7370: /* original f708, guest PC 0x0c0a7370 */
if(!s->budget--) { s->failed_pc=0x0c0a7370u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0a7372;
P_0c0a7372: /* original c721, guest PC 0x0c0a7372 */
if(!s->budget--) { s->failed_pc=0x0c0a7372u; return 0; }
r[0]=0x0c0a73f8u;
goto P_0c0a7374;
P_0c0a7374: /* original d321, guest PC 0x0c0a7374 */
if(!s->budget--) { s->failed_pc=0x0c0a7374u; return 0; }
r[3]=read(ram,0x0c0a73fcu,4);
goto P_0c0a7376;
P_0c0a7376: /* original f608, guest PC 0x0c0a7376 */
if(!s->budget--) { s->failed_pc=0x0c0a7376u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0a7378;
P_0c0a7378: /* original ff8d, guest PC 0x0c0a7378 */
if(!s->budget--) { s->failed_pc=0x0c0a7378u; return 0; }
fr[15]=0;
goto P_0c0a737a;
P_0c0a737a: /* original f5fc, guest PC 0x0c0a737a */
if(!s->budget--) { s->failed_pc=0x0c0a737au; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0a737c;
P_0c0a737c: /* original 430b, guest PC 0x0c0a737c */
if(!s->budget--) { s->failed_pc=0x0c0a737cu; return 0; }
target=r[3];
r[16]=0x0c0a7380u;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a7380u) { target=s->pc; goto dispatch; }
goto P_0c0a7380;
P_0c0a737e: /* original f4fc, guest PC 0x0c0a737e */
if(!s->budget--) { s->failed_pc=0x0c0a737eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0a7380;
P_0c0a7380: /* original 4f26, guest PC 0x0c0a7380 */
if(!s->budget--) { s->failed_pc=0x0c0a7380u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7382;
P_0c0a7382: /* original f5fc, guest PC 0x0c0a7382 */
if(!s->budget--) { s->failed_pc=0x0c0a7382u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0a7384;
P_0c0a7384: /* original f4fc, guest PC 0x0c0a7384 */
if(!s->budget--) { s->failed_pc=0x0c0a7384u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0a7386;
P_0c0a7386: /* original d21e, guest PC 0x0c0a7386 */
if(!s->budget--) { s->failed_pc=0x0c0a7386u; return 0; }
r[2]=read(ram,0x0c0a7400u,4);
goto P_0c0a7388;
P_0c0a7388: /* original fff9, guest PC 0x0c0a7388 */
if(!s->budget--) { s->failed_pc=0x0c0a7388u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a738a;
P_0c0a738a: /* original 422b, guest PC 0x0c0a738a */
if(!s->budget--) { s->failed_pc=0x0c0a738au; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c0a738c: /* original 6ef6, guest PC 0x0c0a738c */
if(!s->budget--) { s->failed_pc=0x0c0a738cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a738eu,s,ram);
P_0c0a803c: /* original 2fe6, guest PC 0x0c0a803c */
if(!s->budget--) { s->failed_pc=0x0c0a803cu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0a803e;
P_0c0a803e: /* original e500, guest PC 0x0c0a803e */
if(!s->budget--) { s->failed_pc=0x0c0a803eu; return 0; }
r[5]=0x00000000u;
goto P_0c0a8040;
P_0c0a8040: /* original 4f22, guest PC 0x0c0a8040 */
if(!s->budget--) { s->failed_pc=0x0c0a8040u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a8042;
P_0c0a8042: /* original 9625, guest PC 0x0c0a8042 */
if(!s->budget--) { s->failed_pc=0x0c0a8042u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a8090u,2);
goto P_0c0a8044;
P_0c0a8044: /* original 6e43, guest PC 0x0c0a8044 */
if(!s->budget--) { s->failed_pc=0x0c0a8044u; return 0; }
r[14]=r[4];
goto P_0c0a8046;
P_0c0a8046: /* original d317, guest PC 0x0c0a8046 */
if(!s->budget--) { s->failed_pc=0x0c0a8046u; return 0; }
r[3]=read(ram,0x0c0a80a4u,4);
goto P_0c0a8048;
P_0c0a8048: /* original 4f12, guest PC 0x0c0a8048 */
if(!s->budget--) { s->failed_pc=0x0c0a8048u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a804a;
P_0c0a804a: /* original 430b, guest PC 0x0c0a804a */
if(!s->budget--) { s->failed_pc=0x0c0a804au; return 0; }
target=r[3];
r[16]=0x0c0a804eu;
r[4]+=0x0000001cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a804eu) { target=s->pc; goto dispatch; }
goto P_0c0a804e;
P_0c0a804c: /* original 741c, guest PC 0x0c0a804c */
if(!s->budget--) { s->failed_pc=0x0c0a804cu; return 0; }
r[4]+=0x0000001cu;
goto P_0c0a804e;
P_0c0a804e: /* original e500, guest PC 0x0c0a804e */
if(!s->budget--) { s->failed_pc=0x0c0a804eu; return 0; }
r[5]=0x00000000u;
goto P_0c0a8050;
P_0c0a8050: /* original 6453, guest PC 0x0c0a8050 */
if(!s->budget--) { s->failed_pc=0x0c0a8050u; return 0; }
r[4]=r[5];
goto P_0c0a8052;
P_0c0a8052: /* original e620, guest PC 0x0c0a8052 */
if(!s->budget--) { s->failed_pc=0x0c0a8052u; return 0; }
r[6]=0x00000020u;
goto P_0c0a8054;
P_0c0a8054: /* original e234, guest PC 0x0c0a8054 */
if(!s->budget--) { s->failed_pc=0x0c0a8054u; return 0; }
r[2]=0x00000034u;
goto P_0c0a8056;
P_0c0a8056: /* original 63e3, guest PC 0x0c0a8056 */
if(!s->budget--) { s->failed_pc=0x0c0a8056u; return 0; }
r[3]=r[14];
goto P_0c0a8058;
P_0c0a8058: /* original 242f, guest PC 0x0c0a8058 */
if(!s->budget--) { s->failed_pc=0x0c0a8058u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[2]);
goto P_0c0a805a;
P_0c0a805a: /* original 731c, guest PC 0x0c0a805a */
if(!s->budget--) { s->failed_pc=0x0c0a805au; return 0; }
r[3]+=0x0000001cu;
goto P_0c0a805c;
P_0c0a805c: /* original e030, guest PC 0x0c0a805c */
if(!s->budget--) { s->failed_pc=0x0c0a805cu; return 0; }
r[0]=0x00000030u;
goto P_0c0a805e;
P_0c0a805e: /* original 021a, guest PC 0x0c0a805e */
if(!s->budget--) { s->failed_pc=0x0c0a805eu; return 0; }
r[2]=r[19];
goto P_0c0a8060;
P_0c0a8060: /* original 622f, guest PC 0x0c0a8060 */
if(!s->budget--) { s->failed_pc=0x0c0a8060u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c0a8062;
P_0c0a8062: /* original 323c, guest PC 0x0c0a8062 */
if(!s->budget--) { s->failed_pc=0x0c0a8062u; return 0; }
r[2]+=r[3];
goto P_0c0a8064;
P_0c0a8064: /* original 0245, guest PC 0x0c0a8064 */
if(!s->budget--) { s->failed_pc=0x0c0a8064u; return 0; }
write(ram,r[2]+r[0],r[4],2);
goto P_0c0a8066;
P_0c0a8066: /* original 7401, guest PC 0x0c0a8066 */
if(!s->budget--) { s->failed_pc=0x0c0a8066u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a8068;
P_0c0a8068: /* original 3463, guest PC 0x0c0a8068 */
if(!s->budget--) { s->failed_pc=0x0c0a8068u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c0a806a;
P_0c0a806a: /* original 8bf3, guest PC 0x0c0a806a */
if(!s->budget--) { s->failed_pc=0x0c0a806au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a8054; }
goto P_0c0a806c;
P_0c0a806c: /* original 62e2, guest PC 0x0c0a806c */
if(!s->budget--) { s->failed_pc=0x0c0a806cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0a806e;
P_0c0a806e: /* original 6053, guest PC 0x0c0a806e */
if(!s->budget--) { s->failed_pc=0x0c0a806eu; return 0; }
r[0]=r[5];
goto P_0c0a8070;
P_0c0a8070: /* original d30d, guest PC 0x0c0a8070 */
if(!s->budget--) { s->failed_pc=0x0c0a8070u; return 0; }
r[3]=read(ram,0x0c0a80a8u,4);
goto P_0c0a8072;
P_0c0a8072: /* original 4f16, guest PC 0x0c0a8072 */
if(!s->budget--) { s->failed_pc=0x0c0a8072u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8074;
P_0c0a8074: /* original 2239, guest PC 0x0c0a8074 */
if(!s->budget--) { s->failed_pc=0x0c0a8074u; return 0; }
r[2]&=r[3];
goto P_0c0a8076;
P_0c0a8076: /* original 2e22, guest PC 0x0c0a8076 */
if(!s->budget--) { s->failed_pc=0x0c0a8076u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a8078;
P_0c0a8078: /* original 4f26, guest PC 0x0c0a8078 */
if(!s->budget--) { s->failed_pc=0x0c0a8078u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a807a;
P_0c0a807a: /* original 1e54, guest PC 0x0c0a807a */
if(!s->budget--) { s->failed_pc=0x0c0a807au; return 0; }
write(ram,r[14]+16,r[5],4);
goto P_0c0a807c;
P_0c0a807c: /* original 81ec, guest PC 0x0c0a807c */
if(!s->budget--) { s->failed_pc=0x0c0a807cu; return 0; }
write(ram,r[14]+24,r[0],2);
goto P_0c0a807e;
P_0c0a807e: /* original 81eb, guest PC 0x0c0a807e */
if(!s->budget--) { s->failed_pc=0x0c0a807eu; return 0; }
write(ram,r[14]+22,r[0],2);
goto P_0c0a8080;
P_0c0a8080: /* original 81ea, guest PC 0x0c0a8080 */
if(!s->budget--) { s->failed_pc=0x0c0a8080u; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c0a8082;
P_0c0a8082: /* original 81ed, guest PC 0x0c0a8082 */
if(!s->budget--) { s->failed_pc=0x0c0a8082u; return 0; }
write(ram,r[14]+26,r[0],2);
goto P_0c0a8084;
P_0c0a8084: /* original d209, guest PC 0x0c0a8084 */
if(!s->budget--) { s->failed_pc=0x0c0a8084u; return 0; }
r[2]=read(ram,0x0c0a80acu,4);
goto P_0c0a8086;
P_0c0a8086: /* original 1e23, guest PC 0x0c0a8086 */
if(!s->budget--) { s->failed_pc=0x0c0a8086u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c0a8088;
P_0c0a8088: /* original 000b, guest PC 0x0c0a8088 */
if(!s->budget--) { s->failed_pc=0x0c0a8088u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a808a: /* original 6ef6, guest PC 0x0c0a808a */
if(!s->budget--) { s->failed_pc=0x0c0a808au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a808cu,s,ram);
P_0c0afef4: /* original 2fe6, guest PC 0x0c0afef4 */
if(!s->budget--) { s->failed_pc=0x0c0afef4u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0afef6;
P_0c0afef6: /* original 2fd6, guest PC 0x0c0afef6 */
if(!s->budget--) { s->failed_pc=0x0c0afef6u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0afef8;
P_0c0afef8: /* original d43c, guest PC 0x0c0afef8 */
if(!s->budget--) { s->failed_pc=0x0c0afef8u; return 0; }
r[4]=read(ram,0x0c0affecu,4);
goto P_0c0afefa;
P_0c0afefa: /* original d53a, guest PC 0x0c0afefa */
if(!s->budget--) { s->failed_pc=0x0c0afefau; return 0; }
r[5]=read(ram,0x0c0affe4u,4);
goto P_0c0afefc;
P_0c0afefc: /* original 5e45, guest PC 0x0c0afefc */
if(!s->budget--) { s->failed_pc=0x0c0afefcu; return 0; }
r[14]=read(ram,r[4]+20,4);
goto P_0c0afefe;
P_0c0afefe: /* original 5d44, guest PC 0x0c0afefe */
if(!s->budget--) { s->failed_pc=0x0c0afefeu; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0aff00;
P_0c0aff00: /* original 6452, guest PC 0x0c0aff00 */
if(!s->budget--) { s->failed_pc=0x0c0aff00u; return 0; }
tmp=read(ram,r[5],4);
r[4]=tmp;
goto P_0c0aff02;
P_0c0aff02: /* original d33b, guest PC 0x0c0aff02 */
if(!s->budget--) { s->failed_pc=0x0c0aff02u; return 0; }
r[3]=read(ram,0x0c0afff0u,4);
return vf3_matrix_family(0x0c0aff04u,s,ram);
P_0c0c26dc: /* original 2fe6, guest PC 0x0c0c26dc */
if(!s->budget--) { s->failed_pc=0x0c0c26dcu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c26de;
P_0c0c26de: /* original 6e43, guest PC 0x0c0c26de */
if(!s->budget--) { s->failed_pc=0x0c0c26deu; return 0; }
r[14]=r[4];
goto P_0c0c26e0;
P_0c0c26e0: /* original 4f22, guest PC 0x0c0c26e0 */
if(!s->budget--) { s->failed_pc=0x0c0c26e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c26e2;
P_0c0c26e2: /* original 9492, guest PC 0x0c0c26e2 */
if(!s->budget--) { s->failed_pc=0x0c0c26e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c280au,2);
goto P_0c0c26e4;
P_0c0c26e4: /* original d252, guest PC 0x0c0c26e4 */
if(!s->budget--) { s->failed_pc=0x0c0c26e4u; return 0; }
r[2]=read(ram,0x0c0c2830u,4);
goto P_0c0c26e6;
P_0c0c26e6: /* original d551, guest PC 0x0c0c26e6 */
if(!s->budget--) { s->failed_pc=0x0c0c26e6u; return 0; }
r[5]=read(ram,0x0c0c282cu,4);
goto P_0c0c26e8;
P_0c0c26e8: /* original d34e, guest PC 0x0c0c26e8 */
if(!s->budget--) { s->failed_pc=0x0c0c26e8u; return 0; }
r[3]=read(ram,0x0c0c2824u,4);
goto P_0c0c26ea;
P_0c0c26ea: /* original d64f, guest PC 0x0c0c26ea */
if(!s->budget--) { s->failed_pc=0x0c0c26eau; return 0; }
r[6]=read(ram,0x0c0c2828u,4);
goto P_0c0c26ec;
P_0c0c26ec: /* original 420b, guest PC 0x0c0c26ec */
if(!s->budget--) { s->failed_pc=0x0c0c26ecu; return 0; }
target=r[2];
r[16]=0x0c0c26f0u;
write(ram,r[14]+12,r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c26f0u) { target=s->pc; goto dispatch; }
goto P_0c0c26f0;
P_0c0c26ee: /* original 1e33, guest PC 0x0c0c26ee */
if(!s->budget--) { s->failed_pc=0x0c0c26eeu; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c0c26f0;
P_0c0c26f0: /* original 4f26, guest PC 0x0c0c26f0 */
if(!s->budget--) { s->failed_pc=0x0c0c26f0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c26f2;
P_0c0c26f2: /* original e000, guest PC 0x0c0c26f2 */
if(!s->budget--) { s->failed_pc=0x0c0c26f2u; return 0; }
r[0]=0x00000000u;
goto P_0c0c26f4;
P_0c0c26f4: /* original 81ec, guest PC 0x0c0c26f4 */
if(!s->budget--) { s->failed_pc=0x0c0c26f4u; return 0; }
write(ram,r[14]+24,r[0],2);
goto P_0c0c26f6;
P_0c0c26f6: /* original 000b, guest PC 0x0c0c26f6 */
if(!s->budget--) { s->failed_pc=0x0c0c26f6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c26f8: /* original 6ef6, guest PC 0x0c0c26f8 */
if(!s->budget--) { s->failed_pc=0x0c0c26f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c26fau,s,ram);
unsupported: s->failed_pc=target; return 0;
}
