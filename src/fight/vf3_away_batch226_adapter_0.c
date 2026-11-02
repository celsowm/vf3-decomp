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
int vf3_away_batch226_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a2e06u: goto P_0c0a2e06;
case 0x0c0a2e08u: goto P_0c0a2e08;
case 0x0c0a2e0au: goto P_0c0a2e0a;
case 0x0c0a2e0cu: goto P_0c0a2e0c;
case 0x0c0a2e0eu: goto P_0c0a2e0e;
case 0x0c0a2e10u: goto P_0c0a2e10;
case 0x0c0a2e12u: goto P_0c0a2e12;
case 0x0c0a2e14u: goto P_0c0a2e14;
case 0x0c0a2e16u: goto P_0c0a2e16;
case 0x0c0a2e18u: goto P_0c0a2e18;
case 0x0c0a2e1au: goto P_0c0a2e1a;
case 0x0c0a2e1cu: goto P_0c0a2e1c;
case 0x0c0a2e1eu: goto P_0c0a2e1e;
case 0x0c0a2e20u: goto P_0c0a2e20;
case 0x0c0a2e22u: goto P_0c0a2e22;
case 0x0c0a2e24u: goto P_0c0a2e24;
case 0x0c0a2e26u: goto P_0c0a2e26;
case 0x0c0a2e28u: goto P_0c0a2e28;
case 0x0c0a2e2au: goto P_0c0a2e2a;
case 0x0c0b41d6u: goto P_0c0b41d6;
case 0x0c0b41d8u: goto P_0c0b41d8;
case 0x0c0b41dau: goto P_0c0b41da;
case 0x0c0b41dcu: goto P_0c0b41dc;
case 0x0c0b41deu: goto P_0c0b41de;
case 0x0c0b41e0u: goto P_0c0b41e0;
case 0x0c0b41e2u: goto P_0c0b41e2;
case 0x0c0b41e4u: goto P_0c0b41e4;
case 0x0c0b41e6u: goto P_0c0b41e6;
case 0x0c0b41e8u: goto P_0c0b41e8;
case 0x0c0b41eau: goto P_0c0b41ea;
case 0x0c0b41ecu: goto P_0c0b41ec;
case 0x0c0b41eeu: goto P_0c0b41ee;
case 0x0c0b41f0u: goto P_0c0b41f0;
case 0x0c0b41f2u: goto P_0c0b41f2;
case 0x0c0b41f4u: goto P_0c0b41f4;
case 0x0c0b41f6u: goto P_0c0b41f6;
case 0x0c0b41f8u: goto P_0c0b41f8;
case 0x0c0b41fau: goto P_0c0b41fa;
case 0x0c0b41fcu: goto P_0c0b41fc;
case 0x0c0b41feu: goto P_0c0b41fe;
case 0x0c0b4200u: goto P_0c0b4200;
case 0x0c0b4202u: goto P_0c0b4202;
case 0x0c0b4204u: goto P_0c0b4204;
case 0x0c0b4206u: goto P_0c0b4206;
case 0x0c0b4208u: goto P_0c0b4208;
case 0x0c0b420au: goto P_0c0b420a;
case 0x0c0b420cu: goto P_0c0b420c;
case 0x0c0b420eu: goto P_0c0b420e;
case 0x0c0b4210u: goto P_0c0b4210;
case 0x0c0b4212u: goto P_0c0b4212;
case 0x0c0b4214u: goto P_0c0b4214;
case 0x0c0b4216u: goto P_0c0b4216;
case 0x0c0b4218u: goto P_0c0b4218;
case 0x0c0b421au: goto P_0c0b421a;
case 0x0c0b421cu: goto P_0c0b421c;
case 0x0c0b421eu: goto P_0c0b421e;
case 0x0c0b4220u: goto P_0c0b4220;
case 0x0c0b4222u: goto P_0c0b4222;
case 0x0c0b4224u: goto P_0c0b4224;
case 0x0c0b4226u: goto P_0c0b4226;
case 0x0c0b4228u: goto P_0c0b4228;
case 0x0c0b422au: goto P_0c0b422a;
case 0x0c0b422cu: goto P_0c0b422c;
case 0x0c0b422eu: goto P_0c0b422e;
case 0x0c0b4230u: goto P_0c0b4230;
case 0x0c0b4232u: goto P_0c0b4232;
case 0x0c0b4234u: goto P_0c0b4234;
case 0x0c0b4236u: goto P_0c0b4236;
case 0x0c0b4238u: goto P_0c0b4238;
case 0x0c0b423au: goto P_0c0b423a;
case 0x0c0b423cu: goto P_0c0b423c;
case 0x0c0b423eu: goto P_0c0b423e;
case 0x0c0b4240u: goto P_0c0b4240;
case 0x0c0b4242u: goto P_0c0b4242;
case 0x0c0b4244u: goto P_0c0b4244;
case 0x0c0b4246u: goto P_0c0b4246;
case 0x0c0b4248u: goto P_0c0b4248;
case 0x0c0b424au: goto P_0c0b424a;
case 0x0c0b424cu: goto P_0c0b424c;
case 0x0c0b424eu: goto P_0c0b424e;
case 0x0c0b4250u: goto P_0c0b4250;
case 0x0c0b4252u: goto P_0c0b4252;
case 0x0c0b4254u: goto P_0c0b4254;
case 0x0c0b4256u: goto P_0c0b4256;
case 0x0c0b4258u: goto P_0c0b4258;
case 0x0c0b425au: goto P_0c0b425a;
case 0x0c0b425cu: goto P_0c0b425c;
case 0x0c0b425eu: goto P_0c0b425e;
case 0x0c0b4260u: goto P_0c0b4260;
case 0x0c0b4262u: goto P_0c0b4262;
case 0x0c0b4264u: goto P_0c0b4264;
case 0x0c0b4266u: goto P_0c0b4266;
case 0x0c0b4268u: goto P_0c0b4268;
case 0x0c0b426au: goto P_0c0b426a;
case 0x0c0b426cu: goto P_0c0b426c;
case 0x0c0b426eu: goto P_0c0b426e;
case 0x0c0b4270u: goto P_0c0b4270;
case 0x0c0b4272u: goto P_0c0b4272;
case 0x0c0b4274u: goto P_0c0b4274;
case 0x0c0b4276u: goto P_0c0b4276;
case 0x0c0b4278u: goto P_0c0b4278;
case 0x0c0b427au: goto P_0c0b427a;
case 0x0c0b427cu: goto P_0c0b427c;
case 0x0c0b427eu: goto P_0c0b427e;
case 0x0c0b4280u: goto P_0c0b4280;
case 0x0c0b4282u: goto P_0c0b4282;
case 0x0c0b4284u: goto P_0c0b4284;
case 0x0c0b4286u: goto P_0c0b4286;
case 0x0c0b4288u: goto P_0c0b4288;
case 0x0c0b428au: goto P_0c0b428a;
case 0x0c0b428cu: goto P_0c0b428c;
case 0x0c0b428eu: goto P_0c0b428e;
case 0x0c0b4290u: goto P_0c0b4290;
case 0x0c0b4292u: goto P_0c0b4292;
case 0x0c0b4294u: goto P_0c0b4294;
case 0x0c0b4296u: goto P_0c0b4296;
case 0x0c0b4298u: goto P_0c0b4298;
case 0x0c0b429au: goto P_0c0b429a;
case 0x0c0b429cu: goto P_0c0b429c;
case 0x0c0b429eu: goto P_0c0b429e;
case 0x0c0b42a0u: goto P_0c0b42a0;
case 0x0c0b42a2u: goto P_0c0b42a2;
case 0x0c0b42a4u: goto P_0c0b42a4;
case 0x0c0b42a6u: goto P_0c0b42a6;
case 0x0c0b42a8u: goto P_0c0b42a8;
case 0x0c0b42aau: goto P_0c0b42aa;
case 0x0c0b42acu: goto P_0c0b42ac;
case 0x0c0b42aeu: goto P_0c0b42ae;
case 0x0c0b42b0u: goto P_0c0b42b0;
case 0x0c0b42b2u: goto P_0c0b42b2;
case 0x0c0b42b4u: goto P_0c0b42b4;
case 0x0c0b42b6u: goto P_0c0b42b6;
case 0x0c0b42b8u: goto P_0c0b42b8;
case 0x0c0b42bau: goto P_0c0b42ba;
case 0x0c0b42bcu: goto P_0c0b42bc;
case 0x0c0b42beu: goto P_0c0b42be;
case 0x0c0b42c0u: goto P_0c0b42c0;
case 0x0c0b42c2u: goto P_0c0b42c2;
case 0x0c0b42c4u: goto P_0c0b42c4;
case 0x0c0b42c6u: goto P_0c0b42c6;
case 0x0c0b42c8u: goto P_0c0b42c8;
case 0x0c0b42cau: goto P_0c0b42ca;
case 0x0c0b42ccu: goto P_0c0b42cc;
case 0x0c0b42ceu: goto P_0c0b42ce;
case 0x0c0b42d0u: goto P_0c0b42d0;
case 0x0c0b42d2u: goto P_0c0b42d2;
case 0x0c0b42d4u: goto P_0c0b42d4;
case 0x0c0b42d6u: goto P_0c0b42d6;
case 0x0c0b42d8u: goto P_0c0b42d8;
case 0x0c0b42dau: goto P_0c0b42da;
case 0x0c0b42dcu: goto P_0c0b42dc;
case 0x0c0b42deu: goto P_0c0b42de;
case 0x0c0b42e0u: goto P_0c0b42e0;
case 0x0c0b42e2u: goto P_0c0b42e2;
case 0x0c0b42e4u: goto P_0c0b42e4;
case 0x0c0b42e6u: goto P_0c0b42e6;
case 0x0c0b42e8u: goto P_0c0b42e8;
case 0x0c0b42eau: goto P_0c0b42ea;
case 0x0c0b42ecu: goto P_0c0b42ec;
case 0x0c0b42eeu: goto P_0c0b42ee;
case 0x0c0b42f0u: goto P_0c0b42f0;
case 0x0c0b42f2u: goto P_0c0b42f2;
case 0x0c0b42f4u: goto P_0c0b42f4;
case 0x0c0b42f6u: goto P_0c0b42f6;
case 0x0c0b42f8u: goto P_0c0b42f8;
case 0x0c0b42fau: goto P_0c0b42fa;
case 0x0c0b42fcu: goto P_0c0b42fc;
case 0x0c0b42feu: goto P_0c0b42fe;
case 0x0c0b4300u: goto P_0c0b4300;
case 0x0c0b4302u: goto P_0c0b4302;
case 0x0c0b4304u: goto P_0c0b4304;
case 0x0c0b4306u: goto P_0c0b4306;
case 0x0c0b4308u: goto P_0c0b4308;
case 0x0c0b430au: goto P_0c0b430a;
case 0x0c0b430cu: goto P_0c0b430c;
case 0x0c0b430eu: goto P_0c0b430e;
case 0x0c0b4310u: goto P_0c0b4310;
case 0x0c0b4312u: goto P_0c0b4312;
case 0x0c0b4314u: goto P_0c0b4314;
case 0x0c0b4316u: goto P_0c0b4316;
case 0x0c0b4318u: goto P_0c0b4318;
case 0x0c0b431au: goto P_0c0b431a;
case 0x0c0b431cu: goto P_0c0b431c;
case 0x0c0b431eu: goto P_0c0b431e;
case 0x0c0b4320u: goto P_0c0b4320;
case 0x0c0b4322u: goto P_0c0b4322;
case 0x0c0b4324u: goto P_0c0b4324;
case 0x0c0b4326u: goto P_0c0b4326;
case 0x0c0b4328u: goto P_0c0b4328;
case 0x0c0b432au: goto P_0c0b432a;
case 0x0c0b432cu: goto P_0c0b432c;
case 0x0c0b432eu: goto P_0c0b432e;
case 0x0c0b4330u: goto P_0c0b4330;
case 0x0c0b4332u: goto P_0c0b4332;
case 0x0c0b4334u: goto P_0c0b4334;
case 0x0c0b4336u: goto P_0c0b4336;
case 0x0c0b4338u: goto P_0c0b4338;
case 0x0c0b43a8u: goto P_0c0b43a8;
case 0x0c0b43aau: goto P_0c0b43aa;
case 0x0c0b43acu: goto P_0c0b43ac;
case 0x0c0b43aeu: goto P_0c0b43ae;
case 0x0c0b43b0u: goto P_0c0b43b0;
case 0x0c0b43b2u: goto P_0c0b43b2;
case 0x0c0b43b4u: goto P_0c0b43b4;
case 0x0c0b43b6u: goto P_0c0b43b6;
case 0x0c0b43b8u: goto P_0c0b43b8;
case 0x0c0b43bau: goto P_0c0b43ba;
case 0x0c0b43bcu: goto P_0c0b43bc;
case 0x0c0b43beu: goto P_0c0b43be;
case 0x0c0b43c0u: goto P_0c0b43c0;
case 0x0c0b43c2u: goto P_0c0b43c2;
case 0x0c0b43c4u: goto P_0c0b43c4;
case 0x0c0b43c6u: goto P_0c0b43c6;
case 0x0c0b43c8u: goto P_0c0b43c8;
case 0x0c0b43cau: goto P_0c0b43ca;
case 0x0c0b43ccu: goto P_0c0b43cc;
case 0x0c0b43ceu: goto P_0c0b43ce;
case 0x0c0b43d0u: goto P_0c0b43d0;
case 0x0c0b43d2u: goto P_0c0b43d2;
case 0x0c0b43d4u: goto P_0c0b43d4;
case 0x0c0b43d6u: goto P_0c0b43d6;
case 0x0c0b43d8u: goto P_0c0b43d8;
case 0x0c0b43dau: goto P_0c0b43da;
case 0x0c0b43dcu: goto P_0c0b43dc;
case 0x0c0b43deu: goto P_0c0b43de;
case 0x0c0b43e0u: goto P_0c0b43e0;
case 0x0c0b43e2u: goto P_0c0b43e2;
case 0x0c0b43e4u: goto P_0c0b43e4;
case 0x0c0b43e6u: goto P_0c0b43e6;
case 0x0c0b43e8u: goto P_0c0b43e8;
case 0x0c0b43eau: goto P_0c0b43ea;
case 0x0c0b43ecu: goto P_0c0b43ec;
case 0x0c0b43eeu: goto P_0c0b43ee;
case 0x0c0b43f0u: goto P_0c0b43f0;
case 0x0c0b43f2u: goto P_0c0b43f2;
case 0x0c0b43f4u: goto P_0c0b43f4;
case 0x0c0b43f6u: goto P_0c0b43f6;
case 0x0c0b43f8u: goto P_0c0b43f8;
case 0x0c0b43fau: goto P_0c0b43fa;
case 0x0c0b43fcu: goto P_0c0b43fc;
case 0x0c0b43feu: goto P_0c0b43fe;
case 0x0c0b4400u: goto P_0c0b4400;
case 0x0c0b4402u: goto P_0c0b4402;
case 0x0c0b4404u: goto P_0c0b4404;
case 0x0c0b4406u: goto P_0c0b4406;
case 0x0c0b4408u: goto P_0c0b4408;
case 0x0c0b440au: goto P_0c0b440a;
case 0x0c0b440cu: goto P_0c0b440c;
case 0x0c0b440eu: goto P_0c0b440e;
case 0x0c0b4410u: goto P_0c0b4410;
case 0x0c0b4412u: goto P_0c0b4412;
case 0x0c0b4414u: goto P_0c0b4414;
case 0x0c0b4416u: goto P_0c0b4416;
case 0x0c0b4418u: goto P_0c0b4418;
case 0x0c0b441au: goto P_0c0b441a;
case 0x0c0b441cu: goto P_0c0b441c;
case 0x0c0b441eu: goto P_0c0b441e;
case 0x0c0b4420u: goto P_0c0b4420;
case 0x0c0b4422u: goto P_0c0b4422;
case 0x0c0b4424u: goto P_0c0b4424;
case 0x0c0b4426u: goto P_0c0b4426;
case 0x0c0b4428u: goto P_0c0b4428;
case 0x0c0b442au: goto P_0c0b442a;
case 0x0c0b442cu: goto P_0c0b442c;
case 0x0c0b442eu: goto P_0c0b442e;
case 0x0c0b4430u: goto P_0c0b4430;
case 0x0c0b4432u: goto P_0c0b4432;
case 0x0c0b4434u: goto P_0c0b4434;
case 0x0c0b4436u: goto P_0c0b4436;
case 0x0c0b4438u: goto P_0c0b4438;
case 0x0c0b443au: goto P_0c0b443a;
case 0x0c0b443cu: goto P_0c0b443c;
case 0x0c0b443eu: goto P_0c0b443e;
case 0x0c0b4440u: goto P_0c0b4440;
case 0x0c0b4442u: goto P_0c0b4442;
case 0x0c0b4444u: goto P_0c0b4444;
case 0x0c0b4446u: goto P_0c0b4446;
case 0x0c0b4448u: goto P_0c0b4448;
case 0x0c0b444au: goto P_0c0b444a;
case 0x0c0b444cu: goto P_0c0b444c;
case 0x0c0b444eu: goto P_0c0b444e;
case 0x0c0b4450u: goto P_0c0b4450;
case 0x0c0b4452u: goto P_0c0b4452;
case 0x0c0b4454u: goto P_0c0b4454;
case 0x0c0b4456u: goto P_0c0b4456;
case 0x0c0b4458u: goto P_0c0b4458;
case 0x0c0b445au: goto P_0c0b445a;
case 0x0c0b445cu: goto P_0c0b445c;
case 0x0c0b445eu: goto P_0c0b445e;
case 0x0c0b4460u: goto P_0c0b4460;
case 0x0c0b4462u: goto P_0c0b4462;
case 0x0c0b4464u: goto P_0c0b4464;
case 0x0c0b4466u: goto P_0c0b4466;
case 0x0c0b4468u: goto P_0c0b4468;
case 0x0c0b446au: goto P_0c0b446a;
case 0x0c0b446cu: goto P_0c0b446c;
case 0x0c0b446eu: goto P_0c0b446e;
case 0x0c0b4470u: goto P_0c0b4470;
case 0x0c0b4472u: goto P_0c0b4472;
case 0x0c0b4474u: goto P_0c0b4474;
case 0x0c0b4476u: goto P_0c0b4476;
case 0x0c0b4478u: goto P_0c0b4478;
case 0x0c0b447au: goto P_0c0b447a;
case 0x0c0b447cu: goto P_0c0b447c;
case 0x0c0b447eu: goto P_0c0b447e;
case 0x0c0b4480u: goto P_0c0b4480;
case 0x0c0b4482u: goto P_0c0b4482;
case 0x0c0b4484u: goto P_0c0b4484;
case 0x0c0b4486u: goto P_0c0b4486;
case 0x0c0b4488u: goto P_0c0b4488;
case 0x0c0b448au: goto P_0c0b448a;
case 0x0c0b448cu: goto P_0c0b448c;
case 0x0c0b448eu: goto P_0c0b448e;
case 0x0c0b4490u: goto P_0c0b4490;
case 0x0c0b4492u: goto P_0c0b4492;
case 0x0c0b4494u: goto P_0c0b4494;
case 0x0c0b4496u: goto P_0c0b4496;
case 0x0c0b4498u: goto P_0c0b4498;
case 0x0c0b449au: goto P_0c0b449a;
case 0x0c0b449cu: goto P_0c0b449c;
case 0x0c0b449eu: goto P_0c0b449e;
case 0x0c0b44a0u: goto P_0c0b44a0;
case 0x0c0b44a2u: goto P_0c0b44a2;
case 0x0c0b44a4u: goto P_0c0b44a4;
case 0x0c0b44a6u: goto P_0c0b44a6;
case 0x0c0b44a8u: goto P_0c0b44a8;
case 0x0c0b44aau: goto P_0c0b44aa;
case 0x0c0b44acu: goto P_0c0b44ac;
case 0x0c0b44aeu: goto P_0c0b44ae;
case 0x0c0b44b0u: goto P_0c0b44b0;
case 0x0c0b44b2u: goto P_0c0b44b2;
case 0x0c0b44b4u: goto P_0c0b44b4;
case 0x0c0b44b6u: goto P_0c0b44b6;
case 0x0c0b44b8u: goto P_0c0b44b8;
case 0x0c0b44bau: goto P_0c0b44ba;
case 0x0c0b44bcu: goto P_0c0b44bc;
case 0x0c0b44beu: goto P_0c0b44be;
case 0x0c0b44c0u: goto P_0c0b44c0;
case 0x0c0b44c2u: goto P_0c0b44c2;
case 0x0c0b44c4u: goto P_0c0b44c4;
case 0x0c0b44c6u: goto P_0c0b44c6;
case 0x0c0b44c8u: goto P_0c0b44c8;
case 0x0c0b44cau: goto P_0c0b44ca;
case 0x0c0b44ccu: goto P_0c0b44cc;
case 0x0c0b44ceu: goto P_0c0b44ce;
case 0x0c0b44d0u: goto P_0c0b44d0;
case 0x0c0b44d2u: goto P_0c0b44d2;
case 0x0c0b44d4u: goto P_0c0b44d4;
case 0x0c0b44d6u: goto P_0c0b44d6;
case 0x0c0b44d8u: goto P_0c0b44d8;
case 0x0c0b44dau: goto P_0c0b44da;
case 0x0c0b44dcu: goto P_0c0b44dc;
case 0x0c0b44deu: goto P_0c0b44de;
case 0x0c0b44e0u: goto P_0c0b44e0;
case 0x0c0b44e2u: goto P_0c0b44e2;
case 0x0c0b44e4u: goto P_0c0b44e4;
case 0x0c0b44e6u: goto P_0c0b44e6;
case 0x0c0b44e8u: goto P_0c0b44e8;
case 0x0c0b44eau: goto P_0c0b44ea;
case 0x0c0b44ecu: goto P_0c0b44ec;
case 0x0c0b44eeu: goto P_0c0b44ee;
case 0x0c0b44f0u: goto P_0c0b44f0;
case 0x0c0b44f2u: goto P_0c0b44f2;
case 0x0c0b44f4u: goto P_0c0b44f4;
case 0x0c0b44f6u: goto P_0c0b44f6;
case 0x0c0b44f8u: goto P_0c0b44f8;
case 0x0c0b44fau: goto P_0c0b44fa;
case 0x0c0b44fcu: goto P_0c0b44fc;
case 0x0c0b44feu: goto P_0c0b44fe;
case 0x0c0b4500u: goto P_0c0b4500;
case 0x0c0b457au: goto P_0c0b457a;
case 0x0c0b457cu: goto P_0c0b457c;
case 0x0c0b457eu: goto P_0c0b457e;
case 0x0c0b4580u: goto P_0c0b4580;
case 0x0c0b4582u: goto P_0c0b4582;
case 0x0c0b4584u: goto P_0c0b4584;
case 0x0c0b4586u: goto P_0c0b4586;
case 0x0c0b4588u: goto P_0c0b4588;
case 0x0c0b458au: goto P_0c0b458a;
case 0x0c0b458cu: goto P_0c0b458c;
case 0x0c0b458eu: goto P_0c0b458e;
case 0x0c0b4590u: goto P_0c0b4590;
case 0x0c0b4592u: goto P_0c0b4592;
case 0x0c0b4594u: goto P_0c0b4594;
case 0x0c0b4596u: goto P_0c0b4596;
case 0x0c0b4598u: goto P_0c0b4598;
case 0x0c0b459au: goto P_0c0b459a;
case 0x0c0b459cu: goto P_0c0b459c;
case 0x0c0b459eu: goto P_0c0b459e;
case 0x0c0b45a0u: goto P_0c0b45a0;
case 0x0c0b45a2u: goto P_0c0b45a2;
case 0x0c0b45a4u: goto P_0c0b45a4;
case 0x0c0b45a6u: goto P_0c0b45a6;
case 0x0c0b45a8u: goto P_0c0b45a8;
case 0x0c0b45aau: goto P_0c0b45aa;
case 0x0c0b45acu: goto P_0c0b45ac;
case 0x0c0b45aeu: goto P_0c0b45ae;
case 0x0c0b45b0u: goto P_0c0b45b0;
case 0x0c0b45b2u: goto P_0c0b45b2;
case 0x0c0b45b4u: goto P_0c0b45b4;
case 0x0c0b45b6u: goto P_0c0b45b6;
case 0x0c0b45b8u: goto P_0c0b45b8;
case 0x0c0b45bau: goto P_0c0b45ba;
case 0x0c0b45bcu: goto P_0c0b45bc;
case 0x0c0b45beu: goto P_0c0b45be;
case 0x0c0b45c0u: goto P_0c0b45c0;
case 0x0c0b45c2u: goto P_0c0b45c2;
case 0x0c0b45c4u: goto P_0c0b45c4;
case 0x0c0b45c6u: goto P_0c0b45c6;
case 0x0c0b45c8u: goto P_0c0b45c8;
case 0x0c0b45cau: goto P_0c0b45ca;
case 0x0c0b45ccu: goto P_0c0b45cc;
case 0x0c0b45ceu: goto P_0c0b45ce;
case 0x0c0b45d0u: goto P_0c0b45d0;
case 0x0c0b45d2u: goto P_0c0b45d2;
case 0x0c0b45d4u: goto P_0c0b45d4;
case 0x0c0b45d6u: goto P_0c0b45d6;
case 0x0c0b45d8u: goto P_0c0b45d8;
case 0x0c0b45dau: goto P_0c0b45da;
case 0x0c0b45dcu: goto P_0c0b45dc;
case 0x0c0b45deu: goto P_0c0b45de;
case 0x0c0b45e0u: goto P_0c0b45e0;
case 0x0c0b45e2u: goto P_0c0b45e2;
case 0x0c0b45e4u: goto P_0c0b45e4;
case 0x0c0b45e6u: goto P_0c0b45e6;
case 0x0c0b45e8u: goto P_0c0b45e8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a2e06: /* original d359, guest PC 0x0c0a2e06 */
if(!s->budget--) { s->failed_pc=0x0c0a2e06u; return 0; }
r[3]=read(ram,0x0c0a2f6cu,4);
goto P_0c0a2e08;
P_0c0a2e08: /* original 6643, guest PC 0x0c0a2e08 */
if(!s->budget--) { s->failed_pc=0x0c0a2e08u; return 0; }
r[6]=r[4];
goto P_0c0a2e0a;
P_0c0a2e0a: /* original 4608, guest PC 0x0c0a2e0a */
if(!s->budget--) { s->failed_pc=0x0c0a2e0au; return 0; }
r[6]<<=2;
goto P_0c0a2e0c;
P_0c0a2e0c: /* original 363c, guest PC 0x0c0a2e0c */
if(!s->budget--) { s->failed_pc=0x0c0a2e0cu; return 0; }
r[6]+=r[3];
goto P_0c0a2e0e;
P_0c0a2e0e: /* original 6262, guest PC 0x0c0a2e0e */
if(!s->budget--) { s->failed_pc=0x0c0a2e0eu; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0a2e10;
P_0c0a2e10: /* original 2228, guest PC 0x0c0a2e10 */
if(!s->budget--) { s->failed_pc=0x0c0a2e10u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2e12;
P_0c0a2e12: /* original 8b09, guest PC 0x0c0a2e12 */
if(!s->budget--) { s->failed_pc=0x0c0a2e12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2e28; }
goto P_0c0a2e14;
P_0c0a2e14: /* original 6062, guest PC 0x0c0a2e14 */
if(!s->budget--) { s->failed_pc=0x0c0a2e14u; return 0; }
tmp=read(ram,r[6],4);
r[0]=tmp;
goto P_0c0a2e16;
P_0c0a2e16: /* original 88ff, guest PC 0x0c0a2e16 */
if(!s->budget--) { s->failed_pc=0x0c0a2e16u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0a2e18;
P_0c0a2e18: /* original 8906, guest PC 0x0c0a2e18 */
if(!s->budget--) { s->failed_pc=0x0c0a2e18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2e28; }
goto P_0c0a2e1a;
P_0c0a2e1a: /* original 5051, guest PC 0x0c0a2e1a */
if(!s->budget--) { s->failed_pc=0x0c0a2e1au; return 0; }
r[0]=read(ram,r[5]+4,4);
goto P_0c0a2e1c;
P_0c0a2e1c: /* original c801, guest PC 0x0c0a2e1c */
if(!s->budget--) { s->failed_pc=0x0c0a2e1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a2e1e;
P_0c0a2e1e: /* original 8901, guest PC 0x0c0a2e1e */
if(!s->budget--) { s->failed_pc=0x0c0a2e1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2e24; }
goto P_0c0a2e20;
P_0c0a2e20: /* original a002, guest PC 0x0c0a2e20 */
if(!s->budget--) { s->failed_pc=0x0c0a2e20u; return 0; }
write(ram,r[6],r[5],4);
goto P_0c0a2e28;
P_0c0a2e22: /* original 2652, guest PC 0x0c0a2e22 */
if(!s->budget--) { s->failed_pc=0x0c0a2e22u; return 0; }
write(ram,r[6],r[5],4);
goto P_0c0a2e24;
P_0c0a2e24: /* original 6152, guest PC 0x0c0a2e24 */
if(!s->budget--) { s->failed_pc=0x0c0a2e24u; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c0a2e26;
P_0c0a2e26: /* original 2612, guest PC 0x0c0a2e26 */
if(!s->budget--) { s->failed_pc=0x0c0a2e26u; return 0; }
write(ram,r[6],r[1],4);
goto P_0c0a2e28;
P_0c0a2e28: /* original 000b, guest PC 0x0c0a2e28 */
if(!s->budget--) { s->failed_pc=0x0c0a2e28u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a2e2a: /* original 0009, guest PC 0x0c0a2e2a */
if(!s->budget--) { s->failed_pc=0x0c0a2e2au; return 0; }
if(!vf3_matrix_family(0x0c0a2e2cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2e2cu; return 0; } return 1;
P_0c0b41d6: /* original 2fe6, guest PC 0x0c0b41d6 */
if(!s->budget--) { s->failed_pc=0x0c0b41d6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b41d8;
P_0c0b41d8: /* original 2fd6, guest PC 0x0c0b41d8 */
if(!s->budget--) { s->failed_pc=0x0c0b41d8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b41da;
P_0c0b41da: /* original 2fc6, guest PC 0x0c0b41da */
if(!s->budget--) { s->failed_pc=0x0c0b41dau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b41dc;
P_0c0b41dc: /* original 2fb6, guest PC 0x0c0b41dc */
if(!s->budget--) { s->failed_pc=0x0c0b41dcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b41de;
P_0c0b41de: /* original 2fa6, guest PC 0x0c0b41de */
if(!s->budget--) { s->failed_pc=0x0c0b41deu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b41e0;
P_0c0b41e0: /* original 2f96, guest PC 0x0c0b41e0 */
if(!s->budget--) { s->failed_pc=0x0c0b41e0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b41e2;
P_0c0b41e2: /* original 4f22, guest PC 0x0c0b41e2 */
if(!s->budget--) { s->failed_pc=0x0c0b41e2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b41e4;
P_0c0b41e4: /* original 5d44, guest PC 0x0c0b41e4 */
if(!s->budget--) { s->failed_pc=0x0c0b41e4u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0b41e6;
P_0c0b41e6: /* original 94a8, guest PC 0x0c0b41e6 */
if(!s->budget--) { s->failed_pc=0x0c0b41e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b433au,2);
goto P_0c0b41e8;
P_0c0b41e8: /* original de6e, guest PC 0x0c0b41e8 */
if(!s->budget--) { s->failed_pc=0x0c0b41e8u; return 0; }
r[14]=read(ram,0x0c0b43a4u,4);
goto P_0c0b41ea;
P_0c0b41ea: /* original 7ff8, guest PC 0x0c0b41ea */
if(!s->budget--) { s->failed_pc=0x0c0b41eau; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0b41ec;
P_0c0b41ec: /* original 4e0b, guest PC 0x0c0b41ec */
if(!s->budget--) { s->failed_pc=0x0c0b41ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b41f0u;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b41f0u) { target=s->pc; goto dispatch; }
goto P_0c0b41f0;
P_0c0b41ee: /* original 65d2, guest PC 0x0c0b41ee */
if(!s->budget--) { s->failed_pc=0x0c0b41eeu; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0b41f0;
P_0c0b41f0: /* original 94a4, guest PC 0x0c0b41f0 */
if(!s->budget--) { s->failed_pc=0x0c0b41f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b433cu,2);
goto P_0c0b41f2;
P_0c0b41f2: /* original 4e0b, guest PC 0x0c0b41f2 */
if(!s->budget--) { s->failed_pc=0x0c0b41f2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b41f6u;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b41f6u) { target=s->pc; goto dispatch; }
goto P_0c0b41f6;
P_0c0b41f4: /* original 55d1, guest PC 0x0c0b41f4 */
if(!s->budget--) { s->failed_pc=0x0c0b41f4u; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0b41f6;
P_0c0b41f6: /* original 94a2, guest PC 0x0c0b41f6 */
if(!s->budget--) { s->failed_pc=0x0c0b41f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b433eu,2);
goto P_0c0b41f8;
P_0c0b41f8: /* original 4e0b, guest PC 0x0c0b41f8 */
if(!s->budget--) { s->failed_pc=0x0c0b41f8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b41fcu;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b41fcu) { target=s->pc; goto dispatch; }
goto P_0c0b41fc;
P_0c0b41fa: /* original 55d2, guest PC 0x0c0b41fa */
if(!s->budget--) { s->failed_pc=0x0c0b41fau; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0b41fc;
P_0c0b41fc: /* original 94a0, guest PC 0x0c0b41fc */
if(!s->budget--) { s->failed_pc=0x0c0b41fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4340u,2);
goto P_0c0b41fe;
P_0c0b41fe: /* original 4e0b, guest PC 0x0c0b41fe */
if(!s->budget--) { s->failed_pc=0x0c0b41feu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4202u;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4202u) { target=s->pc; goto dispatch; }
goto P_0c0b4202;
P_0c0b4200: /* original 55d3, guest PC 0x0c0b4200 */
if(!s->budget--) { s->failed_pc=0x0c0b4200u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0b4202;
P_0c0b4202: /* original 949e, guest PC 0x0c0b4202 */
if(!s->budget--) { s->failed_pc=0x0c0b4202u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4342u,2);
goto P_0c0b4204;
P_0c0b4204: /* original 4e0b, guest PC 0x0c0b4204 */
if(!s->budget--) { s->failed_pc=0x0c0b4204u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4208u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4208u) { target=s->pc; goto dispatch; }
goto P_0c0b4208;
P_0c0b4206: /* original 55d4, guest PC 0x0c0b4206 */
if(!s->budget--) { s->failed_pc=0x0c0b4206u; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0b4208;
P_0c0b4208: /* original 949c, guest PC 0x0c0b4208 */
if(!s->budget--) { s->failed_pc=0x0c0b4208u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4344u,2);
goto P_0c0b420a;
P_0c0b420a: /* original 4e0b, guest PC 0x0c0b420a */
if(!s->budget--) { s->failed_pc=0x0c0b420au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b420eu;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b420eu) { target=s->pc; goto dispatch; }
goto P_0c0b420e;
P_0c0b420c: /* original 55d5, guest PC 0x0c0b420c */
if(!s->budget--) { s->failed_pc=0x0c0b420cu; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0b420e;
P_0c0b420e: /* original 949a, guest PC 0x0c0b420e */
if(!s->budget--) { s->failed_pc=0x0c0b420eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4346u,2);
goto P_0c0b4210;
P_0c0b4210: /* original 4e0b, guest PC 0x0c0b4210 */
if(!s->budget--) { s->failed_pc=0x0c0b4210u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4214u;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4214u) { target=s->pc; goto dispatch; }
goto P_0c0b4214;
P_0c0b4212: /* original 55d6, guest PC 0x0c0b4212 */
if(!s->budget--) { s->failed_pc=0x0c0b4212u; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0b4214;
P_0c0b4214: /* original 9498, guest PC 0x0c0b4214 */
if(!s->budget--) { s->failed_pc=0x0c0b4214u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4348u,2);
goto P_0c0b4216;
P_0c0b4216: /* original 4e0b, guest PC 0x0c0b4216 */
if(!s->budget--) { s->failed_pc=0x0c0b4216u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b421au;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b421au) { target=s->pc; goto dispatch; }
goto P_0c0b421a;
P_0c0b4218: /* original 55d7, guest PC 0x0c0b4218 */
if(!s->budget--) { s->failed_pc=0x0c0b4218u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0b421a;
P_0c0b421a: /* original 9496, guest PC 0x0c0b421a */
if(!s->budget--) { s->failed_pc=0x0c0b421au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b434au,2);
goto P_0c0b421c;
P_0c0b421c: /* original 4e0b, guest PC 0x0c0b421c */
if(!s->budget--) { s->failed_pc=0x0c0b421cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4220u;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4220u) { target=s->pc; goto dispatch; }
goto P_0c0b4220;
P_0c0b421e: /* original 55d8, guest PC 0x0c0b421e */
if(!s->budget--) { s->failed_pc=0x0c0b421eu; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0b4220;
P_0c0b4220: /* original 9494, guest PC 0x0c0b4220 */
if(!s->budget--) { s->failed_pc=0x0c0b4220u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b434cu,2);
goto P_0c0b4222;
P_0c0b4222: /* original 4e0b, guest PC 0x0c0b4222 */
if(!s->budget--) { s->failed_pc=0x0c0b4222u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4226u;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4226u) { target=s->pc; goto dispatch; }
goto P_0c0b4226;
P_0c0b4224: /* original 55d9, guest PC 0x0c0b4224 */
if(!s->budget--) { s->failed_pc=0x0c0b4224u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0b4226;
P_0c0b4226: /* original 9492, guest PC 0x0c0b4226 */
if(!s->budget--) { s->failed_pc=0x0c0b4226u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b434eu,2);
goto P_0c0b4228;
P_0c0b4228: /* original 4e0b, guest PC 0x0c0b4228 */
if(!s->budget--) { s->failed_pc=0x0c0b4228u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b422cu;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b422cu) { target=s->pc; goto dispatch; }
goto P_0c0b422c;
P_0c0b422a: /* original 55da, guest PC 0x0c0b422a */
if(!s->budget--) { s->failed_pc=0x0c0b422au; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0b422c;
P_0c0b422c: /* original 9490, guest PC 0x0c0b422c */
if(!s->budget--) { s->failed_pc=0x0c0b422cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4350u,2);
goto P_0c0b422e;
P_0c0b422e: /* original 4e0b, guest PC 0x0c0b422e */
if(!s->budget--) { s->failed_pc=0x0c0b422eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4232u;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4232u) { target=s->pc; goto dispatch; }
goto P_0c0b4232;
P_0c0b4230: /* original 55db, guest PC 0x0c0b4230 */
if(!s->budget--) { s->failed_pc=0x0c0b4230u; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0b4232;
P_0c0b4232: /* original 948e, guest PC 0x0c0b4232 */
if(!s->budget--) { s->failed_pc=0x0c0b4232u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4352u,2);
goto P_0c0b4234;
P_0c0b4234: /* original 4e0b, guest PC 0x0c0b4234 */
if(!s->budget--) { s->failed_pc=0x0c0b4234u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4238u;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4238u) { target=s->pc; goto dispatch; }
goto P_0c0b4238;
P_0c0b4236: /* original 55dc, guest PC 0x0c0b4236 */
if(!s->budget--) { s->failed_pc=0x0c0b4236u; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0b4238;
P_0c0b4238: /* original 948c, guest PC 0x0c0b4238 */
if(!s->budget--) { s->failed_pc=0x0c0b4238u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4354u,2);
goto P_0c0b423a;
P_0c0b423a: /* original 4e0b, guest PC 0x0c0b423a */
if(!s->budget--) { s->failed_pc=0x0c0b423au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b423eu;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b423eu) { target=s->pc; goto dispatch; }
goto P_0c0b423e;
P_0c0b423c: /* original 55dd, guest PC 0x0c0b423c */
if(!s->budget--) { s->failed_pc=0x0c0b423cu; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0b423e;
P_0c0b423e: /* original 948a, guest PC 0x0c0b423e */
if(!s->budget--) { s->failed_pc=0x0c0b423eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4356u,2);
goto P_0c0b4240;
P_0c0b4240: /* original 4e0b, guest PC 0x0c0b4240 */
if(!s->budget--) { s->failed_pc=0x0c0b4240u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4244u;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4244u) { target=s->pc; goto dispatch; }
goto P_0c0b4244;
P_0c0b4242: /* original 55de, guest PC 0x0c0b4242 */
if(!s->budget--) { s->failed_pc=0x0c0b4242u; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0b4244;
P_0c0b4244: /* original 9488, guest PC 0x0c0b4244 */
if(!s->budget--) { s->failed_pc=0x0c0b4244u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4358u,2);
goto P_0c0b4246;
P_0c0b4246: /* original 4e0b, guest PC 0x0c0b4246 */
if(!s->budget--) { s->failed_pc=0x0c0b4246u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b424au;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b424au) { target=s->pc; goto dispatch; }
goto P_0c0b424a;
P_0c0b4248: /* original 55df, guest PC 0x0c0b4248 */
if(!s->budget--) { s->failed_pc=0x0c0b4248u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0b424a;
P_0c0b424a: /* original 9486, guest PC 0x0c0b424a */
if(!s->budget--) { s->failed_pc=0x0c0b424au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b435au,2);
goto P_0c0b424c;
P_0c0b424c: /* original e040, guest PC 0x0c0b424c */
if(!s->budget--) { s->failed_pc=0x0c0b424cu; return 0; }
r[0]=0x00000040u;
goto P_0c0b424e;
P_0c0b424e: /* original 4e0b, guest PC 0x0c0b424e */
if(!s->budget--) { s->failed_pc=0x0c0b424eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4252u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4252u) { target=s->pc; goto dispatch; }
goto P_0c0b4252;
P_0c0b4250: /* original 05de, guest PC 0x0c0b4250 */
if(!s->budget--) { s->failed_pc=0x0c0b4250u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4252;
P_0c0b4252: /* original 9483, guest PC 0x0c0b4252 */
if(!s->budget--) { s->failed_pc=0x0c0b4252u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b435cu,2);
goto P_0c0b4254;
P_0c0b4254: /* original e044, guest PC 0x0c0b4254 */
if(!s->budget--) { s->failed_pc=0x0c0b4254u; return 0; }
r[0]=0x00000044u;
goto P_0c0b4256;
P_0c0b4256: /* original 4e0b, guest PC 0x0c0b4256 */
if(!s->budget--) { s->failed_pc=0x0c0b4256u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b425au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b425au) { target=s->pc; goto dispatch; }
goto P_0c0b425a;
P_0c0b4258: /* original 05de, guest PC 0x0c0b4258 */
if(!s->budget--) { s->failed_pc=0x0c0b4258u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b425a;
P_0c0b425a: /* original 9480, guest PC 0x0c0b425a */
if(!s->budget--) { s->failed_pc=0x0c0b425au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b435eu,2);
goto P_0c0b425c;
P_0c0b425c: /* original e048, guest PC 0x0c0b425c */
if(!s->budget--) { s->failed_pc=0x0c0b425cu; return 0; }
r[0]=0x00000048u;
goto P_0c0b425e;
P_0c0b425e: /* original 4e0b, guest PC 0x0c0b425e */
if(!s->budget--) { s->failed_pc=0x0c0b425eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4262u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4262u) { target=s->pc; goto dispatch; }
goto P_0c0b4262;
P_0c0b4260: /* original 05de, guest PC 0x0c0b4260 */
if(!s->budget--) { s->failed_pc=0x0c0b4260u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4262;
P_0c0b4262: /* original 947d, guest PC 0x0c0b4262 */
if(!s->budget--) { s->failed_pc=0x0c0b4262u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4360u,2);
goto P_0c0b4264;
P_0c0b4264: /* original e04c, guest PC 0x0c0b4264 */
if(!s->budget--) { s->failed_pc=0x0c0b4264u; return 0; }
r[0]=0x0000004cu;
goto P_0c0b4266;
P_0c0b4266: /* original 4e0b, guest PC 0x0c0b4266 */
if(!s->budget--) { s->failed_pc=0x0c0b4266u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b426au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b426au) { target=s->pc; goto dispatch; }
goto P_0c0b426a;
P_0c0b4268: /* original 05de, guest PC 0x0c0b4268 */
if(!s->budget--) { s->failed_pc=0x0c0b4268u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b426a;
P_0c0b426a: /* original 947a, guest PC 0x0c0b426a */
if(!s->budget--) { s->failed_pc=0x0c0b426au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4362u,2);
goto P_0c0b426c;
P_0c0b426c: /* original e050, guest PC 0x0c0b426c */
if(!s->budget--) { s->failed_pc=0x0c0b426cu; return 0; }
r[0]=0x00000050u;
goto P_0c0b426e;
P_0c0b426e: /* original 4e0b, guest PC 0x0c0b426e */
if(!s->budget--) { s->failed_pc=0x0c0b426eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4272u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4272u) { target=s->pc; goto dispatch; }
goto P_0c0b4272;
P_0c0b4270: /* original 05de, guest PC 0x0c0b4270 */
if(!s->budget--) { s->failed_pc=0x0c0b4270u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4272;
P_0c0b4272: /* original 9477, guest PC 0x0c0b4272 */
if(!s->budget--) { s->failed_pc=0x0c0b4272u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4364u,2);
goto P_0c0b4274;
P_0c0b4274: /* original e054, guest PC 0x0c0b4274 */
if(!s->budget--) { s->failed_pc=0x0c0b4274u; return 0; }
r[0]=0x00000054u;
goto P_0c0b4276;
P_0c0b4276: /* original 4e0b, guest PC 0x0c0b4276 */
if(!s->budget--) { s->failed_pc=0x0c0b4276u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b427au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b427au) { target=s->pc; goto dispatch; }
goto P_0c0b427a;
P_0c0b4278: /* original 05de, guest PC 0x0c0b4278 */
if(!s->budget--) { s->failed_pc=0x0c0b4278u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b427a;
P_0c0b427a: /* original 9474, guest PC 0x0c0b427a */
if(!s->budget--) { s->failed_pc=0x0c0b427au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4366u,2);
goto P_0c0b427c;
P_0c0b427c: /* original e058, guest PC 0x0c0b427c */
if(!s->budget--) { s->failed_pc=0x0c0b427cu; return 0; }
r[0]=0x00000058u;
goto P_0c0b427e;
P_0c0b427e: /* original 4e0b, guest PC 0x0c0b427e */
if(!s->budget--) { s->failed_pc=0x0c0b427eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4282u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4282u) { target=s->pc; goto dispatch; }
goto P_0c0b4282;
P_0c0b4280: /* original 05de, guest PC 0x0c0b4280 */
if(!s->budget--) { s->failed_pc=0x0c0b4280u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4282;
P_0c0b4282: /* original 9471, guest PC 0x0c0b4282 */
if(!s->budget--) { s->failed_pc=0x0c0b4282u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4368u,2);
goto P_0c0b4284;
P_0c0b4284: /* original e05c, guest PC 0x0c0b4284 */
if(!s->budget--) { s->failed_pc=0x0c0b4284u; return 0; }
r[0]=0x0000005cu;
goto P_0c0b4286;
P_0c0b4286: /* original 4e0b, guest PC 0x0c0b4286 */
if(!s->budget--) { s->failed_pc=0x0c0b4286u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b428au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b428au) { target=s->pc; goto dispatch; }
goto P_0c0b428a;
P_0c0b4288: /* original 05de, guest PC 0x0c0b4288 */
if(!s->budget--) { s->failed_pc=0x0c0b4288u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b428a;
P_0c0b428a: /* original 946e, guest PC 0x0c0b428a */
if(!s->budget--) { s->failed_pc=0x0c0b428au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b436au,2);
goto P_0c0b428c;
P_0c0b428c: /* original e060, guest PC 0x0c0b428c */
if(!s->budget--) { s->failed_pc=0x0c0b428cu; return 0; }
r[0]=0x00000060u;
goto P_0c0b428e;
P_0c0b428e: /* original 4e0b, guest PC 0x0c0b428e */
if(!s->budget--) { s->failed_pc=0x0c0b428eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4292u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4292u) { target=s->pc; goto dispatch; }
goto P_0c0b4292;
P_0c0b4290: /* original 05de, guest PC 0x0c0b4290 */
if(!s->budget--) { s->failed_pc=0x0c0b4290u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4292;
P_0c0b4292: /* original 946b, guest PC 0x0c0b4292 */
if(!s->budget--) { s->failed_pc=0x0c0b4292u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b436cu,2);
goto P_0c0b4294;
P_0c0b4294: /* original e064, guest PC 0x0c0b4294 */
if(!s->budget--) { s->failed_pc=0x0c0b4294u; return 0; }
r[0]=0x00000064u;
goto P_0c0b4296;
P_0c0b4296: /* original 4e0b, guest PC 0x0c0b4296 */
if(!s->budget--) { s->failed_pc=0x0c0b4296u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b429au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b429au) { target=s->pc; goto dispatch; }
goto P_0c0b429a;
P_0c0b4298: /* original 05de, guest PC 0x0c0b4298 */
if(!s->budget--) { s->failed_pc=0x0c0b4298u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b429a;
P_0c0b429a: /* original 9468, guest PC 0x0c0b429a */
if(!s->budget--) { s->failed_pc=0x0c0b429au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b436eu,2);
goto P_0c0b429c;
P_0c0b429c: /* original e068, guest PC 0x0c0b429c */
if(!s->budget--) { s->failed_pc=0x0c0b429cu; return 0; }
r[0]=0x00000068u;
goto P_0c0b429e;
P_0c0b429e: /* original 4e0b, guest PC 0x0c0b429e */
if(!s->budget--) { s->failed_pc=0x0c0b429eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b42a2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b42a2u) { target=s->pc; goto dispatch; }
goto P_0c0b42a2;
P_0c0b42a0: /* original 05de, guest PC 0x0c0b42a0 */
if(!s->budget--) { s->failed_pc=0x0c0b42a0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b42a2;
P_0c0b42a2: /* original 9465, guest PC 0x0c0b42a2 */
if(!s->budget--) { s->failed_pc=0x0c0b42a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4370u,2);
goto P_0c0b42a4;
P_0c0b42a4: /* original e06c, guest PC 0x0c0b42a4 */
if(!s->budget--) { s->failed_pc=0x0c0b42a4u; return 0; }
r[0]=0x0000006cu;
goto P_0c0b42a6;
P_0c0b42a6: /* original 4e0b, guest PC 0x0c0b42a6 */
if(!s->budget--) { s->failed_pc=0x0c0b42a6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b42aau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b42aau) { target=s->pc; goto dispatch; }
goto P_0c0b42aa;
P_0c0b42a8: /* original 05de, guest PC 0x0c0b42a8 */
if(!s->budget--) { s->failed_pc=0x0c0b42a8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b42aa;
P_0c0b42aa: /* original 9462, guest PC 0x0c0b42aa */
if(!s->budget--) { s->failed_pc=0x0c0b42aau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4372u,2);
goto P_0c0b42ac;
P_0c0b42ac: /* original e070, guest PC 0x0c0b42ac */
if(!s->budget--) { s->failed_pc=0x0c0b42acu; return 0; }
r[0]=0x00000070u;
goto P_0c0b42ae;
P_0c0b42ae: /* original 4e0b, guest PC 0x0c0b42ae */
if(!s->budget--) { s->failed_pc=0x0c0b42aeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b42b2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b42b2u) { target=s->pc; goto dispatch; }
goto P_0c0b42b2;
P_0c0b42b0: /* original 05de, guest PC 0x0c0b42b0 */
if(!s->budget--) { s->failed_pc=0x0c0b42b0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b42b2;
P_0c0b42b2: /* original 945f, guest PC 0x0c0b42b2 */
if(!s->budget--) { s->failed_pc=0x0c0b42b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4374u,2);
goto P_0c0b42b4;
P_0c0b42b4: /* original e074, guest PC 0x0c0b42b4 */
if(!s->budget--) { s->failed_pc=0x0c0b42b4u; return 0; }
r[0]=0x00000074u;
goto P_0c0b42b6;
P_0c0b42b6: /* original 4e0b, guest PC 0x0c0b42b6 */
if(!s->budget--) { s->failed_pc=0x0c0b42b6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b42bau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b42bau) { target=s->pc; goto dispatch; }
goto P_0c0b42ba;
P_0c0b42b8: /* original 05de, guest PC 0x0c0b42b8 */
if(!s->budget--) { s->failed_pc=0x0c0b42b8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b42ba;
P_0c0b42ba: /* original 945c, guest PC 0x0c0b42ba */
if(!s->budget--) { s->failed_pc=0x0c0b42bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4376u,2);
goto P_0c0b42bc;
P_0c0b42bc: /* original e078, guest PC 0x0c0b42bc */
if(!s->budget--) { s->failed_pc=0x0c0b42bcu; return 0; }
r[0]=0x00000078u;
goto P_0c0b42be;
P_0c0b42be: /* original 4e0b, guest PC 0x0c0b42be */
if(!s->budget--) { s->failed_pc=0x0c0b42beu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b42c2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b42c2u) { target=s->pc; goto dispatch; }
goto P_0c0b42c2;
P_0c0b42c0: /* original 05de, guest PC 0x0c0b42c0 */
if(!s->budget--) { s->failed_pc=0x0c0b42c0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b42c2;
P_0c0b42c2: /* original 9459, guest PC 0x0c0b42c2 */
if(!s->budget--) { s->failed_pc=0x0c0b42c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4378u,2);
goto P_0c0b42c4;
P_0c0b42c4: /* original e07c, guest PC 0x0c0b42c4 */
if(!s->budget--) { s->failed_pc=0x0c0b42c4u; return 0; }
r[0]=0x0000007cu;
goto P_0c0b42c6;
P_0c0b42c6: /* original 4e0b, guest PC 0x0c0b42c6 */
if(!s->budget--) { s->failed_pc=0x0c0b42c6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b42cau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b42cau) { target=s->pc; goto dispatch; }
goto P_0c0b42ca;
P_0c0b42c8: /* original 05de, guest PC 0x0c0b42c8 */
if(!s->budget--) { s->failed_pc=0x0c0b42c8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b42ca;
P_0c0b42ca: /* original 9457, guest PC 0x0c0b42ca */
if(!s->budget--) { s->failed_pc=0x0c0b42cau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b437cu,2);
goto P_0c0b42cc;
P_0c0b42cc: /* original 9055, guest PC 0x0c0b42cc */
if(!s->budget--) { s->failed_pc=0x0c0b42ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b437au,2);
goto P_0c0b42ce;
P_0c0b42ce: /* original 4e0b, guest PC 0x0c0b42ce */
if(!s->budget--) { s->failed_pc=0x0c0b42ceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b42d2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b42d2u) { target=s->pc; goto dispatch; }
goto P_0c0b42d2;
P_0c0b42d0: /* original 05de, guest PC 0x0c0b42d0 */
if(!s->budget--) { s->failed_pc=0x0c0b42d0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b42d2;
P_0c0b42d2: /* original 9554, guest PC 0x0c0b42d2 */
if(!s->budget--) { s->failed_pc=0x0c0b42d2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b437eu,2);
goto P_0c0b42d4;
P_0c0b42d4: /* original 35dc, guest PC 0x0c0b42d4 */
if(!s->budget--) { s->failed_pc=0x0c0b42d4u; return 0; }
r[5]+=r[13];
goto P_0c0b42d6;
P_0c0b42d6: /* original 2f52, guest PC 0x0c0b42d6 */
if(!s->budget--) { s->failed_pc=0x0c0b42d6u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b42d8;
P_0c0b42d8: /* original 9452, guest PC 0x0c0b42d8 */
if(!s->budget--) { s->failed_pc=0x0c0b42d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4380u,2);
goto P_0c0b42da;
P_0c0b42da: /* original 4e0b, guest PC 0x0c0b42da */
if(!s->budget--) { s->failed_pc=0x0c0b42dau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b42deu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b42deu) { target=s->pc; goto dispatch; }
goto P_0c0b42de;
P_0c0b42dc: /* original 6552, guest PC 0x0c0b42dc */
if(!s->budget--) { s->failed_pc=0x0c0b42dcu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b42de;
P_0c0b42de: /* original 9550, guest PC 0x0c0b42de */
if(!s->budget--) { s->failed_pc=0x0c0b42deu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4382u,2);
goto P_0c0b42e0;
P_0c0b42e0: /* original 35dc, guest PC 0x0c0b42e0 */
if(!s->budget--) { s->failed_pc=0x0c0b42e0u; return 0; }
r[5]+=r[13];
goto P_0c0b42e2;
P_0c0b42e2: /* original 1f51, guest PC 0x0c0b42e2 */
if(!s->budget--) { s->failed_pc=0x0c0b42e2u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0b42e4;
P_0c0b42e4: /* original 944e, guest PC 0x0c0b42e4 */
if(!s->budget--) { s->failed_pc=0x0c0b42e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4384u,2);
goto P_0c0b42e6;
P_0c0b42e6: /* original 4e0b, guest PC 0x0c0b42e6 */
if(!s->budget--) { s->failed_pc=0x0c0b42e6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b42eau;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b42eau) { target=s->pc; goto dispatch; }
goto P_0c0b42ea;
P_0c0b42e8: /* original 6552, guest PC 0x0c0b42e8 */
if(!s->budget--) { s->failed_pc=0x0c0b42e8u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b42ea;
P_0c0b42ea: /* original 944d, guest PC 0x0c0b42ea */
if(!s->budget--) { s->failed_pc=0x0c0b42eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4388u,2);
goto P_0c0b42ec;
P_0c0b42ec: /* original 904b, guest PC 0x0c0b42ec */
if(!s->budget--) { s->failed_pc=0x0c0b42ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4386u,2);
goto P_0c0b42ee;
P_0c0b42ee: /* original 4e0b, guest PC 0x0c0b42ee */
if(!s->budget--) { s->failed_pc=0x0c0b42eeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b42f2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b42f2u) { target=s->pc; goto dispatch; }
goto P_0c0b42f2;
P_0c0b42f0: /* original 05de, guest PC 0x0c0b42f0 */
if(!s->budget--) { s->failed_pc=0x0c0b42f0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b42f2;
P_0c0b42f2: /* original 944b, guest PC 0x0c0b42f2 */
if(!s->budget--) { s->failed_pc=0x0c0b42f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b438cu,2);
goto P_0c0b42f4;
P_0c0b42f4: /* original 9049, guest PC 0x0c0b42f4 */
if(!s->budget--) { s->failed_pc=0x0c0b42f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b438au,2);
goto P_0c0b42f6;
P_0c0b42f6: /* original 4e0b, guest PC 0x0c0b42f6 */
if(!s->budget--) { s->failed_pc=0x0c0b42f6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b42fau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b42fau) { target=s->pc; goto dispatch; }
goto P_0c0b42fa;
P_0c0b42f8: /* original 05de, guest PC 0x0c0b42f8 */
if(!s->budget--) { s->failed_pc=0x0c0b42f8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b42fa;
P_0c0b42fa: /* original 9948, guest PC 0x0c0b42fa */
if(!s->budget--) { s->failed_pc=0x0c0b42fau; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b438eu,2);
goto P_0c0b42fc;
P_0c0b42fc: /* original 9448, guest PC 0x0c0b42fc */
if(!s->budget--) { s->failed_pc=0x0c0b42fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4390u,2);
goto P_0c0b42fe;
P_0c0b42fe: /* original 39dc, guest PC 0x0c0b42fe */
if(!s->budget--) { s->failed_pc=0x0c0b42feu; return 0; }
r[9]+=r[13];
goto P_0c0b4300;
P_0c0b4300: /* original 4e0b, guest PC 0x0c0b4300 */
if(!s->budget--) { s->failed_pc=0x0c0b4300u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4304u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4304u) { target=s->pc; goto dispatch; }
goto P_0c0b4304;
P_0c0b4302: /* original 6592, guest PC 0x0c0b4302 */
if(!s->budget--) { s->failed_pc=0x0c0b4302u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b4304;
P_0c0b4304: /* original 9445, guest PC 0x0c0b4304 */
if(!s->budget--) { s->failed_pc=0x0c0b4304u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4392u,2);
goto P_0c0b4306;
P_0c0b4306: /* original 4e0b, guest PC 0x0c0b4306 */
if(!s->budget--) { s->failed_pc=0x0c0b4306u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b430au;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b430au) { target=s->pc; goto dispatch; }
goto P_0c0b430a;
P_0c0b4308: /* original 6592, guest PC 0x0c0b4308 */
if(!s->budget--) { s->failed_pc=0x0c0b4308u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b430a;
P_0c0b430a: /* original 9443, guest PC 0x0c0b430a */
if(!s->budget--) { s->failed_pc=0x0c0b430au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4394u,2);
goto P_0c0b430c;
P_0c0b430c: /* original 4e0b, guest PC 0x0c0b430c */
if(!s->budget--) { s->failed_pc=0x0c0b430cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4310u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4310u) { target=s->pc; goto dispatch; }
goto P_0c0b4310;
P_0c0b430e: /* original 6592, guest PC 0x0c0b430e */
if(!s->budget--) { s->failed_pc=0x0c0b430eu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b4310;
P_0c0b4310: /* original 9441, guest PC 0x0c0b4310 */
if(!s->budget--) { s->failed_pc=0x0c0b4310u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4396u,2);
goto P_0c0b4312;
P_0c0b4312: /* original 4e0b, guest PC 0x0c0b4312 */
if(!s->budget--) { s->failed_pc=0x0c0b4312u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4316u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4316u) { target=s->pc; goto dispatch; }
goto P_0c0b4316;
P_0c0b4314: /* original 6592, guest PC 0x0c0b4314 */
if(!s->budget--) { s->failed_pc=0x0c0b4314u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b4316;
P_0c0b4316: /* original 9c3f, guest PC 0x0c0b4316 */
if(!s->budget--) { s->failed_pc=0x0c0b4316u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4398u,2);
goto P_0c0b4318;
P_0c0b4318: /* original 943f, guest PC 0x0c0b4318 */
if(!s->budget--) { s->failed_pc=0x0c0b4318u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b439au,2);
goto P_0c0b431a;
P_0c0b431a: /* original 3cdc, guest PC 0x0c0b431a */
if(!s->budget--) { s->failed_pc=0x0c0b431au; return 0; }
r[12]+=r[13];
goto P_0c0b431c;
P_0c0b431c: /* original 4e0b, guest PC 0x0c0b431c */
if(!s->budget--) { s->failed_pc=0x0c0b431cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4320u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4320u) { target=s->pc; goto dispatch; }
goto P_0c0b4320;
P_0c0b431e: /* original 65c2, guest PC 0x0c0b431e */
if(!s->budget--) { s->failed_pc=0x0c0b431eu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b4320;
P_0c0b4320: /* original 943c, guest PC 0x0c0b4320 */
if(!s->budget--) { s->failed_pc=0x0c0b4320u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b439cu,2);
goto P_0c0b4322;
P_0c0b4322: /* original 4e0b, guest PC 0x0c0b4322 */
if(!s->budget--) { s->failed_pc=0x0c0b4322u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4326u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4326u) { target=s->pc; goto dispatch; }
goto P_0c0b4326;
P_0c0b4324: /* original 65c2, guest PC 0x0c0b4324 */
if(!s->budget--) { s->failed_pc=0x0c0b4324u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b4326;
P_0c0b4326: /* original 943a, guest PC 0x0c0b4326 */
if(!s->budget--) { s->failed_pc=0x0c0b4326u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b439eu,2);
goto P_0c0b4328;
P_0c0b4328: /* original 4e0b, guest PC 0x0c0b4328 */
if(!s->budget--) { s->failed_pc=0x0c0b4328u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b432cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b432cu) { target=s->pc; goto dispatch; }
goto P_0c0b432c;
P_0c0b432a: /* original 65c2, guest PC 0x0c0b432a */
if(!s->budget--) { s->failed_pc=0x0c0b432au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b432c;
P_0c0b432c: /* original 9438, guest PC 0x0c0b432c */
if(!s->budget--) { s->failed_pc=0x0c0b432cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b43a0u,2);
goto P_0c0b432e;
P_0c0b432e: /* original 4e0b, guest PC 0x0c0b432e */
if(!s->budget--) { s->failed_pc=0x0c0b432eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4332u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4332u) { target=s->pc; goto dispatch; }
goto P_0c0b4332;
P_0c0b4330: /* original 65c2, guest PC 0x0c0b4330 */
if(!s->budget--) { s->failed_pc=0x0c0b4330u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b4332;
P_0c0b4332: /* original 9b36, guest PC 0x0c0b4332 */
if(!s->budget--) { s->failed_pc=0x0c0b4332u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b43a2u,2);
goto P_0c0b4334;
P_0c0b4334: /* original 3bdc, guest PC 0x0c0b4334 */
if(!s->budget--) { s->failed_pc=0x0c0b4334u; return 0; }
r[11]+=r[13];
goto P_0c0b4336;
P_0c0b4336: /* original a037, guest PC 0x0c0b4336 */
if(!s->budget--) { s->failed_pc=0x0c0b4336u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b43a8;
P_0c0b4338: /* original 65b2, guest PC 0x0c0b4338 */
if(!s->budget--) { s->failed_pc=0x0c0b4338u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0b433au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b433au; return 0; } return 1;
P_0c0b43a8: /* original 94ab, guest PC 0x0c0b43a8 */
if(!s->budget--) { s->failed_pc=0x0c0b43a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4502u,2);
goto P_0c0b43aa;
P_0c0b43aa: /* original 4e0b, guest PC 0x0c0b43aa */
if(!s->budget--) { s->failed_pc=0x0c0b43aau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b43aeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b43aeu) { target=s->pc; goto dispatch; }
goto P_0c0b43ae;
P_0c0b43ac: /* original 0009, guest PC 0x0c0b43ac */
if(!s->budget--) { s->failed_pc=0x0c0b43acu; return 0; }
goto P_0c0b43ae;
P_0c0b43ae: /* original 94a9, guest PC 0x0c0b43ae */
if(!s->budget--) { s->failed_pc=0x0c0b43aeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4504u,2);
goto P_0c0b43b0;
P_0c0b43b0: /* original 4e0b, guest PC 0x0c0b43b0 */
if(!s->budget--) { s->failed_pc=0x0c0b43b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b43b4u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b43b4u) { target=s->pc; goto dispatch; }
goto P_0c0b43b4;
P_0c0b43b2: /* original 65b2, guest PC 0x0c0b43b2 */
if(!s->budget--) { s->failed_pc=0x0c0b43b2u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b43b4;
P_0c0b43b4: /* original 94a7, guest PC 0x0c0b43b4 */
if(!s->budget--) { s->failed_pc=0x0c0b43b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4506u,2);
goto P_0c0b43b6;
P_0c0b43b6: /* original 4e0b, guest PC 0x0c0b43b6 */
if(!s->budget--) { s->failed_pc=0x0c0b43b6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b43bau;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b43bau) { target=s->pc; goto dispatch; }
goto P_0c0b43ba;
P_0c0b43b8: /* original 65b2, guest PC 0x0c0b43b8 */
if(!s->budget--) { s->failed_pc=0x0c0b43b8u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b43ba;
P_0c0b43ba: /* original 94a5, guest PC 0x0c0b43ba */
if(!s->budget--) { s->failed_pc=0x0c0b43bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4508u,2);
goto P_0c0b43bc;
P_0c0b43bc: /* original 4e0b, guest PC 0x0c0b43bc */
if(!s->budget--) { s->failed_pc=0x0c0b43bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b43c0u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b43c0u) { target=s->pc; goto dispatch; }
goto P_0c0b43c0;
P_0c0b43be: /* original 65b2, guest PC 0x0c0b43be */
if(!s->budget--) { s->failed_pc=0x0c0b43beu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b43c0;
P_0c0b43c0: /* original 9aa3, guest PC 0x0c0b43c0 */
if(!s->budget--) { s->failed_pc=0x0c0b43c0u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b450au,2);
goto P_0c0b43c2;
P_0c0b43c2: /* original 94a3, guest PC 0x0c0b43c2 */
if(!s->budget--) { s->failed_pc=0x0c0b43c2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b450cu,2);
goto P_0c0b43c4;
P_0c0b43c4: /* original 3adc, guest PC 0x0c0b43c4 */
if(!s->budget--) { s->failed_pc=0x0c0b43c4u; return 0; }
r[10]+=r[13];
goto P_0c0b43c6;
P_0c0b43c6: /* original 4e0b, guest PC 0x0c0b43c6 */
if(!s->budget--) { s->failed_pc=0x0c0b43c6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b43cau;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b43cau) { target=s->pc; goto dispatch; }
goto P_0c0b43ca;
P_0c0b43c8: /* original 65a2, guest PC 0x0c0b43c8 */
if(!s->budget--) { s->failed_pc=0x0c0b43c8u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b43ca;
P_0c0b43ca: /* original 94a0, guest PC 0x0c0b43ca */
if(!s->budget--) { s->failed_pc=0x0c0b43cau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b450eu,2);
goto P_0c0b43cc;
P_0c0b43cc: /* original 4e0b, guest PC 0x0c0b43cc */
if(!s->budget--) { s->failed_pc=0x0c0b43ccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b43d0u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b43d0u) { target=s->pc; goto dispatch; }
goto P_0c0b43d0;
P_0c0b43ce: /* original 65a2, guest PC 0x0c0b43ce */
if(!s->budget--) { s->failed_pc=0x0c0b43ceu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b43d0;
P_0c0b43d0: /* original 949e, guest PC 0x0c0b43d0 */
if(!s->budget--) { s->failed_pc=0x0c0b43d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4510u,2);
goto P_0c0b43d2;
P_0c0b43d2: /* original 4e0b, guest PC 0x0c0b43d2 */
if(!s->budget--) { s->failed_pc=0x0c0b43d2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b43d6u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b43d6u) { target=s->pc; goto dispatch; }
goto P_0c0b43d6;
P_0c0b43d4: /* original 65a2, guest PC 0x0c0b43d4 */
if(!s->budget--) { s->failed_pc=0x0c0b43d4u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b43d6;
P_0c0b43d6: /* original 949c, guest PC 0x0c0b43d6 */
if(!s->budget--) { s->failed_pc=0x0c0b43d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4512u,2);
goto P_0c0b43d8;
P_0c0b43d8: /* original 4e0b, guest PC 0x0c0b43d8 */
if(!s->budget--) { s->failed_pc=0x0c0b43d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b43dcu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b43dcu) { target=s->pc; goto dispatch; }
goto P_0c0b43dc;
P_0c0b43da: /* original 65a2, guest PC 0x0c0b43da */
if(!s->budget--) { s->failed_pc=0x0c0b43dau; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b43dc;
P_0c0b43dc: /* original 949a, guest PC 0x0c0b43dc */
if(!s->budget--) { s->failed_pc=0x0c0b43dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4514u,2);
goto P_0c0b43de;
P_0c0b43de: /* original 65f2, guest PC 0x0c0b43de */
if(!s->budget--) { s->failed_pc=0x0c0b43deu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b43e0;
P_0c0b43e0: /* original 4e0b, guest PC 0x0c0b43e0 */
if(!s->budget--) { s->failed_pc=0x0c0b43e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b43e4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b43e4u) { target=s->pc; goto dispatch; }
goto P_0c0b43e4;
P_0c0b43e2: /* original 6552, guest PC 0x0c0b43e2 */
if(!s->budget--) { s->failed_pc=0x0c0b43e2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b43e4;
P_0c0b43e4: /* original 9497, guest PC 0x0c0b43e4 */
if(!s->budget--) { s->failed_pc=0x0c0b43e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4516u,2);
goto P_0c0b43e6;
P_0c0b43e6: /* original 55f1, guest PC 0x0c0b43e6 */
if(!s->budget--) { s->failed_pc=0x0c0b43e6u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0b43e8;
P_0c0b43e8: /* original 4e0b, guest PC 0x0c0b43e8 */
if(!s->budget--) { s->failed_pc=0x0c0b43e8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b43ecu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b43ecu) { target=s->pc; goto dispatch; }
goto P_0c0b43ec;
P_0c0b43ea: /* original 6552, guest PC 0x0c0b43ea */
if(!s->budget--) { s->failed_pc=0x0c0b43eau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b43ec;
P_0c0b43ec: /* original 9494, guest PC 0x0c0b43ec */
if(!s->budget--) { s->failed_pc=0x0c0b43ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4518u,2);
goto P_0c0b43ee;
P_0c0b43ee: /* original 4e0b, guest PC 0x0c0b43ee */
if(!s->budget--) { s->failed_pc=0x0c0b43eeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b43f2u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b43f2u) { target=s->pc; goto dispatch; }
goto P_0c0b43f2;
P_0c0b43f0: /* original 6592, guest PC 0x0c0b43f0 */
if(!s->budget--) { s->failed_pc=0x0c0b43f0u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b43f2;
P_0c0b43f2: /* original 9492, guest PC 0x0c0b43f2 */
if(!s->budget--) { s->failed_pc=0x0c0b43f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b451au,2);
goto P_0c0b43f4;
P_0c0b43f4: /* original 4e0b, guest PC 0x0c0b43f4 */
if(!s->budget--) { s->failed_pc=0x0c0b43f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b43f8u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b43f8u) { target=s->pc; goto dispatch; }
goto P_0c0b43f8;
P_0c0b43f6: /* original 6592, guest PC 0x0c0b43f6 */
if(!s->budget--) { s->failed_pc=0x0c0b43f6u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b43f8;
P_0c0b43f8: /* original 9490, guest PC 0x0c0b43f8 */
if(!s->budget--) { s->failed_pc=0x0c0b43f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b451cu,2);
goto P_0c0b43fa;
P_0c0b43fa: /* original 4e0b, guest PC 0x0c0b43fa */
if(!s->budget--) { s->failed_pc=0x0c0b43fau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b43feu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b43feu) { target=s->pc; goto dispatch; }
goto P_0c0b43fe;
P_0c0b43fc: /* original 6592, guest PC 0x0c0b43fc */
if(!s->budget--) { s->failed_pc=0x0c0b43fcu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b43fe;
P_0c0b43fe: /* original 948e, guest PC 0x0c0b43fe */
if(!s->budget--) { s->failed_pc=0x0c0b43feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b451eu,2);
goto P_0c0b4400;
P_0c0b4400: /* original 4e0b, guest PC 0x0c0b4400 */
if(!s->budget--) { s->failed_pc=0x0c0b4400u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4404u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4404u) { target=s->pc; goto dispatch; }
goto P_0c0b4404;
P_0c0b4402: /* original 6592, guest PC 0x0c0b4402 */
if(!s->budget--) { s->failed_pc=0x0c0b4402u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b4404;
P_0c0b4404: /* original 948c, guest PC 0x0c0b4404 */
if(!s->budget--) { s->failed_pc=0x0c0b4404u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4520u,2);
goto P_0c0b4406;
P_0c0b4406: /* original 4e0b, guest PC 0x0c0b4406 */
if(!s->budget--) { s->failed_pc=0x0c0b4406u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b440au;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b440au) { target=s->pc; goto dispatch; }
goto P_0c0b440a;
P_0c0b4408: /* original 65c2, guest PC 0x0c0b4408 */
if(!s->budget--) { s->failed_pc=0x0c0b4408u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b440a;
P_0c0b440a: /* original 948a, guest PC 0x0c0b440a */
if(!s->budget--) { s->failed_pc=0x0c0b440au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4522u,2);
goto P_0c0b440c;
P_0c0b440c: /* original 4e0b, guest PC 0x0c0b440c */
if(!s->budget--) { s->failed_pc=0x0c0b440cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4410u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4410u) { target=s->pc; goto dispatch; }
goto P_0c0b4410;
P_0c0b440e: /* original 65c2, guest PC 0x0c0b440e */
if(!s->budget--) { s->failed_pc=0x0c0b440eu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b4410;
P_0c0b4410: /* original 9488, guest PC 0x0c0b4410 */
if(!s->budget--) { s->failed_pc=0x0c0b4410u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4524u,2);
goto P_0c0b4412;
P_0c0b4412: /* original 4e0b, guest PC 0x0c0b4412 */
if(!s->budget--) { s->failed_pc=0x0c0b4412u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4416u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4416u) { target=s->pc; goto dispatch; }
goto P_0c0b4416;
P_0c0b4414: /* original 65c2, guest PC 0x0c0b4414 */
if(!s->budget--) { s->failed_pc=0x0c0b4414u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b4416;
P_0c0b4416: /* original 9486, guest PC 0x0c0b4416 */
if(!s->budget--) { s->failed_pc=0x0c0b4416u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4526u,2);
goto P_0c0b4418;
P_0c0b4418: /* original 4e0b, guest PC 0x0c0b4418 */
if(!s->budget--) { s->failed_pc=0x0c0b4418u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b441cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b441cu) { target=s->pc; goto dispatch; }
goto P_0c0b441c;
P_0c0b441a: /* original 65c2, guest PC 0x0c0b441a */
if(!s->budget--) { s->failed_pc=0x0c0b441au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b441c;
P_0c0b441c: /* original 9484, guest PC 0x0c0b441c */
if(!s->budget--) { s->failed_pc=0x0c0b441cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4528u,2);
goto P_0c0b441e;
P_0c0b441e: /* original 4e0b, guest PC 0x0c0b441e */
if(!s->budget--) { s->failed_pc=0x0c0b441eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4422u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4422u) { target=s->pc; goto dispatch; }
goto P_0c0b4422;
P_0c0b4420: /* original 65b2, guest PC 0x0c0b4420 */
if(!s->budget--) { s->failed_pc=0x0c0b4420u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b4422;
P_0c0b4422: /* original 9482, guest PC 0x0c0b4422 */
if(!s->budget--) { s->failed_pc=0x0c0b4422u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b452au,2);
goto P_0c0b4424;
P_0c0b4424: /* original 4e0b, guest PC 0x0c0b4424 */
if(!s->budget--) { s->failed_pc=0x0c0b4424u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4428u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4428u) { target=s->pc; goto dispatch; }
goto P_0c0b4428;
P_0c0b4426: /* original 65b2, guest PC 0x0c0b4426 */
if(!s->budget--) { s->failed_pc=0x0c0b4426u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b4428;
P_0c0b4428: /* original 9480, guest PC 0x0c0b4428 */
if(!s->budget--) { s->failed_pc=0x0c0b4428u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b452cu,2);
goto P_0c0b442a;
P_0c0b442a: /* original 4e0b, guest PC 0x0c0b442a */
if(!s->budget--) { s->failed_pc=0x0c0b442au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b442eu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b442eu) { target=s->pc; goto dispatch; }
goto P_0c0b442e;
P_0c0b442c: /* original 65b2, guest PC 0x0c0b442c */
if(!s->budget--) { s->failed_pc=0x0c0b442cu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b442e;
P_0c0b442e: /* original 947e, guest PC 0x0c0b442e */
if(!s->budget--) { s->failed_pc=0x0c0b442eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b452eu,2);
goto P_0c0b4430;
P_0c0b4430: /* original 4e0b, guest PC 0x0c0b4430 */
if(!s->budget--) { s->failed_pc=0x0c0b4430u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4434u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4434u) { target=s->pc; goto dispatch; }
goto P_0c0b4434;
P_0c0b4432: /* original 65b2, guest PC 0x0c0b4432 */
if(!s->budget--) { s->failed_pc=0x0c0b4432u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b4434;
P_0c0b4434: /* original 947c, guest PC 0x0c0b4434 */
if(!s->budget--) { s->failed_pc=0x0c0b4434u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4530u,2);
goto P_0c0b4436;
P_0c0b4436: /* original 4e0b, guest PC 0x0c0b4436 */
if(!s->budget--) { s->failed_pc=0x0c0b4436u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b443au;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b443au) { target=s->pc; goto dispatch; }
goto P_0c0b443a;
P_0c0b4438: /* original 65a2, guest PC 0x0c0b4438 */
if(!s->budget--) { s->failed_pc=0x0c0b4438u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b443a;
P_0c0b443a: /* original 947a, guest PC 0x0c0b443a */
if(!s->budget--) { s->failed_pc=0x0c0b443au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4532u,2);
goto P_0c0b443c;
P_0c0b443c: /* original 4e0b, guest PC 0x0c0b443c */
if(!s->budget--) { s->failed_pc=0x0c0b443cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4440u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4440u) { target=s->pc; goto dispatch; }
goto P_0c0b4440;
P_0c0b443e: /* original 65a2, guest PC 0x0c0b443e */
if(!s->budget--) { s->failed_pc=0x0c0b443eu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b4440;
P_0c0b4440: /* original 9478, guest PC 0x0c0b4440 */
if(!s->budget--) { s->failed_pc=0x0c0b4440u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4534u,2);
goto P_0c0b4442;
P_0c0b4442: /* original 4e0b, guest PC 0x0c0b4442 */
if(!s->budget--) { s->failed_pc=0x0c0b4442u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4446u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4446u) { target=s->pc; goto dispatch; }
goto P_0c0b4446;
P_0c0b4444: /* original 65a2, guest PC 0x0c0b4444 */
if(!s->budget--) { s->failed_pc=0x0c0b4444u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b4446;
P_0c0b4446: /* original 9476, guest PC 0x0c0b4446 */
if(!s->budget--) { s->failed_pc=0x0c0b4446u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4536u,2);
goto P_0c0b4448;
P_0c0b4448: /* original 4e0b, guest PC 0x0c0b4448 */
if(!s->budget--) { s->failed_pc=0x0c0b4448u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b444cu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b444cu) { target=s->pc; goto dispatch; }
goto P_0c0b444c;
P_0c0b444a: /* original 65a2, guest PC 0x0c0b444a */
if(!s->budget--) { s->failed_pc=0x0c0b444au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b444c;
P_0c0b444c: /* original 9574, guest PC 0x0c0b444c */
if(!s->budget--) { s->failed_pc=0x0c0b444cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4538u,2);
goto P_0c0b444e;
P_0c0b444e: /* original 35dc, guest PC 0x0c0b444e */
if(!s->budget--) { s->failed_pc=0x0c0b444eu; return 0; }
r[5]+=r[13];
goto P_0c0b4450;
P_0c0b4450: /* original 2f52, guest PC 0x0c0b4450 */
if(!s->budget--) { s->failed_pc=0x0c0b4450u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b4452;
P_0c0b4452: /* original 9472, guest PC 0x0c0b4452 */
if(!s->budget--) { s->failed_pc=0x0c0b4452u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b453au,2);
goto P_0c0b4454;
P_0c0b4454: /* original 4e0b, guest PC 0x0c0b4454 */
if(!s->budget--) { s->failed_pc=0x0c0b4454u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4458u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4458u) { target=s->pc; goto dispatch; }
goto P_0c0b4458;
P_0c0b4456: /* original 6552, guest PC 0x0c0b4456 */
if(!s->budget--) { s->failed_pc=0x0c0b4456u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4458;
P_0c0b4458: /* original 9470, guest PC 0x0c0b4458 */
if(!s->budget--) { s->failed_pc=0x0c0b4458u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b453cu,2);
goto P_0c0b445a;
P_0c0b445a: /* original 65f2, guest PC 0x0c0b445a */
if(!s->budget--) { s->failed_pc=0x0c0b445au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b445c;
P_0c0b445c: /* original 4e0b, guest PC 0x0c0b445c */
if(!s->budget--) { s->failed_pc=0x0c0b445cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4460u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4460u) { target=s->pc; goto dispatch; }
goto P_0c0b4460;
P_0c0b445e: /* original 6552, guest PC 0x0c0b445e */
if(!s->budget--) { s->failed_pc=0x0c0b445eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4460;
P_0c0b4460: /* original 956d, guest PC 0x0c0b4460 */
if(!s->budget--) { s->failed_pc=0x0c0b4460u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b453eu,2);
goto P_0c0b4462;
P_0c0b4462: /* original 35dc, guest PC 0x0c0b4462 */
if(!s->budget--) { s->failed_pc=0x0c0b4462u; return 0; }
r[5]+=r[13];
goto P_0c0b4464;
P_0c0b4464: /* original 2f52, guest PC 0x0c0b4464 */
if(!s->budget--) { s->failed_pc=0x0c0b4464u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b4466;
P_0c0b4466: /* original 946b, guest PC 0x0c0b4466 */
if(!s->budget--) { s->failed_pc=0x0c0b4466u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4540u,2);
goto P_0c0b4468;
P_0c0b4468: /* original 4e0b, guest PC 0x0c0b4468 */
if(!s->budget--) { s->failed_pc=0x0c0b4468u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b446cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b446cu) { target=s->pc; goto dispatch; }
goto P_0c0b446c;
P_0c0b446a: /* original 6552, guest PC 0x0c0b446a */
if(!s->budget--) { s->failed_pc=0x0c0b446au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b446c;
P_0c0b446c: /* original 9469, guest PC 0x0c0b446c */
if(!s->budget--) { s->failed_pc=0x0c0b446cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4542u,2);
goto P_0c0b446e;
P_0c0b446e: /* original 65f2, guest PC 0x0c0b446e */
if(!s->budget--) { s->failed_pc=0x0c0b446eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b4470;
P_0c0b4470: /* original 4e0b, guest PC 0x0c0b4470 */
if(!s->budget--) { s->failed_pc=0x0c0b4470u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4474u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4474u) { target=s->pc; goto dispatch; }
goto P_0c0b4474;
P_0c0b4472: /* original 6552, guest PC 0x0c0b4472 */
if(!s->budget--) { s->failed_pc=0x0c0b4472u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4474;
P_0c0b4474: /* original 9467, guest PC 0x0c0b4474 */
if(!s->budget--) { s->failed_pc=0x0c0b4474u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4546u,2);
goto P_0c0b4476;
P_0c0b4476: /* original 9065, guest PC 0x0c0b4476 */
if(!s->budget--) { s->failed_pc=0x0c0b4476u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4544u,2);
goto P_0c0b4478;
P_0c0b4478: /* original 4e0b, guest PC 0x0c0b4478 */
if(!s->budget--) { s->failed_pc=0x0c0b4478u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b447cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b447cu) { target=s->pc; goto dispatch; }
goto P_0c0b447c;
P_0c0b447a: /* original 05de, guest PC 0x0c0b447a */
if(!s->budget--) { s->failed_pc=0x0c0b447au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b447c;
P_0c0b447c: /* original 9564, guest PC 0x0c0b447c */
if(!s->budget--) { s->failed_pc=0x0c0b447cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4548u,2);
goto P_0c0b447e;
P_0c0b447e: /* original 35dc, guest PC 0x0c0b447e */
if(!s->budget--) { s->failed_pc=0x0c0b447eu; return 0; }
r[5]+=r[13];
goto P_0c0b4480;
P_0c0b4480: /* original 2f52, guest PC 0x0c0b4480 */
if(!s->budget--) { s->failed_pc=0x0c0b4480u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b4482;
P_0c0b4482: /* original 9462, guest PC 0x0c0b4482 */
if(!s->budget--) { s->failed_pc=0x0c0b4482u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b454au,2);
goto P_0c0b4484;
P_0c0b4484: /* original 4e0b, guest PC 0x0c0b4484 */
if(!s->budget--) { s->failed_pc=0x0c0b4484u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4488u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4488u) { target=s->pc; goto dispatch; }
goto P_0c0b4488;
P_0c0b4486: /* original 6552, guest PC 0x0c0b4486 */
if(!s->budget--) { s->failed_pc=0x0c0b4486u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4488;
P_0c0b4488: /* original 9460, guest PC 0x0c0b4488 */
if(!s->budget--) { s->failed_pc=0x0c0b4488u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b454cu,2);
goto P_0c0b448a;
P_0c0b448a: /* original 65f2, guest PC 0x0c0b448a */
if(!s->budget--) { s->failed_pc=0x0c0b448au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b448c;
P_0c0b448c: /* original 4e0b, guest PC 0x0c0b448c */
if(!s->budget--) { s->failed_pc=0x0c0b448cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4490u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4490u) { target=s->pc; goto dispatch; }
goto P_0c0b4490;
P_0c0b448e: /* original 6552, guest PC 0x0c0b448e */
if(!s->budget--) { s->failed_pc=0x0c0b448eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4490;
P_0c0b4490: /* original 945e, guest PC 0x0c0b4490 */
if(!s->budget--) { s->failed_pc=0x0c0b4490u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4550u,2);
goto P_0c0b4492;
P_0c0b4492: /* original 905c, guest PC 0x0c0b4492 */
if(!s->budget--) { s->failed_pc=0x0c0b4492u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b454eu,2);
goto P_0c0b4494;
P_0c0b4494: /* original 4e0b, guest PC 0x0c0b4494 */
if(!s->budget--) { s->failed_pc=0x0c0b4494u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4498u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4498u) { target=s->pc; goto dispatch; }
goto P_0c0b4498;
P_0c0b4496: /* original 05de, guest PC 0x0c0b4496 */
if(!s->budget--) { s->failed_pc=0x0c0b4496u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4498;
P_0c0b4498: /* original 955b, guest PC 0x0c0b4498 */
if(!s->budget--) { s->failed_pc=0x0c0b4498u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4552u,2);
goto P_0c0b449a;
P_0c0b449a: /* original 35dc, guest PC 0x0c0b449a */
if(!s->budget--) { s->failed_pc=0x0c0b449au; return 0; }
r[5]+=r[13];
goto P_0c0b449c;
P_0c0b449c: /* original 2f52, guest PC 0x0c0b449c */
if(!s->budget--) { s->failed_pc=0x0c0b449cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b449e;
P_0c0b449e: /* original 9459, guest PC 0x0c0b449e */
if(!s->budget--) { s->failed_pc=0x0c0b449eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4554u,2);
goto P_0c0b44a0;
P_0c0b44a0: /* original 4e0b, guest PC 0x0c0b44a0 */
if(!s->budget--) { s->failed_pc=0x0c0b44a0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b44a4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b44a4u) { target=s->pc; goto dispatch; }
goto P_0c0b44a4;
P_0c0b44a2: /* original 6552, guest PC 0x0c0b44a2 */
if(!s->budget--) { s->failed_pc=0x0c0b44a2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b44a4;
P_0c0b44a4: /* original 9457, guest PC 0x0c0b44a4 */
if(!s->budget--) { s->failed_pc=0x0c0b44a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4556u,2);
goto P_0c0b44a6;
P_0c0b44a6: /* original 65f2, guest PC 0x0c0b44a6 */
if(!s->budget--) { s->failed_pc=0x0c0b44a6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b44a8;
P_0c0b44a8: /* original 4e0b, guest PC 0x0c0b44a8 */
if(!s->budget--) { s->failed_pc=0x0c0b44a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b44acu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b44acu) { target=s->pc; goto dispatch; }
goto P_0c0b44ac;
P_0c0b44aa: /* original 6552, guest PC 0x0c0b44aa */
if(!s->budget--) { s->failed_pc=0x0c0b44aau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b44ac;
P_0c0b44ac: /* original 9455, guest PC 0x0c0b44ac */
if(!s->budget--) { s->failed_pc=0x0c0b44acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b455au,2);
goto P_0c0b44ae;
P_0c0b44ae: /* original 9053, guest PC 0x0c0b44ae */
if(!s->budget--) { s->failed_pc=0x0c0b44aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4558u,2);
goto P_0c0b44b0;
P_0c0b44b0: /* original 4e0b, guest PC 0x0c0b44b0 */
if(!s->budget--) { s->failed_pc=0x0c0b44b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b44b4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b44b4u) { target=s->pc; goto dispatch; }
goto P_0c0b44b4;
P_0c0b44b2: /* original 05de, guest PC 0x0c0b44b2 */
if(!s->budget--) { s->failed_pc=0x0c0b44b2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b44b4;
P_0c0b44b4: /* original 9552, guest PC 0x0c0b44b4 */
if(!s->budget--) { s->failed_pc=0x0c0b44b4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b455cu,2);
goto P_0c0b44b6;
P_0c0b44b6: /* original 35dc, guest PC 0x0c0b44b6 */
if(!s->budget--) { s->failed_pc=0x0c0b44b6u; return 0; }
r[5]+=r[13];
goto P_0c0b44b8;
P_0c0b44b8: /* original 2f52, guest PC 0x0c0b44b8 */
if(!s->budget--) { s->failed_pc=0x0c0b44b8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b44ba;
P_0c0b44ba: /* original 9450, guest PC 0x0c0b44ba */
if(!s->budget--) { s->failed_pc=0x0c0b44bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b455eu,2);
goto P_0c0b44bc;
P_0c0b44bc: /* original 4e0b, guest PC 0x0c0b44bc */
if(!s->budget--) { s->failed_pc=0x0c0b44bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b44c0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b44c0u) { target=s->pc; goto dispatch; }
goto P_0c0b44c0;
P_0c0b44be: /* original 6552, guest PC 0x0c0b44be */
if(!s->budget--) { s->failed_pc=0x0c0b44beu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b44c0;
P_0c0b44c0: /* original 944e, guest PC 0x0c0b44c0 */
if(!s->budget--) { s->failed_pc=0x0c0b44c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4560u,2);
goto P_0c0b44c2;
P_0c0b44c2: /* original 65f2, guest PC 0x0c0b44c2 */
if(!s->budget--) { s->failed_pc=0x0c0b44c2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b44c4;
P_0c0b44c4: /* original 4e0b, guest PC 0x0c0b44c4 */
if(!s->budget--) { s->failed_pc=0x0c0b44c4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b44c8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b44c8u) { target=s->pc; goto dispatch; }
goto P_0c0b44c8;
P_0c0b44c6: /* original 6552, guest PC 0x0c0b44c6 */
if(!s->budget--) { s->failed_pc=0x0c0b44c6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b44c8;
P_0c0b44c8: /* original 954b, guest PC 0x0c0b44c8 */
if(!s->budget--) { s->failed_pc=0x0c0b44c8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4562u,2);
goto P_0c0b44ca;
P_0c0b44ca: /* original 35dc, guest PC 0x0c0b44ca */
if(!s->budget--) { s->failed_pc=0x0c0b44cau; return 0; }
r[5]+=r[13];
goto P_0c0b44cc;
P_0c0b44cc: /* original 2f52, guest PC 0x0c0b44cc */
if(!s->budget--) { s->failed_pc=0x0c0b44ccu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b44ce;
P_0c0b44ce: /* original 9449, guest PC 0x0c0b44ce */
if(!s->budget--) { s->failed_pc=0x0c0b44ceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4564u,2);
goto P_0c0b44d0;
P_0c0b44d0: /* original 4e0b, guest PC 0x0c0b44d0 */
if(!s->budget--) { s->failed_pc=0x0c0b44d0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b44d4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b44d4u) { target=s->pc; goto dispatch; }
goto P_0c0b44d4;
P_0c0b44d2: /* original 6552, guest PC 0x0c0b44d2 */
if(!s->budget--) { s->failed_pc=0x0c0b44d2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b44d4;
P_0c0b44d4: /* original 9447, guest PC 0x0c0b44d4 */
if(!s->budget--) { s->failed_pc=0x0c0b44d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4566u,2);
goto P_0c0b44d6;
P_0c0b44d6: /* original 65f2, guest PC 0x0c0b44d6 */
if(!s->budget--) { s->failed_pc=0x0c0b44d6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b44d8;
P_0c0b44d8: /* original 4e0b, guest PC 0x0c0b44d8 */
if(!s->budget--) { s->failed_pc=0x0c0b44d8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b44dcu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b44dcu) { target=s->pc; goto dispatch; }
goto P_0c0b44dc;
P_0c0b44da: /* original 6552, guest PC 0x0c0b44da */
if(!s->budget--) { s->failed_pc=0x0c0b44dau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b44dc;
P_0c0b44dc: /* original 9445, guest PC 0x0c0b44dc */
if(!s->budget--) { s->failed_pc=0x0c0b44dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b456au,2);
goto P_0c0b44de;
P_0c0b44de: /* original 9043, guest PC 0x0c0b44de */
if(!s->budget--) { s->failed_pc=0x0c0b44deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4568u,2);
goto P_0c0b44e0;
P_0c0b44e0: /* original 4e0b, guest PC 0x0c0b44e0 */
if(!s->budget--) { s->failed_pc=0x0c0b44e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b44e4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b44e4u) { target=s->pc; goto dispatch; }
goto P_0c0b44e4;
P_0c0b44e2: /* original 05de, guest PC 0x0c0b44e2 */
if(!s->budget--) { s->failed_pc=0x0c0b44e2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b44e4;
P_0c0b44e4: /* original 9443, guest PC 0x0c0b44e4 */
if(!s->budget--) { s->failed_pc=0x0c0b44e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b456eu,2);
goto P_0c0b44e6;
P_0c0b44e6: /* original 9041, guest PC 0x0c0b44e6 */
if(!s->budget--) { s->failed_pc=0x0c0b44e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b456cu,2);
goto P_0c0b44e8;
P_0c0b44e8: /* original 4e0b, guest PC 0x0c0b44e8 */
if(!s->budget--) { s->failed_pc=0x0c0b44e8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b44ecu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b44ecu) { target=s->pc; goto dispatch; }
goto P_0c0b44ec;
P_0c0b44ea: /* original 05de, guest PC 0x0c0b44ea */
if(!s->budget--) { s->failed_pc=0x0c0b44eau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b44ec;
P_0c0b44ec: /* original 9441, guest PC 0x0c0b44ec */
if(!s->budget--) { s->failed_pc=0x0c0b44ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4572u,2);
goto P_0c0b44ee;
P_0c0b44ee: /* original 903f, guest PC 0x0c0b44ee */
if(!s->budget--) { s->failed_pc=0x0c0b44eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4570u,2);
goto P_0c0b44f0;
P_0c0b44f0: /* original 4e0b, guest PC 0x0c0b44f0 */
if(!s->budget--) { s->failed_pc=0x0c0b44f0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b44f4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b44f4u) { target=s->pc; goto dispatch; }
goto P_0c0b44f4;
P_0c0b44f2: /* original 05de, guest PC 0x0c0b44f2 */
if(!s->budget--) { s->failed_pc=0x0c0b44f2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b44f4;
P_0c0b44f4: /* original 943f, guest PC 0x0c0b44f4 */
if(!s->budget--) { s->failed_pc=0x0c0b44f4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4576u,2);
goto P_0c0b44f6;
P_0c0b44f6: /* original 903d, guest PC 0x0c0b44f6 */
if(!s->budget--) { s->failed_pc=0x0c0b44f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4574u,2);
goto P_0c0b44f8;
P_0c0b44f8: /* original 4e0b, guest PC 0x0c0b44f8 */
if(!s->budget--) { s->failed_pc=0x0c0b44f8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b44fcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b44fcu) { target=s->pc; goto dispatch; }
goto P_0c0b44fc;
P_0c0b44fa: /* original 05de, guest PC 0x0c0b44fa */
if(!s->budget--) { s->failed_pc=0x0c0b44fau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b44fc;
P_0c0b44fc: /* original 903c, guest PC 0x0c0b44fc */
if(!s->budget--) { s->failed_pc=0x0c0b44fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4578u,2);
goto P_0c0b44fe;
P_0c0b44fe: /* original a03c, guest PC 0x0c0b44fe */
if(!s->budget--) { s->failed_pc=0x0c0b44feu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b457a;
P_0c0b4500: /* original 05de, guest PC 0x0c0b4500 */
if(!s->budget--) { s->failed_pc=0x0c0b4500u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0b4502u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b4502u; return 0; } return 1;
P_0c0b457a: /* original 9436, guest PC 0x0c0b457a */
if(!s->budget--) { s->failed_pc=0x0c0b457au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b45eau,2);
goto P_0c0b457c;
P_0c0b457c: /* original 4e0b, guest PC 0x0c0b457c */
if(!s->budget--) { s->failed_pc=0x0c0b457cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4580u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4580u) { target=s->pc; goto dispatch; }
goto P_0c0b4580;
P_0c0b457e: /* original 0009, guest PC 0x0c0b457e */
if(!s->budget--) { s->failed_pc=0x0c0b457eu; return 0; }
goto P_0c0b4580;
P_0c0b4580: /* original 9435, guest PC 0x0c0b4580 */
if(!s->budget--) { s->failed_pc=0x0c0b4580u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b45eeu,2);
goto P_0c0b4582;
P_0c0b4582: /* original 9033, guest PC 0x0c0b4582 */
if(!s->budget--) { s->failed_pc=0x0c0b4582u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b45ecu,2);
goto P_0c0b4584;
P_0c0b4584: /* original 4e0b, guest PC 0x0c0b4584 */
if(!s->budget--) { s->failed_pc=0x0c0b4584u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4588u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4588u) { target=s->pc; goto dispatch; }
goto P_0c0b4588;
P_0c0b4586: /* original 05de, guest PC 0x0c0b4586 */
if(!s->budget--) { s->failed_pc=0x0c0b4586u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4588;
P_0c0b4588: /* original 9433, guest PC 0x0c0b4588 */
if(!s->budget--) { s->failed_pc=0x0c0b4588u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b45f2u,2);
goto P_0c0b458a;
P_0c0b458a: /* original 9031, guest PC 0x0c0b458a */
if(!s->budget--) { s->failed_pc=0x0c0b458au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b45f0u,2);
goto P_0c0b458c;
P_0c0b458c: /* original 4e0b, guest PC 0x0c0b458c */
if(!s->budget--) { s->failed_pc=0x0c0b458cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4590u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4590u) { target=s->pc; goto dispatch; }
goto P_0c0b4590;
P_0c0b458e: /* original 05de, guest PC 0x0c0b458e */
if(!s->budget--) { s->failed_pc=0x0c0b458eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4590;
P_0c0b4590: /* original 9431, guest PC 0x0c0b4590 */
if(!s->budget--) { s->failed_pc=0x0c0b4590u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b45f6u,2);
goto P_0c0b4592;
P_0c0b4592: /* original 902f, guest PC 0x0c0b4592 */
if(!s->budget--) { s->failed_pc=0x0c0b4592u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b45f4u,2);
goto P_0c0b4594;
P_0c0b4594: /* original 4e0b, guest PC 0x0c0b4594 */
if(!s->budget--) { s->failed_pc=0x0c0b4594u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4598u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4598u) { target=s->pc; goto dispatch; }
goto P_0c0b4598;
P_0c0b4596: /* original 05de, guest PC 0x0c0b4596 */
if(!s->budget--) { s->failed_pc=0x0c0b4596u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4598;
P_0c0b4598: /* original 942f, guest PC 0x0c0b4598 */
if(!s->budget--) { s->failed_pc=0x0c0b4598u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b45fau,2);
goto P_0c0b459a;
P_0c0b459a: /* original 902d, guest PC 0x0c0b459a */
if(!s->budget--) { s->failed_pc=0x0c0b459au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b45f8u,2);
goto P_0c0b459c;
P_0c0b459c: /* original 4e0b, guest PC 0x0c0b459c */
if(!s->budget--) { s->failed_pc=0x0c0b459cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b45a0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b45a0u) { target=s->pc; goto dispatch; }
goto P_0c0b45a0;
P_0c0b459e: /* original 05de, guest PC 0x0c0b459e */
if(!s->budget--) { s->failed_pc=0x0c0b459eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b45a0;
P_0c0b45a0: /* original 942d, guest PC 0x0c0b45a0 */
if(!s->budget--) { s->failed_pc=0x0c0b45a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b45feu,2);
goto P_0c0b45a2;
P_0c0b45a2: /* original 902b, guest PC 0x0c0b45a2 */
if(!s->budget--) { s->failed_pc=0x0c0b45a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b45fcu,2);
goto P_0c0b45a4;
P_0c0b45a4: /* original 4e0b, guest PC 0x0c0b45a4 */
if(!s->budget--) { s->failed_pc=0x0c0b45a4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b45a8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b45a8u) { target=s->pc; goto dispatch; }
goto P_0c0b45a8;
P_0c0b45a6: /* original 05de, guest PC 0x0c0b45a6 */
if(!s->budget--) { s->failed_pc=0x0c0b45a6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b45a8;
P_0c0b45a8: /* original 942b, guest PC 0x0c0b45a8 */
if(!s->budget--) { s->failed_pc=0x0c0b45a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4602u,2);
goto P_0c0b45aa;
P_0c0b45aa: /* original 9029, guest PC 0x0c0b45aa */
if(!s->budget--) { s->failed_pc=0x0c0b45aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4600u,2);
goto P_0c0b45ac;
P_0c0b45ac: /* original 4e0b, guest PC 0x0c0b45ac */
if(!s->budget--) { s->failed_pc=0x0c0b45acu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b45b0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b45b0u) { target=s->pc; goto dispatch; }
goto P_0c0b45b0;
P_0c0b45ae: /* original 05de, guest PC 0x0c0b45ae */
if(!s->budget--) { s->failed_pc=0x0c0b45aeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b45b0;
P_0c0b45b0: /* original 9429, guest PC 0x0c0b45b0 */
if(!s->budget--) { s->failed_pc=0x0c0b45b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4606u,2);
goto P_0c0b45b2;
P_0c0b45b2: /* original 9027, guest PC 0x0c0b45b2 */
if(!s->budget--) { s->failed_pc=0x0c0b45b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4604u,2);
goto P_0c0b45b4;
P_0c0b45b4: /* original 4e0b, guest PC 0x0c0b45b4 */
if(!s->budget--) { s->failed_pc=0x0c0b45b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b45b8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b45b8u) { target=s->pc; goto dispatch; }
goto P_0c0b45b8;
P_0c0b45b6: /* original 05de, guest PC 0x0c0b45b6 */
if(!s->budget--) { s->failed_pc=0x0c0b45b6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b45b8;
P_0c0b45b8: /* original 9427, guest PC 0x0c0b45b8 */
if(!s->budget--) { s->failed_pc=0x0c0b45b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b460au,2);
goto P_0c0b45ba;
P_0c0b45ba: /* original 9025, guest PC 0x0c0b45ba */
if(!s->budget--) { s->failed_pc=0x0c0b45bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4608u,2);
goto P_0c0b45bc;
P_0c0b45bc: /* original 4e0b, guest PC 0x0c0b45bc */
if(!s->budget--) { s->failed_pc=0x0c0b45bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b45c0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b45c0u) { target=s->pc; goto dispatch; }
goto P_0c0b45c0;
P_0c0b45be: /* original 05de, guest PC 0x0c0b45be */
if(!s->budget--) { s->failed_pc=0x0c0b45beu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b45c0;
P_0c0b45c0: /* original 9425, guest PC 0x0c0b45c0 */
if(!s->budget--) { s->failed_pc=0x0c0b45c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b460eu,2);
goto P_0c0b45c2;
P_0c0b45c2: /* original 9023, guest PC 0x0c0b45c2 */
if(!s->budget--) { s->failed_pc=0x0c0b45c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b460cu,2);
goto P_0c0b45c4;
P_0c0b45c4: /* original 4e0b, guest PC 0x0c0b45c4 */
if(!s->budget--) { s->failed_pc=0x0c0b45c4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b45c8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b45c8u) { target=s->pc; goto dispatch; }
goto P_0c0b45c8;
P_0c0b45c6: /* original 05de, guest PC 0x0c0b45c6 */
if(!s->budget--) { s->failed_pc=0x0c0b45c6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b45c8;
P_0c0b45c8: /* original 9423, guest PC 0x0c0b45c8 */
if(!s->budget--) { s->failed_pc=0x0c0b45c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4612u,2);
goto P_0c0b45ca;
P_0c0b45ca: /* original 9021, guest PC 0x0c0b45ca */
if(!s->budget--) { s->failed_pc=0x0c0b45cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4610u,2);
goto P_0c0b45cc;
P_0c0b45cc: /* original 4e0b, guest PC 0x0c0b45cc */
if(!s->budget--) { s->failed_pc=0x0c0b45ccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b45d0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b45d0u) { target=s->pc; goto dispatch; }
goto P_0c0b45d0;
P_0c0b45ce: /* original 05de, guest PC 0x0c0b45ce */
if(!s->budget--) { s->failed_pc=0x0c0b45ceu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b45d0;
P_0c0b45d0: /* original 9421, guest PC 0x0c0b45d0 */
if(!s->budget--) { s->failed_pc=0x0c0b45d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4616u,2);
goto P_0c0b45d2;
P_0c0b45d2: /* original 901f, guest PC 0x0c0b45d2 */
if(!s->budget--) { s->failed_pc=0x0c0b45d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4614u,2);
goto P_0c0b45d4;
P_0c0b45d4: /* original 4e0b, guest PC 0x0c0b45d4 */
if(!s->budget--) { s->failed_pc=0x0c0b45d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b45d8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b45d8u) { target=s->pc; goto dispatch; }
goto P_0c0b45d8;
P_0c0b45d6: /* original 05de, guest PC 0x0c0b45d6 */
if(!s->budget--) { s->failed_pc=0x0c0b45d6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b45d8;
P_0c0b45d8: /* original 7f08, guest PC 0x0c0b45d8 */
if(!s->budget--) { s->failed_pc=0x0c0b45d8u; return 0; }
r[15]+=0x00000008u;
goto P_0c0b45da;
P_0c0b45da: /* original 4f26, guest PC 0x0c0b45da */
if(!s->budget--) { s->failed_pc=0x0c0b45dau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b45dc;
P_0c0b45dc: /* original 69f6, guest PC 0x0c0b45dc */
if(!s->budget--) { s->failed_pc=0x0c0b45dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b45de;
P_0c0b45de: /* original 6af6, guest PC 0x0c0b45de */
if(!s->budget--) { s->failed_pc=0x0c0b45deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b45e0;
P_0c0b45e0: /* original 6bf6, guest PC 0x0c0b45e0 */
if(!s->budget--) { s->failed_pc=0x0c0b45e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b45e2;
P_0c0b45e2: /* original 6cf6, guest PC 0x0c0b45e2 */
if(!s->budget--) { s->failed_pc=0x0c0b45e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b45e4;
P_0c0b45e4: /* original 6df6, guest PC 0x0c0b45e4 */
if(!s->budget--) { s->failed_pc=0x0c0b45e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b45e6;
P_0c0b45e6: /* original 000b, guest PC 0x0c0b45e6 */
if(!s->budget--) { s->failed_pc=0x0c0b45e6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b45e8: /* original 6ef6, guest PC 0x0c0b45e8 */
if(!s->budget--) { s->failed_pc=0x0c0b45e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b45eau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b45eau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
