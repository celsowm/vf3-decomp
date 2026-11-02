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
int vf3_away_batch3_adapter_20(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0455bcu: goto P_0c0455bc;
case 0x0c0455beu: goto P_0c0455be;
case 0x0c0455c0u: goto P_0c0455c0;
case 0x0c0455c2u: goto P_0c0455c2;
case 0x0c0455c4u: goto P_0c0455c4;
case 0x0c0455c6u: goto P_0c0455c6;
case 0x0c0455c8u: goto P_0c0455c8;
case 0x0c0455cau: goto P_0c0455ca;
case 0x0c0455ccu: goto P_0c0455cc;
case 0x0c0455ceu: goto P_0c0455ce;
case 0x0c0455d0u: goto P_0c0455d0;
case 0x0c0455d2u: goto P_0c0455d2;
case 0x0c0455d4u: goto P_0c0455d4;
case 0x0c0455d6u: goto P_0c0455d6;
case 0x0c0455d8u: goto P_0c0455d8;
case 0x0c0455dau: goto P_0c0455da;
case 0x0c0455dcu: goto P_0c0455dc;
case 0x0c0455deu: goto P_0c0455de;
case 0x0c0455e0u: goto P_0c0455e0;
case 0x0c0455e2u: goto P_0c0455e2;
case 0x0c0455e4u: goto P_0c0455e4;
case 0x0c0455e6u: goto P_0c0455e6;
case 0x0c0455e8u: goto P_0c0455e8;
case 0x0c0455eau: goto P_0c0455ea;
case 0x0c0455ecu: goto P_0c0455ec;
case 0x0c0455eeu: goto P_0c0455ee;
case 0x0c0455f0u: goto P_0c0455f0;
case 0x0c0455f2u: goto P_0c0455f2;
case 0x0c0455f4u: goto P_0c0455f4;
case 0x0c0455f6u: goto P_0c0455f6;
case 0x0c0455f8u: goto P_0c0455f8;
case 0x0c0455fau: goto P_0c0455fa;
case 0x0c0455fcu: goto P_0c0455fc;
case 0x0c0455feu: goto P_0c0455fe;
case 0x0c045600u: goto P_0c045600;
case 0x0c045602u: goto P_0c045602;
case 0x0c045604u: goto P_0c045604;
case 0x0c045606u: goto P_0c045606;
case 0x0c045608u: goto P_0c045608;
case 0x0c04560au: goto P_0c04560a;
case 0x0c04560cu: goto P_0c04560c;
case 0x0c04560eu: goto P_0c04560e;
case 0x0c045610u: goto P_0c045610;
case 0x0c045612u: goto P_0c045612;
case 0x0c045614u: goto P_0c045614;
case 0x0c045616u: goto P_0c045616;
case 0x0c045618u: goto P_0c045618;
case 0x0c04561au: goto P_0c04561a;
case 0x0c04561cu: goto P_0c04561c;
case 0x0c04561eu: goto P_0c04561e;
case 0x0c045620u: goto P_0c045620;
case 0x0c045622u: goto P_0c045622;
case 0x0c045624u: goto P_0c045624;
case 0x0c045626u: goto P_0c045626;
case 0x0c045628u: goto P_0c045628;
case 0x0c04562au: goto P_0c04562a;
case 0x0c04562cu: goto P_0c04562c;
case 0x0c04562eu: goto P_0c04562e;
case 0x0c045630u: goto P_0c045630;
case 0x0c045632u: goto P_0c045632;
case 0x0c045634u: goto P_0c045634;
case 0x0c045636u: goto P_0c045636;
case 0x0c045638u: goto P_0c045638;
case 0x0c04563au: goto P_0c04563a;
case 0x0c04563cu: goto P_0c04563c;
case 0x0c04563eu: goto P_0c04563e;
case 0x0c045640u: goto P_0c045640;
case 0x0c045642u: goto P_0c045642;
case 0x0c045644u: goto P_0c045644;
case 0x0c045646u: goto P_0c045646;
case 0x0c045648u: goto P_0c045648;
case 0x0c04564au: goto P_0c04564a;
case 0x0c04564cu: goto P_0c04564c;
case 0x0c04564eu: goto P_0c04564e;
case 0x0c045650u: goto P_0c045650;
case 0x0c045652u: goto P_0c045652;
case 0x0c045654u: goto P_0c045654;
case 0x0c045656u: goto P_0c045656;
case 0x0c045658u: goto P_0c045658;
case 0x0c04565au: goto P_0c04565a;
case 0x0c04565cu: goto P_0c04565c;
case 0x0c045674u: goto P_0c045674;
case 0x0c045676u: goto P_0c045676;
case 0x0c045678u: goto P_0c045678;
case 0x0c04567au: goto P_0c04567a;
case 0x0c04567cu: goto P_0c04567c;
case 0x0c04567eu: goto P_0c04567e;
case 0x0c045680u: goto P_0c045680;
case 0x0c045682u: goto P_0c045682;
case 0x0c045684u: goto P_0c045684;
case 0x0c045686u: goto P_0c045686;
case 0x0c045688u: goto P_0c045688;
case 0x0c04568au: goto P_0c04568a;
case 0x0c04568cu: goto P_0c04568c;
case 0x0c04568eu: goto P_0c04568e;
case 0x0c045690u: goto P_0c045690;
case 0x0c045692u: goto P_0c045692;
case 0x0c045694u: goto P_0c045694;
case 0x0c045696u: goto P_0c045696;
case 0x0c045698u: goto P_0c045698;
case 0x0c04569au: goto P_0c04569a;
case 0x0c04569cu: goto P_0c04569c;
case 0x0c04569eu: goto P_0c04569e;
case 0x0c0456a0u: goto P_0c0456a0;
case 0x0c0456a2u: goto P_0c0456a2;
case 0x0c0456a4u: goto P_0c0456a4;
case 0x0c0456a6u: goto P_0c0456a6;
case 0x0c0456a8u: goto P_0c0456a8;
case 0x0c0456aau: goto P_0c0456aa;
case 0x0c0456acu: goto P_0c0456ac;
case 0x0c0456aeu: goto P_0c0456ae;
case 0x0c0456b0u: goto P_0c0456b0;
case 0x0c0456b2u: goto P_0c0456b2;
case 0x0c0456b4u: goto P_0c0456b4;
case 0x0c0456b6u: goto P_0c0456b6;
case 0x0c0456b8u: goto P_0c0456b8;
case 0x0c0456bau: goto P_0c0456ba;
case 0x0c0456bcu: goto P_0c0456bc;
case 0x0c0456beu: goto P_0c0456be;
case 0x0c0456c0u: goto P_0c0456c0;
case 0x0c0456c2u: goto P_0c0456c2;
case 0x0c0456c4u: goto P_0c0456c4;
case 0x0c0456c6u: goto P_0c0456c6;
case 0x0c0456c8u: goto P_0c0456c8;
case 0x0c0456cau: goto P_0c0456ca;
case 0x0c0456ccu: goto P_0c0456cc;
case 0x0c0456ceu: goto P_0c0456ce;
case 0x0c0456d0u: goto P_0c0456d0;
case 0x0c0456d2u: goto P_0c0456d2;
case 0x0c0456d4u: goto P_0c0456d4;
case 0x0c0456d6u: goto P_0c0456d6;
case 0x0c0456d8u: goto P_0c0456d8;
case 0x0c0456dau: goto P_0c0456da;
case 0x0c0456dcu: goto P_0c0456dc;
case 0x0c0456deu: goto P_0c0456de;
case 0x0c0456e0u: goto P_0c0456e0;
case 0x0c0456e2u: goto P_0c0456e2;
case 0x0c0456e4u: goto P_0c0456e4;
case 0x0c0456e6u: goto P_0c0456e6;
case 0x0c0456e8u: goto P_0c0456e8;
case 0x0c0456eau: goto P_0c0456ea;
case 0x0c0456ecu: goto P_0c0456ec;
case 0x0c0456eeu: goto P_0c0456ee;
case 0x0c0456f0u: goto P_0c0456f0;
case 0x0c0456f2u: goto P_0c0456f2;
case 0x0c0456f4u: goto P_0c0456f4;
case 0x0c0456f6u: goto P_0c0456f6;
case 0x0c0456f8u: goto P_0c0456f8;
case 0x0c0456fau: goto P_0c0456fa;
case 0x0c0456fcu: goto P_0c0456fc;
case 0x0c0456feu: goto P_0c0456fe;
case 0x0c045700u: goto P_0c045700;
case 0x0c045702u: goto P_0c045702;
case 0x0c045704u: goto P_0c045704;
case 0x0c045706u: goto P_0c045706;
case 0x0c045708u: goto P_0c045708;
case 0x0c04570au: goto P_0c04570a;
case 0x0c04570cu: goto P_0c04570c;
case 0x0c04570eu: goto P_0c04570e;
case 0x0c045710u: goto P_0c045710;
case 0x0c045712u: goto P_0c045712;
case 0x0c045714u: goto P_0c045714;
case 0x0c045716u: goto P_0c045716;
case 0x0c045718u: goto P_0c045718;
case 0x0c04571au: goto P_0c04571a;
case 0x0c04571cu: goto P_0c04571c;
case 0x0c04571eu: goto P_0c04571e;
case 0x0c045720u: goto P_0c045720;
case 0x0c045722u: goto P_0c045722;
case 0x0c045724u: goto P_0c045724;
case 0x0c045726u: goto P_0c045726;
case 0x0c045728u: goto P_0c045728;
case 0x0c04572au: goto P_0c04572a;
case 0x0c04572cu: goto P_0c04572c;
case 0x0c04572eu: goto P_0c04572e;
case 0x0c045730u: goto P_0c045730;
case 0x0c045732u: goto P_0c045732;
case 0x0c045734u: goto P_0c045734;
case 0x0c045736u: goto P_0c045736;
case 0x0c045738u: goto P_0c045738;
case 0x0c04573au: goto P_0c04573a;
case 0x0c04573cu: goto P_0c04573c;
case 0x0c04573eu: goto P_0c04573e;
case 0x0c045740u: goto P_0c045740;
case 0x0c045742u: goto P_0c045742;
case 0x0c045744u: goto P_0c045744;
case 0x0c045746u: goto P_0c045746;
case 0x0c045748u: goto P_0c045748;
case 0x0c04574au: goto P_0c04574a;
case 0x0c04574cu: goto P_0c04574c;
case 0x0c04574eu: goto P_0c04574e;
case 0x0c045750u: goto P_0c045750;
case 0x0c045752u: goto P_0c045752;
case 0x0c045754u: goto P_0c045754;
case 0x0c045756u: goto P_0c045756;
case 0x0c045758u: goto P_0c045758;
case 0x0c04575au: goto P_0c04575a;
case 0x0c04575cu: goto P_0c04575c;
case 0x0c04575eu: goto P_0c04575e;
case 0x0c045760u: goto P_0c045760;
case 0x0c045762u: goto P_0c045762;
case 0x0c045764u: goto P_0c045764;
case 0x0c045766u: goto P_0c045766;
case 0x0c045768u: goto P_0c045768;
case 0x0c04576au: goto P_0c04576a;
case 0x0c04576cu: goto P_0c04576c;
case 0x0c04576eu: goto P_0c04576e;
case 0x0c045770u: goto P_0c045770;
case 0x0c045798u: goto P_0c045798;
case 0x0c04579au: goto P_0c04579a;
case 0x0c04579cu: goto P_0c04579c;
case 0x0c04579eu: goto P_0c04579e;
case 0x0c0457a0u: goto P_0c0457a0;
case 0x0c0457a2u: goto P_0c0457a2;
case 0x0c0457a4u: goto P_0c0457a4;
case 0x0c0457a6u: goto P_0c0457a6;
case 0x0c0457a8u: goto P_0c0457a8;
case 0x0c0457aau: goto P_0c0457aa;
case 0x0c0457acu: goto P_0c0457ac;
case 0x0c0457aeu: goto P_0c0457ae;
case 0x0c0457b0u: goto P_0c0457b0;
case 0x0c0457b2u: goto P_0c0457b2;
case 0x0c0457b4u: goto P_0c0457b4;
case 0x0c0457b6u: goto P_0c0457b6;
case 0x0c0457b8u: goto P_0c0457b8;
case 0x0c0457bau: goto P_0c0457ba;
case 0x0c0457bcu: goto P_0c0457bc;
case 0x0c0457beu: goto P_0c0457be;
case 0x0c0457c0u: goto P_0c0457c0;
case 0x0c0457c2u: goto P_0c0457c2;
case 0x0c0457c4u: goto P_0c0457c4;
case 0x0c0457c6u: goto P_0c0457c6;
case 0x0c0457c8u: goto P_0c0457c8;
case 0x0c0457cau: goto P_0c0457ca;
case 0x0c0457ccu: goto P_0c0457cc;
case 0x0c0457ceu: goto P_0c0457ce;
case 0x0c0457d0u: goto P_0c0457d0;
case 0x0c0457d2u: goto P_0c0457d2;
case 0x0c0457d4u: goto P_0c0457d4;
case 0x0c0457d6u: goto P_0c0457d6;
case 0x0c0457d8u: goto P_0c0457d8;
case 0x0c0457dau: goto P_0c0457da;
case 0x0c0457dcu: goto P_0c0457dc;
case 0x0c0457deu: goto P_0c0457de;
case 0x0c0457e0u: goto P_0c0457e0;
case 0x0c0457e2u: goto P_0c0457e2;
case 0x0c0457e4u: goto P_0c0457e4;
case 0x0c0457e6u: goto P_0c0457e6;
case 0x0c0457e8u: goto P_0c0457e8;
case 0x0c0457eau: goto P_0c0457ea;
case 0x0c0457ecu: goto P_0c0457ec;
case 0x0c0457eeu: goto P_0c0457ee;
case 0x0c0457f0u: goto P_0c0457f0;
case 0x0c0457f2u: goto P_0c0457f2;
case 0x0c0457f4u: goto P_0c0457f4;
case 0x0c0457f6u: goto P_0c0457f6;
case 0x0c0457f8u: goto P_0c0457f8;
case 0x0c0457fau: goto P_0c0457fa;
case 0x0c0457fcu: goto P_0c0457fc;
case 0x0c0457feu: goto P_0c0457fe;
case 0x0c045800u: goto P_0c045800;
case 0x0c045802u: goto P_0c045802;
case 0x0c045804u: goto P_0c045804;
case 0x0c045806u: goto P_0c045806;
case 0x0c045808u: goto P_0c045808;
case 0x0c04580au: goto P_0c04580a;
case 0x0c04580cu: goto P_0c04580c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0455bc: /* original 2fe6, guest PC 0x0c0455bc */
if(!s->budget--) { s->failed_pc=0x0c0455bcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0455be;
P_0c0455be: /* original 6043, guest PC 0x0c0455be */
if(!s->budget--) { s->failed_pc=0x0c0455beu; return 0; }
r[0]=r[4];
goto P_0c0455c0;
P_0c0455c0: /* original 2fd6, guest PC 0x0c0455c0 */
if(!s->budget--) { s->failed_pc=0x0c0455c0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0455c2;
P_0c0455c2: /* original 6e73, guest PC 0x0c0455c2 */
if(!s->budget--) { s->failed_pc=0x0c0455c2u; return 0; }
r[14]=r[7];
goto P_0c0455c4;
P_0c0455c4: /* original 2fc6, guest PC 0x0c0455c4 */
if(!s->budget--) { s->failed_pc=0x0c0455c4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0455c6;
P_0c0455c6: /* original 6c53, guest PC 0x0c0455c6 */
if(!s->budget--) { s->failed_pc=0x0c0455c6u; return 0; }
r[12]=r[5];
goto P_0c0455c8;
P_0c0455c8: /* original 2fb6, guest PC 0x0c0455c8 */
if(!s->budget--) { s->failed_pc=0x0c0455c8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0455ca;
P_0c0455ca: /* original 4f22, guest PC 0x0c0455ca */
if(!s->budget--) { s->failed_pc=0x0c0455cau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0455cc;
P_0c0455cc: /* original 7ff4, guest PC 0x0c0455cc */
if(!s->budget--) { s->failed_pc=0x0c0455ccu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0455ce;
P_0c0455ce: /* original 80f4, guest PC 0x0c0455ce */
if(!s->budget--) { s->failed_pc=0x0c0455ceu; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c0455d0;
P_0c0455d0: /* original 2f62, guest PC 0x0c0455d0 */
if(!s->budget--) { s->failed_pc=0x0c0455d0u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0455d2;
P_0c0455d2: /* original db23, guest PC 0x0c0455d2 */
if(!s->budget--) { s->failed_pc=0x0c0455d2u; return 0; }
r[11]=read(ram,0x0c045660u,4);
goto P_0c0455d4;
P_0c0455d4: /* original d323, guest PC 0x0c0455d4 */
if(!s->budget--) { s->failed_pc=0x0c0455d4u; return 0; }
r[3]=read(ram,0x0c045664u,4);
goto P_0c0455d6;
P_0c0455d6: /* original 4b0b, guest PC 0x0c0455d6 */
if(!s->budget--) { s->failed_pc=0x0c0455d6u; return 0; }
target=r[11];
r[16]=code_base|0x0c0455dau;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0455dau) { target=s->pc; goto dispatch; }
goto P_0c0455da;
P_0c0455d8: /* original 2f36, guest PC 0x0c0455d8 */
if(!s->budget--) { s->failed_pc=0x0c0455d8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0455da;
P_0c0455da: /* original 84c3, guest PC 0x0c0455da */
if(!s->budget--) { s->failed_pc=0x0c0455dau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+3,1);
goto P_0c0455dc;
P_0c0455dc: /* original 600c, guest PC 0x0c0455dc */
if(!s->budget--) { s->failed_pc=0x0c0455dcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0455de;
P_0c0455de: /* original 2f06, guest PC 0x0c0455de */
if(!s->budget--) { s->failed_pc=0x0c0455deu; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0455e0;
P_0c0455e0: /* original 84c2, guest PC 0x0c0455e0 */
if(!s->budget--) { s->failed_pc=0x0c0455e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+2,1);
goto P_0c0455e2;
P_0c0455e2: /* original 600c, guest PC 0x0c0455e2 */
if(!s->budget--) { s->failed_pc=0x0c0455e2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0455e4;
P_0c0455e4: /* original 2f06, guest PC 0x0c0455e4 */
if(!s->budget--) { s->failed_pc=0x0c0455e4u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0455e6;
P_0c0455e6: /* original 84c1, guest PC 0x0c0455e6 */
if(!s->budget--) { s->failed_pc=0x0c0455e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+1,1);
goto P_0c0455e8;
P_0c0455e8: /* original 600c, guest PC 0x0c0455e8 */
if(!s->budget--) { s->failed_pc=0x0c0455e8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0455ea;
P_0c0455ea: /* original 2f06, guest PC 0x0c0455ea */
if(!s->budget--) { s->failed_pc=0x0c0455eau; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0455ec;
P_0c0455ec: /* original e018, guest PC 0x0c0455ec */
if(!s->budget--) { s->failed_pc=0x0c0455ecu; return 0; }
r[0]=0x00000018u;
goto P_0c0455ee;
P_0c0455ee: /* original 63c0, guest PC 0x0c0455ee */
if(!s->budget--) { s->failed_pc=0x0c0455eeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[3]=tmp;
goto P_0c0455f0;
P_0c0455f0: /* original 633c, guest PC 0x0c0455f0 */
if(!s->budget--) { s->failed_pc=0x0c0455f0u; return 0; }
r[3]=r[3]&255u;
goto P_0c0455f2;
P_0c0455f2: /* original 2f36, guest PC 0x0c0455f2 */
if(!s->budget--) { s->failed_pc=0x0c0455f2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0455f4;
P_0c0455f4: /* original 00fc, guest PC 0x0c0455f4 */
if(!s->budget--) { s->failed_pc=0x0c0455f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c0455f6;
P_0c0455f6: /* original 600c, guest PC 0x0c0455f6 */
if(!s->budget--) { s->failed_pc=0x0c0455f6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0455f8;
P_0c0455f8: /* original 1f07, guest PC 0x0c0455f8 */
if(!s->budget--) { s->failed_pc=0x0c0455f8u; return 0; }
write(ram,r[15]+28,r[0],4);
goto P_0c0455fa;
P_0c0455fa: /* original 2f06, guest PC 0x0c0455fa */
if(!s->budget--) { s->failed_pc=0x0c0455fau; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0455fc;
P_0c0455fc: /* original d31a, guest PC 0x0c0455fc */
if(!s->budget--) { s->failed_pc=0x0c0455fcu; return 0; }
r[3]=read(ram,0x0c045668u,4);
goto P_0c0455fe;
P_0c0455fe: /* original 4b0b, guest PC 0x0c0455fe */
if(!s->budget--) { s->failed_pc=0x0c0455feu; return 0; }
target=r[11];
r[16]=code_base|0x0c045602u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045602u) { target=s->pc; goto dispatch; }
goto P_0c045602;
P_0c045600: /* original 2f36, guest PC 0x0c045600 */
if(!s->budget--) { s->failed_pc=0x0c045600u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045602;
P_0c045602: /* original 7f1c, guest PC 0x0c045602 */
if(!s->budget--) { s->failed_pc=0x0c045602u; return 0; }
r[15]+=0x0000001cu;
goto P_0c045604;
P_0c045604: /* original 55f8, guest PC 0x0c045604 */
if(!s->budget--) { s->failed_pc=0x0c045604u; return 0; }
r[5]=read(ram,r[15]+32,4);
goto P_0c045606;
P_0c045606: /* original beb7, guest PC 0x0c045606 */
if(!s->budget--) { s->failed_pc=0x0c045606u; return 0; }
target=code_base|0x0c045378u; r[16]=code_base|0x0c04560au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04560au) { target=s->pc; goto dispatch; }
goto P_0c04560a;
P_0c045608: /* original 64e3, guest PC 0x0c045608 */
if(!s->budget--) { s->failed_pc=0x0c045608u; return 0; }
r[4]=r[14];
goto P_0c04560a;
P_0c04560a: /* original ed00, guest PC 0x0c04560a */
if(!s->budget--) { s->failed_pc=0x0c04560au; return 0; }
r[13]=0x00000000u;
goto P_0c04560c;
P_0c04560c: /* original 60d3, guest PC 0x0c04560c */
if(!s->budget--) { s->failed_pc=0x0c04560cu; return 0; }
r[0]=r[13];
goto P_0c04560e;
P_0c04560e: /* original 80e2, guest PC 0x0c04560e */
if(!s->budget--) { s->failed_pc=0x0c04560eu; return 0; }
write(ram,r[14]+2,r[0],1);
goto P_0c045610;
P_0c045610: /* original 80e3, guest PC 0x0c045610 */
if(!s->budget--) { s->failed_pc=0x0c045610u; return 0; }
write(ram,r[14]+3,r[0],1);
goto P_0c045612;
P_0c045612: /* original 84c3, guest PC 0x0c045612 */
if(!s->budget--) { s->failed_pc=0x0c045612u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+3,1);
goto P_0c045614;
P_0c045614: /* original 53f2, guest PC 0x0c045614 */
if(!s->budget--) { s->failed_pc=0x0c045614u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c045616;
P_0c045616: /* original 600c, guest PC 0x0c045616 */
if(!s->budget--) { s->failed_pc=0x0c045616u; return 0; }
r[0]=r[0]&255u;
goto P_0c045618;
P_0c045618: /* original 2038, guest PC 0x0c045618 */
if(!s->budget--) { s->failed_pc=0x0c045618u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[3])==0)!=0);
goto P_0c04561a;
P_0c04561a: /* original 8909, guest PC 0x0c04561a */
if(!s->budget--) { s->failed_pc=0x0c04561au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c045630; }
goto P_0c04561c;
P_0c04561c: /* original d213, guest PC 0x0c04561c */
if(!s->budget--) { s->failed_pc=0x0c04561cu; return 0; }
r[2]=read(ram,0x0c04566cu,4);
goto P_0c04561e;
P_0c04561e: /* original 4b0b, guest PC 0x0c04561e */
if(!s->budget--) { s->failed_pc=0x0c04561eu; return 0; }
target=r[11];
r[16]=code_base|0x0c045622u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045622u) { target=s->pc; goto dispatch; }
goto P_0c045622;
P_0c045620: /* original 2f26, guest PC 0x0c045620 */
if(!s->budget--) { s->failed_pc=0x0c045620u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045622;
P_0c045622: /* original e004, guest PC 0x0c045622 */
if(!s->budget--) { s->failed_pc=0x0c045622u; return 0; }
r[0]=0x00000004u;
goto P_0c045624;
P_0c045624: /* original 80e4, guest PC 0x0c045624 */
if(!s->budget--) { s->failed_pc=0x0c045624u; return 0; }
write(ram,r[14]+4,r[0],1);
goto P_0c045626;
P_0c045626: /* original e001, guest PC 0x0c045626 */
if(!s->budget--) { s->failed_pc=0x0c045626u; return 0; }
r[0]=0x00000001u;
goto P_0c045628;
P_0c045628: /* original 7f04, guest PC 0x0c045628 */
if(!s->budget--) { s->failed_pc=0x0c045628u; return 0; }
r[15]+=0x00000004u;
goto P_0c04562a;
P_0c04562a: /* original 2ed0, guest PC 0x0c04562a */
if(!s->budget--) { s->failed_pc=0x0c04562au; return 0; }
write(ram,r[14],r[13],1);
goto P_0c04562c;
P_0c04562c: /* original 80e3, guest PC 0x0c04562c */
if(!s->budget--) { s->failed_pc=0x0c04562cu; return 0; }
write(ram,r[14]+3,r[0],1);
goto P_0c04562e;
P_0c04562e: /* original 1ed9, guest PC 0x0c04562e */
if(!s->budget--) { s->failed_pc=0x0c04562eu; return 0; }
write(ram,r[14]+36,r[13],4);
goto P_0c045630;
P_0c045630: /* original d20f, guest PC 0x0c045630 */
if(!s->budget--) { s->failed_pc=0x0c045630u; return 0; }
r[2]=read(ram,0x0c045670u,4);
goto P_0c045632;
P_0c045632: /* original 4b0b, guest PC 0x0c045632 */
if(!s->budget--) { s->failed_pc=0x0c045632u; return 0; }
target=r[11];
r[16]=code_base|0x0c045636u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045636u) { target=s->pc; goto dispatch; }
goto P_0c045636;
P_0c045634: /* original 2f26, guest PC 0x0c045634 */
if(!s->budget--) { s->failed_pc=0x0c045634u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045636;
P_0c045636: /* original 9012, guest PC 0x0c045636 */
if(!s->budget--) { s->failed_pc=0x0c045636u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04565eu,2);
goto P_0c045638;
P_0c045638: /* original 80e4, guest PC 0x0c045638 */
if(!s->budget--) { s->failed_pc=0x0c045638u; return 0; }
write(ram,r[14]+4,r[0],1);
goto P_0c04563a;
P_0c04563a: /* original 2ed0, guest PC 0x0c04563a */
if(!s->budget--) { s->failed_pc=0x0c04563au; return 0; }
write(ram,r[14],r[13],1);
goto P_0c04563c;
P_0c04563c: /* original 84e3, guest PC 0x0c04563c */
if(!s->budget--) { s->failed_pc=0x0c04563cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+3,1);
goto P_0c04563e;
P_0c04563e: /* original 2008, guest PC 0x0c04563e */
if(!s->budget--) { s->failed_pc=0x0c04563eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c045640;
P_0c045640: /* original 8d05, guest PC 0x0c045640 */
if(!s->budget--) { s->failed_pc=0x0c045640u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c04564e; }
goto P_0c045644;
P_0c045642: /* original 7f04, guest PC 0x0c045642 */
if(!s->budget--) { s->failed_pc=0x0c045642u; return 0; }
r[15]+=0x00000004u;
goto P_0c045644;
P_0c045644: /* original 63f2, guest PC 0x0c045644 */
if(!s->budget--) { s->failed_pc=0x0c045644u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c045646;
P_0c045646: /* original e010, guest PC 0x0c045646 */
if(!s->budget--) { s->failed_pc=0x0c045646u; return 0; }
r[0]=0x00000010u;
goto P_0c045648;
P_0c045648: /* original 03d4, guest PC 0x0c045648 */
if(!s->budget--) { s->failed_pc=0x0c045648u; return 0; }
write(ram,r[3]+r[0],r[13],1);
goto P_0c04564a;
P_0c04564a: /* original b18d, guest PC 0x0c04564a */
if(!s->budget--) { s->failed_pc=0x0c04564au; return 0; }
target=code_base|0x0c045968u; r[16]=code_base|0x0c04564eu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04564eu) { target=s->pc; goto dispatch; }
goto P_0c04564e;
P_0c04564c: /* original 64f2, guest PC 0x0c04564c */
if(!s->budget--) { s->failed_pc=0x0c04564cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c04564e;
P_0c04564e: /* original 7f0c, guest PC 0x0c04564e */
if(!s->budget--) { s->failed_pc=0x0c04564eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c045650;
P_0c045650: /* original 4f26, guest PC 0x0c045650 */
if(!s->budget--) { s->failed_pc=0x0c045650u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045652;
P_0c045652: /* original e000, guest PC 0x0c045652 */
if(!s->budget--) { s->failed_pc=0x0c045652u; return 0; }
r[0]=0x00000000u;
goto P_0c045654;
P_0c045654: /* original 6bf6, guest PC 0x0c045654 */
if(!s->budget--) { s->failed_pc=0x0c045654u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c045656;
P_0c045656: /* original 6cf6, guest PC 0x0c045656 */
if(!s->budget--) { s->failed_pc=0x0c045656u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c045658;
P_0c045658: /* original 6df6, guest PC 0x0c045658 */
if(!s->budget--) { s->failed_pc=0x0c045658u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04565a;
P_0c04565a: /* original 000b, guest PC 0x0c04565a */
if(!s->budget--) { s->failed_pc=0x0c04565au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04565c: /* original 6ef6, guest PC 0x0c04565c */
if(!s->budget--) { s->failed_pc=0x0c04565cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04565eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04565eu; return 0; } return 1;
P_0c045674: /* original 2fe6, guest PC 0x0c045674 */
if(!s->budget--) { s->failed_pc=0x0c045674u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045676;
P_0c045676: /* original 6043, guest PC 0x0c045676 */
if(!s->budget--) { s->failed_pc=0x0c045676u; return 0; }
r[0]=r[4];
goto P_0c045678;
P_0c045678: /* original 2fd6, guest PC 0x0c045678 */
if(!s->budget--) { s->failed_pc=0x0c045678u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04567a;
P_0c04567a: /* original ed00, guest PC 0x0c04567a */
if(!s->budget--) { s->failed_pc=0x0c04567au; return 0; }
r[13]=0x00000000u;
goto P_0c04567c;
P_0c04567c: /* original 2fc6, guest PC 0x0c04567c */
if(!s->budget--) { s->failed_pc=0x0c04567cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04567e;
P_0c04567e: /* original 6e73, guest PC 0x0c04567e */
if(!s->budget--) { s->failed_pc=0x0c04567eu; return 0; }
r[14]=r[7];
goto P_0c045680;
P_0c045680: /* original 2fb6, guest PC 0x0c045680 */
if(!s->budget--) { s->failed_pc=0x0c045680u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045682;
P_0c045682: /* original 2fa6, guest PC 0x0c045682 */
if(!s->budget--) { s->failed_pc=0x0c045682u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045684;
P_0c045684: /* original 2f96, guest PC 0x0c045684 */
if(!s->budget--) { s->failed_pc=0x0c045684u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045686;
P_0c045686: /* original 6963, guest PC 0x0c045686 */
if(!s->budget--) { s->failed_pc=0x0c045686u; return 0; }
r[9]=r[6];
goto P_0c045688;
P_0c045688: /* original 2f86, guest PC 0x0c045688 */
if(!s->budget--) { s->failed_pc=0x0c045688u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04568a;
P_0c04568a: /* original 4f22, guest PC 0x0c04568a */
if(!s->budget--) { s->failed_pc=0x0c04568au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04568c;
P_0c04568c: /* original 7ff8, guest PC 0x0c04568c */
if(!s->budget--) { s->failed_pc=0x0c04568cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c04568e;
P_0c04568e: /* original 80f4, guest PC 0x0c04568e */
if(!s->budget--) { s->failed_pc=0x0c04568eu; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c045690;
P_0c045690: /* original 2f52, guest PC 0x0c045690 */
if(!s->budget--) { s->failed_pc=0x0c045690u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c045692;
P_0c045692: /* original 5bfa, guest PC 0x0c045692 */
if(!s->budget--) { s->failed_pc=0x0c045692u; return 0; }
r[11]=read(ram,r[15]+40,4);
goto P_0c045694;
P_0c045694: /* original 65b3, guest PC 0x0c045694 */
if(!s->budget--) { s->failed_pc=0x0c045694u; return 0; }
r[5]=r[11];
goto P_0c045696;
P_0c045696: /* original be78, guest PC 0x0c045696 */
if(!s->budget--) { s->failed_pc=0x0c045696u; return 0; }
target=code_base|0x0c04538au; r[16]=code_base|0x0c04569au;
r[4]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04569au) { target=s->pc; goto dispatch; }
goto P_0c04569a;
P_0c045698: /* original 6473, guest PC 0x0c045698 */
if(!s->budget--) { s->failed_pc=0x0c045698u; return 0; }
r[4]=r[7];
goto P_0c04569a;
P_0c04569a: /* original 60d3, guest PC 0x0c04569a */
if(!s->budget--) { s->failed_pc=0x0c04569au; return 0; }
r[0]=r[13];
goto P_0c04569c;
P_0c04569c: /* original 80e2, guest PC 0x0c04569c */
if(!s->budget--) { s->failed_pc=0x0c04569cu; return 0; }
write(ram,r[14]+2,r[0],1);
goto P_0c04569e;
P_0c04569e: /* original 80e3, guest PC 0x0c04569e */
if(!s->budget--) { s->failed_pc=0x0c04569eu; return 0; }
write(ram,r[14]+3,r[0],1);
goto P_0c0456a0;
P_0c0456a0: /* original 84f4, guest PC 0x0c0456a0 */
if(!s->budget--) { s->failed_pc=0x0c0456a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c0456a2;
P_0c0456a2: /* original 63f2, guest PC 0x0c0456a2 */
if(!s->budget--) { s->failed_pc=0x0c0456a2u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0456a4;
P_0c0456a4: /* original 6803, guest PC 0x0c0456a4 */
if(!s->budget--) { s->failed_pc=0x0c0456a4u; return 0; }
r[8]=r[0];
goto P_0c0456a6;
P_0c0456a6: /* original 688c, guest PC 0x0c0456a6 */
if(!s->budget--) { s->failed_pc=0x0c0456a6u; return 0; }
r[8]=r[8]&255u;
goto P_0c0456a8;
P_0c0456a8: /* original 8432, guest PC 0x0c0456a8 */
if(!s->budget--) { s->failed_pc=0x0c0456a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+2,1);
goto P_0c0456aa;
P_0c0456aa: /* original dc33, guest PC 0x0c0456aa */
if(!s->budget--) { s->failed_pc=0x0c0456aau; return 0; }
r[12]=read(ram,0x0c045778u,4);
goto P_0c0456ac;
P_0c0456ac: /* original 600c, guest PC 0x0c0456ac */
if(!s->budget--) { s->failed_pc=0x0c0456acu; return 0; }
r[0]=r[0]&255u;
goto P_0c0456ae;
P_0c0456ae: /* original 2088, guest PC 0x0c0456ae */
if(!s->budget--) { s->failed_pc=0x0c0456aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[8])==0)!=0);
goto P_0c0456b0;
P_0c0456b0: /* original 8d0a, guest PC 0x0c0456b0 */
if(!s->budget--) { s->failed_pc=0x0c0456b0u; return 0; }
cond=r[17]&1u;
r[10]=0x00000001u;
if(cond) { goto P_0c0456c8; }
goto P_0c0456b4;
P_0c0456b2: /* original ea01, guest PC 0x0c0456b2 */
if(!s->budget--) { s->failed_pc=0x0c0456b2u; return 0; }
r[10]=0x00000001u;
goto P_0c0456b4;
P_0c0456b4: /* original d231, guest PC 0x0c0456b4 */
if(!s->budget--) { s->failed_pc=0x0c0456b4u; return 0; }
r[2]=read(ram,0x0c04577cu,4);
goto P_0c0456b6;
P_0c0456b6: /* original 4c0b, guest PC 0x0c0456b6 */
if(!s->budget--) { s->failed_pc=0x0c0456b6u; return 0; }
target=r[12];
r[16]=code_base|0x0c0456bau;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0456bau) { target=s->pc; goto dispatch; }
goto P_0c0456ba;
P_0c0456b8: /* original 2f26, guest PC 0x0c0456b8 */
if(!s->budget--) { s->failed_pc=0x0c0456b8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0456ba;
P_0c0456ba: /* original 60a3, guest PC 0x0c0456ba */
if(!s->budget--) { s->failed_pc=0x0c0456bau; return 0; }
r[0]=r[10];
goto P_0c0456bc;
P_0c0456bc: /* original 7f04, guest PC 0x0c0456bc */
if(!s->budget--) { s->failed_pc=0x0c0456bcu; return 0; }
r[15]+=0x00000004u;
goto P_0c0456be;
P_0c0456be: /* original 80e4, guest PC 0x0c0456be */
if(!s->budget--) { s->failed_pc=0x0c0456beu; return 0; }
write(ram,r[14]+4,r[0],1);
goto P_0c0456c0;
P_0c0456c0: /* original 2ed0, guest PC 0x0c0456c0 */
if(!s->budget--) { s->failed_pc=0x0c0456c0u; return 0; }
write(ram,r[14],r[13],1);
goto P_0c0456c2;
P_0c0456c2: /* original 53e9, guest PC 0x0c0456c2 */
if(!s->budget--) { s->failed_pc=0x0c0456c2u; return 0; }
r[3]=read(ram,r[14]+36,4);
goto P_0c0456c4;
P_0c0456c4: /* original 7301, guest PC 0x0c0456c4 */
if(!s->budget--) { s->failed_pc=0x0c0456c4u; return 0; }
r[3]+=0x00000001u;
goto P_0c0456c6;
P_0c0456c6: /* original 1e39, guest PC 0x0c0456c6 */
if(!s->budget--) { s->failed_pc=0x0c0456c6u; return 0; }
write(ram,r[14]+36,r[3],4);
goto P_0c0456c8;
P_0c0456c8: /* original 61f2, guest PC 0x0c0456c8 */
if(!s->budget--) { s->failed_pc=0x0c0456c8u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0456ca;
P_0c0456ca: /* original 8413, guest PC 0x0c0456ca */
if(!s->budget--) { s->failed_pc=0x0c0456cau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+3,1);
goto P_0c0456cc;
P_0c0456cc: /* original 600c, guest PC 0x0c0456cc */
if(!s->budget--) { s->failed_pc=0x0c0456ccu; return 0; }
r[0]=r[0]&255u;
goto P_0c0456ce;
P_0c0456ce: /* original 2088, guest PC 0x0c0456ce */
if(!s->budget--) { s->failed_pc=0x0c0456ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[8])==0)!=0);
goto P_0c0456d0;
P_0c0456d0: /* original 8909, guest PC 0x0c0456d0 */
if(!s->budget--) { s->failed_pc=0x0c0456d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0456e6; }
goto P_0c0456d2;
P_0c0456d2: /* original d22b, guest PC 0x0c0456d2 */
if(!s->budget--) { s->failed_pc=0x0c0456d2u; return 0; }
r[2]=read(ram,0x0c045780u,4);
goto P_0c0456d4;
P_0c0456d4: /* original 4c0b, guest PC 0x0c0456d4 */
if(!s->budget--) { s->failed_pc=0x0c0456d4u; return 0; }
target=r[12];
r[16]=code_base|0x0c0456d8u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0456d8u) { target=s->pc; goto dispatch; }
goto P_0c0456d8;
P_0c0456d6: /* original 2f26, guest PC 0x0c0456d6 */
if(!s->budget--) { s->failed_pc=0x0c0456d6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0456d8;
P_0c0456d8: /* original e004, guest PC 0x0c0456d8 */
if(!s->budget--) { s->failed_pc=0x0c0456d8u; return 0; }
r[0]=0x00000004u;
goto P_0c0456da;
P_0c0456da: /* original 80e4, guest PC 0x0c0456da */
if(!s->budget--) { s->failed_pc=0x0c0456dau; return 0; }
write(ram,r[14]+4,r[0],1);
goto P_0c0456dc;
P_0c0456dc: /* original 60a3, guest PC 0x0c0456dc */
if(!s->budget--) { s->failed_pc=0x0c0456dcu; return 0; }
r[0]=r[10];
goto P_0c0456de;
P_0c0456de: /* original 7f04, guest PC 0x0c0456de */
if(!s->budget--) { s->failed_pc=0x0c0456deu; return 0; }
r[15]+=0x00000004u;
goto P_0c0456e0;
P_0c0456e0: /* original 2ed0, guest PC 0x0c0456e0 */
if(!s->budget--) { s->failed_pc=0x0c0456e0u; return 0; }
write(ram,r[14],r[13],1);
goto P_0c0456e2;
P_0c0456e2: /* original 80e3, guest PC 0x0c0456e2 */
if(!s->budget--) { s->failed_pc=0x0c0456e2u; return 0; }
write(ram,r[14]+3,r[0],1);
goto P_0c0456e4;
P_0c0456e4: /* original 1ed9, guest PC 0x0c0456e4 */
if(!s->budget--) { s->failed_pc=0x0c0456e4u; return 0; }
write(ram,r[14]+36,r[13],4);
goto P_0c0456e6;
P_0c0456e6: /* original 62f2, guest PC 0x0c0456e6 */
if(!s->budget--) { s->failed_pc=0x0c0456e6u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0456e8;
P_0c0456e8: /* original 6320, guest PC 0x0c0456e8 */
if(!s->budget--) { s->failed_pc=0x0c0456e8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c0456ea;
P_0c0456ea: /* original 633c, guest PC 0x0c0456ea */
if(!s->budget--) { s->failed_pc=0x0c0456eau; return 0; }
r[3]=r[3]&255u;
goto P_0c0456ec;
P_0c0456ec: /* original 2388, guest PC 0x0c0456ec */
if(!s->budget--) { s->failed_pc=0x0c0456ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c0456ee;
P_0c0456ee: /* original 8953, guest PC 0x0c0456ee */
if(!s->budget--) { s->failed_pc=0x0c0456eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c045798; }
goto P_0c0456f0;
P_0c0456f0: /* original 84e7, guest PC 0x0c0456f0 */
if(!s->budget--) { s->failed_pc=0x0c0456f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+7,1);
goto P_0c0456f2;
P_0c0456f2: /* original 2008, guest PC 0x0c0456f2 */
if(!s->budget--) { s->failed_pc=0x0c0456f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0456f4;
P_0c0456f4: /* original 8b08, guest PC 0x0c0456f4 */
if(!s->budget--) { s->failed_pc=0x0c0456f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c045708; }
goto P_0c0456f6;
P_0c0456f6: /* original d223, guest PC 0x0c0456f6 */
if(!s->budget--) { s->failed_pc=0x0c0456f6u; return 0; }
r[2]=read(ram,0x0c045784u,4);
goto P_0c0456f8;
P_0c0456f8: /* original 4c0b, guest PC 0x0c0456f8 */
if(!s->budget--) { s->failed_pc=0x0c0456f8u; return 0; }
target=r[12];
r[16]=code_base|0x0c0456fcu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0456fcu) { target=s->pc; goto dispatch; }
goto P_0c0456fc;
P_0c0456fa: /* original 2f26, guest PC 0x0c0456fa */
if(!s->budget--) { s->failed_pc=0x0c0456fau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0456fc;
P_0c0456fc: /* original 63e0, guest PC 0x0c0456fc */
if(!s->budget--) { s->failed_pc=0x0c0456fcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[3]=tmp;
goto P_0c0456fe;
P_0c0456fe: /* original 2338, guest PC 0x0c0456fe */
if(!s->budget--) { s->failed_pc=0x0c0456feu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c045700;
P_0c045700: /* original 8f34, guest PC 0x0c045700 */
if(!s->budget--) { s->failed_pc=0x0c045700u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(!cond) { goto P_0c04576c; }
goto P_0c045704;
P_0c045702: /* original 7f04, guest PC 0x0c045702 */
if(!s->budget--) { s->failed_pc=0x0c045702u; return 0; }
r[15]+=0x00000004u;
goto P_0c045704;
P_0c045704: /* original a04f, guest PC 0x0c045704 */
if(!s->budget--) { s->failed_pc=0x0c045704u; return 0; }
goto P_0c0457a6;
P_0c045706: /* original 0009, guest PC 0x0c045706 */
if(!s->budget--) { s->failed_pc=0x0c045706u; return 0; }
goto P_0c045708;
P_0c045708: /* original 600c, guest PC 0x0c045708 */
if(!s->budget--) { s->failed_pc=0x0c045708u; return 0; }
r[0]=r[0]&255u;
goto P_0c04570a;
P_0c04570a: /* original 8801, guest PC 0x0c04570a */
if(!s->budget--) { s->failed_pc=0x0c04570au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c04570c;
P_0c04570c: /* original 8b18, guest PC 0x0c04570c */
if(!s->budget--) { s->failed_pc=0x0c04570cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c045740; }
goto P_0c04570e;
P_0c04570e: /* original d21e, guest PC 0x0c04570e */
if(!s->budget--) { s->failed_pc=0x0c04570eu; return 0; }
r[2]=read(ram,0x0c045788u,4);
goto P_0c045710;
P_0c045710: /* original 4c0b, guest PC 0x0c045710 */
if(!s->budget--) { s->failed_pc=0x0c045710u; return 0; }
target=r[12];
r[16]=code_base|0x0c045714u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045714u) { target=s->pc; goto dispatch; }
goto P_0c045714;
P_0c045712: /* original 2f26, guest PC 0x0c045712 */
if(!s->budget--) { s->failed_pc=0x0c045712u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045714;
P_0c045714: /* original 84e8, guest PC 0x0c045714 */
if(!s->budget--) { s->failed_pc=0x0c045714u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c045716;
P_0c045716: /* original 600c, guest PC 0x0c045716 */
if(!s->budget--) { s->failed_pc=0x0c045716u; return 0; }
r[0]=r[0]&255u;
goto P_0c045718;
P_0c045718: /* original 8805, guest PC 0x0c045718 */
if(!s->budget--) { s->failed_pc=0x0c045718u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c04571a;
P_0c04571a: /* original 8f04, guest PC 0x0c04571a */
if(!s->budget--) { s->failed_pc=0x0c04571au; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(!cond) { goto P_0c045726; }
goto P_0c04571e;
P_0c04571c: /* original 7f04, guest PC 0x0c04571c */
if(!s->budget--) { s->failed_pc=0x0c04571cu; return 0; }
r[15]+=0x00000004u;
goto P_0c04571e;
P_0c04571e: /* original 60a3, guest PC 0x0c04571e */
if(!s->budget--) { s->failed_pc=0x0c04571eu; return 0; }
r[0]=r[10];
goto P_0c045720;
P_0c045720: /* original 80e2, guest PC 0x0c045720 */
if(!s->budget--) { s->failed_pc=0x0c045720u; return 0; }
write(ram,r[14]+2,r[0],1);
goto P_0c045722;
P_0c045722: /* original a023, guest PC 0x0c045722 */
if(!s->budget--) { s->failed_pc=0x0c045722u; return 0; }
write(ram,r[14],r[0],1);
goto P_0c04576c;
P_0c045724: /* original 2e00, guest PC 0x0c045724 */
if(!s->budget--) { s->failed_pc=0x0c045724u; return 0; }
write(ram,r[14],r[0],1);
goto P_0c045726;
P_0c045726: /* original 53e9, guest PC 0x0c045726 */
if(!s->budget--) { s->failed_pc=0x0c045726u; return 0; }
r[3]=read(ram,r[14]+36,4);
goto P_0c045728;
P_0c045728: /* original 7301, guest PC 0x0c045728 */
if(!s->budget--) { s->failed_pc=0x0c045728u; return 0; }
r[3]+=0x00000001u;
goto P_0c04572a;
P_0c04572a: /* original 1e39, guest PC 0x0c04572a */
if(!s->budget--) { s->failed_pc=0x0c04572au; return 0; }
write(ram,r[14]+36,r[3],4);
goto P_0c04572c;
P_0c04572c: /* original d117, guest PC 0x0c04572c */
if(!s->budget--) { s->failed_pc=0x0c04572cu; return 0; }
r[1]=read(ram,0x0c04578cu,4);
goto P_0c04572e;
P_0c04572e: /* original 9020, guest PC 0x0c04572e */
if(!s->budget--) { s->failed_pc=0x0c04572eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c045772u,2);
goto P_0c045730;
P_0c045730: /* original 6212, guest PC 0x0c045730 */
if(!s->budget--) { s->failed_pc=0x0c045730u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c045732;
P_0c045732: /* original 032e, guest PC 0x0c045732 */
if(!s->budget--) { s->failed_pc=0x0c045732u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c045734;
P_0c045734: /* original 50e9, guest PC 0x0c045734 */
if(!s->budget--) { s->failed_pc=0x0c045734u; return 0; }
r[0]=read(ram,r[14]+36,4);
goto P_0c045736;
P_0c045736: /* original 3036, guest PC 0x0c045736 */
if(!s->budget--) { s->failed_pc=0x0c045736u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>r[3])!=0);
goto P_0c045738;
P_0c045738: /* original 890c, guest PC 0x0c045738 */
if(!s->budget--) { s->failed_pc=0x0c045738u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c045754; }
goto P_0c04573a;
P_0c04573a: /* original 60a3, guest PC 0x0c04573a */
if(!s->budget--) { s->failed_pc=0x0c04573au; return 0; }
r[0]=r[10];
goto P_0c04573c;
P_0c04573c: /* original a033, guest PC 0x0c04573c */
if(!s->budget--) { s->failed_pc=0x0c04573cu; return 0; }
write(ram,r[14]+4,r[0],1);
goto P_0c0457a6;
P_0c04573e: /* original 80e4, guest PC 0x0c04573e */
if(!s->budget--) { s->failed_pc=0x0c04573eu; return 0; }
write(ram,r[14]+4,r[0],1);
goto P_0c045740;
P_0c045740: /* original 84e7, guest PC 0x0c045740 */
if(!s->budget--) { s->failed_pc=0x0c045740u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+7,1);
goto P_0c045742;
P_0c045742: /* original 600c, guest PC 0x0c045742 */
if(!s->budget--) { s->failed_pc=0x0c045742u; return 0; }
r[0]=r[0]&255u;
goto P_0c045744;
P_0c045744: /* original 8804, guest PC 0x0c045744 */
if(!s->budget--) { s->failed_pc=0x0c045744u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c045746;
P_0c045746: /* original 8b0a, guest PC 0x0c045746 */
if(!s->budget--) { s->failed_pc=0x0c045746u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04575e; }
goto P_0c045748;
P_0c045748: /* original d211, guest PC 0x0c045748 */
if(!s->budget--) { s->failed_pc=0x0c045748u; return 0; }
r[2]=read(ram,0x0c045790u,4);
goto P_0c04574a;
P_0c04574a: /* original 4c0b, guest PC 0x0c04574a */
if(!s->budget--) { s->failed_pc=0x0c04574au; return 0; }
target=r[12];
r[16]=code_base|0x0c04574eu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04574eu) { target=s->pc; goto dispatch; }
goto P_0c04574e;
P_0c04574c: /* original 2f26, guest PC 0x0c04574c */
if(!s->budget--) { s->failed_pc=0x0c04574cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04574e;
P_0c04574e: /* original 60a3, guest PC 0x0c04574e */
if(!s->budget--) { s->failed_pc=0x0c04574eu; return 0; }
r[0]=r[10];
goto P_0c045750;
P_0c045750: /* original 80e3, guest PC 0x0c045750 */
if(!s->budget--) { s->failed_pc=0x0c045750u; return 0; }
write(ram,r[14]+3,r[0],1);
goto P_0c045752;
P_0c045752: /* original 7f04, guest PC 0x0c045752 */
if(!s->budget--) { s->failed_pc=0x0c045752u; return 0; }
r[15]+=0x00000004u;
goto P_0c045754;
P_0c045754: /* original 2ed0, guest PC 0x0c045754 */
if(!s->budget--) { s->failed_pc=0x0c045754u; return 0; }
write(ram,r[14],r[13],1);
goto P_0c045756;
P_0c045756: /* original 900d, guest PC 0x0c045756 */
if(!s->budget--) { s->failed_pc=0x0c045756u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c045774u,2);
goto P_0c045758;
P_0c045758: /* original 80e4, guest PC 0x0c045758 */
if(!s->budget--) { s->failed_pc=0x0c045758u; return 0; }
write(ram,r[14]+4,r[0],1);
goto P_0c04575a;
P_0c04575a: /* original a024, guest PC 0x0c04575a */
if(!s->budget--) { s->failed_pc=0x0c04575au; return 0; }
write(ram,r[14]+36,r[13],4);
goto P_0c0457a6;
P_0c04575c: /* original 1ed9, guest PC 0x0c04575c */
if(!s->budget--) { s->failed_pc=0x0c04575cu; return 0; }
write(ram,r[14]+36,r[13],4);
goto P_0c04575e;
P_0c04575e: /* original 84e7, guest PC 0x0c04575e */
if(!s->budget--) { s->failed_pc=0x0c04575eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+7,1);
goto P_0c045760;
P_0c045760: /* original 2008, guest PC 0x0c045760 */
if(!s->budget--) { s->failed_pc=0x0c045760u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c045762;
P_0c045762: /* original 8920, guest PC 0x0c045762 */
if(!s->budget--) { s->failed_pc=0x0c045762u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0457a6; }
goto P_0c045764;
P_0c045764: /* original d20b, guest PC 0x0c045764 */
if(!s->budget--) { s->failed_pc=0x0c045764u; return 0; }
r[2]=read(ram,0x0c045794u,4);
goto P_0c045766;
P_0c045766: /* original 4c0b, guest PC 0x0c045766 */
if(!s->budget--) { s->failed_pc=0x0c045766u; return 0; }
target=r[12];
r[16]=code_base|0x0c04576au;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04576au) { target=s->pc; goto dispatch; }
goto P_0c04576a;
P_0c045768: /* original 2f26, guest PC 0x0c045768 */
if(!s->budget--) { s->failed_pc=0x0c045768u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04576a;
P_0c04576a: /* original 7f04, guest PC 0x0c04576a */
if(!s->budget--) { s->failed_pc=0x0c04576au; return 0; }
r[15]+=0x00000004u;
goto P_0c04576c;
P_0c04576c: /* original 60d3, guest PC 0x0c04576c */
if(!s->budget--) { s->failed_pc=0x0c04576cu; return 0; }
r[0]=r[13];
goto P_0c04576e;
P_0c04576e: /* original a01a, guest PC 0x0c04576e */
if(!s->budget--) { s->failed_pc=0x0c04576eu; return 0; }
write(ram,r[14]+4,r[0],1);
goto P_0c0457a6;
P_0c045770: /* original 80e4, guest PC 0x0c045770 */
if(!s->budget--) { s->failed_pc=0x0c045770u; return 0; }
write(ram,r[14]+4,r[0],1);
if(!vf3_matrix_family(0x0c045772u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c045772u; return 0; } return 1;
P_0c045798: /* original d246, guest PC 0x0c045798 */
if(!s->budget--) { s->failed_pc=0x0c045798u; return 0; }
r[2]=read(ram,0x0c0458b4u,4);
goto P_0c04579a;
P_0c04579a: /* original 4c0b, guest PC 0x0c04579a */
if(!s->budget--) { s->failed_pc=0x0c04579au; return 0; }
target=r[12];
r[16]=code_base|0x0c04579eu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04579eu) { target=s->pc; goto dispatch; }
goto P_0c04579e;
P_0c04579c: /* original 2f26, guest PC 0x0c04579c */
if(!s->budget--) { s->failed_pc=0x0c04579cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04579e;
P_0c04579e: /* original 9086, guest PC 0x0c04579e */
if(!s->budget--) { s->failed_pc=0x0c04579eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0458aeu,2);
goto P_0c0457a0;
P_0c0457a0: /* original 7f04, guest PC 0x0c0457a0 */
if(!s->budget--) { s->failed_pc=0x0c0457a0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0457a2;
P_0c0457a2: /* original 80e4, guest PC 0x0c0457a2 */
if(!s->budget--) { s->failed_pc=0x0c0457a2u; return 0; }
write(ram,r[14]+4,r[0],1);
goto P_0c0457a4;
P_0c0457a4: /* original 2ed0, guest PC 0x0c0457a4 */
if(!s->budget--) { s->failed_pc=0x0c0457a4u; return 0; }
write(ram,r[14],r[13],1);
goto P_0c0457a6;
P_0c0457a6: /* original 63e0, guest PC 0x0c0457a6 */
if(!s->budget--) { s->failed_pc=0x0c0457a6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[3]=tmp;
goto P_0c0457a8;
P_0c0457a8: /* original 2338, guest PC 0x0c0457a8 */
if(!s->budget--) { s->failed_pc=0x0c0457a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0457aa;
P_0c0457aa: /* original 8915, guest PC 0x0c0457aa */
if(!s->budget--) { s->failed_pc=0x0c0457aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0457d8; }
goto P_0c0457ac;
P_0c0457ac: /* original 84e7, guest PC 0x0c0457ac */
if(!s->budget--) { s->failed_pc=0x0c0457acu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+7,1);
goto P_0c0457ae;
P_0c0457ae: /* original 2008, guest PC 0x0c0457ae */
if(!s->budget--) { s->failed_pc=0x0c0457aeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0457b0;
P_0c0457b0: /* original 8912, guest PC 0x0c0457b0 */
if(!s->budget--) { s->failed_pc=0x0c0457b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0457d8; }
goto P_0c0457b2;
P_0c0457b2: /* original d341, guest PC 0x0c0457b2 */
if(!s->budget--) { s->failed_pc=0x0c0457b2u; return 0; }
r[3]=read(ram,0x0c0458b8u,4);
goto P_0c0457b4;
P_0c0457b4: /* original 917c, guest PC 0x0c0457b4 */
if(!s->budget--) { s->failed_pc=0x0c0457b4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0458b0u,2);
goto P_0c0457b6;
P_0c0457b6: /* original 6032, guest PC 0x0c0457b6 */
if(!s->budget--) { s->failed_pc=0x0c0457b6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0457b8;
P_0c0457b8: /* original 001e, guest PC 0x0c0457b8 */
if(!s->budget--) { s->failed_pc=0x0c0457b8u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c0457ba;
P_0c0457ba: /* original 8801, guest PC 0x0c0457ba */
if(!s->budget--) { s->failed_pc=0x0c0457bau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0457bc;
P_0c0457bc: /* original 8b0c, guest PC 0x0c0457bc */
if(!s->budget--) { s->failed_pc=0x0c0457bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0457d8; }
goto P_0c0457be;
P_0c0457be: /* original 60b2, guest PC 0x0c0457be */
if(!s->budget--) { s->failed_pc=0x0c0457beu; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c0457c0;
P_0c0457c0: /* original 6403, guest PC 0x0c0457c0 */
if(!s->budget--) { s->failed_pc=0x0c0457c0u; return 0; }
r[4]=r[0];
goto P_0c0457c2;
P_0c0457c2: /* original 88ff, guest PC 0x0c0457c2 */
if(!s->budget--) { s->failed_pc=0x0c0457c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0457c4;
P_0c0457c4: /* original 8908, guest PC 0x0c0457c4 */
if(!s->budget--) { s->failed_pc=0x0c0457c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0457d8; }
goto P_0c0457c6;
P_0c0457c6: /* original 9274, guest PC 0x0c0457c6 */
if(!s->budget--) { s->failed_pc=0x0c0457c6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0458b2u,2);
goto P_0c0457c8;
P_0c0457c8: /* original 3420, guest PC 0x0c0457c8 */
if(!s->budget--) { s->failed_pc=0x0c0457c8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0457ca;
P_0c0457ca: /* original 8905, guest PC 0x0c0457ca */
if(!s->budget--) { s->failed_pc=0x0c0457cau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0457d8; }
goto P_0c0457cc;
P_0c0457cc: /* original 65b2, guest PC 0x0c0457cc */
if(!s->budget--) { s->failed_pc=0x0c0457ccu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0457ce;
P_0c0457ce: /* original d33b, guest PC 0x0c0457ce */
if(!s->budget--) { s->failed_pc=0x0c0457ceu; return 0; }
r[3]=read(ram,0x0c0458bcu,4);
goto P_0c0457d0;
P_0c0457d0: /* original 655c, guest PC 0x0c0457d0 */
if(!s->budget--) { s->failed_pc=0x0c0457d0u; return 0; }
r[5]=r[5]&255u;
goto P_0c0457d2;
P_0c0457d2: /* original 7501, guest PC 0x0c0457d2 */
if(!s->budget--) { s->failed_pc=0x0c0457d2u; return 0; }
r[5]+=0x00000001u;
goto P_0c0457d4;
P_0c0457d4: /* original 430b, guest PC 0x0c0457d4 */
if(!s->budget--) { s->failed_pc=0x0c0457d4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0457d8u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0457d8u) { target=s->pc; goto dispatch; }
goto P_0c0457d8;
P_0c0457d6: /* original 64b3, guest PC 0x0c0457d6 */
if(!s->budget--) { s->failed_pc=0x0c0457d6u; return 0; }
r[4]=r[11];
goto P_0c0457d8;
P_0c0457d8: /* original 84e2, guest PC 0x0c0457d8 */
if(!s->budget--) { s->failed_pc=0x0c0457d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c0457da;
P_0c0457da: /* original 2008, guest PC 0x0c0457da */
if(!s->budget--) { s->failed_pc=0x0c0457dau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0457dc;
P_0c0457dc: /* original 8905, guest PC 0x0c0457dc */
if(!s->budget--) { s->failed_pc=0x0c0457dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0457ea; }
goto P_0c0457de;
P_0c0457de: /* original e010, guest PC 0x0c0457de */
if(!s->budget--) { s->failed_pc=0x0c0457deu; return 0; }
r[0]=0x00000010u;
goto P_0c0457e0;
P_0c0457e0: /* original 65e3, guest PC 0x0c0457e0 */
if(!s->budget--) { s->failed_pc=0x0c0457e0u; return 0; }
r[5]=r[14];
goto P_0c0457e2;
P_0c0457e2: /* original 66b3, guest PC 0x0c0457e2 */
if(!s->budget--) { s->failed_pc=0x0c0457e2u; return 0; }
r[6]=r[11];
goto P_0c0457e4;
P_0c0457e4: /* original 09d4, guest PC 0x0c0457e4 */
if(!s->budget--) { s->failed_pc=0x0c0457e4u; return 0; }
write(ram,r[9]+r[0],r[13],1);
goto P_0c0457e6;
P_0c0457e6: /* original b012, guest PC 0x0c0457e6 */
if(!s->budget--) { s->failed_pc=0x0c0457e6u; return 0; }
target=code_base|0x0c04580eu; r[16]=code_base|0x0c0457eau;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0457eau) { target=s->pc; goto dispatch; }
goto P_0c0457ea;
P_0c0457e8: /* original 6493, guest PC 0x0c0457e8 */
if(!s->budget--) { s->failed_pc=0x0c0457e8u; return 0; }
r[4]=r[9];
goto P_0c0457ea;
P_0c0457ea: /* original 84e3, guest PC 0x0c0457ea */
if(!s->budget--) { s->failed_pc=0x0c0457eau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+3,1);
goto P_0c0457ec;
P_0c0457ec: /* original 2008, guest PC 0x0c0457ec */
if(!s->budget--) { s->failed_pc=0x0c0457ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0457ee;
P_0c0457ee: /* original 8903, guest PC 0x0c0457ee */
if(!s->budget--) { s->failed_pc=0x0c0457eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0457f8; }
goto P_0c0457f0;
P_0c0457f0: /* original e010, guest PC 0x0c0457f0 */
if(!s->budget--) { s->failed_pc=0x0c0457f0u; return 0; }
r[0]=0x00000010u;
goto P_0c0457f2;
P_0c0457f2: /* original 09d4, guest PC 0x0c0457f2 */
if(!s->budget--) { s->failed_pc=0x0c0457f2u; return 0; }
write(ram,r[9]+r[0],r[13],1);
goto P_0c0457f4;
P_0c0457f4: /* original b0b8, guest PC 0x0c0457f4 */
if(!s->budget--) { s->failed_pc=0x0c0457f4u; return 0; }
target=code_base|0x0c045968u; r[16]=code_base|0x0c0457f8u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0457f8u) { target=s->pc; goto dispatch; }
goto P_0c0457f8;
P_0c0457f6: /* original 6493, guest PC 0x0c0457f6 */
if(!s->budget--) { s->failed_pc=0x0c0457f6u; return 0; }
r[4]=r[9];
goto P_0c0457f8;
P_0c0457f8: /* original 7f08, guest PC 0x0c0457f8 */
if(!s->budget--) { s->failed_pc=0x0c0457f8u; return 0; }
r[15]+=0x00000008u;
goto P_0c0457fa;
P_0c0457fa: /* original 4f26, guest PC 0x0c0457fa */
if(!s->budget--) { s->failed_pc=0x0c0457fau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0457fc;
P_0c0457fc: /* original e000, guest PC 0x0c0457fc */
if(!s->budget--) { s->failed_pc=0x0c0457fcu; return 0; }
r[0]=0x00000000u;
goto P_0c0457fe;
P_0c0457fe: /* original 68f6, guest PC 0x0c0457fe */
if(!s->budget--) { s->failed_pc=0x0c0457feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c045800;
P_0c045800: /* original 69f6, guest PC 0x0c045800 */
if(!s->budget--) { s->failed_pc=0x0c045800u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c045802;
P_0c045802: /* original 6af6, guest PC 0x0c045802 */
if(!s->budget--) { s->failed_pc=0x0c045802u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c045804;
P_0c045804: /* original 6bf6, guest PC 0x0c045804 */
if(!s->budget--) { s->failed_pc=0x0c045804u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c045806;
P_0c045806: /* original 6cf6, guest PC 0x0c045806 */
if(!s->budget--) { s->failed_pc=0x0c045806u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c045808;
P_0c045808: /* original 6df6, guest PC 0x0c045808 */
if(!s->budget--) { s->failed_pc=0x0c045808u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04580a;
P_0c04580a: /* original 000b, guest PC 0x0c04580a */
if(!s->budget--) { s->failed_pc=0x0c04580au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04580c: /* original 6ef6, guest PC 0x0c04580c */
if(!s->budget--) { s->failed_pc=0x0c04580cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04580eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
