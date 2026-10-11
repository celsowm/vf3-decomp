/* Counted vector-pair aggregation and affine output, callable 0x8c0a6ff8.
 * Frozen owner 0x8c0a700a omits the integer/FR save prefix. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#define R(n) s->v[(n)]
#define F(n) s->v[21+(n)]
#define READ(a) vf3_matrix_read(ram,(a),4)
#define WRITE(a,v) vf3_matrix_write(ram,(a),(v),4)
static void push(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t v){R(15)-=4;WRITE(R(15),v);}
static uint32_t pop(vf3_matrix_state*s,const vf3_ram_map*ram){uint32_t v=READ(R(15));R(15)+=4;return v;}
static void op(vf3_matrix_state*s,unsigned d,unsigned f,char operation){F(d)=vf3_fpu_binary(F(d),F(f),R(18),operation);}
static void condition(vf3_matrix_state*s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static int call(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t target,uint32_t next){R(16)=next;return vf3_matrix_family(target,s,ram)&&s->pc==next;}
int vf3_vector_sum_c(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t alias)
{
    unsigned k;
    if(!vf3_fpu_supported(R(18)) || (R(18)&0x100000u))return 0;
    push(s,ram,R(14));R(0)=4;push(s,ram,R(13));R(14)=R(4);push(s,ram,R(12));
    for(k=16;k-->12;){push(s,ram,F(k));}
    push(s,ram,R(16));R(15)-=64;WRITE(R(15)+12,R(6));WRITE(R(15)+8,R(7));
    R(12)=READ(R(5));F(4)=0;F(12)=F(4);condition(s,R(12)==0);
    F(15)=F(4);F(14)=F(4);F(13)=F(4);WRITE(R(15)+R(0),F(4));WRITE(R(15),F(4));
    if(!(R(17)&1)){
        R(13)=R(5)+4;
        do{
            if(!s->budget--)return 0;
            /* Each row holds two triples. Accumulate the first triple and
             * their cross product using the shared original matrix helper. */
            F(3)=READ(R(13));R(13)+=4;R(0)=40;R(5)=R(15);R(6)=R(15);WRITE(R(15)+R(0),F(3));
            R(0)=44;F(3)=READ(R(13));R(13)+=4;R(5)+=28;R(12)--;WRITE(R(15)+R(0),F(3));
            R(0)=48;F(3)=READ(R(13));R(13)+=4;R(6)+=28;WRITE(R(15)+R(0),F(3));
            for(k=0;k<3;k++){R(0)=28+k*4;F(3)=READ(R(13));R(13)+=4;WRITE(R(15)+R(0),F(3));}
            for(k=0;k<3;k++){R(0)=40+k*4;F(3)=READ(R(15)+R(0));op(s,13+k,3,'+');}
            R(3)=READ(alias+0x0a718c);R(4)=R(15)+40;
            if(!call(s,ram,R(3),alias+0x0a7076))return 0;
            R(0)=28;condition(s,(int32_t)R(12)>0);F(3)=READ(R(15)+R(0));R(0)=32;op(s,12,3,'+');
            F(3)=READ(R(15)+R(0));R(0)=4;F(2)=READ(R(15)+R(0));R(0)=4;op(s,2,3,'+');WRITE(R(15)+R(0),F(2));
            R(0)=36;F(1)=READ(R(15));F(3)=READ(R(15)+R(0));op(s,1,3,'+');WRITE(R(15),F(1));
        }while(R(17)&1);
        /* Apply per-axis cross-product weights and the common vector weight. */
        R(0)=4;F(4)=READ(R(14));F(3)=READ(R(14)+R(0));R(0)=8;F(5)=F(4);F(7)=READ(R(14)+R(0));op(s,5,3,'*');
        R(0)=12;F(3)=F(7);F(7)=F(4);op(s,7,3,'*');F(6)=READ(R(14)+R(0));R(0)=4;
        F(3)=F(6);F(6)=F(4);op(s,6,3,'*');
        for(k=13;k<=15;k++){F(3)=F(k);F(k)=F(4);op(s,k,3,'*');}
        F(3)=F(12);F(12)=F(5);op(s,12,3,'*');F(3)=READ(R(15)+R(0));R(0)=4;op(s,7,3,'*');WRITE(R(15)+R(0),F(7));
        F(3)=READ(R(15));R(4)=R(15);op(s,6,3,'*');WRITE(R(15),F(6));
        /* Install the configuration matrix while retaining current translation. */
        R(3)=READ(alias+0x0a7190);R(4)+=16;
        if(!call(s,ram,R(3),alias+0x0a70e6))return 0;
        R(2)=READ(alias+0x0a7194);R(4)=R(14)+16;
        if(!call(s,ram,R(2),alias+0x0a70ee))return 0;
        R(3)=READ(alias+0x0a7198);R(4)=R(15)+16;
        if(!call(s,ram,R(3),alias+0x0a70f6))return 0;
        for(k=0;k<3;k++){R(0)=52+k*4;WRITE(R(15)+R(0),F(13+k));}
        R(3)=READ(alias+0x0a719c);R(4)=0;
        if(!call(s,ram,R(3),alias+0x0a7108))return 0;
        R(2)=READ(alias+0x0a71a0);
        if(!call(s,ram,R(2),alias+0x0a710e))return 0;
        R(3)=READ(alias+0x0a71a4);R(5)=R(15)+52;R(4)=R(15)+52;
        if(!call(s,ram,R(3),alias+0x0a711a))return 0;
        R(2)=READ(alias+0x0a71a8);R(4)=1;
        if(!call(s,ram,R(2),alias+0x0a7120))return 0;
        for(k=0;k<3;k++){R(0)=52+k*4;F(13+k)=READ(R(15)+R(0));}
    }
    /* Publish the three translated vector components and three weighted
     * cross-product components through the original six output pointers. */
    R(0)=104;R(3)=READ(R(15)+12);F(3)=READ(R(14)+R(0));R(0)=108;WRITE(R(3),F(3));
    F(3)=READ(R(14)+R(0));R(0)=96;R(3)=READ(R(15)+8);WRITE(R(3),F(3));R(3)=READ(R(15)+R(0));
    R(0)=112;F(3)=READ(R(14)+R(0));R(0)=96;WRITE(R(3),F(3));
    R(3)=READ(R(15)+12);F(3)=READ(R(3));op(s,3,13,'+');WRITE(R(3),F(3));
    R(3)=READ(R(15)+8);F(3)=READ(R(3));op(s,3,14,'+');WRITE(R(3),F(3));
    R(3)=READ(R(15)+R(0));R(0)=100;F(3)=READ(R(3));op(s,3,15,'+');WRITE(R(3),F(3));
    R(3)=READ(R(15)+R(0));R(0)=104;WRITE(R(3),F(12));R(3)=READ(R(15)+R(0));
    R(0)=4;F(3)=READ(R(15)+R(0));R(0)=108;WRITE(R(3),F(3));F(3)=READ(R(15));R(3)=READ(R(15)+R(0));
    R(15)+=64;R(16)=pop(s,ram);WRITE(R(3),F(3));
    for(k=12;k<16;k++){F(k)=pop(s,ram);}
    R(12)=pop(s,ram);R(13)=pop(s,ram);s->pc=R(16);R(14)=pop(s,ram);return ram->oob==0;
}
