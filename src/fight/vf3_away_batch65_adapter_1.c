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
int vf3_away_batch65_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0927e6u: goto P_0c0927e6;
case 0x0c0927e8u: goto P_0c0927e8;
case 0x0c0927eau: goto P_0c0927ea;
case 0x0c0927ecu: goto P_0c0927ec;
case 0x0c0927eeu: goto P_0c0927ee;
case 0x0c0927f0u: goto P_0c0927f0;
case 0x0c0927f2u: goto P_0c0927f2;
case 0x0c0927f4u: goto P_0c0927f4;
case 0x0c0927f6u: goto P_0c0927f6;
case 0x0c0927f8u: goto P_0c0927f8;
case 0x0c0927fau: goto P_0c0927fa;
case 0x0c0927fcu: goto P_0c0927fc;
case 0x0c0927feu: goto P_0c0927fe;
case 0x0c092800u: goto P_0c092800;
case 0x0c092802u: goto P_0c092802;
case 0x0c092804u: goto P_0c092804;
case 0x0c092806u: goto P_0c092806;
case 0x0c092808u: goto P_0c092808;
case 0x0c09280au: goto P_0c09280a;
case 0x0c09280cu: goto P_0c09280c;
case 0x0c09280eu: goto P_0c09280e;
case 0x0c092810u: goto P_0c092810;
case 0x0c092812u: goto P_0c092812;
case 0x0c092814u: goto P_0c092814;
case 0x0c092816u: goto P_0c092816;
case 0x0c092818u: goto P_0c092818;
case 0x0c09281au: goto P_0c09281a;
case 0x0c09281cu: goto P_0c09281c;
case 0x0c09281eu: goto P_0c09281e;
case 0x0c092820u: goto P_0c092820;
case 0x0c092822u: goto P_0c092822;
case 0x0c092824u: goto P_0c092824;
case 0x0c092826u: goto P_0c092826;
case 0x0c092828u: goto P_0c092828;
case 0x0c09282au: goto P_0c09282a;
case 0x0c09282cu: goto P_0c09282c;
case 0x0c09282eu: goto P_0c09282e;
case 0x0c092830u: goto P_0c092830;
case 0x0c092832u: goto P_0c092832;
case 0x0c092834u: goto P_0c092834;
case 0x0c092836u: goto P_0c092836;
case 0x0c092838u: goto P_0c092838;
case 0x0c09283au: goto P_0c09283a;
case 0x0c09283cu: goto P_0c09283c;
case 0x0c09283eu: goto P_0c09283e;
case 0x0c092840u: goto P_0c092840;
case 0x0c092842u: goto P_0c092842;
case 0x0c092844u: goto P_0c092844;
case 0x0c092846u: goto P_0c092846;
case 0x0c092848u: goto P_0c092848;
case 0x0c09284au: goto P_0c09284a;
case 0x0c09284cu: goto P_0c09284c;
case 0x0c09284eu: goto P_0c09284e;
case 0x0c092850u: goto P_0c092850;
case 0x0c092852u: goto P_0c092852;
case 0x0c092854u: goto P_0c092854;
case 0x0c092856u: goto P_0c092856;
case 0x0c092858u: goto P_0c092858;
case 0x0c09285au: goto P_0c09285a;
case 0x0c09285cu: goto P_0c09285c;
case 0x0c09285eu: goto P_0c09285e;
case 0x0c092860u: goto P_0c092860;
case 0x0c092862u: goto P_0c092862;
case 0x0c092884u: goto P_0c092884;
case 0x0c092886u: goto P_0c092886;
case 0x0c092888u: goto P_0c092888;
case 0x0c09288au: goto P_0c09288a;
case 0x0c09288cu: goto P_0c09288c;
case 0x0c09288eu: goto P_0c09288e;
case 0x0c092890u: goto P_0c092890;
case 0x0c092892u: goto P_0c092892;
case 0x0c092894u: goto P_0c092894;
case 0x0c092896u: goto P_0c092896;
case 0x0c092898u: goto P_0c092898;
case 0x0c09289au: goto P_0c09289a;
case 0x0c09289cu: goto P_0c09289c;
case 0x0c09289eu: goto P_0c09289e;
case 0x0c0928a0u: goto P_0c0928a0;
case 0x0c0928a2u: goto P_0c0928a2;
case 0x0c0928a4u: goto P_0c0928a4;
case 0x0c0928a6u: goto P_0c0928a6;
case 0x0c0928a8u: goto P_0c0928a8;
case 0x0c0928aau: goto P_0c0928aa;
case 0x0c0928acu: goto P_0c0928ac;
case 0x0c0928aeu: goto P_0c0928ae;
case 0x0c0928b0u: goto P_0c0928b0;
case 0x0c0928b2u: goto P_0c0928b2;
case 0x0c0928b4u: goto P_0c0928b4;
case 0x0c0928b6u: goto P_0c0928b6;
case 0x0c0928b8u: goto P_0c0928b8;
case 0x0c0928bau: goto P_0c0928ba;
case 0x0c0928bcu: goto P_0c0928bc;
case 0x0c0928beu: goto P_0c0928be;
case 0x0c0928c0u: goto P_0c0928c0;
case 0x0c0928c2u: goto P_0c0928c2;
case 0x0c0928c4u: goto P_0c0928c4;
case 0x0c0928c6u: goto P_0c0928c6;
case 0x0c0928c8u: goto P_0c0928c8;
case 0x0c0928cau: goto P_0c0928ca;
case 0x0c0928ccu: goto P_0c0928cc;
case 0x0c0928ceu: goto P_0c0928ce;
case 0x0c0928d0u: goto P_0c0928d0;
case 0x0c0928d2u: goto P_0c0928d2;
case 0x0c0928d4u: goto P_0c0928d4;
case 0x0c0928d6u: goto P_0c0928d6;
case 0x0c0928d8u: goto P_0c0928d8;
case 0x0c0928dau: goto P_0c0928da;
case 0x0c0928dcu: goto P_0c0928dc;
case 0x0c0928e4u: goto P_0c0928e4;
case 0x0c0928e6u: goto P_0c0928e6;
case 0x0c0928e8u: goto P_0c0928e8;
case 0x0c0928eau: goto P_0c0928ea;
case 0x0c0928ecu: goto P_0c0928ec;
case 0x0c0928eeu: goto P_0c0928ee;
case 0x0c0928f0u: goto P_0c0928f0;
case 0x0c0928f2u: goto P_0c0928f2;
case 0x0c0928f4u: goto P_0c0928f4;
case 0x0c0928f6u: goto P_0c0928f6;
case 0x0c0928f8u: goto P_0c0928f8;
case 0x0c0928fau: goto P_0c0928fa;
case 0x0c0928fcu: goto P_0c0928fc;
case 0x0c0928feu: goto P_0c0928fe;
case 0x0c092900u: goto P_0c092900;
case 0x0c092902u: goto P_0c092902;
case 0x0c092904u: goto P_0c092904;
case 0x0c092906u: goto P_0c092906;
case 0x0c092908u: goto P_0c092908;
case 0x0c09290au: goto P_0c09290a;
case 0x0c09290cu: goto P_0c09290c;
case 0x0c09290eu: goto P_0c09290e;
case 0x0c092910u: goto P_0c092910;
case 0x0c092912u: goto P_0c092912;
case 0x0c092914u: goto P_0c092914;
case 0x0c092916u: goto P_0c092916;
case 0x0c092918u: goto P_0c092918;
case 0x0c09291au: goto P_0c09291a;
case 0x0c09291cu: goto P_0c09291c;
case 0x0c09291eu: goto P_0c09291e;
case 0x0c092920u: goto P_0c092920;
case 0x0c092922u: goto P_0c092922;
case 0x0c092924u: goto P_0c092924;
case 0x0c092926u: goto P_0c092926;
case 0x0c092928u: goto P_0c092928;
case 0x0c09292au: goto P_0c09292a;
case 0x0c09292cu: goto P_0c09292c;
case 0x0c09292eu: goto P_0c09292e;
case 0x0c092930u: goto P_0c092930;
case 0x0c092932u: goto P_0c092932;
case 0x0c092934u: goto P_0c092934;
case 0x0c092936u: goto P_0c092936;
case 0x0c092938u: goto P_0c092938;
case 0x0c09293au: goto P_0c09293a;
case 0x0c09293cu: goto P_0c09293c;
case 0x0c09293eu: goto P_0c09293e;
case 0x0c092940u: goto P_0c092940;
case 0x0c092942u: goto P_0c092942;
case 0x0c092944u: goto P_0c092944;
case 0x0c092946u: goto P_0c092946;
case 0x0c092948u: goto P_0c092948;
case 0x0c09294au: goto P_0c09294a;
case 0x0c09294cu: goto P_0c09294c;
case 0x0c09294eu: goto P_0c09294e;
case 0x0c092950u: goto P_0c092950;
case 0x0c092952u: goto P_0c092952;
case 0x0c092954u: goto P_0c092954;
case 0x0c092956u: goto P_0c092956;
case 0x0c092958u: goto P_0c092958;
case 0x0c09295au: goto P_0c09295a;
case 0x0c09295cu: goto P_0c09295c;
case 0x0c09295eu: goto P_0c09295e;
case 0x0c092960u: goto P_0c092960;
case 0x0c092962u: goto P_0c092962;
case 0x0c092964u: goto P_0c092964;
case 0x0c092966u: goto P_0c092966;
case 0x0c092968u: goto P_0c092968;
case 0x0c09296au: goto P_0c09296a;
case 0x0c09296cu: goto P_0c09296c;
case 0x0c09296eu: goto P_0c09296e;
case 0x0c092970u: goto P_0c092970;
case 0x0c092972u: goto P_0c092972;
case 0x0c092974u: goto P_0c092974;
case 0x0c092976u: goto P_0c092976;
case 0x0c092978u: goto P_0c092978;
case 0x0c09297au: goto P_0c09297a;
case 0x0c09297cu: goto P_0c09297c;
case 0x0c09297eu: goto P_0c09297e;
case 0x0c092980u: goto P_0c092980;
case 0x0c092982u: goto P_0c092982;
case 0x0c092984u: goto P_0c092984;
case 0x0c092986u: goto P_0c092986;
case 0x0c092988u: goto P_0c092988;
case 0x0c09298au: goto P_0c09298a;
case 0x0c09298cu: goto P_0c09298c;
case 0x0c09298eu: goto P_0c09298e;
case 0x0c092990u: goto P_0c092990;
case 0x0c092992u: goto P_0c092992;
case 0x0c092994u: goto P_0c092994;
case 0x0c092996u: goto P_0c092996;
case 0x0c092998u: goto P_0c092998;
case 0x0c09299au: goto P_0c09299a;
case 0x0c09299cu: goto P_0c09299c;
case 0x0c09299eu: goto P_0c09299e;
case 0x0c0929a0u: goto P_0c0929a0;
case 0x0c0929a2u: goto P_0c0929a2;
case 0x0c0929a4u: goto P_0c0929a4;
case 0x0c0929a6u: goto P_0c0929a6;
case 0x0c0929a8u: goto P_0c0929a8;
case 0x0c0929aau: goto P_0c0929aa;
case 0x0c0929acu: goto P_0c0929ac;
case 0x0c0929aeu: goto P_0c0929ae;
case 0x0c0929b0u: goto P_0c0929b0;
case 0x0c0929b2u: goto P_0c0929b2;
case 0x0c0929b4u: goto P_0c0929b4;
case 0x0c0929b6u: goto P_0c0929b6;
case 0x0c0929b8u: goto P_0c0929b8;
case 0x0c0929bau: goto P_0c0929ba;
case 0x0c0929bcu: goto P_0c0929bc;
case 0x0c0929beu: goto P_0c0929be;
case 0x0c0929c0u: goto P_0c0929c0;
case 0x0c0929c2u: goto P_0c0929c2;
case 0x0c0929c4u: goto P_0c0929c4;
case 0x0c0929c6u: goto P_0c0929c6;
case 0x0c0929c8u: goto P_0c0929c8;
case 0x0c0929cau: goto P_0c0929ca;
case 0x0c0929ccu: goto P_0c0929cc;
case 0x0c0929ceu: goto P_0c0929ce;
case 0x0c0929d0u: goto P_0c0929d0;
case 0x0c0929d2u: goto P_0c0929d2;
case 0x0c0929d4u: goto P_0c0929d4;
case 0x0c0929d6u: goto P_0c0929d6;
case 0x0c0929d8u: goto P_0c0929d8;
case 0x0c0929dau: goto P_0c0929da;
case 0x0c0929dcu: goto P_0c0929dc;
case 0x0c0929deu: goto P_0c0929de;
case 0x0c0929e0u: goto P_0c0929e0;
case 0x0c0929e2u: goto P_0c0929e2;
case 0x0c0929e4u: goto P_0c0929e4;
case 0x0c0929e6u: goto P_0c0929e6;
case 0x0c0929e8u: goto P_0c0929e8;
case 0x0c0929eau: goto P_0c0929ea;
case 0x0c0929ecu: goto P_0c0929ec;
case 0x0c0929eeu: goto P_0c0929ee;
case 0x0c0929f0u: goto P_0c0929f0;
case 0x0c0929f2u: goto P_0c0929f2;
case 0x0c0929f4u: goto P_0c0929f4;
case 0x0c0929f6u: goto P_0c0929f6;
case 0x0c0929f8u: goto P_0c0929f8;
case 0x0c0929fau: goto P_0c0929fa;
case 0x0c0929fcu: goto P_0c0929fc;
case 0x0c0929feu: goto P_0c0929fe;
case 0x0c092a00u: goto P_0c092a00;
case 0x0c092a02u: goto P_0c092a02;
case 0x0c092a04u: goto P_0c092a04;
case 0x0c092a06u: goto P_0c092a06;
case 0x0c092a08u: goto P_0c092a08;
case 0x0c092a0au: goto P_0c092a0a;
case 0x0c092a0cu: goto P_0c092a0c;
case 0x0c092a0eu: goto P_0c092a0e;
case 0x0c092a10u: goto P_0c092a10;
case 0x0c092a12u: goto P_0c092a12;
case 0x0c092a14u: goto P_0c092a14;
case 0x0c092a16u: goto P_0c092a16;
case 0x0c092a18u: goto P_0c092a18;
case 0x0c092a1au: goto P_0c092a1a;
case 0x0c092a1cu: goto P_0c092a1c;
case 0x0c092a1eu: goto P_0c092a1e;
case 0x0c092a20u: goto P_0c092a20;
case 0x0c092a22u: goto P_0c092a22;
case 0x0c092a24u: goto P_0c092a24;
case 0x0c092a26u: goto P_0c092a26;
case 0x0c092a28u: goto P_0c092a28;
case 0x0c092a2au: goto P_0c092a2a;
case 0x0c092a2cu: goto P_0c092a2c;
case 0x0c092a2eu: goto P_0c092a2e;
case 0x0c092a30u: goto P_0c092a30;
case 0x0c092a32u: goto P_0c092a32;
case 0x0c092a34u: goto P_0c092a34;
case 0x0c092a36u: goto P_0c092a36;
case 0x0c092a38u: goto P_0c092a38;
case 0x0c092a3au: goto P_0c092a3a;
case 0x0c092a3cu: goto P_0c092a3c;
case 0x0c092a3eu: goto P_0c092a3e;
case 0x0c092a40u: goto P_0c092a40;
case 0x0c092a42u: goto P_0c092a42;
case 0x0c092a44u: goto P_0c092a44;
case 0x0c092a46u: goto P_0c092a46;
case 0x0c092a48u: goto P_0c092a48;
case 0x0c092a4au: goto P_0c092a4a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0927e6: /* original 2fe6, guest PC 0x0c0927e6 */
if(!s->budget--) { s->failed_pc=0x0c0927e6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0927e8;
P_0c0927e8: /* original 6e63, guest PC 0x0c0927e8 */
if(!s->budget--) { s->failed_pc=0x0c0927e8u; return 0; }
r[14]=r[6];
goto P_0c0927ea;
P_0c0927ea: /* original 2fd6, guest PC 0x0c0927ea */
if(!s->budget--) { s->failed_pc=0x0c0927eau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0927ec;
P_0c0927ec: /* original 6d43, guest PC 0x0c0927ec */
if(!s->budget--) { s->failed_pc=0x0c0927ecu; return 0; }
r[13]=r[4];
goto P_0c0927ee;
P_0c0927ee: /* original 2fc6, guest PC 0x0c0927ee */
if(!s->budget--) { s->failed_pc=0x0c0927eeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0927f0;
P_0c0927f0: /* original 2fb6, guest PC 0x0c0927f0 */
if(!s->budget--) { s->failed_pc=0x0c0927f0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0927f2;
P_0c0927f2: /* original 6b53, guest PC 0x0c0927f2 */
if(!s->budget--) { s->failed_pc=0x0c0927f2u; return 0; }
r[11]=r[5];
goto P_0c0927f4;
P_0c0927f4: /* original 2fa6, guest PC 0x0c0927f4 */
if(!s->budget--) { s->failed_pc=0x0c0927f4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0927f6;
P_0c0927f6: /* original ea00, guest PC 0x0c0927f6 */
if(!s->budget--) { s->failed_pc=0x0c0927f6u; return 0; }
r[10]=0x00000000u;
goto P_0c0927f8;
P_0c0927f8: /* original 2f96, guest PC 0x0c0927f8 */
if(!s->budget--) { s->failed_pc=0x0c0927f8u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0927fa;
P_0c0927fa: /* original 4f22, guest PC 0x0c0927fa */
if(!s->budget--) { s->failed_pc=0x0c0927fau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0927fc;
P_0c0927fc: /* original 7fbc, guest PC 0x0c0927fc */
if(!s->budget--) { s->failed_pc=0x0c0927fcu; return 0; }
r[15]+=0xffffffbcu;
goto P_0c0927fe;
P_0c0927fe: /* original 1f73, guest PC 0x0c0927fe */
if(!s->budget--) { s->failed_pc=0x0c0927feu; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c092800;
P_0c092800: /* original e034, guest PC 0x0c092800 */
if(!s->budget--) { s->failed_pc=0x0c092800u; return 0; }
r[0]=0x00000034u;
goto P_0c092802;
P_0c092802: /* original 03ed, guest PC 0x0c092802 */
if(!s->budget--) { s->failed_pc=0x0c092802u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c092804;
P_0c092804: /* original e201, guest PC 0x0c092804 */
if(!s->budget--) { s->failed_pc=0x0c092804u; return 0; }
r[2]=0x00000001u;
goto P_0c092806;
P_0c092806: /* original 633d, guest PC 0x0c092806 */
if(!s->budget--) { s->failed_pc=0x0c092806u; return 0; }
r[3]=r[3]&65535u;
goto P_0c092808;
P_0c092808: /* original 2328, guest PC 0x0c092808 */
if(!s->budget--) { s->failed_pc=0x0c092808u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c09280a;
P_0c09280a: /* original 8f02, guest PC 0x0c09280a */
if(!s->budget--) { s->failed_pc=0x0c09280au; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(!cond) { goto P_0c092812; }
goto P_0c09280e;
P_0c09280c: /* original 2f32, guest PC 0x0c09280c */
if(!s->budget--) { s->failed_pc=0x0c09280cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09280e;
P_0c09280e: /* original a114, guest PC 0x0c09280e */
if(!s->budget--) { s->failed_pc=0x0c09280eu; return 0; }
goto P_0c092a3a;
P_0c092810: /* original 0009, guest PC 0x0c092810 */
if(!s->budget--) { s->failed_pc=0x0c092810u; return 0; }
goto P_0c092812;
P_0c092812: /* original e037, guest PC 0x0c092812 */
if(!s->budget--) { s->failed_pc=0x0c092812u; return 0; }
r[0]=0x00000037u;
goto P_0c092814;
P_0c092814: /* original d219, guest PC 0x0c092814 */
if(!s->budget--) { s->failed_pc=0x0c092814u; return 0; }
r[2]=read(ram,0x0c09287cu,4);
goto P_0c092816;
P_0c092816: /* original 0cec, guest PC 0x0c092816 */
if(!s->budget--) { s->failed_pc=0x0c092816u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c092818;
P_0c092818: /* original 60f2, guest PC 0x0c092818 */
if(!s->budget--) { s->failed_pc=0x0c092818u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c09281a;
P_0c09281a: /* original 63c3, guest PC 0x0c09281a */
if(!s->budget--) { s->failed_pc=0x0c09281au; return 0; }
r[3]=r[12];
goto P_0c09281c;
P_0c09281c: /* original 4308, guest PC 0x0c09281c */
if(!s->budget--) { s->failed_pc=0x0c09281cu; return 0; }
r[3]<<=2;
goto P_0c09281e;
P_0c09281e: /* original 4c00, guest PC 0x0c09281e */
if(!s->budget--) { s->failed_pc=0x0c09281eu; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c092820;
P_0c092820: /* original 3c3c, guest PC 0x0c092820 */
if(!s->budget--) { s->failed_pc=0x0c092820u; return 0; }
r[12]+=r[3];
goto P_0c092822;
P_0c092822: /* original c802, guest PC 0x0c092822 */
if(!s->budget--) { s->failed_pc=0x0c092822u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c092824;
P_0c092824: /* original 4c08, guest PC 0x0c092824 */
if(!s->budget--) { s->failed_pc=0x0c092824u; return 0; }
r[12]<<=2;
goto P_0c092826;
P_0c092826: /* original 8d5d, guest PC 0x0c092826 */
if(!s->budget--) { s->failed_pc=0x0c092826u; return 0; }
cond=r[17]&1u;
r[12]+=r[2];
if(cond) { goto P_0c0928e4; }
goto P_0c09282a;
P_0c092828: /* original 3c2c, guest PC 0x0c092828 */
if(!s->budget--) { s->failed_pc=0x0c092828u; return 0; }
r[12]+=r[2];
goto P_0c09282a;
P_0c09282a: /* original e068, guest PC 0x0c09282a */
if(!s->budget--) { s->failed_pc=0x0c09282au; return 0; }
r[0]=0x00000068u;
goto P_0c09282c;
P_0c09282c: /* original 03fe, guest PC 0x0c09282c */
if(!s->budget--) { s->failed_pc=0x0c09282cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c09282e;
P_0c09282e: /* original 2338, guest PC 0x0c09282e */
if(!s->budget--) { s->failed_pc=0x0c09282eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c092830;
P_0c092830: /* original 8b01, guest PC 0x0c092830 */
if(!s->budget--) { s->failed_pc=0x0c092830u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c092836; }
goto P_0c092832;
P_0c092832: /* original a102, guest PC 0x0c092832 */
if(!s->budget--) { s->failed_pc=0x0c092832u; return 0; }
goto P_0c092a3a;
P_0c092834: /* original 0009, guest PC 0x0c092834 */
if(!s->budget--) { s->failed_pc=0x0c092834u; return 0; }
goto P_0c092836;
P_0c092836: /* original e068, guest PC 0x0c092836 */
if(!s->budget--) { s->failed_pc=0x0c092836u; return 0; }
r[0]=0x00000068u;
goto P_0c092838;
P_0c092838: /* original 02fe, guest PC 0x0c092838 */
if(!s->budget--) { s->failed_pc=0x0c092838u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c09283a;
P_0c09283a: /* original e068, guest PC 0x0c09283a */
if(!s->budget--) { s->failed_pc=0x0c09283au; return 0; }
r[0]=0x00000068u;
goto P_0c09283c;
P_0c09283c: /* original 72ff, guest PC 0x0c09283c */
if(!s->budget--) { s->failed_pc=0x0c09283cu; return 0; }
r[2]+=0xffffffffu;
goto P_0c09283e;
P_0c09283e: /* original 0f26, guest PC 0x0c09283e */
if(!s->budget--) { s->failed_pc=0x0c09283eu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c092840;
P_0c092840: /* original 60f2, guest PC 0x0c092840 */
if(!s->budget--) { s->failed_pc=0x0c092840u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c092842;
P_0c092842: /* original c804, guest PC 0x0c092842 */
if(!s->budget--) { s->failed_pc=0x0c092842u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c092844;
P_0c092844: /* original 8d02, guest PC 0x0c092844 */
if(!s->budget--) { s->failed_pc=0x0c092844u; return 0; }
cond=r[17]&1u;
r[9]=0x00000058u;
if(cond) { goto P_0c09284c; }
goto P_0c092848;
P_0c092846: /* original e958, guest PC 0x0c092846 */
if(!s->budget--) { s->failed_pc=0x0c092846u; return 0; }
r[9]=0x00000058u;
goto P_0c092848;
P_0c092848: /* original a0f2, guest PC 0x0c092848 */
if(!s->budget--) { s->failed_pc=0x0c092848u; return 0; }
goto P_0c092a30;
P_0c09284a: /* original 0009, guest PC 0x0c09284a */
if(!s->budget--) { s->failed_pc=0x0c09284au; return 0; }
goto P_0c09284c;
P_0c09284c: /* original d20c, guest PC 0x0c09284c */
if(!s->budget--) { s->failed_pc=0x0c09284cu; return 0; }
r[2]=read(ram,0x0c092880u,4);
goto P_0c09284e;
P_0c09284e: /* original 66f3, guest PC 0x0c09284e */
if(!s->budget--) { s->failed_pc=0x0c09284eu; return 0; }
r[6]=r[15];
goto P_0c092850;
P_0c092850: /* original 65e3, guest PC 0x0c092850 */
if(!s->budget--) { s->failed_pc=0x0c092850u; return 0; }
r[5]=r[14];
goto P_0c092852;
P_0c092852: /* original 7604, guest PC 0x0c092852 */
if(!s->budget--) { s->failed_pc=0x0c092852u; return 0; }
r[6]+=0x00000004u;
goto P_0c092854;
P_0c092854: /* original 420b, guest PC 0x0c092854 */
if(!s->budget--) { s->failed_pc=0x0c092854u; return 0; }
target=r[2];
r[16]=code_base|0x0c092858u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092858u) { target=s->pc; goto dispatch; }
goto P_0c092858;
P_0c092856: /* original 64d3, guest PC 0x0c092856 */
if(!s->budget--) { s->failed_pc=0x0c092856u; return 0; }
r[4]=r[13];
goto P_0c092858;
P_0c092858: /* original 1f02, guest PC 0x0c092858 */
if(!s->budget--) { s->failed_pc=0x0c092858u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c09285a;
P_0c09285a: /* original 60f2, guest PC 0x0c09285a */
if(!s->budget--) { s->failed_pc=0x0c09285au; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c09285c;
P_0c09285c: /* original c840, guest PC 0x0c09285c */
if(!s->budget--) { s->failed_pc=0x0c09285cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c09285e;
P_0c09285e: /* original 8911, guest PC 0x0c09285e */
if(!s->budget--) { s->failed_pc=0x0c09285eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c092884; }
goto P_0c092860;
P_0c092860: /* original a011, guest PC 0x0c092860 */
if(!s->budget--) { s->failed_pc=0x0c092860u; return 0; }
r[4]=0x00000000u;
goto P_0c092886;
P_0c092862: /* original e400, guest PC 0x0c092862 */
if(!s->budget--) { s->failed_pc=0x0c092862u; return 0; }
r[4]=0x00000000u;
if(!vf3_matrix_family(0x0c092864u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c092864u; return 0; } return 1;
P_0c092884: /* original e401, guest PC 0x0c092884 */
if(!s->budget--) { s->failed_pc=0x0c092884u; return 0; }
r[4]=0x00000001u;
goto P_0c092886;
P_0c092886: /* original 60f2, guest PC 0x0c092886 */
if(!s->budget--) { s->failed_pc=0x0c092886u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c092888;
P_0c092888: /* original c820, guest PC 0x0c092888 */
if(!s->budget--) { s->failed_pc=0x0c092888u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c09288a;
P_0c09288a: /* original 8919, guest PC 0x0c09288a */
if(!s->budget--) { s->failed_pc=0x0c09288au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0928c0; }
goto P_0c09288c;
P_0c09288c: /* original e05c, guest PC 0x0c09288c */
if(!s->budget--) { s->failed_pc=0x0c09288cu; return 0; }
r[0]=0x0000005cu;
goto P_0c09288e;
P_0c09288e: /* original f3d6, guest PC 0x0c09288e */
if(!s->budget--) { s->failed_pc=0x0c09288eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c092890;
P_0c092890: /* original e074, guest PC 0x0c092890 */
if(!s->budget--) { s->failed_pc=0x0c092890u; return 0; }
r[0]=0x00000074u;
goto P_0c092892;
P_0c092892: /* original fd37, guest PC 0x0c092892 */
if(!s->budget--) { s->failed_pc=0x0c092892u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c092894;
P_0c092894: /* original e060, guest PC 0x0c092894 */
if(!s->budget--) { s->failed_pc=0x0c092894u; return 0; }
r[0]=0x00000060u;
goto P_0c092896;
P_0c092896: /* original f3d6, guest PC 0x0c092896 */
if(!s->budget--) { s->failed_pc=0x0c092896u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c092898;
P_0c092898: /* original e078, guest PC 0x0c092898 */
if(!s->budget--) { s->failed_pc=0x0c092898u; return 0; }
r[0]=0x00000078u;
goto P_0c09289a;
P_0c09289a: /* original fd37, guest PC 0x0c09289a */
if(!s->budget--) { s->failed_pc=0x0c09289au; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09289c;
P_0c09289c: /* original e064, guest PC 0x0c09289c */
if(!s->budget--) { s->failed_pc=0x0c09289cu; return 0; }
r[0]=0x00000064u;
goto P_0c09289e;
P_0c09289e: /* original f3d6, guest PC 0x0c09289e */
if(!s->budget--) { s->failed_pc=0x0c09289eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0928a0;
P_0c0928a0: /* original e07c, guest PC 0x0c0928a0 */
if(!s->budget--) { s->failed_pc=0x0c0928a0u; return 0; }
r[0]=0x0000007cu;
goto P_0c0928a2;
P_0c0928a2: /* original fd37, guest PC 0x0c0928a2 */
if(!s->budget--) { s->failed_pc=0x0c0928a2u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0928a4;
P_0c0928a4: /* original e020, guest PC 0x0c0928a4 */
if(!s->budget--) { s->failed_pc=0x0c0928a4u; return 0; }
r[0]=0x00000020u;
goto P_0c0928a6;
P_0c0928a6: /* original f3f6, guest PC 0x0c0928a6 */
if(!s->budget--) { s->failed_pc=0x0c0928a6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0928a8;
P_0c0928a8: /* original e068, guest PC 0x0c0928a8 */
if(!s->budget--) { s->failed_pc=0x0c0928a8u; return 0; }
r[0]=0x00000068u;
goto P_0c0928aa;
P_0c0928aa: /* original fd37, guest PC 0x0c0928aa */
if(!s->budget--) { s->failed_pc=0x0c0928aau; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0928ac;
P_0c0928ac: /* original e024, guest PC 0x0c0928ac */
if(!s->budget--) { s->failed_pc=0x0c0928acu; return 0; }
r[0]=0x00000024u;
goto P_0c0928ae;
P_0c0928ae: /* original f3f6, guest PC 0x0c0928ae */
if(!s->budget--) { s->failed_pc=0x0c0928aeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0928b0;
P_0c0928b0: /* original e06c, guest PC 0x0c0928b0 */
if(!s->budget--) { s->failed_pc=0x0c0928b0u; return 0; }
r[0]=0x0000006cu;
goto P_0c0928b2;
P_0c0928b2: /* original fd37, guest PC 0x0c0928b2 */
if(!s->budget--) { s->failed_pc=0x0c0928b2u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0928b4;
P_0c0928b4: /* original e028, guest PC 0x0c0928b4 */
if(!s->budget--) { s->failed_pc=0x0c0928b4u; return 0; }
r[0]=0x00000028u;
goto P_0c0928b6;
P_0c0928b6: /* original f3f6, guest PC 0x0c0928b6 */
if(!s->budget--) { s->failed_pc=0x0c0928b6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0928b8;
P_0c0928b8: /* original e070, guest PC 0x0c0928b8 */
if(!s->budget--) { s->failed_pc=0x0c0928b8u; return 0; }
r[0]=0x00000070u;
goto P_0c0928ba;
P_0c0928ba: /* original fd37, guest PC 0x0c0928ba */
if(!s->budget--) { s->failed_pc=0x0c0928bau; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0928bc;
P_0c0928bc: /* original afa0, guest PC 0x0c0928bc */
if(!s->budget--) { s->failed_pc=0x0c0928bcu; return 0; }
r[14]+=0x00000058u;
goto P_0c092800;
P_0c0928be: /* original 7e58, guest PC 0x0c0928be */
if(!s->budget--) { s->failed_pc=0x0c0928beu; return 0; }
r[14]+=0x00000058u;
goto P_0c0928c0;
P_0c0928c0: /* original 63f3, guest PC 0x0c0928c0 */
if(!s->budget--) { s->failed_pc=0x0c0928c0u; return 0; }
r[3]=r[15];
goto P_0c0928c2;
P_0c0928c2: /* original 2f36, guest PC 0x0c0928c2 */
if(!s->budget--) { s->failed_pc=0x0c0928c2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0928c4;
P_0c0928c4: /* original 62f3, guest PC 0x0c0928c4 */
if(!s->budget--) { s->failed_pc=0x0c0928c4u; return 0; }
r[2]=r[15];
goto P_0c0928c6;
P_0c0928c6: /* original 7224, guest PC 0x0c0928c6 */
if(!s->budget--) { s->failed_pc=0x0c0928c6u; return 0; }
r[2]+=0x00000024u;
goto P_0c0928c8;
P_0c0928c8: /* original 2f26, guest PC 0x0c0928c8 */
if(!s->budget--) { s->failed_pc=0x0c0928c8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0928ca;
P_0c0928ca: /* original e070, guest PC 0x0c0928ca */
if(!s->budget--) { s->failed_pc=0x0c0928cau; return 0; }
r[0]=0x00000070u;
goto P_0c0928cc;
P_0c0928cc: /* original 2f46, guest PC 0x0c0928cc */
if(!s->budget--) { s->failed_pc=0x0c0928ccu; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0928ce;
P_0c0928ce: /* original 65b3, guest PC 0x0c0928ce */
if(!s->budget--) { s->failed_pc=0x0c0928ceu; return 0; }
r[5]=r[11];
goto P_0c0928d0;
P_0c0928d0: /* original d303, guest PC 0x0c0928d0 */
if(!s->budget--) { s->failed_pc=0x0c0928d0u; return 0; }
r[3]=read(ram,0x0c0928e0u,4);
goto P_0c0928d2;
P_0c0928d2: /* original 66e3, guest PC 0x0c0928d2 */
if(!s->budget--) { s->failed_pc=0x0c0928d2u; return 0; }
r[6]=r[14];
goto P_0c0928d4;
P_0c0928d4: /* original 07fe, guest PC 0x0c0928d4 */
if(!s->budget--) { s->failed_pc=0x0c0928d4u; return 0; }
r[7]=read(ram,r[15]+r[0],4);
goto P_0c0928d6;
P_0c0928d6: /* original 430b, guest PC 0x0c0928d6 */
if(!s->budget--) { s->failed_pc=0x0c0928d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0928dau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0928dau) { target=s->pc; goto dispatch; }
goto P_0c0928da;
P_0c0928d8: /* original 64d3, guest PC 0x0c0928d8 */
if(!s->budget--) { s->failed_pc=0x0c0928d8u; return 0; }
r[4]=r[13];
goto P_0c0928da;
P_0c0928da: /* original a004, guest PC 0x0c0928da */
if(!s->budget--) { s->failed_pc=0x0c0928dau; return 0; }
r[15]+=0x0000000cu;
goto P_0c0928e6;
P_0c0928dc: /* original 7f0c, guest PC 0x0c0928dc */
if(!s->budget--) { s->failed_pc=0x0c0928dcu; return 0; }
r[15]+=0x0000000cu;
if(!vf3_matrix_family(0x0c0928deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0928deu; return 0; } return 1;
P_0c0928e4: /* original e938, guest PC 0x0c0928e4 */
if(!s->budget--) { s->failed_pc=0x0c0928e4u; return 0; }
r[9]=0x00000038u;
goto P_0c0928e6;
P_0c0928e6: /* original f3e8, guest PC 0x0c0928e6 */
if(!s->budget--) { s->failed_pc=0x0c0928e6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c0928e8;
P_0c0928e8: /* original e038, guest PC 0x0c0928e8 */
if(!s->budget--) { s->failed_pc=0x0c0928e8u; return 0; }
r[0]=0x00000038u;
goto P_0c0928ea;
P_0c0928ea: /* original 63f3, guest PC 0x0c0928ea */
if(!s->budget--) { s->failed_pc=0x0c0928eau; return 0; }
r[3]=r[15];
goto P_0c0928ec;
P_0c0928ec: /* original 7320, guest PC 0x0c0928ec */
if(!s->budget--) { s->failed_pc=0x0c0928ecu; return 0; }
r[3]+=0x00000020u;
goto P_0c0928ee;
P_0c0928ee: /* original ff37, guest PC 0x0c0928ee */
if(!s->budget--) { s->failed_pc=0x0c0928eeu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0928f0;
P_0c0928f0: /* original e004, guest PC 0x0c0928f0 */
if(!s->budget--) { s->failed_pc=0x0c0928f0u; return 0; }
r[0]=0x00000004u;
goto P_0c0928f2;
P_0c0928f2: /* original f3e6, guest PC 0x0c0928f2 */
if(!s->budget--) { s->failed_pc=0x0c0928f2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0928f4;
P_0c0928f4: /* original e03c, guest PC 0x0c0928f4 */
if(!s->budget--) { s->failed_pc=0x0c0928f4u; return 0; }
r[0]=0x0000003cu;
goto P_0c0928f6;
P_0c0928f6: /* original 65e3, guest PC 0x0c0928f6 */
if(!s->budget--) { s->failed_pc=0x0c0928f6u; return 0; }
r[5]=r[14];
goto P_0c0928f8;
P_0c0928f8: /* original 66c3, guest PC 0x0c0928f8 */
if(!s->budget--) { s->failed_pc=0x0c0928f8u; return 0; }
r[6]=r[12];
goto P_0c0928fa;
P_0c0928fa: /* original ff37, guest PC 0x0c0928fa */
if(!s->budget--) { s->failed_pc=0x0c0928fau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0928fc;
P_0c0928fc: /* original e008, guest PC 0x0c0928fc */
if(!s->budget--) { s->failed_pc=0x0c0928fcu; return 0; }
r[0]=0x00000008u;
goto P_0c0928fe;
P_0c0928fe: /* original f3e6, guest PC 0x0c0928fe */
if(!s->budget--) { s->failed_pc=0x0c0928feu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c092900;
P_0c092900: /* original e040, guest PC 0x0c092900 */
if(!s->budget--) { s->failed_pc=0x0c092900u; return 0; }
r[0]=0x00000040u;
goto P_0c092902;
P_0c092902: /* original ff37, guest PC 0x0c092902 */
if(!s->budget--) { s->failed_pc=0x0c092902u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c092904;
P_0c092904: /* original 2f36, guest PC 0x0c092904 */
if(!s->budget--) { s->failed_pc=0x0c092904u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c092906;
P_0c092906: /* original 62f3, guest PC 0x0c092906 */
if(!s->budget--) { s->failed_pc=0x0c092906u; return 0; }
r[2]=r[15];
goto P_0c092908;
P_0c092908: /* original 723c, guest PC 0x0c092908 */
if(!s->budget--) { s->failed_pc=0x0c092908u; return 0; }
r[2]+=0x0000003cu;
goto P_0c09290a;
P_0c09290a: /* original 2f26, guest PC 0x0c09290a */
if(!s->budget--) { s->failed_pc=0x0c09290au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09290c;
P_0c09290c: /* original d350, guest PC 0x0c09290c */
if(!s->budget--) { s->failed_pc=0x0c09290cu; return 0; }
r[3]=read(ram,0x0c092a50u,4);
goto P_0c09290e;
P_0c09290e: /* original 57f2, guest PC 0x0c09290e */
if(!s->budget--) { s->failed_pc=0x0c09290eu; return 0; }
r[7]=read(ram,r[15]+8,4);
goto P_0c092910;
P_0c092910: /* original 430b, guest PC 0x0c092910 */
if(!s->budget--) { s->failed_pc=0x0c092910u; return 0; }
target=r[3];
r[16]=code_base|0x0c092914u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092914u) { target=s->pc; goto dispatch; }
goto P_0c092914;
P_0c092912: /* original 64b3, guest PC 0x0c092912 */
if(!s->budget--) { s->failed_pc=0x0c092912u; return 0; }
r[4]=r[11];
goto P_0c092914;
P_0c092914: /* original 62f3, guest PC 0x0c092914 */
if(!s->budget--) { s->failed_pc=0x0c092914u; return 0; }
r[2]=r[15];
goto P_0c092916;
P_0c092916: /* original 7240, guest PC 0x0c092916 */
if(!s->budget--) { s->failed_pc=0x0c092916u; return 0; }
r[2]+=0x00000040u;
goto P_0c092918;
P_0c092918: /* original 2f26, guest PC 0x0c092918 */
if(!s->budget--) { s->failed_pc=0x0c092918u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09291a;
P_0c09291a: /* original 65b3, guest PC 0x0c09291a */
if(!s->budget--) { s->failed_pc=0x0c09291au; return 0; }
r[5]=r[11];
goto P_0c09291c;
P_0c09291c: /* original 63f3, guest PC 0x0c09291c */
if(!s->budget--) { s->failed_pc=0x0c09291cu; return 0; }
r[3]=r[15];
goto P_0c09291e;
P_0c09291e: /* original 7310, guest PC 0x0c09291e */
if(!s->budget--) { s->failed_pc=0x0c09291eu; return 0; }
r[3]+=0x00000010u;
goto P_0c092920;
P_0c092920: /* original 2f36, guest PC 0x0c092920 */
if(!s->budget--) { s->failed_pc=0x0c092920u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c092922;
P_0c092922: /* original 66e3, guest PC 0x0c092922 */
if(!s->budget--) { s->failed_pc=0x0c092922u; return 0; }
r[6]=r[14];
goto P_0c092924;
P_0c092924: /* original 2fc6, guest PC 0x0c092924 */
if(!s->budget--) { s->failed_pc=0x0c092924u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c092926;
P_0c092926: /* original d24b, guest PC 0x0c092926 */
if(!s->budget--) { s->failed_pc=0x0c092926u; return 0; }
r[2]=read(ram,0x0c092a54u,4);
goto P_0c092928;
P_0c092928: /* original 67f3, guest PC 0x0c092928 */
if(!s->budget--) { s->failed_pc=0x0c092928u; return 0; }
r[7]=r[15];
goto P_0c09292a;
P_0c09292a: /* original 771c, guest PC 0x0c09292a */
if(!s->budget--) { s->failed_pc=0x0c09292au; return 0; }
r[7]+=0x0000001cu;
goto P_0c09292c;
P_0c09292c: /* original 420b, guest PC 0x0c09292c */
if(!s->budget--) { s->failed_pc=0x0c09292cu; return 0; }
target=r[2];
r[16]=code_base|0x0c092930u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092930u) { target=s->pc; goto dispatch; }
goto P_0c092930;
P_0c09292e: /* original 64d3, guest PC 0x0c09292e */
if(!s->budget--) { s->failed_pc=0x0c09292eu; return 0; }
r[4]=r[13];
goto P_0c092930;
P_0c092930: /* original 63f3, guest PC 0x0c092930 */
if(!s->budget--) { s->failed_pc=0x0c092930u; return 0; }
r[3]=r[15];
goto P_0c092932;
P_0c092932: /* original 734c, guest PC 0x0c092932 */
if(!s->budget--) { s->failed_pc=0x0c092932u; return 0; }
r[3]+=0x0000004cu;
goto P_0c092934;
P_0c092934: /* original 2f36, guest PC 0x0c092934 */
if(!s->budget--) { s->failed_pc=0x0c092934u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c092936;
P_0c092936: /* original 65b3, guest PC 0x0c092936 */
if(!s->budget--) { s->failed_pc=0x0c092936u; return 0; }
r[5]=r[11];
goto P_0c092938;
P_0c092938: /* original d347, guest PC 0x0c092938 */
if(!s->budget--) { s->failed_pc=0x0c092938u; return 0; }
r[3]=read(ram,0x0c092a58u,4);
goto P_0c09293a;
P_0c09293a: /* original 66c3, guest PC 0x0c09293a */
if(!s->budget--) { s->failed_pc=0x0c09293au; return 0; }
r[6]=r[12];
goto P_0c09293c;
P_0c09293c: /* original 57f6, guest PC 0x0c09293c */
if(!s->budget--) { s->failed_pc=0x0c09293cu; return 0; }
r[7]=read(ram,r[15]+24,4);
goto P_0c09293e;
P_0c09293e: /* original 430b, guest PC 0x0c09293e */
if(!s->budget--) { s->failed_pc=0x0c09293eu; return 0; }
target=r[3];
r[16]=code_base|0x0c092942u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092942u) { target=s->pc; goto dispatch; }
goto P_0c092942;
P_0c092940: /* original 64d3, guest PC 0x0c092940 */
if(!s->budget--) { s->failed_pc=0x0c092940u; return 0; }
r[4]=r[13];
goto P_0c092942;
P_0c092942: /* original e050, guest PC 0x0c092942 */
if(!s->budget--) { s->failed_pc=0x0c092942u; return 0; }
r[0]=0x00000050u;
goto P_0c092944;
P_0c092944: /* original 67f3, guest PC 0x0c092944 */
if(!s->budget--) { s->failed_pc=0x0c092944u; return 0; }
r[7]=r[15];
goto P_0c092946;
P_0c092946: /* original f3f6, guest PC 0x0c092946 */
if(!s->budget--) { s->failed_pc=0x0c092946u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c092948;
P_0c092948: /* original e044, guest PC 0x0c092948 */
if(!s->budget--) { s->failed_pc=0x0c092948u; return 0; }
r[0]=0x00000044u;
goto P_0c09294a;
P_0c09294a: /* original 66c3, guest PC 0x0c09294a */
if(!s->budget--) { s->failed_pc=0x0c09294au; return 0; }
r[6]=r[12];
goto P_0c09294c;
P_0c09294c: /* original 65e3, guest PC 0x0c09294c */
if(!s->budget--) { s->failed_pc=0x0c09294cu; return 0; }
r[5]=r[14];
goto P_0c09294e;
P_0c09294e: /* original ff37, guest PC 0x0c09294e */
if(!s->budget--) { s->failed_pc=0x0c09294eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c092950;
P_0c092950: /* original e054, guest PC 0x0c092950 */
if(!s->budget--) { s->failed_pc=0x0c092950u; return 0; }
r[0]=0x00000054u;
goto P_0c092952;
P_0c092952: /* original f3f6, guest PC 0x0c092952 */
if(!s->budget--) { s->failed_pc=0x0c092952u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c092954;
P_0c092954: /* original e048, guest PC 0x0c092954 */
if(!s->budget--) { s->failed_pc=0x0c092954u; return 0; }
r[0]=0x00000048u;
goto P_0c092956;
P_0c092956: /* original 7744, guest PC 0x0c092956 */
if(!s->budget--) { s->failed_pc=0x0c092956u; return 0; }
r[7]+=0x00000044u;
goto P_0c092958;
P_0c092958: /* original ff37, guest PC 0x0c092958 */
if(!s->budget--) { s->failed_pc=0x0c092958u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09295a;
P_0c09295a: /* original e058, guest PC 0x0c09295a */
if(!s->budget--) { s->failed_pc=0x0c09295au; return 0; }
r[0]=0x00000058u;
goto P_0c09295c;
P_0c09295c: /* original f3f6, guest PC 0x0c09295c */
if(!s->budget--) { s->failed_pc=0x0c09295cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09295e;
P_0c09295e: /* original e04c, guest PC 0x0c09295e */
if(!s->budget--) { s->failed_pc=0x0c09295eu; return 0; }
r[0]=0x0000004cu;
goto P_0c092960;
P_0c092960: /* original ff37, guest PC 0x0c092960 */
if(!s->budget--) { s->failed_pc=0x0c092960u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c092962;
P_0c092962: /* original b085, guest PC 0x0c092962 */
if(!s->budget--) { s->failed_pc=0x0c092962u; return 0; }
target=code_base|0x0c092a70u; r[16]=code_base|0x0c092966u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092966u) { target=s->pc; goto dispatch; }
goto P_0c092966;
P_0c092964: /* original 64b3, guest PC 0x0c092964 */
if(!s->budget--) { s->failed_pc=0x0c092964u; return 0; }
r[4]=r[11];
goto P_0c092966;
P_0c092966: /* original 62f3, guest PC 0x0c092966 */
if(!s->budget--) { s->failed_pc=0x0c092966u; return 0; }
r[2]=r[15];
goto P_0c092968;
P_0c092968: /* original 7218, guest PC 0x0c092968 */
if(!s->budget--) { s->failed_pc=0x0c092968u; return 0; }
r[2]+=0x00000018u;
goto P_0c09296a;
P_0c09296a: /* original e07c, guest PC 0x0c09296a */
if(!s->budget--) { s->failed_pc=0x0c09296au; return 0; }
r[0]=0x0000007cu;
goto P_0c09296c;
P_0c09296c: /* original 2f26, guest PC 0x0c09296c */
if(!s->budget--) { s->failed_pc=0x0c09296cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09296e;
P_0c09296e: /* original 03fe, guest PC 0x0c09296e */
if(!s->budget--) { s->failed_pc=0x0c09296eu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c092970;
P_0c092970: /* original 65e3, guest PC 0x0c092970 */
if(!s->budget--) { s->failed_pc=0x0c092970u; return 0; }
r[5]=r[14];
goto P_0c092972;
P_0c092972: /* original 2f36, guest PC 0x0c092972 */
if(!s->budget--) { s->failed_pc=0x0c092972u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c092974;
P_0c092974: /* original 52fb, guest PC 0x0c092974 */
if(!s->budget--) { s->failed_pc=0x0c092974u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c092976;
P_0c092976: /* original 2f26, guest PC 0x0c092976 */
if(!s->budget--) { s->failed_pc=0x0c092976u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c092978;
P_0c092978: /* original 66f3, guest PC 0x0c092978 */
if(!s->budget--) { s->failed_pc=0x0c092978u; return 0; }
r[6]=r[15];
goto P_0c09297a;
P_0c09297a: /* original d338, guest PC 0x0c09297a */
if(!s->budget--) { s->failed_pc=0x0c09297au; return 0; }
r[3]=read(ram,0x0c092a5cu,4);
goto P_0c09297c;
P_0c09297c: /* original 67f3, guest PC 0x0c09297c */
if(!s->budget--) { s->failed_pc=0x0c09297cu; return 0; }
r[7]=r[15];
goto P_0c09297e;
P_0c09297e: /* original 7744, guest PC 0x0c09297e */
if(!s->budget--) { s->failed_pc=0x0c09297eu; return 0; }
r[7]+=0x00000044u;
goto P_0c092980;
P_0c092980: /* original 7650, guest PC 0x0c092980 */
if(!s->budget--) { s->failed_pc=0x0c092980u; return 0; }
r[6]+=0x00000050u;
goto P_0c092982;
P_0c092982: /* original 430b, guest PC 0x0c092982 */
if(!s->budget--) { s->failed_pc=0x0c092982u; return 0; }
target=r[3];
r[16]=code_base|0x0c092986u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092986u) { target=s->pc; goto dispatch; }
goto P_0c092986;
P_0c092984: /* original 64d3, guest PC 0x0c092984 */
if(!s->budget--) { s->failed_pc=0x0c092984u; return 0; }
r[4]=r[13];
goto P_0c092986;
P_0c092986: /* original 66f3, guest PC 0x0c092986 */
if(!s->budget--) { s->failed_pc=0x0c092986u; return 0; }
r[6]=r[15];
goto P_0c092988;
P_0c092988: /* original 65f3, guest PC 0x0c092988 */
if(!s->budget--) { s->failed_pc=0x0c092988u; return 0; }
r[5]=r[15];
goto P_0c09298a;
P_0c09298a: /* original 67f3, guest PC 0x0c09298a */
if(!s->budget--) { s->failed_pc=0x0c09298au; return 0; }
r[7]=r[15];
goto P_0c09298c;
P_0c09298c: /* original d234, guest PC 0x0c09298c */
if(!s->budget--) { s->failed_pc=0x0c09298cu; return 0; }
r[2]=read(ram,0x0c092a60u,4);
goto P_0c09298e;
P_0c09298e: /* original 7550, guest PC 0x0c09298e */
if(!s->budget--) { s->failed_pc=0x0c09298eu; return 0; }
r[5]+=0x00000050u;
goto P_0c092990;
P_0c092990: /* original 7738, guest PC 0x0c092990 */
if(!s->budget--) { s->failed_pc=0x0c092990u; return 0; }
r[7]+=0x00000038u;
goto P_0c092992;
P_0c092992: /* original 7644, guest PC 0x0c092992 */
if(!s->budget--) { s->failed_pc=0x0c092992u; return 0; }
r[6]+=0x00000044u;
goto P_0c092994;
P_0c092994: /* original 420b, guest PC 0x0c092994 */
if(!s->budget--) { s->failed_pc=0x0c092994u; return 0; }
target=r[2];
r[16]=code_base|0x0c092998u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092998u) { target=s->pc; goto dispatch; }
goto P_0c092998;
P_0c092996: /* original 64e3, guest PC 0x0c092996 */
if(!s->budget--) { s->failed_pc=0x0c092996u; return 0; }
r[4]=r[14];
goto P_0c092998;
P_0c092998: /* original 9058, guest PC 0x0c092998 */
if(!s->budget--) { s->failed_pc=0x0c092998u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092a4cu,2);
goto P_0c09299a;
P_0c09299a: /* original 67f3, guest PC 0x0c09299a */
if(!s->budget--) { s->failed_pc=0x0c09299au; return 0; }
r[7]=r[15];
goto P_0c09299c;
P_0c09299c: /* original d331, guest PC 0x0c09299c */
if(!s->budget--) { s->failed_pc=0x0c09299cu; return 0; }
r[3]=read(ram,0x0c092a64u,4);
goto P_0c09299e;
P_0c09299e: /* original 7738, guest PC 0x0c09299e */
if(!s->budget--) { s->failed_pc=0x0c09299eu; return 0; }
r[7]+=0x00000038u;
goto P_0c0929a0;
P_0c0929a0: /* original 05fe, guest PC 0x0c0929a0 */
if(!s->budget--) { s->failed_pc=0x0c0929a0u; return 0; }
r[5]=read(ram,r[15]+r[0],4);
goto P_0c0929a2;
P_0c0929a2: /* original 56f9, guest PC 0x0c0929a2 */
if(!s->budget--) { s->failed_pc=0x0c0929a2u; return 0; }
r[6]=read(ram,r[15]+36,4);
goto P_0c0929a4;
P_0c0929a4: /* original 430b, guest PC 0x0c0929a4 */
if(!s->budget--) { s->failed_pc=0x0c0929a4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0929a8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0929a8u) { target=s->pc; goto dispatch; }
goto P_0c0929a8;
P_0c0929a6: /* original 64d3, guest PC 0x0c0929a6 */
if(!s->budget--) { s->failed_pc=0x0c0929a6u; return 0; }
r[4]=r[13];
goto P_0c0929a8;
P_0c0929a8: /* original 52f9, guest PC 0x0c0929a8 */
if(!s->budget--) { s->failed_pc=0x0c0929a8u; return 0; }
r[2]=read(ram,r[15]+36,4);
goto P_0c0929aa;
P_0c0929aa: /* original e044, guest PC 0x0c0929aa */
if(!s->budget--) { s->failed_pc=0x0c0929aau; return 0; }
r[0]=0x00000044u;
goto P_0c0929ac;
P_0c0929ac: /* original 65a3, guest PC 0x0c0929ac */
if(!s->budget--) { s->failed_pc=0x0c0929acu; return 0; }
r[5]=r[10];
goto P_0c0929ae;
P_0c0929ae: /* original 66c3, guest PC 0x0c0929ae */
if(!s->budget--) { s->failed_pc=0x0c0929aeu; return 0; }
r[6]=r[12];
goto P_0c0929b0;
P_0c0929b0: /* original 2f26, guest PC 0x0c0929b0 */
if(!s->budget--) { s->failed_pc=0x0c0929b0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0929b2;
P_0c0929b2: /* original 63f3, guest PC 0x0c0929b2 */
if(!s->budget--) { s->failed_pc=0x0c0929b2u; return 0; }
r[3]=r[15];
goto P_0c0929b4;
P_0c0929b4: /* original 733c, guest PC 0x0c0929b4 */
if(!s->budget--) { s->failed_pc=0x0c0929b4u; return 0; }
r[3]+=0x0000003cu;
goto P_0c0929b6;
P_0c0929b6: /* original 2f36, guest PC 0x0c0929b6 */
if(!s->budget--) { s->failed_pc=0x0c0929b6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0929b8;
P_0c0929b8: /* original 62f3, guest PC 0x0c0929b8 */
if(!s->budget--) { s->failed_pc=0x0c0929b8u; return 0; }
r[2]=r[15];
goto P_0c0929ba;
P_0c0929ba: /* original 7264, guest PC 0x0c0929ba */
if(!s->budget--) { s->failed_pc=0x0c0929bau; return 0; }
r[2]+=0x00000064u;
goto P_0c0929bc;
P_0c0929bc: /* original 2f26, guest PC 0x0c0929bc */
if(!s->budget--) { s->failed_pc=0x0c0929bcu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0929be;
P_0c0929be: /* original 63f3, guest PC 0x0c0929be */
if(!s->budget--) { s->failed_pc=0x0c0929beu; return 0; }
r[3]=r[15];
goto P_0c0929c0;
P_0c0929c0: /* original 735c, guest PC 0x0c0929c0 */
if(!s->budget--) { s->failed_pc=0x0c0929c0u; return 0; }
r[3]+=0x0000005cu;
goto P_0c0929c2;
P_0c0929c2: /* original 2f36, guest PC 0x0c0929c2 */
if(!s->budget--) { s->failed_pc=0x0c0929c2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0929c4;
P_0c0929c4: /* original d328, guest PC 0x0c0929c4 */
if(!s->budget--) { s->failed_pc=0x0c0929c4u; return 0; }
r[3]=read(ram,0x0c092a68u,4);
goto P_0c0929c6;
P_0c0929c6: /* original 07fe, guest PC 0x0c0929c6 */
if(!s->budget--) { s->failed_pc=0x0c0929c6u; return 0; }
r[7]=read(ram,r[15]+r[0],4);
goto P_0c0929c8;
P_0c0929c8: /* original 430b, guest PC 0x0c0929c8 */
if(!s->budget--) { s->failed_pc=0x0c0929c8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0929ccu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0929ccu) { target=s->pc; goto dispatch; }
goto P_0c0929cc;
P_0c0929ca: /* original 64e3, guest PC 0x0c0929ca */
if(!s->budget--) { s->failed_pc=0x0c0929cau; return 0; }
r[4]=r[14];
goto P_0c0929cc;
P_0c0929cc: /* original 52fd, guest PC 0x0c0929cc */
if(!s->budget--) { s->failed_pc=0x0c0929ccu; return 0; }
r[2]=read(ram,r[15]+52,4);
goto P_0c0929ce;
P_0c0929ce: /* original 65b3, guest PC 0x0c0929ce */
if(!s->budget--) { s->failed_pc=0x0c0929ceu; return 0; }
r[5]=r[11];
goto P_0c0929d0;
P_0c0929d0: /* original 66e3, guest PC 0x0c0929d0 */
if(!s->budget--) { s->failed_pc=0x0c0929d0u; return 0; }
r[6]=r[14];
goto P_0c0929d2;
P_0c0929d2: /* original 2f26, guest PC 0x0c0929d2 */
if(!s->budget--) { s->failed_pc=0x0c0929d2u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0929d4;
P_0c0929d4: /* original 63f3, guest PC 0x0c0929d4 */
if(!s->budget--) { s->failed_pc=0x0c0929d4u; return 0; }
r[3]=r[15];
goto P_0c0929d6;
P_0c0929d6: /* original 7358, guest PC 0x0c0929d6 */
if(!s->budget--) { s->failed_pc=0x0c0929d6u; return 0; }
r[3]+=0x00000058u;
goto P_0c0929d8;
P_0c0929d8: /* original 2f36, guest PC 0x0c0929d8 */
if(!s->budget--) { s->failed_pc=0x0c0929d8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0929da;
P_0c0929da: /* original d224, guest PC 0x0c0929da */
if(!s->budget--) { s->failed_pc=0x0c0929dau; return 0; }
r[2]=read(ram,0x0c092a6cu,4);
goto P_0c0929dc;
P_0c0929dc: /* original 67f3, guest PC 0x0c0929dc */
if(!s->budget--) { s->failed_pc=0x0c0929dcu; return 0; }
r[7]=r[15];
goto P_0c0929de;
P_0c0929de: /* original 7768, guest PC 0x0c0929de */
if(!s->budget--) { s->failed_pc=0x0c0929deu; return 0; }
r[7]+=0x00000068u;
goto P_0c0929e0;
P_0c0929e0: /* original 420b, guest PC 0x0c0929e0 */
if(!s->budget--) { s->failed_pc=0x0c0929e0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0929e4u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0929e4u) { target=s->pc; goto dispatch; }
goto P_0c0929e4;
P_0c0929e2: /* original 64d3, guest PC 0x0c0929e2 */
if(!s->budget--) { s->failed_pc=0x0c0929e2u; return 0; }
r[4]=r[13];
goto P_0c0929e4;
P_0c0929e4: /* original e02c, guest PC 0x0c0929e4 */
if(!s->budget--) { s->failed_pc=0x0c0929e4u; return 0; }
r[0]=0x0000002cu;
goto P_0c0929e6;
P_0c0929e6: /* original 7f3c, guest PC 0x0c0929e6 */
if(!s->budget--) { s->failed_pc=0x0c0929e6u; return 0; }
r[15]+=0x0000003cu;
goto P_0c0929e8;
P_0c0929e8: /* original f3f6, guest PC 0x0c0929e8 */
if(!s->budget--) { s->failed_pc=0x0c0929e8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0929ea;
P_0c0929ea: /* original e030, guest PC 0x0c0929ea */
if(!s->budget--) { s->failed_pc=0x0c0929eau; return 0; }
r[0]=0x00000030u;
goto P_0c0929ec;
P_0c0929ec: /* original fe3a, guest PC 0x0c0929ec */
if(!s->budget--) { s->failed_pc=0x0c0929ecu; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c0929ee;
P_0c0929ee: /* original f3f6, guest PC 0x0c0929ee */
if(!s->budget--) { s->failed_pc=0x0c0929eeu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0929f0;
P_0c0929f0: /* original e004, guest PC 0x0c0929f0 */
if(!s->budget--) { s->failed_pc=0x0c0929f0u; return 0; }
r[0]=0x00000004u;
goto P_0c0929f2;
P_0c0929f2: /* original fe37, guest PC 0x0c0929f2 */
if(!s->budget--) { s->failed_pc=0x0c0929f2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0929f4;
P_0c0929f4: /* original e034, guest PC 0x0c0929f4 */
if(!s->budget--) { s->failed_pc=0x0c0929f4u; return 0; }
r[0]=0x00000034u;
goto P_0c0929f6;
P_0c0929f6: /* original f3f6, guest PC 0x0c0929f6 */
if(!s->budget--) { s->failed_pc=0x0c0929f6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0929f8;
P_0c0929f8: /* original e008, guest PC 0x0c0929f8 */
if(!s->budget--) { s->failed_pc=0x0c0929f8u; return 0; }
r[0]=0x00000008u;
goto P_0c0929fa;
P_0c0929fa: /* original fe37, guest PC 0x0c0929fa */
if(!s->budget--) { s->failed_pc=0x0c0929fau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0929fc;
P_0c0929fc: /* original e020, guest PC 0x0c0929fc */
if(!s->budget--) { s->failed_pc=0x0c0929fcu; return 0; }
r[0]=0x00000020u;
goto P_0c0929fe;
P_0c0929fe: /* original f3f6, guest PC 0x0c0929fe */
if(!s->budget--) { s->failed_pc=0x0c0929feu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c092a00;
P_0c092a00: /* original e00c, guest PC 0x0c092a00 */
if(!s->budget--) { s->failed_pc=0x0c092a00u; return 0; }
r[0]=0x0000000cu;
goto P_0c092a02;
P_0c092a02: /* original fe37, guest PC 0x0c092a02 */
if(!s->budget--) { s->failed_pc=0x0c092a02u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c092a04;
P_0c092a04: /* original e024, guest PC 0x0c092a04 */
if(!s->budget--) { s->failed_pc=0x0c092a04u; return 0; }
r[0]=0x00000024u;
goto P_0c092a06;
P_0c092a06: /* original f3f6, guest PC 0x0c092a06 */
if(!s->budget--) { s->failed_pc=0x0c092a06u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c092a08;
P_0c092a08: /* original e010, guest PC 0x0c092a08 */
if(!s->budget--) { s->failed_pc=0x0c092a08u; return 0; }
r[0]=0x00000010u;
goto P_0c092a0a;
P_0c092a0a: /* original fe37, guest PC 0x0c092a0a */
if(!s->budget--) { s->failed_pc=0x0c092a0au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c092a0c;
P_0c092a0c: /* original e028, guest PC 0x0c092a0c */
if(!s->budget--) { s->failed_pc=0x0c092a0cu; return 0; }
r[0]=0x00000028u;
goto P_0c092a0e;
P_0c092a0e: /* original f3f6, guest PC 0x0c092a0e */
if(!s->budget--) { s->failed_pc=0x0c092a0eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c092a10;
P_0c092a10: /* original e014, guest PC 0x0c092a10 */
if(!s->budget--) { s->failed_pc=0x0c092a10u; return 0; }
r[0]=0x00000014u;
goto P_0c092a12;
P_0c092a12: /* original fe37, guest PC 0x0c092a12 */
if(!s->budget--) { s->failed_pc=0x0c092a12u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c092a14;
P_0c092a14: /* original e02c, guest PC 0x0c092a14 */
if(!s->budget--) { s->failed_pc=0x0c092a14u; return 0; }
r[0]=0x0000002cu;
goto P_0c092a16;
P_0c092a16: /* original f3f6, guest PC 0x0c092a16 */
if(!s->budget--) { s->failed_pc=0x0c092a16u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c092a18;
P_0c092a18: /* original e020, guest PC 0x0c092a18 */
if(!s->budget--) { s->failed_pc=0x0c092a18u; return 0; }
r[0]=0x00000020u;
goto P_0c092a1a;
P_0c092a1a: /* original ff37, guest PC 0x0c092a1a */
if(!s->budget--) { s->failed_pc=0x0c092a1au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c092a1c;
P_0c092a1c: /* original e030, guest PC 0x0c092a1c */
if(!s->budget--) { s->failed_pc=0x0c092a1cu; return 0; }
r[0]=0x00000030u;
goto P_0c092a1e;
P_0c092a1e: /* original f3f6, guest PC 0x0c092a1e */
if(!s->budget--) { s->failed_pc=0x0c092a1eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c092a20;
P_0c092a20: /* original e024, guest PC 0x0c092a20 */
if(!s->budget--) { s->failed_pc=0x0c092a20u; return 0; }
r[0]=0x00000024u;
goto P_0c092a22;
P_0c092a22: /* original ff37, guest PC 0x0c092a22 */
if(!s->budget--) { s->failed_pc=0x0c092a22u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c092a24;
P_0c092a24: /* original e034, guest PC 0x0c092a24 */
if(!s->budget--) { s->failed_pc=0x0c092a24u; return 0; }
r[0]=0x00000034u;
goto P_0c092a26;
P_0c092a26: /* original 6ae3, guest PC 0x0c092a26 */
if(!s->budget--) { s->failed_pc=0x0c092a26u; return 0; }
r[10]=r[14];
goto P_0c092a28;
P_0c092a28: /* original f3f6, guest PC 0x0c092a28 */
if(!s->budget--) { s->failed_pc=0x0c092a28u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c092a2a;
P_0c092a2a: /* original e028, guest PC 0x0c092a2a */
if(!s->budget--) { s->failed_pc=0x0c092a2au; return 0; }
r[0]=0x00000028u;
goto P_0c092a2c;
P_0c092a2c: /* original ff37, guest PC 0x0c092a2c */
if(!s->budget--) { s->failed_pc=0x0c092a2cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c092a2e;
P_0c092a2e: /* original 1fc4, guest PC 0x0c092a2e */
if(!s->budget--) { s->failed_pc=0x0c092a2eu; return 0; }
write(ram,r[15]+16,r[12],4);
goto P_0c092a30;
P_0c092a30: /* original 63f2, guest PC 0x0c092a30 */
if(!s->budget--) { s->failed_pc=0x0c092a30u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c092a32;
P_0c092a32: /* original e034, guest PC 0x0c092a32 */
if(!s->budget--) { s->failed_pc=0x0c092a32u; return 0; }
r[0]=0x00000034u;
goto P_0c092a34;
P_0c092a34: /* original 0e35, guest PC 0x0c092a34 */
if(!s->budget--) { s->failed_pc=0x0c092a34u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c092a36;
P_0c092a36: /* original aee3, guest PC 0x0c092a36 */
if(!s->budget--) { s->failed_pc=0x0c092a36u; return 0; }
r[14]+=r[9];
goto P_0c092800;
P_0c092a38: /* original 3e9c, guest PC 0x0c092a38 */
if(!s->budget--) { s->failed_pc=0x0c092a38u; return 0; }
r[14]+=r[9];
goto P_0c092a3a;
P_0c092a3a: /* original 7f44, guest PC 0x0c092a3a */
if(!s->budget--) { s->failed_pc=0x0c092a3au; return 0; }
r[15]+=0x00000044u;
goto P_0c092a3c;
P_0c092a3c: /* original 4f26, guest PC 0x0c092a3c */
if(!s->budget--) { s->failed_pc=0x0c092a3cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c092a3e;
P_0c092a3e: /* original 69f6, guest PC 0x0c092a3e */
if(!s->budget--) { s->failed_pc=0x0c092a3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c092a40;
P_0c092a40: /* original 6af6, guest PC 0x0c092a40 */
if(!s->budget--) { s->failed_pc=0x0c092a40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c092a42;
P_0c092a42: /* original 6bf6, guest PC 0x0c092a42 */
if(!s->budget--) { s->failed_pc=0x0c092a42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c092a44;
P_0c092a44: /* original 6cf6, guest PC 0x0c092a44 */
if(!s->budget--) { s->failed_pc=0x0c092a44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c092a46;
P_0c092a46: /* original 6df6, guest PC 0x0c092a46 */
if(!s->budget--) { s->failed_pc=0x0c092a46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c092a48;
P_0c092a48: /* original 000b, guest PC 0x0c092a48 */
if(!s->budget--) { s->failed_pc=0x0c092a48u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c092a4a: /* original 6ef6, guest PC 0x0c092a4a */
if(!s->budget--) { s->failed_pc=0x0c092a4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c092a4cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c092a4cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
