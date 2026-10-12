/* Clip a triangle's six visible topologies into an inherited vertex stream.
 * Attribute-format variants use their original copy/intersection helpers.
 * The final vertex receives the banked end-of-strip command, and the full
 * floating/register frame is restored while retaining the advanced R12. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
typedef struct {
    uint32_t entry,stride,selector_pool,simple_shader_pool,color_shader_pool;
    uint32_t copy_target,edge_target,mask_pools[4],returns[21];
} clip_profile;
static const clip_profile profiles[]={
#include "fight/clip_profiles.inc"
};
typedef struct { unsigned intersect,vertex,other; } clip_vertex;
typedef struct { unsigned first,count; clip_vertex vertices[4]; } clip_topology;
static const clip_topology topologies[]={
    {0,4,{{0,0,0},{0,1,0},{1,0,2},{1,1,2}}},
    {4,4,{{0,0,0},{1,0,1},{0,2,0},{1,2,1}}},
    {8,3,{{0,0,0},{1,0,1},{1,0,2},{0,0,0}}},
    {11,4,{{1,1,0},{0,1,0},{1,2,0},{0,2,0}}},
    {15,3,{{1,1,0},{0,1,0},{1,1,2},{0,0,0}}},
    {18,3,{{1,2,0},{1,2,1},{0,2,0},{0,0,0}}}
};
static void condition(vf3_matrix_state *s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t value){R(15)-=4;WRITE(R(15),value,4);}
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram){uint32_t value=READ(R(15),4);R(15)+=4;return value;}
static void save_float(vf3_matrix_state *s,const vf3_ram_map *ram,unsigned index){R(15)-=(R(18)&0x100000u)?8:4;vf3_matrix_store(s,ram,index,R(15));}
static void restore_float(vf3_matrix_state *s,const vf3_ram_map *ram,unsigned index){vf3_matrix_load(s,ram,index,R(15));R(15)+=(R(18)&0x100000u)?8:4;}
static int mask(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t pool){R(0)=READ(pool,4);R(0)&=R(4);condition(s,(int32_t)R(0)>0);return (R(17)&1)!=0;}

/* Unweighted position/scalar packet; the word at packet +20 is untouched. */
int vf3_plain_weight_vertex_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    R(12)+=32;R(0)=0;R(12)-=4;WRITE(R(12),R(0),4);
    R(12)-=(R(18)&0x100000u)?8:4;vf3_matrix_store(s,ram,11,R(12));
    R(12)-=4;R(12)-=4;WRITE(R(12),R(0),4);
    static const unsigned fields[]={6,5,4};
    for(unsigned i=0;i<3;i++){R(12)-=(R(18)&0x100000u)?8:4;vf3_matrix_store(s,ram,fields[i],R(12));}
    R(12)-=4;WRITE(R(12),R(4),4);R(12)+=32;s->pc=R(16);return ram->oob==0;
}

int vf3_clip_triangle_c(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram)
{
    const clip_profile *profile=0;
    for(unsigned i=0;i<sizeof(profiles)/sizeof(profiles[0]);i++)if(profiles[i].entry==entry){profile=&profiles[i];break;}
    if(!profile)return 0;
    push(s,ram,R(10));push(s,ram,R(9));push(s,ram,R(14));push(s,ram,R(13));
    push(s,ram,R(11));push(s,ram,R(10));push(s,ram,R(9));push(s,ram,R(8));
    for(int i=7;i>=0;i--)push(s,ram,R(i));
    for(int i=15;i>=0;i--)save_float(s,ram,(unsigned)i);
    push(s,ram,R(16));R(14)=R(15);R(0)=0xffffff00u;R(15)+=R(0);
    R(0)=100;R(8)=READ(R(14)+R(0),4);R(8)+=profile->stride;R(0)=104;WRITE(R(14)+R(0),R(8),4);
    R(0)=108;R(8)+=profile->stride;WRITE(R(14)+R(0),R(8),4);vf3_matrix_move(s,15,3);
    R(5)=R(4);R(0)=1;R(5)&=R(0);R(5)<<=2;R(6)=R(4);R(0)=2;R(6)&=R(0);R(5)|=R(6);
    R(7)=R(4);R(0)=4;R(7)&=R(0);R(7)>>=2;R(7)|=R(5);R(4)=R(7);
    if(profile->selector_pool){
        R(0)=READ(profile->selector_pool,4);R(0)=READ(R(0),4);condition(s,R(0)==0);
        R(10)=READ((R(17)&1)?profile->simple_shader_pool:profile->color_shader_pool,4);
    }
    unsigned topology;
    R(0)=1;R(0)&=R(4);condition(s,(int32_t)R(0)>0);
    if(!(R(17)&1)){
        if(!mask(s,ram,profile->mask_pools[0]))topology=0;
        else topology=mask(s,ram,profile->mask_pools[1])?2:1;
    }else{
        if(mask(s,ram,profile->mask_pools[2]))topology=5;
        else topology=mask(s,ram,profile->mask_pools[3])?4:3;
    }
    const clip_topology *shape=&topologies[topology];
    for(unsigned i=0;i<shape->count;i++){
        const clip_vertex *vertex=&shape->vertices[i];
        if(i+1==shape->count){if(!s->bank_known)return 0;R(4)=s->bank[4];}
        else R(4)=R(12);
        R(0)=100+vertex->vertex*4;R(1)=20+vertex->vertex*16;
        uint32_t target=profile->copy_target;
        if(vertex->intersect){R(2)=100+vertex->other*4;R(3)=20+vertex->other*16;target=profile->edge_target;}
        R(16)=profile->returns[shape->first+i];
        if(!vf3_matrix_family(target,s,ram))return 0;
    }
    R(1)=256;R(15)+=R(1);R(16)=pop(s,ram);
    for(unsigned i=0;i<16;i++)restore_float(s,ram,i);
    for(unsigned i=0;i<12;i++)R(i)=pop(s,ram);
    R(13)=pop(s,ram);R(14)=pop(s,ram);R(9)=pop(s,ram);R(10)=pop(s,ram);
    s->pc=R(16);return ram->oob==0;
}
