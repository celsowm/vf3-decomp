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
int vf3_advance_closure_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c037e6eu: goto P_0c037e6e;
case 0x0c037e70u: goto P_0c037e70;
case 0x0c037e72u: goto P_0c037e72;
case 0x0c037e74u: goto P_0c037e74;
case 0x0c037e76u: goto P_0c037e76;
case 0x0c037e78u: goto P_0c037e78;
case 0x0c037e7au: goto P_0c037e7a;
case 0x0c037e7cu: goto P_0c037e7c;
case 0x0c037e7eu: goto P_0c037e7e;
case 0x0c037e80u: goto P_0c037e80;
case 0x0c037e82u: goto P_0c037e82;
case 0x0c037e84u: goto P_0c037e84;
case 0x0c037e86u: goto P_0c037e86;
case 0x0c037e88u: goto P_0c037e88;
case 0x0c037e8au: goto P_0c037e8a;
case 0x0c037e8cu: goto P_0c037e8c;
case 0x0c037e8eu: goto P_0c037e8e;
case 0x0c037e90u: goto P_0c037e90;
case 0x0c037e92u: goto P_0c037e92;
case 0x0c037e94u: goto P_0c037e94;
case 0x0c037e96u: goto P_0c037e96;
case 0x0c037e98u: goto P_0c037e98;
case 0x0c037e9au: goto P_0c037e9a;
case 0x0c037e9cu: goto P_0c037e9c;
case 0x0c037e9eu: goto P_0c037e9e;
case 0x0c037ea0u: goto P_0c037ea0;
case 0x0c037ea2u: goto P_0c037ea2;
case 0x0c037ea4u: goto P_0c037ea4;
case 0x0c037ea6u: goto P_0c037ea6;
case 0x0c037ea8u: goto P_0c037ea8;
case 0x0c037eaau: goto P_0c037eaa;
case 0x0c037eacu: goto P_0c037eac;
case 0x0c037eaeu: goto P_0c037eae;
case 0x0c037eb0u: goto P_0c037eb0;
case 0x0c037eb2u: goto P_0c037eb2;
case 0x0c037eb4u: goto P_0c037eb4;
case 0x0c037eb6u: goto P_0c037eb6;
case 0x0c037eb8u: goto P_0c037eb8;
case 0x0c037ebau: goto P_0c037eba;
case 0x0c037ebcu: goto P_0c037ebc;
case 0x0c037ebeu: goto P_0c037ebe;
case 0x0c037ec0u: goto P_0c037ec0;
case 0x0c037ec2u: goto P_0c037ec2;
case 0x0c037ec4u: goto P_0c037ec4;
case 0x0c037ec6u: goto P_0c037ec6;
case 0x0c037ec8u: goto P_0c037ec8;
case 0x0c037ecau: goto P_0c037eca;
case 0x0c037eccu: goto P_0c037ecc;
case 0x0c037eceu: goto P_0c037ece;
case 0x0c037ed0u: goto P_0c037ed0;
case 0x0c037ed2u: goto P_0c037ed2;
case 0x0c037ed4u: goto P_0c037ed4;
case 0x0c037ed6u: goto P_0c037ed6;
case 0x0c037ed8u: goto P_0c037ed8;
case 0x0c037edau: goto P_0c037eda;
case 0x0c037edcu: goto P_0c037edc;
case 0x0c037edeu: goto P_0c037ede;
case 0x0c037ee0u: goto P_0c037ee0;
case 0x0c037ee2u: goto P_0c037ee2;
case 0x0c037ee4u: goto P_0c037ee4;
case 0x0c037ee6u: goto P_0c037ee6;
case 0x0c037ee8u: goto P_0c037ee8;
case 0x0c037eeau: goto P_0c037eea;
case 0x0c037eecu: goto P_0c037eec;
case 0x0c037eeeu: goto P_0c037eee;
case 0x0c037ef0u: goto P_0c037ef0;
case 0x0c037ef2u: goto P_0c037ef2;
case 0x0c037ef4u: goto P_0c037ef4;
case 0x0c037ef6u: goto P_0c037ef6;
case 0x0c037ef8u: goto P_0c037ef8;
case 0x0c037efau: goto P_0c037efa;
case 0x0c037efcu: goto P_0c037efc;
case 0x0c037efeu: goto P_0c037efe;
case 0x0c037f00u: goto P_0c037f00;
case 0x0c037f02u: goto P_0c037f02;
case 0x0c037f04u: goto P_0c037f04;
case 0x0c037f06u: goto P_0c037f06;
case 0x0c037f08u: goto P_0c037f08;
case 0x0c037f0au: goto P_0c037f0a;
case 0x0c037f0cu: goto P_0c037f0c;
case 0x0c037f0eu: goto P_0c037f0e;
case 0x0c037f10u: goto P_0c037f10;
case 0x0c037f2eu: goto P_0c037f2e;
case 0x0c037f30u: goto P_0c037f30;
case 0x0c037f32u: goto P_0c037f32;
case 0x0c037f34u: goto P_0c037f34;
case 0x0c037f36u: goto P_0c037f36;
case 0x0c037f38u: goto P_0c037f38;
case 0x0c037f3au: goto P_0c037f3a;
case 0x0c037f3cu: goto P_0c037f3c;
case 0x0c037f3eu: goto P_0c037f3e;
case 0x0c037f40u: goto P_0c037f40;
case 0x0c037f42u: goto P_0c037f42;
case 0x0c037f44u: goto P_0c037f44;
case 0x0c037f46u: goto P_0c037f46;
case 0x0c037f48u: goto P_0c037f48;
case 0x0c037f4au: goto P_0c037f4a;
case 0x0c037f4cu: goto P_0c037f4c;
case 0x0c037f4eu: goto P_0c037f4e;
case 0x0c037f50u: goto P_0c037f50;
case 0x0c037f52u: goto P_0c037f52;
case 0x0c037f54u: goto P_0c037f54;
case 0x0c037f56u: goto P_0c037f56;
case 0x0c037f58u: goto P_0c037f58;
case 0x0c037f5au: goto P_0c037f5a;
case 0x0c037f5cu: goto P_0c037f5c;
case 0x0c037f5eu: goto P_0c037f5e;
case 0x0c037f60u: goto P_0c037f60;
case 0x0c037f62u: goto P_0c037f62;
case 0x0c037f64u: goto P_0c037f64;
case 0x0c037f66u: goto P_0c037f66;
case 0x0c037f68u: goto P_0c037f68;
case 0x0c037f6au: goto P_0c037f6a;
case 0x0c037f6cu: goto P_0c037f6c;
case 0x0c037f6eu: goto P_0c037f6e;
case 0x0c037f70u: goto P_0c037f70;
case 0x0c037f72u: goto P_0c037f72;
case 0x0c037f74u: goto P_0c037f74;
case 0x0c037f76u: goto P_0c037f76;
case 0x0c037f78u: goto P_0c037f78;
case 0x0c037f7au: goto P_0c037f7a;
case 0x0c037f7cu: goto P_0c037f7c;
case 0x0c037f7eu: goto P_0c037f7e;
case 0x0c037f80u: goto P_0c037f80;
case 0x0c037f82u: goto P_0c037f82;
case 0x0c037f84u: goto P_0c037f84;
case 0x0c037f86u: goto P_0c037f86;
case 0x0c037f88u: goto P_0c037f88;
case 0x0c037f8au: goto P_0c037f8a;
case 0x0c037f8cu: goto P_0c037f8c;
case 0x0c037f8eu: goto P_0c037f8e;
case 0x0c037f90u: goto P_0c037f90;
case 0x0c037f92u: goto P_0c037f92;
case 0x0c037f94u: goto P_0c037f94;
case 0x0c037f96u: goto P_0c037f96;
case 0x0c037f98u: goto P_0c037f98;
case 0x0c037f9au: goto P_0c037f9a;
case 0x0c037f9cu: goto P_0c037f9c;
case 0x0c037f9eu: goto P_0c037f9e;
case 0x0c037fa0u: goto P_0c037fa0;
case 0x0c037fa2u: goto P_0c037fa2;
case 0x0c037fa4u: goto P_0c037fa4;
case 0x0c037fa6u: goto P_0c037fa6;
case 0x0c037fa8u: goto P_0c037fa8;
case 0x0c037faau: goto P_0c037faa;
case 0x0c037facu: goto P_0c037fac;
case 0x0c037faeu: goto P_0c037fae;
case 0x0c037fb0u: goto P_0c037fb0;
case 0x0c037fb2u: goto P_0c037fb2;
case 0x0c037fb4u: goto P_0c037fb4;
case 0x0c037fb6u: goto P_0c037fb6;
case 0x0c037fb8u: goto P_0c037fb8;
case 0x0c037fbau: goto P_0c037fba;
case 0x0c037fbcu: goto P_0c037fbc;
case 0x0c037fbeu: goto P_0c037fbe;
case 0x0c037fc0u: goto P_0c037fc0;
case 0x0c037fc2u: goto P_0c037fc2;
case 0x0c037fc4u: goto P_0c037fc4;
case 0x0c037fc6u: goto P_0c037fc6;
case 0x0c037fc8u: goto P_0c037fc8;
case 0x0c037fcau: goto P_0c037fca;
case 0x0c037fccu: goto P_0c037fcc;
case 0x0c037fceu: goto P_0c037fce;
case 0x0c037ffeu: goto P_0c037ffe;
case 0x0c038000u: goto P_0c038000;
case 0x0c038002u: goto P_0c038002;
case 0x0c038004u: goto P_0c038004;
case 0x0c038006u: goto P_0c038006;
case 0x0c038008u: goto P_0c038008;
case 0x0c03800au: goto P_0c03800a;
case 0x0c03800cu: goto P_0c03800c;
case 0x0c03800eu: goto P_0c03800e;
case 0x0c038010u: goto P_0c038010;
case 0x0c038012u: goto P_0c038012;
case 0x0c038014u: goto P_0c038014;
case 0x0c038016u: goto P_0c038016;
case 0x0c038018u: goto P_0c038018;
case 0x0c03801au: goto P_0c03801a;
case 0x0c03801cu: goto P_0c03801c;
case 0x0c03801eu: goto P_0c03801e;
case 0x0c038020u: goto P_0c038020;
case 0x0c038022u: goto P_0c038022;
case 0x0c038024u: goto P_0c038024;
case 0x0c038026u: goto P_0c038026;
case 0x0c038028u: goto P_0c038028;
case 0x0c03802au: goto P_0c03802a;
case 0x0c03802cu: goto P_0c03802c;
case 0x0c03802eu: goto P_0c03802e;
case 0x0c038030u: goto P_0c038030;
case 0x0c038032u: goto P_0c038032;
case 0x0c038034u: goto P_0c038034;
case 0x0c038036u: goto P_0c038036;
case 0x0c038038u: goto P_0c038038;
case 0x0c03803au: goto P_0c03803a;
case 0x0c03803cu: goto P_0c03803c;
case 0x0c03803eu: goto P_0c03803e;
case 0x0c038040u: goto P_0c038040;
case 0x0c038042u: goto P_0c038042;
case 0x0c038044u: goto P_0c038044;
case 0x0c038046u: goto P_0c038046;
case 0x0c038048u: goto P_0c038048;
case 0x0c03804au: goto P_0c03804a;
case 0x0c03804cu: goto P_0c03804c;
case 0x0c03804eu: goto P_0c03804e;
case 0x0c038050u: goto P_0c038050;
case 0x0c038052u: goto P_0c038052;
case 0x0c038054u: goto P_0c038054;
case 0x0c038056u: goto P_0c038056;
case 0x0c038058u: goto P_0c038058;
case 0x0c03805au: goto P_0c03805a;
case 0x0c03805cu: goto P_0c03805c;
case 0x0c03805eu: goto P_0c03805e;
case 0x0c038060u: goto P_0c038060;
case 0x0c038062u: goto P_0c038062;
case 0x0c038064u: goto P_0c038064;
case 0x0c038066u: goto P_0c038066;
case 0x0c038068u: goto P_0c038068;
case 0x0c03806au: goto P_0c03806a;
case 0x0c03806cu: goto P_0c03806c;
case 0x0c03806eu: goto P_0c03806e;
case 0x0c038070u: goto P_0c038070;
case 0x0c038072u: goto P_0c038072;
case 0x0c038074u: goto P_0c038074;
case 0x0c038076u: goto P_0c038076;
case 0x0c038078u: goto P_0c038078;
case 0x0c03807au: goto P_0c03807a;
case 0x0c03807cu: goto P_0c03807c;
case 0x0c03807eu: goto P_0c03807e;
case 0x0c038080u: goto P_0c038080;
case 0x0c038082u: goto P_0c038082;
case 0x0c038084u: goto P_0c038084;
case 0x0c038086u: goto P_0c038086;
case 0x0c038088u: goto P_0c038088;
case 0x0c03808au: goto P_0c03808a;
case 0x0c03808cu: goto P_0c03808c;
case 0x0c03808eu: goto P_0c03808e;
case 0x0c038090u: goto P_0c038090;
case 0x0c038092u: goto P_0c038092;
case 0x0c038094u: goto P_0c038094;
case 0x0c038096u: goto P_0c038096;
case 0x0c038098u: goto P_0c038098;
case 0x0c03809au: goto P_0c03809a;
case 0x0c03809cu: goto P_0c03809c;
case 0x0c03809eu: goto P_0c03809e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c037e6e: /* original 4f22, guest PC 0x0c037e6e */
if(!s->budget--) { s->failed_pc=0x0c037e6eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c037e70;
P_0c037e70: /* original e206, guest PC 0x0c037e70 */
if(!s->budget--) { s->failed_pc=0x0c037e70u; return 0; }
r[2]=0x00000006u;
goto P_0c037e72;
P_0c037e72: /* original e604, guest PC 0x0c037e72 */
if(!s->budget--) { s->failed_pc=0x0c037e72u; return 0; }
r[6]=0x00000004u;
goto P_0c037e74;
P_0c037e74: /* original e501, guest PC 0x0c037e74 */
if(!s->budget--) { s->failed_pc=0x0c037e74u; return 0; }
r[5]=0x00000001u;
goto P_0c037e76;
P_0c037e76: /* original 1e51, guest PC 0x0c037e76 */
if(!s->budget--) { s->failed_pc=0x0c037e76u; return 0; }
write(ram,r[14]+4,r[5],4);
goto P_0c037e78;
P_0c037e78: /* original 1e52, guest PC 0x0c037e78 */
if(!s->budget--) { s->failed_pc=0x0c037e78u; return 0; }
write(ram,r[14]+8,r[5],4);
goto P_0c037e7a;
P_0c037e7a: /* original 1e43, guest PC 0x0c037e7a */
if(!s->budget--) { s->failed_pc=0x0c037e7au; return 0; }
write(ram,r[14]+12,r[4],4);
goto P_0c037e7c;
P_0c037e7c: /* original 0e46, guest PC 0x0c037e7c */
if(!s->budget--) { s->failed_pc=0x0c037e7cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c037e7e;
P_0c037e7e: /* original 1e44, guest PC 0x0c037e7e */
if(!s->budget--) { s->failed_pc=0x0c037e7eu; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c037e80;
P_0c037e80: /* original 1e65, guest PC 0x0c037e80 */
if(!s->budget--) { s->failed_pc=0x0c037e80u; return 0; }
write(ram,r[14]+20,r[6],4);
goto P_0c037e82;
P_0c037e82: /* original 1e46, guest PC 0x0c037e82 */
if(!s->budget--) { s->failed_pc=0x0c037e82u; return 0; }
write(ram,r[14]+24,r[4],4);
goto P_0c037e84;
P_0c037e84: /* original 1e47, guest PC 0x0c037e84 */
if(!s->budget--) { s->failed_pc=0x0c037e84u; return 0; }
write(ram,r[14]+28,r[4],4);
goto P_0c037e86;
P_0c037e86: /* original 1e58, guest PC 0x0c037e86 */
if(!s->budget--) { s->failed_pc=0x0c037e86u; return 0; }
write(ram,r[14]+32,r[5],4);
goto P_0c037e88;
P_0c037e88: /* original 1e59, guest PC 0x0c037e88 */
if(!s->budget--) { s->failed_pc=0x0c037e88u; return 0; }
write(ram,r[14]+36,r[5],4);
goto P_0c037e8a;
P_0c037e8a: /* original 1e4a, guest PC 0x0c037e8a */
if(!s->budget--) { s->failed_pc=0x0c037e8au; return 0; }
write(ram,r[14]+40,r[4],4);
goto P_0c037e8c;
P_0c037e8c: /* original 1e3b, guest PC 0x0c037e8c */
if(!s->budget--) { s->failed_pc=0x0c037e8cu; return 0; }
write(ram,r[14]+44,r[3],4);
goto P_0c037e8e;
P_0c037e8e: /* original e302, guest PC 0x0c037e8e */
if(!s->budget--) { s->failed_pc=0x0c037e8eu; return 0; }
r[3]=0x00000002u;
goto P_0c037e90;
P_0c037e90: /* original 1e2c, guest PC 0x0c037e90 */
if(!s->budget--) { s->failed_pc=0x0c037e90u; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c037e92;
P_0c037e92: /* original 1e4d, guest PC 0x0c037e92 */
if(!s->budget--) { s->failed_pc=0x0c037e92u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c037e94;
P_0c037e94: /* original 1e4e, guest PC 0x0c037e94 */
if(!s->budget--) { s->failed_pc=0x0c037e94u; return 0; }
write(ram,r[14]+56,r[4],4);
goto P_0c037e96;
P_0c037e96: /* original 1e3f, guest PC 0x0c037e96 */
if(!s->budget--) { s->failed_pc=0x0c037e96u; return 0; }
write(ram,r[14]+60,r[3],4);
goto P_0c037e98;
P_0c037e98: /* original 0e46, guest PC 0x0c037e98 */
if(!s->budget--) { s->failed_pc=0x0c037e98u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c037e9a;
P_0c037e9a: /* original e044, guest PC 0x0c037e9a */
if(!s->budget--) { s->failed_pc=0x0c037e9au; return 0; }
r[0]=0x00000044u;
goto P_0c037e9c;
P_0c037e9c: /* original 0e46, guest PC 0x0c037e9c */
if(!s->budget--) { s->failed_pc=0x0c037e9cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c037e9e;
P_0c037e9e: /* original e04c, guest PC 0x0c037e9e */
if(!s->budget--) { s->failed_pc=0x0c037e9eu; return 0; }
r[0]=0x0000004cu;
goto P_0c037ea0;
P_0c037ea0: /* original 0e46, guest PC 0x0c037ea0 */
if(!s->budget--) { s->failed_pc=0x0c037ea0u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c037ea2;
P_0c037ea2: /* original e054, guest PC 0x0c037ea2 */
if(!s->budget--) { s->failed_pc=0x0c037ea2u; return 0; }
r[0]=0x00000054u;
goto P_0c037ea4;
P_0c037ea4: /* original 0e46, guest PC 0x0c037ea4 */
if(!s->budget--) { s->failed_pc=0x0c037ea4u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c037ea6;
P_0c037ea6: /* original e058, guest PC 0x0c037ea6 */
if(!s->budget--) { s->failed_pc=0x0c037ea6u; return 0; }
r[0]=0x00000058u;
goto P_0c037ea8;
P_0c037ea8: /* original 0e46, guest PC 0x0c037ea8 */
if(!s->budget--) { s->failed_pc=0x0c037ea8u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c037eaa;
P_0c037eaa: /* original e05c, guest PC 0x0c037eaa */
if(!s->budget--) { s->failed_pc=0x0c037eaau; return 0; }
r[0]=0x0000005cu;
goto P_0c037eac;
P_0c037eac: /* original 0e66, guest PC 0x0c037eac */
if(!s->budget--) { s->failed_pc=0x0c037eacu; return 0; }
write(ram,r[14]+r[0],r[6],4);
goto P_0c037eae;
P_0c037eae: /* original e060, guest PC 0x0c037eae */
if(!s->budget--) { s->failed_pc=0x0c037eaeu; return 0; }
r[0]=0x00000060u;
goto P_0c037eb0;
P_0c037eb0: /* original e303, guest PC 0x0c037eb0 */
if(!s->budget--) { s->failed_pc=0x0c037eb0u; return 0; }
r[3]=0x00000003u;
goto P_0c037eb2;
P_0c037eb2: /* original 0e36, guest PC 0x0c037eb2 */
if(!s->budget--) { s->failed_pc=0x0c037eb2u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c037eb4;
P_0c037eb4: /* original e06c, guest PC 0x0c037eb4 */
if(!s->budget--) { s->failed_pc=0x0c037eb4u; return 0; }
r[0]=0x0000006cu;
goto P_0c037eb6;
P_0c037eb6: /* original 0e46, guest PC 0x0c037eb6 */
if(!s->budget--) { s->failed_pc=0x0c037eb6u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c037eb8;
P_0c037eb8: /* original e064, guest PC 0x0c037eb8 */
if(!s->budget--) { s->failed_pc=0x0c037eb8u; return 0; }
r[0]=0x00000064u;
goto P_0c037eba;
P_0c037eba: /* original 0e46, guest PC 0x0c037eba */
if(!s->budget--) { s->failed_pc=0x0c037ebau; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c037ebc;
P_0c037ebc: /* original e068, guest PC 0x0c037ebc */
if(!s->budget--) { s->failed_pc=0x0c037ebcu; return 0; }
r[0]=0x00000068u;
goto P_0c037ebe;
P_0c037ebe: /* original 0e46, guest PC 0x0c037ebe */
if(!s->budget--) { s->failed_pc=0x0c037ebeu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c037ec0;
P_0c037ec0: /* original e070, guest PC 0x0c037ec0 */
if(!s->budget--) { s->failed_pc=0x0c037ec0u; return 0; }
r[0]=0x00000070u;
goto P_0c037ec2;
P_0c037ec2: /* original f49d, guest PC 0x0c037ec2 */
if(!s->budget--) { s->failed_pc=0x0c037ec2u; return 0; }
fr[4]=0x3f800000u;
goto P_0c037ec4;
P_0c037ec4: /* original fe47, guest PC 0x0c037ec4 */
if(!s->budget--) { s->failed_pc=0x0c037ec4u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c037ec6;
P_0c037ec6: /* original e074, guest PC 0x0c037ec6 */
if(!s->budget--) { s->failed_pc=0x0c037ec6u; return 0; }
r[0]=0x00000074u;
goto P_0c037ec8;
P_0c037ec8: /* original fe47, guest PC 0x0c037ec8 */
if(!s->budget--) { s->failed_pc=0x0c037ec8u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c037eca;
P_0c037eca: /* original e078, guest PC 0x0c037eca */
if(!s->budget--) { s->failed_pc=0x0c037ecau; return 0; }
r[0]=0x00000078u;
goto P_0c037ecc;
P_0c037ecc: /* original fe47, guest PC 0x0c037ecc */
if(!s->budget--) { s->failed_pc=0x0c037eccu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c037ece;
P_0c037ece: /* original e07c, guest PC 0x0c037ece */
if(!s->budget--) { s->failed_pc=0x0c037eceu; return 0; }
r[0]=0x0000007cu;
goto P_0c037ed0;
P_0c037ed0: /* original fe47, guest PC 0x0c037ed0 */
if(!s->budget--) { s->failed_pc=0x0c037ed0u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c037ed2;
P_0c037ed2: /* original 7004, guest PC 0x0c037ed2 */
if(!s->budget--) { s->failed_pc=0x0c037ed2u; return 0; }
r[0]+=0x00000004u;
goto P_0c037ed4;
P_0c037ed4: /* original fe47, guest PC 0x0c037ed4 */
if(!s->budget--) { s->failed_pc=0x0c037ed4u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c037ed6;
P_0c037ed6: /* original 7004, guest PC 0x0c037ed6 */
if(!s->budget--) { s->failed_pc=0x0c037ed6u; return 0; }
r[0]+=0x00000004u;
goto P_0c037ed8;
P_0c037ed8: /* original fe47, guest PC 0x0c037ed8 */
if(!s->budget--) { s->failed_pc=0x0c037ed8u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c037eda;
P_0c037eda: /* original 7004, guest PC 0x0c037eda */
if(!s->budget--) { s->failed_pc=0x0c037edau; return 0; }
r[0]+=0x00000004u;
goto P_0c037edc;
P_0c037edc: /* original fe47, guest PC 0x0c037edc */
if(!s->budget--) { s->failed_pc=0x0c037edcu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c037ede;
P_0c037ede: /* original 7004, guest PC 0x0c037ede */
if(!s->budget--) { s->failed_pc=0x0c037edeu; return 0; }
r[0]+=0x00000004u;
goto P_0c037ee0;
P_0c037ee0: /* original fe47, guest PC 0x0c037ee0 */
if(!s->budget--) { s->failed_pc=0x0c037ee0u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c037ee2;
P_0c037ee2: /* original 7014, guest PC 0x0c037ee2 */
if(!s->budget--) { s->failed_pc=0x0c037ee2u; return 0; }
r[0]+=0x00000014u;
goto P_0c037ee4;
P_0c037ee4: /* original d33c, guest PC 0x0c037ee4 */
if(!s->budget--) { s->failed_pc=0x0c037ee4u; return 0; }
r[3]=read(ram,0x0c037fd8u,4);
goto P_0c037ee6;
P_0c037ee6: /* original 0e36, guest PC 0x0c037ee6 */
if(!s->budget--) { s->failed_pc=0x0c037ee6u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c037ee8;
P_0c037ee8: /* original 7004, guest PC 0x0c037ee8 */
if(!s->budget--) { s->failed_pc=0x0c037ee8u; return 0; }
r[0]+=0x00000004u;
goto P_0c037eea;
P_0c037eea: /* original f48d, guest PC 0x0c037eea */
if(!s->budget--) { s->failed_pc=0x0c037eeau; return 0; }
fr[4]=0;
goto P_0c037eec;
P_0c037eec: /* original fe47, guest PC 0x0c037eec */
if(!s->budget--) { s->failed_pc=0x0c037eecu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c037eee;
P_0c037eee: /* original 7004, guest PC 0x0c037eee */
if(!s->budget--) { s->failed_pc=0x0c037eeeu; return 0; }
r[0]+=0x00000004u;
goto P_0c037ef0;
P_0c037ef0: /* original fe47, guest PC 0x0c037ef0 */
if(!s->budget--) { s->failed_pc=0x0c037ef0u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c037ef2;
P_0c037ef2: /* original c73a, guest PC 0x0c037ef2 */
if(!s->budget--) { s->failed_pc=0x0c037ef2u; return 0; }
r[0]=0x0c037fdcu;
goto P_0c037ef4;
P_0c037ef4: /* original f308, guest PC 0x0c037ef4 */
if(!s->budget--) { s->failed_pc=0x0c037ef4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c037ef6;
P_0c037ef6: /* original 906b, guest PC 0x0c037ef6 */
if(!s->budget--) { s->failed_pc=0x0c037ef6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c037fd0u,2);
goto P_0c037ef8;
P_0c037ef8: /* original fe37, guest PC 0x0c037ef8 */
if(!s->budget--) { s->failed_pc=0x0c037ef8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c037efa;
P_0c037efa: /* original c739, guest PC 0x0c037efa */
if(!s->budget--) { s->failed_pc=0x0c037efau; return 0; }
r[0]=0x0c037fe0u;
goto P_0c037efc;
P_0c037efc: /* original f308, guest PC 0x0c037efc */
if(!s->budget--) { s->failed_pc=0x0c037efcu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c037efe;
P_0c037efe: /* original 9068, guest PC 0x0c037efe */
if(!s->budget--) { s->failed_pc=0x0c037efeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c037fd2u,2);
goto P_0c037f00;
P_0c037f00: /* original fe37, guest PC 0x0c037f00 */
if(!s->budget--) { s->failed_pc=0x0c037f00u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c037f02;
P_0c037f02: /* original d338, guest PC 0x0c037f02 */
if(!s->budget--) { s->failed_pc=0x0c037f02u; return 0; }
r[3]=read(ram,0x0c037fe4u,4);
goto P_0c037f04;
P_0c037f04: /* original 430b, guest PC 0x0c037f04 */
if(!s->budget--) { s->failed_pc=0x0c037f04u; return 0; }
target=r[3];
r[16]=0x0c037f08u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c037f08u) { target=s->pc; goto dispatch; }
goto P_0c037f08;
P_0c037f06: /* original 64e3, guest PC 0x0c037f06 */
if(!s->budget--) { s->failed_pc=0x0c037f06u; return 0; }
r[4]=r[14];
goto P_0c037f08;
P_0c037f08: /* original 4f26, guest PC 0x0c037f08 */
if(!s->budget--) { s->failed_pc=0x0c037f08u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c037f0a;
P_0c037f0a: /* original d237, guest PC 0x0c037f0a */
if(!s->budget--) { s->failed_pc=0x0c037f0au; return 0; }
r[2]=read(ram,0x0c037fe8u,4);
goto P_0c037f0c;
P_0c037f0c: /* original 64e3, guest PC 0x0c037f0c */
if(!s->budget--) { s->failed_pc=0x0c037f0cu; return 0; }
r[4]=r[14];
goto P_0c037f0e;
P_0c037f0e: /* original 422b, guest PC 0x0c037f0e */
if(!s->budget--) { s->failed_pc=0x0c037f0eu; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c037f10: /* original 6ef6, guest PC 0x0c037f10 */
if(!s->budget--) { s->failed_pc=0x0c037f10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c037f12u,s,ram);
P_0c037f2e: /* original 4f22, guest PC 0x0c037f2e */
if(!s->budget--) { s->failed_pc=0x0c037f2eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c037f30;
P_0c037f30: /* original e206, guest PC 0x0c037f30 */
if(!s->budget--) { s->failed_pc=0x0c037f30u; return 0; }
r[2]=0x00000006u;
goto P_0c037f32;
P_0c037f32: /* original e604, guest PC 0x0c037f32 */
if(!s->budget--) { s->failed_pc=0x0c037f32u; return 0; }
r[6]=0x00000004u;
goto P_0c037f34;
P_0c037f34: /* original e501, guest PC 0x0c037f34 */
if(!s->budget--) { s->failed_pc=0x0c037f34u; return 0; }
r[5]=0x00000001u;
goto P_0c037f36;
P_0c037f36: /* original 1e51, guest PC 0x0c037f36 */
if(!s->budget--) { s->failed_pc=0x0c037f36u; return 0; }
write(ram,r[14]+4,r[5],4);
goto P_0c037f38;
P_0c037f38: /* original 1e52, guest PC 0x0c037f38 */
if(!s->budget--) { s->failed_pc=0x0c037f38u; return 0; }
write(ram,r[14]+8,r[5],4);
goto P_0c037f3a;
P_0c037f3a: /* original 1e43, guest PC 0x0c037f3a */
if(!s->budget--) { s->failed_pc=0x0c037f3au; return 0; }
write(ram,r[14]+12,r[4],4);
goto P_0c037f3c;
P_0c037f3c: /* original 0e46, guest PC 0x0c037f3c */
if(!s->budget--) { s->failed_pc=0x0c037f3cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c037f3e;
P_0c037f3e: /* original 1e44, guest PC 0x0c037f3e */
if(!s->budget--) { s->failed_pc=0x0c037f3eu; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c037f40;
P_0c037f40: /* original 1e65, guest PC 0x0c037f40 */
if(!s->budget--) { s->failed_pc=0x0c037f40u; return 0; }
write(ram,r[14]+20,r[6],4);
goto P_0c037f42;
P_0c037f42: /* original 1e46, guest PC 0x0c037f42 */
if(!s->budget--) { s->failed_pc=0x0c037f42u; return 0; }
write(ram,r[14]+24,r[4],4);
goto P_0c037f44;
P_0c037f44: /* original 1e47, guest PC 0x0c037f44 */
if(!s->budget--) { s->failed_pc=0x0c037f44u; return 0; }
write(ram,r[14]+28,r[4],4);
goto P_0c037f46;
P_0c037f46: /* original 1e58, guest PC 0x0c037f46 */
if(!s->budget--) { s->failed_pc=0x0c037f46u; return 0; }
write(ram,r[14]+32,r[5],4);
goto P_0c037f48;
P_0c037f48: /* original 1e59, guest PC 0x0c037f48 */
if(!s->budget--) { s->failed_pc=0x0c037f48u; return 0; }
write(ram,r[14]+36,r[5],4);
goto P_0c037f4a;
P_0c037f4a: /* original 1e4a, guest PC 0x0c037f4a */
if(!s->budget--) { s->failed_pc=0x0c037f4au; return 0; }
write(ram,r[14]+40,r[4],4);
goto P_0c037f4c;
P_0c037f4c: /* original 1e3b, guest PC 0x0c037f4c */
if(!s->budget--) { s->failed_pc=0x0c037f4cu; return 0; }
write(ram,r[14]+44,r[3],4);
goto P_0c037f4e;
P_0c037f4e: /* original e302, guest PC 0x0c037f4e */
if(!s->budget--) { s->failed_pc=0x0c037f4eu; return 0; }
r[3]=0x00000002u;
goto P_0c037f50;
P_0c037f50: /* original 1e2c, guest PC 0x0c037f50 */
if(!s->budget--) { s->failed_pc=0x0c037f50u; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c037f52;
P_0c037f52: /* original 1e4d, guest PC 0x0c037f52 */
if(!s->budget--) { s->failed_pc=0x0c037f52u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c037f54;
P_0c037f54: /* original 1e4e, guest PC 0x0c037f54 */
if(!s->budget--) { s->failed_pc=0x0c037f54u; return 0; }
write(ram,r[14]+56,r[4],4);
goto P_0c037f56;
P_0c037f56: /* original 1e3f, guest PC 0x0c037f56 */
if(!s->budget--) { s->failed_pc=0x0c037f56u; return 0; }
write(ram,r[14]+60,r[3],4);
goto P_0c037f58;
P_0c037f58: /* original 0e46, guest PC 0x0c037f58 */
if(!s->budget--) { s->failed_pc=0x0c037f58u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c037f5a;
P_0c037f5a: /* original e044, guest PC 0x0c037f5a */
if(!s->budget--) { s->failed_pc=0x0c037f5au; return 0; }
r[0]=0x00000044u;
goto P_0c037f5c;
P_0c037f5c: /* original 0e46, guest PC 0x0c037f5c */
if(!s->budget--) { s->failed_pc=0x0c037f5cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c037f5e;
P_0c037f5e: /* original e04c, guest PC 0x0c037f5e */
if(!s->budget--) { s->failed_pc=0x0c037f5eu; return 0; }
r[0]=0x0000004cu;
goto P_0c037f60;
P_0c037f60: /* original 0e46, guest PC 0x0c037f60 */
if(!s->budget--) { s->failed_pc=0x0c037f60u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c037f62;
P_0c037f62: /* original e054, guest PC 0x0c037f62 */
if(!s->budget--) { s->failed_pc=0x0c037f62u; return 0; }
r[0]=0x00000054u;
goto P_0c037f64;
P_0c037f64: /* original 0e46, guest PC 0x0c037f64 */
if(!s->budget--) { s->failed_pc=0x0c037f64u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c037f66;
P_0c037f66: /* original e058, guest PC 0x0c037f66 */
if(!s->budget--) { s->failed_pc=0x0c037f66u; return 0; }
r[0]=0x00000058u;
goto P_0c037f68;
P_0c037f68: /* original 0e46, guest PC 0x0c037f68 */
if(!s->budget--) { s->failed_pc=0x0c037f68u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c037f6a;
P_0c037f6a: /* original e05c, guest PC 0x0c037f6a */
if(!s->budget--) { s->failed_pc=0x0c037f6au; return 0; }
r[0]=0x0000005cu;
goto P_0c037f6c;
P_0c037f6c: /* original 0e66, guest PC 0x0c037f6c */
if(!s->budget--) { s->failed_pc=0x0c037f6cu; return 0; }
write(ram,r[14]+r[0],r[6],4);
goto P_0c037f6e;
P_0c037f6e: /* original e060, guest PC 0x0c037f6e */
if(!s->budget--) { s->failed_pc=0x0c037f6eu; return 0; }
r[0]=0x00000060u;
goto P_0c037f70;
P_0c037f70: /* original e303, guest PC 0x0c037f70 */
if(!s->budget--) { s->failed_pc=0x0c037f70u; return 0; }
r[3]=0x00000003u;
goto P_0c037f72;
P_0c037f72: /* original 0e36, guest PC 0x0c037f72 */
if(!s->budget--) { s->failed_pc=0x0c037f72u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c037f74;
P_0c037f74: /* original e06c, guest PC 0x0c037f74 */
if(!s->budget--) { s->failed_pc=0x0c037f74u; return 0; }
r[0]=0x0000006cu;
goto P_0c037f76;
P_0c037f76: /* original 0e46, guest PC 0x0c037f76 */
if(!s->budget--) { s->failed_pc=0x0c037f76u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c037f78;
P_0c037f78: /* original e064, guest PC 0x0c037f78 */
if(!s->budget--) { s->failed_pc=0x0c037f78u; return 0; }
r[0]=0x00000064u;
goto P_0c037f7a;
P_0c037f7a: /* original 0e46, guest PC 0x0c037f7a */
if(!s->budget--) { s->failed_pc=0x0c037f7au; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c037f7c;
P_0c037f7c: /* original e068, guest PC 0x0c037f7c */
if(!s->budget--) { s->failed_pc=0x0c037f7cu; return 0; }
r[0]=0x00000068u;
goto P_0c037f7e;
P_0c037f7e: /* original 0e46, guest PC 0x0c037f7e */
if(!s->budget--) { s->failed_pc=0x0c037f7eu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c037f80;
P_0c037f80: /* original e070, guest PC 0x0c037f80 */
if(!s->budget--) { s->failed_pc=0x0c037f80u; return 0; }
r[0]=0x00000070u;
goto P_0c037f82;
P_0c037f82: /* original f49d, guest PC 0x0c037f82 */
if(!s->budget--) { s->failed_pc=0x0c037f82u; return 0; }
fr[4]=0x3f800000u;
goto P_0c037f84;
P_0c037f84: /* original fe47, guest PC 0x0c037f84 */
if(!s->budget--) { s->failed_pc=0x0c037f84u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c037f86;
P_0c037f86: /* original e074, guest PC 0x0c037f86 */
if(!s->budget--) { s->failed_pc=0x0c037f86u; return 0; }
r[0]=0x00000074u;
goto P_0c037f88;
P_0c037f88: /* original fe47, guest PC 0x0c037f88 */
if(!s->budget--) { s->failed_pc=0x0c037f88u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c037f8a;
P_0c037f8a: /* original e078, guest PC 0x0c037f8a */
if(!s->budget--) { s->failed_pc=0x0c037f8au; return 0; }
r[0]=0x00000078u;
goto P_0c037f8c;
P_0c037f8c: /* original fe47, guest PC 0x0c037f8c */
if(!s->budget--) { s->failed_pc=0x0c037f8cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c037f8e;
P_0c037f8e: /* original e07c, guest PC 0x0c037f8e */
if(!s->budget--) { s->failed_pc=0x0c037f8eu; return 0; }
r[0]=0x0000007cu;
goto P_0c037f90;
P_0c037f90: /* original fe47, guest PC 0x0c037f90 */
if(!s->budget--) { s->failed_pc=0x0c037f90u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c037f92;
P_0c037f92: /* original 7004, guest PC 0x0c037f92 */
if(!s->budget--) { s->failed_pc=0x0c037f92u; return 0; }
r[0]+=0x00000004u;
goto P_0c037f94;
P_0c037f94: /* original fe47, guest PC 0x0c037f94 */
if(!s->budget--) { s->failed_pc=0x0c037f94u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c037f96;
P_0c037f96: /* original 7004, guest PC 0x0c037f96 */
if(!s->budget--) { s->failed_pc=0x0c037f96u; return 0; }
r[0]+=0x00000004u;
goto P_0c037f98;
P_0c037f98: /* original fe47, guest PC 0x0c037f98 */
if(!s->budget--) { s->failed_pc=0x0c037f98u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c037f9a;
P_0c037f9a: /* original 7004, guest PC 0x0c037f9a */
if(!s->budget--) { s->failed_pc=0x0c037f9au; return 0; }
r[0]+=0x00000004u;
goto P_0c037f9c;
P_0c037f9c: /* original fe47, guest PC 0x0c037f9c */
if(!s->budget--) { s->failed_pc=0x0c037f9cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c037f9e;
P_0c037f9e: /* original 7004, guest PC 0x0c037f9e */
if(!s->budget--) { s->failed_pc=0x0c037f9eu; return 0; }
r[0]+=0x00000004u;
goto P_0c037fa0;
P_0c037fa0: /* original fe47, guest PC 0x0c037fa0 */
if(!s->budget--) { s->failed_pc=0x0c037fa0u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c037fa2;
P_0c037fa2: /* original 7014, guest PC 0x0c037fa2 */
if(!s->budget--) { s->failed_pc=0x0c037fa2u; return 0; }
r[0]+=0x00000014u;
goto P_0c037fa4;
P_0c037fa4: /* original 0e46, guest PC 0x0c037fa4 */
if(!s->budget--) { s->failed_pc=0x0c037fa4u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c037fa6;
P_0c037fa6: /* original 7004, guest PC 0x0c037fa6 */
if(!s->budget--) { s->failed_pc=0x0c037fa6u; return 0; }
r[0]+=0x00000004u;
goto P_0c037fa8;
P_0c037fa8: /* original f48d, guest PC 0x0c037fa8 */
if(!s->budget--) { s->failed_pc=0x0c037fa8u; return 0; }
fr[4]=0;
goto P_0c037faa;
P_0c037faa: /* original fe47, guest PC 0x0c037faa */
if(!s->budget--) { s->failed_pc=0x0c037faau; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c037fac;
P_0c037fac: /* original 7004, guest PC 0x0c037fac */
if(!s->budget--) { s->failed_pc=0x0c037facu; return 0; }
r[0]+=0x00000004u;
goto P_0c037fae;
P_0c037fae: /* original fe47, guest PC 0x0c037fae */
if(!s->budget--) { s->failed_pc=0x0c037faeu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c037fb0;
P_0c037fb0: /* original c70a, guest PC 0x0c037fb0 */
if(!s->budget--) { s->failed_pc=0x0c037fb0u; return 0; }
r[0]=0x0c037fdcu;
goto P_0c037fb2;
P_0c037fb2: /* original f308, guest PC 0x0c037fb2 */
if(!s->budget--) { s->failed_pc=0x0c037fb2u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c037fb4;
P_0c037fb4: /* original 900c, guest PC 0x0c037fb4 */
if(!s->budget--) { s->failed_pc=0x0c037fb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c037fd0u,2);
goto P_0c037fb6;
P_0c037fb6: /* original fe37, guest PC 0x0c037fb6 */
if(!s->budget--) { s->failed_pc=0x0c037fb6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c037fb8;
P_0c037fb8: /* original c709, guest PC 0x0c037fb8 */
if(!s->budget--) { s->failed_pc=0x0c037fb8u; return 0; }
r[0]=0x0c037fe0u;
goto P_0c037fba;
P_0c037fba: /* original f308, guest PC 0x0c037fba */
if(!s->budget--) { s->failed_pc=0x0c037fbau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c037fbc;
P_0c037fbc: /* original 9009, guest PC 0x0c037fbc */
if(!s->budget--) { s->failed_pc=0x0c037fbcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c037fd2u,2);
goto P_0c037fbe;
P_0c037fbe: /* original fe37, guest PC 0x0c037fbe */
if(!s->budget--) { s->failed_pc=0x0c037fbeu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c037fc0;
P_0c037fc0: /* original d308, guest PC 0x0c037fc0 */
if(!s->budget--) { s->failed_pc=0x0c037fc0u; return 0; }
r[3]=read(ram,0x0c037fe4u,4);
goto P_0c037fc2;
P_0c037fc2: /* original 430b, guest PC 0x0c037fc2 */
if(!s->budget--) { s->failed_pc=0x0c037fc2u; return 0; }
target=r[3];
r[16]=0x0c037fc6u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c037fc6u) { target=s->pc; goto dispatch; }
goto P_0c037fc6;
P_0c037fc4: /* original 64e3, guest PC 0x0c037fc4 */
if(!s->budget--) { s->failed_pc=0x0c037fc4u; return 0; }
r[4]=r[14];
goto P_0c037fc6;
P_0c037fc6: /* original 4f26, guest PC 0x0c037fc6 */
if(!s->budget--) { s->failed_pc=0x0c037fc6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c037fc8;
P_0c037fc8: /* original d207, guest PC 0x0c037fc8 */
if(!s->budget--) { s->failed_pc=0x0c037fc8u; return 0; }
r[2]=read(ram,0x0c037fe8u,4);
goto P_0c037fca;
P_0c037fca: /* original 64e3, guest PC 0x0c037fca */
if(!s->budget--) { s->failed_pc=0x0c037fcau; return 0; }
r[4]=r[14];
goto P_0c037fcc;
P_0c037fcc: /* original 422b, guest PC 0x0c037fcc */
if(!s->budget--) { s->failed_pc=0x0c037fccu; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c037fce: /* original 6ef6, guest PC 0x0c037fce */
if(!s->budget--) { s->failed_pc=0x0c037fceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c037fd0u,s,ram);
P_0c037ffe: /* original 4f22, guest PC 0x0c037ffe */
if(!s->budget--) { s->failed_pc=0x0c037ffeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c038000;
P_0c038000: /* original e206, guest PC 0x0c038000 */
if(!s->budget--) { s->failed_pc=0x0c038000u; return 0; }
r[2]=0x00000006u;
goto P_0c038002;
P_0c038002: /* original e604, guest PC 0x0c038002 */
if(!s->budget--) { s->failed_pc=0x0c038002u; return 0; }
r[6]=0x00000004u;
goto P_0c038004;
P_0c038004: /* original e501, guest PC 0x0c038004 */
if(!s->budget--) { s->failed_pc=0x0c038004u; return 0; }
r[5]=0x00000001u;
goto P_0c038006;
P_0c038006: /* original 1e51, guest PC 0x0c038006 */
if(!s->budget--) { s->failed_pc=0x0c038006u; return 0; }
write(ram,r[14]+4,r[5],4);
goto P_0c038008;
P_0c038008: /* original 1e52, guest PC 0x0c038008 */
if(!s->budget--) { s->failed_pc=0x0c038008u; return 0; }
write(ram,r[14]+8,r[5],4);
goto P_0c03800a;
P_0c03800a: /* original 1e43, guest PC 0x0c03800a */
if(!s->budget--) { s->failed_pc=0x0c03800au; return 0; }
write(ram,r[14]+12,r[4],4);
goto P_0c03800c;
P_0c03800c: /* original 0e46, guest PC 0x0c03800c */
if(!s->budget--) { s->failed_pc=0x0c03800cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c03800e;
P_0c03800e: /* original 1e44, guest PC 0x0c03800e */
if(!s->budget--) { s->failed_pc=0x0c03800eu; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c038010;
P_0c038010: /* original 1e65, guest PC 0x0c038010 */
if(!s->budget--) { s->failed_pc=0x0c038010u; return 0; }
write(ram,r[14]+20,r[6],4);
goto P_0c038012;
P_0c038012: /* original 1e46, guest PC 0x0c038012 */
if(!s->budget--) { s->failed_pc=0x0c038012u; return 0; }
write(ram,r[14]+24,r[4],4);
goto P_0c038014;
P_0c038014: /* original 1e47, guest PC 0x0c038014 */
if(!s->budget--) { s->failed_pc=0x0c038014u; return 0; }
write(ram,r[14]+28,r[4],4);
goto P_0c038016;
P_0c038016: /* original 1e58, guest PC 0x0c038016 */
if(!s->budget--) { s->failed_pc=0x0c038016u; return 0; }
write(ram,r[14]+32,r[5],4);
goto P_0c038018;
P_0c038018: /* original 1e59, guest PC 0x0c038018 */
if(!s->budget--) { s->failed_pc=0x0c038018u; return 0; }
write(ram,r[14]+36,r[5],4);
goto P_0c03801a;
P_0c03801a: /* original 1e4a, guest PC 0x0c03801a */
if(!s->budget--) { s->failed_pc=0x0c03801au; return 0; }
write(ram,r[14]+40,r[4],4);
goto P_0c03801c;
P_0c03801c: /* original 1e3b, guest PC 0x0c03801c */
if(!s->budget--) { s->failed_pc=0x0c03801cu; return 0; }
write(ram,r[14]+44,r[3],4);
goto P_0c03801e;
P_0c03801e: /* original e302, guest PC 0x0c03801e */
if(!s->budget--) { s->failed_pc=0x0c03801eu; return 0; }
r[3]=0x00000002u;
goto P_0c038020;
P_0c038020: /* original 1e2c, guest PC 0x0c038020 */
if(!s->budget--) { s->failed_pc=0x0c038020u; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c038022;
P_0c038022: /* original 1e4d, guest PC 0x0c038022 */
if(!s->budget--) { s->failed_pc=0x0c038022u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c038024;
P_0c038024: /* original 1e4e, guest PC 0x0c038024 */
if(!s->budget--) { s->failed_pc=0x0c038024u; return 0; }
write(ram,r[14]+56,r[4],4);
goto P_0c038026;
P_0c038026: /* original 1e3f, guest PC 0x0c038026 */
if(!s->budget--) { s->failed_pc=0x0c038026u; return 0; }
write(ram,r[14]+60,r[3],4);
goto P_0c038028;
P_0c038028: /* original 0e46, guest PC 0x0c038028 */
if(!s->budget--) { s->failed_pc=0x0c038028u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c03802a;
P_0c03802a: /* original e044, guest PC 0x0c03802a */
if(!s->budget--) { s->failed_pc=0x0c03802au; return 0; }
r[0]=0x00000044u;
goto P_0c03802c;
P_0c03802c: /* original 0e46, guest PC 0x0c03802c */
if(!s->budget--) { s->failed_pc=0x0c03802cu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c03802e;
P_0c03802e: /* original e04c, guest PC 0x0c03802e */
if(!s->budget--) { s->failed_pc=0x0c03802eu; return 0; }
r[0]=0x0000004cu;
goto P_0c038030;
P_0c038030: /* original 0e46, guest PC 0x0c038030 */
if(!s->budget--) { s->failed_pc=0x0c038030u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038032;
P_0c038032: /* original e054, guest PC 0x0c038032 */
if(!s->budget--) { s->failed_pc=0x0c038032u; return 0; }
r[0]=0x00000054u;
goto P_0c038034;
P_0c038034: /* original 0e46, guest PC 0x0c038034 */
if(!s->budget--) { s->failed_pc=0x0c038034u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038036;
P_0c038036: /* original e058, guest PC 0x0c038036 */
if(!s->budget--) { s->failed_pc=0x0c038036u; return 0; }
r[0]=0x00000058u;
goto P_0c038038;
P_0c038038: /* original 0e46, guest PC 0x0c038038 */
if(!s->budget--) { s->failed_pc=0x0c038038u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c03803a;
P_0c03803a: /* original e05c, guest PC 0x0c03803a */
if(!s->budget--) { s->failed_pc=0x0c03803au; return 0; }
r[0]=0x0000005cu;
goto P_0c03803c;
P_0c03803c: /* original 0e66, guest PC 0x0c03803c */
if(!s->budget--) { s->failed_pc=0x0c03803cu; return 0; }
write(ram,r[14]+r[0],r[6],4);
goto P_0c03803e;
P_0c03803e: /* original e060, guest PC 0x0c03803e */
if(!s->budget--) { s->failed_pc=0x0c03803eu; return 0; }
r[0]=0x00000060u;
goto P_0c038040;
P_0c038040: /* original e303, guest PC 0x0c038040 */
if(!s->budget--) { s->failed_pc=0x0c038040u; return 0; }
r[3]=0x00000003u;
goto P_0c038042;
P_0c038042: /* original 0e36, guest PC 0x0c038042 */
if(!s->budget--) { s->failed_pc=0x0c038042u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c038044;
P_0c038044: /* original e06c, guest PC 0x0c038044 */
if(!s->budget--) { s->failed_pc=0x0c038044u; return 0; }
r[0]=0x0000006cu;
goto P_0c038046;
P_0c038046: /* original 0e46, guest PC 0x0c038046 */
if(!s->budget--) { s->failed_pc=0x0c038046u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038048;
P_0c038048: /* original e064, guest PC 0x0c038048 */
if(!s->budget--) { s->failed_pc=0x0c038048u; return 0; }
r[0]=0x00000064u;
goto P_0c03804a;
P_0c03804a: /* original 0e46, guest PC 0x0c03804a */
if(!s->budget--) { s->failed_pc=0x0c03804au; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c03804c;
P_0c03804c: /* original e068, guest PC 0x0c03804c */
if(!s->budget--) { s->failed_pc=0x0c03804cu; return 0; }
r[0]=0x00000068u;
goto P_0c03804e;
P_0c03804e: /* original 0e46, guest PC 0x0c03804e */
if(!s->budget--) { s->failed_pc=0x0c03804eu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038050;
P_0c038050: /* original e070, guest PC 0x0c038050 */
if(!s->budget--) { s->failed_pc=0x0c038050u; return 0; }
r[0]=0x00000070u;
goto P_0c038052;
P_0c038052: /* original f49d, guest PC 0x0c038052 */
if(!s->budget--) { s->failed_pc=0x0c038052u; return 0; }
fr[4]=0x3f800000u;
goto P_0c038054;
P_0c038054: /* original fe47, guest PC 0x0c038054 */
if(!s->budget--) { s->failed_pc=0x0c038054u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038056;
P_0c038056: /* original e074, guest PC 0x0c038056 */
if(!s->budget--) { s->failed_pc=0x0c038056u; return 0; }
r[0]=0x00000074u;
goto P_0c038058;
P_0c038058: /* original fe47, guest PC 0x0c038058 */
if(!s->budget--) { s->failed_pc=0x0c038058u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c03805a;
P_0c03805a: /* original e078, guest PC 0x0c03805a */
if(!s->budget--) { s->failed_pc=0x0c03805au; return 0; }
r[0]=0x00000078u;
goto P_0c03805c;
P_0c03805c: /* original fe47, guest PC 0x0c03805c */
if(!s->budget--) { s->failed_pc=0x0c03805cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c03805e;
P_0c03805e: /* original e07c, guest PC 0x0c03805e */
if(!s->budget--) { s->failed_pc=0x0c03805eu; return 0; }
r[0]=0x0000007cu;
goto P_0c038060;
P_0c038060: /* original fe47, guest PC 0x0c038060 */
if(!s->budget--) { s->failed_pc=0x0c038060u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038062;
P_0c038062: /* original 7004, guest PC 0x0c038062 */
if(!s->budget--) { s->failed_pc=0x0c038062u; return 0; }
r[0]+=0x00000004u;
goto P_0c038064;
P_0c038064: /* original fe47, guest PC 0x0c038064 */
if(!s->budget--) { s->failed_pc=0x0c038064u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038066;
P_0c038066: /* original 7004, guest PC 0x0c038066 */
if(!s->budget--) { s->failed_pc=0x0c038066u; return 0; }
r[0]+=0x00000004u;
goto P_0c038068;
P_0c038068: /* original fe47, guest PC 0x0c038068 */
if(!s->budget--) { s->failed_pc=0x0c038068u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c03806a;
P_0c03806a: /* original 7004, guest PC 0x0c03806a */
if(!s->budget--) { s->failed_pc=0x0c03806au; return 0; }
r[0]+=0x00000004u;
goto P_0c03806c;
P_0c03806c: /* original fe47, guest PC 0x0c03806c */
if(!s->budget--) { s->failed_pc=0x0c03806cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c03806e;
P_0c03806e: /* original 7004, guest PC 0x0c03806e */
if(!s->budget--) { s->failed_pc=0x0c03806eu; return 0; }
r[0]+=0x00000004u;
goto P_0c038070;
P_0c038070: /* original fe47, guest PC 0x0c038070 */
if(!s->budget--) { s->failed_pc=0x0c038070u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038072;
P_0c038072: /* original 7014, guest PC 0x0c038072 */
if(!s->budget--) { s->failed_pc=0x0c038072u; return 0; }
r[0]+=0x00000014u;
goto P_0c038074;
P_0c038074: /* original 0e46, guest PC 0x0c038074 */
if(!s->budget--) { s->failed_pc=0x0c038074u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c038076;
P_0c038076: /* original 7004, guest PC 0x0c038076 */
if(!s->budget--) { s->failed_pc=0x0c038076u; return 0; }
r[0]+=0x00000004u;
goto P_0c038078;
P_0c038078: /* original f48d, guest PC 0x0c038078 */
if(!s->budget--) { s->failed_pc=0x0c038078u; return 0; }
fr[4]=0;
goto P_0c03807a;
P_0c03807a: /* original fe47, guest PC 0x0c03807a */
if(!s->budget--) { s->failed_pc=0x0c03807au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c03807c;
P_0c03807c: /* original 7004, guest PC 0x0c03807c */
if(!s->budget--) { s->failed_pc=0x0c03807cu; return 0; }
r[0]+=0x00000004u;
goto P_0c03807e;
P_0c03807e: /* original fe47, guest PC 0x0c03807e */
if(!s->budget--) { s->failed_pc=0x0c03807eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c038080;
P_0c038080: /* original c729, guest PC 0x0c038080 */
if(!s->budget--) { s->failed_pc=0x0c038080u; return 0; }
r[0]=0x0c038128u;
goto P_0c038082;
P_0c038082: /* original f308, guest PC 0x0c038082 */
if(!s->budget--) { s->failed_pc=0x0c038082u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c038084;
P_0c038084: /* original 904b, guest PC 0x0c038084 */
if(!s->budget--) { s->failed_pc=0x0c038084u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03811eu,2);
goto P_0c038086;
P_0c038086: /* original fe37, guest PC 0x0c038086 */
if(!s->budget--) { s->failed_pc=0x0c038086u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c038088;
P_0c038088: /* original c728, guest PC 0x0c038088 */
if(!s->budget--) { s->failed_pc=0x0c038088u; return 0; }
r[0]=0x0c03812cu;
goto P_0c03808a;
P_0c03808a: /* original f308, guest PC 0x0c03808a */
if(!s->budget--) { s->failed_pc=0x0c03808au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c03808c;
P_0c03808c: /* original 9048, guest PC 0x0c03808c */
if(!s->budget--) { s->failed_pc=0x0c03808cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c038120u,2);
goto P_0c03808e;
P_0c03808e: /* original fe37, guest PC 0x0c03808e */
if(!s->budget--) { s->failed_pc=0x0c03808eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c038090;
P_0c038090: /* original d327, guest PC 0x0c038090 */
if(!s->budget--) { s->failed_pc=0x0c038090u; return 0; }
r[3]=read(ram,0x0c038130u,4);
goto P_0c038092;
P_0c038092: /* original 430b, guest PC 0x0c038092 */
if(!s->budget--) { s->failed_pc=0x0c038092u; return 0; }
target=r[3];
r[16]=0x0c038096u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c038096u) { target=s->pc; goto dispatch; }
goto P_0c038096;
P_0c038094: /* original 64e3, guest PC 0x0c038094 */
if(!s->budget--) { s->failed_pc=0x0c038094u; return 0; }
r[4]=r[14];
goto P_0c038096;
P_0c038096: /* original 4f26, guest PC 0x0c038096 */
if(!s->budget--) { s->failed_pc=0x0c038096u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c038098;
P_0c038098: /* original d226, guest PC 0x0c038098 */
if(!s->budget--) { s->failed_pc=0x0c038098u; return 0; }
r[2]=read(ram,0x0c038134u,4);
goto P_0c03809a;
P_0c03809a: /* original 64e3, guest PC 0x0c03809a */
if(!s->budget--) { s->failed_pc=0x0c03809au; return 0; }
r[4]=r[14];
goto P_0c03809c;
P_0c03809c: /* original 422b, guest PC 0x0c03809c */
if(!s->budget--) { s->failed_pc=0x0c03809cu; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c03809e: /* original 6ef6, guest PC 0x0c03809e */
if(!s->budget--) { s->failed_pc=0x0c03809eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0380a0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c037e6eu,0x0c037e70u,0x0c037e72u,0x0c037e74u,0x0c037e76u,0x0c037e78u,0x0c037e7au,0x0c037e7cu,0x0c037e7eu,0x0c037e80u,0x0c037e82u,0x0c037e84u,0x0c037e86u,0x0c037e88u,0x0c037e8au,0x0c037e8cu,
0x0c037e8eu,0x0c037e90u,0x0c037e92u,0x0c037e94u,0x0c037e96u,0x0c037e98u,0x0c037e9au,0x0c037e9cu,0x0c037e9eu,0x0c037ea0u,0x0c037ea2u,0x0c037ea4u,0x0c037ea6u,0x0c037ea8u,0x0c037eaau,0x0c037eacu,
0x0c037eaeu,0x0c037eb0u,0x0c037eb2u,0x0c037eb4u,0x0c037eb6u,0x0c037eb8u,0x0c037ebau,0x0c037ebcu,0x0c037ebeu,0x0c037ec0u,0x0c037ec2u,0x0c037ec4u,0x0c037ec6u,0x0c037ec8u,0x0c037ecau,0x0c037eccu,
0x0c037eceu,0x0c037ed0u,0x0c037ed2u,0x0c037ed4u,0x0c037ed6u,0x0c037ed8u,0x0c037edau,0x0c037edcu,0x0c037edeu,0x0c037ee0u,0x0c037ee2u,0x0c037ee4u,0x0c037ee6u,0x0c037ee8u,0x0c037eeau,0x0c037eecu,
0x0c037eeeu,0x0c037ef0u,0x0c037ef2u,0x0c037ef4u,0x0c037ef6u,0x0c037ef8u,0x0c037efau,0x0c037efcu,0x0c037efeu,0x0c037f00u,0x0c037f02u,0x0c037f04u,0x0c037f06u,0x0c037f08u,0x0c037f0au,0x0c037f0cu,
0x0c037f0eu,0x0c037f10u,0x0c037f2eu,0x0c037f30u,0x0c037f32u,0x0c037f34u,0x0c037f36u,0x0c037f38u,0x0c037f3au,0x0c037f3cu,0x0c037f3eu,0x0c037f40u,0x0c037f42u,0x0c037f44u,0x0c037f46u,0x0c037f48u,
0x0c037f4au,0x0c037f4cu,0x0c037f4eu,0x0c037f50u,0x0c037f52u,0x0c037f54u,0x0c037f56u,0x0c037f58u,0x0c037f5au,0x0c037f5cu,0x0c037f5eu,0x0c037f60u,0x0c037f62u,0x0c037f64u,0x0c037f66u,0x0c037f68u,
0x0c037f6au,0x0c037f6cu,0x0c037f6eu,0x0c037f70u,0x0c037f72u,0x0c037f74u,0x0c037f76u,0x0c037f78u,0x0c037f7au,0x0c037f7cu,0x0c037f7eu,0x0c037f80u,0x0c037f82u,0x0c037f84u,0x0c037f86u,0x0c037f88u,
0x0c037f8au,0x0c037f8cu,0x0c037f8eu,0x0c037f90u,0x0c037f92u,0x0c037f94u,0x0c037f96u,0x0c037f98u,0x0c037f9au,0x0c037f9cu,0x0c037f9eu,0x0c037fa0u,0x0c037fa2u,0x0c037fa4u,0x0c037fa6u,0x0c037fa8u,
0x0c037faau,0x0c037facu,0x0c037faeu,0x0c037fb0u,0x0c037fb2u,0x0c037fb4u,0x0c037fb6u,0x0c037fb8u,0x0c037fbau,0x0c037fbcu,0x0c037fbeu,0x0c037fc0u,0x0c037fc2u,0x0c037fc4u,0x0c037fc6u,0x0c037fc8u,
0x0c037fcau,0x0c037fccu,0x0c037fceu,0x0c037ffeu,0x0c038000u,0x0c038002u,0x0c038004u,0x0c038006u,0x0c038008u,0x0c03800au,0x0c03800cu,0x0c03800eu,0x0c038010u,0x0c038012u,0x0c038014u,0x0c038016u,
0x0c038018u,0x0c03801au,0x0c03801cu,0x0c03801eu,0x0c038020u,0x0c038022u,0x0c038024u,0x0c038026u,0x0c038028u,0x0c03802au,0x0c03802cu,0x0c03802eu,0x0c038030u,0x0c038032u,0x0c038034u,0x0c038036u,
0x0c038038u,0x0c03803au,0x0c03803cu,0x0c03803eu,0x0c038040u,0x0c038042u,0x0c038044u,0x0c038046u,0x0c038048u,0x0c03804au,0x0c03804cu,0x0c03804eu,0x0c038050u,0x0c038052u,0x0c038054u,0x0c038056u,
0x0c038058u,0x0c03805au,0x0c03805cu,0x0c03805eu,0x0c038060u,0x0c038062u,0x0c038064u,0x0c038066u,0x0c038068u,0x0c03806au,0x0c03806cu,0x0c03806eu,0x0c038070u,0x0c038072u,0x0c038074u,0x0c038076u,
0x0c038078u,0x0c03807au,0x0c03807cu,0x0c03807eu,0x0c038080u,0x0c038082u,0x0c038084u,0x0c038086u,0x0c038088u,0x0c03808au,0x0c03808cu,0x0c03808eu,0x0c038090u,0x0c038092u,0x0c038094u,0x0c038096u,
0x0c038098u,0x0c03809au,0x0c03809cu,0x0c03809eu,
};
int vf3_advance_closure_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
