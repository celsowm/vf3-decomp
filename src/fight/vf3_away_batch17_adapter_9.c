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
int vf3_away_batch17_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09363au: goto P_0c09363a;
case 0x0c09363cu: goto P_0c09363c;
case 0x0c09363eu: goto P_0c09363e;
case 0x0c093640u: goto P_0c093640;
case 0x0c093642u: goto P_0c093642;
case 0x0c093644u: goto P_0c093644;
case 0x0c093646u: goto P_0c093646;
case 0x0c093648u: goto P_0c093648;
case 0x0c09364au: goto P_0c09364a;
case 0x0c09364cu: goto P_0c09364c;
case 0x0c09364eu: goto P_0c09364e;
case 0x0c093650u: goto P_0c093650;
case 0x0c093652u: goto P_0c093652;
case 0x0c093654u: goto P_0c093654;
case 0x0c093656u: goto P_0c093656;
case 0x0c093658u: goto P_0c093658;
case 0x0c09365au: goto P_0c09365a;
case 0x0c09365cu: goto P_0c09365c;
case 0x0c09365eu: goto P_0c09365e;
case 0x0c093660u: goto P_0c093660;
case 0x0c093662u: goto P_0c093662;
case 0x0c093664u: goto P_0c093664;
case 0x0c093666u: goto P_0c093666;
case 0x0c093668u: goto P_0c093668;
case 0x0c09366au: goto P_0c09366a;
case 0x0c09366cu: goto P_0c09366c;
case 0x0c09366eu: goto P_0c09366e;
case 0x0c093670u: goto P_0c093670;
case 0x0c093672u: goto P_0c093672;
case 0x0c093674u: goto P_0c093674;
case 0x0c093676u: goto P_0c093676;
case 0x0c093678u: goto P_0c093678;
case 0x0c09367au: goto P_0c09367a;
case 0x0c09367cu: goto P_0c09367c;
case 0x0c09367eu: goto P_0c09367e;
case 0x0c093680u: goto P_0c093680;
case 0x0c093682u: goto P_0c093682;
case 0x0c093684u: goto P_0c093684;
case 0x0c093686u: goto P_0c093686;
case 0x0c093688u: goto P_0c093688;
case 0x0c09368au: goto P_0c09368a;
case 0x0c09368cu: goto P_0c09368c;
case 0x0c09368eu: goto P_0c09368e;
case 0x0c093690u: goto P_0c093690;
case 0x0c093692u: goto P_0c093692;
case 0x0c093694u: goto P_0c093694;
case 0x0c093696u: goto P_0c093696;
case 0x0c093698u: goto P_0c093698;
case 0x0c09369au: goto P_0c09369a;
case 0x0c09369cu: goto P_0c09369c;
case 0x0c09369eu: goto P_0c09369e;
case 0x0c0936a0u: goto P_0c0936a0;
case 0x0c0936a2u: goto P_0c0936a2;
case 0x0c0936a4u: goto P_0c0936a4;
case 0x0c0936a6u: goto P_0c0936a6;
case 0x0c0936a8u: goto P_0c0936a8;
case 0x0c0936aau: goto P_0c0936aa;
case 0x0c0936acu: goto P_0c0936ac;
case 0x0c0936aeu: goto P_0c0936ae;
case 0x0c0936b0u: goto P_0c0936b0;
case 0x0c0936b2u: goto P_0c0936b2;
case 0x0c0936b4u: goto P_0c0936b4;
case 0x0c0936b6u: goto P_0c0936b6;
case 0x0c0936b8u: goto P_0c0936b8;
case 0x0c0936bau: goto P_0c0936ba;
case 0x0c0936bcu: goto P_0c0936bc;
case 0x0c0936beu: goto P_0c0936be;
case 0x0c0936c0u: goto P_0c0936c0;
case 0x0c0936c2u: goto P_0c0936c2;
case 0x0c0936c4u: goto P_0c0936c4;
case 0x0c0936c6u: goto P_0c0936c6;
case 0x0c0936c8u: goto P_0c0936c8;
case 0x0c0936cau: goto P_0c0936ca;
case 0x0c0936ccu: goto P_0c0936cc;
case 0x0c0936ceu: goto P_0c0936ce;
case 0x0c0936d0u: goto P_0c0936d0;
case 0x0c0936d2u: goto P_0c0936d2;
case 0x0c0936d4u: goto P_0c0936d4;
case 0x0c0936d6u: goto P_0c0936d6;
case 0x0c0936d8u: goto P_0c0936d8;
case 0x0c0936dau: goto P_0c0936da;
case 0x0c0936dcu: goto P_0c0936dc;
case 0x0c0936deu: goto P_0c0936de;
case 0x0c0936e0u: goto P_0c0936e0;
case 0x0c0936e2u: goto P_0c0936e2;
case 0x0c0936e4u: goto P_0c0936e4;
case 0x0c0936e6u: goto P_0c0936e6;
case 0x0c0936e8u: goto P_0c0936e8;
case 0x0c0936eau: goto P_0c0936ea;
case 0x0c0936ecu: goto P_0c0936ec;
case 0x0c0936eeu: goto P_0c0936ee;
case 0x0c0936f0u: goto P_0c0936f0;
case 0x0c0936f2u: goto P_0c0936f2;
case 0x0c0936f4u: goto P_0c0936f4;
case 0x0c0936f6u: goto P_0c0936f6;
case 0x0c0936f8u: goto P_0c0936f8;
case 0x0c0936fau: goto P_0c0936fa;
case 0x0c0936fcu: goto P_0c0936fc;
case 0x0c0936feu: goto P_0c0936fe;
case 0x0c093700u: goto P_0c093700;
case 0x0c093702u: goto P_0c093702;
case 0x0c093704u: goto P_0c093704;
case 0x0c093706u: goto P_0c093706;
case 0x0c093708u: goto P_0c093708;
case 0x0c09370au: goto P_0c09370a;
case 0x0c09370cu: goto P_0c09370c;
case 0x0c09370eu: goto P_0c09370e;
case 0x0c093710u: goto P_0c093710;
case 0x0c093712u: goto P_0c093712;
case 0x0c093714u: goto P_0c093714;
case 0x0c093716u: goto P_0c093716;
case 0x0c093718u: goto P_0c093718;
case 0x0c09371au: goto P_0c09371a;
case 0x0c09371cu: goto P_0c09371c;
case 0x0c09371eu: goto P_0c09371e;
case 0x0c093720u: goto P_0c093720;
case 0x0c093722u: goto P_0c093722;
case 0x0c093724u: goto P_0c093724;
case 0x0c093726u: goto P_0c093726;
case 0x0c093728u: goto P_0c093728;
case 0x0c09372au: goto P_0c09372a;
case 0x0c09372cu: goto P_0c09372c;
case 0x0c09372eu: goto P_0c09372e;
case 0x0c093730u: goto P_0c093730;
case 0x0c093732u: goto P_0c093732;
case 0x0c093734u: goto P_0c093734;
case 0x0c093736u: goto P_0c093736;
case 0x0c093738u: goto P_0c093738;
case 0x0c09373au: goto P_0c09373a;
case 0x0c09373cu: goto P_0c09373c;
case 0x0c09373eu: goto P_0c09373e;
case 0x0c093740u: goto P_0c093740;
case 0x0c093742u: goto P_0c093742;
case 0x0c093744u: goto P_0c093744;
case 0x0c093746u: goto P_0c093746;
case 0x0c093748u: goto P_0c093748;
case 0x0c09374au: goto P_0c09374a;
case 0x0c09374cu: goto P_0c09374c;
case 0x0c09374eu: goto P_0c09374e;
case 0x0c093750u: goto P_0c093750;
case 0x0c093768u: goto P_0c093768;
case 0x0c09376au: goto P_0c09376a;
case 0x0c09376cu: goto P_0c09376c;
case 0x0c09376eu: goto P_0c09376e;
case 0x0c093770u: goto P_0c093770;
case 0x0c093772u: goto P_0c093772;
case 0x0c093774u: goto P_0c093774;
case 0x0c093776u: goto P_0c093776;
case 0x0c093778u: goto P_0c093778;
case 0x0c09377au: goto P_0c09377a;
case 0x0c09377cu: goto P_0c09377c;
case 0x0c09377eu: goto P_0c09377e;
case 0x0c093780u: goto P_0c093780;
case 0x0c093782u: goto P_0c093782;
case 0x0c093784u: goto P_0c093784;
case 0x0c093786u: goto P_0c093786;
case 0x0c093788u: goto P_0c093788;
case 0x0c09378au: goto P_0c09378a;
case 0x0c09378cu: goto P_0c09378c;
case 0x0c09378eu: goto P_0c09378e;
case 0x0c093790u: goto P_0c093790;
case 0x0c093792u: goto P_0c093792;
case 0x0c093794u: goto P_0c093794;
case 0x0c093796u: goto P_0c093796;
case 0x0c093798u: goto P_0c093798;
case 0x0c09379au: goto P_0c09379a;
case 0x0c09379cu: goto P_0c09379c;
case 0x0c09379eu: goto P_0c09379e;
case 0x0c0937a0u: goto P_0c0937a0;
case 0x0c0937a2u: goto P_0c0937a2;
case 0x0c0937a4u: goto P_0c0937a4;
case 0x0c0937a6u: goto P_0c0937a6;
case 0x0c0937a8u: goto P_0c0937a8;
case 0x0c0937aau: goto P_0c0937aa;
case 0x0c0937acu: goto P_0c0937ac;
case 0x0c0937aeu: goto P_0c0937ae;
case 0x0c0937b0u: goto P_0c0937b0;
case 0x0c0937b2u: goto P_0c0937b2;
case 0x0c0937b4u: goto P_0c0937b4;
case 0x0c0937b6u: goto P_0c0937b6;
case 0x0c0937b8u: goto P_0c0937b8;
case 0x0c0937bau: goto P_0c0937ba;
case 0x0c0937bcu: goto P_0c0937bc;
case 0x0c0937beu: goto P_0c0937be;
case 0x0c0937c0u: goto P_0c0937c0;
case 0x0c0937c2u: goto P_0c0937c2;
case 0x0c0937c4u: goto P_0c0937c4;
case 0x0c0937c6u: goto P_0c0937c6;
case 0x0c0937c8u: goto P_0c0937c8;
case 0x0c0937cau: goto P_0c0937ca;
case 0x0c0937ccu: goto P_0c0937cc;
case 0x0c0937ceu: goto P_0c0937ce;
case 0x0c0937d4u: goto P_0c0937d4;
case 0x0c0937d6u: goto P_0c0937d6;
case 0x0c0937d8u: goto P_0c0937d8;
case 0x0c0937dau: goto P_0c0937da;
case 0x0c0937dcu: goto P_0c0937dc;
case 0x0c0937deu: goto P_0c0937de;
case 0x0c0937e0u: goto P_0c0937e0;
case 0x0c0937e2u: goto P_0c0937e2;
case 0x0c0937e4u: goto P_0c0937e4;
case 0x0c0937e6u: goto P_0c0937e6;
case 0x0c0937e8u: goto P_0c0937e8;
case 0x0c0937eau: goto P_0c0937ea;
case 0x0c0937ecu: goto P_0c0937ec;
case 0x0c0937eeu: goto P_0c0937ee;
case 0x0c0937f0u: goto P_0c0937f0;
case 0x0c0937f2u: goto P_0c0937f2;
case 0x0c0937f4u: goto P_0c0937f4;
case 0x0c0937f6u: goto P_0c0937f6;
case 0x0c0937f8u: goto P_0c0937f8;
case 0x0c0937fau: goto P_0c0937fa;
case 0x0c0937fcu: goto P_0c0937fc;
case 0x0c0937feu: goto P_0c0937fe;
case 0x0c093800u: goto P_0c093800;
case 0x0c093802u: goto P_0c093802;
case 0x0c093804u: goto P_0c093804;
case 0x0c093806u: goto P_0c093806;
case 0x0c093808u: goto P_0c093808;
case 0x0c09380au: goto P_0c09380a;
case 0x0c09380cu: goto P_0c09380c;
case 0x0c09380eu: goto P_0c09380e;
case 0x0c093810u: goto P_0c093810;
case 0x0c093812u: goto P_0c093812;
case 0x0c093814u: goto P_0c093814;
case 0x0c093816u: goto P_0c093816;
case 0x0c093818u: goto P_0c093818;
case 0x0c09381au: goto P_0c09381a;
case 0x0c09381cu: goto P_0c09381c;
case 0x0c09381eu: goto P_0c09381e;
case 0x0c093820u: goto P_0c093820;
case 0x0c093822u: goto P_0c093822;
case 0x0c093824u: goto P_0c093824;
case 0x0c093826u: goto P_0c093826;
case 0x0c093828u: goto P_0c093828;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09363a: /* original 2fe6, guest PC 0x0c09363a */
if(!s->budget--) { s->failed_pc=0x0c09363au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09363c;
P_0c09363c: /* original 2fd6, guest PC 0x0c09363c */
if(!s->budget--) { s->failed_pc=0x0c09363cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09363e;
P_0c09363e: /* original 2fc6, guest PC 0x0c09363e */
if(!s->budget--) { s->failed_pc=0x0c09363eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093640;
P_0c093640: /* original 2fb6, guest PC 0x0c093640 */
if(!s->budget--) { s->failed_pc=0x0c093640u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093642;
P_0c093642: /* original 4f22, guest PC 0x0c093642 */
if(!s->budget--) { s->failed_pc=0x0c093642u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c093644;
P_0c093644: /* original 9385, guest PC 0x0c093644 */
if(!s->budget--) { s->failed_pc=0x0c093644u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093752u,2);
goto P_0c093646;
P_0c093646: /* original 7fec, guest PC 0x0c093646 */
if(!s->budget--) { s->failed_pc=0x0c093646u; return 0; }
r[15]+=0xffffffecu;
goto P_0c093648;
P_0c093648: /* original 5cfc, guest PC 0x0c093648 */
if(!s->budget--) { s->failed_pc=0x0c093648u; return 0; }
r[12]=read(ram,r[15]+48,4);
goto P_0c09364a;
P_0c09364a: /* original 62c2, guest PC 0x0c09364a */
if(!s->budget--) { s->failed_pc=0x0c09364au; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c09364c;
P_0c09364c: /* original 2239, guest PC 0x0c09364c */
if(!s->budget--) { s->failed_pc=0x0c09364cu; return 0; }
r[2]&=r[3];
goto P_0c09364e;
P_0c09364e: /* original 2c22, guest PC 0x0c09364e */
if(!s->budget--) { s->failed_pc=0x0c09364eu; return 0; }
write(ram,r[12],r[2],4);
goto P_0c093650;
P_0c093650: /* original 8548, guest PC 0x0c093650 */
if(!s->budget--) { s->failed_pc=0x0c093650u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+16,2);
goto P_0c093652;
P_0c093652: /* original 600d, guest PC 0x0c093652 */
if(!s->budget--) { s->failed_pc=0x0c093652u; return 0; }
r[0]=r[0]&65535u;
goto P_0c093654;
P_0c093654: /* original c801, guest PC 0x0c093654 */
if(!s->budget--) { s->failed_pc=0x0c093654u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c093656;
P_0c093656: /* original 8d0a, guest PC 0x0c093656 */
if(!s->budget--) { s->failed_pc=0x0c093656u; return 0; }
cond=r[17]&1u;
r[14]=r[6];
if(cond) { goto P_0c09366e; }
goto P_0c09365a;
P_0c093658: /* original 6e63, guest PC 0x0c093658 */
if(!s->budget--) { s->failed_pc=0x0c093658u; return 0; }
r[14]=r[6];
goto P_0c09365a;
P_0c09365a: /* original e036, guest PC 0x0c09365a */
if(!s->budget--) { s->failed_pc=0x0c09365au; return 0; }
r[0]=0x00000036u;
goto P_0c09365c;
P_0c09365c: /* original 045c, guest PC 0x0c09365c */
if(!s->budget--) { s->failed_pc=0x0c09365cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c09365e;
P_0c09365e: /* original 604c, guest PC 0x0c09365e */
if(!s->budget--) { s->failed_pc=0x0c09365eu; return 0; }
r[0]=r[4]&255u;
goto P_0c093660;
P_0c093660: /* original 8809, guest PC 0x0c093660 */
if(!s->budget--) { s->failed_pc=0x0c093660u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c093662;
P_0c093662: /* original 8d41, guest PC 0x0c093662 */
if(!s->budget--) { s->failed_pc=0x0c093662u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0936e8; }
goto P_0c093666;
P_0c093664: /* original 6403, guest PC 0x0c093664 */
if(!s->budget--) { s->failed_pc=0x0c093664u; return 0; }
r[4]=r[0];
goto P_0c093666;
P_0c093666: /* original 2448, guest PC 0x0c093666 */
if(!s->budget--) { s->failed_pc=0x0c093666u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c093668;
P_0c093668: /* original 893e, guest PC 0x0c093668 */
if(!s->budget--) { s->failed_pc=0x0c093668u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0936e8; }
goto P_0c09366a;
P_0c09366a: /* original a03d, guest PC 0x0c09366a */
if(!s->budget--) { s->failed_pc=0x0c09366au; return 0; }
r[4]=0x00000006u;
goto P_0c0936e8;
P_0c09366c: /* original e406, guest PC 0x0c09366c */
if(!s->budget--) { s->failed_pc=0x0c09366cu; return 0; }
r[4]=0x00000006u;
goto P_0c09366e;
P_0c09366e: /* original 9071, guest PC 0x0c09366e */
if(!s->budget--) { s->failed_pc=0x0c09366eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093754u,2);
goto P_0c093670;
P_0c093670: /* original f446, guest PC 0x0c093670 */
if(!s->budget--) { s->failed_pc=0x0c093670u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c093672;
P_0c093672: /* original e004, guest PC 0x0c093672 */
if(!s->budget--) { s->failed_pc=0x0c093672u; return 0; }
r[0]=0x00000004u;
goto P_0c093674;
P_0c093674: /* original f3e6, guest PC 0x0c093674 */
if(!s->budget--) { s->failed_pc=0x0c093674u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c093676;
P_0c093676: /* original f435, guest PC 0x0c093676 */
if(!s->budget--) { s->failed_pc=0x0c093676u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c093678;
P_0c093678: /* original 8b33, guest PC 0x0c093678 */
if(!s->budget--) { s->failed_pc=0x0c093678u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0936e2; }
goto P_0c09367a;
P_0c09367a: /* original f576, guest PC 0x0c09367a */
if(!s->budget--) { s->failed_pc=0x0c09367au; return 0; }
vf3_matrix_load(s,ram,5,r[7]+r[0]);
goto P_0c09367c;
P_0c09367c: /* original e024, guest PC 0x0c09367c */
if(!s->budget--) { s->failed_pc=0x0c09367cu; return 0; }
r[0]=0x00000024u;
goto P_0c09367e;
P_0c09367e: /* original f656, guest PC 0x0c09367e */
if(!s->budget--) { s->failed_pc=0x0c09367eu; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c093680;
P_0c093680: /* original c735, guest PC 0x0c093680 */
if(!s->budget--) { s->failed_pc=0x0c093680u; return 0; }
r[0]=code_base|0x00093758u;
goto P_0c093682;
P_0c093682: /* original f541, guest PC 0x0c093682 */
if(!s->budget--) { s->failed_pc=0x0c093682u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'-');
goto P_0c093684;
P_0c093684: /* original f908, guest PC 0x0c093684 */
if(!s->budget--) { s->failed_pc=0x0c093684u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c093686;
P_0c093686: /* original f36c, guest PC 0x0c093686 */
if(!s->budget--) { s->failed_pc=0x0c093686u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c093688;
P_0c093688: /* original f362, guest PC 0x0c093688 */
if(!s->budget--) { s->failed_pc=0x0c093688u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c09368a;
P_0c09368a: /* original f25c, guest PC 0x0c09368a */
if(!s->budget--) { s->failed_pc=0x0c09368au; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c09368c;
P_0c09368c: /* original f252, guest PC 0x0c09368c */
if(!s->budget--) { s->failed_pc=0x0c09368cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'*');
goto P_0c09368e;
P_0c09368e: /* original f53c, guest PC 0x0c09368e */
if(!s->budget--) { s->failed_pc=0x0c09368eu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c093690;
P_0c093690: /* original f521, guest PC 0x0c093690 */
if(!s->budget--) { s->failed_pc=0x0c093690u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'-');
goto P_0c093692;
P_0c093692: /* original f955, guest PC 0x0c093692 */
if(!s->budget--) { s->failed_pc=0x0c093692u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[5]))!=0);
goto P_0c093694;
P_0c093694: /* original 8f02, guest PC 0x0c093694 */
if(!s->budget--) { s->failed_pc=0x0c093694u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,3,r[7]);
if(!cond) { goto P_0c09369c; }
goto P_0c093698;
P_0c093696: /* original f378, guest PC 0x0c093696 */
if(!s->budget--) { s->failed_pc=0x0c093696u; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c093698;
P_0c093698: /* original a002, guest PC 0x0c093698 */
if(!s->budget--) { s->failed_pc=0x0c093698u; return 0; }
fr[6]=0;
goto P_0c0936a0;
P_0c09369a: /* original f68d, guest PC 0x0c09369a */
if(!s->budget--) { s->failed_pc=0x0c09369au; return 0; }
fr[6]=0;
goto P_0c09369c;
P_0c09369c: /* original f65c, guest PC 0x0c09369c */
if(!s->budget--) { s->failed_pc=0x0c09369cu; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c09369e;
P_0c09369e: /* original f66d, guest PC 0x0c09369e */
if(!s->budget--) { s->failed_pc=0x0c09369eu; return 0; }
fr[6]=vf3_fpu_sqrt(fr[6],r[18]);
goto P_0c0936a0;
P_0c0936a0: /* original f5e8, guest PC 0x0c0936a0 */
if(!s->budget--) { s->failed_pc=0x0c0936a0u; return 0; }
vf3_matrix_load(s,ram,5,r[14]);
goto P_0c0936a2;
P_0c0936a2: /* original e008, guest PC 0x0c0936a2 */
if(!s->budget--) { s->failed_pc=0x0c0936a2u; return 0; }
r[0]=0x00000008u;
goto P_0c0936a4;
P_0c0936a4: /* original f7e6, guest PC 0x0c0936a4 */
if(!s->budget--) { s->failed_pc=0x0c0936a4u; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0936a6;
P_0c0936a6: /* original f531, guest PC 0x0c0936a6 */
if(!s->budget--) { s->failed_pc=0x0c0936a6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c0936a8;
P_0c0936a8: /* original f376, guest PC 0x0c0936a8 */
if(!s->budget--) { s->failed_pc=0x0c0936a8u; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c0936aa;
P_0c0936aa: /* original f731, guest PC 0x0c0936aa */
if(!s->budget--) { s->failed_pc=0x0c0936aau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c0936ac;
P_0c0936ac: /* original f35c, guest PC 0x0c0936ac */
if(!s->budget--) { s->failed_pc=0x0c0936acu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0936ae;
P_0c0936ae: /* original f352, guest PC 0x0c0936ae */
if(!s->budget--) { s->failed_pc=0x0c0936aeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c0936b0;
P_0c0936b0: /* original f07c, guest PC 0x0c0936b0 */
if(!s->budget--) { s->failed_pc=0x0c0936b0u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c0936b2;
P_0c0936b2: /* original f37e, guest PC 0x0c0936b2 */
if(!s->budget--) { s->failed_pc=0x0c0936b2u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[7],fr[3],r[18]);
goto P_0c0936b4;
P_0c0936b4: /* original f935, guest PC 0x0c0936b4 */
if(!s->budget--) { s->failed_pc=0x0c0936b4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[3]))!=0);
goto P_0c0936b6;
P_0c0936b6: /* original 8f02, guest PC 0x0c0936b6 */
if(!s->budget--) { s->failed_pc=0x0c0936b6u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,8,3);
if(!cond) { goto P_0c0936be; }
goto P_0c0936ba;
P_0c0936b8: /* original f83c, guest PC 0x0c0936b8 */
if(!s->budget--) { s->failed_pc=0x0c0936b8u; return 0; }
vf3_matrix_move(s,8,3);
goto P_0c0936ba;
P_0c0936ba: /* original a002, guest PC 0x0c0936ba */
if(!s->budget--) { s->failed_pc=0x0c0936bau; return 0; }
fr[3]=0;
goto P_0c0936c2;
P_0c0936bc: /* original f38d, guest PC 0x0c0936bc */
if(!s->budget--) { s->failed_pc=0x0c0936bcu; return 0; }
fr[3]=0;
goto P_0c0936be;
P_0c0936be: /* original f38c, guest PC 0x0c0936be */
if(!s->budget--) { s->failed_pc=0x0c0936beu; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c0936c0;
P_0c0936c0: /* original f37d, guest PC 0x0c0936c0 */
if(!s->budget--) { s->failed_pc=0x0c0936c0u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c0936c2;
P_0c0936c2: /* original f632, guest PC 0x0c0936c2 */
if(!s->budget--) { s->failed_pc=0x0c0936c2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0936c4;
P_0c0936c4: /* original f378, guest PC 0x0c0936c4 */
if(!s->budget--) { s->failed_pc=0x0c0936c4u; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c0936c6;
P_0c0936c6: /* original f05c, guest PC 0x0c0936c6 */
if(!s->budget--) { s->failed_pc=0x0c0936c6u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0936c8;
P_0c0936c8: /* original f36e, guest PC 0x0c0936c8 */
if(!s->budget--) { s->failed_pc=0x0c0936c8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[6],fr[3],r[18]);
goto P_0c0936ca;
P_0c0936ca: /* original fe3a, guest PC 0x0c0936ca */
if(!s->budget--) { s->failed_pc=0x0c0936cau; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c0936cc;
P_0c0936cc: /* original f276, guest PC 0x0c0936cc */
if(!s->budget--) { s->failed_pc=0x0c0936ccu; return 0; }
vf3_matrix_load(s,ram,2,r[7]+r[0]);
goto P_0c0936ce;
P_0c0936ce: /* original f06c, guest PC 0x0c0936ce */
if(!s->budget--) { s->failed_pc=0x0c0936ceu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0936d0;
P_0c0936d0: /* original f27e, guest PC 0x0c0936d0 */
if(!s->budget--) { s->failed_pc=0x0c0936d0u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[7],fr[2],r[18]);
goto P_0c0936d2;
P_0c0936d2: /* original fe27, guest PC 0x0c0936d2 */
if(!s->budget--) { s->failed_pc=0x0c0936d2u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0936d4;
P_0c0936d4: /* original e004, guest PC 0x0c0936d4 */
if(!s->budget--) { s->failed_pc=0x0c0936d4u; return 0; }
r[0]=0x00000004u;
goto P_0c0936d6;
P_0c0936d6: /* original fe47, guest PC 0x0c0936d6 */
if(!s->budget--) { s->failed_pc=0x0c0936d6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0936d8;
P_0c0936d8: /* original 933d, guest PC 0x0c0936d8 */
if(!s->budget--) { s->failed_pc=0x0c0936d8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093756u,2);
goto P_0c0936da;
P_0c0936da: /* original 62c2, guest PC 0x0c0936da */
if(!s->budget--) { s->failed_pc=0x0c0936dau; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c0936dc;
P_0c0936dc: /* original 223b, guest PC 0x0c0936dc */
if(!s->budget--) { s->failed_pc=0x0c0936dcu; return 0; }
r[2]|=r[3];
goto P_0c0936de;
P_0c0936de: /* original a031, guest PC 0x0c0936de */
if(!s->budget--) { s->failed_pc=0x0c0936deu; return 0; }
write(ram,r[12],r[2],4);
goto P_0c093744;
P_0c0936e0: /* original 2c22, guest PC 0x0c0936e0 */
if(!s->budget--) { s->failed_pc=0x0c0936e0u; return 0; }
write(ram,r[12],r[2],4);
goto P_0c0936e2;
P_0c0936e2: /* original e036, guest PC 0x0c0936e2 */
if(!s->budget--) { s->failed_pc=0x0c0936e2u; return 0; }
r[0]=0x00000036u;
goto P_0c0936e4;
P_0c0936e4: /* original 045c, guest PC 0x0c0936e4 */
if(!s->budget--) { s->failed_pc=0x0c0936e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0936e6;
P_0c0936e6: /* original 644c, guest PC 0x0c0936e6 */
if(!s->budget--) { s->failed_pc=0x0c0936e6u; return 0; }
r[4]=r[4]&255u;
goto P_0c0936e8;
P_0c0936e8: /* original 4408, guest PC 0x0c0936e8 */
if(!s->budget--) { s->failed_pc=0x0c0936e8u; return 0; }
r[4]<<=2;
goto P_0c0936ea;
P_0c0936ea: /* original db1c, guest PC 0x0c0936ea */
if(!s->budget--) { s->failed_pc=0x0c0936eau; return 0; }
r[11]=read(ram,0x0c09375cu,4);
goto P_0c0936ec;
P_0c0936ec: /* original 4408, guest PC 0x0c0936ec */
if(!s->budget--) { s->failed_pc=0x0c0936ecu; return 0; }
r[4]<<=2;
goto P_0c0936ee;
P_0c0936ee: /* original 4400, guest PC 0x0c0936ee */
if(!s->budget--) { s->failed_pc=0x0c0936eeu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0936f0;
P_0c0936f0: /* original 3b4c, guest PC 0x0c0936f0 */
if(!s->budget--) { s->failed_pc=0x0c0936f0u; return 0; }
r[11]+=r[4];
goto P_0c0936f2;
P_0c0936f2: /* original 66b5, guest PC 0x0c0936f2 */
if(!s->budget--) { s->failed_pc=0x0c0936f2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[11],2);
r[11]+=2;
r[6]=tmp;
goto P_0c0936f4;
P_0c0936f4: /* original 656f, guest PC 0x0c0936f4 */
if(!s->budget--) { s->failed_pc=0x0c0936f4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c0936f6;
P_0c0936f6: /* original 64b5, guest PC 0x0c0936f6 */
if(!s->budget--) { s->failed_pc=0x0c0936f6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[11],2);
r[11]+=2;
r[4]=tmp;
goto P_0c0936f8;
P_0c0936f8: /* original 4511, guest PC 0x0c0936f8 */
if(!s->budget--) { s->failed_pc=0x0c0936f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c0936fa;
P_0c0936fa: /* original 8f23, guest PC 0x0c0936fa */
if(!s->budget--) { s->failed_pc=0x0c0936fau; return 0; }
cond=r[17]&1u;
r[4]=r[4]&65535u;
if(!cond) { goto P_0c093744; }
goto P_0c0936fe;
P_0c0936fc: /* original 644d, guest PC 0x0c0936fc */
if(!s->budget--) { s->failed_pc=0x0c0936fcu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0936fe;
P_0c0936fe: /* original 2558, guest PC 0x0c0936fe */
if(!s->budget--) { s->failed_pc=0x0c0936feu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c093700;
P_0c093700: /* original 890e, guest PC 0x0c093700 */
if(!s->budget--) { s->failed_pc=0x0c093700u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093720; }
goto P_0c093702;
P_0c093702: /* original 2fc6, guest PC 0x0c093702 */
if(!s->budget--) { s->failed_pc=0x0c093702u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093704;
P_0c093704: /* original 2f46, guest PC 0x0c093704 */
if(!s->budget--) { s->failed_pc=0x0c093704u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093706;
P_0c093706: /* original 52fd, guest PC 0x0c093706 */
if(!s->budget--) { s->failed_pc=0x0c093706u; return 0; }
r[2]=read(ram,r[15]+52,4);
goto P_0c093708;
P_0c093708: /* original 2f26, guest PC 0x0c093708 */
if(!s->budget--) { s->failed_pc=0x0c093708u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09370a;
P_0c09370a: /* original 66f3, guest PC 0x0c09370a */
if(!s->budget--) { s->failed_pc=0x0c09370au; return 0; }
r[6]=r[15];
goto P_0c09370c;
P_0c09370c: /* original 65f3, guest PC 0x0c09370c */
if(!s->budget--) { s->failed_pc=0x0c09370cu; return 0; }
r[5]=r[15];
goto P_0c09370e;
P_0c09370e: /* original 67f3, guest PC 0x0c09370e */
if(!s->budget--) { s->failed_pc=0x0c09370eu; return 0; }
r[7]=r[15];
goto P_0c093710;
P_0c093710: /* original d313, guest PC 0x0c093710 */
if(!s->budget--) { s->failed_pc=0x0c093710u; return 0; }
r[3]=read(ram,0x0c093760u,4);
goto P_0c093712;
P_0c093712: /* original 7514, guest PC 0x0c093712 */
if(!s->budget--) { s->failed_pc=0x0c093712u; return 0; }
r[5]+=0x00000014u;
goto P_0c093714;
P_0c093714: /* original 7710, guest PC 0x0c093714 */
if(!s->budget--) { s->failed_pc=0x0c093714u; return 0; }
r[7]+=0x00000010u;
goto P_0c093716;
P_0c093716: /* original 760c, guest PC 0x0c093716 */
if(!s->budget--) { s->failed_pc=0x0c093716u; return 0; }
r[6]+=0x0000000cu;
goto P_0c093718;
P_0c093718: /* original 430b, guest PC 0x0c093718 */
if(!s->budget--) { s->failed_pc=0x0c093718u; return 0; }
target=r[3];
r[16]=code_base|0x0c09371cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09371cu) { target=s->pc; goto dispatch; }
goto P_0c09371c;
P_0c09371a: /* original 64e3, guest PC 0x0c09371a */
if(!s->budget--) { s->failed_pc=0x0c09371au; return 0; }
r[4]=r[14];
goto P_0c09371c;
P_0c09371c: /* original afe9, guest PC 0x0c09371c */
if(!s->budget--) { s->failed_pc=0x0c09371cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0936f2;
P_0c09371e: /* original 7f0c, guest PC 0x0c09371e */
if(!s->budget--) { s->failed_pc=0x0c09371eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c093720;
P_0c093720: /* original 5dfa, guest PC 0x0c093720 */
if(!s->budget--) { s->failed_pc=0x0c093720u; return 0; }
r[13]=read(ram,r[15]+40,4);
goto P_0c093722;
P_0c093722: /* original e00c, guest PC 0x0c093722 */
if(!s->budget--) { s->failed_pc=0x0c093722u; return 0; }
r[0]=0x0000000cu;
goto P_0c093724;
P_0c093724: /* original 66c3, guest PC 0x0c093724 */
if(!s->budget--) { s->failed_pc=0x0c093724u; return 0; }
r[6]=r[12];
goto P_0c093726;
P_0c093726: /* original 3d4c, guest PC 0x0c093726 */
if(!s->budget--) { s->failed_pc=0x0c093726u; return 0; }
r[13]+=r[4];
goto P_0c093728;
P_0c093728: /* original f3d6, guest PC 0x0c093728 */
if(!s->budget--) { s->failed_pc=0x0c093728u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c09372a;
P_0c09372a: /* original e010, guest PC 0x0c09372a */
if(!s->budget--) { s->failed_pc=0x0c09372au; return 0; }
r[0]=0x00000010u;
goto P_0c09372c;
P_0c09372c: /* original 65d3, guest PC 0x0c09372c */
if(!s->budget--) { s->failed_pc=0x0c09372cu; return 0; }
r[5]=r[13];
goto P_0c09372e;
P_0c09372e: /* original ff3a, guest PC 0x0c09372e */
if(!s->budget--) { s->failed_pc=0x0c09372eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c093730;
P_0c093730: /* original f3d6, guest PC 0x0c093730 */
if(!s->budget--) { s->failed_pc=0x0c093730u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c093732;
P_0c093732: /* original e004, guest PC 0x0c093732 */
if(!s->budget--) { s->failed_pc=0x0c093732u; return 0; }
r[0]=0x00000004u;
goto P_0c093734;
P_0c093734: /* original ff37, guest PC 0x0c093734 */
if(!s->budget--) { s->failed_pc=0x0c093734u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c093736;
P_0c093736: /* original f4f8, guest PC 0x0c093736 */
if(!s->budget--) { s->failed_pc=0x0c093736u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c093738;
P_0c093738: /* original d30a, guest PC 0x0c093738 */
if(!s->budget--) { s->failed_pc=0x0c093738u; return 0; }
r[3]=read(ram,0x0c093764u,4);
goto P_0c09373a;
P_0c09373a: /* original f53c, guest PC 0x0c09373a */
if(!s->budget--) { s->failed_pc=0x0c09373au; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c09373c;
P_0c09373c: /* original 430b, guest PC 0x0c09373c */
if(!s->budget--) { s->failed_pc=0x0c09373cu; return 0; }
target=r[3];
r[16]=code_base|0x0c093740u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c093740u) { target=s->pc; goto dispatch; }
goto P_0c093740;
P_0c09373e: /* original 64e3, guest PC 0x0c09373e */
if(!s->budget--) { s->failed_pc=0x0c09373eu; return 0; }
r[4]=r[14];
goto P_0c093740;
P_0c093740: /* original afd7, guest PC 0x0c093740 */
if(!s->budget--) { s->failed_pc=0x0c093740u; return 0; }
goto P_0c0936f2;
P_0c093742: /* original 0009, guest PC 0x0c093742 */
if(!s->budget--) { s->failed_pc=0x0c093742u; return 0; }
goto P_0c093744;
P_0c093744: /* original 7f14, guest PC 0x0c093744 */
if(!s->budget--) { s->failed_pc=0x0c093744u; return 0; }
r[15]+=0x00000014u;
goto P_0c093746;
P_0c093746: /* original 4f26, guest PC 0x0c093746 */
if(!s->budget--) { s->failed_pc=0x0c093746u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c093748;
P_0c093748: /* original 6bf6, guest PC 0x0c093748 */
if(!s->budget--) { s->failed_pc=0x0c093748u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09374a;
P_0c09374a: /* original 6cf6, guest PC 0x0c09374a */
if(!s->budget--) { s->failed_pc=0x0c09374au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09374c;
P_0c09374c: /* original 6df6, guest PC 0x0c09374c */
if(!s->budget--) { s->failed_pc=0x0c09374cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09374e;
P_0c09374e: /* original 000b, guest PC 0x0c09374e */
if(!s->budget--) { s->failed_pc=0x0c09374eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c093750: /* original 6ef6, guest PC 0x0c093750 */
if(!s->budget--) { s->failed_pc=0x0c093750u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c093752u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c093752u; return 0; } return 1;
P_0c093768: /* original 2fe6, guest PC 0x0c093768 */
if(!s->budget--) { s->failed_pc=0x0c093768u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09376a;
P_0c09376a: /* original 6e73, guest PC 0x0c09376a */
if(!s->budget--) { s->failed_pc=0x0c09376au; return 0; }
r[14]=r[7];
goto P_0c09376c;
P_0c09376c: /* original 2fd6, guest PC 0x0c09376c */
if(!s->budget--) { s->failed_pc=0x0c09376cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09376e;
P_0c09376e: /* original 6d53, guest PC 0x0c09376e */
if(!s->budget--) { s->failed_pc=0x0c09376eu; return 0; }
r[13]=r[5];
goto P_0c093770;
P_0c093770: /* original fffb, guest PC 0x0c093770 */
if(!s->budget--) { s->failed_pc=0x0c093770u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c093772;
P_0c093772: /* original 65d3, guest PC 0x0c093772 */
if(!s->budget--) { s->failed_pc=0x0c093772u; return 0; }
r[5]=r[13];
goto P_0c093774;
P_0c093774: /* original 7ff8, guest PC 0x0c093774 */
if(!s->budget--) { s->failed_pc=0x0c093774u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c093776;
P_0c093776: /* original 1f41, guest PC 0x0c093776 */
if(!s->budget--) { s->failed_pc=0x0c093776u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c093778;
P_0c093778: /* original 6473, guest PC 0x0c093778 */
if(!s->budget--) { s->failed_pc=0x0c093778u; return 0; }
r[4]=r[7];
goto P_0c09377a;
P_0c09377a: /* original 2f62, guest PC 0x0c09377a */
if(!s->budget--) { s->failed_pc=0x0c09377au; return 0; }
write(ram,r[15],r[6],4);
goto P_0c09377c;
P_0c09377c: /* original f059, guest PC 0x0c09377c */
if(!s->budget--) { s->failed_pc=0x0c09377cu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c09377e;
P_0c09377e: /* original f369, guest PC 0x0c09377e */
if(!s->budget--) { s->failed_pc=0x0c09377eu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c093780;
P_0c093780: /* original f159, guest PC 0x0c093780 */
if(!s->budget--) { s->failed_pc=0x0c093780u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093782;
P_0c093782: /* original f469, guest PC 0x0c093782 */
if(!s->budget--) { s->failed_pc=0x0c093782u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c093784;
P_0c093784: /* original f031, guest PC 0x0c093784 */
if(!s->budget--) { s->failed_pc=0x0c093784u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c093786;
P_0c093786: /* original f258, guest PC 0x0c093786 */
if(!s->budget--) { s->failed_pc=0x0c093786u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c093788;
P_0c093788: /* original f568, guest PC 0x0c093788 */
if(!s->budget--) { s->failed_pc=0x0c093788u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c09378a;
P_0c09378a: /* original f141, guest PC 0x0c09378a */
if(!s->budget--) { s->failed_pc=0x0c09378au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c09378c;
P_0c09378c: /* original f251, guest PC 0x0c09378c */
if(!s->budget--) { s->failed_pc=0x0c09378cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c09378e;
P_0c09378e: /* original 7408, guest PC 0x0c09378e */
if(!s->budget--) { s->failed_pc=0x0c09378eu; return 0; }
r[4]+=0x00000008u;
goto P_0c093790;
P_0c093790: /* original f42a, guest PC 0x0c093790 */
if(!s->budget--) { s->failed_pc=0x0c093790u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c093792;
P_0c093792: /* original f41b, guest PC 0x0c093792 */
if(!s->budget--) { s->failed_pc=0x0c093792u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093794;
P_0c093794: /* original f40b, guest PC 0x0c093794 */
if(!s->budget--) { s->failed_pc=0x0c093794u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093796;
P_0c093796: /* original 0009, guest PC 0x0c093796 */
if(!s->budget--) { s->failed_pc=0x0c093796u; return 0; }
goto P_0c093798;
P_0c093798: /* original 64e3, guest PC 0x0c093798 */
if(!s->budget--) { s->failed_pc=0x0c093798u; return 0; }
r[4]=r[14];
goto P_0c09379a;
P_0c09379a: /* original f049, guest PC 0x0c09379a */
if(!s->budget--) { s->failed_pc=0x0c09379au; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09379c;
P_0c09379c: /* original f149, guest PC 0x0c09379c */
if(!s->budget--) { s->failed_pc=0x0c09379cu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09379e;
P_0c09379e: /* original f248, guest PC 0x0c09379e */
if(!s->budget--) { s->failed_pc=0x0c09379eu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
goto P_0c0937a0;
P_0c0937a0: /* original f38d, guest PC 0x0c0937a0 */
if(!s->budget--) { s->failed_pc=0x0c0937a0u; return 0; }
fr[3]=0;
goto P_0c0937a2;
P_0c0937a2: /* original f0ed, guest PC 0x0c0937a2 */
if(!s->budget--) { s->failed_pc=0x0c0937a2u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c0937a4;
P_0c0937a4: /* original f03c, guest PC 0x0c0937a4 */
if(!s->budget--) { s->failed_pc=0x0c0937a4u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c0937a6;
P_0c0937a6: /* original 0009, guest PC 0x0c0937a6 */
if(!s->budget--) { s->failed_pc=0x0c0937a6u; return 0; }
goto P_0c0937a8;
P_0c0937a8: /* original f38d, guest PC 0x0c0937a8 */
if(!s->budget--) { s->failed_pc=0x0c0937a8u; return 0; }
fr[3]=0;
goto P_0c0937aa;
P_0c0937aa: /* original ff0c, guest PC 0x0c0937aa */
if(!s->budget--) { s->failed_pc=0x0c0937aau; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c0937ac;
P_0c0937ac: /* original ff34, guest PC 0x0c0937ac */
if(!s->budget--) { s->failed_pc=0x0c0937acu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])==as_float(fr[3]))!=0);
goto P_0c0937ae;
P_0c0937ae: /* original 8906, guest PC 0x0c0937ae */
if(!s->budget--) { s->failed_pc=0x0c0937aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0937be; }
goto P_0c0937b0;
P_0c0937b0: /* original c707, guest PC 0x0c0937b0 */
if(!s->budget--) { s->failed_pc=0x0c0937b0u; return 0; }
r[0]=code_base|0x000937d0u;
goto P_0c0937b2;
P_0c0937b2: /* original f208, guest PC 0x0c0937b2 */
if(!s->budget--) { s->failed_pc=0x0c0937b2u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0937b4;
P_0c0937b4: /* original f2f5, guest PC 0x0c0937b4 */
if(!s->budget--) { s->failed_pc=0x0c0937b4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[15]))!=0);
goto P_0c0937b6;
P_0c0937b6: /* original 8b01, guest PC 0x0c0937b6 */
if(!s->budget--) { s->failed_pc=0x0c0937b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0937bc; }
goto P_0c0937b8;
P_0c0937b8: /* original a001, guest PC 0x0c0937b8 */
if(!s->budget--) { s->failed_pc=0x0c0937b8u; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c0937be;
P_0c0937ba: /* original ff3c, guest PC 0x0c0937ba */
if(!s->budget--) { s->failed_pc=0x0c0937bau; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c0937bc;
P_0c0937bc: /* original ff7d, guest PC 0x0c0937bc */
if(!s->budget--) { s->failed_pc=0x0c0937bcu; return 0; }
if(!vf3_fpu_fsrra(fr[15],r[18],&fr[15])) goto unsupported;
goto P_0c0937be;
P_0c0937be: /* original 53f1, guest PC 0x0c0937be */
if(!s->budget--) { s->failed_pc=0x0c0937beu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0937c0;
P_0c0937c0: /* original e024, guest PC 0x0c0937c0 */
if(!s->budget--) { s->failed_pc=0x0c0937c0u; return 0; }
r[0]=0x00000024u;
goto P_0c0937c2;
P_0c0937c2: /* original f4fc, guest PC 0x0c0937c2 */
if(!s->budget--) { s->failed_pc=0x0c0937c2u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0937c4;
P_0c0937c4: /* original 64d3, guest PC 0x0c0937c4 */
if(!s->budget--) { s->failed_pc=0x0c0937c4u; return 0; }
r[4]=r[13];
goto P_0c0937c6;
P_0c0937c6: /* original f336, guest PC 0x0c0937c6 */
if(!s->budget--) { s->failed_pc=0x0c0937c6u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0937c8;
P_0c0937c8: /* original 65e3, guest PC 0x0c0937c8 */
if(!s->budget--) { s->failed_pc=0x0c0937c8u; return 0; }
r[5]=r[14];
goto P_0c0937ca;
P_0c0937ca: /* original f432, guest PC 0x0c0937ca */
if(!s->budget--) { s->failed_pc=0x0c0937cau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0937cc;
P_0c0937cc: /* original a002, guest PC 0x0c0937cc */
if(!s->budget--) { s->failed_pc=0x0c0937ccu; return 0; }
goto P_0c0937d4;
P_0c0937ce: /* original 0009, guest PC 0x0c0937ce */
if(!s->budget--) { s->failed_pc=0x0c0937ceu; return 0; }
if(!vf3_matrix_family(0x0c0937d0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0937d0u; return 0; } return 1;
P_0c0937d4: /* original f059, guest PC 0x0c0937d4 */
if(!s->budget--) { s->failed_pc=0x0c0937d4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0937d6;
P_0c0937d6: /* original f159, guest PC 0x0c0937d6 */
if(!s->budget--) { s->failed_pc=0x0c0937d6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0937d8;
P_0c0937d8: /* original f259, guest PC 0x0c0937d8 */
if(!s->budget--) { s->failed_pc=0x0c0937d8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0937da;
P_0c0937da: /* original 740c, guest PC 0x0c0937da */
if(!s->budget--) { s->failed_pc=0x0c0937dau; return 0; }
r[4]+=0x0000000cu;
goto P_0c0937dc;
P_0c0937dc: /* original f242, guest PC 0x0c0937dc */
if(!s->budget--) { s->failed_pc=0x0c0937dcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c0937de;
P_0c0937de: /* original f142, guest PC 0x0c0937de */
if(!s->budget--) { s->failed_pc=0x0c0937deu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c0937e0;
P_0c0937e0: /* original f042, guest PC 0x0c0937e0 */
if(!s->budget--) { s->failed_pc=0x0c0937e0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c0937e2;
P_0c0937e2: /* original f42b, guest PC 0x0c0937e2 */
if(!s->budget--) { s->failed_pc=0x0c0937e2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0937e4;
P_0c0937e4: /* original f41b, guest PC 0x0c0937e4 */
if(!s->budget--) { s->failed_pc=0x0c0937e4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c0937e6;
P_0c0937e6: /* original f40b, guest PC 0x0c0937e6 */
if(!s->budget--) { s->failed_pc=0x0c0937e6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0937e8;
P_0c0937e8: /* original 64e3, guest PC 0x0c0937e8 */
if(!s->budget--) { s->failed_pc=0x0c0937e8u; return 0; }
r[4]=r[14];
goto P_0c0937ea;
P_0c0937ea: /* original 65e3, guest PC 0x0c0937ea */
if(!s->budget--) { s->failed_pc=0x0c0937eau; return 0; }
r[5]=r[14];
goto P_0c0937ec;
P_0c0937ec: /* original f4fc, guest PC 0x0c0937ec */
if(!s->budget--) { s->failed_pc=0x0c0937ecu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0937ee;
P_0c0937ee: /* original f059, guest PC 0x0c0937ee */
if(!s->budget--) { s->failed_pc=0x0c0937eeu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0937f0;
P_0c0937f0: /* original f159, guest PC 0x0c0937f0 */
if(!s->budget--) { s->failed_pc=0x0c0937f0u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0937f2;
P_0c0937f2: /* original f259, guest PC 0x0c0937f2 */
if(!s->budget--) { s->failed_pc=0x0c0937f2u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c0937f4;
P_0c0937f4: /* original 740c, guest PC 0x0c0937f4 */
if(!s->budget--) { s->failed_pc=0x0c0937f4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0937f6;
P_0c0937f6: /* original f242, guest PC 0x0c0937f6 */
if(!s->budget--) { s->failed_pc=0x0c0937f6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c0937f8;
P_0c0937f8: /* original f142, guest PC 0x0c0937f8 */
if(!s->budget--) { s->failed_pc=0x0c0937f8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c0937fa;
P_0c0937fa: /* original f042, guest PC 0x0c0937fa */
if(!s->budget--) { s->failed_pc=0x0c0937fau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c0937fc;
P_0c0937fc: /* original f42b, guest PC 0x0c0937fc */
if(!s->budget--) { s->failed_pc=0x0c0937fcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c0937fe;
P_0c0937fe: /* original f41b, guest PC 0x0c0937fe */
if(!s->budget--) { s->failed_pc=0x0c0937feu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093800;
P_0c093800: /* original f40b, guest PC 0x0c093800 */
if(!s->budget--) { s->failed_pc=0x0c093800u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093802;
P_0c093802: /* original 0009, guest PC 0x0c093802 */
if(!s->budget--) { s->failed_pc=0x0c093802u; return 0; }
goto P_0c093804;
P_0c093804: /* original 65f2, guest PC 0x0c093804 */
if(!s->budget--) { s->failed_pc=0x0c093804u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c093806;
P_0c093806: /* original 64d3, guest PC 0x0c093806 */
if(!s->budget--) { s->failed_pc=0x0c093806u; return 0; }
r[4]=r[13];
goto P_0c093808;
P_0c093808: /* original f049, guest PC 0x0c093808 */
if(!s->budget--) { s->failed_pc=0x0c093808u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09380a;
P_0c09380a: /* original f359, guest PC 0x0c09380a */
if(!s->budget--) { s->failed_pc=0x0c09380au; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c09380c;
P_0c09380c: /* original f149, guest PC 0x0c09380c */
if(!s->budget--) { s->failed_pc=0x0c09380cu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c09380e;
P_0c09380e: /* original f459, guest PC 0x0c09380e */
if(!s->budget--) { s->failed_pc=0x0c09380eu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093810;
P_0c093810: /* original f249, guest PC 0x0c093810 */
if(!s->budget--) { s->failed_pc=0x0c093810u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093812;
P_0c093812: /* original f559, guest PC 0x0c093812 */
if(!s->budget--) { s->failed_pc=0x0c093812u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093814;
P_0c093814: /* original f030, guest PC 0x0c093814 */
if(!s->budget--) { s->failed_pc=0x0c093814u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c093816;
P_0c093816: /* original f250, guest PC 0x0c093816 */
if(!s->budget--) { s->failed_pc=0x0c093816u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c093818;
P_0c093818: /* original f140, guest PC 0x0c093818 */
if(!s->budget--) { s->failed_pc=0x0c093818u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c09381a;
P_0c09381a: /* original f42b, guest PC 0x0c09381a */
if(!s->budget--) { s->failed_pc=0x0c09381au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c09381c;
P_0c09381c: /* original f41b, guest PC 0x0c09381c */
if(!s->budget--) { s->failed_pc=0x0c09381cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c09381e;
P_0c09381e: /* original f40b, guest PC 0x0c09381e */
if(!s->budget--) { s->failed_pc=0x0c09381eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093820;
P_0c093820: /* original 7f08, guest PC 0x0c093820 */
if(!s->budget--) { s->failed_pc=0x0c093820u; return 0; }
r[15]+=0x00000008u;
goto P_0c093822;
P_0c093822: /* original fff9, guest PC 0x0c093822 */
if(!s->budget--) { s->failed_pc=0x0c093822u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c093824;
P_0c093824: /* original 6df6, guest PC 0x0c093824 */
if(!s->budget--) { s->failed_pc=0x0c093824u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c093826;
P_0c093826: /* original 000b, guest PC 0x0c093826 */
if(!s->budget--) { s->failed_pc=0x0c093826u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c093828: /* original 6ef6, guest PC 0x0c093828 */
if(!s->budget--) { s->failed_pc=0x0c093828u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09382au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
