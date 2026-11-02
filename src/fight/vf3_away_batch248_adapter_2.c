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
int vf3_away_batch248_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0406b2u: goto P_0c0406b2;
case 0x0c0406b4u: goto P_0c0406b4;
case 0x0c0406b6u: goto P_0c0406b6;
case 0x0c0406b8u: goto P_0c0406b8;
case 0x0c0406bau: goto P_0c0406ba;
case 0x0c0406bcu: goto P_0c0406bc;
case 0x0c0406beu: goto P_0c0406be;
case 0x0c0406c0u: goto P_0c0406c0;
case 0x0c0406c2u: goto P_0c0406c2;
case 0x0c0406c4u: goto P_0c0406c4;
case 0x0c0406c6u: goto P_0c0406c6;
case 0x0c0406c8u: goto P_0c0406c8;
case 0x0c0406cau: goto P_0c0406ca;
case 0x0c0406ccu: goto P_0c0406cc;
case 0x0c0406ceu: goto P_0c0406ce;
case 0x0c0406d0u: goto P_0c0406d0;
case 0x0c0406d2u: goto P_0c0406d2;
case 0x0c0406d4u: goto P_0c0406d4;
case 0x0c0406d6u: goto P_0c0406d6;
case 0x0c0406d8u: goto P_0c0406d8;
case 0x0c0406dau: goto P_0c0406da;
case 0x0c0406dcu: goto P_0c0406dc;
case 0x0c0406deu: goto P_0c0406de;
case 0x0c0406e0u: goto P_0c0406e0;
case 0x0c0406e2u: goto P_0c0406e2;
case 0x0c0406e4u: goto P_0c0406e4;
case 0x0c0406e6u: goto P_0c0406e6;
case 0x0c0406e8u: goto P_0c0406e8;
case 0x0c0406eau: goto P_0c0406ea;
case 0x0c0406ecu: goto P_0c0406ec;
case 0x0c0406eeu: goto P_0c0406ee;
case 0x0c0406f0u: goto P_0c0406f0;
case 0x0c0406f2u: goto P_0c0406f2;
case 0x0c0406f4u: goto P_0c0406f4;
case 0x0c0406f6u: goto P_0c0406f6;
case 0x0c0406f8u: goto P_0c0406f8;
case 0x0c0406fau: goto P_0c0406fa;
case 0x0c0406fcu: goto P_0c0406fc;
case 0x0c0406feu: goto P_0c0406fe;
case 0x0c040700u: goto P_0c040700;
case 0x0c040702u: goto P_0c040702;
case 0x0c040704u: goto P_0c040704;
case 0x0c040706u: goto P_0c040706;
case 0x0c040708u: goto P_0c040708;
case 0x0c04070au: goto P_0c04070a;
case 0x0c040714u: goto P_0c040714;
case 0x0c040716u: goto P_0c040716;
case 0x0c040718u: goto P_0c040718;
case 0x0c04071au: goto P_0c04071a;
case 0x0c04071cu: goto P_0c04071c;
case 0x0c04071eu: goto P_0c04071e;
case 0x0c040720u: goto P_0c040720;
case 0x0c040722u: goto P_0c040722;
case 0x0c040724u: goto P_0c040724;
case 0x0c040726u: goto P_0c040726;
case 0x0c040728u: goto P_0c040728;
case 0x0c04072au: goto P_0c04072a;
case 0x0c04072cu: goto P_0c04072c;
case 0x0c04072eu: goto P_0c04072e;
case 0x0c040730u: goto P_0c040730;
case 0x0c040732u: goto P_0c040732;
case 0x0c040734u: goto P_0c040734;
case 0x0c040736u: goto P_0c040736;
case 0x0c040738u: goto P_0c040738;
case 0x0c04073au: goto P_0c04073a;
case 0x0c04073cu: goto P_0c04073c;
case 0x0c04073eu: goto P_0c04073e;
case 0x0c040740u: goto P_0c040740;
case 0x0c040742u: goto P_0c040742;
case 0x0c040744u: goto P_0c040744;
case 0x0c040746u: goto P_0c040746;
case 0x0c040748u: goto P_0c040748;
case 0x0c04074au: goto P_0c04074a;
case 0x0c04074cu: goto P_0c04074c;
case 0x0c04074eu: goto P_0c04074e;
case 0x0c040750u: goto P_0c040750;
case 0x0c040752u: goto P_0c040752;
case 0x0c040754u: goto P_0c040754;
case 0x0c040756u: goto P_0c040756;
case 0x0c040758u: goto P_0c040758;
case 0x0c04075au: goto P_0c04075a;
case 0x0c04075cu: goto P_0c04075c;
case 0x0c04075eu: goto P_0c04075e;
case 0x0c040760u: goto P_0c040760;
case 0x0c040762u: goto P_0c040762;
case 0x0c040764u: goto P_0c040764;
case 0x0c040766u: goto P_0c040766;
case 0x0c040768u: goto P_0c040768;
case 0x0c04076au: goto P_0c04076a;
case 0x0c04076cu: goto P_0c04076c;
case 0x0c04076eu: goto P_0c04076e;
case 0x0c040770u: goto P_0c040770;
case 0x0c040772u: goto P_0c040772;
case 0x0c040774u: goto P_0c040774;
case 0x0c040776u: goto P_0c040776;
case 0x0c040778u: goto P_0c040778;
case 0x0c04077au: goto P_0c04077a;
case 0x0c04077cu: goto P_0c04077c;
case 0x0c04077eu: goto P_0c04077e;
case 0x0c040780u: goto P_0c040780;
case 0x0c040782u: goto P_0c040782;
case 0x0c040784u: goto P_0c040784;
case 0x0c040786u: goto P_0c040786;
case 0x0c040788u: goto P_0c040788;
case 0x0c04078au: goto P_0c04078a;
case 0x0c04078cu: goto P_0c04078c;
case 0x0c04078eu: goto P_0c04078e;
case 0x0c040790u: goto P_0c040790;
case 0x0c040792u: goto P_0c040792;
case 0x0c040794u: goto P_0c040794;
case 0x0c040796u: goto P_0c040796;
case 0x0c040798u: goto P_0c040798;
case 0x0c04079au: goto P_0c04079a;
case 0x0c04079cu: goto P_0c04079c;
case 0x0c04079eu: goto P_0c04079e;
case 0x0c0407b0u: goto P_0c0407b0;
case 0x0c0407b2u: goto P_0c0407b2;
case 0x0c0407b4u: goto P_0c0407b4;
case 0x0c0407b6u: goto P_0c0407b6;
case 0x0c0407b8u: goto P_0c0407b8;
case 0x0c0407bau: goto P_0c0407ba;
case 0x0c0407bcu: goto P_0c0407bc;
case 0x0c0407beu: goto P_0c0407be;
case 0x0c0407c0u: goto P_0c0407c0;
case 0x0c0407c2u: goto P_0c0407c2;
case 0x0c0407c4u: goto P_0c0407c4;
case 0x0c0407c6u: goto P_0c0407c6;
case 0x0c0407c8u: goto P_0c0407c8;
case 0x0c040f1eu: goto P_0c040f1e;
case 0x0c040f20u: goto P_0c040f20;
case 0x0c040f22u: goto P_0c040f22;
case 0x0c040f24u: goto P_0c040f24;
case 0x0c040f26u: goto P_0c040f26;
case 0x0c040f28u: goto P_0c040f28;
case 0x0c040f2au: goto P_0c040f2a;
case 0x0c040f2cu: goto P_0c040f2c;
case 0x0c040f2eu: goto P_0c040f2e;
case 0x0c040f30u: goto P_0c040f30;
case 0x0c040f32u: goto P_0c040f32;
case 0x0c040f34u: goto P_0c040f34;
case 0x0c040f36u: goto P_0c040f36;
case 0x0c040f38u: goto P_0c040f38;
case 0x0c040f3au: goto P_0c040f3a;
case 0x0c040f3cu: goto P_0c040f3c;
case 0x0c040f3eu: goto P_0c040f3e;
case 0x0c040f40u: goto P_0c040f40;
case 0x0c040f42u: goto P_0c040f42;
case 0x0c040f44u: goto P_0c040f44;
case 0x0c040f46u: goto P_0c040f46;
case 0x0c040f48u: goto P_0c040f48;
case 0x0c040f4au: goto P_0c040f4a;
case 0x0c040f4cu: goto P_0c040f4c;
case 0x0c040f4eu: goto P_0c040f4e;
case 0x0c040f50u: goto P_0c040f50;
case 0x0c040f52u: goto P_0c040f52;
case 0x0c040f54u: goto P_0c040f54;
case 0x0c040f56u: goto P_0c040f56;
case 0x0c040f58u: goto P_0c040f58;
case 0x0c040f5au: goto P_0c040f5a;
case 0x0c040f5cu: goto P_0c040f5c;
case 0x0c040f5eu: goto P_0c040f5e;
case 0x0c040f60u: goto P_0c040f60;
case 0x0c040f62u: goto P_0c040f62;
case 0x0c040f64u: goto P_0c040f64;
case 0x0c040f66u: goto P_0c040f66;
case 0x0c046314u: goto P_0c046314;
case 0x0c046316u: goto P_0c046316;
case 0x0c09571cu: goto P_0c09571c;
case 0x0c09571eu: goto P_0c09571e;
case 0x0c095720u: goto P_0c095720;
case 0x0c095722u: goto P_0c095722;
case 0x0c096864u: goto P_0c096864;
case 0x0c096866u: goto P_0c096866;
case 0x0c096868u: goto P_0c096868;
case 0x0c09686au: goto P_0c09686a;
case 0x0c09686cu: goto P_0c09686c;
case 0x0c09686eu: goto P_0c09686e;
case 0x0c096870u: goto P_0c096870;
case 0x0c096872u: goto P_0c096872;
case 0x0c096874u: goto P_0c096874;
case 0x0c096876u: goto P_0c096876;
case 0x0c096878u: goto P_0c096878;
case 0x0c09687au: goto P_0c09687a;
case 0x0c09687cu: goto P_0c09687c;
case 0x0c09687eu: goto P_0c09687e;
case 0x0c096880u: goto P_0c096880;
case 0x0c096882u: goto P_0c096882;
case 0x0c096884u: goto P_0c096884;
case 0x0c096886u: goto P_0c096886;
case 0x0c096888u: goto P_0c096888;
case 0x0c09688au: goto P_0c09688a;
case 0x0c09688cu: goto P_0c09688c;
case 0x0c09688eu: goto P_0c09688e;
case 0x0c096890u: goto P_0c096890;
case 0x0c096892u: goto P_0c096892;
case 0x0c096894u: goto P_0c096894;
case 0x0c096896u: goto P_0c096896;
case 0x0c096898u: goto P_0c096898;
case 0x0c09689au: goto P_0c09689a;
case 0x0c09689cu: goto P_0c09689c;
case 0x0c09689eu: goto P_0c09689e;
case 0x0c0968a0u: goto P_0c0968a0;
case 0x0c0968a2u: goto P_0c0968a2;
case 0x0c0968a4u: goto P_0c0968a4;
case 0x0c0968a6u: goto P_0c0968a6;
case 0x0c0968a8u: goto P_0c0968a8;
case 0x0c0968aau: goto P_0c0968aa;
case 0x0c0968acu: goto P_0c0968ac;
case 0x0c0968aeu: goto P_0c0968ae;
case 0x0c0a7908u: goto P_0c0a7908;
case 0x0c0a790au: goto P_0c0a790a;
case 0x0c0a790cu: goto P_0c0a790c;
case 0x0c0a790eu: goto P_0c0a790e;
case 0x0c0a7910u: goto P_0c0a7910;
case 0x0c0a7912u: goto P_0c0a7912;
case 0x0c0a7914u: goto P_0c0a7914;
case 0x0c0a7916u: goto P_0c0a7916;
case 0x0c0a7918u: goto P_0c0a7918;
case 0x0c0a791au: goto P_0c0a791a;
case 0x0c0a791cu: goto P_0c0a791c;
case 0x0c0a791eu: goto P_0c0a791e;
case 0x0c0a7920u: goto P_0c0a7920;
case 0x0c0a7922u: goto P_0c0a7922;
case 0x0c0a7924u: goto P_0c0a7924;
case 0x0c0a7926u: goto P_0c0a7926;
case 0x0c0a7928u: goto P_0c0a7928;
case 0x0c0a792au: goto P_0c0a792a;
case 0x0c0a792cu: goto P_0c0a792c;
case 0x0c0a792eu: goto P_0c0a792e;
case 0x0c0a7930u: goto P_0c0a7930;
case 0x0c0a7932u: goto P_0c0a7932;
case 0x0c0a7934u: goto P_0c0a7934;
case 0x0c0a7936u: goto P_0c0a7936;
case 0x0c0a7938u: goto P_0c0a7938;
case 0x0c0a793au: goto P_0c0a793a;
case 0x0c0a793cu: goto P_0c0a793c;
case 0x0c0a793eu: goto P_0c0a793e;
case 0x0c0a7940u: goto P_0c0a7940;
case 0x0c0a7942u: goto P_0c0a7942;
case 0x0c0a7944u: goto P_0c0a7944;
case 0x0c0a7946u: goto P_0c0a7946;
case 0x0c0a7948u: goto P_0c0a7948;
case 0x0c0a794au: goto P_0c0a794a;
case 0x0c0a7978u: goto P_0c0a7978;
case 0x0c0a797au: goto P_0c0a797a;
case 0x0c0a797cu: goto P_0c0a797c;
case 0x0c0a797eu: goto P_0c0a797e;
case 0x0c0a7980u: goto P_0c0a7980;
case 0x0c0a7982u: goto P_0c0a7982;
case 0x0c0a7984u: goto P_0c0a7984;
case 0x0c0a7986u: goto P_0c0a7986;
case 0x0c0a7988u: goto P_0c0a7988;
case 0x0c0a798au: goto P_0c0a798a;
case 0x0c0a798cu: goto P_0c0a798c;
case 0x0c0a798eu: goto P_0c0a798e;
case 0x0c0a7990u: goto P_0c0a7990;
case 0x0c0a7992u: goto P_0c0a7992;
case 0x0c0a7994u: goto P_0c0a7994;
case 0x0c0a7996u: goto P_0c0a7996;
case 0x0c0a7998u: goto P_0c0a7998;
case 0x0c0a799au: goto P_0c0a799a;
case 0x0c0a799cu: goto P_0c0a799c;
case 0x0c0a799eu: goto P_0c0a799e;
case 0x0c0a79a0u: goto P_0c0a79a0;
case 0x0c0a79a2u: goto P_0c0a79a2;
case 0x0c0a79a4u: goto P_0c0a79a4;
case 0x0c0a79a6u: goto P_0c0a79a6;
case 0x0c0a79a8u: goto P_0c0a79a8;
case 0x0c0a79aau: goto P_0c0a79aa;
case 0x0c0a79acu: goto P_0c0a79ac;
case 0x0c0a79aeu: goto P_0c0a79ae;
case 0x0c0a79b0u: goto P_0c0a79b0;
case 0x0c0a79b2u: goto P_0c0a79b2;
case 0x0c0a79b4u: goto P_0c0a79b4;
case 0x0c0a79b6u: goto P_0c0a79b6;
case 0x0c0a79b8u: goto P_0c0a79b8;
case 0x0c0a79bau: goto P_0c0a79ba;
case 0x0c0a79bcu: goto P_0c0a79bc;
case 0x0c0a79beu: goto P_0c0a79be;
case 0x0c0a79c0u: goto P_0c0a79c0;
case 0x0c0a79c2u: goto P_0c0a79c2;
case 0x0c0a79c4u: goto P_0c0a79c4;
case 0x0c0a79c6u: goto P_0c0a79c6;
case 0x0c0a79c8u: goto P_0c0a79c8;
case 0x0c0a79cau: goto P_0c0a79ca;
case 0x0c0a79ccu: goto P_0c0a79cc;
case 0x0c0a79ceu: goto P_0c0a79ce;
case 0x0c0a79d0u: goto P_0c0a79d0;
case 0x0c0a79d2u: goto P_0c0a79d2;
case 0x0c0a79d4u: goto P_0c0a79d4;
case 0x0c0a79d6u: goto P_0c0a79d6;
case 0x0c0a79d8u: goto P_0c0a79d8;
case 0x0c0a79dau: goto P_0c0a79da;
case 0x0c0a79dcu: goto P_0c0a79dc;
case 0x0c0a79deu: goto P_0c0a79de;
case 0x0c0a79e0u: goto P_0c0a79e0;
case 0x0c0a79e2u: goto P_0c0a79e2;
case 0x0c0a79e4u: goto P_0c0a79e4;
case 0x0c0a79e6u: goto P_0c0a79e6;
case 0x0c0a79e8u: goto P_0c0a79e8;
case 0x0c0a79eau: goto P_0c0a79ea;
case 0x0c0a79ecu: goto P_0c0a79ec;
case 0x0c0a79eeu: goto P_0c0a79ee;
case 0x0c0a79f0u: goto P_0c0a79f0;
case 0x0c0a79f2u: goto P_0c0a79f2;
case 0x0c0a79f4u: goto P_0c0a79f4;
case 0x0c0a79f6u: goto P_0c0a79f6;
case 0x0c0a79f8u: goto P_0c0a79f8;
case 0x0c0a79fau: goto P_0c0a79fa;
case 0x0c0a79fcu: goto P_0c0a79fc;
case 0x0c0a79feu: goto P_0c0a79fe;
case 0x0c0a7a00u: goto P_0c0a7a00;
case 0x0c0a7a02u: goto P_0c0a7a02;
case 0x0c0a7a04u: goto P_0c0a7a04;
case 0x0c0a7a06u: goto P_0c0a7a06;
case 0x0c0a7a08u: goto P_0c0a7a08;
case 0x0c0a7a0au: goto P_0c0a7a0a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0406b2: /* original 2fe6, guest PC 0x0c0406b2 */
if(!s->budget--) { s->failed_pc=0x0c0406b2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0406b4;
P_0c0406b4: /* original 2fd6, guest PC 0x0c0406b4 */
if(!s->budget--) { s->failed_pc=0x0c0406b4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0406b6;
P_0c0406b6: /* original 2fc6, guest PC 0x0c0406b6 */
if(!s->budget--) { s->failed_pc=0x0c0406b6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0406b8;
P_0c0406b8: /* original 4f22, guest PC 0x0c0406b8 */
if(!s->budget--) { s->failed_pc=0x0c0406b8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0406ba;
P_0c0406ba: /* original 7fe4, guest PC 0x0c0406ba */
if(!s->budget--) { s->failed_pc=0x0c0406bau; return 0; }
r[15]+=0xffffffe4u;
goto P_0c0406bc;
P_0c0406bc: /* original 1f46, guest PC 0x0c0406bc */
if(!s->budget--) { s->failed_pc=0x0c0406bcu; return 0; }
write(ram,r[15]+24,r[4],4);
goto P_0c0406be;
P_0c0406be: /* original 1f55, guest PC 0x0c0406be */
if(!s->budget--) { s->failed_pc=0x0c0406beu; return 0; }
write(ram,r[15]+20,r[5],4);
goto P_0c0406c0;
P_0c0406c0: /* original 55f5, guest PC 0x0c0406c0 */
if(!s->budget--) { s->failed_pc=0x0c0406c0u; return 0; }
r[5]=read(ram,r[15]+20,4);
goto P_0c0406c2;
P_0c0406c2: /* original 54f6, guest PC 0x0c0406c2 */
if(!s->budget--) { s->failed_pc=0x0c0406c2u; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c0406c4;
P_0c0406c4: /* original bd46, guest PC 0x0c0406c4 */
if(!s->budget--) { s->failed_pc=0x0c0406c4u; return 0; }
target=code_base|0x0c040154u; r[16]=code_base|0x0c0406c8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0406c8u) { target=s->pc; goto dispatch; }
goto P_0c0406c8;
P_0c0406c6: /* original 0009, guest PC 0x0c0406c6 */
if(!s->budget--) { s->failed_pc=0x0c0406c6u; return 0; }
goto P_0c0406c8;
P_0c0406c8: /* original 1f01, guest PC 0x0c0406c8 */
if(!s->budget--) { s->failed_pc=0x0c0406c8u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0406ca;
P_0c0406ca: /* original 2008, guest PC 0x0c0406ca */
if(!s->budget--) { s->failed_pc=0x0c0406cau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0406cc;
P_0c0406cc: /* original 8901, guest PC 0x0c0406cc */
if(!s->budget--) { s->failed_pc=0x0c0406ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0406d2; }
goto P_0c0406ce;
P_0c0406ce: /* original a075, guest PC 0x0c0406ce */
if(!s->budget--) { s->failed_pc=0x0c0406ceu; return 0; }
goto P_0c0407bc;
P_0c0406d0: /* original 0009, guest PC 0x0c0406d0 */
if(!s->budget--) { s->failed_pc=0x0c0406d0u; return 0; }
goto P_0c0406d2;
P_0c0406d2: /* original 52f6, guest PC 0x0c0406d2 */
if(!s->budget--) { s->failed_pc=0x0c0406d2u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c0406d4;
P_0c0406d4: /* original 5322, guest PC 0x0c0406d4 */
if(!s->budget--) { s->failed_pc=0x0c0406d4u; return 0; }
r[3]=read(ram,r[2]+8,4);
goto P_0c0406d6;
P_0c0406d6: /* original 1f33, guest PC 0x0c0406d6 */
if(!s->budget--) { s->failed_pc=0x0c0406d6u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0406d8;
P_0c0406d8: /* original 5121, guest PC 0x0c0406d8 */
if(!s->budget--) { s->failed_pc=0x0c0406d8u; return 0; }
r[1]=read(ram,r[2]+4,4);
goto P_0c0406da;
P_0c0406da: /* original 1f12, guest PC 0x0c0406da */
if(!s->budget--) { s->failed_pc=0x0c0406dau; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c0406dc;
P_0c0406dc: /* original 67f3, guest PC 0x0c0406dc */
if(!s->budget--) { s->failed_pc=0x0c0406dcu; return 0; }
r[7]=r[15];
goto P_0c0406de;
P_0c0406de: /* original 56f3, guest PC 0x0c0406de */
if(!s->budget--) { s->failed_pc=0x0c0406deu; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c0406e0;
P_0c0406e0: /* original 55f2, guest PC 0x0c0406e0 */
if(!s->budget--) { s->failed_pc=0x0c0406e0u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c0406e2;
P_0c0406e2: /* original 54f5, guest PC 0x0c0406e2 */
if(!s->budget--) { s->failed_pc=0x0c0406e2u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c0406e4;
P_0c0406e4: /* original bd9d, guest PC 0x0c0406e4 */
if(!s->budget--) { s->failed_pc=0x0c0406e4u; return 0; }
target=code_base|0x0c040222u; r[16]=code_base|0x0c0406e8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0406e8u) { target=s->pc; goto dispatch; }
goto P_0c0406e8;
P_0c0406e6: /* original 0009, guest PC 0x0c0406e6 */
if(!s->budget--) { s->failed_pc=0x0c0406e6u; return 0; }
goto P_0c0406e8;
P_0c0406e8: /* original 1f04, guest PC 0x0c0406e8 */
if(!s->budget--) { s->failed_pc=0x0c0406e8u; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c0406ea;
P_0c0406ea: /* original ee00, guest PC 0x0c0406ea */
if(!s->budget--) { s->failed_pc=0x0c0406eau; return 0; }
r[14]=0x00000000u;
goto P_0c0406ec;
P_0c0406ec: /* original a008, guest PC 0x0c0406ec */
if(!s->budget--) { s->failed_pc=0x0c0406ecu; return 0; }
goto P_0c040700;
P_0c0406ee: /* original 0009, guest PC 0x0c0406ee */
if(!s->budget--) { s->failed_pc=0x0c0406eeu; return 0; }
goto P_0c0406f0;
P_0c0406f0: /* original 940c, guest PC 0x0c0406f0 */
if(!s->budget--) { s->failed_pc=0x0c0406f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04070cu,2);
goto P_0c0406f2;
P_0c0406f2: /* original b414, guest PC 0x0c0406f2 */
if(!s->budget--) { s->failed_pc=0x0c0406f2u; return 0; }
target=code_base|0x0c040f1eu; r[16]=code_base|0x0c0406f6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0406f6u) { target=s->pc; goto dispatch; }
goto P_0c0406f6;
P_0c0406f4: /* original 0009, guest PC 0x0c0406f4 */
if(!s->budget--) { s->failed_pc=0x0c0406f4u; return 0; }
goto P_0c0406f6;
P_0c0406f6: /* original 2008, guest PC 0x0c0406f6 */
if(!s->budget--) { s->failed_pc=0x0c0406f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0406f8;
P_0c0406f8: /* original 8b01, guest PC 0x0c0406f8 */
if(!s->budget--) { s->failed_pc=0x0c0406f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0406fe; }
goto P_0c0406fa;
P_0c0406fa: /* original a00b, guest PC 0x0c0406fa */
if(!s->budget--) { s->failed_pc=0x0c0406fau; return 0; }
goto P_0c040714;
P_0c0406fc: /* original 0009, guest PC 0x0c0406fc */
if(!s->budget--) { s->failed_pc=0x0c0406fcu; return 0; }
goto P_0c0406fe;
P_0c0406fe: /* original 7e01, guest PC 0x0c0406fe */
if(!s->budget--) { s->failed_pc=0x0c0406feu; return 0; }
r[14]+=0x00000001u;
goto P_0c040700;
P_0c040700: /* original d303, guest PC 0x0c040700 */
if(!s->budget--) { s->failed_pc=0x0c040700u; return 0; }
r[3]=read(ram,0x0c040710u,4);
goto P_0c040702;
P_0c040702: /* original 3e33, guest PC 0x0c040702 */
if(!s->budget--) { s->failed_pc=0x0c040702u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c040704;
P_0c040704: /* original 8bf4, guest PC 0x0c040704 */
if(!s->budget--) { s->failed_pc=0x0c040704u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0406f0; }
goto P_0c040706;
P_0c040706: /* original 9002, guest PC 0x0c040706 */
if(!s->budget--) { s->failed_pc=0x0c040706u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04070eu,2);
goto P_0c040708;
P_0c040708: /* original a058, guest PC 0x0c040708 */
if(!s->budget--) { s->failed_pc=0x0c040708u; return 0; }
goto P_0c0407bc;
P_0c04070a: /* original 0009, guest PC 0x0c04070a */
if(!s->budget--) { s->failed_pc=0x0c04070au; return 0; }
if(!vf3_matrix_family(0x0c04070cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04070cu; return 0; } return 1;
P_0c040714: /* original ee00, guest PC 0x0c040714 */
if(!s->budget--) { s->failed_pc=0x0c040714u; return 0; }
r[14]=0x00000000u;
goto P_0c040716;
P_0c040716: /* original a007, guest PC 0x0c040716 */
if(!s->budget--) { s->failed_pc=0x0c040716u; return 0; }
goto P_0c040728;
P_0c040718: /* original 0009, guest PC 0x0c040718 */
if(!s->budget--) { s->failed_pc=0x0c040718u; return 0; }
goto P_0c04071a;
P_0c04071a: /* original d322, guest PC 0x0c04071a */
if(!s->budget--) { s->failed_pc=0x0c04071au; return 0; }
r[3]=read(ram,0x0c0407a4u,4);
goto P_0c04071c;
P_0c04071c: /* original 6232, guest PC 0x0c04071c */
if(!s->budget--) { s->failed_pc=0x0c04071cu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c04071e;
P_0c04071e: /* original 2228, guest PC 0x0c04071e */
if(!s->budget--) { s->failed_pc=0x0c04071eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c040720;
P_0c040720: /* original 8901, guest PC 0x0c040720 */
if(!s->budget--) { s->failed_pc=0x0c040720u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040726; }
goto P_0c040722;
P_0c040722: /* original a007, guest PC 0x0c040722 */
if(!s->budget--) { s->failed_pc=0x0c040722u; return 0; }
goto P_0c040734;
P_0c040724: /* original 0009, guest PC 0x0c040724 */
if(!s->budget--) { s->failed_pc=0x0c040724u; return 0; }
goto P_0c040726;
P_0c040726: /* original 7e01, guest PC 0x0c040726 */
if(!s->budget--) { s->failed_pc=0x0c040726u; return 0; }
r[14]+=0x00000001u;
goto P_0c040728;
P_0c040728: /* original d31f, guest PC 0x0c040728 */
if(!s->budget--) { s->failed_pc=0x0c040728u; return 0; }
r[3]=read(ram,0x0c0407a8u,4);
goto P_0c04072a;
P_0c04072a: /* original 3e33, guest PC 0x0c04072a */
if(!s->budget--) { s->failed_pc=0x0c04072au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c04072c;
P_0c04072c: /* original 8bf5, guest PC 0x0c04072c */
if(!s->budget--) { s->failed_pc=0x0c04072cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04071a; }
goto P_0c04072e;
P_0c04072e: /* original 9037, guest PC 0x0c04072e */
if(!s->budget--) { s->failed_pc=0x0c04072eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0407a0u,2);
goto P_0c040730;
P_0c040730: /* original a044, guest PC 0x0c040730 */
if(!s->budget--) { s->failed_pc=0x0c040730u; return 0; }
goto P_0c0407bc;
P_0c040732: /* original 0009, guest PC 0x0c040732 */
if(!s->budget--) { s->failed_pc=0x0c040732u; return 0; }
goto P_0c040734;
P_0c040734: /* original 63f2, guest PC 0x0c040734 */
if(!s->budget--) { s->failed_pc=0x0c040734u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c040736;
P_0c040736: /* original 2338, guest PC 0x0c040736 */
if(!s->budget--) { s->failed_pc=0x0c040736u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c040738;
P_0c040738: /* original 8911, guest PC 0x0c040738 */
if(!s->budget--) { s->failed_pc=0x0c040738u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04075e; }
goto P_0c04073a;
P_0c04073a: /* original 66f2, guest PC 0x0c04073a */
if(!s->budget--) { s->failed_pc=0x0c04073au; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c04073c;
P_0c04073c: /* original 53f3, guest PC 0x0c04073c */
if(!s->budget--) { s->failed_pc=0x0c04073cu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c04073e;
P_0c04073e: /* original 55f4, guest PC 0x0c04073e */
if(!s->budget--) { s->failed_pc=0x0c04073eu; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c040740;
P_0c040740: /* original 353c, guest PC 0x0c040740 */
if(!s->budget--) { s->failed_pc=0x0c040740u; return 0; }
r[5]+=r[3];
goto P_0c040742;
P_0c040742: /* original 54f4, guest PC 0x0c040742 */
if(!s->budget--) { s->failed_pc=0x0c040742u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c040744;
P_0c040744: /* original bcbc, guest PC 0x0c040744 */
if(!s->budget--) { s->failed_pc=0x0c040744u; return 0; }
target=code_base|0x0c0400c0u; r[16]=code_base|0x0c040748u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c040748u) { target=s->pc; goto dispatch; }
goto P_0c040748;
P_0c040746: /* original 0009, guest PC 0x0c040746 */
if(!s->budget--) { s->failed_pc=0x0c040746u; return 0; }
goto P_0c040748;
P_0c040748: /* original 1f01, guest PC 0x0c040748 */
if(!s->budget--) { s->failed_pc=0x0c040748u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c04074a;
P_0c04074a: /* original 2008, guest PC 0x0c04074a */
if(!s->budget--) { s->failed_pc=0x0c04074au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04074c;
P_0c04074c: /* original 8901, guest PC 0x0c04074c */
if(!s->budget--) { s->failed_pc=0x0c04074cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040752; }
goto P_0c04074e;
P_0c04074e: /* original a035, guest PC 0x0c04074e */
if(!s->budget--) { s->failed_pc=0x0c04074eu; return 0; }
goto P_0c0407bc;
P_0c040750: /* original 0009, guest PC 0x0c040750 */
if(!s->budget--) { s->failed_pc=0x0c040750u; return 0; }
goto P_0c040752;
P_0c040752: /* original a000, guest PC 0x0c040752 */
if(!s->budget--) { s->failed_pc=0x0c040752u; return 0; }
goto P_0c040756;
P_0c040754: /* original 0009, guest PC 0x0c040754 */
if(!s->budget--) { s->failed_pc=0x0c040754u; return 0; }
goto P_0c040756;
P_0c040756: /* original bcf1, guest PC 0x0c040756 */
if(!s->budget--) { s->failed_pc=0x0c040756u; return 0; }
target=code_base|0x0c04013cu; r[16]=code_base|0x0c04075au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04075au) { target=s->pc; goto dispatch; }
goto P_0c04075a;
P_0c040758: /* original 0009, guest PC 0x0c040758 */
if(!s->budget--) { s->failed_pc=0x0c040758u; return 0; }
goto P_0c04075a;
P_0c04075a: /* original 2008, guest PC 0x0c04075a */
if(!s->budget--) { s->failed_pc=0x0c04075au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04075c;
P_0c04075c: /* original 8bfb, guest PC 0x0c04075c */
if(!s->budget--) { s->failed_pc=0x0c04075cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040756; }
goto P_0c04075e;
P_0c04075e: /* original 5df6, guest PC 0x0c04075e */
if(!s->budget--) { s->failed_pc=0x0c04075eu; return 0; }
r[13]=read(ram,r[15]+24,4);
goto P_0c040760;
P_0c040760: /* original 5cf4, guest PC 0x0c040760 */
if(!s->budget--) { s->failed_pc=0x0c040760u; return 0; }
r[12]=read(ram,r[15]+16,4);
goto P_0c040762;
P_0c040762: /* original ee00, guest PC 0x0c040762 */
if(!s->budget--) { s->failed_pc=0x0c040762u; return 0; }
r[14]=0x00000000u;
goto P_0c040764;
P_0c040764: /* original a005, guest PC 0x0c040764 */
if(!s->budget--) { s->failed_pc=0x0c040764u; return 0; }
goto P_0c040772;
P_0c040766: /* original 0009, guest PC 0x0c040766 */
if(!s->budget--) { s->failed_pc=0x0c040766u; return 0; }
goto P_0c040768;
P_0c040768: /* original 62c3, guest PC 0x0c040768 */
if(!s->budget--) { s->failed_pc=0x0c040768u; return 0; }
r[2]=r[12];
goto P_0c04076a;
P_0c04076a: /* original 7c04, guest PC 0x0c04076a */
if(!s->budget--) { s->failed_pc=0x0c04076au; return 0; }
r[12]+=0x00000004u;
goto P_0c04076c;
P_0c04076c: /* original 63d6, guest PC 0x0c04076c */
if(!s->budget--) { s->failed_pc=0x0c04076cu; return 0; }
tmp=read(ram,r[13],4);
r[13]+=4;
r[3]=tmp;
goto P_0c04076e;
P_0c04076e: /* original 2232, guest PC 0x0c04076e */
if(!s->budget--) { s->failed_pc=0x0c04076eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c040770;
P_0c040770: /* original 7e01, guest PC 0x0c040770 */
if(!s->budget--) { s->failed_pc=0x0c040770u; return 0; }
r[14]+=0x00000001u;
goto P_0c040772;
P_0c040772: /* original 52f3, guest PC 0x0c040772 */
if(!s->budget--) { s->failed_pc=0x0c040772u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c040774;
P_0c040774: /* original 4209, guest PC 0x0c040774 */
if(!s->budget--) { s->failed_pc=0x0c040774u; return 0; }
r[2]>>=2;
goto P_0c040776;
P_0c040776: /* original 3e22, guest PC 0x0c040776 */
if(!s->budget--) { s->failed_pc=0x0c040776u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[2])!=0);
goto P_0c040778;
P_0c040778: /* original 8bf6, guest PC 0x0c040778 */
if(!s->budget--) { s->failed_pc=0x0c040778u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040768; }
goto P_0c04077a;
P_0c04077a: /* original e201, guest PC 0x0c04077a */
if(!s->budget--) { s->failed_pc=0x0c04077au; return 0; }
r[2]=0x00000001u;
goto P_0c04077c;
P_0c04077c: /* original d30b, guest PC 0x0c04077c */
if(!s->budget--) { s->failed_pc=0x0c04077cu; return 0; }
r[3]=read(ram,0x0c0407acu,4);
goto P_0c04077e;
P_0c04077e: /* original 2322, guest PC 0x0c04077e */
if(!s->budget--) { s->failed_pc=0x0c04077eu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c040780;
P_0c040780: /* original ee00, guest PC 0x0c040780 */
if(!s->budget--) { s->failed_pc=0x0c040780u; return 0; }
r[14]=0x00000000u;
goto P_0c040782;
P_0c040782: /* original a007, guest PC 0x0c040782 */
if(!s->budget--) { s->failed_pc=0x0c040782u; return 0; }
goto P_0c040794;
P_0c040784: /* original 0009, guest PC 0x0c040784 */
if(!s->budget--) { s->failed_pc=0x0c040784u; return 0; }
goto P_0c040786;
P_0c040786: /* original d207, guest PC 0x0c040786 */
if(!s->budget--) { s->failed_pc=0x0c040786u; return 0; }
r[2]=read(ram,0x0c0407a4u,4);
goto P_0c040788;
P_0c040788: /* original 6322, guest PC 0x0c040788 */
if(!s->budget--) { s->failed_pc=0x0c040788u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c04078a;
P_0c04078a: /* original 2338, guest PC 0x0c04078a */
if(!s->budget--) { s->failed_pc=0x0c04078au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04078c;
P_0c04078c: /* original 8b01, guest PC 0x0c04078c */
if(!s->budget--) { s->failed_pc=0x0c04078cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040792; }
goto P_0c04078e;
P_0c04078e: /* original a00f, guest PC 0x0c04078e */
if(!s->budget--) { s->failed_pc=0x0c04078eu; return 0; }
goto P_0c0407b0;
P_0c040790: /* original 0009, guest PC 0x0c040790 */
if(!s->budget--) { s->failed_pc=0x0c040790u; return 0; }
goto P_0c040792;
P_0c040792: /* original 7e01, guest PC 0x0c040792 */
if(!s->budget--) { s->failed_pc=0x0c040792u; return 0; }
r[14]+=0x00000001u;
goto P_0c040794;
P_0c040794: /* original d204, guest PC 0x0c040794 */
if(!s->budget--) { s->failed_pc=0x0c040794u; return 0; }
r[2]=read(ram,0x0c0407a8u,4);
goto P_0c040796;
P_0c040796: /* original 3e23, guest PC 0x0c040796 */
if(!s->budget--) { s->failed_pc=0x0c040796u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c040798;
P_0c040798: /* original 8bf5, guest PC 0x0c040798 */
if(!s->budget--) { s->failed_pc=0x0c040798u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040786; }
goto P_0c04079a;
P_0c04079a: /* original 9001, guest PC 0x0c04079a */
if(!s->budget--) { s->failed_pc=0x0c04079au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0407a0u,2);
goto P_0c04079c;
P_0c04079c: /* original a00e, guest PC 0x0c04079c */
if(!s->budget--) { s->failed_pc=0x0c04079cu; return 0; }
goto P_0c0407bc;
P_0c04079e: /* original 0009, guest PC 0x0c04079e */
if(!s->budget--) { s->failed_pc=0x0c04079eu; return 0; }
if(!vf3_matrix_family(0x0c0407a0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0407a0u; return 0; } return 1;
P_0c0407b0: /* original e200, guest PC 0x0c0407b0 */
if(!s->budget--) { s->failed_pc=0x0c0407b0u; return 0; }
r[2]=0x00000000u;
goto P_0c0407b2;
P_0c0407b2: /* original d30e, guest PC 0x0c0407b2 */
if(!s->budget--) { s->failed_pc=0x0c0407b2u; return 0; }
r[3]=read(ram,0x0c0407ecu,4);
goto P_0c0407b4;
P_0c0407b4: /* original 2322, guest PC 0x0c0407b4 */
if(!s->budget--) { s->failed_pc=0x0c0407b4u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0407b6;
P_0c0407b6: /* original e000, guest PC 0x0c0407b6 */
if(!s->budget--) { s->failed_pc=0x0c0407b6u; return 0; }
r[0]=0x00000000u;
goto P_0c0407b8;
P_0c0407b8: /* original a000, guest PC 0x0c0407b8 */
if(!s->budget--) { s->failed_pc=0x0c0407b8u; return 0; }
goto P_0c0407bc;
P_0c0407ba: /* original 0009, guest PC 0x0c0407ba */
if(!s->budget--) { s->failed_pc=0x0c0407bau; return 0; }
goto P_0c0407bc;
P_0c0407bc: /* original 7f1c, guest PC 0x0c0407bc */
if(!s->budget--) { s->failed_pc=0x0c0407bcu; return 0; }
r[15]+=0x0000001cu;
goto P_0c0407be;
P_0c0407be: /* original 4f26, guest PC 0x0c0407be */
if(!s->budget--) { s->failed_pc=0x0c0407beu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0407c0;
P_0c0407c0: /* original 6cf6, guest PC 0x0c0407c0 */
if(!s->budget--) { s->failed_pc=0x0c0407c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0407c2;
P_0c0407c2: /* original 6df6, guest PC 0x0c0407c2 */
if(!s->budget--) { s->failed_pc=0x0c0407c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0407c4;
P_0c0407c4: /* original 6ef6, guest PC 0x0c0407c4 */
if(!s->budget--) { s->failed_pc=0x0c0407c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0407c6;
P_0c0407c6: /* original 000b, guest PC 0x0c0407c6 */
if(!s->budget--) { s->failed_pc=0x0c0407c6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0407c8: /* original 0009, guest PC 0x0c0407c8 */
if(!s->budget--) { s->failed_pc=0x0c0407c8u; return 0; }
if(!vf3_matrix_family(0x0c0407cau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0407cau; return 0; } return 1;
P_0c040f1e: /* original 7ffc, guest PC 0x0c040f1e */
if(!s->budget--) { s->failed_pc=0x0c040f1eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c040f20;
P_0c040f20: /* original 2f42, guest PC 0x0c040f20 */
if(!s->budget--) { s->failed_pc=0x0c040f20u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c040f22;
P_0c040f22: /* original 60f2, guest PC 0x0c040f22 */
if(!s->budget--) { s->failed_pc=0x0c040f22u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c040f24;
P_0c040f24: /* original c880, guest PC 0x0c040f24 */
if(!s->budget--) { s->failed_pc=0x0c040f24u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c040f26;
P_0c040f26: /* original 8b03, guest PC 0x0c040f26 */
if(!s->budget--) { s->failed_pc=0x0c040f26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040f30; }
goto P_0c040f28;
P_0c040f28: /* original e0fe, guest PC 0x0c040f28 */
if(!s->budget--) { s->failed_pc=0x0c040f28u; return 0; }
r[0]=0xfffffffeu;
goto P_0c040f2a;
P_0c040f2a: /* original 7f04, guest PC 0x0c040f2a */
if(!s->budget--) { s->failed_pc=0x0c040f2au; return 0; }
r[15]+=0x00000004u;
goto P_0c040f2c;
P_0c040f2c: /* original 000b, guest PC 0x0c040f2c */
if(!s->budget--) { s->failed_pc=0x0c040f2cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f2e: /* original 0009, guest PC 0x0c040f2e */
if(!s->budget--) { s->failed_pc=0x0c040f2eu; return 0; }
goto P_0c040f30;
P_0c040f30: /* original d30d, guest PC 0x0c040f30 */
if(!s->budget--) { s->failed_pc=0x0c040f30u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f32;
P_0c040f32: /* original 6232, guest PC 0x0c040f32 */
if(!s->budget--) { s->failed_pc=0x0c040f32u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040f34;
P_0c040f34: /* original 6122, guest PC 0x0c040f34 */
if(!s->budget--) { s->failed_pc=0x0c040f34u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c040f36;
P_0c040f36: /* original 2118, guest PC 0x0c040f36 */
if(!s->budget--) { s->failed_pc=0x0c040f36u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c040f38;
P_0c040f38: /* original 8903, guest PC 0x0c040f38 */
if(!s->budget--) { s->failed_pc=0x0c040f38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040f42; }
goto P_0c040f3a;
P_0c040f3a: /* original e0ff, guest PC 0x0c040f3a */
if(!s->budget--) { s->failed_pc=0x0c040f3au; return 0; }
r[0]=0xffffffffu;
goto P_0c040f3c;
P_0c040f3c: /* original 7f04, guest PC 0x0c040f3c */
if(!s->budget--) { s->failed_pc=0x0c040f3cu; return 0; }
r[15]+=0x00000004u;
goto P_0c040f3e;
P_0c040f3e: /* original 000b, guest PC 0x0c040f3e */
if(!s->budget--) { s->failed_pc=0x0c040f3eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f40: /* original 0009, guest PC 0x0c040f40 */
if(!s->budget--) { s->failed_pc=0x0c040f40u; return 0; }
goto P_0c040f42;
P_0c040f42: /* original d309, guest PC 0x0c040f42 */
if(!s->budget--) { s->failed_pc=0x0c040f42u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f44;
P_0c040f44: /* original 6232, guest PC 0x0c040f44 */
if(!s->budget--) { s->failed_pc=0x0c040f44u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040f46;
P_0c040f46: /* original 7204, guest PC 0x0c040f46 */
if(!s->budget--) { s->failed_pc=0x0c040f46u; return 0; }
r[2]+=0x00000004u;
goto P_0c040f48;
P_0c040f48: /* original 2322, guest PC 0x0c040f48 */
if(!s->budget--) { s->failed_pc=0x0c040f48u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c040f4a;
P_0c040f4a: /* original 72fc, guest PC 0x0c040f4a */
if(!s->budget--) { s->failed_pc=0x0c040f4au; return 0; }
r[2]+=0xfffffffcu;
goto P_0c040f4c;
P_0c040f4c: /* original 63f2, guest PC 0x0c040f4c */
if(!s->budget--) { s->failed_pc=0x0c040f4cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c040f4e;
P_0c040f4e: /* original 2232, guest PC 0x0c040f4e */
if(!s->budget--) { s->failed_pc=0x0c040f4eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c040f50;
P_0c040f50: /* original d206, guest PC 0x0c040f50 */
if(!s->budget--) { s->failed_pc=0x0c040f50u; return 0; }
r[2]=read(ram,0x0c040f6cu,4);
goto P_0c040f52;
P_0c040f52: /* original d305, guest PC 0x0c040f52 */
if(!s->budget--) { s->failed_pc=0x0c040f52u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f54;
P_0c040f54: /* original 6132, guest PC 0x0c040f54 */
if(!s->budget--) { s->failed_pc=0x0c040f54u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c040f56;
P_0c040f56: /* original 3120, guest PC 0x0c040f56 */
if(!s->budget--) { s->failed_pc=0x0c040f56u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c040f58;
P_0c040f58: /* original 8b02, guest PC 0x0c040f58 */
if(!s->budget--) { s->failed_pc=0x0c040f58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040f60; }
goto P_0c040f5a;
P_0c040f5a: /* original d305, guest PC 0x0c040f5a */
if(!s->budget--) { s->failed_pc=0x0c040f5au; return 0; }
r[3]=read(ram,0x0c040f70u,4);
goto P_0c040f5c;
P_0c040f5c: /* original d002, guest PC 0x0c040f5c */
if(!s->budget--) { s->failed_pc=0x0c040f5cu; return 0; }
r[0]=read(ram,0x0c040f68u,4);
goto P_0c040f5e;
P_0c040f5e: /* original 2032, guest PC 0x0c040f5e */
if(!s->budget--) { s->failed_pc=0x0c040f5eu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c040f60;
P_0c040f60: /* original e000, guest PC 0x0c040f60 */
if(!s->budget--) { s->failed_pc=0x0c040f60u; return 0; }
r[0]=0x00000000u;
goto P_0c040f62;
P_0c040f62: /* original 7f04, guest PC 0x0c040f62 */
if(!s->budget--) { s->failed_pc=0x0c040f62u; return 0; }
r[15]+=0x00000004u;
goto P_0c040f64;
P_0c040f64: /* original 000b, guest PC 0x0c040f64 */
if(!s->budget--) { s->failed_pc=0x0c040f64u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f66: /* original 0009, guest PC 0x0c040f66 */
if(!s->budget--) { s->failed_pc=0x0c040f66u; return 0; }
if(!vf3_matrix_family(0x0c040f68u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040f68u; return 0; } return 1;
P_0c046314: /* original 000b, guest PC 0x0c046314 */
if(!s->budget--) { s->failed_pc=0x0c046314u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c046316: /* original 0009, guest PC 0x0c046316 */
if(!s->budget--) { s->failed_pc=0x0c046316u; return 0; }
if(!vf3_matrix_family(0x0c046318u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c046318u; return 0; } return 1;
P_0c09571c: /* original d21c, guest PC 0x0c09571c */
if(!s->budget--) { s->failed_pc=0x0c09571cu; return 0; }
r[2]=read(ram,0x0c095790u,4);
goto P_0c09571e;
P_0c09571e: /* original 6322, guest PC 0x0c09571e */
if(!s->budget--) { s->failed_pc=0x0c09571eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c095720;
P_0c095720: /* original 432b, guest PC 0x0c095720 */
if(!s->budget--) { s->failed_pc=0x0c095720u; return 0; }
target=r[3];
r[4]=0x00000001u;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
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
P_0c095722: /* original e401, guest PC 0x0c095722 */
if(!s->budget--) { s->failed_pc=0x0c095722u; return 0; }
r[4]=0x00000001u;
if(!vf3_matrix_family(0x0c095724u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095724u; return 0; } return 1;
P_0c096864: /* original 2fe6, guest PC 0x0c096864 */
if(!s->budget--) { s->failed_pc=0x0c096864u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c096866;
P_0c096866: /* original 4f22, guest PC 0x0c096866 */
if(!s->budget--) { s->failed_pc=0x0c096866u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c096868;
P_0c096868: /* original 7ff8, guest PC 0x0c096868 */
if(!s->budget--) { s->failed_pc=0x0c096868u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c09686a;
P_0c09686a: /* original 2f42, guest PC 0x0c09686a */
if(!s->budget--) { s->failed_pc=0x0c09686au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09686c;
P_0c09686c: /* original d311, guest PC 0x0c09686c */
if(!s->budget--) { s->failed_pc=0x0c09686cu; return 0; }
r[3]=read(ram,0x0c0968b4u,4);
goto P_0c09686e;
P_0c09686e: /* original 430b, guest PC 0x0c09686e */
if(!s->budget--) { s->failed_pc=0x0c09686eu; return 0; }
target=r[3];
r[16]=code_base|0x0c096872u;
write(ram,r[15]+4,r[5],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096872u) { target=s->pc; goto dispatch; }
goto P_0c096872;
P_0c096870: /* original 1f51, guest PC 0x0c096870 */
if(!s->budget--) { s->failed_pc=0x0c096870u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c096872;
P_0c096872: /* original 6e03, guest PC 0x0c096872 */
if(!s->budget--) { s->failed_pc=0x0c096872u; return 0; }
r[14]=r[0];
goto P_0c096874;
P_0c096874: /* original 2ee8, guest PC 0x0c096874 */
if(!s->budget--) { s->failed_pc=0x0c096874u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c096876;
P_0c096876: /* original 8905, guest PC 0x0c096876 */
if(!s->budget--) { s->failed_pc=0x0c096876u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096884; }
goto P_0c096878;
P_0c096878: /* original d30f, guest PC 0x0c096878 */
if(!s->budget--) { s->failed_pc=0x0c096878u; return 0; }
r[3]=read(ram,0x0c0968b8u,4);
goto P_0c09687a;
P_0c09687a: /* original 430b, guest PC 0x0c09687a */
if(!s->budget--) { s->failed_pc=0x0c09687au; return 0; }
target=r[3];
r[16]=code_base|0x0c09687eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09687eu) { target=s->pc; goto dispatch; }
goto P_0c09687e;
P_0c09687c: /* original 64e3, guest PC 0x0c09687c */
if(!s->budget--) { s->failed_pc=0x0c09687cu; return 0; }
r[4]=r[14];
goto P_0c09687e;
P_0c09687e: /* original d20f, guest PC 0x0c09687e */
if(!s->budget--) { s->failed_pc=0x0c09687eu; return 0; }
r[2]=read(ram,0x0c0968bcu,4);
goto P_0c096880;
P_0c096880: /* original 420b, guest PC 0x0c096880 */
if(!s->budget--) { s->failed_pc=0x0c096880u; return 0; }
target=r[2];
r[16]=code_base|0x0c096884u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096884u) { target=s->pc; goto dispatch; }
goto P_0c096884;
P_0c096882: /* original 64e3, guest PC 0x0c096882 */
if(!s->budget--) { s->failed_pc=0x0c096882u; return 0; }
r[4]=r[14];
goto P_0c096884;
P_0c096884: /* original 0002, guest PC 0x0c096884 */
if(!s->budget--) { s->failed_pc=0x0c096884u; return 0; }
r[0]=r[17];
goto P_0c096886;
P_0c096886: /* original 9313, guest PC 0x0c096886 */
if(!s->budget--) { s->failed_pc=0x0c096886u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0968b0u,2);
goto P_0c096888;
P_0c096888: /* original 2039, guest PC 0x0c096888 */
if(!s->budget--) { s->failed_pc=0x0c096888u; return 0; }
r[0]&=r[3];
goto P_0c09688a;
P_0c09688a: /* original cbe0, guest PC 0x0c09688a */
if(!s->budget--) { s->failed_pc=0x0c09688au; return 0; }
r[0]|=224u;
goto P_0c09688c;
P_0c09688c: /* original 400e, guest PC 0x0c09688c */
if(!s->budget--) { s->failed_pc=0x0c09688cu; return 0; }
r[17]=r[0];
goto P_0c09688e;
P_0c09688e: /* original d20c, guest PC 0x0c09688e */
if(!s->budget--) { s->failed_pc=0x0c09688eu; return 0; }
r[2]=read(ram,0x0c0968c0u,4);
goto P_0c096890;
P_0c096890: /* original 420b, guest PC 0x0c096890 */
if(!s->budget--) { s->failed_pc=0x0c096890u; return 0; }
target=r[2];
r[16]=code_base|0x0c096894u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096894u) { target=s->pc; goto dispatch; }
goto P_0c096894;
P_0c096892: /* original 0009, guest PC 0x0c096892 */
if(!s->budget--) { s->failed_pc=0x0c096892u; return 0; }
goto P_0c096894;
P_0c096894: /* original d10b, guest PC 0x0c096894 */
if(!s->budget--) { s->failed_pc=0x0c096894u; return 0; }
r[1]=read(ram,0x0c0968c4u,4);
goto P_0c096896;
P_0c096896: /* original 410b, guest PC 0x0c096896 */
if(!s->budget--) { s->failed_pc=0x0c096896u; return 0; }
target=r[1];
r[16]=code_base|0x0c09689au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09689au) { target=s->pc; goto dispatch; }
goto P_0c09689a;
P_0c096898: /* original 0009, guest PC 0x0c096898 */
if(!s->budget--) { s->failed_pc=0x0c096898u; return 0; }
goto P_0c09689a;
P_0c09689a: /* original 0002, guest PC 0x0c09689a */
if(!s->budget--) { s->failed_pc=0x0c09689au; return 0; }
r[0]=r[17];
goto P_0c09689c;
P_0c09689c: /* original 9208, guest PC 0x0c09689c */
if(!s->budget--) { s->failed_pc=0x0c09689cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0968b0u,2);
goto P_0c09689e;
P_0c09689e: /* original 2029, guest PC 0x0c09689e */
if(!s->budget--) { s->failed_pc=0x0c09689eu; return 0; }
r[0]&=r[2];
goto P_0c0968a0;
P_0c0968a0: /* original 400e, guest PC 0x0c0968a0 */
if(!s->budget--) { s->failed_pc=0x0c0968a0u; return 0; }
r[17]=r[0];
goto P_0c0968a2;
P_0c0968a2: /* original 64f2, guest PC 0x0c0968a2 */
if(!s->budget--) { s->failed_pc=0x0c0968a2u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0968a4;
P_0c0968a4: /* original 55f1, guest PC 0x0c0968a4 */
if(!s->budget--) { s->failed_pc=0x0c0968a4u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0968a6;
P_0c0968a6: /* original 7f08, guest PC 0x0c0968a6 */
if(!s->budget--) { s->failed_pc=0x0c0968a6u; return 0; }
r[15]+=0x00000008u;
goto P_0c0968a8;
P_0c0968a8: /* original 4f26, guest PC 0x0c0968a8 */
if(!s->budget--) { s->failed_pc=0x0c0968a8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0968aa;
P_0c0968aa: /* original d307, guest PC 0x0c0968aa */
if(!s->budget--) { s->failed_pc=0x0c0968aau; return 0; }
r[3]=read(ram,0x0c0968c8u,4);
goto P_0c0968ac;
P_0c0968ac: /* original 432b, guest PC 0x0c0968ac */
if(!s->budget--) { s->failed_pc=0x0c0968acu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c09571cu: goto P_0c09571c;
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
P_0c0968ae: /* original 6ef6, guest PC 0x0c0968ae */
if(!s->budget--) { s->failed_pc=0x0c0968aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0968b0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0968b0u; return 0; } return 1;
P_0c0a7908: /* original 2fe6, guest PC 0x0c0a7908 */
if(!s->budget--) { s->failed_pc=0x0c0a7908u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a790a;
P_0c0a790a: /* original c71a, guest PC 0x0c0a790a */
if(!s->budget--) { s->failed_pc=0x0c0a790au; return 0; }
r[0]=code_base|0x000a7974u;
goto P_0c0a790c;
P_0c0a790c: /* original 2fd6, guest PC 0x0c0a790c */
if(!s->budget--) { s->failed_pc=0x0c0a790cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a790e;
P_0c0a790e: /* original 2fc6, guest PC 0x0c0a790e */
if(!s->budget--) { s->failed_pc=0x0c0a790eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7910;
P_0c0a7910: /* original 2fb6, guest PC 0x0c0a7910 */
if(!s->budget--) { s->failed_pc=0x0c0a7910u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7912;
P_0c0a7912: /* original fffb, guest PC 0x0c0a7912 */
if(!s->budget--) { s->failed_pc=0x0c0a7912u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0a7914;
P_0c0a7914: /* original ffeb, guest PC 0x0c0a7914 */
if(!s->budget--) { s->failed_pc=0x0c0a7914u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0a7916;
P_0c0a7916: /* original ffdb, guest PC 0x0c0a7916 */
if(!s->budget--) { s->failed_pc=0x0c0a7916u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0a7918;
P_0c0a7918: /* original ffcb, guest PC 0x0c0a7918 */
if(!s->budget--) { s->failed_pc=0x0c0a7918u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0a791a;
P_0c0a791a: /* original 4f22, guest PC 0x0c0a791a */
if(!s->budget--) { s->failed_pc=0x0c0a791au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a791c;
P_0c0a791c: /* original ff5c, guest PC 0x0c0a791c */
if(!s->budget--) { s->failed_pc=0x0c0a791cu; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c0a791e;
P_0c0a791e: /* original f508, guest PC 0x0c0a791e */
if(!s->budget--) { s->failed_pc=0x0c0a791eu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0a7920;
P_0c0a7920: /* original e004, guest PC 0x0c0a7920 */
if(!s->budget--) { s->failed_pc=0x0c0a7920u; return 0; }
r[0]=0x00000004u;
goto P_0c0a7922;
P_0c0a7922: /* original 7fd8, guest PC 0x0c0a7922 */
if(!s->budget--) { s->failed_pc=0x0c0a7922u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c0a7924;
P_0c0a7924: /* original fd5c, guest PC 0x0c0a7924 */
if(!s->budget--) { s->failed_pc=0x0c0a7924u; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c0a7926;
P_0c0a7926: /* original 65f3, guest PC 0x0c0a7926 */
if(!s->budget--) { s->failed_pc=0x0c0a7926u; return 0; }
r[5]=r[15];
goto P_0c0a7928;
P_0c0a7928: /* original ff57, guest PC 0x0c0a7928 */
if(!s->budget--) { s->failed_pc=0x0c0a7928u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0a792a;
P_0c0a792a: /* original 7508, guest PC 0x0c0a792a */
if(!s->budget--) { s->failed_pc=0x0c0a792au; return 0; }
r[5]+=0x00000008u;
goto P_0c0a792c;
P_0c0a792c: /* original f59d, guest PC 0x0c0a792c */
if(!s->budget--) { s->failed_pc=0x0c0a792cu; return 0; }
fr[5]=0x3f800000u;
goto P_0c0a792e;
P_0c0a792e: /* original f455, guest PC 0x0c0a792e */
if(!s->budget--) { s->failed_pc=0x0c0a792eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0a7930;
P_0c0a7930: /* original 6b53, guest PC 0x0c0a7930 */
if(!s->budget--) { s->failed_pc=0x0c0a7930u; return 0; }
r[11]=r[5];
goto P_0c0a7932;
P_0c0a7932: /* original 8f01, guest PC 0x0c0a7932 */
if(!s->budget--) { s->failed_pc=0x0c0a7932u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,12,13);
if(!cond) { goto P_0c0a7938; }
goto P_0c0a7936;
P_0c0a7934: /* original fcdc, guest PC 0x0c0a7934 */
if(!s->budget--) { s->failed_pc=0x0c0a7934u; return 0; }
vf3_matrix_move(s,12,13);
goto P_0c0a7936;
P_0c0a7936: /* original f45c, guest PC 0x0c0a7936 */
if(!s->budget--) { s->failed_pc=0x0c0a7936u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0a7938;
P_0c0a7938: /* original ff55, guest PC 0x0c0a7938 */
if(!s->budget--) { s->failed_pc=0x0c0a7938u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[5]))!=0);
goto P_0c0a793a;
P_0c0a793a: /* original 8b00, guest PC 0x0c0a793a */
if(!s->budget--) { s->failed_pc=0x0c0a793au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a793e; }
goto P_0c0a793c;
P_0c0a793c: /* original ff5c, guest PC 0x0c0a793c */
if(!s->budget--) { s->failed_pc=0x0c0a793cu; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c0a793e;
P_0c0a793e: /* original 2448, guest PC 0x0c0a793e */
if(!s->budget--) { s->failed_pc=0x0c0a793eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a7940;
P_0c0a7940: /* original 8b1a, guest PC 0x0c0a7940 */
if(!s->budget--) { s->failed_pc=0x0c0a7940u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7978; }
goto P_0c0a7942;
P_0c0a7942: /* original e004, guest PC 0x0c0a7942 */
if(!s->budget--) { s->failed_pc=0x0c0a7942u; return 0; }
r[0]=0x00000004u;
goto P_0c0a7944;
P_0c0a7944: /* original fc5c, guest PC 0x0c0a7944 */
if(!s->budget--) { s->failed_pc=0x0c0a7944u; return 0; }
vf3_matrix_move(s,12,5);
goto P_0c0a7946;
P_0c0a7946: /* original ff57, guest PC 0x0c0a7946 */
if(!s->budget--) { s->failed_pc=0x0c0a7946u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0a7948;
P_0c0a7948: /* original a023, guest PC 0x0c0a7948 */
if(!s->budget--) { s->failed_pc=0x0c0a7948u; return 0; }
vf3_matrix_move(s,13,12);
goto P_0c0a7992;
P_0c0a794a: /* original fdcc, guest PC 0x0c0a794a */
if(!s->budget--) { s->failed_pc=0x0c0a794au; return 0; }
vf3_matrix_move(s,13,12);
if(!vf3_matrix_family(0x0c0a794cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a794cu; return 0; } return 1;
P_0c0a7978: /* original e201, guest PC 0x0c0a7978 */
if(!s->budget--) { s->failed_pc=0x0c0a7978u; return 0; }
r[2]=0x00000001u;
goto P_0c0a797a;
P_0c0a797a: /* original 2248, guest PC 0x0c0a797a */
if(!s->budget--) { s->failed_pc=0x0c0a797au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0a797c;
P_0c0a797c: /* original 8d01, guest PC 0x0c0a797c */
if(!s->budget--) { s->failed_pc=0x0c0a797cu; return 0; }
cond=r[17]&1u;
r[2]=0x00000002u;
if(cond) { goto P_0c0a7982; }
goto P_0c0a7980;
P_0c0a797e: /* original e202, guest PC 0x0c0a797e */
if(!s->budget--) { s->failed_pc=0x0c0a797eu; return 0; }
r[2]=0x00000002u;
goto P_0c0a7980;
P_0c0a7980: /* original fc5c, guest PC 0x0c0a7980 */
if(!s->budget--) { s->failed_pc=0x0c0a7980u; return 0; }
vf3_matrix_move(s,12,5);
goto P_0c0a7982;
P_0c0a7982: /* original 2248, guest PC 0x0c0a7982 */
if(!s->budget--) { s->failed_pc=0x0c0a7982u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0a7984;
P_0c0a7984: /* original 8901, guest PC 0x0c0a7984 */
if(!s->budget--) { s->failed_pc=0x0c0a7984u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a798a; }
goto P_0c0a7986;
P_0c0a7986: /* original e004, guest PC 0x0c0a7986 */
if(!s->budget--) { s->failed_pc=0x0c0a7986u; return 0; }
r[0]=0x00000004u;
goto P_0c0a7988;
P_0c0a7988: /* original ff57, guest PC 0x0c0a7988 */
if(!s->budget--) { s->failed_pc=0x0c0a7988u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0a798a;
P_0c0a798a: /* original e304, guest PC 0x0c0a798a */
if(!s->budget--) { s->failed_pc=0x0c0a798au; return 0; }
r[3]=0x00000004u;
goto P_0c0a798c;
P_0c0a798c: /* original 2438, guest PC 0x0c0a798c */
if(!s->budget--) { s->failed_pc=0x0c0a798cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0a798e;
P_0c0a798e: /* original 8900, guest PC 0x0c0a798e */
if(!s->budget--) { s->failed_pc=0x0c0a798eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7992; }
goto P_0c0a7990;
P_0c0a7990: /* original fd5c, guest PC 0x0c0a7990 */
if(!s->budget--) { s->failed_pc=0x0c0a7990u; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c0a7992;
P_0c0a7992: /* original 6353, guest PC 0x0c0a7992 */
if(!s->budget--) { s->failed_pc=0x0c0a7992u; return 0; }
r[3]=r[5];
goto P_0c0a7994;
P_0c0a7994: /* original 6d33, guest PC 0x0c0a7994 */
if(!s->budget--) { s->failed_pc=0x0c0a7994u; return 0; }
r[13]=r[3];
goto P_0c0a7996;
P_0c0a7996: /* original 6e33, guest PC 0x0c0a7996 */
if(!s->budget--) { s->failed_pc=0x0c0a7996u; return 0; }
r[14]=r[3];
goto P_0c0a7998;
P_0c0a7998: /* original 6c33, guest PC 0x0c0a7998 */
if(!s->budget--) { s->failed_pc=0x0c0a7998u; return 0; }
r[12]=r[3];
goto P_0c0a799a;
P_0c0a799a: /* original 7c0c, guest PC 0x0c0a799a */
if(!s->budget--) { s->failed_pc=0x0c0a799au; return 0; }
r[12]+=0x0000000cu;
goto P_0c0a799c;
P_0c0a799c: /* original fe4c, guest PC 0x0c0a799c */
if(!s->budget--) { s->failed_pc=0x0c0a799cu; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c0a799e;
P_0c0a799e: /* original 2f32, guest PC 0x0c0a799e */
if(!s->budget--) { s->failed_pc=0x0c0a799eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a79a0;
P_0c0a79a0: /* original 7e08, guest PC 0x0c0a79a0 */
if(!s->budget--) { s->failed_pc=0x0c0a79a0u; return 0; }
r[14]+=0x00000008u;
goto P_0c0a79a2;
P_0c0a79a2: /* original f38d, guest PC 0x0c0a79a2 */
if(!s->budget--) { s->failed_pc=0x0c0a79a2u; return 0; }
fr[3]=0;
goto P_0c0a79a4;
P_0c0a79a4: /* original 7d04, guest PC 0x0c0a79a4 */
if(!s->budget--) { s->failed_pc=0x0c0a79a4u; return 0; }
r[13]+=0x00000004u;
goto P_0c0a79a6;
P_0c0a79a6: /* original f33a, guest PC 0x0c0a79a6 */
if(!s->budget--) { s->failed_pc=0x0c0a79a6u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0a79a8;
P_0c0a79a8: /* original fdea, guest PC 0x0c0a79a8 */
if(!s->budget--) { s->failed_pc=0x0c0a79a8u; return 0; }
vf3_matrix_store(s,ram,14,r[13]);
goto P_0c0a79aa;
P_0c0a79aa: /* original feea, guest PC 0x0c0a79aa */
if(!s->budget--) { s->failed_pc=0x0c0a79aau; return 0; }
vf3_matrix_store(s,ram,14,r[14]);
goto P_0c0a79ac;
P_0c0a79ac: /* original fcea, guest PC 0x0c0a79ac */
if(!s->budget--) { s->failed_pc=0x0c0a79acu; return 0; }
vf3_matrix_store(s,ram,14,r[12]);
goto P_0c0a79ae;
P_0c0a79ae: /* original d33f, guest PC 0x0c0a79ae */
if(!s->budget--) { s->failed_pc=0x0c0a79aeu; return 0; }
r[3]=read(ram,0x0c0a7aacu,4);
goto P_0c0a79b0;
P_0c0a79b0: /* original 430b, guest PC 0x0c0a79b0 */
if(!s->budget--) { s->failed_pc=0x0c0a79b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a79b4u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79b4u) { target=s->pc; goto dispatch; }
goto P_0c0a79b4;
P_0c0a79b2: /* original 64b3, guest PC 0x0c0a79b2 */
if(!s->budget--) { s->failed_pc=0x0c0a79b2u; return 0; }
r[4]=r[11];
goto P_0c0a79b4;
P_0c0a79b4: /* original d23e, guest PC 0x0c0a79b4 */
if(!s->budget--) { s->failed_pc=0x0c0a79b4u; return 0; }
r[2]=read(ram,0x0c0a7ab0u,4);
goto P_0c0a79b6;
P_0c0a79b6: /* original 420b, guest PC 0x0c0a79b6 */
if(!s->budget--) { s->failed_pc=0x0c0a79b6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a79bau;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79bau) { target=s->pc; goto dispatch; }
goto P_0c0a79ba;
P_0c0a79b8: /* original f4ec, guest PC 0x0c0a79b8 */
if(!s->budget--) { s->failed_pc=0x0c0a79b8u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0a79ba;
P_0c0a79ba: /* original 63f2, guest PC 0x0c0a79ba */
if(!s->budget--) { s->failed_pc=0x0c0a79bau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a79bc;
P_0c0a79bc: /* original e004, guest PC 0x0c0a79bc */
if(!s->budget--) { s->failed_pc=0x0c0a79bcu; return 0; }
r[0]=0x00000004u;
goto P_0c0a79be;
P_0c0a79be: /* original f38d, guest PC 0x0c0a79be */
if(!s->budget--) { s->failed_pc=0x0c0a79beu; return 0; }
fr[3]=0;
goto P_0c0a79c0;
P_0c0a79c0: /* original 65b3, guest PC 0x0c0a79c0 */
if(!s->budget--) { s->failed_pc=0x0c0a79c0u; return 0; }
r[5]=r[11];
goto P_0c0a79c2;
P_0c0a79c2: /* original f33a, guest PC 0x0c0a79c2 */
if(!s->budget--) { s->failed_pc=0x0c0a79c2u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0a79c4;
P_0c0a79c4: /* original f2fc, guest PC 0x0c0a79c4 */
if(!s->budget--) { s->failed_pc=0x0c0a79c4u; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c0a79c6;
P_0c0a79c6: /* original f2d2, guest PC 0x0c0a79c6 */
if(!s->budget--) { s->failed_pc=0x0c0a79c6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[13],r[18],'*');
goto P_0c0a79c8;
P_0c0a79c8: /* original fd2a, guest PC 0x0c0a79c8 */
if(!s->budget--) { s->failed_pc=0x0c0a79c8u; return 0; }
vf3_matrix_store(s,ram,2,r[13]);
goto P_0c0a79ca;
P_0c0a79ca: /* original f3f6, guest PC 0x0c0a79ca */
if(!s->budget--) { s->failed_pc=0x0c0a79cau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a79cc;
P_0c0a79cc: /* original f2fc, guest PC 0x0c0a79cc */
if(!s->budget--) { s->failed_pc=0x0c0a79ccu; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c0a79ce;
P_0c0a79ce: /* original ffc2, guest PC 0x0c0a79ce */
if(!s->budget--) { s->failed_pc=0x0c0a79ceu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[12],r[18],'*');
goto P_0c0a79d0;
P_0c0a79d0: /* original f232, guest PC 0x0c0a79d0 */
if(!s->budget--) { s->failed_pc=0x0c0a79d0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0a79d2;
P_0c0a79d2: /* original fe2a, guest PC 0x0c0a79d2 */
if(!s->budget--) { s->failed_pc=0x0c0a79d2u; return 0; }
vf3_matrix_store(s,ram,2,r[14]);
goto P_0c0a79d4;
P_0c0a79d4: /* original fcfa, guest PC 0x0c0a79d4 */
if(!s->budget--) { s->failed_pc=0x0c0a79d4u; return 0; }
vf3_matrix_store(s,ram,15,r[12]);
goto P_0c0a79d6;
P_0c0a79d6: /* original d337, guest PC 0x0c0a79d6 */
if(!s->budget--) { s->failed_pc=0x0c0a79d6u; return 0; }
r[3]=read(ram,0x0c0a7ab4u,4);
goto P_0c0a79d8;
P_0c0a79d8: /* original 430b, guest PC 0x0c0a79d8 */
if(!s->budget--) { s->failed_pc=0x0c0a79d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a79dcu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79dcu) { target=s->pc; goto dispatch; }
goto P_0c0a79dc;
P_0c0a79da: /* original e400, guest PC 0x0c0a79da */
if(!s->budget--) { s->failed_pc=0x0c0a79dau; return 0; }
r[4]=0x00000000u;
goto P_0c0a79dc;
P_0c0a79dc: /* original d236, guest PC 0x0c0a79dc */
if(!s->budget--) { s->failed_pc=0x0c0a79dcu; return 0; }
r[2]=read(ram,0x0c0a7ab8u,4);
goto P_0c0a79de;
P_0c0a79de: /* original f5e8, guest PC 0x0c0a79de */
if(!s->budget--) { s->failed_pc=0x0c0a79deu; return 0; }
vf3_matrix_load(s,ram,5,r[14]);
goto P_0c0a79e0;
P_0c0a79e0: /* original f6c8, guest PC 0x0c0a79e0 */
if(!s->budget--) { s->failed_pc=0x0c0a79e0u; return 0; }
vf3_matrix_load(s,ram,6,r[12]);
goto P_0c0a79e2;
P_0c0a79e2: /* original 420b, guest PC 0x0c0a79e2 */
if(!s->budget--) { s->failed_pc=0x0c0a79e2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a79e6u;
vf3_matrix_load(s,ram,4,r[13]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79e6u) { target=s->pc; goto dispatch; }
goto P_0c0a79e6;
P_0c0a79e4: /* original f4d8, guest PC 0x0c0a79e4 */
if(!s->budget--) { s->failed_pc=0x0c0a79e4u; return 0; }
vf3_matrix_load(s,ram,4,r[13]);
goto P_0c0a79e6;
P_0c0a79e6: /* original d335, guest PC 0x0c0a79e6 */
if(!s->budget--) { s->failed_pc=0x0c0a79e6u; return 0; }
r[3]=read(ram,0x0c0a7abcu,4);
goto P_0c0a79e8;
P_0c0a79e8: /* original e502, guest PC 0x0c0a79e8 */
if(!s->budget--) { s->failed_pc=0x0c0a79e8u; return 0; }
r[5]=0x00000002u;
goto P_0c0a79ea;
P_0c0a79ea: /* original 430b, guest PC 0x0c0a79ea */
if(!s->budget--) { s->failed_pc=0x0c0a79eau; return 0; }
target=r[3];
r[16]=code_base|0x0c0a79eeu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79eeu) { target=s->pc; goto dispatch; }
goto P_0c0a79ee;
P_0c0a79ec: /* original e400, guest PC 0x0c0a79ec */
if(!s->budget--) { s->failed_pc=0x0c0a79ecu; return 0; }
r[4]=0x00000000u;
goto P_0c0a79ee;
P_0c0a79ee: /* original d234, guest PC 0x0c0a79ee */
if(!s->budget--) { s->failed_pc=0x0c0a79eeu; return 0; }
r[2]=read(ram,0x0c0a7ac0u,4);
goto P_0c0a79f0;
P_0c0a79f0: /* original e501, guest PC 0x0c0a79f0 */
if(!s->budget--) { s->failed_pc=0x0c0a79f0u; return 0; }
r[5]=0x00000001u;
goto P_0c0a79f2;
P_0c0a79f2: /* original 420b, guest PC 0x0c0a79f2 */
if(!s->budget--) { s->failed_pc=0x0c0a79f2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a79f6u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79f6u) { target=s->pc; goto dispatch; }
goto P_0c0a79f6;
P_0c0a79f4: /* original e400, guest PC 0x0c0a79f4 */
if(!s->budget--) { s->failed_pc=0x0c0a79f4u; return 0; }
r[4]=0x00000000u;
goto P_0c0a79f6;
P_0c0a79f6: /* original 7f28, guest PC 0x0c0a79f6 */
if(!s->budget--) { s->failed_pc=0x0c0a79f6u; return 0; }
r[15]+=0x00000028u;
goto P_0c0a79f8;
P_0c0a79f8: /* original 4f26, guest PC 0x0c0a79f8 */
if(!s->budget--) { s->failed_pc=0x0c0a79f8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a79fa;
P_0c0a79fa: /* original fcf9, guest PC 0x0c0a79fa */
if(!s->budget--) { s->failed_pc=0x0c0a79fau; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a79fc;
P_0c0a79fc: /* original fdf9, guest PC 0x0c0a79fc */
if(!s->budget--) { s->failed_pc=0x0c0a79fcu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a79fe;
P_0c0a79fe: /* original fef9, guest PC 0x0c0a79fe */
if(!s->budget--) { s->failed_pc=0x0c0a79feu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a7a00;
P_0c0a7a00: /* original fff9, guest PC 0x0c0a7a00 */
if(!s->budget--) { s->failed_pc=0x0c0a7a00u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a7a02;
P_0c0a7a02: /* original 6bf6, guest PC 0x0c0a7a02 */
if(!s->budget--) { s->failed_pc=0x0c0a7a02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a7a04;
P_0c0a7a04: /* original 6cf6, guest PC 0x0c0a7a04 */
if(!s->budget--) { s->failed_pc=0x0c0a7a04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a7a06;
P_0c0a7a06: /* original 6df6, guest PC 0x0c0a7a06 */
if(!s->budget--) { s->failed_pc=0x0c0a7a06u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a7a08;
P_0c0a7a08: /* original 000b, guest PC 0x0c0a7a08 */
if(!s->budget--) { s->failed_pc=0x0c0a7a08u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a7a0a: /* original 6ef6, guest PC 0x0c0a7a0a */
if(!s->budget--) { s->failed_pc=0x0c0a7a0au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a7a0cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7a0cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
