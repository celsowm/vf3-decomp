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
int vf3_away_batch163_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c41beu: goto P_0c0c41be;
case 0x0c0c41c0u: goto P_0c0c41c0;
case 0x0c0c41c2u: goto P_0c0c41c2;
case 0x0c0c41c4u: goto P_0c0c41c4;
case 0x0c0c41c6u: goto P_0c0c41c6;
case 0x0c0c41c8u: goto P_0c0c41c8;
case 0x0c0c41cau: goto P_0c0c41ca;
case 0x0c0c41ccu: goto P_0c0c41cc;
case 0x0c0c41ceu: goto P_0c0c41ce;
case 0x0c0c41d0u: goto P_0c0c41d0;
case 0x0c0c41d2u: goto P_0c0c41d2;
case 0x0c0c41d4u: goto P_0c0c41d4;
case 0x0c0c41d6u: goto P_0c0c41d6;
case 0x0c0c41d8u: goto P_0c0c41d8;
case 0x0c0c41dau: goto P_0c0c41da;
case 0x0c0c41dcu: goto P_0c0c41dc;
case 0x0c0c41deu: goto P_0c0c41de;
case 0x0c0c41e0u: goto P_0c0c41e0;
case 0x0c0c41e2u: goto P_0c0c41e2;
case 0x0c0c4210u: goto P_0c0c4210;
case 0x0c0c4212u: goto P_0c0c4212;
case 0x0c0c4214u: goto P_0c0c4214;
case 0x0c0c4216u: goto P_0c0c4216;
case 0x0c0c4218u: goto P_0c0c4218;
case 0x0c0c421au: goto P_0c0c421a;
case 0x0c0c421cu: goto P_0c0c421c;
case 0x0c0c421eu: goto P_0c0c421e;
case 0x0c0c4220u: goto P_0c0c4220;
case 0x0c0c4222u: goto P_0c0c4222;
case 0x0c0c4224u: goto P_0c0c4224;
case 0x0c0c4226u: goto P_0c0c4226;
case 0x0c0c4228u: goto P_0c0c4228;
case 0x0c0c422au: goto P_0c0c422a;
case 0x0c0c422cu: goto P_0c0c422c;
case 0x0c0c422eu: goto P_0c0c422e;
case 0x0c0c4230u: goto P_0c0c4230;
case 0x0c0c4232u: goto P_0c0c4232;
case 0x0c0c4234u: goto P_0c0c4234;
case 0x0c0c4236u: goto P_0c0c4236;
case 0x0c0c4238u: goto P_0c0c4238;
case 0x0c0c423au: goto P_0c0c423a;
case 0x0c0c423cu: goto P_0c0c423c;
case 0x0c0c423eu: goto P_0c0c423e;
case 0x0c0c4240u: goto P_0c0c4240;
case 0x0c0c4242u: goto P_0c0c4242;
case 0x0c0c4244u: goto P_0c0c4244;
case 0x0c0c4246u: goto P_0c0c4246;
case 0x0c0c4248u: goto P_0c0c4248;
case 0x0c0c424au: goto P_0c0c424a;
case 0x0c0c424cu: goto P_0c0c424c;
case 0x0c0c424eu: goto P_0c0c424e;
case 0x0c0c4250u: goto P_0c0c4250;
case 0x0c0c4252u: goto P_0c0c4252;
case 0x0c0c4254u: goto P_0c0c4254;
case 0x0c0c4256u: goto P_0c0c4256;
case 0x0c0c4258u: goto P_0c0c4258;
case 0x0c0c425au: goto P_0c0c425a;
case 0x0c0c425cu: goto P_0c0c425c;
case 0x0c0c425eu: goto P_0c0c425e;
case 0x0c0c4260u: goto P_0c0c4260;
case 0x0c0c4262u: goto P_0c0c4262;
case 0x0c0c4264u: goto P_0c0c4264;
case 0x0c0c4266u: goto P_0c0c4266;
case 0x0c0c4268u: goto P_0c0c4268;
case 0x0c0c426au: goto P_0c0c426a;
case 0x0c0c426cu: goto P_0c0c426c;
case 0x0c0c426eu: goto P_0c0c426e;
case 0x0c0c4270u: goto P_0c0c4270;
case 0x0c0c4272u: goto P_0c0c4272;
case 0x0c0c4274u: goto P_0c0c4274;
case 0x0c0c4276u: goto P_0c0c4276;
case 0x0c0c4278u: goto P_0c0c4278;
case 0x0c0c427au: goto P_0c0c427a;
case 0x0c0c427cu: goto P_0c0c427c;
case 0x0c0c427eu: goto P_0c0c427e;
case 0x0c0c4280u: goto P_0c0c4280;
case 0x0c0c4282u: goto P_0c0c4282;
case 0x0c0c4284u: goto P_0c0c4284;
case 0x0c0c4286u: goto P_0c0c4286;
case 0x0c0c4288u: goto P_0c0c4288;
case 0x0c0c428au: goto P_0c0c428a;
case 0x0c0c428cu: goto P_0c0c428c;
case 0x0c0c428eu: goto P_0c0c428e;
case 0x0c0c4290u: goto P_0c0c4290;
case 0x0c0c4292u: goto P_0c0c4292;
case 0x0c0c4294u: goto P_0c0c4294;
case 0x0c0c4296u: goto P_0c0c4296;
case 0x0c0c4298u: goto P_0c0c4298;
case 0x0c0c429au: goto P_0c0c429a;
case 0x0c0c429cu: goto P_0c0c429c;
case 0x0c0c429eu: goto P_0c0c429e;
case 0x0c0c42a0u: goto P_0c0c42a0;
case 0x0c0c42a2u: goto P_0c0c42a2;
case 0x0c0c42a4u: goto P_0c0c42a4;
case 0x0c0c42a6u: goto P_0c0c42a6;
case 0x0c0c42a8u: goto P_0c0c42a8;
case 0x0c0c42aau: goto P_0c0c42aa;
case 0x0c0c42acu: goto P_0c0c42ac;
case 0x0c0c42aeu: goto P_0c0c42ae;
case 0x0c0c42b0u: goto P_0c0c42b0;
case 0x0c0c42b2u: goto P_0c0c42b2;
case 0x0c0c42b4u: goto P_0c0c42b4;
case 0x0c0c42b6u: goto P_0c0c42b6;
case 0x0c0c42b8u: goto P_0c0c42b8;
case 0x0c0c42bau: goto P_0c0c42ba;
case 0x0c0c42bcu: goto P_0c0c42bc;
case 0x0c0c42beu: goto P_0c0c42be;
case 0x0c0c42c0u: goto P_0c0c42c0;
case 0x0c0c42c2u: goto P_0c0c42c2;
case 0x0c0c42c4u: goto P_0c0c42c4;
case 0x0c0c42c6u: goto P_0c0c42c6;
case 0x0c0c42c8u: goto P_0c0c42c8;
case 0x0c0c42cau: goto P_0c0c42ca;
case 0x0c0c42ccu: goto P_0c0c42cc;
case 0x0c0c42ceu: goto P_0c0c42ce;
case 0x0c0c42d0u: goto P_0c0c42d0;
case 0x0c0c42d2u: goto P_0c0c42d2;
case 0x0c0c42d4u: goto P_0c0c42d4;
case 0x0c0c42d6u: goto P_0c0c42d6;
case 0x0c0c42d8u: goto P_0c0c42d8;
case 0x0c0c42dau: goto P_0c0c42da;
case 0x0c0c42dcu: goto P_0c0c42dc;
case 0x0c0c42deu: goto P_0c0c42de;
case 0x0c0c42e0u: goto P_0c0c42e0;
case 0x0c0c42e2u: goto P_0c0c42e2;
case 0x0c0c42e4u: goto P_0c0c42e4;
case 0x0c0c42e6u: goto P_0c0c42e6;
case 0x0c0c42e8u: goto P_0c0c42e8;
case 0x0c0c42eau: goto P_0c0c42ea;
case 0x0c0c437cu: goto P_0c0c437c;
case 0x0c0c437eu: goto P_0c0c437e;
case 0x0c0c4380u: goto P_0c0c4380;
case 0x0c0c4382u: goto P_0c0c4382;
case 0x0c0c4384u: goto P_0c0c4384;
case 0x0c0c4386u: goto P_0c0c4386;
case 0x0c0c4388u: goto P_0c0c4388;
case 0x0c0c438au: goto P_0c0c438a;
case 0x0c0c438cu: goto P_0c0c438c;
case 0x0c0c438eu: goto P_0c0c438e;
case 0x0c0c4390u: goto P_0c0c4390;
case 0x0c0c4392u: goto P_0c0c4392;
case 0x0c0c4394u: goto P_0c0c4394;
case 0x0c0c4396u: goto P_0c0c4396;
case 0x0c0c4398u: goto P_0c0c4398;
case 0x0c0c439au: goto P_0c0c439a;
case 0x0c0c439cu: goto P_0c0c439c;
case 0x0c0c439eu: goto P_0c0c439e;
case 0x0c0c43a0u: goto P_0c0c43a0;
case 0x0c0c43a2u: goto P_0c0c43a2;
case 0x0c0c43a4u: goto P_0c0c43a4;
case 0x0c0c43a6u: goto P_0c0c43a6;
case 0x0c0c43a8u: goto P_0c0c43a8;
case 0x0c0c43aau: goto P_0c0c43aa;
case 0x0c0c43acu: goto P_0c0c43ac;
case 0x0c0c43aeu: goto P_0c0c43ae;
case 0x0c0c43b0u: goto P_0c0c43b0;
case 0x0c0c43b2u: goto P_0c0c43b2;
case 0x0c0c43b4u: goto P_0c0c43b4;
case 0x0c0c43b6u: goto P_0c0c43b6;
case 0x0c0c43b8u: goto P_0c0c43b8;
case 0x0c0c43bau: goto P_0c0c43ba;
case 0x0c0c43bcu: goto P_0c0c43bc;
case 0x0c0c43beu: goto P_0c0c43be;
case 0x0c0c43c0u: goto P_0c0c43c0;
case 0x0c0c43c2u: goto P_0c0c43c2;
case 0x0c0c43c4u: goto P_0c0c43c4;
case 0x0c0c43c6u: goto P_0c0c43c6;
case 0x0c0c43c8u: goto P_0c0c43c8;
case 0x0c0c43cau: goto P_0c0c43ca;
case 0x0c0c43ccu: goto P_0c0c43cc;
case 0x0c0c43ceu: goto P_0c0c43ce;
case 0x0c0c43d0u: goto P_0c0c43d0;
case 0x0c0c43d2u: goto P_0c0c43d2;
case 0x0c0c43d4u: goto P_0c0c43d4;
case 0x0c0c43d6u: goto P_0c0c43d6;
case 0x0c0c43d8u: goto P_0c0c43d8;
case 0x0c0c43dau: goto P_0c0c43da;
case 0x0c0c43dcu: goto P_0c0c43dc;
case 0x0c0c43deu: goto P_0c0c43de;
case 0x0c0c43e0u: goto P_0c0c43e0;
case 0x0c0c43e2u: goto P_0c0c43e2;
case 0x0c0c43e4u: goto P_0c0c43e4;
case 0x0c0c43e6u: goto P_0c0c43e6;
case 0x0c0c43e8u: goto P_0c0c43e8;
case 0x0c0c43eau: goto P_0c0c43ea;
case 0x0c0c43ecu: goto P_0c0c43ec;
case 0x0c0c43eeu: goto P_0c0c43ee;
case 0x0c0c43f0u: goto P_0c0c43f0;
case 0x0c0c43f2u: goto P_0c0c43f2;
case 0x0c0c43f4u: goto P_0c0c43f4;
case 0x0c0c43f6u: goto P_0c0c43f6;
case 0x0c0c43f8u: goto P_0c0c43f8;
case 0x0c0c43fau: goto P_0c0c43fa;
case 0x0c0c43fcu: goto P_0c0c43fc;
case 0x0c0c43feu: goto P_0c0c43fe;
case 0x0c0c4400u: goto P_0c0c4400;
case 0x0c0c4402u: goto P_0c0c4402;
case 0x0c0c4404u: goto P_0c0c4404;
case 0x0c0c4406u: goto P_0c0c4406;
case 0x0c0c4408u: goto P_0c0c4408;
case 0x0c0c440au: goto P_0c0c440a;
case 0x0c0c440cu: goto P_0c0c440c;
case 0x0c0c440eu: goto P_0c0c440e;
case 0x0c0c4410u: goto P_0c0c4410;
case 0x0c0c4412u: goto P_0c0c4412;
case 0x0c0c4414u: goto P_0c0c4414;
case 0x0c0c4416u: goto P_0c0c4416;
case 0x0c0c4418u: goto P_0c0c4418;
case 0x0c0c441au: goto P_0c0c441a;
case 0x0c0c441cu: goto P_0c0c441c;
case 0x0c0c441eu: goto P_0c0c441e;
case 0x0c0c4420u: goto P_0c0c4420;
case 0x0c0c4422u: goto P_0c0c4422;
case 0x0c0c4424u: goto P_0c0c4424;
case 0x0c0c4426u: goto P_0c0c4426;
case 0x0c0c4428u: goto P_0c0c4428;
case 0x0c0c442au: goto P_0c0c442a;
case 0x0c0c442cu: goto P_0c0c442c;
case 0x0c0c442eu: goto P_0c0c442e;
case 0x0c0c4430u: goto P_0c0c4430;
case 0x0c0c4432u: goto P_0c0c4432;
case 0x0c0c4434u: goto P_0c0c4434;
case 0x0c0c4436u: goto P_0c0c4436;
case 0x0c0c4438u: goto P_0c0c4438;
case 0x0c0c443au: goto P_0c0c443a;
case 0x0c0c443cu: goto P_0c0c443c;
case 0x0c0c443eu: goto P_0c0c443e;
case 0x0c0c4440u: goto P_0c0c4440;
case 0x0c0c4488u: goto P_0c0c4488;
case 0x0c0c448au: goto P_0c0c448a;
case 0x0c0c448cu: goto P_0c0c448c;
case 0x0c0c448eu: goto P_0c0c448e;
case 0x0c0c4490u: goto P_0c0c4490;
case 0x0c0c4492u: goto P_0c0c4492;
case 0x0c0c4494u: goto P_0c0c4494;
case 0x0c0c4496u: goto P_0c0c4496;
case 0x0c0c4498u: goto P_0c0c4498;
case 0x0c0c449au: goto P_0c0c449a;
case 0x0c0c449cu: goto P_0c0c449c;
case 0x0c0c449eu: goto P_0c0c449e;
case 0x0c0c44a0u: goto P_0c0c44a0;
case 0x0c0c44a2u: goto P_0c0c44a2;
case 0x0c0c44a4u: goto P_0c0c44a4;
case 0x0c0c44a6u: goto P_0c0c44a6;
case 0x0c0c44a8u: goto P_0c0c44a8;
case 0x0c0c44aau: goto P_0c0c44aa;
case 0x0c0c44acu: goto P_0c0c44ac;
case 0x0c0c44aeu: goto P_0c0c44ae;
case 0x0c0c44b0u: goto P_0c0c44b0;
case 0x0c0c44b2u: goto P_0c0c44b2;
case 0x0c0c44b4u: goto P_0c0c44b4;
case 0x0c0c44b6u: goto P_0c0c44b6;
case 0x0c0c44b8u: goto P_0c0c44b8;
case 0x0c0c44bau: goto P_0c0c44ba;
case 0x0c0c44bcu: goto P_0c0c44bc;
case 0x0c0c44beu: goto P_0c0c44be;
case 0x0c0c44c0u: goto P_0c0c44c0;
case 0x0c0c44c2u: goto P_0c0c44c2;
case 0x0c0c44c4u: goto P_0c0c44c4;
case 0x0c0c44c6u: goto P_0c0c44c6;
case 0x0c0c44c8u: goto P_0c0c44c8;
case 0x0c0c44cau: goto P_0c0c44ca;
case 0x0c0c44ccu: goto P_0c0c44cc;
case 0x0c0c44ceu: goto P_0c0c44ce;
case 0x0c0c44d0u: goto P_0c0c44d0;
case 0x0c0c44d2u: goto P_0c0c44d2;
case 0x0c0c44d4u: goto P_0c0c44d4;
case 0x0c0c44d6u: goto P_0c0c44d6;
case 0x0c0c44d8u: goto P_0c0c44d8;
case 0x0c0c44dau: goto P_0c0c44da;
case 0x0c0c44dcu: goto P_0c0c44dc;
case 0x0c0c44deu: goto P_0c0c44de;
case 0x0c0c44e0u: goto P_0c0c44e0;
case 0x0c0c44e2u: goto P_0c0c44e2;
case 0x0c0c44e4u: goto P_0c0c44e4;
case 0x0c0c44e6u: goto P_0c0c44e6;
case 0x0c0c44e8u: goto P_0c0c44e8;
case 0x0c0c44eau: goto P_0c0c44ea;
case 0x0c0c44fcu: goto P_0c0c44fc;
case 0x0c0c44feu: goto P_0c0c44fe;
case 0x0c0c4500u: goto P_0c0c4500;
case 0x0c0c4502u: goto P_0c0c4502;
case 0x0c0c4504u: goto P_0c0c4504;
case 0x0c0c4506u: goto P_0c0c4506;
case 0x0c0c4508u: goto P_0c0c4508;
case 0x0c0c450au: goto P_0c0c450a;
case 0x0c0c450cu: goto P_0c0c450c;
case 0x0c0c450eu: goto P_0c0c450e;
case 0x0c0c4510u: goto P_0c0c4510;
case 0x0c0c4512u: goto P_0c0c4512;
case 0x0c0c4514u: goto P_0c0c4514;
case 0x0c0c4516u: goto P_0c0c4516;
case 0x0c0c4518u: goto P_0c0c4518;
case 0x0c0c451au: goto P_0c0c451a;
case 0x0c0c451cu: goto P_0c0c451c;
case 0x0c0c451eu: goto P_0c0c451e;
case 0x0c0c4520u: goto P_0c0c4520;
case 0x0c0c4522u: goto P_0c0c4522;
case 0x0c0c4524u: goto P_0c0c4524;
case 0x0c0c4526u: goto P_0c0c4526;
case 0x0c0c4528u: goto P_0c0c4528;
case 0x0c0c452au: goto P_0c0c452a;
case 0x0c0c452cu: goto P_0c0c452c;
case 0x0c0c452eu: goto P_0c0c452e;
case 0x0c0c4530u: goto P_0c0c4530;
case 0x0c0c4532u: goto P_0c0c4532;
case 0x0c0c4534u: goto P_0c0c4534;
case 0x0c0c4536u: goto P_0c0c4536;
case 0x0c0c4538u: goto P_0c0c4538;
case 0x0c0c453au: goto P_0c0c453a;
case 0x0c0c453cu: goto P_0c0c453c;
case 0x0c0c453eu: goto P_0c0c453e;
case 0x0c0c4540u: goto P_0c0c4540;
case 0x0c0c4542u: goto P_0c0c4542;
case 0x0c0c4544u: goto P_0c0c4544;
case 0x0c0c4546u: goto P_0c0c4546;
case 0x0c0c4548u: goto P_0c0c4548;
case 0x0c0c454au: goto P_0c0c454a;
case 0x0c0c454cu: goto P_0c0c454c;
case 0x0c0c454eu: goto P_0c0c454e;
case 0x0c0c4550u: goto P_0c0c4550;
case 0x0c0c4552u: goto P_0c0c4552;
case 0x0c0c4554u: goto P_0c0c4554;
case 0x0c0c4556u: goto P_0c0c4556;
case 0x0c0c4558u: goto P_0c0c4558;
case 0x0c0c455au: goto P_0c0c455a;
case 0x0c0c455cu: goto P_0c0c455c;
case 0x0c0c455eu: goto P_0c0c455e;
case 0x0c0c4560u: goto P_0c0c4560;
case 0x0c0c4562u: goto P_0c0c4562;
case 0x0c0c4564u: goto P_0c0c4564;
case 0x0c0c4566u: goto P_0c0c4566;
case 0x0c0c4568u: goto P_0c0c4568;
case 0x0c0c456au: goto P_0c0c456a;
case 0x0c0c456cu: goto P_0c0c456c;
case 0x0c0c456eu: goto P_0c0c456e;
case 0x0c0c4570u: goto P_0c0c4570;
case 0x0c0c4572u: goto P_0c0c4572;
case 0x0c0c4574u: goto P_0c0c4574;
case 0x0c0c4576u: goto P_0c0c4576;
case 0x0c0c4578u: goto P_0c0c4578;
case 0x0c0c457au: goto P_0c0c457a;
case 0x0c0c457cu: goto P_0c0c457c;
case 0x0c0c457eu: goto P_0c0c457e;
case 0x0c0c4580u: goto P_0c0c4580;
case 0x0c0c4582u: goto P_0c0c4582;
case 0x0c0c4584u: goto P_0c0c4584;
case 0x0c0c4586u: goto P_0c0c4586;
case 0x0c0c4588u: goto P_0c0c4588;
case 0x0c0c458au: goto P_0c0c458a;
case 0x0c0c458cu: goto P_0c0c458c;
case 0x0c0c458eu: goto P_0c0c458e;
case 0x0c0c4590u: goto P_0c0c4590;
case 0x0c0c4592u: goto P_0c0c4592;
case 0x0c0c4594u: goto P_0c0c4594;
case 0x0c0c4596u: goto P_0c0c4596;
case 0x0c0c4598u: goto P_0c0c4598;
case 0x0c0c459au: goto P_0c0c459a;
case 0x0c0c459cu: goto P_0c0c459c;
case 0x0c0c459eu: goto P_0c0c459e;
case 0x0c0c45a0u: goto P_0c0c45a0;
case 0x0c0c45a2u: goto P_0c0c45a2;
case 0x0c0c45a4u: goto P_0c0c45a4;
case 0x0c0c45a6u: goto P_0c0c45a6;
case 0x0c0c45a8u: goto P_0c0c45a8;
case 0x0c0c45aau: goto P_0c0c45aa;
case 0x0c0c45acu: goto P_0c0c45ac;
case 0x0c0c45aeu: goto P_0c0c45ae;
case 0x0c0c45b0u: goto P_0c0c45b0;
case 0x0c0c45b2u: goto P_0c0c45b2;
case 0x0c0c45b4u: goto P_0c0c45b4;
case 0x0c0c45b6u: goto P_0c0c45b6;
case 0x0c0c45b8u: goto P_0c0c45b8;
case 0x0c0c45bau: goto P_0c0c45ba;
case 0x0c0c45bcu: goto P_0c0c45bc;
case 0x0c0c45beu: goto P_0c0c45be;
case 0x0c0c45c0u: goto P_0c0c45c0;
case 0x0c0c45c2u: goto P_0c0c45c2;
case 0x0c0c45c4u: goto P_0c0c45c4;
case 0x0c0c45c6u: goto P_0c0c45c6;
case 0x0c0c45c8u: goto P_0c0c45c8;
case 0x0c0c45cau: goto P_0c0c45ca;
case 0x0c0c45ccu: goto P_0c0c45cc;
case 0x0c0c45ceu: goto P_0c0c45ce;
case 0x0c0c45d0u: goto P_0c0c45d0;
case 0x0c0c45d2u: goto P_0c0c45d2;
case 0x0c0c45d4u: goto P_0c0c45d4;
case 0x0c0c45d6u: goto P_0c0c45d6;
case 0x0c0c45d8u: goto P_0c0c45d8;
case 0x0c0c45dau: goto P_0c0c45da;
case 0x0c0c45dcu: goto P_0c0c45dc;
case 0x0c0c45deu: goto P_0c0c45de;
case 0x0c0c45e0u: goto P_0c0c45e0;
case 0x0c0c45e2u: goto P_0c0c45e2;
case 0x0c0c45e4u: goto P_0c0c45e4;
case 0x0c0c45e6u: goto P_0c0c45e6;
case 0x0c0c45e8u: goto P_0c0c45e8;
case 0x0c0c45eau: goto P_0c0c45ea;
case 0x0c0c45ecu: goto P_0c0c45ec;
case 0x0c0c45eeu: goto P_0c0c45ee;
case 0x0c0c45f0u: goto P_0c0c45f0;
case 0x0c0c45f2u: goto P_0c0c45f2;
case 0x0c0c45f4u: goto P_0c0c45f4;
case 0x0c0c45f6u: goto P_0c0c45f6;
case 0x0c0c45f8u: goto P_0c0c45f8;
case 0x0c0c45fau: goto P_0c0c45fa;
case 0x0c0c45fcu: goto P_0c0c45fc;
case 0x0c0c45feu: goto P_0c0c45fe;
case 0x0c0c4600u: goto P_0c0c4600;
case 0x0c0c4602u: goto P_0c0c4602;
case 0x0c0c4604u: goto P_0c0c4604;
case 0x0c0c4606u: goto P_0c0c4606;
case 0x0c0c4608u: goto P_0c0c4608;
case 0x0c0c460au: goto P_0c0c460a;
case 0x0c0c460cu: goto P_0c0c460c;
case 0x0c0c460eu: goto P_0c0c460e;
case 0x0c0c4610u: goto P_0c0c4610;
case 0x0c0c4612u: goto P_0c0c4612;
case 0x0c0c4614u: goto P_0c0c4614;
case 0x0c0c4616u: goto P_0c0c4616;
case 0x0c0c4618u: goto P_0c0c4618;
case 0x0c0c461au: goto P_0c0c461a;
case 0x0c0c461cu: goto P_0c0c461c;
case 0x0c0c461eu: goto P_0c0c461e;
case 0x0c0c4620u: goto P_0c0c4620;
case 0x0c0c4622u: goto P_0c0c4622;
case 0x0c0c4624u: goto P_0c0c4624;
case 0x0c0c4626u: goto P_0c0c4626;
case 0x0c0c4628u: goto P_0c0c4628;
case 0x0c0c462au: goto P_0c0c462a;
case 0x0c0c462cu: goto P_0c0c462c;
case 0x0c0c462eu: goto P_0c0c462e;
case 0x0c0c4668u: goto P_0c0c4668;
case 0x0c0c466au: goto P_0c0c466a;
case 0x0c0c466cu: goto P_0c0c466c;
case 0x0c0c466eu: goto P_0c0c466e;
case 0x0c0c4670u: goto P_0c0c4670;
case 0x0c0c4672u: goto P_0c0c4672;
case 0x0c0c4674u: goto P_0c0c4674;
case 0x0c0c4676u: goto P_0c0c4676;
case 0x0c0c4678u: goto P_0c0c4678;
case 0x0c0c467au: goto P_0c0c467a;
case 0x0c0c467cu: goto P_0c0c467c;
case 0x0c0c467eu: goto P_0c0c467e;
case 0x0c0c4680u: goto P_0c0c4680;
case 0x0c0c4682u: goto P_0c0c4682;
case 0x0c0c4684u: goto P_0c0c4684;
case 0x0c0c4686u: goto P_0c0c4686;
case 0x0c0c4688u: goto P_0c0c4688;
case 0x0c0c468au: goto P_0c0c468a;
case 0x0c0c468cu: goto P_0c0c468c;
case 0x0c0c468eu: goto P_0c0c468e;
case 0x0c0c4690u: goto P_0c0c4690;
case 0x0c0c4692u: goto P_0c0c4692;
case 0x0c0c4694u: goto P_0c0c4694;
case 0x0c0c4696u: goto P_0c0c4696;
case 0x0c0c4698u: goto P_0c0c4698;
case 0x0c0c469au: goto P_0c0c469a;
case 0x0c0c469cu: goto P_0c0c469c;
case 0x0c0c469eu: goto P_0c0c469e;
case 0x0c0c46a0u: goto P_0c0c46a0;
case 0x0c0c46a2u: goto P_0c0c46a2;
case 0x0c0c46a4u: goto P_0c0c46a4;
case 0x0c0c46a6u: goto P_0c0c46a6;
case 0x0c0c46a8u: goto P_0c0c46a8;
case 0x0c0c46aau: goto P_0c0c46aa;
case 0x0c0c46acu: goto P_0c0c46ac;
case 0x0c0c46aeu: goto P_0c0c46ae;
case 0x0c0c46b0u: goto P_0c0c46b0;
case 0x0c0c46b2u: goto P_0c0c46b2;
case 0x0c0c46b4u: goto P_0c0c46b4;
case 0x0c0c46b6u: goto P_0c0c46b6;
case 0x0c0c46b8u: goto P_0c0c46b8;
case 0x0c0c46bau: goto P_0c0c46ba;
case 0x0c0c46bcu: goto P_0c0c46bc;
case 0x0c0c46beu: goto P_0c0c46be;
case 0x0c0c46c0u: goto P_0c0c46c0;
case 0x0c0c46c2u: goto P_0c0c46c2;
case 0x0c0c46c4u: goto P_0c0c46c4;
case 0x0c0c46c6u: goto P_0c0c46c6;
case 0x0c0c46c8u: goto P_0c0c46c8;
case 0x0c0c46cau: goto P_0c0c46ca;
case 0x0c0c46ccu: goto P_0c0c46cc;
case 0x0c0c46ceu: goto P_0c0c46ce;
case 0x0c0c46d0u: goto P_0c0c46d0;
case 0x0c0c46d2u: goto P_0c0c46d2;
case 0x0c0c46d4u: goto P_0c0c46d4;
case 0x0c0c46d6u: goto P_0c0c46d6;
case 0x0c0c46d8u: goto P_0c0c46d8;
case 0x0c0c46dau: goto P_0c0c46da;
case 0x0c0c46dcu: goto P_0c0c46dc;
case 0x0c0c46deu: goto P_0c0c46de;
case 0x0c0c46e0u: goto P_0c0c46e0;
case 0x0c0c46e2u: goto P_0c0c46e2;
case 0x0c0c46e4u: goto P_0c0c46e4;
case 0x0c0c46e6u: goto P_0c0c46e6;
case 0x0c0c46e8u: goto P_0c0c46e8;
case 0x0c0c46eau: goto P_0c0c46ea;
case 0x0c0c46ecu: goto P_0c0c46ec;
case 0x0c0c46eeu: goto P_0c0c46ee;
case 0x0c0c46f0u: goto P_0c0c46f0;
case 0x0c0c46f2u: goto P_0c0c46f2;
case 0x0c0c46f4u: goto P_0c0c46f4;
case 0x0c0c46f6u: goto P_0c0c46f6;
case 0x0c0c46f8u: goto P_0c0c46f8;
case 0x0c0c46fau: goto P_0c0c46fa;
case 0x0c0c46fcu: goto P_0c0c46fc;
case 0x0c0c46feu: goto P_0c0c46fe;
case 0x0c0c4700u: goto P_0c0c4700;
case 0x0c0c4702u: goto P_0c0c4702;
case 0x0c0c4704u: goto P_0c0c4704;
case 0x0c0c4706u: goto P_0c0c4706;
case 0x0c0c4708u: goto P_0c0c4708;
case 0x0c0c470au: goto P_0c0c470a;
case 0x0c0c470cu: goto P_0c0c470c;
case 0x0c0c470eu: goto P_0c0c470e;
case 0x0c0c4710u: goto P_0c0c4710;
case 0x0c0c4712u: goto P_0c0c4712;
case 0x0c0c4714u: goto P_0c0c4714;
case 0x0c0c4716u: goto P_0c0c4716;
case 0x0c0c4718u: goto P_0c0c4718;
case 0x0c0c471au: goto P_0c0c471a;
case 0x0c0c471cu: goto P_0c0c471c;
case 0x0c0c471eu: goto P_0c0c471e;
case 0x0c0c4720u: goto P_0c0c4720;
case 0x0c0c4722u: goto P_0c0c4722;
case 0x0c0c4724u: goto P_0c0c4724;
case 0x0c0c4726u: goto P_0c0c4726;
case 0x0c0c4728u: goto P_0c0c4728;
case 0x0c0c472au: goto P_0c0c472a;
case 0x0c0c472cu: goto P_0c0c472c;
case 0x0c0c472eu: goto P_0c0c472e;
case 0x0c0c4730u: goto P_0c0c4730;
case 0x0c0c4732u: goto P_0c0c4732;
case 0x0c0c4734u: goto P_0c0c4734;
case 0x0c0c4736u: goto P_0c0c4736;
case 0x0c0c4738u: goto P_0c0c4738;
case 0x0c0c473au: goto P_0c0c473a;
case 0x0c0c473cu: goto P_0c0c473c;
case 0x0c0c473eu: goto P_0c0c473e;
case 0x0c0c4740u: goto P_0c0c4740;
case 0x0c0c4742u: goto P_0c0c4742;
case 0x0c0c4744u: goto P_0c0c4744;
case 0x0c0c4746u: goto P_0c0c4746;
case 0x0c0c4748u: goto P_0c0c4748;
case 0x0c0c474au: goto P_0c0c474a;
case 0x0c0c474cu: goto P_0c0c474c;
case 0x0c0c474eu: goto P_0c0c474e;
case 0x0c0c4780u: goto P_0c0c4780;
case 0x0c0c4782u: goto P_0c0c4782;
case 0x0c0c4784u: goto P_0c0c4784;
case 0x0c0c4786u: goto P_0c0c4786;
case 0x0c0c4788u: goto P_0c0c4788;
case 0x0c0c478au: goto P_0c0c478a;
case 0x0c0c478cu: goto P_0c0c478c;
case 0x0c0c478eu: goto P_0c0c478e;
case 0x0c0c4790u: goto P_0c0c4790;
case 0x0c0c4792u: goto P_0c0c4792;
case 0x0c0c4794u: goto P_0c0c4794;
case 0x0c0c4796u: goto P_0c0c4796;
case 0x0c0c4798u: goto P_0c0c4798;
case 0x0c0c479au: goto P_0c0c479a;
case 0x0c0c479cu: goto P_0c0c479c;
case 0x0c0c479eu: goto P_0c0c479e;
case 0x0c0c47a0u: goto P_0c0c47a0;
case 0x0c0c47a2u: goto P_0c0c47a2;
case 0x0c0c47a4u: goto P_0c0c47a4;
case 0x0c0c47a6u: goto P_0c0c47a6;
case 0x0c0c47a8u: goto P_0c0c47a8;
case 0x0c0c47aau: goto P_0c0c47aa;
case 0x0c0c47acu: goto P_0c0c47ac;
case 0x0c0c47aeu: goto P_0c0c47ae;
case 0x0c0c47b0u: goto P_0c0c47b0;
case 0x0c0c47b2u: goto P_0c0c47b2;
case 0x0c0c47b4u: goto P_0c0c47b4;
case 0x0c0c47b6u: goto P_0c0c47b6;
case 0x0c0c47b8u: goto P_0c0c47b8;
case 0x0c0c47bau: goto P_0c0c47ba;
case 0x0c0c47bcu: goto P_0c0c47bc;
case 0x0c0c47beu: goto P_0c0c47be;
case 0x0c0c47c0u: goto P_0c0c47c0;
case 0x0c0c47c2u: goto P_0c0c47c2;
case 0x0c0c47c4u: goto P_0c0c47c4;
case 0x0c0c47c6u: goto P_0c0c47c6;
case 0x0c0c47c8u: goto P_0c0c47c8;
case 0x0c0c47cau: goto P_0c0c47ca;
case 0x0c0c47ccu: goto P_0c0c47cc;
case 0x0c0c47ceu: goto P_0c0c47ce;
case 0x0c0c47d0u: goto P_0c0c47d0;
case 0x0c0c47d2u: goto P_0c0c47d2;
case 0x0c0c47d4u: goto P_0c0c47d4;
case 0x0c0c47d6u: goto P_0c0c47d6;
case 0x0c0c47d8u: goto P_0c0c47d8;
case 0x0c0c47dau: goto P_0c0c47da;
case 0x0c0c47dcu: goto P_0c0c47dc;
case 0x0c0c47deu: goto P_0c0c47de;
case 0x0c0c47e0u: goto P_0c0c47e0;
case 0x0c0c47e2u: goto P_0c0c47e2;
case 0x0c0c47e4u: goto P_0c0c47e4;
case 0x0c0c47e6u: goto P_0c0c47e6;
case 0x0c0c47e8u: goto P_0c0c47e8;
case 0x0c0c47eau: goto P_0c0c47ea;
case 0x0c0c47ecu: goto P_0c0c47ec;
case 0x0c0c47eeu: goto P_0c0c47ee;
case 0x0c0c47f0u: goto P_0c0c47f0;
case 0x0c0c47f2u: goto P_0c0c47f2;
case 0x0c0c47f4u: goto P_0c0c47f4;
case 0x0c0c47f6u: goto P_0c0c47f6;
case 0x0c0c47f8u: goto P_0c0c47f8;
case 0x0c0c47fau: goto P_0c0c47fa;
case 0x0c0c47fcu: goto P_0c0c47fc;
case 0x0c0c47feu: goto P_0c0c47fe;
case 0x0c0c4800u: goto P_0c0c4800;
case 0x0c0c4802u: goto P_0c0c4802;
case 0x0c0c4804u: goto P_0c0c4804;
case 0x0c0c4806u: goto P_0c0c4806;
case 0x0c0c4808u: goto P_0c0c4808;
case 0x0c0c480au: goto P_0c0c480a;
case 0x0c0c480cu: goto P_0c0c480c;
case 0x0c0c480eu: goto P_0c0c480e;
case 0x0c0c4810u: goto P_0c0c4810;
case 0x0c0c4812u: goto P_0c0c4812;
case 0x0c0c4814u: goto P_0c0c4814;
case 0x0c0c4816u: goto P_0c0c4816;
case 0x0c0c4818u: goto P_0c0c4818;
case 0x0c0c481au: goto P_0c0c481a;
case 0x0c0c481cu: goto P_0c0c481c;
case 0x0c0c481eu: goto P_0c0c481e;
case 0x0c0c4820u: goto P_0c0c4820;
case 0x0c0c4822u: goto P_0c0c4822;
case 0x0c0c4824u: goto P_0c0c4824;
case 0x0c0c4826u: goto P_0c0c4826;
case 0x0c0c4828u: goto P_0c0c4828;
case 0x0c0c482au: goto P_0c0c482a;
case 0x0c0c482cu: goto P_0c0c482c;
case 0x0c0c482eu: goto P_0c0c482e;
case 0x0c0c4830u: goto P_0c0c4830;
case 0x0c0c4832u: goto P_0c0c4832;
case 0x0c0c4834u: goto P_0c0c4834;
case 0x0c0c4836u: goto P_0c0c4836;
case 0x0c0c4838u: goto P_0c0c4838;
case 0x0c0c483au: goto P_0c0c483a;
case 0x0c0c483cu: goto P_0c0c483c;
case 0x0c0c483eu: goto P_0c0c483e;
case 0x0c0c4840u: goto P_0c0c4840;
case 0x0c0c4842u: goto P_0c0c4842;
case 0x0c0c4844u: goto P_0c0c4844;
case 0x0c0c4846u: goto P_0c0c4846;
case 0x0c0c4848u: goto P_0c0c4848;
case 0x0c0c484au: goto P_0c0c484a;
case 0x0c0c4874u: goto P_0c0c4874;
case 0x0c0c4876u: goto P_0c0c4876;
case 0x0c0c4878u: goto P_0c0c4878;
case 0x0c0c487au: goto P_0c0c487a;
case 0x0c0c487cu: goto P_0c0c487c;
case 0x0c0c487eu: goto P_0c0c487e;
case 0x0c0c4880u: goto P_0c0c4880;
case 0x0c0c4882u: goto P_0c0c4882;
case 0x0c0c4884u: goto P_0c0c4884;
case 0x0c0c4886u: goto P_0c0c4886;
case 0x0c0c4888u: goto P_0c0c4888;
case 0x0c0c488au: goto P_0c0c488a;
case 0x0c0c488cu: goto P_0c0c488c;
case 0x0c0c488eu: goto P_0c0c488e;
case 0x0c0c4890u: goto P_0c0c4890;
case 0x0c0c4892u: goto P_0c0c4892;
case 0x0c0c4894u: goto P_0c0c4894;
case 0x0c0c4896u: goto P_0c0c4896;
case 0x0c0c4898u: goto P_0c0c4898;
case 0x0c0c489au: goto P_0c0c489a;
case 0x0c0c489cu: goto P_0c0c489c;
case 0x0c0c489eu: goto P_0c0c489e;
case 0x0c0c48a0u: goto P_0c0c48a0;
case 0x0c0c48a2u: goto P_0c0c48a2;
case 0x0c0c48a4u: goto P_0c0c48a4;
case 0x0c0c48a6u: goto P_0c0c48a6;
case 0x0c0c48a8u: goto P_0c0c48a8;
case 0x0c0c48aau: goto P_0c0c48aa;
case 0x0c0c48acu: goto P_0c0c48ac;
case 0x0c0c48aeu: goto P_0c0c48ae;
case 0x0c0c48b0u: goto P_0c0c48b0;
case 0x0c0c48b2u: goto P_0c0c48b2;
case 0x0c0c48b4u: goto P_0c0c48b4;
case 0x0c0c48b6u: goto P_0c0c48b6;
case 0x0c0c48b8u: goto P_0c0c48b8;
case 0x0c0c48bau: goto P_0c0c48ba;
case 0x0c0c48bcu: goto P_0c0c48bc;
case 0x0c0c48beu: goto P_0c0c48be;
case 0x0c0c48c0u: goto P_0c0c48c0;
case 0x0c0c48c2u: goto P_0c0c48c2;
case 0x0c0c48c4u: goto P_0c0c48c4;
case 0x0c0c48c6u: goto P_0c0c48c6;
case 0x0c0c48c8u: goto P_0c0c48c8;
case 0x0c0c48cau: goto P_0c0c48ca;
case 0x0c0c48ccu: goto P_0c0c48cc;
case 0x0c0c48ceu: goto P_0c0c48ce;
case 0x0c0c48d0u: goto P_0c0c48d0;
case 0x0c0c48d2u: goto P_0c0c48d2;
case 0x0c0c48d4u: goto P_0c0c48d4;
case 0x0c0c48d6u: goto P_0c0c48d6;
case 0x0c0c48d8u: goto P_0c0c48d8;
case 0x0c0c48dau: goto P_0c0c48da;
case 0x0c0c48dcu: goto P_0c0c48dc;
case 0x0c0c48deu: goto P_0c0c48de;
case 0x0c0c48e0u: goto P_0c0c48e0;
case 0x0c0c48e2u: goto P_0c0c48e2;
case 0x0c0c48e4u: goto P_0c0c48e4;
case 0x0c0c48e6u: goto P_0c0c48e6;
case 0x0c0c48e8u: goto P_0c0c48e8;
case 0x0c0c48eau: goto P_0c0c48ea;
case 0x0c0c48ecu: goto P_0c0c48ec;
case 0x0c0c48eeu: goto P_0c0c48ee;
case 0x0c0c48f0u: goto P_0c0c48f0;
case 0x0c0c48f2u: goto P_0c0c48f2;
case 0x0c0c48f4u: goto P_0c0c48f4;
case 0x0c0c48f6u: goto P_0c0c48f6;
case 0x0c0c48f8u: goto P_0c0c48f8;
case 0x0c0c48fau: goto P_0c0c48fa;
case 0x0c0c48fcu: goto P_0c0c48fc;
case 0x0c0c48feu: goto P_0c0c48fe;
case 0x0c0c4900u: goto P_0c0c4900;
case 0x0c0c4902u: goto P_0c0c4902;
case 0x0c0c4904u: goto P_0c0c4904;
case 0x0c0c4906u: goto P_0c0c4906;
case 0x0c0c4908u: goto P_0c0c4908;
case 0x0c0c490au: goto P_0c0c490a;
case 0x0c0c490cu: goto P_0c0c490c;
case 0x0c0c490eu: goto P_0c0c490e;
case 0x0c0c4910u: goto P_0c0c4910;
case 0x0c0c4912u: goto P_0c0c4912;
case 0x0c0c4914u: goto P_0c0c4914;
case 0x0c0c4916u: goto P_0c0c4916;
case 0x0c0c4918u: goto P_0c0c4918;
case 0x0c0c491au: goto P_0c0c491a;
case 0x0c0c491cu: goto P_0c0c491c;
case 0x0c0c491eu: goto P_0c0c491e;
case 0x0c0c4920u: goto P_0c0c4920;
case 0x0c0c4922u: goto P_0c0c4922;
case 0x0c0c4924u: goto P_0c0c4924;
case 0x0c0c4926u: goto P_0c0c4926;
case 0x0c0c4928u: goto P_0c0c4928;
case 0x0c0c492au: goto P_0c0c492a;
case 0x0c0c492cu: goto P_0c0c492c;
case 0x0c0c492eu: goto P_0c0c492e;
case 0x0c0c4930u: goto P_0c0c4930;
case 0x0c0c4932u: goto P_0c0c4932;
case 0x0c0c4934u: goto P_0c0c4934;
case 0x0c0c4936u: goto P_0c0c4936;
case 0x0c0c4938u: goto P_0c0c4938;
case 0x0c0c493au: goto P_0c0c493a;
case 0x0c0c493cu: goto P_0c0c493c;
case 0x0c0c493eu: goto P_0c0c493e;
case 0x0c0c4940u: goto P_0c0c4940;
case 0x0c0c4942u: goto P_0c0c4942;
case 0x0c0c4944u: goto P_0c0c4944;
case 0x0c0c4946u: goto P_0c0c4946;
case 0x0c0c4948u: goto P_0c0c4948;
case 0x0c0c494au: goto P_0c0c494a;
case 0x0c0c494cu: goto P_0c0c494c;
case 0x0c0c494eu: goto P_0c0c494e;
case 0x0c0c4950u: goto P_0c0c4950;
case 0x0c0c4952u: goto P_0c0c4952;
case 0x0c0c4954u: goto P_0c0c4954;
case 0x0c0c4956u: goto P_0c0c4956;
case 0x0c0c4958u: goto P_0c0c4958;
case 0x0c0c495au: goto P_0c0c495a;
case 0x0c0c495cu: goto P_0c0c495c;
case 0x0c0c495eu: goto P_0c0c495e;
case 0x0c0c4960u: goto P_0c0c4960;
case 0x0c0c4962u: goto P_0c0c4962;
case 0x0c0c4964u: goto P_0c0c4964;
case 0x0c0c4966u: goto P_0c0c4966;
case 0x0c0c4968u: goto P_0c0c4968;
case 0x0c0c496au: goto P_0c0c496a;
case 0x0c0c496cu: goto P_0c0c496c;
case 0x0c0c496eu: goto P_0c0c496e;
case 0x0c0c4970u: goto P_0c0c4970;
case 0x0c0c4972u: goto P_0c0c4972;
case 0x0c0c4974u: goto P_0c0c4974;
case 0x0c0c4976u: goto P_0c0c4976;
case 0x0c0c4978u: goto P_0c0c4978;
case 0x0c0c497au: goto P_0c0c497a;
case 0x0c0c497cu: goto P_0c0c497c;
case 0x0c0c497eu: goto P_0c0c497e;
case 0x0c0c4980u: goto P_0c0c4980;
case 0x0c0c4982u: goto P_0c0c4982;
case 0x0c0c4984u: goto P_0c0c4984;
case 0x0c0c4986u: goto P_0c0c4986;
case 0x0c0c4988u: goto P_0c0c4988;
case 0x0c0c498au: goto P_0c0c498a;
case 0x0c0c498cu: goto P_0c0c498c;
case 0x0c0c498eu: goto P_0c0c498e;
case 0x0c0c4990u: goto P_0c0c4990;
case 0x0c0c4992u: goto P_0c0c4992;
case 0x0c0c4994u: goto P_0c0c4994;
case 0x0c0c4996u: goto P_0c0c4996;
case 0x0c0c4998u: goto P_0c0c4998;
case 0x0c0c499au: goto P_0c0c499a;
case 0x0c0c499cu: goto P_0c0c499c;
case 0x0c0c499eu: goto P_0c0c499e;
case 0x0c0c49a0u: goto P_0c0c49a0;
case 0x0c0c49a2u: goto P_0c0c49a2;
case 0x0c0c49a4u: goto P_0c0c49a4;
case 0x0c0c49a6u: goto P_0c0c49a6;
case 0x0c0c49a8u: goto P_0c0c49a8;
case 0x0c0c49aau: goto P_0c0c49aa;
case 0x0c0c49e8u: goto P_0c0c49e8;
case 0x0c0c49eau: goto P_0c0c49ea;
case 0x0c0c49ecu: goto P_0c0c49ec;
case 0x0c0c49eeu: goto P_0c0c49ee;
case 0x0c0c49f0u: goto P_0c0c49f0;
case 0x0c0c49f2u: goto P_0c0c49f2;
case 0x0c0c49f4u: goto P_0c0c49f4;
case 0x0c0c49f6u: goto P_0c0c49f6;
case 0x0c0c49f8u: goto P_0c0c49f8;
case 0x0c0c49fau: goto P_0c0c49fa;
case 0x0c0c49fcu: goto P_0c0c49fc;
case 0x0c0c49feu: goto P_0c0c49fe;
case 0x0c0c4a00u: goto P_0c0c4a00;
case 0x0c0c4a02u: goto P_0c0c4a02;
case 0x0c0c4a04u: goto P_0c0c4a04;
case 0x0c0c4a06u: goto P_0c0c4a06;
case 0x0c0c4a08u: goto P_0c0c4a08;
case 0x0c0c4a0au: goto P_0c0c4a0a;
case 0x0c0c4a0cu: goto P_0c0c4a0c;
case 0x0c0c4a0eu: goto P_0c0c4a0e;
case 0x0c0c4a10u: goto P_0c0c4a10;
case 0x0c0c4a12u: goto P_0c0c4a12;
case 0x0c0c4a14u: goto P_0c0c4a14;
case 0x0c0c4a16u: goto P_0c0c4a16;
case 0x0c0c4a18u: goto P_0c0c4a18;
case 0x0c0c4a1au: goto P_0c0c4a1a;
case 0x0c0c4a1cu: goto P_0c0c4a1c;
case 0x0c0c4a1eu: goto P_0c0c4a1e;
case 0x0c0c4a20u: goto P_0c0c4a20;
case 0x0c0c4a22u: goto P_0c0c4a22;
case 0x0c0c4a24u: goto P_0c0c4a24;
case 0x0c0c4a26u: goto P_0c0c4a26;
case 0x0c0c4a28u: goto P_0c0c4a28;
case 0x0c0c4a2au: goto P_0c0c4a2a;
case 0x0c0c4a2cu: goto P_0c0c4a2c;
case 0x0c0c4a2eu: goto P_0c0c4a2e;
case 0x0c0c4a30u: goto P_0c0c4a30;
case 0x0c0c4a32u: goto P_0c0c4a32;
case 0x0c0c4a34u: goto P_0c0c4a34;
case 0x0c0c4a36u: goto P_0c0c4a36;
case 0x0c0c4a38u: goto P_0c0c4a38;
case 0x0c0c4a3au: goto P_0c0c4a3a;
case 0x0c0c4a3cu: goto P_0c0c4a3c;
case 0x0c0c4a3eu: goto P_0c0c4a3e;
case 0x0c0c4a40u: goto P_0c0c4a40;
case 0x0c0c4a42u: goto P_0c0c4a42;
case 0x0c0c4a44u: goto P_0c0c4a44;
case 0x0c0c4a46u: goto P_0c0c4a46;
case 0x0c0c4a48u: goto P_0c0c4a48;
case 0x0c0c4a4au: goto P_0c0c4a4a;
case 0x0c0c4a4cu: goto P_0c0c4a4c;
case 0x0c0c4a4eu: goto P_0c0c4a4e;
case 0x0c0c4a50u: goto P_0c0c4a50;
case 0x0c0c4a52u: goto P_0c0c4a52;
case 0x0c0c4a54u: goto P_0c0c4a54;
case 0x0c0c4a56u: goto P_0c0c4a56;
case 0x0c0c4a58u: goto P_0c0c4a58;
case 0x0c0c4a5au: goto P_0c0c4a5a;
case 0x0c0c4a5cu: goto P_0c0c4a5c;
case 0x0c0c4a5eu: goto P_0c0c4a5e;
case 0x0c0c4a60u: goto P_0c0c4a60;
case 0x0c0c4a62u: goto P_0c0c4a62;
case 0x0c0c4a64u: goto P_0c0c4a64;
case 0x0c0c4a66u: goto P_0c0c4a66;
case 0x0c0c4a68u: goto P_0c0c4a68;
case 0x0c0c4a6au: goto P_0c0c4a6a;
case 0x0c0c4a6cu: goto P_0c0c4a6c;
case 0x0c0c4a6eu: goto P_0c0c4a6e;
case 0x0c0c4a70u: goto P_0c0c4a70;
case 0x0c0c4a72u: goto P_0c0c4a72;
case 0x0c0c4a74u: goto P_0c0c4a74;
case 0x0c0c4a76u: goto P_0c0c4a76;
case 0x0c0c4a78u: goto P_0c0c4a78;
case 0x0c0c4a7au: goto P_0c0c4a7a;
case 0x0c0c4a7cu: goto P_0c0c4a7c;
case 0x0c0c4a7eu: goto P_0c0c4a7e;
case 0x0c0c4a80u: goto P_0c0c4a80;
case 0x0c0c4a82u: goto P_0c0c4a82;
case 0x0c0c4a84u: goto P_0c0c4a84;
case 0x0c0c4a86u: goto P_0c0c4a86;
case 0x0c0c4a88u: goto P_0c0c4a88;
case 0x0c0c4a8au: goto P_0c0c4a8a;
case 0x0c0c4a8cu: goto P_0c0c4a8c;
case 0x0c0c4a8eu: goto P_0c0c4a8e;
case 0x0c0c4a90u: goto P_0c0c4a90;
case 0x0c0c4a92u: goto P_0c0c4a92;
case 0x0c0c4a94u: goto P_0c0c4a94;
case 0x0c0c4a96u: goto P_0c0c4a96;
case 0x0c0c4a98u: goto P_0c0c4a98;
case 0x0c0c4a9au: goto P_0c0c4a9a;
case 0x0c0c4a9cu: goto P_0c0c4a9c;
case 0x0c0c4a9eu: goto P_0c0c4a9e;
case 0x0c0c4aa0u: goto P_0c0c4aa0;
case 0x0c0c4aa2u: goto P_0c0c4aa2;
case 0x0c0c4aa4u: goto P_0c0c4aa4;
case 0x0c0c4aa6u: goto P_0c0c4aa6;
case 0x0c0c4aa8u: goto P_0c0c4aa8;
case 0x0c0c4aaau: goto P_0c0c4aaa;
case 0x0c0c4aacu: goto P_0c0c4aac;
case 0x0c0c4aaeu: goto P_0c0c4aae;
case 0x0c0c4ab0u: goto P_0c0c4ab0;
case 0x0c0c4ab2u: goto P_0c0c4ab2;
case 0x0c0c4ab4u: goto P_0c0c4ab4;
case 0x0c0c4ab6u: goto P_0c0c4ab6;
case 0x0c0c4ab8u: goto P_0c0c4ab8;
case 0x0c0c4abau: goto P_0c0c4aba;
case 0x0c0c4abcu: goto P_0c0c4abc;
case 0x0c0c4abeu: goto P_0c0c4abe;
case 0x0c0c4ac0u: goto P_0c0c4ac0;
case 0x0c0c4ac2u: goto P_0c0c4ac2;
case 0x0c0c4af4u: goto P_0c0c4af4;
case 0x0c0c4af6u: goto P_0c0c4af6;
case 0x0c0c4af8u: goto P_0c0c4af8;
case 0x0c0c4afau: goto P_0c0c4afa;
case 0x0c0c4afcu: goto P_0c0c4afc;
case 0x0c0c4afeu: goto P_0c0c4afe;
case 0x0c0c4b00u: goto P_0c0c4b00;
case 0x0c0c4b02u: goto P_0c0c4b02;
case 0x0c0c4b04u: goto P_0c0c4b04;
case 0x0c0c4b06u: goto P_0c0c4b06;
case 0x0c0c4b08u: goto P_0c0c4b08;
case 0x0c0c4b0au: goto P_0c0c4b0a;
case 0x0c0c4b0cu: goto P_0c0c4b0c;
case 0x0c0c4b0eu: goto P_0c0c4b0e;
case 0x0c0c4b10u: goto P_0c0c4b10;
case 0x0c0c4b12u: goto P_0c0c4b12;
case 0x0c0c4b14u: goto P_0c0c4b14;
case 0x0c0c4b16u: goto P_0c0c4b16;
case 0x0c0c4b18u: goto P_0c0c4b18;
case 0x0c0c4b1au: goto P_0c0c4b1a;
case 0x0c0c4b1cu: goto P_0c0c4b1c;
case 0x0c0c4b1eu: goto P_0c0c4b1e;
case 0x0c0c4b20u: goto P_0c0c4b20;
case 0x0c0c4b22u: goto P_0c0c4b22;
case 0x0c0c4b24u: goto P_0c0c4b24;
case 0x0c0c4b26u: goto P_0c0c4b26;
case 0x0c0c4b28u: goto P_0c0c4b28;
case 0x0c0c4b2au: goto P_0c0c4b2a;
case 0x0c0c4b2cu: goto P_0c0c4b2c;
case 0x0c0c4b2eu: goto P_0c0c4b2e;
case 0x0c0c4b30u: goto P_0c0c4b30;
case 0x0c0c4b32u: goto P_0c0c4b32;
case 0x0c0c4b34u: goto P_0c0c4b34;
case 0x0c0c4b36u: goto P_0c0c4b36;
case 0x0c0c4b38u: goto P_0c0c4b38;
case 0x0c0c4b3au: goto P_0c0c4b3a;
case 0x0c0c4b3cu: goto P_0c0c4b3c;
case 0x0c0c4b3eu: goto P_0c0c4b3e;
case 0x0c0c4b40u: goto P_0c0c4b40;
case 0x0c0c4b42u: goto P_0c0c4b42;
case 0x0c0c4b44u: goto P_0c0c4b44;
case 0x0c0c4b46u: goto P_0c0c4b46;
case 0x0c0c4b48u: goto P_0c0c4b48;
case 0x0c0c4b4au: goto P_0c0c4b4a;
case 0x0c0c4b4cu: goto P_0c0c4b4c;
case 0x0c0c4b4eu: goto P_0c0c4b4e;
case 0x0c0c4b50u: goto P_0c0c4b50;
case 0x0c0c4b52u: goto P_0c0c4b52;
case 0x0c0c4b54u: goto P_0c0c4b54;
case 0x0c0c4b56u: goto P_0c0c4b56;
case 0x0c0c4b58u: goto P_0c0c4b58;
case 0x0c0c4b5au: goto P_0c0c4b5a;
case 0x0c0c4b5cu: goto P_0c0c4b5c;
case 0x0c0c4b5eu: goto P_0c0c4b5e;
case 0x0c0c4b60u: goto P_0c0c4b60;
case 0x0c0c4b62u: goto P_0c0c4b62;
case 0x0c0c4b64u: goto P_0c0c4b64;
case 0x0c0c4b66u: goto P_0c0c4b66;
case 0x0c0c4b68u: goto P_0c0c4b68;
case 0x0c0c4b6au: goto P_0c0c4b6a;
case 0x0c0c4b6cu: goto P_0c0c4b6c;
case 0x0c0c4b6eu: goto P_0c0c4b6e;
case 0x0c0c4b70u: goto P_0c0c4b70;
case 0x0c0c4b72u: goto P_0c0c4b72;
case 0x0c0c4b74u: goto P_0c0c4b74;
case 0x0c0c4b76u: goto P_0c0c4b76;
case 0x0c0c4b78u: goto P_0c0c4b78;
case 0x0c0c4b7au: goto P_0c0c4b7a;
case 0x0c0c4b7cu: goto P_0c0c4b7c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c41be: /* original 2fe6, guest PC 0x0c0c41be */
if(!s->budget--) { s->failed_pc=0x0c0c41beu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c41c0;
P_0c0c41c0: /* original 2fd6, guest PC 0x0c0c41c0 */
if(!s->budget--) { s->failed_pc=0x0c0c41c0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c41c2;
P_0c0c41c2: /* original 2fc6, guest PC 0x0c0c41c2 */
if(!s->budget--) { s->failed_pc=0x0c0c41c2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c41c4;
P_0c0c41c4: /* original 2fb6, guest PC 0x0c0c41c4 */
if(!s->budget--) { s->failed_pc=0x0c0c41c4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c41c6;
P_0c0c41c6: /* original 2fa6, guest PC 0x0c0c41c6 */
if(!s->budget--) { s->failed_pc=0x0c0c41c6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c41c8;
P_0c0c41c8: /* original de0f, guest PC 0x0c0c41c8 */
if(!s->budget--) { s->failed_pc=0x0c0c41c8u; return 0; }
r[14]=read(ram,0x0c0c4208u,4);
goto P_0c0c41ca;
P_0c0c41ca: /* original 9011, guest PC 0x0c0c41ca */
if(!s->budget--) { s->failed_pc=0x0c0c41cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c41f0u,2);
goto P_0c0c41cc;
P_0c0c41cc: /* original 4f22, guest PC 0x0c0c41cc */
if(!s->budget--) { s->failed_pc=0x0c0c41ccu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c41ce;
P_0c0c41ce: /* original 00ec, guest PC 0x0c0c41ce */
if(!s->budget--) { s->failed_pc=0x0c0c41ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c41d0;
P_0c0c41d0: /* original dc0e, guest PC 0x0c0c41d0 */
if(!s->budget--) { s->failed_pc=0x0c0c41d0u; return 0; }
r[12]=read(ram,0x0c0c420cu,4);
goto P_0c0c41d2;
P_0c0c41d2: /* original 8801, guest PC 0x0c0c41d2 */
if(!s->budget--) { s->failed_pc=0x0c0c41d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c41d4;
P_0c0c41d4: /* original 8d37, guest PC 0x0c0c41d4 */
if(!s->budget--) { s->failed_pc=0x0c0c41d4u; return 0; }
cond=r[17]&1u;
r[11]=r[4];
if(cond) { goto P_0c0c4246; }
goto P_0c0c41d8;
P_0c0c41d6: /* original 6b43, guest PC 0x0c0c41d6 */
if(!s->budget--) { s->failed_pc=0x0c0c41d6u; return 0; }
r[11]=r[4];
goto P_0c0c41d8;
P_0c0c41d8: /* original 900b, guest PC 0x0c0c41d8 */
if(!s->budget--) { s->failed_pc=0x0c0c41d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c41f2u,2);
goto P_0c0c41da;
P_0c0c41da: /* original 0dec, guest PC 0x0c0c41da */
if(!s->budget--) { s->failed_pc=0x0c0c41dau; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c41dc;
P_0c0c41dc: /* original 3db3, guest PC 0x0c0c41dc */
if(!s->budget--) { s->failed_pc=0x0c0c41dcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[11])!=0);
goto P_0c0c41de;
P_0c0c41de: /* original 8917, guest PC 0x0c0c41de */
if(!s->budget--) { s->failed_pc=0x0c0c41deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4210; }
goto P_0c0c41e0;
P_0c0c41e0: /* original a036, guest PC 0x0c0c41e0 */
if(!s->budget--) { s->failed_pc=0x0c0c41e0u; return 0; }
r[0]=0xffffffffu;
goto P_0c0c4250;
P_0c0c41e2: /* original e0ff, guest PC 0x0c0c41e2 */
if(!s->budget--) { s->failed_pc=0x0c0c41e2u; return 0; }
r[0]=0xffffffffu;
if(!vf3_matrix_family(0x0c0c41e4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c41e4u; return 0; } return 1;
P_0c0c4210: /* original 3db8, guest PC 0x0c0c4210 */
if(!s->budget--) { s->failed_pc=0x0c0c4210u; return 0; }
r[13]-=r[11];
goto P_0c0c4212;
P_0c0c4212: /* original 64c3, guest PC 0x0c0c4212 */
if(!s->budget--) { s->failed_pc=0x0c0c4212u; return 0; }
r[4]=r[12];
goto P_0c0c4214;
P_0c0c4214: /* original 65d3, guest PC 0x0c0c4214 */
if(!s->budget--) { s->failed_pc=0x0c0c4214u; return 0; }
r[5]=r[13];
goto P_0c0c4216;
P_0c0c4216: /* original 0ed4, guest PC 0x0c0c4216 */
if(!s->budget--) { s->failed_pc=0x0c0c4216u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c0c4218;
P_0c0c4218: /* original da47, guest PC 0x0c0c4218 */
if(!s->budget--) { s->failed_pc=0x0c0c4218u; return 0; }
r[10]=read(ram,0x0c0c4338u,4);
goto P_0c0c421a;
P_0c0c421a: /* original 4a0b, guest PC 0x0c0c421a */
if(!s->budget--) { s->failed_pc=0x0c0c421au; return 0; }
target=r[10];
r[16]=code_base|0x0c0c421eu;
r[4]+=0x00000026u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c421eu) { target=s->pc; goto dispatch; }
goto P_0c0c421e;
P_0c0c421c: /* original 7426, guest PC 0x0c0c421c */
if(!s->budget--) { s->failed_pc=0x0c0c421cu; return 0; }
r[4]+=0x00000026u;
goto P_0c0c421e;
P_0c0c421e: /* original 9082, guest PC 0x0c0c421e */
if(!s->budget--) { s->failed_pc=0x0c0c421eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4326u,2);
goto P_0c0c4220;
P_0c0c4220: /* original e300, guest PC 0x0c0c4220 */
if(!s->budget--) { s->failed_pc=0x0c0c4220u; return 0; }
r[3]=0x00000000u;
goto P_0c0c4222;
P_0c0c4222: /* original 64c3, guest PC 0x0c0c4222 */
if(!s->budget--) { s->failed_pc=0x0c0c4222u; return 0; }
r[4]=r[12];
goto P_0c0c4224;
P_0c0c4224: /* original 6533, guest PC 0x0c0c4224 */
if(!s->budget--) { s->failed_pc=0x0c0c4224u; return 0; }
r[5]=r[3];
goto P_0c0c4226;
P_0c0c4226: /* original 0e34, guest PC 0x0c0c4226 */
if(!s->budget--) { s->failed_pc=0x0c0c4226u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c4228;
P_0c0c4228: /* original 4a0b, guest PC 0x0c0c4228 */
if(!s->budget--) { s->failed_pc=0x0c0c4228u; return 0; }
target=r[10];
r[16]=code_base|0x0c0c422cu;
r[4]+=0x00000028u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c422cu) { target=s->pc; goto dispatch; }
goto P_0c0c422c;
P_0c0c422a: /* original 7428, guest PC 0x0c0c422a */
if(!s->budget--) { s->failed_pc=0x0c0c422au; return 0; }
r[4]+=0x00000028u;
goto P_0c0c422c;
P_0c0c422c: /* original 907c, guest PC 0x0c0c422c */
if(!s->budget--) { s->failed_pc=0x0c0c422cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4328u,2);
goto P_0c0c422e;
P_0c0c422e: /* original 00ec, guest PC 0x0c0c422e */
if(!s->budget--) { s->failed_pc=0x0c0c422eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4230;
P_0c0c4230: /* original 8801, guest PC 0x0c0c4230 */
if(!s->budget--) { s->failed_pc=0x0c0c4230u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c4232;
P_0c0c4232: /* original 890c, guest PC 0x0c0c4232 */
if(!s->budget--) { s->failed_pc=0x0c0c4232u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c424e; }
goto P_0c0c4234;
P_0c0c4234: /* original 9079, guest PC 0x0c0c4234 */
if(!s->budget--) { s->failed_pc=0x0c0c4234u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c432au,2);
goto P_0c0c4236;
P_0c0c4236: /* original e300, guest PC 0x0c0c4236 */
if(!s->budget--) { s->failed_pc=0x0c0c4236u; return 0; }
r[3]=0x00000000u;
goto P_0c0c4238;
P_0c0c4238: /* original 64c3, guest PC 0x0c0c4238 */
if(!s->budget--) { s->failed_pc=0x0c0c4238u; return 0; }
r[4]=r[12];
goto P_0c0c423a;
P_0c0c423a: /* original 6533, guest PC 0x0c0c423a */
if(!s->budget--) { s->failed_pc=0x0c0c423au; return 0; }
r[5]=r[3];
goto P_0c0c423c;
P_0c0c423c: /* original 0e34, guest PC 0x0c0c423c */
if(!s->budget--) { s->failed_pc=0x0c0c423cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c423e;
P_0c0c423e: /* original 4a0b, guest PC 0x0c0c423e */
if(!s->budget--) { s->failed_pc=0x0c0c423eu; return 0; }
target=r[10];
r[16]=code_base|0x0c0c4242u;
r[4]+=0x0000002bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4242u) { target=s->pc; goto dispatch; }
goto P_0c0c4242;
P_0c0c4240: /* original 742b, guest PC 0x0c0c4240 */
if(!s->budget--) { s->failed_pc=0x0c0c4240u; return 0; }
r[4]+=0x0000002bu;
goto P_0c0c4242;
P_0c0c4242: /* original a004, guest PC 0x0c0c4242 */
if(!s->budget--) { s->failed_pc=0x0c0c4242u; return 0; }
goto P_0c0c424e;
P_0c0c4244: /* original 0009, guest PC 0x0c0c4244 */
if(!s->budget--) { s->failed_pc=0x0c0c4244u; return 0; }
goto P_0c0c4246;
P_0c0c4246: /* original 9071, guest PC 0x0c0c4246 */
if(!s->budget--) { s->failed_pc=0x0c0c4246u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c432cu,2);
goto P_0c0c4248;
P_0c0c4248: /* original 02ec, guest PC 0x0c0c4248 */
if(!s->budget--) { s->failed_pc=0x0c0c4248u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c424a;
P_0c0c424a: /* original 7201, guest PC 0x0c0c424a */
if(!s->budget--) { s->failed_pc=0x0c0c424au; return 0; }
r[2]+=0x00000001u;
goto P_0c0c424c;
P_0c0c424c: /* original 0e24, guest PC 0x0c0c424c */
if(!s->budget--) { s->failed_pc=0x0c0c424cu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0c424e;
P_0c0c424e: /* original 60b3, guest PC 0x0c0c424e */
if(!s->budget--) { s->failed_pc=0x0c0c424eu; return 0; }
r[0]=r[11];
goto P_0c0c4250;
P_0c0c4250: /* original 4f26, guest PC 0x0c0c4250 */
if(!s->budget--) { s->failed_pc=0x0c0c4250u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c4252;
P_0c0c4252: /* original 6af6, guest PC 0x0c0c4252 */
if(!s->budget--) { s->failed_pc=0x0c0c4252u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c4254;
P_0c0c4254: /* original 6bf6, guest PC 0x0c0c4254 */
if(!s->budget--) { s->failed_pc=0x0c0c4254u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c4256;
P_0c0c4256: /* original 6cf6, guest PC 0x0c0c4256 */
if(!s->budget--) { s->failed_pc=0x0c0c4256u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c4258;
P_0c0c4258: /* original 6df6, guest PC 0x0c0c4258 */
if(!s->budget--) { s->failed_pc=0x0c0c4258u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c425a;
P_0c0c425a: /* original 000b, guest PC 0x0c0c425a */
if(!s->budget--) { s->failed_pc=0x0c0c425au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c425c: /* original 6ef6, guest PC 0x0c0c425c */
if(!s->budget--) { s->failed_pc=0x0c0c425cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c425e;
P_0c0c425e: /* original 2fe6, guest PC 0x0c0c425e */
if(!s->budget--) { s->failed_pc=0x0c0c425eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4260;
P_0c0c4260: /* original 2fd6, guest PC 0x0c0c4260 */
if(!s->budget--) { s->failed_pc=0x0c0c4260u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4262;
P_0c0c4262: /* original 2fc6, guest PC 0x0c0c4262 */
if(!s->budget--) { s->failed_pc=0x0c0c4262u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4264;
P_0c0c4264: /* original 2fb6, guest PC 0x0c0c4264 */
if(!s->budget--) { s->failed_pc=0x0c0c4264u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4266;
P_0c0c4266: /* original 2fa6, guest PC 0x0c0c4266 */
if(!s->budget--) { s->failed_pc=0x0c0c4266u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4268;
P_0c0c4268: /* original de34, guest PC 0x0c0c4268 */
if(!s->budget--) { s->failed_pc=0x0c0c4268u; return 0; }
r[14]=read(ram,0x0c0c433cu,4);
goto P_0c0c426a;
P_0c0c426a: /* original 9060, guest PC 0x0c0c426a */
if(!s->budget--) { s->failed_pc=0x0c0c426au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c432eu,2);
goto P_0c0c426c;
P_0c0c426c: /* original 4f22, guest PC 0x0c0c426c */
if(!s->budget--) { s->failed_pc=0x0c0c426cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c426e;
P_0c0c426e: /* original 00ec, guest PC 0x0c0c426e */
if(!s->budget--) { s->failed_pc=0x0c0c426eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4270;
P_0c0c4270: /* original db33, guest PC 0x0c0c4270 */
if(!s->budget--) { s->failed_pc=0x0c0c4270u; return 0; }
r[11]=read(ram,0x0c0c4340u,4);
goto P_0c0c4272;
P_0c0c4272: /* original 8801, guest PC 0x0c0c4272 */
if(!s->budget--) { s->failed_pc=0x0c0c4272u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c4274;
P_0c0c4274: /* original 8d2e, guest PC 0x0c0c4274 */
if(!s->budget--) { s->failed_pc=0x0c0c4274u; return 0; }
cond=r[17]&1u;
r[13]=r[4];
if(cond) { goto P_0c0c42d4; }
goto P_0c0c4278;
P_0c0c4276: /* original 6d43, guest PC 0x0c0c4276 */
if(!s->budget--) { s->failed_pc=0x0c0c4276u; return 0; }
r[13]=r[4];
goto P_0c0c4278;
P_0c0c4278: /* original 9056, guest PC 0x0c0c4278 */
if(!s->budget--) { s->failed_pc=0x0c0c4278u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4328u,2);
goto P_0c0c427a;
P_0c0c427a: /* original da2f, guest PC 0x0c0c427a */
if(!s->budget--) { s->failed_pc=0x0c0c427au; return 0; }
r[10]=read(ram,0x0c0c4338u,4);
goto P_0c0c427c;
P_0c0c427c: /* original 00ec, guest PC 0x0c0c427c */
if(!s->budget--) { s->failed_pc=0x0c0c427cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c427e;
P_0c0c427e: /* original 8801, guest PC 0x0c0c427e */
if(!s->budget--) { s->failed_pc=0x0c0c427eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c4280;
P_0c0c4280: /* original 8911, guest PC 0x0c0c4280 */
if(!s->budget--) { s->failed_pc=0x0c0c4280u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c42a6; }
goto P_0c0c4282;
P_0c0c4282: /* original 9055, guest PC 0x0c0c4282 */
if(!s->budget--) { s->failed_pc=0x0c0c4282u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4330u,2);
goto P_0c0c4284;
P_0c0c4284: /* original 0cec, guest PC 0x0c0c4284 */
if(!s->budget--) { s->failed_pc=0x0c0c4284u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4286;
P_0c0c4286: /* original 3cd3, guest PC 0x0c0c4286 */
if(!s->budget--) { s->failed_pc=0x0c0c4286u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[13])!=0);
goto P_0c0c4288;
P_0c0c4288: /* original 8b11, guest PC 0x0c0c4288 */
if(!s->budget--) { s->failed_pc=0x0c0c4288u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c42ae; }
goto P_0c0c428a;
P_0c0c428a: /* original 3cd8, guest PC 0x0c0c428a */
if(!s->budget--) { s->failed_pc=0x0c0c428au; return 0; }
r[12]-=r[13];
goto P_0c0c428c;
P_0c0c428c: /* original 64b3, guest PC 0x0c0c428c */
if(!s->budget--) { s->failed_pc=0x0c0c428cu; return 0; }
r[4]=r[11];
goto P_0c0c428e;
P_0c0c428e: /* original 65c3, guest PC 0x0c0c428e */
if(!s->budget--) { s->failed_pc=0x0c0c428eu; return 0; }
r[5]=r[12];
goto P_0c0c4290;
P_0c0c4290: /* original 0ec4, guest PC 0x0c0c4290 */
if(!s->budget--) { s->failed_pc=0x0c0c4290u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0c4292;
P_0c0c4292: /* original 4a0b, guest PC 0x0c0c4292 */
if(!s->budget--) { s->failed_pc=0x0c0c4292u; return 0; }
target=r[10];
r[16]=code_base|0x0c0c4296u;
r[4]+=0x00000026u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4296u) { target=s->pc; goto dispatch; }
goto P_0c0c4296;
P_0c0c4294: /* original 7426, guest PC 0x0c0c4294 */
if(!s->budget--) { s->failed_pc=0x0c0c4294u; return 0; }
r[4]+=0x00000026u;
goto P_0c0c4296;
P_0c0c4296: /* original 9046, guest PC 0x0c0c4296 */
if(!s->budget--) { s->failed_pc=0x0c0c4296u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4326u,2);
goto P_0c0c4298;
P_0c0c4298: /* original e300, guest PC 0x0c0c4298 */
if(!s->budget--) { s->failed_pc=0x0c0c4298u; return 0; }
r[3]=0x00000000u;
goto P_0c0c429a;
P_0c0c429a: /* original 6533, guest PC 0x0c0c429a */
if(!s->budget--) { s->failed_pc=0x0c0c429au; return 0; }
r[5]=r[3];
goto P_0c0c429c;
P_0c0c429c: /* original 64b3, guest PC 0x0c0c429c */
if(!s->budget--) { s->failed_pc=0x0c0c429cu; return 0; }
r[4]=r[11];
goto P_0c0c429e;
P_0c0c429e: /* original 6cd3, guest PC 0x0c0c429e */
if(!s->budget--) { s->failed_pc=0x0c0c429eu; return 0; }
r[12]=r[13];
goto P_0c0c42a0;
P_0c0c42a0: /* original 0e34, guest PC 0x0c0c42a0 */
if(!s->budget--) { s->failed_pc=0x0c0c42a0u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c42a2;
P_0c0c42a2: /* original a013, guest PC 0x0c0c42a2 */
if(!s->budget--) { s->failed_pc=0x0c0c42a2u; return 0; }
r[4]+=0x00000028u;
goto P_0c0c42cc;
P_0c0c42a4: /* original 7428, guest PC 0x0c0c42a4 */
if(!s->budget--) { s->failed_pc=0x0c0c42a4u; return 0; }
r[4]+=0x00000028u;
goto P_0c0c42a6;
P_0c0c42a6: /* original 9044, guest PC 0x0c0c42a6 */
if(!s->budget--) { s->failed_pc=0x0c0c42a6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4332u,2);
goto P_0c0c42a8;
P_0c0c42a8: /* original 0cec, guest PC 0x0c0c42a8 */
if(!s->budget--) { s->failed_pc=0x0c0c42a8u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c42aa;
P_0c0c42aa: /* original 3cd3, guest PC 0x0c0c42aa */
if(!s->budget--) { s->failed_pc=0x0c0c42aau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[13])!=0);
goto P_0c0c42ac;
P_0c0c42ac: /* original 8901, guest PC 0x0c0c42ac */
if(!s->budget--) { s->failed_pc=0x0c0c42acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c42b2; }
goto P_0c0c42ae;
P_0c0c42ae: /* original a016, guest PC 0x0c0c42ae */
if(!s->budget--) { s->failed_pc=0x0c0c42aeu; return 0; }
r[0]=0xffffffffu;
goto P_0c0c42de;
P_0c0c42b0: /* original e0ff, guest PC 0x0c0c42b0 */
if(!s->budget--) { s->failed_pc=0x0c0c42b0u; return 0; }
r[0]=0xffffffffu;
goto P_0c0c42b2;
P_0c0c42b2: /* original 3cd8, guest PC 0x0c0c42b2 */
if(!s->budget--) { s->failed_pc=0x0c0c42b2u; return 0; }
r[12]-=r[13];
goto P_0c0c42b4;
P_0c0c42b4: /* original 64b3, guest PC 0x0c0c42b4 */
if(!s->budget--) { s->failed_pc=0x0c0c42b4u; return 0; }
r[4]=r[11];
goto P_0c0c42b6;
P_0c0c42b6: /* original 65c3, guest PC 0x0c0c42b6 */
if(!s->budget--) { s->failed_pc=0x0c0c42b6u; return 0; }
r[5]=r[12];
goto P_0c0c42b8;
P_0c0c42b8: /* original 0ec4, guest PC 0x0c0c42b8 */
if(!s->budget--) { s->failed_pc=0x0c0c42b8u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c0c42ba;
P_0c0c42ba: /* original 4a0b, guest PC 0x0c0c42ba */
if(!s->budget--) { s->failed_pc=0x0c0c42bau; return 0; }
target=r[10];
r[16]=code_base|0x0c0c42beu;
r[4]+=0x00000029u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c42beu) { target=s->pc; goto dispatch; }
goto P_0c0c42be;
P_0c0c42bc: /* original 7429, guest PC 0x0c0c42bc */
if(!s->budget--) { s->failed_pc=0x0c0c42bcu; return 0; }
r[4]+=0x00000029u;
goto P_0c0c42be;
P_0c0c42be: /* original 9034, guest PC 0x0c0c42be */
if(!s->budget--) { s->failed_pc=0x0c0c42beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c432au,2);
goto P_0c0c42c0;
P_0c0c42c0: /* original 64b3, guest PC 0x0c0c42c0 */
if(!s->budget--) { s->failed_pc=0x0c0c42c0u; return 0; }
r[4]=r[11];
goto P_0c0c42c2;
P_0c0c42c2: /* original e300, guest PC 0x0c0c42c2 */
if(!s->budget--) { s->failed_pc=0x0c0c42c2u; return 0; }
r[3]=0x00000000u;
goto P_0c0c42c4;
P_0c0c42c4: /* original 6cd3, guest PC 0x0c0c42c4 */
if(!s->budget--) { s->failed_pc=0x0c0c42c4u; return 0; }
r[12]=r[13];
goto P_0c0c42c6;
P_0c0c42c6: /* original 742b, guest PC 0x0c0c42c6 */
if(!s->budget--) { s->failed_pc=0x0c0c42c6u; return 0; }
r[4]+=0x0000002bu;
goto P_0c0c42c8;
P_0c0c42c8: /* original 6533, guest PC 0x0c0c42c8 */
if(!s->budget--) { s->failed_pc=0x0c0c42c8u; return 0; }
r[5]=r[3];
goto P_0c0c42ca;
P_0c0c42ca: /* original 0e34, guest PC 0x0c0c42ca */
if(!s->budget--) { s->failed_pc=0x0c0c42cau; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c42cc;
P_0c0c42cc: /* original 4a0b, guest PC 0x0c0c42cc */
if(!s->budget--) { s->failed_pc=0x0c0c42ccu; return 0; }
target=r[10];
r[16]=code_base|0x0c0c42d0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c42d0u) { target=s->pc; goto dispatch; }
goto P_0c0c42d0;
P_0c0c42ce: /* original 0009, guest PC 0x0c0c42ce */
if(!s->budget--) { s->failed_pc=0x0c0c42ceu; return 0; }
goto P_0c0c42d0;
P_0c0c42d0: /* original a004, guest PC 0x0c0c42d0 */
if(!s->budget--) { s->failed_pc=0x0c0c42d0u; return 0; }
r[13]=r[12];
goto P_0c0c42dc;
P_0c0c42d2: /* original 6dc3, guest PC 0x0c0c42d2 */
if(!s->budget--) { s->failed_pc=0x0c0c42d2u; return 0; }
r[13]=r[12];
goto P_0c0c42d4;
P_0c0c42d4: /* original 902a, guest PC 0x0c0c42d4 */
if(!s->budget--) { s->failed_pc=0x0c0c42d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c432cu,2);
goto P_0c0c42d6;
P_0c0c42d6: /* original 02ec, guest PC 0x0c0c42d6 */
if(!s->budget--) { s->failed_pc=0x0c0c42d6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c42d8;
P_0c0c42d8: /* original 7201, guest PC 0x0c0c42d8 */
if(!s->budget--) { s->failed_pc=0x0c0c42d8u; return 0; }
r[2]+=0x00000001u;
goto P_0c0c42da;
P_0c0c42da: /* original 0e24, guest PC 0x0c0c42da */
if(!s->budget--) { s->failed_pc=0x0c0c42dau; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0c42dc;
P_0c0c42dc: /* original 60d3, guest PC 0x0c0c42dc */
if(!s->budget--) { s->failed_pc=0x0c0c42dcu; return 0; }
r[0]=r[13];
goto P_0c0c42de;
P_0c0c42de: /* original 4f26, guest PC 0x0c0c42de */
if(!s->budget--) { s->failed_pc=0x0c0c42deu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c42e0;
P_0c0c42e0: /* original 6af6, guest PC 0x0c0c42e0 */
if(!s->budget--) { s->failed_pc=0x0c0c42e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c42e2;
P_0c0c42e2: /* original 6bf6, guest PC 0x0c0c42e2 */
if(!s->budget--) { s->failed_pc=0x0c0c42e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c42e4;
P_0c0c42e4: /* original 6cf6, guest PC 0x0c0c42e4 */
if(!s->budget--) { s->failed_pc=0x0c0c42e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c42e6;
P_0c0c42e6: /* original 6df6, guest PC 0x0c0c42e6 */
if(!s->budget--) { s->failed_pc=0x0c0c42e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c42e8;
P_0c0c42e8: /* original 000b, guest PC 0x0c0c42e8 */
if(!s->budget--) { s->failed_pc=0x0c0c42e8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c42ea: /* original 6ef6, guest PC 0x0c0c42ea */
if(!s->budget--) { s->failed_pc=0x0c0c42eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c42ecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c42ecu; return 0; } return 1;
P_0c0c437c: /* original 2fe6, guest PC 0x0c0c437c */
if(!s->budget--) { s->failed_pc=0x0c0c437cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c437e;
P_0c0c437e: /* original 2fd6, guest PC 0x0c0c437e */
if(!s->budget--) { s->failed_pc=0x0c0c437eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4380;
P_0c0c4380: /* original 2fc6, guest PC 0x0c0c4380 */
if(!s->budget--) { s->failed_pc=0x0c0c4380u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4382;
P_0c0c4382: /* original 2fb6, guest PC 0x0c0c4382 */
if(!s->budget--) { s->failed_pc=0x0c0c4382u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4384;
P_0c0c4384: /* original 2fa6, guest PC 0x0c0c4384 */
if(!s->budget--) { s->failed_pc=0x0c0c4384u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4386;
P_0c0c4386: /* original 2f96, guest PC 0x0c0c4386 */
if(!s->budget--) { s->failed_pc=0x0c0c4386u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4388;
P_0c0c4388: /* original 2f86, guest PC 0x0c0c4388 */
if(!s->budget--) { s->failed_pc=0x0c0c4388u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c438a;
P_0c0c438a: /* original fffb, guest PC 0x0c0c438a */
if(!s->budget--) { s->failed_pc=0x0c0c438au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c438c;
P_0c0c438c: /* original ffeb, guest PC 0x0c0c438c */
if(!s->budget--) { s->failed_pc=0x0c0c438cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0c438e;
P_0c0c438e: /* original 4f22, guest PC 0x0c0c438e */
if(!s->budget--) { s->failed_pc=0x0c0c438eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c4390;
P_0c0c4390: /* original 9057, guest PC 0x0c0c4390 */
if(!s->budget--) { s->failed_pc=0x0c0c4390u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4442u,2);
goto P_0c0c4392;
P_0c0c4392: /* original d32e, guest PC 0x0c0c4392 */
if(!s->budget--) { s->failed_pc=0x0c0c4392u; return 0; }
r[3]=read(ram,0x0c0c444cu,4);
goto P_0c0c4394;
P_0c0c4394: /* original 3f0c, guest PC 0x0c0c4394 */
if(!s->budget--) { s->failed_pc=0x0c0c4394u; return 0; }
r[15]+=r[0];
goto P_0c0c4396;
P_0c0c4396: /* original dd2f, guest PC 0x0c0c4396 */
if(!s->budget--) { s->failed_pc=0x0c0c4396u; return 0; }
r[13]=read(ram,0x0c0c4454u,4);
goto P_0c0c4398;
P_0c0c4398: /* original 1f31, guest PC 0x0c0c4398 */
if(!s->budget--) { s->failed_pc=0x0c0c4398u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c439a;
P_0c0c439a: /* original 9653, guest PC 0x0c0c439a */
if(!s->budget--) { s->failed_pc=0x0c0c439au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4444u,2);
goto P_0c0c439c;
P_0c0c439c: /* original d32e, guest PC 0x0c0c439c */
if(!s->budget--) { s->failed_pc=0x0c0c439cu; return 0; }
r[3]=read(ram,0x0c0c4458u,4);
goto P_0c0c439e;
P_0c0c439e: /* original ff8d, guest PC 0x0c0c439e */
if(!s->budget--) { s->failed_pc=0x0c0c439eu; return 0; }
fr[15]=0;
goto P_0c0c43a0;
P_0c0c43a0: /* original 6563, guest PC 0x0c0c43a0 */
if(!s->budget--) { s->failed_pc=0x0c0c43a0u; return 0; }
r[5]=r[6];
goto P_0c0c43a2;
P_0c0c43a2: /* original f5fc, guest PC 0x0c0c43a2 */
if(!s->budget--) { s->failed_pc=0x0c0c43a2u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c43a4;
P_0c0c43a4: /* original f4fc, guest PC 0x0c0c43a4 */
if(!s->budget--) { s->failed_pc=0x0c0c43a4u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0c43a6;
P_0c0c43a6: /* original 430b, guest PC 0x0c0c43a6 */
if(!s->budget--) { s->failed_pc=0x0c0c43a6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c43aau;
r[4]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c43aau) { target=s->pc; goto dispatch; }
goto P_0c0c43aa;
P_0c0c43a8: /* original 6463, guest PC 0x0c0c43a8 */
if(!s->budget--) { s->failed_pc=0x0c0c43a8u; return 0; }
r[4]=r[6];
goto P_0c0c43aa;
P_0c0c43aa: /* original d32d, guest PC 0x0c0c43aa */
if(!s->budget--) { s->failed_pc=0x0c0c43aau; return 0; }
r[3]=read(ram,0x0c0c4460u,4);
goto P_0c0c43ac;
P_0c0c43ac: /* original c72b, guest PC 0x0c0c43ac */
if(!s->budget--) { s->failed_pc=0x0c0c43acu; return 0; }
r[0]=code_base|0x000c445cu;
goto P_0c0c43ae;
P_0c0c43ae: /* original e400, guest PC 0x0c0c43ae */
if(!s->budget--) { s->failed_pc=0x0c0c43aeu; return 0; }
r[4]=0x00000000u;
goto P_0c0c43b0;
P_0c0c43b0: /* original f59d, guest PC 0x0c0c43b0 */
if(!s->budget--) { s->failed_pc=0x0c0c43b0u; return 0; }
fr[5]=0x3f800000u;
goto P_0c0c43b2;
P_0c0c43b2: /* original 430b, guest PC 0x0c0c43b2 */
if(!s->budget--) { s->failed_pc=0x0c0c43b2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c43b6u;
vf3_matrix_load(s,ram,4,r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c43b6u) { target=s->pc; goto dispatch; }
goto P_0c0c43b6;
P_0c0c43b4: /* original f408, guest PC 0x0c0c43b4 */
if(!s->budget--) { s->failed_pc=0x0c0c43b4u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c43b6;
P_0c0c43b6: /* original d22b, guest PC 0x0c0c43b6 */
if(!s->budget--) { s->failed_pc=0x0c0c43b6u; return 0; }
r[2]=read(ram,0x0c0c4464u,4);
goto P_0c0c43b8;
P_0c0c43b8: /* original 420b, guest PC 0x0c0c43b8 */
if(!s->budget--) { s->failed_pc=0x0c0c43b8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c43bcu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c43bcu) { target=s->pc; goto dispatch; }
goto P_0c0c43bc;
P_0c0c43ba: /* original e400, guest PC 0x0c0c43ba */
if(!s->budget--) { s->failed_pc=0x0c0c43bau; return 0; }
r[4]=0x00000000u;
goto P_0c0c43bc;
P_0c0c43bc: /* original d32a, guest PC 0x0c0c43bc */
if(!s->budget--) { s->failed_pc=0x0c0c43bcu; return 0; }
r[3]=read(ram,0x0c0c4468u,4);
goto P_0c0c43be;
P_0c0c43be: /* original 64f3, guest PC 0x0c0c43be */
if(!s->budget--) { s->failed_pc=0x0c0c43beu; return 0; }
r[4]=r[15];
goto P_0c0c43c0;
P_0c0c43c0: /* original 430b, guest PC 0x0c0c43c0 */
if(!s->budget--) { s->failed_pc=0x0c0c43c0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c43c4u;
r[4]+=0x0000007cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c43c4u) { target=s->pc; goto dispatch; }
goto P_0c0c43c4;
P_0c0c43c2: /* original 747c, guest PC 0x0c0c43c2 */
if(!s->budget--) { s->failed_pc=0x0c0c43c2u; return 0; }
r[4]+=0x0000007cu;
goto P_0c0c43c4;
P_0c0c43c4: /* original d229, guest PC 0x0c0c43c4 */
if(!s->budget--) { s->failed_pc=0x0c0c43c4u; return 0; }
r[2]=read(ram,0x0c0c446cu,4);
goto P_0c0c43c6;
P_0c0c43c6: /* original 420b, guest PC 0x0c0c43c6 */
if(!s->budget--) { s->failed_pc=0x0c0c43c6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c43cau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c43cau) { target=s->pc; goto dispatch; }
goto P_0c0c43ca;
P_0c0c43c8: /* original 0009, guest PC 0x0c0c43c8 */
if(!s->budget--) { s->failed_pc=0x0c0c43c8u; return 0; }
goto P_0c0c43ca;
P_0c0c43ca: /* original d329, guest PC 0x0c0c43ca */
if(!s->budget--) { s->failed_pc=0x0c0c43cau; return 0; }
r[3]=read(ram,0x0c0c4470u,4);
goto P_0c0c43cc;
P_0c0c43cc: /* original 430b, guest PC 0x0c0c43cc */
if(!s->budget--) { s->failed_pc=0x0c0c43ccu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c43d0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c43d0u) { target=s->pc; goto dispatch; }
goto P_0c0c43d0;
P_0c0c43ce: /* original 0009, guest PC 0x0c0c43ce */
if(!s->budget--) { s->failed_pc=0x0c0c43ceu; return 0; }
goto P_0c0c43d0;
P_0c0c43d0: /* original de1f, guest PC 0x0c0c43d0 */
if(!s->budget--) { s->failed_pc=0x0c0c43d0u; return 0; }
r[14]=read(ram,0x0c0c4450u,4);
goto P_0c0c43d2;
P_0c0c43d2: /* original e500, guest PC 0x0c0c43d2 */
if(!s->budget--) { s->failed_pc=0x0c0c43d2u; return 0; }
r[5]=0x00000000u;
goto P_0c0c43d4;
P_0c0c43d4: /* original 5aeb, guest PC 0x0c0c43d4 */
if(!s->budget--) { s->failed_pc=0x0c0c43d4u; return 0; }
r[10]=read(ram,r[14]+44,4);
goto P_0c0c43d6;
P_0c0c43d6: /* original 5cea, guest PC 0x0c0c43d6 */
if(!s->budget--) { s->failed_pc=0x0c0c43d6u; return 0; }
r[12]=read(ram,r[14]+40,4);
goto P_0c0c43d8;
P_0c0c43d8: /* original 62a2, guest PC 0x0c0c43d8 */
if(!s->budget--) { s->failed_pc=0x0c0c43d8u; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c0c43da;
P_0c0c43da: /* original 6bc2, guest PC 0x0c0c43da */
if(!s->budget--) { s->failed_pc=0x0c0c43dau; return 0; }
tmp=read(ram,r[12],4);
r[11]=tmp;
goto P_0c0c43dc;
P_0c0c43dc: /* original 1f27, guest PC 0x0c0c43dc */
if(!s->budget--) { s->failed_pc=0x0c0c43dcu; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c0c43de;
P_0c0c43de: /* original d325, guest PC 0x0c0c43de */
if(!s->budget--) { s->failed_pc=0x0c0c43deu; return 0; }
r[3]=read(ram,0x0c0c4474u,4);
goto P_0c0c43e0;
P_0c0c43e0: /* original 430b, guest PC 0x0c0c43e0 */
if(!s->budget--) { s->failed_pc=0x0c0c43e0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c43e4u;
r[4]=0x0000000fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c43e4u) { target=s->pc; goto dispatch; }
goto P_0c0c43e4;
P_0c0c43e2: /* original e40f, guest PC 0x0c0c43e2 */
if(!s->budget--) { s->failed_pc=0x0c0c43e2u; return 0; }
r[4]=0x0000000fu;
goto P_0c0c43e4;
P_0c0c43e4: /* original e20f, guest PC 0x0c0c43e4 */
if(!s->budget--) { s->failed_pc=0x0c0c43e4u; return 0; }
r[2]=0x0000000fu;
goto P_0c0c43e6;
P_0c0c43e6: /* original e500, guest PC 0x0c0c43e6 */
if(!s->budget--) { s->failed_pc=0x0c0c43e6u; return 0; }
r[5]=0x00000000u;
goto P_0c0c43e8;
P_0c0c43e8: /* original 2f26, guest PC 0x0c0c43e8 */
if(!s->budget--) { s->failed_pc=0x0c0c43e8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c43ea;
P_0c0c43ea: /* original d323, guest PC 0x0c0c43ea */
if(!s->budget--) { s->failed_pc=0x0c0c43eau; return 0; }
r[3]=read(ram,0x0c0c4478u,4);
goto P_0c0c43ec;
P_0c0c43ec: /* original e609, guest PC 0x0c0c43ec */
if(!s->budget--) { s->failed_pc=0x0c0c43ecu; return 0; }
r[6]=0x00000009u;
goto P_0c0c43ee;
P_0c0c43ee: /* original 6723, guest PC 0x0c0c43ee */
if(!s->budget--) { s->failed_pc=0x0c0c43eeu; return 0; }
r[7]=r[2];
goto P_0c0c43f0;
P_0c0c43f0: /* original 430b, guest PC 0x0c0c43f0 */
if(!s->budget--) { s->failed_pc=0x0c0c43f0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c43f4u;
r[4]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c43f4u) { target=s->pc; goto dispatch; }
goto P_0c0c43f4;
P_0c0c43f2: /* original 6453, guest PC 0x0c0c43f2 */
if(!s->budget--) { s->failed_pc=0x0c0c43f2u; return 0; }
r[4]=r[5];
goto P_0c0c43f4;
P_0c0c43f4: /* original c721, guest PC 0x0c0c43f4 */
if(!s->budget--) { s->failed_pc=0x0c0c43f4u; return 0; }
r[0]=code_base|0x000c447cu;
goto P_0c0c43f6;
P_0c0c43f6: /* original e30e, guest PC 0x0c0c43f6 */
if(!s->budget--) { s->failed_pc=0x0c0c43f6u; return 0; }
r[3]=0x0000000eu;
goto P_0c0c43f8;
P_0c0c43f8: /* original fe08, guest PC 0x0c0c43f8 */
if(!s->budget--) { s->failed_pc=0x0c0c43f8u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c0c43fa;
P_0c0c43fa: /* original 23b8, guest PC 0x0c0c43fa */
if(!s->budget--) { s->failed_pc=0x0c0c43fau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c0c43fc;
P_0c0c43fc: /* original 7f04, guest PC 0x0c0c43fc */
if(!s->budget--) { s->failed_pc=0x0c0c43fcu; return 0; }
r[15]+=0x00000004u;
goto P_0c0c43fe;
P_0c0c43fe: /* original e808, guest PC 0x0c0c43fe */
if(!s->budget--) { s->failed_pc=0x0c0c43feu; return 0; }
r[8]=0x00000008u;
goto P_0c0c4400;
P_0c0c4400: /* original 8f02, guest PC 0x0c0c4400 */
if(!s->budget--) { s->failed_pc=0x0c0c4400u; return 0; }
cond=r[17]&1u;
r[9]=0x00000009u;
if(!cond) { goto P_0c0c4408; }
goto P_0c0c4404;
P_0c0c4402: /* original e909, guest PC 0x0c0c4402 */
if(!s->budget--) { s->failed_pc=0x0c0c4402u; return 0; }
r[9]=0x00000009u;
goto P_0c0c4404;
P_0c0c4404: /* original a1c0, guest PC 0x0c0c4404 */
if(!s->budget--) { s->failed_pc=0x0c0c4404u; return 0; }
goto P_0c0c4788;
P_0c0c4406: /* original 0009, guest PC 0x0c0c4406 */
if(!s->budget--) { s->failed_pc=0x0c0c4406u; return 0; }
goto P_0c0c4408;
P_0c0c4408: /* original d218, guest PC 0x0c0c4408 */
if(!s->budget--) { s->failed_pc=0x0c0c4408u; return 0; }
r[2]=read(ram,0x0c0c446cu,4);
goto P_0c0c440a;
P_0c0c440a: /* original 420b, guest PC 0x0c0c440a */
if(!s->budget--) { s->failed_pc=0x0c0c440au; return 0; }
target=r[2];
r[16]=code_base|0x0c0c440eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c440eu) { target=s->pc; goto dispatch; }
goto P_0c0c440e;
P_0c0c440c: /* original 0009, guest PC 0x0c0c440c */
if(!s->budget--) { s->failed_pc=0x0c0c440cu; return 0; }
goto P_0c0c440e;
P_0c0c440e: /* original d118, guest PC 0x0c0c440e */
if(!s->budget--) { s->failed_pc=0x0c0c440eu; return 0; }
r[1]=read(ram,0x0c0c4470u,4);
goto P_0c0c4410;
P_0c0c4410: /* original 410b, guest PC 0x0c0c4410 */
if(!s->budget--) { s->failed_pc=0x0c0c4410u; return 0; }
target=r[1];
r[16]=code_base|0x0c0c4414u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4414u) { target=s->pc; goto dispatch; }
goto P_0c0c4414;
P_0c0c4412: /* original 0009, guest PC 0x0c0c4412 */
if(!s->budget--) { s->failed_pc=0x0c0c4412u; return 0; }
goto P_0c0c4414;
P_0c0c4414: /* original d31a, guest PC 0x0c0c4414 */
if(!s->budget--) { s->failed_pc=0x0c0c4414u; return 0; }
r[3]=read(ram,0x0c0c4480u,4);
goto P_0c0c4416;
P_0c0c4416: /* original 9416, guest PC 0x0c0c4416 */
if(!s->budget--) { s->failed_pc=0x0c0c4416u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4446u,2);
goto P_0c0c4418;
P_0c0c4418: /* original 430b, guest PC 0x0c0c4418 */
if(!s->budget--) { s->failed_pc=0x0c0c4418u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c441cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c441cu) { target=s->pc; goto dispatch; }
goto P_0c0c441c;
P_0c0c441a: /* original 0009, guest PC 0x0c0c441a */
if(!s->budget--) { s->failed_pc=0x0c0c441au; return 0; }
goto P_0c0c441c;
P_0c0c441c: /* original e06c, guest PC 0x0c0c441c */
if(!s->budget--) { s->failed_pc=0x0c0c441cu; return 0; }
r[0]=0x0000006cu;
goto P_0c0c441e;
P_0c0c441e: /* original 00ce, guest PC 0x0c0c441e */
if(!s->budget--) { s->failed_pc=0x0c0c441eu; return 0; }
r[0]=read(ram,r[12]+r[0],4);
goto P_0c0c4420;
P_0c0c4420: /* original 8806, guest PC 0x0c0c4420 */
if(!s->budget--) { s->failed_pc=0x0c0c4420u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0c4422;
P_0c0c4422: /* original 8f31, guest PC 0x0c0c4422 */
if(!s->budget--) { s->failed_pc=0x0c0c4422u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[14]+16,4);
if(!cond) { goto P_0c0c4488; }
goto P_0c0c4426;
P_0c0c4424: /* original 54e4, guest PC 0x0c0c4424 */
if(!s->budget--) { s->failed_pc=0x0c0c4424u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c0c4426;
P_0c0c4426: /* original 900f, guest PC 0x0c0c4426 */
if(!s->budget--) { s->failed_pc=0x0c0c4426u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4448u,2);
goto P_0c0c4428;
P_0c0c4428: /* original d316, guest PC 0x0c0c4428 */
if(!s->budget--) { s->failed_pc=0x0c0c4428u; return 0; }
r[3]=read(ram,0x0c0c4484u,4);
goto P_0c0c442a;
P_0c0c442a: /* original 05de, guest PC 0x0c0c442a */
if(!s->budget--) { s->failed_pc=0x0c0c442au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0c442c;
P_0c0c442c: /* original 2538, guest PC 0x0c0c442c */
if(!s->budget--) { s->failed_pc=0x0c0c442cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0c442e;
P_0c0c442e: /* original 8903, guest PC 0x0c0c442e */
if(!s->budget--) { s->failed_pc=0x0c0c442eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4438; }
goto P_0c0c4430;
P_0c0c4430: /* original e060, guest PC 0x0c0c4430 */
if(!s->budget--) { s->failed_pc=0x0c0c4430u; return 0; }
r[0]=0x00000060u;
goto P_0c0c4432;
P_0c0c4432: /* original e116, guest PC 0x0c0c4432 */
if(!s->budget--) { s->failed_pc=0x0c0c4432u; return 0; }
r[1]=0x00000016u;
goto P_0c0c4434;
P_0c0c4434: /* original a002, guest PC 0x0c0c4434 */
if(!s->budget--) { s->failed_pc=0x0c0c4434u; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c0c443c;
P_0c0c4436: /* original 0414, guest PC 0x0c0c4436 */
if(!s->budget--) { s->failed_pc=0x0c0c4436u; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c0c4438;
P_0c0c4438: /* original e060, guest PC 0x0c0c4438 */
if(!s->budget--) { s->failed_pc=0x0c0c4438u; return 0; }
r[0]=0x00000060u;
goto P_0c0c443a;
P_0c0c443a: /* original 0494, guest PC 0x0c0c443a */
if(!s->budget--) { s->failed_pc=0x0c0c443au; return 0; }
write(ram,r[4]+r[0],r[9],1);
goto P_0c0c443c;
P_0c0c443c: /* original e061, guest PC 0x0c0c443c */
if(!s->budget--) { s->failed_pc=0x0c0c443cu; return 0; }
r[0]=0x00000061u;
goto P_0c0c443e;
P_0c0c443e: /* original a027, guest PC 0x0c0c443e */
if(!s->budget--) { s->failed_pc=0x0c0c443eu; return 0; }
write(ram,r[4]+r[0],r[9],1);
goto P_0c0c4490;
P_0c0c4440: /* original 0494, guest PC 0x0c0c4440 */
if(!s->budget--) { s->failed_pc=0x0c0c4440u; return 0; }
write(ram,r[4]+r[0],r[9],1);
if(!vf3_matrix_family(0x0c0c4442u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c4442u; return 0; } return 1;
P_0c0c4488: /* original e032, guest PC 0x0c0c4488 */
if(!s->budget--) { s->failed_pc=0x0c0c4488u; return 0; }
r[0]=0x00000032u;
goto P_0c0c448a;
P_0c0c448a: /* original 02cc, guest PC 0x0c0c448a */
if(!s->budget--) { s->failed_pc=0x0c0c448au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c448c;
P_0c0c448c: /* original e060, guest PC 0x0c0c448c */
if(!s->budget--) { s->failed_pc=0x0c0c448cu; return 0; }
r[0]=0x00000060u;
goto P_0c0c448e;
P_0c0c448e: /* original 0424, guest PC 0x0c0c448e */
if(!s->budget--) { s->failed_pc=0x0c0c448eu; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0c4490;
P_0c0c4490: /* original e058, guest PC 0x0c0c4490 */
if(!s->budget--) { s->failed_pc=0x0c0c4490u; return 0; }
r[0]=0x00000058u;
goto P_0c0c4492;
P_0c0c4492: /* original f4c6, guest PC 0x0c0c4492 */
if(!s->budget--) { s->failed_pc=0x0c0c4492u; return 0; }
vf3_matrix_load(s,ram,4,r[12]+r[0]);
goto P_0c0c4494;
P_0c0c4494: /* original e03a, guest PC 0x0c0c4494 */
if(!s->budget--) { s->failed_pc=0x0c0c4494u; return 0; }
r[0]=0x0000003au;
goto P_0c0c4496;
P_0c0c4496: /* original 05cc, guest PC 0x0c0c4496 */
if(!s->budget--) { s->failed_pc=0x0c0c4496u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c4498;
P_0c0c4498: /* original 2558, guest PC 0x0c0c4498 */
if(!s->budget--) { s->failed_pc=0x0c0c4498u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0c449a;
P_0c0c449a: /* original 8908, guest PC 0x0c0c449a */
if(!s->budget--) { s->failed_pc=0x0c0c449au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c44ae; }
goto P_0c0c449c;
P_0c0c449c: /* original e033, guest PC 0x0c0c449c */
if(!s->budget--) { s->failed_pc=0x0c0c449cu; return 0; }
r[0]=0x00000033u;
goto P_0c0c449e;
P_0c0c449e: /* original 9325, guest PC 0x0c0c449e */
if(!s->budget--) { s->failed_pc=0x0c0c449eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c44ecu,2);
goto P_0c0c44a0;
P_0c0c44a0: /* original 05cc, guest PC 0x0c0c44a0 */
if(!s->budget--) { s->failed_pc=0x0c0c44a0u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c44a2;
P_0c0c44a2: /* original 655c, guest PC 0x0c0c44a2 */
if(!s->budget--) { s->failed_pc=0x0c0c44a2u; return 0; }
r[5]=r[5]&255u;
goto P_0c0c44a4;
P_0c0c44a4: /* original 3530, guest PC 0x0c0c44a4 */
if(!s->budget--) { s->failed_pc=0x0c0c44a4u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[3])!=0);
goto P_0c0c44a6;
P_0c0c44a6: /* original 8d02, guest PC 0x0c0c44a6 */
if(!s->budget--) { s->failed_pc=0x0c0c44a6u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,14);
if(cond) { goto P_0c0c44ae; }
goto P_0c0c44aa;
P_0c0c44a8: /* original f4ec, guest PC 0x0c0c44a8 */
if(!s->budget--) { s->failed_pc=0x0c0c44a8u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0c44aa;
P_0c0c44aa: /* original e060, guest PC 0x0c0c44aa */
if(!s->budget--) { s->failed_pc=0x0c0c44aau; return 0; }
r[0]=0x00000060u;
goto P_0c0c44ac;
P_0c0c44ac: /* original 0454, guest PC 0x0c0c44ac */
if(!s->budget--) { s->failed_pc=0x0c0c44acu; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c44ae;
P_0c0c44ae: /* original 54f1, guest PC 0x0c0c44ae */
if(!s->budget--) { s->failed_pc=0x0c0c44aeu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c44b0;
P_0c0c44b0: /* original c70f, guest PC 0x0c0c44b0 */
if(!s->budget--) { s->failed_pc=0x0c0c44b0u; return 0; }
r[0]=code_base|0x000c44f0u;
goto P_0c0c44b2;
P_0c0c44b2: /* original e304, guest PC 0x0c0c44b2 */
if(!s->budget--) { s->failed_pc=0x0c0c44b2u; return 0; }
r[3]=0x00000004u;
goto P_0c0c44b4;
P_0c0c44b4: /* original f508, guest PC 0x0c0c44b4 */
if(!s->budget--) { s->failed_pc=0x0c0c44b4u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c44b6;
P_0c0c44b6: /* original 5442, guest PC 0x0c0c44b6 */
if(!s->budget--) { s->failed_pc=0x0c0c44b6u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c0c44b8;
P_0c0c44b8: /* original 2438, guest PC 0x0c0c44b8 */
if(!s->budget--) { s->failed_pc=0x0c0c44b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c44ba;
P_0c0c44ba: /* original 8903, guest PC 0x0c0c44ba */
if(!s->budget--) { s->failed_pc=0x0c0c44bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c44c4; }
goto P_0c0c44bc;
P_0c0c44bc: /* original 2b88, guest PC 0x0c0c44bc */
if(!s->budget--) { s->failed_pc=0x0c0c44bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[8])==0)!=0);
goto P_0c0c44be;
P_0c0c44be: /* original 8901, guest PC 0x0c0c44be */
if(!s->budget--) { s->failed_pc=0x0c0c44beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c44c4; }
goto P_0c0c44c0;
P_0c0c44c0: /* original c70c, guest PC 0x0c0c44c0 */
if(!s->budget--) { s->failed_pc=0x0c0c44c0u; return 0; }
r[0]=code_base|0x000c44f4u;
goto P_0c0c44c2;
P_0c0c44c2: /* original f508, guest PC 0x0c0c44c2 */
if(!s->budget--) { s->failed_pc=0x0c0c44c2u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c44c4;
P_0c0c44c4: /* original f451, guest PC 0x0c0c44c4 */
if(!s->budget--) { s->failed_pc=0x0c0c44c4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c0c44c6;
P_0c0c44c6: /* original f38d, guest PC 0x0c0c44c6 */
if(!s->budget--) { s->failed_pc=0x0c0c44c6u; return 0; }
fr[3]=0;
goto P_0c0c44c8;
P_0c0c44c8: /* original f345, guest PC 0x0c0c44c8 */
if(!s->budget--) { s->failed_pc=0x0c0c44c8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0c44ca;
P_0c0c44ca: /* original 8f01, guest PC 0x0c0c44ca */
if(!s->budget--) { s->failed_pc=0x0c0c44cau; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,15);
if(!cond) { goto P_0c0c44d0; }
goto P_0c0c44ce;
P_0c0c44cc: /* original f5fc, guest PC 0x0c0c44cc */
if(!s->budget--) { s->failed_pc=0x0c0c44ccu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c44ce;
P_0c0c44ce: /* original f45c, guest PC 0x0c0c44ce */
if(!s->budget--) { s->failed_pc=0x0c0c44ceu; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0c44d0;
P_0c0c44d0: /* original e058, guest PC 0x0c0c44d0 */
if(!s->budget--) { s->failed_pc=0x0c0c44d0u; return 0; }
r[0]=0x00000058u;
goto P_0c0c44d2;
P_0c0c44d2: /* original fc47, guest PC 0x0c0c44d2 */
if(!s->budget--) { s->failed_pc=0x0c0c44d2u; return 0; }
vf3_matrix_store(s,ram,4,r[12]+r[0]);
goto P_0c0c44d4;
P_0c0c44d4: /* original e044, guest PC 0x0c0c44d4 */
if(!s->budget--) { s->failed_pc=0x0c0c44d4u; return 0; }
r[0]=0x00000044u;
goto P_0c0c44d6;
P_0c0c44d6: /* original 5cea, guest PC 0x0c0c44d6 */
if(!s->budget--) { s->failed_pc=0x0c0c44d6u; return 0; }
r[12]=read(ram,r[14]+40,4);
goto P_0c0c44d8;
P_0c0c44d8: /* original e12a, guest PC 0x0c0c44d8 */
if(!s->budget--) { s->failed_pc=0x0c0c44d8u; return 0; }
r[1]=0x0000002au;
goto P_0c0c44da;
P_0c0c44da: /* original 04cd, guest PC 0x0c0c44da */
if(!s->budget--) { s->failed_pc=0x0c0c44dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0c44dc;
P_0c0c44dc: /* original 50f1, guest PC 0x0c0c44dc */
if(!s->budget--) { s->failed_pc=0x0c0c44dcu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0c44de;
P_0c0c44de: /* original 001c, guest PC 0x0c0c44de */
if(!s->budget--) { s->failed_pc=0x0c0c44deu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0c44e0;
P_0c0c44e0: /* original 600c, guest PC 0x0c0c44e0 */
if(!s->budget--) { s->failed_pc=0x0c0c44e0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c44e2;
P_0c0c44e2: /* original 8801, guest PC 0x0c0c44e2 */
if(!s->budget--) { s->failed_pc=0x0c0c44e2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c44e4;
P_0c0c44e4: /* original 8b0a, guest PC 0x0c0c44e4 */
if(!s->budget--) { s->failed_pc=0x0c0c44e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c44fc; }
goto P_0c0c44e6;
P_0c0c44e6: /* original d404, guest PC 0x0c0c44e6 */
if(!s->budget--) { s->failed_pc=0x0c0c44e6u; return 0; }
r[4]=read(ram,0x0c0c44f8u,4);
goto P_0c0c44e8;
P_0c0c44e8: /* original a00f, guest PC 0x0c0c44e8 */
if(!s->budget--) { s->failed_pc=0x0c0c44e8u; return 0; }
goto P_0c0c450a;
P_0c0c44ea: /* original 0009, guest PC 0x0c0c44ea */
if(!s->budget--) { s->failed_pc=0x0c0c44eau; return 0; }
if(!vf3_matrix_family(0x0c0c44ecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c44ecu; return 0; } return 1;
P_0c0c44fc: /* original 65c2, guest PC 0x0c0c44fc */
if(!s->budget--) { s->failed_pc=0x0c0c44fcu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0c44fe;
P_0c0c44fe: /* original 2588, guest PC 0x0c0c44fe */
if(!s->budget--) { s->failed_pc=0x0c0c44feu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[8])==0)!=0);
goto P_0c0c4500;
P_0c0c4500: /* original 8b03, guest PC 0x0c0c4500 */
if(!s->budget--) { s->failed_pc=0x0c0c4500u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c450a; }
goto P_0c0c4502;
P_0c0c4502: /* original 9295, guest PC 0x0c0c4502 */
if(!s->budget--) { s->failed_pc=0x0c0c4502u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4630u,2);
goto P_0c0c4504;
P_0c0c4504: /* original e044, guest PC 0x0c0c4504 */
if(!s->budget--) { s->failed_pc=0x0c0c4504u; return 0; }
r[0]=0x00000044u;
goto P_0c0c4506;
P_0c0c4506: /* original 3428, guest PC 0x0c0c4506 */
if(!s->budget--) { s->failed_pc=0x0c0c4506u; return 0; }
r[4]-=r[2];
goto P_0c0c4508;
P_0c0c4508: /* original 0c45, guest PC 0x0c0c4508 */
if(!s->budget--) { s->failed_pc=0x0c0c4508u; return 0; }
write(ram,r[12]+r[0],r[4],2);
goto P_0c0c450a;
P_0c0c450a: /* original 55e4, guest PC 0x0c0c450a */
if(!s->budget--) { s->failed_pc=0x0c0c450au; return 0; }
r[5]=read(ram,r[14]+16,4);
goto P_0c0c450c;
P_0c0c450c: /* original e061, guest PC 0x0c0c450c */
if(!s->budget--) { s->failed_pc=0x0c0c450cu; return 0; }
r[0]=0x00000061u;
goto P_0c0c450e;
P_0c0c450e: /* original 9790, guest PC 0x0c0c450e */
if(!s->budget--) { s->failed_pc=0x0c0c450eu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4632u,2);
goto P_0c0c4510;
P_0c0c4510: /* original 055c, guest PC 0x0c0c4510 */
if(!s->budget--) { s->failed_pc=0x0c0c4510u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c4512;
P_0c0c4512: /* original d048, guest PC 0x0c0c4512 */
if(!s->budget--) { s->failed_pc=0x0c0c4512u; return 0; }
r[0]=read(ram,0x0c0c4634u,4);
goto P_0c0c4514;
P_0c0c4514: /* original 655c, guest PC 0x0c0c4514 */
if(!s->budget--) { s->failed_pc=0x0c0c4514u; return 0; }
r[5]=r[5]&255u;
goto P_0c0c4516;
P_0c0c4516: /* original 4500, guest PC 0x0c0c4516 */
if(!s->budget--) { s->failed_pc=0x0c0c4516u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0c4518;
P_0c0c4518: /* original 4500, guest PC 0x0c0c4518 */
if(!s->budget--) { s->failed_pc=0x0c0c4518u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0c451a;
P_0c0c451a: /* original 055d, guest PC 0x0c0c451a */
if(!s->budget--) { s->failed_pc=0x0c0c451au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0c451c;
P_0c0c451c: /* original 345c, guest PC 0x0c0c451c */
if(!s->budget--) { s->failed_pc=0x0c0c451cu; return 0; }
r[4]+=r[5];
goto P_0c0c451e;
P_0c0c451e: /* original d546, guest PC 0x0c0c451e */
if(!s->budget--) { s->failed_pc=0x0c0c451eu; return 0; }
r[5]=read(ram,0x0c0c4638u,4);
goto P_0c0c4520;
P_0c0c4520: /* original 644d, guest PC 0x0c0c4520 */
if(!s->budget--) { s->failed_pc=0x0c0c4520u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0c4522;
P_0c0c4522: /* original 2f56, guest PC 0x0c0c4522 */
if(!s->budget--) { s->failed_pc=0x0c0c4522u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4524;
P_0c0c4524: /* original 2f46, guest PC 0x0c0c4524 */
if(!s->budget--) { s->failed_pc=0x0c0c4524u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4526;
P_0c0c4526: /* original d245, guest PC 0x0c0c4526 */
if(!s->budget--) { s->failed_pc=0x0c0c4526u; return 0; }
r[2]=read(ram,0x0c0c463cu,4);
goto P_0c0c4528;
P_0c0c4528: /* original 65f3, guest PC 0x0c0c4528 */
if(!s->budget--) { s->failed_pc=0x0c0c4528u; return 0; }
r[5]=r[15];
goto P_0c0c452a;
P_0c0c452a: /* original 66f3, guest PC 0x0c0c452a */
if(!s->budget--) { s->failed_pc=0x0c0c452au; return 0; }
r[6]=r[15];
goto P_0c0c452c;
P_0c0c452c: /* original 64f3, guest PC 0x0c0c452c */
if(!s->budget--) { s->failed_pc=0x0c0c452cu; return 0; }
r[4]=r[15];
goto P_0c0c452e;
P_0c0c452e: /* original 7618, guest PC 0x0c0c452e */
if(!s->budget--) { s->failed_pc=0x0c0c452eu; return 0; }
r[6]+=0x00000018u;
goto P_0c0c4530;
P_0c0c4530: /* original 7514, guest PC 0x0c0c4530 */
if(!s->budget--) { s->failed_pc=0x0c0c4530u; return 0; }
r[5]+=0x00000014u;
goto P_0c0c4532;
P_0c0c4532: /* original 420b, guest PC 0x0c0c4532 */
if(!s->budget--) { s->failed_pc=0x0c0c4532u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c4536u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4536u) { target=s->pc; goto dispatch; }
goto P_0c0c4536;
P_0c0c4534: /* original 7410, guest PC 0x0c0c4534 */
if(!s->budget--) { s->failed_pc=0x0c0c4534u; return 0; }
r[4]+=0x00000010u;
goto P_0c0c4536;
P_0c0c4536: /* original e010, guest PC 0x0c0c4536 */
if(!s->budget--) { s->failed_pc=0x0c0c4536u; return 0; }
r[0]=0x00000010u;
goto P_0c0c4538;
P_0c0c4538: /* original d341, guest PC 0x0c0c4538 */
if(!s->budget--) { s->failed_pc=0x0c0c4538u; return 0; }
r[3]=read(ram,0x0c0c4640u,4);
goto P_0c0c453a;
P_0c0c453a: /* original 7f08, guest PC 0x0c0c453a */
if(!s->budget--) { s->failed_pc=0x0c0c453au; return 0; }
r[15]+=0x00000008u;
goto P_0c0c453c;
P_0c0c453c: /* original f6f6, guest PC 0x0c0c453c */
if(!s->budget--) { s->failed_pc=0x0c0c453cu; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0c453e;
P_0c0c453e: /* original e00c, guest PC 0x0c0c453e */
if(!s->budget--) { s->failed_pc=0x0c0c453eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c4540;
P_0c0c4540: /* original f5f6, guest PC 0x0c0c4540 */
if(!s->budget--) { s->failed_pc=0x0c0c4540u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c4542;
P_0c0c4542: /* original e008, guest PC 0x0c0c4542 */
if(!s->budget--) { s->failed_pc=0x0c0c4542u; return 0; }
r[0]=0x00000008u;
goto P_0c0c4544;
P_0c0c4544: /* original 430b, guest PC 0x0c0c4544 */
if(!s->budget--) { s->failed_pc=0x0c0c4544u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4548u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4548u) { target=s->pc; goto dispatch; }
goto P_0c0c4548;
P_0c0c4546: /* original f4f6, guest PC 0x0c0c4546 */
if(!s->budget--) { s->failed_pc=0x0c0c4546u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c4548;
P_0c0c4548: /* original 54e4, guest PC 0x0c0c4548 */
if(!s->budget--) { s->failed_pc=0x0c0c4548u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c0c454a;
P_0c0c454a: /* original e060, guest PC 0x0c0c454a */
if(!s->budget--) { s->failed_pc=0x0c0c454au; return 0; }
r[0]=0x00000060u;
goto P_0c0c454c;
P_0c0c454c: /* original d13d, guest PC 0x0c0c454c */
if(!s->budget--) { s->failed_pc=0x0c0c454cu; return 0; }
r[1]=read(ram,0x0c0c4644u,4);
goto P_0c0c454e;
P_0c0c454e: /* original 044c, guest PC 0x0c0c454e */
if(!s->budget--) { s->failed_pc=0x0c0c454eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c4550;
P_0c0c4550: /* original 644c, guest PC 0x0c0c4550 */
if(!s->budget--) { s->failed_pc=0x0c0c4550u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c4552;
P_0c0c4552: /* original 4400, guest PC 0x0c0c4552 */
if(!s->budget--) { s->failed_pc=0x0c0c4552u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c4554;
P_0c0c4554: /* original 6043, guest PC 0x0c0c4554 */
if(!s->budget--) { s->failed_pc=0x0c0c4554u; return 0; }
r[0]=r[4];
goto P_0c0c4556;
P_0c0c4556: /* original 7001, guest PC 0x0c0c4556 */
if(!s->budget--) { s->failed_pc=0x0c0c4556u; return 0; }
r[0]+=0x00000001u;
goto P_0c0c4558;
P_0c0c4558: /* original 4000, guest PC 0x0c0c4558 */
if(!s->budget--) { s->failed_pc=0x0c0c4558u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c455a;
P_0c0c455a: /* original 001d, guest PC 0x0c0c455a */
if(!s->budget--) { s->failed_pc=0x0c0c455au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c0c455c;
P_0c0c455c: /* original 81fc, guest PC 0x0c0c455c */
if(!s->budget--) { s->failed_pc=0x0c0c455cu; return 0; }
write(ram,r[15]+24,r[0],2);
goto P_0c0c455e;
P_0c0c455e: /* original e061, guest PC 0x0c0c455e */
if(!s->budget--) { s->failed_pc=0x0c0c455eu; return 0; }
r[0]=0x00000061u;
goto P_0c0c4560;
P_0c0c4560: /* original 54e4, guest PC 0x0c0c4560 */
if(!s->budget--) { s->failed_pc=0x0c0c4560u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c0c4562;
P_0c0c4562: /* original d239, guest PC 0x0c0c4562 */
if(!s->budget--) { s->failed_pc=0x0c0c4562u; return 0; }
r[2]=read(ram,0x0c0c4648u,4);
goto P_0c0c4564;
P_0c0c4564: /* original 054c, guest PC 0x0c0c4564 */
if(!s->budget--) { s->failed_pc=0x0c0c4564u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c4566;
P_0c0c4566: /* original e034, guest PC 0x0c0c4566 */
if(!s->budget--) { s->failed_pc=0x0c0c4566u; return 0; }
r[0]=0x00000034u;
goto P_0c0c4568;
P_0c0c4568: /* original 655c, guest PC 0x0c0c4568 */
if(!s->budget--) { s->failed_pc=0x0c0c4568u; return 0; }
r[5]=r[5]&255u;
goto P_0c0c456a;
P_0c0c456a: /* original 6453, guest PC 0x0c0c456a */
if(!s->budget--) { s->failed_pc=0x0c0c456au; return 0; }
r[4]=r[5];
goto P_0c0c456c;
P_0c0c456c: /* original 4408, guest PC 0x0c0c456c */
if(!s->budget--) { s->failed_pc=0x0c0c456cu; return 0; }
r[4]<<=2;
goto P_0c0c456e;
P_0c0c456e: /* original 6353, guest PC 0x0c0c456e */
if(!s->budget--) { s->failed_pc=0x0c0c456eu; return 0; }
r[3]=r[5];
goto P_0c0c4570;
P_0c0c4570: /* original 343c, guest PC 0x0c0c4570 */
if(!s->budget--) { s->failed_pc=0x0c0c4570u; return 0; }
r[4]+=r[3];
goto P_0c0c4572;
P_0c0c4572: /* original 4408, guest PC 0x0c0c4572 */
if(!s->budget--) { s->failed_pc=0x0c0c4572u; return 0; }
r[4]<<=2;
goto P_0c0c4574;
P_0c0c4574: /* original 644f, guest PC 0x0c0c4574 */
if(!s->budget--) { s->failed_pc=0x0c0c4574u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0c4576;
P_0c0c4576: /* original 342c, guest PC 0x0c0c4576 */
if(!s->budget--) { s->failed_pc=0x0c0c4576u; return 0; }
r[4]+=r[2];
goto P_0c0c4578;
P_0c0c4578: /* original f348, guest PC 0x0c0c4578 */
if(!s->budget--) { s->failed_pc=0x0c0c4578u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c0c457a;
P_0c0c457a: /* original ff37, guest PC 0x0c0c457a */
if(!s->budget--) { s->failed_pc=0x0c0c457au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c457c;
P_0c0c457c: /* original e004, guest PC 0x0c0c457c */
if(!s->budget--) { s->failed_pc=0x0c0c457cu; return 0; }
r[0]=0x00000004u;
goto P_0c0c457e;
P_0c0c457e: /* original f346, guest PC 0x0c0c457e */
if(!s->budget--) { s->failed_pc=0x0c0c457eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0c4580;
P_0c0c4580: /* original e030, guest PC 0x0c0c4580 */
if(!s->budget--) { s->failed_pc=0x0c0c4580u; return 0; }
r[0]=0x00000030u;
goto P_0c0c4582;
P_0c0c4582: /* original ff37, guest PC 0x0c0c4582 */
if(!s->budget--) { s->failed_pc=0x0c0c4582u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c4584;
P_0c0c4584: /* original e008, guest PC 0x0c0c4584 */
if(!s->budget--) { s->failed_pc=0x0c0c4584u; return 0; }
r[0]=0x00000008u;
goto P_0c0c4586;
P_0c0c4586: /* original f346, guest PC 0x0c0c4586 */
if(!s->budget--) { s->failed_pc=0x0c0c4586u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0c4588;
P_0c0c4588: /* original e02c, guest PC 0x0c0c4588 */
if(!s->budget--) { s->failed_pc=0x0c0c4588u; return 0; }
r[0]=0x0000002cu;
goto P_0c0c458a;
P_0c0c458a: /* original 61f3, guest PC 0x0c0c458a */
if(!s->budget--) { s->failed_pc=0x0c0c458au; return 0; }
r[1]=r[15];
goto P_0c0c458c;
P_0c0c458c: /* original ff37, guest PC 0x0c0c458c */
if(!s->budget--) { s->failed_pc=0x0c0c458cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c458e;
P_0c0c458e: /* original 7138, guest PC 0x0c0c458e */
if(!s->budget--) { s->failed_pc=0x0c0c458eu; return 0; }
r[1]+=0x00000038u;
goto P_0c0c4590;
P_0c0c4590: /* original 8546, guest PC 0x0c0c4590 */
if(!s->budget--) { s->failed_pc=0x0c0c4590u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+12,2);
goto P_0c0c4592;
P_0c0c4592: /* original 2101, guest PC 0x0c0c4592 */
if(!s->budget--) { s->failed_pc=0x0c0c4592u; return 0; }
write(ram,r[1],r[0],2);
goto P_0c0c4594;
P_0c0c4594: /* original e1f4, guest PC 0x0c0c4594 */
if(!s->budget--) { s->failed_pc=0x0c0c4594u; return 0; }
r[1]=0xfffffff4u;
goto P_0c0c4596;
P_0c0c4596: /* original 8547, guest PC 0x0c0c4596 */
if(!s->budget--) { s->failed_pc=0x0c0c4596u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+14,2);
goto P_0c0c4598;
P_0c0c4598: /* original 81fa, guest PC 0x0c0c4598 */
if(!s->budget--) { s->failed_pc=0x0c0c4598u; return 0; }
write(ram,r[15]+20,r[0],2);
goto P_0c0c459a;
P_0c0c459a: /* original 8548, guest PC 0x0c0c459a */
if(!s->budget--) { s->failed_pc=0x0c0c459au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+16,2);
goto P_0c0c459c;
P_0c0c459c: /* original 2f01, guest PC 0x0c0c459c */
if(!s->budget--) { s->failed_pc=0x0c0c459cu; return 0; }
write(ram,r[15],r[0],2);
goto P_0c0c459e;
P_0c0c459e: /* original e04c, guest PC 0x0c0c459e */
if(!s->budget--) { s->failed_pc=0x0c0c459eu; return 0; }
r[0]=0x0000004cu;
goto P_0c0c45a0;
P_0c0c45a0: /* original 06cd, guest PC 0x0c0c45a0 */
if(!s->budget--) { s->failed_pc=0x0c0c45a0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0c45a2;
P_0c0c45a2: /* original e04a, guest PC 0x0c0c45a2 */
if(!s->budget--) { s->failed_pc=0x0c0c45a2u; return 0; }
r[0]=0x0000004au;
goto P_0c0c45a4;
P_0c0c45a4: /* original 05cd, guest PC 0x0c0c45a4 */
if(!s->budget--) { s->failed_pc=0x0c0c45a4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0c45a6;
P_0c0c45a6: /* original e04e, guest PC 0x0c0c45a6 */
if(!s->budget--) { s->failed_pc=0x0c0c45a6u; return 0; }
r[0]=0x0000004eu;
goto P_0c0c45a8;
P_0c0c45a8: /* original 04cd, guest PC 0x0c0c45a8 */
if(!s->budget--) { s->failed_pc=0x0c0c45a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0c45aa;
P_0c0c45aa: /* original 74f9, guest PC 0x0c0c45aa */
if(!s->budget--) { s->failed_pc=0x0c0c45aau; return 0; }
r[4]+=0xfffffff9u;
goto P_0c0c45ac;
P_0c0c45ac: /* original 634f, guest PC 0x0c0c45ac */
if(!s->budget--) { s->failed_pc=0x0c0c45acu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0c45ae;
P_0c0c45ae: /* original 0c45, guest PC 0x0c0c45ae */
if(!s->budget--) { s->failed_pc=0x0c0c45aeu; return 0; }
write(ram,r[12]+r[0],r[4],2);
goto P_0c0c45b0;
P_0c0c45b0: /* original 431c, guest PC 0x0c0c45b0 */
if(!s->budget--) { s->failed_pc=0x0c0c45b0u; return 0; }
r[3]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[3]>>((-r[1])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[1]&31u);
goto P_0c0c45b2;
P_0c0c45b2: /* original 6433, guest PC 0x0c0c45b2 */
if(!s->budget--) { s->failed_pc=0x0c0c45b2u; return 0; }
r[4]=r[3];
goto P_0c0c45b4;
P_0c0c45b4: /* original 63f1, guest PC 0x0c0c45b4 */
if(!s->budget--) { s->failed_pc=0x0c0c45b4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0c45b6;
P_0c0c45b6: /* original 2338, guest PC 0x0c0c45b6 */
if(!s->budget--) { s->failed_pc=0x0c0c45b6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c45b8;
P_0c0c45b8: /* original 8d01, guest PC 0x0c0c45b8 */
if(!s->budget--) { s->failed_pc=0x0c0c45b8u; return 0; }
cond=r[17]&1u;
r[4]+=r[6];
if(cond) { goto P_0c0c45be; }
goto P_0c0c45bc;
P_0c0c45ba: /* original 346c, guest PC 0x0c0c45ba */
if(!s->budget--) { s->failed_pc=0x0c0c45bau; return 0; }
r[4]+=r[6];
goto P_0c0c45bc;
P_0c0c45bc: /* original 7501, guest PC 0x0c0c45bc */
if(!s->budget--) { s->failed_pc=0x0c0c45bcu; return 0; }
r[5]+=0x00000001u;
goto P_0c0c45be;
P_0c0c45be: /* original 66c2, guest PC 0x0c0c45be */
if(!s->budget--) { s->failed_pc=0x0c0c45beu; return 0; }
tmp=read(ram,r[12],4);
r[6]=tmp;
goto P_0c0c45c0;
P_0c0c45c0: /* original 2688, guest PC 0x0c0c45c0 */
if(!s->budget--) { s->failed_pc=0x0c0c45c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[8])==0)!=0);
goto P_0c0c45c2;
P_0c0c45c2: /* original 8b08, guest PC 0x0c0c45c2 */
if(!s->budget--) { s->failed_pc=0x0c0c45c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c45d6; }
goto P_0c0c45c4;
P_0c0c45c4: /* original d122, guest PC 0x0c0c45c4 */
if(!s->budget--) { s->failed_pc=0x0c0c45c4u; return 0; }
r[1]=read(ram,0x0c0c4650u,4);
goto P_0c0c45c6;
P_0c0c45c6: /* original d321, guest PC 0x0c0c45c6 */
if(!s->budget--) { s->failed_pc=0x0c0c45c6u; return 0; }
r[3]=read(ram,0x0c0c464cu,4);
goto P_0c0c45c8;
P_0c0c45c8: /* original 6212, guest PC 0x0c0c45c8 */
if(!s->budget--) { s->failed_pc=0x0c0c45c8u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0c45ca;
P_0c0c45ca: /* original 2238, guest PC 0x0c0c45ca */
if(!s->budget--) { s->failed_pc=0x0c0c45cau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c45cc;
P_0c0c45cc: /* original 8b03, guest PC 0x0c0c45cc */
if(!s->budget--) { s->failed_pc=0x0c0c45ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c45d6; }
goto P_0c0c45ce;
P_0c0c45ce: /* original e04c, guest PC 0x0c0c45ce */
if(!s->budget--) { s->failed_pc=0x0c0c45ceu; return 0; }
r[0]=0x0000004cu;
goto P_0c0c45d0;
P_0c0c45d0: /* original 0c45, guest PC 0x0c0c45d0 */
if(!s->budget--) { s->failed_pc=0x0c0c45d0u; return 0; }
write(ram,r[12]+r[0],r[4],2);
goto P_0c0c45d2;
P_0c0c45d2: /* original e04a, guest PC 0x0c0c45d2 */
if(!s->budget--) { s->failed_pc=0x0c0c45d2u; return 0; }
r[0]=0x0000004au;
goto P_0c0c45d4;
P_0c0c45d4: /* original 0c55, guest PC 0x0c0c45d4 */
if(!s->budget--) { s->failed_pc=0x0c0c45d4u; return 0; }
write(ram,r[12]+r[0],r[5],2);
goto P_0c0c45d6;
P_0c0c45d6: /* original 85fa, guest PC 0x0c0c45d6 */
if(!s->budget--) { s->failed_pc=0x0c0c45d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+20,2);
goto P_0c0c45d8;
P_0c0c45d8: /* original 3048, guest PC 0x0c0c45d8 */
if(!s->budget--) { s->failed_pc=0x0c0c45d8u; return 0; }
r[0]-=r[4];
goto P_0c0c45da;
P_0c0c45da: /* original 81fa, guest PC 0x0c0c45da */
if(!s->budget--) { s->failed_pc=0x0c0c45dau; return 0; }
write(ram,r[15]+20,r[0],2);
goto P_0c0c45dc;
P_0c0c45dc: /* original 63f1, guest PC 0x0c0c45dc */
if(!s->budget--) { s->failed_pc=0x0c0c45dcu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0c45de;
P_0c0c45de: /* original 3358, guest PC 0x0c0c45de */
if(!s->budget--) { s->failed_pc=0x0c0c45deu; return 0; }
r[3]-=r[5];
goto P_0c0c45e0;
P_0c0c45e0: /* original 2f31, guest PC 0x0c0c45e0 */
if(!s->budget--) { s->failed_pc=0x0c0c45e0u; return 0; }
write(ram,r[15],r[3],2);
goto P_0c0c45e2;
P_0c0c45e2: /* original d31c, guest PC 0x0c0c45e2 */
if(!s->budget--) { s->failed_pc=0x0c0c45e2u; return 0; }
r[3]=read(ram,0x0c0c4654u,4);
goto P_0c0c45e4;
P_0c0c45e4: /* original 430b, guest PC 0x0c0c45e4 */
if(!s->budget--) { s->failed_pc=0x0c0c45e4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c45e8u;
r[11]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c45e8u) { target=s->pc; goto dispatch; }
goto P_0c0c45e8;
P_0c0c45e6: /* original 5be4, guest PC 0x0c0c45e6 */
if(!s->budget--) { s->failed_pc=0x0c0c45e6u; return 0; }
r[11]=read(ram,r[14]+16,4);
goto P_0c0c45e8;
P_0c0c45e8: /* original e02c, guest PC 0x0c0c45e8 */
if(!s->budget--) { s->failed_pc=0x0c0c45e8u; return 0; }
r[0]=0x0000002cu;
goto P_0c0c45ea;
P_0c0c45ea: /* original d31b, guest PC 0x0c0c45ea */
if(!s->budget--) { s->failed_pc=0x0c0c45eau; return 0; }
r[3]=read(ram,0x0c0c4658u,4);
goto P_0c0c45ec;
P_0c0c45ec: /* original f6f6, guest PC 0x0c0c45ec */
if(!s->budget--) { s->failed_pc=0x0c0c45ecu; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0c45ee;
P_0c0c45ee: /* original e030, guest PC 0x0c0c45ee */
if(!s->budget--) { s->failed_pc=0x0c0c45eeu; return 0; }
r[0]=0x00000030u;
goto P_0c0c45f0;
P_0c0c45f0: /* original f5f6, guest PC 0x0c0c45f0 */
if(!s->budget--) { s->failed_pc=0x0c0c45f0u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c45f2;
P_0c0c45f2: /* original e034, guest PC 0x0c0c45f2 */
if(!s->budget--) { s->failed_pc=0x0c0c45f2u; return 0; }
r[0]=0x00000034u;
goto P_0c0c45f4;
P_0c0c45f4: /* original 430b, guest PC 0x0c0c45f4 */
if(!s->budget--) { s->failed_pc=0x0c0c45f4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c45f8u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c45f8u) { target=s->pc; goto dispatch; }
goto P_0c0c45f8;
P_0c0c45f6: /* original f4f6, guest PC 0x0c0c45f6 */
if(!s->budget--) { s->failed_pc=0x0c0c45f6u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c45f8;
P_0c0c45f8: /* original d318, guest PC 0x0c0c45f8 */
if(!s->budget--) { s->failed_pc=0x0c0c45f8u; return 0; }
r[3]=read(ram,0x0c0c465cu,4);
goto P_0c0c45fa;
P_0c0c45fa: /* original e038, guest PC 0x0c0c45fa */
if(!s->budget--) { s->failed_pc=0x0c0c45fau; return 0; }
r[0]=0x00000038u;
goto P_0c0c45fc;
P_0c0c45fc: /* original 430b, guest PC 0x0c0c45fc */
if(!s->budget--) { s->failed_pc=0x0c0c45fcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4600u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4600u) { target=s->pc; goto dispatch; }
goto P_0c0c4600;
P_0c0c45fe: /* original 04fd, guest PC 0x0c0c45fe */
if(!s->budget--) { s->failed_pc=0x0c0c45feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+r[0],2);
goto P_0c0c4600;
P_0c0c4600: /* original d317, guest PC 0x0c0c4600 */
if(!s->budget--) { s->failed_pc=0x0c0c4600u; return 0; }
r[3]=read(ram,0x0c0c4660u,4);
goto P_0c0c4602;
P_0c0c4602: /* original 430b, guest PC 0x0c0c4602 */
if(!s->budget--) { s->failed_pc=0x0c0c4602u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4606u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4606u) { target=s->pc; goto dispatch; }
goto P_0c0c4606;
P_0c0c4604: /* original 64f1, guest PC 0x0c0c4604 */
if(!s->budget--) { s->failed_pc=0x0c0c4604u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c0c4606;
P_0c0c4606: /* original d317, guest PC 0x0c0c4606 */
if(!s->budget--) { s->failed_pc=0x0c0c4606u; return 0; }
r[3]=read(ram,0x0c0c4664u,4);
goto P_0c0c4608;
P_0c0c4608: /* original 85fa, guest PC 0x0c0c4608 */
if(!s->budget--) { s->failed_pc=0x0c0c4608u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+20,2);
goto P_0c0c460a;
P_0c0c460a: /* original 430b, guest PC 0x0c0c460a */
if(!s->budget--) { s->failed_pc=0x0c0c460au; return 0; }
target=r[3];
r[16]=code_base|0x0c0c460eu;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c460eu) { target=s->pc; goto dispatch; }
goto P_0c0c460e;
P_0c0c460c: /* original 6403, guest PC 0x0c0c460c */
if(!s->budget--) { s->failed_pc=0x0c0c460cu; return 0; }
r[4]=r[0];
goto P_0c0c460e;
P_0c0c460e: /* original 85fc, guest PC 0x0c0c460e */
if(!s->budget--) { s->failed_pc=0x0c0c460eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+24,2);
goto P_0c0c4610;
P_0c0c4610: /* original 88ff, guest PC 0x0c0c4610 */
if(!s->budget--) { s->failed_pc=0x0c0c4610u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c4612;
P_0c0c4612: /* original 892c, guest PC 0x0c0c4612 */
if(!s->budget--) { s->failed_pc=0x0c0c4612u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c466e; }
goto P_0c0c4614;
P_0c0c4614: /* original 5cea, guest PC 0x0c0c4614 */
if(!s->budget--) { s->failed_pc=0x0c0c4614u; return 0; }
r[12]=read(ram,r[14]+40,4);
goto P_0c0c4616;
P_0c0c4616: /* original e036, guest PC 0x0c0c4616 */
if(!s->budget--) { s->failed_pc=0x0c0c4616u; return 0; }
r[0]=0x00000036u;
goto P_0c0c4618;
P_0c0c4618: /* original 03cc, guest PC 0x0c0c4618 */
if(!s->budget--) { s->failed_pc=0x0c0c4618u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c461a;
P_0c0c461a: /* original 2338, guest PC 0x0c0c461a */
if(!s->budget--) { s->failed_pc=0x0c0c461au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c461c;
P_0c0c461c: /* original 8b27, guest PC 0x0c0c461c */
if(!s->budget--) { s->failed_pc=0x0c0c461cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c466e; }
goto P_0c0c461e;
P_0c0c461e: /* original 50d8, guest PC 0x0c0c461e */
if(!s->budget--) { s->failed_pc=0x0c0c461eu; return 0; }
r[0]=read(ram,r[13]+32,4);
goto P_0c0c4620;
P_0c0c4620: /* original 88ff, guest PC 0x0c0c4620 */
if(!s->budget--) { s->failed_pc=0x0c0c4620u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c4622;
P_0c0c4622: /* original 8b24, guest PC 0x0c0c4622 */
if(!s->budget--) { s->failed_pc=0x0c0c4622u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c466e; }
goto P_0c0c4624;
P_0c0c4624: /* original 50da, guest PC 0x0c0c4624 */
if(!s->budget--) { s->failed_pc=0x0c0c4624u; return 0; }
r[0]=read(ram,r[13]+40,4);
goto P_0c0c4626;
P_0c0c4626: /* original 88ff, guest PC 0x0c0c4626 */
if(!s->budget--) { s->failed_pc=0x0c0c4626u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c4628;
P_0c0c4628: /* original 8b21, guest PC 0x0c0c4628 */
if(!s->budget--) { s->failed_pc=0x0c0c4628u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c466e; }
goto P_0c0c462a;
P_0c0c462a: /* original 85fc, guest PC 0x0c0c462a */
if(!s->budget--) { s->failed_pc=0x0c0c462au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+24,2);
goto P_0c0c462c;
P_0c0c462c: /* original a01c, guest PC 0x0c0c462c */
if(!s->budget--) { s->failed_pc=0x0c0c462cu; return 0; }
r[4]=r[0];
goto P_0c0c4668;
P_0c0c462e: /* original 6403, guest PC 0x0c0c462e */
if(!s->budget--) { s->failed_pc=0x0c0c462eu; return 0; }
r[4]=r[0];
if(!vf3_matrix_family(0x0c0c4630u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c4630u; return 0; } return 1;
P_0c0c4668: /* original d33a, guest PC 0x0c0c4668 */
if(!s->budget--) { s->failed_pc=0x0c0c4668u; return 0; }
r[3]=read(ram,0x0c0c4754u,4);
goto P_0c0c466a;
P_0c0c466a: /* original 430b, guest PC 0x0c0c466a */
if(!s->budget--) { s->failed_pc=0x0c0c466au; return 0; }
target=r[3];
r[16]=code_base|0x0c0c466eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c466eu) { target=s->pc; goto dispatch; }
goto P_0c0c466e;
P_0c0c466c: /* original 0009, guest PC 0x0c0c466c */
if(!s->budget--) { s->failed_pc=0x0c0c466cu; return 0; }
goto P_0c0c466e;
P_0c0c466e: /* original 52e8, guest PC 0x0c0c466e */
if(!s->budget--) { s->failed_pc=0x0c0c466eu; return 0; }
r[2]=read(ram,r[14]+32,4);
goto P_0c0c4670;
P_0c0c4670: /* original 2f22, guest PC 0x0c0c4670 */
if(!s->budget--) { s->failed_pc=0x0c0c4670u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c4672;
P_0c0c4672: /* original d339, guest PC 0x0c0c4672 */
if(!s->budget--) { s->failed_pc=0x0c0c4672u; return 0; }
r[3]=read(ram,0x0c0c4758u,4);
goto P_0c0c4674;
P_0c0c4674: /* original 430b, guest PC 0x0c0c4674 */
if(!s->budget--) { s->failed_pc=0x0c0c4674u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4678u;
r[4]=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4678u) { target=s->pc; goto dispatch; }
goto P_0c0c4678;
P_0c0c4676: /* original 6423, guest PC 0x0c0c4676 */
if(!s->budget--) { s->failed_pc=0x0c0c4676u; return 0; }
r[4]=r[2];
goto P_0c0c4678;
P_0c0c4678: /* original c738, guest PC 0x0c0c4678 */
if(!s->budget--) { s->failed_pc=0x0c0c4678u; return 0; }
r[0]=code_base|0x000c475cu;
goto P_0c0c467a;
P_0c0c467a: /* original 63f2, guest PC 0x0c0c467a */
if(!s->budget--) { s->failed_pc=0x0c0c467au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c467c;
P_0c0c467c: /* original f608, guest PC 0x0c0c467c */
if(!s->budget--) { s->failed_pc=0x0c0c467cu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0c467e;
P_0c0c467e: /* original c738, guest PC 0x0c0c467e */
if(!s->budget--) { s->failed_pc=0x0c0c467eu; return 0; }
r[0]=code_base|0x000c4760u;
goto P_0c0c4680;
P_0c0c4680: /* original f408, guest PC 0x0c0c4680 */
if(!s->budget--) { s->failed_pc=0x0c0c4680u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c4682;
P_0c0c4682: /* original c738, guest PC 0x0c0c4682 */
if(!s->budget--) { s->failed_pc=0x0c0c4682u; return 0; }
r[0]=code_base|0x000c4764u;
goto P_0c0c4684;
P_0c0c4684: /* original f508, guest PC 0x0c0c4684 */
if(!s->budget--) { s->failed_pc=0x0c0c4684u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c4686;
P_0c0c4686: /* original e010, guest PC 0x0c0c4686 */
if(!s->budget--) { s->failed_pc=0x0c0c4686u; return 0; }
r[0]=0x00000010u;
goto P_0c0c4688;
P_0c0c4688: /* original f367, guest PC 0x0c0c4688 */
if(!s->budget--) { s->failed_pc=0x0c0c4688u; return 0; }
vf3_matrix_store(s,ram,6,r[3]+r[0]);
goto P_0c0c468a;
P_0c0c468a: /* original e014, guest PC 0x0c0c468a */
if(!s->budget--) { s->failed_pc=0x0c0c468au; return 0; }
r[0]=0x00000014u;
goto P_0c0c468c;
P_0c0c468c: /* original 63f2, guest PC 0x0c0c468c */
if(!s->budget--) { s->failed_pc=0x0c0c468cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c468e;
P_0c0c468e: /* original f347, guest PC 0x0c0c468e */
if(!s->budget--) { s->failed_pc=0x0c0c468eu; return 0; }
vf3_matrix_store(s,ram,4,r[3]+r[0]);
goto P_0c0c4690;
P_0c0c4690: /* original e018, guest PC 0x0c0c4690 */
if(!s->budget--) { s->failed_pc=0x0c0c4690u; return 0; }
r[0]=0x00000018u;
goto P_0c0c4692;
P_0c0c4692: /* original 63f2, guest PC 0x0c0c4692 */
if(!s->budget--) { s->failed_pc=0x0c0c4692u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c4694;
P_0c0c4694: /* original f357, guest PC 0x0c0c4694 */
if(!s->budget--) { s->failed_pc=0x0c0c4694u; return 0; }
vf3_matrix_store(s,ram,5,r[3]+r[0]);
goto P_0c0c4696;
P_0c0c4696: /* original e302, guest PC 0x0c0c4696 */
if(!s->budget--) { s->failed_pc=0x0c0c4696u; return 0; }
r[3]=0x00000002u;
goto P_0c0c4698;
P_0c0c4698: /* original 64c2, guest PC 0x0c0c4698 */
if(!s->budget--) { s->failed_pc=0x0c0c4698u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c0c469a;
P_0c0c469a: /* original 2438, guest PC 0x0c0c469a */
if(!s->budget--) { s->failed_pc=0x0c0c469au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c469c;
P_0c0c469c: /* original 8920, guest PC 0x0c0c469c */
if(!s->budget--) { s->failed_pc=0x0c0c469cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c46e0; }
goto P_0c0c469e;
P_0c0c469e: /* original e064, guest PC 0x0c0c469e */
if(!s->budget--) { s->failed_pc=0x0c0c469eu; return 0; }
r[0]=0x00000064u;
goto P_0c0c46a0;
P_0c0c46a0: /* original 00cc, guest PC 0x0c0c46a0 */
if(!s->budget--) { s->failed_pc=0x0c0c46a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c46a2;
P_0c0c46a2: /* original 8801, guest PC 0x0c0c46a2 */
if(!s->budget--) { s->failed_pc=0x0c0c46a2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c46a4;
P_0c0c46a4: /* original 8d0c, guest PC 0x0c0c46a4 */
if(!s->budget--) { s->failed_pc=0x0c0c46a4u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0c46c0; }
goto P_0c0c46a8;
P_0c0c46a6: /* original 6403, guest PC 0x0c0c46a6 */
if(!s->budget--) { s->failed_pc=0x0c0c46a6u; return 0; }
r[4]=r[0];
goto P_0c0c46a8;
P_0c0c46a8: /* original e061, guest PC 0x0c0c46a8 */
if(!s->budget--) { s->failed_pc=0x0c0c46a8u; return 0; }
r[0]=0x00000061u;
goto P_0c0c46aa;
P_0c0c46aa: /* original d32f, guest PC 0x0c0c46aa */
if(!s->budget--) { s->failed_pc=0x0c0c46aau; return 0; }
r[3]=read(ram,0x0c0c4768u,4);
goto P_0c0c46ac;
P_0c0c46ac: /* original 04bc, guest PC 0x0c0c46ac */
if(!s->budget--) { s->failed_pc=0x0c0c46acu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c46ae;
P_0c0c46ae: /* original 7037, guest PC 0x0c0c46ae */
if(!s->budget--) { s->failed_pc=0x0c0c46aeu; return 0; }
r[0]+=0x00000037u;
goto P_0c0c46b0;
P_0c0c46b0: /* original 05de, guest PC 0x0c0c46b0 */
if(!s->budget--) { s->failed_pc=0x0c0c46b0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0c46b2;
P_0c0c46b2: /* original 644c, guest PC 0x0c0c46b2 */
if(!s->budget--) { s->failed_pc=0x0c0c46b2u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c46b4;
P_0c0c46b4: /* original 644b, guest PC 0x0c0c46b4 */
if(!s->budget--) { s->failed_pc=0x0c0c46b4u; return 0; }
r[4]=0u-r[4];
goto P_0c0c46b6;
P_0c0c46b6: /* original 434d, guest PC 0x0c0c46b6 */
if(!s->budget--) { s->failed_pc=0x0c0c46b6u; return 0; }
r[3]=(r[4]&0x80000000u)?((r[4]&31u)?r[3]>>((-r[4])&31u):0):r[3]<<(r[4]&31u);
goto P_0c0c46b8;
P_0c0c46b8: /* original 2358, guest PC 0x0c0c46b8 */
if(!s->budget--) { s->failed_pc=0x0c0c46b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0c46ba;
P_0c0c46ba: /* original 8901, guest PC 0x0c0c46ba */
if(!s->budget--) { s->failed_pc=0x0c0c46bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c46c0; }
goto P_0c0c46bc;
P_0c0c46bc: /* original e058, guest PC 0x0c0c46bc */
if(!s->budget--) { s->failed_pc=0x0c0c46bcu; return 0; }
r[0]=0x00000058u;
goto P_0c0c46be;
P_0c0c46be: /* original fce7, guest PC 0x0c0c46be */
if(!s->budget--) { s->failed_pc=0x0c0c46beu; return 0; }
vf3_matrix_store(s,ram,14,r[12]+r[0]);
goto P_0c0c46c0;
P_0c0c46c0: /* original 5cea, guest PC 0x0c0c46c0 */
if(!s->budget--) { s->failed_pc=0x0c0c46c0u; return 0; }
r[12]=read(ram,r[14]+40,4);
goto P_0c0c46c2;
P_0c0c46c2: /* original e036, guest PC 0x0c0c46c2 */
if(!s->budget--) { s->failed_pc=0x0c0c46c2u; return 0; }
r[0]=0x00000036u;
goto P_0c0c46c4;
P_0c0c46c4: /* original 03cc, guest PC 0x0c0c46c4 */
if(!s->budget--) { s->failed_pc=0x0c0c46c4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c46c6;
P_0c0c46c6: /* original 2338, guest PC 0x0c0c46c6 */
if(!s->budget--) { s->failed_pc=0x0c0c46c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c46c8;
P_0c0c46c8: /* original 8b31, guest PC 0x0c0c46c8 */
if(!s->budget--) { s->failed_pc=0x0c0c46c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c472e; }
goto P_0c0c46ca;
P_0c0c46ca: /* original 50d8, guest PC 0x0c0c46ca */
if(!s->budget--) { s->failed_pc=0x0c0c46cau; return 0; }
r[0]=read(ram,r[13]+32,4);
goto P_0c0c46cc;
P_0c0c46cc: /* original 88ff, guest PC 0x0c0c46cc */
if(!s->budget--) { s->failed_pc=0x0c0c46ccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c46ce;
P_0c0c46ce: /* original 8b2e, guest PC 0x0c0c46ce */
if(!s->budget--) { s->failed_pc=0x0c0c46ceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c472e; }
goto P_0c0c46d0;
P_0c0c46d0: /* original 50da, guest PC 0x0c0c46d0 */
if(!s->budget--) { s->failed_pc=0x0c0c46d0u; return 0; }
r[0]=read(ram,r[13]+40,4);
goto P_0c0c46d2;
P_0c0c46d2: /* original 88ff, guest PC 0x0c0c46d2 */
if(!s->budget--) { s->failed_pc=0x0c0c46d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c46d4;
P_0c0c46d4: /* original 8b2b, guest PC 0x0c0c46d4 */
if(!s->budget--) { s->failed_pc=0x0c0c46d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c472e; }
goto P_0c0c46d6;
P_0c0c46d6: /* original 65b3, guest PC 0x0c0c46d6 */
if(!s->budget--) { s->failed_pc=0x0c0c46d6u; return 0; }
r[5]=r[11];
goto P_0c0c46d8;
P_0c0c46d8: /* original b31c, guest PC 0x0c0c46d8 */
if(!s->budget--) { s->failed_pc=0x0c0c46d8u; return 0; }
target=code_base|0x0c0c4d14u; r[16]=code_base|0x0c0c46dcu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c46dcu) { target=s->pc; goto dispatch; }
goto P_0c0c46dc;
P_0c0c46da: /* original 64c3, guest PC 0x0c0c46da */
if(!s->budget--) { s->failed_pc=0x0c0c46dau; return 0; }
r[4]=r[12];
goto P_0c0c46dc;
P_0c0c46dc: /* original a00e, guest PC 0x0c0c46dc */
if(!s->budget--) { s->failed_pc=0x0c0c46dcu; return 0; }
goto P_0c0c46fc;
P_0c0c46de: /* original 0009, guest PC 0x0c0c46de */
if(!s->budget--) { s->failed_pc=0x0c0c46deu; return 0; }
goto P_0c0c46e0;
P_0c0c46e0: /* original 5cea, guest PC 0x0c0c46e0 */
if(!s->budget--) { s->failed_pc=0x0c0c46e0u; return 0; }
r[12]=read(ram,r[14]+40,4);
goto P_0c0c46e2;
P_0c0c46e2: /* original e036, guest PC 0x0c0c46e2 */
if(!s->budget--) { s->failed_pc=0x0c0c46e2u; return 0; }
r[0]=0x00000036u;
goto P_0c0c46e4;
P_0c0c46e4: /* original 03cc, guest PC 0x0c0c46e4 */
if(!s->budget--) { s->failed_pc=0x0c0c46e4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c46e6;
P_0c0c46e6: /* original 2338, guest PC 0x0c0c46e6 */
if(!s->budget--) { s->failed_pc=0x0c0c46e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c46e8;
P_0c0c46e8: /* original 8b21, guest PC 0x0c0c46e8 */
if(!s->budget--) { s->failed_pc=0x0c0c46e8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c472e; }
goto P_0c0c46ea;
P_0c0c46ea: /* original 50d8, guest PC 0x0c0c46ea */
if(!s->budget--) { s->failed_pc=0x0c0c46eau; return 0; }
r[0]=read(ram,r[13]+32,4);
goto P_0c0c46ec;
P_0c0c46ec: /* original 88ff, guest PC 0x0c0c46ec */
if(!s->budget--) { s->failed_pc=0x0c0c46ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c46ee;
P_0c0c46ee: /* original 8b1e, guest PC 0x0c0c46ee */
if(!s->budget--) { s->failed_pc=0x0c0c46eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c472e; }
goto P_0c0c46f0;
P_0c0c46f0: /* original 50da, guest PC 0x0c0c46f0 */
if(!s->budget--) { s->failed_pc=0x0c0c46f0u; return 0; }
r[0]=read(ram,r[13]+40,4);
goto P_0c0c46f2;
P_0c0c46f2: /* original 88ff, guest PC 0x0c0c46f2 */
if(!s->budget--) { s->failed_pc=0x0c0c46f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c46f4;
P_0c0c46f4: /* original 8b1b, guest PC 0x0c0c46f4 */
if(!s->budget--) { s->failed_pc=0x0c0c46f4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c472e; }
goto P_0c0c46f6;
P_0c0c46f6: /* original 65b3, guest PC 0x0c0c46f6 */
if(!s->budget--) { s->failed_pc=0x0c0c46f6u; return 0; }
r[5]=r[11];
goto P_0c0c46f8;
P_0c0c46f8: /* original b358, guest PC 0x0c0c46f8 */
if(!s->budget--) { s->failed_pc=0x0c0c46f8u; return 0; }
target=code_base|0x0c0c4dacu; r[16]=code_base|0x0c0c46fcu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c46fcu) { target=s->pc; goto dispatch; }
goto P_0c0c46fc;
P_0c0c46fa: /* original 64c3, guest PC 0x0c0c46fa */
if(!s->budget--) { s->failed_pc=0x0c0c46fau; return 0; }
r[4]=r[12];
goto P_0c0c46fc;
P_0c0c46fc: /* original d21b, guest PC 0x0c0c46fc */
if(!s->budget--) { s->failed_pc=0x0c0c46fcu; return 0; }
r[2]=read(ram,0x0c0c476cu,4);
goto P_0c0c46fe;
P_0c0c46fe: /* original 9427, guest PC 0x0c0c46fe */
if(!s->budget--) { s->failed_pc=0x0c0c46feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4750u,2);
goto P_0c0c4700;
P_0c0c4700: /* original 420b, guest PC 0x0c0c4700 */
if(!s->budget--) { s->failed_pc=0x0c0c4700u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c4704u;
r[4]+=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4704u) { target=s->pc; goto dispatch; }
goto P_0c0c4704;
P_0c0c4702: /* original 34bc, guest PC 0x0c0c4702 */
if(!s->budget--) { s->failed_pc=0x0c0c4702u; return 0; }
r[4]+=r[11];
goto P_0c0c4704;
P_0c0c4704: /* original 84b4, guest PC 0x0c0c4704 */
if(!s->budget--) { s->failed_pc=0x0c0c4704u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+4,1);
goto P_0c0c4706;
P_0c0c4706: /* original 2008, guest PC 0x0c0c4706 */
if(!s->budget--) { s->failed_pc=0x0c0c4706u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c4708;
P_0c0c4708: /* original 8f02, guest PC 0x0c0c4708 */
if(!s->budget--) { s->failed_pc=0x0c0c4708u; return 0; }
cond=r[17]&1u;
r[4]=r[11];
if(!cond) { goto P_0c0c4710; }
goto P_0c0c470c;
P_0c0c470a: /* original 64b3, guest PC 0x0c0c470a */
if(!s->budget--) { s->failed_pc=0x0c0c470au; return 0; }
r[4]=r[11];
goto P_0c0c470c;
P_0c0c470c: /* original a001, guest PC 0x0c0c470c */
if(!s->budget--) { s->failed_pc=0x0c0c470cu; return 0; }
r[5]=read(ram,r[14]+20,4);
goto P_0c0c4712;
P_0c0c470e: /* original 55e5, guest PC 0x0c0c470e */
if(!s->budget--) { s->failed_pc=0x0c0c470eu; return 0; }
r[5]=read(ram,r[14]+20,4);
goto P_0c0c4710;
P_0c0c4710: /* original 55e4, guest PC 0x0c0c4710 */
if(!s->budget--) { s->failed_pc=0x0c0c4710u; return 0; }
r[5]=read(ram,r[14]+16,4);
goto P_0c0c4712;
P_0c0c4712: /* original d317, guest PC 0x0c0c4712 */
if(!s->budget--) { s->failed_pc=0x0c0c4712u; return 0; }
r[3]=read(ram,0x0c0c4770u,4);
goto P_0c0c4714;
P_0c0c4714: /* original 430b, guest PC 0x0c0c4714 */
if(!s->budget--) { s->failed_pc=0x0c0c4714u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4718u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4718u) { target=s->pc; goto dispatch; }
goto P_0c0c4718;
P_0c0c4716: /* original 0009, guest PC 0x0c0c4716 */
if(!s->budget--) { s->failed_pc=0x0c0c4716u; return 0; }
goto P_0c0c4718;
P_0c0c4718: /* original e061, guest PC 0x0c0c4718 */
if(!s->budget--) { s->failed_pc=0x0c0c4718u; return 0; }
r[0]=0x00000061u;
goto P_0c0c471a;
P_0c0c471a: /* original 00bc, guest PC 0x0c0c471a */
if(!s->budget--) { s->failed_pc=0x0c0c471au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c471c;
P_0c0c471c: /* original 600c, guest PC 0x0c0c471c */
if(!s->budget--) { s->failed_pc=0x0c0c471cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0c471e;
P_0c0c471e: /* original 8801, guest PC 0x0c0c471e */
if(!s->budget--) { s->failed_pc=0x0c0c471eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c4720;
P_0c0c4720: /* original 8902, guest PC 0x0c0c4720 */
if(!s->budget--) { s->failed_pc=0x0c0c4720u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4728; }
goto P_0c0c4722;
P_0c0c4722: /* original d214, guest PC 0x0c0c4722 */
if(!s->budget--) { s->failed_pc=0x0c0c4722u; return 0; }
r[2]=read(ram,0x0c0c4774u,4);
goto P_0c0c4724;
P_0c0c4724: /* original 420b, guest PC 0x0c0c4724 */
if(!s->budget--) { s->failed_pc=0x0c0c4724u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c4728u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4728u) { target=s->pc; goto dispatch; }
goto P_0c0c4728;
P_0c0c4726: /* original 64b3, guest PC 0x0c0c4726 */
if(!s->budget--) { s->failed_pc=0x0c0c4726u; return 0; }
r[4]=r[11];
goto P_0c0c4728;
P_0c0c4728: /* original d313, guest PC 0x0c0c4728 */
if(!s->budget--) { s->failed_pc=0x0c0c4728u; return 0; }
r[3]=read(ram,0x0c0c4778u,4);
goto P_0c0c472a;
P_0c0c472a: /* original 430b, guest PC 0x0c0c472a */
if(!s->budget--) { s->failed_pc=0x0c0c472au; return 0; }
target=r[3];
r[16]=code_base|0x0c0c472eu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c472eu) { target=s->pc; goto dispatch; }
goto P_0c0c472e;
P_0c0c472c: /* original 64b3, guest PC 0x0c0c472c */
if(!s->budget--) { s->failed_pc=0x0c0c472cu; return 0; }
r[4]=r[11];
goto P_0c0c472e;
P_0c0c472e: /* original e06c, guest PC 0x0c0c472e */
if(!s->budget--) { s->failed_pc=0x0c0c472eu; return 0; }
r[0]=0x0000006cu;
goto P_0c0c4730;
P_0c0c4730: /* original 00ce, guest PC 0x0c0c4730 */
if(!s->budget--) { s->failed_pc=0x0c0c4730u; return 0; }
r[0]=read(ram,r[12]+r[0],4);
goto P_0c0c4732;
P_0c0c4732: /* original 8806, guest PC 0x0c0c4732 */
if(!s->budget--) { s->failed_pc=0x0c0c4732u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0c4734;
P_0c0c4734: /* original 8f24, guest PC 0x0c0c4734 */
if(!s->budget--) { s->failed_pc=0x0c0c4734u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[14]+16,4);
if(!cond) { goto P_0c0c4780; }
goto P_0c0c4738;
P_0c0c4736: /* original 54e4, guest PC 0x0c0c4736 */
if(!s->budget--) { s->failed_pc=0x0c0c4736u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c0c4738;
P_0c0c4738: /* original 900b, guest PC 0x0c0c4738 */
if(!s->budget--) { s->failed_pc=0x0c0c4738u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4752u,2);
goto P_0c0c473a;
P_0c0c473a: /* original d310, guest PC 0x0c0c473a */
if(!s->budget--) { s->failed_pc=0x0c0c473au; return 0; }
r[3]=read(ram,0x0c0c477cu,4);
goto P_0c0c473c;
P_0c0c473c: /* original 05de, guest PC 0x0c0c473c */
if(!s->budget--) { s->failed_pc=0x0c0c473cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0c473e;
P_0c0c473e: /* original 2538, guest PC 0x0c0c473e */
if(!s->budget--) { s->failed_pc=0x0c0c473eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0c4740;
P_0c0c4740: /* original 8903, guest PC 0x0c0c4740 */
if(!s->budget--) { s->failed_pc=0x0c0c4740u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c474a; }
goto P_0c0c4742;
P_0c0c4742: /* original e060, guest PC 0x0c0c4742 */
if(!s->budget--) { s->failed_pc=0x0c0c4742u; return 0; }
r[0]=0x00000060u;
goto P_0c0c4744;
P_0c0c4744: /* original e116, guest PC 0x0c0c4744 */
if(!s->budget--) { s->failed_pc=0x0c0c4744u; return 0; }
r[1]=0x00000016u;
goto P_0c0c4746;
P_0c0c4746: /* original a01f, guest PC 0x0c0c4746 */
if(!s->budget--) { s->failed_pc=0x0c0c4746u; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c0c4788;
P_0c0c4748: /* original 0414, guest PC 0x0c0c4748 */
if(!s->budget--) { s->failed_pc=0x0c0c4748u; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c0c474a;
P_0c0c474a: /* original e060, guest PC 0x0c0c474a */
if(!s->budget--) { s->failed_pc=0x0c0c474au; return 0; }
r[0]=0x00000060u;
goto P_0c0c474c;
P_0c0c474c: /* original a01c, guest PC 0x0c0c474c */
if(!s->budget--) { s->failed_pc=0x0c0c474cu; return 0; }
write(ram,r[4]+r[0],r[9],1);
goto P_0c0c4788;
P_0c0c474e: /* original 0494, guest PC 0x0c0c474e */
if(!s->budget--) { s->failed_pc=0x0c0c474eu; return 0; }
write(ram,r[4]+r[0],r[9],1);
if(!vf3_matrix_family(0x0c0c4750u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c4750u; return 0; } return 1;
P_0c0c4780: /* original e032, guest PC 0x0c0c4780 */
if(!s->budget--) { s->failed_pc=0x0c0c4780u; return 0; }
r[0]=0x00000032u;
goto P_0c0c4782;
P_0c0c4782: /* original 02cc, guest PC 0x0c0c4782 */
if(!s->budget--) { s->failed_pc=0x0c0c4782u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c4784;
P_0c0c4784: /* original e060, guest PC 0x0c0c4784 */
if(!s->budget--) { s->failed_pc=0x0c0c4784u; return 0; }
r[0]=0x00000060u;
goto P_0c0c4786;
P_0c0c4786: /* original 0424, guest PC 0x0c0c4786 */
if(!s->budget--) { s->failed_pc=0x0c0c4786u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0c4788;
P_0c0c4788: /* original d332, guest PC 0x0c0c4788 */
if(!s->budget--) { s->failed_pc=0x0c0c4788u; return 0; }
r[3]=read(ram,0x0c0c4854u,4);
goto P_0c0c478a;
P_0c0c478a: /* original e502, guest PC 0x0c0c478a */
if(!s->budget--) { s->failed_pc=0x0c0c478au; return 0; }
r[5]=0x00000002u;
goto P_0c0c478c;
P_0c0c478c: /* original 430b, guest PC 0x0c0c478c */
if(!s->budget--) { s->failed_pc=0x0c0c478cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4790u;
r[4]=0x0000000fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4790u) { target=s->pc; goto dispatch; }
goto P_0c0c4790;
P_0c0c478e: /* original e40f, guest PC 0x0c0c478e */
if(!s->budget--) { s->failed_pc=0x0c0c478eu; return 0; }
r[4]=0x0000000fu;
goto P_0c0c4790;
P_0c0c4790: /* original e20f, guest PC 0x0c0c4790 */
if(!s->budget--) { s->failed_pc=0x0c0c4790u; return 0; }
r[2]=0x0000000fu;
goto P_0c0c4792;
P_0c0c4792: /* original e500, guest PC 0x0c0c4792 */
if(!s->budget--) { s->failed_pc=0x0c0c4792u; return 0; }
r[5]=0x00000000u;
goto P_0c0c4794;
P_0c0c4794: /* original 2f26, guest PC 0x0c0c4794 */
if(!s->budget--) { s->failed_pc=0x0c0c4794u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4796;
P_0c0c4796: /* original d330, guest PC 0x0c0c4796 */
if(!s->budget--) { s->failed_pc=0x0c0c4796u; return 0; }
r[3]=read(ram,0x0c0c4858u,4);
goto P_0c0c4798;
P_0c0c4798: /* original e614, guest PC 0x0c0c4798 */
if(!s->budget--) { s->failed_pc=0x0c0c4798u; return 0; }
r[6]=0x00000014u;
goto P_0c0c479a;
P_0c0c479a: /* original 6723, guest PC 0x0c0c479a */
if(!s->budget--) { s->failed_pc=0x0c0c479au; return 0; }
r[7]=r[2];
goto P_0c0c479c;
P_0c0c479c: /* original 430b, guest PC 0x0c0c479c */
if(!s->budget--) { s->failed_pc=0x0c0c479cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c47a0u;
r[4]=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c47a0u) { target=s->pc; goto dispatch; }
goto P_0c0c47a0;
P_0c0c479e: /* original e40a, guest PC 0x0c0c479e */
if(!s->budget--) { s->failed_pc=0x0c0c479eu; return 0; }
r[4]=0x0000000au;
goto P_0c0c47a0;
P_0c0c47a0: /* original 7f04, guest PC 0x0c0c47a0 */
if(!s->budget--) { s->failed_pc=0x0c0c47a0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c47a2;
P_0c0c47a2: /* original 50f7, guest PC 0x0c0c47a2 */
if(!s->budget--) { s->failed_pc=0x0c0c47a2u; return 0; }
r[0]=read(ram,r[15]+28,4);
goto P_0c0c47a4;
P_0c0c47a4: /* original c80e, guest PC 0x0c0c47a4 */
if(!s->budget--) { s->failed_pc=0x0c0c47a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&14u)==0)!=0);
goto P_0c0c47a6;
P_0c0c47a6: /* original 8b01, guest PC 0x0c0c47a6 */
if(!s->budget--) { s->failed_pc=0x0c0c47a6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c47ac; }
goto P_0c0c47a8;
P_0c0c47a8: /* original a1a8, guest PC 0x0c0c47a8 */
if(!s->budget--) { s->failed_pc=0x0c0c47a8u; return 0; }
goto P_0c0c4afc;
P_0c0c47aa: /* original 0009, guest PC 0x0c0c47aa */
if(!s->budget--) { s->failed_pc=0x0c0c47aau; return 0; }
goto P_0c0c47ac;
P_0c0c47ac: /* original d32b, guest PC 0x0c0c47ac */
if(!s->budget--) { s->failed_pc=0x0c0c47acu; return 0; }
r[3]=read(ram,0x0c0c485cu,4);
goto P_0c0c47ae;
P_0c0c47ae: /* original 430b, guest PC 0x0c0c47ae */
if(!s->budget--) { s->failed_pc=0x0c0c47aeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c47b2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c47b2u) { target=s->pc; goto dispatch; }
goto P_0c0c47b2;
P_0c0c47b0: /* original 0009, guest PC 0x0c0c47b0 */
if(!s->budget--) { s->failed_pc=0x0c0c47b0u; return 0; }
goto P_0c0c47b2;
P_0c0c47b2: /* original d22b, guest PC 0x0c0c47b2 */
if(!s->budget--) { s->failed_pc=0x0c0c47b2u; return 0; }
r[2]=read(ram,0x0c0c4860u,4);
goto P_0c0c47b4;
P_0c0c47b4: /* original 420b, guest PC 0x0c0c47b4 */
if(!s->budget--) { s->failed_pc=0x0c0c47b4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c47b8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c47b8u) { target=s->pc; goto dispatch; }
goto P_0c0c47b8;
P_0c0c47b6: /* original 0009, guest PC 0x0c0c47b6 */
if(!s->budget--) { s->failed_pc=0x0c0c47b6u; return 0; }
goto P_0c0c47b8;
P_0c0c47b8: /* original d32a, guest PC 0x0c0c47b8 */
if(!s->budget--) { s->failed_pc=0x0c0c47b8u; return 0; }
r[3]=read(ram,0x0c0c4864u,4);
goto P_0c0c47ba;
P_0c0c47ba: /* original 9447, guest PC 0x0c0c47ba */
if(!s->budget--) { s->failed_pc=0x0c0c47bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c484cu,2);
goto P_0c0c47bc;
P_0c0c47bc: /* original 430b, guest PC 0x0c0c47bc */
if(!s->budget--) { s->failed_pc=0x0c0c47bcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c47c0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c47c0u) { target=s->pc; goto dispatch; }
goto P_0c0c47c0;
P_0c0c47be: /* original 0009, guest PC 0x0c0c47be */
if(!s->budget--) { s->failed_pc=0x0c0c47beu; return 0; }
goto P_0c0c47c0;
P_0c0c47c0: /* original e06c, guest PC 0x0c0c47c0 */
if(!s->budget--) { s->failed_pc=0x0c0c47c0u; return 0; }
r[0]=0x0000006cu;
goto P_0c0c47c2;
P_0c0c47c2: /* original 00ae, guest PC 0x0c0c47c2 */
if(!s->budget--) { s->failed_pc=0x0c0c47c2u; return 0; }
r[0]=read(ram,r[10]+r[0],4);
goto P_0c0c47c4;
P_0c0c47c4: /* original 8806, guest PC 0x0c0c47c4 */
if(!s->budget--) { s->failed_pc=0x0c0c47c4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0c47c6;
P_0c0c47c6: /* original 8f0e, guest PC 0x0c0c47c6 */
if(!s->budget--) { s->failed_pc=0x0c0c47c6u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[14]+20,4);
if(!cond) { goto P_0c0c47e6; }
goto P_0c0c47ca;
P_0c0c47c8: /* original 54e5, guest PC 0x0c0c47c8 */
if(!s->budget--) { s->failed_pc=0x0c0c47c8u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c0c47ca;
P_0c0c47ca: /* original 9040, guest PC 0x0c0c47ca */
if(!s->budget--) { s->failed_pc=0x0c0c47cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c484eu,2);
goto P_0c0c47cc;
P_0c0c47cc: /* original d326, guest PC 0x0c0c47cc */
if(!s->budget--) { s->failed_pc=0x0c0c47ccu; return 0; }
r[3]=read(ram,0x0c0c4868u,4);
goto P_0c0c47ce;
P_0c0c47ce: /* original 05de, guest PC 0x0c0c47ce */
if(!s->budget--) { s->failed_pc=0x0c0c47ceu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0c47d0;
P_0c0c47d0: /* original 2538, guest PC 0x0c0c47d0 */
if(!s->budget--) { s->failed_pc=0x0c0c47d0u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0c47d2;
P_0c0c47d2: /* original 8902, guest PC 0x0c0c47d2 */
if(!s->budget--) { s->failed_pc=0x0c0c47d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c47da; }
goto P_0c0c47d4;
P_0c0c47d4: /* original e060, guest PC 0x0c0c47d4 */
if(!s->budget--) { s->failed_pc=0x0c0c47d4u; return 0; }
r[0]=0x00000060u;
goto P_0c0c47d6;
P_0c0c47d6: /* original a003, guest PC 0x0c0c47d6 */
if(!s->budget--) { s->failed_pc=0x0c0c47d6u; return 0; }
write(ram,r[4]+r[0],r[9],1);
goto P_0c0c47e0;
P_0c0c47d8: /* original 0494, guest PC 0x0c0c47d8 */
if(!s->budget--) { s->failed_pc=0x0c0c47d8u; return 0; }
write(ram,r[4]+r[0],r[9],1);
goto P_0c0c47da;
P_0c0c47da: /* original e060, guest PC 0x0c0c47da */
if(!s->budget--) { s->failed_pc=0x0c0c47dau; return 0; }
r[0]=0x00000060u;
goto P_0c0c47dc;
P_0c0c47dc: /* original e116, guest PC 0x0c0c47dc */
if(!s->budget--) { s->failed_pc=0x0c0c47dcu; return 0; }
r[1]=0x00000016u;
goto P_0c0c47de;
P_0c0c47de: /* original 0414, guest PC 0x0c0c47de */
if(!s->budget--) { s->failed_pc=0x0c0c47deu; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c0c47e0;
P_0c0c47e0: /* original e061, guest PC 0x0c0c47e0 */
if(!s->budget--) { s->failed_pc=0x0c0c47e0u; return 0; }
r[0]=0x00000061u;
goto P_0c0c47e2;
P_0c0c47e2: /* original a004, guest PC 0x0c0c47e2 */
if(!s->budget--) { s->failed_pc=0x0c0c47e2u; return 0; }
write(ram,r[4]+r[0],r[9],1);
goto P_0c0c47ee;
P_0c0c47e4: /* original 0494, guest PC 0x0c0c47e4 */
if(!s->budget--) { s->failed_pc=0x0c0c47e4u; return 0; }
write(ram,r[4]+r[0],r[9],1);
goto P_0c0c47e6;
P_0c0c47e6: /* original e032, guest PC 0x0c0c47e6 */
if(!s->budget--) { s->failed_pc=0x0c0c47e6u; return 0; }
r[0]=0x00000032u;
goto P_0c0c47e8;
P_0c0c47e8: /* original 02ac, guest PC 0x0c0c47e8 */
if(!s->budget--) { s->failed_pc=0x0c0c47e8u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c0c47ea;
P_0c0c47ea: /* original e060, guest PC 0x0c0c47ea */
if(!s->budget--) { s->failed_pc=0x0c0c47eau; return 0; }
r[0]=0x00000060u;
goto P_0c0c47ec;
P_0c0c47ec: /* original 0424, guest PC 0x0c0c47ec */
if(!s->budget--) { s->failed_pc=0x0c0c47ecu; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0c47ee;
P_0c0c47ee: /* original e058, guest PC 0x0c0c47ee */
if(!s->budget--) { s->failed_pc=0x0c0c47eeu; return 0; }
r[0]=0x00000058u;
goto P_0c0c47f0;
P_0c0c47f0: /* original f4a6, guest PC 0x0c0c47f0 */
if(!s->budget--) { s->failed_pc=0x0c0c47f0u; return 0; }
vf3_matrix_load(s,ram,4,r[10]+r[0]);
goto P_0c0c47f2;
P_0c0c47f2: /* original e03a, guest PC 0x0c0c47f2 */
if(!s->budget--) { s->failed_pc=0x0c0c47f2u; return 0; }
r[0]=0x0000003au;
goto P_0c0c47f4;
P_0c0c47f4: /* original 05ac, guest PC 0x0c0c47f4 */
if(!s->budget--) { s->failed_pc=0x0c0c47f4u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c0c47f6;
P_0c0c47f6: /* original 2558, guest PC 0x0c0c47f6 */
if(!s->budget--) { s->failed_pc=0x0c0c47f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0c47f8;
P_0c0c47f8: /* original 8908, guest PC 0x0c0c47f8 */
if(!s->budget--) { s->failed_pc=0x0c0c47f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c480c; }
goto P_0c0c47fa;
P_0c0c47fa: /* original e033, guest PC 0x0c0c47fa */
if(!s->budget--) { s->failed_pc=0x0c0c47fau; return 0; }
r[0]=0x00000033u;
goto P_0c0c47fc;
P_0c0c47fc: /* original 9328, guest PC 0x0c0c47fc */
if(!s->budget--) { s->failed_pc=0x0c0c47fcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4850u,2);
goto P_0c0c47fe;
P_0c0c47fe: /* original 05ac, guest PC 0x0c0c47fe */
if(!s->budget--) { s->failed_pc=0x0c0c47feu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c0c4800;
P_0c0c4800: /* original 655c, guest PC 0x0c0c4800 */
if(!s->budget--) { s->failed_pc=0x0c0c4800u; return 0; }
r[5]=r[5]&255u;
goto P_0c0c4802;
P_0c0c4802: /* original 3530, guest PC 0x0c0c4802 */
if(!s->budget--) { s->failed_pc=0x0c0c4802u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[3])!=0);
goto P_0c0c4804;
P_0c0c4804: /* original 8d02, guest PC 0x0c0c4804 */
if(!s->budget--) { s->failed_pc=0x0c0c4804u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,14);
if(cond) { goto P_0c0c480c; }
goto P_0c0c4808;
P_0c0c4806: /* original f4ec, guest PC 0x0c0c4806 */
if(!s->budget--) { s->failed_pc=0x0c0c4806u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0c4808;
P_0c0c4808: /* original e060, guest PC 0x0c0c4808 */
if(!s->budget--) { s->failed_pc=0x0c0c4808u; return 0; }
r[0]=0x00000060u;
goto P_0c0c480a;
P_0c0c480a: /* original 0454, guest PC 0x0c0c480a */
if(!s->budget--) { s->failed_pc=0x0c0c480au; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c480c;
P_0c0c480c: /* original 54f1, guest PC 0x0c0c480c */
if(!s->budget--) { s->failed_pc=0x0c0c480cu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c480e;
P_0c0c480e: /* original c717, guest PC 0x0c0c480e */
if(!s->budget--) { s->failed_pc=0x0c0c480eu; return 0; }
r[0]=code_base|0x000c486cu;
goto P_0c0c4810;
P_0c0c4810: /* original e304, guest PC 0x0c0c4810 */
if(!s->budget--) { s->failed_pc=0x0c0c4810u; return 0; }
r[3]=0x00000004u;
goto P_0c0c4812;
P_0c0c4812: /* original f508, guest PC 0x0c0c4812 */
if(!s->budget--) { s->failed_pc=0x0c0c4812u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c4814;
P_0c0c4814: /* original 5442, guest PC 0x0c0c4814 */
if(!s->budget--) { s->failed_pc=0x0c0c4814u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c0c4816;
P_0c0c4816: /* original 2438, guest PC 0x0c0c4816 */
if(!s->budget--) { s->failed_pc=0x0c0c4816u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c4818;
P_0c0c4818: /* original 8904, guest PC 0x0c0c4818 */
if(!s->budget--) { s->failed_pc=0x0c0c4818u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4824; }
goto P_0c0c481a;
P_0c0c481a: /* original 52f7, guest PC 0x0c0c481a */
if(!s->budget--) { s->failed_pc=0x0c0c481au; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c0c481c;
P_0c0c481c: /* original 2288, guest PC 0x0c0c481c */
if(!s->budget--) { s->failed_pc=0x0c0c481cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[8])==0)!=0);
goto P_0c0c481e;
P_0c0c481e: /* original 8901, guest PC 0x0c0c481e */
if(!s->budget--) { s->failed_pc=0x0c0c481eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4824; }
goto P_0c0c4820;
P_0c0c4820: /* original c713, guest PC 0x0c0c4820 */
if(!s->budget--) { s->failed_pc=0x0c0c4820u; return 0; }
r[0]=code_base|0x000c4870u;
goto P_0c0c4822;
P_0c0c4822: /* original f508, guest PC 0x0c0c4822 */
if(!s->budget--) { s->failed_pc=0x0c0c4822u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c4824;
P_0c0c4824: /* original f451, guest PC 0x0c0c4824 */
if(!s->budget--) { s->failed_pc=0x0c0c4824u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c0c4826;
P_0c0c4826: /* original f38d, guest PC 0x0c0c4826 */
if(!s->budget--) { s->failed_pc=0x0c0c4826u; return 0; }
fr[3]=0;
goto P_0c0c4828;
P_0c0c4828: /* original f345, guest PC 0x0c0c4828 */
if(!s->budget--) { s->failed_pc=0x0c0c4828u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0c482a;
P_0c0c482a: /* original 8f01, guest PC 0x0c0c482a */
if(!s->budget--) { s->failed_pc=0x0c0c482au; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,15);
if(!cond) { goto P_0c0c4830; }
goto P_0c0c482e;
P_0c0c482c: /* original f5fc, guest PC 0x0c0c482c */
if(!s->budget--) { s->failed_pc=0x0c0c482cu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c482e;
P_0c0c482e: /* original f45c, guest PC 0x0c0c482e */
if(!s->budget--) { s->failed_pc=0x0c0c482eu; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0c4830;
P_0c0c4830: /* original e058, guest PC 0x0c0c4830 */
if(!s->budget--) { s->failed_pc=0x0c0c4830u; return 0; }
r[0]=0x00000058u;
goto P_0c0c4832;
P_0c0c4832: /* original fa47, guest PC 0x0c0c4832 */
if(!s->budget--) { s->failed_pc=0x0c0c4832u; return 0; }
vf3_matrix_store(s,ram,4,r[10]+r[0]);
goto P_0c0c4834;
P_0c0c4834: /* original e044, guest PC 0x0c0c4834 */
if(!s->budget--) { s->failed_pc=0x0c0c4834u; return 0; }
r[0]=0x00000044u;
goto P_0c0c4836;
P_0c0c4836: /* original 5ceb, guest PC 0x0c0c4836 */
if(!s->budget--) { s->failed_pc=0x0c0c4836u; return 0; }
r[12]=read(ram,r[14]+44,4);
goto P_0c0c4838;
P_0c0c4838: /* original e12a, guest PC 0x0c0c4838 */
if(!s->budget--) { s->failed_pc=0x0c0c4838u; return 0; }
r[1]=0x0000002au;
goto P_0c0c483a;
P_0c0c483a: /* original 04cd, guest PC 0x0c0c483a */
if(!s->budget--) { s->failed_pc=0x0c0c483au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0c483c;
P_0c0c483c: /* original 50f1, guest PC 0x0c0c483c */
if(!s->budget--) { s->failed_pc=0x0c0c483cu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0c483e;
P_0c0c483e: /* original 001c, guest PC 0x0c0c483e */
if(!s->budget--) { s->failed_pc=0x0c0c483eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0c4840;
P_0c0c4840: /* original 600c, guest PC 0x0c0c4840 */
if(!s->budget--) { s->failed_pc=0x0c0c4840u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c4842;
P_0c0c4842: /* original 8802, guest PC 0x0c0c4842 */
if(!s->budget--) { s->failed_pc=0x0c0c4842u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c4844;
P_0c0c4844: /* original 8b16, guest PC 0x0c0c4844 */
if(!s->budget--) { s->failed_pc=0x0c0c4844u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4874; }
goto P_0c0c4846;
P_0c0c4846: /* original 9404, guest PC 0x0c0c4846 */
if(!s->budget--) { s->failed_pc=0x0c0c4846u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4852u,2);
goto P_0c0c4848;
P_0c0c4848: /* original a01b, guest PC 0x0c0c4848 */
if(!s->budget--) { s->failed_pc=0x0c0c4848u; return 0; }
goto P_0c0c4882;
P_0c0c484a: /* original 0009, guest PC 0x0c0c484a */
if(!s->budget--) { s->failed_pc=0x0c0c484au; return 0; }
if(!vf3_matrix_family(0x0c0c484cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c484cu; return 0; } return 1;
P_0c0c4874: /* original 65c2, guest PC 0x0c0c4874 */
if(!s->budget--) { s->failed_pc=0x0c0c4874u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0c4876;
P_0c0c4876: /* original 2588, guest PC 0x0c0c4876 */
if(!s->budget--) { s->failed_pc=0x0c0c4876u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[8])==0)!=0);
goto P_0c0c4878;
P_0c0c4878: /* original 8b03, guest PC 0x0c0c4878 */
if(!s->budget--) { s->failed_pc=0x0c0c4878u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4882; }
goto P_0c0c487a;
P_0c0c487a: /* original 9297, guest PC 0x0c0c487a */
if(!s->budget--) { s->failed_pc=0x0c0c487au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c49acu,2);
goto P_0c0c487c;
P_0c0c487c: /* original e044, guest PC 0x0c0c487c */
if(!s->budget--) { s->failed_pc=0x0c0c487cu; return 0; }
r[0]=0x00000044u;
goto P_0c0c487e;
P_0c0c487e: /* original 342c, guest PC 0x0c0c487e */
if(!s->budget--) { s->failed_pc=0x0c0c487eu; return 0; }
r[4]+=r[2];
goto P_0c0c4880;
P_0c0c4880: /* original 0c45, guest PC 0x0c0c4880 */
if(!s->budget--) { s->failed_pc=0x0c0c4880u; return 0; }
write(ram,r[12]+r[0],r[4],2);
goto P_0c0c4882;
P_0c0c4882: /* original 55e5, guest PC 0x0c0c4882 */
if(!s->budget--) { s->failed_pc=0x0c0c4882u; return 0; }
r[5]=read(ram,r[14]+20,4);
goto P_0c0c4884;
P_0c0c4884: /* original e061, guest PC 0x0c0c4884 */
if(!s->budget--) { s->failed_pc=0x0c0c4884u; return 0; }
r[0]=0x00000061u;
goto P_0c0c4886;
P_0c0c4886: /* original 9792, guest PC 0x0c0c4886 */
if(!s->budget--) { s->failed_pc=0x0c0c4886u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c49aeu,2);
goto P_0c0c4888;
P_0c0c4888: /* original 055c, guest PC 0x0c0c4888 */
if(!s->budget--) { s->failed_pc=0x0c0c4888u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c488a;
P_0c0c488a: /* original d049, guest PC 0x0c0c488a */
if(!s->budget--) { s->failed_pc=0x0c0c488au; return 0; }
r[0]=read(ram,0x0c0c49b0u,4);
goto P_0c0c488c;
P_0c0c488c: /* original 655c, guest PC 0x0c0c488c */
if(!s->budget--) { s->failed_pc=0x0c0c488cu; return 0; }
r[5]=r[5]&255u;
goto P_0c0c488e;
P_0c0c488e: /* original 4500, guest PC 0x0c0c488e */
if(!s->budget--) { s->failed_pc=0x0c0c488eu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0c4890;
P_0c0c4890: /* original 7501, guest PC 0x0c0c4890 */
if(!s->budget--) { s->failed_pc=0x0c0c4890u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c4892;
P_0c0c4892: /* original 4500, guest PC 0x0c0c4892 */
if(!s->budget--) { s->failed_pc=0x0c0c4892u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0c4894;
P_0c0c4894: /* original 055d, guest PC 0x0c0c4894 */
if(!s->budget--) { s->failed_pc=0x0c0c4894u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0c4896;
P_0c0c4896: /* original 345c, guest PC 0x0c0c4896 */
if(!s->budget--) { s->failed_pc=0x0c0c4896u; return 0; }
r[4]+=r[5];
goto P_0c0c4898;
P_0c0c4898: /* original d546, guest PC 0x0c0c4898 */
if(!s->budget--) { s->failed_pc=0x0c0c4898u; return 0; }
r[5]=read(ram,0x0c0c49b4u,4);
goto P_0c0c489a;
P_0c0c489a: /* original 644d, guest PC 0x0c0c489a */
if(!s->budget--) { s->failed_pc=0x0c0c489au; return 0; }
r[4]=r[4]&65535u;
goto P_0c0c489c;
P_0c0c489c: /* original 2f56, guest PC 0x0c0c489c */
if(!s->budget--) { s->failed_pc=0x0c0c489cu; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c489e;
P_0c0c489e: /* original 2f46, guest PC 0x0c0c489e */
if(!s->budget--) { s->failed_pc=0x0c0c489eu; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c48a0;
P_0c0c48a0: /* original d245, guest PC 0x0c0c48a0 */
if(!s->budget--) { s->failed_pc=0x0c0c48a0u; return 0; }
r[2]=read(ram,0x0c0c49b8u,4);
goto P_0c0c48a2;
P_0c0c48a2: /* original 65f3, guest PC 0x0c0c48a2 */
if(!s->budget--) { s->failed_pc=0x0c0c48a2u; return 0; }
r[5]=r[15];
goto P_0c0c48a4;
P_0c0c48a4: /* original 66f3, guest PC 0x0c0c48a4 */
if(!s->budget--) { s->failed_pc=0x0c0c48a4u; return 0; }
r[6]=r[15];
goto P_0c0c48a6;
P_0c0c48a6: /* original 64f3, guest PC 0x0c0c48a6 */
if(!s->budget--) { s->failed_pc=0x0c0c48a6u; return 0; }
r[4]=r[15];
goto P_0c0c48a8;
P_0c0c48a8: /* original 7618, guest PC 0x0c0c48a8 */
if(!s->budget--) { s->failed_pc=0x0c0c48a8u; return 0; }
r[6]+=0x00000018u;
goto P_0c0c48aa;
P_0c0c48aa: /* original 7514, guest PC 0x0c0c48aa */
if(!s->budget--) { s->failed_pc=0x0c0c48aau; return 0; }
r[5]+=0x00000014u;
goto P_0c0c48ac;
P_0c0c48ac: /* original 420b, guest PC 0x0c0c48ac */
if(!s->budget--) { s->failed_pc=0x0c0c48acu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c48b0u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c48b0u) { target=s->pc; goto dispatch; }
goto P_0c0c48b0;
P_0c0c48ae: /* original 7410, guest PC 0x0c0c48ae */
if(!s->budget--) { s->failed_pc=0x0c0c48aeu; return 0; }
r[4]+=0x00000010u;
goto P_0c0c48b0;
P_0c0c48b0: /* original e010, guest PC 0x0c0c48b0 */
if(!s->budget--) { s->failed_pc=0x0c0c48b0u; return 0; }
r[0]=0x00000010u;
goto P_0c0c48b2;
P_0c0c48b2: /* original d342, guest PC 0x0c0c48b2 */
if(!s->budget--) { s->failed_pc=0x0c0c48b2u; return 0; }
r[3]=read(ram,0x0c0c49bcu,4);
goto P_0c0c48b4;
P_0c0c48b4: /* original 7f08, guest PC 0x0c0c48b4 */
if(!s->budget--) { s->failed_pc=0x0c0c48b4u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c48b6;
P_0c0c48b6: /* original f6f6, guest PC 0x0c0c48b6 */
if(!s->budget--) { s->failed_pc=0x0c0c48b6u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0c48b8;
P_0c0c48b8: /* original e00c, guest PC 0x0c0c48b8 */
if(!s->budget--) { s->failed_pc=0x0c0c48b8u; return 0; }
r[0]=0x0000000cu;
goto P_0c0c48ba;
P_0c0c48ba: /* original f5f6, guest PC 0x0c0c48ba */
if(!s->budget--) { s->failed_pc=0x0c0c48bau; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c48bc;
P_0c0c48bc: /* original e008, guest PC 0x0c0c48bc */
if(!s->budget--) { s->failed_pc=0x0c0c48bcu; return 0; }
r[0]=0x00000008u;
goto P_0c0c48be;
P_0c0c48be: /* original 430b, guest PC 0x0c0c48be */
if(!s->budget--) { s->failed_pc=0x0c0c48beu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c48c2u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c48c2u) { target=s->pc; goto dispatch; }
goto P_0c0c48c2;
P_0c0c48c0: /* original f4f6, guest PC 0x0c0c48c0 */
if(!s->budget--) { s->failed_pc=0x0c0c48c0u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c48c2;
P_0c0c48c2: /* original 54e5, guest PC 0x0c0c48c2 */
if(!s->budget--) { s->failed_pc=0x0c0c48c2u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c0c48c4;
P_0c0c48c4: /* original e060, guest PC 0x0c0c48c4 */
if(!s->budget--) { s->failed_pc=0x0c0c48c4u; return 0; }
r[0]=0x00000060u;
goto P_0c0c48c6;
P_0c0c48c6: /* original 044c, guest PC 0x0c0c48c6 */
if(!s->budget--) { s->failed_pc=0x0c0c48c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c48c8;
P_0c0c48c8: /* original d03d, guest PC 0x0c0c48c8 */
if(!s->budget--) { s->failed_pc=0x0c0c48c8u; return 0; }
r[0]=read(ram,0x0c0c49c0u,4);
goto P_0c0c48ca;
P_0c0c48ca: /* original 644c, guest PC 0x0c0c48ca */
if(!s->budget--) { s->failed_pc=0x0c0c48cau; return 0; }
r[4]=r[4]&255u;
goto P_0c0c48cc;
P_0c0c48cc: /* original 4400, guest PC 0x0c0c48cc */
if(!s->budget--) { s->failed_pc=0x0c0c48ccu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c48ce;
P_0c0c48ce: /* original 7401, guest PC 0x0c0c48ce */
if(!s->budget--) { s->failed_pc=0x0c0c48ceu; return 0; }
r[4]+=0x00000001u;
goto P_0c0c48d0;
P_0c0c48d0: /* original 4400, guest PC 0x0c0c48d0 */
if(!s->budget--) { s->failed_pc=0x0c0c48d0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c48d2;
P_0c0c48d2: /* original 034d, guest PC 0x0c0c48d2 */
if(!s->budget--) { s->failed_pc=0x0c0c48d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c48d4;
P_0c0c48d4: /* original e061, guest PC 0x0c0c48d4 */
if(!s->budget--) { s->failed_pc=0x0c0c48d4u; return 0; }
r[0]=0x00000061u;
goto P_0c0c48d6;
P_0c0c48d6: /* original 2f31, guest PC 0x0c0c48d6 */
if(!s->budget--) { s->failed_pc=0x0c0c48d6u; return 0; }
write(ram,r[15],r[3],2);
goto P_0c0c48d8;
P_0c0c48d8: /* original 54e5, guest PC 0x0c0c48d8 */
if(!s->budget--) { s->failed_pc=0x0c0c48d8u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c0c48da;
P_0c0c48da: /* original d23a, guest PC 0x0c0c48da */
if(!s->budget--) { s->failed_pc=0x0c0c48dau; return 0; }
r[2]=read(ram,0x0c0c49c4u,4);
goto P_0c0c48dc;
P_0c0c48dc: /* original 054c, guest PC 0x0c0c48dc */
if(!s->budget--) { s->failed_pc=0x0c0c48dcu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c48de;
P_0c0c48de: /* original e020, guest PC 0x0c0c48de */
if(!s->budget--) { s->failed_pc=0x0c0c48deu; return 0; }
r[0]=0x00000020u;
goto P_0c0c48e0;
P_0c0c48e0: /* original 645c, guest PC 0x0c0c48e0 */
if(!s->budget--) { s->failed_pc=0x0c0c48e0u; return 0; }
r[4]=r[5]&255u;
goto P_0c0c48e2;
P_0c0c48e2: /* original 740d, guest PC 0x0c0c48e2 */
if(!s->budget--) { s->failed_pc=0x0c0c48e2u; return 0; }
r[4]+=0x0000000du;
goto P_0c0c48e4;
P_0c0c48e4: /* original 6343, guest PC 0x0c0c48e4 */
if(!s->budget--) { s->failed_pc=0x0c0c48e4u; return 0; }
r[3]=r[4];
goto P_0c0c48e6;
P_0c0c48e6: /* original 4408, guest PC 0x0c0c48e6 */
if(!s->budget--) { s->failed_pc=0x0c0c48e6u; return 0; }
r[4]<<=2;
goto P_0c0c48e8;
P_0c0c48e8: /* original 343c, guest PC 0x0c0c48e8 */
if(!s->budget--) { s->failed_pc=0x0c0c48e8u; return 0; }
r[4]+=r[3];
goto P_0c0c48ea;
P_0c0c48ea: /* original 4408, guest PC 0x0c0c48ea */
if(!s->budget--) { s->failed_pc=0x0c0c48eau; return 0; }
r[4]<<=2;
goto P_0c0c48ec;
P_0c0c48ec: /* original 644f, guest PC 0x0c0c48ec */
if(!s->budget--) { s->failed_pc=0x0c0c48ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0c48ee;
P_0c0c48ee: /* original 342c, guest PC 0x0c0c48ee */
if(!s->budget--) { s->failed_pc=0x0c0c48eeu; return 0; }
r[4]+=r[2];
goto P_0c0c48f0;
P_0c0c48f0: /* original f348, guest PC 0x0c0c48f0 */
if(!s->budget--) { s->failed_pc=0x0c0c48f0u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c0c48f2;
P_0c0c48f2: /* original ff37, guest PC 0x0c0c48f2 */
if(!s->budget--) { s->failed_pc=0x0c0c48f2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c48f4;
P_0c0c48f4: /* original e004, guest PC 0x0c0c48f4 */
if(!s->budget--) { s->failed_pc=0x0c0c48f4u; return 0; }
r[0]=0x00000004u;
goto P_0c0c48f6;
P_0c0c48f6: /* original f346, guest PC 0x0c0c48f6 */
if(!s->budget--) { s->failed_pc=0x0c0c48f6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0c48f8;
P_0c0c48f8: /* original e024, guest PC 0x0c0c48f8 */
if(!s->budget--) { s->failed_pc=0x0c0c48f8u; return 0; }
r[0]=0x00000024u;
goto P_0c0c48fa;
P_0c0c48fa: /* original ff37, guest PC 0x0c0c48fa */
if(!s->budget--) { s->failed_pc=0x0c0c48fau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c48fc;
P_0c0c48fc: /* original e008, guest PC 0x0c0c48fc */
if(!s->budget--) { s->failed_pc=0x0c0c48fcu; return 0; }
r[0]=0x00000008u;
goto P_0c0c48fe;
P_0c0c48fe: /* original f346, guest PC 0x0c0c48fe */
if(!s->budget--) { s->failed_pc=0x0c0c48feu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0c4900;
P_0c0c4900: /* original e028, guest PC 0x0c0c4900 */
if(!s->budget--) { s->failed_pc=0x0c0c4900u; return 0; }
r[0]=0x00000028u;
goto P_0c0c4902;
P_0c0c4902: /* original ff37, guest PC 0x0c0c4902 */
if(!s->budget--) { s->failed_pc=0x0c0c4902u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c4904;
P_0c0c4904: /* original e1f4, guest PC 0x0c0c4904 */
if(!s->budget--) { s->failed_pc=0x0c0c4904u; return 0; }
r[1]=0xfffffff4u;
goto P_0c0c4906;
P_0c0c4906: /* original 8546, guest PC 0x0c0c4906 */
if(!s->budget--) { s->failed_pc=0x0c0c4906u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+12,2);
goto P_0c0c4908;
P_0c0c4908: /* original 81fa, guest PC 0x0c0c4908 */
if(!s->budget--) { s->failed_pc=0x0c0c4908u; return 0; }
write(ram,r[15]+20,r[0],2);
goto P_0c0c490a;
P_0c0c490a: /* original 8547, guest PC 0x0c0c490a */
if(!s->budget--) { s->failed_pc=0x0c0c490au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+14,2);
goto P_0c0c490c;
P_0c0c490c: /* original 81f2, guest PC 0x0c0c490c */
if(!s->budget--) { s->failed_pc=0x0c0c490cu; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c0c490e;
P_0c0c490e: /* original 8548, guest PC 0x0c0c490e */
if(!s->budget--) { s->failed_pc=0x0c0c490eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+16,2);
goto P_0c0c4910;
P_0c0c4910: /* original 6a03, guest PC 0x0c0c4910 */
if(!s->budget--) { s->failed_pc=0x0c0c4910u; return 0; }
r[10]=r[0];
goto P_0c0c4912;
P_0c0c4912: /* original e04c, guest PC 0x0c0c4912 */
if(!s->budget--) { s->failed_pc=0x0c0c4912u; return 0; }
r[0]=0x0000004cu;
goto P_0c0c4914;
P_0c0c4914: /* original 06cd, guest PC 0x0c0c4914 */
if(!s->budget--) { s->failed_pc=0x0c0c4914u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0c4916;
P_0c0c4916: /* original e04a, guest PC 0x0c0c4916 */
if(!s->budget--) { s->failed_pc=0x0c0c4916u; return 0; }
r[0]=0x0000004au;
goto P_0c0c4918;
P_0c0c4918: /* original 05cd, guest PC 0x0c0c4918 */
if(!s->budget--) { s->failed_pc=0x0c0c4918u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0c491a;
P_0c0c491a: /* original e04e, guest PC 0x0c0c491a */
if(!s->budget--) { s->failed_pc=0x0c0c491au; return 0; }
r[0]=0x0000004eu;
goto P_0c0c491c;
P_0c0c491c: /* original 04cd, guest PC 0x0c0c491c */
if(!s->budget--) { s->failed_pc=0x0c0c491cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+r[0],2);
goto P_0c0c491e;
P_0c0c491e: /* original 74f9, guest PC 0x0c0c491e */
if(!s->budget--) { s->failed_pc=0x0c0c491eu; return 0; }
r[4]+=0xfffffff9u;
goto P_0c0c4920;
P_0c0c4920: /* original 634f, guest PC 0x0c0c4920 */
if(!s->budget--) { s->failed_pc=0x0c0c4920u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0c4922;
P_0c0c4922: /* original 0c45, guest PC 0x0c0c4922 */
if(!s->budget--) { s->failed_pc=0x0c0c4922u; return 0; }
write(ram,r[12]+r[0],r[4],2);
goto P_0c0c4924;
P_0c0c4924: /* original 431c, guest PC 0x0c0c4924 */
if(!s->budget--) { s->failed_pc=0x0c0c4924u; return 0; }
r[3]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[3]>>((-r[1])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[1]&31u);
goto P_0c0c4926;
P_0c0c4926: /* original 6433, guest PC 0x0c0c4926 */
if(!s->budget--) { s->failed_pc=0x0c0c4926u; return 0; }
r[4]=r[3];
goto P_0c0c4928;
P_0c0c4928: /* original 63af, guest PC 0x0c0c4928 */
if(!s->budget--) { s->failed_pc=0x0c0c4928u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[10];
goto P_0c0c492a;
P_0c0c492a: /* original 2338, guest PC 0x0c0c492a */
if(!s->budget--) { s->failed_pc=0x0c0c492au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c492c;
P_0c0c492c: /* original 8d01, guest PC 0x0c0c492c */
if(!s->budget--) { s->failed_pc=0x0c0c492cu; return 0; }
cond=r[17]&1u;
r[4]+=r[6];
if(cond) { goto P_0c0c4932; }
goto P_0c0c4930;
P_0c0c492e: /* original 346c, guest PC 0x0c0c492e */
if(!s->budget--) { s->failed_pc=0x0c0c492eu; return 0; }
r[4]+=r[6];
goto P_0c0c4930;
P_0c0c4930: /* original 7501, guest PC 0x0c0c4930 */
if(!s->budget--) { s->failed_pc=0x0c0c4930u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c4932;
P_0c0c4932: /* original 66c2, guest PC 0x0c0c4932 */
if(!s->budget--) { s->failed_pc=0x0c0c4932u; return 0; }
tmp=read(ram,r[12],4);
r[6]=tmp;
goto P_0c0c4934;
P_0c0c4934: /* original 2688, guest PC 0x0c0c4934 */
if(!s->budget--) { s->failed_pc=0x0c0c4934u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[8])==0)!=0);
goto P_0c0c4936;
P_0c0c4936: /* original 8b08, guest PC 0x0c0c4936 */
if(!s->budget--) { s->failed_pc=0x0c0c4936u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c494a; }
goto P_0c0c4938;
P_0c0c4938: /* original d124, guest PC 0x0c0c4938 */
if(!s->budget--) { s->failed_pc=0x0c0c4938u; return 0; }
r[1]=read(ram,0x0c0c49ccu,4);
goto P_0c0c493a;
P_0c0c493a: /* original d323, guest PC 0x0c0c493a */
if(!s->budget--) { s->failed_pc=0x0c0c493au; return 0; }
r[3]=read(ram,0x0c0c49c8u,4);
goto P_0c0c493c;
P_0c0c493c: /* original 6212, guest PC 0x0c0c493c */
if(!s->budget--) { s->failed_pc=0x0c0c493cu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0c493e;
P_0c0c493e: /* original 2238, guest PC 0x0c0c493e */
if(!s->budget--) { s->failed_pc=0x0c0c493eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c4940;
P_0c0c4940: /* original 8b03, guest PC 0x0c0c4940 */
if(!s->budget--) { s->failed_pc=0x0c0c4940u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c494a; }
goto P_0c0c4942;
P_0c0c4942: /* original e04c, guest PC 0x0c0c4942 */
if(!s->budget--) { s->failed_pc=0x0c0c4942u; return 0; }
r[0]=0x0000004cu;
goto P_0c0c4944;
P_0c0c4944: /* original 0c45, guest PC 0x0c0c4944 */
if(!s->budget--) { s->failed_pc=0x0c0c4944u; return 0; }
write(ram,r[12]+r[0],r[4],2);
goto P_0c0c4946;
P_0c0c4946: /* original e04a, guest PC 0x0c0c4946 */
if(!s->budget--) { s->failed_pc=0x0c0c4946u; return 0; }
r[0]=0x0000004au;
goto P_0c0c4948;
P_0c0c4948: /* original 0c55, guest PC 0x0c0c4948 */
if(!s->budget--) { s->failed_pc=0x0c0c4948u; return 0; }
write(ram,r[12]+r[0],r[5],2);
goto P_0c0c494a;
P_0c0c494a: /* original 85f2, guest PC 0x0c0c494a */
if(!s->budget--) { s->failed_pc=0x0c0c494au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c0c494c;
P_0c0c494c: /* original 6353, guest PC 0x0c0c494c */
if(!s->budget--) { s->failed_pc=0x0c0c494cu; return 0; }
r[3]=r[5];
goto P_0c0c494e;
P_0c0c494e: /* original 33a8, guest PC 0x0c0c494e */
if(!s->budget--) { s->failed_pc=0x0c0c494eu; return 0; }
r[3]-=r[10];
goto P_0c0c4950;
P_0c0c4950: /* original 304c, guest PC 0x0c0c4950 */
if(!s->budget--) { s->failed_pc=0x0c0c4950u; return 0; }
r[0]+=r[4];
goto P_0c0c4952;
P_0c0c4952: /* original 6a33, guest PC 0x0c0c4952 */
if(!s->budget--) { s->failed_pc=0x0c0c4952u; return 0; }
r[10]=r[3];
goto P_0c0c4954;
P_0c0c4954: /* original 81f2, guest PC 0x0c0c4954 */
if(!s->budget--) { s->failed_pc=0x0c0c4954u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c0c4956;
P_0c0c4956: /* original d21e, guest PC 0x0c0c4956 */
if(!s->budget--) { s->failed_pc=0x0c0c4956u; return 0; }
r[2]=read(ram,0x0c0c49d0u,4);
goto P_0c0c4958;
P_0c0c4958: /* original 420b, guest PC 0x0c0c4958 */
if(!s->budget--) { s->failed_pc=0x0c0c4958u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c495cu;
r[11]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c495cu) { target=s->pc; goto dispatch; }
goto P_0c0c495c;
P_0c0c495a: /* original 5be5, guest PC 0x0c0c495a */
if(!s->budget--) { s->failed_pc=0x0c0c495au; return 0; }
r[11]=read(ram,r[14]+20,4);
goto P_0c0c495c;
P_0c0c495c: /* original e028, guest PC 0x0c0c495c */
if(!s->budget--) { s->failed_pc=0x0c0c495cu; return 0; }
r[0]=0x00000028u;
goto P_0c0c495e;
P_0c0c495e: /* original d31d, guest PC 0x0c0c495e */
if(!s->budget--) { s->failed_pc=0x0c0c495eu; return 0; }
r[3]=read(ram,0x0c0c49d4u,4);
goto P_0c0c4960;
P_0c0c4960: /* original f6f6, guest PC 0x0c0c4960 */
if(!s->budget--) { s->failed_pc=0x0c0c4960u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0c4962;
P_0c0c4962: /* original e024, guest PC 0x0c0c4962 */
if(!s->budget--) { s->failed_pc=0x0c0c4962u; return 0; }
r[0]=0x00000024u;
goto P_0c0c4964;
P_0c0c4964: /* original f5f6, guest PC 0x0c0c4964 */
if(!s->budget--) { s->failed_pc=0x0c0c4964u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c4966;
P_0c0c4966: /* original e020, guest PC 0x0c0c4966 */
if(!s->budget--) { s->failed_pc=0x0c0c4966u; return 0; }
r[0]=0x00000020u;
goto P_0c0c4968;
P_0c0c4968: /* original 430b, guest PC 0x0c0c4968 */
if(!s->budget--) { s->failed_pc=0x0c0c4968u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c496cu;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c496cu) { target=s->pc; goto dispatch; }
goto P_0c0c496c;
P_0c0c496a: /* original f4f6, guest PC 0x0c0c496a */
if(!s->budget--) { s->failed_pc=0x0c0c496au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c496c;
P_0c0c496c: /* original d31a, guest PC 0x0c0c496c */
if(!s->budget--) { s->failed_pc=0x0c0c496cu; return 0; }
r[3]=read(ram,0x0c0c49d8u,4);
goto P_0c0c496e;
P_0c0c496e: /* original 85fa, guest PC 0x0c0c496e */
if(!s->budget--) { s->failed_pc=0x0c0c496eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+20,2);
goto P_0c0c4970;
P_0c0c4970: /* original 430b, guest PC 0x0c0c4970 */
if(!s->budget--) { s->failed_pc=0x0c0c4970u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4974u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4974u) { target=s->pc; goto dispatch; }
goto P_0c0c4974;
P_0c0c4972: /* original 6403, guest PC 0x0c0c4972 */
if(!s->budget--) { s->failed_pc=0x0c0c4972u; return 0; }
r[4]=r[0];
goto P_0c0c4974;
P_0c0c4974: /* original d219, guest PC 0x0c0c4974 */
if(!s->budget--) { s->failed_pc=0x0c0c4974u; return 0; }
r[2]=read(ram,0x0c0c49dcu,4);
goto P_0c0c4976;
P_0c0c4976: /* original 420b, guest PC 0x0c0c4976 */
if(!s->budget--) { s->failed_pc=0x0c0c4976u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c497au;
r[4]=(uint32_t)(int32_t)(int16_t)r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c497au) { target=s->pc; goto dispatch; }
goto P_0c0c497a;
P_0c0c4978: /* original 64af, guest PC 0x0c0c4978 */
if(!s->budget--) { s->failed_pc=0x0c0c4978u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[10];
goto P_0c0c497a;
P_0c0c497a: /* original d319, guest PC 0x0c0c497a */
if(!s->budget--) { s->failed_pc=0x0c0c497au; return 0; }
r[3]=read(ram,0x0c0c49e0u,4);
goto P_0c0c497c;
P_0c0c497c: /* original 85f2, guest PC 0x0c0c497c */
if(!s->budget--) { s->failed_pc=0x0c0c497cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c0c497e;
P_0c0c497e: /* original 430b, guest PC 0x0c0c497e */
if(!s->budget--) { s->failed_pc=0x0c0c497eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4982u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4982u) { target=s->pc; goto dispatch; }
goto P_0c0c4982;
P_0c0c4980: /* original 6403, guest PC 0x0c0c4980 */
if(!s->budget--) { s->failed_pc=0x0c0c4980u; return 0; }
r[4]=r[0];
goto P_0c0c4982;
P_0c0c4982: /* original 64f1, guest PC 0x0c0c4982 */
if(!s->budget--) { s->failed_pc=0x0c0c4982u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c0c4984;
P_0c0c4984: /* original 6043, guest PC 0x0c0c4984 */
if(!s->budget--) { s->failed_pc=0x0c0c4984u; return 0; }
r[0]=r[4];
goto P_0c0c4986;
P_0c0c4986: /* original 88ff, guest PC 0x0c0c4986 */
if(!s->budget--) { s->failed_pc=0x0c0c4986u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c4988;
P_0c0c4988: /* original 890d, guest PC 0x0c0c4988 */
if(!s->budget--) { s->failed_pc=0x0c0c4988u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c49a6; }
goto P_0c0c498a;
P_0c0c498a: /* original 5ceb, guest PC 0x0c0c498a */
if(!s->budget--) { s->failed_pc=0x0c0c498au; return 0; }
r[12]=read(ram,r[14]+44,4);
goto P_0c0c498c;
P_0c0c498c: /* original e036, guest PC 0x0c0c498c */
if(!s->budget--) { s->failed_pc=0x0c0c498cu; return 0; }
r[0]=0x00000036u;
goto P_0c0c498e;
P_0c0c498e: /* original 03cc, guest PC 0x0c0c498e */
if(!s->budget--) { s->failed_pc=0x0c0c498eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c4990;
P_0c0c4990: /* original 2338, guest PC 0x0c0c4990 */
if(!s->budget--) { s->failed_pc=0x0c0c4990u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c4992;
P_0c0c4992: /* original 8b08, guest PC 0x0c0c4992 */
if(!s->budget--) { s->failed_pc=0x0c0c4992u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c49a6; }
goto P_0c0c4994;
P_0c0c4994: /* original 50d9, guest PC 0x0c0c4994 */
if(!s->budget--) { s->failed_pc=0x0c0c4994u; return 0; }
r[0]=read(ram,r[13]+36,4);
goto P_0c0c4996;
P_0c0c4996: /* original 88ff, guest PC 0x0c0c4996 */
if(!s->budget--) { s->failed_pc=0x0c0c4996u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c4998;
P_0c0c4998: /* original 8b05, guest PC 0x0c0c4998 */
if(!s->budget--) { s->failed_pc=0x0c0c4998u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c49a6; }
goto P_0c0c499a;
P_0c0c499a: /* original 50db, guest PC 0x0c0c499a */
if(!s->budget--) { s->failed_pc=0x0c0c499au; return 0; }
r[0]=read(ram,r[13]+44,4);
goto P_0c0c499c;
P_0c0c499c: /* original 88ff, guest PC 0x0c0c499c */
if(!s->budget--) { s->failed_pc=0x0c0c499cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c499e;
P_0c0c499e: /* original 8b02, guest PC 0x0c0c499e */
if(!s->budget--) { s->failed_pc=0x0c0c499eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c49a6; }
goto P_0c0c49a0;
P_0c0c49a0: /* original d310, guest PC 0x0c0c49a0 */
if(!s->budget--) { s->failed_pc=0x0c0c49a0u; return 0; }
r[3]=read(ram,0x0c0c49e4u,4);
goto P_0c0c49a2;
P_0c0c49a2: /* original 430b, guest PC 0x0c0c49a2 */
if(!s->budget--) { s->failed_pc=0x0c0c49a2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c49a6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c49a6u) { target=s->pc; goto dispatch; }
goto P_0c0c49a6;
P_0c0c49a4: /* original 0009, guest PC 0x0c0c49a4 */
if(!s->budget--) { s->failed_pc=0x0c0c49a4u; return 0; }
goto P_0c0c49a6;
P_0c0c49a6: /* original 5ae8, guest PC 0x0c0c49a6 */
if(!s->budget--) { s->failed_pc=0x0c0c49a6u; return 0; }
r[10]=read(ram,r[14]+32,4);
goto P_0c0c49a8;
P_0c0c49a8: /* original a01e, guest PC 0x0c0c49a8 */
if(!s->budget--) { s->failed_pc=0x0c0c49a8u; return 0; }
r[4]=r[10];
goto P_0c0c49e8;
P_0c0c49aa: /* original 64a3, guest PC 0x0c0c49aa */
if(!s->budget--) { s->failed_pc=0x0c0c49aau; return 0; }
r[4]=r[10];
if(!vf3_matrix_family(0x0c0c49acu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c49acu; return 0; } return 1;
P_0c0c49e8: /* original d237, guest PC 0x0c0c49e8 */
if(!s->budget--) { s->failed_pc=0x0c0c49e8u; return 0; }
r[2]=read(ram,0x0c0c4ac8u,4);
goto P_0c0c49ea;
P_0c0c49ea: /* original 420b, guest PC 0x0c0c49ea */
if(!s->budget--) { s->failed_pc=0x0c0c49eau; return 0; }
target=r[2];
r[16]=code_base|0x0c0c49eeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c49eeu) { target=s->pc; goto dispatch; }
goto P_0c0c49ee;
P_0c0c49ec: /* original 0009, guest PC 0x0c0c49ec */
if(!s->budget--) { s->failed_pc=0x0c0c49ecu; return 0; }
goto P_0c0c49ee;
P_0c0c49ee: /* original c737, guest PC 0x0c0c49ee */
if(!s->budget--) { s->failed_pc=0x0c0c49eeu; return 0; }
r[0]=code_base|0x000c4accu;
goto P_0c0c49f0;
P_0c0c49f0: /* original f508, guest PC 0x0c0c49f0 */
if(!s->budget--) { s->failed_pc=0x0c0c49f0u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c49f2;
P_0c0c49f2: /* original c737, guest PC 0x0c0c49f2 */
if(!s->budget--) { s->failed_pc=0x0c0c49f2u; return 0; }
r[0]=code_base|0x000c4ad0u;
goto P_0c0c49f4;
P_0c0c49f4: /* original f408, guest PC 0x0c0c49f4 */
if(!s->budget--) { s->failed_pc=0x0c0c49f4u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c49f6;
P_0c0c49f6: /* original c737, guest PC 0x0c0c49f6 */
if(!s->budget--) { s->failed_pc=0x0c0c49f6u; return 0; }
r[0]=code_base|0x000c4ad4u;
goto P_0c0c49f8;
P_0c0c49f8: /* original f608, guest PC 0x0c0c49f8 */
if(!s->budget--) { s->failed_pc=0x0c0c49f8u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0c49fa;
P_0c0c49fa: /* original e010, guest PC 0x0c0c49fa */
if(!s->budget--) { s->failed_pc=0x0c0c49fau; return 0; }
r[0]=0x00000010u;
goto P_0c0c49fc;
P_0c0c49fc: /* original fa57, guest PC 0x0c0c49fc */
if(!s->budget--) { s->failed_pc=0x0c0c49fcu; return 0; }
vf3_matrix_store(s,ram,5,r[10]+r[0]);
goto P_0c0c49fe;
P_0c0c49fe: /* original e014, guest PC 0x0c0c49fe */
if(!s->budget--) { s->failed_pc=0x0c0c49feu; return 0; }
r[0]=0x00000014u;
goto P_0c0c4a00;
P_0c0c4a00: /* original fa47, guest PC 0x0c0c4a00 */
if(!s->budget--) { s->failed_pc=0x0c0c4a00u; return 0; }
vf3_matrix_store(s,ram,4,r[10]+r[0]);
goto P_0c0c4a02;
P_0c0c4a02: /* original e302, guest PC 0x0c0c4a02 */
if(!s->budget--) { s->failed_pc=0x0c0c4a02u; return 0; }
r[3]=0x00000002u;
goto P_0c0c4a04;
P_0c0c4a04: /* original e018, guest PC 0x0c0c4a04 */
if(!s->budget--) { s->failed_pc=0x0c0c4a04u; return 0; }
r[0]=0x00000018u;
goto P_0c0c4a06;
P_0c0c4a06: /* original fa67, guest PC 0x0c0c4a06 */
if(!s->budget--) { s->failed_pc=0x0c0c4a06u; return 0; }
vf3_matrix_store(s,ram,6,r[10]+r[0]);
goto P_0c0c4a08;
P_0c0c4a08: /* original 64c2, guest PC 0x0c0c4a08 */
if(!s->budget--) { s->failed_pc=0x0c0c4a08u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c0c4a0a;
P_0c0c4a0a: /* original 2438, guest PC 0x0c0c4a0a */
if(!s->budget--) { s->failed_pc=0x0c0c4a0au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c4a0c;
P_0c0c4a0c: /* original 8922, guest PC 0x0c0c4a0c */
if(!s->budget--) { s->failed_pc=0x0c0c4a0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4a54; }
goto P_0c0c4a0e;
P_0c0c4a0e: /* original e064, guest PC 0x0c0c4a0e */
if(!s->budget--) { s->failed_pc=0x0c0c4a0eu; return 0; }
r[0]=0x00000064u;
goto P_0c0c4a10;
P_0c0c4a10: /* original 00cc, guest PC 0x0c0c4a10 */
if(!s->budget--) { s->failed_pc=0x0c0c4a10u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c4a12;
P_0c0c4a12: /* original 8801, guest PC 0x0c0c4a12 */
if(!s->budget--) { s->failed_pc=0x0c0c4a12u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c4a14;
P_0c0c4a14: /* original 8d0e, guest PC 0x0c0c4a14 */
if(!s->budget--) { s->failed_pc=0x0c0c4a14u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0c4a34; }
goto P_0c0c4a18;
P_0c0c4a16: /* original 6403, guest PC 0x0c0c4a16 */
if(!s->budget--) { s->failed_pc=0x0c0c4a16u; return 0; }
r[4]=r[0];
goto P_0c0c4a18;
P_0c0c4a18: /* original e061, guest PC 0x0c0c4a18 */
if(!s->budget--) { s->failed_pc=0x0c0c4a18u; return 0; }
r[0]=0x00000061u;
goto P_0c0c4a1a;
P_0c0c4a1a: /* original d32f, guest PC 0x0c0c4a1a */
if(!s->budget--) { s->failed_pc=0x0c0c4a1au; return 0; }
r[3]=read(ram,0x0c0c4ad8u,4);
goto P_0c0c4a1c;
P_0c0c4a1c: /* original 04bc, guest PC 0x0c0c4a1c */
if(!s->budget--) { s->failed_pc=0x0c0c4a1cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c4a1e;
P_0c0c4a1e: /* original 7037, guest PC 0x0c0c4a1e */
if(!s->budget--) { s->failed_pc=0x0c0c4a1eu; return 0; }
r[0]+=0x00000037u;
goto P_0c0c4a20;
P_0c0c4a20: /* original 05de, guest PC 0x0c0c4a20 */
if(!s->budget--) { s->failed_pc=0x0c0c4a20u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0c4a22;
P_0c0c4a22: /* original 644c, guest PC 0x0c0c4a22 */
if(!s->budget--) { s->failed_pc=0x0c0c4a22u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c4a24;
P_0c0c4a24: /* original 644b, guest PC 0x0c0c4a24 */
if(!s->budget--) { s->failed_pc=0x0c0c4a24u; return 0; }
r[4]=0u-r[4];
goto P_0c0c4a26;
P_0c0c4a26: /* original 434d, guest PC 0x0c0c4a26 */
if(!s->budget--) { s->failed_pc=0x0c0c4a26u; return 0; }
r[3]=(r[4]&0x80000000u)?((r[4]&31u)?r[3]>>((-r[4])&31u):0):r[3]<<(r[4]&31u);
goto P_0c0c4a28;
P_0c0c4a28: /* original 2358, guest PC 0x0c0c4a28 */
if(!s->budget--) { s->failed_pc=0x0c0c4a28u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0c4a2a;
P_0c0c4a2a: /* original 8903, guest PC 0x0c0c4a2a */
if(!s->budget--) { s->failed_pc=0x0c0c4a2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4a34; }
goto P_0c0c4a2c;
P_0c0c4a2c: /* original c72b, guest PC 0x0c0c4a2c */
if(!s->budget--) { s->failed_pc=0x0c0c4a2cu; return 0; }
r[0]=code_base|0x000c4adcu;
goto P_0c0c4a2e;
P_0c0c4a2e: /* original f308, guest PC 0x0c0c4a2e */
if(!s->budget--) { s->failed_pc=0x0c0c4a2eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c4a30;
P_0c0c4a30: /* original e058, guest PC 0x0c0c4a30 */
if(!s->budget--) { s->failed_pc=0x0c0c4a30u; return 0; }
r[0]=0x00000058u;
goto P_0c0c4a32;
P_0c0c4a32: /* original fc37, guest PC 0x0c0c4a32 */
if(!s->budget--) { s->failed_pc=0x0c0c4a32u; return 0; }
vf3_matrix_store(s,ram,3,r[12]+r[0]);
goto P_0c0c4a34;
P_0c0c4a34: /* original 5ceb, guest PC 0x0c0c4a34 */
if(!s->budget--) { s->failed_pc=0x0c0c4a34u; return 0; }
r[12]=read(ram,r[14]+44,4);
goto P_0c0c4a36;
P_0c0c4a36: /* original e036, guest PC 0x0c0c4a36 */
if(!s->budget--) { s->failed_pc=0x0c0c4a36u; return 0; }
r[0]=0x00000036u;
goto P_0c0c4a38;
P_0c0c4a38: /* original 03cc, guest PC 0x0c0c4a38 */
if(!s->budget--) { s->failed_pc=0x0c0c4a38u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c4a3a;
P_0c0c4a3a: /* original 2338, guest PC 0x0c0c4a3a */
if(!s->budget--) { s->failed_pc=0x0c0c4a3au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c4a3c;
P_0c0c4a3c: /* original 8b31, guest PC 0x0c0c4a3c */
if(!s->budget--) { s->failed_pc=0x0c0c4a3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4aa2; }
goto P_0c0c4a3e;
P_0c0c4a3e: /* original 50d9, guest PC 0x0c0c4a3e */
if(!s->budget--) { s->failed_pc=0x0c0c4a3eu; return 0; }
r[0]=read(ram,r[13]+36,4);
goto P_0c0c4a40;
P_0c0c4a40: /* original 88ff, guest PC 0x0c0c4a40 */
if(!s->budget--) { s->failed_pc=0x0c0c4a40u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c4a42;
P_0c0c4a42: /* original 8b2e, guest PC 0x0c0c4a42 */
if(!s->budget--) { s->failed_pc=0x0c0c4a42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4aa2; }
goto P_0c0c4a44;
P_0c0c4a44: /* original 50db, guest PC 0x0c0c4a44 */
if(!s->budget--) { s->failed_pc=0x0c0c4a44u; return 0; }
r[0]=read(ram,r[13]+44,4);
goto P_0c0c4a46;
P_0c0c4a46: /* original 88ff, guest PC 0x0c0c4a46 */
if(!s->budget--) { s->failed_pc=0x0c0c4a46u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c4a48;
P_0c0c4a48: /* original 8b2b, guest PC 0x0c0c4a48 */
if(!s->budget--) { s->failed_pc=0x0c0c4a48u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4aa2; }
goto P_0c0c4a4a;
P_0c0c4a4a: /* original 65b3, guest PC 0x0c0c4a4a */
if(!s->budget--) { s->failed_pc=0x0c0c4a4au; return 0; }
r[5]=r[11];
goto P_0c0c4a4c;
P_0c0c4a4c: /* original b162, guest PC 0x0c0c4a4c */
if(!s->budget--) { s->failed_pc=0x0c0c4a4cu; return 0; }
target=code_base|0x0c0c4d14u; r[16]=code_base|0x0c0c4a50u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4a50u) { target=s->pc; goto dispatch; }
goto P_0c0c4a50;
P_0c0c4a4e: /* original 64c3, guest PC 0x0c0c4a4e */
if(!s->budget--) { s->failed_pc=0x0c0c4a4eu; return 0; }
r[4]=r[12];
goto P_0c0c4a50;
P_0c0c4a50: /* original a00e, guest PC 0x0c0c4a50 */
if(!s->budget--) { s->failed_pc=0x0c0c4a50u; return 0; }
goto P_0c0c4a70;
P_0c0c4a52: /* original 0009, guest PC 0x0c0c4a52 */
if(!s->budget--) { s->failed_pc=0x0c0c4a52u; return 0; }
goto P_0c0c4a54;
P_0c0c4a54: /* original 5ceb, guest PC 0x0c0c4a54 */
if(!s->budget--) { s->failed_pc=0x0c0c4a54u; return 0; }
r[12]=read(ram,r[14]+44,4);
goto P_0c0c4a56;
P_0c0c4a56: /* original e036, guest PC 0x0c0c4a56 */
if(!s->budget--) { s->failed_pc=0x0c0c4a56u; return 0; }
r[0]=0x00000036u;
goto P_0c0c4a58;
P_0c0c4a58: /* original 03cc, guest PC 0x0c0c4a58 */
if(!s->budget--) { s->failed_pc=0x0c0c4a58u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c4a5a;
P_0c0c4a5a: /* original 2338, guest PC 0x0c0c4a5a */
if(!s->budget--) { s->failed_pc=0x0c0c4a5au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c4a5c;
P_0c0c4a5c: /* original 8b21, guest PC 0x0c0c4a5c */
if(!s->budget--) { s->failed_pc=0x0c0c4a5cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4aa2; }
goto P_0c0c4a5e;
P_0c0c4a5e: /* original 50d9, guest PC 0x0c0c4a5e */
if(!s->budget--) { s->failed_pc=0x0c0c4a5eu; return 0; }
r[0]=read(ram,r[13]+36,4);
goto P_0c0c4a60;
P_0c0c4a60: /* original 88ff, guest PC 0x0c0c4a60 */
if(!s->budget--) { s->failed_pc=0x0c0c4a60u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c4a62;
P_0c0c4a62: /* original 8b1e, guest PC 0x0c0c4a62 */
if(!s->budget--) { s->failed_pc=0x0c0c4a62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4aa2; }
goto P_0c0c4a64;
P_0c0c4a64: /* original 50db, guest PC 0x0c0c4a64 */
if(!s->budget--) { s->failed_pc=0x0c0c4a64u; return 0; }
r[0]=read(ram,r[13]+44,4);
goto P_0c0c4a66;
P_0c0c4a66: /* original 88ff, guest PC 0x0c0c4a66 */
if(!s->budget--) { s->failed_pc=0x0c0c4a66u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c4a68;
P_0c0c4a68: /* original 8b1b, guest PC 0x0c0c4a68 */
if(!s->budget--) { s->failed_pc=0x0c0c4a68u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4aa2; }
goto P_0c0c4a6a;
P_0c0c4a6a: /* original 65b3, guest PC 0x0c0c4a6a */
if(!s->budget--) { s->failed_pc=0x0c0c4a6au; return 0; }
r[5]=r[11];
goto P_0c0c4a6c;
P_0c0c4a6c: /* original b19e, guest PC 0x0c0c4a6c */
if(!s->budget--) { s->failed_pc=0x0c0c4a6cu; return 0; }
target=code_base|0x0c0c4dacu; r[16]=code_base|0x0c0c4a70u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4a70u) { target=s->pc; goto dispatch; }
goto P_0c0c4a70;
P_0c0c4a6e: /* original 64c3, guest PC 0x0c0c4a6e */
if(!s->budget--) { s->failed_pc=0x0c0c4a6eu; return 0; }
r[4]=r[12];
goto P_0c0c4a70;
P_0c0c4a70: /* original d21b, guest PC 0x0c0c4a70 */
if(!s->budget--) { s->failed_pc=0x0c0c4a70u; return 0; }
r[2]=read(ram,0x0c0c4ae0u,4);
goto P_0c0c4a72;
P_0c0c4a72: /* original 9427, guest PC 0x0c0c4a72 */
if(!s->budget--) { s->failed_pc=0x0c0c4a72u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4ac4u,2);
goto P_0c0c4a74;
P_0c0c4a74: /* original 420b, guest PC 0x0c0c4a74 */
if(!s->budget--) { s->failed_pc=0x0c0c4a74u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c4a78u;
r[4]+=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4a78u) { target=s->pc; goto dispatch; }
goto P_0c0c4a78;
P_0c0c4a76: /* original 34bc, guest PC 0x0c0c4a76 */
if(!s->budget--) { s->failed_pc=0x0c0c4a76u; return 0; }
r[4]+=r[11];
goto P_0c0c4a78;
P_0c0c4a78: /* original 84b4, guest PC 0x0c0c4a78 */
if(!s->budget--) { s->failed_pc=0x0c0c4a78u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+4,1);
goto P_0c0c4a7a;
P_0c0c4a7a: /* original 2008, guest PC 0x0c0c4a7a */
if(!s->budget--) { s->failed_pc=0x0c0c4a7au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c4a7c;
P_0c0c4a7c: /* original 8f02, guest PC 0x0c0c4a7c */
if(!s->budget--) { s->failed_pc=0x0c0c4a7cu; return 0; }
cond=r[17]&1u;
r[4]=r[11];
if(!cond) { goto P_0c0c4a84; }
goto P_0c0c4a80;
P_0c0c4a7e: /* original 64b3, guest PC 0x0c0c4a7e */
if(!s->budget--) { s->failed_pc=0x0c0c4a7eu; return 0; }
r[4]=r[11];
goto P_0c0c4a80;
P_0c0c4a80: /* original a001, guest PC 0x0c0c4a80 */
if(!s->budget--) { s->failed_pc=0x0c0c4a80u; return 0; }
r[5]=read(ram,r[14]+20,4);
goto P_0c0c4a86;
P_0c0c4a82: /* original 55e5, guest PC 0x0c0c4a82 */
if(!s->budget--) { s->failed_pc=0x0c0c4a82u; return 0; }
r[5]=read(ram,r[14]+20,4);
goto P_0c0c4a84;
P_0c0c4a84: /* original 55e4, guest PC 0x0c0c4a84 */
if(!s->budget--) { s->failed_pc=0x0c0c4a84u; return 0; }
r[5]=read(ram,r[14]+16,4);
goto P_0c0c4a86;
P_0c0c4a86: /* original d317, guest PC 0x0c0c4a86 */
if(!s->budget--) { s->failed_pc=0x0c0c4a86u; return 0; }
r[3]=read(ram,0x0c0c4ae4u,4);
goto P_0c0c4a88;
P_0c0c4a88: /* original 430b, guest PC 0x0c0c4a88 */
if(!s->budget--) { s->failed_pc=0x0c0c4a88u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4a8cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4a8cu) { target=s->pc; goto dispatch; }
goto P_0c0c4a8c;
P_0c0c4a8a: /* original 0009, guest PC 0x0c0c4a8a */
if(!s->budget--) { s->failed_pc=0x0c0c4a8au; return 0; }
goto P_0c0c4a8c;
P_0c0c4a8c: /* original e061, guest PC 0x0c0c4a8c */
if(!s->budget--) { s->failed_pc=0x0c0c4a8cu; return 0; }
r[0]=0x00000061u;
goto P_0c0c4a8e;
P_0c0c4a8e: /* original 00bc, guest PC 0x0c0c4a8e */
if(!s->budget--) { s->failed_pc=0x0c0c4a8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c4a90;
P_0c0c4a90: /* original 600c, guest PC 0x0c0c4a90 */
if(!s->budget--) { s->failed_pc=0x0c0c4a90u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c4a92;
P_0c0c4a92: /* original 8801, guest PC 0x0c0c4a92 */
if(!s->budget--) { s->failed_pc=0x0c0c4a92u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c4a94;
P_0c0c4a94: /* original 8902, guest PC 0x0c0c4a94 */
if(!s->budget--) { s->failed_pc=0x0c0c4a94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4a9c; }
goto P_0c0c4a96;
P_0c0c4a96: /* original d214, guest PC 0x0c0c4a96 */
if(!s->budget--) { s->failed_pc=0x0c0c4a96u; return 0; }
r[2]=read(ram,0x0c0c4ae8u,4);
goto P_0c0c4a98;
P_0c0c4a98: /* original 420b, guest PC 0x0c0c4a98 */
if(!s->budget--) { s->failed_pc=0x0c0c4a98u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c4a9cu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4a9cu) { target=s->pc; goto dispatch; }
goto P_0c0c4a9c;
P_0c0c4a9a: /* original 64b3, guest PC 0x0c0c4a9a */
if(!s->budget--) { s->failed_pc=0x0c0c4a9au; return 0; }
r[4]=r[11];
goto P_0c0c4a9c;
P_0c0c4a9c: /* original d313, guest PC 0x0c0c4a9c */
if(!s->budget--) { s->failed_pc=0x0c0c4a9cu; return 0; }
r[3]=read(ram,0x0c0c4aecu,4);
goto P_0c0c4a9e;
P_0c0c4a9e: /* original 430b, guest PC 0x0c0c4a9e */
if(!s->budget--) { s->failed_pc=0x0c0c4a9eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4aa2u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4aa2u) { target=s->pc; goto dispatch; }
goto P_0c0c4aa2;
P_0c0c4aa0: /* original 64b3, guest PC 0x0c0c4aa0 */
if(!s->budget--) { s->failed_pc=0x0c0c4aa0u; return 0; }
r[4]=r[11];
goto P_0c0c4aa2;
P_0c0c4aa2: /* original e06c, guest PC 0x0c0c4aa2 */
if(!s->budget--) { s->failed_pc=0x0c0c4aa2u; return 0; }
r[0]=0x0000006cu;
goto P_0c0c4aa4;
P_0c0c4aa4: /* original 00ce, guest PC 0x0c0c4aa4 */
if(!s->budget--) { s->failed_pc=0x0c0c4aa4u; return 0; }
r[0]=read(ram,r[12]+r[0],4);
goto P_0c0c4aa6;
P_0c0c4aa6: /* original 8806, guest PC 0x0c0c4aa6 */
if(!s->budget--) { s->failed_pc=0x0c0c4aa6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0c4aa8;
P_0c0c4aa8: /* original 8f24, guest PC 0x0c0c4aa8 */
if(!s->budget--) { s->failed_pc=0x0c0c4aa8u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[14]+20,4);
if(!cond) { goto P_0c0c4af4; }
goto P_0c0c4aac;
P_0c0c4aaa: /* original 54e5, guest PC 0x0c0c4aaa */
if(!s->budget--) { s->failed_pc=0x0c0c4aaau; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c0c4aac;
P_0c0c4aac: /* original 900b, guest PC 0x0c0c4aac */
if(!s->budget--) { s->failed_pc=0x0c0c4aacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4ac6u,2);
goto P_0c0c4aae;
P_0c0c4aae: /* original d310, guest PC 0x0c0c4aae */
if(!s->budget--) { s->failed_pc=0x0c0c4aaeu; return 0; }
r[3]=read(ram,0x0c0c4af0u,4);
goto P_0c0c4ab0;
P_0c0c4ab0: /* original 05de, guest PC 0x0c0c4ab0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ab0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0c4ab2;
P_0c0c4ab2: /* original 2538, guest PC 0x0c0c4ab2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ab2u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0c4ab4;
P_0c0c4ab4: /* original 8902, guest PC 0x0c0c4ab4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ab4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4abc; }
goto P_0c0c4ab6;
P_0c0c4ab6: /* original e060, guest PC 0x0c0c4ab6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ab6u; return 0; }
r[0]=0x00000060u;
goto P_0c0c4ab8;
P_0c0c4ab8: /* original a020, guest PC 0x0c0c4ab8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ab8u; return 0; }
write(ram,r[4]+r[0],r[9],1);
goto P_0c0c4afc;
P_0c0c4aba: /* original 0494, guest PC 0x0c0c4aba */
if(!s->budget--) { s->failed_pc=0x0c0c4abau; return 0; }
write(ram,r[4]+r[0],r[9],1);
goto P_0c0c4abc;
P_0c0c4abc: /* original e060, guest PC 0x0c0c4abc */
if(!s->budget--) { s->failed_pc=0x0c0c4abcu; return 0; }
r[0]=0x00000060u;
goto P_0c0c4abe;
P_0c0c4abe: /* original e116, guest PC 0x0c0c4abe */
if(!s->budget--) { s->failed_pc=0x0c0c4abeu; return 0; }
r[1]=0x00000016u;
goto P_0c0c4ac0;
P_0c0c4ac0: /* original a01c, guest PC 0x0c0c4ac0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ac0u; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c0c4afc;
P_0c0c4ac2: /* original 0414, guest PC 0x0c0c4ac2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ac2u; return 0; }
write(ram,r[4]+r[0],r[1],1);
if(!vf3_matrix_family(0x0c0c4ac4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c4ac4u; return 0; } return 1;
P_0c0c4af4: /* original e032, guest PC 0x0c0c4af4 */
if(!s->budget--) { s->failed_pc=0x0c0c4af4u; return 0; }
r[0]=0x00000032u;
goto P_0c0c4af6;
P_0c0c4af6: /* original 02cc, guest PC 0x0c0c4af6 */
if(!s->budget--) { s->failed_pc=0x0c0c4af6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c4af8;
P_0c0c4af8: /* original e060, guest PC 0x0c0c4af8 */
if(!s->budget--) { s->failed_pc=0x0c0c4af8u; return 0; }
r[0]=0x00000060u;
goto P_0c0c4afa;
P_0c0c4afa: /* original 0424, guest PC 0x0c0c4afa */
if(!s->budget--) { s->failed_pc=0x0c0c4afau; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0c4afc;
P_0c0c4afc: /* original d33d, guest PC 0x0c0c4afc */
if(!s->budget--) { s->failed_pc=0x0c0c4afcu; return 0; }
r[3]=read(ram,0x0c0c4bf4u,4);
goto P_0c0c4afe;
P_0c0c4afe: /* original e502, guest PC 0x0c0c4afe */
if(!s->budget--) { s->failed_pc=0x0c0c4afeu; return 0; }
r[5]=0x00000002u;
goto P_0c0c4b00;
P_0c0c4b00: /* original 430b, guest PC 0x0c0c4b00 */
if(!s->budget--) { s->failed_pc=0x0c0c4b00u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4b04u;
r[4]=0x0000000fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4b04u) { target=s->pc; goto dispatch; }
goto P_0c0c4b04;
P_0c0c4b02: /* original e40f, guest PC 0x0c0c4b02 */
if(!s->budget--) { s->failed_pc=0x0c0c4b02u; return 0; }
r[4]=0x0000000fu;
goto P_0c0c4b04;
P_0c0c4b04: /* original e20f, guest PC 0x0c0c4b04 */
if(!s->budget--) { s->failed_pc=0x0c0c4b04u; return 0; }
r[2]=0x0000000fu;
goto P_0c0c4b06;
P_0c0c4b06: /* original e500, guest PC 0x0c0c4b06 */
if(!s->budget--) { s->failed_pc=0x0c0c4b06u; return 0; }
r[5]=0x00000000u;
goto P_0c0c4b08;
P_0c0c4b08: /* original 2f26, guest PC 0x0c0c4b08 */
if(!s->budget--) { s->failed_pc=0x0c0c4b08u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4b0a;
P_0c0c4b0a: /* original d33b, guest PC 0x0c0c4b0a */
if(!s->budget--) { s->failed_pc=0x0c0c4b0au; return 0; }
r[3]=read(ram,0x0c0c4bf8u,4);
goto P_0c0c4b0c;
P_0c0c4b0c: /* original e614, guest PC 0x0c0c4b0c */
if(!s->budget--) { s->failed_pc=0x0c0c4b0cu; return 0; }
r[6]=0x00000014u;
goto P_0c0c4b0e;
P_0c0c4b0e: /* original 6723, guest PC 0x0c0c4b0e */
if(!s->budget--) { s->failed_pc=0x0c0c4b0eu; return 0; }
r[7]=r[2];
goto P_0c0c4b10;
P_0c0c4b10: /* original 430b, guest PC 0x0c0c4b10 */
if(!s->budget--) { s->failed_pc=0x0c0c4b10u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4b14u;
r[4]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4b14u) { target=s->pc; goto dispatch; }
goto P_0c0c4b14;
P_0c0c4b12: /* original 6453, guest PC 0x0c0c4b12 */
if(!s->budget--) { s->failed_pc=0x0c0c4b12u; return 0; }
r[4]=r[5];
goto P_0c0c4b14;
P_0c0c4b14: /* original d239, guest PC 0x0c0c4b14 */
if(!s->budget--) { s->failed_pc=0x0c0c4b14u; return 0; }
r[2]=read(ram,0x0c0c4bfcu,4);
goto P_0c0c4b16;
P_0c0c4b16: /* original 7f04, guest PC 0x0c0c4b16 */
if(!s->budget--) { s->failed_pc=0x0c0c4b16u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c4b18;
P_0c0c4b18: /* original 64f3, guest PC 0x0c0c4b18 */
if(!s->budget--) { s->failed_pc=0x0c0c4b18u; return 0; }
r[4]=r[15];
goto P_0c0c4b1a;
P_0c0c4b1a: /* original 420b, guest PC 0x0c0c4b1a */
if(!s->budget--) { s->failed_pc=0x0c0c4b1au; return 0; }
target=r[2];
r[16]=code_base|0x0c0c4b1eu;
r[4]+=0x0000007cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4b1eu) { target=s->pc; goto dispatch; }
goto P_0c0c4b1e;
P_0c0c4b1c: /* original 747c, guest PC 0x0c0c4b1c */
if(!s->budget--) { s->failed_pc=0x0c0c4b1cu; return 0; }
r[4]+=0x0000007cu;
goto P_0c0c4b1e;
P_0c0c4b1e: /* original d338, guest PC 0x0c0c4b1e */
if(!s->budget--) { s->failed_pc=0x0c0c4b1eu; return 0; }
r[3]=read(ram,0x0c0c4c00u,4);
goto P_0c0c4b20;
P_0c0c4b20: /* original 430b, guest PC 0x0c0c4b20 */
if(!s->budget--) { s->failed_pc=0x0c0c4b20u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4b24u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4b24u) { target=s->pc; goto dispatch; }
goto P_0c0c4b24;
P_0c0c4b22: /* original e401, guest PC 0x0c0c4b22 */
if(!s->budget--) { s->failed_pc=0x0c0c4b22u; return 0; }
r[4]=0x00000001u;
goto P_0c0c4b24;
P_0c0c4b24: /* original d237, guest PC 0x0c0c4b24 */
if(!s->budget--) { s->failed_pc=0x0c0c4b24u; return 0; }
r[2]=read(ram,0x0c0c4c04u,4);
goto P_0c0c4b26;
P_0c0c4b26: /* original 420b, guest PC 0x0c0c4b26 */
if(!s->budget--) { s->failed_pc=0x0c0c4b26u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c4b2au;
r[4]=read(ram,r[14]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4b2au) { target=s->pc; goto dispatch; }
goto P_0c0c4b2a;
P_0c0c4b28: /* original 54ea, guest PC 0x0c0c4b28 */
if(!s->budget--) { s->failed_pc=0x0c0c4b28u; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c0c4b2a;
P_0c0c4b2a: /* original d336, guest PC 0x0c0c4b2a */
if(!s->budget--) { s->failed_pc=0x0c0c4b2au; return 0; }
r[3]=read(ram,0x0c0c4c04u,4);
goto P_0c0c4b2c;
P_0c0c4b2c: /* original 430b, guest PC 0x0c0c4b2c */
if(!s->budget--) { s->failed_pc=0x0c0c4b2cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4b30u;
r[4]=read(ram,r[14]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4b30u) { target=s->pc; goto dispatch; }
goto P_0c0c4b30;
P_0c0c4b2e: /* original 54eb, guest PC 0x0c0c4b2e */
if(!s->budget--) { s->failed_pc=0x0c0c4b2eu; return 0; }
r[4]=read(ram,r[14]+44,4);
goto P_0c0c4b30;
P_0c0c4b30: /* original e07f, guest PC 0x0c0c4b30 */
if(!s->budget--) { s->failed_pc=0x0c0c4b30u; return 0; }
r[0]=0x0000007fu;
goto P_0c0c4b32;
P_0c0c4b32: /* original e500, guest PC 0x0c0c4b32 */
if(!s->budget--) { s->failed_pc=0x0c0c4b32u; return 0; }
r[5]=0x00000000u;
goto P_0c0c4b34;
P_0c0c4b34: /* original 0d54, guest PC 0x0c0c4b34 */
if(!s->budget--) { s->failed_pc=0x0c0c4b34u; return 0; }
write(ram,r[13]+r[0],r[5],1);
goto P_0c0c4b36;
P_0c0c4b36: /* original 50d8, guest PC 0x0c0c4b36 */
if(!s->budget--) { s->failed_pc=0x0c0c4b36u; return 0; }
r[0]=read(ram,r[13]+32,4);
goto P_0c0c4b38;
P_0c0c4b38: /* original 8801, guest PC 0x0c0c4b38 */
if(!s->budget--) { s->failed_pc=0x0c0c4b38u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c4b3a;
P_0c0c4b3a: /* original 8f08, guest PC 0x0c0c4b3a */
if(!s->budget--) { s->failed_pc=0x0c0c4b3au; return 0; }
cond=r[17]&1u;
r[4]=0xffffffffu;
if(!cond) { goto P_0c0c4b4e; }
goto P_0c0c4b3e;
P_0c0c4b3c: /* original e4ff, guest PC 0x0c0c4b3c */
if(!s->budget--) { s->failed_pc=0x0c0c4b3cu; return 0; }
r[4]=0xffffffffu;
goto P_0c0c4b3e;
P_0c0c4b3e: /* original 50da, guest PC 0x0c0c4b3e */
if(!s->budget--) { s->failed_pc=0x0c0c4b3eu; return 0; }
r[0]=read(ram,r[13]+40,4);
goto P_0c0c4b40;
P_0c0c4b40: /* original 8801, guest PC 0x0c0c4b40 */
if(!s->budget--) { s->failed_pc=0x0c0c4b40u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c4b42;
P_0c0c4b42: /* original 8b04, guest PC 0x0c0c4b42 */
if(!s->budget--) { s->failed_pc=0x0c0c4b42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4b4e; }
goto P_0c0c4b44;
P_0c0c4b44: /* original e03a, guest PC 0x0c0c4b44 */
if(!s->budget--) { s->failed_pc=0x0c0c4b44u; return 0; }
r[0]=0x0000003au;
goto P_0c0c4b46;
P_0c0c4b46: /* original 1d48, guest PC 0x0c0c4b46 */
if(!s->budget--) { s->failed_pc=0x0c0c4b46u; return 0; }
write(ram,r[13]+32,r[4],4);
goto P_0c0c4b48;
P_0c0c4b48: /* original 1d4a, guest PC 0x0c0c4b48 */
if(!s->budget--) { s->failed_pc=0x0c0c4b48u; return 0; }
write(ram,r[13]+40,r[4],4);
goto P_0c0c4b4a;
P_0c0c4b4a: /* original 53ea, guest PC 0x0c0c4b4a */
if(!s->budget--) { s->failed_pc=0x0c0c4b4au; return 0; }
r[3]=read(ram,r[14]+40,4);
goto P_0c0c4b4c;
P_0c0c4b4c: /* original 0354, guest PC 0x0c0c4b4c */
if(!s->budget--) { s->failed_pc=0x0c0c4b4cu; return 0; }
write(ram,r[3]+r[0],r[5],1);
goto P_0c0c4b4e;
P_0c0c4b4e: /* original 50d9, guest PC 0x0c0c4b4e */
if(!s->budget--) { s->failed_pc=0x0c0c4b4eu; return 0; }
r[0]=read(ram,r[13]+36,4);
goto P_0c0c4b50;
P_0c0c4b50: /* original 8801, guest PC 0x0c0c4b50 */
if(!s->budget--) { s->failed_pc=0x0c0c4b50u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c4b52;
P_0c0c4b52: /* original 8b07, guest PC 0x0c0c4b52 */
if(!s->budget--) { s->failed_pc=0x0c0c4b52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4b64; }
goto P_0c0c4b54;
P_0c0c4b54: /* original 50db, guest PC 0x0c0c4b54 */
if(!s->budget--) { s->failed_pc=0x0c0c4b54u; return 0; }
r[0]=read(ram,r[13]+44,4);
goto P_0c0c4b56;
P_0c0c4b56: /* original 8801, guest PC 0x0c0c4b56 */
if(!s->budget--) { s->failed_pc=0x0c0c4b56u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c4b58;
P_0c0c4b58: /* original 8b04, guest PC 0x0c0c4b58 */
if(!s->budget--) { s->failed_pc=0x0c0c4b58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4b64; }
goto P_0c0c4b5a;
P_0c0c4b5a: /* original e03a, guest PC 0x0c0c4b5a */
if(!s->budget--) { s->failed_pc=0x0c0c4b5au; return 0; }
r[0]=0x0000003au;
goto P_0c0c4b5c;
P_0c0c4b5c: /* original 1d49, guest PC 0x0c0c4b5c */
if(!s->budget--) { s->failed_pc=0x0c0c4b5cu; return 0; }
write(ram,r[13]+36,r[4],4);
goto P_0c0c4b5e;
P_0c0c4b5e: /* original 1d4b, guest PC 0x0c0c4b5e */
if(!s->budget--) { s->failed_pc=0x0c0c4b5eu; return 0; }
write(ram,r[13]+44,r[4],4);
goto P_0c0c4b60;
P_0c0c4b60: /* original 53eb, guest PC 0x0c0c4b60 */
if(!s->budget--) { s->failed_pc=0x0c0c4b60u; return 0; }
r[3]=read(ram,r[14]+44,4);
goto P_0c0c4b62;
P_0c0c4b62: /* original 0354, guest PC 0x0c0c4b62 */
if(!s->budget--) { s->failed_pc=0x0c0c4b62u; return 0; }
write(ram,r[3]+r[0],r[5],1);
goto P_0c0c4b64;
P_0c0c4b64: /* original 9142, guest PC 0x0c0c4b64 */
if(!s->budget--) { s->failed_pc=0x0c0c4b64u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4becu,2);
goto P_0c0c4b66;
P_0c0c4b66: /* original 3f1c, guest PC 0x0c0c4b66 */
if(!s->budget--) { s->failed_pc=0x0c0c4b66u; return 0; }
r[15]+=r[1];
goto P_0c0c4b68;
P_0c0c4b68: /* original 4f26, guest PC 0x0c0c4b68 */
if(!s->budget--) { s->failed_pc=0x0c0c4b68u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c4b6a;
P_0c0c4b6a: /* original fef9, guest PC 0x0c0c4b6a */
if(!s->budget--) { s->failed_pc=0x0c0c4b6au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c4b6c;
P_0c0c4b6c: /* original fff9, guest PC 0x0c0c4b6c */
if(!s->budget--) { s->failed_pc=0x0c0c4b6cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c4b6e;
P_0c0c4b6e: /* original 68f6, guest PC 0x0c0c4b6e */
if(!s->budget--) { s->failed_pc=0x0c0c4b6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c4b70;
P_0c0c4b70: /* original 69f6, guest PC 0x0c0c4b70 */
if(!s->budget--) { s->failed_pc=0x0c0c4b70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c4b72;
P_0c0c4b72: /* original 6af6, guest PC 0x0c0c4b72 */
if(!s->budget--) { s->failed_pc=0x0c0c4b72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c4b74;
P_0c0c4b74: /* original 6bf6, guest PC 0x0c0c4b74 */
if(!s->budget--) { s->failed_pc=0x0c0c4b74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c4b76;
P_0c0c4b76: /* original 6cf6, guest PC 0x0c0c4b76 */
if(!s->budget--) { s->failed_pc=0x0c0c4b76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c4b78;
P_0c0c4b78: /* original 6df6, guest PC 0x0c0c4b78 */
if(!s->budget--) { s->failed_pc=0x0c0c4b78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c4b7a;
P_0c0c4b7a: /* original 000b, guest PC 0x0c0c4b7a */
if(!s->budget--) { s->failed_pc=0x0c0c4b7au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c4b7c: /* original 6ef6, guest PC 0x0c0c4b7c */
if(!s->budget--) { s->failed_pc=0x0c0c4b7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c4b7eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c4b7eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
