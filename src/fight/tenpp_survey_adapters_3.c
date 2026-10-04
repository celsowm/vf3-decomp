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
int vf3_tenpp_survey_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06199cu: goto P_0c06199c;
case 0x0c06199eu: goto P_0c06199e;
case 0x0c0619a0u: goto P_0c0619a0;
case 0x0c0619a2u: goto P_0c0619a2;
case 0x0c0619a4u: goto P_0c0619a4;
case 0x0c0619a6u: goto P_0c0619a6;
case 0x0c0619a8u: goto P_0c0619a8;
case 0x0c0619aau: goto P_0c0619aa;
case 0x0c0619acu: goto P_0c0619ac;
case 0x0c0619aeu: goto P_0c0619ae;
case 0x0c0619b0u: goto P_0c0619b0;
case 0x0c0619b2u: goto P_0c0619b2;
case 0x0c0619b4u: goto P_0c0619b4;
case 0x0c0619b6u: goto P_0c0619b6;
case 0x0c0619b8u: goto P_0c0619b8;
case 0x0c0619bau: goto P_0c0619ba;
case 0x0c0619bcu: goto P_0c0619bc;
case 0x0c0619beu: goto P_0c0619be;
case 0x0c0619c0u: goto P_0c0619c0;
case 0x0c0619c2u: goto P_0c0619c2;
case 0x0c0619c4u: goto P_0c0619c4;
case 0x0c0619c6u: goto P_0c0619c6;
case 0x0c0619c8u: goto P_0c0619c8;
case 0x0c0619cau: goto P_0c0619ca;
case 0x0c0619ccu: goto P_0c0619cc;
case 0x0c0619ceu: goto P_0c0619ce;
case 0x0c0619d2u: goto P_0c0619d2;
case 0x0c0619d4u: goto P_0c0619d4;
case 0x0c0619d6u: goto P_0c0619d6;
case 0x0c0619d8u: goto P_0c0619d8;
case 0x0c0619dau: goto P_0c0619da;
case 0x0c0619dcu: goto P_0c0619dc;
case 0x0c0619deu: goto P_0c0619de;
case 0x0c0619e0u: goto P_0c0619e0;
case 0x0c0619e2u: goto P_0c0619e2;
case 0x0c0619e4u: goto P_0c0619e4;
case 0x0c0619e6u: goto P_0c0619e6;
case 0x0c0619e8u: goto P_0c0619e8;
case 0x0c0619eau: goto P_0c0619ea;
case 0x0c0619ecu: goto P_0c0619ec;
case 0x0c0619eeu: goto P_0c0619ee;
case 0x0c0619f0u: goto P_0c0619f0;
case 0x0c0619f2u: goto P_0c0619f2;
case 0x0c0619f4u: goto P_0c0619f4;
case 0x0c0619f6u: goto P_0c0619f6;
case 0x0c0619f8u: goto P_0c0619f8;
case 0x0c0619fau: goto P_0c0619fa;
case 0x0c0619fcu: goto P_0c0619fc;
case 0x0c0619feu: goto P_0c0619fe;
case 0x0c061a00u: goto P_0c061a00;
case 0x0c061a02u: goto P_0c061a02;
case 0x0c061a04u: goto P_0c061a04;
case 0x0c061a06u: goto P_0c061a06;
case 0x0c061a08u: goto P_0c061a08;
case 0x0c061fcau: goto P_0c061fca;
case 0x0c061fccu: goto P_0c061fcc;
case 0x0c061fceu: goto P_0c061fce;
case 0x0c061fd0u: goto P_0c061fd0;
case 0x0c061fd2u: goto P_0c061fd2;
case 0x0c061fd4u: goto P_0c061fd4;
case 0x0c061fd6u: goto P_0c061fd6;
case 0x0c061fd8u: goto P_0c061fd8;
case 0x0c061fdau: goto P_0c061fda;
case 0x0c061fdcu: goto P_0c061fdc;
case 0x0c061fdeu: goto P_0c061fde;
case 0x0c061fe0u: goto P_0c061fe0;
case 0x0c061fe2u: goto P_0c061fe2;
case 0x0c061fe4u: goto P_0c061fe4;
case 0x0c061fe6u: goto P_0c061fe6;
case 0x0c061fe8u: goto P_0c061fe8;
case 0x0c061feau: goto P_0c061fea;
case 0x0c061fecu: goto P_0c061fec;
case 0x0c061feeu: goto P_0c061fee;
case 0x0c061ff0u: goto P_0c061ff0;
case 0x0c061ff2u: goto P_0c061ff2;
case 0x0c061ff4u: goto P_0c061ff4;
case 0x0c061ff6u: goto P_0c061ff6;
case 0x0c061ff8u: goto P_0c061ff8;
case 0x0c061ffau: goto P_0c061ffa;
case 0x0c061ffcu: goto P_0c061ffc;
case 0x0c061ffeu: goto P_0c061ffe;
case 0x0c062000u: goto P_0c062000;
case 0x0c062002u: goto P_0c062002;
case 0x0c062004u: goto P_0c062004;
case 0x0c062006u: goto P_0c062006;
case 0x0c062008u: goto P_0c062008;
case 0x0c06200au: goto P_0c06200a;
case 0x0c06200cu: goto P_0c06200c;
case 0x0c06200eu: goto P_0c06200e;
case 0x0c062010u: goto P_0c062010;
case 0x0c062012u: goto P_0c062012;
case 0x0c062014u: goto P_0c062014;
case 0x0c062016u: goto P_0c062016;
case 0x0c062018u: goto P_0c062018;
case 0x0c06201au: goto P_0c06201a;
case 0x0c06201cu: goto P_0c06201c;
case 0x0c06201eu: goto P_0c06201e;
case 0x0c062020u: goto P_0c062020;
case 0x0c062022u: goto P_0c062022;
case 0x0c062024u: goto P_0c062024;
case 0x0c062026u: goto P_0c062026;
case 0x0c062028u: goto P_0c062028;
case 0x0c06202au: goto P_0c06202a;
case 0x0c06202cu: goto P_0c06202c;
case 0x0c06202eu: goto P_0c06202e;
case 0x0c062030u: goto P_0c062030;
case 0x0c062032u: goto P_0c062032;
case 0x0c062034u: goto P_0c062034;
case 0x0c062036u: goto P_0c062036;
case 0x0c062038u: goto P_0c062038;
case 0x0c06203au: goto P_0c06203a;
case 0x0c06203cu: goto P_0c06203c;
case 0x0c06203eu: goto P_0c06203e;
case 0x0c062040u: goto P_0c062040;
case 0x0c062042u: goto P_0c062042;
case 0x0c062044u: goto P_0c062044;
case 0x0c062046u: goto P_0c062046;
case 0x0c062048u: goto P_0c062048;
case 0x0c06204au: goto P_0c06204a;
case 0x0c06204cu: goto P_0c06204c;
case 0x0c06204eu: goto P_0c06204e;
case 0x0c062050u: goto P_0c062050;
case 0x0c062052u: goto P_0c062052;
case 0x0c062054u: goto P_0c062054;
case 0x0c062056u: goto P_0c062056;
case 0x0c062058u: goto P_0c062058;
case 0x0c06205au: goto P_0c06205a;
case 0x0c06205cu: goto P_0c06205c;
case 0x0c06205eu: goto P_0c06205e;
case 0x0c062060u: goto P_0c062060;
case 0x0c062062u: goto P_0c062062;
case 0x0c062064u: goto P_0c062064;
case 0x0c062066u: goto P_0c062066;
case 0x0c062068u: goto P_0c062068;
case 0x0c06206au: goto P_0c06206a;
case 0x0c06206cu: goto P_0c06206c;
case 0x0c06206eu: goto P_0c06206e;
case 0x0c062070u: goto P_0c062070;
case 0x0c062072u: goto P_0c062072;
case 0x0c062074u: goto P_0c062074;
case 0x0c062076u: goto P_0c062076;
case 0x0c062078u: goto P_0c062078;
case 0x0c06207au: goto P_0c06207a;
case 0x0c06207cu: goto P_0c06207c;
case 0x0c06207eu: goto P_0c06207e;
case 0x0c062080u: goto P_0c062080;
case 0x0c062082u: goto P_0c062082;
case 0x0c062084u: goto P_0c062084;
case 0x0c062086u: goto P_0c062086;
case 0x0c062088u: goto P_0c062088;
case 0x0c06208au: goto P_0c06208a;
case 0x0c06208cu: goto P_0c06208c;
case 0x0c06208eu: goto P_0c06208e;
case 0x0c062090u: goto P_0c062090;
case 0x0c062092u: goto P_0c062092;
case 0x0c062094u: goto P_0c062094;
case 0x0c062096u: goto P_0c062096;
case 0x0c062098u: goto P_0c062098;
case 0x0c06209au: goto P_0c06209a;
case 0x0c06209cu: goto P_0c06209c;
case 0x0c06209eu: goto P_0c06209e;
case 0x0c0620a0u: goto P_0c0620a0;
case 0x0c0620a2u: goto P_0c0620a2;
case 0x0c0620a4u: goto P_0c0620a4;
case 0x0c0620a6u: goto P_0c0620a6;
case 0x0c0620a8u: goto P_0c0620a8;
case 0x0c0620aau: goto P_0c0620aa;
case 0x0c0620acu: goto P_0c0620ac;
case 0x0c0620aeu: goto P_0c0620ae;
case 0x0c0620b0u: goto P_0c0620b0;
case 0x0c0620b2u: goto P_0c0620b2;
case 0x0c0620b4u: goto P_0c0620b4;
case 0x0c0620b6u: goto P_0c0620b6;
case 0x0c0620b8u: goto P_0c0620b8;
case 0x0c0620bau: goto P_0c0620ba;
case 0x0c0620bcu: goto P_0c0620bc;
case 0x0c0620beu: goto P_0c0620be;
case 0x0c0620c0u: goto P_0c0620c0;
case 0x0c0620c2u: goto P_0c0620c2;
case 0x0c0620c4u: goto P_0c0620c4;
case 0x0c0620c6u: goto P_0c0620c6;
case 0x0c0620c8u: goto P_0c0620c8;
case 0x0c0620cau: goto P_0c0620ca;
case 0x0c0620ccu: goto P_0c0620cc;
case 0x0c0620ceu: goto P_0c0620ce;
case 0x0c0620d0u: goto P_0c0620d0;
case 0x0c0620d2u: goto P_0c0620d2;
case 0x0c0620d4u: goto P_0c0620d4;
case 0x0c0620d6u: goto P_0c0620d6;
case 0x0c0620d8u: goto P_0c0620d8;
case 0x0c062604u: goto P_0c062604;
case 0x0c062606u: goto P_0c062606;
case 0x0c062608u: goto P_0c062608;
case 0x0c06260au: goto P_0c06260a;
case 0x0c06260cu: goto P_0c06260c;
case 0x0c06260eu: goto P_0c06260e;
case 0x0c062610u: goto P_0c062610;
case 0x0c062612u: goto P_0c062612;
case 0x0c062614u: goto P_0c062614;
case 0x0c062616u: goto P_0c062616;
case 0x0c062618u: goto P_0c062618;
case 0x0c06261au: goto P_0c06261a;
case 0x0c06261cu: goto P_0c06261c;
case 0x0c06261eu: goto P_0c06261e;
case 0x0c062620u: goto P_0c062620;
case 0x0c062622u: goto P_0c062622;
case 0x0c062624u: goto P_0c062624;
case 0x0c062626u: goto P_0c062626;
case 0x0c062628u: goto P_0c062628;
case 0x0c06262au: goto P_0c06262a;
case 0x0c06262cu: goto P_0c06262c;
case 0x0c06262eu: goto P_0c06262e;
case 0x0c062630u: goto P_0c062630;
case 0x0c062632u: goto P_0c062632;
case 0x0c062634u: goto P_0c062634;
case 0x0c062636u: goto P_0c062636;
case 0x0c062638u: goto P_0c062638;
case 0x0c06263au: goto P_0c06263a;
case 0x0c06263cu: goto P_0c06263c;
case 0x0c06263eu: goto P_0c06263e;
case 0x0c062640u: goto P_0c062640;
case 0x0c062642u: goto P_0c062642;
case 0x0c062644u: goto P_0c062644;
case 0x0c062646u: goto P_0c062646;
case 0x0c062648u: goto P_0c062648;
case 0x0c06264au: goto P_0c06264a;
case 0x0c06264cu: goto P_0c06264c;
case 0x0c06264eu: goto P_0c06264e;
case 0x0c062650u: goto P_0c062650;
case 0x0c062652u: goto P_0c062652;
case 0x0c062654u: goto P_0c062654;
case 0x0c062656u: goto P_0c062656;
case 0x0c062658u: goto P_0c062658;
case 0x0c06265au: goto P_0c06265a;
case 0x0c06265cu: goto P_0c06265c;
case 0x0c06265eu: goto P_0c06265e;
case 0x0c062660u: goto P_0c062660;
case 0x0c062662u: goto P_0c062662;
case 0x0c062664u: goto P_0c062664;
case 0x0c062666u: goto P_0c062666;
case 0x0c062668u: goto P_0c062668;
case 0x0c06266au: goto P_0c06266a;
case 0x0c06266cu: goto P_0c06266c;
case 0x0c06266eu: goto P_0c06266e;
case 0x0c062670u: goto P_0c062670;
case 0x0c062672u: goto P_0c062672;
case 0x0c062674u: goto P_0c062674;
case 0x0c062676u: goto P_0c062676;
case 0x0c062678u: goto P_0c062678;
case 0x0c06267au: goto P_0c06267a;
case 0x0c06267cu: goto P_0c06267c;
case 0x0c06267eu: goto P_0c06267e;
case 0x0c062680u: goto P_0c062680;
case 0x0c062682u: goto P_0c062682;
case 0x0c062684u: goto P_0c062684;
case 0x0c062686u: goto P_0c062686;
case 0x0c062688u: goto P_0c062688;
case 0x0c06268au: goto P_0c06268a;
case 0x0c06268cu: goto P_0c06268c;
case 0x0c06268eu: goto P_0c06268e;
case 0x0c062690u: goto P_0c062690;
case 0x0c062692u: goto P_0c062692;
case 0x0c062694u: goto P_0c062694;
case 0x0c062696u: goto P_0c062696;
case 0x0c062698u: goto P_0c062698;
case 0x0c06269au: goto P_0c06269a;
case 0x0c06269cu: goto P_0c06269c;
case 0x0c06269eu: goto P_0c06269e;
case 0x0c0626a0u: goto P_0c0626a0;
case 0x0c0626a2u: goto P_0c0626a2;
case 0x0c0626b0u: goto P_0c0626b0;
case 0x0c0626b2u: goto P_0c0626b2;
case 0x0c0626b4u: goto P_0c0626b4;
case 0x0c0626b6u: goto P_0c0626b6;
case 0x0c0626b8u: goto P_0c0626b8;
case 0x0c0626bau: goto P_0c0626ba;
case 0x0c0626bcu: goto P_0c0626bc;
case 0x0c0626beu: goto P_0c0626be;
case 0x0c062df4u: goto P_0c062df4;
case 0x0c062df6u: goto P_0c062df6;
case 0x0c062df8u: goto P_0c062df8;
case 0x0c062dfau: goto P_0c062dfa;
case 0x0c062dfcu: goto P_0c062dfc;
case 0x0c062dfeu: goto P_0c062dfe;
case 0x0c062e00u: goto P_0c062e00;
case 0x0c062e02u: goto P_0c062e02;
case 0x0c062e04u: goto P_0c062e04;
case 0x0c062e06u: goto P_0c062e06;
case 0x0c062e08u: goto P_0c062e08;
case 0x0c062e0au: goto P_0c062e0a;
case 0x0c062e0cu: goto P_0c062e0c;
case 0x0c062e0eu: goto P_0c062e0e;
case 0x0c062e10u: goto P_0c062e10;
case 0x0c062e12u: goto P_0c062e12;
case 0x0c062e14u: goto P_0c062e14;
case 0x0c062e16u: goto P_0c062e16;
case 0x0c062e18u: goto P_0c062e18;
case 0x0c062e1au: goto P_0c062e1a;
case 0x0c062e1cu: goto P_0c062e1c;
case 0x0c062e1eu: goto P_0c062e1e;
case 0x0c062e20u: goto P_0c062e20;
case 0x0c062e22u: goto P_0c062e22;
case 0x0c062e24u: goto P_0c062e24;
case 0x0c062e26u: goto P_0c062e26;
case 0x0c062e28u: goto P_0c062e28;
case 0x0c062e2au: goto P_0c062e2a;
case 0x0c062e2cu: goto P_0c062e2c;
case 0x0c062e2eu: goto P_0c062e2e;
case 0x0c062e30u: goto P_0c062e30;
case 0x0c062e32u: goto P_0c062e32;
case 0x0c062ec4u: goto P_0c062ec4;
case 0x0c062ec6u: goto P_0c062ec6;
case 0x0c062ec8u: goto P_0c062ec8;
case 0x0c062ecau: goto P_0c062eca;
case 0x0c062eccu: goto P_0c062ecc;
case 0x0c062eceu: goto P_0c062ece;
case 0x0c062ed0u: goto P_0c062ed0;
case 0x0c062ed2u: goto P_0c062ed2;
case 0x0c062ed4u: goto P_0c062ed4;
case 0x0c062ed6u: goto P_0c062ed6;
case 0x0c062ed8u: goto P_0c062ed8;
case 0x0c062edau: goto P_0c062eda;
case 0x0c062edcu: goto P_0c062edc;
case 0x0c062edeu: goto P_0c062ede;
case 0x0c062ee0u: goto P_0c062ee0;
case 0x0c062ee2u: goto P_0c062ee2;
case 0x0c062ee4u: goto P_0c062ee4;
case 0x0c062ee6u: goto P_0c062ee6;
case 0x0c062ee8u: goto P_0c062ee8;
case 0x0c062eeau: goto P_0c062eea;
case 0x0c062eecu: goto P_0c062eec;
case 0x0c062eeeu: goto P_0c062eee;
case 0x0c062ef0u: goto P_0c062ef0;
case 0x0c062ef2u: goto P_0c062ef2;
case 0x0c062ef4u: goto P_0c062ef4;
case 0x0c062ef8u: goto P_0c062ef8;
case 0x0c062efau: goto P_0c062efa;
case 0x0c062efcu: goto P_0c062efc;
case 0x0c062efeu: goto P_0c062efe;
case 0x0c062f00u: goto P_0c062f00;
case 0x0c062f02u: goto P_0c062f02;
case 0x0c062f04u: goto P_0c062f04;
case 0x0c062f06u: goto P_0c062f06;
case 0x0c062f08u: goto P_0c062f08;
case 0x0c062f0au: goto P_0c062f0a;
case 0x0c062f0cu: goto P_0c062f0c;
case 0x0c062f0eu: goto P_0c062f0e;
case 0x0c062f10u: goto P_0c062f10;
case 0x0c062f12u: goto P_0c062f12;
case 0x0c062f14u: goto P_0c062f14;
case 0x0c062f16u: goto P_0c062f16;
case 0x0c062f18u: goto P_0c062f18;
case 0x0c062f1au: goto P_0c062f1a;
case 0x0c062f1cu: goto P_0c062f1c;
case 0x0c062f1eu: goto P_0c062f1e;
case 0x0c062f20u: goto P_0c062f20;
case 0x0c062f22u: goto P_0c062f22;
case 0x0c062f24u: goto P_0c062f24;
case 0x0c062f26u: goto P_0c062f26;
case 0x0c062f28u: goto P_0c062f28;
case 0x0c062f2au: goto P_0c062f2a;
case 0x0c062f2cu: goto P_0c062f2c;
case 0x0c062f2eu: goto P_0c062f2e;
case 0x0c062f30u: goto P_0c062f30;
case 0x0c062f32u: goto P_0c062f32;
case 0x0c062f34u: goto P_0c062f34;
case 0x0c062f36u: goto P_0c062f36;
case 0x0c062f38u: goto P_0c062f38;
case 0x0c062f3au: goto P_0c062f3a;
case 0x0c062f3cu: goto P_0c062f3c;
case 0x0c062f3eu: goto P_0c062f3e;
case 0x0c062f40u: goto P_0c062f40;
case 0x0c062f42u: goto P_0c062f42;
case 0x0c062f44u: goto P_0c062f44;
case 0x0c062f46u: goto P_0c062f46;
case 0x0c062f48u: goto P_0c062f48;
case 0x0c062f4au: goto P_0c062f4a;
case 0x0c062f4cu: goto P_0c062f4c;
case 0x0c062f4eu: goto P_0c062f4e;
case 0x0c062f50u: goto P_0c062f50;
case 0x0c062f52u: goto P_0c062f52;
case 0x0c062f54u: goto P_0c062f54;
case 0x0c062f56u: goto P_0c062f56;
case 0x0c062f58u: goto P_0c062f58;
case 0x0c062f5au: goto P_0c062f5a;
case 0x0c062f5cu: goto P_0c062f5c;
case 0x0c062f5eu: goto P_0c062f5e;
case 0x0c0636acu: goto P_0c0636ac;
case 0x0c0636aeu: goto P_0c0636ae;
case 0x0c0636b0u: goto P_0c0636b0;
case 0x0c0636b2u: goto P_0c0636b2;
case 0x0c0636b4u: goto P_0c0636b4;
case 0x0c0636b6u: goto P_0c0636b6;
case 0x0c0636b8u: goto P_0c0636b8;
case 0x0c0636bau: goto P_0c0636ba;
case 0x0c0636bcu: goto P_0c0636bc;
case 0x0c0636beu: goto P_0c0636be;
case 0x0c0636c0u: goto P_0c0636c0;
case 0x0c0636c2u: goto P_0c0636c2;
case 0x0c0636c4u: goto P_0c0636c4;
case 0x0c0636c6u: goto P_0c0636c6;
case 0x0c0636c8u: goto P_0c0636c8;
case 0x0c0636cau: goto P_0c0636ca;
case 0x0c0636ccu: goto P_0c0636cc;
case 0x0c0636ceu: goto P_0c0636ce;
case 0x0c0636d0u: goto P_0c0636d0;
case 0x0c0636d2u: goto P_0c0636d2;
case 0x0c0636d4u: goto P_0c0636d4;
case 0x0c0636d6u: goto P_0c0636d6;
case 0x0c0636d8u: goto P_0c0636d8;
case 0x0c0636dau: goto P_0c0636da;
case 0x0c0636dcu: goto P_0c0636dc;
case 0x0c0636deu: goto P_0c0636de;
case 0x0c0636e0u: goto P_0c0636e0;
case 0x0c0636e2u: goto P_0c0636e2;
case 0x0c0636e4u: goto P_0c0636e4;
case 0x0c0636e6u: goto P_0c0636e6;
case 0x0c0636e8u: goto P_0c0636e8;
case 0x0c0636eau: goto P_0c0636ea;
case 0x0c0636ecu: goto P_0c0636ec;
case 0x0c0636eeu: goto P_0c0636ee;
case 0x0c0636f0u: goto P_0c0636f0;
case 0x0c0636f2u: goto P_0c0636f2;
case 0x0c0636f4u: goto P_0c0636f4;
case 0x0c0636f6u: goto P_0c0636f6;
case 0x0c0636f8u: goto P_0c0636f8;
case 0x0c0636fau: goto P_0c0636fa;
case 0x0c0636fcu: goto P_0c0636fc;
case 0x0c06371cu: goto P_0c06371c;
case 0x0c06371eu: goto P_0c06371e;
case 0x0c063720u: goto P_0c063720;
case 0x0c063722u: goto P_0c063722;
case 0x0c063724u: goto P_0c063724;
case 0x0c063726u: goto P_0c063726;
case 0x0c063728u: goto P_0c063728;
case 0x0c06372au: goto P_0c06372a;
case 0x0c06372cu: goto P_0c06372c;
case 0x0c06372eu: goto P_0c06372e;
case 0x0c063730u: goto P_0c063730;
case 0x0c063732u: goto P_0c063732;
case 0x0c063734u: goto P_0c063734;
case 0x0c063736u: goto P_0c063736;
case 0x0c063738u: goto P_0c063738;
case 0x0c06373au: goto P_0c06373a;
case 0x0c06373cu: goto P_0c06373c;
case 0x0c06373eu: goto P_0c06373e;
case 0x0c063740u: goto P_0c063740;
case 0x0c063742u: goto P_0c063742;
case 0x0c063744u: goto P_0c063744;
case 0x0c063746u: goto P_0c063746;
case 0x0c063748u: goto P_0c063748;
case 0x0c06374au: goto P_0c06374a;
case 0x0c06374cu: goto P_0c06374c;
case 0x0c06374eu: goto P_0c06374e;
case 0x0c063750u: goto P_0c063750;
case 0x0c063752u: goto P_0c063752;
case 0x0c063754u: goto P_0c063754;
case 0x0c063756u: goto P_0c063756;
case 0x0c063758u: goto P_0c063758;
case 0x0c06375au: goto P_0c06375a;
case 0x0c06375cu: goto P_0c06375c;
case 0x0c06375eu: goto P_0c06375e;
case 0x0c063760u: goto P_0c063760;
case 0x0c063762u: goto P_0c063762;
case 0x0c063764u: goto P_0c063764;
case 0x0c063766u: goto P_0c063766;
case 0x0c063768u: goto P_0c063768;
case 0x0c06376au: goto P_0c06376a;
case 0x0c0645fau: goto P_0c0645fa;
case 0x0c0645fcu: goto P_0c0645fc;
case 0x0c0645feu: goto P_0c0645fe;
case 0x0c064600u: goto P_0c064600;
case 0x0c064602u: goto P_0c064602;
case 0x0c064604u: goto P_0c064604;
case 0x0c064606u: goto P_0c064606;
case 0x0c064608u: goto P_0c064608;
case 0x0c06460au: goto P_0c06460a;
case 0x0c06460cu: goto P_0c06460c;
case 0x0c06460eu: goto P_0c06460e;
case 0x0c064610u: goto P_0c064610;
case 0x0c064612u: goto P_0c064612;
case 0x0c064614u: goto P_0c064614;
case 0x0c064616u: goto P_0c064616;
case 0x0c064618u: goto P_0c064618;
case 0x0c06461au: goto P_0c06461a;
case 0x0c06461cu: goto P_0c06461c;
case 0x0c06461eu: goto P_0c06461e;
case 0x0c064620u: goto P_0c064620;
case 0x0c064622u: goto P_0c064622;
case 0x0c064624u: goto P_0c064624;
case 0x0c064626u: goto P_0c064626;
case 0x0c064628u: goto P_0c064628;
case 0x0c06462au: goto P_0c06462a;
case 0x0c06462cu: goto P_0c06462c;
case 0x0c06462eu: goto P_0c06462e;
case 0x0c064630u: goto P_0c064630;
case 0x0c064632u: goto P_0c064632;
case 0x0c064634u: goto P_0c064634;
case 0x0c064636u: goto P_0c064636;
case 0x0c064638u: goto P_0c064638;
case 0x0c06463au: goto P_0c06463a;
case 0x0c06463cu: goto P_0c06463c;
case 0x0c06463eu: goto P_0c06463e;
case 0x0c064640u: goto P_0c064640;
case 0x0c064642u: goto P_0c064642;
case 0x0c064644u: goto P_0c064644;
case 0x0c064646u: goto P_0c064646;
case 0x0c064648u: goto P_0c064648;
case 0x0c06464au: goto P_0c06464a;
case 0x0c06464cu: goto P_0c06464c;
case 0x0c06464eu: goto P_0c06464e;
case 0x0c064650u: goto P_0c064650;
case 0x0c064652u: goto P_0c064652;
case 0x0c064654u: goto P_0c064654;
case 0x0c064656u: goto P_0c064656;
case 0x0c064658u: goto P_0c064658;
case 0x0c06465au: goto P_0c06465a;
case 0x0c06465cu: goto P_0c06465c;
case 0x0c06465eu: goto P_0c06465e;
case 0x0c064660u: goto P_0c064660;
case 0x0c064662u: goto P_0c064662;
case 0x0c064664u: goto P_0c064664;
case 0x0c064666u: goto P_0c064666;
case 0x0c064668u: goto P_0c064668;
case 0x0c06466au: goto P_0c06466a;
case 0x0c06466cu: goto P_0c06466c;
case 0x0c06466eu: goto P_0c06466e;
case 0x0c064670u: goto P_0c064670;
case 0x0c064672u: goto P_0c064672;
case 0x0c064674u: goto P_0c064674;
case 0x0c064676u: goto P_0c064676;
case 0x0c064678u: goto P_0c064678;
case 0x0c06467au: goto P_0c06467a;
case 0x0c06467cu: goto P_0c06467c;
case 0x0c06467eu: goto P_0c06467e;
case 0x0c064680u: goto P_0c064680;
case 0x0c064682u: goto P_0c064682;
case 0x0c064684u: goto P_0c064684;
case 0x0c064686u: goto P_0c064686;
case 0x0c064688u: goto P_0c064688;
case 0x0c06468au: goto P_0c06468a;
case 0x0c06468cu: goto P_0c06468c;
case 0x0c06468eu: goto P_0c06468e;
case 0x0c064690u: goto P_0c064690;
case 0x0c064692u: goto P_0c064692;
case 0x0c064694u: goto P_0c064694;
case 0x0c064696u: goto P_0c064696;
case 0x0c064698u: goto P_0c064698;
case 0x0c06469au: goto P_0c06469a;
case 0x0c06469cu: goto P_0c06469c;
case 0x0c06469eu: goto P_0c06469e;
case 0x0c0646a0u: goto P_0c0646a0;
case 0x0c0646a2u: goto P_0c0646a2;
case 0x0c0646a4u: goto P_0c0646a4;
case 0x0c0646a6u: goto P_0c0646a6;
case 0x0c0646a8u: goto P_0c0646a8;
case 0x0c0646aau: goto P_0c0646aa;
case 0x0c0646acu: goto P_0c0646ac;
case 0x0c0646aeu: goto P_0c0646ae;
case 0x0c0646b0u: goto P_0c0646b0;
case 0x0c0646b2u: goto P_0c0646b2;
case 0x0c0646b4u: goto P_0c0646b4;
case 0x0c0646b6u: goto P_0c0646b6;
case 0x0c0646b8u: goto P_0c0646b8;
case 0x0c0646bau: goto P_0c0646ba;
case 0x0c0646bcu: goto P_0c0646bc;
case 0x0c0646beu: goto P_0c0646be;
case 0x0c0646c0u: goto P_0c0646c0;
case 0x0c0646c2u: goto P_0c0646c2;
case 0x0c0646c4u: goto P_0c0646c4;
case 0x0c0646c6u: goto P_0c0646c6;
case 0x0c0646c8u: goto P_0c0646c8;
case 0x0c0646cau: goto P_0c0646ca;
case 0x0c0646ccu: goto P_0c0646cc;
case 0x0c0646ceu: goto P_0c0646ce;
case 0x0c0646d0u: goto P_0c0646d0;
case 0x0c0646d2u: goto P_0c0646d2;
case 0x0c0646d4u: goto P_0c0646d4;
case 0x0c0646d6u: goto P_0c0646d6;
case 0x0c0646d8u: goto P_0c0646d8;
case 0x0c0646dau: goto P_0c0646da;
case 0x0c0646dcu: goto P_0c0646dc;
case 0x0c0646deu: goto P_0c0646de;
case 0x0c0646e0u: goto P_0c0646e0;
case 0x0c0646e2u: goto P_0c0646e2;
case 0x0c0646e4u: goto P_0c0646e4;
case 0x0c0646e6u: goto P_0c0646e6;
case 0x0c0646e8u: goto P_0c0646e8;
case 0x0c0646eau: goto P_0c0646ea;
case 0x0c0646ecu: goto P_0c0646ec;
case 0x0c0646eeu: goto P_0c0646ee;
case 0x0c0646f0u: goto P_0c0646f0;
case 0x0c0646f2u: goto P_0c0646f2;
case 0x0c0646f4u: goto P_0c0646f4;
case 0x0c0646f6u: goto P_0c0646f6;
case 0x0c066a2cu: goto P_0c066a2c;
case 0x0c066a2eu: goto P_0c066a2e;
case 0x0c066a30u: goto P_0c066a30;
case 0x0c066a32u: goto P_0c066a32;
case 0x0c066a34u: goto P_0c066a34;
case 0x0c066a36u: goto P_0c066a36;
case 0x0c066a38u: goto P_0c066a38;
case 0x0c066a3au: goto P_0c066a3a;
case 0x0c066a3cu: goto P_0c066a3c;
case 0x0c066a3eu: goto P_0c066a3e;
case 0x0c066a40u: goto P_0c066a40;
case 0x0c066a42u: goto P_0c066a42;
case 0x0c066a44u: goto P_0c066a44;
case 0x0c066a46u: goto P_0c066a46;
case 0x0c066a48u: goto P_0c066a48;
case 0x0c066a4au: goto P_0c066a4a;
case 0x0c066a4cu: goto P_0c066a4c;
case 0x0c066a4eu: goto P_0c066a4e;
case 0x0c066a50u: goto P_0c066a50;
case 0x0c066a52u: goto P_0c066a52;
case 0x0c066a54u: goto P_0c066a54;
case 0x0c066a56u: goto P_0c066a56;
case 0x0c066a58u: goto P_0c066a58;
case 0x0c066a5au: goto P_0c066a5a;
case 0x0c066a5cu: goto P_0c066a5c;
case 0x0c066a5eu: goto P_0c066a5e;
case 0x0c066a60u: goto P_0c066a60;
case 0x0c066a62u: goto P_0c066a62;
case 0x0c066a64u: goto P_0c066a64;
case 0x0c066cd8u: goto P_0c066cd8;
case 0x0c066cdau: goto P_0c066cda;
case 0x0c066cdcu: goto P_0c066cdc;
case 0x0c066cdeu: goto P_0c066cde;
case 0x0c066ce0u: goto P_0c066ce0;
case 0x0c066ce2u: goto P_0c066ce2;
case 0x0c066ce4u: goto P_0c066ce4;
case 0x0c066ce6u: goto P_0c066ce6;
case 0x0c066ce8u: goto P_0c066ce8;
case 0x0c066ceau: goto P_0c066cea;
case 0x0c0696c6u: goto P_0c0696c6;
case 0x0c0696c8u: goto P_0c0696c8;
case 0x0c0696cau: goto P_0c0696ca;
case 0x0c0696ccu: goto P_0c0696cc;
case 0x0c0696ceu: goto P_0c0696ce;
case 0x0c0696d0u: goto P_0c0696d0;
case 0x0c0696d2u: goto P_0c0696d2;
case 0x0c0696d4u: goto P_0c0696d4;
case 0x0c0696d6u: goto P_0c0696d6;
case 0x0c0696d8u: goto P_0c0696d8;
case 0x0c0696dau: goto P_0c0696da;
case 0x0c0696dcu: goto P_0c0696dc;
case 0x0c0696deu: goto P_0c0696de;
case 0x0c0696e0u: goto P_0c0696e0;
case 0x0c0696e2u: goto P_0c0696e2;
case 0x0c0696e4u: goto P_0c0696e4;
case 0x0c069702u: goto P_0c069702;
case 0x0c069704u: goto P_0c069704;
case 0x0c069706u: goto P_0c069706;
case 0x0c069708u: goto P_0c069708;
case 0x0c06970au: goto P_0c06970a;
case 0x0c06970cu: goto P_0c06970c;
case 0x0c06970eu: goto P_0c06970e;
case 0x0c069710u: goto P_0c069710;
case 0x0c069712u: goto P_0c069712;
case 0x0c069714u: goto P_0c069714;
case 0x0c069716u: goto P_0c069716;
case 0x0c069718u: goto P_0c069718;
case 0x0c06971au: goto P_0c06971a;
case 0x0c06971cu: goto P_0c06971c;
case 0x0c06971eu: goto P_0c06971e;
case 0x0c069720u: goto P_0c069720;
case 0x0c069722u: goto P_0c069722;
case 0x0c069724u: goto P_0c069724;
case 0x0c069726u: goto P_0c069726;
case 0x0c069728u: goto P_0c069728;
case 0x0c06a5eeu: goto P_0c06a5ee;
case 0x0c06a5f0u: goto P_0c06a5f0;
case 0x0c06a5f2u: goto P_0c06a5f2;
case 0x0c06a5f4u: goto P_0c06a5f4;
case 0x0c06a5f6u: goto P_0c06a5f6;
case 0x0c06a5f8u: goto P_0c06a5f8;
case 0x0c06a5fau: goto P_0c06a5fa;
case 0x0c06a5fcu: goto P_0c06a5fc;
case 0x0c06a5feu: goto P_0c06a5fe;
case 0x0c06a600u: goto P_0c06a600;
case 0x0c06a602u: goto P_0c06a602;
case 0x0c06a604u: goto P_0c06a604;
case 0x0c06a606u: goto P_0c06a606;
case 0x0c06a608u: goto P_0c06a608;
case 0x0c06a60au: goto P_0c06a60a;
case 0x0c06a60cu: goto P_0c06a60c;
case 0x0c06a60eu: goto P_0c06a60e;
case 0x0c06a610u: goto P_0c06a610;
case 0x0c06a612u: goto P_0c06a612;
case 0x0c06a614u: goto P_0c06a614;
case 0x0c06a616u: goto P_0c06a616;
case 0x0c06a618u: goto P_0c06a618;
case 0x0c06a61au: goto P_0c06a61a;
case 0x0c06a61cu: goto P_0c06a61c;
case 0x0c06a61eu: goto P_0c06a61e;
case 0x0c06a620u: goto P_0c06a620;
case 0x0c06a622u: goto P_0c06a622;
case 0x0c06a624u: goto P_0c06a624;
case 0x0c06a626u: goto P_0c06a626;
case 0x0c06a628u: goto P_0c06a628;
case 0x0c06a62au: goto P_0c06a62a;
case 0x0c06a62cu: goto P_0c06a62c;
case 0x0c06a62eu: goto P_0c06a62e;
case 0x0c06a630u: goto P_0c06a630;
case 0x0c06a632u: goto P_0c06a632;
case 0x0c06a634u: goto P_0c06a634;
case 0x0c06a636u: goto P_0c06a636;
case 0x0c06a638u: goto P_0c06a638;
case 0x0c06a63au: goto P_0c06a63a;
case 0x0c06a63cu: goto P_0c06a63c;
case 0x0c06a63eu: goto P_0c06a63e;
case 0x0c06a640u: goto P_0c06a640;
case 0x0c06a642u: goto P_0c06a642;
case 0x0c06a644u: goto P_0c06a644;
case 0x0c06a646u: goto P_0c06a646;
case 0x0c06a648u: goto P_0c06a648;
case 0x0c06a64au: goto P_0c06a64a;
case 0x0c06a64cu: goto P_0c06a64c;
case 0x0c06a64eu: goto P_0c06a64e;
case 0x0c06a650u: goto P_0c06a650;
case 0x0c06a652u: goto P_0c06a652;
case 0x0c06a654u: goto P_0c06a654;
case 0x0c06a656u: goto P_0c06a656;
case 0x0c06a658u: goto P_0c06a658;
case 0x0c06a65au: goto P_0c06a65a;
case 0x0c06a65cu: goto P_0c06a65c;
case 0x0c06a65eu: goto P_0c06a65e;
case 0x0c06a660u: goto P_0c06a660;
case 0x0c06a662u: goto P_0c06a662;
case 0x0c06a664u: goto P_0c06a664;
case 0x0c06a666u: goto P_0c06a666;
case 0x0c06a668u: goto P_0c06a668;
case 0x0c06a66au: goto P_0c06a66a;
case 0x0c06be34u: goto P_0c06be34;
case 0x0c06be36u: goto P_0c06be36;
case 0x0c06be38u: goto P_0c06be38;
case 0x0c06be3au: goto P_0c06be3a;
case 0x0c06be3cu: goto P_0c06be3c;
case 0x0c06be3eu: goto P_0c06be3e;
case 0x0c06be40u: goto P_0c06be40;
case 0x0c06be42u: goto P_0c06be42;
case 0x0c06be44u: goto P_0c06be44;
case 0x0c06be46u: goto P_0c06be46;
case 0x0c06be48u: goto P_0c06be48;
case 0x0c06be4au: goto P_0c06be4a;
case 0x0c06be4cu: goto P_0c06be4c;
case 0x0c06be4eu: goto P_0c06be4e;
case 0x0c06be50u: goto P_0c06be50;
case 0x0c06be52u: goto P_0c06be52;
case 0x0c06be54u: goto P_0c06be54;
case 0x0c06be56u: goto P_0c06be56;
case 0x0c06be58u: goto P_0c06be58;
case 0x0c06be5au: goto P_0c06be5a;
case 0x0c06be5cu: goto P_0c06be5c;
case 0x0c06be5eu: goto P_0c06be5e;
case 0x0c06cf20u: goto P_0c06cf20;
case 0x0c06cf22u: goto P_0c06cf22;
case 0x0c06cf24u: goto P_0c06cf24;
case 0x0c06cf26u: goto P_0c06cf26;
case 0x0c06cf28u: goto P_0c06cf28;
case 0x0c06cf2au: goto P_0c06cf2a;
case 0x0c06cf2cu: goto P_0c06cf2c;
case 0x0c06cf2eu: goto P_0c06cf2e;
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
case 0x0c073268u: goto P_0c073268;
case 0x0c07326au: goto P_0c07326a;
case 0x0c07326cu: goto P_0c07326c;
case 0x0c07326eu: goto P_0c07326e;
case 0x0c073270u: goto P_0c073270;
case 0x0c073272u: goto P_0c073272;
case 0x0c073274u: goto P_0c073274;
case 0x0c073276u: goto P_0c073276;
case 0x0c073278u: goto P_0c073278;
case 0x0c07327au: goto P_0c07327a;
case 0x0c07327cu: goto P_0c07327c;
case 0x0c07327eu: goto P_0c07327e;
case 0x0c073280u: goto P_0c073280;
case 0x0c073282u: goto P_0c073282;
case 0x0c073284u: goto P_0c073284;
case 0x0c073286u: goto P_0c073286;
case 0x0c073288u: goto P_0c073288;
case 0x0c07328au: goto P_0c07328a;
case 0x0c07328cu: goto P_0c07328c;
case 0x0c07328eu: goto P_0c07328e;
case 0x0c073290u: goto P_0c073290;
case 0x0c073292u: goto P_0c073292;
case 0x0c073294u: goto P_0c073294;
case 0x0c073296u: goto P_0c073296;
case 0x0c073298u: goto P_0c073298;
case 0x0c07329au: goto P_0c07329a;
case 0x0c07329cu: goto P_0c07329c;
case 0x0c07329eu: goto P_0c07329e;
case 0x0c0732a0u: goto P_0c0732a0;
case 0x0c0732a2u: goto P_0c0732a2;
case 0x0c0732a4u: goto P_0c0732a4;
case 0x0c0732a6u: goto P_0c0732a6;
case 0x0c0732a8u: goto P_0c0732a8;
case 0x0c0732aau: goto P_0c0732aa;
case 0x0c0732acu: goto P_0c0732ac;
case 0x0c0732aeu: goto P_0c0732ae;
case 0x0c0732b0u: goto P_0c0732b0;
case 0x0c0732b2u: goto P_0c0732b2;
case 0x0c0732b4u: goto P_0c0732b4;
case 0x0c0732b6u: goto P_0c0732b6;
case 0x0c0732c8u: goto P_0c0732c8;
case 0x0c0732cau: goto P_0c0732ca;
case 0x0c0732ccu: goto P_0c0732cc;
case 0x0c0732ceu: goto P_0c0732ce;
case 0x0c0732d0u: goto P_0c0732d0;
case 0x0c0732d2u: goto P_0c0732d2;
case 0x0c0732d4u: goto P_0c0732d4;
case 0x0c0732d6u: goto P_0c0732d6;
case 0x0c0732d8u: goto P_0c0732d8;
case 0x0c0732dau: goto P_0c0732da;
case 0x0c0732dcu: goto P_0c0732dc;
case 0x0c0732deu: goto P_0c0732de;
case 0x0c0732e0u: goto P_0c0732e0;
case 0x0c0732e2u: goto P_0c0732e2;
case 0x0c0732e4u: goto P_0c0732e4;
case 0x0c0732e6u: goto P_0c0732e6;
case 0x0c0732e8u: goto P_0c0732e8;
case 0x0c0732eau: goto P_0c0732ea;
case 0x0c0732ecu: goto P_0c0732ec;
case 0x0c0732eeu: goto P_0c0732ee;
case 0x0c0732f0u: goto P_0c0732f0;
case 0x0c0732f2u: goto P_0c0732f2;
case 0x0c0732f4u: goto P_0c0732f4;
case 0x0c0732f6u: goto P_0c0732f6;
case 0x0c0732f8u: goto P_0c0732f8;
case 0x0c0732fau: goto P_0c0732fa;
case 0x0c0732fcu: goto P_0c0732fc;
case 0x0c0732feu: goto P_0c0732fe;
case 0x0c073300u: goto P_0c073300;
case 0x0c073302u: goto P_0c073302;
case 0x0c073304u: goto P_0c073304;
case 0x0c073306u: goto P_0c073306;
case 0x0c073308u: goto P_0c073308;
case 0x0c07330au: goto P_0c07330a;
case 0x0c07330cu: goto P_0c07330c;
case 0x0c07330eu: goto P_0c07330e;
case 0x0c073310u: goto P_0c073310;
case 0x0c073312u: goto P_0c073312;
case 0x0c073314u: goto P_0c073314;
case 0x0c073316u: goto P_0c073316;
case 0x0c073318u: goto P_0c073318;
case 0x0c07331au: goto P_0c07331a;
case 0x0c07331cu: goto P_0c07331c;
case 0x0c07331eu: goto P_0c07331e;
case 0x0c073320u: goto P_0c073320;
case 0x0c073322u: goto P_0c073322;
case 0x0c073324u: goto P_0c073324;
case 0x0c073326u: goto P_0c073326;
case 0x0c073328u: goto P_0c073328;
case 0x0c07332au: goto P_0c07332a;
case 0x0c07332cu: goto P_0c07332c;
case 0x0c07332eu: goto P_0c07332e;
case 0x0c073330u: goto P_0c073330;
case 0x0c073332u: goto P_0c073332;
case 0x0c073334u: goto P_0c073334;
case 0x0c073336u: goto P_0c073336;
case 0x0c073338u: goto P_0c073338;
case 0x0c07333au: goto P_0c07333a;
case 0x0c07333cu: goto P_0c07333c;
case 0x0c07333eu: goto P_0c07333e;
case 0x0c073340u: goto P_0c073340;
case 0x0c073342u: goto P_0c073342;
case 0x0c073344u: goto P_0c073344;
case 0x0c073346u: goto P_0c073346;
case 0x0c073348u: goto P_0c073348;
case 0x0c07334au: goto P_0c07334a;
case 0x0c07334cu: goto P_0c07334c;
case 0x0c07334eu: goto P_0c07334e;
case 0x0c073350u: goto P_0c073350;
case 0x0c073352u: goto P_0c073352;
case 0x0c073354u: goto P_0c073354;
case 0x0c073356u: goto P_0c073356;
case 0x0c073358u: goto P_0c073358;
case 0x0c07335au: goto P_0c07335a;
case 0x0c07335cu: goto P_0c07335c;
case 0x0c07335eu: goto P_0c07335e;
case 0x0c073360u: goto P_0c073360;
case 0x0c073362u: goto P_0c073362;
case 0x0c073364u: goto P_0c073364;
case 0x0c073366u: goto P_0c073366;
case 0x0c073368u: goto P_0c073368;
case 0x0c07336au: goto P_0c07336a;
case 0x0c07336cu: goto P_0c07336c;
case 0x0c07336eu: goto P_0c07336e;
case 0x0c073370u: goto P_0c073370;
case 0x0c073372u: goto P_0c073372;
case 0x0c073374u: goto P_0c073374;
case 0x0c073376u: goto P_0c073376;
case 0x0c073378u: goto P_0c073378;
case 0x0c07337au: goto P_0c07337a;
case 0x0c07337cu: goto P_0c07337c;
case 0x0c07337eu: goto P_0c07337e;
case 0x0c073380u: goto P_0c073380;
case 0x0c073696u: goto P_0c073696;
case 0x0c073698u: goto P_0c073698;
case 0x0c07369au: goto P_0c07369a;
case 0x0c07369cu: goto P_0c07369c;
case 0x0c07369eu: goto P_0c07369e;
case 0x0c0736a0u: goto P_0c0736a0;
case 0x0c0736a2u: goto P_0c0736a2;
case 0x0c0736a4u: goto P_0c0736a4;
case 0x0c0736a6u: goto P_0c0736a6;
case 0x0c0736a8u: goto P_0c0736a8;
case 0x0c0736aau: goto P_0c0736aa;
case 0x0c0736acu: goto P_0c0736ac;
case 0x0c0736aeu: goto P_0c0736ae;
case 0x0c0736b0u: goto P_0c0736b0;
case 0x0c0736b2u: goto P_0c0736b2;
case 0x0c0736b4u: goto P_0c0736b4;
case 0x0c0736b6u: goto P_0c0736b6;
case 0x0c0736b8u: goto P_0c0736b8;
case 0x0c0736bau: goto P_0c0736ba;
case 0x0c0736bcu: goto P_0c0736bc;
case 0x0c0736beu: goto P_0c0736be;
case 0x0c0736c0u: goto P_0c0736c0;
case 0x0c0736c2u: goto P_0c0736c2;
case 0x0c0736c4u: goto P_0c0736c4;
case 0x0c0736c6u: goto P_0c0736c6;
case 0x0c0736c8u: goto P_0c0736c8;
case 0x0c0736cau: goto P_0c0736ca;
case 0x0c0736ccu: goto P_0c0736cc;
case 0x0c0736ceu: goto P_0c0736ce;
case 0x0c0736d0u: goto P_0c0736d0;
case 0x0c07376cu: goto P_0c07376c;
case 0x0c07376eu: goto P_0c07376e;
case 0x0c073770u: goto P_0c073770;
case 0x0c073772u: goto P_0c073772;
case 0x0c073774u: goto P_0c073774;
case 0x0c073776u: goto P_0c073776;
case 0x0c073778u: goto P_0c073778;
case 0x0c07377au: goto P_0c07377a;
case 0x0c07377cu: goto P_0c07377c;
case 0x0c07377eu: goto P_0c07377e;
case 0x0c073780u: goto P_0c073780;
case 0x0c073782u: goto P_0c073782;
case 0x0c073784u: goto P_0c073784;
case 0x0c073786u: goto P_0c073786;
case 0x0c073788u: goto P_0c073788;
case 0x0c07378au: goto P_0c07378a;
case 0x0c07378cu: goto P_0c07378c;
case 0x0c07378eu: goto P_0c07378e;
case 0x0c073790u: goto P_0c073790;
case 0x0c073792u: goto P_0c073792;
case 0x0c073794u: goto P_0c073794;
case 0x0c073796u: goto P_0c073796;
case 0x0c073798u: goto P_0c073798;
case 0x0c07379au: goto P_0c07379a;
case 0x0c07379cu: goto P_0c07379c;
case 0x0c07379eu: goto P_0c07379e;
case 0x0c0737a0u: goto P_0c0737a0;
case 0x0c0737a2u: goto P_0c0737a2;
case 0x0c0737a4u: goto P_0c0737a4;
case 0x0c0737a6u: goto P_0c0737a6;
case 0x0c0737acu: goto P_0c0737ac;
case 0x0c0737aeu: goto P_0c0737ae;
case 0x0c0737b0u: goto P_0c0737b0;
case 0x0c0737b2u: goto P_0c0737b2;
case 0x0c0737b4u: goto P_0c0737b4;
case 0x0c0737b6u: goto P_0c0737b6;
case 0x0c0737b8u: goto P_0c0737b8;
case 0x0c0737bau: goto P_0c0737ba;
case 0x0c0737bcu: goto P_0c0737bc;
case 0x0c0737beu: goto P_0c0737be;
case 0x0c0737c0u: goto P_0c0737c0;
case 0x0c0737c2u: goto P_0c0737c2;
case 0x0c0737c4u: goto P_0c0737c4;
case 0x0c0737c6u: goto P_0c0737c6;
case 0x0c0737c8u: goto P_0c0737c8;
case 0x0c0737cau: goto P_0c0737ca;
case 0x0c0737ccu: goto P_0c0737cc;
case 0x0c0737ceu: goto P_0c0737ce;
case 0x0c0737d0u: goto P_0c0737d0;
case 0x0c0737d2u: goto P_0c0737d2;
case 0x0c0737d4u: goto P_0c0737d4;
case 0x0c0737d6u: goto P_0c0737d6;
case 0x0c0737d8u: goto P_0c0737d8;
case 0x0c0737dau: goto P_0c0737da;
case 0x0c0737dcu: goto P_0c0737dc;
case 0x0c0737deu: goto P_0c0737de;
case 0x0c0737e0u: goto P_0c0737e0;
case 0x0c0737e2u: goto P_0c0737e2;
case 0x0c0737e4u: goto P_0c0737e4;
case 0x0c0737e6u: goto P_0c0737e6;
case 0x0c07b988u: goto P_0c07b988;
case 0x0c07b98au: goto P_0c07b98a;
case 0x0c07b98cu: goto P_0c07b98c;
case 0x0c07b98eu: goto P_0c07b98e;
case 0x0c07b990u: goto P_0c07b990;
case 0x0c07b992u: goto P_0c07b992;
case 0x0c07b994u: goto P_0c07b994;
case 0x0c07b996u: goto P_0c07b996;
case 0x0c07b998u: goto P_0c07b998;
case 0x0c07b99au: goto P_0c07b99a;
case 0x0c07b99cu: goto P_0c07b99c;
case 0x0c07b99eu: goto P_0c07b99e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06199c: /* original 4f22, guest PC 0x0c06199c */
if(!s->budget--) { s->failed_pc=0x0c06199cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06199e;
P_0c06199e: /* original de1b, guest PC 0x0c06199e */
if(!s->budget--) { s->failed_pc=0x0c06199eu; return 0; }
r[14]=read(ram,0x0c061a0cu,4);
goto P_0c0619a0;
P_0c0619a0: /* original 65e3, guest PC 0x0c0619a0 */
if(!s->budget--) { s->failed_pc=0x0c0619a0u; return 0; }
r[5]=r[14];
goto P_0c0619a2;
P_0c0619a2: /* original 7504, guest PC 0x0c0619a2 */
if(!s->budget--) { s->failed_pc=0x0c0619a2u; return 0; }
r[5]+=0x00000004u;
goto P_0c0619a4;
P_0c0619a4: /* original b62e, guest PC 0x0c0619a4 */
if(!s->budget--) { s->failed_pc=0x0c0619a4u; return 0; }
target=0x0c062604u; r[16]=0x0c0619a8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0619a8u) { target=s->pc; goto dispatch; }
goto P_0c0619a8;
P_0c0619a6: /* original 64e3, guest PC 0x0c0619a6 */
if(!s->budget--) { s->failed_pc=0x0c0619a6u; return 0; }
r[4]=r[14];
goto P_0c0619a8;
P_0c0619a8: /* original dd19, guest PC 0x0c0619a8 */
if(!s->budget--) { s->failed_pc=0x0c0619a8u; return 0; }
r[13]=read(ram,0x0c061a10u,4);
goto P_0c0619aa;
P_0c0619aa: /* original 65d3, guest PC 0x0c0619aa */
if(!s->budget--) { s->failed_pc=0x0c0619aau; return 0; }
r[5]=r[13];
goto P_0c0619ac;
P_0c0619ac: /* original 7504, guest PC 0x0c0619ac */
if(!s->budget--) { s->failed_pc=0x0c0619acu; return 0; }
r[5]+=0x00000004u;
goto P_0c0619ae;
P_0c0619ae: /* original b629, guest PC 0x0c0619ae */
if(!s->budget--) { s->failed_pc=0x0c0619aeu; return 0; }
target=0x0c062604u; r[16]=0x0c0619b2u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0619b2u) { target=s->pc; goto dispatch; }
goto P_0c0619b2;
P_0c0619b0: /* original 64d3, guest PC 0x0c0619b0 */
if(!s->budget--) { s->failed_pc=0x0c0619b0u; return 0; }
r[4]=r[13];
goto P_0c0619b2;
P_0c0619b2: /* original 65e3, guest PC 0x0c0619b2 */
if(!s->budget--) { s->failed_pc=0x0c0619b2u; return 0; }
r[5]=r[14];
goto P_0c0619b4;
P_0c0619b4: /* original 750c, guest PC 0x0c0619b4 */
if(!s->budget--) { s->failed_pc=0x0c0619b4u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0619b6;
P_0c0619b6: /* original 64e3, guest PC 0x0c0619b6 */
if(!s->budget--) { s->failed_pc=0x0c0619b6u; return 0; }
r[4]=r[14];
goto P_0c0619b8;
P_0c0619b8: /* original b624, guest PC 0x0c0619b8 */
if(!s->budget--) { s->failed_pc=0x0c0619b8u; return 0; }
target=0x0c062604u; r[16]=0x0c0619bcu;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0619bcu) { target=s->pc; goto dispatch; }
goto P_0c0619bc;
P_0c0619ba: /* original 7408, guest PC 0x0c0619ba */
if(!s->budget--) { s->failed_pc=0x0c0619bau; return 0; }
r[4]+=0x00000008u;
goto P_0c0619bc;
P_0c0619bc: /* original 65d3, guest PC 0x0c0619bc */
if(!s->budget--) { s->failed_pc=0x0c0619bcu; return 0; }
r[5]=r[13];
goto P_0c0619be;
P_0c0619be: /* original 750c, guest PC 0x0c0619be */
if(!s->budget--) { s->failed_pc=0x0c0619beu; return 0; }
r[5]+=0x0000000cu;
goto P_0c0619c0;
P_0c0619c0: /* original 64d3, guest PC 0x0c0619c0 */
if(!s->budget--) { s->failed_pc=0x0c0619c0u; return 0; }
r[4]=r[13];
goto P_0c0619c2;
P_0c0619c2: /* original b61f, guest PC 0x0c0619c2 */
if(!s->budget--) { s->failed_pc=0x0c0619c2u; return 0; }
target=0x0c062604u; r[16]=0x0c0619c6u;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0619c6u) { target=s->pc; goto dispatch; }
goto P_0c0619c6;
P_0c0619c4: /* original 7408, guest PC 0x0c0619c4 */
if(!s->budget--) { s->failed_pc=0x0c0619c4u; return 0; }
r[4]+=0x00000008u;
goto P_0c0619c6;
P_0c0619c6: /* original e000, guest PC 0x0c0619c6 */
if(!s->budget--) { s->failed_pc=0x0c0619c6u; return 0; }
r[0]=0x00000000u;
goto P_0c0619c8;
P_0c0619c8: /* original 4f26, guest PC 0x0c0619c8 */
if(!s->budget--) { s->failed_pc=0x0c0619c8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0619ca;
P_0c0619ca: /* original 6df6, guest PC 0x0c0619ca */
if(!s->budget--) { s->failed_pc=0x0c0619cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0619cc;
P_0c0619cc: /* original 000b, guest PC 0x0c0619cc */
if(!s->budget--) { s->failed_pc=0x0c0619ccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0619ce: /* original 6ef6, guest PC 0x0c0619ce */
if(!s->budget--) { s->failed_pc=0x0c0619ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0619d0u,s,ram);
P_0c0619d2: /* original 4f22, guest PC 0x0c0619d2 */
if(!s->budget--) { s->failed_pc=0x0c0619d2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0619d4;
P_0c0619d4: /* original de0d, guest PC 0x0c0619d4 */
if(!s->budget--) { s->failed_pc=0x0c0619d4u; return 0; }
r[14]=read(ram,0x0c061a0cu,4);
goto P_0c0619d6;
P_0c0619d6: /* original 67e3, guest PC 0x0c0619d6 */
if(!s->budget--) { s->failed_pc=0x0c0619d6u; return 0; }
r[7]=r[14];
goto P_0c0619d8;
P_0c0619d8: /* original 7704, guest PC 0x0c0619d8 */
if(!s->budget--) { s->failed_pc=0x0c0619d8u; return 0; }
r[7]+=0x00000004u;
goto P_0c0619da;
P_0c0619da: /* original 66e3, guest PC 0x0c0619da */
if(!s->budget--) { s->failed_pc=0x0c0619dau; return 0; }
r[6]=r[14];
goto P_0c0619dc;
P_0c0619dc: /* original 65e3, guest PC 0x0c0619dc */
if(!s->budget--) { s->failed_pc=0x0c0619dcu; return 0; }
r[5]=r[14];
goto P_0c0619de;
P_0c0619de: /* original 750c, guest PC 0x0c0619de */
if(!s->budget--) { s->failed_pc=0x0c0619deu; return 0; }
r[5]+=0x0000000cu;
goto P_0c0619e0;
P_0c0619e0: /* original 64e3, guest PC 0x0c0619e0 */
if(!s->budget--) { s->failed_pc=0x0c0619e0u; return 0; }
r[4]=r[14];
goto P_0c0619e2;
P_0c0619e2: /* original b665, guest PC 0x0c0619e2 */
if(!s->budget--) { s->failed_pc=0x0c0619e2u; return 0; }
target=0x0c0626b0u; r[16]=0x0c0619e6u;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0619e6u) { target=s->pc; goto dispatch; }
goto P_0c0619e6;
P_0c0619e4: /* original 7408, guest PC 0x0c0619e4 */
if(!s->budget--) { s->failed_pc=0x0c0619e4u; return 0; }
r[4]+=0x00000008u;
goto P_0c0619e6;
P_0c0619e6: /* original 6403, guest PC 0x0c0619e6 */
if(!s->budget--) { s->failed_pc=0x0c0619e6u; return 0; }
r[4]=r[0];
goto P_0c0619e8;
P_0c0619e8: /* original 2448, guest PC 0x0c0619e8 */
if(!s->budget--) { s->failed_pc=0x0c0619e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0619ea;
P_0c0619ea: /* original 8b09, guest PC 0x0c0619ea */
if(!s->budget--) { s->failed_pc=0x0c0619eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c061a00; }
goto P_0c0619ec;
P_0c0619ec: /* original de08, guest PC 0x0c0619ec */
if(!s->budget--) { s->failed_pc=0x0c0619ecu; return 0; }
r[14]=read(ram,0x0c061a10u,4);
goto P_0c0619ee;
P_0c0619ee: /* original 67e3, guest PC 0x0c0619ee */
if(!s->budget--) { s->failed_pc=0x0c0619eeu; return 0; }
r[7]=r[14];
goto P_0c0619f0;
P_0c0619f0: /* original 7704, guest PC 0x0c0619f0 */
if(!s->budget--) { s->failed_pc=0x0c0619f0u; return 0; }
r[7]+=0x00000004u;
goto P_0c0619f2;
P_0c0619f2: /* original 66e3, guest PC 0x0c0619f2 */
if(!s->budget--) { s->failed_pc=0x0c0619f2u; return 0; }
r[6]=r[14];
goto P_0c0619f4;
P_0c0619f4: /* original 65e3, guest PC 0x0c0619f4 */
if(!s->budget--) { s->failed_pc=0x0c0619f4u; return 0; }
r[5]=r[14];
goto P_0c0619f6;
P_0c0619f6: /* original 750c, guest PC 0x0c0619f6 */
if(!s->budget--) { s->failed_pc=0x0c0619f6u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0619f8;
P_0c0619f8: /* original 64e3, guest PC 0x0c0619f8 */
if(!s->budget--) { s->failed_pc=0x0c0619f8u; return 0; }
r[4]=r[14];
goto P_0c0619fa;
P_0c0619fa: /* original b659, guest PC 0x0c0619fa */
if(!s->budget--) { s->failed_pc=0x0c0619fau; return 0; }
target=0x0c0626b0u; r[16]=0x0c0619feu;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0619feu) { target=s->pc; goto dispatch; }
goto P_0c0619fe;
P_0c0619fc: /* original 7408, guest PC 0x0c0619fc */
if(!s->budget--) { s->failed_pc=0x0c0619fcu; return 0; }
r[4]+=0x00000008u;
goto P_0c0619fe;
P_0c0619fe: /* original 6403, guest PC 0x0c0619fe */
if(!s->budget--) { s->failed_pc=0x0c0619feu; return 0; }
r[4]=r[0];
goto P_0c061a00;
P_0c061a00: /* original 6043, guest PC 0x0c061a00 */
if(!s->budget--) { s->failed_pc=0x0c061a00u; return 0; }
r[0]=r[4];
goto P_0c061a02;
P_0c061a02: /* original 0009, guest PC 0x0c061a02 */
if(!s->budget--) { s->failed_pc=0x0c061a02u; return 0; }
goto P_0c061a04;
P_0c061a04: /* original 4f26, guest PC 0x0c061a04 */
if(!s->budget--) { s->failed_pc=0x0c061a04u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c061a06;
P_0c061a06: /* original 000b, guest PC 0x0c061a06 */
if(!s->budget--) { s->failed_pc=0x0c061a06u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c061a08: /* original 6ef6, guest PC 0x0c061a08 */
if(!s->budget--) { s->failed_pc=0x0c061a08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c061a0au,s,ram);
P_0c061fca: /* original 6153, guest PC 0x0c061fca */
if(!s->budget--) { s->failed_pc=0x0c061fcau; return 0; }
r[1]=r[5];
goto P_0c061fcc;
P_0c061fcc: /* original d343, guest PC 0x0c061fcc */
if(!s->budget--) { s->failed_pc=0x0c061fccu; return 0; }
r[3]=read(ram,0x0c0620dcu,4);
goto P_0c061fce;
P_0c061fce: /* original 2fe6, guest PC 0x0c061fce */
if(!s->budget--) { s->failed_pc=0x0c061fceu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c061fd0;
P_0c061fd0: /* original 2fd6, guest PC 0x0c061fd0 */
if(!s->budget--) { s->failed_pc=0x0c061fd0u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c061fd2;
P_0c061fd2: /* original 2fc6, guest PC 0x0c061fd2 */
if(!s->budget--) { s->failed_pc=0x0c061fd2u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c061fd4;
P_0c061fd4: /* original 2fb6, guest PC 0x0c061fd4 */
if(!s->budget--) { s->failed_pc=0x0c061fd4u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c061fd6;
P_0c061fd6: /* original 6c53, guest PC 0x0c061fd6 */
if(!s->budget--) { s->failed_pc=0x0c061fd6u; return 0; }
r[12]=r[5];
goto P_0c061fd8;
P_0c061fd8: /* original 2fa6, guest PC 0x0c061fd8 */
if(!s->budget--) { s->failed_pc=0x0c061fd8u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c061fda;
P_0c061fda: /* original 2f96, guest PC 0x0c061fda */
if(!s->budget--) { s->failed_pc=0x0c061fdau; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c061fdc;
P_0c061fdc: /* original 2f86, guest PC 0x0c061fdc */
if(!s->budget--) { s->failed_pc=0x0c061fdcu; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c061fde;
P_0c061fde: /* original 6963, guest PC 0x0c061fde */
if(!s->budget--) { s->failed_pc=0x0c061fdeu; return 0; }
r[9]=r[6];
goto P_0c061fe0;
P_0c061fe0: /* original 4f22, guest PC 0x0c061fe0 */
if(!s->budget--) { s->failed_pc=0x0c061fe0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c061fe2;
P_0c061fe2: /* original 6843, guest PC 0x0c061fe2 */
if(!s->budget--) { s->failed_pc=0x0c061fe2u; return 0; }
r[8]=r[4];
goto P_0c061fe4;
P_0c061fe4: /* original 7ffc, guest PC 0x0c061fe4 */
if(!s->budget--) { s->failed_pc=0x0c061fe4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c061fe6;
P_0c061fe6: /* original 430b, guest PC 0x0c061fe6 */
if(!s->budget--) { s->failed_pc=0x0c061fe6u; return 0; }
target=r[3];
r[16]=0x0c061feau;
r[0]=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c061feau) { target=s->pc; goto dispatch; }
goto P_0c061fea;
P_0c061fe8: /* original e020, guest PC 0x0c061fe8 */
if(!s->budget--) { s->failed_pc=0x0c061fe8u; return 0; }
r[0]=0x00000020u;
goto P_0c061fea;
P_0c061fea: /* original 6403, guest PC 0x0c061fea */
if(!s->budget--) { s->failed_pc=0x0c061feau; return 0; }
r[4]=r[0];
goto P_0c061fec;
P_0c061fec: /* original 2448, guest PC 0x0c061fec */
if(!s->budget--) { s->failed_pc=0x0c061fecu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c061fee;
P_0c061fee: /* original 8d03, guest PC 0x0c061fee */
if(!s->budget--) { s->failed_pc=0x0c061feeu; return 0; }
cond=r[17]&1u;
r[14]=0x00000000u;
if(cond) { goto P_0c061ff8; }
goto P_0c061ff2;
P_0c061ff0: /* original ee00, guest PC 0x0c061ff0 */
if(!s->budget--) { s->failed_pc=0x0c061ff0u; return 0; }
r[14]=0x00000000u;
goto P_0c061ff2;
P_0c061ff2: /* original e320, guest PC 0x0c061ff2 */
if(!s->budget--) { s->failed_pc=0x0c061ff2u; return 0; }
r[3]=0x00000020u;
goto P_0c061ff4;
P_0c061ff4: /* original 3348, guest PC 0x0c061ff4 */
if(!s->budget--) { s->failed_pc=0x0c061ff4u; return 0; }
r[3]-=r[4];
goto P_0c061ff6;
P_0c061ff6: /* original 3c3c, guest PC 0x0c061ff6 */
if(!s->budget--) { s->failed_pc=0x0c061ff6u; return 0; }
r[12]+=r[3];
goto P_0c061ff8;
P_0c061ff8: /* original da39, guest PC 0x0c061ff8 */
if(!s->budget--) { s->failed_pc=0x0c061ff8u; return 0; }
r[10]=read(ram,0x0c0620e0u,4);
goto P_0c061ffa;
P_0c061ffa: /* original 6b83, guest PC 0x0c061ffa */
if(!s->budget--) { s->failed_pc=0x0c061ffau; return 0; }
r[11]=r[8];
goto P_0c061ffc;
P_0c061ffc: /* original 6383, guest PC 0x0c061ffc */
if(!s->budget--) { s->failed_pc=0x0c061ffcu; return 0; }
r[3]=r[8];
goto P_0c061ffe;
P_0c061ffe: /* original 4b08, guest PC 0x0c061ffe */
if(!s->budget--) { s->failed_pc=0x0c061ffeu; return 0; }
r[11]<<=2;
goto P_0c062000;
P_0c062000: /* original 3b3c, guest PC 0x0c062000 */
if(!s->budget--) { s->failed_pc=0x0c062000u; return 0; }
r[11]+=r[3];
goto P_0c062002;
P_0c062002: /* original 4b08, guest PC 0x0c062002 */
if(!s->budget--) { s->failed_pc=0x0c062002u; return 0; }
r[11]<<=2;
goto P_0c062004;
P_0c062004: /* original 6bbe, guest PC 0x0c062004 */
if(!s->budget--) { s->failed_pc=0x0c062004u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)r[11];
goto P_0c062006;
P_0c062006: /* original 64b3, guest PC 0x0c062006 */
if(!s->budget--) { s->failed_pc=0x0c062006u; return 0; }
r[4]=r[11];
goto P_0c062008;
P_0c062008: /* original 34ac, guest PC 0x0c062008 */
if(!s->budget--) { s->failed_pc=0x0c062008u; return 0; }
r[4]+=r[10];
goto P_0c06200a;
P_0c06200a: /* original 5442, guest PC 0x0c06200a */
if(!s->budget--) { s->failed_pc=0x0c06200au; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c06200c;
P_0c06200c: /* original 2448, guest PC 0x0c06200c */
if(!s->budget--) { s->failed_pc=0x0c06200cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06200e;
P_0c06200e: /* original 8908, guest PC 0x0c06200e */
if(!s->budget--) { s->failed_pc=0x0c06200eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062022; }
goto P_0c062010;
P_0c062010: /* original 5244, guest PC 0x0c062010 */
if(!s->budget--) { s->failed_pc=0x0c062010u; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c062012;
P_0c062012: /* original 32c3, guest PC 0x0c062012 */
if(!s->budget--) { s->failed_pc=0x0c062012u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[12])!=0);
goto P_0c062014;
P_0c062014: /* original 8b02, guest PC 0x0c062014 */
if(!s->budget--) { s->failed_pc=0x0c062014u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06201c; }
goto P_0c062016;
P_0c062016: /* original 6e43, guest PC 0x0c062016 */
if(!s->budget--) { s->failed_pc=0x0c062016u; return 0; }
r[14]=r[4];
goto P_0c062018;
P_0c062018: /* original a001, guest PC 0x0c062018 */
if(!s->budget--) { s->failed_pc=0x0c062018u; return 0; }
r[4]=0x00000000u;
goto P_0c06201e;
P_0c06201a: /* original e400, guest PC 0x0c06201a */
if(!s->budget--) { s->failed_pc=0x0c06201au; return 0; }
r[4]=0x00000000u;
goto P_0c06201c;
P_0c06201c: /* original 5442, guest PC 0x0c06201c */
if(!s->budget--) { s->failed_pc=0x0c06201cu; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c06201e;
P_0c06201e: /* original 2448, guest PC 0x0c06201e */
if(!s->budget--) { s->failed_pc=0x0c06201eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c062020;
P_0c062020: /* original 8bf6, guest PC 0x0c062020 */
if(!s->budget--) { s->failed_pc=0x0c062020u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062010; }
goto P_0c062022;
P_0c062022: /* original 2ee8, guest PC 0x0c062022 */
if(!s->budget--) { s->failed_pc=0x0c062022u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c062024;
P_0c062024: /* original 8928, guest PC 0x0c062024 */
if(!s->budget--) { s->failed_pc=0x0c062024u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062078; }
goto P_0c062026;
P_0c062026: /* original 52e4, guest PC 0x0c062026 */
if(!s->budget--) { s->failed_pc=0x0c062026u; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c062028;
P_0c062028: /* original 32c0, guest PC 0x0c062028 */
if(!s->budget--) { s->failed_pc=0x0c062028u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[12])!=0);
goto P_0c06202a;
P_0c06202a: /* original 8b20, guest PC 0x0c06202a */
if(!s->budget--) { s->failed_pc=0x0c06202au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06206e; }
goto P_0c06202c;
P_0c06202c: /* original 66e3, guest PC 0x0c06202c */
if(!s->budget--) { s->failed_pc=0x0c06202cu; return 0; }
r[6]=r[14];
goto P_0c06202e;
P_0c06202e: /* original 6db3, guest PC 0x0c06202e */
if(!s->budget--) { s->failed_pc=0x0c06202eu; return 0; }
r[13]=r[11];
goto P_0c062030;
P_0c062030: /* original 3dac, guest PC 0x0c062030 */
if(!s->budget--) { s->failed_pc=0x0c062030u; return 0; }
r[13]+=r[10];
goto P_0c062032;
P_0c062032: /* original 65d3, guest PC 0x0c062032 */
if(!s->budget--) { s->failed_pc=0x0c062032u; return 0; }
r[5]=r[13];
goto P_0c062034;
P_0c062034: /* original 750c, guest PC 0x0c062034 */
if(!s->budget--) { s->failed_pc=0x0c062034u; return 0; }
r[5]+=0x0000000cu;
goto P_0c062036;
P_0c062036: /* original 64d3, guest PC 0x0c062036 */
if(!s->budget--) { s->failed_pc=0x0c062036u; return 0; }
r[4]=r[13];
goto P_0c062038;
P_0c062038: /* original b274, guest PC 0x0c062038 */
if(!s->budget--) { s->failed_pc=0x0c062038u; return 0; }
target=0x0c062524u; r[16]=0x0c06203cu;
r[4]+=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06203cu) { target=s->pc; goto dispatch; }
goto P_0c06203c;
P_0c06203a: /* original 7408, guest PC 0x0c06203a */
if(!s->budget--) { s->failed_pc=0x0c06203au; return 0; }
r[4]+=0x00000008u;
goto P_0c06203c;
P_0c06203c: /* original 66e3, guest PC 0x0c06203c */
if(!s->budget--) { s->failed_pc=0x0c06203cu; return 0; }
r[6]=r[14];
goto P_0c06203e;
P_0c06203e: /* original 65d3, guest PC 0x0c06203e */
if(!s->budget--) { s->failed_pc=0x0c06203eu; return 0; }
r[5]=r[13];
goto P_0c062040;
P_0c062040: /* original 7504, guest PC 0x0c062040 */
if(!s->budget--) { s->failed_pc=0x0c062040u; return 0; }
r[5]+=0x00000004u;
goto P_0c062042;
P_0c062042: /* original b24f, guest PC 0x0c062042 */
if(!s->budget--) { s->failed_pc=0x0c062042u; return 0; }
target=0x0c0624e4u; r[16]=0x0c062046u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c062046u) { target=s->pc; goto dispatch; }
goto P_0c062046;
P_0c062044: /* original 64d3, guest PC 0x0c062044 */
if(!s->budget--) { s->failed_pc=0x0c062044u; return 0; }
r[4]=r[13];
goto P_0c062046;
P_0c062046: /* original e301, guest PC 0x0c062046 */
if(!s->budget--) { s->failed_pc=0x0c062046u; return 0; }
r[3]=0x00000001u;
goto P_0c062048;
P_0c062048: /* original 52e3, guest PC 0x0c062048 */
if(!s->budget--) { s->failed_pc=0x0c062048u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c06204a;
P_0c06204a: /* original 688f, guest PC 0x0c06204a */
if(!s->budget--) { s->failed_pc=0x0c06204au; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)r[8];
goto P_0c06204c;
P_0c06204c: /* original 1927, guest PC 0x0c06204c */
if(!s->budget--) { s->failed_pc=0x0c06204cu; return 0; }
write(ram,r[9]+28,r[2],4);
goto P_0c06204e;
P_0c06204e: /* original 2888, guest PC 0x0c06204e */
if(!s->budget--) { s->failed_pc=0x0c06204eu; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c062050;
P_0c062050: /* original 1e95, guest PC 0x0c062050 */
if(!s->budget--) { s->failed_pc=0x0c062050u; return 0; }
write(ram,r[14]+20,r[9],4);
goto P_0c062052;
P_0c062052: /* original 8f03, guest PC 0x0c062052 */
if(!s->budget--) { s->failed_pc=0x0c062052u; return 0; }
cond=r[17]&1u;
write(ram,r[14],r[3],2);
if(!cond) { goto P_0c06205c; }
goto P_0c062056;
P_0c062054: /* original 2e31, guest PC 0x0c062054 */
if(!s->budget--) { s->failed_pc=0x0c062054u; return 0; }
write(ram,r[14],r[3],2);
goto P_0c062056;
P_0c062056: /* original 60e1, guest PC 0x0c062056 */
if(!s->budget--) { s->failed_pc=0x0c062056u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c062058;
P_0c062058: /* original a002, guest PC 0x0c062058 */
if(!s->budget--) { s->failed_pc=0x0c062058u; return 0; }
r[0]|=32u;
goto P_0c062060;
P_0c06205a: /* original cb20, guest PC 0x0c06205a */
if(!s->budget--) { s->failed_pc=0x0c06205au; return 0; }
r[0]|=32u;
goto P_0c06205c;
P_0c06205c: /* original 60e1, guest PC 0x0c06205c */
if(!s->budget--) { s->failed_pc=0x0c06205cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c06205e;
P_0c06205e: /* original cb40, guest PC 0x0c06205e */
if(!s->budget--) { s->failed_pc=0x0c06205eu; return 0; }
r[0]|=64u;
goto P_0c062060;
P_0c062060: /* original 2e01, guest PC 0x0c062060 */
if(!s->budget--) { s->failed_pc=0x0c062060u; return 0; }
write(ram,r[14],r[0],2);
goto P_0c062062;
P_0c062062: /* original 3bac, guest PC 0x0c062062 */
if(!s->budget--) { s->failed_pc=0x0c062062u; return 0; }
r[11]+=r[10];
goto P_0c062064;
P_0c062064: /* original 60e1, guest PC 0x0c062064 */
if(!s->budget--) { s->failed_pc=0x0c062064u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c062066;
P_0c062066: /* original cb04, guest PC 0x0c062066 */
if(!s->budget--) { s->failed_pc=0x0c062066u; return 0; }
r[0]|=4u;
goto P_0c062068;
P_0c062068: /* original 2e01, guest PC 0x0c062068 */
if(!s->budget--) { s->failed_pc=0x0c062068u; return 0; }
write(ram,r[14],r[0],2);
goto P_0c06206a;
P_0c06206a: /* original a028, guest PC 0x0c06206a */
if(!s->budget--) { s->failed_pc=0x0c06206au; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c0620be;
P_0c06206c: /* original 53e4, guest PC 0x0c06206c */
if(!s->budget--) { s->failed_pc=0x0c06206cu; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c06206e;
P_0c06206e: /* original b20f, guest PC 0x0c06206e */
if(!s->budget--) { s->failed_pc=0x0c06206eu; return 0; }
target=0x0c062490u; r[16]=0x0c062072u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c062072u) { target=s->pc; goto dispatch; }
goto P_0c062072;
P_0c062070: /* original 0009, guest PC 0x0c062070 */
if(!s->budget--) { s->failed_pc=0x0c062070u; return 0; }
goto P_0c062072;
P_0c062072: /* original 6d03, guest PC 0x0c062072 */
if(!s->budget--) { s->failed_pc=0x0c062072u; return 0; }
r[13]=r[0];
goto P_0c062074;
P_0c062074: /* original 2dd8, guest PC 0x0c062074 */
if(!s->budget--) { s->failed_pc=0x0c062074u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c062076;
P_0c062076: /* original 8b01, guest PC 0x0c062076 */
if(!s->budget--) { s->failed_pc=0x0c062076u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06207c; }
goto P_0c062078;
P_0c062078: /* original a025, guest PC 0x0c062078 */
if(!s->budget--) { s->failed_pc=0x0c062078u; return 0; }
r[0]=0x00000003u;
goto P_0c0620c6;
P_0c06207a: /* original e003, guest PC 0x0c06207a */
if(!s->budget--) { s->failed_pc=0x0c06207au; return 0; }
r[0]=0x00000003u;
goto P_0c06207c;
P_0c06207c: /* original 53e3, guest PC 0x0c06207c */
if(!s->budget--) { s->failed_pc=0x0c06207cu; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c06207e;
P_0c06207e: /* original 66d3, guest PC 0x0c06207e */
if(!s->budget--) { s->failed_pc=0x0c06207eu; return 0; }
r[6]=r[13];
goto P_0c062080;
P_0c062080: /* original 1d33, guest PC 0x0c062080 */
if(!s->budget--) { s->failed_pc=0x0c062080u; return 0; }
write(ram,r[13]+12,r[3],4);
goto P_0c062082;
P_0c062082: /* original 65b3, guest PC 0x0c062082 */
if(!s->budget--) { s->failed_pc=0x0c062082u; return 0; }
r[5]=r[11];
goto P_0c062084;
P_0c062084: /* original 1dc4, guest PC 0x0c062084 */
if(!s->budget--) { s->failed_pc=0x0c062084u; return 0; }
write(ram,r[13]+16,r[12],4);
goto P_0c062086;
P_0c062086: /* original 35ac, guest PC 0x0c062086 */
if(!s->budget--) { s->failed_pc=0x0c062086u; return 0; }
r[5]+=r[10];
goto P_0c062088;
P_0c062088: /* original 54e4, guest PC 0x0c062088 */
if(!s->budget--) { s->failed_pc=0x0c062088u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c06208a;
P_0c06208a: /* original 34c8, guest PC 0x0c06208a */
if(!s->budget--) { s->failed_pc=0x0c06208au; return 0; }
r[4]-=r[12];
goto P_0c06208c;
P_0c06208c: /* original 1e44, guest PC 0x0c06208c */
if(!s->budget--) { s->failed_pc=0x0c06208cu; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c06208e;
P_0c06208e: /* original 52e3, guest PC 0x0c06208e */
if(!s->budget--) { s->failed_pc=0x0c06208eu; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c062090;
P_0c062090: /* original 32cc, guest PC 0x0c062090 */
if(!s->budget--) { s->failed_pc=0x0c062090u; return 0; }
r[2]+=r[12];
goto P_0c062092;
P_0c062092: /* original 1e23, guest PC 0x0c062092 */
if(!s->budget--) { s->failed_pc=0x0c062092u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c062094;
P_0c062094: /* original 2f52, guest PC 0x0c062094 */
if(!s->budget--) { s->failed_pc=0x0c062094u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c062096;
P_0c062096: /* original 7504, guest PC 0x0c062096 */
if(!s->budget--) { s->failed_pc=0x0c062096u; return 0; }
r[5]+=0x00000004u;
goto P_0c062098;
P_0c062098: /* original b224, guest PC 0x0c062098 */
if(!s->budget--) { s->failed_pc=0x0c062098u; return 0; }
target=0x0c0624e4u; r[16]=0x0c06209cu;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06209cu) { target=s->pc; goto dispatch; }
goto P_0c06209c;
P_0c06209a: /* original 64f2, guest PC 0x0c06209a */
if(!s->budget--) { s->failed_pc=0x0c06209au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06209c;
P_0c06209c: /* original 52d3, guest PC 0x0c06209c */
if(!s->budget--) { s->failed_pc=0x0c06209cu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c06209e;
P_0c06209e: /* original 688f, guest PC 0x0c06209e */
if(!s->budget--) { s->failed_pc=0x0c06209eu; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)r[8];
goto P_0c0620a0;
P_0c0620a0: /* original 1927, guest PC 0x0c0620a0 */
if(!s->budget--) { s->failed_pc=0x0c0620a0u; return 0; }
write(ram,r[9]+28,r[2],4);
goto P_0c0620a2;
P_0c0620a2: /* original 2888, guest PC 0x0c0620a2 */
if(!s->budget--) { s->failed_pc=0x0c0620a2u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c0620a4;
P_0c0620a4: /* original 8f03, guest PC 0x0c0620a4 */
if(!s->budget--) { s->failed_pc=0x0c0620a4u; return 0; }
cond=r[17]&1u;
write(ram,r[13]+20,r[9],4);
if(!cond) { goto P_0c0620ae; }
goto P_0c0620a8;
P_0c0620a6: /* original 1d95, guest PC 0x0c0620a6 */
if(!s->budget--) { s->failed_pc=0x0c0620a6u; return 0; }
write(ram,r[13]+20,r[9],4);
goto P_0c0620a8;
P_0c0620a8: /* original 60d1, guest PC 0x0c0620a8 */
if(!s->budget--) { s->failed_pc=0x0c0620a8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[0]=tmp;
goto P_0c0620aa;
P_0c0620aa: /* original a002, guest PC 0x0c0620aa */
if(!s->budget--) { s->failed_pc=0x0c0620aau; return 0; }
r[0]|=32u;
goto P_0c0620b2;
P_0c0620ac: /* original cb20, guest PC 0x0c0620ac */
if(!s->budget--) { s->failed_pc=0x0c0620acu; return 0; }
r[0]|=32u;
goto P_0c0620ae;
P_0c0620ae: /* original 60d1, guest PC 0x0c0620ae */
if(!s->budget--) { s->failed_pc=0x0c0620aeu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[0]=tmp;
goto P_0c0620b0;
P_0c0620b0: /* original cb40, guest PC 0x0c0620b0 */
if(!s->budget--) { s->failed_pc=0x0c0620b0u; return 0; }
r[0]|=64u;
goto P_0c0620b2;
P_0c0620b2: /* original 3bac, guest PC 0x0c0620b2 */
if(!s->budget--) { s->failed_pc=0x0c0620b2u; return 0; }
r[11]+=r[10];
goto P_0c0620b4;
P_0c0620b4: /* original 2d01, guest PC 0x0c0620b4 */
if(!s->budget--) { s->failed_pc=0x0c0620b4u; return 0; }
write(ram,r[13],r[0],2);
goto P_0c0620b6;
P_0c0620b6: /* original 60d1, guest PC 0x0c0620b6 */
if(!s->budget--) { s->failed_pc=0x0c0620b6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[0]=tmp;
goto P_0c0620b8;
P_0c0620b8: /* original cb04, guest PC 0x0c0620b8 */
if(!s->budget--) { s->failed_pc=0x0c0620b8u; return 0; }
r[0]|=4u;
goto P_0c0620ba;
P_0c0620ba: /* original 2d01, guest PC 0x0c0620ba */
if(!s->budget--) { s->failed_pc=0x0c0620bau; return 0; }
write(ram,r[13],r[0],2);
goto P_0c0620bc;
P_0c0620bc: /* original 53d4, guest PC 0x0c0620bc */
if(!s->budget--) { s->failed_pc=0x0c0620bcu; return 0; }
r[3]=read(ram,r[13]+16,4);
goto P_0c0620be;
P_0c0620be: /* original e000, guest PC 0x0c0620be */
if(!s->budget--) { s->failed_pc=0x0c0620beu; return 0; }
r[0]=0x00000000u;
goto P_0c0620c0;
P_0c0620c0: /* original 52b4, guest PC 0x0c0620c0 */
if(!s->budget--) { s->failed_pc=0x0c0620c0u; return 0; }
r[2]=read(ram,r[11]+16,4);
goto P_0c0620c2;
P_0c0620c2: /* original 3238, guest PC 0x0c0620c2 */
if(!s->budget--) { s->failed_pc=0x0c0620c2u; return 0; }
r[2]-=r[3];
goto P_0c0620c4;
P_0c0620c4: /* original 1b24, guest PC 0x0c0620c4 */
if(!s->budget--) { s->failed_pc=0x0c0620c4u; return 0; }
write(ram,r[11]+16,r[2],4);
goto P_0c0620c6;
P_0c0620c6: /* original 7f04, guest PC 0x0c0620c6 */
if(!s->budget--) { s->failed_pc=0x0c0620c6u; return 0; }
r[15]+=0x00000004u;
goto P_0c0620c8;
P_0c0620c8: /* original 4f26, guest PC 0x0c0620c8 */
if(!s->budget--) { s->failed_pc=0x0c0620c8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0620ca;
P_0c0620ca: /* original 68f6, guest PC 0x0c0620ca */
if(!s->budget--) { s->failed_pc=0x0c0620cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0620cc;
P_0c0620cc: /* original 69f6, guest PC 0x0c0620cc */
if(!s->budget--) { s->failed_pc=0x0c0620ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0620ce;
P_0c0620ce: /* original 6af6, guest PC 0x0c0620ce */
if(!s->budget--) { s->failed_pc=0x0c0620ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0620d0;
P_0c0620d0: /* original 6bf6, guest PC 0x0c0620d0 */
if(!s->budget--) { s->failed_pc=0x0c0620d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0620d2;
P_0c0620d2: /* original 6cf6, guest PC 0x0c0620d2 */
if(!s->budget--) { s->failed_pc=0x0c0620d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0620d4;
P_0c0620d4: /* original 6df6, guest PC 0x0c0620d4 */
if(!s->budget--) { s->failed_pc=0x0c0620d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0620d6;
P_0c0620d6: /* original 000b, guest PC 0x0c0620d6 */
if(!s->budget--) { s->failed_pc=0x0c0620d6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0620d8: /* original 6ef6, guest PC 0x0c0620d8 */
if(!s->budget--) { s->failed_pc=0x0c0620d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0620dau,s,ram);
P_0c062604: /* original 2fe6, guest PC 0x0c062604 */
if(!s->budget--) { s->failed_pc=0x0c062604u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c062606;
P_0c062606: /* original 2fd6, guest PC 0x0c062606 */
if(!s->budget--) { s->failed_pc=0x0c062606u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c062608;
P_0c062608: /* original 2fc6, guest PC 0x0c062608 */
if(!s->budget--) { s->failed_pc=0x0c062608u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c06260a;
P_0c06260a: /* original 6c53, guest PC 0x0c06260a */
if(!s->budget--) { s->failed_pc=0x0c06260au; return 0; }
r[12]=r[5];
goto P_0c06260c;
P_0c06260c: /* original 2fb6, guest PC 0x0c06260c */
if(!s->budget--) { s->failed_pc=0x0c06260cu; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c06260e;
P_0c06260e: /* original 2fa6, guest PC 0x0c06260e */
if(!s->budget--) { s->failed_pc=0x0c06260eu; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c062610;
P_0c062610: /* original 2f96, guest PC 0x0c062610 */
if(!s->budget--) { s->failed_pc=0x0c062610u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c062612;
P_0c062612: /* original 6943, guest PC 0x0c062612 */
if(!s->budget--) { s->failed_pc=0x0c062612u; return 0; }
r[9]=r[4];
goto P_0c062614;
P_0c062614: /* original 2f86, guest PC 0x0c062614 */
if(!s->budget--) { s->failed_pc=0x0c062614u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c062616;
P_0c062616: /* original 4f22, guest PC 0x0c062616 */
if(!s->budget--) { s->failed_pc=0x0c062616u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c062618;
P_0c062618: /* original 6392, guest PC 0x0c062618 */
if(!s->budget--) { s->failed_pc=0x0c062618u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c06261a;
P_0c06261a: /* original 2338, guest PC 0x0c06261a */
if(!s->budget--) { s->failed_pc=0x0c06261au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06261c;
P_0c06261c: /* original 8d39, guest PC 0x0c06261c */
if(!s->budget--) { s->failed_pc=0x0c06261cu; return 0; }
cond=r[17]&1u;
r[10]=0x00000000u;
if(cond) { goto P_0c062692; }
goto P_0c062620;
P_0c06261e: /* original ea00, guest PC 0x0c06261e */
if(!s->budget--) { s->failed_pc=0x0c06261eu; return 0; }
r[10]=0x00000000u;
goto P_0c062620;
P_0c062620: /* original 6492, guest PC 0x0c062620 */
if(!s->budget--) { s->failed_pc=0x0c062620u; return 0; }
tmp=read(ram,r[9],4);
r[4]=tmp;
goto P_0c062622;
P_0c062622: /* original 6e43, guest PC 0x0c062622 */
if(!s->budget--) { s->failed_pc=0x0c062622u; return 0; }
r[14]=r[4];
goto P_0c062624;
P_0c062624: /* original 53e3, guest PC 0x0c062624 */
if(!s->budget--) { s->failed_pc=0x0c062624u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c062626;
P_0c062626: /* original 5243, guest PC 0x0c062626 */
if(!s->budget--) { s->failed_pc=0x0c062626u; return 0; }
r[2]=read(ram,r[4]+12,4);
goto P_0c062628;
P_0c062628: /* original 3237, guest PC 0x0c062628 */
if(!s->budget--) { s->failed_pc=0x0c062628u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c06262a;
P_0c06262a: /* original 8b00, guest PC 0x0c06262a */
if(!s->budget--) { s->failed_pc=0x0c06262au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06262e; }
goto P_0c06262c;
P_0c06262c: /* original 6e43, guest PC 0x0c06262c */
if(!s->budget--) { s->failed_pc=0x0c06262cu; return 0; }
r[14]=r[4];
goto P_0c06262e;
P_0c06262e: /* original 5442, guest PC 0x0c06262e */
if(!s->budget--) { s->failed_pc=0x0c06262eu; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c062630;
P_0c062630: /* original 2448, guest PC 0x0c062630 */
if(!s->budget--) { s->failed_pc=0x0c062630u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c062632;
P_0c062632: /* original 8ff7, guest PC 0x0c062632 */
if(!s->budget--) { s->failed_pc=0x0c062632u; return 0; }
cond=r[17]&1u;
r[10]+=0x00000001u;
if(!cond) { goto P_0c062624; }
goto P_0c062636;
P_0c062634: /* original 7a01, guest PC 0x0c062634 */
if(!s->budget--) { s->failed_pc=0x0c062634u; return 0; }
r[10]+=0x00000001u;
goto P_0c062636;
P_0c062636: /* original e201, guest PC 0x0c062636 */
if(!s->budget--) { s->failed_pc=0x0c062636u; return 0; }
r[2]=0x00000001u;
goto P_0c062638;
P_0c062638: /* original 3a27, guest PC 0x0c062638 */
if(!s->budget--) { s->failed_pc=0x0c062638u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>(int32_t)r[2])!=0);
goto P_0c06263a;
P_0c06263a: /* original 8b2a, guest PC 0x0c06263a */
if(!s->budget--) { s->failed_pc=0x0c06263au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062692; }
goto P_0c06263c;
P_0c06263c: /* original 61c2, guest PC 0x0c06263c */
if(!s->budget--) { s->failed_pc=0x0c06263cu; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c06263e;
P_0c06263e: /* original 31e0, guest PC 0x0c06263e */
if(!s->budget--) { s->failed_pc=0x0c06263eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[14])!=0);
goto P_0c062640;
P_0c062640: /* original 8907, guest PC 0x0c062640 */
if(!s->budget--) { s->failed_pc=0x0c062640u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c062652; }
goto P_0c062642;
P_0c062642: /* original 66e3, guest PC 0x0c062642 */
if(!s->budget--) { s->failed_pc=0x0c062642u; return 0; }
r[6]=r[14];
goto P_0c062644;
P_0c062644: /* original 65c3, guest PC 0x0c062644 */
if(!s->budget--) { s->failed_pc=0x0c062644u; return 0; }
r[5]=r[12];
goto P_0c062646;
P_0c062646: /* original bf6d, guest PC 0x0c062646 */
if(!s->budget--) { s->failed_pc=0x0c062646u; return 0; }
target=0x0c062524u; r[16]=0x0c06264au;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06264au) { target=s->pc; goto dispatch; }
goto P_0c06264a;
P_0c062648: /* original 6493, guest PC 0x0c062648 */
if(!s->budget--) { s->failed_pc=0x0c062648u; return 0; }
r[4]=r[9];
goto P_0c06264a;
P_0c06264a: /* original 65e3, guest PC 0x0c06264a */
if(!s->budget--) { s->failed_pc=0x0c06264au; return 0; }
r[5]=r[14];
goto P_0c06264c;
P_0c06264c: /* original 66c2, guest PC 0x0c06264c */
if(!s->budget--) { s->failed_pc=0x0c06264cu; return 0; }
tmp=read(ram,r[12],4);
r[6]=tmp;
goto P_0c06264e;
P_0c06264e: /* original bf5b, guest PC 0x0c06264e */
if(!s->budget--) { s->failed_pc=0x0c06264eu; return 0; }
target=0x0c062508u; r[16]=0x0c062652u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c062652u) { target=s->pc; goto dispatch; }
goto P_0c062652;
P_0c062650: /* original 64c3, guest PC 0x0c062650 */
if(!s->budget--) { s->failed_pc=0x0c062650u; return 0; }
r[4]=r[12];
goto P_0c062652;
P_0c062652: /* original 7afe, guest PC 0x0c062652 */
if(!s->budget--) { s->failed_pc=0x0c062652u; return 0; }
r[10]+=0xfffffffeu;
goto P_0c062654;
P_0c062654: /* original 6ba3, guest PC 0x0c062654 */
if(!s->budget--) { s->failed_pc=0x0c062654u; return 0; }
r[11]=r[10];
goto P_0c062656;
P_0c062656: /* original a01a, guest PC 0x0c062656 */
if(!s->budget--) { s->failed_pc=0x0c062656u; return 0; }
r[8]=0x00000000u;
goto P_0c06268e;
P_0c062658: /* original e800, guest PC 0x0c062658 */
if(!s->budget--) { s->failed_pc=0x0c062658u; return 0; }
r[8]=0x00000000u;
goto P_0c06265a;
P_0c06265a: /* original 4b15, guest PC 0x0c06265a */
if(!s->budget--) { s->failed_pc=0x0c06265au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>0)!=0);
goto P_0c06265c;
P_0c06265c: /* original 6e92, guest PC 0x0c06265c */
if(!s->budget--) { s->failed_pc=0x0c06265cu; return 0; }
tmp=read(ram,r[9],4);
r[14]=tmp;
goto P_0c06265e;
P_0c06265e: /* original 6de3, guest PC 0x0c06265e */
if(!s->budget--) { s->failed_pc=0x0c06265eu; return 0; }
r[13]=r[14];
goto P_0c062660;
P_0c062660: /* original 8f09, guest PC 0x0c062660 */
if(!s->budget--) { s->failed_pc=0x0c062660u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(!cond) { goto P_0c062676; }
goto P_0c062664;
P_0c062662: /* original e400, guest PC 0x0c062662 */
if(!s->budget--) { s->failed_pc=0x0c062662u; return 0; }
r[4]=0x00000000u;
goto P_0c062664;
P_0c062664: /* original 5ee2, guest PC 0x0c062664 */
if(!s->budget--) { s->failed_pc=0x0c062664u; return 0; }
r[14]=read(ram,r[14]+8,4);
goto P_0c062666;
P_0c062666: /* original 52d3, guest PC 0x0c062666 */
if(!s->budget--) { s->failed_pc=0x0c062666u; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c062668;
P_0c062668: /* original 53e3, guest PC 0x0c062668 */
if(!s->budget--) { s->failed_pc=0x0c062668u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c06266a;
P_0c06266a: /* original 3327, guest PC 0x0c06266a */
if(!s->budget--) { s->failed_pc=0x0c06266au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c06266c;
P_0c06266c: /* original 8f01, guest PC 0x0c06266c */
if(!s->budget--) { s->failed_pc=0x0c06266cu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c062672; }
goto P_0c062670;
P_0c06266e: /* original 7401, guest PC 0x0c06266e */
if(!s->budget--) { s->failed_pc=0x0c06266eu; return 0; }
r[4]+=0x00000001u;
goto P_0c062670;
P_0c062670: /* original 6de3, guest PC 0x0c062670 */
if(!s->budget--) { s->failed_pc=0x0c062670u; return 0; }
r[13]=r[14];
goto P_0c062672;
P_0c062672: /* original 34b3, guest PC 0x0c062672 */
if(!s->budget--) { s->failed_pc=0x0c062672u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[11])!=0);
goto P_0c062674;
P_0c062674: /* original 8bf6, guest PC 0x0c062674 */
if(!s->budget--) { s->failed_pc=0x0c062674u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062664; }
goto P_0c062676;
P_0c062676: /* original 3ed0, guest PC 0x0c062676 */
if(!s->budget--) { s->failed_pc=0x0c062676u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[13])!=0);
goto P_0c062678;
P_0c062678: /* original 8907, guest PC 0x0c062678 */
if(!s->budget--) { s->failed_pc=0x0c062678u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06268a; }
goto P_0c06267a;
P_0c06267a: /* original 66d3, guest PC 0x0c06267a */
if(!s->budget--) { s->failed_pc=0x0c06267au; return 0; }
r[6]=r[13];
goto P_0c06267c;
P_0c06267c: /* original 65c3, guest PC 0x0c06267c */
if(!s->budget--) { s->failed_pc=0x0c06267cu; return 0; }
r[5]=r[12];
goto P_0c06267e;
P_0c06267e: /* original bf51, guest PC 0x0c06267e */
if(!s->budget--) { s->failed_pc=0x0c06267eu; return 0; }
target=0x0c062524u; r[16]=0x0c062682u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c062682u) { target=s->pc; goto dispatch; }
goto P_0c062682;
P_0c062680: /* original 6493, guest PC 0x0c062680 */
if(!s->budget--) { s->failed_pc=0x0c062680u; return 0; }
r[4]=r[9];
goto P_0c062682;
P_0c062682: /* original 66e3, guest PC 0x0c062682 */
if(!s->budget--) { s->failed_pc=0x0c062682u; return 0; }
r[6]=r[14];
goto P_0c062684;
P_0c062684: /* original 65d3, guest PC 0x0c062684 */
if(!s->budget--) { s->failed_pc=0x0c062684u; return 0; }
r[5]=r[13];
goto P_0c062686;
P_0c062686: /* original bf3f, guest PC 0x0c062686 */
if(!s->budget--) { s->failed_pc=0x0c062686u; return 0; }
target=0x0c062508u; r[16]=0x0c06268au;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06268au) { target=s->pc; goto dispatch; }
goto P_0c06268a;
P_0c062688: /* original 64c3, guest PC 0x0c062688 */
if(!s->budget--) { s->failed_pc=0x0c062688u; return 0; }
r[4]=r[12];
goto P_0c06268a;
P_0c06268a: /* original 7bff, guest PC 0x0c06268a */
if(!s->budget--) { s->failed_pc=0x0c06268au; return 0; }
r[11]+=0xffffffffu;
goto P_0c06268c;
P_0c06268c: /* original 7801, guest PC 0x0c06268c */
if(!s->budget--) { s->failed_pc=0x0c06268cu; return 0; }
r[8]+=0x00000001u;
goto P_0c06268e;
P_0c06268e: /* original 38a3, guest PC 0x0c06268e */
if(!s->budget--) { s->failed_pc=0x0c06268eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[10])!=0);
goto P_0c062690;
P_0c062690: /* original 8be3, guest PC 0x0c062690 */
if(!s->budget--) { s->failed_pc=0x0c062690u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06265a; }
goto P_0c062692;
P_0c062692: /* original 4f26, guest PC 0x0c062692 */
if(!s->budget--) { s->failed_pc=0x0c062692u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c062694;
P_0c062694: /* original 68f6, guest PC 0x0c062694 */
if(!s->budget--) { s->failed_pc=0x0c062694u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c062696;
P_0c062696: /* original 69f6, guest PC 0x0c062696 */
if(!s->budget--) { s->failed_pc=0x0c062696u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c062698;
P_0c062698: /* original 6af6, guest PC 0x0c062698 */
if(!s->budget--) { s->failed_pc=0x0c062698u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06269a;
P_0c06269a: /* original 6bf6, guest PC 0x0c06269a */
if(!s->budget--) { s->failed_pc=0x0c06269au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06269c;
P_0c06269c: /* original 6cf6, guest PC 0x0c06269c */
if(!s->budget--) { s->failed_pc=0x0c06269cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06269e;
P_0c06269e: /* original 6df6, guest PC 0x0c06269e */
if(!s->budget--) { s->failed_pc=0x0c06269eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0626a0;
P_0c0626a0: /* original 000b, guest PC 0x0c0626a0 */
if(!s->budget--) { s->failed_pc=0x0c0626a0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0626a2: /* original 6ef6, guest PC 0x0c0626a2 */
if(!s->budget--) { s->failed_pc=0x0c0626a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0626a4u,s,ram);
P_0c0626b0: /* original 2fe6, guest PC 0x0c0626b0 */
if(!s->budget--) { s->failed_pc=0x0c0626b0u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0626b2;
P_0c0626b2: /* original 2fd6, guest PC 0x0c0626b2 */
if(!s->budget--) { s->failed_pc=0x0c0626b2u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0626b4;
P_0c0626b4: /* original 2fc6, guest PC 0x0c0626b4 */
if(!s->budget--) { s->failed_pc=0x0c0626b4u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0626b6;
P_0c0626b6: /* original 2fb6, guest PC 0x0c0626b6 */
if(!s->budget--) { s->failed_pc=0x0c0626b6u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0626b8;
P_0c0626b8: /* original 2fa6, guest PC 0x0c0626b8 */
if(!s->budget--) { s->failed_pc=0x0c0626b8u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0626ba;
P_0c0626ba: /* original 6b53, guest PC 0x0c0626ba */
if(!s->budget--) { s->failed_pc=0x0c0626bau; return 0; }
r[11]=r[5];
goto P_0c0626bc;
P_0c0626bc: /* original 2f96, guest PC 0x0c0626bc */
if(!s->budget--) { s->failed_pc=0x0c0626bcu; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0626be;
P_0c0626be: /* original 6943, guest PC 0x0c0626be */
if(!s->budget--) { s->failed_pc=0x0c0626beu; return 0; }
r[9]=r[4];
return vf3_matrix_family(0x0c0626c0u,s,ram);
P_0c062df4: /* original d613, guest PC 0x0c062df4 */
if(!s->budget--) { s->failed_pc=0x0c062df4u; return 0; }
r[6]=read(ram,0x0c062e44u,4);
goto P_0c062df6;
P_0c062df6: /* original e500, guest PC 0x0c062df6 */
if(!s->budget--) { s->failed_pc=0x0c062df6u; return 0; }
r[5]=0x00000000u;
goto P_0c062df8;
P_0c062df8: /* original d313, guest PC 0x0c062df8 */
if(!s->budget--) { s->failed_pc=0x0c062df8u; return 0; }
r[3]=read(ram,0x0c062e48u,4);
goto P_0c062dfa;
P_0c062dfa: /* original 3432, guest PC 0x0c062dfa */
if(!s->budget--) { s->failed_pc=0x0c062dfau; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[3])!=0);
goto P_0c062dfc;
P_0c062dfc: /* original 8d0b, guest PC 0x0c062dfc */
if(!s->budget--) { s->failed_pc=0x0c062dfcu; return 0; }
cond=r[17]&1u;
r[7]=0x00000003u;
if(cond) { goto P_0c062e16; }
goto P_0c062e00;
P_0c062dfe: /* original e703, guest PC 0x0c062dfe */
if(!s->budget--) { s->failed_pc=0x0c062dfeu; return 0; }
r[7]=0x00000003u;
goto P_0c062e00;
P_0c062e00: /* original 3462, guest PC 0x0c062e00 */
if(!s->budget--) { s->failed_pc=0x0c062e00u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[6])!=0);
goto P_0c062e02;
P_0c062e02: /* original 8b01, guest PC 0x0c062e02 */
if(!s->budget--) { s->failed_pc=0x0c062e02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062e08; }
goto P_0c062e04;
P_0c062e04: /* original e504, guest PC 0x0c062e04 */
if(!s->budget--) { s->failed_pc=0x0c062e04u; return 0; }
r[5]=0x00000004u;
goto P_0c062e06;
P_0c062e06: /* original 3468, guest PC 0x0c062e06 */
if(!s->budget--) { s->failed_pc=0x0c062e06u; return 0; }
r[4]-=r[6];
goto P_0c062e08;
P_0c062e08: /* original e6fc, guest PC 0x0c062e08 */
if(!s->budget--) { s->failed_pc=0x0c062e08u; return 0; }
r[6]=0xfffffffcu;
goto P_0c062e0a;
P_0c062e0a: /* original 2649, guest PC 0x0c062e0a */
if(!s->budget--) { s->failed_pc=0x0c062e0au; return 0; }
r[6]&=r[4];
goto P_0c062e0c;
P_0c062e0c: /* original 4600, guest PC 0x0c062e0c */
if(!s->budget--) { s->failed_pc=0x0c062e0cu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c062e0e;
P_0c062e0e: /* original 2749, guest PC 0x0c062e0e */
if(!s->budget--) { s->failed_pc=0x0c062e0eu; return 0; }
r[7]&=r[4];
goto P_0c062e10;
P_0c062e10: /* original 367c, guest PC 0x0c062e10 */
if(!s->budget--) { s->failed_pc=0x0c062e10u; return 0; }
r[6]+=r[7];
goto P_0c062e12;
P_0c062e12: /* original a00d, guest PC 0x0c062e12 */
if(!s->budget--) { s->failed_pc=0x0c062e12u; return 0; }
r[6]+=r[5];
goto P_0c062e30;
P_0c062e14: /* original 365c, guest PC 0x0c062e14 */
if(!s->budget--) { s->failed_pc=0x0c062e14u; return 0; }
r[6]+=r[5];
goto P_0c062e16;
P_0c062e16: /* original d20d, guest PC 0x0c062e16 */
if(!s->budget--) { s->failed_pc=0x0c062e16u; return 0; }
r[2]=read(ram,0x0c062e4cu,4);
goto P_0c062e18;
P_0c062e18: /* original 3422, guest PC 0x0c062e18 */
if(!s->budget--) { s->failed_pc=0x0c062e18u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[2])!=0);
goto P_0c062e1a;
P_0c062e1a: /* original 8b01, guest PC 0x0c062e1a */
if(!s->budget--) { s->failed_pc=0x0c062e1au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062e20; }
goto P_0c062e1c;
P_0c062e1c: /* original e504, guest PC 0x0c062e1c */
if(!s->budget--) { s->failed_pc=0x0c062e1cu; return 0; }
r[5]=0x00000004u;
goto P_0c062e1e;
P_0c062e1e: /* original 3468, guest PC 0x0c062e1e */
if(!s->budget--) { s->failed_pc=0x0c062e1eu; return 0; }
r[4]-=r[6];
goto P_0c062e20;
P_0c062e20: /* original d30b, guest PC 0x0c062e20 */
if(!s->budget--) { s->failed_pc=0x0c062e20u; return 0; }
r[3]=read(ram,0x0c062e50u,4);
goto P_0c062e22;
P_0c062e22: /* original e6fc, guest PC 0x0c062e22 */
if(!s->budget--) { s->failed_pc=0x0c062e22u; return 0; }
r[6]=0xfffffffcu;
goto P_0c062e24;
P_0c062e24: /* original 2649, guest PC 0x0c062e24 */
if(!s->budget--) { s->failed_pc=0x0c062e24u; return 0; }
r[6]&=r[4];
goto P_0c062e26;
P_0c062e26: /* original 4600, guest PC 0x0c062e26 */
if(!s->budget--) { s->failed_pc=0x0c062e26u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c062e28;
P_0c062e28: /* original 2749, guest PC 0x0c062e28 */
if(!s->budget--) { s->failed_pc=0x0c062e28u; return 0; }
r[7]&=r[4];
goto P_0c062e2a;
P_0c062e2a: /* original 367c, guest PC 0x0c062e2a */
if(!s->budget--) { s->failed_pc=0x0c062e2au; return 0; }
r[6]+=r[7];
goto P_0c062e2c;
P_0c062e2c: /* original 365c, guest PC 0x0c062e2c */
if(!s->budget--) { s->failed_pc=0x0c062e2cu; return 0; }
r[6]+=r[5];
goto P_0c062e2e;
P_0c062e2e: /* original 363c, guest PC 0x0c062e2e */
if(!s->budget--) { s->failed_pc=0x0c062e2eu; return 0; }
r[6]+=r[3];
goto P_0c062e30;
P_0c062e30: /* original 000b, guest PC 0x0c062e30 */
if(!s->budget--) { s->failed_pc=0x0c062e30u; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c062e32: /* original 6063, guest PC 0x0c062e32 */
if(!s->budget--) { s->failed_pc=0x0c062e32u; return 0; }
r[0]=r[6];
return vf3_matrix_family(0x0c062e34u,s,ram);
P_0c062ec4: /* original 4f22, guest PC 0x0c062ec4 */
if(!s->budget--) { s->failed_pc=0x0c062ec4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c062ec6;
P_0c062ec6: /* original 6343, guest PC 0x0c062ec6 */
if(!s->budget--) { s->failed_pc=0x0c062ec6u; return 0; }
r[3]=r[4];
goto P_0c062ec8;
P_0c062ec8: /* original 430b, guest PC 0x0c062ec8 */
if(!s->budget--) { s->failed_pc=0x0c062ec8u; return 0; }
target=r[3];
r[16]=0x0c062eccu;
r[4]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c062eccu) { target=s->pc; goto dispatch; }
goto P_0c062ecc;
P_0c062eca: /* original 6453, guest PC 0x0c062eca */
if(!s->budget--) { s->failed_pc=0x0c062ecau; return 0; }
r[4]=r[5];
goto P_0c062ecc;
P_0c062ecc: /* original 4f26, guest PC 0x0c062ecc */
if(!s->budget--) { s->failed_pc=0x0c062eccu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c062ece;
P_0c062ece: /* original fff9, guest PC 0x0c062ece */
if(!s->budget--) { s->failed_pc=0x0c062eceu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ed0;
P_0c062ed0: /* original fef9, guest PC 0x0c062ed0 */
if(!s->budget--) { s->failed_pc=0x0c062ed0u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ed2;
P_0c062ed2: /* original fdf9, guest PC 0x0c062ed2 */
if(!s->budget--) { s->failed_pc=0x0c062ed2u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ed4;
P_0c062ed4: /* original fcf9, guest PC 0x0c062ed4 */
if(!s->budget--) { s->failed_pc=0x0c062ed4u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ed6;
P_0c062ed6: /* original fbf9, guest PC 0x0c062ed6 */
if(!s->budget--) { s->failed_pc=0x0c062ed6u; return 0; }
vf3_matrix_load(s,ram,11,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ed8;
P_0c062ed8: /* original faf9, guest PC 0x0c062ed8 */
if(!s->budget--) { s->failed_pc=0x0c062ed8u; return 0; }
vf3_matrix_load(s,ram,10,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062eda;
P_0c062eda: /* original f9f9, guest PC 0x0c062eda */
if(!s->budget--) { s->failed_pc=0x0c062edau; return 0; }
vf3_matrix_load(s,ram,9,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062edc;
P_0c062edc: /* original f8f9, guest PC 0x0c062edc */
if(!s->budget--) { s->failed_pc=0x0c062edcu; return 0; }
vf3_matrix_load(s,ram,8,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ede;
P_0c062ede: /* original f7f9, guest PC 0x0c062ede */
if(!s->budget--) { s->failed_pc=0x0c062edeu; return 0; }
vf3_matrix_load(s,ram,7,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ee0;
P_0c062ee0: /* original f6f9, guest PC 0x0c062ee0 */
if(!s->budget--) { s->failed_pc=0x0c062ee0u; return 0; }
vf3_matrix_load(s,ram,6,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ee2;
P_0c062ee2: /* original f5f9, guest PC 0x0c062ee2 */
if(!s->budget--) { s->failed_pc=0x0c062ee2u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ee4;
P_0c062ee4: /* original f4f9, guest PC 0x0c062ee4 */
if(!s->budget--) { s->failed_pc=0x0c062ee4u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ee6;
P_0c062ee6: /* original f3f9, guest PC 0x0c062ee6 */
if(!s->budget--) { s->failed_pc=0x0c062ee6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062ee8;
P_0c062ee8: /* original f2f9, guest PC 0x0c062ee8 */
if(!s->budget--) { s->failed_pc=0x0c062ee8u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062eea;
P_0c062eea: /* original f1f9, guest PC 0x0c062eea */
if(!s->budget--) { s->failed_pc=0x0c062eeau; return 0; }
vf3_matrix_load(s,ram,1,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062eec;
P_0c062eec: /* original f0f9, guest PC 0x0c062eec */
if(!s->budget--) { s->failed_pc=0x0c062eecu; return 0; }
vf3_matrix_load(s,ram,0,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c062eee;
P_0c062eee: /* original 60f6, guest PC 0x0c062eee */
if(!s->budget--) { s->failed_pc=0x0c062eeeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[0]=tmp;
goto P_0c062ef0;
P_0c062ef0: /* original 406a, guest PC 0x0c062ef0 */
if(!s->budget--) { s->failed_pc=0x0c062ef0u; return 0; }
r[18]=r[0];
goto P_0c062ef2;
P_0c062ef2: /* original 000b, guest PC 0x0c062ef2 */
if(!s->budget--) { s->failed_pc=0x0c062ef2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062ef4: /* original 0009, guest PC 0x0c062ef4 */
if(!s->budget--) { s->failed_pc=0x0c062ef4u; return 0; }
return vf3_matrix_family(0x0c062ef6u,s,ram);
P_0c062ef8: /* original d543, guest PC 0x0c062ef8 */
if(!s->budget--) { s->failed_pc=0x0c062ef8u; return 0; }
r[5]=read(ram,0x0c063008u,4);
goto P_0c062efa;
P_0c062efa: /* original 6352, guest PC 0x0c062efa */
if(!s->budget--) { s->failed_pc=0x0c062efau; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c062efc;
P_0c062efc: /* original e400, guest PC 0x0c062efc */
if(!s->budget--) { s->failed_pc=0x0c062efcu; return 0; }
r[4]=0x00000000u;
goto P_0c062efe;
P_0c062efe: /* original d243, guest PC 0x0c062efe */
if(!s->budget--) { s->failed_pc=0x0c062efeu; return 0; }
r[2]=read(ram,0x0c06300cu,4);
goto P_0c062f00;
P_0c062f00: /* original 2242, guest PC 0x0c062f00 */
if(!s->budget--) { s->failed_pc=0x0c062f00u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c062f02;
P_0c062f02: /* original d343, guest PC 0x0c062f02 */
if(!s->budget--) { s->failed_pc=0x0c062f02u; return 0; }
r[3]=read(ram,0x0c063010u,4);
goto P_0c062f04;
P_0c062f04: /* original 2342, guest PC 0x0c062f04 */
if(!s->budget--) { s->failed_pc=0x0c062f04u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c062f06;
P_0c062f06: /* original d143, guest PC 0x0c062f06 */
if(!s->budget--) { s->failed_pc=0x0c062f06u; return 0; }
r[1]=read(ram,0x0c063014u,4);
goto P_0c062f08;
P_0c062f08: /* original 2142, guest PC 0x0c062f08 */
if(!s->budget--) { s->failed_pc=0x0c062f08u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c062f0a;
P_0c062f0a: /* original 9279, guest PC 0x0c062f0a */
if(!s->budget--) { s->failed_pc=0x0c062f0au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063000u,2);
goto P_0c062f0c;
P_0c062f0c: /* original 2522, guest PC 0x0c062f0c */
if(!s->budget--) { s->failed_pc=0x0c062f0cu; return 0; }
write(ram,r[5],r[2],4);
goto P_0c062f0e;
P_0c062f0e: /* original d042, guest PC 0x0c062f0e */
if(!s->budget--) { s->failed_pc=0x0c062f0eu; return 0; }
r[0]=read(ram,0x0c063018u,4);
goto P_0c062f10;
P_0c062f10: /* original d242, guest PC 0x0c062f10 */
if(!s->budget--) { s->failed_pc=0x0c062f10u; return 0; }
r[2]=read(ram,0x0c06301cu,4);
goto P_0c062f12;
P_0c062f12: /* original 2202, guest PC 0x0c062f12 */
if(!s->budget--) { s->failed_pc=0x0c062f12u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c062f14;
P_0c062f14: /* original d342, guest PC 0x0c062f14 */
if(!s->budget--) { s->failed_pc=0x0c062f14u; return 0; }
r[3]=read(ram,0x0c063020u,4);
goto P_0c062f16;
P_0c062f16: /* original 2342, guest PC 0x0c062f16 */
if(!s->budget--) { s->failed_pc=0x0c062f16u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c062f18;
P_0c062f18: /* original d142, guest PC 0x0c062f18 */
if(!s->budget--) { s->failed_pc=0x0c062f18u; return 0; }
r[1]=read(ram,0x0c063024u,4);
goto P_0c062f1a;
P_0c062f1a: /* original e510, guest PC 0x0c062f1a */
if(!s->budget--) { s->failed_pc=0x0c062f1au; return 0; }
r[5]=0x00000010u;
goto P_0c062f1c;
P_0c062f1c: /* original 2152, guest PC 0x0c062f1c */
if(!s->budget--) { s->failed_pc=0x0c062f1cu; return 0; }
write(ram,r[1],r[5],4);
goto P_0c062f1e;
P_0c062f1e: /* original d242, guest PC 0x0c062f1e */
if(!s->budget--) { s->failed_pc=0x0c062f1eu; return 0; }
r[2]=read(ram,0x0c063028u,4);
goto P_0c062f20;
P_0c062f20: /* original 2252, guest PC 0x0c062f20 */
if(!s->budget--) { s->failed_pc=0x0c062f20u; return 0; }
write(ram,r[2],r[5],4);
goto P_0c062f22;
P_0c062f22: /* original e107, guest PC 0x0c062f22 */
if(!s->budget--) { s->failed_pc=0x0c062f22u; return 0; }
r[1]=0x00000007u;
goto P_0c062f24;
P_0c062f24: /* original d044, guest PC 0x0c062f24 */
if(!s->budget--) { s->failed_pc=0x0c062f24u; return 0; }
r[0]=read(ram,0x0c063038u,4);
goto P_0c062f26;
P_0c062f26: /* original d541, guest PC 0x0c062f26 */
if(!s->budget--) { s->failed_pc=0x0c062f26u; return 0; }
r[5]=read(ram,0x0c06302cu,4);
goto P_0c062f28;
P_0c062f28: /* original d342, guest PC 0x0c062f28 */
if(!s->budget--) { s->failed_pc=0x0c062f28u; return 0; }
r[3]=read(ram,0x0c063034u,4);
goto P_0c062f2a;
P_0c062f2a: /* original 2542, guest PC 0x0c062f2a */
if(!s->budget--) { s->failed_pc=0x0c062f2au; return 0; }
write(ram,r[5],r[4],4);
goto P_0c062f2c;
P_0c062f2c: /* original 1541, guest PC 0x0c062f2c */
if(!s->budget--) { s->failed_pc=0x0c062f2cu; return 0; }
write(ram,r[5]+4,r[4],4);
goto P_0c062f2e;
P_0c062f2e: /* original d540, guest PC 0x0c062f2e */
if(!s->budget--) { s->failed_pc=0x0c062f2eu; return 0; }
r[5]=read(ram,0x0c063030u,4);
goto P_0c062f30;
P_0c062f30: /* original 2542, guest PC 0x0c062f30 */
if(!s->budget--) { s->failed_pc=0x0c062f30u; return 0; }
write(ram,r[5],r[4],4);
goto P_0c062f32;
P_0c062f32: /* original 1541, guest PC 0x0c062f32 */
if(!s->budget--) { s->failed_pc=0x0c062f32u; return 0; }
write(ram,r[5]+4,r[4],4);
goto P_0c062f34;
P_0c062f34: /* original 2342, guest PC 0x0c062f34 */
if(!s->budget--) { s->failed_pc=0x0c062f34u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c062f36;
P_0c062f36: /* original e201, guest PC 0x0c062f36 */
if(!s->budget--) { s->failed_pc=0x0c062f36u; return 0; }
r[2]=0x00000001u;
goto P_0c062f38;
P_0c062f38: /* original 2012, guest PC 0x0c062f38 */
if(!s->budget--) { s->failed_pc=0x0c062f38u; return 0; }
write(ram,r[0],r[1],4);
goto P_0c062f3a;
P_0c062f3a: /* original 6743, guest PC 0x0c062f3a */
if(!s->budget--) { s->failed_pc=0x0c062f3au; return 0; }
r[7]=r[4];
goto P_0c062f3c;
P_0c062f3c: /* original d13f, guest PC 0x0c062f3c */
if(!s->budget--) { s->failed_pc=0x0c062f3cu; return 0; }
r[1]=read(ram,0x0c06303cu,4);
goto P_0c062f3e;
P_0c062f3e: /* original 6643, guest PC 0x0c062f3e */
if(!s->budget--) { s->failed_pc=0x0c062f3eu; return 0; }
r[6]=r[4];
goto P_0c062f40;
P_0c062f40: /* original 2122, guest PC 0x0c062f40 */
if(!s->budget--) { s->failed_pc=0x0c062f40u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c062f42;
P_0c062f42: /* original e508, guest PC 0x0c062f42 */
if(!s->budget--) { s->failed_pc=0x0c062f42u; return 0; }
r[5]=0x00000008u;
goto P_0c062f44;
P_0c062f44: /* original 915d, guest PC 0x0c062f44 */
if(!s->budget--) { s->failed_pc=0x0c062f44u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063002u,2);
goto P_0c062f46;
P_0c062f46: /* original d23e, guest PC 0x0c062f46 */
if(!s->budget--) { s->failed_pc=0x0c062f46u; return 0; }
r[2]=read(ram,0x0c063040u,4);
goto P_0c062f48;
P_0c062f48: /* original 6023, guest PC 0x0c062f48 */
if(!s->budget--) { s->failed_pc=0x0c062f48u; return 0; }
r[0]=r[2];
goto P_0c062f4a;
P_0c062f4a: /* original 0009, guest PC 0x0c062f4a */
if(!s->budget--) { s->failed_pc=0x0c062f4au; return 0; }
goto P_0c062f4c;
P_0c062f4c: /* original 306c, guest PC 0x0c062f4c */
if(!s->budget--) { s->failed_pc=0x0c062f4cu; return 0; }
r[0]+=r[6];
goto P_0c062f4e;
P_0c062f4e: /* original 7701, guest PC 0x0c062f4e */
if(!s->budget--) { s->failed_pc=0x0c062f4eu; return 0; }
r[7]+=0x00000001u;
goto P_0c062f50;
P_0c062f50: /* original 1046, guest PC 0x0c062f50 */
if(!s->budget--) { s->failed_pc=0x0c062f50u; return 0; }
write(ram,r[0]+24,r[4],4);
goto P_0c062f52;
P_0c062f52: /* original 3752, guest PC 0x0c062f52 */
if(!s->budget--) { s->failed_pc=0x0c062f52u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[5])!=0);
goto P_0c062f54;
P_0c062f54: /* original 301c, guest PC 0x0c062f54 */
if(!s->budget--) { s->failed_pc=0x0c062f54u; return 0; }
r[0]+=r[1];
goto P_0c062f56;
P_0c062f56: /* original 1056, guest PC 0x0c062f56 */
if(!s->budget--) { s->failed_pc=0x0c062f56u; return 0; }
write(ram,r[0]+24,r[5],4);
goto P_0c062f58;
P_0c062f58: /* original 8ff6, guest PC 0x0c062f58 */
if(!s->budget--) { s->failed_pc=0x0c062f58u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000020u;
if(!cond) { goto P_0c062f48; }
goto P_0c062f5c;
P_0c062f5a: /* original 7620, guest PC 0x0c062f5a */
if(!s->budget--) { s->failed_pc=0x0c062f5au; return 0; }
r[6]+=0x00000020u;
goto P_0c062f5c;
P_0c062f5c: /* original 000b, guest PC 0x0c062f5c */
if(!s->budget--) { s->failed_pc=0x0c062f5cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062f5e: /* original 0009, guest PC 0x0c062f5e */
if(!s->budget--) { s->failed_pc=0x0c062f5eu; return 0; }
return vf3_matrix_family(0x0c062f60u,s,ram);
P_0c0636ac: /* original 4f22, guest PC 0x0c0636ac */
if(!s->budget--) { s->failed_pc=0x0c0636acu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0636ae;
P_0c0636ae: /* original db18, guest PC 0x0c0636ae */
if(!s->budget--) { s->failed_pc=0x0c0636aeu; return 0; }
r[11]=read(ram,0x0c063710u,4);
goto P_0c0636b0;
P_0c0636b0: /* original d518, guest PC 0x0c0636b0 */
if(!s->budget--) { s->failed_pc=0x0c0636b0u; return 0; }
r[5]=read(ram,0x0c063714u,4);
goto P_0c0636b2;
P_0c0636b2: /* original 9426, guest PC 0x0c0636b2 */
if(!s->budget--) { s->failed_pc=0x0c0636b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063702u,2);
goto P_0c0636b4;
P_0c0636b4: /* original 4b0b, guest PC 0x0c0636b4 */
if(!s->budget--) { s->failed_pc=0x0c0636b4u; return 0; }
target=r[11];
r[16]=0x0c0636b8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0636b8u) { target=s->pc; goto dispatch; }
goto P_0c0636b8;
P_0c0636b6: /* original 0009, guest PC 0x0c0636b6 */
if(!s->budget--) { s->failed_pc=0x0c0636b6u; return 0; }
goto P_0c0636b8;
P_0c0636b8: /* original d517, guest PC 0x0c0636b8 */
if(!s->budget--) { s->failed_pc=0x0c0636b8u; return 0; }
r[5]=read(ram,0x0c063718u,4);
goto P_0c0636ba;
P_0c0636ba: /* original 9423, guest PC 0x0c0636ba */
if(!s->budget--) { s->failed_pc=0x0c0636bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063704u,2);
goto P_0c0636bc;
P_0c0636bc: /* original 4b0b, guest PC 0x0c0636bc */
if(!s->budget--) { s->failed_pc=0x0c0636bcu; return 0; }
target=r[11];
r[16]=0x0c0636c0u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0636c0u) { target=s->pc; goto dispatch; }
goto P_0c0636c0;
P_0c0636be: /* original 0009, guest PC 0x0c0636be */
if(!s->budget--) { s->failed_pc=0x0c0636beu; return 0; }
goto P_0c0636c0;
P_0c0636c0: /* original d515, guest PC 0x0c0636c0 */
if(!s->budget--) { s->failed_pc=0x0c0636c0u; return 0; }
r[5]=read(ram,0x0c063718u,4);
goto P_0c0636c2;
P_0c0636c2: /* original 9420, guest PC 0x0c0636c2 */
if(!s->budget--) { s->failed_pc=0x0c0636c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063706u,2);
goto P_0c0636c4;
P_0c0636c4: /* original 4b0b, guest PC 0x0c0636c4 */
if(!s->budget--) { s->failed_pc=0x0c0636c4u; return 0; }
target=r[11];
r[16]=0x0c0636c8u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0636c8u) { target=s->pc; goto dispatch; }
goto P_0c0636c8;
P_0c0636c6: /* original 0009, guest PC 0x0c0636c6 */
if(!s->budget--) { s->failed_pc=0x0c0636c6u; return 0; }
goto P_0c0636c8;
P_0c0636c8: /* original 9e1e, guest PC 0x0c0636c8 */
if(!s->budget--) { s->failed_pc=0x0c0636c8u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063708u,2);
goto P_0c0636ca;
P_0c0636ca: /* original ea00, guest PC 0x0c0636ca */
if(!s->budget--) { s->failed_pc=0x0c0636cau; return 0; }
r[10]=0x00000000u;
goto P_0c0636cc;
P_0c0636cc: /* original 9c1d, guest PC 0x0c0636cc */
if(!s->budget--) { s->failed_pc=0x0c0636ccu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06370au,2);
goto P_0c0636ce;
P_0c0636ce: /* original 69c3, guest PC 0x0c0636ce */
if(!s->budget--) { s->failed_pc=0x0c0636ceu; return 0; }
r[9]=r[12];
goto P_0c0636d0;
P_0c0636d0: /* original 9d1c, guest PC 0x0c0636d0 */
if(!s->budget--) { s->failed_pc=0x0c0636d0u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06370cu,2);
goto P_0c0636d2;
P_0c0636d2: /* original 7982, guest PC 0x0c0636d2 */
if(!s->budget--) { s->failed_pc=0x0c0636d2u; return 0; }
r[9]+=0xffffff82u;
goto P_0c0636d4;
P_0c0636d4: /* original 65dc, guest PC 0x0c0636d4 */
if(!s->budget--) { s->failed_pc=0x0c0636d4u; return 0; }
r[5]=r[13]&255u;
goto P_0c0636d6;
P_0c0636d6: /* original 4518, guest PC 0x0c0636d6 */
if(!s->budget--) { s->failed_pc=0x0c0636d6u; return 0; }
r[5]<<=8;
goto P_0c0636d8;
P_0c0636d8: /* original 63cc, guest PC 0x0c0636d8 */
if(!s->budget--) { s->failed_pc=0x0c0636d8u; return 0; }
r[3]=r[12]&255u;
goto P_0c0636da;
P_0c0636da: /* original 253b, guest PC 0x0c0636da */
if(!s->budget--) { s->failed_pc=0x0c0636dau; return 0; }
r[5]|=r[3];
goto P_0c0636dc;
P_0c0636dc: /* original 655d, guest PC 0x0c0636dc */
if(!s->budget--) { s->failed_pc=0x0c0636dcu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0636de;
P_0c0636de: /* original 4b0b, guest PC 0x0c0636de */
if(!s->budget--) { s->failed_pc=0x0c0636deu; return 0; }
target=r[11];
r[16]=0x0c0636e2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0636e2u) { target=s->pc; goto dispatch; }
goto P_0c0636e2;
P_0c0636e0: /* original 64e3, guest PC 0x0c0636e0 */
if(!s->budget--) { s->failed_pc=0x0c0636e0u; return 0; }
r[4]=r[14];
goto P_0c0636e2;
P_0c0636e2: /* original 7a01, guest PC 0x0c0636e2 */
if(!s->budget--) { s->failed_pc=0x0c0636e2u; return 0; }
r[10]+=0x00000001u;
goto P_0c0636e4;
P_0c0636e4: /* original 7e04, guest PC 0x0c0636e4 */
if(!s->budget--) { s->failed_pc=0x0c0636e4u; return 0; }
r[14]+=0x00000004u;
goto P_0c0636e6;
P_0c0636e6: /* original 7cff, guest PC 0x0c0636e6 */
if(!s->budget--) { s->failed_pc=0x0c0636e6u; return 0; }
r[12]+=0xffffffffu;
goto P_0c0636e8;
P_0c0636e8: /* original 3a93, guest PC 0x0c0636e8 */
if(!s->budget--) { s->failed_pc=0x0c0636e8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[9])!=0);
goto P_0c0636ea;
P_0c0636ea: /* original 8ff3, guest PC 0x0c0636ea */
if(!s->budget--) { s->failed_pc=0x0c0636eau; return 0; }
cond=r[17]&1u;
r[13]+=0xffffffffu;
if(!cond) { goto P_0c0636d4; }
goto P_0c0636ee;
P_0c0636ec: /* original 7dff, guest PC 0x0c0636ec */
if(!s->budget--) { s->failed_pc=0x0c0636ecu; return 0; }
r[13]+=0xffffffffu;
goto P_0c0636ee;
P_0c0636ee: /* original 4f26, guest PC 0x0c0636ee */
if(!s->budget--) { s->failed_pc=0x0c0636eeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0636f0;
P_0c0636f0: /* original 69f6, guest PC 0x0c0636f0 */
if(!s->budget--) { s->failed_pc=0x0c0636f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0636f2;
P_0c0636f2: /* original 6af6, guest PC 0x0c0636f2 */
if(!s->budget--) { s->failed_pc=0x0c0636f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0636f4;
P_0c0636f4: /* original 6bf6, guest PC 0x0c0636f4 */
if(!s->budget--) { s->failed_pc=0x0c0636f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0636f6;
P_0c0636f6: /* original 6cf6, guest PC 0x0c0636f6 */
if(!s->budget--) { s->failed_pc=0x0c0636f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0636f8;
P_0c0636f8: /* original 6df6, guest PC 0x0c0636f8 */
if(!s->budget--) { s->failed_pc=0x0c0636f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0636fa;
P_0c0636fa: /* original 000b, guest PC 0x0c0636fa */
if(!s->budget--) { s->failed_pc=0x0c0636fau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0636fc: /* original 6ef6, guest PC 0x0c0636fc */
if(!s->budget--) { s->failed_pc=0x0c0636fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0636feu,s,ram);
P_0c06371c: /* original 4f22, guest PC 0x0c06371c */
if(!s->budget--) { s->failed_pc=0x0c06371cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06371e;
P_0c06371e: /* original d444, guest PC 0x0c06371e */
if(!s->budget--) { s->failed_pc=0x0c06371eu; return 0; }
r[4]=read(ram,0x0c063830u,4);
goto P_0c063720;
P_0c063720: /* original d344, guest PC 0x0c063720 */
if(!s->budget--) { s->failed_pc=0x0c063720u; return 0; }
r[3]=read(ram,0x0c063834u,4);
goto P_0c063722;
P_0c063722: /* original 430b, guest PC 0x0c063722 */
if(!s->budget--) { s->failed_pc=0x0c063722u; return 0; }
target=r[3];
r[16]=0x0c063726u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c063726u) { target=s->pc; goto dispatch; }
goto P_0c063726;
P_0c063724: /* original 0009, guest PC 0x0c063724 */
if(!s->budget--) { s->failed_pc=0x0c063724u; return 0; }
goto P_0c063726;
P_0c063726: /* original e400, guest PC 0x0c063726 */
if(!s->budget--) { s->failed_pc=0x0c063726u; return 0; }
r[4]=0x00000000u;
goto P_0c063728;
P_0c063728: /* original d243, guest PC 0x0c063728 */
if(!s->budget--) { s->failed_pc=0x0c063728u; return 0; }
r[2]=read(ram,0x0c063838u,4);
goto P_0c06372a;
P_0c06372a: /* original 2242, guest PC 0x0c06372a */
if(!s->budget--) { s->failed_pc=0x0c06372au; return 0; }
write(ram,r[2],r[4],4);
goto P_0c06372c;
P_0c06372c: /* original d343, guest PC 0x0c06372c */
if(!s->budget--) { s->failed_pc=0x0c06372cu; return 0; }
r[3]=read(ram,0x0c06383cu,4);
goto P_0c06372e;
P_0c06372e: /* original 2342, guest PC 0x0c06372e */
if(!s->budget--) { s->failed_pc=0x0c06372eu; return 0; }
write(ram,r[3],r[4],4);
goto P_0c063730;
P_0c063730: /* original d143, guest PC 0x0c063730 */
if(!s->budget--) { s->failed_pc=0x0c063730u; return 0; }
r[1]=read(ram,0x0c063840u,4);
goto P_0c063732;
P_0c063732: /* original 2142, guest PC 0x0c063732 */
if(!s->budget--) { s->failed_pc=0x0c063732u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c063734;
P_0c063734: /* original d243, guest PC 0x0c063734 */
if(!s->budget--) { s->failed_pc=0x0c063734u; return 0; }
r[2]=read(ram,0x0c063844u,4);
goto P_0c063736;
P_0c063736: /* original 2242, guest PC 0x0c063736 */
if(!s->budget--) { s->failed_pc=0x0c063736u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c063738;
P_0c063738: /* original d543, guest PC 0x0c063738 */
if(!s->budget--) { s->failed_pc=0x0c063738u; return 0; }
r[5]=read(ram,0x0c063848u,4);
goto P_0c06373a;
P_0c06373a: /* original 6743, guest PC 0x0c06373a */
if(!s->budget--) { s->failed_pc=0x0c06373au; return 0; }
r[7]=r[4];
goto P_0c06373c;
P_0c06373c: /* original d343, guest PC 0x0c06373c */
if(!s->budget--) { s->failed_pc=0x0c06373cu; return 0; }
r[3]=read(ram,0x0c06384cu,4);
goto P_0c06373e;
P_0c06373e: /* original e005, guest PC 0x0c06373e */
if(!s->budget--) { s->failed_pc=0x0c06373eu; return 0; }
r[0]=0x00000005u;
goto P_0c063740;
P_0c063740: /* original 2542, guest PC 0x0c063740 */
if(!s->budget--) { s->failed_pc=0x0c063740u; return 0; }
write(ram,r[5],r[4],4);
goto P_0c063742;
P_0c063742: /* original e600, guest PC 0x0c063742 */
if(!s->budget--) { s->failed_pc=0x0c063742u; return 0; }
r[6]=0x00000000u;
goto P_0c063744;
P_0c063744: /* original 1541, guest PC 0x0c063744 */
if(!s->budget--) { s->failed_pc=0x0c063744u; return 0; }
write(ram,r[5]+4,r[4],4);
goto P_0c063746;
P_0c063746: /* original 1542, guest PC 0x0c063746 */
if(!s->budget--) { s->failed_pc=0x0c063746u; return 0; }
write(ram,r[5]+8,r[4],4);
goto P_0c063748;
P_0c063748: /* original 1543, guest PC 0x0c063748 */
if(!s->budget--) { s->failed_pc=0x0c063748u; return 0; }
write(ram,r[5]+12,r[4],4);
goto P_0c06374a;
P_0c06374a: /* original 1544, guest PC 0x0c06374a */
if(!s->budget--) { s->failed_pc=0x0c06374au; return 0; }
write(ram,r[5]+16,r[4],4);
goto P_0c06374c;
P_0c06374c: /* original 1545, guest PC 0x0c06374c */
if(!s->budget--) { s->failed_pc=0x0c06374cu; return 0; }
write(ram,r[5]+20,r[4],4);
goto P_0c06374e;
P_0c06374e: /* original 1546, guest PC 0x0c06374e */
if(!s->budget--) { s->failed_pc=0x0c06374eu; return 0; }
write(ram,r[5]+24,r[4],4);
goto P_0c063750;
P_0c063750: /* original 1547, guest PC 0x0c063750 */
if(!s->budget--) { s->failed_pc=0x0c063750u; return 0; }
write(ram,r[5]+28,r[4],4);
goto P_0c063752;
P_0c063752: /* original 1548, guest PC 0x0c063752 */
if(!s->budget--) { s->failed_pc=0x0c063752u; return 0; }
write(ram,r[5]+32,r[4],4);
goto P_0c063754;
P_0c063754: /* original 2342, guest PC 0x0c063754 */
if(!s->budget--) { s->failed_pc=0x0c063754u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c063756;
P_0c063756: /* original 6253, guest PC 0x0c063756 */
if(!s->budget--) { s->failed_pc=0x0c063756u; return 0; }
r[2]=r[5];
goto P_0c063758;
P_0c063758: /* original 722c, guest PC 0x0c063758 */
if(!s->budget--) { s->failed_pc=0x0c063758u; return 0; }
r[2]+=0x0000002cu;
goto P_0c06375a;
P_0c06375a: /* original 326c, guest PC 0x0c06375a */
if(!s->budget--) { s->failed_pc=0x0c06375au; return 0; }
r[2]+=r[6];
goto P_0c06375c;
P_0c06375c: /* original 2242, guest PC 0x0c06375c */
if(!s->budget--) { s->failed_pc=0x0c06375cu; return 0; }
write(ram,r[2],r[4],4);
goto P_0c06375e;
P_0c06375e: /* original 7701, guest PC 0x0c06375e */
if(!s->budget--) { s->failed_pc=0x0c06375eu; return 0; }
r[7]+=0x00000001u;
goto P_0c063760;
P_0c063760: /* original 3702, guest PC 0x0c063760 */
if(!s->budget--) { s->failed_pc=0x0c063760u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[0])!=0);
goto P_0c063762;
P_0c063762: /* original 8ff8, guest PC 0x0c063762 */
if(!s->budget--) { s->failed_pc=0x0c063762u; return 0; }
cond=r[17]&1u;
r[6]+=0x00000004u;
if(!cond) { goto P_0c063756; }
goto P_0c063766;
P_0c063764: /* original 7604, guest PC 0x0c063764 */
if(!s->budget--) { s->failed_pc=0x0c063764u; return 0; }
r[6]+=0x00000004u;
goto P_0c063766;
P_0c063766: /* original 4f26, guest PC 0x0c063766 */
if(!s->budget--) { s->failed_pc=0x0c063766u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c063768;
P_0c063768: /* original 000b, guest PC 0x0c063768 */
if(!s->budget--) { s->failed_pc=0x0c063768u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06376a: /* original 0009, guest PC 0x0c06376a */
if(!s->budget--) { s->failed_pc=0x0c06376au; return 0; }
return vf3_matrix_family(0x0c06376cu,s,ram);
P_0c0645fa: /* original 4f22, guest PC 0x0c0645fa */
if(!s->budget--) { s->failed_pc=0x0c0645fau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0645fc;
P_0c0645fc: /* original 7ff0, guest PC 0x0c0645fc */
if(!s->budget--) { s->failed_pc=0x0c0645fcu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0645fe;
P_0c0645fe: /* original 6df3, guest PC 0x0c0645fe */
if(!s->budget--) { s->failed_pc=0x0c0645feu; return 0; }
r[13]=r[15];
goto P_0c064600;
P_0c064600: /* original 6342, guest PC 0x0c064600 */
if(!s->budget--) { s->failed_pc=0x0c064600u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c064602;
P_0c064602: /* original 7d04, guest PC 0x0c064602 */
if(!s->budget--) { s->failed_pc=0x0c064602u; return 0; }
r[13]+=0x00000004u;
goto P_0c064604;
P_0c064604: /* original 6ed3, guest PC 0x0c064604 */
if(!s->budget--) { s->failed_pc=0x0c064604u; return 0; }
r[14]=r[13];
goto P_0c064606;
P_0c064606: /* original 66e3, guest PC 0x0c064606 */
if(!s->budget--) { s->failed_pc=0x0c064606u; return 0; }
r[6]=r[14];
goto P_0c064608;
P_0c064608: /* original 2e32, guest PC 0x0c064608 */
if(!s->budget--) { s->failed_pc=0x0c064608u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c06460a;
P_0c06460a: /* original 67e3, guest PC 0x0c06460a */
if(!s->budget--) { s->failed_pc=0x0c06460au; return 0; }
r[7]=r[14];
goto P_0c06460c;
P_0c06460c: /* original 5241, guest PC 0x0c06460c */
if(!s->budget--) { s->failed_pc=0x0c06460cu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c06460e;
P_0c06460e: /* original 7604, guest PC 0x0c06460e */
if(!s->budget--) { s->failed_pc=0x0c06460eu; return 0; }
r[6]+=0x00000004u;
goto P_0c064610;
P_0c064610: /* original 2622, guest PC 0x0c064610 */
if(!s->budget--) { s->failed_pc=0x0c064610u; return 0; }
write(ram,r[6],r[2],4);
goto P_0c064612;
P_0c064612: /* original 7708, guest PC 0x0c064612 */
if(!s->budget--) { s->failed_pc=0x0c064612u; return 0; }
r[7]+=0x00000008u;
goto P_0c064614;
P_0c064614: /* original 5342, guest PC 0x0c064614 */
if(!s->budget--) { s->failed_pc=0x0c064614u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c064616;
P_0c064616: /* original 2732, guest PC 0x0c064616 */
if(!s->budget--) { s->failed_pc=0x0c064616u; return 0; }
write(ram,r[7],r[3],4);
goto P_0c064618;
P_0c064618: /* original d250, guest PC 0x0c064618 */
if(!s->budget--) { s->failed_pc=0x0c064618u; return 0; }
r[2]=read(ram,0x0c06475cu,4);
goto P_0c06461a;
P_0c06461a: /* original 6d22, guest PC 0x0c06461a */
if(!s->budget--) { s->failed_pc=0x0c06461au; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c06461c;
P_0c06461c: /* original d150, guest PC 0x0c06461c */
if(!s->budget--) { s->failed_pc=0x0c06461cu; return 0; }
r[1]=read(ram,0x0c064760u,4);
goto P_0c06461e;
P_0c06461e: /* original 6312, guest PC 0x0c06461e */
if(!s->budget--) { s->failed_pc=0x0c06461eu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c064620;
P_0c064620: /* original 2f32, guest PC 0x0c064620 */
if(!s->budget--) { s->failed_pc=0x0c064620u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c064622;
P_0c064622: /* original d350, guest PC 0x0c064622 */
if(!s->budget--) { s->failed_pc=0x0c064622u; return 0; }
r[3]=read(ram,0x0c064764u,4);
goto P_0c064624;
P_0c064624: /* original 6432, guest PC 0x0c064624 */
if(!s->budget--) { s->failed_pc=0x0c064624u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c064626;
P_0c064626: /* original d03a, guest PC 0x0c064626 */
if(!s->budget--) { s->failed_pc=0x0c064626u; return 0; }
r[0]=read(ram,0x0c064710u,4);
goto P_0c064628;
P_0c064628: /* original 6253, guest PC 0x0c064628 */
if(!s->budget--) { s->failed_pc=0x0c064628u; return 0; }
r[2]=r[5];
goto P_0c06462a;
P_0c06462a: /* original 7501, guest PC 0x0c06462a */
if(!s->budget--) { s->failed_pc=0x0c06462au; return 0; }
r[5]+=0x00000001u;
goto P_0c06462c;
P_0c06462c: /* original 4208, guest PC 0x0c06462c */
if(!s->budget--) { s->failed_pc=0x0c06462cu; return 0; }
r[2]<<=2;
goto P_0c06462e;
P_0c06462e: /* original 02d6, guest PC 0x0c06462e */
if(!s->budget--) { s->failed_pc=0x0c06462eu; return 0; }
write(ram,r[2]+r[0],r[13],4);
goto P_0c064630;
P_0c064630: /* original 6153, guest PC 0x0c064630 */
if(!s->budget--) { s->failed_pc=0x0c064630u; return 0; }
r[1]=r[5];
goto P_0c064632;
P_0c064632: /* original 7501, guest PC 0x0c064632 */
if(!s->budget--) { s->failed_pc=0x0c064632u; return 0; }
r[5]+=0x00000001u;
goto P_0c064634;
P_0c064634: /* original 62f2, guest PC 0x0c064634 */
if(!s->budget--) { s->failed_pc=0x0c064634u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c064636;
P_0c064636: /* original 4108, guest PC 0x0c064636 */
if(!s->budget--) { s->failed_pc=0x0c064636u; return 0; }
r[1]<<=2;
goto P_0c064638;
P_0c064638: /* original 0126, guest PC 0x0c064638 */
if(!s->budget--) { s->failed_pc=0x0c064638u; return 0; }
write(ram,r[1]+r[0],r[2],4);
goto P_0c06463a;
P_0c06463a: /* original 6153, guest PC 0x0c06463a */
if(!s->budget--) { s->failed_pc=0x0c06463au; return 0; }
r[1]=r[5];
goto P_0c06463c;
P_0c06463c: /* original 7501, guest PC 0x0c06463c */
if(!s->budget--) { s->failed_pc=0x0c06463cu; return 0; }
r[5]+=0x00000001u;
goto P_0c06463e;
P_0c06463e: /* original 4108, guest PC 0x0c06463e */
if(!s->budget--) { s->failed_pc=0x0c06463eu; return 0; }
r[1]<<=2;
goto P_0c064640;
P_0c064640: /* original 0146, guest PC 0x0c064640 */
if(!s->budget--) { s->failed_pc=0x0c064640u; return 0; }
write(ram,r[1]+r[0],r[4],4);
goto P_0c064642;
P_0c064642: /* original 6253, guest PC 0x0c064642 */
if(!s->budget--) { s->failed_pc=0x0c064642u; return 0; }
r[2]=r[5];
goto P_0c064644;
P_0c064644: /* original 61e2, guest PC 0x0c064644 */
if(!s->budget--) { s->failed_pc=0x0c064644u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c064646;
P_0c064646: /* original 7501, guest PC 0x0c064646 */
if(!s->budget--) { s->failed_pc=0x0c064646u; return 0; }
r[5]+=0x00000001u;
goto P_0c064648;
P_0c064648: /* original 5111, guest PC 0x0c064648 */
if(!s->budget--) { s->failed_pc=0x0c064648u; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c06464a;
P_0c06464a: /* original 4208, guest PC 0x0c06464a */
if(!s->budget--) { s->failed_pc=0x0c06464au; return 0; }
r[2]<<=2;
goto P_0c06464c;
P_0c06464c: /* original 0216, guest PC 0x0c06464c */
if(!s->budget--) { s->failed_pc=0x0c06464cu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06464e;
P_0c06464e: /* original 6253, guest PC 0x0c06464e */
if(!s->budget--) { s->failed_pc=0x0c06464eu; return 0; }
r[2]=r[5];
goto P_0c064650;
P_0c064650: /* original 61e2, guest PC 0x0c064650 */
if(!s->budget--) { s->failed_pc=0x0c064650u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c064652;
P_0c064652: /* original 7501, guest PC 0x0c064652 */
if(!s->budget--) { s->failed_pc=0x0c064652u; return 0; }
r[5]+=0x00000001u;
goto P_0c064654;
P_0c064654: /* original 5112, guest PC 0x0c064654 */
if(!s->budget--) { s->failed_pc=0x0c064654u; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c064656;
P_0c064656: /* original 4208, guest PC 0x0c064656 */
if(!s->budget--) { s->failed_pc=0x0c064656u; return 0; }
r[2]<<=2;
goto P_0c064658;
P_0c064658: /* original 0216, guest PC 0x0c064658 */
if(!s->budget--) { s->failed_pc=0x0c064658u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06465a;
P_0c06465a: /* original 6253, guest PC 0x0c06465a */
if(!s->budget--) { s->failed_pc=0x0c06465au; return 0; }
r[2]=r[5];
goto P_0c06465c;
P_0c06465c: /* original 61e2, guest PC 0x0c06465c */
if(!s->budget--) { s->failed_pc=0x0c06465cu; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c06465e;
P_0c06465e: /* original 7501, guest PC 0x0c06465e */
if(!s->budget--) { s->failed_pc=0x0c06465eu; return 0; }
r[5]+=0x00000001u;
goto P_0c064660;
P_0c064660: /* original 5113, guest PC 0x0c064660 */
if(!s->budget--) { s->failed_pc=0x0c064660u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c064662;
P_0c064662: /* original 4208, guest PC 0x0c064662 */
if(!s->budget--) { s->failed_pc=0x0c064662u; return 0; }
r[2]<<=2;
goto P_0c064664;
P_0c064664: /* original 0216, guest PC 0x0c064664 */
if(!s->budget--) { s->failed_pc=0x0c064664u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064666;
P_0c064666: /* original 6253, guest PC 0x0c064666 */
if(!s->budget--) { s->failed_pc=0x0c064666u; return 0; }
r[2]=r[5];
goto P_0c064668;
P_0c064668: /* original 61e2, guest PC 0x0c064668 */
if(!s->budget--) { s->failed_pc=0x0c064668u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c06466a;
P_0c06466a: /* original 7501, guest PC 0x0c06466a */
if(!s->budget--) { s->failed_pc=0x0c06466au; return 0; }
r[5]+=0x00000001u;
goto P_0c06466c;
P_0c06466c: /* original 5116, guest PC 0x0c06466c */
if(!s->budget--) { s->failed_pc=0x0c06466cu; return 0; }
r[1]=read(ram,r[1]+24,4);
goto P_0c06466e;
P_0c06466e: /* original 4208, guest PC 0x0c06466e */
if(!s->budget--) { s->failed_pc=0x0c06466eu; return 0; }
r[2]<<=2;
goto P_0c064670;
P_0c064670: /* original 0216, guest PC 0x0c064670 */
if(!s->budget--) { s->failed_pc=0x0c064670u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064672;
P_0c064672: /* original 6253, guest PC 0x0c064672 */
if(!s->budget--) { s->failed_pc=0x0c064672u; return 0; }
r[2]=r[5];
goto P_0c064674;
P_0c064674: /* original 6162, guest PC 0x0c064674 */
if(!s->budget--) { s->failed_pc=0x0c064674u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c064676;
P_0c064676: /* original 7501, guest PC 0x0c064676 */
if(!s->budget--) { s->failed_pc=0x0c064676u; return 0; }
r[5]+=0x00000001u;
goto P_0c064678;
P_0c064678: /* original 5111, guest PC 0x0c064678 */
if(!s->budget--) { s->failed_pc=0x0c064678u; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c06467a;
P_0c06467a: /* original 4208, guest PC 0x0c06467a */
if(!s->budget--) { s->failed_pc=0x0c06467au; return 0; }
r[2]<<=2;
goto P_0c06467c;
P_0c06467c: /* original 0216, guest PC 0x0c06467c */
if(!s->budget--) { s->failed_pc=0x0c06467cu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06467e;
P_0c06467e: /* original 6253, guest PC 0x0c06467e */
if(!s->budget--) { s->failed_pc=0x0c06467eu; return 0; }
r[2]=r[5];
goto P_0c064680;
P_0c064680: /* original 6162, guest PC 0x0c064680 */
if(!s->budget--) { s->failed_pc=0x0c064680u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c064682;
P_0c064682: /* original 7501, guest PC 0x0c064682 */
if(!s->budget--) { s->failed_pc=0x0c064682u; return 0; }
r[5]+=0x00000001u;
goto P_0c064684;
P_0c064684: /* original 5112, guest PC 0x0c064684 */
if(!s->budget--) { s->failed_pc=0x0c064684u; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c064686;
P_0c064686: /* original 4208, guest PC 0x0c064686 */
if(!s->budget--) { s->failed_pc=0x0c064686u; return 0; }
r[2]<<=2;
goto P_0c064688;
P_0c064688: /* original 0216, guest PC 0x0c064688 */
if(!s->budget--) { s->failed_pc=0x0c064688u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c06468a;
P_0c06468a: /* original 6253, guest PC 0x0c06468a */
if(!s->budget--) { s->failed_pc=0x0c06468au; return 0; }
r[2]=r[5];
goto P_0c06468c;
P_0c06468c: /* original 6162, guest PC 0x0c06468c */
if(!s->budget--) { s->failed_pc=0x0c06468cu; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c06468e;
P_0c06468e: /* original 7501, guest PC 0x0c06468e */
if(!s->budget--) { s->failed_pc=0x0c06468eu; return 0; }
r[5]+=0x00000001u;
goto P_0c064690;
P_0c064690: /* original 5113, guest PC 0x0c064690 */
if(!s->budget--) { s->failed_pc=0x0c064690u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c064692;
P_0c064692: /* original 4208, guest PC 0x0c064692 */
if(!s->budget--) { s->failed_pc=0x0c064692u; return 0; }
r[2]<<=2;
goto P_0c064694;
P_0c064694: /* original 0216, guest PC 0x0c064694 */
if(!s->budget--) { s->failed_pc=0x0c064694u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064696;
P_0c064696: /* original 6253, guest PC 0x0c064696 */
if(!s->budget--) { s->failed_pc=0x0c064696u; return 0; }
r[2]=r[5];
goto P_0c064698;
P_0c064698: /* original 6162, guest PC 0x0c064698 */
if(!s->budget--) { s->failed_pc=0x0c064698u; return 0; }
tmp=read(ram,r[6],4);
r[1]=tmp;
goto P_0c06469a;
P_0c06469a: /* original 7501, guest PC 0x0c06469a */
if(!s->budget--) { s->failed_pc=0x0c06469au; return 0; }
r[5]+=0x00000001u;
goto P_0c06469c;
P_0c06469c: /* original 5116, guest PC 0x0c06469c */
if(!s->budget--) { s->failed_pc=0x0c06469cu; return 0; }
r[1]=read(ram,r[1]+24,4);
goto P_0c06469e;
P_0c06469e: /* original 4208, guest PC 0x0c06469e */
if(!s->budget--) { s->failed_pc=0x0c06469eu; return 0; }
r[2]<<=2;
goto P_0c0646a0;
P_0c0646a0: /* original 0216, guest PC 0x0c0646a0 */
if(!s->budget--) { s->failed_pc=0x0c0646a0u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0646a2;
P_0c0646a2: /* original 6253, guest PC 0x0c0646a2 */
if(!s->budget--) { s->failed_pc=0x0c0646a2u; return 0; }
r[2]=r[5];
goto P_0c0646a4;
P_0c0646a4: /* original 6172, guest PC 0x0c0646a4 */
if(!s->budget--) { s->failed_pc=0x0c0646a4u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0646a6;
P_0c0646a6: /* original 7501, guest PC 0x0c0646a6 */
if(!s->budget--) { s->failed_pc=0x0c0646a6u; return 0; }
r[5]+=0x00000001u;
goto P_0c0646a8;
P_0c0646a8: /* original 5111, guest PC 0x0c0646a8 */
if(!s->budget--) { s->failed_pc=0x0c0646a8u; return 0; }
r[1]=read(ram,r[1]+4,4);
goto P_0c0646aa;
P_0c0646aa: /* original 4208, guest PC 0x0c0646aa */
if(!s->budget--) { s->failed_pc=0x0c0646aau; return 0; }
r[2]<<=2;
goto P_0c0646ac;
P_0c0646ac: /* original 0216, guest PC 0x0c0646ac */
if(!s->budget--) { s->failed_pc=0x0c0646acu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0646ae;
P_0c0646ae: /* original 6253, guest PC 0x0c0646ae */
if(!s->budget--) { s->failed_pc=0x0c0646aeu; return 0; }
r[2]=r[5];
goto P_0c0646b0;
P_0c0646b0: /* original 7501, guest PC 0x0c0646b0 */
if(!s->budget--) { s->failed_pc=0x0c0646b0u; return 0; }
r[5]+=0x00000001u;
goto P_0c0646b2;
P_0c0646b2: /* original 4208, guest PC 0x0c0646b2 */
if(!s->budget--) { s->failed_pc=0x0c0646b2u; return 0; }
r[2]<<=2;
goto P_0c0646b4;
P_0c0646b4: /* original 6172, guest PC 0x0c0646b4 */
if(!s->budget--) { s->failed_pc=0x0c0646b4u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0646b6;
P_0c0646b6: /* original 5112, guest PC 0x0c0646b6 */
if(!s->budget--) { s->failed_pc=0x0c0646b6u; return 0; }
r[1]=read(ram,r[1]+8,4);
goto P_0c0646b8;
P_0c0646b8: /* original 0216, guest PC 0x0c0646b8 */
if(!s->budget--) { s->failed_pc=0x0c0646b8u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0646ba;
P_0c0646ba: /* original 6253, guest PC 0x0c0646ba */
if(!s->budget--) { s->failed_pc=0x0c0646bau; return 0; }
r[2]=r[5];
goto P_0c0646bc;
P_0c0646bc: /* original 6172, guest PC 0x0c0646bc */
if(!s->budget--) { s->failed_pc=0x0c0646bcu; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0646be;
P_0c0646be: /* original 7501, guest PC 0x0c0646be */
if(!s->budget--) { s->failed_pc=0x0c0646beu; return 0; }
r[5]+=0x00000001u;
goto P_0c0646c0;
P_0c0646c0: /* original 5113, guest PC 0x0c0646c0 */
if(!s->budget--) { s->failed_pc=0x0c0646c0u; return 0; }
r[1]=read(ram,r[1]+12,4);
goto P_0c0646c2;
P_0c0646c2: /* original 4208, guest PC 0x0c0646c2 */
if(!s->budget--) { s->failed_pc=0x0c0646c2u; return 0; }
r[2]<<=2;
goto P_0c0646c4;
P_0c0646c4: /* original 0216, guest PC 0x0c0646c4 */
if(!s->budget--) { s->failed_pc=0x0c0646c4u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0646c6;
P_0c0646c6: /* original 6253, guest PC 0x0c0646c6 */
if(!s->budget--) { s->failed_pc=0x0c0646c6u; return 0; }
r[2]=r[5];
goto P_0c0646c8;
P_0c0646c8: /* original 6172, guest PC 0x0c0646c8 */
if(!s->budget--) { s->failed_pc=0x0c0646c8u; return 0; }
tmp=read(ram,r[7],4);
r[1]=tmp;
goto P_0c0646ca;
P_0c0646ca: /* original 7501, guest PC 0x0c0646ca */
if(!s->budget--) { s->failed_pc=0x0c0646cau; return 0; }
r[5]+=0x00000001u;
goto P_0c0646cc;
P_0c0646cc: /* original 5116, guest PC 0x0c0646cc */
if(!s->budget--) { s->failed_pc=0x0c0646ccu; return 0; }
r[1]=read(ram,r[1]+24,4);
goto P_0c0646ce;
P_0c0646ce: /* original 4208, guest PC 0x0c0646ce */
if(!s->budget--) { s->failed_pc=0x0c0646ceu; return 0; }
r[2]<<=2;
goto P_0c0646d0;
P_0c0646d0: /* original 0216, guest PC 0x0c0646d0 */
if(!s->budget--) { s->failed_pc=0x0c0646d0u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c0646d2;
P_0c0646d2: /* original 4508, guest PC 0x0c0646d2 */
if(!s->budget--) { s->failed_pc=0x0c0646d2u; return 0; }
r[5]<<=2;
goto P_0c0646d4;
P_0c0646d4: /* original d224, guest PC 0x0c0646d4 */
if(!s->budget--) { s->failed_pc=0x0c0646d4u; return 0; }
r[2]=read(ram,0x0c064768u,4);
goto P_0c0646d6;
P_0c0646d6: /* original 2252, guest PC 0x0c0646d6 */
if(!s->budget--) { s->failed_pc=0x0c0646d6u; return 0; }
write(ram,r[2],r[5],4);
goto P_0c0646d8;
P_0c0646d8: /* original bf1b, guest PC 0x0c0646d8 */
if(!s->budget--) { s->failed_pc=0x0c0646d8u; return 0; }
target=0x0c064512u; r[16]=0x0c0646dcu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0646dcu) { target=s->pc; goto dispatch; }
goto P_0c0646dc;
P_0c0646da: /* original 64d3, guest PC 0x0c0646da */
if(!s->budget--) { s->failed_pc=0x0c0646dau; return 0; }
r[4]=r[13];
goto P_0c0646dc;
P_0c0646dc: /* original 6403, guest PC 0x0c0646dc */
if(!s->budget--) { s->failed_pc=0x0c0646dcu; return 0; }
r[4]=r[0];
goto P_0c0646de;
P_0c0646de: /* original e500, guest PC 0x0c0646de */
if(!s->budget--) { s->failed_pc=0x0c0646deu; return 0; }
r[5]=0x00000000u;
goto P_0c0646e0;
P_0c0646e0: /* original bf02, guest PC 0x0c0646e0 */
if(!s->budget--) { s->failed_pc=0x0c0646e0u; return 0; }
target=0x0c0644e8u; r[16]=0x0c0646e4u;
r[6]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0646e4u) { target=s->pc; goto dispatch; }
goto P_0c0646e4;
P_0c0646e2: /* original 6653, guest PC 0x0c0646e2 */
if(!s->budget--) { s->failed_pc=0x0c0646e2u; return 0; }
r[6]=r[5];
goto P_0c0646e4;
P_0c0646e4: /* original 62e2, guest PC 0x0c0646e4 */
if(!s->budget--) { s->failed_pc=0x0c0646e4u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0646e6;
P_0c0646e6: /* original 5323, guest PC 0x0c0646e6 */
if(!s->budget--) { s->failed_pc=0x0c0646e6u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c0646e8;
P_0c0646e8: /* original d11b, guest PC 0x0c0646e8 */
if(!s->budget--) { s->failed_pc=0x0c0646e8u; return 0; }
r[1]=read(ram,0x0c064758u,4);
goto P_0c0646ea;
P_0c0646ea: /* original 2132, guest PC 0x0c0646ea */
if(!s->budget--) { s->failed_pc=0x0c0646eau; return 0; }
write(ram,r[1],r[3],4);
goto P_0c0646ec;
P_0c0646ec: /* original e000, guest PC 0x0c0646ec */
if(!s->budget--) { s->failed_pc=0x0c0646ecu; return 0; }
r[0]=0x00000000u;
goto P_0c0646ee;
P_0c0646ee: /* original 7f10, guest PC 0x0c0646ee */
if(!s->budget--) { s->failed_pc=0x0c0646eeu; return 0; }
r[15]+=0x00000010u;
goto P_0c0646f0;
P_0c0646f0: /* original 4f26, guest PC 0x0c0646f0 */
if(!s->budget--) { s->failed_pc=0x0c0646f0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0646f2;
P_0c0646f2: /* original 6df6, guest PC 0x0c0646f2 */
if(!s->budget--) { s->failed_pc=0x0c0646f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0646f4;
P_0c0646f4: /* original 000b, guest PC 0x0c0646f4 */
if(!s->budget--) { s->failed_pc=0x0c0646f4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0646f6: /* original 6ef6, guest PC 0x0c0646f6 */
if(!s->budget--) { s->failed_pc=0x0c0646f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0646f8u,s,ram);
P_0c066a2c: /* original 4f22, guest PC 0x0c066a2c */
if(!s->budget--) { s->failed_pc=0x0c066a2cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c066a2e;
P_0c066a2e: /* original b153, guest PC 0x0c066a2e */
if(!s->budget--) { s->failed_pc=0x0c066a2eu; return 0; }
target=0x0c066cd8u; r[16]=0x0c066a32u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c066a32u) { target=s->pc; goto dispatch; }
goto P_0c066a32;
P_0c066a30: /* original 0009, guest PC 0x0c066a30 */
if(!s->budget--) { s->failed_pc=0x0c066a30u; return 0; }
goto P_0c066a32;
P_0c066a32: /* original d11c, guest PC 0x0c066a32 */
if(!s->budget--) { s->failed_pc=0x0c066a32u; return 0; }
r[1]=read(ram,0x0c066aa4u,4);
goto P_0c066a34;
P_0c066a34: /* original 410b, guest PC 0x0c066a34 */
if(!s->budget--) { s->failed_pc=0x0c066a34u; return 0; }
target=r[1];
r[16]=0x0c066a38u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c066a38u) { target=s->pc; goto dispatch; }
goto P_0c066a38;
P_0c066a36: /* original 0009, guest PC 0x0c066a36 */
if(!s->budget--) { s->failed_pc=0x0c066a36u; return 0; }
goto P_0c066a38;
P_0c066a38: /* original d21b, guest PC 0x0c066a38 */
if(!s->budget--) { s->failed_pc=0x0c066a38u; return 0; }
r[2]=read(ram,0x0c066aa8u,4);
goto P_0c066a3a;
P_0c066a3a: /* original d11c, guest PC 0x0c066a3a */
if(!s->budget--) { s->failed_pc=0x0c066a3au; return 0; }
r[1]=read(ram,0x0c066aacu,4);
goto P_0c066a3c;
P_0c066a3c: /* original 2122, guest PC 0x0c066a3c */
if(!s->budget--) { s->failed_pc=0x0c066a3cu; return 0; }
write(ram,r[1],r[2],4);
goto P_0c066a3e;
P_0c066a3e: /* original d31c, guest PC 0x0c066a3e */
if(!s->budget--) { s->failed_pc=0x0c066a3eu; return 0; }
r[3]=read(ram,0x0c066ab0u,4);
goto P_0c066a40;
P_0c066a40: /* original d01c, guest PC 0x0c066a40 */
if(!s->budget--) { s->failed_pc=0x0c066a40u; return 0; }
r[0]=read(ram,0x0c066ab4u,4);
goto P_0c066a42;
P_0c066a42: /* original 2032, guest PC 0x0c066a42 */
if(!s->budget--) { s->failed_pc=0x0c066a42u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c066a44;
P_0c066a44: /* original 6303, guest PC 0x0c066a44 */
if(!s->budget--) { s->failed_pc=0x0c066a44u; return 0; }
r[3]=r[0];
goto P_0c066a46;
P_0c066a46: /* original 6232, guest PC 0x0c066a46 */
if(!s->budget--) { s->failed_pc=0x0c066a46u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c066a48;
P_0c066a48: /* original 710c, guest PC 0x0c066a48 */
if(!s->budget--) { s->failed_pc=0x0c066a48u; return 0; }
r[1]+=0x0000000cu;
goto P_0c066a4a;
P_0c066a4a: /* original 2122, guest PC 0x0c066a4a */
if(!s->budget--) { s->failed_pc=0x0c066a4au; return 0; }
write(ram,r[1],r[2],4);
goto P_0c066a4c;
P_0c066a4c: /* original d217, guest PC 0x0c066a4c */
if(!s->budget--) { s->failed_pc=0x0c066a4cu; return 0; }
r[2]=read(ram,0x0c066aacu,4);
goto P_0c066a4e;
P_0c066a4e: /* original 701c, guest PC 0x0c066a4e */
if(!s->budget--) { s->failed_pc=0x0c066a4eu; return 0; }
r[0]+=0x0000001cu;
goto P_0c066a50;
P_0c066a50: /* original 6322, guest PC 0x0c066a50 */
if(!s->budget--) { s->failed_pc=0x0c066a50u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c066a52;
P_0c066a52: /* original 4301, guest PC 0x0c066a52 */
if(!s->budget--) { s->failed_pc=0x0c066a52u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]>>=1;
goto P_0c066a54;
P_0c066a54: /* original 2032, guest PC 0x0c066a54 */
if(!s->budget--) { s->failed_pc=0x0c066a54u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c066a56;
P_0c066a56: /* original 7138, guest PC 0x0c066a56 */
if(!s->budget--) { s->failed_pc=0x0c066a56u; return 0; }
r[1]+=0x00000038u;
goto P_0c066a58;
P_0c066a58: /* original e300, guest PC 0x0c066a58 */
if(!s->budget--) { s->failed_pc=0x0c066a58u; return 0; }
r[3]=0x00000000u;
goto P_0c066a5a;
P_0c066a5a: /* original 2132, guest PC 0x0c066a5a */
if(!s->budget--) { s->failed_pc=0x0c066a5au; return 0; }
write(ram,r[1],r[3],4);
goto P_0c066a5c;
P_0c066a5c: /* original d316, guest PC 0x0c066a5c */
if(!s->budget--) { s->failed_pc=0x0c066a5cu; return 0; }
r[3]=read(ram,0x0c066ab8u,4);
goto P_0c066a5e;
P_0c066a5e: /* original e201, guest PC 0x0c066a5e */
if(!s->budget--) { s->failed_pc=0x0c066a5eu; return 0; }
r[2]=0x00000001u;
goto P_0c066a60;
P_0c066a60: /* original 4f26, guest PC 0x0c066a60 */
if(!s->budget--) { s->failed_pc=0x0c066a60u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c066a62;
P_0c066a62: /* original 000b, guest PC 0x0c066a62 */
if(!s->budget--) { s->failed_pc=0x0c066a62u; return 0; }
target=r[16];
write(ram,r[3],r[2],4);
s->pc=target; return ram->oob==0;
P_0c066a64: /* original 2322, guest PC 0x0c066a64 */
if(!s->budget--) { s->failed_pc=0x0c066a64u; return 0; }
write(ram,r[3],r[2],4);
return vf3_matrix_family(0x0c066a66u,s,ram);
P_0c066cd8: /* original 4f22, guest PC 0x0c066cd8 */
if(!s->budget--) { s->failed_pc=0x0c066cd8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c066cda;
P_0c066cda: /* original e501, guest PC 0x0c066cda */
if(!s->budget--) { s->failed_pc=0x0c066cdau; return 0; }
r[5]=0x00000001u;
goto P_0c066cdc;
P_0c066cdc: /* original d30d, guest PC 0x0c066cdc */
if(!s->budget--) { s->failed_pc=0x0c066cdcu; return 0; }
r[3]=read(ram,0x0c066d14u,4);
goto P_0c066cde;
P_0c066cde: /* original 430b, guest PC 0x0c066cde */
if(!s->budget--) { s->failed_pc=0x0c066cdeu; return 0; }
target=r[3];
r[16]=0x0c066ce2u;
r[4]=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c066ce2u) { target=s->pc; goto dispatch; }
goto P_0c066ce2;
P_0c066ce0: /* original e408, guest PC 0x0c066ce0 */
if(!s->budget--) { s->failed_pc=0x0c066ce0u; return 0; }
r[4]=0x00000008u;
goto P_0c066ce2;
P_0c066ce2: /* original e500, guest PC 0x0c066ce2 */
if(!s->budget--) { s->failed_pc=0x0c066ce2u; return 0; }
r[5]=0x00000000u;
goto P_0c066ce4;
P_0c066ce4: /* original d20b, guest PC 0x0c066ce4 */
if(!s->budget--) { s->failed_pc=0x0c066ce4u; return 0; }
r[2]=read(ram,0x0c066d14u,4);
goto P_0c066ce6;
P_0c066ce6: /* original e408, guest PC 0x0c066ce6 */
if(!s->budget--) { s->failed_pc=0x0c066ce6u; return 0; }
r[4]=0x00000008u;
goto P_0c066ce8;
P_0c066ce8: /* original 422b, guest PC 0x0c066ce8 */
if(!s->budget--) { s->failed_pc=0x0c066ce8u; return 0; }
target=r[2];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c066cea: /* original 4f26, guest PC 0x0c066cea */
if(!s->budget--) { s->failed_pc=0x0c066ceau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c066cecu,s,ram);
P_0c0696c6: /* original 4f22, guest PC 0x0c0696c6 */
if(!s->budget--) { s->failed_pc=0x0c0696c6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0696c8;
P_0c0696c8: /* original 7ff8, guest PC 0x0c0696c8 */
if(!s->budget--) { s->failed_pc=0x0c0696c8u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0696ca;
P_0c0696ca: /* original 1f41, guest PC 0x0c0696ca */
if(!s->budget--) { s->failed_pc=0x0c0696cau; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0696cc;
P_0c0696cc: /* original 2f52, guest PC 0x0c0696cc */
if(!s->budget--) { s->failed_pc=0x0c0696ccu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0696ce;
P_0c0696ce: /* original d33c, guest PC 0x0c0696ce */
if(!s->budget--) { s->failed_pc=0x0c0696ceu; return 0; }
r[3]=read(ram,0x0c0697c0u,4);
goto P_0c0696d0;
P_0c0696d0: /* original 430b, guest PC 0x0c0696d0 */
if(!s->budget--) { s->failed_pc=0x0c0696d0u; return 0; }
target=r[3];
r[16]=0x0c0696d4u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0696d4u) { target=s->pc; goto dispatch; }
goto P_0c0696d4;
P_0c0696d2: /* original 54f1, guest PC 0x0c0696d2 */
if(!s->budget--) { s->failed_pc=0x0c0696d2u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0696d4;
P_0c0696d4: /* original 62f2, guest PC 0x0c0696d4 */
if(!s->budget--) { s->failed_pc=0x0c0696d4u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0696d6;
P_0c0696d6: /* original 302c, guest PC 0x0c0696d6 */
if(!s->budget--) { s->failed_pc=0x0c0696d6u; return 0; }
r[0]+=r[2];
goto P_0c0696d8;
P_0c0696d8: /* original 2f02, guest PC 0x0c0696d8 */
if(!s->budget--) { s->failed_pc=0x0c0696d8u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0696da;
P_0c0696da: /* original 6503, guest PC 0x0c0696da */
if(!s->budget--) { s->failed_pc=0x0c0696dau; return 0; }
r[5]=r[0];
goto P_0c0696dc;
P_0c0696dc: /* original 54f1, guest PC 0x0c0696dc */
if(!s->budget--) { s->failed_pc=0x0c0696dcu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0696de;
P_0c0696de: /* original 7f08, guest PC 0x0c0696de */
if(!s->budget--) { s->failed_pc=0x0c0696deu; return 0; }
r[15]+=0x00000008u;
goto P_0c0696e0;
P_0c0696e0: /* original d338, guest PC 0x0c0696e0 */
if(!s->budget--) { s->failed_pc=0x0c0696e0u; return 0; }
r[3]=read(ram,0x0c0697c4u,4);
goto P_0c0696e2;
P_0c0696e2: /* original 432b, guest PC 0x0c0696e2 */
if(!s->budget--) { s->failed_pc=0x0c0696e2u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c0696e4: /* original 4f26, guest PC 0x0c0696e4 */
if(!s->budget--) { s->failed_pc=0x0c0696e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0696e6u,s,ram);
P_0c069702: /* original 4f22, guest PC 0x0c069702 */
if(!s->budget--) { s->failed_pc=0x0c069702u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c069704;
P_0c069704: /* original 9454, guest PC 0x0c069704 */
if(!s->budget--) { s->failed_pc=0x0c069704u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0697b0u,2);
goto P_0c069706;
P_0c069706: /* original de2d, guest PC 0x0c069706 */
if(!s->budget--) { s->failed_pc=0x0c069706u; return 0; }
r[14]=read(ram,0x0c0697bcu,4);
goto P_0c069708;
P_0c069708: /* original d32d, guest PC 0x0c069708 */
if(!s->budget--) { s->failed_pc=0x0c069708u; return 0; }
r[3]=read(ram,0x0c0697c0u,4);
goto P_0c06970a;
P_0c06970a: /* original 7ffc, guest PC 0x0c06970a */
if(!s->budget--) { s->failed_pc=0x0c06970au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06970c;
P_0c06970c: /* original 430b, guest PC 0x0c06970c */
if(!s->budget--) { s->failed_pc=0x0c06970cu; return 0; }
target=r[3];
r[16]=0x0c069710u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c069710u) { target=s->pc; goto dispatch; }
goto P_0c069710;
P_0c06970e: /* original 34ec, guest PC 0x0c06970e */
if(!s->budget--) { s->failed_pc=0x0c06970eu; return 0; }
r[4]+=r[14];
goto P_0c069710;
P_0c069710: /* original 2f02, guest PC 0x0c069710 */
if(!s->budget--) { s->failed_pc=0x0c069710u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c069712;
P_0c069712: /* original e500, guest PC 0x0c069712 */
if(!s->budget--) { s->failed_pc=0x0c069712u; return 0; }
r[5]=0x00000000u;
goto P_0c069714;
P_0c069714: /* original 944c, guest PC 0x0c069714 */
if(!s->budget--) { s->failed_pc=0x0c069714u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0697b0u,2);
goto P_0c069716;
P_0c069716: /* original d32b, guest PC 0x0c069716 */
if(!s->budget--) { s->failed_pc=0x0c069716u; return 0; }
r[3]=read(ram,0x0c0697c4u,4);
goto P_0c069718;
P_0c069718: /* original 430b, guest PC 0x0c069718 */
if(!s->budget--) { s->failed_pc=0x0c069718u; return 0; }
target=r[3];
r[16]=0x0c06971cu;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06971cu) { target=s->pc; goto dispatch; }
goto P_0c06971c;
P_0c06971a: /* original 34ec, guest PC 0x0c06971a */
if(!s->budget--) { s->failed_pc=0x0c06971au; return 0; }
r[4]+=r[14];
goto P_0c06971c;
P_0c06971c: /* original 65f2, guest PC 0x0c06971c */
if(!s->budget--) { s->failed_pc=0x0c06971cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06971e;
P_0c06971e: /* original 7f04, guest PC 0x0c06971e */
if(!s->budget--) { s->failed_pc=0x0c06971eu; return 0; }
r[15]+=0x00000004u;
goto P_0c069720;
P_0c069720: /* original 4f26, guest PC 0x0c069720 */
if(!s->budget--) { s->failed_pc=0x0c069720u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c069722;
P_0c069722: /* original 64e3, guest PC 0x0c069722 */
if(!s->budget--) { s->failed_pc=0x0c069722u; return 0; }
r[4]=r[14];
goto P_0c069724;
P_0c069724: /* original 7434, guest PC 0x0c069724 */
if(!s->budget--) { s->failed_pc=0x0c069724u; return 0; }
r[4]+=0x00000034u;
goto P_0c069726;
P_0c069726: /* original afce, guest PC 0x0c069726 */
if(!s->budget--) { s->failed_pc=0x0c069726u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0696c6;
P_0c069728: /* original 6ef6, guest PC 0x0c069728 */
if(!s->budget--) { s->failed_pc=0x0c069728u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06972au,s,ram);
P_0c06a5ee: /* original 4f22, guest PC 0x0c06a5ee */
if(!s->budget--) { s->failed_pc=0x0c06a5eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06a5f0;
P_0c06a5f0: /* original de1f, guest PC 0x0c06a5f0 */
if(!s->budget--) { s->failed_pc=0x0c06a5f0u; return 0; }
r[14]=read(ram,0x0c06a670u,4);
goto P_0c06a5f2;
P_0c06a5f2: /* original da20, guest PC 0x0c06a5f2 */
if(!s->budget--) { s->failed_pc=0x0c06a5f2u; return 0; }
r[10]=read(ram,0x0c06a674u,4);
goto P_0c06a5f4;
P_0c06a5f4: /* original 64e3, guest PC 0x0c06a5f4 */
if(!s->budget--) { s->failed_pc=0x0c06a5f4u; return 0; }
r[4]=r[14];
goto P_0c06a5f6;
P_0c06a5f6: /* original 7ffc, guest PC 0x0c06a5f6 */
if(!s->budget--) { s->failed_pc=0x0c06a5f6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06a5f8;
P_0c06a5f8: /* original 4a0b, guest PC 0x0c06a5f8 */
if(!s->budget--) { s->failed_pc=0x0c06a5f8u; return 0; }
target=r[10];
r[16]=0x0c06a5fcu;
r[4]+=0x0000001cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a5fcu) { target=s->pc; goto dispatch; }
goto P_0c06a5fc;
P_0c06a5fa: /* original 741c, guest PC 0x0c06a5fa */
if(!s->budget--) { s->failed_pc=0x0c06a5fau; return 0; }
r[4]+=0x0000001cu;
goto P_0c06a5fc;
P_0c06a5fc: /* original db1e, guest PC 0x0c06a5fc */
if(!s->budget--) { s->failed_pc=0x0c06a5fcu; return 0; }
r[11]=read(ram,0x0c06a678u,4);
goto P_0c06a5fe;
P_0c06a5fe: /* original 64e3, guest PC 0x0c06a5fe */
if(!s->budget--) { s->failed_pc=0x0c06a5feu; return 0; }
r[4]=r[14];
goto P_0c06a600;
P_0c06a600: /* original 6503, guest PC 0x0c06a600 */
if(!s->budget--) { s->failed_pc=0x0c06a600u; return 0; }
r[5]=r[0];
goto P_0c06a602;
P_0c06a602: /* original 6d03, guest PC 0x0c06a602 */
if(!s->budget--) { s->failed_pc=0x0c06a602u; return 0; }
r[13]=r[0];
goto P_0c06a604;
P_0c06a604: /* original 4b0b, guest PC 0x0c06a604 */
if(!s->budget--) { s->failed_pc=0x0c06a604u; return 0; }
target=r[11];
r[16]=0x0c06a608u;
r[4]+=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a608u) { target=s->pc; goto dispatch; }
goto P_0c06a608;
P_0c06a606: /* original 7420, guest PC 0x0c06a606 */
if(!s->budget--) { s->failed_pc=0x0c06a606u; return 0; }
r[4]+=0x00000020u;
goto P_0c06a608;
P_0c06a608: /* original 9430, guest PC 0x0c06a608 */
if(!s->budget--) { s->failed_pc=0x0c06a608u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a66cu,2);
goto P_0c06a60a;
P_0c06a60a: /* original 4a0b, guest PC 0x0c06a60a */
if(!s->budget--) { s->failed_pc=0x0c06a60au; return 0; }
target=r[10];
r[16]=0x0c06a60eu;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a60eu) { target=s->pc; goto dispatch; }
goto P_0c06a60e;
P_0c06a60c: /* original 34ec, guest PC 0x0c06a60c */
if(!s->budget--) { s->failed_pc=0x0c06a60cu; return 0; }
r[4]+=r[14];
goto P_0c06a60e;
P_0c06a60e: /* original e500, guest PC 0x0c06a60e */
if(!s->budget--) { s->failed_pc=0x0c06a60eu; return 0; }
r[5]=0x00000000u;
goto P_0c06a610;
P_0c06a610: /* original 2f02, guest PC 0x0c06a610 */
if(!s->budget--) { s->failed_pc=0x0c06a610u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a612;
P_0c06a612: /* original 942b, guest PC 0x0c06a612 */
if(!s->budget--) { s->failed_pc=0x0c06a612u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a66cu,2);
goto P_0c06a614;
P_0c06a614: /* original 4b0b, guest PC 0x0c06a614 */
if(!s->budget--) { s->failed_pc=0x0c06a614u; return 0; }
target=r[11];
r[16]=0x0c06a618u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a618u) { target=s->pc; goto dispatch; }
goto P_0c06a618;
P_0c06a616: /* original 34ec, guest PC 0x0c06a616 */
if(!s->budget--) { s->failed_pc=0x0c06a616u; return 0; }
r[4]+=r[14];
goto P_0c06a618;
P_0c06a618: /* original 64e3, guest PC 0x0c06a618 */
if(!s->budget--) { s->failed_pc=0x0c06a618u; return 0; }
r[4]=r[14];
goto P_0c06a61a;
P_0c06a61a: /* original 4a0b, guest PC 0x0c06a61a */
if(!s->budget--) { s->failed_pc=0x0c06a61au; return 0; }
target=r[10];
r[16]=0x0c06a61eu;
r[4]+=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a61eu) { target=s->pc; goto dispatch; }
goto P_0c06a61e;
P_0c06a61c: /* original 7434, guest PC 0x0c06a61c */
if(!s->budget--) { s->failed_pc=0x0c06a61cu; return 0; }
r[4]+=0x00000034u;
goto P_0c06a61e;
P_0c06a61e: /* original 63f2, guest PC 0x0c06a61e */
if(!s->budget--) { s->failed_pc=0x0c06a61eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06a620;
P_0c06a620: /* original 6c03, guest PC 0x0c06a620 */
if(!s->budget--) { s->failed_pc=0x0c06a620u; return 0; }
r[12]=r[0];
goto P_0c06a622;
P_0c06a622: /* original 64e3, guest PC 0x0c06a622 */
if(!s->budget--) { s->failed_pc=0x0c06a622u; return 0; }
r[4]=r[14];
goto P_0c06a624;
P_0c06a624: /* original 3c3c, guest PC 0x0c06a624 */
if(!s->budget--) { s->failed_pc=0x0c06a624u; return 0; }
r[12]+=r[3];
goto P_0c06a626;
P_0c06a626: /* original 65c3, guest PC 0x0c06a626 */
if(!s->budget--) { s->failed_pc=0x0c06a626u; return 0; }
r[5]=r[12];
goto P_0c06a628;
P_0c06a628: /* original 4b0b, guest PC 0x0c06a628 */
if(!s->budget--) { s->failed_pc=0x0c06a628u; return 0; }
target=r[11];
r[16]=0x0c06a62cu;
r[4]+=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a62cu) { target=s->pc; goto dispatch; }
goto P_0c06a62c;
P_0c06a62a: /* original 7434, guest PC 0x0c06a62a */
if(!s->budget--) { s->failed_pc=0x0c06a62au; return 0; }
r[4]+=0x00000034u;
goto P_0c06a62c;
P_0c06a62c: /* original 64e3, guest PC 0x0c06a62c */
if(!s->budget--) { s->failed_pc=0x0c06a62cu; return 0; }
r[4]=r[14];
goto P_0c06a62e;
P_0c06a62e: /* original 65c3, guest PC 0x0c06a62e */
if(!s->budget--) { s->failed_pc=0x0c06a62eu; return 0; }
r[5]=r[12];
goto P_0c06a630;
P_0c06a630: /* original 4b0b, guest PC 0x0c06a630 */
if(!s->budget--) { s->failed_pc=0x0c06a630u; return 0; }
target=r[11];
r[16]=0x0c06a634u;
r[4]+=0x00000038u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a634u) { target=s->pc; goto dispatch; }
goto P_0c06a634;
P_0c06a632: /* original 7438, guest PC 0x0c06a632 */
if(!s->budget--) { s->failed_pc=0x0c06a632u; return 0; }
r[4]+=0x00000038u;
goto P_0c06a634;
P_0c06a634: /* original 64e3, guest PC 0x0c06a634 */
if(!s->budget--) { s->failed_pc=0x0c06a634u; return 0; }
r[4]=r[14];
goto P_0c06a636;
P_0c06a636: /* original 3dc8, guest PC 0x0c06a636 */
if(!s->budget--) { s->failed_pc=0x0c06a636u; return 0; }
r[13]-=r[12];
goto P_0c06a638;
P_0c06a638: /* original 4a0b, guest PC 0x0c06a638 */
if(!s->budget--) { s->failed_pc=0x0c06a638u; return 0; }
target=r[10];
r[16]=0x0c06a63cu;
r[4]+=0x00000024u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a63cu) { target=s->pc; goto dispatch; }
goto P_0c06a63c;
P_0c06a63a: /* original 7424, guest PC 0x0c06a63a */
if(!s->budget--) { s->failed_pc=0x0c06a63au; return 0; }
r[4]+=0x00000024u;
goto P_0c06a63c;
P_0c06a63c: /* original 4d5a, guest PC 0x0c06a63c */
if(!s->budget--) { s->failed_pc=0x0c06a63cu; return 0; }
r[53]=r[13];
goto P_0c06a63e;
P_0c06a63e: /* original 6403, guest PC 0x0c06a63e */
if(!s->budget--) { s->failed_pc=0x0c06a63eu; return 0; }
r[4]=r[0];
goto P_0c06a640;
P_0c06a640: /* original c70e, guest PC 0x0c06a640 */
if(!s->budget--) { s->failed_pc=0x0c06a640u; return 0; }
r[0]=0x0c06a67cu;
goto P_0c06a642;
P_0c06a642: /* original f508, guest PC 0x0c06a642 */
if(!s->budget--) { s->failed_pc=0x0c06a642u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c06a644;
P_0c06a644: /* original f32d, guest PC 0x0c06a644 */
if(!s->budget--) { s->failed_pc=0x0c06a644u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c06a646;
P_0c06a646: /* original 445a, guest PC 0x0c06a646 */
if(!s->budget--) { s->failed_pc=0x0c06a646u; return 0; }
r[53]=r[4];
goto P_0c06a648;
P_0c06a648: /* original 64e3, guest PC 0x0c06a648 */
if(!s->budget--) { s->failed_pc=0x0c06a648u; return 0; }
r[4]=r[14];
goto P_0c06a64a;
P_0c06a64a: /* original f22d, guest PC 0x0c06a64a */
if(!s->budget--) { s->failed_pc=0x0c06a64au; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c06a64c;
P_0c06a64c: /* original f63c, guest PC 0x0c06a64c */
if(!s->budget--) { s->failed_pc=0x0c06a64cu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c06a64e;
P_0c06a64e: /* original f42c, guest PC 0x0c06a64e */
if(!s->budget--) { s->failed_pc=0x0c06a64eu; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c06a650;
P_0c06a650: /* original f452, guest PC 0x0c06a650 */
if(!s->budget--) { s->failed_pc=0x0c06a650u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c06a652;
P_0c06a652: /* original f463, guest PC 0x0c06a652 */
if(!s->budget--) { s->failed_pc=0x0c06a652u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
goto P_0c06a654;
P_0c06a654: /* original f43d, guest PC 0x0c06a654 */
if(!s->budget--) { s->failed_pc=0x0c06a654u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c06a656;
P_0c06a656: /* original 055a, guest PC 0x0c06a656 */
if(!s->budget--) { s->failed_pc=0x0c06a656u; return 0; }
r[5]=r[53];
goto P_0c06a658;
P_0c06a658: /* original 4b0b, guest PC 0x0c06a658 */
if(!s->budget--) { s->failed_pc=0x0c06a658u; return 0; }
target=r[11];
r[16]=0x0c06a65cu;
r[4]+=0x0000003cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a65cu) { target=s->pc; goto dispatch; }
goto P_0c06a65c;
P_0c06a65a: /* original 743c, guest PC 0x0c06a65a */
if(!s->budget--) { s->failed_pc=0x0c06a65au; return 0; }
r[4]+=0x0000003cu;
goto P_0c06a65c;
P_0c06a65c: /* original 7f04, guest PC 0x0c06a65c */
if(!s->budget--) { s->failed_pc=0x0c06a65cu; return 0; }
r[15]+=0x00000004u;
goto P_0c06a65e;
P_0c06a65e: /* original 4f26, guest PC 0x0c06a65e */
if(!s->budget--) { s->failed_pc=0x0c06a65eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06a660;
P_0c06a660: /* original 6af6, guest PC 0x0c06a660 */
if(!s->budget--) { s->failed_pc=0x0c06a660u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06a662;
P_0c06a662: /* original 6bf6, guest PC 0x0c06a662 */
if(!s->budget--) { s->failed_pc=0x0c06a662u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06a664;
P_0c06a664: /* original 6cf6, guest PC 0x0c06a664 */
if(!s->budget--) { s->failed_pc=0x0c06a664u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06a666;
P_0c06a666: /* original 6df6, guest PC 0x0c06a666 */
if(!s->budget--) { s->failed_pc=0x0c06a666u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06a668;
P_0c06a668: /* original 000b, guest PC 0x0c06a668 */
if(!s->budget--) { s->failed_pc=0x0c06a668u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06a66a: /* original 6ef6, guest PC 0x0c06a66a */
if(!s->budget--) { s->failed_pc=0x0c06a66au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06a66cu,s,ram);
P_0c06be34: /* original 4f22, guest PC 0x0c06be34 */
if(!s->budget--) { s->failed_pc=0x0c06be34u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06be36;
P_0c06be36: /* original e300, guest PC 0x0c06be36 */
if(!s->budget--) { s->failed_pc=0x0c06be36u; return 0; }
r[3]=0x00000000u;
goto P_0c06be38;
P_0c06be38: /* original 6233, guest PC 0x0c06be38 */
if(!s->budget--) { s->failed_pc=0x0c06be38u; return 0; }
r[2]=r[3];
goto P_0c06be3a;
P_0c06be3a: /* original 6523, guest PC 0x0c06be3a */
if(!s->budget--) { s->failed_pc=0x0c06be3au; return 0; }
r[5]=r[2];
goto P_0c06be3c;
P_0c06be3c: /* original 7ffc, guest PC 0x0c06be3c */
if(!s->budget--) { s->failed_pc=0x0c06be3cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06be3e;
P_0c06be3e: /* original 2f42, guest PC 0x0c06be3e */
if(!s->budget--) { s->failed_pc=0x0c06be3eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06be40;
P_0c06be40: /* original 9028, guest PC 0x0c06be40 */
if(!s->budget--) { s->failed_pc=0x0c06be40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06be94u,2);
goto P_0c06be42;
P_0c06be42: /* original d415, guest PC 0x0c06be42 */
if(!s->budget--) { s->failed_pc=0x0c06be42u; return 0; }
r[4]=read(ram,0x0c06be98u,4);
goto P_0c06be44;
P_0c06be44: /* original 0434, guest PC 0x0c06be44 */
if(!s->budget--) { s->failed_pc=0x0c06be44u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c06be46;
P_0c06be46: /* original 70ff, guest PC 0x0c06be46 */
if(!s->budget--) { s->failed_pc=0x0c06be46u; return 0; }
r[0]+=0xffffffffu;
goto P_0c06be48;
P_0c06be48: /* original 0424, guest PC 0x0c06be48 */
if(!s->budget--) { s->failed_pc=0x0c06be48u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c06be4a;
P_0c06be4a: /* original d315, guest PC 0x0c06be4a */
if(!s->budget--) { s->failed_pc=0x0c06be4au; return 0; }
r[3]=read(ram,0x0c06bea0u,4);
goto P_0c06be4c;
P_0c06be4c: /* original 64f2, guest PC 0x0c06be4c */
if(!s->budget--) { s->failed_pc=0x0c06be4cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06be4e;
P_0c06be4e: /* original 430b, guest PC 0x0c06be4e */
if(!s->budget--) { s->failed_pc=0x0c06be4eu; return 0; }
target=r[3];
r[16]=0x0c06be52u;
r[4]+=0x0000002bu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06be52u) { target=s->pc; goto dispatch; }
goto P_0c06be52;
P_0c06be50: /* original 742b, guest PC 0x0c06be50 */
if(!s->budget--) { s->failed_pc=0x0c06be50u; return 0; }
r[4]+=0x0000002bu;
goto P_0c06be52;
P_0c06be52: /* original 64f2, guest PC 0x0c06be52 */
if(!s->budget--) { s->failed_pc=0x0c06be52u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06be54;
P_0c06be54: /* original 7f04, guest PC 0x0c06be54 */
if(!s->budget--) { s->failed_pc=0x0c06be54u; return 0; }
r[15]+=0x00000004u;
goto P_0c06be56;
P_0c06be56: /* original d312, guest PC 0x0c06be56 */
if(!s->budget--) { s->failed_pc=0x0c06be56u; return 0; }
r[3]=read(ram,0x0c06bea0u,4);
goto P_0c06be58;
P_0c06be58: /* original e500, guest PC 0x0c06be58 */
if(!s->budget--) { s->failed_pc=0x0c06be58u; return 0; }
r[5]=0x00000000u;
goto P_0c06be5a;
P_0c06be5a: /* original 742a, guest PC 0x0c06be5a */
if(!s->budget--) { s->failed_pc=0x0c06be5au; return 0; }
r[4]+=0x0000002au;
goto P_0c06be5c;
P_0c06be5c: /* original 432b, guest PC 0x0c06be5c */
if(!s->budget--) { s->failed_pc=0x0c06be5cu; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c06be5e: /* original 4f26, guest PC 0x0c06be5e */
if(!s->budget--) { s->failed_pc=0x0c06be5eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c06be60u,s,ram);
P_0c06cf20: /* original 2fe6, guest PC 0x0c06cf20 */
if(!s->budget--) { s->failed_pc=0x0c06cf20u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c06cf22;
P_0c06cf22: /* original e010, guest PC 0x0c06cf22 */
if(!s->budget--) { s->failed_pc=0x0c06cf22u; return 0; }
r[0]=0x00000010u;
goto P_0c06cf24;
P_0c06cf24: /* original f48d, guest PC 0x0c06cf24 */
if(!s->budget--) { s->failed_pc=0x0c06cf24u; return 0; }
fr[4]=0;
goto P_0c06cf26;
P_0c06cf26: /* original 6e43, guest PC 0x0c06cf26 */
if(!s->budget--) { s->failed_pc=0x0c06cf26u; return 0; }
r[14]=r[4];
goto P_0c06cf28;
P_0c06cf28: /* original f54c, guest PC 0x0c06cf28 */
if(!s->budget--) { s->failed_pc=0x0c06cf28u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c06cf2a;
P_0c06cf2a: /* original e400, guest PC 0x0c06cf2a */
if(!s->budget--) { s->failed_pc=0x0c06cf2au; return 0; }
r[4]=0x00000000u;
goto P_0c06cf2c;
P_0c06cf2c: /* original fe57, guest PC 0x0c06cf2c */
if(!s->budget--) { s->failed_pc=0x0c06cf2cu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c06cf2e;
P_0c06cf2e: /* original 907e, guest PC 0x0c06cf2e */
if(!s->budget--) { s->failed_pc=0x0c06cf2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d02eu,2);
return vf3_matrix_family(0x0c06cf30u,s,ram);
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
return vf3_matrix_family(0x0c072eeau,s,ram);
P_0c073268: /* original 4f22, guest PC 0x0c073268 */
if(!s->budget--) { s->failed_pc=0x0c073268u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07326a;
P_0c07326a: /* original 64e3, guest PC 0x0c07326a */
if(!s->budget--) { s->failed_pc=0x0c07326au; return 0; }
r[4]=r[14];
goto P_0c07326c;
P_0c07326c: /* original 7ff4, guest PC 0x0c07326c */
if(!s->budget--) { s->failed_pc=0x0c07326cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c07326e;
P_0c07326e: /* original 1f51, guest PC 0x0c07326e */
if(!s->budget--) { s->failed_pc=0x0c07326eu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c073270;
P_0c073270: /* original d312, guest PC 0x0c073270 */
if(!s->budget--) { s->failed_pc=0x0c073270u; return 0; }
r[3]=read(ram,0x0c0732bcu,4);
goto P_0c073272;
P_0c073272: /* original 430b, guest PC 0x0c073272 */
if(!s->budget--) { s->failed_pc=0x0c073272u; return 0; }
target=r[3];
r[16]=0x0c073276u;
r[4]+=0x00000017u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073276u) { target=s->pc; goto dispatch; }
goto P_0c073276;
P_0c073274: /* original 7417, guest PC 0x0c073274 */
if(!s->budget--) { s->failed_pc=0x0c073274u; return 0; }
r[4]+=0x00000017u;
goto P_0c073276;
P_0c073276: /* original 600c, guest PC 0x0c073276 */
if(!s->budget--) { s->failed_pc=0x0c073276u; return 0; }
r[0]=r[0]&255u;
goto P_0c073278;
P_0c073278: /* original 64e3, guest PC 0x0c073278 */
if(!s->budget--) { s->failed_pc=0x0c073278u; return 0; }
r[4]=r[14];
goto P_0c07327a;
P_0c07327a: /* original 1f02, guest PC 0x0c07327a */
if(!s->budget--) { s->failed_pc=0x0c07327au; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c07327c;
P_0c07327c: /* original d30f, guest PC 0x0c07327c */
if(!s->budget--) { s->failed_pc=0x0c07327cu; return 0; }
r[3]=read(ram,0x0c0732bcu,4);
goto P_0c07327e;
P_0c07327e: /* original 430b, guest PC 0x0c07327e */
if(!s->budget--) { s->failed_pc=0x0c07327eu; return 0; }
target=r[3];
r[16]=0x0c073282u;
r[4]+=0x0000001du;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073282u) { target=s->pc; goto dispatch; }
goto P_0c073282;
P_0c073280: /* original 741d, guest PC 0x0c073280 */
if(!s->budget--) { s->failed_pc=0x0c073280u; return 0; }
r[4]+=0x0000001du;
goto P_0c073282;
P_0c073282: /* original 600c, guest PC 0x0c073282 */
if(!s->budget--) { s->failed_pc=0x0c073282u; return 0; }
r[0]=r[0]&255u;
goto P_0c073284;
P_0c073284: /* original e31b, guest PC 0x0c073284 */
if(!s->budget--) { s->failed_pc=0x0c073284u; return 0; }
r[3]=0x0000001bu;
goto P_0c073286;
P_0c073286: /* original 2f02, guest PC 0x0c073286 */
if(!s->budget--) { s->failed_pc=0x0c073286u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c073288;
P_0c073288: /* original 2f36, guest PC 0x0c073288 */
if(!s->budget--) { s->failed_pc=0x0c073288u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c07328a;
P_0c07328a: /* original e701, guest PC 0x0c07328a */
if(!s->budget--) { s->failed_pc=0x0c07328au; return 0; }
r[7]=0x00000001u;
goto P_0c07328c;
P_0c07328c: /* original 55f2, guest PC 0x0c07328c */
if(!s->budget--) { s->failed_pc=0x0c07328cu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c07328e;
P_0c07328e: /* original 6673, guest PC 0x0c07328e */
if(!s->budget--) { s->failed_pc=0x0c07328eu; return 0; }
r[6]=r[7];
goto P_0c073290;
P_0c073290: /* original be17, guest PC 0x0c073290 */
if(!s->budget--) { s->failed_pc=0x0c073290u; return 0; }
target=0x0c072ec2u; r[16]=0x0c073294u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073294u) { target=s->pc; goto dispatch; }
goto P_0c073294;
P_0c073292: /* original 54f1, guest PC 0x0c073292 */
if(!s->budget--) { s->failed_pc=0x0c073292u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c073294;
P_0c073294: /* original 64e3, guest PC 0x0c073294 */
if(!s->budget--) { s->failed_pc=0x0c073294u; return 0; }
r[4]=r[14];
goto P_0c073296;
P_0c073296: /* original 1f01, guest PC 0x0c073296 */
if(!s->budget--) { s->failed_pc=0x0c073296u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c073298;
P_0c073298: /* original d309, guest PC 0x0c073298 */
if(!s->budget--) { s->failed_pc=0x0c073298u; return 0; }
r[3]=read(ram,0x0c0732c0u,4);
goto P_0c07329a;
P_0c07329a: /* original 6503, guest PC 0x0c07329a */
if(!s->budget--) { s->failed_pc=0x0c07329au; return 0; }
r[5]=r[0];
goto P_0c07329c;
P_0c07329c: /* original 430b, guest PC 0x0c07329c */
if(!s->budget--) { s->failed_pc=0x0c07329cu; return 0; }
target=r[3];
r[16]=0x0c0732a0u;
r[4]+=0x0000001du;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0732a0u) { target=s->pc; goto dispatch; }
goto P_0c0732a0;
P_0c07329e: /* original 741d, guest PC 0x0c07329e */
if(!s->budget--) { s->failed_pc=0x0c07329eu; return 0; }
r[4]+=0x0000001du;
goto P_0c0732a0;
P_0c0732a0: /* original d207, guest PC 0x0c0732a0 */
if(!s->budget--) { s->failed_pc=0x0c0732a0u; return 0; }
r[2]=read(ram,0x0c0732c0u,4);
goto P_0c0732a2;
P_0c0732a2: /* original 64e3, guest PC 0x0c0732a2 */
if(!s->budget--) { s->failed_pc=0x0c0732a2u; return 0; }
r[4]=r[14];
goto P_0c0732a4;
P_0c0732a4: /* original e500, guest PC 0x0c0732a4 */
if(!s->budget--) { s->failed_pc=0x0c0732a4u; return 0; }
r[5]=0x00000000u;
goto P_0c0732a6;
P_0c0732a6: /* original 420b, guest PC 0x0c0732a6 */
if(!s->budget--) { s->failed_pc=0x0c0732a6u; return 0; }
target=r[2];
r[16]=0x0c0732aau;
r[4]+=0x0000001cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0732aau) { target=s->pc; goto dispatch; }
goto P_0c0732aa;
P_0c0732a8: /* original 741c, guest PC 0x0c0732a8 */
if(!s->budget--) { s->failed_pc=0x0c0732a8u; return 0; }
r[4]+=0x0000001cu;
goto P_0c0732aa;
P_0c0732aa: /* original 55f2, guest PC 0x0c0732aa */
if(!s->budget--) { s->failed_pc=0x0c0732aau; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0732ac;
P_0c0732ac: /* original 64e3, guest PC 0x0c0732ac */
if(!s->budget--) { s->failed_pc=0x0c0732acu; return 0; }
r[4]=r[14];
goto P_0c0732ae;
P_0c0732ae: /* original 56f3, guest PC 0x0c0732ae */
if(!s->budget--) { s->failed_pc=0x0c0732aeu; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c0732b0;
P_0c0732b0: /* original 7f10, guest PC 0x0c0732b0 */
if(!s->budget--) { s->failed_pc=0x0c0732b0u; return 0; }
r[15]+=0x00000010u;
goto P_0c0732b2;
P_0c0732b2: /* original 4f26, guest PC 0x0c0732b2 */
if(!s->budget--) { s->failed_pc=0x0c0732b2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0732b4;
P_0c0732b4: /* original a008, guest PC 0x0c0732b4 */
if(!s->budget--) { s->failed_pc=0x0c0732b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0732c8;
P_0c0732b6: /* original 6ef6, guest PC 0x0c0732b6 */
if(!s->budget--) { s->failed_pc=0x0c0732b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0732b8u,s,ram);
P_0c0732c8: /* original 2fe6, guest PC 0x0c0732c8 */
if(!s->budget--) { s->failed_pc=0x0c0732c8u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0732ca;
P_0c0732ca: /* original 2668, guest PC 0x0c0732ca */
if(!s->budget--) { s->failed_pc=0x0c0732cau; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0732cc;
P_0c0732cc: /* original 4f22, guest PC 0x0c0732cc */
if(!s->budget--) { s->failed_pc=0x0c0732ccu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0732ce;
P_0c0732ce: /* original 6e43, guest PC 0x0c0732ce */
if(!s->budget--) { s->failed_pc=0x0c0732ceu; return 0; }
r[14]=r[4];
goto P_0c0732d0;
P_0c0732d0: /* original 7ff8, guest PC 0x0c0732d0 */
if(!s->budget--) { s->failed_pc=0x0c0732d0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0732d2;
P_0c0732d2: /* original 8d20, guest PC 0x0c0732d2 */
if(!s->budget--) { s->failed_pc=0x0c0732d2u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[5],4);
if(cond) { goto P_0c073316; }
goto P_0c0732d6;
P_0c0732d4: /* original 1f51, guest PC 0x0c0732d4 */
if(!s->budget--) { s->failed_pc=0x0c0732d4u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0732d6;
P_0c0732d6: /* original d332, guest PC 0x0c0732d6 */
if(!s->budget--) { s->failed_pc=0x0c0732d6u; return 0; }
r[3]=read(ram,0x0c0733a0u,4);
goto P_0c0732d8;
P_0c0732d8: /* original 64e3, guest PC 0x0c0732d8 */
if(!s->budget--) { s->failed_pc=0x0c0732d8u; return 0; }
r[4]=r[14];
goto P_0c0732da;
P_0c0732da: /* original 430b, guest PC 0x0c0732da */
if(!s->budget--) { s->failed_pc=0x0c0732dau; return 0; }
target=r[3];
r[16]=0x0c0732deu;
r[4]+=0x0000001du;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0732deu) { target=s->pc; goto dispatch; }
goto P_0c0732de;
P_0c0732dc: /* original 741d, guest PC 0x0c0732dc */
if(!s->budget--) { s->failed_pc=0x0c0732dcu; return 0; }
r[4]+=0x0000001du;
goto P_0c0732de;
P_0c0732de: /* original 640c, guest PC 0x0c0732de */
if(!s->budget--) { s->failed_pc=0x0c0732deu; return 0; }
r[4]=r[0]&255u;
goto P_0c0732e0;
P_0c0732e0: /* original d030, guest PC 0x0c0732e0 */
if(!s->budget--) { s->failed_pc=0x0c0732e0u; return 0; }
r[0]=read(ram,0x0c0733a4u,4);
goto P_0c0732e2;
P_0c0732e2: /* original 74ff, guest PC 0x0c0732e2 */
if(!s->budget--) { s->failed_pc=0x0c0732e2u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0732e4;
P_0c0732e4: /* original 044c, guest PC 0x0c0732e4 */
if(!s->budget--) { s->failed_pc=0x0c0732e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0732e6;
P_0c0732e6: /* original 2448, guest PC 0x0c0732e6 */
if(!s->budget--) { s->failed_pc=0x0c0732e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0732e8;
P_0c0732e8: /* original 8b15, guest PC 0x0c0732e8 */
if(!s->budget--) { s->failed_pc=0x0c0732e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073316; }
goto P_0c0732ea;
P_0c0732ea: /* original d22d, guest PC 0x0c0732ea */
if(!s->budget--) { s->failed_pc=0x0c0732eau; return 0; }
r[2]=read(ram,0x0c0733a0u,4);
goto P_0c0732ec;
P_0c0732ec: /* original 64e3, guest PC 0x0c0732ec */
if(!s->budget--) { s->failed_pc=0x0c0732ecu; return 0; }
r[4]=r[14];
goto P_0c0732ee;
P_0c0732ee: /* original 420b, guest PC 0x0c0732ee */
if(!s->budget--) { s->failed_pc=0x0c0732eeu; return 0; }
target=r[2];
r[16]=0x0c0732f2u;
r[4]+=0x0000001du;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0732f2u) { target=s->pc; goto dispatch; }
goto P_0c0732f2;
P_0c0732f0: /* original 741d, guest PC 0x0c0732f0 */
if(!s->budget--) { s->failed_pc=0x0c0732f0u; return 0; }
r[4]+=0x0000001du;
goto P_0c0732f2;
P_0c0732f2: /* original 600c, guest PC 0x0c0732f2 */
if(!s->budget--) { s->failed_pc=0x0c0732f2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0732f4;
P_0c0732f4: /* original e31b, guest PC 0x0c0732f4 */
if(!s->budget--) { s->failed_pc=0x0c0732f4u; return 0; }
r[3]=0x0000001bu;
goto P_0c0732f6;
P_0c0732f6: /* original 2f02, guest PC 0x0c0732f6 */
if(!s->budget--) { s->failed_pc=0x0c0732f6u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0732f8;
P_0c0732f8: /* original 2f36, guest PC 0x0c0732f8 */
if(!s->budget--) { s->failed_pc=0x0c0732f8u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0732fa;
P_0c0732fa: /* original e701, guest PC 0x0c0732fa */
if(!s->budget--) { s->failed_pc=0x0c0732fau; return 0; }
r[7]=0x00000001u;
goto P_0c0732fc;
P_0c0732fc: /* original 55f2, guest PC 0x0c0732fc */
if(!s->budget--) { s->failed_pc=0x0c0732fcu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0732fe;
P_0c0732fe: /* original 6673, guest PC 0x0c0732fe */
if(!s->budget--) { s->failed_pc=0x0c0732feu; return 0; }
r[6]=r[7];
goto P_0c073300;
P_0c073300: /* original bddf, guest PC 0x0c073300 */
if(!s->budget--) { s->failed_pc=0x0c073300u; return 0; }
target=0x0c072ec2u; r[16]=0x0c073304u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073304u) { target=s->pc; goto dispatch; }
goto P_0c073304;
P_0c073302: /* original 54f1, guest PC 0x0c073302 */
if(!s->budget--) { s->failed_pc=0x0c073302u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c073304;
P_0c073304: /* original 7f04, guest PC 0x0c073304 */
if(!s->budget--) { s->failed_pc=0x0c073304u; return 0; }
r[15]+=0x00000004u;
goto P_0c073306;
P_0c073306: /* original 64e3, guest PC 0x0c073306 */
if(!s->budget--) { s->failed_pc=0x0c073306u; return 0; }
r[4]=r[14];
goto P_0c073308;
P_0c073308: /* original 2f02, guest PC 0x0c073308 */
if(!s->budget--) { s->failed_pc=0x0c073308u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c07330a;
P_0c07330a: /* original 6503, guest PC 0x0c07330a */
if(!s->budget--) { s->failed_pc=0x0c07330au; return 0; }
r[5]=r[0];
goto P_0c07330c;
P_0c07330c: /* original d326, guest PC 0x0c07330c */
if(!s->budget--) { s->failed_pc=0x0c07330cu; return 0; }
r[3]=read(ram,0x0c0733a8u,4);
goto P_0c07330e;
P_0c07330e: /* original 430b, guest PC 0x0c07330e */
if(!s->budget--) { s->failed_pc=0x0c07330eu; return 0; }
target=r[3];
r[16]=0x0c073312u;
r[4]+=0x0000001du;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073312u) { target=s->pc; goto dispatch; }
goto P_0c073312;
P_0c073310: /* original 741d, guest PC 0x0c073310 */
if(!s->budget--) { s->failed_pc=0x0c073310u; return 0; }
r[4]+=0x0000001du;
goto P_0c073312;
P_0c073312: /* original afe0, guest PC 0x0c073312 */
if(!s->budget--) { s->failed_pc=0x0c073312u; return 0; }
goto P_0c0732d6;
P_0c073314: /* original 0009, guest PC 0x0c073314 */
if(!s->budget--) { s->failed_pc=0x0c073314u; return 0; }
goto P_0c073316;
P_0c073316: /* original 7f08, guest PC 0x0c073316 */
if(!s->budget--) { s->failed_pc=0x0c073316u; return 0; }
r[15]+=0x00000008u;
goto P_0c073318;
P_0c073318: /* original 64e3, guest PC 0x0c073318 */
if(!s->budget--) { s->failed_pc=0x0c073318u; return 0; }
r[4]=r[14];
goto P_0c07331a;
P_0c07331a: /* original 4f26, guest PC 0x0c07331a */
if(!s->budget--) { s->failed_pc=0x0c07331au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07331c;
P_0c07331c: /* original a000, guest PC 0x0c07331c */
if(!s->budget--) { s->failed_pc=0x0c07331cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c073320;
P_0c07331e: /* original 6ef6, guest PC 0x0c07331e */
if(!s->budget--) { s->failed_pc=0x0c07331eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c073320;
P_0c073320: /* original 2fe6, guest PC 0x0c073320 */
if(!s->budget--) { s->failed_pc=0x0c073320u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c073322;
P_0c073322: /* original 6e43, guest PC 0x0c073322 */
if(!s->budget--) { s->failed_pc=0x0c073322u; return 0; }
r[14]=r[4];
goto P_0c073324;
P_0c073324: /* original 2fd6, guest PC 0x0c073324 */
if(!s->budget--) { s->failed_pc=0x0c073324u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c073326;
P_0c073326: /* original 2fc6, guest PC 0x0c073326 */
if(!s->budget--) { s->failed_pc=0x0c073326u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c073328;
P_0c073328: /* original 4f22, guest PC 0x0c073328 */
if(!s->budget--) { s->failed_pc=0x0c073328u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07332a;
P_0c07332a: /* original d31d, guest PC 0x0c07332a */
if(!s->budget--) { s->failed_pc=0x0c07332au; return 0; }
r[3]=read(ram,0x0c0733a0u,4);
goto P_0c07332c;
P_0c07332c: /* original 7ffc, guest PC 0x0c07332c */
if(!s->budget--) { s->failed_pc=0x0c07332cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07332e;
P_0c07332e: /* original 430b, guest PC 0x0c07332e */
if(!s->budget--) { s->failed_pc=0x0c07332eu; return 0; }
target=r[3];
r[16]=0x0c073332u;
r[4]+=0x0000001du;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073332u) { target=s->pc; goto dispatch; }
goto P_0c073332;
P_0c073330: /* original 741d, guest PC 0x0c073330 */
if(!s->budget--) { s->failed_pc=0x0c073330u; return 0; }
r[4]+=0x0000001du;
goto P_0c073332;
P_0c073332: /* original 640c, guest PC 0x0c073332 */
if(!s->budget--) { s->failed_pc=0x0c073332u; return 0; }
r[4]=r[0]&255u;
goto P_0c073334;
P_0c073334: /* original dc1d, guest PC 0x0c073334 */
if(!s->budget--) { s->failed_pc=0x0c073334u; return 0; }
r[12]=read(ram,0x0c0733acu,4);
goto P_0c073336;
P_0c073336: /* original 74ff, guest PC 0x0c073336 */
if(!s->budget--) { s->failed_pc=0x0c073336u; return 0; }
r[4]+=0xffffffffu;
goto P_0c073338;
P_0c073338: /* original 4408, guest PC 0x0c073338 */
if(!s->budget--) { s->failed_pc=0x0c073338u; return 0; }
r[4]<<=2;
goto P_0c07333a;
P_0c07333a: /* original 3c4c, guest PC 0x0c07333a */
if(!s->budget--) { s->failed_pc=0x0c07333au; return 0; }
r[12]+=r[4];
goto P_0c07333c;
P_0c07333c: /* original 64e3, guest PC 0x0c07333c */
if(!s->budget--) { s->failed_pc=0x0c07333cu; return 0; }
r[4]=r[14];
goto P_0c07333e;
P_0c07333e: /* original 62c0, guest PC 0x0c07333e */
if(!s->budget--) { s->failed_pc=0x0c07333eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[2]=tmp;
goto P_0c073340;
P_0c073340: /* original 622c, guest PC 0x0c073340 */
if(!s->budget--) { s->failed_pc=0x0c073340u; return 0; }
r[2]=r[2]&255u;
goto P_0c073342;
P_0c073342: /* original 6523, guest PC 0x0c073342 */
if(!s->budget--) { s->failed_pc=0x0c073342u; return 0; }
r[5]=r[2];
goto P_0c073344;
P_0c073344: /* original 2f22, guest PC 0x0c073344 */
if(!s->budget--) { s->failed_pc=0x0c073344u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c073346;
P_0c073346: /* original dd18, guest PC 0x0c073346 */
if(!s->budget--) { s->failed_pc=0x0c073346u; return 0; }
r[13]=read(ram,0x0c0733a8u,4);
goto P_0c073348;
P_0c073348: /* original 4d0b, guest PC 0x0c073348 */
if(!s->budget--) { s->failed_pc=0x0c073348u; return 0; }
target=r[13];
r[16]=0x0c07334cu;
r[4]+=0x0000001eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07334cu) { target=s->pc; goto dispatch; }
goto P_0c07334c;
P_0c07334a: /* original 741e, guest PC 0x0c07334a */
if(!s->budget--) { s->failed_pc=0x0c07334au; return 0; }
r[4]+=0x0000001eu;
goto P_0c07334c;
P_0c07334c: /* original 84c1, guest PC 0x0c07334c */
if(!s->budget--) { s->failed_pc=0x0c07334cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+1,1);
goto P_0c07334e;
P_0c07334e: /* original 64e3, guest PC 0x0c07334e */
if(!s->budget--) { s->failed_pc=0x0c07334eu; return 0; }
r[4]=r[14];
goto P_0c073350;
P_0c073350: /* original 600c, guest PC 0x0c073350 */
if(!s->budget--) { s->failed_pc=0x0c073350u; return 0; }
r[0]=r[0]&255u;
goto P_0c073352;
P_0c073352: /* original 6503, guest PC 0x0c073352 */
if(!s->budget--) { s->failed_pc=0x0c073352u; return 0; }
r[5]=r[0];
goto P_0c073354;
P_0c073354: /* original 2f02, guest PC 0x0c073354 */
if(!s->budget--) { s->failed_pc=0x0c073354u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c073356;
P_0c073356: /* original 4d0b, guest PC 0x0c073356 */
if(!s->budget--) { s->failed_pc=0x0c073356u; return 0; }
target=r[13];
r[16]=0x0c07335au;
r[4]+=0x0000001fu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07335au) { target=s->pc; goto dispatch; }
goto P_0c07335a;
P_0c073358: /* original 741f, guest PC 0x0c073358 */
if(!s->budget--) { s->failed_pc=0x0c073358u; return 0; }
r[4]+=0x0000001fu;
goto P_0c07335a;
P_0c07335a: /* original 84c2, guest PC 0x0c07335a */
if(!s->budget--) { s->failed_pc=0x0c07335au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+2,1);
goto P_0c07335c;
P_0c07335c: /* original 64e3, guest PC 0x0c07335c */
if(!s->budget--) { s->failed_pc=0x0c07335cu; return 0; }
r[4]=r[14];
goto P_0c07335e;
P_0c07335e: /* original 600c, guest PC 0x0c07335e */
if(!s->budget--) { s->failed_pc=0x0c07335eu; return 0; }
r[0]=r[0]&255u;
goto P_0c073360;
P_0c073360: /* original 6503, guest PC 0x0c073360 */
if(!s->budget--) { s->failed_pc=0x0c073360u; return 0; }
r[5]=r[0];
goto P_0c073362;
P_0c073362: /* original 2f02, guest PC 0x0c073362 */
if(!s->budget--) { s->failed_pc=0x0c073362u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c073364;
P_0c073364: /* original 4d0b, guest PC 0x0c073364 */
if(!s->budget--) { s->failed_pc=0x0c073364u; return 0; }
target=r[13];
r[16]=0x0c073368u;
r[4]+=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073368u) { target=s->pc; goto dispatch; }
goto P_0c073368;
P_0c073366: /* original 7420, guest PC 0x0c073366 */
if(!s->budget--) { s->failed_pc=0x0c073366u; return 0; }
r[4]+=0x00000020u;
goto P_0c073368;
P_0c073368: /* original 84c3, guest PC 0x0c073368 */
if(!s->budget--) { s->failed_pc=0x0c073368u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+3,1);
goto P_0c07336a;
P_0c07336a: /* original 64e3, guest PC 0x0c07336a */
if(!s->budget--) { s->failed_pc=0x0c07336au; return 0; }
r[4]=r[14];
goto P_0c07336c;
P_0c07336c: /* original 600c, guest PC 0x0c07336c */
if(!s->budget--) { s->failed_pc=0x0c07336cu; return 0; }
r[0]=r[0]&255u;
goto P_0c07336e;
P_0c07336e: /* original 6503, guest PC 0x0c07336e */
if(!s->budget--) { s->failed_pc=0x0c07336eu; return 0; }
r[5]=r[0];
goto P_0c073370;
P_0c073370: /* original 2f02, guest PC 0x0c073370 */
if(!s->budget--) { s->failed_pc=0x0c073370u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c073372;
P_0c073372: /* original 4d0b, guest PC 0x0c073372 */
if(!s->budget--) { s->failed_pc=0x0c073372u; return 0; }
target=r[13];
r[16]=0x0c073376u;
r[4]+=0x00000021u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073376u) { target=s->pc; goto dispatch; }
goto P_0c073376;
P_0c073374: /* original 7421, guest PC 0x0c073374 */
if(!s->budget--) { s->failed_pc=0x0c073374u; return 0; }
r[4]+=0x00000021u;
goto P_0c073376;
P_0c073376: /* original 7f04, guest PC 0x0c073376 */
if(!s->budget--) { s->failed_pc=0x0c073376u; return 0; }
r[15]+=0x00000004u;
goto P_0c073378;
P_0c073378: /* original 4f26, guest PC 0x0c073378 */
if(!s->budget--) { s->failed_pc=0x0c073378u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07337a;
P_0c07337a: /* original 6cf6, guest PC 0x0c07337a */
if(!s->budget--) { s->failed_pc=0x0c07337au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07337c;
P_0c07337c: /* original 6df6, guest PC 0x0c07337c */
if(!s->budget--) { s->failed_pc=0x0c07337cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07337e;
P_0c07337e: /* original 000b, guest PC 0x0c07337e */
if(!s->budget--) { s->failed_pc=0x0c07337eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c073380: /* original 6ef6, guest PC 0x0c073380 */
if(!s->budget--) { s->failed_pc=0x0c073380u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c073382u,s,ram);
P_0c073696: /* original 4f22, guest PC 0x0c073696 */
if(!s->budget--) { s->failed_pc=0x0c073696u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c073698;
P_0c073698: /* original 64e3, guest PC 0x0c073698 */
if(!s->budget--) { s->failed_pc=0x0c073698u; return 0; }
r[4]=r[14];
goto P_0c07369a;
P_0c07369a: /* original 7ff8, guest PC 0x0c07369a */
if(!s->budget--) { s->failed_pc=0x0c07369au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07369c;
P_0c07369c: /* original 1f51, guest PC 0x0c07369c */
if(!s->budget--) { s->failed_pc=0x0c07369cu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c07369e;
P_0c07369e: /* original d32c, guest PC 0x0c07369e */
if(!s->budget--) { s->failed_pc=0x0c07369eu; return 0; }
r[3]=read(ram,0x0c073750u,4);
goto P_0c0736a0;
P_0c0736a0: /* original 430b, guest PC 0x0c0736a0 */
if(!s->budget--) { s->failed_pc=0x0c0736a0u; return 0; }
target=r[3];
r[16]=0x0c0736a4u;
r[4]+=0x00000022u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0736a4u) { target=s->pc; goto dispatch; }
goto P_0c0736a4;
P_0c0736a2: /* original 7422, guest PC 0x0c0736a2 */
if(!s->budget--) { s->failed_pc=0x0c0736a2u; return 0; }
r[4]+=0x00000022u;
goto P_0c0736a4;
P_0c0736a4: /* original 600c, guest PC 0x0c0736a4 */
if(!s->budget--) { s->failed_pc=0x0c0736a4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0736a6;
P_0c0736a6: /* original e309, guest PC 0x0c0736a6 */
if(!s->budget--) { s->failed_pc=0x0c0736a6u; return 0; }
r[3]=0x00000009u;
goto P_0c0736a8;
P_0c0736a8: /* original 2f02, guest PC 0x0c0736a8 */
if(!s->budget--) { s->failed_pc=0x0c0736a8u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0736aa;
P_0c0736aa: /* original 2f36, guest PC 0x0c0736aa */
if(!s->budget--) { s->failed_pc=0x0c0736aau; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0736ac;
P_0c0736ac: /* original e701, guest PC 0x0c0736ac */
if(!s->budget--) { s->failed_pc=0x0c0736acu; return 0; }
r[7]=0x00000001u;
goto P_0c0736ae;
P_0c0736ae: /* original 55f2, guest PC 0x0c0736ae */
if(!s->budget--) { s->failed_pc=0x0c0736aeu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0736b0;
P_0c0736b0: /* original 6673, guest PC 0x0c0736b0 */
if(!s->budget--) { s->failed_pc=0x0c0736b0u; return 0; }
r[6]=r[7];
goto P_0c0736b2;
P_0c0736b2: /* original bc06, guest PC 0x0c0736b2 */
if(!s->budget--) { s->failed_pc=0x0c0736b2u; return 0; }
target=0x0c072ec2u; r[16]=0x0c0736b6u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0736b6u) { target=s->pc; goto dispatch; }
goto P_0c0736b6;
P_0c0736b4: /* original 54f1, guest PC 0x0c0736b4 */
if(!s->budget--) { s->failed_pc=0x0c0736b4u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0736b6;
P_0c0736b6: /* original 64e3, guest PC 0x0c0736b6 */
if(!s->budget--) { s->failed_pc=0x0c0736b6u; return 0; }
r[4]=r[14];
goto P_0c0736b8;
P_0c0736b8: /* original 1f01, guest PC 0x0c0736b8 */
if(!s->budget--) { s->failed_pc=0x0c0736b8u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0736ba;
P_0c0736ba: /* original d32a, guest PC 0x0c0736ba */
if(!s->budget--) { s->failed_pc=0x0c0736bau; return 0; }
r[3]=read(ram,0x0c073764u,4);
goto P_0c0736bc;
P_0c0736bc: /* original 6503, guest PC 0x0c0736bc */
if(!s->budget--) { s->failed_pc=0x0c0736bcu; return 0; }
r[5]=r[0];
goto P_0c0736be;
P_0c0736be: /* original 430b, guest PC 0x0c0736be */
if(!s->budget--) { s->failed_pc=0x0c0736beu; return 0; }
target=r[3];
r[16]=0x0c0736c2u;
r[4]+=0x00000022u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0736c2u) { target=s->pc; goto dispatch; }
goto P_0c0736c2;
P_0c0736c0: /* original 7422, guest PC 0x0c0736c0 */
if(!s->budget--) { s->failed_pc=0x0c0736c0u; return 0; }
r[4]+=0x00000022u;
goto P_0c0736c2;
P_0c0736c2: /* original 7f0c, guest PC 0x0c0736c2 */
if(!s->budget--) { s->failed_pc=0x0c0736c2u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0736c4;
P_0c0736c4: /* original d227, guest PC 0x0c0736c4 */
if(!s->budget--) { s->failed_pc=0x0c0736c4u; return 0; }
r[2]=read(ram,0x0c073764u,4);
goto P_0c0736c6;
P_0c0736c6: /* original 4f26, guest PC 0x0c0736c6 */
if(!s->budget--) { s->failed_pc=0x0c0736c6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0736c8;
P_0c0736c8: /* original 64e3, guest PC 0x0c0736c8 */
if(!s->budget--) { s->failed_pc=0x0c0736c8u; return 0; }
r[4]=r[14];
goto P_0c0736ca;
P_0c0736ca: /* original e501, guest PC 0x0c0736ca */
if(!s->budget--) { s->failed_pc=0x0c0736cau; return 0; }
r[5]=0x00000001u;
goto P_0c0736cc;
P_0c0736cc: /* original 741c, guest PC 0x0c0736cc */
if(!s->budget--) { s->failed_pc=0x0c0736ccu; return 0; }
r[4]+=0x0000001cu;
goto P_0c0736ce;
P_0c0736ce: /* original 422b, guest PC 0x0c0736ce */
if(!s->budget--) { s->failed_pc=0x0c0736ceu; return 0; }
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
P_0c0736d0: /* original 6ef6, guest PC 0x0c0736d0 */
if(!s->budget--) { s->failed_pc=0x0c0736d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0736d2u,s,ram);
P_0c07376c: /* original 4f22, guest PC 0x0c07376c */
if(!s->budget--) { s->failed_pc=0x0c07376cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07376e;
P_0c07376e: /* original 64e3, guest PC 0x0c07376e */
if(!s->budget--) { s->failed_pc=0x0c07376eu; return 0; }
r[4]=r[14];
goto P_0c073770;
P_0c073770: /* original 7ff8, guest PC 0x0c073770 */
if(!s->budget--) { s->failed_pc=0x0c073770u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c073772;
P_0c073772: /* original 1f51, guest PC 0x0c073772 */
if(!s->budget--) { s->failed_pc=0x0c073772u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c073774;
P_0c073774: /* original d333, guest PC 0x0c073774 */
if(!s->budget--) { s->failed_pc=0x0c073774u; return 0; }
r[3]=read(ram,0x0c073844u,4);
goto P_0c073776;
P_0c073776: /* original 430b, guest PC 0x0c073776 */
if(!s->budget--) { s->failed_pc=0x0c073776u; return 0; }
target=r[3];
r[16]=0x0c07377au;
r[4]+=0x00000023u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07377au) { target=s->pc; goto dispatch; }
goto P_0c07377a;
P_0c073778: /* original 7423, guest PC 0x0c073778 */
if(!s->budget--) { s->failed_pc=0x0c073778u; return 0; }
r[4]+=0x00000023u;
goto P_0c07377a;
P_0c07377a: /* original 600c, guest PC 0x0c07377a */
if(!s->budget--) { s->failed_pc=0x0c07377au; return 0; }
r[0]=r[0]&255u;
goto P_0c07377c;
P_0c07377c: /* original e309, guest PC 0x0c07377c */
if(!s->budget--) { s->failed_pc=0x0c07377cu; return 0; }
r[3]=0x00000009u;
goto P_0c07377e;
P_0c07377e: /* original 2f02, guest PC 0x0c07377e */
if(!s->budget--) { s->failed_pc=0x0c07377eu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c073780;
P_0c073780: /* original 2f36, guest PC 0x0c073780 */
if(!s->budget--) { s->failed_pc=0x0c073780u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c073782;
P_0c073782: /* original e701, guest PC 0x0c073782 */
if(!s->budget--) { s->failed_pc=0x0c073782u; return 0; }
r[7]=0x00000001u;
goto P_0c073784;
P_0c073784: /* original 55f2, guest PC 0x0c073784 */
if(!s->budget--) { s->failed_pc=0x0c073784u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c073786;
P_0c073786: /* original 6673, guest PC 0x0c073786 */
if(!s->budget--) { s->failed_pc=0x0c073786u; return 0; }
r[6]=r[7];
goto P_0c073788;
P_0c073788: /* original bb9b, guest PC 0x0c073788 */
if(!s->budget--) { s->failed_pc=0x0c073788u; return 0; }
target=0x0c072ec2u; r[16]=0x0c07378cu;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07378cu) { target=s->pc; goto dispatch; }
goto P_0c07378c;
P_0c07378a: /* original 54f1, guest PC 0x0c07378a */
if(!s->budget--) { s->failed_pc=0x0c07378au; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07378c;
P_0c07378c: /* original 64e3, guest PC 0x0c07378c */
if(!s->budget--) { s->failed_pc=0x0c07378cu; return 0; }
r[4]=r[14];
goto P_0c07378e;
P_0c07378e: /* original 1f01, guest PC 0x0c07378e */
if(!s->budget--) { s->failed_pc=0x0c07378eu; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c073790;
P_0c073790: /* original d32d, guest PC 0x0c073790 */
if(!s->budget--) { s->failed_pc=0x0c073790u; return 0; }
r[3]=read(ram,0x0c073848u,4);
goto P_0c073792;
P_0c073792: /* original 6503, guest PC 0x0c073792 */
if(!s->budget--) { s->failed_pc=0x0c073792u; return 0; }
r[5]=r[0];
goto P_0c073794;
P_0c073794: /* original 430b, guest PC 0x0c073794 */
if(!s->budget--) { s->failed_pc=0x0c073794u; return 0; }
target=r[3];
r[16]=0x0c073798u;
r[4]+=0x00000023u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c073798u) { target=s->pc; goto dispatch; }
goto P_0c073798;
P_0c073796: /* original 7423, guest PC 0x0c073796 */
if(!s->budget--) { s->failed_pc=0x0c073796u; return 0; }
r[4]+=0x00000023u;
goto P_0c073798;
P_0c073798: /* original 7f0c, guest PC 0x0c073798 */
if(!s->budget--) { s->failed_pc=0x0c073798u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07379a;
P_0c07379a: /* original d22b, guest PC 0x0c07379a */
if(!s->budget--) { s->failed_pc=0x0c07379au; return 0; }
r[2]=read(ram,0x0c073848u,4);
goto P_0c07379c;
P_0c07379c: /* original 4f26, guest PC 0x0c07379c */
if(!s->budget--) { s->failed_pc=0x0c07379cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07379e;
P_0c07379e: /* original 64e3, guest PC 0x0c07379e */
if(!s->budget--) { s->failed_pc=0x0c07379eu; return 0; }
r[4]=r[14];
goto P_0c0737a0;
P_0c0737a0: /* original e501, guest PC 0x0c0737a0 */
if(!s->budget--) { s->failed_pc=0x0c0737a0u; return 0; }
r[5]=0x00000001u;
goto P_0c0737a2;
P_0c0737a2: /* original 741c, guest PC 0x0c0737a2 */
if(!s->budget--) { s->failed_pc=0x0c0737a2u; return 0; }
r[4]+=0x0000001cu;
goto P_0c0737a4;
P_0c0737a4: /* original 422b, guest PC 0x0c0737a4 */
if(!s->budget--) { s->failed_pc=0x0c0737a4u; return 0; }
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
P_0c0737a6: /* original 6ef6, guest PC 0x0c0737a6 */
if(!s->budget--) { s->failed_pc=0x0c0737a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0737a8u,s,ram);
P_0c0737ac: /* original 4f22, guest PC 0x0c0737ac */
if(!s->budget--) { s->failed_pc=0x0c0737acu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0737ae;
P_0c0737ae: /* original 64e3, guest PC 0x0c0737ae */
if(!s->budget--) { s->failed_pc=0x0c0737aeu; return 0; }
r[4]=r[14];
goto P_0c0737b0;
P_0c0737b0: /* original 7ff8, guest PC 0x0c0737b0 */
if(!s->budget--) { s->failed_pc=0x0c0737b0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0737b2;
P_0c0737b2: /* original 1f51, guest PC 0x0c0737b2 */
if(!s->budget--) { s->failed_pc=0x0c0737b2u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0737b4;
P_0c0737b4: /* original d323, guest PC 0x0c0737b4 */
if(!s->budget--) { s->failed_pc=0x0c0737b4u; return 0; }
r[3]=read(ram,0x0c073844u,4);
goto P_0c0737b6;
P_0c0737b6: /* original 430b, guest PC 0x0c0737b6 */
if(!s->budget--) { s->failed_pc=0x0c0737b6u; return 0; }
target=r[3];
r[16]=0x0c0737bau;
r[4]+=0x00000024u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0737bau) { target=s->pc; goto dispatch; }
goto P_0c0737ba;
P_0c0737b8: /* original 7424, guest PC 0x0c0737b8 */
if(!s->budget--) { s->failed_pc=0x0c0737b8u; return 0; }
r[4]+=0x00000024u;
goto P_0c0737ba;
P_0c0737ba: /* original 600c, guest PC 0x0c0737ba */
if(!s->budget--) { s->failed_pc=0x0c0737bau; return 0; }
r[0]=r[0]&255u;
goto P_0c0737bc;
P_0c0737bc: /* original e309, guest PC 0x0c0737bc */
if(!s->budget--) { s->failed_pc=0x0c0737bcu; return 0; }
r[3]=0x00000009u;
goto P_0c0737be;
P_0c0737be: /* original 2f02, guest PC 0x0c0737be */
if(!s->budget--) { s->failed_pc=0x0c0737beu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0737c0;
P_0c0737c0: /* original 2f36, guest PC 0x0c0737c0 */
if(!s->budget--) { s->failed_pc=0x0c0737c0u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0737c2;
P_0c0737c2: /* original e701, guest PC 0x0c0737c2 */
if(!s->budget--) { s->failed_pc=0x0c0737c2u; return 0; }
r[7]=0x00000001u;
goto P_0c0737c4;
P_0c0737c4: /* original 55f2, guest PC 0x0c0737c4 */
if(!s->budget--) { s->failed_pc=0x0c0737c4u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0737c6;
P_0c0737c6: /* original 6673, guest PC 0x0c0737c6 */
if(!s->budget--) { s->failed_pc=0x0c0737c6u; return 0; }
r[6]=r[7];
goto P_0c0737c8;
P_0c0737c8: /* original bb7b, guest PC 0x0c0737c8 */
if(!s->budget--) { s->failed_pc=0x0c0737c8u; return 0; }
target=0x0c072ec2u; r[16]=0x0c0737ccu;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0737ccu) { target=s->pc; goto dispatch; }
goto P_0c0737cc;
P_0c0737ca: /* original 54f1, guest PC 0x0c0737ca */
if(!s->budget--) { s->failed_pc=0x0c0737cau; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0737cc;
P_0c0737cc: /* original 64e3, guest PC 0x0c0737cc */
if(!s->budget--) { s->failed_pc=0x0c0737ccu; return 0; }
r[4]=r[14];
goto P_0c0737ce;
P_0c0737ce: /* original 1f01, guest PC 0x0c0737ce */
if(!s->budget--) { s->failed_pc=0x0c0737ceu; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0737d0;
P_0c0737d0: /* original d31d, guest PC 0x0c0737d0 */
if(!s->budget--) { s->failed_pc=0x0c0737d0u; return 0; }
r[3]=read(ram,0x0c073848u,4);
goto P_0c0737d2;
P_0c0737d2: /* original 6503, guest PC 0x0c0737d2 */
if(!s->budget--) { s->failed_pc=0x0c0737d2u; return 0; }
r[5]=r[0];
goto P_0c0737d4;
P_0c0737d4: /* original 430b, guest PC 0x0c0737d4 */
if(!s->budget--) { s->failed_pc=0x0c0737d4u; return 0; }
target=r[3];
r[16]=0x0c0737d8u;
r[4]+=0x00000024u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0737d8u) { target=s->pc; goto dispatch; }
goto P_0c0737d8;
P_0c0737d6: /* original 7424, guest PC 0x0c0737d6 */
if(!s->budget--) { s->failed_pc=0x0c0737d6u; return 0; }
r[4]+=0x00000024u;
goto P_0c0737d8;
P_0c0737d8: /* original 7f0c, guest PC 0x0c0737d8 */
if(!s->budget--) { s->failed_pc=0x0c0737d8u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0737da;
P_0c0737da: /* original d21b, guest PC 0x0c0737da */
if(!s->budget--) { s->failed_pc=0x0c0737dau; return 0; }
r[2]=read(ram,0x0c073848u,4);
goto P_0c0737dc;
P_0c0737dc: /* original 4f26, guest PC 0x0c0737dc */
if(!s->budget--) { s->failed_pc=0x0c0737dcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0737de;
P_0c0737de: /* original 64e3, guest PC 0x0c0737de */
if(!s->budget--) { s->failed_pc=0x0c0737deu; return 0; }
r[4]=r[14];
goto P_0c0737e0;
P_0c0737e0: /* original e501, guest PC 0x0c0737e0 */
if(!s->budget--) { s->failed_pc=0x0c0737e0u; return 0; }
r[5]=0x00000001u;
goto P_0c0737e2;
P_0c0737e2: /* original 741c, guest PC 0x0c0737e2 */
if(!s->budget--) { s->failed_pc=0x0c0737e2u; return 0; }
r[4]+=0x0000001cu;
goto P_0c0737e4;
P_0c0737e4: /* original 422b, guest PC 0x0c0737e4 */
if(!s->budget--) { s->failed_pc=0x0c0737e4u; return 0; }
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
P_0c0737e6: /* original 6ef6, guest PC 0x0c0737e6 */
if(!s->budget--) { s->failed_pc=0x0c0737e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0737e8u,s,ram);
P_0c07b988: /* original 2fe6, guest PC 0x0c07b988 */
if(!s->budget--) { s->failed_pc=0x0c07b988u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07b98a;
P_0c07b98a: /* original 4f22, guest PC 0x0c07b98a */
if(!s->budget--) { s->failed_pc=0x0c07b98au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b98c;
P_0c07b98c: /* original d31f, guest PC 0x0c07b98c */
if(!s->budget--) { s->failed_pc=0x0c07b98cu; return 0; }
r[3]=read(ram,0x0c07ba0cu,4);
goto P_0c07b98e;
P_0c07b98e: /* original 430b, guest PC 0x0c07b98e */
if(!s->budget--) { s->failed_pc=0x0c07b98eu; return 0; }
target=r[3];
r[16]=0x0c07b992u;
r[14]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b992u) { target=s->pc; goto dispatch; }
goto P_0c07b992;
P_0c07b990: /* original 6e43, guest PC 0x0c07b990 */
if(!s->budget--) { s->failed_pc=0x0c07b990u; return 0; }
r[14]=r[4];
goto P_0c07b992;
P_0c07b992: /* original 4f26, guest PC 0x0c07b992 */
if(!s->budget--) { s->failed_pc=0x0c07b992u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b994;
P_0c07b994: /* original d21e, guest PC 0x0c07b994 */
if(!s->budget--) { s->failed_pc=0x0c07b994u; return 0; }
r[2]=read(ram,0x0c07ba10u,4);
goto P_0c07b996;
P_0c07b996: /* original 1e23, guest PC 0x0c07b996 */
if(!s->budget--) { s->failed_pc=0x0c07b996u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c07b998;
P_0c07b998: /* original d31e, guest PC 0x0c07b998 */
if(!s->budget--) { s->failed_pc=0x0c07b998u; return 0; }
r[3]=read(ram,0x0c07ba14u,4);
goto P_0c07b99a;
P_0c07b99a: /* original 1e34, guest PC 0x0c07b99a */
if(!s->budget--) { s->failed_pc=0x0c07b99au; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c07b99c;
P_0c07b99c: /* original 000b, guest PC 0x0c07b99c */
if(!s->budget--) { s->failed_pc=0x0c07b99cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b99e: /* original 6ef6, guest PC 0x0c07b99e */
if(!s->budget--) { s->failed_pc=0x0c07b99eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07b9a0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
