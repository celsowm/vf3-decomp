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
int vf3_seventh_c12_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c038b40u: goto P_0c038b40;
case 0x0c038b42u: goto P_0c038b42;
case 0x0c038b44u: goto P_0c038b44;
case 0x0c038b46u: goto P_0c038b46;
case 0x0c038b48u: goto P_0c038b48;
case 0x0c038b4au: goto P_0c038b4a;
case 0x0c038b4cu: goto P_0c038b4c;
case 0x0c038b4eu: goto P_0c038b4e;
case 0x0c038b50u: goto P_0c038b50;
case 0x0c038b52u: goto P_0c038b52;
case 0x0c038b54u: goto P_0c038b54;
case 0x0c038b56u: goto P_0c038b56;
case 0x0c038b58u: goto P_0c038b58;
case 0x0c038b60u: goto P_0c038b60;
case 0x0c038b62u: goto P_0c038b62;
case 0x0c038b64u: goto P_0c038b64;
case 0x0c038b66u: goto P_0c038b66;
case 0x0c038b68u: goto P_0c038b68;
case 0x0c038b6au: goto P_0c038b6a;
case 0x0c038b6cu: goto P_0c038b6c;
case 0x0c038b6eu: goto P_0c038b6e;
case 0x0c038b70u: goto P_0c038b70;
case 0x0c038b72u: goto P_0c038b72;
case 0x0c038b74u: goto P_0c038b74;
case 0x0c038b76u: goto P_0c038b76;
case 0x0c038b78u: goto P_0c038b78;
case 0x0c038b7au: goto P_0c038b7a;
case 0x0c038b7cu: goto P_0c038b7c;
case 0x0c038b7eu: goto P_0c038b7e;
case 0x0c038b80u: goto P_0c038b80;
case 0x0c038b82u: goto P_0c038b82;
case 0x0c038b90u: goto P_0c038b90;
case 0x0c038b92u: goto P_0c038b92;
case 0x0c038b94u: goto P_0c038b94;
case 0x0c038b96u: goto P_0c038b96;
case 0x0c038b98u: goto P_0c038b98;
case 0x0c038b9au: goto P_0c038b9a;
case 0x0c038b9cu: goto P_0c038b9c;
case 0x0c038b9eu: goto P_0c038b9e;
case 0x0c038ba0u: goto P_0c038ba0;
case 0x0c038ba2u: goto P_0c038ba2;
case 0x0c038ba4u: goto P_0c038ba4;
case 0x0c038ba6u: goto P_0c038ba6;
case 0x0c038ba8u: goto P_0c038ba8;
case 0x0c038baau: goto P_0c038baa;
case 0x0c038bacu: goto P_0c038bac;
case 0x0c038baeu: goto P_0c038bae;
case 0x0c038bb0u: goto P_0c038bb0;
case 0x0c038bb2u: goto P_0c038bb2;
case 0x0c038bb4u: goto P_0c038bb4;
case 0x0c03b684u: goto P_0c03b684;
case 0x0c03b686u: goto P_0c03b686;
case 0x0c03b688u: goto P_0c03b688;
case 0x0c03b68au: goto P_0c03b68a;
case 0x0c03b68cu: goto P_0c03b68c;
case 0x0c03b68eu: goto P_0c03b68e;
case 0x0c054524u: goto P_0c054524;
case 0x0c054526u: goto P_0c054526;
case 0x0c054528u: goto P_0c054528;
case 0x0c05452au: goto P_0c05452a;
case 0x0c05452cu: goto P_0c05452c;
case 0x0c066fd8u: goto P_0c066fd8;
case 0x0c066fdau: goto P_0c066fda;
case 0x0c066fdcu: goto P_0c066fdc;
case 0x0c066fdeu: goto P_0c066fde;
case 0x0c066fe0u: goto P_0c066fe0;
case 0x0c066fe2u: goto P_0c066fe2;
case 0x0c066fe4u: goto P_0c066fe4;
case 0x0c066fe6u: goto P_0c066fe6;
case 0x0c066fe8u: goto P_0c066fe8;
case 0x0c066feau: goto P_0c066fea;
case 0x0c066fecu: goto P_0c066fec;
case 0x0c066feeu: goto P_0c066fee;
case 0x0c066ff0u: goto P_0c066ff0;
case 0x0c066ff2u: goto P_0c066ff2;
case 0x0c066ff4u: goto P_0c066ff4;
case 0x0c066ff6u: goto P_0c066ff6;
case 0x0c066ff8u: goto P_0c066ff8;
case 0x0c066ffau: goto P_0c066ffa;
case 0x0c066ffcu: goto P_0c066ffc;
case 0x0c066ffeu: goto P_0c066ffe;
case 0x0c067000u: goto P_0c067000;
case 0x0c067002u: goto P_0c067002;
case 0x0c067004u: goto P_0c067004;
case 0x0c067006u: goto P_0c067006;
case 0x0c067008u: goto P_0c067008;
case 0x0c06700au: goto P_0c06700a;
case 0x0c06700cu: goto P_0c06700c;
case 0x0c06700eu: goto P_0c06700e;
case 0x0c067010u: goto P_0c067010;
case 0x0c067012u: goto P_0c067012;
case 0x0c067014u: goto P_0c067014;
case 0x0c067016u: goto P_0c067016;
case 0x0c067018u: goto P_0c067018;
case 0x0c06701au: goto P_0c06701a;
case 0x0c06701cu: goto P_0c06701c;
case 0x0c06701eu: goto P_0c06701e;
case 0x0c067020u: goto P_0c067020;
case 0x0c067022u: goto P_0c067022;
case 0x0c067024u: goto P_0c067024;
case 0x0c067026u: goto P_0c067026;
case 0x0c067028u: goto P_0c067028;
case 0x0c06702au: goto P_0c06702a;
case 0x0c06702cu: goto P_0c06702c;
case 0x0c06702eu: goto P_0c06702e;
case 0x0c067030u: goto P_0c067030;
case 0x0c067032u: goto P_0c067032;
case 0x0c067034u: goto P_0c067034;
case 0x0c067036u: goto P_0c067036;
case 0x0c067038u: goto P_0c067038;
case 0x0c06703au: goto P_0c06703a;
case 0x0c06703cu: goto P_0c06703c;
case 0x0c06703eu: goto P_0c06703e;
case 0x0c067040u: goto P_0c067040;
case 0x0c067042u: goto P_0c067042;
case 0x0c067044u: goto P_0c067044;
case 0x0c067046u: goto P_0c067046;
case 0x0c067048u: goto P_0c067048;
case 0x0c06704au: goto P_0c06704a;
case 0x0c06704cu: goto P_0c06704c;
case 0x0c06704eu: goto P_0c06704e;
case 0x0c067050u: goto P_0c067050;
case 0x0c067052u: goto P_0c067052;
case 0x0c067054u: goto P_0c067054;
case 0x0c067056u: goto P_0c067056;
case 0x0c067058u: goto P_0c067058;
case 0x0c06705au: goto P_0c06705a;
case 0x0c06705cu: goto P_0c06705c;
case 0x0c07021cu: goto P_0c07021c;
case 0x0c07021eu: goto P_0c07021e;
case 0x0c070220u: goto P_0c070220;
case 0x0c070222u: goto P_0c070222;
case 0x0c070224u: goto P_0c070224;
case 0x0c070fa6u: goto P_0c070fa6;
case 0x0c070fa8u: goto P_0c070fa8;
case 0x0c070faau: goto P_0c070faa;
case 0x0c070facu: goto P_0c070fac;
case 0x0c070faeu: goto P_0c070fae;
case 0x0c070fb0u: goto P_0c070fb0;
case 0x0c070fb2u: goto P_0c070fb2;
case 0x0c070fb4u: goto P_0c070fb4;
case 0x0c070fb6u: goto P_0c070fb6;
case 0x0c070fb8u: goto P_0c070fb8;
case 0x0c070fc4u: goto P_0c070fc4;
case 0x0c070fc6u: goto P_0c070fc6;
case 0x0c070fc8u: goto P_0c070fc8;
case 0x0c070fcau: goto P_0c070fca;
case 0x0c070fccu: goto P_0c070fcc;
case 0x0c070fceu: goto P_0c070fce;
case 0x0c070fd0u: goto P_0c070fd0;
case 0x0c070fd2u: goto P_0c070fd2;
case 0x0c070fd4u: goto P_0c070fd4;
case 0x0c070fd6u: goto P_0c070fd6;
case 0x0c070fd8u: goto P_0c070fd8;
case 0x0c070fdau: goto P_0c070fda;
case 0x0c070fdcu: goto P_0c070fdc;
case 0x0c070fdeu: goto P_0c070fde;
case 0x0c070fe0u: goto P_0c070fe0;
case 0x0c070fe2u: goto P_0c070fe2;
case 0x0c070fe4u: goto P_0c070fe4;
case 0x0c070fe6u: goto P_0c070fe6;
case 0x0c070fe8u: goto P_0c070fe8;
case 0x0c070feau: goto P_0c070fea;
case 0x0c070fecu: goto P_0c070fec;
case 0x0c070feeu: goto P_0c070fee;
case 0x0c070ff0u: goto P_0c070ff0;
case 0x0c070ff2u: goto P_0c070ff2;
case 0x0c070ff4u: goto P_0c070ff4;
case 0x0c070ff6u: goto P_0c070ff6;
case 0x0c070ff8u: goto P_0c070ff8;
case 0x0c070ffau: goto P_0c070ffa;
case 0x0c070ffcu: goto P_0c070ffc;
case 0x0c070ffeu: goto P_0c070ffe;
case 0x0c071000u: goto P_0c071000;
case 0x0c071002u: goto P_0c071002;
case 0x0c071004u: goto P_0c071004;
case 0x0c071006u: goto P_0c071006;
case 0x0c071008u: goto P_0c071008;
case 0x0c07100au: goto P_0c07100a;
case 0x0c07100cu: goto P_0c07100c;
case 0x0c07100eu: goto P_0c07100e;
case 0x0c071010u: goto P_0c071010;
case 0x0c071012u: goto P_0c071012;
case 0x0c071014u: goto P_0c071014;
case 0x0c071016u: goto P_0c071016;
case 0x0c071018u: goto P_0c071018;
case 0x0c07101au: goto P_0c07101a;
case 0x0c07101cu: goto P_0c07101c;
case 0x0c07101eu: goto P_0c07101e;
case 0x0c071020u: goto P_0c071020;
case 0x0c071022u: goto P_0c071022;
case 0x0c071024u: goto P_0c071024;
case 0x0c071026u: goto P_0c071026;
case 0x0c071028u: goto P_0c071028;
case 0x0c07102au: goto P_0c07102a;
case 0x0c07102cu: goto P_0c07102c;
case 0x0c07102eu: goto P_0c07102e;
case 0x0c071030u: goto P_0c071030;
case 0x0c071032u: goto P_0c071032;
case 0x0c071034u: goto P_0c071034;
case 0x0c071036u: goto P_0c071036;
case 0x0c071038u: goto P_0c071038;
case 0x0c07103au: goto P_0c07103a;
case 0x0c07103cu: goto P_0c07103c;
case 0x0c07103eu: goto P_0c07103e;
case 0x0c071040u: goto P_0c071040;
case 0x0c071042u: goto P_0c071042;
case 0x0c071044u: goto P_0c071044;
case 0x0c071046u: goto P_0c071046;
case 0x0c071048u: goto P_0c071048;
case 0x0c07104au: goto P_0c07104a;
case 0x0c07104cu: goto P_0c07104c;
case 0x0c07104eu: goto P_0c07104e;
case 0x0c071050u: goto P_0c071050;
case 0x0c071052u: goto P_0c071052;
case 0x0c071054u: goto P_0c071054;
case 0x0c071056u: goto P_0c071056;
case 0x0c071058u: goto P_0c071058;
case 0x0c07105au: goto P_0c07105a;
case 0x0c07105cu: goto P_0c07105c;
case 0x0c07105eu: goto P_0c07105e;
case 0x0c071060u: goto P_0c071060;
case 0x0c071062u: goto P_0c071062;
case 0x0c071064u: goto P_0c071064;
case 0x0c071066u: goto P_0c071066;
case 0x0c071068u: goto P_0c071068;
case 0x0c07106au: goto P_0c07106a;
case 0x0c07106cu: goto P_0c07106c;
case 0x0c07106eu: goto P_0c07106e;
case 0x0c074930u: goto P_0c074930;
case 0x0c074932u: goto P_0c074932;
case 0x0c074934u: goto P_0c074934;
case 0x0c074936u: goto P_0c074936;
case 0x0c074938u: goto P_0c074938;
case 0x0c07493au: goto P_0c07493a;
case 0x0c07493cu: goto P_0c07493c;
case 0x0c07493eu: goto P_0c07493e;
case 0x0c074940u: goto P_0c074940;
case 0x0c074942u: goto P_0c074942;
case 0x0c074944u: goto P_0c074944;
case 0x0c074946u: goto P_0c074946;
case 0x0c074948u: goto P_0c074948;
case 0x0c07494au: goto P_0c07494a;
case 0x0c07494cu: goto P_0c07494c;
case 0x0c07494eu: goto P_0c07494e;
case 0x0c074950u: goto P_0c074950;
case 0x0c074952u: goto P_0c074952;
case 0x0c074954u: goto P_0c074954;
case 0x0c074956u: goto P_0c074956;
case 0x0c074958u: goto P_0c074958;
case 0x0c07495au: goto P_0c07495a;
case 0x0c07495cu: goto P_0c07495c;
case 0x0c07495eu: goto P_0c07495e;
case 0x0c074960u: goto P_0c074960;
case 0x0c074962u: goto P_0c074962;
case 0x0c074964u: goto P_0c074964;
case 0x0c074966u: goto P_0c074966;
case 0x0c074968u: goto P_0c074968;
case 0x0c07496au: goto P_0c07496a;
case 0x0c07496cu: goto P_0c07496c;
case 0x0c07496eu: goto P_0c07496e;
case 0x0c074970u: goto P_0c074970;
case 0x0c074972u: goto P_0c074972;
case 0x0c074974u: goto P_0c074974;
case 0x0c074976u: goto P_0c074976;
case 0x0c074978u: goto P_0c074978;
case 0x0c07497au: goto P_0c07497a;
case 0x0c07497cu: goto P_0c07497c;
case 0x0c07497eu: goto P_0c07497e;
case 0x0c074980u: goto P_0c074980;
case 0x0c074982u: goto P_0c074982;
case 0x0c074984u: goto P_0c074984;
case 0x0c074986u: goto P_0c074986;
case 0x0c074988u: goto P_0c074988;
case 0x0c07498au: goto P_0c07498a;
case 0x0c07498cu: goto P_0c07498c;
case 0x0c07498eu: goto P_0c07498e;
case 0x0c074990u: goto P_0c074990;
case 0x0c074992u: goto P_0c074992;
case 0x0c074994u: goto P_0c074994;
case 0x0c074996u: goto P_0c074996;
case 0x0c074998u: goto P_0c074998;
case 0x0c07499au: goto P_0c07499a;
case 0x0c07499cu: goto P_0c07499c;
case 0x0c07499eu: goto P_0c07499e;
case 0x0c0749ccu: goto P_0c0749cc;
case 0x0c0749ceu: goto P_0c0749ce;
case 0x0c0749d0u: goto P_0c0749d0;
case 0x0c0749d2u: goto P_0c0749d2;
case 0x0c0749d4u: goto P_0c0749d4;
case 0x0c0749d6u: goto P_0c0749d6;
case 0x0c0749d8u: goto P_0c0749d8;
case 0x0c0749dau: goto P_0c0749da;
case 0x0c0749dcu: goto P_0c0749dc;
case 0x0c0749deu: goto P_0c0749de;
case 0x0c0749e0u: goto P_0c0749e0;
case 0x0c0749e2u: goto P_0c0749e2;
case 0x0c0749e4u: goto P_0c0749e4;
case 0x0c0749e6u: goto P_0c0749e6;
case 0x0c0749e8u: goto P_0c0749e8;
case 0x0c0749eau: goto P_0c0749ea;
case 0x0c0749ecu: goto P_0c0749ec;
case 0x0c0749eeu: goto P_0c0749ee;
case 0x0c0749f0u: goto P_0c0749f0;
case 0x0c0749f2u: goto P_0c0749f2;
case 0x0c0749f4u: goto P_0c0749f4;
case 0x0c0749f6u: goto P_0c0749f6;
case 0x0c0749f8u: goto P_0c0749f8;
case 0x0c0749fau: goto P_0c0749fa;
case 0x0c0749fcu: goto P_0c0749fc;
case 0x0c0749feu: goto P_0c0749fe;
case 0x0c074a00u: goto P_0c074a00;
case 0x0c074a02u: goto P_0c074a02;
case 0x0c074a04u: goto P_0c074a04;
case 0x0c074a06u: goto P_0c074a06;
case 0x0c074a08u: goto P_0c074a08;
case 0x0c074a0au: goto P_0c074a0a;
case 0x0c074a0cu: goto P_0c074a0c;
case 0x0c074a0eu: goto P_0c074a0e;
case 0x0c074a10u: goto P_0c074a10;
case 0x0c074a12u: goto P_0c074a12;
case 0x0c074a14u: goto P_0c074a14;
case 0x0c074a16u: goto P_0c074a16;
case 0x0c074a18u: goto P_0c074a18;
case 0x0c074a1au: goto P_0c074a1a;
case 0x0c074a1cu: goto P_0c074a1c;
case 0x0c074a1eu: goto P_0c074a1e;
case 0x0c074a20u: goto P_0c074a20;
case 0x0c074a22u: goto P_0c074a22;
case 0x0c074a24u: goto P_0c074a24;
case 0x0c074a26u: goto P_0c074a26;
case 0x0c074a28u: goto P_0c074a28;
case 0x0c074a2au: goto P_0c074a2a;
case 0x0c074a2cu: goto P_0c074a2c;
case 0x0c074a2eu: goto P_0c074a2e;
case 0x0c074a30u: goto P_0c074a30;
case 0x0c074a32u: goto P_0c074a32;
case 0x0c074a34u: goto P_0c074a34;
case 0x0c074a36u: goto P_0c074a36;
case 0x0c074a38u: goto P_0c074a38;
case 0x0c074a52u: goto P_0c074a52;
case 0x0c074a54u: goto P_0c074a54;
case 0x0c074a56u: goto P_0c074a56;
case 0x0c074a58u: goto P_0c074a58;
case 0x0c074a5au: goto P_0c074a5a;
case 0x0c074a5cu: goto P_0c074a5c;
case 0x0c074a5eu: goto P_0c074a5e;
case 0x0c074a60u: goto P_0c074a60;
case 0x0c074a62u: goto P_0c074a62;
case 0x0c074a64u: goto P_0c074a64;
case 0x0c074a66u: goto P_0c074a66;
case 0x0c074a68u: goto P_0c074a68;
case 0x0c074a6au: goto P_0c074a6a;
case 0x0c074a6cu: goto P_0c074a6c;
case 0x0c074a6eu: goto P_0c074a6e;
case 0x0c074a70u: goto P_0c074a70;
case 0x0c074a72u: goto P_0c074a72;
case 0x0c074a74u: goto P_0c074a74;
case 0x0c074a76u: goto P_0c074a76;
case 0x0c074a78u: goto P_0c074a78;
case 0x0c074a7au: goto P_0c074a7a;
case 0x0c074a7cu: goto P_0c074a7c;
case 0x0c074a7eu: goto P_0c074a7e;
case 0x0c074a80u: goto P_0c074a80;
case 0x0c074a82u: goto P_0c074a82;
case 0x0c074a84u: goto P_0c074a84;
case 0x0c074a86u: goto P_0c074a86;
case 0x0c074a88u: goto P_0c074a88;
case 0x0c074a8au: goto P_0c074a8a;
case 0x0c074a8cu: goto P_0c074a8c;
case 0x0c074a8eu: goto P_0c074a8e;
case 0x0c074a90u: goto P_0c074a90;
case 0x0c074a92u: goto P_0c074a92;
case 0x0c074a94u: goto P_0c074a94;
case 0x0c074a96u: goto P_0c074a96;
case 0x0c074a98u: goto P_0c074a98;
case 0x0c074a9au: goto P_0c074a9a;
case 0x0c074a9cu: goto P_0c074a9c;
case 0x0c074a9eu: goto P_0c074a9e;
case 0x0c074aa0u: goto P_0c074aa0;
case 0x0c074aa2u: goto P_0c074aa2;
case 0x0c074aa4u: goto P_0c074aa4;
case 0x0c074aa6u: goto P_0c074aa6;
case 0x0c074aa8u: goto P_0c074aa8;
case 0x0c074aaau: goto P_0c074aaa;
case 0x0c074aacu: goto P_0c074aac;
case 0x0c074aaeu: goto P_0c074aae;
case 0x0c074ab0u: goto P_0c074ab0;
case 0x0c074ab2u: goto P_0c074ab2;
case 0x0c074ab4u: goto P_0c074ab4;
case 0x0c074ab6u: goto P_0c074ab6;
case 0x0c074ae8u: goto P_0c074ae8;
case 0x0c074aeau: goto P_0c074aea;
case 0x0c074aecu: goto P_0c074aec;
case 0x0c074aeeu: goto P_0c074aee;
case 0x0c074af0u: goto P_0c074af0;
case 0x0c074af2u: goto P_0c074af2;
case 0x0c074af4u: goto P_0c074af4;
case 0x0c074af6u: goto P_0c074af6;
case 0x0c074af8u: goto P_0c074af8;
case 0x0c074afau: goto P_0c074afa;
case 0x0c074afcu: goto P_0c074afc;
case 0x0c074afeu: goto P_0c074afe;
case 0x0c074b00u: goto P_0c074b00;
case 0x0c074b02u: goto P_0c074b02;
case 0x0c074b04u: goto P_0c074b04;
case 0x0c074b06u: goto P_0c074b06;
case 0x0c074b08u: goto P_0c074b08;
case 0x0c074b0au: goto P_0c074b0a;
case 0x0c074b0cu: goto P_0c074b0c;
case 0x0c074b0eu: goto P_0c074b0e;
case 0x0c074b10u: goto P_0c074b10;
case 0x0c074b12u: goto P_0c074b12;
case 0x0c074b14u: goto P_0c074b14;
case 0x0c074b16u: goto P_0c074b16;
case 0x0c074b18u: goto P_0c074b18;
case 0x0c074b1au: goto P_0c074b1a;
case 0x0c074b1cu: goto P_0c074b1c;
case 0x0c074b1eu: goto P_0c074b1e;
case 0x0c074b20u: goto P_0c074b20;
case 0x0c074b22u: goto P_0c074b22;
case 0x0c074b24u: goto P_0c074b24;
case 0x0c074b26u: goto P_0c074b26;
case 0x0c074b28u: goto P_0c074b28;
case 0x0c074b2au: goto P_0c074b2a;
case 0x0c074b2cu: goto P_0c074b2c;
case 0x0c074b2eu: goto P_0c074b2e;
case 0x0c074b30u: goto P_0c074b30;
case 0x0c074b32u: goto P_0c074b32;
case 0x0c074b34u: goto P_0c074b34;
case 0x0c074b36u: goto P_0c074b36;
case 0x0c074b38u: goto P_0c074b38;
case 0x0c074b3au: goto P_0c074b3a;
case 0x0c074b3cu: goto P_0c074b3c;
case 0x0c074b3eu: goto P_0c074b3e;
case 0x0c074b40u: goto P_0c074b40;
case 0x0c074b42u: goto P_0c074b42;
case 0x0c074b44u: goto P_0c074b44;
case 0x0c074b46u: goto P_0c074b46;
case 0x0c074b48u: goto P_0c074b48;
case 0x0c074b4au: goto P_0c074b4a;
case 0x0c074b4cu: goto P_0c074b4c;
case 0x0c074b4eu: goto P_0c074b4e;
case 0x0c074b50u: goto P_0c074b50;
case 0x0c074b52u: goto P_0c074b52;
case 0x0c074b54u: goto P_0c074b54;
case 0x0c074b56u: goto P_0c074b56;
case 0x0c074b58u: goto P_0c074b58;
case 0x0c074b5au: goto P_0c074b5a;
case 0x0c074b5cu: goto P_0c074b5c;
case 0x0c074b5eu: goto P_0c074b5e;
case 0x0c074b60u: goto P_0c074b60;
case 0x0c074b62u: goto P_0c074b62;
case 0x0c074b64u: goto P_0c074b64;
case 0x0c074b66u: goto P_0c074b66;
case 0x0c074b68u: goto P_0c074b68;
case 0x0c074b6au: goto P_0c074b6a;
case 0x0c074b6cu: goto P_0c074b6c;
case 0x0c074b6eu: goto P_0c074b6e;
case 0x0c074b70u: goto P_0c074b70;
case 0x0c074b72u: goto P_0c074b72;
case 0x0c074b74u: goto P_0c074b74;
case 0x0c074b76u: goto P_0c074b76;
case 0x0c074b78u: goto P_0c074b78;
case 0x0c074b7au: goto P_0c074b7a;
case 0x0c074b7cu: goto P_0c074b7c;
case 0x0c074b7eu: goto P_0c074b7e;
case 0x0c074b80u: goto P_0c074b80;
case 0x0c074b82u: goto P_0c074b82;
case 0x0c074b84u: goto P_0c074b84;
case 0x0c074b86u: goto P_0c074b86;
case 0x0c074b88u: goto P_0c074b88;
case 0x0c074b8au: goto P_0c074b8a;
case 0x0c074b8cu: goto P_0c074b8c;
case 0x0c074b8eu: goto P_0c074b8e;
case 0x0c074b90u: goto P_0c074b90;
case 0x0c074b92u: goto P_0c074b92;
case 0x0c074b94u: goto P_0c074b94;
case 0x0c074b96u: goto P_0c074b96;
case 0x0c074b98u: goto P_0c074b98;
case 0x0c074b9au: goto P_0c074b9a;
case 0x0c074b9cu: goto P_0c074b9c;
case 0x0c074b9eu: goto P_0c074b9e;
case 0x0c074ba0u: goto P_0c074ba0;
case 0x0c074ba2u: goto P_0c074ba2;
case 0x0c074ba4u: goto P_0c074ba4;
case 0x0c074ba6u: goto P_0c074ba6;
case 0x0c074ba8u: goto P_0c074ba8;
case 0x0c074baau: goto P_0c074baa;
case 0x0c074bacu: goto P_0c074bac;
case 0x0c074baeu: goto P_0c074bae;
case 0x0c074bb0u: goto P_0c074bb0;
case 0x0c074bb2u: goto P_0c074bb2;
case 0x0c074bb4u: goto P_0c074bb4;
case 0x0c074bb6u: goto P_0c074bb6;
case 0x0c074bb8u: goto P_0c074bb8;
case 0x0c074bbau: goto P_0c074bba;
case 0x0c074bbcu: goto P_0c074bbc;
case 0x0c074bbeu: goto P_0c074bbe;
case 0x0c074bc0u: goto P_0c074bc0;
case 0x0c074bc2u: goto P_0c074bc2;
case 0x0c074bc4u: goto P_0c074bc4;
case 0x0c074bc6u: goto P_0c074bc6;
case 0x0c074bc8u: goto P_0c074bc8;
case 0x0c074bcau: goto P_0c074bca;
case 0x0c074bccu: goto P_0c074bcc;
case 0x0c074bf8u: goto P_0c074bf8;
case 0x0c074bfau: goto P_0c074bfa;
case 0x0c074bfcu: goto P_0c074bfc;
case 0x0c074bfeu: goto P_0c074bfe;
case 0x0c074c00u: goto P_0c074c00;
case 0x0c074c02u: goto P_0c074c02;
case 0x0c074c04u: goto P_0c074c04;
case 0x0c074c06u: goto P_0c074c06;
case 0x0c074c08u: goto P_0c074c08;
case 0x0c074c0au: goto P_0c074c0a;
case 0x0c074c0cu: goto P_0c074c0c;
case 0x0c074c0eu: goto P_0c074c0e;
case 0x0c074c10u: goto P_0c074c10;
case 0x0c074c12u: goto P_0c074c12;
case 0x0c074c14u: goto P_0c074c14;
case 0x0c074c16u: goto P_0c074c16;
case 0x0c074c18u: goto P_0c074c18;
case 0x0c074c1au: goto P_0c074c1a;
case 0x0c074c1cu: goto P_0c074c1c;
case 0x0c074c1eu: goto P_0c074c1e;
case 0x0c074c20u: goto P_0c074c20;
case 0x0c074c22u: goto P_0c074c22;
case 0x0c074c24u: goto P_0c074c24;
case 0x0c074c26u: goto P_0c074c26;
case 0x0c074c28u: goto P_0c074c28;
case 0x0c074c2au: goto P_0c074c2a;
case 0x0c074c2cu: goto P_0c074c2c;
case 0x0c074c2eu: goto P_0c074c2e;
case 0x0c074c30u: goto P_0c074c30;
case 0x0c074c32u: goto P_0c074c32;
case 0x0c074c34u: goto P_0c074c34;
case 0x0c074c36u: goto P_0c074c36;
case 0x0c074c38u: goto P_0c074c38;
case 0x0c074c3au: goto P_0c074c3a;
case 0x0c074c3cu: goto P_0c074c3c;
case 0x0c074c3eu: goto P_0c074c3e;
case 0x0c074c40u: goto P_0c074c40;
case 0x0c074c42u: goto P_0c074c42;
case 0x0c074c44u: goto P_0c074c44;
case 0x0c074c46u: goto P_0c074c46;
case 0x0c074c48u: goto P_0c074c48;
case 0x0c074c4au: goto P_0c074c4a;
case 0x0c074c4cu: goto P_0c074c4c;
case 0x0c074c4eu: goto P_0c074c4e;
case 0x0c074c50u: goto P_0c074c50;
case 0x0c074c52u: goto P_0c074c52;
case 0x0c074c54u: goto P_0c074c54;
case 0x0c074c56u: goto P_0c074c56;
case 0x0c074c58u: goto P_0c074c58;
case 0x0c074c5au: goto P_0c074c5a;
case 0x0c074c5cu: goto P_0c074c5c;
case 0x0c074c5eu: goto P_0c074c5e;
case 0x0c074c60u: goto P_0c074c60;
case 0x0c074c62u: goto P_0c074c62;
case 0x0c074c64u: goto P_0c074c64;
case 0x0c074c66u: goto P_0c074c66;
case 0x0c074c68u: goto P_0c074c68;
case 0x0c074c6au: goto P_0c074c6a;
case 0x0c074c6cu: goto P_0c074c6c;
case 0x0c074c6eu: goto P_0c074c6e;
case 0x0c074c70u: goto P_0c074c70;
case 0x0c074c72u: goto P_0c074c72;
case 0x0c074c74u: goto P_0c074c74;
case 0x0c074c76u: goto P_0c074c76;
case 0x0c074c78u: goto P_0c074c78;
case 0x0c074c7au: goto P_0c074c7a;
case 0x0c074c7cu: goto P_0c074c7c;
case 0x0c074c7eu: goto P_0c074c7e;
case 0x0c074c80u: goto P_0c074c80;
case 0x0c074c82u: goto P_0c074c82;
case 0x0c074c84u: goto P_0c074c84;
case 0x0c074c86u: goto P_0c074c86;
case 0x0c074c88u: goto P_0c074c88;
case 0x0c074c8au: goto P_0c074c8a;
case 0x0c074c8cu: goto P_0c074c8c;
case 0x0c074c8eu: goto P_0c074c8e;
case 0x0c074c90u: goto P_0c074c90;
case 0x0c074c92u: goto P_0c074c92;
case 0x0c074c94u: goto P_0c074c94;
case 0x0c074c96u: goto P_0c074c96;
case 0x0c074c98u: goto P_0c074c98;
case 0x0c074c9au: goto P_0c074c9a;
case 0x0c074c9cu: goto P_0c074c9c;
case 0x0c074c9eu: goto P_0c074c9e;
case 0x0c074ca0u: goto P_0c074ca0;
case 0x0c074ca2u: goto P_0c074ca2;
case 0x0c074ca4u: goto P_0c074ca4;
case 0x0c074ca6u: goto P_0c074ca6;
case 0x0c074ca8u: goto P_0c074ca8;
case 0x0c074caau: goto P_0c074caa;
case 0x0c074cacu: goto P_0c074cac;
case 0x0c074caeu: goto P_0c074cae;
case 0x0c074cb0u: goto P_0c074cb0;
case 0x0c074cb2u: goto P_0c074cb2;
case 0x0c074cb4u: goto P_0c074cb4;
case 0x0c074cb6u: goto P_0c074cb6;
case 0x0c074cb8u: goto P_0c074cb8;
case 0x0c074cbau: goto P_0c074cba;
case 0x0c074cbcu: goto P_0c074cbc;
case 0x0c074cd4u: goto P_0c074cd4;
case 0x0c074cd6u: goto P_0c074cd6;
case 0x0c074cd8u: goto P_0c074cd8;
case 0x0c074cdau: goto P_0c074cda;
case 0x0c074cdcu: goto P_0c074cdc;
case 0x0c074cdeu: goto P_0c074cde;
case 0x0c074ce0u: goto P_0c074ce0;
case 0x0c074ce2u: goto P_0c074ce2;
case 0x0c074ce4u: goto P_0c074ce4;
case 0x0c074ce6u: goto P_0c074ce6;
case 0x0c074ce8u: goto P_0c074ce8;
case 0x0c074ceau: goto P_0c074cea;
case 0x0c074cecu: goto P_0c074cec;
case 0x0c074ceeu: goto P_0c074cee;
case 0x0c074cf0u: goto P_0c074cf0;
case 0x0c074cf2u: goto P_0c074cf2;
case 0x0c074cf4u: goto P_0c074cf4;
case 0x0c074cf6u: goto P_0c074cf6;
case 0x0c074cf8u: goto P_0c074cf8;
case 0x0c074cfau: goto P_0c074cfa;
case 0x0c074cfcu: goto P_0c074cfc;
case 0x0c074cfeu: goto P_0c074cfe;
case 0x0c074d00u: goto P_0c074d00;
case 0x0c074d02u: goto P_0c074d02;
case 0x0c074d04u: goto P_0c074d04;
case 0x0c074d06u: goto P_0c074d06;
case 0x0c074d08u: goto P_0c074d08;
case 0x0c074d0au: goto P_0c074d0a;
case 0x0c074d0cu: goto P_0c074d0c;
case 0x0c074d0eu: goto P_0c074d0e;
case 0x0c074d10u: goto P_0c074d10;
case 0x0c074d12u: goto P_0c074d12;
case 0x0c074d14u: goto P_0c074d14;
case 0x0c074d16u: goto P_0c074d16;
case 0x0c074d18u: goto P_0c074d18;
case 0x0c074d1au: goto P_0c074d1a;
case 0x0c074d1cu: goto P_0c074d1c;
case 0x0c074d1eu: goto P_0c074d1e;
case 0x0c074d20u: goto P_0c074d20;
case 0x0c074d22u: goto P_0c074d22;
case 0x0c074d24u: goto P_0c074d24;
case 0x0c074d26u: goto P_0c074d26;
case 0x0c074d28u: goto P_0c074d28;
case 0x0c074d2au: goto P_0c074d2a;
case 0x0c074d2cu: goto P_0c074d2c;
case 0x0c074d2eu: goto P_0c074d2e;
case 0x0c074d30u: goto P_0c074d30;
case 0x0c074d32u: goto P_0c074d32;
case 0x0c074d34u: goto P_0c074d34;
case 0x0c074d36u: goto P_0c074d36;
case 0x0c074d38u: goto P_0c074d38;
case 0x0c074d3au: goto P_0c074d3a;
case 0x0c074d3cu: goto P_0c074d3c;
case 0x0c074d3eu: goto P_0c074d3e;
case 0x0c074d40u: goto P_0c074d40;
case 0x0c074d42u: goto P_0c074d42;
case 0x0c074d44u: goto P_0c074d44;
case 0x0c074d46u: goto P_0c074d46;
case 0x0c074d48u: goto P_0c074d48;
case 0x0c074d4au: goto P_0c074d4a;
case 0x0c074d4cu: goto P_0c074d4c;
case 0x0c074d4eu: goto P_0c074d4e;
case 0x0c074d50u: goto P_0c074d50;
case 0x0c074d52u: goto P_0c074d52;
case 0x0c074d54u: goto P_0c074d54;
case 0x0c074d56u: goto P_0c074d56;
case 0x0c074d58u: goto P_0c074d58;
case 0x0c074d5au: goto P_0c074d5a;
case 0x0c074d5cu: goto P_0c074d5c;
case 0x0c074d5eu: goto P_0c074d5e;
case 0x0c074d60u: goto P_0c074d60;
case 0x0c074d62u: goto P_0c074d62;
case 0x0c074d64u: goto P_0c074d64;
case 0x0c074d66u: goto P_0c074d66;
case 0x0c074d68u: goto P_0c074d68;
case 0x0c074d6au: goto P_0c074d6a;
case 0x0c074d6cu: goto P_0c074d6c;
case 0x0c074d6eu: goto P_0c074d6e;
case 0x0c074d70u: goto P_0c074d70;
case 0x0c074d72u: goto P_0c074d72;
case 0x0c074d74u: goto P_0c074d74;
case 0x0c074d76u: goto P_0c074d76;
case 0x0c074d78u: goto P_0c074d78;
case 0x0c074d7au: goto P_0c074d7a;
case 0x0c074d7cu: goto P_0c074d7c;
case 0x0c074d7eu: goto P_0c074d7e;
case 0x0c074d80u: goto P_0c074d80;
case 0x0c074d82u: goto P_0c074d82;
case 0x0c074d84u: goto P_0c074d84;
case 0x0c074d86u: goto P_0c074d86;
case 0x0c074d88u: goto P_0c074d88;
case 0x0c074d8au: goto P_0c074d8a;
case 0x0c074d8cu: goto P_0c074d8c;
case 0x0c074d8eu: goto P_0c074d8e;
case 0x0c074d90u: goto P_0c074d90;
case 0x0c074db0u: goto P_0c074db0;
case 0x0c074db2u: goto P_0c074db2;
case 0x0c074db4u: goto P_0c074db4;
case 0x0c074db6u: goto P_0c074db6;
case 0x0c074db8u: goto P_0c074db8;
case 0x0c074dbau: goto P_0c074dba;
case 0x0c074dbcu: goto P_0c074dbc;
case 0x0c074dbeu: goto P_0c074dbe;
case 0x0c074dc0u: goto P_0c074dc0;
case 0x0c074dc2u: goto P_0c074dc2;
case 0x0c074dc4u: goto P_0c074dc4;
case 0x0c074dc6u: goto P_0c074dc6;
case 0x0c074dc8u: goto P_0c074dc8;
case 0x0c074dcau: goto P_0c074dca;
case 0x0c074dccu: goto P_0c074dcc;
case 0x0c074dceu: goto P_0c074dce;
case 0x0c074dd0u: goto P_0c074dd0;
case 0x0c074dd2u: goto P_0c074dd2;
case 0x0c074dd4u: goto P_0c074dd4;
case 0x0c074dd6u: goto P_0c074dd6;
case 0x0c074dd8u: goto P_0c074dd8;
case 0x0c074ddau: goto P_0c074dda;
case 0x0c074ddcu: goto P_0c074ddc;
case 0x0c074ddeu: goto P_0c074dde;
case 0x0c074de0u: goto P_0c074de0;
case 0x0c074de2u: goto P_0c074de2;
case 0x0c074de4u: goto P_0c074de4;
case 0x0c074de6u: goto P_0c074de6;
case 0x0c074de8u: goto P_0c074de8;
case 0x0c074deau: goto P_0c074dea;
case 0x0c074decu: goto P_0c074dec;
case 0x0c074deeu: goto P_0c074dee;
case 0x0c074df0u: goto P_0c074df0;
case 0x0c074df2u: goto P_0c074df2;
case 0x0c074df4u: goto P_0c074df4;
case 0x0c074df6u: goto P_0c074df6;
case 0x0c074df8u: goto P_0c074df8;
case 0x0c074dfau: goto P_0c074dfa;
case 0x0c074dfcu: goto P_0c074dfc;
case 0x0c074dfeu: goto P_0c074dfe;
case 0x0c074e00u: goto P_0c074e00;
case 0x0c074e02u: goto P_0c074e02;
case 0x0c074e04u: goto P_0c074e04;
case 0x0c074e06u: goto P_0c074e06;
case 0x0c074e08u: goto P_0c074e08;
case 0x0c074e0au: goto P_0c074e0a;
case 0x0c074e0cu: goto P_0c074e0c;
case 0x0c074e0eu: goto P_0c074e0e;
case 0x0c074e10u: goto P_0c074e10;
case 0x0c074e12u: goto P_0c074e12;
case 0x0c074e14u: goto P_0c074e14;
case 0x0c074e16u: goto P_0c074e16;
case 0x0c074e18u: goto P_0c074e18;
case 0x0c074e1au: goto P_0c074e1a;
case 0x0c09381eu: goto P_0c09381e;
case 0x0c093820u: goto P_0c093820;
case 0x0c093822u: goto P_0c093822;
case 0x0c093824u: goto P_0c093824;
case 0x0c093826u: goto P_0c093826;
case 0x0c093828u: goto P_0c093828;
case 0x0c09571cu: goto P_0c09571c;
case 0x0c09571eu: goto P_0c09571e;
case 0x0c095720u: goto P_0c095720;
case 0x0c095722u: goto P_0c095722;
case 0x0c0a2b98u: goto P_0c0a2b98;
case 0x0c0a2b9au: goto P_0c0a2b9a;
case 0x0c0a2b9cu: goto P_0c0a2b9c;
case 0x0c0a2b9eu: goto P_0c0a2b9e;
case 0x0c0a2ba0u: goto P_0c0a2ba0;
case 0x0c0a2ba2u: goto P_0c0a2ba2;
case 0x0c0a2ba4u: goto P_0c0a2ba4;
case 0x0c0a2ba6u: goto P_0c0a2ba6;
case 0x0c0a2ba8u: goto P_0c0a2ba8;
case 0x0c0a2baau: goto P_0c0a2baa;
case 0x0c0a2bacu: goto P_0c0a2bac;
case 0x0c0a2baeu: goto P_0c0a2bae;
case 0x0c0a2bb0u: goto P_0c0a2bb0;
case 0x0c0a2bb2u: goto P_0c0a2bb2;
case 0x0c0a2bb4u: goto P_0c0a2bb4;
case 0x0c0a2bb6u: goto P_0c0a2bb6;
case 0x0c0a2bb8u: goto P_0c0a2bb8;
case 0x0c0a2bbau: goto P_0c0a2bba;
case 0x0c0a2bbcu: goto P_0c0a2bbc;
case 0x0c0a2bbeu: goto P_0c0a2bbe;
case 0x0c0a2bc0u: goto P_0c0a2bc0;
case 0x0c0a2bc2u: goto P_0c0a2bc2;
case 0x0c0a2bc4u: goto P_0c0a2bc4;
case 0x0c0a2bc6u: goto P_0c0a2bc6;
case 0x0c0a2bc8u: goto P_0c0a2bc8;
case 0x0c0a2bcau: goto P_0c0a2bca;
case 0x0c0a2bccu: goto P_0c0a2bcc;
case 0x0c0a2bceu: goto P_0c0a2bce;
case 0x0c0a2bd0u: goto P_0c0a2bd0;
case 0x0c0a2bd2u: goto P_0c0a2bd2;
case 0x0c0a2bd4u: goto P_0c0a2bd4;
case 0x0c0a2bd6u: goto P_0c0a2bd6;
case 0x0c0a2bd8u: goto P_0c0a2bd8;
case 0x0c0a2bdau: goto P_0c0a2bda;
case 0x0c0a2bdcu: goto P_0c0a2bdc;
case 0x0c0a2bdeu: goto P_0c0a2bde;
case 0x0c0a2be0u: goto P_0c0a2be0;
case 0x0c0a2be2u: goto P_0c0a2be2;
case 0x0c0a2be4u: goto P_0c0a2be4;
case 0x0c0a2be6u: goto P_0c0a2be6;
case 0x0c0a2be8u: goto P_0c0a2be8;
case 0x0c0a2beau: goto P_0c0a2bea;
case 0x0c0a2becu: goto P_0c0a2bec;
case 0x0c0a2beeu: goto P_0c0a2bee;
case 0x0c0a2bf0u: goto P_0c0a2bf0;
case 0x0c0a2bf2u: goto P_0c0a2bf2;
case 0x0c0a2bf4u: goto P_0c0a2bf4;
case 0x0c0a2bf6u: goto P_0c0a2bf6;
case 0x0c0a2bf8u: goto P_0c0a2bf8;
case 0x0c0a2bfau: goto P_0c0a2bfa;
case 0x0c0a2bfcu: goto P_0c0a2bfc;
case 0x0c0a2bfeu: goto P_0c0a2bfe;
case 0x0c0a2c00u: goto P_0c0a2c00;
case 0x0c0a2c02u: goto P_0c0a2c02;
case 0x0c0a2c04u: goto P_0c0a2c04;
case 0x0c0a2c06u: goto P_0c0a2c06;
case 0x0c0a2c08u: goto P_0c0a2c08;
case 0x0c0a2c0au: goto P_0c0a2c0a;
case 0x0c0a2c0cu: goto P_0c0a2c0c;
case 0x0c0a2c0eu: goto P_0c0a2c0e;
case 0x0c0a2c10u: goto P_0c0a2c10;
case 0x0c0a2c12u: goto P_0c0a2c12;
case 0x0c0a2c14u: goto P_0c0a2c14;
case 0x0c0a2c16u: goto P_0c0a2c16;
case 0x0c0a2c18u: goto P_0c0a2c18;
case 0x0c0a2c1au: goto P_0c0a2c1a;
case 0x0c0a2c1cu: goto P_0c0a2c1c;
case 0x0c0a2c1eu: goto P_0c0a2c1e;
case 0x0c0a2c20u: goto P_0c0a2c20;
case 0x0c0a2c22u: goto P_0c0a2c22;
case 0x0c0a2c24u: goto P_0c0a2c24;
case 0x0c0a2c26u: goto P_0c0a2c26;
case 0x0c0a2c28u: goto P_0c0a2c28;
case 0x0c0a2c2au: goto P_0c0a2c2a;
case 0x0c0a2c2cu: goto P_0c0a2c2c;
case 0x0c0a2c2eu: goto P_0c0a2c2e;
case 0x0c0a2c30u: goto P_0c0a2c30;
case 0x0c0a2c32u: goto P_0c0a2c32;
case 0x0c0a2c34u: goto P_0c0a2c34;
case 0x0c0c7648u: goto P_0c0c7648;
case 0x0c0c764au: goto P_0c0c764a;
case 0x0c0c764cu: goto P_0c0c764c;
case 0x0c0c764eu: goto P_0c0c764e;
case 0x0c0c7650u: goto P_0c0c7650;
case 0x0c0c7652u: goto P_0c0c7652;
case 0x0c0c7654u: goto P_0c0c7654;
case 0x0c0c7656u: goto P_0c0c7656;
case 0x0c0c7658u: goto P_0c0c7658;
case 0x0c0c765au: goto P_0c0c765a;
case 0x0c0c765cu: goto P_0c0c765c;
case 0x0c0c765eu: goto P_0c0c765e;
case 0x0c0c7660u: goto P_0c0c7660;
case 0x0c0c7662u: goto P_0c0c7662;
case 0x0c0c7664u: goto P_0c0c7664;
case 0x0c0c7666u: goto P_0c0c7666;
case 0x0c0c7668u: goto P_0c0c7668;
case 0x0c0c766au: goto P_0c0c766a;
case 0x0c0c766cu: goto P_0c0c766c;
case 0x0c0c766eu: goto P_0c0c766e;
case 0x0c0c7670u: goto P_0c0c7670;
case 0x0c0c7672u: goto P_0c0c7672;
case 0x0c0c7674u: goto P_0c0c7674;
case 0x0c0c7676u: goto P_0c0c7676;
case 0x0c0c7678u: goto P_0c0c7678;
case 0x0c0c767au: goto P_0c0c767a;
case 0x0c0c767cu: goto P_0c0c767c;
case 0x0c0c767eu: goto P_0c0c767e;
case 0x0c0c7680u: goto P_0c0c7680;
case 0x0c0c7682u: goto P_0c0c7682;
case 0x0c0c7684u: goto P_0c0c7684;
case 0x0c0c7686u: goto P_0c0c7686;
case 0x0c0c7688u: goto P_0c0c7688;
case 0x0c0c768au: goto P_0c0c768a;
case 0x0c0c768cu: goto P_0c0c768c;
case 0x0c0c768eu: goto P_0c0c768e;
case 0x0c0c7690u: goto P_0c0c7690;
case 0x0c0c7692u: goto P_0c0c7692;
case 0x0c0c7694u: goto P_0c0c7694;
case 0x0c0c7696u: goto P_0c0c7696;
case 0x0c0c7698u: goto P_0c0c7698;
case 0x0c0c769au: goto P_0c0c769a;
case 0x0c0c769cu: goto P_0c0c769c;
case 0x0c0c769eu: goto P_0c0c769e;
case 0x0c0c76a0u: goto P_0c0c76a0;
case 0x0c0c76a2u: goto P_0c0c76a2;
case 0x0c0c76a4u: goto P_0c0c76a4;
case 0x0c0c76a6u: goto P_0c0c76a6;
case 0x0c0c76a8u: goto P_0c0c76a8;
case 0x0c0c76aau: goto P_0c0c76aa;
case 0x0c0c76acu: goto P_0c0c76ac;
case 0x0c0c76aeu: goto P_0c0c76ae;
case 0x0c0c76b0u: goto P_0c0c76b0;
case 0x0c0c76b2u: goto P_0c0c76b2;
case 0x0c0c76b4u: goto P_0c0c76b4;
case 0x0c0c76b6u: goto P_0c0c76b6;
case 0x0c0c76b8u: goto P_0c0c76b8;
case 0x0c0c76bau: goto P_0c0c76ba;
case 0x0c0c76bcu: goto P_0c0c76bc;
case 0x0c0c76beu: goto P_0c0c76be;
default: return vf3_matrix_family(target,s,ram);
}
P_0c038b40: /* original 2fe6, guest PC 0x0c038b40 */
if(!s->budget--) { s->failed_pc=0x0c038b40u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c038b42;
P_0c038b42: /* original 2fd6, guest PC 0x0c038b42 */
if(!s->budget--) { s->failed_pc=0x0c038b42u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c038b44;
P_0c038b44: /* original ed00, guest PC 0x0c038b44 */
if(!s->budget--) { s->failed_pc=0x0c038b44u; return 0; }
r[13]=0x00000000u;
goto P_0c038b46;
P_0c038b46: /* original 2fc6, guest PC 0x0c038b46 */
if(!s->budget--) { s->failed_pc=0x0c038b46u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c038b48;
P_0c038b48: /* original 2fb6, guest PC 0x0c038b48 */
if(!s->budget--) { s->failed_pc=0x0c038b48u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c038b4a;
P_0c038b4a: /* original 2fa6, guest PC 0x0c038b4a */
if(!s->budget--) { s->failed_pc=0x0c038b4au; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c038b4c;
P_0c038b4c: /* original d32f, guest PC 0x0c038b4c */
if(!s->budget--) { s->failed_pc=0x0c038b4cu; return 0; }
r[3]=read(ram,0x0c038c0cu,4);
goto P_0c038b4e;
P_0c038b4e: /* original 4f22, guest PC 0x0c038b4e */
if(!s->budget--) { s->failed_pc=0x0c038b4eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038b50;
P_0c038b50: /* original db31, guest PC 0x0c038b50 */
if(!s->budget--) { s->failed_pc=0x0c038b50u; return 0; }
r[11]=read(ram,0x0c038c18u,4);
goto P_0c038b52;
P_0c038b52: /* original da30, guest PC 0x0c038b52 */
if(!s->budget--) { s->failed_pc=0x0c038b52u; return 0; }
r[10]=read(ram,0x0c038c14u,4);
goto P_0c038b54;
P_0c038b54: /* original 6e32, guest PC 0x0c038b54 */
if(!s->budget--) { s->failed_pc=0x0c038b54u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c038b56;
P_0c038b56: /* original a00d, guest PC 0x0c038b56 */
if(!s->budget--) { s->failed_pc=0x0c038b56u; return 0; }
r[12]=r[13];
goto P_0c038b74;
P_0c038b58: /* original 6cd3, guest PC 0x0c038b58 */
if(!s->budget--) { s->failed_pc=0x0c038b58u; return 0; }
r[12]=r[13];
return vf3_matrix_family(0x0c038b5au,s,ram);
P_0c038b60: /* original 53eb, guest PC 0x0c038b60 */
if(!s->budget--) { s->failed_pc=0x0c038b60u; return 0; }
r[3]=read(ram,r[14]+44,4);
goto P_0c038b62;
P_0c038b62: /* original 2338, guest PC 0x0c038b62 */
if(!s->budget--) { s->failed_pc=0x0c038b62u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c038b64;
P_0c038b64: /* original 8904, guest PC 0x0c038b64 */
if(!s->budget--) { s->failed_pc=0x0c038b64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c038b70; }
goto P_0c038b66;
P_0c038b66: /* original 53ea, guest PC 0x0c038b66 */
if(!s->budget--) { s->failed_pc=0x0c038b66u; return 0; }
r[3]=read(ram,r[14]+40,4);
goto P_0c038b68;
P_0c038b68: /* original 2338, guest PC 0x0c038b68 */
if(!s->budget--) { s->failed_pc=0x0c038b68u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c038b6a;
P_0c038b6a: /* original 8b01, guest PC 0x0c038b6a */
if(!s->budget--) { s->failed_pc=0x0c038b6au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038b70; }
goto P_0c038b6c;
P_0c038b6c: /* original 4a0b, guest PC 0x0c038b6c */
if(!s->budget--) { s->failed_pc=0x0c038b6cu; return 0; }
target=r[10];
r[16]=0x0c038b70u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c038b70u) { target=s->pc; goto dispatch; }
goto P_0c038b70;
P_0c038b6e: /* original 64e3, guest PC 0x0c038b6e */
if(!s->budget--) { s->failed_pc=0x0c038b6eu; return 0; }
r[4]=r[14];
goto P_0c038b70;
P_0c038b70: /* original 7c01, guest PC 0x0c038b70 */
if(!s->budget--) { s->failed_pc=0x0c038b70u; return 0; }
r[12]+=0x00000001u;
goto P_0c038b72;
P_0c038b72: /* original 7e3c, guest PC 0x0c038b72 */
if(!s->budget--) { s->failed_pc=0x0c038b72u; return 0; }
r[14]+=0x0000003cu;
goto P_0c038b74;
P_0c038b74: /* original 63b2, guest PC 0x0c038b74 */
if(!s->budget--) { s->failed_pc=0x0c038b74u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c038b76;
P_0c038b76: /* original 3c33, guest PC 0x0c038b76 */
if(!s->budget--) { s->failed_pc=0x0c038b76u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[3])!=0);
goto P_0c038b78;
P_0c038b78: /* original 8bf2, guest PC 0x0c038b78 */
if(!s->budget--) { s->failed_pc=0x0c038b78u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038b60; }
goto P_0c038b7a;
P_0c038b7a: /* original d124, guest PC 0x0c038b7a */
if(!s->budget--) { s->failed_pc=0x0c038b7au; return 0; }
r[1]=read(ram,0x0c038c0cu,4);
goto P_0c038b7c;
P_0c038b7c: /* original e5ff, guest PC 0x0c038b7c */
if(!s->budget--) { s->failed_pc=0x0c038b7cu; return 0; }
r[5]=0xffffffffu;
goto P_0c038b7e;
P_0c038b7e: /* original 6412, guest PC 0x0c038b7e */
if(!s->budget--) { s->failed_pc=0x0c038b7eu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c038b80;
P_0c038b80: /* original a00b, guest PC 0x0c038b80 */
if(!s->budget--) { s->failed_pc=0x0c038b80u; return 0; }
r[6]=r[13];
goto P_0c038b9a;
P_0c038b82: /* original 66d3, guest PC 0x0c038b82 */
if(!s->budget--) { s->failed_pc=0x0c038b82u; return 0; }
r[6]=r[13];
return vf3_matrix_family(0x0c038b84u,s,ram);
P_0c038b90: /* original 145a, guest PC 0x0c038b90 */
if(!s->budget--) { s->failed_pc=0x0c038b90u; return 0; }
write(ram,r[4]+40,r[5],4);
goto P_0c038b92;
P_0c038b92: /* original 7601, guest PC 0x0c038b92 */
if(!s->budget--) { s->failed_pc=0x0c038b92u; return 0; }
r[6]+=0x00000001u;
goto P_0c038b94;
P_0c038b94: /* original 14db, guest PC 0x0c038b94 */
if(!s->budget--) { s->failed_pc=0x0c038b94u; return 0; }
write(ram,r[4]+44,r[13],4);
goto P_0c038b96;
P_0c038b96: /* original 145e, guest PC 0x0c038b96 */
if(!s->budget--) { s->failed_pc=0x0c038b96u; return 0; }
write(ram,r[4]+56,r[5],4);
goto P_0c038b98;
P_0c038b98: /* original 743c, guest PC 0x0c038b98 */
if(!s->budget--) { s->failed_pc=0x0c038b98u; return 0; }
r[4]+=0x0000003cu;
goto P_0c038b9a;
P_0c038b9a: /* original 62b2, guest PC 0x0c038b9a */
if(!s->budget--) { s->failed_pc=0x0c038b9au; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c038b9c;
P_0c038b9c: /* original 3623, guest PC 0x0c038b9c */
if(!s->budget--) { s->failed_pc=0x0c038b9cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[2])!=0);
goto P_0c038b9e;
P_0c038b9e: /* original 8bf7, guest PC 0x0c038b9e */
if(!s->budget--) { s->failed_pc=0x0c038b9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c038b90; }
goto P_0c038ba0;
P_0c038ba0: /* original 4f26, guest PC 0x0c038ba0 */
if(!s->budget--) { s->failed_pc=0x0c038ba0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038ba2;
P_0c038ba2: /* original d11e, guest PC 0x0c038ba2 */
if(!s->budget--) { s->failed_pc=0x0c038ba2u; return 0; }
r[1]=read(ram,0x0c038c1cu,4);
goto P_0c038ba4;
P_0c038ba4: /* original 21d2, guest PC 0x0c038ba4 */
if(!s->budget--) { s->failed_pc=0x0c038ba4u; return 0; }
write(ram,r[1],r[13],4);
goto P_0c038ba6;
P_0c038ba6: /* original d31e, guest PC 0x0c038ba6 */
if(!s->budget--) { s->failed_pc=0x0c038ba6u; return 0; }
r[3]=read(ram,0x0c038c20u,4);
goto P_0c038ba8;
P_0c038ba8: /* original 23d2, guest PC 0x0c038ba8 */
if(!s->budget--) { s->failed_pc=0x0c038ba8u; return 0; }
write(ram,r[3],r[13],4);
goto P_0c038baa;
P_0c038baa: /* original 6af6, guest PC 0x0c038baa */
if(!s->budget--) { s->failed_pc=0x0c038baau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c038bac;
P_0c038bac: /* original 6bf6, guest PC 0x0c038bac */
if(!s->budget--) { s->failed_pc=0x0c038bacu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c038bae;
P_0c038bae: /* original 6cf6, guest PC 0x0c038bae */
if(!s->budget--) { s->failed_pc=0x0c038baeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c038bb0;
P_0c038bb0: /* original 6df6, guest PC 0x0c038bb0 */
if(!s->budget--) { s->failed_pc=0x0c038bb0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c038bb2;
P_0c038bb2: /* original 000b, guest PC 0x0c038bb2 */
if(!s->budget--) { s->failed_pc=0x0c038bb2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c038bb4: /* original 6ef6, guest PC 0x0c038bb4 */
if(!s->budget--) { s->failed_pc=0x0c038bb4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c038bb6u,s,ram);
P_0c03b684: /* original f40b, guest PC 0x0c03b684 */
if(!s->budget--) { s->failed_pc=0x0c03b684u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c03b686;
P_0c03b686: /* original fbfd, guest PC 0x0c03b686 */
if(!s->budget--) { s->failed_pc=0x0c03b686u; return 0; }
vf3_matrix_swap(s);
goto P_0c03b688;
P_0c03b688: /* original 6043, guest PC 0x0c03b688 */
if(!s->budget--) { s->failed_pc=0x0c03b688u; return 0; }
r[0]=r[4];
goto P_0c03b68a;
P_0c03b68a: /* original 0009, guest PC 0x0c03b68a */
if(!s->budget--) { s->failed_pc=0x0c03b68au; return 0; }
goto P_0c03b68c;
P_0c03b68c: /* original 000b, guest PC 0x0c03b68c */
if(!s->budget--) { s->failed_pc=0x0c03b68cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03b68e: /* original 0009, guest PC 0x0c03b68e */
if(!s->budget--) { s->failed_pc=0x0c03b68eu; return 0; }
return vf3_matrix_family(0x0c03b690u,s,ram);
P_0c054524: /* original f40b, guest PC 0x0c054524 */
if(!s->budget--) { s->failed_pc=0x0c054524u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c054526;
P_0c054526: /* original 74e0, guest PC 0x0c054526 */
if(!s->budget--) { s->failed_pc=0x0c054526u; return 0; }
r[4]+=0xffffffe0u;
goto P_0c054528;
P_0c054528: /* original 6442, guest PC 0x0c054528 */
if(!s->budget--) { s->failed_pc=0x0c054528u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05452a;
P_0c05452a: /* original 000b, guest PC 0x0c05452a */
if(!s->budget--) { s->failed_pc=0x0c05452au; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05452c: /* original e000, guest PC 0x0c05452c */
if(!s->budget--) { s->failed_pc=0x0c05452cu; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c05452eu,s,ram);
P_0c066fd8: /* original 2fe6, guest PC 0x0c066fd8 */
if(!s->budget--) { s->failed_pc=0x0c066fd8u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c066fda;
P_0c066fda: /* original 6e43, guest PC 0x0c066fda */
if(!s->budget--) { s->failed_pc=0x0c066fdau; return 0; }
r[14]=r[4];
goto P_0c066fdc;
P_0c066fdc: /* original 2fd6, guest PC 0x0c066fdc */
if(!s->budget--) { s->failed_pc=0x0c066fdcu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c066fde;
P_0c066fde: /* original 2fc6, guest PC 0x0c066fde */
if(!s->budget--) { s->failed_pc=0x0c066fdeu; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c066fe0;
P_0c066fe0: /* original 6c53, guest PC 0x0c066fe0 */
if(!s->budget--) { s->failed_pc=0x0c066fe0u; return 0; }
r[12]=r[5];
goto P_0c066fe2;
P_0c066fe2: /* original 2fb6, guest PC 0x0c066fe2 */
if(!s->budget--) { s->failed_pc=0x0c066fe2u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c066fe4;
P_0c066fe4: /* original 6b63, guest PC 0x0c066fe4 */
if(!s->budget--) { s->failed_pc=0x0c066fe4u; return 0; }
r[11]=r[6];
goto P_0c066fe6;
P_0c066fe6: /* original 4f22, guest PC 0x0c066fe6 */
if(!s->budget--) { s->failed_pc=0x0c066fe6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c066fe8;
P_0c066fe8: /* original 7ffc, guest PC 0x0c066fe8 */
if(!s->budget--) { s->failed_pc=0x0c066fe8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c066fea;
P_0c066fea: /* original 2f72, guest PC 0x0c066fea */
if(!s->budget--) { s->failed_pc=0x0c066feau; return 0; }
write(ram,r[15],r[7],4);
goto P_0c066fec;
P_0c066fec: /* original 64c2, guest PC 0x0c066fec */
if(!s->budget--) { s->failed_pc=0x0c066fecu; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c066fee;
P_0c066fee: /* original 9069, guest PC 0x0c066fee */
if(!s->budget--) { s->failed_pc=0x0c066feeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670c4u,2);
goto P_0c066ff0;
P_0c066ff0: /* original 24b9, guest PC 0x0c066ff0 */
if(!s->budget--) { s->failed_pc=0x0c066ff0u; return 0; }
r[4]&=r[11];
goto P_0c066ff2;
P_0c066ff2: /* original 2448, guest PC 0x0c066ff2 */
if(!s->budget--) { s->failed_pc=0x0c066ff2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c066ff4;
P_0c066ff4: /* original 8d0e, guest PC 0x0c066ff4 */
if(!s->budget--) { s->failed_pc=0x0c066ff4u; return 0; }
cond=r[17]&1u;
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(cond) { goto P_0c067014; }
goto P_0c066ff8;
P_0c066ff6: /* original 0ded, guest PC 0x0c066ff6 */
if(!s->budget--) { s->failed_pc=0x0c066ff6u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c066ff8;
P_0c066ff8: /* original 62c2, guest PC 0x0c066ff8 */
if(!s->budget--) { s->failed_pc=0x0c066ff8u; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c066ffa;
P_0c066ffa: /* original 63b7, guest PC 0x0c066ffa */
if(!s->budget--) { s->failed_pc=0x0c066ffau; return 0; }
r[3]=~r[11];
goto P_0c066ffc;
P_0c066ffc: /* original 2239, guest PC 0x0c066ffc */
if(!s->budget--) { s->failed_pc=0x0c066ffcu; return 0; }
r[2]&=r[3];
goto P_0c066ffe;
P_0c066ffe: /* original 2c22, guest PC 0x0c066ffe */
if(!s->budget--) { s->failed_pc=0x0c066ffeu; return 0; }
write(ram,r[12],r[2],4);
goto P_0c067000;
P_0c067000: /* original 9061, guest PC 0x0c067000 */
if(!s->budget--) { s->failed_pc=0x0c067000u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670c6u,2);
goto P_0c067002;
P_0c067002: /* original bfc1, guest PC 0x0c067002 */
if(!s->budget--) { s->failed_pc=0x0c067002u; return 0; }
target=0x0c066f88u; r[16]=0x0c067006u;
r[4]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c067006u) { target=s->pc; goto dispatch; }
goto P_0c067006;
P_0c067004: /* original 04ee, guest PC 0x0c067004 */
if(!s->budget--) { s->failed_pc=0x0c067004u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c067006;
P_0c067006: /* original 6403, guest PC 0x0c067006 */
if(!s->budget--) { s->failed_pc=0x0c067006u; return 0; }
r[4]=r[0];
goto P_0c067008;
P_0c067008: /* original 2448, guest PC 0x0c067008 */
if(!s->budget--) { s->failed_pc=0x0c067008u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c06700a;
P_0c06700a: /* original 8b03, guest PC 0x0c06700a */
if(!s->budget--) { s->failed_pc=0x0c06700au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c067014; }
goto P_0c06700c;
P_0c06700c: /* original 62e3, guest PC 0x0c06700c */
if(!s->budget--) { s->failed_pc=0x0c06700cu; return 0; }
r[2]=r[14];
goto P_0c06700e;
P_0c06700e: /* original 32dc, guest PC 0x0c06700e */
if(!s->budget--) { s->failed_pc=0x0c06700eu; return 0; }
r[2]+=r[13];
goto P_0c067010;
P_0c067010: /* original 6d21, guest PC 0x0c067010 */
if(!s->budget--) { s->failed_pc=0x0c067010u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[13]=tmp;
goto P_0c067012;
P_0c067012: /* original 6ddd, guest PC 0x0c067012 */
if(!s->budget--) { s->failed_pc=0x0c067012u; return 0; }
r[13]=r[13]&65535u;
goto P_0c067014;
P_0c067014: /* original 63f2, guest PC 0x0c067014 */
if(!s->budget--) { s->failed_pc=0x0c067014u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c067016;
P_0c067016: /* original 9055, guest PC 0x0c067016 */
if(!s->budget--) { s->failed_pc=0x0c067016u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670c4u,2);
goto P_0c067018;
P_0c067018: /* original 3d38, guest PC 0x0c067018 */
if(!s->budget--) { s->failed_pc=0x0c067018u; return 0; }
r[13]-=r[3];
goto P_0c06701a;
P_0c06701a: /* original 4d15, guest PC 0x0c06701a */
if(!s->budget--) { s->failed_pc=0x0c06701au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c06701c;
P_0c06701c: /* original 8d18, guest PC 0x0c06701c */
if(!s->budget--) { s->failed_pc=0x0c06701cu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[13],2);
if(cond) { goto P_0c067050; }
goto P_0c067020;
P_0c06701e: /* original 0ed5, guest PC 0x0c06701e */
if(!s->budget--) { s->failed_pc=0x0c06701eu; return 0; }
write(ram,r[14]+r[0],r[13],2);
goto P_0c067020;
P_0c067020: /* original 9052, guest PC 0x0c067020 */
if(!s->budget--) { s->failed_pc=0x0c067020u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670c8u,2);
goto P_0c067022;
P_0c067022: /* original 04ee, guest PC 0x0c067022 */
if(!s->budget--) { s->failed_pc=0x0c067022u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c067024;
P_0c067024: /* original 7404, guest PC 0x0c067024 */
if(!s->budget--) { s->failed_pc=0x0c067024u; return 0; }
r[4]+=0x00000004u;
goto P_0c067026;
P_0c067026: /* original 6546, guest PC 0x0c067026 */
if(!s->budget--) { s->failed_pc=0x0c067026u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[5]=tmp;
goto P_0c067028;
P_0c067028: /* original 6746, guest PC 0x0c067028 */
if(!s->budget--) { s->failed_pc=0x0c067028u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[7]=tmp;
goto P_0c06702a;
P_0c06702a: /* original 2558, guest PC 0x0c06702a */
if(!s->budget--) { s->failed_pc=0x0c06702au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06702c;
P_0c06702c: /* original 6642, guest PC 0x0c06702c */
if(!s->budget--) { s->failed_pc=0x0c06702cu; return 0; }
tmp=read(ram,r[4],4);
r[6]=tmp;
goto P_0c06702e;
P_0c06702e: /* original 8f07, guest PC 0x0c06702e */
if(!s->budget--) { s->failed_pc=0x0c06702eu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],4);
if(!cond) { goto P_0c067040; }
goto P_0c067032;
P_0c067030: /* original 0e46, guest PC 0x0c067030 */
if(!s->budget--) { s->failed_pc=0x0c067030u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c067032;
P_0c067032: /* original 9047, guest PC 0x0c067032 */
if(!s->budget--) { s->failed_pc=0x0c067032u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670c4u,2);
goto P_0c067034;
P_0c067034: /* original 0e75, guest PC 0x0c067034 */
if(!s->budget--) { s->failed_pc=0x0c067034u; return 0; }
write(ram,r[14]+r[0],r[7],2);
goto P_0c067036;
P_0c067036: /* original 7008, guest PC 0x0c067036 */
if(!s->budget--) { s->failed_pc=0x0c067036u; return 0; }
r[0]+=0x00000008u;
goto P_0c067038;
P_0c067038: /* original 0e65, guest PC 0x0c067038 */
if(!s->budget--) { s->failed_pc=0x0c067038u; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c06703a;
P_0c06703a: /* original d326, guest PC 0x0c06703a */
if(!s->budget--) { s->failed_pc=0x0c06703au; return 0; }
r[3]=read(ram,0x0c0670d4u,4);
goto P_0c06703c;
P_0c06703c: /* original a008, guest PC 0x0c06703c */
if(!s->budget--) { s->failed_pc=0x0c06703cu; return 0; }
write(ram,r[14]+48,r[3],4);
goto P_0c067050;
P_0c06703e: /* original 1e3c, guest PC 0x0c06703e */
if(!s->budget--) { s->failed_pc=0x0c06703eu; return 0; }
write(ram,r[14]+48,r[3],4);
goto P_0c067040;
P_0c067040: /* original 61c2, guest PC 0x0c067040 */
if(!s->budget--) { s->failed_pc=0x0c067040u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c067042;
P_0c067042: /* original 21bb, guest PC 0x0c067042 */
if(!s->budget--) { s->failed_pc=0x0c067042u; return 0; }
r[1]|=r[11];
goto P_0c067044;
P_0c067044: /* original 2c12, guest PC 0x0c067044 */
if(!s->budget--) { s->failed_pc=0x0c067044u; return 0; }
write(ram,r[12],r[1],4);
goto P_0c067046;
P_0c067046: /* original 903d, guest PC 0x0c067046 */
if(!s->budget--) { s->failed_pc=0x0c067046u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0670c4u,2);
goto P_0c067048;
P_0c067048: /* original 0e75, guest PC 0x0c067048 */
if(!s->budget--) { s->failed_pc=0x0c067048u; return 0; }
write(ram,r[14]+r[0],r[7],2);
goto P_0c06704a;
P_0c06704a: /* original 7008, guest PC 0x0c06704a */
if(!s->budget--) { s->failed_pc=0x0c06704au; return 0; }
r[0]+=0x00000008u;
goto P_0c06704c;
P_0c06704c: /* original 0e65, guest PC 0x0c06704c */
if(!s->budget--) { s->failed_pc=0x0c06704cu; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c06704e;
P_0c06704e: /* original 1e5c, guest PC 0x0c06704e */
if(!s->budget--) { s->failed_pc=0x0c06704eu; return 0; }
write(ram,r[14]+48,r[5],4);
goto P_0c067050;
P_0c067050: /* original 7f04, guest PC 0x0c067050 */
if(!s->budget--) { s->failed_pc=0x0c067050u; return 0; }
r[15]+=0x00000004u;
goto P_0c067052;
P_0c067052: /* original 4f26, guest PC 0x0c067052 */
if(!s->budget--) { s->failed_pc=0x0c067052u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c067054;
P_0c067054: /* original 6bf6, guest PC 0x0c067054 */
if(!s->budget--) { s->failed_pc=0x0c067054u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c067056;
P_0c067056: /* original 6cf6, guest PC 0x0c067056 */
if(!s->budget--) { s->failed_pc=0x0c067056u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c067058;
P_0c067058: /* original 6df6, guest PC 0x0c067058 */
if(!s->budget--) { s->failed_pc=0x0c067058u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06705a;
P_0c06705a: /* original 000b, guest PC 0x0c06705a */
if(!s->budget--) { s->failed_pc=0x0c06705au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06705c: /* original 6ef6, guest PC 0x0c06705c */
if(!s->budget--) { s->failed_pc=0x0c06705cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06705eu,s,ram);
P_0c07021c: /* original f40b, guest PC 0x0c07021c */
if(!s->budget--) { s->failed_pc=0x0c07021cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07021e;
P_0c07021e: /* original 0009, guest PC 0x0c07021e */
if(!s->budget--) { s->failed_pc=0x0c07021eu; return 0; }
goto P_0c070220;
P_0c070220: /* original d306, guest PC 0x0c070220 */
if(!s->budget--) { s->failed_pc=0x0c070220u; return 0; }
r[3]=read(ram,0x0c07023cu,4);
goto P_0c070222;
P_0c070222: /* original 432b, guest PC 0x0c070222 */
if(!s->budget--) { s->failed_pc=0x0c070222u; return 0; }
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
P_0c070224: /* original 0009, guest PC 0x0c070224 */
if(!s->budget--) { s->failed_pc=0x0c070224u; return 0; }
return vf3_matrix_family(0x0c070226u,s,ram);
P_0c070fa6: /* original fe45, guest PC 0x0c070fa6 */
if(!s->budget--) { s->failed_pc=0x0c070fa6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[4]))!=0);
goto P_0c070fa8;
P_0c070fa8: /* original 8902, guest PC 0x0c070fa8 */
if(!s->budget--) { s->failed_pc=0x0c070fa8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c070fb0; }
goto P_0c070faa;
P_0c070faa: /* original d205, guest PC 0x0c070faa */
if(!s->budget--) { s->failed_pc=0x0c070faau; return 0; }
r[2]=read(ram,0x0c070fc0u,4);
goto P_0c070fac;
P_0c070fac: /* original 422b, guest PC 0x0c070fac */
if(!s->budget--) { s->failed_pc=0x0c070facu; return 0; }
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
P_0c070fae: /* original 0009, guest PC 0x0c070fae */
if(!s->budget--) { s->failed_pc=0x0c070faeu; return 0; }
goto P_0c070fb0;
P_0c070fb0: /* original 64f3, guest PC 0x0c070fb0 */
if(!s->budget--) { s->failed_pc=0x0c070fb0u; return 0; }
r[4]=r[15];
goto P_0c070fb2;
P_0c070fb2: /* original 7438, guest PC 0x0c070fb2 */
if(!s->budget--) { s->failed_pc=0x0c070fb2u; return 0; }
r[4]+=0x00000038u;
goto P_0c070fb4;
P_0c070fb4: /* original 65c3, guest PC 0x0c070fb4 */
if(!s->budget--) { s->failed_pc=0x0c070fb4u; return 0; }
r[5]=r[12];
goto P_0c070fb6;
P_0c070fb6: /* original a005, guest PC 0x0c070fb6 */
if(!s->budget--) { s->failed_pc=0x0c070fb6u; return 0; }
goto P_0c070fc4;
P_0c070fb8: /* original 0009, guest PC 0x0c070fb8 */
if(!s->budget--) { s->failed_pc=0x0c070fb8u; return 0; }
return vf3_matrix_family(0x0c070fbau,s,ram);
P_0c070fc4: /* original f059, guest PC 0x0c070fc4 */
if(!s->budget--) { s->failed_pc=0x0c070fc4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070fc6;
P_0c070fc6: /* original f159, guest PC 0x0c070fc6 */
if(!s->budget--) { s->failed_pc=0x0c070fc6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070fc8;
P_0c070fc8: /* original f259, guest PC 0x0c070fc8 */
if(!s->budget--) { s->failed_pc=0x0c070fc8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070fca;
P_0c070fca: /* original 740c, guest PC 0x0c070fca */
if(!s->budget--) { s->failed_pc=0x0c070fcau; return 0; }
r[4]+=0x0000000cu;
goto P_0c070fcc;
P_0c070fcc: /* original f242, guest PC 0x0c070fcc */
if(!s->budget--) { s->failed_pc=0x0c070fccu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c070fce;
P_0c070fce: /* original f142, guest PC 0x0c070fce */
if(!s->budget--) { s->failed_pc=0x0c070fceu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c070fd0;
P_0c070fd0: /* original f042, guest PC 0x0c070fd0 */
if(!s->budget--) { s->failed_pc=0x0c070fd0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c070fd2;
P_0c070fd2: /* original f42b, guest PC 0x0c070fd2 */
if(!s->budget--) { s->failed_pc=0x0c070fd2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070fd4;
P_0c070fd4: /* original f41b, guest PC 0x0c070fd4 */
if(!s->budget--) { s->failed_pc=0x0c070fd4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070fd6;
P_0c070fd6: /* original f40b, guest PC 0x0c070fd6 */
if(!s->budget--) { s->failed_pc=0x0c070fd6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070fd8;
P_0c070fd8: /* original 65f3, guest PC 0x0c070fd8 */
if(!s->budget--) { s->failed_pc=0x0c070fd8u; return 0; }
r[5]=r[15];
goto P_0c070fda;
P_0c070fda: /* original 64f3, guest PC 0x0c070fda */
if(!s->budget--) { s->failed_pc=0x0c070fdau; return 0; }
r[4]=r[15];
goto P_0c070fdc;
P_0c070fdc: /* original 66f3, guest PC 0x0c070fdc */
if(!s->budget--) { s->failed_pc=0x0c070fdcu; return 0; }
r[6]=r[15];
goto P_0c070fde;
P_0c070fde: /* original 7438, guest PC 0x0c070fde */
if(!s->budget--) { s->failed_pc=0x0c070fdeu; return 0; }
r[4]+=0x00000038u;
goto P_0c070fe0;
P_0c070fe0: /* original 7638, guest PC 0x0c070fe0 */
if(!s->budget--) { s->failed_pc=0x0c070fe0u; return 0; }
r[6]+=0x00000038u;
goto P_0c070fe2;
P_0c070fe2: /* original 7544, guest PC 0x0c070fe2 */
if(!s->budget--) { s->failed_pc=0x0c070fe2u; return 0; }
r[5]+=0x00000044u;
goto P_0c070fe4;
P_0c070fe4: /* original f059, guest PC 0x0c070fe4 */
if(!s->budget--) { s->failed_pc=0x0c070fe4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070fe6;
P_0c070fe6: /* original f369, guest PC 0x0c070fe6 */
if(!s->budget--) { s->failed_pc=0x0c070fe6u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070fe8;
P_0c070fe8: /* original f159, guest PC 0x0c070fe8 */
if(!s->budget--) { s->failed_pc=0x0c070fe8u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c070fea;
P_0c070fea: /* original f469, guest PC 0x0c070fea */
if(!s->budget--) { s->failed_pc=0x0c070feau; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c070fec;
P_0c070fec: /* original f031, guest PC 0x0c070fec */
if(!s->budget--) { s->failed_pc=0x0c070fecu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c070fee;
P_0c070fee: /* original f258, guest PC 0x0c070fee */
if(!s->budget--) { s->failed_pc=0x0c070feeu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c070ff0;
P_0c070ff0: /* original f568, guest PC 0x0c070ff0 */
if(!s->budget--) { s->failed_pc=0x0c070ff0u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c070ff2;
P_0c070ff2: /* original f141, guest PC 0x0c070ff2 */
if(!s->budget--) { s->failed_pc=0x0c070ff2u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c070ff4;
P_0c070ff4: /* original f251, guest PC 0x0c070ff4 */
if(!s->budget--) { s->failed_pc=0x0c070ff4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c070ff6;
P_0c070ff6: /* original 7408, guest PC 0x0c070ff6 */
if(!s->budget--) { s->failed_pc=0x0c070ff6u; return 0; }
r[4]+=0x00000008u;
goto P_0c070ff8;
P_0c070ff8: /* original f42a, guest PC 0x0c070ff8 */
if(!s->budget--) { s->failed_pc=0x0c070ff8u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c070ffa;
P_0c070ffa: /* original f41b, guest PC 0x0c070ffa */
if(!s->budget--) { s->failed_pc=0x0c070ffau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c070ffc;
P_0c070ffc: /* original f40b, guest PC 0x0c070ffc */
if(!s->budget--) { s->failed_pc=0x0c070ffcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070ffe;
P_0c070ffe: /* original 0009, guest PC 0x0c070ffe */
if(!s->budget--) { s->failed_pc=0x0c070ffeu; return 0; }
goto P_0c071000;
P_0c071000: /* original e024, guest PC 0x0c071000 */
if(!s->budget--) { s->failed_pc=0x0c071000u; return 0; }
r[0]=0x00000024u;
goto P_0c071002;
P_0c071002: /* original f4fc, guest PC 0x0c071002 */
if(!s->budget--) { s->failed_pc=0x0c071002u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c071004;
P_0c071004: /* original f3f6, guest PC 0x0c071004 */
if(!s->budget--) { s->failed_pc=0x0c071004u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c071006;
P_0c071006: /* original 64f3, guest PC 0x0c071006 */
if(!s->budget--) { s->failed_pc=0x0c071006u; return 0; }
r[4]=r[15];
goto P_0c071008;
P_0c071008: /* original 65f3, guest PC 0x0c071008 */
if(!s->budget--) { s->failed_pc=0x0c071008u; return 0; }
r[5]=r[15];
goto P_0c07100a;
P_0c07100a: /* original 7438, guest PC 0x0c07100a */
if(!s->budget--) { s->failed_pc=0x0c07100au; return 0; }
r[4]+=0x00000038u;
goto P_0c07100c;
P_0c07100c: /* original f431, guest PC 0x0c07100c */
if(!s->budget--) { s->failed_pc=0x0c07100cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c07100e;
P_0c07100e: /* original 7538, guest PC 0x0c07100e */
if(!s->budget--) { s->failed_pc=0x0c07100eu; return 0; }
r[5]+=0x00000038u;
goto P_0c071010;
P_0c071010: /* original f059, guest PC 0x0c071010 */
if(!s->budget--) { s->failed_pc=0x0c071010u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071012;
P_0c071012: /* original f159, guest PC 0x0c071012 */
if(!s->budget--) { s->failed_pc=0x0c071012u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071014;
P_0c071014: /* original f259, guest PC 0x0c071014 */
if(!s->budget--) { s->failed_pc=0x0c071014u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071016;
P_0c071016: /* original f38d, guest PC 0x0c071016 */
if(!s->budget--) { s->failed_pc=0x0c071016u; return 0; }
fr[3]=0;
goto P_0c071018;
P_0c071018: /* original f0ed, guest PC 0x0c071018 */
if(!s->budget--) { s->failed_pc=0x0c071018u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c07101a;
P_0c07101a: /* original f37d, guest PC 0x0c07101a */
if(!s->budget--) { s->failed_pc=0x0c07101au; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c07101c;
P_0c07101c: /* original f342, guest PC 0x0c07101c */
if(!s->budget--) { s->failed_pc=0x0c07101cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c07101e;
P_0c07101e: /* original 740c, guest PC 0x0c07101e */
if(!s->budget--) { s->failed_pc=0x0c07101eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c071020;
P_0c071020: /* original f232, guest PC 0x0c071020 */
if(!s->budget--) { s->failed_pc=0x0c071020u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c071022;
P_0c071022: /* original f132, guest PC 0x0c071022 */
if(!s->budget--) { s->failed_pc=0x0c071022u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c071024;
P_0c071024: /* original f032, guest PC 0x0c071024 */
if(!s->budget--) { s->failed_pc=0x0c071024u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c071026;
P_0c071026: /* original f42b, guest PC 0x0c071026 */
if(!s->budget--) { s->failed_pc=0x0c071026u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071028;
P_0c071028: /* original f41b, guest PC 0x0c071028 */
if(!s->budget--) { s->failed_pc=0x0c071028u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07102a;
P_0c07102a: /* original f40b, guest PC 0x0c07102a */
if(!s->budget--) { s->failed_pc=0x0c07102au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07102c;
P_0c07102c: /* original 64f3, guest PC 0x0c07102c */
if(!s->budget--) { s->failed_pc=0x0c07102cu; return 0; }
r[4]=r[15];
goto P_0c07102e;
P_0c07102e: /* original 65f3, guest PC 0x0c07102e */
if(!s->budget--) { s->failed_pc=0x0c07102eu; return 0; }
r[5]=r[15];
goto P_0c071030;
P_0c071030: /* original 7444, guest PC 0x0c071030 */
if(!s->budget--) { s->failed_pc=0x0c071030u; return 0; }
r[4]+=0x00000044u;
goto P_0c071032;
P_0c071032: /* original 7538, guest PC 0x0c071032 */
if(!s->budget--) { s->failed_pc=0x0c071032u; return 0; }
r[5]+=0x00000038u;
goto P_0c071034;
P_0c071034: /* original f049, guest PC 0x0c071034 */
if(!s->budget--) { s->failed_pc=0x0c071034u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c071036;
P_0c071036: /* original f359, guest PC 0x0c071036 */
if(!s->budget--) { s->failed_pc=0x0c071036u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071038;
P_0c071038: /* original f149, guest PC 0x0c071038 */
if(!s->budget--) { s->failed_pc=0x0c071038u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07103a;
P_0c07103a: /* original f459, guest PC 0x0c07103a */
if(!s->budget--) { s->failed_pc=0x0c07103au; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07103c;
P_0c07103c: /* original f249, guest PC 0x0c07103c */
if(!s->budget--) { s->failed_pc=0x0c07103cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c07103e;
P_0c07103e: /* original f559, guest PC 0x0c07103e */
if(!s->budget--) { s->failed_pc=0x0c07103eu; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071040;
P_0c071040: /* original f030, guest PC 0x0c071040 */
if(!s->budget--) { s->failed_pc=0x0c071040u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c071042;
P_0c071042: /* original f250, guest PC 0x0c071042 */
if(!s->budget--) { s->failed_pc=0x0c071042u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071044;
P_0c071044: /* original f140, guest PC 0x0c071044 */
if(!s->budget--) { s->failed_pc=0x0c071044u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071046;
P_0c071046: /* original f42b, guest PC 0x0c071046 */
if(!s->budget--) { s->failed_pc=0x0c071046u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c071048;
P_0c071048: /* original f41b, guest PC 0x0c071048 */
if(!s->budget--) { s->failed_pc=0x0c071048u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07104a;
P_0c07104a: /* original f40b, guest PC 0x0c07104a */
if(!s->budget--) { s->failed_pc=0x0c07104au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07104c;
P_0c07104c: /* original 65f3, guest PC 0x0c07104c */
if(!s->budget--) { s->failed_pc=0x0c07104cu; return 0; }
r[5]=r[15];
goto P_0c07104e;
P_0c07104e: /* original 64d3, guest PC 0x0c07104e */
if(!s->budget--) { s->failed_pc=0x0c07104eu; return 0; }
r[4]=r[13];
goto P_0c071050;
P_0c071050: /* original 7544, guest PC 0x0c071050 */
if(!s->budget--) { s->failed_pc=0x0c071050u; return 0; }
r[5]+=0x00000044u;
goto P_0c071052;
P_0c071052: /* original 6693, guest PC 0x0c071052 */
if(!s->budget--) { s->failed_pc=0x0c071052u; return 0; }
r[6]=r[9];
goto P_0c071054;
P_0c071054: /* original f059, guest PC 0x0c071054 */
if(!s->budget--) { s->failed_pc=0x0c071054u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c071056;
P_0c071056: /* original f369, guest PC 0x0c071056 */
if(!s->budget--) { s->failed_pc=0x0c071056u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071058;
P_0c071058: /* original f159, guest PC 0x0c071058 */
if(!s->budget--) { s->failed_pc=0x0c071058u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07105a;
P_0c07105a: /* original f469, guest PC 0x0c07105a */
if(!s->budget--) { s->failed_pc=0x0c07105au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c07105c;
P_0c07105c: /* original f259, guest PC 0x0c07105c */
if(!s->budget--) { s->failed_pc=0x0c07105cu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c07105e;
P_0c07105e: /* original f569, guest PC 0x0c07105e */
if(!s->budget--) { s->failed_pc=0x0c07105eu; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c071060;
P_0c071060: /* original 740c, guest PC 0x0c071060 */
if(!s->budget--) { s->failed_pc=0x0c071060u; return 0; }
r[4]+=0x0000000cu;
goto P_0c071062;
P_0c071062: /* original f030, guest PC 0x0c071062 */
if(!s->budget--) { s->failed_pc=0x0c071062u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c071064;
P_0c071064: /* original f250, guest PC 0x0c071064 */
if(!s->budget--) { s->failed_pc=0x0c071064u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c071066;
P_0c071066: /* original f140, guest PC 0x0c071066 */
if(!s->budget--) { s->failed_pc=0x0c071066u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c071068;
P_0c071068: /* original f42b, guest PC 0x0c071068 */
if(!s->budget--) { s->failed_pc=0x0c071068u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c07106a;
P_0c07106a: /* original f41b, guest PC 0x0c07106a */
if(!s->budget--) { s->failed_pc=0x0c07106au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c07106c;
P_0c07106c: /* original f40b, guest PC 0x0c07106c */
if(!s->budget--) { s->failed_pc=0x0c07106cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c07106e;
P_0c07106e: /* original 0009, guest PC 0x0c07106e */
if(!s->budget--) { s->failed_pc=0x0c07106eu; return 0; }
return vf3_matrix_family(0x0c071070u,s,ram);
P_0c074930: /* original 2fe6, guest PC 0x0c074930 */
if(!s->budget--) { s->failed_pc=0x0c074930u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c074932;
P_0c074932: /* original ee00, guest PC 0x0c074932 */
if(!s->budget--) { s->failed_pc=0x0c074932u; return 0; }
r[14]=0x00000000u;
goto P_0c074934;
P_0c074934: /* original 2fd6, guest PC 0x0c074934 */
if(!s->budget--) { s->failed_pc=0x0c074934u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c074936;
P_0c074936: /* original 2fc6, guest PC 0x0c074936 */
if(!s->budget--) { s->failed_pc=0x0c074936u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c074938;
P_0c074938: /* original 2fb6, guest PC 0x0c074938 */
if(!s->budget--) { s->failed_pc=0x0c074938u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07493a;
P_0c07493a: /* original 9034, guest PC 0x0c07493a */
if(!s->budget--) { s->failed_pc=0x0c07493au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0749a6u,2);
goto P_0c07493c;
P_0c07493c: /* original 7ffc, guest PC 0x0c07493c */
if(!s->budget--) { s->failed_pc=0x0c07493cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07493e;
P_0c07493e: /* original 0d4c, guest PC 0x0c07493e */
if(!s->budget--) { s->failed_pc=0x0c07493eu; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c074940;
P_0c074940: /* original 60dc, guest PC 0x0c074940 */
if(!s->budget--) { s->failed_pc=0x0c074940u; return 0; }
r[0]=r[13]&255u;
goto P_0c074942;
P_0c074942: /* original 8800, guest PC 0x0c074942 */
if(!s->budget--) { s->failed_pc=0x0c074942u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c074944;
P_0c074944: /* original 8d13, guest PC 0x0c074944 */
if(!s->budget--) { s->failed_pc=0x0c074944u; return 0; }
cond=r[17]&1u;
r[13]=r[0];
if(cond) { goto P_0c07496e; }
goto P_0c074948;
P_0c074946: /* original 6d03, guest PC 0x0c074946 */
if(!s->budget--) { s->failed_pc=0x0c074946u; return 0; }
r[13]=r[0];
goto P_0c074948;
P_0c074948: /* original 8801, guest PC 0x0c074948 */
if(!s->budget--) { s->failed_pc=0x0c074948u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07494a;
P_0c07494a: /* original 8916, guest PC 0x0c07494a */
if(!s->budget--) { s->failed_pc=0x0c07494au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07497a; }
goto P_0c07494c;
P_0c07494c: /* original 8802, guest PC 0x0c07494c */
if(!s->budget--) { s->failed_pc=0x0c07494cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c07494e;
P_0c07494e: /* original 8906, guest PC 0x0c07494e */
if(!s->budget--) { s->failed_pc=0x0c07494eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07495e; }
goto P_0c074950;
P_0c074950: /* original 8803, guest PC 0x0c074950 */
if(!s->budget--) { s->failed_pc=0x0c074950u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c074952;
P_0c074952: /* original 890f, guest PC 0x0c074952 */
if(!s->budget--) { s->failed_pc=0x0c074952u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074974; }
goto P_0c074954;
P_0c074954: /* original 8805, guest PC 0x0c074954 */
if(!s->budget--) { s->failed_pc=0x0c074954u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c074956;
P_0c074956: /* original 8902, guest PC 0x0c074956 */
if(!s->budget--) { s->failed_pc=0x0c074956u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07495e; }
goto P_0c074958;
P_0c074958: /* original 60d3, guest PC 0x0c074958 */
if(!s->budget--) { s->failed_pc=0x0c074958u; return 0; }
r[0]=r[13];
goto P_0c07495a;
P_0c07495a: /* original 8806, guest PC 0x0c07495a */
if(!s->budget--) { s->failed_pc=0x0c07495au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c07495c;
P_0c07495c: /* original 8b60, guest PC 0x0c07495c */
if(!s->budget--) { s->failed_pc=0x0c07495cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074a20; }
goto P_0c07495e;
P_0c07495e: /* original e048, guest PC 0x0c07495e */
if(!s->budget--) { s->failed_pc=0x0c07495eu; return 0; }
r[0]=0x00000048u;
goto P_0c074960;
P_0c074960: /* original d314, guest PC 0x0c074960 */
if(!s->budget--) { s->failed_pc=0x0c074960u; return 0; }
r[3]=read(ram,0x0c0749b4u,4);
goto P_0c074962;
P_0c074962: /* original 0c5e, guest PC 0x0c074962 */
if(!s->budget--) { s->failed_pc=0x0c074962u; return 0; }
r[12]=read(ram,r[5]+r[0],4);
goto P_0c074964;
P_0c074964: /* original 23c8, guest PC 0x0c074964 */
if(!s->budget--) { s->failed_pc=0x0c074964u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c074966;
P_0c074966: /* original 895b, guest PC 0x0c074966 */
if(!s->budget--) { s->failed_pc=0x0c074966u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074a20; }
goto P_0c074968;
P_0c074968: /* original dd13, guest PC 0x0c074968 */
if(!s->budget--) { s->failed_pc=0x0c074968u; return 0; }
r[13]=read(ram,0x0c0749b8u,4);
goto P_0c07496a;
P_0c07496a: /* original a00c, guest PC 0x0c07496a */
if(!s->budget--) { s->failed_pc=0x0c07496au; return 0; }
goto P_0c074986;
P_0c07496c: /* original 0009, guest PC 0x0c07496c */
if(!s->budget--) { s->failed_pc=0x0c07496cu; return 0; }
goto P_0c07496e;
P_0c07496e: /* original dd13, guest PC 0x0c07496e */
if(!s->budget--) { s->failed_pc=0x0c07496eu; return 0; }
r[13]=read(ram,0x0c0749bcu,4);
goto P_0c074970;
P_0c074970: /* original a009, guest PC 0x0c074970 */
if(!s->budget--) { s->failed_pc=0x0c074970u; return 0; }
goto P_0c074986;
P_0c074972: /* original 0009, guest PC 0x0c074972 */
if(!s->budget--) { s->failed_pc=0x0c074972u; return 0; }
goto P_0c074974;
P_0c074974: /* original dd12, guest PC 0x0c074974 */
if(!s->budget--) { s->failed_pc=0x0c074974u; return 0; }
r[13]=read(ram,0x0c0749c0u,4);
goto P_0c074976;
P_0c074976: /* original a006, guest PC 0x0c074976 */
if(!s->budget--) { s->failed_pc=0x0c074976u; return 0; }
goto P_0c074986;
P_0c074978: /* original 0009, guest PC 0x0c074978 */
if(!s->budget--) { s->failed_pc=0x0c074978u; return 0; }
goto P_0c07497a;
P_0c07497a: /* original 667c, guest PC 0x0c07497a */
if(!s->budget--) { s->failed_pc=0x0c07497au; return 0; }
r[6]=r[7]&255u;
goto P_0c07497c;
P_0c07497c: /* original dd11, guest PC 0x0c07497c */
if(!s->budget--) { s->failed_pc=0x0c07497cu; return 0; }
r[13]=read(ram,0x0c0749c4u,4);
goto P_0c07497e;
P_0c07497e: /* original 6063, guest PC 0x0c07497e */
if(!s->budget--) { s->failed_pc=0x0c07497eu; return 0; }
r[0]=r[6];
goto P_0c074980;
P_0c074980: /* original 880b, guest PC 0x0c074980 */
if(!s->budget--) { s->failed_pc=0x0c074980u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c074982;
P_0c074982: /* original 8b00, guest PC 0x0c074982 */
if(!s->budget--) { s->failed_pc=0x0c074982u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074986; }
goto P_0c074984;
P_0c074984: /* original dd10, guest PC 0x0c074984 */
if(!s->budget--) { s->failed_pc=0x0c074984u; return 0; }
r[13]=read(ram,0x0c0749c8u,4);
goto P_0c074986;
P_0c074986: /* original 900f, guest PC 0x0c074986 */
if(!s->budget--) { s->failed_pc=0x0c074986u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0749a8u,2);
goto P_0c074988;
P_0c074988: /* original eb01, guest PC 0x0c074988 */
if(!s->budget--) { s->failed_pc=0x0c074988u; return 0; }
r[11]=0x00000001u;
goto P_0c07498a;
P_0c07498a: /* original 064e, guest PC 0x0c07498a */
if(!s->budget--) { s->failed_pc=0x0c07498au; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c07498c;
P_0c07498c: /* original 26b8, guest PC 0x0c07498c */
if(!s->budget--) { s->failed_pc=0x0c07498cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[11])==0)!=0);
goto P_0c07498e;
P_0c07498e: /* original 891e, guest PC 0x0c07498e */
if(!s->budget--) { s->failed_pc=0x0c07498eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0749ce; }
goto P_0c074990;
P_0c074990: /* original 900b, guest PC 0x0c074990 */
if(!s->budget--) { s->failed_pc=0x0c074990u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0749aau,2);
goto P_0c074992;
P_0c074992: /* original e31e, guest PC 0x0c074992 */
if(!s->budget--) { s->failed_pc=0x0c074992u; return 0; }
r[3]=0x0000001eu;
goto P_0c074994;
P_0c074994: /* original 064c, guest PC 0x0c074994 */
if(!s->budget--) { s->failed_pc=0x0c074994u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c074996;
P_0c074996: /* original 666c, guest PC 0x0c074996 */
if(!s->budget--) { s->failed_pc=0x0c074996u; return 0; }
r[6]=r[6]&255u;
goto P_0c074998;
P_0c074998: /* original 3632, guest PC 0x0c074998 */
if(!s->budget--) { s->failed_pc=0x0c074998u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[3])!=0);
goto P_0c07499a;
P_0c07499a: /* original 8917, guest PC 0x0c07499a */
if(!s->budget--) { s->failed_pc=0x0c07499au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0749cc; }
goto P_0c07499c;
P_0c07499c: /* original a017, guest PC 0x0c07499c */
if(!s->budget--) { s->failed_pc=0x0c07499cu; return 0; }
r[14]=0x00000003u;
goto P_0c0749ce;
P_0c07499e: /* original ee03, guest PC 0x0c07499e */
if(!s->budget--) { s->failed_pc=0x0c07499eu; return 0; }
r[14]=0x00000003u;
return vf3_matrix_family(0x0c0749a0u,s,ram);
P_0c0749cc: /* original ee06, guest PC 0x0c0749cc */
if(!s->budget--) { s->failed_pc=0x0c0749ccu; return 0; }
r[14]=0x00000006u;
goto P_0c0749ce;
P_0c0749ce: /* original 6673, guest PC 0x0c0749ce */
if(!s->budget--) { s->failed_pc=0x0c0749ceu; return 0; }
r[6]=r[7];
goto P_0c0749d0;
P_0c0749d0: /* original d73f, guest PC 0x0c0749d0 */
if(!s->budget--) { s->failed_pc=0x0c0749d0u; return 0; }
r[7]=read(ram,0x0c074ad0u,4);
goto P_0c0749d2;
P_0c0749d2: /* original 6363, guest PC 0x0c0749d2 */
if(!s->budget--) { s->failed_pc=0x0c0749d2u; return 0; }
r[3]=r[6];
goto P_0c0749d4;
P_0c0749d4: /* original 2378, guest PC 0x0c0749d4 */
if(!s->budget--) { s->failed_pc=0x0c0749d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c0749d6;
P_0c0749d6: /* original 8b02, guest PC 0x0c0749d6 */
if(!s->budget--) { s->failed_pc=0x0c0749d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0749de; }
goto P_0c0749d8;
P_0c0749d8: /* original d13e, guest PC 0x0c0749d8 */
if(!s->budget--) { s->failed_pc=0x0c0749d8u; return 0; }
r[1]=read(ram,0x0c074ad4u,4);
goto P_0c0749da;
P_0c0749da: /* original 2168, guest PC 0x0c0749da */
if(!s->budget--) { s->failed_pc=0x0c0749dau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[6])==0)!=0);
goto P_0c0749dc;
P_0c0749dc: /* original 8914, guest PC 0x0c0749dc */
if(!s->budget--) { s->failed_pc=0x0c0749dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074a08; }
goto P_0c0749de;
P_0c0749de: /* original 6442, guest PC 0x0c0749de */
if(!s->budget--) { s->failed_pc=0x0c0749deu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0749e0;
P_0c0749e0: /* original 6352, guest PC 0x0c0749e0 */
if(!s->budget--) { s->failed_pc=0x0c0749e0u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c0749e2;
P_0c0749e2: /* original 243a, guest PC 0x0c0749e2 */
if(!s->budget--) { s->failed_pc=0x0c0749e2u; return 0; }
r[4]^=r[3];
goto P_0c0749e4;
P_0c0749e4: /* original 4429, guest PC 0x0c0749e4 */
if(!s->budget--) { s->failed_pc=0x0c0749e4u; return 0; }
r[4]>>=16;
goto P_0c0749e6;
P_0c0749e6: /* original 4419, guest PC 0x0c0749e6 */
if(!s->budget--) { s->failed_pc=0x0c0749e6u; return 0; }
r[4]>>=8;
goto P_0c0749e8;
P_0c0749e8: /* original 4401, guest PC 0x0c0749e8 */
if(!s->budget--) { s->failed_pc=0x0c0749e8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c0749ea;
P_0c0749ea: /* original 2f42, guest PC 0x0c0749ea */
if(!s->budget--) { s->failed_pc=0x0c0749eau; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0749ec;
P_0c0749ec: /* original 64c3, guest PC 0x0c0749ec */
if(!s->budget--) { s->failed_pc=0x0c0749ecu; return 0; }
r[4]=r[12];
goto P_0c0749ee;
P_0c0749ee: /* original 63f2, guest PC 0x0c0749ee */
if(!s->budget--) { s->failed_pc=0x0c0749eeu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0749f0;
P_0c0749f0: /* original 4419, guest PC 0x0c0749f0 */
if(!s->budget--) { s->failed_pc=0x0c0749f0u; return 0; }
r[4]>>=8;
goto P_0c0749f2;
P_0c0749f2: /* original 4409, guest PC 0x0c0749f2 */
if(!s->budget--) { s->failed_pc=0x0c0749f2u; return 0; }
r[4]>>=2;
goto P_0c0749f4;
P_0c0749f4: /* original 243a, guest PC 0x0c0749f4 */
if(!s->budget--) { s->failed_pc=0x0c0749f4u; return 0; }
r[4]^=r[3];
goto P_0c0749f6;
P_0c0749f6: /* original 24b8, guest PC 0x0c0749f6 */
if(!s->budget--) { s->failed_pc=0x0c0749f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[11])==0)!=0);
goto P_0c0749f8;
P_0c0749f8: /* original 8900, guest PC 0x0c0749f8 */
if(!s->budget--) { s->failed_pc=0x0c0749f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0749fc; }
goto P_0c0749fa;
P_0c0749fa: /* original 6667, guest PC 0x0c0749fa */
if(!s->budget--) { s->failed_pc=0x0c0749fau; return 0; }
r[6]=~r[6];
goto P_0c0749fc;
P_0c0749fc: /* original 2678, guest PC 0x0c0749fc */
if(!s->budget--) { s->failed_pc=0x0c0749fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[7])==0)!=0);
goto P_0c0749fe;
P_0c0749fe: /* original 8b01, guest PC 0x0c0749fe */
if(!s->budget--) { s->failed_pc=0x0c0749feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074a04; }
goto P_0c074a00;
P_0c074a00: /* original a001, guest PC 0x0c074a00 */
if(!s->budget--) { s->failed_pc=0x0c074a00u; return 0; }
r[4]=0x00000002u;
goto P_0c074a06;
P_0c074a02: /* original e402, guest PC 0x0c074a02 */
if(!s->budget--) { s->failed_pc=0x0c074a02u; return 0; }
r[4]=0x00000002u;
goto P_0c074a04;
P_0c074a04: /* original 64b3, guest PC 0x0c074a04 */
if(!s->budget--) { s->failed_pc=0x0c074a04u; return 0; }
r[4]=r[11];
goto P_0c074a06;
P_0c074a06: /* original 3e4c, guest PC 0x0c074a06 */
if(!s->budget--) { s->failed_pc=0x0c074a06u; return 0; }
r[14]+=r[4];
goto P_0c074a08;
P_0c074a08: /* original e061, guest PC 0x0c074a08 */
if(!s->budget--) { s->failed_pc=0x0c074a08u; return 0; }
r[0]=0x00000061u;
goto P_0c074a0a;
P_0c074a0a: /* original 045c, guest PC 0x0c074a0a */
if(!s->budget--) { s->failed_pc=0x0c074a0au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c074a0c;
P_0c074a0c: /* original 604c, guest PC 0x0c074a0c */
if(!s->budget--) { s->failed_pc=0x0c074a0cu; return 0; }
r[0]=r[4]&255u;
goto P_0c074a0e;
P_0c074a0e: /* original 880c, guest PC 0x0c074a0e */
if(!s->budget--) { s->failed_pc=0x0c074a0eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c074a10;
P_0c074a10: /* original 8f01, guest PC 0x0c074a10 */
if(!s->budget--) { s->failed_pc=0x0c074a10u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c074a16; }
goto P_0c074a14;
P_0c074a12: /* original 6403, guest PC 0x0c074a12 */
if(!s->budget--) { s->failed_pc=0x0c074a12u; return 0; }
r[4]=r[0];
goto P_0c074a14;
P_0c074a14: /* original 7e0c, guest PC 0x0c074a14 */
if(!s->budget--) { s->failed_pc=0x0c074a14u; return 0; }
r[14]+=0x0000000cu;
goto P_0c074a16;
P_0c074a16: /* original 66d3, guest PC 0x0c074a16 */
if(!s->budget--) { s->failed_pc=0x0c074a16u; return 0; }
r[6]=r[13];
goto P_0c074a18;
P_0c074a18: /* original 4e00, guest PC 0x0c074a18 */
if(!s->budget--) { s->failed_pc=0x0c074a18u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c074a1a;
P_0c074a1a: /* original 36ec, guest PC 0x0c074a1a */
if(!s->budget--) { s->failed_pc=0x0c074a1au; return 0; }
r[6]+=r[14];
goto P_0c074a1c;
P_0c074a1c: /* original 6661, guest PC 0x0c074a1c */
if(!s->budget--) { s->failed_pc=0x0c074a1cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[6]=tmp;
goto P_0c074a1e;
P_0c074a1e: /* original 666d, guest PC 0x0c074a1e */
if(!s->budget--) { s->failed_pc=0x0c074a1eu; return 0; }
r[6]=r[6]&65535u;
goto P_0c074a20;
P_0c074a20: /* original 7f04, guest PC 0x0c074a20 */
if(!s->budget--) { s->failed_pc=0x0c074a20u; return 0; }
r[15]+=0x00000004u;
goto P_0c074a22;
P_0c074a22: /* original 6063, guest PC 0x0c074a22 */
if(!s->budget--) { s->failed_pc=0x0c074a22u; return 0; }
r[0]=r[6];
goto P_0c074a24;
P_0c074a24: /* original 6bf6, guest PC 0x0c074a24 */
if(!s->budget--) { s->failed_pc=0x0c074a24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c074a26;
P_0c074a26: /* original 6cf6, guest PC 0x0c074a26 */
if(!s->budget--) { s->failed_pc=0x0c074a26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c074a28;
P_0c074a28: /* original 6df6, guest PC 0x0c074a28 */
if(!s->budget--) { s->failed_pc=0x0c074a28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c074a2a;
P_0c074a2a: /* original 000b, guest PC 0x0c074a2a */
if(!s->budget--) { s->failed_pc=0x0c074a2au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c074a2c: /* original 6ef6, guest PC 0x0c074a2c */
if(!s->budget--) { s->failed_pc=0x0c074a2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c074a2e;
P_0c074a2e: /* original 9043, guest PC 0x0c074a2e */
if(!s->budget--) { s->failed_pc=0x0c074a2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074ab8u,2);
goto P_0c074a30;
P_0c074a30: /* original 000b, guest PC 0x0c074a30 */
if(!s->budget--) { s->failed_pc=0x0c074a30u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c074a32: /* original 0009, guest PC 0x0c074a32 */
if(!s->budget--) { s->failed_pc=0x0c074a32u; return 0; }
goto P_0c074a34;
P_0c074a34: /* original 9041, guest PC 0x0c074a34 */
if(!s->budget--) { s->failed_pc=0x0c074a34u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074abau,2);
goto P_0c074a36;
P_0c074a36: /* original 000b, guest PC 0x0c074a36 */
if(!s->budget--) { s->failed_pc=0x0c074a36u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c074a38: /* original 0009, guest PC 0x0c074a38 */
if(!s->budget--) { s->failed_pc=0x0c074a38u; return 0; }
return vf3_matrix_family(0x0c074a3au,s,ram);
P_0c074a52: /* original 9033, guest PC 0x0c074a52 */
if(!s->budget--) { s->failed_pc=0x0c074a52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074abcu,2);
goto P_0c074a54;
P_0c074a54: /* original f346, guest PC 0x0c074a54 */
if(!s->budget--) { s->failed_pc=0x0c074a54u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c074a56;
P_0c074a56: /* original 9032, guest PC 0x0c074a56 */
if(!s->budget--) { s->failed_pc=0x0c074a56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074abeu,2);
goto P_0c074a58;
P_0c074a58: /* original f456, guest PC 0x0c074a58 */
if(!s->budget--) { s->failed_pc=0x0c074a58u; return 0; }
vf3_matrix_load(s,ram,4,r[5]+r[0]);
goto P_0c074a5a;
P_0c074a5a: /* original c720, guest PC 0x0c074a5a */
if(!s->budget--) { s->failed_pc=0x0c074a5au; return 0; }
r[0]=0x0c074adcu;
goto P_0c074a5c;
P_0c074a5c: /* original f431, guest PC 0x0c074a5c */
if(!s->budget--) { s->failed_pc=0x0c074a5cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c074a5e;
P_0c074a5e: /* original f308, guest PC 0x0c074a5e */
if(!s->budget--) { s->failed_pc=0x0c074a5eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c074a60;
P_0c074a60: /* original f435, guest PC 0x0c074a60 */
if(!s->budget--) { s->failed_pc=0x0c074a60u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c074a62;
P_0c074a62: /* original 8900, guest PC 0x0c074a62 */
if(!s->budget--) { s->failed_pc=0x0c074a62u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074a66; }
goto P_0c074a64;
P_0c074a64: /* original 962d, guest PC 0x0c074a64 */
if(!s->budget--) { s->failed_pc=0x0c074a64u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074ac2u,2);
goto P_0c074a66;
P_0c074a66: /* original 000b, guest PC 0x0c074a66 */
if(!s->budget--) { s->failed_pc=0x0c074a66u; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c074a68: /* original 6063, guest PC 0x0c074a68 */
if(!s->budget--) { s->failed_pc=0x0c074a68u; return 0; }
r[0]=r[6];
goto P_0c074a6a;
P_0c074a6a: /* original 9027, guest PC 0x0c074a6a */
if(!s->budget--) { s->failed_pc=0x0c074a6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074abcu,2);
goto P_0c074a6c;
P_0c074a6c: /* original f346, guest PC 0x0c074a6c */
if(!s->budget--) { s->failed_pc=0x0c074a6cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c074a6e;
P_0c074a6e: /* original 9026, guest PC 0x0c074a6e */
if(!s->budget--) { s->failed_pc=0x0c074a6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074abeu,2);
goto P_0c074a70;
P_0c074a70: /* original f456, guest PC 0x0c074a70 */
if(!s->budget--) { s->failed_pc=0x0c074a70u; return 0; }
vf3_matrix_load(s,ram,4,r[5]+r[0]);
goto P_0c074a72;
P_0c074a72: /* original c71b, guest PC 0x0c074a72 */
if(!s->budget--) { s->failed_pc=0x0c074a72u; return 0; }
r[0]=0x0c074ae0u;
goto P_0c074a74;
P_0c074a74: /* original f431, guest PC 0x0c074a74 */
if(!s->budget--) { s->failed_pc=0x0c074a74u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c074a76;
P_0c074a76: /* original f308, guest PC 0x0c074a76 */
if(!s->budget--) { s->failed_pc=0x0c074a76u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c074a78;
P_0c074a78: /* original f435, guest PC 0x0c074a78 */
if(!s->budget--) { s->failed_pc=0x0c074a78u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c074a7a;
P_0c074a7a: /* original 8900, guest PC 0x0c074a7a */
if(!s->budget--) { s->failed_pc=0x0c074a7au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074a7e; }
goto P_0c074a7c;
P_0c074a7c: /* original 9622, guest PC 0x0c074a7c */
if(!s->budget--) { s->failed_pc=0x0c074a7cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074ac4u,2);
goto P_0c074a7e;
P_0c074a7e: /* original 000b, guest PC 0x0c074a7e */
if(!s->budget--) { s->failed_pc=0x0c074a7eu; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c074a80: /* original 6063, guest PC 0x0c074a80 */
if(!s->budget--) { s->failed_pc=0x0c074a80u; return 0; }
r[0]=r[6];
goto P_0c074a82;
P_0c074a82: /* original 9020, guest PC 0x0c074a82 */
if(!s->budget--) { s->failed_pc=0x0c074a82u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074ac6u,2);
goto P_0c074a84;
P_0c074a84: /* original e30f, guest PC 0x0c074a84 */
if(!s->budget--) { s->failed_pc=0x0c074a84u; return 0; }
r[3]=0x0000000fu;
goto P_0c074a86;
P_0c074a86: /* original 054c, guest PC 0x0c074a86 */
if(!s->budget--) { s->failed_pc=0x0c074a86u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c074a88;
P_0c074a88: /* original d416, guest PC 0x0c074a88 */
if(!s->budget--) { s->failed_pc=0x0c074a88u; return 0; }
r[4]=read(ram,0x0c074ae4u,4);
goto P_0c074a8a;
P_0c074a8a: /* original 655c, guest PC 0x0c074a8a */
if(!s->budget--) { s->failed_pc=0x0c074a8au; return 0; }
r[5]=r[5]&255u;
goto P_0c074a8c;
P_0c074a8c: /* original 3536, guest PC 0x0c074a8c */
if(!s->budget--) { s->failed_pc=0x0c074a8cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[3])!=0);
goto P_0c074a8e;
P_0c074a8e: /* original 8f0b, guest PC 0x0c074a8e */
if(!s->budget--) { s->failed_pc=0x0c074a8eu; return 0; }
cond=r[17]&1u;
r[4]&=r[6];
if(!cond) { goto P_0c074aa8; }
goto P_0c074a92;
P_0c074a90: /* original 2469, guest PC 0x0c074a90 */
if(!s->budget--) { s->failed_pc=0x0c074a90u; return 0; }
r[4]&=r[6];
goto P_0c074a92;
P_0c074a92: /* original e11e, guest PC 0x0c074a92 */
if(!s->budget--) { s->failed_pc=0x0c074a92u; return 0; }
r[1]=0x0000001eu;
goto P_0c074a94;
P_0c074a94: /* original 3516, guest PC 0x0c074a94 */
if(!s->budget--) { s->failed_pc=0x0c074a94u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[1])!=0);
goto P_0c074a96;
P_0c074a96: /* original 8b0d, guest PC 0x0c074a96 */
if(!s->budget--) { s->failed_pc=0x0c074a96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074ab4; }
goto P_0c074a98;
P_0c074a98: /* original 2448, guest PC 0x0c074a98 */
if(!s->budget--) { s->failed_pc=0x0c074a98u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c074a9a;
P_0c074a9a: /* original 8902, guest PC 0x0c074a9a */
if(!s->budget--) { s->failed_pc=0x0c074a9au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074aa2; }
goto P_0c074a9c;
P_0c074a9c: /* original 9714, guest PC 0x0c074a9c */
if(!s->budget--) { s->failed_pc=0x0c074a9cu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074ac8u,2);
goto P_0c074a9e;
P_0c074a9e: /* original a009, guest PC 0x0c074a9e */
if(!s->budget--) { s->failed_pc=0x0c074a9eu; return 0; }
goto P_0c074ab4;
P_0c074aa0: /* original 0009, guest PC 0x0c074aa0 */
if(!s->budget--) { s->failed_pc=0x0c074aa0u; return 0; }
goto P_0c074aa2;
P_0c074aa2: /* original 9712, guest PC 0x0c074aa2 */
if(!s->budget--) { s->failed_pc=0x0c074aa2u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074acau,2);
goto P_0c074aa4;
P_0c074aa4: /* original a006, guest PC 0x0c074aa4 */
if(!s->budget--) { s->failed_pc=0x0c074aa4u; return 0; }
goto P_0c074ab4;
P_0c074aa6: /* original 0009, guest PC 0x0c074aa6 */
if(!s->budget--) { s->failed_pc=0x0c074aa6u; return 0; }
goto P_0c074aa8;
P_0c074aa8: /* original 2448, guest PC 0x0c074aa8 */
if(!s->budget--) { s->failed_pc=0x0c074aa8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c074aaa;
P_0c074aaa: /* original 8902, guest PC 0x0c074aaa */
if(!s->budget--) { s->failed_pc=0x0c074aaau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074ab2; }
goto P_0c074aac;
P_0c074aac: /* original 970e, guest PC 0x0c074aac */
if(!s->budget--) { s->failed_pc=0x0c074aacu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074accu,2);
goto P_0c074aae;
P_0c074aae: /* original a001, guest PC 0x0c074aae */
if(!s->budget--) { s->failed_pc=0x0c074aaeu; return 0; }
goto P_0c074ab4;
P_0c074ab0: /* original 0009, guest PC 0x0c074ab0 */
if(!s->budget--) { s->failed_pc=0x0c074ab0u; return 0; }
goto P_0c074ab2;
P_0c074ab2: /* original 970c, guest PC 0x0c074ab2 */
if(!s->budget--) { s->failed_pc=0x0c074ab2u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074aceu,2);
goto P_0c074ab4;
P_0c074ab4: /* original 000b, guest PC 0x0c074ab4 */
if(!s->budget--) { s->failed_pc=0x0c074ab4u; return 0; }
target=r[16];
r[0]=r[7];
s->pc=target; return ram->oob==0;
P_0c074ab6: /* original 6073, guest PC 0x0c074ab6 */
if(!s->budget--) { s->failed_pc=0x0c074ab6u; return 0; }
r[0]=r[7];
return vf3_matrix_family(0x0c074ab8u,s,ram);
P_0c074ae8: /* original 9071, guest PC 0x0c074ae8 */
if(!s->budget--) { s->failed_pc=0x0c074ae8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074bceu,2);
goto P_0c074aea;
P_0c074aea: /* original 034c, guest PC 0x0c074aea */
if(!s->budget--) { s->failed_pc=0x0c074aeau; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c074aec;
P_0c074aec: /* original 2338, guest PC 0x0c074aec */
if(!s->budget--) { s->failed_pc=0x0c074aecu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c074aee;
P_0c074aee: /* original 8b04, guest PC 0x0c074aee */
if(!s->budget--) { s->failed_pc=0x0c074aeeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074afa; }
goto P_0c074af0;
P_0c074af0: /* original 646c, guest PC 0x0c074af0 */
if(!s->budget--) { s->failed_pc=0x0c074af0u; return 0; }
r[4]=r[6]&255u;
goto P_0c074af2;
P_0c074af2: /* original 6043, guest PC 0x0c074af2 */
if(!s->budget--) { s->failed_pc=0x0c074af2u; return 0; }
r[0]=r[4];
goto P_0c074af4;
P_0c074af4: /* original 8811, guest PC 0x0c074af4 */
if(!s->budget--) { s->failed_pc=0x0c074af4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000011u)!=0);
goto P_0c074af6;
P_0c074af6: /* original 8900, guest PC 0x0c074af6 */
if(!s->budget--) { s->failed_pc=0x0c074af6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074afa; }
goto P_0c074af8;
P_0c074af8: /* original 976a, guest PC 0x0c074af8 */
if(!s->budget--) { s->failed_pc=0x0c074af8u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074bd0u,2);
goto P_0c074afa;
P_0c074afa: /* original 000b, guest PC 0x0c074afa */
if(!s->budget--) { s->failed_pc=0x0c074afau; return 0; }
target=r[16];
r[0]=r[7];
s->pc=target; return ram->oob==0;
P_0c074afc: /* original 6073, guest PC 0x0c074afc */
if(!s->budget--) { s->failed_pc=0x0c074afcu; return 0; }
r[0]=r[7];
goto P_0c074afe;
P_0c074afe: /* original 2fe6, guest PC 0x0c074afe */
if(!s->budget--) { s->failed_pc=0x0c074afeu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c074b00;
P_0c074b00: /* original 6e73, guest PC 0x0c074b00 */
if(!s->budget--) { s->failed_pc=0x0c074b00u; return 0; }
r[14]=r[7];
goto P_0c074b02;
P_0c074b02: /* original 2fd6, guest PC 0x0c074b02 */
if(!s->budget--) { s->failed_pc=0x0c074b02u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c074b04;
P_0c074b04: /* original 2fc6, guest PC 0x0c074b04 */
if(!s->budget--) { s->failed_pc=0x0c074b04u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c074b06;
P_0c074b06: /* original 2fb6, guest PC 0x0c074b06 */
if(!s->budget--) { s->failed_pc=0x0c074b06u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c074b08;
P_0c074b08: /* original 2fa6, guest PC 0x0c074b08 */
if(!s->budget--) { s->failed_pc=0x0c074b08u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c074b0a;
P_0c074b0a: /* original 2f96, guest PC 0x0c074b0a */
if(!s->budget--) { s->failed_pc=0x0c074b0au; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c074b0c;
P_0c074b0c: /* original 2f86, guest PC 0x0c074b0c */
if(!s->budget--) { s->failed_pc=0x0c074b0cu; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c074b0e;
P_0c074b0e: /* original 4f22, guest PC 0x0c074b0e */
if(!s->budget--) { s->failed_pc=0x0c074b0eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c074b10;
P_0c074b10: /* original 7ff8, guest PC 0x0c074b10 */
if(!s->budget--) { s->failed_pc=0x0c074b10u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c074b12;
P_0c074b12: /* original 1f71, guest PC 0x0c074b12 */
if(!s->budget--) { s->failed_pc=0x0c074b12u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c074b14;
P_0c074b14: /* original 5dfb, guest PC 0x0c074b14 */
if(!s->budget--) { s->failed_pc=0x0c074b14u; return 0; }
r[13]=read(ram,r[15]+44,4);
goto P_0c074b16;
P_0c074b16: /* original 50fa, guest PC 0x0c074b16 */
if(!s->budget--) { s->failed_pc=0x0c074b16u; return 0; }
r[0]=read(ram,r[15]+40,4);
goto P_0c074b18;
P_0c074b18: /* original d932, guest PC 0x0c074b18 */
if(!s->budget--) { s->failed_pc=0x0c074b18u; return 0; }
r[9]=read(ram,0x0c074be4u,4);
goto P_0c074b1a;
P_0c074b1a: /* original 6ee2, guest PC 0x0c074b1a */
if(!s->budget--) { s->failed_pc=0x0c074b1au; return 0; }
tmp=read(ram,r[14],4);
r[14]=tmp;
goto P_0c074b1c;
P_0c074b1c: /* original 88ff, guest PC 0x0c074b1c */
if(!s->budget--) { s->failed_pc=0x0c074b1cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c074b1e;
P_0c074b1e: /* original 6dd2, guest PC 0x0c074b1e */
if(!s->budget--) { s->failed_pc=0x0c074b1eu; return 0; }
tmp=read(ram,r[13],4);
r[13]=tmp;
goto P_0c074b20;
P_0c074b20: /* original 8f02, guest PC 0x0c074b20 */
if(!s->budget--) { s->failed_pc=0x0c074b20u; return 0; }
cond=r[17]&1u;
r[8]=0x00000000u;
if(!cond) { goto P_0c074b28; }
goto P_0c074b24;
P_0c074b22: /* original e800, guest PC 0x0c074b22 */
if(!s->budget--) { s->failed_pc=0x0c074b22u; return 0; }
r[8]=0x00000000u;
goto P_0c074b24;
P_0c074b24: /* original a0d6, guest PC 0x0c074b24 */
if(!s->budget--) { s->failed_pc=0x0c074b24u; return 0; }
goto P_0c074cd4;
P_0c074b26: /* original 0009, guest PC 0x0c074b26 */
if(!s->budget--) { s->failed_pc=0x0c074b26u; return 0; }
goto P_0c074b28;
P_0c074b28: /* original e048, guest PC 0x0c074b28 */
if(!s->budget--) { s->failed_pc=0x0c074b28u; return 0; }
r[0]=0x00000048u;
goto P_0c074b2a;
P_0c074b2a: /* original db2f, guest PC 0x0c074b2a */
if(!s->budget--) { s->failed_pc=0x0c074b2au; return 0; }
r[11]=read(ram,0x0c074be8u,4);
goto P_0c074b2c;
P_0c074b2c: /* original 0d5e, guest PC 0x0c074b2c */
if(!s->budget--) { s->failed_pc=0x0c074b2cu; return 0; }
r[13]=read(ram,r[5]+r[0],4);
goto P_0c074b2e;
P_0c074b2e: /* original 63d3, guest PC 0x0c074b2e */
if(!s->budget--) { s->failed_pc=0x0c074b2eu; return 0; }
r[3]=r[13];
goto P_0c074b30;
P_0c074b30: /* original 2398, guest PC 0x0c074b30 */
if(!s->budget--) { s->failed_pc=0x0c074b30u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c074b32;
P_0c074b32: /* original 8d1a, guest PC 0x0c074b32 */
if(!s->budget--) { s->failed_pc=0x0c074b32u; return 0; }
cond=r[17]&1u;
r[7]=r[6];
if(cond) { goto P_0c074b6a; }
goto P_0c074b36;
P_0c074b34: /* original 6763, guest PC 0x0c074b34 */
if(!s->budget--) { s->failed_pc=0x0c074b34u; return 0; }
r[7]=r[6];
goto P_0c074b36;
P_0c074b36: /* original e03e, guest PC 0x0c074b36 */
if(!s->budget--) { s->failed_pc=0x0c074b36u; return 0; }
r[0]=0x0000003eu;
goto P_0c074b38;
P_0c074b38: /* original 065d, guest PC 0x0c074b38 */
if(!s->budget--) { s->failed_pc=0x0c074b38u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c074b3a;
P_0c074b3a: /* original 904a, guest PC 0x0c074b3a */
if(!s->budget--) { s->failed_pc=0x0c074b3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074bd2u,2);
goto P_0c074b3c;
P_0c074b3c: /* original 666d, guest PC 0x0c074b3c */
if(!s->budget--) { s->failed_pc=0x0c074b3cu; return 0; }
r[6]=r[6]&65535u;
goto P_0c074b3e;
P_0c074b3e: /* original 035d, guest PC 0x0c074b3e */
if(!s->budget--) { s->failed_pc=0x0c074b3eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c074b40;
P_0c074b40: /* original 4600, guest PC 0x0c074b40 */
if(!s->budget--) { s->failed_pc=0x0c074b40u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c074b42;
P_0c074b42: /* original 633d, guest PC 0x0c074b42 */
if(!s->budget--) { s->failed_pc=0x0c074b42u; return 0; }
r[3]=r[3]&65535u;
goto P_0c074b44;
P_0c074b44: /* original 3636, guest PC 0x0c074b44 */
if(!s->budget--) { s->failed_pc=0x0c074b44u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>r[3])!=0);
goto P_0c074b46;
P_0c074b46: /* original 8d10, guest PC 0x0c074b46 */
if(!s->budget--) { s->failed_pc=0x0c074b46u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(cond) { goto P_0c074b6a; }
goto P_0c074b4a;
P_0c074b48: /* original 2f32, guest PC 0x0c074b48 */
if(!s->budget--) { s->failed_pc=0x0c074b48u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c074b4a;
P_0c074b4a: /* original 9043, guest PC 0x0c074b4a */
if(!s->budget--) { s->failed_pc=0x0c074b4au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074bd4u,2);
goto P_0c074b4c;
P_0c074b4c: /* original 9343, guest PC 0x0c074b4c */
if(!s->budget--) { s->failed_pc=0x0c074b4cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074bd6u,2);
goto P_0c074b4e;
P_0c074b4e: /* original 065d, guest PC 0x0c074b4e */
if(!s->budget--) { s->failed_pc=0x0c074b4eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c074b50;
P_0c074b50: /* original 3637, guest PC 0x0c074b50 */
if(!s->budget--) { s->failed_pc=0x0c074b50u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[3])!=0);
goto P_0c074b52;
P_0c074b52: /* original 8b02, guest PC 0x0c074b52 */
if(!s->budget--) { s->failed_pc=0x0c074b52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074b5a; }
goto P_0c074b54;
P_0c074b54: /* original 9240, guest PC 0x0c074b54 */
if(!s->budget--) { s->failed_pc=0x0c074b54u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074bd8u,2);
goto P_0c074b56;
P_0c074b56: /* original 3623, guest PC 0x0c074b56 */
if(!s->budget--) { s->failed_pc=0x0c074b56u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[2])!=0);
goto P_0c074b58;
P_0c074b58: /* original 8b07, guest PC 0x0c074b58 */
if(!s->budget--) { s->failed_pc=0x0c074b58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074b6a; }
goto P_0c074b5a;
P_0c074b5a: /* original d324, guest PC 0x0c074b5a */
if(!s->budget--) { s->failed_pc=0x0c074b5au; return 0; }
r[3]=read(ram,0x0c074becu,4);
goto P_0c074b5c;
P_0c074b5c: /* original e048, guest PC 0x0c074b5c */
if(!s->budget--) { s->failed_pc=0x0c074b5cu; return 0; }
r[0]=0x00000048u;
goto P_0c074b5e;
P_0c074b5e: /* original 2d39, guest PC 0x0c074b5e */
if(!s->budget--) { s->failed_pc=0x0c074b5eu; return 0; }
r[13]&=r[3];
goto P_0c074b60;
P_0c074b60: /* original 05d6, guest PC 0x0c074b60 */
if(!s->budget--) { s->failed_pc=0x0c074b60u; return 0; }
write(ram,r[5]+r[0],r[13],4);
goto P_0c074b62;
P_0c074b62: /* original e050, guest PC 0x0c074b62 */
if(!s->budget--) { s->failed_pc=0x0c074b62u; return 0; }
r[0]=0x00000050u;
goto P_0c074b64;
P_0c074b64: /* original 025e, guest PC 0x0c074b64 */
if(!s->budget--) { s->failed_pc=0x0c074b64u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c074b66;
P_0c074b66: /* original 22ba, guest PC 0x0c074b66 */
if(!s->budget--) { s->failed_pc=0x0c074b66u; return 0; }
r[2]^=r[11];
goto P_0c074b68;
P_0c074b68: /* original 0526, guest PC 0x0c074b68 */
if(!s->budget--) { s->failed_pc=0x0c074b68u; return 0; }
write(ram,r[5]+r[0],r[2],4);
goto P_0c074b6a;
P_0c074b6a: /* original e320, guest PC 0x0c074b6a */
if(!s->budget--) { s->failed_pc=0x0c074b6au; return 0; }
r[3]=0x00000020u;
goto P_0c074b6c;
P_0c074b6c: /* original 23d8, guest PC 0x0c074b6c */
if(!s->budget--) { s->failed_pc=0x0c074b6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c074b6e;
P_0c074b6e: /* original 891e, guest PC 0x0c074b6e */
if(!s->budget--) { s->failed_pc=0x0c074b6eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074bae; }
goto P_0c074b70;
P_0c074b70: /* original 9033, guest PC 0x0c074b70 */
if(!s->budget--) { s->failed_pc=0x0c074b70u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074bdau,2);
goto P_0c074b72;
P_0c074b72: /* original f28d, guest PC 0x0c074b72 */
if(!s->budget--) { s->failed_pc=0x0c074b72u; return 0; }
fr[2]=0;
goto P_0c074b74;
P_0c074b74: /* original 064d, guest PC 0x0c074b74 */
if(!s->budget--) { s->failed_pc=0x0c074b74u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c074b76;
P_0c074b76: /* original 854f, guest PC 0x0c074b76 */
if(!s->budget--) { s->failed_pc=0x0c074b76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c074b78;
P_0c074b78: /* original d71d, guest PC 0x0c074b78 */
if(!s->budget--) { s->failed_pc=0x0c074b78u; return 0; }
r[7]=read(ram,0x0c074bf0u,4);
goto P_0c074b7a;
P_0c074b7a: /* original 360c, guest PC 0x0c074b7a */
if(!s->budget--) { s->failed_pc=0x0c074b7au; return 0; }
r[6]+=r[0];
goto P_0c074b7c;
P_0c074b7c: /* original 902e, guest PC 0x0c074b7c */
if(!s->budget--) { s->failed_pc=0x0c074b7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074bdcu,2);
goto P_0c074b7e;
P_0c074b7e: /* original 035d, guest PC 0x0c074b7e */
if(!s->budget--) { s->failed_pc=0x0c074b7eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c074b80;
P_0c074b80: /* original 902d, guest PC 0x0c074b80 */
if(!s->budget--) { s->failed_pc=0x0c074b80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074bdeu,2);
goto P_0c074b82;
P_0c074b82: /* original 3638, guest PC 0x0c074b82 */
if(!s->budget--) { s->failed_pc=0x0c074b82u; return 0; }
r[6]-=r[3];
goto P_0c074b84;
P_0c074b84: /* original 9328, guest PC 0x0c074b84 */
if(!s->budget--) { s->failed_pc=0x0c074b84u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074bd8u,2);
goto P_0c074b86;
P_0c074b86: /* original 025d, guest PC 0x0c074b86 */
if(!s->budget--) { s->failed_pc=0x0c074b86u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c074b88;
P_0c074b88: /* original 363c, guest PC 0x0c074b88 */
if(!s->budget--) { s->failed_pc=0x0c074b88u; return 0; }
r[6]+=r[3];
goto P_0c074b8a;
P_0c074b8a: /* original 622d, guest PC 0x0c074b8a */
if(!s->budget--) { s->failed_pc=0x0c074b8au; return 0; }
r[2]=r[2]&65535u;
goto P_0c074b8c;
P_0c074b8c: /* original 425a, guest PC 0x0c074b8c */
if(!s->budget--) { s->failed_pc=0x0c074b8cu; return 0; }
r[53]=r[2];
goto P_0c074b8e;
P_0c074b8e: /* original 4628, guest PC 0x0c074b8e */
if(!s->budget--) { s->failed_pc=0x0c074b8eu; return 0; }
r[6]<<=16;
goto P_0c074b90;
P_0c074b90: /* original 6463, guest PC 0x0c074b90 */
if(!s->budget--) { s->failed_pc=0x0c074b90u; return 0; }
r[4]=r[6];
goto P_0c074b92;
P_0c074b92: /* original f32d, guest PC 0x0c074b92 */
if(!s->budget--) { s->failed_pc=0x0c074b92u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c074b94;
P_0c074b94: /* original f235, guest PC 0x0c074b94 */
if(!s->budget--) { s->failed_pc=0x0c074b94u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c074b96;
P_0c074b96: /* original 8f04, guest PC 0x0c074b96 */
if(!s->budget--) { s->failed_pc=0x0c074b96u; return 0; }
cond=r[17]&1u;
r[4]&=r[11];
if(!cond) { goto P_0c074ba2; }
goto P_0c074b9a;
P_0c074b98: /* original 24b9, guest PC 0x0c074b98 */
if(!s->budget--) { s->failed_pc=0x0c074b98u; return 0; }
r[4]&=r[11];
goto P_0c074b9a;
P_0c074b9a: /* original 2448, guest PC 0x0c074b9a */
if(!s->budget--) { s->failed_pc=0x0c074b9au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c074b9c;
P_0c074b9c: /* original 8b05, guest PC 0x0c074b9c */
if(!s->budget--) { s->failed_pc=0x0c074b9cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074baa; }
goto P_0c074b9e;
P_0c074b9e: /* original a002, guest PC 0x0c074b9e */
if(!s->budget--) { s->failed_pc=0x0c074b9eu; return 0; }
goto P_0c074ba6;
P_0c074ba0: /* original 0009, guest PC 0x0c074ba0 */
if(!s->budget--) { s->failed_pc=0x0c074ba0u; return 0; }
goto P_0c074ba2;
P_0c074ba2: /* original 2448, guest PC 0x0c074ba2 */
if(!s->budget--) { s->failed_pc=0x0c074ba2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c074ba4;
P_0c074ba4: /* original 8901, guest PC 0x0c074ba4 */
if(!s->budget--) { s->failed_pc=0x0c074ba4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074baa; }
goto P_0c074ba6;
P_0c074ba6: /* original a12b, guest PC 0x0c074ba6 */
if(!s->budget--) { s->failed_pc=0x0c074ba6u; return 0; }
r[14]=read(ram,r[7]+4,4);
goto P_0c074e00;
P_0c074ba8: /* original 5e71, guest PC 0x0c074ba8 */
if(!s->budget--) { s->failed_pc=0x0c074ba8u; return 0; }
r[14]=read(ram,r[7]+4,4);
goto P_0c074baa;
P_0c074baa: /* original a129, guest PC 0x0c074baa */
if(!s->budget--) { s->failed_pc=0x0c074baau; return 0; }
tmp=read(ram,r[7],4);
r[14]=tmp;
goto P_0c074e00;
P_0c074bac: /* original 6e72, guest PC 0x0c074bac */
if(!s->budget--) { s->failed_pc=0x0c074bacu; return 0; }
tmp=read(ram,r[7],4);
r[14]=tmp;
goto P_0c074bae;
P_0c074bae: /* original e04c, guest PC 0x0c074bae */
if(!s->budget--) { s->failed_pc=0x0c074baeu; return 0; }
r[0]=0x0000004cu;
goto P_0c074bb0;
P_0c074bb0: /* original 9316, guest PC 0x0c074bb0 */
if(!s->budget--) { s->failed_pc=0x0c074bb0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074be0u,2);
goto P_0c074bb2;
P_0c074bb2: /* original 025e, guest PC 0x0c074bb2 */
if(!s->budget--) { s->failed_pc=0x0c074bb2u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c074bb4;
P_0c074bb4: /* original 2238, guest PC 0x0c074bb4 */
if(!s->budget--) { s->failed_pc=0x0c074bb4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c074bb6;
P_0c074bb6: /* original 891f, guest PC 0x0c074bb6 */
if(!s->budget--) { s->failed_pc=0x0c074bb6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074bf8; }
goto P_0c074bb8;
P_0c074bb8: /* original e050, guest PC 0x0c074bb8 */
if(!s->budget--) { s->failed_pc=0x0c074bb8u; return 0; }
r[0]=0x00000050u;
goto P_0c074bba;
P_0c074bba: /* original 065e, guest PC 0x0c074bba */
if(!s->budget--) { s->failed_pc=0x0c074bbau; return 0; }
r[6]=read(ram,r[5]+r[0],4);
goto P_0c074bbc;
P_0c074bbc: /* original 26b8, guest PC 0x0c074bbc */
if(!s->budget--) { s->failed_pc=0x0c074bbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[11])==0)!=0);
goto P_0c074bbe;
P_0c074bbe: /* original 8d01, guest PC 0x0c074bbe */
if(!s->budget--) { s->failed_pc=0x0c074bbeu; return 0; }
cond=r[17]&1u;
r[4]=r[8];
if(cond) { goto P_0c074bc4; }
goto P_0c074bc2;
P_0c074bc0: /* original 6483, guest PC 0x0c074bc0 */
if(!s->budget--) { s->failed_pc=0x0c074bc0u; return 0; }
r[4]=r[8];
goto P_0c074bc2;
P_0c074bc2: /* original 7401, guest PC 0x0c074bc2 */
if(!s->budget--) { s->failed_pc=0x0c074bc2u; return 0; }
r[4]+=0x00000001u;
goto P_0c074bc4;
P_0c074bc4: /* original d00b, guest PC 0x0c074bc4 */
if(!s->budget--) { s->failed_pc=0x0c074bc4u; return 0; }
r[0]=read(ram,0x0c074bf4u,4);
goto P_0c074bc6;
P_0c074bc6: /* original 6e43, guest PC 0x0c074bc6 */
if(!s->budget--) { s->failed_pc=0x0c074bc6u; return 0; }
r[14]=r[4];
goto P_0c074bc8;
P_0c074bc8: /* original 4e08, guest PC 0x0c074bc8 */
if(!s->budget--) { s->failed_pc=0x0c074bc8u; return 0; }
r[14]<<=2;
goto P_0c074bca;
P_0c074bca: /* original a119, guest PC 0x0c074bca */
if(!s->budget--) { s->failed_pc=0x0c074bcau; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c074e00;
P_0c074bcc: /* original 0eee, guest PC 0x0c074bcc */
if(!s->budget--) { s->failed_pc=0x0c074bccu; return 0; }
r[14]=read(ram,r[14]+r[0],4);
return vf3_matrix_family(0x0c074bceu,s,ram);
P_0c074bf8: /* original 9061, guest PC 0x0c074bf8 */
if(!s->budget--) { s->failed_pc=0x0c074bf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074cbeu,2);
goto P_0c074bfa;
P_0c074bfa: /* original 0a4e, guest PC 0x0c074bfa */
if(!s->budget--) { s->failed_pc=0x0c074bfau; return 0; }
r[10]=read(ram,r[4]+r[0],4);
goto P_0c074bfc;
P_0c074bfc: /* original e061, guest PC 0x0c074bfc */
if(!s->budget--) { s->failed_pc=0x0c074bfcu; return 0; }
r[0]=0x00000061u;
goto P_0c074bfe;
P_0c074bfe: /* original 035c, guest PC 0x0c074bfe */
if(!s->budget--) { s->failed_pc=0x0c074bfeu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c074c00;
P_0c074c00: /* original 66ac, guest PC 0x0c074c00 */
if(!s->budget--) { s->failed_pc=0x0c074c00u; return 0; }
r[6]=r[10]&255u;
goto P_0c074c02;
P_0c074c02: /* original 633c, guest PC 0x0c074c02 */
if(!s->budget--) { s->failed_pc=0x0c074c02u; return 0; }
r[3]=r[3]&255u;
goto P_0c074c04;
P_0c074c04: /* original 6e63, guest PC 0x0c074c04 */
if(!s->budget--) { s->failed_pc=0x0c074c04u; return 0; }
r[14]=r[6];
goto P_0c074c06;
P_0c074c06: /* original 6033, guest PC 0x0c074c06 */
if(!s->budget--) { s->failed_pc=0x0c074c06u; return 0; }
r[0]=r[3];
goto P_0c074c08;
P_0c074c08: /* original 880c, guest PC 0x0c074c08 */
if(!s->budget--) { s->failed_pc=0x0c074c08u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c074c0a;
P_0c074c0a: /* original 2f32, guest PC 0x0c074c0a */
if(!s->budget--) { s->failed_pc=0x0c074c0au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c074c0c;
P_0c074c0c: /* original 8f03, guest PC 0x0c074c0c */
if(!s->budget--) { s->failed_pc=0x0c074c0cu; return 0; }
cond=r[17]&1u;
r[14]<<=2;
if(!cond) { goto P_0c074c16; }
goto P_0c074c10;
P_0c074c0e: /* original 4e08, guest PC 0x0c074c0e */
if(!s->budget--) { s->failed_pc=0x0c074c0eu; return 0; }
r[14]<<=2;
goto P_0c074c10;
P_0c074c10: /* original d02b, guest PC 0x0c074c10 */
if(!s->budget--) { s->failed_pc=0x0c074c10u; return 0; }
r[0]=read(ram,0x0c074cc0u,4);
goto P_0c074c12;
P_0c074c12: /* original a001, guest PC 0x0c074c12 */
if(!s->budget--) { s->failed_pc=0x0c074c12u; return 0; }
goto P_0c074c18;
P_0c074c14: /* original 0009, guest PC 0x0c074c14 */
if(!s->budget--) { s->failed_pc=0x0c074c14u; return 0; }
goto P_0c074c16;
P_0c074c16: /* original d02b, guest PC 0x0c074c16 */
if(!s->budget--) { s->failed_pc=0x0c074c16u; return 0; }
r[0]=read(ram,0x0c074cc4u,4);
goto P_0c074c18;
P_0c074c18: /* original 02ee, guest PC 0x0c074c18 */
if(!s->budget--) { s->failed_pc=0x0c074c18u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c074c1a;
P_0c074c1a: /* original 6073, guest PC 0x0c074c1a */
if(!s->budget--) { s->failed_pc=0x0c074c1au; return 0; }
r[0]=r[7];
goto P_0c074c1c;
P_0c074c1c: /* original 8805, guest PC 0x0c074c1c */
if(!s->budget--) { s->failed_pc=0x0c074c1cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c074c1e;
P_0c074c1e: /* original 8f06, guest PC 0x0c074c1e */
if(!s->budget--) { s->failed_pc=0x0c074c1eu; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[2],4);
if(!cond) { goto P_0c074c2e; }
goto P_0c074c22;
P_0c074c20: /* original 2f22, guest PC 0x0c074c20 */
if(!s->budget--) { s->failed_pc=0x0c074c20u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c074c22;
P_0c074c22: /* original d229, guest PC 0x0c074c22 */
if(!s->budget--) { s->failed_pc=0x0c074c22u; return 0; }
r[2]=read(ram,0x0c074cc8u,4);
goto P_0c074c24;
P_0c074c24: /* original 22d8, guest PC 0x0c074c24 */
if(!s->budget--) { s->failed_pc=0x0c074c24u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c074c26;
P_0c074c26: /* original 8d26, guest PC 0x0c074c26 */
if(!s->budget--) { s->failed_pc=0x0c074c26u; return 0; }
cond=r[17]&1u;
r[14]=0x00000028u;
if(cond) { goto P_0c074c76; }
goto P_0c074c2a;
P_0c074c28: /* original ee28, guest PC 0x0c074c28 */
if(!s->budget--) { s->failed_pc=0x0c074c28u; return 0; }
r[14]=0x00000028u;
goto P_0c074c2a;
P_0c074c2a: /* original a024, guest PC 0x0c074c2a */
if(!s->budget--) { s->failed_pc=0x0c074c2au; return 0; }
r[14]=0x0000002au;
goto P_0c074c76;
P_0c074c2c: /* original ee2a, guest PC 0x0c074c2c */
if(!s->budget--) { s->failed_pc=0x0c074c2cu; return 0; }
r[14]=0x0000002au;
goto P_0c074c2e;
P_0c074c2e: /* original 6073, guest PC 0x0c074c2e */
if(!s->budget--) { s->failed_pc=0x0c074c2eu; return 0; }
r[0]=r[7];
goto P_0c074c30;
P_0c074c30: /* original 8806, guest PC 0x0c074c30 */
if(!s->budget--) { s->failed_pc=0x0c074c30u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c074c32;
P_0c074c32: /* original 8f01, guest PC 0x0c074c32 */
if(!s->budget--) { s->failed_pc=0x0c074c32u; return 0; }
cond=r[17]&1u;
r[14]=r[8];
if(!cond) { goto P_0c074c38; }
goto P_0c074c36;
P_0c074c34: /* original 6e83, guest PC 0x0c074c34 */
if(!s->budget--) { s->failed_pc=0x0c074c34u; return 0; }
r[14]=r[8];
goto P_0c074c36;
P_0c074c36: /* original e702, guest PC 0x0c074c36 */
if(!s->budget--) { s->failed_pc=0x0c074c36u; return 0; }
r[7]=0x00000002u;
goto P_0c074c38;
P_0c074c38: /* original d224, guest PC 0x0c074c38 */
if(!s->budget--) { s->failed_pc=0x0c074c38u; return 0; }
r[2]=read(ram,0x0c074cccu,4);
goto P_0c074c3a;
P_0c074c3a: /* original 22d8, guest PC 0x0c074c3a */
if(!s->budget--) { s->failed_pc=0x0c074c3au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c074c3c;
P_0c074c3c: /* original 8d01, guest PC 0x0c074c3c */
if(!s->budget--) { s->failed_pc=0x0c074c3cu; return 0; }
cond=r[17]&1u;
r[0]=r[10];
if(cond) { goto P_0c074c42; }
goto P_0c074c40;
P_0c074c3e: /* original 60a3, guest PC 0x0c074c3e */
if(!s->budget--) { s->failed_pc=0x0c074c3eu; return 0; }
r[0]=r[10];
goto P_0c074c40;
P_0c074c40: /* original ee04, guest PC 0x0c074c40 */
if(!s->budget--) { s->failed_pc=0x0c074c40u; return 0; }
r[14]=0x00000004u;
goto P_0c074c42;
P_0c074c42: /* original 6352, guest PC 0x0c074c42 */
if(!s->budget--) { s->failed_pc=0x0c074c42u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c074c44;
P_0c074c44: /* original 4004, guest PC 0x0c074c44 */
if(!s->budget--) { s->failed_pc=0x0c074c44u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]=(r[0]<<1)|(r[0]>>31);
goto P_0c074c46;
P_0c074c46: /* original 6642, guest PC 0x0c074c46 */
if(!s->budget--) { s->failed_pc=0x0c074c46u; return 0; }
tmp=read(ram,r[4],4);
r[6]=tmp;
goto P_0c074c48;
P_0c074c48: /* original c901, guest PC 0x0c074c48 */
if(!s->budget--) { s->failed_pc=0x0c074c48u; return 0; }
r[0]&=1u;
goto P_0c074c4a;
P_0c074c4a: /* original 6c03, guest PC 0x0c074c4a */
if(!s->budget--) { s->failed_pc=0x0c074c4au; return 0; }
r[12]=r[0];
goto P_0c074c4c;
P_0c074c4c: /* original e050, guest PC 0x0c074c4c */
if(!s->budget--) { s->failed_pc=0x0c074c4cu; return 0; }
r[0]=0x00000050u;
goto P_0c074c4e;
P_0c074c4e: /* original 263a, guest PC 0x0c074c4e */
if(!s->budget--) { s->failed_pc=0x0c074c4eu; return 0; }
r[6]^=r[3];
goto P_0c074c50;
P_0c074c50: /* original 035e, guest PC 0x0c074c50 */
if(!s->budget--) { s->failed_pc=0x0c074c50u; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c074c52;
P_0c074c52: /* original 4629, guest PC 0x0c074c52 */
if(!s->budget--) { s->failed_pc=0x0c074c52u; return 0; }
r[6]>>=16;
goto P_0c074c54;
P_0c074c54: /* original 4619, guest PC 0x0c074c54 */
if(!s->budget--) { s->failed_pc=0x0c074c54u; return 0; }
r[6]>>=8;
goto P_0c074c56;
P_0c074c56: /* original 4601, guest PC 0x0c074c56 */
if(!s->budget--) { s->failed_pc=0x0c074c56u; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c074c58;
P_0c074c58: /* original 2c6a, guest PC 0x0c074c58 */
if(!s->budget--) { s->failed_pc=0x0c074c58u; return 0; }
r[12]^=r[6];
goto P_0c074c5a;
P_0c074c5a: /* original 66d3, guest PC 0x0c074c5a */
if(!s->budget--) { s->failed_pc=0x0c074c5au; return 0; }
r[6]=r[13];
goto P_0c074c5c;
P_0c074c5c: /* original 4619, guest PC 0x0c074c5c */
if(!s->budget--) { s->failed_pc=0x0c074c5cu; return 0; }
r[6]>>=8;
goto P_0c074c5e;
P_0c074c5e: /* original 4609, guest PC 0x0c074c5e */
if(!s->budget--) { s->failed_pc=0x0c074c5eu; return 0; }
r[6]>>=2;
goto P_0c074c60;
P_0c074c60: /* original 2c6a, guest PC 0x0c074c60 */
if(!s->budget--) { s->failed_pc=0x0c074c60u; return 0; }
r[12]^=r[6];
goto P_0c074c62;
P_0c074c62: /* original e201, guest PC 0x0c074c62 */
if(!s->budget--) { s->failed_pc=0x0c074c62u; return 0; }
r[2]=0x00000001u;
goto P_0c074c64;
P_0c074c64: /* original 23b8, guest PC 0x0c074c64 */
if(!s->budget--) { s->failed_pc=0x0c074c64u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c074c66;
P_0c074c66: /* original 2c29, guest PC 0x0c074c66 */
if(!s->budget--) { s->failed_pc=0x0c074c66u; return 0; }
r[12]&=r[2];
goto P_0c074c68;
P_0c074c68: /* original 8d01, guest PC 0x0c074c68 */
if(!s->budget--) { s->failed_pc=0x0c074c68u; return 0; }
cond=r[17]&1u;
r[14]+=r[12];
if(cond) { goto P_0c074c6e; }
goto P_0c074c6c;
P_0c074c6a: /* original 3ecc, guest PC 0x0c074c6a */
if(!s->budget--) { s->failed_pc=0x0c074c6au; return 0; }
r[14]+=r[12];
goto P_0c074c6c;
P_0c074c6c: /* original 7e02, guest PC 0x0c074c6c */
if(!s->budget--) { s->failed_pc=0x0c074c6cu; return 0; }
r[14]+=0x00000002u;
goto P_0c074c6e;
P_0c074c6e: /* original 6673, guest PC 0x0c074c6e */
if(!s->budget--) { s->failed_pc=0x0c074c6eu; return 0; }
r[6]=r[7];
goto P_0c074c70;
P_0c074c70: /* original 4608, guest PC 0x0c074c70 */
if(!s->budget--) { s->failed_pc=0x0c074c70u; return 0; }
r[6]<<=2;
goto P_0c074c72;
P_0c074c72: /* original 4600, guest PC 0x0c074c72 */
if(!s->budget--) { s->failed_pc=0x0c074c72u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c074c74;
P_0c074c74: /* original 3e6c, guest PC 0x0c074c74 */
if(!s->budget--) { s->failed_pc=0x0c074c74u; return 0; }
r[14]+=r[6];
goto P_0c074c76;
P_0c074c76: /* original e340, guest PC 0x0c074c76 */
if(!s->budget--) { s->failed_pc=0x0c074c76u; return 0; }
r[3]=0x00000040u;
goto P_0c074c78;
P_0c074c78: /* original 66e3, guest PC 0x0c074c78 */
if(!s->budget--) { s->failed_pc=0x0c074c78u; return 0; }
r[6]=r[14];
goto P_0c074c7a;
P_0c074c7a: /* original 23d8, guest PC 0x0c074c7a */
if(!s->budget--) { s->failed_pc=0x0c074c7au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c074c7c;
P_0c074c7c: /* original 8d03, guest PC 0x0c074c7c */
if(!s->budget--) { s->failed_pc=0x0c074c7cu; return 0; }
cond=r[17]&1u;
r[6]<<=2;
if(cond) { goto P_0c074c86; }
goto P_0c074c80;
P_0c074c7e: /* original 4608, guest PC 0x0c074c7e */
if(!s->budget--) { s->failed_pc=0x0c074c7eu; return 0; }
r[6]<<=2;
goto P_0c074c80;
P_0c074c80: /* original d013, guest PC 0x0c074c80 */
if(!s->budget--) { s->failed_pc=0x0c074c80u; return 0; }
r[0]=read(ram,0x0c074cd0u,4);
goto P_0c074c82;
P_0c074c82: /* original a0bd, guest PC 0x0c074c82 */
if(!s->budget--) { s->failed_pc=0x0c074c82u; return 0; }
r[14]=read(ram,r[6]+r[0],4);
goto P_0c074e00;
P_0c074c84: /* original 0e6e, guest PC 0x0c074c84 */
if(!s->budget--) { s->failed_pc=0x0c074c84u; return 0; }
r[14]=read(ram,r[6]+r[0],4);
goto P_0c074c86;
P_0c074c86: /* original 60f2, guest PC 0x0c074c86 */
if(!s->budget--) { s->failed_pc=0x0c074c86u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c074c88;
P_0c074c88: /* original 0e6e, guest PC 0x0c074c88 */
if(!s->budget--) { s->failed_pc=0x0c074c88u; return 0; }
r[14]=read(ram,r[6]+r[0],4);
goto P_0c074c8a;
P_0c074c8a: /* original 6073, guest PC 0x0c074c8a */
if(!s->budget--) { s->failed_pc=0x0c074c8au; return 0; }
r[0]=r[7];
goto P_0c074c8c;
P_0c074c8c: /* original 8805, guest PC 0x0c074c8c */
if(!s->budget--) { s->failed_pc=0x0c074c8cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c074c8e;
P_0c074c8e: /* original 8b04, guest PC 0x0c074c8e */
if(!s->budget--) { s->failed_pc=0x0c074c8eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074c9a; }
goto P_0c074c90;
P_0c074c90: /* original 67e3, guest PC 0x0c074c90 */
if(!s->budget--) { s->failed_pc=0x0c074c90u; return 0; }
r[7]=r[14];
goto P_0c074c92;
P_0c074c92: /* original bef6, guest PC 0x0c074c92 */
if(!s->budget--) { s->failed_pc=0x0c074c92u; return 0; }
target=0x0c074a82u; r[16]=0x0c074c96u;
r[6]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074c96u) { target=s->pc; goto dispatch; }
goto P_0c074c96;
P_0c074c94: /* original 66d3, guest PC 0x0c074c94 */
if(!s->budget--) { s->failed_pc=0x0c074c94u; return 0; }
r[6]=r[13];
goto P_0c074c96;
P_0c074c96: /* original a0b3, guest PC 0x0c074c96 */
if(!s->budget--) { s->failed_pc=0x0c074c96u; return 0; }
r[14]=r[0];
goto P_0c074e00;
P_0c074c98: /* original 6e03, guest PC 0x0c074c98 */
if(!s->budget--) { s->failed_pc=0x0c074c98u; return 0; }
r[14]=r[0];
goto P_0c074c9a;
P_0c074c9a: /* original 8804, guest PC 0x0c074c9a */
if(!s->budget--) { s->failed_pc=0x0c074c9au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c074c9c;
P_0c074c9c: /* original 8b08, guest PC 0x0c074c9c */
if(!s->budget--) { s->failed_pc=0x0c074c9cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074cb0; }
goto P_0c074c9e;
P_0c074c9e: /* original e050, guest PC 0x0c074c9e */
if(!s->budget--) { s->failed_pc=0x0c074c9eu; return 0; }
r[0]=0x00000050u;
goto P_0c074ca0;
P_0c074ca0: /* original 025e, guest PC 0x0c074ca0 */
if(!s->budget--) { s->failed_pc=0x0c074ca0u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c074ca2;
P_0c074ca2: /* original 2b28, guest PC 0x0c074ca2 */
if(!s->budget--) { s->failed_pc=0x0c074ca2u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[2])==0)!=0);
goto P_0c074ca4;
P_0c074ca4: /* original 8904, guest PC 0x0c074ca4 */
if(!s->budget--) { s->failed_pc=0x0c074ca4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074cb0; }
goto P_0c074ca6;
P_0c074ca6: /* original 67e3, guest PC 0x0c074ca6 */
if(!s->budget--) { s->failed_pc=0x0c074ca6u; return 0; }
r[7]=r[14];
goto P_0c074ca8;
P_0c074ca8: /* original bf1e, guest PC 0x0c074ca8 */
if(!s->budget--) { s->failed_pc=0x0c074ca8u; return 0; }
target=0x0c074ae8u; r[16]=0x0c074cacu;
r[6]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074cacu) { target=s->pc; goto dispatch; }
goto P_0c074cac;
P_0c074caa: /* original 66a3, guest PC 0x0c074caa */
if(!s->budget--) { s->failed_pc=0x0c074caau; return 0; }
r[6]=r[10];
goto P_0c074cac;
P_0c074cac: /* original aff3, guest PC 0x0c074cac */
if(!s->budget--) { s->failed_pc=0x0c074cacu; return 0; }
goto P_0c074c96;
P_0c074cae: /* original 0009, guest PC 0x0c074cae */
if(!s->budget--) { s->failed_pc=0x0c074caeu; return 0; }
goto P_0c074cb0;
P_0c074cb0: /* original 2778, guest PC 0x0c074cb0 */
if(!s->budget--) { s->failed_pc=0x0c074cb0u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c074cb2;
P_0c074cb2: /* original 8b0f, guest PC 0x0c074cb2 */
if(!s->budget--) { s->failed_pc=0x0c074cb2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074cd4; }
goto P_0c074cb4;
P_0c074cb4: /* original 67a3, guest PC 0x0c074cb4 */
if(!s->budget--) { s->failed_pc=0x0c074cb4u; return 0; }
r[7]=r[10];
goto P_0c074cb6;
P_0c074cb6: /* original be3b, guest PC 0x0c074cb6 */
if(!s->budget--) { s->failed_pc=0x0c074cb6u; return 0; }
target=0x0c074930u; r[16]=0x0c074cbau;
r[6]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074cbau) { target=s->pc; goto dispatch; }
goto P_0c074cba;
P_0c074cb8: /* original 66e3, guest PC 0x0c074cb8 */
if(!s->budget--) { s->failed_pc=0x0c074cb8u; return 0; }
r[6]=r[14];
goto P_0c074cba;
P_0c074cba: /* original afec, guest PC 0x0c074cba */
if(!s->budget--) { s->failed_pc=0x0c074cbau; return 0; }
goto P_0c074c96;
P_0c074cbc: /* original 0009, guest PC 0x0c074cbc */
if(!s->budget--) { s->failed_pc=0x0c074cbcu; return 0; }
return vf3_matrix_family(0x0c074cbeu,s,ram);
P_0c074cd4: /* original 915d, guest PC 0x0c074cd4 */
if(!s->budget--) { s->failed_pc=0x0c074cd4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074d92u,2);
goto P_0c074cd6;
P_0c074cd6: /* original 60e3, guest PC 0x0c074cd6 */
if(!s->budget--) { s->failed_pc=0x0c074cd6u; return 0; }
r[0]=r[14];
goto P_0c074cd8;
P_0c074cd8: /* original 3010, guest PC 0x0c074cd8 */
if(!s->budget--) { s->failed_pc=0x0c074cd8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c074cda;
P_0c074cda: /* original 891b, guest PC 0x0c074cda */
if(!s->budget--) { s->failed_pc=0x0c074cdau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074d14; }
goto P_0c074cdc;
P_0c074cdc: /* original 915a, guest PC 0x0c074cdc */
if(!s->budget--) { s->failed_pc=0x0c074cdcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074d94u,2);
goto P_0c074cde;
P_0c074cde: /* original 3010, guest PC 0x0c074cde */
if(!s->budget--) { s->failed_pc=0x0c074cdeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c074ce0;
P_0c074ce0: /* original 891c, guest PC 0x0c074ce0 */
if(!s->budget--) { s->failed_pc=0x0c074ce0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074d1c; }
goto P_0c074ce2;
P_0c074ce2: /* original 9158, guest PC 0x0c074ce2 */
if(!s->budget--) { s->failed_pc=0x0c074ce2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074d96u,2);
goto P_0c074ce4;
P_0c074ce4: /* original 3010, guest PC 0x0c074ce4 */
if(!s->budget--) { s->failed_pc=0x0c074ce4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c074ce6;
P_0c074ce6: /* original 8911, guest PC 0x0c074ce6 */
if(!s->budget--) { s->failed_pc=0x0c074ce6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074d0c; }
goto P_0c074ce8;
P_0c074ce8: /* original 9156, guest PC 0x0c074ce8 */
if(!s->budget--) { s->failed_pc=0x0c074ce8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074d98u,2);
goto P_0c074cea;
P_0c074cea: /* original 3010, guest PC 0x0c074cea */
if(!s->budget--) { s->failed_pc=0x0c074ceau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c074cec;
P_0c074cec: /* original 8b01, guest PC 0x0c074cec */
if(!s->budget--) { s->failed_pc=0x0c074cecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074cf2; }
goto P_0c074cee;
P_0c074cee: /* original a087, guest PC 0x0c074cee */
if(!s->budget--) { s->failed_pc=0x0c074ceeu; return 0; }
goto P_0c074e00;
P_0c074cf0: /* original 0009, guest PC 0x0c074cf0 */
if(!s->budget--) { s->failed_pc=0x0c074cf0u; return 0; }
goto P_0c074cf2;
P_0c074cf2: /* original 9152, guest PC 0x0c074cf2 */
if(!s->budget--) { s->failed_pc=0x0c074cf2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074d9au,2);
goto P_0c074cf4;
P_0c074cf4: /* original 3010, guest PC 0x0c074cf4 */
if(!s->budget--) { s->failed_pc=0x0c074cf4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c074cf6;
P_0c074cf6: /* original 890d, guest PC 0x0c074cf6 */
if(!s->budget--) { s->failed_pc=0x0c074cf6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074d14; }
goto P_0c074cf8;
P_0c074cf8: /* original 9150, guest PC 0x0c074cf8 */
if(!s->budget--) { s->failed_pc=0x0c074cf8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074d9cu,2);
goto P_0c074cfa;
P_0c074cfa: /* original 3010, guest PC 0x0c074cfa */
if(!s->budget--) { s->failed_pc=0x0c074cfau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c074cfc;
P_0c074cfc: /* original 8906, guest PC 0x0c074cfc */
if(!s->budget--) { s->failed_pc=0x0c074cfcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074d0c; }
goto P_0c074cfe;
P_0c074cfe: /* original 914e, guest PC 0x0c074cfe */
if(!s->budget--) { s->failed_pc=0x0c074cfeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074d9eu,2);
goto P_0c074d00;
P_0c074d00: /* original 3010, guest PC 0x0c074d00 */
if(!s->budget--) { s->failed_pc=0x0c074d00u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c074d02;
P_0c074d02: /* original 8b01, guest PC 0x0c074d02 */
if(!s->budget--) { s->failed_pc=0x0c074d02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074d08; }
goto P_0c074d04;
P_0c074d04: /* original a07c, guest PC 0x0c074d04 */
if(!s->budget--) { s->failed_pc=0x0c074d04u; return 0; }
goto P_0c074e00;
P_0c074d06: /* original 0009, guest PC 0x0c074d06 */
if(!s->budget--) { s->failed_pc=0x0c074d06u; return 0; }
goto P_0c074d08;
P_0c074d08: /* original a00c, guest PC 0x0c074d08 */
if(!s->budget--) { s->failed_pc=0x0c074d08u; return 0; }
goto P_0c074d24;
P_0c074d0a: /* original 0009, guest PC 0x0c074d0a */
if(!s->budget--) { s->failed_pc=0x0c074d0au; return 0; }
goto P_0c074d0c;
P_0c074d0c: /* original bead, guest PC 0x0c074d0c */
if(!s->budget--) { s->failed_pc=0x0c074d0cu; return 0; }
target=0x0c074a6au; r[16]=0x0c074d10u;
r[6]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074d10u) { target=s->pc; goto dispatch; }
goto P_0c074d10;
P_0c074d0e: /* original 66e3, guest PC 0x0c074d0e */
if(!s->budget--) { s->failed_pc=0x0c074d0eu; return 0; }
r[6]=r[14];
goto P_0c074d10;
P_0c074d10: /* original afc1, guest PC 0x0c074d10 */
if(!s->budget--) { s->failed_pc=0x0c074d10u; return 0; }
goto P_0c074c96;
P_0c074d12: /* original 0009, guest PC 0x0c074d12 */
if(!s->budget--) { s->failed_pc=0x0c074d12u; return 0; }
goto P_0c074d14;
P_0c074d14: /* original be91, guest PC 0x0c074d14 */
if(!s->budget--) { s->failed_pc=0x0c074d14u; return 0; }
target=0x0c074a3au; r[16]=0x0c074d18u;
r[6]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074d18u) { target=s->pc; goto dispatch; }
goto P_0c074d18;
P_0c074d16: /* original 66e3, guest PC 0x0c074d16 */
if(!s->budget--) { s->failed_pc=0x0c074d16u; return 0; }
r[6]=r[14];
goto P_0c074d18;
P_0c074d18: /* original afbd, guest PC 0x0c074d18 */
if(!s->budget--) { s->failed_pc=0x0c074d18u; return 0; }
goto P_0c074c96;
P_0c074d1a: /* original 0009, guest PC 0x0c074d1a */
if(!s->budget--) { s->failed_pc=0x0c074d1au; return 0; }
goto P_0c074d1c;
P_0c074d1c: /* original be99, guest PC 0x0c074d1c */
if(!s->budget--) { s->failed_pc=0x0c074d1cu; return 0; }
target=0x0c074a52u; r[16]=0x0c074d20u;
r[6]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074d20u) { target=s->pc; goto dispatch; }
goto P_0c074d20;
P_0c074d1e: /* original 66e3, guest PC 0x0c074d1e */
if(!s->budget--) { s->failed_pc=0x0c074d1eu; return 0; }
r[6]=r[14];
goto P_0c074d20;
P_0c074d20: /* original afb9, guest PC 0x0c074d20 */
if(!s->budget--) { s->failed_pc=0x0c074d20u; return 0; }
goto P_0c074c96;
P_0c074d22: /* original 0009, guest PC 0x0c074d22 */
if(!s->budget--) { s->failed_pc=0x0c074d22u; return 0; }
goto P_0c074d24;
P_0c074d24: /* original e061, guest PC 0x0c074d24 */
if(!s->budget--) { s->failed_pc=0x0c074d24u; return 0; }
r[0]=0x00000061u;
goto P_0c074d26;
P_0c074d26: /* original 065c, guest PC 0x0c074d26 */
if(!s->budget--) { s->failed_pc=0x0c074d26u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c074d28;
P_0c074d28: /* original 606c, guest PC 0x0c074d28 */
if(!s->budget--) { s->failed_pc=0x0c074d28u; return 0; }
r[0]=r[6]&255u;
goto P_0c074d2a;
P_0c074d2a: /* original 880b, guest PC 0x0c074d2a */
if(!s->budget--) { s->failed_pc=0x0c074d2au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c074d2c;
P_0c074d2c: /* original 8f0e, guest PC 0x0c074d2c */
if(!s->budget--) { s->failed_pc=0x0c074d2cu; return 0; }
cond=r[17]&1u;
r[6]=r[0];
if(!cond) { goto P_0c074d4c; }
goto P_0c074d30;
P_0c074d2e: /* original 6603, guest PC 0x0c074d2e */
if(!s->budget--) { s->failed_pc=0x0c074d2eu; return 0; }
r[6]=r[0];
goto P_0c074d30;
P_0c074d30: /* original 9236, guest PC 0x0c074d30 */
if(!s->budget--) { s->failed_pc=0x0c074d30u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074da0u,2);
goto P_0c074d32;
P_0c074d32: /* original 3e20, guest PC 0x0c074d32 */
if(!s->budget--) { s->failed_pc=0x0c074d32u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c074d34;
P_0c074d34: /* original 8b03, guest PC 0x0c074d34 */
if(!s->budget--) { s->failed_pc=0x0c074d34u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074d3e; }
goto P_0c074d36;
P_0c074d36: /* original be7a, guest PC 0x0c074d36 */
if(!s->budget--) { s->failed_pc=0x0c074d36u; return 0; }
target=0x0c074a2eu; r[16]=0x0c074d3au;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074d3au) { target=s->pc; goto dispatch; }
goto P_0c074d3a;
P_0c074d38: /* original 0009, guest PC 0x0c074d38 */
if(!s->budget--) { s->failed_pc=0x0c074d38u; return 0; }
goto P_0c074d3a;
P_0c074d3a: /* original a061, guest PC 0x0c074d3a */
if(!s->budget--) { s->failed_pc=0x0c074d3au; return 0; }
r[14]=r[0];
goto P_0c074e00;
P_0c074d3c: /* original 6e03, guest PC 0x0c074d3c */
if(!s->budget--) { s->failed_pc=0x0c074d3cu; return 0; }
r[14]=r[0];
goto P_0c074d3e;
P_0c074d3e: /* original 9130, guest PC 0x0c074d3e */
if(!s->budget--) { s->failed_pc=0x0c074d3eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074da2u,2);
goto P_0c074d40;
P_0c074d40: /* original 3e10, guest PC 0x0c074d40 */
if(!s->budget--) { s->failed_pc=0x0c074d40u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[1])!=0);
goto P_0c074d42;
P_0c074d42: /* original 8b03, guest PC 0x0c074d42 */
if(!s->budget--) { s->failed_pc=0x0c074d42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074d4c; }
goto P_0c074d44;
P_0c074d44: /* original be76, guest PC 0x0c074d44 */
if(!s->budget--) { s->failed_pc=0x0c074d44u; return 0; }
target=0x0c074a34u; r[16]=0x0c074d48u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c074d48u) { target=s->pc; goto dispatch; }
goto P_0c074d48;
P_0c074d46: /* original 0009, guest PC 0x0c074d46 */
if(!s->budget--) { s->failed_pc=0x0c074d46u; return 0; }
goto P_0c074d48;
P_0c074d48: /* original a05a, guest PC 0x0c074d48 */
if(!s->budget--) { s->failed_pc=0x0c074d48u; return 0; }
r[14]=r[0];
goto P_0c074e00;
P_0c074d4a: /* original 6e03, guest PC 0x0c074d4a */
if(!s->budget--) { s->failed_pc=0x0c074d4au; return 0; }
r[14]=r[0];
goto P_0c074d4c;
P_0c074d4c: /* original e061, guest PC 0x0c074d4c */
if(!s->budget--) { s->failed_pc=0x0c074d4cu; return 0; }
r[0]=0x00000061u;
goto P_0c074d4e;
P_0c074d4e: /* original 065c, guest PC 0x0c074d4e */
if(!s->budget--) { s->failed_pc=0x0c074d4eu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c074d50;
P_0c074d50: /* original 606c, guest PC 0x0c074d50 */
if(!s->budget--) { s->failed_pc=0x0c074d50u; return 0; }
r[0]=r[6]&255u;
goto P_0c074d52;
P_0c074d52: /* original 880c, guest PC 0x0c074d52 */
if(!s->budget--) { s->failed_pc=0x0c074d52u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c074d54;
P_0c074d54: /* original 8d54, guest PC 0x0c074d54 */
if(!s->budget--) { s->failed_pc=0x0c074d54u; return 0; }
cond=r[17]&1u;
r[6]=r[0];
if(cond) { goto P_0c074e00; }
goto P_0c074d58;
P_0c074d56: /* original 6603, guest PC 0x0c074d56 */
if(!s->budget--) { s->failed_pc=0x0c074d56u; return 0; }
r[6]=r[0];
goto P_0c074d58;
P_0c074d58: /* original 6073, guest PC 0x0c074d58 */
if(!s->budget--) { s->failed_pc=0x0c074d58u; return 0; }
r[0]=r[7];
goto P_0c074d5a;
P_0c074d5a: /* original 8802, guest PC 0x0c074d5a */
if(!s->budget--) { s->failed_pc=0x0c074d5au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c074d5c;
P_0c074d5c: /* original 8b50, guest PC 0x0c074d5c */
if(!s->budget--) { s->failed_pc=0x0c074d5cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074e00; }
goto P_0c074d5e;
P_0c074d5e: /* original d313, guest PC 0x0c074d5e */
if(!s->budget--) { s->failed_pc=0x0c074d5eu; return 0; }
r[3]=read(ram,0x0c074dacu,4);
goto P_0c074d60;
P_0c074d60: /* original 23d8, guest PC 0x0c074d60 */
if(!s->budget--) { s->failed_pc=0x0c074d60u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c074d62;
P_0c074d62: /* original 8b4d, guest PC 0x0c074d62 */
if(!s->budget--) { s->failed_pc=0x0c074d62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074e00; }
goto P_0c074d64;
P_0c074d64: /* original e3f1, guest PC 0x0c074d64 */
if(!s->budget--) { s->failed_pc=0x0c074d64u; return 0; }
r[3]=0xfffffff1u;
goto P_0c074d66;
P_0c074d66: /* original e601, guest PC 0x0c074d66 */
if(!s->budget--) { s->failed_pc=0x0c074d66u; return 0; }
r[6]=0x00000001u;
goto P_0c074d68;
P_0c074d68: /* original 4c3d, guest PC 0x0c074d68 */
if(!s->budget--) { s->failed_pc=0x0c074d68u; return 0; }
r[12]=(r[3]&0x80000000u)?((r[3]&31u)?r[12]>>((-r[3])&31u):0):r[12]<<(r[3]&31u);
goto P_0c074d6a;
P_0c074d6a: /* original 26c9, guest PC 0x0c074d6a */
if(!s->budget--) { s->failed_pc=0x0c074d6au; return 0; }
r[6]&=r[12];
goto P_0c074d6c;
P_0c074d6c: /* original 2668, guest PC 0x0c074d6c */
if(!s->budget--) { s->failed_pc=0x0c074d6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c074d6e;
P_0c074d6e: /* original 8947, guest PC 0x0c074d6e */
if(!s->budget--) { s->failed_pc=0x0c074d6eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074e00; }
goto P_0c074d70;
P_0c074d70: /* original e06a, guest PC 0x0c074d70 */
if(!s->budget--) { s->failed_pc=0x0c074d70u; return 0; }
r[0]=0x0000006au;
goto P_0c074d72;
P_0c074d72: /* original 9318, guest PC 0x0c074d72 */
if(!s->budget--) { s->failed_pc=0x0c074d72u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074da6u,2);
goto P_0c074d74;
P_0c074d74: /* original 065d, guest PC 0x0c074d74 */
if(!s->budget--) { s->failed_pc=0x0c074d74u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c074d76;
P_0c074d76: /* original 9015, guest PC 0x0c074d76 */
if(!s->budget--) { s->failed_pc=0x0c074d76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074da4u,2);
goto P_0c074d78;
P_0c074d78: /* original 075d, guest PC 0x0c074d78 */
if(!s->budget--) { s->failed_pc=0x0c074d78u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c074d7a;
P_0c074d7a: /* original 3768, guest PC 0x0c074d7a */
if(!s->budget--) { s->failed_pc=0x0c074d7au; return 0; }
r[7]-=r[6];
goto P_0c074d7c;
P_0c074d7c: /* original 667f, guest PC 0x0c074d7c */
if(!s->budget--) { s->failed_pc=0x0c074d7cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[7];
goto P_0c074d7e;
P_0c074d7e: /* original 3637, guest PC 0x0c074d7e */
if(!s->budget--) { s->failed_pc=0x0c074d7eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[3])!=0);
goto P_0c074d80;
P_0c074d80: /* original 8916, guest PC 0x0c074d80 */
if(!s->budget--) { s->failed_pc=0x0c074d80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074db0; }
goto P_0c074d82;
P_0c074d82: /* original 9211, guest PC 0x0c074d82 */
if(!s->budget--) { s->failed_pc=0x0c074d82u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074da8u,2);
goto P_0c074d84;
P_0c074d84: /* original 3623, guest PC 0x0c074d84 */
if(!s->budget--) { s->failed_pc=0x0c074d84u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[2])!=0);
goto P_0c074d86;
P_0c074d86: /* original 893b, guest PC 0x0c074d86 */
if(!s->budget--) { s->failed_pc=0x0c074d86u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074e00; }
goto P_0c074d88;
P_0c074d88: /* original 6352, guest PC 0x0c074d88 */
if(!s->budget--) { s->failed_pc=0x0c074d88u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c074d8a;
P_0c074d8a: /* original 2938, guest PC 0x0c074d8a */
if(!s->budget--) { s->failed_pc=0x0c074d8au; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[3])==0)!=0);
goto P_0c074d8c;
P_0c074d8c: /* original 8b13, guest PC 0x0c074d8c */
if(!s->budget--) { s->failed_pc=0x0c074d8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074db6; }
goto P_0c074d8e;
P_0c074d8e: /* original a013, guest PC 0x0c074d8e */
if(!s->budget--) { s->failed_pc=0x0c074d8eu; return 0; }
r[5]=0x00000002u;
goto P_0c074db8;
P_0c074d90: /* original e502, guest PC 0x0c074d90 */
if(!s->budget--) { s->failed_pc=0x0c074d90u; return 0; }
r[5]=0x00000002u;
return vf3_matrix_family(0x0c074d92u,s,ram);
P_0c074db0: /* original 6252, guest PC 0x0c074db0 */
if(!s->budget--) { s->failed_pc=0x0c074db0u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c074db2;
P_0c074db2: /* original 2928, guest PC 0x0c074db2 */
if(!s->budget--) { s->failed_pc=0x0c074db2u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[2])==0)!=0);
goto P_0c074db4;
P_0c074db4: /* original 8beb, guest PC 0x0c074db4 */
if(!s->budget--) { s->failed_pc=0x0c074db4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074d8e; }
goto P_0c074db6;
P_0c074db6: /* original 6583, guest PC 0x0c074db6 */
if(!s->budget--) { s->failed_pc=0x0c074db6u; return 0; }
r[5]=r[8];
goto P_0c074db8;
P_0c074db8: /* original 9053, guest PC 0x0c074db8 */
if(!s->budget--) { s->failed_pc=0x0c074db8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c074e62u,2);
goto P_0c074dba;
P_0c074dba: /* original 064e, guest PC 0x0c074dba */
if(!s->budget--) { s->failed_pc=0x0c074dbau; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c074dbc;
P_0c074dbc: /* original 70fd, guest PC 0x0c074dbc */
if(!s->budget--) { s->failed_pc=0x0c074dbcu; return 0; }
r[0]+=0xfffffffdu;
goto P_0c074dbe;
P_0c074dbe: /* original 676c, guest PC 0x0c074dbe */
if(!s->budget--) { s->failed_pc=0x0c074dbeu; return 0; }
r[7]=r[6]&255u;
goto P_0c074dc0;
P_0c074dc0: /* original 064c, guest PC 0x0c074dc0 */
if(!s->budget--) { s->failed_pc=0x0c074dc0u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c074dc2;
P_0c074dc2: /* original 606c, guest PC 0x0c074dc2 */
if(!s->budget--) { s->failed_pc=0x0c074dc2u; return 0; }
r[0]=r[6]&255u;
goto P_0c074dc4;
P_0c074dc4: /* original 8801, guest PC 0x0c074dc4 */
if(!s->budget--) { s->failed_pc=0x0c074dc4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c074dc6;
P_0c074dc6: /* original 8d07, guest PC 0x0c074dc6 */
if(!s->budget--) { s->failed_pc=0x0c074dc6u; return 0; }
cond=r[17]&1u;
r[6]=r[0];
if(cond) { goto P_0c074dd8; }
goto P_0c074dca;
P_0c074dc8: /* original 6603, guest PC 0x0c074dc8 */
if(!s->budget--) { s->failed_pc=0x0c074dc8u; return 0; }
r[6]=r[0];
goto P_0c074dca;
P_0c074dca: /* original 2668, guest PC 0x0c074dca */
if(!s->budget--) { s->failed_pc=0x0c074dcau; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c074dcc;
P_0c074dcc: /* original 8b18, guest PC 0x0c074dcc */
if(!s->budget--) { s->failed_pc=0x0c074dccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074e00; }
goto P_0c074dce;
P_0c074dce: /* original 2778, guest PC 0x0c074dce */
if(!s->budget--) { s->failed_pc=0x0c074dceu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c074dd0;
P_0c074dd0: /* original 8b16, guest PC 0x0c074dd0 */
if(!s->budget--) { s->failed_pc=0x0c074dd0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074e00; }
goto P_0c074dd2;
P_0c074dd2: /* original d424, guest PC 0x0c074dd2 */
if(!s->budget--) { s->failed_pc=0x0c074dd2u; return 0; }
r[4]=read(ram,0x0c074e64u,4);
goto P_0c074dd4;
P_0c074dd4: /* original a00a, guest PC 0x0c074dd4 */
if(!s->budget--) { s->failed_pc=0x0c074dd4u; return 0; }
goto P_0c074dec;
P_0c074dd6: /* original 0009, guest PC 0x0c074dd6 */
if(!s->budget--) { s->failed_pc=0x0c074dd6u; return 0; }
goto P_0c074dd8;
P_0c074dd8: /* original 6073, guest PC 0x0c074dd8 */
if(!s->budget--) { s->failed_pc=0x0c074dd8u; return 0; }
r[0]=r[7];
goto P_0c074dda;
P_0c074dda: /* original 8806, guest PC 0x0c074dda */
if(!s->budget--) { s->failed_pc=0x0c074ddau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c074ddc;
P_0c074ddc: /* original 8905, guest PC 0x0c074ddc */
if(!s->budget--) { s->failed_pc=0x0c074ddcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074dea; }
goto P_0c074dde;
P_0c074dde: /* original 880f, guest PC 0x0c074dde */
if(!s->budget--) { s->failed_pc=0x0c074ddeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c074de0;
P_0c074de0: /* original 8903, guest PC 0x0c074de0 */
if(!s->budget--) { s->failed_pc=0x0c074de0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074dea; }
goto P_0c074de2;
P_0c074de2: /* original 881b, guest PC 0x0c074de2 */
if(!s->budget--) { s->failed_pc=0x0c074de2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001bu)!=0);
goto P_0c074de4;
P_0c074de4: /* original 8901, guest PC 0x0c074de4 */
if(!s->budget--) { s->failed_pc=0x0c074de4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c074dea; }
goto P_0c074de6;
P_0c074de6: /* original a00b, guest PC 0x0c074de6 */
if(!s->budget--) { s->failed_pc=0x0c074de6u; return 0; }
goto P_0c074e00;
P_0c074de8: /* original 0009, guest PC 0x0c074de8 */
if(!s->budget--) { s->failed_pc=0x0c074de8u; return 0; }
goto P_0c074dea;
P_0c074dea: /* original d41f, guest PC 0x0c074dea */
if(!s->budget--) { s->failed_pc=0x0c074deau; return 0; }
r[4]=read(ram,0x0c074e68u,4);
goto P_0c074dec;
P_0c074dec: /* original 6643, guest PC 0x0c074dec */
if(!s->budget--) { s->failed_pc=0x0c074decu; return 0; }
r[6]=r[4];
goto P_0c074dee;
P_0c074dee: /* original 365c, guest PC 0x0c074dee */
if(!s->budget--) { s->failed_pc=0x0c074deeu; return 0; }
r[6]+=r[5];
goto P_0c074df0;
P_0c074df0: /* original 8461, guest PC 0x0c074df0 */
if(!s->budget--) { s->failed_pc=0x0c074df0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+1,1);
goto P_0c074df2;
P_0c074df2: /* original de1e, guest PC 0x0c074df2 */
if(!s->budget--) { s->failed_pc=0x0c074df2u; return 0; }
r[14]=read(ram,0x0c074e6cu,4);
goto P_0c074df4;
P_0c074df4: /* original 6360, guest PC 0x0c074df4 */
if(!s->budget--) { s->failed_pc=0x0c074df4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[3]=tmp;
goto P_0c074df6;
P_0c074df6: /* original 600c, guest PC 0x0c074df6 */
if(!s->budget--) { s->failed_pc=0x0c074df6u; return 0; }
r[0]=r[0]&255u;
goto P_0c074df8;
P_0c074df8: /* original 4018, guest PC 0x0c074df8 */
if(!s->budget--) { s->failed_pc=0x0c074df8u; return 0; }
r[0]<<=8;
goto P_0c074dfa;
P_0c074dfa: /* original 633c, guest PC 0x0c074dfa */
if(!s->budget--) { s->failed_pc=0x0c074dfau; return 0; }
r[3]=r[3]&255u;
goto P_0c074dfc;
P_0c074dfc: /* original 2e09, guest PC 0x0c074dfc */
if(!s->budget--) { s->failed_pc=0x0c074dfcu; return 0; }
r[14]&=r[0];
goto P_0c074dfe;
P_0c074dfe: /* original 2e3b, guest PC 0x0c074dfe */
if(!s->budget--) { s->failed_pc=0x0c074dfeu; return 0; }
r[14]|=r[3];
goto P_0c074e00;
P_0c074e00: /* original 52fb, guest PC 0x0c074e00 */
if(!s->budget--) { s->failed_pc=0x0c074e00u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c074e02;
P_0c074e02: /* original 22d2, guest PC 0x0c074e02 */
if(!s->budget--) { s->failed_pc=0x0c074e02u; return 0; }
write(ram,r[2],r[13],4);
goto P_0c074e04;
P_0c074e04: /* original 53f1, guest PC 0x0c074e04 */
if(!s->budget--) { s->failed_pc=0x0c074e04u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c074e06;
P_0c074e06: /* original 7f08, guest PC 0x0c074e06 */
if(!s->budget--) { s->failed_pc=0x0c074e06u; return 0; }
r[15]+=0x00000008u;
goto P_0c074e08;
P_0c074e08: /* original 4f26, guest PC 0x0c074e08 */
if(!s->budget--) { s->failed_pc=0x0c074e08u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c074e0a;
P_0c074e0a: /* original 23e2, guest PC 0x0c074e0a */
if(!s->budget--) { s->failed_pc=0x0c074e0au; return 0; }
write(ram,r[3],r[14],4);
goto P_0c074e0c;
P_0c074e0c: /* original 68f6, guest PC 0x0c074e0c */
if(!s->budget--) { s->failed_pc=0x0c074e0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c074e0e;
P_0c074e0e: /* original 69f6, guest PC 0x0c074e0e */
if(!s->budget--) { s->failed_pc=0x0c074e0eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c074e10;
P_0c074e10: /* original 6af6, guest PC 0x0c074e10 */
if(!s->budget--) { s->failed_pc=0x0c074e10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c074e12;
P_0c074e12: /* original 6bf6, guest PC 0x0c074e12 */
if(!s->budget--) { s->failed_pc=0x0c074e12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c074e14;
P_0c074e14: /* original 6cf6, guest PC 0x0c074e14 */
if(!s->budget--) { s->failed_pc=0x0c074e14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c074e16;
P_0c074e16: /* original 6df6, guest PC 0x0c074e16 */
if(!s->budget--) { s->failed_pc=0x0c074e16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c074e18;
P_0c074e18: /* original 000b, guest PC 0x0c074e18 */
if(!s->budget--) { s->failed_pc=0x0c074e18u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c074e1a: /* original 6ef6, guest PC 0x0c074e1a */
if(!s->budget--) { s->failed_pc=0x0c074e1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c074e1cu,s,ram);
P_0c09381e: /* original f40b, guest PC 0x0c09381e */
if(!s->budget--) { s->failed_pc=0x0c09381eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093820;
P_0c093820: /* original 7f08, guest PC 0x0c093820 */
if(!s->budget--) { s->failed_pc=0x0c093820u; return 0; }
r[15]+=0x00000008u;
goto P_0c093822;
P_0c093822: /* original fff9, guest PC 0x0c093822 */
if(!s->budget--) { s->failed_pc=0x0c093822u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c093824;
P_0c093824: /* original 6df6, guest PC 0x0c093824 */
if(!s->budget--) { s->failed_pc=0x0c093824u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c093826;
P_0c093826: /* original 000b, guest PC 0x0c093826 */
if(!s->budget--) { s->failed_pc=0x0c093826u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c093828: /* original 6ef6, guest PC 0x0c093828 */
if(!s->budget--) { s->failed_pc=0x0c093828u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09382au,s,ram);
P_0c09571c: /* original d21c, guest PC 0x0c09571c */
if(!s->budget--) { s->failed_pc=0x0c09571cu; return 0; }
r[2]=read(ram,0x0c095790u,4);
goto P_0c09571e;
P_0c09571e: /* original 6322, guest PC 0x0c09571e */
if(!s->budget--) { s->failed_pc=0x0c09571eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c095720;
P_0c095720: /* original 432b, guest PC 0x0c095720 */
if(!s->budget--) { s->failed_pc=0x0c095720u; return 0; }
target=r[3];
r[4]=0x00000001u;
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
P_0c095722: /* original e401, guest PC 0x0c095722 */
if(!s->budget--) { s->failed_pc=0x0c095722u; return 0; }
r[4]=0x00000001u;
return vf3_matrix_family(0x0c095724u,s,ram);
P_0c0a2b98: /* original 2fe6, guest PC 0x0c0a2b98 */
if(!s->budget--) { s->failed_pc=0x0c0a2b98u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0a2b9a;
P_0c0a2b9a: /* original 6e43, guest PC 0x0c0a2b9a */
if(!s->budget--) { s->failed_pc=0x0c0a2b9au; return 0; }
r[14]=r[4];
goto P_0c0a2b9c;
P_0c0a2b9c: /* original 2fd6, guest PC 0x0c0a2b9c */
if(!s->budget--) { s->failed_pc=0x0c0a2b9cu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0a2b9e;
P_0c0a2b9e: /* original 2fc6, guest PC 0x0c0a2b9e */
if(!s->budget--) { s->failed_pc=0x0c0a2b9eu; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0a2ba0;
P_0c0a2ba0: /* original 2fb6, guest PC 0x0c0a2ba0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba0u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0a2ba2;
P_0c0a2ba2: /* original 2fa6, guest PC 0x0c0a2ba2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba2u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0a2ba4;
P_0c0a2ba4: /* original 2f96, guest PC 0x0c0a2ba4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba4u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0a2ba6;
P_0c0a2ba6: /* original 2f86, guest PC 0x0c0a2ba6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba6u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c0a2ba8;
P_0c0a2ba8: /* original 60e2, guest PC 0x0c0a2ba8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba8u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0a2baa;
P_0c0a2baa: /* original 4f22, guest PC 0x0c0a2baa */
if(!s->budget--) { s->failed_pc=0x0c0a2baau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2bac;
P_0c0a2bac: /* original c880, guest PC 0x0c0a2bac */
if(!s->budget--) { s->failed_pc=0x0c0a2bacu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0a2bae;
P_0c0a2bae: /* original 8938, guest PC 0x0c0a2bae */
if(!s->budget--) { s->failed_pc=0x0c0a2baeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2c22; }
goto P_0c0a2bb0;
P_0c0a2bb0: /* original 62e2, guest PC 0x0c0a2bb0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0a2bb2;
P_0c0a2bb2: /* original d33b, guest PC 0x0c0a2bb2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb2u; return 0; }
r[3]=read(ram,0x0c0a2ca0u,4);
goto P_0c0a2bb4;
P_0c0a2bb4: /* original 9173, guest PC 0x0c0a2bb4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2c9eu,2);
goto P_0c0a2bb6;
P_0c0a2bb6: /* original 2239, guest PC 0x0c0a2bb6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb6u; return 0; }
r[2]&=r[3];
goto P_0c0a2bb8;
P_0c0a2bb8: /* original 3210, guest PC 0x0c0a2bb8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c0a2bba;
P_0c0a2bba: /* original 8905, guest PC 0x0c0a2bba */
if(!s->budget--) { s->failed_pc=0x0c0a2bbau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2bc8; }
goto P_0c0a2bbc;
P_0c0a2bbc: /* original d239, guest PC 0x0c0a2bbc */
if(!s->budget--) { s->failed_pc=0x0c0a2bbcu; return 0; }
r[2]=read(ram,0x0c0a2ca4u,4);
goto P_0c0a2bbe;
P_0c0a2bbe: /* original e56a, guest PC 0x0c0a2bbe */
if(!s->budget--) { s->failed_pc=0x0c0a2bbeu; return 0; }
r[5]=0x0000006au;
goto P_0c0a2bc0;
P_0c0a2bc0: /* original 420b, guest PC 0x0c0a2bc0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc0u; return 0; }
target=r[2];
r[16]=0x0c0a2bc4u;
r[4]=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2bc4u) { target=s->pc; goto dispatch; }
goto P_0c0a2bc4;
P_0c0a2bc2: /* original e401, guest PC 0x0c0a2bc2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc2u; return 0; }
r[4]=0x00000001u;
goto P_0c0a2bc4;
P_0c0a2bc4: /* original a02e, guest PC 0x0c0a2bc4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc4u; return 0; }
r[0]=0xffffffffu;
goto P_0c0a2c24;
P_0c0a2bc6: /* original e0ff, guest PC 0x0c0a2bc6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc6u; return 0; }
r[0]=0xffffffffu;
goto P_0c0a2bc8;
P_0c0a2bc8: /* original e020, guest PC 0x0c0a2bc8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc8u; return 0; }
r[0]=0x00000020u;
goto P_0c0a2bca;
P_0c0a2bca: /* original 03ed, guest PC 0x0c0a2bca */
if(!s->budget--) { s->failed_pc=0x0c0a2bcau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2bcc;
P_0c0a2bcc: /* original e022, guest PC 0x0c0a2bcc */
if(!s->budget--) { s->failed_pc=0x0c0a2bccu; return 0; }
r[0]=0x00000022u;
goto P_0c0a2bce;
P_0c0a2bce: /* original 02ed, guest PC 0x0c0a2bce */
if(!s->budget--) { s->failed_pc=0x0c0a2bceu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2bd0;
P_0c0a2bd0: /* original 633d, guest PC 0x0c0a2bd0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd0u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a2bd2;
P_0c0a2bd2: /* original 622d, guest PC 0x0c0a2bd2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd2u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0a2bd4;
P_0c0a2bd4: /* original 232b, guest PC 0x0c0a2bd4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd4u; return 0; }
r[3]|=r[2];
goto P_0c0a2bd6;
P_0c0a2bd6: /* original 2338, guest PC 0x0c0a2bd6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2bd8;
P_0c0a2bd8: /* original 8923, guest PC 0x0c0a2bd8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2c22; }
goto P_0c0a2bda;
P_0c0a2bda: /* original e020, guest PC 0x0c0a2bda */
if(!s->budget--) { s->failed_pc=0x0c0a2bdau; return 0; }
r[0]=0x00000020u;
goto P_0c0a2bdc;
P_0c0a2bdc: /* original d332, guest PC 0x0c0a2bdc */
if(!s->budget--) { s->failed_pc=0x0c0a2bdcu; return 0; }
r[3]=read(ram,0x0c0a2ca8u,4);
goto P_0c0a2bde;
P_0c0a2bde: /* original 04ed, guest PC 0x0c0a2bde */
if(!s->budget--) { s->failed_pc=0x0c0a2bdeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2be0;
P_0c0a2be0: /* original 430b, guest PC 0x0c0a2be0 */
if(!s->budget--) { s->failed_pc=0x0c0a2be0u; return 0; }
target=r[3];
r[16]=0x0c0a2be4u;
r[4]=r[4]&65535u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2be4u) { target=s->pc; goto dispatch; }
goto P_0c0a2be4;
P_0c0a2be2: /* original 644d, guest PC 0x0c0a2be2 */
if(!s->budget--) { s->failed_pc=0x0c0a2be2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a2be4;
P_0c0a2be4: /* original d932, guest PC 0x0c0a2be4 */
if(!s->budget--) { s->failed_pc=0x0c0a2be4u; return 0; }
r[9]=read(ram,0x0c0a2cb0u,4);
goto P_0c0a2be6;
P_0c0a2be6: /* original eb01, guest PC 0x0c0a2be6 */
if(!s->budget--) { s->failed_pc=0x0c0a2be6u; return 0; }
r[11]=0x00000001u;
goto P_0c0a2be8;
P_0c0a2be8: /* original d830, guest PC 0x0c0a2be8 */
if(!s->budget--) { s->failed_pc=0x0c0a2be8u; return 0; }
r[8]=read(ram,0x0c0a2cacu,4);
goto P_0c0a2bea;
P_0c0a2bea: /* original 5ae4, guest PC 0x0c0a2bea */
if(!s->budget--) { s->failed_pc=0x0c0a2beau; return 0; }
r[10]=read(ram,r[14]+16,4);
goto P_0c0a2bec;
P_0c0a2bec: /* original a010, guest PC 0x0c0a2bec */
if(!s->budget--) { s->failed_pc=0x0c0a2becu; return 0; }
r[12]=0x00000000u;
goto P_0c0a2c10;
P_0c0a2bee: /* original ec00, guest PC 0x0c0a2bee */
if(!s->budget--) { s->failed_pc=0x0c0a2beeu; return 0; }
r[12]=0x00000000u;
goto P_0c0a2bf0;
P_0c0a2bf0: /* original 6dc3, guest PC 0x0c0a2bf0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf0u; return 0; }
r[13]=r[12];
goto P_0c0a2bf2;
P_0c0a2bf2: /* original 4d08, guest PC 0x0c0a2bf2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf2u; return 0; }
r[13]<<=2;
goto P_0c0a2bf4;
P_0c0a2bf4: /* original 3dac, guest PC 0x0c0a2bf4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf4u; return 0; }
r[13]+=r[10];
goto P_0c0a2bf6;
P_0c0a2bf6: /* original 63d2, guest PC 0x0c0a2bf6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf6u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0a2bf8;
P_0c0a2bf8: /* original 5231, guest PC 0x0c0a2bf8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf8u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c0a2bfa;
P_0c0a2bfa: /* original 22b8, guest PC 0x0c0a2bfa */
if(!s->budget--) { s->failed_pc=0x0c0a2bfau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[11])==0)!=0);
goto P_0c0a2bfc;
P_0c0a2bfc: /* original 8903, guest PC 0x0c0a2bfc */
if(!s->budget--) { s->failed_pc=0x0c0a2bfcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2c06; }
goto P_0c0a2bfe;
P_0c0a2bfe: /* original 480b, guest PC 0x0c0a2bfe */
if(!s->budget--) { s->failed_pc=0x0c0a2bfeu; return 0; }
target=r[8];
r[16]=0x0c0a2c02u;
tmp=read(ram,r[13],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2c02u) { target=s->pc; goto dispatch; }
goto P_0c0a2c02;
P_0c0a2c00: /* original 64d2, guest PC 0x0c0a2c00 */
if(!s->budget--) { s->failed_pc=0x0c0a2c00u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2c02;
P_0c0a2c02: /* original a004, guest PC 0x0c0a2c02 */
if(!s->budget--) { s->failed_pc=0x0c0a2c02u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2c0e;
P_0c0a2c04: /* original 2008, guest PC 0x0c0a2c04 */
if(!s->budget--) { s->failed_pc=0x0c0a2c04u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2c06;
P_0c0a2c06: /* original 64d2, guest PC 0x0c0a2c06 */
if(!s->budget--) { s->failed_pc=0x0c0a2c06u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2c08;
P_0c0a2c08: /* original 490b, guest PC 0x0c0a2c08 */
if(!s->budget--) { s->failed_pc=0x0c0a2c08u; return 0; }
target=r[9];
r[16]=0x0c0a2c0cu;
r[4]=read(ram,r[4]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0a2c0cu) { target=s->pc; goto dispatch; }
goto P_0c0a2c0c;
P_0c0a2c0a: /* original 5441, guest PC 0x0c0a2c0a */
if(!s->budget--) { s->failed_pc=0x0c0a2c0au; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0a2c0c;
P_0c0a2c0c: /* original 2008, guest PC 0x0c0a2c0c */
if(!s->budget--) { s->failed_pc=0x0c0a2c0cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2c0e;
P_0c0a2c0e: /* original 7c01, guest PC 0x0c0a2c0e */
if(!s->budget--) { s->failed_pc=0x0c0a2c0eu; return 0; }
r[12]+=0x00000001u;
goto P_0c0a2c10;
P_0c0a2c10: /* original 85e6, guest PC 0x0c0a2c10 */
if(!s->budget--) { s->failed_pc=0x0c0a2c10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0a2c12;
P_0c0a2c12: /* original 600d, guest PC 0x0c0a2c12 */
if(!s->budget--) { s->failed_pc=0x0c0a2c12u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2c14;
P_0c0a2c14: /* original 3c03, guest PC 0x0c0a2c14 */
if(!s->budget--) { s->failed_pc=0x0c0a2c14u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[0])!=0);
goto P_0c0a2c16;
P_0c0a2c16: /* original 8beb, guest PC 0x0c0a2c16 */
if(!s->budget--) { s->failed_pc=0x0c0a2c16u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2bf0; }
goto P_0c0a2c18;
P_0c0a2c18: /* original e022, guest PC 0x0c0a2c18 */
if(!s->budget--) { s->failed_pc=0x0c0a2c18u; return 0; }
r[0]=0x00000022u;
goto P_0c0a2c1a;
P_0c0a2c1a: /* original e200, guest PC 0x0c0a2c1a */
if(!s->budget--) { s->failed_pc=0x0c0a2c1au; return 0; }
r[2]=0x00000000u;
goto P_0c0a2c1c;
P_0c0a2c1c: /* original 0e25, guest PC 0x0c0a2c1c */
if(!s->budget--) { s->failed_pc=0x0c0a2c1cu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0a2c1e;
P_0c0a2c1e: /* original e020, guest PC 0x0c0a2c1e */
if(!s->budget--) { s->failed_pc=0x0c0a2c1eu; return 0; }
r[0]=0x00000020u;
goto P_0c0a2c20;
P_0c0a2c20: /* original 0e25, guest PC 0x0c0a2c20 */
if(!s->budget--) { s->failed_pc=0x0c0a2c20u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0a2c22;
P_0c0a2c22: /* original e000, guest PC 0x0c0a2c22 */
if(!s->budget--) { s->failed_pc=0x0c0a2c22u; return 0; }
r[0]=0x00000000u;
goto P_0c0a2c24;
P_0c0a2c24: /* original 4f26, guest PC 0x0c0a2c24 */
if(!s->budget--) { s->failed_pc=0x0c0a2c24u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2c26;
P_0c0a2c26: /* original 68f6, guest PC 0x0c0a2c26 */
if(!s->budget--) { s->failed_pc=0x0c0a2c26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2c28;
P_0c0a2c28: /* original 69f6, guest PC 0x0c0a2c28 */
if(!s->budget--) { s->failed_pc=0x0c0a2c28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a2c2a;
P_0c0a2c2a: /* original 6af6, guest PC 0x0c0a2c2a */
if(!s->budget--) { s->failed_pc=0x0c0a2c2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a2c2c;
P_0c0a2c2c: /* original 6bf6, guest PC 0x0c0a2c2c */
if(!s->budget--) { s->failed_pc=0x0c0a2c2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a2c2e;
P_0c0a2c2e: /* original 6cf6, guest PC 0x0c0a2c2e */
if(!s->budget--) { s->failed_pc=0x0c0a2c2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a2c30;
P_0c0a2c30: /* original 6df6, guest PC 0x0c0a2c30 */
if(!s->budget--) { s->failed_pc=0x0c0a2c30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2c32;
P_0c0a2c32: /* original 000b, guest PC 0x0c0a2c32 */
if(!s->budget--) { s->failed_pc=0x0c0a2c32u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2c34: /* original 6ef6, guest PC 0x0c0a2c34 */
if(!s->budget--) { s->failed_pc=0x0c0a2c34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a2c36u,s,ram);
P_0c0c7648: /* original 2fe6, guest PC 0x0c0c7648 */
if(!s->budget--) { s->failed_pc=0x0c0c7648u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0c764a;
P_0c0c764a: /* original 2fd6, guest PC 0x0c0c764a */
if(!s->budget--) { s->failed_pc=0x0c0c764au; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0c764c;
P_0c0c764c: /* original 2fc6, guest PC 0x0c0c764c */
if(!s->budget--) { s->failed_pc=0x0c0c764cu; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c0c764e;
P_0c0c764e: /* original 2fb6, guest PC 0x0c0c764e */
if(!s->budget--) { s->failed_pc=0x0c0c764eu; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c0c7650;
P_0c0c7650: /* original 2fa6, guest PC 0x0c0c7650 */
if(!s->budget--) { s->failed_pc=0x0c0c7650u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c0c7652;
P_0c0c7652: /* original 2f96, guest PC 0x0c0c7652 */
if(!s->budget--) { s->failed_pc=0x0c0c7652u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c0c7654;
P_0c0c7654: /* original da40, guest PC 0x0c0c7654 */
if(!s->budget--) { s->failed_pc=0x0c0c7654u; return 0; }
r[10]=read(ram,0x0c0c7758u,4);
goto P_0c0c7656;
P_0c0c7656: /* original 9077, guest PC 0x0c0c7656 */
if(!s->budget--) { s->failed_pc=0x0c0c7656u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7748u,2);
goto P_0c0c7658;
P_0c0c7658: /* original 4f22, guest PC 0x0c0c7658 */
if(!s->budget--) { s->failed_pc=0x0c0c7658u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c765a;
P_0c0c765a: /* original 0cae, guest PC 0x0c0c765a */
if(!s->budget--) { s->failed_pc=0x0c0c765au; return 0; }
r[12]=read(ram,r[10]+r[0],4);
goto P_0c0c765c;
P_0c0c765c: /* original 7004, guest PC 0x0c0c765c */
if(!s->budget--) { s->failed_pc=0x0c0c765cu; return 0; }
r[0]+=0x00000004u;
goto P_0c0c765e;
P_0c0c765e: /* original dd3f, guest PC 0x0c0c765e */
if(!s->budget--) { s->failed_pc=0x0c0c765eu; return 0; }
r[13]=read(ram,0x0c0c775cu,4);
goto P_0c0c7660;
P_0c0c7660: /* original 2cc8, guest PC 0x0c0c7660 */
if(!s->budget--) { s->failed_pc=0x0c0c7660u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0c7662;
P_0c0c7662: /* original 8d0e, guest PC 0x0c0c7662 */
if(!s->budget--) { s->failed_pc=0x0c0c7662u; return 0; }
cond=r[17]&1u;
r[11]=read(ram,r[10]+r[0],4);
if(cond) { goto P_0c0c7682; }
goto P_0c0c7666;
P_0c0c7664: /* original 0bae, guest PC 0x0c0c7664 */
if(!s->budget--) { s->failed_pc=0x0c0c7664u; return 0; }
r[11]=read(ram,r[10]+r[0],4);
goto P_0c0c7666;
P_0c0c7666: /* original 85c6, guest PC 0x0c0c7666 */
if(!s->budget--) { s->failed_pc=0x0c0c7666u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+12,2);
goto P_0c0c7668;
P_0c0c7668: /* original 996f, guest PC 0x0c0c7668 */
if(!s->budget--) { s->failed_pc=0x0c0c7668u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774au,2);
goto P_0c0c766a;
P_0c0c766a: /* original 6e0d, guest PC 0x0c0c766a */
if(!s->budget--) { s->failed_pc=0x0c0c766au; return 0; }
r[14]=r[0]&65535u;
goto P_0c0c766c;
P_0c0c766c: /* original 4e15, guest PC 0x0c0c766c */
if(!s->budget--) { s->failed_pc=0x0c0c766cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c766e;
P_0c0c766e: /* original 8b05, guest PC 0x0c0c766e */
if(!s->budget--) { s->failed_pc=0x0c0c766eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c767c; }
goto P_0c0c7670;
P_0c0c7670: /* original 6493, guest PC 0x0c0c7670 */
if(!s->budget--) { s->failed_pc=0x0c0c7670u; return 0; }
r[4]=r[9];
goto P_0c0c7672;
P_0c0c7672: /* original 4d0b, guest PC 0x0c0c7672 */
if(!s->budget--) { s->failed_pc=0x0c0c7672u; return 0; }
target=r[13];
r[16]=0x0c0c7676u;
r[9]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7676u) { target=s->pc; goto dispatch; }
goto P_0c0c7676;
P_0c0c7674: /* original 7901, guest PC 0x0c0c7674 */
if(!s->budget--) { s->failed_pc=0x0c0c7674u; return 0; }
r[9]+=0x00000001u;
goto P_0c0c7676;
P_0c0c7676: /* original 7eff, guest PC 0x0c0c7676 */
if(!s->budget--) { s->failed_pc=0x0c0c7676u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0c7678;
P_0c0c7678: /* original 4e15, guest PC 0x0c0c7678 */
if(!s->budget--) { s->failed_pc=0x0c0c7678u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c767a;
P_0c0c767a: /* original 89f9, guest PC 0x0c0c767a */
if(!s->budget--) { s->failed_pc=0x0c0c767au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7670; }
goto P_0c0c767c;
P_0c0c767c: /* original d338, guest PC 0x0c0c767c */
if(!s->budget--) { s->failed_pc=0x0c0c767cu; return 0; }
r[3]=read(ram,0x0c0c7760u,4);
goto P_0c0c767e;
P_0c0c767e: /* original 430b, guest PC 0x0c0c767e */
if(!s->budget--) { s->failed_pc=0x0c0c767eu; return 0; }
target=r[3];
r[16]=0x0c0c7682u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7682u) { target=s->pc; goto dispatch; }
goto P_0c0c7682;
P_0c0c7680: /* original 64c3, guest PC 0x0c0c7680 */
if(!s->budget--) { s->failed_pc=0x0c0c7680u; return 0; }
r[4]=r[12];
goto P_0c0c7682;
P_0c0c7682: /* original 2bb8, guest PC 0x0c0c7682 */
if(!s->budget--) { s->failed_pc=0x0c0c7682u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0c7684;
P_0c0c7684: /* original 890d, guest PC 0x0c0c7684 */
if(!s->budget--) { s->failed_pc=0x0c0c7684u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c76a2; }
goto P_0c0c7686;
P_0c0c7686: /* original 85b6, guest PC 0x0c0c7686 */
if(!s->budget--) { s->failed_pc=0x0c0c7686u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+12,2);
goto P_0c0c7688;
P_0c0c7688: /* original 9c60, guest PC 0x0c0c7688 */
if(!s->budget--) { s->failed_pc=0x0c0c7688u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774cu,2);
goto P_0c0c768a;
P_0c0c768a: /* original 6e0d, guest PC 0x0c0c768a */
if(!s->budget--) { s->failed_pc=0x0c0c768au; return 0; }
r[14]=r[0]&65535u;
goto P_0c0c768c;
P_0c0c768c: /* original 4e15, guest PC 0x0c0c768c */
if(!s->budget--) { s->failed_pc=0x0c0c768cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c768e;
P_0c0c768e: /* original 8b05, guest PC 0x0c0c768e */
if(!s->budget--) { s->failed_pc=0x0c0c768eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c769c; }
goto P_0c0c7690;
P_0c0c7690: /* original 64c3, guest PC 0x0c0c7690 */
if(!s->budget--) { s->failed_pc=0x0c0c7690u; return 0; }
r[4]=r[12];
goto P_0c0c7692;
P_0c0c7692: /* original 4d0b, guest PC 0x0c0c7692 */
if(!s->budget--) { s->failed_pc=0x0c0c7692u; return 0; }
target=r[13];
r[16]=0x0c0c7696u;
r[12]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7696u) { target=s->pc; goto dispatch; }
goto P_0c0c7696;
P_0c0c7694: /* original 7c01, guest PC 0x0c0c7694 */
if(!s->budget--) { s->failed_pc=0x0c0c7694u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c7696;
P_0c0c7696: /* original 7eff, guest PC 0x0c0c7696 */
if(!s->budget--) { s->failed_pc=0x0c0c7696u; return 0; }
r[14]+=0xffffffffu;
goto P_0c0c7698;
P_0c0c7698: /* original 4e15, guest PC 0x0c0c7698 */
if(!s->budget--) { s->failed_pc=0x0c0c7698u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c0c769a;
P_0c0c769a: /* original 89f9, guest PC 0x0c0c769a */
if(!s->budget--) { s->failed_pc=0x0c0c769au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7690; }
goto P_0c0c769c;
P_0c0c769c: /* original d330, guest PC 0x0c0c769c */
if(!s->budget--) { s->failed_pc=0x0c0c769cu; return 0; }
r[3]=read(ram,0x0c0c7760u,4);
goto P_0c0c769e;
P_0c0c769e: /* original 430b, guest PC 0x0c0c769e */
if(!s->budget--) { s->failed_pc=0x0c0c769eu; return 0; }
target=r[3];
r[16]=0x0c0c76a2u;
r[4]=r[11];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c76a2u) { target=s->pc; goto dispatch; }
goto P_0c0c76a2;
P_0c0c76a0: /* original 64b3, guest PC 0x0c0c76a0 */
if(!s->budget--) { s->failed_pc=0x0c0c76a0u; return 0; }
r[4]=r[11];
goto P_0c0c76a2;
P_0c0c76a2: /* original 9054, guest PC 0x0c0c76a2 */
if(!s->budget--) { s->failed_pc=0x0c0c76a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c774eu,2);
goto P_0c0c76a4;
P_0c0c76a4: /* original e400, guest PC 0x0c0c76a4 */
if(!s->budget--) { s->failed_pc=0x0c0c76a4u; return 0; }
r[4]=0x00000000u;
goto P_0c0c76a6;
P_0c0c76a6: /* original 4f26, guest PC 0x0c0c76a6 */
if(!s->budget--) { s->failed_pc=0x0c0c76a6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c76a8;
P_0c0c76a8: /* original 0a46, guest PC 0x0c0c76a8 */
if(!s->budget--) { s->failed_pc=0x0c0c76a8u; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c0c76aa;
P_0c0c76aa: /* original 70f8, guest PC 0x0c0c76aa */
if(!s->budget--) { s->failed_pc=0x0c0c76aau; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c76ac;
P_0c0c76ac: /* original 0a46, guest PC 0x0c0c76ac */
if(!s->budget--) { s->failed_pc=0x0c0c76acu; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c0c76ae;
P_0c0c76ae: /* original 7004, guest PC 0x0c0c76ae */
if(!s->budget--) { s->failed_pc=0x0c0c76aeu; return 0; }
r[0]+=0x00000004u;
goto P_0c0c76b0;
P_0c0c76b0: /* original 0a46, guest PC 0x0c0c76b0 */
if(!s->budget--) { s->failed_pc=0x0c0c76b0u; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c0c76b2;
P_0c0c76b2: /* original 69f6, guest PC 0x0c0c76b2 */
if(!s->budget--) { s->failed_pc=0x0c0c76b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c76b4;
P_0c0c76b4: /* original 6af6, guest PC 0x0c0c76b4 */
if(!s->budget--) { s->failed_pc=0x0c0c76b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c76b6;
P_0c0c76b6: /* original 6bf6, guest PC 0x0c0c76b6 */
if(!s->budget--) { s->failed_pc=0x0c0c76b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c76b8;
P_0c0c76b8: /* original 6cf6, guest PC 0x0c0c76b8 */
if(!s->budget--) { s->failed_pc=0x0c0c76b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c76ba;
P_0c0c76ba: /* original 6df6, guest PC 0x0c0c76ba */
if(!s->budget--) { s->failed_pc=0x0c0c76bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c76bc;
P_0c0c76bc: /* original 000b, guest PC 0x0c0c76bc */
if(!s->budget--) { s->failed_pc=0x0c0c76bcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c76be: /* original 6ef6, guest PC 0x0c0c76be */
if(!s->budget--) { s->failed_pc=0x0c0c76beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c76c0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c038b40u,0x0c038b42u,0x0c038b44u,0x0c038b46u,0x0c038b48u,0x0c038b4au,0x0c038b4cu,0x0c038b4eu,0x0c038b50u,0x0c038b52u,0x0c038b54u,0x0c038b56u,0x0c038b58u,0x0c038b60u,0x0c038b62u,0x0c038b64u,
0x0c038b66u,0x0c038b68u,0x0c038b6au,0x0c038b6cu,0x0c038b6eu,0x0c038b70u,0x0c038b72u,0x0c038b74u,0x0c038b76u,0x0c038b78u,0x0c038b7au,0x0c038b7cu,0x0c038b7eu,0x0c038b80u,0x0c038b82u,0x0c038b90u,
0x0c038b92u,0x0c038b94u,0x0c038b96u,0x0c038b98u,0x0c038b9au,0x0c038b9cu,0x0c038b9eu,0x0c038ba0u,0x0c038ba2u,0x0c038ba4u,0x0c038ba6u,0x0c038ba8u,0x0c038baau,0x0c038bacu,0x0c038baeu,0x0c038bb0u,
0x0c038bb2u,0x0c038bb4u,0x0c03b684u,0x0c03b686u,0x0c03b688u,0x0c03b68au,0x0c03b68cu,0x0c03b68eu,0x0c054524u,0x0c054526u,0x0c054528u,0x0c05452au,0x0c05452cu,0x0c066fd8u,0x0c066fdau,0x0c066fdcu,
0x0c066fdeu,0x0c066fe0u,0x0c066fe2u,0x0c066fe4u,0x0c066fe6u,0x0c066fe8u,0x0c066feau,0x0c066fecu,0x0c066feeu,0x0c066ff0u,0x0c066ff2u,0x0c066ff4u,0x0c066ff6u,0x0c066ff8u,0x0c066ffau,0x0c066ffcu,
0x0c066ffeu,0x0c067000u,0x0c067002u,0x0c067004u,0x0c067006u,0x0c067008u,0x0c06700au,0x0c06700cu,0x0c06700eu,0x0c067010u,0x0c067012u,0x0c067014u,0x0c067016u,0x0c067018u,0x0c06701au,0x0c06701cu,
0x0c06701eu,0x0c067020u,0x0c067022u,0x0c067024u,0x0c067026u,0x0c067028u,0x0c06702au,0x0c06702cu,0x0c06702eu,0x0c067030u,0x0c067032u,0x0c067034u,0x0c067036u,0x0c067038u,0x0c06703au,0x0c06703cu,
0x0c06703eu,0x0c067040u,0x0c067042u,0x0c067044u,0x0c067046u,0x0c067048u,0x0c06704au,0x0c06704cu,0x0c06704eu,0x0c067050u,0x0c067052u,0x0c067054u,0x0c067056u,0x0c067058u,0x0c06705au,0x0c06705cu,
0x0c07021cu,0x0c07021eu,0x0c070220u,0x0c070222u,0x0c070224u,0x0c070fa6u,0x0c070fa8u,0x0c070faau,0x0c070facu,0x0c070faeu,0x0c070fb0u,0x0c070fb2u,0x0c070fb4u,0x0c070fb6u,0x0c070fb8u,0x0c070fc4u,
0x0c070fc6u,0x0c070fc8u,0x0c070fcau,0x0c070fccu,0x0c070fceu,0x0c070fd0u,0x0c070fd2u,0x0c070fd4u,0x0c070fd6u,0x0c070fd8u,0x0c070fdau,0x0c070fdcu,0x0c070fdeu,0x0c070fe0u,0x0c070fe2u,0x0c070fe4u,
0x0c070fe6u,0x0c070fe8u,0x0c070feau,0x0c070fecu,0x0c070feeu,0x0c070ff0u,0x0c070ff2u,0x0c070ff4u,0x0c070ff6u,0x0c070ff8u,0x0c070ffau,0x0c070ffcu,0x0c070ffeu,0x0c071000u,0x0c071002u,0x0c071004u,
0x0c071006u,0x0c071008u,0x0c07100au,0x0c07100cu,0x0c07100eu,0x0c071010u,0x0c071012u,0x0c071014u,0x0c071016u,0x0c071018u,0x0c07101au,0x0c07101cu,0x0c07101eu,0x0c071020u,0x0c071022u,0x0c071024u,
0x0c071026u,0x0c071028u,0x0c07102au,0x0c07102cu,0x0c07102eu,0x0c071030u,0x0c071032u,0x0c071034u,0x0c071036u,0x0c071038u,0x0c07103au,0x0c07103cu,0x0c07103eu,0x0c071040u,0x0c071042u,0x0c071044u,
0x0c071046u,0x0c071048u,0x0c07104au,0x0c07104cu,0x0c07104eu,0x0c071050u,0x0c071052u,0x0c071054u,0x0c071056u,0x0c071058u,0x0c07105au,0x0c07105cu,0x0c07105eu,0x0c071060u,0x0c071062u,0x0c071064u,
0x0c071066u,0x0c071068u,0x0c07106au,0x0c07106cu,0x0c07106eu,0x0c074930u,0x0c074932u,0x0c074934u,0x0c074936u,0x0c074938u,0x0c07493au,0x0c07493cu,0x0c07493eu,0x0c074940u,0x0c074942u,0x0c074944u,
0x0c074946u,0x0c074948u,0x0c07494au,0x0c07494cu,0x0c07494eu,0x0c074950u,0x0c074952u,0x0c074954u,0x0c074956u,0x0c074958u,0x0c07495au,0x0c07495cu,0x0c07495eu,0x0c074960u,0x0c074962u,0x0c074964u,
0x0c074966u,0x0c074968u,0x0c07496au,0x0c07496cu,0x0c07496eu,0x0c074970u,0x0c074972u,0x0c074974u,0x0c074976u,0x0c074978u,0x0c07497au,0x0c07497cu,0x0c07497eu,0x0c074980u,0x0c074982u,0x0c074984u,
0x0c074986u,0x0c074988u,0x0c07498au,0x0c07498cu,0x0c07498eu,0x0c074990u,0x0c074992u,0x0c074994u,0x0c074996u,0x0c074998u,0x0c07499au,0x0c07499cu,0x0c07499eu,0x0c0749ccu,0x0c0749ceu,0x0c0749d0u,
0x0c0749d2u,0x0c0749d4u,0x0c0749d6u,0x0c0749d8u,0x0c0749dau,0x0c0749dcu,0x0c0749deu,0x0c0749e0u,0x0c0749e2u,0x0c0749e4u,0x0c0749e6u,0x0c0749e8u,0x0c0749eau,0x0c0749ecu,0x0c0749eeu,0x0c0749f0u,
0x0c0749f2u,0x0c0749f4u,0x0c0749f6u,0x0c0749f8u,0x0c0749fau,0x0c0749fcu,0x0c0749feu,0x0c074a00u,0x0c074a02u,0x0c074a04u,0x0c074a06u,0x0c074a08u,0x0c074a0au,0x0c074a0cu,0x0c074a0eu,0x0c074a10u,
0x0c074a12u,0x0c074a14u,0x0c074a16u,0x0c074a18u,0x0c074a1au,0x0c074a1cu,0x0c074a1eu,0x0c074a20u,0x0c074a22u,0x0c074a24u,0x0c074a26u,0x0c074a28u,0x0c074a2au,0x0c074a2cu,0x0c074a2eu,0x0c074a30u,
0x0c074a32u,0x0c074a34u,0x0c074a36u,0x0c074a38u,0x0c074a52u,0x0c074a54u,0x0c074a56u,0x0c074a58u,0x0c074a5au,0x0c074a5cu,0x0c074a5eu,0x0c074a60u,0x0c074a62u,0x0c074a64u,0x0c074a66u,0x0c074a68u,
0x0c074a6au,0x0c074a6cu,0x0c074a6eu,0x0c074a70u,0x0c074a72u,0x0c074a74u,0x0c074a76u,0x0c074a78u,0x0c074a7au,0x0c074a7cu,0x0c074a7eu,0x0c074a80u,0x0c074a82u,0x0c074a84u,0x0c074a86u,0x0c074a88u,
0x0c074a8au,0x0c074a8cu,0x0c074a8eu,0x0c074a90u,0x0c074a92u,0x0c074a94u,0x0c074a96u,0x0c074a98u,0x0c074a9au,0x0c074a9cu,0x0c074a9eu,0x0c074aa0u,0x0c074aa2u,0x0c074aa4u,0x0c074aa6u,0x0c074aa8u,
0x0c074aaau,0x0c074aacu,0x0c074aaeu,0x0c074ab0u,0x0c074ab2u,0x0c074ab4u,0x0c074ab6u,0x0c074ae8u,0x0c074aeau,0x0c074aecu,0x0c074aeeu,0x0c074af0u,0x0c074af2u,0x0c074af4u,0x0c074af6u,0x0c074af8u,
0x0c074afau,0x0c074afcu,0x0c074afeu,0x0c074b00u,0x0c074b02u,0x0c074b04u,0x0c074b06u,0x0c074b08u,0x0c074b0au,0x0c074b0cu,0x0c074b0eu,0x0c074b10u,0x0c074b12u,0x0c074b14u,0x0c074b16u,0x0c074b18u,
0x0c074b1au,0x0c074b1cu,0x0c074b1eu,0x0c074b20u,0x0c074b22u,0x0c074b24u,0x0c074b26u,0x0c074b28u,0x0c074b2au,0x0c074b2cu,0x0c074b2eu,0x0c074b30u,0x0c074b32u,0x0c074b34u,0x0c074b36u,0x0c074b38u,
0x0c074b3au,0x0c074b3cu,0x0c074b3eu,0x0c074b40u,0x0c074b42u,0x0c074b44u,0x0c074b46u,0x0c074b48u,0x0c074b4au,0x0c074b4cu,0x0c074b4eu,0x0c074b50u,0x0c074b52u,0x0c074b54u,0x0c074b56u,0x0c074b58u,
0x0c074b5au,0x0c074b5cu,0x0c074b5eu,0x0c074b60u,0x0c074b62u,0x0c074b64u,0x0c074b66u,0x0c074b68u,0x0c074b6au,0x0c074b6cu,0x0c074b6eu,0x0c074b70u,0x0c074b72u,0x0c074b74u,0x0c074b76u,0x0c074b78u,
0x0c074b7au,0x0c074b7cu,0x0c074b7eu,0x0c074b80u,0x0c074b82u,0x0c074b84u,0x0c074b86u,0x0c074b88u,0x0c074b8au,0x0c074b8cu,0x0c074b8eu,0x0c074b90u,0x0c074b92u,0x0c074b94u,0x0c074b96u,0x0c074b98u,
0x0c074b9au,0x0c074b9cu,0x0c074b9eu,0x0c074ba0u,0x0c074ba2u,0x0c074ba4u,0x0c074ba6u,0x0c074ba8u,0x0c074baau,0x0c074bacu,0x0c074baeu,0x0c074bb0u,0x0c074bb2u,0x0c074bb4u,0x0c074bb6u,0x0c074bb8u,
0x0c074bbau,0x0c074bbcu,0x0c074bbeu,0x0c074bc0u,0x0c074bc2u,0x0c074bc4u,0x0c074bc6u,0x0c074bc8u,0x0c074bcau,0x0c074bccu,0x0c074bf8u,0x0c074bfau,0x0c074bfcu,0x0c074bfeu,0x0c074c00u,0x0c074c02u,
0x0c074c04u,0x0c074c06u,0x0c074c08u,0x0c074c0au,0x0c074c0cu,0x0c074c0eu,0x0c074c10u,0x0c074c12u,0x0c074c14u,0x0c074c16u,0x0c074c18u,0x0c074c1au,0x0c074c1cu,0x0c074c1eu,0x0c074c20u,0x0c074c22u,
0x0c074c24u,0x0c074c26u,0x0c074c28u,0x0c074c2au,0x0c074c2cu,0x0c074c2eu,0x0c074c30u,0x0c074c32u,0x0c074c34u,0x0c074c36u,0x0c074c38u,0x0c074c3au,0x0c074c3cu,0x0c074c3eu,0x0c074c40u,0x0c074c42u,
0x0c074c44u,0x0c074c46u,0x0c074c48u,0x0c074c4au,0x0c074c4cu,0x0c074c4eu,0x0c074c50u,0x0c074c52u,0x0c074c54u,0x0c074c56u,0x0c074c58u,0x0c074c5au,0x0c074c5cu,0x0c074c5eu,0x0c074c60u,0x0c074c62u,
0x0c074c64u,0x0c074c66u,0x0c074c68u,0x0c074c6au,0x0c074c6cu,0x0c074c6eu,0x0c074c70u,0x0c074c72u,0x0c074c74u,0x0c074c76u,0x0c074c78u,0x0c074c7au,0x0c074c7cu,0x0c074c7eu,0x0c074c80u,0x0c074c82u,
0x0c074c84u,0x0c074c86u,0x0c074c88u,0x0c074c8au,0x0c074c8cu,0x0c074c8eu,0x0c074c90u,0x0c074c92u,0x0c074c94u,0x0c074c96u,0x0c074c98u,0x0c074c9au,0x0c074c9cu,0x0c074c9eu,0x0c074ca0u,0x0c074ca2u,
0x0c074ca4u,0x0c074ca6u,0x0c074ca8u,0x0c074caau,0x0c074cacu,0x0c074caeu,0x0c074cb0u,0x0c074cb2u,0x0c074cb4u,0x0c074cb6u,0x0c074cb8u,0x0c074cbau,0x0c074cbcu,0x0c074cd4u,0x0c074cd6u,0x0c074cd8u,
0x0c074cdau,0x0c074cdcu,0x0c074cdeu,0x0c074ce0u,0x0c074ce2u,0x0c074ce4u,0x0c074ce6u,0x0c074ce8u,0x0c074ceau,0x0c074cecu,0x0c074ceeu,0x0c074cf0u,0x0c074cf2u,0x0c074cf4u,0x0c074cf6u,0x0c074cf8u,
0x0c074cfau,0x0c074cfcu,0x0c074cfeu,0x0c074d00u,0x0c074d02u,0x0c074d04u,0x0c074d06u,0x0c074d08u,0x0c074d0au,0x0c074d0cu,0x0c074d0eu,0x0c074d10u,0x0c074d12u,0x0c074d14u,0x0c074d16u,0x0c074d18u,
0x0c074d1au,0x0c074d1cu,0x0c074d1eu,0x0c074d20u,0x0c074d22u,0x0c074d24u,0x0c074d26u,0x0c074d28u,0x0c074d2au,0x0c074d2cu,0x0c074d2eu,0x0c074d30u,0x0c074d32u,0x0c074d34u,0x0c074d36u,0x0c074d38u,
0x0c074d3au,0x0c074d3cu,0x0c074d3eu,0x0c074d40u,0x0c074d42u,0x0c074d44u,0x0c074d46u,0x0c074d48u,0x0c074d4au,0x0c074d4cu,0x0c074d4eu,0x0c074d50u,0x0c074d52u,0x0c074d54u,0x0c074d56u,0x0c074d58u,
0x0c074d5au,0x0c074d5cu,0x0c074d5eu,0x0c074d60u,0x0c074d62u,0x0c074d64u,0x0c074d66u,0x0c074d68u,0x0c074d6au,0x0c074d6cu,0x0c074d6eu,0x0c074d70u,0x0c074d72u,0x0c074d74u,0x0c074d76u,0x0c074d78u,
0x0c074d7au,0x0c074d7cu,0x0c074d7eu,0x0c074d80u,0x0c074d82u,0x0c074d84u,0x0c074d86u,0x0c074d88u,0x0c074d8au,0x0c074d8cu,0x0c074d8eu,0x0c074d90u,0x0c074db0u,0x0c074db2u,0x0c074db4u,0x0c074db6u,
0x0c074db8u,0x0c074dbau,0x0c074dbcu,0x0c074dbeu,0x0c074dc0u,0x0c074dc2u,0x0c074dc4u,0x0c074dc6u,0x0c074dc8u,0x0c074dcau,0x0c074dccu,0x0c074dceu,0x0c074dd0u,0x0c074dd2u,0x0c074dd4u,0x0c074dd6u,
0x0c074dd8u,0x0c074ddau,0x0c074ddcu,0x0c074ddeu,0x0c074de0u,0x0c074de2u,0x0c074de4u,0x0c074de6u,0x0c074de8u,0x0c074deau,0x0c074decu,0x0c074deeu,0x0c074df0u,0x0c074df2u,0x0c074df4u,0x0c074df6u,
0x0c074df8u,0x0c074dfau,0x0c074dfcu,0x0c074dfeu,0x0c074e00u,0x0c074e02u,0x0c074e04u,0x0c074e06u,0x0c074e08u,0x0c074e0au,0x0c074e0cu,0x0c074e0eu,0x0c074e10u,0x0c074e12u,0x0c074e14u,0x0c074e16u,
0x0c074e18u,0x0c074e1au,0x0c09381eu,0x0c093820u,0x0c093822u,0x0c093824u,0x0c093826u,0x0c093828u,0x0c09571cu,0x0c09571eu,0x0c095720u,0x0c095722u,0x0c0a2b98u,0x0c0a2b9au,0x0c0a2b9cu,0x0c0a2b9eu,
0x0c0a2ba0u,0x0c0a2ba2u,0x0c0a2ba4u,0x0c0a2ba6u,0x0c0a2ba8u,0x0c0a2baau,0x0c0a2bacu,0x0c0a2baeu,0x0c0a2bb0u,0x0c0a2bb2u,0x0c0a2bb4u,0x0c0a2bb6u,0x0c0a2bb8u,0x0c0a2bbau,0x0c0a2bbcu,0x0c0a2bbeu,
0x0c0a2bc0u,0x0c0a2bc2u,0x0c0a2bc4u,0x0c0a2bc6u,0x0c0a2bc8u,0x0c0a2bcau,0x0c0a2bccu,0x0c0a2bceu,0x0c0a2bd0u,0x0c0a2bd2u,0x0c0a2bd4u,0x0c0a2bd6u,0x0c0a2bd8u,0x0c0a2bdau,0x0c0a2bdcu,0x0c0a2bdeu,
0x0c0a2be0u,0x0c0a2be2u,0x0c0a2be4u,0x0c0a2be6u,0x0c0a2be8u,0x0c0a2beau,0x0c0a2becu,0x0c0a2beeu,0x0c0a2bf0u,0x0c0a2bf2u,0x0c0a2bf4u,0x0c0a2bf6u,0x0c0a2bf8u,0x0c0a2bfau,0x0c0a2bfcu,0x0c0a2bfeu,
0x0c0a2c00u,0x0c0a2c02u,0x0c0a2c04u,0x0c0a2c06u,0x0c0a2c08u,0x0c0a2c0au,0x0c0a2c0cu,0x0c0a2c0eu,0x0c0a2c10u,0x0c0a2c12u,0x0c0a2c14u,0x0c0a2c16u,0x0c0a2c18u,0x0c0a2c1au,0x0c0a2c1cu,0x0c0a2c1eu,
0x0c0a2c20u,0x0c0a2c22u,0x0c0a2c24u,0x0c0a2c26u,0x0c0a2c28u,0x0c0a2c2au,0x0c0a2c2cu,0x0c0a2c2eu,0x0c0a2c30u,0x0c0a2c32u,0x0c0a2c34u,0x0c0c7648u,0x0c0c764au,0x0c0c764cu,0x0c0c764eu,0x0c0c7650u,
0x0c0c7652u,0x0c0c7654u,0x0c0c7656u,0x0c0c7658u,0x0c0c765au,0x0c0c765cu,0x0c0c765eu,0x0c0c7660u,0x0c0c7662u,0x0c0c7664u,0x0c0c7666u,0x0c0c7668u,0x0c0c766au,0x0c0c766cu,0x0c0c766eu,0x0c0c7670u,
0x0c0c7672u,0x0c0c7674u,0x0c0c7676u,0x0c0c7678u,0x0c0c767au,0x0c0c767cu,0x0c0c767eu,0x0c0c7680u,0x0c0c7682u,0x0c0c7684u,0x0c0c7686u,0x0c0c7688u,0x0c0c768au,0x0c0c768cu,0x0c0c768eu,0x0c0c7690u,
0x0c0c7692u,0x0c0c7694u,0x0c0c7696u,0x0c0c7698u,0x0c0c769au,0x0c0c769cu,0x0c0c769eu,0x0c0c76a0u,0x0c0c76a2u,0x0c0c76a4u,0x0c0c76a6u,0x0c0c76a8u,0x0c0c76aau,0x0c0c76acu,0x0c0c76aeu,0x0c0c76b0u,
0x0c0c76b2u,0x0c0c76b4u,0x0c0c76b6u,0x0c0c76b8u,0x0c0c76bau,0x0c0c76bcu,0x0c0c76beu,
};
int vf3_seventh_c12_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
