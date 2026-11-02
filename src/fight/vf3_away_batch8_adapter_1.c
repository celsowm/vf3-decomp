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
int vf3_away_batch8_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042edeu: goto P_0c042ede;
case 0x0c042ee0u: goto P_0c042ee0;
case 0x0c042ee2u: goto P_0c042ee2;
case 0x0c042ee4u: goto P_0c042ee4;
case 0x0c042ee6u: goto P_0c042ee6;
case 0x0c042ee8u: goto P_0c042ee8;
case 0x0c042eeau: goto P_0c042eea;
case 0x0c042eecu: goto P_0c042eec;
case 0x0c042eeeu: goto P_0c042eee;
case 0x0c042ef0u: goto P_0c042ef0;
case 0x0c042ef2u: goto P_0c042ef2;
case 0x0c042efcu: goto P_0c042efc;
case 0x0c042efeu: goto P_0c042efe;
case 0x0c042f00u: goto P_0c042f00;
case 0x0c042f02u: goto P_0c042f02;
case 0x0c042f04u: goto P_0c042f04;
case 0x0c042f06u: goto P_0c042f06;
case 0x0c04b9e4u: goto P_0c04b9e4;
case 0x0c04b9e6u: goto P_0c04b9e6;
case 0x0c04b9e8u: goto P_0c04b9e8;
case 0x0c04b9eau: goto P_0c04b9ea;
case 0x0c04b9ecu: goto P_0c04b9ec;
case 0x0c04b9eeu: goto P_0c04b9ee;
case 0x0c04b9f0u: goto P_0c04b9f0;
case 0x0c04b9f2u: goto P_0c04b9f2;
case 0x0c04b9f4u: goto P_0c04b9f4;
case 0x0c04b9f6u: goto P_0c04b9f6;
case 0x0c04b9f8u: goto P_0c04b9f8;
case 0x0c04b9fau: goto P_0c04b9fa;
case 0x0c054530u: goto P_0c054530;
case 0x0c054532u: goto P_0c054532;
case 0x0c054534u: goto P_0c054534;
case 0x0c054536u: goto P_0c054536;
case 0x0c054538u: goto P_0c054538;
case 0x0c05453au: goto P_0c05453a;
case 0x0c05453cu: goto P_0c05453c;
case 0x0c054594u: goto P_0c054594;
case 0x0c054596u: goto P_0c054596;
case 0x0c054598u: goto P_0c054598;
case 0x0c05459au: goto P_0c05459a;
case 0x0c05459cu: goto P_0c05459c;
case 0x0c05459eu: goto P_0c05459e;
case 0x0c0545a0u: goto P_0c0545a0;
case 0x0c0545a2u: goto P_0c0545a2;
case 0x0c0545a4u: goto P_0c0545a4;
case 0x0c0545a6u: goto P_0c0545a6;
case 0x0c0545a8u: goto P_0c0545a8;
case 0x0c0545aau: goto P_0c0545aa;
case 0x0c0545acu: goto P_0c0545ac;
case 0x0c0545aeu: goto P_0c0545ae;
case 0x0c0545b0u: goto P_0c0545b0;
case 0x0c0545b2u: goto P_0c0545b2;
case 0x0c0545b4u: goto P_0c0545b4;
case 0x0c0545b6u: goto P_0c0545b6;
case 0x0c0545b8u: goto P_0c0545b8;
case 0x0c0545bau: goto P_0c0545ba;
case 0x0c0545bcu: goto P_0c0545bc;
case 0x0c0545beu: goto P_0c0545be;
case 0x0c0545c0u: goto P_0c0545c0;
case 0x0c0545c2u: goto P_0c0545c2;
case 0x0c0545c4u: goto P_0c0545c4;
case 0x0c0545c6u: goto P_0c0545c6;
case 0x0c0545c8u: goto P_0c0545c8;
case 0x0c0545cau: goto P_0c0545ca;
case 0x0c0545ccu: goto P_0c0545cc;
case 0x0c0545ceu: goto P_0c0545ce;
case 0x0c0545d0u: goto P_0c0545d0;
case 0x0c0545d2u: goto P_0c0545d2;
case 0x0c0545d4u: goto P_0c0545d4;
case 0x0c0545d6u: goto P_0c0545d6;
case 0x0c0545d8u: goto P_0c0545d8;
case 0x0c0545dau: goto P_0c0545da;
case 0x0c0545dcu: goto P_0c0545dc;
case 0x0c0545deu: goto P_0c0545de;
case 0x0c0545e0u: goto P_0c0545e0;
case 0x0c0545e2u: goto P_0c0545e2;
case 0x0c0545e4u: goto P_0c0545e4;
case 0x0c0545e6u: goto P_0c0545e6;
case 0x0c0545e8u: goto P_0c0545e8;
case 0x0c0545eau: goto P_0c0545ea;
case 0x0c0545ecu: goto P_0c0545ec;
case 0x0c0545eeu: goto P_0c0545ee;
case 0x0c0545f0u: goto P_0c0545f0;
case 0x0c0545f2u: goto P_0c0545f2;
case 0x0c0545f4u: goto P_0c0545f4;
case 0x0c0545f6u: goto P_0c0545f6;
case 0x0c0545f8u: goto P_0c0545f8;
case 0x0c0545fau: goto P_0c0545fa;
case 0x0c0545fcu: goto P_0c0545fc;
case 0x0c0545feu: goto P_0c0545fe;
case 0x0c054600u: goto P_0c054600;
case 0x0c054602u: goto P_0c054602;
case 0x0c054604u: goto P_0c054604;
case 0x0c05460cu: goto P_0c05460c;
case 0x0c05460eu: goto P_0c05460e;
case 0x0c054610u: goto P_0c054610;
case 0x0c054612u: goto P_0c054612;
case 0x0c054614u: goto P_0c054614;
case 0x0c054616u: goto P_0c054616;
case 0x0c054618u: goto P_0c054618;
case 0x0c05461au: goto P_0c05461a;
case 0x0c05461cu: goto P_0c05461c;
case 0x0c05461eu: goto P_0c05461e;
case 0x0c054620u: goto P_0c054620;
case 0x0c054622u: goto P_0c054622;
case 0x0c054624u: goto P_0c054624;
case 0x0c054626u: goto P_0c054626;
case 0x0c054628u: goto P_0c054628;
case 0x0c05462au: goto P_0c05462a;
case 0x0c05462cu: goto P_0c05462c;
case 0x0c05462eu: goto P_0c05462e;
case 0x0c054630u: goto P_0c054630;
case 0x0c054632u: goto P_0c054632;
case 0x0c054634u: goto P_0c054634;
case 0x0c054636u: goto P_0c054636;
case 0x0c054638u: goto P_0c054638;
case 0x0c05463au: goto P_0c05463a;
case 0x0c05463cu: goto P_0c05463c;
case 0x0c05463eu: goto P_0c05463e;
case 0x0c059896u: goto P_0c059896;
case 0x0c059898u: goto P_0c059898;
case 0x0c05989au: goto P_0c05989a;
case 0x0c05989cu: goto P_0c05989c;
case 0x0c05989eu: goto P_0c05989e;
case 0x0c0598a0u: goto P_0c0598a0;
case 0x0c0598a2u: goto P_0c0598a2;
case 0x0c0598a4u: goto P_0c0598a4;
case 0x0c0598a6u: goto P_0c0598a6;
case 0x0c0598a8u: goto P_0c0598a8;
case 0x0c0598aau: goto P_0c0598aa;
case 0x0c0598acu: goto P_0c0598ac;
case 0x0c0598aeu: goto P_0c0598ae;
case 0x0c0598b0u: goto P_0c0598b0;
case 0x0c0598b2u: goto P_0c0598b2;
case 0x0c0598b4u: goto P_0c0598b4;
case 0x0c0598b6u: goto P_0c0598b6;
case 0x0c0598b8u: goto P_0c0598b8;
case 0x0c0598bau: goto P_0c0598ba;
case 0x0c0598bcu: goto P_0c0598bc;
case 0x0c0598beu: goto P_0c0598be;
case 0x0c0598c0u: goto P_0c0598c0;
case 0x0c0598c2u: goto P_0c0598c2;
case 0x0c0598c4u: goto P_0c0598c4;
case 0x0c0598c6u: goto P_0c0598c6;
case 0x0c0598c8u: goto P_0c0598c8;
case 0x0c0598cau: goto P_0c0598ca;
case 0x0c0598ccu: goto P_0c0598cc;
case 0x0c0598ceu: goto P_0c0598ce;
case 0x0c0598d0u: goto P_0c0598d0;
case 0x0c0598d2u: goto P_0c0598d2;
case 0x0c0598d4u: goto P_0c0598d4;
case 0x0c0598d6u: goto P_0c0598d6;
case 0x0c0598d8u: goto P_0c0598d8;
case 0x0c0598dau: goto P_0c0598da;
case 0x0c0598dcu: goto P_0c0598dc;
case 0x0c0598deu: goto P_0c0598de;
case 0x0c0598e0u: goto P_0c0598e0;
case 0x0c0598e2u: goto P_0c0598e2;
case 0x0c0598e4u: goto P_0c0598e4;
case 0x0c0598e6u: goto P_0c0598e6;
case 0x0c0598e8u: goto P_0c0598e8;
case 0x0c0598eau: goto P_0c0598ea;
case 0x0c0598ecu: goto P_0c0598ec;
case 0x0c0598eeu: goto P_0c0598ee;
case 0x0c059920u: goto P_0c059920;
case 0x0c059922u: goto P_0c059922;
case 0x0c059924u: goto P_0c059924;
case 0x0c059926u: goto P_0c059926;
case 0x0c059928u: goto P_0c059928;
case 0x0c05992au: goto P_0c05992a;
case 0x0c05992cu: goto P_0c05992c;
case 0x0c05992eu: goto P_0c05992e;
case 0x0c059930u: goto P_0c059930;
case 0x0c059932u: goto P_0c059932;
case 0x0c059934u: goto P_0c059934;
case 0x0c059936u: goto P_0c059936;
case 0x0c059938u: goto P_0c059938;
case 0x0c05993au: goto P_0c05993a;
case 0x0c05993cu: goto P_0c05993c;
case 0x0c05993eu: goto P_0c05993e;
case 0x0c059940u: goto P_0c059940;
case 0x0c059942u: goto P_0c059942;
case 0x0c059944u: goto P_0c059944;
case 0x0c059946u: goto P_0c059946;
case 0x0c059948u: goto P_0c059948;
case 0x0c05994au: goto P_0c05994a;
case 0x0c05994cu: goto P_0c05994c;
case 0x0c05994eu: goto P_0c05994e;
case 0x0c059950u: goto P_0c059950;
case 0x0c059952u: goto P_0c059952;
case 0x0c059954u: goto P_0c059954;
case 0x0c059956u: goto P_0c059956;
case 0x0c059958u: goto P_0c059958;
case 0x0c05995au: goto P_0c05995a;
case 0x0c05995cu: goto P_0c05995c;
case 0x0c05995eu: goto P_0c05995e;
case 0x0c059960u: goto P_0c059960;
case 0x0c059962u: goto P_0c059962;
case 0x0c059964u: goto P_0c059964;
case 0x0c059966u: goto P_0c059966;
case 0x0c059968u: goto P_0c059968;
case 0x0c05996au: goto P_0c05996a;
case 0x0c05996cu: goto P_0c05996c;
case 0x0c05996eu: goto P_0c05996e;
case 0x0c059970u: goto P_0c059970;
case 0x0c059972u: goto P_0c059972;
case 0x0c059974u: goto P_0c059974;
case 0x0c059976u: goto P_0c059976;
case 0x0c059978u: goto P_0c059978;
case 0x0c05997au: goto P_0c05997a;
case 0x0c05997cu: goto P_0c05997c;
case 0x0c05997eu: goto P_0c05997e;
case 0x0c059980u: goto P_0c059980;
case 0x0c059982u: goto P_0c059982;
case 0x0c059984u: goto P_0c059984;
case 0x0c059986u: goto P_0c059986;
case 0x0c059988u: goto P_0c059988;
case 0x0c05998au: goto P_0c05998a;
case 0x0c05998cu: goto P_0c05998c;
case 0x0c05998eu: goto P_0c05998e;
case 0x0c059990u: goto P_0c059990;
case 0x0c059992u: goto P_0c059992;
case 0x0c059994u: goto P_0c059994;
case 0x0c059996u: goto P_0c059996;
case 0x0c059998u: goto P_0c059998;
case 0x0c05999au: goto P_0c05999a;
case 0x0c05999cu: goto P_0c05999c;
case 0x0c05999eu: goto P_0c05999e;
case 0x0c0599a0u: goto P_0c0599a0;
case 0x0c0599a2u: goto P_0c0599a2;
case 0x0c0599a4u: goto P_0c0599a4;
case 0x0c0599a6u: goto P_0c0599a6;
case 0x0c0599a8u: goto P_0c0599a8;
case 0x0c0599aau: goto P_0c0599aa;
case 0x0c0599acu: goto P_0c0599ac;
case 0x0c0599aeu: goto P_0c0599ae;
case 0x0c0599b0u: goto P_0c0599b0;
case 0x0c0599b2u: goto P_0c0599b2;
case 0x0c0599b4u: goto P_0c0599b4;
case 0x0c0599b6u: goto P_0c0599b6;
case 0x0c0599b8u: goto P_0c0599b8;
case 0x0c0599bau: goto P_0c0599ba;
case 0x0c0599bcu: goto P_0c0599bc;
case 0x0c0599beu: goto P_0c0599be;
case 0x0c0599c0u: goto P_0c0599c0;
case 0x0c0599c2u: goto P_0c0599c2;
case 0x0c0599c4u: goto P_0c0599c4;
case 0x0c0599c6u: goto P_0c0599c6;
case 0x0c0599c8u: goto P_0c0599c8;
case 0x0c0599cau: goto P_0c0599ca;
case 0x0c0599ccu: goto P_0c0599cc;
case 0x0c0599ceu: goto P_0c0599ce;
case 0x0c0599d0u: goto P_0c0599d0;
case 0x0c0599d2u: goto P_0c0599d2;
case 0x0c0599d4u: goto P_0c0599d4;
case 0x0c0599d6u: goto P_0c0599d6;
case 0x0c0599d8u: goto P_0c0599d8;
case 0x0c0599dau: goto P_0c0599da;
case 0x0c0599dcu: goto P_0c0599dc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c042ede: /* original 303c, guest PC 0x0c042ede */
if(!s->budget--) { s->failed_pc=0x0c042edeu; return 0; }
r[0]+=r[3];
goto P_0c042ee0;
P_0c042ee0: /* original 64f6, guest PC 0x0c042ee0 */
if(!s->budget--) { s->failed_pc=0x0c042ee0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c042ee2;
P_0c042ee2: /* original 000b, guest PC 0x0c042ee2 */
if(!s->budget--) { s->failed_pc=0x0c042ee2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
s->pc=target; return ram->oob==0;
P_0c042ee4: /* original 63f6, guest PC 0x0c042ee4 */
if(!s->budget--) { s->failed_pc=0x0c042ee4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042ee6;
P_0c042ee6: /* original 2f26, guest PC 0x0c042ee6 */
if(!s->budget--) { s->failed_pc=0x0c042ee6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042ee8;
P_0c042ee8: /* original d102, guest PC 0x0c042ee8 */
if(!s->budget--) { s->failed_pc=0x0c042ee8u; return 0; }
r[1]=read(ram,0x0c042ef4u,4);
goto P_0c042eea;
P_0c042eea: /* original d203, guest PC 0x0c042eea */
if(!s->budget--) { s->failed_pc=0x0c042eeau; return 0; }
r[2]=read(ram,0x0c042ef8u,4);
goto P_0c042eec;
P_0c042eec: /* original e000, guest PC 0x0c042eec */
if(!s->budget--) { s->failed_pc=0x0c042eecu; return 0; }
r[0]=0x00000000u;
goto P_0c042eee;
P_0c042eee: /* original 2122, guest PC 0x0c042eee */
if(!s->budget--) { s->failed_pc=0x0c042eeeu; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042ef0;
P_0c042ef0: /* original 000b, guest PC 0x0c042ef0 */
if(!s->budget--) { s->failed_pc=0x0c042ef0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042ef2: /* original 62f6, guest PC 0x0c042ef2 */
if(!s->budget--) { s->failed_pc=0x0c042ef2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042ef4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042ef4u; return 0; } return 1;
P_0c042efc: /* original 2f36, guest PC 0x0c042efc */
if(!s->budget--) { s->failed_pc=0x0c042efcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042efe;
P_0c042efe: /* original d305, guest PC 0x0c042efe */
if(!s->budget--) { s->failed_pc=0x0c042efeu; return 0; }
r[3]=read(ram,0x0c042f14u,4);
goto P_0c042f00;
P_0c042f00: /* original 033e, guest PC 0x0c042f00 */
if(!s->budget--) { s->failed_pc=0x0c042f00u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c042f02;
P_0c042f02: /* original 70fc, guest PC 0x0c042f02 */
if(!s->budget--) { s->failed_pc=0x0c042f02u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c042f04;
P_0c042f04: /* original 432b, guest PC 0x0c042f04 */
if(!s->budget--) { s->failed_pc=0x0c042f04u; return 0; }
target=r[3];
r[0]=read(ram,r[2]+r[0],4);
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
P_0c042f06: /* original 002e, guest PC 0x0c042f06 */
if(!s->budget--) { s->failed_pc=0x0c042f06u; return 0; }
r[0]=read(ram,r[2]+r[0],4);
if(!vf3_matrix_family(0x0c042f08u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042f08u; return 0; } return 1;
P_0c04b9e4: /* original e700, guest PC 0x0c04b9e4 */
if(!s->budget--) { s->failed_pc=0x0c04b9e4u; return 0; }
r[7]=0x00000000u;
goto P_0c04b9e6;
P_0c04b9e6: /* original 6373, guest PC 0x0c04b9e6 */
if(!s->budget--) { s->failed_pc=0x0c04b9e6u; return 0; }
r[3]=r[7];
goto P_0c04b9e8;
P_0c04b9e8: /* original 3362, guest PC 0x0c04b9e8 */
if(!s->budget--) { s->failed_pc=0x0c04b9e8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[6])!=0);
goto P_0c04b9ea;
P_0c04b9ea: /* original 8d05, guest PC 0x0c04b9ea */
if(!s->budget--) { s->failed_pc=0x0c04b9eau; return 0; }
cond=r[17]&1u;
r[0]=r[4];
if(cond) { goto P_0c04b9f8; }
goto P_0c04b9ee;
P_0c04b9ec: /* original 6043, guest PC 0x0c04b9ec */
if(!s->budget--) { s->failed_pc=0x0c04b9ecu; return 0; }
r[0]=r[4];
goto P_0c04b9ee;
P_0c04b9ee: /* original 7701, guest PC 0x0c04b9ee */
if(!s->budget--) { s->failed_pc=0x0c04b9eeu; return 0; }
r[7]+=0x00000001u;
goto P_0c04b9f0;
P_0c04b9f0: /* original 2050, guest PC 0x0c04b9f0 */
if(!s->budget--) { s->failed_pc=0x0c04b9f0u; return 0; }
write(ram,r[0],r[5],1);
goto P_0c04b9f2;
P_0c04b9f2: /* original 3762, guest PC 0x0c04b9f2 */
if(!s->budget--) { s->failed_pc=0x0c04b9f2u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[6])!=0);
goto P_0c04b9f4;
P_0c04b9f4: /* original 8ffb, guest PC 0x0c04b9f4 */
if(!s->budget--) { s->failed_pc=0x0c04b9f4u; return 0; }
cond=r[17]&1u;
r[0]+=0x00000001u;
if(!cond) { goto P_0c04b9ee; }
goto P_0c04b9f8;
P_0c04b9f6: /* original 7001, guest PC 0x0c04b9f6 */
if(!s->budget--) { s->failed_pc=0x0c04b9f6u; return 0; }
r[0]+=0x00000001u;
goto P_0c04b9f8;
P_0c04b9f8: /* original 000b, guest PC 0x0c04b9f8 */
if(!s->budget--) { s->failed_pc=0x0c04b9f8u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c04b9fa: /* original 6043, guest PC 0x0c04b9fa */
if(!s->budget--) { s->failed_pc=0x0c04b9fau; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c04b9fcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04b9fcu; return 0; } return 1;
P_0c054530: /* original 4f22, guest PC 0x0c054530 */
if(!s->budget--) { s->failed_pc=0x0c054530u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c054532;
P_0c054532: /* original d303, guest PC 0x0c054532 */
if(!s->budget--) { s->failed_pc=0x0c054532u; return 0; }
r[3]=read(ram,0x0c054540u,4);
goto P_0c054534;
P_0c054534: /* original 430b, guest PC 0x0c054534 */
if(!s->budget--) { s->failed_pc=0x0c054534u; return 0; }
target=r[3];
r[16]=code_base|0x0c054538u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054538u) { target=s->pc; goto dispatch; }
goto P_0c054538;
P_0c054536: /* original 0009, guest PC 0x0c054536 */
if(!s->budget--) { s->failed_pc=0x0c054536u; return 0; }
goto P_0c054538;
P_0c054538: /* original 4f26, guest PC 0x0c054538 */
if(!s->budget--) { s->failed_pc=0x0c054538u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05453a;
P_0c05453a: /* original 000b, guest PC 0x0c05453a */
if(!s->budget--) { s->failed_pc=0x0c05453au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05453c: /* original 0009, guest PC 0x0c05453c */
if(!s->budget--) { s->failed_pc=0x0c05453cu; return 0; }
if(!vf3_matrix_family(0x0c05453eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05453eu; return 0; } return 1;
P_0c054594: /* original 6043, guest PC 0x0c054594 */
if(!s->budget--) { s->failed_pc=0x0c054594u; return 0; }
r[0]=r[4];
goto P_0c054596;
P_0c054596: /* original 205b, guest PC 0x0c054596 */
if(!s->budget--) { s->failed_pc=0x0c054596u; return 0; }
r[0]|=r[5];
goto P_0c054598;
P_0c054598: /* original c803, guest PC 0x0c054598 */
if(!s->budget--) { s->failed_pc=0x0c054598u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&3u)==0)!=0);
goto P_0c05459a;
P_0c05459a: /* original 8f37, guest PC 0x0c05459a */
if(!s->budget--) { s->failed_pc=0x0c05459au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05460c; }
goto P_0c05459e;
P_0c05459c: /* original 0009, guest PC 0x0c05459c */
if(!s->budget--) { s->failed_pc=0x0c05459cu; return 0; }
goto P_0c05459e;
P_0c05459e: /* original 6356, guest PC 0x0c05459e */
if(!s->budget--) { s->failed_pc=0x0c05459eu; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[3]=tmp;
goto P_0c0545a0;
P_0c0545a0: /* original e200, guest PC 0x0c0545a0 */
if(!s->budget--) { s->failed_pc=0x0c0545a0u; return 0; }
r[2]=0x00000000u;
goto P_0c0545a2;
P_0c0545a2: /* original 6046, guest PC 0x0c0545a2 */
if(!s->budget--) { s->failed_pc=0x0c0545a2u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0545a4;
P_0c0545a4: /* original 232c, guest PC 0x0c0545a4 */
if(!s->budget--) { s->failed_pc=0x0c0545a4u; return 0; }
r[17]=(r[17]&~1u)|((((r[3]^r[2])&0xffu)==0 || ((r[3]^r[2])&0xff00u)==0 || ((r[3]^r[2])&0xff0000u)==0 || ((r[3]^r[2])&0xff000000u)==0)!=0);
goto P_0c0545a6;
P_0c0545a6: /* original 8d16, guest PC 0x0c0545a6 */
if(!s->budget--) { s->failed_pc=0x0c0545a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0545d6; }
goto P_0c0545aa;
P_0c0545a8: /* original 0009, guest PC 0x0c0545a8 */
if(!s->budget--) { s->failed_pc=0x0c0545a8u; return 0; }
goto P_0c0545aa;
P_0c0545aa: /* original 3300, guest PC 0x0c0545aa */
if(!s->budget--) { s->failed_pc=0x0c0545aau; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[0])!=0);
goto P_0c0545ac;
P_0c0545ac: /* original 6156, guest PC 0x0c0545ac */
if(!s->budget--) { s->failed_pc=0x0c0545acu; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[1]=tmp;
goto P_0c0545ae;
P_0c0545ae: /* original 8b11, guest PC 0x0c0545ae */
if(!s->budget--) { s->failed_pc=0x0c0545aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0545d4; }
goto P_0c0545b0;
P_0c0545b0: /* original 6046, guest PC 0x0c0545b0 */
if(!s->budget--) { s->failed_pc=0x0c0545b0u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0545b2;
P_0c0545b2: /* original 212c, guest PC 0x0c0545b2 */
if(!s->budget--) { s->failed_pc=0x0c0545b2u; return 0; }
r[17]=(r[17]&~1u)|((((r[1]^r[2])&0xffu)==0 || ((r[1]^r[2])&0xff00u)==0 || ((r[1]^r[2])&0xff0000u)==0 || ((r[1]^r[2])&0xff000000u)==0)!=0);
goto P_0c0545b4;
P_0c0545b4: /* original 890f, guest PC 0x0c0545b4 */
if(!s->budget--) { s->failed_pc=0x0c0545b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0545d6; }
goto P_0c0545b6;
P_0c0545b6: /* original 3100, guest PC 0x0c0545b6 */
if(!s->budget--) { s->failed_pc=0x0c0545b6u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[0])!=0);
goto P_0c0545b8;
P_0c0545b8: /* original 6356, guest PC 0x0c0545b8 */
if(!s->budget--) { s->failed_pc=0x0c0545b8u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[3]=tmp;
goto P_0c0545ba;
P_0c0545ba: /* original 8b0b, guest PC 0x0c0545ba */
if(!s->budget--) { s->failed_pc=0x0c0545bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0545d4; }
goto P_0c0545bc;
P_0c0545bc: /* original 6046, guest PC 0x0c0545bc */
if(!s->budget--) { s->failed_pc=0x0c0545bcu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0545be;
P_0c0545be: /* original 232c, guest PC 0x0c0545be */
if(!s->budget--) { s->failed_pc=0x0c0545beu; return 0; }
r[17]=(r[17]&~1u)|((((r[3]^r[2])&0xffu)==0 || ((r[3]^r[2])&0xff00u)==0 || ((r[3]^r[2])&0xff0000u)==0 || ((r[3]^r[2])&0xff000000u)==0)!=0);
goto P_0c0545c0;
P_0c0545c0: /* original 8909, guest PC 0x0c0545c0 */
if(!s->budget--) { s->failed_pc=0x0c0545c0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0545d6; }
goto P_0c0545c2;
P_0c0545c2: /* original 3300, guest PC 0x0c0545c2 */
if(!s->budget--) { s->failed_pc=0x0c0545c2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[0])!=0);
goto P_0c0545c4;
P_0c0545c4: /* original 6156, guest PC 0x0c0545c4 */
if(!s->budget--) { s->failed_pc=0x0c0545c4u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[1]=tmp;
goto P_0c0545c6;
P_0c0545c6: /* original 8b05, guest PC 0x0c0545c6 */
if(!s->budget--) { s->failed_pc=0x0c0545c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0545d4; }
goto P_0c0545c8;
P_0c0545c8: /* original 6046, guest PC 0x0c0545c8 */
if(!s->budget--) { s->failed_pc=0x0c0545c8u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[0]=tmp;
goto P_0c0545ca;
P_0c0545ca: /* original 212c, guest PC 0x0c0545ca */
if(!s->budget--) { s->failed_pc=0x0c0545cau; return 0; }
r[17]=(r[17]&~1u)|((((r[1]^r[2])&0xffu)==0 || ((r[1]^r[2])&0xff00u)==0 || ((r[1]^r[2])&0xff0000u)==0 || ((r[1]^r[2])&0xff000000u)==0)!=0);
goto P_0c0545cc;
P_0c0545cc: /* original 8903, guest PC 0x0c0545cc */
if(!s->budget--) { s->failed_pc=0x0c0545ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0545d6; }
goto P_0c0545ce;
P_0c0545ce: /* original 3100, guest PC 0x0c0545ce */
if(!s->budget--) { s->failed_pc=0x0c0545ceu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[0])!=0);
goto P_0c0545d0;
P_0c0545d0: /* original 6356, guest PC 0x0c0545d0 */
if(!s->budget--) { s->failed_pc=0x0c0545d0u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[3]=tmp;
goto P_0c0545d2;
P_0c0545d2: /* original 89e6, guest PC 0x0c0545d2 */
if(!s->budget--) { s->failed_pc=0x0c0545d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0545a2; }
goto P_0c0545d4;
P_0c0545d4: /* original 75fc, guest PC 0x0c0545d4 */
if(!s->budget--) { s->failed_pc=0x0c0545d4u; return 0; }
r[5]+=0xfffffffcu;
goto P_0c0545d6;
P_0c0545d6: /* original 75fc, guest PC 0x0c0545d6 */
if(!s->budget--) { s->failed_pc=0x0c0545d6u; return 0; }
r[5]+=0xfffffffcu;
goto P_0c0545d8;
P_0c0545d8: /* original 6154, guest PC 0x0c0545d8 */
if(!s->budget--) { s->failed_pc=0x0c0545d8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[1]=tmp;
goto P_0c0545da;
P_0c0545da: /* original 74fc, guest PC 0x0c0545da */
if(!s->budget--) { s->failed_pc=0x0c0545dau; return 0; }
r[4]+=0xfffffffcu;
goto P_0c0545dc;
P_0c0545dc: /* original 6044, guest PC 0x0c0545dc */
if(!s->budget--) { s->failed_pc=0x0c0545dcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[0]=tmp;
goto P_0c0545de;
P_0c0545de: /* original 3120, guest PC 0x0c0545de */
if(!s->budget--) { s->failed_pc=0x0c0545deu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c0545e0;
P_0c0545e0: /* original 890f, guest PC 0x0c0545e0 */
if(!s->budget--) { s->failed_pc=0x0c0545e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054602; }
goto P_0c0545e2;
P_0c0545e2: /* original 3100, guest PC 0x0c0545e2 */
if(!s->budget--) { s->failed_pc=0x0c0545e2u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[0])!=0);
goto P_0c0545e4;
P_0c0545e4: /* original 8b0d, guest PC 0x0c0545e4 */
if(!s->budget--) { s->failed_pc=0x0c0545e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054602; }
goto P_0c0545e6;
P_0c0545e6: /* original 6154, guest PC 0x0c0545e6 */
if(!s->budget--) { s->failed_pc=0x0c0545e6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[1]=tmp;
goto P_0c0545e8;
P_0c0545e8: /* original 6044, guest PC 0x0c0545e8 */
if(!s->budget--) { s->failed_pc=0x0c0545e8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[0]=tmp;
goto P_0c0545ea;
P_0c0545ea: /* original 3120, guest PC 0x0c0545ea */
if(!s->budget--) { s->failed_pc=0x0c0545eau; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c0545ec;
P_0c0545ec: /* original 8909, guest PC 0x0c0545ec */
if(!s->budget--) { s->failed_pc=0x0c0545ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054602; }
goto P_0c0545ee;
P_0c0545ee: /* original 3100, guest PC 0x0c0545ee */
if(!s->budget--) { s->failed_pc=0x0c0545eeu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[0])!=0);
goto P_0c0545f0;
P_0c0545f0: /* original 8b07, guest PC 0x0c0545f0 */
if(!s->budget--) { s->failed_pc=0x0c0545f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054602; }
goto P_0c0545f2;
P_0c0545f2: /* original 6154, guest PC 0x0c0545f2 */
if(!s->budget--) { s->failed_pc=0x0c0545f2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[1]=tmp;
goto P_0c0545f4;
P_0c0545f4: /* original 6044, guest PC 0x0c0545f4 */
if(!s->budget--) { s->failed_pc=0x0c0545f4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[0]=tmp;
goto P_0c0545f6;
P_0c0545f6: /* original 3120, guest PC 0x0c0545f6 */
if(!s->budget--) { s->failed_pc=0x0c0545f6u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c0545f8;
P_0c0545f8: /* original 8903, guest PC 0x0c0545f8 */
if(!s->budget--) { s->failed_pc=0x0c0545f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054602; }
goto P_0c0545fa;
P_0c0545fa: /* original 3100, guest PC 0x0c0545fa */
if(!s->budget--) { s->failed_pc=0x0c0545fau; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[0])!=0);
goto P_0c0545fc;
P_0c0545fc: /* original 8b01, guest PC 0x0c0545fc */
if(!s->budget--) { s->failed_pc=0x0c0545fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054602; }
goto P_0c0545fe;
P_0c0545fe: /* original 6044, guest PC 0x0c0545fe */
if(!s->budget--) { s->failed_pc=0x0c0545feu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[0]=tmp;
goto P_0c054600;
P_0c054600: /* original 6154, guest PC 0x0c054600 */
if(!s->budget--) { s->failed_pc=0x0c054600u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[1]=tmp;
goto P_0c054602;
P_0c054602: /* original 000b, guest PC 0x0c054602 */
if(!s->budget--) { s->failed_pc=0x0c054602u; return 0; }
target=r[16];
r[0]-=r[1];
s->pc=target; return ram->oob==0;
P_0c054604: /* original 3018, guest PC 0x0c054604 */
if(!s->budget--) { s->failed_pc=0x0c054604u; return 0; }
r[0]-=r[1];
if(!vf3_matrix_family(0x0c054606u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c054606u; return 0; } return 1;
P_0c05460c: /* original 6044, guest PC 0x0c05460c */
if(!s->budget--) { s->failed_pc=0x0c05460cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[0]=tmp;
goto P_0c05460e;
P_0c05460e: /* original 8800, guest PC 0x0c05460e */
if(!s->budget--) { s->failed_pc=0x0c05460eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c054610;
P_0c054610: /* original 6354, guest PC 0x0c054610 */
if(!s->budget--) { s->failed_pc=0x0c054610u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c054612;
P_0c054612: /* original 8913, guest PC 0x0c054612 */
if(!s->budget--) { s->failed_pc=0x0c054612u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05463c; }
goto P_0c054614;
P_0c054614: /* original 3300, guest PC 0x0c054614 */
if(!s->budget--) { s->failed_pc=0x0c054614u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[0])!=0);
goto P_0c054616;
P_0c054616: /* original 8b11, guest PC 0x0c054616 */
if(!s->budget--) { s->failed_pc=0x0c054616u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05463c; }
goto P_0c054618;
P_0c054618: /* original 6044, guest PC 0x0c054618 */
if(!s->budget--) { s->failed_pc=0x0c054618u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[0]=tmp;
goto P_0c05461a;
P_0c05461a: /* original 6354, guest PC 0x0c05461a */
if(!s->budget--) { s->failed_pc=0x0c05461au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c05461c;
P_0c05461c: /* original 8800, guest PC 0x0c05461c */
if(!s->budget--) { s->failed_pc=0x0c05461cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c05461e;
P_0c05461e: /* original 890d, guest PC 0x0c05461e */
if(!s->budget--) { s->failed_pc=0x0c05461eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05463c; }
goto P_0c054620;
P_0c054620: /* original 3300, guest PC 0x0c054620 */
if(!s->budget--) { s->failed_pc=0x0c054620u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[0])!=0);
goto P_0c054622;
P_0c054622: /* original 8b0b, guest PC 0x0c054622 */
if(!s->budget--) { s->failed_pc=0x0c054622u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05463c; }
goto P_0c054624;
P_0c054624: /* original 6044, guest PC 0x0c054624 */
if(!s->budget--) { s->failed_pc=0x0c054624u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[0]=tmp;
goto P_0c054626;
P_0c054626: /* original 6354, guest PC 0x0c054626 */
if(!s->budget--) { s->failed_pc=0x0c054626u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c054628;
P_0c054628: /* original 8800, guest PC 0x0c054628 */
if(!s->budget--) { s->failed_pc=0x0c054628u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c05462a;
P_0c05462a: /* original 8907, guest PC 0x0c05462a */
if(!s->budget--) { s->failed_pc=0x0c05462au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05463c; }
goto P_0c05462c;
P_0c05462c: /* original 3300, guest PC 0x0c05462c */
if(!s->budget--) { s->failed_pc=0x0c05462cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[0])!=0);
goto P_0c05462e;
P_0c05462e: /* original 8b05, guest PC 0x0c05462e */
if(!s->budget--) { s->failed_pc=0x0c05462eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05463c; }
goto P_0c054630;
P_0c054630: /* original 6044, guest PC 0x0c054630 */
if(!s->budget--) { s->failed_pc=0x0c054630u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[0]=tmp;
goto P_0c054632;
P_0c054632: /* original 6354, guest PC 0x0c054632 */
if(!s->budget--) { s->failed_pc=0x0c054632u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c054634;
P_0c054634: /* original 8800, guest PC 0x0c054634 */
if(!s->budget--) { s->failed_pc=0x0c054634u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c054636;
P_0c054636: /* original 8901, guest PC 0x0c054636 */
if(!s->budget--) { s->failed_pc=0x0c054636u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05463c; }
goto P_0c054638;
P_0c054638: /* original 3300, guest PC 0x0c054638 */
if(!s->budget--) { s->failed_pc=0x0c054638u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[0])!=0);
goto P_0c05463a;
P_0c05463a: /* original 89e7, guest PC 0x0c05463a */
if(!s->budget--) { s->failed_pc=0x0c05463au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05460c; }
goto P_0c05463c;
P_0c05463c: /* original 000b, guest PC 0x0c05463c */
if(!s->budget--) { s->failed_pc=0x0c05463cu; return 0; }
target=r[16];
r[0]-=r[3];
s->pc=target; return ram->oob==0;
P_0c05463e: /* original 3038, guest PC 0x0c05463e */
if(!s->budget--) { s->failed_pc=0x0c05463eu; return 0; }
r[0]-=r[3];
if(!vf3_matrix_family(0x0c054640u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c054640u; return 0; } return 1;
P_0c059896: /* original 2fe6, guest PC 0x0c059896 */
if(!s->budget--) { s->failed_pc=0x0c059896u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059898;
P_0c059898: /* original 2fd6, guest PC 0x0c059898 */
if(!s->budget--) { s->failed_pc=0x0c059898u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05989a;
P_0c05989a: /* original 6e43, guest PC 0x0c05989a */
if(!s->budget--) { s->failed_pc=0x0c05989au; return 0; }
r[14]=r[4];
goto P_0c05989c;
P_0c05989c: /* original 2fc6, guest PC 0x0c05989c */
if(!s->budget--) { s->failed_pc=0x0c05989cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05989e;
P_0c05989e: /* original 2ee8, guest PC 0x0c05989e */
if(!s->budget--) { s->failed_pc=0x0c05989eu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0598a0;
P_0c0598a0: /* original 2fb6, guest PC 0x0c0598a0 */
if(!s->budget--) { s->failed_pc=0x0c0598a0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0598a2;
P_0c0598a2: /* original 6c53, guest PC 0x0c0598a2 */
if(!s->budget--) { s->failed_pc=0x0c0598a2u; return 0; }
r[12]=r[5];
goto P_0c0598a4;
P_0c0598a4: /* original 2fa6, guest PC 0x0c0598a4 */
if(!s->budget--) { s->failed_pc=0x0c0598a4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0598a6;
P_0c0598a6: /* original 6b63, guest PC 0x0c0598a6 */
if(!s->budget--) { s->failed_pc=0x0c0598a6u; return 0; }
r[11]=r[6];
goto P_0c0598a8;
P_0c0598a8: /* original 4f22, guest PC 0x0c0598a8 */
if(!s->budget--) { s->failed_pc=0x0c0598a8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0598aa;
P_0c0598aa: /* original 7ffc, guest PC 0x0c0598aa */
if(!s->budget--) { s->failed_pc=0x0c0598aau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0598ac;
P_0c0598ac: /* original 2f72, guest PC 0x0c0598ac */
if(!s->budget--) { s->failed_pc=0x0c0598acu; return 0; }
write(ram,r[15],r[7],4);
goto P_0c0598ae;
P_0c0598ae: /* original 8d02, guest PC 0x0c0598ae */
if(!s->budget--) { s->failed_pc=0x0c0598aeu; return 0; }
cond=r[17]&1u;
r[10]=0x00000000u;
if(cond) { goto P_0c0598b6; }
goto P_0c0598b2;
P_0c0598b0: /* original ea00, guest PC 0x0c0598b0 */
if(!s->budget--) { s->failed_pc=0x0c0598b0u; return 0; }
r[10]=0x00000000u;
goto P_0c0598b2;
P_0c0598b2: /* original 2cc8, guest PC 0x0c0598b2 */
if(!s->budget--) { s->failed_pc=0x0c0598b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0598b4;
P_0c0598b4: /* original 8b01, guest PC 0x0c0598b4 */
if(!s->budget--) { s->failed_pc=0x0c0598b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0598ba; }
goto P_0c0598b6;
P_0c0598b6: /* original a08a, guest PC 0x0c0598b6 */
if(!s->budget--) { s->failed_pc=0x0c0598b6u; return 0; }
r[0]=0x0000000eu;
goto P_0c0599ce;
P_0c0598b8: /* original e00e, guest PC 0x0c0598b8 */
if(!s->budget--) { s->failed_pc=0x0c0598b8u; return 0; }
r[0]=0x0000000eu;
goto P_0c0598ba;
P_0c0598ba: /* original e040, guest PC 0x0c0598ba */
if(!s->budget--) { s->failed_pc=0x0c0598bau; return 0; }
r[0]=0x00000040u;
goto P_0c0598bc;
P_0c0598bc: /* original d216, guest PC 0x0c0598bc */
if(!s->budget--) { s->failed_pc=0x0c0598bcu; return 0; }
r[2]=read(ram,0x0c059918u,4);
goto P_0c0598be;
P_0c0598be: /* original dd14, guest PC 0x0c0598be */
if(!s->budget--) { s->failed_pc=0x0c0598beu; return 0; }
r[13]=read(ram,0x0c059910u,4);
goto P_0c0598c0;
P_0c0598c0: /* original 1def, guest PC 0x0c0598c0 */
if(!s->budget--) { s->failed_pc=0x0c0598c0u; return 0; }
write(ram,r[13]+60,r[14],4);
goto P_0c0598c2;
P_0c0598c2: /* original 0dc6, guest PC 0x0c0598c2 */
if(!s->budget--) { s->failed_pc=0x0c0598c2u; return 0; }
write(ram,r[13]+r[0],r[12],4);
goto P_0c0598c4;
P_0c0598c4: /* original 63f2, guest PC 0x0c0598c4 */
if(!s->budget--) { s->failed_pc=0x0c0598c4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0598c6;
P_0c0598c6: /* original e044, guest PC 0x0c0598c6 */
if(!s->budget--) { s->failed_pc=0x0c0598c6u; return 0; }
r[0]=0x00000044u;
goto P_0c0598c8;
P_0c0598c8: /* original 0d36, guest PC 0x0c0598c8 */
if(!s->budget--) { s->failed_pc=0x0c0598c8u; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c0598ca;
P_0c0598ca: /* original 1db6, guest PC 0x0c0598ca */
if(!s->budget--) { s->failed_pc=0x0c0598cau; return 0; }
write(ram,r[13]+24,r[11],4);
goto P_0c0598cc;
P_0c0598cc: /* original d311, guest PC 0x0c0598cc */
if(!s->budget--) { s->failed_pc=0x0c0598ccu; return 0; }
r[3]=read(ram,0x0c059914u,4);
goto P_0c0598ce;
P_0c0598ce: /* original 420b, guest PC 0x0c0598ce */
if(!s->budget--) { s->failed_pc=0x0c0598ceu; return 0; }
target=r[2];
r[16]=code_base|0x0c0598d2u;
write(ram,r[3],r[11],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0598d2u) { target=s->pc; goto dispatch; }
goto P_0c0598d2;
P_0c0598d0: /* original 23b2, guest PC 0x0c0598d0 */
if(!s->budget--) { s->failed_pc=0x0c0598d0u; return 0; }
write(ram,r[3],r[11],4);
goto P_0c0598d2;
P_0c0598d2: /* original d112, guest PC 0x0c0598d2 */
if(!s->budget--) { s->failed_pc=0x0c0598d2u; return 0; }
r[1]=read(ram,0x0c05991cu,4);
goto P_0c0598d4;
P_0c0598d4: /* original 3010, guest PC 0x0c0598d4 */
if(!s->budget--) { s->failed_pc=0x0c0598d4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0598d6;
P_0c0598d6: /* original 8b68, guest PC 0x0c0598d6 */
if(!s->budget--) { s->failed_pc=0x0c0598d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0599aa; }
goto P_0c0598d8;
P_0c0598d8: /* original 52c6, guest PC 0x0c0598d8 */
if(!s->budget--) { s->failed_pc=0x0c0598d8u; return 0; }
r[2]=read(ram,r[12]+24,4);
goto P_0c0598da;
P_0c0598da: /* original 53e6, guest PC 0x0c0598da */
if(!s->budget--) { s->failed_pc=0x0c0598dau; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c0598dc;
P_0c0598dc: /* original 3320, guest PC 0x0c0598dc */
if(!s->budget--) { s->failed_pc=0x0c0598dcu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0598de;
P_0c0598de: /* original 8901, guest PC 0x0c0598de */
if(!s->budget--) { s->failed_pc=0x0c0598deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0598e4; }
goto P_0c0598e0;
P_0c0598e0: /* original a075, guest PC 0x0c0598e0 */
if(!s->budget--) { s->failed_pc=0x0c0598e0u; return 0; }
r[0]=0x0000000fu;
goto P_0c0599ce;
P_0c0598e2: /* original e00f, guest PC 0x0c0598e2 */
if(!s->budget--) { s->failed_pc=0x0c0598e2u; return 0; }
r[0]=0x0000000fu;
goto P_0c0598e4;
P_0c0598e4: /* original 53c5, guest PC 0x0c0598e4 */
if(!s->budget--) { s->failed_pc=0x0c0598e4u; return 0; }
r[3]=read(ram,r[12]+20,4);
goto P_0c0598e6;
P_0c0598e6: /* original 52e5, guest PC 0x0c0598e6 */
if(!s->budget--) { s->failed_pc=0x0c0598e6u; return 0; }
r[2]=read(ram,r[14]+20,4);
goto P_0c0598e8;
P_0c0598e8: /* original 3230, guest PC 0x0c0598e8 */
if(!s->budget--) { s->failed_pc=0x0c0598e8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0598ea;
P_0c0598ea: /* original 8919, guest PC 0x0c0598ea */
if(!s->budget--) { s->failed_pc=0x0c0598eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059920; }
goto P_0c0598ec;
P_0c0598ec: /* original a06f, guest PC 0x0c0598ec */
if(!s->budget--) { s->failed_pc=0x0c0598ecu; return 0; }
r[0]=0x00000010u;
goto P_0c0599ce;
P_0c0598ee: /* original e010, guest PC 0x0c0598ee */
if(!s->budget--) { s->failed_pc=0x0c0598eeu; return 0; }
r[0]=0x00000010u;
if(!vf3_matrix_family(0x0c0598f0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0598f0u; return 0; } return 1;
P_0c059920: /* original d330, guest PC 0x0c059920 */
if(!s->budget--) { s->failed_pc=0x0c059920u; return 0; }
r[3]=read(ram,0x0c0599e4u,4);
goto P_0c059922;
P_0c059922: /* original 52e7, guest PC 0x0c059922 */
if(!s->budget--) { s->failed_pc=0x0c059922u; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c059924;
P_0c059924: /* original 2322, guest PC 0x0c059924 */
if(!s->budget--) { s->failed_pc=0x0c059924u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c059926;
P_0c059926: /* original e200, guest PC 0x0c059926 */
if(!s->budget--) { s->failed_pc=0x0c059926u; return 0; }
r[2]=0x00000000u;
goto P_0c059928;
P_0c059928: /* original d12f, guest PC 0x0c059928 */
if(!s->budget--) { s->failed_pc=0x0c059928u; return 0; }
r[1]=read(ram,0x0c0599e8u,4);
goto P_0c05992a;
P_0c05992a: /* original 2122, guest PC 0x0c05992a */
if(!s->budget--) { s->failed_pc=0x0c05992au; return 0; }
write(ram,r[1],r[2],4);
goto P_0c05992c;
P_0c05992c: /* original d02f, guest PC 0x0c05992c */
if(!s->budget--) { s->failed_pc=0x0c05992cu; return 0; }
r[0]=read(ram,0x0c0599ecu,4);
goto P_0c05992e;
P_0c05992e: /* original 53c7, guest PC 0x0c05992e */
if(!s->budget--) { s->failed_pc=0x0c05992eu; return 0; }
r[3]=read(ram,r[12]+28,4);
goto P_0c059930;
P_0c059930: /* original 2032, guest PC 0x0c059930 */
if(!s->budget--) { s->failed_pc=0x0c059930u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c059932;
P_0c059932: /* original e300, guest PC 0x0c059932 */
if(!s->budget--) { s->failed_pc=0x0c059932u; return 0; }
r[3]=0x00000000u;
goto P_0c059934;
P_0c059934: /* original d22e, guest PC 0x0c059934 */
if(!s->budget--) { s->failed_pc=0x0c059934u; return 0; }
r[2]=read(ram,0x0c0599f0u,4);
goto P_0c059936;
P_0c059936: /* original 2232, guest PC 0x0c059936 */
if(!s->budget--) { s->failed_pc=0x0c059936u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c059938;
P_0c059938: /* original de2e, guest PC 0x0c059938 */
if(!s->budget--) { s->failed_pc=0x0c059938u; return 0; }
r[14]=read(ram,0x0c0599f4u,4);
goto P_0c05993a;
P_0c05993a: /* original 7194, guest PC 0x0c05993a */
if(!s->budget--) { s->failed_pc=0x0c05993au; return 0; }
r[1]+=0xffffff94u;
goto P_0c05993c;
P_0c05993c: /* original 6512, guest PC 0x0c05993c */
if(!s->budget--) { s->failed_pc=0x0c05993cu; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c05993e;
P_0c05993e: /* original 4e0b, guest PC 0x0c05993e */
if(!s->budget--) { s->failed_pc=0x0c05993eu; return 0; }
target=r[14];
r[16]=code_base|0x0c059942u;
r[4]=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059942u) { target=s->pc; goto dispatch; }
goto P_0c059942;
P_0c059940: /* original e450, guest PC 0x0c059940 */
if(!s->budget--) { s->failed_pc=0x0c059940u; return 0; }
r[4]=0x00000050u;
goto P_0c059942;
P_0c059942: /* original d32d, guest PC 0x0c059942 */
if(!s->budget--) { s->failed_pc=0x0c059942u; return 0; }
r[3]=read(ram,0x0c0599f8u,4);
goto P_0c059944;
P_0c059944: /* original 6532, guest PC 0x0c059944 */
if(!s->budget--) { s->failed_pc=0x0c059944u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c059946;
P_0c059946: /* original 4e0b, guest PC 0x0c059946 */
if(!s->budget--) { s->failed_pc=0x0c059946u; return 0; }
target=r[14];
r[16]=code_base|0x0c05994au;
r[4]=0x00000054u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05994au) { target=s->pc; goto dispatch; }
goto P_0c05994a;
P_0c059948: /* original e454, guest PC 0x0c059948 */
if(!s->budget--) { s->failed_pc=0x0c059948u; return 0; }
r[4]=0x00000054u;
goto P_0c05994a;
P_0c05994a: /* original d526, guest PC 0x0c05994a */
if(!s->budget--) { s->failed_pc=0x0c05994au; return 0; }
r[5]=read(ram,0x0c0599e4u,4);
goto P_0c05994c;
P_0c05994c: /* original 6552, guest PC 0x0c05994c */
if(!s->budget--) { s->failed_pc=0x0c05994cu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c05994e;
P_0c05994e: /* original 4e0b, guest PC 0x0c05994e */
if(!s->budget--) { s->failed_pc=0x0c05994eu; return 0; }
target=r[14];
r[16]=code_base|0x0c059952u;
r[4]=0x00000060u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059952u) { target=s->pc; goto dispatch; }
goto P_0c059952;
P_0c059950: /* original e460, guest PC 0x0c059950 */
if(!s->budget--) { s->failed_pc=0x0c059950u; return 0; }
r[4]=0x00000060u;
goto P_0c059952;
P_0c059952: /* original d526, guest PC 0x0c059952 */
if(!s->budget--) { s->failed_pc=0x0c059952u; return 0; }
r[5]=read(ram,0x0c0599ecu,4);
goto P_0c059954;
P_0c059954: /* original 6552, guest PC 0x0c059954 */
if(!s->budget--) { s->failed_pc=0x0c059954u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c059956;
P_0c059956: /* original 4e0b, guest PC 0x0c059956 */
if(!s->budget--) { s->failed_pc=0x0c059956u; return 0; }
target=r[14];
r[16]=code_base|0x0c05995au;
r[4]=0x00000064u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05995au) { target=s->pc; goto dispatch; }
goto P_0c05995a;
P_0c059958: /* original e464, guest PC 0x0c059958 */
if(!s->budget--) { s->failed_pc=0x0c059958u; return 0; }
r[4]=0x00000064u;
goto P_0c05995a;
P_0c05995a: /* original d222, guest PC 0x0c05995a */
if(!s->budget--) { s->failed_pc=0x0c05995au; return 0; }
r[2]=read(ram,0x0c0599e4u,4);
goto P_0c05995c;
P_0c05995c: /* original 6322, guest PC 0x0c05995c */
if(!s->budget--) { s->failed_pc=0x0c05995cu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c05995e;
P_0c05995e: /* original d126, guest PC 0x0c05995e */
if(!s->budget--) { s->failed_pc=0x0c05995eu; return 0; }
r[1]=read(ram,0x0c0599f8u,4);
goto P_0c059960;
P_0c059960: /* original 2132, guest PC 0x0c059960 */
if(!s->budget--) { s->failed_pc=0x0c059960u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c059962;
P_0c059962: /* original d022, guest PC 0x0c059962 */
if(!s->budget--) { s->failed_pc=0x0c059962u; return 0; }
r[0]=read(ram,0x0c0599ecu,4);
goto P_0c059964;
P_0c059964: /* original 6302, guest PC 0x0c059964 */
if(!s->budget--) { s->failed_pc=0x0c059964u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c059966;
P_0c059966: /* original 72a0, guest PC 0x0c059966 */
if(!s->budget--) { s->failed_pc=0x0c059966u; return 0; }
r[2]+=0xffffffa0u;
goto P_0c059968;
P_0c059968: /* original 2232, guest PC 0x0c059968 */
if(!s->budget--) { s->failed_pc=0x0c059968u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c05996a;
P_0c05996a: /* original 60b3, guest PC 0x0c05996a */
if(!s->budget--) { s->failed_pc=0x0c05996au; return 0; }
r[0]=r[11];
goto P_0c05996c;
P_0c05996c: /* original 0009, guest PC 0x0c05996c */
if(!s->budget--) { s->failed_pc=0x0c05996cu; return 0; }
goto P_0c05996e;
P_0c05996e: /* original 8801, guest PC 0x0c05996e */
if(!s->budget--) { s->failed_pc=0x0c05996eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c059970;
P_0c059970: /* original 8b0b, guest PC 0x0c059970 */
if(!s->budget--) { s->failed_pc=0x0c059970u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05998a; }
goto P_0c059972;
P_0c059972: /* original e400, guest PC 0x0c059972 */
if(!s->budget--) { s->failed_pc=0x0c059972u; return 0; }
r[4]=0x00000000u;
goto P_0c059974;
P_0c059974: /* original d121, guest PC 0x0c059974 */
if(!s->budget--) { s->failed_pc=0x0c059974u; return 0; }
r[1]=read(ram,0x0c0599fcu,4);
goto P_0c059976;
P_0c059976: /* original 2142, guest PC 0x0c059976 */
if(!s->budget--) { s->failed_pc=0x0c059976u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c059978;
P_0c059978: /* original d321, guest PC 0x0c059978 */
if(!s->budget--) { s->failed_pc=0x0c059978u; return 0; }
r[3]=read(ram,0x0c059a00u,4);
goto P_0c05997a;
P_0c05997a: /* original 2342, guest PC 0x0c05997a */
if(!s->budget--) { s->failed_pc=0x0c05997au; return 0; }
write(ram,r[3],r[4],4);
goto P_0c05997c;
P_0c05997c: /* original d21e, guest PC 0x0c05997c */
if(!s->budget--) { s->failed_pc=0x0c05997cu; return 0; }
r[2]=read(ram,0x0c0599f8u,4);
goto P_0c05997e;
P_0c05997e: /* original 6522, guest PC 0x0c05997e */
if(!s->budget--) { s->failed_pc=0x0c05997eu; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c059980;
P_0c059980: /* original 4e0b, guest PC 0x0c059980 */
if(!s->budget--) { s->failed_pc=0x0c059980u; return 0; }
target=r[14];
r[16]=code_base|0x0c059984u;
r[4]=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059984u) { target=s->pc; goto dispatch; }
goto P_0c059984;
P_0c059982: /* original e450, guest PC 0x0c059982 */
if(!s->budget--) { s->failed_pc=0x0c059982u; return 0; }
r[4]=0x00000050u;
goto P_0c059984;
P_0c059984: /* original d31f, guest PC 0x0c059984 */
if(!s->budget--) { s->failed_pc=0x0c059984u; return 0; }
r[3]=read(ram,0x0c059a04u,4);
goto P_0c059986;
P_0c059986: /* original a006, guest PC 0x0c059986 */
if(!s->budget--) { s->failed_pc=0x0c059986u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c059996;
P_0c059988: /* original 6532, guest PC 0x0c059988 */
if(!s->budget--) { s->failed_pc=0x0c059988u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c05998a;
P_0c05998a: /* original d31b, guest PC 0x0c05998a */
if(!s->budget--) { s->failed_pc=0x0c05998au; return 0; }
r[3]=read(ram,0x0c0599f8u,4);
goto P_0c05998c;
P_0c05998c: /* original 6532, guest PC 0x0c05998c */
if(!s->budget--) { s->failed_pc=0x0c05998cu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c05998e;
P_0c05998e: /* original 4e0b, guest PC 0x0c05998e */
if(!s->budget--) { s->failed_pc=0x0c05998eu; return 0; }
target=r[14];
r[16]=code_base|0x0c059992u;
r[4]=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059992u) { target=s->pc; goto dispatch; }
goto P_0c059992;
P_0c059990: /* original e450, guest PC 0x0c059990 */
if(!s->budget--) { s->failed_pc=0x0c059990u; return 0; }
r[4]=0x00000050u;
goto P_0c059992;
P_0c059992: /* original d219, guest PC 0x0c059992 */
if(!s->budget--) { s->failed_pc=0x0c059992u; return 0; }
r[2]=read(ram,0x0c0599f8u,4);
goto P_0c059994;
P_0c059994: /* original 6522, guest PC 0x0c059994 */
if(!s->budget--) { s->failed_pc=0x0c059994u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c059996;
P_0c059996: /* original 4e0b, guest PC 0x0c059996 */
if(!s->budget--) { s->failed_pc=0x0c059996u; return 0; }
target=r[14];
r[16]=code_base|0x0c05999au;
r[4]=0x00000054u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05999au) { target=s->pc; goto dispatch; }
goto P_0c05999a;
P_0c059998: /* original e454, guest PC 0x0c059998 */
if(!s->budget--) { s->failed_pc=0x0c059998u; return 0; }
r[4]=0x00000054u;
goto P_0c05999a;
P_0c05999a: /* original e301, guest PC 0x0c05999a */
if(!s->budget--) { s->failed_pc=0x0c05999au; return 0; }
r[3]=0x00000001u;
goto P_0c05999c;
P_0c05999c: /* original d21a, guest PC 0x0c05999c */
if(!s->budget--) { s->failed_pc=0x0c05999cu; return 0; }
r[2]=read(ram,0x0c059a08u,4);
goto P_0c05999e;
P_0c05999e: /* original 2232, guest PC 0x0c05999e */
if(!s->budget--) { s->failed_pc=0x0c05999eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0599a0;
P_0c0599a0: /* original 61f2, guest PC 0x0c0599a0 */
if(!s->budget--) { s->failed_pc=0x0c0599a0u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0599a2;
P_0c0599a2: /* original d31a, guest PC 0x0c0599a2 */
if(!s->budget--) { s->failed_pc=0x0c0599a2u; return 0; }
r[3]=read(ram,0x0c059a0cu,4);
goto P_0c0599a4;
P_0c0599a4: /* original 2312, guest PC 0x0c0599a4 */
if(!s->budget--) { s->failed_pc=0x0c0599a4u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0599a6;
P_0c0599a6: /* original a010, guest PC 0x0c0599a6 */
if(!s->budget--) { s->failed_pc=0x0c0599a6u; return 0; }
goto P_0c0599ca;
P_0c0599a8: /* original 0009, guest PC 0x0c0599a8 */
if(!s->budget--) { s->failed_pc=0x0c0599a8u; return 0; }
goto P_0c0599aa;
P_0c0599aa: /* original 9418, guest PC 0x0c0599aa */
if(!s->budget--) { s->failed_pc=0x0c0599aau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0599deu,2);
goto P_0c0599ac;
P_0c0599ac: /* original d318, guest PC 0x0c0599ac */
if(!s->budget--) { s->failed_pc=0x0c0599acu; return 0; }
r[3]=read(ram,0x0c059a10u,4);
goto P_0c0599ae;
P_0c0599ae: /* original 430b, guest PC 0x0c0599ae */
if(!s->budget--) { s->failed_pc=0x0c0599aeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0599b2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0599b2u) { target=s->pc; goto dispatch; }
goto P_0c0599b2;
P_0c0599b0: /* original 0009, guest PC 0x0c0599b0 */
if(!s->budget--) { s->failed_pc=0x0c0599b0u; return 0; }
goto P_0c0599b2;
P_0c0599b2: /* original 9215, guest PC 0x0c0599b2 */
if(!s->budget--) { s->failed_pc=0x0c0599b2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0599e0u,2);
goto P_0c0599b4;
P_0c0599b4: /* original 3020, guest PC 0x0c0599b4 */
if(!s->budget--) { s->failed_pc=0x0c0599b4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[2])!=0);
goto P_0c0599b6;
P_0c0599b6: /* original 8b08, guest PC 0x0c0599b6 */
if(!s->budget--) { s->failed_pc=0x0c0599b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0599ca; }
goto P_0c0599b8;
P_0c0599b8: /* original d416, guest PC 0x0c0599b8 */
if(!s->budget--) { s->failed_pc=0x0c0599b8u; return 0; }
r[4]=read(ram,0x0c059a14u,4);
goto P_0c0599ba;
P_0c0599ba: /* original d117, guest PC 0x0c0599ba */
if(!s->budget--) { s->failed_pc=0x0c0599bau; return 0; }
r[1]=read(ram,0x0c059a18u,4);
goto P_0c0599bc;
P_0c0599bc: /* original 410b, guest PC 0x0c0599bc */
if(!s->budget--) { s->failed_pc=0x0c0599bcu; return 0; }
target=r[1];
r[16]=code_base|0x0c0599c0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0599c0u) { target=s->pc; goto dispatch; }
goto P_0c0599c0;
P_0c0599be: /* original 0009, guest PC 0x0c0599be */
if(!s->budget--) { s->failed_pc=0x0c0599beu; return 0; }
goto P_0c0599c0;
P_0c0599c0: /* original d316, guest PC 0x0c0599c0 */
if(!s->budget--) { s->failed_pc=0x0c0599c0u; return 0; }
r[3]=read(ram,0x0c059a1cu,4);
goto P_0c0599c2;
P_0c0599c2: /* original e054, guest PC 0x0c0599c2 */
if(!s->budget--) { s->failed_pc=0x0c0599c2u; return 0; }
r[0]=0x00000054u;
goto P_0c0599c4;
P_0c0599c4: /* original 430b, guest PC 0x0c0599c4 */
if(!s->budget--) { s->failed_pc=0x0c0599c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0599c8u;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0599c8u) { target=s->pc; goto dispatch; }
goto P_0c0599c8;
P_0c0599c6: /* original 04de, guest PC 0x0c0599c6 */
if(!s->budget--) { s->failed_pc=0x0c0599c6u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c0599c8;
P_0c0599c8: /* original 6a03, guest PC 0x0c0599c8 */
if(!s->budget--) { s->failed_pc=0x0c0599c8u; return 0; }
r[10]=r[0];
goto P_0c0599ca;
P_0c0599ca: /* original 60a3, guest PC 0x0c0599ca */
if(!s->budget--) { s->failed_pc=0x0c0599cau; return 0; }
r[0]=r[10];
goto P_0c0599cc;
P_0c0599cc: /* original 0009, guest PC 0x0c0599cc */
if(!s->budget--) { s->failed_pc=0x0c0599ccu; return 0; }
goto P_0c0599ce;
P_0c0599ce: /* original 7f04, guest PC 0x0c0599ce */
if(!s->budget--) { s->failed_pc=0x0c0599ceu; return 0; }
r[15]+=0x00000004u;
goto P_0c0599d0;
P_0c0599d0: /* original 4f26, guest PC 0x0c0599d0 */
if(!s->budget--) { s->failed_pc=0x0c0599d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0599d2;
P_0c0599d2: /* original 6af6, guest PC 0x0c0599d2 */
if(!s->budget--) { s->failed_pc=0x0c0599d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0599d4;
P_0c0599d4: /* original 6bf6, guest PC 0x0c0599d4 */
if(!s->budget--) { s->failed_pc=0x0c0599d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0599d6;
P_0c0599d6: /* original 6cf6, guest PC 0x0c0599d6 */
if(!s->budget--) { s->failed_pc=0x0c0599d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0599d8;
P_0c0599d8: /* original 6df6, guest PC 0x0c0599d8 */
if(!s->budget--) { s->failed_pc=0x0c0599d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0599da;
P_0c0599da: /* original 000b, guest PC 0x0c0599da */
if(!s->budget--) { s->failed_pc=0x0c0599dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0599dc: /* original 6ef6, guest PC 0x0c0599dc */
if(!s->budget--) { s->failed_pc=0x0c0599dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0599deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0599deu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
