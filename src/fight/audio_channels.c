/* Channel buffer allocation, 0x8c040fa4. Host records have 24-byte stride;
 * driver records have 96-byte stride. The posted command's consumption is
 * separate from this synchronous publication operation. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#ifdef VF3_AUDIO_BRIDGE
extern void vf3_audio_queue_step(vf3_matrix_state*,uint32_t);
#define STEP(pc) vf3_audio_queue_step(s,0x8c000000u+(pc))
#define DIV_STEP(pc) vf3_audio_queue_step(s,0x0c000000u+(pc))
#else
#define STEP(pc) ((void)0)
#define DIV_STEP(pc) ((void)0)
#endif
extern int vf3_audio_queue_c(vf3_matrix_state*,const vf3_ram_map*);
static uint32_t word(const vf3_ram_map *ram,uint32_t a)
{ return (uint32_t)(int32_t)(int16_t)vf3_matrix_read(ram,a,2); }
static void t(vf3_matrix_state *s,int v)
{ R(17)=(R(17)&~1u)|(v!=0); }
static void shift(vf3_matrix_state *s,unsigned n)
{ t(s,R(n)>>31); R(n)<<=1; }
static void rotate(vf3_matrix_state *s,unsigned n)
{ uint32_t v=R(n),carry=R(17)&1u; t(s,v>>31); R(n)=(v<<1)|carry; }
static void division_bit(vf3_matrix_state *s)
{
    unsigned oldq=(R(17)>>8)&1u,m=(R(17)>>9)&1u,q=R(2)>>31;
    uint32_t shifted=(R(2)<<1)|(R(17)&1u),divisor=R(0);
    R(2)=oldq==m?shifted-divisor:shifted+divisor;
    unsigned carry=oldq==m?R(2)>shifted:R(2)<shifted;
    q^=carry^m; R(17)=(R(17)&~0x101u)|(q<<8)|(q==m);
}
/* SDK unsigned division: preserve the saved r2 and the helper's Q/M/T effects. */
static int quotient(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    DIV_STEP(0x042cd4); t(s,R(0)==0);
    DIV_STEP(0x042cd6); R(15)-=4; vf3_matrix_write(ram,R(15),R(2),4);
    DIV_STEP(0x042cd8); int zero=R(17)&1u;
    DIV_STEP(0x042cda);
    if(zero) {
        DIV_STEP(0x042d68); R(2)=0x0c1a5a60;
        DIV_STEP(0x042d6a); R(1)=0x44e;
        DIV_STEP(0x042d6c); R(0)=0;
        DIV_STEP(0x042d6e); vf3_matrix_write(ram,R(2),R(1),4);
        DIV_STEP(0x042d70); DIV_STEP(0x042d72);
    } else {
        DIV_STEP(0x042cdc); R(2)=0;
        DIV_STEP(0x042cde); R(17)&=~0x301u;
        for(unsigned i=0;i<32;++i) {
            DIV_STEP(0x042ce0+i*4); rotate(s,1);
            DIV_STEP(0x042ce2+i*4); division_bit(s);
        }
        DIV_STEP(0x042d60); rotate(s,1);
        DIV_STEP(0x042d62); R(0)=R(1);
        DIV_STEP(0x042d64); DIV_STEP(0x042d66);
    }
    R(2)=vf3_matrix_read(ram,R(15),4); R(15)+=4; s->pc=R(16);
    return ram->oob==0;
}
/* Expand the channel index into the original byte-sized record offset while
 * retaining the scratch-register/condition state needed by the calling ABI. */
static void offset(vf3_matrix_state *s,const vf3_ram_map *ram,
                   uint32_t pc,unsigned n,unsigned scratch)
{
    STEP(pc); R(0)=word(ram,R(15)+2);
    STEP(pc+2); R(n)=R(0);
    STEP(pc+4); R(scratch)=R(n);
    STEP(pc+6); shift(s,n);
    STEP(pc+8); R(n)+=R(scratch);
    STEP(pc+10); R(n)<<=2;
    STEP(pc+12); shift(s,n);
    STEP(pc+14); R(n)&=255;
}
static void offset_nop(vf3_matrix_state *s,const vf3_ram_map *ram,
                       uint32_t pc,unsigned n)
{
    STEP(pc); R(0)=word(ram,R(15)+2);
    STEP(pc+2); R(n)=R(0);
    STEP(pc+4); R(0)=R(n);
    STEP(pc+6);
    STEP(pc+8); shift(s,n);
    STEP(pc+10); R(n)+=R(0);
    STEP(pc+12); R(n)<<=2;
    STEP(pc+14); shift(s,n);
    STEP(pc+16); R(n)&=255;
}
static void increment(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t pc)
{
    STEP(pc); R(0)=word(ram,R(15)+2);
    STEP(pc+2); R(0)+=1;
    STEP(pc+4); vf3_matrix_write(ram,R(15)+2,R(0),2);
}
static int finish(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t pc)
{
    STEP(pc); R(15)+=32;
    STEP(pc+2); R(16)=vf3_matrix_read(ram,R(15),4); R(15)+=4;
    STEP(pc+4); uint32_t parent=R(16);
    STEP(pc+6); s->pc=parent;
    return ram->oob==0;
}
int vf3_audio_channels_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    STEP(0x040fa4); R(15)-=4; vf3_matrix_write(ram,R(15),R(16),4);
    STEP(0x040fa6); R(15)-=32;
    STEP(0x040fa8); R(3)=R(15);
    STEP(0x040faa); R(3)+=30;
    STEP(0x040fac); vf3_matrix_write(ram,R(3),R(4),2);
    STEP(0x040fae); R(2)=R(15);
    STEP(0x040fb0); R(2)+=28;
    STEP(0x040fb2); vf3_matrix_write(ram,R(2),R(5),2);
    STEP(0x040fb4); R(3)=R(15);
    STEP(0x040fb6); R(3)+=26;
    STEP(0x040fb8); vf3_matrix_write(ram,R(3),R(6),2);
    STEP(0x040fba); R(0)=word(ram,R(15)+26);
    STEP(0x040fbc); t(s,R(0)==0);
    STEP(0x040fbe);
    if(!(R(17)&1u)) {
        STEP(0x040fc0); R(0)=0xfffffffeu;
        return finish(s,ram,0x040fc2);
    }
    STEP(0x040fca); R(0)=word(ram,R(15)+28);
    STEP(0x040fcc); shift(s,0);
    STEP(0x040fce); R(3)=R(0);
    STEP(0x040fd0); R(0)=word(ram,R(15)+30);
    STEP(0x040fd2); R(0)+=R(3);
    STEP(0x040fd4); vf3_matrix_write(ram,R(15),R(0),2);
    STEP(0x040fd6); R(0)=(uint32_t)(int32_t)(int16_t)R(0);
    STEP(0x040fd8); R(3)=8;
    STEP(0x040fda); t(s,(int32_t)R(0)>(int32_t)R(3));
    STEP(0x040fdc);
    if(R(17)&1u) {
        STEP(0x040fde); R(0)=0xffffffffu;
        return finish(s,ram,0x040fe0);
    }
    STEP(0x040fe8); R(0)=0;
    STEP(0x040fea); vf3_matrix_write(ram,R(15)+2,R(0),2);
    STEP(0x040fec); STEP(0x040fee);
    for(;;) {
        STEP(0x04101a); R(0)=word(ram,R(15)+2);
        STEP(0x04101c); R(3)=8;
        STEP(0x04101e); t(s,(int32_t)R(0)>=(int32_t)R(3));
        STEP(0x041020); if(R(17)&1u) break;
        STEP(0x040ff0); R(0)=(uint32_t)(int32_t)(int8_t)vf3_matrix_read(ram,R(15)+2,1);
        STEP(0x040ff2); R(3)=R(0);
        STEP(0x040ff4); shift(s,0);
        STEP(0x040ff6); R(0)+=R(3);
        STEP(0x040ff8); R(0)<<=2;
        STEP(0x040ffa); shift(s,0);
        STEP(0x040ffc); R(0)&=255;
        STEP(0x040ffe); R(1)=0x0c19e250;
        STEP(0x041000); R(0)=(uint32_t)(int32_t)(int8_t)vf3_matrix_read(ram,R(0)+R(1),1);
        STEP(0x041002); t(s,R(0)==1);
        STEP(0x041004);
        if(R(17)&1u) {
            STEP(0x041006); R(0)=0xfffffffdu;
            return finish(s,ram,0x041008);
        }
        increment(s,ram,0x041014);
    }
    STEP(0x041022); R(0)=word(ram,R(15)+30);
    STEP(0x041024); R(3)=0xa08000a0;
    STEP(0x041026); vf3_matrix_write(ram,R(3),R(0),4);
    STEP(0x041028); R(0)=word(ram,R(15)+28);
    STEP(0x04102a); R(2)=0xa08000a4;
    STEP(0x04102c); vf3_matrix_write(ram,R(2),R(0),4);
    STEP(0x04102e); R(0)=0xa080008c;
    STEP(0x041030); R(1)=vf3_matrix_read(ram,R(0),4);
    STEP(0x041032); vf3_matrix_write(ram,R(15)+20,R(1),4);
    STEP(0x041034); R(3)=word(ram,R(15));
    STEP(0x041036); t(s,R(3)==0);
    STEP(0x041038);
    if(!(R(17)&1u)) {
        STEP(0x04103a); R(3)=word(ram,R(15));
        STEP(0x04103c); R(3)<<=2;
        STEP(0x04103e); R(3)<<=2;
        STEP(0x041040); R(3)<<=2;
        STEP(0x041042); R(1)=vf3_matrix_read(ram,R(15)+20,4);
        STEP(0x041044); R(1)-=R(3);
        STEP(0x041046); R(0)=word(ram,R(15));
        STEP(0x041048); R(3)=0x0c042cd4;
        STEP(0x04104a); STEP(0x04104c); R(16)=0x8c04104e;
        if(!quotient(s,ram)) return 0;
        STEP(0x04104e); R(1)=0x7fffffe0;
        STEP(0x041050); R(0)&=R(1);
        STEP(0x041052); R(3)=0x0c19e22c;
        STEP(0x041054); vf3_matrix_write(ram,R(3),R(0),4);
        STEP(0x041056); R(2)=0x4000;
        STEP(0x041058); t(s,(int32_t)R(0)>(int32_t)R(2));
        STEP(0x04105a);
        if(R(17)&1u) {
            STEP(0x04105c); R(1)=0x0c19e22c;
            STEP(0x04105e); vf3_matrix_write(ram,R(1),R(2),4);
        }
        STEP(0x041060); R(0)=0x0c19e22c;
        STEP(0x041062); R(3)=vf3_matrix_read(ram,R(0),4);
        STEP(0x041064); R(3)+=64;
        STEP(0x041066); vf3_matrix_write(ram,R(15)+16,R(3),4);
        STEP(0x041068); R(2)=0x0c19e220;
        STEP(0x04106a); R(0)=vf3_matrix_read(ram,R(2),4);
        STEP(0x04106c); R(0)=vf3_matrix_read(ram,R(0),4);
        STEP(0x04106e); vf3_matrix_write(ram,R(15)+4,R(0),4);
        STEP(0x041070); t(s,(R(0)&31u)==0);
        STEP(0x041072);
        if(!(R(17)&1u)) {
            STEP(0x041074); R(1)=0xffffffe0u;
            STEP(0x041076); R(0)=vf3_matrix_read(ram,R(15)+4,4);
            STEP(0x041078); R(0)&=R(1);
            STEP(0x04107a); R(0)+=32;
            STEP(0x04107c); vf3_matrix_write(ram,R(15)+4,R(0),4);
        }
        STEP(0x04107e); R(3)=vf3_matrix_read(ram,R(15)+16,4);
        STEP(0x041080); R(1)=0x0c19e224;
        STEP(0x041082); R(2)=vf3_matrix_read(ram,R(1),4);
        STEP(0x041084); R(2)-=R(3);
        STEP(0x041086); R(0)=vf3_matrix_read(ram,R(15)+4,4);
        STEP(0x041088); R(2)-=R(0);
        STEP(0x04108a); vf3_matrix_write(ram,R(15)+12,R(2),4);
        STEP(0x04108c); R(1)=0xa0800100;
        STEP(0x04108e); vf3_matrix_write(ram,R(15)+8,R(1),4);
        STEP(0x041090); STEP(0x041092);
    } else {
        STEP(0x041094); R(3)=0;
        STEP(0x041096); vf3_matrix_write(ram,R(15)+16,R(3),4);
        STEP(0x041098); R(1)=0;
        STEP(0x04109a); R(3)=0x0c19e22c;
        STEP(0x04109c); vf3_matrix_write(ram,R(3),R(1),4);
    }
    STEP(0x04109e); R(2)=vf3_matrix_read(ram,R(15)+16,4);
    STEP(0x0410a0); R(3)=0xa08000a8;
    STEP(0x0410a2); vf3_matrix_write(ram,R(3),R(2),4);
    STEP(0x0410a4); R(0)=0;
    STEP(0x0410a6); vf3_matrix_write(ram,R(15)+2,R(0),2);
    STEP(0x0410a8); STEP(0x0410aa);
    unsigned loops=0;
    for(;;) {
        STEP(0x04118c); R(0)=word(ram,R(15)+2);
        STEP(0x04118e); R(3)=R(0);
        STEP(0x041190); R(0)=word(ram,R(15)+30);
        STEP(0x041192); t(s,(int32_t)R(3)>=(int32_t)R(0));
        STEP(0x041194); if(R(17)&1u) break;
        if(++loops>65536) { s->failed_pc=0x8c0410d8; return 0; }
        offset(s,ram,0x0410d8,3,2); offset(s,ram,0x0410e8,1,2);
        STEP(0x0410f8); R(0)=0;
        STEP(0x0410fa); R(2)=0x0c19e251;
        STEP(0x0410fc); R(2)+=R(1);
        STEP(0x0410fe); vf3_matrix_write(ram,R(2),R(0),1);
        STEP(0x041100); R(1)=0x0c19e250;
        STEP(0x041102); R(1)+=R(3);
        STEP(0x041104); vf3_matrix_write(ram,R(1),R(0),1);
        offset(s,ram,0x041106,3,2);
        STEP(0x041116); R(2)=0xa0800000;
        STEP(0x041118); R(1)=vf3_matrix_read(ram,R(15)+12,4);
        STEP(0x04111a); R(1)+=R(2);
        STEP(0x04111c); R(0)=0x0c19e254;
        STEP(0x04111e); vf3_matrix_write(ram,R(0)+R(3),R(1),4);
        STEP(0x041120); R(3)=vf3_matrix_read(ram,R(15)+8,4);
        STEP(0x041122); R(3)+=12;
        STEP(0x041124); R(1)=vf3_matrix_read(ram,R(15)+12,4);
        STEP(0x041126); vf3_matrix_write(ram,R(3),R(1),4);
        STEP(0x041128); R(3)=vf3_matrix_read(ram,R(15)+16,4);
        STEP(0x04112a); R(1)=vf3_matrix_read(ram,R(15)+12,4);
        STEP(0x04112c); R(1)-=R(3);
        STEP(0x04112e); vf3_matrix_write(ram,R(15)+12,R(1),4);
        offset_nop(s,ram,0x041130,2);
        STEP(0x041142); R(3)=0;
        STEP(0x041144); R(0)=0x0c19e258;
        STEP(0x041146); vf3_matrix_write(ram,R(0)+R(2),R(3),4);
        STEP(0x041148); R(2)=vf3_matrix_read(ram,R(15)+8,4);
        STEP(0x04114a); R(2)+=16;
        STEP(0x04114c); R(3)=0;
        STEP(0x04114e); vf3_matrix_write(ram,R(2),R(3),4);
        offset(s,ram,0x041150,2,3);
        STEP(0x041160); R(1)=vf3_matrix_read(ram,R(15)+8,4);
        STEP(0x041162); R(1)+=20;
        STEP(0x041164); R(0)=0x0c19e260;
        STEP(0x041166); vf3_matrix_write(ram,R(0)+R(2),R(1),4);
        offset(s,ram,0x041168,3,2);
        STEP(0x041178); R(1)=vf3_matrix_read(ram,R(15)+8,4);
        STEP(0x04117a); R(1)+=4;
        STEP(0x04117c); R(0)=0x0c19e264;
        STEP(0x04117e); vf3_matrix_write(ram,R(0)+R(3),R(1),4);
        STEP(0x041180); R(3)=vf3_matrix_read(ram,R(15)+8,4);
        STEP(0x041182); R(3)+=96;
        STEP(0x041184); vf3_matrix_write(ram,R(15)+8,R(3),4);
        increment(s,ram,0x041186);
    }
    STEP(0x041196); STEP(0x041198);
    for(;;) {
        STEP(0x04127a); R(0)=word(ram,R(15)+30);
        STEP(0x04127c); R(3)=R(0);
        STEP(0x04127e); R(0)=word(ram,R(15)+28);
        STEP(0x041280); R(3)+=R(0);
        STEP(0x041282); R(0)=word(ram,R(15)+2);
        STEP(0x041284); t(s,(int32_t)R(0)>=(int32_t)R(3));
        STEP(0x041286); if(R(17)&1u) break;
        if(++loops>65536) { s->failed_pc=0x8c0411b8; return 0; }
        offset(s,ram,0x0411b8,2,3); offset(s,ram,0x0411c8,1,3);
        STEP(0x0411d8); R(0)=0;
        STEP(0x0411da); R(3)=0x0c19e251;
        STEP(0x0411dc); R(3)+=R(1);
        STEP(0x0411de); vf3_matrix_write(ram,R(3),R(0),1);
        STEP(0x0411e0); R(1)=0x0c19e250;
        STEP(0x0411e2); R(1)+=R(2);
        STEP(0x0411e4); vf3_matrix_write(ram,R(1),R(0),1);
        offset(s,ram,0x0411e6,3,2);
        STEP(0x0411f6); R(2)=0xa0800000;
        STEP(0x0411f8); R(1)=vf3_matrix_read(ram,R(15)+12,4);
        STEP(0x0411fa); R(1)+=R(2);
        STEP(0x0411fc); R(0)=0x0c19e258;
        STEP(0x0411fe); vf3_matrix_write(ram,R(0)+R(3),R(1),4);
        STEP(0x041200); R(3)=vf3_matrix_read(ram,R(15)+8,4);
        STEP(0x041202); R(3)+=16;
        STEP(0x041204); R(1)=vf3_matrix_read(ram,R(15)+12,4);
        STEP(0x041206); vf3_matrix_write(ram,R(3),R(1),4);
        STEP(0x041208); R(3)=vf3_matrix_read(ram,R(15)+16,4);
        STEP(0x04120a); R(1)=vf3_matrix_read(ram,R(15)+12,4);
        STEP(0x04120c); R(1)-=R(3);
        STEP(0x04120e); vf3_matrix_write(ram,R(15)+12,R(1),4);
        offset_nop(s,ram,0x041210,2);
        STEP(0x041222); R(3)=0xa0800000;
        STEP(0x041224); R(1)=vf3_matrix_read(ram,R(15)+12,4);
        STEP(0x041226); R(1)+=R(3);
        STEP(0x041228); R(0)=0x0c19e254;
        STEP(0x04122a); vf3_matrix_write(ram,R(0)+R(2),R(1),4);
        STEP(0x04122c); R(2)=vf3_matrix_read(ram,R(15)+8,4);
        STEP(0x04122e); R(2)+=12;
        STEP(0x041230); R(1)=vf3_matrix_read(ram,R(15)+12,4);
        STEP(0x041232); vf3_matrix_write(ram,R(2),R(1),4);
        STEP(0x041234); R(2)=vf3_matrix_read(ram,R(15)+16,4);
        STEP(0x041236); R(1)=vf3_matrix_read(ram,R(15)+12,4);
        STEP(0x041238); R(1)-=R(2);
        STEP(0x04123a); vf3_matrix_write(ram,R(15)+12,R(1),4);
        offset_nop(s,ram,0x04123c,3);
        STEP(0x04124e); R(2)=vf3_matrix_read(ram,R(15)+8,4);
        STEP(0x041250); R(2)+=20;
        STEP(0x041252); R(0)=0x0c19e260;
        STEP(0x041254); vf3_matrix_write(ram,R(0)+R(3),R(2),4);
        offset(s,ram,0x041256,3,2);
        STEP(0x041266); R(1)=vf3_matrix_read(ram,R(15)+8,4);
        STEP(0x041268); R(1)+=4;
        STEP(0x04126a); R(0)=0x0c19e264;
        STEP(0x04126c); vf3_matrix_write(ram,R(0)+R(3),R(1),4);
        STEP(0x04126e); R(3)=vf3_matrix_read(ram,R(15)+8,4);
        STEP(0x041270); R(3)+=96;
        STEP(0x041272); vf3_matrix_write(ram,R(15)+8,R(3),4);
        increment(s,ram,0x041274);
    }
    STEP(0x041288); STEP(0x04128a);
    for(;;) {
        STEP(0x041308); R(0)=word(ram,R(15)+2);
        STEP(0x04130a); R(3)=8;
        STEP(0x04130c); t(s,(int32_t)R(0)>=(int32_t)R(3));
        STEP(0x04130e); if(R(17)&1u) break;
        offset(s,ram,0x0412a8,2,3);
        STEP(0x0412b8); R(1)=0xffffffffu;
        STEP(0x0412ba); R(0)=0x0c19e250;
        STEP(0x0412bc); vf3_matrix_write(ram,R(0)+R(2),R(1),1);
        offset(s,ram,0x0412be,3,2);
        STEP(0x0412ce); R(1)=0;
        STEP(0x0412d0); R(0)=0x0c19e251;
        STEP(0x0412d2); vf3_matrix_write(ram,R(0)+R(3),R(1),1);
        offset(s,ram,0x0412d4,3,2); offset(s,ram,0x0412e4,1,2);
        STEP(0x0412f4); R(0)=0xffffffffu;
        STEP(0x0412f6); R(2)=0x0c19e258;
        STEP(0x0412f8); R(2)+=R(1);
        STEP(0x0412fa); vf3_matrix_write(ram,R(2),R(0),4);
        STEP(0x0412fc); R(1)=0x0c19e254;
        STEP(0x0412fe); R(1)+=R(3);
        STEP(0x041300); vf3_matrix_write(ram,R(1),R(0),4);
        increment(s,ram,0x041302);
    }
    STEP(0x041310); R(4)=0xa1;
    STEP(0x041312); STEP(0x041314); R(16)=0x8c041316;
    if(!vf3_audio_queue_c(s,ram)) return 0;
    STEP(0x041316); R(0)=0;
    return finish(s,ram,0x041318);
}
