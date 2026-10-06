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
int vf3_target_extended_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0356d4u: goto P_0c0356d4;
case 0x0c0356d6u: goto P_0c0356d6;
case 0x0c0356d8u: goto P_0c0356d8;
case 0x0c0356dau: goto P_0c0356da;
case 0x0c0356dcu: goto P_0c0356dc;
case 0x0c0356deu: goto P_0c0356de;
case 0x0c0356e0u: goto P_0c0356e0;
case 0x0c0356e2u: goto P_0c0356e2;
case 0x0c0356e4u: goto P_0c0356e4;
case 0x0c0356e6u: goto P_0c0356e6;
case 0x0c0356e8u: goto P_0c0356e8;
case 0x0c0356eau: goto P_0c0356ea;
case 0x0c0356ecu: goto P_0c0356ec;
case 0x0c0356eeu: goto P_0c0356ee;
case 0x0c0356f0u: goto P_0c0356f0;
case 0x0c0356f2u: goto P_0c0356f2;
case 0x0c0356f4u: goto P_0c0356f4;
case 0x0c0356f6u: goto P_0c0356f6;
case 0x0c0356f8u: goto P_0c0356f8;
case 0x0c0356fau: goto P_0c0356fa;
case 0x0c0356fcu: goto P_0c0356fc;
case 0x0c0356feu: goto P_0c0356fe;
case 0x0c035700u: goto P_0c035700;
case 0x0c035702u: goto P_0c035702;
case 0x0c035704u: goto P_0c035704;
case 0x0c035706u: goto P_0c035706;
case 0x0c035708u: goto P_0c035708;
case 0x0c03570au: goto P_0c03570a;
case 0x0c03570cu: goto P_0c03570c;
case 0x0c03570eu: goto P_0c03570e;
case 0x0c035710u: goto P_0c035710;
case 0x0c035712u: goto P_0c035712;
case 0x0c035714u: goto P_0c035714;
case 0x0c035716u: goto P_0c035716;
case 0x0c035718u: goto P_0c035718;
case 0x0c03571au: goto P_0c03571a;
case 0x0c03571cu: goto P_0c03571c;
case 0x0c03571eu: goto P_0c03571e;
case 0x0c035720u: goto P_0c035720;
case 0x0c035722u: goto P_0c035722;
case 0x0c035724u: goto P_0c035724;
case 0x0c035726u: goto P_0c035726;
case 0x0c035728u: goto P_0c035728;
case 0x0c03572au: goto P_0c03572a;
case 0x0c03572cu: goto P_0c03572c;
case 0x0c03572eu: goto P_0c03572e;
case 0x0c035730u: goto P_0c035730;
case 0x0c035732u: goto P_0c035732;
case 0x0c035734u: goto P_0c035734;
case 0x0c035736u: goto P_0c035736;
case 0x0c035738u: goto P_0c035738;
case 0x0c03573au: goto P_0c03573a;
case 0x0c03573cu: goto P_0c03573c;
case 0x0c03573eu: goto P_0c03573e;
case 0x0c035740u: goto P_0c035740;
case 0x0c035742u: goto P_0c035742;
case 0x0c035744u: goto P_0c035744;
case 0x0c035746u: goto P_0c035746;
case 0x0c035748u: goto P_0c035748;
case 0x0c03574au: goto P_0c03574a;
case 0x0c03574cu: goto P_0c03574c;
case 0x0c03574eu: goto P_0c03574e;
case 0x0c035750u: goto P_0c035750;
case 0x0c035752u: goto P_0c035752;
case 0x0c035754u: goto P_0c035754;
case 0x0c035756u: goto P_0c035756;
case 0x0c035758u: goto P_0c035758;
case 0x0c03575au: goto P_0c03575a;
case 0x0c03575cu: goto P_0c03575c;
case 0x0c03575eu: goto P_0c03575e;
case 0x0c035760u: goto P_0c035760;
case 0x0c035762u: goto P_0c035762;
case 0x0c035764u: goto P_0c035764;
case 0x0c035766u: goto P_0c035766;
case 0x0c035768u: goto P_0c035768;
case 0x0c03576au: goto P_0c03576a;
case 0x0c03576cu: goto P_0c03576c;
case 0x0c03576eu: goto P_0c03576e;
case 0x0c035770u: goto P_0c035770;
case 0x0c035772u: goto P_0c035772;
case 0x0c035774u: goto P_0c035774;
case 0x0c035776u: goto P_0c035776;
case 0x0c035778u: goto P_0c035778;
case 0x0c03577au: goto P_0c03577a;
case 0x0c03577cu: goto P_0c03577c;
case 0x0c03577eu: goto P_0c03577e;
case 0x0c035780u: goto P_0c035780;
case 0x0c035782u: goto P_0c035782;
case 0x0c035784u: goto P_0c035784;
case 0x0c035786u: goto P_0c035786;
case 0x0c035788u: goto P_0c035788;
case 0x0c03578au: goto P_0c03578a;
case 0x0c03578cu: goto P_0c03578c;
case 0x0c03578eu: goto P_0c03578e;
case 0x0c035790u: goto P_0c035790;
case 0x0c035792u: goto P_0c035792;
case 0x0c035794u: goto P_0c035794;
case 0x0c035796u: goto P_0c035796;
case 0x0c035798u: goto P_0c035798;
case 0x0c03579au: goto P_0c03579a;
case 0x0c03579cu: goto P_0c03579c;
case 0x0c03579eu: goto P_0c03579e;
case 0x0c0357a0u: goto P_0c0357a0;
case 0x0c0357a2u: goto P_0c0357a2;
case 0x0c0357a4u: goto P_0c0357a4;
case 0x0c0357a6u: goto P_0c0357a6;
case 0x0c0357a8u: goto P_0c0357a8;
case 0x0c0357aau: goto P_0c0357aa;
case 0x0c0357acu: goto P_0c0357ac;
case 0x0c0357aeu: goto P_0c0357ae;
case 0x0c0357b0u: goto P_0c0357b0;
case 0x0c0357b2u: goto P_0c0357b2;
case 0x0c0357b4u: goto P_0c0357b4;
case 0x0c0357b6u: goto P_0c0357b6;
case 0x0c0357b8u: goto P_0c0357b8;
case 0x0c0357bau: goto P_0c0357ba;
case 0x0c038956u: goto P_0c038956;
case 0x0c038958u: goto P_0c038958;
case 0x0c03895au: goto P_0c03895a;
case 0x0c03895cu: goto P_0c03895c;
case 0x0c03895eu: goto P_0c03895e;
case 0x0c038960u: goto P_0c038960;
case 0x0c038962u: goto P_0c038962;
case 0x0c038964u: goto P_0c038964;
case 0x0c038966u: goto P_0c038966;
case 0x0c038970u: goto P_0c038970;
case 0x0c038972u: goto P_0c038972;
case 0x0c038974u: goto P_0c038974;
case 0x0c038976u: goto P_0c038976;
case 0x0c038978u: goto P_0c038978;
case 0x0c03897au: goto P_0c03897a;
case 0x0c03897cu: goto P_0c03897c;
case 0x0c03897eu: goto P_0c03897e;
case 0x0c038980u: goto P_0c038980;
case 0x0c038982u: goto P_0c038982;
case 0x0c038984u: goto P_0c038984;
case 0x0c038986u: goto P_0c038986;
case 0x0c038988u: goto P_0c038988;
case 0x0c03898au: goto P_0c03898a;
case 0x0c03898cu: goto P_0c03898c;
case 0x0c03f5a0u: goto P_0c03f5a0;
case 0x0c03f5a2u: goto P_0c03f5a2;
case 0x0c03f5a4u: goto P_0c03f5a4;
case 0x0c03f5a6u: goto P_0c03f5a6;
case 0x0c03f5a8u: goto P_0c03f5a8;
case 0x0c03f5aau: goto P_0c03f5aa;
case 0x0c03f5acu: goto P_0c03f5ac;
case 0x0c03f5aeu: goto P_0c03f5ae;
case 0x0c03f5b0u: goto P_0c03f5b0;
case 0x0c03f5b2u: goto P_0c03f5b2;
case 0x0c03f5b4u: goto P_0c03f5b4;
case 0x0c03f5b6u: goto P_0c03f5b6;
case 0x0c03f5b8u: goto P_0c03f5b8;
case 0x0c03f5bau: goto P_0c03f5ba;
case 0x0c03f5bcu: goto P_0c03f5bc;
case 0x0c03f5beu: goto P_0c03f5be;
case 0x0c03f5c0u: goto P_0c03f5c0;
case 0x0c03f5c2u: goto P_0c03f5c2;
case 0x0c03f5d0u: goto P_0c03f5d0;
case 0x0c03f5d2u: goto P_0c03f5d2;
case 0x0c03f5d4u: goto P_0c03f5d4;
case 0x0c03f5d6u: goto P_0c03f5d6;
case 0x0c03f5d8u: goto P_0c03f5d8;
case 0x0c03f5dau: goto P_0c03f5da;
case 0x0c03f5dcu: goto P_0c03f5dc;
case 0x0c03f5deu: goto P_0c03f5de;
case 0x0c03f5e0u: goto P_0c03f5e0;
case 0x0c03f5e2u: goto P_0c03f5e2;
case 0x0c03f5e4u: goto P_0c03f5e4;
case 0x0c03f5e6u: goto P_0c03f5e6;
case 0x0c03f5e8u: goto P_0c03f5e8;
case 0x0c03f5eau: goto P_0c03f5ea;
case 0x0c03f5ecu: goto P_0c03f5ec;
case 0x0c03f5eeu: goto P_0c03f5ee;
case 0x0c03f5f0u: goto P_0c03f5f0;
case 0x0c03f5f2u: goto P_0c03f5f2;
case 0x0c03f5f4u: goto P_0c03f5f4;
case 0x0c03f5f6u: goto P_0c03f5f6;
case 0x0c03f5f8u: goto P_0c03f5f8;
case 0x0c03f5fau: goto P_0c03f5fa;
case 0x0c03f5fcu: goto P_0c03f5fc;
case 0x0c03f5feu: goto P_0c03f5fe;
case 0x0c03f600u: goto P_0c03f600;
case 0x0c03f602u: goto P_0c03f602;
case 0x0c03f604u: goto P_0c03f604;
case 0x0c03f606u: goto P_0c03f606;
case 0x0c03f608u: goto P_0c03f608;
case 0x0c03f60au: goto P_0c03f60a;
case 0x0c03f60cu: goto P_0c03f60c;
case 0x0c03f60eu: goto P_0c03f60e;
case 0x0c03f610u: goto P_0c03f610;
case 0x0c03f612u: goto P_0c03f612;
case 0x0c03f614u: goto P_0c03f614;
case 0x0c03f616u: goto P_0c03f616;
case 0x0c03f618u: goto P_0c03f618;
case 0x0c03f61au: goto P_0c03f61a;
case 0x0c03f61cu: goto P_0c03f61c;
case 0x0c03f61eu: goto P_0c03f61e;
case 0x0c03f620u: goto P_0c03f620;
case 0x0c03f622u: goto P_0c03f622;
case 0x0c03f624u: goto P_0c03f624;
case 0x0c03f626u: goto P_0c03f626;
case 0x0c03f628u: goto P_0c03f628;
case 0x0c03f62au: goto P_0c03f62a;
case 0x0c03f62cu: goto P_0c03f62c;
case 0x0c03f62eu: goto P_0c03f62e;
case 0x0c03f630u: goto P_0c03f630;
case 0x0c03f632u: goto P_0c03f632;
case 0x0c03f634u: goto P_0c03f634;
case 0x0c03f636u: goto P_0c03f636;
case 0x0c03f638u: goto P_0c03f638;
case 0x0c03f63au: goto P_0c03f63a;
case 0x0c03f63cu: goto P_0c03f63c;
case 0x0c03f63eu: goto P_0c03f63e;
case 0x0c03f640u: goto P_0c03f640;
case 0x0c03f642u: goto P_0c03f642;
case 0x0c03f644u: goto P_0c03f644;
case 0x0c03f646u: goto P_0c03f646;
case 0x0c03f648u: goto P_0c03f648;
case 0x0c03f64au: goto P_0c03f64a;
case 0x0c03f64cu: goto P_0c03f64c;
case 0x0c03f64eu: goto P_0c03f64e;
case 0x0c03f650u: goto P_0c03f650;
case 0x0c03f652u: goto P_0c03f652;
case 0x0c03f654u: goto P_0c03f654;
case 0x0c03f656u: goto P_0c03f656;
case 0x0c03f658u: goto P_0c03f658;
case 0x0c03f65au: goto P_0c03f65a;
case 0x0c03f65cu: goto P_0c03f65c;
case 0x0c03f65eu: goto P_0c03f65e;
case 0x0c03f660u: goto P_0c03f660;
case 0x0c03f662u: goto P_0c03f662;
case 0x0c03f664u: goto P_0c03f664;
case 0x0c03f666u: goto P_0c03f666;
case 0x0c03f668u: goto P_0c03f668;
case 0x0c03f66au: goto P_0c03f66a;
case 0x0c03f66cu: goto P_0c03f66c;
case 0x0c03f66eu: goto P_0c03f66e;
case 0x0c03f670u: goto P_0c03f670;
case 0x0c03f672u: goto P_0c03f672;
case 0x0c03f674u: goto P_0c03f674;
case 0x0c03f676u: goto P_0c03f676;
case 0x0c03f678u: goto P_0c03f678;
case 0x0c03f67au: goto P_0c03f67a;
case 0x0c03f67cu: goto P_0c03f67c;
case 0x0c03f67eu: goto P_0c03f67e;
case 0x0c03f680u: goto P_0c03f680;
case 0x0c03f682u: goto P_0c03f682;
case 0x0c03f684u: goto P_0c03f684;
case 0x0c03fcf0u: goto P_0c03fcf0;
case 0x0c03fcf2u: goto P_0c03fcf2;
case 0x0c03fcf4u: goto P_0c03fcf4;
case 0x0c03fcf6u: goto P_0c03fcf6;
case 0x0c03fcf8u: goto P_0c03fcf8;
case 0x0c03fcfau: goto P_0c03fcfa;
case 0x0c03fcfcu: goto P_0c03fcfc;
case 0x0c03fcfeu: goto P_0c03fcfe;
case 0x0c03fd00u: goto P_0c03fd00;
case 0x0c04326cu: goto P_0c04326c;
case 0x0c04326eu: goto P_0c04326e;
case 0x0c043270u: goto P_0c043270;
case 0x0c043272u: goto P_0c043272;
case 0x0c043274u: goto P_0c043274;
case 0x0c043276u: goto P_0c043276;
case 0x0c043278u: goto P_0c043278;
case 0x0c04327au: goto P_0c04327a;
case 0x0c04327cu: goto P_0c04327c;
case 0x0c04327eu: goto P_0c04327e;
case 0x0c043280u: goto P_0c043280;
case 0x0c043282u: goto P_0c043282;
case 0x0c043284u: goto P_0c043284;
case 0x0c0433c6u: goto P_0c0433c6;
case 0x0c0433c8u: goto P_0c0433c8;
case 0x0c0433cau: goto P_0c0433ca;
case 0x0c0433ccu: goto P_0c0433cc;
case 0x0c0433ceu: goto P_0c0433ce;
case 0x0c0433d0u: goto P_0c0433d0;
case 0x0c0433d2u: goto P_0c0433d2;
case 0x0c0433d4u: goto P_0c0433d4;
case 0x0c0433d6u: goto P_0c0433d6;
case 0x0c0433d8u: goto P_0c0433d8;
case 0x0c0433dau: goto P_0c0433da;
case 0x0c0433dcu: goto P_0c0433dc;
case 0x0c0433deu: goto P_0c0433de;
case 0x0c04341eu: goto P_0c04341e;
case 0x0c043420u: goto P_0c043420;
case 0x0c043422u: goto P_0c043422;
case 0x0c043424u: goto P_0c043424;
case 0x0c043426u: goto P_0c043426;
case 0x0c043428u: goto P_0c043428;
case 0x0c04342au: goto P_0c04342a;
case 0x0c04342cu: goto P_0c04342c;
case 0x0c04342eu: goto P_0c04342e;
case 0x0c043430u: goto P_0c043430;
case 0x0c043432u: goto P_0c043432;
case 0x0c043434u: goto P_0c043434;
case 0x0c043436u: goto P_0c043436;
case 0x0c043438u: goto P_0c043438;
case 0x0c04343au: goto P_0c04343a;
case 0x0c043440u: goto P_0c043440;
case 0x0c043442u: goto P_0c043442;
case 0x0c043444u: goto P_0c043444;
case 0x0c043446u: goto P_0c043446;
case 0x0c043448u: goto P_0c043448;
case 0x0c04344au: goto P_0c04344a;
case 0x0c04344cu: goto P_0c04344c;
case 0x0c04344eu: goto P_0c04344e;
case 0x0c043450u: goto P_0c043450;
case 0x0c043452u: goto P_0c043452;
case 0x0c043454u: goto P_0c043454;
case 0x0c043456u: goto P_0c043456;
case 0x0c043458u: goto P_0c043458;
case 0x0c04345au: goto P_0c04345a;
case 0x0c04345cu: goto P_0c04345c;
case 0x0c043472u: goto P_0c043472;
case 0x0c043474u: goto P_0c043474;
case 0x0c043476u: goto P_0c043476;
case 0x0c043478u: goto P_0c043478;
case 0x0c04347au: goto P_0c04347a;
case 0x0c04347cu: goto P_0c04347c;
case 0x0c04347eu: goto P_0c04347e;
case 0x0c043480u: goto P_0c043480;
case 0x0c043482u: goto P_0c043482;
case 0x0c043484u: goto P_0c043484;
case 0x0c043486u: goto P_0c043486;
case 0x0c043488u: goto P_0c043488;
case 0x0c04348au: goto P_0c04348a;
case 0x0c04348eu: goto P_0c04348e;
case 0x0c043490u: goto P_0c043490;
case 0x0c043492u: goto P_0c043492;
case 0x0c043494u: goto P_0c043494;
case 0x0c043496u: goto P_0c043496;
case 0x0c043498u: goto P_0c043498;
case 0x0c04349au: goto P_0c04349a;
case 0x0c04349cu: goto P_0c04349c;
case 0x0c04349eu: goto P_0c04349e;
case 0x0c0434a0u: goto P_0c0434a0;
case 0x0c0434a2u: goto P_0c0434a2;
case 0x0c0434a4u: goto P_0c0434a4;
case 0x0c0434a6u: goto P_0c0434a6;
case 0x0c0434aau: goto P_0c0434aa;
case 0x0c0434acu: goto P_0c0434ac;
case 0x0c0434aeu: goto P_0c0434ae;
case 0x0c0434b0u: goto P_0c0434b0;
case 0x0c0434b2u: goto P_0c0434b2;
case 0x0c0434b4u: goto P_0c0434b4;
case 0x0c0434b6u: goto P_0c0434b6;
case 0x0c0434b8u: goto P_0c0434b8;
case 0x0c0434bau: goto P_0c0434ba;
case 0x0c0434bcu: goto P_0c0434bc;
case 0x0c0434beu: goto P_0c0434be;
case 0x0c0434c0u: goto P_0c0434c0;
case 0x0c0434c2u: goto P_0c0434c2;
case 0x0c0434c4u: goto P_0c0434c4;
case 0x0c0434c6u: goto P_0c0434c6;
case 0x0c04bbf2u: goto P_0c04bbf2;
case 0x0c04bbf4u: goto P_0c04bbf4;
case 0x0c04bbf6u: goto P_0c04bbf6;
case 0x0c04bbf8u: goto P_0c04bbf8;
case 0x0c04bbfau: goto P_0c04bbfa;
case 0x0c04bbfcu: goto P_0c04bbfc;
case 0x0c04bbfeu: goto P_0c04bbfe;
case 0x0c04bc00u: goto P_0c04bc00;
case 0x0c04bc02u: goto P_0c04bc02;
case 0x0c04bc04u: goto P_0c04bc04;
case 0x0c04bc06u: goto P_0c04bc06;
case 0x0c04bc08u: goto P_0c04bc08;
case 0x0c04bc0au: goto P_0c04bc0a;
case 0x0c04bc0cu: goto P_0c04bc0c;
case 0x0c04bc0eu: goto P_0c04bc0e;
case 0x0c04bc10u: goto P_0c04bc10;
case 0x0c04bc12u: goto P_0c04bc12;
case 0x0c04bc14u: goto P_0c04bc14;
case 0x0c04bc16u: goto P_0c04bc16;
case 0x0c04bc18u: goto P_0c04bc18;
case 0x0c04bc1au: goto P_0c04bc1a;
case 0x0c04bc1cu: goto P_0c04bc1c;
case 0x0c04bc1eu: goto P_0c04bc1e;
case 0x0c04bc20u: goto P_0c04bc20;
case 0x0c04bc22u: goto P_0c04bc22;
case 0x0c04bc24u: goto P_0c04bc24;
case 0x0c04bc26u: goto P_0c04bc26;
case 0x0c04bc28u: goto P_0c04bc28;
case 0x0c04bc2au: goto P_0c04bc2a;
case 0x0c04bc2cu: goto P_0c04bc2c;
case 0x0c04bc2eu: goto P_0c04bc2e;
case 0x0c04bc30u: goto P_0c04bc30;
case 0x0c04bc32u: goto P_0c04bc32;
case 0x0c04bc34u: goto P_0c04bc34;
case 0x0c04bc36u: goto P_0c04bc36;
case 0x0c04bc38u: goto P_0c04bc38;
case 0x0c04bc3au: goto P_0c04bc3a;
case 0x0c04bc3cu: goto P_0c04bc3c;
case 0x0c04bc3eu: goto P_0c04bc3e;
case 0x0c04bc40u: goto P_0c04bc40;
case 0x0c04bc42u: goto P_0c04bc42;
case 0x0c04bc44u: goto P_0c04bc44;
case 0x0c04bc46u: goto P_0c04bc46;
case 0x0c04bc48u: goto P_0c04bc48;
case 0x0c04bc4au: goto P_0c04bc4a;
case 0x0c04bc4cu: goto P_0c04bc4c;
case 0x0c04bc4eu: goto P_0c04bc4e;
case 0x0c04bc50u: goto P_0c04bc50;
case 0x0c04f8beu: goto P_0c04f8be;
case 0x0c04f8c0u: goto P_0c04f8c0;
case 0x0c04f8c2u: goto P_0c04f8c2;
case 0x0c04f8c4u: goto P_0c04f8c4;
case 0x0c04f8c6u: goto P_0c04f8c6;
case 0x0c04f8c8u: goto P_0c04f8c8;
case 0x0c04f8cau: goto P_0c04f8ca;
case 0x0c04f8ccu: goto P_0c04f8cc;
case 0x0c04f8ceu: goto P_0c04f8ce;
case 0x0c04f8d0u: goto P_0c04f8d0;
case 0x0c04f8d2u: goto P_0c04f8d2;
case 0x0c04f8d4u: goto P_0c04f8d4;
case 0x0c04f8d6u: goto P_0c04f8d6;
case 0x0c04f8d8u: goto P_0c04f8d8;
case 0x0c04f8dau: goto P_0c04f8da;
case 0x0c04f8dcu: goto P_0c04f8dc;
case 0x0c04f8deu: goto P_0c04f8de;
case 0x0c04f8e0u: goto P_0c04f8e0;
case 0x0c04f8e2u: goto P_0c04f8e2;
case 0x0c04f8e4u: goto P_0c04f8e4;
case 0x0c04f8e6u: goto P_0c04f8e6;
case 0x0c04f8e8u: goto P_0c04f8e8;
case 0x0c04f8eau: goto P_0c04f8ea;
case 0x0c04f8ecu: goto P_0c04f8ec;
case 0x0c04f8eeu: goto P_0c04f8ee;
case 0x0c04f8f0u: goto P_0c04f8f0;
case 0x0c04f8f2u: goto P_0c04f8f2;
case 0x0c04f8f4u: goto P_0c04f8f4;
case 0x0c04f8f6u: goto P_0c04f8f6;
case 0x0c04f8f8u: goto P_0c04f8f8;
case 0x0c04f8fau: goto P_0c04f8fa;
case 0x0c04f8fcu: goto P_0c04f8fc;
case 0x0c04f8feu: goto P_0c04f8fe;
case 0x0c04f900u: goto P_0c04f900;
case 0x0c04f902u: goto P_0c04f902;
case 0x0c04f904u: goto P_0c04f904;
case 0x0c05fc14u: goto P_0c05fc14;
case 0x0c05fc16u: goto P_0c05fc16;
case 0x0c05fc18u: goto P_0c05fc18;
case 0x0c05fc1au: goto P_0c05fc1a;
case 0x0c05fc1cu: goto P_0c05fc1c;
case 0x0c05fc1eu: goto P_0c05fc1e;
case 0x0c05fc20u: goto P_0c05fc20;
case 0x0c05fc22u: goto P_0c05fc22;
case 0x0c05fc24u: goto P_0c05fc24;
case 0x0c05fc26u: goto P_0c05fc26;
case 0x0c05fc28u: goto P_0c05fc28;
case 0x0c05fc2au: goto P_0c05fc2a;
case 0x0c05fc2cu: goto P_0c05fc2c;
case 0x0c05fc2eu: goto P_0c05fc2e;
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
case 0x0c0636feu: goto P_0c0636fe;
case 0x0c063700u: goto P_0c063700;
case 0x0c0696e6u: goto P_0c0696e6;
case 0x0c0696e8u: goto P_0c0696e8;
case 0x0c0696eau: goto P_0c0696ea;
case 0x0c0696ecu: goto P_0c0696ec;
case 0x0c0696eeu: goto P_0c0696ee;
case 0x0c0696f0u: goto P_0c0696f0;
case 0x0c0696f2u: goto P_0c0696f2;
case 0x0c0696f4u: goto P_0c0696f4;
case 0x0c0696f6u: goto P_0c0696f6;
case 0x0c0696f8u: goto P_0c0696f8;
case 0x0c0696fau: goto P_0c0696fa;
case 0x0c0696fcu: goto P_0c0696fc;
case 0x0c0696feu: goto P_0c0696fe;
case 0x0c06a348u: goto P_0c06a348;
case 0x0c06a34au: goto P_0c06a34a;
case 0x0c06a34cu: goto P_0c06a34c;
case 0x0c06a34eu: goto P_0c06a34e;
case 0x0c06a350u: goto P_0c06a350;
case 0x0c06a352u: goto P_0c06a352;
case 0x0c06a354u: goto P_0c06a354;
case 0x0c06a356u: goto P_0c06a356;
case 0x0c06a358u: goto P_0c06a358;
case 0x0c06a35au: goto P_0c06a35a;
case 0x0c06a35cu: goto P_0c06a35c;
case 0x0c06a35eu: goto P_0c06a35e;
case 0x0c06a360u: goto P_0c06a360;
case 0x0c06a362u: goto P_0c06a362;
case 0x0c06a364u: goto P_0c06a364;
case 0x0c06a366u: goto P_0c06a366;
case 0x0c06a368u: goto P_0c06a368;
case 0x0c06a36au: goto P_0c06a36a;
case 0x0c06a36cu: goto P_0c06a36c;
case 0x0c06a36eu: goto P_0c06a36e;
case 0x0c06a370u: goto P_0c06a370;
case 0x0c06a372u: goto P_0c06a372;
case 0x0c06a374u: goto P_0c06a374;
case 0x0c06a376u: goto P_0c06a376;
case 0x0c06a378u: goto P_0c06a378;
case 0x0c06a37au: goto P_0c06a37a;
case 0x0c06a37cu: goto P_0c06a37c;
case 0x0c06a37eu: goto P_0c06a37e;
case 0x0c06a380u: goto P_0c06a380;
case 0x0c06a382u: goto P_0c06a382;
case 0x0c06a384u: goto P_0c06a384;
case 0x0c06a386u: goto P_0c06a386;
case 0x0c06a388u: goto P_0c06a388;
case 0x0c06a38au: goto P_0c06a38a;
case 0x0c06a38cu: goto P_0c06a38c;
case 0x0c06a38eu: goto P_0c06a38e;
case 0x0c06a390u: goto P_0c06a390;
case 0x0c06a392u: goto P_0c06a392;
case 0x0c06a394u: goto P_0c06a394;
case 0x0c06a396u: goto P_0c06a396;
case 0x0c06a398u: goto P_0c06a398;
case 0x0c06a39au: goto P_0c06a39a;
case 0x0c06a39cu: goto P_0c06a39c;
case 0x0c06a39eu: goto P_0c06a39e;
case 0x0c06a3a0u: goto P_0c06a3a0;
case 0x0c06a3a2u: goto P_0c06a3a2;
case 0x0c06a3a4u: goto P_0c06a3a4;
case 0x0c06a3a6u: goto P_0c06a3a6;
case 0x0c06a3a8u: goto P_0c06a3a8;
case 0x0c06a3aau: goto P_0c06a3aa;
case 0x0c06a3acu: goto P_0c06a3ac;
case 0x0c06a3aeu: goto P_0c06a3ae;
case 0x0c06a3b0u: goto P_0c06a3b0;
case 0x0c06a3b2u: goto P_0c06a3b2;
case 0x0c06a3b4u: goto P_0c06a3b4;
case 0x0c06a3b6u: goto P_0c06a3b6;
case 0x0c06a3b8u: goto P_0c06a3b8;
case 0x0c06a3bau: goto P_0c06a3ba;
case 0x0c06a3bcu: goto P_0c06a3bc;
case 0x0c06a3beu: goto P_0c06a3be;
case 0x0c06a3c0u: goto P_0c06a3c0;
case 0x0c06a3c2u: goto P_0c06a3c2;
case 0x0c06a3c4u: goto P_0c06a3c4;
case 0x0c06a3c6u: goto P_0c06a3c6;
case 0x0c06a3c8u: goto P_0c06a3c8;
case 0x0c06a3cau: goto P_0c06a3ca;
case 0x0c06a3ccu: goto P_0c06a3cc;
case 0x0c06a3ceu: goto P_0c06a3ce;
case 0x0c06a3d0u: goto P_0c06a3d0;
case 0x0c06a3d2u: goto P_0c06a3d2;
case 0x0c06a3d4u: goto P_0c06a3d4;
case 0x0c06a3d6u: goto P_0c06a3d6;
case 0x0c06a3d8u: goto P_0c06a3d8;
case 0x0c06a3dau: goto P_0c06a3da;
case 0x0c06a3dcu: goto P_0c06a3dc;
case 0x0c06a3deu: goto P_0c06a3de;
case 0x0c06a3e0u: goto P_0c06a3e0;
case 0x0c06a3e2u: goto P_0c06a3e2;
case 0x0c06a3e4u: goto P_0c06a3e4;
case 0x0c06a3e6u: goto P_0c06a3e6;
case 0x0c06a3e8u: goto P_0c06a3e8;
case 0x0c06a3eau: goto P_0c06a3ea;
case 0x0c06a3ecu: goto P_0c06a3ec;
case 0x0c06a3eeu: goto P_0c06a3ee;
case 0x0c06a3f0u: goto P_0c06a3f0;
case 0x0c06a3f2u: goto P_0c06a3f2;
case 0x0c06a3f4u: goto P_0c06a3f4;
case 0x0c06a3f6u: goto P_0c06a3f6;
case 0x0c06a3f8u: goto P_0c06a3f8;
case 0x0c06a3fau: goto P_0c06a3fa;
case 0x0c06a3fcu: goto P_0c06a3fc;
case 0x0c06a3feu: goto P_0c06a3fe;
case 0x0c06a400u: goto P_0c06a400;
case 0x0c06a402u: goto P_0c06a402;
case 0x0c06a404u: goto P_0c06a404;
case 0x0c06a406u: goto P_0c06a406;
case 0x0c06a408u: goto P_0c06a408;
case 0x0c06a40au: goto P_0c06a40a;
case 0x0c06a40cu: goto P_0c06a40c;
case 0x0c06a40eu: goto P_0c06a40e;
case 0x0c06a410u: goto P_0c06a410;
case 0x0c06a412u: goto P_0c06a412;
case 0x0c06a414u: goto P_0c06a414;
case 0x0c06a416u: goto P_0c06a416;
case 0x0c06a418u: goto P_0c06a418;
case 0x0c06a41au: goto P_0c06a41a;
case 0x0c06a41cu: goto P_0c06a41c;
case 0x0c06a41eu: goto P_0c06a41e;
case 0x0c06a420u: goto P_0c06a420;
case 0x0c06a422u: goto P_0c06a422;
case 0x0c06a424u: goto P_0c06a424;
case 0x0c06a426u: goto P_0c06a426;
case 0x0c06a428u: goto P_0c06a428;
case 0x0c06a42au: goto P_0c06a42a;
case 0x0c06a42cu: goto P_0c06a42c;
case 0x0c06a42eu: goto P_0c06a42e;
case 0x0c06a430u: goto P_0c06a430;
case 0x0c06a432u: goto P_0c06a432;
case 0x0c06a434u: goto P_0c06a434;
case 0x0c06a436u: goto P_0c06a436;
case 0x0c06a438u: goto P_0c06a438;
case 0x0c06a43au: goto P_0c06a43a;
case 0x0c06a43cu: goto P_0c06a43c;
case 0x0c06a43eu: goto P_0c06a43e;
case 0x0c06a440u: goto P_0c06a440;
case 0x0c06a442u: goto P_0c06a442;
case 0x0c06a444u: goto P_0c06a444;
case 0x0c06a446u: goto P_0c06a446;
case 0x0c06a448u: goto P_0c06a448;
case 0x0c06a44au: goto P_0c06a44a;
case 0x0c06a44cu: goto P_0c06a44c;
case 0x0c06a44eu: goto P_0c06a44e;
case 0x0c06a450u: goto P_0c06a450;
case 0x0c06a480u: goto P_0c06a480;
case 0x0c06a482u: goto P_0c06a482;
case 0x0c06a484u: goto P_0c06a484;
case 0x0c06a486u: goto P_0c06a486;
case 0x0c06a488u: goto P_0c06a488;
case 0x0c06a48au: goto P_0c06a48a;
case 0x0c06a48cu: goto P_0c06a48c;
case 0x0c06a48eu: goto P_0c06a48e;
case 0x0c06a490u: goto P_0c06a490;
case 0x0c06a492u: goto P_0c06a492;
case 0x0c06a494u: goto P_0c06a494;
case 0x0c06a496u: goto P_0c06a496;
case 0x0c06a498u: goto P_0c06a498;
case 0x0c06a49au: goto P_0c06a49a;
case 0x0c06a49cu: goto P_0c06a49c;
case 0x0c06a49eu: goto P_0c06a49e;
case 0x0c06a4a0u: goto P_0c06a4a0;
case 0x0c06a4a2u: goto P_0c06a4a2;
case 0x0c06a4a4u: goto P_0c06a4a4;
case 0x0c06a4a6u: goto P_0c06a4a6;
case 0x0c06a4a8u: goto P_0c06a4a8;
case 0x0c06a4aau: goto P_0c06a4aa;
case 0x0c06a4acu: goto P_0c06a4ac;
case 0x0c06a4aeu: goto P_0c06a4ae;
case 0x0c06a4b0u: goto P_0c06a4b0;
case 0x0c06a4b2u: goto P_0c06a4b2;
case 0x0c06a4b4u: goto P_0c06a4b4;
case 0x0c06a4b6u: goto P_0c06a4b6;
case 0x0c06a4b8u: goto P_0c06a4b8;
case 0x0c06a4bau: goto P_0c06a4ba;
case 0x0c06a4bcu: goto P_0c06a4bc;
case 0x0c06a4beu: goto P_0c06a4be;
case 0x0c06a4c0u: goto P_0c06a4c0;
case 0x0c06a4c2u: goto P_0c06a4c2;
case 0x0c06a4c4u: goto P_0c06a4c4;
case 0x0c06a4c6u: goto P_0c06a4c6;
case 0x0c06a4c8u: goto P_0c06a4c8;
case 0x0c06a4cau: goto P_0c06a4ca;
case 0x0c06a4ccu: goto P_0c06a4cc;
case 0x0c06a4ceu: goto P_0c06a4ce;
case 0x0c06a4d0u: goto P_0c06a4d0;
case 0x0c06a4d2u: goto P_0c06a4d2;
case 0x0c06a4d4u: goto P_0c06a4d4;
case 0x0c06a4d6u: goto P_0c06a4d6;
case 0x0c06a4d8u: goto P_0c06a4d8;
case 0x0c06a4dau: goto P_0c06a4da;
case 0x0c06a4dcu: goto P_0c06a4dc;
case 0x0c06a4deu: goto P_0c06a4de;
case 0x0c06a4e0u: goto P_0c06a4e0;
case 0x0c06a4e2u: goto P_0c06a4e2;
case 0x0c06a4e4u: goto P_0c06a4e4;
case 0x0c06a4e6u: goto P_0c06a4e6;
case 0x0c06a4e8u: goto P_0c06a4e8;
case 0x0c06a4eau: goto P_0c06a4ea;
case 0x0c06a4ecu: goto P_0c06a4ec;
case 0x0c06a4eeu: goto P_0c06a4ee;
case 0x0c06a4f0u: goto P_0c06a4f0;
case 0x0c06a4f2u: goto P_0c06a4f2;
case 0x0c06a4f4u: goto P_0c06a4f4;
case 0x0c06a4f6u: goto P_0c06a4f6;
case 0x0c06a4f8u: goto P_0c06a4f8;
case 0x0c06a4fau: goto P_0c06a4fa;
case 0x0c06a4fcu: goto P_0c06a4fc;
case 0x0c06a4feu: goto P_0c06a4fe;
case 0x0c06a500u: goto P_0c06a500;
case 0x0c06a502u: goto P_0c06a502;
case 0x0c06a504u: goto P_0c06a504;
case 0x0c06a506u: goto P_0c06a506;
case 0x0c06a508u: goto P_0c06a508;
case 0x0c06a50au: goto P_0c06a50a;
case 0x0c06a50cu: goto P_0c06a50c;
case 0x0c06a50eu: goto P_0c06a50e;
case 0x0c06a510u: goto P_0c06a510;
case 0x0c06a512u: goto P_0c06a512;
case 0x0c06a514u: goto P_0c06a514;
case 0x0c06a516u: goto P_0c06a516;
case 0x0c06a518u: goto P_0c06a518;
case 0x0c06a51au: goto P_0c06a51a;
case 0x0c06a51cu: goto P_0c06a51c;
case 0x0c06a51eu: goto P_0c06a51e;
case 0x0c06a520u: goto P_0c06a520;
case 0x0c06a522u: goto P_0c06a522;
case 0x0c06a524u: goto P_0c06a524;
case 0x0c06a526u: goto P_0c06a526;
case 0x0c06a528u: goto P_0c06a528;
case 0x0c06a52au: goto P_0c06a52a;
case 0x0c06a52cu: goto P_0c06a52c;
case 0x0c06a52eu: goto P_0c06a52e;
case 0x0c06a530u: goto P_0c06a530;
case 0x0c06a532u: goto P_0c06a532;
case 0x0c06a534u: goto P_0c06a534;
case 0x0c06a536u: goto P_0c06a536;
case 0x0c06a538u: goto P_0c06a538;
case 0x0c06a53au: goto P_0c06a53a;
case 0x0c06a53cu: goto P_0c06a53c;
case 0x0c06a53eu: goto P_0c06a53e;
case 0x0c06a540u: goto P_0c06a540;
case 0x0c06a542u: goto P_0c06a542;
case 0x0c06a544u: goto P_0c06a544;
case 0x0c06a546u: goto P_0c06a546;
case 0x0c06a548u: goto P_0c06a548;
case 0x0c06a54au: goto P_0c06a54a;
case 0x0c06a54cu: goto P_0c06a54c;
case 0x0c06a54eu: goto P_0c06a54e;
case 0x0c06a550u: goto P_0c06a550;
case 0x0c06a552u: goto P_0c06a552;
case 0x0c06a554u: goto P_0c06a554;
case 0x0c06a556u: goto P_0c06a556;
case 0x0c06a558u: goto P_0c06a558;
case 0x0c06a55au: goto P_0c06a55a;
case 0x0c06a55cu: goto P_0c06a55c;
case 0x0c06a55eu: goto P_0c06a55e;
case 0x0c06a560u: goto P_0c06a560;
case 0x0c06a562u: goto P_0c06a562;
case 0x0c06a564u: goto P_0c06a564;
case 0x0c06a566u: goto P_0c06a566;
case 0x0c06a568u: goto P_0c06a568;
case 0x0c06a56au: goto P_0c06a56a;
case 0x0c06a56cu: goto P_0c06a56c;
case 0x0c06a56eu: goto P_0c06a56e;
case 0x0c06a570u: goto P_0c06a570;
case 0x0c06a572u: goto P_0c06a572;
case 0x0c06a574u: goto P_0c06a574;
case 0x0c06a576u: goto P_0c06a576;
case 0x0c06a578u: goto P_0c06a578;
case 0x0c06a57au: goto P_0c06a57a;
case 0x0c06a57cu: goto P_0c06a57c;
case 0x0c06a57eu: goto P_0c06a57e;
case 0x0c06a580u: goto P_0c06a580;
case 0x0c06a582u: goto P_0c06a582;
case 0x0c06a584u: goto P_0c06a584;
case 0x0c06a586u: goto P_0c06a586;
case 0x0c06a588u: goto P_0c06a588;
case 0x0c06a58au: goto P_0c06a58a;
case 0x0c06a58cu: goto P_0c06a58c;
case 0x0c06a58eu: goto P_0c06a58e;
case 0x0c06a590u: goto P_0c06a590;
case 0x0c06a592u: goto P_0c06a592;
case 0x0c06a594u: goto P_0c06a594;
case 0x0c06a596u: goto P_0c06a596;
case 0x0c06a598u: goto P_0c06a598;
case 0x0c06a59au: goto P_0c06a59a;
case 0x0c06a59cu: goto P_0c06a59c;
case 0x0c06a59eu: goto P_0c06a59e;
case 0x0c06a5a0u: goto P_0c06a5a0;
case 0x0c06a5a2u: goto P_0c06a5a2;
case 0x0c06a5a4u: goto P_0c06a5a4;
case 0x0c06a5a6u: goto P_0c06a5a6;
case 0x0c06a5a8u: goto P_0c06a5a8;
case 0x0c06a5aau: goto P_0c06a5aa;
case 0x0c06a5acu: goto P_0c06a5ac;
case 0x0c06a5aeu: goto P_0c06a5ae;
case 0x0c06a5b0u: goto P_0c06a5b0;
case 0x0c06a5b2u: goto P_0c06a5b2;
case 0x0c06a5b4u: goto P_0c06a5b4;
case 0x0c06a5b6u: goto P_0c06a5b6;
case 0x0c06a5b8u: goto P_0c06a5b8;
case 0x0c06a5bau: goto P_0c06a5ba;
case 0x0c06a5bcu: goto P_0c06a5bc;
case 0x0c06a5beu: goto P_0c06a5be;
case 0x0c06a5c0u: goto P_0c06a5c0;
case 0x0c06a5c2u: goto P_0c06a5c2;
case 0x0c06ada0u: goto P_0c06ada0;
case 0x0c06ada2u: goto P_0c06ada2;
case 0x0c06ada4u: goto P_0c06ada4;
case 0x0c06ada6u: goto P_0c06ada6;
case 0x0c06ada8u: goto P_0c06ada8;
case 0x0c06adaau: goto P_0c06adaa;
case 0x0c06adacu: goto P_0c06adac;
case 0x0c06adaeu: goto P_0c06adae;
case 0x0c06adb0u: goto P_0c06adb0;
case 0x0c06adb2u: goto P_0c06adb2;
case 0x0c06adb4u: goto P_0c06adb4;
case 0x0c06adb6u: goto P_0c06adb6;
case 0x0c06adb8u: goto P_0c06adb8;
case 0x0c06adbau: goto P_0c06adba;
case 0x0c06adbcu: goto P_0c06adbc;
case 0x0c06adbeu: goto P_0c06adbe;
case 0x0c06adc0u: goto P_0c06adc0;
case 0x0c06adc2u: goto P_0c06adc2;
case 0x0c06adc4u: goto P_0c06adc4;
case 0x0c06adc6u: goto P_0c06adc6;
case 0x0c06adc8u: goto P_0c06adc8;
case 0x0c06adcau: goto P_0c06adca;
case 0x0c06adccu: goto P_0c06adcc;
case 0x0c06adf4u: goto P_0c06adf4;
case 0x0c06adf6u: goto P_0c06adf6;
case 0x0c06adf8u: goto P_0c06adf8;
case 0x0c06adfau: goto P_0c06adfa;
case 0x0c06adfcu: goto P_0c06adfc;
case 0x0c06adfeu: goto P_0c06adfe;
case 0x0c06ae00u: goto P_0c06ae00;
case 0x0c06ae02u: goto P_0c06ae02;
case 0x0c06ae04u: goto P_0c06ae04;
case 0x0c06ae06u: goto P_0c06ae06;
case 0x0c06ae08u: goto P_0c06ae08;
case 0x0c06ae0au: goto P_0c06ae0a;
case 0x0c06ae0cu: goto P_0c06ae0c;
case 0x0c06ae0eu: goto P_0c06ae0e;
case 0x0c06ae10u: goto P_0c06ae10;
case 0x0c06ae12u: goto P_0c06ae12;
case 0x0c06ae14u: goto P_0c06ae14;
case 0x0c06ae16u: goto P_0c06ae16;
case 0x0c06ae18u: goto P_0c06ae18;
case 0x0c06ae1au: goto P_0c06ae1a;
case 0x0c06ae1cu: goto P_0c06ae1c;
case 0x0c06ae1eu: goto P_0c06ae1e;
case 0x0c06ae20u: goto P_0c06ae20;
case 0x0c06ae22u: goto P_0c06ae22;
case 0x0c06ae24u: goto P_0c06ae24;
case 0x0c06ae26u: goto P_0c06ae26;
case 0x0c06ae28u: goto P_0c06ae28;
case 0x0c06ae2au: goto P_0c06ae2a;
case 0x0c06ae2cu: goto P_0c06ae2c;
case 0x0c06ae2eu: goto P_0c06ae2e;
case 0x0c06ae30u: goto P_0c06ae30;
case 0x0c06ae32u: goto P_0c06ae32;
case 0x0c06ae34u: goto P_0c06ae34;
case 0x0c06ae36u: goto P_0c06ae36;
case 0x0c06ae38u: goto P_0c06ae38;
case 0x0c06ae3au: goto P_0c06ae3a;
case 0x0c06ae3cu: goto P_0c06ae3c;
case 0x0c06ae3eu: goto P_0c06ae3e;
case 0x0c06ae40u: goto P_0c06ae40;
case 0x0c06ae42u: goto P_0c06ae42;
case 0x0c06ae44u: goto P_0c06ae44;
case 0x0c06ae46u: goto P_0c06ae46;
case 0x0c06ae48u: goto P_0c06ae48;
case 0x0c06ae4au: goto P_0c06ae4a;
case 0x0c06ae4cu: goto P_0c06ae4c;
case 0x0c06ae4eu: goto P_0c06ae4e;
case 0x0c06ae50u: goto P_0c06ae50;
case 0x0c06ae52u: goto P_0c06ae52;
case 0x0c06ae54u: goto P_0c06ae54;
case 0x0c06ae56u: goto P_0c06ae56;
case 0x0c06ae58u: goto P_0c06ae58;
case 0x0c06ae5au: goto P_0c06ae5a;
case 0x0c06ae5cu: goto P_0c06ae5c;
case 0x0c06ae5eu: goto P_0c06ae5e;
case 0x0c06ae60u: goto P_0c06ae60;
case 0x0c06ae62u: goto P_0c06ae62;
case 0x0c06ae64u: goto P_0c06ae64;
case 0x0c06ae66u: goto P_0c06ae66;
case 0x0c06ae68u: goto P_0c06ae68;
case 0x0c06ae6au: goto P_0c06ae6a;
case 0x0c06ae6cu: goto P_0c06ae6c;
case 0x0c06ae6eu: goto P_0c06ae6e;
case 0x0c06ae70u: goto P_0c06ae70;
case 0x0c06ae72u: goto P_0c06ae72;
case 0x0c06ae74u: goto P_0c06ae74;
case 0x0c06ae76u: goto P_0c06ae76;
case 0x0c06ae78u: goto P_0c06ae78;
case 0x0c06ae7au: goto P_0c06ae7a;
case 0x0c06ae7cu: goto P_0c06ae7c;
case 0x0c06ae7eu: goto P_0c06ae7e;
case 0x0c06ae80u: goto P_0c06ae80;
case 0x0c06ae82u: goto P_0c06ae82;
case 0x0c06ae84u: goto P_0c06ae84;
case 0x0c06ae86u: goto P_0c06ae86;
case 0x0c06ae88u: goto P_0c06ae88;
case 0x0c06ae8au: goto P_0c06ae8a;
case 0x0c06ae8cu: goto P_0c06ae8c;
case 0x0c06ae8eu: goto P_0c06ae8e;
case 0x0c06ae90u: goto P_0c06ae90;
case 0x0c06ae92u: goto P_0c06ae92;
case 0x0c06ae94u: goto P_0c06ae94;
case 0x0c06ae96u: goto P_0c06ae96;
case 0x0c06ae98u: goto P_0c06ae98;
case 0x0c06ae9au: goto P_0c06ae9a;
case 0x0c06ae9cu: goto P_0c06ae9c;
case 0x0c06ae9eu: goto P_0c06ae9e;
case 0x0c06aea0u: goto P_0c06aea0;
case 0x0c06aea2u: goto P_0c06aea2;
case 0x0c06aea4u: goto P_0c06aea4;
case 0x0c06aea6u: goto P_0c06aea6;
case 0x0c06aea8u: goto P_0c06aea8;
case 0x0c06aeaau: goto P_0c06aeaa;
case 0x0c06aeacu: goto P_0c06aeac;
case 0x0c06aeaeu: goto P_0c06aeae;
case 0x0c06aeb0u: goto P_0c06aeb0;
case 0x0c06aeb2u: goto P_0c06aeb2;
case 0x0c06aeb4u: goto P_0c06aeb4;
case 0x0c06aeb6u: goto P_0c06aeb6;
case 0x0c06aeb8u: goto P_0c06aeb8;
case 0x0c06aebau: goto P_0c06aeba;
case 0x0c06aebcu: goto P_0c06aebc;
case 0x0c06aebeu: goto P_0c06aebe;
case 0x0c06aec0u: goto P_0c06aec0;
case 0x0c06aec2u: goto P_0c06aec2;
case 0x0c06aec4u: goto P_0c06aec4;
case 0x0c06aec6u: goto P_0c06aec6;
case 0x0c06aec8u: goto P_0c06aec8;
case 0x0c06aecau: goto P_0c06aeca;
case 0x0c06aeccu: goto P_0c06aecc;
case 0x0c06aeceu: goto P_0c06aece;
case 0x0c06aed0u: goto P_0c06aed0;
case 0x0c06aed2u: goto P_0c06aed2;
case 0x0c06aed4u: goto P_0c06aed4;
case 0x0c06aed6u: goto P_0c06aed6;
case 0x0c06aed8u: goto P_0c06aed8;
case 0x0c06aedau: goto P_0c06aeda;
case 0x0c06aedcu: goto P_0c06aedc;
case 0x0c06aefcu: goto P_0c06aefc;
case 0x0c06aefeu: goto P_0c06aefe;
case 0x0c06af00u: goto P_0c06af00;
case 0x0c06af02u: goto P_0c06af02;
case 0x0c06af04u: goto P_0c06af04;
case 0x0c06af06u: goto P_0c06af06;
case 0x0c06af08u: goto P_0c06af08;
case 0x0c06af0au: goto P_0c06af0a;
case 0x0c06af0cu: goto P_0c06af0c;
case 0x0c06af0eu: goto P_0c06af0e;
case 0x0c06af10u: goto P_0c06af10;
case 0x0c06af12u: goto P_0c06af12;
case 0x0c06af14u: goto P_0c06af14;
case 0x0c06af16u: goto P_0c06af16;
case 0x0c06af18u: goto P_0c06af18;
case 0x0c06af1au: goto P_0c06af1a;
case 0x0c06af1cu: goto P_0c06af1c;
case 0x0c06af1eu: goto P_0c06af1e;
case 0x0c06af20u: goto P_0c06af20;
case 0x0c06af22u: goto P_0c06af22;
case 0x0c06af24u: goto P_0c06af24;
case 0x0c06af26u: goto P_0c06af26;
case 0x0c06af28u: goto P_0c06af28;
case 0x0c06af2au: goto P_0c06af2a;
case 0x0c06af2cu: goto P_0c06af2c;
case 0x0c06af2eu: goto P_0c06af2e;
case 0x0c06af30u: goto P_0c06af30;
case 0x0c06af32u: goto P_0c06af32;
case 0x0c06af34u: goto P_0c06af34;
case 0x0c06af36u: goto P_0c06af36;
case 0x0c06af38u: goto P_0c06af38;
case 0x0c06af3au: goto P_0c06af3a;
case 0x0c06af3cu: goto P_0c06af3c;
case 0x0c06af3eu: goto P_0c06af3e;
case 0x0c06af40u: goto P_0c06af40;
case 0x0c06af42u: goto P_0c06af42;
case 0x0c06af44u: goto P_0c06af44;
case 0x0c06af46u: goto P_0c06af46;
case 0x0c06af48u: goto P_0c06af48;
case 0x0c06af4au: goto P_0c06af4a;
case 0x0c06af4cu: goto P_0c06af4c;
case 0x0c06af4eu: goto P_0c06af4e;
case 0x0c06af50u: goto P_0c06af50;
case 0x0c06af52u: goto P_0c06af52;
case 0x0c06af54u: goto P_0c06af54;
case 0x0c06af56u: goto P_0c06af56;
case 0x0c06af58u: goto P_0c06af58;
case 0x0c06af5au: goto P_0c06af5a;
case 0x0c06af5cu: goto P_0c06af5c;
case 0x0c06af5eu: goto P_0c06af5e;
case 0x0c06af60u: goto P_0c06af60;
case 0x0c06af62u: goto P_0c06af62;
case 0x0c06af64u: goto P_0c06af64;
case 0x0c06af66u: goto P_0c06af66;
case 0x0c06af68u: goto P_0c06af68;
case 0x0c06af6au: goto P_0c06af6a;
case 0x0c06af6cu: goto P_0c06af6c;
case 0x0c06af6eu: goto P_0c06af6e;
case 0x0c06af70u: goto P_0c06af70;
case 0x0c06af72u: goto P_0c06af72;
case 0x0c06af74u: goto P_0c06af74;
case 0x0c06af76u: goto P_0c06af76;
case 0x0c06af78u: goto P_0c06af78;
case 0x0c06af7au: goto P_0c06af7a;
case 0x0c06af7cu: goto P_0c06af7c;
case 0x0c06af7eu: goto P_0c06af7e;
case 0x0c06af80u: goto P_0c06af80;
case 0x0c06af82u: goto P_0c06af82;
case 0x0c06af84u: goto P_0c06af84;
case 0x0c06af86u: goto P_0c06af86;
case 0x0c06af88u: goto P_0c06af88;
case 0x0c06af8au: goto P_0c06af8a;
case 0x0c06af8cu: goto P_0c06af8c;
case 0x0c06af8eu: goto P_0c06af8e;
case 0x0c06af90u: goto P_0c06af90;
case 0x0c06af92u: goto P_0c06af92;
case 0x0c06af94u: goto P_0c06af94;
case 0x0c06af96u: goto P_0c06af96;
case 0x0c06af98u: goto P_0c06af98;
case 0x0c06af9au: goto P_0c06af9a;
case 0x0c06af9cu: goto P_0c06af9c;
case 0x0c06af9eu: goto P_0c06af9e;
case 0x0c06afa0u: goto P_0c06afa0;
case 0x0c06afa2u: goto P_0c06afa2;
case 0x0c06afa4u: goto P_0c06afa4;
case 0x0c06afa6u: goto P_0c06afa6;
case 0x0c06afa8u: goto P_0c06afa8;
case 0x0c06afaau: goto P_0c06afaa;
case 0x0c06afacu: goto P_0c06afac;
case 0x0c06afaeu: goto P_0c06afae;
case 0x0c06afb0u: goto P_0c06afb0;
case 0x0c06afb2u: goto P_0c06afb2;
case 0x0c06afb4u: goto P_0c06afb4;
case 0x0c06afb6u: goto P_0c06afb6;
case 0x0c06afb8u: goto P_0c06afb8;
case 0x0c06afbau: goto P_0c06afba;
case 0x0c06afbcu: goto P_0c06afbc;
case 0x0c06afbeu: goto P_0c06afbe;
case 0x0c06afc0u: goto P_0c06afc0;
case 0x0c06afc2u: goto P_0c06afc2;
case 0x0c06afc4u: goto P_0c06afc4;
case 0x0c06afc6u: goto P_0c06afc6;
case 0x0c06afc8u: goto P_0c06afc8;
case 0x0c06afcau: goto P_0c06afca;
case 0x0c06afccu: goto P_0c06afcc;
case 0x0c06afceu: goto P_0c06afce;
case 0x0c06afd0u: goto P_0c06afd0;
case 0x0c06afd2u: goto P_0c06afd2;
case 0x0c06afd4u: goto P_0c06afd4;
case 0x0c06afd6u: goto P_0c06afd6;
case 0x0c06afd8u: goto P_0c06afd8;
case 0x0c06afdau: goto P_0c06afda;
case 0x0c06afdcu: goto P_0c06afdc;
case 0x0c06afdeu: goto P_0c06afde;
case 0x0c06afe0u: goto P_0c06afe0;
case 0x0c06afe2u: goto P_0c06afe2;
case 0x0c06afe4u: goto P_0c06afe4;
case 0x0c06afe6u: goto P_0c06afe6;
case 0x0c06afe8u: goto P_0c06afe8;
case 0x0c06afeau: goto P_0c06afea;
case 0x0c06c398u: goto P_0c06c398;
case 0x0c06c39au: goto P_0c06c39a;
case 0x0c06c39cu: goto P_0c06c39c;
case 0x0c06c39eu: goto P_0c06c39e;
case 0x0c06c3a0u: goto P_0c06c3a0;
case 0x0c06c3a2u: goto P_0c06c3a2;
case 0x0c06c3a4u: goto P_0c06c3a4;
case 0x0c06c3a6u: goto P_0c06c3a6;
case 0x0c06c3a8u: goto P_0c06c3a8;
case 0x0c06c3aau: goto P_0c06c3aa;
case 0x0c06c3acu: goto P_0c06c3ac;
case 0x0c06c3aeu: goto P_0c06c3ae;
case 0x0c06c3b0u: goto P_0c06c3b0;
case 0x0c06c3b2u: goto P_0c06c3b2;
case 0x0c06c3b4u: goto P_0c06c3b4;
case 0x0c06c3b6u: goto P_0c06c3b6;
case 0x0c06c3b8u: goto P_0c06c3b8;
case 0x0c06c3bau: goto P_0c06c3ba;
case 0x0c06c3bcu: goto P_0c06c3bc;
case 0x0c06c3beu: goto P_0c06c3be;
case 0x0c06c3c0u: goto P_0c06c3c0;
case 0x0c06c3c2u: goto P_0c06c3c2;
case 0x0c06c3c4u: goto P_0c06c3c4;
case 0x0c06c3c6u: goto P_0c06c3c6;
case 0x0c06c3c8u: goto P_0c06c3c8;
case 0x0c06c3cau: goto P_0c06c3ca;
case 0x0c06c3ccu: goto P_0c06c3cc;
case 0x0c06c3ceu: goto P_0c06c3ce;
case 0x0c06c8a4u: goto P_0c06c8a4;
case 0x0c06c8a6u: goto P_0c06c8a6;
case 0x0c06c8a8u: goto P_0c06c8a8;
case 0x0c06c8aau: goto P_0c06c8aa;
case 0x0c06c8acu: goto P_0c06c8ac;
case 0x0c06c8aeu: goto P_0c06c8ae;
case 0x0c06c8b0u: goto P_0c06c8b0;
case 0x0c06c8b2u: goto P_0c06c8b2;
case 0x0c06c8b4u: goto P_0c06c8b4;
case 0x0c06c8b6u: goto P_0c06c8b6;
case 0x0c06c8b8u: goto P_0c06c8b8;
case 0x0c06c8bau: goto P_0c06c8ba;
case 0x0c06c8bcu: goto P_0c06c8bc;
case 0x0c06c8beu: goto P_0c06c8be;
case 0x0c06c8c0u: goto P_0c06c8c0;
case 0x0c06c8c2u: goto P_0c06c8c2;
case 0x0c06c8c4u: goto P_0c06c8c4;
case 0x0c06c8c6u: goto P_0c06c8c6;
case 0x0c06c8c8u: goto P_0c06c8c8;
case 0x0c06c8cau: goto P_0c06c8ca;
case 0x0c06c8ccu: goto P_0c06c8cc;
case 0x0c06c8ceu: goto P_0c06c8ce;
case 0x0c06c8d0u: goto P_0c06c8d0;
case 0x0c06c8d2u: goto P_0c06c8d2;
case 0x0c06c8d4u: goto P_0c06c8d4;
case 0x0c06c8d6u: goto P_0c06c8d6;
case 0x0c06c8d8u: goto P_0c06c8d8;
case 0x0c06c8dau: goto P_0c06c8da;
case 0x0c06c8dcu: goto P_0c06c8dc;
case 0x0c06c8deu: goto P_0c06c8de;
case 0x0c06c8e0u: goto P_0c06c8e0;
case 0x0c06c8e2u: goto P_0c06c8e2;
case 0x0c06c8e4u: goto P_0c06c8e4;
case 0x0c06c8e6u: goto P_0c06c8e6;
case 0x0c06c8e8u: goto P_0c06c8e8;
case 0x0c06c8eau: goto P_0c06c8ea;
case 0x0c06c8ecu: goto P_0c06c8ec;
case 0x0c06c8eeu: goto P_0c06c8ee;
case 0x0c06c8f0u: goto P_0c06c8f0;
case 0x0c06c8f2u: goto P_0c06c8f2;
case 0x0c06c8f4u: goto P_0c06c8f4;
case 0x0c06c914u: goto P_0c06c914;
case 0x0c06c916u: goto P_0c06c916;
case 0x0c06c918u: goto P_0c06c918;
case 0x0c06c91au: goto P_0c06c91a;
case 0x0c06c91cu: goto P_0c06c91c;
case 0x0c06c91eu: goto P_0c06c91e;
case 0x0c06c920u: goto P_0c06c920;
case 0x0c06c922u: goto P_0c06c922;
case 0x0c06c924u: goto P_0c06c924;
case 0x0c06c926u: goto P_0c06c926;
case 0x0c06c928u: goto P_0c06c928;
case 0x0c06c92au: goto P_0c06c92a;
case 0x0c06c92cu: goto P_0c06c92c;
case 0x0c06c92eu: goto P_0c06c92e;
case 0x0c06c930u: goto P_0c06c930;
case 0x0c06c932u: goto P_0c06c932;
case 0x0c06c934u: goto P_0c06c934;
case 0x0c06c936u: goto P_0c06c936;
case 0x0c06c938u: goto P_0c06c938;
case 0x0c06c93au: goto P_0c06c93a;
case 0x0c06c93cu: goto P_0c06c93c;
case 0x0c06c93eu: goto P_0c06c93e;
case 0x0c06c940u: goto P_0c06c940;
case 0x0c06c942u: goto P_0c06c942;
case 0x0c06c944u: goto P_0c06c944;
case 0x0c06c946u: goto P_0c06c946;
case 0x0c06c948u: goto P_0c06c948;
case 0x0c06c94au: goto P_0c06c94a;
case 0x0c06c94cu: goto P_0c06c94c;
case 0x0c06c94eu: goto P_0c06c94e;
case 0x0c06c950u: goto P_0c06c950;
case 0x0c06c952u: goto P_0c06c952;
case 0x0c06c954u: goto P_0c06c954;
case 0x0c06c956u: goto P_0c06c956;
case 0x0c06c958u: goto P_0c06c958;
case 0x0c06c95au: goto P_0c06c95a;
case 0x0c06c95cu: goto P_0c06c95c;
case 0x0c07a844u: goto P_0c07a844;
case 0x0c07a846u: goto P_0c07a846;
case 0x0c07a848u: goto P_0c07a848;
case 0x0c07a84au: goto P_0c07a84a;
case 0x0c07a84cu: goto P_0c07a84c;
case 0x0c07a84eu: goto P_0c07a84e;
case 0x0c07a850u: goto P_0c07a850;
case 0x0c07a852u: goto P_0c07a852;
case 0x0c07a854u: goto P_0c07a854;
case 0x0c07a856u: goto P_0c07a856;
case 0x0c07a858u: goto P_0c07a858;
case 0x0c07a85au: goto P_0c07a85a;
case 0x0c07a85cu: goto P_0c07a85c;
case 0x0c07a85eu: goto P_0c07a85e;
case 0x0c07a860u: goto P_0c07a860;
case 0x0c07a862u: goto P_0c07a862;
case 0x0c07a864u: goto P_0c07a864;
case 0x0c07a866u: goto P_0c07a866;
case 0x0c07a868u: goto P_0c07a868;
case 0x0c07a86au: goto P_0c07a86a;
case 0x0c07a86cu: goto P_0c07a86c;
case 0x0c07a86eu: goto P_0c07a86e;
case 0x0c07a870u: goto P_0c07a870;
case 0x0c07a872u: goto P_0c07a872;
case 0x0c07a874u: goto P_0c07a874;
case 0x0c07a876u: goto P_0c07a876;
case 0x0c07a878u: goto P_0c07a878;
case 0x0c07a87au: goto P_0c07a87a;
case 0x0c07a87cu: goto P_0c07a87c;
case 0x0c07a87eu: goto P_0c07a87e;
case 0x0c07a880u: goto P_0c07a880;
case 0x0c07a882u: goto P_0c07a882;
case 0x0c07a884u: goto P_0c07a884;
case 0x0c07a886u: goto P_0c07a886;
case 0x0c07a888u: goto P_0c07a888;
case 0x0c07a88au: goto P_0c07a88a;
case 0x0c07a88cu: goto P_0c07a88c;
case 0x0c07a88eu: goto P_0c07a88e;
case 0x0c07a890u: goto P_0c07a890;
case 0x0c07a892u: goto P_0c07a892;
case 0x0c07a894u: goto P_0c07a894;
case 0x0c07a896u: goto P_0c07a896;
case 0x0c07a898u: goto P_0c07a898;
case 0x0c07a89au: goto P_0c07a89a;
case 0x0c07a89cu: goto P_0c07a89c;
case 0x0c07a89eu: goto P_0c07a89e;
case 0x0c07a8a0u: goto P_0c07a8a0;
case 0x0c07a8a2u: goto P_0c07a8a2;
case 0x0c07a8a4u: goto P_0c07a8a4;
case 0x0c07a8a6u: goto P_0c07a8a6;
case 0x0c07a8a8u: goto P_0c07a8a8;
case 0x0c07a8aau: goto P_0c07a8aa;
case 0x0c07a8acu: goto P_0c07a8ac;
case 0x0c07a8aeu: goto P_0c07a8ae;
case 0x0c07a8b0u: goto P_0c07a8b0;
case 0x0c07a8b2u: goto P_0c07a8b2;
case 0x0c07a8b4u: goto P_0c07a8b4;
case 0x0c07a8b6u: goto P_0c07a8b6;
case 0x0c07a8b8u: goto P_0c07a8b8;
case 0x0c07a8bau: goto P_0c07a8ba;
case 0x0c07a8bcu: goto P_0c07a8bc;
case 0x0c07a8beu: goto P_0c07a8be;
case 0x0c07a8c0u: goto P_0c07a8c0;
case 0x0c07a8c2u: goto P_0c07a8c2;
case 0x0c07a8c4u: goto P_0c07a8c4;
case 0x0c07a8c6u: goto P_0c07a8c6;
case 0x0c07a8c8u: goto P_0c07a8c8;
case 0x0c07a8cau: goto P_0c07a8ca;
case 0x0c07a8ccu: goto P_0c07a8cc;
case 0x0c07a8ceu: goto P_0c07a8ce;
case 0x0c07a8d0u: goto P_0c07a8d0;
case 0x0c07a8d2u: goto P_0c07a8d2;
case 0x0c07a8d4u: goto P_0c07a8d4;
case 0x0c07a8d6u: goto P_0c07a8d6;
case 0x0c07a8d8u: goto P_0c07a8d8;
case 0x0c07a8dau: goto P_0c07a8da;
case 0x0c07a8dcu: goto P_0c07a8dc;
case 0x0c07a8deu: goto P_0c07a8de;
case 0x0c07a8e0u: goto P_0c07a8e0;
case 0x0c07a8e2u: goto P_0c07a8e2;
case 0x0c07a8e4u: goto P_0c07a8e4;
case 0x0c07a8e6u: goto P_0c07a8e6;
case 0x0c07a8e8u: goto P_0c07a8e8;
case 0x0c07a8eau: goto P_0c07a8ea;
case 0x0c07a8ecu: goto P_0c07a8ec;
case 0x0c07a8eeu: goto P_0c07a8ee;
case 0x0c07a8f0u: goto P_0c07a8f0;
case 0x0c07a8f2u: goto P_0c07a8f2;
case 0x0c07a8f4u: goto P_0c07a8f4;
case 0x0c07a8f6u: goto P_0c07a8f6;
case 0x0c07a8f8u: goto P_0c07a8f8;
case 0x0c07a8fau: goto P_0c07a8fa;
case 0x0c07a8fcu: goto P_0c07a8fc;
case 0x0c07a8feu: goto P_0c07a8fe;
case 0x0c07a900u: goto P_0c07a900;
case 0x0c07a902u: goto P_0c07a902;
case 0x0c07a904u: goto P_0c07a904;
case 0x0c07a906u: goto P_0c07a906;
case 0x0c07a908u: goto P_0c07a908;
case 0x0c07a90au: goto P_0c07a90a;
case 0x0c07a90cu: goto P_0c07a90c;
case 0x0c07a90eu: goto P_0c07a90e;
case 0x0c07a910u: goto P_0c07a910;
case 0x0c07a912u: goto P_0c07a912;
case 0x0c07a914u: goto P_0c07a914;
case 0x0c07a916u: goto P_0c07a916;
case 0x0c07a918u: goto P_0c07a918;
case 0x0c07a91au: goto P_0c07a91a;
case 0x0c07a91cu: goto P_0c07a91c;
case 0x0c07a91eu: goto P_0c07a91e;
case 0x0c07a920u: goto P_0c07a920;
case 0x0c07a922u: goto P_0c07a922;
case 0x0c07a924u: goto P_0c07a924;
case 0x0c07a926u: goto P_0c07a926;
case 0x0c07a928u: goto P_0c07a928;
case 0x0c07a92au: goto P_0c07a92a;
case 0x0c07a92cu: goto P_0c07a92c;
case 0x0c07a92eu: goto P_0c07a92e;
case 0x0c07a930u: goto P_0c07a930;
case 0x0c07a932u: goto P_0c07a932;
case 0x0c07a934u: goto P_0c07a934;
case 0x0c07a936u: goto P_0c07a936;
case 0x0c07a938u: goto P_0c07a938;
case 0x0c07a93au: goto P_0c07a93a;
case 0x0c07a93cu: goto P_0c07a93c;
case 0x0c07a93eu: goto P_0c07a93e;
case 0x0c07a940u: goto P_0c07a940;
case 0x0c07a942u: goto P_0c07a942;
case 0x0c07a944u: goto P_0c07a944;
case 0x0c07a946u: goto P_0c07a946;
case 0x0c07a948u: goto P_0c07a948;
case 0x0c07a94au: goto P_0c07a94a;
case 0x0c07a94cu: goto P_0c07a94c;
case 0x0c07a94eu: goto P_0c07a94e;
case 0x0c07a950u: goto P_0c07a950;
case 0x0c07a952u: goto P_0c07a952;
case 0x0c07a954u: goto P_0c07a954;
case 0x0c07a956u: goto P_0c07a956;
case 0x0c07a958u: goto P_0c07a958;
case 0x0c07a95au: goto P_0c07a95a;
case 0x0c07a95cu: goto P_0c07a95c;
case 0x0c07a95eu: goto P_0c07a95e;
case 0x0c07a960u: goto P_0c07a960;
case 0x0c07a962u: goto P_0c07a962;
case 0x0c07a964u: goto P_0c07a964;
case 0x0c07a966u: goto P_0c07a966;
case 0x0c07a968u: goto P_0c07a968;
case 0x0c07a96au: goto P_0c07a96a;
case 0x0c07a96cu: goto P_0c07a96c;
case 0x0c07a96eu: goto P_0c07a96e;
case 0x0c07a970u: goto P_0c07a970;
case 0x0c07a972u: goto P_0c07a972;
case 0x0c07a974u: goto P_0c07a974;
case 0x0c07a976u: goto P_0c07a976;
case 0x0c07a978u: goto P_0c07a978;
case 0x0c07a97au: goto P_0c07a97a;
case 0x0c07a97cu: goto P_0c07a97c;
case 0x0c07a97eu: goto P_0c07a97e;
case 0x0c07a980u: goto P_0c07a980;
case 0x0c07a982u: goto P_0c07a982;
case 0x0c07a984u: goto P_0c07a984;
case 0x0c07a986u: goto P_0c07a986;
case 0x0c07a988u: goto P_0c07a988;
case 0x0c07a98au: goto P_0c07a98a;
case 0x0c07a98cu: goto P_0c07a98c;
case 0x0c07a98eu: goto P_0c07a98e;
case 0x0c07a990u: goto P_0c07a990;
case 0x0c07a992u: goto P_0c07a992;
case 0x0c07a994u: goto P_0c07a994;
case 0x0c07a996u: goto P_0c07a996;
case 0x0c07a998u: goto P_0c07a998;
case 0x0c07a99au: goto P_0c07a99a;
case 0x0c07a99cu: goto P_0c07a99c;
case 0x0c07a99eu: goto P_0c07a99e;
case 0x0c07a9a0u: goto P_0c07a9a0;
case 0x0c07a9a2u: goto P_0c07a9a2;
case 0x0c07a9a4u: goto P_0c07a9a4;
case 0x0c07a9a6u: goto P_0c07a9a6;
case 0x0c07a9a8u: goto P_0c07a9a8;
case 0x0c07a9aau: goto P_0c07a9aa;
case 0x0c07a9acu: goto P_0c07a9ac;
case 0x0c07a9aeu: goto P_0c07a9ae;
case 0x0c07a9b0u: goto P_0c07a9b0;
case 0x0c07a9b2u: goto P_0c07a9b2;
case 0x0c07a9f8u: goto P_0c07a9f8;
case 0x0c07a9fau: goto P_0c07a9fa;
case 0x0c07a9fcu: goto P_0c07a9fc;
case 0x0c07a9feu: goto P_0c07a9fe;
case 0x0c07aa00u: goto P_0c07aa00;
case 0x0c07aa02u: goto P_0c07aa02;
case 0x0c07aa04u: goto P_0c07aa04;
case 0x0c07aa06u: goto P_0c07aa06;
case 0x0c07aa08u: goto P_0c07aa08;
case 0x0c07aa0au: goto P_0c07aa0a;
case 0x0c07aa0cu: goto P_0c07aa0c;
case 0x0c07aa0eu: goto P_0c07aa0e;
case 0x0c07aa10u: goto P_0c07aa10;
case 0x0c07aa12u: goto P_0c07aa12;
case 0x0c07aa14u: goto P_0c07aa14;
case 0x0c07aa16u: goto P_0c07aa16;
case 0x0c07aa18u: goto P_0c07aa18;
case 0x0c07aa1au: goto P_0c07aa1a;
case 0x0c07aa1cu: goto P_0c07aa1c;
case 0x0c07aa1eu: goto P_0c07aa1e;
case 0x0c07aa20u: goto P_0c07aa20;
case 0x0c07aa22u: goto P_0c07aa22;
case 0x0c07aa24u: goto P_0c07aa24;
case 0x0c07aa26u: goto P_0c07aa26;
case 0x0c07aa28u: goto P_0c07aa28;
case 0x0c07aa2au: goto P_0c07aa2a;
case 0x0c07aa2cu: goto P_0c07aa2c;
case 0x0c07aa2eu: goto P_0c07aa2e;
case 0x0c07aa34u: goto P_0c07aa34;
case 0x0c07aa36u: goto P_0c07aa36;
case 0x0c07aa38u: goto P_0c07aa38;
case 0x0c07aa3au: goto P_0c07aa3a;
case 0x0c07aa3cu: goto P_0c07aa3c;
case 0x0c07aa3eu: goto P_0c07aa3e;
case 0x0c07aa40u: goto P_0c07aa40;
case 0x0c07aa42u: goto P_0c07aa42;
case 0x0c07aa44u: goto P_0c07aa44;
case 0x0c07aa46u: goto P_0c07aa46;
case 0x0c07aa48u: goto P_0c07aa48;
case 0x0c07aa4au: goto P_0c07aa4a;
case 0x0c07aa4cu: goto P_0c07aa4c;
case 0x0c07aa4eu: goto P_0c07aa4e;
case 0x0c07aa50u: goto P_0c07aa50;
case 0x0c07aa52u: goto P_0c07aa52;
case 0x0c07aa54u: goto P_0c07aa54;
case 0x0c07aa56u: goto P_0c07aa56;
case 0x0c07aa58u: goto P_0c07aa58;
case 0x0c07d890u: goto P_0c07d890;
case 0x0c07d892u: goto P_0c07d892;
case 0x0c07d894u: goto P_0c07d894;
case 0x0c07d896u: goto P_0c07d896;
case 0x0c07d898u: goto P_0c07d898;
case 0x0c07d89au: goto P_0c07d89a;
case 0x0c07d89cu: goto P_0c07d89c;
case 0x0c07d89eu: goto P_0c07d89e;
case 0x0c07d8a0u: goto P_0c07d8a0;
case 0x0c07d8a2u: goto P_0c07d8a2;
case 0x0c07d8a4u: goto P_0c07d8a4;
case 0x0c07d8a6u: goto P_0c07d8a6;
case 0x0c07d8a8u: goto P_0c07d8a8;
case 0x0c07d8aau: goto P_0c07d8aa;
case 0x0c07d8acu: goto P_0c07d8ac;
case 0x0c07d8aeu: goto P_0c07d8ae;
case 0x0c07d8b0u: goto P_0c07d8b0;
case 0x0c07d8b2u: goto P_0c07d8b2;
case 0x0c07d8b4u: goto P_0c07d8b4;
case 0x0c07d8b6u: goto P_0c07d8b6;
case 0x0c07d8b8u: goto P_0c07d8b8;
case 0x0c07d8bau: goto P_0c07d8ba;
case 0x0c07d8bcu: goto P_0c07d8bc;
case 0x0c07d8beu: goto P_0c07d8be;
case 0x0c07d8c0u: goto P_0c07d8c0;
case 0x0c07d8c2u: goto P_0c07d8c2;
case 0x0c07d8c4u: goto P_0c07d8c4;
case 0x0c07d8c6u: goto P_0c07d8c6;
case 0x0c07d8c8u: goto P_0c07d8c8;
case 0x0c07d8cau: goto P_0c07d8ca;
case 0x0c07d8ccu: goto P_0c07d8cc;
case 0x0c07d8ceu: goto P_0c07d8ce;
case 0x0c07d8d0u: goto P_0c07d8d0;
case 0x0c07d8d2u: goto P_0c07d8d2;
case 0x0c07d8d4u: goto P_0c07d8d4;
case 0x0c07d8d6u: goto P_0c07d8d6;
case 0x0c07d8d8u: goto P_0c07d8d8;
case 0x0c07d8dau: goto P_0c07d8da;
case 0x0c07d8dcu: goto P_0c07d8dc;
case 0x0c07d8deu: goto P_0c07d8de;
case 0x0c07d8e0u: goto P_0c07d8e0;
case 0x0c07d8e2u: goto P_0c07d8e2;
case 0x0c07d8e4u: goto P_0c07d8e4;
case 0x0c07d8e6u: goto P_0c07d8e6;
case 0x0c07d8e8u: goto P_0c07d8e8;
case 0x0c07d8eau: goto P_0c07d8ea;
case 0x0c07d8ecu: goto P_0c07d8ec;
case 0x0c07e918u: goto P_0c07e918;
case 0x0c07e91au: goto P_0c07e91a;
case 0x0c07e91cu: goto P_0c07e91c;
case 0x0c07e91eu: goto P_0c07e91e;
case 0x0c07e920u: goto P_0c07e920;
case 0x0c07e922u: goto P_0c07e922;
case 0x0c07e924u: goto P_0c07e924;
case 0x0c07e926u: goto P_0c07e926;
case 0x0c07e928u: goto P_0c07e928;
case 0x0c07e92au: goto P_0c07e92a;
case 0x0c07e92cu: goto P_0c07e92c;
case 0x0c07e92eu: goto P_0c07e92e;
case 0x0c07e930u: goto P_0c07e930;
case 0x0c07e932u: goto P_0c07e932;
case 0x0c07e934u: goto P_0c07e934;
case 0x0c07e936u: goto P_0c07e936;
case 0x0c07e938u: goto P_0c07e938;
case 0x0c07e93au: goto P_0c07e93a;
case 0x0c07e93cu: goto P_0c07e93c;
case 0x0c07e93eu: goto P_0c07e93e;
case 0x0c07e940u: goto P_0c07e940;
case 0x0c07e942u: goto P_0c07e942;
case 0x0c07e944u: goto P_0c07e944;
case 0x0c07e946u: goto P_0c07e946;
case 0x0c07e948u: goto P_0c07e948;
case 0x0c07e94au: goto P_0c07e94a;
case 0x0c07e94cu: goto P_0c07e94c;
case 0x0c07e94eu: goto P_0c07e94e;
case 0x0c07e950u: goto P_0c07e950;
case 0x0c07e952u: goto P_0c07e952;
case 0x0c07e954u: goto P_0c07e954;
case 0x0c07e956u: goto P_0c07e956;
case 0x0c07e958u: goto P_0c07e958;
case 0x0c07e95au: goto P_0c07e95a;
case 0x0c07e95cu: goto P_0c07e95c;
case 0x0c07e95eu: goto P_0c07e95e;
case 0x0c07e960u: goto P_0c07e960;
case 0x0c07e962u: goto P_0c07e962;
case 0x0c07e964u: goto P_0c07e964;
case 0x0c07e966u: goto P_0c07e966;
case 0x0c07e968u: goto P_0c07e968;
case 0x0c07e96au: goto P_0c07e96a;
case 0x0c07e96cu: goto P_0c07e96c;
case 0x0c07e96eu: goto P_0c07e96e;
case 0x0c07e970u: goto P_0c07e970;
case 0x0c07e972u: goto P_0c07e972;
case 0x0c07e974u: goto P_0c07e974;
case 0x0c07e976u: goto P_0c07e976;
case 0x0c07e978u: goto P_0c07e978;
case 0x0c07e97au: goto P_0c07e97a;
case 0x0c07e97cu: goto P_0c07e97c;
case 0x0c07e97eu: goto P_0c07e97e;
case 0x0c07e980u: goto P_0c07e980;
case 0x0c07e982u: goto P_0c07e982;
case 0x0c07e984u: goto P_0c07e984;
case 0x0c07e986u: goto P_0c07e986;
case 0x0c07e988u: goto P_0c07e988;
case 0x0c07e98au: goto P_0c07e98a;
case 0x0c07e9dcu: goto P_0c07e9dc;
case 0x0c07e9deu: goto P_0c07e9de;
case 0x0c07e9e0u: goto P_0c07e9e0;
case 0x0c07e9e2u: goto P_0c07e9e2;
case 0x0c07e9e4u: goto P_0c07e9e4;
case 0x0c07e9e6u: goto P_0c07e9e6;
case 0x0c07e9e8u: goto P_0c07e9e8;
case 0x0c07e9eau: goto P_0c07e9ea;
case 0x0c07e9ecu: goto P_0c07e9ec;
case 0x0c07e9eeu: goto P_0c07e9ee;
case 0x0c07e9f0u: goto P_0c07e9f0;
case 0x0c07e9f2u: goto P_0c07e9f2;
case 0x0c07e9f4u: goto P_0c07e9f4;
case 0x0c07e9f6u: goto P_0c07e9f6;
case 0x0c07e9f8u: goto P_0c07e9f8;
case 0x0c07e9fau: goto P_0c07e9fa;
case 0x0c07e9fcu: goto P_0c07e9fc;
case 0x0c07e9feu: goto P_0c07e9fe;
case 0x0c07ea00u: goto P_0c07ea00;
case 0x0c07ea02u: goto P_0c07ea02;
case 0x0c07ea04u: goto P_0c07ea04;
case 0x0c07ea06u: goto P_0c07ea06;
case 0x0c07ea08u: goto P_0c07ea08;
case 0x0c07ea0au: goto P_0c07ea0a;
case 0x0c07ea0cu: goto P_0c07ea0c;
case 0x0c07ea0eu: goto P_0c07ea0e;
case 0x0c07ea10u: goto P_0c07ea10;
case 0x0c07ea12u: goto P_0c07ea12;
case 0x0c07ea14u: goto P_0c07ea14;
case 0x0c07ea16u: goto P_0c07ea16;
case 0x0c07ea18u: goto P_0c07ea18;
case 0x0c07ea1au: goto P_0c07ea1a;
case 0x0c07ea1cu: goto P_0c07ea1c;
case 0x0c07ea1eu: goto P_0c07ea1e;
case 0x0c07ea20u: goto P_0c07ea20;
case 0x0c07ea22u: goto P_0c07ea22;
case 0x0c07ea24u: goto P_0c07ea24;
case 0x0c07ea26u: goto P_0c07ea26;
case 0x0c07ea28u: goto P_0c07ea28;
case 0x0c07ea2au: goto P_0c07ea2a;
case 0x0c07ea2cu: goto P_0c07ea2c;
case 0x0c07ea2eu: goto P_0c07ea2e;
case 0x0c07ea30u: goto P_0c07ea30;
case 0x0c07ea32u: goto P_0c07ea32;
case 0x0c07ea34u: goto P_0c07ea34;
case 0x0c07ea36u: goto P_0c07ea36;
case 0x0c07ea38u: goto P_0c07ea38;
case 0x0c07ea3au: goto P_0c07ea3a;
case 0x0c07ea3cu: goto P_0c07ea3c;
case 0x0c07ea3eu: goto P_0c07ea3e;
case 0x0c07ea40u: goto P_0c07ea40;
case 0x0c07ea42u: goto P_0c07ea42;
case 0x0c07ea44u: goto P_0c07ea44;
case 0x0c07ea46u: goto P_0c07ea46;
case 0x0c07ea48u: goto P_0c07ea48;
case 0x0c07ea4au: goto P_0c07ea4a;
case 0x0c07ea4cu: goto P_0c07ea4c;
case 0x0c07ea4eu: goto P_0c07ea4e;
case 0x0c07ea50u: goto P_0c07ea50;
case 0x0c07ea52u: goto P_0c07ea52;
case 0x0c07ea54u: goto P_0c07ea54;
case 0x0c07ea56u: goto P_0c07ea56;
case 0x0c07ea58u: goto P_0c07ea58;
case 0x0c07ea5au: goto P_0c07ea5a;
case 0x0c07ea5cu: goto P_0c07ea5c;
case 0x0c07ea5eu: goto P_0c07ea5e;
case 0x0c07ea60u: goto P_0c07ea60;
case 0x0c07ea62u: goto P_0c07ea62;
case 0x0c07ea64u: goto P_0c07ea64;
case 0x0c07ea66u: goto P_0c07ea66;
case 0x0c07ea68u: goto P_0c07ea68;
case 0x0c07ea6au: goto P_0c07ea6a;
case 0x0c07ea6cu: goto P_0c07ea6c;
case 0x0c07ea6eu: goto P_0c07ea6e;
case 0x0c07ea70u: goto P_0c07ea70;
case 0x0c07ea72u: goto P_0c07ea72;
case 0x0c07ea74u: goto P_0c07ea74;
case 0x0c07ea76u: goto P_0c07ea76;
case 0x0c07ea78u: goto P_0c07ea78;
case 0x0c07ea7au: goto P_0c07ea7a;
case 0x0c07ea7cu: goto P_0c07ea7c;
case 0x0c07ea7eu: goto P_0c07ea7e;
case 0x0c07ea80u: goto P_0c07ea80;
case 0x0c07ea82u: goto P_0c07ea82;
case 0x0c07ea84u: goto P_0c07ea84;
case 0x0c07ea86u: goto P_0c07ea86;
case 0x0c07ea88u: goto P_0c07ea88;
case 0x0c07ea8au: goto P_0c07ea8a;
case 0x0c07ea8cu: goto P_0c07ea8c;
case 0x0c07ea8eu: goto P_0c07ea8e;
case 0x0c07ea90u: goto P_0c07ea90;
case 0x0c07ea92u: goto P_0c07ea92;
case 0x0c07ea94u: goto P_0c07ea94;
case 0x0c07ea96u: goto P_0c07ea96;
case 0x0c07ea98u: goto P_0c07ea98;
case 0x0c07ea9au: goto P_0c07ea9a;
case 0x0c07ea9cu: goto P_0c07ea9c;
case 0x0c07ea9eu: goto P_0c07ea9e;
case 0x0c07eaa0u: goto P_0c07eaa0;
case 0x0c07eaa2u: goto P_0c07eaa2;
case 0x0c07eaa4u: goto P_0c07eaa4;
case 0x0c07eaa6u: goto P_0c07eaa6;
case 0x0c07eaa8u: goto P_0c07eaa8;
case 0x0c07eaaau: goto P_0c07eaaa;
case 0x0c07eaacu: goto P_0c07eaac;
case 0x0c07eaaeu: goto P_0c07eaae;
case 0x0c07eab0u: goto P_0c07eab0;
case 0x0c07eab2u: goto P_0c07eab2;
case 0x0c07eab4u: goto P_0c07eab4;
case 0x0c07eab6u: goto P_0c07eab6;
case 0x0c07eab8u: goto P_0c07eab8;
case 0x0c07eabau: goto P_0c07eaba;
case 0x0c07eabcu: goto P_0c07eabc;
case 0x0c07eabeu: goto P_0c07eabe;
case 0x0c07eac0u: goto P_0c07eac0;
case 0x0c07eac2u: goto P_0c07eac2;
case 0x0c07eac4u: goto P_0c07eac4;
case 0x0c07eac6u: goto P_0c07eac6;
case 0x0c07f022u: goto P_0c07f022;
case 0x0c07f024u: goto P_0c07f024;
case 0x0c07f026u: goto P_0c07f026;
case 0x0c07f028u: goto P_0c07f028;
case 0x0c07f02au: goto P_0c07f02a;
case 0x0c07f02cu: goto P_0c07f02c;
case 0x0c07f02eu: goto P_0c07f02e;
case 0x0c07f030u: goto P_0c07f030;
case 0x0c07f032u: goto P_0c07f032;
case 0x0c07f034u: goto P_0c07f034;
case 0x0c07f036u: goto P_0c07f036;
case 0x0c07f038u: goto P_0c07f038;
case 0x0c07f03au: goto P_0c07f03a;
case 0x0c07f03cu: goto P_0c07f03c;
case 0x0c07f03eu: goto P_0c07f03e;
case 0x0c07f040u: goto P_0c07f040;
case 0x0c07f042u: goto P_0c07f042;
case 0x0c07f044u: goto P_0c07f044;
case 0x0c07f046u: goto P_0c07f046;
case 0x0c07f048u: goto P_0c07f048;
case 0x0c07f04au: goto P_0c07f04a;
case 0x0c07f04cu: goto P_0c07f04c;
case 0x0c07f04eu: goto P_0c07f04e;
case 0x0c07f050u: goto P_0c07f050;
case 0x0c07f052u: goto P_0c07f052;
case 0x0c07f054u: goto P_0c07f054;
case 0x0c07f056u: goto P_0c07f056;
case 0x0c07f058u: goto P_0c07f058;
case 0x0c07f05au: goto P_0c07f05a;
case 0x0c07f05cu: goto P_0c07f05c;
case 0x0c07f05eu: goto P_0c07f05e;
case 0x0c07f060u: goto P_0c07f060;
case 0x0c07f062u: goto P_0c07f062;
case 0x0c07f064u: goto P_0c07f064;
case 0x0c07f066u: goto P_0c07f066;
case 0x0c07f068u: goto P_0c07f068;
case 0x0c07f06au: goto P_0c07f06a;
case 0x0c07f06cu: goto P_0c07f06c;
case 0x0c07f06eu: goto P_0c07f06e;
case 0x0c07f070u: goto P_0c07f070;
case 0x0c07f072u: goto P_0c07f072;
case 0x0c07f074u: goto P_0c07f074;
case 0x0c07f076u: goto P_0c07f076;
case 0x0c07f078u: goto P_0c07f078;
case 0x0c07f07au: goto P_0c07f07a;
case 0x0c07f07cu: goto P_0c07f07c;
case 0x0c07f07eu: goto P_0c07f07e;
case 0x0c07f080u: goto P_0c07f080;
case 0x0c07f082u: goto P_0c07f082;
case 0x0c07f084u: goto P_0c07f084;
case 0x0c07f086u: goto P_0c07f086;
case 0x0c07f088u: goto P_0c07f088;
case 0x0c0807d2u: goto P_0c0807d2;
case 0x0c0807d4u: goto P_0c0807d4;
case 0x0c0807d6u: goto P_0c0807d6;
case 0x0c0807d8u: goto P_0c0807d8;
case 0x0c0807dau: goto P_0c0807da;
case 0x0c0807dcu: goto P_0c0807dc;
case 0x0c0807deu: goto P_0c0807de;
case 0x0c0807e0u: goto P_0c0807e0;
case 0x0c0807e2u: goto P_0c0807e2;
case 0x0c0807e4u: goto P_0c0807e4;
case 0x0c0807e6u: goto P_0c0807e6;
case 0x0c0807e8u: goto P_0c0807e8;
case 0x0c0807eau: goto P_0c0807ea;
case 0x0c0807ecu: goto P_0c0807ec;
case 0x0c0807eeu: goto P_0c0807ee;
case 0x0c0810c0u: goto P_0c0810c0;
case 0x0c0810c2u: goto P_0c0810c2;
case 0x0c0810c4u: goto P_0c0810c4;
case 0x0c0810c6u: goto P_0c0810c6;
case 0x0c0810c8u: goto P_0c0810c8;
case 0x0c0810cau: goto P_0c0810ca;
case 0x0c0810ccu: goto P_0c0810cc;
case 0x0c0810ceu: goto P_0c0810ce;
case 0x0c0810d0u: goto P_0c0810d0;
case 0x0c0810d2u: goto P_0c0810d2;
case 0x0c0810d4u: goto P_0c0810d4;
case 0x0c0810d6u: goto P_0c0810d6;
case 0x0c0810d8u: goto P_0c0810d8;
case 0x0c0810dau: goto P_0c0810da;
case 0x0c0810dcu: goto P_0c0810dc;
case 0x0c0810deu: goto P_0c0810de;
case 0x0c0810e0u: goto P_0c0810e0;
case 0x0c0810e2u: goto P_0c0810e2;
case 0x0c0810e4u: goto P_0c0810e4;
case 0x0c0810e6u: goto P_0c0810e6;
case 0x0c0810e8u: goto P_0c0810e8;
case 0x0c0810eau: goto P_0c0810ea;
case 0x0c0810ecu: goto P_0c0810ec;
case 0x0c0810eeu: goto P_0c0810ee;
case 0x0c0810f0u: goto P_0c0810f0;
case 0x0c081982u: goto P_0c081982;
case 0x0c081984u: goto P_0c081984;
case 0x0c081986u: goto P_0c081986;
case 0x0c081988u: goto P_0c081988;
case 0x0c08198au: goto P_0c08198a;
case 0x0c08198cu: goto P_0c08198c;
case 0x0c08198eu: goto P_0c08198e;
case 0x0c081990u: goto P_0c081990;
case 0x0c081992u: goto P_0c081992;
case 0x0c081994u: goto P_0c081994;
case 0x0c081996u: goto P_0c081996;
case 0x0c081998u: goto P_0c081998;
case 0x0c08199au: goto P_0c08199a;
case 0x0c08199cu: goto P_0c08199c;
case 0x0c08199eu: goto P_0c08199e;
case 0x0c0819a0u: goto P_0c0819a0;
case 0x0c0819a2u: goto P_0c0819a2;
case 0x0c0819a4u: goto P_0c0819a4;
case 0x0c0819b0u: goto P_0c0819b0;
case 0x0c0819b2u: goto P_0c0819b2;
case 0x0c0819b4u: goto P_0c0819b4;
case 0x0c0819b6u: goto P_0c0819b6;
case 0x0c0819b8u: goto P_0c0819b8;
case 0x0c0819bau: goto P_0c0819ba;
case 0x0c0819bcu: goto P_0c0819bc;
case 0x0c0819beu: goto P_0c0819be;
case 0x0c0819c0u: goto P_0c0819c0;
case 0x0c0819c2u: goto P_0c0819c2;
case 0x0c0819c4u: goto P_0c0819c4;
case 0x0c0819c6u: goto P_0c0819c6;
case 0x0c0819c8u: goto P_0c0819c8;
case 0x0c0819cau: goto P_0c0819ca;
case 0x0c0819ccu: goto P_0c0819cc;
case 0x0c0819ceu: goto P_0c0819ce;
case 0x0c0819d0u: goto P_0c0819d0;
case 0x0c0819d2u: goto P_0c0819d2;
case 0x0c084aa2u: goto P_0c084aa2;
case 0x0c084aa4u: goto P_0c084aa4;
case 0x0c084aa6u: goto P_0c084aa6;
case 0x0c084aa8u: goto P_0c084aa8;
case 0x0c084aaau: goto P_0c084aaa;
case 0x0c084aacu: goto P_0c084aac;
case 0x0c084aaeu: goto P_0c084aae;
case 0x0c084ab0u: goto P_0c084ab0;
case 0x0c084ab2u: goto P_0c084ab2;
case 0x0c084ab4u: goto P_0c084ab4;
case 0x0c084ab6u: goto P_0c084ab6;
case 0x0c084ab8u: goto P_0c084ab8;
case 0x0c084abau: goto P_0c084aba;
case 0x0c084abcu: goto P_0c084abc;
case 0x0c084abeu: goto P_0c084abe;
case 0x0c084ac0u: goto P_0c084ac0;
case 0x0c084ac2u: goto P_0c084ac2;
case 0x0c084ac4u: goto P_0c084ac4;
case 0x0c084ac6u: goto P_0c084ac6;
case 0x0c084ac8u: goto P_0c084ac8;
case 0x0c084acau: goto P_0c084aca;
case 0x0c084accu: goto P_0c084acc;
case 0x0c084aceu: goto P_0c084ace;
case 0x0c084ad0u: goto P_0c084ad0;
case 0x0c084ad2u: goto P_0c084ad2;
case 0x0c084ad4u: goto P_0c084ad4;
case 0x0c084ad6u: goto P_0c084ad6;
case 0x0c084ad8u: goto P_0c084ad8;
case 0x0c084adau: goto P_0c084ada;
case 0x0c084adcu: goto P_0c084adc;
case 0x0c085cb4u: goto P_0c085cb4;
case 0x0c085cb6u: goto P_0c085cb6;
case 0x0c085cb8u: goto P_0c085cb8;
case 0x0c085cbau: goto P_0c085cba;
case 0x0c085cbcu: goto P_0c085cbc;
case 0x0c085cbeu: goto P_0c085cbe;
case 0x0c085cc0u: goto P_0c085cc0;
case 0x0c085cc2u: goto P_0c085cc2;
case 0x0c085cc4u: goto P_0c085cc4;
case 0x0c085cc6u: goto P_0c085cc6;
case 0x0c085cc8u: goto P_0c085cc8;
case 0x0c085ccau: goto P_0c085cca;
case 0x0c085cccu: goto P_0c085ccc;
case 0x0c085cceu: goto P_0c085cce;
case 0x0c085cd0u: goto P_0c085cd0;
case 0x0c085cd2u: goto P_0c085cd2;
case 0x0c085cd4u: goto P_0c085cd4;
case 0x0c085cd6u: goto P_0c085cd6;
case 0x0c085cd8u: goto P_0c085cd8;
case 0x0c085cdau: goto P_0c085cda;
case 0x0c085cdcu: goto P_0c085cdc;
case 0x0c085cdeu: goto P_0c085cde;
case 0x0c085ce0u: goto P_0c085ce0;
case 0x0c085ce2u: goto P_0c085ce2;
case 0x0c085ce4u: goto P_0c085ce4;
case 0x0c085ce6u: goto P_0c085ce6;
case 0x0c085ce8u: goto P_0c085ce8;
case 0x0c085ceau: goto P_0c085cea;
case 0x0c085cecu: goto P_0c085cec;
case 0x0c085ceeu: goto P_0c085cee;
case 0x0c085cf0u: goto P_0c085cf0;
case 0x0c085cf2u: goto P_0c085cf2;
case 0x0c085cf4u: goto P_0c085cf4;
case 0x0c085cf6u: goto P_0c085cf6;
case 0x0c085cf8u: goto P_0c085cf8;
case 0x0c085cfau: goto P_0c085cfa;
case 0x0c085cfcu: goto P_0c085cfc;
case 0x0c085cfeu: goto P_0c085cfe;
case 0x0c085d00u: goto P_0c085d00;
case 0x0c085d02u: goto P_0c085d02;
case 0x0c085d04u: goto P_0c085d04;
case 0x0c085d06u: goto P_0c085d06;
case 0x0c085d08u: goto P_0c085d08;
case 0x0c085d0au: goto P_0c085d0a;
case 0x0c085d0cu: goto P_0c085d0c;
case 0x0c085d0eu: goto P_0c085d0e;
case 0x0c085d10u: goto P_0c085d10;
case 0x0c085d12u: goto P_0c085d12;
case 0x0c085d14u: goto P_0c085d14;
case 0x0c085d16u: goto P_0c085d16;
case 0x0c085d18u: goto P_0c085d18;
case 0x0c085d1au: goto P_0c085d1a;
case 0x0c085d1cu: goto P_0c085d1c;
case 0x0c085d1eu: goto P_0c085d1e;
case 0x0c085d20u: goto P_0c085d20;
case 0x0c085d22u: goto P_0c085d22;
case 0x0c085d24u: goto P_0c085d24;
case 0x0c085d26u: goto P_0c085d26;
case 0x0c085d28u: goto P_0c085d28;
case 0x0c085d2au: goto P_0c085d2a;
case 0x0c085d2cu: goto P_0c085d2c;
case 0x0c085d2eu: goto P_0c085d2e;
case 0x0c085d30u: goto P_0c085d30;
case 0x0c085d32u: goto P_0c085d32;
case 0x0c085d34u: goto P_0c085d34;
case 0x0c085d36u: goto P_0c085d36;
case 0x0c085d38u: goto P_0c085d38;
case 0x0c085d3au: goto P_0c085d3a;
case 0x0c085d3cu: goto P_0c085d3c;
case 0x0c085d3eu: goto P_0c085d3e;
case 0x0c085d40u: goto P_0c085d40;
case 0x0c085d42u: goto P_0c085d42;
case 0x0c085d44u: goto P_0c085d44;
case 0x0c085d46u: goto P_0c085d46;
case 0x0c085d48u: goto P_0c085d48;
case 0x0c085d4au: goto P_0c085d4a;
case 0x0c085d4cu: goto P_0c085d4c;
case 0x0c085d4eu: goto P_0c085d4e;
case 0x0c085d50u: goto P_0c085d50;
case 0x0c085d52u: goto P_0c085d52;
case 0x0c085d54u: goto P_0c085d54;
case 0x0c085d56u: goto P_0c085d56;
case 0x0c085d58u: goto P_0c085d58;
case 0x0c085d5au: goto P_0c085d5a;
case 0x0c085d5cu: goto P_0c085d5c;
case 0x0c085d7cu: goto P_0c085d7c;
case 0x0c085d7eu: goto P_0c085d7e;
case 0x0c085d80u: goto P_0c085d80;
case 0x0c085d82u: goto P_0c085d82;
case 0x0c085d84u: goto P_0c085d84;
case 0x0c085d86u: goto P_0c085d86;
case 0x0c085d88u: goto P_0c085d88;
case 0x0c085d8au: goto P_0c085d8a;
case 0x0c085d8cu: goto P_0c085d8c;
case 0x0c085d8eu: goto P_0c085d8e;
case 0x0c085d90u: goto P_0c085d90;
case 0x0c085d92u: goto P_0c085d92;
case 0x0c085d94u: goto P_0c085d94;
case 0x0c085d96u: goto P_0c085d96;
case 0x0c085d98u: goto P_0c085d98;
case 0x0c085d9au: goto P_0c085d9a;
case 0x0c085d9cu: goto P_0c085d9c;
case 0x0c085d9eu: goto P_0c085d9e;
case 0x0c085da0u: goto P_0c085da0;
case 0x0c085da2u: goto P_0c085da2;
case 0x0c085da4u: goto P_0c085da4;
case 0x0c085da6u: goto P_0c085da6;
case 0x0c085da8u: goto P_0c085da8;
case 0x0c085daau: goto P_0c085daa;
case 0x0c085dacu: goto P_0c085dac;
case 0x0c085daeu: goto P_0c085dae;
case 0x0c085db0u: goto P_0c085db0;
case 0x0c085db2u: goto P_0c085db2;
case 0x0c085db4u: goto P_0c085db4;
case 0x0c085db6u: goto P_0c085db6;
case 0x0c085db8u: goto P_0c085db8;
case 0x0c085dbau: goto P_0c085dba;
case 0x0c085dbcu: goto P_0c085dbc;
case 0x0c085dbeu: goto P_0c085dbe;
case 0x0c085dc0u: goto P_0c085dc0;
case 0x0c085dc2u: goto P_0c085dc2;
case 0x0c085dc4u: goto P_0c085dc4;
case 0x0c085dc6u: goto P_0c085dc6;
case 0x0c085dc8u: goto P_0c085dc8;
case 0x0c085dcau: goto P_0c085dca;
case 0x0c085dccu: goto P_0c085dcc;
case 0x0c085dceu: goto P_0c085dce;
case 0x0c085dd0u: goto P_0c085dd0;
case 0x0c085dd2u: goto P_0c085dd2;
case 0x0c085dd4u: goto P_0c085dd4;
case 0x0c085dd6u: goto P_0c085dd6;
case 0x0c085dd8u: goto P_0c085dd8;
case 0x0c085ddau: goto P_0c085dda;
case 0x0c085ddcu: goto P_0c085ddc;
case 0x0c085ddeu: goto P_0c085dde;
case 0x0c085de0u: goto P_0c085de0;
case 0x0c085de2u: goto P_0c085de2;
case 0x0c085de4u: goto P_0c085de4;
case 0x0c085de6u: goto P_0c085de6;
case 0x0c085de8u: goto P_0c085de8;
case 0x0c085deau: goto P_0c085dea;
case 0x0c085decu: goto P_0c085dec;
case 0x0c085deeu: goto P_0c085dee;
case 0x0c085df0u: goto P_0c085df0;
case 0x0c085df2u: goto P_0c085df2;
case 0x0c085df4u: goto P_0c085df4;
case 0x0c085df6u: goto P_0c085df6;
case 0x0c085df8u: goto P_0c085df8;
case 0x0c085dfau: goto P_0c085dfa;
case 0x0c085dfcu: goto P_0c085dfc;
case 0x0c085dfeu: goto P_0c085dfe;
case 0x0c085e00u: goto P_0c085e00;
case 0x0c085e02u: goto P_0c085e02;
case 0x0c085e04u: goto P_0c085e04;
case 0x0c085e06u: goto P_0c085e06;
case 0x0c085e08u: goto P_0c085e08;
case 0x0c085e0au: goto P_0c085e0a;
case 0x0c085e0cu: goto P_0c085e0c;
case 0x0c085e0eu: goto P_0c085e0e;
case 0x0c085e10u: goto P_0c085e10;
case 0x0c085e12u: goto P_0c085e12;
case 0x0c085e14u: goto P_0c085e14;
case 0x0c085e16u: goto P_0c085e16;
case 0x0c085e18u: goto P_0c085e18;
case 0x0c085e1au: goto P_0c085e1a;
case 0x0c085e1cu: goto P_0c085e1c;
case 0x0c085e1eu: goto P_0c085e1e;
case 0x0c085e20u: goto P_0c085e20;
case 0x0c085e22u: goto P_0c085e22;
case 0x0c085e24u: goto P_0c085e24;
case 0x0c085e26u: goto P_0c085e26;
case 0x0c085e28u: goto P_0c085e28;
case 0x0c085e2au: goto P_0c085e2a;
case 0x0c085e2cu: goto P_0c085e2c;
case 0x0c085e2eu: goto P_0c085e2e;
case 0x0c085e30u: goto P_0c085e30;
case 0x0c085e32u: goto P_0c085e32;
case 0x0c085e34u: goto P_0c085e34;
case 0x0c085e36u: goto P_0c085e36;
case 0x0c085e38u: goto P_0c085e38;
case 0x0c085e3au: goto P_0c085e3a;
case 0x0c085e3cu: goto P_0c085e3c;
case 0x0c085e3eu: goto P_0c085e3e;
case 0x0c085e40u: goto P_0c085e40;
case 0x0c085e42u: goto P_0c085e42;
case 0x0c085e44u: goto P_0c085e44;
case 0x0c085e46u: goto P_0c085e46;
case 0x0c085e48u: goto P_0c085e48;
case 0x0c085e4au: goto P_0c085e4a;
case 0x0c085e4cu: goto P_0c085e4c;
case 0x0c085e4eu: goto P_0c085e4e;
case 0x0c085e50u: goto P_0c085e50;
case 0x0c085e52u: goto P_0c085e52;
case 0x0c085e54u: goto P_0c085e54;
case 0x0c085e56u: goto P_0c085e56;
case 0x0c085e58u: goto P_0c085e58;
case 0x0c085e5au: goto P_0c085e5a;
case 0x0c085e5cu: goto P_0c085e5c;
case 0x0c085e5eu: goto P_0c085e5e;
case 0x0c085e60u: goto P_0c085e60;
case 0x0c085e62u: goto P_0c085e62;
case 0x0c085e64u: goto P_0c085e64;
case 0x0c085e66u: goto P_0c085e66;
case 0x0c085e68u: goto P_0c085e68;
case 0x0c085e6au: goto P_0c085e6a;
case 0x0c085e6cu: goto P_0c085e6c;
case 0x0c085e6eu: goto P_0c085e6e;
case 0x0c085e70u: goto P_0c085e70;
case 0x0c085e72u: goto P_0c085e72;
case 0x0c085e74u: goto P_0c085e74;
case 0x0c085e76u: goto P_0c085e76;
case 0x0c085e78u: goto P_0c085e78;
case 0x0c085e7au: goto P_0c085e7a;
case 0x0c085e7cu: goto P_0c085e7c;
case 0x0c085e7eu: goto P_0c085e7e;
case 0x0c085e80u: goto P_0c085e80;
case 0x0c085e82u: goto P_0c085e82;
case 0x0c085e84u: goto P_0c085e84;
case 0x0c085e86u: goto P_0c085e86;
case 0x0c085e88u: goto P_0c085e88;
case 0x0c085e8au: goto P_0c085e8a;
case 0x0c085e8cu: goto P_0c085e8c;
case 0x0c085e8eu: goto P_0c085e8e;
case 0x0c085e90u: goto P_0c085e90;
case 0x0c085e92u: goto P_0c085e92;
case 0x0c085e94u: goto P_0c085e94;
case 0x0c085e96u: goto P_0c085e96;
case 0x0c085e98u: goto P_0c085e98;
case 0x0c085e9au: goto P_0c085e9a;
case 0x0c085e9cu: goto P_0c085e9c;
case 0x0c085e9eu: goto P_0c085e9e;
case 0x0c085ea0u: goto P_0c085ea0;
case 0x0c085ea2u: goto P_0c085ea2;
case 0x0c085ea4u: goto P_0c085ea4;
case 0x0c085ea6u: goto P_0c085ea6;
case 0x0c085ea8u: goto P_0c085ea8;
case 0x0c085eaau: goto P_0c085eaa;
case 0x0c085eacu: goto P_0c085eac;
case 0x0c085eaeu: goto P_0c085eae;
case 0x0c085eb0u: goto P_0c085eb0;
case 0x0c085eb2u: goto P_0c085eb2;
case 0x0c085eb4u: goto P_0c085eb4;
case 0x0c085eb6u: goto P_0c085eb6;
case 0x0c085eb8u: goto P_0c085eb8;
case 0x0c085ebau: goto P_0c085eba;
case 0x0c085ebcu: goto P_0c085ebc;
case 0x0c085ebeu: goto P_0c085ebe;
case 0x0c085ec0u: goto P_0c085ec0;
case 0x0c085ec2u: goto P_0c085ec2;
case 0x0c085ec4u: goto P_0c085ec4;
case 0x0c085ec6u: goto P_0c085ec6;
case 0x0c085ec8u: goto P_0c085ec8;
case 0x0c085ee0u: goto P_0c085ee0;
case 0x0c085ee2u: goto P_0c085ee2;
case 0x0c085ee4u: goto P_0c085ee4;
case 0x0c085ee6u: goto P_0c085ee6;
case 0x0c085ee8u: goto P_0c085ee8;
case 0x0c085eeau: goto P_0c085eea;
case 0x0c085eecu: goto P_0c085eec;
case 0x0c085eeeu: goto P_0c085eee;
case 0x0c085ef0u: goto P_0c085ef0;
case 0x0c085ef2u: goto P_0c085ef2;
case 0x0c085ef4u: goto P_0c085ef4;
case 0x0c085ef6u: goto P_0c085ef6;
case 0x0c085ef8u: goto P_0c085ef8;
case 0x0c085efau: goto P_0c085efa;
case 0x0c085efcu: goto P_0c085efc;
case 0x0c085efeu: goto P_0c085efe;
case 0x0c085f00u: goto P_0c085f00;
case 0x0c085f02u: goto P_0c085f02;
case 0x0c085f04u: goto P_0c085f04;
case 0x0c085f06u: goto P_0c085f06;
case 0x0c085f08u: goto P_0c085f08;
case 0x0c085f0au: goto P_0c085f0a;
case 0x0c085f0cu: goto P_0c085f0c;
case 0x0c085f0eu: goto P_0c085f0e;
case 0x0c085f10u: goto P_0c085f10;
case 0x0c085f12u: goto P_0c085f12;
case 0x0c085f14u: goto P_0c085f14;
case 0x0c085f16u: goto P_0c085f16;
case 0x0c085f18u: goto P_0c085f18;
case 0x0c085f1au: goto P_0c085f1a;
case 0x0c085f1cu: goto P_0c085f1c;
case 0x0c085f1eu: goto P_0c085f1e;
case 0x0c085f20u: goto P_0c085f20;
case 0x0c085f22u: goto P_0c085f22;
case 0x0c085f24u: goto P_0c085f24;
case 0x0c085f26u: goto P_0c085f26;
case 0x0c085f28u: goto P_0c085f28;
case 0x0c085f2au: goto P_0c085f2a;
case 0x0c085f2cu: goto P_0c085f2c;
case 0x0c085f2eu: goto P_0c085f2e;
case 0x0c085f30u: goto P_0c085f30;
case 0x0c085f32u: goto P_0c085f32;
case 0x0c085f34u: goto P_0c085f34;
case 0x0c085f36u: goto P_0c085f36;
case 0x0c085f38u: goto P_0c085f38;
case 0x0c085f3au: goto P_0c085f3a;
case 0x0c085f3cu: goto P_0c085f3c;
case 0x0c085f3eu: goto P_0c085f3e;
case 0x0c085f40u: goto P_0c085f40;
case 0x0c085f42u: goto P_0c085f42;
case 0x0c085f44u: goto P_0c085f44;
case 0x0c085f46u: goto P_0c085f46;
case 0x0c085f48u: goto P_0c085f48;
case 0x0c085f4au: goto P_0c085f4a;
case 0x0c085f4cu: goto P_0c085f4c;
case 0x0c085f4eu: goto P_0c085f4e;
case 0x0c085f50u: goto P_0c085f50;
case 0x0c085f52u: goto P_0c085f52;
case 0x0c085f54u: goto P_0c085f54;
case 0x0c085f56u: goto P_0c085f56;
case 0x0c085f58u: goto P_0c085f58;
case 0x0c085f5au: goto P_0c085f5a;
case 0x0c085f5cu: goto P_0c085f5c;
case 0x0c085f5eu: goto P_0c085f5e;
case 0x0c085f60u: goto P_0c085f60;
case 0x0c085f62u: goto P_0c085f62;
case 0x0c085f64u: goto P_0c085f64;
case 0x0c085f66u: goto P_0c085f66;
case 0x0c085f68u: goto P_0c085f68;
case 0x0c085f6au: goto P_0c085f6a;
case 0x0c085f6cu: goto P_0c085f6c;
case 0x0c085f6eu: goto P_0c085f6e;
case 0x0c085f70u: goto P_0c085f70;
case 0x0c085f72u: goto P_0c085f72;
case 0x0c085f74u: goto P_0c085f74;
case 0x0c085f76u: goto P_0c085f76;
case 0x0c085f78u: goto P_0c085f78;
case 0x0c085f7au: goto P_0c085f7a;
case 0x0c085f7cu: goto P_0c085f7c;
case 0x0c085f7eu: goto P_0c085f7e;
case 0x0c085f80u: goto P_0c085f80;
case 0x0c085f82u: goto P_0c085f82;
case 0x0c085f84u: goto P_0c085f84;
case 0x0c085f86u: goto P_0c085f86;
case 0x0c085f88u: goto P_0c085f88;
case 0x0c085f8au: goto P_0c085f8a;
case 0x0c085f8cu: goto P_0c085f8c;
case 0x0c085f8eu: goto P_0c085f8e;
case 0x0c085f90u: goto P_0c085f90;
case 0x0c085f92u: goto P_0c085f92;
case 0x0c085f94u: goto P_0c085f94;
case 0x0c085f96u: goto P_0c085f96;
case 0x0c085f98u: goto P_0c085f98;
case 0x0c085f9au: goto P_0c085f9a;
case 0x0c085f9cu: goto P_0c085f9c;
case 0x0c085f9eu: goto P_0c085f9e;
case 0x0c085fa0u: goto P_0c085fa0;
case 0x0c085fa2u: goto P_0c085fa2;
case 0x0c085fa4u: goto P_0c085fa4;
case 0x0c085fa6u: goto P_0c085fa6;
case 0x0c085fa8u: goto P_0c085fa8;
case 0x0c085faau: goto P_0c085faa;
case 0x0c085facu: goto P_0c085fac;
case 0x0c085faeu: goto P_0c085fae;
case 0x0c085fb0u: goto P_0c085fb0;
case 0x0c085fb2u: goto P_0c085fb2;
case 0x0c085fb4u: goto P_0c085fb4;
case 0x0c085fb6u: goto P_0c085fb6;
case 0x0c085fb8u: goto P_0c085fb8;
case 0x0c085fbau: goto P_0c085fba;
case 0x0c085fbcu: goto P_0c085fbc;
case 0x0c085fbeu: goto P_0c085fbe;
case 0x0c085fc0u: goto P_0c085fc0;
case 0x0c085fc2u: goto P_0c085fc2;
case 0x0c085fc4u: goto P_0c085fc4;
case 0x0c085fc6u: goto P_0c085fc6;
case 0x0c085fc8u: goto P_0c085fc8;
case 0x0c085fcau: goto P_0c085fca;
case 0x0c085fccu: goto P_0c085fcc;
case 0x0c085fceu: goto P_0c085fce;
case 0x0c085fd0u: goto P_0c085fd0;
case 0x0c085fd2u: goto P_0c085fd2;
case 0x0c085fd4u: goto P_0c085fd4;
case 0x0c085fd6u: goto P_0c085fd6;
case 0x0c085fd8u: goto P_0c085fd8;
case 0x0c085fdau: goto P_0c085fda;
case 0x0c085fdcu: goto P_0c085fdc;
case 0x0c085fdeu: goto P_0c085fde;
case 0x0c085fe0u: goto P_0c085fe0;
case 0x0c085fe2u: goto P_0c085fe2;
case 0x0c085fe4u: goto P_0c085fe4;
case 0x0c085fe6u: goto P_0c085fe6;
case 0x0c085fe8u: goto P_0c085fe8;
case 0x0c085feau: goto P_0c085fea;
case 0x0c085fecu: goto P_0c085fec;
case 0x0c085feeu: goto P_0c085fee;
case 0x0c085ff0u: goto P_0c085ff0;
case 0x0c085ff2u: goto P_0c085ff2;
case 0x0c085ff4u: goto P_0c085ff4;
case 0x0c085ff6u: goto P_0c085ff6;
case 0x0c085ff8u: goto P_0c085ff8;
case 0x0c085ffau: goto P_0c085ffa;
case 0x0c085ffcu: goto P_0c085ffc;
case 0x0c085ffeu: goto P_0c085ffe;
case 0x0c086000u: goto P_0c086000;
case 0x0c086002u: goto P_0c086002;
case 0x0c086004u: goto P_0c086004;
case 0x0c086006u: goto P_0c086006;
case 0x0c086008u: goto P_0c086008;
case 0x0c08600au: goto P_0c08600a;
case 0x0c08600cu: goto P_0c08600c;
case 0x0c08600eu: goto P_0c08600e;
case 0x0c086010u: goto P_0c086010;
case 0x0c086012u: goto P_0c086012;
case 0x0c086014u: goto P_0c086014;
case 0x0c086016u: goto P_0c086016;
case 0x0c086018u: goto P_0c086018;
case 0x0c08601au: goto P_0c08601a;
case 0x0c08601cu: goto P_0c08601c;
case 0x0c08601eu: goto P_0c08601e;
case 0x0c086020u: goto P_0c086020;
case 0x0c086022u: goto P_0c086022;
case 0x0c086024u: goto P_0c086024;
case 0x0c086026u: goto P_0c086026;
case 0x0c086028u: goto P_0c086028;
case 0x0c08602au: goto P_0c08602a;
case 0x0c08602cu: goto P_0c08602c;
case 0x0c08602eu: goto P_0c08602e;
case 0x0c086030u: goto P_0c086030;
case 0x0c08604cu: goto P_0c08604c;
case 0x0c08604eu: goto P_0c08604e;
case 0x0c086050u: goto P_0c086050;
case 0x0c086052u: goto P_0c086052;
case 0x0c086054u: goto P_0c086054;
case 0x0c086056u: goto P_0c086056;
case 0x0c086058u: goto P_0c086058;
case 0x0c08605au: goto P_0c08605a;
case 0x0c08605cu: goto P_0c08605c;
case 0x0c08605eu: goto P_0c08605e;
case 0x0c086060u: goto P_0c086060;
case 0x0c086062u: goto P_0c086062;
case 0x0c086064u: goto P_0c086064;
case 0x0c086066u: goto P_0c086066;
case 0x0c086068u: goto P_0c086068;
case 0x0c08606au: goto P_0c08606a;
case 0x0c08606cu: goto P_0c08606c;
case 0x0c08606eu: goto P_0c08606e;
case 0x0c086070u: goto P_0c086070;
case 0x0c086072u: goto P_0c086072;
case 0x0c086074u: goto P_0c086074;
case 0x0c086076u: goto P_0c086076;
case 0x0c086078u: goto P_0c086078;
case 0x0c08607au: goto P_0c08607a;
case 0x0c08607cu: goto P_0c08607c;
case 0x0c08607eu: goto P_0c08607e;
case 0x0c086080u: goto P_0c086080;
case 0x0c086082u: goto P_0c086082;
case 0x0c086084u: goto P_0c086084;
case 0x0c086086u: goto P_0c086086;
case 0x0c086088u: goto P_0c086088;
case 0x0c08608au: goto P_0c08608a;
case 0x0c08608cu: goto P_0c08608c;
case 0x0c08608eu: goto P_0c08608e;
case 0x0c086090u: goto P_0c086090;
case 0x0c086092u: goto P_0c086092;
case 0x0c086094u: goto P_0c086094;
case 0x0c086096u: goto P_0c086096;
case 0x0c086098u: goto P_0c086098;
case 0x0c08609au: goto P_0c08609a;
case 0x0c08609cu: goto P_0c08609c;
case 0x0c08609eu: goto P_0c08609e;
case 0x0c0860a0u: goto P_0c0860a0;
case 0x0c0860a2u: goto P_0c0860a2;
case 0x0c0860a4u: goto P_0c0860a4;
case 0x0c0860a6u: goto P_0c0860a6;
case 0x0c0860a8u: goto P_0c0860a8;
case 0x0c0860aau: goto P_0c0860aa;
case 0x0c0860acu: goto P_0c0860ac;
case 0x0c0860aeu: goto P_0c0860ae;
case 0x0c0860b0u: goto P_0c0860b0;
case 0x0c0860b2u: goto P_0c0860b2;
case 0x0c0860b4u: goto P_0c0860b4;
case 0x0c0860b6u: goto P_0c0860b6;
case 0x0c0860b8u: goto P_0c0860b8;
case 0x0c0860bau: goto P_0c0860ba;
case 0x0c0860bcu: goto P_0c0860bc;
case 0x0c0860beu: goto P_0c0860be;
case 0x0c0860c0u: goto P_0c0860c0;
case 0x0c08612cu: goto P_0c08612c;
case 0x0c08612eu: goto P_0c08612e;
case 0x0c086130u: goto P_0c086130;
case 0x0c086132u: goto P_0c086132;
case 0x0c086134u: goto P_0c086134;
case 0x0c086136u: goto P_0c086136;
case 0x0c086138u: goto P_0c086138;
case 0x0c08613au: goto P_0c08613a;
case 0x0c08613cu: goto P_0c08613c;
case 0x0c08613eu: goto P_0c08613e;
case 0x0c086140u: goto P_0c086140;
case 0x0c086142u: goto P_0c086142;
case 0x0c086144u: goto P_0c086144;
case 0x0c086146u: goto P_0c086146;
case 0x0c086148u: goto P_0c086148;
case 0x0c08614au: goto P_0c08614a;
case 0x0c08614cu: goto P_0c08614c;
case 0x0c08614eu: goto P_0c08614e;
case 0x0c086150u: goto P_0c086150;
case 0x0c086152u: goto P_0c086152;
case 0x0c087190u: goto P_0c087190;
case 0x0c087192u: goto P_0c087192;
case 0x0c087194u: goto P_0c087194;
case 0x0c087196u: goto P_0c087196;
case 0x0c087198u: goto P_0c087198;
case 0x0c08719au: goto P_0c08719a;
case 0x0c08719cu: goto P_0c08719c;
case 0x0c08719eu: goto P_0c08719e;
case 0x0c0871a0u: goto P_0c0871a0;
case 0x0c0871a2u: goto P_0c0871a2;
case 0x0c0871a4u: goto P_0c0871a4;
case 0x0c0871a6u: goto P_0c0871a6;
case 0x0c0871a8u: goto P_0c0871a8;
case 0x0c0871aau: goto P_0c0871aa;
case 0x0c0871acu: goto P_0c0871ac;
case 0x0c0871aeu: goto P_0c0871ae;
case 0x0c0871b0u: goto P_0c0871b0;
case 0x0c0871b2u: goto P_0c0871b2;
case 0x0c0871b4u: goto P_0c0871b4;
case 0x0c0871b6u: goto P_0c0871b6;
case 0x0c0871b8u: goto P_0c0871b8;
case 0x0c0871bau: goto P_0c0871ba;
case 0x0c0871bcu: goto P_0c0871bc;
case 0x0c0871beu: goto P_0c0871be;
case 0x0c0871c0u: goto P_0c0871c0;
case 0x0c0871c2u: goto P_0c0871c2;
case 0x0c0871c4u: goto P_0c0871c4;
case 0x0c0871c6u: goto P_0c0871c6;
case 0x0c0871c8u: goto P_0c0871c8;
case 0x0c0871cau: goto P_0c0871ca;
case 0x0c0871ccu: goto P_0c0871cc;
case 0x0c0871ceu: goto P_0c0871ce;
case 0x0c0871d0u: goto P_0c0871d0;
case 0x0c0871d2u: goto P_0c0871d2;
case 0x0c0871d4u: goto P_0c0871d4;
case 0x0c0871d6u: goto P_0c0871d6;
case 0x0c0871d8u: goto P_0c0871d8;
case 0x0c0871dau: goto P_0c0871da;
case 0x0c0871dcu: goto P_0c0871dc;
case 0x0c0871deu: goto P_0c0871de;
case 0x0c0871e0u: goto P_0c0871e0;
case 0x0c0871e2u: goto P_0c0871e2;
case 0x0c0871e4u: goto P_0c0871e4;
case 0x0c0875b0u: goto P_0c0875b0;
case 0x0c0875b2u: goto P_0c0875b2;
case 0x0c0875b4u: goto P_0c0875b4;
case 0x0c0875b6u: goto P_0c0875b6;
case 0x0c0875b8u: goto P_0c0875b8;
case 0x0c0875bau: goto P_0c0875ba;
case 0x0c0875bcu: goto P_0c0875bc;
case 0x0c0875beu: goto P_0c0875be;
case 0x0c0875c0u: goto P_0c0875c0;
case 0x0c0875c2u: goto P_0c0875c2;
case 0x0c0875c4u: goto P_0c0875c4;
case 0x0c0875c6u: goto P_0c0875c6;
case 0x0c0875c8u: goto P_0c0875c8;
case 0x0c0875cau: goto P_0c0875ca;
case 0x0c0875ccu: goto P_0c0875cc;
case 0x0c090fc0u: goto P_0c090fc0;
case 0x0c090fc2u: goto P_0c090fc2;
case 0x0c090fc4u: goto P_0c090fc4;
case 0x0c090fc6u: goto P_0c090fc6;
case 0x0c090fc8u: goto P_0c090fc8;
case 0x0c090fcau: goto P_0c090fca;
case 0x0c090fccu: goto P_0c090fcc;
case 0x0c090fceu: goto P_0c090fce;
case 0x0c090fd0u: goto P_0c090fd0;
case 0x0c090fd2u: goto P_0c090fd2;
case 0x0c090fd4u: goto P_0c090fd4;
case 0x0c090fd6u: goto P_0c090fd6;
case 0x0c090fd8u: goto P_0c090fd8;
case 0x0c090fdau: goto P_0c090fda;
case 0x0c090fdcu: goto P_0c090fdc;
case 0x0c090fdeu: goto P_0c090fde;
case 0x0c090fe0u: goto P_0c090fe0;
case 0x0c090fe2u: goto P_0c090fe2;
case 0x0c090fe4u: goto P_0c090fe4;
case 0x0c090fe6u: goto P_0c090fe6;
case 0x0c090fe8u: goto P_0c090fe8;
case 0x0c090feau: goto P_0c090fea;
case 0x0c090fecu: goto P_0c090fec;
case 0x0c090feeu: goto P_0c090fee;
case 0x0c090ff0u: goto P_0c090ff0;
case 0x0c090ff2u: goto P_0c090ff2;
case 0x0c090ff4u: goto P_0c090ff4;
case 0x0c090ff6u: goto P_0c090ff6;
case 0x0c090ff8u: goto P_0c090ff8;
case 0x0c090ffau: goto P_0c090ffa;
case 0x0c090ffcu: goto P_0c090ffc;
case 0x0c090ffeu: goto P_0c090ffe;
case 0x0c091000u: goto P_0c091000;
case 0x0c091002u: goto P_0c091002;
case 0x0c091004u: goto P_0c091004;
case 0x0c091006u: goto P_0c091006;
case 0x0c091008u: goto P_0c091008;
case 0x0c09100au: goto P_0c09100a;
case 0x0c09100cu: goto P_0c09100c;
case 0x0c09100eu: goto P_0c09100e;
case 0x0c091010u: goto P_0c091010;
case 0x0c091012u: goto P_0c091012;
case 0x0c091014u: goto P_0c091014;
case 0x0c091016u: goto P_0c091016;
case 0x0c091018u: goto P_0c091018;
case 0x0c09101au: goto P_0c09101a;
case 0x0c09101cu: goto P_0c09101c;
case 0x0c09101eu: goto P_0c09101e;
case 0x0c091020u: goto P_0c091020;
case 0x0c091022u: goto P_0c091022;
case 0x0c091024u: goto P_0c091024;
case 0x0c091026u: goto P_0c091026;
case 0x0c091048u: goto P_0c091048;
case 0x0c09104au: goto P_0c09104a;
case 0x0c09104cu: goto P_0c09104c;
case 0x0c09104eu: goto P_0c09104e;
case 0x0c091050u: goto P_0c091050;
case 0x0c091052u: goto P_0c091052;
case 0x0c091054u: goto P_0c091054;
case 0x0c091056u: goto P_0c091056;
case 0x0c091058u: goto P_0c091058;
case 0x0c09105au: goto P_0c09105a;
case 0x0c09105cu: goto P_0c09105c;
case 0x0c09105eu: goto P_0c09105e;
case 0x0c091060u: goto P_0c091060;
case 0x0c091062u: goto P_0c091062;
case 0x0c091064u: goto P_0c091064;
case 0x0c091066u: goto P_0c091066;
case 0x0c091068u: goto P_0c091068;
case 0x0c09106au: goto P_0c09106a;
case 0x0c09106cu: goto P_0c09106c;
case 0x0c09106eu: goto P_0c09106e;
case 0x0c091070u: goto P_0c091070;
case 0x0c091072u: goto P_0c091072;
case 0x0c091074u: goto P_0c091074;
case 0x0c091076u: goto P_0c091076;
case 0x0c091078u: goto P_0c091078;
case 0x0c09107au: goto P_0c09107a;
case 0x0c09107cu: goto P_0c09107c;
case 0x0c09107eu: goto P_0c09107e;
case 0x0c091080u: goto P_0c091080;
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
case 0x0c0978eeu: goto P_0c0978ee;
case 0x0c0978f0u: goto P_0c0978f0;
case 0x0c0978f2u: goto P_0c0978f2;
case 0x0c0978f4u: goto P_0c0978f4;
case 0x0c0978f6u: goto P_0c0978f6;
case 0x0c0978f8u: goto P_0c0978f8;
case 0x0c0978fau: goto P_0c0978fa;
case 0x0c0978fcu: goto P_0c0978fc;
case 0x0c0978feu: goto P_0c0978fe;
case 0x0c097900u: goto P_0c097900;
case 0x0c097902u: goto P_0c097902;
case 0x0c097904u: goto P_0c097904;
case 0x0c097906u: goto P_0c097906;
case 0x0c097908u: goto P_0c097908;
case 0x0c09790au: goto P_0c09790a;
case 0x0c09790cu: goto P_0c09790c;
case 0x0c09790eu: goto P_0c09790e;
case 0x0c097910u: goto P_0c097910;
case 0x0c09a992u: goto P_0c09a992;
case 0x0c09a994u: goto P_0c09a994;
case 0x0c09a996u: goto P_0c09a996;
case 0x0c09a998u: goto P_0c09a998;
case 0x0c09a99au: goto P_0c09a99a;
case 0x0c09a99cu: goto P_0c09a99c;
case 0x0c09a99eu: goto P_0c09a99e;
case 0x0c09a9a0u: goto P_0c09a9a0;
case 0x0c09a9a2u: goto P_0c09a9a2;
case 0x0c09a9a4u: goto P_0c09a9a4;
case 0x0c09a9a6u: goto P_0c09a9a6;
case 0x0c09a9a8u: goto P_0c09a9a8;
case 0x0c09a9aau: goto P_0c09a9aa;
case 0x0c09a9acu: goto P_0c09a9ac;
case 0x0c09a9aeu: goto P_0c09a9ae;
case 0x0c09a9b0u: goto P_0c09a9b0;
case 0x0c09a9b2u: goto P_0c09a9b2;
case 0x0c09a9b4u: goto P_0c09a9b4;
case 0x0c09a9b6u: goto P_0c09a9b6;
case 0x0c09a9b8u: goto P_0c09a9b8;
case 0x0c09a9bau: goto P_0c09a9ba;
case 0x0c09a9bcu: goto P_0c09a9bc;
case 0x0c09a9beu: goto P_0c09a9be;
case 0x0c09a9c0u: goto P_0c09a9c0;
case 0x0c09a9c2u: goto P_0c09a9c2;
case 0x0c09a9c4u: goto P_0c09a9c4;
case 0x0c09a9c6u: goto P_0c09a9c6;
case 0x0c09a9c8u: goto P_0c09a9c8;
case 0x0c09a9cau: goto P_0c09a9ca;
case 0x0c09a9ccu: goto P_0c09a9cc;
case 0x0c09a9ceu: goto P_0c09a9ce;
case 0x0c09a9d0u: goto P_0c09a9d0;
case 0x0c09a9d2u: goto P_0c09a9d2;
case 0x0c09a9d4u: goto P_0c09a9d4;
case 0x0c09a9d6u: goto P_0c09a9d6;
case 0x0c09a9d8u: goto P_0c09a9d8;
case 0x0c09a9dau: goto P_0c09a9da;
case 0x0c09a9dcu: goto P_0c09a9dc;
case 0x0c09a9deu: goto P_0c09a9de;
case 0x0c09a9e0u: goto P_0c09a9e0;
case 0x0c09a9e2u: goto P_0c09a9e2;
case 0x0c09a9e4u: goto P_0c09a9e4;
case 0x0c09a9e6u: goto P_0c09a9e6;
case 0x0c09d38eu: goto P_0c09d38e;
case 0x0c09d390u: goto P_0c09d390;
case 0x0c09d392u: goto P_0c09d392;
case 0x0c09d394u: goto P_0c09d394;
case 0x0c09d396u: goto P_0c09d396;
case 0x0c09d398u: goto P_0c09d398;
case 0x0c09d39au: goto P_0c09d39a;
case 0x0c09d39cu: goto P_0c09d39c;
case 0x0c09d39eu: goto P_0c09d39e;
case 0x0c09d3a0u: goto P_0c09d3a0;
case 0x0c09d3a2u: goto P_0c09d3a2;
case 0x0c09d3a4u: goto P_0c09d3a4;
case 0x0c09d3a6u: goto P_0c09d3a6;
case 0x0c09d3a8u: goto P_0c09d3a8;
case 0x0c09d3aau: goto P_0c09d3aa;
case 0x0c09d3acu: goto P_0c09d3ac;
case 0x0c09d3aeu: goto P_0c09d3ae;
case 0x0c09d3b0u: goto P_0c09d3b0;
case 0x0c09d3b2u: goto P_0c09d3b2;
case 0x0c09d3b4u: goto P_0c09d3b4;
case 0x0c09d3b6u: goto P_0c09d3b6;
case 0x0c09d3b8u: goto P_0c09d3b8;
case 0x0c09d3bau: goto P_0c09d3ba;
case 0x0c09d3bcu: goto P_0c09d3bc;
case 0x0c09d3beu: goto P_0c09d3be;
case 0x0c09d3c0u: goto P_0c09d3c0;
case 0x0c09d3c2u: goto P_0c09d3c2;
case 0x0c09d3c4u: goto P_0c09d3c4;
case 0x0c09d3c6u: goto P_0c09d3c6;
case 0x0c09d3c8u: goto P_0c09d3c8;
case 0x0c09d3cau: goto P_0c09d3ca;
case 0x0c09d3ccu: goto P_0c09d3cc;
case 0x0c09d3ceu: goto P_0c09d3ce;
case 0x0c09d3d0u: goto P_0c09d3d0;
case 0x0c09d3d2u: goto P_0c09d3d2;
case 0x0c09d3d4u: goto P_0c09d3d4;
case 0x0c09d3d6u: goto P_0c09d3d6;
case 0x0c09d3d8u: goto P_0c09d3d8;
case 0x0c09d3dau: goto P_0c09d3da;
case 0x0c09d3dcu: goto P_0c09d3dc;
case 0x0c09d3deu: goto P_0c09d3de;
case 0x0c09d3e0u: goto P_0c09d3e0;
case 0x0c09d3e2u: goto P_0c09d3e2;
case 0x0c09d3e4u: goto P_0c09d3e4;
case 0x0c0abad8u: goto P_0c0abad8;
case 0x0c0abadau: goto P_0c0abada;
case 0x0c0abadcu: goto P_0c0abadc;
case 0x0c0abadeu: goto P_0c0abade;
case 0x0c0abae0u: goto P_0c0abae0;
case 0x0c0abae2u: goto P_0c0abae2;
case 0x0c0abae4u: goto P_0c0abae4;
case 0x0c0abae6u: goto P_0c0abae6;
case 0x0c0abae8u: goto P_0c0abae8;
case 0x0c0abaeau: goto P_0c0abaea;
case 0x0c0abaecu: goto P_0c0abaec;
case 0x0c0abaeeu: goto P_0c0abaee;
case 0x0c0abaf0u: goto P_0c0abaf0;
case 0x0c0abaf2u: goto P_0c0abaf2;
case 0x0c0abaf4u: goto P_0c0abaf4;
case 0x0c0abaf6u: goto P_0c0abaf6;
case 0x0c0abaf8u: goto P_0c0abaf8;
case 0x0c0abafau: goto P_0c0abafa;
case 0x0c0abafcu: goto P_0c0abafc;
case 0x0c0abafeu: goto P_0c0abafe;
case 0x0c0abb00u: goto P_0c0abb00;
case 0x0c0abb02u: goto P_0c0abb02;
case 0x0c0abb04u: goto P_0c0abb04;
case 0x0c0abb06u: goto P_0c0abb06;
case 0x0c0abb08u: goto P_0c0abb08;
case 0x0c0abb0au: goto P_0c0abb0a;
case 0x0c0abb0cu: goto P_0c0abb0c;
case 0x0c0abb0eu: goto P_0c0abb0e;
case 0x0c0abb10u: goto P_0c0abb10;
case 0x0c0abb12u: goto P_0c0abb12;
case 0x0c0abb14u: goto P_0c0abb14;
case 0x0c0abb16u: goto P_0c0abb16;
case 0x0c0abb18u: goto P_0c0abb18;
case 0x0c0abb1au: goto P_0c0abb1a;
case 0x0c0abb1cu: goto P_0c0abb1c;
case 0x0c0abb1eu: goto P_0c0abb1e;
case 0x0c0abb20u: goto P_0c0abb20;
case 0x0c0abb22u: goto P_0c0abb22;
case 0x0c0abb24u: goto P_0c0abb24;
case 0x0c0abb26u: goto P_0c0abb26;
case 0x0c0abb28u: goto P_0c0abb28;
case 0x0c0abb2au: goto P_0c0abb2a;
case 0x0c0abb2cu: goto P_0c0abb2c;
case 0x0c0abb2eu: goto P_0c0abb2e;
case 0x0c0abb30u: goto P_0c0abb30;
case 0x0c0abb32u: goto P_0c0abb32;
case 0x0c0abb34u: goto P_0c0abb34;
case 0x0c0abb36u: goto P_0c0abb36;
case 0x0c0abb38u: goto P_0c0abb38;
case 0x0c0abb3au: goto P_0c0abb3a;
case 0x0c0abb3cu: goto P_0c0abb3c;
case 0x0c0abb3eu: goto P_0c0abb3e;
case 0x0c0abb40u: goto P_0c0abb40;
case 0x0c0abb42u: goto P_0c0abb42;
case 0x0c0abb44u: goto P_0c0abb44;
case 0x0c0abb46u: goto P_0c0abb46;
case 0x0c0abb48u: goto P_0c0abb48;
case 0x0c0abb4au: goto P_0c0abb4a;
case 0x0c0abb4cu: goto P_0c0abb4c;
case 0x0c0abb4eu: goto P_0c0abb4e;
case 0x0c0abb50u: goto P_0c0abb50;
case 0x0c0abb52u: goto P_0c0abb52;
case 0x0c0abb54u: goto P_0c0abb54;
case 0x0c0abb56u: goto P_0c0abb56;
case 0x0c0abb58u: goto P_0c0abb58;
case 0x0c0abb5au: goto P_0c0abb5a;
case 0x0c0abb5cu: goto P_0c0abb5c;
case 0x0c0abb5eu: goto P_0c0abb5e;
case 0x0c0abb60u: goto P_0c0abb60;
case 0x0c0abb62u: goto P_0c0abb62;
case 0x0c0abb64u: goto P_0c0abb64;
case 0x0c0abb66u: goto P_0c0abb66;
case 0x0c0abb68u: goto P_0c0abb68;
case 0x0c0abb6au: goto P_0c0abb6a;
case 0x0c0abb6cu: goto P_0c0abb6c;
case 0x0c0abb6eu: goto P_0c0abb6e;
case 0x0c0abb70u: goto P_0c0abb70;
case 0x0c0abb72u: goto P_0c0abb72;
case 0x0c0abb74u: goto P_0c0abb74;
case 0x0c0abb76u: goto P_0c0abb76;
case 0x0c0abb78u: goto P_0c0abb78;
case 0x0c0abb7au: goto P_0c0abb7a;
case 0x0c0abb7cu: goto P_0c0abb7c;
case 0x0c0abb7eu: goto P_0c0abb7e;
case 0x0c0abb80u: goto P_0c0abb80;
case 0x0c0abb82u: goto P_0c0abb82;
case 0x0c0abb84u: goto P_0c0abb84;
case 0x0c0abb86u: goto P_0c0abb86;
case 0x0c0abb88u: goto P_0c0abb88;
case 0x0c0abb8au: goto P_0c0abb8a;
case 0x0c0abb8cu: goto P_0c0abb8c;
case 0x0c0abb8eu: goto P_0c0abb8e;
case 0x0c0abb90u: goto P_0c0abb90;
case 0x0c0abb92u: goto P_0c0abb92;
case 0x0c0abb94u: goto P_0c0abb94;
case 0x0c0abb96u: goto P_0c0abb96;
case 0x0c0abb98u: goto P_0c0abb98;
case 0x0c0abb9au: goto P_0c0abb9a;
case 0x0c0abb9cu: goto P_0c0abb9c;
case 0x0c0abb9eu: goto P_0c0abb9e;
case 0x0c0abba0u: goto P_0c0abba0;
case 0x0c0abba2u: goto P_0c0abba2;
case 0x0c0abba4u: goto P_0c0abba4;
case 0x0c0abba6u: goto P_0c0abba6;
case 0x0c0abba8u: goto P_0c0abba8;
case 0x0c0abbaau: goto P_0c0abbaa;
case 0x0c0abbacu: goto P_0c0abbac;
case 0x0c0abbaeu: goto P_0c0abbae;
case 0x0c0abbb0u: goto P_0c0abbb0;
case 0x0c0abbb2u: goto P_0c0abbb2;
case 0x0c0abbb4u: goto P_0c0abbb4;
case 0x0c0abbb6u: goto P_0c0abbb6;
case 0x0c0abbb8u: goto P_0c0abbb8;
case 0x0c0c66ccu: goto P_0c0c66cc;
case 0x0c0c66ceu: goto P_0c0c66ce;
case 0x0c0c66dcu: goto P_0c0c66dc;
case 0x0c0c66deu: goto P_0c0c66de;
case 0x0c0c80a8u: goto P_0c0c80a8;
case 0x0c0c80aau: goto P_0c0c80aa;
case 0x0c0c80acu: goto P_0c0c80ac;
case 0x0c0c80aeu: goto P_0c0c80ae;
case 0x0c0c80b0u: goto P_0c0c80b0;
case 0x0c0c80b2u: goto P_0c0c80b2;
case 0x0c0c80b4u: goto P_0c0c80b4;
case 0x0c0c80b6u: goto P_0c0c80b6;
case 0x0c0c80b8u: goto P_0c0c80b8;
case 0x0c0c80bau: goto P_0c0c80ba;
case 0x0c0c80bcu: goto P_0c0c80bc;
case 0x0c0c80beu: goto P_0c0c80be;
case 0x0c0c80c0u: goto P_0c0c80c0;
case 0x0c0c80c2u: goto P_0c0c80c2;
case 0x0c0c80c4u: goto P_0c0c80c4;
case 0x0c0c80c6u: goto P_0c0c80c6;
case 0x0c0c80c8u: goto P_0c0c80c8;
case 0x0c0c80cau: goto P_0c0c80ca;
case 0x0c0c80ccu: goto P_0c0c80cc;
case 0x0c0c80ceu: goto P_0c0c80ce;
case 0x0c0c80d0u: goto P_0c0c80d0;
case 0x0c0c80d2u: goto P_0c0c80d2;
case 0x0c0c80d4u: goto P_0c0c80d4;
case 0x0c0c80d6u: goto P_0c0c80d6;
case 0x0c0c80d8u: goto P_0c0c80d8;
case 0x0c0c80dau: goto P_0c0c80da;
case 0x0c0c80dcu: goto P_0c0c80dc;
case 0x0c0c80deu: goto P_0c0c80de;
case 0x0c0c80e0u: goto P_0c0c80e0;
case 0x0c0c80e2u: goto P_0c0c80e2;
case 0x0c0c80e4u: goto P_0c0c80e4;
case 0x0c0c80e6u: goto P_0c0c80e6;
case 0x0c0c80e8u: goto P_0c0c80e8;
case 0x0c0c80eau: goto P_0c0c80ea;
case 0x0c0c80ecu: goto P_0c0c80ec;
case 0x0c0c80eeu: goto P_0c0c80ee;
case 0x0c0c80f0u: goto P_0c0c80f0;
case 0x0c0c80f2u: goto P_0c0c80f2;
case 0x0c0c80f4u: goto P_0c0c80f4;
case 0x0c0c80f6u: goto P_0c0c80f6;
case 0x0c0c80f8u: goto P_0c0c80f8;
case 0x0c0c80fau: goto P_0c0c80fa;
case 0x0c0c80fcu: goto P_0c0c80fc;
case 0x0c0c80feu: goto P_0c0c80fe;
case 0x0c0c8100u: goto P_0c0c8100;
case 0x0c0c8102u: goto P_0c0c8102;
case 0x0c0c8104u: goto P_0c0c8104;
case 0x0c0c8106u: goto P_0c0c8106;
case 0x0c0c8108u: goto P_0c0c8108;
case 0x0c0c810au: goto P_0c0c810a;
case 0x0c0c810cu: goto P_0c0c810c;
case 0x0c0c810eu: goto P_0c0c810e;
case 0x0c0c8110u: goto P_0c0c8110;
case 0x0c0c8112u: goto P_0c0c8112;
case 0x0c0c8114u: goto P_0c0c8114;
case 0x0c0c8116u: goto P_0c0c8116;
case 0x0c0c8118u: goto P_0c0c8118;
case 0x0c0c811au: goto P_0c0c811a;
case 0x0c0c811cu: goto P_0c0c811c;
case 0x0c0c811eu: goto P_0c0c811e;
case 0x0c0c8120u: goto P_0c0c8120;
case 0x0c0c8122u: goto P_0c0c8122;
case 0x0c0c8124u: goto P_0c0c8124;
case 0x0c0c8126u: goto P_0c0c8126;
case 0x0c0c8128u: goto P_0c0c8128;
case 0x0c0c812au: goto P_0c0c812a;
case 0x0c0c812cu: goto P_0c0c812c;
case 0x0c0c812eu: goto P_0c0c812e;
case 0x0c0c8130u: goto P_0c0c8130;
case 0x0c0c8132u: goto P_0c0c8132;
case 0x0c0c8134u: goto P_0c0c8134;
case 0x0c0c8136u: goto P_0c0c8136;
case 0x0c0c8138u: goto P_0c0c8138;
case 0x0c0c813au: goto P_0c0c813a;
case 0x0c0c813cu: goto P_0c0c813c;
case 0x0c0c813eu: goto P_0c0c813e;
case 0x0c0c8140u: goto P_0c0c8140;
case 0x0c0c8142u: goto P_0c0c8142;
case 0x0c0c8144u: goto P_0c0c8144;
case 0x0c0c8146u: goto P_0c0c8146;
case 0x0c0c8148u: goto P_0c0c8148;
case 0x0c0c8168u: goto P_0c0c8168;
case 0x0c0c816au: goto P_0c0c816a;
case 0x0c0c816cu: goto P_0c0c816c;
case 0x0c0c816eu: goto P_0c0c816e;
case 0x0c0c8170u: goto P_0c0c8170;
case 0x0c0c8172u: goto P_0c0c8172;
case 0x0c0c8174u: goto P_0c0c8174;
case 0x0c0c8176u: goto P_0c0c8176;
case 0x0c0c8178u: goto P_0c0c8178;
case 0x0c0c817au: goto P_0c0c817a;
case 0x0c0c817cu: goto P_0c0c817c;
case 0x0c0c817eu: goto P_0c0c817e;
case 0x0c0c8180u: goto P_0c0c8180;
case 0x0c0c8182u: goto P_0c0c8182;
case 0x0c0c8184u: goto P_0c0c8184;
case 0x0c0c8186u: goto P_0c0c8186;
case 0x0c0c8188u: goto P_0c0c8188;
case 0x0c0c818au: goto P_0c0c818a;
case 0x0c0c818cu: goto P_0c0c818c;
case 0x0c0c818eu: goto P_0c0c818e;
case 0x0c0c8190u: goto P_0c0c8190;
case 0x0c0c8192u: goto P_0c0c8192;
case 0x0c0c8194u: goto P_0c0c8194;
case 0x0c0c8196u: goto P_0c0c8196;
case 0x0c0c8198u: goto P_0c0c8198;
case 0x0c0c819au: goto P_0c0c819a;
case 0x0c0c819cu: goto P_0c0c819c;
case 0x0c0c819eu: goto P_0c0c819e;
case 0x0c0c81a0u: goto P_0c0c81a0;
case 0x0c0c81a2u: goto P_0c0c81a2;
case 0x0c0c81a4u: goto P_0c0c81a4;
case 0x0c0c81a6u: goto P_0c0c81a6;
case 0x0c0c81a8u: goto P_0c0c81a8;
case 0x0c0c81aau: goto P_0c0c81aa;
case 0x0c0c81acu: goto P_0c0c81ac;
case 0x0c0c81aeu: goto P_0c0c81ae;
case 0x0c0c81b0u: goto P_0c0c81b0;
case 0x0c0c81b2u: goto P_0c0c81b2;
case 0x0c0c81b4u: goto P_0c0c81b4;
case 0x0c0c81b6u: goto P_0c0c81b6;
case 0x0c0c81b8u: goto P_0c0c81b8;
case 0x0c0c81bau: goto P_0c0c81ba;
case 0x0c0c81bcu: goto P_0c0c81bc;
case 0x0c0c81beu: goto P_0c0c81be;
case 0x0c0c81c0u: goto P_0c0c81c0;
case 0x0c0c81c2u: goto P_0c0c81c2;
case 0x0c0c81c4u: goto P_0c0c81c4;
case 0x0c0c81c6u: goto P_0c0c81c6;
case 0x0c0c81c8u: goto P_0c0c81c8;
case 0x0c0c81cau: goto P_0c0c81ca;
case 0x0c0c81ccu: goto P_0c0c81cc;
case 0x0c0c81ceu: goto P_0c0c81ce;
case 0x0c0c81d0u: goto P_0c0c81d0;
case 0x0c0c81d2u: goto P_0c0c81d2;
case 0x0c0c81d4u: goto P_0c0c81d4;
case 0x0c0c81d6u: goto P_0c0c81d6;
case 0x0c0c81d8u: goto P_0c0c81d8;
case 0x0c0c81dau: goto P_0c0c81da;
case 0x0c0c81dcu: goto P_0c0c81dc;
case 0x0c0c81deu: goto P_0c0c81de;
case 0x0c0c81e0u: goto P_0c0c81e0;
case 0x0c0c81e2u: goto P_0c0c81e2;
case 0x0c0c81e4u: goto P_0c0c81e4;
case 0x0c0c81e6u: goto P_0c0c81e6;
case 0x0c0c81e8u: goto P_0c0c81e8;
case 0x0c0c81eau: goto P_0c0c81ea;
case 0x0c0c81ecu: goto P_0c0c81ec;
case 0x0c0c81eeu: goto P_0c0c81ee;
case 0x0c0c81f0u: goto P_0c0c81f0;
case 0x0c0c81f2u: goto P_0c0c81f2;
case 0x0c0c81f4u: goto P_0c0c81f4;
case 0x0c0c81f6u: goto P_0c0c81f6;
case 0x0c0c81f8u: goto P_0c0c81f8;
case 0x0c0c81fau: goto P_0c0c81fa;
case 0x0c0c81fcu: goto P_0c0c81fc;
case 0x0c0c81feu: goto P_0c0c81fe;
case 0x0c0c8200u: goto P_0c0c8200;
case 0x0c0c8202u: goto P_0c0c8202;
case 0x0c0c8204u: goto P_0c0c8204;
case 0x0c0c8206u: goto P_0c0c8206;
case 0x0c0c8208u: goto P_0c0c8208;
case 0x0c0c820au: goto P_0c0c820a;
case 0x0c0c820cu: goto P_0c0c820c;
case 0x0c0c820eu: goto P_0c0c820e;
case 0x0c0c8210u: goto P_0c0c8210;
case 0x0c0c8212u: goto P_0c0c8212;
case 0x0c0c8214u: goto P_0c0c8214;
case 0x0c0c8216u: goto P_0c0c8216;
case 0x0c0c8218u: goto P_0c0c8218;
case 0x0c0c821au: goto P_0c0c821a;
case 0x0c0c821cu: goto P_0c0c821c;
case 0x0c0c821eu: goto P_0c0c821e;
case 0x0c0c8220u: goto P_0c0c8220;
case 0x0c0c8222u: goto P_0c0c8222;
case 0x0c0c8224u: goto P_0c0c8224;
case 0x0c0c8226u: goto P_0c0c8226;
case 0x0c0c8228u: goto P_0c0c8228;
case 0x0c0c822au: goto P_0c0c822a;
case 0x0c0c822cu: goto P_0c0c822c;
case 0x0c0c822eu: goto P_0c0c822e;
case 0x0c0c8230u: goto P_0c0c8230;
case 0x0c0c8232u: goto P_0c0c8232;
case 0x0c0c8234u: goto P_0c0c8234;
case 0x0c0c8236u: goto P_0c0c8236;
case 0x0c0c8238u: goto P_0c0c8238;
case 0x0c0c823au: goto P_0c0c823a;
case 0x0c0c823cu: goto P_0c0c823c;
case 0x0c0c823eu: goto P_0c0c823e;
case 0x0c0c8240u: goto P_0c0c8240;
case 0x0c0c8242u: goto P_0c0c8242;
case 0x0c0c8244u: goto P_0c0c8244;
case 0x0c0c8246u: goto P_0c0c8246;
case 0x0c0c8248u: goto P_0c0c8248;
case 0x0c0c824au: goto P_0c0c824a;
case 0x0c0c824cu: goto P_0c0c824c;
case 0x0c0c824eu: goto P_0c0c824e;
case 0x0c0c82e4u: goto P_0c0c82e4;
case 0x0c0c82e6u: goto P_0c0c82e6;
case 0x0c0c82e8u: goto P_0c0c82e8;
case 0x0c0c82eau: goto P_0c0c82ea;
case 0x0c0c82ecu: goto P_0c0c82ec;
case 0x0c0c82eeu: goto P_0c0c82ee;
case 0x0c0c82f0u: goto P_0c0c82f0;
case 0x0c0c82f2u: goto P_0c0c82f2;
case 0x0c0c82f4u: goto P_0c0c82f4;
case 0x0c0c82f6u: goto P_0c0c82f6;
case 0x0c0c82f8u: goto P_0c0c82f8;
case 0x0c0c82fau: goto P_0c0c82fa;
case 0x0c0c82fcu: goto P_0c0c82fc;
case 0x0c0c82feu: goto P_0c0c82fe;
case 0x0c0c8300u: goto P_0c0c8300;
case 0x0c0c8302u: goto P_0c0c8302;
case 0x0c0c8304u: goto P_0c0c8304;
case 0x0c0c8306u: goto P_0c0c8306;
case 0x0c0c8308u: goto P_0c0c8308;
case 0x0c0c830au: goto P_0c0c830a;
case 0x0c0c830cu: goto P_0c0c830c;
case 0x0c0c830eu: goto P_0c0c830e;
case 0x0c0c8310u: goto P_0c0c8310;
case 0x0c0c8312u: goto P_0c0c8312;
case 0x0c0c8314u: goto P_0c0c8314;
case 0x0c0c8316u: goto P_0c0c8316;
case 0x0c0c8318u: goto P_0c0c8318;
case 0x0c0c831au: goto P_0c0c831a;
case 0x0c0c831cu: goto P_0c0c831c;
case 0x0c0c831eu: goto P_0c0c831e;
case 0x0c0c8320u: goto P_0c0c8320;
case 0x0c0c8322u: goto P_0c0c8322;
case 0x0c0c8324u: goto P_0c0c8324;
case 0x0c0c8326u: goto P_0c0c8326;
case 0x0c0c8328u: goto P_0c0c8328;
case 0x0c0c832au: goto P_0c0c832a;
case 0x0c0c832cu: goto P_0c0c832c;
case 0x0c0c832eu: goto P_0c0c832e;
case 0x0c0c8330u: goto P_0c0c8330;
case 0x0c0c8332u: goto P_0c0c8332;
case 0x0c0c94b2u: goto P_0c0c94b2;
case 0x0c0c94b4u: goto P_0c0c94b4;
case 0x0c0c94b6u: goto P_0c0c94b6;
case 0x0c0c94b8u: goto P_0c0c94b8;
case 0x0c0c94bau: goto P_0c0c94ba;
case 0x0c0c94bcu: goto P_0c0c94bc;
case 0x0c0c94beu: goto P_0c0c94be;
case 0x0c0c94c0u: goto P_0c0c94c0;
case 0x0c0c94c2u: goto P_0c0c94c2;
case 0x0c0c94c4u: goto P_0c0c94c4;
case 0x0c0c94c6u: goto P_0c0c94c6;
case 0x0c0c94c8u: goto P_0c0c94c8;
case 0x0c0c94cau: goto P_0c0c94ca;
case 0x0c0c94ccu: goto P_0c0c94cc;
case 0x0c0c94ceu: goto P_0c0c94ce;
case 0x0c0c94d0u: goto P_0c0c94d0;
case 0x0c0c94d2u: goto P_0c0c94d2;
case 0x0c0c94d4u: goto P_0c0c94d4;
case 0x0c0c94d6u: goto P_0c0c94d6;
case 0x0c0c94d8u: goto P_0c0c94d8;
case 0x0c0c94dau: goto P_0c0c94da;
case 0x0c0c94dcu: goto P_0c0c94dc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0356d4: /* original 4f22, guest PC 0x0c0356d4 */
if(!s->budget--) { s->failed_pc=0x0c0356d4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0356d6;
P_0c0356d6: /* original 6e43, guest PC 0x0c0356d6 */
if(!s->budget--) { s->failed_pc=0x0c0356d6u; return 0; }
r[14]=r[4];
goto P_0c0356d8;
P_0c0356d8: /* original e701, guest PC 0x0c0356d8 */
if(!s->budget--) { s->failed_pc=0x0c0356d8u; return 0; }
r[7]=0x00000001u;
goto P_0c0356da;
P_0c0356da: /* original 8f02, guest PC 0x0c0356da */
if(!s->budget--) { s->failed_pc=0x0c0356dau; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(!cond) { goto P_0c0356e2; }
goto P_0c0356de;
P_0c0356dc: /* original ed00, guest PC 0x0c0356dc */
if(!s->budget--) { s->failed_pc=0x0c0356dcu; return 0; }
r[13]=0x00000000u;
goto P_0c0356de;
P_0c0356de: /* original a001, guest PC 0x0c0356de */
if(!s->budget--) { s->failed_pc=0x0c0356deu; return 0; }
r[4]=r[7];
goto P_0c0356e4;
P_0c0356e0: /* original 6473, guest PC 0x0c0356e0 */
if(!s->budget--) { s->failed_pc=0x0c0356e0u; return 0; }
r[4]=r[7];
goto P_0c0356e2;
P_0c0356e2: /* original 64d3, guest PC 0x0c0356e2 */
if(!s->budget--) { s->failed_pc=0x0c0356e2u; return 0; }
r[4]=r[13];
goto P_0c0356e4;
P_0c0356e4: /* original 6043, guest PC 0x0c0356e4 */
if(!s->budget--) { s->failed_pc=0x0c0356e4u; return 0; }
r[0]=r[4];
goto P_0c0356e6;
P_0c0356e6: /* original 8801, guest PC 0x0c0356e6 */
if(!s->budget--) { s->failed_pc=0x0c0356e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0356e8;
P_0c0356e8: /* original 8b06, guest PC 0x0c0356e8 */
if(!s->budget--) { s->failed_pc=0x0c0356e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0356f8; }
goto P_0c0356ea;
P_0c0356ea: /* original 63e2, guest PC 0x0c0356ea */
if(!s->budget--) { s->failed_pc=0x0c0356eau; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0356ec;
P_0c0356ec: /* original e202, guest PC 0x0c0356ec */
if(!s->budget--) { s->failed_pc=0x0c0356ecu; return 0; }
r[2]=0x00000002u;
goto P_0c0356ee;
P_0c0356ee: /* original 1329, guest PC 0x0c0356ee */
if(!s->budget--) { s->failed_pc=0x0c0356eeu; return 0; }
write(ram,r[3]+36,r[2],4);
goto P_0c0356f0;
P_0c0356f0: /* original b064, guest PC 0x0c0356f0 */
if(!s->budget--) { s->failed_pc=0x0c0356f0u; return 0; }
target=0x0c0357bcu; r[16]=0x0c0356f4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0356f4u) { target=s->pc; goto dispatch; }
goto P_0c0356f4;
P_0c0356f2: /* original 64e3, guest PC 0x0c0356f2 */
if(!s->budget--) { s->failed_pc=0x0c0356f2u; return 0; }
r[4]=r[14];
goto P_0c0356f4;
P_0c0356f4: /* original a004, guest PC 0x0c0356f4 */
if(!s->budget--) { s->failed_pc=0x0c0356f4u; return 0; }
goto P_0c035700;
P_0c0356f6: /* original 0009, guest PC 0x0c0356f6 */
if(!s->budget--) { s->failed_pc=0x0c0356f6u; return 0; }
goto P_0c0356f8;
P_0c0356f8: /* original 63e2, guest PC 0x0c0356f8 */
if(!s->budget--) { s->failed_pc=0x0c0356f8u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0356fa;
P_0c0356fa: /* original 1379, guest PC 0x0c0356fa */
if(!s->budget--) { s->failed_pc=0x0c0356fau; return 0; }
write(ram,r[3]+36,r[7],4);
goto P_0c0356fc;
P_0c0356fc: /* original b00d, guest PC 0x0c0356fc */
if(!s->budget--) { s->failed_pc=0x0c0356fcu; return 0; }
target=0x0c03571au; r[16]=0x0c035700u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c035700u) { target=s->pc; goto dispatch; }
goto P_0c035700;
P_0c0356fe: /* original 64e3, guest PC 0x0c0356fe */
if(!s->budget--) { s->failed_pc=0x0c0356feu; return 0; }
r[4]=r[14];
goto P_0c035700;
P_0c035700: /* original 6403, guest PC 0x0c035700 */
if(!s->budget--) { s->failed_pc=0x0c035700u; return 0; }
r[4]=r[0];
goto P_0c035702;
P_0c035702: /* original 4411, guest PC 0x0c035702 */
if(!s->budget--) { s->failed_pc=0x0c035702u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c035704;
P_0c035704: /* original 8b02, guest PC 0x0c035704 */
if(!s->budget--) { s->failed_pc=0x0c035704u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03570c; }
goto P_0c035706;
P_0c035706: /* original bf01, guest PC 0x0c035706 */
if(!s->budget--) { s->failed_pc=0x0c035706u; return 0; }
target=0x0c03550cu; r[16]=0x0c03570au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03570au) { target=s->pc; goto dispatch; }
goto P_0c03570a;
P_0c035708: /* original 64e3, guest PC 0x0c035708 */
if(!s->budget--) { s->failed_pc=0x0c035708u; return 0; }
r[4]=r[14];
goto P_0c03570a;
P_0c03570a: /* original 6403, guest PC 0x0c03570a */
if(!s->budget--) { s->failed_pc=0x0c03570au; return 0; }
r[4]=r[0];
goto P_0c03570c;
P_0c03570c: /* original 62e2, guest PC 0x0c03570c */
if(!s->budget--) { s->failed_pc=0x0c03570cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03570e;
P_0c03570e: /* original 12d9, guest PC 0x0c03570e */
if(!s->budget--) { s->failed_pc=0x0c03570eu; return 0; }
write(ram,r[2]+36,r[13],4);
goto P_0c035710;
P_0c035710: /* original 4f26, guest PC 0x0c035710 */
if(!s->budget--) { s->failed_pc=0x0c035710u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c035712;
P_0c035712: /* original 6043, guest PC 0x0c035712 */
if(!s->budget--) { s->failed_pc=0x0c035712u; return 0; }
r[0]=r[4];
goto P_0c035714;
P_0c035714: /* original 6df6, guest PC 0x0c035714 */
if(!s->budget--) { s->failed_pc=0x0c035714u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c035716;
P_0c035716: /* original 000b, guest PC 0x0c035716 */
if(!s->budget--) { s->failed_pc=0x0c035716u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035718: /* original 6ef6, guest PC 0x0c035718 */
if(!s->budget--) { s->failed_pc=0x0c035718u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c03571a;
P_0c03571a: /* original 2fe6, guest PC 0x0c03571a */
if(!s->budget--) { s->failed_pc=0x0c03571au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03571c;
P_0c03571c: /* original 6e43, guest PC 0x0c03571c */
if(!s->budget--) { s->failed_pc=0x0c03571cu; return 0; }
r[14]=r[4];
goto P_0c03571e;
P_0c03571e: /* original 2fd6, guest PC 0x0c03571e */
if(!s->budget--) { s->failed_pc=0x0c03571eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035720;
P_0c035720: /* original 2ee8, guest PC 0x0c035720 */
if(!s->budget--) { s->failed_pc=0x0c035720u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c035722;
P_0c035722: /* original 2fc6, guest PC 0x0c035722 */
if(!s->budget--) { s->failed_pc=0x0c035722u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035724;
P_0c035724: /* original 2fb6, guest PC 0x0c035724 */
if(!s->budget--) { s->failed_pc=0x0c035724u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035726;
P_0c035726: /* original 2fa6, guest PC 0x0c035726 */
if(!s->budget--) { s->failed_pc=0x0c035726u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035728;
P_0c035728: /* original 4f22, guest PC 0x0c035728 */
if(!s->budget--) { s->failed_pc=0x0c035728u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03572a;
P_0c03572a: /* original 8d04, guest PC 0x0c03572a */
if(!s->budget--) { s->failed_pc=0x0c03572au; return 0; }
cond=r[17]&1u;
r[12]=r[5];
if(cond) { goto P_0c035736; }
goto P_0c03572e;
P_0c03572c: /* original 6c53, guest PC 0x0c03572c */
if(!s->budget--) { s->failed_pc=0x0c03572cu; return 0; }
r[12]=r[5];
goto P_0c03572e;
P_0c03572e: /* original e048, guest PC 0x0c03572e */
if(!s->budget--) { s->failed_pc=0x0c03572eu; return 0; }
r[0]=0x00000048u;
goto P_0c035730;
P_0c035730: /* original 02ed, guest PC 0x0c035730 */
if(!s->budget--) { s->failed_pc=0x0c035730u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c035732;
P_0c035732: /* original 2228, guest PC 0x0c035732 */
if(!s->budget--) { s->failed_pc=0x0c035732u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c035734;
P_0c035734: /* original 8b01, guest PC 0x0c035734 */
if(!s->budget--) { s->failed_pc=0x0c035734u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03573a; }
goto P_0c035736;
P_0c035736: /* original a03a, guest PC 0x0c035736 */
if(!s->budget--) { s->failed_pc=0x0c035736u; return 0; }
r[0]=0xfffffff6u;
goto P_0c0357ae;
P_0c035738: /* original e0f6, guest PC 0x0c035738 */
if(!s->budget--) { s->failed_pc=0x0c035738u; return 0; }
r[0]=0xfffffff6u;
goto P_0c03573a;
P_0c03573a: /* original 62e2, guest PC 0x0c03573a */
if(!s->budget--) { s->failed_pc=0x0c03573au; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03573c;
P_0c03573c: /* original 532a, guest PC 0x0c03573c */
if(!s->budget--) { s->failed_pc=0x0c03573cu; return 0; }
r[3]=read(ram,r[2]+40,4);
goto P_0c03573e;
P_0c03573e: /* original 2338, guest PC 0x0c03573e */
if(!s->budget--) { s->failed_pc=0x0c03573eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c035740;
P_0c035740: /* original 8901, guest PC 0x0c035740 */
if(!s->budget--) { s->failed_pc=0x0c035740u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035746; }
goto P_0c035742;
P_0c035742: /* original a034, guest PC 0x0c035742 */
if(!s->budget--) { s->failed_pc=0x0c035742u; return 0; }
r[0]=0x00000000u;
goto P_0c0357ae;
P_0c035744: /* original e000, guest PC 0x0c035744 */
if(!s->budget--) { s->failed_pc=0x0c035744u; return 0; }
r[0]=0x00000000u;
goto P_0c035746;
P_0c035746: /* original 5ae5, guest PC 0x0c035746 */
if(!s->budget--) { s->failed_pc=0x0c035746u; return 0; }
r[10]=read(ram,r[14]+20,4);
goto P_0c035748;
P_0c035748: /* original eb01, guest PC 0x0c035748 */
if(!s->budget--) { s->failed_pc=0x0c035748u; return 0; }
r[11]=0x00000001u;
goto P_0c03574a;
P_0c03574a: /* original 54e2, guest PC 0x0c03574a */
if(!s->budget--) { s->failed_pc=0x0c03574au; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c03574c;
P_0c03574c: /* original 53e4, guest PC 0x0c03574c */
if(!s->budget--) { s->failed_pc=0x0c03574cu; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c03574e;
P_0c03574e: /* original 3a4c, guest PC 0x0c03574e */
if(!s->budget--) { s->failed_pc=0x0c03574eu; return 0; }
r[10]+=r[4];
goto P_0c035750;
P_0c035750: /* original 343c, guest PC 0x0c035750 */
if(!s->budget--) { s->failed_pc=0x0c035750u; return 0; }
r[4]+=r[3];
goto P_0c035752;
P_0c035752: /* original 3a43, guest PC 0x0c035752 */
if(!s->budget--) { s->failed_pc=0x0c035752u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[4])!=0);
goto P_0c035754;
P_0c035754: /* original 8d08, guest PC 0x0c035754 */
if(!s->budget--) { s->failed_pc=0x0c035754u; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(cond) { goto P_0c035768; }
goto P_0c035758;
P_0c035756: /* original ed00, guest PC 0x0c035756 */
if(!s->budget--) { s->failed_pc=0x0c035756u; return 0; }
r[13]=0x00000000u;
goto P_0c035758;
P_0c035758: /* original 63c3, guest PC 0x0c035758 */
if(!s->budget--) { s->failed_pc=0x0c035758u; return 0; }
r[3]=r[12];
goto P_0c03575a;
P_0c03575a: /* original 33ac, guest PC 0x0c03575a */
if(!s->budget--) { s->failed_pc=0x0c03575au; return 0; }
r[3]+=r[10];
goto P_0c03575c;
P_0c03575c: /* original 3347, guest PC 0x0c03575c */
if(!s->budget--) { s->failed_pc=0x0c03575cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[4])!=0);
goto P_0c03575e;
P_0c03575e: /* original 8b01, guest PC 0x0c03575e */
if(!s->budget--) { s->failed_pc=0x0c03575eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c035764; }
goto P_0c035760;
P_0c035760: /* original 6c43, guest PC 0x0c035760 */
if(!s->budget--) { s->failed_pc=0x0c035760u; return 0; }
r[12]=r[4];
goto P_0c035762;
P_0c035762: /* original 3ca8, guest PC 0x0c035762 */
if(!s->budget--) { s->failed_pc=0x0c035762u; return 0; }
r[12]-=r[10];
goto P_0c035764;
P_0c035764: /* original 2cc8, guest PC 0x0c035764 */
if(!s->budget--) { s->failed_pc=0x0c035764u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c035766;
P_0c035766: /* original 8b01, guest PC 0x0c035766 */
if(!s->budget--) { s->failed_pc=0x0c035766u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03576c; }
goto P_0c035768;
P_0c035768: /* original a01e, guest PC 0x0c035768 */
if(!s->budget--) { s->failed_pc=0x0c035768u; return 0; }
write(ram,r[14]+24,r[13],4);
goto P_0c0357a8;
P_0c03576a: /* original 1ed6, guest PC 0x0c03576a */
if(!s->budget--) { s->failed_pc=0x0c03576au; return 0; }
write(ram,r[14]+24,r[13],4);
goto P_0c03576c;
P_0c03576c: /* original 63e2, guest PC 0x0c03576c */
if(!s->budget--) { s->failed_pc=0x0c03576cu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03576e;
P_0c03576e: /* original 13b9, guest PC 0x0c03576e */
if(!s->budget--) { s->failed_pc=0x0c03576eu; return 0; }
write(ram,r[3]+36,r[11],4);
goto P_0c035770;
P_0c035770: /* original 62e2, guest PC 0x0c035770 */
if(!s->budget--) { s->failed_pc=0x0c035770u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c035772;
P_0c035772: /* original 65c3, guest PC 0x0c035772 */
if(!s->budget--) { s->failed_pc=0x0c035772u; return 0; }
r[5]=r[12];
goto P_0c035774;
P_0c035774: /* original e700, guest PC 0x0c035774 */
if(!s->budget--) { s->failed_pc=0x0c035774u; return 0; }
r[7]=0x00000000u;
goto P_0c035776;
P_0c035776: /* original 5325, guest PC 0x0c035776 */
if(!s->budget--) { s->failed_pc=0x0c035776u; return 0; }
r[3]=read(ram,r[2]+20,4);
goto P_0c035778;
P_0c035778: /* original 5131, guest PC 0x0c035778 */
if(!s->budget--) { s->failed_pc=0x0c035778u; return 0; }
r[1]=read(ram,r[3]+4,4);
goto P_0c03577a;
P_0c03577a: /* original 410b, guest PC 0x0c03577a */
if(!s->budget--) { s->failed_pc=0x0c03577au; return 0; }
target=r[1];
r[16]=0x0c03577eu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03577eu) { target=s->pc; goto dispatch; }
goto P_0c03577e;
P_0c03577c: /* original 64a3, guest PC 0x0c03577c */
if(!s->budget--) { s->failed_pc=0x0c03577cu; return 0; }
r[4]=r[10];
goto P_0c03577e;
P_0c03577e: /* original 6403, guest PC 0x0c03577e */
if(!s->budget--) { s->failed_pc=0x0c03577eu; return 0; }
r[4]=r[0];
goto P_0c035780;
P_0c035780: /* original 2448, guest PC 0x0c035780 */
if(!s->budget--) { s->failed_pc=0x0c035780u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c035782;
P_0c035782: /* original 890f, guest PC 0x0c035782 */
if(!s->budget--) { s->failed_pc=0x0c035782u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0357a4; }
goto P_0c035784;
P_0c035784: /* original 62e2, guest PC 0x0c035784 */
if(!s->budget--) { s->failed_pc=0x0c035784u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c035786;
P_0c035786: /* original 12ea, guest PC 0x0c035786 */
if(!s->budget--) { s->failed_pc=0x0c035786u; return 0; }
write(ram,r[2]+40,r[14],4);
goto P_0c035788;
P_0c035788: /* original e302, guest PC 0x0c035788 */
if(!s->budget--) { s->failed_pc=0x0c035788u; return 0; }
r[3]=0x00000002u;
goto P_0c03578a;
P_0c03578a: /* original 1e4f, guest PC 0x0c03578a */
if(!s->budget--) { s->failed_pc=0x0c03578au; return 0; }
write(ram,r[14]+60,r[4],4);
goto P_0c03578c;
P_0c03578c: /* original e04c, guest PC 0x0c03578c */
if(!s->budget--) { s->failed_pc=0x0c03578cu; return 0; }
r[0]=0x0000004cu;
goto P_0c03578e;
P_0c03578e: /* original 1ec7, guest PC 0x0c03578e */
if(!s->budget--) { s->failed_pc=0x0c03578eu; return 0; }
write(ram,r[14]+28,r[12],4);
goto P_0c035790;
P_0c035790: /* original 0e35, guest PC 0x0c035790 */
if(!s->budget--) { s->failed_pc=0x0c035790u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c035792;
P_0c035792: /* original e046, guest PC 0x0c035792 */
if(!s->budget--) { s->failed_pc=0x0c035792u; return 0; }
r[0]=0x00000046u;
goto P_0c035794;
P_0c035794: /* original 0eb5, guest PC 0x0c035794 */
if(!s->budget--) { s->failed_pc=0x0c035794u; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c035796;
P_0c035796: /* original e044, guest PC 0x0c035796 */
if(!s->budget--) { s->failed_pc=0x0c035796u; return 0; }
r[0]=0x00000044u;
goto P_0c035798;
P_0c035798: /* original 0eb5, guest PC 0x0c035798 */
if(!s->budget--) { s->failed_pc=0x0c035798u; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c03579a;
P_0c03579a: /* original 1ed6, guest PC 0x0c03579a */
if(!s->budget--) { s->failed_pc=0x0c03579au; return 0; }
write(ram,r[14]+24,r[13],4);
goto P_0c03579c;
P_0c03579c: /* original 63e2, guest PC 0x0c03579c */
if(!s->budget--) { s->failed_pc=0x0c03579cu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03579e;
P_0c03579e: /* original 13d9, guest PC 0x0c03579e */
if(!s->budget--) { s->failed_pc=0x0c03579eu; return 0; }
write(ram,r[3]+36,r[13],4);
goto P_0c0357a0;
P_0c0357a0: /* original a005, guest PC 0x0c0357a0 */
if(!s->budget--) { s->failed_pc=0x0c0357a0u; return 0; }
r[0]=r[12];
goto P_0c0357ae;
P_0c0357a2: /* original 60c3, guest PC 0x0c0357a2 */
if(!s->budget--) { s->failed_pc=0x0c0357a2u; return 0; }
r[0]=r[12];
goto P_0c0357a4;
P_0c0357a4: /* original 62e2, guest PC 0x0c0357a4 */
if(!s->budget--) { s->failed_pc=0x0c0357a4u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0357a6;
P_0c0357a6: /* original 12d9, guest PC 0x0c0357a6 */
if(!s->budget--) { s->failed_pc=0x0c0357a6u; return 0; }
write(ram,r[2]+36,r[13],4);
goto P_0c0357a8;
P_0c0357a8: /* original e04c, guest PC 0x0c0357a8 */
if(!s->budget--) { s->failed_pc=0x0c0357a8u; return 0; }
r[0]=0x0000004cu;
goto P_0c0357aa;
P_0c0357aa: /* original 0eb5, guest PC 0x0c0357aa */
if(!s->budget--) { s->failed_pc=0x0c0357aau; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c0357ac;
P_0c0357ac: /* original 60d3, guest PC 0x0c0357ac */
if(!s->budget--) { s->failed_pc=0x0c0357acu; return 0; }
r[0]=r[13];
goto P_0c0357ae;
P_0c0357ae: /* original 4f26, guest PC 0x0c0357ae */
if(!s->budget--) { s->failed_pc=0x0c0357aeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0357b0;
P_0c0357b0: /* original 6af6, guest PC 0x0c0357b0 */
if(!s->budget--) { s->failed_pc=0x0c0357b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0357b2;
P_0c0357b2: /* original 6bf6, guest PC 0x0c0357b2 */
if(!s->budget--) { s->failed_pc=0x0c0357b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0357b4;
P_0c0357b4: /* original 6cf6, guest PC 0x0c0357b4 */
if(!s->budget--) { s->failed_pc=0x0c0357b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0357b6;
P_0c0357b6: /* original 6df6, guest PC 0x0c0357b6 */
if(!s->budget--) { s->failed_pc=0x0c0357b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0357b8;
P_0c0357b8: /* original 000b, guest PC 0x0c0357b8 */
if(!s->budget--) { s->failed_pc=0x0c0357b8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0357ba: /* original 6ef6, guest PC 0x0c0357ba */
if(!s->budget--) { s->failed_pc=0x0c0357bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0357bcu,s,ram);
P_0c038956: /* original 4f22, guest PC 0x0c038956 */
if(!s->budget--) { s->failed_pc=0x0c038956u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038958;
P_0c038958: /* original d31f, guest PC 0x0c038958 */
if(!s->budget--) { s->failed_pc=0x0c038958u; return 0; }
r[3]=read(ram,0x0c0389d8u,4);
goto P_0c03895a;
P_0c03895a: /* original 430b, guest PC 0x0c03895a */
if(!s->budget--) { s->failed_pc=0x0c03895au; return 0; }
target=r[3];
r[16]=0x0c03895eu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03895eu) { target=s->pc; goto dispatch; }
goto P_0c03895e;
P_0c03895c: /* original 0009, guest PC 0x0c03895c */
if(!s->budget--) { s->failed_pc=0x0c03895cu; return 0; }
goto P_0c03895e;
P_0c03895e: /* original d21d, guest PC 0x0c03895e */
if(!s->budget--) { s->failed_pc=0x0c03895eu; return 0; }
r[2]=read(ram,0x0c0389d4u,4);
goto P_0c038960;
P_0c038960: /* original dc1e, guest PC 0x0c038960 */
if(!s->budget--) { s->failed_pc=0x0c038960u; return 0; }
r[12]=read(ram,0x0c0389dcu,4);
goto P_0c038962;
P_0c038962: /* original 6e22, guest PC 0x0c038962 */
if(!s->budget--) { s->failed_pc=0x0c038962u; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c038964;
P_0c038964: /* original a00b, guest PC 0x0c038964 */
if(!s->budget--) { s->failed_pc=0x0c038964u; return 0; }
r[13]=0x00000000u;
goto P_0c03897e;
P_0c038966: /* original ed00, guest PC 0x0c038966 */
if(!s->budget--) { s->failed_pc=0x0c038966u; return 0; }
r[13]=0x00000000u;
return vf3_matrix_family(0x0c038968u,s,ram);
P_0c038970: /* original 52ea, guest PC 0x0c038970 */
if(!s->budget--) { s->failed_pc=0x0c038970u; return 0; }
r[2]=read(ram,r[14]+40,4);
goto P_0c038972;
P_0c038972: /* original 2228, guest PC 0x0c038972 */
if(!s->budget--) { s->failed_pc=0x0c038972u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c038974;
P_0c038974: /* original 8b01, guest PC 0x0c038974 */
if(!s->budget--) { s->failed_pc=0x0c038974u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03897a; }
goto P_0c038976;
P_0c038976: /* original b083, guest PC 0x0c038976 */
if(!s->budget--) { s->failed_pc=0x0c038976u; return 0; }
target=0x0c038a80u; r[16]=0x0c03897au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03897au) { target=s->pc; goto dispatch; }
goto P_0c03897a;
P_0c038978: /* original 64e3, guest PC 0x0c038978 */
if(!s->budget--) { s->failed_pc=0x0c038978u; return 0; }
r[4]=r[14];
goto P_0c03897a;
P_0c03897a: /* original 7e3c, guest PC 0x0c03897a */
if(!s->budget--) { s->failed_pc=0x0c03897au; return 0; }
r[14]+=0x0000003cu;
goto P_0c03897c;
P_0c03897c: /* original 7d01, guest PC 0x0c03897c */
if(!s->budget--) { s->failed_pc=0x0c03897cu; return 0; }
r[13]+=0x00000001u;
goto P_0c03897e;
P_0c03897e: /* original 62c2, guest PC 0x0c03897e */
if(!s->budget--) { s->failed_pc=0x0c03897eu; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c038980;
P_0c038980: /* original 3d23, guest PC 0x0c038980 */
if(!s->budget--) { s->failed_pc=0x0c038980u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[2])!=0);
goto P_0c038982;
P_0c038982: /* original 8bf5, guest PC 0x0c038982 */
if(!s->budget--) { s->failed_pc=0x0c038982u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038970; }
goto P_0c038984;
P_0c038984: /* original 4f26, guest PC 0x0c038984 */
if(!s->budget--) { s->failed_pc=0x0c038984u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038986;
P_0c038986: /* original 6cf6, guest PC 0x0c038986 */
if(!s->budget--) { s->failed_pc=0x0c038986u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c038988;
P_0c038988: /* original 6df6, guest PC 0x0c038988 */
if(!s->budget--) { s->failed_pc=0x0c038988u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03898a;
P_0c03898a: /* original 000b, guest PC 0x0c03898a */
if(!s->budget--) { s->failed_pc=0x0c03898au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03898c: /* original 6ef6, guest PC 0x0c03898c */
if(!s->budget--) { s->failed_pc=0x0c03898cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03898eu,s,ram);
P_0c03f5a0: /* original 2fe6, guest PC 0x0c03f5a0 */
if(!s->budget--) { s->failed_pc=0x0c03f5a0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5a2;
P_0c03f5a2: /* original e300, guest PC 0x0c03f5a2 */
if(!s->budget--) { s->failed_pc=0x0c03f5a2u; return 0; }
r[3]=0x00000000u;
goto P_0c03f5a4;
P_0c03f5a4: /* original 2fd6, guest PC 0x0c03f5a4 */
if(!s->budget--) { s->failed_pc=0x0c03f5a4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5a6;
P_0c03f5a6: /* original 2fc6, guest PC 0x0c03f5a6 */
if(!s->budget--) { s->failed_pc=0x0c03f5a6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5a8;
P_0c03f5a8: /* original 6c43, guest PC 0x0c03f5a8 */
if(!s->budget--) { s->failed_pc=0x0c03f5a8u; return 0; }
r[12]=r[4];
goto P_0c03f5aa;
P_0c03f5aa: /* original 2fb6, guest PC 0x0c03f5aa */
if(!s->budget--) { s->failed_pc=0x0c03f5aau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5ac;
P_0c03f5ac: /* original 2fa6, guest PC 0x0c03f5ac */
if(!s->budget--) { s->failed_pc=0x0c03f5acu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5ae;
P_0c03f5ae: /* original 2f96, guest PC 0x0c03f5ae */
if(!s->budget--) { s->failed_pc=0x0c03f5aeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5b0;
P_0c03f5b0: /* original 2f86, guest PC 0x0c03f5b0 */
if(!s->budget--) { s->failed_pc=0x0c03f5b0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5b2;
P_0c03f5b2: /* original 4f22, guest PC 0x0c03f5b2 */
if(!s->budget--) { s->failed_pc=0x0c03f5b2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f5b4;
P_0c03f5b4: /* original 4f12, guest PC 0x0c03f5b4 */
if(!s->budget--) { s->failed_pc=0x0c03f5b4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03f5b6;
P_0c03f5b6: /* original 7ffc, guest PC 0x0c03f5b6 */
if(!s->budget--) { s->failed_pc=0x0c03f5b6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03f5b8;
P_0c03f5b8: /* original 2f32, guest PC 0x0c03f5b8 */
if(!s->budget--) { s->failed_pc=0x0c03f5b8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c03f5ba;
P_0c03f5ba: /* original d37a, guest PC 0x0c03f5ba */
if(!s->budget--) { s->failed_pc=0x0c03f5bau; return 0; }
r[3]=read(ram,0x0c03f7a4u,4);
goto P_0c03f5bc;
P_0c03f5bc: /* original de78, guest PC 0x0c03f5bc */
if(!s->budget--) { s->failed_pc=0x0c03f5bcu; return 0; }
r[14]=read(ram,0x0c03f7a0u,4);
goto P_0c03f5be;
P_0c03f5be: /* original d974, guest PC 0x0c03f5be */
if(!s->budget--) { s->failed_pc=0x0c03f5beu; return 0; }
r[9]=read(ram,0x0c03f790u,4);
goto P_0c03f5c0;
P_0c03f5c0: /* original a052, guest PC 0x0c03f5c0 */
if(!s->budget--) { s->failed_pc=0x0c03f5c0u; return 0; }
tmp=read(ram,r[3],4);
r[11]=tmp;
goto P_0c03f668;
P_0c03f5c2: /* original 6b32, guest PC 0x0c03f5c2 */
if(!s->budget--) { s->failed_pc=0x0c03f5c2u; return 0; }
tmp=read(ram,r[3],4);
r[11]=tmp;
return vf3_matrix_family(0x0c03f5c4u,s,ram);
P_0c03f5d0: /* original 6db3, guest PC 0x0c03f5d0 */
if(!s->budget--) { s->failed_pc=0x0c03f5d0u; return 0; }
r[13]=r[11];
goto P_0c03f5d2;
P_0c03f5d2: /* original 63e2, guest PC 0x0c03f5d2 */
if(!s->budget--) { s->failed_pc=0x0c03f5d2u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c03f5d4;
P_0c03f5d4: /* original 4d08, guest PC 0x0c03f5d4 */
if(!s->budget--) { s->failed_pc=0x0c03f5d4u; return 0; }
r[13]<<=2;
goto P_0c03f5d6;
P_0c03f5d6: /* original 4d00, guest PC 0x0c03f5d6 */
if(!s->budget--) { s->failed_pc=0x0c03f5d6u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c03f5d8;
P_0c03f5d8: /* original 33dc, guest PC 0x0c03f5d8 */
if(!s->budget--) { s->failed_pc=0x0c03f5d8u; return 0; }
r[3]+=r[13];
goto P_0c03f5da;
P_0c03f5da: /* original 6232, guest PC 0x0c03f5da */
if(!s->budget--) { s->failed_pc=0x0c03f5dau; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c03f5dc;
P_0c03f5dc: /* original 2228, guest PC 0x0c03f5dc */
if(!s->budget--) { s->failed_pc=0x0c03f5dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03f5de;
P_0c03f5de: /* original 8f09, guest PC 0x0c03f5de */
if(!s->budget--) { s->failed_pc=0x0c03f5deu; return 0; }
cond=r[17]&1u;
r[4]=r[11];
if(!cond) { goto P_0c03f5f4; }
goto P_0c03f5e2;
P_0c03f5e0: /* original 64b3, guest PC 0x0c03f5e0 */
if(!s->budget--) { s->failed_pc=0x0c03f5e0u; return 0; }
r[4]=r[11];
goto P_0c03f5e2;
P_0c03f5e2: /* original 62e2, guest PC 0x0c03f5e2 */
if(!s->budget--) { s->failed_pc=0x0c03f5e2u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f5e4;
P_0c03f5e4: /* original e104, guest PC 0x0c03f5e4 */
if(!s->budget--) { s->failed_pc=0x0c03f5e4u; return 0; }
r[1]=0x00000004u;
goto P_0c03f5e6;
P_0c03f5e6: /* original d370, guest PC 0x0c03f5e6 */
if(!s->budget--) { s->failed_pc=0x0c03f5e6u; return 0; }
r[3]=read(ram,0x0c03f7a8u,4);
goto P_0c03f5e8;
P_0c03f5e8: /* original 32dc, guest PC 0x0c03f5e8 */
if(!s->budget--) { s->failed_pc=0x0c03f5e8u; return 0; }
r[2]+=r[13];
goto P_0c03f5ea;
P_0c03f5ea: /* original 312c, guest PC 0x0c03f5ea */
if(!s->budget--) { s->failed_pc=0x0c03f5eau; return 0; }
r[1]+=r[2];
goto P_0c03f5ec;
P_0c03f5ec: /* original 430b, guest PC 0x0c03f5ec */
if(!s->budget--) { s->failed_pc=0x0c03f5ecu; return 0; }
target=r[3];
r[16]=0x0c03f5f0u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f5f0u) { target=s->pc; goto dispatch; }
goto P_0c03f5f0;
P_0c03f5ee: /* original 2f16, guest PC 0x0c03f5ee */
if(!s->budget--) { s->failed_pc=0x0c03f5eeu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f5f0;
P_0c03f5f0: /* original 63f6, guest PC 0x0c03f5f0 */
if(!s->budget--) { s->failed_pc=0x0c03f5f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c03f5f2;
P_0c03f5f2: /* original 2302, guest PC 0x0c03f5f2 */
if(!s->budget--) { s->failed_pc=0x0c03f5f2u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c03f5f4;
P_0c03f5f4: /* original 62e2, guest PC 0x0c03f5f4 */
if(!s->budget--) { s->failed_pc=0x0c03f5f4u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f5f6;
P_0c03f5f6: /* original ea3c, guest PC 0x0c03f5f6 */
if(!s->budget--) { s->failed_pc=0x0c03f5f6u; return 0; }
r[10]=0x0000003cu;
goto P_0c03f5f8;
P_0c03f5f8: /* original 68b3, guest PC 0x0c03f5f8 */
if(!s->budget--) { s->failed_pc=0x0c03f5f8u; return 0; }
r[8]=r[11];
goto P_0c03f5fa;
P_0c03f5fa: /* original 4800, guest PC 0x0c03f5fa */
if(!s->budget--) { s->failed_pc=0x0c03f5fau; return 0; }
r[17]=(r[17]&~1u)|((r[8]>>31)!=0);
r[8]<<=1;
goto P_0c03f5fc;
P_0c03f5fc: /* original 32dc, guest PC 0x0c03f5fc */
if(!s->budget--) { s->failed_pc=0x0c03f5fcu; return 0; }
r[2]+=r[13];
goto P_0c03f5fe;
P_0c03f5fe: /* original 6322, guest PC 0x0c03f5fe */
if(!s->budget--) { s->failed_pc=0x0c03f5feu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f600;
P_0c03f600: /* original 7301, guest PC 0x0c03f600 */
if(!s->budget--) { s->failed_pc=0x0c03f600u; return 0; }
r[3]+=0x00000001u;
goto P_0c03f602;
P_0c03f602: /* original 2232, guest PC 0x0c03f602 */
if(!s->budget--) { s->failed_pc=0x0c03f602u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c03f604;
P_0c03f604: /* original 62e2, guest PC 0x0c03f604 */
if(!s->budget--) { s->failed_pc=0x0c03f604u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f606;
P_0c03f606: /* original 6192, guest PC 0x0c03f606 */
if(!s->budget--) { s->failed_pc=0x0c03f606u; return 0; }
tmp=read(ram,r[9],4);
r[1]=tmp;
goto P_0c03f608;
P_0c03f608: /* original 32dc, guest PC 0x0c03f608 */
if(!s->budget--) { s->failed_pc=0x0c03f608u; return 0; }
r[2]+=r[13];
goto P_0c03f60a;
P_0c03f60a: /* original 5d21, guest PC 0x0c03f60a */
if(!s->budget--) { s->failed_pc=0x0c03f60au; return 0; }
r[13]=read(ram,r[2]+4,4);
goto P_0c03f60c;
P_0c03f60c: /* original 381c, guest PC 0x0c03f60c */
if(!s->budget--) { s->failed_pc=0x0c03f60cu; return 0; }
r[8]+=r[1];
goto P_0c03f60e;
P_0c03f60e: /* original d267, guest PC 0x0c03f60e */
if(!s->budget--) { s->failed_pc=0x0c03f60eu; return 0; }
r[2]=read(ram,0x0c03f7acu,4);
goto P_0c03f610;
P_0c03f610: /* original 0da7, guest PC 0x0c03f610 */
if(!s->budget--) { s->failed_pc=0x0c03f610u; return 0; }
r[19]=r[13]*r[10];
goto P_0c03f612;
P_0c03f612: /* original 6081, guest PC 0x0c03f612 */
if(!s->budget--) { s->failed_pc=0x0c03f612u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[8],2);
r[0]=tmp;
goto P_0c03f614;
P_0c03f614: /* original 6322, guest PC 0x0c03f614 */
if(!s->budget--) { s->failed_pc=0x0c03f614u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f616;
P_0c03f616: /* original 88ff, guest PC 0x0c03f616 */
if(!s->budget--) { s->failed_pc=0x0c03f616u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03f618;
P_0c03f618: /* original 0a1a, guest PC 0x0c03f618 */
if(!s->budget--) { s->failed_pc=0x0c03f618u; return 0; }
r[10]=r[19];
goto P_0c03f61a;
P_0c03f61a: /* original 8f03, guest PC 0x0c03f61a */
if(!s->budget--) { s->failed_pc=0x0c03f61au; return 0; }
cond=r[17]&1u;
r[10]+=r[3];
if(!cond) { goto P_0c03f624; }
goto P_0c03f61e;
P_0c03f61c: /* original 3a3c, guest PC 0x0c03f61c */
if(!s->budget--) { s->failed_pc=0x0c03f61cu; return 0; }
r[10]+=r[3];
goto P_0c03f61e;
P_0c03f61e: /* original b367, guest PC 0x0c03f61e */
if(!s->budget--) { s->failed_pc=0x0c03f61eu; return 0; }
target=0x0c03fcf0u; r[16]=0x0c03f622u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f622u) { target=s->pc; goto dispatch; }
goto P_0c03f622;
P_0c03f620: /* original 0009, guest PC 0x0c03f620 */
if(!s->budget--) { s->failed_pc=0x0c03f620u; return 0; }
goto P_0c03f622;
P_0c03f622: /* original 2801, guest PC 0x0c03f622 */
if(!s->budget--) { s->failed_pc=0x0c03f622u; return 0; }
write(ram,r[8],r[0],2);
goto P_0c03f624;
P_0c03f624: /* original 60b3, guest PC 0x0c03f624 */
if(!s->budget--) { s->failed_pc=0x0c03f624u; return 0; }
r[0]=r[11];
goto P_0c03f626;
P_0c03f626: /* original 0009, guest PC 0x0c03f626 */
if(!s->budget--) { s->failed_pc=0x0c03f626u; return 0; }
goto P_0c03f628;
P_0c03f628: /* original 6392, guest PC 0x0c03f628 */
if(!s->budget--) { s->failed_pc=0x0c03f628u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c03f62a;
P_0c03f62a: /* original 4000, guest PC 0x0c03f62a */
if(!s->budget--) { s->failed_pc=0x0c03f62au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c03f62c;
P_0c03f62c: /* original 083d, guest PC 0x0c03f62c */
if(!s->budget--) { s->failed_pc=0x0c03f62cu; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c03f62e;
P_0c03f62e: /* original 53ab, guest PC 0x0c03f62e */
if(!s->budget--) { s->failed_pc=0x0c03f62eu; return 0; }
r[3]=read(ram,r[10]+44,4);
goto P_0c03f630;
P_0c03f630: /* original 2338, guest PC 0x0c03f630 */
if(!s->budget--) { s->failed_pc=0x0c03f630u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03f632;
P_0c03f632: /* original 8b0b, guest PC 0x0c03f632 */
if(!s->budget--) { s->failed_pc=0x0c03f632u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f64c; }
goto P_0c03f634;
P_0c03f634: /* original d35e, guest PC 0x0c03f634 */
if(!s->budget--) { s->failed_pc=0x0c03f634u; return 0; }
r[3]=read(ram,0x0c03f7b0u,4);
goto P_0c03f636;
P_0c03f636: /* original 65d3, guest PC 0x0c03f636 */
if(!s->budget--) { s->failed_pc=0x0c03f636u; return 0; }
r[5]=r[13];
goto P_0c03f638;
P_0c03f638: /* original 56c2, guest PC 0x0c03f638 */
if(!s->budget--) { s->failed_pc=0x0c03f638u; return 0; }
r[6]=read(ram,r[12]+8,4);
goto P_0c03f63a;
P_0c03f63a: /* original 430b, guest PC 0x0c03f63a */
if(!s->budget--) { s->failed_pc=0x0c03f63au; return 0; }
target=r[3];
r[16]=0x0c03f63eu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f63eu) { target=s->pc; goto dispatch; }
goto P_0c03f63e;
P_0c03f63c: /* original 64c3, guest PC 0x0c03f63c */
if(!s->budget--) { s->failed_pc=0x0c03f63cu; return 0; }
r[4]=r[12];
goto P_0c03f63e;
P_0c03f63e: /* original 62f2, guest PC 0x0c03f63e */
if(!s->budget--) { s->failed_pc=0x0c03f63eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c03f640;
P_0c03f640: /* original 220b, guest PC 0x0c03f640 */
if(!s->budget--) { s->failed_pc=0x0c03f640u; return 0; }
r[2]|=r[0];
goto P_0c03f642;
P_0c03f642: /* original 2f22, guest PC 0x0c03f642 */
if(!s->budget--) { s->failed_pc=0x0c03f642u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c03f644;
P_0c03f644: /* original d35b, guest PC 0x0c03f644 */
if(!s->budget--) { s->failed_pc=0x0c03f644u; return 0; }
r[3]=read(ram,0x0c03f7b4u,4);
goto P_0c03f646;
P_0c03f646: /* original 430b, guest PC 0x0c03f646 */
if(!s->budget--) { s->failed_pc=0x0c03f646u; return 0; }
target=r[3];
r[16]=0x0c03f64au;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f64au) { target=s->pc; goto dispatch; }
goto P_0c03f64a;
P_0c03f648: /* original 64d3, guest PC 0x0c03f648 */
if(!s->budget--) { s->failed_pc=0x0c03f648u; return 0; }
r[4]=r[13];
goto P_0c03f64a;
P_0c03f64a: /* original 1ade, guest PC 0x0c03f64a */
if(!s->budget--) { s->failed_pc=0x0c03f64au; return 0; }
write(ram,r[10]+56,r[13],4);
goto P_0c03f64c;
P_0c03f64c: /* original d253, guest PC 0x0c03f64c */
if(!s->budget--) { s->failed_pc=0x0c03f64cu; return 0; }
r[2]=read(ram,0x0c03f79cu,4);
goto P_0c03f64e;
P_0c03f64e: /* original 6483, guest PC 0x0c03f64e */
if(!s->budget--) { s->failed_pc=0x0c03f64eu; return 0; }
r[4]=r[8];
goto P_0c03f650;
P_0c03f650: /* original 4408, guest PC 0x0c03f650 */
if(!s->budget--) { s->failed_pc=0x0c03f650u; return 0; }
r[4]<<=2;
goto P_0c03f652;
P_0c03f652: /* original 65d3, guest PC 0x0c03f652 */
if(!s->budget--) { s->failed_pc=0x0c03f652u; return 0; }
r[5]=r[13];
goto P_0c03f654;
P_0c03f654: /* original 6322, guest PC 0x0c03f654 */
if(!s->budget--) { s->failed_pc=0x0c03f654u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f656;
P_0c03f656: /* original 4408, guest PC 0x0c03f656 */
if(!s->budget--) { s->failed_pc=0x0c03f656u; return 0; }
r[4]<<=2;
goto P_0c03f658;
P_0c03f658: /* original 4400, guest PC 0x0c03f658 */
if(!s->budget--) { s->failed_pc=0x0c03f658u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c03f65a;
P_0c03f65a: /* original b319, guest PC 0x0c03f65a */
if(!s->budget--) { s->failed_pc=0x0c03f65au; return 0; }
target=0x0c03fc90u; r[16]=0x0c03f65eu;
r[4]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f65eu) { target=s->pc; goto dispatch; }
goto P_0c03f65e;
P_0c03f65c: /* original 343c, guest PC 0x0c03f65c */
if(!s->budget--) { s->failed_pc=0x0c03f65cu; return 0; }
r[4]+=r[3];
goto P_0c03f65e;
P_0c03f65e: /* original 53ab, guest PC 0x0c03f65e */
if(!s->budget--) { s->failed_pc=0x0c03f65eu; return 0; }
r[3]=read(ram,r[10]+44,4);
goto P_0c03f660;
P_0c03f660: /* original 7b01, guest PC 0x0c03f660 */
if(!s->budget--) { s->failed_pc=0x0c03f660u; return 0; }
r[11]+=0x00000001u;
goto P_0c03f662;
P_0c03f662: /* original 7c10, guest PC 0x0c03f662 */
if(!s->budget--) { s->failed_pc=0x0c03f662u; return 0; }
r[12]+=0x00000010u;
goto P_0c03f664;
P_0c03f664: /* original 7301, guest PC 0x0c03f664 */
if(!s->budget--) { s->failed_pc=0x0c03f664u; return 0; }
r[3]+=0x00000001u;
goto P_0c03f666;
P_0c03f666: /* original 1a3b, guest PC 0x0c03f666 */
if(!s->budget--) { s->failed_pc=0x0c03f666u; return 0; }
write(ram,r[10]+44,r[3],4);
goto P_0c03f668;
P_0c03f668: /* original 50c1, guest PC 0x0c03f668 */
if(!s->budget--) { s->failed_pc=0x0c03f668u; return 0; }
r[0]=read(ram,r[12]+4,4);
goto P_0c03f66a;
P_0c03f66a: /* original 88ff, guest PC 0x0c03f66a */
if(!s->budget--) { s->failed_pc=0x0c03f66au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03f66c;
P_0c03f66c: /* original 8bb0, guest PC 0x0c03f66c */
if(!s->budget--) { s->failed_pc=0x0c03f66cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f5d0; }
goto P_0c03f66e;
P_0c03f66e: /* original 60f2, guest PC 0x0c03f66e */
if(!s->budget--) { s->failed_pc=0x0c03f66eu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c03f670;
P_0c03f670: /* original 7f04, guest PC 0x0c03f670 */
if(!s->budget--) { s->failed_pc=0x0c03f670u; return 0; }
r[15]+=0x00000004u;
goto P_0c03f672;
P_0c03f672: /* original 4f16, guest PC 0x0c03f672 */
if(!s->budget--) { s->failed_pc=0x0c03f672u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f674;
P_0c03f674: /* original 4f26, guest PC 0x0c03f674 */
if(!s->budget--) { s->failed_pc=0x0c03f674u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f676;
P_0c03f676: /* original 68f6, guest PC 0x0c03f676 */
if(!s->budget--) { s->failed_pc=0x0c03f676u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03f678;
P_0c03f678: /* original 69f6, guest PC 0x0c03f678 */
if(!s->budget--) { s->failed_pc=0x0c03f678u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03f67a;
P_0c03f67a: /* original 6af6, guest PC 0x0c03f67a */
if(!s->budget--) { s->failed_pc=0x0c03f67au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03f67c;
P_0c03f67c: /* original 6bf6, guest PC 0x0c03f67c */
if(!s->budget--) { s->failed_pc=0x0c03f67cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f67e;
P_0c03f67e: /* original 6cf6, guest PC 0x0c03f67e */
if(!s->budget--) { s->failed_pc=0x0c03f67eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f680;
P_0c03f680: /* original 6df6, guest PC 0x0c03f680 */
if(!s->budget--) { s->failed_pc=0x0c03f680u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f682;
P_0c03f682: /* original 000b, guest PC 0x0c03f682 */
if(!s->budget--) { s->failed_pc=0x0c03f682u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f684: /* original 6ef6, guest PC 0x0c03f684 */
if(!s->budget--) { s->failed_pc=0x0c03f684u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03f686u,s,ram);
P_0c03fcf0: /* original 2fe6, guest PC 0x0c03fcf0 */
if(!s->budget--) { s->failed_pc=0x0c03fcf0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcf2;
P_0c03fcf2: /* original 2fd6, guest PC 0x0c03fcf2 */
if(!s->budget--) { s->failed_pc=0x0c03fcf2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcf4;
P_0c03fcf4: /* original 2fb6, guest PC 0x0c03fcf4 */
if(!s->budget--) { s->failed_pc=0x0c03fcf4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcf6;
P_0c03fcf6: /* original eb00, guest PC 0x0c03fcf6 */
if(!s->budget--) { s->failed_pc=0x0c03fcf6u; return 0; }
r[11]=0x00000000u;
goto P_0c03fcf8;
P_0c03fcf8: /* original 2fa6, guest PC 0x0c03fcf8 */
if(!s->budget--) { s->failed_pc=0x0c03fcf8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcfa;
P_0c03fcfa: /* original ea01, guest PC 0x0c03fcfa */
if(!s->budget--) { s->failed_pc=0x0c03fcfau; return 0; }
r[10]=0x00000001u;
goto P_0c03fcfc;
P_0c03fcfc: /* original 2f96, guest PC 0x0c03fcfc */
if(!s->budget--) { s->failed_pc=0x0c03fcfcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03fcfe;
P_0c03fcfe: /* original e920, guest PC 0x0c03fcfe */
if(!s->budget--) { s->failed_pc=0x0c03fcfeu; return 0; }
r[9]=0x00000020u;
goto P_0c03fd00;
P_0c03fd00: /* original 2f86, guest PC 0x0c03fd00 */
if(!s->budget--) { s->failed_pc=0x0c03fd00u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
return vf3_matrix_family(0x0c03fd02u,s,ram);
P_0c04326c: /* original 4f22, guest PC 0x0c04326c */
if(!s->budget--) { s->failed_pc=0x0c04326cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04326e;
P_0c04326e: /* original 7ff8, guest PC 0x0c04326e */
if(!s->budget--) { s->failed_pc=0x0c04326eu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c043270;
P_0c043270: /* original 6ef3, guest PC 0x0c043270 */
if(!s->budget--) { s->failed_pc=0x0c043270u; return 0; }
r[14]=r[15];
goto P_0c043272;
P_0c043272: /* original 2e42, guest PC 0x0c043272 */
if(!s->budget--) { s->failed_pc=0x0c043272u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c043274;
P_0c043274: /* original 1e51, guest PC 0x0c043274 */
if(!s->budget--) { s->failed_pc=0x0c043274u; return 0; }
write(ram,r[14]+4,r[5],4);
goto P_0c043276;
P_0c043276: /* original 65e3, guest PC 0x0c043276 */
if(!s->budget--) { s->failed_pc=0x0c043276u; return 0; }
r[5]=r[14];
goto P_0c043278;
P_0c043278: /* original d32e, guest PC 0x0c043278 */
if(!s->budget--) { s->failed_pc=0x0c043278u; return 0; }
r[3]=read(ram,0x0c043334u,4);
goto P_0c04327a;
P_0c04327a: /* original 430b, guest PC 0x0c04327a */
if(!s->budget--) { s->failed_pc=0x0c04327au; return 0; }
target=r[3];
r[16]=0x0c04327eu;
r[4]=0x0000001cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04327eu) { target=s->pc; goto dispatch; }
goto P_0c04327e;
P_0c04327c: /* original e41c, guest PC 0x0c04327c */
if(!s->budget--) { s->failed_pc=0x0c04327cu; return 0; }
r[4]=0x0000001cu;
goto P_0c04327e;
P_0c04327e: /* original 7f08, guest PC 0x0c04327e */
if(!s->budget--) { s->failed_pc=0x0c04327eu; return 0; }
r[15]+=0x00000008u;
goto P_0c043280;
P_0c043280: /* original 4f26, guest PC 0x0c043280 */
if(!s->budget--) { s->failed_pc=0x0c043280u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043282;
P_0c043282: /* original 000b, guest PC 0x0c043282 */
if(!s->budget--) { s->failed_pc=0x0c043282u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c043284: /* original 6ef6, guest PC 0x0c043284 */
if(!s->budget--) { s->failed_pc=0x0c043284u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c043286u,s,ram);
P_0c0433c6: /* original 4f22, guest PC 0x0c0433c6 */
if(!s->budget--) { s->failed_pc=0x0c0433c6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0433c8;
P_0c0433c8: /* original 7ff8, guest PC 0x0c0433c8 */
if(!s->budget--) { s->failed_pc=0x0c0433c8u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0433ca;
P_0c0433ca: /* original 6ef3, guest PC 0x0c0433ca */
if(!s->budget--) { s->failed_pc=0x0c0433cau; return 0; }
r[14]=r[15];
goto P_0c0433cc;
P_0c0433cc: /* original 65e3, guest PC 0x0c0433cc */
if(!s->budget--) { s->failed_pc=0x0c0433ccu; return 0; }
r[5]=r[14];
goto P_0c0433ce;
P_0c0433ce: /* original 2e42, guest PC 0x0c0433ce */
if(!s->budget--) { s->failed_pc=0x0c0433ceu; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0433d0;
P_0c0433d0: /* original 1e31, guest PC 0x0c0433d0 */
if(!s->budget--) { s->failed_pc=0x0c0433d0u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c0433d2;
P_0c0433d2: /* original d245, guest PC 0x0c0433d2 */
if(!s->budget--) { s->failed_pc=0x0c0433d2u; return 0; }
r[2]=read(ram,0x0c0434e8u,4);
goto P_0c0433d4;
P_0c0433d4: /* original 420b, guest PC 0x0c0433d4 */
if(!s->budget--) { s->failed_pc=0x0c0433d4u; return 0; }
target=r[2];
r[16]=0x0c0433d8u;
r[4]=0x0000001bu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0433d8u) { target=s->pc; goto dispatch; }
goto P_0c0433d8;
P_0c0433d6: /* original e41b, guest PC 0x0c0433d6 */
if(!s->budget--) { s->failed_pc=0x0c0433d6u; return 0; }
r[4]=0x0000001bu;
goto P_0c0433d8;
P_0c0433d8: /* original 7f08, guest PC 0x0c0433d8 */
if(!s->budget--) { s->failed_pc=0x0c0433d8u; return 0; }
r[15]+=0x00000008u;
goto P_0c0433da;
P_0c0433da: /* original 4f26, guest PC 0x0c0433da */
if(!s->budget--) { s->failed_pc=0x0c0433dau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0433dc;
P_0c0433dc: /* original 000b, guest PC 0x0c0433dc */
if(!s->budget--) { s->failed_pc=0x0c0433dcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0433de: /* original 6ef6, guest PC 0x0c0433de */
if(!s->budget--) { s->failed_pc=0x0c0433deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0433e0u,s,ram);
P_0c04341e: /* original 4f22, guest PC 0x0c04341e */
if(!s->budget--) { s->failed_pc=0x0c04341eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043420;
P_0c043420: /* original 7ff0, guest PC 0x0c043420 */
if(!s->budget--) { s->failed_pc=0x0c043420u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c043422;
P_0c043422: /* original 6ef3, guest PC 0x0c043422 */
if(!s->budget--) { s->failed_pc=0x0c043422u; return 0; }
r[14]=r[15];
goto P_0c043424;
P_0c043424: /* original 2e42, guest PC 0x0c043424 */
if(!s->budget--) { s->failed_pc=0x0c043424u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c043426;
P_0c043426: /* original 1e51, guest PC 0x0c043426 */
if(!s->budget--) { s->failed_pc=0x0c043426u; return 0; }
write(ram,r[14]+4,r[5],4);
goto P_0c043428;
P_0c043428: /* original 65e3, guest PC 0x0c043428 */
if(!s->budget--) { s->failed_pc=0x0c043428u; return 0; }
r[5]=r[14];
goto P_0c04342a;
P_0c04342a: /* original 1e62, guest PC 0x0c04342a */
if(!s->budget--) { s->failed_pc=0x0c04342au; return 0; }
write(ram,r[14]+8,r[6],4);
goto P_0c04342c;
P_0c04342c: /* original 1e33, guest PC 0x0c04342c */
if(!s->budget--) { s->failed_pc=0x0c04342cu; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c04342e;
P_0c04342e: /* original d22e, guest PC 0x0c04342e */
if(!s->budget--) { s->failed_pc=0x0c04342eu; return 0; }
r[2]=read(ram,0x0c0434e8u,4);
goto P_0c043430;
P_0c043430: /* original 420b, guest PC 0x0c043430 */
if(!s->budget--) { s->failed_pc=0x0c043430u; return 0; }
target=r[2];
r[16]=0x0c043434u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043434u) { target=s->pc; goto dispatch; }
goto P_0c043434;
P_0c043432: /* original e414, guest PC 0x0c043432 */
if(!s->budget--) { s->failed_pc=0x0c043432u; return 0; }
r[4]=0x00000014u;
goto P_0c043434;
P_0c043434: /* original 7f10, guest PC 0x0c043434 */
if(!s->budget--) { s->failed_pc=0x0c043434u; return 0; }
r[15]+=0x00000010u;
goto P_0c043436;
P_0c043436: /* original 4f26, guest PC 0x0c043436 */
if(!s->budget--) { s->failed_pc=0x0c043436u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043438;
P_0c043438: /* original 000b, guest PC 0x0c043438 */
if(!s->budget--) { s->failed_pc=0x0c043438u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04343a: /* original 6ef6, guest PC 0x0c04343a */
if(!s->budget--) { s->failed_pc=0x0c04343au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04343cu,s,ram);
P_0c043440: /* original 4f22, guest PC 0x0c043440 */
if(!s->budget--) { s->failed_pc=0x0c043440u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043442;
P_0c043442: /* original 7ff0, guest PC 0x0c043442 */
if(!s->budget--) { s->failed_pc=0x0c043442u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c043444;
P_0c043444: /* original 6ef3, guest PC 0x0c043444 */
if(!s->budget--) { s->failed_pc=0x0c043444u; return 0; }
r[14]=r[15];
goto P_0c043446;
P_0c043446: /* original 2e42, guest PC 0x0c043446 */
if(!s->budget--) { s->failed_pc=0x0c043446u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c043448;
P_0c043448: /* original 1e51, guest PC 0x0c043448 */
if(!s->budget--) { s->failed_pc=0x0c043448u; return 0; }
write(ram,r[14]+4,r[5],4);
goto P_0c04344a;
P_0c04344a: /* original 65e3, guest PC 0x0c04344a */
if(!s->budget--) { s->failed_pc=0x0c04344au; return 0; }
r[5]=r[14];
goto P_0c04344c;
P_0c04344c: /* original 1e62, guest PC 0x0c04344c */
if(!s->budget--) { s->failed_pc=0x0c04344cu; return 0; }
write(ram,r[14]+8,r[6],4);
goto P_0c04344e;
P_0c04344e: /* original 1e33, guest PC 0x0c04344e */
if(!s->budget--) { s->failed_pc=0x0c04344eu; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c043450;
P_0c043450: /* original d225, guest PC 0x0c043450 */
if(!s->budget--) { s->failed_pc=0x0c043450u; return 0; }
r[2]=read(ram,0x0c0434e8u,4);
goto P_0c043452;
P_0c043452: /* original 420b, guest PC 0x0c043452 */
if(!s->budget--) { s->failed_pc=0x0c043452u; return 0; }
target=r[2];
r[16]=0x0c043456u;
r[4]=0x00000015u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043456u) { target=s->pc; goto dispatch; }
goto P_0c043456;
P_0c043454: /* original e415, guest PC 0x0c043454 */
if(!s->budget--) { s->failed_pc=0x0c043454u; return 0; }
r[4]=0x00000015u;
goto P_0c043456;
P_0c043456: /* original 7f10, guest PC 0x0c043456 */
if(!s->budget--) { s->failed_pc=0x0c043456u; return 0; }
r[15]+=0x00000010u;
goto P_0c043458;
P_0c043458: /* original 4f26, guest PC 0x0c043458 */
if(!s->budget--) { s->failed_pc=0x0c043458u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04345a;
P_0c04345a: /* original 000b, guest PC 0x0c04345a */
if(!s->budget--) { s->failed_pc=0x0c04345au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04345c: /* original 6ef6, guest PC 0x0c04345c */
if(!s->budget--) { s->failed_pc=0x0c04345cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04345eu,s,ram);
P_0c043472: /* original 4f22, guest PC 0x0c043472 */
if(!s->budget--) { s->failed_pc=0x0c043472u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043474;
P_0c043474: /* original 7ff8, guest PC 0x0c043474 */
if(!s->budget--) { s->failed_pc=0x0c043474u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c043476;
P_0c043476: /* original 6ef3, guest PC 0x0c043476 */
if(!s->budget--) { s->failed_pc=0x0c043476u; return 0; }
r[14]=r[15];
goto P_0c043478;
P_0c043478: /* original 65e3, guest PC 0x0c043478 */
if(!s->budget--) { s->failed_pc=0x0c043478u; return 0; }
r[5]=r[14];
goto P_0c04347a;
P_0c04347a: /* original 2e42, guest PC 0x0c04347a */
if(!s->budget--) { s->failed_pc=0x0c04347au; return 0; }
write(ram,r[14],r[4],4);
goto P_0c04347c;
P_0c04347c: /* original 1e31, guest PC 0x0c04347c */
if(!s->budget--) { s->failed_pc=0x0c04347cu; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c04347e;
P_0c04347e: /* original d21a, guest PC 0x0c04347e */
if(!s->budget--) { s->failed_pc=0x0c04347eu; return 0; }
r[2]=read(ram,0x0c0434e8u,4);
goto P_0c043480;
P_0c043480: /* original 420b, guest PC 0x0c043480 */
if(!s->budget--) { s->failed_pc=0x0c043480u; return 0; }
target=r[2];
r[16]=0x0c043484u;
r[4]=0x00000017u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c043484u) { target=s->pc; goto dispatch; }
goto P_0c043484;
P_0c043482: /* original e417, guest PC 0x0c043482 */
if(!s->budget--) { s->failed_pc=0x0c043482u; return 0; }
r[4]=0x00000017u;
goto P_0c043484;
P_0c043484: /* original 7f08, guest PC 0x0c043484 */
if(!s->budget--) { s->failed_pc=0x0c043484u; return 0; }
r[15]+=0x00000008u;
goto P_0c043486;
P_0c043486: /* original 4f26, guest PC 0x0c043486 */
if(!s->budget--) { s->failed_pc=0x0c043486u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c043488;
P_0c043488: /* original 000b, guest PC 0x0c043488 */
if(!s->budget--) { s->failed_pc=0x0c043488u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04348a: /* original 6ef6, guest PC 0x0c04348a */
if(!s->budget--) { s->failed_pc=0x0c04348au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04348cu,s,ram);
P_0c04348e: /* original 4f22, guest PC 0x0c04348e */
if(!s->budget--) { s->failed_pc=0x0c04348eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043490;
P_0c043490: /* original 7ff8, guest PC 0x0c043490 */
if(!s->budget--) { s->failed_pc=0x0c043490u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c043492;
P_0c043492: /* original 6ef3, guest PC 0x0c043492 */
if(!s->budget--) { s->failed_pc=0x0c043492u; return 0; }
r[14]=r[15];
goto P_0c043494;
P_0c043494: /* original 2e42, guest PC 0x0c043494 */
if(!s->budget--) { s->failed_pc=0x0c043494u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c043496;
P_0c043496: /* original 1e51, guest PC 0x0c043496 */
if(!s->budget--) { s->failed_pc=0x0c043496u; return 0; }
write(ram,r[14]+4,r[5],4);
goto P_0c043498;
P_0c043498: /* original 65e3, guest PC 0x0c043498 */
if(!s->budget--) { s->failed_pc=0x0c043498u; return 0; }
r[5]=r[14];
goto P_0c04349a;
P_0c04349a: /* original d313, guest PC 0x0c04349a */
if(!s->budget--) { s->failed_pc=0x0c04349au; return 0; }
r[3]=read(ram,0x0c0434e8u,4);
goto P_0c04349c;
P_0c04349c: /* original 430b, guest PC 0x0c04349c */
if(!s->budget--) { s->failed_pc=0x0c04349cu; return 0; }
target=r[3];
r[16]=0x0c0434a0u;
r[4]=0x00000013u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0434a0u) { target=s->pc; goto dispatch; }
goto P_0c0434a0;
P_0c04349e: /* original e413, guest PC 0x0c04349e */
if(!s->budget--) { s->failed_pc=0x0c04349eu; return 0; }
r[4]=0x00000013u;
goto P_0c0434a0;
P_0c0434a0: /* original 7f08, guest PC 0x0c0434a0 */
if(!s->budget--) { s->failed_pc=0x0c0434a0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0434a2;
P_0c0434a2: /* original 4f26, guest PC 0x0c0434a2 */
if(!s->budget--) { s->failed_pc=0x0c0434a2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0434a4;
P_0c0434a4: /* original 000b, guest PC 0x0c0434a4 */
if(!s->budget--) { s->failed_pc=0x0c0434a4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0434a6: /* original 6ef6, guest PC 0x0c0434a6 */
if(!s->budget--) { s->failed_pc=0x0c0434a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0434a8u,s,ram);
P_0c0434aa: /* original 4f22, guest PC 0x0c0434aa */
if(!s->budget--) { s->failed_pc=0x0c0434aau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0434ac;
P_0c0434ac: /* original 7ff0, guest PC 0x0c0434ac */
if(!s->budget--) { s->failed_pc=0x0c0434acu; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0434ae;
P_0c0434ae: /* original 6ef3, guest PC 0x0c0434ae */
if(!s->budget--) { s->failed_pc=0x0c0434aeu; return 0; }
r[14]=r[15];
goto P_0c0434b0;
P_0c0434b0: /* original 2e42, guest PC 0x0c0434b0 */
if(!s->budget--) { s->failed_pc=0x0c0434b0u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0434b2;
P_0c0434b2: /* original 1e51, guest PC 0x0c0434b2 */
if(!s->budget--) { s->failed_pc=0x0c0434b2u; return 0; }
write(ram,r[14]+4,r[5],4);
goto P_0c0434b4;
P_0c0434b4: /* original 65e3, guest PC 0x0c0434b4 */
if(!s->budget--) { s->failed_pc=0x0c0434b4u; return 0; }
r[5]=r[14];
goto P_0c0434b6;
P_0c0434b6: /* original 1e62, guest PC 0x0c0434b6 */
if(!s->budget--) { s->failed_pc=0x0c0434b6u; return 0; }
write(ram,r[14]+8,r[6],4);
goto P_0c0434b8;
P_0c0434b8: /* original 1e73, guest PC 0x0c0434b8 */
if(!s->budget--) { s->failed_pc=0x0c0434b8u; return 0; }
write(ram,r[14]+12,r[7],4);
goto P_0c0434ba;
P_0c0434ba: /* original d30b, guest PC 0x0c0434ba */
if(!s->budget--) { s->failed_pc=0x0c0434bau; return 0; }
r[3]=read(ram,0x0c0434e8u,4);
goto P_0c0434bc;
P_0c0434bc: /* original 430b, guest PC 0x0c0434bc */
if(!s->budget--) { s->failed_pc=0x0c0434bcu; return 0; }
target=r[3];
r[16]=0x0c0434c0u;
r[4]=0x0000001du;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0434c0u) { target=s->pc; goto dispatch; }
goto P_0c0434c0;
P_0c0434be: /* original e41d, guest PC 0x0c0434be */
if(!s->budget--) { s->failed_pc=0x0c0434beu; return 0; }
r[4]=0x0000001du;
goto P_0c0434c0;
P_0c0434c0: /* original 7f10, guest PC 0x0c0434c0 */
if(!s->budget--) { s->failed_pc=0x0c0434c0u; return 0; }
r[15]+=0x00000010u;
goto P_0c0434c2;
P_0c0434c2: /* original 4f26, guest PC 0x0c0434c2 */
if(!s->budget--) { s->failed_pc=0x0c0434c2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0434c4;
P_0c0434c4: /* original 000b, guest PC 0x0c0434c4 */
if(!s->budget--) { s->failed_pc=0x0c0434c4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0434c6: /* original 6ef6, guest PC 0x0c0434c6 */
if(!s->budget--) { s->failed_pc=0x0c0434c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0434c8u,s,ram);
P_0c04bbf2: /* original 4f22, guest PC 0x0c04bbf2 */
if(!s->budget--) { s->failed_pc=0x0c04bbf2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04bbf4;
P_0c04bbf4: /* original de22, guest PC 0x0c04bbf4 */
if(!s->budget--) { s->failed_pc=0x0c04bbf4u; return 0; }
r[14]=read(ram,0x0c04bc80u,4);
goto P_0c04bbf6;
P_0c04bbf6: /* original 63e2, guest PC 0x0c04bbf6 */
if(!s->budget--) { s->failed_pc=0x0c04bbf6u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c04bbf8;
P_0c04bbf8: /* original 2338, guest PC 0x0c04bbf8 */
if(!s->budget--) { s->failed_pc=0x0c04bbf8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04bbfa;
P_0c04bbfa: /* original 8901, guest PC 0x0c04bbfa */
if(!s->budget--) { s->failed_pc=0x0c04bbfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04bc00; }
goto P_0c04bbfc;
P_0c04bbfc: /* original b00a, guest PC 0x0c04bbfc */
if(!s->budget--) { s->failed_pc=0x0c04bbfcu; return 0; }
target=0x0c04bc14u; r[16]=0x0c04bc00u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04bc00u) { target=s->pc; goto dispatch; }
goto P_0c04bc00;
P_0c04bbfe: /* original 64e3, guest PC 0x0c04bbfe */
if(!s->budget--) { s->failed_pc=0x0c04bbfeu; return 0; }
r[4]=r[14];
goto P_0c04bc00;
P_0c04bc00: /* original 9235, guest PC 0x0c04bc00 */
if(!s->budget--) { s->failed_pc=0x0c04bc00u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc6eu,2);
goto P_0c04bc02;
P_0c04bc02: /* original 7d01, guest PC 0x0c04bc02 */
if(!s->budget--) { s->failed_pc=0x0c04bc02u; return 0; }
r[13]+=0x00000001u;
goto P_0c04bc04;
P_0c04bc04: /* original 3dc3, guest PC 0x0c04bc04 */
if(!s->budget--) { s->failed_pc=0x0c04bc04u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[12])!=0);
goto P_0c04bc06;
P_0c04bc06: /* original 8ff6, guest PC 0x0c04bc06 */
if(!s->budget--) { s->failed_pc=0x0c04bc06u; return 0; }
cond=r[17]&1u;
r[14]+=r[2];
if(!cond) { goto P_0c04bbf6; }
goto P_0c04bc0a;
P_0c04bc08: /* original 3e2c, guest PC 0x0c04bc08 */
if(!s->budget--) { s->failed_pc=0x0c04bc08u; return 0; }
r[14]+=r[2];
goto P_0c04bc0a;
P_0c04bc0a: /* original 4f26, guest PC 0x0c04bc0a */
if(!s->budget--) { s->failed_pc=0x0c04bc0au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04bc0c;
P_0c04bc0c: /* original 6cf6, guest PC 0x0c04bc0c */
if(!s->budget--) { s->failed_pc=0x0c04bc0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04bc0e;
P_0c04bc0e: /* original 6df6, guest PC 0x0c04bc0e */
if(!s->budget--) { s->failed_pc=0x0c04bc0eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04bc10;
P_0c04bc10: /* original 000b, guest PC 0x0c04bc10 */
if(!s->budget--) { s->failed_pc=0x0c04bc10u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04bc12: /* original 6ef6, guest PC 0x0c04bc12 */
if(!s->budget--) { s->failed_pc=0x0c04bc12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04bc14;
P_0c04bc14: /* original 2fe6, guest PC 0x0c04bc14 */
if(!s->budget--) { s->failed_pc=0x0c04bc14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bc16;
P_0c04bc16: /* original 2fd6, guest PC 0x0c04bc16 */
if(!s->budget--) { s->failed_pc=0x0c04bc16u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bc18;
P_0c04bc18: /* original 6d43, guest PC 0x0c04bc18 */
if(!s->budget--) { s->failed_pc=0x0c04bc18u; return 0; }
r[13]=r[4];
goto P_0c04bc1a;
P_0c04bc1a: /* original 2fc6, guest PC 0x0c04bc1a */
if(!s->budget--) { s->failed_pc=0x0c04bc1au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bc1c;
P_0c04bc1c: /* original ec00, guest PC 0x0c04bc1c */
if(!s->budget--) { s->failed_pc=0x0c04bc1cu; return 0; }
r[12]=0x00000000u;
goto P_0c04bc1e;
P_0c04bc1e: /* original 4f22, guest PC 0x0c04bc1e */
if(!s->budget--) { s->failed_pc=0x0c04bc1eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04bc20;
P_0c04bc20: /* original 9e26, guest PC 0x0c04bc20 */
if(!s->budget--) { s->failed_pc=0x0c04bc20u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc70u,2);
goto P_0c04bc22;
P_0c04bc22: /* original a009, guest PC 0x0c04bc22 */
if(!s->budget--) { s->failed_pc=0x0c04bc22u; return 0; }
r[14]+=r[13];
goto P_0c04bc38;
P_0c04bc24: /* original 3edc, guest PC 0x0c04bc24 */
if(!s->budget--) { s->failed_pc=0x0c04bc24u; return 0; }
r[14]+=r[13];
goto P_0c04bc26;
P_0c04bc26: /* original 52e3, guest PC 0x0c04bc26 */
if(!s->budget--) { s->failed_pc=0x0c04bc26u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c04bc28;
P_0c04bc28: /* original 2228, guest PC 0x0c04bc28 */
if(!s->budget--) { s->failed_pc=0x0c04bc28u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c04bc2a;
P_0c04bc2a: /* original 8902, guest PC 0x0c04bc2a */
if(!s->budget--) { s->failed_pc=0x0c04bc2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04bc32; }
goto P_0c04bc2c;
P_0c04bc2c: /* original 65e3, guest PC 0x0c04bc2c */
if(!s->budget--) { s->failed_pc=0x0c04bc2cu; return 0; }
r[5]=r[14];
goto P_0c04bc2e;
P_0c04bc2e: /* original bfca, guest PC 0x0c04bc2e */
if(!s->budget--) { s->failed_pc=0x0c04bc2eu; return 0; }
target=0x0c04bbc6u; r[16]=0x0c04bc32u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04bc32u) { target=s->pc; goto dispatch; }
goto P_0c04bc32;
P_0c04bc30: /* original 64d3, guest PC 0x0c04bc30 */
if(!s->budget--) { s->failed_pc=0x0c04bc30u; return 0; }
r[4]=r[13];
goto P_0c04bc32;
P_0c04bc32: /* original 9216, guest PC 0x0c04bc32 */
if(!s->budget--) { s->failed_pc=0x0c04bc32u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc62u,2);
goto P_0c04bc34;
P_0c04bc34: /* original 7c01, guest PC 0x0c04bc34 */
if(!s->budget--) { s->failed_pc=0x0c04bc34u; return 0; }
r[12]+=0x00000001u;
goto P_0c04bc36;
P_0c04bc36: /* original 3e2c, guest PC 0x0c04bc36 */
if(!s->budget--) { s->failed_pc=0x0c04bc36u; return 0; }
r[14]+=r[2];
goto P_0c04bc38;
P_0c04bc38: /* original 901b, guest PC 0x0c04bc38 */
if(!s->budget--) { s->failed_pc=0x0c04bc38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc72u,2);
goto P_0c04bc3a;
P_0c04bc3a: /* original 03de, guest PC 0x0c04bc3a */
if(!s->budget--) { s->failed_pc=0x0c04bc3au; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c04bc3c;
P_0c04bc3c: /* original 3c33, guest PC 0x0c04bc3c */
if(!s->budget--) { s->failed_pc=0x0c04bc3cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[3])!=0);
goto P_0c04bc3e;
P_0c04bc3e: /* original 8bf2, guest PC 0x0c04bc3e */
if(!s->budget--) { s->failed_pc=0x0c04bc3eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04bc26; }
goto P_0c04bc40;
P_0c04bc40: /* original 4f26, guest PC 0x0c04bc40 */
if(!s->budget--) { s->failed_pc=0x0c04bc40u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04bc42;
P_0c04bc42: /* original 64d3, guest PC 0x0c04bc42 */
if(!s->budget--) { s->failed_pc=0x0c04bc42u; return 0; }
r[4]=r[13];
goto P_0c04bc44;
P_0c04bc44: /* original d30f, guest PC 0x0c04bc44 */
if(!s->budget--) { s->failed_pc=0x0c04bc44u; return 0; }
r[3]=read(ram,0x0c04bc84u,4);
goto P_0c04bc46;
P_0c04bc46: /* original 9612, guest PC 0x0c04bc46 */
if(!s->budget--) { s->failed_pc=0x0c04bc46u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bc6eu,2);
goto P_0c04bc48;
P_0c04bc48: /* original e500, guest PC 0x0c04bc48 */
if(!s->budget--) { s->failed_pc=0x0c04bc48u; return 0; }
r[5]=0x00000000u;
goto P_0c04bc4a;
P_0c04bc4a: /* original 6cf6, guest PC 0x0c04bc4a */
if(!s->budget--) { s->failed_pc=0x0c04bc4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04bc4c;
P_0c04bc4c: /* original 6df6, guest PC 0x0c04bc4c */
if(!s->budget--) { s->failed_pc=0x0c04bc4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04bc4e;
P_0c04bc4e: /* original 432b, guest PC 0x0c04bc4e */
if(!s->budget--) { s->failed_pc=0x0c04bc4eu; return 0; }
target=r[3];
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
P_0c04bc50: /* original 6ef6, guest PC 0x0c04bc50 */
if(!s->budget--) { s->failed_pc=0x0c04bc50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04bc52u,s,ram);
P_0c04f8be: /* original 4f22, guest PC 0x0c04f8be */
if(!s->budget--) { s->failed_pc=0x0c04f8beu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f8c0;
P_0c04f8c0: /* original 7ff8, guest PC 0x0c04f8c0 */
if(!s->budget--) { s->failed_pc=0x0c04f8c0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c04f8c2;
P_0c04f8c2: /* original 2f42, guest PC 0x0c04f8c2 */
if(!s->budget--) { s->failed_pc=0x0c04f8c2u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c04f8c4;
P_0c04f8c4: /* original 1f51, guest PC 0x0c04f8c4 */
if(!s->budget--) { s->failed_pc=0x0c04f8c4u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c04f8c6;
P_0c04f8c6: /* original bfe1, guest PC 0x0c04f8c6 */
if(!s->budget--) { s->failed_pc=0x0c04f8c6u; return 0; }
target=0x0c04f88cu; r[16]=0x0c04f8cau;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f8cau) { target=s->pc; goto dispatch; }
goto P_0c04f8ca;
P_0c04f8c8: /* original 64f2, guest PC 0x0c04f8c8 */
if(!s->budget--) { s->failed_pc=0x0c04f8c8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c04f8ca;
P_0c04f8ca: /* original 6e03, guest PC 0x0c04f8ca */
if(!s->budget--) { s->failed_pc=0x0c04f8cau; return 0; }
r[14]=r[0];
goto P_0c04f8cc;
P_0c04f8cc: /* original bfde, guest PC 0x0c04f8cc */
if(!s->budget--) { s->failed_pc=0x0c04f8ccu; return 0; }
target=0x0c04f88cu; r[16]=0x0c04f8d0u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04f8d0u) { target=s->pc; goto dispatch; }
goto P_0c04f8d0;
P_0c04f8ce: /* original 54f1, guest PC 0x0c04f8ce */
if(!s->budget--) { s->failed_pc=0x0c04f8ceu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c04f8d0;
P_0c04f8d0: /* original 6403, guest PC 0x0c04f8d0 */
if(!s->budget--) { s->failed_pc=0x0c04f8d0u; return 0; }
r[4]=r[0];
goto P_0c04f8d2;
P_0c04f8d2: /* original 3e40, guest PC 0x0c04f8d2 */
if(!s->budget--) { s->failed_pc=0x0c04f8d2u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[4])!=0);
goto P_0c04f8d4;
P_0c04f8d4: /* original 8b08, guest PC 0x0c04f8d4 */
if(!s->budget--) { s->failed_pc=0x0c04f8d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f8e8; }
goto P_0c04f8d6;
P_0c04f8d6: /* original 54f1, guest PC 0x0c04f8d6 */
if(!s->budget--) { s->failed_pc=0x0c04f8d6u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c04f8d8;
P_0c04f8d8: /* original 4e15, guest PC 0x0c04f8d8 */
if(!s->budget--) { s->failed_pc=0x0c04f8d8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c04f8da;
P_0c04f8da: /* original e600, guest PC 0x0c04f8da */
if(!s->budget--) { s->failed_pc=0x0c04f8dau; return 0; }
r[6]=0x00000000u;
goto P_0c04f8dc;
P_0c04f8dc: /* original 8f0e, guest PC 0x0c04f8dc */
if(!s->budget--) { s->failed_pc=0x0c04f8dcu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[15],4);
r[5]=tmp;
if(!cond) { goto P_0c04f8fc; }
goto P_0c04f8e0;
P_0c04f8de: /* original 65f2, guest PC 0x0c04f8de */
if(!s->budget--) { s->failed_pc=0x0c04f8deu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04f8e0;
P_0c04f8e0: /* original 6340, guest PC 0x0c04f8e0 */
if(!s->budget--) { s->failed_pc=0x0c04f8e0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c04f8e2;
P_0c04f8e2: /* original 6250, guest PC 0x0c04f8e2 */
if(!s->budget--) { s->failed_pc=0x0c04f8e2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[2]=tmp;
goto P_0c04f8e4;
P_0c04f8e4: /* original 3230, guest PC 0x0c04f8e4 */
if(!s->budget--) { s->failed_pc=0x0c04f8e4u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c04f8e6;
P_0c04f8e6: /* original 8904, guest PC 0x0c04f8e6 */
if(!s->budget--) { s->failed_pc=0x0c04f8e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f8f2; }
goto P_0c04f8e8;
P_0c04f8e8: /* original 7f08, guest PC 0x0c04f8e8 */
if(!s->budget--) { s->failed_pc=0x0c04f8e8u; return 0; }
r[15]+=0x00000008u;
goto P_0c04f8ea;
P_0c04f8ea: /* original 4f26, guest PC 0x0c04f8ea */
if(!s->budget--) { s->failed_pc=0x0c04f8eau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f8ec;
P_0c04f8ec: /* original e000, guest PC 0x0c04f8ec */
if(!s->budget--) { s->failed_pc=0x0c04f8ecu; return 0; }
r[0]=0x00000000u;
goto P_0c04f8ee;
P_0c04f8ee: /* original 000b, guest PC 0x0c04f8ee */
if(!s->budget--) { s->failed_pc=0x0c04f8eeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f8f0: /* original 6ef6, guest PC 0x0c04f8f0 */
if(!s->budget--) { s->failed_pc=0x0c04f8f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04f8f2;
P_0c04f8f2: /* original 7601, guest PC 0x0c04f8f2 */
if(!s->budget--) { s->failed_pc=0x0c04f8f2u; return 0; }
r[6]+=0x00000001u;
goto P_0c04f8f4;
P_0c04f8f4: /* original 36e3, guest PC 0x0c04f8f4 */
if(!s->budget--) { s->failed_pc=0x0c04f8f4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[14])!=0);
goto P_0c04f8f6;
P_0c04f8f6: /* original 7401, guest PC 0x0c04f8f6 */
if(!s->budget--) { s->failed_pc=0x0c04f8f6u; return 0; }
r[4]+=0x00000001u;
goto P_0c04f8f8;
P_0c04f8f8: /* original 8ff2, guest PC 0x0c04f8f8 */
if(!s->budget--) { s->failed_pc=0x0c04f8f8u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(!cond) { goto P_0c04f8e0; }
goto P_0c04f8fc;
P_0c04f8fa: /* original 7501, guest PC 0x0c04f8fa */
if(!s->budget--) { s->failed_pc=0x0c04f8fau; return 0; }
r[5]+=0x00000001u;
goto P_0c04f8fc;
P_0c04f8fc: /* original e001, guest PC 0x0c04f8fc */
if(!s->budget--) { s->failed_pc=0x0c04f8fcu; return 0; }
r[0]=0x00000001u;
goto P_0c04f8fe;
P_0c04f8fe: /* original 7f08, guest PC 0x0c04f8fe */
if(!s->budget--) { s->failed_pc=0x0c04f8feu; return 0; }
r[15]+=0x00000008u;
goto P_0c04f900;
P_0c04f900: /* original 4f26, guest PC 0x0c04f900 */
if(!s->budget--) { s->failed_pc=0x0c04f900u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f902;
P_0c04f902: /* original 000b, guest PC 0x0c04f902 */
if(!s->budget--) { s->failed_pc=0x0c04f902u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f904: /* original 6ef6, guest PC 0x0c04f904 */
if(!s->budget--) { s->failed_pc=0x0c04f904u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04f906u,s,ram);
P_0c05fc14: /* original 4f22, guest PC 0x0c05fc14 */
if(!s->budget--) { s->failed_pc=0x0c05fc14u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05fc16;
P_0c05fc16: /* original d24b, guest PC 0x0c05fc16 */
if(!s->budget--) { s->failed_pc=0x0c05fc16u; return 0; }
r[2]=read(ram,0x0c05fd44u,4);
goto P_0c05fc18;
P_0c05fc18: /* original 6322, guest PC 0x0c05fc18 */
if(!s->budget--) { s->failed_pc=0x0c05fc18u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c05fc1a;
P_0c05fc1a: /* original 2338, guest PC 0x0c05fc1a */
if(!s->budget--) { s->failed_pc=0x0c05fc1au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c05fc1c;
P_0c05fc1c: /* original 8905, guest PC 0x0c05fc1c */
if(!s->budget--) { s->failed_pc=0x0c05fc1cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05fc2a; }
goto P_0c05fc1e;
P_0c05fc1e: /* original d34a, guest PC 0x0c05fc1e */
if(!s->budget--) { s->failed_pc=0x0c05fc1eu; return 0; }
r[3]=read(ram,0x0c05fd48u,4);
goto P_0c05fc20;
P_0c05fc20: /* original 430b, guest PC 0x0c05fc20 */
if(!s->budget--) { s->failed_pc=0x0c05fc20u; return 0; }
target=r[3];
r[16]=0x0c05fc24u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c05fc24u) { target=s->pc; goto dispatch; }
goto P_0c05fc24;
P_0c05fc22: /* original 0009, guest PC 0x0c05fc22 */
if(!s->budget--) { s->failed_pc=0x0c05fc22u; return 0; }
goto P_0c05fc24;
P_0c05fc24: /* original d347, guest PC 0x0c05fc24 */
if(!s->budget--) { s->failed_pc=0x0c05fc24u; return 0; }
r[3]=read(ram,0x0c05fd44u,4);
goto P_0c05fc26;
P_0c05fc26: /* original e200, guest PC 0x0c05fc26 */
if(!s->budget--) { s->failed_pc=0x0c05fc26u; return 0; }
r[2]=0x00000000u;
goto P_0c05fc28;
P_0c05fc28: /* original 2322, guest PC 0x0c05fc28 */
if(!s->budget--) { s->failed_pc=0x0c05fc28u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c05fc2a;
P_0c05fc2a: /* original 4f26, guest PC 0x0c05fc2a */
if(!s->budget--) { s->failed_pc=0x0c05fc2au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05fc2c;
P_0c05fc2c: /* original 000b, guest PC 0x0c05fc2c */
if(!s->budget--) { s->failed_pc=0x0c05fc2cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05fc2e: /* original 0009, guest PC 0x0c05fc2e */
if(!s->budget--) { s->failed_pc=0x0c05fc2eu; return 0; }
return vf3_matrix_family(0x0c05fc30u,s,ram);
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
P_0c0636fe: /* original 000b, guest PC 0x0c0636fe */
if(!s->budget--) { s->failed_pc=0x0c0636feu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c063700: /* original 0009, guest PC 0x0c063700 */
if(!s->budget--) { s->failed_pc=0x0c063700u; return 0; }
return vf3_matrix_family(0x0c063702u,s,ram);
P_0c0696e6: /* original 4f22, guest PC 0x0c0696e6 */
if(!s->budget--) { s->failed_pc=0x0c0696e6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0696e8;
P_0c0696e8: /* original d337, guest PC 0x0c0696e8 */
if(!s->budget--) { s->failed_pc=0x0c0696e8u; return 0; }
r[3]=read(ram,0x0c0697c8u,4);
goto P_0c0696ea;
P_0c0696ea: /* original 7ffc, guest PC 0x0c0696ea */
if(!s->budget--) { s->failed_pc=0x0c0696eau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0696ec;
P_0c0696ec: /* original 430b, guest PC 0x0c0696ec */
if(!s->budget--) { s->failed_pc=0x0c0696ecu; return 0; }
target=r[3];
r[16]=0x0c0696f0u;
write(ram,r[15],r[4],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0696f0u) { target=s->pc; goto dispatch; }
goto P_0c0696f0;
P_0c0696ee: /* original 2f42, guest PC 0x0c0696ee */
if(!s->budget--) { s->failed_pc=0x0c0696eeu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0696f0;
P_0c0696f0: /* original f40c, guest PC 0x0c0696f0 */
if(!s->budget--) { s->failed_pc=0x0c0696f0u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0696f2;
P_0c0696f2: /* original f39d, guest PC 0x0c0696f2 */
if(!s->budget--) { s->failed_pc=0x0c0696f2u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0696f4;
P_0c0696f4: /* original f430, guest PC 0x0c0696f4 */
if(!s->budget--) { s->failed_pc=0x0c0696f4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0696f6;
P_0c0696f6: /* original d335, guest PC 0x0c0696f6 */
if(!s->budget--) { s->failed_pc=0x0c0696f6u; return 0; }
r[3]=read(ram,0x0c0697ccu,4);
goto P_0c0696f8;
P_0c0696f8: /* original 64f2, guest PC 0x0c0696f8 */
if(!s->budget--) { s->failed_pc=0x0c0696f8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0696fa;
P_0c0696fa: /* original 7f04, guest PC 0x0c0696fa */
if(!s->budget--) { s->failed_pc=0x0c0696fau; return 0; }
r[15]+=0x00000004u;
goto P_0c0696fc;
P_0c0696fc: /* original 432b, guest PC 0x0c0696fc */
if(!s->budget--) { s->failed_pc=0x0c0696fcu; return 0; }
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
P_0c0696fe: /* original 4f26, guest PC 0x0c0696fe */
if(!s->budget--) { s->failed_pc=0x0c0696feu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c069700u,s,ram);
P_0c06a348: /* original 2fe6, guest PC 0x0c06a348 */
if(!s->budget--) { s->failed_pc=0x0c06a348u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a34a;
P_0c06a34a: /* original 2fd6, guest PC 0x0c06a34a */
if(!s->budget--) { s->failed_pc=0x0c06a34au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a34c;
P_0c06a34c: /* original 2fc6, guest PC 0x0c06a34c */
if(!s->budget--) { s->failed_pc=0x0c06a34cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a34e;
P_0c06a34e: /* original 2fb6, guest PC 0x0c06a34e */
if(!s->budget--) { s->failed_pc=0x0c06a34eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a350;
P_0c06a350: /* original 2fa6, guest PC 0x0c06a350 */
if(!s->budget--) { s->failed_pc=0x0c06a350u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a352;
P_0c06a352: /* original 2f96, guest PC 0x0c06a352 */
if(!s->budget--) { s->failed_pc=0x0c06a352u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a354;
P_0c06a354: /* original 2f86, guest PC 0x0c06a354 */
if(!s->budget--) { s->failed_pc=0x0c06a354u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06a356;
P_0c06a356: /* original 9e7c, guest PC 0x0c06a356 */
if(!s->budget--) { s->failed_pc=0x0c06a356u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a452u,2);
goto P_0c06a358;
P_0c06a358: /* original dc44, guest PC 0x0c06a358 */
if(!s->budget--) { s->failed_pc=0x0c06a358u; return 0; }
r[12]=read(ram,0x0c06a46cu,4);
goto P_0c06a35a;
P_0c06a35a: /* original 907b, guest PC 0x0c06a35a */
if(!s->budget--) { s->failed_pc=0x0c06a35au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a454u,2);
goto P_0c06a35c;
P_0c06a35c: /* original 4f22, guest PC 0x0c06a35c */
if(!s->budget--) { s->failed_pc=0x0c06a35cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06a35e;
P_0c06a35e: /* original d442, guest PC 0x0c06a35e */
if(!s->budget--) { s->failed_pc=0x0c06a35eu; return 0; }
r[4]=read(ram,0x0c06a468u,4);
goto P_0c06a360;
P_0c06a360: /* original 09ce, guest PC 0x0c06a360 */
if(!s->budget--) { s->failed_pc=0x0c06a360u; return 0; }
r[9]=read(ram,r[12]+r[0],4);
goto P_0c06a362;
P_0c06a362: /* original 3e4c, guest PC 0x0c06a362 */
if(!s->budget--) { s->failed_pc=0x0c06a362u; return 0; }
r[14]+=r[4];
goto P_0c06a364;
P_0c06a364: /* original db42, guest PC 0x0c06a364 */
if(!s->budget--) { s->failed_pc=0x0c06a364u; return 0; }
r[11]=read(ram,0x0c06a470u,4);
goto P_0c06a366;
P_0c06a366: /* original 64e3, guest PC 0x0c06a366 */
if(!s->budget--) { s->failed_pc=0x0c06a366u; return 0; }
r[4]=r[14];
goto P_0c06a368;
P_0c06a368: /* original 7ff8, guest PC 0x0c06a368 */
if(!s->budget--) { s->failed_pc=0x0c06a368u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06a36a;
P_0c06a36a: /* original 4b0b, guest PC 0x0c06a36a */
if(!s->budget--) { s->failed_pc=0x0c06a36au; return 0; }
target=r[11];
r[16]=0x0c06a36eu;
r[4]+=0x00000024u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a36eu) { target=s->pc; goto dispatch; }
goto P_0c06a36e;
P_0c06a36c: /* original 7424, guest PC 0x0c06a36c */
if(!s->budget--) { s->failed_pc=0x0c06a36cu; return 0; }
r[4]+=0x00000024u;
goto P_0c06a36e;
P_0c06a36e: /* original 6a03, guest PC 0x0c06a36e */
if(!s->budget--) { s->failed_pc=0x0c06a36eu; return 0; }
r[10]=r[0];
goto P_0c06a370;
P_0c06a370: /* original dd40, guest PC 0x0c06a370 */
if(!s->budget--) { s->failed_pc=0x0c06a370u; return 0; }
r[13]=read(ram,0x0c06a474u,4);
goto P_0c06a372;
P_0c06a372: /* original 3a9c, guest PC 0x0c06a372 */
if(!s->budget--) { s->failed_pc=0x0c06a372u; return 0; }
r[10]+=r[9];
goto P_0c06a374;
P_0c06a374: /* original 64e3, guest PC 0x0c06a374 */
if(!s->budget--) { s->failed_pc=0x0c06a374u; return 0; }
r[4]=r[14];
goto P_0c06a376;
P_0c06a376: /* original 65a3, guest PC 0x0c06a376 */
if(!s->budget--) { s->failed_pc=0x0c06a376u; return 0; }
r[5]=r[10];
goto P_0c06a378;
P_0c06a378: /* original 4d0b, guest PC 0x0c06a378 */
if(!s->budget--) { s->failed_pc=0x0c06a378u; return 0; }
target=r[13];
r[16]=0x0c06a37cu;
r[4]+=0x00000024u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a37cu) { target=s->pc; goto dispatch; }
goto P_0c06a37c;
P_0c06a37a: /* original 7424, guest PC 0x0c06a37a */
if(!s->budget--) { s->failed_pc=0x0c06a37au; return 0; }
r[4]+=0x00000024u;
goto P_0c06a37c;
P_0c06a37c: /* original 64e3, guest PC 0x0c06a37c */
if(!s->budget--) { s->failed_pc=0x0c06a37cu; return 0; }
r[4]=r[14];
goto P_0c06a37e;
P_0c06a37e: /* original 6593, guest PC 0x0c06a37e */
if(!s->budget--) { s->failed_pc=0x0c06a37eu; return 0; }
r[5]=r[9];
goto P_0c06a380;
P_0c06a380: /* original b9a1, guest PC 0x0c06a380 */
if(!s->budget--) { s->failed_pc=0x0c06a380u; return 0; }
target=0x0c0696c6u; r[16]=0x0c06a384u;
r[4]+=0x00000030u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a384u) { target=s->pc; goto dispatch; }
goto P_0c06a384;
P_0c06a382: /* original 7430, guest PC 0x0c06a382 */
if(!s->budget--) { s->failed_pc=0x0c06a382u; return 0; }
r[4]+=0x00000030u;
goto P_0c06a384;
P_0c06a384: /* original 9067, guest PC 0x0c06a384 */
if(!s->budget--) { s->failed_pc=0x0c06a384u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a456u,2);
goto P_0c06a386;
P_0c06a386: /* original 64e3, guest PC 0x0c06a386 */
if(!s->budget--) { s->failed_pc=0x0c06a386u; return 0; }
r[4]=r[14];
goto P_0c06a388;
P_0c06a388: /* original 02ce, guest PC 0x0c06a388 */
if(!s->budget--) { s->failed_pc=0x0c06a388u; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c06a38a;
P_0c06a38a: /* original 2f22, guest PC 0x0c06a38a */
if(!s->budget--) { s->failed_pc=0x0c06a38au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c06a38c;
P_0c06a38c: /* original 4b0b, guest PC 0x0c06a38c */
if(!s->budget--) { s->failed_pc=0x0c06a38cu; return 0; }
target=r[11];
r[16]=0x0c06a390u;
r[4]+=0x0000001cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a390u) { target=s->pc; goto dispatch; }
goto P_0c06a390;
P_0c06a38e: /* original 741c, guest PC 0x0c06a38e */
if(!s->budget--) { s->failed_pc=0x0c06a38eu; return 0; }
r[4]+=0x0000001cu;
goto P_0c06a390;
P_0c06a390: /* original 64e3, guest PC 0x0c06a390 */
if(!s->budget--) { s->failed_pc=0x0c06a390u; return 0; }
r[4]=r[14];
goto P_0c06a392;
P_0c06a392: /* original 6903, guest PC 0x0c06a392 */
if(!s->budget--) { s->failed_pc=0x0c06a392u; return 0; }
r[9]=r[0];
goto P_0c06a394;
P_0c06a394: /* original 4b0b, guest PC 0x0c06a394 */
if(!s->budget--) { s->failed_pc=0x0c06a394u; return 0; }
target=r[11];
r[16]=0x0c06a398u;
r[4]+=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a398u) { target=s->pc; goto dispatch; }
goto P_0c06a398;
P_0c06a396: /* original 7434, guest PC 0x0c06a396 */
if(!s->budget--) { s->failed_pc=0x0c06a396u; return 0; }
r[4]+=0x00000034u;
goto P_0c06a398;
P_0c06a398: /* original 63f2, guest PC 0x0c06a398 */
if(!s->budget--) { s->failed_pc=0x0c06a398u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06a39a;
P_0c06a39a: /* original 6803, guest PC 0x0c06a39a */
if(!s->budget--) { s->failed_pc=0x0c06a39au; return 0; }
r[8]=r[0];
goto P_0c06a39c;
P_0c06a39c: /* original 2338, guest PC 0x0c06a39c */
if(!s->budget--) { s->failed_pc=0x0c06a39cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c06a39e;
P_0c06a39e: /* original 8905, guest PC 0x0c06a39e */
if(!s->budget--) { s->failed_pc=0x0c06a39eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06a3ac; }
goto P_0c06a3a0;
P_0c06a3a0: /* original 63f2, guest PC 0x0c06a3a0 */
if(!s->budget--) { s->failed_pc=0x0c06a3a0u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06a3a2;
P_0c06a3a2: /* original 64e3, guest PC 0x0c06a3a2 */
if(!s->budget--) { s->failed_pc=0x0c06a3a2u; return 0; }
r[4]=r[14];
goto P_0c06a3a4;
P_0c06a3a4: /* original 383c, guest PC 0x0c06a3a4 */
if(!s->budget--) { s->failed_pc=0x0c06a3a4u; return 0; }
r[8]+=r[3];
goto P_0c06a3a6;
P_0c06a3a6: /* original 6583, guest PC 0x0c06a3a6 */
if(!s->budget--) { s->failed_pc=0x0c06a3a6u; return 0; }
r[5]=r[8];
goto P_0c06a3a8;
P_0c06a3a8: /* original 4d0b, guest PC 0x0c06a3a8 */
if(!s->budget--) { s->failed_pc=0x0c06a3a8u; return 0; }
target=r[13];
r[16]=0x0c06a3acu;
r[4]+=0x00000034u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a3acu) { target=s->pc; goto dispatch; }
goto P_0c06a3ac;
P_0c06a3aa: /* original 7434, guest PC 0x0c06a3aa */
if(!s->budget--) { s->failed_pc=0x0c06a3aau; return 0; }
r[4]+=0x00000034u;
goto P_0c06a3ac;
P_0c06a3ac: /* original 3988, guest PC 0x0c06a3ac */
if(!s->budget--) { s->failed_pc=0x0c06a3acu; return 0; }
r[9]-=r[8];
goto P_0c06a3ae;
P_0c06a3ae: /* original 64e3, guest PC 0x0c06a3ae */
if(!s->budget--) { s->failed_pc=0x0c06a3aeu; return 0; }
r[4]=r[14];
goto P_0c06a3b0;
P_0c06a3b0: /* original 495a, guest PC 0x0c06a3b0 */
if(!s->budget--) { s->failed_pc=0x0c06a3b0u; return 0; }
r[53]=r[9];
goto P_0c06a3b2;
P_0c06a3b2: /* original c731, guest PC 0x0c06a3b2 */
if(!s->budget--) { s->failed_pc=0x0c06a3b2u; return 0; }
r[0]=0x0c06a478u;
goto P_0c06a3b4;
P_0c06a3b4: /* original f508, guest PC 0x0c06a3b4 */
if(!s->budget--) { s->failed_pc=0x0c06a3b4u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c06a3b6;
P_0c06a3b6: /* original f32d, guest PC 0x0c06a3b6 */
if(!s->budget--) { s->failed_pc=0x0c06a3b6u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c06a3b8;
P_0c06a3b8: /* original 4a5a, guest PC 0x0c06a3b8 */
if(!s->budget--) { s->failed_pc=0x0c06a3b8u; return 0; }
r[53]=r[10];
goto P_0c06a3ba;
P_0c06a3ba: /* original f22d, guest PC 0x0c06a3ba */
if(!s->budget--) { s->failed_pc=0x0c06a3bau; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c06a3bc;
P_0c06a3bc: /* original f63c, guest PC 0x0c06a3bc */
if(!s->budget--) { s->failed_pc=0x0c06a3bcu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c06a3be;
P_0c06a3be: /* original f42c, guest PC 0x0c06a3be */
if(!s->budget--) { s->failed_pc=0x0c06a3beu; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c06a3c0;
P_0c06a3c0: /* original f452, guest PC 0x0c06a3c0 */
if(!s->budget--) { s->failed_pc=0x0c06a3c0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c06a3c2;
P_0c06a3c2: /* original f463, guest PC 0x0c06a3c2 */
if(!s->budget--) { s->failed_pc=0x0c06a3c2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
goto P_0c06a3c4;
P_0c06a3c4: /* original f43d, guest PC 0x0c06a3c4 */
if(!s->budget--) { s->failed_pc=0x0c06a3c4u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c06a3c6;
P_0c06a3c6: /* original 055a, guest PC 0x0c06a3c6 */
if(!s->budget--) { s->failed_pc=0x0c06a3c6u; return 0; }
r[5]=r[53];
goto P_0c06a3c8;
P_0c06a3c8: /* original 4d0b, guest PC 0x0c06a3c8 */
if(!s->budget--) { s->failed_pc=0x0c06a3c8u; return 0; }
target=r[13];
r[16]=0x0c06a3ccu;
r[4]+=0x0000003cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a3ccu) { target=s->pc; goto dispatch; }
goto P_0c06a3cc;
P_0c06a3ca: /* original 743c, guest PC 0x0c06a3ca */
if(!s->budget--) { s->failed_pc=0x0c06a3cau; return 0; }
r[4]+=0x0000003cu;
goto P_0c06a3cc;
P_0c06a3cc: /* original 9444, guest PC 0x0c06a3cc */
if(!s->budget--) { s->failed_pc=0x0c06a3ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a458u,2);
goto P_0c06a3ce;
P_0c06a3ce: /* original e500, guest PC 0x0c06a3ce */
if(!s->budget--) { s->failed_pc=0x0c06a3ceu; return 0; }
r[5]=0x00000000u;
goto P_0c06a3d0;
P_0c06a3d0: /* original 4d0b, guest PC 0x0c06a3d0 */
if(!s->budget--) { s->failed_pc=0x0c06a3d0u; return 0; }
target=r[13];
r[16]=0x0c06a3d4u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a3d4u) { target=s->pc; goto dispatch; }
goto P_0c06a3d4;
P_0c06a3d2: /* original 34ec, guest PC 0x0c06a3d2 */
if(!s->budget--) { s->failed_pc=0x0c06a3d2u; return 0; }
r[4]+=r[14];
goto P_0c06a3d4;
P_0c06a3d4: /* original 9041, guest PC 0x0c06a3d4 */
if(!s->budget--) { s->failed_pc=0x0c06a3d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a45au,2);
goto P_0c06a3d6;
P_0c06a3d6: /* original 0ace, guest PC 0x0c06a3d6 */
if(!s->budget--) { s->failed_pc=0x0c06a3d6u; return 0; }
r[10]=read(ram,r[12]+r[0],4);
goto P_0c06a3d8;
P_0c06a3d8: /* original 2aa8, guest PC 0x0c06a3d8 */
if(!s->budget--) { s->failed_pc=0x0c06a3d8u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c06a3da;
P_0c06a3da: /* original 8f02, guest PC 0x0c06a3da */
if(!s->budget--) { s->failed_pc=0x0c06a3dau; return 0; }
cond=r[17]&1u;
r[9]=0x00000000u;
if(!cond) { goto P_0c06a3e2; }
goto P_0c06a3de;
P_0c06a3dc: /* original e900, guest PC 0x0c06a3dc */
if(!s->budget--) { s->failed_pc=0x0c06a3dcu; return 0; }
r[9]=0x00000000u;
goto P_0c06a3de;
P_0c06a3de: /* original a0cc, guest PC 0x0c06a3de */
if(!s->budget--) { s->failed_pc=0x0c06a3deu; return 0; }
goto P_0c06a57a;
P_0c06a3e0: /* original 0009, guest PC 0x0c06a3e0 */
if(!s->budget--) { s->failed_pc=0x0c06a3e0u; return 0; }
goto P_0c06a3e2;
P_0c06a3e2: /* original 903b, guest PC 0x0c06a3e2 */
if(!s->budget--) { s->failed_pc=0x0c06a3e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a45cu,2);
goto P_0c06a3e4;
P_0c06a3e4: /* original 05cc, guest PC 0x0c06a3e4 */
if(!s->budget--) { s->failed_pc=0x0c06a3e4u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c06a3e6;
P_0c06a3e6: /* original 903a, guest PC 0x0c06a3e6 */
if(!s->budget--) { s->failed_pc=0x0c06a3e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a45eu,2);
goto P_0c06a3e8;
P_0c06a3e8: /* original 04cc, guest PC 0x0c06a3e8 */
if(!s->budget--) { s->failed_pc=0x0c06a3e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c06a3ea;
P_0c06a3ea: /* original 6043, guest PC 0x0c06a3ea */
if(!s->budget--) { s->failed_pc=0x0c06a3eau; return 0; }
r[0]=r[4];
goto P_0c06a3ec;
P_0c06a3ec: /* original 8803, guest PC 0x0c06a3ec */
if(!s->budget--) { s->failed_pc=0x0c06a3ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c06a3ee;
P_0c06a3ee: /* original 8d47, guest PC 0x0c06a3ee */
if(!s->budget--) { s->failed_pc=0x0c06a3eeu; return 0; }
cond=r[17]&1u;
r[8]=0x00000014u;
if(cond) { goto P_0c06a480; }
goto P_0c06a3f2;
P_0c06a3f0: /* original e814, guest PC 0x0c06a3f0 */
if(!s->budget--) { s->failed_pc=0x0c06a3f0u; return 0; }
r[8]=0x00000014u;
goto P_0c06a3f2;
P_0c06a3f2: /* original 2448, guest PC 0x0c06a3f2 */
if(!s->budget--) { s->failed_pc=0x0c06a3f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06a3f4;
P_0c06a3f4: /* original 8901, guest PC 0x0c06a3f4 */
if(!s->budget--) { s->failed_pc=0x0c06a3f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06a3fa; }
goto P_0c06a3f6;
P_0c06a3f6: /* original 3540, guest PC 0x0c06a3f6 */
if(!s->budget--) { s->failed_pc=0x0c06a3f6u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[4])!=0);
goto P_0c06a3f8;
P_0c06a3f8: /* original 8942, guest PC 0x0c06a3f8 */
if(!s->budget--) { s->failed_pc=0x0c06a3f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06a480; }
goto P_0c06a3fa;
P_0c06a3fa: /* original 64e3, guest PC 0x0c06a3fa */
if(!s->budget--) { s->failed_pc=0x0c06a3fau; return 0; }
r[4]=r[14];
goto P_0c06a3fc;
P_0c06a3fc: /* original 4b0b, guest PC 0x0c06a3fc */
if(!s->budget--) { s->failed_pc=0x0c06a3fcu; return 0; }
target=r[11];
r[16]=0x0c06a400u;
r[4]+=0x00000060u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a400u) { target=s->pc; goto dispatch; }
goto P_0c06a400;
P_0c06a3fe: /* original 7460, guest PC 0x0c06a3fe */
if(!s->budget--) { s->failed_pc=0x0c06a3feu; return 0; }
r[4]+=0x00000060u;
goto P_0c06a400;
P_0c06a400: /* original 6403, guest PC 0x0c06a400 */
if(!s->budget--) { s->failed_pc=0x0c06a400u; return 0; }
r[4]=r[0];
goto P_0c06a402;
P_0c06a402: /* original 7401, guest PC 0x0c06a402 */
if(!s->budget--) { s->failed_pc=0x0c06a402u; return 0; }
r[4]+=0x00000001u;
goto P_0c06a404;
P_0c06a404: /* original 6543, guest PC 0x0c06a404 */
if(!s->budget--) { s->failed_pc=0x0c06a404u; return 0; }
r[5]=r[4];
goto P_0c06a406;
P_0c06a406: /* original 1f41, guest PC 0x0c06a406 */
if(!s->budget--) { s->failed_pc=0x0c06a406u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c06a408;
P_0c06a408: /* original 64e3, guest PC 0x0c06a408 */
if(!s->budget--) { s->failed_pc=0x0c06a408u; return 0; }
r[4]=r[14];
goto P_0c06a40a;
P_0c06a40a: /* original 4d0b, guest PC 0x0c06a40a */
if(!s->budget--) { s->failed_pc=0x0c06a40au; return 0; }
target=r[13];
r[16]=0x0c06a40eu;
r[4]+=0x00000060u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a40eu) { target=s->pc; goto dispatch; }
goto P_0c06a40e;
P_0c06a40c: /* original 7460, guest PC 0x0c06a40c */
if(!s->budget--) { s->failed_pc=0x0c06a40cu; return 0; }
r[4]+=0x00000060u;
goto P_0c06a40e;
P_0c06a40e: /* original 9427, guest PC 0x0c06a40e */
if(!s->budget--) { s->failed_pc=0x0c06a40eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a460u,2);
goto P_0c06a410;
P_0c06a410: /* original 4b0b, guest PC 0x0c06a410 */
if(!s->budget--) { s->failed_pc=0x0c06a410u; return 0; }
target=r[11];
r[16]=0x0c06a414u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a414u) { target=s->pc; goto dispatch; }
goto P_0c06a414;
P_0c06a412: /* original 34ec, guest PC 0x0c06a412 */
if(!s->budget--) { s->failed_pc=0x0c06a412u; return 0; }
r[4]+=r[14];
goto P_0c06a414;
P_0c06a414: /* original 30ac, guest PC 0x0c06a414 */
if(!s->budget--) { s->failed_pc=0x0c06a414u; return 0; }
r[0]+=r[10];
goto P_0c06a416;
P_0c06a416: /* original 6503, guest PC 0x0c06a416 */
if(!s->budget--) { s->failed_pc=0x0c06a416u; return 0; }
r[5]=r[0];
goto P_0c06a418;
P_0c06a418: /* original 2f02, guest PC 0x0c06a418 */
if(!s->budget--) { s->failed_pc=0x0c06a418u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a41a;
P_0c06a41a: /* original 9421, guest PC 0x0c06a41a */
if(!s->budget--) { s->failed_pc=0x0c06a41au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a460u,2);
goto P_0c06a41c;
P_0c06a41c: /* original 4d0b, guest PC 0x0c06a41c */
if(!s->budget--) { s->failed_pc=0x0c06a41cu; return 0; }
target=r[13];
r[16]=0x0c06a420u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a420u) { target=s->pc; goto dispatch; }
goto P_0c06a420;
P_0c06a41e: /* original 34ec, guest PC 0x0c06a41e */
if(!s->budget--) { s->failed_pc=0x0c06a41eu; return 0; }
r[4]+=r[14];
goto P_0c06a420;
P_0c06a420: /* original d316, guest PC 0x0c06a420 */
if(!s->budget--) { s->failed_pc=0x0c06a420u; return 0; }
r[3]=read(ram,0x0c06a47cu,4);
goto P_0c06a422;
P_0c06a422: /* original 61f2, guest PC 0x0c06a422 */
if(!s->budget--) { s->failed_pc=0x0c06a422u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c06a424;
P_0c06a424: /* original 430b, guest PC 0x0c06a424 */
if(!s->budget--) { s->failed_pc=0x0c06a424u; return 0; }
target=r[3];
r[16]=0x0c06a428u;
r[0]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a428u) { target=s->pc; goto dispatch; }
goto P_0c06a428;
P_0c06a426: /* original 50f1, guest PC 0x0c06a426 */
if(!s->budget--) { s->failed_pc=0x0c06a426u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c06a428;
P_0c06a428: /* original 64e3, guest PC 0x0c06a428 */
if(!s->budget--) { s->failed_pc=0x0c06a428u; return 0; }
r[4]=r[14];
goto P_0c06a42a;
P_0c06a42a: /* original 6503, guest PC 0x0c06a42a */
if(!s->budget--) { s->failed_pc=0x0c06a42au; return 0; }
r[5]=r[0];
goto P_0c06a42c;
P_0c06a42c: /* original 2f02, guest PC 0x0c06a42c */
if(!s->budget--) { s->failed_pc=0x0c06a42cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a42e;
P_0c06a42e: /* original 4d0b, guest PC 0x0c06a42e */
if(!s->budget--) { s->failed_pc=0x0c06a42eu; return 0; }
target=r[13];
r[16]=0x0c06a432u;
r[4]+=0x00000070u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a432u) { target=s->pc; goto dispatch; }
goto P_0c06a432;
P_0c06a430: /* original 7470, guest PC 0x0c06a430 */
if(!s->budget--) { s->failed_pc=0x0c06a430u; return 0; }
r[4]+=0x00000070u;
goto P_0c06a432;
P_0c06a432: /* original d312, guest PC 0x0c06a432 */
if(!s->budget--) { s->failed_pc=0x0c06a432u; return 0; }
r[3]=read(ram,0x0c06a47cu,4);
goto P_0c06a434;
P_0c06a434: /* original 61a3, guest PC 0x0c06a434 */
if(!s->budget--) { s->failed_pc=0x0c06a434u; return 0; }
r[1]=r[10];
goto P_0c06a436;
P_0c06a436: /* original 9414, guest PC 0x0c06a436 */
if(!s->budget--) { s->failed_pc=0x0c06a436u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a462u,2);
goto P_0c06a438;
P_0c06a438: /* original 430b, guest PC 0x0c06a438 */
if(!s->budget--) { s->failed_pc=0x0c06a438u; return 0; }
target=r[3];
r[16]=0x0c06a43cu;
r[0]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a43cu) { target=s->pc; goto dispatch; }
goto P_0c06a43c;
P_0c06a43a: /* original 6043, guest PC 0x0c06a43a */
if(!s->budget--) { s->failed_pc=0x0c06a43au; return 0; }
r[0]=r[4];
goto P_0c06a43c;
P_0c06a43c: /* original 3087, guest PC 0x0c06a43c */
if(!s->budget--) { s->failed_pc=0x0c06a43cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>(int32_t)r[8])!=0);
goto P_0c06a43e;
P_0c06a43e: /* original 8f01, guest PC 0x0c06a43e */
if(!s->budget--) { s->failed_pc=0x0c06a43eu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[0],4);
if(!cond) { goto P_0c06a444; }
goto P_0c06a442;
P_0c06a440: /* original 2f02, guest PC 0x0c06a440 */
if(!s->budget--) { s->failed_pc=0x0c06a440u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a442;
P_0c06a442: /* original 2f82, guest PC 0x0c06a442 */
if(!s->budget--) { s->failed_pc=0x0c06a442u; return 0; }
write(ram,r[15],r[8],4);
goto P_0c06a444;
P_0c06a444: /* original 930e, guest PC 0x0c06a444 */
if(!s->budget--) { s->failed_pc=0x0c06a444u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a464u,2);
goto P_0c06a446;
P_0c06a446: /* original 64f2, guest PC 0x0c06a446 */
if(!s->budget--) { s->failed_pc=0x0c06a446u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06a448;
P_0c06a448: /* original 33ec, guest PC 0x0c06a448 */
if(!s->budget--) { s->failed_pc=0x0c06a448u; return 0; }
r[3]+=r[14];
goto P_0c06a44a;
P_0c06a44a: /* original 4408, guest PC 0x0c06a44a */
if(!s->budget--) { s->failed_pc=0x0c06a44au; return 0; }
r[4]<<=2;
goto P_0c06a44c;
P_0c06a44c: /* original 343c, guest PC 0x0c06a44c */
if(!s->budget--) { s->failed_pc=0x0c06a44cu; return 0; }
r[4]+=r[3];
goto P_0c06a44e;
P_0c06a44e: /* original a046, guest PC 0x0c06a44e */
if(!s->budget--) { s->failed_pc=0x0c06a44eu; return 0; }
r[5]=0x00000001u;
goto P_0c06a4de;
P_0c06a450: /* original e501, guest PC 0x0c06a450 */
if(!s->budget--) { s->failed_pc=0x0c06a450u; return 0; }
r[5]=0x00000001u;
return vf3_matrix_family(0x0c06a452u,s,ram);
P_0c06a480: /* original 64e3, guest PC 0x0c06a480 */
if(!s->budget--) { s->failed_pc=0x0c06a480u; return 0; }
r[4]=r[14];
goto P_0c06a482;
P_0c06a482: /* original 4b0b, guest PC 0x0c06a482 */
if(!s->budget--) { s->failed_pc=0x0c06a482u; return 0; }
target=r[11];
r[16]=0x0c06a486u;
r[4]+=0x00000064u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a486u) { target=s->pc; goto dispatch; }
goto P_0c06a486;
P_0c06a484: /* original 7464, guest PC 0x0c06a484 */
if(!s->budget--) { s->failed_pc=0x0c06a484u; return 0; }
r[4]+=0x00000064u;
goto P_0c06a486;
P_0c06a486: /* original 6403, guest PC 0x0c06a486 */
if(!s->budget--) { s->failed_pc=0x0c06a486u; return 0; }
r[4]=r[0];
goto P_0c06a488;
P_0c06a488: /* original 7401, guest PC 0x0c06a488 */
if(!s->budget--) { s->failed_pc=0x0c06a488u; return 0; }
r[4]+=0x00000001u;
goto P_0c06a48a;
P_0c06a48a: /* original 6543, guest PC 0x0c06a48a */
if(!s->budget--) { s->failed_pc=0x0c06a48au; return 0; }
r[5]=r[4];
goto P_0c06a48c;
P_0c06a48c: /* original 1f41, guest PC 0x0c06a48c */
if(!s->budget--) { s->failed_pc=0x0c06a48cu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c06a48e;
P_0c06a48e: /* original 64e3, guest PC 0x0c06a48e */
if(!s->budget--) { s->failed_pc=0x0c06a48eu; return 0; }
r[4]=r[14];
goto P_0c06a490;
P_0c06a490: /* original 4d0b, guest PC 0x0c06a490 */
if(!s->budget--) { s->failed_pc=0x0c06a490u; return 0; }
target=r[13];
r[16]=0x0c06a494u;
r[4]+=0x00000064u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a494u) { target=s->pc; goto dispatch; }
goto P_0c06a494;
P_0c06a492: /* original 7464, guest PC 0x0c06a492 */
if(!s->budget--) { s->failed_pc=0x0c06a492u; return 0; }
r[4]+=0x00000064u;
goto P_0c06a494;
P_0c06a494: /* original 9496, guest PC 0x0c06a494 */
if(!s->budget--) { s->failed_pc=0x0c06a494u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5c4u,2);
goto P_0c06a496;
P_0c06a496: /* original 55f1, guest PC 0x0c06a496 */
if(!s->budget--) { s->failed_pc=0x0c06a496u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c06a498;
P_0c06a498: /* original 4d0b, guest PC 0x0c06a498 */
if(!s->budget--) { s->failed_pc=0x0c06a498u; return 0; }
target=r[13];
r[16]=0x0c06a49cu;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a49cu) { target=s->pc; goto dispatch; }
goto P_0c06a49c;
P_0c06a49a: /* original 34ec, guest PC 0x0c06a49a */
if(!s->budget--) { s->failed_pc=0x0c06a49au; return 0; }
r[4]+=r[14];
goto P_0c06a49c;
P_0c06a49c: /* original 9493, guest PC 0x0c06a49c */
if(!s->budget--) { s->failed_pc=0x0c06a49cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5c6u,2);
goto P_0c06a49e;
P_0c06a49e: /* original 4b0b, guest PC 0x0c06a49e */
if(!s->budget--) { s->failed_pc=0x0c06a49eu; return 0; }
target=r[11];
r[16]=0x0c06a4a2u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a4a2u) { target=s->pc; goto dispatch; }
goto P_0c06a4a2;
P_0c06a4a0: /* original 34ec, guest PC 0x0c06a4a0 */
if(!s->budget--) { s->failed_pc=0x0c06a4a0u; return 0; }
r[4]+=r[14];
goto P_0c06a4a2;
P_0c06a4a2: /* original 30ac, guest PC 0x0c06a4a2 */
if(!s->budget--) { s->failed_pc=0x0c06a4a2u; return 0; }
r[0]+=r[10];
goto P_0c06a4a4;
P_0c06a4a4: /* original 6503, guest PC 0x0c06a4a4 */
if(!s->budget--) { s->failed_pc=0x0c06a4a4u; return 0; }
r[5]=r[0];
goto P_0c06a4a6;
P_0c06a4a6: /* original 2f02, guest PC 0x0c06a4a6 */
if(!s->budget--) { s->failed_pc=0x0c06a4a6u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a4a8;
P_0c06a4a8: /* original 948d, guest PC 0x0c06a4a8 */
if(!s->budget--) { s->failed_pc=0x0c06a4a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5c6u,2);
goto P_0c06a4aa;
P_0c06a4aa: /* original 4d0b, guest PC 0x0c06a4aa */
if(!s->budget--) { s->failed_pc=0x0c06a4aau; return 0; }
target=r[13];
r[16]=0x0c06a4aeu;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a4aeu) { target=s->pc; goto dispatch; }
goto P_0c06a4ae;
P_0c06a4ac: /* original 34ec, guest PC 0x0c06a4ac */
if(!s->budget--) { s->failed_pc=0x0c06a4acu; return 0; }
r[4]+=r[14];
goto P_0c06a4ae;
P_0c06a4ae: /* original d34b, guest PC 0x0c06a4ae */
if(!s->budget--) { s->failed_pc=0x0c06a4aeu; return 0; }
r[3]=read(ram,0x0c06a5dcu,4);
goto P_0c06a4b0;
P_0c06a4b0: /* original 61f2, guest PC 0x0c06a4b0 */
if(!s->budget--) { s->failed_pc=0x0c06a4b0u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c06a4b2;
P_0c06a4b2: /* original 430b, guest PC 0x0c06a4b2 */
if(!s->budget--) { s->failed_pc=0x0c06a4b2u; return 0; }
target=r[3];
r[16]=0x0c06a4b6u;
r[0]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a4b6u) { target=s->pc; goto dispatch; }
goto P_0c06a4b6;
P_0c06a4b4: /* original 50f1, guest PC 0x0c06a4b4 */
if(!s->budget--) { s->failed_pc=0x0c06a4b4u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c06a4b6;
P_0c06a4b6: /* original 64e3, guest PC 0x0c06a4b6 */
if(!s->budget--) { s->failed_pc=0x0c06a4b6u; return 0; }
r[4]=r[14];
goto P_0c06a4b8;
P_0c06a4b8: /* original 6503, guest PC 0x0c06a4b8 */
if(!s->budget--) { s->failed_pc=0x0c06a4b8u; return 0; }
r[5]=r[0];
goto P_0c06a4ba;
P_0c06a4ba: /* original 2f02, guest PC 0x0c06a4ba */
if(!s->budget--) { s->failed_pc=0x0c06a4bau; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a4bc;
P_0c06a4bc: /* original 4d0b, guest PC 0x0c06a4bc */
if(!s->budget--) { s->failed_pc=0x0c06a4bcu; return 0; }
target=r[13];
r[16]=0x0c06a4c0u;
r[4]+=0x00000074u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a4c0u) { target=s->pc; goto dispatch; }
goto P_0c06a4c0;
P_0c06a4be: /* original 7474, guest PC 0x0c06a4be */
if(!s->budget--) { s->failed_pc=0x0c06a4beu; return 0; }
r[4]+=0x00000074u;
goto P_0c06a4c0;
P_0c06a4c0: /* original d346, guest PC 0x0c06a4c0 */
if(!s->budget--) { s->failed_pc=0x0c06a4c0u; return 0; }
r[3]=read(ram,0x0c06a5dcu,4);
goto P_0c06a4c2;
P_0c06a4c2: /* original 61a3, guest PC 0x0c06a4c2 */
if(!s->budget--) { s->failed_pc=0x0c06a4c2u; return 0; }
r[1]=r[10];
goto P_0c06a4c4;
P_0c06a4c4: /* original 9480, guest PC 0x0c06a4c4 */
if(!s->budget--) { s->failed_pc=0x0c06a4c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5c8u,2);
goto P_0c06a4c6;
P_0c06a4c6: /* original 430b, guest PC 0x0c06a4c6 */
if(!s->budget--) { s->failed_pc=0x0c06a4c6u; return 0; }
target=r[3];
r[16]=0x0c06a4cau;
r[0]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a4cau) { target=s->pc; goto dispatch; }
goto P_0c06a4ca;
P_0c06a4c8: /* original 6043, guest PC 0x0c06a4c8 */
if(!s->budget--) { s->failed_pc=0x0c06a4c8u; return 0; }
r[0]=r[4];
goto P_0c06a4ca;
P_0c06a4ca: /* original 3087, guest PC 0x0c06a4ca */
if(!s->budget--) { s->failed_pc=0x0c06a4cau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>(int32_t)r[8])!=0);
goto P_0c06a4cc;
P_0c06a4cc: /* original 8f01, guest PC 0x0c06a4cc */
if(!s->budget--) { s->failed_pc=0x0c06a4ccu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[0],4);
if(!cond) { goto P_0c06a4d2; }
goto P_0c06a4d0;
P_0c06a4ce: /* original 2f02, guest PC 0x0c06a4ce */
if(!s->budget--) { s->failed_pc=0x0c06a4ceu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06a4d0;
P_0c06a4d0: /* original 2f82, guest PC 0x0c06a4d0 */
if(!s->budget--) { s->failed_pc=0x0c06a4d0u; return 0; }
write(ram,r[15],r[8],4);
goto P_0c06a4d2;
P_0c06a4d2: /* original 937a, guest PC 0x0c06a4d2 */
if(!s->budget--) { s->failed_pc=0x0c06a4d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5cau,2);
goto P_0c06a4d4;
P_0c06a4d4: /* original e501, guest PC 0x0c06a4d4 */
if(!s->budget--) { s->failed_pc=0x0c06a4d4u; return 0; }
r[5]=0x00000001u;
goto P_0c06a4d6;
P_0c06a4d6: /* original 64f2, guest PC 0x0c06a4d6 */
if(!s->budget--) { s->failed_pc=0x0c06a4d6u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06a4d8;
P_0c06a4d8: /* original 33ec, guest PC 0x0c06a4d8 */
if(!s->budget--) { s->failed_pc=0x0c06a4d8u; return 0; }
r[3]+=r[14];
goto P_0c06a4da;
P_0c06a4da: /* original 4408, guest PC 0x0c06a4da */
if(!s->budget--) { s->failed_pc=0x0c06a4dau; return 0; }
r[4]<<=2;
goto P_0c06a4dc;
P_0c06a4dc: /* original 343c, guest PC 0x0c06a4dc */
if(!s->budget--) { s->failed_pc=0x0c06a4dcu; return 0; }
r[4]+=r[3];
goto P_0c06a4de;
P_0c06a4de: /* original b8f2, guest PC 0x0c06a4de */
if(!s->budget--) { s->failed_pc=0x0c06a4deu; return 0; }
target=0x0c0696c6u; r[16]=0x0c06a4e2u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a4e2u) { target=s->pc; goto dispatch; }
goto P_0c06a4e2;
P_0c06a4e0: /* original 0009, guest PC 0x0c06a4e0 */
if(!s->budget--) { s->failed_pc=0x0c06a4e0u; return 0; }
goto P_0c06a4e2;
P_0c06a4e2: /* original 9473, guest PC 0x0c06a4e2 */
if(!s->budget--) { s->failed_pc=0x0c06a4e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5ccu,2);
goto P_0c06a4e4;
P_0c06a4e4: /* original 4b0b, guest PC 0x0c06a4e4 */
if(!s->budget--) { s->failed_pc=0x0c06a4e4u; return 0; }
target=r[11];
r[16]=0x0c06a4e8u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a4e8u) { target=s->pc; goto dispatch; }
goto P_0c06a4e8;
P_0c06a4e6: /* original 34ec, guest PC 0x0c06a4e6 */
if(!s->budget--) { s->failed_pc=0x0c06a4e6u; return 0; }
r[4]+=r[14];
goto P_0c06a4e8;
P_0c06a4e8: /* original 6403, guest PC 0x0c06a4e8 */
if(!s->budget--) { s->failed_pc=0x0c06a4e8u; return 0; }
r[4]=r[0];
goto P_0c06a4ea;
P_0c06a4ea: /* original 34ac, guest PC 0x0c06a4ea */
if(!s->budget--) { s->failed_pc=0x0c06a4eau; return 0; }
r[4]+=r[10];
goto P_0c06a4ec;
P_0c06a4ec: /* original 6543, guest PC 0x0c06a4ec */
if(!s->budget--) { s->failed_pc=0x0c06a4ecu; return 0; }
r[5]=r[4];
goto P_0c06a4ee;
P_0c06a4ee: /* original 2f42, guest PC 0x0c06a4ee */
if(!s->budget--) { s->failed_pc=0x0c06a4eeu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06a4f0;
P_0c06a4f0: /* original 946c, guest PC 0x0c06a4f0 */
if(!s->budget--) { s->failed_pc=0x0c06a4f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5ccu,2);
goto P_0c06a4f2;
P_0c06a4f2: /* original 4d0b, guest PC 0x0c06a4f2 */
if(!s->budget--) { s->failed_pc=0x0c06a4f2u; return 0; }
target=r[13];
r[16]=0x0c06a4f6u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a4f6u) { target=s->pc; goto dispatch; }
goto P_0c06a4f6;
P_0c06a4f4: /* original 34ec, guest PC 0x0c06a4f4 */
if(!s->budget--) { s->failed_pc=0x0c06a4f4u; return 0; }
r[4]+=r[14];
goto P_0c06a4f6;
P_0c06a4f6: /* original 946a, guest PC 0x0c06a4f6 */
if(!s->budget--) { s->failed_pc=0x0c06a4f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5ceu,2);
goto P_0c06a4f8;
P_0c06a4f8: /* original 4b0b, guest PC 0x0c06a4f8 */
if(!s->budget--) { s->failed_pc=0x0c06a4f8u; return 0; }
target=r[11];
r[16]=0x0c06a4fcu;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a4fcu) { target=s->pc; goto dispatch; }
goto P_0c06a4fc;
P_0c06a4fa: /* original 34ec, guest PC 0x0c06a4fa */
if(!s->budget--) { s->failed_pc=0x0c06a4fau; return 0; }
r[4]+=r[14];
goto P_0c06a4fc;
P_0c06a4fc: /* original 6803, guest PC 0x0c06a4fc */
if(!s->budget--) { s->failed_pc=0x0c06a4fcu; return 0; }
r[8]=r[0];
goto P_0c06a4fe;
P_0c06a4fe: /* original 9466, guest PC 0x0c06a4fe */
if(!s->budget--) { s->failed_pc=0x0c06a4feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5ceu,2);
goto P_0c06a500;
P_0c06a500: /* original 7801, guest PC 0x0c06a500 */
if(!s->budget--) { s->failed_pc=0x0c06a500u; return 0; }
r[8]+=0x00000001u;
goto P_0c06a502;
P_0c06a502: /* original 6583, guest PC 0x0c06a502 */
if(!s->budget--) { s->failed_pc=0x0c06a502u; return 0; }
r[5]=r[8];
goto P_0c06a504;
P_0c06a504: /* original 4d0b, guest PC 0x0c06a504 */
if(!s->budget--) { s->failed_pc=0x0c06a504u; return 0; }
target=r[13];
r[16]=0x0c06a508u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a508u) { target=s->pc; goto dispatch; }
goto P_0c06a508;
P_0c06a506: /* original 34ec, guest PC 0x0c06a506 */
if(!s->budget--) { s->failed_pc=0x0c06a506u; return 0; }
r[4]+=r[14];
goto P_0c06a508;
P_0c06a508: /* original d334, guest PC 0x0c06a508 */
if(!s->budget--) { s->failed_pc=0x0c06a508u; return 0; }
r[3]=read(ram,0x0c06a5dcu,4);
goto P_0c06a50a;
P_0c06a50a: /* original 61f2, guest PC 0x0c06a50a */
if(!s->budget--) { s->failed_pc=0x0c06a50au; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c06a50c;
P_0c06a50c: /* original 430b, guest PC 0x0c06a50c */
if(!s->budget--) { s->failed_pc=0x0c06a50cu; return 0; }
target=r[3];
r[16]=0x0c06a510u;
r[0]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a510u) { target=s->pc; goto dispatch; }
goto P_0c06a510;
P_0c06a50e: /* original 6083, guest PC 0x0c06a50e */
if(!s->budget--) { s->failed_pc=0x0c06a50eu; return 0; }
r[0]=r[8];
goto P_0c06a510;
P_0c06a510: /* original 945e, guest PC 0x0c06a510 */
if(!s->budget--) { s->failed_pc=0x0c06a510u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5d0u,2);
goto P_0c06a512;
P_0c06a512: /* original 6503, guest PC 0x0c06a512 */
if(!s->budget--) { s->failed_pc=0x0c06a512u; return 0; }
r[5]=r[0];
goto P_0c06a514;
P_0c06a514: /* original 6803, guest PC 0x0c06a514 */
if(!s->budget--) { s->failed_pc=0x0c06a514u; return 0; }
r[8]=r[0];
goto P_0c06a516;
P_0c06a516: /* original 4d0b, guest PC 0x0c06a516 */
if(!s->budget--) { s->failed_pc=0x0c06a516u; return 0; }
target=r[13];
r[16]=0x0c06a51au;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a51au) { target=s->pc; goto dispatch; }
goto P_0c06a51a;
P_0c06a518: /* original 34ec, guest PC 0x0c06a518 */
if(!s->budget--) { s->failed_pc=0x0c06a518u; return 0; }
r[4]+=r[14];
goto P_0c06a51a;
P_0c06a51a: /* original 945a, guest PC 0x0c06a51a */
if(!s->budget--) { s->failed_pc=0x0c06a51au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5d2u,2);
goto P_0c06a51c;
P_0c06a51c: /* original 4b0b, guest PC 0x0c06a51c */
if(!s->budget--) { s->failed_pc=0x0c06a51cu; return 0; }
target=r[11];
r[16]=0x0c06a520u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a520u) { target=s->pc; goto dispatch; }
goto P_0c06a520;
P_0c06a51e: /* original 34ec, guest PC 0x0c06a51e */
if(!s->budget--) { s->failed_pc=0x0c06a51eu; return 0; }
r[4]+=r[14];
goto P_0c06a520;
P_0c06a520: /* original 6403, guest PC 0x0c06a520 */
if(!s->budget--) { s->failed_pc=0x0c06a520u; return 0; }
r[4]=r[0];
goto P_0c06a522;
P_0c06a522: /* original 2448, guest PC 0x0c06a522 */
if(!s->budget--) { s->failed_pc=0x0c06a522u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06a524;
P_0c06a524: /* original 8901, guest PC 0x0c06a524 */
if(!s->budget--) { s->failed_pc=0x0c06a524u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06a52a; }
goto P_0c06a526;
P_0c06a526: /* original 34a7, guest PC 0x0c06a526 */
if(!s->budget--) { s->failed_pc=0x0c06a526u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[10])!=0);
goto P_0c06a528;
P_0c06a528: /* original 8b03, guest PC 0x0c06a528 */
if(!s->budget--) { s->failed_pc=0x0c06a528u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06a532; }
goto P_0c06a52a;
P_0c06a52a: /* original 9452, guest PC 0x0c06a52a */
if(!s->budget--) { s->failed_pc=0x0c06a52au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5d2u,2);
goto P_0c06a52c;
P_0c06a52c: /* original 65a3, guest PC 0x0c06a52c */
if(!s->budget--) { s->failed_pc=0x0c06a52cu; return 0; }
r[5]=r[10];
goto P_0c06a52e;
P_0c06a52e: /* original 4d0b, guest PC 0x0c06a52e */
if(!s->budget--) { s->failed_pc=0x0c06a52eu; return 0; }
target=r[13];
r[16]=0x0c06a532u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a532u) { target=s->pc; goto dispatch; }
goto P_0c06a532;
P_0c06a530: /* original 34ec, guest PC 0x0c06a530 */
if(!s->budget--) { s->failed_pc=0x0c06a530u; return 0; }
r[4]+=r[14];
goto P_0c06a532;
P_0c06a532: /* original 944f, guest PC 0x0c06a532 */
if(!s->budget--) { s->failed_pc=0x0c06a532u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5d4u,2);
goto P_0c06a534;
P_0c06a534: /* original 4b0b, guest PC 0x0c06a534 */
if(!s->budget--) { s->failed_pc=0x0c06a534u; return 0; }
target=r[11];
r[16]=0x0c06a538u;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a538u) { target=s->pc; goto dispatch; }
goto P_0c06a538;
P_0c06a536: /* original 34ec, guest PC 0x0c06a536 */
if(!s->budget--) { s->failed_pc=0x0c06a536u; return 0; }
r[4]+=r[14];
goto P_0c06a538;
P_0c06a538: /* original 6403, guest PC 0x0c06a538 */
if(!s->budget--) { s->failed_pc=0x0c06a538u; return 0; }
r[4]=r[0];
goto P_0c06a53a;
P_0c06a53a: /* original 2448, guest PC 0x0c06a53a */
if(!s->budget--) { s->failed_pc=0x0c06a53au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06a53c;
P_0c06a53c: /* original 8901, guest PC 0x0c06a53c */
if(!s->budget--) { s->failed_pc=0x0c06a53cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06a542; }
goto P_0c06a53e;
P_0c06a53e: /* original 34a3, guest PC 0x0c06a53e */
if(!s->budget--) { s->failed_pc=0x0c06a53eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[10])!=0);
goto P_0c06a540;
P_0c06a540: /* original 8903, guest PC 0x0c06a540 */
if(!s->budget--) { s->failed_pc=0x0c06a540u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06a54a; }
goto P_0c06a542;
P_0c06a542: /* original 9447, guest PC 0x0c06a542 */
if(!s->budget--) { s->failed_pc=0x0c06a542u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5d4u,2);
goto P_0c06a544;
P_0c06a544: /* original 65a3, guest PC 0x0c06a544 */
if(!s->budget--) { s->failed_pc=0x0c06a544u; return 0; }
r[5]=r[10];
goto P_0c06a546;
P_0c06a546: /* original 4d0b, guest PC 0x0c06a546 */
if(!s->budget--) { s->failed_pc=0x0c06a546u; return 0; }
target=r[13];
r[16]=0x0c06a54au;
r[4]+=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a54au) { target=s->pc; goto dispatch; }
goto P_0c06a54a;
P_0c06a548: /* original 34ec, guest PC 0x0c06a548 */
if(!s->budget--) { s->failed_pc=0x0c06a548u; return 0; }
r[4]+=r[14];
goto P_0c06a54a;
P_0c06a54a: /* original 9044, guest PC 0x0c06a54a */
if(!s->budget--) { s->failed_pc=0x0c06a54au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5d6u,2);
goto P_0c06a54c;
P_0c06a54c: /* original 04ce, guest PC 0x0c06a54c */
if(!s->budget--) { s->failed_pc=0x0c06a54cu; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c06a54e;
P_0c06a54e: /* original 6043, guest PC 0x0c06a54e */
if(!s->budget--) { s->failed_pc=0x0c06a54eu; return 0; }
r[0]=r[4];
goto P_0c06a550;
P_0c06a550: /* original 8801, guest PC 0x0c06a550 */
if(!s->budget--) { s->failed_pc=0x0c06a550u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06a552;
P_0c06a552: /* original 8d0b, guest PC 0x0c06a552 */
if(!s->budget--) { s->failed_pc=0x0c06a552u; return 0; }
cond=r[17]&1u;
r[13]=r[9];
if(cond) { goto P_0c06a56c; }
goto P_0c06a556;
P_0c06a554: /* original 6d93, guest PC 0x0c06a554 */
if(!s->budget--) { s->failed_pc=0x0c06a554u; return 0; }
r[13]=r[9];
goto P_0c06a556;
P_0c06a556: /* original e205, guest PC 0x0c06a556 */
if(!s->budget--) { s->failed_pc=0x0c06a556u; return 0; }
r[2]=0x00000005u;
goto P_0c06a558;
P_0c06a558: /* original 3423, guest PC 0x0c06a558 */
if(!s->budget--) { s->failed_pc=0x0c06a558u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c06a55a;
P_0c06a55a: /* original 8f07, guest PC 0x0c06a55a */
if(!s->budget--) { s->failed_pc=0x0c06a55au; return 0; }
cond=r[17]&1u;
r[13]+=0x00000001u;
if(!cond) { goto P_0c06a56c; }
goto P_0c06a55e;
P_0c06a55c: /* original 7d01, guest PC 0x0c06a55c */
if(!s->budget--) { s->failed_pc=0x0c06a55cu; return 0; }
r[13]+=0x00000001u;
goto P_0c06a55e;
P_0c06a55e: /* original d31f, guest PC 0x0c06a55e */
if(!s->budget--) { s->failed_pc=0x0c06a55eu; return 0; }
r[3]=read(ram,0x0c06a5dcu,4);
goto P_0c06a560;
P_0c06a560: /* original 6143, guest PC 0x0c06a560 */
if(!s->budget--) { s->failed_pc=0x0c06a560u; return 0; }
r[1]=r[4];
goto P_0c06a562;
P_0c06a562: /* original e50a, guest PC 0x0c06a562 */
if(!s->budget--) { s->failed_pc=0x0c06a562u; return 0; }
r[5]=0x0000000au;
goto P_0c06a564;
P_0c06a564: /* original 430b, guest PC 0x0c06a564 */
if(!s->budget--) { s->failed_pc=0x0c06a564u; return 0; }
target=r[3];
r[16]=0x0c06a568u;
r[0]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a568u) { target=s->pc; goto dispatch; }
goto P_0c06a568;
P_0c06a566: /* original 6053, guest PC 0x0c06a566 */
if(!s->budget--) { s->failed_pc=0x0c06a566u; return 0; }
r[0]=r[5];
goto P_0c06a568;
P_0c06a568: /* original 6d03, guest PC 0x0c06a568 */
if(!s->budget--) { s->failed_pc=0x0c06a568u; return 0; }
r[13]=r[0];
goto P_0c06a56a;
P_0c06a56a: /* original 7d02, guest PC 0x0c06a56a */
if(!s->budget--) { s->failed_pc=0x0c06a56au; return 0; }
r[13]+=0x00000002u;
goto P_0c06a56c;
P_0c06a56c: /* original 9333, guest PC 0x0c06a56c */
if(!s->budget--) { s->failed_pc=0x0c06a56cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5d6u,2);
goto P_0c06a56e;
P_0c06a56e: /* original 64d3, guest PC 0x0c06a56e */
if(!s->budget--) { s->failed_pc=0x0c06a56eu; return 0; }
r[4]=r[13];
goto P_0c06a570;
P_0c06a570: /* original e501, guest PC 0x0c06a570 */
if(!s->budget--) { s->failed_pc=0x0c06a570u; return 0; }
r[5]=0x00000001u;
goto P_0c06a572;
P_0c06a572: /* original 33ec, guest PC 0x0c06a572 */
if(!s->budget--) { s->failed_pc=0x0c06a572u; return 0; }
r[3]+=r[14];
goto P_0c06a574;
P_0c06a574: /* original 4408, guest PC 0x0c06a574 */
if(!s->budget--) { s->failed_pc=0x0c06a574u; return 0; }
r[4]<<=2;
goto P_0c06a576;
P_0c06a576: /* original b8a6, guest PC 0x0c06a576 */
if(!s->budget--) { s->failed_pc=0x0c06a576u; return 0; }
target=0x0c0696c6u; r[16]=0x0c06a57au;
r[4]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06a57au) { target=s->pc; goto dispatch; }
goto P_0c06a57a;
P_0c06a578: /* original 343c, guest PC 0x0c06a578 */
if(!s->budget--) { s->failed_pc=0x0c06a578u; return 0; }
r[4]+=r[3];
goto P_0c06a57a;
P_0c06a57a: /* original 54c2, guest PC 0x0c06a57a */
if(!s->budget--) { s->failed_pc=0x0c06a57au; return 0; }
r[4]=read(ram,r[12]+8,4);
goto P_0c06a57c;
P_0c06a57c: /* original e304, guest PC 0x0c06a57c */
if(!s->budget--) { s->failed_pc=0x0c06a57cu; return 0; }
r[3]=0x00000004u;
goto P_0c06a57e;
P_0c06a57e: /* original 2438, guest PC 0x0c06a57e */
if(!s->budget--) { s->failed_pc=0x0c06a57eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c06a580;
P_0c06a580: /* original 8b0d, guest PC 0x0c06a580 */
if(!s->budget--) { s->failed_pc=0x0c06a580u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06a59e; }
goto P_0c06a582;
P_0c06a582: /* original e029, guest PC 0x0c06a582 */
if(!s->budget--) { s->failed_pc=0x0c06a582u; return 0; }
r[0]=0x00000029u;
goto P_0c06a584;
P_0c06a584: /* original d516, guest PC 0x0c06a584 */
if(!s->budget--) { s->failed_pc=0x0c06a584u; return 0; }
r[5]=read(ram,0x0c06a5e0u,4);
goto P_0c06a586;
P_0c06a586: /* original 06cc, guest PC 0x0c06a586 */
if(!s->budget--) { s->failed_pc=0x0c06a586u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c06a588;
P_0c06a588: /* original e01d, guest PC 0x0c06a588 */
if(!s->budget--) { s->failed_pc=0x0c06a588u; return 0; }
r[0]=0x0000001du;
goto P_0c06a58a;
P_0c06a58a: /* original 07cc, guest PC 0x0c06a58a */
if(!s->budget--) { s->failed_pc=0x0c06a58au; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c06a58c;
P_0c06a58c: /* original 666c, guest PC 0x0c06a58c */
if(!s->budget--) { s->failed_pc=0x0c06a58cu; return 0; }
r[6]=r[6]&255u;
goto P_0c06a58e;
P_0c06a58e: /* original 5454, guest PC 0x0c06a58e */
if(!s->budget--) { s->failed_pc=0x0c06a58eu; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c06a590;
P_0c06a590: /* original 6063, guest PC 0x0c06a590 */
if(!s->budget--) { s->failed_pc=0x0c06a590u; return 0; }
r[0]=r[6];
goto P_0c06a592;
P_0c06a592: /* original 8803, guest PC 0x0c06a592 */
if(!s->budget--) { s->failed_pc=0x0c06a592u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c06a594;
P_0c06a594: /* original 8d03, guest PC 0x0c06a594 */
if(!s->budget--) { s->failed_pc=0x0c06a594u; return 0; }
cond=r[17]&1u;
r[7]=r[7]&255u;
if(cond) { goto P_0c06a59e; }
goto P_0c06a598;
P_0c06a596: /* original 677c, guest PC 0x0c06a596 */
if(!s->budget--) { s->failed_pc=0x0c06a596u; return 0; }
r[7]=r[7]&255u;
goto P_0c06a598;
P_0c06a598: /* original 2778, guest PC 0x0c06a598 */
if(!s->budget--) { s->failed_pc=0x0c06a598u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c06a59a;
P_0c06a59a: /* original 8900, guest PC 0x0c06a59a */
if(!s->budget--) { s->failed_pc=0x0c06a59au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06a59e; }
goto P_0c06a59c;
P_0c06a59c: /* original 5455, guest PC 0x0c06a59c */
if(!s->budget--) { s->failed_pc=0x0c06a59cu; return 0; }
r[4]=read(ram,r[5]+20,4);
goto P_0c06a59e;
P_0c06a59e: /* original 901b, guest PC 0x0c06a59e */
if(!s->budget--) { s->failed_pc=0x0c06a59eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5d8u,2);
goto P_0c06a5a0;
P_0c06a5a0: /* original 7f08, guest PC 0x0c06a5a0 */
if(!s->budget--) { s->failed_pc=0x0c06a5a0u; return 0; }
r[15]+=0x00000008u;
goto P_0c06a5a2;
P_0c06a5a2: /* original 4f26, guest PC 0x0c06a5a2 */
if(!s->budget--) { s->failed_pc=0x0c06a5a2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06a5a4;
P_0c06a5a4: /* original 0c96, guest PC 0x0c06a5a4 */
if(!s->budget--) { s->failed_pc=0x0c06a5a4u; return 0; }
write(ram,r[12]+r[0],r[9],4);
goto P_0c06a5a6;
P_0c06a5a6: /* original 7008, guest PC 0x0c06a5a6 */
if(!s->budget--) { s->failed_pc=0x0c06a5a6u; return 0; }
r[0]+=0x00000008u;
goto P_0c06a5a8;
P_0c06a5a8: /* original 0c96, guest PC 0x0c06a5a8 */
if(!s->budget--) { s->failed_pc=0x0c06a5a8u; return 0; }
write(ram,r[12]+r[0],r[9],4);
goto P_0c06a5aa;
P_0c06a5aa: /* original e301, guest PC 0x0c06a5aa */
if(!s->budget--) { s->failed_pc=0x0c06a5aau; return 0; }
r[3]=0x00000001u;
goto P_0c06a5ac;
P_0c06a5ac: /* original 900a, guest PC 0x0c06a5ac */
if(!s->budget--) { s->failed_pc=0x0c06a5acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06a5c4u,2);
goto P_0c06a5ae;
P_0c06a5ae: /* original 0c96, guest PC 0x0c06a5ae */
if(!s->budget--) { s->failed_pc=0x0c06a5aeu; return 0; }
write(ram,r[12]+r[0],r[9],4);
goto P_0c06a5b0;
P_0c06a5b0: /* original 701c, guest PC 0x0c06a5b0 */
if(!s->budget--) { s->failed_pc=0x0c06a5b0u; return 0; }
r[0]+=0x0000001cu;
goto P_0c06a5b2;
P_0c06a5b2: /* original 0c36, guest PC 0x0c06a5b2 */
if(!s->budget--) { s->failed_pc=0x0c06a5b2u; return 0; }
write(ram,r[12]+r[0],r[3],4);
goto P_0c06a5b4;
P_0c06a5b4: /* original 68f6, guest PC 0x0c06a5b4 */
if(!s->budget--) { s->failed_pc=0x0c06a5b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06a5b6;
P_0c06a5b6: /* original 69f6, guest PC 0x0c06a5b6 */
if(!s->budget--) { s->failed_pc=0x0c06a5b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06a5b8;
P_0c06a5b8: /* original 6af6, guest PC 0x0c06a5b8 */
if(!s->budget--) { s->failed_pc=0x0c06a5b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06a5ba;
P_0c06a5ba: /* original 6bf6, guest PC 0x0c06a5ba */
if(!s->budget--) { s->failed_pc=0x0c06a5bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06a5bc;
P_0c06a5bc: /* original 6cf6, guest PC 0x0c06a5bc */
if(!s->budget--) { s->failed_pc=0x0c06a5bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06a5be;
P_0c06a5be: /* original 6df6, guest PC 0x0c06a5be */
if(!s->budget--) { s->failed_pc=0x0c06a5beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06a5c0;
P_0c06a5c0: /* original 000b, guest PC 0x0c06a5c0 */
if(!s->budget--) { s->failed_pc=0x0c06a5c0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06a5c2: /* original 6ef6, guest PC 0x0c06a5c2 */
if(!s->budget--) { s->failed_pc=0x0c06a5c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06a5c4u,s,ram);
P_0c06ada0: /* original 2fe6, guest PC 0x0c06ada0 */
if(!s->budget--) { s->failed_pc=0x0c06ada0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ada2;
P_0c06ada2: /* original 2fd6, guest PC 0x0c06ada2 */
if(!s->budget--) { s->failed_pc=0x0c06ada2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ada4;
P_0c06ada4: /* original 2fc6, guest PC 0x0c06ada4 */
if(!s->budget--) { s->failed_pc=0x0c06ada4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ada6;
P_0c06ada6: /* original ec0d, guest PC 0x0c06ada6 */
if(!s->budget--) { s->failed_pc=0x0c06ada6u; return 0; }
r[12]=0x0000000du;
goto P_0c06ada8;
P_0c06ada8: /* original 2fb6, guest PC 0x0c06ada8 */
if(!s->budget--) { s->failed_pc=0x0c06ada8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06adaa;
P_0c06adaa: /* original eb00, guest PC 0x0c06adaa */
if(!s->budget--) { s->failed_pc=0x0c06adaau; return 0; }
r[11]=0x00000000u;
goto P_0c06adac;
P_0c06adac: /* original 2fa6, guest PC 0x0c06adac */
if(!s->budget--) { s->failed_pc=0x0c06adacu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06adae;
P_0c06adae: /* original 2f96, guest PC 0x0c06adae */
if(!s->budget--) { s->failed_pc=0x0c06adaeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06adb0;
P_0c06adb0: /* original 69b3, guest PC 0x0c06adb0 */
if(!s->budget--) { s->failed_pc=0x0c06adb0u; return 0; }
r[9]=r[11];
goto P_0c06adb2;
P_0c06adb2: /* original 2f86, guest PC 0x0c06adb2 */
if(!s->budget--) { s->failed_pc=0x0c06adb2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06adb4;
P_0c06adb4: /* original fffb, guest PC 0x0c06adb4 */
if(!s->budget--) { s->failed_pc=0x0c06adb4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06adb6;
P_0c06adb6: /* original ffeb, guest PC 0x0c06adb6 */
if(!s->budget--) { s->failed_pc=0x0c06adb6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06adb8;
P_0c06adb8: /* original ffdb, guest PC 0x0c06adb8 */
if(!s->budget--) { s->failed_pc=0x0c06adb8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c06adba;
P_0c06adba: /* original 4f22, guest PC 0x0c06adba */
if(!s->budget--) { s->failed_pc=0x0c06adbau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06adbc;
P_0c06adbc: /* original 9e07, guest PC 0x0c06adbc */
if(!s->budget--) { s->failed_pc=0x0c06adbcu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06adceu,2);
goto P_0c06adbe;
P_0c06adbe: /* original d40b, guest PC 0x0c06adbe */
if(!s->budget--) { s->failed_pc=0x0c06adbeu; return 0; }
r[4]=read(ram,0x0c06adecu,4);
goto P_0c06adc0;
P_0c06adc0: /* original dd0b, guest PC 0x0c06adc0 */
if(!s->budget--) { s->failed_pc=0x0c06adc0u; return 0; }
r[13]=read(ram,0x0c06adf0u,4);
goto P_0c06adc2;
P_0c06adc2: /* original 7ff0, guest PC 0x0c06adc2 */
if(!s->budget--) { s->failed_pc=0x0c06adc2u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c06adc4;
P_0c06adc4: /* original 9a04, guest PC 0x0c06adc4 */
if(!s->budget--) { s->failed_pc=0x0c06adc4u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06add0u,2);
goto P_0c06adc6;
P_0c06adc6: /* original 3e4c, guest PC 0x0c06adc6 */
if(!s->budget--) { s->failed_pc=0x0c06adc6u; return 0; }
r[14]+=r[4];
goto P_0c06adc8;
P_0c06adc8: /* original fe8d, guest PC 0x0c06adc8 */
if(!s->budget--) { s->failed_pc=0x0c06adc8u; return 0; }
fr[14]=0;
goto P_0c06adca;
P_0c06adca: /* original a018, guest PC 0x0c06adca */
if(!s->budget--) { s->failed_pc=0x0c06adcau; return 0; }
r[10]+=r[14];
goto P_0c06adfe;
P_0c06adcc: /* original 3aec, guest PC 0x0c06adcc */
if(!s->budget--) { s->failed_pc=0x0c06adccu; return 0; }
r[10]+=r[14];
return vf3_matrix_family(0x0c06adceu,s,ram);
P_0c06adf4: /* original 4d0b, guest PC 0x0c06adf4 */
if(!s->budget--) { s->failed_pc=0x0c06adf4u; return 0; }
target=r[13];
r[16]=0x0c06adf8u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06adf8u) { target=s->pc; goto dispatch; }
goto P_0c06adf8;
P_0c06adf6: /* original 64a3, guest PC 0x0c06adf6 */
if(!s->budget--) { s->failed_pc=0x0c06adf6u; return 0; }
r[4]=r[10];
goto P_0c06adf8;
P_0c06adf8: /* original fe00, guest PC 0x0c06adf8 */
if(!s->budget--) { s->failed_pc=0x0c06adf8u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[0],r[18],'+');
goto P_0c06adfa;
P_0c06adfa: /* original 7a04, guest PC 0x0c06adfa */
if(!s->budget--) { s->failed_pc=0x0c06adfau; return 0; }
r[10]+=0x00000004u;
goto P_0c06adfc;
P_0c06adfc: /* original 7901, guest PC 0x0c06adfc */
if(!s->budget--) { s->failed_pc=0x0c06adfcu; return 0; }
r[9]+=0x00000001u;
goto P_0c06adfe;
P_0c06adfe: /* original 39c3, guest PC 0x0c06adfe */
if(!s->budget--) { s->failed_pc=0x0c06adfeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[12])!=0);
goto P_0c06ae00;
P_0c06ae00: /* original 8bf8, guest PC 0x0c06ae00 */
if(!s->budget--) { s->failed_pc=0x0c06ae00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06adf4; }
goto P_0c06ae02;
P_0c06ae02: /* original f38d, guest PC 0x0c06ae02 */
if(!s->budget--) { s->failed_pc=0x0c06ae02u; return 0; }
fr[3]=0;
goto P_0c06ae04;
P_0c06ae04: /* original f3e4, guest PC 0x0c06ae04 */
if(!s->budget--) { s->failed_pc=0x0c06ae04u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[14]))!=0);
goto P_0c06ae06;
P_0c06ae06: /* original d939, guest PC 0x0c06ae06 */
if(!s->budget--) { s->failed_pc=0x0c06ae06u; return 0; }
r[9]=read(ram,0x0c06aeecu,4);
goto P_0c06ae08;
P_0c06ae08: /* original c739, guest PC 0x0c06ae08 */
if(!s->budget--) { s->failed_pc=0x0c06ae08u; return 0; }
r[0]=0x0c06aef0u;
goto P_0c06ae0a;
P_0c06ae0a: /* original 8d12, guest PC 0x0c06ae0a */
if(!s->budget--) { s->failed_pc=0x0c06ae0au; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,15,r[0]);
if(cond) { goto P_0c06ae32; }
goto P_0c06ae0e;
P_0c06ae0c: /* original ff08, guest PC 0x0c06ae0c */
if(!s->budget--) { s->failed_pc=0x0c06ae0cu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c06ae0e;
P_0c06ae0e: /* original fef3, guest PC 0x0c06ae0e */
if(!s->budget--) { s->failed_pc=0x0c06ae0eu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'/');
goto P_0c06ae10;
P_0c06ae10: /* original 68b3, guest PC 0x0c06ae10 */
if(!s->budget--) { s->failed_pc=0x0c06ae10u; return 0; }
r[8]=r[11];
goto P_0c06ae12;
P_0c06ae12: /* original a00c, guest PC 0x0c06ae12 */
if(!s->budget--) { s->failed_pc=0x0c06ae12u; return 0; }
r[10]=r[11];
goto P_0c06ae2e;
P_0c06ae14: /* original 6ab3, guest PC 0x0c06ae14 */
if(!s->budget--) { s->failed_pc=0x0c06ae14u; return 0; }
r[10]=r[11];
goto P_0c06ae16;
P_0c06ae16: /* original 9462, guest PC 0x0c06ae16 */
if(!s->budget--) { s->failed_pc=0x0c06ae16u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aedeu,2);
goto P_0c06ae18;
P_0c06ae18: /* original 34ec, guest PC 0x0c06ae18 */
if(!s->budget--) { s->failed_pc=0x0c06ae18u; return 0; }
r[4]+=r[14];
goto P_0c06ae1a;
P_0c06ae1a: /* original 4d0b, guest PC 0x0c06ae1a */
if(!s->budget--) { s->failed_pc=0x0c06ae1au; return 0; }
target=r[13];
r[16]=0x0c06ae1eu;
r[4]+=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06ae1eu) { target=s->pc; goto dispatch; }
goto P_0c06ae1e;
P_0c06ae1c: /* original 34ac, guest PC 0x0c06ae1c */
if(!s->budget--) { s->failed_pc=0x0c06ae1cu; return 0; }
r[4]+=r[10];
goto P_0c06ae1e;
P_0c06ae1e: /* original f40c, guest PC 0x0c06ae1e */
if(!s->budget--) { s->failed_pc=0x0c06ae1eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c06ae20;
P_0c06ae20: /* original f4e3, guest PC 0x0c06ae20 */
if(!s->budget--) { s->failed_pc=0x0c06ae20u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'/');
goto P_0c06ae22;
P_0c06ae22: /* original 945d, guest PC 0x0c06ae22 */
if(!s->budget--) { s->failed_pc=0x0c06ae22u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aee0u,2);
goto P_0c06ae24;
P_0c06ae24: /* original 34ec, guest PC 0x0c06ae24 */
if(!s->budget--) { s->failed_pc=0x0c06ae24u; return 0; }
r[4]+=r[14];
goto P_0c06ae26;
P_0c06ae26: /* original 490b, guest PC 0x0c06ae26 */
if(!s->budget--) { s->failed_pc=0x0c06ae26u; return 0; }
target=r[9];
r[16]=0x0c06ae2au;
r[4]+=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06ae2au) { target=s->pc; goto dispatch; }
goto P_0c06ae2a;
P_0c06ae28: /* original 34ac, guest PC 0x0c06ae28 */
if(!s->budget--) { s->failed_pc=0x0c06ae28u; return 0; }
r[4]+=r[10];
goto P_0c06ae2a;
P_0c06ae2a: /* original 7a04, guest PC 0x0c06ae2a */
if(!s->budget--) { s->failed_pc=0x0c06ae2au; return 0; }
r[10]+=0x00000004u;
goto P_0c06ae2c;
P_0c06ae2c: /* original 7801, guest PC 0x0c06ae2c */
if(!s->budget--) { s->failed_pc=0x0c06ae2cu; return 0; }
r[8]+=0x00000001u;
goto P_0c06ae2e;
P_0c06ae2e: /* original 38c3, guest PC 0x0c06ae2e */
if(!s->budget--) { s->failed_pc=0x0c06ae2eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[12])!=0);
goto P_0c06ae30;
P_0c06ae30: /* original 8bf1, guest PC 0x0c06ae30 */
if(!s->budget--) { s->failed_pc=0x0c06ae30u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ae16; }
goto P_0c06ae32;
P_0c06ae32: /* original 1fb2, guest PC 0x0c06ae32 */
if(!s->budget--) { s->failed_pc=0x0c06ae32u; return 0; }
write(ram,r[15]+8,r[11],4);
goto P_0c06ae34;
P_0c06ae34: /* original a02a, guest PC 0x0c06ae34 */
if(!s->budget--) { s->failed_pc=0x0c06ae34u; return 0; }
write(ram,r[15]+4,r[11],4);
goto P_0c06ae8c;
P_0c06ae36: /* original 1fb1, guest PC 0x0c06ae36 */
if(!s->budget--) { s->failed_pc=0x0c06ae36u; return 0; }
write(ram,r[15]+4,r[11],4);
goto P_0c06ae38;
P_0c06ae38: /* original 55f1, guest PC 0x0c06ae38 */
if(!s->budget--) { s->failed_pc=0x0c06ae38u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c06ae3a;
P_0c06ae3a: /* original 68e3, guest PC 0x0c06ae3a */
if(!s->budget--) { s->failed_pc=0x0c06ae3au; return 0; }
r[8]=r[14];
goto P_0c06ae3c;
P_0c06ae3c: /* original 2fb2, guest PC 0x0c06ae3c */
if(!s->budget--) { s->failed_pc=0x0c06ae3cu; return 0; }
write(ram,r[15],r[11],4);
goto P_0c06ae3e;
P_0c06ae3e: /* original 6453, guest PC 0x0c06ae3e */
if(!s->budget--) { s->failed_pc=0x0c06ae3eu; return 0; }
r[4]=r[5];
goto P_0c06ae40;
P_0c06ae40: /* original 4408, guest PC 0x0c06ae40 */
if(!s->budget--) { s->failed_pc=0x0c06ae40u; return 0; }
r[4]<<=2;
goto P_0c06ae42;
P_0c06ae42: /* original 384c, guest PC 0x0c06ae42 */
if(!s->budget--) { s->failed_pc=0x0c06ae42u; return 0; }
r[8]+=r[4];
goto P_0c06ae44;
P_0c06ae44: /* original a019, guest PC 0x0c06ae44 */
if(!s->budget--) { s->failed_pc=0x0c06ae44u; return 0; }
r[10]=r[4];
goto P_0c06ae7a;
P_0c06ae46: /* original 6a43, guest PC 0x0c06ae46 */
if(!s->budget--) { s->failed_pc=0x0c06ae46u; return 0; }
r[10]=r[4];
goto P_0c06ae48;
P_0c06ae48: /* original 944b, guest PC 0x0c06ae48 */
if(!s->budget--) { s->failed_pc=0x0c06ae48u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aee2u,2);
goto P_0c06ae4a;
P_0c06ae4a: /* original 34ec, guest PC 0x0c06ae4a */
if(!s->budget--) { s->failed_pc=0x0c06ae4au; return 0; }
r[4]+=r[14];
goto P_0c06ae4c;
P_0c06ae4c: /* original 4d0b, guest PC 0x0c06ae4c */
if(!s->budget--) { s->failed_pc=0x0c06ae4cu; return 0; }
target=r[13];
r[16]=0x0c06ae50u;
r[4]+=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06ae50u) { target=s->pc; goto dispatch; }
goto P_0c06ae50;
P_0c06ae4e: /* original 34ac, guest PC 0x0c06ae4e */
if(!s->budget--) { s->failed_pc=0x0c06ae4eu; return 0; }
r[4]+=r[10];
goto P_0c06ae50;
P_0c06ae50: /* original 9448, guest PC 0x0c06ae50 */
if(!s->budget--) { s->failed_pc=0x0c06ae50u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aee4u,2);
goto P_0c06ae52;
P_0c06ae52: /* original fe0c, guest PC 0x0c06ae52 */
if(!s->budget--) { s->failed_pc=0x0c06ae52u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c06ae54;
P_0c06ae54: /* original 34ec, guest PC 0x0c06ae54 */
if(!s->budget--) { s->failed_pc=0x0c06ae54u; return 0; }
r[4]+=r[14];
goto P_0c06ae56;
P_0c06ae56: /* original 4d0b, guest PC 0x0c06ae56 */
if(!s->budget--) { s->failed_pc=0x0c06ae56u; return 0; }
target=r[13];
r[16]=0x0c06ae5au;
r[4]+=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06ae5au) { target=s->pc; goto dispatch; }
goto P_0c06ae5a;
P_0c06ae58: /* original 34ac, guest PC 0x0c06ae58 */
if(!s->budget--) { s->failed_pc=0x0c06ae58u; return 0; }
r[4]+=r[10];
goto P_0c06ae5a;
P_0c06ae5a: /* original f38d, guest PC 0x0c06ae5a */
if(!s->budget--) { s->failed_pc=0x0c06ae5au; return 0; }
fr[3]=0;
goto P_0c06ae5c;
P_0c06ae5c: /* original f40c, guest PC 0x0c06ae5c */
if(!s->budget--) { s->failed_pc=0x0c06ae5cu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c06ae5e;
P_0c06ae5e: /* original f344, guest PC 0x0c06ae5e */
if(!s->budget--) { s->failed_pc=0x0c06ae5eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[4]))!=0);
goto P_0c06ae60;
P_0c06ae60: /* original 8d04, guest PC 0x0c06ae60 */
if(!s->budget--) { s->failed_pc=0x0c06ae60u; return 0; }
cond=r[17]&1u;
r[4]=r[8];
if(cond) { goto P_0c06ae6c; }
goto P_0c06ae64;
P_0c06ae62: /* original 6483, guest PC 0x0c06ae62 */
if(!s->budget--) { s->failed_pc=0x0c06ae62u; return 0; }
r[4]=r[8];
goto P_0c06ae64;
P_0c06ae64: /* original fef2, guest PC 0x0c06ae64 */
if(!s->budget--) { s->failed_pc=0x0c06ae64u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[15],r[18],'*');
goto P_0c06ae66;
P_0c06ae66: /* original f24c, guest PC 0x0c06ae66 */
if(!s->budget--) { s->failed_pc=0x0c06ae66u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c06ae68;
P_0c06ae68: /* original f4ec, guest PC 0x0c06ae68 */
if(!s->budget--) { s->failed_pc=0x0c06ae68u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06ae6a;
P_0c06ae6a: /* original f423, guest PC 0x0c06ae6a */
if(!s->budget--) { s->failed_pc=0x0c06ae6au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'/');
goto P_0c06ae6c;
P_0c06ae6c: /* original 490b, guest PC 0x0c06ae6c */
if(!s->budget--) { s->failed_pc=0x0c06ae6cu; return 0; }
target=r[9];
r[16]=0x0c06ae70u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06ae70u) { target=s->pc; goto dispatch; }
goto P_0c06ae70;
P_0c06ae6e: /* original 0009, guest PC 0x0c06ae6e */
if(!s->budget--) { s->failed_pc=0x0c06ae6eu; return 0; }
goto P_0c06ae70;
P_0c06ae70: /* original 63f2, guest PC 0x0c06ae70 */
if(!s->budget--) { s->failed_pc=0x0c06ae70u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06ae72;
P_0c06ae72: /* original 7a04, guest PC 0x0c06ae72 */
if(!s->budget--) { s->failed_pc=0x0c06ae72u; return 0; }
r[10]+=0x00000004u;
goto P_0c06ae74;
P_0c06ae74: /* original 7804, guest PC 0x0c06ae74 */
if(!s->budget--) { s->failed_pc=0x0c06ae74u; return 0; }
r[8]+=0x00000004u;
goto P_0c06ae76;
P_0c06ae76: /* original 7301, guest PC 0x0c06ae76 */
if(!s->budget--) { s->failed_pc=0x0c06ae76u; return 0; }
r[3]+=0x00000001u;
goto P_0c06ae78;
P_0c06ae78: /* original 2f32, guest PC 0x0c06ae78 */
if(!s->budget--) { s->failed_pc=0x0c06ae78u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06ae7a;
P_0c06ae7a: /* original 63f2, guest PC 0x0c06ae7a */
if(!s->budget--) { s->failed_pc=0x0c06ae7au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06ae7c;
P_0c06ae7c: /* original 33c3, guest PC 0x0c06ae7c */
if(!s->budget--) { s->failed_pc=0x0c06ae7cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[12])!=0);
goto P_0c06ae7e;
P_0c06ae7e: /* original 8be3, guest PC 0x0c06ae7e */
if(!s->budget--) { s->failed_pc=0x0c06ae7eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ae48; }
goto P_0c06ae80;
P_0c06ae80: /* original 51f2, guest PC 0x0c06ae80 */
if(!s->budget--) { s->failed_pc=0x0c06ae80u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c06ae82;
P_0c06ae82: /* original 7101, guest PC 0x0c06ae82 */
if(!s->budget--) { s->failed_pc=0x0c06ae82u; return 0; }
r[1]+=0x00000001u;
goto P_0c06ae84;
P_0c06ae84: /* original 1f12, guest PC 0x0c06ae84 */
if(!s->budget--) { s->failed_pc=0x0c06ae84u; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c06ae86;
P_0c06ae86: /* original 53f1, guest PC 0x0c06ae86 */
if(!s->budget--) { s->failed_pc=0x0c06ae86u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06ae88;
P_0c06ae88: /* original 730d, guest PC 0x0c06ae88 */
if(!s->budget--) { s->failed_pc=0x0c06ae88u; return 0; }
r[3]+=0x0000000du;
goto P_0c06ae8a;
P_0c06ae8a: /* original 1f31, guest PC 0x0c06ae8a */
if(!s->budget--) { s->failed_pc=0x0c06ae8au; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c06ae8c;
P_0c06ae8c: /* original 52f2, guest PC 0x0c06ae8c */
if(!s->budget--) { s->failed_pc=0x0c06ae8cu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c06ae8e;
P_0c06ae8e: /* original 32c3, guest PC 0x0c06ae8e */
if(!s->budget--) { s->failed_pc=0x0c06ae8eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[12])!=0);
goto P_0c06ae90;
P_0c06ae90: /* original 8bd2, guest PC 0x0c06ae90 */
if(!s->budget--) { s->failed_pc=0x0c06ae90u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ae38; }
goto P_0c06ae92;
P_0c06ae92: /* original 2fb2, guest PC 0x0c06ae92 */
if(!s->budget--) { s->failed_pc=0x0c06ae92u; return 0; }
write(ram,r[15],r[11],4);
goto P_0c06ae94;
P_0c06ae94: /* original 9827, guest PC 0x0c06ae94 */
if(!s->budget--) { s->failed_pc=0x0c06ae94u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aee6u,2);
goto P_0c06ae96;
P_0c06ae96: /* original 38ec, guest PC 0x0c06ae96 */
if(!s->budget--) { s->failed_pc=0x0c06ae96u; return 0; }
r[8]+=r[14];
goto P_0c06ae98;
P_0c06ae98: /* original a019, guest PC 0x0c06ae98 */
if(!s->budget--) { s->failed_pc=0x0c06ae98u; return 0; }
r[10]=0x00000000u;
goto P_0c06aece;
P_0c06ae9a: /* original ea00, guest PC 0x0c06ae9a */
if(!s->budget--) { s->failed_pc=0x0c06ae9au; return 0; }
r[10]=0x00000000u;
goto P_0c06ae9c;
P_0c06ae9c: /* original 9424, guest PC 0x0c06ae9c */
if(!s->budget--) { s->failed_pc=0x0c06ae9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aee8u,2);
goto P_0c06ae9e;
P_0c06ae9e: /* original 34ec, guest PC 0x0c06ae9e */
if(!s->budget--) { s->failed_pc=0x0c06ae9eu; return 0; }
r[4]+=r[14];
goto P_0c06aea0;
P_0c06aea0: /* original 4d0b, guest PC 0x0c06aea0 */
if(!s->budget--) { s->failed_pc=0x0c06aea0u; return 0; }
target=r[13];
r[16]=0x0c06aea4u;
r[4]+=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06aea4u) { target=s->pc; goto dispatch; }
goto P_0c06aea4;
P_0c06aea2: /* original 34ac, guest PC 0x0c06aea2 */
if(!s->budget--) { s->failed_pc=0x0c06aea2u; return 0; }
r[4]+=r[10];
goto P_0c06aea4;
P_0c06aea4: /* original 9421, guest PC 0x0c06aea4 */
if(!s->budget--) { s->failed_pc=0x0c06aea4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aeeau,2);
goto P_0c06aea6;
P_0c06aea6: /* original fe0c, guest PC 0x0c06aea6 */
if(!s->budget--) { s->failed_pc=0x0c06aea6u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c06aea8;
P_0c06aea8: /* original 34ec, guest PC 0x0c06aea8 */
if(!s->budget--) { s->failed_pc=0x0c06aea8u; return 0; }
r[4]+=r[14];
goto P_0c06aeaa;
P_0c06aeaa: /* original 4d0b, guest PC 0x0c06aeaa */
if(!s->budget--) { s->failed_pc=0x0c06aeaau; return 0; }
target=r[13];
r[16]=0x0c06aeaeu;
r[4]+=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06aeaeu) { target=s->pc; goto dispatch; }
goto P_0c06aeae;
P_0c06aeac: /* original 34ac, guest PC 0x0c06aeac */
if(!s->budget--) { s->failed_pc=0x0c06aeacu; return 0; }
r[4]+=r[10];
goto P_0c06aeae;
P_0c06aeae: /* original f38d, guest PC 0x0c06aeae */
if(!s->budget--) { s->failed_pc=0x0c06aeaeu; return 0; }
fr[3]=0;
goto P_0c06aeb0;
P_0c06aeb0: /* original f40c, guest PC 0x0c06aeb0 */
if(!s->budget--) { s->failed_pc=0x0c06aeb0u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c06aeb2;
P_0c06aeb2: /* original f344, guest PC 0x0c06aeb2 */
if(!s->budget--) { s->failed_pc=0x0c06aeb2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[4]))!=0);
goto P_0c06aeb4;
P_0c06aeb4: /* original 8d04, guest PC 0x0c06aeb4 */
if(!s->budget--) { s->failed_pc=0x0c06aeb4u; return 0; }
cond=r[17]&1u;
r[4]=r[8];
if(cond) { goto P_0c06aec0; }
goto P_0c06aeb8;
P_0c06aeb6: /* original 6483, guest PC 0x0c06aeb6 */
if(!s->budget--) { s->failed_pc=0x0c06aeb6u; return 0; }
r[4]=r[8];
goto P_0c06aeb8;
P_0c06aeb8: /* original f24c, guest PC 0x0c06aeb8 */
if(!s->budget--) { s->failed_pc=0x0c06aeb8u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c06aeba;
P_0c06aeba: /* original f4ec, guest PC 0x0c06aeba */
if(!s->budget--) { s->failed_pc=0x0c06aebau; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06aebc;
P_0c06aebc: /* original f423, guest PC 0x0c06aebc */
if(!s->budget--) { s->failed_pc=0x0c06aebcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'/');
goto P_0c06aebe;
P_0c06aebe: /* original f4f2, guest PC 0x0c06aebe */
if(!s->budget--) { s->failed_pc=0x0c06aebeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c06aec0;
P_0c06aec0: /* original 490b, guest PC 0x0c06aec0 */
if(!s->budget--) { s->failed_pc=0x0c06aec0u; return 0; }
target=r[9];
r[16]=0x0c06aec4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06aec4u) { target=s->pc; goto dispatch; }
goto P_0c06aec4;
P_0c06aec2: /* original 0009, guest PC 0x0c06aec2 */
if(!s->budget--) { s->failed_pc=0x0c06aec2u; return 0; }
goto P_0c06aec4;
P_0c06aec4: /* original 63f2, guest PC 0x0c06aec4 */
if(!s->budget--) { s->failed_pc=0x0c06aec4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06aec6;
P_0c06aec6: /* original 7a04, guest PC 0x0c06aec6 */
if(!s->budget--) { s->failed_pc=0x0c06aec6u; return 0; }
r[10]+=0x00000004u;
goto P_0c06aec8;
P_0c06aec8: /* original 7804, guest PC 0x0c06aec8 */
if(!s->budget--) { s->failed_pc=0x0c06aec8u; return 0; }
r[8]+=0x00000004u;
goto P_0c06aeca;
P_0c06aeca: /* original 7301, guest PC 0x0c06aeca */
if(!s->budget--) { s->failed_pc=0x0c06aecau; return 0; }
r[3]+=0x00000001u;
goto P_0c06aecc;
P_0c06aecc: /* original 2f32, guest PC 0x0c06aecc */
if(!s->budget--) { s->failed_pc=0x0c06aeccu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06aece;
P_0c06aece: /* original 63f2, guest PC 0x0c06aece */
if(!s->budget--) { s->failed_pc=0x0c06aeceu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c06aed0;
P_0c06aed0: /* original 33c3, guest PC 0x0c06aed0 */
if(!s->budget--) { s->failed_pc=0x0c06aed0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[12])!=0);
goto P_0c06aed2;
P_0c06aed2: /* original 8be3, guest PC 0x0c06aed2 */
if(!s->budget--) { s->failed_pc=0x0c06aed2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ae9c; }
goto P_0c06aed4;
P_0c06aed4: /* original 2fb0, guest PC 0x0c06aed4 */
if(!s->budget--) { s->failed_pc=0x0c06aed4u; return 0; }
write(ram,r[15],r[11],1);
goto P_0c06aed6;
P_0c06aed6: /* original da08, guest PC 0x0c06aed6 */
if(!s->budget--) { s->failed_pc=0x0c06aed6u; return 0; }
r[10]=read(ram,0x0c06aef8u,4);
goto P_0c06aed8;
P_0c06aed8: /* original d906, guest PC 0x0c06aed8 */
if(!s->budget--) { s->failed_pc=0x0c06aed8u; return 0; }
r[9]=read(ram,0x0c06aef4u,4);
goto P_0c06aeda;
P_0c06aeda: /* original a026, guest PC 0x0c06aeda */
if(!s->budget--) { s->failed_pc=0x0c06aedau; return 0; }
r[8]=r[11];
goto P_0c06af2a;
P_0c06aedc: /* original 68b3, guest PC 0x0c06aedc */
if(!s->budget--) { s->failed_pc=0x0c06aedcu; return 0; }
r[8]=r[11];
return vf3_matrix_family(0x0c06aedeu,s,ram);
P_0c06aefc: /* original 6483, guest PC 0x0c06aefc */
if(!s->budget--) { s->failed_pc=0x0c06aefcu; return 0; }
r[4]=r[8];
goto P_0c06aefe;
P_0c06aefe: /* original 4408, guest PC 0x0c06aefe */
if(!s->budget--) { s->failed_pc=0x0c06aefeu; return 0; }
r[4]<<=2;
goto P_0c06af00;
P_0c06af00: /* original 1f41, guest PC 0x0c06af00 */
if(!s->budget--) { s->failed_pc=0x0c06af00u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c06af02;
P_0c06af02: /* original 9373, guest PC 0x0c06af02 */
if(!s->budget--) { s->failed_pc=0x0c06af02u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06afecu,2);
goto P_0c06af04;
P_0c06af04: /* original 33ec, guest PC 0x0c06af04 */
if(!s->budget--) { s->failed_pc=0x0c06af04u; return 0; }
r[3]+=r[14];
goto P_0c06af06;
P_0c06af06: /* original 4d0b, guest PC 0x0c06af06 */
if(!s->budget--) { s->failed_pc=0x0c06af06u; return 0; }
target=r[13];
r[16]=0x0c06af0au;
r[4]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06af0au) { target=s->pc; goto dispatch; }
goto P_0c06af0a;
P_0c06af08: /* original 343c, guest PC 0x0c06af08 */
if(!s->budget--) { s->failed_pc=0x0c06af08u; return 0; }
r[4]+=r[3];
goto P_0c06af0a;
P_0c06af0a: /* original 9270, guest PC 0x0c06af0a */
if(!s->budget--) { s->failed_pc=0x0c06af0au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06afeeu,2);
goto P_0c06af0c;
P_0c06af0c: /* original 53f1, guest PC 0x0c06af0c */
if(!s->budget--) { s->failed_pc=0x0c06af0cu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06af0e;
P_0c06af0e: /* original 32ac, guest PC 0x0c06af0e */
if(!s->budget--) { s->failed_pc=0x0c06af0eu; return 0; }
r[2]+=r[10];
goto P_0c06af10;
P_0c06af10: /* original f40c, guest PC 0x0c06af10 */
if(!s->budget--) { s->failed_pc=0x0c06af10u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c06af12;
P_0c06af12: /* original 323c, guest PC 0x0c06af12 */
if(!s->budget--) { s->failed_pc=0x0c06af12u; return 0; }
r[2]+=r[3];
goto P_0c06af14;
P_0c06af14: /* original f24a, guest PC 0x0c06af14 */
if(!s->budget--) { s->failed_pc=0x0c06af14u; return 0; }
vf3_matrix_store(s,ram,4,r[2]);
goto P_0c06af16;
P_0c06af16: /* original 936b, guest PC 0x0c06af16 */
if(!s->budget--) { s->failed_pc=0x0c06af16u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aff0u,2);
goto P_0c06af18;
P_0c06af18: /* original 64f0, guest PC 0x0c06af18 */
if(!s->budget--) { s->failed_pc=0x0c06af18u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[4]=tmp;
goto P_0c06af1a;
P_0c06af1a: /* original 65f0, guest PC 0x0c06af1a */
if(!s->budget--) { s->failed_pc=0x0c06af1au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[5]=tmp;
goto P_0c06af1c;
P_0c06af1c: /* original 33ec, guest PC 0x0c06af1c */
if(!s->budget--) { s->failed_pc=0x0c06af1cu; return 0; }
r[3]+=r[14];
goto P_0c06af1e;
P_0c06af1e: /* original 490b, guest PC 0x0c06af1e */
if(!s->budget--) { s->failed_pc=0x0c06af1eu; return 0; }
target=r[9];
r[16]=0x0c06af22u;
r[4]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06af22u) { target=s->pc; goto dispatch; }
goto P_0c06af22;
P_0c06af20: /* original 343c, guest PC 0x0c06af20 */
if(!s->budget--) { s->failed_pc=0x0c06af20u; return 0; }
r[4]+=r[3];
goto P_0c06af22;
P_0c06af22: /* original 62f0, guest PC 0x0c06af22 */
if(!s->budget--) { s->failed_pc=0x0c06af22u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[2]=tmp;
goto P_0c06af24;
P_0c06af24: /* original 7801, guest PC 0x0c06af24 */
if(!s->budget--) { s->failed_pc=0x0c06af24u; return 0; }
r[8]+=0x00000001u;
goto P_0c06af26;
P_0c06af26: /* original 7201, guest PC 0x0c06af26 */
if(!s->budget--) { s->failed_pc=0x0c06af26u; return 0; }
r[2]+=0x00000001u;
goto P_0c06af28;
P_0c06af28: /* original 2f20, guest PC 0x0c06af28 */
if(!s->budget--) { s->failed_pc=0x0c06af28u; return 0; }
write(ram,r[15],r[2],1);
goto P_0c06af2a;
P_0c06af2a: /* original 38c3, guest PC 0x0c06af2a */
if(!s->budget--) { s->failed_pc=0x0c06af2au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[12])!=0);
goto P_0c06af2c;
P_0c06af2c: /* original 8be6, guest PC 0x0c06af2c */
if(!s->budget--) { s->failed_pc=0x0c06af2cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06aefc; }
goto P_0c06af2e;
P_0c06af2e: /* original e401, guest PC 0x0c06af2e */
if(!s->budget--) { s->failed_pc=0x0c06af2eu; return 0; }
r[4]=0x00000001u;
goto P_0c06af30;
P_0c06af30: /* original 6043, guest PC 0x0c06af30 */
if(!s->budget--) { s->failed_pc=0x0c06af30u; return 0; }
r[0]=r[4];
goto P_0c06af32;
P_0c06af32: /* original 80f4, guest PC 0x0c06af32 */
if(!s->budget--) { s->failed_pc=0x0c06af32u; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c06af34;
P_0c06af34: /* original a047, guest PC 0x0c06af34 */
if(!s->budget--) { s->failed_pc=0x0c06af34u; return 0; }
r[12]=r[11];
goto P_0c06afc6;
P_0c06af36: /* original 6cb3, guest PC 0x0c06af36 */
if(!s->budget--) { s->failed_pc=0x0c06af36u; return 0; }
r[12]=r[11];
goto P_0c06af38;
P_0c06af38: /* original 9459, guest PC 0x0c06af38 */
if(!s->budget--) { s->failed_pc=0x0c06af38u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06afeeu,2);
goto P_0c06af3a;
P_0c06af3a: /* original 60c3, guest PC 0x0c06af3a */
if(!s->budget--) { s->failed_pc=0x0c06af3au; return 0; }
r[0]=r[12];
goto P_0c06af3c;
P_0c06af3c: /* original 4008, guest PC 0x0c06af3c */
if(!s->budget--) { s->failed_pc=0x0c06af3cu; return 0; }
r[0]<<=2;
goto P_0c06af3e;
P_0c06af3e: /* original 34ac, guest PC 0x0c06af3e */
if(!s->budget--) { s->failed_pc=0x0c06af3eu; return 0; }
r[4]+=r[10];
goto P_0c06af40;
P_0c06af40: /* original 1f02, guest PC 0x0c06af40 */
if(!s->budget--) { s->failed_pc=0x0c06af40u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c06af42;
P_0c06af42: /* original ff46, guest PC 0x0c06af42 */
if(!s->budget--) { s->failed_pc=0x0c06af42u; return 0; }
vf3_matrix_load(s,ram,15,r[4]+r[0]);
goto P_0c06af44;
P_0c06af44: /* original 60c3, guest PC 0x0c06af44 */
if(!s->budget--) { s->failed_pc=0x0c06af44u; return 0; }
r[0]=r[12];
goto P_0c06af46;
P_0c06af46: /* original 7001, guest PC 0x0c06af46 */
if(!s->budget--) { s->failed_pc=0x0c06af46u; return 0; }
r[0]+=0x00000001u;
goto P_0c06af48;
P_0c06af48: /* original 4008, guest PC 0x0c06af48 */
if(!s->budget--) { s->failed_pc=0x0c06af48u; return 0; }
r[0]<<=2;
goto P_0c06af4a;
P_0c06af4a: /* original 1f03, guest PC 0x0c06af4a */
if(!s->budget--) { s->failed_pc=0x0c06af4au; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c06af4c;
P_0c06af4c: /* original fe46, guest PC 0x0c06af4c */
if(!s->budget--) { s->failed_pc=0x0c06af4cu; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c06af4e;
P_0c06af4e: /* original 944f, guest PC 0x0c06af4e */
if(!s->budget--) { s->failed_pc=0x0c06af4eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aff0u,2);
goto P_0c06af50;
P_0c06af50: /* original d328, guest PC 0x0c06af50 */
if(!s->budget--) { s->failed_pc=0x0c06af50u; return 0; }
r[3]=read(ram,0x0c06aff4u,4);
goto P_0c06af52;
P_0c06af52: /* original 34ec, guest PC 0x0c06af52 */
if(!s->budget--) { s->failed_pc=0x0c06af52u; return 0; }
r[4]+=r[14];
goto P_0c06af54;
P_0c06af54: /* original 430b, guest PC 0x0c06af54 */
if(!s->budget--) { s->failed_pc=0x0c06af54u; return 0; }
target=r[3];
r[16]=0x0c06af58u;
r[4]+=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06af58u) { target=s->pc; goto dispatch; }
goto P_0c06af58;
P_0c06af56: /* original 34cc, guest PC 0x0c06af56 */
if(!s->budget--) { s->failed_pc=0x0c06af56u; return 0; }
r[4]+=r[12];
goto P_0c06af58;
P_0c06af58: /* original 934a, guest PC 0x0c06af58 */
if(!s->budget--) { s->failed_pc=0x0c06af58u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aff0u,2);
goto P_0c06af5a;
P_0c06af5a: /* original 64c3, guest PC 0x0c06af5a */
if(!s->budget--) { s->failed_pc=0x0c06af5au; return 0; }
r[4]=r[12];
goto P_0c06af5c;
P_0c06af5c: /* original d225, guest PC 0x0c06af5c */
if(!s->budget--) { s->failed_pc=0x0c06af5cu; return 0; }
r[2]=read(ram,0x0c06aff4u,4);
goto P_0c06af5e;
P_0c06af5e: /* original 680c, guest PC 0x0c06af5e */
if(!s->budget--) { s->failed_pc=0x0c06af5eu; return 0; }
r[8]=r[0]&255u;
goto P_0c06af60;
P_0c06af60: /* original 33ec, guest PC 0x0c06af60 */
if(!s->budget--) { s->failed_pc=0x0c06af60u; return 0; }
r[3]+=r[14];
goto P_0c06af62;
P_0c06af62: /* original 7401, guest PC 0x0c06af62 */
if(!s->budget--) { s->failed_pc=0x0c06af62u; return 0; }
r[4]+=0x00000001u;
goto P_0c06af64;
P_0c06af64: /* original 420b, guest PC 0x0c06af64 */
if(!s->budget--) { s->failed_pc=0x0c06af64u; return 0; }
target=r[2];
r[16]=0x0c06af68u;
r[4]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06af68u) { target=s->pc; goto dispatch; }
goto P_0c06af68;
P_0c06af66: /* original 343c, guest PC 0x0c06af66 */
if(!s->budget--) { s->failed_pc=0x0c06af66u; return 0; }
r[4]+=r[3];
goto P_0c06af68;
P_0c06af68: /* original 6483, guest PC 0x0c06af68 */
if(!s->budget--) { s->failed_pc=0x0c06af68u; return 0; }
r[4]=r[8];
goto P_0c06af6a;
P_0c06af6a: /* original 600c, guest PC 0x0c06af6a */
if(!s->budget--) { s->failed_pc=0x0c06af6au; return 0; }
r[0]=r[0]&255u;
goto P_0c06af6c;
P_0c06af6c: /* original 2f02, guest PC 0x0c06af6c */
if(!s->budget--) { s->failed_pc=0x0c06af6cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06af6e;
P_0c06af6e: /* original 4408, guest PC 0x0c06af6e */
if(!s->budget--) { s->failed_pc=0x0c06af6eu; return 0; }
r[4]<<=2;
goto P_0c06af70;
P_0c06af70: /* original 933f, guest PC 0x0c06af70 */
if(!s->budget--) { s->failed_pc=0x0c06af70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aff2u,2);
goto P_0c06af72;
P_0c06af72: /* original 33ec, guest PC 0x0c06af72 */
if(!s->budget--) { s->failed_pc=0x0c06af72u; return 0; }
r[3]+=r[14];
goto P_0c06af74;
P_0c06af74: /* original 4d0b, guest PC 0x0c06af74 */
if(!s->budget--) { s->failed_pc=0x0c06af74u; return 0; }
target=r[13];
r[16]=0x0c06af78u;
r[4]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06af78u) { target=s->pc; goto dispatch; }
goto P_0c06af78;
P_0c06af76: /* original 343c, guest PC 0x0c06af76 */
if(!s->budget--) { s->failed_pc=0x0c06af76u; return 0; }
r[4]+=r[3];
goto P_0c06af78;
P_0c06af78: /* original 933b, guest PC 0x0c06af78 */
if(!s->budget--) { s->failed_pc=0x0c06af78u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aff2u,2);
goto P_0c06af7a;
P_0c06af7a: /* original 64f2, guest PC 0x0c06af7a */
if(!s->budget--) { s->failed_pc=0x0c06af7au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06af7c;
P_0c06af7c: /* original 33ec, guest PC 0x0c06af7c */
if(!s->budget--) { s->failed_pc=0x0c06af7cu; return 0; }
r[3]+=r[14];
goto P_0c06af7e;
P_0c06af7e: /* original fd0c, guest PC 0x0c06af7e */
if(!s->budget--) { s->failed_pc=0x0c06af7eu; return 0; }
vf3_matrix_move(s,13,0);
goto P_0c06af80;
P_0c06af80: /* original 4408, guest PC 0x0c06af80 */
if(!s->budget--) { s->failed_pc=0x0c06af80u; return 0; }
r[4]<<=2;
goto P_0c06af82;
P_0c06af82: /* original 4d0b, guest PC 0x0c06af82 */
if(!s->budget--) { s->failed_pc=0x0c06af82u; return 0; }
target=r[13];
r[16]=0x0c06af86u;
r[4]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06af86u) { target=s->pc; goto dispatch; }
goto P_0c06af86;
P_0c06af84: /* original 343c, guest PC 0x0c06af84 */
if(!s->budget--) { s->failed_pc=0x0c06af84u; return 0; }
r[4]+=r[3];
goto P_0c06af86;
P_0c06af86: /* original fef5, guest PC 0x0c06af86 */
if(!s->budget--) { s->failed_pc=0x0c06af86u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[15]))!=0);
goto P_0c06af88;
P_0c06af88: /* original 8d04, guest PC 0x0c06af88 */
if(!s->budget--) { s->failed_pc=0x0c06af88u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,0);
if(cond) { goto P_0c06af94; }
goto P_0c06af8c;
P_0c06af8a: /* original f40c, guest PC 0x0c06af8a */
if(!s->budget--) { s->failed_pc=0x0c06af8au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c06af8c;
P_0c06af8c: /* original ffe5, guest PC 0x0c06af8c */
if(!s->budget--) { s->failed_pc=0x0c06af8cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[14]))!=0);
goto P_0c06af8e;
P_0c06af8e: /* original 8919, guest PC 0x0c06af8e */
if(!s->budget--) { s->failed_pc=0x0c06af8eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06afc4; }
goto P_0c06af90;
P_0c06af90: /* original f4d5, guest PC 0x0c06af90 */
if(!s->budget--) { s->failed_pc=0x0c06af90u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[13]))!=0);
goto P_0c06af92;
P_0c06af92: /* original 8b17, guest PC 0x0c06af92 */
if(!s->budget--) { s->failed_pc=0x0c06af92u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06afc4; }
goto P_0c06af94;
P_0c06af94: /* original 922b, guest PC 0x0c06af94 */
if(!s->budget--) { s->failed_pc=0x0c06af94u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06afeeu,2);
goto P_0c06af96;
P_0c06af96: /* original 64c3, guest PC 0x0c06af96 */
if(!s->budget--) { s->failed_pc=0x0c06af96u; return 0; }
r[4]=r[12];
goto P_0c06af98;
P_0c06af98: /* original 53f3, guest PC 0x0c06af98 */
if(!s->budget--) { s->failed_pc=0x0c06af98u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c06af9a;
P_0c06af9a: /* original 6583, guest PC 0x0c06af9a */
if(!s->budget--) { s->failed_pc=0x0c06af9au; return 0; }
r[5]=r[8];
goto P_0c06af9c;
P_0c06af9c: /* original 32ac, guest PC 0x0c06af9c */
if(!s->budget--) { s->failed_pc=0x0c06af9cu; return 0; }
r[2]+=r[10];
goto P_0c06af9e;
P_0c06af9e: /* original 323c, guest PC 0x0c06af9e */
if(!s->budget--) { s->failed_pc=0x0c06af9eu; return 0; }
r[2]+=r[3];
goto P_0c06afa0;
P_0c06afa0: /* original f2fa, guest PC 0x0c06afa0 */
if(!s->budget--) { s->failed_pc=0x0c06afa0u; return 0; }
vf3_matrix_store(s,ram,15,r[2]);
goto P_0c06afa2;
P_0c06afa2: /* original 7401, guest PC 0x0c06afa2 */
if(!s->budget--) { s->failed_pc=0x0c06afa2u; return 0; }
r[4]+=0x00000001u;
goto P_0c06afa4;
P_0c06afa4: /* original 9223, guest PC 0x0c06afa4 */
if(!s->budget--) { s->failed_pc=0x0c06afa4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06afeeu,2);
goto P_0c06afa6;
P_0c06afa6: /* original 53f2, guest PC 0x0c06afa6 */
if(!s->budget--) { s->failed_pc=0x0c06afa6u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c06afa8;
P_0c06afa8: /* original 32ac, guest PC 0x0c06afa8 */
if(!s->budget--) { s->failed_pc=0x0c06afa8u; return 0; }
r[2]+=r[10];
goto P_0c06afaa;
P_0c06afaa: /* original 323c, guest PC 0x0c06afaa */
if(!s->budget--) { s->failed_pc=0x0c06afaau; return 0; }
r[2]+=r[3];
goto P_0c06afac;
P_0c06afac: /* original f2ea, guest PC 0x0c06afac */
if(!s->budget--) { s->failed_pc=0x0c06afacu; return 0; }
vf3_matrix_store(s,ram,14,r[2]);
goto P_0c06afae;
P_0c06afae: /* original 931f, guest PC 0x0c06afae */
if(!s->budget--) { s->failed_pc=0x0c06afaeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aff0u,2);
goto P_0c06afb0;
P_0c06afb0: /* original 33ec, guest PC 0x0c06afb0 */
if(!s->budget--) { s->failed_pc=0x0c06afb0u; return 0; }
r[3]+=r[14];
goto P_0c06afb2;
P_0c06afb2: /* original 490b, guest PC 0x0c06afb2 */
if(!s->budget--) { s->failed_pc=0x0c06afb2u; return 0; }
target=r[9];
r[16]=0x0c06afb6u;
r[4]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06afb6u) { target=s->pc; goto dispatch; }
goto P_0c06afb6;
P_0c06afb4: /* original 343c, guest PC 0x0c06afb4 */
if(!s->budget--) { s->failed_pc=0x0c06afb4u; return 0; }
r[4]+=r[3];
goto P_0c06afb6;
P_0c06afb6: /* original 941b, guest PC 0x0c06afb6 */
if(!s->budget--) { s->failed_pc=0x0c06afb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06aff0u,2);
goto P_0c06afb8;
P_0c06afb8: /* original 65f2, guest PC 0x0c06afb8 */
if(!s->budget--) { s->failed_pc=0x0c06afb8u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06afba;
P_0c06afba: /* original 34ec, guest PC 0x0c06afba */
if(!s->budget--) { s->failed_pc=0x0c06afbau; return 0; }
r[4]+=r[14];
goto P_0c06afbc;
P_0c06afbc: /* original 490b, guest PC 0x0c06afbc */
if(!s->budget--) { s->failed_pc=0x0c06afbcu; return 0; }
target=r[9];
r[16]=0x0c06afc0u;
r[4]+=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06afc0u) { target=s->pc; goto dispatch; }
goto P_0c06afc0;
P_0c06afbe: /* original 34cc, guest PC 0x0c06afbe */
if(!s->budget--) { s->failed_pc=0x0c06afbeu; return 0; }
r[4]+=r[12];
goto P_0c06afc0;
P_0c06afc0: /* original 60b3, guest PC 0x0c06afc0 */
if(!s->budget--) { s->failed_pc=0x0c06afc0u; return 0; }
r[0]=r[11];
goto P_0c06afc2;
P_0c06afc2: /* original 80f4, guest PC 0x0c06afc2 */
if(!s->budget--) { s->failed_pc=0x0c06afc2u; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c06afc4;
P_0c06afc4: /* original 7c01, guest PC 0x0c06afc4 */
if(!s->budget--) { s->failed_pc=0x0c06afc4u; return 0; }
r[12]+=0x00000001u;
goto P_0c06afc6;
P_0c06afc6: /* original e40c, guest PC 0x0c06afc6 */
if(!s->budget--) { s->failed_pc=0x0c06afc6u; return 0; }
r[4]=0x0000000cu;
goto P_0c06afc8;
P_0c06afc8: /* original 3c43, guest PC 0x0c06afc8 */
if(!s->budget--) { s->failed_pc=0x0c06afc8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[4])!=0);
goto P_0c06afca;
P_0c06afca: /* original 8bb5, guest PC 0x0c06afca */
if(!s->budget--) { s->failed_pc=0x0c06afcau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06af38; }
goto P_0c06afcc;
P_0c06afcc: /* original 84f4, guest PC 0x0c06afcc */
if(!s->budget--) { s->failed_pc=0x0c06afccu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c06afce;
P_0c06afce: /* original 2008, guest PC 0x0c06afce */
if(!s->budget--) { s->failed_pc=0x0c06afceu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06afd0;
P_0c06afd0: /* original 89ad, guest PC 0x0c06afd0 */
if(!s->budget--) { s->failed_pc=0x0c06afd0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06af2e; }
goto P_0c06afd2;
P_0c06afd2: /* original 7f10, guest PC 0x0c06afd2 */
if(!s->budget--) { s->failed_pc=0x0c06afd2u; return 0; }
r[15]+=0x00000010u;
goto P_0c06afd4;
P_0c06afd4: /* original 4f26, guest PC 0x0c06afd4 */
if(!s->budget--) { s->failed_pc=0x0c06afd4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06afd6;
P_0c06afd6: /* original fdf9, guest PC 0x0c06afd6 */
if(!s->budget--) { s->failed_pc=0x0c06afd6u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06afd8;
P_0c06afd8: /* original fef9, guest PC 0x0c06afd8 */
if(!s->budget--) { s->failed_pc=0x0c06afd8u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06afda;
P_0c06afda: /* original fff9, guest PC 0x0c06afda */
if(!s->budget--) { s->failed_pc=0x0c06afdau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06afdc;
P_0c06afdc: /* original 68f6, guest PC 0x0c06afdc */
if(!s->budget--) { s->failed_pc=0x0c06afdcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06afde;
P_0c06afde: /* original 69f6, guest PC 0x0c06afde */
if(!s->budget--) { s->failed_pc=0x0c06afdeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06afe0;
P_0c06afe0: /* original 6af6, guest PC 0x0c06afe0 */
if(!s->budget--) { s->failed_pc=0x0c06afe0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06afe2;
P_0c06afe2: /* original 6bf6, guest PC 0x0c06afe2 */
if(!s->budget--) { s->failed_pc=0x0c06afe2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06afe4;
P_0c06afe4: /* original 6cf6, guest PC 0x0c06afe4 */
if(!s->budget--) { s->failed_pc=0x0c06afe4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06afe6;
P_0c06afe6: /* original 6df6, guest PC 0x0c06afe6 */
if(!s->budget--) { s->failed_pc=0x0c06afe6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06afe8;
P_0c06afe8: /* original 000b, guest PC 0x0c06afe8 */
if(!s->budget--) { s->failed_pc=0x0c06afe8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06afea: /* original 6ef6, guest PC 0x0c06afea */
if(!s->budget--) { s->failed_pc=0x0c06afeau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06afecu,s,ram);
P_0c06c398: /* original 4f22, guest PC 0x0c06c398 */
if(!s->budget--) { s->failed_pc=0x0c06c398u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c39a;
P_0c06c39a: /* original e21f, guest PC 0x0c06c39a */
if(!s->budget--) { s->failed_pc=0x0c06c39au; return 0; }
r[2]=0x0000001fu;
goto P_0c06c39c;
P_0c06c39c: /* original e108, guest PC 0x0c06c39c */
if(!s->budget--) { s->failed_pc=0x0c06c39cu; return 0; }
r[1]=0x00000008u;
goto P_0c06c39e;
P_0c06c39e: /* original 7ffc, guest PC 0x0c06c39e */
if(!s->budget--) { s->failed_pc=0x0c06c39eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c3a0;
P_0c06c3a0: /* original 2f42, guest PC 0x0c06c3a0 */
if(!s->budget--) { s->failed_pc=0x0c06c3a0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06c3a2;
P_0c06c3a2: /* original d337, guest PC 0x0c06c3a2 */
if(!s->budget--) { s->failed_pc=0x0c06c3a2u; return 0; }
r[3]=read(ram,0x0c06c480u,4);
goto P_0c06c3a4;
P_0c06c3a4: /* original d435, guest PC 0x0c06c3a4 */
if(!s->budget--) { s->failed_pc=0x0c06c3a4u; return 0; }
r[4]=read(ram,0x0c06c47cu,4);
goto P_0c06c3a6;
P_0c06c3a6: /* original 6532, guest PC 0x0c06c3a6 */
if(!s->budget--) { s->failed_pc=0x0c06c3a6u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06c3a8;
P_0c06c3a8: /* original 2529, guest PC 0x0c06c3a8 */
if(!s->budget--) { s->failed_pc=0x0c06c3a8u; return 0; }
r[5]&=r[2];
goto P_0c06c3aa;
P_0c06c3aa: /* original 3513, guest PC 0x0c06c3aa */
if(!s->budget--) { s->failed_pc=0x0c06c3aau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[1])!=0);
goto P_0c06c3ac;
P_0c06c3ac: /* original 8b03, guest PC 0x0c06c3ac */
if(!s->budget--) { s->failed_pc=0x0c06c3acu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c3b6; }
goto P_0c06c3ae;
P_0c06c3ae: /* original 7f04, guest PC 0x0c06c3ae */
if(!s->budget--) { s->failed_pc=0x0c06c3aeu; return 0; }
r[15]+=0x00000004u;
goto P_0c06c3b0;
P_0c06c3b0: /* original 4f26, guest PC 0x0c06c3b0 */
if(!s->budget--) { s->failed_pc=0x0c06c3b0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c3b2;
P_0c06c3b2: /* original 000b, guest PC 0x0c06c3b2 */
if(!s->budget--) { s->failed_pc=0x0c06c3b2u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c06c3b4: /* original 6053, guest PC 0x0c06c3b4 */
if(!s->budget--) { s->failed_pc=0x0c06c3b4u; return 0; }
r[0]=r[5];
goto P_0c06c3b6;
P_0c06c3b6: /* original e220, guest PC 0x0c06c3b6 */
if(!s->budget--) { s->failed_pc=0x0c06c3b6u; return 0; }
r[2]=0x00000020u;
goto P_0c06c3b8;
P_0c06c3b8: /* original e618, guest PC 0x0c06c3b8 */
if(!s->budget--) { s->failed_pc=0x0c06c3b8u; return 0; }
r[6]=0x00000018u;
goto P_0c06c3ba;
P_0c06c3ba: /* original 2f26, guest PC 0x0c06c3ba */
if(!s->budget--) { s->failed_pc=0x0c06c3bau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c3bc;
P_0c06c3bc: /* original d331, guest PC 0x0c06c3bc */
if(!s->budget--) { s->failed_pc=0x0c06c3bcu; return 0; }
r[3]=read(ram,0x0c06c484u,4);
goto P_0c06c3be;
P_0c06c3be: /* original e701, guest PC 0x0c06c3be */
if(!s->budget--) { s->failed_pc=0x0c06c3beu; return 0; }
r[7]=0x00000001u;
goto P_0c06c3c0;
P_0c06c3c0: /* original 430b, guest PC 0x0c06c3c0 */
if(!s->budget--) { s->failed_pc=0x0c06c3c0u; return 0; }
target=r[3];
r[16]=0x0c06c3c4u;
r[5]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06c3c4u) { target=s->pc; goto dispatch; }
goto P_0c06c3c4;
P_0c06c3c2: /* original 55f1, guest PC 0x0c06c3c2 */
if(!s->budget--) { s->failed_pc=0x0c06c3c2u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c06c3c4;
P_0c06c3c4: /* original e000, guest PC 0x0c06c3c4 */
if(!s->budget--) { s->failed_pc=0x0c06c3c4u; return 0; }
r[0]=0x00000000u;
goto P_0c06c3c6;
P_0c06c3c6: /* original 7f04, guest PC 0x0c06c3c6 */
if(!s->budget--) { s->failed_pc=0x0c06c3c6u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c3c8;
P_0c06c3c8: /* original 7f04, guest PC 0x0c06c3c8 */
if(!s->budget--) { s->failed_pc=0x0c06c3c8u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c3ca;
P_0c06c3ca: /* original 4f26, guest PC 0x0c06c3ca */
if(!s->budget--) { s->failed_pc=0x0c06c3cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c3cc;
P_0c06c3cc: /* original 000b, guest PC 0x0c06c3cc */
if(!s->budget--) { s->failed_pc=0x0c06c3ccu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06c3ce: /* original 0009, guest PC 0x0c06c3ce */
if(!s->budget--) { s->failed_pc=0x0c06c3ceu; return 0; }
return vf3_matrix_family(0x0c06c3d0u,s,ram);
P_0c06c8a4: /* original 2fe6, guest PC 0x0c06c8a4 */
if(!s->budget--) { s->failed_pc=0x0c06c8a4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c8a6;
P_0c06c8a6: /* original e207, guest PC 0x0c06c8a6 */
if(!s->budget--) { s->failed_pc=0x0c06c8a6u; return 0; }
r[2]=0x00000007u;
goto P_0c06c8a8;
P_0c06c8a8: /* original 2fd6, guest PC 0x0c06c8a8 */
if(!s->budget--) { s->failed_pc=0x0c06c8a8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c8aa;
P_0c06c8aa: /* original ee08, guest PC 0x0c06c8aa */
if(!s->budget--) { s->failed_pc=0x0c06c8aau; return 0; }
r[14]=0x00000008u;
goto P_0c06c8ac;
P_0c06c8ac: /* original d317, guest PC 0x0c06c8ac */
if(!s->budget--) { s->failed_pc=0x0c06c8acu; return 0; }
r[3]=read(ram,0x0c06c90cu,4);
goto P_0c06c8ae;
P_0c06c8ae: /* original 9023, guest PC 0x0c06c8ae */
if(!s->budget--) { s->failed_pc=0x0c06c8aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8f8u,2);
goto P_0c06c8b0;
P_0c06c8b0: /* original 6432, guest PC 0x0c06c8b0 */
if(!s->budget--) { s->failed_pc=0x0c06c8b0u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c06c8b2;
P_0c06c8b2: /* original 4f22, guest PC 0x0c06c8b2 */
if(!s->budget--) { s->failed_pc=0x0c06c8b2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c8b4;
P_0c06c8b4: /* original 7401, guest PC 0x0c06c8b4 */
if(!s->budget--) { s->failed_pc=0x0c06c8b4u; return 0; }
r[4]+=0x00000001u;
goto P_0c06c8b6;
P_0c06c8b6: /* original 6543, guest PC 0x0c06c8b6 */
if(!s->budget--) { s->failed_pc=0x0c06c8b6u; return 0; }
r[5]=r[4];
goto P_0c06c8b8;
P_0c06c8b8: /* original d413, guest PC 0x0c06c8b8 */
if(!s->budget--) { s->failed_pc=0x0c06c8b8u; return 0; }
r[4]=read(ram,0x0c06c908u,4);
goto P_0c06c8ba;
P_0c06c8ba: /* original 7ffc, guest PC 0x0c06c8ba */
if(!s->budget--) { s->failed_pc=0x0c06c8bau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06c8bc;
P_0c06c8bc: /* original 014c, guest PC 0x0c06c8bc */
if(!s->budget--) { s->failed_pc=0x0c06c8bcu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c8be;
P_0c06c8be: /* original 452d, guest PC 0x0c06c8be */
if(!s->budget--) { s->failed_pc=0x0c06c8beu; return 0; }
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?r[5]>>((-r[2])&31u):0):r[5]<<(r[2]&31u);
goto P_0c06c8c0;
P_0c06c8c0: /* original 6013, guest PC 0x0c06c8c0 */
if(!s->budget--) { s->failed_pc=0x0c06c8c0u; return 0; }
r[0]=r[1];
goto P_0c06c8c2;
P_0c06c8c2: /* original 8801, guest PC 0x0c06c8c2 */
if(!s->budget--) { s->failed_pc=0x0c06c8c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c8c4;
P_0c06c8c4: /* original 2f12, guest PC 0x0c06c8c4 */
if(!s->budget--) { s->failed_pc=0x0c06c8c4u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c06c8c6;
P_0c06c8c6: /* original 8f02, guest PC 0x0c06c8c6 */
if(!s->budget--) { s->failed_pc=0x0c06c8c6u; return 0; }
cond=r[17]&1u;
r[14]|=r[5];
if(!cond) { goto P_0c06c8ce; }
goto P_0c06c8ca;
P_0c06c8c8: /* original 2e5b, guest PC 0x0c06c8c8 */
if(!s->budget--) { s->failed_pc=0x0c06c8c8u; return 0; }
r[14]|=r[5];
goto P_0c06c8ca;
P_0c06c8ca: /* original ee4e, guest PC 0x0c06c8ca */
if(!s->budget--) { s->failed_pc=0x0c06c8cau; return 0; }
r[14]=0x0000004eu;
goto P_0c06c8cc;
P_0c06c8cc: /* original 2e5b, guest PC 0x0c06c8cc */
if(!s->budget--) { s->failed_pc=0x0c06c8ccu; return 0; }
r[14]|=r[5];
goto P_0c06c8ce;
P_0c06c8ce: /* original 9017, guest PC 0x0c06c8ce */
if(!s->budget--) { s->failed_pc=0x0c06c8ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c900u,2);
goto P_0c06c8d0;
P_0c06c8d0: /* original 004c, guest PC 0x0c06c8d0 */
if(!s->budget--) { s->failed_pc=0x0c06c8d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c8d2;
P_0c06c8d2: /* original 8801, guest PC 0x0c06c8d2 */
if(!s->budget--) { s->failed_pc=0x0c06c8d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c8d4;
P_0c06c8d4: /* original 8d34, guest PC 0x0c06c8d4 */
if(!s->budget--) { s->failed_pc=0x0c06c8d4u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c06c940; }
goto P_0c06c8d8;
P_0c06c8d6: /* original 6503, guest PC 0x0c06c8d6 */
if(!s->budget--) { s->failed_pc=0x0c06c8d6u; return 0; }
r[5]=r[0];
goto P_0c06c8d8;
P_0c06c8d8: /* original 900d, guest PC 0x0c06c8d8 */
if(!s->budget--) { s->failed_pc=0x0c06c8d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8f6u,2);
goto P_0c06c8da;
P_0c06c8da: /* original 004c, guest PC 0x0c06c8da */
if(!s->budget--) { s->failed_pc=0x0c06c8dau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c8dc;
P_0c06c8dc: /* original 8801, guest PC 0x0c06c8dc */
if(!s->budget--) { s->failed_pc=0x0c06c8dcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c8de;
P_0c06c8de: /* original 8d19, guest PC 0x0c06c8de */
if(!s->budget--) { s->failed_pc=0x0c06c8deu; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c06c914; }
goto P_0c06c8e2;
P_0c06c8e0: /* original 6503, guest PC 0x0c06c8e0 */
if(!s->budget--) { s->failed_pc=0x0c06c8e0u; return 0; }
r[5]=r[0];
goto P_0c06c8e2;
P_0c06c8e2: /* original 900a, guest PC 0x0c06c8e2 */
if(!s->budget--) { s->failed_pc=0x0c06c8e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c8fau,2);
goto P_0c06c8e4;
P_0c06c8e4: /* original 064c, guest PC 0x0c06c8e4 */
if(!s->budget--) { s->failed_pc=0x0c06c8e4u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c8e6;
P_0c06c8e6: /* original 70ff, guest PC 0x0c06c8e6 */
if(!s->budget--) { s->failed_pc=0x0c06c8e6u; return 0; }
r[0]+=0xffffffffu;
goto P_0c06c8e8;
P_0c06c8e8: /* original 054c, guest PC 0x0c06c8e8 */
if(!s->budget--) { s->failed_pc=0x0c06c8e8u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c8ea;
P_0c06c8ea: /* original 2558, guest PC 0x0c06c8ea */
if(!s->budget--) { s->failed_pc=0x0c06c8eau; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06c8ec;
P_0c06c8ec: /* original 8b1d, guest PC 0x0c06c8ec */
if(!s->budget--) { s->failed_pc=0x0c06c8ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c92a; }
goto P_0c06c8ee;
P_0c06c8ee: /* original 2668, guest PC 0x0c06c8ee */
if(!s->budget--) { s->failed_pc=0x0c06c8eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06c8f0;
P_0c06c8f0: /* original 8b1b, guest PC 0x0c06c8f0 */
if(!s->budget--) { s->failed_pc=0x0c06c8f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c92a; }
goto P_0c06c8f2;
P_0c06c8f2: /* original a022, guest PC 0x0c06c8f2 */
if(!s->budget--) { s->failed_pc=0x0c06c8f2u; return 0; }
goto P_0c06c93a;
P_0c06c8f4: /* original 0009, guest PC 0x0c06c8f4 */
if(!s->budget--) { s->failed_pc=0x0c06c8f4u; return 0; }
return vf3_matrix_family(0x0c06c8f6u,s,ram);
P_0c06c914: /* original 60f2, guest PC 0x0c06c914 */
if(!s->budget--) { s->failed_pc=0x0c06c914u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c06c916;
P_0c06c916: /* original 8801, guest PC 0x0c06c916 */
if(!s->budget--) { s->failed_pc=0x0c06c916u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c918;
P_0c06c918: /* original 89e3, guest PC 0x0c06c918 */
if(!s->budget--) { s->failed_pc=0x0c06c918u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c8e2; }
goto P_0c06c91a;
P_0c06c91a: /* original 906d, guest PC 0x0c06c91a */
if(!s->budget--) { s->failed_pc=0x0c06c91au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c9f8u,2);
goto P_0c06c91c;
P_0c06c91c: /* original 064c, guest PC 0x0c06c91c */
if(!s->budget--) { s->failed_pc=0x0c06c91cu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c91e;
P_0c06c91e: /* original 70ff, guest PC 0x0c06c91e */
if(!s->budget--) { s->failed_pc=0x0c06c91eu; return 0; }
r[0]+=0xffffffffu;
goto P_0c06c920;
P_0c06c920: /* original 054c, guest PC 0x0c06c920 */
if(!s->budget--) { s->failed_pc=0x0c06c920u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c922;
P_0c06c922: /* original 2558, guest PC 0x0c06c922 */
if(!s->budget--) { s->failed_pc=0x0c06c922u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06c924;
P_0c06c924: /* original 8b01, guest PC 0x0c06c924 */
if(!s->budget--) { s->failed_pc=0x0c06c924u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c92a; }
goto P_0c06c926;
P_0c06c926: /* original 2668, guest PC 0x0c06c926 */
if(!s->budget--) { s->failed_pc=0x0c06c926u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c06c928;
P_0c06c928: /* original 8907, guest PC 0x0c06c928 */
if(!s->budget--) { s->failed_pc=0x0c06c928u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c93a; }
goto P_0c06c92a;
P_0c06c92a: /* original 9066, guest PC 0x0c06c92a */
if(!s->budget--) { s->failed_pc=0x0c06c92au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06c9fau,2);
goto P_0c06c92c;
P_0c06c92c: /* original 064c, guest PC 0x0c06c92c */
if(!s->budget--) { s->failed_pc=0x0c06c92cu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06c92e;
P_0c06c92e: /* original 6453, guest PC 0x0c06c92e */
if(!s->budget--) { s->failed_pc=0x0c06c92eu; return 0; }
r[4]=r[5];
goto P_0c06c930;
P_0c06c930: /* original 3462, guest PC 0x0c06c930 */
if(!s->budget--) { s->failed_pc=0x0c06c930u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[6])!=0);
goto P_0c06c932;
P_0c06c932: /* original 8905, guest PC 0x0c06c932 */
if(!s->budget--) { s->failed_pc=0x0c06c932u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c940; }
goto P_0c06c934;
P_0c06c934: /* original dd32, guest PC 0x0c06c934 */
if(!s->budget--) { s->failed_pc=0x0c06c934u; return 0; }
r[13]=read(ram,0x0c06ca00u,4);
goto P_0c06c936;
P_0c06c936: /* original a004, guest PC 0x0c06c936 */
if(!s->budget--) { s->failed_pc=0x0c06c936u; return 0; }
goto P_0c06c942;
P_0c06c938: /* original 0009, guest PC 0x0c06c938 */
if(!s->budget--) { s->failed_pc=0x0c06c938u; return 0; }
goto P_0c06c93a;
P_0c06c93a: /* original dd32, guest PC 0x0c06c93a */
if(!s->budget--) { s->failed_pc=0x0c06c93au; return 0; }
r[13]=read(ram,0x0c06ca04u,4);
goto P_0c06c93c;
P_0c06c93c: /* original a001, guest PC 0x0c06c93c */
if(!s->budget--) { s->failed_pc=0x0c06c93cu; return 0; }
goto P_0c06c942;
P_0c06c93e: /* original 0009, guest PC 0x0c06c93e */
if(!s->budget--) { s->failed_pc=0x0c06c93eu; return 0; }
goto P_0c06c940;
P_0c06c940: /* original dd31, guest PC 0x0c06c940 */
if(!s->budget--) { s->failed_pc=0x0c06c940u; return 0; }
r[13]=read(ram,0x0c06ca08u,4);
goto P_0c06c942;
P_0c06c942: /* original bd29, guest PC 0x0c06c942 */
if(!s->budget--) { s->failed_pc=0x0c06c942u; return 0; }
target=0x0c06c398u; r[16]=0x0c06c946u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06c946u) { target=s->pc; goto dispatch; }
goto P_0c06c946;
P_0c06c944: /* original 64e3, guest PC 0x0c06c944 */
if(!s->budget--) { s->failed_pc=0x0c06c944u; return 0; }
r[4]=r[14];
goto P_0c06c946;
P_0c06c946: /* original 2008, guest PC 0x0c06c946 */
if(!s->budget--) { s->failed_pc=0x0c06c946u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06c948;
P_0c06c948: /* original 8904, guest PC 0x0c06c948 */
if(!s->budget--) { s->failed_pc=0x0c06c948u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06c954; }
goto P_0c06c94a;
P_0c06c94a: /* original d230, guest PC 0x0c06c94a */
if(!s->budget--) { s->failed_pc=0x0c06c94au; return 0; }
r[2]=read(ram,0x0c06ca0cu,4);
goto P_0c06c94c;
P_0c06c94c: /* original 65d3, guest PC 0x0c06c94c */
if(!s->budget--) { s->failed_pc=0x0c06c94cu; return 0; }
r[5]=r[13];
goto P_0c06c94e;
P_0c06c94e: /* original e601, guest PC 0x0c06c94e */
if(!s->budget--) { s->failed_pc=0x0c06c94eu; return 0; }
r[6]=0x00000001u;
goto P_0c06c950;
P_0c06c950: /* original 420b, guest PC 0x0c06c950 */
if(!s->budget--) { s->failed_pc=0x0c06c950u; return 0; }
target=r[2];
r[16]=0x0c06c954u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06c954u) { target=s->pc; goto dispatch; }
goto P_0c06c954;
P_0c06c952: /* original 64e3, guest PC 0x0c06c952 */
if(!s->budget--) { s->failed_pc=0x0c06c952u; return 0; }
r[4]=r[14];
goto P_0c06c954;
P_0c06c954: /* original 7f04, guest PC 0x0c06c954 */
if(!s->budget--) { s->failed_pc=0x0c06c954u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c956;
P_0c06c956: /* original 4f26, guest PC 0x0c06c956 */
if(!s->budget--) { s->failed_pc=0x0c06c956u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c958;
P_0c06c958: /* original 6df6, guest PC 0x0c06c958 */
if(!s->budget--) { s->failed_pc=0x0c06c958u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06c95a;
P_0c06c95a: /* original 000b, guest PC 0x0c06c95a */
if(!s->budget--) { s->failed_pc=0x0c06c95au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c95c: /* original 6ef6, guest PC 0x0c06c95c */
if(!s->budget--) { s->failed_pc=0x0c06c95cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06c95eu,s,ram);
P_0c07a844: /* original 2fe6, guest PC 0x0c07a844 */
if(!s->budget--) { s->failed_pc=0x0c07a844u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a846;
P_0c07a846: /* original 6e53, guest PC 0x0c07a846 */
if(!s->budget--) { s->failed_pc=0x0c07a846u; return 0; }
r[14]=r[5];
goto P_0c07a848;
P_0c07a848: /* original 2fd6, guest PC 0x0c07a848 */
if(!s->budget--) { s->failed_pc=0x0c07a848u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a84a;
P_0c07a84a: /* original 2fc6, guest PC 0x0c07a84a */
if(!s->budget--) { s->failed_pc=0x0c07a84au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a84c;
P_0c07a84c: /* original 2fb6, guest PC 0x0c07a84c */
if(!s->budget--) { s->failed_pc=0x0c07a84cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a84e;
P_0c07a84e: /* original 2fa6, guest PC 0x0c07a84e */
if(!s->budget--) { s->failed_pc=0x0c07a84eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a850;
P_0c07a850: /* original 6a43, guest PC 0x0c07a850 */
if(!s->budget--) { s->failed_pc=0x0c07a850u; return 0; }
r[10]=r[4];
goto P_0c07a852;
P_0c07a852: /* original 2f96, guest PC 0x0c07a852 */
if(!s->budget--) { s->failed_pc=0x0c07a852u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a854;
P_0c07a854: /* original 6bad, guest PC 0x0c07a854 */
if(!s->budget--) { s->failed_pc=0x0c07a854u; return 0; }
r[11]=r[10]&65535u;
goto P_0c07a856;
P_0c07a856: /* original 4f22, guest PC 0x0c07a856 */
if(!s->budget--) { s->failed_pc=0x0c07a856u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07a858;
P_0c07a858: /* original dc59, guest PC 0x0c07a858 */
if(!s->budget--) { s->failed_pc=0x0c07a858u; return 0; }
r[12]=read(ram,0x0c07a9c0u,4);
goto P_0c07a85a;
P_0c07a85a: /* original dd5c, guest PC 0x0c07a85a */
if(!s->budget--) { s->failed_pc=0x0c07a85au; return 0; }
r[13]=read(ram,0x0c07a9ccu,4);
goto P_0c07a85c;
P_0c07a85c: /* original 4c0b, guest PC 0x0c07a85c */
if(!s->budget--) { s->failed_pc=0x0c07a85cu; return 0; }
target=r[12];
r[16]=0x0c07a860u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a860u) { target=s->pc; goto dispatch; }
goto P_0c07a860;
P_0c07a85e: /* original 64b3, guest PC 0x0c07a85e */
if(!s->budget--) { s->failed_pc=0x0c07a85eu; return 0; }
r[4]=r[11];
goto P_0c07a860;
P_0c07a860: /* original 60b3, guest PC 0x0c07a860 */
if(!s->budget--) { s->failed_pc=0x0c07a860u; return 0; }
r[0]=r[11];
goto P_0c07a862;
P_0c07a862: /* original 880f, guest PC 0x0c07a862 */
if(!s->budget--) { s->failed_pc=0x0c07a862u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c07a864;
P_0c07a864: /* original 8b0e, guest PC 0x0c07a864 */
if(!s->budget--) { s->failed_pc=0x0c07a864u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a884; }
goto P_0c07a866;
P_0c07a866: /* original 4c0b, guest PC 0x0c07a866 */
if(!s->budget--) { s->failed_pc=0x0c07a866u; return 0; }
target=r[12];
r[16]=0x0c07a86au;
r[4]=0x0000000fu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a86au) { target=s->pc; goto dispatch; }
goto P_0c07a86a;
P_0c07a868: /* original e40f, guest PC 0x0c07a868 */
if(!s->budget--) { s->failed_pc=0x0c07a868u; return 0; }
r[4]=0x0000000fu;
goto P_0c07a86a;
P_0c07a86a: /* original d459, guest PC 0x0c07a86a */
if(!s->budget--) { s->failed_pc=0x0c07a86au; return 0; }
r[4]=read(ram,0x0c07a9d0u,4);
goto P_0c07a86c;
P_0c07a86c: /* original bfbc, guest PC 0x0c07a86c */
if(!s->budget--) { s->failed_pc=0x0c07a86cu; return 0; }
target=0x0c07a7e8u; r[16]=0x0c07a870u;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a870u) { target=s->pc; goto dispatch; }
goto P_0c07a870;
P_0c07a86e: /* original 65e3, guest PC 0x0c07a86e */
if(!s->budget--) { s->failed_pc=0x0c07a86eu; return 0; }
r[5]=r[14];
goto P_0c07a870;
P_0c07a870: /* original 4c0b, guest PC 0x0c07a870 */
if(!s->budget--) { s->failed_pc=0x0c07a870u; return 0; }
target=r[12];
r[16]=0x0c07a874u;
r[4]=0x00000024u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a874u) { target=s->pc; goto dispatch; }
goto P_0c07a874;
P_0c07a872: /* original e424, guest PC 0x0c07a872 */
if(!s->budget--) { s->failed_pc=0x0c07a872u; return 0; }
r[4]=0x00000024u;
goto P_0c07a874;
P_0c07a874: /* original d457, guest PC 0x0c07a874 */
if(!s->budget--) { s->failed_pc=0x0c07a874u; return 0; }
r[4]=read(ram,0x0c07a9d4u,4);
goto P_0c07a876;
P_0c07a876: /* original bfb7, guest PC 0x0c07a876 */
if(!s->budget--) { s->failed_pc=0x0c07a876u; return 0; }
target=0x0c07a7e8u; r[16]=0x0c07a87au;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a87au) { target=s->pc; goto dispatch; }
goto P_0c07a87a;
P_0c07a878: /* original 65e3, guest PC 0x0c07a878 */
if(!s->budget--) { s->failed_pc=0x0c07a878u; return 0; }
r[5]=r[14];
goto P_0c07a87a;
P_0c07a87a: /* original e00f, guest PC 0x0c07a87a */
if(!s->budget--) { s->failed_pc=0x0c07a87au; return 0; }
r[0]=0x0000000fu;
goto P_0c07a87c;
P_0c07a87c: /* original 81df, guest PC 0x0c07a87c */
if(!s->budget--) { s->failed_pc=0x0c07a87cu; return 0; }
write(ram,r[13]+30,r[0],2);
goto P_0c07a87e;
P_0c07a87e: /* original e048, guest PC 0x0c07a87e */
if(!s->budget--) { s->failed_pc=0x0c07a87eu; return 0; }
r[0]=0x00000048u;
goto P_0c07a880;
P_0c07a880: /* original a096, guest PC 0x0c07a880 */
if(!s->budget--) { s->failed_pc=0x0c07a880u; return 0; }
r[3]=0x00000024u;
goto P_0c07a9b0;
P_0c07a882: /* original e324, guest PC 0x0c07a882 */
if(!s->budget--) { s->failed_pc=0x0c07a882u; return 0; }
r[3]=0x00000024u;
goto P_0c07a884;
P_0c07a884: /* original 60b3, guest PC 0x0c07a884 */
if(!s->budget--) { s->failed_pc=0x0c07a884u; return 0; }
r[0]=r[11];
goto P_0c07a886;
P_0c07a886: /* original d954, guest PC 0x0c07a886 */
if(!s->budget--) { s->failed_pc=0x0c07a886u; return 0; }
r[9]=read(ram,0x0c07a9d8u,4);
goto P_0c07a888;
P_0c07a888: /* original 8808, guest PC 0x0c07a888 */
if(!s->budget--) { s->failed_pc=0x0c07a888u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c07a88a;
P_0c07a88a: /* original 8b06, guest PC 0x0c07a88a */
if(!s->budget--) { s->failed_pc=0x0c07a88au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a89a; }
goto P_0c07a88c;
P_0c07a88c: /* original 4c0b, guest PC 0x0c07a88c */
if(!s->budget--) { s->failed_pc=0x0c07a88cu; return 0; }
target=r[12];
r[16]=0x0c07a890u;
r[4]=0x00000008u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a890u) { target=s->pc; goto dispatch; }
goto P_0c07a890;
P_0c07a88e: /* original e408, guest PC 0x0c07a88e */
if(!s->budget--) { s->failed_pc=0x0c07a88eu; return 0; }
r[4]=0x00000008u;
goto P_0c07a890;
P_0c07a890: /* original 65e3, guest PC 0x0c07a890 */
if(!s->budget--) { s->failed_pc=0x0c07a890u; return 0; }
r[5]=r[14];
goto P_0c07a892;
P_0c07a892: /* original bfa9, guest PC 0x0c07a892 */
if(!s->budget--) { s->failed_pc=0x0c07a892u; return 0; }
target=0x0c07a7e8u; r[16]=0x0c07a896u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a896u) { target=s->pc; goto dispatch; }
goto P_0c07a896;
P_0c07a894: /* original 6493, guest PC 0x0c07a894 */
if(!s->budget--) { s->failed_pc=0x0c07a894u; return 0; }
r[4]=r[9];
goto P_0c07a896;
P_0c07a896: /* original a008, guest PC 0x0c07a896 */
if(!s->budget--) { s->failed_pc=0x0c07a896u; return 0; }
r[4]=0x00000008u;
goto P_0c07a8aa;
P_0c07a898: /* original e408, guest PC 0x0c07a898 */
if(!s->budget--) { s->failed_pc=0x0c07a898u; return 0; }
r[4]=0x00000008u;
goto P_0c07a89a;
P_0c07a89a: /* original 8809, guest PC 0x0c07a89a */
if(!s->budget--) { s->failed_pc=0x0c07a89au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c07a89c;
P_0c07a89c: /* original 8b0b, guest PC 0x0c07a89c */
if(!s->budget--) { s->failed_pc=0x0c07a89cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a8b6; }
goto P_0c07a89e;
P_0c07a89e: /* original 4c0b, guest PC 0x0c07a89e */
if(!s->budget--) { s->failed_pc=0x0c07a89eu; return 0; }
target=r[12];
r[16]=0x0c07a8a2u;
r[4]=0x00000009u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a8a2u) { target=s->pc; goto dispatch; }
goto P_0c07a8a2;
P_0c07a8a0: /* original e409, guest PC 0x0c07a8a0 */
if(!s->budget--) { s->failed_pc=0x0c07a8a0u; return 0; }
r[4]=0x00000009u;
goto P_0c07a8a2;
P_0c07a8a2: /* original 65e3, guest PC 0x0c07a8a2 */
if(!s->budget--) { s->failed_pc=0x0c07a8a2u; return 0; }
r[5]=r[14];
goto P_0c07a8a4;
P_0c07a8a4: /* original bfa0, guest PC 0x0c07a8a4 */
if(!s->budget--) { s->failed_pc=0x0c07a8a4u; return 0; }
target=0x0c07a7e8u; r[16]=0x0c07a8a8u;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a8a8u) { target=s->pc; goto dispatch; }
goto P_0c07a8a8;
P_0c07a8a6: /* original 6493, guest PC 0x0c07a8a6 */
if(!s->budget--) { s->failed_pc=0x0c07a8a6u; return 0; }
r[4]=r[9];
goto P_0c07a8a8;
P_0c07a8a8: /* original e409, guest PC 0x0c07a8a8 */
if(!s->budget--) { s->failed_pc=0x0c07a8a8u; return 0; }
r[4]=0x00000009u;
goto P_0c07a8aa;
P_0c07a8aa: /* original 60ad, guest PC 0x0c07a8aa */
if(!s->budget--) { s->failed_pc=0x0c07a8aau; return 0; }
r[0]=r[10]&65535u;
goto P_0c07a8ac;
P_0c07a8ac: /* original 4000, guest PC 0x0c07a8ac */
if(!s->budget--) { s->failed_pc=0x0c07a8acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07a8ae;
P_0c07a8ae: /* original 0d45, guest PC 0x0c07a8ae */
if(!s->budget--) { s->failed_pc=0x0c07a8aeu; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c07a8b0;
P_0c07a8b0: /* original 6043, guest PC 0x0c07a8b0 */
if(!s->budget--) { s->failed_pc=0x0c07a8b0u; return 0; }
r[0]=r[4];
goto P_0c07a8b2;
P_0c07a8b2: /* original a0b5, guest PC 0x0c07a8b2 */
if(!s->budget--) { s->failed_pc=0x0c07a8b2u; return 0; }
write(ram,r[13]+10,r[0],2);
goto P_0c07aa20;
P_0c07a8b4: /* original 81d5, guest PC 0x0c07a8b4 */
if(!s->budget--) { s->failed_pc=0x0c07a8b4u; return 0; }
write(ram,r[13]+10,r[0],2);
goto P_0c07a8b6;
P_0c07a8b6: /* original 60b3, guest PC 0x0c07a8b6 */
if(!s->budget--) { s->failed_pc=0x0c07a8b6u; return 0; }
r[0]=r[11];
goto P_0c07a8b8;
P_0c07a8b8: /* original d448, guest PC 0x0c07a8b8 */
if(!s->budget--) { s->failed_pc=0x0c07a8b8u; return 0; }
r[4]=read(ram,0x0c07a9dcu,4);
goto P_0c07a8ba;
P_0c07a8ba: /* original 880a, guest PC 0x0c07a8ba */
if(!s->budget--) { s->failed_pc=0x0c07a8bau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c07a8bc;
P_0c07a8bc: /* original 8902, guest PC 0x0c07a8bc */
if(!s->budget--) { s->failed_pc=0x0c07a8bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07a8c4; }
goto P_0c07a8be;
P_0c07a8be: /* original 60b3, guest PC 0x0c07a8be */
if(!s->budget--) { s->failed_pc=0x0c07a8beu; return 0; }
r[0]=r[11];
goto P_0c07a8c0;
P_0c07a8c0: /* original 880b, guest PC 0x0c07a8c0 */
if(!s->budget--) { s->failed_pc=0x0c07a8c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c07a8c2;
P_0c07a8c2: /* original 8b07, guest PC 0x0c07a8c2 */
if(!s->budget--) { s->failed_pc=0x0c07a8c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a8d4; }
goto P_0c07a8c4;
P_0c07a8c4: /* original bf9f, guest PC 0x0c07a8c4 */
if(!s->budget--) { s->failed_pc=0x0c07a8c4u; return 0; }
target=0x0c07a806u; r[16]=0x0c07a8c8u;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a8c8u) { target=s->pc; goto dispatch; }
goto P_0c07a8c8;
P_0c07a8c6: /* original 65e3, guest PC 0x0c07a8c6 */
if(!s->budget--) { s->failed_pc=0x0c07a8c6u; return 0; }
r[5]=r[14];
goto P_0c07a8c8;
P_0c07a8c8: /* original 60ad, guest PC 0x0c07a8c8 */
if(!s->budget--) { s->failed_pc=0x0c07a8c8u; return 0; }
r[0]=r[10]&65535u;
goto P_0c07a8ca;
P_0c07a8ca: /* original 4000, guest PC 0x0c07a8ca */
if(!s->budget--) { s->failed_pc=0x0c07a8cau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07a8cc;
P_0c07a8cc: /* original 0db5, guest PC 0x0c07a8cc */
if(!s->budget--) { s->failed_pc=0x0c07a8ccu; return 0; }
write(ram,r[13]+r[0],r[11],2);
goto P_0c07a8ce;
P_0c07a8ce: /* original 60b3, guest PC 0x0c07a8ce */
if(!s->budget--) { s->failed_pc=0x0c07a8ceu; return 0; }
r[0]=r[11];
goto P_0c07a8d0;
P_0c07a8d0: /* original a0a6, guest PC 0x0c07a8d0 */
if(!s->budget--) { s->failed_pc=0x0c07a8d0u; return 0; }
write(ram,r[13]+12,r[0],2);
goto P_0c07aa20;
P_0c07a8d2: /* original 81d6, guest PC 0x0c07a8d2 */
if(!s->budget--) { s->failed_pc=0x0c07a8d2u; return 0; }
write(ram,r[13]+12,r[0],2);
goto P_0c07a8d4;
P_0c07a8d4: /* original 8812, guest PC 0x0c07a8d4 */
if(!s->budget--) { s->failed_pc=0x0c07a8d4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c07a8d6;
P_0c07a8d6: /* original 8b15, guest PC 0x0c07a8d6 */
if(!s->budget--) { s->failed_pc=0x0c07a8d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a904; }
goto P_0c07a8d8;
P_0c07a8d8: /* original 4c0b, guest PC 0x0c07a8d8 */
if(!s->budget--) { s->failed_pc=0x0c07a8d8u; return 0; }
target=r[12];
r[16]=0x0c07a8dcu;
r[4]=0x00000023u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a8dcu) { target=s->pc; goto dispatch; }
goto P_0c07a8dc;
P_0c07a8da: /* original e423, guest PC 0x0c07a8da */
if(!s->budget--) { s->failed_pc=0x0c07a8dau; return 0; }
r[4]=0x00000023u;
goto P_0c07a8dc;
P_0c07a8dc: /* original db40, guest PC 0x0c07a8dc */
if(!s->budget--) { s->failed_pc=0x0c07a8dcu; return 0; }
r[11]=read(ram,0x0c07a9e0u,4);
goto P_0c07a8de;
P_0c07a8de: /* original 65e3, guest PC 0x0c07a8de */
if(!s->budget--) { s->failed_pc=0x0c07a8deu; return 0; }
r[5]=r[14];
goto P_0c07a8e0;
P_0c07a8e0: /* original bf82, guest PC 0x0c07a8e0 */
if(!s->budget--) { s->failed_pc=0x0c07a8e0u; return 0; }
target=0x0c07a7e8u; r[16]=0x0c07a8e4u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a8e4u) { target=s->pc; goto dispatch; }
goto P_0c07a8e4;
P_0c07a8e2: /* original 64b3, guest PC 0x0c07a8e2 */
if(!s->budget--) { s->failed_pc=0x0c07a8e2u; return 0; }
r[4]=r[11];
goto P_0c07a8e4;
P_0c07a8e4: /* original 4c0b, guest PC 0x0c07a8e4 */
if(!s->budget--) { s->failed_pc=0x0c07a8e4u; return 0; }
target=r[12];
r[16]=0x0c07a8e8u;
r[4]=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a8e8u) { target=s->pc; goto dispatch; }
goto P_0c07a8e8;
P_0c07a8e6: /* original e412, guest PC 0x0c07a8e6 */
if(!s->budget--) { s->failed_pc=0x0c07a8e6u; return 0; }
r[4]=0x00000012u;
goto P_0c07a8e8;
P_0c07a8e8: /* original 64b3, guest PC 0x0c07a8e8 */
if(!s->budget--) { s->failed_pc=0x0c07a8e8u; return 0; }
r[4]=r[11];
goto P_0c07a8ea;
P_0c07a8ea: /* original 65e3, guest PC 0x0c07a8ea */
if(!s->budget--) { s->failed_pc=0x0c07a8eau; return 0; }
r[5]=r[14];
goto P_0c07a8ec;
P_0c07a8ec: /* original bf7c, guest PC 0x0c07a8ec */
if(!s->budget--) { s->failed_pc=0x0c07a8ecu; return 0; }
target=0x0c07a7e8u; r[16]=0x0c07a8f0u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a8f0u) { target=s->pc; goto dispatch; }
goto P_0c07a8f0;
P_0c07a8ee: /* original 7410, guest PC 0x0c07a8ee */
if(!s->budget--) { s->failed_pc=0x0c07a8eeu; return 0; }
r[4]+=0x00000010u;
goto P_0c07a8f0;
P_0c07a8f0: /* original 4c0b, guest PC 0x0c07a8f0 */
if(!s->budget--) { s->failed_pc=0x0c07a8f0u; return 0; }
target=r[12];
r[16]=0x0c07a8f4u;
r[4]=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a8f4u) { target=s->pc; goto dispatch; }
goto P_0c07a8f4;
P_0c07a8f2: /* original e418, guest PC 0x0c07a8f2 */
if(!s->budget--) { s->failed_pc=0x0c07a8f2u; return 0; }
r[4]=0x00000018u;
goto P_0c07a8f4;
P_0c07a8f4: /* original 64b3, guest PC 0x0c07a8f4 */
if(!s->budget--) { s->failed_pc=0x0c07a8f4u; return 0; }
r[4]=r[11];
goto P_0c07a8f6;
P_0c07a8f6: /* original 65e3, guest PC 0x0c07a8f6 */
if(!s->budget--) { s->failed_pc=0x0c07a8f6u; return 0; }
r[5]=r[14];
goto P_0c07a8f8;
P_0c07a8f8: /* original bf76, guest PC 0x0c07a8f8 */
if(!s->budget--) { s->failed_pc=0x0c07a8f8u; return 0; }
target=0x0c07a7e8u; r[16]=0x0c07a8fcu;
r[4]+=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a8fcu) { target=s->pc; goto dispatch; }
goto P_0c07a8fc;
P_0c07a8fa: /* original 7420, guest PC 0x0c07a8fa */
if(!s->budget--) { s->failed_pc=0x0c07a8fau; return 0; }
r[4]+=0x00000020u;
goto P_0c07a8fc;
P_0c07a8fc: /* original e212, guest PC 0x0c07a8fc */
if(!s->budget--) { s->failed_pc=0x0c07a8fcu; return 0; }
r[2]=0x00000012u;
goto P_0c07a8fe;
P_0c07a8fe: /* original e024, guest PC 0x0c07a8fe */
if(!s->budget--) { s->failed_pc=0x0c07a8feu; return 0; }
r[0]=0x00000024u;
goto P_0c07a900;
P_0c07a900: /* original a018, guest PC 0x0c07a900 */
if(!s->budget--) { s->failed_pc=0x0c07a900u; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c07a934;
P_0c07a902: /* original 0d25, guest PC 0x0c07a902 */
if(!s->budget--) { s->failed_pc=0x0c07a902u; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c07a904;
P_0c07a904: /* original 60b3, guest PC 0x0c07a904 */
if(!s->budget--) { s->failed_pc=0x0c07a904u; return 0; }
r[0]=r[11];
goto P_0c07a906;
P_0c07a906: /* original 8813, guest PC 0x0c07a906 */
if(!s->budget--) { s->failed_pc=0x0c07a906u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000013u)!=0);
goto P_0c07a908;
P_0c07a908: /* original 8b1b, guest PC 0x0c07a908 */
if(!s->budget--) { s->failed_pc=0x0c07a908u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a942; }
goto P_0c07a90a;
P_0c07a90a: /* original 4c0b, guest PC 0x0c07a90a */
if(!s->budget--) { s->failed_pc=0x0c07a90au; return 0; }
target=r[12];
r[16]=0x0c07a90eu;
r[4]=0x00000023u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a90eu) { target=s->pc; goto dispatch; }
goto P_0c07a90e;
P_0c07a90c: /* original e423, guest PC 0x0c07a90c */
if(!s->budget--) { s->failed_pc=0x0c07a90cu; return 0; }
r[4]=0x00000023u;
goto P_0c07a90e;
P_0c07a90e: /* original db35, guest PC 0x0c07a90e */
if(!s->budget--) { s->failed_pc=0x0c07a90eu; return 0; }
r[11]=read(ram,0x0c07a9e4u,4);
goto P_0c07a910;
P_0c07a910: /* original 65e3, guest PC 0x0c07a910 */
if(!s->budget--) { s->failed_pc=0x0c07a910u; return 0; }
r[5]=r[14];
goto P_0c07a912;
P_0c07a912: /* original bf69, guest PC 0x0c07a912 */
if(!s->budget--) { s->failed_pc=0x0c07a912u; return 0; }
target=0x0c07a7e8u; r[16]=0x0c07a916u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a916u) { target=s->pc; goto dispatch; }
goto P_0c07a916;
P_0c07a914: /* original 64b3, guest PC 0x0c07a914 */
if(!s->budget--) { s->failed_pc=0x0c07a914u; return 0; }
r[4]=r[11];
goto P_0c07a916;
P_0c07a916: /* original 4c0b, guest PC 0x0c07a916 */
if(!s->budget--) { s->failed_pc=0x0c07a916u; return 0; }
target=r[12];
r[16]=0x0c07a91au;
r[4]=0x00000013u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a91au) { target=s->pc; goto dispatch; }
goto P_0c07a91a;
P_0c07a918: /* original e413, guest PC 0x0c07a918 */
if(!s->budget--) { s->failed_pc=0x0c07a918u; return 0; }
r[4]=0x00000013u;
goto P_0c07a91a;
P_0c07a91a: /* original 64b3, guest PC 0x0c07a91a */
if(!s->budget--) { s->failed_pc=0x0c07a91au; return 0; }
r[4]=r[11];
goto P_0c07a91c;
P_0c07a91c: /* original 65e3, guest PC 0x0c07a91c */
if(!s->budget--) { s->failed_pc=0x0c07a91cu; return 0; }
r[5]=r[14];
goto P_0c07a91e;
P_0c07a91e: /* original bf63, guest PC 0x0c07a91e */
if(!s->budget--) { s->failed_pc=0x0c07a91eu; return 0; }
target=0x0c07a7e8u; r[16]=0x0c07a922u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a922u) { target=s->pc; goto dispatch; }
goto P_0c07a922;
P_0c07a920: /* original 7410, guest PC 0x0c07a920 */
if(!s->budget--) { s->failed_pc=0x0c07a920u; return 0; }
r[4]+=0x00000010u;
goto P_0c07a922;
P_0c07a922: /* original 4c0b, guest PC 0x0c07a922 */
if(!s->budget--) { s->failed_pc=0x0c07a922u; return 0; }
target=r[12];
r[16]=0x0c07a926u;
r[4]=0x00000018u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a926u) { target=s->pc; goto dispatch; }
goto P_0c07a926;
P_0c07a924: /* original e418, guest PC 0x0c07a924 */
if(!s->budget--) { s->failed_pc=0x0c07a924u; return 0; }
r[4]=0x00000018u;
goto P_0c07a926;
P_0c07a926: /* original 64b3, guest PC 0x0c07a926 */
if(!s->budget--) { s->failed_pc=0x0c07a926u; return 0; }
r[4]=r[11];
goto P_0c07a928;
P_0c07a928: /* original 65e3, guest PC 0x0c07a928 */
if(!s->budget--) { s->failed_pc=0x0c07a928u; return 0; }
r[5]=r[14];
goto P_0c07a92a;
P_0c07a92a: /* original bf5d, guest PC 0x0c07a92a */
if(!s->budget--) { s->failed_pc=0x0c07a92au; return 0; }
target=0x0c07a7e8u; r[16]=0x0c07a92eu;
r[4]+=0x00000020u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a92eu) { target=s->pc; goto dispatch; }
goto P_0c07a92e;
P_0c07a92c: /* original 7420, guest PC 0x0c07a92c */
if(!s->budget--) { s->failed_pc=0x0c07a92cu; return 0; }
r[4]+=0x00000020u;
goto P_0c07a92e;
P_0c07a92e: /* original e313, guest PC 0x0c07a92e */
if(!s->budget--) { s->failed_pc=0x0c07a92eu; return 0; }
r[3]=0x00000013u;
goto P_0c07a930;
P_0c07a930: /* original e026, guest PC 0x0c07a930 */
if(!s->budget--) { s->failed_pc=0x0c07a930u; return 0; }
r[0]=0x00000026u;
goto P_0c07a932;
P_0c07a932: /* original 0d35, guest PC 0x0c07a932 */
if(!s->budget--) { s->failed_pc=0x0c07a932u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07a934;
P_0c07a934: /* original e223, guest PC 0x0c07a934 */
if(!s->budget--) { s->failed_pc=0x0c07a934u; return 0; }
r[2]=0x00000023u;
goto P_0c07a936;
P_0c07a936: /* original e046, guest PC 0x0c07a936 */
if(!s->budget--) { s->failed_pc=0x0c07a936u; return 0; }
r[0]=0x00000046u;
goto P_0c07a938;
P_0c07a938: /* original 0d25, guest PC 0x0c07a938 */
if(!s->budget--) { s->failed_pc=0x0c07a938u; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c07a93a;
P_0c07a93a: /* original e318, guest PC 0x0c07a93a */
if(!s->budget--) { s->failed_pc=0x0c07a93au; return 0; }
r[3]=0x00000018u;
goto P_0c07a93c;
P_0c07a93c: /* original e030, guest PC 0x0c07a93c */
if(!s->budget--) { s->failed_pc=0x0c07a93cu; return 0; }
r[0]=0x00000030u;
goto P_0c07a93e;
P_0c07a93e: /* original a037, guest PC 0x0c07a93e */
if(!s->budget--) { s->failed_pc=0x0c07a93eu; return 0; }
goto P_0c07a9b0;
P_0c07a940: /* original 0009, guest PC 0x0c07a940 */
if(!s->budget--) { s->failed_pc=0x0c07a940u; return 0; }
goto P_0c07a942;
P_0c07a942: /* original 880e, guest PC 0x0c07a942 */
if(!s->budget--) { s->failed_pc=0x0c07a942u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c07a944;
P_0c07a944: /* original 8b01, guest PC 0x0c07a944 */
if(!s->budget--) { s->failed_pc=0x0c07a944u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a94a; }
goto P_0c07a946;
P_0c07a946: /* original a004, guest PC 0x0c07a946 */
if(!s->budget--) { s->failed_pc=0x0c07a946u; return 0; }
r[4]=0x0000000eu;
goto P_0c07a952;
P_0c07a948: /* original e40e, guest PC 0x0c07a948 */
if(!s->budget--) { s->failed_pc=0x0c07a948u; return 0; }
r[4]=0x0000000eu;
goto P_0c07a94a;
P_0c07a94a: /* original 60b3, guest PC 0x0c07a94a */
if(!s->budget--) { s->failed_pc=0x0c07a94au; return 0; }
r[0]=r[11];
goto P_0c07a94c;
P_0c07a94c: /* original 881b, guest PC 0x0c07a94c */
if(!s->budget--) { s->failed_pc=0x0c07a94cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001bu)!=0);
goto P_0c07a94e;
P_0c07a94e: /* original 8b07, guest PC 0x0c07a94e */
if(!s->budget--) { s->failed_pc=0x0c07a94eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a960; }
goto P_0c07a950;
P_0c07a950: /* original e41b, guest PC 0x0c07a950 */
if(!s->budget--) { s->failed_pc=0x0c07a950u; return 0; }
r[4]=0x0000001bu;
goto P_0c07a952;
P_0c07a952: /* original 4c0b, guest PC 0x0c07a952 */
if(!s->budget--) { s->failed_pc=0x0c07a952u; return 0; }
target=r[12];
r[16]=0x0c07a956u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a956u) { target=s->pc; goto dispatch; }
goto P_0c07a956;
P_0c07a954: /* original 0009, guest PC 0x0c07a954 */
if(!s->budget--) { s->failed_pc=0x0c07a954u; return 0; }
goto P_0c07a956;
P_0c07a956: /* original 65e3, guest PC 0x0c07a956 */
if(!s->budget--) { s->failed_pc=0x0c07a956u; return 0; }
r[5]=r[14];
goto P_0c07a958;
P_0c07a958: /* original bf55, guest PC 0x0c07a958 */
if(!s->budget--) { s->failed_pc=0x0c07a958u; return 0; }
target=0x0c07a806u; r[16]=0x0c07a95cu;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a95cu) { target=s->pc; goto dispatch; }
goto P_0c07a95c;
P_0c07a95a: /* original 6493, guest PC 0x0c07a95a */
if(!s->budget--) { s->failed_pc=0x0c07a95au; return 0; }
r[4]=r[9];
goto P_0c07a95c;
P_0c07a95c: /* original a05d, guest PC 0x0c07a95c */
if(!s->budget--) { s->failed_pc=0x0c07a95cu; return 0; }
goto P_0c07aa1a;
P_0c07a95e: /* original 0009, guest PC 0x0c07a95e */
if(!s->budget--) { s->failed_pc=0x0c07a95eu; return 0; }
goto P_0c07a960;
P_0c07a960: /* original 8814, guest PC 0x0c07a960 */
if(!s->budget--) { s->failed_pc=0x0c07a960u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000014u)!=0);
goto P_0c07a962;
P_0c07a962: /* original 8b10, guest PC 0x0c07a962 */
if(!s->budget--) { s->failed_pc=0x0c07a962u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a986; }
goto P_0c07a964;
P_0c07a964: /* original 4c0b, guest PC 0x0c07a964 */
if(!s->budget--) { s->failed_pc=0x0c07a964u; return 0; }
target=r[12];
r[16]=0x0c07a968u;
r[4]=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a968u) { target=s->pc; goto dispatch; }
goto P_0c07a968;
P_0c07a966: /* original e414, guest PC 0x0c07a966 */
if(!s->budget--) { s->failed_pc=0x0c07a966u; return 0; }
r[4]=0x00000014u;
goto P_0c07a968;
P_0c07a968: /* original d41f, guest PC 0x0c07a968 */
if(!s->budget--) { s->failed_pc=0x0c07a968u; return 0; }
r[4]=read(ram,0x0c07a9e8u,4);
goto P_0c07a96a;
P_0c07a96a: /* original bf3d, guest PC 0x0c07a96a */
if(!s->budget--) { s->failed_pc=0x0c07a96au; return 0; }
target=0x0c07a7e8u; r[16]=0x0c07a96eu;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a96eu) { target=s->pc; goto dispatch; }
goto P_0c07a96e;
P_0c07a96c: /* original 65e3, guest PC 0x0c07a96c */
if(!s->budget--) { s->failed_pc=0x0c07a96cu; return 0; }
r[5]=r[14];
goto P_0c07a96e;
P_0c07a96e: /* original 4c0b, guest PC 0x0c07a96e */
if(!s->budget--) { s->failed_pc=0x0c07a96eu; return 0; }
target=r[12];
r[16]=0x0c07a972u;
r[4]=0x00000022u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a972u) { target=s->pc; goto dispatch; }
goto P_0c07a972;
P_0c07a970: /* original e422, guest PC 0x0c07a970 */
if(!s->budget--) { s->failed_pc=0x0c07a970u; return 0; }
r[4]=0x00000022u;
goto P_0c07a972;
P_0c07a972: /* original d41e, guest PC 0x0c07a972 */
if(!s->budget--) { s->failed_pc=0x0c07a972u; return 0; }
r[4]=read(ram,0x0c07a9ecu,4);
goto P_0c07a974;
P_0c07a974: /* original bf38, guest PC 0x0c07a974 */
if(!s->budget--) { s->failed_pc=0x0c07a974u; return 0; }
target=0x0c07a7e8u; r[16]=0x0c07a978u;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a978u) { target=s->pc; goto dispatch; }
goto P_0c07a978;
P_0c07a976: /* original 65e3, guest PC 0x0c07a976 */
if(!s->budget--) { s->failed_pc=0x0c07a976u; return 0; }
r[5]=r[14];
goto P_0c07a978;
P_0c07a978: /* original e214, guest PC 0x0c07a978 */
if(!s->budget--) { s->failed_pc=0x0c07a978u; return 0; }
r[2]=0x00000014u;
goto P_0c07a97a;
P_0c07a97a: /* original e028, guest PC 0x0c07a97a */
if(!s->budget--) { s->failed_pc=0x0c07a97au; return 0; }
r[0]=0x00000028u;
goto P_0c07a97c;
P_0c07a97c: /* original 0d25, guest PC 0x0c07a97c */
if(!s->budget--) { s->failed_pc=0x0c07a97cu; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c07a97e;
P_0c07a97e: /* original e322, guest PC 0x0c07a97e */
if(!s->budget--) { s->failed_pc=0x0c07a97eu; return 0; }
r[3]=0x00000022u;
goto P_0c07a980;
P_0c07a980: /* original e044, guest PC 0x0c07a980 */
if(!s->budget--) { s->failed_pc=0x0c07a980u; return 0; }
r[0]=0x00000044u;
goto P_0c07a982;
P_0c07a982: /* original a015, guest PC 0x0c07a982 */
if(!s->budget--) { s->failed_pc=0x0c07a982u; return 0; }
goto P_0c07a9b0;
P_0c07a984: /* original 0009, guest PC 0x0c07a984 */
if(!s->budget--) { s->failed_pc=0x0c07a984u; return 0; }
goto P_0c07a986;
P_0c07a986: /* original 60b3, guest PC 0x0c07a986 */
if(!s->budget--) { s->failed_pc=0x0c07a986u; return 0; }
r[0]=r[11];
goto P_0c07a988;
P_0c07a988: /* original 8816, guest PC 0x0c07a988 */
if(!s->budget--) { s->failed_pc=0x0c07a988u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000016u)!=0);
goto P_0c07a98a;
P_0c07a98a: /* original 8b08, guest PC 0x0c07a98a */
if(!s->budget--) { s->failed_pc=0x0c07a98au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a99e; }
goto P_0c07a98c;
P_0c07a98c: /* original 4c0b, guest PC 0x0c07a98c */
if(!s->budget--) { s->failed_pc=0x0c07a98cu; return 0; }
target=r[12];
r[16]=0x0c07a990u;
r[4]=0x00000016u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a990u) { target=s->pc; goto dispatch; }
goto P_0c07a990;
P_0c07a98e: /* original e416, guest PC 0x0c07a98e */
if(!s->budget--) { s->failed_pc=0x0c07a98eu; return 0; }
r[4]=0x00000016u;
goto P_0c07a990;
P_0c07a990: /* original d417, guest PC 0x0c07a990 */
if(!s->budget--) { s->failed_pc=0x0c07a990u; return 0; }
r[4]=read(ram,0x0c07a9f0u,4);
goto P_0c07a992;
P_0c07a992: /* original bf29, guest PC 0x0c07a992 */
if(!s->budget--) { s->failed_pc=0x0c07a992u; return 0; }
target=0x0c07a7e8u; r[16]=0x0c07a996u;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a996u) { target=s->pc; goto dispatch; }
goto P_0c07a996;
P_0c07a994: /* original 65e3, guest PC 0x0c07a994 */
if(!s->budget--) { s->failed_pc=0x0c07a994u; return 0; }
r[5]=r[14];
goto P_0c07a996;
P_0c07a996: /* original e316, guest PC 0x0c07a996 */
if(!s->budget--) { s->failed_pc=0x0c07a996u; return 0; }
r[3]=0x00000016u;
goto P_0c07a998;
P_0c07a998: /* original e02c, guest PC 0x0c07a998 */
if(!s->budget--) { s->failed_pc=0x0c07a998u; return 0; }
r[0]=0x0000002cu;
goto P_0c07a99a;
P_0c07a99a: /* original a009, guest PC 0x0c07a99a */
if(!s->budget--) { s->failed_pc=0x0c07a99au; return 0; }
goto P_0c07a9b0;
P_0c07a99c: /* original 0009, guest PC 0x0c07a99c */
if(!s->budget--) { s->failed_pc=0x0c07a99cu; return 0; }
goto P_0c07a99e;
P_0c07a99e: /* original 8817, guest PC 0x0c07a99e */
if(!s->budget--) { s->failed_pc=0x0c07a99eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000017u)!=0);
goto P_0c07a9a0;
P_0c07a9a0: /* original 8b2a, guest PC 0x0c07a9a0 */
if(!s->budget--) { s->failed_pc=0x0c07a9a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a9f8; }
goto P_0c07a9a2;
P_0c07a9a2: /* original 4c0b, guest PC 0x0c07a9a2 */
if(!s->budget--) { s->failed_pc=0x0c07a9a2u; return 0; }
target=r[12];
r[16]=0x0c07a9a6u;
r[4]=0x00000017u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a9a6u) { target=s->pc; goto dispatch; }
goto P_0c07a9a6;
P_0c07a9a4: /* original e417, guest PC 0x0c07a9a4 */
if(!s->budget--) { s->failed_pc=0x0c07a9a4u; return 0; }
r[4]=0x00000017u;
goto P_0c07a9a6;
P_0c07a9a6: /* original d413, guest PC 0x0c07a9a6 */
if(!s->budget--) { s->failed_pc=0x0c07a9a6u; return 0; }
r[4]=read(ram,0x0c07a9f4u,4);
goto P_0c07a9a8;
P_0c07a9a8: /* original bf1e, guest PC 0x0c07a9a8 */
if(!s->budget--) { s->failed_pc=0x0c07a9a8u; return 0; }
target=0x0c07a7e8u; r[16]=0x0c07a9acu;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07a9acu) { target=s->pc; goto dispatch; }
goto P_0c07a9ac;
P_0c07a9aa: /* original 65e3, guest PC 0x0c07a9aa */
if(!s->budget--) { s->failed_pc=0x0c07a9aau; return 0; }
r[5]=r[14];
goto P_0c07a9ac;
P_0c07a9ac: /* original e317, guest PC 0x0c07a9ac */
if(!s->budget--) { s->failed_pc=0x0c07a9acu; return 0; }
r[3]=0x00000017u;
goto P_0c07a9ae;
P_0c07a9ae: /* original e02e, guest PC 0x0c07a9ae */
if(!s->budget--) { s->failed_pc=0x0c07a9aeu; return 0; }
r[0]=0x0000002eu;
goto P_0c07a9b0;
P_0c07a9b0: /* original a036, guest PC 0x0c07a9b0 */
if(!s->budget--) { s->failed_pc=0x0c07a9b0u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07aa20;
P_0c07a9b2: /* original 0d35, guest PC 0x0c07a9b2 */
if(!s->budget--) { s->failed_pc=0x0c07a9b2u; return 0; }
write(ram,r[13]+r[0],r[3],2);
return vf3_matrix_family(0x0c07a9b4u,s,ram);
P_0c07a9f8: /* original 60b3, guest PC 0x0c07a9f8 */
if(!s->budget--) { s->failed_pc=0x0c07a9f8u; return 0; }
r[0]=r[11];
goto P_0c07a9fa;
P_0c07a9fa: /* original 880c, guest PC 0x0c07a9fa */
if(!s->budget--) { s->failed_pc=0x0c07a9fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c07a9fc;
P_0c07a9fc: /* original 8902, guest PC 0x0c07a9fc */
if(!s->budget--) { s->failed_pc=0x0c07a9fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07aa04; }
goto P_0c07a9fe;
P_0c07a9fe: /* original 60b3, guest PC 0x0c07a9fe */
if(!s->budget--) { s->failed_pc=0x0c07a9feu; return 0; }
r[0]=r[11];
goto P_0c07aa00;
P_0c07aa00: /* original 880d, guest PC 0x0c07aa00 */
if(!s->budget--) { s->failed_pc=0x0c07aa00u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c07aa02;
P_0c07aa02: /* original 8b08, guest PC 0x0c07aa02 */
if(!s->budget--) { s->failed_pc=0x0c07aa02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07aa16; }
goto P_0c07aa04;
P_0c07aa04: /* original 4c0b, guest PC 0x0c07aa04 */
if(!s->budget--) { s->failed_pc=0x0c07aa04u; return 0; }
target=r[12];
r[16]=0x0c07aa08u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07aa08u) { target=s->pc; goto dispatch; }
goto P_0c07aa08;
P_0c07aa06: /* original 64b3, guest PC 0x0c07aa06 */
if(!s->budget--) { s->failed_pc=0x0c07aa06u; return 0; }
r[4]=r[11];
goto P_0c07aa08;
P_0c07aa08: /* original 65e3, guest PC 0x0c07aa08 */
if(!s->budget--) { s->failed_pc=0x0c07aa08u; return 0; }
r[5]=r[14];
goto P_0c07aa0a;
P_0c07aa0a: /* original beed, guest PC 0x0c07aa0a */
if(!s->budget--) { s->failed_pc=0x0c07aa0au; return 0; }
target=0x0c07a7e8u; r[16]=0x0c07aa0eu;
r[4]=r[9];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07aa0eu) { target=s->pc; goto dispatch; }
goto P_0c07aa0e;
P_0c07aa0c: /* original 6493, guest PC 0x0c07aa0c */
if(!s->budget--) { s->failed_pc=0x0c07aa0cu; return 0; }
r[4]=r[9];
goto P_0c07aa0e;
P_0c07aa0e: /* original 60ad, guest PC 0x0c07aa0e */
if(!s->budget--) { s->failed_pc=0x0c07aa0eu; return 0; }
r[0]=r[10]&65535u;
goto P_0c07aa10;
P_0c07aa10: /* original 4000, guest PC 0x0c07aa10 */
if(!s->budget--) { s->failed_pc=0x0c07aa10u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07aa12;
P_0c07aa12: /* original a005, guest PC 0x0c07aa12 */
if(!s->budget--) { s->failed_pc=0x0c07aa12u; return 0; }
write(ram,r[13]+r[0],r[10],2);
goto P_0c07aa20;
P_0c07aa14: /* original 0da5, guest PC 0x0c07aa14 */
if(!s->budget--) { s->failed_pc=0x0c07aa14u; return 0; }
write(ram,r[13]+r[0],r[10],2);
goto P_0c07aa16;
P_0c07aa16: /* original bef6, guest PC 0x0c07aa16 */
if(!s->budget--) { s->failed_pc=0x0c07aa16u; return 0; }
target=0x0c07a806u; r[16]=0x0c07aa1au;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07aa1au) { target=s->pc; goto dispatch; }
goto P_0c07aa1a;
P_0c07aa18: /* original 65e3, guest PC 0x0c07aa18 */
if(!s->budget--) { s->failed_pc=0x0c07aa18u; return 0; }
r[5]=r[14];
goto P_0c07aa1a;
P_0c07aa1a: /* original 60ad, guest PC 0x0c07aa1a */
if(!s->budget--) { s->failed_pc=0x0c07aa1au; return 0; }
r[0]=r[10]&65535u;
goto P_0c07aa1c;
P_0c07aa1c: /* original 4000, guest PC 0x0c07aa1c */
if(!s->budget--) { s->failed_pc=0x0c07aa1cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07aa1e;
P_0c07aa1e: /* original 0db5, guest PC 0x0c07aa1e */
if(!s->budget--) { s->failed_pc=0x0c07aa1eu; return 0; }
write(ram,r[13]+r[0],r[11],2);
goto P_0c07aa20;
P_0c07aa20: /* original 4f26, guest PC 0x0c07aa20 */
if(!s->budget--) { s->failed_pc=0x0c07aa20u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07aa22;
P_0c07aa22: /* original 69f6, guest PC 0x0c07aa22 */
if(!s->budget--) { s->failed_pc=0x0c07aa22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07aa24;
P_0c07aa24: /* original 6af6, guest PC 0x0c07aa24 */
if(!s->budget--) { s->failed_pc=0x0c07aa24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07aa26;
P_0c07aa26: /* original 6bf6, guest PC 0x0c07aa26 */
if(!s->budget--) { s->failed_pc=0x0c07aa26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07aa28;
P_0c07aa28: /* original 6cf6, guest PC 0x0c07aa28 */
if(!s->budget--) { s->failed_pc=0x0c07aa28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07aa2a;
P_0c07aa2a: /* original 6df6, guest PC 0x0c07aa2a */
if(!s->budget--) { s->failed_pc=0x0c07aa2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07aa2c;
P_0c07aa2c: /* original 000b, guest PC 0x0c07aa2c */
if(!s->budget--) { s->failed_pc=0x0c07aa2cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07aa2e: /* original 6ef6, guest PC 0x0c07aa2e */
if(!s->budget--) { s->failed_pc=0x0c07aa2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07aa30u,s,ram);
P_0c07aa34: /* original 4f22, guest PC 0x0c07aa34 */
if(!s->budget--) { s->failed_pc=0x0c07aa34u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07aa36;
P_0c07aa36: /* original 5341, guest PC 0x0c07aa36 */
if(!s->budget--) { s->failed_pc=0x0c07aa36u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c07aa38;
P_0c07aa38: /* original 7ffc, guest PC 0x0c07aa38 */
if(!s->budget--) { s->failed_pc=0x0c07aa38u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07aa3a;
P_0c07aa3a: /* original 2f32, guest PC 0x0c07aa3a */
if(!s->budget--) { s->failed_pc=0x0c07aa3au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07aa3c;
P_0c07aa3c: /* original 8d05, guest PC 0x0c07aa3c */
if(!s->budget--) { s->failed_pc=0x0c07aa3cu; return 0; }
cond=r[17]&1u;
r[14]=read(ram,r[4]+24,4);
if(cond) { goto P_0c07aa4a; }
goto P_0c07aa40;
P_0c07aa3e: /* original 5e46, guest PC 0x0c07aa3e */
if(!s->budget--) { s->failed_pc=0x0c07aa3eu; return 0; }
r[14]=read(ram,r[4]+24,4);
goto P_0c07aa40;
P_0c07aa40: /* original d02c, guest PC 0x0c07aa40 */
if(!s->budget--) { s->failed_pc=0x0c07aa40u; return 0; }
r[0]=read(ram,0x0c07aaf4u,4);
goto P_0c07aa42;
P_0c07aa42: /* original e200, guest PC 0x0c07aa42 */
if(!s->budget--) { s->failed_pc=0x0c07aa42u; return 0; }
r[2]=0x00000000u;
goto P_0c07aa44;
P_0c07aa44: /* original 4e00, guest PC 0x0c07aa44 */
if(!s->budget--) { s->failed_pc=0x0c07aa44u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07aa46;
P_0c07aa46: /* original a003, guest PC 0x0c07aa46 */
if(!s->budget--) { s->failed_pc=0x0c07aa46u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c07aa50;
P_0c07aa48: /* original 0e25, guest PC 0x0c07aa48 */
if(!s->budget--) { s->failed_pc=0x0c07aa48u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c07aa4a;
P_0c07aa4a: /* original 65f2, guest PC 0x0c07aa4a */
if(!s->budget--) { s->failed_pc=0x0c07aa4au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c07aa4c;
P_0c07aa4c: /* original befa, guest PC 0x0c07aa4c */
if(!s->budget--) { s->failed_pc=0x0c07aa4cu; return 0; }
target=0x0c07a844u; r[16]=0x0c07aa50u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07aa50u) { target=s->pc; goto dispatch; }
goto P_0c07aa50;
P_0c07aa4e: /* original 64e3, guest PC 0x0c07aa4e */
if(!s->budget--) { s->failed_pc=0x0c07aa4eu; return 0; }
r[4]=r[14];
goto P_0c07aa50;
P_0c07aa50: /* original 7f04, guest PC 0x0c07aa50 */
if(!s->budget--) { s->failed_pc=0x0c07aa50u; return 0; }
r[15]+=0x00000004u;
goto P_0c07aa52;
P_0c07aa52: /* original 4f26, guest PC 0x0c07aa52 */
if(!s->budget--) { s->failed_pc=0x0c07aa52u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07aa54;
P_0c07aa54: /* original e000, guest PC 0x0c07aa54 */
if(!s->budget--) { s->failed_pc=0x0c07aa54u; return 0; }
r[0]=0x00000000u;
goto P_0c07aa56;
P_0c07aa56: /* original 000b, guest PC 0x0c07aa56 */
if(!s->budget--) { s->failed_pc=0x0c07aa56u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07aa58: /* original 6ef6, guest PC 0x0c07aa58 */
if(!s->budget--) { s->failed_pc=0x0c07aa58u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07aa5au,s,ram);
P_0c07d890: /* original 4f22, guest PC 0x0c07d890 */
if(!s->budget--) { s->failed_pc=0x0c07d890u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07d892;
P_0c07d892: /* original 7ff8, guest PC 0x0c07d892 */
if(!s->budget--) { s->failed_pc=0x0c07d892u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07d894;
P_0c07d894: /* original 2f42, guest PC 0x0c07d894 */
if(!s->budget--) { s->failed_pc=0x0c07d894u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07d896;
P_0c07d896: /* original dd1d, guest PC 0x0c07d896 */
if(!s->budget--) { s->failed_pc=0x0c07d896u; return 0; }
r[13]=read(ram,0x0c07d90cu,4);
goto P_0c07d898;
P_0c07d898: /* original d326, guest PC 0x0c07d898 */
if(!s->budget--) { s->failed_pc=0x0c07d898u; return 0; }
r[3]=read(ram,0x0c07d934u,4);
goto P_0c07d89a;
P_0c07d89a: /* original 430b, guest PC 0x0c07d89a */
if(!s->budget--) { s->failed_pc=0x0c07d89au; return 0; }
target=r[3];
r[16]=0x0c07d89eu;
write(ram,r[15]+4,r[5],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07d89eu) { target=s->pc; goto dispatch; }
goto P_0c07d89e;
P_0c07d89c: /* original 1f51, guest PC 0x0c07d89c */
if(!s->budget--) { s->failed_pc=0x0c07d89cu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c07d89e;
P_0c07d89e: /* original d226, guest PC 0x0c07d89e */
if(!s->budget--) { s->failed_pc=0x0c07d89eu; return 0; }
r[2]=read(ram,0x0c07d938u,4);
goto P_0c07d8a0;
P_0c07d8a0: /* original 6422, guest PC 0x0c07d8a0 */
if(!s->budget--) { s->failed_pc=0x0c07d8a0u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c07d8a2;
P_0c07d8a2: /* original 4415, guest PC 0x0c07d8a2 */
if(!s->budget--) { s->failed_pc=0x0c07d8a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c07d8a4;
P_0c07d8a4: /* original 8b1a, guest PC 0x0c07d8a4 */
if(!s->budget--) { s->failed_pc=0x0c07d8a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07d8dc; }
goto P_0c07d8a6;
P_0c07d8a6: /* original d225, guest PC 0x0c07d8a6 */
if(!s->budget--) { s->failed_pc=0x0c07d8a6u; return 0; }
r[2]=read(ram,0x0c07d93cu,4);
goto P_0c07d8a8;
P_0c07d8a8: /* original e3fa, guest PC 0x0c07d8a8 */
if(!s->budget--) { s->failed_pc=0x0c07d8a8u; return 0; }
r[3]=0xfffffffau;
goto P_0c07d8aa;
P_0c07d8aa: /* original 6e43, guest PC 0x0c07d8aa */
if(!s->budget--) { s->failed_pc=0x0c07d8aau; return 0; }
r[14]=r[4];
goto P_0c07d8ac;
P_0c07d8ac: /* original e00a, guest PC 0x0c07d8ac */
if(!s->budget--) { s->failed_pc=0x0c07d8acu; return 0; }
r[0]=0x0000000au;
goto P_0c07d8ae;
P_0c07d8ae: /* original 4e3c, guest PC 0x0c07d8ae */
if(!s->budget--) { s->failed_pc=0x0c07d8aeu; return 0; }
r[14]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[14]>>((-r[3])&31u)):((int32_t)r[14]<0?0xffffffffu:0)):r[14]<<(r[3]&31u);
goto P_0c07d8b0;
P_0c07d8b0: /* original 420b, guest PC 0x0c07d8b0 */
if(!s->budget--) { s->failed_pc=0x0c07d8b0u; return 0; }
target=r[2];
r[16]=0x0c07d8b4u;
r[1]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07d8b4u) { target=s->pc; goto dispatch; }
goto P_0c07d8b4;
P_0c07d8b2: /* original 61e3, guest PC 0x0c07d8b2 */
if(!s->budget--) { s->failed_pc=0x0c07d8b2u; return 0; }
r[1]=r[14];
goto P_0c07d8b4;
P_0c07d8b4: /* original 6403, guest PC 0x0c07d8b4 */
if(!s->budget--) { s->failed_pc=0x0c07d8b4u; return 0; }
r[4]=r[0];
goto P_0c07d8b6;
P_0c07d8b6: /* original 4408, guest PC 0x0c07d8b6 */
if(!s->budget--) { s->failed_pc=0x0c07d8b6u; return 0; }
r[4]<<=2;
goto P_0c07d8b8;
P_0c07d8b8: /* original 6303, guest PC 0x0c07d8b8 */
if(!s->budget--) { s->failed_pc=0x0c07d8b8u; return 0; }
r[3]=r[0];
goto P_0c07d8ba;
P_0c07d8ba: /* original 343c, guest PC 0x0c07d8ba */
if(!s->budget--) { s->failed_pc=0x0c07d8bau; return 0; }
r[4]+=r[3];
goto P_0c07d8bc;
P_0c07d8bc: /* original 951e, guest PC 0x0c07d8bc */
if(!s->budget--) { s->failed_pc=0x0c07d8bcu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07d8fcu,2);
goto P_0c07d8be;
P_0c07d8be: /* original 4400, guest PC 0x0c07d8be */
if(!s->budget--) { s->failed_pc=0x0c07d8beu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07d8c0;
P_0c07d8c0: /* original 971d, guest PC 0x0c07d8c0 */
if(!s->budget--) { s->failed_pc=0x0c07d8c0u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07d8feu,2);
goto P_0c07d8c2;
P_0c07d8c2: /* original 6c03, guest PC 0x0c07d8c2 */
if(!s->budget--) { s->failed_pc=0x0c07d8c2u; return 0; }
r[12]=r[0];
goto P_0c07d8c4;
P_0c07d8c4: /* original d21e, guest PC 0x0c07d8c4 */
if(!s->budget--) { s->failed_pc=0x0c07d8c4u; return 0; }
r[2]=read(ram,0x0c07d940u,4);
goto P_0c07d8c6;
P_0c07d8c6: /* original 6603, guest PC 0x0c07d8c6 */
if(!s->budget--) { s->failed_pc=0x0c07d8c6u; return 0; }
r[6]=r[0];
goto P_0c07d8c8;
P_0c07d8c8: /* original 3e48, guest PC 0x0c07d8c8 */
if(!s->budget--) { s->failed_pc=0x0c07d8c8u; return 0; }
r[14]-=r[4];
goto P_0c07d8ca;
P_0c07d8ca: /* original 420b, guest PC 0x0c07d8ca */
if(!s->budget--) { s->failed_pc=0x0c07d8cau; return 0; }
target=r[2];
r[16]=0x0c07d8ceu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07d8ceu) { target=s->pc; goto dispatch; }
goto P_0c07d8ce;
P_0c07d8cc: /* original 64d3, guest PC 0x0c07d8cc */
if(!s->budget--) { s->failed_pc=0x0c07d8ccu; return 0; }
r[4]=r[13];
goto P_0c07d8ce;
P_0c07d8ce: /* original d31c, guest PC 0x0c07d8ce */
if(!s->budget--) { s->failed_pc=0x0c07d8ceu; return 0; }
r[3]=read(ram,0x0c07d940u,4);
goto P_0c07d8d0;
P_0c07d8d0: /* original 66e3, guest PC 0x0c07d8d0 */
if(!s->budget--) { s->failed_pc=0x0c07d8d0u; return 0; }
r[6]=r[14];
goto P_0c07d8d2;
P_0c07d8d2: /* original 9714, guest PC 0x0c07d8d2 */
if(!s->budget--) { s->failed_pc=0x0c07d8d2u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07d8feu,2);
goto P_0c07d8d4;
P_0c07d8d4: /* original 9514, guest PC 0x0c07d8d4 */
if(!s->budget--) { s->failed_pc=0x0c07d8d4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07d900u,2);
goto P_0c07d8d6;
P_0c07d8d6: /* original 430b, guest PC 0x0c07d8d6 */
if(!s->budget--) { s->failed_pc=0x0c07d8d6u; return 0; }
target=r[3];
r[16]=0x0c07d8dau;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07d8dau) { target=s->pc; goto dispatch; }
goto P_0c07d8da;
P_0c07d8d8: /* original 64d3, guest PC 0x0c07d8d8 */
if(!s->budget--) { s->failed_pc=0x0c07d8d8u; return 0; }
r[4]=r[13];
goto P_0c07d8da;
P_0c07d8da: /* original 1f01, guest PC 0x0c07d8da */
if(!s->budget--) { s->failed_pc=0x0c07d8dau; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c07d8dc;
P_0c07d8dc: /* original 64f2, guest PC 0x0c07d8dc */
if(!s->budget--) { s->failed_pc=0x0c07d8dcu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07d8de;
P_0c07d8de: /* original 55f1, guest PC 0x0c07d8de */
if(!s->budget--) { s->failed_pc=0x0c07d8deu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07d8e0;
P_0c07d8e0: /* original 7f08, guest PC 0x0c07d8e0 */
if(!s->budget--) { s->failed_pc=0x0c07d8e0u; return 0; }
r[15]+=0x00000008u;
goto P_0c07d8e2;
P_0c07d8e2: /* original 4f26, guest PC 0x0c07d8e2 */
if(!s->budget--) { s->failed_pc=0x0c07d8e2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07d8e4;
P_0c07d8e4: /* original d317, guest PC 0x0c07d8e4 */
if(!s->budget--) { s->failed_pc=0x0c07d8e4u; return 0; }
r[3]=read(ram,0x0c07d944u,4);
goto P_0c07d8e6;
P_0c07d8e6: /* original 6cf6, guest PC 0x0c07d8e6 */
if(!s->budget--) { s->failed_pc=0x0c07d8e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07d8e8;
P_0c07d8e8: /* original 6df6, guest PC 0x0c07d8e8 */
if(!s->budget--) { s->failed_pc=0x0c07d8e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07d8ea;
P_0c07d8ea: /* original 432b, guest PC 0x0c07d8ea */
if(!s->budget--) { s->failed_pc=0x0c07d8eau; return 0; }
target=r[3];
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
P_0c07d8ec: /* original 6ef6, guest PC 0x0c07d8ec */
if(!s->budget--) { s->failed_pc=0x0c07d8ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07d8eeu,s,ram);
P_0c07e918: /* original 4f22, guest PC 0x0c07e918 */
if(!s->budget--) { s->failed_pc=0x0c07e918u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07e91a;
P_0c07e91a: /* original e706, guest PC 0x0c07e91a */
if(!s->budget--) { s->failed_pc=0x0c07e91au; return 0; }
r[7]=0x00000006u;
goto P_0c07e91c;
P_0c07e91c: /* original 7ffc, guest PC 0x0c07e91c */
if(!s->budget--) { s->failed_pc=0x0c07e91cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07e91e;
P_0c07e91e: /* original 2f42, guest PC 0x0c07e91e */
if(!s->budget--) { s->failed_pc=0x0c07e91eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07e920;
P_0c07e920: /* original 933b, guest PC 0x0c07e920 */
if(!s->budget--) { s->failed_pc=0x0c07e920u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e99au,2);
goto P_0c07e922;
P_0c07e922: /* original d523, guest PC 0x0c07e922 */
if(!s->budget--) { s->failed_pc=0x0c07e922u; return 0; }
r[5]=read(ram,0x0c07e9b0u,4);
goto P_0c07e924;
P_0c07e924: /* original 1535, guest PC 0x0c07e924 */
if(!s->budget--) { s->failed_pc=0x0c07e924u; return 0; }
write(ram,r[5]+20,r[3],4);
goto P_0c07e926;
P_0c07e926: /* original 025c, guest PC 0x0c07e926 */
if(!s->budget--) { s->failed_pc=0x0c07e926u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07e928;
P_0c07e928: /* original 7201, guest PC 0x0c07e928 */
if(!s->budget--) { s->failed_pc=0x0c07e928u; return 0; }
r[2]+=0x00000001u;
goto P_0c07e92a;
P_0c07e92a: /* original 0524, guest PC 0x0c07e92a */
if(!s->budget--) { s->failed_pc=0x0c07e92au; return 0; }
write(ram,r[5]+r[0],r[2],1);
goto P_0c07e92c;
P_0c07e92c: /* original e200, guest PC 0x0c07e92c */
if(!s->budget--) { s->failed_pc=0x0c07e92cu; return 0; }
r[2]=0x00000000u;
goto P_0c07e92e;
P_0c07e92e: /* original d327, guest PC 0x0c07e92e */
if(!s->budget--) { s->failed_pc=0x0c07e92eu; return 0; }
r[3]=read(ram,0x0c07e9ccu,4);
goto P_0c07e930;
P_0c07e930: /* original 6523, guest PC 0x0c07e930 */
if(!s->budget--) { s->failed_pc=0x0c07e930u; return 0; }
r[5]=r[2];
goto P_0c07e932;
P_0c07e932: /* original 1434, guest PC 0x0c07e932 */
if(!s->budget--) { s->failed_pc=0x0c07e932u; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c07e934;
P_0c07e934: /* original de1c, guest PC 0x0c07e934 */
if(!s->budget--) { s->failed_pc=0x0c07e934u; return 0; }
r[14]=read(ram,0x0c07e9a8u,4);
goto P_0c07e936;
P_0c07e936: /* original 2f26, guest PC 0x0c07e936 */
if(!s->budget--) { s->failed_pc=0x0c07e936u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e938;
P_0c07e938: /* original d325, guest PC 0x0c07e938 */
if(!s->budget--) { s->failed_pc=0x0c07e938u; return 0; }
r[3]=read(ram,0x0c07e9d0u,4);
goto P_0c07e93a;
P_0c07e93a: /* original 430b, guest PC 0x0c07e93a */
if(!s->budget--) { s->failed_pc=0x0c07e93au; return 0; }
target=r[3];
r[16]=0x0c07e93eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07e93eu) { target=s->pc; goto dispatch; }
goto P_0c07e93e;
P_0c07e93c: /* original 64e3, guest PC 0x0c07e93c */
if(!s->budget--) { s->failed_pc=0x0c07e93cu; return 0; }
r[4]=r[14];
goto P_0c07e93e;
P_0c07e93e: /* original 9d2d, guest PC 0x0c07e93e */
if(!s->budget--) { s->failed_pc=0x0c07e93eu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e99cu,2);
goto P_0c07e940;
P_0c07e940: /* original e200, guest PC 0x0c07e940 */
if(!s->budget--) { s->failed_pc=0x0c07e940u; return 0; }
r[2]=0x00000000u;
goto P_0c07e942;
P_0c07e942: /* original e63e, guest PC 0x0c07e942 */
if(!s->budget--) { s->failed_pc=0x0c07e942u; return 0; }
r[6]=0x0000003eu;
goto P_0c07e944;
P_0c07e944: /* original 2f26, guest PC 0x0c07e944 */
if(!s->budget--) { s->failed_pc=0x0c07e944u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e946;
P_0c07e946: /* original d322, guest PC 0x0c07e946 */
if(!s->budget--) { s->failed_pc=0x0c07e946u; return 0; }
r[3]=read(ram,0x0c07e9d0u,4);
goto P_0c07e948;
P_0c07e948: /* original 65d3, guest PC 0x0c07e948 */
if(!s->budget--) { s->failed_pc=0x0c07e948u; return 0; }
r[5]=r[13];
goto P_0c07e94a;
P_0c07e94a: /* original e708, guest PC 0x0c07e94a */
if(!s->budget--) { s->failed_pc=0x0c07e94au; return 0; }
r[7]=0x00000008u;
goto P_0c07e94c;
P_0c07e94c: /* original 430b, guest PC 0x0c07e94c */
if(!s->budget--) { s->failed_pc=0x0c07e94cu; return 0; }
target=r[3];
r[16]=0x0c07e950u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07e950u) { target=s->pc; goto dispatch; }
goto P_0c07e950;
P_0c07e94e: /* original 64e3, guest PC 0x0c07e94e */
if(!s->budget--) { s->failed_pc=0x0c07e94eu; return 0; }
r[4]=r[14];
goto P_0c07e950;
P_0c07e950: /* original 54f2, guest PC 0x0c07e950 */
if(!s->budget--) { s->failed_pc=0x0c07e950u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07e952;
P_0c07e952: /* original 7f0c, guest PC 0x0c07e952 */
if(!s->budget--) { s->failed_pc=0x0c07e952u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07e954;
P_0c07e954: /* original 4f26, guest PC 0x0c07e954 */
if(!s->budget--) { s->failed_pc=0x0c07e954u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07e956;
P_0c07e956: /* original 65d3, guest PC 0x0c07e956 */
if(!s->budget--) { s->failed_pc=0x0c07e956u; return 0; }
r[5]=r[13];
goto P_0c07e958;
P_0c07e958: /* original 6df6, guest PC 0x0c07e958 */
if(!s->budget--) { s->failed_pc=0x0c07e958u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07e95a;
P_0c07e95a: /* original a000, guest PC 0x0c07e95a */
if(!s->budget--) { s->failed_pc=0x0c07e95au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07e95e;
P_0c07e95c: /* original 6ef6, guest PC 0x0c07e95c */
if(!s->budget--) { s->failed_pc=0x0c07e95cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07e95e;
P_0c07e95e: /* original 2fe6, guest PC 0x0c07e95e */
if(!s->budget--) { s->failed_pc=0x0c07e95eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e960;
P_0c07e960: /* original e019, guest PC 0x0c07e960 */
if(!s->budget--) { s->failed_pc=0x0c07e960u; return 0; }
r[0]=0x00000019u;
goto P_0c07e962;
P_0c07e962: /* original 2fd6, guest PC 0x0c07e962 */
if(!s->budget--) { s->failed_pc=0x0c07e962u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e964;
P_0c07e964: /* original 2fc6, guest PC 0x0c07e964 */
if(!s->budget--) { s->failed_pc=0x0c07e964u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e966;
P_0c07e966: /* original 2fb6, guest PC 0x0c07e966 */
if(!s->budget--) { s->failed_pc=0x0c07e966u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e968;
P_0c07e968: /* original 2fa6, guest PC 0x0c07e968 */
if(!s->budget--) { s->failed_pc=0x0c07e968u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e96a;
P_0c07e96a: /* original 2f96, guest PC 0x0c07e96a */
if(!s->budget--) { s->failed_pc=0x0c07e96au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e96c;
P_0c07e96c: /* original 4f22, guest PC 0x0c07e96c */
if(!s->budget--) { s->failed_pc=0x0c07e96cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07e96e;
P_0c07e96e: /* original 7ff8, guest PC 0x0c07e96e */
if(!s->budget--) { s->failed_pc=0x0c07e96eu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07e970;
P_0c07e970: /* original 2f42, guest PC 0x0c07e970 */
if(!s->budget--) { s->failed_pc=0x0c07e970u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07e972;
P_0c07e972: /* original d318, guest PC 0x0c07e972 */
if(!s->budget--) { s->failed_pc=0x0c07e972u; return 0; }
r[3]=read(ram,0x0c07e9d4u,4);
goto P_0c07e974;
P_0c07e974: /* original 1f31, guest PC 0x0c07e974 */
if(!s->budget--) { s->failed_pc=0x0c07e974u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07e976;
P_0c07e976: /* original de18, guest PC 0x0c07e976 */
if(!s->budget--) { s->failed_pc=0x0c07e976u; return 0; }
r[14]=read(ram,0x0c07e9d8u,4);
goto P_0c07e978;
P_0c07e978: /* original 6df2, guest PC 0x0c07e978 */
if(!s->budget--) { s->failed_pc=0x0c07e978u; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c07e97a;
P_0c07e97a: /* original 04ec, guest PC 0x0c07e97a */
if(!s->budget--) { s->failed_pc=0x0c07e97au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e97c;
P_0c07e97c: /* original 604e, guest PC 0x0c07e97c */
if(!s->budget--) { s->failed_pc=0x0c07e97cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c07e97e;
P_0c07e97e: /* original 8802, guest PC 0x0c07e97e */
if(!s->budget--) { s->failed_pc=0x0c07e97eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c07e980;
P_0c07e980: /* original 8f2c, guest PC 0x0c07e980 */
if(!s->budget--) { s->failed_pc=0x0c07e980u; return 0; }
cond=r[17]&1u;
r[12]=0x00000014u;
if(!cond) { goto P_0c07e9dc; }
goto P_0c07e984;
P_0c07e982: /* original ec14, guest PC 0x0c07e982 */
if(!s->budget--) { s->failed_pc=0x0c07e982u; return 0; }
r[12]=0x00000014u;
goto P_0c07e984;
P_0c07e984: /* original 9e0b, guest PC 0x0c07e984 */
if(!s->budget--) { s->failed_pc=0x0c07e984u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e99eu,2);
goto P_0c07e986;
P_0c07e986: /* original e417, guest PC 0x0c07e986 */
if(!s->budget--) { s->failed_pc=0x0c07e986u; return 0; }
r[4]=0x00000017u;
goto P_0c07e988;
P_0c07e988: /* original a056, guest PC 0x0c07e988 */
if(!s->budget--) { s->failed_pc=0x0c07e988u; return 0; }
r[5]=r[12];
goto P_0c07ea38;
P_0c07e98a: /* original 65c3, guest PC 0x0c07e98a */
if(!s->budget--) { s->failed_pc=0x0c07e98au; return 0; }
r[5]=r[12];
return vf3_matrix_family(0x0c07e98cu,s,ram);
P_0c07e9dc: /* original d340, guest PC 0x0c07e9dc */
if(!s->budget--) { s->failed_pc=0x0c07e9dcu; return 0; }
r[3]=read(ram,0x0c07eae0u,4);
goto P_0c07e9de;
P_0c07e9de: /* original 54f1, guest PC 0x0c07e9de */
if(!s->budget--) { s->failed_pc=0x0c07e9deu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07e9e0;
P_0c07e9e0: /* original 430b, guest PC 0x0c07e9e0 */
if(!s->budget--) { s->failed_pc=0x0c07e9e0u; return 0; }
target=r[3];
r[16]=0x0c07e9e4u;
r[4]+=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07e9e4u) { target=s->pc; goto dispatch; }
goto P_0c07e9e4;
P_0c07e9e2: /* original 7412, guest PC 0x0c07e9e2 */
if(!s->budget--) { s->failed_pc=0x0c07e9e2u; return 0; }
r[4]+=0x00000012u;
goto P_0c07e9e4;
P_0c07e9e4: /* original 670c, guest PC 0x0c07e9e4 */
if(!s->budget--) { s->failed_pc=0x0c07e9e4u; return 0; }
r[7]=r[0]&255u;
goto P_0c07e9e6;
P_0c07e9e6: /* original e018, guest PC 0x0c07e9e6 */
if(!s->budget--) { s->failed_pc=0x0c07e9e6u; return 0; }
r[0]=0x00000018u;
goto P_0c07e9e8;
P_0c07e9e8: /* original 06ec, guest PC 0x0c07e9e8 */
if(!s->budget--) { s->failed_pc=0x0c07e9e8u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07e9ea;
P_0c07e9ea: /* original 906d, guest PC 0x0c07e9ea */
if(!s->budget--) { s->failed_pc=0x0c07e9eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07eac8u,2);
goto P_0c07e9ec;
P_0c07e9ec: /* original 04ee, guest PC 0x0c07e9ec */
if(!s->budget--) { s->failed_pc=0x0c07e9ecu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c07e9ee;
P_0c07e9ee: /* original e046, guest PC 0x0c07e9ee */
if(!s->budget--) { s->failed_pc=0x0c07e9eeu; return 0; }
r[0]=0x00000046u;
goto P_0c07e9f0;
P_0c07e9f0: /* original 054d, guest PC 0x0c07e9f0 */
if(!s->budget--) { s->failed_pc=0x0c07e9f0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07e9f2;
P_0c07e9f2: /* original 906a, guest PC 0x0c07e9f2 */
if(!s->budget--) { s->failed_pc=0x0c07e9f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07eacau,2);
goto P_0c07e9f4;
P_0c07e9f4: /* original 004d, guest PC 0x0c07e9f4 */
if(!s->budget--) { s->failed_pc=0x0c07e9f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07e9f6;
P_0c07e9f6: /* original 646e, guest PC 0x0c07e9f6 */
if(!s->budget--) { s->failed_pc=0x0c07e9f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[6];
goto P_0c07e9f8;
P_0c07e9f8: /* original 2448, guest PC 0x0c07e9f8 */
if(!s->budget--) { s->failed_pc=0x0c07e9f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07e9fa;
P_0c07e9fa: /* original 8f0c, guest PC 0x0c07e9fa */
if(!s->budget--) { s->failed_pc=0x0c07e9fau; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[0],2);
if(!cond) { goto P_0c07ea16; }
goto P_0c07e9fe;
P_0c07e9fc: /* original 81f2, guest PC 0x0c07e9fc */
if(!s->budget--) { s->failed_pc=0x0c07e9fcu; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c07e9fe;
P_0c07e9fe: /* original 85f2, guest PC 0x0c07e9fe */
if(!s->budget--) { s->failed_pc=0x0c07e9feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c07ea00;
P_0c07ea00: /* original 655f, guest PC 0x0c07ea00 */
if(!s->budget--) { s->failed_pc=0x0c07ea00u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c07ea02;
P_0c07ea02: /* original 3500, guest PC 0x0c07ea02 */
if(!s->budget--) { s->failed_pc=0x0c07ea02u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[0])!=0);
goto P_0c07ea04;
P_0c07ea04: /* original 8b03, guest PC 0x0c07ea04 */
if(!s->budget--) { s->failed_pc=0x0c07ea04u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ea0e; }
goto P_0c07ea06;
P_0c07ea06: /* original 9e61, guest PC 0x0c07ea06 */
if(!s->budget--) { s->failed_pc=0x0c07ea06u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07eaccu,2);
goto P_0c07ea08;
P_0c07ea08: /* original e410, guest PC 0x0c07ea08 */
if(!s->budget--) { s->failed_pc=0x0c07ea08u; return 0; }
r[4]=0x00000010u;
goto P_0c07ea0a;
P_0c07ea0a: /* original a015, guest PC 0x0c07ea0a */
if(!s->budget--) { s->failed_pc=0x0c07ea0au; return 0; }
r[5]=0x0000001eu;
goto P_0c07ea38;
P_0c07ea0c: /* original e51e, guest PC 0x0c07ea0c */
if(!s->budget--) { s->failed_pc=0x0c07ea0cu; return 0; }
r[5]=0x0000001eu;
goto P_0c07ea0e;
P_0c07ea0e: /* original 9e5e, guest PC 0x0c07ea0e */
if(!s->budget--) { s->failed_pc=0x0c07ea0eu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07eaceu,2);
goto P_0c07ea10;
P_0c07ea10: /* original e41a, guest PC 0x0c07ea10 */
if(!s->budget--) { s->failed_pc=0x0c07ea10u; return 0; }
r[4]=0x0000001au;
goto P_0c07ea12;
P_0c07ea12: /* original a011, guest PC 0x0c07ea12 */
if(!s->budget--) { s->failed_pc=0x0c07ea12u; return 0; }
r[5]=0x00000018u;
goto P_0c07ea38;
P_0c07ea14: /* original e518, guest PC 0x0c07ea14 */
if(!s->budget--) { s->failed_pc=0x0c07ea14u; return 0; }
r[5]=0x00000018u;
goto P_0c07ea16;
P_0c07ea16: /* original 6043, guest PC 0x0c07ea16 */
if(!s->budget--) { s->failed_pc=0x0c07ea16u; return 0; }
r[0]=r[4];
goto P_0c07ea18;
P_0c07ea18: /* original 8801, guest PC 0x0c07ea18 */
if(!s->budget--) { s->failed_pc=0x0c07ea18u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07ea1a;
P_0c07ea1a: /* original 8b07, guest PC 0x0c07ea1a */
if(!s->budget--) { s->failed_pc=0x0c07ea1au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ea2c; }
goto P_0c07ea1c;
P_0c07ea1c: /* original 9e58, guest PC 0x0c07ea1c */
if(!s->budget--) { s->failed_pc=0x0c07ea1cu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ead0u,2);
goto P_0c07ea1e;
P_0c07ea1e: /* original 2778, guest PC 0x0c07ea1e */
if(!s->budget--) { s->failed_pc=0x0c07ea1eu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c07ea20;
P_0c07ea20: /* original e415, guest PC 0x0c07ea20 */
if(!s->budget--) { s->failed_pc=0x0c07ea20u; return 0; }
r[4]=0x00000015u;
goto P_0c07ea22;
P_0c07ea22: /* original 8d09, guest PC 0x0c07ea22 */
if(!s->budget--) { s->failed_pc=0x0c07ea22u; return 0; }
cond=r[17]&1u;
r[5]=r[12];
if(cond) { goto P_0c07ea38; }
goto P_0c07ea26;
P_0c07ea24: /* original 65c3, guest PC 0x0c07ea24 */
if(!s->budget--) { s->failed_pc=0x0c07ea24u; return 0; }
r[5]=r[12];
goto P_0c07ea26;
P_0c07ea26: /* original 9e54, guest PC 0x0c07ea26 */
if(!s->budget--) { s->failed_pc=0x0c07ea26u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ead2u,2);
goto P_0c07ea28;
P_0c07ea28: /* original a006, guest PC 0x0c07ea28 */
if(!s->budget--) { s->failed_pc=0x0c07ea28u; return 0; }
r[4]=0x0000000cu;
goto P_0c07ea38;
P_0c07ea2a: /* original e40c, guest PC 0x0c07ea2a */
if(!s->budget--) { s->failed_pc=0x0c07ea2au; return 0; }
r[4]=0x0000000cu;
goto P_0c07ea2c;
P_0c07ea2c: /* original 9e52, guest PC 0x0c07ea2c */
if(!s->budget--) { s->failed_pc=0x0c07ea2cu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ead4u,2);
goto P_0c07ea2e;
P_0c07ea2e: /* original 2778, guest PC 0x0c07ea2e */
if(!s->budget--) { s->failed_pc=0x0c07ea2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c07ea30;
P_0c07ea30: /* original e412, guest PC 0x0c07ea30 */
if(!s->budget--) { s->failed_pc=0x0c07ea30u; return 0; }
r[4]=0x00000012u;
goto P_0c07ea32;
P_0c07ea32: /* original 8d01, guest PC 0x0c07ea32 */
if(!s->budget--) { s->failed_pc=0x0c07ea32u; return 0; }
cond=r[17]&1u;
r[5]=r[12];
if(cond) { goto P_0c07ea38; }
goto P_0c07ea36;
P_0c07ea34: /* original 65c3, guest PC 0x0c07ea34 */
if(!s->budget--) { s->failed_pc=0x0c07ea34u; return 0; }
r[5]=r[12];
goto P_0c07ea36;
P_0c07ea36: /* original 9e4e, guest PC 0x0c07ea36 */
if(!s->budget--) { s->failed_pc=0x0c07ea36u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ead6u,2);
goto P_0c07ea38;
P_0c07ea38: /* original 6043, guest PC 0x0c07ea38 */
if(!s->budget--) { s->failed_pc=0x0c07ea38u; return 0; }
r[0]=r[4];
goto P_0c07ea3a;
P_0c07ea3a: /* original 81da, guest PC 0x0c07ea3a */
if(!s->budget--) { s->failed_pc=0x0c07ea3au; return 0; }
write(ram,r[13]+20,r[0],2);
goto P_0c07ea3c;
P_0c07ea3c: /* original 6053, guest PC 0x0c07ea3c */
if(!s->budget--) { s->failed_pc=0x0c07ea3cu; return 0; }
r[0]=r[5];
goto P_0c07ea3e;
P_0c07ea3e: /* original 81db, guest PC 0x0c07ea3e */
if(!s->budget--) { s->failed_pc=0x0c07ea3eu; return 0; }
write(ram,r[13]+22,r[0],2);
goto P_0c07ea40;
P_0c07ea40: /* original 60e3, guest PC 0x0c07ea40 */
if(!s->budget--) { s->failed_pc=0x0c07ea40u; return 0; }
r[0]=r[14];
goto P_0c07ea42;
P_0c07ea42: /* original 694f, guest PC 0x0c07ea42 */
if(!s->budget--) { s->failed_pc=0x0c07ea42u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c07ea44;
P_0c07ea44: /* original 81dc, guest PC 0x0c07ea44 */
if(!s->budget--) { s->failed_pc=0x0c07ea44u; return 0; }
write(ram,r[13]+24,r[0],2);
goto P_0c07ea46;
P_0c07ea46: /* original e307, guest PC 0x0c07ea46 */
if(!s->budget--) { s->failed_pc=0x0c07ea46u; return 0; }
r[3]=0x00000007u;
goto P_0c07ea48;
P_0c07ea48: /* original dc27, guest PC 0x0c07ea48 */
if(!s->budget--) { s->failed_pc=0x0c07ea48u; return 0; }
r[12]=read(ram,0x0c07eae8u,4);
goto P_0c07ea4a;
P_0c07ea4a: /* original 6a5f, guest PC 0x0c07ea4a */
if(!s->budget--) { s->failed_pc=0x0c07ea4au; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c07ea4c;
P_0c07ea4c: /* original 6d93, guest PC 0x0c07ea4c */
if(!s->budget--) { s->failed_pc=0x0c07ea4cu; return 0; }
r[13]=r[9];
goto P_0c07ea4e;
P_0c07ea4e: /* original 4d00, guest PC 0x0c07ea4e */
if(!s->budget--) { s->failed_pc=0x0c07ea4eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07ea50;
P_0c07ea50: /* original e200, guest PC 0x0c07ea50 */
if(!s->budget--) { s->failed_pc=0x0c07ea50u; return 0; }
r[2]=0x00000000u;
goto P_0c07ea52;
P_0c07ea52: /* original db24, guest PC 0x0c07ea52 */
if(!s->budget--) { s->failed_pc=0x0c07ea52u; return 0; }
r[11]=read(ram,0x0c07eae4u,4);
goto P_0c07ea54;
P_0c07ea54: /* original 4a3c, guest PC 0x0c07ea54 */
if(!s->budget--) { s->failed_pc=0x0c07ea54u; return 0; }
r[10]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[10]>>((-r[3])&31u)):((int32_t)r[10]<0?0xffffffffu:0)):r[10]<<(r[3]&31u);
goto P_0c07ea56;
P_0c07ea56: /* original 66c3, guest PC 0x0c07ea56 */
if(!s->budget--) { s->failed_pc=0x0c07ea56u; return 0; }
r[6]=r[12];
goto P_0c07ea58;
P_0c07ea58: /* original 65ed, guest PC 0x0c07ea58 */
if(!s->budget--) { s->failed_pc=0x0c07ea58u; return 0; }
r[5]=r[14]&65535u;
goto P_0c07ea5a;
P_0c07ea5a: /* original 6723, guest PC 0x0c07ea5a */
if(!s->budget--) { s->failed_pc=0x0c07ea5au; return 0; }
r[7]=r[2];
goto P_0c07ea5c;
P_0c07ea5c: /* original 2dab, guest PC 0x0c07ea5c */
if(!s->budget--) { s->failed_pc=0x0c07ea5cu; return 0; }
r[13]|=r[10];
goto P_0c07ea5e;
P_0c07ea5e: /* original 2f26, guest PC 0x0c07ea5e */
if(!s->budget--) { s->failed_pc=0x0c07ea5eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ea60;
P_0c07ea60: /* original 4b0b, guest PC 0x0c07ea60 */
if(!s->budget--) { s->failed_pc=0x0c07ea60u; return 0; }
target=r[11];
r[16]=0x0c07ea64u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ea64u) { target=s->pc; goto dispatch; }
goto P_0c07ea64;
P_0c07ea62: /* original 64d3, guest PC 0x0c07ea62 */
if(!s->budget--) { s->failed_pc=0x0c07ea62u; return 0; }
r[4]=r[13];
goto P_0c07ea64;
P_0c07ea64: /* original 9336, guest PC 0x0c07ea64 */
if(!s->budget--) { s->failed_pc=0x0c07ea64u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ead4u,2);
goto P_0c07ea66;
P_0c07ea66: /* original 64ef, guest PC 0x0c07ea66 */
if(!s->budget--) { s->failed_pc=0x0c07ea66u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c07ea68;
P_0c07ea68: /* original 3430, guest PC 0x0c07ea68 */
if(!s->budget--) { s->failed_pc=0x0c07ea68u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c07ea6a;
P_0c07ea6a: /* original 8f0d, guest PC 0x0c07ea6a */
if(!s->budget--) { s->failed_pc=0x0c07ea6au; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(!cond) { goto P_0c07ea88; }
goto P_0c07ea6e;
P_0c07ea6c: /* original 7f04, guest PC 0x0c07ea6c */
if(!s->budget--) { s->failed_pc=0x0c07ea6cu; return 0; }
r[15]+=0x00000004u;
goto P_0c07ea6e;
P_0c07ea6e: /* original 6d93, guest PC 0x0c07ea6e */
if(!s->budget--) { s->failed_pc=0x0c07ea6eu; return 0; }
r[13]=r[9];
goto P_0c07ea70;
P_0c07ea70: /* original 7d0d, guest PC 0x0c07ea70 */
if(!s->budget--) { s->failed_pc=0x0c07ea70u; return 0; }
r[13]+=0x0000000du;
goto P_0c07ea72;
P_0c07ea72: /* original e200, guest PC 0x0c07ea72 */
if(!s->budget--) { s->failed_pc=0x0c07ea72u; return 0; }
r[2]=0x00000000u;
goto P_0c07ea74;
P_0c07ea74: /* original 66c3, guest PC 0x0c07ea74 */
if(!s->budget--) { s->failed_pc=0x0c07ea74u; return 0; }
r[6]=r[12];
goto P_0c07ea76;
P_0c07ea76: /* original 4d00, guest PC 0x0c07ea76 */
if(!s->budget--) { s->failed_pc=0x0c07ea76u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07ea78;
P_0c07ea78: /* original 6723, guest PC 0x0c07ea78 */
if(!s->budget--) { s->failed_pc=0x0c07ea78u; return 0; }
r[7]=r[2];
goto P_0c07ea7a;
P_0c07ea7a: /* original 2dab, guest PC 0x0c07ea7a */
if(!s->budget--) { s->failed_pc=0x0c07ea7au; return 0; }
r[13]|=r[10];
goto P_0c07ea7c;
P_0c07ea7c: /* original 2f26, guest PC 0x0c07ea7c */
if(!s->budget--) { s->failed_pc=0x0c07ea7cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ea7e;
P_0c07ea7e: /* original 952b, guest PC 0x0c07ea7e */
if(!s->budget--) { s->failed_pc=0x0c07ea7eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ead8u,2);
goto P_0c07ea80;
P_0c07ea80: /* original 4b0b, guest PC 0x0c07ea80 */
if(!s->budget--) { s->failed_pc=0x0c07ea80u; return 0; }
target=r[11];
r[16]=0x0c07ea84u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07ea84u) { target=s->pc; goto dispatch; }
goto P_0c07ea84;
P_0c07ea82: /* original 64d3, guest PC 0x0c07ea82 */
if(!s->budget--) { s->failed_pc=0x0c07ea82u; return 0; }
r[4]=r[13];
goto P_0c07ea84;
P_0c07ea84: /* original a00f, guest PC 0x0c07ea84 */
if(!s->budget--) { s->failed_pc=0x0c07ea84u; return 0; }
r[15]+=0x00000004u;
goto P_0c07eaa6;
P_0c07ea86: /* original 7f04, guest PC 0x0c07ea86 */
if(!s->budget--) { s->failed_pc=0x0c07ea86u; return 0; }
r[15]+=0x00000004u;
goto P_0c07ea88;
P_0c07ea88: /* original 9222, guest PC 0x0c07ea88 */
if(!s->budget--) { s->failed_pc=0x0c07ea88u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ead0u,2);
goto P_0c07ea8a;
P_0c07ea8a: /* original 3420, guest PC 0x0c07ea8a */
if(!s->budget--) { s->failed_pc=0x0c07ea8au; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c07ea8c;
P_0c07ea8c: /* original 8b0b, guest PC 0x0c07ea8c */
if(!s->budget--) { s->failed_pc=0x0c07ea8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07eaa6; }
goto P_0c07ea8e;
P_0c07ea8e: /* original 6d93, guest PC 0x0c07ea8e */
if(!s->budget--) { s->failed_pc=0x0c07ea8eu; return 0; }
r[13]=r[9];
goto P_0c07ea90;
P_0c07ea90: /* original 7d0c, guest PC 0x0c07ea90 */
if(!s->budget--) { s->failed_pc=0x0c07ea90u; return 0; }
r[13]+=0x0000000cu;
goto P_0c07ea92;
P_0c07ea92: /* original e100, guest PC 0x0c07ea92 */
if(!s->budget--) { s->failed_pc=0x0c07ea92u; return 0; }
r[1]=0x00000000u;
goto P_0c07ea94;
P_0c07ea94: /* original 66c3, guest PC 0x0c07ea94 */
if(!s->budget--) { s->failed_pc=0x0c07ea94u; return 0; }
r[6]=r[12];
goto P_0c07ea96;
P_0c07ea96: /* original 4d00, guest PC 0x0c07ea96 */
if(!s->budget--) { s->failed_pc=0x0c07ea96u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07ea98;
P_0c07ea98: /* original 6713, guest PC 0x0c07ea98 */
if(!s->budget--) { s->failed_pc=0x0c07ea98u; return 0; }
r[7]=r[1];
goto P_0c07ea9a;
P_0c07ea9a: /* original 2dab, guest PC 0x0c07ea9a */
if(!s->budget--) { s->failed_pc=0x0c07ea9au; return 0; }
r[13]|=r[10];
goto P_0c07ea9c;
P_0c07ea9c: /* original 2f16, guest PC 0x0c07ea9c */
if(!s->budget--) { s->failed_pc=0x0c07ea9cu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ea9e;
P_0c07ea9e: /* original 951c, guest PC 0x0c07ea9e */
if(!s->budget--) { s->failed_pc=0x0c07ea9eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07eadau,2);
goto P_0c07eaa0;
P_0c07eaa0: /* original 4b0b, guest PC 0x0c07eaa0 */
if(!s->budget--) { s->failed_pc=0x0c07eaa0u; return 0; }
target=r[11];
r[16]=0x0c07eaa4u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07eaa4u) { target=s->pc; goto dispatch; }
goto P_0c07eaa4;
P_0c07eaa2: /* original 64d3, guest PC 0x0c07eaa2 */
if(!s->budget--) { s->failed_pc=0x0c07eaa2u; return 0; }
r[4]=r[13];
goto P_0c07eaa4;
P_0c07eaa4: /* original 7f04, guest PC 0x0c07eaa4 */
if(!s->budget--) { s->failed_pc=0x0c07eaa4u; return 0; }
r[15]+=0x00000004u;
goto P_0c07eaa6;
P_0c07eaa6: /* original d311, guest PC 0x0c07eaa6 */
if(!s->budget--) { s->failed_pc=0x0c07eaa6u; return 0; }
r[3]=read(ram,0x0c07eaecu,4);
goto P_0c07eaa8;
P_0c07eaa8: /* original 65d3, guest PC 0x0c07eaa8 */
if(!s->budget--) { s->failed_pc=0x0c07eaa8u; return 0; }
r[5]=r[13];
goto P_0c07eaaa;
P_0c07eaaa: /* original 9217, guest PC 0x0c07eaaa */
if(!s->budget--) { s->failed_pc=0x0c07eaaau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07eadcu,2);
goto P_0c07eaac;
P_0c07eaac: /* original 6132, guest PC 0x0c07eaac */
if(!s->budget--) { s->failed_pc=0x0c07eaacu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c07eaae;
P_0c07eaae: /* original 212b, guest PC 0x0c07eaae */
if(!s->budget--) { s->failed_pc=0x0c07eaaeu; return 0; }
r[1]|=r[2];
goto P_0c07eab0;
P_0c07eab0: /* original 2312, guest PC 0x0c07eab0 */
if(!s->budget--) { s->failed_pc=0x0c07eab0u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c07eab2;
P_0c07eab2: /* original 64f2, guest PC 0x0c07eab2 */
if(!s->budget--) { s->failed_pc=0x0c07eab2u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07eab4;
P_0c07eab4: /* original 7f08, guest PC 0x0c07eab4 */
if(!s->budget--) { s->failed_pc=0x0c07eab4u; return 0; }
r[15]+=0x00000008u;
goto P_0c07eab6;
P_0c07eab6: /* original 4f26, guest PC 0x0c07eab6 */
if(!s->budget--) { s->failed_pc=0x0c07eab6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07eab8;
P_0c07eab8: /* original d30d, guest PC 0x0c07eab8 */
if(!s->budget--) { s->failed_pc=0x0c07eab8u; return 0; }
r[3]=read(ram,0x0c07eaf0u,4);
goto P_0c07eaba;
P_0c07eaba: /* original 69f6, guest PC 0x0c07eaba */
if(!s->budget--) { s->failed_pc=0x0c07eabau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07eabc;
P_0c07eabc: /* original 6af6, guest PC 0x0c07eabc */
if(!s->budget--) { s->failed_pc=0x0c07eabcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07eabe;
P_0c07eabe: /* original 6bf6, guest PC 0x0c07eabe */
if(!s->budget--) { s->failed_pc=0x0c07eabeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07eac0;
P_0c07eac0: /* original 6cf6, guest PC 0x0c07eac0 */
if(!s->budget--) { s->failed_pc=0x0c07eac0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07eac2;
P_0c07eac2: /* original 6df6, guest PC 0x0c07eac2 */
if(!s->budget--) { s->failed_pc=0x0c07eac2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07eac4;
P_0c07eac4: /* original 432b, guest PC 0x0c07eac4 */
if(!s->budget--) { s->failed_pc=0x0c07eac4u; return 0; }
target=r[3];
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
P_0c07eac6: /* original 6ef6, guest PC 0x0c07eac6 */
if(!s->budget--) { s->failed_pc=0x0c07eac6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07eac8u,s,ram);
P_0c07f022: /* original 4f22, guest PC 0x0c07f022 */
if(!s->budget--) { s->failed_pc=0x0c07f022u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07f024;
P_0c07f024: /* original 7ffc, guest PC 0x0c07f024 */
if(!s->budget--) { s->failed_pc=0x0c07f024u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07f026;
P_0c07f026: /* original 2f42, guest PC 0x0c07f026 */
if(!s->budget--) { s->failed_pc=0x0c07f026u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07f028;
P_0c07f028: /* original d32f, guest PC 0x0c07f028 */
if(!s->budget--) { s->failed_pc=0x0c07f028u; return 0; }
r[3]=read(ram,0x0c07f0e8u,4);
goto P_0c07f02a;
P_0c07f02a: /* original d428, guest PC 0x0c07f02a */
if(!s->budget--) { s->failed_pc=0x0c07f02au; return 0; }
r[4]=read(ram,0x0c07f0ccu,4);
goto P_0c07f02c;
P_0c07f02c: /* original 6230, guest PC 0x0c07f02c */
if(!s->budget--) { s->failed_pc=0x0c07f02cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c07f02e;
P_0c07f02e: /* original 6e43, guest PC 0x0c07f02e */
if(!s->budget--) { s->failed_pc=0x0c07f02eu; return 0; }
r[14]=r[4];
goto P_0c07f030;
P_0c07f030: /* original 6c43, guest PC 0x0c07f030 */
if(!s->budget--) { s->failed_pc=0x0c07f030u; return 0; }
r[12]=r[4];
goto P_0c07f032;
P_0c07f032: /* original 7201, guest PC 0x0c07f032 */
if(!s->budget--) { s->failed_pc=0x0c07f032u; return 0; }
r[2]+=0x00000001u;
goto P_0c07f034;
P_0c07f034: /* original 2320, guest PC 0x0c07f034 */
if(!s->budget--) { s->failed_pc=0x0c07f034u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c07f036;
P_0c07f036: /* original e2ff, guest PC 0x0c07f036 */
if(!s->budget--) { s->failed_pc=0x0c07f036u; return 0; }
r[2]=0xffffffffu;
goto P_0c07f038;
P_0c07f038: /* original d32c, guest PC 0x0c07f038 */
if(!s->budget--) { s->failed_pc=0x0c07f038u; return 0; }
r[3]=read(ram,0x0c07f0ecu,4);
goto P_0c07f03a;
P_0c07f03a: /* original 7c58, guest PC 0x0c07f03a */
if(!s->budget--) { s->failed_pc=0x0c07f03au; return 0; }
r[12]+=0x00000058u;
goto P_0c07f03c;
P_0c07f03c: /* original 66c3, guest PC 0x0c07f03c */
if(!s->budget--) { s->failed_pc=0x0c07f03cu; return 0; }
r[6]=r[12];
goto P_0c07f03e;
P_0c07f03e: /* original 1534, guest PC 0x0c07f03e */
if(!s->budget--) { s->failed_pc=0x0c07f03eu; return 0; }
write(ram,r[5]+16,r[3],4);
goto P_0c07f040;
P_0c07f040: /* original 903e, guest PC 0x0c07f040 */
if(!s->budget--) { s->failed_pc=0x0c07f040u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f0c0u,2);
goto P_0c07f042;
P_0c07f042: /* original 0426, guest PC 0x0c07f042 */
if(!s->budget--) { s->failed_pc=0x0c07f042u; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c07f044;
P_0c07f044: /* original 903d, guest PC 0x0c07f044 */
if(!s->budget--) { s->failed_pc=0x0c07f044u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f0c2u,2);
goto P_0c07f046;
P_0c07f046: /* original 04d6, guest PC 0x0c07f046 */
if(!s->budget--) { s->failed_pc=0x0c07f046u; return 0; }
write(ram,r[4]+r[0],r[13],4);
goto P_0c07f048;
P_0c07f048: /* original 943c, guest PC 0x0c07f048 */
if(!s->budget--) { s->failed_pc=0x0c07f048u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f0c4u,2);
goto P_0c07f04a;
P_0c07f04a: /* original d321, guest PC 0x0c07f04a */
if(!s->budget--) { s->failed_pc=0x0c07f04au; return 0; }
r[3]=read(ram,0x0c07f0d0u,4);
goto P_0c07f04c;
P_0c07f04c: /* original 430b, guest PC 0x0c07f04c */
if(!s->budget--) { s->failed_pc=0x0c07f04cu; return 0; }
target=r[3];
r[16]=0x0c07f050u;
r[5]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f050u) { target=s->pc; goto dispatch; }
goto P_0c07f050;
P_0c07f04e: /* original 65e3, guest PC 0x0c07f04e */
if(!s->budget--) { s->failed_pc=0x0c07f04eu; return 0; }
r[5]=r[14];
goto P_0c07f050;
P_0c07f050: /* original d227, guest PC 0x0c07f050 */
if(!s->budget--) { s->failed_pc=0x0c07f050u; return 0; }
r[2]=read(ram,0x0c07f0f0u,4);
goto P_0c07f052;
P_0c07f052: /* original 420b, guest PC 0x0c07f052 */
if(!s->budget--) { s->failed_pc=0x0c07f052u; return 0; }
target=r[2];
r[16]=0x0c07f056u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f056u) { target=s->pc; goto dispatch; }
goto P_0c07f056;
P_0c07f054: /* original 64e3, guest PC 0x0c07f054 */
if(!s->budget--) { s->failed_pc=0x0c07f054u; return 0; }
r[4]=r[14];
goto P_0c07f056;
P_0c07f056: /* original 65d3, guest PC 0x0c07f056 */
if(!s->budget--) { s->failed_pc=0x0c07f056u; return 0; }
r[5]=r[13];
goto P_0c07f058;
P_0c07f058: /* original e63e, guest PC 0x0c07f058 */
if(!s->budget--) { s->failed_pc=0x0c07f058u; return 0; }
r[6]=0x0000003eu;
goto P_0c07f05a;
P_0c07f05a: /* original 2fd6, guest PC 0x0c07f05a */
if(!s->budget--) { s->failed_pc=0x0c07f05au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f05c;
P_0c07f05c: /* original e730, guest PC 0x0c07f05c */
if(!s->budget--) { s->failed_pc=0x0c07f05cu; return 0; }
r[7]=0x00000030u;
goto P_0c07f05e;
P_0c07f05e: /* original d31f, guest PC 0x0c07f05e */
if(!s->budget--) { s->failed_pc=0x0c07f05eu; return 0; }
r[3]=read(ram,0x0c07f0dcu,4);
goto P_0c07f060;
P_0c07f060: /* original 430b, guest PC 0x0c07f060 */
if(!s->budget--) { s->failed_pc=0x0c07f060u; return 0; }
target=r[3];
r[16]=0x0c07f064u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f064u) { target=s->pc; goto dispatch; }
goto P_0c07f064;
P_0c07f062: /* original 64c3, guest PC 0x0c07f062 */
if(!s->budget--) { s->failed_pc=0x0c07f062u; return 0; }
r[4]=r[12];
goto P_0c07f064;
P_0c07f064: /* original 9c2f, guest PC 0x0c07f064 */
if(!s->budget--) { s->failed_pc=0x0c07f064u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f0c6u,2);
goto P_0c07f066;
P_0c07f066: /* original 66e3, guest PC 0x0c07f066 */
if(!s->budget--) { s->failed_pc=0x0c07f066u; return 0; }
r[6]=r[14];
goto P_0c07f068;
P_0c07f068: /* original 2fd6, guest PC 0x0c07f068 */
if(!s->budget--) { s->failed_pc=0x0c07f068u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07f06a;
P_0c07f06a: /* original 67d3, guest PC 0x0c07f06a */
if(!s->budget--) { s->failed_pc=0x0c07f06au; return 0; }
r[7]=r[13];
goto P_0c07f06c;
P_0c07f06c: /* original 952c, guest PC 0x0c07f06c */
if(!s->budget--) { s->failed_pc=0x0c07f06cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07f0c8u,2);
goto P_0c07f06e;
P_0c07f06e: /* original d21c, guest PC 0x0c07f06e */
if(!s->budget--) { s->failed_pc=0x0c07f06eu; return 0; }
r[2]=read(ram,0x0c07f0e0u,4);
goto P_0c07f070;
P_0c07f070: /* original 420b, guest PC 0x0c07f070 */
if(!s->budget--) { s->failed_pc=0x0c07f070u; return 0; }
target=r[2];
r[16]=0x0c07f074u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07f074u) { target=s->pc; goto dispatch; }
goto P_0c07f074;
P_0c07f072: /* original 64c3, guest PC 0x0c07f072 */
if(!s->budget--) { s->failed_pc=0x0c07f072u; return 0; }
r[4]=r[12];
goto P_0c07f074;
P_0c07f074: /* original 65c3, guest PC 0x0c07f074 */
if(!s->budget--) { s->failed_pc=0x0c07f074u; return 0; }
r[5]=r[12];
goto P_0c07f076;
P_0c07f076: /* original d31f, guest PC 0x0c07f076 */
if(!s->budget--) { s->failed_pc=0x0c07f076u; return 0; }
r[3]=read(ram,0x0c07f0f4u,4);
goto P_0c07f078;
P_0c07f078: /* original 23d2, guest PC 0x0c07f078 */
if(!s->budget--) { s->failed_pc=0x0c07f078u; return 0; }
write(ram,r[3],r[13],4);
goto P_0c07f07a;
P_0c07f07a: /* original 54f2, guest PC 0x0c07f07a */
if(!s->budget--) { s->failed_pc=0x0c07f07au; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07f07c;
P_0c07f07c: /* original 7f0c, guest PC 0x0c07f07c */
if(!s->budget--) { s->failed_pc=0x0c07f07cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c07f07e;
P_0c07f07e: /* original 4f26, guest PC 0x0c07f07e */
if(!s->budget--) { s->failed_pc=0x0c07f07eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07f080;
P_0c07f080: /* original d218, guest PC 0x0c07f080 */
if(!s->budget--) { s->failed_pc=0x0c07f080u; return 0; }
r[2]=read(ram,0x0c07f0e4u,4);
goto P_0c07f082;
P_0c07f082: /* original 6cf6, guest PC 0x0c07f082 */
if(!s->budget--) { s->failed_pc=0x0c07f082u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07f084;
P_0c07f084: /* original 6df6, guest PC 0x0c07f084 */
if(!s->budget--) { s->failed_pc=0x0c07f084u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07f086;
P_0c07f086: /* original 422b, guest PC 0x0c07f086 */
if(!s->budget--) { s->failed_pc=0x0c07f086u; return 0; }
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
P_0c07f088: /* original 6ef6, guest PC 0x0c07f088 */
if(!s->budget--) { s->failed_pc=0x0c07f088u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07f08au,s,ram);
P_0c0807d2: /* original 4f22, guest PC 0x0c0807d2 */
if(!s->budget--) { s->failed_pc=0x0c0807d2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0807d4;
P_0c0807d4: /* original e320, guest PC 0x0c0807d4 */
if(!s->budget--) { s->failed_pc=0x0c0807d4u; return 0; }
r[3]=0x00000020u;
goto P_0c0807d6;
P_0c0807d6: /* original de15, guest PC 0x0c0807d6 */
if(!s->budget--) { s->failed_pc=0x0c0807d6u; return 0; }
r[14]=read(ram,0x0c08082cu,4);
goto P_0c0807d8;
P_0c0807d8: /* original 9525, guest PC 0x0c0807d8 */
if(!s->budget--) { s->failed_pc=0x0c0807d8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080826u,2);
goto P_0c0807da;
P_0c0807da: /* original 6673, guest PC 0x0c0807da */
if(!s->budget--) { s->failed_pc=0x0c0807dau; return 0; }
r[6]=r[7];
goto P_0c0807dc;
P_0c0807dc: /* original 2f36, guest PC 0x0c0807dc */
if(!s->budget--) { s->failed_pc=0x0c0807dcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0807de;
P_0c0807de: /* original d215, guest PC 0x0c0807de */
if(!s->budget--) { s->failed_pc=0x0c0807deu; return 0; }
r[2]=read(ram,0x0c080834u,4);
goto P_0c0807e0;
P_0c0807e0: /* original 420b, guest PC 0x0c0807e0 */
if(!s->budget--) { s->failed_pc=0x0c0807e0u; return 0; }
target=r[2];
r[16]=0x0c0807e4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0807e4u) { target=s->pc; goto dispatch; }
goto P_0c0807e4;
P_0c0807e2: /* original 64e3, guest PC 0x0c0807e2 */
if(!s->budget--) { s->failed_pc=0x0c0807e2u; return 0; }
r[4]=r[14];
goto P_0c0807e4;
P_0c0807e4: /* original 7f04, guest PC 0x0c0807e4 */
if(!s->budget--) { s->failed_pc=0x0c0807e4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0807e6;
P_0c0807e6: /* original d314, guest PC 0x0c0807e6 */
if(!s->budget--) { s->failed_pc=0x0c0807e6u; return 0; }
r[3]=read(ram,0x0c080838u,4);
goto P_0c0807e8;
P_0c0807e8: /* original 4f26, guest PC 0x0c0807e8 */
if(!s->budget--) { s->failed_pc=0x0c0807e8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0807ea;
P_0c0807ea: /* original 64e3, guest PC 0x0c0807ea */
if(!s->budget--) { s->failed_pc=0x0c0807eau; return 0; }
r[4]=r[14];
goto P_0c0807ec;
P_0c0807ec: /* original 432b, guest PC 0x0c0807ec */
if(!s->budget--) { s->failed_pc=0x0c0807ecu; return 0; }
target=r[3];
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
P_0c0807ee: /* original 6ef6, guest PC 0x0c0807ee */
if(!s->budget--) { s->failed_pc=0x0c0807eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0807f0u,s,ram);
P_0c0810c0: /* original 4f22, guest PC 0x0c0810c0 */
if(!s->budget--) { s->failed_pc=0x0c0810c0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0810c2;
P_0c0810c2: /* original 6030, guest PC 0x0c0810c2 */
if(!s->budget--) { s->failed_pc=0x0c0810c2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0810c4;
P_0c0810c4: /* original 600c, guest PC 0x0c0810c4 */
if(!s->budget--) { s->failed_pc=0x0c0810c4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0810c6;
P_0c0810c6: /* original 8803, guest PC 0x0c0810c6 */
if(!s->budget--) { s->failed_pc=0x0c0810c6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0810c8;
P_0c0810c8: /* original 8b10, guest PC 0x0c0810c8 */
if(!s->budget--) { s->failed_pc=0x0c0810c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0810ec; }
goto P_0c0810ca;
P_0c0810ca: /* original d128, guest PC 0x0c0810ca */
if(!s->budget--) { s->failed_pc=0x0c0810cau; return 0; }
r[1]=read(ram,0x0c08116cu,4);
goto P_0c0810cc;
P_0c0810cc: /* original d326, guest PC 0x0c0810cc */
if(!s->budget--) { s->failed_pc=0x0c0810ccu; return 0; }
r[3]=read(ram,0x0c081168u,4);
goto P_0c0810ce;
P_0c0810ce: /* original 6212, guest PC 0x0c0810ce */
if(!s->budget--) { s->failed_pc=0x0c0810ceu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0810d0;
P_0c0810d0: /* original 2238, guest PC 0x0c0810d0 */
if(!s->budget--) { s->failed_pc=0x0c0810d0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0810d2;
P_0c0810d2: /* original 8b0b, guest PC 0x0c0810d2 */
if(!s->budget--) { s->failed_pc=0x0c0810d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0810ec; }
goto P_0c0810d4;
P_0c0810d4: /* original d327, guest PC 0x0c0810d4 */
if(!s->budget--) { s->failed_pc=0x0c0810d4u; return 0; }
r[3]=read(ram,0x0c081174u,4);
goto P_0c0810d6;
P_0c0810d6: /* original e500, guest PC 0x0c0810d6 */
if(!s->budget--) { s->failed_pc=0x0c0810d6u; return 0; }
r[5]=0x00000000u;
goto P_0c0810d8;
P_0c0810d8: /* original de25, guest PC 0x0c0810d8 */
if(!s->budget--) { s->failed_pc=0x0c0810d8u; return 0; }
r[14]=read(ram,0x0c081170u,4);
goto P_0c0810da;
P_0c0810da: /* original 430b, guest PC 0x0c0810da */
if(!s->budget--) { s->failed_pc=0x0c0810dau; return 0; }
target=r[3];
r[16]=0x0c0810deu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0810deu) { target=s->pc; goto dispatch; }
goto P_0c0810de;
P_0c0810dc: /* original 64e3, guest PC 0x0c0810dc */
if(!s->budget--) { s->failed_pc=0x0c0810dcu; return 0; }
r[4]=r[14];
goto P_0c0810de;
P_0c0810de: /* original d226, guest PC 0x0c0810de */
if(!s->budget--) { s->failed_pc=0x0c0810deu; return 0; }
r[2]=read(ram,0x0c081178u,4);
goto P_0c0810e0;
P_0c0810e0: /* original 420b, guest PC 0x0c0810e0 */
if(!s->budget--) { s->failed_pc=0x0c0810e0u; return 0; }
target=r[2];
r[16]=0x0c0810e4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0810e4u) { target=s->pc; goto dispatch; }
goto P_0c0810e4;
P_0c0810e2: /* original 0009, guest PC 0x0c0810e2 */
if(!s->budget--) { s->failed_pc=0x0c0810e2u; return 0; }
goto P_0c0810e4;
P_0c0810e4: /* original d323, guest PC 0x0c0810e4 */
if(!s->budget--) { s->failed_pc=0x0c0810e4u; return 0; }
r[3]=read(ram,0x0c081174u,4);
goto P_0c0810e6;
P_0c0810e6: /* original 9533, guest PC 0x0c0810e6 */
if(!s->budget--) { s->failed_pc=0x0c0810e6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c081150u,2);
goto P_0c0810e8;
P_0c0810e8: /* original 430b, guest PC 0x0c0810e8 */
if(!s->budget--) { s->failed_pc=0x0c0810e8u; return 0; }
target=r[3];
r[16]=0x0c0810ecu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0810ecu) { target=s->pc; goto dispatch; }
goto P_0c0810ec;
P_0c0810ea: /* original 64e3, guest PC 0x0c0810ea */
if(!s->budget--) { s->failed_pc=0x0c0810eau; return 0; }
r[4]=r[14];
goto P_0c0810ec;
P_0c0810ec: /* original 4f26, guest PC 0x0c0810ec */
if(!s->budget--) { s->failed_pc=0x0c0810ecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0810ee;
P_0c0810ee: /* original 000b, guest PC 0x0c0810ee */
if(!s->budget--) { s->failed_pc=0x0c0810eeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0810f0: /* original 6ef6, guest PC 0x0c0810f0 */
if(!s->budget--) { s->failed_pc=0x0c0810f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0810f2u,s,ram);
P_0c081982: /* original 4f22, guest PC 0x0c081982 */
if(!s->budget--) { s->failed_pc=0x0c081982u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c081984;
P_0c081984: /* original 02ec, guest PC 0x0c081984 */
if(!s->budget--) { s->failed_pc=0x0c081984u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c081986;
P_0c081986: /* original 7ffc, guest PC 0x0c081986 */
if(!s->budget--) { s->failed_pc=0x0c081986u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c081988;
P_0c081988: /* original 66f3, guest PC 0x0c081988 */
if(!s->budget--) { s->failed_pc=0x0c081988u; return 0; }
r[6]=r[15];
goto P_0c08198a;
P_0c08198a: /* original 2f20, guest PC 0x0c08198a */
if(!s->budget--) { s->failed_pc=0x0c08198au; return 0; }
write(ram,r[15],r[2],1);
goto P_0c08198c;
P_0c08198c: /* original b051, guest PC 0x0c08198c */
if(!s->budget--) { s->failed_pc=0x0c08198cu; return 0; }
target=0x0c081a32u; r[16]=0x0c081990u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081990u) { target=s->pc; goto dispatch; }
goto P_0c081990;
P_0c08198e: /* original 64e3, guest PC 0x0c08198e */
if(!s->budget--) { s->failed_pc=0x0c08198eu; return 0; }
r[4]=r[14];
goto P_0c081990;
P_0c081990: /* original e593, guest PC 0x0c081990 */
if(!s->budget--) { s->failed_pc=0x0c081990u; return 0; }
r[5]=0xffffff93u;
goto P_0c081992;
P_0c081992: /* original 66f3, guest PC 0x0c081992 */
if(!s->budget--) { s->failed_pc=0x0c081992u; return 0; }
r[6]=r[15];
goto P_0c081994;
P_0c081994: /* original b04d, guest PC 0x0c081994 */
if(!s->budget--) { s->failed_pc=0x0c081994u; return 0; }
target=0x0c081a32u; r[16]=0x0c081998u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c081998u) { target=s->pc; goto dispatch; }
goto P_0c081998;
P_0c081996: /* original 64e3, guest PC 0x0c081996 */
if(!s->budget--) { s->failed_pc=0x0c081996u; return 0; }
r[4]=r[14];
goto P_0c081998;
P_0c081998: /* original 62f0, guest PC 0x0c081998 */
if(!s->budget--) { s->failed_pc=0x0c081998u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[2]=tmp;
goto P_0c08199a;
P_0c08199a: /* original 7f04, guest PC 0x0c08199a */
if(!s->budget--) { s->failed_pc=0x0c08199au; return 0; }
r[15]+=0x00000004u;
goto P_0c08199c;
P_0c08199c: /* original 4f26, guest PC 0x0c08199c */
if(!s->budget--) { s->failed_pc=0x0c08199cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08199e;
P_0c08199e: /* original 9019, guest PC 0x0c08199e */
if(!s->budget--) { s->failed_pc=0x0c08199eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0819d4u,2);
goto P_0c0819a0;
P_0c0819a0: /* original 0e24, guest PC 0x0c0819a0 */
if(!s->budget--) { s->failed_pc=0x0c0819a0u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0819a2;
P_0c0819a2: /* original 000b, guest PC 0x0c0819a2 */
if(!s->budget--) { s->failed_pc=0x0c0819a2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0819a4: /* original 6ef6, guest PC 0x0c0819a4 */
if(!s->budget--) { s->failed_pc=0x0c0819a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0819a6u,s,ram);
P_0c0819b0: /* original 4f22, guest PC 0x0c0819b0 */
if(!s->budget--) { s->failed_pc=0x0c0819b0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0819b2;
P_0c0819b2: /* original 02ec, guest PC 0x0c0819b2 */
if(!s->budget--) { s->failed_pc=0x0c0819b2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0819b4;
P_0c0819b4: /* original 7ffc, guest PC 0x0c0819b4 */
if(!s->budget--) { s->failed_pc=0x0c0819b4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0819b6;
P_0c0819b6: /* original 66f3, guest PC 0x0c0819b6 */
if(!s->budget--) { s->failed_pc=0x0c0819b6u; return 0; }
r[6]=r[15];
goto P_0c0819b8;
P_0c0819b8: /* original 2f20, guest PC 0x0c0819b8 */
if(!s->budget--) { s->failed_pc=0x0c0819b8u; return 0; }
write(ram,r[15],r[2],1);
goto P_0c0819ba;
P_0c0819ba: /* original b03a, guest PC 0x0c0819ba */
if(!s->budget--) { s->failed_pc=0x0c0819bau; return 0; }
target=0x0c081a32u; r[16]=0x0c0819beu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0819beu) { target=s->pc; goto dispatch; }
goto P_0c0819be;
P_0c0819bc: /* original 64e3, guest PC 0x0c0819bc */
if(!s->budget--) { s->failed_pc=0x0c0819bcu; return 0; }
r[4]=r[14];
goto P_0c0819be;
P_0c0819be: /* original e59b, guest PC 0x0c0819be */
if(!s->budget--) { s->failed_pc=0x0c0819beu; return 0; }
r[5]=0xffffff9bu;
goto P_0c0819c0;
P_0c0819c0: /* original 66f3, guest PC 0x0c0819c0 */
if(!s->budget--) { s->failed_pc=0x0c0819c0u; return 0; }
r[6]=r[15];
goto P_0c0819c2;
P_0c0819c2: /* original b036, guest PC 0x0c0819c2 */
if(!s->budget--) { s->failed_pc=0x0c0819c2u; return 0; }
target=0x0c081a32u; r[16]=0x0c0819c6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0819c6u) { target=s->pc; goto dispatch; }
goto P_0c0819c6;
P_0c0819c4: /* original 64e3, guest PC 0x0c0819c4 */
if(!s->budget--) { s->failed_pc=0x0c0819c4u; return 0; }
r[4]=r[14];
goto P_0c0819c6;
P_0c0819c6: /* original 62f0, guest PC 0x0c0819c6 */
if(!s->budget--) { s->failed_pc=0x0c0819c6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[2]=tmp;
goto P_0c0819c8;
P_0c0819c8: /* original 7f04, guest PC 0x0c0819c8 */
if(!s->budget--) { s->failed_pc=0x0c0819c8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0819ca;
P_0c0819ca: /* original 4f26, guest PC 0x0c0819ca */
if(!s->budget--) { s->failed_pc=0x0c0819cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0819cc;
P_0c0819cc: /* original 9002, guest PC 0x0c0819cc */
if(!s->budget--) { s->failed_pc=0x0c0819ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0819d4u,2);
goto P_0c0819ce;
P_0c0819ce: /* original 0e24, guest PC 0x0c0819ce */
if(!s->budget--) { s->failed_pc=0x0c0819ceu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0819d0;
P_0c0819d0: /* original 000b, guest PC 0x0c0819d0 */
if(!s->budget--) { s->failed_pc=0x0c0819d0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0819d2: /* original 6ef6, guest PC 0x0c0819d2 */
if(!s->budget--) { s->failed_pc=0x0c0819d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0819d4u,s,ram);
P_0c084aa2: /* original 4f22, guest PC 0x0c084aa2 */
if(!s->budget--) { s->failed_pc=0x0c084aa2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c084aa4;
P_0c084aa4: /* original 1e32, guest PC 0x0c084aa4 */
if(!s->budget--) { s->failed_pc=0x0c084aa4u; return 0; }
write(ram,r[14]+8,r[3],4);
goto P_0c084aa6;
P_0c084aa6: /* original d211, guest PC 0x0c084aa6 */
if(!s->budget--) { s->failed_pc=0x0c084aa6u; return 0; }
r[2]=read(ram,0x0c084aecu,4);
goto P_0c084aa8;
P_0c084aa8: /* original 420b, guest PC 0x0c084aa8 */
if(!s->budget--) { s->failed_pc=0x0c084aa8u; return 0; }
target=r[2];
r[16]=0x0c084aacu;
r[13]+=0x00000014u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c084aacu) { target=s->pc; goto dispatch; }
goto P_0c084aac;
P_0c084aaa: /* original 7d14, guest PC 0x0c084aaa */
if(!s->budget--) { s->failed_pc=0x0c084aaau; return 0; }
r[13]+=0x00000014u;
goto P_0c084aac;
P_0c084aac: /* original e3f9, guest PC 0x0c084aac */
if(!s->budget--) { s->failed_pc=0x0c084aacu; return 0; }
r[3]=0xfffffff9u;
goto P_0c084aae;
P_0c084aae: /* original 6403, guest PC 0x0c084aae */
if(!s->budget--) { s->failed_pc=0x0c084aaeu; return 0; }
r[4]=r[0];
goto P_0c084ab0;
P_0c084ab0: /* original 443c, guest PC 0x0c084ab0 */
if(!s->budget--) { s->failed_pc=0x0c084ab0u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c084ab2;
P_0c084ab2: /* original e20e, guest PC 0x0c084ab2 */
if(!s->budget--) { s->failed_pc=0x0c084ab2u; return 0; }
r[2]=0x0000000eu;
goto P_0c084ab4;
P_0c084ab4: /* original 2429, guest PC 0x0c084ab4 */
if(!s->budget--) { s->failed_pc=0x0c084ab4u; return 0; }
r[4]&=r[2];
goto P_0c084ab6;
P_0c084ab6: /* original e001, guest PC 0x0c084ab6 */
if(!s->budget--) { s->failed_pc=0x0c084ab6u; return 0; }
r[0]=0x00000001u;
goto P_0c084ab8;
P_0c084ab8: /* original 4401, guest PC 0x0c084ab8 */
if(!s->budget--) { s->failed_pc=0x0c084ab8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c084aba;
P_0c084aba: /* original 81e2, guest PC 0x0c084aba */
if(!s->budget--) { s->failed_pc=0x0c084abau; return 0; }
write(ram,r[14]+4,r[0],2);
goto P_0c084abc;
P_0c084abc: /* original d10f, guest PC 0x0c084abc */
if(!s->budget--) { s->failed_pc=0x0c084abcu; return 0; }
r[1]=read(ram,0x0c084afcu,4);
goto P_0c084abe;
P_0c084abe: /* original 6043, guest PC 0x0c084abe */
if(!s->budget--) { s->failed_pc=0x0c084abeu; return 0; }
r[0]=r[4];
goto P_0c084ac0;
P_0c084ac0: /* original 4000, guest PC 0x0c084ac0 */
if(!s->budget--) { s->failed_pc=0x0c084ac0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c084ac2;
P_0c084ac2: /* original 001d, guest PC 0x0c084ac2 */
if(!s->budget--) { s->failed_pc=0x0c084ac2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c084ac4;
P_0c084ac4: /* original ec0a, guest PC 0x0c084ac4 */
if(!s->budget--) { s->failed_pc=0x0c084ac4u; return 0; }
r[12]=0x0000000au;
goto P_0c084ac6;
P_0c084ac6: /* original 81e1, guest PC 0x0c084ac6 */
if(!s->budget--) { s->failed_pc=0x0c084ac6u; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c084ac8;
P_0c084ac8: /* original 65d3, guest PC 0x0c084ac8 */
if(!s->budget--) { s->failed_pc=0x0c084ac8u; return 0; }
r[5]=r[13];
goto P_0c084aca;
P_0c084aca: /* original bf57, guest PC 0x0c084aca */
if(!s->budget--) { s->failed_pc=0x0c084acau; return 0; }
target=0x0c08497cu; r[16]=0x0c084aceu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c084aceu) { target=s->pc; goto dispatch; }
goto P_0c084ace;
P_0c084acc: /* original 64e3, guest PC 0x0c084acc */
if(!s->budget--) { s->failed_pc=0x0c084accu; return 0; }
r[4]=r[14];
goto P_0c084ace;
P_0c084ace: /* original 4c10, guest PC 0x0c084ace */
if(!s->budget--) { s->failed_pc=0x0c084aceu; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c084ad0;
P_0c084ad0: /* original 8ffa, guest PC 0x0c084ad0 */
if(!s->budget--) { s->failed_pc=0x0c084ad0u; return 0; }
cond=r[17]&1u;
r[13]+=0x0000002cu;
if(!cond) { goto P_0c084ac8; }
goto P_0c084ad4;
P_0c084ad2: /* original 7d2c, guest PC 0x0c084ad2 */
if(!s->budget--) { s->failed_pc=0x0c084ad2u; return 0; }
r[13]+=0x0000002cu;
goto P_0c084ad4;
P_0c084ad4: /* original 4f26, guest PC 0x0c084ad4 */
if(!s->budget--) { s->failed_pc=0x0c084ad4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c084ad6;
P_0c084ad6: /* original 6cf6, guest PC 0x0c084ad6 */
if(!s->budget--) { s->failed_pc=0x0c084ad6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c084ad8;
P_0c084ad8: /* original 6df6, guest PC 0x0c084ad8 */
if(!s->budget--) { s->failed_pc=0x0c084ad8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c084ada;
P_0c084ada: /* original 000b, guest PC 0x0c084ada */
if(!s->budget--) { s->failed_pc=0x0c084adau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c084adc: /* original 6ef6, guest PC 0x0c084adc */
if(!s->budget--) { s->failed_pc=0x0c084adcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c084adeu,s,ram);
P_0c085cb4: /* original 5341, guest PC 0x0c085cb4 */
if(!s->budget--) { s->failed_pc=0x0c085cb4u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c085cb6;
P_0c085cb6: /* original d52b, guest PC 0x0c085cb6 */
if(!s->budget--) { s->failed_pc=0x0c085cb6u; return 0; }
r[5]=read(ram,0x0c085d64u,4);
goto P_0c085cb8;
P_0c085cb8: /* original 4f12, guest PC 0x0c085cb8 */
if(!s->budget--) { s->failed_pc=0x0c085cb8u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c085cba;
P_0c085cba: /* original 0537, guest PC 0x0c085cba */
if(!s->budget--) { s->failed_pc=0x0c085cbau; return 0; }
r[19]=r[5]*r[3];
goto P_0c085cbc;
P_0c085cbc: /* original 9250, guest PC 0x0c085cbc */
if(!s->budget--) { s->failed_pc=0x0c085cbcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085d60u,2);
goto P_0c085cbe;
P_0c085cbe: /* original 051a, guest PC 0x0c085cbe */
if(!s->budget--) { s->failed_pc=0x0c085cbeu; return 0; }
r[5]=r[19];
goto P_0c085cc0;
P_0c085cc0: /* original 352c, guest PC 0x0c085cc0 */
if(!s->budget--) { s->failed_pc=0x0c085cc0u; return 0; }
r[5]+=r[2];
goto P_0c085cc2;
P_0c085cc2: /* original 1451, guest PC 0x0c085cc2 */
if(!s->budget--) { s->failed_pc=0x0c085cc2u; return 0; }
write(ram,r[4]+4,r[5],4);
goto P_0c085cc4;
P_0c085cc4: /* original 4529, guest PC 0x0c085cc4 */
if(!s->budget--) { s->failed_pc=0x0c085cc4u; return 0; }
r[5]>>=16;
goto P_0c085cc6;
P_0c085cc6: /* original 934c, guest PC 0x0c085cc6 */
if(!s->budget--) { s->failed_pc=0x0c085cc6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085d62u,2);
goto P_0c085cc8;
P_0c085cc8: /* original 655f, guest PC 0x0c085cc8 */
if(!s->budget--) { s->failed_pc=0x0c085cc8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c085cca;
P_0c085cca: /* original 2539, guest PC 0x0c085cca */
if(!s->budget--) { s->failed_pc=0x0c085ccau; return 0; }
r[5]&=r[3];
goto P_0c085ccc;
P_0c085ccc: /* original 6053, guest PC 0x0c085ccc */
if(!s->budget--) { s->failed_pc=0x0c085cccu; return 0; }
r[0]=r[5];
goto P_0c085cce;
P_0c085cce: /* original 000b, guest PC 0x0c085cce */
if(!s->budget--) { s->failed_pc=0x0c085cceu; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c085cd0: /* original 4f16, guest PC 0x0c085cd0 */
if(!s->budget--) { s->failed_pc=0x0c085cd0u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c085cd2;
P_0c085cd2: /* original c725, guest PC 0x0c085cd2 */
if(!s->budget--) { s->failed_pc=0x0c085cd2u; return 0; }
r[0]=0x0c085d68u;
goto P_0c085cd4;
P_0c085cd4: /* original f308, guest PC 0x0c085cd4 */
if(!s->budget--) { s->failed_pc=0x0c085cd4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c085cd6;
P_0c085cd6: /* original e00c, guest PC 0x0c085cd6 */
if(!s->budget--) { s->failed_pc=0x0c085cd6u; return 0; }
r[0]=0x0000000cu;
goto P_0c085cd8;
P_0c085cd8: /* original 000b, guest PC 0x0c085cd8 */
if(!s->budget--) { s->failed_pc=0x0c085cd8u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,3,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c085cda: /* original f437, guest PC 0x0c085cda */
if(!s->budget--) { s->failed_pc=0x0c085cdau; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c085cdc;
P_0c085cdc: /* original 2fe6, guest PC 0x0c085cdc */
if(!s->budget--) { s->failed_pc=0x0c085cdcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085cde;
P_0c085cde: /* original e014, guest PC 0x0c085cde */
if(!s->budget--) { s->failed_pc=0x0c085cdeu; return 0; }
r[0]=0x00000014u;
goto P_0c085ce0;
P_0c085ce0: /* original 2fd6, guest PC 0x0c085ce0 */
if(!s->budget--) { s->failed_pc=0x0c085ce0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085ce2;
P_0c085ce2: /* original 6e53, guest PC 0x0c085ce2 */
if(!s->budget--) { s->failed_pc=0x0c085ce2u; return 0; }
r[14]=r[5];
goto P_0c085ce4;
P_0c085ce4: /* original 2fc6, guest PC 0x0c085ce4 */
if(!s->budget--) { s->failed_pc=0x0c085ce4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085ce6;
P_0c085ce6: /* original 2fb6, guest PC 0x0c085ce6 */
if(!s->budget--) { s->failed_pc=0x0c085ce6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085ce8;
P_0c085ce8: /* original 2fa6, guest PC 0x0c085ce8 */
if(!s->budget--) { s->failed_pc=0x0c085ce8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085cea;
P_0c085cea: /* original 2f96, guest PC 0x0c085cea */
if(!s->budget--) { s->failed_pc=0x0c085ceau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085cec;
P_0c085cec: /* original 2f86, guest PC 0x0c085cec */
if(!s->budget--) { s->failed_pc=0x0c085cecu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085cee;
P_0c085cee: /* original fffb, guest PC 0x0c085cee */
if(!s->budget--) { s->failed_pc=0x0c085ceeu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c085cf0;
P_0c085cf0: /* original ffeb, guest PC 0x0c085cf0 */
if(!s->budget--) { s->failed_pc=0x0c085cf0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c085cf2;
P_0c085cf2: /* original ffdb, guest PC 0x0c085cf2 */
if(!s->budget--) { s->failed_pc=0x0c085cf2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c085cf4;
P_0c085cf4: /* original ffcb, guest PC 0x0c085cf4 */
if(!s->budget--) { s->failed_pc=0x0c085cf4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c085cf6;
P_0c085cf6: /* original 4f22, guest PC 0x0c085cf6 */
if(!s->budget--) { s->failed_pc=0x0c085cf6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c085cf8;
P_0c085cf8: /* original 7fd8, guest PC 0x0c085cf8 */
if(!s->budget--) { s->failed_pc=0x0c085cf8u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c085cfa;
P_0c085cfa: /* original 1f42, guest PC 0x0c085cfa */
if(!s->budget--) { s->failed_pc=0x0c085cfau; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c085cfc;
P_0c085cfc: /* original 1f63, guest PC 0x0c085cfc */
if(!s->budget--) { s->failed_pc=0x0c085cfcu; return 0; }
write(ram,r[15]+12,r[6],4);
goto P_0c085cfe;
P_0c085cfe: /* original fc4c, guest PC 0x0c085cfe */
if(!s->budget--) { s->failed_pc=0x0c085cfeu; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c085d00;
P_0c085d00: /* original ff57, guest PC 0x0c085d00 */
if(!s->budget--) { s->failed_pc=0x0c085d00u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c085d02;
P_0c085d02: /* original e004, guest PC 0x0c085d02 */
if(!s->budget--) { s->failed_pc=0x0c085d02u; return 0; }
r[0]=0x00000004u;
goto P_0c085d04;
P_0c085d04: /* original ff67, guest PC 0x0c085d04 */
if(!s->budget--) { s->failed_pc=0x0c085d04u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c085d06;
P_0c085d06: /* original c719, guest PC 0x0c085d06 */
if(!s->budget--) { s->failed_pc=0x0c085d06u; return 0; }
r[0]=0x0c085d6cu;
goto P_0c085d08;
P_0c085d08: /* original f308, guest PC 0x0c085d08 */
if(!s->budget--) { s->failed_pc=0x0c085d08u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c085d0a;
P_0c085d0a: /* original e010, guest PC 0x0c085d0a */
if(!s->budget--) { s->failed_pc=0x0c085d0au; return 0; }
r[0]=0x00000010u;
goto P_0c085d0c;
P_0c085d0c: /* original ff37, guest PC 0x0c085d0c */
if(!s->budget--) { s->failed_pc=0x0c085d0cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c085d0e;
P_0c085d0e: /* original e004, guest PC 0x0c085d0e */
if(!s->budget--) { s->failed_pc=0x0c085d0eu; return 0; }
r[0]=0x00000004u;
goto P_0c085d10;
P_0c085d10: /* original 59f3, guest PC 0x0c085d10 */
if(!s->budget--) { s->failed_pc=0x0c085d10u; return 0; }
r[9]=read(ram,r[15]+12,4);
goto P_0c085d12;
P_0c085d12: /* original 6991, guest PC 0x0c085d12 */
if(!s->budget--) { s->failed_pc=0x0c085d12u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[9],2);
r[9]=tmp;
goto P_0c085d14;
P_0c085d14: /* original 1f96, guest PC 0x0c085d14 */
if(!s->budget--) { s->failed_pc=0x0c085d14u; return 0; }
write(ram,r[15]+24,r[9],4);
goto P_0c085d16;
P_0c085d16: /* original d816, guest PC 0x0c085d16 */
if(!s->budget--) { s->failed_pc=0x0c085d16u; return 0; }
r[8]=read(ram,0x0c085d70u,4);
goto P_0c085d18;
P_0c085d18: /* original f5f6, guest PC 0x0c085d18 */
if(!s->budget--) { s->failed_pc=0x0c085d18u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c085d1a;
P_0c085d1a: /* original f4cc, guest PC 0x0c085d1a */
if(!s->budget--) { s->failed_pc=0x0c085d1au; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c085d1c;
P_0c085d1c: /* original 65f3, guest PC 0x0c085d1c */
if(!s->budget--) { s->failed_pc=0x0c085d1cu; return 0; }
r[5]=r[15];
goto P_0c085d1e;
P_0c085d1e: /* original 751c, guest PC 0x0c085d1e */
if(!s->budget--) { s->failed_pc=0x0c085d1eu; return 0; }
r[5]+=0x0000001cu;
goto P_0c085d20;
P_0c085d20: /* original 480b, guest PC 0x0c085d20 */
if(!s->budget--) { s->failed_pc=0x0c085d20u; return 0; }
target=r[8];
r[16]=0x0c085d24u;
r[4]=r[15];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085d24u) { target=s->pc; goto dispatch; }
goto P_0c085d24;
P_0c085d22: /* original 64f3, guest PC 0x0c085d22 */
if(!s->budget--) { s->failed_pc=0x0c085d22u; return 0; }
r[4]=r[15];
goto P_0c085d24;
P_0c085d24: /* original e014, guest PC 0x0c085d24 */
if(!s->budget--) { s->failed_pc=0x0c085d24u; return 0; }
r[0]=0x00000014u;
goto P_0c085d26;
P_0c085d26: /* original f2f8, guest PC 0x0c085d26 */
if(!s->budget--) { s->failed_pc=0x0c085d26u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c085d28;
P_0c085d28: /* original f3f6, guest PC 0x0c085d28 */
if(!s->budget--) { s->failed_pc=0x0c085d28u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c085d2a;
P_0c085d2a: /* original f325, guest PC 0x0c085d2a */
if(!s->budget--) { s->failed_pc=0x0c085d2au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c085d2c;
P_0c085d2c: /* original 8f02, guest PC 0x0c085d2c */
if(!s->budget--) { s->failed_pc=0x0c085d2cu; return 0; }
cond=r[17]&1u;
r[12]=0x00000001u;
if(!cond) { goto P_0c085d34; }
goto P_0c085d30;
P_0c085d2e: /* original ec01, guest PC 0x0c085d2e */
if(!s->budget--) { s->failed_pc=0x0c085d2eu; return 0; }
r[12]=0x00000001u;
goto P_0c085d30;
P_0c085d30: /* original a06f, guest PC 0x0c085d30 */
if(!s->budget--) { s->failed_pc=0x0c085d30u; return 0; }
r[9]|=r[12];
goto P_0c085e12;
P_0c085d32: /* original 29cb, guest PC 0x0c085d32 */
if(!s->budget--) { s->failed_pc=0x0c085d32u; return 0; }
r[9]|=r[12];
goto P_0c085d34;
P_0c085d34: /* original 53f6, guest PC 0x0c085d34 */
if(!s->budget--) { s->failed_pc=0x0c085d34u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c085d36;
P_0c085d36: /* original e2fe, guest PC 0x0c085d36 */
if(!s->budget--) { s->failed_pc=0x0c085d36u; return 0; }
r[2]=0xfffffffeu;
goto P_0c085d38;
P_0c085d38: /* original 23c8, guest PC 0x0c085d38 */
if(!s->budget--) { s->failed_pc=0x0c085d38u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c085d3a;
P_0c085d3a: /* original 8d6a, guest PC 0x0c085d3a */
if(!s->budget--) { s->failed_pc=0x0c085d3au; return 0; }
cond=r[17]&1u;
r[9]&=r[2];
if(cond) { goto P_0c085e12; }
goto P_0c085d3e;
P_0c085d3c: /* original 2929, guest PC 0x0c085d3c */
if(!s->budget--) { s->failed_pc=0x0c085d3cu; return 0; }
r[9]&=r[2];
goto P_0c085d3e;
P_0c085d3e: /* original c70d, guest PC 0x0c085d3e */
if(!s->budget--) { s->failed_pc=0x0c085d3eu; return 0; }
r[0]=0x0c085d74u;
goto P_0c085d40;
P_0c085d40: /* original fe08, guest PC 0x0c085d40 */
if(!s->budget--) { s->failed_pc=0x0c085d40u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c085d42;
P_0c085d42: /* original ea07, guest PC 0x0c085d42 */
if(!s->budget--) { s->failed_pc=0x0c085d42u; return 0; }
r[10]=0x00000007u;
goto P_0c085d44;
P_0c085d44: /* original a063, guest PC 0x0c085d44 */
if(!s->budget--) { s->failed_pc=0x0c085d44u; return 0; }
r[13]=0x0000001fu;
goto P_0c085e0e;
P_0c085d46: /* original ed1f, guest PC 0x0c085d46 */
if(!s->budget--) { s->failed_pc=0x0c085d46u; return 0; }
r[13]=0x0000001fu;
goto P_0c085d48;
P_0c085d48: /* original d20b, guest PC 0x0c085d48 */
if(!s->budget--) { s->failed_pc=0x0c085d48u; return 0; }
r[2]=read(ram,0x0c085d78u,4);
goto P_0c085d4a;
P_0c085d4a: /* original 6322, guest PC 0x0c085d4a */
if(!s->budget--) { s->failed_pc=0x0c085d4au; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c085d4c;
P_0c085d4c: /* original 3e32, guest PC 0x0c085d4c */
if(!s->budget--) { s->failed_pc=0x0c085d4cu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[3])!=0);
goto P_0c085d4e;
P_0c085d4e: /* original 8960, guest PC 0x0c085d4e */
if(!s->budget--) { s->failed_pc=0x0c085d4eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c085e12; }
goto P_0c085d50;
P_0c085d50: /* original 54e4, guest PC 0x0c085d50 */
if(!s->budget--) { s->failed_pc=0x0c085d50u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c085d52;
P_0c085d52: /* original 2448, guest PC 0x0c085d52 */
if(!s->budget--) { s->failed_pc=0x0c085d52u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c085d54;
P_0c085d54: /* original 8b01, guest PC 0x0c085d54 */
if(!s->budget--) { s->failed_pc=0x0c085d54u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085d5a; }
goto P_0c085d56;
P_0c085d56: /* original a011, guest PC 0x0c085d56 */
if(!s->budget--) { s->failed_pc=0x0c085d56u; return 0; }
write(ram,r[14]+16,r[12],4);
goto P_0c085d7c;
P_0c085d58: /* original 1ec4, guest PC 0x0c085d58 */
if(!s->budget--) { s->failed_pc=0x0c085d58u; return 0; }
write(ram,r[14]+16,r[12],4);
goto P_0c085d5a;
P_0c085d5a: /* original aff5, guest PC 0x0c085d5a */
if(!s->budget--) { s->failed_pc=0x0c085d5au; return 0; }
r[14]+=0x00000014u;
goto P_0c085d48;
P_0c085d5c: /* original 7e14, guest PC 0x0c085d5c */
if(!s->budget--) { s->failed_pc=0x0c085d5cu; return 0; }
r[14]+=0x00000014u;
return vf3_matrix_family(0x0c085d5eu,s,ram);
P_0c085d7c: /* original bf9a, guest PC 0x0c085d7c */
if(!s->budget--) { s->failed_pc=0x0c085d7cu; return 0; }
target=0x0c085cb4u; r[16]=0x0c085d80u;
r[4]=read(ram,r[15]+8,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085d80u) { target=s->pc; goto dispatch; }
goto P_0c085d80;
P_0c085d7e: /* original 54f2, guest PC 0x0c085d7e */
if(!s->budget--) { s->failed_pc=0x0c085d7eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c085d80;
P_0c085d80: /* original 6503, guest PC 0x0c085d80 */
if(!s->budget--) { s->failed_pc=0x0c085d80u; return 0; }
r[5]=r[0];
goto P_0c085d82;
P_0c085d82: /* original 25d9, guest PC 0x0c085d82 */
if(!s->budget--) { s->failed_pc=0x0c085d82u; return 0; }
r[5]&=r[13];
goto P_0c085d84;
P_0c085d84: /* original 75f1, guest PC 0x0c085d84 */
if(!s->budget--) { s->failed_pc=0x0c085d84u; return 0; }
r[5]+=0xfffffff1u;
goto P_0c085d86;
P_0c085d86: /* original 6303, guest PC 0x0c085d86 */
if(!s->budget--) { s->failed_pc=0x0c085d86u; return 0; }
r[3]=r[0];
goto P_0c085d88;
P_0c085d88: /* original 455a, guest PC 0x0c085d88 */
if(!s->budget--) { s->failed_pc=0x0c085d88u; return 0; }
r[53]=r[5];
goto P_0c085d8a;
P_0c085d8a: /* original 6503, guest PC 0x0c085d8a */
if(!s->budget--) { s->failed_pc=0x0c085d8au; return 0; }
r[5]=r[0];
goto P_0c085d8c;
P_0c085d8c: /* original 4528, guest PC 0x0c085d8c */
if(!s->budget--) { s->failed_pc=0x0c085d8cu; return 0; }
r[5]<<=16;
goto P_0c085d8e;
P_0c085d8e: /* original 6403, guest PC 0x0c085d8e */
if(!s->budget--) { s->failed_pc=0x0c085d8eu; return 0; }
r[4]=r[0];
goto P_0c085d90;
P_0c085d90: /* original 4518, guest PC 0x0c085d90 */
if(!s->budget--) { s->failed_pc=0x0c085d90u; return 0; }
r[5]<<=8;
goto P_0c085d92;
P_0c085d92: /* original ffcc, guest PC 0x0c085d92 */
if(!s->budget--) { s->failed_pc=0x0c085d92u; return 0; }
vf3_matrix_move(s,15,12);
goto P_0c085d94;
P_0c085d94: /* original e2fa, guest PC 0x0c085d94 */
if(!s->budget--) { s->failed_pc=0x0c085d94u; return 0; }
r[2]=0xfffffffau;
goto P_0c085d96;
P_0c085d96: /* original f32d, guest PC 0x0c085d96 */
if(!s->budget--) { s->failed_pc=0x0c085d96u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c085d98;
P_0c085d98: /* original 4508, guest PC 0x0c085d98 */
if(!s->budget--) { s->failed_pc=0x0c085d98u; return 0; }
r[5]<<=2;
goto P_0c085d9a;
P_0c085d9a: /* original f0ec, guest PC 0x0c085d9a */
if(!s->budget--) { s->failed_pc=0x0c085d9au; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c085d9c;
P_0c085d9c: /* original 432c, guest PC 0x0c085d9c */
if(!s->budget--) { s->failed_pc=0x0c085d9cu; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c085d9e;
P_0c085d9e: /* original 6243, guest PC 0x0c085d9e */
if(!s->budget--) { s->failed_pc=0x0c085d9eu; return 0; }
r[2]=r[4];
goto P_0c085da0;
P_0c085da0: /* original 253b, guest PC 0x0c085da0 */
if(!s->budget--) { s->failed_pc=0x0c085da0u; return 0; }
r[5]|=r[3];
goto P_0c085da2;
P_0c085da2: /* original 6343, guest PC 0x0c085da2 */
if(!s->budget--) { s->failed_pc=0x0c085da2u; return 0; }
r[3]=r[4];
goto P_0c085da4;
P_0c085da4: /* original 25d9, guest PC 0x0c085da4 */
if(!s->budget--) { s->failed_pc=0x0c085da4u; return 0; }
r[5]&=r[13];
goto P_0c085da6;
P_0c085da6: /* original 75f1, guest PC 0x0c085da6 */
if(!s->budget--) { s->failed_pc=0x0c085da6u; return 0; }
r[5]+=0xfffffff1u;
goto P_0c085da8;
P_0c085da8: /* original f43c, guest PC 0x0c085da8 */
if(!s->budget--) { s->failed_pc=0x0c085da8u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c085daa;
P_0c085daa: /* original 455a, guest PC 0x0c085daa */
if(!s->budget--) { s->failed_pc=0x0c085daau; return 0; }
r[53]=r[5];
goto P_0c085dac;
P_0c085dac: /* original e004, guest PC 0x0c085dac */
if(!s->budget--) { s->failed_pc=0x0c085dacu; return 0; }
r[0]=0x00000004u;
goto P_0c085dae;
P_0c085dae: /* original ff4e, guest PC 0x0c085dae */
if(!s->budget--) { s->failed_pc=0x0c085daeu; return 0; }
fr[15]=vf3_fpu_mac(fr[0],fr[4],fr[15],r[18]);
goto P_0c085db0;
P_0c085db0: /* original fdf6, guest PC 0x0c085db0 */
if(!s->budget--) { s->failed_pc=0x0c085db0u; return 0; }
vf3_matrix_load(s,ram,13,r[15]+r[0]);
goto P_0c085db2;
P_0c085db2: /* original e1f8, guest PC 0x0c085db2 */
if(!s->budget--) { s->failed_pc=0x0c085db2u; return 0; }
r[1]=0xfffffff8u;
goto P_0c085db4;
P_0c085db4: /* original f32d, guest PC 0x0c085db4 */
if(!s->budget--) { s->failed_pc=0x0c085db4u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c085db6;
P_0c085db6: /* original 4328, guest PC 0x0c085db6 */
if(!s->budget--) { s->failed_pc=0x0c085db6u; return 0; }
r[3]<<=16;
goto P_0c085db8;
P_0c085db8: /* original 421c, guest PC 0x0c085db8 */
if(!s->budget--) { s->failed_pc=0x0c085db8u; return 0; }
r[2]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[2]>>((-r[1])&31u)):((int32_t)r[2]<0?0xffffffffu:0)):r[2]<<(r[1]&31u);
goto P_0c085dba;
P_0c085dba: /* original 4318, guest PC 0x0c085dba */
if(!s->budget--) { s->failed_pc=0x0c085dbau; return 0; }
r[3]<<=8;
goto P_0c085dbc;
P_0c085dbc: /* original f43c, guest PC 0x0c085dbc */
if(!s->budget--) { s->failed_pc=0x0c085dbcu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c085dbe;
P_0c085dbe: /* original fd4e, guest PC 0x0c085dbe */
if(!s->budget--) { s->failed_pc=0x0c085dbeu; return 0; }
fr[13]=vf3_fpu_mac(fr[0],fr[4],fr[13],r[18]);
goto P_0c085dc0;
P_0c085dc0: /* original 232b, guest PC 0x0c085dc0 */
if(!s->budget--) { s->failed_pc=0x0c085dc0u; return 0; }
r[3]|=r[2];
goto P_0c085dc2;
P_0c085dc2: /* original 65f3, guest PC 0x0c085dc2 */
if(!s->budget--) { s->failed_pc=0x0c085dc2u; return 0; }
r[5]=r[15];
goto P_0c085dc4;
P_0c085dc4: /* original 6433, guest PC 0x0c085dc4 */
if(!s->budget--) { s->failed_pc=0x0c085dc4u; return 0; }
r[4]=r[3];
goto P_0c085dc6;
P_0c085dc6: /* original 24d9, guest PC 0x0c085dc6 */
if(!s->budget--) { s->failed_pc=0x0c085dc6u; return 0; }
r[4]&=r[13];
goto P_0c085dc8;
P_0c085dc8: /* original 445a, guest PC 0x0c085dc8 */
if(!s->budget--) { s->failed_pc=0x0c085dc8u; return 0; }
r[53]=r[4];
goto P_0c085dca;
P_0c085dca: /* original e010, guest PC 0x0c085dca */
if(!s->budget--) { s->failed_pc=0x0c085dcau; return 0; }
r[0]=0x00000010u;
goto P_0c085dcc;
P_0c085dcc: /* original f2f6, guest PC 0x0c085dcc */
if(!s->budget--) { s->failed_pc=0x0c085dccu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c085dce;
P_0c085dce: /* original c73f, guest PC 0x0c085dce */
if(!s->budget--) { s->failed_pc=0x0c085dceu; return 0; }
r[0]=0x0c085eccu;
goto P_0c085dd0;
P_0c085dd0: /* original f008, guest PC 0x0c085dd0 */
if(!s->budget--) { s->failed_pc=0x0c085dd0u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c085dd2;
P_0c085dd2: /* original e008, guest PC 0x0c085dd2 */
if(!s->budget--) { s->failed_pc=0x0c085dd2u; return 0; }
r[0]=0x00000008u;
goto P_0c085dd4;
P_0c085dd4: /* original f32d, guest PC 0x0c085dd4 */
if(!s->budget--) { s->failed_pc=0x0c085dd4u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c085dd6;
P_0c085dd6: /* original 64f3, guest PC 0x0c085dd6 */
if(!s->budget--) { s->failed_pc=0x0c085dd6u; return 0; }
r[4]=r[15];
goto P_0c085dd8;
P_0c085dd8: /* original 751c, guest PC 0x0c085dd8 */
if(!s->budget--) { s->failed_pc=0x0c085dd8u; return 0; }
r[5]+=0x0000001cu;
goto P_0c085dda;
P_0c085dda: /* original f43c, guest PC 0x0c085dda */
if(!s->budget--) { s->failed_pc=0x0c085ddau; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c085ddc;
P_0c085ddc: /* original f24e, guest PC 0x0c085ddc */
if(!s->budget--) { s->failed_pc=0x0c085ddcu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[4],fr[2],r[18]);
goto P_0c085dde;
P_0c085dde: /* original f42c, guest PC 0x0c085dde */
if(!s->budget--) { s->failed_pc=0x0c085ddeu; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c085de0;
P_0c085de0: /* original fefa, guest PC 0x0c085de0 */
if(!s->budget--) { s->failed_pc=0x0c085de0u; return 0; }
vf3_matrix_store(s,ram,15,r[14]);
goto P_0c085de2;
P_0c085de2: /* original f3dc, guest PC 0x0c085de2 */
if(!s->budget--) { s->failed_pc=0x0c085de2u; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c085de4;
P_0c085de4: /* original f34d, guest PC 0x0c085de4 */
if(!s->budget--) { s->failed_pc=0x0c085de4u; return 0; }
fr[3]^=0x80000000u;
goto P_0c085de6;
P_0c085de6: /* original fe37, guest PC 0x0c085de6 */
if(!s->budget--) { s->failed_pc=0x0c085de6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c085de8;
P_0c085de8: /* original e00c, guest PC 0x0c085de8 */
if(!s->budget--) { s->failed_pc=0x0c085de8u; return 0; }
r[0]=0x0000000cu;
goto P_0c085dea;
P_0c085dea: /* original fe47, guest PC 0x0c085dea */
if(!s->budget--) { s->failed_pc=0x0c085deau; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c085dec;
P_0c085dec: /* original f5dc, guest PC 0x0c085dec */
if(!s->budget--) { s->failed_pc=0x0c085decu; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c085dee;
P_0c085dee: /* original 480b, guest PC 0x0c085dee */
if(!s->budget--) { s->failed_pc=0x0c085deeu; return 0; }
target=r[8];
r[16]=0x0c085df2u;
vf3_matrix_move(s,4,15);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085df2u) { target=s->pc; goto dispatch; }
goto P_0c085df2;
P_0c085df0: /* original f4fc, guest PC 0x0c085df0 */
if(!s->budget--) { s->failed_pc=0x0c085df0u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c085df2;
P_0c085df2: /* original f3f8, guest PC 0x0c085df2 */
if(!s->budget--) { s->failed_pc=0x0c085df2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c085df4;
P_0c085df4: /* original 6b03, guest PC 0x0c085df4 */
if(!s->budget--) { s->failed_pc=0x0c085df4u; return 0; }
r[11]=r[0];
goto P_0c085df6;
P_0c085df6: /* original e004, guest PC 0x0c085df6 */
if(!s->budget--) { s->failed_pc=0x0c085df6u; return 0; }
r[0]=0x00000004u;
goto P_0c085df8;
P_0c085df8: /* original fe37, guest PC 0x0c085df8 */
if(!s->budget--) { s->failed_pc=0x0c085df8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c085dfa;
P_0c085dfa: /* original e3fd, guest PC 0x0c085dfa */
if(!s->budget--) { s->failed_pc=0x0c085dfau; return 0; }
r[3]=0xfffffffdu;
goto P_0c085dfc;
P_0c085dfc: /* original 9265, guest PC 0x0c085dfc */
if(!s->budget--) { s->failed_pc=0x0c085dfcu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085ecau,2);
goto P_0c085dfe;
P_0c085dfe: /* original 54e4, guest PC 0x0c085dfe */
if(!s->budget--) { s->failed_pc=0x0c085dfeu; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c085e00;
P_0c085e00: /* original 22b8, guest PC 0x0c085e00 */
if(!s->budget--) { s->failed_pc=0x0c085e00u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[11])==0)!=0);
goto P_0c085e02;
P_0c085e02: /* original 8d02, guest PC 0x0c085e02 */
if(!s->budget--) { s->failed_pc=0x0c085e02u; return 0; }
cond=r[17]&1u;
r[4]&=r[3];
if(cond) { goto P_0c085e0a; }
goto P_0c085e06;
P_0c085e04: /* original 2439, guest PC 0x0c085e04 */
if(!s->budget--) { s->failed_pc=0x0c085e04u; return 0; }
r[4]&=r[3];
goto P_0c085e06;
P_0c085e06: /* original e002, guest PC 0x0c085e06 */
if(!s->budget--) { s->failed_pc=0x0c085e06u; return 0; }
r[0]=0x00000002u;
goto P_0c085e08;
P_0c085e08: /* original 240b, guest PC 0x0c085e08 */
if(!s->budget--) { s->failed_pc=0x0c085e08u; return 0; }
r[4]|=r[0];
goto P_0c085e0a;
P_0c085e0a: /* original 7aff, guest PC 0x0c085e0a */
if(!s->budget--) { s->failed_pc=0x0c085e0au; return 0; }
r[10]+=0xffffffffu;
goto P_0c085e0c;
P_0c085e0c: /* original 1e44, guest PC 0x0c085e0c */
if(!s->budget--) { s->failed_pc=0x0c085e0cu; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c085e0e;
P_0c085e0e: /* original 4a15, guest PC 0x0c085e0e */
if(!s->budget--) { s->failed_pc=0x0c085e0eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>0)!=0);
goto P_0c085e10;
P_0c085e10: /* original 899a, guest PC 0x0c085e10 */
if(!s->budget--) { s->failed_pc=0x0c085e10u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c085d48; }
goto P_0c085e12;
P_0c085e12: /* original 52f3, guest PC 0x0c085e12 */
if(!s->budget--) { s->failed_pc=0x0c085e12u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c085e14;
P_0c085e14: /* original 7f28, guest PC 0x0c085e14 */
if(!s->budget--) { s->failed_pc=0x0c085e14u; return 0; }
r[15]+=0x00000028u;
goto P_0c085e16;
P_0c085e16: /* original 4f26, guest PC 0x0c085e16 */
if(!s->budget--) { s->failed_pc=0x0c085e16u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c085e18;
P_0c085e18: /* original 2291, guest PC 0x0c085e18 */
if(!s->budget--) { s->failed_pc=0x0c085e18u; return 0; }
write(ram,r[2],r[9],2);
goto P_0c085e1a;
P_0c085e1a: /* original fcf9, guest PC 0x0c085e1a */
if(!s->budget--) { s->failed_pc=0x0c085e1au; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085e1c;
P_0c085e1c: /* original fdf9, guest PC 0x0c085e1c */
if(!s->budget--) { s->failed_pc=0x0c085e1cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085e1e;
P_0c085e1e: /* original fef9, guest PC 0x0c085e1e */
if(!s->budget--) { s->failed_pc=0x0c085e1eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085e20;
P_0c085e20: /* original fff9, guest PC 0x0c085e20 */
if(!s->budget--) { s->failed_pc=0x0c085e20u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085e22;
P_0c085e22: /* original 68f6, guest PC 0x0c085e22 */
if(!s->budget--) { s->failed_pc=0x0c085e22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c085e24;
P_0c085e24: /* original 69f6, guest PC 0x0c085e24 */
if(!s->budget--) { s->failed_pc=0x0c085e24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c085e26;
P_0c085e26: /* original 6af6, guest PC 0x0c085e26 */
if(!s->budget--) { s->failed_pc=0x0c085e26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c085e28;
P_0c085e28: /* original 6bf6, guest PC 0x0c085e28 */
if(!s->budget--) { s->failed_pc=0x0c085e28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c085e2a;
P_0c085e2a: /* original 6cf6, guest PC 0x0c085e2a */
if(!s->budget--) { s->failed_pc=0x0c085e2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c085e2c;
P_0c085e2c: /* original 6df6, guest PC 0x0c085e2c */
if(!s->budget--) { s->failed_pc=0x0c085e2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c085e2e;
P_0c085e2e: /* original 000b, guest PC 0x0c085e2e */
if(!s->budget--) { s->failed_pc=0x0c085e2eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c085e30: /* original 6ef6, guest PC 0x0c085e30 */
if(!s->budget--) { s->failed_pc=0x0c085e30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c085e32;
P_0c085e32: /* original 2fe6, guest PC 0x0c085e32 */
if(!s->budget--) { s->failed_pc=0x0c085e32u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085e34;
P_0c085e34: /* original e008, guest PC 0x0c085e34 */
if(!s->budget--) { s->failed_pc=0x0c085e34u; return 0; }
r[0]=0x00000008u;
goto P_0c085e36;
P_0c085e36: /* original 2fd6, guest PC 0x0c085e36 */
if(!s->budget--) { s->failed_pc=0x0c085e36u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085e38;
P_0c085e38: /* original 6e53, guest PC 0x0c085e38 */
if(!s->budget--) { s->failed_pc=0x0c085e38u; return 0; }
r[14]=r[5];
goto P_0c085e3a;
P_0c085e3a: /* original 2fc6, guest PC 0x0c085e3a */
if(!s->budget--) { s->failed_pc=0x0c085e3au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085e3c;
P_0c085e3c: /* original fffb, guest PC 0x0c085e3c */
if(!s->budget--) { s->failed_pc=0x0c085e3cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c085e3e;
P_0c085e3e: /* original ffeb, guest PC 0x0c085e3e */
if(!s->budget--) { s->failed_pc=0x0c085e3eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c085e40;
P_0c085e40: /* original ffdb, guest PC 0x0c085e40 */
if(!s->budget--) { s->failed_pc=0x0c085e40u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c085e42;
P_0c085e42: /* original ffcb, guest PC 0x0c085e42 */
if(!s->budget--) { s->failed_pc=0x0c085e42u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c085e44;
P_0c085e44: /* original 4f22, guest PC 0x0c085e44 */
if(!s->budget--) { s->failed_pc=0x0c085e44u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c085e46;
P_0c085e46: /* original fd5c, guest PC 0x0c085e46 */
if(!s->budget--) { s->failed_pc=0x0c085e46u; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c085e48;
P_0c085e48: /* original fe4c, guest PC 0x0c085e48 */
if(!s->budget--) { s->failed_pc=0x0c085e48u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c085e4a;
P_0c085e4a: /* original 7fd4, guest PC 0x0c085e4a */
if(!s->budget--) { s->failed_pc=0x0c085e4au; return 0; }
r[15]+=0xffffffd4u;
goto P_0c085e4c;
P_0c085e4c: /* original ff77, guest PC 0x0c085e4c */
if(!s->budget--) { s->failed_pc=0x0c085e4cu; return 0; }
vf3_matrix_store(s,ram,7,r[15]+r[0]);
goto P_0c085e4e;
P_0c085e4e: /* original e010, guest PC 0x0c085e4e */
if(!s->budget--) { s->failed_pc=0x0c085e4eu; return 0; }
r[0]=0x00000010u;
goto P_0c085e50;
P_0c085e50: /* original ff87, guest PC 0x0c085e50 */
if(!s->budget--) { s->failed_pc=0x0c085e50u; return 0; }
vf3_matrix_store(s,ram,8,r[15]+r[0]);
goto P_0c085e52;
P_0c085e52: /* original e00c, guest PC 0x0c085e52 */
if(!s->budget--) { s->failed_pc=0x0c085e52u; return 0; }
r[0]=0x0000000cu;
goto P_0c085e54;
P_0c085e54: /* original ff97, guest PC 0x0c085e54 */
if(!s->budget--) { s->failed_pc=0x0c085e54u; return 0; }
vf3_matrix_store(s,ram,9,r[15]+r[0]);
goto P_0c085e56;
P_0c085e56: /* original 6541, guest PC 0x0c085e56 */
if(!s->budget--) { s->failed_pc=0x0c085e56u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[5]=tmp;
goto P_0c085e58;
P_0c085e58: /* original 2558, guest PC 0x0c085e58 */
if(!s->budget--) { s->failed_pc=0x0c085e58u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c085e5a;
P_0c085e5a: /* original 8d02, guest PC 0x0c085e5a */
if(!s->budget--) { s->failed_pc=0x0c085e5au; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,12,6);
if(cond) { goto P_0c085e62; }
goto P_0c085e5e;
P_0c085e5c: /* original fc6c, guest PC 0x0c085e5c */
if(!s->budget--) { s->failed_pc=0x0c085e5cu; return 0; }
vf3_matrix_move(s,12,6);
goto P_0c085e5e;
P_0c085e5e: /* original a090, guest PC 0x0c085e5e */
if(!s->budget--) { s->failed_pc=0x0c085e5eu; return 0; }
goto P_0c085f82;
P_0c085e60: /* original 0009, guest PC 0x0c085e60 */
if(!s->budget--) { s->failed_pc=0x0c085e60u; return 0; }
goto P_0c085e62;
P_0c085e62: /* original c71b, guest PC 0x0c085e62 */
if(!s->budget--) { s->failed_pc=0x0c085e62u; return 0; }
r[0]=0x0c085ed0u;
goto P_0c085e64;
P_0c085e64: /* original f308, guest PC 0x0c085e64 */
if(!s->budget--) { s->failed_pc=0x0c085e64u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c085e66;
P_0c085e66: /* original e018, guest PC 0x0c085e66 */
if(!s->budget--) { s->failed_pc=0x0c085e66u; return 0; }
r[0]=0x00000018u;
goto P_0c085e68;
P_0c085e68: /* original ec14, guest PC 0x0c085e68 */
if(!s->budget--) { s->failed_pc=0x0c085e68u; return 0; }
r[12]=0x00000014u;
goto P_0c085e6a;
P_0c085e6a: /* original ff37, guest PC 0x0c085e6a */
if(!s->budget--) { s->failed_pc=0x0c085e6au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c085e6c;
P_0c085e6c: /* original c719, guest PC 0x0c085e6c */
if(!s->budget--) { s->failed_pc=0x0c085e6cu; return 0; }
r[0]=0x0c085ed4u;
goto P_0c085e6e;
P_0c085e6e: /* original f308, guest PC 0x0c085e6e */
if(!s->budget--) { s->failed_pc=0x0c085e6eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c085e70;
P_0c085e70: /* original e014, guest PC 0x0c085e70 */
if(!s->budget--) { s->failed_pc=0x0c085e70u; return 0; }
r[0]=0x00000014u;
goto P_0c085e72;
P_0c085e72: /* original ff37, guest PC 0x0c085e72 */
if(!s->budget--) { s->failed_pc=0x0c085e72u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c085e74;
P_0c085e74: /* original c718, guest PC 0x0c085e74 */
if(!s->budget--) { s->failed_pc=0x0c085e74u; return 0; }
r[0]=0x0c085ed8u;
goto P_0c085e76;
P_0c085e76: /* original f308, guest PC 0x0c085e76 */
if(!s->budget--) { s->failed_pc=0x0c085e76u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c085e78;
P_0c085e78: /* original e01c, guest PC 0x0c085e78 */
if(!s->budget--) { s->failed_pc=0x0c085e78u; return 0; }
r[0]=0x0000001cu;
goto P_0c085e7a;
P_0c085e7a: /* original bf1b, guest PC 0x0c085e7a */
if(!s->budget--) { s->failed_pc=0x0c085e7au; return 0; }
target=0x0c085cb4u; r[16]=0x0c085e7eu;
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085e7eu) { target=s->pc; goto dispatch; }
goto P_0c085e7e;
P_0c085e7c: /* original ff37, guest PC 0x0c085e7c */
if(!s->budget--) { s->failed_pc=0x0c085e7cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c085e7e;
P_0c085e7e: /* original e21f, guest PC 0x0c085e7e */
if(!s->budget--) { s->failed_pc=0x0c085e7eu; return 0; }
r[2]=0x0000001fu;
goto P_0c085e80;
P_0c085e80: /* original 6403, guest PC 0x0c085e80 */
if(!s->budget--) { s->failed_pc=0x0c085e80u; return 0; }
r[4]=r[0];
goto P_0c085e82;
P_0c085e82: /* original 2429, guest PC 0x0c085e82 */
if(!s->budget--) { s->failed_pc=0x0c085e82u; return 0; }
r[4]&=r[2];
goto P_0c085e84;
P_0c085e84: /* original 445a, guest PC 0x0c085e84 */
if(!s->budget--) { s->failed_pc=0x0c085e84u; return 0; }
r[53]=r[4];
goto P_0c085e86;
P_0c085e86: /* original c711, guest PC 0x0c085e86 */
if(!s->budget--) { s->failed_pc=0x0c085e86u; return 0; }
r[0]=0x0c085eccu;
goto P_0c085e88;
P_0c085e88: /* original f208, guest PC 0x0c085e88 */
if(!s->budget--) { s->failed_pc=0x0c085e88u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c085e8a;
P_0c085e8a: /* original e01c, guest PC 0x0c085e8a */
if(!s->budget--) { s->failed_pc=0x0c085e8au; return 0; }
r[0]=0x0000001cu;
goto P_0c085e8c;
P_0c085e8c: /* original f32d, guest PC 0x0c085e8c */
if(!s->budget--) { s->failed_pc=0x0c085e8cu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c085e8e;
P_0c085e8e: /* original f43c, guest PC 0x0c085e8e */
if(!s->budget--) { s->failed_pc=0x0c085e8eu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c085e90;
P_0c085e90: /* original ff2a, guest PC 0x0c085e90 */
if(!s->budget--) { s->failed_pc=0x0c085e90u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c085e92;
P_0c085e92: /* original f3f6, guest PC 0x0c085e92 */
if(!s->budget--) { s->failed_pc=0x0c085e92u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c085e94;
P_0c085e94: /* original e004, guest PC 0x0c085e94 */
if(!s->budget--) { s->failed_pc=0x0c085e94u; return 0; }
r[0]=0x00000004u;
goto P_0c085e96;
P_0c085e96: /* original f02c, guest PC 0x0c085e96 */
if(!s->budget--) { s->failed_pc=0x0c085e96u; return 0; }
vf3_matrix_move(s,0,2);
goto P_0c085e98;
P_0c085e98: /* original f34e, guest PC 0x0c085e98 */
if(!s->budget--) { s->failed_pc=0x0c085e98u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c085e9a;
P_0c085e9a: /* original ff37, guest PC 0x0c085e9a */
if(!s->budget--) { s->failed_pc=0x0c085e9au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c085e9c;
P_0c085e9c: /* original 7cff, guest PC 0x0c085e9c */
if(!s->budget--) { s->failed_pc=0x0c085e9cu; return 0; }
r[12]+=0xffffffffu;
goto P_0c085e9e;
P_0c085e9e: /* original 4c11, guest PC 0x0c085e9e */
if(!s->budget--) { s->failed_pc=0x0c085e9eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=0)!=0);
goto P_0c085ea0;
P_0c085ea0: /* original 8b6f, guest PC 0x0c085ea0 */
if(!s->budget--) { s->failed_pc=0x0c085ea0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085f82; }
goto P_0c085ea2;
P_0c085ea2: /* original e008, guest PC 0x0c085ea2 */
if(!s->budget--) { s->failed_pc=0x0c085ea2u; return 0; }
r[0]=0x00000008u;
goto P_0c085ea4;
P_0c085ea4: /* original f6f6, guest PC 0x0c085ea4 */
if(!s->budget--) { s->failed_pc=0x0c085ea4u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c085ea6;
P_0c085ea6: /* original e00c, guest PC 0x0c085ea6 */
if(!s->budget--) { s->failed_pc=0x0c085ea6u; return 0; }
r[0]=0x0000000cu;
goto P_0c085ea8;
P_0c085ea8: /* original f5f6, guest PC 0x0c085ea8 */
if(!s->budget--) { s->failed_pc=0x0c085ea8u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c085eaa;
P_0c085eaa: /* original e014, guest PC 0x0c085eaa */
if(!s->budget--) { s->failed_pc=0x0c085eaau; return 0; }
r[0]=0x00000014u;
goto P_0c085eac;
P_0c085eac: /* original f6e1, guest PC 0x0c085eac */
if(!s->budget--) { s->failed_pc=0x0c085eacu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[14],r[18],'-');
goto P_0c085eae;
P_0c085eae: /* original f3f6, guest PC 0x0c085eae */
if(!s->budget--) { s->failed_pc=0x0c085eaeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c085eb0;
P_0c085eb0: /* original f5c1, guest PC 0x0c085eb0 */
if(!s->budget--) { s->failed_pc=0x0c085eb0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[12],r[18],'-');
goto P_0c085eb2;
P_0c085eb2: /* original f46c, guest PC 0x0c085eb2 */
if(!s->budget--) { s->failed_pc=0x0c085eb2u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c085eb4;
P_0c085eb4: /* original f462, guest PC 0x0c085eb4 */
if(!s->budget--) { s->failed_pc=0x0c085eb4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c085eb6;
P_0c085eb6: /* original f05c, guest PC 0x0c085eb6 */
if(!s->budget--) { s->failed_pc=0x0c085eb6u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c085eb8;
P_0c085eb8: /* original f45e, guest PC 0x0c085eb8 */
if(!s->budget--) { s->failed_pc=0x0c085eb8u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[5],fr[4],r[18]);
goto P_0c085eba;
P_0c085eba: /* original f345, guest PC 0x0c085eba */
if(!s->budget--) { s->failed_pc=0x0c085ebau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c085ebc;
P_0c085ebc: /* original 8961, guest PC 0x0c085ebc */
if(!s->budget--) { s->failed_pc=0x0c085ebcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c085f82; }
goto P_0c085ebe;
P_0c085ebe: /* original c707, guest PC 0x0c085ebe */
if(!s->budget--) { s->failed_pc=0x0c085ebeu; return 0; }
r[0]=0x0c085edcu;
goto P_0c085ec0;
P_0c085ec0: /* original f708, guest PC 0x0c085ec0 */
if(!s->budget--) { s->failed_pc=0x0c085ec0u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c085ec2;
P_0c085ec2: /* original f745, guest PC 0x0c085ec2 */
if(!s->budget--) { s->failed_pc=0x0c085ec2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[4]))!=0);
goto P_0c085ec4;
P_0c085ec4: /* original 8b0c, guest PC 0x0c085ec4 */
if(!s->budget--) { s->failed_pc=0x0c085ec4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085ee0; }
goto P_0c085ec6;
P_0c085ec6: /* original a00c, guest PC 0x0c085ec6 */
if(!s->budget--) { s->failed_pc=0x0c085ec6u; return 0; }
fr[4]=0;
goto P_0c085ee2;
P_0c085ec8: /* original f48d, guest PC 0x0c085ec8 */
if(!s->budget--) { s->failed_pc=0x0c085ec8u; return 0; }
fr[4]=0;
return vf3_matrix_family(0x0c085ecau,s,ram);
P_0c085ee0: /* original f47d, guest PC 0x0c085ee0 */
if(!s->budget--) { s->failed_pc=0x0c085ee0u; return 0; }
if(!vf3_fpu_fsrra(fr[4],r[18],&fr[4])) goto unsupported;
goto P_0c085ee2;
P_0c085ee2: /* original e018, guest PC 0x0c085ee2 */
if(!s->budget--) { s->failed_pc=0x0c085ee2u; return 0; }
r[0]=0x00000018u;
goto P_0c085ee4;
P_0c085ee4: /* original f34c, guest PC 0x0c085ee4 */
if(!s->budget--) { s->failed_pc=0x0c085ee4u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c085ee6;
P_0c085ee6: /* original f4f6, guest PC 0x0c085ee6 */
if(!s->budget--) { s->failed_pc=0x0c085ee6u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c085ee8;
P_0c085ee8: /* original e010, guest PC 0x0c085ee8 */
if(!s->budget--) { s->failed_pc=0x0c085ee8u; return 0; }
r[0]=0x00000010u;
goto P_0c085eea;
P_0c085eea: /* original dd54, guest PC 0x0c085eea */
if(!s->budget--) { s->failed_pc=0x0c085eeau; return 0; }
r[13]=read(ram,0x0c08603cu,4);
goto P_0c085eec;
P_0c085eec: /* original 65f3, guest PC 0x0c085eec */
if(!s->budget--) { s->failed_pc=0x0c085eecu; return 0; }
r[5]=r[15];
goto P_0c085eee;
P_0c085eee: /* original f432, guest PC 0x0c085eee */
if(!s->budget--) { s->failed_pc=0x0c085eeeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c085ef0;
P_0c085ef0: /* original f3dc, guest PC 0x0c085ef0 */
if(!s->budget--) { s->failed_pc=0x0c085ef0u; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c085ef2;
P_0c085ef2: /* original 64f3, guest PC 0x0c085ef2 */
if(!s->budget--) { s->failed_pc=0x0c085ef2u; return 0; }
r[4]=r[15];
goto P_0c085ef4;
P_0c085ef4: /* original 7520, guest PC 0x0c085ef4 */
if(!s->budget--) { s->failed_pc=0x0c085ef4u; return 0; }
r[5]+=0x00000020u;
goto P_0c085ef6;
P_0c085ef6: /* original f04c, guest PC 0x0c085ef6 */
if(!s->budget--) { s->failed_pc=0x0c085ef6u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c085ef8;
P_0c085ef8: /* original fc5e, guest PC 0x0c085ef8 */
if(!s->budget--) { s->failed_pc=0x0c085ef8u; return 0; }
fr[12]=vf3_fpu_mac(fr[0],fr[5],fr[12],r[18]);
goto P_0c085efa;
P_0c085efa: /* original f5f6, guest PC 0x0c085efa */
if(!s->budget--) { s->failed_pc=0x0c085efau; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c085efc;
P_0c085efc: /* original fe6e, guest PC 0x0c085efc */
if(!s->budget--) { s->failed_pc=0x0c085efcu; return 0; }
fr[14]=vf3_fpu_mac(fr[0],fr[6],fr[14],r[18]);
goto P_0c085efe;
P_0c085efe: /* original f5d1, guest PC 0x0c085efe */
if(!s->budget--) { s->failed_pc=0x0c085efeu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[13],r[18],'-');
goto P_0c085f00;
P_0c085f00: /* original ffcc, guest PC 0x0c085f00 */
if(!s->budget--) { s->failed_pc=0x0c085f00u; return 0; }
vf3_matrix_move(s,15,12);
goto P_0c085f02;
P_0c085f02: /* original f35e, guest PC 0x0c085f02 */
if(!s->budget--) { s->failed_pc=0x0c085f02u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c085f04;
P_0c085f04: /* original f5cc, guest PC 0x0c085f04 */
if(!s->budget--) { s->failed_pc=0x0c085f04u; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c085f06;
P_0c085f06: /* original fd3c, guest PC 0x0c085f06 */
if(!s->budget--) { s->failed_pc=0x0c085f06u; return 0; }
vf3_matrix_move(s,13,3);
goto P_0c085f08;
P_0c085f08: /* original 4d0b, guest PC 0x0c085f08 */
if(!s->budget--) { s->failed_pc=0x0c085f08u; return 0; }
target=r[13];
r[16]=0x0c085f0cu;
vf3_matrix_move(s,4,14);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085f0cu) { target=s->pc; goto dispatch; }
goto P_0c085f0c;
P_0c085f0a: /* original f4ec, guest PC 0x0c085f0a */
if(!s->budget--) { s->failed_pc=0x0c085f0au; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c085f0c;
P_0c085f0c: /* original f6f8, guest PC 0x0c085f0c */
if(!s->budget--) { s->failed_pc=0x0c085f0cu; return 0; }
vf3_matrix_load(s,ram,6,r[15]);
goto P_0c085f0e;
P_0c085f0e: /* original 6d03, guest PC 0x0c085f0e */
if(!s->budget--) { s->failed_pc=0x0c085f0eu; return 0; }
r[13]=r[0];
goto P_0c085f10;
P_0c085f10: /* original f4dc, guest PC 0x0c085f10 */
if(!s->budget--) { s->failed_pc=0x0c085f10u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c085f12;
P_0c085f12: /* original e004, guest PC 0x0c085f12 */
if(!s->budget--) { s->failed_pc=0x0c085f12u; return 0; }
r[0]=0x00000004u;
goto P_0c085f14;
P_0c085f14: /* original f461, guest PC 0x0c085f14 */
if(!s->budget--) { s->failed_pc=0x0c085f14u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c085f16;
P_0c085f16: /* original f38d, guest PC 0x0c085f16 */
if(!s->budget--) { s->failed_pc=0x0c085f16u; return 0; }
fr[3]=0;
goto P_0c085f18;
P_0c085f18: /* original f435, guest PC 0x0c085f18 */
if(!s->budget--) { s->failed_pc=0x0c085f18u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c085f1a;
P_0c085f1a: /* original 8f11, guest PC 0x0c085f1a */
if(!s->budget--) { s->failed_pc=0x0c085f1au; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,5,r[15]+r[0]);
if(!cond) { goto P_0c085f40; }
goto P_0c085f1e;
P_0c085f1c: /* original f5f6, guest PC 0x0c085f1c */
if(!s->budget--) { s->failed_pc=0x0c085f1cu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c085f1e;
P_0c085f1e: /* original c748, guest PC 0x0c085f1e */
if(!s->budget--) { s->failed_pc=0x0c085f1eu; return 0; }
r[0]=0x0c086040u;
goto P_0c085f20;
P_0c085f20: /* original f28d, guest PC 0x0c085f20 */
if(!s->budget--) { s->failed_pc=0x0c085f20u; return 0; }
fr[2]=0;
goto P_0c085f22;
P_0c085f22: /* original f508, guest PC 0x0c085f22 */
if(!s->budget--) { s->failed_pc=0x0c085f22u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c085f24;
P_0c085f24: /* original f75c, guest PC 0x0c085f24 */
if(!s->budget--) { s->failed_pc=0x0c085f24u; return 0; }
vf3_matrix_move(s,7,5);
goto P_0c085f26;
P_0c085f26: /* original f472, guest PC 0x0c085f26 */
if(!s->budget--) { s->failed_pc=0x0c085f26u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c085f28;
P_0c085f28: /* original f59d, guest PC 0x0c085f28 */
if(!s->budget--) { s->failed_pc=0x0c085f28u; return 0; }
fr[5]=0x3f800000u;
goto P_0c085f2a;
P_0c085f2a: /* original f34c, guest PC 0x0c085f2a */
if(!s->budget--) { s->failed_pc=0x0c085f2au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c085f2c;
P_0c085f2c: /* original f351, guest PC 0x0c085f2c */
if(!s->budget--) { s->failed_pc=0x0c085f2cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c085f2e;
P_0c085f2e: /* original f235, guest PC 0x0c085f2e */
if(!s->budget--) { s->failed_pc=0x0c085f2eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c085f30;
P_0c085f30: /* original 8b25, guest PC 0x0c085f30 */
if(!s->budget--) { s->failed_pc=0x0c085f30u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085f7e; }
goto P_0c085f32;
P_0c085f32: /* original f34c, guest PC 0x0c085f32 */
if(!s->budget--) { s->failed_pc=0x0c085f32u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c085f34;
P_0c085f34: /* original e004, guest PC 0x0c085f34 */
if(!s->budget--) { s->failed_pc=0x0c085f34u; return 0; }
r[0]=0x00000004u;
goto P_0c085f36;
P_0c085f36: /* original f45c, guest PC 0x0c085f36 */
if(!s->budget--) { s->failed_pc=0x0c085f36u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c085f38;
P_0c085f38: /* original f431, guest PC 0x0c085f38 */
if(!s->budget--) { s->failed_pc=0x0c085f38u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c085f3a;
P_0c085f3a: /* original f3f6, guest PC 0x0c085f3a */
if(!s->budget--) { s->failed_pc=0x0c085f3au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c085f3c;
P_0c085f3c: /* original f54c, guest PC 0x0c085f3c */
if(!s->budget--) { s->failed_pc=0x0c085f3cu; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c085f3e;
P_0c085f3e: /* original f532, guest PC 0x0c085f3e */
if(!s->budget--) { s->failed_pc=0x0c085f3eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c085f40;
P_0c085f40: /* original d440, guest PC 0x0c085f40 */
if(!s->budget--) { s->failed_pc=0x0c085f40u; return 0; }
r[4]=read(ram,0x0c086044u,4);
goto P_0c085f42;
P_0c085f42: /* original 6242, guest PC 0x0c085f42 */
if(!s->budget--) { s->failed_pc=0x0c085f42u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c085f44;
P_0c085f44: /* original 3e22, guest PC 0x0c085f44 */
if(!s->budget--) { s->failed_pc=0x0c085f44u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[2])!=0);
goto P_0c085f46;
P_0c085f46: /* original 891c, guest PC 0x0c085f46 */
if(!s->budget--) { s->failed_pc=0x0c085f46u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c085f82; }
goto P_0c085f48;
P_0c085f48: /* original 54e4, guest PC 0x0c085f48 */
if(!s->budget--) { s->failed_pc=0x0c085f48u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c085f4a;
P_0c085f4a: /* original 2448, guest PC 0x0c085f4a */
if(!s->budget--) { s->failed_pc=0x0c085f4au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c085f4c;
P_0c085f4c: /* original 8b02, guest PC 0x0c085f4c */
if(!s->budget--) { s->failed_pc=0x0c085f4cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085f54; }
goto P_0c085f4e;
P_0c085f4e: /* original e401, guest PC 0x0c085f4e */
if(!s->budget--) { s->failed_pc=0x0c085f4eu; return 0; }
r[4]=0x00000001u;
goto P_0c085f50;
P_0c085f50: /* original a002, guest PC 0x0c085f50 */
if(!s->budget--) { s->failed_pc=0x0c085f50u; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c085f58;
P_0c085f52: /* original 1e44, guest PC 0x0c085f52 */
if(!s->budget--) { s->failed_pc=0x0c085f52u; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c085f54;
P_0c085f54: /* original aff4, guest PC 0x0c085f54 */
if(!s->budget--) { s->failed_pc=0x0c085f54u; return 0; }
r[14]+=0x00000014u;
goto P_0c085f40;
P_0c085f56: /* original 7e14, guest PC 0x0c085f56 */
if(!s->budget--) { s->failed_pc=0x0c085f56u; return 0; }
r[14]+=0x00000014u;
goto P_0c085f58;
P_0c085f58: /* original e004, guest PC 0x0c085f58 */
if(!s->budget--) { s->failed_pc=0x0c085f58u; return 0; }
r[0]=0x00000004u;
goto P_0c085f5a;
P_0c085f5a: /* original 63d3, guest PC 0x0c085f5a */
if(!s->budget--) { s->failed_pc=0x0c085f5au; return 0; }
r[3]=r[13];
goto P_0c085f5c;
P_0c085f5c: /* original e5fd, guest PC 0x0c085f5c */
if(!s->budget--) { s->failed_pc=0x0c085f5cu; return 0; }
r[5]=0xfffffffdu;
goto P_0c085f5e;
P_0c085f5e: /* original feea, guest PC 0x0c085f5e */
if(!s->budget--) { s->failed_pc=0x0c085f5eu; return 0; }
vf3_matrix_store(s,ram,14,r[14]);
goto P_0c085f60;
P_0c085f60: /* original fe67, guest PC 0x0c085f60 */
if(!s->budget--) { s->failed_pc=0x0c085f60u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c085f62;
P_0c085f62: /* original e008, guest PC 0x0c085f62 */
if(!s->budget--) { s->failed_pc=0x0c085f62u; return 0; }
r[0]=0x00000008u;
goto P_0c085f64;
P_0c085f64: /* original f3fc, guest PC 0x0c085f64 */
if(!s->budget--) { s->failed_pc=0x0c085f64u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c085f66;
P_0c085f66: /* original f34d, guest PC 0x0c085f66 */
if(!s->budget--) { s->failed_pc=0x0c085f66u; return 0; }
fr[3]^=0x80000000u;
goto P_0c085f68;
P_0c085f68: /* original fe37, guest PC 0x0c085f68 */
if(!s->budget--) { s->failed_pc=0x0c085f68u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c085f6a;
P_0c085f6a: /* original e00c, guest PC 0x0c085f6a */
if(!s->budget--) { s->failed_pc=0x0c085f6au; return 0; }
r[0]=0x0000000cu;
goto P_0c085f6c;
P_0c085f6c: /* original fe57, guest PC 0x0c085f6c */
if(!s->budget--) { s->failed_pc=0x0c085f6cu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c085f6e;
P_0c085f6e: /* original 54e4, guest PC 0x0c085f6e */
if(!s->budget--) { s->failed_pc=0x0c085f6eu; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c085f70;
P_0c085f70: /* original 2459, guest PC 0x0c085f70 */
if(!s->budget--) { s->failed_pc=0x0c085f70u; return 0; }
r[4]&=r[5];
goto P_0c085f72;
P_0c085f72: /* original 955e, guest PC 0x0c085f72 */
if(!s->budget--) { s->failed_pc=0x0c085f72u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086032u,2);
goto P_0c085f74;
P_0c085f74: /* original 2358, guest PC 0x0c085f74 */
if(!s->budget--) { s->failed_pc=0x0c085f74u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c085f76;
P_0c085f76: /* original 8901, guest PC 0x0c085f76 */
if(!s->budget--) { s->failed_pc=0x0c085f76u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c085f7c; }
goto P_0c085f78;
P_0c085f78: /* original e502, guest PC 0x0c085f78 */
if(!s->budget--) { s->failed_pc=0x0c085f78u; return 0; }
r[5]=0x00000002u;
goto P_0c085f7a;
P_0c085f7a: /* original 245b, guest PC 0x0c085f7a */
if(!s->budget--) { s->failed_pc=0x0c085f7au; return 0; }
r[4]|=r[5];
goto P_0c085f7c;
P_0c085f7c: /* original 1e44, guest PC 0x0c085f7c */
if(!s->budget--) { s->failed_pc=0x0c085f7cu; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c085f7e;
P_0c085f7e: /* original af8d, guest PC 0x0c085f7e */
if(!s->budget--) { s->failed_pc=0x0c085f7eu; return 0; }
vf3_matrix_move(s,12,15);
goto P_0c085e9c;
P_0c085f80: /* original fcfc, guest PC 0x0c085f80 */
if(!s->budget--) { s->failed_pc=0x0c085f80u; return 0; }
vf3_matrix_move(s,12,15);
goto P_0c085f82;
P_0c085f82: /* original 7f2c, guest PC 0x0c085f82 */
if(!s->budget--) { s->failed_pc=0x0c085f82u; return 0; }
r[15]+=0x0000002cu;
goto P_0c085f84;
P_0c085f84: /* original 4f26, guest PC 0x0c085f84 */
if(!s->budget--) { s->failed_pc=0x0c085f84u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c085f86;
P_0c085f86: /* original fcf9, guest PC 0x0c085f86 */
if(!s->budget--) { s->failed_pc=0x0c085f86u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085f88;
P_0c085f88: /* original fdf9, guest PC 0x0c085f88 */
if(!s->budget--) { s->failed_pc=0x0c085f88u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085f8a;
P_0c085f8a: /* original fef9, guest PC 0x0c085f8a */
if(!s->budget--) { s->failed_pc=0x0c085f8au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085f8c;
P_0c085f8c: /* original fff9, guest PC 0x0c085f8c */
if(!s->budget--) { s->failed_pc=0x0c085f8cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085f8e;
P_0c085f8e: /* original 6cf6, guest PC 0x0c085f8e */
if(!s->budget--) { s->failed_pc=0x0c085f8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c085f90;
P_0c085f90: /* original 6df6, guest PC 0x0c085f90 */
if(!s->budget--) { s->failed_pc=0x0c085f90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c085f92;
P_0c085f92: /* original 000b, guest PC 0x0c085f92 */
if(!s->budget--) { s->failed_pc=0x0c085f92u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c085f94: /* original 6ef6, guest PC 0x0c085f94 */
if(!s->budget--) { s->failed_pc=0x0c085f94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c085f96;
P_0c085f96: /* original 2fe6, guest PC 0x0c085f96 */
if(!s->budget--) { s->failed_pc=0x0c085f96u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085f98;
P_0c085f98: /* original 6e53, guest PC 0x0c085f98 */
if(!s->budget--) { s->failed_pc=0x0c085f98u; return 0; }
r[14]=r[5];
goto P_0c085f9a;
P_0c085f9a: /* original 2fd6, guest PC 0x0c085f9a */
if(!s->budget--) { s->failed_pc=0x0c085f9au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085f9c;
P_0c085f9c: /* original 6d43, guest PC 0x0c085f9c */
if(!s->budget--) { s->failed_pc=0x0c085f9cu; return 0; }
r[13]=r[4];
goto P_0c085f9e;
P_0c085f9e: /* original 2fc6, guest PC 0x0c085f9e */
if(!s->budget--) { s->failed_pc=0x0c085f9eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085fa0;
P_0c085fa0: /* original 6c63, guest PC 0x0c085fa0 */
if(!s->budget--) { s->failed_pc=0x0c085fa0u; return 0; }
r[12]=r[6];
goto P_0c085fa2;
P_0c085fa2: /* original 2fb6, guest PC 0x0c085fa2 */
if(!s->budget--) { s->failed_pc=0x0c085fa2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085fa4;
P_0c085fa4: /* original 6b73, guest PC 0x0c085fa4 */
if(!s->budget--) { s->failed_pc=0x0c085fa4u; return 0; }
r[11]=r[7];
goto P_0c085fa6;
P_0c085fa6: /* original fffb, guest PC 0x0c085fa6 */
if(!s->budget--) { s->failed_pc=0x0c085fa6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c085fa8;
P_0c085fa8: /* original 9044, guest PC 0x0c085fa8 */
if(!s->budget--) { s->failed_pc=0x0c085fa8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086034u,2);
goto P_0c085faa;
P_0c085faa: /* original 4f22, guest PC 0x0c085faa */
if(!s->budget--) { s->failed_pc=0x0c085faau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c085fac;
P_0c085fac: /* original f7d6, guest PC 0x0c085fac */
if(!s->budget--) { s->failed_pc=0x0c085facu; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c085fae;
P_0c085fae: /* original 7004, guest PC 0x0c085fae */
if(!s->budget--) { s->failed_pc=0x0c085faeu; return 0; }
r[0]+=0x00000004u;
goto P_0c085fb0;
P_0c085fb0: /* original f8d6, guest PC 0x0c085fb0 */
if(!s->budget--) { s->failed_pc=0x0c085fb0u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c085fb2;
P_0c085fb2: /* original 7004, guest PC 0x0c085fb2 */
if(!s->budget--) { s->failed_pc=0x0c085fb2u; return 0; }
r[0]+=0x00000004u;
goto P_0c085fb4;
P_0c085fb4: /* original f9d6, guest PC 0x0c085fb4 */
if(!s->budget--) { s->failed_pc=0x0c085fb4u; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c085fb6;
P_0c085fb6: /* original c724, guest PC 0x0c085fb6 */
if(!s->budget--) { s->failed_pc=0x0c085fb6u; return 0; }
r[0]=0x0c086048u;
goto P_0c085fb8;
P_0c085fb8: /* original ff08, guest PC 0x0c085fb8 */
if(!s->budget--) { s->failed_pc=0x0c085fb8u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c085fba;
P_0c085fba: /* original e004, guest PC 0x0c085fba */
if(!s->budget--) { s->failed_pc=0x0c085fbau; return 0; }
r[0]=0x00000004u;
goto P_0c085fbc;
P_0c085fbc: /* original f4e6, guest PC 0x0c085fbc */
if(!s->budget--) { s->failed_pc=0x0c085fbcu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c085fbe;
P_0c085fbe: /* original e008, guest PC 0x0c085fbe */
if(!s->budget--) { s->failed_pc=0x0c085fbeu; return 0; }
r[0]=0x00000008u;
goto P_0c085fc0;
P_0c085fc0: /* original f5e6, guest PC 0x0c085fc0 */
if(!s->budget--) { s->failed_pc=0x0c085fc0u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c085fc2;
P_0c085fc2: /* original e00c, guest PC 0x0c085fc2 */
if(!s->budget--) { s->failed_pc=0x0c085fc2u; return 0; }
r[0]=0x0000000cu;
goto P_0c085fc4;
P_0c085fc4: /* original f6e6, guest PC 0x0c085fc4 */
if(!s->budget--) { s->failed_pc=0x0c085fc4u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c085fc6;
P_0c085fc6: /* original f8f0, guest PC 0x0c085fc6 */
if(!s->budget--) { s->failed_pc=0x0c085fc6u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[15],r[18],'+');
goto P_0c085fc8;
P_0c085fc8: /* original e004, guest PC 0x0c085fc8 */
if(!s->budget--) { s->failed_pc=0x0c085fc8u; return 0; }
r[0]=0x00000004u;
goto P_0c085fca;
P_0c085fca: /* original f94d, guest PC 0x0c085fca */
if(!s->budget--) { s->failed_pc=0x0c085fcau; return 0; }
fr[9]^=0x80000000u;
goto P_0c085fcc;
P_0c085fcc: /* original fe77, guest PC 0x0c085fcc */
if(!s->budget--) { s->failed_pc=0x0c085fccu; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c085fce;
P_0c085fce: /* original e008, guest PC 0x0c085fce */
if(!s->budget--) { s->failed_pc=0x0c085fceu; return 0; }
r[0]=0x00000008u;
goto P_0c085fd0;
P_0c085fd0: /* original fe87, guest PC 0x0c085fd0 */
if(!s->budget--) { s->failed_pc=0x0c085fd0u; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c085fd2;
P_0c085fd2: /* original e00c, guest PC 0x0c085fd2 */
if(!s->budget--) { s->failed_pc=0x0c085fd2u; return 0; }
r[0]=0x0000000cu;
goto P_0c085fd4;
P_0c085fd4: /* original fe97, guest PC 0x0c085fd4 */
if(!s->budget--) { s->failed_pc=0x0c085fd4u; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c085fd6;
P_0c085fd6: /* original 65c3, guest PC 0x0c085fd6 */
if(!s->budget--) { s->failed_pc=0x0c085fd6u; return 0; }
r[5]=r[12];
goto P_0c085fd8;
P_0c085fd8: /* original bf2b, guest PC 0x0c085fd8 */
if(!s->budget--) { s->failed_pc=0x0c085fd8u; return 0; }
target=0x0c085e32u; r[16]=0x0c085fdcu;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c085fdcu) { target=s->pc; goto dispatch; }
goto P_0c085fdc;
P_0c085fda: /* original 64b3, guest PC 0x0c085fda */
if(!s->budget--) { s->failed_pc=0x0c085fdau; return 0; }
r[4]=r[11];
goto P_0c085fdc;
P_0c085fdc: /* original 902b, guest PC 0x0c085fdc */
if(!s->budget--) { s->failed_pc=0x0c085fdcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086036u,2);
goto P_0c085fde;
P_0c085fde: /* original 7e10, guest PC 0x0c085fde */
if(!s->budget--) { s->failed_pc=0x0c085fdeu; return 0; }
r[14]+=0x00000010u;
goto P_0c085fe0;
P_0c085fe0: /* original 65c3, guest PC 0x0c085fe0 */
if(!s->budget--) { s->failed_pc=0x0c085fe0u; return 0; }
r[5]=r[12];
goto P_0c085fe2;
P_0c085fe2: /* original f7d6, guest PC 0x0c085fe2 */
if(!s->budget--) { s->failed_pc=0x0c085fe2u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c085fe4;
P_0c085fe4: /* original 7004, guest PC 0x0c085fe4 */
if(!s->budget--) { s->failed_pc=0x0c085fe4u; return 0; }
r[0]+=0x00000004u;
goto P_0c085fe6;
P_0c085fe6: /* original f8d6, guest PC 0x0c085fe6 */
if(!s->budget--) { s->failed_pc=0x0c085fe6u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c085fe8;
P_0c085fe8: /* original 7004, guest PC 0x0c085fe8 */
if(!s->budget--) { s->failed_pc=0x0c085fe8u; return 0; }
r[0]+=0x00000004u;
goto P_0c085fea;
P_0c085fea: /* original f9d6, guest PC 0x0c085fea */
if(!s->budget--) { s->failed_pc=0x0c085feau; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c085fec;
P_0c085fec: /* original e004, guest PC 0x0c085fec */
if(!s->budget--) { s->failed_pc=0x0c085fecu; return 0; }
r[0]=0x00000004u;
goto P_0c085fee;
P_0c085fee: /* original f4e6, guest PC 0x0c085fee */
if(!s->budget--) { s->failed_pc=0x0c085feeu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c085ff0;
P_0c085ff0: /* original e008, guest PC 0x0c085ff0 */
if(!s->budget--) { s->failed_pc=0x0c085ff0u; return 0; }
r[0]=0x00000008u;
goto P_0c085ff2;
P_0c085ff2: /* original f5e6, guest PC 0x0c085ff2 */
if(!s->budget--) { s->failed_pc=0x0c085ff2u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c085ff4;
P_0c085ff4: /* original e00c, guest PC 0x0c085ff4 */
if(!s->budget--) { s->failed_pc=0x0c085ff4u; return 0; }
r[0]=0x0000000cu;
goto P_0c085ff6;
P_0c085ff6: /* original f6e6, guest PC 0x0c085ff6 */
if(!s->budget--) { s->failed_pc=0x0c085ff6u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c085ff8;
P_0c085ff8: /* original f8f0, guest PC 0x0c085ff8 */
if(!s->budget--) { s->failed_pc=0x0c085ff8u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[15],r[18],'+');
goto P_0c085ffa;
P_0c085ffa: /* original e004, guest PC 0x0c085ffa */
if(!s->budget--) { s->failed_pc=0x0c085ffau; return 0; }
r[0]=0x00000004u;
goto P_0c085ffc;
P_0c085ffc: /* original f94d, guest PC 0x0c085ffc */
if(!s->budget--) { s->failed_pc=0x0c085ffcu; return 0; }
fr[9]^=0x80000000u;
goto P_0c085ffe;
P_0c085ffe: /* original fe77, guest PC 0x0c085ffe */
if(!s->budget--) { s->failed_pc=0x0c085ffeu; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c086000;
P_0c086000: /* original e008, guest PC 0x0c086000 */
if(!s->budget--) { s->failed_pc=0x0c086000u; return 0; }
r[0]=0x00000008u;
goto P_0c086002;
P_0c086002: /* original fe87, guest PC 0x0c086002 */
if(!s->budget--) { s->failed_pc=0x0c086002u; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c086004;
P_0c086004: /* original e00c, guest PC 0x0c086004 */
if(!s->budget--) { s->failed_pc=0x0c086004u; return 0; }
r[0]=0x0000000cu;
goto P_0c086006;
P_0c086006: /* original fe97, guest PC 0x0c086006 */
if(!s->budget--) { s->failed_pc=0x0c086006u; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c086008;
P_0c086008: /* original bf13, guest PC 0x0c086008 */
if(!s->budget--) { s->failed_pc=0x0c086008u; return 0; }
target=0x0c085e32u; r[16]=0x0c08600cu;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08600cu) { target=s->pc; goto dispatch; }
goto P_0c08600c;
P_0c08600a: /* original 64b3, guest PC 0x0c08600a */
if(!s->budget--) { s->failed_pc=0x0c08600au; return 0; }
r[4]=r[11];
goto P_0c08600c;
P_0c08600c: /* original 9014, guest PC 0x0c08600c */
if(!s->budget--) { s->failed_pc=0x0c08600cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086038u,2);
goto P_0c08600e;
P_0c08600e: /* original 64b3, guest PC 0x0c08600e */
if(!s->budget--) { s->failed_pc=0x0c08600eu; return 0; }
r[4]=r[11];
goto P_0c086010;
P_0c086010: /* original 4f26, guest PC 0x0c086010 */
if(!s->budget--) { s->failed_pc=0x0c086010u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c086012;
P_0c086012: /* original f4d6, guest PC 0x0c086012 */
if(!s->budget--) { s->failed_pc=0x0c086012u; return 0; }
vf3_matrix_load(s,ram,4,r[13]+r[0]);
goto P_0c086014;
P_0c086014: /* original 7004, guest PC 0x0c086014 */
if(!s->budget--) { s->failed_pc=0x0c086014u; return 0; }
r[0]+=0x00000004u;
goto P_0c086016;
P_0c086016: /* original f5d6, guest PC 0x0c086016 */
if(!s->budget--) { s->failed_pc=0x0c086016u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c086018;
P_0c086018: /* original 65c3, guest PC 0x0c086018 */
if(!s->budget--) { s->failed_pc=0x0c086018u; return 0; }
r[5]=r[12];
goto P_0c08601a;
P_0c08601a: /* original 7004, guest PC 0x0c08601a */
if(!s->budget--) { s->failed_pc=0x0c08601au; return 0; }
r[0]+=0x00000004u;
goto P_0c08601c;
P_0c08601c: /* original f5f0, guest PC 0x0c08601c */
if(!s->budget--) { s->failed_pc=0x0c08601cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'+');
goto P_0c08601e;
P_0c08601e: /* original fff9, guest PC 0x0c08601e */
if(!s->budget--) { s->failed_pc=0x0c08601eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086020;
P_0c086020: /* original f6d6, guest PC 0x0c086020 */
if(!s->budget--) { s->failed_pc=0x0c086020u; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c086022;
P_0c086022: /* original 7e10, guest PC 0x0c086022 */
if(!s->budget--) { s->failed_pc=0x0c086022u; return 0; }
r[14]+=0x00000010u;
goto P_0c086024;
P_0c086024: /* original 6bf6, guest PC 0x0c086024 */
if(!s->budget--) { s->failed_pc=0x0c086024u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c086026;
P_0c086026: /* original 66e3, guest PC 0x0c086026 */
if(!s->budget--) { s->failed_pc=0x0c086026u; return 0; }
r[6]=r[14];
goto P_0c086028;
P_0c086028: /* original f64d, guest PC 0x0c086028 */
if(!s->budget--) { s->failed_pc=0x0c086028u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08602a;
P_0c08602a: /* original 6cf6, guest PC 0x0c08602a */
if(!s->budget--) { s->failed_pc=0x0c08602au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08602c;
P_0c08602c: /* original 6df6, guest PC 0x0c08602c */
if(!s->budget--) { s->failed_pc=0x0c08602cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08602e;
P_0c08602e: /* original ae55, guest PC 0x0c08602e */
if(!s->budget--) { s->failed_pc=0x0c08602eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c085cdc;
P_0c086030: /* original 6ef6, guest PC 0x0c086030 */
if(!s->budget--) { s->failed_pc=0x0c086030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c086032u,s,ram);
P_0c08604c: /* original 2fe6, guest PC 0x0c08604c */
if(!s->budget--) { s->failed_pc=0x0c08604cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08604e;
P_0c08604e: /* original 6e43, guest PC 0x0c08604e */
if(!s->budget--) { s->failed_pc=0x0c08604eu; return 0; }
r[14]=r[4];
goto P_0c086050;
P_0c086050: /* original 2fd6, guest PC 0x0c086050 */
if(!s->budget--) { s->failed_pc=0x0c086050u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086052;
P_0c086052: /* original 67e3, guest PC 0x0c086052 */
if(!s->budget--) { s->failed_pc=0x0c086052u; return 0; }
r[7]=r[14];
goto P_0c086054;
P_0c086054: /* original 2fc6, guest PC 0x0c086054 */
if(!s->budget--) { s->failed_pc=0x0c086054u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086056;
P_0c086056: /* original 9c7e, guest PC 0x0c086056 */
if(!s->budget--) { s->failed_pc=0x0c086056u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086156u,2);
goto P_0c086058;
P_0c086058: /* original 53e5, guest PC 0x0c086058 */
if(!s->budget--) { s->failed_pc=0x0c086058u; return 0; }
r[3]=read(ram,r[14]+20,4);
goto P_0c08605a;
P_0c08605a: /* original 4f22, guest PC 0x0c08605a */
if(!s->budget--) { s->failed_pc=0x0c08605au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08605c;
P_0c08605c: /* original d23f, guest PC 0x0c08605c */
if(!s->budget--) { s->failed_pc=0x0c08605cu; return 0; }
r[2]=read(ram,0x0c08615cu,4);
goto P_0c08605e;
P_0c08605e: /* original 3cec, guest PC 0x0c08605e */
if(!s->budget--) { s->failed_pc=0x0c08605eu; return 0; }
r[12]+=r[14];
goto P_0c086060;
P_0c086060: /* original 9d78, guest PC 0x0c086060 */
if(!s->budget--) { s->failed_pc=0x0c086060u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086154u,2);
goto P_0c086062;
P_0c086062: /* original 66c3, guest PC 0x0c086062 */
if(!s->budget--) { s->failed_pc=0x0c086062u; return 0; }
r[6]=r[12];
goto P_0c086064;
P_0c086064: /* original 2232, guest PC 0x0c086064 */
if(!s->budget--) { s->failed_pc=0x0c086064u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c086066;
P_0c086066: /* original d13e, guest PC 0x0c086066 */
if(!s->budget--) { s->failed_pc=0x0c086066u; return 0; }
r[1]=read(ram,0x0c086160u,4);
goto P_0c086068;
P_0c086068: /* original 3dec, guest PC 0x0c086068 */
if(!s->budget--) { s->failed_pc=0x0c086068u; return 0; }
r[13]+=r[14];
goto P_0c08606a;
P_0c08606a: /* original 6412, guest PC 0x0c08606a */
if(!s->budget--) { s->failed_pc=0x0c08606au; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c08606c;
P_0c08606c: /* original bf93, guest PC 0x0c08606c */
if(!s->budget--) { s->failed_pc=0x0c08606cu; return 0; }
target=0x0c085f96u; r[16]=0x0c086070u;
r[5]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c086070u) { target=s->pc; goto dispatch; }
goto P_0c086070;
P_0c08606e: /* original 65d3, guest PC 0x0c08606e */
if(!s->budget--) { s->failed_pc=0x0c08606eu; return 0; }
r[5]=r[13];
goto P_0c086070;
P_0c086070: /* original 4f26, guest PC 0x0c086070 */
if(!s->budget--) { s->failed_pc=0x0c086070u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c086072;
P_0c086072: /* original 66c3, guest PC 0x0c086072 */
if(!s->budget--) { s->failed_pc=0x0c086072u; return 0; }
r[6]=r[12];
goto P_0c086074;
P_0c086074: /* original d23b, guest PC 0x0c086074 */
if(!s->budget--) { s->failed_pc=0x0c086074u; return 0; }
r[2]=read(ram,0x0c086164u,4);
goto P_0c086076;
P_0c086076: /* original 7d30, guest PC 0x0c086076 */
if(!s->budget--) { s->failed_pc=0x0c086076u; return 0; }
r[13]+=0x00000030u;
goto P_0c086078;
P_0c086078: /* original 67e3, guest PC 0x0c086078 */
if(!s->budget--) { s->failed_pc=0x0c086078u; return 0; }
r[7]=r[14];
goto P_0c08607a;
P_0c08607a: /* original 6cf6, guest PC 0x0c08607a */
if(!s->budget--) { s->failed_pc=0x0c08607au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08607c;
P_0c08607c: /* original 65d3, guest PC 0x0c08607c */
if(!s->budget--) { s->failed_pc=0x0c08607cu; return 0; }
r[5]=r[13];
goto P_0c08607e;
P_0c08607e: /* original 6422, guest PC 0x0c08607e */
if(!s->budget--) { s->failed_pc=0x0c08607eu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c086080;
P_0c086080: /* original 6df6, guest PC 0x0c086080 */
if(!s->budget--) { s->failed_pc=0x0c086080u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c086082;
P_0c086082: /* original af88, guest PC 0x0c086082 */
if(!s->budget--) { s->failed_pc=0x0c086082u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c085f96;
P_0c086084: /* original 6ef6, guest PC 0x0c086084 */
if(!s->budget--) { s->failed_pc=0x0c086084u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c086086;
P_0c086086: /* original 9566, guest PC 0x0c086086 */
if(!s->budget--) { s->failed_pc=0x0c086086u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086156u,2);
goto P_0c086088;
P_0c086088: /* original e00c, guest PC 0x0c086088 */
if(!s->budget--) { s->failed_pc=0x0c086088u; return 0; }
r[0]=0x0000000cu;
goto P_0c08608a;
P_0c08608a: /* original 5345, guest PC 0x0c08608a */
if(!s->budget--) { s->failed_pc=0x0c08608au; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c08608c;
P_0c08608c: /* original d633, guest PC 0x0c08608c */
if(!s->budget--) { s->failed_pc=0x0c08608cu; return 0; }
r[6]=read(ram,0x0c08615cu,4);
goto P_0c08608e;
P_0c08608e: /* original 354c, guest PC 0x0c08608e */
if(!s->budget--) { s->failed_pc=0x0c08608eu; return 0; }
r[5]+=r[4];
goto P_0c086090;
P_0c086090: /* original f646, guest PC 0x0c086090 */
if(!s->budget--) { s->failed_pc=0x0c086090u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c086092;
P_0c086092: /* original a011, guest PC 0x0c086092 */
if(!s->budget--) { s->failed_pc=0x0c086092u; return 0; }
write(ram,r[6],r[3],4);
goto P_0c0860b8;
P_0c086094: /* original 2632, guest PC 0x0c086094 */
if(!s->budget--) { s->failed_pc=0x0c086094u; return 0; }
write(ram,r[6],r[3],4);
goto P_0c086096;
P_0c086096: /* original 5454, guest PC 0x0c086096 */
if(!s->budget--) { s->failed_pc=0x0c086096u; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c086098;
P_0c086098: /* original e701, guest PC 0x0c086098 */
if(!s->budget--) { s->failed_pc=0x0c086098u; return 0; }
r[7]=0x00000001u;
goto P_0c08609a;
P_0c08609a: /* original 6343, guest PC 0x0c08609a */
if(!s->budget--) { s->failed_pc=0x0c08609au; return 0; }
r[3]=r[4];
goto P_0c08609c;
P_0c08609c: /* original 2378, guest PC 0x0c08609c */
if(!s->budget--) { s->failed_pc=0x0c08609cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c08609e;
P_0c08609e: /* original 890a, guest PC 0x0c08609e */
if(!s->budget--) { s->failed_pc=0x0c08609eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0860b6; }
goto P_0c0860a0;
P_0c0860a0: /* original f456, guest PC 0x0c0860a0 */
if(!s->budget--) { s->failed_pc=0x0c0860a0u; return 0; }
vf3_matrix_load(s,ram,4,r[5]+r[0]);
goto P_0c0860a2;
P_0c0860a2: /* original f38d, guest PC 0x0c0860a2 */
if(!s->budget--) { s->failed_pc=0x0c0860a2u; return 0; }
fr[3]=0;
goto P_0c0860a4;
P_0c0860a4: /* original f461, guest PC 0x0c0860a4 */
if(!s->budget--) { s->failed_pc=0x0c0860a4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c0860a6;
P_0c0860a6: /* original f435, guest PC 0x0c0860a6 */
if(!s->budget--) { s->failed_pc=0x0c0860a6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0860a8;
P_0c0860a8: /* original 8903, guest PC 0x0c0860a8 */
if(!s->budget--) { s->failed_pc=0x0c0860a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0860b2; }
goto P_0c0860aa;
P_0c0860aa: /* original f58d, guest PC 0x0c0860aa */
if(!s->budget--) { s->failed_pc=0x0c0860aau; return 0; }
fr[5]=0;
goto P_0c0860ac;
P_0c0860ac: /* original e7fc, guest PC 0x0c0860ac */
if(!s->budget--) { s->failed_pc=0x0c0860acu; return 0; }
r[7]=0xfffffffcu;
goto P_0c0860ae;
P_0c0860ae: /* original f45c, guest PC 0x0c0860ae */
if(!s->budget--) { s->failed_pc=0x0c0860aeu; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0860b0;
P_0c0860b0: /* original 2479, guest PC 0x0c0860b0 */
if(!s->budget--) { s->failed_pc=0x0c0860b0u; return 0; }
r[4]&=r[7];
goto P_0c0860b2;
P_0c0860b2: /* original 1544, guest PC 0x0c0860b2 */
if(!s->budget--) { s->failed_pc=0x0c0860b2u; return 0; }
write(ram,r[5]+16,r[4],4);
goto P_0c0860b4;
P_0c0860b4: /* original f547, guest PC 0x0c0860b4 */
if(!s->budget--) { s->failed_pc=0x0c0860b4u; return 0; }
vf3_matrix_store(s,ram,4,r[5]+r[0]);
goto P_0c0860b6;
P_0c0860b6: /* original 7514, guest PC 0x0c0860b6 */
if(!s->budget--) { s->failed_pc=0x0c0860b6u; return 0; }
r[5]+=0x00000014u;
goto P_0c0860b8;
P_0c0860b8: /* original 6362, guest PC 0x0c0860b8 */
if(!s->budget--) { s->failed_pc=0x0c0860b8u; return 0; }
tmp=read(ram,r[6],4);
r[3]=tmp;
goto P_0c0860ba;
P_0c0860ba: /* original 3532, guest PC 0x0c0860ba */
if(!s->budget--) { s->failed_pc=0x0c0860bau; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[3])!=0);
goto P_0c0860bc;
P_0c0860bc: /* original 8beb, guest PC 0x0c0860bc */
if(!s->budget--) { s->failed_pc=0x0c0860bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086096; }
goto P_0c0860be;
P_0c0860be: /* original 000b, guest PC 0x0c0860be */
if(!s->budget--) { s->failed_pc=0x0c0860beu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0860c0: /* original 0009, guest PC 0x0c0860c0 */
if(!s->budget--) { s->failed_pc=0x0c0860c0u; return 0; }
return vf3_matrix_family(0x0c0860c2u,s,ram);
P_0c08612c: /* original 4f22, guest PC 0x0c08612c */
if(!s->budget--) { s->failed_pc=0x0c08612cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08612e;
P_0c08612e: /* original 6212, guest PC 0x0c08612e */
if(!s->budget--) { s->failed_pc=0x0c08612eu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c086130;
P_0c086130: /* original d30f, guest PC 0x0c086130 */
if(!s->budget--) { s->failed_pc=0x0c086130u; return 0; }
r[3]=read(ram,0x0c086170u,4);
goto P_0c086132;
P_0c086132: /* original 2238, guest PC 0x0c086132 */
if(!s->budget--) { s->failed_pc=0x0c086132u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c086134;
P_0c086134: /* original 8b0b, guest PC 0x0c086134 */
if(!s->budget--) { s->failed_pc=0x0c086134u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08614e; }
goto P_0c086136;
P_0c086136: /* original 6e43, guest PC 0x0c086136 */
if(!s->budget--) { s->failed_pc=0x0c086136u; return 0; }
r[14]=r[4];
goto P_0c086138;
P_0c086138: /* original 64e1, guest PC 0x0c086138 */
if(!s->budget--) { s->failed_pc=0x0c086138u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[4]=tmp;
goto P_0c08613a;
P_0c08613a: /* original 2448, guest PC 0x0c08613a */
if(!s->budget--) { s->failed_pc=0x0c08613au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08613c;
P_0c08613c: /* original 8901, guest PC 0x0c08613c */
if(!s->budget--) { s->failed_pc=0x0c08613cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086142; }
goto P_0c08613e;
P_0c08613e: /* original 74ff, guest PC 0x0c08613e */
if(!s->budget--) { s->failed_pc=0x0c08613eu; return 0; }
r[4]+=0xffffffffu;
goto P_0c086140;
P_0c086140: /* original 2e41, guest PC 0x0c086140 */
if(!s->budget--) { s->failed_pc=0x0c086140u; return 0; }
write(ram,r[14],r[4],2);
goto P_0c086142;
P_0c086142: /* original bdc6, guest PC 0x0c086142 */
if(!s->budget--) { s->failed_pc=0x0c086142u; return 0; }
target=0x0c085cd2u; r[16]=0x0c086146u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c086146u) { target=s->pc; goto dispatch; }
goto P_0c086146;
P_0c086144: /* original 64e3, guest PC 0x0c086144 */
if(!s->budget--) { s->failed_pc=0x0c086144u; return 0; }
r[4]=r[14];
goto P_0c086146;
P_0c086146: /* original bf81, guest PC 0x0c086146 */
if(!s->budget--) { s->failed_pc=0x0c086146u; return 0; }
target=0x0c08604cu; r[16]=0x0c08614au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08614au) { target=s->pc; goto dispatch; }
goto P_0c08614a;
P_0c086148: /* original 64e3, guest PC 0x0c086148 */
if(!s->budget--) { s->failed_pc=0x0c086148u; return 0; }
r[4]=r[14];
goto P_0c08614a;
P_0c08614a: /* original bf9c, guest PC 0x0c08614a */
if(!s->budget--) { s->failed_pc=0x0c08614au; return 0; }
target=0x0c086086u; r[16]=0x0c08614eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c08614eu) { target=s->pc; goto dispatch; }
goto P_0c08614e;
P_0c08614c: /* original 64e3, guest PC 0x0c08614c */
if(!s->budget--) { s->failed_pc=0x0c08614cu; return 0; }
r[4]=r[14];
goto P_0c08614e;
P_0c08614e: /* original 4f26, guest PC 0x0c08614e */
if(!s->budget--) { s->failed_pc=0x0c08614eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c086150;
P_0c086150: /* original 000b, guest PC 0x0c086150 */
if(!s->budget--) { s->failed_pc=0x0c086150u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c086152: /* original 6ef6, guest PC 0x0c086152 */
if(!s->budget--) { s->failed_pc=0x0c086152u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c086154u,s,ram);
P_0c087190: /* original 4f22, guest PC 0x0c087190 */
if(!s->budget--) { s->failed_pc=0x0c087190u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c087192;
P_0c087192: /* original 6212, guest PC 0x0c087192 */
if(!s->budget--) { s->failed_pc=0x0c087192u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c087194;
P_0c087194: /* original d33b, guest PC 0x0c087194 */
if(!s->budget--) { s->failed_pc=0x0c087194u; return 0; }
r[3]=read(ram,0x0c087284u,4);
goto P_0c087196;
P_0c087196: /* original 2238, guest PC 0x0c087196 */
if(!s->budget--) { s->failed_pc=0x0c087196u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c087198;
P_0c087198: /* original 8b22, guest PC 0x0c087198 */
if(!s->budget--) { s->failed_pc=0x0c087198u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0871e0; }
goto P_0c08719a;
P_0c08719a: /* original 9e70, guest PC 0x0c08719a */
if(!s->budget--) { s->failed_pc=0x0c08719au; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08727eu,2);
goto P_0c08719c;
P_0c08719c: /* original e52c, guest PC 0x0c08719c */
if(!s->budget--) { s->failed_pc=0x0c08719cu; return 0; }
r[5]=0x0000002cu;
goto P_0c08719e;
P_0c08719e: /* original d33b, guest PC 0x0c08719e */
if(!s->budget--) { s->failed_pc=0x0c08719eu; return 0; }
r[3]=read(ram,0x0c08728cu,4);
goto P_0c0871a0;
P_0c0871a0: /* original e64c, guest PC 0x0c0871a0 */
if(!s->budget--) { s->failed_pc=0x0c0871a0u; return 0; }
r[6]=0x0000004cu;
goto P_0c0871a2;
P_0c0871a2: /* original 976d, guest PC 0x0c0871a2 */
if(!s->budget--) { s->failed_pc=0x0c0871a2u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087280u,2);
goto P_0c0871a4;
P_0c0871a4: /* original 3e4c, guest PC 0x0c0871a4 */
if(!s->budget--) { s->failed_pc=0x0c0871a4u; return 0; }
r[14]+=r[4];
goto P_0c0871a6;
P_0c0871a6: /* original 430b, guest PC 0x0c0871a6 */
if(!s->budget--) { s->failed_pc=0x0c0871a6u; return 0; }
target=r[3];
r[16]=0x0c0871aau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0871aau) { target=s->pc; goto dispatch; }
goto P_0c0871aa;
P_0c0871a8: /* original 64e3, guest PC 0x0c0871a8 */
if(!s->budget--) { s->failed_pc=0x0c0871a8u; return 0; }
r[4]=r[14];
goto P_0c0871aa;
P_0c0871aa: /* original e03a, guest PC 0x0c0871aa */
if(!s->budget--) { s->failed_pc=0x0c0871aau; return 0; }
r[0]=0x0000003au;
goto P_0c0871ac;
P_0c0871ac: /* original e401, guest PC 0x0c0871ac */
if(!s->budget--) { s->failed_pc=0x0c0871acu; return 0; }
r[4]=0x00000001u;
goto P_0c0871ae;
P_0c0871ae: /* original 0e44, guest PC 0x0c0871ae */
if(!s->budget--) { s->failed_pc=0x0c0871aeu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0871b0;
P_0c0871b0: /* original e03b, guest PC 0x0c0871b0 */
if(!s->budget--) { s->failed_pc=0x0c0871b0u; return 0; }
r[0]=0x0000003bu;
goto P_0c0871b2;
P_0c0871b2: /* original 0e44, guest PC 0x0c0871b2 */
if(!s->budget--) { s->failed_pc=0x0c0871b2u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0871b4;
P_0c0871b4: /* original 6043, guest PC 0x0c0871b4 */
if(!s->budget--) { s->failed_pc=0x0c0871b4u; return 0; }
r[0]=r[4];
goto P_0c0871b6;
P_0c0871b6: /* original 81e4, guest PC 0x0c0871b6 */
if(!s->budget--) { s->failed_pc=0x0c0871b6u; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c0871b8;
P_0c0871b8: /* original 81e5, guest PC 0x0c0871b8 */
if(!s->budget--) { s->failed_pc=0x0c0871b8u; return 0; }
write(ram,r[14]+10,r[0],2);
goto P_0c0871ba;
P_0c0871ba: /* original c735, guest PC 0x0c0871ba */
if(!s->budget--) { s->failed_pc=0x0c0871bau; return 0; }
r[0]=0x0c087290u;
goto P_0c0871bc;
P_0c0871bc: /* original f308, guest PC 0x0c0871bc */
if(!s->budget--) { s->failed_pc=0x0c0871bcu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0871be;
P_0c0871be: /* original e020, guest PC 0x0c0871be */
if(!s->budget--) { s->failed_pc=0x0c0871beu; return 0; }
r[0]=0x00000020u;
goto P_0c0871c0;
P_0c0871c0: /* original fe37, guest PC 0x0c0871c0 */
if(!s->budget--) { s->failed_pc=0x0c0871c0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0871c2;
P_0c0871c2: /* original c734, guest PC 0x0c0871c2 */
if(!s->budget--) { s->failed_pc=0x0c0871c2u; return 0; }
r[0]=0x0c087294u;
goto P_0c0871c4;
P_0c0871c4: /* original f308, guest PC 0x0c0871c4 */
if(!s->budget--) { s->failed_pc=0x0c0871c4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0871c6;
P_0c0871c6: /* original e024, guest PC 0x0c0871c6 */
if(!s->budget--) { s->failed_pc=0x0c0871c6u; return 0; }
r[0]=0x00000024u;
goto P_0c0871c8;
P_0c0871c8: /* original fe37, guest PC 0x0c0871c8 */
if(!s->budget--) { s->failed_pc=0x0c0871c8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0871ca;
P_0c0871ca: /* original c733, guest PC 0x0c0871ca */
if(!s->budget--) { s->failed_pc=0x0c0871cau; return 0; }
r[0]=0x0c087298u;
goto P_0c0871cc;
P_0c0871cc: /* original f308, guest PC 0x0c0871cc */
if(!s->budget--) { s->failed_pc=0x0c0871ccu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0871ce;
P_0c0871ce: /* original e028, guest PC 0x0c0871ce */
if(!s->budget--) { s->failed_pc=0x0c0871ceu; return 0; }
r[0]=0x00000028u;
goto P_0c0871d0;
P_0c0871d0: /* original fe37, guest PC 0x0c0871d0 */
if(!s->budget--) { s->failed_pc=0x0c0871d0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0871d2;
P_0c0871d2: /* original e030, guest PC 0x0c0871d2 */
if(!s->budget--) { s->failed_pc=0x0c0871d2u; return 0; }
r[0]=0x00000030u;
goto P_0c0871d4;
P_0c0871d4: /* original f38d, guest PC 0x0c0871d4 */
if(!s->budget--) { s->failed_pc=0x0c0871d4u; return 0; }
fr[3]=0;
goto P_0c0871d6;
P_0c0871d6: /* original fe37, guest PC 0x0c0871d6 */
if(!s->budget--) { s->failed_pc=0x0c0871d6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0871d8;
P_0c0871d8: /* original c730, guest PC 0x0c0871d8 */
if(!s->budget--) { s->failed_pc=0x0c0871d8u; return 0; }
r[0]=0x0c08729cu;
goto P_0c0871da;
P_0c0871da: /* original f308, guest PC 0x0c0871da */
if(!s->budget--) { s->failed_pc=0x0c0871dau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0871dc;
P_0c0871dc: /* original e02c, guest PC 0x0c0871dc */
if(!s->budget--) { s->failed_pc=0x0c0871dcu; return 0; }
r[0]=0x0000002cu;
goto P_0c0871de;
P_0c0871de: /* original fe37, guest PC 0x0c0871de */
if(!s->budget--) { s->failed_pc=0x0c0871deu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0871e0;
P_0c0871e0: /* original 4f26, guest PC 0x0c0871e0 */
if(!s->budget--) { s->failed_pc=0x0c0871e0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0871e2;
P_0c0871e2: /* original 000b, guest PC 0x0c0871e2 */
if(!s->budget--) { s->failed_pc=0x0c0871e2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0871e4: /* original 6ef6, guest PC 0x0c0871e4 */
if(!s->budget--) { s->failed_pc=0x0c0871e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0871e6u,s,ram);
P_0c0875b0: /* original 364c, guest PC 0x0c0875b0 */
if(!s->budget--) { s->failed_pc=0x0c0875b0u; return 0; }
r[6]+=r[4];
goto P_0c0875b2;
P_0c0875b2: /* original e0ff, guest PC 0x0c0875b2 */
if(!s->budget--) { s->failed_pc=0x0c0875b2u; return 0; }
r[0]=0xffffffffu;
goto P_0c0875b4;
P_0c0875b4: /* original 2402, guest PC 0x0c0875b4 */
if(!s->budget--) { s->failed_pc=0x0c0875b4u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c0875b6;
P_0c0875b6: /* original 1461, guest PC 0x0c0875b6 */
if(!s->budget--) { s->failed_pc=0x0c0875b6u; return 0; }
write(ram,r[4]+4,r[6],4);
goto P_0c0875b8;
P_0c0875b8: /* original 6463, guest PC 0x0c0875b8 */
if(!s->budget--) { s->failed_pc=0x0c0875b8u; return 0; }
r[4]=r[6];
goto P_0c0875ba;
P_0c0875ba: /* original 345c, guest PC 0x0c0875ba */
if(!s->budget--) { s->failed_pc=0x0c0875bau; return 0; }
r[4]+=r[5];
goto P_0c0875bc;
P_0c0875bc: /* original 2778, guest PC 0x0c0875bc */
if(!s->budget--) { s->failed_pc=0x0c0875bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0875be;
P_0c0875be: /* original 2642, guest PC 0x0c0875be */
if(!s->budget--) { s->failed_pc=0x0c0875beu; return 0; }
write(ram,r[6],r[4],4);
goto P_0c0875c0;
P_0c0875c0: /* original 8d02, guest PC 0x0c0875c0 */
if(!s->budget--) { s->failed_pc=0x0c0875c0u; return 0; }
cond=r[17]&1u;
r[6]+=r[5];
if(cond) { goto P_0c0875c8; }
goto P_0c0875c4;
P_0c0875c2: /* original 365c, guest PC 0x0c0875c2 */
if(!s->budget--) { s->failed_pc=0x0c0875c2u; return 0; }
r[6]+=r[5];
goto P_0c0875c4;
P_0c0875c4: /* original aff9, guest PC 0x0c0875c4 */
if(!s->budget--) { s->failed_pc=0x0c0875c4u; return 0; }
r[7]+=0xffffffffu;
goto P_0c0875ba;
P_0c0875c6: /* original 77ff, guest PC 0x0c0875c6 */
if(!s->budget--) { s->failed_pc=0x0c0875c6u; return 0; }
r[7]+=0xffffffffu;
goto P_0c0875c8;
P_0c0875c8: /* original 2602, guest PC 0x0c0875c8 */
if(!s->budget--) { s->failed_pc=0x0c0875c8u; return 0; }
write(ram,r[6],r[0],4);
goto P_0c0875ca;
P_0c0875ca: /* original 000b, guest PC 0x0c0875ca */
if(!s->budget--) { s->failed_pc=0x0c0875cau; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c0875cc: /* original 6063, guest PC 0x0c0875cc */
if(!s->budget--) { s->failed_pc=0x0c0875ccu; return 0; }
r[0]=r[6];
return vf3_matrix_family(0x0c0875ceu,s,ram);
P_0c090fc0: /* original 4f22, guest PC 0x0c090fc0 */
if(!s->budget--) { s->failed_pc=0x0c090fc0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c090fc2;
P_0c090fc2: /* original 6212, guest PC 0x0c090fc2 */
if(!s->budget--) { s->failed_pc=0x0c090fc2u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c090fc4;
P_0c090fc4: /* original d334, guest PC 0x0c090fc4 */
if(!s->budget--) { s->failed_pc=0x0c090fc4u; return 0; }
r[3]=read(ram,0x0c091098u,4);
goto P_0c090fc6;
P_0c090fc6: /* original 2238, guest PC 0x0c090fc6 */
if(!s->budget--) { s->failed_pc=0x0c090fc6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c090fc8;
P_0c090fc8: /* original 8f2b, guest PC 0x0c090fc8 */
if(!s->budget--) { s->failed_pc=0x0c090fc8u; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(!cond) { goto P_0c091022; }
goto P_0c090fcc;
P_0c090fca: /* original 6e43, guest PC 0x0c090fca */
if(!s->budget--) { s->failed_pc=0x0c090fcau; return 0; }
r[14]=r[4];
goto P_0c090fcc;
P_0c090fcc: /* original d334, guest PC 0x0c090fcc */
if(!s->budget--) { s->failed_pc=0x0c090fccu; return 0; }
r[3]=read(ram,0x0c0910a0u,4);
goto P_0c090fce;
P_0c090fce: /* original 430b, guest PC 0x0c090fce */
if(!s->budget--) { s->failed_pc=0x0c090fceu; return 0; }
target=r[3];
r[16]=0x0c090fd2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090fd2u) { target=s->pc; goto dispatch; }
goto P_0c090fd2;
P_0c090fd0: /* original 64e3, guest PC 0x0c090fd0 */
if(!s->budget--) { s->failed_pc=0x0c090fd0u; return 0; }
r[4]=r[14];
goto P_0c090fd2;
P_0c090fd2: /* original d234, guest PC 0x0c090fd2 */
if(!s->budget--) { s->failed_pc=0x0c090fd2u; return 0; }
r[2]=read(ram,0x0c0910a4u,4);
goto P_0c090fd4;
P_0c090fd4: /* original 420b, guest PC 0x0c090fd4 */
if(!s->budget--) { s->failed_pc=0x0c090fd4u; return 0; }
target=r[2];
r[16]=0x0c090fd8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090fd8u) { target=s->pc; goto dispatch; }
goto P_0c090fd8;
P_0c090fd6: /* original 64e3, guest PC 0x0c090fd6 */
if(!s->budget--) { s->failed_pc=0x0c090fd6u; return 0; }
r[4]=r[14];
goto P_0c090fd8;
P_0c090fd8: /* original d333, guest PC 0x0c090fd8 */
if(!s->budget--) { s->failed_pc=0x0c090fd8u; return 0; }
r[3]=read(ram,0x0c0910a8u,4);
goto P_0c090fda;
P_0c090fda: /* original 430b, guest PC 0x0c090fda */
if(!s->budget--) { s->failed_pc=0x0c090fdau; return 0; }
target=r[3];
r[16]=0x0c090fdeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090fdeu) { target=s->pc; goto dispatch; }
goto P_0c090fde;
P_0c090fdc: /* original 64e3, guest PC 0x0c090fdc */
if(!s->budget--) { s->failed_pc=0x0c090fdcu; return 0; }
r[4]=r[14];
goto P_0c090fde;
P_0c090fde: /* original d233, guest PC 0x0c090fde */
if(!s->budget--) { s->failed_pc=0x0c090fdeu; return 0; }
r[2]=read(ram,0x0c0910acu,4);
goto P_0c090fe0;
P_0c090fe0: /* original 420b, guest PC 0x0c090fe0 */
if(!s->budget--) { s->failed_pc=0x0c090fe0u; return 0; }
target=r[2];
r[16]=0x0c090fe4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090fe4u) { target=s->pc; goto dispatch; }
goto P_0c090fe4;
P_0c090fe2: /* original 64e3, guest PC 0x0c090fe2 */
if(!s->budget--) { s->failed_pc=0x0c090fe2u; return 0; }
r[4]=r[14];
goto P_0c090fe4;
P_0c090fe4: /* original d332, guest PC 0x0c090fe4 */
if(!s->budget--) { s->failed_pc=0x0c090fe4u; return 0; }
r[3]=read(ram,0x0c0910b0u,4);
goto P_0c090fe6;
P_0c090fe6: /* original 430b, guest PC 0x0c090fe6 */
if(!s->budget--) { s->failed_pc=0x0c090fe6u; return 0; }
target=r[3];
r[16]=0x0c090feau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090feau) { target=s->pc; goto dispatch; }
goto P_0c090fea;
P_0c090fe8: /* original 64e3, guest PC 0x0c090fe8 */
if(!s->budget--) { s->failed_pc=0x0c090fe8u; return 0; }
r[4]=r[14];
goto P_0c090fea;
P_0c090fea: /* original bb64, guest PC 0x0c090fea */
if(!s->budget--) { s->failed_pc=0x0c090feau; return 0; }
target=0x0c0906b6u; r[16]=0x0c090feeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090feeu) { target=s->pc; goto dispatch; }
goto P_0c090fee;
P_0c090fec: /* original 64e3, guest PC 0x0c090fec */
if(!s->budget--) { s->failed_pc=0x0c090fecu; return 0; }
r[4]=r[14];
goto P_0c090fee;
P_0c090fee: /* original d331, guest PC 0x0c090fee */
if(!s->budget--) { s->failed_pc=0x0c090feeu; return 0; }
r[3]=read(ram,0x0c0910b4u,4);
goto P_0c090ff0;
P_0c090ff0: /* original 430b, guest PC 0x0c090ff0 */
if(!s->budget--) { s->failed_pc=0x0c090ff0u; return 0; }
target=r[3];
r[16]=0x0c090ff4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090ff4u) { target=s->pc; goto dispatch; }
goto P_0c090ff4;
P_0c090ff2: /* original 64e3, guest PC 0x0c090ff2 */
if(!s->budget--) { s->failed_pc=0x0c090ff2u; return 0; }
r[4]=r[14];
goto P_0c090ff4;
P_0c090ff4: /* original d230, guest PC 0x0c090ff4 */
if(!s->budget--) { s->failed_pc=0x0c090ff4u; return 0; }
r[2]=read(ram,0x0c0910b8u,4);
goto P_0c090ff6;
P_0c090ff6: /* original 420b, guest PC 0x0c090ff6 */
if(!s->budget--) { s->failed_pc=0x0c090ff6u; return 0; }
target=r[2];
r[16]=0x0c090ffau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c090ffau) { target=s->pc; goto dispatch; }
goto P_0c090ffa;
P_0c090ff8: /* original 64e3, guest PC 0x0c090ff8 */
if(!s->budget--) { s->failed_pc=0x0c090ff8u; return 0; }
r[4]=r[14];
goto P_0c090ffa;
P_0c090ffa: /* original 9043, guest PC 0x0c090ffa */
if(!s->budget--) { s->failed_pc=0x0c090ffau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091084u,2);
goto P_0c090ffc;
P_0c090ffc: /* original 00ec, guest PC 0x0c090ffc */
if(!s->budget--) { s->failed_pc=0x0c090ffcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c090ffe;
P_0c090ffe: /* original 8817, guest PC 0x0c090ffe */
if(!s->budget--) { s->failed_pc=0x0c090ffeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000017u)!=0);
goto P_0c091000;
P_0c091000: /* original 8d03, guest PC 0x0c091000 */
if(!s->budget--) { s->failed_pc=0x0c091000u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c09100a; }
goto P_0c091004;
P_0c091002: /* original 6403, guest PC 0x0c091002 */
if(!s->budget--) { s->failed_pc=0x0c091002u; return 0; }
r[4]=r[0];
goto P_0c091004;
P_0c091004: /* original 6043, guest PC 0x0c091004 */
if(!s->budget--) { s->failed_pc=0x0c091004u; return 0; }
r[0]=r[4];
goto P_0c091006;
P_0c091006: /* original 8807, guest PC 0x0c091006 */
if(!s->budget--) { s->failed_pc=0x0c091006u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c091008;
P_0c091008: /* original 8b0b, guest PC 0x0c091008 */
if(!s->budget--) { s->failed_pc=0x0c091008u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091022; }
goto P_0c09100a;
P_0c09100a: /* original 903c, guest PC 0x0c09100a */
if(!s->budget--) { s->failed_pc=0x0c09100au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091086u,2);
goto P_0c09100c;
P_0c09100c: /* original f5e6, guest PC 0x0c09100c */
if(!s->budget--) { s->failed_pc=0x0c09100cu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c09100e;
P_0c09100e: /* original 7004, guest PC 0x0c09100e */
if(!s->budget--) { s->failed_pc=0x0c09100eu; return 0; }
r[0]+=0x00000004u;
goto P_0c091010;
P_0c091010: /* original f6e6, guest PC 0x0c091010 */
if(!s->budget--) { s->failed_pc=0x0c091010u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c091012;
P_0c091012: /* original 7004, guest PC 0x0c091012 */
if(!s->budget--) { s->failed_pc=0x0c091012u; return 0; }
r[0]+=0x00000004u;
goto P_0c091014;
P_0c091014: /* original f4e6, guest PC 0x0c091014 */
if(!s->budget--) { s->failed_pc=0x0c091014u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c091016;
P_0c091016: /* original 9037, guest PC 0x0c091016 */
if(!s->budget--) { s->failed_pc=0x0c091016u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091088u,2);
goto P_0c091018;
P_0c091018: /* original fe57, guest PC 0x0c091018 */
if(!s->budget--) { s->failed_pc=0x0c091018u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c09101a;
P_0c09101a: /* original 7004, guest PC 0x0c09101a */
if(!s->budget--) { s->failed_pc=0x0c09101au; return 0; }
r[0]+=0x00000004u;
goto P_0c09101c;
P_0c09101c: /* original fe67, guest PC 0x0c09101c */
if(!s->budget--) { s->failed_pc=0x0c09101cu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c09101e;
P_0c09101e: /* original 7004, guest PC 0x0c09101e */
if(!s->budget--) { s->failed_pc=0x0c09101eu; return 0; }
r[0]+=0x00000004u;
goto P_0c091020;
P_0c091020: /* original fe47, guest PC 0x0c091020 */
if(!s->budget--) { s->failed_pc=0x0c091020u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c091022;
P_0c091022: /* original 4f26, guest PC 0x0c091022 */
if(!s->budget--) { s->failed_pc=0x0c091022u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c091024;
P_0c091024: /* original 000b, guest PC 0x0c091024 */
if(!s->budget--) { s->failed_pc=0x0c091024u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c091026: /* original 6ef6, guest PC 0x0c091026 */
if(!s->budget--) { s->failed_pc=0x0c091026u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c091028u,s,ram);
P_0c091048: /* original 4f22, guest PC 0x0c091048 */
if(!s->budget--) { s->failed_pc=0x0c091048u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09104a;
P_0c09104a: /* original 6212, guest PC 0x0c09104a */
if(!s->budget--) { s->failed_pc=0x0c09104au; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c09104c;
P_0c09104c: /* original d312, guest PC 0x0c09104c */
if(!s->budget--) { s->failed_pc=0x0c09104cu; return 0; }
r[3]=read(ram,0x0c091098u,4);
goto P_0c09104e;
P_0c09104e: /* original 2238, guest PC 0x0c09104e */
if(!s->budget--) { s->failed_pc=0x0c09104eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c091050;
P_0c091050: /* original 8f14, guest PC 0x0c091050 */
if(!s->budget--) { s->failed_pc=0x0c091050u; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(!cond) { goto P_0c09107c; }
goto P_0c091054;
P_0c091052: /* original 6e43, guest PC 0x0c091052 */
if(!s->budget--) { s->failed_pc=0x0c091052u; return 0; }
r[14]=r[4];
goto P_0c091054;
P_0c091054: /* original d313, guest PC 0x0c091054 */
if(!s->budget--) { s->failed_pc=0x0c091054u; return 0; }
r[3]=read(ram,0x0c0910a4u,4);
goto P_0c091056;
P_0c091056: /* original 430b, guest PC 0x0c091056 */
if(!s->budget--) { s->failed_pc=0x0c091056u; return 0; }
target=r[3];
r[16]=0x0c09105au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09105au) { target=s->pc; goto dispatch; }
goto P_0c09105a;
P_0c091058: /* original 64e3, guest PC 0x0c091058 */
if(!s->budget--) { s->failed_pc=0x0c091058u; return 0; }
r[4]=r[14];
goto P_0c09105a;
P_0c09105a: /* original d213, guest PC 0x0c09105a */
if(!s->budget--) { s->failed_pc=0x0c09105au; return 0; }
r[2]=read(ram,0x0c0910a8u,4);
goto P_0c09105c;
P_0c09105c: /* original 420b, guest PC 0x0c09105c */
if(!s->budget--) { s->failed_pc=0x0c09105cu; return 0; }
target=r[2];
r[16]=0x0c091060u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091060u) { target=s->pc; goto dispatch; }
goto P_0c091060;
P_0c09105e: /* original 64e3, guest PC 0x0c09105e */
if(!s->budget--) { s->failed_pc=0x0c09105eu; return 0; }
r[4]=r[14];
goto P_0c091060;
P_0c091060: /* original d312, guest PC 0x0c091060 */
if(!s->budget--) { s->failed_pc=0x0c091060u; return 0; }
r[3]=read(ram,0x0c0910acu,4);
goto P_0c091062;
P_0c091062: /* original 430b, guest PC 0x0c091062 */
if(!s->budget--) { s->failed_pc=0x0c091062u; return 0; }
target=r[3];
r[16]=0x0c091066u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091066u) { target=s->pc; goto dispatch; }
goto P_0c091066;
P_0c091064: /* original 64e3, guest PC 0x0c091064 */
if(!s->budget--) { s->failed_pc=0x0c091064u; return 0; }
r[4]=r[14];
goto P_0c091066;
P_0c091066: /* original d212, guest PC 0x0c091066 */
if(!s->budget--) { s->failed_pc=0x0c091066u; return 0; }
r[2]=read(ram,0x0c0910b0u,4);
goto P_0c091068;
P_0c091068: /* original 420b, guest PC 0x0c091068 */
if(!s->budget--) { s->failed_pc=0x0c091068u; return 0; }
target=r[2];
r[16]=0x0c09106cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09106cu) { target=s->pc; goto dispatch; }
goto P_0c09106c;
P_0c09106a: /* original 64e3, guest PC 0x0c09106a */
if(!s->budget--) { s->failed_pc=0x0c09106au; return 0; }
r[4]=r[14];
goto P_0c09106c;
P_0c09106c: /* original bb23, guest PC 0x0c09106c */
if(!s->budget--) { s->failed_pc=0x0c09106cu; return 0; }
target=0x0c0906b6u; r[16]=0x0c091070u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091070u) { target=s->pc; goto dispatch; }
goto P_0c091070;
P_0c09106e: /* original 64e3, guest PC 0x0c09106e */
if(!s->budget--) { s->failed_pc=0x0c09106eu; return 0; }
r[4]=r[14];
goto P_0c091070;
P_0c091070: /* original d210, guest PC 0x0c091070 */
if(!s->budget--) { s->failed_pc=0x0c091070u; return 0; }
r[2]=read(ram,0x0c0910b4u,4);
goto P_0c091072;
P_0c091072: /* original 420b, guest PC 0x0c091072 */
if(!s->budget--) { s->failed_pc=0x0c091072u; return 0; }
target=r[2];
r[16]=0x0c091076u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c091076u) { target=s->pc; goto dispatch; }
goto P_0c091076;
P_0c091074: /* original 64e3, guest PC 0x0c091074 */
if(!s->budget--) { s->failed_pc=0x0c091074u; return 0; }
r[4]=r[14];
goto P_0c091076;
P_0c091076: /* original d310, guest PC 0x0c091076 */
if(!s->budget--) { s->failed_pc=0x0c091076u; return 0; }
r[3]=read(ram,0x0c0910b8u,4);
goto P_0c091078;
P_0c091078: /* original 430b, guest PC 0x0c091078 */
if(!s->budget--) { s->failed_pc=0x0c091078u; return 0; }
target=r[3];
r[16]=0x0c09107cu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09107cu) { target=s->pc; goto dispatch; }
goto P_0c09107c;
P_0c09107a: /* original 64e3, guest PC 0x0c09107a */
if(!s->budget--) { s->failed_pc=0x0c09107au; return 0; }
r[4]=r[14];
goto P_0c09107c;
P_0c09107c: /* original 4f26, guest PC 0x0c09107c */
if(!s->budget--) { s->failed_pc=0x0c09107cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09107e;
P_0c09107e: /* original 000b, guest PC 0x0c09107e */
if(!s->budget--) { s->failed_pc=0x0c09107eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c091080: /* original 6ef6, guest PC 0x0c091080 */
if(!s->budget--) { s->failed_pc=0x0c091080u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c091082u,s,ram);
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
return vf3_matrix_family(0x0c092230u,s,ram);
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
r[16]=0x0c09426au;
r[5]+=0x00000004u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09426au) { target=s->pc; goto dispatch; }
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
r[16]=0x0c094278u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094278u) { target=s->pc; goto dispatch; }
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
r[16]=0x0c094290u;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094290u) { target=s->pc; goto dispatch; }
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
goto P_0c094294;
P_0c094294: /* original d216, guest PC 0x0c094294 */
if(!s->budget--) { s->failed_pc=0x0c094294u; return 0; }
r[2]=read(ram,0x0c0942f0u,4);
goto P_0c094296;
P_0c094296: /* original 422b, guest PC 0x0c094296 */
if(!s->budget--) { s->failed_pc=0x0c094296u; return 0; }
target=r[2];
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
P_0c094298: /* original 0009, guest PC 0x0c094298 */
if(!s->budget--) { s->failed_pc=0x0c094298u; return 0; }
return vf3_matrix_family(0x0c09429au,s,ram);
P_0c0978ee: /* original 4f22, guest PC 0x0c0978ee */
if(!s->budget--) { s->failed_pc=0x0c0978eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0978f0;
P_0c0978f0: /* original d30d, guest PC 0x0c0978f0 */
if(!s->budget--) { s->failed_pc=0x0c0978f0u; return 0; }
r[3]=read(ram,0x0c097928u,4);
goto P_0c0978f2;
P_0c0978f2: /* original 6563, guest PC 0x0c0978f2 */
if(!s->budget--) { s->failed_pc=0x0c0978f2u; return 0; }
r[5]=r[6];
goto P_0c0978f4;
P_0c0978f4: /* original de0a, guest PC 0x0c0978f4 */
if(!s->budget--) { s->failed_pc=0x0c0978f4u; return 0; }
r[14]=read(ram,0x0c097920u,4);
goto P_0c0978f6;
P_0c0978f6: /* original 430b, guest PC 0x0c0978f6 */
if(!s->budget--) { s->failed_pc=0x0c0978f6u; return 0; }
target=r[3];
r[16]=0x0c0978fau;
r[4]=r[6];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0978fau) { target=s->pc; goto dispatch; }
goto P_0c0978fa;
P_0c0978f8: /* original 6463, guest PC 0x0c0978f8 */
if(!s->budget--) { s->failed_pc=0x0c0978f8u; return 0; }
r[4]=r[6];
goto P_0c0978fa;
P_0c0978fa: /* original d20f, guest PC 0x0c0978fa */
if(!s->budget--) { s->failed_pc=0x0c0978fau; return 0; }
r[2]=read(ram,0x0c097938u,4);
goto P_0c0978fc;
P_0c0978fc: /* original 420b, guest PC 0x0c0978fc */
if(!s->budget--) { s->failed_pc=0x0c0978fcu; return 0; }
target=r[2];
r[16]=0x0c097900u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c097900u) { target=s->pc; goto dispatch; }
goto P_0c097900;
P_0c0978fe: /* original 0009, guest PC 0x0c0978fe */
if(!s->budget--) { s->failed_pc=0x0c0978feu; return 0; }
goto P_0c097900;
P_0c097900: /* original 53e3, guest PC 0x0c097900 */
if(!s->budget--) { s->failed_pc=0x0c097900u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c097902;
P_0c097902: /* original 2338, guest PC 0x0c097902 */
if(!s->budget--) { s->failed_pc=0x0c097902u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c097904;
P_0c097904: /* original 8b02, guest PC 0x0c097904 */
if(!s->budget--) { s->failed_pc=0x0c097904u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09790c; }
goto P_0c097906;
P_0c097906: /* original 84eb, guest PC 0x0c097906 */
if(!s->budget--) { s->failed_pc=0x0c097906u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c097908;
P_0c097908: /* original 7001, guest PC 0x0c097908 */
if(!s->budget--) { s->failed_pc=0x0c097908u; return 0; }
r[0]+=0x00000001u;
goto P_0c09790a;
P_0c09790a: /* original 80eb, guest PC 0x0c09790a */
if(!s->budget--) { s->failed_pc=0x0c09790au; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09790c;
P_0c09790c: /* original 4f26, guest PC 0x0c09790c */
if(!s->budget--) { s->failed_pc=0x0c09790cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09790e;
P_0c09790e: /* original 000b, guest PC 0x0c09790e */
if(!s->budget--) { s->failed_pc=0x0c09790eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c097910: /* original 6ef6, guest PC 0x0c097910 */
if(!s->budget--) { s->failed_pc=0x0c097910u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c097912u,s,ram);
P_0c09a992: /* original 4f22, guest PC 0x0c09a992 */
if(!s->budget--) { s->failed_pc=0x0c09a992u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09a994;
P_0c09a994: /* original 50e3, guest PC 0x0c09a994 */
if(!s->budget--) { s->failed_pc=0x0c09a994u; return 0; }
r[0]=read(ram,r[14]+12,4);
goto P_0c09a996;
P_0c09a996: /* original dd15, guest PC 0x0c09a996 */
if(!s->budget--) { s->failed_pc=0x0c09a996u; return 0; }
r[13]=read(ram,0x0c09a9ecu,4);
goto P_0c09a998;
P_0c09a998: /* original 8840, guest PC 0x0c09a998 */
if(!s->budget--) { s->failed_pc=0x0c09a998u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c09a99a;
P_0c09a99a: /* original 8b02, guest PC 0x0c09a99a */
if(!s->budget--) { s->failed_pc=0x0c09a99au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09a9a2; }
goto P_0c09a99c;
P_0c09a99c: /* original e010, guest PC 0x0c09a99c */
if(!s->budget--) { s->failed_pc=0x0c09a99cu; return 0; }
r[0]=0x00000010u;
goto P_0c09a99e;
P_0c09a99e: /* original e300, guest PC 0x0c09a99e */
if(!s->budget--) { s->failed_pc=0x0c09a99eu; return 0; }
r[3]=0x00000000u;
goto P_0c09a9a0;
P_0c09a9a0: /* original 0e34, guest PC 0x0c09a9a0 */
if(!s->budget--) { s->failed_pc=0x0c09a9a0u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09a9a2;
P_0c09a9a2: /* original 52e3, guest PC 0x0c09a9a2 */
if(!s->budget--) { s->failed_pc=0x0c09a9a2u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c09a9a4;
P_0c09a9a4: /* original 4215, guest PC 0x0c09a9a4 */
if(!s->budget--) { s->failed_pc=0x0c09a9a4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c09a9a6;
P_0c09a9a6: /* original 891b, guest PC 0x0c09a9a6 */
if(!s->budget--) { s->failed_pc=0x0c09a9a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09a9e0; }
goto P_0c09a9a8;
P_0c09a9a8: /* original d112, guest PC 0x0c09a9a8 */
if(!s->budget--) { s->failed_pc=0x0c09a9a8u; return 0; }
r[1]=read(ram,0x0c09a9f4u,4);
goto P_0c09a9aa;
P_0c09a9aa: /* original 410b, guest PC 0x0c09a9aa */
if(!s->budget--) { s->failed_pc=0x0c09a9aau; return 0; }
target=r[1];
r[16]=0x0c09a9aeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09a9aeu) { target=s->pc; goto dispatch; }
goto P_0c09a9ae;
P_0c09a9ac: /* original 0009, guest PC 0x0c09a9ac */
if(!s->budget--) { s->failed_pc=0x0c09a9acu; return 0; }
goto P_0c09a9ae;
P_0c09a9ae: /* original d312, guest PC 0x0c09a9ae */
if(!s->budget--) { s->failed_pc=0x0c09a9aeu; return 0; }
r[3]=read(ram,0x0c09a9f8u,4);
goto P_0c09a9b0;
P_0c09a9b0: /* original 430b, guest PC 0x0c09a9b0 */
if(!s->budget--) { s->failed_pc=0x0c09a9b0u; return 0; }
target=r[3];
r[16]=0x0c09a9b4u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09a9b4u) { target=s->pc; goto dispatch; }
goto P_0c09a9b4;
P_0c09a9b2: /* original 0009, guest PC 0x0c09a9b2 */
if(!s->budget--) { s->failed_pc=0x0c09a9b2u; return 0; }
goto P_0c09a9b4;
P_0c09a9b4: /* original e029, guest PC 0x0c09a9b4 */
if(!s->budget--) { s->failed_pc=0x0c09a9b4u; return 0; }
r[0]=0x00000029u;
goto P_0c09a9b6;
P_0c09a9b6: /* original e100, guest PC 0x0c09a9b6 */
if(!s->budget--) { s->failed_pc=0x0c09a9b6u; return 0; }
r[1]=0x00000000u;
goto P_0c09a9b8;
P_0c09a9b8: /* original 0d14, guest PC 0x0c09a9b8 */
if(!s->budget--) { s->failed_pc=0x0c09a9b8u; return 0; }
write(ram,r[13]+r[0],r[1],1);
goto P_0c09a9ba;
P_0c09a9ba: /* original d310, guest PC 0x0c09a9ba */
if(!s->budget--) { s->failed_pc=0x0c09a9bau; return 0; }
r[3]=read(ram,0x0c09a9fcu,4);
goto P_0c09a9bc;
P_0c09a9bc: /* original 54d2, guest PC 0x0c09a9bc */
if(!s->budget--) { s->failed_pc=0x0c09a9bcu; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c09a9be;
P_0c09a9be: /* original 2439, guest PC 0x0c09a9be */
if(!s->budget--) { s->failed_pc=0x0c09a9beu; return 0; }
r[4]&=r[3];
goto P_0c09a9c0;
P_0c09a9c0: /* original 1d42, guest PC 0x0c09a9c0 */
if(!s->budget--) { s->failed_pc=0x0c09a9c0u; return 0; }
write(ram,r[13]+8,r[4],4);
goto P_0c09a9c2;
P_0c09a9c2: /* original 9011, guest PC 0x0c09a9c2 */
if(!s->budget--) { s->failed_pc=0x0c09a9c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a9e8u,2);
goto P_0c09a9c4;
P_0c09a9c4: /* original 02ee, guest PC 0x0c09a9c4 */
if(!s->budget--) { s->failed_pc=0x0c09a9c4u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09a9c6;
P_0c09a9c6: /* original 2228, guest PC 0x0c09a9c6 */
if(!s->budget--) { s->failed_pc=0x0c09a9c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09a9c8;
P_0c09a9c8: /* original 8908, guest PC 0x0c09a9c8 */
if(!s->budget--) { s->failed_pc=0x0c09a9c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09a9dc; }
goto P_0c09a9ca;
P_0c09a9ca: /* original 900e, guest PC 0x0c09a9ca */
if(!s->budget--) { s->failed_pc=0x0c09a9cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a9eau,2);
goto P_0c09a9cc;
P_0c09a9cc: /* original d40c, guest PC 0x0c09a9cc */
if(!s->budget--) { s->failed_pc=0x0c09a9ccu; return 0; }
r[4]=read(ram,0x0c09aa00u,4);
goto P_0c09a9ce;
P_0c09a9ce: /* original 024e, guest PC 0x0c09a9ce */
if(!s->budget--) { s->failed_pc=0x0c09a9ceu; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c09a9d0;
P_0c09a9d0: /* original 2228, guest PC 0x0c09a9d0 */
if(!s->budget--) { s->failed_pc=0x0c09a9d0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09a9d2;
P_0c09a9d2: /* original 8b03, guest PC 0x0c09a9d2 */
if(!s->budget--) { s->failed_pc=0x0c09a9d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09a9dc; }
goto P_0c09a9d4;
P_0c09a9d4: /* original e201, guest PC 0x0c09a9d4 */
if(!s->budget--) { s->failed_pc=0x0c09a9d4u; return 0; }
r[2]=0x00000001u;
goto P_0c09a9d6;
P_0c09a9d6: /* original 0426, guest PC 0x0c09a9d6 */
if(!s->budget--) { s->failed_pc=0x0c09a9d6u; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c09a9d8;
P_0c09a9d8: /* original a001, guest PC 0x0c09a9d8 */
if(!s->budget--) { s->failed_pc=0x0c09a9d8u; return 0; }
r[0]=0x00000018u;
goto P_0c09a9de;
P_0c09a9da: /* original e018, guest PC 0x0c09a9da */
if(!s->budget--) { s->failed_pc=0x0c09a9dau; return 0; }
r[0]=0x00000018u;
goto P_0c09a9dc;
P_0c09a9dc: /* original e002, guest PC 0x0c09a9dc */
if(!s->budget--) { s->failed_pc=0x0c09a9dcu; return 0; }
r[0]=0x00000002u;
goto P_0c09a9de;
P_0c09a9de: /* original 80ea, guest PC 0x0c09a9de */
if(!s->budget--) { s->failed_pc=0x0c09a9deu; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c09a9e0;
P_0c09a9e0: /* original 4f26, guest PC 0x0c09a9e0 */
if(!s->budget--) { s->failed_pc=0x0c09a9e0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09a9e2;
P_0c09a9e2: /* original 6df6, guest PC 0x0c09a9e2 */
if(!s->budget--) { s->failed_pc=0x0c09a9e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09a9e4;
P_0c09a9e4: /* original 000b, guest PC 0x0c09a9e4 */
if(!s->budget--) { s->failed_pc=0x0c09a9e4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09a9e6: /* original 6ef6, guest PC 0x0c09a9e6 */
if(!s->budget--) { s->failed_pc=0x0c09a9e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09a9e8u,s,ram);
P_0c09d38e: /* original 2fe6, guest PC 0x0c09d38e */
if(!s->budget--) { s->failed_pc=0x0c09d38eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d390;
P_0c09d390: /* original d217, guest PC 0x0c09d390 */
if(!s->budget--) { s->failed_pc=0x0c09d390u; return 0; }
r[2]=read(ram,0x0c09d3f0u,4);
goto P_0c09d392;
P_0c09d392: /* original 7ffc, guest PC 0x0c09d392 */
if(!s->budget--) { s->failed_pc=0x0c09d392u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09d394;
P_0c09d394: /* original d01a, guest PC 0x0c09d394 */
if(!s->budget--) { s->failed_pc=0x0c09d394u; return 0; }
r[0]=read(ram,0x0c09d400u,4);
goto P_0c09d396;
P_0c09d396: /* original 6322, guest PC 0x0c09d396 */
if(!s->budget--) { s->failed_pc=0x0c09d396u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c09d398;
P_0c09d398: /* original d218, guest PC 0x0c09d398 */
if(!s->budget--) { s->failed_pc=0x0c09d398u; return 0; }
r[2]=read(ram,0x0c09d3fcu,4);
goto P_0c09d39a;
P_0c09d39a: /* original d61a, guest PC 0x0c09d39a */
if(!s->budget--) { s->failed_pc=0x0c09d39au; return 0; }
r[6]=read(ram,0x0c09d404u,4);
goto P_0c09d39c;
P_0c09d39c: /* original 2338, guest PC 0x0c09d39c */
if(!s->budget--) { s->failed_pc=0x0c09d39cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09d39e;
P_0c09d39e: /* original d416, guest PC 0x0c09d39e */
if(!s->budget--) { s->failed_pc=0x0c09d39eu; return 0; }
r[4]=read(ram,0x0c09d3f8u,4);
goto P_0c09d3a0;
P_0c09d3a0: /* original 6422, guest PC 0x0c09d3a0 */
if(!s->budget--) { s->failed_pc=0x0c09d3a0u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c09d3a2;
P_0c09d3a2: /* original 6563, guest PC 0x0c09d3a2 */
if(!s->budget--) { s->failed_pc=0x0c09d3a2u; return 0; }
r[5]=r[6];
goto P_0c09d3a4;
P_0c09d3a4: /* original d713, guest PC 0x0c09d3a4 */
if(!s->budget--) { s->failed_pc=0x0c09d3a4u; return 0; }
r[7]=read(ram,0x0c09d3f4u,4);
goto P_0c09d3a6;
P_0c09d3a6: /* original 4408, guest PC 0x0c09d3a6 */
if(!s->budget--) { s->failed_pc=0x0c09d3a6u; return 0; }
r[4]<<=2;
goto P_0c09d3a8;
P_0c09d3a8: /* original 6e43, guest PC 0x0c09d3a8 */
if(!s->budget--) { s->failed_pc=0x0c09d3a8u; return 0; }
r[14]=r[4];
goto P_0c09d3aa;
P_0c09d3aa: /* original 044e, guest PC 0x0c09d3aa */
if(!s->budget--) { s->failed_pc=0x0c09d3aau; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c09d3ac;
P_0c09d3ac: /* original 6063, guest PC 0x0c09d3ac */
if(!s->budget--) { s->failed_pc=0x0c09d3acu; return 0; }
r[0]=r[6];
goto P_0c09d3ae;
P_0c09d3ae: /* original 03ee, guest PC 0x0c09d3ae */
if(!s->budget--) { s->failed_pc=0x0c09d3aeu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09d3b0;
P_0c09d3b0: /* original 3343, guest PC 0x0c09d3b0 */
if(!s->budget--) { s->failed_pc=0x0c09d3b0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[4])!=0);
goto P_0c09d3b2;
P_0c09d3b2: /* original 8d02, guest PC 0x0c09d3b2 */
if(!s->budget--) { s->failed_pc=0x0c09d3b2u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(cond) { goto P_0c09d3ba; }
goto P_0c09d3b6;
P_0c09d3b4: /* original 2f32, guest PC 0x0c09d3b4 */
if(!s->budget--) { s->failed_pc=0x0c09d3b4u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09d3b6;
P_0c09d3b6: /* original 60e3, guest PC 0x0c09d3b6 */
if(!s->budget--) { s->failed_pc=0x0c09d3b6u; return 0; }
r[0]=r[14];
goto P_0c09d3b8;
P_0c09d3b8: /* original 0546, guest PC 0x0c09d3b8 */
if(!s->budget--) { s->failed_pc=0x0c09d3b8u; return 0; }
write(ram,r[5]+r[0],r[4],4);
goto P_0c09d3ba;
P_0c09d3ba: /* original d011, guest PC 0x0c09d3ba */
if(!s->budget--) { s->failed_pc=0x0c09d3bau; return 0; }
r[0]=read(ram,0x0c09d400u,4);
goto P_0c09d3bc;
P_0c09d3bc: /* original e100, guest PC 0x0c09d3bc */
if(!s->budget--) { s->failed_pc=0x0c09d3bcu; return 0; }
r[1]=0x00000000u;
goto P_0c09d3be;
P_0c09d3be: /* original e3ff, guest PC 0x0c09d3be */
if(!s->budget--) { s->failed_pc=0x0c09d3beu; return 0; }
r[3]=0xffffffffu;
goto P_0c09d3c0;
P_0c09d3c0: /* original 6413, guest PC 0x0c09d3c0 */
if(!s->budget--) { s->failed_pc=0x0c09d3c0u; return 0; }
r[4]=r[1];
goto P_0c09d3c2;
P_0c09d3c2: /* original 0e16, guest PC 0x0c09d3c2 */
if(!s->budget--) { s->failed_pc=0x0c09d3c2u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09d3c4;
P_0c09d3c4: /* original ee0d, guest PC 0x0c09d3c4 */
if(!s->budget--) { s->failed_pc=0x0c09d3c4u; return 0; }
r[14]=0x0000000du;
goto P_0c09d3c6;
P_0c09d3c6: /* original d20a, guest PC 0x0c09d3c6 */
if(!s->budget--) { s->failed_pc=0x0c09d3c6u; return 0; }
r[2]=read(ram,0x0c09d3f0u,4);
goto P_0c09d3c8;
P_0c09d3c8: /* original 6513, guest PC 0x0c09d3c8 */
if(!s->budget--) { s->failed_pc=0x0c09d3c8u; return 0; }
r[5]=r[1];
goto P_0c09d3ca;
P_0c09d3ca: /* original 2232, guest PC 0x0c09d3ca */
if(!s->budget--) { s->failed_pc=0x0c09d3cau; return 0; }
write(ram,r[2],r[3],4);
goto P_0c09d3cc;
P_0c09d3cc: /* original 930e, guest PC 0x0c09d3cc */
if(!s->budget--) { s->failed_pc=0x0c09d3ccu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d3ecu,2);
goto P_0c09d3ce;
P_0c09d3ce: /* original 6043, guest PC 0x0c09d3ce */
if(!s->budget--) { s->failed_pc=0x0c09d3ceu; return 0; }
r[0]=r[4];
goto P_0c09d3d0;
P_0c09d3d0: /* original 026e, guest PC 0x0c09d3d0 */
if(!s->budget--) { s->failed_pc=0x0c09d3d0u; return 0; }
r[2]=read(ram,r[6]+r[0],4);
goto P_0c09d3d2;
P_0c09d3d2: /* original 7501, guest PC 0x0c09d3d2 */
if(!s->budget--) { s->failed_pc=0x0c09d3d2u; return 0; }
r[5]+=0x00000001u;
goto P_0c09d3d4;
P_0c09d3d4: /* original 337c, guest PC 0x0c09d3d4 */
if(!s->budget--) { s->failed_pc=0x0c09d3d4u; return 0; }
r[3]+=r[7];
goto P_0c09d3d6;
P_0c09d3d6: /* original 35e3, guest PC 0x0c09d3d6 */
if(!s->budget--) { s->failed_pc=0x0c09d3d6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[14])!=0);
goto P_0c09d3d8;
P_0c09d3d8: /* original 334c, guest PC 0x0c09d3d8 */
if(!s->budget--) { s->failed_pc=0x0c09d3d8u; return 0; }
r[3]+=r[4];
goto P_0c09d3da;
P_0c09d3da: /* original 2322, guest PC 0x0c09d3da */
if(!s->budget--) { s->failed_pc=0x0c09d3dau; return 0; }
write(ram,r[3],r[2],4);
goto P_0c09d3dc;
P_0c09d3dc: /* original 8ff6, guest PC 0x0c09d3dc */
if(!s->budget--) { s->failed_pc=0x0c09d3dcu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c09d3cc; }
goto P_0c09d3e0;
P_0c09d3de: /* original 7404, guest PC 0x0c09d3de */
if(!s->budget--) { s->failed_pc=0x0c09d3deu; return 0; }
r[4]+=0x00000004u;
goto P_0c09d3e0;
P_0c09d3e0: /* original 7f04, guest PC 0x0c09d3e0 */
if(!s->budget--) { s->failed_pc=0x0c09d3e0u; return 0; }
r[15]+=0x00000004u;
goto P_0c09d3e2;
P_0c09d3e2: /* original 000b, guest PC 0x0c09d3e2 */
if(!s->budget--) { s->failed_pc=0x0c09d3e2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09d3e4: /* original 6ef6, guest PC 0x0c09d3e4 */
if(!s->budget--) { s->failed_pc=0x0c09d3e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09d3e6u,s,ram);
P_0c0abad8: /* original 4f22, guest PC 0x0c0abad8 */
if(!s->budget--) { s->failed_pc=0x0c0abad8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abada;
P_0c0abada: /* original d344, guest PC 0x0c0abada */
if(!s->budget--) { s->failed_pc=0x0c0abadau; return 0; }
r[3]=read(ram,0x0c0abbecu,4);
goto P_0c0abadc;
P_0c0abadc: /* original 7ff8, guest PC 0x0c0abadc */
if(!s->budget--) { s->failed_pc=0x0c0abadcu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0abade;
P_0c0abade: /* original 2f32, guest PC 0x0c0abade */
if(!s->budget--) { s->failed_pc=0x0c0abadeu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0abae0;
P_0c0abae0: /* original b104, guest PC 0x0c0abae0 */
if(!s->budget--) { s->failed_pc=0x0c0abae0u; return 0; }
target=0x0c0abcecu; r[16]=0x0c0abae4u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0abae4u) { target=s->pc; goto dispatch; }
goto P_0c0abae4;
P_0c0abae2: /* original 64e3, guest PC 0x0c0abae2 */
if(!s->budget--) { s->failed_pc=0x0c0abae2u; return 0; }
r[4]=r[14];
goto P_0c0abae4;
P_0c0abae4: /* original b122, guest PC 0x0c0abae4 */
if(!s->budget--) { s->failed_pc=0x0c0abae4u; return 0; }
target=0x0c0abd2cu; r[16]=0x0c0abae8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0abae8u) { target=s->pc; goto dispatch; }
goto P_0c0abae8;
P_0c0abae6: /* original 64e3, guest PC 0x0c0abae6 */
if(!s->budget--) { s->failed_pc=0x0c0abae6u; return 0; }
r[4]=r[14];
goto P_0c0abae8;
P_0c0abae8: /* original 1f01, guest PC 0x0c0abae8 */
if(!s->budget--) { s->failed_pc=0x0c0abae8u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0abaea;
P_0c0abaea: /* original b16b, guest PC 0x0c0abaea */
if(!s->budget--) { s->failed_pc=0x0c0abaeau; return 0; }
target=0x0c0abdc4u; r[16]=0x0c0abaeeu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0abaeeu) { target=s->pc; goto dispatch; }
goto P_0c0abaee;
P_0c0abaec: /* original 64e3, guest PC 0x0c0abaec */
if(!s->budget--) { s->failed_pc=0x0c0abaecu; return 0; }
r[4]=r[14];
goto P_0c0abaee;
P_0c0abaee: /* original 50f1, guest PC 0x0c0abaee */
if(!s->budget--) { s->failed_pc=0x0c0abaeeu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0abaf0;
P_0c0abaf0: /* original 8801, guest PC 0x0c0abaf0 */
if(!s->budget--) { s->failed_pc=0x0c0abaf0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0abaf2;
P_0c0abaf2: /* original 8b06, guest PC 0x0c0abaf2 */
if(!s->budget--) { s->failed_pc=0x0c0abaf2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abb02; }
goto P_0c0abaf4;
P_0c0abaf4: /* original 60f2, guest PC 0x0c0abaf4 */
if(!s->budget--) { s->failed_pc=0x0c0abaf4u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0abaf6;
P_0c0abaf6: /* original e11c, guest PC 0x0c0abaf6 */
if(!s->budget--) { s->failed_pc=0x0c0abaf6u; return 0; }
r[1]=0x0000001cu;
goto P_0c0abaf8;
P_0c0abaf8: /* original 001c, guest PC 0x0c0abaf8 */
if(!s->budget--) { s->failed_pc=0x0c0abaf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0abafa;
P_0c0abafa: /* original 600c, guest PC 0x0c0abafa */
if(!s->budget--) { s->failed_pc=0x0c0abafau; return 0; }
r[0]=r[0]&255u;
goto P_0c0abafc;
P_0c0abafc: /* original c90f, guest PC 0x0c0abafc */
if(!s->budget--) { s->failed_pc=0x0c0abafcu; return 0; }
r[0]&=15u;
goto P_0c0abafe;
P_0c0abafe: /* original 8806, guest PC 0x0c0abafe */
if(!s->budget--) { s->failed_pc=0x0c0abafeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0abb00;
P_0c0abb00: /* original 8b0b, guest PC 0x0c0abb00 */
if(!s->budget--) { s->failed_pc=0x0c0abb00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abb1a; }
goto P_0c0abb02;
P_0c0abb02: /* original 7f08, guest PC 0x0c0abb02 */
if(!s->budget--) { s->failed_pc=0x0c0abb02u; return 0; }
r[15]+=0x00000008u;
goto P_0c0abb04;
P_0c0abb04: /* original 65d3, guest PC 0x0c0abb04 */
if(!s->budget--) { s->failed_pc=0x0c0abb04u; return 0; }
r[5]=r[13];
goto P_0c0abb06;
P_0c0abb06: /* original 4f26, guest PC 0x0c0abb06 */
if(!s->budget--) { s->failed_pc=0x0c0abb06u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abb08;
P_0c0abb08: /* original e203, guest PC 0x0c0abb08 */
if(!s->budget--) { s->failed_pc=0x0c0abb08u; return 0; }
r[2]=0x00000003u;
goto P_0c0abb0a;
P_0c0abb0a: /* original 64e3, guest PC 0x0c0abb0a */
if(!s->budget--) { s->failed_pc=0x0c0abb0au; return 0; }
r[4]=r[14];
goto P_0c0abb0c;
P_0c0abb0c: /* original 1d22, guest PC 0x0c0abb0c */
if(!s->budget--) { s->failed_pc=0x0c0abb0cu; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c0abb0e;
P_0c0abb0e: /* original 6323, guest PC 0x0c0abb0e */
if(!s->budget--) { s->failed_pc=0x0c0abb0eu; return 0; }
r[3]=r[2];
goto P_0c0abb10;
P_0c0abb10: /* original e062, guest PC 0x0c0abb10 */
if(!s->budget--) { s->failed_pc=0x0c0abb10u; return 0; }
r[0]=0x00000062u;
goto P_0c0abb12;
P_0c0abb12: /* original 0e34, guest PC 0x0c0abb12 */
if(!s->budget--) { s->failed_pc=0x0c0abb12u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0abb14;
P_0c0abb14: /* original 6df6, guest PC 0x0c0abb14 */
if(!s->budget--) { s->failed_pc=0x0c0abb14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abb16;
P_0c0abb16: /* original a005, guest PC 0x0c0abb16 */
if(!s->budget--) { s->failed_pc=0x0c0abb16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abb24;
P_0c0abb18: /* original 6ef6, guest PC 0x0c0abb18 */
if(!s->budget--) { s->failed_pc=0x0c0abb18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abb1a;
P_0c0abb1a: /* original 7f08, guest PC 0x0c0abb1a */
if(!s->budget--) { s->failed_pc=0x0c0abb1au; return 0; }
r[15]+=0x00000008u;
goto P_0c0abb1c;
P_0c0abb1c: /* original 4f26, guest PC 0x0c0abb1c */
if(!s->budget--) { s->failed_pc=0x0c0abb1cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abb1e;
P_0c0abb1e: /* original 6df6, guest PC 0x0c0abb1e */
if(!s->budget--) { s->failed_pc=0x0c0abb1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abb20;
P_0c0abb20: /* original 000b, guest PC 0x0c0abb20 */
if(!s->budget--) { s->failed_pc=0x0c0abb20u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0abb22: /* original 6ef6, guest PC 0x0c0abb22 */
if(!s->budget--) { s->failed_pc=0x0c0abb22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abb24;
P_0c0abb24: /* original 2fe6, guest PC 0x0c0abb24 */
if(!s->budget--) { s->failed_pc=0x0c0abb24u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abb26;
P_0c0abb26: /* original 6e43, guest PC 0x0c0abb26 */
if(!s->budget--) { s->failed_pc=0x0c0abb26u; return 0; }
r[14]=r[4];
goto P_0c0abb28;
P_0c0abb28: /* original 2fd6, guest PC 0x0c0abb28 */
if(!s->budget--) { s->failed_pc=0x0c0abb28u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abb2a;
P_0c0abb2a: /* original 4f22, guest PC 0x0c0abb2a */
if(!s->budget--) { s->failed_pc=0x0c0abb2au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abb2c;
P_0c0abb2c: /* original b0de, guest PC 0x0c0abb2c */
if(!s->budget--) { s->failed_pc=0x0c0abb2cu; return 0; }
target=0x0c0abcecu; r[16]=0x0c0abb30u;
r[13]=r[5];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0abb30u) { target=s->pc; goto dispatch; }
goto P_0c0abb30;
P_0c0abb2e: /* original 6d53, guest PC 0x0c0abb2e */
if(!s->budget--) { s->failed_pc=0x0c0abb2eu; return 0; }
r[13]=r[5];
goto P_0c0abb30;
P_0c0abb30: /* original e03e, guest PC 0x0c0abb30 */
if(!s->budget--) { s->failed_pc=0x0c0abb30u; return 0; }
r[0]=0x0000003eu;
goto P_0c0abb32;
P_0c0abb32: /* original 04ed, guest PC 0x0c0abb32 */
if(!s->budget--) { s->failed_pc=0x0c0abb32u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abb34;
P_0c0abb34: /* original 9054, guest PC 0x0c0abb34 */
if(!s->budget--) { s->failed_pc=0x0c0abb34u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abbe0u,2);
goto P_0c0abb36;
P_0c0abb36: /* original 644d, guest PC 0x0c0abb36 */
if(!s->budget--) { s->failed_pc=0x0c0abb36u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0abb38;
P_0c0abb38: /* original 05ed, guest PC 0x0c0abb38 */
if(!s->budget--) { s->failed_pc=0x0c0abb38u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abb3a;
P_0c0abb3a: /* original 9052, guest PC 0x0c0abb3a */
if(!s->budget--) { s->failed_pc=0x0c0abb3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abbe2u,2);
goto P_0c0abb3c;
P_0c0abb3c: /* original 3450, guest PC 0x0c0abb3c */
if(!s->budget--) { s->failed_pc=0x0c0abb3cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[5])!=0);
goto P_0c0abb3e;
P_0c0abb3e: /* original 06ed, guest PC 0x0c0abb3e */
if(!s->budget--) { s->failed_pc=0x0c0abb3eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abb40;
P_0c0abb40: /* original 8f03, guest PC 0x0c0abb40 */
if(!s->budget--) { s->failed_pc=0x0c0abb40u; return 0; }
cond=r[17]&1u;
r[6]=r[6]&65535u;
if(!cond) { goto P_0c0abb4a; }
goto P_0c0abb44;
P_0c0abb42: /* original 666d, guest PC 0x0c0abb42 */
if(!s->budget--) { s->failed_pc=0x0c0abb42u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0abb44;
P_0c0abb44: /* original e03e, guest PC 0x0c0abb44 */
if(!s->budget--) { s->failed_pc=0x0c0abb44u; return 0; }
r[0]=0x0000003eu;
goto P_0c0abb46;
P_0c0abb46: /* original 7401, guest PC 0x0c0abb46 */
if(!s->budget--) { s->failed_pc=0x0c0abb46u; return 0; }
r[4]+=0x00000001u;
goto P_0c0abb48;
P_0c0abb48: /* original 0e45, guest PC 0x0c0abb48 */
if(!s->budget--) { s->failed_pc=0x0c0abb48u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0abb4a;
P_0c0abb4a: /* original 3462, guest PC 0x0c0abb4a */
if(!s->budget--) { s->failed_pc=0x0c0abb4au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[6])!=0);
goto P_0c0abb4c;
P_0c0abb4c: /* original 8b15, guest PC 0x0c0abb4c */
if(!s->budget--) { s->failed_pc=0x0c0abb4cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abb7a; }
goto P_0c0abb4e;
P_0c0abb4e: /* original e204, guest PC 0x0c0abb4e */
if(!s->budget--) { s->failed_pc=0x0c0abb4eu; return 0; }
r[2]=0x00000004u;
goto P_0c0abb50;
P_0c0abb50: /* original 65d3, guest PC 0x0c0abb50 */
if(!s->budget--) { s->failed_pc=0x0c0abb50u; return 0; }
r[5]=r[13];
goto P_0c0abb52;
P_0c0abb52: /* original 6323, guest PC 0x0c0abb52 */
if(!s->budget--) { s->failed_pc=0x0c0abb52u; return 0; }
r[3]=r[2];
goto P_0c0abb54;
P_0c0abb54: /* original e062, guest PC 0x0c0abb54 */
if(!s->budget--) { s->failed_pc=0x0c0abb54u; return 0; }
r[0]=0x00000062u;
goto P_0c0abb56;
P_0c0abb56: /* original 1d22, guest PC 0x0c0abb56 */
if(!s->budget--) { s->failed_pc=0x0c0abb56u; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c0abb58;
P_0c0abb58: /* original 64e3, guest PC 0x0c0abb58 */
if(!s->budget--) { s->failed_pc=0x0c0abb58u; return 0; }
r[4]=r[14];
goto P_0c0abb5a;
P_0c0abb5a: /* original 0e34, guest PC 0x0c0abb5a */
if(!s->budget--) { s->failed_pc=0x0c0abb5au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0abb5c;
P_0c0abb5c: /* original e048, guest PC 0x0c0abb5c */
if(!s->budget--) { s->failed_pc=0x0c0abb5cu; return 0; }
r[0]=0x00000048u;
goto P_0c0abb5e;
P_0c0abb5e: /* original 62d2, guest PC 0x0c0abb5e */
if(!s->budget--) { s->failed_pc=0x0c0abb5eu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0abb60;
P_0c0abb60: /* original d323, guest PC 0x0c0abb60 */
if(!s->budget--) { s->failed_pc=0x0c0abb60u; return 0; }
r[3]=read(ram,0x0c0abbf0u,4);
goto P_0c0abb62;
P_0c0abb62: /* original 4f26, guest PC 0x0c0abb62 */
if(!s->budget--) { s->failed_pc=0x0c0abb62u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abb64;
P_0c0abb64: /* original 223b, guest PC 0x0c0abb64 */
if(!s->budget--) { s->failed_pc=0x0c0abb64u; return 0; }
r[2]|=r[3];
goto P_0c0abb66;
P_0c0abb66: /* original 2d22, guest PC 0x0c0abb66 */
if(!s->budget--) { s->failed_pc=0x0c0abb66u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0abb68;
P_0c0abb68: /* original 01ee, guest PC 0x0c0abb68 */
if(!s->budget--) { s->failed_pc=0x0c0abb68u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0abb6a;
P_0c0abb6a: /* original d222, guest PC 0x0c0abb6a */
if(!s->budget--) { s->failed_pc=0x0c0abb6au; return 0; }
r[2]=read(ram,0x0c0abbf4u,4);
goto P_0c0abb6c;
P_0c0abb6c: /* original 212b, guest PC 0x0c0abb6c */
if(!s->budget--) { s->failed_pc=0x0c0abb6cu; return 0; }
r[1]|=r[2];
goto P_0c0abb6e;
P_0c0abb6e: /* original 0e16, guest PC 0x0c0abb6e */
if(!s->budget--) { s->failed_pc=0x0c0abb6eu; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c0abb70;
P_0c0abb70: /* original 60d2, guest PC 0x0c0abb70 */
if(!s->budget--) { s->failed_pc=0x0c0abb70u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0abb72;
P_0c0abb72: /* original 2e02, guest PC 0x0c0abb72 */
if(!s->budget--) { s->failed_pc=0x0c0abb72u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c0abb74;
P_0c0abb74: /* original 6df6, guest PC 0x0c0abb74 */
if(!s->budget--) { s->failed_pc=0x0c0abb74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abb76;
P_0c0abb76: /* original a004, guest PC 0x0c0abb76 */
if(!s->budget--) { s->failed_pc=0x0c0abb76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abb82;
P_0c0abb78: /* original 6ef6, guest PC 0x0c0abb78 */
if(!s->budget--) { s->failed_pc=0x0c0abb78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abb7a;
P_0c0abb7a: /* original 4f26, guest PC 0x0c0abb7a */
if(!s->budget--) { s->failed_pc=0x0c0abb7au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abb7c;
P_0c0abb7c: /* original 6df6, guest PC 0x0c0abb7c */
if(!s->budget--) { s->failed_pc=0x0c0abb7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abb7e;
P_0c0abb7e: /* original 000b, guest PC 0x0c0abb7e */
if(!s->budget--) { s->failed_pc=0x0c0abb7eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0abb80: /* original 6ef6, guest PC 0x0c0abb80 */
if(!s->budget--) { s->failed_pc=0x0c0abb80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abb82;
P_0c0abb82: /* original 2fe6, guest PC 0x0c0abb82 */
if(!s->budget--) { s->failed_pc=0x0c0abb82u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abb84;
P_0c0abb84: /* original e048, guest PC 0x0c0abb84 */
if(!s->budget--) { s->failed_pc=0x0c0abb84u; return 0; }
r[0]=0x00000048u;
goto P_0c0abb86;
P_0c0abb86: /* original 6e43, guest PC 0x0c0abb86 */
if(!s->budget--) { s->failed_pc=0x0c0abb86u; return 0; }
r[14]=r[4];
goto P_0c0abb88;
P_0c0abb88: /* original 02ee, guest PC 0x0c0abb88 */
if(!s->budget--) { s->failed_pc=0x0c0abb88u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0abb8a;
P_0c0abb8a: /* original d31b, guest PC 0x0c0abb8a */
if(!s->budget--) { s->failed_pc=0x0c0abb8au; return 0; }
r[3]=read(ram,0x0c0abbf8u,4);
goto P_0c0abb8c;
P_0c0abb8c: /* original 4f22, guest PC 0x0c0abb8c */
if(!s->budget--) { s->failed_pc=0x0c0abb8cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abb8e;
P_0c0abb8e: /* original 2239, guest PC 0x0c0abb8e */
if(!s->budget--) { s->failed_pc=0x0c0abb8eu; return 0; }
r[2]&=r[3];
goto P_0c0abb90;
P_0c0abb90: /* original 0e26, guest PC 0x0c0abb90 */
if(!s->budget--) { s->failed_pc=0x0c0abb90u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0abb92;
P_0c0abb92: /* original b0ab, guest PC 0x0c0abb92 */
if(!s->budget--) { s->failed_pc=0x0c0abb92u; return 0; }
target=0x0c0abcecu; r[16]=0x0c0abb96u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0abb96u) { target=s->pc; goto dispatch; }
goto P_0c0abb96;
P_0c0abb94: /* original 64e3, guest PC 0x0c0abb94 */
if(!s->budget--) { s->failed_pc=0x0c0abb94u; return 0; }
r[4]=r[14];
goto P_0c0abb96;
P_0c0abb96: /* original e024, guest PC 0x0c0abb96 */
if(!s->budget--) { s->failed_pc=0x0c0abb96u; return 0; }
r[0]=0x00000024u;
goto P_0c0abb98;
P_0c0abb98: /* original f48d, guest PC 0x0c0abb98 */
if(!s->budget--) { s->failed_pc=0x0c0abb98u; return 0; }
fr[4]=0;
goto P_0c0abb9a;
P_0c0abb9a: /* original fe47, guest PC 0x0c0abb9a */
if(!s->budget--) { s->failed_pc=0x0c0abb9au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0abb9c;
P_0c0abb9c: /* original e02c, guest PC 0x0c0abb9c */
if(!s->budget--) { s->failed_pc=0x0c0abb9cu; return 0; }
r[0]=0x0000002cu;
goto P_0c0abb9e;
P_0c0abb9e: /* original fe47, guest PC 0x0c0abb9e */
if(!s->budget--) { s->failed_pc=0x0c0abb9eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0abba0;
P_0c0abba0: /* original 9020, guest PC 0x0c0abba0 */
if(!s->budget--) { s->failed_pc=0x0c0abba0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abbe4u,2);
goto P_0c0abba2;
P_0c0abba2: /* original 4f26, guest PC 0x0c0abba2 */
if(!s->budget--) { s->failed_pc=0x0c0abba2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abba4;
P_0c0abba4: /* original fe47, guest PC 0x0c0abba4 */
if(!s->budget--) { s->failed_pc=0x0c0abba4u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0abba6;
P_0c0abba6: /* original 7004, guest PC 0x0c0abba6 */
if(!s->budget--) { s->failed_pc=0x0c0abba6u; return 0; }
r[0]+=0x00000004u;
goto P_0c0abba8;
P_0c0abba8: /* original fe47, guest PC 0x0c0abba8 */
if(!s->budget--) { s->failed_pc=0x0c0abba8u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0abbaa;
P_0c0abbaa: /* original 7004, guest PC 0x0c0abbaa */
if(!s->budget--) { s->failed_pc=0x0c0abbaau; return 0; }
r[0]+=0x00000004u;
goto P_0c0abbac;
P_0c0abbac: /* original fe47, guest PC 0x0c0abbac */
if(!s->budget--) { s->failed_pc=0x0c0abbacu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0abbae;
P_0c0abbae: /* original 9018, guest PC 0x0c0abbae */
if(!s->budget--) { s->failed_pc=0x0c0abbaeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0abbe2u,2);
goto P_0c0abbb0;
P_0c0abbb0: /* original 03ed, guest PC 0x0c0abbb0 */
if(!s->budget--) { s->failed_pc=0x0c0abbb0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abbb2;
P_0c0abbb2: /* original e03e, guest PC 0x0c0abbb2 */
if(!s->budget--) { s->failed_pc=0x0c0abbb2u; return 0; }
r[0]=0x0000003eu;
goto P_0c0abbb4;
P_0c0abbb4: /* original 0e35, guest PC 0x0c0abbb4 */
if(!s->budget--) { s->failed_pc=0x0c0abbb4u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0abbb6;
P_0c0abbb6: /* original 000b, guest PC 0x0c0abbb6 */
if(!s->budget--) { s->failed_pc=0x0c0abbb6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0abbb8: /* original 6ef6, guest PC 0x0c0abbb8 */
if(!s->budget--) { s->failed_pc=0x0c0abbb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0abbbau,s,ram);
P_0c0c66cc: /* original 000b, guest PC 0x0c0c66cc */
if(!s->budget--) { s->failed_pc=0x0c0c66ccu; return 0; }
target=r[16];
vf3_matrix_load(s,ram,0,r[4]);
s->pc=target; return ram->oob==0;
P_0c0c66ce: /* original f048, guest PC 0x0c0c66ce */
if(!s->budget--) { s->failed_pc=0x0c0c66ceu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
return vf3_matrix_family(0x0c0c66d0u,s,ram);
P_0c0c66dc: /* original 000b, guest PC 0x0c0c66dc */
if(!s->budget--) { s->failed_pc=0x0c0c66dcu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,4,r[4]);
s->pc=target; return ram->oob==0;
P_0c0c66de: /* original f44a, guest PC 0x0c0c66de */
if(!s->budget--) { s->failed_pc=0x0c0c66deu; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
return vf3_matrix_family(0x0c0c66e0u,s,ram);
P_0c0c80a8: /* original 2fe6, guest PC 0x0c0c80a8 */
if(!s->budget--) { s->failed_pc=0x0c0c80a8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c80aa;
P_0c0c80aa: /* original 2fd6, guest PC 0x0c0c80aa */
if(!s->budget--) { s->failed_pc=0x0c0c80aau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c80ac;
P_0c0c80ac: /* original 2fc6, guest PC 0x0c0c80ac */
if(!s->budget--) { s->failed_pc=0x0c0c80acu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c80ae;
P_0c0c80ae: /* original 2fb6, guest PC 0x0c0c80ae */
if(!s->budget--) { s->failed_pc=0x0c0c80aeu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c80b0;
P_0c0c80b0: /* original 2fa6, guest PC 0x0c0c80b0 */
if(!s->budget--) { s->failed_pc=0x0c0c80b0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c80b2;
P_0c0c80b2: /* original 2f96, guest PC 0x0c0c80b2 */
if(!s->budget--) { s->failed_pc=0x0c0c80b2u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c80b4;
P_0c0c80b4: /* original 9049, guest PC 0x0c0c80b4 */
if(!s->budget--) { s->failed_pc=0x0c0c80b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c814au,2);
goto P_0c0c80b6;
P_0c0c80b6: /* original d429, guest PC 0x0c0c80b6 */
if(!s->budget--) { s->failed_pc=0x0c0c80b6u; return 0; }
r[4]=read(ram,0x0c0c815cu,4);
goto P_0c0c80b8;
P_0c0c80b8: /* original d629, guest PC 0x0c0c80b8 */
if(!s->budget--) { s->failed_pc=0x0c0c80b8u; return 0; }
r[6]=read(ram,0x0c0c8160u,4);
goto P_0c0c80ba;
P_0c0c80ba: /* original 034c, guest PC 0x0c0c80ba */
if(!s->budget--) { s->failed_pc=0x0c0c80bau; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c80bc;
P_0c0c80bc: /* original 70f8, guest PC 0x0c0c80bc */
if(!s->budget--) { s->failed_pc=0x0c0c80bcu; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c80be;
P_0c0c80be: /* original 4f22, guest PC 0x0c0c80be */
if(!s->budget--) { s->failed_pc=0x0c0c80beu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c80c0;
P_0c0c80c0: /* original 0434, guest PC 0x0c0c80c0 */
if(!s->budget--) { s->failed_pc=0x0c0c80c0u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c0c80c2;
P_0c0c80c2: /* original 9043, guest PC 0x0c0c80c2 */
if(!s->budget--) { s->failed_pc=0x0c0c80c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c814cu,2);
goto P_0c0c80c4;
P_0c0c80c4: /* original 9343, guest PC 0x0c0c80c4 */
if(!s->budget--) { s->failed_pc=0x0c0c80c4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c814eu,2);
goto P_0c0c80c6;
P_0c0c80c6: /* original 7ffc, guest PC 0x0c0c80c6 */
if(!s->budget--) { s->failed_pc=0x0c0c80c6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c80c8;
P_0c0c80c8: /* original 026c, guest PC 0x0c0c80c8 */
if(!s->budget--) { s->failed_pc=0x0c0c80c8u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0c80ca;
P_0c0c80ca: /* original 622c, guest PC 0x0c0c80ca */
if(!s->budget--) { s->failed_pc=0x0c0c80cau; return 0; }
r[2]=r[2]&255u;
goto P_0c0c80cc;
P_0c0c80cc: /* original 3230, guest PC 0x0c0c80cc */
if(!s->budget--) { s->failed_pc=0x0c0c80ccu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0c80ce;
P_0c0c80ce: /* original 8901, guest PC 0x0c0c80ce */
if(!s->budget--) { s->failed_pc=0x0c0c80ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c80d4; }
goto P_0c0c80d0;
P_0c0c80d0: /* original a0b5, guest PC 0x0c0c80d0 */
if(!s->budget--) { s->failed_pc=0x0c0c80d0u; return 0; }
goto P_0c0c823e;
P_0c0c80d2: /* original 0009, guest PC 0x0c0c80d2 */
if(!s->budget--) { s->failed_pc=0x0c0c80d2u; return 0; }
goto P_0c0c80d4;
P_0c0c80d4: /* original 903c, guest PC 0x0c0c80d4 */
if(!s->budget--) { s->failed_pc=0x0c0c80d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8150u,2);
goto P_0c0c80d6;
P_0c0c80d6: /* original 074e, guest PC 0x0c0c80d6 */
if(!s->budget--) { s->failed_pc=0x0c0c80d6u; return 0; }
r[7]=read(ram,r[4]+r[0],4);
goto P_0c0c80d8;
P_0c0c80d8: /* original 70fc, guest PC 0x0c0c80d8 */
if(!s->budget--) { s->failed_pc=0x0c0c80d8u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0c80da;
P_0c0c80da: /* original 0a4e, guest PC 0x0c0c80da */
if(!s->budget--) { s->failed_pc=0x0c0c80dau; return 0; }
r[10]=read(ram,r[4]+r[0],4);
goto P_0c0c80dc;
P_0c0c80dc: /* original 9039, guest PC 0x0c0c80dc */
if(!s->budget--) { s->failed_pc=0x0c0c80dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8152u,2);
goto P_0c0c80de;
P_0c0c80de: /* original 006c, guest PC 0x0c0c80de */
if(!s->budget--) { s->failed_pc=0x0c0c80deu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0c80e0;
P_0c0c80e0: /* original 8801, guest PC 0x0c0c80e0 */
if(!s->budget--) { s->failed_pc=0x0c0c80e0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c80e2;
P_0c0c80e2: /* original 8b01, guest PC 0x0c0c80e2 */
if(!s->budget--) { s->failed_pc=0x0c0c80e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c80e8; }
goto P_0c0c80e4;
P_0c0c80e4: /* original 4a19, guest PC 0x0c0c80e4 */
if(!s->budget--) { s->failed_pc=0x0c0c80e4u; return 0; }
r[10]>>=8;
goto P_0c0c80e6;
P_0c0c80e6: /* original 4719, guest PC 0x0c0c80e6 */
if(!s->budget--) { s->failed_pc=0x0c0c80e6u; return 0; }
r[7]>>=8;
goto P_0c0c80e8;
P_0c0c80e8: /* original 9034, guest PC 0x0c0c80e8 */
if(!s->budget--) { s->failed_pc=0x0c0c80e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8154u,2);
goto P_0c0c80ea;
P_0c0c80ea: /* original ec00, guest PC 0x0c0c80ea */
if(!s->budget--) { s->failed_pc=0x0c0c80eau; return 0; }
r[12]=0x00000000u;
goto P_0c0c80ec;
P_0c0c80ec: /* original 9333, guest PC 0x0c0c80ec */
if(!s->budget--) { s->failed_pc=0x0c0c80ecu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8156u,2);
goto P_0c0c80ee;
P_0c0c80ee: /* original 6bc3, guest PC 0x0c0c80ee */
if(!s->budget--) { s->failed_pc=0x0c0c80eeu; return 0; }
r[11]=r[12];
goto P_0c0c80f0;
P_0c0c80f0: /* original 054c, guest PC 0x0c0c80f0 */
if(!s->budget--) { s->failed_pc=0x0c0c80f0u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c80f2;
P_0c0c80f2: /* original 7001, guest PC 0x0c0c80f2 */
if(!s->budget--) { s->failed_pc=0x0c0c80f2u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c80f4;
P_0c0c80f4: /* original 0e4c, guest PC 0x0c0c80f4 */
if(!s->budget--) { s->failed_pc=0x0c0c80f4u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c80f6;
P_0c0c80f6: /* original 2379, guest PC 0x0c0c80f6 */
if(!s->budget--) { s->failed_pc=0x0c0c80f6u; return 0; }
r[3]&=r[7];
goto P_0c0c80f8;
P_0c0c80f8: /* original 922e, guest PC 0x0c0c80f8 */
if(!s->budget--) { s->failed_pc=0x0c0c80f8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8158u,2);
goto P_0c0c80fa;
P_0c0c80fa: /* original 655c, guest PC 0x0c0c80fa */
if(!s->budget--) { s->failed_pc=0x0c0c80fau; return 0; }
r[5]=r[5]&255u;
goto P_0c0c80fc;
P_0c0c80fc: /* original 6eec, guest PC 0x0c0c80fc */
if(!s->budget--) { s->failed_pc=0x0c0c80fcu; return 0; }
r[14]=r[14]&255u;
goto P_0c0c80fe;
P_0c0c80fe: /* original 69c3, guest PC 0x0c0c80fe */
if(!s->budget--) { s->failed_pc=0x0c0c80feu; return 0; }
r[9]=r[12];
goto P_0c0c8100;
P_0c0c8100: /* original 2278, guest PC 0x0c0c8100 */
if(!s->budget--) { s->failed_pc=0x0c0c8100u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[7])==0)!=0);
goto P_0c0c8102;
P_0c0c8102: /* original ed01, guest PC 0x0c0c8102 */
if(!s->budget--) { s->failed_pc=0x0c0c8102u; return 0; }
r[13]=0x00000001u;
goto P_0c0c8104;
P_0c0c8104: /* original 8d04, guest PC 0x0c0c8104 */
if(!s->budget--) { s->failed_pc=0x0c0c8104u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(cond) { goto P_0c0c8110; }
goto P_0c0c8108;
P_0c0c8106: /* original 2f32, guest PC 0x0c0c8106 */
if(!s->budget--) { s->failed_pc=0x0c0c8106u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c8108;
P_0c0c8108: /* original 63f2, guest PC 0x0c0c8108 */
if(!s->budget--) { s->failed_pc=0x0c0c8108u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c810a;
P_0c0c810a: /* original 2338, guest PC 0x0c0c810a */
if(!s->budget--) { s->failed_pc=0x0c0c810au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c810c;
P_0c0c810c: /* original 8b00, guest PC 0x0c0c810c */
if(!s->budget--) { s->failed_pc=0x0c0c810cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8110; }
goto P_0c0c810e;
P_0c0c810e: /* original 6bd3, guest PC 0x0c0c810e */
if(!s->budget--) { s->failed_pc=0x0c0c810eu; return 0; }
r[11]=r[13];
goto P_0c0c8110;
P_0c0c8110: /* original d214, guest PC 0x0c0c8110 */
if(!s->budget--) { s->failed_pc=0x0c0c8110u; return 0; }
r[2]=read(ram,0x0c0c8164u,4);
goto P_0c0c8112;
P_0c0c8112: /* original 9022, guest PC 0x0c0c8112 */
if(!s->budget--) { s->failed_pc=0x0c0c8112u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c815au,2);
goto P_0c0c8114;
P_0c0c8114: /* original 2278, guest PC 0x0c0c8114 */
if(!s->budget--) { s->failed_pc=0x0c0c8114u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[7])==0)!=0);
goto P_0c0c8116;
P_0c0c8116: /* original 8d03, guest PC 0x0c0c8116 */
if(!s->budget--) { s->failed_pc=0x0c0c8116u; return 0; }
cond=r[17]&1u;
r[0]&=r[7];
if(cond) { goto P_0c0c8120; }
goto P_0c0c811a;
P_0c0c8118: /* original 2079, guest PC 0x0c0c8118 */
if(!s->budget--) { s->failed_pc=0x0c0c8118u; return 0; }
r[0]&=r[7];
goto P_0c0c811a;
P_0c0c811a: /* original 2008, guest PC 0x0c0c811a */
if(!s->budget--) { s->failed_pc=0x0c0c811au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c811c;
P_0c0c811c: /* original 8b00, guest PC 0x0c0c811c */
if(!s->budget--) { s->failed_pc=0x0c0c811cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8120; }
goto P_0c0c811e;
P_0c0c811e: /* original ebff, guest PC 0x0c0c811e */
if(!s->budget--) { s->failed_pc=0x0c0c811eu; return 0; }
r[11]=0xffffffffu;
goto P_0c0c8120;
P_0c0c8120: /* original 2008, guest PC 0x0c0c8120 */
if(!s->budget--) { s->failed_pc=0x0c0c8120u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c8122;
P_0c0c8122: /* original 8904, guest PC 0x0c0c8122 */
if(!s->budget--) { s->failed_pc=0x0c0c8122u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c812e; }
goto P_0c0c8124;
P_0c0c8124: /* original 9318, guest PC 0x0c0c8124 */
if(!s->budget--) { s->failed_pc=0x0c0c8124u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8158u,2);
goto P_0c0c8126;
P_0c0c8126: /* original 23a8, guest PC 0x0c0c8126 */
if(!s->budget--) { s->failed_pc=0x0c0c8126u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[10])==0)!=0);
goto P_0c0c8128;
P_0c0c8128: /* original 8d01, guest PC 0x0c0c8128 */
if(!s->budget--) { s->failed_pc=0x0c0c8128u; return 0; }
cond=r[17]&1u;
r[9]=r[13];
if(cond) { goto P_0c0c812e; }
goto P_0c0c812c;
P_0c0c812a: /* original 69d3, guest PC 0x0c0c812a */
if(!s->budget--) { s->failed_pc=0x0c0c812au; return 0; }
r[9]=r[13];
goto P_0c0c812c;
P_0c0c812c: /* original 6bd3, guest PC 0x0c0c812c */
if(!s->budget--) { s->failed_pc=0x0c0c812cu; return 0; }
r[11]=r[13];
goto P_0c0c812e;
P_0c0c812e: /* original 63f2, guest PC 0x0c0c812e */
if(!s->budget--) { s->failed_pc=0x0c0c812eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c8130;
P_0c0c8130: /* original 2338, guest PC 0x0c0c8130 */
if(!s->budget--) { s->failed_pc=0x0c0c8130u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c8132;
P_0c0c8132: /* original 8904, guest PC 0x0c0c8132 */
if(!s->budget--) { s->failed_pc=0x0c0c8132u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c813e; }
goto P_0c0c8134;
P_0c0c8134: /* original d20b, guest PC 0x0c0c8134 */
if(!s->budget--) { s->failed_pc=0x0c0c8134u; return 0; }
r[2]=read(ram,0x0c0c8164u,4);
goto P_0c0c8136;
P_0c0c8136: /* original 2a28, guest PC 0x0c0c8136 */
if(!s->budget--) { s->failed_pc=0x0c0c8136u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[2])==0)!=0);
goto P_0c0c8138;
P_0c0c8138: /* original 8900, guest PC 0x0c0c8138 */
if(!s->budget--) { s->failed_pc=0x0c0c8138u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c813c; }
goto P_0c0c813a;
P_0c0c813a: /* original ebff, guest PC 0x0c0c813a */
if(!s->budget--) { s->failed_pc=0x0c0c813au; return 0; }
r[11]=0xffffffffu;
goto P_0c0c813c;
P_0c0c813c: /* original e9ff, guest PC 0x0c0c813c */
if(!s->budget--) { s->failed_pc=0x0c0c813cu; return 0; }
r[9]=0xffffffffu;
goto P_0c0c813e;
P_0c0c813e: /* original 699e, guest PC 0x0c0c813e */
if(!s->budget--) { s->failed_pc=0x0c0c813eu; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)r[9];
goto P_0c0c8140;
P_0c0c8140: /* original 359c, guest PC 0x0c0c8140 */
if(!s->budget--) { s->failed_pc=0x0c0c8140u; return 0; }
r[5]+=r[9];
goto P_0c0c8142;
P_0c0c8142: /* original 4511, guest PC 0x0c0c8142 */
if(!s->budget--) { s->failed_pc=0x0c0c8142u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c0c8144;
P_0c0c8144: /* original 8910, guest PC 0x0c0c8144 */
if(!s->budget--) { s->failed_pc=0x0c0c8144u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8168; }
goto P_0c0c8146;
P_0c0c8146: /* original a012, guest PC 0x0c0c8146 */
if(!s->budget--) { s->failed_pc=0x0c0c8146u; return 0; }
r[5]=r[12];
goto P_0c0c816e;
P_0c0c8148: /* original 65c3, guest PC 0x0c0c8148 */
if(!s->budget--) { s->failed_pc=0x0c0c8148u; return 0; }
r[5]=r[12];
return vf3_matrix_family(0x0c0c814au,s,ram);
P_0c0c8168: /* original 35d7, guest PC 0x0c0c8168 */
if(!s->budget--) { s->failed_pc=0x0c0c8168u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[13])!=0);
goto P_0c0c816a;
P_0c0c816a: /* original 8b00, guest PC 0x0c0c816a */
if(!s->budget--) { s->failed_pc=0x0c0c816au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c816e; }
goto P_0c0c816c;
P_0c0c816c: /* original 65d3, guest PC 0x0c0c816c */
if(!s->budget--) { s->failed_pc=0x0c0c816cu; return 0; }
r[5]=r[13];
goto P_0c0c816e;
P_0c0c816e: /* original 3ebc, guest PC 0x0c0c816e */
if(!s->budget--) { s->failed_pc=0x0c0c816eu; return 0; }
r[14]+=r[11];
goto P_0c0c8170;
P_0c0c8170: /* original 6b53, guest PC 0x0c0c8170 */
if(!s->budget--) { s->failed_pc=0x0c0c8170u; return 0; }
r[11]=r[5];
goto P_0c0c8172;
P_0c0c8172: /* original 4e11, guest PC 0x0c0c8172 */
if(!s->budget--) { s->failed_pc=0x0c0c8172u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0c8174;
P_0c0c8174: /* original 8d01, guest PC 0x0c0c8174 */
if(!s->budget--) { s->failed_pc=0x0c0c8174u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000005u;
if(cond) { goto P_0c0c817a; }
goto P_0c0c8178;
P_0c0c8176: /* original 7b05, guest PC 0x0c0c8176 */
if(!s->budget--) { s->failed_pc=0x0c0c8176u; return 0; }
r[11]+=0x00000005u;
goto P_0c0c8178;
P_0c0c8178: /* original 6eb3, guest PC 0x0c0c8178 */
if(!s->budget--) { s->failed_pc=0x0c0c8178u; return 0; }
r[14]=r[11];
goto P_0c0c817a;
P_0c0c817a: /* original 3eb7, guest PC 0x0c0c817a */
if(!s->budget--) { s->failed_pc=0x0c0c817au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[11])!=0);
goto P_0c0c817c;
P_0c0c817c: /* original 8b00, guest PC 0x0c0c817c */
if(!s->budget--) { s->failed_pc=0x0c0c817cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8180; }
goto P_0c0c817e;
P_0c0c817e: /* original 6ec3, guest PC 0x0c0c817e */
if(!s->budget--) { s->failed_pc=0x0c0c817eu; return 0; }
r[14]=r[12];
goto P_0c0c8180;
P_0c0c8180: /* original 9066, guest PC 0x0c0c8180 */
if(!s->budget--) { s->failed_pc=0x0c0c8180u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8250u,2);
goto P_0c0c8182;
P_0c0c8182: /* original 6b53, guest PC 0x0c0c8182 */
if(!s->budget--) { s->failed_pc=0x0c0c8182u; return 0; }
r[11]=r[5];
goto P_0c0c8184;
P_0c0c8184: /* original 6353, guest PC 0x0c0c8184 */
if(!s->budget--) { s->failed_pc=0x0c0c8184u; return 0; }
r[3]=r[5];
goto P_0c0c8186;
P_0c0c8186: /* original 4b08, guest PC 0x0c0c8186 */
if(!s->budget--) { s->failed_pc=0x0c0c8186u; return 0; }
r[11]<<=2;
goto P_0c0c8188;
P_0c0c8188: /* original 0454, guest PC 0x0c0c8188 */
if(!s->budget--) { s->failed_pc=0x0c0c8188u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c818a;
P_0c0c818a: /* original 7001, guest PC 0x0c0c818a */
if(!s->budget--) { s->failed_pc=0x0c0c818au; return 0; }
r[0]+=0x00000001u;
goto P_0c0c818c;
P_0c0c818c: /* original 3b3c, guest PC 0x0c0c818c */
if(!s->budget--) { s->failed_pc=0x0c0c818cu; return 0; }
r[11]+=r[3];
goto P_0c0c818e;
P_0c0c818e: /* original 04e4, guest PC 0x0c0c818e */
if(!s->budget--) { s->failed_pc=0x0c0c818eu; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c0c8190;
P_0c0c8190: /* original d033, guest PC 0x0c0c8190 */
if(!s->budget--) { s->failed_pc=0x0c0c8190u; return 0; }
r[0]=read(ram,0x0c0c8260u,4);
goto P_0c0c8192;
P_0c0c8192: /* original 3bec, guest PC 0x0c0c8192 */
if(!s->budget--) { s->failed_pc=0x0c0c8192u; return 0; }
r[11]+=r[14];
goto P_0c0c8194;
P_0c0c8194: /* original 935d, guest PC 0x0c0c8194 */
if(!s->budget--) { s->failed_pc=0x0c0c8194u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8252u,2);
goto P_0c0c8196;
P_0c0c8196: /* original 3b5c, guest PC 0x0c0c8196 */
if(!s->budget--) { s->failed_pc=0x0c0c8196u; return 0; }
r[11]+=r[5];
goto P_0c0c8198;
P_0c0c8198: /* original 05bc, guest PC 0x0c0c8198 */
if(!s->budget--) { s->failed_pc=0x0c0c8198u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c819a;
P_0c0c819a: /* original 334c, guest PC 0x0c0c819a */
if(!s->budget--) { s->failed_pc=0x0c0c819au; return 0; }
r[3]+=r[4];
goto P_0c0c819c;
P_0c0c819c: /* original 2350, guest PC 0x0c0c819c */
if(!s->budget--) { s->failed_pc=0x0c0c819cu; return 0; }
write(ram,r[3],r[5],1);
goto P_0c0c819e;
P_0c0c819e: /* original 5e43, guest PC 0x0c0c819e */
if(!s->budget--) { s->failed_pc=0x0c0c819eu; return 0; }
r[14]=read(ram,r[4]+12,4);
goto P_0c0c81a0;
P_0c0c81a0: /* original 4e15, guest PC 0x0c0c81a0 */
if(!s->budget--) { s->failed_pc=0x0c0c81a0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c81a2;
P_0c0c81a2: /* original 8f03, guest PC 0x0c0c81a2 */
if(!s->budget--) { s->failed_pc=0x0c0c81a2u; return 0; }
cond=r[17]&1u;
r[5]=r[5]&255u;
if(!cond) { goto P_0c0c81ac; }
goto P_0c0c81a6;
P_0c0c81a4: /* original 655c, guest PC 0x0c0c81a4 */
if(!s->budget--) { s->failed_pc=0x0c0c81a4u; return 0; }
r[5]=r[5]&255u;
goto P_0c0c81a6;
P_0c0c81a6: /* original 9255, guest PC 0x0c0c81a6 */
if(!s->budget--) { s->failed_pc=0x0c0c81a6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8254u,2);
goto P_0c0c81a8;
P_0c0c81a8: /* original 2728, guest PC 0x0c0c81a8 */
if(!s->budget--) { s->failed_pc=0x0c0c81a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[2])==0)!=0);
goto P_0c0c81aa;
P_0c0c81aa: /* original 8948, guest PC 0x0c0c81aa */
if(!s->budget--) { s->failed_pc=0x0c0c81aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c823e; }
goto P_0c0c81ac;
P_0c0c81ac: /* original 9053, guest PC 0x0c0c81ac */
if(!s->budget--) { s->failed_pc=0x0c0c81acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8256u,2);
goto P_0c0c81ae;
P_0c0c81ae: /* original e33f, guest PC 0x0c0c81ae */
if(!s->budget--) { s->failed_pc=0x0c0c81aeu; return 0; }
r[3]=0x0000003fu;
goto P_0c0c81b0;
P_0c0c81b0: /* original 2e39, guest PC 0x0c0c81b0 */
if(!s->budget--) { s->failed_pc=0x0c0c81b0u; return 0; }
r[14]&=r[3];
goto P_0c0c81b2;
P_0c0c81b2: /* original 076c, guest PC 0x0c0c81b2 */
if(!s->budget--) { s->failed_pc=0x0c0c81b2u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0c81b4;
P_0c0c81b4: /* original 37ec, guest PC 0x0c0c81b4 */
if(!s->budget--) { s->failed_pc=0x0c0c81b4u; return 0; }
r[7]+=r[14];
goto P_0c0c81b6;
P_0c0c81b6: /* original 0674, guest PC 0x0c0c81b6 */
if(!s->budget--) { s->failed_pc=0x0c0c81b6u; return 0; }
write(ram,r[6]+r[0],r[7],1);
goto P_0c0c81b8;
P_0c0c81b8: /* original 904e, guest PC 0x0c0c81b8 */
if(!s->budget--) { s->failed_pc=0x0c0c81b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8258u,2);
goto P_0c0c81ba;
P_0c0c81ba: /* original 026c, guest PC 0x0c0c81ba */
if(!s->budget--) { s->failed_pc=0x0c0c81bau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0c81bc;
P_0c0c81bc: /* original 2f22, guest PC 0x0c0c81bc */
if(!s->budget--) { s->failed_pc=0x0c0c81bcu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c81be;
P_0c0c81be: /* original 6e23, guest PC 0x0c0c81be */
if(!s->budget--) { s->failed_pc=0x0c0c81beu; return 0; }
r[14]=r[2];
goto P_0c0c81c0;
P_0c0c81c0: /* original 5062, guest PC 0x0c0c81c0 */
if(!s->budget--) { s->failed_pc=0x0c0c81c0u; return 0; }
r[0]=read(ram,r[6]+8,4);
goto P_0c0c81c2;
P_0c0c81c2: /* original c804, guest PC 0x0c0c81c2 */
if(!s->budget--) { s->failed_pc=0x0c0c81c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0c81c4;
P_0c0c81c4: /* original 8f0e, guest PC 0x0c0c81c4 */
if(!s->budget--) { s->failed_pc=0x0c0c81c4u; return 0; }
cond=r[17]&1u;
r[14]+=0xffffffffu;
if(!cond) { goto P_0c0c81e4; }
goto P_0c0c81c8;
P_0c0c81c6: /* original 7eff, guest PC 0x0c0c81c6 */
if(!s->budget--) { s->failed_pc=0x0c0c81c6u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0c81c8;
P_0c0c81c8: /* original 9047, guest PC 0x0c0c81c8 */
if(!s->budget--) { s->failed_pc=0x0c0c81c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c825au,2);
goto P_0c0c81ca;
P_0c0c81ca: /* original 2ee8, guest PC 0x0c0c81ca */
if(!s->budget--) { s->failed_pc=0x0c0c81cau; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c81cc;
P_0c0c81cc: /* original 004e, guest PC 0x0c0c81cc */
if(!s->budget--) { s->failed_pc=0x0c0c81ccu; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c0c81ce;
P_0c0c81ce: /* original c910, guest PC 0x0c0c81ce */
if(!s->budget--) { s->failed_pc=0x0c0c81ceu; return 0; }
r[0]&=16u;
goto P_0c0c81d0;
P_0c0c81d0: /* original 8f04, guest PC 0x0c0c81d0 */
if(!s->budget--) { s->failed_pc=0x0c0c81d0u; return 0; }
cond=r[17]&1u;
r[7]=r[0];
if(!cond) { goto P_0c0c81dc; }
goto P_0c0c81d4;
P_0c0c81d2: /* original 6703, guest PC 0x0c0c81d2 */
if(!s->budget--) { s->failed_pc=0x0c0c81d2u; return 0; }
r[7]=r[0];
goto P_0c0c81d4;
P_0c0c81d4: /* original 9041, guest PC 0x0c0c81d4 */
if(!s->budget--) { s->failed_pc=0x0c0c81d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c825au,2);
goto P_0c0c81d6;
P_0c0c81d6: /* original 004e, guest PC 0x0c0c81d6 */
if(!s->budget--) { s->failed_pc=0x0c0c81d6u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c0c81d8;
P_0c0c81d8: /* original c920, guest PC 0x0c0c81d8 */
if(!s->budget--) { s->failed_pc=0x0c0c81d8u; return 0; }
r[0]&=32u;
goto P_0c0c81da;
P_0c0c81da: /* original 6703, guest PC 0x0c0c81da */
if(!s->budget--) { s->failed_pc=0x0c0c81dau; return 0; }
r[7]=r[0];
goto P_0c0c81dc;
P_0c0c81dc: /* original 2778, guest PC 0x0c0c81dc */
if(!s->budget--) { s->failed_pc=0x0c0c81dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c81de;
P_0c0c81de: /* original 8927, guest PC 0x0c0c81de */
if(!s->budget--) { s->failed_pc=0x0c0c81deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8230; }
goto P_0c0c81e0;
P_0c0c81e0: /* original a027, guest PC 0x0c0c81e0 */
if(!s->budget--) { s->failed_pc=0x0c0c81e0u; return 0; }
goto P_0c0c8232;
P_0c0c81e2: /* original 0009, guest PC 0x0c0c81e2 */
if(!s->budget--) { s->failed_pc=0x0c0c81e2u; return 0; }
goto P_0c0c81e4;
P_0c0c81e4: /* original 2cc8, guest PC 0x0c0c81e4 */
if(!s->budget--) { s->failed_pc=0x0c0c81e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0c81e6;
P_0c0c81e6: /* original 8b1b, guest PC 0x0c0c81e6 */
if(!s->budget--) { s->failed_pc=0x0c0c81e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8220; }
goto P_0c0c81e8;
P_0c0c81e8: /* original 9037, guest PC 0x0c0c81e8 */
if(!s->budget--) { s->failed_pc=0x0c0c81e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c825au,2);
goto P_0c0c81ea;
P_0c0c81ea: /* original 2ee8, guest PC 0x0c0c81ea */
if(!s->budget--) { s->failed_pc=0x0c0c81eau; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c81ec;
P_0c0c81ec: /* original 004e, guest PC 0x0c0c81ec */
if(!s->budget--) { s->failed_pc=0x0c0c81ecu; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c0c81ee;
P_0c0c81ee: /* original c910, guest PC 0x0c0c81ee */
if(!s->budget--) { s->failed_pc=0x0c0c81eeu; return 0; }
r[0]&=16u;
goto P_0c0c81f0;
P_0c0c81f0: /* original 8f06, guest PC 0x0c0c81f0 */
if(!s->budget--) { s->failed_pc=0x0c0c81f0u; return 0; }
cond=r[17]&1u;
r[11]=r[0];
if(!cond) { goto P_0c0c8200; }
goto P_0c0c81f4;
P_0c0c81f2: /* original 6b03, guest PC 0x0c0c81f2 */
if(!s->budget--) { s->failed_pc=0x0c0c81f2u; return 0; }
r[11]=r[0];
goto P_0c0c81f4;
P_0c0c81f4: /* original 2cc8, guest PC 0x0c0c81f4 */
if(!s->budget--) { s->failed_pc=0x0c0c81f4u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0c81f6;
P_0c0c81f6: /* original 8b13, guest PC 0x0c0c81f6 */
if(!s->budget--) { s->failed_pc=0x0c0c81f6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8220; }
goto P_0c0c81f8;
P_0c0c81f8: /* original 902f, guest PC 0x0c0c81f8 */
if(!s->budget--) { s->failed_pc=0x0c0c81f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c825au,2);
goto P_0c0c81fa;
P_0c0c81fa: /* original 004e, guest PC 0x0c0c81fa */
if(!s->budget--) { s->failed_pc=0x0c0c81fau; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c0c81fc;
P_0c0c81fc: /* original c920, guest PC 0x0c0c81fc */
if(!s->budget--) { s->failed_pc=0x0c0c81fcu; return 0; }
r[0]&=32u;
goto P_0c0c81fe;
P_0c0c81fe: /* original 6b03, guest PC 0x0c0c81fe */
if(!s->budget--) { s->failed_pc=0x0c0c81feu; return 0; }
r[11]=r[0];
goto P_0c0c8200;
P_0c0c8200: /* original 2bb8, guest PC 0x0c0c8200 */
if(!s->budget--) { s->failed_pc=0x0c0c8200u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0c8202;
P_0c0c8202: /* original 8916, guest PC 0x0c0c8202 */
if(!s->budget--) { s->failed_pc=0x0c0c8202u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8232; }
goto P_0c0c8204;
P_0c0c8204: /* original e311, guest PC 0x0c0c8204 */
if(!s->budget--) { s->failed_pc=0x0c0c8204u; return 0; }
r[3]=0x00000011u;
goto P_0c0c8206;
P_0c0c8206: /* original 6173, guest PC 0x0c0c8206 */
if(!s->budget--) { s->failed_pc=0x0c0c8206u; return 0; }
r[1]=r[7];
goto P_0c0c8208;
P_0c0c8208: /* original 2f32, guest PC 0x0c0c8208 */
if(!s->budget--) { s->failed_pc=0x0c0c8208u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c820a;
P_0c0c820a: /* original d216, guest PC 0x0c0c820a */
if(!s->budget--) { s->failed_pc=0x0c0c820au; return 0; }
r[2]=read(ram,0x0c0c8264u,4);
goto P_0c0c820c;
P_0c0c820c: /* original 420b, guest PC 0x0c0c820c */
if(!s->budget--) { s->failed_pc=0x0c0c820cu; return 0; }
target=r[2];
r[16]=0x0c0c8210u;
r[0]=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c8210u) { target=s->pc; goto dispatch; }
goto P_0c0c8210;
P_0c0c820e: /* original 6033, guest PC 0x0c0c820e */
if(!s->budget--) { s->failed_pc=0x0c0c820eu; return 0; }
r[0]=r[3];
goto P_0c0c8210;
P_0c0c8210: /* original 6303, guest PC 0x0c0c8210 */
if(!s->budget--) { s->failed_pc=0x0c0c8210u; return 0; }
r[3]=r[0];
goto P_0c0c8212;
P_0c0c8212: /* original 2f02, guest PC 0x0c0c8212 */
if(!s->budget--) { s->failed_pc=0x0c0c8212u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0c8214;
P_0c0c8214: /* original 4008, guest PC 0x0c0c8214 */
if(!s->budget--) { s->failed_pc=0x0c0c8214u; return 0; }
r[0]<<=2;
goto P_0c0c8216;
P_0c0c8216: /* original 4008, guest PC 0x0c0c8216 */
if(!s->budget--) { s->failed_pc=0x0c0c8216u; return 0; }
r[0]<<=2;
goto P_0c0c8218;
P_0c0c8218: /* original 303c, guest PC 0x0c0c8218 */
if(!s->budget--) { s->failed_pc=0x0c0c8218u; return 0; }
r[0]+=r[3];
goto P_0c0c821a;
P_0c0c821a: /* original 3708, guest PC 0x0c0c821a */
if(!s->budget--) { s->failed_pc=0x0c0c821au; return 0; }
r[7]-=r[0];
goto P_0c0c821c;
P_0c0c821c: /* original 2778, guest PC 0x0c0c821c */
if(!s->budget--) { s->failed_pc=0x0c0c821cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c821e;
P_0c0c821e: /* original 8b07, guest PC 0x0c0c821e */
if(!s->budget--) { s->failed_pc=0x0c0c821eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8230; }
goto P_0c0c8220;
P_0c0c8220: /* original 6053, guest PC 0x0c0c8220 */
if(!s->budget--) { s->failed_pc=0x0c0c8220u; return 0; }
r[0]=r[5];
goto P_0c0c8222;
P_0c0c8222: /* original 8806, guest PC 0x0c0c8222 */
if(!s->budget--) { s->failed_pc=0x0c0c8222u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0c8224;
P_0c0c8224: /* original 8904, guest PC 0x0c0c8224 */
if(!s->budget--) { s->failed_pc=0x0c0c8224u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8230; }
goto P_0c0c8226;
P_0c0c8226: /* original 6053, guest PC 0x0c0c8226 */
if(!s->budget--) { s->failed_pc=0x0c0c8226u; return 0; }
r[0]=r[5];
goto P_0c0c8228;
P_0c0c8228: /* original 8804, guest PC 0x0c0c8228 */
if(!s->budget--) { s->failed_pc=0x0c0c8228u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0c822a;
P_0c0c822a: /* original 8901, guest PC 0x0c0c822a */
if(!s->budget--) { s->failed_pc=0x0c0c822au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c8230; }
goto P_0c0c822c;
P_0c0c822c: /* original a001, guest PC 0x0c0c822c */
if(!s->budget--) { s->failed_pc=0x0c0c822cu; return 0; }
r[5]+=0x00000010u;
goto P_0c0c8232;
P_0c0c822e: /* original 7510, guest PC 0x0c0c822e */
if(!s->budget--) { s->failed_pc=0x0c0c822eu; return 0; }
r[5]+=0x00000010u;
goto P_0c0c8230;
P_0c0c8230: /* original 7520, guest PC 0x0c0c8230 */
if(!s->budget--) { s->failed_pc=0x0c0c8230u; return 0; }
r[5]+=0x00000020u;
goto P_0c0c8232;
P_0c0c8232: /* original 9013, guest PC 0x0c0c8232 */
if(!s->budget--) { s->failed_pc=0x0c0c8232u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c825cu,2);
goto P_0c0c8234;
P_0c0c8234: /* original e33f, guest PC 0x0c0c8234 */
if(!s->budget--) { s->failed_pc=0x0c0c8234u; return 0; }
r[3]=0x0000003fu;
goto P_0c0c8236;
P_0c0c8236: /* original 0654, guest PC 0x0c0c8236 */
if(!s->budget--) { s->failed_pc=0x0c0c8236u; return 0; }
write(ram,r[6]+r[0],r[5],1);
goto P_0c0c8238;
P_0c0c8238: /* original 9011, guest PC 0x0c0c8238 */
if(!s->budget--) { s->failed_pc=0x0c0c8238u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c825eu,2);
goto P_0c0c823a;
P_0c0c823a: /* original 04d4, guest PC 0x0c0c823a */
if(!s->budget--) { s->failed_pc=0x0c0c823au; return 0; }
write(ram,r[4]+r[0],r[13],1);
goto P_0c0c823c;
P_0c0c823c: /* original 1433, guest PC 0x0c0c823c */
if(!s->budget--) { s->failed_pc=0x0c0c823cu; return 0; }
write(ram,r[4]+12,r[3],4);
goto P_0c0c823e;
P_0c0c823e: /* original 7f04, guest PC 0x0c0c823e */
if(!s->budget--) { s->failed_pc=0x0c0c823eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0c8240;
P_0c0c8240: /* original 4f26, guest PC 0x0c0c8240 */
if(!s->budget--) { s->failed_pc=0x0c0c8240u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c8242;
P_0c0c8242: /* original 69f6, guest PC 0x0c0c8242 */
if(!s->budget--) { s->failed_pc=0x0c0c8242u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c8244;
P_0c0c8244: /* original 6af6, guest PC 0x0c0c8244 */
if(!s->budget--) { s->failed_pc=0x0c0c8244u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c8246;
P_0c0c8246: /* original 6bf6, guest PC 0x0c0c8246 */
if(!s->budget--) { s->failed_pc=0x0c0c8246u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c8248;
P_0c0c8248: /* original 6cf6, guest PC 0x0c0c8248 */
if(!s->budget--) { s->failed_pc=0x0c0c8248u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c824a;
P_0c0c824a: /* original 6df6, guest PC 0x0c0c824a */
if(!s->budget--) { s->failed_pc=0x0c0c824au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c824c;
P_0c0c824c: /* original 000b, guest PC 0x0c0c824c */
if(!s->budget--) { s->failed_pc=0x0c0c824cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c824e: /* original 6ef6, guest PC 0x0c0c824e */
if(!s->budget--) { s->failed_pc=0x0c0c824eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c8250u,s,ram);
P_0c0c82e4: /* original 2fe6, guest PC 0x0c0c82e4 */
if(!s->budget--) { s->failed_pc=0x0c0c82e4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c82e6;
P_0c0c82e6: /* original 4f22, guest PC 0x0c0c82e6 */
if(!s->budget--) { s->failed_pc=0x0c0c82e6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c82e8;
P_0c0c82e8: /* original d426, guest PC 0x0c0c82e8 */
if(!s->budget--) { s->failed_pc=0x0c0c82e8u; return 0; }
r[4]=read(ram,0x0c0c8384u,4);
goto P_0c0c82ea;
P_0c0c82ea: /* original d322, guest PC 0x0c0c82ea */
if(!s->budget--) { s->failed_pc=0x0c0c82eau; return 0; }
r[3]=read(ram,0x0c0c8374u,4);
goto P_0c0c82ec;
P_0c0c82ec: /* original 7ffc, guest PC 0x0c0c82ec */
if(!s->budget--) { s->failed_pc=0x0c0c82ecu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c82ee;
P_0c0c82ee: /* original 2f32, guest PC 0x0c0c82ee */
if(!s->budget--) { s->failed_pc=0x0c0c82eeu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c82f0;
P_0c0c82f0: /* original 903d, guest PC 0x0c0c82f0 */
if(!s->budget--) { s->failed_pc=0x0c0c82f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c836eu,2);
goto P_0c0c82f2;
P_0c0c82f2: /* original 024c, guest PC 0x0c0c82f2 */
if(!s->budget--) { s->failed_pc=0x0c0c82f2u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c82f4;
P_0c0c82f4: /* original 70f8, guest PC 0x0c0c82f4 */
if(!s->budget--) { s->failed_pc=0x0c0c82f4u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c82f6;
P_0c0c82f6: /* original 034c, guest PC 0x0c0c82f6 */
if(!s->budget--) { s->failed_pc=0x0c0c82f6u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c82f8;
P_0c0c82f8: /* original 3230, guest PC 0x0c0c82f8 */
if(!s->budget--) { s->failed_pc=0x0c0c82f8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0c82fa;
P_0c0c82fa: /* original 8b04, guest PC 0x0c0c82fa */
if(!s->budget--) { s->failed_pc=0x0c0c82fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c8306; }
goto P_0c0c82fc;
P_0c0c82fc: /* original 7f04, guest PC 0x0c0c82fc */
if(!s->budget--) { s->failed_pc=0x0c0c82fcu; return 0; }
r[15]+=0x00000004u;
goto P_0c0c82fe;
P_0c0c82fe: /* original 4f26, guest PC 0x0c0c82fe */
if(!s->budget--) { s->failed_pc=0x0c0c82feu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c8300;
P_0c0c8300: /* original e400, guest PC 0x0c0c8300 */
if(!s->budget--) { s->failed_pc=0x0c0c8300u; return 0; }
r[4]=0x00000000u;
goto P_0c0c8302;
P_0c0c8302: /* original a00f, guest PC 0x0c0c8302 */
if(!s->budget--) { s->failed_pc=0x0c0c8302u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c8324;
P_0c0c8304: /* original 6ef6, guest PC 0x0c0c8304 */
if(!s->budget--) { s->failed_pc=0x0c0c8304u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c8306;
P_0c0c8306: /* original 9033, guest PC 0x0c0c8306 */
if(!s->budget--) { s->failed_pc=0x0c0c8306u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c8370u,2);
goto P_0c0c8308;
P_0c0c8308: /* original e320, guest PC 0x0c0c8308 */
if(!s->budget--) { s->failed_pc=0x0c0c8308u; return 0; }
r[3]=0x00000020u;
goto P_0c0c830a;
P_0c0c830a: /* original e608, guest PC 0x0c0c830a */
if(!s->budget--) { s->failed_pc=0x0c0c830au; return 0; }
r[6]=0x00000008u;
goto P_0c0c830c;
P_0c0c830c: /* original 0e4e, guest PC 0x0c0c830c */
if(!s->budget--) { s->failed_pc=0x0c0c830cu; return 0; }
r[14]=read(ram,r[4]+r[0],4);
goto P_0c0c830e;
P_0c0c830e: /* original e707, guest PC 0x0c0c830e */
if(!s->budget--) { s->failed_pc=0x0c0c830eu; return 0; }
r[7]=0x00000007u;
goto P_0c0c8310;
P_0c0c8310: /* original 2f36, guest PC 0x0c0c8310 */
if(!s->budget--) { s->failed_pc=0x0c0c8310u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8312;
P_0c0c8312: /* original d21d, guest PC 0x0c0c8312 */
if(!s->budget--) { s->failed_pc=0x0c0c8312u; return 0; }
r[2]=read(ram,0x0c0c8388u,4);
goto P_0c0c8314;
P_0c0c8314: /* original 65e3, guest PC 0x0c0c8314 */
if(!s->budget--) { s->failed_pc=0x0c0c8314u; return 0; }
r[5]=r[14];
goto P_0c0c8316;
P_0c0c8316: /* original 420b, guest PC 0x0c0c8316 */
if(!s->budget--) { s->failed_pc=0x0c0c8316u; return 0; }
target=r[2];
r[16]=0x0c0c831au;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c831au) { target=s->pc; goto dispatch; }
goto P_0c0c831a;
P_0c0c8318: /* original 54f1, guest PC 0x0c0c8318 */
if(!s->budget--) { s->failed_pc=0x0c0c8318u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c831a;
P_0c0c831a: /* original 7f08, guest PC 0x0c0c831a */
if(!s->budget--) { s->failed_pc=0x0c0c831au; return 0; }
r[15]+=0x00000008u;
goto P_0c0c831c;
P_0c0c831c: /* original 64e3, guest PC 0x0c0c831c */
if(!s->budget--) { s->failed_pc=0x0c0c831cu; return 0; }
r[4]=r[14];
goto P_0c0c831e;
P_0c0c831e: /* original 4f26, guest PC 0x0c0c831e */
if(!s->budget--) { s->failed_pc=0x0c0c831eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c8320;
P_0c0c8320: /* original a000, guest PC 0x0c0c8320 */
if(!s->budget--) { s->failed_pc=0x0c0c8320u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c8324;
P_0c0c8322: /* original 6ef6, guest PC 0x0c0c8322 */
if(!s->budget--) { s->failed_pc=0x0c0c8322u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c8324;
P_0c0c8324: /* original 2fe6, guest PC 0x0c0c8324 */
if(!s->budget--) { s->failed_pc=0x0c0c8324u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8326;
P_0c0c8326: /* original 2fd6, guest PC 0x0c0c8326 */
if(!s->budget--) { s->failed_pc=0x0c0c8326u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8328;
P_0c0c8328: /* original 2fc6, guest PC 0x0c0c8328 */
if(!s->budget--) { s->failed_pc=0x0c0c8328u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c832a;
P_0c0c832a: /* original 2fb6, guest PC 0x0c0c832a */
if(!s->budget--) { s->failed_pc=0x0c0c832au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c832c;
P_0c0c832c: /* original 2fa6, guest PC 0x0c0c832c */
if(!s->budget--) { s->failed_pc=0x0c0c832cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c832e;
P_0c0c832e: /* original 2f96, guest PC 0x0c0c832e */
if(!s->budget--) { s->failed_pc=0x0c0c832eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8330;
P_0c0c8330: /* original 2f86, guest PC 0x0c0c8330 */
if(!s->budget--) { s->failed_pc=0x0c0c8330u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c8332;
P_0c0c8332: /* original de14, guest PC 0x0c0c8332 */
if(!s->budget--) { s->failed_pc=0x0c0c8332u; return 0; }
r[14]=read(ram,0x0c0c8384u,4);
return vf3_matrix_family(0x0c0c8334u,s,ram);
P_0c0c94b2: /* original 4f22, guest PC 0x0c0c94b2 */
if(!s->budget--) { s->failed_pc=0x0c0c94b2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c94b4;
P_0c0c94b4: /* original d314, guest PC 0x0c0c94b4 */
if(!s->budget--) { s->failed_pc=0x0c0c94b4u; return 0; }
r[3]=read(ram,0x0c0c9508u,4);
goto P_0c0c94b6;
P_0c0c94b6: /* original de0d, guest PC 0x0c0c94b6 */
if(!s->budget--) { s->failed_pc=0x0c0c94b6u; return 0; }
r[14]=read(ram,0x0c0c94ecu,4);
goto P_0c0c94b8;
P_0c0c94b8: /* original dd0b, guest PC 0x0c0c94b8 */
if(!s->budget--) { s->failed_pc=0x0c0c94b8u; return 0; }
r[13]=read(ram,0x0c0c94e8u,4);
goto P_0c0c94ba;
P_0c0c94ba: /* original 430b, guest PC 0x0c0c94ba */
if(!s->budget--) { s->failed_pc=0x0c0c94bau; return 0; }
target=r[3];
r[16]=0x0c0c94beu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c94beu) { target=s->pc; goto dispatch; }
goto P_0c0c94be;
P_0c0c94bc: /* original 0009, guest PC 0x0c0c94bc */
if(!s->budget--) { s->failed_pc=0x0c0c94bcu; return 0; }
goto P_0c0c94be;
P_0c0c94be: /* original 900f, guest PC 0x0c0c94be */
if(!s->budget--) { s->failed_pc=0x0c0c94beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c94e0u,2);
goto P_0c0c94c0;
P_0c0c94c0: /* original e400, guest PC 0x0c0c94c0 */
if(!s->budget--) { s->failed_pc=0x0c0c94c0u; return 0; }
r[4]=0x00000000u;
goto P_0c0c94c2;
P_0c0c94c2: /* original e353, guest PC 0x0c0c94c2 */
if(!s->budget--) { s->failed_pc=0x0c0c94c2u; return 0; }
r[3]=0x00000053u;
goto P_0c0c94c4;
P_0c0c94c4: /* original 0e44, guest PC 0x0c0c94c4 */
if(!s->budget--) { s->failed_pc=0x0c0c94c4u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c94c6;
P_0c0c94c6: /* original 7001, guest PC 0x0c0c94c6 */
if(!s->budget--) { s->failed_pc=0x0c0c94c6u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c94c8;
P_0c0c94c8: /* original 0e44, guest PC 0x0c0c94c8 */
if(!s->budget--) { s->failed_pc=0x0c0c94c8u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c94ca;
P_0c0c94ca: /* original e010, guest PC 0x0c0c94ca */
if(!s->budget--) { s->failed_pc=0x0c0c94cau; return 0; }
r[0]=0x00000010u;
goto P_0c0c94cc;
P_0c0c94cc: /* original 0d34, guest PC 0x0c0c94cc */
if(!s->budget--) { s->failed_pc=0x0c0c94ccu; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c0c94ce;
P_0c0c94ce: /* original 84db, guest PC 0x0c0c94ce */
if(!s->budget--) { s->failed_pc=0x0c0c94ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+11,1);
goto P_0c0c94d0;
P_0c0c94d0: /* original 4f26, guest PC 0x0c0c94d0 */
if(!s->budget--) { s->failed_pc=0x0c0c94d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c94d2;
P_0c0c94d2: /* original 7001, guest PC 0x0c0c94d2 */
if(!s->budget--) { s->failed_pc=0x0c0c94d2u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c94d4;
P_0c0c94d4: /* original 80db, guest PC 0x0c0c94d4 */
if(!s->budget--) { s->failed_pc=0x0c0c94d4u; return 0; }
write(ram,r[13]+11,r[0],1);
goto P_0c0c94d6;
P_0c0c94d6: /* original d306, guest PC 0x0c0c94d6 */
if(!s->budget--) { s->failed_pc=0x0c0c94d6u; return 0; }
r[3]=read(ram,0x0c0c94f0u,4);
goto P_0c0c94d8;
P_0c0c94d8: /* original 6df6, guest PC 0x0c0c94d8 */
if(!s->budget--) { s->failed_pc=0x0c0c94d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c94da;
P_0c0c94da: /* original 432b, guest PC 0x0c0c94da */
if(!s->budget--) { s->failed_pc=0x0c0c94dau; return 0; }
target=r[3];
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
P_0c0c94dc: /* original 6ef6, guest PC 0x0c0c94dc */
if(!s->budget--) { s->failed_pc=0x0c0c94dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c94deu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c0356d4u,0x0c0356d6u,0x0c0356d8u,0x0c0356dau,0x0c0356dcu,0x0c0356deu,0x0c0356e0u,0x0c0356e2u,0x0c0356e4u,0x0c0356e6u,0x0c0356e8u,0x0c0356eau,0x0c0356ecu,0x0c0356eeu,0x0c0356f0u,0x0c0356f2u,
0x0c0356f4u,0x0c0356f6u,0x0c0356f8u,0x0c0356fau,0x0c0356fcu,0x0c0356feu,0x0c035700u,0x0c035702u,0x0c035704u,0x0c035706u,0x0c035708u,0x0c03570au,0x0c03570cu,0x0c03570eu,0x0c035710u,0x0c035712u,
0x0c035714u,0x0c035716u,0x0c035718u,0x0c03571au,0x0c03571cu,0x0c03571eu,0x0c035720u,0x0c035722u,0x0c035724u,0x0c035726u,0x0c035728u,0x0c03572au,0x0c03572cu,0x0c03572eu,0x0c035730u,0x0c035732u,
0x0c035734u,0x0c035736u,0x0c035738u,0x0c03573au,0x0c03573cu,0x0c03573eu,0x0c035740u,0x0c035742u,0x0c035744u,0x0c035746u,0x0c035748u,0x0c03574au,0x0c03574cu,0x0c03574eu,0x0c035750u,0x0c035752u,
0x0c035754u,0x0c035756u,0x0c035758u,0x0c03575au,0x0c03575cu,0x0c03575eu,0x0c035760u,0x0c035762u,0x0c035764u,0x0c035766u,0x0c035768u,0x0c03576au,0x0c03576cu,0x0c03576eu,0x0c035770u,0x0c035772u,
0x0c035774u,0x0c035776u,0x0c035778u,0x0c03577au,0x0c03577cu,0x0c03577eu,0x0c035780u,0x0c035782u,0x0c035784u,0x0c035786u,0x0c035788u,0x0c03578au,0x0c03578cu,0x0c03578eu,0x0c035790u,0x0c035792u,
0x0c035794u,0x0c035796u,0x0c035798u,0x0c03579au,0x0c03579cu,0x0c03579eu,0x0c0357a0u,0x0c0357a2u,0x0c0357a4u,0x0c0357a6u,0x0c0357a8u,0x0c0357aau,0x0c0357acu,0x0c0357aeu,0x0c0357b0u,0x0c0357b2u,
0x0c0357b4u,0x0c0357b6u,0x0c0357b8u,0x0c0357bau,0x0c038956u,0x0c038958u,0x0c03895au,0x0c03895cu,0x0c03895eu,0x0c038960u,0x0c038962u,0x0c038964u,0x0c038966u,0x0c038970u,0x0c038972u,0x0c038974u,
0x0c038976u,0x0c038978u,0x0c03897au,0x0c03897cu,0x0c03897eu,0x0c038980u,0x0c038982u,0x0c038984u,0x0c038986u,0x0c038988u,0x0c03898au,0x0c03898cu,0x0c03f5a0u,0x0c03f5a2u,0x0c03f5a4u,0x0c03f5a6u,
0x0c03f5a8u,0x0c03f5aau,0x0c03f5acu,0x0c03f5aeu,0x0c03f5b0u,0x0c03f5b2u,0x0c03f5b4u,0x0c03f5b6u,0x0c03f5b8u,0x0c03f5bau,0x0c03f5bcu,0x0c03f5beu,0x0c03f5c0u,0x0c03f5c2u,0x0c03f5d0u,0x0c03f5d2u,
0x0c03f5d4u,0x0c03f5d6u,0x0c03f5d8u,0x0c03f5dau,0x0c03f5dcu,0x0c03f5deu,0x0c03f5e0u,0x0c03f5e2u,0x0c03f5e4u,0x0c03f5e6u,0x0c03f5e8u,0x0c03f5eau,0x0c03f5ecu,0x0c03f5eeu,0x0c03f5f0u,0x0c03f5f2u,
0x0c03f5f4u,0x0c03f5f6u,0x0c03f5f8u,0x0c03f5fau,0x0c03f5fcu,0x0c03f5feu,0x0c03f600u,0x0c03f602u,0x0c03f604u,0x0c03f606u,0x0c03f608u,0x0c03f60au,0x0c03f60cu,0x0c03f60eu,0x0c03f610u,0x0c03f612u,
0x0c03f614u,0x0c03f616u,0x0c03f618u,0x0c03f61au,0x0c03f61cu,0x0c03f61eu,0x0c03f620u,0x0c03f622u,0x0c03f624u,0x0c03f626u,0x0c03f628u,0x0c03f62au,0x0c03f62cu,0x0c03f62eu,0x0c03f630u,0x0c03f632u,
0x0c03f634u,0x0c03f636u,0x0c03f638u,0x0c03f63au,0x0c03f63cu,0x0c03f63eu,0x0c03f640u,0x0c03f642u,0x0c03f644u,0x0c03f646u,0x0c03f648u,0x0c03f64au,0x0c03f64cu,0x0c03f64eu,0x0c03f650u,0x0c03f652u,
0x0c03f654u,0x0c03f656u,0x0c03f658u,0x0c03f65au,0x0c03f65cu,0x0c03f65eu,0x0c03f660u,0x0c03f662u,0x0c03f664u,0x0c03f666u,0x0c03f668u,0x0c03f66au,0x0c03f66cu,0x0c03f66eu,0x0c03f670u,0x0c03f672u,
0x0c03f674u,0x0c03f676u,0x0c03f678u,0x0c03f67au,0x0c03f67cu,0x0c03f67eu,0x0c03f680u,0x0c03f682u,0x0c03f684u,0x0c03fcf0u,0x0c03fcf2u,0x0c03fcf4u,0x0c03fcf6u,0x0c03fcf8u,0x0c03fcfau,0x0c03fcfcu,
0x0c03fcfeu,0x0c03fd00u,0x0c04326cu,0x0c04326eu,0x0c043270u,0x0c043272u,0x0c043274u,0x0c043276u,0x0c043278u,0x0c04327au,0x0c04327cu,0x0c04327eu,0x0c043280u,0x0c043282u,0x0c043284u,0x0c0433c6u,
0x0c0433c8u,0x0c0433cau,0x0c0433ccu,0x0c0433ceu,0x0c0433d0u,0x0c0433d2u,0x0c0433d4u,0x0c0433d6u,0x0c0433d8u,0x0c0433dau,0x0c0433dcu,0x0c0433deu,0x0c04341eu,0x0c043420u,0x0c043422u,0x0c043424u,
0x0c043426u,0x0c043428u,0x0c04342au,0x0c04342cu,0x0c04342eu,0x0c043430u,0x0c043432u,0x0c043434u,0x0c043436u,0x0c043438u,0x0c04343au,0x0c043440u,0x0c043442u,0x0c043444u,0x0c043446u,0x0c043448u,
0x0c04344au,0x0c04344cu,0x0c04344eu,0x0c043450u,0x0c043452u,0x0c043454u,0x0c043456u,0x0c043458u,0x0c04345au,0x0c04345cu,0x0c043472u,0x0c043474u,0x0c043476u,0x0c043478u,0x0c04347au,0x0c04347cu,
0x0c04347eu,0x0c043480u,0x0c043482u,0x0c043484u,0x0c043486u,0x0c043488u,0x0c04348au,0x0c04348eu,0x0c043490u,0x0c043492u,0x0c043494u,0x0c043496u,0x0c043498u,0x0c04349au,0x0c04349cu,0x0c04349eu,
0x0c0434a0u,0x0c0434a2u,0x0c0434a4u,0x0c0434a6u,0x0c0434aau,0x0c0434acu,0x0c0434aeu,0x0c0434b0u,0x0c0434b2u,0x0c0434b4u,0x0c0434b6u,0x0c0434b8u,0x0c0434bau,0x0c0434bcu,0x0c0434beu,0x0c0434c0u,
0x0c0434c2u,0x0c0434c4u,0x0c0434c6u,0x0c04bbf2u,0x0c04bbf4u,0x0c04bbf6u,0x0c04bbf8u,0x0c04bbfau,0x0c04bbfcu,0x0c04bbfeu,0x0c04bc00u,0x0c04bc02u,0x0c04bc04u,0x0c04bc06u,0x0c04bc08u,0x0c04bc0au,
0x0c04bc0cu,0x0c04bc0eu,0x0c04bc10u,0x0c04bc12u,0x0c04bc14u,0x0c04bc16u,0x0c04bc18u,0x0c04bc1au,0x0c04bc1cu,0x0c04bc1eu,0x0c04bc20u,0x0c04bc22u,0x0c04bc24u,0x0c04bc26u,0x0c04bc28u,0x0c04bc2au,
0x0c04bc2cu,0x0c04bc2eu,0x0c04bc30u,0x0c04bc32u,0x0c04bc34u,0x0c04bc36u,0x0c04bc38u,0x0c04bc3au,0x0c04bc3cu,0x0c04bc3eu,0x0c04bc40u,0x0c04bc42u,0x0c04bc44u,0x0c04bc46u,0x0c04bc48u,0x0c04bc4au,
0x0c04bc4cu,0x0c04bc4eu,0x0c04bc50u,0x0c04f8beu,0x0c04f8c0u,0x0c04f8c2u,0x0c04f8c4u,0x0c04f8c6u,0x0c04f8c8u,0x0c04f8cau,0x0c04f8ccu,0x0c04f8ceu,0x0c04f8d0u,0x0c04f8d2u,0x0c04f8d4u,0x0c04f8d6u,
0x0c04f8d8u,0x0c04f8dau,0x0c04f8dcu,0x0c04f8deu,0x0c04f8e0u,0x0c04f8e2u,0x0c04f8e4u,0x0c04f8e6u,0x0c04f8e8u,0x0c04f8eau,0x0c04f8ecu,0x0c04f8eeu,0x0c04f8f0u,0x0c04f8f2u,0x0c04f8f4u,0x0c04f8f6u,
0x0c04f8f8u,0x0c04f8fau,0x0c04f8fcu,0x0c04f8feu,0x0c04f900u,0x0c04f902u,0x0c04f904u,0x0c05fc14u,0x0c05fc16u,0x0c05fc18u,0x0c05fc1au,0x0c05fc1cu,0x0c05fc1eu,0x0c05fc20u,0x0c05fc22u,0x0c05fc24u,
0x0c05fc26u,0x0c05fc28u,0x0c05fc2au,0x0c05fc2cu,0x0c05fc2eu,0x0c06199cu,0x0c06199eu,0x0c0619a0u,0x0c0619a2u,0x0c0619a4u,0x0c0619a6u,0x0c0619a8u,0x0c0619aau,0x0c0619acu,0x0c0619aeu,0x0c0619b0u,
0x0c0619b2u,0x0c0619b4u,0x0c0619b6u,0x0c0619b8u,0x0c0619bau,0x0c0619bcu,0x0c0619beu,0x0c0619c0u,0x0c0619c2u,0x0c0619c4u,0x0c0619c6u,0x0c0619c8u,0x0c0619cau,0x0c0619ccu,0x0c0619ceu,0x0c0636feu,
0x0c063700u,0x0c0696e6u,0x0c0696e8u,0x0c0696eau,0x0c0696ecu,0x0c0696eeu,0x0c0696f0u,0x0c0696f2u,0x0c0696f4u,0x0c0696f6u,0x0c0696f8u,0x0c0696fau,0x0c0696fcu,0x0c0696feu,0x0c06a348u,0x0c06a34au,
0x0c06a34cu,0x0c06a34eu,0x0c06a350u,0x0c06a352u,0x0c06a354u,0x0c06a356u,0x0c06a358u,0x0c06a35au,0x0c06a35cu,0x0c06a35eu,0x0c06a360u,0x0c06a362u,0x0c06a364u,0x0c06a366u,0x0c06a368u,0x0c06a36au,
0x0c06a36cu,0x0c06a36eu,0x0c06a370u,0x0c06a372u,0x0c06a374u,0x0c06a376u,0x0c06a378u,0x0c06a37au,0x0c06a37cu,0x0c06a37eu,0x0c06a380u,0x0c06a382u,0x0c06a384u,0x0c06a386u,0x0c06a388u,0x0c06a38au,
0x0c06a38cu,0x0c06a38eu,0x0c06a390u,0x0c06a392u,0x0c06a394u,0x0c06a396u,0x0c06a398u,0x0c06a39au,0x0c06a39cu,0x0c06a39eu,0x0c06a3a0u,0x0c06a3a2u,0x0c06a3a4u,0x0c06a3a6u,0x0c06a3a8u,0x0c06a3aau,
0x0c06a3acu,0x0c06a3aeu,0x0c06a3b0u,0x0c06a3b2u,0x0c06a3b4u,0x0c06a3b6u,0x0c06a3b8u,0x0c06a3bau,0x0c06a3bcu,0x0c06a3beu,0x0c06a3c0u,0x0c06a3c2u,0x0c06a3c4u,0x0c06a3c6u,0x0c06a3c8u,0x0c06a3cau,
0x0c06a3ccu,0x0c06a3ceu,0x0c06a3d0u,0x0c06a3d2u,0x0c06a3d4u,0x0c06a3d6u,0x0c06a3d8u,0x0c06a3dau,0x0c06a3dcu,0x0c06a3deu,0x0c06a3e0u,0x0c06a3e2u,0x0c06a3e4u,0x0c06a3e6u,0x0c06a3e8u,0x0c06a3eau,
0x0c06a3ecu,0x0c06a3eeu,0x0c06a3f0u,0x0c06a3f2u,0x0c06a3f4u,0x0c06a3f6u,0x0c06a3f8u,0x0c06a3fau,0x0c06a3fcu,0x0c06a3feu,0x0c06a400u,0x0c06a402u,0x0c06a404u,0x0c06a406u,0x0c06a408u,0x0c06a40au,
0x0c06a40cu,0x0c06a40eu,0x0c06a410u,0x0c06a412u,0x0c06a414u,0x0c06a416u,0x0c06a418u,0x0c06a41au,0x0c06a41cu,0x0c06a41eu,0x0c06a420u,0x0c06a422u,0x0c06a424u,0x0c06a426u,0x0c06a428u,0x0c06a42au,
0x0c06a42cu,0x0c06a42eu,0x0c06a430u,0x0c06a432u,0x0c06a434u,0x0c06a436u,0x0c06a438u,0x0c06a43au,0x0c06a43cu,0x0c06a43eu,0x0c06a440u,0x0c06a442u,0x0c06a444u,0x0c06a446u,0x0c06a448u,0x0c06a44au,
0x0c06a44cu,0x0c06a44eu,0x0c06a450u,0x0c06a480u,0x0c06a482u,0x0c06a484u,0x0c06a486u,0x0c06a488u,0x0c06a48au,0x0c06a48cu,0x0c06a48eu,0x0c06a490u,0x0c06a492u,0x0c06a494u,0x0c06a496u,0x0c06a498u,
0x0c06a49au,0x0c06a49cu,0x0c06a49eu,0x0c06a4a0u,0x0c06a4a2u,0x0c06a4a4u,0x0c06a4a6u,0x0c06a4a8u,0x0c06a4aau,0x0c06a4acu,0x0c06a4aeu,0x0c06a4b0u,0x0c06a4b2u,0x0c06a4b4u,0x0c06a4b6u,0x0c06a4b8u,
0x0c06a4bau,0x0c06a4bcu,0x0c06a4beu,0x0c06a4c0u,0x0c06a4c2u,0x0c06a4c4u,0x0c06a4c6u,0x0c06a4c8u,0x0c06a4cau,0x0c06a4ccu,0x0c06a4ceu,0x0c06a4d0u,0x0c06a4d2u,0x0c06a4d4u,0x0c06a4d6u,0x0c06a4d8u,
0x0c06a4dau,0x0c06a4dcu,0x0c06a4deu,0x0c06a4e0u,0x0c06a4e2u,0x0c06a4e4u,0x0c06a4e6u,0x0c06a4e8u,0x0c06a4eau,0x0c06a4ecu,0x0c06a4eeu,0x0c06a4f0u,0x0c06a4f2u,0x0c06a4f4u,0x0c06a4f6u,0x0c06a4f8u,
0x0c06a4fau,0x0c06a4fcu,0x0c06a4feu,0x0c06a500u,0x0c06a502u,0x0c06a504u,0x0c06a506u,0x0c06a508u,0x0c06a50au,0x0c06a50cu,0x0c06a50eu,0x0c06a510u,0x0c06a512u,0x0c06a514u,0x0c06a516u,0x0c06a518u,
0x0c06a51au,0x0c06a51cu,0x0c06a51eu,0x0c06a520u,0x0c06a522u,0x0c06a524u,0x0c06a526u,0x0c06a528u,0x0c06a52au,0x0c06a52cu,0x0c06a52eu,0x0c06a530u,0x0c06a532u,0x0c06a534u,0x0c06a536u,0x0c06a538u,
0x0c06a53au,0x0c06a53cu,0x0c06a53eu,0x0c06a540u,0x0c06a542u,0x0c06a544u,0x0c06a546u,0x0c06a548u,0x0c06a54au,0x0c06a54cu,0x0c06a54eu,0x0c06a550u,0x0c06a552u,0x0c06a554u,0x0c06a556u,0x0c06a558u,
0x0c06a55au,0x0c06a55cu,0x0c06a55eu,0x0c06a560u,0x0c06a562u,0x0c06a564u,0x0c06a566u,0x0c06a568u,0x0c06a56au,0x0c06a56cu,0x0c06a56eu,0x0c06a570u,0x0c06a572u,0x0c06a574u,0x0c06a576u,0x0c06a578u,
0x0c06a57au,0x0c06a57cu,0x0c06a57eu,0x0c06a580u,0x0c06a582u,0x0c06a584u,0x0c06a586u,0x0c06a588u,0x0c06a58au,0x0c06a58cu,0x0c06a58eu,0x0c06a590u,0x0c06a592u,0x0c06a594u,0x0c06a596u,0x0c06a598u,
0x0c06a59au,0x0c06a59cu,0x0c06a59eu,0x0c06a5a0u,0x0c06a5a2u,0x0c06a5a4u,0x0c06a5a6u,0x0c06a5a8u,0x0c06a5aau,0x0c06a5acu,0x0c06a5aeu,0x0c06a5b0u,0x0c06a5b2u,0x0c06a5b4u,0x0c06a5b6u,0x0c06a5b8u,
0x0c06a5bau,0x0c06a5bcu,0x0c06a5beu,0x0c06a5c0u,0x0c06a5c2u,0x0c06ada0u,0x0c06ada2u,0x0c06ada4u,0x0c06ada6u,0x0c06ada8u,0x0c06adaau,0x0c06adacu,0x0c06adaeu,0x0c06adb0u,0x0c06adb2u,0x0c06adb4u,
0x0c06adb6u,0x0c06adb8u,0x0c06adbau,0x0c06adbcu,0x0c06adbeu,0x0c06adc0u,0x0c06adc2u,0x0c06adc4u,0x0c06adc6u,0x0c06adc8u,0x0c06adcau,0x0c06adccu,0x0c06adf4u,0x0c06adf6u,0x0c06adf8u,0x0c06adfau,
0x0c06adfcu,0x0c06adfeu,0x0c06ae00u,0x0c06ae02u,0x0c06ae04u,0x0c06ae06u,0x0c06ae08u,0x0c06ae0au,0x0c06ae0cu,0x0c06ae0eu,0x0c06ae10u,0x0c06ae12u,0x0c06ae14u,0x0c06ae16u,0x0c06ae18u,0x0c06ae1au,
0x0c06ae1cu,0x0c06ae1eu,0x0c06ae20u,0x0c06ae22u,0x0c06ae24u,0x0c06ae26u,0x0c06ae28u,0x0c06ae2au,0x0c06ae2cu,0x0c06ae2eu,0x0c06ae30u,0x0c06ae32u,0x0c06ae34u,0x0c06ae36u,0x0c06ae38u,0x0c06ae3au,
0x0c06ae3cu,0x0c06ae3eu,0x0c06ae40u,0x0c06ae42u,0x0c06ae44u,0x0c06ae46u,0x0c06ae48u,0x0c06ae4au,0x0c06ae4cu,0x0c06ae4eu,0x0c06ae50u,0x0c06ae52u,0x0c06ae54u,0x0c06ae56u,0x0c06ae58u,0x0c06ae5au,
0x0c06ae5cu,0x0c06ae5eu,0x0c06ae60u,0x0c06ae62u,0x0c06ae64u,0x0c06ae66u,0x0c06ae68u,0x0c06ae6au,0x0c06ae6cu,0x0c06ae6eu,0x0c06ae70u,0x0c06ae72u,0x0c06ae74u,0x0c06ae76u,0x0c06ae78u,0x0c06ae7au,
0x0c06ae7cu,0x0c06ae7eu,0x0c06ae80u,0x0c06ae82u,0x0c06ae84u,0x0c06ae86u,0x0c06ae88u,0x0c06ae8au,0x0c06ae8cu,0x0c06ae8eu,0x0c06ae90u,0x0c06ae92u,0x0c06ae94u,0x0c06ae96u,0x0c06ae98u,0x0c06ae9au,
0x0c06ae9cu,0x0c06ae9eu,0x0c06aea0u,0x0c06aea2u,0x0c06aea4u,0x0c06aea6u,0x0c06aea8u,0x0c06aeaau,0x0c06aeacu,0x0c06aeaeu,0x0c06aeb0u,0x0c06aeb2u,0x0c06aeb4u,0x0c06aeb6u,0x0c06aeb8u,0x0c06aebau,
0x0c06aebcu,0x0c06aebeu,0x0c06aec0u,0x0c06aec2u,0x0c06aec4u,0x0c06aec6u,0x0c06aec8u,0x0c06aecau,0x0c06aeccu,0x0c06aeceu,0x0c06aed0u,0x0c06aed2u,0x0c06aed4u,0x0c06aed6u,0x0c06aed8u,0x0c06aedau,
0x0c06aedcu,0x0c06aefcu,0x0c06aefeu,0x0c06af00u,0x0c06af02u,0x0c06af04u,0x0c06af06u,0x0c06af08u,0x0c06af0au,0x0c06af0cu,0x0c06af0eu,0x0c06af10u,0x0c06af12u,0x0c06af14u,0x0c06af16u,0x0c06af18u,
0x0c06af1au,0x0c06af1cu,0x0c06af1eu,0x0c06af20u,0x0c06af22u,0x0c06af24u,0x0c06af26u,0x0c06af28u,0x0c06af2au,0x0c06af2cu,0x0c06af2eu,0x0c06af30u,0x0c06af32u,0x0c06af34u,0x0c06af36u,0x0c06af38u,
0x0c06af3au,0x0c06af3cu,0x0c06af3eu,0x0c06af40u,0x0c06af42u,0x0c06af44u,0x0c06af46u,0x0c06af48u,0x0c06af4au,0x0c06af4cu,0x0c06af4eu,0x0c06af50u,0x0c06af52u,0x0c06af54u,0x0c06af56u,0x0c06af58u,
0x0c06af5au,0x0c06af5cu,0x0c06af5eu,0x0c06af60u,0x0c06af62u,0x0c06af64u,0x0c06af66u,0x0c06af68u,0x0c06af6au,0x0c06af6cu,0x0c06af6eu,0x0c06af70u,0x0c06af72u,0x0c06af74u,0x0c06af76u,0x0c06af78u,
0x0c06af7au,0x0c06af7cu,0x0c06af7eu,0x0c06af80u,0x0c06af82u,0x0c06af84u,0x0c06af86u,0x0c06af88u,0x0c06af8au,0x0c06af8cu,0x0c06af8eu,0x0c06af90u,0x0c06af92u,0x0c06af94u,0x0c06af96u,0x0c06af98u,
0x0c06af9au,0x0c06af9cu,0x0c06af9eu,0x0c06afa0u,0x0c06afa2u,0x0c06afa4u,0x0c06afa6u,0x0c06afa8u,0x0c06afaau,0x0c06afacu,0x0c06afaeu,0x0c06afb0u,0x0c06afb2u,0x0c06afb4u,0x0c06afb6u,0x0c06afb8u,
0x0c06afbau,0x0c06afbcu,0x0c06afbeu,0x0c06afc0u,0x0c06afc2u,0x0c06afc4u,0x0c06afc6u,0x0c06afc8u,0x0c06afcau,0x0c06afccu,0x0c06afceu,0x0c06afd0u,0x0c06afd2u,0x0c06afd4u,0x0c06afd6u,0x0c06afd8u,
0x0c06afdau,0x0c06afdcu,0x0c06afdeu,0x0c06afe0u,0x0c06afe2u,0x0c06afe4u,0x0c06afe6u,0x0c06afe8u,0x0c06afeau,0x0c06c398u,0x0c06c39au,0x0c06c39cu,0x0c06c39eu,0x0c06c3a0u,0x0c06c3a2u,0x0c06c3a4u,
0x0c06c3a6u,0x0c06c3a8u,0x0c06c3aau,0x0c06c3acu,0x0c06c3aeu,0x0c06c3b0u,0x0c06c3b2u,0x0c06c3b4u,0x0c06c3b6u,0x0c06c3b8u,0x0c06c3bau,0x0c06c3bcu,0x0c06c3beu,0x0c06c3c0u,0x0c06c3c2u,0x0c06c3c4u,
0x0c06c3c6u,0x0c06c3c8u,0x0c06c3cau,0x0c06c3ccu,0x0c06c3ceu,0x0c06c8a4u,0x0c06c8a6u,0x0c06c8a8u,0x0c06c8aau,0x0c06c8acu,0x0c06c8aeu,0x0c06c8b0u,0x0c06c8b2u,0x0c06c8b4u,0x0c06c8b6u,0x0c06c8b8u,
0x0c06c8bau,0x0c06c8bcu,0x0c06c8beu,0x0c06c8c0u,0x0c06c8c2u,0x0c06c8c4u,0x0c06c8c6u,0x0c06c8c8u,0x0c06c8cau,0x0c06c8ccu,0x0c06c8ceu,0x0c06c8d0u,0x0c06c8d2u,0x0c06c8d4u,0x0c06c8d6u,0x0c06c8d8u,
0x0c06c8dau,0x0c06c8dcu,0x0c06c8deu,0x0c06c8e0u,0x0c06c8e2u,0x0c06c8e4u,0x0c06c8e6u,0x0c06c8e8u,0x0c06c8eau,0x0c06c8ecu,0x0c06c8eeu,0x0c06c8f0u,0x0c06c8f2u,0x0c06c8f4u,0x0c06c914u,0x0c06c916u,
0x0c06c918u,0x0c06c91au,0x0c06c91cu,0x0c06c91eu,0x0c06c920u,0x0c06c922u,0x0c06c924u,0x0c06c926u,0x0c06c928u,0x0c06c92au,0x0c06c92cu,0x0c06c92eu,0x0c06c930u,0x0c06c932u,0x0c06c934u,0x0c06c936u,
0x0c06c938u,0x0c06c93au,0x0c06c93cu,0x0c06c93eu,0x0c06c940u,0x0c06c942u,0x0c06c944u,0x0c06c946u,0x0c06c948u,0x0c06c94au,0x0c06c94cu,0x0c06c94eu,0x0c06c950u,0x0c06c952u,0x0c06c954u,0x0c06c956u,
0x0c06c958u,0x0c06c95au,0x0c06c95cu,0x0c07a844u,0x0c07a846u,0x0c07a848u,0x0c07a84au,0x0c07a84cu,0x0c07a84eu,0x0c07a850u,0x0c07a852u,0x0c07a854u,0x0c07a856u,0x0c07a858u,0x0c07a85au,0x0c07a85cu,
0x0c07a85eu,0x0c07a860u,0x0c07a862u,0x0c07a864u,0x0c07a866u,0x0c07a868u,0x0c07a86au,0x0c07a86cu,0x0c07a86eu,0x0c07a870u,0x0c07a872u,0x0c07a874u,0x0c07a876u,0x0c07a878u,0x0c07a87au,0x0c07a87cu,
0x0c07a87eu,0x0c07a880u,0x0c07a882u,0x0c07a884u,0x0c07a886u,0x0c07a888u,0x0c07a88au,0x0c07a88cu,0x0c07a88eu,0x0c07a890u,0x0c07a892u,0x0c07a894u,0x0c07a896u,0x0c07a898u,0x0c07a89au,0x0c07a89cu,
0x0c07a89eu,0x0c07a8a0u,0x0c07a8a2u,0x0c07a8a4u,0x0c07a8a6u,0x0c07a8a8u,0x0c07a8aau,0x0c07a8acu,0x0c07a8aeu,0x0c07a8b0u,0x0c07a8b2u,0x0c07a8b4u,0x0c07a8b6u,0x0c07a8b8u,0x0c07a8bau,0x0c07a8bcu,
0x0c07a8beu,0x0c07a8c0u,0x0c07a8c2u,0x0c07a8c4u,0x0c07a8c6u,0x0c07a8c8u,0x0c07a8cau,0x0c07a8ccu,0x0c07a8ceu,0x0c07a8d0u,0x0c07a8d2u,0x0c07a8d4u,0x0c07a8d6u,0x0c07a8d8u,0x0c07a8dau,0x0c07a8dcu,
0x0c07a8deu,0x0c07a8e0u,0x0c07a8e2u,0x0c07a8e4u,0x0c07a8e6u,0x0c07a8e8u,0x0c07a8eau,0x0c07a8ecu,0x0c07a8eeu,0x0c07a8f0u,0x0c07a8f2u,0x0c07a8f4u,0x0c07a8f6u,0x0c07a8f8u,0x0c07a8fau,0x0c07a8fcu,
0x0c07a8feu,0x0c07a900u,0x0c07a902u,0x0c07a904u,0x0c07a906u,0x0c07a908u,0x0c07a90au,0x0c07a90cu,0x0c07a90eu,0x0c07a910u,0x0c07a912u,0x0c07a914u,0x0c07a916u,0x0c07a918u,0x0c07a91au,0x0c07a91cu,
0x0c07a91eu,0x0c07a920u,0x0c07a922u,0x0c07a924u,0x0c07a926u,0x0c07a928u,0x0c07a92au,0x0c07a92cu,0x0c07a92eu,0x0c07a930u,0x0c07a932u,0x0c07a934u,0x0c07a936u,0x0c07a938u,0x0c07a93au,0x0c07a93cu,
0x0c07a93eu,0x0c07a940u,0x0c07a942u,0x0c07a944u,0x0c07a946u,0x0c07a948u,0x0c07a94au,0x0c07a94cu,0x0c07a94eu,0x0c07a950u,0x0c07a952u,0x0c07a954u,0x0c07a956u,0x0c07a958u,0x0c07a95au,0x0c07a95cu,
0x0c07a95eu,0x0c07a960u,0x0c07a962u,0x0c07a964u,0x0c07a966u,0x0c07a968u,0x0c07a96au,0x0c07a96cu,0x0c07a96eu,0x0c07a970u,0x0c07a972u,0x0c07a974u,0x0c07a976u,0x0c07a978u,0x0c07a97au,0x0c07a97cu,
0x0c07a97eu,0x0c07a980u,0x0c07a982u,0x0c07a984u,0x0c07a986u,0x0c07a988u,0x0c07a98au,0x0c07a98cu,0x0c07a98eu,0x0c07a990u,0x0c07a992u,0x0c07a994u,0x0c07a996u,0x0c07a998u,0x0c07a99au,0x0c07a99cu,
0x0c07a99eu,0x0c07a9a0u,0x0c07a9a2u,0x0c07a9a4u,0x0c07a9a6u,0x0c07a9a8u,0x0c07a9aau,0x0c07a9acu,0x0c07a9aeu,0x0c07a9b0u,0x0c07a9b2u,0x0c07a9f8u,0x0c07a9fau,0x0c07a9fcu,0x0c07a9feu,0x0c07aa00u,
0x0c07aa02u,0x0c07aa04u,0x0c07aa06u,0x0c07aa08u,0x0c07aa0au,0x0c07aa0cu,0x0c07aa0eu,0x0c07aa10u,0x0c07aa12u,0x0c07aa14u,0x0c07aa16u,0x0c07aa18u,0x0c07aa1au,0x0c07aa1cu,0x0c07aa1eu,0x0c07aa20u,
0x0c07aa22u,0x0c07aa24u,0x0c07aa26u,0x0c07aa28u,0x0c07aa2au,0x0c07aa2cu,0x0c07aa2eu,0x0c07aa34u,0x0c07aa36u,0x0c07aa38u,0x0c07aa3au,0x0c07aa3cu,0x0c07aa3eu,0x0c07aa40u,0x0c07aa42u,0x0c07aa44u,
0x0c07aa46u,0x0c07aa48u,0x0c07aa4au,0x0c07aa4cu,0x0c07aa4eu,0x0c07aa50u,0x0c07aa52u,0x0c07aa54u,0x0c07aa56u,0x0c07aa58u,0x0c07d890u,0x0c07d892u,0x0c07d894u,0x0c07d896u,0x0c07d898u,0x0c07d89au,
0x0c07d89cu,0x0c07d89eu,0x0c07d8a0u,0x0c07d8a2u,0x0c07d8a4u,0x0c07d8a6u,0x0c07d8a8u,0x0c07d8aau,0x0c07d8acu,0x0c07d8aeu,0x0c07d8b0u,0x0c07d8b2u,0x0c07d8b4u,0x0c07d8b6u,0x0c07d8b8u,0x0c07d8bau,
0x0c07d8bcu,0x0c07d8beu,0x0c07d8c0u,0x0c07d8c2u,0x0c07d8c4u,0x0c07d8c6u,0x0c07d8c8u,0x0c07d8cau,0x0c07d8ccu,0x0c07d8ceu,0x0c07d8d0u,0x0c07d8d2u,0x0c07d8d4u,0x0c07d8d6u,0x0c07d8d8u,0x0c07d8dau,
0x0c07d8dcu,0x0c07d8deu,0x0c07d8e0u,0x0c07d8e2u,0x0c07d8e4u,0x0c07d8e6u,0x0c07d8e8u,0x0c07d8eau,0x0c07d8ecu,0x0c07e918u,0x0c07e91au,0x0c07e91cu,0x0c07e91eu,0x0c07e920u,0x0c07e922u,0x0c07e924u,
0x0c07e926u,0x0c07e928u,0x0c07e92au,0x0c07e92cu,0x0c07e92eu,0x0c07e930u,0x0c07e932u,0x0c07e934u,0x0c07e936u,0x0c07e938u,0x0c07e93au,0x0c07e93cu,0x0c07e93eu,0x0c07e940u,0x0c07e942u,0x0c07e944u,
0x0c07e946u,0x0c07e948u,0x0c07e94au,0x0c07e94cu,0x0c07e94eu,0x0c07e950u,0x0c07e952u,0x0c07e954u,0x0c07e956u,0x0c07e958u,0x0c07e95au,0x0c07e95cu,0x0c07e95eu,0x0c07e960u,0x0c07e962u,0x0c07e964u,
0x0c07e966u,0x0c07e968u,0x0c07e96au,0x0c07e96cu,0x0c07e96eu,0x0c07e970u,0x0c07e972u,0x0c07e974u,0x0c07e976u,0x0c07e978u,0x0c07e97au,0x0c07e97cu,0x0c07e97eu,0x0c07e980u,0x0c07e982u,0x0c07e984u,
0x0c07e986u,0x0c07e988u,0x0c07e98au,0x0c07e9dcu,0x0c07e9deu,0x0c07e9e0u,0x0c07e9e2u,0x0c07e9e4u,0x0c07e9e6u,0x0c07e9e8u,0x0c07e9eau,0x0c07e9ecu,0x0c07e9eeu,0x0c07e9f0u,0x0c07e9f2u,0x0c07e9f4u,
0x0c07e9f6u,0x0c07e9f8u,0x0c07e9fau,0x0c07e9fcu,0x0c07e9feu,0x0c07ea00u,0x0c07ea02u,0x0c07ea04u,0x0c07ea06u,0x0c07ea08u,0x0c07ea0au,0x0c07ea0cu,0x0c07ea0eu,0x0c07ea10u,0x0c07ea12u,0x0c07ea14u,
0x0c07ea16u,0x0c07ea18u,0x0c07ea1au,0x0c07ea1cu,0x0c07ea1eu,0x0c07ea20u,0x0c07ea22u,0x0c07ea24u,0x0c07ea26u,0x0c07ea28u,0x0c07ea2au,0x0c07ea2cu,0x0c07ea2eu,0x0c07ea30u,0x0c07ea32u,0x0c07ea34u,
0x0c07ea36u,0x0c07ea38u,0x0c07ea3au,0x0c07ea3cu,0x0c07ea3eu,0x0c07ea40u,0x0c07ea42u,0x0c07ea44u,0x0c07ea46u,0x0c07ea48u,0x0c07ea4au,0x0c07ea4cu,0x0c07ea4eu,0x0c07ea50u,0x0c07ea52u,0x0c07ea54u,
0x0c07ea56u,0x0c07ea58u,0x0c07ea5au,0x0c07ea5cu,0x0c07ea5eu,0x0c07ea60u,0x0c07ea62u,0x0c07ea64u,0x0c07ea66u,0x0c07ea68u,0x0c07ea6au,0x0c07ea6cu,0x0c07ea6eu,0x0c07ea70u,0x0c07ea72u,0x0c07ea74u,
0x0c07ea76u,0x0c07ea78u,0x0c07ea7au,0x0c07ea7cu,0x0c07ea7eu,0x0c07ea80u,0x0c07ea82u,0x0c07ea84u,0x0c07ea86u,0x0c07ea88u,0x0c07ea8au,0x0c07ea8cu,0x0c07ea8eu,0x0c07ea90u,0x0c07ea92u,0x0c07ea94u,
0x0c07ea96u,0x0c07ea98u,0x0c07ea9au,0x0c07ea9cu,0x0c07ea9eu,0x0c07eaa0u,0x0c07eaa2u,0x0c07eaa4u,0x0c07eaa6u,0x0c07eaa8u,0x0c07eaaau,0x0c07eaacu,0x0c07eaaeu,0x0c07eab0u,0x0c07eab2u,0x0c07eab4u,
0x0c07eab6u,0x0c07eab8u,0x0c07eabau,0x0c07eabcu,0x0c07eabeu,0x0c07eac0u,0x0c07eac2u,0x0c07eac4u,0x0c07eac6u,0x0c07f022u,0x0c07f024u,0x0c07f026u,0x0c07f028u,0x0c07f02au,0x0c07f02cu,0x0c07f02eu,
0x0c07f030u,0x0c07f032u,0x0c07f034u,0x0c07f036u,0x0c07f038u,0x0c07f03au,0x0c07f03cu,0x0c07f03eu,0x0c07f040u,0x0c07f042u,0x0c07f044u,0x0c07f046u,0x0c07f048u,0x0c07f04au,0x0c07f04cu,0x0c07f04eu,
0x0c07f050u,0x0c07f052u,0x0c07f054u,0x0c07f056u,0x0c07f058u,0x0c07f05au,0x0c07f05cu,0x0c07f05eu,0x0c07f060u,0x0c07f062u,0x0c07f064u,0x0c07f066u,0x0c07f068u,0x0c07f06au,0x0c07f06cu,0x0c07f06eu,
0x0c07f070u,0x0c07f072u,0x0c07f074u,0x0c07f076u,0x0c07f078u,0x0c07f07au,0x0c07f07cu,0x0c07f07eu,0x0c07f080u,0x0c07f082u,0x0c07f084u,0x0c07f086u,0x0c07f088u,0x0c0807d2u,0x0c0807d4u,0x0c0807d6u,
0x0c0807d8u,0x0c0807dau,0x0c0807dcu,0x0c0807deu,0x0c0807e0u,0x0c0807e2u,0x0c0807e4u,0x0c0807e6u,0x0c0807e8u,0x0c0807eau,0x0c0807ecu,0x0c0807eeu,0x0c0810c0u,0x0c0810c2u,0x0c0810c4u,0x0c0810c6u,
0x0c0810c8u,0x0c0810cau,0x0c0810ccu,0x0c0810ceu,0x0c0810d0u,0x0c0810d2u,0x0c0810d4u,0x0c0810d6u,0x0c0810d8u,0x0c0810dau,0x0c0810dcu,0x0c0810deu,0x0c0810e0u,0x0c0810e2u,0x0c0810e4u,0x0c0810e6u,
0x0c0810e8u,0x0c0810eau,0x0c0810ecu,0x0c0810eeu,0x0c0810f0u,0x0c081982u,0x0c081984u,0x0c081986u,0x0c081988u,0x0c08198au,0x0c08198cu,0x0c08198eu,0x0c081990u,0x0c081992u,0x0c081994u,0x0c081996u,
0x0c081998u,0x0c08199au,0x0c08199cu,0x0c08199eu,0x0c0819a0u,0x0c0819a2u,0x0c0819a4u,0x0c0819b0u,0x0c0819b2u,0x0c0819b4u,0x0c0819b6u,0x0c0819b8u,0x0c0819bau,0x0c0819bcu,0x0c0819beu,0x0c0819c0u,
0x0c0819c2u,0x0c0819c4u,0x0c0819c6u,0x0c0819c8u,0x0c0819cau,0x0c0819ccu,0x0c0819ceu,0x0c0819d0u,0x0c0819d2u,0x0c084aa2u,0x0c084aa4u,0x0c084aa6u,0x0c084aa8u,0x0c084aaau,0x0c084aacu,0x0c084aaeu,
0x0c084ab0u,0x0c084ab2u,0x0c084ab4u,0x0c084ab6u,0x0c084ab8u,0x0c084abau,0x0c084abcu,0x0c084abeu,0x0c084ac0u,0x0c084ac2u,0x0c084ac4u,0x0c084ac6u,0x0c084ac8u,0x0c084acau,0x0c084accu,0x0c084aceu,
0x0c084ad0u,0x0c084ad2u,0x0c084ad4u,0x0c084ad6u,0x0c084ad8u,0x0c084adau,0x0c084adcu,0x0c085cb4u,0x0c085cb6u,0x0c085cb8u,0x0c085cbau,0x0c085cbcu,0x0c085cbeu,0x0c085cc0u,0x0c085cc2u,0x0c085cc4u,
0x0c085cc6u,0x0c085cc8u,0x0c085ccau,0x0c085cccu,0x0c085cceu,0x0c085cd0u,0x0c085cd2u,0x0c085cd4u,0x0c085cd6u,0x0c085cd8u,0x0c085cdau,0x0c085cdcu,0x0c085cdeu,0x0c085ce0u,0x0c085ce2u,0x0c085ce4u,
0x0c085ce6u,0x0c085ce8u,0x0c085ceau,0x0c085cecu,0x0c085ceeu,0x0c085cf0u,0x0c085cf2u,0x0c085cf4u,0x0c085cf6u,0x0c085cf8u,0x0c085cfau,0x0c085cfcu,0x0c085cfeu,0x0c085d00u,0x0c085d02u,0x0c085d04u,
0x0c085d06u,0x0c085d08u,0x0c085d0au,0x0c085d0cu,0x0c085d0eu,0x0c085d10u,0x0c085d12u,0x0c085d14u,0x0c085d16u,0x0c085d18u,0x0c085d1au,0x0c085d1cu,0x0c085d1eu,0x0c085d20u,0x0c085d22u,0x0c085d24u,
0x0c085d26u,0x0c085d28u,0x0c085d2au,0x0c085d2cu,0x0c085d2eu,0x0c085d30u,0x0c085d32u,0x0c085d34u,0x0c085d36u,0x0c085d38u,0x0c085d3au,0x0c085d3cu,0x0c085d3eu,0x0c085d40u,0x0c085d42u,0x0c085d44u,
0x0c085d46u,0x0c085d48u,0x0c085d4au,0x0c085d4cu,0x0c085d4eu,0x0c085d50u,0x0c085d52u,0x0c085d54u,0x0c085d56u,0x0c085d58u,0x0c085d5au,0x0c085d5cu,0x0c085d7cu,0x0c085d7eu,0x0c085d80u,0x0c085d82u,
0x0c085d84u,0x0c085d86u,0x0c085d88u,0x0c085d8au,0x0c085d8cu,0x0c085d8eu,0x0c085d90u,0x0c085d92u,0x0c085d94u,0x0c085d96u,0x0c085d98u,0x0c085d9au,0x0c085d9cu,0x0c085d9eu,0x0c085da0u,0x0c085da2u,
0x0c085da4u,0x0c085da6u,0x0c085da8u,0x0c085daau,0x0c085dacu,0x0c085daeu,0x0c085db0u,0x0c085db2u,0x0c085db4u,0x0c085db6u,0x0c085db8u,0x0c085dbau,0x0c085dbcu,0x0c085dbeu,0x0c085dc0u,0x0c085dc2u,
0x0c085dc4u,0x0c085dc6u,0x0c085dc8u,0x0c085dcau,0x0c085dccu,0x0c085dceu,0x0c085dd0u,0x0c085dd2u,0x0c085dd4u,0x0c085dd6u,0x0c085dd8u,0x0c085ddau,0x0c085ddcu,0x0c085ddeu,0x0c085de0u,0x0c085de2u,
0x0c085de4u,0x0c085de6u,0x0c085de8u,0x0c085deau,0x0c085decu,0x0c085deeu,0x0c085df0u,0x0c085df2u,0x0c085df4u,0x0c085df6u,0x0c085df8u,0x0c085dfau,0x0c085dfcu,0x0c085dfeu,0x0c085e00u,0x0c085e02u,
0x0c085e04u,0x0c085e06u,0x0c085e08u,0x0c085e0au,0x0c085e0cu,0x0c085e0eu,0x0c085e10u,0x0c085e12u,0x0c085e14u,0x0c085e16u,0x0c085e18u,0x0c085e1au,0x0c085e1cu,0x0c085e1eu,0x0c085e20u,0x0c085e22u,
0x0c085e24u,0x0c085e26u,0x0c085e28u,0x0c085e2au,0x0c085e2cu,0x0c085e2eu,0x0c085e30u,0x0c085e32u,0x0c085e34u,0x0c085e36u,0x0c085e38u,0x0c085e3au,0x0c085e3cu,0x0c085e3eu,0x0c085e40u,0x0c085e42u,
0x0c085e44u,0x0c085e46u,0x0c085e48u,0x0c085e4au,0x0c085e4cu,0x0c085e4eu,0x0c085e50u,0x0c085e52u,0x0c085e54u,0x0c085e56u,0x0c085e58u,0x0c085e5au,0x0c085e5cu,0x0c085e5eu,0x0c085e60u,0x0c085e62u,
0x0c085e64u,0x0c085e66u,0x0c085e68u,0x0c085e6au,0x0c085e6cu,0x0c085e6eu,0x0c085e70u,0x0c085e72u,0x0c085e74u,0x0c085e76u,0x0c085e78u,0x0c085e7au,0x0c085e7cu,0x0c085e7eu,0x0c085e80u,0x0c085e82u,
0x0c085e84u,0x0c085e86u,0x0c085e88u,0x0c085e8au,0x0c085e8cu,0x0c085e8eu,0x0c085e90u,0x0c085e92u,0x0c085e94u,0x0c085e96u,0x0c085e98u,0x0c085e9au,0x0c085e9cu,0x0c085e9eu,0x0c085ea0u,0x0c085ea2u,
0x0c085ea4u,0x0c085ea6u,0x0c085ea8u,0x0c085eaau,0x0c085eacu,0x0c085eaeu,0x0c085eb0u,0x0c085eb2u,0x0c085eb4u,0x0c085eb6u,0x0c085eb8u,0x0c085ebau,0x0c085ebcu,0x0c085ebeu,0x0c085ec0u,0x0c085ec2u,
0x0c085ec4u,0x0c085ec6u,0x0c085ec8u,0x0c085ee0u,0x0c085ee2u,0x0c085ee4u,0x0c085ee6u,0x0c085ee8u,0x0c085eeau,0x0c085eecu,0x0c085eeeu,0x0c085ef0u,0x0c085ef2u,0x0c085ef4u,0x0c085ef6u,0x0c085ef8u,
0x0c085efau,0x0c085efcu,0x0c085efeu,0x0c085f00u,0x0c085f02u,0x0c085f04u,0x0c085f06u,0x0c085f08u,0x0c085f0au,0x0c085f0cu,0x0c085f0eu,0x0c085f10u,0x0c085f12u,0x0c085f14u,0x0c085f16u,0x0c085f18u,
0x0c085f1au,0x0c085f1cu,0x0c085f1eu,0x0c085f20u,0x0c085f22u,0x0c085f24u,0x0c085f26u,0x0c085f28u,0x0c085f2au,0x0c085f2cu,0x0c085f2eu,0x0c085f30u,0x0c085f32u,0x0c085f34u,0x0c085f36u,0x0c085f38u,
0x0c085f3au,0x0c085f3cu,0x0c085f3eu,0x0c085f40u,0x0c085f42u,0x0c085f44u,0x0c085f46u,0x0c085f48u,0x0c085f4au,0x0c085f4cu,0x0c085f4eu,0x0c085f50u,0x0c085f52u,0x0c085f54u,0x0c085f56u,0x0c085f58u,
0x0c085f5au,0x0c085f5cu,0x0c085f5eu,0x0c085f60u,0x0c085f62u,0x0c085f64u,0x0c085f66u,0x0c085f68u,0x0c085f6au,0x0c085f6cu,0x0c085f6eu,0x0c085f70u,0x0c085f72u,0x0c085f74u,0x0c085f76u,0x0c085f78u,
0x0c085f7au,0x0c085f7cu,0x0c085f7eu,0x0c085f80u,0x0c085f82u,0x0c085f84u,0x0c085f86u,0x0c085f88u,0x0c085f8au,0x0c085f8cu,0x0c085f8eu,0x0c085f90u,0x0c085f92u,0x0c085f94u,0x0c085f96u,0x0c085f98u,
0x0c085f9au,0x0c085f9cu,0x0c085f9eu,0x0c085fa0u,0x0c085fa2u,0x0c085fa4u,0x0c085fa6u,0x0c085fa8u,0x0c085faau,0x0c085facu,0x0c085faeu,0x0c085fb0u,0x0c085fb2u,0x0c085fb4u,0x0c085fb6u,0x0c085fb8u,
0x0c085fbau,0x0c085fbcu,0x0c085fbeu,0x0c085fc0u,0x0c085fc2u,0x0c085fc4u,0x0c085fc6u,0x0c085fc8u,0x0c085fcau,0x0c085fccu,0x0c085fceu,0x0c085fd0u,0x0c085fd2u,0x0c085fd4u,0x0c085fd6u,0x0c085fd8u,
0x0c085fdau,0x0c085fdcu,0x0c085fdeu,0x0c085fe0u,0x0c085fe2u,0x0c085fe4u,0x0c085fe6u,0x0c085fe8u,0x0c085feau,0x0c085fecu,0x0c085feeu,0x0c085ff0u,0x0c085ff2u,0x0c085ff4u,0x0c085ff6u,0x0c085ff8u,
0x0c085ffau,0x0c085ffcu,0x0c085ffeu,0x0c086000u,0x0c086002u,0x0c086004u,0x0c086006u,0x0c086008u,0x0c08600au,0x0c08600cu,0x0c08600eu,0x0c086010u,0x0c086012u,0x0c086014u,0x0c086016u,0x0c086018u,
0x0c08601au,0x0c08601cu,0x0c08601eu,0x0c086020u,0x0c086022u,0x0c086024u,0x0c086026u,0x0c086028u,0x0c08602au,0x0c08602cu,0x0c08602eu,0x0c086030u,0x0c08604cu,0x0c08604eu,0x0c086050u,0x0c086052u,
0x0c086054u,0x0c086056u,0x0c086058u,0x0c08605au,0x0c08605cu,0x0c08605eu,0x0c086060u,0x0c086062u,0x0c086064u,0x0c086066u,0x0c086068u,0x0c08606au,0x0c08606cu,0x0c08606eu,0x0c086070u,0x0c086072u,
0x0c086074u,0x0c086076u,0x0c086078u,0x0c08607au,0x0c08607cu,0x0c08607eu,0x0c086080u,0x0c086082u,0x0c086084u,0x0c086086u,0x0c086088u,0x0c08608au,0x0c08608cu,0x0c08608eu,0x0c086090u,0x0c086092u,
0x0c086094u,0x0c086096u,0x0c086098u,0x0c08609au,0x0c08609cu,0x0c08609eu,0x0c0860a0u,0x0c0860a2u,0x0c0860a4u,0x0c0860a6u,0x0c0860a8u,0x0c0860aau,0x0c0860acu,0x0c0860aeu,0x0c0860b0u,0x0c0860b2u,
0x0c0860b4u,0x0c0860b6u,0x0c0860b8u,0x0c0860bau,0x0c0860bcu,0x0c0860beu,0x0c0860c0u,0x0c08612cu,0x0c08612eu,0x0c086130u,0x0c086132u,0x0c086134u,0x0c086136u,0x0c086138u,0x0c08613au,0x0c08613cu,
0x0c08613eu,0x0c086140u,0x0c086142u,0x0c086144u,0x0c086146u,0x0c086148u,0x0c08614au,0x0c08614cu,0x0c08614eu,0x0c086150u,0x0c086152u,0x0c087190u,0x0c087192u,0x0c087194u,0x0c087196u,0x0c087198u,
0x0c08719au,0x0c08719cu,0x0c08719eu,0x0c0871a0u,0x0c0871a2u,0x0c0871a4u,0x0c0871a6u,0x0c0871a8u,0x0c0871aau,0x0c0871acu,0x0c0871aeu,0x0c0871b0u,0x0c0871b2u,0x0c0871b4u,0x0c0871b6u,0x0c0871b8u,
0x0c0871bau,0x0c0871bcu,0x0c0871beu,0x0c0871c0u,0x0c0871c2u,0x0c0871c4u,0x0c0871c6u,0x0c0871c8u,0x0c0871cau,0x0c0871ccu,0x0c0871ceu,0x0c0871d0u,0x0c0871d2u,0x0c0871d4u,0x0c0871d6u,0x0c0871d8u,
0x0c0871dau,0x0c0871dcu,0x0c0871deu,0x0c0871e0u,0x0c0871e2u,0x0c0871e4u,0x0c0875b0u,0x0c0875b2u,0x0c0875b4u,0x0c0875b6u,0x0c0875b8u,0x0c0875bau,0x0c0875bcu,0x0c0875beu,0x0c0875c0u,0x0c0875c2u,
0x0c0875c4u,0x0c0875c6u,0x0c0875c8u,0x0c0875cau,0x0c0875ccu,0x0c090fc0u,0x0c090fc2u,0x0c090fc4u,0x0c090fc6u,0x0c090fc8u,0x0c090fcau,0x0c090fccu,0x0c090fceu,0x0c090fd0u,0x0c090fd2u,0x0c090fd4u,
0x0c090fd6u,0x0c090fd8u,0x0c090fdau,0x0c090fdcu,0x0c090fdeu,0x0c090fe0u,0x0c090fe2u,0x0c090fe4u,0x0c090fe6u,0x0c090fe8u,0x0c090feau,0x0c090fecu,0x0c090feeu,0x0c090ff0u,0x0c090ff2u,0x0c090ff4u,
0x0c090ff6u,0x0c090ff8u,0x0c090ffau,0x0c090ffcu,0x0c090ffeu,0x0c091000u,0x0c091002u,0x0c091004u,0x0c091006u,0x0c091008u,0x0c09100au,0x0c09100cu,0x0c09100eu,0x0c091010u,0x0c091012u,0x0c091014u,
0x0c091016u,0x0c091018u,0x0c09101au,0x0c09101cu,0x0c09101eu,0x0c091020u,0x0c091022u,0x0c091024u,0x0c091026u,0x0c091048u,0x0c09104au,0x0c09104cu,0x0c09104eu,0x0c091050u,0x0c091052u,0x0c091054u,
0x0c091056u,0x0c091058u,0x0c09105au,0x0c09105cu,0x0c09105eu,0x0c091060u,0x0c091062u,0x0c091064u,0x0c091066u,0x0c091068u,0x0c09106au,0x0c09106cu,0x0c09106eu,0x0c091070u,0x0c091072u,0x0c091074u,
0x0c091076u,0x0c091078u,0x0c09107au,0x0c09107cu,0x0c09107eu,0x0c091080u,0x0c092210u,0x0c092212u,0x0c092214u,0x0c092216u,0x0c092218u,0x0c09221au,0x0c09221cu,0x0c09221eu,0x0c092220u,0x0c092222u,
0x0c092224u,0x0c092226u,0x0c092228u,0x0c09222au,0x0c09222cu,0x0c09222eu,0x0c094242u,0x0c094244u,0x0c094246u,0x0c094248u,0x0c09424au,0x0c09424cu,0x0c09424eu,0x0c094250u,0x0c094252u,0x0c094254u,
0x0c094256u,0x0c094258u,0x0c09425au,0x0c09425cu,0x0c09425eu,0x0c094260u,0x0c094262u,0x0c094264u,0x0c094266u,0x0c094268u,0x0c09426au,0x0c09426cu,0x0c09426eu,0x0c094270u,0x0c094272u,0x0c094274u,
0x0c094276u,0x0c094278u,0x0c09427au,0x0c09427cu,0x0c09427eu,0x0c094280u,0x0c094282u,0x0c094284u,0x0c094286u,0x0c094288u,0x0c09428au,0x0c09428cu,0x0c09428eu,0x0c094290u,0x0c094292u,0x0c094294u,
0x0c094296u,0x0c094298u,0x0c0978eeu,0x0c0978f0u,0x0c0978f2u,0x0c0978f4u,0x0c0978f6u,0x0c0978f8u,0x0c0978fau,0x0c0978fcu,0x0c0978feu,0x0c097900u,0x0c097902u,0x0c097904u,0x0c097906u,0x0c097908u,
0x0c09790au,0x0c09790cu,0x0c09790eu,0x0c097910u,0x0c09a992u,0x0c09a994u,0x0c09a996u,0x0c09a998u,0x0c09a99au,0x0c09a99cu,0x0c09a99eu,0x0c09a9a0u,0x0c09a9a2u,0x0c09a9a4u,0x0c09a9a6u,0x0c09a9a8u,
0x0c09a9aau,0x0c09a9acu,0x0c09a9aeu,0x0c09a9b0u,0x0c09a9b2u,0x0c09a9b4u,0x0c09a9b6u,0x0c09a9b8u,0x0c09a9bau,0x0c09a9bcu,0x0c09a9beu,0x0c09a9c0u,0x0c09a9c2u,0x0c09a9c4u,0x0c09a9c6u,0x0c09a9c8u,
0x0c09a9cau,0x0c09a9ccu,0x0c09a9ceu,0x0c09a9d0u,0x0c09a9d2u,0x0c09a9d4u,0x0c09a9d6u,0x0c09a9d8u,0x0c09a9dau,0x0c09a9dcu,0x0c09a9deu,0x0c09a9e0u,0x0c09a9e2u,0x0c09a9e4u,0x0c09a9e6u,0x0c09d38eu,
0x0c09d390u,0x0c09d392u,0x0c09d394u,0x0c09d396u,0x0c09d398u,0x0c09d39au,0x0c09d39cu,0x0c09d39eu,0x0c09d3a0u,0x0c09d3a2u,0x0c09d3a4u,0x0c09d3a6u,0x0c09d3a8u,0x0c09d3aau,0x0c09d3acu,0x0c09d3aeu,
0x0c09d3b0u,0x0c09d3b2u,0x0c09d3b4u,0x0c09d3b6u,0x0c09d3b8u,0x0c09d3bau,0x0c09d3bcu,0x0c09d3beu,0x0c09d3c0u,0x0c09d3c2u,0x0c09d3c4u,0x0c09d3c6u,0x0c09d3c8u,0x0c09d3cau,0x0c09d3ccu,0x0c09d3ceu,
0x0c09d3d0u,0x0c09d3d2u,0x0c09d3d4u,0x0c09d3d6u,0x0c09d3d8u,0x0c09d3dau,0x0c09d3dcu,0x0c09d3deu,0x0c09d3e0u,0x0c09d3e2u,0x0c09d3e4u,0x0c0abad8u,0x0c0abadau,0x0c0abadcu,0x0c0abadeu,0x0c0abae0u,
0x0c0abae2u,0x0c0abae4u,0x0c0abae6u,0x0c0abae8u,0x0c0abaeau,0x0c0abaecu,0x0c0abaeeu,0x0c0abaf0u,0x0c0abaf2u,0x0c0abaf4u,0x0c0abaf6u,0x0c0abaf8u,0x0c0abafau,0x0c0abafcu,0x0c0abafeu,0x0c0abb00u,
0x0c0abb02u,0x0c0abb04u,0x0c0abb06u,0x0c0abb08u,0x0c0abb0au,0x0c0abb0cu,0x0c0abb0eu,0x0c0abb10u,0x0c0abb12u,0x0c0abb14u,0x0c0abb16u,0x0c0abb18u,0x0c0abb1au,0x0c0abb1cu,0x0c0abb1eu,0x0c0abb20u,
0x0c0abb22u,0x0c0abb24u,0x0c0abb26u,0x0c0abb28u,0x0c0abb2au,0x0c0abb2cu,0x0c0abb2eu,0x0c0abb30u,0x0c0abb32u,0x0c0abb34u,0x0c0abb36u,0x0c0abb38u,0x0c0abb3au,0x0c0abb3cu,0x0c0abb3eu,0x0c0abb40u,
0x0c0abb42u,0x0c0abb44u,0x0c0abb46u,0x0c0abb48u,0x0c0abb4au,0x0c0abb4cu,0x0c0abb4eu,0x0c0abb50u,0x0c0abb52u,0x0c0abb54u,0x0c0abb56u,0x0c0abb58u,0x0c0abb5au,0x0c0abb5cu,0x0c0abb5eu,0x0c0abb60u,
0x0c0abb62u,0x0c0abb64u,0x0c0abb66u,0x0c0abb68u,0x0c0abb6au,0x0c0abb6cu,0x0c0abb6eu,0x0c0abb70u,0x0c0abb72u,0x0c0abb74u,0x0c0abb76u,0x0c0abb78u,0x0c0abb7au,0x0c0abb7cu,0x0c0abb7eu,0x0c0abb80u,
0x0c0abb82u,0x0c0abb84u,0x0c0abb86u,0x0c0abb88u,0x0c0abb8au,0x0c0abb8cu,0x0c0abb8eu,0x0c0abb90u,0x0c0abb92u,0x0c0abb94u,0x0c0abb96u,0x0c0abb98u,0x0c0abb9au,0x0c0abb9cu,0x0c0abb9eu,0x0c0abba0u,
0x0c0abba2u,0x0c0abba4u,0x0c0abba6u,0x0c0abba8u,0x0c0abbaau,0x0c0abbacu,0x0c0abbaeu,0x0c0abbb0u,0x0c0abbb2u,0x0c0abbb4u,0x0c0abbb6u,0x0c0abbb8u,0x0c0c66ccu,0x0c0c66ceu,0x0c0c66dcu,0x0c0c66deu,
0x0c0c80a8u,0x0c0c80aau,0x0c0c80acu,0x0c0c80aeu,0x0c0c80b0u,0x0c0c80b2u,0x0c0c80b4u,0x0c0c80b6u,0x0c0c80b8u,0x0c0c80bau,0x0c0c80bcu,0x0c0c80beu,0x0c0c80c0u,0x0c0c80c2u,0x0c0c80c4u,0x0c0c80c6u,
0x0c0c80c8u,0x0c0c80cau,0x0c0c80ccu,0x0c0c80ceu,0x0c0c80d0u,0x0c0c80d2u,0x0c0c80d4u,0x0c0c80d6u,0x0c0c80d8u,0x0c0c80dau,0x0c0c80dcu,0x0c0c80deu,0x0c0c80e0u,0x0c0c80e2u,0x0c0c80e4u,0x0c0c80e6u,
0x0c0c80e8u,0x0c0c80eau,0x0c0c80ecu,0x0c0c80eeu,0x0c0c80f0u,0x0c0c80f2u,0x0c0c80f4u,0x0c0c80f6u,0x0c0c80f8u,0x0c0c80fau,0x0c0c80fcu,0x0c0c80feu,0x0c0c8100u,0x0c0c8102u,0x0c0c8104u,0x0c0c8106u,
0x0c0c8108u,0x0c0c810au,0x0c0c810cu,0x0c0c810eu,0x0c0c8110u,0x0c0c8112u,0x0c0c8114u,0x0c0c8116u,0x0c0c8118u,0x0c0c811au,0x0c0c811cu,0x0c0c811eu,0x0c0c8120u,0x0c0c8122u,0x0c0c8124u,0x0c0c8126u,
0x0c0c8128u,0x0c0c812au,0x0c0c812cu,0x0c0c812eu,0x0c0c8130u,0x0c0c8132u,0x0c0c8134u,0x0c0c8136u,0x0c0c8138u,0x0c0c813au,0x0c0c813cu,0x0c0c813eu,0x0c0c8140u,0x0c0c8142u,0x0c0c8144u,0x0c0c8146u,
0x0c0c8148u,0x0c0c8168u,0x0c0c816au,0x0c0c816cu,0x0c0c816eu,0x0c0c8170u,0x0c0c8172u,0x0c0c8174u,0x0c0c8176u,0x0c0c8178u,0x0c0c817au,0x0c0c817cu,0x0c0c817eu,0x0c0c8180u,0x0c0c8182u,0x0c0c8184u,
0x0c0c8186u,0x0c0c8188u,0x0c0c818au,0x0c0c818cu,0x0c0c818eu,0x0c0c8190u,0x0c0c8192u,0x0c0c8194u,0x0c0c8196u,0x0c0c8198u,0x0c0c819au,0x0c0c819cu,0x0c0c819eu,0x0c0c81a0u,0x0c0c81a2u,0x0c0c81a4u,
0x0c0c81a6u,0x0c0c81a8u,0x0c0c81aau,0x0c0c81acu,0x0c0c81aeu,0x0c0c81b0u,0x0c0c81b2u,0x0c0c81b4u,0x0c0c81b6u,0x0c0c81b8u,0x0c0c81bau,0x0c0c81bcu,0x0c0c81beu,0x0c0c81c0u,0x0c0c81c2u,0x0c0c81c4u,
0x0c0c81c6u,0x0c0c81c8u,0x0c0c81cau,0x0c0c81ccu,0x0c0c81ceu,0x0c0c81d0u,0x0c0c81d2u,0x0c0c81d4u,0x0c0c81d6u,0x0c0c81d8u,0x0c0c81dau,0x0c0c81dcu,0x0c0c81deu,0x0c0c81e0u,0x0c0c81e2u,0x0c0c81e4u,
0x0c0c81e6u,0x0c0c81e8u,0x0c0c81eau,0x0c0c81ecu,0x0c0c81eeu,0x0c0c81f0u,0x0c0c81f2u,0x0c0c81f4u,0x0c0c81f6u,0x0c0c81f8u,0x0c0c81fau,0x0c0c81fcu,0x0c0c81feu,0x0c0c8200u,0x0c0c8202u,0x0c0c8204u,
0x0c0c8206u,0x0c0c8208u,0x0c0c820au,0x0c0c820cu,0x0c0c820eu,0x0c0c8210u,0x0c0c8212u,0x0c0c8214u,0x0c0c8216u,0x0c0c8218u,0x0c0c821au,0x0c0c821cu,0x0c0c821eu,0x0c0c8220u,0x0c0c8222u,0x0c0c8224u,
0x0c0c8226u,0x0c0c8228u,0x0c0c822au,0x0c0c822cu,0x0c0c822eu,0x0c0c8230u,0x0c0c8232u,0x0c0c8234u,0x0c0c8236u,0x0c0c8238u,0x0c0c823au,0x0c0c823cu,0x0c0c823eu,0x0c0c8240u,0x0c0c8242u,0x0c0c8244u,
0x0c0c8246u,0x0c0c8248u,0x0c0c824au,0x0c0c824cu,0x0c0c824eu,0x0c0c82e4u,0x0c0c82e6u,0x0c0c82e8u,0x0c0c82eau,0x0c0c82ecu,0x0c0c82eeu,0x0c0c82f0u,0x0c0c82f2u,0x0c0c82f4u,0x0c0c82f6u,0x0c0c82f8u,
0x0c0c82fau,0x0c0c82fcu,0x0c0c82feu,0x0c0c8300u,0x0c0c8302u,0x0c0c8304u,0x0c0c8306u,0x0c0c8308u,0x0c0c830au,0x0c0c830cu,0x0c0c830eu,0x0c0c8310u,0x0c0c8312u,0x0c0c8314u,0x0c0c8316u,0x0c0c8318u,
0x0c0c831au,0x0c0c831cu,0x0c0c831eu,0x0c0c8320u,0x0c0c8322u,0x0c0c8324u,0x0c0c8326u,0x0c0c8328u,0x0c0c832au,0x0c0c832cu,0x0c0c832eu,0x0c0c8330u,0x0c0c8332u,0x0c0c94b2u,0x0c0c94b4u,0x0c0c94b6u,
0x0c0c94b8u,0x0c0c94bau,0x0c0c94bcu,0x0c0c94beu,0x0c0c94c0u,0x0c0c94c2u,0x0c0c94c4u,0x0c0c94c6u,0x0c0c94c8u,0x0c0c94cau,0x0c0c94ccu,0x0c0c94ceu,0x0c0c94d0u,0x0c0c94d2u,0x0c0c94d4u,0x0c0c94d6u,
0x0c0c94d8u,0x0c0c94dau,0x0c0c94dcu,
};
int vf3_target_extended_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
