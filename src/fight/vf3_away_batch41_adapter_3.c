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
int vf3_away_batch41_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a76ecu: goto P_0c0a76ec;
case 0x0c0a76eeu: goto P_0c0a76ee;
case 0x0c0a76f0u: goto P_0c0a76f0;
case 0x0c0a76f2u: goto P_0c0a76f2;
case 0x0c0a76f4u: goto P_0c0a76f4;
case 0x0c0a76f6u: goto P_0c0a76f6;
case 0x0c0a76f8u: goto P_0c0a76f8;
case 0x0c0a76fau: goto P_0c0a76fa;
case 0x0c0a76fcu: goto P_0c0a76fc;
case 0x0c0a76feu: goto P_0c0a76fe;
case 0x0c0a7700u: goto P_0c0a7700;
case 0x0c0a7702u: goto P_0c0a7702;
case 0x0c0a7704u: goto P_0c0a7704;
case 0x0c0a7706u: goto P_0c0a7706;
case 0x0c0a7708u: goto P_0c0a7708;
case 0x0c0a770au: goto P_0c0a770a;
case 0x0c0a770cu: goto P_0c0a770c;
case 0x0c0a770eu: goto P_0c0a770e;
case 0x0c0a7710u: goto P_0c0a7710;
case 0x0c0a7712u: goto P_0c0a7712;
case 0x0c0a7714u: goto P_0c0a7714;
case 0x0c0a7716u: goto P_0c0a7716;
case 0x0c0a7718u: goto P_0c0a7718;
case 0x0c0a771au: goto P_0c0a771a;
case 0x0c0a771cu: goto P_0c0a771c;
case 0x0c0a771eu: goto P_0c0a771e;
case 0x0c0a7720u: goto P_0c0a7720;
case 0x0c0a7722u: goto P_0c0a7722;
case 0x0c0a7724u: goto P_0c0a7724;
case 0x0c0a7726u: goto P_0c0a7726;
case 0x0c0a7728u: goto P_0c0a7728;
case 0x0c0a772au: goto P_0c0a772a;
case 0x0c0a772cu: goto P_0c0a772c;
case 0x0c0a772eu: goto P_0c0a772e;
case 0x0c0a7730u: goto P_0c0a7730;
case 0x0c0a7732u: goto P_0c0a7732;
case 0x0c0a7734u: goto P_0c0a7734;
case 0x0c0a7736u: goto P_0c0a7736;
case 0x0c0a7738u: goto P_0c0a7738;
case 0x0c0a773au: goto P_0c0a773a;
case 0x0c0a773cu: goto P_0c0a773c;
case 0x0c0a773eu: goto P_0c0a773e;
case 0x0c0a7740u: goto P_0c0a7740;
case 0x0c0a7742u: goto P_0c0a7742;
case 0x0c0a7744u: goto P_0c0a7744;
case 0x0c0a7746u: goto P_0c0a7746;
case 0x0c0a7748u: goto P_0c0a7748;
case 0x0c0a774au: goto P_0c0a774a;
case 0x0c0c66b8u: goto P_0c0c66b8;
case 0x0c0c66bau: goto P_0c0c66ba;
case 0x0c0c66d0u: goto P_0c0c66d0;
case 0x0c0c66d2u: goto P_0c0c66d2;
case 0x0c0c6742u: goto P_0c0c6742;
case 0x0c0c6744u: goto P_0c0c6744;
case 0x0c0c6746u: goto P_0c0c6746;
case 0x0c0c6748u: goto P_0c0c6748;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a76ec: /* original 2fe6, guest PC 0x0c0a76ec */
if(!s->budget--) { s->failed_pc=0x0c0a76ecu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a76ee;
P_0c0a76ee: /* original 4f22, guest PC 0x0c0a76ee */
if(!s->budget--) { s->failed_pc=0x0c0a76eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a76f0;
P_0c0a76f0: /* original 7ff8, guest PC 0x0c0a76f0 */
if(!s->budget--) { s->failed_pc=0x0c0a76f0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a76f2;
P_0c0a76f2: /* original 1f41, guest PC 0x0c0a76f2 */
if(!s->budget--) { s->failed_pc=0x0c0a76f2u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0a76f4;
P_0c0a76f4: /* original ff4a, guest PC 0x0c0a76f4 */
if(!s->budget--) { s->failed_pc=0x0c0a76f4u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c0a76f6;
P_0c0a76f6: /* original d34b, guest PC 0x0c0a76f6 */
if(!s->budget--) { s->failed_pc=0x0c0a76f6u; return 0; }
r[3]=read(ram,0x0c0a7824u,4);
goto P_0c0a76f8;
P_0c0a76f8: /* original 430b, guest PC 0x0c0a76f8 */
if(!s->budget--) { s->failed_pc=0x0c0a76f8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a76fcu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a76fcu) { target=s->pc; goto dispatch; }
goto P_0c0a76fc;
P_0c0a76fa: /* original e400, guest PC 0x0c0a76fa */
if(!s->budget--) { s->failed_pc=0x0c0a76fau; return 0; }
r[4]=0x00000000u;
goto P_0c0a76fc;
P_0c0a76fc: /* original 5ef1, guest PC 0x0c0a76fc */
if(!s->budget--) { s->failed_pc=0x0c0a76fcu; return 0; }
r[14]=read(ram,r[15]+4,4);
goto P_0c0a76fe;
P_0c0a76fe: /* original e301, guest PC 0x0c0a76fe */
if(!s->budget--) { s->failed_pc=0x0c0a76feu; return 0; }
r[3]=0x00000001u;
goto P_0c0a7700;
P_0c0a7700: /* original 5ee1, guest PC 0x0c0a7700 */
if(!s->budget--) { s->failed_pc=0x0c0a7700u; return 0; }
r[14]=read(ram,r[14]+4,4);
goto P_0c0a7702;
P_0c0a7702: /* original 23e8, guest PC 0x0c0a7702 */
if(!s->budget--) { s->failed_pc=0x0c0a7702u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c0a7704;
P_0c0a7704: /* original 8b1e, guest PC 0x0c0a7704 */
if(!s->budget--) { s->failed_pc=0x0c0a7704u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7744; }
goto P_0c0a7706;
P_0c0a7706: /* original 2ee8, guest PC 0x0c0a7706 */
if(!s->budget--) { s->failed_pc=0x0c0a7706u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a7708;
P_0c0a7708: /* original 8916, guest PC 0x0c0a7708 */
if(!s->budget--) { s->failed_pc=0x0c0a7708u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7738; }
goto P_0c0a770a;
P_0c0a770a: /* original d348, guest PC 0x0c0a770a */
if(!s->budget--) { s->failed_pc=0x0c0a770au; return 0; }
r[3]=read(ram,0x0c0a782cu,4);
goto P_0c0a770c;
P_0c0a770c: /* original d446, guest PC 0x0c0a770c */
if(!s->budget--) { s->failed_pc=0x0c0a770cu; return 0; }
r[4]=read(ram,0x0c0a7828u,4);
goto P_0c0a770e;
P_0c0a770e: /* original 430b, guest PC 0x0c0a770e */
if(!s->budget--) { s->failed_pc=0x0c0a770eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7712u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7712u) { target=s->pc; goto dispatch; }
goto P_0c0a7712;
P_0c0a7710: /* original 0009, guest PC 0x0c0a7710 */
if(!s->budget--) { s->failed_pc=0x0c0a7710u; return 0; }
goto P_0c0a7712;
P_0c0a7712: /* original d247, guest PC 0x0c0a7712 */
if(!s->budget--) { s->failed_pc=0x0c0a7712u; return 0; }
r[2]=read(ram,0x0c0a7830u,4);
goto P_0c0a7714;
P_0c0a7714: /* original 420b, guest PC 0x0c0a7714 */
if(!s->budget--) { s->failed_pc=0x0c0a7714u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7718u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7718u) { target=s->pc; goto dispatch; }
goto P_0c0a7718;
P_0c0a7716: /* original 0009, guest PC 0x0c0a7716 */
if(!s->budget--) { s->failed_pc=0x0c0a7716u; return 0; }
goto P_0c0a7718;
P_0c0a7718: /* original f2f8, guest PC 0x0c0a7718 */
if(!s->budget--) { s->failed_pc=0x0c0a7718u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0a771a;
P_0c0a771a: /* original f39d, guest PC 0x0c0a771a */
if(!s->budget--) { s->failed_pc=0x0c0a771au; return 0; }
fr[3]=0x3f800000u;
goto P_0c0a771c;
P_0c0a771c: /* original f325, guest PC 0x0c0a771c */
if(!s->budget--) { s->failed_pc=0x0c0a771cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0a771e;
P_0c0a771e: /* original 8907, guest PC 0x0c0a771e */
if(!s->budget--) { s->failed_pc=0x0c0a771eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7730; }
goto P_0c0a7720;
P_0c0a7720: /* original d244, guest PC 0x0c0a7720 */
if(!s->budget--) { s->failed_pc=0x0c0a7720u; return 0; }
r[2]=read(ram,0x0c0a7834u,4);
goto P_0c0a7722;
P_0c0a7722: /* original 22e8, guest PC 0x0c0a7722 */
if(!s->budget--) { s->failed_pc=0x0c0a7722u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c0a7724;
P_0c0a7724: /* original 8908, guest PC 0x0c0a7724 */
if(!s->budget--) { s->failed_pc=0x0c0a7724u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7738; }
goto P_0c0a7726;
P_0c0a7726: /* original d244, guest PC 0x0c0a7726 */
if(!s->budget--) { s->failed_pc=0x0c0a7726u; return 0; }
r[2]=read(ram,0x0c0a7838u,4);
goto P_0c0a7728;
P_0c0a7728: /* original 420b, guest PC 0x0c0a7728 */
if(!s->budget--) { s->failed_pc=0x0c0a7728u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a772cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a772cu) { target=s->pc; goto dispatch; }
goto P_0c0a772c;
P_0c0a772a: /* original 64e3, guest PC 0x0c0a772a */
if(!s->budget--) { s->failed_pc=0x0c0a772au; return 0; }
r[4]=r[14];
goto P_0c0a772c;
P_0c0a772c: /* original a004, guest PC 0x0c0a772c */
if(!s->budget--) { s->failed_pc=0x0c0a772cu; return 0; }
goto P_0c0a7738;
P_0c0a772e: /* original 0009, guest PC 0x0c0a772e */
if(!s->budget--) { s->failed_pc=0x0c0a772eu; return 0; }
goto P_0c0a7730;
P_0c0a7730: /* original d342, guest PC 0x0c0a7730 */
if(!s->budget--) { s->failed_pc=0x0c0a7730u; return 0; }
r[3]=read(ram,0x0c0a783cu,4);
goto P_0c0a7732;
P_0c0a7732: /* original f42c, guest PC 0x0c0a7732 */
if(!s->budget--) { s->failed_pc=0x0c0a7732u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c0a7734;
P_0c0a7734: /* original 430b, guest PC 0x0c0a7734 */
if(!s->budget--) { s->failed_pc=0x0c0a7734u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7738u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7738u) { target=s->pc; goto dispatch; }
goto P_0c0a7738;
P_0c0a7736: /* original 64e3, guest PC 0x0c0a7736 */
if(!s->budget--) { s->failed_pc=0x0c0a7736u; return 0; }
r[4]=r[14];
goto P_0c0a7738;
P_0c0a7738: /* original 7f08, guest PC 0x0c0a7738 */
if(!s->budget--) { s->failed_pc=0x0c0a7738u; return 0; }
r[15]+=0x00000008u;
goto P_0c0a773a;
P_0c0a773a: /* original d241, guest PC 0x0c0a773a */
if(!s->budget--) { s->failed_pc=0x0c0a773au; return 0; }
r[2]=read(ram,0x0c0a7840u,4);
goto P_0c0a773c;
P_0c0a773c: /* original 4f26, guest PC 0x0c0a773c */
if(!s->budget--) { s->failed_pc=0x0c0a773cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a773e;
P_0c0a773e: /* original e401, guest PC 0x0c0a773e */
if(!s->budget--) { s->failed_pc=0x0c0a773eu; return 0; }
r[4]=0x00000001u;
goto P_0c0a7740;
P_0c0a7740: /* original 422b, guest PC 0x0c0a7740 */
if(!s->budget--) { s->failed_pc=0x0c0a7740u; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c0a7742: /* original 6ef6, guest PC 0x0c0a7742 */
if(!s->budget--) { s->failed_pc=0x0c0a7742u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a7744;
P_0c0a7744: /* original 7f08, guest PC 0x0c0a7744 */
if(!s->budget--) { s->failed_pc=0x0c0a7744u; return 0; }
r[15]+=0x00000008u;
goto P_0c0a7746;
P_0c0a7746: /* original 4f26, guest PC 0x0c0a7746 */
if(!s->budget--) { s->failed_pc=0x0c0a7746u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7748;
P_0c0a7748: /* original 000b, guest PC 0x0c0a7748 */
if(!s->budget--) { s->failed_pc=0x0c0a7748u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a774a: /* original 6ef6, guest PC 0x0c0a774a */
if(!s->budget--) { s->failed_pc=0x0c0a774au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a774cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a774cu; return 0; } return 1;
P_0c0c66b8: /* original 000b, guest PC 0x0c0c66b8 */
if(!s->budget--) { s->failed_pc=0x0c0c66b8u; return 0; }
target=r[16];
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c66ba: /* original 6040, guest PC 0x0c0c66ba */
if(!s->budget--) { s->failed_pc=0x0c0c66bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
if(!vf3_matrix_family(0x0c0c66bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66bcu; return 0; } return 1;
P_0c0c66d0: /* original 000b, guest PC 0x0c0c66d0 */
if(!s->budget--) { s->failed_pc=0x0c0c66d0u; return 0; }
target=r[16];
write(ram,r[4],r[5],1);
s->pc=target; return ram->oob==0;
P_0c0c66d2: /* original 2450, guest PC 0x0c0c66d2 */
if(!s->budget--) { s->failed_pc=0x0c0c66d2u; return 0; }
write(ram,r[4],r[5],1);
if(!vf3_matrix_family(0x0c0c66d4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66d4u; return 0; } return 1;
P_0c0c6742: /* original 9049, guest PC 0x0c0c6742 */
if(!s->budget--) { s->failed_pc=0x0c0c6742u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c67d8u,2);
goto P_0c0c6744;
P_0c0c6744: /* original d426, guest PC 0x0c0c6744 */
if(!s->budget--) { s->failed_pc=0x0c0c6744u; return 0; }
r[4]=read(ram,0x0c0c67e0u,4);
goto P_0c0c6746;
P_0c0c6746: /* original 000b, guest PC 0x0c0c6746 */
if(!s->budget--) { s->failed_pc=0x0c0c6746u; return 0; }
target=r[16];
r[0]=read(ram,r[4]+r[0],4);
s->pc=target; return ram->oob==0;
P_0c0c6748: /* original 004e, guest PC 0x0c0c6748 */
if(!s->budget--) { s->failed_pc=0x0c0c6748u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
if(!vf3_matrix_family(0x0c0c674au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c674au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
