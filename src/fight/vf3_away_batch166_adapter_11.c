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
int vf3_away_batch166_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c7558u: goto P_0c0c7558;
case 0x0c0c755au: goto P_0c0c755a;
case 0x0c0c755cu: goto P_0c0c755c;
case 0x0c0c755eu: goto P_0c0c755e;
case 0x0c0c7560u: goto P_0c0c7560;
case 0x0c0c7562u: goto P_0c0c7562;
case 0x0c0c7564u: goto P_0c0c7564;
case 0x0c0c7566u: goto P_0c0c7566;
case 0x0c0c7568u: goto P_0c0c7568;
case 0x0c0c756au: goto P_0c0c756a;
case 0x0c0c756cu: goto P_0c0c756c;
case 0x0c0c756eu: goto P_0c0c756e;
case 0x0c0c7570u: goto P_0c0c7570;
case 0x0c0c7572u: goto P_0c0c7572;
case 0x0c0c7574u: goto P_0c0c7574;
case 0x0c0c7576u: goto P_0c0c7576;
case 0x0c0c7578u: goto P_0c0c7578;
case 0x0c0c757au: goto P_0c0c757a;
case 0x0c0c757cu: goto P_0c0c757c;
case 0x0c0c757eu: goto P_0c0c757e;
case 0x0c0c7580u: goto P_0c0c7580;
case 0x0c0c7582u: goto P_0c0c7582;
case 0x0c0c7584u: goto P_0c0c7584;
case 0x0c0c7586u: goto P_0c0c7586;
case 0x0c0c7588u: goto P_0c0c7588;
case 0x0c0c758au: goto P_0c0c758a;
case 0x0c0c758cu: goto P_0c0c758c;
case 0x0c0c758eu: goto P_0c0c758e;
case 0x0c0c7590u: goto P_0c0c7590;
case 0x0c0c7592u: goto P_0c0c7592;
case 0x0c0c7594u: goto P_0c0c7594;
case 0x0c0c7596u: goto P_0c0c7596;
case 0x0c0c7598u: goto P_0c0c7598;
case 0x0c0c759au: goto P_0c0c759a;
case 0x0c0c759cu: goto P_0c0c759c;
case 0x0c0c759eu: goto P_0c0c759e;
case 0x0c0c75a0u: goto P_0c0c75a0;
case 0x0c0c75a2u: goto P_0c0c75a2;
case 0x0c0c75a4u: goto P_0c0c75a4;
case 0x0c0c75a6u: goto P_0c0c75a6;
case 0x0c0c75a8u: goto P_0c0c75a8;
case 0x0c0c75aau: goto P_0c0c75aa;
case 0x0c0c75acu: goto P_0c0c75ac;
case 0x0c0c75aeu: goto P_0c0c75ae;
case 0x0c0c75b0u: goto P_0c0c75b0;
case 0x0c0c75b2u: goto P_0c0c75b2;
case 0x0c0c75b4u: goto P_0c0c75b4;
case 0x0c0c75b6u: goto P_0c0c75b6;
case 0x0c0c75b8u: goto P_0c0c75b8;
case 0x0c0c75bau: goto P_0c0c75ba;
case 0x0c0c75bcu: goto P_0c0c75bc;
case 0x0c0c75beu: goto P_0c0c75be;
case 0x0c0c75c0u: goto P_0c0c75c0;
case 0x0c0c75c2u: goto P_0c0c75c2;
case 0x0c0c75c4u: goto P_0c0c75c4;
case 0x0c0c75c6u: goto P_0c0c75c6;
case 0x0c0c75c8u: goto P_0c0c75c8;
case 0x0c0c75cau: goto P_0c0c75ca;
case 0x0c0c75ccu: goto P_0c0c75cc;
case 0x0c0c75ceu: goto P_0c0c75ce;
case 0x0c0c75d0u: goto P_0c0c75d0;
case 0x0c0c75d2u: goto P_0c0c75d2;
case 0x0c0c75d4u: goto P_0c0c75d4;
case 0x0c0c75d6u: goto P_0c0c75d6;
case 0x0c0c75d8u: goto P_0c0c75d8;
case 0x0c0c75dau: goto P_0c0c75da;
case 0x0c0c75dcu: goto P_0c0c75dc;
case 0x0c0c75deu: goto P_0c0c75de;
case 0x0c0c75e0u: goto P_0c0c75e0;
case 0x0c0c75e2u: goto P_0c0c75e2;
case 0x0c0c75e4u: goto P_0c0c75e4;
case 0x0c0c75e6u: goto P_0c0c75e6;
case 0x0c0c75e8u: goto P_0c0c75e8;
case 0x0c0c75eau: goto P_0c0c75ea;
case 0x0c0c75ecu: goto P_0c0c75ec;
case 0x0c0c75eeu: goto P_0c0c75ee;
case 0x0c0c75f0u: goto P_0c0c75f0;
case 0x0c0c75f2u: goto P_0c0c75f2;
case 0x0c0c75f4u: goto P_0c0c75f4;
case 0x0c0c75f6u: goto P_0c0c75f6;
case 0x0c0c75f8u: goto P_0c0c75f8;
case 0x0c0c75fau: goto P_0c0c75fa;
case 0x0c0c75fcu: goto P_0c0c75fc;
case 0x0c0c75feu: goto P_0c0c75fe;
case 0x0c0c7600u: goto P_0c0c7600;
case 0x0c0c7602u: goto P_0c0c7602;
case 0x0c0c7604u: goto P_0c0c7604;
case 0x0c0c7606u: goto P_0c0c7606;
case 0x0c0c7608u: goto P_0c0c7608;
case 0x0c0c760au: goto P_0c0c760a;
case 0x0c0c760cu: goto P_0c0c760c;
case 0x0c0c760eu: goto P_0c0c760e;
case 0x0c0c7610u: goto P_0c0c7610;
case 0x0c0c7612u: goto P_0c0c7612;
case 0x0c0c7614u: goto P_0c0c7614;
case 0x0c0c7616u: goto P_0c0c7616;
case 0x0c0c7618u: goto P_0c0c7618;
case 0x0c0c761au: goto P_0c0c761a;
case 0x0c0c761cu: goto P_0c0c761c;
case 0x0c0c7802u: goto P_0c0c7802;
case 0x0c0c7804u: goto P_0c0c7804;
case 0x0c0c7806u: goto P_0c0c7806;
case 0x0c0c7808u: goto P_0c0c7808;
case 0x0c0c780au: goto P_0c0c780a;
case 0x0c0c780cu: goto P_0c0c780c;
case 0x0c0c780eu: goto P_0c0c780e;
case 0x0c0c7810u: goto P_0c0c7810;
case 0x0c0c7812u: goto P_0c0c7812;
case 0x0c0c7814u: goto P_0c0c7814;
case 0x0c0c7816u: goto P_0c0c7816;
case 0x0c0c7818u: goto P_0c0c7818;
case 0x0c0c781au: goto P_0c0c781a;
case 0x0c0c781cu: goto P_0c0c781c;
case 0x0c0c781eu: goto P_0c0c781e;
case 0x0c0c7820u: goto P_0c0c7820;
case 0x0c0c7822u: goto P_0c0c7822;
case 0x0c0c7824u: goto P_0c0c7824;
case 0x0c0c7826u: goto P_0c0c7826;
case 0x0c0c7828u: goto P_0c0c7828;
case 0x0c0c782au: goto P_0c0c782a;
case 0x0c0c782cu: goto P_0c0c782c;
case 0x0c0c782eu: goto P_0c0c782e;
case 0x0c0c7830u: goto P_0c0c7830;
case 0x0c0c7832u: goto P_0c0c7832;
case 0x0c0c7834u: goto P_0c0c7834;
case 0x0c0c7836u: goto P_0c0c7836;
case 0x0c0c7838u: goto P_0c0c7838;
case 0x0c0c783au: goto P_0c0c783a;
case 0x0c0c783cu: goto P_0c0c783c;
case 0x0c0c783eu: goto P_0c0c783e;
case 0x0c0c7840u: goto P_0c0c7840;
case 0x0c0c7842u: goto P_0c0c7842;
case 0x0c0c7844u: goto P_0c0c7844;
case 0x0c0c7846u: goto P_0c0c7846;
case 0x0c0c7848u: goto P_0c0c7848;
case 0x0c0c784au: goto P_0c0c784a;
case 0x0c0c784cu: goto P_0c0c784c;
case 0x0c0c784eu: goto P_0c0c784e;
case 0x0c0c7850u: goto P_0c0c7850;
case 0x0c0c7852u: goto P_0c0c7852;
case 0x0c0c7854u: goto P_0c0c7854;
case 0x0c0c7856u: goto P_0c0c7856;
case 0x0c0c7858u: goto P_0c0c7858;
case 0x0c0c785au: goto P_0c0c785a;
case 0x0c0c785cu: goto P_0c0c785c;
case 0x0c0c78d0u: goto P_0c0c78d0;
case 0x0c0c78d2u: goto P_0c0c78d2;
case 0x0c0c78d4u: goto P_0c0c78d4;
case 0x0c0c78d6u: goto P_0c0c78d6;
case 0x0c0c78d8u: goto P_0c0c78d8;
case 0x0c0c78dau: goto P_0c0c78da;
case 0x0c0c78dcu: goto P_0c0c78dc;
case 0x0c0c78deu: goto P_0c0c78de;
case 0x0c0c78e0u: goto P_0c0c78e0;
case 0x0c0c78e2u: goto P_0c0c78e2;
case 0x0c0c78e4u: goto P_0c0c78e4;
case 0x0c0c78e6u: goto P_0c0c78e6;
case 0x0c0c78e8u: goto P_0c0c78e8;
case 0x0c0c78eau: goto P_0c0c78ea;
case 0x0c0c78ecu: goto P_0c0c78ec;
case 0x0c0c78eeu: goto P_0c0c78ee;
case 0x0c0c78f0u: goto P_0c0c78f0;
case 0x0c0c78f2u: goto P_0c0c78f2;
case 0x0c0c78f4u: goto P_0c0c78f4;
case 0x0c0c78f6u: goto P_0c0c78f6;
case 0x0c0c78f8u: goto P_0c0c78f8;
case 0x0c0c78fau: goto P_0c0c78fa;
case 0x0c0c78fcu: goto P_0c0c78fc;
case 0x0c0c78feu: goto P_0c0c78fe;
case 0x0c0c7900u: goto P_0c0c7900;
case 0x0c0c7902u: goto P_0c0c7902;
case 0x0c0c7904u: goto P_0c0c7904;
case 0x0c0c7906u: goto P_0c0c7906;
case 0x0c0c7908u: goto P_0c0c7908;
case 0x0c0c790au: goto P_0c0c790a;
case 0x0c0c790cu: goto P_0c0c790c;
case 0x0c0c790eu: goto P_0c0c790e;
case 0x0c0c7910u: goto P_0c0c7910;
case 0x0c0c7912u: goto P_0c0c7912;
case 0x0c0c7914u: goto P_0c0c7914;
case 0x0c0c7916u: goto P_0c0c7916;
case 0x0c0c7918u: goto P_0c0c7918;
case 0x0c0c791au: goto P_0c0c791a;
case 0x0c0c791cu: goto P_0c0c791c;
case 0x0c0c791eu: goto P_0c0c791e;
case 0x0c0c7920u: goto P_0c0c7920;
case 0x0c0c7922u: goto P_0c0c7922;
case 0x0c0c7924u: goto P_0c0c7924;
case 0x0c0c7926u: goto P_0c0c7926;
case 0x0c0c7928u: goto P_0c0c7928;
case 0x0c0c792au: goto P_0c0c792a;
case 0x0c0c792cu: goto P_0c0c792c;
case 0x0c0c792eu: goto P_0c0c792e;
case 0x0c0c7930u: goto P_0c0c7930;
case 0x0c0c7932u: goto P_0c0c7932;
case 0x0c0c7934u: goto P_0c0c7934;
case 0x0c0c7936u: goto P_0c0c7936;
case 0x0c0c7938u: goto P_0c0c7938;
case 0x0c0c793au: goto P_0c0c793a;
case 0x0c0c793cu: goto P_0c0c793c;
case 0x0c0c793eu: goto P_0c0c793e;
case 0x0c0c7940u: goto P_0c0c7940;
case 0x0c0c7942u: goto P_0c0c7942;
case 0x0c0c7944u: goto P_0c0c7944;
case 0x0c0c7946u: goto P_0c0c7946;
case 0x0c0c7948u: goto P_0c0c7948;
case 0x0c0c794au: goto P_0c0c794a;
case 0x0c0c794cu: goto P_0c0c794c;
case 0x0c0c794eu: goto P_0c0c794e;
case 0x0c0c7950u: goto P_0c0c7950;
case 0x0c0c7952u: goto P_0c0c7952;
case 0x0c0c7954u: goto P_0c0c7954;
case 0x0c0c7956u: goto P_0c0c7956;
case 0x0c0c7958u: goto P_0c0c7958;
case 0x0c0c795au: goto P_0c0c795a;
case 0x0c0c795cu: goto P_0c0c795c;
case 0x0c0c795eu: goto P_0c0c795e;
case 0x0c0c7960u: goto P_0c0c7960;
case 0x0c0c7962u: goto P_0c0c7962;
case 0x0c0c7964u: goto P_0c0c7964;
case 0x0c0c7966u: goto P_0c0c7966;
case 0x0c0c7968u: goto P_0c0c7968;
case 0x0c0c796au: goto P_0c0c796a;
case 0x0c0c796cu: goto P_0c0c796c;
case 0x0c0c796eu: goto P_0c0c796e;
case 0x0c0c7970u: goto P_0c0c7970;
case 0x0c0c7972u: goto P_0c0c7972;
case 0x0c0c7974u: goto P_0c0c7974;
case 0x0c0c7976u: goto P_0c0c7976;
case 0x0c0c7978u: goto P_0c0c7978;
case 0x0c0c797au: goto P_0c0c797a;
case 0x0c0c797cu: goto P_0c0c797c;
case 0x0c0c797eu: goto P_0c0c797e;
case 0x0c0c7980u: goto P_0c0c7980;
case 0x0c0c7982u: goto P_0c0c7982;
case 0x0c0c7984u: goto P_0c0c7984;
case 0x0c0c7986u: goto P_0c0c7986;
case 0x0c0c7988u: goto P_0c0c7988;
case 0x0c0c798au: goto P_0c0c798a;
case 0x0c0c798cu: goto P_0c0c798c;
case 0x0c0c798eu: goto P_0c0c798e;
case 0x0c0c7990u: goto P_0c0c7990;
case 0x0c0c7992u: goto P_0c0c7992;
case 0x0c0c7994u: goto P_0c0c7994;
case 0x0c0c7996u: goto P_0c0c7996;
case 0x0c0c7998u: goto P_0c0c7998;
case 0x0c0c799au: goto P_0c0c799a;
case 0x0c0c799cu: goto P_0c0c799c;
case 0x0c0c799eu: goto P_0c0c799e;
case 0x0c0c79a0u: goto P_0c0c79a0;
case 0x0c0c79a2u: goto P_0c0c79a2;
case 0x0c0c79a4u: goto P_0c0c79a4;
case 0x0c0c79a6u: goto P_0c0c79a6;
case 0x0c0c79a8u: goto P_0c0c79a8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c7558: /* original 2fe6, guest PC 0x0c0c7558 */
if(!s->budget--) { s->failed_pc=0x0c0c7558u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c755a;
P_0c0c755a: /* original 2fd6, guest PC 0x0c0c755a */
if(!s->budget--) { s->failed_pc=0x0c0c755au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c755c;
P_0c0c755c: /* original 2fc6, guest PC 0x0c0c755c */
if(!s->budget--) { s->failed_pc=0x0c0c755cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c755e;
P_0c0c755e: /* original 2fb6, guest PC 0x0c0c755e */
if(!s->budget--) { s->failed_pc=0x0c0c755eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7560;
P_0c0c7560: /* original de33, guest PC 0x0c0c7560 */
if(!s->budget--) { s->failed_pc=0x0c0c7560u; return 0; }
r[14]=read(ram,0x0c0c7630u,4);
goto P_0c0c7562;
P_0c0c7562: /* original 4f22, guest PC 0x0c0c7562 */
if(!s->budget--) { s->failed_pc=0x0c0c7562u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7564;
P_0c0c7564: /* original d333, guest PC 0x0c0c7564 */
if(!s->budget--) { s->failed_pc=0x0c0c7564u; return 0; }
r[3]=read(ram,0x0c0c7634u,4);
goto P_0c0c7566;
P_0c0c7566: /* original 7ffc, guest PC 0x0c0c7566 */
if(!s->budget--) { s->failed_pc=0x0c0c7566u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c7568;
P_0c0c7568: /* original 2f32, guest PC 0x0c0c7568 */
if(!s->budget--) { s->failed_pc=0x0c0c7568u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c756a;
P_0c0c756a: /* original 50e2, guest PC 0x0c0c756a */
if(!s->budget--) { s->failed_pc=0x0c0c756au; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c0c756c;
P_0c0c756c: /* original c804, guest PC 0x0c0c756c */
if(!s->budget--) { s->failed_pc=0x0c0c756cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0c756e;
P_0c0c756e: /* original 8d05, guest PC 0x0c0c756e */
if(!s->budget--) { s->failed_pc=0x0c0c756eu; return 0; }
cond=r[17]&1u;
r[5]=0x00000001u;
if(cond) { goto P_0c0c757c; }
goto P_0c0c7572;
P_0c0c7570: /* original e501, guest PC 0x0c0c7570 */
if(!s->budget--) { s->failed_pc=0x0c0c7570u; return 0; }
r[5]=0x00000001u;
goto P_0c0c7572;
P_0c0c7572: /* original d331, guest PC 0x0c0c7572 */
if(!s->budget--) { s->failed_pc=0x0c0c7572u; return 0; }
r[3]=read(ram,0x0c0c7638u,4);
goto P_0c0c7574;
P_0c0c7574: /* original 64f2, guest PC 0x0c0c7574 */
if(!s->budget--) { s->failed_pc=0x0c0c7574u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c7576;
P_0c0c7576: /* original 430b, guest PC 0x0c0c7576 */
if(!s->budget--) { s->failed_pc=0x0c0c7576u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c757au;
r[4]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c757au) { target=s->pc; goto dispatch; }
goto P_0c0c757a;
P_0c0c7578: /* original 7401, guest PC 0x0c0c7578 */
if(!s->budget--) { s->failed_pc=0x0c0c7578u; return 0; }
r[4]+=0x00000001u;
goto P_0c0c757a;
P_0c0c757a: /* original 650c, guest PC 0x0c0c757a */
if(!s->budget--) { s->failed_pc=0x0c0c757au; return 0; }
r[5]=r[0]&255u;
goto P_0c0c757c;
P_0c0c757c: /* original 9457, guest PC 0x0c0c757c */
if(!s->budget--) { s->failed_pc=0x0c0c757cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c762eu,2);
goto P_0c0c757e;
P_0c0c757e: /* original 6753, guest PC 0x0c0c757e */
if(!s->budget--) { s->failed_pc=0x0c0c757eu; return 0; }
r[7]=r[5];
goto P_0c0c7580;
P_0c0c7580: /* original 34ec, guest PC 0x0c0c7580 */
if(!s->budget--) { s->failed_pc=0x0c0c7580u; return 0; }
r[4]+=r[14];
goto P_0c0c7582;
P_0c0c7582: /* original ed09, guest PC 0x0c0c7582 */
if(!s->budget--) { s->failed_pc=0x0c0c7582u; return 0; }
r[13]=0x00000009u;
goto P_0c0c7584;
P_0c0c7584: /* original e600, guest PC 0x0c0c7584 */
if(!s->budget--) { s->failed_pc=0x0c0c7584u; return 0; }
r[6]=0x00000000u;
goto P_0c0c7586;
P_0c0c7586: /* original 2460, guest PC 0x0c0c7586 */
if(!s->budget--) { s->failed_pc=0x0c0c7586u; return 0; }
write(ram,r[4],r[6],1);
goto P_0c0c7588;
P_0c0c7588: /* original 4d10, guest PC 0x0c0c7588 */
if(!s->budget--) { s->failed_pc=0x0c0c7588u; return 0; }
--r[13];
r[17]=(r[17]&~1u)|((r[13]==0)!=0);
goto P_0c0c758a;
P_0c0c758a: /* original 7401, guest PC 0x0c0c758a */
if(!s->budget--) { s->failed_pc=0x0c0c758au; return 0; }
r[4]+=0x00000001u;
goto P_0c0c758c;
P_0c0c758c: /* original 8ffb, guest PC 0x0c0c758c */
if(!s->budget--) { s->failed_pc=0x0c0c758cu; return 0; }
cond=r[17]&1u;
r[6]+=0x00000001u;
if(!cond) { goto P_0c0c7586; }
goto P_0c0c7590;
P_0c0c758e: /* original 7601, guest PC 0x0c0c758e */
if(!s->budget--) { s->failed_pc=0x0c0c758eu; return 0; }
r[6]+=0x00000001u;
goto P_0c0c7590;
P_0c0c7590: /* original e603, guest PC 0x0c0c7590 */
if(!s->budget--) { s->failed_pc=0x0c0c7590u; return 0; }
r[6]=0x00000003u;
goto P_0c0c7592;
P_0c0c7592: /* original ed0a, guest PC 0x0c0c7592 */
if(!s->budget--) { s->failed_pc=0x0c0c7592u; return 0; }
r[13]=0x0000000au;
goto P_0c0c7594;
P_0c0c7594: /* original 24d0, guest PC 0x0c0c7594 */
if(!s->budget--) { s->failed_pc=0x0c0c7594u; return 0; }
write(ram,r[4],r[13],1);
goto P_0c0c7596;
P_0c0c7596: /* original 4610, guest PC 0x0c0c7596 */
if(!s->budget--) { s->failed_pc=0x0c0c7596u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c0c7598;
P_0c0c7598: /* original 7401, guest PC 0x0c0c7598 */
if(!s->budget--) { s->failed_pc=0x0c0c7598u; return 0; }
r[4]+=0x00000001u;
goto P_0c0c759a;
P_0c0c759a: /* original 8ffb, guest PC 0x0c0c759a */
if(!s->budget--) { s->failed_pc=0x0c0c759au; return 0; }
cond=r[17]&1u;
r[13]+=0x00000001u;
if(!cond) { goto P_0c0c7594; }
goto P_0c0c759e;
P_0c0c759c: /* original 7d01, guest PC 0x0c0c759c */
if(!s->budget--) { s->failed_pc=0x0c0c759cu; return 0; }
r[13]+=0x00000001u;
goto P_0c0c759e;
P_0c0c759e: /* original 77ff, guest PC 0x0c0c759e */
if(!s->budget--) { s->failed_pc=0x0c0c759eu; return 0; }
r[7]+=0xffffffffu;
goto P_0c0c75a0;
P_0c0c75a0: /* original 4715, guest PC 0x0c0c75a0 */
if(!s->budget--) { s->failed_pc=0x0c0c75a0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>0)!=0);
goto P_0c0c75a2;
P_0c0c75a2: /* original 89ee, guest PC 0x0c0c75a2 */
if(!s->budget--) { s->failed_pc=0x0c0c75a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7582; }
goto P_0c0c75a4;
P_0c0c75a4: /* original 9343, guest PC 0x0c0c75a4 */
if(!s->budget--) { s->failed_pc=0x0c0c75a4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c762eu,2);
goto P_0c0c75a6;
P_0c0c75a6: /* original ed0c, guest PC 0x0c0c75a6 */
if(!s->budget--) { s->failed_pc=0x0c0c75a6u; return 0; }
r[13]=0x0000000cu;
goto P_0c0c75a8;
P_0c0c75a8: /* original 6b53, guest PC 0x0c0c75a8 */
if(!s->budget--) { s->failed_pc=0x0c0c75a8u; return 0; }
r[11]=r[5];
goto P_0c0c75aa;
P_0c0c75aa: /* original 3e3c, guest PC 0x0c0c75aa */
if(!s->budget--) { s->failed_pc=0x0c0c75aau; return 0; }
r[14]+=r[3];
goto P_0c0c75ac;
P_0c0c75ac: /* original ec20, guest PC 0x0c0c75ac */
if(!s->budget--) { s->failed_pc=0x0c0c75acu; return 0; }
r[12]=0x00000020u;
goto P_0c0c75ae;
P_0c0c75ae: /* original d223, guest PC 0x0c0c75ae */
if(!s->budget--) { s->failed_pc=0x0c0c75aeu; return 0; }
r[2]=read(ram,0x0c0c763cu,4);
goto P_0c0c75b0;
P_0c0c75b0: /* original 420b, guest PC 0x0c0c75b0 */
if(!s->budget--) { s->failed_pc=0x0c0c75b0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c75b4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c75b4u) { target=s->pc; goto dispatch; }
goto P_0c0c75b4;
P_0c0c75b2: /* original 0009, guest PC 0x0c0c75b2 */
if(!s->budget--) { s->failed_pc=0x0c0c75b2u; return 0; }
goto P_0c0c75b4;
P_0c0c75b4: /* original e3f8, guest PC 0x0c0c75b4 */
if(!s->budget--) { s->failed_pc=0x0c0c75b4u; return 0; }
r[3]=0xfffffff8u;
goto P_0c0c75b6;
P_0c0c75b6: /* original 6503, guest PC 0x0c0c75b6 */
if(!s->budget--) { s->failed_pc=0x0c0c75b6u; return 0; }
r[5]=r[0];
goto P_0c0c75b8;
P_0c0c75b8: /* original 6403, guest PC 0x0c0c75b8 */
if(!s->budget--) { s->failed_pc=0x0c0c75b8u; return 0; }
r[4]=r[0];
goto P_0c0c75ba;
P_0c0c75ba: /* original 644c, guest PC 0x0c0c75ba */
if(!s->budget--) { s->failed_pc=0x0c0c75bau; return 0; }
r[4]=r[4]&255u;
goto P_0c0c75bc;
P_0c0c75bc: /* original d220, guest PC 0x0c0c75bc */
if(!s->budget--) { s->failed_pc=0x0c0c75bcu; return 0; }
r[2]=read(ram,0x0c0c7640u,4);
goto P_0c0c75be;
P_0c0c75be: /* original 453c, guest PC 0x0c0c75be */
if(!s->budget--) { s->failed_pc=0x0c0c75beu; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[5]>>((-r[3])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[3]&31u);
goto P_0c0c75c0;
P_0c0c75c0: /* original 6143, guest PC 0x0c0c75c0 */
if(!s->budget--) { s->failed_pc=0x0c0c75c0u; return 0; }
r[1]=r[4];
goto P_0c0c75c2;
P_0c0c75c2: /* original 655c, guest PC 0x0c0c75c2 */
if(!s->budget--) { s->failed_pc=0x0c0c75c2u; return 0; }
r[5]=r[5]&255u;
goto P_0c0c75c4;
P_0c0c75c4: /* original 420b, guest PC 0x0c0c75c4 */
if(!s->budget--) { s->failed_pc=0x0c0c75c4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c75c8u;
r[0]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c75c8u) { target=s->pc; goto dispatch; }
goto P_0c0c75c8;
P_0c0c75c6: /* original 60d3, guest PC 0x0c0c75c6 */
if(!s->budget--) { s->failed_pc=0x0c0c75c6u; return 0; }
r[0]=r[13];
goto P_0c0c75c8;
P_0c0c75c8: /* original 6603, guest PC 0x0c0c75c8 */
if(!s->budget--) { s->failed_pc=0x0c0c75c8u; return 0; }
r[6]=r[0];
goto P_0c0c75ca;
P_0c0c75ca: /* original 4600, guest PC 0x0c0c75ca */
if(!s->budget--) { s->failed_pc=0x0c0c75cau; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0c75cc;
P_0c0c75cc: /* original 6303, guest PC 0x0c0c75cc */
if(!s->budget--) { s->failed_pc=0x0c0c75ccu; return 0; }
r[3]=r[0];
goto P_0c0c75ce;
P_0c0c75ce: /* original 363c, guest PC 0x0c0c75ce */
if(!s->budget--) { s->failed_pc=0x0c0c75ceu; return 0; }
r[6]+=r[3];
goto P_0c0c75d0;
P_0c0c75d0: /* original d21b, guest PC 0x0c0c75d0 */
if(!s->budget--) { s->failed_pc=0x0c0c75d0u; return 0; }
r[2]=read(ram,0x0c0c7640u,4);
goto P_0c0c75d2;
P_0c0c75d2: /* original 4608, guest PC 0x0c0c75d2 */
if(!s->budget--) { s->failed_pc=0x0c0c75d2u; return 0; }
r[6]<<=2;
goto P_0c0c75d4;
P_0c0c75d4: /* original 6153, guest PC 0x0c0c75d4 */
if(!s->budget--) { s->failed_pc=0x0c0c75d4u; return 0; }
r[1]=r[5];
goto P_0c0c75d6;
P_0c0c75d6: /* original 3468, guest PC 0x0c0c75d6 */
if(!s->budget--) { s->failed_pc=0x0c0c75d6u; return 0; }
r[4]-=r[6];
goto P_0c0c75d8;
P_0c0c75d8: /* original 420b, guest PC 0x0c0c75d8 */
if(!s->budget--) { s->failed_pc=0x0c0c75d8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c75dcu;
r[0]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c75dcu) { target=s->pc; goto dispatch; }
goto P_0c0c75dc;
P_0c0c75da: /* original 60d3, guest PC 0x0c0c75da */
if(!s->budget--) { s->failed_pc=0x0c0c75dau; return 0; }
r[0]=r[13];
goto P_0c0c75dc;
P_0c0c75dc: /* original 6603, guest PC 0x0c0c75dc */
if(!s->budget--) { s->failed_pc=0x0c0c75dcu; return 0; }
r[6]=r[0];
goto P_0c0c75de;
P_0c0c75de: /* original 4600, guest PC 0x0c0c75de */
if(!s->budget--) { s->failed_pc=0x0c0c75deu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0c75e0;
P_0c0c75e0: /* original 6303, guest PC 0x0c0c75e0 */
if(!s->budget--) { s->failed_pc=0x0c0c75e0u; return 0; }
r[3]=r[0];
goto P_0c0c75e2;
P_0c0c75e2: /* original 363c, guest PC 0x0c0c75e2 */
if(!s->budget--) { s->failed_pc=0x0c0c75e2u; return 0; }
r[6]+=r[3];
goto P_0c0c75e4;
P_0c0c75e4: /* original 4608, guest PC 0x0c0c75e4 */
if(!s->budget--) { s->failed_pc=0x0c0c75e4u; return 0; }
r[6]<<=2;
goto P_0c0c75e6;
P_0c0c75e6: /* original 3568, guest PC 0x0c0c75e6 */
if(!s->budget--) { s->failed_pc=0x0c0c75e6u; return 0; }
r[5]-=r[6];
goto P_0c0c75e8;
P_0c0c75e8: /* original 6643, guest PC 0x0c0c75e8 */
if(!s->budget--) { s->failed_pc=0x0c0c75e8u; return 0; }
r[6]=r[4];
goto P_0c0c75ea;
P_0c0c75ea: /* original 6753, guest PC 0x0c0c75ea */
if(!s->budget--) { s->failed_pc=0x0c0c75eau; return 0; }
r[7]=r[5];
goto P_0c0c75ec;
P_0c0c75ec: /* original 37ec, guest PC 0x0c0c75ec */
if(!s->budget--) { s->failed_pc=0x0c0c75ecu; return 0; }
r[7]+=r[14];
goto P_0c0c75ee;
P_0c0c75ee: /* original 36ec, guest PC 0x0c0c75ee */
if(!s->budget--) { s->failed_pc=0x0c0c75eeu; return 0; }
r[6]+=r[14];
goto P_0c0c75f0;
P_0c0c75f0: /* original 2f62, guest PC 0x0c0c75f0 */
if(!s->budget--) { s->failed_pc=0x0c0c75f0u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0c75f2;
P_0c0c75f2: /* original 4c10, guest PC 0x0c0c75f2 */
if(!s->budget--) { s->failed_pc=0x0c0c75f2u; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c0c75f4;
P_0c0c75f4: /* original 6470, guest PC 0x0c0c75f4 */
if(!s->budget--) { s->failed_pc=0x0c0c75f4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[4]=tmp;
goto P_0c0c75f6;
P_0c0c75f6: /* original 6660, guest PC 0x0c0c75f6 */
if(!s->budget--) { s->failed_pc=0x0c0c75f6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[6]=tmp;
goto P_0c0c75f8;
P_0c0c75f8: /* original 63f2, guest PC 0x0c0c75f8 */
if(!s->budget--) { s->failed_pc=0x0c0c75f8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c75fa;
P_0c0c75fa: /* original 644c, guest PC 0x0c0c75fa */
if(!s->budget--) { s->failed_pc=0x0c0c75fau; return 0; }
r[4]=r[4]&255u;
goto P_0c0c75fc;
P_0c0c75fc: /* original 666c, guest PC 0x0c0c75fc */
if(!s->budget--) { s->failed_pc=0x0c0c75fcu; return 0; }
r[6]=r[6]&255u;
goto P_0c0c75fe;
P_0c0c75fe: /* original 2340, guest PC 0x0c0c75fe */
if(!s->budget--) { s->failed_pc=0x0c0c75feu; return 0; }
write(ram,r[3],r[4],1);
goto P_0c0c7600;
P_0c0c7600: /* original 8fd5, guest PC 0x0c0c7600 */
if(!s->budget--) { s->failed_pc=0x0c0c7600u; return 0; }
cond=r[17]&1u;
write(ram,r[7],r[6],1);
if(!cond) { goto P_0c0c75ae; }
goto P_0c0c7604;
P_0c0c7602: /* original 2760, guest PC 0x0c0c7602 */
if(!s->budget--) { s->failed_pc=0x0c0c7602u; return 0; }
write(ram,r[7],r[6],1);
goto P_0c0c7604;
P_0c0c7604: /* original 7bff, guest PC 0x0c0c7604 */
if(!s->budget--) { s->failed_pc=0x0c0c7604u; return 0; }
r[11]+=0xffffffffu;
goto P_0c0c7606;
P_0c0c7606: /* original e009, guest PC 0x0c0c7606 */
if(!s->budget--) { s->failed_pc=0x0c0c7606u; return 0; }
r[0]=0x00000009u;
goto P_0c0c7608;
P_0c0c7608: /* original 4b15, guest PC 0x0c0c7608 */
if(!s->budget--) { s->failed_pc=0x0c0c7608u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>0)!=0);
goto P_0c0c760a;
P_0c0c760a: /* original 80e8, guest PC 0x0c0c760a */
if(!s->budget--) { s->failed_pc=0x0c0c760au; return 0; }
write(ram,r[14]+8,r[0],1);
goto P_0c0c760c;
P_0c0c760c: /* original 8dce, guest PC 0x0c0c760c */
if(!s->budget--) { s->failed_pc=0x0c0c760cu; return 0; }
cond=r[17]&1u;
r[14]+=0x0000000cu;
if(cond) { goto P_0c0c75ac; }
goto P_0c0c7610;
P_0c0c760e: /* original 7e0c, guest PC 0x0c0c760e */
if(!s->budget--) { s->failed_pc=0x0c0c760eu; return 0; }
r[14]+=0x0000000cu;
goto P_0c0c7610;
P_0c0c7610: /* original 7f04, guest PC 0x0c0c7610 */
if(!s->budget--) { s->failed_pc=0x0c0c7610u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c7612;
P_0c0c7612: /* original 4f26, guest PC 0x0c0c7612 */
if(!s->budget--) { s->failed_pc=0x0c0c7612u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7614;
P_0c0c7614: /* original 6bf6, guest PC 0x0c0c7614 */
if(!s->budget--) { s->failed_pc=0x0c0c7614u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7616;
P_0c0c7616: /* original 6cf6, guest PC 0x0c0c7616 */
if(!s->budget--) { s->failed_pc=0x0c0c7616u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7618;
P_0c0c7618: /* original 6df6, guest PC 0x0c0c7618 */
if(!s->budget--) { s->failed_pc=0x0c0c7618u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c761a;
P_0c0c761a: /* original 000b, guest PC 0x0c0c761a */
if(!s->budget--) { s->failed_pc=0x0c0c761au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c761c: /* original 6ef6, guest PC 0x0c0c761c */
if(!s->budget--) { s->failed_pc=0x0c0c761cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c761eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c761eu; return 0; } return 1;
P_0c0c7802: /* original e01c, guest PC 0x0c0c7802 */
if(!s->budget--) { s->failed_pc=0x0c0c7802u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7804;
P_0c0c7804: /* original 2fe6, guest PC 0x0c0c7804 */
if(!s->budget--) { s->failed_pc=0x0c0c7804u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7806;
P_0c0c7806: /* original 2fd6, guest PC 0x0c0c7806 */
if(!s->budget--) { s->failed_pc=0x0c0c7806u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7808;
P_0c0c7808: /* original 2fc6, guest PC 0x0c0c7808 */
if(!s->budget--) { s->failed_pc=0x0c0c7808u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c780a;
P_0c0c780a: /* original 2fb6, guest PC 0x0c0c780a */
if(!s->budget--) { s->failed_pc=0x0c0c780au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c780c;
P_0c0c780c: /* original 2fa6, guest PC 0x0c0c780c */
if(!s->budget--) { s->failed_pc=0x0c0c780cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c780e;
P_0c0c780e: /* original d419, guest PC 0x0c0c780e */
if(!s->budget--) { s->failed_pc=0x0c0c780eu; return 0; }
r[4]=read(ram,0x0c0c7874u,4);
goto P_0c0c7810;
P_0c0c7810: /* original 4f22, guest PC 0x0c0c7810 */
if(!s->budget--) { s->failed_pc=0x0c0c7810u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7812;
P_0c0c7812: /* original 004c, guest PC 0x0c0c7812 */
if(!s->budget--) { s->failed_pc=0x0c0c7812u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7814;
P_0c0c7814: /* original e40f, guest PC 0x0c0c7814 */
if(!s->budget--) { s->failed_pc=0x0c0c7814u; return 0; }
r[4]=0x0000000fu;
goto P_0c0c7816;
P_0c0c7816: /* original 600c, guest PC 0x0c0c7816 */
if(!s->budget--) { s->failed_pc=0x0c0c7816u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c7818;
P_0c0c7818: /* original 2409, guest PC 0x0c0c7818 */
if(!s->budget--) { s->failed_pc=0x0c0c7818u; return 0; }
r[4]&=r[0];
goto P_0c0c781a;
P_0c0c781a: /* original d017, guest PC 0x0c0c781a */
if(!s->budget--) { s->failed_pc=0x0c0c781au; return 0; }
r[0]=read(ram,0x0c0c7878u,4);
goto P_0c0c781c;
P_0c0c781c: /* original 6e43, guest PC 0x0c0c781c */
if(!s->budget--) { s->failed_pc=0x0c0c781cu; return 0; }
r[14]=r[4];
goto P_0c0c781e;
P_0c0c781e: /* original 4e08, guest PC 0x0c0c781e */
if(!s->budget--) { s->failed_pc=0x0c0c781eu; return 0; }
r[14]<<=2;
goto P_0c0c7820;
P_0c0c7820: /* original 0eee, guest PC 0x0c0c7820 */
if(!s->budget--) { s->failed_pc=0x0c0c7820u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c0c7822;
P_0c0c7822: /* original 2ee8, guest PC 0x0c0c7822 */
if(!s->budget--) { s->failed_pc=0x0c0c7822u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c7824;
P_0c0c7824: /* original 8914, guest PC 0x0c0c7824 */
if(!s->budget--) { s->failed_pc=0x0c0c7824u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7850; }
goto P_0c0c7826;
P_0c0c7826: /* original dc17, guest PC 0x0c0c7826 */
if(!s->budget--) { s->failed_pc=0x0c0c7826u; return 0; }
r[12]=read(ram,0x0c0c7884u,4);
goto P_0c0c7828;
P_0c0c7828: /* original db15, guest PC 0x0c0c7828 */
if(!s->budget--) { s->failed_pc=0x0c0c7828u; return 0; }
r[11]=read(ram,0x0c0c7880u,4);
goto P_0c0c782a;
P_0c0c782a: /* original da14, guest PC 0x0c0c782a */
if(!s->budget--) { s->failed_pc=0x0c0c782au; return 0; }
r[10]=read(ram,0x0c0c787cu,4);
goto P_0c0c782c;
P_0c0c782c: /* original a00d, guest PC 0x0c0c782c */
if(!s->budget--) { s->failed_pc=0x0c0c782cu; return 0; }
r[13]=0x00000001u;
goto P_0c0c784a;
P_0c0c782e: /* original ed01, guest PC 0x0c0c782e */
if(!s->budget--) { s->failed_pc=0x0c0c782eu; return 0; }
r[13]=0x00000001u;
goto P_0c0c7830;
P_0c0c7830: /* original 60e5, guest PC 0x0c0c7830 */
if(!s->budget--) { s->failed_pc=0x0c0c7830u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[0]=tmp;
goto P_0c0c7832;
P_0c0c7832: /* original 600d, guest PC 0x0c0c7832 */
if(!s->budget--) { s->failed_pc=0x0c0c7832u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c7834;
P_0c0c7834: /* original 4008, guest PC 0x0c0c7834 */
if(!s->budget--) { s->failed_pc=0x0c0c7834u; return 0; }
r[0]<<=2;
goto P_0c0c7836;
P_0c0c7836: /* original 04ce, guest PC 0x0c0c7836 */
if(!s->budget--) { s->failed_pc=0x0c0c7836u; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c0c7838;
P_0c0c7838: /* original 5341, guest PC 0x0c0c7838 */
if(!s->budget--) { s->failed_pc=0x0c0c7838u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0c783a;
P_0c0c783a: /* original 23d8, guest PC 0x0c0c783a */
if(!s->budget--) { s->failed_pc=0x0c0c783au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c783c;
P_0c0c783c: /* original 8903, guest PC 0x0c0c783c */
if(!s->budget--) { s->failed_pc=0x0c0c783cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7846; }
goto P_0c0c783e;
P_0c0c783e: /* original 4b0b, guest PC 0x0c0c783e */
if(!s->budget--) { s->failed_pc=0x0c0c783eu; return 0; }
target=r[11];
r[16]=code_base|0x0c0c7842u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7842u) { target=s->pc; goto dispatch; }
goto P_0c0c7842;
P_0c0c7840: /* original 0009, guest PC 0x0c0c7840 */
if(!s->budget--) { s->failed_pc=0x0c0c7840u; return 0; }
goto P_0c0c7842;
P_0c0c7842: /* original a002, guest PC 0x0c0c7842 */
if(!s->budget--) { s->failed_pc=0x0c0c7842u; return 0; }
goto P_0c0c784a;
P_0c0c7844: /* original 0009, guest PC 0x0c0c7844 */
if(!s->budget--) { s->failed_pc=0x0c0c7844u; return 0; }
goto P_0c0c7846;
P_0c0c7846: /* original 4a0b, guest PC 0x0c0c7846 */
if(!s->budget--) { s->failed_pc=0x0c0c7846u; return 0; }
target=r[10];
r[16]=code_base|0x0c0c784au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c784au) { target=s->pc; goto dispatch; }
goto P_0c0c784a;
P_0c0c7848: /* original 0009, guest PC 0x0c0c7848 */
if(!s->budget--) { s->failed_pc=0x0c0c7848u; return 0; }
goto P_0c0c784a;
P_0c0c784a: /* original 62e1, guest PC 0x0c0c784a */
if(!s->budget--) { s->failed_pc=0x0c0c784au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[2]=tmp;
goto P_0c0c784c;
P_0c0c784c: /* original 2228, guest PC 0x0c0c784c */
if(!s->budget--) { s->failed_pc=0x0c0c784cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c784e;
P_0c0c784e: /* original 8bef, guest PC 0x0c0c784e */
if(!s->budget--) { s->failed_pc=0x0c0c784eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7830; }
goto P_0c0c7850;
P_0c0c7850: /* original 4f26, guest PC 0x0c0c7850 */
if(!s->budget--) { s->failed_pc=0x0c0c7850u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7852;
P_0c0c7852: /* original 6af6, guest PC 0x0c0c7852 */
if(!s->budget--) { s->failed_pc=0x0c0c7852u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c7854;
P_0c0c7854: /* original 6bf6, guest PC 0x0c0c7854 */
if(!s->budget--) { s->failed_pc=0x0c0c7854u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7856;
P_0c0c7856: /* original 6cf6, guest PC 0x0c0c7856 */
if(!s->budget--) { s->failed_pc=0x0c0c7856u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7858;
P_0c0c7858: /* original 6df6, guest PC 0x0c0c7858 */
if(!s->budget--) { s->failed_pc=0x0c0c7858u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c785a;
P_0c0c785a: /* original 000b, guest PC 0x0c0c785a */
if(!s->budget--) { s->failed_pc=0x0c0c785au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c785c: /* original 6ef6, guest PC 0x0c0c785c */
if(!s->budget--) { s->failed_pc=0x0c0c785cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c785eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c785eu; return 0; } return 1;
P_0c0c78d0: /* original 2fe6, guest PC 0x0c0c78d0 */
if(!s->budget--) { s->failed_pc=0x0c0c78d0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c78d2;
P_0c0c78d2: /* original 4511, guest PC 0x0c0c78d2 */
if(!s->budget--) { s->failed_pc=0x0c0c78d2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c0c78d4;
P_0c0c78d4: /* original 2fd6, guest PC 0x0c0c78d4 */
if(!s->budget--) { s->failed_pc=0x0c0c78d4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c78d6;
P_0c0c78d6: /* original 2fc6, guest PC 0x0c0c78d6 */
if(!s->budget--) { s->failed_pc=0x0c0c78d6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c78d8;
P_0c0c78d8: /* original 2fb6, guest PC 0x0c0c78d8 */
if(!s->budget--) { s->failed_pc=0x0c0c78d8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c78da;
P_0c0c78da: /* original 2fa6, guest PC 0x0c0c78da */
if(!s->budget--) { s->failed_pc=0x0c0c78dau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c78dc;
P_0c0c78dc: /* original 2f96, guest PC 0x0c0c78dc */
if(!s->budget--) { s->failed_pc=0x0c0c78dcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c78de;
P_0c0c78de: /* original 2f86, guest PC 0x0c0c78de */
if(!s->budget--) { s->failed_pc=0x0c0c78deu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c78e0;
P_0c0c78e0: /* original 4f22, guest PC 0x0c0c78e0 */
if(!s->budget--) { s->failed_pc=0x0c0c78e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c78e2;
P_0c0c78e2: /* original de37, guest PC 0x0c0c78e2 */
if(!s->budget--) { s->failed_pc=0x0c0c78e2u; return 0; }
r[14]=read(ram,0x0c0c79c0u,4);
goto P_0c0c78e4;
P_0c0c78e4: /* original 7ffc, guest PC 0x0c0c78e4 */
if(!s->budget--) { s->failed_pc=0x0c0c78e4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c78e6;
P_0c0c78e6: /* original 8f55, guest PC 0x0c0c78e6 */
if(!s->budget--) { s->failed_pc=0x0c0c78e6u; return 0; }
cond=r[17]&1u;
r[11]=read(ram,r[4]+24,4);
if(!cond) { goto P_0c0c7994; }
goto P_0c0c78ea;
P_0c0c78e8: /* original 5b46, guest PC 0x0c0c78e8 */
if(!s->budget--) { s->failed_pc=0x0c0c78e8u; return 0; }
r[11]=read(ram,r[4]+24,4);
goto P_0c0c78ea;
P_0c0c78ea: /* original d33d, guest PC 0x0c0c78ea */
if(!s->budget--) { s->failed_pc=0x0c0c78eau; return 0; }
r[3]=read(ram,0x0c0c79e0u,4);
goto P_0c0c78ec;
P_0c0c78ec: /* original d23d, guest PC 0x0c0c78ec */
if(!s->budget--) { s->failed_pc=0x0c0c78ecu; return 0; }
r[2]=read(ram,0x0c0c79e4u,4);
goto P_0c0c78ee;
P_0c0c78ee: /* original 905e, guest PC 0x0c0c78ee */
if(!s->budget--) { s->failed_pc=0x0c0c78eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79aeu,2);
goto P_0c0c78f0;
P_0c0c78f0: /* original 6522, guest PC 0x0c0c78f0 */
if(!s->budget--) { s->failed_pc=0x0c0c78f0u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c0c78f2;
P_0c0c78f2: /* original d13d, guest PC 0x0c0c78f2 */
if(!s->budget--) { s->failed_pc=0x0c0c78f2u; return 0; }
r[1]=read(ram,0x0c0c79e8u,4);
goto P_0c0c78f4;
P_0c0c78f4: /* original 0cee, guest PC 0x0c0c78f4 */
if(!s->budget--) { s->failed_pc=0x0c0c78f4u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c0c78f6;
P_0c0c78f6: /* original 6631, guest PC 0x0c0c78f6 */
if(!s->budget--) { s->failed_pc=0x0c0c78f6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[6]=tmp;
goto P_0c0c78f8;
P_0c0c78f8: /* original 410b, guest PC 0x0c0c78f8 */
if(!s->budget--) { s->failed_pc=0x0c0c78f8u; return 0; }
target=r[1];
r[16]=code_base|0x0c0c78fcu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c78fcu) { target=s->pc; goto dispatch; }
goto P_0c0c78fc;
P_0c0c78fa: /* original 64c3, guest PC 0x0c0c78fa */
if(!s->budget--) { s->failed_pc=0x0c0c78fau; return 0; }
r[4]=r[12];
goto P_0c0c78fc;
P_0c0c78fc: /* original d83b, guest PC 0x0c0c78fc */
if(!s->budget--) { s->failed_pc=0x0c0c78fcu; return 0; }
r[8]=read(ram,0x0c0c79ecu,4);
goto P_0c0c78fe;
P_0c0c78fe: /* original 9a57, guest PC 0x0c0c78fe */
if(!s->budget--) { s->failed_pc=0x0c0c78feu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79b0u,2);
goto P_0c0c7900;
P_0c0c7900: /* original 59c4, guest PC 0x0c0c7900 */
if(!s->budget--) { s->failed_pc=0x0c0c7900u; return 0; }
r[9]=read(ram,r[12]+16,4);
goto P_0c0c7902;
P_0c0c7902: /* original a007, guest PC 0x0c0c7902 */
if(!s->budget--) { s->failed_pc=0x0c0c7902u; return 0; }
r[13]=0x00000000u;
goto P_0c0c7914;
P_0c0c7904: /* original ed00, guest PC 0x0c0c7904 */
if(!s->budget--) { s->failed_pc=0x0c0c7904u; return 0; }
r[13]=0x00000000u;
goto P_0c0c7906;
P_0c0c7906: /* original 60d3, guest PC 0x0c0c7906 */
if(!s->budget--) { s->failed_pc=0x0c0c7906u; return 0; }
r[0]=r[13];
goto P_0c0c7908;
P_0c0c7908: /* original 4008, guest PC 0x0c0c7908 */
if(!s->budget--) { s->failed_pc=0x0c0c7908u; return 0; }
r[0]<<=2;
goto P_0c0c790a;
P_0c0c790a: /* original 059e, guest PC 0x0c0c790a */
if(!s->budget--) { s->failed_pc=0x0c0c790au; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c0c790c;
P_0c0c790c: /* original 64a3, guest PC 0x0c0c790c */
if(!s->budget--) { s->failed_pc=0x0c0c790cu; return 0; }
r[4]=r[10];
goto P_0c0c790e;
P_0c0c790e: /* original 480b, guest PC 0x0c0c790e */
if(!s->budget--) { s->failed_pc=0x0c0c790eu; return 0; }
target=r[8];
r[16]=code_base|0x0c0c7912u;
r[10]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7912u) { target=s->pc; goto dispatch; }
goto P_0c0c7912;
P_0c0c7910: /* original 7a01, guest PC 0x0c0c7910 */
if(!s->budget--) { s->failed_pc=0x0c0c7910u; return 0; }
r[10]+=0x00000001u;
goto P_0c0c7912;
P_0c0c7912: /* original 7d01, guest PC 0x0c0c7912 */
if(!s->budget--) { s->failed_pc=0x0c0c7912u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c7914;
P_0c0c7914: /* original 85c6, guest PC 0x0c0c7914 */
if(!s->budget--) { s->failed_pc=0x0c0c7914u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+12,2);
goto P_0c0c7916;
P_0c0c7916: /* original 600d, guest PC 0x0c0c7916 */
if(!s->budget--) { s->failed_pc=0x0c0c7916u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c7918;
P_0c0c7918: /* original 3d03, guest PC 0x0c0c7918 */
if(!s->budget--) { s->failed_pc=0x0c0c7918u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[0])!=0);
goto P_0c0c791a;
P_0c0c791a: /* original 8bf4, guest PC 0x0c0c791a */
if(!s->budget--) { s->failed_pc=0x0c0c791au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7906; }
goto P_0c0c791c;
P_0c0c791c: /* original 9047, guest PC 0x0c0c791c */
if(!s->budget--) { s->failed_pc=0x0c0c791cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79aeu,2);
goto P_0c0c791e;
P_0c0c791e: /* original 6db3, guest PC 0x0c0c791e */
if(!s->budget--) { s->failed_pc=0x0c0c791eu; return 0; }
r[13]=r[11];
goto P_0c0c7920;
P_0c0c7920: /* original 53c6, guest PC 0x0c0c7920 */
if(!s->budget--) { s->failed_pc=0x0c0c7920u; return 0; }
r[3]=read(ram,r[12]+24,4);
goto P_0c0c7922;
P_0c0c7922: /* original 4d08, guest PC 0x0c0c7922 */
if(!s->budget--) { s->failed_pc=0x0c0c7922u; return 0; }
r[13]<<=2;
goto P_0c0c7924;
P_0c0c7924: /* original 02ee, guest PC 0x0c0c7924 */
if(!s->budget--) { s->failed_pc=0x0c0c7924u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0c7926;
P_0c0c7926: /* original 7004, guest PC 0x0c0c7926 */
if(!s->budget--) { s->failed_pc=0x0c0c7926u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c7928;
P_0c0c7928: /* original 9143, guest PC 0x0c0c7928 */
if(!s->budget--) { s->failed_pc=0x0c0c7928u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79b2u,2);
goto P_0c0c792a;
P_0c0c792a: /* original 4d00, guest PC 0x0c0c792a */
if(!s->budget--) { s->failed_pc=0x0c0c792au; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c0c792c;
P_0c0c792c: /* original 323c, guest PC 0x0c0c792c */
if(!s->budget--) { s->failed_pc=0x0c0c792cu; return 0; }
r[2]+=r[3];
goto P_0c0c792e;
P_0c0c792e: /* original 9341, guest PC 0x0c0c792e */
if(!s->budget--) { s->failed_pc=0x0c0c792eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79b4u,2);
goto P_0c0c7930;
P_0c0c7930: /* original 321c, guest PC 0x0c0c7930 */
if(!s->budget--) { s->failed_pc=0x0c0c7930u; return 0; }
r[2]+=r[1];
goto P_0c0c7932;
P_0c0c7932: /* original 2239, guest PC 0x0c0c7932 */
if(!s->budget--) { s->failed_pc=0x0c0c7932u; return 0; }
r[2]&=r[3];
goto P_0c0c7934;
P_0c0c7934: /* original 0e26, guest PC 0x0c0c7934 */
if(!s->budget--) { s->failed_pc=0x0c0c7934u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c7936;
P_0c0c7936: /* original 70f8, guest PC 0x0c0c7936 */
if(!s->budget--) { s->failed_pc=0x0c0c7936u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c7938;
P_0c0c7938: /* original 0e26, guest PC 0x0c0c7938 */
if(!s->budget--) { s->failed_pc=0x0c0c7938u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c793a;
P_0c0c793a: /* original d22d, guest PC 0x0c0c793a */
if(!s->budget--) { s->failed_pc=0x0c0c793au; return 0; }
r[2]=read(ram,0x0c0c79f0u,4);
goto P_0c0c793c;
P_0c0c793c: /* original 3d2c, guest PC 0x0c0c793c */
if(!s->budget--) { s->failed_pc=0x0c0c793cu; return 0; }
r[13]+=r[2];
goto P_0c0c793e;
P_0c0c793e: /* original 60d2, guest PC 0x0c0c793e */
if(!s->budget--) { s->failed_pc=0x0c0c793eu; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0c7940;
P_0c0c7940: /* original 88ff, guest PC 0x0c0c7940 */
if(!s->budget--) { s->failed_pc=0x0c0c7940u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c7942;
P_0c0c7942: /* original 891f, guest PC 0x0c0c7942 */
if(!s->budget--) { s->failed_pc=0x0c0c7942u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7984; }
goto P_0c0c7944;
P_0c0c7944: /* original 9137, guest PC 0x0c0c7944 */
if(!s->budget--) { s->failed_pc=0x0c0c7944u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79b6u,2);
goto P_0c0c7946;
P_0c0c7946: /* original e700, guest PC 0x0c0c7946 */
if(!s->budget--) { s->failed_pc=0x0c0c7946u; return 0; }
r[7]=0x00000000u;
goto P_0c0c7948;
P_0c0c7948: /* original 2f16, guest PC 0x0c0c7948 */
if(!s->budget--) { s->failed_pc=0x0c0c7948u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c794a;
P_0c0c794a: /* original d32a, guest PC 0x0c0c794a */
if(!s->budget--) { s->failed_pc=0x0c0c794au; return 0; }
r[3]=read(ram,0x0c0c79f4u,4);
goto P_0c0c794c;
P_0c0c794c: /* original 2f36, guest PC 0x0c0c794c */
if(!s->budget--) { s->failed_pc=0x0c0c794cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c794e;
P_0c0c794e: /* original 2fb6, guest PC 0x0c0c794e */
if(!s->budget--) { s->failed_pc=0x0c0c794eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7950;
P_0c0c7950: /* original 9632, guest PC 0x0c0c7950 */
if(!s->budget--) { s->failed_pc=0x0c0c7950u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79b8u,2);
goto P_0c0c7952;
P_0c0c7952: /* original 9032, guest PC 0x0c0c7952 */
if(!s->budget--) { s->failed_pc=0x0c0c7952u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79bau,2);
goto P_0c0c7954;
P_0c0c7954: /* original 36ec, guest PC 0x0c0c7954 */
if(!s->budget--) { s->failed_pc=0x0c0c7954u; return 0; }
r[6]+=r[14];
goto P_0c0c7956;
P_0c0c7956: /* original 05ee, guest PC 0x0c0c7956 */
if(!s->budget--) { s->failed_pc=0x0c0c7956u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0c7958;
P_0c0c7958: /* original 7608, guest PC 0x0c0c7958 */
if(!s->budget--) { s->failed_pc=0x0c0c7958u; return 0; }
r[6]+=0x00000008u;
goto P_0c0c795a;
P_0c0c795a: /* original 1fd3, guest PC 0x0c0c795a */
if(!s->budget--) { s->failed_pc=0x0c0c795au; return 0; }
write(ram,r[15]+12,r[13],4);
goto P_0c0c795c;
P_0c0c795c: /* original d326, guest PC 0x0c0c795c */
if(!s->budget--) { s->failed_pc=0x0c0c795cu; return 0; }
r[3]=read(ram,0x0c0c79f8u,4);
goto P_0c0c795e;
P_0c0c795e: /* original 430b, guest PC 0x0c0c795e */
if(!s->budget--) { s->failed_pc=0x0c0c795eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7962u;
tmp=read(ram,r[13],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7962u) { target=s->pc; goto dispatch; }
goto P_0c0c7962;
P_0c0c7960: /* original 64d2, guest PC 0x0c0c7960 */
if(!s->budget--) { s->failed_pc=0x0c0c7960u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0c7962;
P_0c0c7962: /* original 922b, guest PC 0x0c0c7962 */
if(!s->budget--) { s->failed_pc=0x0c0c7962u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79bcu,2);
goto P_0c0c7964;
P_0c0c7964: /* original 2f26, guest PC 0x0c0c7964 */
if(!s->budget--) { s->failed_pc=0x0c0c7964u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7966;
P_0c0c7966: /* original d323, guest PC 0x0c0c7966 */
if(!s->budget--) { s->failed_pc=0x0c0c7966u; return 0; }
r[3]=read(ram,0x0c0c79f4u,4);
goto P_0c0c7968;
P_0c0c7968: /* original 2f36, guest PC 0x0c0c7968 */
if(!s->budget--) { s->failed_pc=0x0c0c7968u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c796a;
P_0c0c796a: /* original 2fb6, guest PC 0x0c0c796a */
if(!s->budget--) { s->failed_pc=0x0c0c796au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c796c;
P_0c0c796c: /* original 9624, guest PC 0x0c0c796c */
if(!s->budget--) { s->failed_pc=0x0c0c796cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79b8u,2);
goto P_0c0c796e;
P_0c0c796e: /* original d11d, guest PC 0x0c0c796e */
if(!s->budget--) { s->failed_pc=0x0c0c796eu; return 0; }
r[1]=read(ram,0x0c0c79e4u,4);
goto P_0c0c7970;
P_0c0c7970: /* original 53f6, guest PC 0x0c0c7970 */
if(!s->budget--) { s->failed_pc=0x0c0c7970u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0c7972;
P_0c0c7972: /* original 36ec, guest PC 0x0c0c7972 */
if(!s->budget--) { s->failed_pc=0x0c0c7972u; return 0; }
r[6]+=r[14];
goto P_0c0c7974;
P_0c0c7974: /* original 6512, guest PC 0x0c0c7974 */
if(!s->budget--) { s->failed_pc=0x0c0c7974u; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c0c7976;
P_0c0c7976: /* original 7608, guest PC 0x0c0c7976 */
if(!s->budget--) { s->failed_pc=0x0c0c7976u; return 0; }
r[6]+=0x00000008u;
goto P_0c0c7978;
P_0c0c7978: /* original d720, guest PC 0x0c0c7978 */
if(!s->budget--) { s->failed_pc=0x0c0c7978u; return 0; }
r[7]=read(ram,0x0c0c79fcu,4);
goto P_0c0c797a;
P_0c0c797a: /* original d21f, guest PC 0x0c0c797a */
if(!s->budget--) { s->failed_pc=0x0c0c797au; return 0; }
r[2]=read(ram,0x0c0c79f8u,4);
goto P_0c0c797c;
P_0c0c797c: /* original 420b, guest PC 0x0c0c797c */
if(!s->budget--) { s->failed_pc=0x0c0c797cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7980u;
r[4]=read(ram,r[3]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7980u) { target=s->pc; goto dispatch; }
goto P_0c0c7980;
P_0c0c797e: /* original 5431, guest PC 0x0c0c797e */
if(!s->budget--) { s->failed_pc=0x0c0c797eu; return 0; }
r[4]=read(ram,r[3]+4,4);
goto P_0c0c7980;
P_0c0c7980: /* original a008, guest PC 0x0c0c7980 */
if(!s->budget--) { s->failed_pc=0x0c0c7980u; return 0; }
r[15]+=0x00000018u;
goto P_0c0c7994;
P_0c0c7982: /* original 7f18, guest PC 0x0c0c7982 */
if(!s->budget--) { s->failed_pc=0x0c0c7982u; return 0; }
r[15]+=0x00000018u;
goto P_0c0c7984;
P_0c0c7984: /* original 9119, guest PC 0x0c0c7984 */
if(!s->budget--) { s->failed_pc=0x0c0c7984u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79bau,2);
goto P_0c0c7986;
P_0c0c7986: /* original e000, guest PC 0x0c0c7986 */
if(!s->budget--) { s->failed_pc=0x0c0c7986u; return 0; }
r[0]=0x00000000u;
goto P_0c0c7988;
P_0c0c7988: /* original e3ff, guest PC 0x0c0c7988 */
if(!s->budget--) { s->failed_pc=0x0c0c7988u; return 0; }
r[3]=0xffffffffu;
goto P_0c0c798a;
P_0c0c798a: /* original 31ec, guest PC 0x0c0c798a */
if(!s->budget--) { s->failed_pc=0x0c0c798au; return 0; }
r[1]+=r[14];
goto P_0c0c798c;
P_0c0c798c: /* original 2102, guest PC 0x0c0c798c */
if(!s->budget--) { s->failed_pc=0x0c0c798cu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0c798e;
P_0c0c798e: /* original 900d, guest PC 0x0c0c798e */
if(!s->budget--) { s->failed_pc=0x0c0c798eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c79acu,2);
goto P_0c0c7990;
P_0c0c7990: /* original bf37, guest PC 0x0c0c7990 */
if(!s->budget--) { s->failed_pc=0x0c0c7990u; return 0; }
target=code_base|0x0c0c7802u; r[16]=code_base|0x0c0c7994u;
write(ram,r[14]+r[0],r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7994u) { target=s->pc; goto dispatch; }
goto P_0c0c7994;
P_0c0c7992: /* original 0e36, guest PC 0x0c0c7992 */
if(!s->budget--) { s->failed_pc=0x0c0c7992u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0c7994;
P_0c0c7994: /* original 7f04, guest PC 0x0c0c7994 */
if(!s->budget--) { s->failed_pc=0x0c0c7994u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c7996;
P_0c0c7996: /* original 4f26, guest PC 0x0c0c7996 */
if(!s->budget--) { s->failed_pc=0x0c0c7996u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7998;
P_0c0c7998: /* original e000, guest PC 0x0c0c7998 */
if(!s->budget--) { s->failed_pc=0x0c0c7998u; return 0; }
r[0]=0x00000000u;
goto P_0c0c799a;
P_0c0c799a: /* original 68f6, guest PC 0x0c0c799a */
if(!s->budget--) { s->failed_pc=0x0c0c799au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c799c;
P_0c0c799c: /* original 69f6, guest PC 0x0c0c799c */
if(!s->budget--) { s->failed_pc=0x0c0c799cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c799e;
P_0c0c799e: /* original 6af6, guest PC 0x0c0c799e */
if(!s->budget--) { s->failed_pc=0x0c0c799eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c79a0;
P_0c0c79a0: /* original 6bf6, guest PC 0x0c0c79a0 */
if(!s->budget--) { s->failed_pc=0x0c0c79a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c79a2;
P_0c0c79a2: /* original 6cf6, guest PC 0x0c0c79a2 */
if(!s->budget--) { s->failed_pc=0x0c0c79a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c79a4;
P_0c0c79a4: /* original 6df6, guest PC 0x0c0c79a4 */
if(!s->budget--) { s->failed_pc=0x0c0c79a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c79a6;
P_0c0c79a6: /* original 000b, guest PC 0x0c0c79a6 */
if(!s->budget--) { s->failed_pc=0x0c0c79a6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c79a8: /* original 6ef6, guest PC 0x0c0c79a8 */
if(!s->budget--) { s->failed_pc=0x0c0c79a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c79aau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c79aau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
