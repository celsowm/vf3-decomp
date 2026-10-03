/* Matrix stack, affine transforms and register-bank adapters. This source
 * uses matrix/vector loops; it neither decodes opcodes nor executes the ROM. */
#include "fight/matrix_family.h"
#include "fight/sh4_matrix.h"
#include "fight/sh4_fpu.h"
#include "fight/fpu_tz.h"
#include <string.h>
#define rd vf3_matrix_read
#define wr vf3_matrix_write
#define load vf3_matrix_load
#define store vf3_matrix_store
#define mov vf3_matrix_move
#define swap_banks vf3_matrix_swap
#define R(n) s->v[n]
#define FR(n) s->v[21+(n)]
#define XF(n) s->v[37+(n)]
#define FPSCR s->v[18]
#define FPUL s->v[53]
static void t(vf3_matrix_state*s,int v) { R(17)=(R(17)&~1u)|(v!=0); }
uint32_t vf3_matrix_read(const vf3_ram_map *ram,uint32_t addr,unsigned size) {
    uint32_t value=0;
    addr&=0x1FFFFFFFu;
    if((addr<0x0c000000u || addr>=0x0d000000u) && ram->device_read)
        return ram->device_read(ram->device_context,addr,size);
    for(unsigned j=0;j<size;++j) {
        int found=0;
        for(int i=0;i<ram->n;++i) if(addr+j>=ram->wins[i].base && addr+j-ram->wins[i].base<ram->wins[i].len) {
            value|=(uint32_t)ram->wins[i].data[addr+j-ram->wins[i].base]<<(8*j); found=1; break;
        }
        if(!found) ++((vf3_ram_map*)ram)->oob;
    }
    return value;
}
void vf3_matrix_write(const vf3_ram_map *ram,uint32_t addr,uint32_t value,unsigned size) {
    addr&=0x1FFFFFFFu;
    if((addr<0x0c000000u || addr>=0x0d000000u) && ram->device_write) {
        ram->device_write(ram->device_context,addr,size,value); return;
    }
    for(unsigned j=0;j<size;++j) {
        int found=0;
        for(int i=0;i<ram->n;++i) if(addr+j>=ram->wins[i].base && addr+j-ram->wins[i].base<ram->wins[i].len) {
            ram->wins[i].data[addr+j-ram->wins[i].base]=(uint8_t)(value>>(8*j)); found=1; break;
        }
        if(!found) ++((vf3_ram_map*)ram)->oob;
    }
}
void vf3_matrix_swap(vf3_matrix_state*s) {
    for(unsigned i=0;i<16;++i) { uint32_t a=FR(i); FR(i)=XF(i); XF(i)=a; }
    FPSCR^=0x200000u; /* FR is bit 21; DN is bit 18 on the SH-4. */
}
static unsigned width(vf3_matrix_state*s) { return (FPSCR&0x100000u)?8:4; }
static uint32_t *bank(vf3_matrix_state*s,unsigned n) {
    if(width(s)==4) return &FR(n);
    return (n&1)?&XF(n&~1u):&FR(n&~1u);
}
void vf3_matrix_load(vf3_matrix_state*s,const vf3_ram_map*ram,unsigned reg,uint32_t addr) {
    uint32_t *p=bank(s,reg); unsigned n=width(s)/4;
    for(unsigned i=0;i<n;++i) p[i]=vf3_matrix_read(ram,addr+4*i,4);
}
void vf3_matrix_store(vf3_matrix_state*s,const vf3_ram_map*ram,unsigned reg,uint32_t addr) {
    uint32_t *p=bank(s,reg); unsigned n=width(s)/4;
    for(unsigned i=0;i<n;++i) vf3_matrix_write(ram,addr+4*i,p[i],4);
}
void vf3_matrix_move(vf3_matrix_state*s,unsigned dst,unsigned src) {
    uint32_t temp[2]; unsigned n=width(s);
    memcpy(temp,bank(s,src),n); memcpy(bank(s,dst),temp,n);
}
static int transform(vf3_matrix_state*s,unsigned base) {
    return vf3_fpu_ftrv(&XF(0),&FR(base),FPSCR,&FR(base));
}
static void push(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t value) { R(15)-=4; wr(ram,R(15),value,4); }
static uint32_t pop(vf3_matrix_state*s,const vf3_ram_map*ram) { uint32_t a=rd(ram,R(15),4); R(15)+=4; return a; }
int vf3_matrix_family(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
    const uint32_t queue=0x0C19D2E4u;
    entry&=0x1FFFFFFFu;
    if(!vf3_fpu_supported(FPSCR)) return 0;
    switch(entry) {
    case 0x0c0cc2d6: return vf3_motion_record_init(s,ram);
    case 0x0c069624: return vf3_fight_angle(s,ram);
    case 0x0c06911c: case 0x0c06912a: return vf3_fight_mesh(entry,s,ram);
    case 0x0C03C940: case 0x0C03C880: case 0x0C03C6C0: {
        uint32_t out[37],xf[16];
        int ok=entry==0x0C03C940?vf3_sh4_c940(s->v,out,&XF(0),xf):
               entry==0x0C03C880?vf3_sh4_c880(s->v,out,&XF(0),xf):vf3_sh4_c6c0(s->v,out,&XF(0),xf);
        if(!ok) return 0;
        FPUL=R(4); memcpy(s->v,out,sizeof(out)); memcpy(&XF(0),xf,sizeof(xf)); break;
    }
    case 0x0C03C4F0: { /* Push current matrix; optionally load the next one. */
        R(3)=queue; swap_banks(s); FPSCR^=0x100000u;
        R(1)=rd(ram,queue+8,4); R(2)=rd(ram,queue,4); R(7)=R(1); R(1)+=64;
        R(6)=(uint32_t)(int32_t)(int16_t)R(2); R(2)=(uint32_t)(int32_t)(int16_t)(R(2)>>16);
        t(s,(int32_t)R(2)>(int32_t)R(6)); R(0)=R(17)&1u;
        for(int i=14;i>=0;i-=2) { R(1)-=width(s); store(s,ram,(unsigned)i,R(1)); }
        R(6)++; R(7)+=64; wr(ram,queue+8,R(7),4);
        t(s,R(4)==0); wr(ram,queue,R(6),2);
        if(!R(4)) FPSCR^=0x100000u;
        else {
            R(1)=4; t(s,(R(4)&4)==0);
            if(R(4)&4) { FPSCR^=0x100000u; for(unsigned i=0;i<16;++i) { load(s,ram,i,R(4)); R(4)+=width(s); } }
            else { for(unsigned i=0;i<16;i+=2) { load(s,ram,i,R(4)); R(4)+=width(s); } FPSCR^=0x100000u; }
        }
        swap_banks(s); break;
    }
    case 0x0C03C4A0: { /* Pop a matrix, clamping the stack cursor to zero. */
        R(3)=queue; t(s,(int32_t)R(4)>0); if(!(R(17)&1)) R(4)=1;
        R(6)=(uint32_t)(int32_t)(int16_t)rd(ram,queue,2);
        FPSCR^=0x100000u; R(2)=(uint32_t)(int32_t)(int16_t)rd(ram,queue+2,2);
        t(s,(int32_t)R(6)>=(int32_t)R(4)); R(6)-=R(4); if(!(R(17)&1)) R(6)=0;
        R(0)=R(17)&1; R(7)=rd(ram,queue+4,4); R(4)=R(6)<<6;
        t(s,(int32_t)R(6)>=(int32_t)R(2)); wr(ram,queue,R(6),2); R(7)+=R(4);
        if(!(R(17)&1)) wr(ram,queue+8,R(7),4);
        for(unsigned i=1;i<16;i+=2) { load(s,ram,i,R(7)); R(7)+=width(s); }
        FPSCR^=0x100000u; break;
    }
    case 0x0C03B620: /* Store current matrix in caller memory or stack slot. */
        t(s,R(4)==0); if(!R(4)) R(4)=rd(ram,queue+8,4);
        R(4)+=64; swap_banks(s);
        for(int i=15;i>=0;--i) { R(4)-=width(s); store(s,ram,(unsigned)i,R(4)); }
        swap_banks(s); R(0)=R(4); break;
    case 0x0C03BD80: /* Load a matrix. */
        t(s,R(4)==0); if(!R(4)) R(4)=rd(ram,queue+8,4);
        swap_banks(s);
        for(unsigned i=0;i<16;++i) { load(s,ram,i,R(4)); R(4)+=width(s); }
        swap_banks(s); break;
    case 0x0C03B530: { /* Copy, load, or store a matrix according to pointers. */
        t(s,R(4)==0); push(s,ram,R(14)); R(14)=R(5);
        if(!R(4)) {
            t(s,R(14)==0);
            if(R(14)) { R(3)=0x0C03BD80u; R(4)=R(14); R(14)=pop(s,ram); return vf3_matrix_family(R(3),s,ram); }
        } else {
            t(s,R(14)==0);
            if(!R(14)) { R(3)=0x0C03B620u; R(14)=pop(s,ram); return vf3_matrix_family(R(3),s,ram); }
            R(5)=R(4); R(4)=16; R(6)=R(14);
            do { load(s,ram,3,R(6)); R(6)+=width(s); --R(4); t(s,R(4)==0); store(s,ram,3,R(5)); R(5)+=4; } while(R(4));
        }
        R(14)=pop(s,ram); break;
    }
    case 0x0C03B450: case 0x0C03B4B0: /* Affine point/direction transform. */
        for(unsigned i=4;i<7;++i) { load(s,ram,i,R(4)); R(4)+=width(s); }
        FR(7)=entry==0x0C03B450?0x3F800000u:0;
        if(!transform(s,4)) return 0;
        R(5)+=12;
        for(int i=6;i>=4;--i) { R(5)-=width(s); store(s,ram,(unsigned)i,R(5)); } break;
    case 0x0C03B820: /* Extract translation. */
        R(4)+=12; swap_banks(s);
        for(int i=14;i>=12;--i) { R(4)-=width(s); store(s,ram,(unsigned)i,R(4)); }
        swap_banks(s); break;
    case 0x0C03CBD0: /* Set translation. */
        swap_banks(s); for(unsigned i=12;i<15;++i) { load(s,ram,i,R(4)); R(4)+=width(s); } swap_banks(s); break;
    case 0x0C03C610: /* Reflect the third basis vector. */
        for(unsigned i=8;i<12;++i) XF(i)^=0x80000000u; break;
    case 0x0C03CC60: /* Apply affine translation. */
        FR(7)=0x3F800000u; if(!transform(s,4)) return 0;
        FPSCR^=0x100000u; mov(s,13,4); mov(s,15,6); FPSCR^=0x100000u; break;
    case 0x0C03CC90: {
        push(s,ram,R(14)); R(14)=R(4); R(0)=8;
        load(s,ram,6,R(14)+8); R(0)=4; R(3)=0x0C03CC60u;
        load(s,ram,4,R(14)); load(s,ram,5,R(14)+4); R(14)=pop(s,ram);
        return vf3_matrix_family(R(3),s,ram);
    }
    case 0x0C03CCB0: /* Seed the rotational identity while retaining translation. */
        FPSCR^=0x100000u; FR(0)=0; FR(1)=0; FR(2)=0; FR(3)=0x3F800000u;
        mov(s,3,0); mov(s,7,0); mov(s,9,0); mov(s,13,0);
        FR(0)=0x3F800000u; mov(s,1,0); mov(s,11,0); mov(s,5,2); mov(s,15,2);
        FPSCR^=0x100000u; break;
    case 0x0C03C970: /* Rotate using sine/cosine already held in FR4/FR5. */
        mov(s,1,4); FR(4)^=0x80000000u; mov(s,0,5); FR(2)=0; FR(3)=0;
        if(!transform(s,0)) return 0; FR(6)=0; FR(7)=0; if(!transform(s,4)) return 0;
        FPSCR^=0x100000u; mov(s,1,0); mov(s,3,2); mov(s,5,4); mov(s,7,6); FPSCR^=0x100000u; break;
    case 0x0C03C0E0: { /* Multiply an input matrix by XF, preserving caller FR12..15. */
        for(int i=15;i>=13;--i) { R(15)-=width(s); store(s,ram,(unsigned)i,R(15)); }
        FPUL=FR(12);
        for(unsigned base=0;base<16;base+=4) {
            for(unsigned i=base;i<base+4;++i) { load(s,ram,i,R(4)); R(4)+=width(s); }
            if(!transform(s,base)) return 0;
        }
        swap_banks(s); FR(12)=FPUL;
        for(unsigned i=13;i<16;++i) { load(s,ram,i,R(15)); R(15)+=width(s); } break;
    }
    default:
        /* Ownership is selected before execution; failed calls never retry. */
        if(vf3_phase2_adapter_contains(entry)) return vf3_phase2_adapter(entry,s,ram);
        if(vf3_phase1_adapter_contains(entry)) return vf3_phase1_adapter(entry,s,ram);
        if(vf3_sixth_loader_adapter_contains(entry)) return vf3_sixth_loader_adapter(entry,s,ram);
        if(vf3_seventh_adapter_contains(entry)) return vf3_seventh_adapter(entry,s,ram);
        if(vf3_seventh_c_adapter_contains(entry)) return vf3_seventh_c_adapter(entry,s,ram);
        if(vf3_seventh_c3_adapter_contains(entry)) return vf3_seventh_c3_adapter(entry,s,ram);
        if(vf3_seventh_c4_adapter_contains(entry)) return vf3_seventh_c4_adapter(entry,s,ram);
        if(vf3_seventh_c5_adapter_contains(entry)) return vf3_seventh_c5_adapter(entry,s,ram);
        if(vf3_seventh_c6_adapter_contains(entry)) return vf3_seventh_c6_adapter(entry,s,ram);
        if(vf3_seventh_c7_adapter_contains(entry)) return vf3_seventh_c7_adapter(entry,s,ram);
        if(vf3_seventh_c8_adapter_contains(entry)) return vf3_seventh_c8_adapter(entry,s,ram);
        if(vf3_seventh_c9_adapter_contains(entry)) return vf3_seventh_c9_adapter(entry,s,ram);
        if(vf3_seventh_c10_adapter_contains(entry)) return vf3_seventh_c10_adapter(entry,s,ram);
        if(vf3_seventh_c11_adapter_contains(entry)) return vf3_seventh_c11_adapter(entry,s,ram);
        if(vf3_seventh_c12_adapter_contains(entry)) return vf3_seventh_c12_adapter(entry,s,ram);
        if(vf3_seventh_c13_adapter_contains(entry)) return vf3_seventh_c13_adapter(entry,s,ram);
        if(vf3_seventh_c14_adapter_contains(entry)) return vf3_seventh_c14_adapter(entry,s,ram);
        if(vf3_eighth_adapter_contains(entry)) return vf3_eighth_adapter(entry,s,ram);
        if(vf3_fifth_leaf_adapter_contains(entry)) return vf3_fifth_leaf_adapter(entry,s,ram);
        if(vf3_fifth_adapter_contains(entry)) return vf3_fifth_adapter(entry,s,ram);
        if(vf3_device_adapter_contains(entry)) return vf3_device_adapter(entry,s,ram);
        if(vf3_next_adapter_contains(entry)) return vf3_next_adapter(entry,s,ram);
        if(vf3_motion_adapter_contains(entry)) return vf3_motion_adapter(entry,s,ram);
        if(vf3_fight_adapter_contains(entry)) return vf3_fight_adapter(entry,s,ram);
        if(vf3_motion_final_adapter_contains(entry)) return vf3_motion_final_adapter(entry,s,ram);
        if(vf3_fifth_leaf_unowned_adapter_contains(entry)) return vf3_fifth_leaf_unowned_adapter(entry,s,ram);
        if(vf3_motion_unowned_extra_adapter_contains(entry)) return vf3_motion_unowned_extra_adapter(entry,s,ram);
        if(vf3_fifth_leaf_extra_adapter_contains(entry)) return vf3_fifth_leaf_extra_adapter(entry,s,ram);
        return vf3_matrix_adapter(entry,s,ram);
    }
    s->pc=R(16);
    return ram->oob==0;
}
