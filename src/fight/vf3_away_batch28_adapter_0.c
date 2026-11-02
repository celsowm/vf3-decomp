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
int vf3_away_batch28_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042cd4u: goto P_0c042cd4;
case 0x0c042cd6u: goto P_0c042cd6;
case 0x0c042cd8u: goto P_0c042cd8;
case 0x0c042cdau: goto P_0c042cda;
case 0x0c042cdcu: goto P_0c042cdc;
case 0x0c042cdeu: goto P_0c042cde;
case 0x0c042ce0u: goto P_0c042ce0;
case 0x0c042ce2u: goto P_0c042ce2;
case 0x0c042ce4u: goto P_0c042ce4;
case 0x0c042ce6u: goto P_0c042ce6;
case 0x0c042ce8u: goto P_0c042ce8;
case 0x0c042ceau: goto P_0c042cea;
case 0x0c042cecu: goto P_0c042cec;
case 0x0c042ceeu: goto P_0c042cee;
case 0x0c042cf0u: goto P_0c042cf0;
case 0x0c042cf2u: goto P_0c042cf2;
case 0x0c042cf4u: goto P_0c042cf4;
case 0x0c042cf6u: goto P_0c042cf6;
case 0x0c042cf8u: goto P_0c042cf8;
case 0x0c042cfau: goto P_0c042cfa;
case 0x0c042cfcu: goto P_0c042cfc;
case 0x0c042cfeu: goto P_0c042cfe;
case 0x0c042d00u: goto P_0c042d00;
case 0x0c042d02u: goto P_0c042d02;
case 0x0c042d04u: goto P_0c042d04;
case 0x0c042d06u: goto P_0c042d06;
case 0x0c042d08u: goto P_0c042d08;
case 0x0c042d0au: goto P_0c042d0a;
case 0x0c042d0cu: goto P_0c042d0c;
case 0x0c042d0eu: goto P_0c042d0e;
case 0x0c042d10u: goto P_0c042d10;
case 0x0c042d12u: goto P_0c042d12;
case 0x0c042d14u: goto P_0c042d14;
case 0x0c042d16u: goto P_0c042d16;
case 0x0c042d18u: goto P_0c042d18;
case 0x0c042d1au: goto P_0c042d1a;
case 0x0c042d1cu: goto P_0c042d1c;
case 0x0c042d1eu: goto P_0c042d1e;
case 0x0c042d20u: goto P_0c042d20;
case 0x0c042d22u: goto P_0c042d22;
case 0x0c042d24u: goto P_0c042d24;
case 0x0c042d26u: goto P_0c042d26;
case 0x0c042d28u: goto P_0c042d28;
case 0x0c042d2au: goto P_0c042d2a;
case 0x0c042d2cu: goto P_0c042d2c;
case 0x0c042d2eu: goto P_0c042d2e;
case 0x0c042d30u: goto P_0c042d30;
case 0x0c042d32u: goto P_0c042d32;
case 0x0c042d34u: goto P_0c042d34;
case 0x0c042d36u: goto P_0c042d36;
case 0x0c042d38u: goto P_0c042d38;
case 0x0c042d3au: goto P_0c042d3a;
case 0x0c042d3cu: goto P_0c042d3c;
case 0x0c042d3eu: goto P_0c042d3e;
case 0x0c042d40u: goto P_0c042d40;
case 0x0c042d42u: goto P_0c042d42;
case 0x0c042d44u: goto P_0c042d44;
case 0x0c042d46u: goto P_0c042d46;
case 0x0c042d48u: goto P_0c042d48;
case 0x0c042d4au: goto P_0c042d4a;
case 0x0c042d4cu: goto P_0c042d4c;
case 0x0c042d4eu: goto P_0c042d4e;
case 0x0c042d50u: goto P_0c042d50;
case 0x0c042d52u: goto P_0c042d52;
case 0x0c042d54u: goto P_0c042d54;
case 0x0c042d56u: goto P_0c042d56;
case 0x0c042d58u: goto P_0c042d58;
case 0x0c042d5au: goto P_0c042d5a;
case 0x0c042d5cu: goto P_0c042d5c;
case 0x0c042d5eu: goto P_0c042d5e;
case 0x0c042d60u: goto P_0c042d60;
case 0x0c042d62u: goto P_0c042d62;
case 0x0c042d64u: goto P_0c042d64;
case 0x0c042d66u: goto P_0c042d66;
case 0x0c042d68u: goto P_0c042d68;
case 0x0c042d6au: goto P_0c042d6a;
case 0x0c042d6cu: goto P_0c042d6c;
case 0x0c042d6eu: goto P_0c042d6e;
case 0x0c042d70u: goto P_0c042d70;
case 0x0c042d72u: goto P_0c042d72;
case 0x0c042e44u: goto P_0c042e44;
case 0x0c042e46u: goto P_0c042e46;
case 0x0c042e48u: goto P_0c042e48;
case 0x0c042e4au: goto P_0c042e4a;
case 0x0c042e4cu: goto P_0c042e4c;
case 0x0c042e4eu: goto P_0c042e4e;
case 0x0c042e50u: goto P_0c042e50;
case 0x0c042e52u: goto P_0c042e52;
case 0x0c042e54u: goto P_0c042e54;
case 0x0c042e56u: goto P_0c042e56;
case 0x0c042e58u: goto P_0c042e58;
case 0x0c042e5au: goto P_0c042e5a;
case 0x0c042e5cu: goto P_0c042e5c;
case 0x0c042e5eu: goto P_0c042e5e;
case 0x0c042e60u: goto P_0c042e60;
case 0x0c042e62u: goto P_0c042e62;
case 0x0c042e64u: goto P_0c042e64;
case 0x0c042e66u: goto P_0c042e66;
case 0x0c042e68u: goto P_0c042e68;
case 0x0c042e6au: goto P_0c042e6a;
case 0x0c042e6cu: goto P_0c042e6c;
case 0x0c042e6eu: goto P_0c042e6e;
case 0x0c042e70u: goto P_0c042e70;
case 0x0c042e72u: goto P_0c042e72;
case 0x0c042e74u: goto P_0c042e74;
case 0x0c042e76u: goto P_0c042e76;
case 0x0c042e78u: goto P_0c042e78;
case 0x0c042e7au: goto P_0c042e7a;
case 0x0c042e7cu: goto P_0c042e7c;
case 0x0c042e7eu: goto P_0c042e7e;
case 0x0c042e80u: goto P_0c042e80;
case 0x0c042e82u: goto P_0c042e82;
case 0x0c042e84u: goto P_0c042e84;
case 0x0c042e86u: goto P_0c042e86;
case 0x0c042e88u: goto P_0c042e88;
case 0x0c042e8au: goto P_0c042e8a;
case 0x0c042e8cu: goto P_0c042e8c;
case 0x0c042e8eu: goto P_0c042e8e;
case 0x0c042e90u: goto P_0c042e90;
case 0x0c042e92u: goto P_0c042e92;
case 0x0c042e94u: goto P_0c042e94;
case 0x0c042e96u: goto P_0c042e96;
case 0x0c042e98u: goto P_0c042e98;
case 0x0c042e9au: goto P_0c042e9a;
case 0x0c042e9cu: goto P_0c042e9c;
case 0x0c042e9eu: goto P_0c042e9e;
case 0x0c042ea0u: goto P_0c042ea0;
case 0x0c042ea2u: goto P_0c042ea2;
case 0x0c042ea4u: goto P_0c042ea4;
case 0x0c042ea6u: goto P_0c042ea6;
case 0x0c042ea8u: goto P_0c042ea8;
case 0x0c042eaau: goto P_0c042eaa;
case 0x0c042eacu: goto P_0c042eac;
case 0x0c042eaeu: goto P_0c042eae;
case 0x0c042eb0u: goto P_0c042eb0;
case 0x0c042eb2u: goto P_0c042eb2;
case 0x0c042eb4u: goto P_0c042eb4;
case 0x0c042eb6u: goto P_0c042eb6;
case 0x0c042eb8u: goto P_0c042eb8;
case 0x0c042ebau: goto P_0c042eba;
case 0x0c042ebcu: goto P_0c042ebc;
case 0x0c042ebeu: goto P_0c042ebe;
case 0x0c042ec0u: goto P_0c042ec0;
case 0x0c042ec2u: goto P_0c042ec2;
case 0x0c042ec4u: goto P_0c042ec4;
case 0x0c042ec6u: goto P_0c042ec6;
case 0x0c042ec8u: goto P_0c042ec8;
case 0x0c042ecau: goto P_0c042eca;
case 0x0c042eccu: goto P_0c042ecc;
case 0x0c042eceu: goto P_0c042ece;
case 0x0c042ed0u: goto P_0c042ed0;
case 0x0c042ed2u: goto P_0c042ed2;
case 0x0c042ed4u: goto P_0c042ed4;
case 0x0c042ed6u: goto P_0c042ed6;
case 0x0c042ed8u: goto P_0c042ed8;
case 0x0c042edau: goto P_0c042eda;
case 0x0c042edcu: goto P_0c042edc;
case 0x0c042edeu: goto P_0c042ede;
case 0x0c042ee0u: goto P_0c042ee0;
case 0x0c042ee2u: goto P_0c042ee2;
case 0x0c042ee4u: goto P_0c042ee4;
case 0x0c042ee6u: goto P_0c042ee6;
case 0x0c042ee8u: goto P_0c042ee8;
case 0x0c042eeau: goto P_0c042eea;
case 0x0c042eecu: goto P_0c042eec;
case 0x0c042eeeu: goto P_0c042eee;
case 0x0c042ef0u: goto P_0c042ef0;
case 0x0c042ef2u: goto P_0c042ef2;
case 0x0c042efcu: goto P_0c042efc;
case 0x0c042efeu: goto P_0c042efe;
case 0x0c042f00u: goto P_0c042f00;
case 0x0c042f02u: goto P_0c042f02;
case 0x0c042f04u: goto P_0c042f04;
case 0x0c042f06u: goto P_0c042f06;
case 0x0c059896u: goto P_0c059896;
case 0x0c059898u: goto P_0c059898;
case 0x0c05989au: goto P_0c05989a;
case 0x0c05989cu: goto P_0c05989c;
case 0x0c05989eu: goto P_0c05989e;
case 0x0c0598a0u: goto P_0c0598a0;
case 0x0c0598a2u: goto P_0c0598a2;
case 0x0c0598a4u: goto P_0c0598a4;
case 0x0c0598a6u: goto P_0c0598a6;
case 0x0c0598a8u: goto P_0c0598a8;
case 0x0c0598aau: goto P_0c0598aa;
case 0x0c0598acu: goto P_0c0598ac;
case 0x0c0598aeu: goto P_0c0598ae;
case 0x0c0598b0u: goto P_0c0598b0;
case 0x0c0598b2u: goto P_0c0598b2;
case 0x0c0598b4u: goto P_0c0598b4;
case 0x0c0598b6u: goto P_0c0598b6;
case 0x0c0598b8u: goto P_0c0598b8;
case 0x0c0598bau: goto P_0c0598ba;
case 0x0c0598bcu: goto P_0c0598bc;
case 0x0c0598beu: goto P_0c0598be;
case 0x0c0598c0u: goto P_0c0598c0;
case 0x0c0598c2u: goto P_0c0598c2;
case 0x0c0598c4u: goto P_0c0598c4;
case 0x0c0598c6u: goto P_0c0598c6;
case 0x0c0598c8u: goto P_0c0598c8;
case 0x0c0598cau: goto P_0c0598ca;
case 0x0c0598ccu: goto P_0c0598cc;
case 0x0c0598ceu: goto P_0c0598ce;
case 0x0c0598d0u: goto P_0c0598d0;
case 0x0c0598d2u: goto P_0c0598d2;
case 0x0c0598d4u: goto P_0c0598d4;
case 0x0c0598d6u: goto P_0c0598d6;
case 0x0c0598d8u: goto P_0c0598d8;
case 0x0c0598dau: goto P_0c0598da;
case 0x0c0598dcu: goto P_0c0598dc;
case 0x0c0598deu: goto P_0c0598de;
case 0x0c0598e0u: goto P_0c0598e0;
case 0x0c0598e2u: goto P_0c0598e2;
case 0x0c0598e4u: goto P_0c0598e4;
case 0x0c0598e6u: goto P_0c0598e6;
case 0x0c0598e8u: goto P_0c0598e8;
case 0x0c0598eau: goto P_0c0598ea;
case 0x0c0598ecu: goto P_0c0598ec;
case 0x0c0598eeu: goto P_0c0598ee;
case 0x0c059920u: goto P_0c059920;
case 0x0c059922u: goto P_0c059922;
case 0x0c059924u: goto P_0c059924;
case 0x0c059926u: goto P_0c059926;
case 0x0c059928u: goto P_0c059928;
case 0x0c05992au: goto P_0c05992a;
case 0x0c05992cu: goto P_0c05992c;
case 0x0c05992eu: goto P_0c05992e;
case 0x0c059930u: goto P_0c059930;
case 0x0c059932u: goto P_0c059932;
case 0x0c059934u: goto P_0c059934;
case 0x0c059936u: goto P_0c059936;
case 0x0c059938u: goto P_0c059938;
case 0x0c05993au: goto P_0c05993a;
case 0x0c05993cu: goto P_0c05993c;
case 0x0c05993eu: goto P_0c05993e;
case 0x0c059940u: goto P_0c059940;
case 0x0c059942u: goto P_0c059942;
case 0x0c059944u: goto P_0c059944;
case 0x0c059946u: goto P_0c059946;
case 0x0c059948u: goto P_0c059948;
case 0x0c05994au: goto P_0c05994a;
case 0x0c05994cu: goto P_0c05994c;
case 0x0c05994eu: goto P_0c05994e;
case 0x0c059950u: goto P_0c059950;
case 0x0c059952u: goto P_0c059952;
case 0x0c059954u: goto P_0c059954;
case 0x0c059956u: goto P_0c059956;
case 0x0c059958u: goto P_0c059958;
case 0x0c05995au: goto P_0c05995a;
case 0x0c05995cu: goto P_0c05995c;
case 0x0c05995eu: goto P_0c05995e;
case 0x0c059960u: goto P_0c059960;
case 0x0c059962u: goto P_0c059962;
case 0x0c059964u: goto P_0c059964;
case 0x0c059966u: goto P_0c059966;
case 0x0c059968u: goto P_0c059968;
case 0x0c05996au: goto P_0c05996a;
case 0x0c05996cu: goto P_0c05996c;
case 0x0c05996eu: goto P_0c05996e;
case 0x0c059970u: goto P_0c059970;
case 0x0c059972u: goto P_0c059972;
case 0x0c059974u: goto P_0c059974;
case 0x0c059976u: goto P_0c059976;
case 0x0c059978u: goto P_0c059978;
case 0x0c05997au: goto P_0c05997a;
case 0x0c05997cu: goto P_0c05997c;
case 0x0c05997eu: goto P_0c05997e;
case 0x0c059980u: goto P_0c059980;
case 0x0c059982u: goto P_0c059982;
case 0x0c059984u: goto P_0c059984;
case 0x0c059986u: goto P_0c059986;
case 0x0c059988u: goto P_0c059988;
case 0x0c05998au: goto P_0c05998a;
case 0x0c05998cu: goto P_0c05998c;
case 0x0c05998eu: goto P_0c05998e;
case 0x0c059990u: goto P_0c059990;
case 0x0c059992u: goto P_0c059992;
case 0x0c059994u: goto P_0c059994;
case 0x0c059996u: goto P_0c059996;
case 0x0c059998u: goto P_0c059998;
case 0x0c05999au: goto P_0c05999a;
case 0x0c05999cu: goto P_0c05999c;
case 0x0c05999eu: goto P_0c05999e;
case 0x0c0599a0u: goto P_0c0599a0;
case 0x0c0599a2u: goto P_0c0599a2;
case 0x0c0599a4u: goto P_0c0599a4;
case 0x0c0599a6u: goto P_0c0599a6;
case 0x0c0599a8u: goto P_0c0599a8;
case 0x0c0599aau: goto P_0c0599aa;
case 0x0c0599acu: goto P_0c0599ac;
case 0x0c0599aeu: goto P_0c0599ae;
case 0x0c0599b0u: goto P_0c0599b0;
case 0x0c0599b2u: goto P_0c0599b2;
case 0x0c0599b4u: goto P_0c0599b4;
case 0x0c0599b6u: goto P_0c0599b6;
case 0x0c0599b8u: goto P_0c0599b8;
case 0x0c0599bau: goto P_0c0599ba;
case 0x0c0599bcu: goto P_0c0599bc;
case 0x0c0599beu: goto P_0c0599be;
case 0x0c0599c0u: goto P_0c0599c0;
case 0x0c0599c2u: goto P_0c0599c2;
case 0x0c0599c4u: goto P_0c0599c4;
case 0x0c0599c6u: goto P_0c0599c6;
case 0x0c0599c8u: goto P_0c0599c8;
case 0x0c0599cau: goto P_0c0599ca;
case 0x0c0599ccu: goto P_0c0599cc;
case 0x0c0599ceu: goto P_0c0599ce;
case 0x0c0599d0u: goto P_0c0599d0;
case 0x0c0599d2u: goto P_0c0599d2;
case 0x0c0599d4u: goto P_0c0599d4;
case 0x0c0599d6u: goto P_0c0599d6;
case 0x0c0599d8u: goto P_0c0599d8;
case 0x0c0599dau: goto P_0c0599da;
case 0x0c0599dcu: goto P_0c0599dc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c042cd4: /* original 2008, guest PC 0x0c042cd4 */
if(!s->budget--) { s->failed_pc=0x0c042cd4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042cd6;
P_0c042cd6: /* original 2f26, guest PC 0x0c042cd6 */
if(!s->budget--) { s->failed_pc=0x0c042cd6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042cd8;
P_0c042cd8: /* original 8d46, guest PC 0x0c042cd8 */
if(!s->budget--) { s->failed_pc=0x0c042cd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042d68; }
goto P_0c042cdc;
P_0c042cda: /* original 0009, guest PC 0x0c042cda */
if(!s->budget--) { s->failed_pc=0x0c042cdau; return 0; }
goto P_0c042cdc;
P_0c042cdc: /* original e200, guest PC 0x0c042cdc */
if(!s->budget--) { s->failed_pc=0x0c042cdcu; return 0; }
r[2]=0x00000000u;
goto P_0c042cde;
P_0c042cde: /* original 0019, guest PC 0x0c042cde */
if(!s->budget--) { s->failed_pc=0x0c042cdeu; return 0; }
r[17]&=~0x301u;
goto P_0c042ce0;
P_0c042ce0: /* original 4124, guest PC 0x0c042ce0 */
if(!s->budget--) { s->failed_pc=0x0c042ce0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ce2;
P_0c042ce2: /* original 3204, guest PC 0x0c042ce2 */
if(!s->budget--) { s->failed_pc=0x0c042ce2u; return 0; }
divide_step(s,2,0);
goto P_0c042ce4;
P_0c042ce4: /* original 4124, guest PC 0x0c042ce4 */
if(!s->budget--) { s->failed_pc=0x0c042ce4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ce6;
P_0c042ce6: /* original 3204, guest PC 0x0c042ce6 */
if(!s->budget--) { s->failed_pc=0x0c042ce6u; return 0; }
divide_step(s,2,0);
goto P_0c042ce8;
P_0c042ce8: /* original 4124, guest PC 0x0c042ce8 */
if(!s->budget--) { s->failed_pc=0x0c042ce8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cea;
P_0c042cea: /* original 3204, guest PC 0x0c042cea */
if(!s->budget--) { s->failed_pc=0x0c042ceau; return 0; }
divide_step(s,2,0);
goto P_0c042cec;
P_0c042cec: /* original 4124, guest PC 0x0c042cec */
if(!s->budget--) { s->failed_pc=0x0c042cecu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cee;
P_0c042cee: /* original 3204, guest PC 0x0c042cee */
if(!s->budget--) { s->failed_pc=0x0c042ceeu; return 0; }
divide_step(s,2,0);
goto P_0c042cf0;
P_0c042cf0: /* original 4124, guest PC 0x0c042cf0 */
if(!s->budget--) { s->failed_pc=0x0c042cf0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cf2;
P_0c042cf2: /* original 3204, guest PC 0x0c042cf2 */
if(!s->budget--) { s->failed_pc=0x0c042cf2u; return 0; }
divide_step(s,2,0);
goto P_0c042cf4;
P_0c042cf4: /* original 4124, guest PC 0x0c042cf4 */
if(!s->budget--) { s->failed_pc=0x0c042cf4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cf6;
P_0c042cf6: /* original 3204, guest PC 0x0c042cf6 */
if(!s->budget--) { s->failed_pc=0x0c042cf6u; return 0; }
divide_step(s,2,0);
goto P_0c042cf8;
P_0c042cf8: /* original 4124, guest PC 0x0c042cf8 */
if(!s->budget--) { s->failed_pc=0x0c042cf8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cfa;
P_0c042cfa: /* original 3204, guest PC 0x0c042cfa */
if(!s->budget--) { s->failed_pc=0x0c042cfau; return 0; }
divide_step(s,2,0);
goto P_0c042cfc;
P_0c042cfc: /* original 4124, guest PC 0x0c042cfc */
if(!s->budget--) { s->failed_pc=0x0c042cfcu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cfe;
P_0c042cfe: /* original 3204, guest PC 0x0c042cfe */
if(!s->budget--) { s->failed_pc=0x0c042cfeu; return 0; }
divide_step(s,2,0);
goto P_0c042d00;
P_0c042d00: /* original 4124, guest PC 0x0c042d00 */
if(!s->budget--) { s->failed_pc=0x0c042d00u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d02;
P_0c042d02: /* original 3204, guest PC 0x0c042d02 */
if(!s->budget--) { s->failed_pc=0x0c042d02u; return 0; }
divide_step(s,2,0);
goto P_0c042d04;
P_0c042d04: /* original 4124, guest PC 0x0c042d04 */
if(!s->budget--) { s->failed_pc=0x0c042d04u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d06;
P_0c042d06: /* original 3204, guest PC 0x0c042d06 */
if(!s->budget--) { s->failed_pc=0x0c042d06u; return 0; }
divide_step(s,2,0);
goto P_0c042d08;
P_0c042d08: /* original 4124, guest PC 0x0c042d08 */
if(!s->budget--) { s->failed_pc=0x0c042d08u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d0a;
P_0c042d0a: /* original 3204, guest PC 0x0c042d0a */
if(!s->budget--) { s->failed_pc=0x0c042d0au; return 0; }
divide_step(s,2,0);
goto P_0c042d0c;
P_0c042d0c: /* original 4124, guest PC 0x0c042d0c */
if(!s->budget--) { s->failed_pc=0x0c042d0cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d0e;
P_0c042d0e: /* original 3204, guest PC 0x0c042d0e */
if(!s->budget--) { s->failed_pc=0x0c042d0eu; return 0; }
divide_step(s,2,0);
goto P_0c042d10;
P_0c042d10: /* original 4124, guest PC 0x0c042d10 */
if(!s->budget--) { s->failed_pc=0x0c042d10u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d12;
P_0c042d12: /* original 3204, guest PC 0x0c042d12 */
if(!s->budget--) { s->failed_pc=0x0c042d12u; return 0; }
divide_step(s,2,0);
goto P_0c042d14;
P_0c042d14: /* original 4124, guest PC 0x0c042d14 */
if(!s->budget--) { s->failed_pc=0x0c042d14u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d16;
P_0c042d16: /* original 3204, guest PC 0x0c042d16 */
if(!s->budget--) { s->failed_pc=0x0c042d16u; return 0; }
divide_step(s,2,0);
goto P_0c042d18;
P_0c042d18: /* original 4124, guest PC 0x0c042d18 */
if(!s->budget--) { s->failed_pc=0x0c042d18u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d1a;
P_0c042d1a: /* original 3204, guest PC 0x0c042d1a */
if(!s->budget--) { s->failed_pc=0x0c042d1au; return 0; }
divide_step(s,2,0);
goto P_0c042d1c;
P_0c042d1c: /* original 4124, guest PC 0x0c042d1c */
if(!s->budget--) { s->failed_pc=0x0c042d1cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d1e;
P_0c042d1e: /* original 3204, guest PC 0x0c042d1e */
if(!s->budget--) { s->failed_pc=0x0c042d1eu; return 0; }
divide_step(s,2,0);
goto P_0c042d20;
P_0c042d20: /* original 4124, guest PC 0x0c042d20 */
if(!s->budget--) { s->failed_pc=0x0c042d20u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d22;
P_0c042d22: /* original 3204, guest PC 0x0c042d22 */
if(!s->budget--) { s->failed_pc=0x0c042d22u; return 0; }
divide_step(s,2,0);
goto P_0c042d24;
P_0c042d24: /* original 4124, guest PC 0x0c042d24 */
if(!s->budget--) { s->failed_pc=0x0c042d24u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d26;
P_0c042d26: /* original 3204, guest PC 0x0c042d26 */
if(!s->budget--) { s->failed_pc=0x0c042d26u; return 0; }
divide_step(s,2,0);
goto P_0c042d28;
P_0c042d28: /* original 4124, guest PC 0x0c042d28 */
if(!s->budget--) { s->failed_pc=0x0c042d28u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d2a;
P_0c042d2a: /* original 3204, guest PC 0x0c042d2a */
if(!s->budget--) { s->failed_pc=0x0c042d2au; return 0; }
divide_step(s,2,0);
goto P_0c042d2c;
P_0c042d2c: /* original 4124, guest PC 0x0c042d2c */
if(!s->budget--) { s->failed_pc=0x0c042d2cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d2e;
P_0c042d2e: /* original 3204, guest PC 0x0c042d2e */
if(!s->budget--) { s->failed_pc=0x0c042d2eu; return 0; }
divide_step(s,2,0);
goto P_0c042d30;
P_0c042d30: /* original 4124, guest PC 0x0c042d30 */
if(!s->budget--) { s->failed_pc=0x0c042d30u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d32;
P_0c042d32: /* original 3204, guest PC 0x0c042d32 */
if(!s->budget--) { s->failed_pc=0x0c042d32u; return 0; }
divide_step(s,2,0);
goto P_0c042d34;
P_0c042d34: /* original 4124, guest PC 0x0c042d34 */
if(!s->budget--) { s->failed_pc=0x0c042d34u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d36;
P_0c042d36: /* original 3204, guest PC 0x0c042d36 */
if(!s->budget--) { s->failed_pc=0x0c042d36u; return 0; }
divide_step(s,2,0);
goto P_0c042d38;
P_0c042d38: /* original 4124, guest PC 0x0c042d38 */
if(!s->budget--) { s->failed_pc=0x0c042d38u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d3a;
P_0c042d3a: /* original 3204, guest PC 0x0c042d3a */
if(!s->budget--) { s->failed_pc=0x0c042d3au; return 0; }
divide_step(s,2,0);
goto P_0c042d3c;
P_0c042d3c: /* original 4124, guest PC 0x0c042d3c */
if(!s->budget--) { s->failed_pc=0x0c042d3cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d3e;
P_0c042d3e: /* original 3204, guest PC 0x0c042d3e */
if(!s->budget--) { s->failed_pc=0x0c042d3eu; return 0; }
divide_step(s,2,0);
goto P_0c042d40;
P_0c042d40: /* original 4124, guest PC 0x0c042d40 */
if(!s->budget--) { s->failed_pc=0x0c042d40u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d42;
P_0c042d42: /* original 3204, guest PC 0x0c042d42 */
if(!s->budget--) { s->failed_pc=0x0c042d42u; return 0; }
divide_step(s,2,0);
goto P_0c042d44;
P_0c042d44: /* original 4124, guest PC 0x0c042d44 */
if(!s->budget--) { s->failed_pc=0x0c042d44u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d46;
P_0c042d46: /* original 3204, guest PC 0x0c042d46 */
if(!s->budget--) { s->failed_pc=0x0c042d46u; return 0; }
divide_step(s,2,0);
goto P_0c042d48;
P_0c042d48: /* original 4124, guest PC 0x0c042d48 */
if(!s->budget--) { s->failed_pc=0x0c042d48u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d4a;
P_0c042d4a: /* original 3204, guest PC 0x0c042d4a */
if(!s->budget--) { s->failed_pc=0x0c042d4au; return 0; }
divide_step(s,2,0);
goto P_0c042d4c;
P_0c042d4c: /* original 4124, guest PC 0x0c042d4c */
if(!s->budget--) { s->failed_pc=0x0c042d4cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d4e;
P_0c042d4e: /* original 3204, guest PC 0x0c042d4e */
if(!s->budget--) { s->failed_pc=0x0c042d4eu; return 0; }
divide_step(s,2,0);
goto P_0c042d50;
P_0c042d50: /* original 4124, guest PC 0x0c042d50 */
if(!s->budget--) { s->failed_pc=0x0c042d50u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d52;
P_0c042d52: /* original 3204, guest PC 0x0c042d52 */
if(!s->budget--) { s->failed_pc=0x0c042d52u; return 0; }
divide_step(s,2,0);
goto P_0c042d54;
P_0c042d54: /* original 4124, guest PC 0x0c042d54 */
if(!s->budget--) { s->failed_pc=0x0c042d54u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d56;
P_0c042d56: /* original 3204, guest PC 0x0c042d56 */
if(!s->budget--) { s->failed_pc=0x0c042d56u; return 0; }
divide_step(s,2,0);
goto P_0c042d58;
P_0c042d58: /* original 4124, guest PC 0x0c042d58 */
if(!s->budget--) { s->failed_pc=0x0c042d58u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d5a;
P_0c042d5a: /* original 3204, guest PC 0x0c042d5a */
if(!s->budget--) { s->failed_pc=0x0c042d5au; return 0; }
divide_step(s,2,0);
goto P_0c042d5c;
P_0c042d5c: /* original 4124, guest PC 0x0c042d5c */
if(!s->budget--) { s->failed_pc=0x0c042d5cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d5e;
P_0c042d5e: /* original 3204, guest PC 0x0c042d5e */
if(!s->budget--) { s->failed_pc=0x0c042d5eu; return 0; }
divide_step(s,2,0);
goto P_0c042d60;
P_0c042d60: /* original 4124, guest PC 0x0c042d60 */
if(!s->budget--) { s->failed_pc=0x0c042d60u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042d62;
P_0c042d62: /* original 6013, guest PC 0x0c042d62 */
if(!s->budget--) { s->failed_pc=0x0c042d62u; return 0; }
r[0]=r[1];
goto P_0c042d64;
P_0c042d64: /* original 000b, guest PC 0x0c042d64 */
if(!s->budget--) { s->failed_pc=0x0c042d64u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042d66: /* original 62f6, guest PC 0x0c042d66 */
if(!s->budget--) { s->failed_pc=0x0c042d66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c042d68;
P_0c042d68: /* original d202, guest PC 0x0c042d68 */
if(!s->budget--) { s->failed_pc=0x0c042d68u; return 0; }
r[2]=read(ram,0x0c042d74u,4);
goto P_0c042d6a;
P_0c042d6a: /* original d103, guest PC 0x0c042d6a */
if(!s->budget--) { s->failed_pc=0x0c042d6au; return 0; }
r[1]=read(ram,0x0c042d78u,4);
goto P_0c042d6c;
P_0c042d6c: /* original e000, guest PC 0x0c042d6c */
if(!s->budget--) { s->failed_pc=0x0c042d6cu; return 0; }
r[0]=0x00000000u;
goto P_0c042d6e;
P_0c042d6e: /* original 2212, guest PC 0x0c042d6e */
if(!s->budget--) { s->failed_pc=0x0c042d6eu; return 0; }
write(ram,r[2],r[1],4);
goto P_0c042d70;
P_0c042d70: /* original 000b, guest PC 0x0c042d70 */
if(!s->budget--) { s->failed_pc=0x0c042d70u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042d72: /* original 62f6, guest PC 0x0c042d72 */
if(!s->budget--) { s->failed_pc=0x0c042d72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042d74u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042d74u; return 0; } return 1;
P_0c042e44: /* original 2008, guest PC 0x0c042e44 */
if(!s->budget--) { s->failed_pc=0x0c042e44u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042e46;
P_0c042e46: /* original 8d4e, guest PC 0x0c042e46 */
if(!s->budget--) { s->failed_pc=0x0c042e46u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042ee6; }
goto P_0c042e4a;
P_0c042e48: /* original 0009, guest PC 0x0c042e48 */
if(!s->budget--) { s->failed_pc=0x0c042e48u; return 0; }
goto P_0c042e4a;
P_0c042e4a: /* original 2f36, guest PC 0x0c042e4a */
if(!s->budget--) { s->failed_pc=0x0c042e4au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042e4c;
P_0c042e4c: /* original e300, guest PC 0x0c042e4c */
if(!s->budget--) { s->failed_pc=0x0c042e4cu; return 0; }
r[3]=0x00000000u;
goto P_0c042e4e;
P_0c042e4e: /* original 2f46, guest PC 0x0c042e4e */
if(!s->budget--) { s->failed_pc=0x0c042e4eu; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042e50;
P_0c042e50: /* original 6403, guest PC 0x0c042e50 */
if(!s->budget--) { s->failed_pc=0x0c042e50u; return 0; }
r[4]=r[0];
goto P_0c042e52;
P_0c042e52: /* original 0019, guest PC 0x0c042e52 */
if(!s->budget--) { s->failed_pc=0x0c042e52u; return 0; }
r[17]&=~0x301u;
goto P_0c042e54;
P_0c042e54: /* original 4124, guest PC 0x0c042e54 */
if(!s->budget--) { s->failed_pc=0x0c042e54u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e56;
P_0c042e56: /* original 3344, guest PC 0x0c042e56 */
if(!s->budget--) { s->failed_pc=0x0c042e56u; return 0; }
divide_step(s,3,4);
goto P_0c042e58;
P_0c042e58: /* original 4124, guest PC 0x0c042e58 */
if(!s->budget--) { s->failed_pc=0x0c042e58u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e5a;
P_0c042e5a: /* original 3344, guest PC 0x0c042e5a */
if(!s->budget--) { s->failed_pc=0x0c042e5au; return 0; }
divide_step(s,3,4);
goto P_0c042e5c;
P_0c042e5c: /* original 4124, guest PC 0x0c042e5c */
if(!s->budget--) { s->failed_pc=0x0c042e5cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e5e;
P_0c042e5e: /* original 3344, guest PC 0x0c042e5e */
if(!s->budget--) { s->failed_pc=0x0c042e5eu; return 0; }
divide_step(s,3,4);
goto P_0c042e60;
P_0c042e60: /* original 4124, guest PC 0x0c042e60 */
if(!s->budget--) { s->failed_pc=0x0c042e60u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e62;
P_0c042e62: /* original 3344, guest PC 0x0c042e62 */
if(!s->budget--) { s->failed_pc=0x0c042e62u; return 0; }
divide_step(s,3,4);
goto P_0c042e64;
P_0c042e64: /* original 4124, guest PC 0x0c042e64 */
if(!s->budget--) { s->failed_pc=0x0c042e64u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e66;
P_0c042e66: /* original 3344, guest PC 0x0c042e66 */
if(!s->budget--) { s->failed_pc=0x0c042e66u; return 0; }
divide_step(s,3,4);
goto P_0c042e68;
P_0c042e68: /* original 4124, guest PC 0x0c042e68 */
if(!s->budget--) { s->failed_pc=0x0c042e68u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e6a;
P_0c042e6a: /* original 3344, guest PC 0x0c042e6a */
if(!s->budget--) { s->failed_pc=0x0c042e6au; return 0; }
divide_step(s,3,4);
goto P_0c042e6c;
P_0c042e6c: /* original 4124, guest PC 0x0c042e6c */
if(!s->budget--) { s->failed_pc=0x0c042e6cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e6e;
P_0c042e6e: /* original 3344, guest PC 0x0c042e6e */
if(!s->budget--) { s->failed_pc=0x0c042e6eu; return 0; }
divide_step(s,3,4);
goto P_0c042e70;
P_0c042e70: /* original 4124, guest PC 0x0c042e70 */
if(!s->budget--) { s->failed_pc=0x0c042e70u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e72;
P_0c042e72: /* original 3344, guest PC 0x0c042e72 */
if(!s->budget--) { s->failed_pc=0x0c042e72u; return 0; }
divide_step(s,3,4);
goto P_0c042e74;
P_0c042e74: /* original 4124, guest PC 0x0c042e74 */
if(!s->budget--) { s->failed_pc=0x0c042e74u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e76;
P_0c042e76: /* original 3344, guest PC 0x0c042e76 */
if(!s->budget--) { s->failed_pc=0x0c042e76u; return 0; }
divide_step(s,3,4);
goto P_0c042e78;
P_0c042e78: /* original 4124, guest PC 0x0c042e78 */
if(!s->budget--) { s->failed_pc=0x0c042e78u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e7a;
P_0c042e7a: /* original 3344, guest PC 0x0c042e7a */
if(!s->budget--) { s->failed_pc=0x0c042e7au; return 0; }
divide_step(s,3,4);
goto P_0c042e7c;
P_0c042e7c: /* original 4124, guest PC 0x0c042e7c */
if(!s->budget--) { s->failed_pc=0x0c042e7cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e7e;
P_0c042e7e: /* original 3344, guest PC 0x0c042e7e */
if(!s->budget--) { s->failed_pc=0x0c042e7eu; return 0; }
divide_step(s,3,4);
goto P_0c042e80;
P_0c042e80: /* original 4124, guest PC 0x0c042e80 */
if(!s->budget--) { s->failed_pc=0x0c042e80u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e82;
P_0c042e82: /* original 3344, guest PC 0x0c042e82 */
if(!s->budget--) { s->failed_pc=0x0c042e82u; return 0; }
divide_step(s,3,4);
goto P_0c042e84;
P_0c042e84: /* original 4124, guest PC 0x0c042e84 */
if(!s->budget--) { s->failed_pc=0x0c042e84u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e86;
P_0c042e86: /* original 3344, guest PC 0x0c042e86 */
if(!s->budget--) { s->failed_pc=0x0c042e86u; return 0; }
divide_step(s,3,4);
goto P_0c042e88;
P_0c042e88: /* original 4124, guest PC 0x0c042e88 */
if(!s->budget--) { s->failed_pc=0x0c042e88u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e8a;
P_0c042e8a: /* original 3344, guest PC 0x0c042e8a */
if(!s->budget--) { s->failed_pc=0x0c042e8au; return 0; }
divide_step(s,3,4);
goto P_0c042e8c;
P_0c042e8c: /* original 4124, guest PC 0x0c042e8c */
if(!s->budget--) { s->failed_pc=0x0c042e8cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e8e;
P_0c042e8e: /* original 3344, guest PC 0x0c042e8e */
if(!s->budget--) { s->failed_pc=0x0c042e8eu; return 0; }
divide_step(s,3,4);
goto P_0c042e90;
P_0c042e90: /* original 4124, guest PC 0x0c042e90 */
if(!s->budget--) { s->failed_pc=0x0c042e90u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e92;
P_0c042e92: /* original 3344, guest PC 0x0c042e92 */
if(!s->budget--) { s->failed_pc=0x0c042e92u; return 0; }
divide_step(s,3,4);
goto P_0c042e94;
P_0c042e94: /* original 4124, guest PC 0x0c042e94 */
if(!s->budget--) { s->failed_pc=0x0c042e94u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e96;
P_0c042e96: /* original 3344, guest PC 0x0c042e96 */
if(!s->budget--) { s->failed_pc=0x0c042e96u; return 0; }
divide_step(s,3,4);
goto P_0c042e98;
P_0c042e98: /* original 4124, guest PC 0x0c042e98 */
if(!s->budget--) { s->failed_pc=0x0c042e98u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e9a;
P_0c042e9a: /* original 3344, guest PC 0x0c042e9a */
if(!s->budget--) { s->failed_pc=0x0c042e9au; return 0; }
divide_step(s,3,4);
goto P_0c042e9c;
P_0c042e9c: /* original 4124, guest PC 0x0c042e9c */
if(!s->budget--) { s->failed_pc=0x0c042e9cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042e9e;
P_0c042e9e: /* original 3344, guest PC 0x0c042e9e */
if(!s->budget--) { s->failed_pc=0x0c042e9eu; return 0; }
divide_step(s,3,4);
goto P_0c042ea0;
P_0c042ea0: /* original 4124, guest PC 0x0c042ea0 */
if(!s->budget--) { s->failed_pc=0x0c042ea0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ea2;
P_0c042ea2: /* original 3344, guest PC 0x0c042ea2 */
if(!s->budget--) { s->failed_pc=0x0c042ea2u; return 0; }
divide_step(s,3,4);
goto P_0c042ea4;
P_0c042ea4: /* original 4124, guest PC 0x0c042ea4 */
if(!s->budget--) { s->failed_pc=0x0c042ea4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ea6;
P_0c042ea6: /* original 3344, guest PC 0x0c042ea6 */
if(!s->budget--) { s->failed_pc=0x0c042ea6u; return 0; }
divide_step(s,3,4);
goto P_0c042ea8;
P_0c042ea8: /* original 4124, guest PC 0x0c042ea8 */
if(!s->budget--) { s->failed_pc=0x0c042ea8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042eaa;
P_0c042eaa: /* original 3344, guest PC 0x0c042eaa */
if(!s->budget--) { s->failed_pc=0x0c042eaau; return 0; }
divide_step(s,3,4);
goto P_0c042eac;
P_0c042eac: /* original 4124, guest PC 0x0c042eac */
if(!s->budget--) { s->failed_pc=0x0c042eacu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042eae;
P_0c042eae: /* original 3344, guest PC 0x0c042eae */
if(!s->budget--) { s->failed_pc=0x0c042eaeu; return 0; }
divide_step(s,3,4);
goto P_0c042eb0;
P_0c042eb0: /* original 4124, guest PC 0x0c042eb0 */
if(!s->budget--) { s->failed_pc=0x0c042eb0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042eb2;
P_0c042eb2: /* original 3344, guest PC 0x0c042eb2 */
if(!s->budget--) { s->failed_pc=0x0c042eb2u; return 0; }
divide_step(s,3,4);
goto P_0c042eb4;
P_0c042eb4: /* original 4124, guest PC 0x0c042eb4 */
if(!s->budget--) { s->failed_pc=0x0c042eb4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042eb6;
P_0c042eb6: /* original 3344, guest PC 0x0c042eb6 */
if(!s->budget--) { s->failed_pc=0x0c042eb6u; return 0; }
divide_step(s,3,4);
goto P_0c042eb8;
P_0c042eb8: /* original 4124, guest PC 0x0c042eb8 */
if(!s->budget--) { s->failed_pc=0x0c042eb8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042eba;
P_0c042eba: /* original 3344, guest PC 0x0c042eba */
if(!s->budget--) { s->failed_pc=0x0c042ebau; return 0; }
divide_step(s,3,4);
goto P_0c042ebc;
P_0c042ebc: /* original 4124, guest PC 0x0c042ebc */
if(!s->budget--) { s->failed_pc=0x0c042ebcu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ebe;
P_0c042ebe: /* original 3344, guest PC 0x0c042ebe */
if(!s->budget--) { s->failed_pc=0x0c042ebeu; return 0; }
divide_step(s,3,4);
goto P_0c042ec0;
P_0c042ec0: /* original 4124, guest PC 0x0c042ec0 */
if(!s->budget--) { s->failed_pc=0x0c042ec0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ec2;
P_0c042ec2: /* original 3344, guest PC 0x0c042ec2 */
if(!s->budget--) { s->failed_pc=0x0c042ec2u; return 0; }
divide_step(s,3,4);
goto P_0c042ec4;
P_0c042ec4: /* original 4124, guest PC 0x0c042ec4 */
if(!s->budget--) { s->failed_pc=0x0c042ec4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ec6;
P_0c042ec6: /* original 3344, guest PC 0x0c042ec6 */
if(!s->budget--) { s->failed_pc=0x0c042ec6u; return 0; }
divide_step(s,3,4);
goto P_0c042ec8;
P_0c042ec8: /* original 4124, guest PC 0x0c042ec8 */
if(!s->budget--) { s->failed_pc=0x0c042ec8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042eca;
P_0c042eca: /* original 3344, guest PC 0x0c042eca */
if(!s->budget--) { s->failed_pc=0x0c042ecau; return 0; }
divide_step(s,3,4);
goto P_0c042ecc;
P_0c042ecc: /* original 4124, guest PC 0x0c042ecc */
if(!s->budget--) { s->failed_pc=0x0c042eccu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ece;
P_0c042ece: /* original 3344, guest PC 0x0c042ece */
if(!s->budget--) { s->failed_pc=0x0c042eceu; return 0; }
divide_step(s,3,4);
goto P_0c042ed0;
P_0c042ed0: /* original 4124, guest PC 0x0c042ed0 */
if(!s->budget--) { s->failed_pc=0x0c042ed0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ed2;
P_0c042ed2: /* original 3344, guest PC 0x0c042ed2 */
if(!s->budget--) { s->failed_pc=0x0c042ed2u; return 0; }
divide_step(s,3,4);
goto P_0c042ed4;
P_0c042ed4: /* original 8b03, guest PC 0x0c042ed4 */
if(!s->budget--) { s->failed_pc=0x0c042ed4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042ede; }
goto P_0c042ed6;
P_0c042ed6: /* original 6033, guest PC 0x0c042ed6 */
if(!s->budget--) { s->failed_pc=0x0c042ed6u; return 0; }
r[0]=r[3];
goto P_0c042ed8;
P_0c042ed8: /* original 64f6, guest PC 0x0c042ed8 */
if(!s->budget--) { s->failed_pc=0x0c042ed8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c042eda;
P_0c042eda: /* original 000b, guest PC 0x0c042eda */
if(!s->budget--) { s->failed_pc=0x0c042edau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
s->pc=target; return ram->oob==0;
P_0c042edc: /* original 63f6, guest PC 0x0c042edc */
if(!s->budget--) { s->failed_pc=0x0c042edcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042ede;
P_0c042ede: /* original 303c, guest PC 0x0c042ede */
if(!s->budget--) { s->failed_pc=0x0c042edeu; return 0; }
r[0]+=r[3];
goto P_0c042ee0;
P_0c042ee0: /* original 64f6, guest PC 0x0c042ee0 */
if(!s->budget--) { s->failed_pc=0x0c042ee0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c042ee2;
P_0c042ee2: /* original 000b, guest PC 0x0c042ee2 */
if(!s->budget--) { s->failed_pc=0x0c042ee2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
s->pc=target; return ram->oob==0;
P_0c042ee4: /* original 63f6, guest PC 0x0c042ee4 */
if(!s->budget--) { s->failed_pc=0x0c042ee4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042ee6;
P_0c042ee6: /* original 2f26, guest PC 0x0c042ee6 */
if(!s->budget--) { s->failed_pc=0x0c042ee6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042ee8;
P_0c042ee8: /* original d102, guest PC 0x0c042ee8 */
if(!s->budget--) { s->failed_pc=0x0c042ee8u; return 0; }
r[1]=read(ram,0x0c042ef4u,4);
goto P_0c042eea;
P_0c042eea: /* original d203, guest PC 0x0c042eea */
if(!s->budget--) { s->failed_pc=0x0c042eeau; return 0; }
r[2]=read(ram,0x0c042ef8u,4);
goto P_0c042eec;
P_0c042eec: /* original e000, guest PC 0x0c042eec */
if(!s->budget--) { s->failed_pc=0x0c042eecu; return 0; }
r[0]=0x00000000u;
goto P_0c042eee;
P_0c042eee: /* original 2122, guest PC 0x0c042eee */
if(!s->budget--) { s->failed_pc=0x0c042eeeu; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042ef0;
P_0c042ef0: /* original 000b, guest PC 0x0c042ef0 */
if(!s->budget--) { s->failed_pc=0x0c042ef0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042ef2: /* original 62f6, guest PC 0x0c042ef2 */
if(!s->budget--) { s->failed_pc=0x0c042ef2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042ef4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042ef4u; return 0; } return 1;
P_0c042efc: /* original 2f36, guest PC 0x0c042efc */
if(!s->budget--) { s->failed_pc=0x0c042efcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042efe;
P_0c042efe: /* original d305, guest PC 0x0c042efe */
if(!s->budget--) { s->failed_pc=0x0c042efeu; return 0; }
r[3]=read(ram,0x0c042f14u,4);
goto P_0c042f00;
P_0c042f00: /* original 033e, guest PC 0x0c042f00 */
if(!s->budget--) { s->failed_pc=0x0c042f00u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c042f02;
P_0c042f02: /* original 70fc, guest PC 0x0c042f02 */
if(!s->budget--) { s->failed_pc=0x0c042f02u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c042f04;
P_0c042f04: /* original 432b, guest PC 0x0c042f04 */
if(!s->budget--) { s->failed_pc=0x0c042f04u; return 0; }
target=r[3];
r[0]=read(ram,r[2]+r[0],4);
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
P_0c042f06: /* original 002e, guest PC 0x0c042f06 */
if(!s->budget--) { s->failed_pc=0x0c042f06u; return 0; }
r[0]=read(ram,r[2]+r[0],4);
if(!vf3_matrix_family(0x0c042f08u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042f08u; return 0; } return 1;
P_0c059896: /* original 2fe6, guest PC 0x0c059896 */
if(!s->budget--) { s->failed_pc=0x0c059896u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059898;
P_0c059898: /* original 2fd6, guest PC 0x0c059898 */
if(!s->budget--) { s->failed_pc=0x0c059898u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05989a;
P_0c05989a: /* original 6e43, guest PC 0x0c05989a */
if(!s->budget--) { s->failed_pc=0x0c05989au; return 0; }
r[14]=r[4];
goto P_0c05989c;
P_0c05989c: /* original 2fc6, guest PC 0x0c05989c */
if(!s->budget--) { s->failed_pc=0x0c05989cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05989e;
P_0c05989e: /* original 2ee8, guest PC 0x0c05989e */
if(!s->budget--) { s->failed_pc=0x0c05989eu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0598a0;
P_0c0598a0: /* original 2fb6, guest PC 0x0c0598a0 */
if(!s->budget--) { s->failed_pc=0x0c0598a0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0598a2;
P_0c0598a2: /* original 6c53, guest PC 0x0c0598a2 */
if(!s->budget--) { s->failed_pc=0x0c0598a2u; return 0; }
r[12]=r[5];
goto P_0c0598a4;
P_0c0598a4: /* original 2fa6, guest PC 0x0c0598a4 */
if(!s->budget--) { s->failed_pc=0x0c0598a4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0598a6;
P_0c0598a6: /* original 6b63, guest PC 0x0c0598a6 */
if(!s->budget--) { s->failed_pc=0x0c0598a6u; return 0; }
r[11]=r[6];
goto P_0c0598a8;
P_0c0598a8: /* original 4f22, guest PC 0x0c0598a8 */
if(!s->budget--) { s->failed_pc=0x0c0598a8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0598aa;
P_0c0598aa: /* original 7ffc, guest PC 0x0c0598aa */
if(!s->budget--) { s->failed_pc=0x0c0598aau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0598ac;
P_0c0598ac: /* original 2f72, guest PC 0x0c0598ac */
if(!s->budget--) { s->failed_pc=0x0c0598acu; return 0; }
write(ram,r[15],r[7],4);
goto P_0c0598ae;
P_0c0598ae: /* original 8d02, guest PC 0x0c0598ae */
if(!s->budget--) { s->failed_pc=0x0c0598aeu; return 0; }
cond=r[17]&1u;
r[10]=0x00000000u;
if(cond) { goto P_0c0598b6; }
goto P_0c0598b2;
P_0c0598b0: /* original ea00, guest PC 0x0c0598b0 */
if(!s->budget--) { s->failed_pc=0x0c0598b0u; return 0; }
r[10]=0x00000000u;
goto P_0c0598b2;
P_0c0598b2: /* original 2cc8, guest PC 0x0c0598b2 */
if(!s->budget--) { s->failed_pc=0x0c0598b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0598b4;
P_0c0598b4: /* original 8b01, guest PC 0x0c0598b4 */
if(!s->budget--) { s->failed_pc=0x0c0598b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0598ba; }
goto P_0c0598b6;
P_0c0598b6: /* original a08a, guest PC 0x0c0598b6 */
if(!s->budget--) { s->failed_pc=0x0c0598b6u; return 0; }
r[0]=0x0000000eu;
goto P_0c0599ce;
P_0c0598b8: /* original e00e, guest PC 0x0c0598b8 */
if(!s->budget--) { s->failed_pc=0x0c0598b8u; return 0; }
r[0]=0x0000000eu;
goto P_0c0598ba;
P_0c0598ba: /* original e040, guest PC 0x0c0598ba */
if(!s->budget--) { s->failed_pc=0x0c0598bau; return 0; }
r[0]=0x00000040u;
goto P_0c0598bc;
P_0c0598bc: /* original d216, guest PC 0x0c0598bc */
if(!s->budget--) { s->failed_pc=0x0c0598bcu; return 0; }
r[2]=read(ram,0x0c059918u,4);
goto P_0c0598be;
P_0c0598be: /* original dd14, guest PC 0x0c0598be */
if(!s->budget--) { s->failed_pc=0x0c0598beu; return 0; }
r[13]=read(ram,0x0c059910u,4);
goto P_0c0598c0;
P_0c0598c0: /* original 1def, guest PC 0x0c0598c0 */
if(!s->budget--) { s->failed_pc=0x0c0598c0u; return 0; }
write(ram,r[13]+60,r[14],4);
goto P_0c0598c2;
P_0c0598c2: /* original 0dc6, guest PC 0x0c0598c2 */
if(!s->budget--) { s->failed_pc=0x0c0598c2u; return 0; }
write(ram,r[13]+r[0],r[12],4);
goto P_0c0598c4;
P_0c0598c4: /* original 63f2, guest PC 0x0c0598c4 */
if(!s->budget--) { s->failed_pc=0x0c0598c4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0598c6;
P_0c0598c6: /* original e044, guest PC 0x0c0598c6 */
if(!s->budget--) { s->failed_pc=0x0c0598c6u; return 0; }
r[0]=0x00000044u;
goto P_0c0598c8;
P_0c0598c8: /* original 0d36, guest PC 0x0c0598c8 */
if(!s->budget--) { s->failed_pc=0x0c0598c8u; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c0598ca;
P_0c0598ca: /* original 1db6, guest PC 0x0c0598ca */
if(!s->budget--) { s->failed_pc=0x0c0598cau; return 0; }
write(ram,r[13]+24,r[11],4);
goto P_0c0598cc;
P_0c0598cc: /* original d311, guest PC 0x0c0598cc */
if(!s->budget--) { s->failed_pc=0x0c0598ccu; return 0; }
r[3]=read(ram,0x0c059914u,4);
goto P_0c0598ce;
P_0c0598ce: /* original 420b, guest PC 0x0c0598ce */
if(!s->budget--) { s->failed_pc=0x0c0598ceu; return 0; }
target=r[2];
r[16]=code_base|0x0c0598d2u;
write(ram,r[3],r[11],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0598d2u) { target=s->pc; goto dispatch; }
goto P_0c0598d2;
P_0c0598d0: /* original 23b2, guest PC 0x0c0598d0 */
if(!s->budget--) { s->failed_pc=0x0c0598d0u; return 0; }
write(ram,r[3],r[11],4);
goto P_0c0598d2;
P_0c0598d2: /* original d112, guest PC 0x0c0598d2 */
if(!s->budget--) { s->failed_pc=0x0c0598d2u; return 0; }
r[1]=read(ram,0x0c05991cu,4);
goto P_0c0598d4;
P_0c0598d4: /* original 3010, guest PC 0x0c0598d4 */
if(!s->budget--) { s->failed_pc=0x0c0598d4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0598d6;
P_0c0598d6: /* original 8b68, guest PC 0x0c0598d6 */
if(!s->budget--) { s->failed_pc=0x0c0598d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0599aa; }
goto P_0c0598d8;
P_0c0598d8: /* original 52c6, guest PC 0x0c0598d8 */
if(!s->budget--) { s->failed_pc=0x0c0598d8u; return 0; }
r[2]=read(ram,r[12]+24,4);
goto P_0c0598da;
P_0c0598da: /* original 53e6, guest PC 0x0c0598da */
if(!s->budget--) { s->failed_pc=0x0c0598dau; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c0598dc;
P_0c0598dc: /* original 3320, guest PC 0x0c0598dc */
if(!s->budget--) { s->failed_pc=0x0c0598dcu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0598de;
P_0c0598de: /* original 8901, guest PC 0x0c0598de */
if(!s->budget--) { s->failed_pc=0x0c0598deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0598e4; }
goto P_0c0598e0;
P_0c0598e0: /* original a075, guest PC 0x0c0598e0 */
if(!s->budget--) { s->failed_pc=0x0c0598e0u; return 0; }
r[0]=0x0000000fu;
goto P_0c0599ce;
P_0c0598e2: /* original e00f, guest PC 0x0c0598e2 */
if(!s->budget--) { s->failed_pc=0x0c0598e2u; return 0; }
r[0]=0x0000000fu;
goto P_0c0598e4;
P_0c0598e4: /* original 53c5, guest PC 0x0c0598e4 */
if(!s->budget--) { s->failed_pc=0x0c0598e4u; return 0; }
r[3]=read(ram,r[12]+20,4);
goto P_0c0598e6;
P_0c0598e6: /* original 52e5, guest PC 0x0c0598e6 */
if(!s->budget--) { s->failed_pc=0x0c0598e6u; return 0; }
r[2]=read(ram,r[14]+20,4);
goto P_0c0598e8;
P_0c0598e8: /* original 3230, guest PC 0x0c0598e8 */
if(!s->budget--) { s->failed_pc=0x0c0598e8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0598ea;
P_0c0598ea: /* original 8919, guest PC 0x0c0598ea */
if(!s->budget--) { s->failed_pc=0x0c0598eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059920; }
goto P_0c0598ec;
P_0c0598ec: /* original a06f, guest PC 0x0c0598ec */
if(!s->budget--) { s->failed_pc=0x0c0598ecu; return 0; }
r[0]=0x00000010u;
goto P_0c0599ce;
P_0c0598ee: /* original e010, guest PC 0x0c0598ee */
if(!s->budget--) { s->failed_pc=0x0c0598eeu; return 0; }
r[0]=0x00000010u;
if(!vf3_matrix_family(0x0c0598f0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0598f0u; return 0; } return 1;
P_0c059920: /* original d330, guest PC 0x0c059920 */
if(!s->budget--) { s->failed_pc=0x0c059920u; return 0; }
r[3]=read(ram,0x0c0599e4u,4);
goto P_0c059922;
P_0c059922: /* original 52e7, guest PC 0x0c059922 */
if(!s->budget--) { s->failed_pc=0x0c059922u; return 0; }
r[2]=read(ram,r[14]+28,4);
goto P_0c059924;
P_0c059924: /* original 2322, guest PC 0x0c059924 */
if(!s->budget--) { s->failed_pc=0x0c059924u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c059926;
P_0c059926: /* original e200, guest PC 0x0c059926 */
if(!s->budget--) { s->failed_pc=0x0c059926u; return 0; }
r[2]=0x00000000u;
goto P_0c059928;
P_0c059928: /* original d12f, guest PC 0x0c059928 */
if(!s->budget--) { s->failed_pc=0x0c059928u; return 0; }
r[1]=read(ram,0x0c0599e8u,4);
goto P_0c05992a;
P_0c05992a: /* original 2122, guest PC 0x0c05992a */
if(!s->budget--) { s->failed_pc=0x0c05992au; return 0; }
write(ram,r[1],r[2],4);
goto P_0c05992c;
P_0c05992c: /* original d02f, guest PC 0x0c05992c */
if(!s->budget--) { s->failed_pc=0x0c05992cu; return 0; }
r[0]=read(ram,0x0c0599ecu,4);
goto P_0c05992e;
P_0c05992e: /* original 53c7, guest PC 0x0c05992e */
if(!s->budget--) { s->failed_pc=0x0c05992eu; return 0; }
r[3]=read(ram,r[12]+28,4);
goto P_0c059930;
P_0c059930: /* original 2032, guest PC 0x0c059930 */
if(!s->budget--) { s->failed_pc=0x0c059930u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c059932;
P_0c059932: /* original e300, guest PC 0x0c059932 */
if(!s->budget--) { s->failed_pc=0x0c059932u; return 0; }
r[3]=0x00000000u;
goto P_0c059934;
P_0c059934: /* original d22e, guest PC 0x0c059934 */
if(!s->budget--) { s->failed_pc=0x0c059934u; return 0; }
r[2]=read(ram,0x0c0599f0u,4);
goto P_0c059936;
P_0c059936: /* original 2232, guest PC 0x0c059936 */
if(!s->budget--) { s->failed_pc=0x0c059936u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c059938;
P_0c059938: /* original de2e, guest PC 0x0c059938 */
if(!s->budget--) { s->failed_pc=0x0c059938u; return 0; }
r[14]=read(ram,0x0c0599f4u,4);
goto P_0c05993a;
P_0c05993a: /* original 7194, guest PC 0x0c05993a */
if(!s->budget--) { s->failed_pc=0x0c05993au; return 0; }
r[1]+=0xffffff94u;
goto P_0c05993c;
P_0c05993c: /* original 6512, guest PC 0x0c05993c */
if(!s->budget--) { s->failed_pc=0x0c05993cu; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c05993e;
P_0c05993e: /* original 4e0b, guest PC 0x0c05993e */
if(!s->budget--) { s->failed_pc=0x0c05993eu; return 0; }
target=r[14];
r[16]=code_base|0x0c059942u;
r[4]=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059942u) { target=s->pc; goto dispatch; }
goto P_0c059942;
P_0c059940: /* original e450, guest PC 0x0c059940 */
if(!s->budget--) { s->failed_pc=0x0c059940u; return 0; }
r[4]=0x00000050u;
goto P_0c059942;
P_0c059942: /* original d32d, guest PC 0x0c059942 */
if(!s->budget--) { s->failed_pc=0x0c059942u; return 0; }
r[3]=read(ram,0x0c0599f8u,4);
goto P_0c059944;
P_0c059944: /* original 6532, guest PC 0x0c059944 */
if(!s->budget--) { s->failed_pc=0x0c059944u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c059946;
P_0c059946: /* original 4e0b, guest PC 0x0c059946 */
if(!s->budget--) { s->failed_pc=0x0c059946u; return 0; }
target=r[14];
r[16]=code_base|0x0c05994au;
r[4]=0x00000054u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05994au) { target=s->pc; goto dispatch; }
goto P_0c05994a;
P_0c059948: /* original e454, guest PC 0x0c059948 */
if(!s->budget--) { s->failed_pc=0x0c059948u; return 0; }
r[4]=0x00000054u;
goto P_0c05994a;
P_0c05994a: /* original d526, guest PC 0x0c05994a */
if(!s->budget--) { s->failed_pc=0x0c05994au; return 0; }
r[5]=read(ram,0x0c0599e4u,4);
goto P_0c05994c;
P_0c05994c: /* original 6552, guest PC 0x0c05994c */
if(!s->budget--) { s->failed_pc=0x0c05994cu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c05994e;
P_0c05994e: /* original 4e0b, guest PC 0x0c05994e */
if(!s->budget--) { s->failed_pc=0x0c05994eu; return 0; }
target=r[14];
r[16]=code_base|0x0c059952u;
r[4]=0x00000060u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059952u) { target=s->pc; goto dispatch; }
goto P_0c059952;
P_0c059950: /* original e460, guest PC 0x0c059950 */
if(!s->budget--) { s->failed_pc=0x0c059950u; return 0; }
r[4]=0x00000060u;
goto P_0c059952;
P_0c059952: /* original d526, guest PC 0x0c059952 */
if(!s->budget--) { s->failed_pc=0x0c059952u; return 0; }
r[5]=read(ram,0x0c0599ecu,4);
goto P_0c059954;
P_0c059954: /* original 6552, guest PC 0x0c059954 */
if(!s->budget--) { s->failed_pc=0x0c059954u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c059956;
P_0c059956: /* original 4e0b, guest PC 0x0c059956 */
if(!s->budget--) { s->failed_pc=0x0c059956u; return 0; }
target=r[14];
r[16]=code_base|0x0c05995au;
r[4]=0x00000064u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05995au) { target=s->pc; goto dispatch; }
goto P_0c05995a;
P_0c059958: /* original e464, guest PC 0x0c059958 */
if(!s->budget--) { s->failed_pc=0x0c059958u; return 0; }
r[4]=0x00000064u;
goto P_0c05995a;
P_0c05995a: /* original d222, guest PC 0x0c05995a */
if(!s->budget--) { s->failed_pc=0x0c05995au; return 0; }
r[2]=read(ram,0x0c0599e4u,4);
goto P_0c05995c;
P_0c05995c: /* original 6322, guest PC 0x0c05995c */
if(!s->budget--) { s->failed_pc=0x0c05995cu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c05995e;
P_0c05995e: /* original d126, guest PC 0x0c05995e */
if(!s->budget--) { s->failed_pc=0x0c05995eu; return 0; }
r[1]=read(ram,0x0c0599f8u,4);
goto P_0c059960;
P_0c059960: /* original 2132, guest PC 0x0c059960 */
if(!s->budget--) { s->failed_pc=0x0c059960u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c059962;
P_0c059962: /* original d022, guest PC 0x0c059962 */
if(!s->budget--) { s->failed_pc=0x0c059962u; return 0; }
r[0]=read(ram,0x0c0599ecu,4);
goto P_0c059964;
P_0c059964: /* original 6302, guest PC 0x0c059964 */
if(!s->budget--) { s->failed_pc=0x0c059964u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c059966;
P_0c059966: /* original 72a0, guest PC 0x0c059966 */
if(!s->budget--) { s->failed_pc=0x0c059966u; return 0; }
r[2]+=0xffffffa0u;
goto P_0c059968;
P_0c059968: /* original 2232, guest PC 0x0c059968 */
if(!s->budget--) { s->failed_pc=0x0c059968u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c05996a;
P_0c05996a: /* original 60b3, guest PC 0x0c05996a */
if(!s->budget--) { s->failed_pc=0x0c05996au; return 0; }
r[0]=r[11];
goto P_0c05996c;
P_0c05996c: /* original 0009, guest PC 0x0c05996c */
if(!s->budget--) { s->failed_pc=0x0c05996cu; return 0; }
goto P_0c05996e;
P_0c05996e: /* original 8801, guest PC 0x0c05996e */
if(!s->budget--) { s->failed_pc=0x0c05996eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c059970;
P_0c059970: /* original 8b0b, guest PC 0x0c059970 */
if(!s->budget--) { s->failed_pc=0x0c059970u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05998a; }
goto P_0c059972;
P_0c059972: /* original e400, guest PC 0x0c059972 */
if(!s->budget--) { s->failed_pc=0x0c059972u; return 0; }
r[4]=0x00000000u;
goto P_0c059974;
P_0c059974: /* original d121, guest PC 0x0c059974 */
if(!s->budget--) { s->failed_pc=0x0c059974u; return 0; }
r[1]=read(ram,0x0c0599fcu,4);
goto P_0c059976;
P_0c059976: /* original 2142, guest PC 0x0c059976 */
if(!s->budget--) { s->failed_pc=0x0c059976u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c059978;
P_0c059978: /* original d321, guest PC 0x0c059978 */
if(!s->budget--) { s->failed_pc=0x0c059978u; return 0; }
r[3]=read(ram,0x0c059a00u,4);
goto P_0c05997a;
P_0c05997a: /* original 2342, guest PC 0x0c05997a */
if(!s->budget--) { s->failed_pc=0x0c05997au; return 0; }
write(ram,r[3],r[4],4);
goto P_0c05997c;
P_0c05997c: /* original d21e, guest PC 0x0c05997c */
if(!s->budget--) { s->failed_pc=0x0c05997cu; return 0; }
r[2]=read(ram,0x0c0599f8u,4);
goto P_0c05997e;
P_0c05997e: /* original 6522, guest PC 0x0c05997e */
if(!s->budget--) { s->failed_pc=0x0c05997eu; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c059980;
P_0c059980: /* original 4e0b, guest PC 0x0c059980 */
if(!s->budget--) { s->failed_pc=0x0c059980u; return 0; }
target=r[14];
r[16]=code_base|0x0c059984u;
r[4]=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059984u) { target=s->pc; goto dispatch; }
goto P_0c059984;
P_0c059982: /* original e450, guest PC 0x0c059982 */
if(!s->budget--) { s->failed_pc=0x0c059982u; return 0; }
r[4]=0x00000050u;
goto P_0c059984;
P_0c059984: /* original d31f, guest PC 0x0c059984 */
if(!s->budget--) { s->failed_pc=0x0c059984u; return 0; }
r[3]=read(ram,0x0c059a04u,4);
goto P_0c059986;
P_0c059986: /* original a006, guest PC 0x0c059986 */
if(!s->budget--) { s->failed_pc=0x0c059986u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c059996;
P_0c059988: /* original 6532, guest PC 0x0c059988 */
if(!s->budget--) { s->failed_pc=0x0c059988u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c05998a;
P_0c05998a: /* original d31b, guest PC 0x0c05998a */
if(!s->budget--) { s->failed_pc=0x0c05998au; return 0; }
r[3]=read(ram,0x0c0599f8u,4);
goto P_0c05998c;
P_0c05998c: /* original 6532, guest PC 0x0c05998c */
if(!s->budget--) { s->failed_pc=0x0c05998cu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c05998e;
P_0c05998e: /* original 4e0b, guest PC 0x0c05998e */
if(!s->budget--) { s->failed_pc=0x0c05998eu; return 0; }
target=r[14];
r[16]=code_base|0x0c059992u;
r[4]=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059992u) { target=s->pc; goto dispatch; }
goto P_0c059992;
P_0c059990: /* original e450, guest PC 0x0c059990 */
if(!s->budget--) { s->failed_pc=0x0c059990u; return 0; }
r[4]=0x00000050u;
goto P_0c059992;
P_0c059992: /* original d219, guest PC 0x0c059992 */
if(!s->budget--) { s->failed_pc=0x0c059992u; return 0; }
r[2]=read(ram,0x0c0599f8u,4);
goto P_0c059994;
P_0c059994: /* original 6522, guest PC 0x0c059994 */
if(!s->budget--) { s->failed_pc=0x0c059994u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c059996;
P_0c059996: /* original 4e0b, guest PC 0x0c059996 */
if(!s->budget--) { s->failed_pc=0x0c059996u; return 0; }
target=r[14];
r[16]=code_base|0x0c05999au;
r[4]=0x00000054u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05999au) { target=s->pc; goto dispatch; }
goto P_0c05999a;
P_0c059998: /* original e454, guest PC 0x0c059998 */
if(!s->budget--) { s->failed_pc=0x0c059998u; return 0; }
r[4]=0x00000054u;
goto P_0c05999a;
P_0c05999a: /* original e301, guest PC 0x0c05999a */
if(!s->budget--) { s->failed_pc=0x0c05999au; return 0; }
r[3]=0x00000001u;
goto P_0c05999c;
P_0c05999c: /* original d21a, guest PC 0x0c05999c */
if(!s->budget--) { s->failed_pc=0x0c05999cu; return 0; }
r[2]=read(ram,0x0c059a08u,4);
goto P_0c05999e;
P_0c05999e: /* original 2232, guest PC 0x0c05999e */
if(!s->budget--) { s->failed_pc=0x0c05999eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0599a0;
P_0c0599a0: /* original 61f2, guest PC 0x0c0599a0 */
if(!s->budget--) { s->failed_pc=0x0c0599a0u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c0599a2;
P_0c0599a2: /* original d31a, guest PC 0x0c0599a2 */
if(!s->budget--) { s->failed_pc=0x0c0599a2u; return 0; }
r[3]=read(ram,0x0c059a0cu,4);
goto P_0c0599a4;
P_0c0599a4: /* original 2312, guest PC 0x0c0599a4 */
if(!s->budget--) { s->failed_pc=0x0c0599a4u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0599a6;
P_0c0599a6: /* original a010, guest PC 0x0c0599a6 */
if(!s->budget--) { s->failed_pc=0x0c0599a6u; return 0; }
goto P_0c0599ca;
P_0c0599a8: /* original 0009, guest PC 0x0c0599a8 */
if(!s->budget--) { s->failed_pc=0x0c0599a8u; return 0; }
goto P_0c0599aa;
P_0c0599aa: /* original 9418, guest PC 0x0c0599aa */
if(!s->budget--) { s->failed_pc=0x0c0599aau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0599deu,2);
goto P_0c0599ac;
P_0c0599ac: /* original d318, guest PC 0x0c0599ac */
if(!s->budget--) { s->failed_pc=0x0c0599acu; return 0; }
r[3]=read(ram,0x0c059a10u,4);
goto P_0c0599ae;
P_0c0599ae: /* original 430b, guest PC 0x0c0599ae */
if(!s->budget--) { s->failed_pc=0x0c0599aeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0599b2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0599b2u) { target=s->pc; goto dispatch; }
goto P_0c0599b2;
P_0c0599b0: /* original 0009, guest PC 0x0c0599b0 */
if(!s->budget--) { s->failed_pc=0x0c0599b0u; return 0; }
goto P_0c0599b2;
P_0c0599b2: /* original 9215, guest PC 0x0c0599b2 */
if(!s->budget--) { s->failed_pc=0x0c0599b2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0599e0u,2);
goto P_0c0599b4;
P_0c0599b4: /* original 3020, guest PC 0x0c0599b4 */
if(!s->budget--) { s->failed_pc=0x0c0599b4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[2])!=0);
goto P_0c0599b6;
P_0c0599b6: /* original 8b08, guest PC 0x0c0599b6 */
if(!s->budget--) { s->failed_pc=0x0c0599b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0599ca; }
goto P_0c0599b8;
P_0c0599b8: /* original d416, guest PC 0x0c0599b8 */
if(!s->budget--) { s->failed_pc=0x0c0599b8u; return 0; }
r[4]=read(ram,0x0c059a14u,4);
goto P_0c0599ba;
P_0c0599ba: /* original d117, guest PC 0x0c0599ba */
if(!s->budget--) { s->failed_pc=0x0c0599bau; return 0; }
r[1]=read(ram,0x0c059a18u,4);
goto P_0c0599bc;
P_0c0599bc: /* original 410b, guest PC 0x0c0599bc */
if(!s->budget--) { s->failed_pc=0x0c0599bcu; return 0; }
target=r[1];
r[16]=code_base|0x0c0599c0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0599c0u) { target=s->pc; goto dispatch; }
goto P_0c0599c0;
P_0c0599be: /* original 0009, guest PC 0x0c0599be */
if(!s->budget--) { s->failed_pc=0x0c0599beu; return 0; }
goto P_0c0599c0;
P_0c0599c0: /* original d316, guest PC 0x0c0599c0 */
if(!s->budget--) { s->failed_pc=0x0c0599c0u; return 0; }
r[3]=read(ram,0x0c059a1cu,4);
goto P_0c0599c2;
P_0c0599c2: /* original e054, guest PC 0x0c0599c2 */
if(!s->budget--) { s->failed_pc=0x0c0599c2u; return 0; }
r[0]=0x00000054u;
goto P_0c0599c4;
P_0c0599c4: /* original 430b, guest PC 0x0c0599c4 */
if(!s->budget--) { s->failed_pc=0x0c0599c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0599c8u;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0599c8u) { target=s->pc; goto dispatch; }
goto P_0c0599c8;
P_0c0599c6: /* original 04de, guest PC 0x0c0599c6 */
if(!s->budget--) { s->failed_pc=0x0c0599c6u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c0599c8;
P_0c0599c8: /* original 6a03, guest PC 0x0c0599c8 */
if(!s->budget--) { s->failed_pc=0x0c0599c8u; return 0; }
r[10]=r[0];
goto P_0c0599ca;
P_0c0599ca: /* original 60a3, guest PC 0x0c0599ca */
if(!s->budget--) { s->failed_pc=0x0c0599cau; return 0; }
r[0]=r[10];
goto P_0c0599cc;
P_0c0599cc: /* original 0009, guest PC 0x0c0599cc */
if(!s->budget--) { s->failed_pc=0x0c0599ccu; return 0; }
goto P_0c0599ce;
P_0c0599ce: /* original 7f04, guest PC 0x0c0599ce */
if(!s->budget--) { s->failed_pc=0x0c0599ceu; return 0; }
r[15]+=0x00000004u;
goto P_0c0599d0;
P_0c0599d0: /* original 4f26, guest PC 0x0c0599d0 */
if(!s->budget--) { s->failed_pc=0x0c0599d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0599d2;
P_0c0599d2: /* original 6af6, guest PC 0x0c0599d2 */
if(!s->budget--) { s->failed_pc=0x0c0599d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0599d4;
P_0c0599d4: /* original 6bf6, guest PC 0x0c0599d4 */
if(!s->budget--) { s->failed_pc=0x0c0599d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0599d6;
P_0c0599d6: /* original 6cf6, guest PC 0x0c0599d6 */
if(!s->budget--) { s->failed_pc=0x0c0599d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0599d8;
P_0c0599d8: /* original 6df6, guest PC 0x0c0599d8 */
if(!s->budget--) { s->failed_pc=0x0c0599d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0599da;
P_0c0599da: /* original 000b, guest PC 0x0c0599da */
if(!s->budget--) { s->failed_pc=0x0c0599dau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0599dc: /* original 6ef6, guest PC 0x0c0599dc */
if(!s->budget--) { s->failed_pc=0x0c0599dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0599deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0599deu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
