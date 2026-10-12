/* Vertex-format adapters for triangle clipping: indexed/inline ARGB, signed
 * texture coordinates and packed coordinate words. Position intersection
 * and ARGB blending retain the original shared helper calls. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#define R(n) s->v[(n)]
#define F(n) s->v[21+(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
typedef struct {
    uint32_t copy,edge,emitter,format,palette_pool,mode_pool,alpha_pool,alpha_base_pool;
    uint32_t near_pool,intersection_pool,color_pool,intersection_return,color_return,emit_return;
} vertex_format;
static const vertex_format formats[]={
    {0x0c0517a0,0x0c0517b8,0x0c05174c,0,0x0c0517fc,0x0c05176c,0x0c05179c,0x0c051914,
     0x0c051908,0,0,0x0c0517ec,0x0c0517f0,0x0c0517f4},
    {0x0c051ea0,0x0c051eca,0x0c051e4c,1,0x0c051f3c,0x0c051e6c,0x0c051e9c,0x0c051f4c,
     0x0c051f40,0x0c051f34,0x0c051f38,0x0c051f24,0x0c051f2a,0x0c051f2e},
    {0x0c052518,0x0c052540,0x0c0524ac,2,0x0c0525ac,0x0c0524d8,0x0c052514,0x0c0525bc,
     0x0c0525b0,0x0c0525a4,0x0c0525a8,0x0c052592,0x0c052598,0x0c05259c},
    {0x0c052b94,0x0c052bba,0x0c052b3c,3,0,0x0c052b5c,0x0c052b90,0,
     0x0c052c28,0x0c052c1c,0x0c052c20,0x0c052c0c,0x0c052c12,0x0c052c16},
    {0x0c052eb4,0x0c052eca,0x0c052e54,4,0,0x0c052e78,0x0c052eb0,0,
     0x0c052f18,0x0c052f0c,0x0c052f10,0x0c052efc,0x0c052f02,0x0c052f06}
};
static uint32_t word(const vf3_ram_map *ram,uint32_t address){return (uint32_t)(int32_t)(int16_t)READ(address,2);}
static void load_next(vf3_matrix_state *s,const vf3_ram_map *ram,unsigned fr,unsigned pointer){vf3_matrix_load(s,ram,fr,R(pointer));R(pointer)+=(R(18)&0x100000u)?8:4;}
static void store_previous(vf3_matrix_state *s,const vf3_ram_map *ram,unsigned fr){R(12)-=(R(18)&0x100000u)?8:4;vf3_matrix_store(s,ram,fr,R(12));}
static void texture(vf3_matrix_state *s,const vf3_ram_map *ram,unsigned first){
    for(unsigned axis=0;axis<2;axis++){
        R(0)=word(ram,R(8)+2+axis*2);R(53)=R(0);F(first+axis)=vf3_fpu_float(R(53),R(18));
        F(first+axis)=vf3_fpu_binary(F(first+axis),F(15),R(18),'*');
    }
}
static void inline_color(vf3_matrix_state *s,const vf3_ram_map *ram,unsigned dst,unsigned offset){
    R(0)=word(ram,R(8)+offset);R(dst)=(R(0)<<16)|(R(0)>>16);
    R(0)=word(ram,R(8)+offset+2);R(dst)=(R(0)<<16)|(R(dst)>>16);
}
static void position(vf3_matrix_state *s,const vf3_ram_map *ram,unsigned pointer,unsigned first){
    R(pointer)+=R(14);for(unsigned axis=0;axis<3;axis++)load_next(s,ram,first+axis,pointer);
}
static int emit(vf3_matrix_state *s,const vf3_ram_map *ram,const vertex_format *format){
    R(0)=READ(format->mode_pool,4);R(0)=READ(R(0),4);R(17)=(R(17)&~1u)|(R(0)==0);
    if(format->format==4)R(0)=0;
    if(!(R(17)&1)){
        if(format->format<3){
            R(1)=READ(format->alpha_base_pool,4);vf3_matrix_load(s,ram,0,R(1));
            R(1)=READ(format->alpha_pool,4);vf3_matrix_load(s,ram,2,R(1));
            F(0)=vf3_fpu_binary(F(0),F(2),R(18),'*');R(53)=vf3_fpu_ftrc(F(0));R(1)=R(53);R(1)<<=16;R(1)<<=8;R(5)|=R(1);
        }else{
            R(1)=READ(format->alpha_pool,4);R(1)=READ(R(1),4);R(2)=R(5);R(2)>>=16;R(2)>>=8;
            R(19)=(R(1)&0xffffu)*(R(2)&0xffffu);R(2)=R(19);R(2)>>=8;R(2)<<=8;R(2)<<=16;
            R(5)<<=8;R(5)>>=8;R(5)|=R(2);
        }
    }
    R(12)+=28;
    if(format->format==2){R(53)=F(8);R(0)=R(53);R(53)=F(9);R(1)=R(53);R(0)>>=16;R(1)=(R(0)<<16)|(R(1)>>16);}
    if(format->format==4)WRITE(R(12),R(0),4);
    R(12)-=4;WRITE(R(12),R(5),4);
    if(format->format==1||format->format==3){store_previous(s,ram,9);store_previous(s,ram,8);}
    else {R(12)-=4;if(format->format==0)R(0)=0;R(12)-=4;WRITE(R(12),format->format==2?R(1):R(0),4);}
    store_previous(s,ram,6);store_previous(s,ram,5);store_previous(s,ram,4);
    R(12)-=4;WRITE(R(12),R(4),4);R(12)+=32;s->pc=R(16);return ram->oob==0;
}
int vf3_clip_attributes_c(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram)
{
    const vertex_format *format=0;
    for(unsigned i=0;i<sizeof(formats)/sizeof(formats[0]);i++)if(entry==formats[i].copy||entry==formats[i].edge||entry==formats[i].emitter){format=&formats[i];break;}
    if(!format)return 0;
    if(entry==format->emitter)return emit(s,ram,format);
    if(entry==format->copy){
        R(8)=READ(R(14)+R(0),4);
        if(format->format<3){R(3)=word(ram,R(8));R(2)=READ(format->palette_pool,4);R(3)<<=2;R(0)=READ(R(2),4);R(3)<<=1;R(5)=READ(R(0)+R(3),4);}
        if(format->format==1||format->format==3)texture(s,ram,8);
        if(format->format>=3)inline_color(s,ram,5,format->format==3?6:2);
        position(s,ram,1,4);
        if(format->format==2){R(8)=READ(R(1),4);R(1)+=4;R(9)=R(8);R(9)<<=16;R(53)=R(8);F(8)=R(53);R(53)=R(9);F(9)=R(53);}
        return emit(s,ram,format);
    }
    R(15)-=4;WRITE(R(15),R(16),4);
    if(format->format==0||format->format==2){
        R(5)=READ(format->palette_pool,4);R(8)=READ(R(14)+R(0),4);R(0)=word(ram,R(8));R(0)<<=2;R(5)=READ(R(5),4);R(0)<<=1;R(6)=READ(R(5)+R(0),4);
        R(0)=R(2);R(8)=READ(R(14)+R(0),4);R(0)=word(ram,R(8));R(0)<<=2;R(0)<<=1;R(7)=READ(R(5)+R(0),4);
        position(s,ram,1,4);
        if(format->format==2){R(0)=READ(R(1),4);R(1)+=4;R(1)=R(0);R(1)<<=16;R(53)=R(0);F(0)=R(53);R(53)=R(1);F(1)=R(53);}
        position(s,ram,3,8);
        if(format->format==2){R(0)=READ(R(3),4);R(3)+=4;R(1)=R(0);R(1)<<=16;R(53)=R(0);F(11)=R(53);R(53)=R(1);F(12)=R(53);}
    }else{
        R(8)=READ(R(14)+R(0),4);
        if(format->format==1){R(6)=word(ram,R(8));R(0)=READ(format->palette_pool,4);R(6)<<=2;R(0)=READ(R(0),4);R(6)<<=1;R(6)=READ(R(0)+R(6),4);}
        if(format->format!=4)texture(s,ram,0);
        if(format->format>=3)inline_color(s,ram,6,format->format==3?6:2);
        position(s,ram,1,4);R(0)=R(2);R(8)=READ(R(14)+R(0),4);
        if(format->format==1){R(7)=word(ram,R(8));R(0)=READ(format->palette_pool,4);R(7)<<=2;R(0)=READ(R(0),4);R(7)<<=1;R(7)=READ(R(0)+R(7),4);}
        if(format->format!=4)texture(s,ram,11);
        if(format->format>=3)inline_color(s,ram,7,format->format==3?6:2);
        position(s,ram,3,8);
    }
    R(0)=format->near_pool;R(0)=READ(R(0),4);if(format->intersection_pool)R(1)=READ(format->intersection_pool,4);
    vf3_matrix_load(s,ram,3,R(0));R(16)=format->intersection_return;
    if(!vf3_matrix_family(format->intersection_pool?R(1):0x0c051800,s,ram))return 0;
    if(format->color_pool){R(0)=READ(format->color_pool,4);}
    R(16)=format->color_return;
    if(!vf3_matrix_family(format->color_pool?R(0):0x0c05184c,s,ram))return 0;
    R(16)=format->emit_return;if(!emit(s,ram,format))return 0;
    R(16)=READ(R(15),4);R(15)+=4;s->pc=R(16);return ram->oob==0;
}
