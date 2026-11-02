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
int vf3_away_batch248_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c7104u: goto P_0c0c7104;
case 0x0c0c7106u: goto P_0c0c7106;
case 0x0c0c7108u: goto P_0c0c7108;
case 0x0c0c710au: goto P_0c0c710a;
case 0x0c0c710cu: goto P_0c0c710c;
case 0x0c0c710eu: goto P_0c0c710e;
case 0x0c0c7110u: goto P_0c0c7110;
case 0x0c0c7112u: goto P_0c0c7112;
case 0x0c0c7114u: goto P_0c0c7114;
case 0x0c0c7116u: goto P_0c0c7116;
case 0x0c0c7118u: goto P_0c0c7118;
case 0x0c0c711au: goto P_0c0c711a;
case 0x0c0c711cu: goto P_0c0c711c;
case 0x0c0c711eu: goto P_0c0c711e;
case 0x0c0c7120u: goto P_0c0c7120;
case 0x0c0c7122u: goto P_0c0c7122;
case 0x0c0c7124u: goto P_0c0c7124;
case 0x0c0c7126u: goto P_0c0c7126;
case 0x0c0c7128u: goto P_0c0c7128;
case 0x0c0c712au: goto P_0c0c712a;
case 0x0c0c712cu: goto P_0c0c712c;
case 0x0c0c712eu: goto P_0c0c712e;
case 0x0c0c7130u: goto P_0c0c7130;
case 0x0c0c7132u: goto P_0c0c7132;
case 0x0c0c7134u: goto P_0c0c7134;
case 0x0c0c7136u: goto P_0c0c7136;
case 0x0c0c7138u: goto P_0c0c7138;
case 0x0c0c713au: goto P_0c0c713a;
case 0x0c0c713cu: goto P_0c0c713c;
case 0x0c0c713eu: goto P_0c0c713e;
case 0x0c0c7140u: goto P_0c0c7140;
case 0x0c0c7142u: goto P_0c0c7142;
case 0x0c0c7144u: goto P_0c0c7144;
case 0x0c0c7146u: goto P_0c0c7146;
case 0x0c0c7148u: goto P_0c0c7148;
case 0x0c0c714au: goto P_0c0c714a;
case 0x0c0c714cu: goto P_0c0c714c;
case 0x0c0c714eu: goto P_0c0c714e;
case 0x0c0c7150u: goto P_0c0c7150;
case 0x0c0c7152u: goto P_0c0c7152;
case 0x0c0c7154u: goto P_0c0c7154;
case 0x0c0c7156u: goto P_0c0c7156;
case 0x0c0c7158u: goto P_0c0c7158;
case 0x0c0c715au: goto P_0c0c715a;
case 0x0c0c715cu: goto P_0c0c715c;
case 0x0c0c715eu: goto P_0c0c715e;
case 0x0c0c7160u: goto P_0c0c7160;
case 0x0c0c7162u: goto P_0c0c7162;
case 0x0c0c7164u: goto P_0c0c7164;
case 0x0c0c7166u: goto P_0c0c7166;
case 0x0c0c7168u: goto P_0c0c7168;
case 0x0c0c716au: goto P_0c0c716a;
case 0x0c0c716cu: goto P_0c0c716c;
case 0x0c0c716eu: goto P_0c0c716e;
case 0x0c0c7170u: goto P_0c0c7170;
case 0x0c0c7172u: goto P_0c0c7172;
case 0x0c0c7174u: goto P_0c0c7174;
case 0x0c0c7176u: goto P_0c0c7176;
case 0x0c0c7178u: goto P_0c0c7178;
case 0x0c0c717au: goto P_0c0c717a;
case 0x0c0c717cu: goto P_0c0c717c;
case 0x0c0c717eu: goto P_0c0c717e;
case 0x0c0c7180u: goto P_0c0c7180;
case 0x0c0c7182u: goto P_0c0c7182;
case 0x0c0c7184u: goto P_0c0c7184;
case 0x0c0c7186u: goto P_0c0c7186;
case 0x0c0c7188u: goto P_0c0c7188;
case 0x0c0c718au: goto P_0c0c718a;
case 0x0c0c718cu: goto P_0c0c718c;
case 0x0c0c718eu: goto P_0c0c718e;
case 0x0c0c7190u: goto P_0c0c7190;
case 0x0c0c7192u: goto P_0c0c7192;
case 0x0c0c7194u: goto P_0c0c7194;
case 0x0c0c7196u: goto P_0c0c7196;
case 0x0c0c7198u: goto P_0c0c7198;
case 0x0c0c719au: goto P_0c0c719a;
case 0x0c0c719cu: goto P_0c0c719c;
case 0x0c0c719eu: goto P_0c0c719e;
case 0x0c0c71a0u: goto P_0c0c71a0;
case 0x0c0c71a2u: goto P_0c0c71a2;
case 0x0c0c71a4u: goto P_0c0c71a4;
case 0x0c0c71a6u: goto P_0c0c71a6;
case 0x0c0c71a8u: goto P_0c0c71a8;
case 0x0c0c71aau: goto P_0c0c71aa;
case 0x0c0c71acu: goto P_0c0c71ac;
case 0x0c0c71aeu: goto P_0c0c71ae;
case 0x0c0c71b0u: goto P_0c0c71b0;
case 0x0c0c71b2u: goto P_0c0c71b2;
case 0x0c0c71b4u: goto P_0c0c71b4;
case 0x0c0c71b6u: goto P_0c0c71b6;
case 0x0c0c71b8u: goto P_0c0c71b8;
case 0x0c0c71bau: goto P_0c0c71ba;
case 0x0c0c71bcu: goto P_0c0c71bc;
case 0x0c0c71beu: goto P_0c0c71be;
case 0x0c0c71c0u: goto P_0c0c71c0;
case 0x0c0c71c2u: goto P_0c0c71c2;
case 0x0c0c71c4u: goto P_0c0c71c4;
case 0x0c0c71c6u: goto P_0c0c71c6;
case 0x0c0c71c8u: goto P_0c0c71c8;
case 0x0c0c71cau: goto P_0c0c71ca;
case 0x0c0c71ccu: goto P_0c0c71cc;
case 0x0c0c71ceu: goto P_0c0c71ce;
case 0x0c0c71d0u: goto P_0c0c71d0;
case 0x0c0c71d2u: goto P_0c0c71d2;
case 0x0c0c71d4u: goto P_0c0c71d4;
case 0x0c0c71d6u: goto P_0c0c71d6;
case 0x0c0c71d8u: goto P_0c0c71d8;
case 0x0c0c71dau: goto P_0c0c71da;
case 0x0c0c71dcu: goto P_0c0c71dc;
case 0x0c0c71deu: goto P_0c0c71de;
case 0x0c0c71e0u: goto P_0c0c71e0;
case 0x0c0c71e2u: goto P_0c0c71e2;
case 0x0c0c71e4u: goto P_0c0c71e4;
case 0x0c0c71e6u: goto P_0c0c71e6;
case 0x0c0c71e8u: goto P_0c0c71e8;
case 0x0c0c71eau: goto P_0c0c71ea;
case 0x0c0c71ecu: goto P_0c0c71ec;
case 0x0c0c721cu: goto P_0c0c721c;
case 0x0c0c721eu: goto P_0c0c721e;
case 0x0c0c7220u: goto P_0c0c7220;
case 0x0c0c7222u: goto P_0c0c7222;
case 0x0c0c7224u: goto P_0c0c7224;
case 0x0c0c7226u: goto P_0c0c7226;
case 0x0c0c7228u: goto P_0c0c7228;
case 0x0c0c722au: goto P_0c0c722a;
case 0x0c0c722cu: goto P_0c0c722c;
case 0x0c0c722eu: goto P_0c0c722e;
case 0x0c0c7230u: goto P_0c0c7230;
case 0x0c0c7232u: goto P_0c0c7232;
case 0x0c0c7234u: goto P_0c0c7234;
case 0x0c0c7236u: goto P_0c0c7236;
case 0x0c0c7238u: goto P_0c0c7238;
case 0x0c0c723au: goto P_0c0c723a;
case 0x0c0c723cu: goto P_0c0c723c;
case 0x0c0c723eu: goto P_0c0c723e;
case 0x0c0c7240u: goto P_0c0c7240;
case 0x0c0c7242u: goto P_0c0c7242;
case 0x0c0c7244u: goto P_0c0c7244;
case 0x0c0c7246u: goto P_0c0c7246;
case 0x0c0c7248u: goto P_0c0c7248;
case 0x0c0c724au: goto P_0c0c724a;
case 0x0c0c724cu: goto P_0c0c724c;
case 0x0c0c724eu: goto P_0c0c724e;
case 0x0c0c7250u: goto P_0c0c7250;
case 0x0c0c7252u: goto P_0c0c7252;
case 0x0c0c7254u: goto P_0c0c7254;
case 0x0c0c7256u: goto P_0c0c7256;
case 0x0c0c7258u: goto P_0c0c7258;
case 0x0c0c725au: goto P_0c0c725a;
case 0x0c0c725cu: goto P_0c0c725c;
case 0x0c0c725eu: goto P_0c0c725e;
case 0x0c0c7260u: goto P_0c0c7260;
case 0x0c0c7262u: goto P_0c0c7262;
case 0x0c0c7264u: goto P_0c0c7264;
case 0x0c0c7266u: goto P_0c0c7266;
case 0x0c0c7268u: goto P_0c0c7268;
case 0x0c0c726au: goto P_0c0c726a;
case 0x0c0c726cu: goto P_0c0c726c;
case 0x0c0c726eu: goto P_0c0c726e;
case 0x0c0c7270u: goto P_0c0c7270;
case 0x0c0c7272u: goto P_0c0c7272;
case 0x0c0c7274u: goto P_0c0c7274;
case 0x0c0c7276u: goto P_0c0c7276;
case 0x0c0c7278u: goto P_0c0c7278;
case 0x0c0c727au: goto P_0c0c727a;
case 0x0c0c727cu: goto P_0c0c727c;
case 0x0c0c727eu: goto P_0c0c727e;
case 0x0c0c7280u: goto P_0c0c7280;
case 0x0c0c7282u: goto P_0c0c7282;
case 0x0c0c7284u: goto P_0c0c7284;
case 0x0c0c7286u: goto P_0c0c7286;
case 0x0c0c7288u: goto P_0c0c7288;
case 0x0c0c728au: goto P_0c0c728a;
case 0x0c0c728cu: goto P_0c0c728c;
case 0x0c0c728eu: goto P_0c0c728e;
case 0x0c0c7290u: goto P_0c0c7290;
case 0x0c0c7292u: goto P_0c0c7292;
case 0x0c0c7294u: goto P_0c0c7294;
case 0x0c0c7296u: goto P_0c0c7296;
case 0x0c0c7298u: goto P_0c0c7298;
case 0x0c0c729au: goto P_0c0c729a;
case 0x0c0c729cu: goto P_0c0c729c;
case 0x0c0c729eu: goto P_0c0c729e;
case 0x0c0c72a0u: goto P_0c0c72a0;
case 0x0c0c72a2u: goto P_0c0c72a2;
case 0x0c0c72a4u: goto P_0c0c72a4;
case 0x0c0c72a6u: goto P_0c0c72a6;
case 0x0c0c72a8u: goto P_0c0c72a8;
case 0x0c0c72aau: goto P_0c0c72aa;
case 0x0c0c72acu: goto P_0c0c72ac;
case 0x0c0c72aeu: goto P_0c0c72ae;
case 0x0c0c72b0u: goto P_0c0c72b0;
case 0x0c0c72b2u: goto P_0c0c72b2;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c7104: /* original 2fe6, guest PC 0x0c0c7104 */
if(!s->budget--) { s->failed_pc=0x0c0c7104u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7106;
P_0c0c7106: /* original 2fd6, guest PC 0x0c0c7106 */
if(!s->budget--) { s->failed_pc=0x0c0c7106u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7108;
P_0c0c7108: /* original 2fc6, guest PC 0x0c0c7108 */
if(!s->budget--) { s->failed_pc=0x0c0c7108u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c710a;
P_0c0c710a: /* original 2fb6, guest PC 0x0c0c710a */
if(!s->budget--) { s->failed_pc=0x0c0c710au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c710c;
P_0c0c710c: /* original 2fa6, guest PC 0x0c0c710c */
if(!s->budget--) { s->failed_pc=0x0c0c710cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c710e;
P_0c0c710e: /* original 2f96, guest PC 0x0c0c710e */
if(!s->budget--) { s->failed_pc=0x0c0c710eu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7110;
P_0c0c7110: /* original e90f, guest PC 0x0c0c7110 */
if(!s->budget--) { s->failed_pc=0x0c0c7110u; return 0; }
r[9]=0x0000000fu;
goto P_0c0c7112;
P_0c0c7112: /* original 2f86, guest PC 0x0c0c7112 */
if(!s->budget--) { s->failed_pc=0x0c0c7112u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7114;
P_0c0c7114: /* original 4f22, guest PC 0x0c0c7114 */
if(!s->budget--) { s->failed_pc=0x0c0c7114u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7116;
P_0c0c7116: /* original 906a, guest PC 0x0c0c7116 */
if(!s->budget--) { s->failed_pc=0x0c0c7116u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71eeu,2);
goto P_0c0c7118;
P_0c0c7118: /* original db38, guest PC 0x0c0c7118 */
if(!s->budget--) { s->failed_pc=0x0c0c7118u; return 0; }
r[11]=read(ram,0x0c0c71fcu,4);
goto P_0c0c711a;
P_0c0c711a: /* original 4f12, guest PC 0x0c0c711a */
if(!s->budget--) { s->failed_pc=0x0c0c711au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c711c;
P_0c0c711c: /* original d338, guest PC 0x0c0c711c */
if(!s->budget--) { s->failed_pc=0x0c0c711cu; return 0; }
r[3]=read(ram,0x0c0c7200u,4);
goto P_0c0c711e;
P_0c0c711e: /* original 3f0c, guest PC 0x0c0c711e */
if(!s->budget--) { s->failed_pc=0x0c0c711eu; return 0; }
r[15]+=r[0];
goto P_0c0c7120;
P_0c0c7120: /* original e01c, guest PC 0x0c0c7120 */
if(!s->budget--) { s->failed_pc=0x0c0c7120u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7122;
P_0c0c7122: /* original 00bc, guest PC 0x0c0c7122 */
if(!s->budget--) { s->failed_pc=0x0c0c7122u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c7124;
P_0c0c7124: /* original 600c, guest PC 0x0c0c7124 */
if(!s->budget--) { s->failed_pc=0x0c0c7124u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c7126;
P_0c0c7126: /* original 2909, guest PC 0x0c0c7126 */
if(!s->budget--) { s->failed_pc=0x0c0c7126u; return 0; }
r[9]&=r[0];
goto P_0c0c7128;
P_0c0c7128: /* original 6030, guest PC 0x0c0c7128 */
if(!s->budget--) { s->failed_pc=0x0c0c7128u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0c712a;
P_0c0c712a: /* original 600c, guest PC 0x0c0c712a */
if(!s->budget--) { s->failed_pc=0x0c0c712au; return 0; }
r[0]=r[0]&255u;
goto P_0c0c712c;
P_0c0c712c: /* original 8804, guest PC 0x0c0c712c */
if(!s->budget--) { s->failed_pc=0x0c0c712cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0c712e;
P_0c0c712e: /* original 8b01, guest PC 0x0c0c712e */
if(!s->budget--) { s->failed_pc=0x0c0c712eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7134; }
goto P_0c0c7130;
P_0c0c7130: /* original a0b4, guest PC 0x0c0c7130 */
if(!s->budget--) { s->failed_pc=0x0c0c7130u; return 0; }
goto P_0c0c729c;
P_0c0c7132: /* original 0009, guest PC 0x0c0c7132 */
if(!s->budget--) { s->failed_pc=0x0c0c7132u; return 0; }
goto P_0c0c7134;
P_0c0c7134: /* original 6242, guest PC 0x0c0c7134 */
if(!s->budget--) { s->failed_pc=0x0c0c7134u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0c7136;
P_0c0c7136: /* original 935b, guest PC 0x0c0c7136 */
if(!s->budget--) { s->failed_pc=0x0c0c7136u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71f0u,2);
goto P_0c0c7138;
P_0c0c7138: /* original 2238, guest PC 0x0c0c7138 */
if(!s->budget--) { s->failed_pc=0x0c0c7138u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c713a;
P_0c0c713a: /* original 8901, guest PC 0x0c0c713a */
if(!s->budget--) { s->failed_pc=0x0c0c713au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7140; }
goto P_0c0c713c;
P_0c0c713c: /* original a0ae, guest PC 0x0c0c713c */
if(!s->budget--) { s->failed_pc=0x0c0c713cu; return 0; }
goto P_0c0c729c;
P_0c0c713e: /* original 0009, guest PC 0x0c0c713e */
if(!s->budget--) { s->failed_pc=0x0c0c713eu; return 0; }
goto P_0c0c7140;
P_0c0c7140: /* original 9057, guest PC 0x0c0c7140 */
if(!s->budget--) { s->failed_pc=0x0c0c7140u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71f2u,2);
goto P_0c0c7142;
P_0c0c7142: /* original ec00, guest PC 0x0c0c7142 */
if(!s->budget--) { s->failed_pc=0x0c0c7142u; return 0; }
r[12]=0x00000000u;
goto P_0c0c7144;
P_0c0c7144: /* original 004c, guest PC 0x0c0c7144 */
if(!s->budget--) { s->failed_pc=0x0c0c7144u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7146;
P_0c0c7146: /* original 8817, guest PC 0x0c0c7146 */
if(!s->budget--) { s->failed_pc=0x0c0c7146u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000017u)!=0);
goto P_0c0c7148;
P_0c0c7148: /* original 8d08, guest PC 0x0c0c7148 */
if(!s->budget--) { s->failed_pc=0x0c0c7148u; return 0; }
cond=r[17]&1u;
r[8]=0x00000020u;
if(cond) { goto P_0c0c715c; }
goto P_0c0c714c;
P_0c0c714a: /* original e820, guest PC 0x0c0c714a */
if(!s->budget--) { s->failed_pc=0x0c0c714au; return 0; }
r[8]=0x00000020u;
goto P_0c0c714c;
P_0c0c714c: /* original 9051, guest PC 0x0c0c714c */
if(!s->budget--) { s->failed_pc=0x0c0c714cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71f2u,2);
goto P_0c0c714e;
P_0c0c714e: /* original 004c, guest PC 0x0c0c714e */
if(!s->budget--) { s->failed_pc=0x0c0c714eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7150;
P_0c0c7150: /* original 8807, guest PC 0x0c0c7150 */
if(!s->budget--) { s->failed_pc=0x0c0c7150u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0c7152;
P_0c0c7152: /* original 8903, guest PC 0x0c0c7152 */
if(!s->budget--) { s->failed_pc=0x0c0c7152u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c715c; }
goto P_0c0c7154;
P_0c0c7154: /* original 904e, guest PC 0x0c0c7154 */
if(!s->budget--) { s->failed_pc=0x0c0c7154u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71f4u,2);
goto P_0c0c7156;
P_0c0c7156: /* original 034c, guest PC 0x0c0c7156 */
if(!s->budget--) { s->failed_pc=0x0c0c7156u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7158;
P_0c0c7158: /* original 3387, guest PC 0x0c0c7158 */
if(!s->budget--) { s->failed_pc=0x0c0c7158u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[8])!=0);
goto P_0c0c715a;
P_0c0c715a: /* original 8903, guest PC 0x0c0c715a */
if(!s->budget--) { s->failed_pc=0x0c0c715au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7164; }
goto P_0c0c715c;
P_0c0c715c: /* original 904b, guest PC 0x0c0c715c */
if(!s->budget--) { s->failed_pc=0x0c0c715cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71f6u,2);
goto P_0c0c715e;
P_0c0c715e: /* original 004c, guest PC 0x0c0c715e */
if(!s->budget--) { s->failed_pc=0x0c0c715eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7160;
P_0c0c7160: /* original 8803, guest PC 0x0c0c7160 */
if(!s->budget--) { s->failed_pc=0x0c0c7160u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c7162;
P_0c0c7162: /* original 8b0a, guest PC 0x0c0c7162 */
if(!s->budget--) { s->failed_pc=0x0c0c7162u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c717a; }
goto P_0c0c7164;
P_0c0c7164: /* original 6093, guest PC 0x0c0c7164 */
if(!s->budget--) { s->failed_pc=0x0c0c7164u; return 0; }
r[0]=r[9];
goto P_0c0c7166;
P_0c0c7166: /* original 8802, guest PC 0x0c0c7166 */
if(!s->budget--) { s->failed_pc=0x0c0c7166u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c7168;
P_0c0c7168: /* original 8d06, guest PC 0x0c0c7168 */
if(!s->budget--) { s->failed_pc=0x0c0c7168u; return 0; }
cond=r[17]&1u;
r[4]=0x00000009u;
if(cond) { goto P_0c0c7178; }
goto P_0c0c716c;
P_0c0c716a: /* original e409, guest PC 0x0c0c716a */
if(!s->budget--) { s->failed_pc=0x0c0c716au; return 0; }
r[4]=0x00000009u;
goto P_0c0c716c;
P_0c0c716c: /* original 8807, guest PC 0x0c0c716c */
if(!s->budget--) { s->failed_pc=0x0c0c716cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0c716e;
P_0c0c716e: /* original 8901, guest PC 0x0c0c716e */
if(!s->budget--) { s->failed_pc=0x0c0c716eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7174; }
goto P_0c0c7170;
P_0c0c7170: /* original 880e, guest PC 0x0c0c7170 */
if(!s->budget--) { s->failed_pc=0x0c0c7170u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c0c7172;
P_0c0c7172: /* original 8b02, guest PC 0x0c0c7172 */
if(!s->budget--) { s->failed_pc=0x0c0c7172u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c717a; }
goto P_0c0c7174;
P_0c0c7174: /* original a001, guest PC 0x0c0c7174 */
if(!s->budget--) { s->failed_pc=0x0c0c7174u; return 0; }
r[12]=r[4];
goto P_0c0c717a;
P_0c0c7176: /* original 6c43, guest PC 0x0c0c7176 */
if(!s->budget--) { s->failed_pc=0x0c0c7176u; return 0; }
r[12]=r[4];
goto P_0c0c7178;
P_0c0c7178: /* original ec01, guest PC 0x0c0c7178 */
if(!s->budget--) { s->failed_pc=0x0c0c7178u; return 0; }
r[12]=0x00000001u;
goto P_0c0c717a;
P_0c0c717a: /* original d322, guest PC 0x0c0c717a */
if(!s->budget--) { s->failed_pc=0x0c0c717au; return 0; }
r[3]=read(ram,0x0c0c7204u,4);
goto P_0c0c717c;
P_0c0c717c: /* original 430b, guest PC 0x0c0c717c */
if(!s->budget--) { s->failed_pc=0x0c0c717cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7180u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7180u) { target=s->pc; goto dispatch; }
goto P_0c0c7180;
P_0c0c717e: /* original e400, guest PC 0x0c0c717e */
if(!s->budget--) { s->failed_pc=0x0c0c717eu; return 0; }
r[4]=0x00000000u;
goto P_0c0c7180;
P_0c0c7180: /* original d221, guest PC 0x0c0c7180 */
if(!s->budget--) { s->failed_pc=0x0c0c7180u; return 0; }
r[2]=read(ram,0x0c0c7208u,4);
goto P_0c0c7182;
P_0c0c7182: /* original 420b, guest PC 0x0c0c7182 */
if(!s->budget--) { s->failed_pc=0x0c0c7182u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7186u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7186u) { target=s->pc; goto dispatch; }
goto P_0c0c7186;
P_0c0c7184: /* original 0009, guest PC 0x0c0c7184 */
if(!s->budget--) { s->failed_pc=0x0c0c7184u; return 0; }
goto P_0c0c7186;
P_0c0c7186: /* original 6093, guest PC 0x0c0c7186 */
if(!s->budget--) { s->failed_pc=0x0c0c7186u; return 0; }
r[0]=r[9];
goto P_0c0c7188;
P_0c0c7188: /* original d120, guest PC 0x0c0c7188 */
if(!s->budget--) { s->failed_pc=0x0c0c7188u; return 0; }
r[1]=read(ram,0x0c0c720cu,4);
goto P_0c0c718a;
P_0c0c718a: /* original 4008, guest PC 0x0c0c718a */
if(!s->budget--) { s->failed_pc=0x0c0c718au; return 0; }
r[0]<<=2;
goto P_0c0c718c;
P_0c0c718c: /* original 4000, guest PC 0x0c0c718c */
if(!s->budget--) { s->failed_pc=0x0c0c718cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c718e;
P_0c0c718e: /* original 001e, guest PC 0x0c0c718e */
if(!s->budget--) { s->failed_pc=0x0c0c718eu; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c0c7190;
P_0c0c7190: /* original 88ff, guest PC 0x0c0c7190 */
if(!s->budget--) { s->failed_pc=0x0c0c7190u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c7192;
P_0c0c7192: /* original 8975, guest PC 0x0c0c7192 */
if(!s->budget--) { s->failed_pc=0x0c0c7192u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7280; }
goto P_0c0c7194;
P_0c0c7194: /* original d21e, guest PC 0x0c0c7194 */
if(!s->budget--) { s->failed_pc=0x0c0c7194u; return 0; }
r[2]=read(ram,0x0c0c7210u,4);
goto P_0c0c7196;
P_0c0c7196: /* original 6a22, guest PC 0x0c0c7196 */
if(!s->budget--) { s->failed_pc=0x0c0c7196u; return 0; }
tmp=read(ram,r[2],4);
r[10]=tmp;
goto P_0c0c7198;
P_0c0c7198: /* original 2aa8, guest PC 0x0c0c7198 */
if(!s->budget--) { s->failed_pc=0x0c0c7198u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0c719a;
P_0c0c719a: /* original 8971, guest PC 0x0c0c719a */
if(!s->budget--) { s->failed_pc=0x0c0c719au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7280; }
goto P_0c0c719c;
P_0c0c719c: /* original 6093, guest PC 0x0c0c719c */
if(!s->budget--) { s->failed_pc=0x0c0c719cu; return 0; }
r[0]=r[9];
goto P_0c0c719e;
P_0c0c719e: /* original de1d, guest PC 0x0c0c719e */
if(!s->budget--) { s->failed_pc=0x0c0c719eu; return 0; }
r[14]=read(ram,0x0c0c7214u,4);
goto P_0c0c71a0;
P_0c0c71a0: /* original 9d2a, guest PC 0x0c0c71a0 */
if(!s->budget--) { s->failed_pc=0x0c0c71a0u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71f8u,2);
goto P_0c0c71a2;
P_0c0c71a2: /* original 8801, guest PC 0x0c0c71a2 */
if(!s->budget--) { s->failed_pc=0x0c0c71a2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c71a4;
P_0c0c71a4: /* original 893a, guest PC 0x0c0c71a4 */
if(!s->budget--) { s->failed_pc=0x0c0c71a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c721c; }
goto P_0c0c71a6;
P_0c0c71a6: /* original d01c, guest PC 0x0c0c71a6 */
if(!s->budget--) { s->failed_pc=0x0c0c71a6u; return 0; }
r[0]=read(ram,0x0c0c7218u,4);
goto P_0c0c71a8;
P_0c0c71a8: /* original 6302, guest PC 0x0c0c71a8 */
if(!s->budget--) { s->failed_pc=0x0c0c71a8u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c0c71aa;
P_0c0c71aa: /* original 2838, guest PC 0x0c0c71aa */
if(!s->budget--) { s->failed_pc=0x0c0c71aau; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c0c71ac;
P_0c0c71ac: /* original 8b04, guest PC 0x0c0c71ac */
if(!s->budget--) { s->failed_pc=0x0c0c71acu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c71b8; }
goto P_0c0c71ae;
P_0c0c71ae: /* original e01c, guest PC 0x0c0c71ae */
if(!s->budget--) { s->failed_pc=0x0c0c71aeu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c71b0;
P_0c0c71b0: /* original 00bc, guest PC 0x0c0c71b0 */
if(!s->budget--) { s->failed_pc=0x0c0c71b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c71b2;
P_0c0c71b2: /* original 600c, guest PC 0x0c0c71b2 */
if(!s->budget--) { s->failed_pc=0x0c0c71b2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c71b4;
P_0c0c71b4: /* original 881f, guest PC 0x0c0c71b4 */
if(!s->budget--) { s->failed_pc=0x0c0c71b4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001fu)!=0);
goto P_0c0c71b6;
P_0c0c71b6: /* original 8b0b, guest PC 0x0c0c71b6 */
if(!s->budget--) { s->failed_pc=0x0c0c71b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c71d0; }
goto P_0c0c71b8;
P_0c0c71b8: /* original 4e0b, guest PC 0x0c0c71b8 */
if(!s->budget--) { s->failed_pc=0x0c0c71b8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c71bcu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c71bcu) { target=s->pc; goto dispatch; }
goto P_0c0c71bc;
P_0c0c71ba: /* original 64d3, guest PC 0x0c0c71ba */
if(!s->budget--) { s->failed_pc=0x0c0c71bau; return 0; }
r[4]=r[13];
goto P_0c0c71bc;
P_0c0c71bc: /* original e01c, guest PC 0x0c0c71bc */
if(!s->budget--) { s->failed_pc=0x0c0c71bcu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c71be;
P_0c0c71be: /* original 00bc, guest PC 0x0c0c71be */
if(!s->budget--) { s->failed_pc=0x0c0c71beu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c71c0;
P_0c0c71c0: /* original 600c, guest PC 0x0c0c71c0 */
if(!s->budget--) { s->failed_pc=0x0c0c71c0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c71c2;
P_0c0c71c2: /* original 881f, guest PC 0x0c0c71c2 */
if(!s->budget--) { s->failed_pc=0x0c0c71c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001fu)!=0);
goto P_0c0c71c4;
P_0c0c71c4: /* original 8b5c, guest PC 0x0c0c71c4 */
if(!s->budget--) { s->failed_pc=0x0c0c71c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7280; }
goto P_0c0c71c6;
P_0c0c71c6: /* original 9418, guest PC 0x0c0c71c6 */
if(!s->budget--) { s->failed_pc=0x0c0c71c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71fau,2);
goto P_0c0c71c8;
P_0c0c71c8: /* original 4e0b, guest PC 0x0c0c71c8 */
if(!s->budget--) { s->failed_pc=0x0c0c71c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c71ccu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c71ccu) { target=s->pc; goto dispatch; }
goto P_0c0c71cc;
P_0c0c71ca: /* original 0009, guest PC 0x0c0c71ca */
if(!s->budget--) { s->failed_pc=0x0c0c71cau; return 0; }
goto P_0c0c71cc;
P_0c0c71cc: /* original a058, guest PC 0x0c0c71cc */
if(!s->budget--) { s->failed_pc=0x0c0c71ccu; return 0; }
goto P_0c0c7280;
P_0c0c71ce: /* original 0009, guest PC 0x0c0c71ce */
if(!s->budget--) { s->failed_pc=0x0c0c71ceu; return 0; }
goto P_0c0c71d0;
P_0c0c71d0: /* original 85a6, guest PC 0x0c0c71d0 */
if(!s->budget--) { s->failed_pc=0x0c0c71d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+12,2);
goto P_0c0c71d2;
P_0c0c71d2: /* original 600d, guest PC 0x0c0c71d2 */
if(!s->budget--) { s->failed_pc=0x0c0c71d2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c71d4;
P_0c0c71d4: /* original 6303, guest PC 0x0c0c71d4 */
if(!s->budget--) { s->failed_pc=0x0c0c71d4u; return 0; }
r[3]=r[0];
goto P_0c0c71d6;
P_0c0c71d6: /* original 33c8, guest PC 0x0c0c71d6 */
if(!s->budget--) { s->failed_pc=0x0c0c71d6u; return 0; }
r[3]-=r[12];
goto P_0c0c71d8;
P_0c0c71d8: /* original 6c33, guest PC 0x0c0c71d8 */
if(!s->budget--) { s->failed_pc=0x0c0c71d8u; return 0; }
r[12]=r[3];
goto P_0c0c71da;
P_0c0c71da: /* original 4c15, guest PC 0x0c0c71da */
if(!s->budget--) { s->failed_pc=0x0c0c71dau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c0c71dc;
P_0c0c71dc: /* original 8b50, guest PC 0x0c0c71dc */
if(!s->budget--) { s->failed_pc=0x0c0c71dcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7280; }
goto P_0c0c71de;
P_0c0c71de: /* original 64d3, guest PC 0x0c0c71de */
if(!s->budget--) { s->failed_pc=0x0c0c71deu; return 0; }
r[4]=r[13];
goto P_0c0c71e0;
P_0c0c71e0: /* original 4e0b, guest PC 0x0c0c71e0 */
if(!s->budget--) { s->failed_pc=0x0c0c71e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c71e4u;
r[13]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c71e4u) { target=s->pc; goto dispatch; }
goto P_0c0c71e4;
P_0c0c71e2: /* original 7d01, guest PC 0x0c0c71e2 */
if(!s->budget--) { s->failed_pc=0x0c0c71e2u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c71e4;
P_0c0c71e4: /* original 7cff, guest PC 0x0c0c71e4 */
if(!s->budget--) { s->failed_pc=0x0c0c71e4u; return 0; }
r[12]+=0xffffffffu;
goto P_0c0c71e6;
P_0c0c71e6: /* original 4c15, guest PC 0x0c0c71e6 */
if(!s->budget--) { s->failed_pc=0x0c0c71e6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c0c71e8;
P_0c0c71e8: /* original 89f9, guest PC 0x0c0c71e8 */
if(!s->budget--) { s->failed_pc=0x0c0c71e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c71de; }
goto P_0c0c71ea;
P_0c0c71ea: /* original a049, guest PC 0x0c0c71ea */
if(!s->budget--) { s->failed_pc=0x0c0c71eau; return 0; }
goto P_0c0c7280;
P_0c0c71ec: /* original 0009, guest PC 0x0c0c71ec */
if(!s->budget--) { s->failed_pc=0x0c0c71ecu; return 0; }
if(!vf3_matrix_family(0x0c0c71eeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c71eeu; return 0; } return 1;
P_0c0c721c: /* original c726, guest PC 0x0c0c721c */
if(!s->budget--) { s->failed_pc=0x0c0c721cu; return 0; }
r[0]=code_base|0x000c72b8u;
goto P_0c0c721e;
P_0c0c721e: /* original d328, guest PC 0x0c0c721e */
if(!s->budget--) { s->failed_pc=0x0c0c721eu; return 0; }
r[3]=read(ram,0x0c0c72c0u,4);
goto P_0c0c7220;
P_0c0c7220: /* original f508, guest PC 0x0c0c7220 */
if(!s->budget--) { s->failed_pc=0x0c0c7220u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c7222;
P_0c0c7222: /* original e400, guest PC 0x0c0c7222 */
if(!s->budget--) { s->failed_pc=0x0c0c7222u; return 0; }
r[4]=0x00000000u;
goto P_0c0c7224;
P_0c0c7224: /* original c725, guest PC 0x0c0c7224 */
if(!s->budget--) { s->failed_pc=0x0c0c7224u; return 0; }
r[0]=code_base|0x000c72bcu;
goto P_0c0c7226;
P_0c0c7226: /* original 430b, guest PC 0x0c0c7226 */
if(!s->budget--) { s->failed_pc=0x0c0c7226u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c722au;
vf3_matrix_load(s,ram,4,r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c722au) { target=s->pc; goto dispatch; }
goto P_0c0c722a;
P_0c0c7228: /* original f408, guest PC 0x0c0c7228 */
if(!s->budget--) { s->failed_pc=0x0c0c7228u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c722a;
P_0c0c722a: /* original 64d3, guest PC 0x0c0c722a */
if(!s->budget--) { s->failed_pc=0x0c0c722au; return 0; }
r[4]=r[13];
goto P_0c0c722c;
P_0c0c722c: /* original 4e0b, guest PC 0x0c0c722c */
if(!s->budget--) { s->failed_pc=0x0c0c722cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c7230u;
r[13]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7230u) { target=s->pc; goto dispatch; }
goto P_0c0c7230;
P_0c0c722e: /* original 7d01, guest PC 0x0c0c722e */
if(!s->budget--) { s->failed_pc=0x0c0c722eu; return 0; }
r[13]+=0x00000001u;
goto P_0c0c7230;
P_0c0c7230: /* original e334, guest PC 0x0c0c7230 */
if(!s->budget--) { s->failed_pc=0x0c0c7230u; return 0; }
r[3]=0x00000034u;
goto P_0c0c7232;
P_0c0c7232: /* original e01c, guest PC 0x0c0c7232 */
if(!s->budget--) { s->failed_pc=0x0c0c7232u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7234;
P_0c0c7234: /* original 02bc, guest PC 0x0c0c7234 */
if(!s->budget--) { s->failed_pc=0x0c0c7234u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c7236;
P_0c0c7236: /* original 2f20, guest PC 0x0c0c7236 */
if(!s->budget--) { s->failed_pc=0x0c0c7236u; return 0; }
write(ram,r[15],r[2],1);
goto P_0c0c7238;
P_0c0c7238: /* original 622c, guest PC 0x0c0c7238 */
if(!s->budget--) { s->failed_pc=0x0c0c7238u; return 0; }
r[2]=r[2]&255u;
goto P_0c0c723a;
P_0c0c723a: /* original 64f0, guest PC 0x0c0c723a */
if(!s->budget--) { s->failed_pc=0x0c0c723au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[4]=tmp;
goto P_0c0c723c;
P_0c0c723c: /* original 4208, guest PC 0x0c0c723c */
if(!s->budget--) { s->failed_pc=0x0c0c723cu; return 0; }
r[2]<<=2;
goto P_0c0c723e;
P_0c0c723e: /* original d022, guest PC 0x0c0c723e */
if(!s->budget--) { s->failed_pc=0x0c0c723eu; return 0; }
r[0]=read(ram,0x0c0c72c8u,4);
goto P_0c0c7240;
P_0c0c7240: /* original 4208, guest PC 0x0c0c7240 */
if(!s->budget--) { s->failed_pc=0x0c0c7240u; return 0; }
r[2]<<=2;
goto P_0c0c7242;
P_0c0c7242: /* original 644c, guest PC 0x0c0c7242 */
if(!s->budget--) { s->failed_pc=0x0c0c7242u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c7244;
P_0c0c7244: /* original db1f, guest PC 0x0c0c7244 */
if(!s->budget--) { s->failed_pc=0x0c0c7244u; return 0; }
r[11]=read(ram,0x0c0c72c4u,4);
goto P_0c0c7246;
P_0c0c7246: /* original 243f, guest PC 0x0c0c7246 */
if(!s->budget--) { s->failed_pc=0x0c0c7246u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c0c7248;
P_0c0c7248: /* original 4208, guest PC 0x0c0c7248 */
if(!s->budget--) { s->failed_pc=0x0c0c7248u; return 0; }
r[2]<<=2;
goto P_0c0c724a;
P_0c0c724a: /* original 3b2c, guest PC 0x0c0c724a */
if(!s->budget--) { s->failed_pc=0x0c0c724au; return 0; }
r[11]+=r[2];
goto P_0c0c724c;
P_0c0c724c: /* original d21c, guest PC 0x0c0c724c */
if(!s->budget--) { s->failed_pc=0x0c0c724cu; return 0; }
r[2]=read(ram,0x0c0c72c0u,4);
goto P_0c0c724e;
P_0c0c724e: /* original 041a, guest PC 0x0c0c724e */
if(!s->budget--) { s->failed_pc=0x0c0c724eu; return 0; }
r[4]=r[19];
goto P_0c0c7250;
P_0c0c7250: /* original 644f, guest PC 0x0c0c7250 */
if(!s->budget--) { s->failed_pc=0x0c0c7250u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0c7252;
P_0c0c7252: /* original 044c, guest PC 0x0c0c7252 */
if(!s->budget--) { s->failed_pc=0x0c0c7252u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7254;
P_0c0c7254: /* original e010, guest PC 0x0c0c7254 */
if(!s->budget--) { s->failed_pc=0x0c0c7254u; return 0; }
r[0]=0x00000010u;
goto P_0c0c7256;
P_0c0c7256: /* original f5b6, guest PC 0x0c0c7256 */
if(!s->budget--) { s->failed_pc=0x0c0c7256u; return 0; }
vf3_matrix_load(s,ram,5,r[11]+r[0]);
goto P_0c0c7258;
P_0c0c7258: /* original e014, guest PC 0x0c0c7258 */
if(!s->budget--) { s->failed_pc=0x0c0c7258u; return 0; }
r[0]=0x00000014u;
goto P_0c0c725a;
P_0c0c725a: /* original 420b, guest PC 0x0c0c725a */
if(!s->budget--) { s->failed_pc=0x0c0c725au; return 0; }
target=r[2];
r[16]=code_base|0x0c0c725eu;
vf3_matrix_load(s,ram,4,r[11]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c725eu) { target=s->pc; goto dispatch; }
goto P_0c0c725e;
P_0c0c725c: /* original f4b6, guest PC 0x0c0c725c */
if(!s->budget--) { s->failed_pc=0x0c0c725cu; return 0; }
vf3_matrix_load(s,ram,4,r[11]+r[0]);
goto P_0c0c725e;
P_0c0c725e: /* original d21b, guest PC 0x0c0c725e */
if(!s->budget--) { s->failed_pc=0x0c0c725eu; return 0; }
r[2]=read(ram,0x0c0c72ccu,4);
goto P_0c0c7260;
P_0c0c7260: /* original 6322, guest PC 0x0c0c7260 */
if(!s->budget--) { s->failed_pc=0x0c0c7260u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0c7262;
P_0c0c7262: /* original 2838, guest PC 0x0c0c7262 */
if(!s->budget--) { s->failed_pc=0x0c0c7262u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c0c7264;
P_0c0c7264: /* original 8b0c, guest PC 0x0c0c7264 */
if(!s->budget--) { s->failed_pc=0x0c0c7264u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7280; }
goto P_0c0c7266;
P_0c0c7266: /* original 85a6, guest PC 0x0c0c7266 */
if(!s->budget--) { s->failed_pc=0x0c0c7266u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+12,2);
goto P_0c0c7268;
P_0c0c7268: /* original 600d, guest PC 0x0c0c7268 */
if(!s->budget--) { s->failed_pc=0x0c0c7268u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c726a;
P_0c0c726a: /* original 30c8, guest PC 0x0c0c726a */
if(!s->budget--) { s->failed_pc=0x0c0c726au; return 0; }
r[0]-=r[12];
goto P_0c0c726c;
P_0c0c726c: /* original 6c03, guest PC 0x0c0c726c */
if(!s->budget--) { s->failed_pc=0x0c0c726cu; return 0; }
r[12]=r[0];
goto P_0c0c726e;
P_0c0c726e: /* original 7cff, guest PC 0x0c0c726e */
if(!s->budget--) { s->failed_pc=0x0c0c726eu; return 0; }
r[12]+=0xffffffffu;
goto P_0c0c7270;
P_0c0c7270: /* original 4c15, guest PC 0x0c0c7270 */
if(!s->budget--) { s->failed_pc=0x0c0c7270u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c0c7272;
P_0c0c7272: /* original 8b05, guest PC 0x0c0c7272 */
if(!s->budget--) { s->failed_pc=0x0c0c7272u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7280; }
goto P_0c0c7274;
P_0c0c7274: /* original 64d3, guest PC 0x0c0c7274 */
if(!s->budget--) { s->failed_pc=0x0c0c7274u; return 0; }
r[4]=r[13];
goto P_0c0c7276;
P_0c0c7276: /* original 4e0b, guest PC 0x0c0c7276 */
if(!s->budget--) { s->failed_pc=0x0c0c7276u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c727au;
r[13]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c727au) { target=s->pc; goto dispatch; }
goto P_0c0c727a;
P_0c0c7278: /* original 7d01, guest PC 0x0c0c7278 */
if(!s->budget--) { s->failed_pc=0x0c0c7278u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c727a;
P_0c0c727a: /* original 7cff, guest PC 0x0c0c727a */
if(!s->budget--) { s->failed_pc=0x0c0c727au; return 0; }
r[12]+=0xffffffffu;
goto P_0c0c727c;
P_0c0c727c: /* original 4c15, guest PC 0x0c0c727c */
if(!s->budget--) { s->failed_pc=0x0c0c727cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c0c727e;
P_0c0c727e: /* original 89f9, guest PC 0x0c0c727e */
if(!s->budget--) { s->failed_pc=0x0c0c727eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7274; }
goto P_0c0c7280;
P_0c0c7280: /* original 9118, guest PC 0x0c0c7280 */
if(!s->budget--) { s->failed_pc=0x0c0c7280u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c72b4u,2);
goto P_0c0c7282;
P_0c0c7282: /* original e401, guest PC 0x0c0c7282 */
if(!s->budget--) { s->failed_pc=0x0c0c7282u; return 0; }
r[4]=0x00000001u;
goto P_0c0c7284;
P_0c0c7284: /* original d312, guest PC 0x0c0c7284 */
if(!s->budget--) { s->failed_pc=0x0c0c7284u; return 0; }
r[3]=read(ram,0x0c0c72d0u,4);
goto P_0c0c7286;
P_0c0c7286: /* original 3f1c, guest PC 0x0c0c7286 */
if(!s->budget--) { s->failed_pc=0x0c0c7286u; return 0; }
r[15]+=r[1];
goto P_0c0c7288;
P_0c0c7288: /* original 4f16, guest PC 0x0c0c7288 */
if(!s->budget--) { s->failed_pc=0x0c0c7288u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c728a;
P_0c0c728a: /* original 4f26, guest PC 0x0c0c728a */
if(!s->budget--) { s->failed_pc=0x0c0c728au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c728c;
P_0c0c728c: /* original 68f6, guest PC 0x0c0c728c */
if(!s->budget--) { s->failed_pc=0x0c0c728cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c728e;
P_0c0c728e: /* original 69f6, guest PC 0x0c0c728e */
if(!s->budget--) { s->failed_pc=0x0c0c728eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c7290;
P_0c0c7290: /* original 6af6, guest PC 0x0c0c7290 */
if(!s->budget--) { s->failed_pc=0x0c0c7290u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c7292;
P_0c0c7292: /* original 6bf6, guest PC 0x0c0c7292 */
if(!s->budget--) { s->failed_pc=0x0c0c7292u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7294;
P_0c0c7294: /* original 6cf6, guest PC 0x0c0c7294 */
if(!s->budget--) { s->failed_pc=0x0c0c7294u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7296;
P_0c0c7296: /* original 6df6, guest PC 0x0c0c7296 */
if(!s->budget--) { s->failed_pc=0x0c0c7296u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c7298;
P_0c0c7298: /* original 432b, guest PC 0x0c0c7298 */
if(!s->budget--) { s->failed_pc=0x0c0c7298u; return 0; }
target=r[3];
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
P_0c0c729a: /* original 6ef6, guest PC 0x0c0c729a */
if(!s->budget--) { s->failed_pc=0x0c0c729au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c729c;
P_0c0c729c: /* original 910a, guest PC 0x0c0c729c */
if(!s->budget--) { s->failed_pc=0x0c0c729cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c72b4u,2);
goto P_0c0c729e;
P_0c0c729e: /* original 3f1c, guest PC 0x0c0c729e */
if(!s->budget--) { s->failed_pc=0x0c0c729eu; return 0; }
r[15]+=r[1];
goto P_0c0c72a0;
P_0c0c72a0: /* original 4f16, guest PC 0x0c0c72a0 */
if(!s->budget--) { s->failed_pc=0x0c0c72a0u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c72a2;
P_0c0c72a2: /* original 4f26, guest PC 0x0c0c72a2 */
if(!s->budget--) { s->failed_pc=0x0c0c72a2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c72a4;
P_0c0c72a4: /* original 68f6, guest PC 0x0c0c72a4 */
if(!s->budget--) { s->failed_pc=0x0c0c72a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c72a6;
P_0c0c72a6: /* original 69f6, guest PC 0x0c0c72a6 */
if(!s->budget--) { s->failed_pc=0x0c0c72a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c72a8;
P_0c0c72a8: /* original 6af6, guest PC 0x0c0c72a8 */
if(!s->budget--) { s->failed_pc=0x0c0c72a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c72aa;
P_0c0c72aa: /* original 6bf6, guest PC 0x0c0c72aa */
if(!s->budget--) { s->failed_pc=0x0c0c72aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c72ac;
P_0c0c72ac: /* original 6cf6, guest PC 0x0c0c72ac */
if(!s->budget--) { s->failed_pc=0x0c0c72acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c72ae;
P_0c0c72ae: /* original 6df6, guest PC 0x0c0c72ae */
if(!s->budget--) { s->failed_pc=0x0c0c72aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c72b0;
P_0c0c72b0: /* original 000b, guest PC 0x0c0c72b0 */
if(!s->budget--) { s->failed_pc=0x0c0c72b0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c72b2: /* original 6ef6, guest PC 0x0c0c72b2 */
if(!s->budget--) { s->failed_pc=0x0c0c72b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c72b4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c72b4u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
