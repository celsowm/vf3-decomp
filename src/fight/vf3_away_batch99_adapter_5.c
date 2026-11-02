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
int vf3_away_batch99_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c61a8u: goto P_0c0c61a8;
case 0x0c0c61aau: goto P_0c0c61aa;
case 0x0c0c61acu: goto P_0c0c61ac;
case 0x0c0c61aeu: goto P_0c0c61ae;
case 0x0c0c61b0u: goto P_0c0c61b0;
case 0x0c0c61b2u: goto P_0c0c61b2;
case 0x0c0c61b4u: goto P_0c0c61b4;
case 0x0c0c61b6u: goto P_0c0c61b6;
case 0x0c0c61b8u: goto P_0c0c61b8;
case 0x0c0c61bau: goto P_0c0c61ba;
case 0x0c0c61bcu: goto P_0c0c61bc;
case 0x0c0c61beu: goto P_0c0c61be;
case 0x0c0c61c0u: goto P_0c0c61c0;
case 0x0c0c61c2u: goto P_0c0c61c2;
case 0x0c0c61c4u: goto P_0c0c61c4;
case 0x0c0c61c6u: goto P_0c0c61c6;
case 0x0c0c61c8u: goto P_0c0c61c8;
case 0x0c0c61cau: goto P_0c0c61ca;
case 0x0c0c61ccu: goto P_0c0c61cc;
case 0x0c0c61ceu: goto P_0c0c61ce;
case 0x0c0c61d0u: goto P_0c0c61d0;
case 0x0c0c61d2u: goto P_0c0c61d2;
case 0x0c0c61d4u: goto P_0c0c61d4;
case 0x0c0c61d6u: goto P_0c0c61d6;
case 0x0c0c61d8u: goto P_0c0c61d8;
case 0x0c0c61dau: goto P_0c0c61da;
case 0x0c0c61dcu: goto P_0c0c61dc;
case 0x0c0c61deu: goto P_0c0c61de;
case 0x0c0c61e0u: goto P_0c0c61e0;
case 0x0c0c61e2u: goto P_0c0c61e2;
case 0x0c0c61e4u: goto P_0c0c61e4;
case 0x0c0c61e6u: goto P_0c0c61e6;
case 0x0c0c61e8u: goto P_0c0c61e8;
case 0x0c0c61eau: goto P_0c0c61ea;
case 0x0c0c61ecu: goto P_0c0c61ec;
case 0x0c0c61eeu: goto P_0c0c61ee;
case 0x0c0c61f0u: goto P_0c0c61f0;
case 0x0c0c61f2u: goto P_0c0c61f2;
case 0x0c0c61f4u: goto P_0c0c61f4;
case 0x0c0c61f6u: goto P_0c0c61f6;
case 0x0c0c61f8u: goto P_0c0c61f8;
case 0x0c0c61fau: goto P_0c0c61fa;
case 0x0c0c61fcu: goto P_0c0c61fc;
case 0x0c0c61feu: goto P_0c0c61fe;
case 0x0c0c6200u: goto P_0c0c6200;
case 0x0c0c6202u: goto P_0c0c6202;
case 0x0c0c6204u: goto P_0c0c6204;
case 0x0c0c6206u: goto P_0c0c6206;
case 0x0c0c6208u: goto P_0c0c6208;
case 0x0c0c620au: goto P_0c0c620a;
case 0x0c0c620cu: goto P_0c0c620c;
case 0x0c0c620eu: goto P_0c0c620e;
case 0x0c0c6210u: goto P_0c0c6210;
case 0x0c0c6212u: goto P_0c0c6212;
case 0x0c0c6214u: goto P_0c0c6214;
case 0x0c0c6216u: goto P_0c0c6216;
case 0x0c0c6218u: goto P_0c0c6218;
case 0x0c0c621au: goto P_0c0c621a;
case 0x0c0c621cu: goto P_0c0c621c;
case 0x0c0c621eu: goto P_0c0c621e;
case 0x0c0c6220u: goto P_0c0c6220;
case 0x0c0c6222u: goto P_0c0c6222;
case 0x0c0c6224u: goto P_0c0c6224;
case 0x0c0c6226u: goto P_0c0c6226;
case 0x0c0c6228u: goto P_0c0c6228;
case 0x0c0c622au: goto P_0c0c622a;
case 0x0c0c622cu: goto P_0c0c622c;
case 0x0c0c622eu: goto P_0c0c622e;
case 0x0c0c6230u: goto P_0c0c6230;
case 0x0c0c6232u: goto P_0c0c6232;
case 0x0c0c6234u: goto P_0c0c6234;
case 0x0c0c6236u: goto P_0c0c6236;
case 0x0c0c6238u: goto P_0c0c6238;
case 0x0c0c623au: goto P_0c0c623a;
case 0x0c0c623cu: goto P_0c0c623c;
case 0x0c0c623eu: goto P_0c0c623e;
case 0x0c0c6240u: goto P_0c0c6240;
case 0x0c0c6242u: goto P_0c0c6242;
case 0x0c0c6244u: goto P_0c0c6244;
case 0x0c0c6246u: goto P_0c0c6246;
case 0x0c0c6248u: goto P_0c0c6248;
case 0x0c0c624au: goto P_0c0c624a;
case 0x0c0c624cu: goto P_0c0c624c;
case 0x0c0c624eu: goto P_0c0c624e;
case 0x0c0c6250u: goto P_0c0c6250;
case 0x0c0c6252u: goto P_0c0c6252;
case 0x0c0c6254u: goto P_0c0c6254;
case 0x0c0c632eu: goto P_0c0c632e;
case 0x0c0c6330u: goto P_0c0c6330;
case 0x0c0c6332u: goto P_0c0c6332;
case 0x0c0c6334u: goto P_0c0c6334;
case 0x0c0c6336u: goto P_0c0c6336;
case 0x0c0c6338u: goto P_0c0c6338;
case 0x0c0c633au: goto P_0c0c633a;
case 0x0c0c633cu: goto P_0c0c633c;
case 0x0c0c633eu: goto P_0c0c633e;
case 0x0c0c6340u: goto P_0c0c6340;
case 0x0c0c6342u: goto P_0c0c6342;
case 0x0c0c6344u: goto P_0c0c6344;
case 0x0c0c6346u: goto P_0c0c6346;
case 0x0c0c6348u: goto P_0c0c6348;
case 0x0c0c634au: goto P_0c0c634a;
case 0x0c0c634cu: goto P_0c0c634c;
case 0x0c0c634eu: goto P_0c0c634e;
case 0x0c0c6350u: goto P_0c0c6350;
case 0x0c0c6352u: goto P_0c0c6352;
case 0x0c0c6354u: goto P_0c0c6354;
case 0x0c0c6356u: goto P_0c0c6356;
case 0x0c0c6358u: goto P_0c0c6358;
case 0x0c0c635au: goto P_0c0c635a;
case 0x0c0c635cu: goto P_0c0c635c;
case 0x0c0c635eu: goto P_0c0c635e;
case 0x0c0c6360u: goto P_0c0c6360;
case 0x0c0c6362u: goto P_0c0c6362;
case 0x0c0c6364u: goto P_0c0c6364;
case 0x0c0c6366u: goto P_0c0c6366;
case 0x0c0c6368u: goto P_0c0c6368;
case 0x0c0c636au: goto P_0c0c636a;
case 0x0c0c636cu: goto P_0c0c636c;
case 0x0c0c636eu: goto P_0c0c636e;
case 0x0c0c6370u: goto P_0c0c6370;
case 0x0c0c6372u: goto P_0c0c6372;
case 0x0c0c6374u: goto P_0c0c6374;
case 0x0c0c6376u: goto P_0c0c6376;
case 0x0c0c6378u: goto P_0c0c6378;
case 0x0c0c637au: goto P_0c0c637a;
case 0x0c0c637cu: goto P_0c0c637c;
case 0x0c0c637eu: goto P_0c0c637e;
case 0x0c0c63c4u: goto P_0c0c63c4;
case 0x0c0c63c6u: goto P_0c0c63c6;
case 0x0c0c63c8u: goto P_0c0c63c8;
case 0x0c0c63cau: goto P_0c0c63ca;
case 0x0c0c63ccu: goto P_0c0c63cc;
case 0x0c0c63ceu: goto P_0c0c63ce;
case 0x0c0c63d0u: goto P_0c0c63d0;
case 0x0c0c63d2u: goto P_0c0c63d2;
case 0x0c0c63d4u: goto P_0c0c63d4;
case 0x0c0c63d6u: goto P_0c0c63d6;
case 0x0c0c63d8u: goto P_0c0c63d8;
case 0x0c0c63dau: goto P_0c0c63da;
case 0x0c0c63dcu: goto P_0c0c63dc;
case 0x0c0c63deu: goto P_0c0c63de;
case 0x0c0c63e0u: goto P_0c0c63e0;
case 0x0c0c63e2u: goto P_0c0c63e2;
case 0x0c0c63e4u: goto P_0c0c63e4;
case 0x0c0c63e6u: goto P_0c0c63e6;
case 0x0c0c63e8u: goto P_0c0c63e8;
case 0x0c0c63eau: goto P_0c0c63ea;
case 0x0c0c63ecu: goto P_0c0c63ec;
case 0x0c0c63eeu: goto P_0c0c63ee;
case 0x0c0c63f0u: goto P_0c0c63f0;
case 0x0c0c63f2u: goto P_0c0c63f2;
case 0x0c0c63f4u: goto P_0c0c63f4;
case 0x0c0c63f6u: goto P_0c0c63f6;
case 0x0c0c63f8u: goto P_0c0c63f8;
case 0x0c0c63fau: goto P_0c0c63fa;
case 0x0c0c63fcu: goto P_0c0c63fc;
case 0x0c0c63feu: goto P_0c0c63fe;
case 0x0c0c6400u: goto P_0c0c6400;
case 0x0c0c6402u: goto P_0c0c6402;
case 0x0c0c6404u: goto P_0c0c6404;
case 0x0c0c6406u: goto P_0c0c6406;
case 0x0c0c6408u: goto P_0c0c6408;
case 0x0c0c640au: goto P_0c0c640a;
case 0x0c0c640cu: goto P_0c0c640c;
case 0x0c0c640eu: goto P_0c0c640e;
case 0x0c0c6410u: goto P_0c0c6410;
case 0x0c0c6412u: goto P_0c0c6412;
case 0x0c0c6414u: goto P_0c0c6414;
case 0x0c0c6416u: goto P_0c0c6416;
case 0x0c0c6418u: goto P_0c0c6418;
case 0x0c0c641au: goto P_0c0c641a;
case 0x0c0c641cu: goto P_0c0c641c;
case 0x0c0c641eu: goto P_0c0c641e;
case 0x0c0c6420u: goto P_0c0c6420;
case 0x0c0c6422u: goto P_0c0c6422;
case 0x0c0c6424u: goto P_0c0c6424;
case 0x0c0c6426u: goto P_0c0c6426;
case 0x0c0c6428u: goto P_0c0c6428;
case 0x0c0c642au: goto P_0c0c642a;
case 0x0c0c642cu: goto P_0c0c642c;
case 0x0c0c642eu: goto P_0c0c642e;
case 0x0c0c6430u: goto P_0c0c6430;
case 0x0c0c6432u: goto P_0c0c6432;
case 0x0c0c6434u: goto P_0c0c6434;
case 0x0c0c6436u: goto P_0c0c6436;
case 0x0c0c6438u: goto P_0c0c6438;
case 0x0c0c643au: goto P_0c0c643a;
case 0x0c0c643cu: goto P_0c0c643c;
case 0x0c0c643eu: goto P_0c0c643e;
case 0x0c0c6440u: goto P_0c0c6440;
case 0x0c0c6442u: goto P_0c0c6442;
case 0x0c0c6444u: goto P_0c0c6444;
case 0x0c0c6446u: goto P_0c0c6446;
case 0x0c0c6448u: goto P_0c0c6448;
case 0x0c0c644au: goto P_0c0c644a;
case 0x0c0c644cu: goto P_0c0c644c;
case 0x0c0c644eu: goto P_0c0c644e;
case 0x0c0c6450u: goto P_0c0c6450;
case 0x0c0c6452u: goto P_0c0c6452;
case 0x0c0c6454u: goto P_0c0c6454;
case 0x0c0c6456u: goto P_0c0c6456;
case 0x0c0c6458u: goto P_0c0c6458;
case 0x0c0c645au: goto P_0c0c645a;
case 0x0c0c645cu: goto P_0c0c645c;
case 0x0c0c645eu: goto P_0c0c645e;
case 0x0c0c6460u: goto P_0c0c6460;
case 0x0c0c6462u: goto P_0c0c6462;
case 0x0c0c6464u: goto P_0c0c6464;
case 0x0c0c6466u: goto P_0c0c6466;
case 0x0c0c6468u: goto P_0c0c6468;
case 0x0c0c646au: goto P_0c0c646a;
case 0x0c0c646cu: goto P_0c0c646c;
case 0x0c0c646eu: goto P_0c0c646e;
case 0x0c0c6470u: goto P_0c0c6470;
case 0x0c0c6472u: goto P_0c0c6472;
case 0x0c0c6474u: goto P_0c0c6474;
case 0x0c0c6476u: goto P_0c0c6476;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c61a8: /* original 2fe6, guest PC 0x0c0c61a8 */
if(!s->budget--) { s->failed_pc=0x0c0c61a8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61aa;
P_0c0c61aa: /* original 4411, guest PC 0x0c0c61aa */
if(!s->budget--) { s->failed_pc=0x0c0c61aau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c61ac;
P_0c0c61ac: /* original 2fd6, guest PC 0x0c0c61ac */
if(!s->budget--) { s->failed_pc=0x0c0c61acu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61ae;
P_0c0c61ae: /* original 2fc6, guest PC 0x0c0c61ae */
if(!s->budget--) { s->failed_pc=0x0c0c61aeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b0;
P_0c0c61b0: /* original 2fb6, guest PC 0x0c0c61b0 */
if(!s->budget--) { s->failed_pc=0x0c0c61b0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b2;
P_0c0c61b2: /* original 2fa6, guest PC 0x0c0c61b2 */
if(!s->budget--) { s->failed_pc=0x0c0c61b2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b4;
P_0c0c61b4: /* original 2f96, guest PC 0x0c0c61b4 */
if(!s->budget--) { s->failed_pc=0x0c0c61b4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b6;
P_0c0c61b6: /* original 2f86, guest PC 0x0c0c61b6 */
if(!s->budget--) { s->failed_pc=0x0c0c61b6u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b8;
P_0c0c61b8: /* original 4f22, guest PC 0x0c0c61b8 */
if(!s->budget--) { s->failed_pc=0x0c0c61b8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c61ba;
P_0c0c61ba: /* original 7ffc, guest PC 0x0c0c61ba */
if(!s->budget--) { s->failed_pc=0x0c0c61bau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c61bc;
P_0c0c61bc: /* original 8b41, guest PC 0x0c0c61bc */
if(!s->budget--) { s->failed_pc=0x0c0c61bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6242; }
goto P_0c0c61be;
P_0c0c61be: /* original 924a, guest PC 0x0c0c61be */
if(!s->budget--) { s->failed_pc=0x0c0c61beu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6256u,2);
goto P_0c0c61c0;
P_0c0c61c0: /* original 3423, guest PC 0x0c0c61c0 */
if(!s->budget--) { s->failed_pc=0x0c0c61c0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0c61c2;
P_0c0c61c2: /* original 893e, guest PC 0x0c0c61c2 */
if(!s->budget--) { s->failed_pc=0x0c0c61c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6242; }
goto P_0c0c61c4;
P_0c0c61c4: /* original d325, guest PC 0x0c0c61c4 */
if(!s->budget--) { s->failed_pc=0x0c0c61c4u; return 0; }
r[3]=read(ram,0x0c0c625cu,4);
goto P_0c0c61c6;
P_0c0c61c6: /* original 6143, guest PC 0x0c0c61c6 */
if(!s->budget--) { s->failed_pc=0x0c0c61c6u; return 0; }
r[1]=r[4];
goto P_0c0c61c8;
P_0c0c61c8: /* original 4108, guest PC 0x0c0c61c8 */
if(!s->budget--) { s->failed_pc=0x0c0c61c8u; return 0; }
r[1]<<=2;
goto P_0c0c61ca;
P_0c0c61ca: /* original 313c, guest PC 0x0c0c61ca */
if(!s->budget--) { s->failed_pc=0x0c0c61cau; return 0; }
r[1]+=r[3];
goto P_0c0c61cc;
P_0c0c61cc: /* original 2f12, guest PC 0x0c0c61cc */
if(!s->budget--) { s->failed_pc=0x0c0c61ccu; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0c61ce;
P_0c0c61ce: /* original 6212, guest PC 0x0c0c61ce */
if(!s->budget--) { s->failed_pc=0x0c0c61ceu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0c61d0;
P_0c0c61d0: /* original 4211, guest PC 0x0c0c61d0 */
if(!s->budget--) { s->failed_pc=0x0c0c61d0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c0c61d2;
P_0c0c61d2: /* original 8b36, guest PC 0x0c0c61d2 */
if(!s->budget--) { s->failed_pc=0x0c0c61d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6242; }
goto P_0c0c61d4;
P_0c0c61d4: /* original da23, guest PC 0x0c0c61d4 */
if(!s->budget--) { s->failed_pc=0x0c0c61d4u; return 0; }
r[10]=read(ram,0x0c0c6264u,4);
goto P_0c0c61d6;
P_0c0c61d6: /* original ec00, guest PC 0x0c0c61d6 */
if(!s->budget--) { s->failed_pc=0x0c0c61d6u; return 0; }
r[12]=0x00000000u;
goto P_0c0c61d8;
P_0c0c61d8: /* original db23, guest PC 0x0c0c61d8 */
if(!s->budget--) { s->failed_pc=0x0c0c61d8u; return 0; }
r[11]=read(ram,0x0c0c6268u,4);
goto P_0c0c61da;
P_0c0c61da: /* original dd24, guest PC 0x0c0c61da */
if(!s->budget--) { s->failed_pc=0x0c0c61dau; return 0; }
r[13]=read(ram,0x0c0c626cu,4);
goto P_0c0c61dc;
P_0c0c61dc: /* original d920, guest PC 0x0c0c61dc */
if(!s->budget--) { s->failed_pc=0x0c0c61dcu; return 0; }
r[9]=read(ram,0x0c0c6260u,4);
goto P_0c0c61de;
P_0c0c61de: /* original 983b, guest PC 0x0c0c61de */
if(!s->budget--) { s->failed_pc=0x0c0c61deu; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6258u,2);
goto P_0c0c61e0;
P_0c0c61e0: /* original 6ec3, guest PC 0x0c0c61e0 */
if(!s->budget--) { s->failed_pc=0x0c0c61e0u; return 0; }
r[14]=r[12];
goto P_0c0c61e2;
P_0c0c61e2: /* original 4e08, guest PC 0x0c0c61e2 */
if(!s->budget--) { s->failed_pc=0x0c0c61e2u; return 0; }
r[14]<<=2;
goto P_0c0c61e4;
P_0c0c61e4: /* original 4e00, guest PC 0x0c0c61e4 */
if(!s->budget--) { s->failed_pc=0x0c0c61e4u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c0c61e6;
P_0c0c61e6: /* original 3ebc, guest PC 0x0c0c61e6 */
if(!s->budget--) { s->failed_pc=0x0c0c61e6u; return 0; }
r[14]+=r[11];
goto P_0c0c61e8;
P_0c0c61e8: /* original 53e1, guest PC 0x0c0c61e8 */
if(!s->budget--) { s->failed_pc=0x0c0c61e8u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0c61ea;
P_0c0c61ea: /* original 2338, guest PC 0x0c0c61ea */
if(!s->budget--) { s->failed_pc=0x0c0c61eau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c61ec;
P_0c0c61ec: /* original 8929, guest PC 0x0c0c61ec */
if(!s->budget--) { s->failed_pc=0x0c0c61ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6242; }
goto P_0c0c61ee;
P_0c0c61ee: /* original 52e1, guest PC 0x0c0c61ee */
if(!s->budget--) { s->failed_pc=0x0c0c61eeu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0c61f0;
P_0c0c61f0: /* original 3420, guest PC 0x0c0c61f0 */
if(!s->budget--) { s->failed_pc=0x0c0c61f0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0c61f2;
P_0c0c61f2: /* original 8b24, guest PC 0x0c0c61f2 */
if(!s->budget--) { s->failed_pc=0x0c0c61f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c623e; }
goto P_0c0c61f4;
P_0c0c61f4: /* original 6392, guest PC 0x0c0c61f4 */
if(!s->budget--) { s->failed_pc=0x0c0c61f4u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c0c61f6;
P_0c0c61f6: /* original 61e2, guest PC 0x0c0c61f6 */
if(!s->budget--) { s->failed_pc=0x0c0c61f6u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0c61f8;
P_0c0c61f8: /* original 3310, guest PC 0x0c0c61f8 */
if(!s->budget--) { s->failed_pc=0x0c0c61f8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c0c61fa;
P_0c0c61fa: /* original 891a, guest PC 0x0c0c61fa */
if(!s->budget--) { s->failed_pc=0x0c0c61fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6232; }
goto P_0c0c61fc;
P_0c0c61fc: /* original 65a2, guest PC 0x0c0c61fc */
if(!s->budget--) { s->failed_pc=0x0c0c61fcu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0c61fe;
P_0c0c61fe: /* original d31c, guest PC 0x0c0c61fe */
if(!s->budget--) { s->failed_pc=0x0c0c61feu; return 0; }
r[3]=read(ram,0x0c0c6270u,4);
goto P_0c0c6200;
P_0c0c6200: /* original 35dc, guest PC 0x0c0c6200 */
if(!s->budget--) { s->failed_pc=0x0c0c6200u; return 0; }
r[5]+=r[13];
goto P_0c0c6202;
P_0c0c6202: /* original 430b, guest PC 0x0c0c6202 */
if(!s->budget--) { s->failed_pc=0x0c0c6202u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6206u;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6206u) { target=s->pc; goto dispatch; }
goto P_0c0c6206;
P_0c0c6204: /* original 64e2, guest PC 0x0c0c6204 */
if(!s->budget--) { s->failed_pc=0x0c0c6204u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0c6206;
P_0c0c6206: /* original d41b, guest PC 0x0c0c6206 */
if(!s->budget--) { s->failed_pc=0x0c0c6206u; return 0; }
r[4]=read(ram,0x0c0c6274u,4);
goto P_0c0c6208;
P_0c0c6208: /* original bd44, guest PC 0x0c0c6208 */
if(!s->budget--) { s->failed_pc=0x0c0c6208u; return 0; }
target=code_base|0x0c0c5c94u; r[16]=code_base|0x0c0c620cu;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c620cu) { target=s->pc; goto dispatch; }
goto P_0c0c620c;
P_0c0c620a: /* original e500, guest PC 0x0c0c620a */
if(!s->budget--) { s->failed_pc=0x0c0c620au; return 0; }
r[5]=0x00000000u;
goto P_0c0c620c;
P_0c0c620c: /* original d31a, guest PC 0x0c0c620c */
if(!s->budget--) { s->failed_pc=0x0c0c620cu; return 0; }
r[3]=read(ram,0x0c0c6278u,4);
goto P_0c0c620e;
P_0c0c620e: /* original 430b, guest PC 0x0c0c620e */
if(!s->budget--) { s->failed_pc=0x0c0c620eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6212u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6212u) { target=s->pc; goto dispatch; }
goto P_0c0c6212;
P_0c0c6210: /* original e403, guest PC 0x0c0c6210 */
if(!s->budget--) { s->failed_pc=0x0c0c6210u; return 0; }
r[4]=0x00000003u;
goto P_0c0c6212;
P_0c0c6212: /* original d21a, guest PC 0x0c0c6212 */
if(!s->budget--) { s->failed_pc=0x0c0c6212u; return 0; }
r[2]=read(ram,0x0c0c627cu,4);
goto P_0c0c6214;
P_0c0c6214: /* original e503, guest PC 0x0c0c6214 */
if(!s->budget--) { s->failed_pc=0x0c0c6214u; return 0; }
r[5]=0x00000003u;
goto P_0c0c6216;
P_0c0c6216: /* original 64a2, guest PC 0x0c0c6216 */
if(!s->budget--) { s->failed_pc=0x0c0c6216u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0c6218;
P_0c0c6218: /* original 420b, guest PC 0x0c0c6218 */
if(!s->budget--) { s->failed_pc=0x0c0c6218u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c621cu;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c621cu) { target=s->pc; goto dispatch; }
goto P_0c0c621c;
P_0c0c621a: /* original 34dc, guest PC 0x0c0c621a */
if(!s->budget--) { s->failed_pc=0x0c0c621au; return 0; }
r[4]+=r[13];
goto P_0c0c621c;
P_0c0c621c: /* original 2008, guest PC 0x0c0c621c */
if(!s->budget--) { s->failed_pc=0x0c0c621cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c621e;
P_0c0c621e: /* original 8903, guest PC 0x0c0c621e */
if(!s->budget--) { s->failed_pc=0x0c0c621eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6228; }
goto P_0c0c6220;
P_0c0c6220: /* original d217, guest PC 0x0c0c6220 */
if(!s->budget--) { s->failed_pc=0x0c0c6220u; return 0; }
r[2]=read(ram,0x0c0c6280u,4);
goto P_0c0c6222;
P_0c0c6222: /* original 6583, guest PC 0x0c0c6222 */
if(!s->budget--) { s->failed_pc=0x0c0c6222u; return 0; }
r[5]=r[8];
goto P_0c0c6224;
P_0c0c6224: /* original 420b, guest PC 0x0c0c6224 */
if(!s->budget--) { s->failed_pc=0x0c0c6224u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c6228u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6228u) { target=s->pc; goto dispatch; }
goto P_0c0c6228;
P_0c0c6226: /* original e401, guest PC 0x0c0c6226 */
if(!s->budget--) { s->failed_pc=0x0c0c6226u; return 0; }
r[4]=0x00000001u;
goto P_0c0c6228;
P_0c0c6228: /* original 4c08, guest PC 0x0c0c6228 */
if(!s->budget--) { s->failed_pc=0x0c0c6228u; return 0; }
r[12]<<=2;
goto P_0c0c622a;
P_0c0c622a: /* original 4c00, guest PC 0x0c0c622a */
if(!s->budget--) { s->failed_pc=0x0c0c622au; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c0c622c;
P_0c0c622c: /* original 3cbc, guest PC 0x0c0c622c */
if(!s->budget--) { s->failed_pc=0x0c0c622cu; return 0; }
r[12]+=r[11];
goto P_0c0c622e;
P_0c0c622e: /* original 63c2, guest PC 0x0c0c622e */
if(!s->budget--) { s->failed_pc=0x0c0c622eu; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c0c6230;
P_0c0c6230: /* original 2932, guest PC 0x0c0c6230 */
if(!s->budget--) { s->failed_pc=0x0c0c6230u; return 0; }
write(ram,r[9],r[3],4);
goto P_0c0c6232;
P_0c0c6232: /* original d314, guest PC 0x0c0c6232 */
if(!s->budget--) { s->failed_pc=0x0c0c6232u; return 0; }
r[3]=read(ram,0x0c0c6284u,4);
goto P_0c0c6234;
P_0c0c6234: /* original 64f2, guest PC 0x0c0c6234 */
if(!s->budget--) { s->failed_pc=0x0c0c6234u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c6236;
P_0c0c6236: /* original 430b, guest PC 0x0c0c6236 */
if(!s->budget--) { s->failed_pc=0x0c0c6236u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c623au;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c623au) { target=s->pc; goto dispatch; }
goto P_0c0c623a;
P_0c0c6238: /* original 6442, guest PC 0x0c0c6238 */
if(!s->budget--) { s->failed_pc=0x0c0c6238u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c623a;
P_0c0c623a: /* original a002, guest PC 0x0c0c623a */
if(!s->budget--) { s->failed_pc=0x0c0c623au; return 0; }
goto P_0c0c6242;
P_0c0c623c: /* original 0009, guest PC 0x0c0c623c */
if(!s->budget--) { s->failed_pc=0x0c0c623cu; return 0; }
goto P_0c0c623e;
P_0c0c623e: /* original afcf, guest PC 0x0c0c623e */
if(!s->budget--) { s->failed_pc=0x0c0c623eu; return 0; }
r[12]+=0x00000001u;
goto P_0c0c61e0;
P_0c0c6240: /* original 7c01, guest PC 0x0c0c6240 */
if(!s->budget--) { s->failed_pc=0x0c0c6240u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c6242;
P_0c0c6242: /* original 7f04, guest PC 0x0c0c6242 */
if(!s->budget--) { s->failed_pc=0x0c0c6242u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c6244;
P_0c0c6244: /* original 4f26, guest PC 0x0c0c6244 */
if(!s->budget--) { s->failed_pc=0x0c0c6244u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c6246;
P_0c0c6246: /* original 68f6, guest PC 0x0c0c6246 */
if(!s->budget--) { s->failed_pc=0x0c0c6246u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c6248;
P_0c0c6248: /* original 69f6, guest PC 0x0c0c6248 */
if(!s->budget--) { s->failed_pc=0x0c0c6248u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c624a;
P_0c0c624a: /* original 6af6, guest PC 0x0c0c624a */
if(!s->budget--) { s->failed_pc=0x0c0c624au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c624c;
P_0c0c624c: /* original 6bf6, guest PC 0x0c0c624c */
if(!s->budget--) { s->failed_pc=0x0c0c624cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c624e;
P_0c0c624e: /* original 6cf6, guest PC 0x0c0c624e */
if(!s->budget--) { s->failed_pc=0x0c0c624eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c6250;
P_0c0c6250: /* original 6df6, guest PC 0x0c0c6250 */
if(!s->budget--) { s->failed_pc=0x0c0c6250u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c6252;
P_0c0c6252: /* original 000b, guest PC 0x0c0c6252 */
if(!s->budget--) { s->failed_pc=0x0c0c6252u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c6254: /* original 6ef6, guest PC 0x0c0c6254 */
if(!s->budget--) { s->failed_pc=0x0c0c6254u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c6256u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c6256u; return 0; } return 1;
P_0c0c632e: /* original 2fe6, guest PC 0x0c0c632e */
if(!s->budget--) { s->failed_pc=0x0c0c632eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6330;
P_0c0c6330: /* original 6e53, guest PC 0x0c0c6330 */
if(!s->budget--) { s->failed_pc=0x0c0c6330u; return 0; }
r[14]=r[5];
goto P_0c0c6332;
P_0c0c6332: /* original 2fd6, guest PC 0x0c0c6332 */
if(!s->budget--) { s->failed_pc=0x0c0c6332u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6334;
P_0c0c6334: /* original 60e3, guest PC 0x0c0c6334 */
if(!s->budget--) { s->failed_pc=0x0c0c6334u; return 0; }
r[0]=r[14];
goto P_0c0c6336;
P_0c0c6336: /* original 2fc6, guest PC 0x0c0c6336 */
if(!s->budget--) { s->failed_pc=0x0c0c6336u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6338;
P_0c0c6338: /* original 8820, guest PC 0x0c0c6338 */
if(!s->budget--) { s->failed_pc=0x0c0c6338u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c0c633a;
P_0c0c633a: /* original 2fb6, guest PC 0x0c0c633a */
if(!s->budget--) { s->failed_pc=0x0c0c633au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c633c;
P_0c0c633c: /* original e500, guest PC 0x0c0c633c */
if(!s->budget--) { s->failed_pc=0x0c0c633cu; return 0; }
r[5]=0x00000000u;
goto P_0c0c633e;
P_0c0c633e: /* original 2fa6, guest PC 0x0c0c633e */
if(!s->budget--) { s->failed_pc=0x0c0c633eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6340;
P_0c0c6340: /* original 2f96, guest PC 0x0c0c6340 */
if(!s->budget--) { s->failed_pc=0x0c0c6340u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6342;
P_0c0c6342: /* original 6943, guest PC 0x0c0c6342 */
if(!s->budget--) { s->failed_pc=0x0c0c6342u; return 0; }
r[9]=r[4];
goto P_0c0c6344;
P_0c0c6344: /* original 2f86, guest PC 0x0c0c6344 */
if(!s->budget--) { s->failed_pc=0x0c0c6344u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c6346;
P_0c0c6346: /* original 6d93, guest PC 0x0c0c6346 */
if(!s->budget--) { s->failed_pc=0x0c0c6346u; return 0; }
r[13]=r[9];
goto P_0c0c6348;
P_0c0c6348: /* original 4f22, guest PC 0x0c0c6348 */
if(!s->budget--) { s->failed_pc=0x0c0c6348u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c634a;
P_0c0c634a: /* original db1c, guest PC 0x0c0c634a */
if(!s->budget--) { s->failed_pc=0x0c0c634au; return 0; }
r[11]=read(ram,0x0c0c63bcu,4);
goto P_0c0c634c;
P_0c0c634c: /* original dc1c, guest PC 0x0c0c634c */
if(!s->budget--) { s->failed_pc=0x0c0c634cu; return 0; }
r[12]=read(ram,0x0c0c63c0u,4);
goto P_0c0c634e;
P_0c0c634e: /* original d80e, guest PC 0x0c0c634e */
if(!s->budget--) { s->failed_pc=0x0c0c634eu; return 0; }
r[8]=read(ram,0x0c0c6388u,4);
goto P_0c0c6350;
P_0c0c6350: /* original d419, guest PC 0x0c0c6350 */
if(!s->budget--) { s->failed_pc=0x0c0c6350u; return 0; }
r[4]=read(ram,0x0c0c63b8u,4);
goto P_0c0c6352;
P_0c0c6352: /* original 8d03, guest PC 0x0c0c6352 */
if(!s->budget--) { s->failed_pc=0x0c0c6352u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000005u;
if(cond) { goto P_0c0c635c; }
goto P_0c0c6356;
P_0c0c6354: /* original 7d05, guest PC 0x0c0c6354 */
if(!s->budget--) { s->failed_pc=0x0c0c6354u; return 0; }
r[13]+=0x00000005u;
goto P_0c0c6356;
P_0c0c6356: /* original 60e3, guest PC 0x0c0c6356 */
if(!s->budget--) { s->failed_pc=0x0c0c6356u; return 0; }
r[0]=r[14];
goto P_0c0c6358;
P_0c0c6358: /* original 881f, guest PC 0x0c0c6358 */
if(!s->budget--) { s->failed_pc=0x0c0c6358u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001fu)!=0);
goto P_0c0c635a;
P_0c0c635a: /* original 8b09, guest PC 0x0c0c635a */
if(!s->budget--) { s->failed_pc=0x0c0c635au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6370; }
goto P_0c0c635c;
P_0c0c635c: /* original e3ff, guest PC 0x0c0c635c */
if(!s->budget--) { s->failed_pc=0x0c0c635cu; return 0; }
r[3]=0xffffffffu;
goto P_0c0c635e;
P_0c0c635e: /* original 2432, guest PC 0x0c0c635e */
if(!s->budget--) { s->failed_pc=0x0c0c635eu; return 0; }
write(ram,r[4],r[3],4);
goto P_0c0c6360;
P_0c0c6360: /* original 1c55, guest PC 0x0c0c6360 */
if(!s->budget--) { s->failed_pc=0x0c0c6360u; return 0; }
write(ram,r[12]+20,r[5],4);
goto P_0c0c6362;
P_0c0c6362: /* original 1c56, guest PC 0x0c0c6362 */
if(!s->budget--) { s->failed_pc=0x0c0c6362u; return 0; }
write(ram,r[12]+24,r[5],4);
goto P_0c0c6364;
P_0c0c6364: /* original 4b0b, guest PC 0x0c0c6364 */
if(!s->budget--) { s->failed_pc=0x0c0c6364u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c6368u;
r[4]=0x00000005u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6368u) { target=s->pc; goto dispatch; }
goto P_0c0c6368;
P_0c0c6366: /* original e405, guest PC 0x0c0c6366 */
if(!s->budget--) { s->failed_pc=0x0c0c6366u; return 0; }
r[4]=0x00000005u;
goto P_0c0c6368;
P_0c0c6368: /* original 4b0b, guest PC 0x0c0c6368 */
if(!s->budget--) { s->failed_pc=0x0c0c6368u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c636cu;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c636cu) { target=s->pc; goto dispatch; }
goto P_0c0c636c;
P_0c0c636a: /* original e406, guest PC 0x0c0c636a */
if(!s->budget--) { s->failed_pc=0x0c0c636au; return 0; }
r[4]=0x00000006u;
goto P_0c0c636c;
P_0c0c636c: /* original a046, guest PC 0x0c0c636c */
if(!s->budget--) { s->failed_pc=0x0c0c636cu; return 0; }
goto P_0c0c63fc;
P_0c0c636e: /* original 0009, guest PC 0x0c0c636e */
if(!s->budget--) { s->failed_pc=0x0c0c636eu; return 0; }
goto P_0c0c6370;
P_0c0c6370: /* original e30d, guest PC 0x0c0c6370 */
if(!s->budget--) { s->failed_pc=0x0c0c6370u; return 0; }
r[3]=0x0000000du;
goto P_0c0c6372;
P_0c0c6372: /* original 3e33, guest PC 0x0c0c6372 */
if(!s->budget--) { s->failed_pc=0x0c0c6372u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[3])!=0);
goto P_0c0c6374;
P_0c0c6374: /* original 8b00, guest PC 0x0c0c6374 */
if(!s->budget--) { s->failed_pc=0x0c0c6374u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6378; }
goto P_0c0c6376;
P_0c0c6376: /* original 3e38, guest PC 0x0c0c6376 */
if(!s->budget--) { s->failed_pc=0x0c0c6376u; return 0; }
r[14]-=r[3];
goto P_0c0c6378;
P_0c0c6378: /* original 2998, guest PC 0x0c0c6378 */
if(!s->budget--) { s->failed_pc=0x0c0c6378u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0c637a;
P_0c0c637a: /* original 8b23, guest PC 0x0c0c637a */
if(!s->budget--) { s->failed_pc=0x0c0c637au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c63c4; }
goto P_0c0c637c;
P_0c0c637c: /* original a029, guest PC 0x0c0c637c */
if(!s->budget--) { s->failed_pc=0x0c0c637cu; return 0; }
write(ram,r[4],r[14],4);
goto P_0c0c63d2;
P_0c0c637e: /* original 24e2, guest PC 0x0c0c637e */
if(!s->budget--) { s->failed_pc=0x0c0c637eu; return 0; }
write(ram,r[4],r[14],4);
if(!vf3_matrix_family(0x0c0c6380u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c6380u; return 0; } return 1;
P_0c0c63c4: /* original 6342, guest PC 0x0c0c63c4 */
if(!s->budget--) { s->failed_pc=0x0c0c63c4u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0c63c6;
P_0c0c63c6: /* original 3e30, guest PC 0x0c0c63c6 */
if(!s->budget--) { s->failed_pc=0x0c0c63c6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c0c63c8;
P_0c0c63c8: /* original 8b03, guest PC 0x0c0c63c8 */
if(!s->budget--) { s->failed_pc=0x0c0c63c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c63d2; }
goto P_0c0c63ca;
P_0c0c63ca: /* original 60d3, guest PC 0x0c0c63ca */
if(!s->budget--) { s->failed_pc=0x0c0c63cau; return 0; }
r[0]=r[13];
goto P_0c0c63cc;
P_0c0c63cc: /* original 4008, guest PC 0x0c0c63cc */
if(!s->budget--) { s->failed_pc=0x0c0c63ccu; return 0; }
r[0]<<=2;
goto P_0c0c63ce;
P_0c0c63ce: /* original a040, guest PC 0x0c0c63ce */
if(!s->budget--) { s->failed_pc=0x0c0c63ceu; return 0; }
write(ram,r[12]+r[0],r[5],4);
goto P_0c0c6452;
P_0c0c63d0: /* original 0c56, guest PC 0x0c0c63d0 */
if(!s->budget--) { s->failed_pc=0x0c0c63d0u; return 0; }
write(ram,r[12]+r[0],r[5],4);
goto P_0c0c63d2;
P_0c0c63d2: /* original e01c, guest PC 0x0c0c63d2 */
if(!s->budget--) { s->failed_pc=0x0c0c63d2u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c63d4;
P_0c0c63d4: /* original 008c, guest PC 0x0c0c63d4 */
if(!s->budget--) { s->failed_pc=0x0c0c63d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[8]+r[0],1);
goto P_0c0c63d6;
P_0c0c63d6: /* original e40f, guest PC 0x0c0c63d6 */
if(!s->budget--) { s->failed_pc=0x0c0c63d6u; return 0; }
r[4]=0x0000000fu;
goto P_0c0c63d8;
P_0c0c63d8: /* original 600c, guest PC 0x0c0c63d8 */
if(!s->budget--) { s->failed_pc=0x0c0c63d8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c63da;
P_0c0c63da: /* original 2409, guest PC 0x0c0c63da */
if(!s->budget--) { s->failed_pc=0x0c0c63dau; return 0; }
r[4]&=r[0];
goto P_0c0c63dc;
P_0c0c63dc: /* original 6043, guest PC 0x0c0c63dc */
if(!s->budget--) { s->failed_pc=0x0c0c63dcu; return 0; }
r[0]=r[4];
goto P_0c0c63de;
P_0c0c63de: /* original 8802, guest PC 0x0c0c63de */
if(!s->budget--) { s->failed_pc=0x0c0c63deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c63e0;
P_0c0c63e0: /* original 890b, guest PC 0x0c0c63e0 */
if(!s->budget--) { s->failed_pc=0x0c0c63e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c63fa; }
goto P_0c0c63e2;
P_0c0c63e2: /* original 6043, guest PC 0x0c0c63e2 */
if(!s->budget--) { s->failed_pc=0x0c0c63e2u; return 0; }
r[0]=r[4];
goto P_0c0c63e4;
P_0c0c63e4: /* original 8804, guest PC 0x0c0c63e4 */
if(!s->budget--) { s->failed_pc=0x0c0c63e4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0c63e6;
P_0c0c63e6: /* original 8908, guest PC 0x0c0c63e6 */
if(!s->budget--) { s->failed_pc=0x0c0c63e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c63fa; }
goto P_0c0c63e8;
P_0c0c63e8: /* original 6043, guest PC 0x0c0c63e8 */
if(!s->budget--) { s->failed_pc=0x0c0c63e8u; return 0; }
r[0]=r[4];
goto P_0c0c63ea;
P_0c0c63ea: /* original 8807, guest PC 0x0c0c63ea */
if(!s->budget--) { s->failed_pc=0x0c0c63eau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0c63ec;
P_0c0c63ec: /* original 8905, guest PC 0x0c0c63ec */
if(!s->budget--) { s->failed_pc=0x0c0c63ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c63fa; }
goto P_0c0c63ee;
P_0c0c63ee: /* original 6043, guest PC 0x0c0c63ee */
if(!s->budget--) { s->failed_pc=0x0c0c63eeu; return 0; }
r[0]=r[4];
goto P_0c0c63f0;
P_0c0c63f0: /* original 8808, guest PC 0x0c0c63f0 */
if(!s->budget--) { s->failed_pc=0x0c0c63f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0c63f2;
P_0c0c63f2: /* original 8902, guest PC 0x0c0c63f2 */
if(!s->budget--) { s->failed_pc=0x0c0c63f2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c63fa; }
goto P_0c0c63f4;
P_0c0c63f4: /* original 6043, guest PC 0x0c0c63f4 */
if(!s->budget--) { s->failed_pc=0x0c0c63f4u; return 0; }
r[0]=r[4];
goto P_0c0c63f6;
P_0c0c63f6: /* original 880e, guest PC 0x0c0c63f6 */
if(!s->budget--) { s->failed_pc=0x0c0c63f6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c0c63f8;
P_0c0c63f8: /* original 8b00, guest PC 0x0c0c63f8 */
if(!s->budget--) { s->failed_pc=0x0c0c63f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c63fc; }
goto P_0c0c63fa;
P_0c0c63fa: /* original 7e0d, guest PC 0x0c0c63fa */
if(!s->budget--) { s->failed_pc=0x0c0c63fau; return 0; }
r[14]+=0x0000000du;
goto P_0c0c63fc;
P_0c0c63fc: /* original d32f, guest PC 0x0c0c63fc */
if(!s->budget--) { s->failed_pc=0x0c0c63fcu; return 0; }
r[3]=read(ram,0x0c0c64bcu,4);
goto P_0c0c63fe;
P_0c0c63fe: /* original 6ae3, guest PC 0x0c0c63fe */
if(!s->budget--) { s->failed_pc=0x0c0c63feu; return 0; }
r[10]=r[14];
goto P_0c0c6400;
P_0c0c6400: /* original 4a08, guest PC 0x0c0c6400 */
if(!s->budget--) { s->failed_pc=0x0c0c6400u; return 0; }
r[10]<<=2;
goto P_0c0c6402;
P_0c0c6402: /* original 3a3c, guest PC 0x0c0c6402 */
if(!s->budget--) { s->failed_pc=0x0c0c6402u; return 0; }
r[10]+=r[3];
goto P_0c0c6404;
P_0c0c6404: /* original 62a2, guest PC 0x0c0c6404 */
if(!s->budget--) { s->failed_pc=0x0c0c6404u; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c0c6406;
P_0c0c6406: /* original 2228, guest PC 0x0c0c6406 */
if(!s->budget--) { s->failed_pc=0x0c0c6406u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c6408;
P_0c0c6408: /* original 892b, guest PC 0x0c0c6408 */
if(!s->budget--) { s->failed_pc=0x0c0c6408u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6462; }
goto P_0c0c640a;
P_0c0c640a: /* original 60d3, guest PC 0x0c0c640a */
if(!s->budget--) { s->failed_pc=0x0c0c640au; return 0; }
r[0]=r[13];
goto P_0c0c640c;
P_0c0c640c: /* original 4008, guest PC 0x0c0c640c */
if(!s->budget--) { s->failed_pc=0x0c0c640cu; return 0; }
r[0]<<=2;
goto P_0c0c640e;
P_0c0c640e: /* original 61a2, guest PC 0x0c0c640e */
if(!s->budget--) { s->failed_pc=0x0c0c640eu; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c0c6410;
P_0c0c6410: /* original 02ce, guest PC 0x0c0c6410 */
if(!s->budget--) { s->failed_pc=0x0c0c6410u; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0c6412;
P_0c0c6412: /* original 3210, guest PC 0x0c0c6412 */
if(!s->budget--) { s->failed_pc=0x0c0c6412u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c0c6414;
P_0c0c6414: /* original 8927, guest PC 0x0c0c6414 */
if(!s->budget--) { s->failed_pc=0x0c0c6414u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6466; }
goto P_0c0c6416;
P_0c0c6416: /* original d02b, guest PC 0x0c0c6416 */
if(!s->budget--) { s->failed_pc=0x0c0c6416u; return 0; }
r[0]=read(ram,0x0c0c64c4u,4);
goto P_0c0c6418;
P_0c0c6418: /* original d229, guest PC 0x0c0c6418 */
if(!s->budget--) { s->failed_pc=0x0c0c6418u; return 0; }
r[2]=read(ram,0x0c0c64c0u,4);
goto P_0c0c641a;
P_0c0c641a: /* original 6502, guest PC 0x0c0c641a */
if(!s->budget--) { s->failed_pc=0x0c0c641au; return 0; }
tmp=read(ram,r[0],4);
r[5]=tmp;
goto P_0c0c641c;
P_0c0c641c: /* original d32a, guest PC 0x0c0c641c */
if(!s->budget--) { s->failed_pc=0x0c0c641cu; return 0; }
r[3]=read(ram,0x0c0c64c8u,4);
goto P_0c0c641e;
P_0c0c641e: /* original 352c, guest PC 0x0c0c641e */
if(!s->budget--) { s->failed_pc=0x0c0c641eu; return 0; }
r[5]+=r[2];
goto P_0c0c6420;
P_0c0c6420: /* original 430b, guest PC 0x0c0c6420 */
if(!s->budget--) { s->failed_pc=0x0c0c6420u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6424u;
tmp=read(ram,r[10],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6424u) { target=s->pc; goto dispatch; }
goto P_0c0c6424;
P_0c0c6422: /* original 64a2, guest PC 0x0c0c6422 */
if(!s->budget--) { s->failed_pc=0x0c0c6422u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0c6424;
P_0c0c6424: /* original 4b0b, guest PC 0x0c0c6424 */
if(!s->budget--) { s->failed_pc=0x0c0c6424u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c6428u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6428u) { target=s->pc; goto dispatch; }
goto P_0c0c6428;
P_0c0c6426: /* original 64d3, guest PC 0x0c0c6426 */
if(!s->budget--) { s->failed_pc=0x0c0c6426u; return 0; }
r[4]=r[13];
goto P_0c0c6428;
P_0c0c6428: /* original d226, guest PC 0x0c0c6428 */
if(!s->budget--) { s->failed_pc=0x0c0c6428u; return 0; }
r[2]=read(ram,0x0c0c64c4u,4);
goto P_0c0c642a;
P_0c0c642a: /* original 65d3, guest PC 0x0c0c642a */
if(!s->budget--) { s->failed_pc=0x0c0c642au; return 0; }
r[5]=r[13];
goto P_0c0c642c;
P_0c0c642c: /* original d127, guest PC 0x0c0c642c */
if(!s->budget--) { s->failed_pc=0x0c0c642cu; return 0; }
r[1]=read(ram,0x0c0c64ccu,4);
goto P_0c0c642e;
P_0c0c642e: /* original 6422, guest PC 0x0c0c642e */
if(!s->budget--) { s->failed_pc=0x0c0c642eu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0c6430;
P_0c0c6430: /* original d323, guest PC 0x0c0c6430 */
if(!s->budget--) { s->failed_pc=0x0c0c6430u; return 0; }
r[3]=read(ram,0x0c0c64c0u,4);
goto P_0c0c6432;
P_0c0c6432: /* original 410b, guest PC 0x0c0c6432 */
if(!s->budget--) { s->failed_pc=0x0c0c6432u; return 0; }
target=r[1];
r[16]=code_base|0x0c0c6436u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6436u) { target=s->pc; goto dispatch; }
goto P_0c0c6436;
P_0c0c6434: /* original 343c, guest PC 0x0c0c6434 */
if(!s->budget--) { s->failed_pc=0x0c0c6434u; return 0; }
r[4]+=r[3];
goto P_0c0c6436;
P_0c0c6436: /* original 2008, guest PC 0x0c0c6436 */
if(!s->budget--) { s->failed_pc=0x0c0c6436u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c6438;
P_0c0c6438: /* original 8903, guest PC 0x0c0c6438 */
if(!s->budget--) { s->failed_pc=0x0c0c6438u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6442; }
goto P_0c0c643a;
P_0c0c643a: /* original d225, guest PC 0x0c0c643a */
if(!s->budget--) { s->failed_pc=0x0c0c643au; return 0; }
r[2]=read(ram,0x0c0c64d0u,4);
goto P_0c0c643c;
P_0c0c643c: /* original 953c, guest PC 0x0c0c643c */
if(!s->budget--) { s->failed_pc=0x0c0c643cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c64b8u,2);
goto P_0c0c643e;
P_0c0c643e: /* original 420b, guest PC 0x0c0c643e */
if(!s->budget--) { s->failed_pc=0x0c0c643eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c6442u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6442u) { target=s->pc; goto dispatch; }
goto P_0c0c6442;
P_0c0c6440: /* original e401, guest PC 0x0c0c6440 */
if(!s->budget--) { s->failed_pc=0x0c0c6440u; return 0; }
r[4]=0x00000001u;
goto P_0c0c6442;
P_0c0c6442: /* original 60d3, guest PC 0x0c0c6442 */
if(!s->budget--) { s->failed_pc=0x0c0c6442u; return 0; }
r[0]=r[13];
goto P_0c0c6444;
P_0c0c6444: /* original 4008, guest PC 0x0c0c6444 */
if(!s->budget--) { s->failed_pc=0x0c0c6444u; return 0; }
r[0]<<=2;
goto P_0c0c6446;
P_0c0c6446: /* original 6203, guest PC 0x0c0c6446 */
if(!s->budget--) { s->failed_pc=0x0c0c6446u; return 0; }
r[2]=r[0];
goto P_0c0c6448;
P_0c0c6448: /* original d01c, guest PC 0x0c0c6448 */
if(!s->budget--) { s->failed_pc=0x0c0c6448u; return 0; }
r[0]=read(ram,0x0c0c64bcu,4);
goto P_0c0c644a;
P_0c0c644a: /* original 4e08, guest PC 0x0c0c644a */
if(!s->budget--) { s->failed_pc=0x0c0c644au; return 0; }
r[14]<<=2;
goto P_0c0c644c;
P_0c0c644c: /* original 03ee, guest PC 0x0c0c644c */
if(!s->budget--) { s->failed_pc=0x0c0c644cu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0c644e;
P_0c0c644e: /* original 32cc, guest PC 0x0c0c644e */
if(!s->budget--) { s->failed_pc=0x0c0c644eu; return 0; }
r[2]+=r[12];
goto P_0c0c6450;
P_0c0c6450: /* original 2232, guest PC 0x0c0c6450 */
if(!s->budget--) { s->failed_pc=0x0c0c6450u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0c6452;
P_0c0c6452: /* original 9332, guest PC 0x0c0c6452 */
if(!s->budget--) { s->failed_pc=0x0c0c6452u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c64bau,2);
goto P_0c0c6454;
P_0c0c6454: /* original 7906, guest PC 0x0c0c6454 */
if(!s->budget--) { s->failed_pc=0x0c0c6454u; return 0; }
r[9]+=0x00000006u;
goto P_0c0c6456;
P_0c0c6456: /* original 4908, guest PC 0x0c0c6456 */
if(!s->budget--) { s->failed_pc=0x0c0c6456u; return 0; }
r[9]<<=2;
goto P_0c0c6458;
P_0c0c6458: /* original 338c, guest PC 0x0c0c6458 */
if(!s->budget--) { s->failed_pc=0x0c0c6458u; return 0; }
r[3]+=r[8];
goto P_0c0c645a;
P_0c0c645a: /* original e2ff, guest PC 0x0c0c645a */
if(!s->budget--) { s->failed_pc=0x0c0c645au; return 0; }
r[2]=0xffffffffu;
goto P_0c0c645c;
P_0c0c645c: /* original 393c, guest PC 0x0c0c645c */
if(!s->budget--) { s->failed_pc=0x0c0c645cu; return 0; }
r[9]+=r[3];
goto P_0c0c645e;
P_0c0c645e: /* original a002, guest PC 0x0c0c645e */
if(!s->budget--) { s->failed_pc=0x0c0c645eu; return 0; }
write(ram,r[9],r[2],4);
goto P_0c0c6466;
P_0c0c6460: /* original 2922, guest PC 0x0c0c6460 */
if(!s->budget--) { s->failed_pc=0x0c0c6460u; return 0; }
write(ram,r[9],r[2],4);
goto P_0c0c6462;
P_0c0c6462: /* original 4b0b, guest PC 0x0c0c6462 */
if(!s->budget--) { s->failed_pc=0x0c0c6462u; return 0; }
target=r[11];
r[16]=code_base|0x0c0c6466u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6466u) { target=s->pc; goto dispatch; }
goto P_0c0c6466;
P_0c0c6464: /* original 64d3, guest PC 0x0c0c6464 */
if(!s->budget--) { s->failed_pc=0x0c0c6464u; return 0; }
r[4]=r[13];
goto P_0c0c6466;
P_0c0c6466: /* original 4f26, guest PC 0x0c0c6466 */
if(!s->budget--) { s->failed_pc=0x0c0c6466u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c6468;
P_0c0c6468: /* original 68f6, guest PC 0x0c0c6468 */
if(!s->budget--) { s->failed_pc=0x0c0c6468u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c646a;
P_0c0c646a: /* original 69f6, guest PC 0x0c0c646a */
if(!s->budget--) { s->failed_pc=0x0c0c646au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c646c;
P_0c0c646c: /* original 6af6, guest PC 0x0c0c646c */
if(!s->budget--) { s->failed_pc=0x0c0c646cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c646e;
P_0c0c646e: /* original 6bf6, guest PC 0x0c0c646e */
if(!s->budget--) { s->failed_pc=0x0c0c646eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c6470;
P_0c0c6470: /* original 6cf6, guest PC 0x0c0c6470 */
if(!s->budget--) { s->failed_pc=0x0c0c6470u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c6472;
P_0c0c6472: /* original 6df6, guest PC 0x0c0c6472 */
if(!s->budget--) { s->failed_pc=0x0c0c6472u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c6474;
P_0c0c6474: /* original 000b, guest PC 0x0c0c6474 */
if(!s->budget--) { s->failed_pc=0x0c0c6474u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c6476: /* original 6ef6, guest PC 0x0c0c6476 */
if(!s->budget--) { s->failed_pc=0x0c0c6476u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c6478u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c6478u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
