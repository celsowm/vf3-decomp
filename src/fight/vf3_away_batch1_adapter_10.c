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
int vf3_away_batch1_adapter_10(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04625cu: goto P_0c04625c;
case 0x0c04625eu: goto P_0c04625e;
case 0x0c046260u: goto P_0c046260;
case 0x0c046262u: goto P_0c046262;
case 0x0c046264u: goto P_0c046264;
case 0x0c046266u: goto P_0c046266;
case 0x0c046268u: goto P_0c046268;
case 0x0c04626au: goto P_0c04626a;
case 0x0c04626cu: goto P_0c04626c;
case 0x0c04626eu: goto P_0c04626e;
case 0x0c046270u: goto P_0c046270;
case 0x0c046272u: goto P_0c046272;
case 0x0c046274u: goto P_0c046274;
case 0x0c046276u: goto P_0c046276;
case 0x0c046278u: goto P_0c046278;
case 0x0c04627au: goto P_0c04627a;
case 0x0c04627cu: goto P_0c04627c;
case 0x0c04627eu: goto P_0c04627e;
case 0x0c046280u: goto P_0c046280;
case 0x0c046282u: goto P_0c046282;
case 0x0c046284u: goto P_0c046284;
case 0x0c046286u: goto P_0c046286;
case 0x0c046288u: goto P_0c046288;
case 0x0c04628au: goto P_0c04628a;
case 0x0c04628cu: goto P_0c04628c;
case 0x0c04628eu: goto P_0c04628e;
case 0x0c046290u: goto P_0c046290;
case 0x0c046292u: goto P_0c046292;
case 0x0c046294u: goto P_0c046294;
case 0x0c046296u: goto P_0c046296;
case 0x0c046298u: goto P_0c046298;
case 0x0c04629au: goto P_0c04629a;
case 0x0c04629cu: goto P_0c04629c;
case 0x0c04629eu: goto P_0c04629e;
case 0x0c0462a0u: goto P_0c0462a0;
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
case 0x0c059400u: goto P_0c059400;
case 0x0c059402u: goto P_0c059402;
case 0x0c059404u: goto P_0c059404;
case 0x0c059406u: goto P_0c059406;
case 0x0c059408u: goto P_0c059408;
case 0x0c05940au: goto P_0c05940a;
case 0x0c05940cu: goto P_0c05940c;
case 0x0c05940eu: goto P_0c05940e;
case 0x0c059410u: goto P_0c059410;
case 0x0c059412u: goto P_0c059412;
case 0x0c059414u: goto P_0c059414;
case 0x0c059416u: goto P_0c059416;
case 0x0c059418u: goto P_0c059418;
case 0x0c05941au: goto P_0c05941a;
case 0x0c05941cu: goto P_0c05941c;
case 0x0c05941eu: goto P_0c05941e;
case 0x0c059420u: goto P_0c059420;
case 0x0c059422u: goto P_0c059422;
case 0x0c059424u: goto P_0c059424;
case 0x0c059426u: goto P_0c059426;
case 0x0c059428u: goto P_0c059428;
case 0x0c05942au: goto P_0c05942a;
case 0x0c05942cu: goto P_0c05942c;
case 0x0c05942eu: goto P_0c05942e;
case 0x0c059430u: goto P_0c059430;
case 0x0c059432u: goto P_0c059432;
case 0x0c059434u: goto P_0c059434;
case 0x0c059436u: goto P_0c059436;
case 0x0c059438u: goto P_0c059438;
case 0x0c05943au: goto P_0c05943a;
case 0x0c05943cu: goto P_0c05943c;
case 0x0c05943eu: goto P_0c05943e;
case 0x0c059440u: goto P_0c059440;
case 0x0c059442u: goto P_0c059442;
case 0x0c059444u: goto P_0c059444;
case 0x0c059446u: goto P_0c059446;
case 0x0c059448u: goto P_0c059448;
case 0x0c05944au: goto P_0c05944a;
case 0x0c05944cu: goto P_0c05944c;
case 0x0c05944eu: goto P_0c05944e;
case 0x0c059450u: goto P_0c059450;
case 0x0c059452u: goto P_0c059452;
case 0x0c059454u: goto P_0c059454;
case 0x0c059456u: goto P_0c059456;
case 0x0c059458u: goto P_0c059458;
case 0x0c05945au: goto P_0c05945a;
case 0x0c05945cu: goto P_0c05945c;
case 0x0c05945eu: goto P_0c05945e;
case 0x0c059460u: goto P_0c059460;
case 0x0c059462u: goto P_0c059462;
case 0x0c059464u: goto P_0c059464;
case 0x0c059466u: goto P_0c059466;
case 0x0c059468u: goto P_0c059468;
case 0x0c05946au: goto P_0c05946a;
case 0x0c05946cu: goto P_0c05946c;
case 0x0c05946eu: goto P_0c05946e;
case 0x0c059470u: goto P_0c059470;
case 0x0c059472u: goto P_0c059472;
case 0x0c059474u: goto P_0c059474;
case 0x0c0594b4u: goto P_0c0594b4;
case 0x0c0594b6u: goto P_0c0594b6;
case 0x0c0594b8u: goto P_0c0594b8;
case 0x0c0594bau: goto P_0c0594ba;
case 0x0c0594bcu: goto P_0c0594bc;
case 0x0c0594beu: goto P_0c0594be;
case 0x0c0594c0u: goto P_0c0594c0;
case 0x0c0594c2u: goto P_0c0594c2;
case 0x0c0594c4u: goto P_0c0594c4;
case 0x0c0594c6u: goto P_0c0594c6;
case 0x0c0594c8u: goto P_0c0594c8;
case 0x0c0594cau: goto P_0c0594ca;
case 0x0c0594ccu: goto P_0c0594cc;
case 0x0c0594ceu: goto P_0c0594ce;
case 0x0c0594d0u: goto P_0c0594d0;
case 0x0c0594d2u: goto P_0c0594d2;
case 0x0c0594d4u: goto P_0c0594d4;
case 0x0c0594d6u: goto P_0c0594d6;
case 0x0c0594d8u: goto P_0c0594d8;
case 0x0c0594dau: goto P_0c0594da;
case 0x0c0594dcu: goto P_0c0594dc;
case 0x0c0594deu: goto P_0c0594de;
case 0x0c0594e0u: goto P_0c0594e0;
case 0x0c0594e2u: goto P_0c0594e2;
case 0x0c0594e4u: goto P_0c0594e4;
case 0x0c0594e6u: goto P_0c0594e6;
case 0x0c0594e8u: goto P_0c0594e8;
case 0x0c0594eau: goto P_0c0594ea;
case 0x0c0594ecu: goto P_0c0594ec;
case 0x0c0594eeu: goto P_0c0594ee;
case 0x0c0594f0u: goto P_0c0594f0;
case 0x0c0594f2u: goto P_0c0594f2;
case 0x0c0594f4u: goto P_0c0594f4;
case 0x0c0594f6u: goto P_0c0594f6;
case 0x0c0594f8u: goto P_0c0594f8;
case 0x0c0594fau: goto P_0c0594fa;
case 0x0c0594fcu: goto P_0c0594fc;
case 0x0c0594feu: goto P_0c0594fe;
case 0x0c059500u: goto P_0c059500;
case 0x0c059502u: goto P_0c059502;
case 0x0c059504u: goto P_0c059504;
case 0x0c059506u: goto P_0c059506;
case 0x0c059524u: goto P_0c059524;
case 0x0c059526u: goto P_0c059526;
case 0x0c059528u: goto P_0c059528;
case 0x0c05952au: goto P_0c05952a;
case 0x0c05952cu: goto P_0c05952c;
case 0x0c05952eu: goto P_0c05952e;
case 0x0c059530u: goto P_0c059530;
case 0x0c059532u: goto P_0c059532;
case 0x0c059534u: goto P_0c059534;
case 0x0c059536u: goto P_0c059536;
case 0x0c059538u: goto P_0c059538;
case 0x0c05953au: goto P_0c05953a;
case 0x0c05953cu: goto P_0c05953c;
case 0x0c05953eu: goto P_0c05953e;
case 0x0c059540u: goto P_0c059540;
case 0x0c059542u: goto P_0c059542;
case 0x0c059544u: goto P_0c059544;
case 0x0c060cf2u: goto P_0c060cf2;
case 0x0c060cf4u: goto P_0c060cf4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04625c: /* original be8f, guest PC 0x0c04625c */
if(!s->budget--) { s->failed_pc=0x0c04625cu; return 0; }
target=code_base|0x0c045f7eu; r[16]=code_base|0x0c046260u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c046260u) { target=s->pc; goto dispatch; }
goto P_0c046260;
P_0c04625e: /* original 64f1, guest PC 0x0c04625e */
if(!s->budget--) { s->failed_pc=0x0c04625eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c046260;
P_0c046260: /* original 6e03, guest PC 0x0c046260 */
if(!s->budget--) { s->failed_pc=0x0c046260u; return 0; }
r[14]=r[0];
goto P_0c046262;
P_0c046262: /* original 2ee8, guest PC 0x0c046262 */
if(!s->budget--) { s->failed_pc=0x0c046262u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c046264;
P_0c046264: /* original 8b00, guest PC 0x0c046264 */
if(!s->budget--) { s->failed_pc=0x0c046264u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c046268; }
goto P_0c046266;
P_0c046266: /* original c332, guest PC 0x0c046266 */
if(!s->budget--) { s->failed_pc=0x0c046266u; return 0; }
s->failed_pc=0x0c046266u; return 0;
goto P_0c046268;
P_0c046268: /* original 54e1, guest PC 0x0c046268 */
if(!s->budget--) { s->failed_pc=0x0c046268u; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c04626a;
P_0c04626a: /* original 84e2, guest PC 0x0c04626a */
if(!s->budget--) { s->failed_pc=0x0c04626au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+2,1);
goto P_0c04626c;
P_0c04626c: /* original 2448, guest PC 0x0c04626c */
if(!s->budget--) { s->failed_pc=0x0c04626cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c04626e;
P_0c04626e: /* original 8d04, guest PC 0x0c04626e */
if(!s->budget--) { s->failed_pc=0x0c04626eu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[0],4);
if(cond) { goto P_0c04627a; }
goto P_0c046272;
P_0c046270: /* original 2f02, guest PC 0x0c046270 */
if(!s->budget--) { s->failed_pc=0x0c046270u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c046272;
P_0c046272: /* original d30e, guest PC 0x0c046272 */
if(!s->budget--) { s->failed_pc=0x0c046272u; return 0; }
r[3]=read(ram,0x0c0462acu,4);
goto P_0c046274;
P_0c046274: /* original 6232, guest PC 0x0c046274 */
if(!s->budget--) { s->failed_pc=0x0c046274u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c046276;
P_0c046276: /* original 224b, guest PC 0x0c046276 */
if(!s->budget--) { s->failed_pc=0x0c046276u; return 0; }
r[2]|=r[4];
goto P_0c046278;
P_0c046278: /* original 2322, guest PC 0x0c046278 */
if(!s->budget--) { s->failed_pc=0x0c046278u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c04627a;
P_0c04627a: /* original 55f1, guest PC 0x0c04627a */
if(!s->budget--) { s->failed_pc=0x0c04627au; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c04627c;
P_0c04627c: /* original 56f3, guest PC 0x0c04627c */
if(!s->budget--) { s->failed_pc=0x0c04627cu; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c04627e;
P_0c04627e: /* original 57f2, guest PC 0x0c04627e */
if(!s->budget--) { s->failed_pc=0x0c04627eu; return 0; }
r[7]=read(ram,r[15]+8,4);
goto P_0c046280;
P_0c046280: /* original be8d, guest PC 0x0c046280 */
if(!s->budget--) { s->failed_pc=0x0c046280u; return 0; }
target=code_base|0x0c045f9eu; r[16]=code_base|0x0c046284u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c046284u) { target=s->pc; goto dispatch; }
goto P_0c046284;
P_0c046282: /* original 64f2, guest PC 0x0c046282 */
if(!s->budget--) { s->failed_pc=0x0c046282u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c046284;
P_0c046284: /* original 6403, guest PC 0x0c046284 */
if(!s->budget--) { s->failed_pc=0x0c046284u; return 0; }
r[4]=r[0];
goto P_0c046286;
P_0c046286: /* original 50f4, guest PC 0x0c046286 */
if(!s->budget--) { s->failed_pc=0x0c046286u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c046288;
P_0c046288: /* original 0202, guest PC 0x0c046288 */
if(!s->budget--) { s->failed_pc=0x0c046288u; return 0; }
r[2]=r[17];
goto P_0c04628a;
P_0c04628a: /* original 930c, guest PC 0x0c04628a */
if(!s->budget--) { s->failed_pc=0x0c04628au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0462a6u,2);
goto P_0c04628c;
P_0c04628c: /* original c90f, guest PC 0x0c04628c */
if(!s->budget--) { s->failed_pc=0x0c04628cu; return 0; }
r[0]&=15u;
goto P_0c04628e;
P_0c04628e: /* original 4008, guest PC 0x0c04628e */
if(!s->budget--) { s->failed_pc=0x0c04628eu; return 0; }
r[0]<<=2;
goto P_0c046290;
P_0c046290: /* original 2239, guest PC 0x0c046290 */
if(!s->budget--) { s->failed_pc=0x0c046290u; return 0; }
r[2]&=r[3];
goto P_0c046292;
P_0c046292: /* original 4008, guest PC 0x0c046292 */
if(!s->budget--) { s->failed_pc=0x0c046292u; return 0; }
r[0]<<=2;
goto P_0c046294;
P_0c046294: /* original 202b, guest PC 0x0c046294 */
if(!s->budget--) { s->failed_pc=0x0c046294u; return 0; }
r[0]|=r[2];
goto P_0c046296;
P_0c046296: /* original 400e, guest PC 0x0c046296 */
if(!s->budget--) { s->failed_pc=0x0c046296u; return 0; }
r[17]=r[0];
goto P_0c046298;
P_0c046298: /* original 6043, guest PC 0x0c046298 */
if(!s->budget--) { s->failed_pc=0x0c046298u; return 0; }
r[0]=r[4];
goto P_0c04629a;
P_0c04629a: /* original 7f14, guest PC 0x0c04629a */
if(!s->budget--) { s->failed_pc=0x0c04629au; return 0; }
r[15]+=0x00000014u;
goto P_0c04629c;
P_0c04629c: /* original 4f26, guest PC 0x0c04629c */
if(!s->budget--) { s->failed_pc=0x0c04629cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04629e;
P_0c04629e: /* original 000b, guest PC 0x0c04629e */
if(!s->budget--) { s->failed_pc=0x0c04629eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0462a0: /* original 6ef6, guest PC 0x0c0462a0 */
if(!s->budget--) { s->failed_pc=0x0c0462a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0462a2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0462a2u; return 0; } return 1;
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
P_0c059400: /* original 6053, guest PC 0x0c059400 */
if(!s->budget--) { s->failed_pc=0x0c059400u; return 0; }
r[0]=r[5];
goto P_0c059402;
P_0c059402: /* original 0009, guest PC 0x0c059402 */
if(!s->budget--) { s->failed_pc=0x0c059402u; return 0; }
goto P_0c059404;
P_0c059404: /* original 8800, guest PC 0x0c059404 */
if(!s->budget--) { s->failed_pc=0x0c059404u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c059406;
P_0c059406: /* original 8911, guest PC 0x0c059406 */
if(!s->budget--) { s->failed_pc=0x0c059406u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05942c; }
goto P_0c059408;
P_0c059408: /* original 8801, guest PC 0x0c059408 */
if(!s->budget--) { s->failed_pc=0x0c059408u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05940a;
P_0c05940a: /* original 8913, guest PC 0x0c05940a */
if(!s->budget--) { s->failed_pc=0x0c05940au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059434; }
goto P_0c05940c;
P_0c05940c: /* original 8802, guest PC 0x0c05940c */
if(!s->budget--) { s->failed_pc=0x0c05940cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c05940e;
P_0c05940e: /* original 8915, guest PC 0x0c05940e */
if(!s->budget--) { s->failed_pc=0x0c05940eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05943c; }
goto P_0c059410;
P_0c059410: /* original 8803, guest PC 0x0c059410 */
if(!s->budget--) { s->failed_pc=0x0c059410u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c059412;
P_0c059412: /* original 8917, guest PC 0x0c059412 */
if(!s->budget--) { s->failed_pc=0x0c059412u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059444; }
goto P_0c059414;
P_0c059414: /* original 8804, guest PC 0x0c059414 */
if(!s->budget--) { s->failed_pc=0x0c059414u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c059416;
P_0c059416: /* original 8919, guest PC 0x0c059416 */
if(!s->budget--) { s->failed_pc=0x0c059416u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05944c; }
goto P_0c059418;
P_0c059418: /* original 8805, guest PC 0x0c059418 */
if(!s->budget--) { s->failed_pc=0x0c059418u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c05941a;
P_0c05941a: /* original 891b, guest PC 0x0c05941a */
if(!s->budget--) { s->failed_pc=0x0c05941au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059454; }
goto P_0c05941c;
P_0c05941c: /* original 8806, guest PC 0x0c05941c */
if(!s->budget--) { s->failed_pc=0x0c05941cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c05941e;
P_0c05941e: /* original 891d, guest PC 0x0c05941e */
if(!s->budget--) { s->failed_pc=0x0c05941eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05945c; }
goto P_0c059420;
P_0c059420: /* original 8807, guest PC 0x0c059420 */
if(!s->budget--) { s->failed_pc=0x0c059420u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c059422;
P_0c059422: /* original 891f, guest PC 0x0c059422 */
if(!s->budget--) { s->failed_pc=0x0c059422u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059464; }
goto P_0c059424;
P_0c059424: /* original 8808, guest PC 0x0c059424 */
if(!s->budget--) { s->failed_pc=0x0c059424u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c059426;
P_0c059426: /* original 8921, guest PC 0x0c059426 */
if(!s->budget--) { s->failed_pc=0x0c059426u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05946c; }
goto P_0c059428;
P_0c059428: /* original a023, guest PC 0x0c059428 */
if(!s->budget--) { s->failed_pc=0x0c059428u; return 0; }
goto P_0c059472;
P_0c05942a: /* original 0009, guest PC 0x0c05942a */
if(!s->budget--) { s->failed_pc=0x0c05942au; return 0; }
goto P_0c05942c;
P_0c05942c: /* original d318, guest PC 0x0c05942c */
if(!s->budget--) { s->failed_pc=0x0c05942cu; return 0; }
r[3]=read(ram,0x0c059490u,4);
goto P_0c05942e;
P_0c05942e: /* original 9022, guest PC 0x0c05942e */
if(!s->budget--) { s->failed_pc=0x0c05942eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059476u,2);
goto P_0c059430;
P_0c059430: /* original a01f, guest PC 0x0c059430 */
if(!s->budget--) { s->failed_pc=0x0c059430u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c059472;
P_0c059432: /* original 0436, guest PC 0x0c059432 */
if(!s->budget--) { s->failed_pc=0x0c059432u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c059434;
P_0c059434: /* original d117, guest PC 0x0c059434 */
if(!s->budget--) { s->failed_pc=0x0c059434u; return 0; }
r[1]=read(ram,0x0c059494u,4);
goto P_0c059436;
P_0c059436: /* original 901f, guest PC 0x0c059436 */
if(!s->budget--) { s->failed_pc=0x0c059436u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059478u,2);
goto P_0c059438;
P_0c059438: /* original a016, guest PC 0x0c059438 */
if(!s->budget--) { s->failed_pc=0x0c059438u; return 0; }
goto P_0c059468;
P_0c05943a: /* original 0009, guest PC 0x0c05943a */
if(!s->budget--) { s->failed_pc=0x0c05943au; return 0; }
goto P_0c05943c;
P_0c05943c: /* original d216, guest PC 0x0c05943c */
if(!s->budget--) { s->failed_pc=0x0c05943cu; return 0; }
r[2]=read(ram,0x0c059498u,4);
goto P_0c05943e;
P_0c05943e: /* original 901c, guest PC 0x0c05943e */
if(!s->budget--) { s->failed_pc=0x0c05943eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05947au,2);
goto P_0c059440;
P_0c059440: /* original a016, guest PC 0x0c059440 */
if(!s->budget--) { s->failed_pc=0x0c059440u; return 0; }
goto P_0c059470;
P_0c059442: /* original 0009, guest PC 0x0c059442 */
if(!s->budget--) { s->failed_pc=0x0c059442u; return 0; }
goto P_0c059444;
P_0c059444: /* original d115, guest PC 0x0c059444 */
if(!s->budget--) { s->failed_pc=0x0c059444u; return 0; }
r[1]=read(ram,0x0c05949cu,4);
goto P_0c059446;
P_0c059446: /* original 9019, guest PC 0x0c059446 */
if(!s->budget--) { s->failed_pc=0x0c059446u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05947cu,2);
goto P_0c059448;
P_0c059448: /* original a00e, guest PC 0x0c059448 */
if(!s->budget--) { s->failed_pc=0x0c059448u; return 0; }
goto P_0c059468;
P_0c05944a: /* original 0009, guest PC 0x0c05944a */
if(!s->budget--) { s->failed_pc=0x0c05944au; return 0; }
goto P_0c05944c;
P_0c05944c: /* original d214, guest PC 0x0c05944c */
if(!s->budget--) { s->failed_pc=0x0c05944cu; return 0; }
r[2]=read(ram,0x0c0594a0u,4);
goto P_0c05944e;
P_0c05944e: /* original 9016, guest PC 0x0c05944e */
if(!s->budget--) { s->failed_pc=0x0c05944eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05947eu,2);
goto P_0c059450;
P_0c059450: /* original a00e, guest PC 0x0c059450 */
if(!s->budget--) { s->failed_pc=0x0c059450u; return 0; }
goto P_0c059470;
P_0c059452: /* original 0009, guest PC 0x0c059452 */
if(!s->budget--) { s->failed_pc=0x0c059452u; return 0; }
goto P_0c059454;
P_0c059454: /* original d113, guest PC 0x0c059454 */
if(!s->budget--) { s->failed_pc=0x0c059454u; return 0; }
r[1]=read(ram,0x0c0594a4u,4);
goto P_0c059456;
P_0c059456: /* original 9013, guest PC 0x0c059456 */
if(!s->budget--) { s->failed_pc=0x0c059456u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059480u,2);
goto P_0c059458;
P_0c059458: /* original a006, guest PC 0x0c059458 */
if(!s->budget--) { s->failed_pc=0x0c059458u; return 0; }
goto P_0c059468;
P_0c05945a: /* original 0009, guest PC 0x0c05945a */
if(!s->budget--) { s->failed_pc=0x0c05945au; return 0; }
goto P_0c05945c;
P_0c05945c: /* original d212, guest PC 0x0c05945c */
if(!s->budget--) { s->failed_pc=0x0c05945cu; return 0; }
r[2]=read(ram,0x0c0594a8u,4);
goto P_0c05945e;
P_0c05945e: /* original 9010, guest PC 0x0c05945e */
if(!s->budget--) { s->failed_pc=0x0c05945eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059482u,2);
goto P_0c059460;
P_0c059460: /* original a006, guest PC 0x0c059460 */
if(!s->budget--) { s->failed_pc=0x0c059460u; return 0; }
goto P_0c059470;
P_0c059462: /* original 0009, guest PC 0x0c059462 */
if(!s->budget--) { s->failed_pc=0x0c059462u; return 0; }
goto P_0c059464;
P_0c059464: /* original d111, guest PC 0x0c059464 */
if(!s->budget--) { s->failed_pc=0x0c059464u; return 0; }
r[1]=read(ram,0x0c0594acu,4);
goto P_0c059466;
P_0c059466: /* original 900d, guest PC 0x0c059466 */
if(!s->budget--) { s->failed_pc=0x0c059466u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059484u,2);
goto P_0c059468;
P_0c059468: /* original a003, guest PC 0x0c059468 */
if(!s->budget--) { s->failed_pc=0x0c059468u; return 0; }
write(ram,r[4]+r[0],r[1],4);
goto P_0c059472;
P_0c05946a: /* original 0416, guest PC 0x0c05946a */
if(!s->budget--) { s->failed_pc=0x0c05946au; return 0; }
write(ram,r[4]+r[0],r[1],4);
goto P_0c05946c;
P_0c05946c: /* original d210, guest PC 0x0c05946c */
if(!s->budget--) { s->failed_pc=0x0c05946cu; return 0; }
r[2]=read(ram,0x0c0594b0u,4);
goto P_0c05946e;
P_0c05946e: /* original 900a, guest PC 0x0c05946e */
if(!s->budget--) { s->failed_pc=0x0c05946eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059486u,2);
goto P_0c059470;
P_0c059470: /* original 0426, guest PC 0x0c059470 */
if(!s->budget--) { s->failed_pc=0x0c059470u; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c059472;
P_0c059472: /* original 000b, guest PC 0x0c059472 */
if(!s->budget--) { s->failed_pc=0x0c059472u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c059474: /* original 0009, guest PC 0x0c059474 */
if(!s->budget--) { s->failed_pc=0x0c059474u; return 0; }
if(!vf3_matrix_family(0x0c059476u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c059476u; return 0; } return 1;
P_0c0594b4: /* original 4f22, guest PC 0x0c0594b4 */
if(!s->budget--) { s->failed_pc=0x0c0594b4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0594b6;
P_0c0594b6: /* original 0002, guest PC 0x0c0594b6 */
if(!s->budget--) { s->failed_pc=0x0c0594b6u; return 0; }
r[0]=r[17];
goto P_0c0594b8;
P_0c0594b8: /* original 9372, guest PC 0x0c0594b8 */
if(!s->budget--) { s->failed_pc=0x0c0594b8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0595a0u,2);
goto P_0c0594ba;
P_0c0594ba: /* original 7ff8, guest PC 0x0c0594ba */
if(!s->budget--) { s->failed_pc=0x0c0594bau; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0594bc;
P_0c0594bc: /* original 4009, guest PC 0x0c0594bc */
if(!s->budget--) { s->failed_pc=0x0c0594bcu; return 0; }
r[0]>>=2;
goto P_0c0594be;
P_0c0594be: /* original 4009, guest PC 0x0c0594be */
if(!s->budget--) { s->failed_pc=0x0c0594beu; return 0; }
r[0]>>=2;
goto P_0c0594c0;
P_0c0594c0: /* original c90f, guest PC 0x0c0594c0 */
if(!s->budget--) { s->failed_pc=0x0c0594c0u; return 0; }
r[0]&=15u;
goto P_0c0594c2;
P_0c0594c2: /* original 2f02, guest PC 0x0c0594c2 */
if(!s->budget--) { s->failed_pc=0x0c0594c2u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0594c4;
P_0c0594c4: /* original 0002, guest PC 0x0c0594c4 */
if(!s->budget--) { s->failed_pc=0x0c0594c4u; return 0; }
r[0]=r[17];
goto P_0c0594c6;
P_0c0594c6: /* original 2039, guest PC 0x0c0594c6 */
if(!s->budget--) { s->failed_pc=0x0c0594c6u; return 0; }
r[0]&=r[3];
goto P_0c0594c8;
P_0c0594c8: /* original cbf0, guest PC 0x0c0594c8 */
if(!s->budget--) { s->failed_pc=0x0c0594c8u; return 0; }
r[0]|=240u;
goto P_0c0594ca;
P_0c0594ca: /* original 400e, guest PC 0x0c0594ca */
if(!s->budget--) { s->failed_pc=0x0c0594cau; return 0; }
r[17]=r[0];
goto P_0c0594cc;
P_0c0594cc: /* original 2668, guest PC 0x0c0594cc */
if(!s->budget--) { s->failed_pc=0x0c0594ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0594ce;
P_0c0594ce: /* original 890c, guest PC 0x0c0594ce */
if(!s->budget--) { s->failed_pc=0x0c0594ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0594ea; }
goto P_0c0594d0;
P_0c0594d0: /* original 9367, guest PC 0x0c0594d0 */
if(!s->budget--) { s->failed_pc=0x0c0594d0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0595a2u,2);
goto P_0c0594d2;
P_0c0594d2: /* original 4508, guest PC 0x0c0594d2 */
if(!s->budget--) { s->failed_pc=0x0c0594d2u; return 0; }
r[5]<<=2;
goto P_0c0594d4;
P_0c0594d4: /* original 9265, guest PC 0x0c0594d4 */
if(!s->budget--) { s->failed_pc=0x0c0594d4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0595a2u,2);
goto P_0c0594d6;
P_0c0594d6: /* original 334c, guest PC 0x0c0594d6 */
if(!s->budget--) { s->failed_pc=0x0c0594d6u; return 0; }
r[3]+=r[4];
goto P_0c0594d8;
P_0c0594d8: /* original 4500, guest PC 0x0c0594d8 */
if(!s->budget--) { s->failed_pc=0x0c0594d8u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0594da;
P_0c0594da: /* original 324c, guest PC 0x0c0594da */
if(!s->budget--) { s->failed_pc=0x0c0594dau; return 0; }
r[2]+=r[4];
goto P_0c0594dc;
P_0c0594dc: /* original 1f51, guest PC 0x0c0594dc */
if(!s->budget--) { s->failed_pc=0x0c0594dcu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0594de;
P_0c0594de: /* original 353c, guest PC 0x0c0594de */
if(!s->budget--) { s->failed_pc=0x0c0594deu; return 0; }
r[5]+=r[3];
goto P_0c0594e0;
P_0c0594e0: /* original 2562, guest PC 0x0c0594e0 */
if(!s->budget--) { s->failed_pc=0x0c0594e0u; return 0; }
write(ram,r[5],r[6],4);
goto P_0c0594e2;
P_0c0594e2: /* original 53f1, guest PC 0x0c0594e2 */
if(!s->budget--) { s->failed_pc=0x0c0594e2u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0594e4;
P_0c0594e4: /* original 323c, guest PC 0x0c0594e4 */
if(!s->budget--) { s->failed_pc=0x0c0594e4u; return 0; }
r[2]+=r[3];
goto P_0c0594e6;
P_0c0594e6: /* original a002, guest PC 0x0c0594e6 */
if(!s->budget--) { s->failed_pc=0x0c0594e6u; return 0; }
write(ram,r[2]+4,r[7],4);
goto P_0c0594ee;
P_0c0594e8: /* original 1271, guest PC 0x0c0594e8 */
if(!s->budget--) { s->failed_pc=0x0c0594e8u; return 0; }
write(ram,r[2]+4,r[7],4);
goto P_0c0594ea;
P_0c0594ea: /* original bf89, guest PC 0x0c0594ea */
if(!s->budget--) { s->failed_pc=0x0c0594eau; return 0; }
target=code_base|0x0c059400u; r[16]=code_base|0x0c0594eeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0594eeu) { target=s->pc; goto dispatch; }
goto P_0c0594ee;
P_0c0594ec: /* original 0009, guest PC 0x0c0594ec */
if(!s->budget--) { s->failed_pc=0x0c0594ecu; return 0; }
goto P_0c0594ee;
P_0c0594ee: /* original 0302, guest PC 0x0c0594ee */
if(!s->budget--) { s->failed_pc=0x0c0594eeu; return 0; }
r[3]=r[17];
goto P_0c0594f0;
P_0c0594f0: /* original 9256, guest PC 0x0c0594f0 */
if(!s->budget--) { s->failed_pc=0x0c0594f0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0595a0u,2);
goto P_0c0594f2;
P_0c0594f2: /* original 60f2, guest PC 0x0c0594f2 */
if(!s->budget--) { s->failed_pc=0x0c0594f2u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0594f4;
P_0c0594f4: /* original c90f, guest PC 0x0c0594f4 */
if(!s->budget--) { s->failed_pc=0x0c0594f4u; return 0; }
r[0]&=15u;
goto P_0c0594f6;
P_0c0594f6: /* original 4008, guest PC 0x0c0594f6 */
if(!s->budget--) { s->failed_pc=0x0c0594f6u; return 0; }
r[0]<<=2;
goto P_0c0594f8;
P_0c0594f8: /* original 4008, guest PC 0x0c0594f8 */
if(!s->budget--) { s->failed_pc=0x0c0594f8u; return 0; }
r[0]<<=2;
goto P_0c0594fa;
P_0c0594fa: /* original 2329, guest PC 0x0c0594fa */
if(!s->budget--) { s->failed_pc=0x0c0594fau; return 0; }
r[3]&=r[2];
goto P_0c0594fc;
P_0c0594fc: /* original 203b, guest PC 0x0c0594fc */
if(!s->budget--) { s->failed_pc=0x0c0594fcu; return 0; }
r[0]|=r[3];
goto P_0c0594fe;
P_0c0594fe: /* original 400e, guest PC 0x0c0594fe */
if(!s->budget--) { s->failed_pc=0x0c0594feu; return 0; }
r[17]=r[0];
goto P_0c059500;
P_0c059500: /* original 7f08, guest PC 0x0c059500 */
if(!s->budget--) { s->failed_pc=0x0c059500u; return 0; }
r[15]+=0x00000008u;
goto P_0c059502;
P_0c059502: /* original 4f26, guest PC 0x0c059502 */
if(!s->budget--) { s->failed_pc=0x0c059502u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c059504;
P_0c059504: /* original 000b, guest PC 0x0c059504 */
if(!s->budget--) { s->failed_pc=0x0c059504u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c059506: /* original 0009, guest PC 0x0c059506 */
if(!s->budget--) { s->failed_pc=0x0c059506u; return 0; }
if(!vf3_matrix_family(0x0c059508u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c059508u; return 0; } return 1;
P_0c059524: /* original 4f22, guest PC 0x0c059524 */
if(!s->budget--) { s->failed_pc=0x0c059524u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c059526;
P_0c059526: /* original 7ff8, guest PC 0x0c059526 */
if(!s->budget--) { s->failed_pc=0x0c059526u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c059528;
P_0c059528: /* original d31f, guest PC 0x0c059528 */
if(!s->budget--) { s->failed_pc=0x0c059528u; return 0; }
r[3]=read(ram,0x0c0595a8u,4);
goto P_0c05952a;
P_0c05952a: /* original 2f42, guest PC 0x0c05952a */
if(!s->budget--) { s->failed_pc=0x0c05952au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05952c;
P_0c05952c: /* original 1f51, guest PC 0x0c05952c */
if(!s->budget--) { s->failed_pc=0x0c05952cu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c05952e;
P_0c05952e: /* original 430b, guest PC 0x0c05952e */
if(!s->budget--) { s->failed_pc=0x0c05952eu; return 0; }
target=r[3];
r[16]=code_base|0x0c059532u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059532u) { target=s->pc; goto dispatch; }
goto P_0c059532;
P_0c059530: /* original e401, guest PC 0x0c059530 */
if(!s->budget--) { s->failed_pc=0x0c059530u; return 0; }
r[4]=0x00000001u;
goto P_0c059532;
P_0c059532: /* original e501, guest PC 0x0c059532 */
if(!s->budget--) { s->failed_pc=0x0c059532u; return 0; }
r[5]=0x00000001u;
goto P_0c059534;
P_0c059534: /* original d31b, guest PC 0x0c059534 */
if(!s->budget--) { s->failed_pc=0x0c059534u; return 0; }
r[3]=read(ram,0x0c0595a4u,4);
goto P_0c059536;
P_0c059536: /* original 57f1, guest PC 0x0c059536 */
if(!s->budget--) { s->failed_pc=0x0c059536u; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c059538;
P_0c059538: /* original 66f2, guest PC 0x0c059538 */
if(!s->budget--) { s->failed_pc=0x0c059538u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c05953a;
P_0c05953a: /* original bfbb, guest PC 0x0c05953a */
if(!s->budget--) { s->failed_pc=0x0c05953au; return 0; }
target=code_base|0x0c0594b4u; r[16]=code_base|0x0c05953eu;
tmp=read(ram,r[3],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05953eu) { target=s->pc; goto dispatch; }
goto P_0c05953e;
P_0c05953c: /* original 6432, guest PC 0x0c05953c */
if(!s->budget--) { s->failed_pc=0x0c05953cu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c05953e;
P_0c05953e: /* original 7f08, guest PC 0x0c05953e */
if(!s->budget--) { s->failed_pc=0x0c05953eu; return 0; }
r[15]+=0x00000008u;
goto P_0c059540;
P_0c059540: /* original 4f26, guest PC 0x0c059540 */
if(!s->budget--) { s->failed_pc=0x0c059540u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c059542;
P_0c059542: /* original 000b, guest PC 0x0c059542 */
if(!s->budget--) { s->failed_pc=0x0c059542u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c059544: /* original e000, guest PC 0x0c059544 */
if(!s->budget--) { s->failed_pc=0x0c059544u; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c059546u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c059546u; return 0; } return 1;
P_0c060cf2: /* original 000b, guest PC 0x0c060cf2 */
if(!s->budget--) { s->failed_pc=0x0c060cf2u; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c060cf4: /* original e001, guest PC 0x0c060cf4 */
if(!s->budget--) { s->failed_pc=0x0c060cf4u; return 0; }
r[0]=0x00000001u;
if(!vf3_matrix_family(0x0c060cf6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060cf6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
