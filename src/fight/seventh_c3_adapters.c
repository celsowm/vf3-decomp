/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_seventh_c3_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c038a20u: goto P_0c038a20;
case 0x0c038a22u: goto P_0c038a22;
case 0x0c038a24u: goto P_0c038a24;
case 0x0c038a26u: goto P_0c038a26;
case 0x0c038a28u: goto P_0c038a28;
case 0x0c038a2au: goto P_0c038a2a;
case 0x0c038a2cu: goto P_0c038a2c;
case 0x0c038a2eu: goto P_0c038a2e;
case 0x0c038a30u: goto P_0c038a30;
case 0x0c038a32u: goto P_0c038a32;
case 0x0c038a34u: goto P_0c038a34;
case 0x0c038a36u: goto P_0c038a36;
case 0x0c038a38u: goto P_0c038a38;
case 0x0c038a3au: goto P_0c038a3a;
case 0x0c038a3cu: goto P_0c038a3c;
case 0x0c038a3eu: goto P_0c038a3e;
case 0x0c038a40u: goto P_0c038a40;
case 0x0c038a42u: goto P_0c038a42;
case 0x0c038a44u: goto P_0c038a44;
case 0x0c03f77eu: goto P_0c03f77e;
case 0x0c03f780u: goto P_0c03f780;
case 0x0c03f782u: goto P_0c03f782;
case 0x0c03f784u: goto P_0c03f784;
case 0x0c03f786u: goto P_0c03f786;
case 0x0c03f788u: goto P_0c03f788;
case 0x0c03f78au: goto P_0c03f78a;
case 0x0c03f7c0u: goto P_0c03f7c0;
case 0x0c03f7c2u: goto P_0c03f7c2;
case 0x0c03f7c4u: goto P_0c03f7c4;
case 0x0c03f7c6u: goto P_0c03f7c6;
case 0x0c03f7c8u: goto P_0c03f7c8;
case 0x0c03f7cau: goto P_0c03f7ca;
case 0x0c03f7ccu: goto P_0c03f7cc;
case 0x0c03f7ceu: goto P_0c03f7ce;
case 0x0c03f7d0u: goto P_0c03f7d0;
case 0x0c03f7d2u: goto P_0c03f7d2;
case 0x0c03f7d4u: goto P_0c03f7d4;
case 0x0c03f7d6u: goto P_0c03f7d6;
case 0x0c03f7d8u: goto P_0c03f7d8;
case 0x0c03f7dau: goto P_0c03f7da;
case 0x0c03f7dcu: goto P_0c03f7dc;
case 0x0c03f7deu: goto P_0c03f7de;
case 0x0c03f7e0u: goto P_0c03f7e0;
case 0x0c03f7e2u: goto P_0c03f7e2;
case 0x0c03f7e4u: goto P_0c03f7e4;
case 0x0c03f7e6u: goto P_0c03f7e6;
case 0x0c03f7e8u: goto P_0c03f7e8;
case 0x0c03f7eau: goto P_0c03f7ea;
case 0x0c03f7ecu: goto P_0c03f7ec;
case 0x0c03f7eeu: goto P_0c03f7ee;
case 0x0c03f7f0u: goto P_0c03f7f0;
case 0x0c03f7f2u: goto P_0c03f7f2;
case 0x0c03f7f4u: goto P_0c03f7f4;
case 0x0c03f7f6u: goto P_0c03f7f6;
case 0x0c03f7f8u: goto P_0c03f7f8;
case 0x0c03f7fau: goto P_0c03f7fa;
case 0x0c03f7fcu: goto P_0c03f7fc;
case 0x0c03f7feu: goto P_0c03f7fe;
case 0x0c03f800u: goto P_0c03f800;
case 0x0c03f802u: goto P_0c03f802;
case 0x0c03f804u: goto P_0c03f804;
case 0x0c03f806u: goto P_0c03f806;
case 0x0c03f808u: goto P_0c03f808;
case 0x0c03f80au: goto P_0c03f80a;
case 0x0c03fc90u: goto P_0c03fc90;
case 0x0c03fc92u: goto P_0c03fc92;
case 0x0c03fc94u: goto P_0c03fc94;
case 0x0c03fc96u: goto P_0c03fc96;
case 0x0c03fc98u: goto P_0c03fc98;
case 0x0c03fc9au: goto P_0c03fc9a;
case 0x0c03fc9cu: goto P_0c03fc9c;
case 0x0c03fc9eu: goto P_0c03fc9e;
case 0x0c03fca0u: goto P_0c03fca0;
case 0x0c03fca2u: goto P_0c03fca2;
case 0x0c03fca4u: goto P_0c03fca4;
case 0x0c03fca6u: goto P_0c03fca6;
case 0x0c03fca8u: goto P_0c03fca8;
case 0x0c03fcaau: goto P_0c03fcaa;
case 0x0c03fcacu: goto P_0c03fcac;
case 0x0c03fcaeu: goto P_0c03fcae;
case 0x0c03fcb0u: goto P_0c03fcb0;
case 0x0c03fcb2u: goto P_0c03fcb2;
case 0x0c03fcb4u: goto P_0c03fcb4;
case 0x0c03fcb6u: goto P_0c03fcb6;
case 0x0c03fcb8u: goto P_0c03fcb8;
case 0x0c03fcbau: goto P_0c03fcba;
case 0x0c03fcbcu: goto P_0c03fcbc;
case 0x0c03fcbeu: goto P_0c03fcbe;
case 0x0c03fcc0u: goto P_0c03fcc0;
case 0x0c03fcc2u: goto P_0c03fcc2;
case 0x0c03fcc4u: goto P_0c03fcc4;
case 0x0c03fcc6u: goto P_0c03fcc6;
case 0x0c03fcc8u: goto P_0c03fcc8;
case 0x0c03fccau: goto P_0c03fcca;
case 0x0c03fcccu: goto P_0c03fccc;
case 0x0c03fcceu: goto P_0c03fcce;
case 0x0c03fcd0u: goto P_0c03fcd0;
case 0x0c03fcd2u: goto P_0c03fcd2;
case 0x0c03fcd4u: goto P_0c03fcd4;
case 0x0c03fcd6u: goto P_0c03fcd6;
case 0x0c03fcd8u: goto P_0c03fcd8;
case 0x0c03fcdau: goto P_0c03fcda;
case 0x0c03fcdcu: goto P_0c03fcdc;
case 0x0c03fcdeu: goto P_0c03fcde;
case 0x0c03fce0u: goto P_0c03fce0;
case 0x0c03fce2u: goto P_0c03fce2;
case 0x0c03fce4u: goto P_0c03fce4;
case 0x0c03fce6u: goto P_0c03fce6;
case 0x0c03fce8u: goto P_0c03fce8;
case 0x0c03fceau: goto P_0c03fcea;
case 0x0c03fcecu: goto P_0c03fcec;
case 0x0c03fd02u: goto P_0c03fd02;
case 0x0c03fd04u: goto P_0c03fd04;
case 0x0c03fd06u: goto P_0c03fd06;
case 0x0c03fd08u: goto P_0c03fd08;
case 0x0c03fd0au: goto P_0c03fd0a;
case 0x0c03fd10u: goto P_0c03fd10;
case 0x0c03fd12u: goto P_0c03fd12;
case 0x0c03fd14u: goto P_0c03fd14;
case 0x0c03fd16u: goto P_0c03fd16;
case 0x0c03fd18u: goto P_0c03fd18;
case 0x0c03fd1au: goto P_0c03fd1a;
case 0x0c03fd1cu: goto P_0c03fd1c;
case 0x0c03fd1eu: goto P_0c03fd1e;
case 0x0c03fd20u: goto P_0c03fd20;
case 0x0c03fd22u: goto P_0c03fd22;
case 0x0c03fd24u: goto P_0c03fd24;
case 0x0c03fd26u: goto P_0c03fd26;
case 0x0c03fd28u: goto P_0c03fd28;
case 0x0c03fd2au: goto P_0c03fd2a;
case 0x0c03fd2cu: goto P_0c03fd2c;
case 0x0c03fd2eu: goto P_0c03fd2e;
case 0x0c03fd30u: goto P_0c03fd30;
case 0x0c03fd32u: goto P_0c03fd32;
case 0x0c03fd34u: goto P_0c03fd34;
case 0x0c03fd36u: goto P_0c03fd36;
case 0x0c03fd38u: goto P_0c03fd38;
case 0x0c03fd3au: goto P_0c03fd3a;
case 0x0c03fd3cu: goto P_0c03fd3c;
case 0x0c03fd3eu: goto P_0c03fd3e;
case 0x0c03fd40u: goto P_0c03fd40;
case 0x0c03fd42u: goto P_0c03fd42;
case 0x0c03fd44u: goto P_0c03fd44;
case 0x0c03fd70u: goto P_0c03fd70;
case 0x0c03fd72u: goto P_0c03fd72;
case 0x0c03fd74u: goto P_0c03fd74;
case 0x0c03fd76u: goto P_0c03fd76;
case 0x0c03fd78u: goto P_0c03fd78;
case 0x0c03fd7au: goto P_0c03fd7a;
case 0x0c03fd7cu: goto P_0c03fd7c;
case 0x0c03fd7eu: goto P_0c03fd7e;
case 0x0c03fd80u: goto P_0c03fd80;
case 0x0c03fd82u: goto P_0c03fd82;
case 0x0c03fd84u: goto P_0c03fd84;
case 0x0c03fd86u: goto P_0c03fd86;
case 0x0c03fd88u: goto P_0c03fd88;
case 0x0c03fd8au: goto P_0c03fd8a;
case 0x0c03fd8cu: goto P_0c03fd8c;
case 0x0c03fd8eu: goto P_0c03fd8e;
case 0x0c03fd90u: goto P_0c03fd90;
case 0x0c03fd92u: goto P_0c03fd92;
case 0x0c03fd94u: goto P_0c03fd94;
case 0x0c042c20u: goto P_0c042c20;
case 0x0c042c22u: goto P_0c042c22;
case 0x0c042c24u: goto P_0c042c24;
case 0x0c042c26u: goto P_0c042c26;
case 0x0c042c28u: goto P_0c042c28;
case 0x0c042c2au: goto P_0c042c2a;
case 0x0c042c2cu: goto P_0c042c2c;
case 0x0c042c2eu: goto P_0c042c2e;
case 0x0c042c30u: goto P_0c042c30;
case 0x0c042c32u: goto P_0c042c32;
case 0x0c042c34u: goto P_0c042c34;
case 0x0c042c36u: goto P_0c042c36;
case 0x0c042c38u: goto P_0c042c38;
case 0x0c042c3au: goto P_0c042c3a;
case 0x0c042c3cu: goto P_0c042c3c;
case 0x0c042c3eu: goto P_0c042c3e;
case 0x0c042c40u: goto P_0c042c40;
case 0x0c042c42u: goto P_0c042c42;
case 0x0c042c44u: goto P_0c042c44;
case 0x0c042c46u: goto P_0c042c46;
case 0x0c042c48u: goto P_0c042c48;
case 0x0c042c4au: goto P_0c042c4a;
case 0x0c042c4cu: goto P_0c042c4c;
case 0x0c042c4eu: goto P_0c042c4e;
case 0x0c042c50u: goto P_0c042c50;
case 0x0c042c52u: goto P_0c042c52;
case 0x0c042c54u: goto P_0c042c54;
case 0x0c042c56u: goto P_0c042c56;
case 0x0c042c58u: goto P_0c042c58;
case 0x0c042c5au: goto P_0c042c5a;
case 0x0c042c5cu: goto P_0c042c5c;
case 0x0c042c5eu: goto P_0c042c5e;
case 0x0c042c60u: goto P_0c042c60;
case 0x0c042c62u: goto P_0c042c62;
case 0x0c042c64u: goto P_0c042c64;
case 0x0c042c66u: goto P_0c042c66;
case 0x0c042c68u: goto P_0c042c68;
case 0x0c042c6au: goto P_0c042c6a;
case 0x0c042c6cu: goto P_0c042c6c;
case 0x0c042c6eu: goto P_0c042c6e;
case 0x0c042c70u: goto P_0c042c70;
case 0x0c042c72u: goto P_0c042c72;
case 0x0c042c74u: goto P_0c042c74;
case 0x0c042c76u: goto P_0c042c76;
case 0x0c042c78u: goto P_0c042c78;
case 0x0c042c7au: goto P_0c042c7a;
case 0x0c042c7cu: goto P_0c042c7c;
case 0x0c042c7eu: goto P_0c042c7e;
case 0x0c042c80u: goto P_0c042c80;
case 0x0c042c82u: goto P_0c042c82;
case 0x0c042c84u: goto P_0c042c84;
case 0x0c042c86u: goto P_0c042c86;
case 0x0c042c88u: goto P_0c042c88;
case 0x0c042c8au: goto P_0c042c8a;
case 0x0c042c8cu: goto P_0c042c8c;
case 0x0c042c8eu: goto P_0c042c8e;
case 0x0c042c90u: goto P_0c042c90;
case 0x0c042c92u: goto P_0c042c92;
case 0x0c042c94u: goto P_0c042c94;
case 0x0c042c96u: goto P_0c042c96;
case 0x0c042c98u: goto P_0c042c98;
case 0x0c042c9au: goto P_0c042c9a;
case 0x0c042c9cu: goto P_0c042c9c;
case 0x0c042c9eu: goto P_0c042c9e;
case 0x0c042ca0u: goto P_0c042ca0;
case 0x0c042ca2u: goto P_0c042ca2;
case 0x0c042ca4u: goto P_0c042ca4;
case 0x0c042ca6u: goto P_0c042ca6;
case 0x0c042ca8u: goto P_0c042ca8;
case 0x0c042caau: goto P_0c042caa;
case 0x0c042cacu: goto P_0c042cac;
case 0x0c042caeu: goto P_0c042cae;
case 0x0c042cb0u: goto P_0c042cb0;
case 0x0c042cb2u: goto P_0c042cb2;
case 0x0c042cb4u: goto P_0c042cb4;
case 0x0c042cb6u: goto P_0c042cb6;
case 0x0c042cb8u: goto P_0c042cb8;
case 0x0c042cbau: goto P_0c042cba;
case 0x0c042cbcu: goto P_0c042cbc;
case 0x0c042cbeu: goto P_0c042cbe;
case 0x0c042cc0u: goto P_0c042cc0;
case 0x0c042cc2u: goto P_0c042cc2;
case 0x0c042cc4u: goto P_0c042cc4;
case 0x0c042cc6u: goto P_0c042cc6;
case 0x0c042cc8u: goto P_0c042cc8;
case 0x0c042ccau: goto P_0c042cca;
case 0x0c0441b6u: goto P_0c0441b6;
case 0x0c0441b8u: goto P_0c0441b8;
case 0x0c0441bau: goto P_0c0441ba;
case 0x0c0441bcu: goto P_0c0441bc;
case 0x0c0441beu: goto P_0c0441be;
case 0x0c0441c0u: goto P_0c0441c0;
case 0x0c0441c2u: goto P_0c0441c2;
case 0x0c0441c4u: goto P_0c0441c4;
case 0x0c0441c6u: goto P_0c0441c6;
case 0x0c0441c8u: goto P_0c0441c8;
case 0x0c0441cau: goto P_0c0441ca;
case 0x0c0441ccu: goto P_0c0441cc;
case 0x0c0441ceu: goto P_0c0441ce;
case 0x0c0441d0u: goto P_0c0441d0;
case 0x0c0441d2u: goto P_0c0441d2;
case 0x0c0441d4u: goto P_0c0441d4;
case 0x0c0441d6u: goto P_0c0441d6;
case 0x0c0441d8u: goto P_0c0441d8;
case 0x0c0441dau: goto P_0c0441da;
case 0x0c0441dcu: goto P_0c0441dc;
case 0x0c0441deu: goto P_0c0441de;
case 0x0c0441e0u: goto P_0c0441e0;
case 0x0c0441e2u: goto P_0c0441e2;
case 0x0c0441e4u: goto P_0c0441e4;
case 0x0c044234u: goto P_0c044234;
case 0x0c044236u: goto P_0c044236;
case 0x0c044238u: goto P_0c044238;
case 0x0c04423au: goto P_0c04423a;
case 0x0c04423cu: goto P_0c04423c;
case 0x0c04423eu: goto P_0c04423e;
case 0x0c044240u: goto P_0c044240;
case 0x0c044242u: goto P_0c044242;
case 0x0c044244u: goto P_0c044244;
case 0x0c044246u: goto P_0c044246;
case 0x0c044248u: goto P_0c044248;
case 0x0c04424au: goto P_0c04424a;
case 0x0c04424cu: goto P_0c04424c;
case 0x0c04424eu: goto P_0c04424e;
case 0x0c044250u: goto P_0c044250;
case 0x0c044252u: goto P_0c044252;
case 0x0c044254u: goto P_0c044254;
case 0x0c044256u: goto P_0c044256;
case 0x0c044258u: goto P_0c044258;
case 0x0c04425au: goto P_0c04425a;
case 0x0c04425cu: goto P_0c04425c;
case 0x0c04425eu: goto P_0c04425e;
case 0x0c044260u: goto P_0c044260;
case 0x0c044262u: goto P_0c044262;
case 0x0c044264u: goto P_0c044264;
case 0x0c044266u: goto P_0c044266;
case 0x0c044268u: goto P_0c044268;
case 0x0c04426au: goto P_0c04426a;
case 0x0c04426cu: goto P_0c04426c;
case 0x0c04426eu: goto P_0c04426e;
case 0x0c044270u: goto P_0c044270;
case 0x0c044272u: goto P_0c044272;
case 0x0c044274u: goto P_0c044274;
case 0x0c044276u: goto P_0c044276;
case 0x0c044278u: goto P_0c044278;
case 0x0c04427au: goto P_0c04427a;
case 0x0c04427cu: goto P_0c04427c;
case 0x0c04427eu: goto P_0c04427e;
case 0x0c044280u: goto P_0c044280;
case 0x0c044282u: goto P_0c044282;
case 0x0c044284u: goto P_0c044284;
case 0x0c044286u: goto P_0c044286;
case 0x0c044288u: goto P_0c044288;
case 0x0c04428au: goto P_0c04428a;
case 0x0c04428cu: goto P_0c04428c;
case 0x0c04428eu: goto P_0c04428e;
case 0x0c044290u: goto P_0c044290;
case 0x0c044292u: goto P_0c044292;
case 0x0c044302u: goto P_0c044302;
case 0x0c044304u: goto P_0c044304;
case 0x0c044306u: goto P_0c044306;
case 0x0c044308u: goto P_0c044308;
case 0x0c04430au: goto P_0c04430a;
case 0x0c04430cu: goto P_0c04430c;
case 0x0c04430eu: goto P_0c04430e;
case 0x0c044310u: goto P_0c044310;
case 0x0c044312u: goto P_0c044312;
case 0x0c044314u: goto P_0c044314;
case 0x0c044316u: goto P_0c044316;
case 0x0c044318u: goto P_0c044318;
case 0x0c04431au: goto P_0c04431a;
case 0x0c04431cu: goto P_0c04431c;
case 0x0c04431eu: goto P_0c04431e;
case 0x0c044320u: goto P_0c044320;
case 0x0c044322u: goto P_0c044322;
case 0x0c044324u: goto P_0c044324;
case 0x0c044326u: goto P_0c044326;
case 0x0c044328u: goto P_0c044328;
case 0x0c04432au: goto P_0c04432a;
case 0x0c04432cu: goto P_0c04432c;
case 0x0c04432eu: goto P_0c04432e;
case 0x0c044330u: goto P_0c044330;
case 0x0c044332u: goto P_0c044332;
case 0x0c044334u: goto P_0c044334;
case 0x0c044336u: goto P_0c044336;
case 0x0c044338u: goto P_0c044338;
case 0x0c04433au: goto P_0c04433a;
case 0x0c04433cu: goto P_0c04433c;
case 0x0c04433eu: goto P_0c04433e;
case 0x0c044340u: goto P_0c044340;
case 0x0c044342u: goto P_0c044342;
case 0x0c044344u: goto P_0c044344;
case 0x0c044346u: goto P_0c044346;
case 0x0c044348u: goto P_0c044348;
case 0x0c04434au: goto P_0c04434a;
case 0x0c04434cu: goto P_0c04434c;
case 0x0c04434eu: goto P_0c04434e;
case 0x0c044350u: goto P_0c044350;
case 0x0c044352u: goto P_0c044352;
case 0x0c044354u: goto P_0c044354;
case 0x0c044356u: goto P_0c044356;
case 0x0c044358u: goto P_0c044358;
case 0x0c04435au: goto P_0c04435a;
case 0x0c04435cu: goto P_0c04435c;
case 0x0c04435eu: goto P_0c04435e;
case 0x0c044360u: goto P_0c044360;
case 0x0c044362u: goto P_0c044362;
case 0x0c044364u: goto P_0c044364;
case 0x0c044366u: goto P_0c044366;
case 0x0c044368u: goto P_0c044368;
case 0x0c06f814u: goto P_0c06f814;
case 0x0c06f816u: goto P_0c06f816;
case 0x0c06f818u: goto P_0c06f818;
case 0x0c06f81au: goto P_0c06f81a;
case 0x0c06f81cu: goto P_0c06f81c;
case 0x0c06f81eu: goto P_0c06f81e;
case 0x0c06f820u: goto P_0c06f820;
case 0x0c06f822u: goto P_0c06f822;
case 0x0c06f824u: goto P_0c06f824;
case 0x0c06f826u: goto P_0c06f826;
case 0x0c06f828u: goto P_0c06f828;
case 0x0c06f82au: goto P_0c06f82a;
case 0x0c06f82cu: goto P_0c06f82c;
case 0x0c06f82eu: goto P_0c06f82e;
case 0x0c06f830u: goto P_0c06f830;
case 0x0c06f832u: goto P_0c06f832;
case 0x0c06f834u: goto P_0c06f834;
case 0x0c06f836u: goto P_0c06f836;
case 0x0c06f838u: goto P_0c06f838;
case 0x0c06f83au: goto P_0c06f83a;
case 0x0c06f83cu: goto P_0c06f83c;
case 0x0c06f83eu: goto P_0c06f83e;
case 0x0c06f840u: goto P_0c06f840;
case 0x0c06f842u: goto P_0c06f842;
case 0x0c06f844u: goto P_0c06f844;
case 0x0c06f846u: goto P_0c06f846;
case 0x0c06f848u: goto P_0c06f848;
case 0x0c06f84au: goto P_0c06f84a;
case 0x0c06f84cu: goto P_0c06f84c;
case 0x0c06f84eu: goto P_0c06f84e;
case 0x0c06f850u: goto P_0c06f850;
case 0x0c06f852u: goto P_0c06f852;
case 0x0c06f854u: goto P_0c06f854;
case 0x0c06f856u: goto P_0c06f856;
case 0x0c06f858u: goto P_0c06f858;
case 0x0c06f85au: goto P_0c06f85a;
case 0x0c06f85cu: goto P_0c06f85c;
case 0x0c06f85eu: goto P_0c06f85e;
case 0x0c06f860u: goto P_0c06f860;
case 0x0c06f862u: goto P_0c06f862;
case 0x0c06f864u: goto P_0c06f864;
case 0x0c06f866u: goto P_0c06f866;
case 0x0c06f868u: goto P_0c06f868;
case 0x0c06f86au: goto P_0c06f86a;
case 0x0c06f86cu: goto P_0c06f86c;
case 0x0c06f86eu: goto P_0c06f86e;
case 0x0c06f870u: goto P_0c06f870;
case 0x0c06f872u: goto P_0c06f872;
case 0x0c06f874u: goto P_0c06f874;
case 0x0c06f876u: goto P_0c06f876;
case 0x0c06f878u: goto P_0c06f878;
case 0x0c06f87au: goto P_0c06f87a;
case 0x0c06f87cu: goto P_0c06f87c;
case 0x0c06f87eu: goto P_0c06f87e;
case 0x0c06f880u: goto P_0c06f880;
case 0x0c06f882u: goto P_0c06f882;
case 0x0c06f884u: goto P_0c06f884;
case 0x0c06f886u: goto P_0c06f886;
case 0x0c06f888u: goto P_0c06f888;
case 0x0c06f88au: goto P_0c06f88a;
case 0x0c06f88cu: goto P_0c06f88c;
case 0x0c06f88eu: goto P_0c06f88e;
case 0x0c06f890u: goto P_0c06f890;
case 0x0c06f892u: goto P_0c06f892;
case 0x0c06f894u: goto P_0c06f894;
case 0x0c06f896u: goto P_0c06f896;
case 0x0c06f898u: goto P_0c06f898;
case 0x0c06f89au: goto P_0c06f89a;
case 0x0c06f89cu: goto P_0c06f89c;
case 0x0c06f89eu: goto P_0c06f89e;
case 0x0c06f8a0u: goto P_0c06f8a0;
case 0x0c06f8a2u: goto P_0c06f8a2;
case 0x0c06f8a4u: goto P_0c06f8a4;
case 0x0c06f8a6u: goto P_0c06f8a6;
case 0x0c06f8a8u: goto P_0c06f8a8;
case 0x0c06f8aau: goto P_0c06f8aa;
case 0x0c06f8acu: goto P_0c06f8ac;
case 0x0c06f8aeu: goto P_0c06f8ae;
case 0x0c06f8b0u: goto P_0c06f8b0;
case 0x0c06f8b2u: goto P_0c06f8b2;
case 0x0c06f8b4u: goto P_0c06f8b4;
case 0x0c06f8b6u: goto P_0c06f8b6;
case 0x0c06f8b8u: goto P_0c06f8b8;
case 0x0c06f8bau: goto P_0c06f8ba;
case 0x0c06f8bcu: goto P_0c06f8bc;
case 0x0c06f8beu: goto P_0c06f8be;
case 0x0c06f8c0u: goto P_0c06f8c0;
case 0x0c06f8c2u: goto P_0c06f8c2;
case 0x0c06f8c4u: goto P_0c06f8c4;
case 0x0c06f8c6u: goto P_0c06f8c6;
case 0x0c06f8c8u: goto P_0c06f8c8;
case 0x0c06f8cau: goto P_0c06f8ca;
case 0x0c06f8ccu: goto P_0c06f8cc;
case 0x0c06f8ceu: goto P_0c06f8ce;
case 0x0c06f8d0u: goto P_0c06f8d0;
case 0x0c06f8d2u: goto P_0c06f8d2;
case 0x0c06f8d4u: goto P_0c06f8d4;
case 0x0c06f8d6u: goto P_0c06f8d6;
case 0x0c06f8d8u: goto P_0c06f8d8;
case 0x0c06f8dau: goto P_0c06f8da;
case 0x0c06f8dcu: goto P_0c06f8dc;
case 0x0c06f8deu: goto P_0c06f8de;
case 0x0c06f8e0u: goto P_0c06f8e0;
case 0x0c06f8e2u: goto P_0c06f8e2;
case 0x0c06f8e4u: goto P_0c06f8e4;
case 0x0c06f8e6u: goto P_0c06f8e6;
case 0x0c06f8e8u: goto P_0c06f8e8;
case 0x0c06f8eau: goto P_0c06f8ea;
case 0x0c06f8ecu: goto P_0c06f8ec;
case 0x0c06f8eeu: goto P_0c06f8ee;
case 0x0c06f8f0u: goto P_0c06f8f0;
case 0x0c06f8f2u: goto P_0c06f8f2;
case 0x0c06f8f4u: goto P_0c06f8f4;
case 0x0c06f8f6u: goto P_0c06f8f6;
case 0x0c06f8f8u: goto P_0c06f8f8;
case 0x0c06f8fau: goto P_0c06f8fa;
case 0x0c06f8fcu: goto P_0c06f8fc;
case 0x0c06f8feu: goto P_0c06f8fe;
case 0x0c06f900u: goto P_0c06f900;
case 0x0c06f902u: goto P_0c06f902;
case 0x0c06f904u: goto P_0c06f904;
case 0x0c06f906u: goto P_0c06f906;
case 0x0c06f908u: goto P_0c06f908;
case 0x0c06f90au: goto P_0c06f90a;
case 0x0c06f90cu: goto P_0c06f90c;
case 0x0c06f90eu: goto P_0c06f90e;
case 0x0c06f910u: goto P_0c06f910;
case 0x0c06f912u: goto P_0c06f912;
case 0x0c06f914u: goto P_0c06f914;
case 0x0c06f916u: goto P_0c06f916;
case 0x0c06f918u: goto P_0c06f918;
case 0x0c06f91au: goto P_0c06f91a;
case 0x0c06f91cu: goto P_0c06f91c;
case 0x0c06f91eu: goto P_0c06f91e;
case 0x0c06f920u: goto P_0c06f920;
case 0x0c06f922u: goto P_0c06f922;
case 0x0c06f924u: goto P_0c06f924;
case 0x0c06f926u: goto P_0c06f926;
case 0x0c06f928u: goto P_0c06f928;
case 0x0c06f92au: goto P_0c06f92a;
case 0x0c06f92cu: goto P_0c06f92c;
case 0x0c06f92eu: goto P_0c06f92e;
case 0x0c06f930u: goto P_0c06f930;
case 0x0c06f932u: goto P_0c06f932;
case 0x0c06f934u: goto P_0c06f934;
case 0x0c06f936u: goto P_0c06f936;
case 0x0c06f938u: goto P_0c06f938;
case 0x0c06f93au: goto P_0c06f93a;
case 0x0c06f93cu: goto P_0c06f93c;
case 0x0c06f93eu: goto P_0c06f93e;
case 0x0c06f940u: goto P_0c06f940;
case 0x0c06f942u: goto P_0c06f942;
case 0x0c06f944u: goto P_0c06f944;
case 0x0c06f946u: goto P_0c06f946;
case 0x0c06f948u: goto P_0c06f948;
case 0x0c06f94au: goto P_0c06f94a;
case 0x0c06f94cu: goto P_0c06f94c;
case 0x0c06f94eu: goto P_0c06f94e;
case 0x0c06f950u: goto P_0c06f950;
case 0x0c06f952u: goto P_0c06f952;
case 0x0c06f954u: goto P_0c06f954;
case 0x0c06f956u: goto P_0c06f956;
case 0x0c06f958u: goto P_0c06f958;
case 0x0c06f95au: goto P_0c06f95a;
case 0x0c06f95cu: goto P_0c06f95c;
case 0x0c06f95eu: goto P_0c06f95e;
case 0x0c06f960u: goto P_0c06f960;
case 0x0c06f962u: goto P_0c06f962;
case 0x0c06f964u: goto P_0c06f964;
case 0x0c06f966u: goto P_0c06f966;
case 0x0c06f968u: goto P_0c06f968;
case 0x0c06f96au: goto P_0c06f96a;
case 0x0c06f96cu: goto P_0c06f96c;
case 0x0c06f96eu: goto P_0c06f96e;
case 0x0c06f970u: goto P_0c06f970;
case 0x0c06f972u: goto P_0c06f972;
case 0x0c06f974u: goto P_0c06f974;
case 0x0c06f976u: goto P_0c06f976;
case 0x0c06f978u: goto P_0c06f978;
case 0x0c06f97au: goto P_0c06f97a;
case 0x0c06f97cu: goto P_0c06f97c;
case 0x0c06f97eu: goto P_0c06f97e;
case 0x0c06f980u: goto P_0c06f980;
case 0x0c06f982u: goto P_0c06f982;
case 0x0c06f984u: goto P_0c06f984;
case 0x0c06f986u: goto P_0c06f986;
case 0x0c06f988u: goto P_0c06f988;
case 0x0c06f98au: goto P_0c06f98a;
case 0x0c06f98cu: goto P_0c06f98c;
case 0x0c06f98eu: goto P_0c06f98e;
case 0x0c06f990u: goto P_0c06f990;
default: return vf3_matrix_family(target,s,ram);
}
P_0c038a20: /* original e23c, guest PC 0x0c038a20 */
if(!s->budget--) { s->failed_pc=0x0c038a20u; return 0; }
r[2]=0x0000003cu;
goto P_0c038a22;
P_0c038a22: /* original d036, guest PC 0x0c038a22 */
if(!s->budget--) { s->failed_pc=0x0c038a22u; return 0; }
r[0]=read(ram,0x0c038afcu,4);
goto P_0c038a24;
P_0c038a24: /* original 4f12, guest PC 0x0c038a24 */
if(!s->budget--) { s->failed_pc=0x0c038a24u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c038a26;
P_0c038a26: /* original 0527, guest PC 0x0c038a26 */
if(!s->budget--) { s->failed_pc=0x0c038a26u; return 0; }
r[19]=r[5]*r[2];
goto P_0c038a28;
P_0c038a28: /* original 6102, guest PC 0x0c038a28 */
if(!s->budget--) { s->failed_pc=0x0c038a28u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c038a2a;
P_0c038a2a: /* original e3c0, guest PC 0x0c038a2a */
if(!s->budget--) { s->failed_pc=0x0c038a2au; return 0; }
r[3]=0xffffffc0u;
goto P_0c038a2c;
P_0c038a2c: /* original 5642, guest PC 0x0c038a2c */
if(!s->budget--) { s->failed_pc=0x0c038a2cu; return 0; }
r[6]=read(ram,r[4]+8,4);
goto P_0c038a2e;
P_0c038a2e: /* original e700, guest PC 0x0c038a2e */
if(!s->budget--) { s->failed_pc=0x0c038a2eu; return 0; }
r[7]=0x00000000u;
goto P_0c038a30;
P_0c038a30: /* original 051a, guest PC 0x0c038a30 */
if(!s->budget--) { s->failed_pc=0x0c038a30u; return 0; }
r[5]=r[19];
goto P_0c038a32;
P_0c038a32: /* original 2639, guest PC 0x0c038a32 */
if(!s->budget--) { s->failed_pc=0x0c038a32u; return 0; }
r[6]&=r[3];
goto P_0c038a34;
P_0c038a34: /* original 351c, guest PC 0x0c038a34 */
if(!s->budget--) { s->failed_pc=0x0c038a34u; return 0; }
r[5]+=r[1];
goto P_0c038a36;
P_0c038a36: /* original 525d, guest PC 0x0c038a36 */
if(!s->budget--) { s->failed_pc=0x0c038a36u; return 0; }
r[2]=read(ram,r[5]+52,4);
goto P_0c038a38;
P_0c038a38: /* original 535c, guest PC 0x0c038a38 */
if(!s->budget--) { s->failed_pc=0x0c038a38u; return 0; }
r[3]=read(ram,r[5]+48,4);
goto P_0c038a3a;
P_0c038a3a: /* original 272b, guest PC 0x0c038a3a */
if(!s->budget--) { s->failed_pc=0x0c038a3au; return 0; }
r[7]|=r[2];
goto P_0c038a3c;
P_0c038a3c: /* original 263b, guest PC 0x0c038a3c */
if(!s->budget--) { s->failed_pc=0x0c038a3cu; return 0; }
r[6]|=r[3];
goto P_0c038a3e;
P_0c038a3e: /* original 1462, guest PC 0x0c038a3e */
if(!s->budget--) { s->failed_pc=0x0c038a3eu; return 0; }
write(ram,r[4]+8,r[6],4);
goto P_0c038a40;
P_0c038a40: /* original 1473, guest PC 0x0c038a40 */
if(!s->budget--) { s->failed_pc=0x0c038a40u; return 0; }
write(ram,r[4]+12,r[7],4);
goto P_0c038a42;
P_0c038a42: /* original 000b, guest PC 0x0c038a42 */
if(!s->budget--) { s->failed_pc=0x0c038a42u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c038a44: /* original 4f16, guest PC 0x0c038a44 */
if(!s->budget--) { s->failed_pc=0x0c038a44u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c038a46u,s,ram);
P_0c03f77e: /* original 4f22, guest PC 0x0c03f77e */
if(!s->budget--) { s->failed_pc=0x0c03f77eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f780;
P_0c03f780: /* original db06, guest PC 0x0c03f780 */
if(!s->budget--) { s->failed_pc=0x0c03f780u; return 0; }
r[11]=read(ram,0x0c03f79cu,4);
goto P_0c03f782;
P_0c03f782: /* original d308, guest PC 0x0c03f782 */
if(!s->budget--) { s->failed_pc=0x0c03f782u; return 0; }
r[3]=read(ram,0x0c03f7a4u,4);
goto P_0c03f784;
P_0c03f784: /* original d902, guest PC 0x0c03f784 */
if(!s->budget--) { s->failed_pc=0x0c03f784u; return 0; }
r[9]=read(ram,0x0c03f790u,4);
goto P_0c03f786;
P_0c03f786: /* original da06, guest PC 0x0c03f786 */
if(!s->budget--) { s->failed_pc=0x0c03f786u; return 0; }
r[10]=read(ram,0x0c03f7a0u,4);
goto P_0c03f788;
P_0c03f788: /* original a035, guest PC 0x0c03f788 */
if(!s->budget--) { s->failed_pc=0x0c03f788u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c03f7f6;
P_0c03f78a: /* original 6e32, guest PC 0x0c03f78a */
if(!s->budget--) { s->failed_pc=0x0c03f78au; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
return vf3_matrix_family(0x0c03f78cu,s,ram);
P_0c03f7c0: /* original 64e3, guest PC 0x0c03f7c0 */
if(!s->budget--) { s->failed_pc=0x0c03f7c0u; return 0; }
r[4]=r[14];
goto P_0c03f7c2;
P_0c03f7c2: /* original 63a2, guest PC 0x0c03f7c2 */
if(!s->budget--) { s->failed_pc=0x0c03f7c2u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c03f7c4;
P_0c03f7c4: /* original 4408, guest PC 0x0c03f7c4 */
if(!s->budget--) { s->failed_pc=0x0c03f7c4u; return 0; }
r[4]<<=2;
goto P_0c03f7c6;
P_0c03f7c6: /* original 4400, guest PC 0x0c03f7c6 */
if(!s->budget--) { s->failed_pc=0x0c03f7c6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c03f7c8;
P_0c03f7c8: /* original 343c, guest PC 0x0c03f7c8 */
if(!s->budget--) { s->failed_pc=0x0c03f7c8u; return 0; }
r[4]+=r[3];
goto P_0c03f7ca;
P_0c03f7ca: /* original 6142, guest PC 0x0c03f7ca */
if(!s->budget--) { s->failed_pc=0x0c03f7cau; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c03f7cc;
P_0c03f7cc: /* original e200, guest PC 0x0c03f7cc */
if(!s->budget--) { s->failed_pc=0x0c03f7ccu; return 0; }
r[2]=0x00000000u;
goto P_0c03f7ce;
P_0c03f7ce: /* original 3126, guest PC 0x0c03f7ce */
if(!s->budget--) { s->failed_pc=0x0c03f7ceu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[2])!=0);
goto P_0c03f7d0;
P_0c03f7d0: /* original 8b0f, guest PC 0x0c03f7d0 */
if(!s->budget--) { s->failed_pc=0x0c03f7d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f7f2; }
goto P_0c03f7d2;
P_0c03f7d2: /* original 5541, guest PC 0x0c03f7d2 */
if(!s->budget--) { s->failed_pc=0x0c03f7d2u; return 0; }
r[5]=read(ram,r[4]+4,4);
goto P_0c03f7d4;
P_0c03f7d4: /* original 60e3, guest PC 0x0c03f7d4 */
if(!s->budget--) { s->failed_pc=0x0c03f7d4u; return 0; }
r[0]=r[14];
goto P_0c03f7d6;
P_0c03f7d6: /* original 0009, guest PC 0x0c03f7d6 */
if(!s->budget--) { s->failed_pc=0x0c03f7d6u; return 0; }
goto P_0c03f7d8;
P_0c03f7d8: /* original 6392, guest PC 0x0c03f7d8 */
if(!s->budget--) { s->failed_pc=0x0c03f7d8u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c03f7da;
P_0c03f7da: /* original 4000, guest PC 0x0c03f7da */
if(!s->budget--) { s->failed_pc=0x0c03f7dau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c03f7dc;
P_0c03f7dc: /* original 003d, guest PC 0x0c03f7dc */
if(!s->budget--) { s->failed_pc=0x0c03f7dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c03f7de;
P_0c03f7de: /* original 88ff, guest PC 0x0c03f7de */
if(!s->budget--) { s->failed_pc=0x0c03f7deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03f7e0;
P_0c03f7e0: /* original 8d07, guest PC 0x0c03f7e0 */
if(!s->budget--) { s->failed_pc=0x0c03f7e0u; return 0; }
cond=r[17]&1u;
r[13]=r[0];
if(cond) { goto P_0c03f7f2; }
goto P_0c03f7e4;
P_0c03f7e2: /* original 6d03, guest PC 0x0c03f7e2 */
if(!s->budget--) { s->failed_pc=0x0c03f7e2u; return 0; }
r[13]=r[0];
goto P_0c03f7e4;
P_0c03f7e4: /* original 64d3, guest PC 0x0c03f7e4 */
if(!s->budget--) { s->failed_pc=0x0c03f7e4u; return 0; }
r[4]=r[13];
goto P_0c03f7e6;
P_0c03f7e6: /* original 4408, guest PC 0x0c03f7e6 */
if(!s->budget--) { s->failed_pc=0x0c03f7e6u; return 0; }
r[4]<<=2;
goto P_0c03f7e8;
P_0c03f7e8: /* original 63b2, guest PC 0x0c03f7e8 */
if(!s->budget--) { s->failed_pc=0x0c03f7e8u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c03f7ea;
P_0c03f7ea: /* original 4408, guest PC 0x0c03f7ea */
if(!s->budget--) { s->failed_pc=0x0c03f7eau; return 0; }
r[4]<<=2;
goto P_0c03f7ec;
P_0c03f7ec: /* original 4400, guest PC 0x0c03f7ec */
if(!s->budget--) { s->failed_pc=0x0c03f7ecu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c03f7ee;
P_0c03f7ee: /* original b24f, guest PC 0x0c03f7ee */
if(!s->budget--) { s->failed_pc=0x0c03f7eeu; return 0; }
target=0x0c03fc90u; r[16]=0x0c03f7f2u;
r[4]+=r[3];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03f7f2u) { target=s->pc; goto dispatch; }
goto P_0c03f7f2;
P_0c03f7f0: /* original 343c, guest PC 0x0c03f7f0 */
if(!s->budget--) { s->failed_pc=0x0c03f7f0u; return 0; }
r[4]+=r[3];
goto P_0c03f7f2;
P_0c03f7f2: /* original 7e01, guest PC 0x0c03f7f2 */
if(!s->budget--) { s->failed_pc=0x0c03f7f2u; return 0; }
r[14]+=0x00000001u;
goto P_0c03f7f4;
P_0c03f7f4: /* original 7c10, guest PC 0x0c03f7f4 */
if(!s->budget--) { s->failed_pc=0x0c03f7f4u; return 0; }
r[12]+=0x00000010u;
goto P_0c03f7f6;
P_0c03f7f6: /* original 50c1, guest PC 0x0c03f7f6 */
if(!s->budget--) { s->failed_pc=0x0c03f7f6u; return 0; }
r[0]=read(ram,r[12]+4,4);
goto P_0c03f7f8;
P_0c03f7f8: /* original 88ff, guest PC 0x0c03f7f8 */
if(!s->budget--) { s->failed_pc=0x0c03f7f8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03f7fa;
P_0c03f7fa: /* original 8be1, guest PC 0x0c03f7fa */
if(!s->budget--) { s->failed_pc=0x0c03f7fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f7c0; }
goto P_0c03f7fc;
P_0c03f7fc: /* original 4f26, guest PC 0x0c03f7fc */
if(!s->budget--) { s->failed_pc=0x0c03f7fcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f7fe;
P_0c03f7fe: /* original 69f6, guest PC 0x0c03f7fe */
if(!s->budget--) { s->failed_pc=0x0c03f7feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03f800;
P_0c03f800: /* original 6af6, guest PC 0x0c03f800 */
if(!s->budget--) { s->failed_pc=0x0c03f800u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03f802;
P_0c03f802: /* original 6bf6, guest PC 0x0c03f802 */
if(!s->budget--) { s->failed_pc=0x0c03f802u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f804;
P_0c03f804: /* original 6cf6, guest PC 0x0c03f804 */
if(!s->budget--) { s->failed_pc=0x0c03f804u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f806;
P_0c03f806: /* original 6df6, guest PC 0x0c03f806 */
if(!s->budget--) { s->failed_pc=0x0c03f806u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f808;
P_0c03f808: /* original 000b, guest PC 0x0c03f808 */
if(!s->budget--) { s->failed_pc=0x0c03f808u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f80a: /* original 6ef6, guest PC 0x0c03f80a */
if(!s->budget--) { s->failed_pc=0x0c03f80au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03f80cu,s,ram);
P_0c03fc90: /* original 2fe6, guest PC 0x0c03fc90 */
if(!s->budget--) { s->failed_pc=0x0c03fc90u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c03fc92;
P_0c03fc92: /* original 6e43, guest PC 0x0c03fc92 */
if(!s->budget--) { s->failed_pc=0x0c03fc92u; return 0; }
r[14]=r[4];
goto P_0c03fc94;
P_0c03fc94: /* original d32d, guest PC 0x0c03fc94 */
if(!s->budget--) { s->failed_pc=0x0c03fc94u; return 0; }
r[3]=read(ram,0x0c03fd4cu,4);
goto P_0c03fc96;
P_0c03fc96: /* original 4f22, guest PC 0x0c03fc96 */
if(!s->budget--) { s->failed_pc=0x0c03fc96u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03fc98;
P_0c03fc98: /* original 2e32, guest PC 0x0c03fc98 */
if(!s->budget--) { s->failed_pc=0x0c03fc98u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c03fc9a;
P_0c03fc9a: /* original d22d, guest PC 0x0c03fc9a */
if(!s->budget--) { s->failed_pc=0x0c03fc9au; return 0; }
r[2]=read(ram,0x0c03fd50u,4);
goto P_0c03fc9c;
P_0c03fc9c: /* original 1e21, guest PC 0x0c03fc9c */
if(!s->budget--) { s->failed_pc=0x0c03fc9cu; return 0; }
write(ram,r[14]+4,r[2],4);
goto P_0c03fc9e;
P_0c03fc9e: /* original e200, guest PC 0x0c03fc9e */
if(!s->budget--) { s->failed_pc=0x0c03fc9eu; return 0; }
r[2]=0x00000000u;
goto P_0c03fca0;
P_0c03fca0: /* original 9352, guest PC 0x0c03fca0 */
if(!s->budget--) { s->failed_pc=0x0c03fca0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03fd48u,2);
goto P_0c03fca2;
P_0c03fca2: /* original 1e32, guest PC 0x0c03fca2 */
if(!s->budget--) { s->failed_pc=0x0c03fca2u; return 0; }
write(ram,r[14]+8,r[3],4);
goto P_0c03fca4;
P_0c03fca4: /* original 1e23, guest PC 0x0c03fca4 */
if(!s->budget--) { s->failed_pc=0x0c03fca4u; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c03fca6;
P_0c03fca6: /* original d32b, guest PC 0x0c03fca6 */
if(!s->budget--) { s->failed_pc=0x0c03fca6u; return 0; }
r[3]=read(ram,0x0c03fd54u,4);
goto P_0c03fca8;
P_0c03fca8: /* original 430b, guest PC 0x0c03fca8 */
if(!s->budget--) { s->failed_pc=0x0c03fca8u; return 0; }
target=r[3];
r[16]=0x0c03fcacu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03fcacu) { target=s->pc; goto dispatch; }
goto P_0c03fcac;
P_0c03fcaa: /* original 64e3, guest PC 0x0c03fcaa */
if(!s->budget--) { s->failed_pc=0x0c03fcaau; return 0; }
r[4]=r[14];
goto P_0c03fcac;
P_0c03fcac: /* original 55e3, guest PC 0x0c03fcac */
if(!s->budget--) { s->failed_pc=0x0c03fcacu; return 0; }
r[5]=read(ram,r[14]+12,4);
goto P_0c03fcae;
P_0c03fcae: /* original e3e5, guest PC 0x0c03fcae */
if(!s->budget--) { s->failed_pc=0x0c03fcaeu; return 0; }
r[3]=0xffffffe5u;
goto P_0c03fcb0;
P_0c03fcb0: /* original e407, guest PC 0x0c03fcb0 */
if(!s->budget--) { s->failed_pc=0x0c03fcb0u; return 0; }
r[4]=0x00000007u;
goto P_0c03fcb2;
P_0c03fcb2: /* original 453d, guest PC 0x0c03fcb2 */
if(!s->budget--) { s->failed_pc=0x0c03fcb2u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c03fcb4;
P_0c03fcb4: /* original 2549, guest PC 0x0c03fcb4 */
if(!s->budget--) { s->failed_pc=0x0c03fcb4u; return 0; }
r[5]&=r[4];
goto P_0c03fcb6;
P_0c03fcb6: /* original 2558, guest PC 0x0c03fcb6 */
if(!s->budget--) { s->failed_pc=0x0c03fcb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c03fcb8;
P_0c03fcb8: /* original e200, guest PC 0x0c03fcb8 */
if(!s->budget--) { s->failed_pc=0x0c03fcb8u; return 0; }
r[2]=0x00000000u;
goto P_0c03fcba;
P_0c03fcba: /* original 8d04, guest PC 0x0c03fcba */
if(!s->budget--) { s->failed_pc=0x0c03fcbau; return 0; }
cond=r[17]&1u;
write(ram,r[14]+20,r[2],4);
if(cond) { goto P_0c03fcc6; }
goto P_0c03fcbe;
P_0c03fcbc: /* original 1e25, guest PC 0x0c03fcbc */
if(!s->budget--) { s->failed_pc=0x0c03fcbcu; return 0; }
write(ram,r[14]+20,r[2],4);
goto P_0c03fcbe;
P_0c03fcbe: /* original 6053, guest PC 0x0c03fcbe */
if(!s->budget--) { s->failed_pc=0x0c03fcbeu; return 0; }
r[0]=r[5];
goto P_0c03fcc0;
P_0c03fcc0: /* original 0009, guest PC 0x0c03fcc0 */
if(!s->budget--) { s->failed_pc=0x0c03fcc0u; return 0; }
goto P_0c03fcc2;
P_0c03fcc2: /* original 8802, guest PC 0x0c03fcc2 */
if(!s->budget--) { s->failed_pc=0x0c03fcc2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c03fcc4;
P_0c03fcc4: /* original 8b01, guest PC 0x0c03fcc4 */
if(!s->budget--) { s->failed_pc=0x0c03fcc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fcca; }
goto P_0c03fcc6;
P_0c03fcc6: /* original e301, guest PC 0x0c03fcc6 */
if(!s->budget--) { s->failed_pc=0x0c03fcc6u; return 0; }
r[3]=0x00000001u;
goto P_0c03fcc8;
P_0c03fcc8: /* original 1e35, guest PC 0x0c03fcc8 */
if(!s->budget--) { s->failed_pc=0x0c03fcc8u; return 0; }
write(ram,r[14]+20,r[3],4);
goto P_0c03fcca;
P_0c03fcca: /* original 50e2, guest PC 0x0c03fcca */
if(!s->budget--) { s->failed_pc=0x0c03fccau; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c03fccc;
P_0c03fccc: /* original d522, guest PC 0x0c03fccc */
if(!s->budget--) { s->failed_pc=0x0c03fcccu; return 0; }
r[5]=read(ram,0x0c03fd58u,4);
goto P_0c03fcce;
P_0c03fcce: /* original 4009, guest PC 0x0c03fcce */
if(!s->budget--) { s->failed_pc=0x0c03fcceu; return 0; }
r[0]>>=2;
goto P_0c03fcd0;
P_0c03fcd0: /* original 4001, guest PC 0x0c03fcd0 */
if(!s->budget--) { s->failed_pc=0x0c03fcd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c03fcd2;
P_0c03fcd2: /* original 2049, guest PC 0x0c03fcd2 */
if(!s->budget--) { s->failed_pc=0x0c03fcd2u; return 0; }
r[0]&=r[4];
goto P_0c03fcd4;
P_0c03fcd4: /* original 4008, guest PC 0x0c03fcd4 */
if(!s->budget--) { s->failed_pc=0x0c03fcd4u; return 0; }
r[0]<<=2;
goto P_0c03fcd6;
P_0c03fcd6: /* original f356, guest PC 0x0c03fcd6 */
if(!s->budget--) { s->failed_pc=0x0c03fcd6u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c03fcd8;
P_0c03fcd8: /* original e018, guest PC 0x0c03fcd8 */
if(!s->budget--) { s->failed_pc=0x0c03fcd8u; return 0; }
r[0]=0x00000018u;
goto P_0c03fcda;
P_0c03fcda: /* original 4f26, guest PC 0x0c03fcda */
if(!s->budget--) { s->failed_pc=0x0c03fcdau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03fcdc;
P_0c03fcdc: /* original fe37, guest PC 0x0c03fcdc */
if(!s->budget--) { s->failed_pc=0x0c03fcdcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c03fcde;
P_0c03fcde: /* original 50e2, guest PC 0x0c03fcde */
if(!s->budget--) { s->failed_pc=0x0c03fcdeu; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c03fce0;
P_0c03fce0: /* original 2049, guest PC 0x0c03fce0 */
if(!s->budget--) { s->failed_pc=0x0c03fce0u; return 0; }
r[0]&=r[4];
goto P_0c03fce2;
P_0c03fce2: /* original 4008, guest PC 0x0c03fce2 */
if(!s->budget--) { s->failed_pc=0x0c03fce2u; return 0; }
r[0]<<=2;
goto P_0c03fce4;
P_0c03fce4: /* original f356, guest PC 0x0c03fce4 */
if(!s->budget--) { s->failed_pc=0x0c03fce4u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c03fce6;
P_0c03fce6: /* original e01c, guest PC 0x0c03fce6 */
if(!s->budget--) { s->failed_pc=0x0c03fce6u; return 0; }
r[0]=0x0000001cu;
goto P_0c03fce8;
P_0c03fce8: /* original fe37, guest PC 0x0c03fce8 */
if(!s->budget--) { s->failed_pc=0x0c03fce8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c03fcea;
P_0c03fcea: /* original 000b, guest PC 0x0c03fcea */
if(!s->budget--) { s->failed_pc=0x0c03fceau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03fcec: /* original 6ef6, guest PC 0x0c03fcec */
if(!s->budget--) { s->failed_pc=0x0c03fcecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03fceeu,s,ram);
P_0c03fd02: /* original 4f22, guest PC 0x0c03fd02 */
if(!s->budget--) { s->failed_pc=0x0c03fd02u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03fd04;
P_0c03fd04: /* original d716, guest PC 0x0c03fd04 */
if(!s->budget--) { s->failed_pc=0x0c03fd04u; return 0; }
r[7]=read(ram,0x0c03fd60u,4);
goto P_0c03fd06;
P_0c03fd06: /* original d815, guest PC 0x0c03fd06 */
if(!s->budget--) { s->failed_pc=0x0c03fd06u; return 0; }
r[8]=read(ram,0x0c03fd5cu,4);
goto P_0c03fd08;
P_0c03fd08: /* original a033, guest PC 0x0c03fd08 */
if(!s->budget--) { s->failed_pc=0x0c03fd08u; return 0; }
r[5]=r[11];
goto P_0c03fd72;
P_0c03fd0a: /* original 65b3, guest PC 0x0c03fd0a */
if(!s->budget--) { s->failed_pc=0x0c03fd0au; return 0; }
r[5]=r[11];
return vf3_matrix_family(0x0c03fd0cu,s,ram);
P_0c03fd10: /* original 6072, guest PC 0x0c03fd10 */
if(!s->budget--) { s->failed_pc=0x0c03fd10u; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c03fd12;
P_0c03fd12: /* original 6e53, guest PC 0x0c03fd12 */
if(!s->budget--) { s->failed_pc=0x0c03fd12u; return 0; }
r[14]=r[5];
goto P_0c03fd14;
P_0c03fd14: /* original 4e08, guest PC 0x0c03fd14 */
if(!s->budget--) { s->failed_pc=0x0c03fd14u; return 0; }
r[14]<<=2;
goto P_0c03fd16;
P_0c03fd16: /* original 00ee, guest PC 0x0c03fd16 */
if(!s->budget--) { s->failed_pc=0x0c03fd16u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c03fd18;
P_0c03fd18: /* original 88ff, guest PC 0x0c03fd18 */
if(!s->budget--) { s->failed_pc=0x0c03fd18u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c03fd1a;
P_0c03fd1a: /* original 8d29, guest PC 0x0c03fd1a */
if(!s->budget--) { s->failed_pc=0x0c03fd1au; return 0; }
cond=r[17]&1u;
r[13]=r[0];
if(cond) { goto P_0c03fd70; }
goto P_0c03fd1e;
P_0c03fd1c: /* original 6d03, guest PC 0x0c03fd1c */
if(!s->budget--) { s->failed_pc=0x0c03fd1cu; return 0; }
r[13]=r[0];
goto P_0c03fd1e;
P_0c03fd1e: /* original 6153, guest PC 0x0c03fd1e */
if(!s->budget--) { s->failed_pc=0x0c03fd1eu; return 0; }
r[1]=r[5];
goto P_0c03fd20;
P_0c03fd20: /* original 4108, guest PC 0x0c03fd20 */
if(!s->budget--) { s->failed_pc=0x0c03fd20u; return 0; }
r[1]<<=2;
goto P_0c03fd22;
P_0c03fd22: /* original 4108, guest PC 0x0c03fd22 */
if(!s->budget--) { s->failed_pc=0x0c03fd22u; return 0; }
r[1]<<=2;
goto P_0c03fd24;
P_0c03fd24: /* original 66b3, guest PC 0x0c03fd24 */
if(!s->budget--) { s->failed_pc=0x0c03fd24u; return 0; }
r[6]=r[11];
goto P_0c03fd26;
P_0c03fd26: /* original 4100, guest PC 0x0c03fd26 */
if(!s->budget--) { s->failed_pc=0x0c03fd26u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c03fd28;
P_0c03fd28: /* original 64a3, guest PC 0x0c03fd28 */
if(!s->budget--) { s->failed_pc=0x0c03fd28u; return 0; }
r[4]=r[10];
goto P_0c03fd2a;
P_0c03fd2a: /* original 62d3, guest PC 0x0c03fd2a */
if(!s->budget--) { s->failed_pc=0x0c03fd2au; return 0; }
r[2]=r[13];
goto P_0c03fd2c;
P_0c03fd2c: /* original 2248, guest PC 0x0c03fd2c */
if(!s->budget--) { s->failed_pc=0x0c03fd2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c03fd2e;
P_0c03fd2e: /* original 8b07, guest PC 0x0c03fd2e */
if(!s->budget--) { s->failed_pc=0x0c03fd2eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fd40; }
goto P_0c03fd30;
P_0c03fd30: /* original 6072, guest PC 0x0c03fd30 */
if(!s->budget--) { s->failed_pc=0x0c03fd30u; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c03fd32;
P_0c03fd32: /* original 02ee, guest PC 0x0c03fd32 */
if(!s->budget--) { s->failed_pc=0x0c03fd32u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c03fd34;
P_0c03fd34: /* original 224b, guest PC 0x0c03fd34 */
if(!s->budget--) { s->failed_pc=0x0c03fd34u; return 0; }
r[2]|=r[4];
goto P_0c03fd36;
P_0c03fd36: /* original 0e26, guest PC 0x0c03fd36 */
if(!s->budget--) { s->failed_pc=0x0c03fd36u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c03fd38;
P_0c03fd38: /* original 6013, guest PC 0x0c03fd38 */
if(!s->budget--) { s->failed_pc=0x0c03fd38u; return 0; }
r[0]=r[1];
goto P_0c03fd3a;
P_0c03fd3a: /* original 0009, guest PC 0x0c03fd3a */
if(!s->budget--) { s->failed_pc=0x0c03fd3au; return 0; }
goto P_0c03fd3c;
P_0c03fd3c: /* original a023, guest PC 0x0c03fd3c */
if(!s->budget--) { s->failed_pc=0x0c03fd3cu; return 0; }
r[0]+=r[6];
goto P_0c03fd86;
P_0c03fd3e: /* original 306c, guest PC 0x0c03fd3e */
if(!s->budget--) { s->failed_pc=0x0c03fd3eu; return 0; }
r[0]+=r[6];
goto P_0c03fd40;
P_0c03fd40: /* original 4400, guest PC 0x0c03fd40 */
if(!s->budget--) { s->failed_pc=0x0c03fd40u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c03fd42;
P_0c03fd42: /* original aff2, guest PC 0x0c03fd42 */
if(!s->budget--) { s->failed_pc=0x0c03fd42u; return 0; }
r[6]+=0x00000001u;
goto P_0c03fd2a;
P_0c03fd44: /* original 7601, guest PC 0x0c03fd44 */
if(!s->budget--) { s->failed_pc=0x0c03fd44u; return 0; }
r[6]+=0x00000001u;
return vf3_matrix_family(0x0c03fd46u,s,ram);
P_0c03fd70: /* original 7501, guest PC 0x0c03fd70 */
if(!s->budget--) { s->failed_pc=0x0c03fd70u; return 0; }
r[5]+=0x00000001u;
goto P_0c03fd72;
P_0c03fd72: /* original 6182, guest PC 0x0c03fd72 */
if(!s->budget--) { s->failed_pc=0x0c03fd72u; return 0; }
tmp=read(ram,r[8],4);
r[1]=tmp;
goto P_0c03fd74;
P_0c03fd74: /* original 711f, guest PC 0x0c03fd74 */
if(!s->budget--) { s->failed_pc=0x0c03fd74u; return 0; }
r[1]+=0x0000001fu;
goto P_0c03fd76;
P_0c03fd76: /* original 6093, guest PC 0x0c03fd76 */
if(!s->budget--) { s->failed_pc=0x0c03fd76u; return 0; }
r[0]=r[9];
goto P_0c03fd78;
P_0c03fd78: /* original 0009, guest PC 0x0c03fd78 */
if(!s->budget--) { s->failed_pc=0x0c03fd78u; return 0; }
goto P_0c03fd7a;
P_0c03fd7a: /* original d311, guest PC 0x0c03fd7a */
if(!s->budget--) { s->failed_pc=0x0c03fd7au; return 0; }
r[3]=read(ram,0x0c03fdc0u,4);
goto P_0c03fd7c;
P_0c03fd7c: /* original 430b, guest PC 0x0c03fd7c */
if(!s->budget--) { s->failed_pc=0x0c03fd7cu; return 0; }
target=r[3];
r[16]=0x0c03fd80u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c03fd80u) { target=s->pc; goto dispatch; }
goto P_0c03fd80;
P_0c03fd7e: /* original 0009, guest PC 0x0c03fd7e */
if(!s->budget--) { s->failed_pc=0x0c03fd7eu; return 0; }
goto P_0c03fd80;
P_0c03fd80: /* original 3503, guest PC 0x0c03fd80 */
if(!s->budget--) { s->failed_pc=0x0c03fd80u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[0])!=0);
goto P_0c03fd82;
P_0c03fd82: /* original 8bc5, guest PC 0x0c03fd82 */
if(!s->budget--) { s->failed_pc=0x0c03fd82u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03fd10; }
goto P_0c03fd84;
P_0c03fd84: /* original e0ff, guest PC 0x0c03fd84 */
if(!s->budget--) { s->failed_pc=0x0c03fd84u; return 0; }
r[0]=0xffffffffu;
goto P_0c03fd86;
P_0c03fd86: /* original 4f26, guest PC 0x0c03fd86 */
if(!s->budget--) { s->failed_pc=0x0c03fd86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03fd88;
P_0c03fd88: /* original 68f6, guest PC 0x0c03fd88 */
if(!s->budget--) { s->failed_pc=0x0c03fd88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03fd8a;
P_0c03fd8a: /* original 69f6, guest PC 0x0c03fd8a */
if(!s->budget--) { s->failed_pc=0x0c03fd8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03fd8c;
P_0c03fd8c: /* original 6af6, guest PC 0x0c03fd8c */
if(!s->budget--) { s->failed_pc=0x0c03fd8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03fd8e;
P_0c03fd8e: /* original 6bf6, guest PC 0x0c03fd8e */
if(!s->budget--) { s->failed_pc=0x0c03fd8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03fd90;
P_0c03fd90: /* original 6df6, guest PC 0x0c03fd90 */
if(!s->budget--) { s->failed_pc=0x0c03fd90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03fd92;
P_0c03fd92: /* original 000b, guest PC 0x0c03fd92 */
if(!s->budget--) { s->failed_pc=0x0c03fd92u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03fd94: /* original 6ef6, guest PC 0x0c03fd94 */
if(!s->budget--) { s->failed_pc=0x0c03fd94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c03fd96u,s,ram);
P_0c042c20: /* original 2008, guest PC 0x0c042c20 */
if(!s->budget--) { s->failed_pc=0x0c042c20u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042c22;
P_0c042c22: /* original 2f26, guest PC 0x0c042c22 */
if(!s->budget--) { s->failed_pc=0x0c042c22u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c042c24;
P_0c042c24: /* original 8d4c, guest PC 0x0c042c24 */
if(!s->budget--) { s->failed_pc=0x0c042c24u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042cc0; }
goto P_0c042c28;
P_0c042c26: /* original 0009, guest PC 0x0c042c26 */
if(!s->budget--) { s->failed_pc=0x0c042c26u; return 0; }
goto P_0c042c28;
P_0c042c28: /* original 2f36, guest PC 0x0c042c28 */
if(!s->budget--) { s->failed_pc=0x0c042c28u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c042c2a;
P_0c042c2a: /* original e200, guest PC 0x0c042c2a */
if(!s->budget--) { s->failed_pc=0x0c042c2au; return 0; }
r[2]=0x00000000u;
goto P_0c042c2c;
P_0c042c2c: /* original 2127, guest PC 0x0c042c2c */
if(!s->budget--) { s->failed_pc=0x0c042c2cu; return 0; }
r[17]=(r[17]&~0x301u)|((r[1]>>31)<<8)|((r[2]>>31)<<9)|(((r[1]^r[2])>>31)&1u);
goto P_0c042c2e;
P_0c042c2e: /* original 333a, guest PC 0x0c042c2e */
if(!s->budget--) { s->failed_pc=0x0c042c2eu; return 0; }
wide=(uint64_t)r[3]-r[3]-(r[17]&1u); r[3]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c30;
P_0c042c30: /* original 312a, guest PC 0x0c042c30 */
if(!s->budget--) { s->failed_pc=0x0c042c30u; return 0; }
wide=(uint64_t)r[1]-r[2]-(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c32;
P_0c042c32: /* original 2307, guest PC 0x0c042c32 */
if(!s->budget--) { s->failed_pc=0x0c042c32u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042c34;
P_0c042c34: /* original 4124, guest PC 0x0c042c34 */
if(!s->budget--) { s->failed_pc=0x0c042c34u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c36;
P_0c042c36: /* original 3304, guest PC 0x0c042c36 */
if(!s->budget--) { s->failed_pc=0x0c042c36u; return 0; }
divide_step(s,3,0);
goto P_0c042c38;
P_0c042c38: /* original 4124, guest PC 0x0c042c38 */
if(!s->budget--) { s->failed_pc=0x0c042c38u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3a;
P_0c042c3a: /* original 3304, guest PC 0x0c042c3a */
if(!s->budget--) { s->failed_pc=0x0c042c3au; return 0; }
divide_step(s,3,0);
goto P_0c042c3c;
P_0c042c3c: /* original 4124, guest PC 0x0c042c3c */
if(!s->budget--) { s->failed_pc=0x0c042c3cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3e;
P_0c042c3e: /* original 3304, guest PC 0x0c042c3e */
if(!s->budget--) { s->failed_pc=0x0c042c3eu; return 0; }
divide_step(s,3,0);
goto P_0c042c40;
P_0c042c40: /* original 4124, guest PC 0x0c042c40 */
if(!s->budget--) { s->failed_pc=0x0c042c40u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c42;
P_0c042c42: /* original 3304, guest PC 0x0c042c42 */
if(!s->budget--) { s->failed_pc=0x0c042c42u; return 0; }
divide_step(s,3,0);
goto P_0c042c44;
P_0c042c44: /* original 4124, guest PC 0x0c042c44 */
if(!s->budget--) { s->failed_pc=0x0c042c44u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c46;
P_0c042c46: /* original 3304, guest PC 0x0c042c46 */
if(!s->budget--) { s->failed_pc=0x0c042c46u; return 0; }
divide_step(s,3,0);
goto P_0c042c48;
P_0c042c48: /* original 4124, guest PC 0x0c042c48 */
if(!s->budget--) { s->failed_pc=0x0c042c48u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4a;
P_0c042c4a: /* original 3304, guest PC 0x0c042c4a */
if(!s->budget--) { s->failed_pc=0x0c042c4au; return 0; }
divide_step(s,3,0);
goto P_0c042c4c;
P_0c042c4c: /* original 4124, guest PC 0x0c042c4c */
if(!s->budget--) { s->failed_pc=0x0c042c4cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4e;
P_0c042c4e: /* original 3304, guest PC 0x0c042c4e */
if(!s->budget--) { s->failed_pc=0x0c042c4eu; return 0; }
divide_step(s,3,0);
goto P_0c042c50;
P_0c042c50: /* original 4124, guest PC 0x0c042c50 */
if(!s->budget--) { s->failed_pc=0x0c042c50u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c52;
P_0c042c52: /* original 3304, guest PC 0x0c042c52 */
if(!s->budget--) { s->failed_pc=0x0c042c52u; return 0; }
divide_step(s,3,0);
goto P_0c042c54;
P_0c042c54: /* original 4124, guest PC 0x0c042c54 */
if(!s->budget--) { s->failed_pc=0x0c042c54u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c56;
P_0c042c56: /* original 3304, guest PC 0x0c042c56 */
if(!s->budget--) { s->failed_pc=0x0c042c56u; return 0; }
divide_step(s,3,0);
goto P_0c042c58;
P_0c042c58: /* original 4124, guest PC 0x0c042c58 */
if(!s->budget--) { s->failed_pc=0x0c042c58u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5a;
P_0c042c5a: /* original 3304, guest PC 0x0c042c5a */
if(!s->budget--) { s->failed_pc=0x0c042c5au; return 0; }
divide_step(s,3,0);
goto P_0c042c5c;
P_0c042c5c: /* original 4124, guest PC 0x0c042c5c */
if(!s->budget--) { s->failed_pc=0x0c042c5cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5e;
P_0c042c5e: /* original 3304, guest PC 0x0c042c5e */
if(!s->budget--) { s->failed_pc=0x0c042c5eu; return 0; }
divide_step(s,3,0);
goto P_0c042c60;
P_0c042c60: /* original 4124, guest PC 0x0c042c60 */
if(!s->budget--) { s->failed_pc=0x0c042c60u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c62;
P_0c042c62: /* original 3304, guest PC 0x0c042c62 */
if(!s->budget--) { s->failed_pc=0x0c042c62u; return 0; }
divide_step(s,3,0);
goto P_0c042c64;
P_0c042c64: /* original 4124, guest PC 0x0c042c64 */
if(!s->budget--) { s->failed_pc=0x0c042c64u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c66;
P_0c042c66: /* original 3304, guest PC 0x0c042c66 */
if(!s->budget--) { s->failed_pc=0x0c042c66u; return 0; }
divide_step(s,3,0);
goto P_0c042c68;
P_0c042c68: /* original 4124, guest PC 0x0c042c68 */
if(!s->budget--) { s->failed_pc=0x0c042c68u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6a;
P_0c042c6a: /* original 3304, guest PC 0x0c042c6a */
if(!s->budget--) { s->failed_pc=0x0c042c6au; return 0; }
divide_step(s,3,0);
goto P_0c042c6c;
P_0c042c6c: /* original 4124, guest PC 0x0c042c6c */
if(!s->budget--) { s->failed_pc=0x0c042c6cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6e;
P_0c042c6e: /* original 3304, guest PC 0x0c042c6e */
if(!s->budget--) { s->failed_pc=0x0c042c6eu; return 0; }
divide_step(s,3,0);
goto P_0c042c70;
P_0c042c70: /* original 4124, guest PC 0x0c042c70 */
if(!s->budget--) { s->failed_pc=0x0c042c70u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c72;
P_0c042c72: /* original 3304, guest PC 0x0c042c72 */
if(!s->budget--) { s->failed_pc=0x0c042c72u; return 0; }
divide_step(s,3,0);
goto P_0c042c74;
P_0c042c74: /* original 4124, guest PC 0x0c042c74 */
if(!s->budget--) { s->failed_pc=0x0c042c74u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c76;
P_0c042c76: /* original 3304, guest PC 0x0c042c76 */
if(!s->budget--) { s->failed_pc=0x0c042c76u; return 0; }
divide_step(s,3,0);
goto P_0c042c78;
P_0c042c78: /* original 4124, guest PC 0x0c042c78 */
if(!s->budget--) { s->failed_pc=0x0c042c78u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7a;
P_0c042c7a: /* original 3304, guest PC 0x0c042c7a */
if(!s->budget--) { s->failed_pc=0x0c042c7au; return 0; }
divide_step(s,3,0);
goto P_0c042c7c;
P_0c042c7c: /* original 4124, guest PC 0x0c042c7c */
if(!s->budget--) { s->failed_pc=0x0c042c7cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7e;
P_0c042c7e: /* original 3304, guest PC 0x0c042c7e */
if(!s->budget--) { s->failed_pc=0x0c042c7eu; return 0; }
divide_step(s,3,0);
goto P_0c042c80;
P_0c042c80: /* original 4124, guest PC 0x0c042c80 */
if(!s->budget--) { s->failed_pc=0x0c042c80u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c82;
P_0c042c82: /* original 3304, guest PC 0x0c042c82 */
if(!s->budget--) { s->failed_pc=0x0c042c82u; return 0; }
divide_step(s,3,0);
goto P_0c042c84;
P_0c042c84: /* original 4124, guest PC 0x0c042c84 */
if(!s->budget--) { s->failed_pc=0x0c042c84u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c86;
P_0c042c86: /* original 3304, guest PC 0x0c042c86 */
if(!s->budget--) { s->failed_pc=0x0c042c86u; return 0; }
divide_step(s,3,0);
goto P_0c042c88;
P_0c042c88: /* original 4124, guest PC 0x0c042c88 */
if(!s->budget--) { s->failed_pc=0x0c042c88u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8a;
P_0c042c8a: /* original 3304, guest PC 0x0c042c8a */
if(!s->budget--) { s->failed_pc=0x0c042c8au; return 0; }
divide_step(s,3,0);
goto P_0c042c8c;
P_0c042c8c: /* original 4124, guest PC 0x0c042c8c */
if(!s->budget--) { s->failed_pc=0x0c042c8cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8e;
P_0c042c8e: /* original 3304, guest PC 0x0c042c8e */
if(!s->budget--) { s->failed_pc=0x0c042c8eu; return 0; }
divide_step(s,3,0);
goto P_0c042c90;
P_0c042c90: /* original 4124, guest PC 0x0c042c90 */
if(!s->budget--) { s->failed_pc=0x0c042c90u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c92;
P_0c042c92: /* original 3304, guest PC 0x0c042c92 */
if(!s->budget--) { s->failed_pc=0x0c042c92u; return 0; }
divide_step(s,3,0);
goto P_0c042c94;
P_0c042c94: /* original 4124, guest PC 0x0c042c94 */
if(!s->budget--) { s->failed_pc=0x0c042c94u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c96;
P_0c042c96: /* original 3304, guest PC 0x0c042c96 */
if(!s->budget--) { s->failed_pc=0x0c042c96u; return 0; }
divide_step(s,3,0);
goto P_0c042c98;
P_0c042c98: /* original 4124, guest PC 0x0c042c98 */
if(!s->budget--) { s->failed_pc=0x0c042c98u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9a;
P_0c042c9a: /* original 3304, guest PC 0x0c042c9a */
if(!s->budget--) { s->failed_pc=0x0c042c9au; return 0; }
divide_step(s,3,0);
goto P_0c042c9c;
P_0c042c9c: /* original 4124, guest PC 0x0c042c9c */
if(!s->budget--) { s->failed_pc=0x0c042c9cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9e;
P_0c042c9e: /* original 3304, guest PC 0x0c042c9e */
if(!s->budget--) { s->failed_pc=0x0c042c9eu; return 0; }
divide_step(s,3,0);
goto P_0c042ca0;
P_0c042ca0: /* original 4124, guest PC 0x0c042ca0 */
if(!s->budget--) { s->failed_pc=0x0c042ca0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca2;
P_0c042ca2: /* original 3304, guest PC 0x0c042ca2 */
if(!s->budget--) { s->failed_pc=0x0c042ca2u; return 0; }
divide_step(s,3,0);
goto P_0c042ca4;
P_0c042ca4: /* original 4124, guest PC 0x0c042ca4 */
if(!s->budget--) { s->failed_pc=0x0c042ca4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca6;
P_0c042ca6: /* original 3304, guest PC 0x0c042ca6 */
if(!s->budget--) { s->failed_pc=0x0c042ca6u; return 0; }
divide_step(s,3,0);
goto P_0c042ca8;
P_0c042ca8: /* original 4124, guest PC 0x0c042ca8 */
if(!s->budget--) { s->failed_pc=0x0c042ca8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042caa;
P_0c042caa: /* original 3304, guest PC 0x0c042caa */
if(!s->budget--) { s->failed_pc=0x0c042caau; return 0; }
divide_step(s,3,0);
goto P_0c042cac;
P_0c042cac: /* original 4124, guest PC 0x0c042cac */
if(!s->budget--) { s->failed_pc=0x0c042cacu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cae;
P_0c042cae: /* original 3304, guest PC 0x0c042cae */
if(!s->budget--) { s->failed_pc=0x0c042caeu; return 0; }
divide_step(s,3,0);
goto P_0c042cb0;
P_0c042cb0: /* original 4124, guest PC 0x0c042cb0 */
if(!s->budget--) { s->failed_pc=0x0c042cb0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb2;
P_0c042cb2: /* original 3304, guest PC 0x0c042cb2 */
if(!s->budget--) { s->failed_pc=0x0c042cb2u; return 0; }
divide_step(s,3,0);
goto P_0c042cb4;
P_0c042cb4: /* original 4124, guest PC 0x0c042cb4 */
if(!s->budget--) { s->failed_pc=0x0c042cb4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb6;
P_0c042cb6: /* original 312e, guest PC 0x0c042cb6 */
if(!s->budget--) { s->failed_pc=0x0c042cb6u; return 0; }
wide=(uint64_t)r[1]+r[2]+(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042cb8;
P_0c042cb8: /* original 6013, guest PC 0x0c042cb8 */
if(!s->budget--) { s->failed_pc=0x0c042cb8u; return 0; }
r[0]=r[1];
goto P_0c042cba;
P_0c042cba: /* original 63f6, guest PC 0x0c042cba */
if(!s->budget--) { s->failed_pc=0x0c042cbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042cbc;
P_0c042cbc: /* original 000b, guest PC 0x0c042cbc */
if(!s->budget--) { s->failed_pc=0x0c042cbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042cbe: /* original 62f6, guest PC 0x0c042cbe */
if(!s->budget--) { s->failed_pc=0x0c042cbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c042cc0;
P_0c042cc0: /* original d102, guest PC 0x0c042cc0 */
if(!s->budget--) { s->failed_pc=0x0c042cc0u; return 0; }
r[1]=read(ram,0x0c042cccu,4);
goto P_0c042cc2;
P_0c042cc2: /* original d203, guest PC 0x0c042cc2 */
if(!s->budget--) { s->failed_pc=0x0c042cc2u; return 0; }
r[2]=read(ram,0x0c042cd0u,4);
goto P_0c042cc4;
P_0c042cc4: /* original e000, guest PC 0x0c042cc4 */
if(!s->budget--) { s->failed_pc=0x0c042cc4u; return 0; }
r[0]=0x00000000u;
goto P_0c042cc6;
P_0c042cc6: /* original 2122, guest PC 0x0c042cc6 */
if(!s->budget--) { s->failed_pc=0x0c042cc6u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042cc8;
P_0c042cc8: /* original 000b, guest PC 0x0c042cc8 */
if(!s->budget--) { s->failed_pc=0x0c042cc8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042cca: /* original 62f6, guest PC 0x0c042cca */
if(!s->budget--) { s->failed_pc=0x0c042ccau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
return vf3_matrix_family(0x0c042cccu,s,ram);
P_0c0441b6: /* original 6743, guest PC 0x0c0441b6 */
if(!s->budget--) { s->failed_pc=0x0c0441b6u; return 0; }
r[7]=r[4];
goto P_0c0441b8;
P_0c0441b8: /* original 2fc6, guest PC 0x0c0441b8 */
if(!s->budget--) { s->failed_pc=0x0c0441b8u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0441ba;
P_0c0441ba: /* original d63d, guest PC 0x0c0441ba */
if(!s->budget--) { s->failed_pc=0x0c0441bau; return 0; }
r[6]=read(ram,0x0c0442b0u,4);
goto P_0c0441bc;
P_0c0441bc: /* original e020, guest PC 0x0c0441bc */
if(!s->budget--) { s->failed_pc=0x0c0441bcu; return 0; }
r[0]=0x00000020u;
goto P_0c0441be;
P_0c0441be: /* original 6c46, guest PC 0x0c0441be */
if(!s->budget--) { s->failed_pc=0x0c0441beu; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[12]=tmp;
goto P_0c0441c0;
P_0c0441c0: /* original 7704, guest PC 0x0c0441c0 */
if(!s->budget--) { s->failed_pc=0x0c0441c0u; return 0; }
r[7]+=0x00000004u;
goto P_0c0441c2;
P_0c0441c2: /* original e100, guest PC 0x0c0441c2 */
if(!s->budget--) { s->failed_pc=0x0c0441c2u; return 0; }
r[1]=0x00000000u;
goto P_0c0441c4;
P_0c0441c4: /* original 6363, guest PC 0x0c0441c4 */
if(!s->budget--) { s->failed_pc=0x0c0441c4u; return 0; }
r[3]=r[6];
goto P_0c0441c6;
P_0c0441c6: /* original 23c8, guest PC 0x0c0441c6 */
if(!s->budget--) { s->failed_pc=0x0c0441c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0441c8;
P_0c0441c8: /* original 8906, guest PC 0x0c0441c8 */
if(!s->budget--) { s->failed_pc=0x0c0441c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0441d8; }
goto P_0c0441ca;
P_0c0441ca: /* original 3560, guest PC 0x0c0441ca */
if(!s->budget--) { s->failed_pc=0x0c0441cau; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c0441cc;
P_0c0441cc: /* original 8b02, guest PC 0x0c0441cc */
if(!s->budget--) { s->failed_pc=0x0c0441ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0441d4; }
goto P_0c0441ce;
P_0c0441ce: /* original 6073, guest PC 0x0c0441ce */
if(!s->budget--) { s->failed_pc=0x0c0441ceu; return 0; }
r[0]=r[7];
goto P_0c0441d0;
P_0c0441d0: /* original 000b, guest PC 0x0c0441d0 */
if(!s->budget--) { s->failed_pc=0x0c0441d0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
s->pc=target; return ram->oob==0;
P_0c0441d2: /* original 6cf6, guest PC 0x0c0441d2 */
if(!s->budget--) { s->failed_pc=0x0c0441d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0441d4;
P_0c0441d4: /* original 7404, guest PC 0x0c0441d4 */
if(!s->budget--) { s->failed_pc=0x0c0441d4u; return 0; }
r[4]+=0x00000004u;
goto P_0c0441d6;
P_0c0441d6: /* original 6743, guest PC 0x0c0441d6 */
if(!s->budget--) { s->failed_pc=0x0c0441d6u; return 0; }
r[7]=r[4];
goto P_0c0441d8;
P_0c0441d8: /* original 7101, guest PC 0x0c0441d8 */
if(!s->budget--) { s->failed_pc=0x0c0441d8u; return 0; }
r[1]+=0x00000001u;
goto P_0c0441da;
P_0c0441da: /* original 4601, guest PC 0x0c0441da */
if(!s->budget--) { s->failed_pc=0x0c0441dau; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c0441dc;
P_0c0441dc: /* original 3102, guest PC 0x0c0441dc */
if(!s->budget--) { s->failed_pc=0x0c0441dcu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[0])!=0);
goto P_0c0441de;
P_0c0441de: /* original 8bf1, guest PC 0x0c0441de */
if(!s->budget--) { s->failed_pc=0x0c0441deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0441c4; }
goto P_0c0441e0;
P_0c0441e0: /* original e000, guest PC 0x0c0441e0 */
if(!s->budget--) { s->failed_pc=0x0c0441e0u; return 0; }
r[0]=0x00000000u;
goto P_0c0441e2;
P_0c0441e2: /* original 000b, guest PC 0x0c0441e2 */
if(!s->budget--) { s->failed_pc=0x0c0441e2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
s->pc=target; return ram->oob==0;
P_0c0441e4: /* original 6cf6, guest PC 0x0c0441e4 */
if(!s->budget--) { s->failed_pc=0x0c0441e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
return vf3_matrix_family(0x0c0441e6u,s,ram);
P_0c044234: /* original 4f22, guest PC 0x0c044234 */
if(!s->budget--) { s->failed_pc=0x0c044234u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c044236;
P_0c044236: /* original 7ffc, guest PC 0x0c044236 */
if(!s->budget--) { s->failed_pc=0x0c044236u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c044238;
P_0c044238: /* original 2f52, guest PC 0x0c044238 */
if(!s->budget--) { s->failed_pc=0x0c044238u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c04423a;
P_0c04423a: /* original e502, guest PC 0x0c04423a */
if(!s->budget--) { s->failed_pc=0x0c04423au; return 0; }
r[5]=0x00000002u;
goto P_0c04423c;
P_0c04423c: /* original bfbb, guest PC 0x0c04423c */
if(!s->budget--) { s->failed_pc=0x0c04423cu; return 0; }
target=0x0c0441b6u; r[16]=0x0c044240u;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c044240u) { target=s->pc; goto dispatch; }
goto P_0c044240;
P_0c04423e: /* original 64f2, guest PC 0x0c04423e */
if(!s->budget--) { s->failed_pc=0x0c04423eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c044240;
P_0c044240: /* original 6403, guest PC 0x0c044240 */
if(!s->budget--) { s->failed_pc=0x0c044240u; return 0; }
r[4]=r[0];
goto P_0c044242;
P_0c044242: /* original 2448, guest PC 0x0c044242 */
if(!s->budget--) { s->failed_pc=0x0c044242u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c044244;
P_0c044244: /* original 8b04, guest PC 0x0c044244 */
if(!s->budget--) { s->failed_pc=0x0c044244u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c044250; }
goto P_0c044246;
P_0c044246: /* original 7f04, guest PC 0x0c044246 */
if(!s->budget--) { s->failed_pc=0x0c044246u; return 0; }
r[15]+=0x00000004u;
goto P_0c044248;
P_0c044248: /* original 4f26, guest PC 0x0c044248 */
if(!s->budget--) { s->failed_pc=0x0c044248u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04424a;
P_0c04424a: /* original e0ff, guest PC 0x0c04424a */
if(!s->budget--) { s->failed_pc=0x0c04424au; return 0; }
r[0]=0xffffffffu;
goto P_0c04424c;
P_0c04424c: /* original 000b, guest PC 0x0c04424c */
if(!s->budget--) { s->failed_pc=0x0c04424cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04424e: /* original 6ef6, guest PC 0x0c04424e */
if(!s->budget--) { s->failed_pc=0x0c04424eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c044250;
P_0c044250: /* original 6543, guest PC 0x0c044250 */
if(!s->budget--) { s->failed_pc=0x0c044250u; return 0; }
r[5]=r[4];
goto P_0c044252;
P_0c044252: /* original 7502, guest PC 0x0c044252 */
if(!s->budget--) { s->failed_pc=0x0c044252u; return 0; }
r[5]+=0x00000002u;
goto P_0c044254;
P_0c044254: /* original 6340, guest PC 0x0c044254 */
if(!s->budget--) { s->failed_pc=0x0c044254u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c044256;
P_0c044256: /* original 633c, guest PC 0x0c044256 */
if(!s->budget--) { s->failed_pc=0x0c044256u; return 0; }
r[3]=r[3]&255u;
goto P_0c044258;
P_0c044258: /* original 7301, guest PC 0x0c044258 */
if(!s->budget--) { s->failed_pc=0x0c044258u; return 0; }
r[3]+=0x00000001u;
goto P_0c04425a;
P_0c04425a: /* original 2e31, guest PC 0x0c04425a */
if(!s->budget--) { s->failed_pc=0x0c04425au; return 0; }
write(ram,r[14],r[3],2);
goto P_0c04425c;
P_0c04425c: /* original e3f9, guest PC 0x0c04425c */
if(!s->budget--) { s->failed_pc=0x0c04425cu; return 0; }
r[3]=0xfffffff9u;
goto P_0c04425e;
P_0c04425e: /* original 8441, guest PC 0x0c04425e */
if(!s->budget--) { s->failed_pc=0x0c04425eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c044260;
P_0c044260: /* original 600c, guest PC 0x0c044260 */
if(!s->budget--) { s->failed_pc=0x0c044260u; return 0; }
r[0]=r[0]&255u;
goto P_0c044262;
P_0c044262: /* original 7001, guest PC 0x0c044262 */
if(!s->budget--) { s->failed_pc=0x0c044262u; return 0; }
r[0]+=0x00000001u;
goto P_0c044264;
P_0c044264: /* original 4008, guest PC 0x0c044264 */
if(!s->budget--) { s->failed_pc=0x0c044264u; return 0; }
r[0]<<=2;
goto P_0c044266;
P_0c044266: /* original 4008, guest PC 0x0c044266 */
if(!s->budget--) { s->failed_pc=0x0c044266u; return 0; }
r[0]<<=2;
goto P_0c044268;
P_0c044268: /* original 4000, guest PC 0x0c044268 */
if(!s->budget--) { s->failed_pc=0x0c044268u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c04426a;
P_0c04426a: /* original 81e1, guest PC 0x0c04426a */
if(!s->budget--) { s->failed_pc=0x0c04426au; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c04426c;
P_0c04426c: /* original 6050, guest PC 0x0c04426c */
if(!s->budget--) { s->failed_pc=0x0c04426cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[0]=tmp;
goto P_0c04426e;
P_0c04426e: /* original 600c, guest PC 0x0c04426e */
if(!s->budget--) { s->failed_pc=0x0c04426eu; return 0; }
r[0]=r[0]&255u;
goto P_0c044270;
P_0c044270: /* original 4009, guest PC 0x0c044270 */
if(!s->budget--) { s->failed_pc=0x0c044270u; return 0; }
r[0]>>=2;
goto P_0c044272;
P_0c044272: /* original 4009, guest PC 0x0c044272 */
if(!s->budget--) { s->failed_pc=0x0c044272u; return 0; }
r[0]>>=2;
goto P_0c044274;
P_0c044274: /* original c90f, guest PC 0x0c044274 */
if(!s->budget--) { s->failed_pc=0x0c044274u; return 0; }
r[0]&=15u;
goto P_0c044276;
P_0c044276: /* original 81e2, guest PC 0x0c044276 */
if(!s->budget--) { s->failed_pc=0x0c044276u; return 0; }
write(ram,r[14]+4,r[0],2);
goto P_0c044278;
P_0c044278: /* original 6050, guest PC 0x0c044278 */
if(!s->budget--) { s->failed_pc=0x0c044278u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[0]=tmp;
goto P_0c04427a;
P_0c04427a: /* original 600c, guest PC 0x0c04427a */
if(!s->budget--) { s->failed_pc=0x0c04427au; return 0; }
r[0]=r[0]&255u;
goto P_0c04427c;
P_0c04427c: /* original c90f, guest PC 0x0c04427c */
if(!s->budget--) { s->failed_pc=0x0c04427cu; return 0; }
r[0]&=15u;
goto P_0c04427e;
P_0c04427e: /* original 81e3, guest PC 0x0c04427e */
if(!s->budget--) { s->failed_pc=0x0c04427eu; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c044280;
P_0c044280: /* original 8443, guest PC 0x0c044280 */
if(!s->budget--) { s->failed_pc=0x0c044280u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c044282;
P_0c044282: /* original 600c, guest PC 0x0c044282 */
if(!s->budget--) { s->failed_pc=0x0c044282u; return 0; }
r[0]=r[0]&255u;
goto P_0c044284;
P_0c044284: /* original 403d, guest PC 0x0c044284 */
if(!s->budget--) { s->failed_pc=0x0c044284u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?r[0]>>((-r[3])&31u):0):r[0]<<(r[3]&31u);
goto P_0c044286;
P_0c044286: /* original c901, guest PC 0x0c044286 */
if(!s->budget--) { s->failed_pc=0x0c044286u; return 0; }
r[0]&=1u;
goto P_0c044288;
P_0c044288: /* original 81e4, guest PC 0x0c044288 */
if(!s->budget--) { s->failed_pc=0x0c044288u; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c04428a;
P_0c04428a: /* original e000, guest PC 0x0c04428a */
if(!s->budget--) { s->failed_pc=0x0c04428au; return 0; }
r[0]=0x00000000u;
goto P_0c04428c;
P_0c04428c: /* original 7f04, guest PC 0x0c04428c */
if(!s->budget--) { s->failed_pc=0x0c04428cu; return 0; }
r[15]+=0x00000004u;
goto P_0c04428e;
P_0c04428e: /* original 4f26, guest PC 0x0c04428e */
if(!s->budget--) { s->failed_pc=0x0c04428eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c044290;
P_0c044290: /* original 000b, guest PC 0x0c044290 */
if(!s->budget--) { s->failed_pc=0x0c044290u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c044292: /* original 6ef6, guest PC 0x0c044292 */
if(!s->budget--) { s->failed_pc=0x0c044292u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c044294u,s,ram);
P_0c044302: /* original 4f22, guest PC 0x0c044302 */
if(!s->budget--) { s->failed_pc=0x0c044302u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c044304;
P_0c044304: /* original 7ffc, guest PC 0x0c044304 */
if(!s->budget--) { s->failed_pc=0x0c044304u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c044306;
P_0c044306: /* original 2f52, guest PC 0x0c044306 */
if(!s->budget--) { s->failed_pc=0x0c044306u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c044308;
P_0c044308: /* original e504, guest PC 0x0c044308 */
if(!s->budget--) { s->failed_pc=0x0c044308u; return 0; }
r[5]=0x00000004u;
goto P_0c04430a;
P_0c04430a: /* original bf54, guest PC 0x0c04430a */
if(!s->budget--) { s->failed_pc=0x0c04430au; return 0; }
target=0x0c0441b6u; r[16]=0x0c04430eu;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c04430eu) { target=s->pc; goto dispatch; }
goto P_0c04430e;
P_0c04430c: /* original 64f2, guest PC 0x0c04430c */
if(!s->budget--) { s->failed_pc=0x0c04430cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c04430e;
P_0c04430e: /* original 6403, guest PC 0x0c04430e */
if(!s->budget--) { s->failed_pc=0x0c04430eu; return 0; }
r[4]=r[0];
goto P_0c044310;
P_0c044310: /* original 2448, guest PC 0x0c044310 */
if(!s->budget--) { s->failed_pc=0x0c044310u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c044312;
P_0c044312: /* original 8b04, guest PC 0x0c044312 */
if(!s->budget--) { s->failed_pc=0x0c044312u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04431e; }
goto P_0c044314;
P_0c044314: /* original 7f04, guest PC 0x0c044314 */
if(!s->budget--) { s->failed_pc=0x0c044314u; return 0; }
r[15]+=0x00000004u;
goto P_0c044316;
P_0c044316: /* original 4f26, guest PC 0x0c044316 */
if(!s->budget--) { s->failed_pc=0x0c044316u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c044318;
P_0c044318: /* original e0ff, guest PC 0x0c044318 */
if(!s->budget--) { s->failed_pc=0x0c044318u; return 0; }
r[0]=0xffffffffu;
goto P_0c04431a;
P_0c04431a: /* original 000b, guest PC 0x0c04431a */
if(!s->budget--) { s->failed_pc=0x0c04431au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04431c: /* original 6ef6, guest PC 0x0c04431c */
if(!s->budget--) { s->failed_pc=0x0c04431cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04431e;
P_0c04431e: /* original 6543, guest PC 0x0c04431e */
if(!s->budget--) { s->failed_pc=0x0c04431eu; return 0; }
r[5]=r[4];
goto P_0c044320;
P_0c044320: /* original 7503, guest PC 0x0c044320 */
if(!s->budget--) { s->failed_pc=0x0c044320u; return 0; }
r[5]+=0x00000003u;
goto P_0c044322;
P_0c044322: /* original 6340, guest PC 0x0c044322 */
if(!s->budget--) { s->failed_pc=0x0c044322u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c044324;
P_0c044324: /* original 633c, guest PC 0x0c044324 */
if(!s->budget--) { s->failed_pc=0x0c044324u; return 0; }
r[3]=r[3]&255u;
goto P_0c044326;
P_0c044326: /* original 7301, guest PC 0x0c044326 */
if(!s->budget--) { s->failed_pc=0x0c044326u; return 0; }
r[3]+=0x00000001u;
goto P_0c044328;
P_0c044328: /* original 2e31, guest PC 0x0c044328 */
if(!s->budget--) { s->failed_pc=0x0c044328u; return 0; }
write(ram,r[14],r[3],2);
goto P_0c04432a;
P_0c04432a: /* original 8441, guest PC 0x0c04432a */
if(!s->budget--) { s->failed_pc=0x0c04432au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c04432c;
P_0c04432c: /* original 600c, guest PC 0x0c04432c */
if(!s->budget--) { s->failed_pc=0x0c04432cu; return 0; }
r[0]=r[0]&255u;
goto P_0c04432e;
P_0c04432e: /* original 7001, guest PC 0x0c04432e */
if(!s->budget--) { s->failed_pc=0x0c04432eu; return 0; }
r[0]+=0x00000001u;
goto P_0c044330;
P_0c044330: /* original 4008, guest PC 0x0c044330 */
if(!s->budget--) { s->failed_pc=0x0c044330u; return 0; }
r[0]<<=2;
goto P_0c044332;
P_0c044332: /* original 4008, guest PC 0x0c044332 */
if(!s->budget--) { s->failed_pc=0x0c044332u; return 0; }
r[0]<<=2;
goto P_0c044334;
P_0c044334: /* original 4000, guest PC 0x0c044334 */
if(!s->budget--) { s->failed_pc=0x0c044334u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c044336;
P_0c044336: /* original 81e1, guest PC 0x0c044336 */
if(!s->budget--) { s->failed_pc=0x0c044336u; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c044338;
P_0c044338: /* original 8442, guest PC 0x0c044338 */
if(!s->budget--) { s->failed_pc=0x0c044338u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c04433a;
P_0c04433a: /* original 600c, guest PC 0x0c04433a */
if(!s->budget--) { s->failed_pc=0x0c04433au; return 0; }
r[0]=r[0]&255u;
goto P_0c04433c;
P_0c04433c: /* original 4009, guest PC 0x0c04433c */
if(!s->budget--) { s->failed_pc=0x0c04433cu; return 0; }
r[0]>>=2;
goto P_0c04433e;
P_0c04433e: /* original 4009, guest PC 0x0c04433e */
if(!s->budget--) { s->failed_pc=0x0c04433eu; return 0; }
r[0]>>=2;
goto P_0c044340;
P_0c044340: /* original c90f, guest PC 0x0c044340 */
if(!s->budget--) { s->failed_pc=0x0c044340u; return 0; }
r[0]&=15u;
goto P_0c044342;
P_0c044342: /* original 81e2, guest PC 0x0c044342 */
if(!s->budget--) { s->failed_pc=0x0c044342u; return 0; }
write(ram,r[14]+4,r[0],2);
goto P_0c044344;
P_0c044344: /* original 6050, guest PC 0x0c044344 */
if(!s->budget--) { s->failed_pc=0x0c044344u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[0]=tmp;
goto P_0c044346;
P_0c044346: /* original 600c, guest PC 0x0c044346 */
if(!s->budget--) { s->failed_pc=0x0c044346u; return 0; }
r[0]=r[0]&255u;
goto P_0c044348;
P_0c044348: /* original 4009, guest PC 0x0c044348 */
if(!s->budget--) { s->failed_pc=0x0c044348u; return 0; }
r[0]>>=2;
goto P_0c04434a;
P_0c04434a: /* original 4009, guest PC 0x0c04434a */
if(!s->budget--) { s->failed_pc=0x0c04434au; return 0; }
r[0]>>=2;
goto P_0c04434c;
P_0c04434c: /* original 4009, guest PC 0x0c04434c */
if(!s->budget--) { s->failed_pc=0x0c04434cu; return 0; }
r[0]>>=2;
goto P_0c04434e;
P_0c04434e: /* original c903, guest PC 0x0c04434e */
if(!s->budget--) { s->failed_pc=0x0c04434eu; return 0; }
r[0]&=3u;
goto P_0c044350;
P_0c044350: /* original 80e6, guest PC 0x0c044350 */
if(!s->budget--) { s->failed_pc=0x0c044350u; return 0; }
write(ram,r[14]+6,r[0],1);
goto P_0c044352;
P_0c044352: /* original 6050, guest PC 0x0c044352 */
if(!s->budget--) { s->failed_pc=0x0c044352u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[0]=tmp;
goto P_0c044354;
P_0c044354: /* original 600c, guest PC 0x0c044354 */
if(!s->budget--) { s->failed_pc=0x0c044354u; return 0; }
r[0]=r[0]&255u;
goto P_0c044356;
P_0c044356: /* original 4009, guest PC 0x0c044356 */
if(!s->budget--) { s->failed_pc=0x0c044356u; return 0; }
r[0]>>=2;
goto P_0c044358;
P_0c044358: /* original 4009, guest PC 0x0c044358 */
if(!s->budget--) { s->failed_pc=0x0c044358u; return 0; }
r[0]>>=2;
goto P_0c04435a;
P_0c04435a: /* original 4001, guest PC 0x0c04435a */
if(!s->budget--) { s->failed_pc=0x0c04435au; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c04435c;
P_0c04435c: /* original c901, guest PC 0x0c04435c */
if(!s->budget--) { s->failed_pc=0x0c04435cu; return 0; }
r[0]&=1u;
goto P_0c04435e;
P_0c04435e: /* original 80e7, guest PC 0x0c04435e */
if(!s->budget--) { s->failed_pc=0x0c04435eu; return 0; }
write(ram,r[14]+7,r[0],1);
goto P_0c044360;
P_0c044360: /* original e000, guest PC 0x0c044360 */
if(!s->budget--) { s->failed_pc=0x0c044360u; return 0; }
r[0]=0x00000000u;
goto P_0c044362;
P_0c044362: /* original 7f04, guest PC 0x0c044362 */
if(!s->budget--) { s->failed_pc=0x0c044362u; return 0; }
r[15]+=0x00000004u;
goto P_0c044364;
P_0c044364: /* original 4f26, guest PC 0x0c044364 */
if(!s->budget--) { s->failed_pc=0x0c044364u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c044366;
P_0c044366: /* original 000b, guest PC 0x0c044366 */
if(!s->budget--) { s->failed_pc=0x0c044366u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c044368: /* original 6ef6, guest PC 0x0c044368 */
if(!s->budget--) { s->failed_pc=0x0c044368u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04436au,s,ram);
P_0c06f814: /* original f40b, guest PC 0x0c06f814 */
if(!s->budget--) { s->failed_pc=0x0c06f814u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f816;
P_0c06f816: /* original 0009, guest PC 0x0c06f816 */
if(!s->budget--) { s->failed_pc=0x0c06f816u; return 0; }
goto P_0c06f818;
P_0c06f818: /* original e038, guest PC 0x0c06f818 */
if(!s->budget--) { s->failed_pc=0x0c06f818u; return 0; }
r[0]=0x00000038u;
goto P_0c06f81a;
P_0c06f81a: /* original 65f3, guest PC 0x0c06f81a */
if(!s->budget--) { s->failed_pc=0x0c06f81au; return 0; }
r[5]=r[15];
goto P_0c06f81c;
P_0c06f81c: /* original f3f6, guest PC 0x0c06f81c */
if(!s->budget--) { s->failed_pc=0x0c06f81cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06f81e;
P_0c06f81e: /* original e02c, guest PC 0x0c06f81e */
if(!s->budget--) { s->failed_pc=0x0c06f81eu; return 0; }
r[0]=0x0000002cu;
goto P_0c06f820;
P_0c06f820: /* original 64f3, guest PC 0x0c06f820 */
if(!s->budget--) { s->failed_pc=0x0c06f820u; return 0; }
r[4]=r[15];
goto P_0c06f822;
P_0c06f822: /* original 742c, guest PC 0x0c06f822 */
if(!s->budget--) { s->failed_pc=0x0c06f822u; return 0; }
r[4]+=0x0000002cu;
goto P_0c06f824;
P_0c06f824: /* original ff37, guest PC 0x0c06f824 */
if(!s->budget--) { s->failed_pc=0x0c06f824u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06f826;
P_0c06f826: /* original e03c, guest PC 0x0c06f826 */
if(!s->budget--) { s->failed_pc=0x0c06f826u; return 0; }
r[0]=0x0000003cu;
goto P_0c06f828;
P_0c06f828: /* original f3f6, guest PC 0x0c06f828 */
if(!s->budget--) { s->failed_pc=0x0c06f828u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06f82a;
P_0c06f82a: /* original e030, guest PC 0x0c06f82a */
if(!s->budget--) { s->failed_pc=0x0c06f82au; return 0; }
r[0]=0x00000030u;
goto P_0c06f82c;
P_0c06f82c: /* original 7544, guest PC 0x0c06f82c */
if(!s->budget--) { s->failed_pc=0x0c06f82cu; return 0; }
r[5]+=0x00000044u;
goto P_0c06f82e;
P_0c06f82e: /* original ff37, guest PC 0x0c06f82e */
if(!s->budget--) { s->failed_pc=0x0c06f82eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06f830;
P_0c06f830: /* original e040, guest PC 0x0c06f830 */
if(!s->budget--) { s->failed_pc=0x0c06f830u; return 0; }
r[0]=0x00000040u;
goto P_0c06f832;
P_0c06f832: /* original f3f6, guest PC 0x0c06f832 */
if(!s->budget--) { s->failed_pc=0x0c06f832u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06f834;
P_0c06f834: /* original e034, guest PC 0x0c06f834 */
if(!s->budget--) { s->failed_pc=0x0c06f834u; return 0; }
r[0]=0x00000034u;
goto P_0c06f836;
P_0c06f836: /* original ff37, guest PC 0x0c06f836 */
if(!s->budget--) { s->failed_pc=0x0c06f836u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c06f838;
P_0c06f838: /* original f049, guest PC 0x0c06f838 */
if(!s->budget--) { s->failed_pc=0x0c06f838u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f83a;
P_0c06f83a: /* original f149, guest PC 0x0c06f83a */
if(!s->budget--) { s->failed_pc=0x0c06f83au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f83c;
P_0c06f83c: /* original f249, guest PC 0x0c06f83c */
if(!s->budget--) { s->failed_pc=0x0c06f83cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f83e;
P_0c06f83e: /* original f38d, guest PC 0x0c06f83e */
if(!s->budget--) { s->failed_pc=0x0c06f83eu; return 0; }
fr[3]=0;
goto P_0c06f840;
P_0c06f840: /* original f459, guest PC 0x0c06f840 */
if(!s->budget--) { s->failed_pc=0x0c06f840u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f842;
P_0c06f842: /* original f559, guest PC 0x0c06f842 */
if(!s->budget--) { s->failed_pc=0x0c06f842u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f844;
P_0c06f844: /* original f659, guest PC 0x0c06f844 */
if(!s->budget--) { s->failed_pc=0x0c06f844u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f846;
P_0c06f846: /* original f78d, guest PC 0x0c06f846 */
if(!s->budget--) { s->failed_pc=0x0c06f846u; return 0; }
fr[7]=0;
goto P_0c06f848;
P_0c06f848: /* original f4ed, guest PC 0x0c06f848 */
if(!s->budget--) { s->failed_pc=0x0c06f848u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c06f84a;
P_0c06f84a: /* original f07c, guest PC 0x0c06f84a */
if(!s->budget--) { s->failed_pc=0x0c06f84au; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c06f84c;
P_0c06f84c: /* original 64f3, guest PC 0x0c06f84c */
if(!s->budget--) { s->failed_pc=0x0c06f84cu; return 0; }
r[4]=r[15];
goto P_0c06f84e;
P_0c06f84e: /* original 65f3, guest PC 0x0c06f84e */
if(!s->budget--) { s->failed_pc=0x0c06f84eu; return 0; }
r[5]=r[15];
goto P_0c06f850;
P_0c06f850: /* original 7420, guest PC 0x0c06f850 */
if(!s->budget--) { s->failed_pc=0x0c06f850u; return 0; }
r[4]+=0x00000020u;
goto P_0c06f852;
P_0c06f852: /* original f40c, guest PC 0x0c06f852 */
if(!s->budget--) { s->failed_pc=0x0c06f852u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c06f854;
P_0c06f854: /* original 752c, guest PC 0x0c06f854 */
if(!s->budget--) { s->failed_pc=0x0c06f854u; return 0; }
r[5]+=0x0000002cu;
goto P_0c06f856;
P_0c06f856: /* original f059, guest PC 0x0c06f856 */
if(!s->budget--) { s->failed_pc=0x0c06f856u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f858;
P_0c06f858: /* original f159, guest PC 0x0c06f858 */
if(!s->budget--) { s->failed_pc=0x0c06f858u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f85a;
P_0c06f85a: /* original f259, guest PC 0x0c06f85a */
if(!s->budget--) { s->failed_pc=0x0c06f85au; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f85c;
P_0c06f85c: /* original f38d, guest PC 0x0c06f85c */
if(!s->budget--) { s->failed_pc=0x0c06f85cu; return 0; }
fr[3]=0;
goto P_0c06f85e;
P_0c06f85e: /* original f0ed, guest PC 0x0c06f85e */
if(!s->budget--) { s->failed_pc=0x0c06f85eu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c06f860;
P_0c06f860: /* original f37d, guest PC 0x0c06f860 */
if(!s->budget--) { s->failed_pc=0x0c06f860u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c06f862;
P_0c06f862: /* original f342, guest PC 0x0c06f862 */
if(!s->budget--) { s->failed_pc=0x0c06f862u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c06f864;
P_0c06f864: /* original 740c, guest PC 0x0c06f864 */
if(!s->budget--) { s->failed_pc=0x0c06f864u; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f866;
P_0c06f866: /* original f232, guest PC 0x0c06f866 */
if(!s->budget--) { s->failed_pc=0x0c06f866u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c06f868;
P_0c06f868: /* original f132, guest PC 0x0c06f868 */
if(!s->budget--) { s->failed_pc=0x0c06f868u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c06f86a;
P_0c06f86a: /* original f032, guest PC 0x0c06f86a */
if(!s->budget--) { s->failed_pc=0x0c06f86au; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c06f86c;
P_0c06f86c: /* original f42b, guest PC 0x0c06f86c */
if(!s->budget--) { s->failed_pc=0x0c06f86cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f86e;
P_0c06f86e: /* original f41b, guest PC 0x0c06f86e */
if(!s->budget--) { s->failed_pc=0x0c06f86eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f870;
P_0c06f870: /* original f40b, guest PC 0x0c06f870 */
if(!s->budget--) { s->failed_pc=0x0c06f870u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f872;
P_0c06f872: /* original 0009, guest PC 0x0c06f872 */
if(!s->budget--) { s->failed_pc=0x0c06f872u; return 0; }
goto P_0c06f874;
P_0c06f874: /* original 64f3, guest PC 0x0c06f874 */
if(!s->budget--) { s->failed_pc=0x0c06f874u; return 0; }
r[4]=r[15];
goto P_0c06f876;
P_0c06f876: /* original 65f3, guest PC 0x0c06f876 */
if(!s->budget--) { s->failed_pc=0x0c06f876u; return 0; }
r[5]=r[15];
goto P_0c06f878;
P_0c06f878: /* original 7444, guest PC 0x0c06f878 */
if(!s->budget--) { s->failed_pc=0x0c06f878u; return 0; }
r[4]+=0x00000044u;
goto P_0c06f87a;
P_0c06f87a: /* original 7520, guest PC 0x0c06f87a */
if(!s->budget--) { s->failed_pc=0x0c06f87au; return 0; }
r[5]+=0x00000020u;
goto P_0c06f87c;
P_0c06f87c: /* original f049, guest PC 0x0c06f87c */
if(!s->budget--) { s->failed_pc=0x0c06f87cu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f87e;
P_0c06f87e: /* original f359, guest PC 0x0c06f87e */
if(!s->budget--) { s->failed_pc=0x0c06f87eu; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f880;
P_0c06f880: /* original f149, guest PC 0x0c06f880 */
if(!s->budget--) { s->failed_pc=0x0c06f880u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f882;
P_0c06f882: /* original f459, guest PC 0x0c06f882 */
if(!s->budget--) { s->failed_pc=0x0c06f882u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f884;
P_0c06f884: /* original f249, guest PC 0x0c06f884 */
if(!s->budget--) { s->failed_pc=0x0c06f884u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06f886;
P_0c06f886: /* original f559, guest PC 0x0c06f886 */
if(!s->budget--) { s->failed_pc=0x0c06f886u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f888;
P_0c06f888: /* original f031, guest PC 0x0c06f888 */
if(!s->budget--) { s->failed_pc=0x0c06f888u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c06f88a;
P_0c06f88a: /* original f251, guest PC 0x0c06f88a */
if(!s->budget--) { s->failed_pc=0x0c06f88au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c06f88c;
P_0c06f88c: /* original f141, guest PC 0x0c06f88c */
if(!s->budget--) { s->failed_pc=0x0c06f88cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c06f88e;
P_0c06f88e: /* original f42b, guest PC 0x0c06f88e */
if(!s->budget--) { s->failed_pc=0x0c06f88eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f890;
P_0c06f890: /* original f41b, guest PC 0x0c06f890 */
if(!s->budget--) { s->failed_pc=0x0c06f890u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f892;
P_0c06f892: /* original f40b, guest PC 0x0c06f892 */
if(!s->budget--) { s->failed_pc=0x0c06f892u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f894;
P_0c06f894: /* original 65f3, guest PC 0x0c06f894 */
if(!s->budget--) { s->failed_pc=0x0c06f894u; return 0; }
r[5]=r[15];
goto P_0c06f896;
P_0c06f896: /* original 64f3, guest PC 0x0c06f896 */
if(!s->budget--) { s->failed_pc=0x0c06f896u; return 0; }
r[4]=r[15];
goto P_0c06f898;
P_0c06f898: /* original 66f3, guest PC 0x0c06f898 */
if(!s->budget--) { s->failed_pc=0x0c06f898u; return 0; }
r[6]=r[15];
goto P_0c06f89a;
P_0c06f89a: /* original 742c, guest PC 0x0c06f89a */
if(!s->budget--) { s->failed_pc=0x0c06f89au; return 0; }
r[4]+=0x0000002cu;
goto P_0c06f89c;
P_0c06f89c: /* original 7644, guest PC 0x0c06f89c */
if(!s->budget--) { s->failed_pc=0x0c06f89cu; return 0; }
r[6]+=0x00000044u;
goto P_0c06f89e;
P_0c06f89e: /* original 7538, guest PC 0x0c06f89e */
if(!s->budget--) { s->failed_pc=0x0c06f89eu; return 0; }
r[5]+=0x00000038u;
goto P_0c06f8a0;
P_0c06f8a0: /* original f059, guest PC 0x0c06f8a0 */
if(!s->budget--) { s->failed_pc=0x0c06f8a0u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8a2;
P_0c06f8a2: /* original f369, guest PC 0x0c06f8a2 */
if(!s->budget--) { s->failed_pc=0x0c06f8a2u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8a4;
P_0c06f8a4: /* original f159, guest PC 0x0c06f8a4 */
if(!s->budget--) { s->failed_pc=0x0c06f8a4u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8a6;
P_0c06f8a6: /* original f469, guest PC 0x0c06f8a6 */
if(!s->budget--) { s->failed_pc=0x0c06f8a6u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8a8;
P_0c06f8a8: /* original f259, guest PC 0x0c06f8a8 */
if(!s->budget--) { s->failed_pc=0x0c06f8a8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8aa;
P_0c06f8aa: /* original f569, guest PC 0x0c06f8aa */
if(!s->budget--) { s->failed_pc=0x0c06f8aau; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8ac;
P_0c06f8ac: /* original 740c, guest PC 0x0c06f8ac */
if(!s->budget--) { s->failed_pc=0x0c06f8acu; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f8ae;
P_0c06f8ae: /* original f030, guest PC 0x0c06f8ae */
if(!s->budget--) { s->failed_pc=0x0c06f8aeu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c06f8b0;
P_0c06f8b0: /* original f250, guest PC 0x0c06f8b0 */
if(!s->budget--) { s->failed_pc=0x0c06f8b0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c06f8b2;
P_0c06f8b2: /* original f140, guest PC 0x0c06f8b2 */
if(!s->budget--) { s->failed_pc=0x0c06f8b2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c06f8b4;
P_0c06f8b4: /* original f42b, guest PC 0x0c06f8b4 */
if(!s->budget--) { s->failed_pc=0x0c06f8b4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f8b6;
P_0c06f8b6: /* original f41b, guest PC 0x0c06f8b6 */
if(!s->budget--) { s->failed_pc=0x0c06f8b6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f8b8;
P_0c06f8b8: /* original f40b, guest PC 0x0c06f8b8 */
if(!s->budget--) { s->failed_pc=0x0c06f8b8u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f8ba;
P_0c06f8ba: /* original 0009, guest PC 0x0c06f8ba */
if(!s->budget--) { s->failed_pc=0x0c06f8bau; return 0; }
goto P_0c06f8bc;
P_0c06f8bc: /* original 64f3, guest PC 0x0c06f8bc */
if(!s->budget--) { s->failed_pc=0x0c06f8bcu; return 0; }
r[4]=r[15];
goto P_0c06f8be;
P_0c06f8be: /* original 65f3, guest PC 0x0c06f8be */
if(!s->budget--) { s->failed_pc=0x0c06f8beu; return 0; }
r[5]=r[15];
goto P_0c06f8c0;
P_0c06f8c0: /* original 742c, guest PC 0x0c06f8c0 */
if(!s->budget--) { s->failed_pc=0x0c06f8c0u; return 0; }
r[4]+=0x0000002cu;
goto P_0c06f8c2;
P_0c06f8c2: /* original f4ec, guest PC 0x0c06f8c2 */
if(!s->budget--) { s->failed_pc=0x0c06f8c2u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06f8c4;
P_0c06f8c4: /* original 752c, guest PC 0x0c06f8c4 */
if(!s->budget--) { s->failed_pc=0x0c06f8c4u; return 0; }
r[5]+=0x0000002cu;
goto P_0c06f8c6;
P_0c06f8c6: /* original f059, guest PC 0x0c06f8c6 */
if(!s->budget--) { s->failed_pc=0x0c06f8c6u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8c8;
P_0c06f8c8: /* original f159, guest PC 0x0c06f8c8 */
if(!s->budget--) { s->failed_pc=0x0c06f8c8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8ca;
P_0c06f8ca: /* original f259, guest PC 0x0c06f8ca */
if(!s->budget--) { s->failed_pc=0x0c06f8cau; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8cc;
P_0c06f8cc: /* original f38d, guest PC 0x0c06f8cc */
if(!s->budget--) { s->failed_pc=0x0c06f8ccu; return 0; }
fr[3]=0;
goto P_0c06f8ce;
P_0c06f8ce: /* original f0ed, guest PC 0x0c06f8ce */
if(!s->budget--) { s->failed_pc=0x0c06f8ceu; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c06f8d0;
P_0c06f8d0: /* original f37d, guest PC 0x0c06f8d0 */
if(!s->budget--) { s->failed_pc=0x0c06f8d0u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c06f8d2;
P_0c06f8d2: /* original f342, guest PC 0x0c06f8d2 */
if(!s->budget--) { s->failed_pc=0x0c06f8d2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c06f8d4;
P_0c06f8d4: /* original 740c, guest PC 0x0c06f8d4 */
if(!s->budget--) { s->failed_pc=0x0c06f8d4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f8d6;
P_0c06f8d6: /* original f232, guest PC 0x0c06f8d6 */
if(!s->budget--) { s->failed_pc=0x0c06f8d6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c06f8d8;
P_0c06f8d8: /* original f132, guest PC 0x0c06f8d8 */
if(!s->budget--) { s->failed_pc=0x0c06f8d8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c06f8da;
P_0c06f8da: /* original f032, guest PC 0x0c06f8da */
if(!s->budget--) { s->failed_pc=0x0c06f8dau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c06f8dc;
P_0c06f8dc: /* original f42b, guest PC 0x0c06f8dc */
if(!s->budget--) { s->failed_pc=0x0c06f8dcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f8de;
P_0c06f8de: /* original f41b, guest PC 0x0c06f8de */
if(!s->budget--) { s->failed_pc=0x0c06f8deu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f8e0;
P_0c06f8e0: /* original f40b, guest PC 0x0c06f8e0 */
if(!s->budget--) { s->failed_pc=0x0c06f8e0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f8e2;
P_0c06f8e2: /* original 0009, guest PC 0x0c06f8e2 */
if(!s->budget--) { s->failed_pc=0x0c06f8e2u; return 0; }
goto P_0c06f8e4;
P_0c06f8e4: /* original 64f3, guest PC 0x0c06f8e4 */
if(!s->budget--) { s->failed_pc=0x0c06f8e4u; return 0; }
r[4]=r[15];
goto P_0c06f8e6;
P_0c06f8e6: /* original 66f3, guest PC 0x0c06f8e6 */
if(!s->budget--) { s->failed_pc=0x0c06f8e6u; return 0; }
r[6]=r[15];
goto P_0c06f8e8;
P_0c06f8e8: /* original 7450, guest PC 0x0c06f8e8 */
if(!s->budget--) { s->failed_pc=0x0c06f8e8u; return 0; }
r[4]+=0x00000050u;
goto P_0c06f8ea;
P_0c06f8ea: /* original 65c3, guest PC 0x0c06f8ea */
if(!s->budget--) { s->failed_pc=0x0c06f8eau; return 0; }
r[5]=r[12];
goto P_0c06f8ec;
P_0c06f8ec: /* original 762c, guest PC 0x0c06f8ec */
if(!s->budget--) { s->failed_pc=0x0c06f8ecu; return 0; }
r[6]+=0x0000002cu;
goto P_0c06f8ee;
P_0c06f8ee: /* original f059, guest PC 0x0c06f8ee */
if(!s->budget--) { s->failed_pc=0x0c06f8eeu; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f0;
P_0c06f8f0: /* original f369, guest PC 0x0c06f8f0 */
if(!s->budget--) { s->failed_pc=0x0c06f8f0u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f2;
P_0c06f8f2: /* original f159, guest PC 0x0c06f8f2 */
if(!s->budget--) { s->failed_pc=0x0c06f8f2u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f4;
P_0c06f8f4: /* original f469, guest PC 0x0c06f8f4 */
if(!s->budget--) { s->failed_pc=0x0c06f8f4u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f6;
P_0c06f8f6: /* original f259, guest PC 0x0c06f8f6 */
if(!s->budget--) { s->failed_pc=0x0c06f8f6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8f8;
P_0c06f8f8: /* original f569, guest PC 0x0c06f8f8 */
if(!s->budget--) { s->failed_pc=0x0c06f8f8u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f8fa;
P_0c06f8fa: /* original 740c, guest PC 0x0c06f8fa */
if(!s->budget--) { s->failed_pc=0x0c06f8fau; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f8fc;
P_0c06f8fc: /* original f030, guest PC 0x0c06f8fc */
if(!s->budget--) { s->failed_pc=0x0c06f8fcu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c06f8fe;
P_0c06f8fe: /* original f250, guest PC 0x0c06f8fe */
if(!s->budget--) { s->failed_pc=0x0c06f8feu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c06f900;
P_0c06f900: /* original f140, guest PC 0x0c06f900 */
if(!s->budget--) { s->failed_pc=0x0c06f900u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c06f902;
P_0c06f902: /* original f42b, guest PC 0x0c06f902 */
if(!s->budget--) { s->failed_pc=0x0c06f902u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f904;
P_0c06f904: /* original f41b, guest PC 0x0c06f904 */
if(!s->budget--) { s->failed_pc=0x0c06f904u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f906;
P_0c06f906: /* original f40b, guest PC 0x0c06f906 */
if(!s->budget--) { s->failed_pc=0x0c06f906u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f908;
P_0c06f908: /* original 66f3, guest PC 0x0c06f908 */
if(!s->budget--) { s->failed_pc=0x0c06f908u; return 0; }
r[6]=r[15];
goto P_0c06f90a;
P_0c06f90a: /* original 64d3, guest PC 0x0c06f90a */
if(!s->budget--) { s->failed_pc=0x0c06f90au; return 0; }
r[4]=r[13];
goto P_0c06f90c;
P_0c06f90c: /* original 65c3, guest PC 0x0c06f90c */
if(!s->budget--) { s->failed_pc=0x0c06f90cu; return 0; }
r[5]=r[12];
goto P_0c06f90e;
P_0c06f90e: /* original 762c, guest PC 0x0c06f90e */
if(!s->budget--) { s->failed_pc=0x0c06f90eu; return 0; }
r[6]+=0x0000002cu;
goto P_0c06f910;
P_0c06f910: /* original f059, guest PC 0x0c06f910 */
if(!s->budget--) { s->failed_pc=0x0c06f910u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f912;
P_0c06f912: /* original f369, guest PC 0x0c06f912 */
if(!s->budget--) { s->failed_pc=0x0c06f912u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f914;
P_0c06f914: /* original f159, guest PC 0x0c06f914 */
if(!s->budget--) { s->failed_pc=0x0c06f914u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f916;
P_0c06f916: /* original f469, guest PC 0x0c06f916 */
if(!s->budget--) { s->failed_pc=0x0c06f916u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f918;
P_0c06f918: /* original f259, guest PC 0x0c06f918 */
if(!s->budget--) { s->failed_pc=0x0c06f918u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c06f91a;
P_0c06f91a: /* original f569, guest PC 0x0c06f91a */
if(!s->budget--) { s->failed_pc=0x0c06f91au; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c06f91c;
P_0c06f91c: /* original 740c, guest PC 0x0c06f91c */
if(!s->budget--) { s->failed_pc=0x0c06f91cu; return 0; }
r[4]+=0x0000000cu;
goto P_0c06f91e;
P_0c06f91e: /* original f030, guest PC 0x0c06f91e */
if(!s->budget--) { s->failed_pc=0x0c06f91eu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c06f920;
P_0c06f920: /* original f250, guest PC 0x0c06f920 */
if(!s->budget--) { s->failed_pc=0x0c06f920u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c06f922;
P_0c06f922: /* original f140, guest PC 0x0c06f922 */
if(!s->budget--) { s->failed_pc=0x0c06f922u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c06f924;
P_0c06f924: /* original f42b, guest PC 0x0c06f924 */
if(!s->budget--) { s->failed_pc=0x0c06f924u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c06f926;
P_0c06f926: /* original f41b, guest PC 0x0c06f926 */
if(!s->budget--) { s->failed_pc=0x0c06f926u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c06f928;
P_0c06f928: /* original f40b, guest PC 0x0c06f928 */
if(!s->budget--) { s->failed_pc=0x0c06f928u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c06f92a;
P_0c06f92a: /* original 0009, guest PC 0x0c06f92a */
if(!s->budget--) { s->failed_pc=0x0c06f92au; return 0; }
goto P_0c06f92c;
P_0c06f92c: /* original 7901, guest PC 0x0c06f92c */
if(!s->budget--) { s->failed_pc=0x0c06f92cu; return 0; }
r[9]+=0x00000001u;
goto P_0c06f92e;
P_0c06f92e: /* original 39a3, guest PC 0x0c06f92e */
if(!s->budget--) { s->failed_pc=0x0c06f92eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[10])!=0);
goto P_0c06f930;
P_0c06f930: /* original 7d18, guest PC 0x0c06f930 */
if(!s->budget--) { s->failed_pc=0x0c06f930u; return 0; }
r[13]+=0x00000018u;
goto P_0c06f932;
P_0c06f932: /* original 8d03, guest PC 0x0c06f932 */
if(!s->budget--) { s->failed_pc=0x0c06f932u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000018u;
if(cond) { goto P_0c06f93c; }
goto P_0c06f936;
P_0c06f934: /* original 7c18, guest PC 0x0c06f934 */
if(!s->budget--) { s->failed_pc=0x0c06f934u; return 0; }
r[12]+=0x00000018u;
goto P_0c06f936;
P_0c06f936: /* original d234, guest PC 0x0c06f936 */
if(!s->budget--) { s->failed_pc=0x0c06f936u; return 0; }
r[2]=read(ram,0x0c06fa08u,4);
goto P_0c06f938;
P_0c06f938: /* original 422b, guest PC 0x0c06f938 */
if(!s->budget--) { s->failed_pc=0x0c06f938u; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c06f93a: /* original 0009, guest PC 0x0c06f93a */
if(!s->budget--) { s->failed_pc=0x0c06f93au; return 0; }
goto P_0c06f93c;
P_0c06f93c: /* original d333, guest PC 0x0c06f93c */
if(!s->budget--) { s->failed_pc=0x0c06f93cu; return 0; }
r[3]=read(ram,0x0c06fa0cu,4);
goto P_0c06f93e;
P_0c06f93e: /* original 65e3, guest PC 0x0c06f93e */
if(!s->budget--) { s->failed_pc=0x0c06f93eu; return 0; }
r[5]=r[14];
goto P_0c06f940;
P_0c06f940: /* original 6783, guest PC 0x0c06f940 */
if(!s->budget--) { s->failed_pc=0x0c06f940u; return 0; }
r[7]=r[8];
goto P_0c06f942;
P_0c06f942: /* original 66d3, guest PC 0x0c06f942 */
if(!s->budget--) { s->failed_pc=0x0c06f942u; return 0; }
r[6]=r[13];
goto P_0c06f944;
P_0c06f944: /* original 430b, guest PC 0x0c06f944 */
if(!s->budget--) { s->failed_pc=0x0c06f944u; return 0; }
target=r[3];
r[16]=0x0c06f948u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f948u) { target=s->pc; goto dispatch; }
goto P_0c06f948;
P_0c06f946: /* original 64b3, guest PC 0x0c06f946 */
if(!s->budget--) { s->failed_pc=0x0c06f946u; return 0; }
r[4]=r[11];
goto P_0c06f948;
P_0c06f948: /* original 7801, guest PC 0x0c06f948 */
if(!s->budget--) { s->failed_pc=0x0c06f948u; return 0; }
r[8]+=0x00000001u;
goto P_0c06f94a;
P_0c06f94a: /* original 52f1, guest PC 0x0c06f94a */
if(!s->budget--) { s->failed_pc=0x0c06f94au; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c06f94c;
P_0c06f94c: /* original 3823, guest PC 0x0c06f94c */
if(!s->budget--) { s->failed_pc=0x0c06f94cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[2])!=0);
goto P_0c06f94e;
P_0c06f94e: /* original 8902, guest PC 0x0c06f94e */
if(!s->budget--) { s->failed_pc=0x0c06f94eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06f956; }
goto P_0c06f950;
P_0c06f950: /* original d32f, guest PC 0x0c06f950 */
if(!s->budget--) { s->failed_pc=0x0c06f950u; return 0; }
r[3]=read(ram,0x0c06fa10u,4);
goto P_0c06f952;
P_0c06f952: /* original 432b, guest PC 0x0c06f952 */
if(!s->budget--) { s->failed_pc=0x0c06f952u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c06f954: /* original 0009, guest PC 0x0c06f954 */
if(!s->budget--) { s->failed_pc=0x0c06f954u; return 0; }
goto P_0c06f956;
P_0c06f956: /* original d22f, guest PC 0x0c06f956 */
if(!s->budget--) { s->failed_pc=0x0c06f956u; return 0; }
r[2]=read(ram,0x0c06fa14u,4);
goto P_0c06f958;
P_0c06f958: /* original 420b, guest PC 0x0c06f958 */
if(!s->budget--) { s->failed_pc=0x0c06f958u; return 0; }
target=r[2];
r[16]=0x0c06f95cu;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f95cu) { target=s->pc; goto dispatch; }
goto P_0c06f95c;
P_0c06f95a: /* original e401, guest PC 0x0c06f95a */
if(!s->budget--) { s->failed_pc=0x0c06f95au; return 0; }
r[4]=0x00000001u;
goto P_0c06f95c;
P_0c06f95c: /* original d32e, guest PC 0x0c06f95c */
if(!s->budget--) { s->failed_pc=0x0c06f95cu; return 0; }
r[3]=read(ram,0x0c06fa18u,4);
goto P_0c06f95e;
P_0c06f95e: /* original 430b, guest PC 0x0c06f95e */
if(!s->budget--) { s->failed_pc=0x0c06f95eu; return 0; }
target=r[3];
r[16]=0x0c06f962u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f962u) { target=s->pc; goto dispatch; }
goto P_0c06f962;
P_0c06f960: /* original 64e3, guest PC 0x0c06f960 */
if(!s->budget--) { s->failed_pc=0x0c06f960u; return 0; }
r[4]=r[14];
goto P_0c06f962;
P_0c06f962: /* original d22e, guest PC 0x0c06f962 */
if(!s->budget--) { s->failed_pc=0x0c06f962u; return 0; }
r[2]=read(ram,0x0c06fa1cu,4);
goto P_0c06f964;
P_0c06f964: /* original 65e3, guest PC 0x0c06f964 */
if(!s->budget--) { s->failed_pc=0x0c06f964u; return 0; }
r[5]=r[14];
goto P_0c06f966;
P_0c06f966: /* original 420b, guest PC 0x0c06f966 */
if(!s->budget--) { s->failed_pc=0x0c06f966u; return 0; }
target=r[2];
r[16]=0x0c06f96au;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f96au) { target=s->pc; goto dispatch; }
goto P_0c06f96a;
P_0c06f968: /* original 64b3, guest PC 0x0c06f968 */
if(!s->budget--) { s->failed_pc=0x0c06f968u; return 0; }
r[4]=r[11];
goto P_0c06f96a;
P_0c06f96a: /* original d32d, guest PC 0x0c06f96a */
if(!s->budget--) { s->failed_pc=0x0c06f96au; return 0; }
r[3]=read(ram,0x0c06fa20u,4);
goto P_0c06f96c;
P_0c06f96c: /* original 64e3, guest PC 0x0c06f96c */
if(!s->budget--) { s->failed_pc=0x0c06f96cu; return 0; }
r[4]=r[14];
goto P_0c06f96e;
P_0c06f96e: /* original 65f2, guest PC 0x0c06f96e */
if(!s->budget--) { s->failed_pc=0x0c06f96eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06f970;
P_0c06f970: /* original 430b, guest PC 0x0c06f970 */
if(!s->budget--) { s->failed_pc=0x0c06f970u; return 0; }
target=r[3];
r[16]=0x0c06f974u;
r[4]+=0x00000010u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c06f974u) { target=s->pc; goto dispatch; }
goto P_0c06f974;
P_0c06f972: /* original 7410, guest PC 0x0c06f972 */
if(!s->budget--) { s->failed_pc=0x0c06f972u; return 0; }
r[4]+=0x00000010u;
goto P_0c06f974;
P_0c06f974: /* original 7f74, guest PC 0x0c06f974 */
if(!s->budget--) { s->failed_pc=0x0c06f974u; return 0; }
r[15]+=0x00000074u;
goto P_0c06f976;
P_0c06f976: /* original 4f16, guest PC 0x0c06f976 */
if(!s->budget--) { s->failed_pc=0x0c06f976u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06f978;
P_0c06f978: /* original 4f26, guest PC 0x0c06f978 */
if(!s->budget--) { s->failed_pc=0x0c06f978u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06f97a;
P_0c06f97a: /* original fcf9, guest PC 0x0c06f97a */
if(!s->budget--) { s->failed_pc=0x0c06f97au; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f97c;
P_0c06f97c: /* original fdf9, guest PC 0x0c06f97c */
if(!s->budget--) { s->failed_pc=0x0c06f97cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f97e;
P_0c06f97e: /* original fef9, guest PC 0x0c06f97e */
if(!s->budget--) { s->failed_pc=0x0c06f97eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f980;
P_0c06f980: /* original fff9, guest PC 0x0c06f980 */
if(!s->budget--) { s->failed_pc=0x0c06f980u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06f982;
P_0c06f982: /* original 68f6, guest PC 0x0c06f982 */
if(!s->budget--) { s->failed_pc=0x0c06f982u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06f984;
P_0c06f984: /* original 69f6, guest PC 0x0c06f984 */
if(!s->budget--) { s->failed_pc=0x0c06f984u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06f986;
P_0c06f986: /* original 6af6, guest PC 0x0c06f986 */
if(!s->budget--) { s->failed_pc=0x0c06f986u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06f988;
P_0c06f988: /* original 6bf6, guest PC 0x0c06f988 */
if(!s->budget--) { s->failed_pc=0x0c06f988u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06f98a;
P_0c06f98a: /* original 6cf6, guest PC 0x0c06f98a */
if(!s->budget--) { s->failed_pc=0x0c06f98au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06f98c;
P_0c06f98c: /* original 6df6, guest PC 0x0c06f98c */
if(!s->budget--) { s->failed_pc=0x0c06f98cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06f98e;
P_0c06f98e: /* original 000b, guest PC 0x0c06f98e */
if(!s->budget--) { s->failed_pc=0x0c06f98eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06f990: /* original 6ef6, guest PC 0x0c06f990 */
if(!s->budget--) { s->failed_pc=0x0c06f990u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06f992u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c038a20u,0x0c038a22u,0x0c038a24u,0x0c038a26u,0x0c038a28u,0x0c038a2au,0x0c038a2cu,0x0c038a2eu,0x0c038a30u,0x0c038a32u,0x0c038a34u,0x0c038a36u,0x0c038a38u,0x0c038a3au,0x0c038a3cu,0x0c038a3eu,
0x0c038a40u,0x0c038a42u,0x0c038a44u,0x0c03f77eu,0x0c03f780u,0x0c03f782u,0x0c03f784u,0x0c03f786u,0x0c03f788u,0x0c03f78au,0x0c03f7c0u,0x0c03f7c2u,0x0c03f7c4u,0x0c03f7c6u,0x0c03f7c8u,0x0c03f7cau,
0x0c03f7ccu,0x0c03f7ceu,0x0c03f7d0u,0x0c03f7d2u,0x0c03f7d4u,0x0c03f7d6u,0x0c03f7d8u,0x0c03f7dau,0x0c03f7dcu,0x0c03f7deu,0x0c03f7e0u,0x0c03f7e2u,0x0c03f7e4u,0x0c03f7e6u,0x0c03f7e8u,0x0c03f7eau,
0x0c03f7ecu,0x0c03f7eeu,0x0c03f7f0u,0x0c03f7f2u,0x0c03f7f4u,0x0c03f7f6u,0x0c03f7f8u,0x0c03f7fau,0x0c03f7fcu,0x0c03f7feu,0x0c03f800u,0x0c03f802u,0x0c03f804u,0x0c03f806u,0x0c03f808u,0x0c03f80au,
0x0c03fc90u,0x0c03fc92u,0x0c03fc94u,0x0c03fc96u,0x0c03fc98u,0x0c03fc9au,0x0c03fc9cu,0x0c03fc9eu,0x0c03fca0u,0x0c03fca2u,0x0c03fca4u,0x0c03fca6u,0x0c03fca8u,0x0c03fcaau,0x0c03fcacu,0x0c03fcaeu,
0x0c03fcb0u,0x0c03fcb2u,0x0c03fcb4u,0x0c03fcb6u,0x0c03fcb8u,0x0c03fcbau,0x0c03fcbcu,0x0c03fcbeu,0x0c03fcc0u,0x0c03fcc2u,0x0c03fcc4u,0x0c03fcc6u,0x0c03fcc8u,0x0c03fccau,0x0c03fcccu,0x0c03fcceu,
0x0c03fcd0u,0x0c03fcd2u,0x0c03fcd4u,0x0c03fcd6u,0x0c03fcd8u,0x0c03fcdau,0x0c03fcdcu,0x0c03fcdeu,0x0c03fce0u,0x0c03fce2u,0x0c03fce4u,0x0c03fce6u,0x0c03fce8u,0x0c03fceau,0x0c03fcecu,0x0c03fd02u,
0x0c03fd04u,0x0c03fd06u,0x0c03fd08u,0x0c03fd0au,0x0c03fd10u,0x0c03fd12u,0x0c03fd14u,0x0c03fd16u,0x0c03fd18u,0x0c03fd1au,0x0c03fd1cu,0x0c03fd1eu,0x0c03fd20u,0x0c03fd22u,0x0c03fd24u,0x0c03fd26u,
0x0c03fd28u,0x0c03fd2au,0x0c03fd2cu,0x0c03fd2eu,0x0c03fd30u,0x0c03fd32u,0x0c03fd34u,0x0c03fd36u,0x0c03fd38u,0x0c03fd3au,0x0c03fd3cu,0x0c03fd3eu,0x0c03fd40u,0x0c03fd42u,0x0c03fd44u,0x0c03fd70u,
0x0c03fd72u,0x0c03fd74u,0x0c03fd76u,0x0c03fd78u,0x0c03fd7au,0x0c03fd7cu,0x0c03fd7eu,0x0c03fd80u,0x0c03fd82u,0x0c03fd84u,0x0c03fd86u,0x0c03fd88u,0x0c03fd8au,0x0c03fd8cu,0x0c03fd8eu,0x0c03fd90u,
0x0c03fd92u,0x0c03fd94u,0x0c042c20u,0x0c042c22u,0x0c042c24u,0x0c042c26u,0x0c042c28u,0x0c042c2au,0x0c042c2cu,0x0c042c2eu,0x0c042c30u,0x0c042c32u,0x0c042c34u,0x0c042c36u,0x0c042c38u,0x0c042c3au,
0x0c042c3cu,0x0c042c3eu,0x0c042c40u,0x0c042c42u,0x0c042c44u,0x0c042c46u,0x0c042c48u,0x0c042c4au,0x0c042c4cu,0x0c042c4eu,0x0c042c50u,0x0c042c52u,0x0c042c54u,0x0c042c56u,0x0c042c58u,0x0c042c5au,
0x0c042c5cu,0x0c042c5eu,0x0c042c60u,0x0c042c62u,0x0c042c64u,0x0c042c66u,0x0c042c68u,0x0c042c6au,0x0c042c6cu,0x0c042c6eu,0x0c042c70u,0x0c042c72u,0x0c042c74u,0x0c042c76u,0x0c042c78u,0x0c042c7au,
0x0c042c7cu,0x0c042c7eu,0x0c042c80u,0x0c042c82u,0x0c042c84u,0x0c042c86u,0x0c042c88u,0x0c042c8au,0x0c042c8cu,0x0c042c8eu,0x0c042c90u,0x0c042c92u,0x0c042c94u,0x0c042c96u,0x0c042c98u,0x0c042c9au,
0x0c042c9cu,0x0c042c9eu,0x0c042ca0u,0x0c042ca2u,0x0c042ca4u,0x0c042ca6u,0x0c042ca8u,0x0c042caau,0x0c042cacu,0x0c042caeu,0x0c042cb0u,0x0c042cb2u,0x0c042cb4u,0x0c042cb6u,0x0c042cb8u,0x0c042cbau,
0x0c042cbcu,0x0c042cbeu,0x0c042cc0u,0x0c042cc2u,0x0c042cc4u,0x0c042cc6u,0x0c042cc8u,0x0c042ccau,0x0c0441b6u,0x0c0441b8u,0x0c0441bau,0x0c0441bcu,0x0c0441beu,0x0c0441c0u,0x0c0441c2u,0x0c0441c4u,
0x0c0441c6u,0x0c0441c8u,0x0c0441cau,0x0c0441ccu,0x0c0441ceu,0x0c0441d0u,0x0c0441d2u,0x0c0441d4u,0x0c0441d6u,0x0c0441d8u,0x0c0441dau,0x0c0441dcu,0x0c0441deu,0x0c0441e0u,0x0c0441e2u,0x0c0441e4u,
0x0c044234u,0x0c044236u,0x0c044238u,0x0c04423au,0x0c04423cu,0x0c04423eu,0x0c044240u,0x0c044242u,0x0c044244u,0x0c044246u,0x0c044248u,0x0c04424au,0x0c04424cu,0x0c04424eu,0x0c044250u,0x0c044252u,
0x0c044254u,0x0c044256u,0x0c044258u,0x0c04425au,0x0c04425cu,0x0c04425eu,0x0c044260u,0x0c044262u,0x0c044264u,0x0c044266u,0x0c044268u,0x0c04426au,0x0c04426cu,0x0c04426eu,0x0c044270u,0x0c044272u,
0x0c044274u,0x0c044276u,0x0c044278u,0x0c04427au,0x0c04427cu,0x0c04427eu,0x0c044280u,0x0c044282u,0x0c044284u,0x0c044286u,0x0c044288u,0x0c04428au,0x0c04428cu,0x0c04428eu,0x0c044290u,0x0c044292u,
0x0c044302u,0x0c044304u,0x0c044306u,0x0c044308u,0x0c04430au,0x0c04430cu,0x0c04430eu,0x0c044310u,0x0c044312u,0x0c044314u,0x0c044316u,0x0c044318u,0x0c04431au,0x0c04431cu,0x0c04431eu,0x0c044320u,
0x0c044322u,0x0c044324u,0x0c044326u,0x0c044328u,0x0c04432au,0x0c04432cu,0x0c04432eu,0x0c044330u,0x0c044332u,0x0c044334u,0x0c044336u,0x0c044338u,0x0c04433au,0x0c04433cu,0x0c04433eu,0x0c044340u,
0x0c044342u,0x0c044344u,0x0c044346u,0x0c044348u,0x0c04434au,0x0c04434cu,0x0c04434eu,0x0c044350u,0x0c044352u,0x0c044354u,0x0c044356u,0x0c044358u,0x0c04435au,0x0c04435cu,0x0c04435eu,0x0c044360u,
0x0c044362u,0x0c044364u,0x0c044366u,0x0c044368u,0x0c06f814u,0x0c06f816u,0x0c06f818u,0x0c06f81au,0x0c06f81cu,0x0c06f81eu,0x0c06f820u,0x0c06f822u,0x0c06f824u,0x0c06f826u,0x0c06f828u,0x0c06f82au,
0x0c06f82cu,0x0c06f82eu,0x0c06f830u,0x0c06f832u,0x0c06f834u,0x0c06f836u,0x0c06f838u,0x0c06f83au,0x0c06f83cu,0x0c06f83eu,0x0c06f840u,0x0c06f842u,0x0c06f844u,0x0c06f846u,0x0c06f848u,0x0c06f84au,
0x0c06f84cu,0x0c06f84eu,0x0c06f850u,0x0c06f852u,0x0c06f854u,0x0c06f856u,0x0c06f858u,0x0c06f85au,0x0c06f85cu,0x0c06f85eu,0x0c06f860u,0x0c06f862u,0x0c06f864u,0x0c06f866u,0x0c06f868u,0x0c06f86au,
0x0c06f86cu,0x0c06f86eu,0x0c06f870u,0x0c06f872u,0x0c06f874u,0x0c06f876u,0x0c06f878u,0x0c06f87au,0x0c06f87cu,0x0c06f87eu,0x0c06f880u,0x0c06f882u,0x0c06f884u,0x0c06f886u,0x0c06f888u,0x0c06f88au,
0x0c06f88cu,0x0c06f88eu,0x0c06f890u,0x0c06f892u,0x0c06f894u,0x0c06f896u,0x0c06f898u,0x0c06f89au,0x0c06f89cu,0x0c06f89eu,0x0c06f8a0u,0x0c06f8a2u,0x0c06f8a4u,0x0c06f8a6u,0x0c06f8a8u,0x0c06f8aau,
0x0c06f8acu,0x0c06f8aeu,0x0c06f8b0u,0x0c06f8b2u,0x0c06f8b4u,0x0c06f8b6u,0x0c06f8b8u,0x0c06f8bau,0x0c06f8bcu,0x0c06f8beu,0x0c06f8c0u,0x0c06f8c2u,0x0c06f8c4u,0x0c06f8c6u,0x0c06f8c8u,0x0c06f8cau,
0x0c06f8ccu,0x0c06f8ceu,0x0c06f8d0u,0x0c06f8d2u,0x0c06f8d4u,0x0c06f8d6u,0x0c06f8d8u,0x0c06f8dau,0x0c06f8dcu,0x0c06f8deu,0x0c06f8e0u,0x0c06f8e2u,0x0c06f8e4u,0x0c06f8e6u,0x0c06f8e8u,0x0c06f8eau,
0x0c06f8ecu,0x0c06f8eeu,0x0c06f8f0u,0x0c06f8f2u,0x0c06f8f4u,0x0c06f8f6u,0x0c06f8f8u,0x0c06f8fau,0x0c06f8fcu,0x0c06f8feu,0x0c06f900u,0x0c06f902u,0x0c06f904u,0x0c06f906u,0x0c06f908u,0x0c06f90au,
0x0c06f90cu,0x0c06f90eu,0x0c06f910u,0x0c06f912u,0x0c06f914u,0x0c06f916u,0x0c06f918u,0x0c06f91au,0x0c06f91cu,0x0c06f91eu,0x0c06f920u,0x0c06f922u,0x0c06f924u,0x0c06f926u,0x0c06f928u,0x0c06f92au,
0x0c06f92cu,0x0c06f92eu,0x0c06f930u,0x0c06f932u,0x0c06f934u,0x0c06f936u,0x0c06f938u,0x0c06f93au,0x0c06f93cu,0x0c06f93eu,0x0c06f940u,0x0c06f942u,0x0c06f944u,0x0c06f946u,0x0c06f948u,0x0c06f94au,
0x0c06f94cu,0x0c06f94eu,0x0c06f950u,0x0c06f952u,0x0c06f954u,0x0c06f956u,0x0c06f958u,0x0c06f95au,0x0c06f95cu,0x0c06f95eu,0x0c06f960u,0x0c06f962u,0x0c06f964u,0x0c06f966u,0x0c06f968u,0x0c06f96au,
0x0c06f96cu,0x0c06f96eu,0x0c06f970u,0x0c06f972u,0x0c06f974u,0x0c06f976u,0x0c06f978u,0x0c06f97au,0x0c06f97cu,0x0c06f97eu,0x0c06f980u,0x0c06f982u,0x0c06f984u,0x0c06f986u,0x0c06f988u,0x0c06f98au,
0x0c06f98cu,0x0c06f98eu,0x0c06f990u,
};
int vf3_seventh_c3_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
